
// $destdir/u35.c        Machine generated C code

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



// Code for domainvalchk

static LispObject CC_domainvalchk(LispObject env,
                         LispObject v_20045, LispObject v_20046)
{
    env = qenv(env);
    LispObject v_20114, v_20115, v_20116;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20045,v_20046);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20046;
    stack[-1] = v_20045;
// end of prologue
    goto v_20061;
v_20057:
    v_20115 = qvalue(elt(env, 1)); // dmode!*
    goto v_20058;
v_20059:
    v_20114 = elt(env, 0); // domainvalchk
    goto v_20060;
v_20061:
    goto v_20057;
v_20058:
    goto v_20059;
v_20060:
    v_20114 = get(v_20115, v_20114);
    env = stack[-3];
    stack[-2] = v_20114;
    if (v_20114 == nil) goto v_20055;
    goto v_20071;
v_20065:
    v_20116 = stack[-2];
    goto v_20066;
v_20067:
    v_20115 = stack[-1];
    goto v_20068;
v_20069:
    v_20114 = stack[0];
    goto v_20070;
v_20071:
    goto v_20065;
v_20066:
    goto v_20067;
v_20068:
    goto v_20069;
v_20070:
        return Lapply2(nil, 3, v_20116, v_20115, v_20114);
v_20055:
    v_20114 = stack[0];
    v_20114 = Lreverse(nil, v_20114);
    env = stack[-3];
    stack[0] = v_20114;
v_20051:
    v_20114 = stack[0];
    if (v_20114 == nil) goto v_20079;
    else goto v_20080;
v_20079:
    goto v_20087;
v_20083:
    v_20115 = stack[-1];
    goto v_20084;
v_20085:
    v_20114 = stack[-2];
    goto v_20086;
v_20087:
    goto v_20083;
v_20084:
    goto v_20085;
v_20086:
    {
        fn = elt(env, 2); // valuechk
        return (*qfn2(fn))(fn, v_20115, v_20114);
    }
v_20080:
    goto v_20096;
v_20092:
    v_20114 = stack[0];
    v_20114 = qcar(v_20114);
    v_20115 = qcdr(v_20114);
    goto v_20093;
v_20094:
    v_20114 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20095;
v_20096:
    goto v_20092;
v_20093:
    goto v_20094;
v_20095:
    if (v_20115 == v_20114) goto v_20091;
    v_20114 = nil;
    goto v_20050;
v_20091:
    goto v_20107;
v_20103:
    v_20114 = stack[0];
    v_20114 = qcar(v_20114);
    fn = elt(env, 3); // mk!*sq
    v_20115 = (*qfn1(fn))(fn, v_20114);
    env = stack[-3];
    goto v_20104;
v_20105:
    v_20114 = stack[-2];
    goto v_20106;
v_20107:
    goto v_20103;
v_20104:
    goto v_20105;
v_20106:
    v_20114 = cons(v_20115, v_20114);
    env = stack[-3];
    stack[-2] = v_20114;
    v_20114 = stack[0];
    v_20114 = qcdr(v_20114);
    stack[0] = v_20114;
    goto v_20051;
v_20050:
    return onevalue(v_20114);
}



// Code for pasf_anegrel

static LispObject CC_pasf_anegrel(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20068, v_20069, v_20070;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20070 = v_20045;
// end of prologue
    goto v_20054;
v_20050:
    v_20069 = v_20070;
    goto v_20051;
v_20052:
    v_20068 = elt(env, 1); // ((equal . equal) (neq . neq) (leq . geq) (geq . leq) (lessp . greaterp) (greaterp . lessp) (cong . cong) (ncong . ncong))
    goto v_20053;
v_20054:
    goto v_20050;
v_20051:
    goto v_20052;
v_20053:
    v_20068 = Latsoc(nil, v_20069, v_20068);
    v_20068 = qcdr(v_20068);
    if (v_20068 == nil) goto v_20049;
    else goto v_20048;
v_20049:
    goto v_20065;
v_20061:
    v_20068 = elt(env, 2); // "pasf_anegrel: unknown operator "
    goto v_20062;
v_20063:
    v_20069 = v_20070;
    goto v_20064;
v_20065:
    goto v_20061;
v_20062:
    goto v_20063;
v_20064:
    v_20068 = list2(v_20068, v_20069);
    env = stack[0];
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_20068);
    }
v_20048:
    return onevalue(v_20068);
}



// Code for aex_subrat1

static LispObject CC_aex_subrat1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20085, v_20086, v_20087;
    LispObject fn;
    LispObject v_20047, v_20046, v_20045;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "aex_subrat1");
    va_start(aa, nargs);
    v_20045 = va_arg(aa, LispObject);
    v_20046 = va_arg(aa, LispObject);
    v_20047 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20047,v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20045,v_20046,v_20047);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20047;
    stack[-1] = v_20046;
    stack[-2] = v_20045;
// end of prologue
    v_20085 = stack[-2];
    fn = elt(env, 1); // aex_ex
    v_20085 = (*qfn1(fn))(fn, v_20085);
    env = stack[-3];
    goto v_20062;
v_20056:
    v_20087 = qcar(v_20085);
    goto v_20057;
v_20058:
    v_20086 = stack[-1];
    goto v_20059;
v_20060:
    v_20085 = stack[0];
    goto v_20061;
v_20062:
    goto v_20056;
v_20057:
    goto v_20058;
v_20059:
    goto v_20060;
v_20061:
    fn = elt(env, 2); // sfto_qsubhor1
    v_20085 = (*qfnn(fn))(fn, 3, v_20087, v_20086, v_20085);
    env = stack[-3];
    goto v_20072;
v_20068:
    stack[-1] = v_20085;
    goto v_20069;
v_20070:
    goto v_20079;
v_20075:
    v_20085 = qcar(v_20085);
    fn = elt(env, 3); // kernels
    stack[0] = (*qfn1(fn))(fn, v_20085);
    env = stack[-3];
    goto v_20076;
v_20077:
    v_20085 = stack[-2];
    fn = elt(env, 4); // aex_ctx
    v_20085 = (*qfn1(fn))(fn, v_20085);
    env = stack[-3];
    goto v_20078;
v_20079:
    goto v_20075;
v_20076:
    goto v_20077;
v_20078:
    fn = elt(env, 5); // ctx_filter
    v_20085 = (*qfn2(fn))(fn, stack[0], v_20085);
    env = stack[-3];
    goto v_20071;
v_20072:
    goto v_20068;
v_20069:
    goto v_20070;
v_20071:
    {
        LispObject v_20091 = stack[-1];
        fn = elt(env, 6); // aex_mk
        return (*qfn2(fn))(fn, v_20091, v_20085);
    }
    return onevalue(v_20085);
}



// Code for fnrd

static LispObject CC_fnrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20075, v_20076;
    LispObject fn;
    argcheck(nargs, 0, "fnrd");
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
    stack[0] = nil;
    fn = elt(env, 3); // lex
    v_20075 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_20058;
v_20054:
    v_20076 = qvalue(elt(env, 1)); // char
    goto v_20055;
v_20056:
    v_20075 = elt(env, 2); // (c i)
    goto v_20057;
v_20058:
    goto v_20054;
v_20055:
    goto v_20056;
v_20057:
    if (equal(v_20076, v_20075)) goto v_20053;
    goto v_20066;
v_20062:
    v_20075 = qvalue(elt(env, 1)); // char
    v_20076 = Lcompress(nil, v_20075);
    env = stack[-1];
    goto v_20063;
v_20064:
    v_20075 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_20065;
v_20066:
    goto v_20062;
v_20063:
    goto v_20064;
v_20065:
    fn = elt(env, 4); // errorml
    v_20075 = (*qfn2(fn))(fn, v_20076, v_20075);
    env = stack[-1];
    goto v_20051;
v_20053:
    fn = elt(env, 5); // mathml2
    v_20075 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_20075;
    goto v_20051;
v_20051:
    fn = elt(env, 3); // lex
    v_20075 = (*qfnn(fn))(fn, 0);
    v_20075 = stack[0];
    return onevalue(v_20075);
}



// Code for sc_subtrsq

static LispObject CC_sc_subtrsq(LispObject env,
                         LispObject v_20045, LispObject v_20046)
{
    env = qenv(env);
    LispObject v_20057, v_20058;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20045,v_20046);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_20057 = v_20046;
    v_20058 = v_20045;
// end of prologue
    goto v_20053;
v_20049:
    stack[0] = v_20058;
    goto v_20050;
v_20051:
    fn = elt(env, 1); // negsq
    v_20057 = (*qfn1(fn))(fn, v_20057);
    env = stack[-1];
    goto v_20052;
v_20053:
    goto v_20049;
v_20050:
    goto v_20051;
v_20052:
    {
        LispObject v_20060 = stack[0];
        fn = elt(env, 2); // addsq
        return (*qfn2(fn))(fn, v_20060, v_20057);
    }
}



// Code for vdpilcomb1

static LispObject CC_vdpilcomb1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20123, v_20124, v_20125, v_20126, v_20127, v_20128;
    LispObject fn;
    LispObject v_20050, v_20049, v_20048, v_20047, v_20046, v_20045;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "vdpilcomb1");
    va_start(aa, nargs);
    v_20045 = va_arg(aa, LispObject);
    v_20046 = va_arg(aa, LispObject);
    v_20047 = va_arg(aa, LispObject);
    v_20048 = va_arg(aa, LispObject);
    v_20049 = va_arg(aa, LispObject);
    v_20050 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_20050,v_20049,v_20048,v_20047,v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_20045,v_20046,v_20047,v_20048,v_20049,v_20050);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_20050;
    v_20123 = v_20049;
    stack[-2] = v_20048;
    stack[-3] = v_20047;
    v_20124 = v_20046;
    stack[-4] = v_20045;
// end of prologue
    goto v_20069;
v_20057:
    v_20125 = stack[-4];
    v_20125 = qcdr(v_20125);
    v_20125 = qcdr(v_20125);
    v_20125 = qcdr(v_20125);
    v_20128 = qcar(v_20125);
    goto v_20058;
v_20059:
    v_20127 = v_20124;
    goto v_20060;
v_20061:
    v_20126 = stack[-3];
    goto v_20062;
v_20063:
    v_20124 = stack[-2];
    v_20124 = qcdr(v_20124);
    v_20124 = qcdr(v_20124);
    v_20124 = qcdr(v_20124);
    v_20125 = qcar(v_20124);
    goto v_20064;
v_20065:
    v_20124 = v_20123;
    goto v_20066;
v_20067:
    v_20123 = stack[-1];
    goto v_20068;
v_20069:
    goto v_20057;
v_20058:
    goto v_20059;
v_20060:
    goto v_20061;
v_20062:
    goto v_20063;
v_20064:
    goto v_20065;
v_20066:
    goto v_20067;
v_20068:
    fn = elt(env, 2); // dipilcomb1
    v_20123 = (*qfnn(fn))(fn, 6, v_20128, v_20127, v_20126, v_20125, v_20124, v_20123);
    env = stack[-6];
    fn = elt(env, 3); // dip2vdp
    v_20123 = (*qfn1(fn))(fn, v_20123);
    env = stack[-6];
    stack[-5] = v_20123;
    v_20123 = qvalue(elt(env, 1)); // !*gsugar
    if (v_20123 == nil) goto v_20087;
    goto v_20094;
v_20090:
    stack[0] = stack[-5];
    goto v_20091;
v_20092:
    goto v_20101;
v_20097:
    goto v_20107;
v_20103:
    v_20123 = stack[-4];
    fn = elt(env, 4); // gsugar
    stack[-4] = (*qfn1(fn))(fn, v_20123);
    env = stack[-6];
    goto v_20104;
v_20105:
    v_20123 = stack[-3];
    fn = elt(env, 5); // vevtdeg
    v_20123 = (*qfn1(fn))(fn, v_20123);
    env = stack[-6];
    goto v_20106;
v_20107:
    goto v_20103;
v_20104:
    goto v_20105;
v_20106:
    stack[-3] = plus2(stack[-4], v_20123);
    env = stack[-6];
    goto v_20098;
v_20099:
    goto v_20117;
v_20113:
    v_20123 = stack[-2];
    fn = elt(env, 4); // gsugar
    stack[-2] = (*qfn1(fn))(fn, v_20123);
    env = stack[-6];
    goto v_20114;
v_20115:
    v_20123 = stack[-1];
    fn = elt(env, 5); // vevtdeg
    v_20123 = (*qfn1(fn))(fn, v_20123);
    env = stack[-6];
    goto v_20116;
v_20117:
    goto v_20113;
v_20114:
    goto v_20115;
v_20116:
    v_20123 = plus2(stack[-2], v_20123);
    env = stack[-6];
    goto v_20100;
v_20101:
    goto v_20097;
v_20098:
    goto v_20099;
v_20100:
    fn = elt(env, 6); // max
    v_20123 = (*qfn2(fn))(fn, stack[-3], v_20123);
    env = stack[-6];
    goto v_20093;
v_20094:
    goto v_20090;
v_20091:
    goto v_20092;
v_20093:
    fn = elt(env, 7); // gsetsugar
    v_20123 = (*qfn2(fn))(fn, stack[0], v_20123);
    goto v_20085;
v_20087:
v_20085:
    v_20123 = stack[-5];
    return onevalue(v_20123);
}



// Code for calc_coeff

static LispObject CC_calc_coeff(LispObject env,
                         LispObject v_20045, LispObject v_20046)
{
    env = qenv(env);
    LispObject v_20098, v_20099, v_20100;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20045,v_20046);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20046;
    stack[-1] = v_20045;
// end of prologue
    v_20098 = stack[-1];
    if (v_20098 == nil) goto v_20050;
    else goto v_20051;
v_20050:
    v_20098 = (LispObject)16+TAG_FIXNUM; // 1
    return ncons(v_20098);
v_20051:
    goto v_20062;
v_20058:
    v_20098 = stack[-1];
    v_20099 = qcar(v_20098);
    goto v_20059;
v_20060:
    v_20098 = stack[0];
    goto v_20061;
v_20062:
    goto v_20058;
v_20059:
    goto v_20060;
v_20061:
    fn = elt(env, 1); // calc_world
    v_20098 = (*qfn2(fn))(fn, v_20099, v_20098);
    env = stack[-3];
    v_20100 = v_20098;
    goto v_20075;
v_20071:
    v_20099 = v_20100;
    goto v_20072;
v_20073:
    v_20098 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20074;
v_20075:
    goto v_20071;
v_20072:
    goto v_20073;
v_20074:
    if (v_20099 == v_20098) goto v_20069;
    else goto v_20070;
v_20069:
    v_20098 = (LispObject)0+TAG_FIXNUM; // 0
    return ncons(v_20098);
v_20070:
    goto v_20087;
v_20083:
    stack[-2] = v_20100;
    goto v_20084;
v_20085:
    goto v_20094;
v_20090:
    v_20098 = stack[-1];
    v_20099 = qcdr(v_20098);
    goto v_20091;
v_20092:
    v_20098 = stack[0];
    goto v_20093;
v_20094:
    goto v_20090;
v_20091:
    goto v_20092;
v_20093:
    v_20098 = CC_calc_coeff(elt(env, 0), v_20099, v_20098);
    goto v_20086;
v_20087:
    goto v_20083;
v_20084:
    goto v_20085;
v_20086:
    {
        LispObject v_20104 = stack[-2];
        return cons(v_20104, v_20098);
    }
    v_20098 = nil;
    goto v_20049;
    v_20098 = nil;
v_20049:
    return onevalue(v_20098);
}



// Code for dp_neworder

static LispObject CC_dp_neworder(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20114, v_20115;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_20114 = v_20045;
// end of prologue
    goto v_20052;
v_20048:
    stack[-4] = v_20114;
    v_20114 = stack[-4];
    if (v_20114 == nil) goto v_20062;
    else goto v_20063;
v_20062:
    v_20114 = nil;
    v_20115 = v_20114;
    goto v_20057;
v_20063:
    v_20114 = stack[-4];
    v_20114 = qcar(v_20114);
    stack[0] = v_20114;
    goto v_20075;
v_20071:
    v_20114 = stack[0];
    v_20114 = qcar(v_20114);
    fn = elt(env, 2); // mo_neworder
    v_20115 = (*qfn1(fn))(fn, v_20114);
    env = stack[-5];
    goto v_20072;
v_20073:
    v_20114 = stack[0];
    v_20114 = qcdr(v_20114);
    goto v_20074;
v_20075:
    goto v_20071;
v_20072:
    goto v_20073;
v_20074:
    v_20114 = cons(v_20115, v_20114);
    env = stack[-5];
    v_20114 = ncons(v_20114);
    env = stack[-5];
    stack[-2] = v_20114;
    stack[-3] = v_20114;
v_20058:
    v_20114 = stack[-4];
    v_20114 = qcdr(v_20114);
    stack[-4] = v_20114;
    v_20114 = stack[-4];
    if (v_20114 == nil) goto v_20085;
    else goto v_20086;
v_20085:
    v_20114 = stack[-3];
    v_20115 = v_20114;
    goto v_20057;
v_20086:
    goto v_20094;
v_20090:
    stack[-1] = stack[-2];
    goto v_20091;
v_20092:
    v_20114 = stack[-4];
    v_20114 = qcar(v_20114);
    stack[0] = v_20114;
    goto v_20105;
v_20101:
    v_20114 = stack[0];
    v_20114 = qcar(v_20114);
    fn = elt(env, 2); // mo_neworder
    v_20115 = (*qfn1(fn))(fn, v_20114);
    env = stack[-5];
    goto v_20102;
v_20103:
    v_20114 = stack[0];
    v_20114 = qcdr(v_20114);
    goto v_20104;
v_20105:
    goto v_20101;
v_20102:
    goto v_20103;
v_20104:
    v_20114 = cons(v_20115, v_20114);
    env = stack[-5];
    v_20114 = ncons(v_20114);
    env = stack[-5];
    goto v_20093;
v_20094:
    goto v_20090;
v_20091:
    goto v_20092;
v_20093:
    v_20114 = Lrplacd(nil, stack[-1], v_20114);
    env = stack[-5];
    v_20114 = stack[-2];
    v_20114 = qcdr(v_20114);
    stack[-2] = v_20114;
    goto v_20058;
v_20057:
    goto v_20049;
v_20050:
    v_20114 = elt(env, 1); // dp!=mocompare
    goto v_20051;
v_20052:
    goto v_20048;
v_20049:
    goto v_20050;
v_20051:
    {
        fn = elt(env, 3); // sort
        return (*qfn2(fn))(fn, v_20115, v_20114);
    }
}



// Code for dfprintfn

static LispObject CC_dfprintfn(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20100, v_20101, v_20102;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20100 = v_20045;
// end of prologue
    v_20101 = qvalue(elt(env, 1)); // !*nat
    if (v_20101 == nil) goto v_20053;
    else goto v_20054;
v_20053:
    v_20101 = lisp_true;
    goto v_20052;
v_20054:
    v_20101 = qvalue(elt(env, 2)); // !*fort
    if (v_20101 == nil) goto v_20061;
    else goto v_20060;
v_20061:
    v_20101 = qvalue(elt(env, 3)); // !*dfprint
    v_20101 = (v_20101 == nil ? lisp_true : nil);
v_20060:
    goto v_20052;
    v_20101 = nil;
v_20052:
    if (v_20101 == nil) goto v_20050;
    v_20100 = elt(env, 4); // failed
    goto v_20048;
v_20050:
    goto v_20078;
v_20072:
    goto v_20084;
v_20080:
    v_20101 = elt(env, 5); // !!df!!
    goto v_20081;
v_20082:
    v_20100 = qcdr(v_20100);
    goto v_20083;
v_20084:
    goto v_20080;
v_20081:
    goto v_20082;
v_20083:
    v_20102 = cons(v_20101, v_20100);
    env = stack[0];
    goto v_20073;
v_20074:
    v_20101 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20075;
v_20076:
    v_20100 = nil;
    goto v_20077;
v_20078:
    goto v_20072;
v_20073:
    goto v_20074;
v_20075:
    goto v_20076;
v_20077:
    fn = elt(env, 6); // layout!-formula
    v_20100 = (*qfnn(fn))(fn, 3, v_20102, v_20101, v_20100);
    env = stack[0];
    v_20101 = v_20100;
    v_20100 = v_20101;
    if (v_20100 == nil) goto v_20092;
    else goto v_20093;
v_20092:
    v_20100 = elt(env, 4); // failed
    goto v_20070;
v_20093:
    v_20100 = v_20101;
    fn = elt(env, 7); // putpline
    v_20100 = (*qfn1(fn))(fn, v_20100);
    goto v_20091;
v_20091:
    v_20100 = nil;
v_20070:
    goto v_20048;
    v_20100 = nil;
v_20048:
    return onevalue(v_20100);
}



// Code for clean_numid

