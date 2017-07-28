
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



// Code for cl_susiupdknowl2

static LispObject CC_cl_susiupdknowl2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16984, v_16985, v_16986;
    LispObject fn;
    LispObject v_16831, v_16830, v_16829;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cl_susiupdknowl2");
    va_start(aa, nargs);
    v_16829 = va_arg(aa, LispObject);
    v_16830 = va_arg(aa, LispObject);
    v_16831 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_16831,v_16830,v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_16829,v_16830,v_16831);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_16831;
    stack[-5] = v_16830;
    stack[-6] = v_16829;
// end of prologue
    stack[-3] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    v_16984 = stack[-5];
    stack[-2] = v_16984;
v_16845:
    v_16984 = stack[-2];
    if (v_16984 == nil) goto v_16848;
    else goto v_16849;
v_16848:
    goto v_16844;
v_16849:
    v_16984 = stack[-2];
    v_16984 = qcar(v_16984);
    stack[-7] = v_16984;
    v_16984 = stack[-2];
    v_16984 = qcdr(v_16984);
    stack[-2] = v_16984;
    goto v_16861;
v_16857:
    v_16985 = stack[-7];
    goto v_16858;
v_16859:
    v_16984 = stack[-6];
    goto v_16860;
v_16861:
    goto v_16857;
v_16858:
    goto v_16859;
v_16860:
    fn = elt(env, 2); // rl_susibin
    v_16984 = (*qfn2(fn))(fn, v_16985, v_16984);
    env = stack[-8];
    stack[-3] = v_16984;
    goto v_16872;
v_16868:
    v_16985 = stack[-3];
    goto v_16869;
v_16870:
    v_16984 = elt(env, 1); // false
    goto v_16871;
v_16872:
    goto v_16868;
v_16869:
    goto v_16870;
v_16871:
    if (v_16985 == v_16984) goto v_16866;
    else goto v_16867;
v_16866:
    v_16984 = nil;
    stack[-2] = v_16984;
    goto v_16865;
v_16867:
    goto v_16885;
v_16879:
    v_16986 = stack[-3];
    goto v_16880;
v_16881:
    v_16985 = stack[-5];
    goto v_16882;
v_16883:
    v_16984 = stack[-7];
    goto v_16884;
v_16885:
    goto v_16879;
v_16880:
    goto v_16881;
v_16882:
    goto v_16883;
v_16884:
    fn = elt(env, 3); // cl_susiinter
    v_16984 = (*qfnn(fn))(fn, 3, v_16986, v_16985, v_16984);
    env = stack[-8];
    stack[-3] = v_16984;
    goto v_16894;
v_16890:
    v_16985 = stack[0];
    goto v_16891;
v_16892:
    v_16984 = stack[-3];
    v_16984 = qcdr(v_16984);
    v_16984 = qcar(v_16984);
    goto v_16893;
v_16894:
    goto v_16890;
v_16891:
    goto v_16892;
v_16893:
    v_16984 = Lnconc(nil, v_16985, v_16984);
    env = stack[-8];
    stack[0] = v_16984;
    v_16984 = stack[-3];
    v_16984 = qcar(v_16984);
    stack[-5] = v_16984;
    v_16984 = stack[-3];
    v_16984 = qcdr(v_16984);
    v_16984 = qcdr(v_16984);
    v_16984 = qcar(v_16984);
    if (v_16984 == nil) goto v_16904;
    goto v_16902;
v_16904:
v_16902:
    v_16984 = stack[-3];
    v_16984 = qcdr(v_16984);
    v_16984 = qcdr(v_16984);
    v_16984 = qcdr(v_16984);
    v_16984 = qcar(v_16984);
    if (v_16984 == nil) goto v_16913;
    v_16984 = lisp_true;
    stack[-1] = v_16984;
    v_16984 = nil;
    stack[-2] = v_16984;
    goto v_16911;
v_16913:
v_16911:
    goto v_16865;
v_16865:
    goto v_16845;
v_16844:
    goto v_16929;
v_16925:
    v_16985 = stack[-3];
    goto v_16926;
v_16927:
    v_16984 = elt(env, 1); // false
    goto v_16928;
v_16929:
    goto v_16925;
v_16926:
    goto v_16927;
v_16928:
    if (v_16985 == v_16984) goto v_16923;
    else goto v_16924;
v_16923:
    v_16984 = elt(env, 1); // false
    goto v_16841;
v_16924:
    v_16984 = stack[-1];
    if (v_16984 == nil) goto v_16935;
    else goto v_16936;
v_16935:
    goto v_16943;
v_16939:
    v_16985 = stack[-6];
    goto v_16940;
v_16941:
    v_16984 = stack[-5];
    goto v_16942;
v_16943:
    goto v_16939;
v_16940:
    goto v_16941;
v_16942:
    v_16984 = cons(v_16985, v_16984);
    env = stack[-8];
    stack[-5] = v_16984;
    goto v_16934;
v_16936:
v_16934:
v_16948:
    v_16984 = stack[0];
    if (v_16984 == nil) goto v_16951;
    else goto v_16952;
v_16951:
    goto v_16947;
v_16952:
    goto v_16962;
v_16956:
    v_16984 = stack[0];
    v_16986 = qcar(v_16984);
    goto v_16957;
v_16958:
    v_16985 = stack[-5];
    goto v_16959;
v_16960:
    v_16984 = stack[-4];
    goto v_16961;
v_16962:
    goto v_16956;
v_16957:
    goto v_16958;
v_16959:
    goto v_16960;
v_16961:
    v_16984 = CC_cl_susiupdknowl2(elt(env, 0), 3, v_16986, v_16985, v_16984);
    env = stack[-8];
    stack[-5] = v_16984;
    goto v_16975;
v_16971:
    v_16985 = stack[-5];
    goto v_16972;
v_16973:
    v_16984 = elt(env, 1); // false
    goto v_16974;
v_16975:
    goto v_16971;
v_16972:
    goto v_16973;
v_16974:
    if (v_16985 == v_16984) goto v_16969;
    else goto v_16970;
v_16969:
    v_16984 = nil;
    stack[0] = v_16984;
    goto v_16968;
v_16970:
    v_16984 = stack[0];
    v_16984 = qcdr(v_16984);
    stack[0] = v_16984;
    goto v_16968;
v_16968:
    goto v_16948;
v_16947:
    v_16984 = stack[-5];
v_16841:
    return onevalue(v_16984);
}



// Code for semanticml

static LispObject CC_semanticml(LispObject env,
                         LispObject v_16829)
{
    env = qenv(env);
    LispObject v_16913, v_16914;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16829);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_16829;
// end of prologue
    goto v_16842;
v_16838:
    v_16913 = stack[0];
    v_16914 = Llength(nil, v_16913);
    env = stack[-1];
    goto v_16839;
v_16840:
    v_16913 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16841;
v_16842:
    goto v_16838;
v_16839:
    goto v_16840;
v_16841:
    v_16913 = (LispObject)greaterp2(v_16914, v_16913);
    v_16913 = v_16913 ? lisp_true : nil;
    env = stack[-1];
    if (v_16913 == nil) goto v_16836;
    v_16913 = elt(env, 1); // "<apply>"
    fn = elt(env, 13); // printout
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    v_16913 = lisp_true;
    fn = elt(env, 14); // indent!*
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    v_16913 = elt(env, 2); // "<fn>"
    fn = elt(env, 13); // printout
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    v_16913 = lisp_true;
    fn = elt(env, 14); // indent!*
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    goto v_16834;
v_16836:
v_16834:
    v_16913 = elt(env, 3); // "<semantic>"
    fn = elt(env, 13); // printout
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    v_16913 = lisp_true;
    fn = elt(env, 14); // indent!*
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    v_16913 = elt(env, 4); // "<ci><mo>"
    fn = elt(env, 13); // printout
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    v_16913 = stack[0];
    v_16913 = qcar(v_16913);
    v_16913 = qcar(v_16913);
    v_16913 = Lprinc(nil, v_16913);
    env = stack[-1];
    v_16913 = elt(env, 5); // "</mo></ci>"
    v_16913 = Lprinc(nil, v_16913);
    env = stack[-1];
    v_16913 = elt(env, 6); // "<annotation-xml encoding=""OpenMath"">"
    fn = elt(env, 13); // printout
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    v_16913 = lisp_true;
    fn = elt(env, 14); // indent!*
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    v_16913 = elt(env, 7); // "<"
    fn = elt(env, 13); // printout
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    v_16913 = stack[0];
    v_16913 = qcar(v_16913);
    v_16913 = qcdr(v_16913);
    v_16913 = qcar(v_16913);
    fn = elt(env, 15); // mathml_list2string
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    v_16913 = elt(env, 8); // ">"
    v_16913 = Lprinc(nil, v_16913);
    env = stack[-1];
    v_16913 = nil;
    fn = elt(env, 14); // indent!*
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    v_16913 = elt(env, 9); // "</annotation-xml>"
    fn = elt(env, 13); // printout
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    v_16913 = nil;
    fn = elt(env, 14); // indent!*
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    v_16913 = elt(env, 10); // "</semantic>"
    fn = elt(env, 13); // printout
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    goto v_16897;
v_16893:
    v_16913 = stack[0];
    v_16914 = Llength(nil, v_16913);
    env = stack[-1];
    goto v_16894;
v_16895:
    v_16913 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16896;
v_16897:
    goto v_16893;
v_16894:
    goto v_16895;
v_16896:
    v_16913 = (LispObject)greaterp2(v_16914, v_16913);
    v_16913 = v_16913 ? lisp_true : nil;
    env = stack[-1];
    if (v_16913 == nil) goto v_16891;
    v_16913 = nil;
    fn = elt(env, 14); // indent!*
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    v_16913 = elt(env, 11); // "</fn>"
    fn = elt(env, 13); // printout
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    v_16913 = stack[0];
    v_16913 = qcdr(v_16913);
    fn = elt(env, 16); // multi_elem
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    v_16913 = nil;
    fn = elt(env, 14); // indent!*
    v_16913 = (*qfn1(fn))(fn, v_16913);
    env = stack[-1];
    v_16913 = elt(env, 12); // "</apply>"
    fn = elt(env, 13); // printout
    v_16913 = (*qfn1(fn))(fn, v_16913);
    goto v_16889;
v_16891:
v_16889:
    v_16913 = nil;
    return onevalue(v_16913);
}



// Code for derad

static LispObject CC_derad(LispObject env,
                         LispObject v_16829, LispObject v_16830)
{
    env = qenv(env);
    LispObject v_16969, v_16970, v_16971;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16830,v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16829,v_16830);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16830;
    stack[-1] = v_16829;
// end of prologue
    stack[-2] = nil;
v_16835:
    v_16969 = stack[0];
    if (v_16969 == nil) goto v_16838;
    else goto v_16839;
v_16838:
    goto v_16846;
v_16842:
    stack[0] = stack[-2];
    goto v_16843;
v_16844:
    v_16969 = stack[-1];
    v_16969 = ncons(v_16969);
    env = stack[-3];
    goto v_16845;
v_16846:
    goto v_16842;
v_16843:
    goto v_16844;
v_16845:
    {
        LispObject v_16975 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_16975, v_16969);
    }
v_16839:
    v_16969 = stack[0];
    v_16969 = qcar(v_16969);
    if (is_number(v_16969)) goto v_16850;
    else goto v_16851;
v_16850:
    goto v_16859;
v_16855:
    v_16969 = stack[0];
    v_16970 = qcar(v_16969);
    goto v_16856;
v_16857:
    v_16969 = stack[-2];
    goto v_16858;
v_16859:
    goto v_16855;
v_16856:
    goto v_16857;
v_16858:
    v_16969 = cons(v_16970, v_16969);
    env = stack[-3];
    stack[-2] = v_16969;
    v_16969 = stack[0];
    v_16969 = qcdr(v_16969);
    stack[0] = v_16969;
    goto v_16835;
v_16851:
    goto v_16871;
v_16867:
    v_16970 = stack[-1];
    goto v_16868;
v_16869:
    v_16969 = stack[0];
    v_16969 = qcar(v_16969);
    goto v_16870;
v_16871:
    goto v_16867;
v_16868:
    goto v_16869;
v_16870:
    if (equal(v_16970, v_16969)) goto v_16865;
    else goto v_16866;
v_16865:
    v_16969 = stack[0];
    v_16969 = qcdr(v_16969);
    if (v_16969 == nil) goto v_16878;
    v_16969 = stack[0];
    v_16969 = qcdr(v_16969);
    v_16969 = qcar(v_16969);
    if (is_number(v_16969)) goto v_16882;
    else goto v_16878;
v_16882:
    goto v_16891;
v_16887:
    goto v_16888;
v_16889:
    goto v_16900;
v_16894:
    goto v_16895;
v_16896:
    v_16969 = stack[0];
    v_16969 = qcdr(v_16969);
    v_16969 = qcar(v_16969);
    v_16970 = add1(v_16969);
    env = stack[-3];
    goto v_16897;
v_16898:
    v_16969 = stack[0];
    v_16969 = qcdr(v_16969);
    v_16969 = qcdr(v_16969);
    goto v_16899;
v_16900:
    goto v_16894;
v_16895:
    goto v_16896;
v_16897:
    goto v_16898;
v_16899:
    v_16969 = list2star(stack[-1], v_16970, v_16969);
    env = stack[-3];
    goto v_16890;
v_16891:
    goto v_16887;
v_16888:
    goto v_16889;
v_16890:
    {
        LispObject v_16976 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_16976, v_16969);
    }
v_16878:
    goto v_16916;
v_16912:
    goto v_16913;
v_16914:
    goto v_16925;
v_16919:
    v_16971 = stack[-1];
    goto v_16920;
v_16921:
    v_16970 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_16922;
v_16923:
    v_16969 = stack[0];
    v_16969 = qcdr(v_16969);
    goto v_16924;
v_16925:
    goto v_16919;
v_16920:
    goto v_16921;
v_16922:
    goto v_16923;
v_16924:
    v_16969 = list2star(v_16971, v_16970, v_16969);
    env = stack[-3];
    goto v_16915;
v_16916:
    goto v_16912;
v_16913:
    goto v_16914;
v_16915:
    {
        LispObject v_16977 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_16977, v_16969);
    }
    goto v_16837;
v_16866:
    goto v_16937;
v_16933:
    v_16970 = stack[-1];
    goto v_16934;
v_16935:
    v_16969 = stack[0];
    v_16969 = qcar(v_16969);
    goto v_16936;
v_16937:
    goto v_16933;
v_16934:
    goto v_16935;
v_16936:
    fn = elt(env, 2); // ordp
    v_16969 = (*qfn2(fn))(fn, v_16970, v_16969);
    env = stack[-3];
    if (v_16969 == nil) goto v_16931;
    goto v_16946;
v_16942:
    goto v_16943;
v_16944:
    goto v_16953;
v_16949:
    v_16970 = stack[-1];
    goto v_16950;
v_16951:
    v_16969 = stack[0];
    goto v_16952;
v_16953:
    goto v_16949;
v_16950:
    goto v_16951;
v_16952:
    v_16969 = cons(v_16970, v_16969);
    env = stack[-3];
    goto v_16945;
v_16946:
    goto v_16942;
v_16943:
    goto v_16944;
v_16945:
    {
        LispObject v_16978 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_16978, v_16969);
    }
v_16931:
    goto v_16963;
v_16959:
    v_16969 = stack[0];
    v_16970 = qcar(v_16969);
    goto v_16960;
v_16961:
    v_16969 = stack[-2];
    goto v_16962;
v_16963:
    goto v_16959;
v_16960:
    goto v_16961;
v_16962:
    v_16969 = cons(v_16970, v_16969);
    env = stack[-3];
    stack[-2] = v_16969;
    v_16969 = stack[0];
    v_16969 = qcdr(v_16969);
    stack[0] = v_16969;
    goto v_16835;
v_16837:
    v_16969 = nil;
    return onevalue(v_16969);
}



// Code for evalvars

static LispObject CC_evalvars(LispObject env,
                         LispObject v_16829)
{
    env = qenv(env);
    LispObject v_16925, v_16926;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16829);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_16829;
// end of prologue
    stack[-2] = nil;
v_16834:
    v_16925 = stack[-1];
    if (v_16925 == nil) goto v_16837;
    else goto v_16838;
v_16837:
    v_16925 = stack[-2];
    {
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(fn, v_16925);
    }
v_16838:
    v_16925 = stack[-1];
    v_16925 = qcar(v_16925);
    if (!consp(v_16925)) goto v_16846;
    else goto v_16847;
v_16846:
    v_16925 = lisp_true;
    goto v_16845;
v_16847:
    goto v_16858;
v_16854:
    v_16925 = stack[-1];
    v_16925 = qcar(v_16925);
    v_16926 = qcar(v_16925);
    goto v_16855;
v_16856:
    v_16925 = elt(env, 1); // intfn
    goto v_16857;
v_16858:
    goto v_16854;
v_16855:
    goto v_16856;
v_16857:
    v_16925 = Lflagp(nil, v_16926, v_16925);
    env = stack[-3];
    goto v_16845;
    v_16925 = nil;
v_16845:
    if (v_16925 == nil) goto v_16843;
    goto v_16868;
v_16864:
    v_16925 = stack[-1];
    v_16926 = qcar(v_16925);
    goto v_16865;
v_16866:
    v_16925 = stack[-2];
    goto v_16867;
v_16868:
    goto v_16864;
v_16865:
    goto v_16866;
v_16867:
    v_16925 = cons(v_16926, v_16925);
    env = stack[-3];
    stack[-2] = v_16925;
    v_16925 = stack[-1];
    v_16925 = qcdr(v_16925);
    stack[-1] = v_16925;
    goto v_16834;
v_16843:
    goto v_16881;
v_16877:
    v_16925 = stack[-1];
    v_16925 = qcar(v_16925);
    v_16925 = qcar(v_16925);
    if (!symbolp(v_16925)) v_16926 = nil;
    else { v_16926 = qfastgets(v_16925);
           if (v_16926 != nil) { v_16926 = elt(v_16926, 2); // rtype
#ifdef RECORD_GET
             if (v_16926 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_16926 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_16926 == SPID_NOPROP) v_16926 = nil; }}
#endif
    goto v_16878;
v_16879:
    v_16925 = elt(env, 2); // setelemfn
    goto v_16880;
v_16881:
    goto v_16877;
v_16878:
    goto v_16879;
v_16880:
    v_16925 = get(v_16926, v_16925);
    env = stack[-3];
    if (v_16925 == nil) goto v_16875;
    goto v_16894;
v_16888:
    v_16925 = stack[-1];
    v_16925 = qcar(v_16925);
    stack[0] = qcar(v_16925);
    goto v_16889;
v_16890:
    v_16925 = stack[-1];
    v_16925 = qcar(v_16925);
    v_16925 = qcdr(v_16925);
    fn = elt(env, 4); // revlis_without_mode
    v_16926 = (*qfn1(fn))(fn, v_16925);
    env = stack[-3];
    goto v_16891;
v_16892:
    v_16925 = stack[-2];
    goto v_16893;
v_16894:
    goto v_16888;
v_16889:
    goto v_16890;
v_16891:
    goto v_16892;
v_16893:
    v_16925 = acons(stack[0], v_16926, v_16925);
    env = stack[-3];
    stack[-2] = v_16925;
    v_16925 = stack[-1];
    v_16925 = qcdr(v_16925);
    stack[-1] = v_16925;
    goto v_16834;
v_16875:
    goto v_16914;
v_16908:
    v_16925 = stack[-1];
    v_16925 = qcar(v_16925);
    stack[0] = qcar(v_16925);
    goto v_16909;
v_16910:
    v_16925 = stack[-1];
    v_16925 = qcar(v_16925);
    v_16925 = qcdr(v_16925);
    fn = elt(env, 5); // revlis
    v_16926 = (*qfn1(fn))(fn, v_16925);
    env = stack[-3];
    goto v_16911;
v_16912:
    v_16925 = stack[-2];
    goto v_16913;
v_16914:
    goto v_16908;
v_16909:
    goto v_16910;
v_16911:
    goto v_16912;
v_16913:
    v_16925 = acons(stack[0], v_16926, v_16925);
    env = stack[-3];
    stack[-2] = v_16925;
    v_16925 = stack[-1];
    v_16925 = qcdr(v_16925);
    stack[-1] = v_16925;
    goto v_16834;
    v_16925 = nil;
    return onevalue(v_16925);
}



// Code for vdp2a

static LispObject CC_vdp2a(LispObject env,
                         LispObject v_16829)
{
    env = qenv(env);
    LispObject v_16837;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16837 = v_16829;
// end of prologue
    v_16837 = qcdr(v_16837);
    v_16837 = qcdr(v_16837);
    v_16837 = qcdr(v_16837);
    v_16837 = qcar(v_16837);
    {
        fn = elt(env, 1); // dip2a
        return (*qfn1(fn))(fn, v_16837);
    }
}



// Code for gfplusn

static LispObject CC_gfplusn(LispObject env,
                         LispObject v_16829, LispObject v_16830)
{
    env = qenv(env);
    LispObject v_16874, v_16875;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16830,v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16829,v_16830);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16830;
    stack[-1] = v_16829;
// end of prologue
    v_16874 = stack[-1];
    v_16874 = qcar(v_16874);
    if (!consp(v_16874)) goto v_16834;
    else goto v_16835;
v_16834:
    goto v_16843;
v_16839:
    v_16875 = stack[-1];
    goto v_16840;
v_16841:
    v_16874 = stack[0];
    goto v_16842;
v_16843:
    goto v_16839;
v_16840:
    goto v_16841;
v_16842:
    {
        fn = elt(env, 1); // gffplus
        return (*qfn2(fn))(fn, v_16875, v_16874);
    }
v_16835:
    goto v_16853;
v_16849:
    goto v_16859;
v_16855:
    v_16874 = stack[-1];
    v_16875 = qcar(v_16874);
    goto v_16856;
v_16857:
    v_16874 = stack[0];
    v_16874 = qcar(v_16874);
    goto v_16858;
v_16859:
    goto v_16855;
v_16856:
    goto v_16857;
v_16858:
    fn = elt(env, 2); // plus!:
    stack[-2] = (*qfn2(fn))(fn, v_16875, v_16874);
    env = stack[-3];
    goto v_16850;
