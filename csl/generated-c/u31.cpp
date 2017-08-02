
// $destdir/u31.c        Machine generated C code

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



// Code for ifstat

static LispObject CC_ifstat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16523, v_16524;
    LispObject fn;
    argcheck(nargs, 0, "ifstat");
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
    stack[-1] = nil;
v_16437:
    v_16523 = lisp_true;
    fn = elt(env, 7); // xread
    v_16523 = (*qfn1(fn))(fn, v_16523);
    env = stack[-2];
    stack[0] = v_16523;
    goto v_16449;
v_16445:
    v_16524 = qvalue(elt(env, 2)); // cursym!*
    goto v_16446;
v_16447:
    v_16523 = elt(env, 3); // then
    goto v_16448;
v_16449:
    goto v_16445;
v_16446:
    goto v_16447;
v_16448:
    if (v_16524 == v_16523) goto v_16444;
    goto v_16457;
v_16453:
    v_16524 = elt(env, 4); // if
    goto v_16454;
v_16455:
    v_16523 = lisp_true;
    goto v_16456;
v_16457:
    goto v_16453;
v_16454:
    goto v_16455;
v_16456:
    fn = elt(env, 8); // symerr
    v_16523 = (*qfn2(fn))(fn, v_16524, v_16523);
    env = stack[-2];
    goto v_16442;
v_16444:
v_16442:
    goto v_16465;
v_16461:
    goto v_16462;
v_16463:
    goto v_16472;
v_16468:
    goto v_16469;
v_16470:
    v_16523 = lisp_true;
    fn = elt(env, 7); // xread
    v_16523 = (*qfn1(fn))(fn, v_16523);
    env = stack[-2];
    goto v_16471;
v_16472:
    goto v_16468;
v_16469:
    goto v_16470;
v_16471:
    v_16523 = list2(stack[0], v_16523);
    env = stack[-2];
    goto v_16464;
v_16465:
    goto v_16461;
v_16462:
    goto v_16463;
v_16464:
    fn = elt(env, 9); // aconc!*
    v_16523 = (*qfn2(fn))(fn, stack[-1], v_16523);
    env = stack[-2];
    stack[-1] = v_16523;
    goto v_16484;
v_16480:
    v_16524 = qvalue(elt(env, 2)); // cursym!*
    goto v_16481;
v_16482:
    v_16523 = elt(env, 5); // else
    goto v_16483;
v_16484:
    goto v_16480;
v_16481:
    goto v_16482;
v_16483:
    if (v_16524 == v_16523) goto v_16479;
    goto v_16477;
v_16479:
    goto v_16494;
v_16490:
    fn = elt(env, 10); // scan
    v_16524 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_16491;
v_16492:
    v_16523 = elt(env, 4); // if
    goto v_16493;
v_16494:
    goto v_16490;
v_16491:
    goto v_16492;
v_16493:
    if (v_16524 == v_16523) goto v_16488;
    else goto v_16489;
v_16488:
    goto v_16437;
v_16489:
    goto v_16504;
v_16500:
    goto v_16501;
v_16502:
    goto v_16511;
v_16507:
    stack[0] = lisp_true;
    goto v_16508;
v_16509:
    v_16523 = lisp_true;
    fn = elt(env, 11); // xread1
    v_16523 = (*qfn1(fn))(fn, v_16523);
    env = stack[-2];
    goto v_16510;
v_16511:
    goto v_16507;
v_16508:
    goto v_16509;
v_16510:
    v_16523 = list2(stack[0], v_16523);
    env = stack[-2];
    goto v_16503;
v_16504:
    goto v_16500;
v_16501:
    goto v_16502;
v_16503:
    fn = elt(env, 9); // aconc!*
    v_16523 = (*qfn2(fn))(fn, stack[-1], v_16523);
    env = stack[-2];
    stack[-1] = v_16523;
    goto v_16477;
v_16477:
    goto v_16520;
v_16516:
    v_16524 = elt(env, 6); // cond
    goto v_16517;
v_16518:
    v_16523 = stack[-1];
    goto v_16519;
v_16520:
    goto v_16516;
v_16517:
    goto v_16518;
v_16519:
    return cons(v_16524, v_16523);
    return onevalue(v_16523);
}



// Code for cquotegex

static LispObject CC_cquotegex(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16440;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16440 = v_16432;
// end of prologue
    v_16440 = qvalue(elt(env, 1)); // !*guardian
    if (v_16440 == nil) goto v_16437;
    v_16440 = elt(env, 2); // gex
    goto v_16435;
v_16437:
    v_16440 = nil;
v_16435:
    return onevalue(v_16440);
}



// Code for cl_rename!-vars

static LispObject CC_cl_renameKvars(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16444;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_16444 = v_16432;
// end of prologue
    goto v_16439;
v_16435:
    stack[0] = v_16444;
    goto v_16436;
v_16437:
    fn = elt(env, 1); // cl_replace!-varl
    v_16444 = (*qfn1(fn))(fn, v_16444);
    env = stack[-1];
    goto v_16438;
v_16439:
    goto v_16435;
v_16436:
    goto v_16437;
v_16438:
    fn = elt(env, 2); // cl_rename!-vars1
    v_16444 = (*qfn2(fn))(fn, stack[0], v_16444);
    v_16444 = qcar(v_16444);
    return onevalue(v_16444);
}



// Code for qqe_arg!-check!-lb!-rb

static LispObject CC_qqe_argKcheckKlbKrb(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16478, v_16479;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_16432;
// end of prologue
    v_16478 = stack[0];
    v_16478 = qcdr(v_16478);
    v_16478 = qcar(v_16478);
    v_16479 = v_16478;
    v_16478 = stack[0];
    v_16478 = qcdr(v_16478);
    v_16478 = qcdr(v_16478);
    v_16478 = qcar(v_16478);
    stack[-1] = v_16478;
    v_16478 = v_16479;
    fn = elt(env, 3); // qqe_arg!-check!-b
    v_16478 = (*qfn1(fn))(fn, v_16478);
    env = stack[-2];
    if (v_16478 == nil) goto v_16448;
    else goto v_16449;
v_16448:
    fn = elt(env, 4); // qqe_arg!-check!-marked!-ids!-rollback
    v_16478 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_16458;
v_16454:
    v_16479 = stack[0];
    goto v_16455;
v_16456:
    v_16478 = elt(env, 2); // "type conflict: arguments don't fit
//             binary op with basic type args"
    goto v_16457;
v_16458:
    goto v_16454;
v_16455:
    goto v_16456;
v_16457:
    fn = elt(env, 5); // typerr
    v_16478 = (*qfn2(fn))(fn, v_16479, v_16478);
    env = stack[-2];
    goto v_16447;
v_16449:
v_16447:
    v_16478 = stack[-1];
    fn = elt(env, 3); // qqe_arg!-check!-b
    v_16478 = (*qfn1(fn))(fn, v_16478);
    env = stack[-2];
    if (v_16478 == nil) goto v_16464;
    else goto v_16465;
v_16464:
    fn = elt(env, 4); // qqe_arg!-check!-marked!-ids!-rollback
    v_16478 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_16474;
v_16470:
    v_16479 = stack[0];
    goto v_16471;
v_16472:
    v_16478 = elt(env, 2); // "type conflict: arguments don't fit
//             binary op with basic type args"
    goto v_16473;
v_16474:
    goto v_16470;
v_16471:
    goto v_16472;
v_16473:
    fn = elt(env, 5); // typerr
    v_16478 = (*qfn2(fn))(fn, v_16479, v_16478);
    goto v_16463;
v_16465:
v_16463:
    v_16478 = nil;
    return onevalue(v_16478);
}



// Code for pasf_simplat1

static LispObject CC_pasf_simplat1(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16696, v_16697, v_16698;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16432,v_16433);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_16696 = v_16433;
    v_16697 = v_16432;
// end of prologue
    v_16696 = v_16697;
    fn = elt(env, 6); // pasf_zcong
    v_16696 = (*qfn1(fn))(fn, v_16696);
    env = stack[0];
    fn = elt(env, 7); // pasf_mkpos
    v_16696 = (*qfn1(fn))(fn, v_16696);
    env = stack[0];
    fn = elt(env, 8); // pasf_dt
    v_16696 = (*qfn1(fn))(fn, v_16696);
    env = stack[0];
    fn = elt(env, 9); // pasf_vf
    v_16696 = (*qfn1(fn))(fn, v_16696);
    env = stack[0];
    v_16697 = v_16696;
    goto v_16455;
v_16451:
    v_16698 = v_16697;
    goto v_16452;
v_16453:
    v_16696 = elt(env, 1); // true
    goto v_16454;
v_16455:
    goto v_16451;
v_16452:
    goto v_16453;
v_16454:
    if (v_16698 == v_16696) goto v_16449;
    else goto v_16450;
v_16449:
    v_16696 = lisp_true;
    goto v_16448;
v_16450:
    goto v_16465;
v_16461:
    v_16698 = v_16697;
    goto v_16462;
v_16463:
    v_16696 = elt(env, 2); // false
    goto v_16464;
v_16465:
    goto v_16461;
v_16462:
    goto v_16463;
v_16464:
    v_16696 = (v_16698 == v_16696 ? lisp_true : nil);
    goto v_16448;
    v_16696 = nil;
v_16448:
    if (v_16696 == nil) goto v_16446;
    v_16696 = v_16697;
    goto v_16436;
v_16446:
    v_16696 = v_16697;
    v_16696 = Lconsp(nil, v_16696);
    env = stack[0];
    if (v_16696 == nil) goto v_16473;
    v_16696 = v_16697;
    v_16696 = qcar(v_16696);
    v_16696 = Lconsp(nil, v_16696);
    env = stack[0];
    if (v_16696 == nil) goto v_16473;
    goto v_16487;
v_16483:
    v_16696 = v_16697;
    v_16696 = qcar(v_16696);
    v_16698 = qcar(v_16696);
    goto v_16484;
v_16485:
    v_16696 = elt(env, 3); // (cong ncong)
    goto v_16486;
v_16487:
    goto v_16483;
v_16484:
    goto v_16485;
v_16486:
    v_16696 = Lmemq(nil, v_16698, v_16696);
    if (v_16696 == nil) goto v_16473;
    v_16696 = v_16697;
    fn = elt(env, 10); // pasf_mr
    v_16696 = (*qfn1(fn))(fn, v_16696);
    env = stack[0];
    fn = elt(env, 9); // pasf_vf
    v_16696 = (*qfn1(fn))(fn, v_16696);
    env = stack[0];
    fn = elt(env, 11); // pasf_cecong
    v_16696 = (*qfn1(fn))(fn, v_16696);
    env = stack[0];
    v_16697 = v_16696;
    goto v_16471;
v_16473:
    goto v_16507;
v_16503:
    goto v_16520;
v_16516:
    v_16698 = v_16697;
    goto v_16517;
v_16518:
    v_16696 = elt(env, 1); // true
    goto v_16519;
v_16520:
    goto v_16516;
v_16517:
    goto v_16518;
v_16519:
    if (v_16698 == v_16696) goto v_16514;
    else goto v_16515;
v_16514:
    v_16696 = lisp_true;
    goto v_16513;
v_16515:
    goto v_16530;
v_16526:
    v_16698 = v_16697;
    goto v_16527;
v_16528:
    v_16696 = elt(env, 2); // false
    goto v_16529;
v_16530:
    goto v_16526;
v_16527:
    goto v_16528;
v_16529:
    v_16696 = (v_16698 == v_16696 ? lisp_true : nil);
    goto v_16513;
    v_16696 = nil;
v_16513:
    if (v_16696 == nil) goto v_16511;
    v_16696 = v_16697;
    v_16698 = v_16696;
    goto v_16509;
v_16511:
    v_16696 = v_16697;
    v_16696 = qcar(v_16696);
    v_16696 = Lconsp(nil, v_16696);
    env = stack[0];
    if (v_16696 == nil) goto v_16536;
    v_16696 = v_16697;
    v_16696 = qcar(v_16696);
    v_16696 = qcar(v_16696);
    v_16698 = v_16696;
    goto v_16509;
v_16536:
    v_16696 = v_16697;
    v_16696 = qcar(v_16696);
    v_16698 = v_16696;
    goto v_16509;
    v_16698 = nil;
v_16509:
    goto v_16504;
v_16505:
    v_16696 = elt(env, 4); // (equal neq)
    goto v_16506;
v_16507:
    goto v_16503;
v_16504:
    goto v_16505;
v_16506:
    v_16696 = Lmemq(nil, v_16698, v_16696);
    if (v_16696 == nil) goto v_16502;
    v_16696 = v_16697;
    fn = elt(env, 12); // pasf_ceeq
    v_16696 = (*qfn1(fn))(fn, v_16696);
    env = stack[0];
    v_16697 = v_16696;
    goto v_16500;
v_16502:
    v_16696 = v_16697;
    fn = elt(env, 13); // pasf_cein
    v_16696 = (*qfn1(fn))(fn, v_16696);
    env = stack[0];
    v_16697 = v_16696;
    goto v_16500;
v_16500:
    goto v_16471;
v_16471:
    goto v_16567;
v_16563:
    v_16698 = v_16697;
    goto v_16564;
v_16565:
    v_16696 = elt(env, 1); // true
    goto v_16566;
v_16567:
    goto v_16563;
v_16564:
    goto v_16565;
v_16566:
    if (v_16698 == v_16696) goto v_16561;
    else goto v_16562;
v_16561:
    v_16696 = lisp_true;
    goto v_16560;
v_16562:
    goto v_16577;
v_16573:
    v_16698 = v_16697;
    goto v_16574;
v_16575:
    v_16696 = elt(env, 2); // false
    goto v_16576;
v_16577:
    goto v_16573;
v_16574:
    goto v_16575;
v_16576:
    v_16696 = (v_16698 == v_16696 ? lisp_true : nil);
    goto v_16560;
    v_16696 = nil;
v_16560:
    if (v_16696 == nil) goto v_16558;
    v_16696 = v_16697;
    goto v_16436;
v_16558:
    goto v_16590;
v_16586:
    goto v_16603;
v_16599:
    v_16698 = v_16697;
    goto v_16600;
v_16601:
    v_16696 = elt(env, 1); // true
    goto v_16602;
v_16603:
    goto v_16599;
v_16600:
    goto v_16601;
v_16602:
    if (v_16698 == v_16696) goto v_16597;
    else goto v_16598;
v_16597:
    v_16696 = lisp_true;
    goto v_16596;
v_16598:
    goto v_16613;
v_16609:
    v_16698 = v_16697;
    goto v_16610;
v_16611:
    v_16696 = elt(env, 2); // false
    goto v_16612;
v_16613:
    goto v_16609;
v_16610:
    goto v_16611;
v_16612:
    v_16696 = (v_16698 == v_16696 ? lisp_true : nil);
    goto v_16596;
    v_16696 = nil;
v_16596:
    if (v_16696 == nil) goto v_16594;
    v_16696 = v_16697;
    v_16698 = v_16696;
    goto v_16592;
v_16594:
    v_16696 = v_16697;
    v_16696 = qcar(v_16696);
    v_16696 = Lconsp(nil, v_16696);
    env = stack[0];
    if (v_16696 == nil) goto v_16619;
    v_16696 = v_16697;
    v_16696 = qcar(v_16696);
    v_16696 = qcar(v_16696);
    v_16698 = v_16696;
    goto v_16592;
v_16619:
    v_16696 = v_16697;
    v_16696 = qcar(v_16696);
    v_16698 = v_16696;
    goto v_16592;
    v_16698 = nil;
v_16592:
    goto v_16587;
v_16588:
    v_16696 = elt(env, 3); // (cong ncong)
    goto v_16589;
v_16590:
    goto v_16586;
v_16587:
    goto v_16588;
v_16589:
    v_16696 = Lmemq(nil, v_16698, v_16696);
    if (v_16696 == nil) goto v_16585;
    v_16696 = v_16697;
    fn = elt(env, 14); // pasf_sc
    v_16696 = (*qfn1(fn))(fn, v_16696);
    env = stack[0];
    goto v_16583;
v_16585:
    goto v_16640;
v_16636:
    goto v_16653;
v_16649:
    v_16698 = v_16697;
    goto v_16650;
v_16651:
    v_16696 = elt(env, 1); // true
    goto v_16652;
v_16653:
    goto v_16649;
v_16650:
    goto v_16651;
v_16652:
    if (v_16698 == v_16696) goto v_16647;
    else goto v_16648;
v_16647:
    v_16696 = lisp_true;
    goto v_16646;
v_16648:
    goto v_16663;
v_16659:
    v_16698 = v_16697;
    goto v_16660;
v_16661:
    v_16696 = elt(env, 2); // false
    goto v_16662;
v_16663:
    goto v_16659;
v_16660:
    goto v_16661;
v_16662:
    v_16696 = (v_16698 == v_16696 ? lisp_true : nil);
    goto v_16646;
    v_16696 = nil;
v_16646:
    if (v_16696 == nil) goto v_16644;
    v_16696 = v_16697;
    v_16698 = v_16696;
    goto v_16642;
v_16644:
    v_16696 = v_16697;
    v_16696 = qcar(v_16696);
    v_16696 = Lconsp(nil, v_16696);
    env = stack[0];
    if (v_16696 == nil) goto v_16669;
    v_16696 = v_16697;
    v_16696 = qcar(v_16696);
    v_16696 = qcar(v_16696);
    v_16698 = v_16696;
    goto v_16642;
v_16669:
    v_16696 = v_16697;
    v_16696 = qcar(v_16696);
    v_16698 = v_16696;
    goto v_16642;
    v_16698 = nil;
v_16642:
    goto v_16637;
v_16638:
    v_16696 = elt(env, 4); // (equal neq)
    goto v_16639;
v_16640:
    goto v_16636;
v_16637:
    goto v_16638;
v_16639:
    v_16696 = Lmemq(nil, v_16698, v_16696);
    if (v_16696 == nil) goto v_16635;
    v_16696 = v_16697;
    fn = elt(env, 15); // pasf_se
    v_16696 = (*qfn1(fn))(fn, v_16696);
    env = stack[0];
    goto v_16583;
v_16635:
    v_16696 = v_16697;
    fn = elt(env, 16); // pasf_or
    v_16696 = (*qfn1(fn))(fn, v_16696);
    env = stack[0];
    goto v_16583;
    v_16696 = nil;
v_16583:
    v_16697 = v_16696;
    v_16696 = qvalue(elt(env, 5)); // !*rlsifac
    if (v_16696 == nil) goto v_16690;
    else goto v_16691;
v_16690:
    v_16696 = v_16697;
    goto v_16436;
v_16691:
    v_16696 = v_16697;
    {
        fn = elt(env, 17); // pasf_fact
        return (*qfn1(fn))(fn, v_16696);
    }
v_16436:
    return onevalue(v_16696);
}



// Code for acfsf_0mk2

static LispObject CC_acfsf_0mk2(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16446, v_16447, v_16448;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16446 = v_16433;
    v_16447 = v_16432;
// end of prologue
    goto v_16442;
v_16436:
    v_16448 = v_16447;
    goto v_16437;
v_16438:
    v_16447 = v_16446;
    goto v_16439;
v_16440:
    v_16446 = nil;
    goto v_16441;
v_16442:
    goto v_16436;
v_16437:
    goto v_16438;
v_16439:
    goto v_16440;
v_16441:
    return list3(v_16448, v_16447, v_16446);
}



// Code for dm!-mkfloat

static LispObject CC_dmKmkfloat(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16452, v_16453;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_16452 = v_16432;
// end of prologue
    v_16453 = v_16452;
    v_16453 = Lintegerp(nil, v_16453);
    env = stack[0];
    if (v_16453 == nil) goto v_16437;
    goto v_16445;
v_16441:
    v_16453 = elt(env, 1); // !:rd!:
    if (!symbolp(v_16453)) v_16453 = nil;
    else { v_16453 = qfastgets(v_16453);
           if (v_16453 != nil) { v_16453 = elt(v_16453, 34); // i2d
#ifdef RECORD_GET
             if (v_16453 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_16453 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_16453 == SPID_NOPROP) v_16453 = nil; }}
#endif
    goto v_16442;
v_16443:
    goto v_16444;
v_16445:
    goto v_16441;
v_16442:
    goto v_16443;
v_16444:
        return Lapply1(nil, v_16453, v_16452);
v_16437:
    goto v_16435;
    v_16452 = nil;
v_16435:
    return onevalue(v_16452);
}



// Code for evrevgradlexcomp

static LispObject CC_evrevgradlexcomp(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16505, v_16506;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16432,v_16433);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_16433;
    stack[-2] = v_16432;
// end of prologue
v_16437:
    v_16505 = stack[-2];
    if (v_16505 == nil) goto v_16440;
    else goto v_16441;
v_16440:
    v_16505 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16436;
v_16441:
    v_16505 = stack[-1];
    if (v_16505 == nil) goto v_16444;
    else goto v_16445;
v_16444:
    v_16505 = elt(env, 1); // (0)
    stack[-1] = v_16505;
    goto v_16437;
v_16445:
    goto v_16455;
v_16451:
    v_16505 = stack[-2];
    v_16506 = qcar(v_16505);
    goto v_16452;
v_16453:
    v_16505 = stack[-1];
    v_16505 = qcar(v_16505);
    goto v_16454;
v_16455:
    goto v_16451;
v_16452:
    goto v_16453;
v_16454:
    fn = elt(env, 2); // iequal
    v_16505 = (*qfn2(fn))(fn, v_16506, v_16505);
    env = stack[-4];
    if (v_16505 == nil) goto v_16449;
    v_16505 = stack[-2];
    v_16505 = qcdr(v_16505);
    stack[-2] = v_16505;
    v_16505 = stack[-1];
    v_16505 = qcdr(v_16505);
    stack[-1] = v_16505;
    goto v_16437;
v_16449:
    v_16505 = stack[-2];
    fn = elt(env, 3); // evtdeg
    stack[0] = (*qfn1(fn))(fn, v_16505);
    env = stack[-4];
    v_16505 = stack[-1];
    fn = elt(env, 3); // evtdeg
    v_16505 = (*qfn1(fn))(fn, v_16505);
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v_16505;
    goto v_16481;