static LispObject CC_clean_numid(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20078, v_20079;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_20045;
// end of prologue
    stack[-1] = nil;
v_20050:
    v_20078 = stack[0];
    if (v_20078 == nil) goto v_20053;
    else goto v_20054;
v_20053:
    v_20078 = stack[-1];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_20078);
    }
v_20054:
    v_20078 = stack[0];
    v_20078 = qcar(v_20078);
    fn = elt(env, 2); // !*id2num
    v_20078 = (*qfn1(fn))(fn, v_20078);
    env = stack[-2];
    if (v_20078 == nil) goto v_20059;
    v_20078 = stack[0];
    v_20078 = qcdr(v_20078);
    stack[0] = v_20078;
    goto v_20050;
v_20059:
    goto v_20072;
v_20068:
    v_20078 = stack[0];
    v_20079 = qcar(v_20078);
    goto v_20069;
v_20070:
    v_20078 = stack[-1];
    goto v_20071;
v_20072:
    goto v_20068;
v_20069:
    goto v_20070;
v_20071:
    v_20078 = cons(v_20079, v_20078);
    env = stack[-2];
    stack[-1] = v_20078;
    v_20078 = stack[0];
    v_20078 = qcdr(v_20078);
    stack[0] = v_20078;
    goto v_20050;
    v_20078 = nil;
    return onevalue(v_20078);
}



// Code for dummyp

static LispObject CC_dummyp(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20164, v_20165, v_20166;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_20045;
// end of prologue
    v_20164 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_20164;
    v_20164 = stack[-3];
    fn = elt(env, 4); // listp
    v_20164 = (*qfn1(fn))(fn, v_20164);
    env = stack[-5];
    if (v_20164 == nil) goto v_20057;
    goto v_20069;
v_20065:
    v_20165 = stack[-3];
    goto v_20066;
v_20067:
    v_20164 = elt(env, 1); // minus
    goto v_20068;
v_20069:
    goto v_20065;
v_20066:
    goto v_20067;
v_20068:
    if (!consp(v_20165)) goto v_20063;
    v_20165 = qcar(v_20165);
    if (v_20165 == v_20164) goto v_20062;
    else goto v_20063;
v_20062:
    v_20164 = stack[-3];
    v_20164 = qcdr(v_20164);
    v_20164 = qcar(v_20164);
    stack[-3] = v_20164;
    goto v_20061;
v_20063:
    v_20164 = nil;
    goto v_20051;
v_20061:
    goto v_20055;
v_20057:
v_20055:
    v_20164 = stack[-3];
    if (is_number(v_20164)) goto v_20080;
    v_20164 = stack[-3];
    fn = elt(env, 5); // !*id2num
    v_20164 = (*qfn1(fn))(fn, v_20164);
    env = stack[-5];
    if (v_20164 == nil) goto v_20084;
    else goto v_20080;
v_20084:
    goto v_20081;
v_20080:
    v_20164 = nil;
    goto v_20051;
v_20081:
    v_20164 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_20164;
v_20091:
    goto v_20101;
v_20097:
    stack[0] = stack[-4];
    goto v_20098;
v_20099:
    v_20164 = qvalue(elt(env, 2)); // g_dvnames
    fn = elt(env, 6); // upbve
    v_20164 = (*qfn1(fn))(fn, v_20164);
    env = stack[-5];
    goto v_20100;
v_20101:
    goto v_20097;
v_20098:
    goto v_20099;
v_20100:
    v_20164 = (LispObject)lesseq2(stack[0], v_20164);
    v_20164 = v_20164 ? lisp_true : nil;
    env = stack[-5];
    if (v_20164 == nil) goto v_20094;
    else goto v_20095;
v_20094:
    goto v_20090;
v_20095:
    goto v_20114;
v_20110:
    stack[-1] = stack[-3];
    goto v_20111;
v_20112:
    goto v_20120;
v_20116:
    stack[0] = qvalue(elt(env, 2)); // g_dvnames
    goto v_20117;
v_20118:
    v_20164 = stack[-4];
    v_20164 = sub1(v_20164);
    env = stack[-5];
    goto v_20119;
v_20120:
    goto v_20116;
v_20117:
    goto v_20118;
v_20119:
    v_20164 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_20164-TAG_FIXNUM)/(16/CELL)));
    goto v_20113;
v_20114:
    goto v_20110;
v_20111:
    goto v_20112;
v_20113:
    if (equal(stack[-1], v_20164)) goto v_20108;
    else goto v_20109;
v_20108:
    v_20164 = stack[-4];
    stack[-2] = v_20164;
    v_20164 = qvalue(elt(env, 2)); // g_dvnames
    fn = elt(env, 6); // upbve
    v_20164 = (*qfn1(fn))(fn, v_20164);
    env = stack[-5];
    v_20164 = add1(v_20164);
    env = stack[-5];
    stack[-4] = v_20164;
    goto v_20107;
v_20109:
    v_20164 = stack[-4];
    v_20164 = add1(v_20164);
    env = stack[-5];
    stack[-4] = v_20164;
    goto v_20107;
v_20107:
    goto v_20091;
v_20090:
    goto v_20142;
v_20138:
    v_20165 = stack[-2];
    goto v_20139;
v_20140:
    v_20164 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20141;
v_20142:
    goto v_20138;
v_20139:
    goto v_20140;
v_20141:
    if (v_20165 == v_20164) goto v_20136;
    else goto v_20137;
v_20136:
    v_20164 = stack[-3];
    fn = elt(env, 7); // ad_splitname
    v_20164 = (*qfn1(fn))(fn, v_20164);
    env = stack[-5];
    v_20165 = v_20164;
    goto v_20155;
v_20151:
    v_20164 = v_20165;
    v_20164 = qcar(v_20164);
    goto v_20152;
v_20153:
    v_20166 = qvalue(elt(env, 3)); // g_dvbase
    goto v_20154;
v_20155:
    goto v_20151;
v_20152:
    goto v_20153;
v_20154:
    if (v_20164 == v_20166) goto v_20149;
    else goto v_20150;
v_20149:
    v_20164 = v_20165;
    v_20164 = qcdr(v_20164);
    goto v_20051;
v_20150:
    goto v_20135;
v_20137:
    v_20164 = stack[-2];
    goto v_20051;
v_20135:
    v_20164 = nil;
v_20051:
    return onevalue(v_20164);
}



// Code for difbf

static LispObject CC_difbf(LispObject env,
                         LispObject v_20045, LispObject v_20046)
{
    env = qenv(env);
    LispObject v_20299, v_20300, v_20301;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20045,v_20046);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-6] = v_20046;
    stack[-7] = v_20045;
// end of prologue
    goto v_20065;
v_20061:
    v_20299 = stack[-7];
    v_20299 = qcdr(v_20299);
    v_20300 = qcar(v_20299);
    stack[-8] = v_20300;
    goto v_20062;
v_20063:
    v_20299 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20064;
v_20065:
    goto v_20061;
v_20062:
    goto v_20063;
v_20064:
    if (v_20300 == v_20299) goto v_20059;
    else goto v_20060;
v_20059:
    v_20299 = stack[-6];
    fn = elt(env, 3); // minus!:
    v_20299 = (*qfn1(fn))(fn, v_20299);
    env = stack[-9];
    goto v_20056;
v_20060:
    goto v_20080;
v_20076:
    v_20299 = stack[-6];
    v_20299 = qcdr(v_20299);
    v_20300 = qcar(v_20299);
    stack[-5] = v_20300;
    goto v_20077;
v_20078:
    v_20299 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20079;
v_20080:
    goto v_20076;
v_20077:
    goto v_20078;
v_20079:
    if (v_20300 == v_20299) goto v_20074;
    else goto v_20075;
v_20074:
    v_20299 = stack[-7];
    goto v_20056;
v_20075:
    goto v_20094;
v_20090:
    goto v_20100;
v_20096:
    v_20299 = stack[-7];
    v_20299 = qcdr(v_20299);
    v_20300 = qcdr(v_20299);
    stack[-4] = v_20300;
    goto v_20097;
v_20098:
    v_20299 = stack[-6];
    v_20299 = qcdr(v_20299);
    v_20299 = qcdr(v_20299);
    stack[-3] = v_20299;
    goto v_20099;
v_20100:
    goto v_20096;
v_20097:
    goto v_20098;
v_20099:
    v_20300 = difference2(v_20300, v_20299);
    env = stack[-9];
    stack[-2] = v_20300;
    goto v_20091;
v_20092:
    v_20299 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20093;
v_20094:
    goto v_20090;
v_20091:
    goto v_20092;
v_20093:
    if (v_20300 == v_20299) goto v_20088;
    else goto v_20089;
v_20088:
    goto v_20115;
v_20109:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_20110;
v_20111:
    goto v_20122;
v_20118:
    v_20300 = stack[-8];
    goto v_20119;
v_20120:
    v_20299 = stack[-5];
    goto v_20121;
v_20122:
    goto v_20118;
v_20119:
    goto v_20120;
v_20121:
    v_20300 = difference2(v_20300, v_20299);
    env = stack[-9];
    goto v_20112;
v_20113:
    v_20299 = stack[-4];
    goto v_20114;
v_20115:
    goto v_20109;
v_20110:
    goto v_20111;
v_20112:
    goto v_20113;
v_20114:
    v_20299 = list2star(stack[0], v_20300, v_20299);
    env = stack[-9];
    goto v_20056;
v_20089:
    goto v_20131;
v_20127:
    stack[-1] = stack[-2];
    goto v_20128;
v_20129:
    goto v_20138;
v_20134:
    v_20299 = stack[-8];
    v_20299 = Labsval(nil, v_20299);
    env = stack[-9];
    fn = elt(env, 4); // msd
    stack[0] = (*qfn1(fn))(fn, v_20299);
    env = stack[-9];
    goto v_20135;
v_20136:
    v_20299 = stack[-5];
    v_20299 = Labsval(nil, v_20299);
    env = stack[-9];
    fn = elt(env, 4); // msd
    v_20299 = (*qfn1(fn))(fn, v_20299);
    env = stack[-9];
    goto v_20137;
v_20138:
    goto v_20134;
v_20135:
    goto v_20136;
v_20137:
    v_20299 = difference2(stack[0], v_20299);
    env = stack[-9];
    goto v_20130;
v_20131:
    goto v_20127;
v_20128:
    goto v_20129;
v_20130:
    v_20299 = plus2(stack[-1], v_20299);
    env = stack[-9];
    stack[-1] = v_20299;
    v_20299 = qvalue(elt(env, 2)); // !:bprec!:
    v_20299 = add1(v_20299);
    env = stack[-9];
    stack[0] = v_20299;
    goto v_20156;
v_20152:
    v_20300 = stack[-1];
    goto v_20153;
v_20154:
    v_20299 = stack[0];
    goto v_20155;
v_20156:
    goto v_20152;
v_20153:
    goto v_20154;
v_20155:
    v_20299 = (LispObject)greaterp2(v_20300, v_20299);
    v_20299 = v_20299 ? lisp_true : nil;
    env = stack[-9];
    if (v_20299 == nil) goto v_20150;
    v_20299 = stack[-7];
    goto v_20056;
v_20150:
    goto v_20169;
v_20165:
    goto v_20166;
v_20167:
    v_20299 = stack[0];
    v_20299 = negate(v_20299);
    env = stack[-9];
    goto v_20168;
v_20169:
    goto v_20165;
v_20166:
    goto v_20167;
v_20168:
    v_20299 = (LispObject)lessp2(stack[-1], v_20299);
    v_20299 = v_20299 ? lisp_true : nil;
    env = stack[-9];
    if (v_20299 == nil) goto v_20163;
    v_20299 = stack[-6];
    fn = elt(env, 3); // minus!:
    v_20299 = (*qfn1(fn))(fn, v_20299);
    env = stack[-9];
    goto v_20056;
v_20163:
    goto v_20184;
v_20180:
    v_20300 = stack[-2];
    goto v_20181;
v_20182:
    v_20299 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20183;
v_20184:
    goto v_20180;
v_20181:
    goto v_20182;
v_20183:
    v_20299 = (LispObject)greaterp2(v_20300, v_20299);
    v_20299 = v_20299 ? lisp_true : nil;
    env = stack[-9];
    if (v_20299 == nil) goto v_20178;
    goto v_20194;
v_20188:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_20189;
v_20190:
    goto v_20201;
v_20197:
    goto v_20207;
v_20203:
    v_20300 = stack[-8];
    goto v_20204;
v_20205:
    v_20299 = stack[-2];
    goto v_20206;
v_20207:
    goto v_20203;
v_20204:
    goto v_20205;
v_20206:
    fn = elt(env, 5); // ashift
    v_20300 = (*qfn2(fn))(fn, v_20300, v_20299);
    env = stack[-9];
    goto v_20198;
v_20199:
    v_20299 = stack[-5];
    goto v_20200;
v_20201:
    goto v_20197;
v_20198:
    goto v_20199;
v_20200:
    v_20300 = difference2(v_20300, v_20299);
    env = stack[-9];
    goto v_20191;
v_20192:
    v_20299 = stack[-3];
    goto v_20193;
v_20194:
    goto v_20188;
v_20189:
    goto v_20190;
v_20191:
    goto v_20192;
v_20193:
    v_20299 = list2star(stack[0], v_20300, v_20299);
    env = stack[-9];
    goto v_20056;
v_20178:
    goto v_20221;
v_20215:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_20216;
v_20217:
    goto v_20228;
v_20224:
    stack[-1] = stack[-8];
    goto v_20225;
v_20226:
    goto v_20235;
v_20231:
    stack[-3] = stack[-5];
    goto v_20232;
v_20233:
    v_20299 = stack[-2];
    v_20299 = negate(v_20299);
    env = stack[-9];
    goto v_20234;
v_20235:
    goto v_20231;
v_20232:
    goto v_20233;
v_20234:
    fn = elt(env, 5); // ashift
    v_20299 = (*qfn2(fn))(fn, stack[-3], v_20299);
    env = stack[-9];
    goto v_20227;
v_20228:
    goto v_20224;
v_20225:
    goto v_20226;
v_20227:
    v_20300 = difference2(stack[-1], v_20299);
    env = stack[-9];
    goto v_20218;
v_20219:
    v_20299 = stack[-4];
    goto v_20220;
v_20221:
    goto v_20215;
v_20216:
    goto v_20217;
v_20218:
    goto v_20219;
v_20220:
    v_20299 = list2star(stack[0], v_20300, v_20299);
    env = stack[-9];
    goto v_20056;
    v_20299 = nil;
v_20056:
    stack[-2] = v_20299;
    v_20299 = stack[-2];
    v_20299 = qcdr(v_20299);
    v_20299 = qcar(v_20299);
    v_20301 = v_20299;
    goto v_20255;
v_20251:
    v_20300 = v_20301;
    goto v_20252;
v_20253:
    v_20299 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20254;
v_20255:
    goto v_20251;
v_20252:
    goto v_20253;
v_20254:
    if (v_20300 == v_20299) goto v_20249;
    else goto v_20250;
v_20249:
    goto v_20265;
v_20259:
    v_20301 = elt(env, 1); // !:rd!:
    goto v_20260;
v_20261:
    v_20300 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20262;
v_20263:
    v_20299 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20264;
v_20265:
    goto v_20259;
v_20260:
    goto v_20261;
v_20262:
    goto v_20263;
v_20264:
    return list2star(v_20301, v_20300, v_20299);
v_20250:
    goto v_20274;
v_20270:
    v_20300 = v_20301;
    goto v_20271;
v_20272:
    v_20299 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_20273;
v_20274:
    goto v_20270;
v_20271:
    goto v_20272;
v_20273:
    fn = elt(env, 6); // inorm
    v_20299 = (*qfn2(fn))(fn, v_20300, v_20299);
    env = stack[-9];
    v_20301 = v_20299;
    goto v_20284;
v_20278:
    stack[-1] = elt(env, 1); // !:rd!:
    goto v_20279;
v_20280:
    v_20299 = v_20301;
    stack[0] = qcar(v_20299);
    goto v_20281;
v_20282:
    goto v_20293;
v_20289:
    v_20299 = v_20301;
    v_20300 = qcdr(v_20299);
    goto v_20290;
v_20291:
    v_20299 = stack[-2];
    v_20299 = qcdr(v_20299);
    v_20299 = qcdr(v_20299);
    goto v_20292;
v_20293:
    goto v_20289;
v_20290:
    goto v_20291;
v_20292:
    v_20299 = plus2(v_20300, v_20299);
    goto v_20283;
v_20284:
    goto v_20278;
v_20279:
    goto v_20280;
v_20281:
    goto v_20282;
v_20283:
    {
        LispObject v_20311 = stack[-1];
        LispObject v_20312 = stack[0];
        return list2star(v_20311, v_20312, v_20299);
    }
    return onevalue(v_20299);
}



// Code for order_of_der_mind

static LispObject CC_order_of_der_mind(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20051;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20051 = v_20045;
// end of prologue
    v_20051 = qcdr(v_20051);
    v_20051 = qcar(v_20051);
    {
        fn = elt(env, 1); // length_multiindex
        return (*qfn1(fn))(fn, v_20051);
    }
}



// Code for ext_mult

static LispObject CC_ext_mult(LispObject env,
                         LispObject v_20045, LispObject v_20046)
{
    env = qenv(env);
    LispObject v_20121, v_20122, v_20123;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20045,v_20046);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_20121 = v_20046;
    v_20122 = v_20045;
// end of prologue
    goto v_20053;
v_20049:
    v_20122 = qcdr(v_20122);
    goto v_20050;
v_20051:
    v_20121 = qcdr(v_20121);
    goto v_20052;
v_20053:
    goto v_20049;
v_20050:
    goto v_20051;
v_20052:
    fn = elt(env, 2); // merge_lists
    v_20121 = (*qfn2(fn))(fn, v_20122, v_20121);
    env = stack[-1];
    stack[0] = v_20121;
    v_20121 = stack[0];
    if (v_20121 == nil) goto v_20061;
    else goto v_20062;
v_20061:
    goto v_20069;
v_20065:
    v_20122 = nil;
    goto v_20066;
v_20067:
    v_20121 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20068;
v_20069:
    goto v_20065;
v_20066:
    goto v_20067;
v_20068:
    return cons(v_20122, v_20121);
v_20062:
    v_20121 = stack[0];
    v_20121 = qcdr(v_20121);
    if (v_20121 == nil) goto v_20072;
    else goto v_20073;
v_20072:
    goto v_20081;
v_20077:
    v_20122 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20078;
v_20079:
    v_20121 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20080;
v_20081:
    goto v_20077;
v_20078:
    goto v_20079;
v_20080:
    return cons(v_20122, v_20121);
v_20073:
    goto v_20093;
v_20087:
    goto v_20099;
v_20095:
    goto v_20105;
v_20101:
    goto v_20112;
v_20108:
    v_20122 = elt(env, 1); // ext
    goto v_20109;
v_20110:
    v_20121 = stack[0];
    v_20121 = qcdr(v_20121);
    goto v_20111;
v_20112:
    goto v_20108;
v_20109:
    goto v_20110;
v_20111:
    v_20121 = cons(v_20122, v_20121);
    env = stack[-1];
    fn = elt(env, 3); // !*a2k
    v_20122 = (*qfn1(fn))(fn, v_20121);
    env = stack[-1];
    goto v_20102;
v_20103:
    v_20121 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20104;
v_20105:
    goto v_20101;
v_20102:
    goto v_20103;
v_20104:
    fn = elt(env, 4); // to
    v_20122 = (*qfn2(fn))(fn, v_20122, v_20121);
    env = stack[-1];
    goto v_20096;
v_20097:
    v_20121 = stack[0];
    v_20121 = qcar(v_20121);
    goto v_20098;
v_20099:
    goto v_20095;
v_20096:
    goto v_20097;
v_20098:
    v_20123 = cons(v_20122, v_20121);
    goto v_20088;
v_20089:
    v_20122 = nil;
    goto v_20090;
v_20091:
    v_20121 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20092;
v_20093:
    goto v_20087;
v_20088:
    goto v_20089;
v_20090:
    goto v_20091;
v_20092:
    return acons(v_20123, v_20122, v_20121);
    v_20121 = nil;
    return onevalue(v_20121);
}



// Code for bc_mkat

static LispObject CC_bc_mkat(LispObject env,
                         LispObject v_20045, LispObject v_20046)
{
    env = qenv(env);
    LispObject v_20060, v_20061, v_20062;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20060 = v_20046;
    v_20061 = v_20045;
// end of prologue
    goto v_20055;
v_20049:
    v_20062 = v_20061;
    goto v_20050;
v_20051:
    v_20061 = qcar(v_20060);
    goto v_20052;
v_20053:
    v_20060 = nil;
    goto v_20054;
v_20055:
    goto v_20049;
v_20050:
    goto v_20051;
v_20052:
    goto v_20053;
v_20054:
    return list3(v_20062, v_20061, v_20060);
}



// Code for ithlistelem

static LispObject CC_ithlistelem(LispObject env,
                         LispObject v_20045, LispObject v_20046)
{
    env = qenv(env);
    LispObject v_20079, v_20080;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20045,v_20046);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20046;
    stack[-1] = v_20045;