v_16851:
    goto v_16869;
v_16865:
    v_16874 = stack[-1];
    v_16875 = qcdr(v_16874);
    goto v_16866;
v_16867:
    v_16874 = stack[0];
    v_16874 = qcdr(v_16874);
    goto v_16868;
v_16869:
    goto v_16865;
v_16866:
    goto v_16867;
v_16868:
    fn = elt(env, 2); // plus!:
    v_16874 = (*qfn2(fn))(fn, v_16875, v_16874);
    goto v_16852;
v_16853:
    goto v_16849;
v_16850:
    goto v_16851;
v_16852:
    {
        LispObject v_16879 = stack[-2];
        return cons(v_16879, v_16874);
    }
    v_16874 = nil;
    return onevalue(v_16874);
}



// Code for clogsq!*

static LispObject CC_clogsqH(LispObject env,
                         LispObject v_16829)
{
    env = qenv(env);
    LispObject v_16847, v_16848;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16829);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_16847 = v_16829;
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
    v_16848 = lisp_true;
    qvalue(elt(env, 3)) = v_16848; // !*expandlogs
    qvalue(elt(env, 1)) = v_16848; // !*div
    v_16848 = lisp_true;
// Binding !*uncached
// FLUIDBIND: reloadenv=4 litvec-offset=4 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 4, 0);
    qvalue(elt(env, 4)) = v_16848; // !*uncached
    fn = elt(env, 5); // prepsq
    v_16847 = (*qfn1(fn))(fn, v_16847);
    env = stack[-4];
    fn = elt(env, 6); // simp
    v_16847 = (*qfn1(fn))(fn, v_16847);
    env = stack[-4];
    ;}  // end of a binding scope
    v_16848 = nil;
    qvalue(elt(env, 3)) = v_16848; // !*expandlogs
    fn = elt(env, 7); // prepsq!*
    v_16847 = (*qfn1(fn))(fn, v_16847);
    env = stack[-4];
    fn = elt(env, 8); // comblog
    v_16847 = (*qfn1(fn))(fn, v_16847);
    env = stack[-4];
    fn = elt(env, 9); // simp!*
    v_16847 = (*qfn1(fn))(fn, v_16847);
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_16847);
}



// Code for assert_stat!-parse

static LispObject CC_assert_statKparse(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16919, v_16920, v_16921;
    LispObject fn;
    argcheck(nargs, 0, "assert_stat-parse");
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
    fn = elt(env, 8); // scan
    v_16919 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-2] = v_16919;
    goto v_16844;
v_16840:
    fn = elt(env, 8); // scan
    v_16920 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_16841;
v_16842:
    v_16919 = elt(env, 1); // !*colon!*
    goto v_16843;
v_16844:
    goto v_16840;
v_16841:
    goto v_16842;
v_16843:
    if (v_16920 == v_16919) goto v_16839;
    goto v_16853;
v_16849:
    v_16920 = elt(env, 2); // "expecting ':' in assert but found"
    goto v_16850;
v_16851:
    v_16919 = qvalue(elt(env, 3)); // cursym!*
    goto v_16852;
v_16853:
    goto v_16849;
v_16850:
    goto v_16851;
v_16852:
    v_16919 = list2(v_16920, v_16919);
    env = stack[-3];
    fn = elt(env, 9); // rederr
    v_16919 = (*qfn1(fn))(fn, v_16919);
    env = stack[-3];
    goto v_16837;
v_16839:
v_16837:
    fn = elt(env, 10); // assert_stat1
    v_16919 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-1] = v_16919;
    goto v_16869;
v_16865:
    fn = elt(env, 8); // scan
    v_16920 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_16866;
v_16867:
    v_16919 = elt(env, 4); // difference
    goto v_16868;
v_16869:
    goto v_16865;
v_16866:
    goto v_16867;
v_16868:
    if (v_16920 == v_16919) goto v_16864;
    v_16919 = lisp_true;
    goto v_16862;
v_16864:
    goto v_16880;
v_16876:
    fn = elt(env, 8); // scan
    v_16920 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_16877;
v_16878:
    v_16919 = elt(env, 5); // greaterp
    goto v_16879;
v_16880:
    goto v_16876;
v_16877:
    goto v_16878;
v_16879:
    v_16919 = Lneq(nil, v_16920, v_16919);
    env = stack[-3];
    goto v_16862;
    v_16919 = nil;
v_16862:
    if (v_16919 == nil) goto v_16860;
    goto v_16889;
v_16885:
    v_16920 = elt(env, 6); // "expecting '->' in assert but found"
    goto v_16886;
v_16887:
    v_16919 = qvalue(elt(env, 3)); // cursym!*
    goto v_16888;
v_16889:
    goto v_16885;
v_16886:
    goto v_16887;
v_16888:
    v_16919 = list2(v_16920, v_16919);
    env = stack[-3];
    fn = elt(env, 9); // rederr
    v_16919 = (*qfn1(fn))(fn, v_16919);
    env = stack[-3];
    goto v_16858;
v_16860:
v_16858:
    fn = elt(env, 8); // scan
    v_16919 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[0] = v_16919;
    fn = elt(env, 8); // scan
    v_16919 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    if (!symbolp(v_16919)) v_16919 = nil;
    else { v_16919 = qfastgets(v_16919);
           if (v_16919 != nil) { v_16919 = elt(v_16919, 55); // delim
#ifdef RECORD_GET
             if (v_16919 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v_16919 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v_16919 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v_16919 == SPID_NOPROP) v_16919 = nil; else v_16919 = lisp_true; }}
#endif
    if (v_16919 == nil) goto v_16895;
    else goto v_16896;
v_16895:
    goto v_16905;
v_16901:
    v_16920 = elt(env, 7); // "expecting end of assert but found"
    goto v_16902;
v_16903:
    v_16919 = qvalue(elt(env, 3)); // cursym!*
    goto v_16904;
v_16905:
    goto v_16901;
v_16902:
    goto v_16903;
v_16904:
    v_16919 = list2(v_16920, v_16919);
    env = stack[-3];
    fn = elt(env, 9); // rederr
    v_16919 = (*qfn1(fn))(fn, v_16919);
    goto v_16894;
v_16896:
v_16894:
    goto v_16915;
v_16909:
    v_16921 = stack[-2];
    goto v_16910;
v_16911:
    v_16920 = stack[-1];
    goto v_16912;
v_16913:
    v_16919 = stack[0];
    goto v_16914;
v_16915:
    goto v_16909;
v_16910:
    goto v_16911;
v_16912:
    goto v_16913;
v_16914:
    return list3(v_16921, v_16920, v_16919);
    return onevalue(v_16919);
}



// Code for mv!-pow!-!>

static LispObject CC_mvKpowKS(LispObject env,
                         LispObject v_16829, LispObject v_16830)
{
    env = qenv(env);
    LispObject v_16868, v_16869, v_16870, v_16871;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16869 = v_16830;
    v_16870 = v_16829;
// end of prologue
v_16834:
    v_16868 = v_16870;
    if (v_16868 == nil) goto v_16837;
    else goto v_16838;
v_16837:
    v_16868 = nil;
    goto v_16833;
v_16838:
    goto v_16847;
v_16843:
    v_16868 = v_16870;
    v_16871 = qcar(v_16868);
    goto v_16844;
v_16845:
    v_16868 = v_16869;
    v_16868 = qcar(v_16868);
    goto v_16846;
v_16847:
    goto v_16843;
v_16844:
    goto v_16845;
v_16846:
    if (equal(v_16871, v_16868)) goto v_16841;
    else goto v_16842;
v_16841:
    v_16868 = v_16870;
    v_16868 = qcdr(v_16868);
    v_16870 = v_16868;
    v_16868 = v_16869;
    v_16868 = qcdr(v_16868);
    v_16869 = v_16868;
    goto v_16834;
v_16842:
    goto v_16863;
v_16859:
    v_16868 = v_16870;
    v_16868 = qcar(v_16868);
    goto v_16860;
v_16861:
    v_16869 = qcar(v_16869);
    goto v_16862;
v_16863:
    goto v_16859;
v_16860:
    goto v_16861;
v_16862:
        return Lgreaterp(nil, v_16868, v_16869);
    v_16868 = nil;
v_16833:
    return onevalue(v_16868);
}



// Code for symbol

static LispObject CC_symbol(LispObject env,
                         LispObject v_16829)
{
    env = qenv(env);
    LispObject v_16902, v_16903, v_16904;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16829);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_16903 = v_16829;
// end of prologue
    v_16902 = qvalue(elt(env, 1)); // !*utf8
    if (v_16902 == nil) goto v_16834;
    v_16902 = qvalue(elt(env, 2)); // !*utf82d
    if (v_16902 == nil) goto v_16839;
    goto v_16849;
v_16845:
    v_16904 = v_16903;
    goto v_16846;
v_16847:
    v_16902 = elt(env, 3); // utf8_2d!-symbol!-character
    goto v_16848;
v_16849:
    goto v_16845;
v_16846:
    goto v_16847;
v_16848:
    v_16902 = get(v_16904, v_16902);
    env = stack[0];
    if (v_16902 == nil) goto v_16843;
    else goto v_16842;
v_16843:
    goto v_16860;
v_16856:
    v_16904 = v_16903;
    goto v_16857;
v_16858:
    v_16902 = elt(env, 4); // utf8_symbol!-character
    goto v_16859;
v_16860:
    goto v_16856;
v_16857:
    goto v_16858;
v_16859:
    v_16902 = get(v_16904, v_16902);
    env = stack[0];
    if (v_16902 == nil) goto v_16854;
    else goto v_16853;
v_16854:
    goto v_16868;
v_16864:
    v_16902 = v_16903;
    goto v_16865;
v_16866:
    v_16903 = elt(env, 5); // symbol!-character
    goto v_16867;
v_16868:
    goto v_16864;
v_16865:
    goto v_16866;
v_16867:
    return get(v_16902, v_16903);
v_16853:
v_16842:
    goto v_16837;
v_16839:
    goto v_16881;
v_16877:
    v_16904 = v_16903;
    goto v_16878;
v_16879:
    v_16902 = elt(env, 4); // utf8_symbol!-character
    goto v_16880;
v_16881:
    goto v_16877;
v_16878:
    goto v_16879;
v_16880:
    v_16902 = get(v_16904, v_16902);
    env = stack[0];
    if (v_16902 == nil) goto v_16875;
    else goto v_16874;
v_16875:
    goto v_16889;
v_16885:
    v_16902 = v_16903;
    goto v_16886;
v_16887:
    v_16903 = elt(env, 5); // symbol!-character
    goto v_16888;
v_16889:
    goto v_16885;
v_16886:
    goto v_16887;
v_16888:
    return get(v_16902, v_16903);
v_16874:
    goto v_16837;
    v_16902 = nil;
v_16837:
    goto v_16832;
v_16834:
    goto v_16899;
v_16895:
    v_16902 = v_16903;
    goto v_16896;
v_16897:
    v_16903 = elt(env, 5); // symbol!-character
    goto v_16898;
v_16899:
    goto v_16895;
v_16896:
    goto v_16897;
v_16898:
    return get(v_16902, v_16903);
    v_16902 = nil;
v_16832:
    return onevalue(v_16902);
}



// Code for red!=hide

static LispObject CC_redMhide(LispObject env,
                         LispObject v_16829)
{
    env = qenv(env);
    LispObject v_16905, v_16906;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16829);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_16905 = v_16829;
// end of prologue
    stack[-5] = v_16905;
    v_16905 = stack[-5];
    if (v_16905 == nil) goto v_16840;
    else goto v_16841;
v_16840:
    v_16905 = nil;
    goto v_16835;
v_16841:
    v_16905 = stack[-5];
    v_16905 = qcar(v_16905);
    stack[-1] = v_16905;
    goto v_16853;
v_16849:
    goto v_16859;
v_16855:
    stack[0] = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_16856;
v_16857:
    v_16905 = stack[-1];
    v_16905 = qcar(v_16905);
    fn = elt(env, 1); // mo_neg
    v_16905 = (*qfn1(fn))(fn, v_16905);
    env = stack[-6];
    goto v_16858;
v_16859:
    goto v_16855;
v_16856:
    goto v_16857;
v_16858:
    fn = elt(env, 2); // mo_times_ei
    v_16906 = (*qfn2(fn))(fn, stack[0], v_16905);
    env = stack[-6];
    goto v_16850;
v_16851:
    v_16905 = stack[-1];
    v_16905 = qcdr(v_16905);
    goto v_16852;
v_16853:
    goto v_16849;
v_16850:
    goto v_16851;
v_16852:
    v_16905 = cons(v_16906, v_16905);
    env = stack[-6];
    v_16905 = ncons(v_16905);
    env = stack[-6];
    stack[-3] = v_16905;
    stack[-4] = v_16905;
v_16836:
    v_16905 = stack[-5];
    v_16905 = qcdr(v_16905);
    stack[-5] = v_16905;
    v_16905 = stack[-5];
    if (v_16905 == nil) goto v_16870;
    else goto v_16871;
v_16870:
    v_16905 = stack[-4];
    goto v_16835;
v_16871:
    goto v_16879;
v_16875:
    stack[-2] = stack[-3];
    goto v_16876;
v_16877:
    v_16905 = stack[-5];
    v_16905 = qcar(v_16905);
    stack[-1] = v_16905;
    goto v_16890;
v_16886:
    goto v_16896;
v_16892:
    stack[0] = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_16893;
v_16894:
    v_16905 = stack[-1];
    v_16905 = qcar(v_16905);
    fn = elt(env, 1); // mo_neg
    v_16905 = (*qfn1(fn))(fn, v_16905);
    env = stack[-6];
    goto v_16895;
v_16896:
    goto v_16892;
v_16893:
    goto v_16894;
v_16895:
    fn = elt(env, 2); // mo_times_ei
    v_16906 = (*qfn2(fn))(fn, stack[0], v_16905);
    env = stack[-6];
    goto v_16887;
v_16888:
    v_16905 = stack[-1];
    v_16905 = qcdr(v_16905);
    goto v_16889;
v_16890:
    goto v_16886;
v_16887:
    goto v_16888;
v_16889:
    v_16905 = cons(v_16906, v_16905);
    env = stack[-6];
    v_16905 = ncons(v_16905);
    env = stack[-6];
    goto v_16878;
v_16879:
    goto v_16875;
v_16876:
    goto v_16877;
v_16878:
    v_16905 = Lrplacd(nil, stack[-2], v_16905);
    env = stack[-6];
    v_16905 = stack[-3];
    v_16905 = qcdr(v_16905);
    stack[-3] = v_16905;
    goto v_16836;
v_16835:
    return onevalue(v_16905);
}



// Code for general!-ordered!-gcd!-mod!-p

static LispObject CC_generalKorderedKgcdKmodKp(LispObject env,
                         LispObject v_16829, LispObject v_16830)
{
    env = qenv(env);
    LispObject v_16909, v_16910;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16830,v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16829,v_16830);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16830;
    stack[-1] = v_16829;
// end of prologue
    v_16909 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_16909;
v_16835:
    goto v_16842;
v_16838:
    v_16910 = stack[-1];
    goto v_16839;
v_16840:
    v_16909 = stack[0];
    goto v_16841;
v_16842:
    goto v_16838;
v_16839:
    goto v_16840;
v_16841:
    fn = elt(env, 2); // general!-reduce!-degree!-mod!-p
    v_16909 = (*qfn2(fn))(fn, v_16910, v_16909);
    env = stack[-3];
    stack[-1] = v_16909;
    v_16909 = stack[-1];
    if (v_16909 == nil) goto v_16847;
    else goto v_16848;
v_16847:
    v_16909 = stack[0];
    {
        fn = elt(env, 3); // general!-monic!-mod!-p
        return (*qfn1(fn))(fn, v_16909);
    }
v_16848:
    v_16909 = stack[-2];
    v_16909 = add1(v_16909);
    env = stack[-3];
    stack[-2] = v_16909;
    v_16909 = stack[-1];
    if (!consp(v_16909)) goto v_16860;
    else goto v_16861;
v_16860:
    v_16909 = lisp_true;
    goto v_16859;
v_16861:
    v_16909 = stack[-1];
    v_16909 = qcar(v_16909);
    v_16909 = (consp(v_16909) ? nil : lisp_true);
    goto v_16859;
    v_16909 = nil;
v_16859:
    if (v_16909 == nil) goto v_16857;
    goto v_16874;
v_16870:
    v_16910 = qvalue(elt(env, 1)); // reduction!-count
    goto v_16871;
v_16872:
    v_16909 = stack[-2];
    goto v_16873;
v_16874:
    goto v_16870;
v_16871:
    goto v_16872;
v_16873:
    v_16909 = plus2(v_16910, v_16909);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_16909; // reduction!-count
    v_16909 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16834;
v_16857:
    goto v_16885;
v_16881:
    v_16909 = stack[-1];
    v_16909 = qcar(v_16909);
    v_16909 = qcar(v_16909);
    v_16910 = qcdr(v_16909);
    goto v_16882;
v_16883:
    v_16909 = stack[0];
    v_16909 = qcar(v_16909);
    v_16909 = qcar(v_16909);
    v_16909 = qcdr(v_16909);
    goto v_16884;
v_16885:
    goto v_16881;
v_16882:
    goto v_16883;
v_16884:
    v_16909 = (LispObject)lessp2(v_16910, v_16909);
    v_16909 = v_16909 ? lisp_true : nil;
    env = stack[-3];
    if (v_16909 == nil) goto v_16879;
    goto v_16902;
v_16898:
    v_16910 = qvalue(elt(env, 1)); // reduction!-count
    goto v_16899;
v_16900:
    v_16909 = stack[-2];
    goto v_16901;
v_16902:
    goto v_16898;
v_16899:
    goto v_16900;
v_16901:
    v_16909 = plus2(v_16910, v_16909);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_16909; // reduction!-count
    v_16909 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_16909;
    v_16909 = stack[-1];
    v_16910 = v_16909;
    v_16909 = stack[0];
    stack[-1] = v_16909;
    v_16909 = v_16910;
    stack[0] = v_16909;
    goto v_16855;
v_16879:
v_16855:
    goto v_16835;
v_16834:
    return onevalue(v_16909);
}



// Code for not_included

static LispObject CC_not_included(LispObject env,
                         LispObject v_16829, LispObject v_16830)
{
    env = qenv(env);
    LispObject v_16883, v_16884, v_16885, v_16886, v_16887;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16885 = v_16830;
    v_16886 = v_16829;
// end of prologue
    v_16883 = lisp_true;
    v_16887 = v_16883;
v_16838:
    v_16883 = v_16886;
    if (v_16883 == nil) goto v_16841;
    v_16883 = v_16887;
    if (v_16883 == nil) goto v_16841;
    goto v_16842;
v_16841:
    goto v_16837;
v_16842:
    v_16883 = v_16885;
    v_16887 = v_16883;
v_16851:
    v_16883 = v_16887;
    if (v_16883 == nil) goto v_16854;
    goto v_16863;
v_16859:
    v_16883 = v_16886;
    v_16884 = qcar(v_16883);
    goto v_16860;
v_16861:
    v_16883 = v_16887;
    v_16883 = qcar(v_16883);
    goto v_16862;
v_16863:
    goto v_16859;
v_16860:
    goto v_16861;
v_16862:
    if (equal(v_16884, v_16883)) goto v_16854;
    goto v_16855;
v_16854:
    goto v_16850;
v_16855:
    v_16883 = v_16887;
    v_16883 = qcdr(v_16883);
    v_16887 = v_16883;
    goto v_16851;
v_16850:
    v_16883 = v_16886;
    v_16883 = qcdr(v_16883);
    v_16886 = v_16883;
    goto v_16838;
v_16837:
    v_16883 = v_16887;
    if (v_16883 == nil) goto v_16877;
    v_16883 = nil;
    goto v_16875;
v_16877:
    v_16883 = lisp_true;
    goto v_16875;
    v_16883 = nil;
v_16875:
    return onevalue(v_16883);
}



// Code for lex_basic_token