v_16477:
    v_16506 = stack[-3];
    goto v_16478;
v_16479:
    v_16505 = stack[0];
    goto v_16480;
v_16481:
    goto v_16477;
v_16478:
    goto v_16479;
v_16480:
    fn = elt(env, 2); // iequal
    v_16505 = (*qfn2(fn))(fn, v_16506, v_16505);
    env = stack[-4];
    if (v_16505 == nil) goto v_16475;
    goto v_16489;
v_16485:
    v_16506 = stack[-2];
    goto v_16486;
v_16487:
    v_16505 = stack[-1];
    goto v_16488;
v_16489:
    goto v_16485;
v_16486:
    goto v_16487;
v_16488:
    {
        fn = elt(env, 4); // evinvlexcomp
        return (*qfn2(fn))(fn, v_16506, v_16505);
    }
v_16475:
    goto v_16498;
v_16494:
    v_16506 = stack[-3];
    goto v_16495;
v_16496:
    v_16505 = stack[0];
    goto v_16497;
v_16498:
    goto v_16494;
v_16495:
    goto v_16496;
v_16497:
    if (((intptr_t)(v_16506)) > ((intptr_t)(v_16505))) goto v_16492;
    else goto v_16493;
v_16492:
    v_16505 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16473;
v_16493:
    v_16505 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_16473;
    v_16505 = nil;
v_16473:
    goto v_16436;
    v_16505 = nil;
v_16436:
    return onevalue(v_16505);
}



// Code for !*pf2sq

static LispObject CC_Hpf2sq(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16530, v_16531;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_16432;
// end of prologue
    goto v_16443;
v_16439:
    v_16531 = nil;
    goto v_16440;
v_16441:
    v_16530 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16442;
v_16443:
    goto v_16439;
v_16440:
    goto v_16441;
v_16442:
    v_16530 = cons(v_16531, v_16530);
    env = stack[-2];
    stack[-1] = v_16530;
    v_16530 = stack[0];
    if (v_16530 == nil) goto v_16448;
    else goto v_16449;
v_16448:
    v_16530 = stack[-1];
    goto v_16436;
v_16449:
    v_16530 = stack[0];
    stack[0] = v_16530;
v_16455:
    v_16530 = stack[0];
    if (v_16530 == nil) goto v_16459;
    else goto v_16460;
v_16459:
    goto v_16454;
v_16460:
    goto v_16468;
v_16464:
    goto v_16474;
v_16470:
    goto v_16483;
v_16479:
    v_16530 = stack[0];
    v_16530 = qcar(v_16530);
    v_16531 = qcar(v_16530);
    goto v_16480;
v_16481:
    v_16530 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16482;
v_16483:
    goto v_16479;
v_16480:
    goto v_16481;
v_16482:
    if (v_16531 == v_16530) goto v_16477;
    else goto v_16478;
v_16477:
    goto v_16493;
v_16489:
    v_16531 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16490;
v_16491:
    v_16530 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16492;
v_16493:
    goto v_16489;
v_16490:
    goto v_16491;
v_16492:
    v_16530 = cons(v_16531, v_16530);
    env = stack[-2];
    v_16531 = v_16530;
    goto v_16476;
v_16478:
    goto v_16503;
v_16499:
    goto v_16510;
v_16506:
    goto v_16516;
v_16512:
    v_16530 = stack[0];
    v_16530 = qcar(v_16530);
    v_16531 = qcar(v_16530);
    goto v_16513;
v_16514:
    v_16530 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16515;
v_16516:
    goto v_16512;
v_16513:
    goto v_16514;
v_16515:
    fn = elt(env, 2); // to
    v_16531 = (*qfn2(fn))(fn, v_16531, v_16530);
    env = stack[-2];
    goto v_16507;
v_16508:
    v_16530 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16509;
v_16510:
    goto v_16506;
v_16507:
    goto v_16508;
v_16509:
    v_16530 = cons(v_16531, v_16530);
    env = stack[-2];
    v_16531 = ncons(v_16530);
    env = stack[-2];
    goto v_16500;
v_16501:
    v_16530 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16502;
v_16503:
    goto v_16499;
v_16500:
    goto v_16501;
v_16502:
    v_16530 = cons(v_16531, v_16530);
    env = stack[-2];
    v_16531 = v_16530;
    goto v_16476;
    v_16531 = nil;
v_16476:
    goto v_16471;
v_16472:
    v_16530 = stack[0];
    v_16530 = qcar(v_16530);
    v_16530 = qcdr(v_16530);
    goto v_16473;
v_16474:
    goto v_16470;
v_16471:
    goto v_16472;
v_16473:
    fn = elt(env, 3); // multsq
    v_16531 = (*qfn2(fn))(fn, v_16531, v_16530);
    env = stack[-2];
    goto v_16465;
v_16466:
    v_16530 = stack[-1];
    goto v_16467;
v_16468:
    goto v_16464;
v_16465:
    goto v_16466;
v_16467:
    fn = elt(env, 4); // addsq
    v_16530 = (*qfn2(fn))(fn, v_16531, v_16530);
    env = stack[-2];
    stack[-1] = v_16530;
    v_16530 = stack[0];
    v_16530 = qcdr(v_16530);
    stack[0] = v_16530;
    goto v_16455;
v_16454:
    v_16530 = stack[-1];
v_16436:
    return onevalue(v_16530);
}



// Code for quotpri

static LispObject CC_quotpri(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16490, v_16491, v_16492;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_16491 = v_16432;
// end of prologue
    stack[0] = nil;
    v_16490 = qvalue(elt(env, 2)); // !*ratpri
    if (v_16490 == nil) goto v_16444;
    else goto v_16445;
v_16444:
    v_16490 = lisp_true;
    goto v_16443;
v_16445:
    v_16490 = qvalue(elt(env, 3)); // !*nat
    if (v_16490 == nil) goto v_16452;
    else goto v_16453;
v_16452:
    v_16490 = lisp_true;
    goto v_16451;
v_16453:
    v_16490 = qvalue(elt(env, 4)); // !*fort
    if (v_16490 == nil) goto v_16460;
    else goto v_16459;
v_16460:
    v_16490 = qvalue(elt(env, 5)); // !*list
    if (v_16490 == nil) goto v_16464;
    else goto v_16463;
v_16464:
    v_16490 = qvalue(elt(env, 6)); // !*mcd
    v_16490 = (v_16490 == nil ? lisp_true : nil);
v_16463:
v_16459:
    goto v_16451;
    v_16490 = nil;
v_16451:
    goto v_16443;
    v_16490 = nil;
v_16443:
    if (v_16490 == nil) goto v_16441;
    v_16490 = elt(env, 7); // failed
    goto v_16436;
v_16441:
    goto v_16476;
v_16472:
    v_16492 = qvalue(elt(env, 8)); // dmode!*
    goto v_16473;
v_16474:
    v_16490 = elt(env, 9); // ratmode
    goto v_16475;
v_16476:
    goto v_16472;
v_16473:
    goto v_16474;
v_16475:
    v_16490 = Lflagp(nil, v_16492, v_16490);
    env = stack[-1];
    if (v_16490 == nil) goto v_16470;
    v_16490 = qvalue(elt(env, 8)); // dmode!*
    stack[0] = v_16490;
    v_16490 = nil;
    qvalue(elt(env, 8)) = v_16490; // dmode!*
    goto v_16439;
v_16470:
v_16439:
    v_16490 = v_16491;
    fn = elt(env, 10); // ratfunpri1
    v_16490 = (*qfn1(fn))(fn, v_16490);
    env = stack[-1];
    v_16491 = v_16490;
    v_16490 = stack[0];
    if (v_16490 == nil) goto v_16486;
    v_16490 = stack[0];
    qvalue(elt(env, 8)) = v_16490; // dmode!*
    goto v_16484;
v_16486:
v_16484:
    v_16490 = v_16491;
v_16436:
    return onevalue(v_16490);
}



// Code for idtomind

static LispObject CC_idtomind(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16466, v_16467, v_16468;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16468 = v_16433;
    v_16466 = v_16432;
// end of prologue
    goto v_16443;
v_16439:
    v_16467 = v_16466;
    goto v_16440;
v_16441:
    v_16466 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16442;
v_16443:
    goto v_16439;
v_16440:
    goto v_16441;
v_16442:
    if (v_16467 == v_16466) goto v_16437;
    else goto v_16438;
v_16437:
    goto v_16450;
v_16446:
    v_16466 = v_16468;
    goto v_16447;
v_16448:
    v_16467 = qvalue(elt(env, 1)); // i2m_jetspace!*
    goto v_16449;
v_16450:
    goto v_16446;
v_16447:
    goto v_16448;
v_16449:
    v_16466 = Lassoc(nil, v_16466, v_16467);
    v_16466 = qcdr(v_16466);
    goto v_16436;
v_16438:
    goto v_16461;
v_16457:
    v_16466 = v_16468;
    goto v_16458;
v_16459:
    v_16467 = qvalue(elt(env, 2)); // i2m_jetspace_odd!*
    goto v_16460;
v_16461:
    goto v_16457;
v_16458:
    goto v_16459;
v_16460:
    v_16466 = Lassoc(nil, v_16466, v_16467);
    v_16466 = qcdr(v_16466);
    goto v_16436;
    v_16466 = nil;
v_16436:
    return onevalue(v_16466);
}



// Code for expansion_name

static LispObject CC_expansion_name(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16445;
    argcheck(nargs, 0, "expansion_name");
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
    goto v_16439;
v_16435:
    v_16445 = elt(env, 1); // lalr_internal_
    stack[0] = Lexplode(nil, v_16445);
    env = stack[-1];
    goto v_16436;
v_16437:
    v_16445 = qvalue(elt(env, 2)); // expansion_count
    v_16445 = add1(v_16445);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_16445; // expansion_count
    v_16445 = Lexplode(nil, v_16445);
    env = stack[-1];
    goto v_16438;
v_16439:
    goto v_16435;
v_16436:
    goto v_16437;
v_16438:
    v_16445 = Lappend(nil, stack[0], v_16445);
        return Lcompress(nil, v_16445);
}



// Code for talp_getinvfsym

static LispObject CC_talp_getinvfsym(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16485, v_16486;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16432,v_16433);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16433;
    stack[-1] = v_16432;
// end of prologue
    fn = elt(env, 2); // talp_getextl
    v_16485 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-2] = v_16485;
v_16442:
    goto v_16451;
v_16447:
    v_16485 = stack[-2];
    v_16485 = qcar(v_16485);
    v_16486 = qcar(v_16485);
    goto v_16448;
v_16449:
    v_16485 = stack[-1];
    goto v_16450;
v_16451:
    goto v_16447;
v_16448:
    goto v_16449;
v_16450:
    if (equal(v_16486, v_16485)) goto v_16445;
    else goto v_16446;
v_16445:
    goto v_16441;
v_16446:
    v_16485 = stack[-2];
    v_16485 = qcdr(v_16485);
    stack[-2] = v_16485;
    goto v_16442;
v_16441:
    v_16485 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_16485;
v_16462:
    goto v_16474;
v_16470:
    v_16486 = stack[0];
    goto v_16471;
v_16472:
    v_16485 = stack[-1];
    goto v_16473;
v_16474:
    goto v_16470;
v_16471:
    goto v_16472;
v_16473:
    v_16485 = difference2(v_16486, v_16485);
    env = stack[-3];
    v_16485 = Lminusp(nil, v_16485);
    env = stack[-3];
    if (v_16485 == nil) goto v_16467;
    goto v_16461;
v_16467:
    v_16485 = stack[-2];
    v_16485 = qcdr(v_16485);
    stack[-2] = v_16485;
    v_16485 = stack[-1];
    v_16485 = add1(v_16485);
    env = stack[-3];
    stack[-1] = v_16485;
    goto v_16462;
v_16461:
    v_16485 = stack[-2];
    v_16485 = qcar(v_16485);
    v_16485 = qcar(v_16485);
    return onevalue(v_16485);
}



// Code for qqe_ofsf_simpat

static LispObject CC_qqe_ofsf_simpat(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16464, v_16465;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_16432;
// end of prologue
    v_16464 = stack[0];
    fn = elt(env, 2); // qqe_arg2l
    v_16464 = (*qfn1(fn))(fn, v_16464);
    env = stack[-1];
    fn = elt(env, 3); // qqe_ofsf_chsimpterm
    v_16464 = (*qfn1(fn))(fn, v_16464);
    env = stack[-1];
    v_16464 = stack[0];
    fn = elt(env, 4); // qqe_arg2r
    v_16464 = (*qfn1(fn))(fn, v_16464);
    env = stack[-1];
    fn = elt(env, 3); // qqe_ofsf_chsimpterm
    v_16464 = (*qfn1(fn))(fn, v_16464);
    env = stack[-1];
    v_16464 = stack[0];
    fn = elt(env, 5); // qqe_arg!-check
    v_16464 = (*qfn1(fn))(fn, v_16464);
    env = stack[-1];
    goto v_16453;
v_16449:
    v_16464 = stack[0];
    fn = elt(env, 6); // qqe_op
    v_16465 = (*qfn1(fn))(fn, v_16464);
    env = stack[-1];
    goto v_16450;
v_16451:
    v_16464 = elt(env, 1); // (qequal qneq)
    goto v_16452;
v_16453:
    goto v_16449;
v_16450:
    goto v_16451;
v_16452:
    v_16464 = Lmemq(nil, v_16465, v_16464);
    if (v_16464 == nil) goto v_16448;
    v_16464 = stack[0];
    {
        fn = elt(env, 7); // qqe_simpat
        return (*qfn1(fn))(fn, v_16464);
    }
v_16448:
    v_16464 = stack[0];
    {
        fn = elt(env, 8); // ofsf_simpat
        return (*qfn1(fn))(fn, v_16464);
    }
    v_16464 = nil;
    return onevalue(v_16464);
}



// Code for repr_a

static LispObject CC_repr_a(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16452, v_16453;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_16432;
// end of prologue
    goto v_16439;
v_16435:
    v_16452 = stack[0];
    v_16452 = qcdr(v_16452);
    v_16452 = qcdr(v_16452);
    v_16452 = qcar(v_16452);
    v_16452 = Lreverse(nil, v_16452);
    env = stack[-1];
    v_16452 = qcar(v_16452);
    v_16453 = qcar(v_16452);
    goto v_16436;
v_16437:
    v_16452 = stack[0];
    v_16452 = qcdr(v_16452);
    v_16452 = qcdr(v_16452);
    v_16452 = qcdr(v_16452);
    v_16452 = qcar(v_16452);
    goto v_16438;
v_16439:
    goto v_16435;
v_16436:
    goto v_16437;
v_16438:
    {
        fn = elt(env, 1); // addf
        return (*qfn2(fn))(fn, v_16453, v_16452);
    }
}



// Code for ev_insert

static LispObject CC_ev_insert(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16498, v_16499, v_16500;
    LispObject fn;
    LispObject v_16435, v_16434, v_16433, v_16432;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ev_insert");
    va_start(aa, nargs);
    v_16432 = va_arg(aa, LispObject);
    v_16433 = va_arg(aa, LispObject);
    v_16434 = va_arg(aa, LispObject);
    v_16435 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_16435,v_16434,v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_16432,v_16433,v_16434,v_16435);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_16435;
    stack[-1] = v_16434;
    stack[-2] = v_16433;
    stack[-3] = v_16432;
// end of prologue
    v_16500 = nil;
v_16440:
    v_16498 = stack[-3];
    if (v_16498 == nil) goto v_16447;
    else goto v_16448;
v_16447:
    v_16498 = lisp_true;
    goto v_16446;
v_16448:
    v_16498 = stack[0];
    v_16498 = (v_16498 == nil ? lisp_true : nil);
    goto v_16446;
    v_16498 = nil;
v_16446:
    if (v_16498 == nil) goto v_16444;
    v_16498 = v_16500;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_16498);
    }
v_16444:
    goto v_16463;
v_16459:
    v_16498 = stack[0];
    v_16499 = qcar(v_16498);
    goto v_16460;
v_16461:
    v_16498 = stack[-2];
    goto v_16462;
v_16463:
    goto v_16459;
v_16460:
    goto v_16461;
v_16462:
    if (v_16499 == v_16498) goto v_16457;
    else goto v_16458;
v_16457:
    goto v_16472;
v_16468:
    stack[0] = v_16500;
    goto v_16469;
v_16470:
    goto v_16479;
v_16475:
    v_16499 = stack[-1];
    goto v_16476;
v_16477:
    v_16498 = stack[-3];
    v_16498 = qcdr(v_16498);
    goto v_16478;
v_16479:
    goto v_16475;
v_16476:
    goto v_16477;
v_16478:
    v_16498 = cons(v_16499, v_16498);
    env = stack[-4];
    goto v_16471;
v_16472:
    goto v_16468;
v_16469:
    goto v_16470;
v_16471:
    {
        LispObject v_16505 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_16505, v_16498);
    }
v_16458:
    goto v_16490;
v_16486:
    v_16498 = stack[-3];
    v_16498 = qcar(v_16498);
    goto v_16487;
v_16488:
    v_16499 = v_16500;
    goto v_16489;
v_16490:
    goto v_16486;
v_16487:
    goto v_16488;
v_16489:
    v_16498 = cons(v_16498, v_16499);
    env = stack[-4];
    v_16500 = v_16498;
    v_16498 = stack[-3];
    v_16498 = qcdr(v_16498);
    stack[-3] = v_16498;
    v_16498 = stack[0];
    v_16498 = qcdr(v_16498);
    stack[0] = v_16498;
    goto v_16440;
    v_16498 = nil;
    return onevalue(v_16498);
}



// Code for get!-height

static LispObject CC_getKheight(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16460;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_16432;
// end of prologue
    v_16460 = stack[0];
    if (v_16460 == nil) goto v_16436;
    else goto v_16437;
v_16436:
    v_16460 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16435;
v_16437:
    v_16460 = stack[0];
    if (is_number(v_16460)) goto v_16440;
    else goto v_16441;
v_16440:
    v_16460 = stack[0];
        return Labsval(nil, v_16460);
v_16441:
    goto v_16452;
v_16448:
    v_16460 = stack[0];
    v_16460 = qcar(v_16460);
    v_16460 = qcdr(v_16460);
    stack[-1] = CC_getKheight(elt(env, 0), v_16460);
    env = stack[-2];
    goto v_16449;
v_16450:
    v_16460 = stack[0];
    v_16460 = qcdr(v_16460);
    v_16460 = CC_getKheight(elt(env, 0), v_16460);
    env = stack[-2];
    goto v_16451;
v_16452:
    goto v_16448;
v_16449:
    goto v_16450;
v_16451:
    {
        LispObject v_16463 = stack[-1];
        fn = elt(env, 1); // max
        return (*qfn2(fn))(fn, v_16463, v_16460);
    }
    v_16460 = nil;
v_16435:
    return onevalue(v_16460);
}



// Code for getdec

static LispObject CC_getdec(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16454, v_16455;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_16432;
// end of prologue
    goto v_16443;
v_16439:
    v_16455 = nil;
    goto v_16440;
v_16441:
    v_16454 = stack[0];
    goto v_16442;
v_16443:
    goto v_16439;
v_16440:
    goto v_16441;
v_16442:
    fn = elt(env, 2); // symtabget
    v_16454 = (*qfn2(fn))(fn, v_16455, v_16454);
    env = stack[-1];
    v_16455 = v_16454;
    v_16454 = v_16455;
    if (v_16454 == nil) goto v_16448;
    else goto v_16449;
v_16448:
    v_16454 = stack[0];
    fn = elt(env, 3); // implicitdec
    v_16454 = (*qfn1(fn))(fn, v_16454);
    v_16455 = v_16454;
    goto v_16447;
v_16449:
v_16447:
    v_16454 = v_16455;
    return onevalue(v_16454);
}



// Code for unresidp

static LispObject CC_unresidp(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16443, v_16444;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16443 = v_16432;
// end of prologue
    goto v_16438;
v_16434:
    goto v_16435;
v_16436:
    v_16444 = qvalue(elt(env, 1)); // !*reservedops!*
    goto v_16437;
v_16438:
    goto v_16434;
v_16435:
    goto v_16436;
v_16437:
    v_16443 = Lmemq(nil, v_16443, v_16444);
    v_16443 = (v_16443 == nil ? lisp_true : nil);
    return onevalue(v_16443);
}



// Code for edge_new_parents

static LispObject CC_edge_new_parents(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16465, v_16466, v_16467;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_16467 = v_16432;
// end of prologue
    goto v_16442;
v_16438:
    v_16465 = v_16467;
    v_16466 = qcar(v_16465);
    goto v_16439;
v_16440:
    v_16465 = qvalue(elt(env, 1)); // old_edge_list
    goto v_16441;
v_16442:
    goto v_16438;
v_16439:
    goto v_16440;
v_16441:
    v_16465 = Lassoc(nil, v_16466, v_16465);
    if (v_16465 == nil) goto v_16437;
    v_16465 = nil;
    goto v_16435;
v_16437:
    v_16465 = v_16467;
    v_16465 = qcdr(v_16465);
    v_16465 = qcar(v_16465);
    goto v_16460;
v_16456:
    v_16466 = v_16465;
    v_16466 = qcar(v_16466);
    goto v_16457;
v_16458:
    v_16465 = qcdr(v_16465);
    goto v_16459;
v_16460:
    goto v_16456;
v_16457:
    goto v_16458;
v_16459:
    v_16465 = list2(v_16466, v_16465);
    env = stack[0];
    {
        fn = elt(env, 2); // edge_new_parent
        return (*qfn1(fn))(fn, v_16465);
    }
    v_16465 = nil;
v_16435:
    return onevalue(v_16465);
}



// Code for no!-side!-effect!-listp