// end of prologue
    v_20079 = stack[-1];
    if (v_20079 == nil) goto v_20053;
    goto v_20060;
v_20056:
    goto v_20066;
v_20062:
    v_20079 = stack[-1];
    v_20080 = qcar(v_20079);
    goto v_20063;
v_20064:
    v_20079 = stack[0];
    goto v_20065;
v_20066:
    goto v_20062;
v_20063:
    goto v_20064;
v_20065:
    fn = elt(env, 1); // nth
    stack[-2] = (*qfn2(fn))(fn, v_20080, v_20079);
    env = stack[-3];
    goto v_20057;
v_20058:
    goto v_20075;
v_20071:
    v_20079 = stack[-1];
    v_20080 = qcdr(v_20079);
    goto v_20072;
v_20073:
    v_20079 = stack[0];
    goto v_20074;
v_20075:
    goto v_20071;
v_20072:
    goto v_20073;
v_20074:
    v_20079 = CC_ithlistelem(elt(env, 0), v_20080, v_20079);
    goto v_20059;
v_20060:
    goto v_20056;
v_20057:
    goto v_20058;
v_20059:
    {
        LispObject v_20084 = stack[-2];
        return cons(v_20084, v_20079);
    }
v_20053:
    v_20079 = nil;
    return onevalue(v_20079);
}



// Code for maxl

static LispObject CC_maxl(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20088, v_20089;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_20045;
// end of prologue
    stack[-1] = nil;
v_20051:
    v_20088 = stack[0];
    if (v_20088 == nil) goto v_20056;
    else goto v_20057;
v_20056:
    goto v_20052;
v_20057:
    goto v_20064;
v_20060:
    v_20088 = stack[0];
    v_20089 = qcar(v_20088);
    goto v_20061;
v_20062:
    v_20088 = stack[-1];
    goto v_20063;
v_20064:
    goto v_20060;
v_20061:
    goto v_20062;
v_20063:
    v_20088 = cons(v_20089, v_20088);
    env = stack[-2];
    stack[-1] = v_20088;
    v_20088 = stack[0];
    v_20088 = qcdr(v_20088);
    stack[0] = v_20088;
    goto v_20051;
v_20052:
    v_20088 = (LispObject)-160000+TAG_FIXNUM; // -10000
    v_20089 = v_20088;
v_20053:
    v_20088 = stack[-1];
    if (v_20088 == nil) goto v_20073;
    else goto v_20074;
v_20073:
    v_20088 = v_20089;
    goto v_20050;
v_20074:
    goto v_20082;
v_20078:
    v_20088 = stack[-1];
    v_20088 = qcar(v_20088);
    goto v_20079;
v_20080:
    goto v_20081;
v_20082:
    goto v_20078;
v_20079:
    goto v_20080;
v_20081:
    fn = elt(env, 1); // max
    v_20088 = (*qfn2(fn))(fn, v_20088, v_20089);
    env = stack[-2];
    v_20089 = v_20088;
    v_20088 = stack[-1];
    v_20088 = qcdr(v_20088);
    stack[-1] = v_20088;
    goto v_20053;
v_20050:
    return onevalue(v_20088);
}



// Code for make!-unique!-freevars

static LispObject CC_makeKuniqueKfreevars(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20157, v_20158, v_20159;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_20158 = v_20045;
// end of prologue
    v_20157 = v_20158;
    if (!consp(v_20157)) goto v_20049;
    else goto v_20050;
v_20049:
    goto v_20061;
v_20057:
    v_20159 = v_20158;
    goto v_20058;
v_20059:
    v_20157 = elt(env, 1); // gen
    goto v_20060;
v_20061:
    goto v_20057;
v_20058:
    goto v_20059;
v_20060:
    v_20157 = get(v_20159, v_20157);
    env = stack[-4];
    if (v_20157 == nil) goto v_20055;
    goto v_20071;
v_20067:
    v_20159 = v_20158;
    goto v_20068;
v_20069:
    v_20157 = qvalue(elt(env, 2)); // freevarlist!*
    goto v_20070;
v_20071:
    goto v_20067;
v_20068:
    goto v_20069;
v_20070:
    v_20157 = Latsoc(nil, v_20159, v_20157);
    stack[0] = v_20157;
    v_20157 = stack[0];
    if (v_20157 == nil) goto v_20077;
    else goto v_20078;
v_20077:
    goto v_20085;
v_20081:
    stack[0] = v_20158;
    goto v_20082;
v_20083:
    fn = elt(env, 3); // pm!:gensym
    v_20157 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_20084;
v_20085:
    goto v_20081;
v_20082:
    goto v_20083;
v_20084:
    v_20157 = cons(stack[0], v_20157);
    env = stack[-4];
    stack[0] = v_20157;
    goto v_20095;
v_20089:
    v_20157 = stack[0];
    v_20159 = qcdr(v_20157);
    goto v_20090;
v_20091:
    v_20158 = elt(env, 1); // gen
    goto v_20092;
v_20093:
    v_20157 = lisp_true;
    goto v_20094;
v_20095:
    goto v_20089;
v_20090:
    goto v_20091;
v_20092:
    goto v_20093;
v_20094:
    v_20157 = Lputprop(nil, 3, v_20159, v_20158, v_20157);
    env = stack[-4];
    goto v_20105;
v_20101:
    v_20158 = stack[0];
    goto v_20102;
v_20103:
    v_20157 = qvalue(elt(env, 2)); // freevarlist!*
    goto v_20104;
v_20105:
    goto v_20101;
v_20102:
    goto v_20103;
v_20104:
    v_20157 = cons(v_20158, v_20157);
    env = stack[-4];
    qvalue(elt(env, 2)) = v_20157; // freevarlist!*
    goto v_20076;
v_20078:
v_20076:
    v_20157 = stack[0];
    v_20157 = qcdr(v_20157);
    goto v_20053;
v_20055:
    v_20157 = v_20158;
    goto v_20053;
    v_20157 = nil;
v_20053:
    goto v_20048;
v_20050:
    v_20157 = v_20158;
    stack[-3] = v_20157;
    v_20157 = stack[-3];
    if (v_20157 == nil) goto v_20124;
    else goto v_20125;
v_20124:
    v_20157 = nil;
    goto v_20119;
v_20125:
    v_20157 = stack[-3];
    v_20157 = qcar(v_20157);
    v_20157 = CC_makeKuniqueKfreevars(elt(env, 0), v_20157);
    env = stack[-4];
    v_20157 = ncons(v_20157);
    env = stack[-4];
    stack[-1] = v_20157;
    stack[-2] = v_20157;
v_20120:
    v_20157 = stack[-3];
    v_20157 = qcdr(v_20157);
    stack[-3] = v_20157;
    v_20157 = stack[-3];
    if (v_20157 == nil) goto v_20138;
    else goto v_20139;
v_20138:
    v_20157 = stack[-2];
    goto v_20119;
v_20139:
    goto v_20147;
v_20143:
    stack[0] = stack[-1];
    goto v_20144;
v_20145:
    v_20157 = stack[-3];
    v_20157 = qcar(v_20157);
    v_20157 = CC_makeKuniqueKfreevars(elt(env, 0), v_20157);
    env = stack[-4];
    v_20157 = ncons(v_20157);
    env = stack[-4];
    goto v_20146;
v_20147:
    goto v_20143;
v_20144:
    goto v_20145;
v_20146:
    v_20157 = Lrplacd(nil, stack[0], v_20157);
    env = stack[-4];
    v_20157 = stack[-1];
    v_20157 = qcdr(v_20157);
    stack[-1] = v_20157;
    goto v_20120;
v_20119:
    goto v_20048;
    v_20157 = nil;
v_20048:
    return onevalue(v_20157);
}



// Code for noncomexpf

static LispObject CC_noncomexpf(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20083;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_20045;
// end of prologue
v_20044:
    v_20083 = stack[0];
    if (!consp(v_20083)) goto v_20053;
    else goto v_20054;
v_20053:
    v_20083 = lisp_true;
    goto v_20052;
v_20054:
    v_20083 = stack[0];
    v_20083 = qcar(v_20083);
    v_20083 = (consp(v_20083) ? nil : lisp_true);
    goto v_20052;
    v_20083 = nil;
v_20052:
    if (v_20083 == nil) goto v_20049;
    else goto v_20050;
v_20049:
    v_20083 = stack[0];
    v_20083 = qcar(v_20083);
    v_20083 = qcar(v_20083);
    v_20083 = qcar(v_20083);
    fn = elt(env, 1); // noncomp
    v_20083 = (*qfn1(fn))(fn, v_20083);
    env = stack[-1];
    if (v_20083 == nil) goto v_20064;
    else goto v_20063;
v_20064:
    v_20083 = stack[0];
    v_20083 = qcar(v_20083);
    v_20083 = qcdr(v_20083);
    v_20083 = CC_noncomexpf(elt(env, 0), v_20083);
    env = stack[-1];
    if (v_20083 == nil) goto v_20072;
    else goto v_20071;
v_20072:
    v_20083 = stack[0];
    v_20083 = qcdr(v_20083);
    stack[0] = v_20083;
    goto v_20044;
v_20071:
v_20063:
    goto v_20048;
v_20050:
    v_20083 = nil;
    goto v_20048;
    v_20083 = nil;
v_20048:
    return onevalue(v_20083);
}



// Code for getrlist

static LispObject CC_getrlist(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20089, v_20090, v_20091;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20091 = v_20045;
// end of prologue
    goto v_20056;
v_20052:
    v_20090 = v_20091;
    goto v_20053;
v_20054:
    v_20089 = elt(env, 1); // list
    goto v_20055;
v_20056:
    goto v_20052;
v_20053:
    goto v_20054;
v_20055:
    if (!consp(v_20090)) goto v_20050;
    v_20090 = qcar(v_20090);
    if (v_20090 == v_20089) goto v_20049;
    else goto v_20050;
v_20049:
    v_20089 = v_20091;
    v_20089 = qcdr(v_20089);
    goto v_20048;
v_20050:
    goto v_20068;
v_20064:
    goto v_20078;
v_20074:
    v_20090 = v_20091;
    goto v_20075;
v_20076:
    v_20089 = elt(env, 2); // !*sq
    goto v_20077;
v_20078:
    goto v_20074;
v_20075:
    goto v_20076;
v_20077:
    if (!consp(v_20090)) goto v_20072;
    v_20090 = qcar(v_20090);
    if (v_20090 == v_20089) goto v_20071;
    else goto v_20072;
v_20071:
    v_20089 = v_20091;
    v_20089 = qcdr(v_20089);
    v_20089 = qcar(v_20089);
    fn = elt(env, 4); // prepsq
    v_20089 = (*qfn1(fn))(fn, v_20089);
    env = stack[0];
    v_20090 = v_20089;
    goto v_20070;
v_20072:
    v_20089 = v_20091;
    v_20090 = v_20089;
    goto v_20070;
    v_20090 = nil;
v_20070:
    goto v_20065;
v_20066:
    v_20089 = elt(env, 3); // "list"
    goto v_20067;
v_20068:
    goto v_20064;
v_20065:
    goto v_20066;
v_20067:
    {
        fn = elt(env, 5); // typerr
        return (*qfn2(fn))(fn, v_20090, v_20089);
    }
    v_20089 = nil;
v_20048:
    return onevalue(v_20089);
}



// Code for chkint!*

static LispObject CC_chkintH(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20152, v_20153, v_20154;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_20045;
// end of prologue
    v_20152 = qvalue(elt(env, 1)); // !*!*roundbf
    if (v_20152 == nil) goto v_20050;
    v_20152 = stack[0];
    v_20152 = Lfloatp(nil, v_20152);
    env = stack[-1];
    if (v_20152 == nil) goto v_20055;
    v_20152 = stack[0];
    {
        fn = elt(env, 4); // fl2bf
        return (*qfn1(fn))(fn, v_20152);
    }
v_20055:
    v_20152 = stack[0];
    if (!consp(v_20152)) goto v_20066;
    v_20152 = stack[0];
    goto v_20064;
v_20066:
    v_20152 = stack[0];
    v_20152 = integerp(v_20152);
    if (v_20152 == nil) goto v_20070;
    goto v_20080;
v_20074:
    v_20154 = elt(env, 2); // !:rd!:
    goto v_20075;
v_20076:
    v_20153 = stack[0];
    goto v_20077;
v_20078:
    v_20152 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20079;
v_20080:
    goto v_20074;
v_20075:
    goto v_20076;
v_20077:
    goto v_20078;
v_20079:
    v_20152 = list2star(v_20154, v_20153, v_20152);
    env = stack[-1];
    goto v_20064;
v_20070:
    v_20152 = stack[0];
    fn = elt(env, 5); // read!:num
    v_20152 = (*qfn1(fn))(fn, v_20152);
    env = stack[-1];
    goto v_20064;
    v_20152 = nil;
v_20064:
    {
        fn = elt(env, 6); // normbf
        return (*qfn1(fn))(fn, v_20152);
    }
    v_20152 = nil;
    goto v_20048;
v_20050:
    v_20152 = stack[0];
    v_20152 = Labsval(nil, v_20152);
    env = stack[-1];
    v_20153 = v_20152;
    v_20152 = stack[0];
    v_20152 = Lfloatp(nil, v_20152);
    env = stack[-1];
    if (v_20152 == nil) goto v_20096;
    v_20152 = stack[0];
    goto v_20094;
v_20096:
    goto v_20107;
v_20103:
    v_20152 = v_20153;
    fn = elt(env, 7); // msd
    v_20153 = (*qfn1(fn))(fn, v_20152);
    env = stack[-1];
    goto v_20104;
v_20105:
    v_20152 = qvalue(elt(env, 3)); // !!maxbflexp
    goto v_20106;
v_20107:
    goto v_20103;
v_20104:
    goto v_20105;
v_20106:
    v_20152 = (LispObject)lesseq2(v_20153, v_20152);
    v_20152 = v_20152 ? lisp_true : nil;
    env = stack[-1];
    if (v_20152 == nil) goto v_20101;
    v_20152 = stack[0];
        return Lfloat(nil, v_20152);
v_20101:
    fn = elt(env, 8); // rndbfon
    v_20152 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_20152 = stack[0];
    v_20152 = Lfloatp(nil, v_20152);
    env = stack[-1];
    if (v_20152 == nil) goto v_20119;
    v_20152 = stack[0];
    {
        fn = elt(env, 4); // fl2bf
        return (*qfn1(fn))(fn, v_20152);
    }
v_20119:
    v_20152 = stack[0];
    if (!consp(v_20152)) goto v_20130;
    v_20152 = stack[0];
    goto v_20128;
v_20130:
    v_20152 = stack[0];
    v_20152 = integerp(v_20152);
    if (v_20152 == nil) goto v_20134;
    goto v_20144;
v_20138:
    v_20154 = elt(env, 2); // !:rd!:
    goto v_20139;
v_20140:
    v_20153 = stack[0];
    goto v_20141;
v_20142:
    v_20152 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20143;
v_20144:
    goto v_20138;
v_20139:
    goto v_20140;
v_20141:
    goto v_20142;
v_20143:
    v_20152 = list2star(v_20154, v_20153, v_20152);
    env = stack[-1];
    goto v_20128;
v_20134:
    v_20152 = stack[0];
    fn = elt(env, 5); // read!:num
    v_20152 = (*qfn1(fn))(fn, v_20152);
    env = stack[-1];
    goto v_20128;
    v_20152 = nil;
v_20128:
    {
        fn = elt(env, 6); // normbf
        return (*qfn1(fn))(fn, v_20152);
    }
    v_20152 = nil;
    goto v_20094;
    v_20152 = nil;
v_20094:
    goto v_20048;
    v_20152 = nil;
v_20048:
    return onevalue(v_20152);
}



// Code for indordl2

static LispObject CC_indordl2(LispObject env,
                         LispObject v_20045, LispObject v_20046)
{
    env = qenv(env);
    LispObject v_20078, v_20079;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20045,v_20046);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_20046;
    stack[-1] = v_20045;
// end of prologue
    goto v_20057;
v_20053:
    v_20079 = stack[-1];
    goto v_20054;
v_20055:
    v_20078 = stack[0];
    goto v_20056;
v_20057:
    goto v_20053;
v_20054:
    goto v_20055;
v_20056:
    fn = elt(env, 1); // indordlp
    v_20078 = (*qfn2(fn))(fn, v_20079, v_20078);
    if (v_20078 == nil) goto v_20051;
    goto v_20065;
v_20061:
    v_20079 = stack[-1];
    goto v_20062;
v_20063:
    v_20078 = stack[0];
    goto v_20064;
v_20065:
    goto v_20061;
v_20062:
    goto v_20063;
v_20064:
    return list2(v_20079, v_20078);
v_20051:
    goto v_20075;
v_20071:
    v_20079 = stack[0];
    goto v_20072;
v_20073:
    v_20078 = stack[-1];
    goto v_20074;
v_20075:
    goto v_20071;
v_20072:
    goto v_20073;
v_20074:
    return list2(v_20079, v_20078);
    v_20078 = nil;
    return onevalue(v_20078);
}



// Code for liennewstruc

static LispObject CC_liennewstruc(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20814, v_20815, v_20816, v_20817;
    LispObject fn;
    LispObject v_20047, v_20046, v_20045;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "liennewstruc");
    va_start(aa, nargs);
    v_20045 = va_arg(aa, LispObject);
    v_20046 = va_arg(aa, LispObject);
    v_20047 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20047,v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20045,v_20046,v_20047);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(17);
// copy arguments values to proper place
    stack[-12] = v_20047;
    stack[-13] = v_20046;
    stack[-14] = v_20045;
// end of prologue
    goto v_20061;
v_20055:
    v_20816 = elt(env, 1); // lie_a
    goto v_20056;
v_20057:
    v_20815 = stack[-14];
    goto v_20058;
v_20059:
    v_20814 = stack[-14];
    goto v_20060;
v_20061:
    goto v_20055;
v_20056:
    goto v_20057;
v_20058:
    goto v_20059;
v_20060:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    v_20814 = ncons(v_20814);
    env = stack[-16];
    fn = elt(env, 11); // matrix
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    fn = elt(env, 12); // aeval
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    goto v_20070;
v_20066:
    stack[0] = elt(env, 1); // lie_a
    goto v_20067;
v_20068:
    goto v_20080;
v_20074:
    v_20816 = elt(env, 2); // expt
    goto v_20075;
v_20076:
    v_20815 = elt(env, 1); // lie_a
    goto v_20077;
v_20078:
    v_20814 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20079;
v_20080:
    goto v_20074;
v_20075:
    goto v_20076;
v_20077:
    goto v_20078;
v_20079:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 12); // aeval
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    goto v_20069;
v_20070:
    goto v_20066;
v_20067:
    goto v_20068;
v_20069:
    fn = elt(env, 13); // setk
    v_20814 = (*qfn2(fn))(fn, stack[0], v_20814);
    env = stack[-16];
    v_20814 = stack[-13];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    stack[-15] = v_20814;
v_20087:
    goto v_20102;
v_20096:
    stack[0] = elt(env, 3); // difference
    goto v_20097;
v_20098:
    goto v_20112;
v_20106:
    v_20816 = elt(env, 3); // difference
    goto v_20107;
v_20108:
    v_20815 = stack[-14];
    goto v_20109;
v_20110:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20111;
v_20112:
    goto v_20106;
v_20107:
    goto v_20108;
v_20109:
    goto v_20110;
v_20111:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20815 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    goto v_20099;
v_20100:
    v_20814 = stack[-15];
    goto v_20101;
v_20102:
    goto v_20096;
v_20097:
    goto v_20098;
v_20099:
    goto v_20100;