static LispObject CC_lex_basic_token(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18068, v_18069, v_18070;
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
v_16828:
    stack[-4] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    v_18068 = qvalue(elt(env, 1)); // lex_peeked
    if (v_18068 == nil) goto v_16838;
    v_18068 = qvalue(elt(env, 1)); // lex_peeked
    stack[-4] = v_18068;
    v_18068 = qvalue(elt(env, 2)); // lex_peeked_yylval
    qvalue(elt(env, 3)) = v_18068; // yylval
    v_18068 = qvalue(elt(env, 4)); // lex_peeked_escaped
    qvalue(elt(env, 5)) = v_18068; // lex_escaped
    v_18068 = nil;
    qvalue(elt(env, 4)) = v_18068; // lex_peeked_escaped
    qvalue(elt(env, 2)) = v_18068; // lex_peeked_yylval
    qvalue(elt(env, 1)) = v_18068; // lex_peeked
    v_18068 = stack[-4];
    goto v_16834;
v_16838:
    v_18068 = nil;
    qvalue(elt(env, 5)) = v_18068; // lex_escaped
v_16848:
    goto v_16861;
v_16857:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_16858;
v_16859:
    v_18068 = elt(env, 7); // ! 
    goto v_16860;
v_16861:
    goto v_16857;
v_16858:
    goto v_16859;
v_16860:
    if (v_18069 == v_18068) goto v_16855;
    else goto v_16856;
v_16855:
    v_18068 = lisp_true;
    goto v_16854;
v_16856:
    goto v_16875;
v_16871:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_16872;
v_16873:
    v_18068 = qvalue(elt(env, 8)); // !$eol!$
    goto v_16874;
v_16875:
    goto v_16871;
v_16872:
    goto v_16873;
v_16874:
    if (equal(v_18069, v_18068)) goto v_16869;
    else goto v_16870;
v_16869:
    v_18068 = lisp_true;
    goto v_16868;
v_16870:
    goto v_16889;
v_16885:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_16886;
v_16887:
    v_18068 = elt(env, 9); // !	
    goto v_16888;
v_16889:
    goto v_16885;
v_16886:
    goto v_16887;
v_16888:
    if (v_18069 == v_18068) goto v_16883;
    else goto v_16884;
v_16883:
    v_18068 = lisp_true;
    goto v_16882;
v_16884:
    v_18068 = qvalue(elt(env, 6)); // lex_char
    fn = elt(env, 46); // lex_start_line_comment
    v_18068 = (*qfn1(fn))(fn, v_18068);
    env = stack[-5];
    if (v_18068 == nil) goto v_16900;
    else goto v_16901;
v_16900:
    v_18068 = nil;
    goto v_16899;
v_16901:
    fn = elt(env, 47); // lex_skip_line_comment
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_16899;
    v_18068 = nil;
v_16899:
    if (v_18068 == nil) goto v_16897;
    else goto v_16896;
v_16897:
    v_18068 = qvalue(elt(env, 6)); // lex_char
    fn = elt(env, 48); // lex_start_block_comment
    v_18068 = (*qfn1(fn))(fn, v_18068);
    env = stack[-5];
    if (v_18068 == nil) goto v_16910;
    else goto v_16911;
v_16910:
    v_18068 = nil;
    goto v_16909;
v_16911:
    fn = elt(env, 49); // lex_skip_block_comment
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_16909;
    v_18068 = nil;
v_16909:
v_16896:
    goto v_16882;
    v_18068 = nil;
v_16882:
    goto v_16868;
    v_18068 = nil;
v_16868:
    goto v_16854;
    v_18068 = nil;
v_16854:
    if (v_18068 == nil) goto v_16851;
    else goto v_16852;
v_16851:
    goto v_16847;
v_16852:
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_16848;
v_16847:
    goto v_16928;
v_16924:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_16925;
v_16926:
    v_18068 = qvalue(elt(env, 10)); // !$eof!$
    goto v_16927;
v_16928:
    goto v_16924;
v_16925:
    goto v_16926;
v_16927:
    if (equal(v_18069, v_18068)) goto v_16922;
    else goto v_16923;
v_16922:
    v_18068 = qvalue(elt(env, 6)); // lex_char
    qvalue(elt(env, 3)) = v_18068; // yylval
    v_18068 = qvalue(elt(env, 11)); // lex_eof_code
    goto v_16834;
v_16923:
    v_18068 = qvalue(elt(env, 6)); // lex_char
    fn = elt(env, 51); // lexer_word_starter
    v_18068 = (*qfn1(fn))(fn, v_18068);
    env = stack[-5];
    if (v_18068 == nil) goto v_16937;
    else goto v_16935;
v_16937:
    goto v_16949;
v_16945:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_16946;
v_16947:
    v_18068 = elt(env, 12); // !!
    goto v_16948;
v_16949:
    goto v_16945;
v_16946:
    goto v_16947;
v_16948:
    if (v_18069 == v_18068) goto v_16943;
    else goto v_16944;
v_16943:
    goto v_16962;
v_16958:
    v_18069 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_16959;
v_16960:
    v_18068 = (LispObject)524288+TAG_FIXNUM; // 32768
    goto v_16961;
v_16962:
    goto v_16958;
v_16959:
    goto v_16960;
v_16961:
    fn = elt(env, 52); // land
    v_18068 = (*qfn2(fn))(fn, v_18069, v_18068);
    env = stack[-5];
    v_18068 = (LispObject)zerop(v_18068);
    v_18068 = v_18068 ? lisp_true : nil;
    env = stack[-5];
    if (v_18068 == nil) goto v_16954;
    else goto v_16955;
v_16954:
    v_18069 = nil;
    v_18068 = nil;
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=14 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 14, -1);
    qvalue(elt(env, 14)) = v_18069; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 15, 0);
    qvalue(elt(env, 15)) = v_18068; // !*lower
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    v_18068 = lisp_true;
    qvalue(elt(env, 5)) = v_18068; // lex_escaped
    goto v_16953;
v_16955:
    v_18068 = nil;
    goto v_16953;
    v_18068 = nil;
v_16953:
    goto v_16942;
v_16944:
    v_18068 = nil;
    goto v_16942;
    v_18068 = nil;
v_16942:
    if (v_18068 == nil) goto v_16940;
    else goto v_16935;
v_16940:
    goto v_16936;
v_16935:
    goto v_16982;
v_16978:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_16979;
v_16980:
    v_18068 = stack[-4];
    goto v_16981;
v_16982:
    goto v_16978;
v_16979:
    goto v_16980;
v_16981:
    v_18068 = cons(v_18069, v_18068);
    env = stack[-5];
    stack[-4] = v_18068;
v_16987:
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    fn = elt(env, 53); // lexer_word_continues
    v_18068 = (*qfn1(fn))(fn, v_18068);
    env = stack[-5];
    if (v_18068 == nil) goto v_16992;
    else goto v_16991;
v_16992:
    goto v_17004;
v_17000:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17001;
v_17002:
    v_18068 = elt(env, 12); // !!
    goto v_17003;
v_17004:
    goto v_17000;
v_17001:
    goto v_17002;
v_17003:
    if (v_18069 == v_18068) goto v_16998;
    else goto v_16999;
v_16998:
    goto v_17017;
v_17013:
    v_18069 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17014;
v_17015:
    v_18068 = (LispObject)524288+TAG_FIXNUM; // 32768
    goto v_17016;
v_17017:
    goto v_17013;
v_17014:
    goto v_17015;
v_17016:
    fn = elt(env, 52); // land
    v_18068 = (*qfn2(fn))(fn, v_18069, v_18068);
    env = stack[-5];
    v_18068 = (LispObject)zerop(v_18068);
    v_18068 = v_18068 ? lisp_true : nil;
    env = stack[-5];
    if (v_18068 == nil) goto v_17009;
    else goto v_17010;
v_17009:
    v_18069 = nil;
    v_18068 = nil;
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=14 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 14, -1);
    qvalue(elt(env, 14)) = v_18069; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 15, 0);
    qvalue(elt(env, 15)) = v_18068; // !*lower
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    v_18068 = lisp_true;
    qvalue(elt(env, 5)) = v_18068; // lex_escaped
    goto v_17008;
v_17010:
    v_18068 = nil;
    goto v_17008;
    v_18068 = nil;
v_17008:
    goto v_16997;
v_16999:
    v_18068 = nil;
    goto v_16997;
    v_18068 = nil;
v_16997:
    if (v_18068 == nil) goto v_16995;
    else goto v_16991;
v_16995:
    goto v_16986;
v_16991:
    goto v_17038;
v_17034:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17035;
v_17036:
    v_18068 = stack[-4];
    goto v_17037;
v_17038:
    goto v_17034;
v_17035:
    goto v_17036;
v_17037:
    v_18068 = cons(v_18069, v_18068);
    env = stack[-5];
    stack[-4] = v_18068;
    goto v_16987;
v_16986:
    v_18068 = stack[-4];
    v_18068 = Lnreverse(nil, v_18068);
    env = stack[-5];
    stack[-4] = v_18068;
    fn = elt(env, 54); // list2widestring
    v_18068 = (*qfn1(fn))(fn, v_18068);
    env = stack[-5];
    v_18068 = Lintern(nil, v_18068);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18068; // yylval
    goto v_17057;
v_17053:
    v_18069 = qvalue(elt(env, 3)); // yylval
    goto v_17054;
v_17055:
    v_18068 = elt(env, 16); // comment
    goto v_17056;
v_17057:
    goto v_17053;
v_17054:
    goto v_17055;
v_17056:
    if (v_18069 == v_18068) goto v_17051;
    else goto v_17052;
v_17051:
    goto v_17070;
v_17066:
    v_18069 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17067;
v_17068:
    v_18068 = (LispObject)4194304+TAG_FIXNUM; // 262144
    goto v_17069;
v_17070:
    goto v_17066;
v_17067:
    goto v_17068;
v_17069:
    fn = elt(env, 52); // land
    v_18068 = (*qfn2(fn))(fn, v_18069, v_18068);
    env = stack[-5];
    v_18068 = (LispObject)zerop(v_18068);
    v_18068 = v_18068 ? lisp_true : nil;
    env = stack[-5];
    if (v_18068 == nil) goto v_17062;
    else goto v_17063;
v_17062:
    v_18068 = qvalue(elt(env, 5)); // lex_escaped
    v_18068 = (v_18068 == nil ? lisp_true : nil);
    goto v_17061;
v_17063:
    v_18068 = nil;
    goto v_17061;
    v_18068 = nil;
v_17061:
    goto v_17050;
v_17052:
    v_18068 = nil;
    goto v_17050;
    v_18068 = nil;
v_17050:
    if (v_18068 == nil) goto v_17048;
v_17083:
    goto v_17096;
v_17092:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17093;
v_17094:
    v_18068 = elt(env, 17); // !;
    goto v_17095;
v_17096:
    goto v_17092;
v_17093:
    goto v_17094;
v_17095:
    if (v_18069 == v_18068) goto v_17090;
    else goto v_17091;
v_17090:
    v_18068 = lisp_true;
    goto v_17089;
v_17091:
    goto v_17106;
v_17102:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17103;
v_17104:
    v_18068 = elt(env, 18); // !$
    goto v_17105;
v_17106:
    goto v_17102;
v_17103:
    goto v_17104;
v_17105:
    v_18068 = (v_18069 == v_18068 ? lisp_true : nil);
    goto v_17089;
    v_18068 = nil;
v_17089:
    if (v_18068 == nil) goto v_17087;
    goto v_17082;
v_17087:
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17083;
v_17082:
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_16828;
v_17048:
    v_18068 = qvalue(elt(env, 5)); // lex_escaped
    if (v_18068 == nil) goto v_17120;
    else goto v_17121;
v_17120:
    goto v_17128;
v_17124:
    v_18069 = qvalue(elt(env, 3)); // yylval
    goto v_17125;
v_17126:
    v_18068 = elt(env, 19); // lex_code
    goto v_17127;
v_17128:
    goto v_17124;
v_17125:
    goto v_17126;
v_17127:
    v_18068 = get(v_18069, v_18068);
    env = stack[-5];
    stack[-3] = v_18068;
    goto v_17119;
v_17121:
    v_18068 = nil;
    goto v_17119;
    v_18068 = nil;
v_17119:
    if (v_18068 == nil) goto v_17117;
    v_18068 = stack[-3];
    goto v_16834;
v_17117:
    goto v_17146;
v_17142:
    v_18069 = stack[-4];
    goto v_17143;
v_17144:
    v_18068 = elt(env, 20); // !'
    goto v_17145;
v_17146:
    goto v_17142;
v_17143:
    goto v_17144;
v_17145:
    if (!consp(v_18069)) goto v_17140;
    v_18069 = qcar(v_18069);
    if (v_18069 == v_18068) goto v_17139;
    else goto v_17140;
v_17139:
    v_18068 = lisp_true;
    goto v_17138;
v_17140:
    goto v_17157;
v_17153:
    v_18069 = stack[-4];
    goto v_17154;
v_17155:
    v_18068 = elt(env, 21); // lex_is_typename
    goto v_17156;
v_17157:
    goto v_17153;
v_17154:
    goto v_17155;
v_17156:
    v_18068 = get(v_18069, v_18068);
    env = stack[-5];
    goto v_17138;
    v_18068 = nil;
v_17138:
    if (v_18068 == nil) goto v_17136;
    v_18068 = qvalue(elt(env, 22)); // lex_typename_code
    goto v_16834;
v_17136:
    v_18068 = qvalue(elt(env, 23)); // lex_symbol_code
    goto v_16834;
    goto v_16934;
v_16936:
    v_18068 = qvalue(elt(env, 6)); // lex_char
    v_18068 = Ldigitp(nil, v_18068);
    env = stack[-5];
    if (v_18068 == nil) goto v_17166;
    else goto v_17164;
v_17166:
    goto v_17178;
v_17174:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17175;
v_17176:
    v_18068 = elt(env, 24); // !~
    goto v_17177;
v_17178:
    goto v_17174;
v_17175:
    goto v_17176;
v_17177:
    if (v_18069 == v_18068) goto v_17172;
    else goto v_17173;
v_17172:
    goto v_17191;
v_17187:
    v_18069 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17188;
v_17189:
    v_18068 = (LispObject)2097152+TAG_FIXNUM; // 131072
    goto v_17190;
v_17191:
    goto v_17187;
v_17188:
    goto v_17189;
v_17190:
    fn = elt(env, 52); // land
    v_18068 = (*qfn2(fn))(fn, v_18069, v_18068);
    env = stack[-5];
    v_18068 = (LispObject)zerop(v_18068);
    v_18068 = v_18068 ? lisp_true : nil;
    env = stack[-5];
    if (v_18068 == nil) goto v_17183;
    else goto v_17184;
v_17183:
    fn = elt(env, 55); // yypeek
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18068 = Ldigitp(nil, v_18068);
    env = stack[-5];
    goto v_17182;
v_17184:
    v_18068 = nil;
    goto v_17182;
    v_18068 = nil;
v_17182:
    goto v_17171;
v_17173:
    v_18068 = nil;
    goto v_17171;
    v_18068 = nil;
v_17171:
    if (v_18068 == nil) goto v_17169;
    else goto v_17164;
v_17169:
    goto v_17165;
v_17164:
    goto v_17210;
v_17206:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17207;
v_17208:
    v_18068 = elt(env, 24); // !~
    goto v_17209;
v_17210:
    goto v_17206;
v_17207:
    goto v_17208;
v_17209:
    if (v_18069 == v_18068) goto v_17204;
    else goto v_17205;
v_17204:
    v_18068 = lisp_true;
    stack[-2] = v_18068;
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17203;
v_17205:
v_17203:
    goto v_17227;
v_17223:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17224;
v_17225:
    v_18068 = elt(env, 25); // !0
    goto v_17226;
v_17227:
    goto v_17223;
v_17224:
    goto v_17225;
v_17226:
    if (v_18069 == v_18068) goto v_17221;
    else goto v_17222;
v_17221:
    goto v_17238;
v_17234:
    fn = elt(env, 55); // yypeek
    v_18069 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17235;
v_17236:
    v_18068 = elt(env, 26); // x
    goto v_17237;
v_17238:
    goto v_17234;
v_17235:
    goto v_17236;
v_17237:
    if (v_18069 == v_18068) goto v_17232;
    else goto v_17233;
v_17232:
    v_18068 = lisp_true;
    goto v_17231;
v_17233:
    goto v_17248;
v_17244:
    fn = elt(env, 55); // yypeek
    v_18069 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17245;
v_17246:
    v_18068 = elt(env, 27); // !X
    goto v_17247;
v_17248:
    goto v_17244;
v_17245:
    goto v_17246;
v_17247:
    v_18068 = (v_18069 == v_18068 ? lisp_true : nil);
    goto v_17231;
    v_18068 = nil;
v_17231:
    goto v_17220;
v_17222:
    v_18068 = nil;
    goto v_17220;
    v_18068 = nil;
v_17220:
    if (v_18068 == nil) goto v_17218;
    v_18068 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 3)) = v_18068; // yylval
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
v_17259:
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    fn = elt(env, 56); // lex_hexval
    v_18068 = (*qfn1(fn))(fn, v_18068);
    env = stack[-5];
    stack[-3] = v_18068;
    if (v_18068 == nil) goto v_17262;
    else goto v_17263;
v_17262:
    goto v_17258;
v_17263:
    goto v_17272;
v_17268:
    goto v_17278;
v_17274:
    v_18069 = (LispObject)256+TAG_FIXNUM; // 16
    goto v_17275;
v_17276:
    v_18068 = qvalue(elt(env, 3)); // yylval
    goto v_17277;
v_17278:
    goto v_17274;
v_17275:
    goto v_17276;
v_17277:
    v_18069 = times2(v_18069, v_18068);
    env = stack[-5];
    goto v_17269;
v_17270:
    v_18068 = stack[-3];
    goto v_17271;
v_17272:
    goto v_17268;
v_17269:
    goto v_17270;
v_17271:
    v_18068 = plus2(v_18069, v_18068);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18068; // yylval
    goto v_17259;
v_17258:
    v_18068 = stack[-2];
    if (v_18068 == nil) goto v_17285;
    v_18068 = qvalue(elt(env, 3)); // yylval
    v_18068 = negate(v_18068);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18068; // yylval
    goto v_17283;
v_17285:
v_17283:
    v_18068 = qvalue(elt(env, 28)); // lex_number_code
    goto v_16834;
v_17218:
    v_18068 = qvalue(elt(env, 6)); // lex_char
    v_18068 = ncons(v_18068);
    env = stack[-5];
    stack[-4] = v_18068;
v_17294:
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18068 = qvalue(elt(env, 6)); // lex_char
    v_18068 = Ldigitp(nil, v_18068);
    env = stack[-5];
    if (v_18068 == nil) goto v_17297;
    else goto v_17298;
v_17297:
    goto v_17293;
v_17298:
    goto v_17308;
v_17304:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17305;
v_17306:
    v_18068 = stack[-4];
    goto v_17307;
v_17308:
    goto v_17304;
v_17305:
    goto v_17306;
v_17307:
    v_18068 = cons(v_18069, v_18068);
    env = stack[-5];
    stack[-4] = v_18068;
    goto v_17294;
v_17293:
    goto v_17319;
v_17315:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17316;
v_17317:
    v_18068 = elt(env, 29); // !.
    goto v_17318;
v_17319:
    goto v_17315;
v_17316:
    goto v_17317;
v_17318:
    if (v_18069 == v_18068) goto v_17313;
    else goto v_17314;
v_17313:
    v_18068 = lisp_true;
    stack[-3] = v_18068;
    goto v_17328;
v_17324:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17325;
v_17326:
    v_18068 = stack[-4];
    goto v_17327;
v_17328:
    goto v_17324;
v_17325:
    goto v_17326;
v_17327:
    v_18068 = cons(v_18069, v_18068);
    env = stack[-5];
    stack[-4] = v_18068;
v_17333:
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18068 = qvalue(elt(env, 6)); // lex_char
    v_18068 = Ldigitp(nil, v_18068);
    env = stack[-5];
    if (v_18068 == nil) goto v_17336;
    else goto v_17337;
v_17336:
    goto v_17332;
v_17337:
    goto v_17347;
v_17343:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17344;
v_17345:
    v_18068 = stack[-4];
    goto v_17346;
v_17347:
    goto v_17343;
v_17344:
    goto v_17345;
v_17346:
    v_18068 = cons(v_18069, v_18068);
    env = stack[-5];
    stack[-4] = v_18068;
    goto v_17333;
v_17332:
    goto v_17312;
v_17314:
v_17312:
    goto v_17362;
v_17358:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17359;
v_17360:
    v_18068 = elt(env, 30); // e
    goto v_17361;
v_17362:
    goto v_17358;
v_17359:
    goto v_17360;
v_17361:
    if (v_18069 == v_18068) goto v_17356;
    else goto v_17357;
v_17356:
    v_18068 = lisp_true;
    goto v_17355;
v_17357:
    goto v_17372;
v_17368:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17369;
v_17370:
    v_18068 = elt(env, 31); // !E
    goto v_17371;
v_17372:
    goto v_17368;
v_17369:
    goto v_17370;
v_17371:
    v_18068 = (v_18069 == v_18068 ? lisp_true : nil);
    goto v_17355;
    v_18068 = nil;
v_17355:
    if (v_18068 == nil) goto v_17353;
    v_18068 = stack[-3];
    if (v_18068 == nil) goto v_17378;
    else goto v_17379;
v_17378:
    goto v_17388;
v_17382:
    v_18070 = elt(env, 25); // !0
    goto v_17383;
v_17384:
    v_18069 = elt(env, 29); // !.
    goto v_17385;
v_17386:
    v_18068 = stack[-4];
    goto v_17387;
v_17388:
    goto v_17382;
v_17383:
    goto v_17384;
v_17385:
    goto v_17386;
v_17387:
    v_18068 = list2star(v_18070, v_18069, v_18068);
    env = stack[-5];
    stack[-4] = v_18068;
    goto v_17377;
v_17379:
v_17377:
    goto v_17398;
v_17394:
    v_18069 = elt(env, 30); // e
    goto v_17395;
v_17396:
    v_18068 = stack[-4];
    goto v_17397;
v_17398:
    goto v_17394;
v_17395:
    goto v_17396;
v_17397:
    v_18068 = cons(v_18069, v_18068);
    env = stack[-5];
    stack[-4] = v_18068;
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17414;
v_17410:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17411;
v_17412:
    v_18068 = elt(env, 32); // !+
    goto v_17413;
v_17414:
    goto v_17410;
v_17411:
    goto v_17412;
v_17413:
    if (v_18069 == v_18068) goto v_17408;
    else goto v_17409;
v_17408:
    v_18068 = lisp_true;
    goto v_17407;
v_17409:
    goto v_17424;
v_17420:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17421;
v_17422:
    v_18068 = elt(env, 33); // !-
    goto v_17423;
v_17424:
    goto v_17420;
v_17421:
    goto v_17422;
v_17423:
    v_18068 = (v_18069 == v_18068 ? lisp_true : nil);
    goto v_17407;
    v_18068 = nil;
v_17407:
    if (v_18068 == nil) goto v_17405;
    goto v_17433;
v_17429:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17430;
v_17431:
    v_18068 = stack[-4];
    goto v_17432;
v_17433:
    goto v_17429;
v_17430:
    goto v_17431;
v_17432:
    v_18068 = cons(v_18069, v_18068);
    env = stack[-5];
    stack[-4] = v_18068;
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17403;
v_17405:
v_17403:
    v_18068 = qvalue(elt(env, 6)); // lex_char
    v_18068 = Ldigitp(nil, v_18068);
    env = stack[-5];
    if (v_18068 == nil) goto v_17439;
    else goto v_17440;
v_17439:
    goto v_17448;
v_17444:
    v_18069 = elt(env, 25); // !0
    goto v_17445;
v_17446:
    v_18068 = stack[-4];
    goto v_17447;
v_17448:
    goto v_17444;
v_17445:
    goto v_17446;
v_17447:
    v_18068 = cons(v_18069, v_18068);
    env = stack[-5];
    stack[-4] = v_18068;
    goto v_17438;
v_17440:
    goto v_17458;
v_17454:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17455;
v_17456:
    v_18068 = stack[-4];
    goto v_17457;
v_17458:
    goto v_17454;
v_17455:
    goto v_17456;
v_17457:
    v_18068 = cons(v_18069, v_18068);
    env = stack[-5];
    stack[-4] = v_18068;