static LispObject CC_noKsideKeffectKlistp(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16455;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_16432;
// end of prologue
v_16431:
    v_16455 = stack[0];
    if (v_16455 == nil) goto v_16436;
    else goto v_16437;
v_16436:
    v_16455 = lisp_true;
    goto v_16435;
v_16437:
    v_16455 = stack[0];
    v_16455 = qcar(v_16455);
    fn = elt(env, 1); // no!-side!-effectp
    v_16455 = (*qfn1(fn))(fn, v_16455);
    env = stack[-1];
    if (v_16455 == nil) goto v_16444;
    else goto v_16445;
v_16444:
    v_16455 = nil;
    goto v_16443;
v_16445:
    v_16455 = stack[0];
    v_16455 = qcdr(v_16455);
    stack[0] = v_16455;
    goto v_16431;
    v_16455 = nil;
v_16443:
    goto v_16435;
    v_16455 = nil;
v_16435:
    return onevalue(v_16455);
}



// Code for generic!-sub

static LispObject CC_genericKsub(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16454, v_16455;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16432,v_16433);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_16454 = v_16433;
    v_16455 = v_16432;
// end of prologue
    goto v_16440;
v_16436:
    stack[-2] = v_16455;
    goto v_16437;
v_16438:
    goto v_16449;
v_16443:
    stack[-1] = elt(env, 1); // dfp
    goto v_16444;
v_16445:
    stack[0] = v_16454;
    goto v_16446;
v_16447:
    v_16454 = elt(env, 2); // list
    v_16454 = ncons(v_16454);
    env = stack[-3];
    goto v_16448;
v_16449:
    goto v_16443;
v_16444:
    goto v_16445;
v_16446:
    goto v_16447;
v_16448:
    v_16454 = list3(stack[-1], stack[0], v_16454);
    env = stack[-3];
    goto v_16439;
v_16440:
    goto v_16436;
v_16437:
    goto v_16438;
v_16439:
    {
        LispObject v_16459 = stack[-2];
        fn = elt(env, 3); // dfp!-sub
        return (*qfn2(fn))(fn, v_16459, v_16454);
    }
}



// Code for aex_divposcnt

static LispObject CC_aex_divposcnt(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16526, v_16527;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16432,v_16433);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_16526 = v_16433;
    stack[-2] = v_16432;
// end of prologue
    v_16526 = stack[-2];
    fn = elt(env, 2); // aex_ex
    v_16526 = (*qfn1(fn))(fn, v_16526);
    env = stack[-4];
    v_16526 = qcar(v_16526);
    stack[0] = v_16526;
    v_16526 = stack[0];
    fn = elt(env, 3); // sfto_ucontentf
    v_16526 = (*qfn1(fn))(fn, v_16526);
    env = stack[-4];
    stack[-1] = v_16526;
    goto v_16454;
v_16450:
    v_16527 = stack[0];
    goto v_16451;
v_16452:
    v_16526 = stack[-1];
    goto v_16453;
v_16454:
    goto v_16450;
v_16451:
    goto v_16452;
v_16453:
    fn = elt(env, 4); // quotfx
    v_16526 = (*qfn2(fn))(fn, v_16527, v_16526);
    env = stack[-4];
    stack[0] = v_16526;
    goto v_16463;
v_16459:
    goto v_16469;
v_16465:
    v_16527 = stack[-1];
    goto v_16466;
v_16467:
    v_16526 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16468;
v_16469:
    goto v_16465;
v_16466:
    goto v_16467;
v_16468:
    stack[-3] = cons(v_16527, v_16526);
    env = stack[-4];
    goto v_16460;
v_16461:
    goto v_16477;
v_16473:
    v_16526 = stack[-1];
    fn = elt(env, 5); // kernels
    stack[-1] = (*qfn1(fn))(fn, v_16526);
    env = stack[-4];
    goto v_16474;
v_16475:
    v_16526 = stack[-2];
    fn = elt(env, 6); // aex_ctx
    v_16526 = (*qfn1(fn))(fn, v_16526);
    env = stack[-4];
    goto v_16476;
v_16477:
    goto v_16473;
v_16474:
    goto v_16475;
v_16476:
    fn = elt(env, 7); // ctx_filter
    v_16526 = (*qfn2(fn))(fn, stack[-1], v_16526);
    env = stack[-4];
    goto v_16462;
v_16463:
    goto v_16459;
v_16460:
    goto v_16461;
v_16462:
    fn = elt(env, 8); // aex_mk
    v_16526 = (*qfn2(fn))(fn, stack[-3], v_16526);
    env = stack[-4];
    fn = elt(env, 9); // aex_sgn
    v_16526 = (*qfn1(fn))(fn, v_16526);
    env = stack[-4];
    stack[-3] = v_16526;
    goto v_16485;
    goto v_16483;
v_16485:
v_16483:
    goto v_16492;
v_16488:
    goto v_16498;
v_16494:
    v_16527 = stack[0];
    goto v_16495;
v_16496:
    v_16526 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16497;
v_16498:
    goto v_16494;
v_16495:
    goto v_16496;
v_16497:
    stack[-1] = cons(v_16527, v_16526);
    env = stack[-4];
    goto v_16489;
v_16490:
    goto v_16506;
v_16502:
    v_16526 = stack[0];
    fn = elt(env, 5); // kernels
    stack[0] = (*qfn1(fn))(fn, v_16526);
    env = stack[-4];
    goto v_16503;
v_16504:
    v_16526 = stack[-2];
    fn = elt(env, 6); // aex_ctx
    v_16526 = (*qfn1(fn))(fn, v_16526);
    env = stack[-4];
    goto v_16505;
v_16506:
    goto v_16502;
v_16503:
    goto v_16504;
v_16505:
    fn = elt(env, 7); // ctx_filter
    v_16526 = (*qfn2(fn))(fn, stack[0], v_16526);
    env = stack[-4];
    goto v_16491;
v_16492:
    goto v_16488;
v_16489:
    goto v_16490;
v_16491:
    fn = elt(env, 8); // aex_mk
    v_16526 = (*qfn2(fn))(fn, stack[-1], v_16526);
    env = stack[-4];
    stack[0] = v_16526;
    goto v_16520;
v_16516:
    v_16527 = stack[-3];
    goto v_16517;
v_16518:
    v_16526 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16519;
v_16520:
    goto v_16516;
v_16517:
    goto v_16518;
v_16519:
    v_16526 = Leqn(nil, v_16527, v_16526);
    env = stack[-4];
    if (v_16526 == nil) goto v_16514;
    v_16526 = stack[0];
    goto v_16441;
v_16514:
    v_16526 = stack[0];
    {
        fn = elt(env, 10); // aex_neg
        return (*qfn1(fn))(fn, v_16526);
    }
v_16441:
    return onevalue(v_16526);
}



// Code for mkfil!*

static LispObject CC_mkfilH(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16475, v_16476;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_16432;
// end of prologue
    v_16476 = nil;
    v_16475 = stack[0];
    v_16475 = Lstringp(nil, v_16475);
    env = stack[-1];
    if (v_16475 == nil) goto v_16441;
    v_16475 = stack[0];
    goto v_16439;
v_16441:
    v_16475 = stack[0];
    if (symbolp(v_16475)) goto v_16446;
    goto v_16453;
v_16449:
    v_16476 = stack[0];
    goto v_16450;
v_16451:
    v_16475 = elt(env, 2); // "file name"
    goto v_16452;
v_16453:
    goto v_16449;
v_16450:
    goto v_16451;
v_16452:
    {
        fn = elt(env, 3); // typerr
        return (*qfn2(fn))(fn, v_16476, v_16475);
    }
v_16446:
    v_16475 = stack[0];
    if (!symbolp(v_16475)) v_16475 = nil;
    else { v_16475 = qfastgets(v_16475);
           if (v_16475 != nil) { v_16475 = elt(v_16475, 17); // share
#ifdef RECORD_GET
             if (v_16475 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v_16475 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v_16475 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v_16475 == SPID_NOPROP) v_16475 = nil; else v_16475 = lisp_true; }}
#endif
    if (v_16475 == nil) goto v_16461;
    v_16475 = stack[0];
    fn = elt(env, 4); // eval
    v_16475 = (*qfn1(fn))(fn, v_16475);
    env = stack[-1];
    v_16476 = v_16475;
    v_16475 = Lstringp(nil, v_16475);
    env = stack[-1];
    goto v_16459;
v_16461:
    v_16475 = nil;
    goto v_16459;
    v_16475 = nil;
v_16459:
    if (v_16475 == nil) goto v_16457;
    v_16475 = v_16476;
    goto v_16439;
v_16457:
    v_16475 = stack[0];
    {
        fn = elt(env, 5); // string!-downcase
        return (*qfn1(fn))(fn, v_16475);
    }
    v_16475 = nil;
v_16439:
    return onevalue(v_16475);
}



// Code for pushback

static LispObject CC_pushback(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16477, v_16478;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16432,v_16433);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_16433;
    v_16477 = v_16432;
// end of prologue
v_16442:
    v_16478 = v_16477;
    v_16478 = qcar(v_16478);
    if (v_16478 == nil) goto v_16445;
    else goto v_16446;
v_16445:
    goto v_16441;
v_16446:
    v_16477 = qcdr(v_16477);
    goto v_16442;
v_16441:
    goto v_16458;
v_16454:
    goto v_16464;
v_16460:
    stack[-1] = v_16477;
    goto v_16461;
v_16462:
    goto v_16471;
v_16467:
    v_16478 = v_16477;
    v_16478 = qcar(v_16478);
    goto v_16468;
v_16469:
    v_16477 = qcdr(v_16477);
    goto v_16470;
v_16471:
    goto v_16467;
v_16468:
    goto v_16469;
v_16470:
    v_16477 = cons(v_16478, v_16477);
    env = stack[-2];
    goto v_16463;
v_16464:
    goto v_16460;
v_16461:
    goto v_16462;
v_16463:
    v_16478 = Lrplacd(nil, stack[-1], v_16477);
    env = stack[-2];
    goto v_16455;
v_16456:
    v_16477 = stack[0];
    goto v_16457;
v_16458:
    goto v_16454;
v_16455:
    goto v_16456;
v_16457:
    v_16477 = Lrplaca(nil, v_16478, v_16477);
    v_16477 = nil;
    return onevalue(v_16477);
}



// Code for cl_sordpl

static LispObject CC_cl_sordpl(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16475, v_16476, v_16477, v_16478;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16476 = v_16433;
    v_16477 = v_16432;
// end of prologue
v_16437:
    v_16475 = v_16476;
    if (v_16475 == nil) goto v_16440;
    else goto v_16441;
v_16440:
    v_16475 = nil;
    goto v_16436;
v_16441:
    v_16475 = v_16477;
    if (v_16475 == nil) goto v_16444;
    else goto v_16445;
v_16444:
    v_16475 = lisp_true;
    goto v_16436;
v_16445:
    goto v_16454;
v_16450:
    v_16475 = v_16477;
    v_16478 = qcar(v_16475);
    goto v_16451;
v_16452:
    v_16475 = v_16476;
    v_16475 = qcar(v_16475);
    goto v_16453;
v_16454:
    goto v_16450;
v_16451:
    goto v_16452;
v_16453:
    if (equal(v_16478, v_16475)) goto v_16449;
    goto v_16464;
v_16460:
    v_16475 = v_16477;
    v_16475 = qcar(v_16475);
    goto v_16461;
v_16462:
    v_16476 = qcar(v_16476);
    goto v_16463;
v_16464:
    goto v_16460;
v_16461:
    goto v_16462;
v_16463:
    {
        fn = elt(env, 1); // cl_sordp
        return (*qfn2(fn))(fn, v_16475, v_16476);
    }
v_16449:
    v_16475 = v_16477;
    v_16475 = qcdr(v_16475);
    v_16477 = v_16475;
    v_16475 = v_16476;
    v_16475 = qcdr(v_16475);
    v_16476 = v_16475;
    goto v_16437;
    v_16475 = nil;
v_16436:
    return onevalue(v_16475);
}



// Code for sfto_b!:ordexn

static LispObject CC_sfto_bTordexn(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16525, v_16526;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16432,v_16433);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_16433;
    stack[-2] = v_16432;
// end of prologue
    stack[0] = nil;
    stack[-3] = nil;
v_16439:
    v_16525 = stack[-1];
    if (v_16525 == nil) goto v_16443;
    else goto v_16444;
v_16443:
    goto v_16451;
v_16447:
    goto v_16448;
v_16449:
    goto v_16459;
v_16455:
    v_16526 = stack[-2];
    goto v_16456;
v_16457:
    v_16525 = stack[-3];
    goto v_16458;
v_16459:
    goto v_16455;
v_16456:
    goto v_16457;
v_16458:
    v_16525 = cons(v_16526, v_16525);
    env = stack[-4];
    v_16525 = Lreverse(nil, v_16525);
    goto v_16450;
v_16451:
    goto v_16447;
v_16448:
    goto v_16449;
v_16450:
    {
        LispObject v_16531 = stack[0];
        return cons(v_16531, v_16525);
    }
v_16444:
    goto v_16468;
v_16464:
    v_16526 = stack[-2];
    goto v_16465;
v_16466:
    v_16525 = stack[-1];
    v_16525 = qcar(v_16525);
    goto v_16467;
v_16468:
    goto v_16464;
v_16465:
    goto v_16466;
v_16467:
    if (equal(v_16526, v_16525)) goto v_16462;
    else goto v_16463;
v_16462:
    v_16525 = nil;
    goto v_16438;
v_16463:
    v_16525 = stack[-2];
    if (v_16525 == nil) goto v_16474;
    goto v_16483;
v_16479:
    v_16526 = stack[-2];
    goto v_16480;
v_16481:
    v_16525 = stack[-1];
    v_16525 = qcar(v_16525);
    goto v_16482;
v_16483:
    goto v_16479;
v_16480:
    goto v_16481;
v_16482:
    v_16525 = (LispObject)greaterp2(v_16526, v_16525);
    v_16525 = v_16525 ? lisp_true : nil;
    env = stack[-4];
    if (v_16525 == nil) goto v_16474;
    goto v_16492;
v_16488:
    goto v_16489;
v_16490:
    goto v_16499;
v_16495:
    goto v_16506;
v_16502:
    v_16526 = stack[-2];
    goto v_16503;
v_16504:
    v_16525 = stack[-3];
    goto v_16505;
v_16506:
    goto v_16502;
v_16503:
    goto v_16504;
v_16505:
    v_16525 = cons(v_16526, v_16525);
    env = stack[-4];
    v_16526 = Lreverse(nil, v_16525);
    env = stack[-4];
    goto v_16496;
v_16497:
    v_16525 = stack[-1];
    goto v_16498;
v_16499:
    goto v_16495;
v_16496:
    goto v_16497;
v_16498:
    v_16525 = Lappend(nil, v_16526, v_16525);
    goto v_16491;
v_16492:
    goto v_16488;
v_16489:
    goto v_16490;
v_16491:
    {
        LispObject v_16532 = stack[0];
        return cons(v_16532, v_16525);
    }
v_16474:
    goto v_16517;
v_16513:
    v_16525 = stack[-1];
    v_16526 = qcar(v_16525);
    goto v_16514;
v_16515:
    v_16525 = stack[-3];
    goto v_16516;
v_16517:
    goto v_16513;
v_16514:
    goto v_16515;
v_16516:
    v_16525 = cons(v_16526, v_16525);
    env = stack[-4];
    stack[-3] = v_16525;
    v_16525 = stack[-1];
    v_16525 = qcdr(v_16525);
    stack[-1] = v_16525;
    v_16525 = stack[0];
    v_16525 = (v_16525 == nil ? lisp_true : nil);
    stack[0] = v_16525;
    goto v_16442;
v_16442:
    goto v_16439;
v_16438:
    return onevalue(v_16525);
}



// Code for omfir

static LispObject CC_omfir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16466, v_16467;
    LispObject fn;
    argcheck(nargs, 0, "omfir");
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
    goto v_16442;
v_16438:
    v_16467 = qvalue(elt(env, 2)); // atts
    goto v_16439;
v_16440:
    v_16466 = elt(env, 3); // dec
    goto v_16441;
v_16442:
    goto v_16438;
v_16439:
    goto v_16440;
v_16441:
    fn = elt(env, 6); // find
    v_16466 = (*qfn2(fn))(fn, v_16467, v_16466);
    env = stack[-1];
    stack[0] = v_16466;
    goto v_16454;
v_16450:
    v_16467 = qvalue(elt(env, 2)); // atts
    goto v_16451;
v_16452:
    v_16466 = elt(env, 4); // name
    goto v_16453;
v_16454:
    goto v_16450;
v_16451:
    goto v_16452;
v_16453:
    fn = elt(env, 6); // find
    v_16466 = (*qfn2(fn))(fn, v_16467, v_16466);
    env = stack[-1];
    if (v_16466 == nil) goto v_16448;
    goto v_16462;
v_16458:
    v_16467 = elt(env, 5); // "wrong att"
    goto v_16459;
v_16460:
    v_16466 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_16461;
v_16462:
    goto v_16458;
v_16459:
    goto v_16460;
v_16461:
    fn = elt(env, 7); // errorml
    v_16466 = (*qfn2(fn))(fn, v_16467, v_16466);
    goto v_16446;
v_16448:
v_16446:
    v_16466 = stack[0];
    return onevalue(v_16466);
}



// Code for exptplus

static LispObject CC_exptplus(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16482, v_16483, v_16484;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16432,v_16433);
    }
// copy arguments values to proper place
    v_16483 = v_16433;
    v_16484 = v_16432;
// end of prologue
    v_16482 = v_16484;
    if (!consp(v_16482)) goto v_16437;
    else goto v_16438;
v_16437:
    v_16482 = v_16483;
    if (!consp(v_16482)) goto v_16442;
    else goto v_16443;
v_16442:
    goto v_16450;
v_16446:
    v_16482 = v_16484;
    goto v_16447;
v_16448:
    goto v_16449;
v_16450:
    goto v_16446;
v_16447:
    goto v_16448;
v_16449:
    return plus2(v_16482, v_16483);
v_16443:
    goto v_16461;
v_16457:
    v_16482 = v_16484;
    goto v_16458;
v_16459:
    v_16483 = qcar(v_16483);
    goto v_16460;
v_16461:
    goto v_16457;
v_16458:
    goto v_16459;
v_16460:
    v_16482 = plus2(v_16482, v_16483);
    return ncons(v_16482);
    v_16482 = nil;
    goto v_16436;
v_16438:
    v_16482 = v_16483;
    if (!consp(v_16482)) goto v_16465;
    else goto v_16466;
v_16465:
    goto v_16474;
v_16470:
    v_16482 = v_16484;
    v_16482 = qcar(v_16482);
    goto v_16471;
v_16472:
    goto v_16473;
v_16474:
    goto v_16470;
v_16471:
    goto v_16472;
v_16473:
    v_16482 = plus2(v_16482, v_16483);
    return ncons(v_16482);
v_16466:
    v_16482 = elt(env, 1); // "Bad exponent sum"
    {
        fn = elt(env, 2); // interr
        return (*qfn1(fn))(fn, v_16482);
    }
    v_16482 = nil;
v_16436:
    return onevalue(v_16482);
}



// Code for initarg