v_20101:
    v_20814 = list3(stack[0], v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    if (v_20814 == nil) goto v_20093;
    goto v_20086;
v_20093:
    goto v_20130;
v_20124:
    v_20816 = elt(env, 4); // plus
    goto v_20125;
v_20126:
    v_20815 = stack[-15];
    goto v_20127;
v_20128:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20129;
v_20130:
    goto v_20124;
v_20125:
    goto v_20126;
v_20127:
    goto v_20128;
v_20129:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    stack[-11] = v_20814;
v_20121:
    goto v_20146;
v_20140:
    stack[0] = elt(env, 3); // difference
    goto v_20141;
v_20142:
    v_20814 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_20815 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    goto v_20143;
v_20144:
    v_20814 = stack[-11];
    goto v_20145;
v_20146:
    goto v_20140;
v_20141:
    goto v_20142;
v_20143:
    goto v_20144;
v_20145:
    v_20814 = list3(stack[0], v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    if (v_20814 == nil) goto v_20137;
    goto v_20120;
v_20137:
    goto v_20157;
v_20153:
    goto v_20165;
v_20159:
    v_20816 = elt(env, 5); // lie_lamb
    goto v_20160;
v_20161:
    v_20815 = stack[-15];
    goto v_20162;
v_20163:
    v_20814 = stack[-11];
    goto v_20164;
v_20165:
    goto v_20159;
v_20160:
    goto v_20161;
v_20162:
    goto v_20163;
v_20164:
    stack[-10] = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    goto v_20154;
v_20155:
    goto v_20177;
v_20171:
    stack[-9] = elt(env, 6); // quotient
    goto v_20172;
v_20173:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_20814;
    v_20814 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_20814;
v_20183:
    goto v_20198;
v_20192:
    stack[0] = elt(env, 3); // difference
    goto v_20193;
v_20194:
    v_20814 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_20815 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    goto v_20195;
v_20196:
    v_20814 = stack[-8];
    goto v_20197;
v_20198:
    goto v_20192;
v_20193:
    goto v_20194;
v_20195:
    goto v_20196;
v_20197:
    v_20814 = list3(stack[0], v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    if (v_20814 == nil) goto v_20189;
    v_20814 = stack[-7];
    stack[0] = v_20814;
    goto v_20182;
v_20189:
    goto v_20212;
v_20206:
    stack[-6] = elt(env, 4); // plus
    goto v_20207;
v_20208:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_20814;
    v_20814 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_20814;
v_20218:
    goto v_20233;
v_20227:
    stack[0] = elt(env, 3); // difference
    goto v_20228;
v_20229:
    v_20814 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_20815 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    goto v_20230;
v_20231:
    v_20814 = stack[-5];
    goto v_20232;
v_20233:
    goto v_20227;
v_20228:
    goto v_20229;
v_20230:
    goto v_20231;
v_20232:
    v_20814 = list3(stack[0], v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    if (v_20814 == nil) goto v_20224;
    v_20814 = stack[-4];
    v_20815 = v_20814;
    goto v_20217;
v_20224:
    goto v_20247;
v_20241:
    stack[-3] = elt(env, 4); // plus
    goto v_20242;
v_20243:
    goto v_20259;
v_20251:
    stack[-2] = elt(env, 7); // times
    goto v_20252;
v_20253:
    goto v_20268;
v_20262:
    v_20816 = elt(env, 8); // lientrans
    goto v_20263;
v_20264:
    v_20815 = stack[-15];
    goto v_20265;
v_20266:
    v_20814 = stack[-8];
    goto v_20267;
v_20268:
    goto v_20262;
v_20263:
    goto v_20264;
v_20265:
    goto v_20266;
v_20267:
    stack[-1] = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    goto v_20254;
v_20255:
    goto v_20279;
v_20273:
    v_20816 = elt(env, 8); // lientrans
    goto v_20274;
v_20275:
    v_20815 = stack[-11];
    goto v_20276;
v_20277:
    v_20814 = stack[-5];
    goto v_20278;
v_20279:
    goto v_20273;
v_20274:
    goto v_20275;
v_20276:
    goto v_20277;
v_20278:
    stack[0] = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    goto v_20256;
v_20257:
    goto v_20292;
v_20284:
    v_20817 = elt(env, 9); // lie_cc
    goto v_20285;
v_20286:
    v_20816 = stack[-8];
    goto v_20287;
v_20288:
    v_20815 = stack[-5];
    goto v_20289;
v_20290:
    v_20814 = stack[-12];
    goto v_20291;
v_20292:
    goto v_20284;
v_20285:
    goto v_20286;
v_20287:
    goto v_20288;
v_20289:
    goto v_20290;
v_20291:
    v_20814 = list4(v_20817, v_20816, v_20815, v_20814);
    env = stack[-16];
    goto v_20258;
v_20259:
    goto v_20251;
v_20252:
    goto v_20253;
v_20254:
    goto v_20255;
v_20256:
    goto v_20257;
v_20258:
    v_20814 = list4(stack[-2], stack[-1], stack[0], v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20815 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    goto v_20244;
v_20245:
    v_20814 = stack[-4];
    goto v_20246;
v_20247:
    goto v_20241;
v_20242:
    goto v_20243;
v_20244:
    goto v_20245;
v_20246:
    v_20814 = list3(stack[-3], v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    stack[-4] = v_20814;
    v_20814 = stack[-5];
    goto v_20308;
v_20302:
    v_20816 = elt(env, 4); // plus
    goto v_20303;
v_20304:
    v_20815 = v_20814;
    goto v_20305;
v_20306:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20307;
v_20308:
    goto v_20302;
v_20303:
    goto v_20304;
v_20305:
    goto v_20306;
v_20307:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    stack[-5] = v_20814;
    goto v_20218;
v_20217:
    goto v_20209;
v_20210:
    v_20814 = stack[-7];
    goto v_20211;
v_20212:
    goto v_20206;
v_20207:
    goto v_20208;
v_20209:
    goto v_20210;
v_20211:
    v_20814 = list3(stack[-6], v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    stack[-7] = v_20814;
    v_20814 = stack[-8];
    goto v_20323;
v_20317:
    v_20816 = elt(env, 4); // plus
    goto v_20318;
v_20319:
    v_20815 = v_20814;
    goto v_20320;
v_20321:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20322;
v_20323:
    goto v_20317;
v_20318:
    goto v_20319;
v_20320:
    goto v_20321;
v_20322:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    stack[-8] = v_20814;
    goto v_20183;
v_20182:
    goto v_20174;
v_20175:
    goto v_20334;
v_20328:
    v_20816 = elt(env, 8); // lientrans
    goto v_20329;
v_20330:
    v_20815 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20331;
v_20332:
    v_20814 = stack[-12];
    goto v_20333;
v_20334:
    goto v_20328;
v_20329:
    goto v_20330;
v_20331:
    goto v_20332;
v_20333:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    goto v_20176;
v_20177:
    goto v_20171;
v_20172:
    goto v_20173;
v_20174:
    goto v_20175;
v_20176:
    v_20814 = list3(stack[-9], stack[0], v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    goto v_20156;
v_20157:
    goto v_20153;
v_20154:
    goto v_20155;
v_20156:
    fn = elt(env, 13); // setk
    v_20814 = (*qfn2(fn))(fn, stack[-10], v_20814);
    env = stack[-16];
    v_20814 = stack[-11];
    goto v_20348;
v_20342:
    v_20816 = elt(env, 4); // plus
    goto v_20343;
v_20344:
    v_20815 = v_20814;
    goto v_20345;
v_20346:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20347;
v_20348:
    goto v_20342;
v_20343:
    goto v_20344;
v_20345:
    goto v_20346;
v_20347:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    stack[-11] = v_20814;
    goto v_20121;
v_20120:
    v_20814 = stack[-15];
    goto v_20362;
v_20356:
    v_20816 = elt(env, 4); // plus
    goto v_20357;
v_20358:
    v_20815 = v_20814;
    goto v_20359;
v_20360:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20361;
v_20362:
    goto v_20356;
v_20357:
    goto v_20358;
v_20359:
    goto v_20360;
v_20361:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    stack[-15] = v_20814;
    goto v_20087;
v_20086:
    goto v_20378;
v_20372:
    v_20816 = elt(env, 4); // plus
    goto v_20373;
v_20374:
    v_20815 = stack[-13];
    goto v_20375;
v_20376:
    v_20814 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_20377;
v_20378:
    goto v_20372;
v_20373:
    goto v_20374;
v_20375:
    goto v_20376;
v_20377:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    stack[-2] = v_20814;
v_20369:
    goto v_20394;
v_20388:
    stack[0] = elt(env, 3); // difference
    goto v_20389;
v_20390:
    v_20814 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_20815 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    goto v_20391;
v_20392:
    v_20814 = stack[-2];
    goto v_20393;
v_20394:
    goto v_20388;
v_20389:
    goto v_20390;
v_20391:
    goto v_20392;
v_20393:
    v_20814 = list3(stack[0], v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    if (v_20814 == nil) goto v_20385;
    goto v_20368;
v_20385:
    goto v_20405;
v_20401:
    goto v_20413;
v_20407:
    stack[-1] = elt(env, 1); // lie_a
    goto v_20408;
v_20409:
    stack[0] = stack[-2];
    goto v_20410;
v_20411:
    goto v_20423;
v_20417:
    v_20816 = elt(env, 4); // plus
    goto v_20418;
v_20419:
    v_20815 = stack[-13];
    goto v_20420;
v_20421:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20422;
v_20423:
    goto v_20417;
v_20418:
    goto v_20419;
v_20420:
    goto v_20421;
v_20422:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    goto v_20412;
v_20413:
    goto v_20407;
v_20408:
    goto v_20409;
v_20410:
    goto v_20411;
v_20412:
    stack[-1] = list3(stack[-1], stack[0], v_20814);
    env = stack[-16];
    goto v_20402;
v_20403:
    goto v_20433;
v_20429:
    stack[0] = elt(env, 10); // minus
    goto v_20430;
v_20431:
    goto v_20442;
v_20436:
    v_20816 = elt(env, 5); // lie_lamb
    goto v_20437;
v_20438:
    v_20815 = stack[-13];
    goto v_20439;
v_20440:
    v_20814 = stack[-2];
    goto v_20441;
v_20442:
    goto v_20436;
v_20437:
    goto v_20438;
v_20439:
    goto v_20440;
v_20441:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    goto v_20432;
v_20433:
    goto v_20429;
v_20430:
    goto v_20431;
v_20432:
    v_20814 = list2(stack[0], v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    goto v_20404;
v_20405:
    goto v_20401;
v_20402:
    goto v_20403;
v_20404:
    fn = elt(env, 13); // setk
    v_20814 = (*qfn2(fn))(fn, stack[-1], v_20814);
    env = stack[-16];
    goto v_20451;
v_20447:
    goto v_20459;
v_20453:
    v_20816 = elt(env, 1); // lie_a
    goto v_20454;
v_20455:
    v_20815 = stack[-2];
    goto v_20456;
v_20457:
    v_20814 = stack[-13];
    goto v_20458;
v_20459:
    goto v_20453;
v_20454:
    goto v_20455;
v_20456:
    goto v_20457;
v_20458:
    stack[-1] = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    goto v_20448;
v_20449:
    goto v_20471;
v_20465:
    stack[0] = elt(env, 5); // lie_lamb
    goto v_20466;
v_20467:
    goto v_20480;
v_20474:
    v_20816 = elt(env, 4); // plus
    goto v_20475;
v_20476:
    v_20815 = stack[-13];
    goto v_20477;
v_20478:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20479;
v_20480:
    goto v_20474;
v_20475:
    goto v_20476;
v_20477:
    goto v_20478;
v_20479:
    v_20815 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    goto v_20468;
v_20469:
    v_20814 = stack[-2];
    goto v_20470;
v_20471:
    goto v_20465;
v_20466:
    goto v_20467;
v_20468:
    goto v_20469;
v_20470:
    v_20814 = list3(stack[0], v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    goto v_20450;
v_20451:
    goto v_20447;
v_20448:
    goto v_20449;
v_20450:
    fn = elt(env, 13); // setk
    v_20814 = (*qfn2(fn))(fn, stack[-1], v_20814);
    env = stack[-16];
    v_20814 = stack[-2];
    goto v_20495;
v_20489:
    v_20816 = elt(env, 4); // plus
    goto v_20490;
v_20491:
    v_20815 = v_20814;
    goto v_20492;
v_20493:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20494;
v_20495:
    goto v_20489;
v_20490:
    goto v_20491;
v_20492:
    goto v_20493;
v_20494:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    stack[-2] = v_20814;
    goto v_20369;
v_20368:
    goto v_20504;
v_20500:
    stack[0] = elt(env, 8); // lientrans
    goto v_20501;
v_20502:
    goto v_20514;
v_20508:
    v_20816 = elt(env, 7); // times
    goto v_20509;
v_20510:
    v_20815 = elt(env, 1); // lie_a
    goto v_20511;
v_20512:
    v_20814 = elt(env, 8); // lientrans
    goto v_20513;
v_20514:
    goto v_20508;
v_20509:
    goto v_20510;
v_20511:
    goto v_20512;
v_20513:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 12); // aeval
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    goto v_20503;
v_20504:
    goto v_20500;
v_20501:
    goto v_20502;
v_20503:
    fn = elt(env, 13); // setk
    v_20814 = (*qfn2(fn))(fn, stack[0], v_20814);
    env = stack[-16];
    goto v_20530;
v_20524:
    v_20816 = elt(env, 4); // plus
    goto v_20525;
v_20526:
    v_20815 = stack[-13];
    goto v_20527;
v_20528:
    v_20814 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_20529;
v_20530:
    goto v_20524;
v_20525:
    goto v_20526;
v_20527:
    goto v_20528;
v_20529:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    stack[-13] = v_20814;
v_20521:
    goto v_20546;
v_20540:
    stack[0] = elt(env, 3); // difference
    goto v_20541;
v_20542:
    goto v_20556;
v_20550:
    v_20816 = elt(env, 3); // difference
    goto v_20551;
v_20552:
    v_20815 = stack[-14];
    goto v_20553;
v_20554:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20555;
v_20556:
    goto v_20550;
v_20551:
    goto v_20552;
v_20553:
    goto v_20554;
v_20555:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20815 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    goto v_20543;
v_20544:
    v_20814 = stack[-13];
    goto v_20545;
v_20546:
    goto v_20540;
v_20541:
    goto v_20542;
v_20543:
    goto v_20544;
v_20545:
    v_20814 = list3(stack[0], v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    if (v_20814 == nil) goto v_20537;
    goto v_20520;
v_20537:
    goto v_20574;
v_20568:
    v_20816 = elt(env, 4); // plus
    goto v_20569;
v_20570:
    v_20815 = stack[-13];
    goto v_20571;
v_20572:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20573;
v_20574:
    goto v_20568;
v_20569:
    goto v_20570;
v_20571:
    goto v_20572;
v_20573:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    stack[-11] = v_20814;
v_20565:
    goto v_20590;
v_20584:
    stack[0] = elt(env, 3); // difference
    goto v_20585;
v_20586:
    v_20814 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_20815 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    goto v_20587;
v_20588:
    v_20814 = stack[-11];
    goto v_20589;
v_20590:
    goto v_20584;
v_20585:
    goto v_20586;
v_20587:
    goto v_20588;
v_20589:
    v_20814 = list3(stack[0], v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    if (v_20814 == nil) goto v_20581;
    goto v_20564;
v_20581:
    goto v_20601;
v_20597:
    goto v_20609;
v_20603:
    v_20816 = elt(env, 5); // lie_lamb
    goto v_20604;
v_20605:
    v_20815 = stack[-13];
    goto v_20606;
v_20607:
    v_20814 = stack[-11];
    goto v_20608;
v_20609:
    goto v_20603;
v_20604:
    goto v_20605;
v_20606:
    goto v_20607;
v_20608:
    stack[-10] = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    goto v_20598;
v_20599:
    goto v_20621;
v_20615:
    stack[-9] = elt(env, 6); // quotient
    goto v_20616;
v_20617:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_20814;
    v_20814 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_20814;
v_20627:
    goto v_20642;
v_20636:
    stack[0] = elt(env, 3); // difference
    goto v_20637;
v_20638:
    v_20814 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_20815 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    goto v_20639;
v_20640:
    v_20814 = stack[-8];
    goto v_20641;
v_20642:
    goto v_20636;
v_20637:
    goto v_20638;
v_20639:
    goto v_20640;
v_20641:
    v_20814 = list3(stack[0], v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    if (v_20814 == nil) goto v_20633;
    v_20814 = stack[-7];
    stack[0] = v_20814;
    goto v_20626;
v_20633:
    goto v_20656;
v_20650:
    stack[-6] = elt(env, 4); // plus
    goto v_20651;
v_20652:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_20814;
    v_20814 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_20814;
v_20662:
    goto v_20677;
v_20671:
    stack[0] = elt(env, 3); // difference
    goto v_20672;
v_20673:
    v_20814 = stack[-14];
    fn = elt(env, 14); // aeval!*
    v_20815 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    goto v_20674;
v_20675:
    v_20814 = stack[-5];
    goto v_20676;
v_20677:
    goto v_20671;
v_20672:
    goto v_20673;
v_20674:
    goto v_20675;
v_20676:
    v_20814 = list3(stack[0], v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 15); // aminusp!:
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    if (v_20814 == nil) goto v_20668;
    v_20814 = stack[-4];
    v_20815 = v_20814;
    goto v_20661;
v_20668:
    goto v_20691;
v_20685:
    stack[-3] = elt(env, 4); // plus
    goto v_20686;
v_20687:
    goto v_20703;
v_20695:
    stack[-2] = elt(env, 7); // times
    goto v_20696;
v_20697:
    goto v_20712;
v_20706:
    v_20816 = elt(env, 8); // lientrans
    goto v_20707;
v_20708:
    v_20815 = stack[-13];
    goto v_20709;
v_20710:
    v_20814 = stack[-8];
    goto v_20711;
v_20712:
    goto v_20706;
v_20707:
    goto v_20708;
v_20709:
    goto v_20710;
v_20711:
    stack[-1] = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    goto v_20698;
v_20699:
    goto v_20723;
v_20717:
    v_20816 = elt(env, 8); // lientrans
    goto v_20718;
v_20719:
    v_20815 = stack[-11];
    goto v_20720;
v_20721:
    v_20814 = stack[-5];
    goto v_20722;
v_20723:
    goto v_20717;
v_20718:
    goto v_20719;
v_20720:
    goto v_20721;
v_20722:
    stack[0] = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    goto v_20700;
v_20701:
    goto v_20736;
v_20728:
    v_20817 = elt(env, 9); // lie_cc
    goto v_20729;
v_20730:
    v_20816 = stack[-8];
    goto v_20731;
v_20732:
    v_20815 = stack[-5];
    goto v_20733;
v_20734:
    v_20814 = stack[-12];
    goto v_20735;
v_20736:
    goto v_20728;
v_20729:
    goto v_20730;
v_20731:
    goto v_20732;
v_20733:
    goto v_20734;
v_20735:
    v_20814 = list4(v_20817, v_20816, v_20815, v_20814);
    env = stack[-16];
    goto v_20702;
v_20703:
    goto v_20695;
v_20696:
    goto v_20697;
v_20698:
    goto v_20699;
v_20700:
    goto v_20701;
v_20702:
    v_20814 = list4(stack[-2], stack[-1], stack[0], v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20815 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    goto v_20688;
v_20689:
    v_20814 = stack[-4];
    goto v_20690;
v_20691:
    goto v_20685;
v_20686:
    goto v_20687;
v_20688:
    goto v_20689;
v_20690:
    v_20814 = list3(stack[-3], v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    stack[-4] = v_20814;
    v_20814 = stack[-5];
    goto v_20752;
v_20746:
    v_20816 = elt(env, 4); // plus
    goto v_20747;
v_20748:
    v_20815 = v_20814;
    goto v_20749;
v_20750:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20751;
v_20752:
    goto v_20746;
v_20747:
    goto v_20748;
v_20749:
    goto v_20750;
v_20751:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    stack[-5] = v_20814;
    goto v_20662;
v_20661:
    goto v_20653;
v_20654:
    v_20814 = stack[-7];
    goto v_20655;
v_20656:
    goto v_20650;
v_20651:
    goto v_20652;
v_20653:
    goto v_20654;
v_20655:
    v_20814 = list3(stack[-6], v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    stack[-7] = v_20814;
    v_20814 = stack[-8];
    goto v_20767;
v_20761:
    v_20816 = elt(env, 4); // plus
    goto v_20762;
v_20763:
    v_20815 = v_20814;
    goto v_20764;
v_20765:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20766;
v_20767:
    goto v_20761;
v_20762:
    goto v_20763;
v_20764:
    goto v_20765;
v_20766:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    stack[-8] = v_20814;
    goto v_20627;
v_20626:
    goto v_20618;
v_20619:
    goto v_20778;
v_20772:
    v_20816 = elt(env, 8); // lientrans
    goto v_20773;
v_20774:
    v_20815 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20775;
v_20776:
    v_20814 = stack[-12];
    goto v_20777;
v_20778:
    goto v_20772;
v_20773:
    goto v_20774;
v_20775:
    goto v_20776;
v_20777:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    goto v_20620;
v_20621:
    goto v_20615;
v_20616:
    goto v_20617;
v_20618:
    goto v_20619;
v_20620:
    v_20814 = list3(stack[-9], stack[0], v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    goto v_20600;
v_20601:
    goto v_20597;
v_20598:
    goto v_20599;
v_20600:
    fn = elt(env, 13); // setk
    v_20814 = (*qfn2(fn))(fn, stack[-10], v_20814);
    env = stack[-16];
    v_20814 = stack[-11];
    goto v_20792;
v_20786:
    v_20816 = elt(env, 4); // plus
    goto v_20787;
v_20788:
    v_20815 = v_20814;
    goto v_20789;
v_20790:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20791;
v_20792:
    goto v_20786;
v_20787:
    goto v_20788;
v_20789:
    goto v_20790;
v_20791:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    stack[-11] = v_20814;
    goto v_20565;
v_20564:
    v_20814 = stack[-13];
    goto v_20806;
v_20800:
    v_20816 = elt(env, 4); // plus
    goto v_20801;
v_20802:
    v_20815 = v_20814;
    goto v_20803;
v_20804:
    v_20814 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20805;
v_20806:
    goto v_20800;
v_20801:
    goto v_20802;
v_20803:
    goto v_20804;
v_20805:
    v_20814 = list3(v_20816, v_20815, v_20814);
    env = stack[-16];
    fn = elt(env, 14); // aeval!*
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    stack[-13] = v_20814;
    goto v_20521;
v_20520:
    v_20814 = elt(env, 1); // lie_a
    v_20814 = ncons(v_20814);
    env = stack[-16];
    fn = elt(env, 16); // clear
    v_20814 = (*qfn1(fn))(fn, v_20814);
    env = stack[-16];
    fn = elt(env, 12); // aeval
    v_20814 = (*qfn1(fn))(fn, v_20814);
    v_20814 = nil;
    return onevalue(v_20814);
}



// Code for listsub

static LispObject CC_listsub(LispObject env,
                         LispObject v_20045, LispObject v_20046)
{
    env = qenv(env);
    LispObject v_20104, v_20105;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20045,v_20046);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_20104 = v_20046;
    stack[-3] = v_20045;
// end of prologue
    v_20104 = qcdr(v_20104);
    stack[-4] = v_20104;
    v_20104 = stack[-4];
    if (v_20104 == nil) goto v_20059;
    else goto v_20060;
v_20059:
    v_20104 = nil;
    goto v_20053;
v_20060:
    v_20104 = stack[-4];
    v_20104 = qcar(v_20104);
    goto v_20072;
v_20068:
    v_20105 = stack[-3];
    goto v_20069;
v_20070:
    goto v_20071;
v_20072:
    goto v_20068;
v_20069:
    goto v_20070;
v_20071:
    fn = elt(env, 1); // subeval1
    v_20104 = (*qfn2(fn))(fn, v_20105, v_20104);
    env = stack[-5];
    v_20104 = ncons(v_20104);
    env = stack[-5];
    stack[-1] = v_20104;
    stack[-2] = v_20104;
v_20054:
    v_20104 = stack[-4];
    v_20104 = qcdr(v_20104);
    stack[-4] = v_20104;
    v_20104 = stack[-4];
    if (v_20104 == nil) goto v_20079;
    else goto v_20080;
v_20079:
    v_20104 = stack[-2];
    goto v_20053;
v_20080:
    goto v_20088;
v_20084:
    stack[0] = stack[-1];
    goto v_20085;
v_20086:
    v_20104 = stack[-4];
    v_20104 = qcar(v_20104);
    goto v_20099;
v_20095:
    v_20105 = stack[-3];
    goto v_20096;
v_20097:
    goto v_20098;
v_20099:
    goto v_20095;
v_20096:
    goto v_20097;
v_20098:
    fn = elt(env, 1); // subeval1
    v_20104 = (*qfn2(fn))(fn, v_20105, v_20104);
    env = stack[-5];
    v_20104 = ncons(v_20104);
    env = stack[-5];
    goto v_20087;
v_20088:
    goto v_20084;
v_20085:
    goto v_20086;
v_20087:
    v_20104 = Lrplacd(nil, stack[0], v_20104);
    env = stack[-5];
    v_20104 = stack[-1];
    v_20104 = qcdr(v_20104);
    stack[-1] = v_20104;
    goto v_20054;
v_20053:
    {
        fn = elt(env, 2); // makelist
        return (*qfn1(fn))(fn, v_20104);
    }
}



// Code for mo!=zero

static LispObject CC_moMzero(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20073, v_20074, v_20075;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20074 = v_20045;
// end of prologue
v_20044:
    v_20073 = v_20074;
    if (v_20073 == nil) goto v_20049;
    else goto v_20050;
v_20049:
    v_20073 = lisp_true;
    goto v_20048;
v_20050:
    goto v_20063;
v_20059:
    v_20073 = v_20074;
    v_20075 = qcar(v_20073);
    goto v_20060;
v_20061:
    v_20073 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20062;
v_20063:
    goto v_20059;
v_20060:
    goto v_20061;
v_20062:
    if (v_20075 == v_20073) goto v_20057;
    else goto v_20058;
v_20057:
    v_20073 = v_20074;
    v_20073 = qcdr(v_20073);
    v_20074 = v_20073;
    goto v_20044;
v_20058:
    v_20073 = nil;
    goto v_20056;
    v_20073 = nil;
v_20056:
    goto v_20048;
    v_20073 = nil;
v_20048:
    return onevalue(v_20073);
}



// Code for lalr_get_lex_codes

static LispObject CC_lalr_get_lex_codes(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20091, v_20092;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_20091 = v_20045;
// end of prologue
    stack[-1] = nil;
    stack[0] = v_20091;
v_20055:
    v_20091 = stack[0];
    if (v_20091 == nil) goto v_20059;
    else goto v_20060;
v_20059:
    goto v_20054;
v_20060:
    v_20091 = stack[0];
    v_20091 = qcar(v_20091);
    v_20092 = v_20091;
    v_20091 = v_20092;
    v_20091 = Lstringp(nil, v_20091);
    env = stack[-2];
    if (v_20091 == nil) goto v_20069;
    goto v_20077;
v_20073:
    goto v_20074;
v_20075:
    v_20091 = stack[-1];
    goto v_20076;
v_20077:
    goto v_20073;
v_20074:
    goto v_20075;
v_20076:
    v_20091 = cons(v_20092, v_20091);
    env = stack[-2];
    stack[-1] = v_20091;
    goto v_20067;
v_20069:
v_20067:
    v_20091 = stack[0];
    v_20091 = qcdr(v_20091);
    stack[0] = v_20091;
    goto v_20055;
v_20054:
    fn = elt(env, 2); // lex_save_context
    v_20091 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[0] = v_20091;
    fn = elt(env, 3); // lex_cleanup
    v_20091 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_20091 = stack[-1];
    fn = elt(env, 4); // lex_keywords
    v_20091 = (*qfn1(fn))(fn, v_20091);
    env = stack[-2];
    fn = elt(env, 2); // lex_save_context
    v_20091 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_20091; // lex_context
    fn = elt(env, 5); // lex_export_codes
    v_20091 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_20091;
    v_20091 = stack[0];
    fn = elt(env, 6); // lex_restore_context
    v_20091 = (*qfn1(fn))(fn, v_20091);
    v_20091 = stack[-1];
    return onevalue(v_20091);
}



// Code for polynomcompare

static LispObject CC_polynomcompare(LispObject env,
                         LispObject v_20045, LispObject v_20046)
{
    env = qenv(env);
    LispObject v_20132, v_20133, v_20134;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20045,v_20046);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_20133 = v_20046;
    v_20132 = v_20045;
// end of prologue
    stack[-1] = v_20132;
    v_20132 = v_20133;
    stack[0] = v_20132;
v_20058:
    v_20132 = stack[-1];
    v_20132 = qcar(v_20132);
    if (v_20132 == nil) goto v_20061;
    v_20132 = stack[0];
    v_20132 = qcar(v_20132);
    if (v_20132 == nil) goto v_20061;
    goto v_20062;
v_20061:
    goto v_20057;
v_20062:
    goto v_20075;
v_20071:
    v_20132 = stack[-1];
    v_20133 = qcar(v_20132);
    goto v_20072;
v_20073:
    v_20132 = stack[0];
    v_20132 = qcar(v_20132);
    goto v_20074;
v_20075:
    goto v_20071;
v_20072:
    goto v_20073;
v_20074:
    fn = elt(env, 1); // monomcompare
    v_20132 = (*qfn2(fn))(fn, v_20133, v_20132);
    env = stack[-2];
    v_20134 = v_20132;
    goto v_20088;
v_20084:
    v_20133 = v_20134;
    goto v_20085;
v_20086:
    v_20132 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20087;
v_20088:
    goto v_20084;
v_20085:
    goto v_20086;
v_20087:
    if (v_20133 == v_20132) goto v_20082;
    else goto v_20083;
v_20082:
    v_20132 = nil;
    v_20132 = ncons(v_20132);
    env = stack[-2];
    stack[0] = v_20132;
    goto v_20081;
v_20083:
    goto v_20100;
v_20096:
    v_20133 = v_20134;
    goto v_20097;
v_20098:
    v_20132 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_20099;
v_20100:
    goto v_20096;
v_20097:
    goto v_20098;
v_20099:
    if (v_20133 == v_20132) goto v_20094;
    else goto v_20095;
v_20094:
    v_20132 = nil;
    v_20132 = ncons(v_20132);
    env = stack[-2];
    stack[-1] = v_20132;
    goto v_20081;
v_20095:
    v_20132 = stack[-1];
    v_20132 = qcdr(v_20132);
    stack[-1] = v_20132;
    v_20132 = stack[0];
    v_20132 = qcdr(v_20132);
    stack[0] = v_20132;
    goto v_20081;
v_20081:
    goto v_20058;
v_20057:
    v_20132 = stack[-1];
    v_20132 = qcar(v_20132);
    if (v_20132 == nil) goto v_20117;
    v_20132 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20052;
v_20117:
    v_20132 = stack[0];
    v_20132 = qcar(v_20132);
    if (v_20132 == nil) goto v_20123;
    v_20132 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_20052;
v_20123:
    v_20132 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20052;
    v_20132 = nil;
v_20052:
    return onevalue(v_20132);
}



// Code for maxfrom1

static LispObject CC_maxfrom1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20079, v_20080;
    LispObject fn;
    LispObject v_20047, v_20046, v_20045;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "maxfrom1");
    va_start(aa, nargs);
    v_20045 = va_arg(aa, LispObject);
    v_20046 = va_arg(aa, LispObject);
    v_20047 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20047,v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20045,v_20046,v_20047);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20047;
    stack[-1] = v_20046;
    stack[-2] = v_20045;
// end of prologue
v_20051:
    v_20079 = stack[-2];
    if (v_20079 == nil) goto v_20054;
    else goto v_20055;
v_20054:
    v_20079 = stack[0];
    goto v_20050;
v_20055:
    goto v_20065;
v_20061:
    goto v_20071;
v_20067:
    v_20079 = stack[-2];
    v_20079 = qcar(v_20079);
    v_20080 = qcar(v_20079);
    goto v_20068;
v_20069:
    v_20079 = stack[-1];
    goto v_20070;
v_20071:
    goto v_20067;
v_20068:
    goto v_20069;
v_20070:
    fn = elt(env, 1); // nth
    v_20080 = (*qfn2(fn))(fn, v_20080, v_20079);
    env = stack[-3];
    goto v_20062;
v_20063:
    v_20079 = stack[0];
    goto v_20064;
v_20065:
    goto v_20061;
v_20062:
    goto v_20063;
v_20064:
    fn = elt(env, 2); // max
    v_20079 = (*qfn2(fn))(fn, v_20080, v_20079);
    env = stack[-3];
    stack[0] = v_20079;
    v_20079 = stack[-2];
    v_20079 = qcdr(v_20079);
    stack[-2] = v_20079;
    goto v_20051;
    v_20079 = nil;
v_20050:
    return onevalue(v_20079);
}



// Code for get!-denom!-l

static LispObject CC_getKdenomKl(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20097, v_20098, v_20099;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_20098 = v_20045;
// end of prologue
    v_20097 = v_20098;
    v_20097 = qcar(v_20097);
    if (!consp(v_20097)) goto v_20049;
    else goto v_20050;
v_20049:
    v_20097 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20048;
v_20050:
    v_20097 = v_20098;
    v_20097 = qcar(v_20097);
    v_20097 = qcdr(v_20097);
    v_20097 = qcdr(v_20097);
    goto v_20048;
    v_20097 = nil;
v_20048:
    v_20098 = qcdr(v_20098);
    stack[0] = v_20098;
v_20064:
    v_20098 = stack[0];
    if (v_20098 == nil) goto v_20069;
    else goto v_20070;
v_20069:
    goto v_20063;
v_20070:
    v_20098 = stack[0];
    v_20098 = qcar(v_20098);
    v_20099 = v_20098;
    goto v_20081;
v_20077:
    v_20098 = v_20097;
    goto v_20078;
v_20079:
    v_20097 = v_20099;
    if (!consp(v_20097)) goto v_20085;
    else goto v_20086;
v_20085:
    v_20097 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20084;
v_20086:
    v_20097 = v_20099;
    v_20097 = qcdr(v_20097);
    v_20097 = qcdr(v_20097);
    goto v_20084;
    v_20097 = nil;
v_20084:
    goto v_20080;
v_20081:
    goto v_20077;
v_20078:
    goto v_20079;
v_20080:
    fn = elt(env, 1); // lcmn
    v_20097 = (*qfn2(fn))(fn, v_20098, v_20097);
    env = stack[-1];
    v_20098 = stack[0];
    v_20098 = qcdr(v_20098);
    stack[0] = v_20098;
    goto v_20064;
v_20063:
    return onevalue(v_20097);
}



// Code for mk!+real!+inner!+product

static LispObject CC_mkLrealLinnerLproduct(LispObject env,
                         LispObject v_20045, LispObject v_20046)
{
    env = qenv(env);
    LispObject v_20131, v_20132;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20045,v_20046);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_20046;
    stack[-3] = v_20045;
// end of prologue
    goto v_20060;
v_20056:
    v_20131 = stack[-3];
    fn = elt(env, 3); // get!+vec!+dim
    stack[0] = (*qfn1(fn))(fn, v_20131);
    env = stack[-5];
    goto v_20057;
v_20058:
    v_20131 = stack[-2];
    fn = elt(env, 3); // get!+vec!+dim
    v_20131 = (*qfn1(fn))(fn, v_20131);
    env = stack[-5];
    goto v_20059;
v_20060:
    goto v_20056;
v_20057:
    goto v_20058;
v_20059:
    if (equal(stack[0], v_20131)) goto v_20055;
    v_20131 = elt(env, 1); // "wrong dimensions in innerproduct"
    fn = elt(env, 4); // rederr
    v_20131 = (*qfn1(fn))(fn, v_20131);
    env = stack[-5];
    goto v_20053;
v_20055:
v_20053:
    goto v_20072;
v_20068:
    v_20132 = nil;
    goto v_20069;
v_20070:
    v_20131 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20071;
v_20072:
    goto v_20068;
v_20069:
    goto v_20070;
v_20071:
    v_20131 = cons(v_20132, v_20131);
    env = stack[-5];
    stack[0] = v_20131;
    v_20131 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_20131;
v_20078:
    goto v_20090;
v_20086:
    v_20131 = stack[-3];
    fn = elt(env, 3); // get!+vec!+dim
    v_20132 = (*qfn1(fn))(fn, v_20131);
    env = stack[-5];
    goto v_20087;
v_20088:
    v_20131 = stack[-4];
    goto v_20089;
v_20090:
    goto v_20086;
v_20087:
    goto v_20088;
v_20089:
    v_20131 = difference2(v_20132, v_20131);
    env = stack[-5];
    v_20131 = Lminusp(nil, v_20131);
    env = stack[-5];
    if (v_20131 == nil) goto v_20083;
    goto v_20077;
v_20083:
    goto v_20100;
v_20096:
    stack[-1] = stack[0];
    goto v_20097;
v_20098:
    goto v_20107;
v_20103:
    goto v_20113;
v_20109:
    v_20132 = stack[-3];
    goto v_20110;
v_20111:
    v_20131 = stack[-4];
    goto v_20112;
v_20113:
    goto v_20109;
v_20110:
    goto v_20111;
v_20112:
    fn = elt(env, 5); // get!+vec!+entry
    stack[0] = (*qfn2(fn))(fn, v_20132, v_20131);
    env = stack[-5];
    goto v_20104;
v_20105:
    goto v_20121;
v_20117:
    v_20132 = stack[-2];
    goto v_20118;
v_20119:
    v_20131 = stack[-4];
    goto v_20120;
v_20121:
    goto v_20117;
v_20118:
    goto v_20119;
v_20120:
    fn = elt(env, 5); // get!+vec!+entry
    v_20131 = (*qfn2(fn))(fn, v_20132, v_20131);
    env = stack[-5];
    goto v_20106;
v_20107:
    goto v_20103;
v_20104:
    goto v_20105;
v_20106:
    fn = elt(env, 6); // multsq
    v_20131 = (*qfn2(fn))(fn, stack[0], v_20131);
    env = stack[-5];
    goto v_20099;
v_20100:
    goto v_20096;
v_20097:
    goto v_20098;
v_20099:
    fn = elt(env, 7); // addsq
    v_20131 = (*qfn2(fn))(fn, stack[-1], v_20131);
    env = stack[-5];
    stack[0] = v_20131;
    v_20131 = stack[-4];
    v_20131 = add1(v_20131);
    env = stack[-5];
    stack[-4] = v_20131;
    goto v_20078;
v_20077:
    v_20131 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=5 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 2, -1);
    qvalue(elt(env, 2)) = v_20131; // !*sub2
    v_20131 = stack[0];
    fn = elt(env, 8); // subs2
    v_20131 = (*qfn1(fn))(fn, v_20131);
    stack[0] = v_20131;
    ;}  // end of a binding scope
    v_20131 = stack[0];
    return onevalue(v_20131);
}



// Code for cl_bvarl1

static LispObject CC_cl_bvarl1(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20050;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
// copy arguments values to proper place
    v_20050 = v_20045;
// end of prologue
    fn = elt(env, 1); // cl_varl1
    v_20050 = (*qfn1(fn))(fn, v_20050);
    v_20050 = qcdr(v_20050);
    return onevalue(v_20050);
}



// Code for iv_cutcongs1

static LispObject CC_iv_cutcongs1(LispObject env,
                         LispObject v_20045, LispObject v_20046)
{
    env = qenv(env);
    LispObject v_20077, v_20078;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20045,v_20046);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_20046;
    stack[-1] = v_20045;
// end of prologue
v_20050:
    v_20077 = stack[0];
    if (v_20077 == nil) goto v_20054;
    goto v_20065;
v_20061:
    v_20078 = stack[-1];
    goto v_20062;
v_20063:
    v_20077 = stack[0];
    v_20077 = qcar(v_20077);
    goto v_20064;
v_20065:
    goto v_20061;
v_20062:
    goto v_20063;
v_20064:
    fn = elt(env, 1); // iv_cutcongs2
    v_20077 = (*qfn2(fn))(fn, v_20078, v_20077);
    env = stack[-2];
    if (v_20077 == nil) goto v_20059;
    v_20077 = stack[0];
    v_20077 = qcdr(v_20077);
    stack[0] = v_20077;
    goto v_20050;
v_20059:
    v_20077 = nil;
    goto v_20049;
    goto v_20052;
v_20054:
    v_20077 = lisp_true;
    goto v_20049;
v_20052:
    v_20077 = nil;
v_20049:
    return onevalue(v_20077);
}



// Code for ofsf_sippsignchkf

static LispObject CC_ofsf_sippsignchkf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20226, v_20227, v_20228, v_20229, v_20230, v_20231, v_20232;
    LispObject fn;
    LispObject v_20051, v_20050, v_20049, v_20048, v_20047, v_20046, v_20045;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 7, "ofsf_sippsignchkf");
    va_start(aa, nargs);
    v_20045 = va_arg(aa, LispObject);
    v_20046 = va_arg(aa, LispObject);
    v_20047 = va_arg(aa, LispObject);
    v_20048 = va_arg(aa, LispObject);
    v_20049 = va_arg(aa, LispObject);
    v_20050 = va_arg(aa, LispObject);
    v_20051 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_20051,v_20050,v_20049,v_20048,v_20047,v_20046);
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_20045,v_20046,v_20047,v_20048,v_20049,v_20050);
        pop(v_20051);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-1] = v_20051;
    stack[-2] = v_20050;
    stack[-3] = v_20049;
    stack[-4] = v_20048;
    stack[-5] = v_20047;
    stack[-6] = v_20046;
    stack[-7] = v_20045;
// end of prologue
    v_20226 = stack[-7];
    if (!consp(v_20226)) goto v_20065;
    else goto v_20066;
v_20065:
    v_20226 = lisp_true;
    goto v_20064;
v_20066:
    v_20226 = stack[-7];
    v_20226 = qcar(v_20226);
    v_20226 = (consp(v_20226) ? nil : lisp_true);
    goto v_20064;
    v_20226 = nil;
v_20064:
    if (v_20226 == nil) goto v_20062;
    v_20226 = stack[-7];
    {
        fn = elt(env, 2); // ofsf_updsigndom
        return (*qfn1(fn))(fn, v_20226);
    }
v_20062:
    goto v_20091;
v_20077:
    v_20226 = stack[-7];
    v_20226 = qcar(v_20226);
    v_20226 = qcar(v_20226);
    v_20232 = qcar(v_20226);
    goto v_20078;
v_20079:
    v_20231 = stack[-6];
    goto v_20080;
v_20081:
    v_20230 = stack[-5];
    goto v_20082;
v_20083:
    v_20229 = stack[-4];
    goto v_20084;
v_20085:
    v_20228 = stack[-3];
    goto v_20086;
v_20087:
    v_20227 = stack[-2];
    goto v_20088;
v_20089:
    v_20226 = stack[-1];
    goto v_20090;
v_20091:
    goto v_20077;
v_20078:
    goto v_20079;
v_20080:
    goto v_20081;
v_20082:
    goto v_20083;
v_20084:
    goto v_20085;
v_20086:
    goto v_20087;
v_20088:
    goto v_20089;
v_20090:
    fn = elt(env, 3); // ofsf_updsignvar
    v_20226 = (*qfnn(fn))(fn, 7, v_20232, v_20231, v_20230, v_20229, v_20228, v_20227, v_20226);
    env = stack[-9];
    stack[0] = v_20226;
    goto v_20110;
v_20106:
    v_20227 = stack[0];
    goto v_20107;
v_20108:
    v_20226 = elt(env, 1); // unknown
    goto v_20109;
v_20110:
    goto v_20106;
v_20107:
    goto v_20108;
v_20109:
    if (v_20227 == v_20226) goto v_20104;
    else goto v_20105;
v_20104:
    v_20226 = elt(env, 1); // unknown
    goto v_20058;
v_20105:
    goto v_20129;
v_20115:
    v_20226 = stack[-7];
    v_20226 = qcar(v_20226);
    v_20232 = qcdr(v_20226);
    goto v_20116;
v_20117:
    v_20231 = stack[-6];
    goto v_20118;
v_20119:
    v_20230 = stack[-5];
    goto v_20120;
v_20121:
    v_20229 = stack[-4];
    goto v_20122;
v_20123:
    v_20228 = stack[-3];
    goto v_20124;
v_20125:
    v_20227 = stack[-2];
    goto v_20126;
v_20127:
    v_20226 = stack[-1];
    goto v_20128;
v_20129:
    goto v_20115;
v_20116:
    goto v_20117;
v_20118:
    goto v_20119;
v_20120:
    goto v_20121;
v_20122:
    goto v_20123;
v_20124:
    goto v_20125;
v_20126:
    goto v_20127;
v_20128:
    v_20226 = CC_ofsf_sippsignchkf(elt(env, 0), 7, v_20232, v_20231, v_20230, v_20229, v_20228, v_20227, v_20226);
    env = stack[-9];
    stack[-8] = v_20226;
    goto v_20147;
v_20143:
    v_20227 = stack[-8];
    goto v_20144;
v_20145:
    v_20226 = elt(env, 1); // unknown
    goto v_20146;
v_20147:
    goto v_20143;
v_20144:
    goto v_20145;
v_20146:
    if (v_20227 == v_20226) goto v_20141;
    else goto v_20142;
v_20141:
    v_20226 = elt(env, 1); // unknown
    goto v_20058;
v_20142:
    goto v_20166;
v_20152:
    v_20226 = stack[-7];
    v_20232 = qcdr(v_20226);
    goto v_20153;
v_20154:
    v_20231 = stack[-6];
    goto v_20155;
v_20156:
    v_20230 = stack[-5];
    goto v_20157;
v_20158:
    v_20229 = stack[-4];
    goto v_20159;
v_20160:
    v_20228 = stack[-3];
    goto v_20161;
v_20162:
    v_20227 = stack[-2];
    goto v_20163;
v_20164:
    v_20226 = stack[-1];
    goto v_20165;
v_20166:
    goto v_20152;
v_20153:
    goto v_20154;
v_20155:
    goto v_20156;
v_20157:
    goto v_20158;
v_20159:
    goto v_20160;
v_20161:
    goto v_20162;
v_20163:
    goto v_20164;
v_20165:
    v_20226 = CC_ofsf_sippsignchkf(elt(env, 0), 7, v_20232, v_20231, v_20230, v_20229, v_20228, v_20227, v_20226);
    env = stack[-9];
    stack[-1] = v_20226;
    goto v_20183;
v_20179:
    v_20227 = stack[-1];
    goto v_20180;
v_20181:
    v_20226 = elt(env, 1); // unknown
    goto v_20182;
v_20183:
    goto v_20179;
v_20180:
    goto v_20181;
v_20182:
    if (v_20227 == v_20226) goto v_20177;
    else goto v_20178;
v_20177:
    v_20226 = elt(env, 1); // unknown
    goto v_20058;
v_20178:
    goto v_20192;
v_20188:
    v_20227 = stack[0];
    goto v_20189;
v_20190:
    v_20226 = stack[-7];
    v_20226 = qcar(v_20226);
    v_20226 = qcar(v_20226);
    v_20226 = qcdr(v_20226);
    goto v_20191;
v_20192:
    goto v_20188;
v_20189:
    goto v_20190;
v_20191:
    fn = elt(env, 4); // ofsf_updsignpow
    v_20226 = (*qfn2(fn))(fn, v_20227, v_20226);
    env = stack[-9];
    stack[0] = v_20226;
    goto v_20203;
v_20199:
    v_20227 = stack[-8];
    goto v_20200;
v_20201:
    v_20226 = stack[0];
    goto v_20202;
v_20203:
    goto v_20199;
v_20200:
    goto v_20201;
v_20202:
    fn = elt(env, 5); // ofsf_updsignmult
    v_20226 = (*qfn2(fn))(fn, v_20227, v_20226);
    env = stack[-9];
    v_20228 = v_20226;
    goto v_20214;
v_20210:
    v_20227 = v_20228;
    goto v_20211;
v_20212:
    v_20226 = elt(env, 1); // unknown
    goto v_20213;
v_20214:
    goto v_20210;
v_20211:
    goto v_20212;
v_20213:
    if (v_20227 == v_20226) goto v_20208;
    else goto v_20209;
v_20208:
    v_20226 = elt(env, 1); // unknown
    goto v_20058;
v_20209:
    goto v_20223;
v_20219:
    v_20227 = v_20228;
    goto v_20220;
v_20221:
    v_20226 = stack[-1];
    goto v_20222;
v_20223:
    goto v_20219;
v_20220:
    goto v_20221;
v_20222:
    {
        fn = elt(env, 6); // ofsf_updsignadd
        return (*qfn2(fn))(fn, v_20227, v_20226);
    }
v_20058:
    return onevalue(v_20226);
}



// Code for dip_moncomp

static LispObject CC_dip_moncomp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20060, v_20061, v_20062;
    LispObject v_20047, v_20046, v_20045;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dip_moncomp");
    va_start(aa, nargs);
    v_20045 = va_arg(aa, LispObject);
    v_20046 = va_arg(aa, LispObject);
    v_20047 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20060 = v_20047;
    v_20061 = v_20046;
    v_20062 = v_20045;
// end of prologue
    goto v_20056;
v_20050:
    goto v_20051;
v_20052:
    goto v_20053;
v_20054:
    goto v_20055;
v_20056:
    goto v_20050;
v_20051:
    goto v_20052;
v_20053:
    goto v_20054;
v_20055:
    return list2star(v_20061, v_20062, v_20060);
}



// Code for getargsrd

static LispObject CC_getargsrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20070, v_20071;
    LispObject fn;
    argcheck(nargs, 0, "getargsrd");
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
    goto v_20057;
v_20053:
    v_20071 = qvalue(elt(env, 1)); // char
    goto v_20054;
v_20055:
    v_20070 = elt(env, 2); // (b v a r)
    goto v_20056;
v_20057:
    goto v_20053;
v_20054:
    goto v_20055;
v_20056:
    if (equal(v_20071, v_20070)) goto v_20051;
    else goto v_20052;
v_20051:
    fn = elt(env, 3); // bvarrd
    v_20070 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_20070;
    fn = elt(env, 4); // lex
    v_20070 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_20067;
v_20063:
    goto v_20064;
v_20065:
    v_20070 = CC_getargsrd(elt(env, 0), 0);
    goto v_20066;
v_20067:
    goto v_20063;
v_20064:
    goto v_20065;
v_20066:
    {
        LispObject v_20073 = stack[0];
        return cons(v_20073, v_20070);
    }
v_20052:
    v_20070 = nil;
    return onevalue(v_20070);
}