v_17463:
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18068 = qvalue(elt(env, 6)); // lex_char
    v_18068 = Ldigitp(nil, v_18068);
    env = stack[-5];
    if (v_18068 == nil) goto v_17466;
    else goto v_17467;
v_17466:
    goto v_17462;
v_17467:
    goto v_17477;
v_17473:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17474;
v_17475:
    v_18068 = stack[-4];
    goto v_17476;
v_17477:
    goto v_17473;
v_17474:
    goto v_17475;
v_17476:
    v_18068 = cons(v_18069, v_18068);
    env = stack[-5];
    stack[-4] = v_18068;
    goto v_17463;
v_17462:
    goto v_17438;
v_17438:
    goto v_17351;
v_17353:
v_17351:
    v_18068 = stack[-4];
    v_18068 = Lnreverse(nil, v_18068);
    env = stack[-5];
    v_18068 = Lcompress(nil, v_18068);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18068; // yylval
    v_18068 = stack[-2];
    if (v_18068 == nil) goto v_17486;
    v_18068 = qvalue(elt(env, 3)); // yylval
    v_18068 = negate(v_18068);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18068; // yylval
    goto v_17484;
v_17486:
v_17484:
    v_18068 = qvalue(elt(env, 28)); // lex_number_code
    goto v_16834;
v_17165:
    goto v_17501;
v_17497:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17498;
v_17499:
    v_18068 = elt(env, 34); // !"
    goto v_17500;
v_17501:
    goto v_17497;
v_17498:
    goto v_17499;
v_17500:
    if (v_18069 == v_18068) goto v_17495;
    else goto v_17496;
v_17495:
    goto v_17510;
v_17506:
    v_18069 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17507;
v_17508:
    v_18068 = (LispObject)2048+TAG_FIXNUM; // 128
    goto v_17509;
v_17510:
    goto v_17506;
v_17507:
    goto v_17508;
v_17509:
    fn = elt(env, 52); // land
    v_18068 = (*qfn2(fn))(fn, v_18069, v_18068);
    env = stack[-5];
    v_18068 = (LispObject)zerop(v_18068);
    v_18068 = v_18068 ? lisp_true : nil;
    env = stack[-5];
    v_18068 = (v_18068 == nil ? lisp_true : nil);
    goto v_17494;
v_17496:
    v_18068 = nil;
    goto v_17494;
    v_18068 = nil;
v_17494:
    if (v_18068 == nil) goto v_17492;
    goto v_17527;
v_17523:
    v_18069 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17524;
v_17525:
    v_18068 = (LispObject)16384+TAG_FIXNUM; // 1024
    goto v_17526;
v_17527:
    goto v_17523;
v_17524:
    goto v_17525;
v_17526:
    fn = elt(env, 52); // land
    v_18068 = (*qfn2(fn))(fn, v_18069, v_18068);
    env = stack[-5];
    v_18068 = (LispObject)zerop(v_18068);
    v_18068 = v_18068 ? lisp_true : nil;
    env = stack[-5];
    if (v_18068 == nil) goto v_17519;
    else goto v_17520;
v_17519:
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=14 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 14, -1);
    qvalue(elt(env, 14)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 15, 0);
    qvalue(elt(env, 15)) = nil; // !*lower
v_17536:
    goto v_17549;
v_17545:
    fn = elt(env, 50); // yyreadch
    v_18069 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17546;
v_17547:
    v_18068 = elt(env, 34); // !"
    goto v_17548;
v_17549:
    goto v_17545;
v_17546:
    goto v_17547;
v_17548:
    if (v_18069 == v_18068) goto v_17544;
    v_18068 = lisp_true;
    goto v_17542;
v_17544:
    goto v_17563;
v_17559:
    fn = elt(env, 55); // yypeek
    v_18069 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17560;
v_17561:
    v_18068 = elt(env, 34); // !"
    goto v_17562;
v_17563:
    goto v_17559;
v_17560:
    goto v_17561;
v_17562:
    if (v_18069 == v_18068) goto v_17557;
    else goto v_17558;
v_17557:
    goto v_17570;
v_17566:
    fn = elt(env, 50); // yyreadch
    v_18069 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17567;
v_17568:
    v_18068 = elt(env, 34); // !"
    goto v_17569;
v_17570:
    goto v_17566;
v_17567:
    goto v_17568;
v_17569:
    v_18068 = (v_18069 == v_18068 ? lisp_true : nil);
    goto v_17556;
v_17558:
    v_18068 = nil;
    goto v_17556;
    v_18068 = nil;
v_17556:
    goto v_17542;
    v_18068 = nil;
v_17542:
    if (v_18068 == nil) goto v_17539;
    else goto v_17540;
v_17539:
    goto v_17535;
v_17540:
    goto v_17583;
v_17579:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17580;
v_17581:
    v_18068 = stack[-4];
    goto v_17582;
v_17583:
    goto v_17579;
v_17580:
    goto v_17581;
v_17582:
    v_18068 = cons(v_18069, v_18068);
    env = stack[-5];
    stack[-4] = v_18068;
    goto v_17536;
v_17535:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_17518;
v_17520:
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=14 saveloc=2
{   bind_fluid_stack bind_fluid_var(-5, 14, -2);
    qvalue(elt(env, 14)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 15, -1);
    qvalue(elt(env, 15)) = nil; // !*lower
    stack[0] = nil;
v_17595:
    goto v_17608;
v_17604:
    fn = elt(env, 50); // yyreadch
    v_18069 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17605;
v_17606:
    v_18068 = elt(env, 34); // !"
    goto v_17607;
v_17608:
    goto v_17604;
v_17605:
    goto v_17606;
v_17607:
    if (v_18069 == v_18068) goto v_17603;
    v_18068 = lisp_true;
    goto v_17601;
v_17603:
    goto v_17618;
v_17614:
    v_18069 = stack[0];
    goto v_17615;
v_17616:
    v_18068 = elt(env, 35); // !\ (backslash)
    goto v_17617;
v_17618:
    goto v_17614;
v_17615:
    goto v_17616;
v_17617:
    v_18068 = (v_18069 == v_18068 ? lisp_true : nil);
    goto v_17601;
    v_18068 = nil;
v_17601:
    if (v_18068 == nil) goto v_17598;
    else goto v_17599;
v_17598:
    goto v_17594;
v_17599:
    v_18068 = qvalue(elt(env, 6)); // lex_char
    stack[0] = v_18068;
    goto v_17629;
v_17625:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17626;
v_17627:
    v_18068 = stack[-4];
    goto v_17628;
v_17629:
    goto v_17625;
v_17626:
    goto v_17627;
v_17628:
    v_18068 = cons(v_18069, v_18068);
    env = stack[-5];
    stack[-4] = v_18068;
    goto v_17595;
v_17594:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_17518;
v_17518:
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_18068 = stack[-4];
    v_18068 = Lnreverse(nil, v_18068);
    env = stack[-5];
    fn = elt(env, 54); // list2widestring
    v_18068 = (*qfn1(fn))(fn, v_18068);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18068; // yylval
    v_18068 = qvalue(elt(env, 36)); // lex_string_code
    goto v_16834;
v_17492:
    goto v_17647;
v_17643:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17644;
v_17645:
    v_18068 = elt(env, 20); // !'
    goto v_17646;
v_17647:
    goto v_17643;
v_17644:
    goto v_17645;
v_17646:
    if (v_18069 == v_18068) goto v_17641;
    else goto v_17642;
v_17641:
    goto v_17656;
v_17652:
    v_18069 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17653;
v_17654:
    v_18068 = (LispObject)4096+TAG_FIXNUM; // 256
    goto v_17655;
v_17656:
    goto v_17652;
v_17653:
    goto v_17654;
v_17655:
    fn = elt(env, 52); // land
    v_18068 = (*qfn2(fn))(fn, v_18069, v_18068);
    env = stack[-5];
    v_18068 = (LispObject)zerop(v_18068);
    v_18068 = v_18068 ? lisp_true : nil;
    env = stack[-5];
    v_18068 = (v_18068 == nil ? lisp_true : nil);
    goto v_17640;
v_17642:
    v_18068 = nil;
    goto v_17640;
    v_18068 = nil;
v_17640:
    if (v_18068 == nil) goto v_17638;
// Binding !*raise
// FLUIDBIND: reloadenv=5 litvec-offset=14 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 14, -1);
    qvalue(elt(env, 14)) = nil; // !*raise
// Binding !*lower
// FLUIDBIND: reloadenv=5 litvec-offset=15 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 15, 0);
    qvalue(elt(env, 15)) = nil; // !*lower
v_17669:
v_17672:
    goto v_17681;
v_17677:
    fn = elt(env, 50); // yyreadch
    v_18069 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17678;
v_17679:
    v_18068 = elt(env, 20); // !'
    goto v_17680;
v_17681:
    goto v_17677;
v_17678:
    goto v_17679;
v_17680:
    if (v_18069 == v_18068) goto v_17675;
    else goto v_17676;
v_17675:
    goto v_17671;
v_17676:
    goto v_17690;
v_17686:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17687;
v_17688:
    v_18068 = stack[-4];
    goto v_17689;
v_17690:
    goto v_17686;
v_17687:
    goto v_17688;
v_17689:
    v_18068 = cons(v_18069, v_18068);
    env = stack[-5];
    stack[-4] = v_18068;
    goto v_17672;
v_17671:
    goto v_17698;
v_17694:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17695;
v_17696:
    v_18068 = stack[-4];
    goto v_17697;
v_17698:
    goto v_17694;
v_17695:
    goto v_17696;
v_17697:
    v_18068 = cons(v_18069, v_18068);
    env = stack[-5];
    stack[-4] = v_18068;
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17710;
v_17706:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17707;
v_17708:
    v_18068 = elt(env, 20); // !'
    goto v_17709;
v_17710:
    goto v_17706;
v_17707:
    goto v_17708;
v_17709:
    if (v_18069 == v_18068) goto v_17704;
    else goto v_17705;
v_17704:
    goto v_17669;
v_17705:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    v_18068 = stack[-4];
    v_18068 = qcdr(v_18068);
    v_18068 = Lnreverse(nil, v_18068);
    env = stack[-5];
    fn = elt(env, 54); // list2widestring
    v_18068 = (*qfn1(fn))(fn, v_18068);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18068; // yylval
    v_18068 = qvalue(elt(env, 37)); // lex_char_code
    goto v_16834;
v_17638:
    goto v_17728;
v_17724:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17725;
v_17726:
    v_18068 = elt(env, 20); // !'
    goto v_17727;
v_17728:
    goto v_17724;
v_17725:
    goto v_17726;
v_17727:
    if (v_18069 == v_18068) goto v_17722;
    else goto v_17723;
v_17722:
    goto v_17737;
v_17733:
    v_18069 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17734;
v_17735:
    v_18068 = (LispObject)4194304+TAG_FIXNUM; // 262144
    goto v_17736;
v_17737:
    goto v_17733;
v_17734:
    goto v_17735;
v_17736:
    fn = elt(env, 52); // land
    v_18068 = (*qfn2(fn))(fn, v_18069, v_18068);
    env = stack[-5];
    v_18068 = (LispObject)zerop(v_18068);
    v_18068 = v_18068 ? lisp_true : nil;
    env = stack[-5];
    v_18068 = (v_18068 == nil ? lisp_true : nil);
    goto v_17721;
v_17723:
    v_18068 = nil;
    goto v_17721;
    v_18068 = nil;
v_17721:
    if (v_18068 == nil) goto v_17719;
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    fn = elt(env, 57); // read_s_expression
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17751;
v_17747:
    v_18069 = elt(env, 38); // quote
    goto v_17748;
v_17749:
    v_18068 = qvalue(elt(env, 3)); // yylval
    goto v_17750;
v_17751:
    goto v_17747;
v_17748:
    goto v_17749;
v_17750:
    v_18068 = list2(v_18069, v_18068);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18068; // yylval
    v_18068 = qvalue(elt(env, 39)); // lex_list_code
    goto v_16834;
v_17719:
    goto v_17765;
v_17761:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17762;
v_17763:
    v_18068 = elt(env, 40); // !`
    goto v_17764;
v_17765:
    goto v_17761;
v_17762:
    goto v_17763;
v_17764:
    if (v_18069 == v_18068) goto v_17759;
    else goto v_17760;
v_17759:
    goto v_17774;
v_17770:
    v_18069 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17771;
v_17772:
    v_18068 = (LispObject)4194304+TAG_FIXNUM; // 262144
    goto v_17773;
v_17774:
    goto v_17770;
v_17771:
    goto v_17772;
v_17773:
    fn = elt(env, 52); // land
    v_18068 = (*qfn2(fn))(fn, v_18069, v_18068);
    env = stack[-5];
    v_18068 = (LispObject)zerop(v_18068);
    v_18068 = v_18068 ? lisp_true : nil;
    env = stack[-5];
    v_18068 = (v_18068 == nil ? lisp_true : nil);
    goto v_17758;
v_17760:
    v_18068 = nil;
    goto v_17758;
    v_18068 = nil;
v_17758:
    if (v_18068 == nil) goto v_17756;
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    fn = elt(env, 57); // read_s_expression
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17788;
v_17784:
    v_18069 = elt(env, 41); // backquote
    goto v_17785;
v_17786:
    v_18068 = qvalue(elt(env, 3)); // yylval
    goto v_17787;
v_17788:
    goto v_17784;
v_17785:
    goto v_17786;
v_17787:
    v_18068 = list2(v_18069, v_18068);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18068; // yylval
    v_18068 = qvalue(elt(env, 39)); // lex_list_code
    goto v_16834;
v_17756:
    v_18068 = qvalue(elt(env, 6)); // lex_char
    qvalue(elt(env, 3)) = v_18068; // yylval
    goto v_17803;
v_17799:
    v_18069 = qvalue(elt(env, 3)); // yylval
    goto v_17800;
v_17801:
    v_18068 = qvalue(elt(env, 10)); // !$eof!$
    goto v_17802;
v_17803:
    goto v_17799;
v_17800:
    goto v_17801;
v_17802:
    if (equal(v_18069, v_18068)) goto v_17797;
    else goto v_17798;
v_17797:
    v_18068 = qvalue(elt(env, 11)); // lex_eof_code
    goto v_16834;
v_17798:
    goto v_17823;
v_17819:
    v_18069 = qvalue(elt(env, 3)); // yylval
    goto v_17820;
v_17821:
    v_18068 = elt(env, 42); // !#
    goto v_17822;
v_17823:
    goto v_17819;
v_17820:
    goto v_17821;
v_17822:
    if (v_18069 == v_18068) goto v_17817;
    else goto v_17818;
v_17817:
    goto v_17832;
v_17828:
    v_18069 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17829;
v_17830:
    v_18068 = (LispObject)1024+TAG_FIXNUM; // 64
    goto v_17831;
v_17832:
    goto v_17828;
v_17829:
    goto v_17830;
v_17831:
    fn = elt(env, 52); // land
    v_18068 = (*qfn2(fn))(fn, v_18069, v_18068);
    env = stack[-5];
    v_18068 = (LispObject)zerop(v_18068);
    v_18068 = v_18068 ? lisp_true : nil;
    env = stack[-5];
    v_18068 = (v_18068 == nil ? lisp_true : nil);
    goto v_17816;
v_17818:
    v_18068 = nil;
    goto v_17816;
    v_18068 = nil;
v_17816:
    if (v_18068 == nil) goto v_17814;
    v_18068 = lisp_true;
    goto v_17812;
v_17814:
    goto v_17850;
v_17846:
    v_18069 = qvalue(elt(env, 3)); // yylval
    goto v_17847;
v_17848:
    v_18068 = elt(env, 43); // lex_dipthong
    goto v_17849;
v_17850:
    goto v_17846;
v_17847:
    goto v_17848;
v_17849:
    v_18068 = get(v_18069, v_18068);
    env = stack[-5];
    if (v_18068 == nil) goto v_17844;
    else goto v_17843;
v_17844:
    goto v_17863;
v_17859:
    v_18069 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17860;
v_17861:
    v_18068 = (LispObject)2097152+TAG_FIXNUM; // 131072
    goto v_17862;
v_17863:
    goto v_17859;
v_17860:
    goto v_17861;
v_17862:
    fn = elt(env, 52); // land
    v_18068 = (*qfn2(fn))(fn, v_18069, v_18068);
    env = stack[-5];
    v_18068 = (LispObject)zerop(v_18068);
    v_18068 = v_18068 ? lisp_true : nil;
    env = stack[-5];
    if (v_18068 == nil) goto v_17855;
    else goto v_17856;
v_17855:
    goto v_17871;
v_17867:
    v_18069 = qvalue(elt(env, 3)); // yylval
    goto v_17868;
v_17869:
    v_18068 = elt(env, 44); // sml_opchar
    goto v_17870;
v_17871:
    goto v_17867;
v_17868:
    goto v_17869;
v_17870:
    v_18068 = Lflagp(nil, v_18069, v_18068);
    env = stack[-5];
    goto v_17854;
v_17856:
    v_18068 = nil;
    goto v_17854;
    v_18068 = nil;
v_17854:
v_17843:
    goto v_17812;
    v_18068 = nil;
v_17812:
    if (v_18068 == nil) goto v_17810;
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17808;
v_17810:
    v_18068 = elt(env, 7); // ! 
    qvalue(elt(env, 6)) = v_18068; // lex_char
    goto v_17808;
v_17808:
    goto v_17894;
v_17890:
    v_18069 = qvalue(elt(env, 3)); // yylval
    goto v_17891;
v_17892:
    v_18068 = elt(env, 42); // !#
    goto v_17893;
v_17894:
    goto v_17890;
v_17891:
    goto v_17892;
v_17893:
    if (v_18069 == v_18068) goto v_17888;
    else goto v_17889;
v_17888:
    goto v_17907;
v_17903:
    v_18069 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17904;
v_17905:
    v_18068 = (LispObject)1024+TAG_FIXNUM; // 64
    goto v_17906;
v_17907:
    goto v_17903;
v_17904:
    goto v_17905;
v_17906:
    fn = elt(env, 52); // land
    v_18068 = (*qfn2(fn))(fn, v_18069, v_18068);
    env = stack[-5];
    v_18068 = (LispObject)zerop(v_18068);
    v_18068 = v_18068 ? lisp_true : nil;
    env = stack[-5];
    if (v_18068 == nil) goto v_17899;
    else goto v_17900;
v_17899:
    v_18068 = qvalue(elt(env, 6)); // lex_char
    v_18068 = Lalpha_char_p(nil, v_18068);
    env = stack[-5];
    goto v_17898;
v_17900:
    v_18068 = nil;
    goto v_17898;
    v_18068 = nil;
v_17898:
    goto v_17887;
v_17889:
    v_18068 = nil;
    goto v_17887;
    v_18068 = nil;
v_17887:
    if (v_18068 == nil) goto v_17885;
    else goto v_17883;
v_17885:
    goto v_17923;
v_17919:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_17920;
v_17921:
    v_18068 = elt(env, 12); // !!
    goto v_17922;
v_17923:
    goto v_17919;
v_17920:
    goto v_17921;
v_17922:
    if (v_18069 == v_18068) goto v_17883;
    goto v_17884;
v_17883:
    v_18068 = CC_lex_basic_token(elt(env, 0), 0);
    env = stack[-5];
    stack[-4] = v_18068;
    goto v_17935;
v_17931:
    v_18069 = qvalue(elt(env, 3)); // yylval
    goto v_17932;
v_17933:
    v_18068 = elt(env, 45); // (if else elif endif define eval)
    goto v_17934;
v_17935:
    goto v_17931;
v_17932:
    goto v_17933;
v_17934:
    v_18068 = Lmemq(nil, v_18069, v_18068);
    if (v_18068 == nil) goto v_17930;
    goto v_17946;
v_17942:
    stack[0] = elt(env, 42); // !#
    goto v_17943;
v_17944:
    v_18068 = qvalue(elt(env, 3)); // yylval
    v_18068 = Lsymbol_name(nil, v_18068);
    env = stack[-5];
    fn = elt(env, 58); // widestring2list
    v_18068 = (*qfn1(fn))(fn, v_18068);
    env = stack[-5];
    goto v_17945;
v_17946:
    goto v_17942;
v_17943:
    goto v_17944;
v_17945:
    v_18068 = cons(stack[0], v_18068);
    env = stack[-5];
    fn = elt(env, 54); // list2widestring
    v_18068 = (*qfn1(fn))(fn, v_18068);
    env = stack[-5];
    v_18068 = Lintern(nil, v_18068);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18068; // yylval
    goto v_17928;
v_17930:
    v_18068 = stack[-4];
    qvalue(elt(env, 1)) = v_18068; // lex_peeked
    v_18068 = qvalue(elt(env, 3)); // yylval
    qvalue(elt(env, 2)) = v_18068; // lex_peeked_yylval
    v_18068 = qvalue(elt(env, 5)); // lex_escaped
    qvalue(elt(env, 4)) = v_18068; // lex_peeked_escaped
    v_18068 = elt(env, 42); // !#
    qvalue(elt(env, 3)) = v_18068; // yylval
    v_18068 = nil;
    qvalue(elt(env, 5)) = v_18068; // lex_escaped
    goto v_17928;
v_17928:
    goto v_17882;
v_17884:
v_17882:
v_17960:
    goto v_17969;
v_17965:
    v_18070 = qvalue(elt(env, 6)); // lex_char
    goto v_17966;
v_17967:
    goto v_17976;
v_17972:
    v_18069 = qvalue(elt(env, 3)); // yylval
    goto v_17973;
v_17974:
    v_18068 = elt(env, 43); // lex_dipthong
    goto v_17975;
v_17976:
    goto v_17972;
v_17973:
    goto v_17974;
v_17975:
    v_18068 = get(v_18069, v_18068);
    env = stack[-5];
    goto v_17968;
v_17969:
    goto v_17965;
v_17966:
    goto v_17967;
v_17968:
    v_18068 = Latsoc(nil, v_18070, v_18068);
    stack[-3] = v_18068;
    if (v_18068 == nil) goto v_17963;
    else goto v_17964;
v_17963:
    goto v_17959;
v_17964:
    v_18068 = stack[-3];
    v_18068 = qcdr(v_18068);
    qvalue(elt(env, 3)) = v_18068; // yylval
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_17960;
v_17959:
    goto v_17998;
v_17994:
    v_18069 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_17995;
v_17996:
    v_18068 = (LispObject)2097152+TAG_FIXNUM; // 131072
    goto v_17997;
v_17998:
    goto v_17994;
v_17995:
    goto v_17996;
v_17997:
    fn = elt(env, 52); // land
    v_18068 = (*qfn2(fn))(fn, v_18069, v_18068);
    env = stack[-5];
    v_18068 = (LispObject)zerop(v_18068);
    v_18068 = v_18068 ? lisp_true : nil;
    env = stack[-5];
    if (v_18068 == nil) goto v_17990;
    else goto v_17991;
v_17990:
    v_18068 = qvalue(elt(env, 3)); // yylval
    v_18068 = Lexplodec(nil, v_18068);
    env = stack[-5];
    stack[-3] = v_18068;
    fn = elt(env, 59); // all_sml_opchar
    v_18068 = (*qfn1(fn))(fn, v_18068);
    env = stack[-5];
    goto v_17989;
v_17991:
    v_18068 = nil;
    goto v_17989;
    v_18068 = nil;
v_17989:
    if (v_18068 == nil) goto v_17987;
v_18009:
    goto v_18024;
v_18020:
    v_18069 = qvalue(elt(env, 13)); // lexer_style!*
    goto v_18021;
v_18022:
    v_18068 = (LispObject)2097152+TAG_FIXNUM; // 131072
    goto v_18023;
v_18024:
    goto v_18020;
v_18021:
    goto v_18022;
v_18023:
    fn = elt(env, 52); // land
    v_18068 = (*qfn2(fn))(fn, v_18069, v_18068);
    env = stack[-5];
    v_18068 = (LispObject)zerop(v_18068);
    v_18068 = v_18068 ? lisp_true : nil;
    env = stack[-5];
    if (v_18068 == nil) goto v_18016;
    else goto v_18017;
v_18016:
    goto v_18032;
v_18028:
    v_18069 = qvalue(elt(env, 6)); // lex_char
    goto v_18029;
v_18030:
    v_18068 = elt(env, 44); // sml_opchar
    goto v_18031;
v_18032:
    goto v_18028;
v_18029:
    goto v_18030;
v_18031:
    v_18068 = Lflagp(nil, v_18069, v_18068);
    env = stack[-5];
    goto v_18015;
v_18017:
    v_18068 = nil;
    goto v_18015;
    v_18068 = nil;
v_18015:
    if (v_18068 == nil) goto v_18012;
    else goto v_18013;
v_18012:
    goto v_18008;
v_18013:
    goto v_18044;
v_18040:
    stack[0] = stack[-3];
    goto v_18041;
v_18042:
    v_18068 = qvalue(elt(env, 6)); // lex_char
    v_18068 = ncons(v_18068);
    env = stack[-5];
    goto v_18043;
v_18044:
    goto v_18040;
v_18041:
    goto v_18042;
v_18043:
    v_18068 = Lappend(nil, stack[0], v_18068);
    env = stack[-5];
    stack[-3] = v_18068;
    fn = elt(env, 50); // yyreadch
    v_18068 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_18009;
v_18008:
    v_18068 = stack[-3];
    fn = elt(env, 60); // list2string
    v_18068 = (*qfn1(fn))(fn, v_18068);
    env = stack[-5];
    v_18068 = Lintern(nil, v_18068);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_18068; // yylval
    goto v_17985;
v_17987:
v_17985:
    goto v_18061;
v_18057:
    v_18069 = qvalue(elt(env, 3)); // yylval
    goto v_18058;
v_18059:
    v_18068 = elt(env, 19); // lex_code
    goto v_18060;
v_18061:
    goto v_18057;
v_18058:
    goto v_18059;
v_18060:
    v_18068 = get(v_18069, v_18068);
    env = stack[-5];
    stack[-3] = v_18068;
    if (v_18068 == nil) goto v_18055;
    v_18068 = stack[-3];
    goto v_16834;
v_18055:
    v_18068 = qvalue(elt(env, 23)); // lex_symbol_code
    goto v_16834;
    goto v_16934;
v_16934:
    v_18068 = nil;
v_16834:
    return onevalue(v_18068);
}