static LispObject CC_initarg(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16654, v_16655;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_16432;
// end of prologue
    v_16654 = qvalue(elt(env, 2)); // op
    if (!symbolp(v_16654)) v_16654 = nil;
    else { v_16654 = qfastgets(v_16654);
           if (v_16654 != nil) { v_16654 = elt(v_16654, 43); // symmetric
#ifdef RECORD_GET
             if (v_16654 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v_16654 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v_16654 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v_16654 == SPID_NOPROP) v_16654 = nil; else v_16654 = lisp_true; }}
#endif
    qvalue(elt(env, 3)) = v_16654; // symm
    goto v_16453;
v_16449:
    v_16654 = qvalue(elt(env, 4)); // p
    stack[0] = Llength(nil, v_16654);
    env = stack[-6];
    goto v_16450;
v_16451:
    v_16654 = qvalue(elt(env, 5)); // r
    v_16654 = Llength(nil, v_16654);
    env = stack[-6];
    goto v_16452;
v_16453:
    goto v_16449;
v_16450:
    goto v_16451;
v_16452:
    v_16654 = difference2(stack[0], v_16654);
    env = stack[-6];
    v_16654 = add1(v_16654);
    env = stack[-6];
    stack[-1] = v_16654;
    v_16654 = qvalue(elt(env, 2)); // op
    fn = elt(env, 15); // ident
    v_16654 = (*qfn1(fn))(fn, v_16654);
    env = stack[-6];
    qvalue(elt(env, 6)) = v_16654; // identity
    v_16654 = qvalue(elt(env, 5)); // r
    v_16654 = qcar(v_16654);
    fn = elt(env, 16); // mgenp
    v_16654 = (*qfn1(fn))(fn, v_16654);
    env = stack[-6];
    stack[-3] = v_16654;
    v_16654 = qvalue(elt(env, 5)); // r
    v_16654 = qcdr(v_16654);
    fn = elt(env, 17); // list!-mgen
    v_16654 = (*qfn1(fn))(fn, v_16654);
    env = stack[-6];
    stack[0] = v_16654;
    goto v_16475;
v_16471:
    v_16655 = qvalue(elt(env, 2)); // op
    goto v_16472;
v_16473:
    v_16654 = elt(env, 7); // assoc
    goto v_16474;
v_16475:
    goto v_16471;
v_16472:
    goto v_16473;
v_16474:
    v_16654 = Lflagp(nil, v_16655, v_16654);
    env = stack[-6];
    if (v_16654 == nil) goto v_16469;
    v_16654 = qvalue(elt(env, 3)); // symm
    if (v_16654 == nil) goto v_16480;
    else goto v_16481;
v_16480:
    v_16654 = nil;
    goto v_16479;
v_16481:
    goto v_16495;
v_16491:
    v_16655 = stack[0];
    goto v_16492;
v_16493:
    v_16654 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16494;
v_16495:
    goto v_16491;
v_16492:
    goto v_16493;
v_16494:
    v_16654 = (LispObject)greaterp2(v_16655, v_16654);
    v_16654 = v_16654 ? lisp_true : nil;
    env = stack[-6];
    if (v_16654 == nil) goto v_16488;
    else goto v_16489;
v_16488:
    v_16654 = nil;
    goto v_16487;
v_16489:
    v_16654 = qvalue(elt(env, 8)); // !*sym!-assoc
    v_16654 = (v_16654 == nil ? lisp_true : nil);
    goto v_16487;
    v_16654 = nil;
v_16487:
    goto v_16479;
    v_16654 = nil;
v_16479:
    v_16654 = (v_16654 == nil ? lisp_true : nil);
    goto v_16467;
v_16469:
    v_16654 = nil;
    goto v_16467;
    v_16654 = nil;
v_16467:
    stack[-5] = v_16654;
    goto v_16516;
v_16512:
    v_16654 = qvalue(elt(env, 5)); // r
    v_16655 = Llength(nil, v_16654);
    env = stack[-6];
    goto v_16513;
v_16514:
    v_16654 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16515;
v_16516:
    goto v_16512;
v_16513:
    goto v_16514;
v_16515:
    v_16654 = (LispObject)greaterp2(v_16655, v_16654);
    v_16654 = v_16654 ? lisp_true : nil;
    env = stack[-6];
    if (v_16654 == nil) goto v_16509;
    else goto v_16510;
v_16509:
    v_16654 = nil;
    goto v_16508;
v_16510:
    v_16654 = stack[-5];
    if (v_16654 == nil) goto v_16525;
    else goto v_16524;
v_16525:
    v_16654 = stack[0];
v_16524:
    goto v_16508;
    v_16654 = nil;
v_16508:
    stack[-2] = v_16654;
    goto v_16536;
v_16532:
    v_16655 = stack[-1];
    goto v_16533;
v_16534:
    v_16654 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16535;
v_16536:
    goto v_16532;
v_16533:
    goto v_16534;
v_16535:
    v_16654 = (LispObject)greaterp2(v_16655, v_16654);
    v_16654 = v_16654 ? lisp_true : nil;
    env = stack[-6];
    if (v_16654 == nil) goto v_16530;
    else goto v_16529;
v_16530:
    v_16654 = qvalue(elt(env, 6)); // identity
    if (v_16654 == nil) goto v_16541;
    else goto v_16542;
v_16541:
    v_16654 = nil;
    goto v_16540;
v_16542:
    goto v_16552;
v_16548:
    v_16654 = qvalue(elt(env, 4)); // p
    v_16655 = Llength(nil, v_16654);
    env = stack[-6];
    goto v_16549;
v_16550:
    v_16654 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16551;
v_16552:
    goto v_16548;
v_16549:
    goto v_16550;
v_16551:
    v_16654 = (LispObject)greaterp2(v_16655, v_16654);
    v_16654 = v_16654 ? lisp_true : nil;
    env = stack[-6];
    goto v_16540;
    v_16654 = nil;
v_16540:
v_16529:
    v_16655 = v_16654;
    v_16654 = stack[-3];
    if (v_16654 == nil) goto v_16558;
    else goto v_16559;
v_16558:
    v_16654 = nil;
    goto v_16557;
v_16559:
    v_16654 = v_16655;
    goto v_16557;
    v_16654 = nil;
v_16557:
    qvalue(elt(env, 9)) = v_16654; // mcontract
    v_16654 = stack[-5];
    if (v_16654 == nil) goto v_16567;
    else goto v_16568;
v_16567:
    v_16654 = nil;
    goto v_16566;
v_16568:
    v_16654 = v_16655;
    if (v_16654 == nil) goto v_16575;
    else goto v_16576;
v_16575:
    v_16654 = nil;
    goto v_16574;
v_16576:
    v_16654 = stack[-3];
    v_16654 = (v_16654 == nil ? lisp_true : nil);
    goto v_16574;
    v_16654 = nil;
v_16574:
    goto v_16566;
    v_16654 = nil;
v_16566:
    qvalue(elt(env, 10)) = v_16654; // acontract
    v_16654 = qvalue(elt(env, 6)); // identity
    if (v_16654 == nil) goto v_16585;
    else goto v_16586;
v_16585:
    v_16654 = nil;
    goto v_16584;
v_16586:
    goto v_16599;
v_16595:
    v_16655 = stack[-1];
    goto v_16596;
v_16597:
    v_16654 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16598;
v_16599:
    goto v_16595;
v_16596:
    goto v_16597;
v_16598:
    v_16654 = (LispObject)lessp2(v_16655, v_16654);
    v_16654 = v_16654 ? lisp_true : nil;
    env = stack[-6];
    if (v_16654 == nil) goto v_16593;
    else goto v_16592;
v_16593:
    v_16654 = stack[-2];
v_16592:
    goto v_16584;
    v_16654 = nil;
v_16584:
    qvalue(elt(env, 11)) = v_16654; // expand
    v_16654 = stack[-2];
    if (v_16654 == nil) goto v_16607;
    else goto v_16605;
v_16607:
    goto v_16615;
v_16611:
    v_16655 = stack[-1];
    goto v_16612;
v_16613:
    v_16654 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16614;
v_16615:
    goto v_16611;
v_16612:
    goto v_16613;
v_16614:
    v_16654 = (LispObject)lessp2(v_16655, v_16654);
    v_16654 = v_16654 ? lisp_true : nil;
    env = stack[-6];
    if (v_16654 == nil) goto v_16609;
    else goto v_16605;
v_16609:
    goto v_16606;
v_16605:
    v_16654 = stack[-3];
    if (v_16654 == nil) goto v_16621;
    v_16654 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16619;
v_16621:
    v_16654 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16619;
    v_16654 = nil;
v_16619:
    goto v_16604;
v_16606:
    v_16654 = stack[-1];
    goto v_16604;
    v_16654 = nil;
v_16604:
    qvalue(elt(env, 12)) = v_16654; // i
    v_16654 = qvalue(elt(env, 6)); // identity
    if (v_16654 == nil) goto v_16633;
    v_16654 = qvalue(elt(env, 4)); // p
    v_16654 = Llength(nil, v_16654);
    env = stack[-6];
    goto v_16631;
v_16633:
    goto v_16644;
v_16640:
    v_16655 = stack[-1];
    goto v_16641;
v_16642:
    v_16654 = stack[0];
    goto v_16643;
v_16644:
    goto v_16640;
v_16641:
    goto v_16642;
v_16643:
    v_16654 = plus2(v_16655, v_16654);
    env = stack[-6];
    goto v_16631;
    v_16654 = nil;
v_16631:
    qvalue(elt(env, 13)) = v_16654; // upb
    v_16654 = qvalue(elt(env, 3)); // symm
    if (v_16654 == nil) goto v_16650;
    v_16654 = stack[-4];
    fn = elt(env, 18); // initcomb
    v_16654 = (*qfn1(fn))(fn, v_16654);
    env = stack[-6];
    qvalue(elt(env, 14)) = v_16654; // comb
    goto v_16648;
v_16650:
v_16648:
    v_16654 = nil;
    return onevalue(v_16654);
}



// Code for dipprod

static LispObject CC_dipprod(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16467, v_16468;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16432,v_16433);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16433;
    stack[-1] = v_16432;
// end of prologue
    goto v_16444;
v_16440:
    v_16467 = stack[-1];
    fn = elt(env, 1); // diplength
    stack[-2] = (*qfn1(fn))(fn, v_16467);
    env = stack[-3];
    goto v_16441;
v_16442:
    v_16467 = stack[0];
    fn = elt(env, 1); // diplength
    v_16467 = (*qfn1(fn))(fn, v_16467);
    env = stack[-3];
    goto v_16443;
v_16444:
    goto v_16440;
v_16441:
    goto v_16442;
v_16443:
    v_16467 = (LispObject)lesseq2(stack[-2], v_16467);
    v_16467 = v_16467 ? lisp_true : nil;
    env = stack[-3];
    if (v_16467 == nil) goto v_16438;
    goto v_16454;
v_16450:
    v_16468 = stack[-1];
    goto v_16451;
v_16452:
    v_16467 = stack[0];
    goto v_16453;
v_16454:
    goto v_16450;
v_16451:
    goto v_16452;
v_16453:
    {
        fn = elt(env, 2); // dipprodin
        return (*qfn2(fn))(fn, v_16468, v_16467);
    }
v_16438:
    goto v_16464;
v_16460:
    v_16468 = stack[0];
    goto v_16461;
v_16462:
    v_16467 = stack[-1];
    goto v_16463;
v_16464:
    goto v_16460;
v_16461:
    goto v_16462;
v_16463:
    {
        fn = elt(env, 2); // dipprodin
        return (*qfn2(fn))(fn, v_16468, v_16467);
    }
    v_16467 = nil;
    return onevalue(v_16467);
}



// Code for prop!-simp2

static LispObject CC_propKsimp2(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16493, v_16494;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16432,v_16433);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_16433;
    stack[-3] = v_16432;
// end of prologue
    v_16493 = stack[-2];
    if (!consp(v_16493)) goto v_16445;
    else goto v_16446;
v_16445:
    v_16493 = nil;
    goto v_16444;
v_16446:
    goto v_16455;
v_16451:
    v_16494 = stack[-2];
    goto v_16452;
v_16453:
    v_16493 = stack[-3];
    goto v_16454;
v_16455:
    goto v_16451;
v_16452:
    goto v_16453;
v_16454:
    v_16493 = Lmember(nil, v_16494, v_16493);
    goto v_16444;
    v_16493 = nil;
v_16444:
    stack[-4] = v_16493;
    if (v_16493 == nil) goto v_16442;
    goto v_16464;
v_16460:
    goto v_16470;
v_16466:
    stack[-1] = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_16467;
v_16468:
    goto v_16477;
v_16473:
    v_16493 = stack[-3];
    stack[0] = Llength(nil, v_16493);
    env = stack[-5];
    goto v_16474;
v_16475:
    v_16493 = stack[-4];
    v_16493 = Llength(nil, v_16493);
    env = stack[-5];
    goto v_16476;
v_16477:
    goto v_16473;
v_16474:
    goto v_16475;
v_16476:
    v_16493 = difference2(stack[0], v_16493);
    env = stack[-5];
    goto v_16469;
v_16470:
    goto v_16466;
v_16467:
    goto v_16468;
v_16469:
    stack[0] = Lexpt(nil, stack[-1], v_16493);
    env = stack[-5];
    goto v_16461;
v_16462:
    goto v_16487;
v_16483:
    v_16494 = stack[-2];
    goto v_16484;
v_16485:
    v_16493 = stack[-3];
    goto v_16486;
v_16487:
    goto v_16483;
v_16484:
    goto v_16485;
v_16486:
    v_16493 = Ldelete(nil, v_16494, v_16493);
    goto v_16463;
v_16464:
    goto v_16460;
v_16461:
    goto v_16462;
v_16463:
    {
        LispObject v_16500 = stack[0];
        return cons(v_16500, v_16493);
    }
v_16442:
    v_16493 = nil;
    goto v_16437;
    v_16493 = nil;
v_16437:
    return onevalue(v_16493);
}



// Code for subsq

static LispObject CC_subsq(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16503, v_16504, v_16505;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16432,v_16433);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16433;
    stack[-1] = v_16432;
// end of prologue
    goto v_16444;
v_16440:
    v_16503 = stack[-1];
    v_16504 = qcar(v_16503);
    goto v_16441;
v_16442:
    v_16503 = stack[0];
    goto v_16443;
v_16444:
    goto v_16440;
v_16441:
    goto v_16442;
v_16443:
    fn = elt(env, 5); // subf
    v_16503 = (*qfn2(fn))(fn, v_16504, v_16503);
    env = stack[-3];
    stack[-2] = v_16503;
    goto v_16453;
v_16449:
    v_16503 = stack[-1];
    v_16504 = qcdr(v_16503);
    goto v_16450;
v_16451:
    v_16503 = stack[0];
    goto v_16452;
v_16453:
    goto v_16449;
v_16450:
    goto v_16451;
v_16452:
    fn = elt(env, 5); // subf
    v_16503 = (*qfn2(fn))(fn, v_16504, v_16503);
    env = stack[-3];
    stack[-1] = v_16503;
    v_16503 = stack[-1];
    fn = elt(env, 6); // subs2!*
    v_16503 = (*qfn1(fn))(fn, v_16503);
    env = stack[-3];
    v_16503 = qcar(v_16503);
    if (v_16503 == nil) goto v_16459;
    else goto v_16460;
v_16459:
    v_16503 = stack[-2];
    fn = elt(env, 6); // subs2!*
    v_16503 = (*qfn1(fn))(fn, v_16503);
    env = stack[-3];
    v_16503 = qcar(v_16503);
    if (v_16503 == nil) goto v_16466;
    else goto v_16467;
v_16466:
    goto v_16478;
v_16472:
    v_16505 = elt(env, 2); // alg
    goto v_16473;
v_16474:
    v_16504 = (LispObject)3216+TAG_FIXNUM; // 201
    goto v_16475;
v_16476:
    v_16503 = elt(env, 3); // "0/0 formed"
    goto v_16477;
v_16478:
    goto v_16472;
v_16473:
    goto v_16474;
v_16475:
    goto v_16476;
v_16477:
    fn = elt(env, 7); // rerror
    v_16503 = (*qfnn(fn))(fn, 3, v_16505, v_16504, v_16503);
    env = stack[-3];
    goto v_16465;
v_16467:
    goto v_16491;
v_16485:
    v_16505 = elt(env, 2); // alg
    goto v_16486;
v_16487:
    v_16504 = (LispObject)3216+TAG_FIXNUM; // 201
    goto v_16488;
v_16489:
    v_16503 = elt(env, 4); // "Zero divisor"
    goto v_16490;
v_16491:
    goto v_16485;
v_16486:
    goto v_16487;
v_16488:
    goto v_16489;
v_16490:
    fn = elt(env, 7); // rerror
    v_16503 = (*qfnn(fn))(fn, 3, v_16505, v_16504, v_16503);
    env = stack[-3];
    goto v_16465;
v_16465:
    goto v_16458;
v_16460:
v_16458:
    goto v_16500;
v_16496:
    v_16504 = stack[-2];
    goto v_16497;
v_16498:
    v_16503 = stack[-1];
    goto v_16499;
v_16500:
    goto v_16496;
v_16497:
    goto v_16498;
v_16499:
    {
        fn = elt(env, 8); // quotsq
        return (*qfn2(fn))(fn, v_16504, v_16503);
    }
    return onevalue(v_16503);
}



// Code for arminusp!:

static LispObject CC_arminuspT(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16437;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16437 = v_16432;
// end of prologue
    v_16437 = qcdr(v_16437);
    {
        fn = elt(env, 1); // minusf
        return (*qfn1(fn))(fn, v_16437);
    }
}



// Code for aex_sgn

static LispObject CC_aex_sgn(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16610, v_16611;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_16432;
// end of prologue
    goto v_16446;
    goto v_16444;
v_16446:
v_16444:
    v_16610 = stack[0];
    fn = elt(env, 6); // aex_simpleratp
    v_16610 = (*qfn1(fn))(fn, v_16610);
    env = stack[-5];
    if (v_16610 == nil) goto v_16451;
    v_16610 = stack[0];
    fn = elt(env, 7); // aex_ex
    v_16610 = (*qfn1(fn))(fn, v_16610);
    env = stack[-5];
    {
        fn = elt(env, 8); // rat_sgn
        return (*qfn1(fn))(fn, v_16610);
    }
v_16451:
    v_16610 = qvalue(elt(env, 2)); // !*rlanuexsgnopt
    if (v_16610 == nil) goto v_16460;
    v_16610 = stack[0];
    fn = elt(env, 9); // aex_containment
    v_16610 = (*qfn1(fn))(fn, v_16610);
    env = stack[-5];
    stack[-2] = v_16610;
    goto v_16473;
v_16469:
    fn = elt(env, 10); // rat_0
    stack[-1] = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_16470;
v_16471:
    v_16610 = stack[-2];
    fn = elt(env, 11); // iv_lb
    v_16610 = (*qfn1(fn))(fn, v_16610);
    env = stack[-5];
    goto v_16472;
v_16473:
    goto v_16469;
v_16470:
    goto v_16471;
v_16472:
    fn = elt(env, 12); // rat_less
    v_16610 = (*qfn2(fn))(fn, stack[-1], v_16610);
    env = stack[-5];
    if (v_16610 == nil) goto v_16467;
    v_16610 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16441;
v_16467:
    goto v_16487;
v_16483:
    v_16610 = stack[-2];
    fn = elt(env, 13); // iv_rb
    stack[-1] = (*qfn1(fn))(fn, v_16610);
    env = stack[-5];
    goto v_16484;
v_16485:
    fn = elt(env, 10); // rat_0
    v_16610 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_16486;
v_16487:
    goto v_16483;
v_16484:
    goto v_16485;
v_16486:
    fn = elt(env, 12); // rat_less
    v_16610 = (*qfn2(fn))(fn, stack[-1], v_16610);
    env = stack[-5];
    if (v_16610 == nil) goto v_16481;
    v_16610 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_16441;
v_16481:
    goto v_16458;
v_16460:
v_16458:
    v_16610 = stack[0];
    fn = elt(env, 14); // aex_mvar
    v_16610 = (*qfn1(fn))(fn, v_16610);
    env = stack[-5];
    stack[-4] = v_16610;
    goto v_16499;
v_16495:
    v_16610 = stack[0];
    fn = elt(env, 15); // aex_ctx
    v_16611 = (*qfn1(fn))(fn, v_16610);
    env = stack[-5];
    goto v_16496;
v_16497:
    v_16610 = stack[-4];
    goto v_16498;
v_16499:
    goto v_16495;
v_16496:
    goto v_16497;
v_16498:
    fn = elt(env, 16); // ctx_get
    v_16610 = (*qfn2(fn))(fn, v_16611, v_16610);
    env = stack[-5];
    stack[-3] = v_16610;
    goto v_16510;
v_16506:
    v_16611 = stack[0];
    goto v_16507;
v_16508:
    v_16610 = stack[-4];
    goto v_16509;
v_16510:
    goto v_16506;
v_16507:
    goto v_16508;
v_16509:
    fn = elt(env, 17); // aex_unbind
    v_16610 = (*qfn2(fn))(fn, v_16611, v_16610);
    env = stack[-5];
    fn = elt(env, 18); // aex_reduce
    v_16610 = (*qfn1(fn))(fn, v_16610);
    env = stack[-5];
    fn = elt(env, 19); // aex_mklcnt
    v_16610 = (*qfn1(fn))(fn, v_16610);
    env = stack[-5];
    stack[-1] = v_16610;
    v_16610 = stack[-1];
    fn = elt(env, 6); // aex_simpleratp
    v_16610 = (*qfn1(fn))(fn, v_16610);
    env = stack[-5];
    if (v_16610 == nil) goto v_16516;
    v_16610 = stack[-1];
    fn = elt(env, 7); // aex_ex
    v_16610 = (*qfn1(fn))(fn, v_16610);
    env = stack[-5];
    {
        fn = elt(env, 8); // rat_sgn
        return (*qfn1(fn))(fn, v_16610);
    }
v_16516:
    v_16610 = qvalue(elt(env, 3)); // !*rlverbose
    if (v_16610 == nil) goto v_16525;
    v_16610 = qvalue(elt(env, 4)); // !*rlanuexverbose
    if (v_16610 == nil) goto v_16525;
    goto v_16539;
v_16535:
    goto v_16545;
v_16541:
    v_16611 = stack[-1];
    goto v_16542;
v_16543:
    v_16610 = stack[-4];
    goto v_16544;
v_16545:
    goto v_16541;
v_16542:
    goto v_16543;
v_16544:
    fn = elt(env, 20); // aex_deg
    v_16611 = (*qfn2(fn))(fn, v_16611, v_16610);
    env = stack[-5];
    goto v_16536;
v_16537:
    v_16610 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16538;
v_16539:
    goto v_16535;
v_16536:
    goto v_16537;
v_16538:
    v_16610 = (LispObject)lesseq2(v_16611, v_16610);
    v_16610 = v_16610 ? lisp_true : nil;
    env = stack[-5];
    if (v_16610 == nil) goto v_16533;
    v_16610 = elt(env, 5); // "[aex_sgn:num!]"
    v_16610 = Lprinc(nil, v_16610);
    env = stack[-5];
    goto v_16531;
v_16533:
v_16531:
    goto v_16523;
v_16525:
v_16523:
    v_16610 = stack[-3];
    fn = elt(env, 21); // anu_dp
    v_16610 = (*qfn1(fn))(fn, v_16610);
    env = stack[-5];
    goto v_16560;
v_16554:
    stack[0] = v_16610;
    goto v_16555;
v_16556:
    goto v_16567;
v_16563:
    goto v_16573;
v_16569:
    v_16611 = v_16610;
    goto v_16570;
v_16571:
    v_16610 = stack[-4];
    goto v_16572;
v_16573:
    goto v_16569;
v_16570:
    goto v_16571;
v_16572:
    fn = elt(env, 22); // aex_diff
    v_16611 = (*qfn2(fn))(fn, v_16611, v_16610);
    env = stack[-5];
    goto v_16564;
v_16565:
    v_16610 = stack[-1];
    goto v_16566;
v_16567:
    goto v_16563;
v_16564:
    goto v_16565;
v_16566:
    fn = elt(env, 23); // aex_mult
    v_16611 = (*qfn2(fn))(fn, v_16611, v_16610);
    env = stack[-5];
    goto v_16557;
v_16558:
    v_16610 = stack[-4];
    goto v_16559;
v_16560:
    goto v_16554;
v_16555:
    goto v_16556;
v_16557:
    goto v_16558;
v_16559:
    fn = elt(env, 24); // aex_sturmchain
    v_16610 = (*qfnn(fn))(fn, 3, stack[0], v_16611, v_16610);
    env = stack[-5];
    stack[-2] = v_16610;
    goto v_16583;
v_16579:
    goto v_16591;
v_16585:
    stack[-1] = stack[-2];
    goto v_16586;
v_16587:
    stack[0] = stack[-4];
    goto v_16588;
v_16589:
    v_16610 = stack[-3];
    fn = elt(env, 25); // anu_iv
    v_16610 = (*qfn1(fn))(fn, v_16610);
    env = stack[-5];
    fn = elt(env, 11); // iv_lb
    v_16610 = (*qfn1(fn))(fn, v_16610);
    env = stack[-5];
    goto v_16590;
v_16591:
    goto v_16585;
v_16586:
    goto v_16587;
v_16588:
    goto v_16589;
v_16590:
    fn = elt(env, 26); // aex_stchsgnch1
    stack[0] = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_16610);
    env = stack[-5];
    goto v_16580;