// Code for sc_mkmatrix

static LispObject CC_sc_mkmatrix(LispObject env,
                         LispObject v_20045, LispObject v_20046)
{
    env = qenv(env);
    LispObject v_20127, v_20128, v_20129;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20045,v_20046);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_20046;
    stack[-6] = v_20045;
// end of prologue
    v_20127 = stack[-6];
    v_20127 = sub1(v_20127);
    env = stack[-8];
    v_20127 = Lmkvect(nil, v_20127);
    env = stack[-8];
    stack[-7] = v_20127;
    v_20127 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_20127;
v_20058:
    goto v_20070;
v_20066:
    v_20127 = stack[-6];
    v_20128 = sub1(v_20127);
    env = stack[-8];
    goto v_20067;
v_20068:
    v_20127 = stack[-3];
    goto v_20069;
v_20070:
    goto v_20066;
v_20067:
    goto v_20068;
v_20069:
    v_20127 = difference2(v_20128, v_20127);
    env = stack[-8];
    v_20127 = Lminusp(nil, v_20127);
    env = stack[-8];
    if (v_20127 == nil) goto v_20063;
    goto v_20057;
v_20063:
    v_20127 = stack[-5];
    v_20127 = sub1(v_20127);
    env = stack[-8];
    v_20127 = Lmkvect(nil, v_20127);
    env = stack[-8];
    stack[-4] = v_20127;
    v_20127 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_20127;