// Code for formbool

static LispObject CC_formbool(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17120, v_17121, v_17122, v_17123, v_17124;
    LispObject fn;
    LispObject v_16831, v_16830, v_16829;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formbool");
    va_start(aa, nargs);
    v_16829 = va_arg(aa, LispObject);
    v_16830 = va_arg(aa, LispObject);
    v_16831 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_16831,v_16830,v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_16829,v_16830,v_16831);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_16831;
    stack[-3] = v_16830;
    stack[-4] = v_16829;
// end of prologue
    goto v_16841;
v_16837:
    v_17121 = stack[-2];
    goto v_16838;
v_16839:
    v_17120 = elt(env, 1); // symbolic
    goto v_16840;
v_16841:
    goto v_16837;
v_16838:
    goto v_16839;
v_16840:
    if (v_17121 == v_17120) goto v_16835;
    else goto v_16836;
v_16835:
    goto v_16851;
v_16845:
    v_17122 = stack[-4];
    goto v_16846;
v_16847:
    v_17121 = stack[-3];
    goto v_16848;
v_16849:
    v_17120 = stack[-2];
    goto v_16850;
v_16851:
    goto v_16845;
v_16846:
    goto v_16847;
v_16848:
    goto v_16849;
v_16850:
    {
        fn = elt(env, 9); // formc
        return (*qfnn(fn))(fn, 3, v_17122, v_17121, v_17120);
    }
v_16836:
    v_17120 = stack[-4];
    if (!consp(v_17120)) goto v_16855;
    else goto v_16856;
v_16855:
    goto v_16866;
v_16862:
    v_17121 = stack[-4];
    goto v_16863;
v_16864:
    v_17120 = lisp_true;
    goto v_16865;
v_16866:
    goto v_16862;
v_16863:
    goto v_16864;
v_16865:
    if (v_17121 == v_17120) goto v_16860;
    else goto v_16861;
v_16860:
    v_17120 = stack[-4];
    goto v_16859;
v_16861:
    v_17120 = stack[-4];
    if (symbolp(v_17120)) goto v_16875;
    v_17120 = lisp_true;
    goto v_16873;
v_16875:
    goto v_16884;
v_16880:
    v_17121 = stack[-4];
    goto v_16881;
v_16882:
    v_17120 = stack[-3];
    goto v_16883;
v_16884:
    goto v_16880;
v_16881:
    goto v_16882;
v_16883:
    v_17120 = Latsoc(nil, v_17121, v_17120);
    goto v_16873;
    v_17120 = nil;
v_16873:
    if (v_17120 == nil) goto v_16871;
    goto v_16893;
v_16889:
    v_17121 = elt(env, 2); // boolvalue!*
    goto v_16890;
v_16891:
    v_17120 = stack[-4];
    goto v_16892;
v_16893:
    goto v_16889;
v_16890:
    goto v_16891;
v_16892:
    return list2(v_17121, v_17120);
v_16871:
    goto v_16903;
v_16899:
    stack[0] = elt(env, 2); // boolvalue!*
    goto v_16900;
v_16901:
    goto v_16912;
v_16906:
    v_17122 = stack[-4];
    goto v_16907;
v_16908:
    v_17121 = stack[-3];
    goto v_16909;
v_16910:
    v_17120 = stack[-2];
    goto v_16911;
v_16912:
    goto v_16906;
v_16907:
    goto v_16908;
v_16909:
    goto v_16910;
v_16911:
    fn = elt(env, 10); // formc!*
    v_17120 = (*qfnn(fn))(fn, 3, v_17122, v_17121, v_17120);
    goto v_16902;
v_16903:
    goto v_16899;
v_16900:
    goto v_16901;
v_16902:
    {
        LispObject v_17131 = stack[0];
        return list2(v_17131, v_17120);
    }
    v_17120 = nil;
v_16859:
    goto v_16834;
v_16856:
    goto v_16924;
v_16920:
    v_17120 = stack[-4];
    v_17121 = qcdr(v_17120);
    goto v_16921;
v_16922:
    v_17120 = stack[-3];
    goto v_16923;
v_16924:
    goto v_16920;
v_16921:
    goto v_16922;
v_16923:
    fn = elt(env, 11); // intexprlisp
    v_17120 = (*qfn2(fn))(fn, v_17121, v_17120);
    env = stack[-6];
    if (v_17120 == nil) goto v_16917;
    goto v_16934;
v_16930:
    v_17120 = stack[-4];
    v_17121 = qcar(v_17120);
    goto v_16931;
v_16932:
    v_17120 = elt(env, 3); // boolfn
    goto v_16933;
v_16934:
    goto v_16930;
v_16931:
    goto v_16932;
v_16933:
    v_17120 = get(v_17121, v_17120);
    env = stack[-6];
    if (v_17120 == nil) goto v_16917;
    v_17120 = stack[-4];
    goto v_16834;
v_16917:
    v_17120 = stack[-4];
    v_17120 = qcar(v_17120);
    if (symbolp(v_17120)) goto v_16941;
    else goto v_16940;
v_16941:
    goto v_16950;
v_16946:
    v_17120 = stack[-4];
    v_17121 = qcar(v_17120);
    goto v_16947;
v_16948:
    v_17120 = elt(env, 3); // boolfn
    goto v_16949;
v_16950:
    goto v_16946;
v_16947:
    goto v_16948;
v_16949:
    v_17120 = get(v_17121, v_17120);
    env = stack[-6];
    if (v_17120 == nil) goto v_16940;
    goto v_16959;
v_16955:
    goto v_16965;
v_16961:
    v_17120 = stack[-4];
    v_17121 = qcar(v_17120);
    goto v_16962;
v_16963:
    v_17120 = elt(env, 3); // boolfn
    goto v_16964;
v_16965:
    goto v_16961;
v_16962:
    goto v_16963;
v_16964:
    stack[0] = get(v_17121, v_17120);
    env = stack[-6];
    goto v_16956;
v_16957:
    goto v_16976;
v_16970:
    v_17120 = stack[-4];
    v_17122 = qcdr(v_17120);
    goto v_16971;
v_16972:
    v_17121 = stack[-3];
    goto v_16973;
v_16974:
    v_17120 = stack[-2];
    goto v_16975;
v_16976:
    goto v_16970;
v_16971:
    goto v_16972;
v_16973:
    goto v_16974;
v_16975:
    fn = elt(env, 12); // formclis
    v_17120 = (*qfnn(fn))(fn, 3, v_17122, v_17121, v_17120);
    goto v_16958;
v_16959:
    goto v_16955;
v_16956:
    goto v_16957;
v_16958:
    {
        LispObject v_17132 = stack[0];
        return cons(v_17132, v_17120);
    }
v_16940:
    v_17120 = stack[-4];
    v_17120 = qcar(v_17120);
    if (symbolp(v_17120)) goto v_16983;
    else goto v_16982;
v_16983:
    goto v_16992;
v_16988:
    v_17120 = stack[-4];
    v_17121 = qcar(v_17120);
    goto v_16989;
v_16990:
    v_17120 = elt(env, 4); // boolean
    goto v_16991;
v_16992:
    goto v_16988;
v_16989:
    goto v_16990;
v_16991:
    v_17120 = Lflagp(nil, v_17121, v_17120);
    env = stack[-6];
    if (v_17120 == nil) goto v_16982;
    goto v_17001;
v_16997:
    v_17120 = stack[-4];
    stack[0] = qcar(v_17120);
    goto v_16998;
v_16999:
    goto v_17013;
v_17005:
    v_17120 = stack[-4];
    v_17124 = qcdr(v_17120);
    goto v_17006;
v_17007:
    v_17123 = stack[-3];
    goto v_17008;
v_17009:
    v_17122 = stack[-2];
    goto v_17010;
v_17011:
    goto v_17023;
v_17019:
    v_17120 = stack[-4];
    v_17121 = qcar(v_17120);
    goto v_17020;
v_17021:
    v_17120 = elt(env, 5); // boolargs
    goto v_17022;
v_17023:
    goto v_17019;
v_17020:
    goto v_17021;
v_17022:
    v_17120 = Lflagp(nil, v_17121, v_17120);
    env = stack[-6];
    goto v_17012;
v_17013:
    goto v_17005;
v_17006:
    goto v_17007;
v_17008:
    goto v_17009;
v_17010:
    goto v_17011;
v_17012:
    fn = elt(env, 13); // formboollis
    v_17120 = (*qfnn(fn))(fn, 4, v_17124, v_17123, v_17122, v_17120);
    goto v_17000;
v_17001:
    goto v_16997;
v_16998:
    goto v_16999;
v_17000:
    {
        LispObject v_17133 = stack[0];
        return cons(v_17133, v_17120);
    }
v_16982:
    goto v_17033;
v_17029:
    v_17120 = stack[-4];
    v_17121 = qcar(v_17120);
    goto v_17030;
v_17031:
    v_17120 = elt(env, 2); // boolvalue!*
    goto v_17032;
v_17033:
    goto v_17029;
v_17030:
    goto v_17031;
v_17032:
    if (v_17121 == v_17120) goto v_17027;
    else goto v_17028;
v_17027:
    v_17120 = elt(env, 6); // "Too many formbools"
    {
        fn = elt(env, 14); // rederr
        return (*qfn1(fn))(fn, v_17120);
    }
v_17028:
    goto v_17045;
v_17041:
    v_17120 = stack[-4];
    v_17121 = qcar(v_17120);
    goto v_17042;
v_17043:
    v_17120 = elt(env, 7); // where
    goto v_17044;
v_17045:
    goto v_17041;
v_17042:
    goto v_17043;
v_17044:
    if (v_17121 == v_17120) goto v_17039;
    else goto v_17040;
v_17039:
    goto v_17054;
v_17050:
    stack[-5] = elt(env, 2); // boolvalue!*
    goto v_17051;
v_17052:
    goto v_17063;
v_17057:
    goto v_17071;
v_17065:
    stack[-1] = elt(env, 7); // where
    goto v_17066;
v_17067:
    goto v_17079;
v_17075:
    stack[0] = elt(env, 8); // bool!-eval
    goto v_17076;
v_17077:
    goto v_17088;
v_17082:
    v_17120 = stack[-4];
    v_17120 = qcdr(v_17120);
    v_17122 = qcar(v_17120);
    goto v_17083;
v_17084:
    v_17121 = stack[-3];
    goto v_17085;
v_17086:
    v_17120 = stack[-2];
    goto v_17087;
v_17088:
    goto v_17082;
v_17083:
    goto v_17084;
v_17085:
    goto v_17086;
v_17087:
    v_17120 = CC_formbool(elt(env, 0), 3, v_17122, v_17121, v_17120);
    env = stack[-6];
    goto v_17078;
v_17079:
    goto v_17075;
v_17076:
    goto v_17077;
v_17078:
    v_17120 = list2(stack[0], v_17120);
    env = stack[-6];
    v_17121 = Lmkquote(nil, v_17120);
    env = stack[-6];
    goto v_17068;
v_17069:
    v_17120 = stack[-4];
    v_17120 = qcdr(v_17120);
    v_17120 = qcdr(v_17120);
    v_17120 = qcar(v_17120);
    goto v_17070;
v_17071:
    goto v_17065;
v_17066:
    goto v_17067;
v_17068:
    goto v_17069;
v_17070:
    v_17122 = list3(stack[-1], v_17121, v_17120);
    env = stack[-6];
    goto v_17058;
v_17059:
    v_17121 = stack[-3];
    goto v_17060;
v_17061:
    v_17120 = stack[-2];
    goto v_17062;
v_17063:
    goto v_17057;
v_17058:
    goto v_17059;
v_17060:
    goto v_17061;
v_17062:
    fn = elt(env, 10); // formc!*
    v_17120 = (*qfnn(fn))(fn, 3, v_17122, v_17121, v_17120);
    goto v_17053;
v_17054:
    goto v_17050;
v_17051:
    goto v_17052;
v_17053:
    {
        LispObject v_17134 = stack[-5];
        return list2(v_17134, v_17120);
    }
v_17040:
    goto v_17107;
v_17103:
    stack[0] = elt(env, 2); // boolvalue!*
    goto v_17104;
v_17105:
    goto v_17116;
v_17110:
    v_17122 = stack[-4];
    goto v_17111;
v_17112:
    v_17121 = stack[-3];
    goto v_17113;
v_17114:
    v_17120 = stack[-2];
    goto v_17115;
v_17116:
    goto v_17110;
v_17111:
    goto v_17112;
v_17113:
    goto v_17114;
v_17115:
    fn = elt(env, 10); // formc!*
    v_17120 = (*qfnn(fn))(fn, 3, v_17122, v_17121, v_17120);
    goto v_17106;
v_17107:
    goto v_17103;
v_17104:
    goto v_17105;
v_17106:
    {
        LispObject v_17135 = stack[0];
        return list2(v_17135, v_17120);
    }
    v_17120 = nil;
v_16834:
    return onevalue(v_17120);
}



// Code for even_action_sf

static LispObject CC_even_action_sf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16889, v_16890, v_16891, v_16892;
    LispObject fn;
    LispObject v_16832, v_16831, v_16830, v_16829;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "even_action_sf");
    va_start(aa, nargs);
    v_16829 = va_arg(aa, LispObject);
    v_16830 = va_arg(aa, LispObject);
    v_16831 = va_arg(aa, LispObject);
    v_16832 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_16832,v_16831,v_16830,v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_16829,v_16830,v_16831,v_16832);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_16832;
    stack[-1] = v_16831;
    stack[-2] = v_16830;
    stack[-3] = v_16829;
// end of prologue
    goto v_16842;
v_16838:
    v_16890 = nil;
    goto v_16839;
v_16840:
    v_16889 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16841;
v_16842:
    goto v_16838;
v_16839:
    goto v_16840;
v_16841:
    v_16889 = cons(v_16890, v_16889);
    env = stack[-5];
    v_16890 = v_16889;
v_16847:
    v_16889 = stack[-2];
    if (!consp(v_16889)) goto v_16854;
    else goto v_16855;
v_16854:
    v_16889 = lisp_true;
    goto v_16853;
v_16855:
    v_16889 = stack[-2];
    v_16889 = qcar(v_16889);
    v_16889 = (consp(v_16889) ? nil : lisp_true);
    goto v_16853;
    v_16889 = nil;
v_16853:
    if (v_16889 == nil) goto v_16851;
    goto v_16846;
v_16851:
    goto v_16869;
v_16865:
    stack[-4] = v_16890;
    goto v_16866;
v_16867:
    goto v_16880;
v_16872:
    v_16892 = stack[-3];
    goto v_16873;
v_16874:
    v_16889 = stack[-2];
    v_16891 = qcar(v_16889);
    goto v_16875;
v_16876:
    v_16890 = stack[-1];
    goto v_16877;
v_16878:
    v_16889 = stack[0];
    goto v_16879;
v_16880:
    goto v_16872;
v_16873:
    goto v_16874;
v_16875:
    goto v_16876;
v_16877:
    goto v_16878;
v_16879:
    fn = elt(env, 1); // even_action_term
    v_16889 = (*qfnn(fn))(fn, 4, v_16892, v_16891, v_16890, v_16889);
    env = stack[-5];
    goto v_16868;
v_16869:
    goto v_16865;
v_16866:
    goto v_16867;
v_16868:
    fn = elt(env, 2); // addsq
    v_16889 = (*qfn2(fn))(fn, stack[-4], v_16889);
    env = stack[-5];
    v_16890 = v_16889;
    v_16889 = stack[-2];
    v_16889 = qcdr(v_16889);
    stack[-2] = v_16889;
    goto v_16847;
v_16846:
    v_16889 = v_16890;
    return onevalue(v_16889);
}



// Code for matrix_rows

static LispObject CC_matrix_rows(LispObject env,
                         LispObject v_16829)
{
    env = qenv(env);
    LispObject v_16853;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16829);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_16829;
// end of prologue
    v_16853 = stack[0];
    if (v_16853 == nil) goto v_16836;
    v_16853 = elt(env, 1); // "<matrixrow>"
    fn = elt(env, 3); // printout
    v_16853 = (*qfn1(fn))(fn, v_16853);
    env = stack[-1];
    v_16853 = lisp_true;
    fn = elt(env, 4); // indent!*
    v_16853 = (*qfn1(fn))(fn, v_16853);
    env = stack[-1];
    v_16853 = stack[0];
    v_16853 = qcar(v_16853);
    fn = elt(env, 5); // row
    v_16853 = (*qfn1(fn))(fn, v_16853);
    env = stack[-1];
    v_16853 = nil;
    fn = elt(env, 4); // indent!*
    v_16853 = (*qfn1(fn))(fn, v_16853);
    env = stack[-1];
    v_16853 = elt(env, 2); // "</matrixrow>"
    fn = elt(env, 3); // printout
    v_16853 = (*qfn1(fn))(fn, v_16853);
    env = stack[-1];
    v_16853 = stack[0];
    v_16853 = qcdr(v_16853);
    v_16853 = CC_matrix_rows(elt(env, 0), v_16853);
    goto v_16834;
v_16836:
v_16834:
    v_16853 = nil;
    return onevalue(v_16853);
}



// Code for sc_getrow

static LispObject CC_sc_getrow(LispObject env,
                         LispObject v_16829, LispObject v_16830)
{
    env = qenv(env);
    LispObject v_16841, v_16842;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16830,v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16829,v_16830);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_16841 = v_16830;
    v_16842 = v_16829;
// end of prologue
    goto v_16837;
v_16833:
    stack[0] = v_16842;
    goto v_16834;
v_16835:
    v_16841 = sub1(v_16841);
    env = stack[-1];
    goto v_16836;
v_16837:
    goto v_16833;
v_16834:
    goto v_16835;
v_16836:
    {
        LispObject v_16844 = stack[0];
        fn = elt(env, 1); // sc_igetv
        return (*qfn2(fn))(fn, v_16844, v_16841);
    }
}



// Code for gparg1p

static LispObject CC_gparg1p(LispObject env,
                         LispObject v_16829)
{
    env = qenv(env);
    LispObject v_16852;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16829);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_16829;
// end of prologue
v_16828:
    v_16852 = stack[0];
    if (v_16852 == nil) goto v_16833;
    else goto v_16834;
v_16833:
    v_16852 = lisp_true;
    goto v_16832;