v_16581:
    goto v_16604;
v_16598:
    stack[-1] = stack[-2];
    goto v_16599;
v_16600:
    stack[-2] = stack[-4];
    goto v_16601;
v_16602:
    v_16610 = stack[-3];
    fn = elt(env, 25); // anu_iv
    v_16610 = (*qfn1(fn))(fn, v_16610);
    env = stack[-5];
    fn = elt(env, 13); // iv_rb
    v_16610 = (*qfn1(fn))(fn, v_16610);
    env = stack[-5];
    goto v_16603;
v_16604:
    goto v_16598;
v_16599:
    goto v_16600;
v_16601:
    goto v_16602;
v_16603:
    fn = elt(env, 26); // aex_stchsgnch1
    v_16610 = (*qfnn(fn))(fn, 3, stack[-1], stack[-2], v_16610);
    goto v_16582;
v_16583:
    goto v_16579;
v_16580:
    goto v_16581;
v_16582:
    {
        LispObject v_16617 = stack[0];
        return difference2(v_16617, v_16610);
    }
v_16441:
    return onevalue(v_16610);
}



// Code for open

static LispObject CC_open(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16512, v_16513, v_16514, v_16515;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16432,v_16433);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_16514 = v_16433;
    v_16515 = v_16432;
// end of prologue
    goto v_16443;
v_16439:
    v_16513 = v_16514;
    goto v_16440;
v_16441:
    v_16512 = elt(env, 1); // input
    goto v_16442;
v_16443:
    goto v_16439;
v_16440:
    goto v_16441;
v_16442:
    if (v_16513 == v_16512) goto v_16437;
    else goto v_16438;
v_16437:
    goto v_16451;
v_16447:
    v_16513 = v_16515;
    goto v_16448;
v_16449:
    v_16512 = (LispObject)1040+TAG_FIXNUM; // 65
    goto v_16450;
v_16451:
    goto v_16447;
v_16448:
    goto v_16449;
v_16450:
    {
        fn = elt(env, 5); // internal!-open
        return (*qfn2(fn))(fn, v_16513, v_16512);
    }
v_16438:
    goto v_16460;
v_16456:
    v_16513 = v_16514;
    goto v_16457;
v_16458:
    v_16512 = elt(env, 2); // output
    goto v_16459;
v_16460:
    goto v_16456;
v_16457:
    goto v_16458;
v_16459:
    if (v_16513 == v_16512) goto v_16454;
    else goto v_16455;
v_16454:
    goto v_16468;
v_16464:
    stack[0] = v_16515;
    goto v_16465;
v_16466:
    goto v_16475;
v_16471:
    v_16513 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_16472;
v_16473:
    v_16512 = (LispObject)832+TAG_FIXNUM; // 52
    goto v_16474;
v_16475:
    goto v_16471;
v_16472:
    goto v_16473;
v_16474:
    v_16512 = plus2(v_16513, v_16512);
    env = stack[-1];
    goto v_16467;
v_16468:
    goto v_16464;
v_16465:
    goto v_16466;
v_16467:
    {
        LispObject v_16517 = stack[0];
        fn = elt(env, 5); // internal!-open
        return (*qfn2(fn))(fn, v_16517, v_16512);
    }
v_16455:
    goto v_16484;
v_16480:
    v_16513 = v_16514;
    goto v_16481;
v_16482:
    v_16512 = elt(env, 3); // append
    goto v_16483;
v_16484:
    goto v_16480;
v_16481:
    goto v_16482;
v_16483:
    if (v_16513 == v_16512) goto v_16478;
    else goto v_16479;
v_16478:
    goto v_16492;
v_16488:
    stack[0] = v_16515;
    goto v_16489;
v_16490:
    goto v_16499;
v_16495:
    v_16513 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_16496;
v_16497:
    v_16512 = (LispObject)640+TAG_FIXNUM; // 40
    goto v_16498;
v_16499:
    goto v_16495;
v_16496:
    goto v_16497;
v_16498:
    v_16512 = plus2(v_16513, v_16512);
    env = stack[-1];
    goto v_16491;
v_16492:
    goto v_16488;
v_16489:
    goto v_16490;
v_16491:
    {
        LispObject v_16518 = stack[0];
        fn = elt(env, 5); // internal!-open
        return (*qfn2(fn))(fn, v_16518, v_16512);
    }
v_16479:
    goto v_16509;
v_16505:
    v_16512 = elt(env, 4); // "bad direction ~A in open"
    goto v_16506;
v_16507:
    v_16513 = v_16514;
    goto v_16508;
v_16509:
    goto v_16505;
v_16506:
    goto v_16507;
v_16508:
    {
        fn = elt(env, 6); // error
        return (*qfn2(fn))(fn, v_16512, v_16513);
    }
    v_16512 = nil;
    return onevalue(v_16512);
}



// Code for ofsf_smordtable

static LispObject CC_ofsf_smordtable(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16456, v_16457, v_16458;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16456 = v_16433;
    v_16457 = v_16432;
// end of prologue
    v_16458 = elt(env, 2); // ((equal (equal . false) (neq equal . t) (geq equal . t) (leq . false) (greaterp equal . t) (lessp . false)) (neq (equal equal)
// (neq) (geq) (leq leq) (greaterp) (lessp lessp)) (geq (equal . false) (neq geq . t) (geq geq . t) (leq . false) (greaterp
// geq . t) (lessp . false)) (leq (equal equal) (neq) (geq) (leq leq) (greaterp) (lessp lessp)) (greaterp (equal . false) (neq
// greaterp . t) (geq greaterp . t) (leq . false) (greaterp greaterp . t) (lessp . false)) (lessp (equal equal) (neq) (geq)
// (leq leq) (greaterp) (lessp lessp)))
    goto v_16444;
v_16440:
    goto v_16441;
v_16442:
    goto v_16450;
v_16446:
    goto v_16447;
v_16448:
    goto v_16449;
v_16450:
    goto v_16446;
v_16447:
    goto v_16448;
v_16449:
    v_16457 = Latsoc(nil, v_16457, v_16458);
    goto v_16443;
v_16444:
    goto v_16440;
v_16441:
    goto v_16442;
v_16443:
    v_16456 = Latsoc(nil, v_16456, v_16457);
    v_16456 = qcdr(v_16456);
    return onevalue(v_16456);
}



// Code for checku

static LispObject CC_checku(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16469, v_16470, v_16471, v_16472;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16470 = v_16433;
    v_16471 = v_16432;
// end of prologue
v_16431:
    v_16469 = v_16471;
    if (v_16469 == nil) goto v_16437;
    else goto v_16438;
v_16437:
    v_16469 = nil;
    goto v_16436;
v_16438:
    goto v_16451;
v_16447:
    v_16469 = v_16470;
    v_16472 = qcar(v_16469);
    goto v_16448;
v_16449:
    v_16469 = v_16471;
    v_16469 = qcar(v_16469);
    v_16469 = qcar(v_16469);
    goto v_16450;
v_16451:
    goto v_16447;
v_16448:
    goto v_16449;
v_16450:
    if (equal(v_16472, v_16469)) goto v_16445;
    else goto v_16446;
v_16445:
    v_16469 = lisp_true;
    goto v_16444;
v_16446:
    goto v_16465;
v_16461:
    v_16469 = v_16471;
    v_16471 = qcdr(v_16469);
    goto v_16462;
v_16463:
    v_16469 = v_16470;
    goto v_16464;
v_16465:
    goto v_16461;
v_16462:
    goto v_16463;
v_16464:
    v_16470 = v_16469;
    goto v_16431;
    v_16469 = nil;
v_16444:
    goto v_16436;
    v_16469 = nil;
v_16436:
    return onevalue(v_16469);
}



// Code for cl_nnfnot

static LispObject CC_cl_nnfnot(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16442, v_16443;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16442 = v_16432;
// end of prologue
    goto v_16439;
v_16435:
    v_16443 = v_16442;
    goto v_16436;
v_16437:
    v_16442 = nil;
    goto v_16438;
v_16439:
    goto v_16435;
v_16436:
    goto v_16437;
v_16438:
    {
        fn = elt(env, 1); // cl_nnf1
        return (*qfn2(fn))(fn, v_16443, v_16442);
    }
}



// Code for qqe_eta!-in!-term1

static LispObject CC_qqe_etaKinKterm1(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16466, v_16467;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_16432;
// end of prologue
    v_16466 = stack[0];
    v_16466 = qcdr(v_16466);
    v_16466 = qcar(v_16466);
    fn = elt(env, 3); // qqe_simplterm
    v_16466 = (*qfn1(fn))(fn, v_16466);
    env = stack[-2];
    stack[-1] = v_16466;
    goto v_16447;
v_16443:
    v_16466 = stack[0];
    fn = elt(env, 4); // qqe_op
    v_16467 = (*qfn1(fn))(fn, v_16466);
    env = stack[-2];
    goto v_16444;
v_16445:
    v_16466 = stack[-1];
    goto v_16446;
v_16447:
    goto v_16443;
v_16444:
    goto v_16445;
v_16446:
    v_16466 = cons(v_16467, v_16466);
    env = stack[-2];
    goto v_16459;
v_16455:
    v_16466 = stack[-1];
    goto v_16456;
v_16457:
    v_16467 = elt(env, 2); // qepsilon
    goto v_16458;
v_16459:
    goto v_16455;
v_16456:
    goto v_16457;
v_16458:
    if (v_16466 == v_16467) goto v_16453;
    else goto v_16454;
v_16453:
    v_16466 = lisp_true;
    goto v_16436;
v_16454:
    v_16466 = nil;
    goto v_16436;
    v_16466 = nil;
v_16436:
    return onevalue(v_16466);
}



// Code for cl_susiupdknowl2

static LispObject CC_cl_susiupdknowl2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16588, v_16589, v_16590;
    LispObject fn;
    LispObject v_16434, v_16433, v_16432;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cl_susiupdknowl2");
    va_start(aa, nargs);
    v_16432 = va_arg(aa, LispObject);
    v_16433 = va_arg(aa, LispObject);
    v_16434 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_16434,v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_16432,v_16433,v_16434);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_16434;
    stack[-5] = v_16433;
    stack[-6] = v_16432;
// end of prologue
    stack[-3] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    v_16588 = stack[-5];
    stack[-2] = v_16588;
v_16449:
    v_16588 = stack[-2];
    if (v_16588 == nil) goto v_16452;
    else goto v_16453;
v_16452:
    goto v_16448;
v_16453:
    v_16588 = stack[-2];
    v_16588 = qcar(v_16588);
    stack[-7] = v_16588;
    v_16588 = stack[-2];
    v_16588 = qcdr(v_16588);
    stack[-2] = v_16588;
    goto v_16465;
v_16461:
    v_16589 = stack[-7];
    goto v_16462;
v_16463:
    v_16588 = stack[-6];
    goto v_16464;
v_16465:
    goto v_16461;
v_16462:
    goto v_16463;
v_16464:
    fn = elt(env, 3); // rl_susibin
    v_16588 = (*qfn2(fn))(fn, v_16589, v_16588);
    env = stack[-8];
    stack[-3] = v_16588;
    goto v_16476;
v_16472:
    v_16589 = stack[-3];
    goto v_16473;
v_16474:
    v_16588 = elt(env, 2); // false
    goto v_16475;
v_16476:
    goto v_16472;
v_16473:
    goto v_16474;
v_16475:
    if (v_16589 == v_16588) goto v_16470;
    else goto v_16471;
v_16470:
    v_16588 = nil;
    stack[-2] = v_16588;
    goto v_16469;
v_16471:
    goto v_16489;
v_16483:
    v_16590 = stack[-3];
    goto v_16484;
v_16485:
    v_16589 = stack[-5];
    goto v_16486;
v_16487:
    v_16588 = stack[-7];
    goto v_16488;
v_16489:
    goto v_16483;
v_16484:
    goto v_16485;
v_16486:
    goto v_16487;
v_16488:
    fn = elt(env, 4); // cl_susiinter
    v_16588 = (*qfnn(fn))(fn, 3, v_16590, v_16589, v_16588);
    env = stack[-8];
    stack[-3] = v_16588;
    goto v_16498;
v_16494:
    v_16589 = stack[0];
    goto v_16495;
v_16496:
    v_16588 = stack[-3];
    v_16588 = qcdr(v_16588);
    v_16588 = qcar(v_16588);
    goto v_16497;
v_16498:
    goto v_16494;
v_16495:
    goto v_16496;
v_16497:
    v_16588 = Lnconc(nil, v_16589, v_16588);
    env = stack[-8];
    stack[0] = v_16588;
    v_16588 = stack[-3];
    v_16588 = qcar(v_16588);
    stack[-5] = v_16588;
    v_16588 = stack[-3];
    v_16588 = qcdr(v_16588);
    v_16588 = qcdr(v_16588);
    v_16588 = qcar(v_16588);
    if (v_16588 == nil) goto v_16508;
    goto v_16506;
v_16508:
v_16506:
    v_16588 = stack[-3];
    v_16588 = qcdr(v_16588);
    v_16588 = qcdr(v_16588);
    v_16588 = qcdr(v_16588);
    v_16588 = qcar(v_16588);
    if (v_16588 == nil) goto v_16517;
    v_16588 = lisp_true;
    stack[-1] = v_16588;
    v_16588 = nil;
    stack[-2] = v_16588;
    goto v_16515;
v_16517:
v_16515:
    goto v_16469;
v_16469:
    goto v_16449;
v_16448:
    goto v_16533;
v_16529:
    v_16589 = stack[-3];
    goto v_16530;
v_16531:
    v_16588 = elt(env, 2); // false
    goto v_16532;
v_16533:
    goto v_16529;
v_16530:
    goto v_16531;
v_16532:
    if (v_16589 == v_16588) goto v_16527;
    else goto v_16528;
v_16527:
    v_16588 = elt(env, 2); // false
    goto v_16444;
v_16528:
    v_16588 = stack[-1];
    if (v_16588 == nil) goto v_16539;
    else goto v_16540;
v_16539:
    goto v_16547;
v_16543:
    v_16589 = stack[-6];
    goto v_16544;
v_16545:
    v_16588 = stack[-5];
    goto v_16546;
v_16547:
    goto v_16543;
v_16544:
    goto v_16545;
v_16546:
    v_16588 = cons(v_16589, v_16588);
    env = stack[-8];
    stack[-5] = v_16588;
    goto v_16538;
v_16540:
v_16538:
v_16552:
    v_16588 = stack[0];
    if (v_16588 == nil) goto v_16555;
    else goto v_16556;
v_16555:
    goto v_16551;
v_16556:
    goto v_16566;
v_16560:
    v_16588 = stack[0];
    v_16590 = qcar(v_16588);
    goto v_16561;
v_16562:
    v_16589 = stack[-5];
    goto v_16563;
v_16564:
    v_16588 = stack[-4];
    goto v_16565;
v_16566:
    goto v_16560;
v_16561:
    goto v_16562;
v_16563:
    goto v_16564;
v_16565:
    v_16588 = CC_cl_susiupdknowl2(elt(env, 0), 3, v_16590, v_16589, v_16588);
    env = stack[-8];
    stack[-5] = v_16588;
    goto v_16579;
v_16575:
    v_16589 = stack[-5];
    goto v_16576;
v_16577:
    v_16588 = elt(env, 2); // false
    goto v_16578;
v_16579:
    goto v_16575;
v_16576:
    goto v_16577;
v_16578:
    if (v_16589 == v_16588) goto v_16573;
    else goto v_16574;
v_16573:
    v_16588 = nil;
    stack[0] = v_16588;
    goto v_16572;
v_16574:
    v_16588 = stack[0];
    v_16588 = qcdr(v_16588);
    stack[0] = v_16588;
    goto v_16572;
v_16572:
    goto v_16552;
v_16551:
    v_16588 = stack[-5];
v_16444:
    return onevalue(v_16588);
}



// Code for ofsf_xor

static LispObject CC_ofsf_xor(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16456, v_16457, v_16458;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16456 = v_16433;
    v_16457 = v_16432;
// end of prologue
    v_16458 = v_16457;
    if (v_16458 == nil) goto v_16439;
    else goto v_16438;
v_16439:
    v_16458 = v_16456;
    if (v_16458 == nil) goto v_16441;
    else goto v_16438;
v_16441:
    v_16456 = nil;
    goto v_16436;
v_16438:
    if (v_16457 == nil) goto v_16448;
    else goto v_16449;
v_16448:
    v_16456 = nil;
    goto v_16447;
v_16449:
    goto v_16447;
    v_16456 = nil;
v_16447:
    v_16456 = (v_16456 == nil ? lisp_true : nil);
    goto v_16436;
    v_16456 = nil;
v_16436:
    return onevalue(v_16456);
}



// Code for dvfsf_0mk2

static LispObject CC_dvfsf_0mk2(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16446, v_16447, v_16448;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16446 = v_16433;
    v_16447 = v_16432;
// end of prologue
    goto v_16442;
v_16436:
    v_16448 = v_16447;
    goto v_16437;
v_16438:
    v_16447 = v_16446;
    goto v_16439;
v_16440:
    v_16446 = nil;
    goto v_16441;
v_16442:
    goto v_16436;
v_16437:
    goto v_16438;
v_16439:
    goto v_16440;
v_16441:
    return list3(v_16448, v_16447, v_16446);
}



// Code for sfto_b!:extmult

static LispObject CC_sfto_bTextmult(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16578, v_16579;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16432,v_16433);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_16433;
    stack[-3] = v_16432;
// end of prologue
    v_16578 = stack[-3];
    if (v_16578 == nil) goto v_16441;
    else goto v_16442;
v_16441:
    v_16578 = lisp_true;
    goto v_16440;
v_16442:
    v_16578 = stack[-2];
    v_16578 = (v_16578 == nil ? lisp_true : nil);
    goto v_16440;
    v_16578 = nil;
v_16440:
    if (v_16578 == nil) goto v_16438;
    v_16578 = nil;
    goto v_16436;
v_16438:
    goto v_16456;
v_16452:
    v_16579 = stack[-2];
    goto v_16453;
v_16454:
    v_16578 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16455;
v_16456:
    goto v_16452;
v_16453:
    goto v_16454;
v_16455:
    if (v_16579 == v_16578) goto v_16450;
    else goto v_16451;
v_16450:
    v_16578 = stack[-3];
    goto v_16436;
v_16451:
    goto v_16467;
v_16463:
    v_16578 = stack[-3];
    v_16578 = qcar(v_16578);
    v_16578 = qcar(v_16578);
    v_16579 = qcar(v_16578);
    goto v_16464;
v_16465:
    v_16578 = stack[-2];
    v_16578 = qcar(v_16578);
    v_16578 = qcar(v_16578);
    goto v_16466;
v_16467:
    goto v_16463;
v_16464:
    goto v_16465;
v_16466:
    fn = elt(env, 1); // sfto_b!:ordexn
    v_16578 = (*qfn2(fn))(fn, v_16579, v_16578);
    env = stack[-5];
    v_16579 = v_16578;
    v_16578 = v_16579;
    if (v_16578 == nil) goto v_16479;
    goto v_16488;
v_16482:
    v_16578 = v_16579;
    stack[-4] = qcdr(v_16578);
    goto v_16483;
v_16484:
    v_16578 = v_16579;
    v_16578 = qcar(v_16578);
    if (v_16578 == nil) goto v_16494;
    goto v_16503;
v_16499:
    v_16578 = stack[-3];
    v_16578 = qcar(v_16578);
    v_16579 = qcdr(v_16578);
    goto v_16500;
v_16501:
    v_16578 = stack[-2];
    v_16578 = qcar(v_16578);
    v_16578 = qcdr(v_16578);
    goto v_16502;
v_16503:
    goto v_16499;
v_16500:
    goto v_16501;
v_16502:
    fn = elt(env, 2); // multf
    v_16578 = (*qfn2(fn))(fn, v_16579, v_16578);
    env = stack[-5];
    fn = elt(env, 3); // negf
    v_16578 = (*qfn1(fn))(fn, v_16578);
    env = stack[-5];
    stack[-1] = v_16578;
    goto v_16492;
v_16494:
    goto v_16517;
v_16513:
    v_16578 = stack[-3];
    v_16578 = qcar(v_16578);
    v_16579 = qcdr(v_16578);
    goto v_16514;
v_16515:
    v_16578 = stack[-2];
    v_16578 = qcar(v_16578);
    v_16578 = qcdr(v_16578);
    goto v_16516;
v_16517:
    goto v_16513;
v_16514:
    goto v_16515;
v_16516:
    fn = elt(env, 2); // multf
    v_16578 = (*qfn2(fn))(fn, v_16579, v_16578);
    env = stack[-5];
    stack[-1] = v_16578;
    goto v_16492;
    stack[-1] = nil;
v_16492:
    goto v_16485;
v_16486:
    goto v_16529;
v_16525:
    goto v_16535;
v_16531:
    v_16578 = stack[-3];
    v_16578 = qcar(v_16578);
    v_16579 = ncons(v_16578);
    env = stack[-5];
    goto v_16532;
v_16533:
    v_16578 = stack[-2];
    v_16578 = qcdr(v_16578);
    goto v_16534;
v_16535:
    goto v_16531;
v_16532:
    goto v_16533;
v_16534:
    stack[0] = CC_sfto_bTextmult(elt(env, 0), v_16579, v_16578);
    env = stack[-5];
    goto v_16526;