v_20081:
    goto v_20093;
v_20089:
    v_20127 = stack[-5];
    v_20128 = sub1(v_20127);
    env = stack[-8];
    goto v_20090;
v_20091:
    v_20127 = stack[-2];
    goto v_20092;
v_20093:
    goto v_20089;
v_20090:
    goto v_20091;
v_20092:
    v_20127 = difference2(v_20128, v_20127);
    env = stack[-8];
    v_20127 = Lminusp(nil, v_20127);
    env = stack[-8];
    if (v_20127 == nil) goto v_20086;
    goto v_20080;
v_20086:
    goto v_20105;
v_20099:
    stack[-1] = stack[-4];
    goto v_20100;
v_20101:
    stack[0] = stack[-2];
    goto v_20102;
v_20103:
    v_20127 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 1); // sc_simp
    v_20127 = (*qfn1(fn))(fn, v_20127);
    env = stack[-8];
    goto v_20104;
v_20105:
    goto v_20099;
v_20100:
    goto v_20101;
v_20102:
    goto v_20103;
v_20104:
    fn = elt(env, 2); // sc_iputv
    v_20127 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_20127);
    env = stack[-8];
    v_20127 = stack[-2];
    v_20127 = add1(v_20127);
    env = stack[-8];
    stack[-2] = v_20127;
    goto v_20081;
v_20080:
    goto v_20119;
v_20113:
    v_20129 = stack[-7];
    goto v_20114;
v_20115:
    v_20128 = stack[-3];
    goto v_20116;
v_20117:
    v_20127 = stack[-4];
    goto v_20118;
v_20119:
    goto v_20113;
v_20114:
    goto v_20115;
v_20116:
    goto v_20117;
v_20118:
    fn = elt(env, 2); // sc_iputv
    v_20127 = (*qfnn(fn))(fn, 3, v_20129, v_20128, v_20127);
    env = stack[-8];
    v_20127 = stack[-3];
    v_20127 = add1(v_20127);
    env = stack[-8];
    stack[-3] = v_20127;
    goto v_20058;
v_20057:
    v_20127 = stack[-7];
    return onevalue(v_20127);
}



// Code for evalb

static LispObject CC_evalb(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20067, v_20068, v_20069;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20067 = v_20045;
// end of prologue
    goto v_20059;
v_20053:
    v_20069 = v_20067;
    goto v_20054;
v_20055:
    v_20068 = nil;
    goto v_20056;
v_20057:
    v_20067 = elt(env, 1); // algebraic
    goto v_20058;
v_20059:
    goto v_20053;
v_20054:
    goto v_20055;
v_20056:
    goto v_20057;
v_20058:
    fn = elt(env, 4); // formbool
    v_20067 = (*qfnn(fn))(fn, 3, v_20069, v_20068, v_20067);
    env = stack[0];
    fn = elt(env, 5); // eval
    v_20067 = (*qfn1(fn))(fn, v_20067);
    env = stack[0];
    if (v_20067 == nil) goto v_20050;
    v_20067 = elt(env, 2); // true
    goto v_20048;
v_20050:
    v_20067 = elt(env, 3); // false
    goto v_20048;
    v_20067 = nil;
v_20048:
    return onevalue(v_20067);
}



// Code for min0

static LispObject CC_min0(LispObject env,
                         LispObject v_20045, LispObject v_20046)
{
    env = qenv(env);
    LispObject v_20063, v_20064;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20045,v_20046);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20063 = v_20046;
    v_20064 = v_20045;
// end of prologue
    goto v_20053;
v_20049:
    goto v_20059;
v_20055:
    goto v_20056;
v_20057:
    goto v_20058;
v_20059:
    goto v_20055;
v_20056:
    goto v_20057;
v_20058:
    fn = elt(env, 1); // min
    v_20064 = (*qfn2(fn))(fn, v_20064, v_20063);
    env = stack[0];
    goto v_20050;
v_20051:
    v_20063 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20052;
v_20053:
    goto v_20049;
v_20050:
    goto v_20051;
v_20052:
    {
        fn = elt(env, 2); // max
        return (*qfn2(fn))(fn, v_20064, v_20063);
    }
}



// Code for physoptimes

static LispObject CC_physoptimes(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20302, v_20303;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[0] = v_20045;
// end of prologue
    stack[-2] = nil;
    goto v_20069;
v_20065:
    v_20303 = qvalue(elt(env, 1)); // tstack!*
    goto v_20066;
v_20067:
    v_20302 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20068;
v_20069:
    goto v_20065;
v_20066:
    goto v_20067;
v_20068:
    if (v_20303 == v_20302) goto v_20063;
    else goto v_20064;
v_20063:
    v_20302 = qvalue(elt(env, 2)); // mul!*
    goto v_20062;
v_20064:
    v_20302 = nil;
    goto v_20062;
    v_20302 = nil;
v_20062:
    if (v_20302 == nil) goto v_20060;
    v_20302 = qvalue(elt(env, 2)); // mul!*
    stack[-2] = v_20302;
    v_20302 = nil;
    qvalue(elt(env, 2)) = v_20302; // mul!*
    goto v_20058;
v_20060:
v_20058:
    v_20302 = qvalue(elt(env, 1)); // tstack!*
    v_20302 = add1(v_20302);
    env = stack[-7];
    qvalue(elt(env, 1)) = v_20302; // tstack!*
    v_20302 = stack[0];
    v_20302 = qcar(v_20302);
    fn = elt(env, 4); // physopsim!*
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    stack[-6] = v_20302;
    v_20302 = stack[0];
    v_20302 = qcdr(v_20302);
    stack[-1] = v_20302;
v_20087:
    v_20302 = stack[-1];
    if (v_20302 == nil) goto v_20092;
    else goto v_20093;
v_20092:
    goto v_20086;
v_20093:
    v_20302 = stack[-1];
    v_20302 = qcar(v_20302);
    fn = elt(env, 4); // physopsim!*
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    stack[-5] = v_20302;
    v_20302 = stack[-6];
    fn = elt(env, 5); // getphystype
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    stack[-4] = v_20302;
    v_20302 = stack[-5];
    fn = elt(env, 5); // getphystype
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    stack[-3] = v_20302;
    v_20302 = stack[-4];
    if (v_20302 == nil) goto v_20107;
    else goto v_20108;
v_20107:
    v_20302 = stack[-3];
    if (v_20302 == nil) goto v_20112;
    else goto v_20113;
v_20112:
    goto v_20121;
v_20117:
    v_20302 = stack[-6];
    fn = elt(env, 6); // physop2sq
    stack[0] = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    goto v_20118;
v_20119:
    v_20302 = stack[-5];
    fn = elt(env, 6); // physop2sq
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    goto v_20120;
v_20121:
    goto v_20117;
v_20118:
    goto v_20119;
v_20120:
    fn = elt(env, 7); // multsq
    v_20302 = (*qfn2(fn))(fn, stack[0], v_20302);
    env = stack[-7];
    fn = elt(env, 8); // mk!*sq
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    stack[-6] = v_20302;
    goto v_20111;
v_20113:
    v_20302 = stack[-6];
    v_20302 = (LispObject)zerop(v_20302);
    v_20302 = v_20302 ? lisp_true : nil;
    env = stack[-7];
    if (v_20302 == nil) goto v_20127;
    goto v_20136;
v_20132:
    v_20303 = nil;
    goto v_20133;
v_20134:
    v_20302 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20135;
v_20136:
    goto v_20132;
v_20133:
    goto v_20134;
v_20135:
    v_20302 = cons(v_20303, v_20302);
    env = stack[-7];
    fn = elt(env, 8); // mk!*sq
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    stack[-6] = v_20302;
    goto v_20111;
v_20127:
    v_20302 = stack[-6];
    v_20302 = Lonep(nil, v_20302);
    env = stack[-7];
    if (v_20302 == nil) goto v_20140;
    v_20302 = stack[-5];
    fn = elt(env, 6); // physop2sq
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    fn = elt(env, 8); // mk!*sq
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    stack[-6] = v_20302;
    goto v_20111;
v_20140:
    goto v_20154;
v_20150:
    v_20302 = stack[-6];
    fn = elt(env, 6); // physop2sq
    stack[0] = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    goto v_20151;
v_20152:
    v_20302 = stack[-5];
    fn = elt(env, 6); // physop2sq
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    goto v_20153;
v_20154:
    goto v_20150;
v_20151:
    goto v_20152;
v_20153:
    fn = elt(env, 7); // multsq
    v_20302 = (*qfn2(fn))(fn, stack[0], v_20302);
    env = stack[-7];
    fn = elt(env, 8); // mk!*sq
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    stack[-6] = v_20302;
    goto v_20111;
v_20111:
    goto v_20106;
v_20108:
    v_20302 = stack[-3];
    if (v_20302 == nil) goto v_20159;
    else goto v_20160;
v_20159:
    v_20302 = stack[-5];
    v_20302 = (LispObject)zerop(v_20302);
    v_20302 = v_20302 ? lisp_true : nil;
    env = stack[-7];
    if (v_20302 == nil) goto v_20165;
    goto v_20174;
v_20170:
    v_20303 = nil;
    goto v_20171;
v_20172:
    v_20302 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20173;
v_20174:
    goto v_20170;
v_20171:
    goto v_20172;
v_20173:
    v_20302 = cons(v_20303, v_20302);
    env = stack[-7];
    fn = elt(env, 8); // mk!*sq
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    goto v_20163;
v_20165:
    v_20302 = stack[-5];
    v_20302 = Lonep(nil, v_20302);
    env = stack[-7];
    if (v_20302 == nil) goto v_20178;
    v_20302 = stack[-6];
    fn = elt(env, 6); // physop2sq
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    fn = elt(env, 8); // mk!*sq
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    goto v_20163;
v_20178:
    goto v_20192;
v_20188:
    v_20302 = stack[-5];
    fn = elt(env, 6); // physop2sq
    stack[0] = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    goto v_20189;
v_20190:
    v_20302 = stack[-6];
    fn = elt(env, 6); // physop2sq
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    goto v_20191;
v_20192:
    goto v_20188;
v_20189:
    goto v_20190;
v_20191:
    fn = elt(env, 7); // multsq
    v_20302 = (*qfn2(fn))(fn, stack[0], v_20302);
    env = stack[-7];
    fn = elt(env, 8); // mk!*sq
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    goto v_20163;
    v_20302 = nil;
v_20163:
    stack[-6] = v_20302;
    goto v_20106;
v_20160:
    goto v_20205;
v_20201:
    v_20302 = stack[-6];
    fn = elt(env, 9); // physopaeval
    stack[0] = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    goto v_20202;
v_20203:
    v_20302 = stack[-5];
    fn = elt(env, 9); // physopaeval
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    goto v_20204;
v_20205:
    goto v_20201;
v_20202:
    goto v_20203;
v_20204:
    fn = elt(env, 10); // physopordchk
    v_20302 = (*qfn2(fn))(fn, stack[0], v_20302);
    env = stack[-7];
    if (v_20302 == nil) goto v_20198;
    goto v_20219;
v_20215:
    v_20303 = stack[-4];
    goto v_20216;
v_20217:
    v_20302 = stack[-3];
    goto v_20218;
v_20219:
    goto v_20215;
v_20216:
    goto v_20217;
v_20218:
    if (equal(v_20303, v_20302)) goto v_20213;
    else goto v_20214;
v_20213:
    goto v_20226;
v_20222:
    v_20303 = stack[-4];
    goto v_20223;
v_20224:
    v_20302 = elt(env, 3); // scalar
    goto v_20225;
v_20226:
    goto v_20222;
v_20223:
    goto v_20224;
v_20225:
    v_20302 = (v_20303 == v_20302 ? lisp_true : nil);
    goto v_20212;
v_20214:
    v_20302 = nil;
    goto v_20212;
    v_20302 = nil;
v_20212:
    if (v_20302 == nil) goto v_20198;
    goto v_20239;
v_20235:
    v_20302 = stack[-6];
    fn = elt(env, 6); // physop2sq
    stack[0] = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    goto v_20236;
v_20237:
    v_20302 = stack[-5];
    fn = elt(env, 6); // physop2sq
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    goto v_20238;
v_20239:
    goto v_20235;
v_20236:
    goto v_20237;
v_20238:
    fn = elt(env, 7); // multsq
    v_20302 = (*qfn2(fn))(fn, stack[0], v_20302);
    env = stack[-7];
    fn = elt(env, 8); // mk!*sq
    v_20302 = (*qfn1(fn))(fn, v_20302);
    env = stack[-7];
    stack[-6] = v_20302;
    goto v_20106;
v_20198:
    goto v_20251;
v_20247:
    v_20303 = stack[-6];
    goto v_20248;
v_20249:
    v_20302 = stack[-5];
    goto v_20250;
v_20251:
    goto v_20247;
v_20248:
    goto v_20249;
v_20250:
    fn = elt(env, 11); // multopop!*
    v_20302 = (*qfn2(fn))(fn, v_20303, v_20302);
    env = stack[-7];
    stack[-6] = v_20302;
    goto v_20106;
v_20106:
    v_20302 = stack[-1];
    v_20302 = qcdr(v_20302);
    stack[-1] = v_20302;
    goto v_20087;
v_20086:
v_20055:
    v_20302 = qvalue(elt(env, 2)); // mul!*
    if (v_20302 == nil) goto v_20262;
    else goto v_20263;
v_20262:
    v_20302 = lisp_true;
    goto v_20261;
v_20263:
    goto v_20273;
v_20269:
    v_20303 = qvalue(elt(env, 1)); // tstack!*
    goto v_20270;
v_20271:
    v_20302 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20272;
v_20273:
    goto v_20269;
v_20270:
    goto v_20271;
v_20272:
    v_20302 = (LispObject)greaterp2(v_20303, v_20302);
    v_20302 = v_20302 ? lisp_true : nil;
    env = stack[-7];
    goto v_20261;
    v_20302 = nil;
v_20261:
    if (v_20302 == nil) goto v_20259;
    goto v_20056;
v_20259:
    goto v_20281;
v_20277:
    v_20302 = qvalue(elt(env, 2)); // mul!*
    v_20303 = qcar(v_20302);
    goto v_20278;
v_20279:
    v_20302 = stack[-6];
    goto v_20280;
v_20281:
    goto v_20277;
v_20278:
    goto v_20279;
v_20280:
    v_20302 = Lapply1(nil, v_20303, v_20302);
    env = stack[-7];
    stack[-6] = v_20302;
    v_20302 = qvalue(elt(env, 2)); // mul!*
    v_20302 = qcdr(v_20302);
    qvalue(elt(env, 2)) = v_20302; // mul!*
    goto v_20055;
v_20056:
    v_20302 = qvalue(elt(env, 1)); // tstack!*
    v_20302 = sub1(v_20302);
    env = stack[-7];
    qvalue(elt(env, 1)) = v_20302; // tstack!*
    goto v_20297;
v_20293:
    v_20303 = qvalue(elt(env, 1)); // tstack!*
    goto v_20294;
v_20295:
    v_20302 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20296;
v_20297:
    goto v_20293;
v_20294:
    goto v_20295;
v_20296:
    if (v_20303 == v_20302) goto v_20291;
    else goto v_20292;
v_20291:
    v_20302 = stack[-2];
    qvalue(elt(env, 2)) = v_20302; // mul!*
    goto v_20290;
v_20292:
v_20290:
    v_20302 = stack[-6];
    return onevalue(v_20302);
}