v_16834:
    v_16852 = stack[0];
    v_16852 = qcar(v_16852);
    fn = elt(env, 1); // gpargp
    v_16852 = (*qfn1(fn))(fn, v_16852);
    env = stack[-1];
    if (v_16852 == nil) goto v_16841;
    else goto v_16842;
v_16841:
    v_16852 = nil;
    goto v_16840;
v_16842:
    v_16852 = stack[0];
    v_16852 = qcdr(v_16852);
    stack[0] = v_16852;
    goto v_16828;
    v_16852 = nil;
v_16840:
    goto v_16832;
    v_16852 = nil;
v_16832:
    return onevalue(v_16852);
}



// Code for indordn

static LispObject CC_indordn(LispObject env,
                         LispObject v_16829)
{
    env = qenv(env);
    LispObject v_16871, v_16872;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16829);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_16872 = v_16829;
// end of prologue
    v_16871 = v_16872;
    if (v_16871 == nil) goto v_16833;
    else goto v_16834;
v_16833:
    v_16871 = nil;
    goto v_16832;
v_16834:
    v_16871 = v_16872;
    v_16871 = qcdr(v_16871);
    if (v_16871 == nil) goto v_16837;
    else goto v_16838;
v_16837:
    v_16871 = v_16872;
    goto v_16832;
v_16838:
    v_16871 = v_16872;
    v_16871 = qcdr(v_16871);
    v_16871 = qcdr(v_16871);
    if (v_16871 == nil) goto v_16842;
    else goto v_16843;
v_16842:
    goto v_16852;
v_16848:
    v_16871 = v_16872;
    v_16871 = qcar(v_16871);
    goto v_16849;
v_16850:
    v_16872 = qcdr(v_16872);
    v_16872 = qcar(v_16872);
    goto v_16851;
v_16852:
    goto v_16848;
v_16849:
    goto v_16850;
v_16851:
    {
        fn = elt(env, 1); // indord2
        return (*qfn2(fn))(fn, v_16871, v_16872);
    }
v_16843:
    goto v_16865;
v_16861:
    v_16871 = v_16872;
    stack[0] = qcar(v_16871);
    goto v_16862;
v_16863:
    v_16871 = v_16872;
    v_16871 = qcdr(v_16871);
    v_16871 = CC_indordn(elt(env, 0), v_16871);
    env = stack[-1];
    goto v_16864;
v_16865:
    goto v_16861;
v_16862:
    goto v_16863;
v_16864:
    {
        LispObject v_16874 = stack[0];
        fn = elt(env, 2); // indordad
        return (*qfn2(fn))(fn, v_16874, v_16871);
    }
    v_16871 = nil;
v_16832:
    return onevalue(v_16871);
}



// Code for one!-entryp

static LispObject CC_oneKentryp(LispObject env,
                         LispObject v_16829, LispObject v_16830)
{
    env = qenv(env);
    LispObject v_16874, v_16875;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16830,v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16829,v_16830);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_16830;
    stack[-1] = v_16829;
// end of prologue
v_16834:
    v_16874 = stack[0];
    if (!consp(v_16874)) goto v_16837;
    else goto v_16838;
v_16837:
    v_16874 = lisp_true;
    goto v_16833;
v_16838:
    goto v_16848;
v_16844:
    v_16875 = stack[-1];
    goto v_16845;
v_16846:
    v_16874 = stack[0];
    v_16874 = qcar(v_16874);
    goto v_16847;
v_16848:
    goto v_16844;
v_16845:
    goto v_16846;
v_16847:
    v_16874 = Lsmemq(nil, v_16875, v_16874);
    env = stack[-2];
    if (v_16874 == nil) goto v_16842;
    goto v_16861;
v_16857:
    v_16875 = stack[-1];
    goto v_16858;
v_16859:
    v_16874 = stack[0];
    v_16874 = qcdr(v_16874);
    goto v_16860;
v_16861:
    goto v_16857;
v_16858:
    goto v_16859;
v_16860:
    v_16874 = Lsmemq(nil, v_16875, v_16874);
    env = stack[-2];
    if (v_16874 == nil) goto v_16855;
    v_16874 = nil;
    goto v_16833;
v_16855:
    v_16874 = stack[0];
    v_16874 = qcar(v_16874);
    stack[0] = v_16874;
    goto v_16834;
    goto v_16836;
v_16842:
    v_16874 = stack[0];
    v_16874 = qcdr(v_16874);
    stack[0] = v_16874;
    goto v_16834;
v_16836:
    v_16874 = nil;
v_16833:
    return onevalue(v_16874);
}



// Code for modp

static LispObject CC_modp(LispObject env,
                         LispObject v_16829, LispObject v_16830)
{
    env = qenv(env);
    LispObject v_16863, v_16864;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16830,v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16829,v_16830);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_16830;
    stack[-1] = v_16829;
// end of prologue
    goto v_16837;
v_16833:
    v_16864 = stack[-1];
    goto v_16834;
v_16835:
    v_16863 = stack[0];
    goto v_16836;
v_16837:
    goto v_16833;
v_16834:
    goto v_16835;
v_16836:
    v_16863 = Cremainder(v_16864, v_16863);
    env = stack[-2];
    stack[-1] = v_16863;
    goto v_16849;
v_16845:
    v_16864 = stack[-1];
    goto v_16846;
v_16847:
    v_16863 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16848;
v_16849:
    goto v_16845;
v_16846:
    goto v_16847;
v_16848:
    v_16863 = (LispObject)lessp2(v_16864, v_16863);
    v_16863 = v_16863 ? lisp_true : nil;
    if (v_16863 == nil) goto v_16843;
    goto v_16857;
v_16853:
    v_16864 = stack[-1];
    goto v_16854;
v_16855:
    v_16863 = stack[0];
    goto v_16856;
v_16857:
    goto v_16853;
v_16854:
    goto v_16855;
v_16856:
    return plus2(v_16864, v_16863);
v_16843:
    v_16863 = stack[-1];
    goto v_16841;
    v_16863 = nil;
v_16841:
    return onevalue(v_16863);
}



// Code for horner!-rule!-for!-one!-var

static LispObject CC_hornerKruleKforKoneKvar(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16970, v_16971, v_16972, v_16973, v_16974, v_16975, v_16976;
    LispObject fn;
    LispObject v_16833, v_16832, v_16831, v_16830, v_16829;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "horner-rule-for-one-var");
    va_start(aa, nargs);
    v_16829 = va_arg(aa, LispObject);
    v_16830 = va_arg(aa, LispObject);
    v_16831 = va_arg(aa, LispObject);
    v_16832 = va_arg(aa, LispObject);
    v_16833 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_16833,v_16832,v_16831,v_16830,v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_16829,v_16830,v_16831,v_16832,v_16833);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_16971 = v_16833;
    v_16972 = v_16832;
    v_16973 = v_16831;
    v_16974 = v_16830;
    v_16975 = v_16829;
// end of prologue
v_16828:
    v_16970 = v_16975;
    if (!consp(v_16970)) goto v_16845;
    else goto v_16846;
v_16845:
    v_16970 = lisp_true;
    goto v_16844;
v_16846:
    v_16970 = v_16975;
    v_16970 = qcar(v_16970);
    v_16970 = (consp(v_16970) ? nil : lisp_true);
    goto v_16844;
    v_16970 = nil;
v_16844:
    if (v_16970 == nil) goto v_16842;
    v_16970 = lisp_true;
    goto v_16840;
v_16842:
    goto v_16861;
v_16857:
    v_16970 = v_16975;
    v_16970 = qcar(v_16970);
    v_16970 = qcar(v_16970);
    v_16976 = qcar(v_16970);
    goto v_16858;
v_16859:
    v_16970 = v_16974;
    goto v_16860;
v_16861:
    goto v_16857;
v_16858:
    goto v_16859;
v_16860:
    v_16970 = (equal(v_16976, v_16970) ? lisp_true : nil);
    v_16970 = (v_16970 == nil ? lisp_true : nil);
    goto v_16840;
    v_16970 = nil;
v_16840:
    if (v_16970 == nil) goto v_16838;
    v_16970 = v_16973;
    v_16970 = (LispObject)zerop(v_16970);
    v_16970 = v_16970 ? lisp_true : nil;
    env = stack[-6];
    if (v_16970 == nil) goto v_16872;
    v_16970 = v_16975;
    goto v_16870;
v_16872:
    goto v_16883;
v_16879:
    stack[-1] = v_16975;
    goto v_16880;
v_16881:
    goto v_16890;
v_16886:
    stack[0] = v_16972;
    goto v_16887;
v_16888:
    goto v_16898;
v_16894:
    v_16970 = v_16973;
    goto v_16895;
v_16896:
    goto v_16897;
v_16898:
    goto v_16894;
v_16895:
    goto v_16896;
v_16897:
    v_16970 = Lexpt(nil, v_16970, v_16971);
    env = stack[-6];
    fn = elt(env, 1); // !*n2f
    v_16970 = (*qfn1(fn))(fn, v_16970);
    env = stack[-6];
    goto v_16889;
v_16890:
    goto v_16886;
v_16887:
    goto v_16888;
v_16889:
    fn = elt(env, 2); // multf
    v_16970 = (*qfn2(fn))(fn, stack[0], v_16970);
    env = stack[-6];
    goto v_16882;
v_16883:
    goto v_16879;
v_16880:
    goto v_16881;
v_16882:
    {
        LispObject v_16983 = stack[-1];
        fn = elt(env, 3); // addf
        return (*qfn2(fn))(fn, v_16983, v_16970);
    }
    v_16970 = nil;
v_16870:
    goto v_16836;
v_16838:
    v_16970 = v_16975;
    v_16970 = qcar(v_16970);
    v_16970 = qcar(v_16970);
    v_16970 = qcdr(v_16970);
    stack[-5] = v_16970;
    goto v_16921;
v_16911:
    v_16970 = v_16975;
    stack[-4] = qcdr(v_16970);
    goto v_16912;
v_16913:
    stack[-3] = v_16974;
    goto v_16914;
v_16915:
    stack[-2] = v_16973;
    goto v_16916;
v_16917:
    v_16970 = v_16973;
    v_16970 = (LispObject)zerop(v_16970);
    v_16970 = v_16970 ? lisp_true : nil;
    env = stack[-6];
    if (v_16970 == nil) goto v_16929;
    v_16970 = v_16975;
    v_16970 = qcar(v_16970);
    v_16970 = qcdr(v_16970);
    v_16971 = v_16970;
    goto v_16927;
v_16929:
    goto v_16942;
v_16938:
    v_16970 = v_16975;
    v_16970 = qcar(v_16970);
    stack[-1] = qcdr(v_16970);
    goto v_16939;
v_16940:
    goto v_16951;
v_16947:
    stack[0] = v_16972;
    goto v_16948;
v_16949:
    goto v_16959;
v_16955:
    v_16972 = v_16973;
    goto v_16956;
v_16957:
    goto v_16965;
v_16961:
    goto v_16962;
v_16963:
    v_16970 = stack[-5];
    goto v_16964;
v_16965:
    goto v_16961;
v_16962:
    goto v_16963;
v_16964:
    v_16970 = (LispObject)(intptr_t)((intptr_t)v_16971 - (intptr_t)v_16970 + TAG_FIXNUM);
    goto v_16958;
v_16959:
    goto v_16955;
v_16956:
    goto v_16957;
v_16958:
    v_16970 = Lexpt(nil, v_16972, v_16970);
    env = stack[-6];
    fn = elt(env, 1); // !*n2f
    v_16970 = (*qfn1(fn))(fn, v_16970);
    env = stack[-6];
    goto v_16950;
v_16951:
    goto v_16947;
v_16948:
    goto v_16949;
v_16950:
    fn = elt(env, 2); // multf
    v_16970 = (*qfn2(fn))(fn, stack[0], v_16970);
    env = stack[-6];
    goto v_16941;
v_16942:
    goto v_16938;
v_16939:
    goto v_16940;
v_16941:
    fn = elt(env, 3); // addf
    v_16970 = (*qfn2(fn))(fn, stack[-1], v_16970);
    env = stack[-6];
    v_16971 = v_16970;
    goto v_16927;
    v_16971 = nil;
v_16927:
    goto v_16918;
v_16919:
    v_16970 = stack[-5];
    goto v_16920;
v_16921:
    goto v_16911;
v_16912:
    goto v_16913;
v_16914:
    goto v_16915;
v_16916:
    goto v_16917;
v_16918:
    goto v_16919;
v_16920:
    v_16975 = stack[-4];
    v_16974 = stack[-3];
    v_16973 = stack[-2];
    v_16972 = v_16971;
    v_16971 = v_16970;
    goto v_16828;
    goto v_16836;
    v_16970 = nil;
v_16836:
    return onevalue(v_16970);
}



// Code for lalr_process_reductions

static LispObject CC_lalr_process_reductions(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_17038, v_17039, v_17040;
    LispObject fn;
    argcheck(nargs, 0, "lalr_process_reductions");
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
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// end of prologue
    stack[-6] = nil;
    v_17038 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[-4] = v_17038;
    v_17038 = qvalue(elt(env, 1)); // nonterminals
    stack[-5] = v_17038;
v_16847:
    v_17038 = stack[-5];
    if (v_17038 == nil) goto v_16851;
    else goto v_16852;
v_16851:
    goto v_16846;
v_16852:
    v_17038 = stack[-5];
    v_17038 = qcar(v_17038);
    stack[-3] = v_17038;
    v_17038 = stack[-3];
    fn = elt(env, 3); // lalr_productions
    v_17038 = (*qfn1(fn))(fn, v_17038);
    env = stack[-7];
    stack[-2] = v_17038;
v_16861:
    v_17038 = stack[-2];
    if (v_17038 == nil) goto v_16866;
    else goto v_16867;
v_16866:
    goto v_16860;
v_16867:
    v_17038 = stack[-2];
    v_17038 = qcar(v_17038);
    stack[-1] = v_17038;
    goto v_16880;
v_16874:
    stack[0] = stack[-3];
    goto v_16875;
v_16876:
    v_17038 = stack[-1];
    v_17038 = qcar(v_17038);
    v_17039 = Llength(nil, v_17038);
    env = stack[-7];
    goto v_16877;
v_16878:
    v_17038 = stack[-1];
    v_17038 = qcdr(v_17038);
    goto v_16879;
v_16880:
    goto v_16874;
v_16875:
    goto v_16876;
v_16877:
    goto v_16878;
v_16879:
    v_17038 = acons(stack[0], v_17039, v_17038);
    env = stack[-7];
    v_17040 = v_17038;
    goto v_16891;
v_16887:
    v_17039 = v_17040;
    goto v_16888;
v_16889:
    v_17038 = stack[-6];
    goto v_16890;
v_16891:
    goto v_16887;
v_16888:
    goto v_16889;
v_16890:
    v_17038 = Lassoc(nil, v_17039, v_17038);
    stack[0] = v_17038;
    v_17038 = stack[0];
    if (v_17038 == nil) goto v_16897;
    else goto v_16898;
v_16897:
    goto v_16905;
v_16901:
    stack[0] = v_17040;
    goto v_16902;
v_16903:
    v_17038 = stack[-4];
    v_17038 = add1(v_17038);
    env = stack[-7];
    stack[-4] = v_17038;
    goto v_16904;
v_16905:
    goto v_16901;
v_16902:
    goto v_16903;
v_16904:
    v_17038 = cons(stack[0], v_17038);
    env = stack[-7];
    stack[0] = v_17038;
    goto v_16914;
v_16910:
    v_17039 = stack[0];
    goto v_16911;
v_16912:
    v_17038 = stack[-6];
    goto v_16913;
v_16914:
    goto v_16910;
v_16911:
    goto v_16912;
v_16913:
    v_17038 = cons(v_17039, v_17038);
    env = stack[-7];
    stack[-6] = v_17038;
    goto v_16896;
v_16898:
v_16896:
    goto v_16922;
v_16918:
    v_17039 = stack[-1];
    goto v_16919;
v_16920:
    v_17038 = stack[0];
    v_17038 = qcdr(v_17038);
    goto v_16921;
v_16922:
    goto v_16918;
v_16919:
    goto v_16920;
v_16921:
    v_17038 = Lrplacd(nil, v_17039, v_17038);
    env = stack[-7];
    v_17038 = stack[-2];
    v_17038 = qcdr(v_17038);
    stack[-2] = v_17038;
    goto v_16861;
v_16860:
    v_17038 = stack[-5];
    v_17038 = qcdr(v_17038);
    stack[-5] = v_17038;
    goto v_16847;
v_16846:
    v_17038 = stack[-4];
    v_17038 = add1(v_17038);
    env = stack[-7];
    stack[0] = v_17038;
    v_17038 = stack[0];
    v_17038 = sub1(v_17038);
    env = stack[-7];
    v_17038 = Lmkvect(nil, v_17038);
    env = stack[-7];
    stack[-5] = v_17038;
    v_17038 = stack[0];
    v_17038 = sub1(v_17038);
    env = stack[-7];
    fn = elt(env, 4); // mkvect16
    v_17038 = (*qfn1(fn))(fn, v_17038);
    env = stack[-7];
    stack[-3] = v_17038;
    v_17038 = stack[0];
    v_17038 = sub1(v_17038);
    env = stack[-7];
    fn = elt(env, 5); // mkvect8
    v_17038 = (*qfn1(fn))(fn, v_17038);
    env = stack[-7];
    stack[-2] = v_17038;
    v_17038 = stack[-6];
    stack[-1] = v_17038;
v_16944:
    v_17038 = stack[-1];
    if (v_17038 == nil) goto v_16948;
    else goto v_16949;
v_16948:
    goto v_16943;
v_16949:
    v_17038 = stack[-1];
    v_17038 = qcar(v_17038);
    stack[0] = v_17038;
    v_17038 = stack[0];
    v_17038 = qcdr(v_17038);
    stack[-4] = v_17038;
    v_17038 = stack[0];
    v_17038 = qcar(v_17038);
    v_17038 = qcar(v_17038);
    v_17038 = qcdr(v_17038);
    stack[-6] = v_17038;
    goto v_16966;
v_16962:
    v_17038 = stack[0];
    v_17038 = qcar(v_17038);
    v_17038 = qcar(v_17038);
    v_17039 = qcar(v_17038);
    goto v_16963;
v_16964:
    v_17038 = elt(env, 2); // lalr_nonterminal_code
    goto v_16965;
v_16966:
    goto v_16962;
v_16963:
    goto v_16964;
v_16965:
    v_17038 = get(v_17039, v_17038);
    env = stack[-7];
    goto v_16979;
v_16973:
    v_17040 = stack[-3];
    goto v_16974;
v_16975:
    v_17039 = stack[-4];
    goto v_16976;
v_16977:
    goto v_16978;
v_16979:
    goto v_16973;
v_16974:
    goto v_16975;
v_16976:
    goto v_16977;
v_16978:
    fn = elt(env, 6); // putv16
    v_17038 = (*qfnn(fn))(fn, 3, v_17040, v_17039, v_17038);
    env = stack[-7];
    goto v_16990;
v_16984:
    v_17040 = stack[-2];
    goto v_16985;
v_16986:
    v_17039 = stack[-4];
    goto v_16987;
v_16988:
    v_17038 = stack[-6];
    goto v_16989;
v_16990:
    goto v_16984;
v_16985:
    goto v_16986;
v_16987:
    goto v_16988;
v_16989:
    fn = elt(env, 7); // putv8
    v_17038 = (*qfnn(fn))(fn, 3, v_17040, v_17039, v_17038);
    env = stack[-7];
    v_17038 = stack[0];
    v_17038 = qcar(v_17038);
    v_17038 = qcdr(v_17038);
    if (v_17038 == nil) goto v_16997;
    v_17038 = stack[0];
    v_17038 = qcar(v_17038);
    v_17038 = qcdr(v_17038);
    goto v_17009;
v_17005:
    v_17039 = v_17038;
    goto v_17006;
v_17007:
    v_17038 = stack[-6];
    goto v_17008;
v_17009:
    goto v_17005;
v_17006:
    goto v_17007;
v_17008:
    fn = elt(env, 8); // lalr_construct_fn
    v_17038 = (*qfn2(fn))(fn, v_17039, v_17038);
    env = stack[-7];
    goto v_16995;
v_16997:
    v_17038 = nil;
    goto v_16995;
v_16995:
    goto v_17021;
v_17015:
    v_17040 = stack[-5];
    goto v_17016;
v_17017:
    v_17039 = stack[-4];
    goto v_17018;
v_17019:
    goto v_17020;
v_17021:
    goto v_17015;
v_17016:
    goto v_17017;
v_17018:
    goto v_17019;
v_17020:
    *(LispObject *)((char *)v_17040 + (CELL-TAG_VECTOR) + (((intptr_t)v_17039-TAG_FIXNUM)/(16/CELL))) = v_17038;
    v_17038 = stack[-1];
    v_17038 = qcdr(v_17038);
    stack[-1] = v_17038;
    goto v_16944;
v_16943:
    goto v_17034;
v_17028:
    v_17040 = stack[-5];
    goto v_17029;
v_17030:
    v_17039 = stack[-2];
    goto v_17031;
v_17032:
    v_17038 = stack[-3];
    goto v_17033;
v_17034:
    goto v_17028;
v_17029:
    goto v_17030;
v_17031:
    goto v_17032;
v_17033:
    return list3(v_17040, v_17039, v_17038);
    return onevalue(v_17038);
}



// Code for profile_a_package

static LispObject CC_profile_a_package(LispObject env,
                         LispObject v_16829)
{
    env = qenv(env);
    LispObject v_17569, v_17570, v_17571, v_17572, v_17573;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_16829);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_16829;
// end of prologue
// Binding !*errcont
// FLUIDBIND: reloadenv=9 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-9, 1, -2);
    qvalue(elt(env, 1)) = nil; // !*errcont
    v_17569 = elt(env, 2); // cpulimit
    v_17569 = Lboundp(nil, v_17569);
    env = stack[-9];
    if (v_17569 == nil) goto v_16847;
    else goto v_16848;
v_16847:
    v_17569 = lisp_true;
    goto v_16846;