v_16527:
    goto v_16546;
v_16542:
    v_16578 = stack[-3];
    v_16579 = qcdr(v_16578);
    goto v_16543;
v_16544:
    v_16578 = stack[-2];
    goto v_16545;
v_16546:
    goto v_16542;
v_16543:
    goto v_16544;
v_16545:
    v_16578 = CC_sfto_bTextmult(elt(env, 0), v_16579, v_16578);
    env = stack[-5];
    goto v_16528;
v_16529:
    goto v_16525;
v_16526:
    goto v_16527;
v_16528:
    fn = elt(env, 4); // sfto_b!:extadd
    v_16578 = (*qfn2(fn))(fn, stack[0], v_16578);
    goto v_16487;
v_16488:
    goto v_16482;
v_16483:
    goto v_16484;
v_16485:
    goto v_16486;
v_16487:
    {
        LispObject v_16585 = stack[-4];
        LispObject v_16586 = stack[-1];
        return acons(v_16585, v_16586, v_16578);
    }
v_16479:
    goto v_16557;
v_16553:
    goto v_16563;
v_16559:
    v_16578 = stack[-3];
    v_16579 = qcdr(v_16578);
    goto v_16560;
v_16561:
    v_16578 = stack[-2];
    goto v_16562;
v_16563:
    goto v_16559;
v_16560:
    goto v_16561;
v_16562:
    stack[0] = CC_sfto_bTextmult(elt(env, 0), v_16579, v_16578);
    env = stack[-5];
    goto v_16554;
v_16555:
    goto v_16572;
v_16568:
    v_16578 = stack[-3];
    v_16578 = qcar(v_16578);
    v_16579 = ncons(v_16578);
    env = stack[-5];
    goto v_16569;
v_16570:
    v_16578 = stack[-2];
    v_16578 = qcdr(v_16578);
    goto v_16571;
v_16572:
    goto v_16568;
v_16569:
    goto v_16570;
v_16571:
    v_16578 = CC_sfto_bTextmult(elt(env, 0), v_16579, v_16578);
    env = stack[-5];
    goto v_16556;
v_16557:
    goto v_16553;
v_16554:
    goto v_16555;
v_16556:
    {
        LispObject v_16587 = stack[0];
        fn = elt(env, 4); // sfto_b!:extadd
        return (*qfn2(fn))(fn, v_16587, v_16578);
    }
    v_16578 = nil;
    goto v_16436;
    v_16578 = nil;
v_16436:
    return onevalue(v_16578);
}



// Code for lambdaom

static LispObject CC_lambdaom(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16470, v_16471;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_16471 = v_16432;
// end of prologue
    v_16470 = v_16471;
    v_16470 = qcdr(v_16470);
    v_16470 = qcdr(v_16470);
    v_16470 = qcar(v_16470);
    v_16470 = qcdr(v_16470);
    v_16470 = qcar(v_16470);
    stack[-1] = v_16470;
    v_16470 = v_16471;
    v_16470 = Lreverse(nil, v_16470);
    env = stack[-2];
    v_16470 = qcar(v_16470);
    stack[0] = v_16470;
    v_16470 = elt(env, 2); // "<OMBIND>"
    fn = elt(env, 7); // printout
    v_16470 = (*qfn1(fn))(fn, v_16470);
    env = stack[-2];
    v_16470 = lisp_true;
    fn = elt(env, 8); // indent!*
    v_16470 = (*qfn1(fn))(fn, v_16470);
    env = stack[-2];
    v_16470 = elt(env, 3); // "<OMS cd=""fns1"" name=""lambda""/>"
    fn = elt(env, 7); // printout
    v_16470 = (*qfn1(fn))(fn, v_16470);
    env = stack[-2];
    v_16470 = elt(env, 4); // "<OMBVAR>"
    fn = elt(env, 7); // printout
    v_16470 = (*qfn1(fn))(fn, v_16470);
    env = stack[-2];
    v_16470 = lisp_true;
    fn = elt(env, 8); // indent!*
    v_16470 = (*qfn1(fn))(fn, v_16470);
    env = stack[-2];
    v_16470 = stack[-1];
    fn = elt(env, 9); // objectom
    v_16470 = (*qfn1(fn))(fn, v_16470);
    env = stack[-2];
    v_16470 = nil;
    fn = elt(env, 8); // indent!*
    v_16470 = (*qfn1(fn))(fn, v_16470);
    env = stack[-2];
    v_16470 = elt(env, 5); // "</OMBVAR>"
    fn = elt(env, 7); // printout
    v_16470 = (*qfn1(fn))(fn, v_16470);
    env = stack[-2];
    v_16470 = stack[0];
    fn = elt(env, 9); // objectom
    v_16470 = (*qfn1(fn))(fn, v_16470);
    env = stack[-2];
    v_16470 = nil;
    fn = elt(env, 8); // indent!*
    v_16470 = (*qfn1(fn))(fn, v_16470);
    env = stack[-2];
    v_16470 = elt(env, 6); // "</OMBIND>"
    fn = elt(env, 7); // printout
    v_16470 = (*qfn1(fn))(fn, v_16470);
    v_16470 = nil;
    return onevalue(v_16470);
}



// Code for vdpcondense

static LispObject CC_vdpcondense(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16440;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16440 = v_16432;
// end of prologue
    v_16440 = qcdr(v_16440);
    v_16440 = qcdr(v_16440);
    v_16440 = qcdr(v_16440);
    v_16440 = qcar(v_16440);
    {
        fn = elt(env, 1); // dipcondense
        return (*qfn1(fn))(fn, v_16440);
    }
}



// Code for all_defined_vertex

static LispObject CC_all_defined_vertex(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16449, v_16450, v_16451, v_16452;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16449 = v_16433;
    v_16450 = v_16432;
// end of prologue
    goto v_16444;
v_16436:
    v_16452 = v_16450;
    goto v_16437;
v_16438:
    v_16451 = nil;
    goto v_16439;
v_16440:
    v_16450 = nil;
    goto v_16441;
v_16442:
    goto v_16443;
v_16444:
    goto v_16436;
v_16437:
    goto v_16438;
v_16439:
    goto v_16440;
v_16441:
    goto v_16442;
v_16443:
    {
        fn = elt(env, 1); // al1_defined_vertex
        return (*qfnn(fn))(fn, 4, v_16452, v_16451, v_16450, v_16449);
    }
}



// Code for repartsq

static LispObject CC_repartsq(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16505, v_16506, v_16507, v_16508;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_16432;
// end of prologue
    v_16505 = stack[0];
    v_16505 = qcar(v_16505);
    fn = elt(env, 1); // splitcomplex
    stack[-1] = (*qfn1(fn))(fn, v_16505);
    env = stack[-4];
    v_16505 = stack[0];
    v_16505 = qcdr(v_16505);
    fn = elt(env, 1); // splitcomplex
    v_16505 = (*qfn1(fn))(fn, v_16505);
    env = stack[-4];
    v_16507 = stack[-1];
    v_16506 = v_16505;
    v_16505 = v_16507;
    v_16505 = qcar(v_16505);
    v_16508 = qcdr(v_16507);
    v_16507 = v_16506;
    v_16507 = qcar(v_16507);
    v_16506 = qcdr(v_16506);
    stack[-3] = v_16508;
    stack[-2] = v_16507;
    stack[-1] = v_16506;
    goto v_16459;
v_16455:
    goto v_16465;
v_16461:
    goto v_16471;
v_16467:
    v_16506 = v_16505;
    goto v_16468;
v_16469:
    v_16505 = stack[-2];
    goto v_16470;
v_16471:
    goto v_16467;
v_16468:
    goto v_16469;
v_16470:
    fn = elt(env, 2); // multsq
    stack[0] = (*qfn2(fn))(fn, v_16506, v_16505);
    env = stack[-4];
    goto v_16462;
v_16463:
    goto v_16479;
v_16475:
    v_16506 = stack[-3];
    goto v_16476;
v_16477:
    v_16505 = stack[-1];
    goto v_16478;
v_16479:
    goto v_16475;
v_16476:
    goto v_16477;
v_16478:
    fn = elt(env, 2); // multsq
    v_16505 = (*qfn2(fn))(fn, v_16506, v_16505);
    env = stack[-4];
    goto v_16464;
v_16465:
    goto v_16461;
v_16462:
    goto v_16463;
v_16464:
    fn = elt(env, 3); // addsq
    stack[0] = (*qfn2(fn))(fn, stack[0], v_16505);
    env = stack[-4];
    goto v_16456;
v_16457:
    goto v_16488;
v_16484:
    goto v_16494;
v_16490:
    v_16506 = stack[-2];
    goto v_16491;
v_16492:
    v_16505 = stack[-2];
    goto v_16493;
v_16494:
    goto v_16490;
v_16491:
    goto v_16492;
v_16493:
    fn = elt(env, 2); // multsq
    stack[-2] = (*qfn2(fn))(fn, v_16506, v_16505);
    env = stack[-4];
    goto v_16485;
v_16486:
    goto v_16502;
v_16498:
    v_16506 = stack[-1];
    goto v_16499;
v_16500:
    v_16505 = stack[-1];
    goto v_16501;
v_16502:
    goto v_16498;
v_16499:
    goto v_16500;
v_16501:
    fn = elt(env, 2); // multsq
    v_16505 = (*qfn2(fn))(fn, v_16506, v_16505);
    env = stack[-4];
    goto v_16487;
v_16488:
    goto v_16484;
v_16485:
    goto v_16486;
v_16487:
    fn = elt(env, 3); // addsq
    v_16505 = (*qfn2(fn))(fn, stack[-2], v_16505);
    env = stack[-4];
    fn = elt(env, 4); // invsq
    v_16505 = (*qfn1(fn))(fn, v_16505);
    env = stack[-4];
    goto v_16458;
v_16459:
    goto v_16455;
v_16456:
    goto v_16457;
v_16458:
    {
        LispObject v_16513 = stack[0];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_16513, v_16505);
    }
}



// Code for red_topred

static LispObject CC_red_topred(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16518, v_16519;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16432,v_16433);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16433;
    stack[-1] = v_16432;
// end of prologue
    v_16518 = stack[0];
    fn = elt(env, 3); // bas_dpoly
    v_16518 = (*qfn1(fn))(fn, v_16518);
    env = stack[-3];
    if (v_16518 == nil) goto v_16441;
    else goto v_16442;
v_16441:
    v_16518 = lisp_true;
    goto v_16440;
v_16442:
    v_16518 = stack[-1];
    v_16518 = (v_16518 == nil ? lisp_true : nil);
    goto v_16440;
    v_16518 = nil;
v_16440:
    if (v_16518 == nil) goto v_16438;
    v_16518 = stack[0];
    goto v_16436;
v_16438:
    goto v_16463;
v_16459:
    v_16519 = stack[-1];
    goto v_16460;
v_16461:
    v_16518 = stack[0];
    goto v_16462;
v_16463:
    goto v_16459;
v_16460:
    goto v_16461;
v_16462:
    fn = elt(env, 4); // red_topredbe
    v_16518 = (*qfn2(fn))(fn, v_16519, v_16518);
    env = stack[-3];
    stack[0] = v_16518;
v_16468:
    v_16518 = stack[0];
    fn = elt(env, 3); // bas_dpoly
    v_16518 = (*qfn1(fn))(fn, v_16518);
    env = stack[-3];
    v_16519 = v_16518;
    if (v_16518 == nil) goto v_16471;
    goto v_16482;
v_16478:
    stack[-2] = stack[-1];
    goto v_16479;
v_16480:
    v_16518 = v_16519;
    fn = elt(env, 5); // dp_lmon
    v_16518 = (*qfn1(fn))(fn, v_16518);
    env = stack[-3];
    goto v_16481;
v_16482:
    goto v_16478;
v_16479:
    goto v_16480;
v_16481:
    fn = elt(env, 6); // red_divtest
    v_16518 = (*qfn2(fn))(fn, stack[-2], v_16518);
    env = stack[-3];
    stack[-2] = v_16518;
    if (v_16518 == nil) goto v_16471;
    goto v_16472;
v_16471:
    goto v_16467;
v_16472:
    goto v_16492;
v_16488:
    v_16519 = stack[0];
    goto v_16489;
v_16490:
    v_16518 = stack[-2];
    goto v_16491;
v_16492:
    goto v_16488;
v_16489:
    goto v_16490;
v_16491:
    fn = elt(env, 7); // red_subst
    v_16518 = (*qfn2(fn))(fn, v_16519, v_16518);
    env = stack[-3];
    stack[-2] = v_16518;
    v_16518 = qvalue(elt(env, 2)); // !*noetherian
    if (v_16518 == nil) goto v_16497;
    else goto v_16498;
v_16497:
    goto v_16505;
v_16501:
    v_16519 = stack[-1];
    goto v_16502;
v_16503:
    v_16518 = stack[0];
    goto v_16504;
v_16505:
    goto v_16501;
v_16502:
    goto v_16503;
v_16504:
    fn = elt(env, 8); // red_update
    v_16518 = (*qfn2(fn))(fn, v_16519, v_16518);
    env = stack[-3];
    stack[-1] = v_16518;
    goto v_16496;
v_16498:
v_16496:
    goto v_16513;
v_16509:
    v_16519 = stack[-1];
    goto v_16510;
v_16511:
    v_16518 = stack[-2];
    goto v_16512;
v_16513:
    goto v_16509;
v_16510:
    goto v_16511;
v_16512:
    fn = elt(env, 4); // red_topredbe
    v_16518 = (*qfn2(fn))(fn, v_16519, v_16518);
    env = stack[-3];
    stack[0] = v_16518;
    goto v_16468;
v_16467:
    v_16518 = stack[0];
    goto v_16436;
    v_16518 = nil;
v_16436:
    return onevalue(v_16518);
}



// Code for dfconst

static LispObject CC_dfconst(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16453, v_16454;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_16432;
// end of prologue
    v_16453 = stack[0];
    v_16453 = qcar(v_16453);
    if (v_16453 == nil) goto v_16436;
    else goto v_16437;
v_16436:
    v_16453 = nil;
    goto v_16435;
v_16437:
    goto v_16449;
v_16445:
    v_16453 = qvalue(elt(env, 1)); // zlist
    fn = elt(env, 2); // vp2
    v_16454 = (*qfn1(fn))(fn, v_16453);
    env = stack[-1];
    goto v_16446;
v_16447:
    v_16453 = stack[0];
    goto v_16448;
v_16449:
    goto v_16445;
v_16446:
    goto v_16447;
v_16448:
    v_16453 = cons(v_16454, v_16453);
    return ncons(v_16453);
    v_16453 = nil;
v_16435:
    return onevalue(v_16453);
}



// Code for qqe_simplterm!-tail

static LispObject CC_qqe_simpltermKtail(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16571, v_16572, v_16573;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_16432;
// end of prologue
    v_16571 = stack[-2];
    fn = elt(env, 8); // qqe_arg2l
    v_16571 = (*qfn1(fn))(fn, v_16571);
    env = stack[-4];
    stack[-3] = v_16571;
    goto v_16452;
v_16448:
    v_16572 = stack[-3];
    goto v_16449;
v_16450:
    v_16571 = elt(env, 2); // qepsilon
    goto v_16451;
v_16452:
    goto v_16448;
v_16449:
    goto v_16450;
v_16451:
    if (v_16572 == v_16571) goto v_16446;
    else goto v_16447;
v_16446:
    v_16571 = elt(env, 2); // qepsilon
    goto v_16440;
v_16447:
    v_16571 = stack[-3];
    if (!consp(v_16571)) goto v_16458;
    else goto v_16459;
v_16458:
    v_16571 = stack[-2];
    goto v_16440;
v_16459:
    v_16571 = stack[-2];
    fn = elt(env, 9); // qqe_op
    v_16571 = (*qfn1(fn))(fn, v_16571);
    env = stack[-4];
    stack[-1] = v_16571;
    v_16571 = stack[-3];
    fn = elt(env, 9); // qqe_op
    v_16571 = (*qfn1(fn))(fn, v_16571);
    env = stack[-4];
    stack[0] = v_16571;
    goto v_16474;
v_16470:
    v_16572 = stack[0];
    goto v_16471;
v_16472:
    v_16571 = elt(env, 3); // (ladd radd)
    goto v_16473;
v_16474:
    goto v_16470;
v_16471:
    goto v_16472;
v_16473:
    v_16571 = Lmemq(nil, v_16572, v_16571);
    if (v_16571 == nil) goto v_16469;
    v_16571 = stack[-3];
    fn = elt(env, 10); // qqe_arg2r
    v_16571 = (*qfn1(fn))(fn, v_16571);
    env = stack[-4];
    v_16573 = v_16571;
    goto v_16488;
v_16484:
    v_16572 = v_16573;
    goto v_16485;
v_16486:
    v_16571 = elt(env, 2); // qepsilon
    goto v_16487;
v_16488:
    goto v_16484;
v_16485:
    goto v_16486;
v_16487:
    if (v_16572 == v_16571) goto v_16482;
    else goto v_16483;
v_16482:
    v_16571 = elt(env, 2); // qepsilon
    goto v_16440;
v_16483:
    goto v_16508;
v_16504:
    v_16572 = stack[-1];
    goto v_16505;
v_16506:
    v_16571 = elt(env, 4); // ltail
    goto v_16507;
v_16508:
    goto v_16504;
v_16505:
    goto v_16506;
v_16507:
    if (v_16572 == v_16571) goto v_16502;
    else goto v_16503;
v_16502:
    goto v_16515;
v_16511:
    v_16572 = stack[0];
    goto v_16512;
v_16513:
    v_16571 = elt(env, 5); // radd
    goto v_16514;
v_16515:
    goto v_16511;
v_16512:
    goto v_16513;
v_16514:
    v_16571 = (v_16572 == v_16571 ? lisp_true : nil);
    goto v_16501;
v_16503:
    v_16571 = nil;
    goto v_16501;
    v_16571 = nil;
v_16501:
    if (v_16571 == nil) goto v_16499;
    v_16571 = lisp_true;
    goto v_16497;
v_16499:
    goto v_16533;
v_16529:
    v_16572 = stack[-1];
    goto v_16530;
v_16531:
    v_16571 = elt(env, 6); // rtail
    goto v_16532;
v_16533:
    goto v_16529;
v_16530:
    goto v_16531;
v_16532:
    if (v_16572 == v_16571) goto v_16527;
    else goto v_16528;
v_16527:
    goto v_16540;
v_16536:
    v_16572 = stack[0];
    goto v_16537;
v_16538:
    v_16571 = elt(env, 7); // ladd
    goto v_16539;
v_16540:
    goto v_16536;
v_16537:
    goto v_16538;
v_16539:
    v_16571 = (v_16572 == v_16571 ? lisp_true : nil);
    goto v_16526;
v_16528:
    v_16571 = nil;
    goto v_16526;
    v_16571 = nil;
v_16526:
    goto v_16497;
    v_16571 = nil;
v_16497:
    if (v_16571 == nil) goto v_16495;
    v_16571 = v_16573;
    goto v_16440;
v_16495:
    goto v_16467;
v_16469:
v_16467:
    v_16571 = stack[-3];
    fn = elt(env, 11); // qqe_simplterm
    v_16571 = (*qfn1(fn))(fn, v_16571);
    env = stack[-4];
    v_16573 = v_16571;
    goto v_16558;
v_16554:
    v_16572 = v_16573;
    goto v_16555;
v_16556:
    v_16571 = stack[-3];
    goto v_16557;
v_16558:
    goto v_16554;
v_16555:
    goto v_16556;
v_16557:
    if (equal(v_16572, v_16571)) goto v_16552;
    else goto v_16553;
v_16552:
    v_16571 = stack[-2];
    goto v_16440;
v_16553:
    goto v_16568;
v_16564:
    v_16571 = stack[-1];
    goto v_16565;
v_16566:
    v_16572 = v_16573;
    goto v_16567;
v_16568:
    goto v_16564;
v_16565:
    goto v_16566;
v_16567:
    v_16571 = list2(v_16571, v_16572);
    env = stack[-4];
    {
        fn = elt(env, 11); // qqe_simplterm
        return (*qfn1(fn))(fn, v_16571);
    }
v_16440:
    return onevalue(v_16571);
}



// Code for derad

static LispObject CC_derad(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16572, v_16573, v_16574;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16432,v_16433);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16433;
    stack[-1] = v_16432;
// end of prologue
    stack[-2] = nil;
v_16438:
    v_16572 = stack[0];
    if (v_16572 == nil) goto v_16441;
    else goto v_16442;
v_16441:
    goto v_16449;
v_16445:
    stack[0] = stack[-2];
    goto v_16446;
v_16447:
    v_16572 = stack[-1];
    v_16572 = ncons(v_16572);
    env = stack[-3];
    goto v_16448;
v_16449:
    goto v_16445;
v_16446:
    goto v_16447;
v_16448:
    {
        LispObject v_16578 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_16578, v_16572);
    }
v_16442:
    v_16572 = stack[0];
    v_16572 = qcar(v_16572);
    if (is_number(v_16572)) goto v_16453;
    else goto v_16454;
v_16453:
    goto v_16462;
v_16458:
    v_16572 = stack[0];
    v_16573 = qcar(v_16572);
    goto v_16459;
v_16460:
    v_16572 = stack[-2];
    goto v_16461;
v_16462:
    goto v_16458;
v_16459:
    goto v_16460;
v_16461:
    v_16572 = cons(v_16573, v_16572);
    env = stack[-3];
    stack[-2] = v_16572;
    v_16572 = stack[0];
    v_16572 = qcdr(v_16572);
    stack[0] = v_16572;
    goto v_16438;
v_16454:
    goto v_16474;
v_16470:
    v_16573 = stack[-1];
    goto v_16471;
v_16472:
    v_16572 = stack[0];
    v_16572 = qcar(v_16572);
    goto v_16473;
v_16474:
    goto v_16470;
v_16471:
    goto v_16472;
v_16473:
    if (equal(v_16573, v_16572)) goto v_16468;
    else goto v_16469;