// Code for prop!-simp1

static LispObject CC_propKsimp1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20163, v_20164, v_20165;
    LispObject fn;
    LispObject v_20049, v_20048, v_20047, v_20046, v_20045;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "prop-simp1");
    va_start(aa, nargs);
    v_20045 = va_arg(aa, LispObject);
    v_20046 = va_arg(aa, LispObject);
    v_20047 = va_arg(aa, LispObject);
    v_20048 = va_arg(aa, LispObject);
    v_20049 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_20049,v_20048,v_20047,v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_20045,v_20046,v_20047,v_20048,v_20049);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_20049;
    stack[0] = v_20048;
    stack[-5] = v_20047;
    stack[-2] = v_20046;
    stack[-6] = v_20045;
// end of prologue
v_20044:
    v_20163 = stack[-2];
    if (v_20163 == nil) goto v_20053;
    else goto v_20054;
v_20053:
    goto v_20063;
v_20057:
    goto v_20069;
v_20065:
    v_20164 = stack[0];
    goto v_20066;
v_20067:
    v_20163 = stack[-4];
    goto v_20068;
v_20069:
    goto v_20065;
v_20066:
    goto v_20067;
v_20068:
    stack[0] = list2(v_20164, v_20163);
    env = stack[-8];
    goto v_20058;
v_20059:
    stack[-1] = stack[-6];
    goto v_20060;
v_20061:
    v_20163 = stack[-5];
    v_20163 = Lreverse(nil, v_20163);
    goto v_20062;
v_20063:
    goto v_20057;
v_20058:
    goto v_20059;
v_20060:
    goto v_20061;
v_20062:
    {
        LispObject v_20174 = stack[0];
        LispObject v_20175 = stack[-1];
        return list2star(v_20174, v_20175, v_20163);
    }
v_20054:
    goto v_20082;
v_20078:
    v_20164 = stack[-6];
    goto v_20079;
v_20080:
    v_20163 = stack[-2];
    v_20163 = qcar(v_20163);
    goto v_20081;
v_20082:
    goto v_20078;
v_20079:
    goto v_20080;
v_20081:
    fn = elt(env, 1); // prop!-simp2
    v_20163 = (*qfn2(fn))(fn, v_20164, v_20163);
    env = stack[-8];
    stack[-3] = v_20163;
    v_20163 = stack[-3];
    if (v_20163 == nil) goto v_20089;
    else goto v_20090;
v_20089:
    goto v_20103;
v_20093:
    stack[-3] = stack[-6];
    goto v_20094;
v_20095:
    v_20163 = stack[-2];
    stack[-1] = qcdr(v_20163);
    goto v_20096;
v_20097:
    goto v_20112;
v_20108:
    v_20163 = stack[-2];
    v_20164 = qcar(v_20163);
    goto v_20109;
v_20110:
    v_20163 = stack[-5];
    goto v_20111;
v_20112:
    goto v_20108;
v_20109:
    goto v_20110;
v_20111:
    v_20165 = cons(v_20164, v_20163);
    env = stack[-8];
    goto v_20098;
v_20099:
    v_20164 = stack[0];
    goto v_20100;
v_20101:
    v_20163 = stack[-4];
    goto v_20102;
v_20103:
    goto v_20093;
v_20094:
    goto v_20095;
v_20096:
    goto v_20097;
v_20098:
    goto v_20099;
v_20100:
    goto v_20101;
v_20102:
    stack[-6] = stack[-3];
    stack[-2] = stack[-1];
    stack[-5] = v_20165;
    stack[0] = v_20164;
    stack[-4] = v_20163;
    goto v_20044;
v_20090:
    goto v_20131;
v_20121:
    v_20163 = stack[-3];
    stack[-6] = qcdr(v_20163);
    goto v_20122;
v_20123:
    v_20163 = stack[-2];
    stack[-2] = qcdr(v_20163);
    goto v_20124;
v_20125:
    stack[-1] = stack[-5];
    goto v_20126;
v_20127:
    v_20163 = stack[0];
    stack[0] = add1(v_20163);
    env = stack[-8];
    goto v_20128;
v_20129:
    goto v_20144;
v_20140:
    v_20163 = stack[-3];
    stack[-7] = qcar(v_20163);
    goto v_20141;
v_20142:
    goto v_20152;
v_20148:
    goto v_20149;
v_20150:
    goto v_20159;
v_20155:
    stack[-3] = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_20156;
v_20157:
    v_20163 = stack[-5];
    v_20163 = Llength(nil, v_20163);
    env = stack[-8];
    goto v_20158;
v_20159:
    goto v_20155;
v_20156:
    goto v_20157;
v_20158:
    v_20163 = Lexpt(nil, stack[-3], v_20163);
    env = stack[-8];
    goto v_20151;
v_20152:
    goto v_20148;
v_20149:
    goto v_20150;
v_20151:
    v_20163 = times2(stack[-4], v_20163);
    env = stack[-8];
    goto v_20143;
v_20144:
    goto v_20140;
v_20141:
    goto v_20142;
v_20143:
    v_20163 = times2(stack[-7], v_20163);
    env = stack[-8];
    goto v_20130;
v_20131:
    goto v_20121;
v_20122:
    goto v_20123;
v_20124:
    goto v_20125;
v_20126:
    goto v_20127;
v_20128:
    goto v_20129;
v_20130:
    stack[-5] = stack[-1];
    stack[-4] = v_20163;
    goto v_20044;
    v_20163 = nil;
    goto v_20052;
    v_20163 = nil;
v_20052:
    return onevalue(v_20163);
}



// Code for no!-side!-effectp

static LispObject CC_noKsideKeffectp(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20101, v_20102;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_20045;
// end of prologue
    v_20101 = stack[0];
    if (!consp(v_20101)) goto v_20049;
    else goto v_20050;
v_20049:
    v_20101 = stack[0];
    v_20101 = (is_number(v_20101) ? lisp_true : nil);
    if (v_20101 == nil) goto v_20054;
    else goto v_20053;
v_20054:
    v_20101 = stack[0];
    if (symbolp(v_20101)) goto v_20060;
    v_20101 = nil;
    goto v_20058;
v_20060:
    v_20101 = stack[0];
    v_20101 = Lsymbol_specialp(nil, v_20101);
    env = stack[-1];
    if (v_20101 == nil) goto v_20067;
    else goto v_20066;
v_20067:
    v_20101 = stack[0];
    v_20101 = Lsymbol_globalp(nil, v_20101);
v_20066:
    v_20101 = (v_20101 == nil ? lisp_true : nil);
    goto v_20058;
    v_20101 = nil;
v_20058:
v_20053:
    goto v_20048;
v_20050:
    goto v_20079;
v_20075:
    v_20101 = stack[0];
    v_20102 = qcar(v_20101);
    goto v_20076;
v_20077:
    v_20101 = elt(env, 1); // quote
    goto v_20078;
v_20079:
    goto v_20075;
v_20076:
    goto v_20077;
v_20078:
    if (v_20102 == v_20101) goto v_20073;
    else goto v_20074;
v_20073:
    v_20101 = lisp_true;
    goto v_20048;
v_20074:
    goto v_20091;
v_20087:
    v_20101 = stack[0];
    v_20102 = qcar(v_20101);
    goto v_20088;
v_20089:
    v_20101 = elt(env, 2); // nosideeffects
    goto v_20090;
v_20091:
    goto v_20087;
v_20088:
    goto v_20089;
v_20090:
    v_20101 = Lflagp(nil, v_20102, v_20101);
    env = stack[-1];
    if (v_20101 == nil) goto v_20085;
    v_20101 = stack[0];
    v_20101 = qcdr(v_20101);
    {
        fn = elt(env, 3); // no!-side!-effect!-listp
        return (*qfn1(fn))(fn, v_20101);
    }
v_20085:
    v_20101 = nil;
    goto v_20048;
    v_20101 = nil;
v_20048:
    return onevalue(v_20101);
}



// Code for remchkf1

static LispObject CC_remchkf1(LispObject env,
                         LispObject v_20045, LispObject v_20046)
{
    env = qenv(env);
    LispObject v_20094, v_20095, v_20096;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20045,v_20046);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20046;
    stack[-1] = v_20045;
// end of prologue
    v_20094 = stack[-1];
    fn = elt(env, 3); // termsf
    v_20094 = (*qfn1(fn))(fn, v_20094);
    env = stack[-3];
    stack[-2] = v_20094;
    goto v_20061;
v_20055:
    v_20096 = stack[-1];
    goto v_20056;
v_20057:
    v_20095 = stack[0];
    goto v_20058;
v_20059:
    v_20094 = stack[-2];
    goto v_20060;
v_20061:
    goto v_20055;
v_20056:
    goto v_20057;
v_20058:
    goto v_20059;
v_20060:
    fn = elt(env, 4); // xremf
    v_20094 = (*qfnn(fn))(fn, 3, v_20096, v_20095, v_20094);
    env = stack[-3];
    stack[0] = v_20094;
    v_20094 = stack[0];
    if (v_20094 == nil) goto v_20071;
    else goto v_20072;
v_20071:
    v_20094 = lisp_true;
    goto v_20070;
v_20072:
    goto v_20082;
v_20078:
    v_20094 = stack[0];
    v_20094 = qcar(v_20094);
    stack[0] = v_20094;
    fn = elt(env, 3); // termsf
    v_20095 = (*qfn1(fn))(fn, v_20094);
    env = stack[-3];
    goto v_20079;
v_20080:
    v_20094 = stack[-2];
    goto v_20081;
v_20082:
    goto v_20078;
v_20079:
    goto v_20080;
v_20081:
    v_20094 = (LispObject)geq2(v_20095, v_20094);
    v_20094 = v_20094 ? lisp_true : nil;
    env = stack[-3];
    goto v_20070;
    v_20094 = nil;
v_20070:
    if (v_20094 == nil) goto v_20068;
    v_20094 = stack[-1];
    goto v_20050;
v_20068:
    v_20094 = qvalue(elt(env, 1)); // !*trcompact
    if (v_20094 == nil) goto v_20089;
    v_20094 = elt(env, 2); // "*** Remainder smaller"
    fn = elt(env, 5); // prin2t
    v_20094 = (*qfn1(fn))(fn, v_20094);
    goto v_20066;
v_20089:
v_20066:
    v_20094 = stack[0];
v_20050:
    return onevalue(v_20094);
}



// Code for red_tailreddriver

static LispObject CC_red_tailreddriver(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20103;
    LispObject fn;
    LispObject v_20047, v_20046, v_20045;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "red_tailreddriver");
    va_start(aa, nargs);
    v_20045 = va_arg(aa, LispObject);
    v_20046 = va_arg(aa, LispObject);
    v_20047 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20047,v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20045,v_20046,v_20047);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_20047;
    stack[-2] = v_20046;
    stack[-3] = v_20045;
// end of prologue
    v_20103 = stack[-2];
    fn = elt(env, 1); // bas_dpoly
    v_20103 = (*qfn1(fn))(fn, v_20103);
    env = stack[-5];
    if (v_20103 == nil) goto v_20055;
    else goto v_20056;
v_20055:
    v_20103 = lisp_true;
    goto v_20054;
v_20056:
    v_20103 = stack[-2];
    fn = elt(env, 1); // bas_dpoly
    v_20103 = (*qfn1(fn))(fn, v_20103);
    env = stack[-5];
    v_20103 = qcdr(v_20103);
    if (v_20103 == nil) goto v_20064;
    else goto v_20065;
v_20064:
    v_20103 = lisp_true;
    goto v_20063;
v_20065:
    v_20103 = stack[-3];
    v_20103 = (v_20103 == nil ? lisp_true : nil);
    goto v_20063;
    v_20103 = nil;
v_20063:
    goto v_20054;
    v_20103 = nil;
v_20054:
    if (v_20103 == nil) goto v_20052;
    v_20103 = stack[-2];
    goto v_20050;
v_20052:
v_20081:
    v_20103 = stack[-2];
    fn = elt(env, 1); // bas_dpoly
    v_20103 = (*qfn1(fn))(fn, v_20103);
    env = stack[-5];
    if (v_20103 == nil) goto v_20084;
    else goto v_20085;
v_20084:
    goto v_20080;
v_20085:
    goto v_20096;
v_20090:
    stack[-4] = stack[-1];
    goto v_20091;
v_20092:
    stack[0] = stack[-3];
    goto v_20093;
v_20094:
    v_20103 = stack[-2];
    fn = elt(env, 2); // red!=hidelt
    v_20103 = (*qfn1(fn))(fn, v_20103);
    env = stack[-5];
    goto v_20095;
v_20096:
    goto v_20090;
v_20091:
    goto v_20092;
v_20093:
    goto v_20094;
v_20095:
    v_20103 = Lapply2(nil, 3, stack[-4], stack[0], v_20103);
    env = stack[-5];
    stack[-2] = v_20103;
    goto v_20081;
v_20080:
    v_20103 = stack[-2];
    {
        fn = elt(env, 3); // red!=recover
        return (*qfn1(fn))(fn, v_20103);
    }
    goto v_20050;
    v_20103 = nil;
v_20050:
    return onevalue(v_20103);
}



// Code for ra_qmk

static LispObject CC_ra_qmk(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20067, v_20068, v_20069;
    LispObject fn;
    LispObject v_20047, v_20046, v_20045;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ra_qmk");
    va_start(aa, nargs);
    v_20045 = va_arg(aa, LispObject);
    v_20046 = va_arg(aa, LispObject);
    v_20047 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20047,v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20045,v_20046,v_20047);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_20067 = v_20047;
    v_20068 = v_20046;
    v_20069 = v_20045;
// end of prologue
    goto v_20056;
v_20050:
    stack[-1] = elt(env, 1); // !:ra!:
    goto v_20051;
v_20052:
    stack[0] = v_20069;
    goto v_20053;
v_20054:
    goto v_20064;
v_20060:
    goto v_20061;
v_20062:
    goto v_20063;
v_20064:
    goto v_20060;
v_20061:
    goto v_20062;
v_20063:
    fn = elt(env, 2); // riv_mk
    v_20067 = (*qfn2(fn))(fn, v_20068, v_20067);
    goto v_20055;
v_20056:
    goto v_20050;
v_20051:
    goto v_20052;
v_20053:
    goto v_20054;
v_20055:
    {
        LispObject v_20072 = stack[-1];
        LispObject v_20073 = stack[0];
        return list3(v_20072, v_20073, v_20067);
    }
}



// Code for lalr_print_first_information

static LispObject CC_lalr_print_first_information(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20100, v_20101;
    LispObject fn;
    argcheck(nargs, 0, "lalr_print_first_information");
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
    v_20100 = elt(env, 1); // "=== FIRST sets for each nonterminal ==="
    v_20100 = Lprinc(nil, v_20100);
    env = stack[-2];
    v_20100 = Lterpri(nil, 0);
    env = stack[-2];
    v_20100 = qvalue(elt(env, 2)); // nonterminals
    stack[-1] = v_20100;
v_20052:
    v_20100 = stack[-1];
    if (v_20100 == nil) goto v_20056;
    else goto v_20057;
v_20056:
    goto v_20051;
v_20057:
    v_20100 = stack[-1];
    v_20100 = qcar(v_20100);
    stack[0] = v_20100;
    v_20100 = stack[0];
    fn = elt(env, 6); // lalr_prin_symbol
    v_20100 = (*qfn1(fn))(fn, v_20100);
    env = stack[-2];
    v_20100 = elt(env, 3); // ":"
    v_20100 = Lprinc(nil, v_20100);
    env = stack[-2];
    v_20100 = (LispObject)320+TAG_FIXNUM; // 20
    v_20100 = Lttab(nil, v_20100);
    env = stack[-2];
    goto v_20078;
v_20074:
    v_20101 = stack[0];
    goto v_20075;
v_20076:
    v_20100 = elt(env, 4); // lalr_first
    goto v_20077;
v_20078:
    goto v_20074;
v_20075:
    goto v_20076;
v_20077:
    v_20100 = get(v_20101, v_20100);
    env = stack[-2];
    stack[0] = v_20100;
v_20072:
    v_20100 = stack[0];
    if (v_20100 == nil) goto v_20083;
    else goto v_20084;
v_20083:
    goto v_20071;
v_20084:
    v_20100 = stack[0];
    v_20100 = qcar(v_20100);
    fn = elt(env, 6); // lalr_prin_symbol
    v_20100 = (*qfn1(fn))(fn, v_20100);
    env = stack[-2];
    v_20100 = elt(env, 5); // " "
    v_20100 = Lprinc(nil, v_20100);
    env = stack[-2];
    v_20100 = stack[0];
    v_20100 = qcdr(v_20100);
    stack[0] = v_20100;
    goto v_20072;
v_20071:
    v_20100 = Lterpri(nil, 0);
    env = stack[-2];
    v_20100 = stack[-1];
    v_20100 = qcdr(v_20100);
    stack[-1] = v_20100;
    goto v_20052;
v_20051:
        return Lterpri(nil, 0);
}



// Code for dvfsf_v