v_16848:
    v_17569 = qvalue(elt(env, 2)); // cpulimit
    v_17569 = Lexplodec(nil, v_17569);
    env = stack[-9];
    v_17569 = Lcompress(nil, v_17569);
    env = stack[-9];
    qvalue(elt(env, 2)) = v_17569; // cpulimit
    v_17569 = integerp(v_17569);
    if (v_17569 == nil) goto v_16856;
    else goto v_16857;
v_16856:
    v_17569 = lisp_true;
    goto v_16855;
v_16857:
    goto v_16870;
v_16866:
    v_17570 = qvalue(elt(env, 2)); // cpulimit
    goto v_16867;
v_16868:
    v_17569 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16869;
v_16870:
    goto v_16866;
v_16867:
    goto v_16868;
v_16869:
    v_17569 = (LispObject)lessp2(v_17570, v_17569);
    v_17569 = v_17569 ? lisp_true : nil;
    env = stack[-9];
    goto v_16855;
    v_17569 = nil;
v_16855:
    goto v_16846;
    v_17569 = nil;
v_16846:
    if (v_17569 == nil) goto v_16844;
    goto v_16881;
v_16877:
    v_17570 = elt(env, 3); // jlisp
    goto v_16878;
v_16879:
    v_17569 = qvalue(elt(env, 4)); // lispsystem!*
    goto v_16880;
v_16881:
    goto v_16877;
v_16878:
    goto v_16879;
v_16880:
    v_17569 = Lmemq(nil, v_17570, v_17569);
    if (v_17569 == nil) goto v_16876;
    v_17569 = (LispObject)80000+TAG_FIXNUM; // 5000
    goto v_16874;
v_16876:
    v_17569 = (LispObject)2880+TAG_FIXNUM; // 180
    goto v_16874;
    v_17569 = nil;
v_16874:
    qvalue(elt(env, 2)) = v_17569; // cpulimit
    goto v_16842;
v_16844:
v_16842:
    v_17569 = elt(env, 5); // conslimit
    v_17569 = Lboundp(nil, v_17569);
    env = stack[-9];
    if (v_17569 == nil) goto v_16895;
    else goto v_16896;
v_16895:
    v_17569 = lisp_true;
    goto v_16894;
v_16896:
    v_17569 = qvalue(elt(env, 5)); // conslimit
    v_17569 = Lexplodec(nil, v_17569);
    env = stack[-9];
    v_17569 = Lcompress(nil, v_17569);
    env = stack[-9];
    qvalue(elt(env, 5)) = v_17569; // conslimit
    v_17569 = integerp(v_17569);
    if (v_17569 == nil) goto v_16904;
    else goto v_16905;
v_16904:
    v_17569 = lisp_true;
    goto v_16903;
v_16905:
    goto v_16918;
v_16914:
    v_17570 = qvalue(elt(env, 5)); // conslimit
    goto v_16915;
v_16916:
    v_17569 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16917;
v_16918:
    goto v_16914;
v_16915:
    goto v_16916;
v_16917:
    v_17569 = (LispObject)lessp2(v_17570, v_17569);
    v_17569 = v_17569 ? lisp_true : nil;
    env = stack[-9];
    goto v_16903;
    v_17569 = nil;
v_16903:
    goto v_16894;
    v_17569 = nil;
v_16894:
    if (v_17569 == nil) goto v_16892;
    v_17569 = (LispObject)32000+TAG_FIXNUM; // 2000
    qvalue(elt(env, 5)) = v_17569; // conslimit
    goto v_16890;
v_16892:
v_16890:
    v_17569 = elt(env, 6); // "PROFILING: "
    v_17569 = Lprinc(nil, v_17569);
    env = stack[-9];
    v_17569 = stack[-7];
    v_17569 = qcar(v_17569);
    v_17569 = Lprint(nil, v_17569);
    env = stack[-9];
    v_17569 = nil;
    qvalue(elt(env, 7)) = v_17569; // !*backtrace
    v_17569 = lisp_true;
    qvalue(elt(env, 1)) = v_17569; // !*errcont
    v_17569 = nil;
    qvalue(elt(env, 8)) = v_17569; // !*int
    v_17569 = stack[-7];
    v_17569 = qcar(v_17569);
    stack[-8] = v_17569;
    v_17569 = nil;
    v_17569 = Lverbos(nil, v_17569);
    env = stack[-9];
    fn = elt(env, 53); // get_configuration_data
    v_17569 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    goto v_16943;
v_16939:
    v_17570 = stack[-8];
    goto v_16940;
v_16941:
    v_17569 = qvalue(elt(env, 9)); // reduce_regression_tests
    goto v_16942;
v_16943:
    goto v_16939;
v_16940:
    goto v_16941;
v_16942:
    v_17569 = Lmemq(nil, v_17570, v_17569);
    if (v_17569 == nil) goto v_16937;
    else goto v_16938;
v_16937:
    v_17569 = stack[-8];
    fn = elt(env, 54); // load!-package
    v_17569 = (*qfn1(fn))(fn, v_17569);
    env = stack[-9];
    goto v_16958;
v_16954:
    v_17570 = stack[-8];
    goto v_16955;
v_16956:
    v_17569 = elt(env, 10); // folder
    goto v_16957;
v_16958:
    goto v_16954;
v_16955:
    goto v_16956;
v_16957:
    v_17569 = get(v_17570, v_17569);
    env = stack[-9];
    if (v_17569 == nil) goto v_16952;
    goto v_16966;
v_16962:
    v_17570 = stack[-8];
    goto v_16963;
v_16964:
    v_17569 = elt(env, 10); // folder
    goto v_16965;
v_16966:
    goto v_16962;
v_16963:
    goto v_16964;
v_16965:
    v_17569 = get(v_17570, v_17569);
    env = stack[-9];
    stack[-8] = v_17569;
    goto v_16950;
v_16952:
v_16950:
    goto v_16974;
v_16970:
    v_17570 = elt(env, 11); // "$reduce/packages/"
    goto v_16971;
v_16972:
    v_17569 = stack[-8];
    goto v_16973;
v_16974:
    goto v_16970;
v_16971:
    goto v_16972;
v_16973:
    fn = elt(env, 55); // concat
    v_17569 = (*qfn2(fn))(fn, v_17570, v_17569);
    env = stack[-9];
    qvalue(elt(env, 12)) = v_17569; // testdirectory
    goto v_16982;
v_16978:
    stack[-1] = elt(env, 11); // "$reduce/packages/"
    goto v_16979;
v_16980:
    goto v_16989;
v_16985:
    stack[-3] = stack[-8];
    goto v_16986;
v_16987:
    goto v_16996;
v_16992:
    stack[0] = elt(env, 13); // "/"
    goto v_16993;
v_16994:
    goto v_17003;
v_16999:
    v_17569 = stack[-7];
    v_17570 = qcar(v_17569);
    goto v_17000;
v_17001:
    v_17569 = elt(env, 14); // ".tst"
    goto v_17002;
v_17003:
    goto v_16999;
v_17000:
    goto v_17001;
v_17002:
    fn = elt(env, 55); // concat
    v_17569 = (*qfn2(fn))(fn, v_17570, v_17569);
    env = stack[-9];
    goto v_16995;
v_16996:
    goto v_16992;
v_16993:
    goto v_16994;
v_16995:
    fn = elt(env, 55); // concat
    v_17569 = (*qfn2(fn))(fn, stack[0], v_17569);
    env = stack[-9];
    goto v_16988;
v_16989:
    goto v_16985;
v_16986:
    goto v_16987;
v_16988:
    fn = elt(env, 55); // concat
    v_17569 = (*qfn2(fn))(fn, stack[-3], v_17569);
    env = stack[-9];
    goto v_16981;
v_16982:
    goto v_16978;
v_16979:
    goto v_16980;
v_16981:
    fn = elt(env, 55); // concat
    v_17569 = (*qfn2(fn))(fn, stack[-1], v_17569);
    env = stack[-9];
    stack[-8] = v_17569;
    v_17569 = (LispObject)1280+TAG_FIXNUM; // 80
    v_17569 = Llinelength(nil, v_17569);
    env = stack[-9];
    stack[-6] = v_17569;
    v_17569 = nil;
    v_17569 = ncons(v_17569);
    env = stack[-9];
    qvalue(elt(env, 15)) = v_17569; // alglist!*
    v_17569 = elt(env, 16); // algebraic
    qvalue(elt(env, 17)) = v_17569; // !*mode
    goto v_17019;
v_17015:
    v_17569 = elt(env, 18); // "[Profile] "
    stack[0] = Lexplodec(nil, v_17569);
    env = stack[-9];
    goto v_17016;
v_17017:
    v_17569 = stack[-7];
    v_17569 = qcar(v_17569);
    v_17569 = Lexplodec(nil, v_17569);
    env = stack[-9];
    goto v_17018;
v_17019:
    goto v_17015;
v_17016:
    goto v_17017;
v_17018:
    v_17569 = Lappend(nil, stack[0], v_17569);
    env = stack[-9];
    fn = elt(env, 56); // list!-to!-string
    v_17569 = (*qfn1(fn))(fn, v_17569);
    env = stack[-9];
    fn = elt(env, 57); // window!-heading
    v_17569 = (*qfn1(fn))(fn, v_17569);
    env = stack[-9];
    v_17569 = elt(env, 19); // quit
    fn = elt(env, 58); // getd
    v_17569 = (*qfn1(fn))(fn, v_17569);
    env = stack[-9];
    stack[-3] = v_17569;
    v_17569 = elt(env, 19); // quit
    v_17569 = Lremd(nil, v_17569);
    env = stack[-9];
    goto v_17036;
v_17030:
    v_17571 = elt(env, 19); // quit
    goto v_17031;
v_17032:
    v_17570 = elt(env, 20); // expr
    goto v_17033;
v_17034:
    v_17569 = elt(env, 21); // posn
    goto v_17035;
v_17036:
    goto v_17030;
v_17031:
    goto v_17032;
v_17033:
    goto v_17034;
v_17035:
    fn = elt(env, 59); // putd
    v_17569 = (*qfnn(fn))(fn, 3, v_17571, v_17570, v_17569);
    env = stack[-9];
    v_17569 = (LispObject)64+TAG_FIXNUM; // 4
    v_17569 = Lmapstore(nil, v_17569);
    env = stack[-9];
    v_17569 = lisp_true;
    qvalue(elt(env, 1)) = v_17569; // !*errcont
    v_17569 = nil;
    v_17569 = Lwrs(nil, v_17569);
    env = stack[-9];
    stack[-5] = v_17569;
    v_17569 = nil;
    v_17569 = Lrds(nil, v_17569);
    env = stack[-9];
    stack[-4] = v_17569;
    v_17569 = stack[-5];
    v_17569 = Lwrs(nil, v_17569);
    env = stack[-9];
    v_17569 = stack[-4];
    v_17569 = Lrds(nil, v_17569);
    env = stack[-9];
    goto v_17062;
v_17052:
    goto v_17072;
v_17064:
    stack[-1] = elt(env, 22); // errorset
    goto v_17065;
v_17066:
    goto v_17082;
v_17076:
    stack[0] = elt(env, 23); // in_list1
    goto v_17077;
v_17078:
    v_17569 = stack[-8];
    v_17570 = Lmkquote(nil, v_17569);
    env = stack[-9];
    goto v_17079;
v_17080:
    v_17569 = lisp_true;
    goto v_17081;
v_17082:
    goto v_17076;
v_17077:
    goto v_17078;
v_17079:
    goto v_17080;
v_17081:
    v_17569 = list3(stack[0], v_17570, v_17569);
    env = stack[-9];
    v_17571 = Lmkquote(nil, v_17569);
    env = stack[-9];
    goto v_17067;
v_17068:
    v_17570 = nil;
    goto v_17069;
v_17070:
    v_17569 = nil;
    goto v_17071;
v_17072:
    goto v_17064;
v_17065:
    goto v_17066;
v_17067:
    goto v_17068;
v_17069:
    goto v_17070;
v_17071:
    v_17573 = list4(stack[-1], v_17571, v_17570, v_17569);
    env = stack[-9];
    goto v_17053;
v_17054:
    v_17572 = qvalue(elt(env, 2)); // cpulimit
    goto v_17055;
v_17056:
    v_17571 = qvalue(elt(env, 5)); // conslimit
    goto v_17057;
v_17058:
    v_17570 = (LispObject)160000+TAG_FIXNUM; // 10000
    goto v_17059;
v_17060:
    v_17569 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_17061;
v_17062:
    goto v_17052;
v_17053:
    goto v_17054;
v_17055:
    goto v_17056;
v_17057:
    goto v_17058;
v_17059:
    goto v_17060;
v_17061:
    fn = elt(env, 60); // resource!-limit
    v_17569 = (*qfnn(fn))(fn, 5, v_17573, v_17572, v_17571, v_17570, v_17569);
    env = stack[-9];
    stack[0] = v_17569;
    v_17569 = stack[-5];
    v_17569 = Lwrs(nil, v_17569);
    env = stack[-9];
    v_17569 = stack[-4];
    v_17569 = Lrds(nil, v_17569);
    env = stack[-9];
    v_17569 = nil;
    qvalue(elt(env, 24)) = v_17569; // erfg!*
    v_17569 = Lterpri(nil, 0);
    env = stack[-9];
    goto v_17106;
v_17100:
    v_17571 = elt(env, 19); // quit
    goto v_17101;
v_17102:
    v_17569 = stack[-3];
    v_17570 = qcar(v_17569);
    goto v_17103;
v_17104:
    v_17569 = stack[-3];
    v_17569 = qcdr(v_17569);
    goto v_17105;
v_17106:
    goto v_17100;
v_17101:
    goto v_17102;
v_17103:
    goto v_17104;
v_17105:
    fn = elt(env, 59); // putd
    v_17569 = (*qfnn(fn))(fn, 3, v_17571, v_17570, v_17569);
    env = stack[-9];
    goto v_17117;
v_17113:
    v_17569 = (LispObject)32+TAG_FIXNUM; // 2
    v_17570 = Lmapstore(nil, v_17569);
    env = stack[-9];
    goto v_17114;
v_17115:
    v_17569 = elt(env, 25); // profile_compare_fn
    goto v_17116;
v_17117:
    goto v_17113;
v_17114:
    goto v_17115;
v_17116:
    fn = elt(env, 61); // sort
    v_17569 = (*qfn2(fn))(fn, v_17570, v_17569);
    env = stack[-9];
    stack[-5] = v_17569;
    goto v_17130;
v_17126:
    v_17570 = elt(env, 26); // "buildlogs/flaguse.log"
    goto v_17127;
v_17128:
    v_17569 = elt(env, 27); // append
    goto v_17129;
v_17130:
    goto v_17126;
v_17127:
    goto v_17128;
v_17129:
    fn = elt(env, 62); // open
    v_17569 = (*qfn2(fn))(fn, v_17570, v_17569);
    env = stack[-9];
    v_17569 = Lwrs(nil, v_17569);
    env = stack[-9];
    stack[-1] = v_17569;
    v_17569 = lisp_true;
    fn = elt(env, 63); // bytecounts
    v_17569 = (*qfn1(fn))(fn, v_17569);
    env = stack[-9];
    v_17569 = stack[-1];
    v_17569 = Lwrs(nil, v_17569);
    env = stack[-9];
    v_17569 = Lclose(nil, v_17569);
    env = stack[-9];
    fn = elt(env, 64); // load!-source
    v_17569 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    v_17569 = nil;
    stack[-4] = v_17569;
v_17142:
    v_17569 = stack[-5];
    if (v_17569 == nil) goto v_17145;
    else goto v_17146;
v_17145:
    goto v_17141;
v_17146:
    goto v_17154;
v_17150:
    v_17569 = stack[-5];
    v_17569 = qcar(v_17569);
    v_17570 = qcar(v_17569);
    goto v_17151;
v_17152:
    v_17569 = elt(env, 28); // !*savedef
    goto v_17153;
v_17154:
    goto v_17150;
v_17151:
    goto v_17152;
v_17153:
    v_17569 = get(v_17570, v_17569);
    env = stack[-9];
    v_17571 = v_17569;
    goto v_17168;
v_17164:
    v_17570 = v_17571;
    goto v_17165;
v_17166:
    v_17569 = elt(env, 29); // lambda
    goto v_17167;
v_17168:
    goto v_17164;
v_17165:
    goto v_17166;
v_17167:
    if (!consp(v_17570)) goto v_17162;
    v_17570 = qcar(v_17570);
    if (v_17570 == v_17569) goto v_17161;
    else goto v_17162;
v_17161:
    goto v_17178;
v_17172:
    v_17569 = stack[-5];
    v_17569 = qcar(v_17569);
    stack[-1] = qcar(v_17569);
    goto v_17173;
v_17174:
    goto v_17189;
v_17183:
    goto v_17196;
v_17192:
    v_17569 = stack[-5];
    v_17569 = qcar(v_17569);
    v_17569 = qcar(v_17569);
    goto v_17193;
v_17194:
    v_17570 = v_17571;
    v_17570 = qcdr(v_17570);
    goto v_17195;
v_17196:
    goto v_17192;
v_17193:
    goto v_17194;
v_17195:
    v_17569 = cons(v_17569, v_17570);
    env = stack[-9];
    fn = elt(env, 65); // md60
    v_17571 = (*qfn1(fn))(fn, v_17569);
    env = stack[-9];
    goto v_17184;
v_17185:
    v_17569 = stack[-5];
    v_17569 = qcar(v_17569);
    v_17569 = qcdr(v_17569);
    v_17570 = qcar(v_17569);
    goto v_17186;
v_17187:
    v_17569 = stack[-5];
    v_17569 = qcar(v_17569);
    v_17569 = qcdr(v_17569);
    v_17569 = qcdr(v_17569);
    v_17569 = qcar(v_17569);
    goto v_17188;
v_17189:
    goto v_17183;
v_17184:
    goto v_17185;
v_17186:
    goto v_17187;
v_17188:
    v_17570 = list2star(v_17571, v_17570, v_17569);
    env = stack[-9];
    goto v_17175;
v_17176:
    v_17569 = stack[-4];
    goto v_17177;
v_17178:
    goto v_17172;
v_17173:
    goto v_17174;
v_17175:
    goto v_17176;
v_17177:
    v_17569 = acons(stack[-1], v_17570, v_17569);
    env = stack[-9];
    stack[-4] = v_17569;
    goto v_17160;
v_17162:
v_17160:
    v_17569 = stack[-5];
    v_17569 = qcdr(v_17569);
    stack[-5] = v_17569;
    goto v_17142;
v_17141:
    v_17569 = stack[-4];
    stack[-5] = v_17569;
    v_17569 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_17569;
v_17218:
    goto v_17230;
v_17226:
    v_17570 = (LispObject)5584+TAG_FIXNUM; // 349
    goto v_17227;
v_17228:
    v_17569 = stack[-1];
    goto v_17229;
v_17230:
    goto v_17226;
v_17227:
    goto v_17228;
v_17229:
    v_17569 = difference2(v_17570, v_17569);
    env = stack[-9];
    v_17569 = Lminusp(nil, v_17569);
    env = stack[-9];
    if (v_17569 == nil) goto v_17223;
    goto v_17217;
v_17223:
    v_17569 = stack[-4];
    if (v_17569 == nil) goto v_17237;
    v_17569 = stack[-4];
    v_17569 = qcdr(v_17569);
    stack[-4] = v_17569;
    goto v_17235;
v_17237:
v_17235:
    v_17569 = stack[-1];
    v_17569 = add1(v_17569);
    env = stack[-9];
    stack[-1] = v_17569;
    goto v_17218;
v_17217:
    v_17569 = stack[-4];
    if (v_17569 == nil) goto v_17246;
    goto v_17253;
v_17249:
    v_17570 = stack[-4];
    goto v_17250;
v_17251:
    v_17569 = nil;
    goto v_17252;
v_17253:
    goto v_17249;
v_17250:
    goto v_17251;
v_17252:
    v_17569 = Lrplacd(nil, v_17570, v_17569);
    env = stack[-9];
    goto v_17244;
v_17246:
v_17244:
    goto v_17261;
v_17257:
    v_17570 = elt(env, 30); // "profile.dat"
    goto v_17258;
v_17259:
    v_17569 = elt(env, 27); // append
    goto v_17260;
v_17261:
    goto v_17257;
v_17258:
    goto v_17259;
v_17260:
    fn = elt(env, 62); // open
    v_17569 = (*qfn2(fn))(fn, v_17570, v_17569);
    env = stack[-9];
    stack[-4] = v_17569;
    v_17569 = stack[-4];
    v_17569 = Lwrs(nil, v_17569);
    env = stack[-9];
    stack[-4] = v_17569;
    v_17569 = (LispObject)1280+TAG_FIXNUM; // 80
    v_17569 = Llinelength(nil, v_17569);
    env = stack[-9];
    v_17569 = stack[0];
    if (!consp(v_17569)) goto v_17270;
    else goto v_17271;
v_17270:
    v_17569 = elt(env, 31); // "% +++++ Error: Resource limit exceeded"
    v_17569 = Lprintc(nil, v_17569);
    env = stack[-9];
    goto v_17269;
v_17271:
v_17269:
    v_17569 = elt(env, 32); // "% @@@@@ Resources used: "
    v_17569 = Lprinc(nil, v_17569);
    env = stack[-9];
    v_17569 = qvalue(elt(env, 33)); // !*resources!*
    v_17569 = Lprint(nil, v_17569);
    env = stack[-9];
    v_17569 = elt(env, 34); // "("
    v_17569 = Lprinc(nil, v_17569);
    env = stack[-9];
    v_17569 = stack[-7];
    v_17569 = qcar(v_17569);
    v_17569 = Lprin(nil, v_17569);
    env = stack[-9];
    v_17569 = Lterpri(nil, 0);
    env = stack[-9];
    v_17569 = stack[-5];
    stack[-1] = v_17569;
v_17288:
    v_17569 = stack[-1];
    if (v_17569 == nil) goto v_17292;
    else goto v_17293;
v_17292:
    goto v_17287;
v_17293:
    v_17569 = stack[-1];
    v_17569 = qcar(v_17569);
    stack[0] = v_17569;
    v_17569 = elt(env, 35); // "  ("
    v_17569 = Lprinc(nil, v_17569);
    env = stack[-9];
    v_17569 = stack[0];
    v_17569 = qcar(v_17569);
    v_17569 = Lprin(nil, v_17569);
    env = stack[-9];
    v_17569 = elt(env, 36); // " "
    v_17569 = Lprinc(nil, v_17569);
    env = stack[-9];
    goto v_17315;