v_16468:
    v_16572 = stack[0];
    v_16572 = qcdr(v_16572);
    if (v_16572 == nil) goto v_16481;
    v_16572 = stack[0];
    v_16572 = qcdr(v_16572);
    v_16572 = qcar(v_16572);
    if (is_number(v_16572)) goto v_16485;
    else goto v_16481;
v_16485:
    goto v_16494;
v_16490:
    goto v_16491;
v_16492:
    goto v_16503;
v_16497:
    goto v_16498;
v_16499:
    v_16572 = stack[0];
    v_16572 = qcdr(v_16572);
    v_16572 = qcar(v_16572);
    v_16573 = add1(v_16572);
    env = stack[-3];
    goto v_16500;
v_16501:
    v_16572 = stack[0];
    v_16572 = qcdr(v_16572);
    v_16572 = qcdr(v_16572);
    goto v_16502;
v_16503:
    goto v_16497;
v_16498:
    goto v_16499;
v_16500:
    goto v_16501;
v_16502:
    v_16572 = list2star(stack[-1], v_16573, v_16572);
    env = stack[-3];
    goto v_16493;
v_16494:
    goto v_16490;
v_16491:
    goto v_16492;
v_16493:
    {
        LispObject v_16579 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_16579, v_16572);
    }
v_16481:
    goto v_16519;
v_16515:
    goto v_16516;
v_16517:
    goto v_16528;
v_16522:
    v_16574 = stack[-1];
    goto v_16523;
v_16524:
    v_16573 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_16525;
v_16526:
    v_16572 = stack[0];
    v_16572 = qcdr(v_16572);
    goto v_16527;
v_16528:
    goto v_16522;
v_16523:
    goto v_16524;
v_16525:
    goto v_16526;
v_16527:
    v_16572 = list2star(v_16574, v_16573, v_16572);
    env = stack[-3];
    goto v_16518;
v_16519:
    goto v_16515;
v_16516:
    goto v_16517;
v_16518:
    {
        LispObject v_16580 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_16580, v_16572);
    }
    goto v_16440;
v_16469:
    goto v_16540;
v_16536:
    v_16573 = stack[-1];
    goto v_16537;
v_16538:
    v_16572 = stack[0];
    v_16572 = qcar(v_16572);
    goto v_16539;
v_16540:
    goto v_16536;
v_16537:
    goto v_16538;
v_16539:
    fn = elt(env, 2); // ordp
    v_16572 = (*qfn2(fn))(fn, v_16573, v_16572);
    env = stack[-3];
    if (v_16572 == nil) goto v_16534;
    goto v_16549;
v_16545:
    goto v_16546;
v_16547:
    goto v_16556;
v_16552:
    v_16573 = stack[-1];
    goto v_16553;
v_16554:
    v_16572 = stack[0];
    goto v_16555;
v_16556:
    goto v_16552;
v_16553:
    goto v_16554;
v_16555:
    v_16572 = cons(v_16573, v_16572);
    env = stack[-3];
    goto v_16548;
v_16549:
    goto v_16545;
v_16546:
    goto v_16547;
v_16548:
    {
        LispObject v_16581 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_16581, v_16572);
    }
v_16534:
    goto v_16566;
v_16562:
    v_16572 = stack[0];
    v_16573 = qcar(v_16572);
    goto v_16563;
v_16564:
    v_16572 = stack[-2];
    goto v_16565;
v_16566:
    goto v_16562;
v_16563:
    goto v_16564;
v_16565:
    v_16572 = cons(v_16573, v_16572);
    env = stack[-3];
    stack[-2] = v_16572;
    v_16572 = stack[0];
    v_16572 = qcdr(v_16572);
    stack[0] = v_16572;
    goto v_16438;
v_16440:
    v_16572 = nil;
    return onevalue(v_16572);
}



// Code for testpr

static LispObject CC_testpr(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16588, v_16589, v_16590;
    LispObject fn;
    LispObject v_16435, v_16434, v_16433, v_16432;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "testpr");
    va_start(aa, nargs);
    v_16432 = va_arg(aa, LispObject);
    v_16433 = va_arg(aa, LispObject);
    v_16434 = va_arg(aa, LispObject);
    v_16435 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_16435,v_16434,v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_16432,v_16433,v_16434,v_16435);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_16435;
    stack[-6] = v_16434;
    stack[0] = v_16433;
    v_16588 = v_16432;
// end of prologue
    stack[-3] = nil;
    v_16589 = qvalue(elt(env, 2)); // jsi
    stack[-2] = v_16589;
    goto v_16452;
v_16448:
    goto v_16457;
v_16453:
    stack[-1] = qvalue(elt(env, 3)); // codmat
    goto v_16454;
v_16455:
    goto v_16464;
v_16460:
    v_16589 = qvalue(elt(env, 4)); // maxvar
    goto v_16461;
v_16462:
    goto v_16463;
v_16464:
    goto v_16460;
v_16461:
    goto v_16462;
v_16463:
    v_16588 = plus2(v_16589, v_16588);
    env = stack[-8];
    goto v_16456;
v_16457:
    goto v_16453;
v_16454:
    goto v_16455;
v_16456:
    v_16589 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_16588-TAG_FIXNUM)/(16/CELL)));
    goto v_16449;
v_16450:
    v_16588 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_16451;
v_16452:
    goto v_16448;
v_16449:
    goto v_16450;
v_16451:
    v_16588 = *(LispObject *)((char *)v_16589 + (CELL-TAG_VECTOR) + (((intptr_t)v_16588-TAG_FIXNUM)/(16/CELL)));
    stack[-7] = v_16588;
    goto v_16474;
v_16470:
    goto v_16479;
v_16475:
    stack[-1] = qvalue(elt(env, 3)); // codmat
    goto v_16476;
v_16477:
    goto v_16486;
v_16482:
    v_16589 = qvalue(elt(env, 4)); // maxvar
    goto v_16483;
v_16484:
    v_16588 = stack[0];
    goto v_16485;
v_16486:
    goto v_16482;
v_16483:
    goto v_16484;
v_16485:
    v_16588 = plus2(v_16589, v_16588);
    env = stack[-8];
    goto v_16478;
v_16479:
    goto v_16475;
v_16476:
    goto v_16477;
v_16478:
    v_16589 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_16588-TAG_FIXNUM)/(16/CELL)));
    goto v_16471;
v_16472:
    v_16588 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_16473;
v_16474:
    goto v_16470;
v_16471:
    goto v_16472;
v_16473:
    v_16588 = *(LispObject *)((char *)v_16589 + (CELL-TAG_VECTOR) + (((intptr_t)v_16588-TAG_FIXNUM)/(16/CELL)));
    stack[-4] = v_16588;
v_16494:
    v_16588 = stack[-2];
    if (v_16588 == nil) goto v_16497;
    v_16588 = stack[-7];
    if (v_16588 == nil) goto v_16497;
    goto v_16498;
v_16497:
    goto v_16493;
v_16498:
    goto v_16512;
v_16508:
    v_16588 = stack[-2];
    v_16589 = qcar(v_16588);
    stack[-1] = v_16589;
    goto v_16509;
v_16510:
    v_16588 = stack[-7];
    v_16588 = qcar(v_16588);
    v_16588 = qcar(v_16588);
    v_16590 = v_16588;
    goto v_16511;
v_16512:
    goto v_16508;
v_16509:
    goto v_16510;
v_16511:
    if (equal(v_16589, v_16588)) goto v_16506;
    else goto v_16507;
v_16506:
    goto v_16523;
v_16519:
    v_16589 = stack[-1];
    goto v_16520;
v_16521:
    v_16588 = stack[-4];
    goto v_16522;
v_16523:
    goto v_16519;
v_16520:
    goto v_16521;
v_16522:
    fn = elt(env, 5); // pnthxzz
    v_16588 = (*qfn2(fn))(fn, v_16589, v_16588);
    env = stack[-8];
    stack[-4] = v_16588;
    goto v_16536;
v_16532:
    goto v_16542;
v_16538:
    v_16588 = stack[-7];
    v_16588 = qcar(v_16588);
    v_16588 = qcdr(v_16588);
    v_16589 = qcar(v_16588);
    goto v_16539;
v_16540:
    v_16588 = stack[-5];
    goto v_16541;
v_16542:
    goto v_16538;
v_16539:
    goto v_16540;
v_16541:
    fn = elt(env, 6); // dm!-times
    stack[0] = (*qfn2(fn))(fn, v_16589, v_16588);
    env = stack[-8];
    goto v_16533;
v_16534:
    goto v_16553;
v_16549:
    v_16588 = stack[-4];
    v_16588 = qcar(v_16588);
    v_16588 = qcdr(v_16588);
    v_16589 = qcar(v_16588);
    goto v_16550;
v_16551:
    v_16588 = stack[-6];
    goto v_16552;
v_16553:
    goto v_16549;
v_16550:
    goto v_16551;
v_16552:
    fn = elt(env, 6); // dm!-times
    v_16588 = (*qfn2(fn))(fn, v_16589, v_16588);
    env = stack[-8];
    goto v_16535;
v_16536:
    goto v_16532;
v_16533:
    goto v_16534;
v_16535:
    fn = elt(env, 7); // dm!-difference
    v_16588 = (*qfn2(fn))(fn, stack[0], v_16588);
    env = stack[-8];
    fn = elt(env, 8); // zeropp
    v_16588 = (*qfn1(fn))(fn, v_16588);
    env = stack[-8];
    if (v_16588 == nil) goto v_16529;
    goto v_16564;
v_16560:
    v_16589 = stack[-1];
    goto v_16561;
v_16562:
    v_16588 = stack[-3];
    goto v_16563;
v_16564:
    goto v_16560;
v_16561:
    goto v_16562;
v_16563:
    v_16588 = cons(v_16589, v_16588);
    env = stack[-8];
    stack[-3] = v_16588;
    goto v_16527;
v_16529:
v_16527:
    v_16588 = stack[-2];
    v_16588 = qcdr(v_16588);
    stack[-2] = v_16588;
    v_16588 = stack[-7];
    v_16588 = qcdr(v_16588);
    stack[-7] = v_16588;
    goto v_16505;
v_16507:
    goto v_16578;
v_16574:
    v_16588 = stack[-1];
    goto v_16575;
v_16576:
    v_16589 = v_16590;
    goto v_16577;
v_16578:
    goto v_16574;
v_16575:
    goto v_16576;
v_16577:
    v_16588 = (LispObject)greaterp2(v_16588, v_16589);
    v_16588 = v_16588 ? lisp_true : nil;
    env = stack[-8];
    if (v_16588 == nil) goto v_16572;
    v_16588 = stack[-7];
    v_16588 = qcdr(v_16588);
    stack[-7] = v_16588;
    goto v_16505;
v_16572:
    v_16588 = stack[-2];
    v_16588 = qcdr(v_16588);
    stack[-2] = v_16588;
    goto v_16505;
v_16505:
    goto v_16494;
v_16493:
    v_16588 = stack[-3];
    return onevalue(v_16588);
}



// Code for embed!-null!-fn

static LispObject CC_embedKnullKfn(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16538, v_16539, v_16540;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_16539 = v_16432;
// end of prologue
    v_16538 = v_16539;
    if (!consp(v_16538)) goto v_16436;
    else goto v_16437;
v_16436:
    v_16538 = v_16539;
    goto v_16435;
v_16437:
    v_16538 = v_16539;
    stack[-3] = v_16538;
v_16447:
    v_16538 = stack[-3];
    if (v_16538 == nil) goto v_16452;
    else goto v_16453;
v_16452:
    v_16538 = nil;
    goto v_16446;
v_16453:
    v_16538 = stack[-3];
    v_16538 = qcar(v_16538);
    v_16540 = v_16538;
    v_16538 = v_16540;
    if (!consp(v_16538)) goto v_16461;
    else goto v_16462;
v_16461:
    v_16538 = v_16540;
    v_16538 = ncons(v_16538);
    env = stack[-4];
    goto v_16460;
v_16462:
    goto v_16472;
v_16468:
    v_16538 = v_16540;
    v_16539 = qcar(v_16538);
    goto v_16469;
v_16470:
    v_16538 = elt(env, 1); // null!-fn
    goto v_16471;
v_16472:
    goto v_16468;
v_16469:
    goto v_16470;
v_16471:
    if (v_16539 == v_16538) goto v_16466;
    else goto v_16467;
v_16466:
    v_16538 = v_16540;
    v_16538 = qcdr(v_16538);
    v_16538 = CC_embedKnullKfn(elt(env, 0), v_16538);
    env = stack[-4];
    goto v_16460;
v_16467:
    v_16538 = v_16540;
    v_16538 = CC_embedKnullKfn(elt(env, 0), v_16538);
    env = stack[-4];
    v_16538 = ncons(v_16538);
    env = stack[-4];
    goto v_16460;
    v_16538 = nil;
v_16460:
    stack[-2] = v_16538;
    v_16538 = stack[-2];
    fn = elt(env, 2); // lastpair
    v_16538 = (*qfn1(fn))(fn, v_16538);
    env = stack[-4];
    stack[-1] = v_16538;
    v_16538 = stack[-3];
    v_16538 = qcdr(v_16538);
    stack[-3] = v_16538;
    v_16538 = stack[-1];
    if (!consp(v_16538)) goto v_16490;
    else goto v_16491;
v_16490:
    goto v_16447;
v_16491:
v_16448:
    v_16538 = stack[-3];
    if (v_16538 == nil) goto v_16495;
    else goto v_16496;
v_16495:
    v_16538 = stack[-2];
    goto v_16446;
v_16496:
    goto v_16504;
v_16500:
    stack[0] = stack[-1];
    goto v_16501;
v_16502:
    v_16538 = stack[-3];
    v_16538 = qcar(v_16538);
    v_16540 = v_16538;
    v_16538 = v_16540;
    if (!consp(v_16538)) goto v_16511;
    else goto v_16512;
v_16511:
    v_16538 = v_16540;
    v_16538 = ncons(v_16538);
    env = stack[-4];
    goto v_16510;
v_16512:
    goto v_16522;
v_16518:
    v_16538 = v_16540;
    v_16539 = qcar(v_16538);
    goto v_16519;
v_16520:
    v_16538 = elt(env, 1); // null!-fn
    goto v_16521;
v_16522:
    goto v_16518;
v_16519:
    goto v_16520;
v_16521:
    if (v_16539 == v_16538) goto v_16516;
    else goto v_16517;
v_16516:
    v_16538 = v_16540;
    v_16538 = qcdr(v_16538);
    v_16538 = CC_embedKnullKfn(elt(env, 0), v_16538);
    env = stack[-4];
    goto v_16510;
v_16517:
    v_16538 = v_16540;
    v_16538 = CC_embedKnullKfn(elt(env, 0), v_16538);
    env = stack[-4];
    v_16538 = ncons(v_16538);
    env = stack[-4];
    goto v_16510;
    v_16538 = nil;
v_16510:
    goto v_16503;
v_16504:
    goto v_16500;
v_16501:
    goto v_16502;
v_16503:
    v_16538 = Lrplacd(nil, stack[0], v_16538);
    env = stack[-4];
    v_16538 = stack[-1];
    fn = elt(env, 2); // lastpair
    v_16538 = (*qfn1(fn))(fn, v_16538);
    env = stack[-4];
    stack[-1] = v_16538;
    v_16538 = stack[-3];
    v_16538 = qcdr(v_16538);
    stack[-3] = v_16538;
    goto v_16448;
v_16446:
    goto v_16435;
    v_16538 = nil;
v_16435:
    return onevalue(v_16538);
}



// Code for basisformp

static LispObject CC_basisformp(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16450, v_16451;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16451 = v_16432;
// end of prologue
    v_16450 = v_16451;
    if (!consp(v_16450)) goto v_16437;
    goto v_16443;
v_16439:
    v_16450 = v_16451;
    goto v_16440;
v_16441:
    v_16451 = qvalue(elt(env, 1)); // basisforml!*
    goto v_16442;
v_16443:
    goto v_16439;
v_16440:
    goto v_16441;
v_16442:
    v_16450 = Lmemq(nil, v_16450, v_16451);
    goto v_16435;
v_16437:
    v_16450 = nil;
    goto v_16435;
    v_16450 = nil;
v_16435:
    return onevalue(v_16450);
}



// Code for inprinla

static LispObject CC_inprinla(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16516, v_16517;
    LispObject fn;
    LispObject v_16434, v_16433, v_16432;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "inprinla");
    va_start(aa, nargs);
    v_16432 = va_arg(aa, LispObject);
    v_16433 = va_arg(aa, LispObject);
    v_16434 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_16434,v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_16432,v_16433,v_16434);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_16434;
    stack[-1] = v_16433;
    stack[-2] = v_16432;
// end of prologue
    v_16516 = stack[-2];
    if (!symbolp(v_16516)) v_16516 = nil;
    else { v_16516 = qfastgets(v_16516);
           if (v_16516 != nil) { v_16516 = elt(v_16516, 49); // alt
#ifdef RECORD_GET
             if (v_16516 != SPID_NOPROP)
                record_get(elt(fastget_names, 49), 1);
             else record_get(elt(fastget_names, 49), 0),
                v_16516 = nil; }
           else record_get(elt(fastget_names, 49), 0); }
#else
             if (v_16516 == SPID_NOPROP) v_16516 = nil; }}
#endif
    if (v_16516 == nil) goto v_16444;
    goto v_16439;
v_16444:
    goto v_16452;
v_16448:
    v_16516 = stack[0];
    v_16517 = qcar(v_16516);
    goto v_16449;
v_16450:
    v_16516 = stack[-1];
    goto v_16451;
v_16452:
    goto v_16448;
v_16449:
    goto v_16450;
v_16451:
    fn = elt(env, 2); // maprintla
    v_16516 = (*qfn2(fn))(fn, v_16517, v_16516);
    env = stack[-4];
v_16438:
    v_16516 = stack[0];
    v_16516 = qcdr(v_16516);
    stack[0] = v_16516;
v_16439:
    v_16516 = stack[0];
    if (v_16516 == nil) goto v_16460;
    else goto v_16461;
v_16460:
    v_16516 = nil;
    goto v_16437;
v_16461:
    v_16516 = stack[0];
    v_16516 = qcar(v_16516);
    if (!consp(v_16516)) goto v_16468;
    else goto v_16469;
v_16468:
    v_16516 = lisp_true;
    goto v_16467;
v_16469:
    goto v_16479;
v_16475:
    stack[-3] = stack[-2];
    goto v_16476;
v_16477:
    goto v_16486;
v_16482:
    v_16516 = stack[0];
    v_16516 = qcar(v_16516);
    v_16517 = qcar(v_16516);
    goto v_16483;
v_16484:
    v_16516 = elt(env, 1); // alt
    goto v_16485;
v_16486:
    goto v_16482;
v_16483:
    goto v_16484;
v_16485:
    v_16516 = Lget(nil, v_16517, v_16516);
    env = stack[-4];
    goto v_16478;
v_16479:
    goto v_16475;
v_16476:
    goto v_16477;
v_16478:
    v_16516 = (stack[-3] == v_16516 ? lisp_true : nil);
    v_16516 = (v_16516 == nil ? lisp_true : nil);
    goto v_16467;
    v_16516 = nil;
v_16467:
    if (v_16516 == nil) goto v_16465;
    v_16516 = stack[-2];
    fn = elt(env, 3); // oprinla
    v_16516 = (*qfn1(fn))(fn, v_16516);
    env = stack[-4];
    goto v_16500;
v_16496:
    v_16516 = stack[0];
    v_16516 = qcar(v_16516);
    fn = elt(env, 4); // negnumberchk
    v_16517 = (*qfn1(fn))(fn, v_16516);
    env = stack[-4];
    goto v_16497;
v_16498:
    v_16516 = stack[-1];
    goto v_16499;
v_16500:
    goto v_16496;
v_16497:
    goto v_16498;
v_16499:
    fn = elt(env, 2); // maprintla
    v_16516 = (*qfn2(fn))(fn, v_16517, v_16516);
    env = stack[-4];
    goto v_16459;
v_16465:
    goto v_16512;
v_16508:
    v_16516 = stack[0];
    v_16517 = qcar(v_16516);
    goto v_16509;
v_16510:
    v_16516 = stack[-1];
    goto v_16511;
v_16512:
    goto v_16508;
v_16509:
    goto v_16510;
v_16511:
    fn = elt(env, 2); // maprintla
    v_16516 = (*qfn2(fn))(fn, v_16517, v_16516);
    env = stack[-4];
    goto v_16459;
v_16459:
    goto v_16438;
v_16437:
    return onevalue(v_16516);
}



// Code for getphystypetimes

static LispObject CC_getphystypetimes(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16475, v_16476;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_16432;
// end of prologue
    goto v_16447;
v_16443:
    stack[-1] = nil;
    goto v_16444;
v_16445:
    v_16475 = stack[0];
    fn = elt(env, 3); // collectphystype
    v_16475 = (*qfn1(fn))(fn, v_16475);
    env = stack[-2];
    goto v_16446;
v_16447:
    goto v_16443;
v_16444:
    goto v_16445;
v_16446:
    fn = elt(env, 4); // deleteall
    v_16475 = (*qfn2(fn))(fn, stack[-1], v_16475);
    env = stack[-2];
    v_16476 = v_16475;
    if (v_16475 == nil) goto v_16440;
    else goto v_16441;
v_16440:
    v_16475 = nil;
    goto v_16436;
v_16441:
    v_16475 = v_16476;
    v_16475 = qcdr(v_16475);
    if (v_16475 == nil) goto v_16452;
    else goto v_16453;
v_16452:
    v_16475 = v_16476;
    v_16475 = qcar(v_16475);
    goto v_16436;
v_16453:
    goto v_16465;
v_16461:
    stack[-1] = elt(env, 0); // getphystypetimes
    goto v_16462;
v_16463:
    goto v_16472;
v_16468:
    v_16476 = elt(env, 2); // "PHYSOP type mismatch in"
    goto v_16469;
v_16470:
    v_16475 = stack[0];
    goto v_16471;
v_16472:
    goto v_16468;
v_16469:
    goto v_16470;
v_16471:
    v_16475 = list2(v_16476, v_16475);
    env = stack[-2];
    goto v_16464;
v_16465:
    goto v_16461;
v_16462:
    goto v_16463;
v_16464:
    fn = elt(env, 5); // rederr2
    v_16475 = (*qfn2(fn))(fn, stack[-1], v_16475);
    goto v_16439;
v_16439:
    v_16475 = nil;
v_16436:
    return onevalue(v_16475);
}