static LispObject CC_dvfsf_v(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20069, v_20070;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20069 = v_20045;
// end of prologue
    goto v_20052;
v_20048:
    v_20070 = v_20069;
    goto v_20049;
v_20050:
    v_20069 = qvalue(elt(env, 1)); // dvfsf_p!*
    goto v_20051;
v_20052:
    goto v_20048;
v_20049:
    goto v_20050;
v_20051:
    fn = elt(env, 2); // qremf
    v_20069 = (*qfn2(fn))(fn, v_20070, v_20069);
    env = stack[0];
    v_20070 = v_20069;
    v_20069 = v_20070;
    v_20069 = qcdr(v_20069);
    if (v_20069 == nil) goto v_20058;
    else goto v_20059;
v_20058:
    v_20069 = v_20070;
    v_20069 = qcar(v_20069);
    v_20069 = CC_dvfsf_v(elt(env, 0), v_20069);
    return add1(v_20069);
v_20059:
    v_20069 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20057;
    v_20069 = nil;
v_20057:
    return onevalue(v_20069);
}



// Code for rl_fvarl

static LispObject CC_rl_fvarl(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20056;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_20056 = v_20045;
// end of prologue
    goto v_20052;
v_20048:
    stack[0] = qvalue(elt(env, 1)); // rl_fvarl!*
    goto v_20049;
v_20050:
    v_20056 = ncons(v_20056);
    env = stack[-1];
    goto v_20051;
v_20052:
    goto v_20048;
v_20049:
    goto v_20050;
v_20051:
    {
        LispObject v_20058 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_20058, v_20056);
    }
}



// Code for pasf_smordtable1

static LispObject CC_pasf_smordtable1(LispObject env,
                         LispObject v_20045, LispObject v_20046)
{
    env = qenv(env);
    LispObject v_20068, v_20069, v_20070;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20068 = v_20046;
    v_20069 = v_20045;
// end of prologue
    v_20070 = elt(env, 1); // ((lessp (lessp 1) (leq 1) (equal false) (neq 1) (geq false) (greaterp false) (cong nil) (ncong nil)) (leq (lessp 1) (leq 1)
// (equal false) (neq 1) (geq false) (greaterp false) (cong nil) (ncong nil)) (equal (lessp 1) (leq 1) (equal false) (neq 1)
// (geq false) (greaterp false) (cong nil) (ncong nil)) (neq (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2)
// (cong nil) (ncong nil)) (geq (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong nil) (ncong nil)) (greaterp
// (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong nil) (ncong nil)))
    goto v_20056;
v_20052:
    goto v_20053;
v_20054:
    goto v_20062;
v_20058:
    goto v_20059;
v_20060:
    goto v_20061;
v_20062:
    goto v_20058;
v_20059:
    goto v_20060;
v_20061:
    v_20069 = Latsoc(nil, v_20069, v_20070);
    goto v_20055;
v_20056:
    goto v_20052;
v_20053:
    goto v_20054;
v_20055:
    v_20068 = Latsoc(nil, v_20068, v_20069);
    v_20068 = qcdr(v_20068);
    return onevalue(v_20068);
}



// Code for cgp_lbc

static LispObject CC_cgp_lbc(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20050;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20050 = v_20045;
// end of prologue
    fn = elt(env, 1); // cgp_rp
    v_20050 = (*qfn1(fn))(fn, v_20050);
    env = stack[0];
    {
        fn = elt(env, 2); // dip_lbc
        return (*qfn1(fn))(fn, v_20050);
    }
}



// Code for symbolsom

static LispObject CC_symbolsom(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20189, v_20190, v_20191;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_20045;
// end of prologue
    stack[-1] = nil;
    goto v_20058;
v_20054:
    v_20189 = stack[-4];
    v_20190 = qcar(v_20189);
    goto v_20055;
v_20056:
    v_20189 = qvalue(elt(env, 1)); // valid_om!*
    goto v_20057;
v_20058:
    goto v_20054;
v_20055:
    goto v_20056;
v_20057:
    v_20189 = Lassoc(nil, v_20190, v_20189);
    stack[-5] = v_20189;
    v_20189 = stack[-5];
    if (v_20189 == nil) goto v_20066;
    v_20189 = stack[-5];
    v_20189 = qcdr(v_20189);
    v_20189 = qcar(v_20189);
    stack[-5] = v_20189;
    goto v_20064;
v_20066:
v_20064:
    v_20189 = stack[-4];
    v_20189 = qcar(v_20189);
    stack[0] = v_20189;
    v_20189 = stack[-4];
    v_20189 = qcdr(v_20189);
    v_20189 = qcdr(v_20189);
    v_20189 = qcar(v_20189);
    stack[-3] = v_20189;
    v_20189 = stack[-4];
    v_20189 = Lreverse(nil, v_20189);
    env = stack[-6];
    v_20189 = qcar(v_20189);
    stack[-2] = v_20189;
    goto v_20088;
v_20084:
    v_20190 = stack[0];
    goto v_20085;
v_20086:
    v_20189 = elt(env, 2); // diff
    goto v_20087;
v_20088:
    goto v_20084;
v_20085:
    goto v_20086;
v_20087:
    if (v_20190 == v_20189) goto v_20083;
    v_20189 = stack[-4];
    v_20189 = qcdr(v_20189);
    v_20189 = qcdr(v_20189);
    v_20189 = qcdr(v_20189);
    v_20189 = qcar(v_20189);
    stack[-1] = v_20189;
    goto v_20081;
v_20083:
v_20081:
    v_20189 = stack[-1];
    if (v_20189 == nil) goto v_20099;
    goto v_20109;
v_20105:
    v_20189 = stack[-1];
    v_20190 = qcar(v_20189);
    goto v_20106;
v_20107:
    v_20189 = elt(env, 3); // condition
    goto v_20108;
v_20109:
    goto v_20105;
v_20106:
    goto v_20107;
v_20108:
    if (v_20190 == v_20189) goto v_20103;
    else goto v_20104;
v_20103:
    goto v_20118;
v_20114:
    v_20190 = elt(env, 4); // "<condition> tag not supported in MathML"
    goto v_20115;
v_20116:
    v_20189 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20117;
v_20118:
    goto v_20114;
v_20115:
    goto v_20116;
v_20117:
    fn = elt(env, 13); // errorml
    v_20189 = (*qfn2(fn))(fn, v_20190, v_20189);
    env = stack[-6];
    goto v_20102;
v_20104:
v_20102:
    goto v_20097;
v_20099:
v_20097:
    v_20189 = elt(env, 5); // "<OMA>"
    fn = elt(env, 14); // printout
    v_20189 = (*qfn1(fn))(fn, v_20189);
    env = stack[-6];
    v_20189 = lisp_true;
    fn = elt(env, 15); // indent!*
    v_20189 = (*qfn1(fn))(fn, v_20189);
    env = stack[-6];
    v_20189 = stack[-1];
    if (v_20189 == nil) goto v_20132;
    goto v_20138;
v_20134:
    v_20190 = stack[0];
    goto v_20135;
v_20136:
    v_20189 = elt(env, 6); // int
    goto v_20137;
v_20138:
    goto v_20134;
v_20135:
    goto v_20136;
v_20137:
    v_20189 = (v_20190 == v_20189 ? lisp_true : nil);
    goto v_20130;
v_20132:
    v_20189 = nil;
    goto v_20130;
    v_20189 = nil;
v_20130:
    if (v_20189 == nil) goto v_20128;
    v_20189 = elt(env, 7); // defint
    stack[0] = v_20189;
    goto v_20126;
v_20128:
v_20126:
    v_20189 = elt(env, 8); // "<OMS cd="""
    fn = elt(env, 14); // printout
    v_20189 = (*qfn1(fn))(fn, v_20189);
    env = stack[-6];
    v_20189 = stack[-5];
    v_20189 = Lprinc(nil, v_20189);
    env = stack[-6];
    v_20189 = elt(env, 9); // """ name="""
    v_20189 = Lprinc(nil, v_20189);
    env = stack[-6];
    v_20189 = stack[0];
    v_20189 = Lprinc(nil, v_20189);
    env = stack[-6];
    v_20189 = elt(env, 10); // """/>"
    v_20189 = Lprinc(nil, v_20189);
    env = stack[-6];
    v_20189 = stack[-1];
    if (v_20189 == nil) goto v_20159;
    v_20189 = stack[-1];
    fn = elt(env, 16); // objectom
    v_20189 = (*qfn1(fn))(fn, v_20189);
    env = stack[-6];
    goto v_20157;
v_20159:
v_20157:
    goto v_20171;
v_20165:
    stack[-1] = elt(env, 11); // lambda
    goto v_20166;
v_20167:
    stack[0] = nil;
    goto v_20168;
v_20169:
    goto v_20181;
v_20175:
    v_20191 = stack[-3];
    goto v_20176;
v_20177:
    v_20190 = stack[-2];
    goto v_20178;
v_20179:
    v_20189 = nil;
    goto v_20180;
v_20181:
    goto v_20175;
v_20176:
    goto v_20177;
v_20178:
    goto v_20179;
v_20180:
    v_20189 = list2star(v_20191, v_20190, v_20189);
    env = stack[-6];
    goto v_20170;
v_20171:
    goto v_20165;
v_20166:
    goto v_20167;
v_20168:
    goto v_20169;
v_20170:
    v_20189 = list2star(stack[-1], stack[0], v_20189);
    env = stack[-6];
    fn = elt(env, 17); // lambdaom
    v_20189 = (*qfn1(fn))(fn, v_20189);
    env = stack[-6];
    v_20189 = nil;
    fn = elt(env, 15); // indent!*
    v_20189 = (*qfn1(fn))(fn, v_20189);
    env = stack[-6];
    v_20189 = elt(env, 12); // "</OMA>"
    fn = elt(env, 14); // printout
    v_20189 = (*qfn1(fn))(fn, v_20189);
    v_20189 = nil;
    return onevalue(v_20189);
}



// Code for close_forall

static LispObject CC_close_forall(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20061, v_20062;
    LispObject fn;
    argcheck(nargs, 0, "close_forall");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
// end of prologue
    goto v_20056;
v_20052:
    v_20062 = qvalue(elt(env, 1)); // flagg
    goto v_20053;
v_20054:
    v_20061 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20055;
v_20056:
    goto v_20052;
v_20053:
    goto v_20054;
v_20055:
    if (v_20062 == v_20061) goto v_20050;
    else goto v_20051;
v_20050:
    v_20061 = elt(env, 2); // "</apply>"
    fn = elt(env, 3); // printout
    v_20061 = (*qfn1(fn))(fn, v_20061);
    goto v_20049;
v_20051:
v_20049:
    v_20061 = nil;
    return onevalue(v_20061);
}



// Code for sparpri

static LispObject CC_sparpri(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20116, v_20117, v_20118;
    LispObject fn;
    LispObject v_20047, v_20046, v_20045;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sparpri");
    va_start(aa, nargs);
    v_20045 = va_arg(aa, LispObject);
    v_20046 = va_arg(aa, LispObject);
    v_20047 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20047,v_20046,v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20045,v_20046,v_20047);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_20047;
    v_20116 = v_20046;
    v_20117 = v_20045;
// end of prologue
    stack[-5] = v_20116;
    v_20116 = v_20117;
    stack[-3] = v_20116;
v_20058:
    v_20116 = stack[-3];
    if (v_20116 == nil) goto v_20062;
    else goto v_20063;
v_20062:
    goto v_20057;
v_20063:
    v_20116 = stack[-3];
    v_20116 = qcar(v_20116);
    stack[-2] = v_20116;
    goto v_20074;
v_20070:
    goto v_20080;
v_20076:
    stack[-1] = elt(env, 1); // quote
    goto v_20077;
v_20078:
    goto v_20089;
v_20083:
    stack[0] = elt(env, 2); // setq
    goto v_20084;
v_20085:
    goto v_20098;
v_20092:
    v_20118 = stack[-4];
    goto v_20093;
v_20094:
    v_20117 = stack[-5];
    goto v_20095;
v_20096:
    v_20116 = stack[-2];
    v_20116 = qcar(v_20116);
    goto v_20097;
v_20098:
    goto v_20092;
v_20093:
    goto v_20094;
v_20095:
    goto v_20096;
v_20097:
    v_20117 = list3(v_20118, v_20117, v_20116);
    env = stack[-6];
    goto v_20086;
v_20087:
    v_20116 = stack[-2];
    v_20116 = qcdr(v_20116);
    goto v_20088;
v_20089:
    goto v_20083;
v_20084:
    goto v_20085;
v_20086:
    goto v_20087;
v_20088:
    v_20116 = list3(stack[0], v_20117, v_20116);
    env = stack[-6];
    goto v_20079;
v_20080:
    goto v_20076;
v_20077:
    goto v_20078;
v_20079:
    v_20117 = list2(stack[-1], v_20116);
    env = stack[-6];
    goto v_20071;
v_20072:
    v_20116 = elt(env, 3); // first
    goto v_20073;
v_20074:
    goto v_20070;
v_20071:
    goto v_20072;
v_20073:
    fn = elt(env, 6); // writepri
    v_20116 = (*qfn2(fn))(fn, v_20117, v_20116);
    env = stack[-6];
    goto v_20111;
v_20107:
    v_20117 = elt(env, 4); // (quote !$)
    goto v_20108;
v_20109:
    v_20116 = elt(env, 5); // last
    goto v_20110;
v_20111:
    goto v_20107;
v_20108:
    goto v_20109;
v_20110:
    fn = elt(env, 6); // writepri
    v_20116 = (*qfn2(fn))(fn, v_20117, v_20116);
    env = stack[-6];
    v_20116 = stack[-3];
    v_20116 = qcdr(v_20116);
    stack[-3] = v_20116;
    goto v_20058;
v_20057:
    v_20116 = nil;
    return onevalue(v_20116);
}



// Code for string2bytelist

static LispObject CC_string2bytelist(LispObject env,
                         LispObject v_20045)
{
    env = qenv(env);
    LispObject v_20100, v_20101;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20045);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20045);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_20100 = v_20045;
// end of prologue
    stack[-1] = nil;
    fn = elt(env, 1); // string2list
    v_20100 = (*qfn1(fn))(fn, v_20100);
    env = stack[-2];
    stack[0] = v_20100;
v_20055:
    v_20100 = stack[0];
    if (v_20100 == nil) goto v_20058;
    else goto v_20059;
v_20058:
    goto v_20054;
v_20059:
    v_20100 = stack[0];
    v_20100 = qcar(v_20100);
    v_20100 = Lminusp(nil, v_20100);
    env = stack[-2];
    if (v_20100 == nil) goto v_20065;
    goto v_20074;
v_20070:
    goto v_20080;
v_20076:
    v_20101 = (LispObject)4096+TAG_FIXNUM; // 256
    goto v_20077;
v_20078:
    v_20100 = stack[0];
    v_20100 = qcar(v_20100);
    goto v_20079;
v_20080:
    goto v_20076;
v_20077:
    goto v_20078;
v_20079:
    v_20101 = plus2(v_20101, v_20100);
    env = stack[-2];
    goto v_20071;
v_20072:
    v_20100 = stack[-1];
    goto v_20073;
v_20074:
    goto v_20070;
v_20071:
    goto v_20072;
v_20073:
    v_20100 = cons(v_20101, v_20100);
    env = stack[-2];
    stack[-1] = v_20100;
    goto v_20063;
v_20065:
    goto v_20092;
v_20088:
    v_20100 = stack[0];
    v_20101 = qcar(v_20100);
    goto v_20089;
v_20090:
    v_20100 = stack[-1];
    goto v_20091;
v_20092:
    goto v_20088;
v_20089:
    goto v_20090;
v_20091:
    v_20100 = cons(v_20101, v_20100);
    env = stack[-2];
    stack[-1] = v_20100;
    goto v_20063;
v_20063:
    v_20100 = stack[0];
    v_20100 = qcdr(v_20100);
    stack[0] = v_20100;
    goto v_20055;
v_20054:
    v_20100 = stack[-1];
        return Lnreverse(nil, v_20100);
    return onevalue(v_20100);
}



setup_type const u35_setup[] =
{
    {"domainvalchk",            TOO_FEW_2,      CC_domainvalchk,WRONG_NO_2},
    {"pasf_anegrel",            CC_pasf_anegrel,TOO_MANY_1,    WRONG_NO_1},
    {"aex_subrat1",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_aex_subrat1},
    {"fnrd",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_fnrd},
    {"sc_subtrsq",              TOO_FEW_2,      CC_sc_subtrsq, WRONG_NO_2},
    {"vdpilcomb1",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vdpilcomb1},
    {"calc_coeff",              TOO_FEW_2,      CC_calc_coeff, WRONG_NO_2},
    {"dp_neworder",             CC_dp_neworder, TOO_MANY_1,    WRONG_NO_1},
    {"dfprintfn",               CC_dfprintfn,   TOO_MANY_1,    WRONG_NO_1},
    {"clean_numid",             CC_clean_numid, TOO_MANY_1,    WRONG_NO_1},
    {"dummyp",                  CC_dummyp,      TOO_MANY_1,    WRONG_NO_1},
    {"difbf",                   TOO_FEW_2,      CC_difbf,      WRONG_NO_2},
    {"order_of_der_mind",       CC_order_of_der_mind,TOO_MANY_1,WRONG_NO_1},
    {"ext_mult",                TOO_FEW_2,      CC_ext_mult,   WRONG_NO_2},
    {"bc_mkat",                 TOO_FEW_2,      CC_bc_mkat,    WRONG_NO_2},
    {"ithlistelem",             TOO_FEW_2,      CC_ithlistelem,WRONG_NO_2},
    {"maxl",                    CC_maxl,        TOO_MANY_1,    WRONG_NO_1},
    {"make-unique-freevars",    CC_makeKuniqueKfreevars,TOO_MANY_1,WRONG_NO_1},
    {"noncomexpf",              CC_noncomexpf,  TOO_MANY_1,    WRONG_NO_1},
    {"getrlist",                CC_getrlist,    TOO_MANY_1,    WRONG_NO_1},
    {"chkint*",                 CC_chkintH,     TOO_MANY_1,    WRONG_NO_1},
    {"indordl2",                TOO_FEW_2,      CC_indordl2,   WRONG_NO_2},
    {"liennewstruc",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_liennewstruc},
    {"listsub",                 TOO_FEW_2,      CC_listsub,    WRONG_NO_2},
    {"mo=zero",                 CC_moMzero,     TOO_MANY_1,    WRONG_NO_1},
    {"lalr_get_lex_codes",      CC_lalr_get_lex_codes,TOO_MANY_1,WRONG_NO_1},
    {"polynomcompare",          TOO_FEW_2,      CC_polynomcompare,WRONG_NO_2},
    {"maxfrom1",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_maxfrom1},
    {"get-denom-l",             CC_getKdenomKl, TOO_MANY_1,    WRONG_NO_1},
    {"mk+real+inner+product",   TOO_FEW_2,      CC_mkLrealLinnerLproduct,WRONG_NO_2},
    {"cl_bvarl1",               CC_cl_bvarl1,   TOO_MANY_1,    WRONG_NO_1},
    {"iv_cutcongs1",            TOO_FEW_2,      CC_iv_cutcongs1,WRONG_NO_2},
    {"ofsf_sippsignchkf",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_sippsignchkf},
    {"dip_moncomp",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dip_moncomp},
    {"getargsrd",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_getargsrd},
    {"sc_mkmatrix",             TOO_FEW_2,      CC_sc_mkmatrix,WRONG_NO_2},
    {"evalb",                   CC_evalb,       TOO_MANY_1,    WRONG_NO_1},
    {"min0",                    TOO_FEW_2,      CC_min0,       WRONG_NO_2},
    {"physoptimes",             CC_physoptimes, TOO_MANY_1,    WRONG_NO_1},
    {"prop-simp1",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_propKsimp1},
    {"no-side-effectp",         CC_noKsideKeffectp,TOO_MANY_1, WRONG_NO_1},
    {"remchkf1",                TOO_FEW_2,      CC_remchkf1,   WRONG_NO_2},
    {"red_tailreddriver",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_red_tailreddriver},
    {"ra_qmk",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ra_qmk},
    {"lalr_print_first_information",WRONG_NO_NA,WRONG_NO_NB,   (n_args *)CC_lalr_print_first_information},
    {"dvfsf_v",                 CC_dvfsf_v,     TOO_MANY_1,    WRONG_NO_1},
    {"rl_fvarl",                CC_rl_fvarl,    TOO_MANY_1,    WRONG_NO_1},
    {"pasf_smordtable1",        TOO_FEW_2,      CC_pasf_smordtable1,WRONG_NO_2},
    {"cgp_lbc",                 CC_cgp_lbc,     TOO_MANY_1,    WRONG_NO_1},
    {"symbolsom",               CC_symbolsom,   TOO_MANY_1,    WRONG_NO_1},
    {"close_forall",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_close_forall},
    {"sparpri",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_sparpri},
    {"string2bytelist",         CC_string2bytelist,TOO_MANY_1, WRONG_NO_1},
    {NULL, (one_args *)"u35", (two_args *)"81423 151474 1093592", 0}
};

// end of generated code