v_17311:
    v_17570 = Lposn(nil, 0);
    env = stack[-9];
    goto v_17312;
v_17313:
    v_17569 = (LispObject)480+TAG_FIXNUM; // 30
    goto v_17314;
v_17315:
    goto v_17311;
v_17312:
    goto v_17313;
v_17314:
    v_17569 = (LispObject)greaterp2(v_17570, v_17569);
    v_17569 = v_17569 ? lisp_true : nil;
    env = stack[-9];
    if (v_17569 == nil) goto v_17309;
    v_17569 = Lterpri(nil, 0);
    env = stack[-9];
    v_17569 = (LispObject)480+TAG_FIXNUM; // 30
    v_17569 = Lttab(nil, v_17569);
    env = stack[-9];
    goto v_17307;
v_17309:
v_17307:
    v_17569 = stack[0];
    v_17569 = qcdr(v_17569);
    v_17569 = qcar(v_17569);
    v_17569 = Lprin(nil, v_17569);
    env = stack[-9];
    v_17569 = elt(env, 36); // " "
    v_17569 = Lprinc(nil, v_17569);
    env = stack[-9];
    v_17569 = stack[0];
    v_17569 = qcdr(v_17569);
    v_17569 = qcdr(v_17569);
    v_17569 = qcar(v_17569);
    v_17569 = Lprin(nil, v_17569);
    env = stack[-9];
    v_17569 = elt(env, 36); // " "
    v_17569 = Lprinc(nil, v_17569);
    env = stack[-9];
    v_17569 = stack[0];
    v_17569 = qcdr(v_17569);
    v_17569 = qcdr(v_17569);
    v_17569 = qcdr(v_17569);
    v_17569 = Lprinc(nil, v_17569);
    env = stack[-9];
    v_17569 = elt(env, 37); // ")"
    v_17569 = Lprintc(nil, v_17569);
    env = stack[-9];
    v_17569 = stack[-1];
    v_17569 = qcdr(v_17569);
    stack[-1] = v_17569;
    goto v_17288;
v_17287:
    v_17569 = elt(env, 38); // "  )"
    v_17569 = Lprintc(nil, v_17569);
    env = stack[-9];
    v_17569 = Lterpri(nil, 0);
    env = stack[-9];
    v_17569 = stack[-4];
    v_17569 = Lwrs(nil, v_17569);
    env = stack[-9];
    v_17569 = Lclose(nil, v_17569);
    env = stack[-9];
    v_17569 = stack[-6];
    v_17569 = Llinelength(nil, v_17569);
    env = stack[-9];
    goto v_16936;
v_16938:
v_16936:
    v_17569 = stack[-7];
    v_17569 = qcdr(v_17569);
    stack[-7] = v_17569;
    v_17569 = stack[-7];
    if (v_17569 == nil) goto v_17355;
    else goto v_17356;
v_17355:
    goto v_17363;
v_17359:
    v_17570 = elt(env, 26); // "buildlogs/flaguse.log"
    goto v_17360;
v_17361:
    v_17569 = elt(env, 39); // input
    goto v_17362;
v_17363:
    goto v_17359;
v_17360:
    goto v_17361;
v_17362:
    fn = elt(env, 62); // open
    v_17569 = (*qfn2(fn))(fn, v_17570, v_17569);
    env = stack[-9];
    stack[-4] = v_17569;
    v_17569 = stack[-4];
    v_17569 = Lrds(nil, v_17569);
    env = stack[-9];
    stack[-4] = v_17569;
    v_17569 = nil;
    stack[-5] = v_17569;
v_17371:
    goto v_17380;
v_17376:
    v_17570 = Lread(nil, 0);
    env = stack[-9];
    v_17571 = v_17570;
    goto v_17377;
v_17378:
    v_17569 = qvalue(elt(env, 40)); // !$eof!$
    goto v_17379;
v_17380:
    goto v_17376;
v_17377:
    goto v_17378;
v_17379:
    if (equal(v_17570, v_17569)) goto v_17374;
    else goto v_17375;
v_17374:
    goto v_17370;
v_17375:
    goto v_17389;
v_17385:
    goto v_17395;
v_17391:
    v_17570 = v_17571;
    goto v_17392;
v_17393:
    v_17569 = elt(env, 41); // orderp
    goto v_17394;
v_17395:
    goto v_17391;
v_17392:
    goto v_17393;
v_17394:
    fn = elt(env, 61); // sort
    v_17570 = (*qfn2(fn))(fn, v_17570, v_17569);
    env = stack[-9];
    goto v_17386;
v_17387:
    v_17569 = stack[-5];
    goto v_17388;
v_17389:
    goto v_17385;
v_17386:
    goto v_17387;
v_17388:
    v_17569 = cons(v_17570, v_17569);
    env = stack[-9];
    stack[-5] = v_17569;
    goto v_17371;
v_17370:
    v_17569 = stack[-4];
    v_17569 = Lrds(nil, v_17569);
    env = stack[-9];
    v_17569 = Lclose(nil, v_17569);
    env = stack[-9];
    v_17569 = elt(env, 42); // ((symbol!-make!-fastget (quote lose) 1) (symbol!-make!-fastget (quote noncom) 0))
    stack[0] = v_17569;
    goto v_17408;
v_17404:
    v_17570 = elt(env, 43); // (lose noncom)
    goto v_17405;
v_17406:
    v_17569 = elt(env, 44); // processed
    goto v_17407;
v_17408:
    goto v_17404;
v_17405:
    goto v_17406;
v_17407:
    v_17569 = Lflag(nil, v_17570, v_17569);
    env = stack[-9];
    v_17569 = (LispObject)32+TAG_FIXNUM; // 2
    stack[-6] = v_17569;
v_17414:
    v_17569 = stack[-5];
    if (v_17569 == nil) goto v_17417;
    else goto v_17418;
v_17417:
    goto v_17413;
v_17418:
    v_17569 = nil;
    stack[-4] = v_17569;
    v_17569 = stack[-5];
    stack[-5] = v_17569;
v_17425:
    v_17569 = stack[-5];
    if (v_17569 == nil) goto v_17429;
    else goto v_17430;
v_17429:
    goto v_17424;
v_17430:
    v_17569 = stack[-5];
    v_17569 = qcar(v_17569);
    stack[-3] = v_17569;
    v_17569 = stack[-3];
    if (v_17569 == nil) goto v_17439;
    goto v_17452;
v_17448:
    v_17569 = stack[-3];
    v_17569 = qcar(v_17569);
    v_17569 = qcdr(v_17569);
    v_17570 = qcar(v_17569);
    goto v_17449;
v_17450:
    v_17569 = elt(env, 44); // processed
    goto v_17451;
v_17452:
    goto v_17448;
v_17449:
    goto v_17450;
v_17451:
    v_17569 = Lflagp(nil, v_17570, v_17569);
    env = stack[-9];
    if (v_17569 == nil) goto v_17445;
    else goto v_17446;
v_17445:
    goto v_17463;
v_17459:
    v_17570 = stack[-6];
    goto v_17460;
v_17461:
    v_17569 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_17462;
v_17463:
    goto v_17459;
v_17460:
    goto v_17461;
v_17462:
    v_17569 = (LispObject)lessp2(v_17570, v_17569);
    v_17569 = v_17569 ? lisp_true : nil;
    env = stack[-9];
    goto v_17444;
v_17446:
    v_17569 = nil;
    goto v_17444;
    v_17569 = nil;
v_17444:
    if (v_17569 == nil) goto v_17439;
    goto v_17474;
v_17470:
    goto v_17482;
v_17476:
    stack[-1] = elt(env, 45); // symbol!-make!-fastget
    goto v_17477;
v_17478:
    v_17569 = stack[-3];
    v_17569 = qcar(v_17569);
    v_17569 = qcdr(v_17569);
    v_17569 = qcar(v_17569);
    v_17570 = Lmkquote(nil, v_17569);
    env = stack[-9];
    goto v_17479;
v_17480:
    v_17569 = stack[-6];
    goto v_17481;
v_17482:
    goto v_17476;
v_17477:
    goto v_17478;
v_17479:
    goto v_17480;
v_17481:
    v_17570 = list3(stack[-1], v_17570, v_17569);
    env = stack[-9];
    goto v_17471;
v_17472:
    v_17569 = stack[0];
    goto v_17473;
v_17474:
    goto v_17470;
v_17471:
    goto v_17472;
v_17473:
    v_17569 = cons(v_17570, v_17569);
    env = stack[-9];
    stack[0] = v_17569;
    goto v_17496;
v_17492:
    v_17569 = stack[-3];
    v_17569 = qcar(v_17569);
    v_17569 = qcdr(v_17569);
    v_17569 = qcar(v_17569);
    v_17570 = ncons(v_17569);
    env = stack[-9];
    goto v_17493;
v_17494:
    v_17569 = elt(env, 44); // processed
    goto v_17495;
v_17496:
    goto v_17492;
v_17493:
    goto v_17494;
v_17495:
    v_17569 = Lflag(nil, v_17570, v_17569);
    env = stack[-9];
    v_17569 = stack[-6];
    v_17569 = add1(v_17569);
    env = stack[-9];
    stack[-6] = v_17569;
    goto v_17437;
v_17439:
v_17437:
    v_17569 = stack[-3];
    v_17569 = qcdr(v_17569);
    if (v_17569 == nil) goto v_17508;
    goto v_17516;
v_17512:
    v_17569 = stack[-3];
    v_17570 = qcdr(v_17569);
    goto v_17513;
v_17514:
    v_17569 = stack[-4];
    goto v_17515;
v_17516:
    goto v_17512;
v_17513:
    goto v_17514;
v_17515:
    v_17569 = cons(v_17570, v_17569);
    env = stack[-9];
    stack[-4] = v_17569;
    goto v_17506;
v_17508:
v_17506:
    v_17569 = stack[-5];
    v_17569 = qcdr(v_17569);
    stack[-5] = v_17569;
    goto v_17425;
v_17424:
    v_17569 = stack[-4];
    v_17569 = Lreverse(nil, v_17569);
    env = stack[-9];
    stack[-5] = v_17569;
    goto v_17414;
v_17413:
    goto v_17529;
v_17525:
    v_17570 = elt(env, 46); // "buildlogs/fastgets.lsp"
    goto v_17526;
v_17527:
    v_17569 = elt(env, 47); // output
    goto v_17528;
v_17529:
    goto v_17525;
v_17526:
    goto v_17527;
v_17528:
    fn = elt(env, 62); // open
    v_17569 = (*qfn2(fn))(fn, v_17570, v_17569);
    env = stack[-9];
    stack[-5] = v_17569;
    v_17569 = stack[-5];
    v_17569 = Lwrs(nil, v_17569);
    env = stack[-9];
    stack[-5] = v_17569;
    v_17569 = elt(env, 48); // "% fastgets.lsp generated by profiling"
    v_17569 = Lprintc(nil, v_17569);
    env = stack[-9];
    v_17569 = Lterpri(nil, 0);
    env = stack[-9];
    goto v_17543;
v_17539:
    stack[-1] = elt(env, 49); // progn
    goto v_17540;
v_17541:
    v_17569 = stack[0];
    v_17569 = Lreverse(nil, v_17569);
    env = stack[-9];
    goto v_17542;
v_17543:
    goto v_17539;
v_17540:
    goto v_17541;
v_17542:
    v_17569 = cons(stack[-1], v_17569);
    env = stack[-9];
    fn = elt(env, 66); // prettyprint
    v_17569 = (*qfn1(fn))(fn, v_17569);
    env = stack[-9];
    v_17569 = Lterpri(nil, 0);
    env = stack[-9];
    v_17569 = elt(env, 50); // "% end of fastgets.lsp"
    v_17569 = Lprintc(nil, v_17569);
    env = stack[-9];
    v_17569 = stack[-5];
    v_17569 = Lwrs(nil, v_17569);
    env = stack[-9];
    v_17569 = Lclose(nil, v_17569);
    env = stack[-9];
    v_17569 = elt(env, 51); // "Profiling complete"
    v_17569 = Lprintc(nil, v_17569);
    env = stack[-9];
    v_17569 = elt(env, 51); // "Profiling complete"
    fn = elt(env, 57); // window!-heading
    v_17569 = (*qfn1(fn))(fn, v_17569);
    env = stack[-9];
    v_17569 = lisp_true;
    fn = elt(env, 67); // restart!-csl
    v_17569 = (*qfn1(fn))(fn, v_17569);
    goto v_17354;
v_17356:
    goto v_17566;
v_17562:
    v_17570 = elt(env, 52); // (remake profile_a_package)
    goto v_17563;
v_17564:
    v_17569 = stack[-7];
    goto v_17565;
v_17566:
    goto v_17562;
v_17563:
    goto v_17564;
v_17565:
    fn = elt(env, 67); // restart!-csl
    v_17569 = (*qfn2(fn))(fn, v_17570, v_17569);
    goto v_17354;
v_17354:
    v_17569 = nil;
    ;}  // end of a binding scope
    return onevalue(v_17569);
}



// Code for ofsf_siatsubf

static LispObject CC_ofsf_siatsubf(LispObject env,
                         LispObject v_16829, LispObject v_16830)
{
    env = qenv(env);
    LispObject v_16948, v_16949, v_16950;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_16830,v_16829);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_16829,v_16830);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_16830;
    stack[-1] = v_16829;
// end of prologue
    v_16948 = stack[-1];
    if (!consp(v_16948)) goto v_16843;
    else goto v_16844;
v_16843:
    v_16948 = lisp_true;
    goto v_16842;
v_16844:
    v_16948 = stack[-1];
    v_16948 = qcar(v_16948);
    v_16948 = (consp(v_16948) ? nil : lisp_true);
    goto v_16842;
    v_16948 = nil;
v_16842:
    if (v_16948 == nil) goto v_16840;
    goto v_16857;
v_16853:
    v_16949 = stack[-1];
    goto v_16854;
v_16855:
    v_16948 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16856;
v_16857:
    goto v_16853;
v_16854:
    goto v_16855;
v_16856:
    return cons(v_16949, v_16948);
v_16840:
    goto v_16865;
v_16861:
    v_16948 = stack[-1];
    v_16949 = qcdr(v_16948);
    goto v_16862;
v_16863:
    v_16948 = stack[0];
    goto v_16864;
v_16865:
    goto v_16861;
v_16862:
    goto v_16863;
v_16864:
    v_16948 = CC_ofsf_siatsubf(elt(env, 0), v_16949, v_16948);
    env = stack[-3];
    stack[-2] = v_16948;
    goto v_16874;
v_16870:
    v_16948 = stack[-1];
    v_16948 = qcar(v_16948);
    v_16949 = qcdr(v_16948);
    goto v_16871;
v_16872:
    v_16948 = stack[0];
    goto v_16873;
v_16874:
    goto v_16870;
v_16871:
    goto v_16872;
v_16873:
    v_16948 = CC_ofsf_siatsubf(elt(env, 0), v_16949, v_16948);
    env = stack[-3];
    v_16949 = v_16948;
    goto v_16887;
v_16883:
    v_16948 = stack[-1];
    v_16948 = qcar(v_16948);
    v_16948 = qcar(v_16948);
    v_16950 = qcar(v_16948);
    goto v_16884;
v_16885:
    v_16948 = stack[0];
    goto v_16886;
v_16887:
    goto v_16883;
v_16884:
    goto v_16885;
v_16886:
    v_16948 = Latsoc(nil, v_16950, v_16948);
    v_16950 = v_16948;
    if (v_16948 == nil) goto v_16882;
    goto v_16899;
v_16895:
    goto v_16905;
v_16901:
    stack[0] = v_16949;
    goto v_16902;
v_16903:
    goto v_16912;
v_16908:
    v_16948 = v_16950;
    v_16949 = qcdr(v_16948);
    goto v_16909;
v_16910:
    v_16948 = stack[-1];
    v_16948 = qcar(v_16948);
    v_16948 = qcar(v_16948);
    v_16948 = qcdr(v_16948);
    goto v_16911;
v_16912:
    goto v_16908;
v_16909:
    goto v_16910;
v_16911:
    fn = elt(env, 1); // exptsq
    v_16948 = (*qfn2(fn))(fn, v_16949, v_16948);
    env = stack[-3];
    goto v_16904;
v_16905:
    goto v_16901;
v_16902:
    goto v_16903;
v_16904:
    fn = elt(env, 2); // multsq
    v_16949 = (*qfn2(fn))(fn, stack[0], v_16948);
    env = stack[-3];
    goto v_16896;
v_16897:
    v_16948 = stack[-2];
    goto v_16898;
v_16899:
    goto v_16895;
v_16896:
    goto v_16897;
v_16898:
    {
        fn = elt(env, 3); // addsq
        return (*qfn2(fn))(fn, v_16949, v_16948);
    }
v_16882:
    goto v_16925;
v_16921:
    goto v_16931;
v_16927:
    stack[0] = v_16949;
    goto v_16928;
v_16929:
    goto v_16938;
v_16934:
    v_16948 = stack[-1];
    v_16948 = qcar(v_16948);
    v_16948 = qcar(v_16948);
    v_16949 = qcar(v_16948);
    goto v_16935;
v_16936:
    v_16948 = stack[-1];
    v_16948 = qcar(v_16948);
    v_16948 = qcar(v_16948);
    v_16948 = qcdr(v_16948);
    goto v_16937;
v_16938:
    goto v_16934;
v_16935:
    goto v_16936;
v_16937:
    fn = elt(env, 4); // ofsf_pow2q
    v_16948 = (*qfn2(fn))(fn, v_16949, v_16948);
    env = stack[-3];
    goto v_16930;
v_16931:
    goto v_16927;
v_16928:
    goto v_16929;
v_16930:
    fn = elt(env, 2); // multsq
    v_16949 = (*qfn2(fn))(fn, stack[0], v_16948);
    env = stack[-3];
    goto v_16922;
v_16923:
    v_16948 = stack[-2];
    goto v_16924;
v_16925:
    goto v_16921;
v_16922:
    goto v_16923;
v_16924:
    {
        fn = elt(env, 3); // addsq
        return (*qfn2(fn))(fn, v_16949, v_16948);
    }
    return onevalue(v_16948);
}



// Code for monomgetfirstmultivar

static LispObject CC_monomgetfirstmultivar(LispObject env,
                         LispObject v_16829)
{
    env = qenv(env);
    LispObject v_16858, v_16859, v_16860;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16859 = v_16829;
// end of prologue
    goto v_16841;
v_16837:
    v_16860 = v_16859;
    goto v_16838;
v_16839:
    v_16858 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16840;
v_16841:
    goto v_16837;
v_16838:
    goto v_16839;
v_16840:
    v_16858 = *(LispObject *)((char *)v_16860 + (CELL-TAG_VECTOR) + (((intptr_t)v_16858-TAG_FIXNUM)/(16/CELL)));
    v_16858 = qcar(v_16858);
    if (v_16858 == nil) goto v_16836;
    goto v_16850;
v_16846:
    goto v_16847;
v_16848:
    v_16858 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16849;
v_16850:
    goto v_16846;
v_16847:
    goto v_16848;
v_16849:
    v_16858 = *(LispObject *)((char *)v_16859 + (CELL-TAG_VECTOR) + (((intptr_t)v_16858-TAG_FIXNUM)/(16/CELL)));
    v_16858 = qcar(v_16858);
    goto v_16834;
v_16836:
    v_16858 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16834;
    v_16858 = nil;
v_16834:
    return onevalue(v_16858);
}



setup_type const u31_setup[] =
{
    {"cl_susiupdknowl2",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_susiupdknowl2},
    {"semanticml",              CC_semanticml,  TOO_MANY_1,    WRONG_NO_1},
    {"derad",                   TOO_FEW_2,      CC_derad,      WRONG_NO_2},
    {"evalvars",                CC_evalvars,    TOO_MANY_1,    WRONG_NO_1},
    {"vdp2a",                   CC_vdp2a,       TOO_MANY_1,    WRONG_NO_1},
    {"gfplusn",                 TOO_FEW_2,      CC_gfplusn,    WRONG_NO_2},
    {"clogsq*",                 CC_clogsqH,     TOO_MANY_1,    WRONG_NO_1},
    {"assert_stat-parse",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_assert_statKparse},
    {"mv-pow->",                TOO_FEW_2,      CC_mvKpowKS,   WRONG_NO_2},
    {"symbol",                  CC_symbol,      TOO_MANY_1,    WRONG_NO_1},
    {"red=hide",                CC_redMhide,    TOO_MANY_1,    WRONG_NO_1},
    {"general-ordered-gcd-mod-p",TOO_FEW_2,     CC_generalKorderedKgcdKmodKp,WRONG_NO_2},
    {"not_included",            TOO_FEW_2,      CC_not_included,WRONG_NO_2},
    {"lex_basic_token",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex_basic_token},
    {"formbool",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formbool},
    {"even_action_sf",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_even_action_sf},
    {"matrix_rows",             CC_matrix_rows, TOO_MANY_1,    WRONG_NO_1},
    {"sc_getrow",               TOO_FEW_2,      CC_sc_getrow,  WRONG_NO_2},
    {"gparg1p",                 CC_gparg1p,     TOO_MANY_1,    WRONG_NO_1},
    {"indordn",                 CC_indordn,     TOO_MANY_1,    WRONG_NO_1},
    {"one-entryp",              TOO_FEW_2,      CC_oneKentryp, WRONG_NO_2},
    {"modp",                    TOO_FEW_2,      CC_modp,       WRONG_NO_2},
    {"horner-rule-for-one-var", WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_hornerKruleKforKoneKvar},
    {"lalr_process_reductions", WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lalr_process_reductions},
    {"profile_a_package",       CC_profile_a_package,TOO_MANY_1,WRONG_NO_1},
    {"ofsf_siatsubf",           TOO_FEW_2,      CC_ofsf_siatsubf,WRONG_NO_2},
    {"monomgetfirstmultivar",   CC_monomgetfirstmultivar,TOO_MANY_1,WRONG_NO_1},
    {NULL, (one_args *)"u31", (two_args *)"174514 3604770 4493392", 0}
};

// end of generated code