// Code for clogsq!*

static LispObject CC_clogsqH(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16451, v_16452;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_16451 = v_16432;
// end of prologue
// Binding !*div
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = nil; // !*div
// Binding !*combinelogs
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=2
{   bind_fluid_stack bind_fluid_var(-4, 2, -2);
    qvalue(elt(env, 2)) = nil; // !*combinelogs
// Binding !*expandlogs
// FLUIDBIND: reloadenv=4 litvec-offset=3 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 3, -1);
    qvalue(elt(env, 3)) = nil; // !*expandlogs
    v_16452 = lisp_true;
    qvalue(elt(env, 3)) = v_16452; // !*expandlogs
    qvalue(elt(env, 1)) = v_16452; // !*div
    v_16452 = lisp_true;
// Binding !*uncached
// FLUIDBIND: reloadenv=4 litvec-offset=5 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 5, 0);
    qvalue(elt(env, 5)) = v_16452; // !*uncached
    fn = elt(env, 6); // prepsq
    v_16451 = (*qfn1(fn))(fn, v_16451);
    env = stack[-4];
    fn = elt(env, 7); // simp
    v_16451 = (*qfn1(fn))(fn, v_16451);
    env = stack[-4];
    ;}  // end of a binding scope
    v_16452 = nil;
    qvalue(elt(env, 3)) = v_16452; // !*expandlogs
    fn = elt(env, 8); // prepsq!*
    v_16451 = (*qfn1(fn))(fn, v_16451);
    env = stack[-4];
    fn = elt(env, 9); // comblog
    v_16451 = (*qfn1(fn))(fn, v_16451);
    env = stack[-4];
    fn = elt(env, 10); // simp!*
    v_16451 = (*qfn1(fn))(fn, v_16451);
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_16451);
}



// Code for subla!-q

static LispObject CC_sublaKq(LispObject env,
                         LispObject v_16432, LispObject v_16433)
{
    env = qenv(env);
    LispObject v_16615, v_16616;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16432,v_16433);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16433;
    stack[-1] = v_16432;
// end of prologue
    v_16615 = stack[-1];
    if (v_16615 == nil) goto v_16445;
    else goto v_16446;
v_16445:
    v_16615 = lisp_true;
    goto v_16444;
v_16446:
    v_16615 = stack[0];
    v_16615 = (v_16615 == nil ? lisp_true : nil);
    goto v_16444;
    v_16615 = nil;
v_16444:
    if (v_16615 == nil) goto v_16442;
    v_16615 = stack[0];
    goto v_16437;
v_16442:
    v_16615 = stack[0];
    if (!consp(v_16615)) goto v_16454;
    else goto v_16455;
v_16454:
    goto v_16465;
v_16461:
    v_16616 = stack[0];
    goto v_16462;
v_16463:
    v_16615 = stack[-1];
    goto v_16464;
v_16465:
    goto v_16461;
v_16462:
    goto v_16463;
v_16464:
    v_16616 = Latsoc(nil, v_16616, v_16615);
    v_16615 = v_16616;
    if (v_16616 == nil) goto v_16460;
    v_16615 = qcdr(v_16615);
    goto v_16458;
v_16460:
    v_16615 = stack[0];
    goto v_16458;
    v_16615 = nil;
v_16458:
    goto v_16437;
v_16455:
    goto v_16484;
v_16480:
    v_16615 = stack[0];
    v_16616 = qcar(v_16615);
    goto v_16481;
v_16482:
    v_16615 = elt(env, 2); // quote
    goto v_16483;
v_16484:
    goto v_16480;
v_16481:
    goto v_16482;
v_16483:
    if (v_16616 == v_16615) goto v_16478;
    else goto v_16479;
v_16478:
    v_16615 = lisp_true;
    goto v_16477;
v_16479:
    goto v_16495;
v_16491:
    v_16615 = stack[0];
    v_16616 = qcar(v_16615);
    goto v_16492;
v_16493:
    v_16615 = elt(env, 3); // go
    goto v_16494;
v_16495:
    goto v_16491;
v_16492:
    goto v_16493;
v_16494:
    v_16615 = (v_16616 == v_16615 ? lisp_true : nil);
    goto v_16477;
    v_16615 = nil;
v_16477:
    if (v_16615 == nil) goto v_16475;
    v_16615 = stack[0];
    goto v_16437;
v_16475:
    goto v_16516;
v_16512:
    v_16616 = stack[0];
    goto v_16513;
v_16514:
    v_16615 = elt(env, 4); // lambda
    goto v_16515;
v_16516:
    goto v_16512;
v_16513:
    goto v_16514;
v_16515:
    if (!consp(v_16616)) goto v_16510;
    v_16616 = qcar(v_16616);
    if (v_16616 == v_16615) goto v_16509;
    else goto v_16510;
v_16509:
    v_16615 = lisp_true;
    goto v_16508;
v_16510:
    goto v_16527;
v_16523:
    v_16616 = stack[0];
    goto v_16524;
v_16525:
    v_16615 = elt(env, 5); // prog
    goto v_16526;
v_16527:
    goto v_16523;
v_16524:
    goto v_16525;
v_16526:
    v_16615 = Leqcar(nil, v_16616, v_16615);
    env = stack[-3];
    goto v_16508;
    v_16615 = nil;
v_16508:
    if (v_16615 == nil) goto v_16506;
    v_16615 = stack[0];
    v_16615 = qcdr(v_16615);
    v_16615 = (consp(v_16615) ? nil : lisp_true);
    v_16615 = (v_16615 == nil ? lisp_true : nil);
    goto v_16504;
v_16506:
    v_16615 = nil;
    goto v_16504;
    v_16615 = nil;
v_16504:
    if (v_16615 == nil) goto v_16502;
    v_16615 = stack[0];
    v_16615 = qcdr(v_16615);
    v_16615 = qcar(v_16615);
    stack[-2] = v_16615;
v_16543:
    v_16615 = stack[-2];
    if (v_16615 == nil) goto v_16547;
    else goto v_16548;
v_16547:
    goto v_16542;
v_16548:
    v_16615 = stack[-2];
    v_16615 = qcar(v_16615);
    goto v_16559;
v_16555:
    v_16616 = v_16615;
    goto v_16556;
v_16557:
    v_16615 = stack[-1];
    goto v_16558;
v_16559:
    goto v_16555;
v_16556:
    goto v_16557;
v_16558:
    fn = elt(env, 6); // delasc
    v_16615 = (*qfn2(fn))(fn, v_16616, v_16615);
    env = stack[-3];
    stack[-1] = v_16615;
    v_16615 = stack[-2];
    v_16615 = qcdr(v_16615);
    stack[-2] = v_16615;
    goto v_16543;
v_16542:
    goto v_16569;
v_16565:
    goto v_16575;
v_16571:
    v_16616 = stack[-1];
    goto v_16572;
v_16573:
    v_16615 = stack[0];
    v_16615 = qcar(v_16615);
    goto v_16574;
v_16575:
    goto v_16571;
v_16572:
    goto v_16573;
v_16574:
    stack[-2] = CC_sublaKq(elt(env, 0), v_16616, v_16615);
    env = stack[-3];
    goto v_16566;
v_16567:
    goto v_16584;
v_16580:
    v_16616 = stack[-1];
    goto v_16581;
v_16582:
    v_16615 = stack[0];
    v_16615 = qcdr(v_16615);
    goto v_16583;
v_16584:
    goto v_16580;
v_16581:
    goto v_16582;
v_16583:
    v_16615 = CC_sublaKq(elt(env, 0), v_16616, v_16615);
    goto v_16568;
v_16569:
    goto v_16565;
v_16566:
    goto v_16567;
v_16568:
    {
        LispObject v_16620 = stack[-2];
        return cons(v_16620, v_16615);
    }
v_16502:
    goto v_16596;
v_16592:
    goto v_16602;
v_16598:
    v_16616 = stack[-1];
    goto v_16599;
v_16600:
    v_16615 = stack[0];
    v_16615 = qcar(v_16615);
    goto v_16601;
v_16602:
    goto v_16598;
v_16599:
    goto v_16600;
v_16601:
    stack[-2] = CC_sublaKq(elt(env, 0), v_16616, v_16615);
    env = stack[-3];
    goto v_16593;
v_16594:
    goto v_16611;
v_16607:
    v_16616 = stack[-1];
    goto v_16608;
v_16609:
    v_16615 = stack[0];
    v_16615 = qcdr(v_16615);
    goto v_16610;
v_16611:
    goto v_16607;
v_16608:
    goto v_16609;
v_16610:
    v_16615 = CC_sublaKq(elt(env, 0), v_16616, v_16615);
    goto v_16595;
v_16596:
    goto v_16592;
v_16593:
    goto v_16594;
v_16595:
    {
        LispObject v_16621 = stack[-2];
        return cons(v_16621, v_16615);
    }
    v_16615 = nil;
v_16437:
    return onevalue(v_16615);
}



// Code for changearg

static LispObject CC_changearg(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16503, v_16504, v_16505;
    LispObject fn;
    LispObject v_16434, v_16433, v_16432;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "changearg");
    va_start(aa, nargs);
    v_16432 = va_arg(aa, LispObject);
    v_16433 = va_arg(aa, LispObject);
    v_16434 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_16434,v_16433,v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_16432,v_16433,v_16434);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_16434;
    stack[-1] = v_16433;
    stack[-2] = v_16432;
// end of prologue
    stack[-3] = nil;
v_16439:
    v_16503 = stack[0];
    if (!consp(v_16503)) goto v_16442;
    else goto v_16443;
v_16442:
    goto v_16450;
v_16446:
    v_16504 = stack[-3];
    goto v_16447;
v_16448:
    v_16503 = stack[0];
    goto v_16449;
v_16450:
    goto v_16446;
v_16447:
    goto v_16448;
v_16449:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_16504, v_16503);
    }
v_16443:
    goto v_16459;
v_16455:
    v_16503 = stack[0];
    v_16504 = qcar(v_16503);
    goto v_16456;
v_16457:
    v_16503 = stack[-2];
    goto v_16458;
v_16459:
    goto v_16455;
v_16456:
    goto v_16457;
v_16458:
    v_16503 = Lmemq(nil, v_16504, v_16503);
    if (v_16503 == nil) goto v_16454;
    goto v_16469;
v_16465:
    stack[-2] = stack[-3];
    goto v_16466;
v_16467:
    goto v_16476;
v_16472:
    v_16503 = stack[0];
    v_16504 = qcar(v_16503);
    goto v_16473;
v_16474:
    v_16503 = stack[-1];
    goto v_16475;
v_16476:
    goto v_16472;
v_16473:
    goto v_16474;
v_16475:
    v_16503 = cons(v_16504, v_16503);
    env = stack[-4];
    goto v_16468;
v_16469:
    goto v_16465;
v_16466:
    goto v_16467;
v_16468:
    {
        LispObject v_16510 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_16510, v_16503);
    }
v_16454:
    goto v_16487;
v_16483:
    goto v_16495;
v_16489:
    v_16505 = stack[-2];
    goto v_16490;
v_16491:
    v_16504 = stack[-1];
    goto v_16492;
v_16493:
    v_16503 = stack[0];
    v_16503 = qcar(v_16503);
    goto v_16494;
v_16495:
    goto v_16489;
v_16490:
    goto v_16491;
v_16492:
    goto v_16493;
v_16494:
    v_16504 = CC_changearg(elt(env, 0), 3, v_16505, v_16504, v_16503);
    env = stack[-4];
    goto v_16484;
v_16485:
    v_16503 = stack[-3];
    goto v_16486;
v_16487:
    goto v_16483;
v_16484:
    goto v_16485;
v_16486:
    v_16503 = cons(v_16504, v_16503);
    env = stack[-4];
    stack[-3] = v_16503;
    v_16503 = stack[0];
    v_16503 = qcdr(v_16503);
    stack[0] = v_16503;
    goto v_16439;
    v_16503 = nil;
    return onevalue(v_16503);
}



// Code for red!=hide

static LispObject CC_redMhide(LispObject env,
                         LispObject v_16432)
{
    env = qenv(env);
    LispObject v_16508, v_16509;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16432);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16432);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_16508 = v_16432;
// end of prologue
    stack[-5] = v_16508;
    v_16508 = stack[-5];
    if (v_16508 == nil) goto v_16443;
    else goto v_16444;
v_16443:
    v_16508 = nil;
    goto v_16438;
v_16444:
    v_16508 = stack[-5];
    v_16508 = qcar(v_16508);
    stack[-1] = v_16508;
    goto v_16456;
v_16452:
    goto v_16462;
v_16458:
    stack[0] = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_16459;
v_16460:
    v_16508 = stack[-1];
    v_16508 = qcar(v_16508);
    fn = elt(env, 1); // mo_neg
    v_16508 = (*qfn1(fn))(fn, v_16508);
    env = stack[-6];
    goto v_16461;
v_16462:
    goto v_16458;
v_16459:
    goto v_16460;
v_16461:
    fn = elt(env, 2); // mo_times_ei
    v_16509 = (*qfn2(fn))(fn, stack[0], v_16508);
    env = stack[-6];
    goto v_16453;
v_16454:
    v_16508 = stack[-1];
    v_16508 = qcdr(v_16508);
    goto v_16455;
v_16456:
    goto v_16452;
v_16453:
    goto v_16454;
v_16455:
    v_16508 = cons(v_16509, v_16508);
    env = stack[-6];
    v_16508 = ncons(v_16508);
    env = stack[-6];
    stack[-3] = v_16508;
    stack[-4] = v_16508;
v_16439:
    v_16508 = stack[-5];
    v_16508 = qcdr(v_16508);
    stack[-5] = v_16508;
    v_16508 = stack[-5];
    if (v_16508 == nil) goto v_16473;
    else goto v_16474;
v_16473:
    v_16508 = stack[-4];
    goto v_16438;
v_16474:
    goto v_16482;
v_16478:
    stack[-2] = stack[-3];
    goto v_16479;
v_16480:
    v_16508 = stack[-5];
    v_16508 = qcar(v_16508);
    stack[-1] = v_16508;
    goto v_16493;
v_16489:
    goto v_16499;
v_16495:
    stack[0] = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_16496;
v_16497:
    v_16508 = stack[-1];
    v_16508 = qcar(v_16508);
    fn = elt(env, 1); // mo_neg
    v_16508 = (*qfn1(fn))(fn, v_16508);
    env = stack[-6];
    goto v_16498;
v_16499:
    goto v_16495;
v_16496:
    goto v_16497;
v_16498:
    fn = elt(env, 2); // mo_times_ei
    v_16509 = (*qfn2(fn))(fn, stack[0], v_16508);
    env = stack[-6];
    goto v_16490;
v_16491:
    v_16508 = stack[-1];
    v_16508 = qcdr(v_16508);
    goto v_16492;
v_16493:
    goto v_16489;
v_16490:
    goto v_16491;
v_16492:
    v_16508 = cons(v_16509, v_16508);
    env = stack[-6];
    v_16508 = ncons(v_16508);
    env = stack[-6];
    goto v_16481;
v_16482:
    goto v_16478;
v_16479:
    goto v_16480;
v_16481:
    v_16508 = Lrplacd(nil, stack[-2], v_16508);
    env = stack[-6];
    v_16508 = stack[-3];
    v_16508 = qcdr(v_16508);
    stack[-3] = v_16508;
    goto v_16439;
v_16438:
    return onevalue(v_16508);
}



setup_type const u31_setup[] =
{
    {"ifstat",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ifstat},
    {"cquotegex",               CC_cquotegex,   TOO_MANY_1,    WRONG_NO_1},
    {"cl_rename-vars",          CC_cl_renameKvars,TOO_MANY_1,  WRONG_NO_1},
    {"qqe_arg-check-lb-rb",     CC_qqe_argKcheckKlbKrb,TOO_MANY_1,WRONG_NO_1},
    {"pasf_simplat1",           TOO_FEW_2,      CC_pasf_simplat1,WRONG_NO_2},
    {"acfsf_0mk2",              TOO_FEW_2,      CC_acfsf_0mk2, WRONG_NO_2},
    {"dm-mkfloat",              CC_dmKmkfloat,  TOO_MANY_1,    WRONG_NO_1},
    {"evrevgradlexcomp",        TOO_FEW_2,      CC_evrevgradlexcomp,WRONG_NO_2},
    {"*pf2sq",                  CC_Hpf2sq,      TOO_MANY_1,    WRONG_NO_1},
    {"quotpri",                 CC_quotpri,     TOO_MANY_1,    WRONG_NO_1},
    {"idtomind",                TOO_FEW_2,      CC_idtomind,   WRONG_NO_2},
    {"expansion_name",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_expansion_name},
    {"talp_getinvfsym",         TOO_FEW_2,      CC_talp_getinvfsym,WRONG_NO_2},
    {"qqe_ofsf_simpat",         CC_qqe_ofsf_simpat,TOO_MANY_1, WRONG_NO_1},
    {"repr_a",                  CC_repr_a,      TOO_MANY_1,    WRONG_NO_1},
    {"ev_insert",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ev_insert},
    {"get-height",              CC_getKheight,  TOO_MANY_1,    WRONG_NO_1},
    {"getdec",                  CC_getdec,      TOO_MANY_1,    WRONG_NO_1},
    {"unresidp",                CC_unresidp,    TOO_MANY_1,    WRONG_NO_1},
    {"edge_new_parents",        CC_edge_new_parents,TOO_MANY_1,WRONG_NO_1},
    {"no-side-effect-listp",    CC_noKsideKeffectKlistp,TOO_MANY_1,WRONG_NO_1},
    {"generic-sub",             TOO_FEW_2,      CC_genericKsub,WRONG_NO_2},
    {"aex_divposcnt",           TOO_FEW_2,      CC_aex_divposcnt,WRONG_NO_2},
    {"mkfil*",                  CC_mkfilH,      TOO_MANY_1,    WRONG_NO_1},
    {"pushback",                TOO_FEW_2,      CC_pushback,   WRONG_NO_2},
    {"cl_sordpl",               TOO_FEW_2,      CC_cl_sordpl,  WRONG_NO_2},
    {"sfto_b:ordexn",           TOO_FEW_2,      CC_sfto_bTordexn,WRONG_NO_2},
    {"omfir",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_omfir},
    {"exptplus",                TOO_FEW_2,      CC_exptplus,   WRONG_NO_2},
    {"initarg",                 CC_initarg,     TOO_MANY_1,    WRONG_NO_1},
    {"dipprod",                 TOO_FEW_2,      CC_dipprod,    WRONG_NO_2},
    {"prop-simp2",              TOO_FEW_2,      CC_propKsimp2, WRONG_NO_2},
    {"subsq",                   TOO_FEW_2,      CC_subsq,      WRONG_NO_2},
    {"arminusp:",               CC_arminuspT,   TOO_MANY_1,    WRONG_NO_1},
    {"aex_sgn",                 CC_aex_sgn,     TOO_MANY_1,    WRONG_NO_1},
    {"open",                    TOO_FEW_2,      CC_open,       WRONG_NO_2},
    {"ofsf_smordtable",         TOO_FEW_2,      CC_ofsf_smordtable,WRONG_NO_2},
    {"checku",                  TOO_FEW_2,      CC_checku,     WRONG_NO_2},
    {"cl_nnfnot",               CC_cl_nnfnot,   TOO_MANY_1,    WRONG_NO_1},
    {"qqe_eta-in-term1",        CC_qqe_etaKinKterm1,TOO_MANY_1,WRONG_NO_1},
    {"cl_susiupdknowl2",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_susiupdknowl2},
    {"ofsf_xor",                TOO_FEW_2,      CC_ofsf_xor,   WRONG_NO_2},
    {"dvfsf_0mk2",              TOO_FEW_2,      CC_dvfsf_0mk2, WRONG_NO_2},
    {"sfto_b:extmult",          TOO_FEW_2,      CC_sfto_bTextmult,WRONG_NO_2},
    {"lambdaom",                CC_lambdaom,    TOO_MANY_1,    WRONG_NO_1},
    {"vdpcondense",             CC_vdpcondense, TOO_MANY_1,    WRONG_NO_1},
    {"all_defined_vertex",      TOO_FEW_2,      CC_all_defined_vertex,WRONG_NO_2},
    {"repartsq",                CC_repartsq,    TOO_MANY_1,    WRONG_NO_1},
    {"red_topred",              TOO_FEW_2,      CC_red_topred, WRONG_NO_2},
    {"dfconst",                 CC_dfconst,     TOO_MANY_1,    WRONG_NO_1},
    {"qqe_simplterm-tail",      CC_qqe_simpltermKtail,TOO_MANY_1,WRONG_NO_1},
    {"derad",                   TOO_FEW_2,      CC_derad,      WRONG_NO_2},
    {"testpr",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_testpr},
    {"embed-null-fn",           CC_embedKnullKfn,TOO_MANY_1,   WRONG_NO_1},
    {"basisformp",              CC_basisformp,  TOO_MANY_1,    WRONG_NO_1},
    {"inprinla",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_inprinla},
    {"getphystypetimes",        CC_getphystypetimes,TOO_MANY_1,WRONG_NO_1},
    {"clogsq*",                 CC_clogsqH,     TOO_MANY_1,    WRONG_NO_1},
    {"subla-q",                 TOO_FEW_2,      CC_sublaKq,    WRONG_NO_2},
    {"changearg",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_changearg},
    {"red=hide",                CC_redMhide,    TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u31", (two_args *)"121699 819214 7169483", 0}
};

// end of generated code
