
// $destdir/u25.c        Machine generated C code

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



// Code for polynomlistreduce

static LispObject CC_polynomlistreduce(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13941, v_13942, v_13943;
    LispObject fn;
    LispObject v_13827, v_13826, v_13825;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "polynomlistreduce");
    va_start(aa, nargs);
    v_13825 = va_arg(aa, LispObject);
    v_13826 = va_arg(aa, LispObject);
    v_13827 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13827,v_13826,v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13825,v_13826,v_13827);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_13827;
    stack[-2] = v_13826;
    stack[-3] = v_13825;
// end of prologue
    v_13941 = nil;
    v_13941 = ncons(v_13941);
    env = stack[-5];
    stack[-4] = v_13941;
    v_13941 = stack[-2];
    v_13941 = qcar(v_13941);
    if (v_13941 == nil) goto v_13838;
    else goto v_13839;
v_13838:
    v_13941 = stack[-4];
    goto v_13832;
v_13839:
v_13846:
    v_13941 = stack[-2];
    v_13941 = qcar(v_13941);
    if (v_13941 == nil) goto v_13849;
    else goto v_13850;
v_13849:
    goto v_13845;
v_13850:
    goto v_13861;
v_13855:
    v_13943 = stack[-3];
    goto v_13856;
v_13857:
    v_13942 = stack[-2];
    goto v_13858;
v_13859:
    v_13941 = stack[-1];
    goto v_13860;
v_13861:
    goto v_13855;
v_13856:
    goto v_13857;
v_13858:
    goto v_13859;
v_13860:
    fn = elt(env, 2); // polynomlistfinddivisor
    v_13941 = (*qfnn(fn))(fn, 3, v_13943, v_13942, v_13941);
    env = stack[-5];
v_13867:
    v_13942 = v_13941;
    if (v_13942 == nil) goto v_13870;
    else goto v_13871;
v_13870:
    goto v_13866;
v_13871:
    goto v_13879;
v_13875:
    v_13942 = stack[-2];
    goto v_13876;
v_13877:
    goto v_13878;
v_13879:
    goto v_13875;
v_13876:
    goto v_13877;
v_13878:
    fn = elt(env, 3); // polynomreduceby
    v_13941 = (*qfn2(fn))(fn, v_13942, v_13941);
    env = stack[-5];
    goto v_13889;
v_13883:
    v_13943 = stack[-3];
    goto v_13884;
v_13885:
    v_13942 = stack[-2];
    goto v_13886;
v_13887:
    v_13941 = stack[-1];
    goto v_13888;
v_13889:
    goto v_13883;
v_13884:
    goto v_13885;
v_13886:
    goto v_13887;
v_13888:
    fn = elt(env, 2); // polynomlistfinddivisor
    v_13941 = (*qfnn(fn))(fn, 3, v_13943, v_13942, v_13941);
    env = stack[-5];
    goto v_13867;
v_13866:
    v_13941 = stack[-2];
    v_13941 = qcar(v_13941);
    if (v_13941 == nil) goto v_13897;
    goto v_13905;
v_13901:
    stack[0] = stack[-4];
    goto v_13902;
v_13903:
    goto v_13914;
v_13908:
    v_13941 = stack[-2];
    v_13943 = qcar(v_13941);
    goto v_13909;
v_13910:
    v_13942 = nil;
    goto v_13911;
v_13912:
    v_13941 = nil;
    goto v_13913;
v_13914:
    goto v_13908;
v_13909:
    goto v_13910;
v_13911:
    goto v_13912;
v_13913:
    v_13941 = list2star(v_13943, v_13942, v_13941);
    env = stack[-5];
    goto v_13904;
v_13905:
    goto v_13901;
v_13902:
    goto v_13903;
v_13904:
    fn = elt(env, 4); // polynomadd
    v_13941 = (*qfn2(fn))(fn, stack[0], v_13941);
    env = stack[-5];
    goto v_13924;
v_13920:
    goto v_13930;
v_13926:
    v_13942 = stack[-2];
    goto v_13927;
v_13928:
    v_13941 = stack[-2];
    v_13941 = qcdr(v_13941);
    v_13941 = qcar(v_13941);
    goto v_13929;
v_13930:
    goto v_13926;
v_13927:
    goto v_13928;
v_13929:
    v_13942 = Lrplaca(nil, v_13942, v_13941);
    env = stack[-5];
    goto v_13921;
v_13922:
    v_13941 = stack[-2];
    v_13941 = qcdr(v_13941);
    v_13941 = qcdr(v_13941);
    goto v_13923;
v_13924:
    goto v_13920;
v_13921:
    goto v_13922;
v_13923:
    v_13941 = Lrplacd(nil, v_13942, v_13941);
    env = stack[-5];
    goto v_13895;
v_13897:
v_13895:
    goto v_13846;
v_13845:
    v_13941 = stack[-4];
v_13832:
    return onevalue(v_13941);
}



// Code for rl_eqnrhskernels

static LispObject CC_rl_eqnrhskernels(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13836;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_13836 = v_13825;
// end of prologue
    goto v_13832;
v_13828:
    stack[0] = qvalue(elt(env, 1)); // rl_eqnrhskernels!*
    goto v_13829;
v_13830:
    v_13836 = ncons(v_13836);
    env = stack[-1];
    goto v_13831;
v_13832:
    goto v_13828;
v_13829:
    goto v_13830;
v_13831:
    {
        LispObject v_13838 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_13838, v_13836);
    }
}



// Code for pasf_vf

static LispObject CC_pasf_vf(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13949, v_13950, v_13951;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_13950 = v_13825;
// end of prologue
    goto v_13846;
v_13842:
    v_13951 = v_13950;
    goto v_13843;
v_13844:
    v_13949 = elt(env, 1); // true
    goto v_13845;
v_13846:
    goto v_13842;
v_13843:
    goto v_13844;
v_13845:
    if (v_13951 == v_13949) goto v_13840;
    else goto v_13841;
v_13840:
    v_13949 = lisp_true;
    goto v_13839;
v_13841:
    goto v_13856;
v_13852:
    v_13951 = v_13950;
    goto v_13853;
v_13854:
    v_13949 = elt(env, 2); // false
    goto v_13855;
v_13856:
    goto v_13852;
v_13853:
    goto v_13854;
v_13855:
    v_13949 = (v_13951 == v_13949 ? lisp_true : nil);
    goto v_13839;
    v_13949 = nil;
v_13839:
    if (v_13949 == nil) goto v_13836;
    else goto v_13837;
v_13836:
    v_13949 = v_13950;
    v_13949 = qcdr(v_13949);
    v_13949 = qcar(v_13949);
    if (!consp(v_13949)) goto v_13862;
    else goto v_13863;
v_13862:
    v_13949 = lisp_true;
    goto v_13861;
v_13863:
    v_13949 = v_13950;
    v_13949 = qcdr(v_13949);
    v_13949 = qcar(v_13949);
    v_13949 = qcar(v_13949);
    v_13949 = (consp(v_13949) ? nil : lisp_true);
    goto v_13861;
    v_13949 = nil;
v_13861:
    goto v_13835;
v_13837:
    v_13949 = nil;
    goto v_13835;
    v_13949 = nil;
v_13835:
    if (v_13949 == nil) goto v_13833;
    v_13949 = v_13950;
    v_13949 = Lconsp(nil, v_13949);
    env = stack[0];
    if (v_13949 == nil) goto v_13881;
    v_13949 = v_13950;
    v_13949 = qcar(v_13949);
    v_13949 = Lconsp(nil, v_13949);
    env = stack[0];
    if (v_13949 == nil) goto v_13881;
    goto v_13896;
v_13892:
    v_13949 = v_13950;
    v_13949 = qcar(v_13949);
    v_13951 = qcar(v_13949);
    goto v_13893;
v_13894:
    v_13949 = elt(env, 3); // (cong ncong)
    goto v_13895;
v_13896:
    goto v_13892;
v_13893:
    goto v_13894;
v_13895:
    v_13949 = Lmemq(nil, v_13951, v_13949);
    if (v_13949 == nil) goto v_13881;
    v_13949 = v_13950;
    v_13949 = qcar(v_13949);
    v_13949 = qcdr(v_13949);
    if (!consp(v_13949)) goto v_13905;
    else goto v_13906;
v_13905:
    v_13949 = lisp_true;
    goto v_13904;
v_13906:
    v_13949 = v_13950;
    v_13949 = qcar(v_13949);
    v_13949 = qcdr(v_13949);
    v_13949 = qcar(v_13949);
    v_13949 = (consp(v_13949) ? nil : lisp_true);
    goto v_13904;
    v_13949 = nil;
v_13904:
    if (v_13949 == nil) goto v_13902;
    else goto v_13881;
v_13902:
    v_13949 = v_13950;
    v_13949 = qcdr(v_13949);
    v_13949 = qcar(v_13949);
    if (v_13949 == nil) goto v_13920;
    else goto v_13921;
v_13920:
    v_13949 = elt(env, 2); // false
    goto v_13828;
v_13921:
    v_13949 = v_13950;
    goto v_13828;
    goto v_13879;
v_13881:
v_13879:
    goto v_13938;
v_13934:
    v_13949 = v_13950;
    v_13949 = qcar(v_13949);
    goto v_13935;
v_13936:
    v_13950 = qcdr(v_13950);
    v_13950 = qcar(v_13950);
    goto v_13937;
v_13938:
    goto v_13934;
v_13935:
    goto v_13936;
v_13937:
    fn = elt(env, 4); // pasf_evalatp
    v_13949 = (*qfn2(fn))(fn, v_13949, v_13950);
    env = stack[0];
    if (v_13949 == nil) goto v_13932;
    v_13949 = elt(env, 1); // true
    goto v_13930;
v_13932:
    v_13949 = elt(env, 2); // false
    goto v_13930;
    v_13949 = nil;
v_13930:
    goto v_13828;
v_13833:
    v_13949 = v_13950;
v_13828:
    return onevalue(v_13949);
}



// Code for vdp_getprop

static LispObject CC_vdp_getprop(LispObject env,
                         LispObject v_13825, LispObject v_13826)
{
    env = qenv(env);
    LispObject v_13848, v_13849;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13826,v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13825,v_13826);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_13848 = v_13826;
    v_13849 = v_13825;
// end of prologue
    goto v_13832;
v_13828:
    stack[0] = v_13848;
    goto v_13829;
v_13830:
    v_13848 = v_13849;
    fn = elt(env, 1); // vdp_plist
    v_13848 = (*qfn1(fn))(fn, v_13848);
    goto v_13831;
v_13832:
    goto v_13828;
v_13829:
    goto v_13830;
v_13831:
    v_13848 = Latsoc(nil, stack[0], v_13848);
    v_13849 = v_13848;
    v_13848 = v_13849;
    if (v_13848 == nil) goto v_13841;
    v_13848 = v_13849;
    v_13848 = qcdr(v_13848);
    goto v_13839;
v_13841:
    v_13848 = nil;
    goto v_13839;
    v_13848 = nil;
v_13839:
    return onevalue(v_13848);
}



// Code for unaryrd

static LispObject CC_unaryrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13834;
    LispObject fn;
    argcheck(nargs, 0, "unaryrd");
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
    v_13834 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_13834;
    fn = elt(env, 3); // lex
    v_13834 = (*qfnn(fn))(fn, 0);
    v_13834 = stack[0];
    return ncons(v_13834);
    return onevalue(v_13834);
}



// Code for rationalizesq

static LispObject CC_rationalizesq(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13940, v_13941;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_13825;
// end of prologue
// Binding !*structure
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = nil; // !*structure
// Binding !*sub2
// FLUIDBIND: reloadenv=5 litvec-offset=2 saveloc=2
{   bind_fluid_stack bind_fluid_var(-5, 2, -2);
    qvalue(elt(env, 2)) = nil; // !*sub2
    goto v_13843;
v_13839:
    v_13941 = qvalue(elt(env, 4)); // dmode!*
    goto v_13840;
v_13841:
    v_13940 = elt(env, 5); // rationalizefn
    goto v_13842;
v_13843:
    goto v_13839;
v_13840:
    goto v_13841;
v_13842:
    v_13940 = get(v_13941, v_13940);
    env = stack[-5];
    stack[0] = v_13940;
    if (v_13940 == nil) goto v_13837;
    goto v_13851;
v_13847:
    v_13941 = stack[0];
    goto v_13848;
v_13849:
    v_13940 = stack[-3];
    goto v_13850;
v_13851:
    goto v_13847;
v_13848:
    goto v_13849;
v_13850:
    v_13940 = Lapply1(nil, v_13941, v_13940);
    env = stack[-5];
    stack[-3] = v_13940;
    goto v_13835;
v_13837:
v_13835:
    goto v_13859;
v_13855:
    v_13941 = elt(env, 6); // (i 2 (nil . t) -1 nil)
    goto v_13856;
v_13857:
    v_13940 = qvalue(elt(env, 7)); // powlis!*
    goto v_13858;
v_13859:
    goto v_13855;
v_13856:
    goto v_13857;
v_13858:
    v_13940 = cons(v_13941, v_13940);
    env = stack[-5];
    qvalue(elt(env, 7)) = v_13940; // powlis!*
    v_13940 = stack[-3];
    fn = elt(env, 10); // subs2q
    v_13940 = (*qfn1(fn))(fn, v_13940);
    env = stack[-5];
    stack[-1] = v_13940;
    v_13940 = qvalue(elt(env, 7)); // powlis!*
    v_13940 = qcdr(v_13940);
    qvalue(elt(env, 7)) = v_13940; // powlis!*
    v_13940 = stack[-1];
    v_13940 = qcdr(v_13940);
    if (!consp(v_13940)) goto v_13872;
    else goto v_13873;
v_13872:
    v_13940 = lisp_true;
    goto v_13871;
v_13873:
    v_13940 = stack[-1];
    v_13940 = qcdr(v_13940);
    v_13940 = qcar(v_13940);
    v_13940 = (consp(v_13940) ? nil : lisp_true);
    goto v_13871;
    v_13940 = nil;
v_13871:
    if (v_13940 == nil) goto v_13869;
    v_13940 = stack[-1];
    goto v_13867;
v_13869:
    goto v_13890;
v_13886:
    v_13940 = stack[-1];
    v_13940 = qcdr(v_13940);
    fn = elt(env, 11); // rationalizef
    v_13941 = (*qfn1(fn))(fn, v_13940);
    env = stack[-5];
    stack[0] = v_13941;
    goto v_13887;
v_13888:
    v_13940 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13889;
v_13890:
    goto v_13886;
v_13887:
    goto v_13888;
v_13889:
    if (v_13941 == v_13940) goto v_13885;
    goto v_13900;
v_13896:
    goto v_13906;
v_13902:
    v_13940 = stack[-1];
    v_13941 = qcar(v_13940);
    goto v_13903;
v_13904:
    v_13940 = stack[0];
    goto v_13905;
v_13906:
    goto v_13902;
v_13903:
    goto v_13904;
v_13905:
    fn = elt(env, 12); // multf
    stack[-3] = (*qfn2(fn))(fn, v_13941, v_13940);
    env = stack[-5];
    goto v_13897;
v_13898:
    goto v_13915;
v_13911:
    v_13940 = stack[-1];
    v_13941 = qcdr(v_13940);
    goto v_13912;
v_13913:
    v_13940 = stack[0];
    goto v_13914;
v_13915:
    goto v_13911;
v_13912:
    goto v_13913;
v_13914:
    fn = elt(env, 12); // multf
    v_13940 = (*qfn2(fn))(fn, v_13941, v_13940);
    env = stack[-5];
    goto v_13899;
v_13900:
    goto v_13896;
v_13897:
    goto v_13898;
v_13899:
    v_13940 = cons(stack[-3], v_13940);
    env = stack[-5];
    stack[-1] = v_13940;
    v_13940 = qvalue(elt(env, 8)); // !*algint
    if (v_13940 == nil) goto v_13925;
    else goto v_13926;
v_13925:
    v_13940 = qvalue(elt(env, 9)); // !*rationalize
    v_13940 = (v_13940 == nil ? lisp_true : nil);
    goto v_13924;
v_13926:
    v_13940 = nil;
    goto v_13924;
    v_13940 = nil;
v_13924:
    if (v_13940 == nil) goto v_13922;
    v_13940 = stack[-1];
    fn = elt(env, 13); // gcdchk
    v_13940 = (*qfn1(fn))(fn, v_13940);
    env = stack[-5];
    stack[-1] = v_13940;
    goto v_13920;
v_13922:
v_13920:
    v_13940 = stack[-1];
    fn = elt(env, 10); // subs2q
    v_13940 = (*qfn1(fn))(fn, v_13940);
    goto v_13867;
v_13885:
    v_13940 = stack[-3];
    goto v_13867;
    v_13940 = nil;
v_13867:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_13940);
}



// Code for dipev2f

static LispObject CC_dipev2f(LispObject env,
                         LispObject v_13825, LispObject v_13826)
{
    env = qenv(env);
    LispObject v_13887, v_13888;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13826,v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13825,v_13826);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13826;
    stack[-1] = v_13825;
// end of prologue
v_13830:
    v_13887 = stack[-1];
    if (v_13887 == nil) goto v_13833;
    else goto v_13834;
v_13833:
    v_13887 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13829;
v_13834:
    goto v_13843;
v_13839:
    v_13887 = stack[-1];
    v_13888 = qcar(v_13887);
    goto v_13840;
v_13841:
    v_13887 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13842;
v_13843:
    goto v_13839;
v_13840:
    goto v_13841;
v_13842:
    if (v_13888 == v_13887) goto v_13837;
    else goto v_13838;
v_13837:
    v_13887 = stack[-1];
    v_13887 = qcdr(v_13887);
    stack[-1] = v_13887;
    v_13887 = stack[0];
    v_13887 = qcdr(v_13887);
    stack[0] = v_13887;
    goto v_13830;
v_13838:
    goto v_13858;
v_13854:
    goto v_13865;
v_13861:
    goto v_13871;
v_13867:
    v_13887 = stack[0];
    v_13888 = qcar(v_13887);
    goto v_13868;
v_13869:
    v_13887 = stack[-1];
    v_13887 = qcar(v_13887);
    goto v_13870;
v_13871:
    goto v_13867;
v_13868:
    goto v_13869;
v_13870:
    fn = elt(env, 1); // to
    v_13888 = (*qfn2(fn))(fn, v_13888, v_13887);
    env = stack[-3];
    goto v_13862;
v_13863:
    v_13887 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13864;
v_13865:
    goto v_13861;
v_13862:
    goto v_13863;
v_13864:
    v_13887 = cons(v_13888, v_13887);
    env = stack[-3];
    stack[-2] = ncons(v_13887);
    env = stack[-3];
    goto v_13855;
v_13856:
    goto v_13882;
v_13878:
    v_13887 = stack[-1];
    v_13888 = qcdr(v_13887);
    goto v_13879;
v_13880:
    v_13887 = stack[0];
    v_13887 = qcdr(v_13887);
    goto v_13881;
v_13882:
    goto v_13878;
v_13879:
    goto v_13880;
v_13881:
    v_13887 = CC_dipev2f(elt(env, 0), v_13888, v_13887);
    env = stack[-3];
    goto v_13857;
v_13858:
    goto v_13854;
v_13855:
    goto v_13856;
v_13857:
    {
        LispObject v_13892 = stack[-2];
        fn = elt(env, 2); // multf
        return (*qfn2(fn))(fn, v_13892, v_13887);
    }
    v_13887 = nil;
v_13829:
    return onevalue(v_13887);
}



// Code for cos!*

static LispObject CC_cosH(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13835, v_13836;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13835 = v_13825;
// end of prologue
    goto v_13832;
v_13828:
    v_13836 = v_13835;
    goto v_13829;
v_13830:
    v_13835 = qvalue(elt(env, 1)); // !:bprec!:
    goto v_13831;
v_13832:
    goto v_13828;
v_13829:
    goto v_13830;
v_13831:
    {
        fn = elt(env, 2); // cos!:
        return (*qfn2(fn))(fn, v_13836, v_13835);
    }
}



// Code for flatindl

static LispObject CC_flatindl(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13868, v_13869;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13825;
// end of prologue
    stack[-1] = nil;
v_13831:
    v_13868 = stack[0];
    if (v_13868 == nil) goto v_13836;
    else goto v_13837;
v_13836:
    goto v_13832;
v_13837:
    goto v_13844;
v_13840:
    v_13868 = stack[0];
    v_13869 = qcar(v_13868);
    goto v_13841;
v_13842:
    v_13868 = stack[-1];
    goto v_13843;
v_13844:
    goto v_13840;
v_13841:
    goto v_13842;
v_13843:
    v_13868 = cons(v_13869, v_13868);
    env = stack[-2];
    stack[-1] = v_13868;
    v_13868 = stack[0];
    v_13868 = qcdr(v_13868);
    stack[0] = v_13868;
    goto v_13831;
v_13832:
    v_13868 = nil;
    v_13869 = v_13868;
v_13833:
    v_13868 = stack[-1];
    if (v_13868 == nil) goto v_13853;
    else goto v_13854;
v_13853:
    v_13868 = v_13869;
    goto v_13830;
v_13854:
    goto v_13862;
v_13858:
    v_13868 = stack[-1];
    v_13868 = qcar(v_13868);
    goto v_13859;
v_13860:
    goto v_13861;
v_13862:
    goto v_13858;
v_13859:
    goto v_13860;
v_13861:
    v_13868 = Lappend(nil, v_13868, v_13869);
    env = stack[-2];
    v_13869 = v_13868;
    v_13868 = stack[-1];
    v_13868 = qcdr(v_13868);
    stack[-1] = v_13868;
    goto v_13833;
v_13830:
    return onevalue(v_13868);
}



// Code for impartf

static LispObject CC_impartf(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13956, v_13957;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_13825;
// end of prologue
    goto v_13832;
v_13828:
    v_13957 = elt(env, 1); // i
    goto v_13829;
v_13830:
    v_13956 = qvalue(elt(env, 2)); // kord!*
    goto v_13831;
v_13832:
    goto v_13828;
v_13829:
    goto v_13830;
v_13831:
    v_13956 = cons(v_13957, v_13956);
    env = stack[-4];
// Binding kord!*
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 2, -3);
    qvalue(elt(env, 2)) = v_13956; // kord!*
    v_13956 = stack[0];
    fn = elt(env, 4); // reorder
    v_13956 = (*qfn1(fn))(fn, v_13956);
    env = stack[-4];
    stack[-2] = v_13956;
    v_13956 = stack[-2];
    if (!consp(v_13956)) goto v_13845;
    else goto v_13846;
v_13845:
    v_13956 = lisp_true;
    goto v_13844;
v_13846:
    v_13956 = stack[-2];
    v_13956 = qcar(v_13956);
    v_13956 = (consp(v_13956) ? nil : lisp_true);
    goto v_13844;
    v_13956 = nil;
v_13844:
    if (v_13956 == nil) goto v_13842;
    v_13956 = stack[-2];
    if (!consp(v_13956)) goto v_13856;
    else goto v_13857;
v_13856:
    v_13956 = nil;
    goto v_13855;
v_13857:
    goto v_13867;
v_13863:
    v_13956 = stack[-2];
    v_13957 = qcar(v_13956);
    goto v_13864;
v_13865:
    v_13956 = elt(env, 3); // cmpxfn
    goto v_13866;
v_13867:
    goto v_13863;
v_13864:
    goto v_13865;
v_13866:
    v_13956 = get(v_13957, v_13956);
    env = stack[-4];
    if (v_13956 == nil) goto v_13861;
    goto v_13879;
v_13873:
    v_13956 = stack[-2];
    stack[-1] = qcar(v_13956);
    goto v_13874;
v_13875:
    v_13956 = stack[-2];
    v_13956 = qcdr(v_13956);
    stack[0] = qcdr(v_13956);
    goto v_13876;
v_13877:
    goto v_13890;
v_13886:
    v_13956 = stack[-2];
    v_13956 = qcar(v_13956);
    if (!symbolp(v_13956)) v_13957 = nil;
    else { v_13957 = qfastgets(v_13956);
           if (v_13957 != nil) { v_13957 = elt(v_13957, 34); // i2d
#ifdef RECORD_GET
             if (v_13957 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_13957 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_13957 == SPID_NOPROP) v_13957 = nil; }}
#endif
    goto v_13887;
v_13888:
    v_13956 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13889;
v_13890:
    goto v_13886;
v_13887:
    goto v_13888;
v_13889:
    v_13956 = Lapply1(nil, v_13957, v_13956);
    env = stack[-4];
    v_13956 = qcdr(v_13956);
    v_13956 = qcar(v_13956);
    goto v_13878;
v_13879:
    goto v_13873;
v_13874:
    goto v_13875;
v_13876:
    goto v_13877;
v_13878:
    v_13956 = list2star(stack[-1], stack[0], v_13956);
    env = stack[-4];
    fn = elt(env, 5); // int!-equiv!-chk
    v_13956 = (*qfn1(fn))(fn, v_13956);
    goto v_13855;
v_13861:
    v_13956 = nil;
    goto v_13855;
    v_13956 = nil;
v_13855:
    goto v_13840;
v_13842:
    goto v_13906;
v_13902:
    v_13956 = stack[-2];
    v_13956 = qcar(v_13956);
    v_13956 = qcar(v_13956);
    v_13957 = qcar(v_13956);
    goto v_13903;
v_13904:
    v_13956 = elt(env, 1); // i
    goto v_13905;
v_13906:
    goto v_13902;
v_13903:
    goto v_13904;
v_13905:
    if (v_13957 == v_13956) goto v_13900;
    else goto v_13901;
v_13900:
    goto v_13917;
v_13913:
    v_13956 = stack[-2];
    v_13956 = qcar(v_13956);
    stack[0] = qcdr(v_13956);
    goto v_13914;
v_13915:
    v_13956 = stack[-2];
    v_13956 = qcdr(v_13956);
    v_13956 = CC_impartf(elt(env, 0), v_13956);
    env = stack[-4];
    goto v_13916;
v_13917:
    goto v_13913;
v_13914:
    goto v_13915;
v_13916:
    fn = elt(env, 6); // addf
    v_13956 = (*qfn2(fn))(fn, stack[0], v_13956);
    goto v_13840;
v_13901:
    goto v_13931;
v_13927:
    goto v_13937;
v_13933:
    goto v_13944;
v_13940:
    v_13956 = stack[-2];
    v_13956 = qcar(v_13956);
    v_13957 = qcar(v_13956);
    goto v_13941;
v_13942:
    v_13956 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13943;
v_13944:
    goto v_13940;
v_13941:
    goto v_13942;
v_13943:
    v_13956 = cons(v_13957, v_13956);
    env = stack[-4];
    stack[0] = ncons(v_13956);
    env = stack[-4];
    goto v_13934;
v_13935:
    v_13956 = stack[-2];
    v_13956 = qcar(v_13956);
    v_13956 = qcdr(v_13956);
    v_13956 = CC_impartf(elt(env, 0), v_13956);
    env = stack[-4];
    goto v_13936;
v_13937:
    goto v_13933;
v_13934:
    goto v_13935;
v_13936:
    fn = elt(env, 7); // multf
    stack[0] = (*qfn2(fn))(fn, stack[0], v_13956);
    env = stack[-4];
    goto v_13928;
v_13929:
    v_13956 = stack[-2];
    v_13956 = qcdr(v_13956);
    v_13956 = CC_impartf(elt(env, 0), v_13956);
    env = stack[-4];
    goto v_13930;
v_13931:
    goto v_13927;
v_13928:
    goto v_13929;
v_13930:
    fn = elt(env, 6); // addf
    v_13956 = (*qfn2(fn))(fn, stack[0], v_13956);
    goto v_13840;
    v_13956 = nil;
v_13840:
    ;}  // end of a binding scope
    return onevalue(v_13956);
}



// Code for red_topredbe

static LispObject CC_red_topredbe(LispObject env,
                         LispObject v_13825, LispObject v_13826)
{
    env = qenv(env);
    LispObject v_13903, v_13904;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13826,v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13825,v_13826);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_13826;
    stack[-2] = v_13825;
// end of prologue
    v_13903 = stack[-1];
    fn = elt(env, 3); // bas_dpoly
    v_13903 = (*qfn1(fn))(fn, v_13903);
    env = stack[-4];
    if (v_13903 == nil) goto v_13834;
    else goto v_13835;
v_13834:
    v_13903 = lisp_true;
    goto v_13833;
v_13835:
    v_13903 = stack[-2];
    v_13903 = (v_13903 == nil ? lisp_true : nil);
    goto v_13833;
    v_13903 = nil;
v_13833:
    if (v_13903 == nil) goto v_13831;
    v_13903 = stack[-1];
    goto v_13829;
v_13831:
    goto v_13860;
v_13856:
    fn = elt(env, 4); // cali_trace
    v_13904 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_13857;
v_13858:
    v_13903 = (LispObject)1264+TAG_FIXNUM; // 79
    goto v_13859;
v_13860:
    goto v_13856;
v_13857:
    goto v_13858;
v_13859:
    v_13903 = (LispObject)greaterp2(v_13904, v_13903);
    v_13903 = v_13903 ? lisp_true : nil;
    env = stack[-4];
    if (v_13903 == nil) goto v_13854;
    v_13903 = elt(env, 2); // " reduce "
    v_13903 = Lprinc(nil, v_13903);
    env = stack[-4];
    v_13903 = stack[-1];
    fn = elt(env, 3); // bas_dpoly
    v_13903 = (*qfn1(fn))(fn, v_13903);
    env = stack[-4];
    fn = elt(env, 5); // dp_print
    v_13903 = (*qfn1(fn))(fn, v_13903);
    env = stack[-4];
    goto v_13852;
v_13854:
v_13852:
v_13871:
    v_13903 = stack[-1];
    fn = elt(env, 3); // bas_dpoly
    v_13903 = (*qfn1(fn))(fn, v_13903);
    env = stack[-4];
    v_13904 = v_13903;
    if (v_13903 == nil) goto v_13874;
    goto v_13887;
v_13881:
    stack[-3] = stack[-2];
    goto v_13882;
v_13883:
    v_13903 = v_13904;
    fn = elt(env, 6); // dp_lmon
    stack[0] = (*qfn1(fn))(fn, v_13903);
    env = stack[-4];
    goto v_13884;
v_13885:
    v_13903 = stack[-1];
    fn = elt(env, 7); // bas_dpecart
    v_13903 = (*qfn1(fn))(fn, v_13903);
    env = stack[-4];
    goto v_13886;
v_13887:
    goto v_13881;
v_13882:
    goto v_13883;
v_13884:
    goto v_13885;
v_13886:
    fn = elt(env, 8); // red_divtestbe
    v_13904 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_13903);
    env = stack[-4];
    v_13903 = v_13904;
    if (v_13904 == nil) goto v_13874;
    goto v_13875;
v_13874:
    goto v_13870;
v_13875:
    goto v_13899;
v_13895:
    v_13904 = stack[-1];
    goto v_13896;
v_13897:
    goto v_13898;
v_13899:
    goto v_13895;
v_13896:
    goto v_13897;
v_13898:
    fn = elt(env, 9); // red_subst
    v_13903 = (*qfn2(fn))(fn, v_13904, v_13903);
    env = stack[-4];
    stack[-1] = v_13903;
    goto v_13871;
v_13870:
    v_13903 = stack[-1];
    goto v_13829;
    v_13903 = nil;
v_13829:
    return onevalue(v_13903);
}



// Code for gcdout

static LispObject CC_gcdout(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13912, v_13913, v_13914;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13825;
// end of prologue
    v_13912 = qvalue(elt(env, 1)); // !*modular
    if (v_13912 == nil) goto v_13830;
    v_13912 = stack[0];
    goto v_13828;
v_13830:
    v_13912 = stack[0];
    if (v_13912 == nil) goto v_13833;
    else goto v_13834;
v_13833:
    v_13912 = nil;
    goto v_13828;
v_13834:
    goto v_13843;
v_13839:
    v_13912 = stack[0];
    fn = elt(env, 3); // ljet
    v_13912 = (*qfn1(fn))(fn, v_13912);
    env = stack[-2];
    fn = elt(env, 4); // ord
    v_13913 = (*qfn1(fn))(fn, v_13912);
    env = stack[-2];
    goto v_13840;
v_13841:
    v_13912 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13842;
v_13843:
    goto v_13839;
v_13840:
    goto v_13841;
v_13842:
    if (v_13913 == v_13912) goto v_13837;
    else goto v_13838;
v_13837:
    v_13912 = stack[0];
    goto v_13828;
v_13838:
    v_13912 = stack[0];
    stack[-1] = v_13912;
    v_13912 = stack[-1];
    v_13912 = qcar(v_13912);
    v_13912 = qcdr(v_13912);
    v_13914 = v_13912;
v_13862:
    v_13912 = stack[-1];
    if (v_13912 == nil) goto v_13865;
    goto v_13874;
v_13870:
    v_13913 = v_13914;
    goto v_13871;
v_13872:
    v_13912 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13873;
v_13874:
    goto v_13870;
v_13871:
    goto v_13872;
v_13873:
    if (v_13913 == v_13912) goto v_13865;
    goto v_13866;
v_13865:
    goto v_13861;
v_13866:
    goto v_13883;
v_13879:
    v_13913 = v_13914;
    goto v_13880;
v_13881:
    v_13912 = stack[-1];
    v_13912 = qcar(v_13912);
    v_13912 = qcdr(v_13912);
    goto v_13882;
v_13883:
    goto v_13879;
v_13880:
    goto v_13881;
v_13882:
    fn = elt(env, 5); // gcdf!*
    v_13912 = (*qfn2(fn))(fn, v_13913, v_13912);
    env = stack[-2];
    v_13914 = v_13912;
    v_13912 = stack[-1];
    v_13912 = qcdr(v_13912);
    stack[-1] = v_13912;
    goto v_13862;
v_13861:
    goto v_13898;
v_13894:
    v_13913 = v_13914;
    goto v_13895;
v_13896:
    v_13912 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13897;
v_13898:
    goto v_13894;
v_13895:
    goto v_13896;
v_13897:
    if (v_13913 == v_13912) goto v_13892;
    else goto v_13893;
v_13892:
    v_13912 = stack[0];
    goto v_13891;
v_13893:
    goto v_13909;
v_13905:
    v_13912 = stack[0];
    goto v_13906;
v_13907:
    v_13913 = v_13914;
    goto v_13908;
v_13909:
    goto v_13905;
v_13906:
    goto v_13907;
v_13908:
    {
        fn = elt(env, 6); // pcdiv
        return (*qfn2(fn))(fn, v_13912, v_13913);
    }
    v_13912 = nil;
v_13891:
    goto v_13828;
    v_13912 = nil;
v_13828:
    return onevalue(v_13912);
}



// Code for numlist_ordp

static LispObject CC_numlist_ordp(LispObject env,
                         LispObject v_13825, LispObject v_13826)
{
    env = qenv(env);
    LispObject v_13839, v_13840, v_13841;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13839 = v_13826;
    v_13840 = v_13825;
// end of prologue
    goto v_13835;
v_13829:
    v_13841 = v_13840;
    goto v_13830;
v_13831:
    v_13840 = v_13839;
    goto v_13832;
v_13833:
    v_13839 = elt(env, 1); // lambda_ygm6np4pcqv31
    goto v_13834;
v_13835:
    goto v_13829;
v_13830:
    goto v_13831;
v_13832:
    goto v_13833;
v_13834:
    {
        fn = elt(env, 2); // cons_ordp
        return (*qfnn(fn))(fn, 3, v_13841, v_13840, v_13839);
    }
}



// Code for lambda_ygm6np4pcqv31

static LispObject CC_lambda_ygm6np4pcqv31(LispObject env,
                         LispObject v_13825, LispObject v_13826)
{
    env = qenv(env);
    LispObject v_13836, v_13837;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13836 = v_13826;
    v_13837 = v_13825;
// end of prologue
    goto v_13833;
v_13829:
    goto v_13830;
v_13831:
    goto v_13832;
v_13833:
    goto v_13829;
v_13830:
    goto v_13831;
v_13832:
        return Lleq(nil, v_13837, v_13836);
}



// Code for ilog2

static LispObject CC_ilog2(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13953, v_13954;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_13825;
// end of prologue
    goto v_13842;
v_13838:
    v_13954 = stack[-2];
    goto v_13839;
v_13840:
    v_13953 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13841;
v_13842:
    goto v_13838;
v_13839:
    goto v_13840;
v_13841:
    v_13953 = (LispObject)lesseq2(v_13954, v_13953);
    v_13953 = v_13953 ? lisp_true : nil;
    env = stack[-4];
    if (v_13953 == nil) goto v_13836;
    goto v_13850;
v_13846:
    v_13954 = stack[-2];
    goto v_13847;
v_13848:
    v_13953 = elt(env, 0); // ilog2
    goto v_13849;
v_13850:
    goto v_13846;
v_13847:
    goto v_13848;
v_13849:
    fn = elt(env, 2); // terrlst
    v_13953 = (*qfn2(fn))(fn, v_13954, v_13953);
    env = stack[-4];
    goto v_13834;
v_13836:
v_13834:
    v_13953 = (LispObject)32+TAG_FIXNUM; // 2
    stack[0] = v_13953;
    v_13953 = stack[0];
    v_13953 = ncons(v_13953);
    env = stack[-4];
    stack[-1] = v_13953;
v_13858:
    goto v_13868;
v_13864:
    v_13954 = stack[-2];
    goto v_13865;
v_13866:
    v_13953 = stack[0];
    goto v_13867;
v_13868:
    goto v_13864;
v_13865:
    goto v_13866;
v_13867:
    v_13953 = (LispObject)greaterp2(v_13954, v_13953);
    v_13953 = v_13953 ? lisp_true : nil;
    env = stack[-4];
    if (v_13953 == nil) goto v_13861;
    else goto v_13862;
v_13861:
    goto v_13857;
v_13862:
    goto v_13877;
v_13873:
    v_13954 = stack[0];
    goto v_13874;
v_13875:
    v_13953 = stack[-1];
    goto v_13876;
v_13877:
    goto v_13873;
v_13874:
    goto v_13875;
v_13876:
    v_13953 = cons(v_13954, v_13953);
    env = stack[-4];
    stack[-1] = v_13953;
    goto v_13885;
v_13881:
    v_13954 = stack[0];
    goto v_13882;
v_13883:
    v_13953 = stack[0];
    goto v_13884;
v_13885:
    goto v_13881;
v_13882:
    goto v_13883;
v_13884:
    v_13953 = times2(v_13954, v_13953);
    env = stack[-4];
    stack[0] = v_13953;
    goto v_13858;
v_13857:
    v_13953 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_13953;
v_13891:
    goto v_13900;
v_13896:
    v_13953 = stack[-1];
    v_13954 = qcar(v_13953);
    stack[0] = v_13954;
    goto v_13897;
v_13898:
    v_13953 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13899;
v_13900:
    goto v_13896;
v_13897:
    goto v_13898;
v_13899:
    if (v_13954 == v_13953) goto v_13894;
    else goto v_13895;
v_13894:
    goto v_13890;
v_13895:
    v_13953 = stack[-1];
    v_13953 = qcdr(v_13953);
    stack[-1] = v_13953;
    goto v_13916;
v_13912:
    v_13954 = stack[-2];
    goto v_13913;
v_13914:
    v_13953 = stack[0];
    goto v_13915;
v_13916:
    goto v_13912;
v_13913:
    goto v_13914;
v_13915:
    v_13953 = (LispObject)geq2(v_13954, v_13953);
    v_13953 = v_13953 ? lisp_true : nil;
    env = stack[-4];
    if (v_13953 == nil) goto v_13910;
    goto v_13924;
v_13920:
    v_13954 = stack[-2];
    goto v_13921;
v_13922:
    v_13953 = stack[0];
    goto v_13923;
v_13924:
    goto v_13920;
v_13921:
    goto v_13922;
v_13923:
    v_13953 = quot2(v_13954, v_13953);
    env = stack[-4];
    stack[-2] = v_13953;
    v_13953 = stack[-3];
    v_13953 = add1(v_13953);
    env = stack[-4];
    stack[-3] = v_13953;
    goto v_13908;
v_13910:
v_13908:
    goto v_13935;
v_13931:
    v_13954 = stack[-3];
    goto v_13932;
v_13933:
    v_13953 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13934;
v_13935:
    goto v_13931;
v_13932:
    goto v_13933;
v_13934:
    v_13953 = times2(v_13954, v_13953);
    env = stack[-4];
    stack[-3] = v_13953;
    goto v_13891;
v_13890:
    goto v_13947;
v_13943:
    v_13954 = stack[-2];
    goto v_13944;
v_13945:
    v_13953 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13946;
v_13947:
    goto v_13943;
v_13944:
    goto v_13945;
v_13946:
    v_13953 = (LispObject)geq2(v_13954, v_13953);
    v_13953 = v_13953 ? lisp_true : nil;
    env = stack[-4];
    if (v_13953 == nil) goto v_13941;
    v_13953 = stack[-3];
    v_13953 = add1(v_13953);
    stack[-3] = v_13953;
    goto v_13939;
v_13941:
v_13939:
    v_13953 = stack[-3];
    return onevalue(v_13953);
}



// Code for let2

static LispObject CC_let2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_14128, v_14129, v_14130, v_14131, v_14132;
    LispObject fn;
    LispObject v_13828, v_13827, v_13826, v_13825;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "let2");
    va_start(aa, nargs);
    v_13825 = va_arg(aa, LispObject);
    v_13826 = va_arg(aa, LispObject);
    v_13827 = va_arg(aa, LispObject);
    v_13828 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_13828,v_13827,v_13826,v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_13825,v_13826,v_13827,v_13828);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-3] = v_13828;
    stack[-4] = v_13827;
    stack[-5] = v_13826;
    stack[-6] = v_13825;
// end of prologue
    stack[-7] = nil;
    v_14128 = stack[-6];
    fn = elt(env, 13); // getrtype
    v_14128 = (*qfn1(fn))(fn, v_14128);
    env = stack[-8];
    stack[-1] = v_14128;
    if (v_14128 == nil) goto v_13840;
    goto v_13851;
v_13847:
    v_14129 = stack[-1];
    goto v_13848;
v_13849:
    v_14128 = elt(env, 2); // typeletfn
    goto v_13850;
v_13851:
    goto v_13847;
v_13848:
    goto v_13849;
v_13850:
    v_14128 = get(v_14129, v_14128);
    env = stack[-8];
    v_14130 = v_14128;
    if (v_14128 == nil) goto v_13840;
    goto v_13860;
v_13856:
    v_14129 = v_14130;
    goto v_13857;
v_13858:
    v_14128 = elt(env, 3); // direct
    goto v_13859;
v_13860:
    goto v_13856;
v_13857:
    goto v_13858;
v_13859:
    v_14128 = Lflagp(nil, v_14129, v_14128);
    env = stack[-8];
    if (v_14128 == nil) goto v_13840;
    goto v_13868;
v_13864:
    stack[-2] = v_14130;
    goto v_13865;
v_13866:
    goto v_13879;
v_13871:
    stack[-4] = stack[-6];
    goto v_13872;
v_13873:
    stack[0] = stack[-5];
    goto v_13874;
v_13875:
    goto v_13876;
v_13877:
    goto v_13888;
v_13884:
    goto v_13885;
v_13886:
    v_14128 = stack[-5];
    fn = elt(env, 13); // getrtype
    v_14128 = (*qfn1(fn))(fn, v_14128);
    env = stack[-8];
    goto v_13887;
v_13888:
    goto v_13884;
v_13885:
    goto v_13886;
v_13887:
    v_14128 = list2(stack[-3], v_14128);
    env = stack[-8];
    goto v_13878;
v_13879:
    goto v_13871;
v_13872:
    goto v_13873;
v_13874:
    goto v_13875;
v_13876:
    goto v_13877;
v_13878:
    v_14128 = list3star(stack[-4], stack[0], stack[-1], v_14128);
    env = stack[-8];
    goto v_13867;
v_13868:
    goto v_13864;
v_13865:
    goto v_13866;
v_13867:
    {
        LispObject v_14141 = stack[-2];
        fn = elt(env, 14); // lispapply
        return (*qfn2(fn))(fn, v_14141, v_14128);
    }
v_13840:
    v_14128 = stack[-5];
    fn = elt(env, 13); // getrtype
    v_14128 = (*qfn1(fn))(fn, v_14128);
    env = stack[-8];
    stack[-1] = v_14128;
    if (v_14128 == nil) goto v_13893;
    goto v_13904;
v_13900:
    v_14129 = stack[-1];
    goto v_13901;
v_13902:
    v_14128 = elt(env, 2); // typeletfn
    goto v_13903;
v_13904:
    goto v_13900;
v_13901:
    goto v_13902;
v_13903:
    v_14128 = get(v_14129, v_14128);
    env = stack[-8];
    v_14130 = v_14128;
    if (v_14128 == nil) goto v_13893;
    goto v_13913;
v_13909:
    v_14129 = v_14130;
    goto v_13910;
v_13911:
    v_14128 = elt(env, 3); // direct
    goto v_13912;
v_13913:
    goto v_13909;
v_13910:
    goto v_13911;
v_13912:
    v_14128 = Lflagp(nil, v_14129, v_14128);
    env = stack[-8];
    if (v_14128 == nil) goto v_13893;
    goto v_13921;
v_13917:
    stack[-2] = v_14130;
    goto v_13918;
v_13919:
    goto v_13932;
v_13924:
    stack[-4] = stack[-6];
    goto v_13925;
v_13926:
    goto v_13927;
v_13928:
    stack[0] = nil;
    goto v_13929;
v_13930:
    goto v_13941;
v_13937:
    v_14129 = stack[-3];
    goto v_13938;
v_13939:
    v_14128 = stack[-1];
    goto v_13940;
v_13941:
    goto v_13937;
v_13938:
    goto v_13939;
v_13940:
    v_14128 = list2(v_14129, v_14128);
    env = stack[-8];
    goto v_13931;
v_13932:
    goto v_13924;
v_13925:
    goto v_13926;
v_13927:
    goto v_13928;
v_13929:
    goto v_13930;
v_13931:
    v_14128 = list3star(stack[-4], stack[-5], stack[0], v_14128);
    env = stack[-8];
    goto v_13920;
v_13921:
    goto v_13917;
v_13918:
    goto v_13919;
v_13920:
    {
        LispObject v_14142 = stack[-2];
        fn = elt(env, 14); // lispapply
        return (*qfn2(fn))(fn, v_14142, v_14128);
    }
v_13893:
    goto v_13949;
v_13945:
    v_14129 = qvalue(elt(env, 4)); // frasc!*
    goto v_13946;
v_13947:
    v_14128 = stack[-6];
    goto v_13948;
v_13949:
    goto v_13945;
v_13946:
    goto v_13947;
v_13948:
    v_14128 = Lsubla(nil, v_14129, v_14128);
    env = stack[-8];
    stack[-2] = v_14128;
    goto v_13960;
v_13956:
    v_14129 = stack[-2];
    goto v_13957;
v_13958:
    v_14128 = stack[-6];
    goto v_13959;
v_13960:
    goto v_13956;
v_13957:
    goto v_13958;
v_13959:
    if (equal(v_14129, v_14128)) goto v_13955;
    v_14128 = stack[-2];
    if (!consp(v_14128)) goto v_13965;
    else goto v_13966;
v_13965:
    v_14128 = stack[-6];
    {
        fn = elt(env, 15); // errpri1
        return (*qfn1(fn))(fn, v_14128);
    }
v_13966:
    v_14128 = lisp_true;
    stack[-7] = v_14128;
    v_14128 = stack[-2];
    stack[-6] = v_14128;
    goto v_13964;
v_13964:
    goto v_13953;
v_13955:
v_13953:
    goto v_13979;
v_13975:
    v_14129 = qvalue(elt(env, 4)); // frasc!*
    goto v_13976;
v_13977:
    v_14128 = stack[-5];
    goto v_13978;
v_13979:
    goto v_13975;
v_13976:
    goto v_13977;
v_13978:
    v_14128 = Lsubla(nil, v_14129, v_14128);
    env = stack[-8];
    stack[-2] = v_14128;
    goto v_13990;
v_13986:
    v_14129 = stack[-2];
    goto v_13987;
v_13988:
    v_14128 = stack[-5];
    goto v_13989;
v_13990:
    goto v_13986;
v_13987:
    goto v_13988;
v_13989:
    if (equal(v_14129, v_14128)) goto v_13985;
    v_14128 = stack[-2];
    stack[-5] = v_14128;
    goto v_14003;
v_13999:
    v_14129 = stack[-5];
    goto v_14000;
v_14001:
    v_14128 = elt(env, 5); // !*sq!*
    goto v_14002;
v_14003:
    goto v_13999;
v_14000:
    goto v_14001;
v_14002:
    if (!consp(v_14129)) goto v_13997;
    v_14129 = qcar(v_14129);
    if (v_14129 == v_14128) goto v_13996;
    else goto v_13997;
v_13996:
    v_14128 = stack[-5];
    v_14128 = qcdr(v_14128);
    v_14128 = qcar(v_14128);
    fn = elt(env, 16); // prepsq!*
    v_14128 = (*qfn1(fn))(fn, v_14128);
    env = stack[-8];
    stack[-5] = v_14128;
    goto v_13995;
v_13997:
v_13995:
    goto v_13983;
v_13985:
v_13983:
    goto v_14015;
v_14011:
    v_14129 = qvalue(elt(env, 6)); // frlis!*
    goto v_14012;
v_14013:
    v_14128 = qvalue(elt(env, 7)); // mcond!*
    goto v_14014;
v_14015:
    goto v_14011;
v_14012:
    goto v_14013;
v_14014:
    fn = elt(env, 17); // smemql
    v_14128 = (*qfn2(fn))(fn, v_14129, v_14128);
    env = stack[-8];
    stack[-2] = v_14128;
    goto v_14023;
v_14019:
    v_14129 = qvalue(elt(env, 6)); // frlis!*
    goto v_14020;
v_14021:
    v_14128 = stack[-6];
    goto v_14022;
v_14023:
    goto v_14019;
v_14020:
    goto v_14021;
v_14022:
    fn = elt(env, 17); // smemql
    v_14128 = (*qfn2(fn))(fn, v_14129, v_14128);
    env = stack[-8];
    stack[-1] = v_14128;
    goto v_14036;
v_14032:
    v_14129 = stack[-2];
    goto v_14033;
v_14034:
    v_14128 = stack[-1];
    goto v_14035;
v_14036:
    goto v_14032;
v_14033:
    goto v_14034;
v_14035:
    fn = elt(env, 18); // setdiff
    v_14128 = (*qfn2(fn))(fn, v_14129, v_14128);
    env = stack[-8];
    v_14130 = v_14128;
    if (v_14128 == nil) goto v_14030;
    else goto v_14028;
v_14030:
    goto v_14045;
v_14041:
    goto v_14051;
v_14047:
    goto v_14057;
v_14053:
    v_14129 = qvalue(elt(env, 6)); // frlis!*
    goto v_14054;
v_14055:
    v_14128 = stack[-5];
    goto v_14056;
v_14057:
    goto v_14053;
v_14054:
    goto v_14055;
v_14056:
    fn = elt(env, 17); // smemql
    v_14129 = (*qfn2(fn))(fn, v_14129, v_14128);
    env = stack[-8];
    goto v_14048;
v_14049:
    v_14128 = stack[-2];
    goto v_14050;
v_14051:
    goto v_14047;
v_14048:
    goto v_14049;
v_14050:
    fn = elt(env, 18); // setdiff
    stack[0] = (*qfn2(fn))(fn, v_14129, v_14128);
    env = stack[-8];
    goto v_14042;
v_14043:
    goto v_14066;
v_14062:
    v_14129 = stack[-1];
    goto v_14063;
v_14064:
    v_14128 = stack[-2];
    goto v_14065;
v_14066:
    goto v_14062;
v_14063:
    goto v_14064;
v_14065:
    fn = elt(env, 18); // setdiff
    v_14128 = (*qfn2(fn))(fn, v_14129, v_14128);
    env = stack[-8];
    goto v_14044;
v_14045:
    goto v_14041;
v_14042:
    goto v_14043;
v_14044:
    fn = elt(env, 18); // setdiff
    v_14128 = (*qfn2(fn))(fn, stack[0], v_14128);
    env = stack[-8];
    v_14130 = v_14128;
    if (v_14128 == nil) goto v_14039;
    else goto v_14028;
v_14039:
    goto v_14029;
v_14028:
    goto v_14075;
v_14071:
    v_14128 = elt(env, 8); // "Unmatched free variable(s)"
    goto v_14072;
v_14073:
    v_14129 = v_14130;
    goto v_14074;
v_14075:
    goto v_14071;
v_14072:
    goto v_14073;
v_14074:
    v_14128 = cons(v_14128, v_14129);
    env = stack[-8];
    fn = elt(env, 19); // lprie
    v_14128 = (*qfn1(fn))(fn, v_14128);
    env = stack[-8];
    v_14128 = elt(env, 9); // hold
    qvalue(elt(env, 10)) = v_14128; // erfg!*
    v_14128 = nil;
    goto v_13835;
v_14029:
    v_14128 = stack[-6];
    if (!consp(v_14128)) goto v_14080;
    else goto v_14081;
v_14080:
    goto v_14027;
v_14081:
    goto v_14090;
v_14086:
    v_14128 = stack[-6];
    v_14129 = qcar(v_14128);
    goto v_14087;
v_14088:
    v_14128 = elt(env, 11); // getel
    goto v_14089;
v_14090:
    goto v_14086;
v_14087:
    goto v_14088;
v_14089:
    if (v_14129 == v_14128) goto v_14084;
    else goto v_14085;
v_14084:
    v_14128 = stack[-6];
    v_14128 = qcdr(v_14128);
    v_14128 = qcar(v_14128);
    fn = elt(env, 20); // lispeval
    v_14128 = (*qfn1(fn))(fn, v_14128);
    env = stack[-8];
    stack[-6] = v_14128;
    goto v_14027;
v_14085:
    goto v_14105;
v_14101:
    v_14128 = stack[-6];
    v_14129 = qcar(v_14128);
    goto v_14102;
v_14103:
    v_14128 = elt(env, 12); // immediate
    goto v_14104;
v_14105:
    goto v_14101;
v_14102:
    goto v_14103;
v_14104:
    v_14128 = Lflagp(nil, v_14129, v_14128);
    env = stack[-8];
    if (v_14128 == nil) goto v_14099;
    v_14128 = stack[-6];
    fn = elt(env, 21); // reval
    v_14128 = (*qfn1(fn))(fn, v_14128);
    env = stack[-8];
    stack[-6] = v_14128;
    goto v_14027;
v_14099:
v_14027:
    goto v_14122;
v_14112:
    v_14132 = stack[-6];
    goto v_14113;
v_14114:
    v_14131 = stack[-5];
    goto v_14115;
v_14116:
    v_14130 = stack[-4];
    goto v_14117;
v_14118:
    v_14129 = stack[-3];
    goto v_14119;
v_14120:
    v_14128 = stack[-7];
    goto v_14121;
v_14122:
    goto v_14112;
v_14113:
    goto v_14114;
v_14115:
    goto v_14116;
v_14117:
    goto v_14118;
v_14119:
    goto v_14120;
v_14121:
    {
        fn = elt(env, 22); // let3
        return (*qfnn(fn))(fn, 5, v_14132, v_14131, v_14130, v_14129, v_14128);
    }
v_13835:
    return onevalue(v_14128);
}



// Code for remlocs

static LispObject CC_remlocs(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13924, v_13925;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_13925 = v_13825;
// end of prologue
    v_13924 = qvalue(elt(env, 2)); // !*globals
    if (v_13924 == nil) goto v_13834;
    v_13924 = v_13925;
    stack[-2] = v_13924;
v_13839:
    v_13924 = stack[-2];
    if (v_13924 == nil) goto v_13843;
    else goto v_13844;
v_13843:
    goto v_13838;
v_13844:
    v_13924 = stack[-2];
    v_13924 = qcar(v_13924);
    stack[-1] = v_13924;
    goto v_13854;
v_13850:
    v_13925 = stack[-1];
    goto v_13851;
v_13852:
    v_13924 = qvalue(elt(env, 3)); // locls!*
    goto v_13853;
v_13854:
    goto v_13850;
v_13851:
    goto v_13852;
v_13853:
    v_13924 = Lassoc(nil, v_13925, v_13924);
    stack[-3] = v_13924;
    v_13924 = stack[-3];
    if (v_13924 == nil) goto v_13860;
    else goto v_13861;
v_13860:
    v_13924 = elt(env, 4); // begin
    fn = elt(env, 6); // getd
    v_13924 = (*qfn1(fn))(fn, v_13924);
    env = stack[-4];
    if (v_13924 == nil) goto v_13866;
    goto v_13875;
v_13871:
    v_13925 = elt(env, 5); // " Lvar confused"
    goto v_13872;
v_13873:
    v_13924 = stack[-1];
    goto v_13874;
v_13875:
    goto v_13871;
v_13872:
    goto v_13873;
v_13874:
    v_13924 = list2(v_13925, v_13924);
    env = stack[-4];
    fn = elt(env, 7); // rederr
    v_13924 = (*qfn1(fn))(fn, v_13924);
    env = stack[-4];
    goto v_13864;
v_13866:
    goto v_13885;
v_13881:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13882;
v_13883:
    goto v_13892;
v_13888:
    v_13925 = elt(env, 5); // " Lvar confused"
    goto v_13889;
v_13890:
    v_13924 = stack[-1];
    goto v_13891;
v_13892:
    goto v_13888;
v_13889:
    goto v_13890;
v_13891:
    v_13924 = list2(v_13925, v_13924);
    env = stack[-4];
    goto v_13884;
v_13885:
    goto v_13881;
v_13882:
    goto v_13883;
v_13884:
    fn = elt(env, 8); // error
    v_13924 = (*qfn2(fn))(fn, stack[0], v_13924);
    env = stack[-4];
    goto v_13864;
v_13864:
    goto v_13859;
v_13861:
v_13859:
    v_13924 = stack[-3];
    v_13924 = qcdr(v_13924);
    v_13924 = qcdr(v_13924);
    if (v_13924 == nil) goto v_13898;
    goto v_13907;
v_13903:
    v_13925 = stack[-3];
    goto v_13904;
v_13905:
    v_13924 = stack[-3];
    v_13924 = qcdr(v_13924);
    v_13924 = qcdr(v_13924);
    goto v_13906;
v_13907:
    goto v_13903;
v_13904:
    goto v_13905;
v_13906:
    v_13924 = Lrplacd(nil, v_13925, v_13924);
    env = stack[-4];
    goto v_13896;
v_13898:
    goto v_13919;
v_13915:
    v_13925 = stack[-3];
    goto v_13916;
v_13917:
    v_13924 = qvalue(elt(env, 3)); // locls!*
    goto v_13918;
v_13919:
    goto v_13915;
v_13916:
    goto v_13917;
v_13918:
    fn = elt(env, 9); // efface1
    v_13924 = (*qfn2(fn))(fn, v_13925, v_13924);
    env = stack[-4];
    qvalue(elt(env, 3)) = v_13924; // locls!*
    goto v_13896;
v_13896:
    v_13924 = stack[-2];
    v_13924 = qcdr(v_13924);
    stack[-2] = v_13924;
    goto v_13839;
v_13838:
    goto v_13832;
v_13834:
v_13832:
    v_13924 = nil;
    return onevalue(v_13924);
}



// Code for ofsf_ignshift

static LispObject CC_ofsf_ignshift(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13915, v_13916, v_13917;
    LispObject fn;
    LispObject v_13827, v_13826, v_13825;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_ignshift");
    va_start(aa, nargs);
    v_13825 = va_arg(aa, LispObject);
    v_13826 = va_arg(aa, LispObject);
    v_13827 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13827,v_13826,v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13825,v_13826,v_13827);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13827;
    stack[-1] = v_13826;
    stack[-2] = v_13825;
// end of prologue
    goto v_13838;
v_13834:
    v_13915 = stack[-2];
    v_13915 = qcdr(v_13915);
    v_13916 = qcar(v_13915);
    goto v_13835;
v_13836:
    v_13915 = stack[-1];
    goto v_13837;
v_13838:
    goto v_13834;
v_13835:
    goto v_13836;
v_13837:
    fn = elt(env, 6); // sfto_reorder
    v_13915 = (*qfn2(fn))(fn, v_13916, v_13915);
    env = stack[-3];
    v_13917 = v_13915;
    v_13915 = v_13917;
    if (!consp(v_13915)) goto v_13853;
    else goto v_13854;
v_13853:
    v_13915 = lisp_true;
    goto v_13852;
v_13854:
    v_13915 = v_13917;
    v_13915 = qcar(v_13915);
    v_13915 = (consp(v_13915) ? nil : lisp_true);
    goto v_13852;
    v_13915 = nil;
v_13852:
    if (v_13915 == nil) goto v_13849;
    else goto v_13850;
v_13849:
    v_13915 = v_13917;
    v_13915 = qcdr(v_13915);
    if (v_13915 == nil) goto v_13864;
    else goto v_13865;
v_13864:
    goto v_13872;
v_13868:
    v_13915 = v_13917;
    v_13915 = qcar(v_13915);
    v_13915 = qcar(v_13915);
    v_13916 = qcar(v_13915);
    goto v_13869;
v_13870:
    v_13915 = stack[-1];
    goto v_13871;
v_13872:
    goto v_13868;
v_13869:
    goto v_13870;
v_13871:
    v_13915 = (v_13916 == v_13915 ? lisp_true : nil);
    goto v_13863;
v_13865:
    v_13915 = nil;
    goto v_13863;
    v_13915 = nil;
v_13863:
    goto v_13848;
v_13850:
    v_13915 = nil;
    goto v_13848;
    v_13915 = nil;
v_13848:
    if (v_13915 == nil) goto v_13846;
    v_13915 = qvalue(elt(env, 2)); // !*rlpos
    if (v_13915 == nil) goto v_13889;
    else goto v_13887;
v_13889:
    v_13915 = stack[0];
    if (v_13915 == nil) goto v_13892;
    else goto v_13887;
v_13892:
    goto v_13900;
v_13896:
    v_13915 = stack[-2];
    v_13916 = qcar(v_13915);
    goto v_13897;
v_13898:
    v_13915 = elt(env, 3); // (equal neq)
    goto v_13899;
v_13900:
    goto v_13896;
v_13897:
    goto v_13898;
v_13899:
    v_13915 = Lmemq(nil, v_13916, v_13915);
    if (v_13915 == nil) goto v_13895;
    else goto v_13887;
v_13895:
    v_13915 = v_13917;
    v_13915 = qcar(v_13915);
    v_13915 = qcar(v_13915);
    v_13915 = qcdr(v_13915);
    v_13915 = Levenp(nil, v_13915);
    env = stack[-3];
    if (v_13915 == nil) goto v_13905;
    else goto v_13887;
v_13905:
    goto v_13888;
v_13887:
    v_13915 = elt(env, 4); // ignore
    goto v_13831;
v_13888:
    v_13915 = elt(env, 5); // odd
    goto v_13831;
    goto v_13844;
v_13846:
v_13844:
    v_13915 = nil;
v_13831:
    return onevalue(v_13915);
}



// Code for cl_pnf

static LispObject CC_cl_pnf(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13830;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_13830 = v_13825;
// end of prologue
    fn = elt(env, 1); // rl_nnf
    v_13830 = (*qfn1(fn))(fn, v_13830);
    env = stack[0];
    {
        fn = elt(env, 2); // cl_pnf1
        return (*qfn1(fn))(fn, v_13830);
    }
}



// Code for expnd

static LispObject CC_expnd(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13863, v_13864, v_13865;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13825;
// end of prologue
    v_13863 = qvalue(elt(env, 1)); // !*really_off_exp
    if (v_13863 == nil) goto v_13830;
    v_13863 = stack[0];
    goto v_13828;
v_13830:
// Binding !*sub2
// FLUIDBIND: reloadenv=2 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 2, -1);
    qvalue(elt(env, 2)) = nil; // !*sub2
    v_13863 = stack[0];
    fn = elt(env, 4); // expnd1
    v_13863 = (*qfn1(fn))(fn, v_13863);
    env = stack[-2];
    stack[0] = v_13863;
    v_13863 = qvalue(elt(env, 2)); // !*sub2
    if (v_13863 == nil) goto v_13845;
    goto v_13853;
v_13849:
    v_13863 = stack[0];
    fn = elt(env, 5); // subs2f
    v_13863 = (*qfn1(fn))(fn, v_13863);
    v_13865 = v_13863;
    v_13864 = qcdr(v_13863);
    goto v_13850;
v_13851:
    v_13863 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13852;
v_13853:
    goto v_13849;
v_13850:
    goto v_13851;
v_13852:
    if (v_13864 == v_13863) goto v_13848;
    else goto v_13845;
v_13848:
    v_13863 = v_13865;
    v_13863 = qcar(v_13863);
    goto v_13843;
v_13845:
    v_13863 = stack[0];
    goto v_13843;
    v_13863 = nil;
v_13843:
    ;}  // end of a binding scope
    goto v_13828;
    v_13863 = nil;
v_13828:
    return onevalue(v_13863);
}



// Code for pasf_mkpos

static LispObject CC_pasf_mkpos(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13964, v_13965;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13825;
// end of prologue
    goto v_13847;
v_13843:
    v_13965 = stack[0];
    goto v_13844;
v_13845:
    v_13964 = elt(env, 2); // true
    goto v_13846;
v_13847:
    goto v_13843;
v_13844:
    goto v_13845;
v_13846:
    if (v_13965 == v_13964) goto v_13841;
    else goto v_13842;
v_13841:
    v_13964 = lisp_true;
    goto v_13840;
v_13842:
    goto v_13857;
v_13853:
    v_13965 = stack[0];
    goto v_13854;
v_13855:
    v_13964 = elt(env, 3); // false
    goto v_13856;
v_13857:
    goto v_13853;
v_13854:
    goto v_13855;
v_13856:
    v_13964 = (v_13965 == v_13964 ? lisp_true : nil);
    goto v_13840;
    v_13964 = nil;
v_13840:
    if (v_13964 == nil) goto v_13837;
    else goto v_13838;
v_13837:
    v_13964 = stack[0];
    v_13964 = qcdr(v_13964);
    v_13964 = qcar(v_13964);
    fn = elt(env, 5); // minusf
    v_13964 = (*qfn1(fn))(fn, v_13964);
    env = stack[-3];
    goto v_13836;
v_13838:
    v_13964 = nil;
    goto v_13836;
    v_13964 = nil;
v_13836:
    if (v_13964 == nil) goto v_13834;
    v_13964 = stack[0];
    fn = elt(env, 6); // pasf_anegateat
    v_13964 = (*qfn1(fn))(fn, v_13964);
    env = stack[-3];
    goto v_13832;
v_13834:
    v_13964 = stack[0];
    goto v_13832;
    v_13964 = nil;
v_13832:
    stack[-2] = v_13964;
    v_13964 = stack[-2];
    v_13964 = Lconsp(nil, v_13964);
    env = stack[-3];
    if (v_13964 == nil) goto v_13876;
    v_13964 = stack[-2];
    v_13964 = qcar(v_13964);
    v_13964 = Lconsp(nil, v_13964);
    env = stack[-3];
    if (v_13964 == nil) goto v_13876;
    goto v_13891;
v_13887:
    v_13964 = stack[-2];
    v_13964 = qcar(v_13964);
    v_13965 = qcar(v_13964);
    goto v_13888;
v_13889:
    v_13964 = elt(env, 4); // (cong ncong)
    goto v_13890;
v_13891:
    goto v_13887;
v_13888:
    goto v_13889;
v_13890:
    v_13964 = Lmemq(nil, v_13965, v_13964);
    if (v_13964 == nil) goto v_13876;
    v_13964 = stack[-2];
    v_13964 = qcar(v_13964);
    v_13964 = qcdr(v_13964);
    fn = elt(env, 5); // minusf
    v_13964 = (*qfn1(fn))(fn, v_13964);
    env = stack[-3];
    if (v_13964 == nil) goto v_13876;
    goto v_13909;
v_13903:
    goto v_13922;
v_13918:
    v_13965 = stack[-2];
    goto v_13919;
v_13920:
    v_13964 = elt(env, 2); // true
    goto v_13921;
v_13922:
    goto v_13918;
v_13919:
    goto v_13920;
v_13921:
    if (v_13965 == v_13964) goto v_13916;
    else goto v_13917;
v_13916:
    v_13964 = lisp_true;
    goto v_13915;
v_13917:
    goto v_13932;
v_13928:
    v_13965 = stack[-2];
    goto v_13929;
v_13930:
    v_13964 = elt(env, 3); // false
    goto v_13931;
v_13932:
    goto v_13928;
v_13929:
    goto v_13930;
v_13931:
    v_13964 = (v_13965 == v_13964 ? lisp_true : nil);
    goto v_13915;
    v_13964 = nil;
v_13915:
    if (v_13964 == nil) goto v_13913;
    v_13964 = stack[-2];
    stack[-1] = v_13964;
    goto v_13911;
v_13913:
    v_13964 = stack[-2];
    v_13964 = qcar(v_13964);
    v_13964 = Lconsp(nil, v_13964);
    env = stack[-3];
    if (v_13964 == nil) goto v_13938;
    v_13964 = stack[-2];
    v_13964 = qcar(v_13964);
    v_13964 = qcar(v_13964);
    stack[-1] = v_13964;
    goto v_13911;
v_13938:
    v_13964 = stack[-2];
    v_13964 = qcar(v_13964);
    stack[-1] = v_13964;
    goto v_13911;
    stack[-1] = nil;
v_13911:
    goto v_13904;
v_13905:
    v_13964 = stack[-2];
    v_13964 = qcar(v_13964);
    v_13964 = qcdr(v_13964);
    fn = elt(env, 7); // negf
    stack[0] = (*qfn1(fn))(fn, v_13964);
    env = stack[-3];
    goto v_13906;
v_13907:
    goto v_13958;
v_13954:
    v_13964 = stack[-2];
    v_13964 = qcdr(v_13964);
    v_13965 = qcar(v_13964);
    goto v_13955;
v_13956:
    v_13964 = nil;
    goto v_13957;
v_13958:
    goto v_13954;
v_13955:
    goto v_13956;
v_13957:
    v_13964 = list2(v_13965, v_13964);
    env = stack[-3];
    goto v_13908;
v_13909:
    goto v_13903;
v_13904:
    goto v_13905;
v_13906:
    goto v_13907;
v_13908:
    v_13964 = acons(stack[-1], stack[0], v_13964);
    stack[-2] = v_13964;
    goto v_13874;
v_13876:
v_13874:
    v_13964 = stack[-2];
    return onevalue(v_13964);
}



// Code for diff!-k!-times!-mod!-p

static LispObject CC_diffKkKtimesKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_14010, v_14011, v_14012;
    LispObject fn;
    LispObject v_13827, v_13826, v_13825;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "diff-k-times-mod-p");
    va_start(aa, nargs);
    v_13825 = va_arg(aa, LispObject);
    v_13826 = va_arg(aa, LispObject);
    v_13827 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13827,v_13826,v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13825,v_13826,v_13827);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_13827;
    stack[-2] = v_13826;
    stack[-3] = v_13825;
// end of prologue
    v_14010 = stack[-3];
    if (!consp(v_14010)) goto v_13835;
    else goto v_13836;
v_13835:
    v_14010 = lisp_true;
    goto v_13834;
v_13836:
    v_14010 = stack[-3];
    v_14010 = qcar(v_14010);
    v_14010 = (consp(v_14010) ? nil : lisp_true);
    goto v_13834;
    v_14010 = nil;
v_13834:
    if (v_14010 == nil) goto v_13832;
    v_14010 = nil;
    goto v_13830;
v_13832:
    goto v_13851;
v_13847:
    v_14010 = stack[-3];
    v_14010 = qcar(v_14010);
    v_14010 = qcar(v_14010);
    v_14011 = qcar(v_14010);
    goto v_13848;
v_13849:
    v_14010 = stack[-1];
    goto v_13850;
v_13851:
    goto v_13847;
v_13848:
    goto v_13849;
v_13850:
    if (equal(v_14011, v_14010)) goto v_13845;
    else goto v_13846;
v_13845:
    goto v_13866;
v_13862:
    v_14010 = stack[-3];
    v_14010 = qcar(v_14010);
    v_14010 = qcar(v_14010);
    v_14011 = qcdr(v_14010);
    goto v_13863;
v_13864:
    v_14010 = stack[-2];
    goto v_13865;
v_13866:
    goto v_13862;
v_13863:
    goto v_13864;
v_13865:
    v_14010 = (LispObject)lessp2(v_14011, v_14010);
    v_14010 = v_14010 ? lisp_true : nil;
    env = stack[-5];
    if (v_14010 == nil) goto v_13860;
    v_14010 = nil;
    goto v_13858;
v_13860:
    goto v_13879;
v_13875:
    v_14010 = stack[-3];
    v_14010 = qcar(v_14010);
    v_14010 = qcar(v_14010);
    v_14011 = qcdr(v_14010);
    goto v_13876;
v_13877:
    v_14010 = stack[-2];
    goto v_13878;
v_13879:
    goto v_13875;
v_13876:
    goto v_13877;
v_13878:
    if (equal(v_14011, v_14010)) goto v_13873;
    else goto v_13874;
v_13873:
    v_14010 = stack[-3];
    v_14010 = qcar(v_14010);
    v_14010 = qcdr(v_14010);
    goto v_13858;
v_13874:
    goto v_13895;
v_13891:
    goto v_13901;
v_13897:
    v_14010 = stack[-3];
    v_14010 = qcar(v_14010);
    v_14010 = qcar(v_14010);
    v_14011 = qcdr(v_14010);
    goto v_13898;
v_13899:
    v_14010 = stack[-2];
    goto v_13900;
v_13901:
    goto v_13897;
v_13898:
    goto v_13899;
v_13900:
    fn = elt(env, 1); // binomial!-coefft!-mod!-p
    v_14011 = (*qfn2(fn))(fn, v_14011, v_14010);
    env = stack[-5];
    goto v_13892;
v_13893:
    v_14010 = stack[-3];
    v_14010 = qcar(v_14010);
    v_14010 = qcdr(v_14010);
    goto v_13894;
v_13895:
    goto v_13891;
v_13892:
    goto v_13893;
v_13894:
    fn = elt(env, 2); // times!-mod!-p
    stack[0] = (*qfn2(fn))(fn, v_14011, v_14010);
    env = stack[-5];
    goto v_13917;
v_13911:
    v_14010 = stack[-3];
    v_14012 = qcdr(v_14010);
    goto v_13912;
v_13913:
    v_14011 = stack[-2];
    goto v_13914;
v_13915:
    v_14010 = stack[-1];
    goto v_13916;
v_13917:
    goto v_13911;
v_13912:
    goto v_13913;
v_13914:
    goto v_13915;
v_13916:
    v_14010 = CC_diffKkKtimesKmodKp(elt(env, 0), 3, v_14012, v_14011, v_14010);
    env = stack[-5];
    stack[-4] = stack[0];
    stack[0] = v_14010;
    v_14010 = stack[-4];
    if (v_14010 == nil) goto v_13926;
    else goto v_13927;
v_13926:
    v_14010 = stack[0];
    goto v_13925;
v_13927:
    goto v_13939;
v_13933:
    goto v_13945;
v_13941:
    goto v_13942;
v_13943:
    goto v_13952;
v_13948:
    v_14010 = stack[-3];
    v_14010 = qcar(v_14010);
    v_14010 = qcar(v_14010);
    v_14011 = qcdr(v_14010);
    goto v_13949;
v_13950:
    v_14010 = stack[-2];
    goto v_13951;
v_13952:
    goto v_13948;
v_13949:
    goto v_13950;
v_13951:
    v_14010 = difference2(v_14011, v_14010);
    env = stack[-5];
    goto v_13944;
v_13945:
    goto v_13941;
v_13942:
    goto v_13943;
v_13944:
    fn = elt(env, 3); // mksp
    v_14012 = (*qfn2(fn))(fn, stack[-1], v_14010);
    goto v_13934;
v_13935:
    v_14011 = stack[-4];
    goto v_13936;
v_13937:
    v_14010 = stack[0];
    goto v_13938;
v_13939:
    goto v_13933;
v_13934:
    goto v_13935;
v_13936:
    goto v_13937;
v_13938:
    return acons(v_14012, v_14011, v_14010);
    v_14010 = nil;
v_13925:
    goto v_13858;
    v_14010 = nil;
v_13858:
    goto v_13830;
v_13846:
    goto v_13969;
v_13963:
    v_14010 = stack[-3];
    v_14010 = qcar(v_14010);
    v_14012 = qcdr(v_14010);
    goto v_13964;
v_13965:
    v_14011 = stack[-2];
    goto v_13966;
v_13967:
    v_14010 = stack[-1];
    goto v_13968;
v_13969:
    goto v_13963;
v_13964:
    goto v_13965;
v_13966:
    goto v_13967;
v_13968:
    stack[0] = CC_diffKkKtimesKmodKp(elt(env, 0), 3, v_14012, v_14011, v_14010);
    env = stack[-5];
    goto v_13982;
v_13976:
    v_14010 = stack[-3];
    v_14012 = qcdr(v_14010);
    goto v_13977;
v_13978:
    v_14011 = stack[-2];
    goto v_13979;
v_13980:
    v_14010 = stack[-1];
    goto v_13981;
v_13982:
    goto v_13976;
v_13977:
    goto v_13978;
v_13979:
    goto v_13980;
v_13981:
    v_14010 = CC_diffKkKtimesKmodKp(elt(env, 0), 3, v_14012, v_14011, v_14010);
    v_14011 = stack[0];
    v_14012 = v_14011;
    if (v_14012 == nil) goto v_13991;
    else goto v_13992;
v_13991:
    goto v_13990;
v_13992:
    goto v_14004;
v_13998:
    v_14012 = stack[-3];
    v_14012 = qcar(v_14012);
    v_14012 = qcar(v_14012);
    goto v_13999;
v_14000:
    goto v_14001;
v_14002:
    goto v_14003;
v_14004:
    goto v_13998;
v_13999:
    goto v_14000;
v_14001:
    goto v_14002;
v_14003:
    return acons(v_14012, v_14011, v_14010);
    v_14010 = nil;
v_13990:
    goto v_13830;
    v_14010 = nil;
v_13830:
    return onevalue(v_14010);
}



// Code for row

static LispObject CC_row(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13842;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_13825;
// end of prologue
    v_13842 = stack[0];
    if (v_13842 == nil) goto v_13833;
    v_13842 = stack[0];
    v_13842 = qcar(v_13842);
    fn = elt(env, 1); // expression
    v_13842 = (*qfn1(fn))(fn, v_13842);
    env = stack[-1];
    v_13842 = stack[0];
    v_13842 = qcdr(v_13842);
    v_13842 = CC_row(elt(env, 0), v_13842);
    goto v_13831;
v_13833:
v_13831:
    v_13842 = nil;
    return onevalue(v_13842);
}



// Code for !:dmpluslst

static LispObject CC_Tdmpluslst(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13852, v_13853;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_13853 = v_13825;
// end of prologue
    v_13852 = v_13853;
    if (v_13852 == nil) goto v_13829;
    else goto v_13830;
v_13829:
    v_13852 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13828;
v_13830:
    v_13852 = v_13853;
    v_13852 = qcdr(v_13852);
    if (v_13852 == nil) goto v_13833;
    else goto v_13834;
v_13833:
    v_13852 = v_13853;
    v_13852 = qcar(v_13852);
    goto v_13828;
v_13834:
    goto v_13846;
v_13842:
    v_13852 = v_13853;
    stack[0] = qcar(v_13852);
    goto v_13843;
v_13844:
    v_13852 = v_13853;
    v_13852 = qcdr(v_13852);
    v_13852 = CC_Tdmpluslst(elt(env, 0), v_13852);
    env = stack[-1];
    goto v_13845;
v_13846:
    goto v_13842;
v_13843:
    goto v_13844;
v_13845:
    {
        LispObject v_13855 = stack[0];
        fn = elt(env, 1); // !:plus
        return (*qfn2(fn))(fn, v_13855, v_13852);
    }
    v_13852 = nil;
v_13828:
    return onevalue(v_13852);
}



// Code for mktails1

static LispObject CC_mktails1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13964, v_13965, v_13966;
    LispObject fn;
    LispObject v_13827, v_13826, v_13825;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mktails1");
    va_start(aa, nargs);
    v_13825 = va_arg(aa, LispObject);
    v_13826 = va_arg(aa, LispObject);
    v_13827 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13827,v_13826,v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13825,v_13826,v_13827);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13827;
    v_13964 = v_13826;
    stack[-1] = v_13825;
// end of prologue
    goto v_13840;
v_13836:
    v_13965 = stack[-1];
    goto v_13837;
v_13838:
    goto v_13839;
v_13840:
    goto v_13836;
v_13837:
    goto v_13838;
v_13839:
    fn = elt(env, 3); // getroad
    v_13964 = (*qfn2(fn))(fn, v_13965, v_13964);
    env = stack[-3];
    v_13965 = v_13964;
    goto v_13851;
v_13847:
    v_13966 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13848;
v_13849:
    v_13964 = v_13965;
    goto v_13850;
v_13851:
    goto v_13847;
v_13848:
    goto v_13849;
v_13850:
    if (v_13966 == v_13964) goto v_13845;
    else goto v_13846;
v_13845:
    goto v_13859;
v_13855:
    v_13965 = nil;
    goto v_13856;
v_13857:
    v_13964 = stack[0];
    goto v_13858;
v_13859:
    goto v_13855;
v_13856:
    goto v_13857;
v_13858:
    return cons(v_13965, v_13964);
v_13846:
    goto v_13870;
v_13866:
    v_13966 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13867;
v_13868:
    v_13964 = stack[-1];
    v_13964 = qcdr(v_13964);
    goto v_13869;
v_13870:
    goto v_13866;
v_13867:
    goto v_13868;
v_13869:
    if (v_13966 == v_13964) goto v_13864;
    else goto v_13865;
v_13864:
    goto v_13879;
v_13875:
    goto v_13889;
v_13885:
    v_13964 = stack[-1];
    v_13965 = qcar(v_13964);
    goto v_13886;
v_13887:
    v_13964 = elt(env, 2); // replace_by_vector
    goto v_13888;
v_13889:
    goto v_13885;
v_13886:
    goto v_13887;
v_13888:
    v_13964 = get(v_13965, v_13964);
    env = stack[-3];
    if (v_13964 == nil) goto v_13883;
    else goto v_13882;
v_13883:
    v_13964 = stack[-1];
    v_13964 = qcar(v_13964);
v_13882:
    v_13965 = ncons(v_13964);
    goto v_13876;
v_13877:
    v_13964 = stack[0];
    goto v_13878;
v_13879:
    goto v_13875;
v_13876:
    goto v_13877;
v_13878:
    return cons(v_13965, v_13964);
v_13865:
    goto v_13900;
v_13896:
    v_13966 = stack[-1];
    goto v_13897;
v_13898:
    v_13964 = stack[0];
    goto v_13899;
v_13900:
    goto v_13896;
v_13897:
    goto v_13898;
v_13899:
    v_13964 = Lassoc(nil, v_13966, v_13964);
    v_13966 = v_13964;
    v_13964 = v_13966;
    if (v_13964 == nil) goto v_13907;
    v_13964 = v_13966;
    v_13964 = qcdr(v_13964);
    v_13964 = qcdr(v_13964);
    if (v_13964 == nil) goto v_13911;
    else goto v_13912;
v_13911:
    goto v_13921;
v_13917:
    v_13964 = v_13966;
    v_13965 = qcdr(v_13964);
    goto v_13918;
v_13919:
    v_13964 = stack[0];
    goto v_13920;
v_13921:
    goto v_13917;
v_13918:
    goto v_13919;
v_13920:
    return cons(v_13965, v_13964);
v_13912:
    goto v_13932;
v_13928:
    v_13964 = v_13966;
    v_13964 = qcdr(v_13964);
    v_13965 = Lreverse(nil, v_13964);
    goto v_13929;
v_13930:
    v_13964 = stack[0];
    goto v_13931;
v_13932:
    goto v_13928;
v_13929:
    goto v_13930;
v_13931:
    return cons(v_13965, v_13964);
    v_13964 = nil;
    goto v_13833;
v_13907:
    v_13964 = stack[-1];
    goto v_13943;
v_13939:
    goto v_13940;
v_13941:
    goto v_13942;
v_13943:
    goto v_13939;
v_13940:
    goto v_13941;
v_13942:
    fn = elt(env, 4); // mkinds
    v_13964 = (*qfn2(fn))(fn, v_13964, v_13965);
    env = stack[-3];
    v_13966 = v_13964;
    goto v_13953;
v_13947:
    stack[-2] = v_13966;
    goto v_13948;
v_13949:
    goto v_13960;
v_13956:
    v_13964 = stack[-1];
    goto v_13957;
v_13958:
    v_13965 = v_13966;
    goto v_13959;
v_13960:
    goto v_13956;
v_13957:
    goto v_13958;
v_13959:
    v_13965 = cons(v_13964, v_13965);
    goto v_13950;
v_13951:
    v_13964 = stack[0];
    goto v_13952;
v_13953:
    goto v_13947;
v_13948:
    goto v_13949;
v_13950:
    goto v_13951;
v_13952:
    {
        LispObject v_13970 = stack[-2];
        return list2star(v_13970, v_13965, v_13964);
    }
v_13833:
    return onevalue(v_13964);
}



// Code for cde_position

static LispObject CC_cde_position(LispObject env,
                         LispObject v_13825, LispObject v_13826)
{
    env = qenv(env);
    LispObject v_13851, v_13852, v_13853, v_13854;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13853 = v_13826;
    v_13854 = v_13825;
// end of prologue
    goto v_13836;
v_13832:
    v_13852 = v_13854;
    goto v_13833;
v_13834:
    v_13851 = v_13853;
    goto v_13835;
v_13836:
    goto v_13832;
v_13833:
    goto v_13834;
v_13835:
    v_13851 = Lmember(nil, v_13852, v_13851);
    if (v_13851 == nil) goto v_13831;
    goto v_13845;
v_13841:
    v_13851 = v_13854;
    goto v_13842;
v_13843:
    v_13852 = v_13853;
    goto v_13844;
v_13845:
    goto v_13841;
v_13842:
    goto v_13843;
v_13844:
    {
        fn = elt(env, 1); // cde_position2
        return (*qfn2(fn))(fn, v_13851, v_13852);
    }
v_13831:
    v_13851 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13829;
    v_13851 = nil;
v_13829:
    return onevalue(v_13851);
}



// Code for riv_mk

static LispObject CC_riv_mk(LispObject env,
                         LispObject v_13825, LispObject v_13826)
{
    env = qenv(env);
    LispObject v_13839, v_13840, v_13841;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13839 = v_13826;
    v_13840 = v_13825;
// end of prologue
    goto v_13835;
v_13829:
    v_13841 = elt(env, 1); // iv
    goto v_13830;
v_13831:
    goto v_13832;
v_13833:
    goto v_13834;
v_13835:
    goto v_13829;
v_13830:
    goto v_13831;
v_13832:
    goto v_13833;
v_13834:
    return list3(v_13841, v_13840, v_13839);
}



// Code for lalr_prin_production

static LispObject CC_lalr_prin_production(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13835;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_13825;
// end of prologue
    v_13835 = stack[0];
    v_13835 = qcar(v_13835);
    fn = elt(env, 2); // lalr_prin_symbol
    v_13835 = (*qfn1(fn))(fn, v_13835);
    env = stack[-1];
    v_13835 = elt(env, 1); // " -> "
    v_13835 = Lprinc(nil, v_13835);
    env = stack[-1];
    v_13835 = stack[0];
    v_13835 = qcdr(v_13835);
    {
        fn = elt(env, 3); // lalr_prin_rhs
        return (*qfn1(fn))(fn, v_13835);
    }
}



// Code for rlis

static LispObject CC_rlis(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13877, v_13878;
    LispObject fn;
    argcheck(nargs, 0, "rlis");
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
    v_13877 = qvalue(elt(env, 2)); // cursym!*
    stack[0] = v_13877;
    fn = elt(env, 6); // scan
    v_13877 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (!symbolp(v_13877)) v_13877 = nil;
    else { v_13877 = qfastgets(v_13877);
           if (v_13877 != nil) { v_13877 = elt(v_13877, 55); // delim
#ifdef RECORD_GET
             if (v_13877 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v_13877 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v_13877 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v_13877 == SPID_NOPROP) v_13877 = nil; else v_13877 = lisp_true; }}
#endif
    if (v_13877 == nil) goto v_13834;
    goto v_13842;
v_13838:
    v_13878 = stack[0];
    goto v_13839;
v_13840:
    v_13877 = nil;
    goto v_13841;
v_13842:
    goto v_13838;
v_13839:
    goto v_13840;
v_13841:
    return list2(v_13878, v_13877);
v_13834:
    v_13877 = qvalue(elt(env, 3)); // !*reduce4
    if (v_13877 == nil) goto v_13846;
    goto v_13853;
v_13849:
    stack[-1] = stack[0];
    goto v_13850;
v_13851:
    goto v_13860;
v_13856:
    stack[0] = elt(env, 4); // list
    goto v_13857;
v_13858:
    v_13877 = elt(env, 5); // lambda
    fn = elt(env, 7); // xread1
    v_13877 = (*qfn1(fn))(fn, v_13877);
    env = stack[-2];
    fn = elt(env, 8); // remcomma
    v_13877 = (*qfn1(fn))(fn, v_13877);
    env = stack[-2];
    goto v_13859;
v_13860:
    goto v_13856;
v_13857:
    goto v_13858;
v_13859:
    v_13877 = cons(stack[0], v_13877);
    goto v_13852;
v_13853:
    goto v_13849;
v_13850:
    goto v_13851;
v_13852:
    {
        LispObject v_13881 = stack[-1];
        return list2(v_13881, v_13877);
    }
v_13846:
    goto v_13872;
v_13868:
    goto v_13869;
v_13870:
    v_13877 = elt(env, 5); // lambda
    fn = elt(env, 7); // xread1
    v_13877 = (*qfn1(fn))(fn, v_13877);
    env = stack[-2];
    fn = elt(env, 8); // remcomma
    v_13877 = (*qfn1(fn))(fn, v_13877);
    goto v_13871;
v_13872:
    goto v_13868;
v_13869:
    goto v_13870;
v_13871:
    {
        LispObject v_13882 = stack[0];
        return cons(v_13882, v_13877);
    }
    v_13877 = nil;
    return onevalue(v_13877);
}



// Code for tripleisprolongedby

static LispObject CC_tripleisprolongedby(LispObject env,
                         LispObject v_13825, LispObject v_13826)
{
    env = qenv(env);
    LispObject v_13886, v_13887;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13826,v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13825,v_13826);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13826;
    v_13886 = v_13825;
// end of prologue
    goto v_13836;
v_13832:
    v_13887 = v_13886;
    goto v_13833;
v_13834:
    v_13886 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_13835;
v_13836:
    goto v_13832;
v_13833:
    goto v_13834;
v_13835:
    v_13886 = *(LispObject *)((char *)v_13887 + (CELL-TAG_VECTOR) + (((intptr_t)v_13886-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_13886;
v_13842:
    v_13886 = stack[-1];
    v_13886 = qcar(v_13886);
    if (v_13886 == nil) goto v_13845;
    goto v_13856;
v_13852:
    v_13886 = stack[-1];
    v_13887 = qcar(v_13886);
    goto v_13853;
v_13854:
    v_13886 = stack[0];
    goto v_13855;
v_13856:
    goto v_13852;
v_13853:
    goto v_13854;
v_13855:
    v_13886 = (LispObject)greaterp2(v_13887, v_13886);
    v_13886 = v_13886 ? lisp_true : nil;
    env = stack[-2];
    if (v_13886 == nil) goto v_13845;
    goto v_13846;
v_13845:
    goto v_13841;
v_13846:
    v_13886 = stack[-1];
    v_13886 = qcdr(v_13886);
    stack[-1] = v_13886;
    goto v_13842;
v_13841:
    v_13886 = stack[-1];
    v_13886 = qcar(v_13886);
    if (v_13886 == nil) goto v_13867;
    goto v_13876;
v_13872:
    v_13886 = stack[-1];
    v_13887 = qcar(v_13886);
    goto v_13873;
v_13874:
    v_13886 = stack[0];
    goto v_13875;
v_13876:
    goto v_13872;
v_13873:
    goto v_13874;
v_13875:
    if (equal(v_13887, v_13886)) goto v_13871;
    else goto v_13867;
v_13871:
    v_13886 = lisp_true;
    goto v_13830;
v_13867:
    v_13886 = nil;
    goto v_13830;
    v_13886 = nil;
v_13830:
    return onevalue(v_13886);
}



// Code for ofsf_smupdknowl

static LispObject CC_ofsf_smupdknowl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13929, v_13930, v_13931;
    LispObject fn;
    LispObject v_13828, v_13827, v_13826, v_13825;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ofsf_smupdknowl");
    va_start(aa, nargs);
    v_13825 = va_arg(aa, LispObject);
    v_13826 = va_arg(aa, LispObject);
    v_13827 = va_arg(aa, LispObject);
    v_13828 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_13828,v_13827,v_13826,v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_13825,v_13826,v_13827,v_13828);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_13828;
    stack[-2] = v_13827;
    stack[-3] = v_13826;
    stack[-4] = v_13825;
// end of prologue
v_13838:
    v_13929 = stack[-3];
    if (v_13929 == nil) goto v_13841;
    else goto v_13842;
v_13841:
    goto v_13837;
v_13842:
    goto v_13853;
v_13849:
    v_13930 = stack[-4];
    goto v_13850;
v_13851:
    v_13929 = elt(env, 2); // and
    goto v_13852;
v_13853:
    goto v_13849;
v_13850:
    goto v_13851;
v_13852:
    if (v_13930 == v_13929) goto v_13847;
    else goto v_13848;
v_13847:
    v_13929 = stack[-3];
    v_13929 = qcar(v_13929);
    goto v_13846;
v_13848:
    v_13929 = stack[-3];
    v_13929 = qcar(v_13929);
    fn = elt(env, 4); // ofsf_negateat
    v_13929 = (*qfn1(fn))(fn, v_13929);
    env = stack[-6];
    goto v_13846;
    v_13929 = nil;
v_13846:
    v_13930 = v_13929;
    v_13929 = stack[-3];
    v_13929 = qcdr(v_13929);
    stack[-3] = v_13929;
    goto v_13870;
v_13866:
    goto v_13867;
v_13868:
    v_13929 = stack[-1];
    goto v_13869;
v_13870:
    goto v_13866;
v_13867:
    goto v_13868;
v_13869:
    fn = elt(env, 5); // ofsf_at2ir
    v_13929 = (*qfn2(fn))(fn, v_13930, v_13929);
    env = stack[-6];
    v_13931 = v_13929;
    goto v_13881;
v_13877:
    v_13929 = v_13931;
    v_13930 = qcar(v_13929);
    goto v_13878;
v_13879:
    v_13929 = stack[-2];
    goto v_13880;
v_13881:
    goto v_13877;
v_13878:
    goto v_13879;
v_13880:
    v_13929 = Lassoc(nil, v_13930, v_13929);
    stack[-5] = v_13929;
    if (v_13929 == nil) goto v_13876;
    goto v_13891;
v_13887:
    stack[0] = stack[-5];
    goto v_13888;
v_13889:
    goto v_13898;
v_13894:
    v_13929 = v_13931;
    v_13929 = qcdr(v_13929);
    v_13930 = qcar(v_13929);
    goto v_13895;
v_13896:
    v_13929 = stack[-5];
    v_13929 = qcdr(v_13929);
    goto v_13897;
v_13898:
    goto v_13894;
v_13895:
    goto v_13896;
v_13897:
    fn = elt(env, 6); // ofsf_sminsert
    v_13929 = (*qfn2(fn))(fn, v_13930, v_13929);
    env = stack[-6];
    goto v_13890;
v_13891:
    goto v_13887;
v_13888:
    goto v_13889;
v_13890:
    fn = elt(env, 7); // setcdr
    v_13929 = (*qfn2(fn))(fn, stack[0], v_13929);
    env = stack[-6];
    goto v_13912;
v_13908:
    v_13929 = stack[-5];
    v_13930 = qcdr(v_13929);
    goto v_13909;
v_13910:
    v_13929 = elt(env, 3); // false
    goto v_13911;
v_13912:
    goto v_13908;
v_13909:
    goto v_13910;
v_13911:
    if (v_13930 == v_13929) goto v_13906;
    else goto v_13907;
v_13906:
    v_13929 = nil;
    stack[-3] = v_13929;
    v_13929 = elt(env, 3); // false
    stack[-2] = v_13929;
    goto v_13905;
v_13907:
v_13905:
    goto v_13874;
v_13876:
    goto v_13925;
v_13921:
    v_13930 = v_13931;
    goto v_13922;
v_13923:
    v_13929 = stack[-2];
    goto v_13924;
v_13925:
    goto v_13921;
v_13922:
    goto v_13923;
v_13924:
    v_13929 = cons(v_13930, v_13929);
    env = stack[-6];
    stack[-2] = v_13929;
    goto v_13874;
v_13874:
    goto v_13838;
v_13837:
    v_13929 = stack[-2];
    return onevalue(v_13929);
}



// Code for evaluatecoeffts

static LispObject CC_evaluatecoeffts(LispObject env,
                         LispObject v_13825, LispObject v_13826)
{
    env = qenv(env);
    LispObject v_13947, v_13948, v_13949;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13826,v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13825,v_13826);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13826;
    stack[-1] = v_13825;
// end of prologue
    v_13947 = stack[-1];
    if (v_13947 == nil) goto v_13834;
    else goto v_13835;
v_13834:
    v_13947 = lisp_true;
    goto v_13833;
v_13835:
    v_13947 = stack[-1];
    if (!consp(v_13947)) goto v_13842;
    else goto v_13843;
v_13842:
    v_13947 = lisp_true;
    goto v_13841;
v_13843:
    v_13947 = stack[-1];
    v_13947 = qcar(v_13947);
    v_13947 = (consp(v_13947) ? nil : lisp_true);
    goto v_13841;
    v_13947 = nil;
v_13841:
    goto v_13833;
    v_13947 = nil;
v_13833:
    if (v_13947 == nil) goto v_13831;
    goto v_13859;
v_13855:
    v_13948 = stack[-1];
    goto v_13856;
v_13857:
    v_13947 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13858;
v_13859:
    goto v_13855;
v_13856:
    goto v_13857;
v_13858:
    if (v_13948 == v_13947) goto v_13853;
    else goto v_13854;
v_13853:
    v_13947 = nil;
    goto v_13852;
v_13854:
    v_13947 = stack[-1];
    goto v_13852;
    v_13947 = nil;
v_13852:
    goto v_13829;
v_13831:
    goto v_13880;
v_13876:
    v_13947 = stack[-1];
    v_13947 = qcar(v_13947);
    v_13947 = qcar(v_13947);
    v_13948 = qcar(v_13947);
    goto v_13877;
v_13878:
    v_13947 = qvalue(elt(env, 2)); // indexlist
    goto v_13879;
v_13880:
    goto v_13876;
v_13877:
    goto v_13878;
v_13879:
    v_13947 = Lmember(nil, v_13948, v_13947);
    if (v_13947 == nil) goto v_13875;
    goto v_13894;
v_13888:
    v_13947 = stack[-1];
    v_13947 = qcar(v_13947);
    v_13947 = qcar(v_13947);
    v_13949 = qcar(v_13947);
    goto v_13889;
v_13890:
    v_13948 = stack[0];
    goto v_13891;
v_13892:
    v_13947 = qvalue(elt(env, 2)); // indexlist
    goto v_13893;
v_13894:
    goto v_13888;
v_13889:
    goto v_13890;
v_13891:
    goto v_13892;
v_13893:
    fn = elt(env, 3); // valuecoefft
    v_13947 = (*qfnn(fn))(fn, 3, v_13949, v_13948, v_13947);
    env = stack[-3];
    goto v_13873;
v_13875:
    goto v_13909;
v_13905:
    v_13947 = stack[-1];
    v_13947 = qcar(v_13947);
    v_13948 = qcar(v_13947);
    goto v_13906;
v_13907:
    v_13947 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13908;
v_13909:
    goto v_13905;
v_13906:
    goto v_13907;
v_13908:
    v_13947 = cons(v_13948, v_13947);
    env = stack[-3];
    v_13947 = ncons(v_13947);
    env = stack[-3];
    goto v_13873;
v_13873:
    goto v_13919;
v_13915:
    stack[-2] = v_13947;
    goto v_13916;
v_13917:
    goto v_13926;
v_13922:
    v_13947 = stack[-1];
    v_13947 = qcar(v_13947);
    v_13948 = qcdr(v_13947);
    goto v_13923;
v_13924:
    v_13947 = stack[0];
    goto v_13925;
v_13926:
    goto v_13922;
v_13923:
    goto v_13924;
v_13925:
    v_13947 = CC_evaluatecoeffts(elt(env, 0), v_13948, v_13947);
    env = stack[-3];
    goto v_13918;
v_13919:
    goto v_13915;
v_13916:
    goto v_13917;
v_13918:
    fn = elt(env, 4); // !*multf
    v_13947 = (*qfn2(fn))(fn, stack[-2], v_13947);
    env = stack[-3];
    goto v_13936;
v_13932:
    stack[-2] = v_13947;
    goto v_13933;
v_13934:
    goto v_13943;
v_13939:
    v_13947 = stack[-1];
    v_13948 = qcdr(v_13947);
    goto v_13940;
v_13941:
    v_13947 = stack[0];
    goto v_13942;
v_13943:
    goto v_13939;
v_13940:
    goto v_13941;
v_13942:
    v_13947 = CC_evaluatecoeffts(elt(env, 0), v_13948, v_13947);
    env = stack[-3];
    goto v_13935;
v_13936:
    goto v_13932;
v_13933:
    goto v_13934;
v_13935:
    {
        LispObject v_13953 = stack[-2];
        fn = elt(env, 5); // addf
        return (*qfn2(fn))(fn, v_13953, v_13947);
    }
    goto v_13829;
    v_13947 = nil;
v_13829:
    return onevalue(v_13947);
}



// Code for cl_smsimpl!-junct1

static LispObject CC_cl_smsimplKjunct1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_14244, v_14245, v_14246, v_14247, v_14248, v_14249;
    LispObject fn;
    LispObject v_13831, v_13830, v_13829, v_13828, v_13827, v_13826, v_13825;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 7, "cl_smsimpl-junct1");
    va_start(aa, nargs);
    v_13825 = va_arg(aa, LispObject);
    v_13826 = va_arg(aa, LispObject);
    v_13827 = va_arg(aa, LispObject);
    v_13828 = va_arg(aa, LispObject);
    v_13829 = va_arg(aa, LispObject);
    v_13830 = va_arg(aa, LispObject);
    v_13831 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_13831,v_13830,v_13829,v_13828,v_13827,v_13826);
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_13825,v_13826,v_13827,v_13828,v_13829,v_13830);
        pop(v_13831);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-3] = v_13831;
    stack[-4] = v_13830;
    stack[-5] = v_13829;
    stack[-6] = v_13828;
    stack[-7] = v_13827;
    v_14244 = v_13826;
    stack[-8] = v_13825;
// end of prologue
    stack[-9] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
v_13844:
    v_14244 = stack[-7];
    if (v_14244 == nil) goto v_13847;
    else goto v_13848;
v_13847:
    goto v_13843;
v_13848:
    v_14244 = stack[-7];
    v_14244 = qcar(v_14244);
    v_14245 = v_14244;
    v_14244 = stack[-7];
    v_14244 = qcdr(v_14244);
    stack[-7] = v_14244;
    v_14244 = v_14245;
    stack[-9] = v_14244;
    goto v_13869;
v_13861:
    stack[-10] = stack[-9];
    goto v_13862;
v_13863:
    stack[0] = stack[-5];
    goto v_13864;
v_13865:
    v_14244 = stack[-4];
    v_14245 = sub1(v_14244);
    env = stack[-11];
    goto v_13866;
v_13867:
    v_14244 = stack[-8];
    goto v_13868;
v_13869:
    goto v_13861;
v_13862:
    goto v_13863;
v_13864:
    goto v_13865;
v_13866:
    goto v_13867;
v_13868:
    fn = elt(env, 15); // cl_simpl1
    v_14244 = (*qfnn(fn))(fn, 4, stack[-10], stack[0], v_14245, v_14244);
    env = stack[-11];
    stack[-10] = v_14244;
    v_14244 = stack[-10];
    if (!consp(v_14244)) goto v_13877;
    else goto v_13878;
v_13877:
    v_14244 = stack[-10];
    goto v_13876;
v_13878:
    v_14244 = stack[-10];
    v_14244 = qcar(v_14244);
    goto v_13876;
    v_14244 = nil;
v_13876:
    v_14246 = v_14244;
    goto v_13893;
v_13889:
    v_14245 = v_14246;
    goto v_13890;
v_13891:
    v_14244 = stack[-3];
    goto v_13892;
v_13893:
    goto v_13889;
v_13890:
    goto v_13891;
v_13892:
    if (v_14245 == v_14244) goto v_13887;
    else goto v_13888;
v_13887:
    v_14244 = stack[-3];
    stack[-9] = v_14244;
    v_14244 = nil;
    stack[-7] = v_14244;
    goto v_13886;
v_13888:
    goto v_13904;
v_13900:
    v_14245 = v_14246;
    goto v_13901;
v_13902:
    v_14244 = stack[-8];
    goto v_13903;
v_13904:
    goto v_13900;
v_13901:
    goto v_13902;
v_13903:
    if (v_14245 == v_14244) goto v_13898;
    else goto v_13899;
v_13898:
    v_14244 = stack[-10];
    v_14244 = qcdr(v_14244);
    stack[0] = v_14244;
v_13911:
    v_14244 = stack[0];
    if (v_14244 == nil) goto v_13914;
    v_14244 = stack[0];
    v_14244 = qcar(v_14244);
    fn = elt(env, 16); // cl_atfp
    v_14244 = (*qfn1(fn))(fn, v_14244);
    env = stack[-11];
    if (v_14244 == nil) goto v_13914;
    goto v_13915;
v_13914:
    goto v_13910;
v_13915:
    goto v_13928;
v_13924:
    v_14244 = stack[0];
    v_14245 = qcar(v_14244);
    goto v_13925;
v_13926:
    v_14244 = stack[-1];
    goto v_13927;
v_13928:
    goto v_13924;
v_13925:
    goto v_13926;
v_13927:
    v_14244 = cons(v_14245, v_14244);
    env = stack[-11];
    stack[-1] = v_14244;
    v_14244 = stack[0];
    v_14244 = qcdr(v_14244);
    stack[0] = v_14244;
    goto v_13911;
v_13910:
    v_14244 = qvalue(elt(env, 2)); // !*rlsiidem
    if (v_14244 == nil) goto v_13937;
    v_14244 = stack[-1];
    if (v_14244 == nil) goto v_13937;
    goto v_13947;
v_13943:
    v_14244 = stack[-2];
    v_14245 = Lnreverse(nil, v_14244);
    env = stack[-11];
    goto v_13944;
v_13945:
    v_14244 = stack[-7];
    goto v_13946;
v_13947:
    goto v_13943;
v_13944:
    goto v_13945;
v_13946:
    v_14244 = Lnconc(nil, v_14245, v_14244);
    env = stack[-11];
    stack[-7] = v_14244;
    v_14244 = nil;
    stack[-2] = v_14244;
    goto v_13935;
v_13937:
v_13935:
    goto v_13957;
v_13953:
    goto v_13954;
v_13955:
    v_14244 = stack[0];
    v_14244 = Lreverse(nil, v_14244);
    env = stack[-11];
    goto v_13956;
v_13957:
    goto v_13953;
v_13954:
    goto v_13955;
v_13956:
    v_14244 = Lnconc(nil, stack[-2], v_14244);
    env = stack[-11];
    stack[-2] = v_14244;
    goto v_13886;
v_13899:
    goto v_13975;
v_13971:
    v_14245 = v_14246;
    goto v_13972;
v_13973:
    v_14244 = elt(env, 3); // true
    goto v_13974;
v_13975:
    goto v_13971;
v_13972:
    goto v_13973;
v_13974:
    if (v_14245 == v_14244) goto v_13969;
    else goto v_13970;
v_13969:
    v_14244 = lisp_true;
    goto v_13968;
v_13970:
    goto v_13985;
v_13981:
    v_14245 = v_14246;
    goto v_13982;
v_13983:
    v_14244 = elt(env, 4); // false
    goto v_13984;
v_13985:
    goto v_13981;
v_13982:
    goto v_13983;
v_13984:
    v_14244 = (v_14245 == v_14244 ? lisp_true : nil);
    goto v_13968;
    v_14244 = nil;
v_13968:
    if (v_14244 == nil) goto v_13966;
    v_14244 = lisp_true;
    goto v_13964;
v_13966:
    goto v_14012;
v_14008:
    v_14245 = v_14246;
    goto v_14009;
v_14010:
    v_14244 = elt(env, 5); // or
    goto v_14011;
v_14012:
    goto v_14008;
v_14009:
    goto v_14010;
v_14011:
    if (v_14245 == v_14244) goto v_14006;
    else goto v_14007;
v_14006:
    v_14244 = lisp_true;
    goto v_14005;
v_14007:
    goto v_14022;
v_14018:
    v_14245 = v_14246;
    goto v_14019;
v_14020:
    v_14244 = elt(env, 6); // and
    goto v_14021;
v_14022:
    goto v_14018;
v_14019:
    goto v_14020;
v_14021:
    v_14244 = (v_14245 == v_14244 ? lisp_true : nil);
    goto v_14005;
    v_14244 = nil;
v_14005:
    if (v_14244 == nil) goto v_14003;
    v_14244 = lisp_true;
    goto v_14001;
v_14003:
    goto v_14033;
v_14029:
    v_14245 = v_14246;
    goto v_14030;
v_14031:
    v_14244 = elt(env, 7); // not
    goto v_14032;
v_14033:
    goto v_14029;
v_14030:
    goto v_14031;
v_14032:
    v_14244 = (v_14245 == v_14244 ? lisp_true : nil);
    goto v_14001;
    v_14244 = nil;
v_14001:
    if (v_14244 == nil) goto v_13999;
    v_14244 = lisp_true;
    goto v_13997;
v_13999:
    goto v_14048;
v_14044:
    v_14245 = v_14246;
    goto v_14045;
v_14046:
    v_14244 = elt(env, 8); // impl
    goto v_14047;
v_14048:
    goto v_14044;
v_14045:
    goto v_14046;
v_14047:
    if (v_14245 == v_14244) goto v_14042;
    else goto v_14043;
v_14042:
    v_14244 = lisp_true;
    goto v_14041;
v_14043:
    goto v_14062;
v_14058:
    v_14245 = v_14246;
    goto v_14059;
v_14060:
    v_14244 = elt(env, 9); // repl
    goto v_14061;
v_14062:
    goto v_14058;
v_14059:
    goto v_14060;
v_14061:
    if (v_14245 == v_14244) goto v_14056;
    else goto v_14057;
v_14056:
    v_14244 = lisp_true;
    goto v_14055;
v_14057:
    goto v_14072;
v_14068:
    v_14245 = v_14246;
    goto v_14069;
v_14070:
    v_14244 = elt(env, 10); // equiv
    goto v_14071;
v_14072:
    goto v_14068;
v_14069:
    goto v_14070;
v_14071:
    v_14244 = (v_14245 == v_14244 ? lisp_true : nil);
    goto v_14055;
    v_14244 = nil;
v_14055:
    goto v_14041;
    v_14244 = nil;
v_14041:
    goto v_13997;
    v_14244 = nil;
v_13997:
    if (v_14244 == nil) goto v_13995;
    v_14244 = lisp_true;
    goto v_13993;
v_13995:
    goto v_14091;
v_14087:
    v_14245 = v_14246;
    goto v_14088;
v_14089:
    v_14244 = elt(env, 11); // ex
    goto v_14090;
v_14091:
    goto v_14087;
v_14088:
    goto v_14089;
v_14090:
    if (v_14245 == v_14244) goto v_14085;
    else goto v_14086;
v_14085:
    v_14244 = lisp_true;
    goto v_14084;
v_14086:
    goto v_14101;
v_14097:
    v_14245 = v_14246;
    goto v_14098;
v_14099:
    v_14244 = elt(env, 12); // all
    goto v_14100;
v_14101:
    goto v_14097;
v_14098:
    goto v_14099;
v_14100:
    v_14244 = (v_14245 == v_14244 ? lisp_true : nil);
    goto v_14084;
    v_14244 = nil;
v_14084:
    if (v_14244 == nil) goto v_14082;
    v_14244 = lisp_true;
    goto v_14080;
v_14082:
    goto v_14120;
v_14116:
    v_14245 = v_14246;
    goto v_14117;
v_14118:
    v_14244 = elt(env, 13); // bex
    goto v_14119;
v_14120:
    goto v_14116;
v_14117:
    goto v_14118;
v_14119:
    if (v_14245 == v_14244) goto v_14114;
    else goto v_14115;
v_14114:
    v_14244 = lisp_true;
    goto v_14113;
v_14115:
    goto v_14130;
v_14126:
    v_14245 = v_14246;
    goto v_14127;
v_14128:
    v_14244 = elt(env, 14); // ball
    goto v_14129;
v_14130:
    goto v_14126;
v_14127:
    goto v_14128;
v_14129:
    v_14244 = (v_14245 == v_14244 ? lisp_true : nil);
    goto v_14113;
    v_14244 = nil;
v_14113:
    if (v_14244 == nil) goto v_14111;
    v_14244 = lisp_true;
    goto v_14109;
v_14111:
    v_14244 = v_14246;
    if (!symbolp(v_14244)) v_14244 = nil;
    else { v_14244 = qfastgets(v_14244);
           if (v_14244 != nil) { v_14244 = elt(v_14244, 21); // rl_external
#ifdef RECORD_GET
             if (v_14244 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_14244 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_14244 == SPID_NOPROP) v_14244 = nil; }}
#endif
    goto v_14109;
    v_14244 = nil;
v_14109:
    goto v_14080;
    v_14244 = nil;
v_14080:
    goto v_13993;
    v_14244 = nil;
v_13993:
    goto v_13964;
    v_14244 = nil;
v_13964:
    if (v_14244 == nil) goto v_13962;
    goto v_14147;
v_14143:
    stack[0] = v_14246;
    goto v_14144;
v_14145:
    v_14244 = stack[-3];
    fn = elt(env, 17); // cl_flip
    v_14244 = (*qfn1(fn))(fn, v_14244);
    env = stack[-11];
    goto v_14146;
v_14147:
    goto v_14143;
v_14144:
    goto v_14145;
v_14146:
    if (equal(stack[0], v_14244)) goto v_14142;
    goto v_14156;
v_14152:
    v_14245 = stack[-10];
    goto v_14153;
v_14154:
    v_14244 = stack[-2];
    goto v_14155;
v_14156:
    goto v_14152;
v_14153:
    goto v_14154;
v_14155:
    v_14244 = cons(v_14245, v_14244);
    env = stack[-11];
    stack[-2] = v_14244;
    goto v_14140;
v_14142:
v_14140:
    goto v_13886;
v_13962:
    v_14244 = qvalue(elt(env, 2)); // !*rlsiidem
    if (v_14244 == nil) goto v_14164;
    goto v_14171;
v_14167:
    v_14244 = stack[-2];
    v_14245 = Lnreverse(nil, v_14244);
    env = stack[-11];
    goto v_14168;
v_14169:
    v_14244 = stack[-7];
    goto v_14170;
v_14171:
    goto v_14167;
v_14168:
    goto v_14169;
v_14170:
    v_14244 = Lnconc(nil, v_14245, v_14244);
    env = stack[-11];
    stack[-7] = v_14244;
    v_14244 = nil;
    stack[-2] = v_14244;
    goto v_14162;
v_14164:
v_14162:
    v_14244 = stack[-10];
    v_14244 = ncons(v_14244);
    env = stack[-11];
    stack[-1] = v_14244;
    goto v_13886;
v_13886:
    v_14244 = stack[-1];
    if (v_14244 == nil) goto v_14181;
    goto v_14192;
v_14184:
    v_14247 = stack[-8];
    goto v_14185;
v_14186:
    v_14246 = stack[-1];
    goto v_14187;
v_14188:
    v_14245 = stack[-5];
    goto v_14189;
v_14190:
    v_14244 = stack[-4];
    goto v_14191;
v_14192:
    goto v_14184;
v_14185:
    goto v_14186;
v_14187:
    goto v_14188;
v_14189:
    goto v_14190;
v_14191:
    fn = elt(env, 18); // rl_smupdknowl
    v_14244 = (*qfnn(fn))(fn, 4, v_14247, v_14246, v_14245, v_14244);
    env = stack[-11];
    stack[-5] = v_14244;
    goto v_14205;
v_14201:
    v_14245 = stack[-5];
    goto v_14202;
v_14203:
    v_14244 = elt(env, 4); // false
    goto v_14204;
v_14205:
    goto v_14201;
v_14202:
    goto v_14203;
v_14204:
    if (v_14245 == v_14244) goto v_14199;
    else goto v_14200;
v_14199:
    v_14244 = stack[-3];
    stack[-9] = v_14244;
    v_14244 = nil;
    stack[-7] = v_14244;
    goto v_14198;
v_14200:
v_14198:
    v_14244 = nil;
    stack[-1] = v_14244;
    goto v_14179;
v_14181:
v_14179:
    goto v_13844;
v_13843:
    goto v_14219;
v_14215:
    v_14245 = stack[-9];
    goto v_14216;
v_14217:
    v_14244 = stack[-3];
    goto v_14218;
v_14219:
    goto v_14215;
v_14216:
    goto v_14217;
v_14218:
    if (v_14245 == v_14244) goto v_14213;
    else goto v_14214;
v_14213:
    v_14244 = stack[-3];
    return ncons(v_14244);
v_14214:
    goto v_14237;
v_14225:
    v_14249 = stack[-8];
    goto v_14226;
v_14227:
    v_14248 = stack[-2];
    goto v_14228;
v_14229:
    v_14247 = stack[-6];
    goto v_14230;
v_14231:
    v_14246 = stack[-5];
    goto v_14232;
v_14233:
    v_14245 = stack[-4];
    goto v_14234;
v_14235:
    v_14244 = stack[-3];
    goto v_14236;
v_14237:
    goto v_14225;
v_14226:
    goto v_14227;
v_14228:
    goto v_14229;
v_14230:
    goto v_14231;
v_14232:
    goto v_14233;
v_14234:
    goto v_14235;
v_14236:
    {
        fn = elt(env, 19); // cl_smsimpl!-junct2
        return (*qfnn(fn))(fn, 6, v_14249, v_14248, v_14247, v_14246, v_14245, v_14244);
    }
    return onevalue(v_14244);
}



// Code for mri_prepat

static LispObject CC_mri_prepat(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13830;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_13830 = v_13825;
// end of prologue
    fn = elt(env, 1); // mri_2pasfat
    v_13830 = (*qfn1(fn))(fn, v_13830);
    env = stack[0];
    {
        fn = elt(env, 2); // pasf_prepat
        return (*qfn1(fn))(fn, v_13830);
    }
}



// Code for distribute!.multiplicity

static LispObject CC_distributeQmultiplicity(LispObject env,
                         LispObject v_13825, LispObject v_13826)
{
    env = qenv(env);
    LispObject v_13882, v_13883;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13826,v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13825,v_13826);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_13826;
    v_13882 = v_13825;
// end of prologue
    stack[-4] = v_13882;
    v_13882 = stack[-4];
    if (v_13882 == nil) goto v_13837;
    else goto v_13838;
v_13837:
    v_13882 = nil;
    goto v_13832;
v_13838:
    v_13882 = stack[-4];
    v_13882 = qcar(v_13882);
    goto v_13850;
v_13846:
    v_13883 = v_13882;
    goto v_13847;
v_13848:
    v_13882 = stack[-3];
    goto v_13849;
v_13850:
    goto v_13846;
v_13847:
    goto v_13848;
v_13849:
    v_13882 = cons(v_13883, v_13882);
    env = stack[-5];
    v_13882 = ncons(v_13882);
    env = stack[-5];
    stack[-1] = v_13882;
    stack[-2] = v_13882;
v_13833:
    v_13882 = stack[-4];
    v_13882 = qcdr(v_13882);
    stack[-4] = v_13882;
    v_13882 = stack[-4];
    if (v_13882 == nil) goto v_13857;
    else goto v_13858;
v_13857:
    v_13882 = stack[-2];
    goto v_13832;
v_13858:
    goto v_13866;
v_13862:
    stack[0] = stack[-1];
    goto v_13863;
v_13864:
    v_13882 = stack[-4];
    v_13882 = qcar(v_13882);
    goto v_13877;
v_13873:
    v_13883 = v_13882;
    goto v_13874;
v_13875:
    v_13882 = stack[-3];
    goto v_13876;
v_13877:
    goto v_13873;
v_13874:
    goto v_13875;
v_13876:
    v_13882 = cons(v_13883, v_13882);
    env = stack[-5];
    v_13882 = ncons(v_13882);
    env = stack[-5];
    goto v_13865;
v_13866:
    goto v_13862;
v_13863:
    goto v_13864;
v_13865:
    v_13882 = Lrplacd(nil, stack[0], v_13882);
    env = stack[-5];
    v_13882 = stack[-1];
    v_13882 = qcdr(v_13882);
    stack[-1] = v_13882;
    goto v_13833;
v_13832:
    return onevalue(v_13882);
}



// Code for bvarml

static LispObject CC_bvarml(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13860, v_13861;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_13825;
// end of prologue
    v_13860 = elt(env, 1); // "<bvar>"
    fn = elt(env, 3); // printout
    v_13860 = (*qfn1(fn))(fn, v_13860);
    env = stack[-1];
    v_13860 = lisp_true;
    fn = elt(env, 4); // indent!*
    v_13860 = (*qfn1(fn))(fn, v_13860);
    env = stack[-1];
    v_13860 = stack[0];
    v_13860 = qcar(v_13860);
    fn = elt(env, 5); // expression
    v_13860 = (*qfn1(fn))(fn, v_13860);
    env = stack[-1];
    goto v_13845;
v_13841:
    v_13860 = stack[0];
    v_13860 = qcdr(v_13860);
    v_13861 = qcar(v_13860);
    goto v_13842;
v_13843:
    v_13860 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13844;
v_13845:
    goto v_13841;
v_13842:
    goto v_13843;
v_13844:
    if (v_13861 == v_13860) goto v_13840;
    v_13860 = stack[0];
    v_13860 = qcdr(v_13860);
    v_13860 = qcar(v_13860);
    v_13860 = ncons(v_13860);
    env = stack[-1];
    fn = elt(env, 6); // degreeml
    v_13860 = (*qfn1(fn))(fn, v_13860);
    env = stack[-1];
    goto v_13838;
v_13840:
v_13838:
    v_13860 = nil;
    fn = elt(env, 4); // indent!*
    v_13860 = (*qfn1(fn))(fn, v_13860);
    env = stack[-1];
    v_13860 = elt(env, 2); // "</bvar>"
    fn = elt(env, 3); // printout
    v_13860 = (*qfn1(fn))(fn, v_13860);
    v_13860 = nil;
    return onevalue(v_13860);
}



// Code for bcneg

static LispObject CC_bcneg(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13859, v_13860;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_13825;
// end of prologue
    v_13859 = qvalue(elt(env, 1)); // !*grmod!*
    if (v_13859 == nil) goto v_13830;
    goto v_13841;
v_13837:
    v_13860 = stack[0];
    goto v_13838;
v_13839:
    v_13859 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13840;
v_13841:
    goto v_13837;
v_13838:
    goto v_13839;
v_13840:
    v_13859 = Leqn(nil, v_13860, v_13859);
    env = stack[-1];
    if (v_13859 == nil) goto v_13835;
    v_13859 = stack[0];
    goto v_13833;
v_13835:
    goto v_13851;
v_13847:
    v_13860 = qvalue(elt(env, 2)); // current!-modulus
    goto v_13848;
v_13849:
    v_13859 = stack[0];
    goto v_13850;
v_13851:
    goto v_13847;
v_13848:
    goto v_13849;
v_13850:
    v_13859 = (LispObject)(intptr_t)((intptr_t)v_13860 - (intptr_t)v_13859 + TAG_FIXNUM);
    goto v_13833;
    v_13859 = nil;
v_13833:
    goto v_13828;
v_13830:
    v_13859 = stack[0];
    {
        fn = elt(env, 3); // negsq
        return (*qfn1(fn))(fn, v_13859);
    }
    v_13859 = nil;
v_13828:
    return onevalue(v_13859);
}



// Code for ev!-denom2

static LispObject CC_evKdenom2(LispObject env,
                         LispObject v_13825, LispObject v_13826)
{
    env = qenv(env);
    LispObject v_13837, v_13838;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13837 = v_13826;
    v_13838 = v_13825;
// end of prologue
    goto v_13833;
v_13829:
    v_13838 = qcar(v_13838);
    goto v_13830;
v_13831:
    goto v_13832;
v_13833:
    goto v_13829;
v_13830:
    goto v_13831;
v_13832:
    {
        fn = elt(env, 1); // ev!-edgeloop
        return (*qfn2(fn))(fn, v_13838, v_13837);
    }
}



// Code for comblog

static LispObject CC_comblog(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13950, v_13951;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13825;
// end of prologue
    stack[-1] = nil;
v_13830:
    v_13950 = stack[0];
    if (!consp(v_13950)) goto v_13837;
    else goto v_13838;
v_13837:
    v_13950 = lisp_true;
    goto v_13836;
v_13838:
    goto v_13847;
v_13843:
    v_13950 = stack[0];
    v_13951 = qcar(v_13950);
    goto v_13844;
v_13845:
    v_13950 = qvalue(elt(env, 1)); // domainlist!*
    goto v_13846;
v_13847:
    goto v_13843;
v_13844:
    goto v_13845;
v_13846:
    v_13950 = Lmemq(nil, v_13951, v_13950);
    goto v_13836;
    v_13950 = nil;
v_13836:
    if (v_13950 == nil) goto v_13834;
    goto v_13857;
v_13853:
    v_13951 = stack[-1];
    goto v_13854;
v_13855:
    v_13950 = stack[0];
    goto v_13856;
v_13857:
    goto v_13853;
v_13854:
    goto v_13855;
v_13856:
    {
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(fn, v_13951, v_13950);
    }
v_13834:
    goto v_13870;
v_13866:
    v_13950 = stack[0];
    v_13951 = qcar(v_13950);
    goto v_13867;
v_13868:
    v_13950 = elt(env, 2); // plus
    goto v_13869;
v_13870:
    goto v_13866;
v_13867:
    goto v_13868;
v_13869:
    if (v_13951 == v_13950) goto v_13864;
    else goto v_13865;
v_13864:
    v_13950 = lisp_true;
    goto v_13863;
v_13865:
    goto v_13885;
v_13881:
    v_13950 = stack[0];
    v_13951 = qcar(v_13950);
    goto v_13882;
v_13883:
    v_13950 = elt(env, 3); // times
    goto v_13884;
v_13885:
    goto v_13881;
v_13882:
    goto v_13883;
v_13884:
    if (v_13951 == v_13950) goto v_13879;
    else goto v_13880;
v_13879:
    v_13950 = stack[0];
    fn = elt(env, 6); // simp!*
    v_13950 = (*qfn1(fn))(fn, v_13950);
    env = stack[-2];
    v_13950 = qcar(v_13950);
    v_13951 = v_13950;
    v_13950 = v_13951;
    if (!consp(v_13950)) goto v_13899;
    else goto v_13900;
v_13899:
    v_13950 = lisp_true;
    goto v_13898;
v_13900:
    v_13950 = v_13951;
    v_13950 = qcar(v_13950);
    v_13950 = (consp(v_13950) ? nil : lisp_true);
    goto v_13898;
    v_13950 = nil;
v_13898:
    if (v_13950 == nil) goto v_13895;
    else goto v_13896;
v_13895:
    goto v_13913;
v_13909:
    v_13950 = v_13951;
    v_13950 = qcar(v_13950);
    v_13950 = qcar(v_13950);
    v_13951 = qcar(v_13950);
    goto v_13910;
v_13911:
    v_13950 = elt(env, 4); // log
    goto v_13912;
v_13913:
    goto v_13909;
v_13910:
    goto v_13911;
v_13912:
    v_13950 = Leqcar(nil, v_13951, v_13950);
    env = stack[-2];
    goto v_13894;
v_13896:
    v_13950 = nil;
    goto v_13894;
    v_13950 = nil;
v_13894:
    goto v_13878;
v_13880:
    v_13950 = nil;
    goto v_13878;
    v_13950 = nil;
v_13878:
    goto v_13863;
    v_13950 = nil;
v_13863:
    if (v_13950 == nil) goto v_13861;
    goto v_13930;
v_13926:
    goto v_13927;
v_13928:
    v_13950 = stack[0];
    fn = elt(env, 6); // simp!*
    v_13950 = (*qfn1(fn))(fn, v_13950);
    env = stack[-2];
    fn = elt(env, 7); // clogsq
    v_13950 = (*qfn1(fn))(fn, v_13950);
    env = stack[-2];
    fn = elt(env, 8); // prepsq!*
    v_13950 = (*qfn1(fn))(fn, v_13950);
    env = stack[-2];
    goto v_13929;
v_13930:
    goto v_13926;
v_13927:
    goto v_13928;
v_13929:
    {
        LispObject v_13954 = stack[-1];
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(fn, v_13954, v_13950);
    }
v_13861:
    goto v_13943;
v_13939:
    v_13950 = stack[0];
    v_13950 = qcar(v_13950);
    v_13951 = CC_comblog(elt(env, 0), v_13950);
    env = stack[-2];
    goto v_13940;
v_13941:
    v_13950 = stack[-1];
    goto v_13942;
v_13943:
    goto v_13939;
v_13940:
    goto v_13941;
v_13942:
    v_13950 = cons(v_13951, v_13950);
    env = stack[-2];
    stack[-1] = v_13950;
    v_13950 = stack[0];
    v_13950 = qcdr(v_13950);
    stack[0] = v_13950;
    goto v_13830;
    v_13950 = nil;
    return onevalue(v_13950);
}



// Code for copy!-tree

static LispObject CC_copyKtree(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13911, v_13912, v_13913, v_13914;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_13825;
// end of prologue
    v_13911 = stack[-2];
    if (v_13911 == nil) goto v_13829;
    else goto v_13830;
v_13829:
    v_13911 = nil;
    goto v_13828;
v_13830:
    v_13911 = (LispObject)48+TAG_FIXNUM; // 3
    v_13911 = Lmkvect(nil, v_13911);
    env = stack[-4];
    stack[-3] = v_13911;
    goto v_13847;
v_13841:
    v_13914 = stack[-3];
    goto v_13842;
v_13843:
    v_13913 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13844;
v_13845:
    goto v_13854;
v_13850:
    v_13912 = stack[-2];
    goto v_13851;
v_13852:
    v_13911 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13853;
v_13854:
    goto v_13850;
v_13851:
    goto v_13852;
v_13853:
    v_13911 = *(LispObject *)((char *)v_13912 + (CELL-TAG_VECTOR) + (((intptr_t)v_13911-TAG_FIXNUM)/(16/CELL)));
    goto v_13846;
v_13847:
    goto v_13841;
v_13842:
    goto v_13843;
v_13844:
    goto v_13845;
v_13846:
    *(LispObject *)((char *)v_13914 + (CELL-TAG_VECTOR) + (((intptr_t)v_13913-TAG_FIXNUM)/(16/CELL))) = v_13911;
    goto v_13864;
v_13858:
    v_13914 = stack[-3];
    goto v_13859;
v_13860:
    v_13913 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13861;
v_13862:
    goto v_13871;
v_13867:
    v_13912 = stack[-2];
    goto v_13868;
v_13869:
    v_13911 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13870;
v_13871:
    goto v_13867;
v_13868:
    goto v_13869;
v_13870:
    v_13911 = *(LispObject *)((char *)v_13912 + (CELL-TAG_VECTOR) + (((intptr_t)v_13911-TAG_FIXNUM)/(16/CELL)));
    goto v_13863;
v_13864:
    goto v_13858;
v_13859:
    goto v_13860;
v_13861:
    goto v_13862;
v_13863:
    *(LispObject *)((char *)v_13914 + (CELL-TAG_VECTOR) + (((intptr_t)v_13913-TAG_FIXNUM)/(16/CELL))) = v_13911;
    goto v_13881;
v_13875:
    v_13914 = stack[-3];
    goto v_13876;
v_13877:
    v_13913 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13878;
v_13879:
    goto v_13888;
v_13884:
    v_13912 = stack[-2];
    goto v_13885;
v_13886:
    v_13911 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13887;
v_13888:
    goto v_13884;
v_13885:
    goto v_13886;
v_13887:
    v_13911 = *(LispObject *)((char *)v_13912 + (CELL-TAG_VECTOR) + (((intptr_t)v_13911-TAG_FIXNUM)/(16/CELL)));
    goto v_13880;
v_13881:
    goto v_13875;
v_13876:
    goto v_13877;
v_13878:
    goto v_13879;
v_13880:
    *(LispObject *)((char *)v_13914 + (CELL-TAG_VECTOR) + (((intptr_t)v_13913-TAG_FIXNUM)/(16/CELL))) = v_13911;
    goto v_13898;
v_13892:
    stack[-1] = stack[-3];
    goto v_13893;
v_13894:
    stack[0] = (LispObject)48+TAG_FIXNUM; // 3
    goto v_13895;
v_13896:
    goto v_13906;
v_13902:
    v_13912 = stack[-2];
    goto v_13903;
v_13904:
    v_13911 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_13905;
v_13906:
    goto v_13902;
v_13903:
    goto v_13904;
v_13905:
    v_13911 = *(LispObject *)((char *)v_13912 + (CELL-TAG_VECTOR) + (((intptr_t)v_13911-TAG_FIXNUM)/(16/CELL)));
    v_13911 = CC_copyKtree(elt(env, 0), v_13911);
    goto v_13897;
v_13898:
    goto v_13892;
v_13893:
    goto v_13894;
v_13895:
    goto v_13896;
v_13897:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_13911;
    v_13911 = stack[-3];
    goto v_13828;
    v_13911 = nil;
v_13828:
    return onevalue(v_13911);
}



// Code for merge

static LispObject CC_merge(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13894, v_13895, v_13896;
    LispObject v_13827, v_13826, v_13825;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "merge");
    va_start(aa, nargs);
    v_13825 = va_arg(aa, LispObject);
    v_13826 = va_arg(aa, LispObject);
    v_13827 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13827,v_13826,v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13825,v_13826,v_13827);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_13827;
    stack[-1] = v_13826;
    stack[-2] = v_13825;
// end of prologue
    v_13894 = stack[-2];
    if (v_13894 == nil) goto v_13831;
    else goto v_13832;
v_13831:
    v_13894 = stack[-1];
    goto v_13830;
v_13832:
    v_13894 = stack[-1];
    if (v_13894 == nil) goto v_13835;
    else goto v_13836;
v_13835:
    v_13894 = stack[-2];
    goto v_13830;
v_13836:
    goto v_13848;
v_13842:
    v_13896 = stack[0];
    goto v_13843;
v_13844:
    v_13894 = stack[-2];
    v_13895 = qcar(v_13894);
    goto v_13845;
v_13846:
    v_13894 = stack[-1];
    v_13894 = qcar(v_13894);
    goto v_13847;
v_13848:
    goto v_13842;
v_13843:
    goto v_13844;
v_13845:
    goto v_13846;
v_13847:
    v_13894 = Lapply2(nil, 3, v_13896, v_13895, v_13894);
    env = stack[-4];
    if (v_13894 == nil) goto v_13840;
    goto v_13859;
v_13855:
    stack[-3] = stack[-2];
    goto v_13856;
v_13857:
    goto v_13868;
v_13862:
    v_13894 = stack[-2];
    v_13896 = qcdr(v_13894);
    goto v_13863;
v_13864:
    v_13895 = stack[-1];
    goto v_13865;
v_13866:
    v_13894 = stack[0];
    goto v_13867;
v_13868:
    goto v_13862;
v_13863:
    goto v_13864;
v_13865:
    goto v_13866;
v_13867:
    v_13894 = CC_merge(elt(env, 0), 3, v_13896, v_13895, v_13894);
    goto v_13858;
v_13859:
    goto v_13855;
v_13856:
    goto v_13857;
v_13858:
    {
        LispObject v_13901 = stack[-3];
        return Lrplacd(nil, v_13901, v_13894);
    }
v_13840:
    goto v_13880;
v_13876:
    stack[-3] = stack[-1];
    goto v_13877;
v_13878:
    goto v_13889;
v_13883:
    v_13896 = stack[-2];
    goto v_13884;
v_13885:
    v_13894 = stack[-1];
    v_13895 = qcdr(v_13894);
    goto v_13886;
v_13887:
    v_13894 = stack[0];
    goto v_13888;
v_13889:
    goto v_13883;
v_13884:
    goto v_13885;
v_13886:
    goto v_13887;
v_13888:
    v_13894 = CC_merge(elt(env, 0), 3, v_13896, v_13895, v_13894);
    goto v_13879;
v_13880:
    goto v_13876;
v_13877:
    goto v_13878;
v_13879:
    {
        LispObject v_13902 = stack[-3];
        return Lrplacd(nil, v_13902, v_13894);
    }
    v_13894 = nil;
v_13830:
    return onevalue(v_13894);
}



// Code for safe!-modrecip

static LispObject CC_safeKmodrecip(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13879, v_13880, v_13881;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_13880 = v_13825;
// end of prologue
// Binding !*msg
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-3, 1, -1);
    qvalue(elt(env, 1)) = nil; // !*msg
// Binding !*protfg
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-3, 2, 0);
    qvalue(elt(env, 2)) = nil; // !*protfg
    v_13879 = nil;
    qvalue(elt(env, 1)) = v_13879; // !*msg
    v_13879 = lisp_true;
    qvalue(elt(env, 2)) = v_13879; // !*protfg
    goto v_13844;
v_13840:
    v_13881 = v_13880;
    goto v_13841;
v_13842:
    v_13879 = elt(env, 4); // !:mod!:
    goto v_13843;
v_13844:
    goto v_13840;
v_13841:
    goto v_13842;
v_13843:
    if (!consp(v_13881)) goto v_13838;
    v_13881 = qcar(v_13881);
    if (v_13881 == v_13879) goto v_13837;
    else goto v_13838;
v_13837:
    v_13879 = v_13880;
    v_13879 = qcdr(v_13879);
    v_13880 = v_13879;
    goto v_13836;
v_13838:
v_13836:
    goto v_13856;
v_13850:
    goto v_13862;
v_13858:
    v_13879 = elt(env, 5); // general!-modular!-reciprocal
    goto v_13859;
v_13860:
    goto v_13861;
v_13862:
    goto v_13858;
v_13859:
    goto v_13860;
v_13861:
    v_13881 = list2(v_13879, v_13880);
    env = stack[-3];
    goto v_13851;
v_13852:
    v_13880 = nil;
    goto v_13853;
v_13854:
    v_13879 = nil;
    goto v_13855;
v_13856:
    goto v_13850;
v_13851:
    goto v_13852;
v_13853:
    goto v_13854;
v_13855:
    fn = elt(env, 7); // errorset
    v_13879 = (*qfnn(fn))(fn, 3, v_13881, v_13880, v_13879);
    env = stack[-3];
    stack[-2] = v_13879;
    v_13879 = nil;
    qvalue(elt(env, 6)) = v_13879; // erfg!*
    v_13879 = stack[-2];
    fn = elt(env, 8); // errorp
    v_13879 = (*qfn1(fn))(fn, v_13879);
    if (v_13879 == nil) goto v_13871;
    v_13879 = nil;
    goto v_13869;
v_13871:
    v_13879 = stack[-2];
    v_13879 = qcar(v_13879);
    goto v_13869;
    v_13879 = nil;
v_13869:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_13879);
}



// Code for setk_super_vectorfield

static LispObject CC_setk_super_vectorfield(LispObject env,
                         LispObject v_13825, LispObject v_13826)
{
    env = qenv(env);
    LispObject v_14000, v_14001, v_14002, v_14003, v_14004;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13826,v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13825,v_13826);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_13826;
    stack[0] = v_13825;
// end of prologue
    goto v_13844;
v_13840:
    v_14000 = stack[0];
    v_14001 = Llength(nil, v_14000);
    env = stack[-4];
    goto v_13841;
v_13842:
    v_14000 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13843;
v_13844:
    goto v_13840;
v_13841:
    goto v_13842;
v_13843:
    if (v_14001 == v_14000) goto v_13839;
    goto v_13857;
v_13849:
    v_14003 = stack[0];
    goto v_13850;
v_13851:
    v_14002 = stack[-2];
    goto v_13852;
v_13853:
    v_14001 = nil;
    goto v_13854;
v_13855:
    v_14000 = lisp_true;
    goto v_13856;
v_13857:
    goto v_13849;
v_13850:
    goto v_13851;
v_13852:
    goto v_13853;
v_13854:
    goto v_13855;
v_13856:
    {
        fn = elt(env, 6); // let2
        return (*qfnn(fn))(fn, 4, v_14003, v_14002, v_14001, v_14000);
    }
v_13839:
    v_14000 = stack[0];
    v_14000 = qcar(v_14000);
    stack[-3] = v_14000;
    v_14000 = stack[0];
    v_14000 = qcdr(v_14000);
    v_14000 = qcar(v_14000);
    stack[-1] = v_14000;
    v_14000 = stack[-1];
    if (!consp(v_14000)) goto v_13874;
    goto v_13884;
v_13880:
    v_14000 = stack[-1];
    v_14001 = qcar(v_14000);
    goto v_13881;
v_13882:
    v_14000 = elt(env, 2); // ext
    goto v_13883;
v_13884:
    goto v_13880;
v_13881:
    goto v_13882;
v_13883:
    if (v_14001 == v_14000) goto v_13878;
    else goto v_13879;
v_13878:
    goto v_13892;
v_13888:
    v_14000 = stack[-1];
    v_14001 = Llength(nil, v_14000);
    env = stack[-4];
    goto v_13889;
v_13890:
    v_14000 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13891;
v_13892:
    goto v_13888;
v_13889:
    goto v_13890;
v_13891:
    v_14000 = (v_14001 == v_14000 ? lisp_true : nil);
    goto v_13877;
v_13879:
    v_14000 = nil;
    goto v_13877;
    v_14000 = nil;
v_13877:
    goto v_13872;
v_13874:
    v_14000 = nil;
    goto v_13872;
    v_14000 = nil;
v_13872:
    if (v_14000 == nil) goto v_13870;
    goto v_13908;
v_13904:
    v_14001 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13905;
v_13906:
    v_14000 = stack[-1];
    v_14000 = qcdr(v_14000);
    v_14000 = qcar(v_14000);
    goto v_13907;
v_13908:
    goto v_13904;
v_13905:
    goto v_13906;
v_13907:
    v_14000 = list2(v_14001, v_14000);
    env = stack[-4];
    goto v_13868;
v_13870:
    goto v_13920;
v_13916:
    v_14001 = stack[-3];
    goto v_13917;
v_13918:
    v_14000 = elt(env, 3); // variables
    goto v_13919;
v_13920:
    goto v_13916;
v_13917:
    goto v_13918;
v_13919:
    v_14000 = get(v_14001, v_14000);
    env = stack[-4];
    stack[0] = v_14000;
    v_14000 = (LispObject)16+TAG_FIXNUM; // 1
    v_14002 = v_14000;
v_13926:
    v_14000 = stack[0];
    if (v_14000 == nil) goto v_13929;
    goto v_13938;
v_13934:
    v_14001 = stack[-1];
    goto v_13935;
v_13936:
    v_14000 = stack[0];
    v_14000 = qcar(v_14000);
    goto v_13937;
v_13938:
    goto v_13934;
v_13935:
    goto v_13936;
v_13937:
    if (equal(v_14001, v_14000)) goto v_13929;
    goto v_13930;
v_13929:
    goto v_13925;
v_13930:
    v_14000 = stack[0];
    v_14000 = qcdr(v_14000);
    stack[0] = v_14000;
    v_14000 = v_14002;
    v_14000 = add1(v_14000);
    env = stack[-4];
    v_14002 = v_14000;
    goto v_13926;
v_13925:
    v_14000 = stack[0];
    if (v_14000 == nil) goto v_13949;
    else goto v_13950;
v_13949:
    goto v_13963;
v_13953:
    v_14004 = elt(env, 4); // "SETK_SUPER_VECTORFIELD:"
    goto v_13954;
v_13955:
    v_14003 = stack[-1];
    goto v_13956;
v_13957:
    v_14002 = elt(env, 5); // "not a valid variable for"
    goto v_13958;
v_13959:
    v_14001 = stack[-3];
    goto v_13960;
v_13961:
    v_14000 = lisp_true;
    goto v_13962;
v_13963:
    goto v_13953;
v_13954:
    goto v_13955;
v_13956:
    goto v_13957;
v_13958:
    goto v_13959;
v_13960:
    goto v_13961;
v_13962:
    fn = elt(env, 7); // msgpri
    v_14000 = (*qfnn(fn))(fn, 5, v_14004, v_14003, v_14002, v_14001, v_14000);
    env = stack[-4];
    goto v_13948;
v_13950:
    goto v_13976;
v_13972:
    v_14000 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13973;
v_13974:
    v_14001 = v_14002;
    goto v_13975;
v_13976:
    goto v_13972;
v_13973:
    goto v_13974;
v_13975:
    v_14000 = list2(v_14000, v_14001);
    env = stack[-4];
    goto v_13948;
    v_14000 = nil;
v_13948:
    goto v_13868;
    v_14000 = nil;
v_13868:
    goto v_13988;
v_13980:
    goto v_13994;
v_13990:
    v_14001 = stack[-3];
    goto v_13991;
v_13992:
    goto v_13993;
v_13994:
    goto v_13990;
v_13991:
    goto v_13992;
v_13993:
    v_14003 = cons(v_14001, v_14000);
    env = stack[-4];
    goto v_13981;
v_13982:
    v_14002 = stack[-2];
    goto v_13983;
v_13984:
    v_14001 = nil;
    goto v_13985;
v_13986:
    v_14000 = lisp_true;
    goto v_13987;
v_13988:
    goto v_13980;
v_13981:
    goto v_13982;
v_13983:
    goto v_13984;
v_13985:
    goto v_13986;
v_13987:
    {
        fn = elt(env, 6); // let2
        return (*qfnn(fn))(fn, 4, v_14003, v_14002, v_14001, v_14000);
    }
    return onevalue(v_14000);
}



// Code for lex_cleanup

static LispObject CC_lex_cleanup(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13864, v_13865, v_13866, v_13867;
    argcheck(nargs, 0, "lex_cleanup");
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
    v_13864 = qvalue(elt(env, 1)); // lex_keyword_names
    v_13867 = v_13864;
v_13832:
    v_13864 = v_13867;
    if (v_13864 == nil) goto v_13836;
    else goto v_13837;
v_13836:
    goto v_13831;
v_13837:
    v_13864 = v_13867;
    v_13864 = qcar(v_13864);
    v_13866 = v_13864;
    goto v_13848;
v_13844:
    v_13865 = v_13866;
    goto v_13845;
v_13846:
    v_13864 = elt(env, 2); // lex_code
    goto v_13847;
v_13848:
    goto v_13844;
v_13845:
    goto v_13846;
v_13847:
    v_13864 = Lremprop(nil, v_13865, v_13864);
    env = stack[0];
    goto v_13856;
v_13852:
    v_13865 = v_13866;
    goto v_13853;
v_13854:
    v_13864 = elt(env, 3); // lex_dipthong
    goto v_13855;
v_13856:
    goto v_13852;
v_13853:
    goto v_13854;
v_13855:
    v_13864 = Lremprop(nil, v_13865, v_13864);
    env = stack[0];
    v_13864 = v_13867;
    v_13864 = qcdr(v_13864);
    v_13867 = v_13864;
    goto v_13832;
v_13831:
    v_13864 = nil;
    qvalue(elt(env, 1)) = v_13864; // lex_keyword_names
    v_13864 = qvalue(elt(env, 4)); // lex_initial_next_code
    qvalue(elt(env, 5)) = v_13864; // lex_next_code
    v_13864 = qvalue(elt(env, 6)); // initial_codename
    qvalue(elt(env, 7)) = v_13864; // lex_codename
    v_13864 = nil;
    return onevalue(v_13864);
}



// Code for gcref_mkgraph!-tgf

static LispObject CC_gcref_mkgraphKtgf(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13879, v_13880;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13825;
// end of prologue
    v_13879 = stack[0];
    stack[-1] = v_13879;
v_13830:
    v_13879 = stack[-1];
    if (v_13879 == nil) goto v_13834;
    else goto v_13835;
v_13834:
    goto v_13829;
v_13835:
    v_13879 = stack[-1];
    v_13879 = qcar(v_13879);
    fn = elt(env, 3); // gcref_mknode!-tgf
    v_13879 = (*qfn1(fn))(fn, v_13879);
    env = stack[-2];
    v_13879 = stack[-1];
    v_13879 = qcdr(v_13879);
    stack[-1] = v_13879;
    goto v_13830;
v_13829:
    v_13879 = elt(env, 1); // "#"
    fn = elt(env, 4); // prin2t
    v_13879 = (*qfn1(fn))(fn, v_13879);
    env = stack[-2];
    v_13879 = stack[0];
    stack[-1] = v_13879;
v_13850:
    v_13879 = stack[-1];
    if (v_13879 == nil) goto v_13854;
    else goto v_13855;
v_13854:
    v_13879 = nil;
    goto v_13849;
v_13855:
    v_13879 = stack[-1];
    v_13879 = qcar(v_13879);
    goto v_13866;
v_13862:
    stack[0] = v_13879;
    goto v_13863;
v_13864:
    goto v_13874;
v_13870:
    v_13880 = v_13879;
    goto v_13871;
v_13872:
    v_13879 = elt(env, 2); // calls
    goto v_13873;
v_13874:
    goto v_13870;
v_13871:
    goto v_13872;
v_13873:
    v_13879 = get(v_13880, v_13879);
    env = stack[-2];
    fn = elt(env, 5); // gcref_select
    v_13879 = (*qfn1(fn))(fn, v_13879);
    env = stack[-2];
    goto v_13865;
v_13866:
    goto v_13862;
v_13863:
    goto v_13864;
v_13865:
    fn = elt(env, 6); // gcref_mkedges!-tgf
    v_13879 = (*qfn2(fn))(fn, stack[0], v_13879);
    env = stack[-2];
    v_13879 = stack[-1];
    v_13879 = qcdr(v_13879);
    stack[-1] = v_13879;
    goto v_13850;
v_13849:
    return onevalue(v_13879);
}



// Code for cl_f2ml

static LispObject CC_cl_f2ml(LispObject env,
                         LispObject v_13825, LispObject v_13826)
{
    env = qenv(env);
    LispObject v_14123, v_14124, v_14125;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13826,v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13825,v_13826);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_13826;
    stack[0] = v_13825;
// end of prologue
v_13824:
    v_14123 = stack[0];
    if (!consp(v_14123)) goto v_13834;
    else goto v_13835;
v_13834:
    v_14123 = stack[0];
    goto v_13833;
v_13835:
    v_14123 = stack[0];
    v_14123 = qcar(v_14123);
    goto v_13833;
    v_14123 = nil;
v_13833:
    v_14125 = v_14123;
    goto v_13854;
v_13850:
    v_14124 = stack[0];
    goto v_13851;
v_13852:
    v_14123 = elt(env, 2); // true
    goto v_13853;
v_13854:
    goto v_13850;
v_13851:
    goto v_13852;
v_13853:
    if (v_14124 == v_14123) goto v_13848;
    else goto v_13849;
v_13848:
    v_14123 = lisp_true;
    goto v_13847;
v_13849:
    goto v_13864;
v_13860:
    v_14124 = stack[0];
    goto v_13861;
v_13862:
    v_14123 = elt(env, 3); // false
    goto v_13863;
v_13864:
    goto v_13860;
v_13861:
    goto v_13862;
v_13863:
    v_14123 = (v_14124 == v_14123 ? lisp_true : nil);
    goto v_13847;
    v_14123 = nil;
v_13847:
    if (v_14123 == nil) goto v_13845;
    v_14123 = nil;
    goto v_13830;
v_13845:
    goto v_13889;
v_13885:
    v_14124 = v_14125;
    goto v_13886;
v_13887:
    v_14123 = elt(env, 4); // or
    goto v_13888;
v_13889:
    goto v_13885;
v_13886:
    goto v_13887;
v_13888:
    if (v_14124 == v_14123) goto v_13883;
    else goto v_13884;
v_13883:
    v_14123 = lisp_true;
    goto v_13882;
v_13884:
    goto v_13899;
v_13895:
    v_14124 = v_14125;
    goto v_13896;
v_13897:
    v_14123 = elt(env, 5); // and
    goto v_13898;
v_13899:
    goto v_13895;
v_13896:
    goto v_13897;
v_13898:
    v_14123 = (v_14124 == v_14123 ? lisp_true : nil);
    goto v_13882;
    v_14123 = nil;
v_13882:
    if (v_14123 == nil) goto v_13880;
    v_14123 = lisp_true;
    goto v_13878;
v_13880:
    goto v_13910;
v_13906:
    v_14124 = v_14125;
    goto v_13907;
v_13908:
    v_14123 = elt(env, 6); // not
    goto v_13909;
v_13910:
    goto v_13906;
v_13907:
    goto v_13908;
v_13909:
    v_14123 = (v_14124 == v_14123 ? lisp_true : nil);
    goto v_13878;
    v_14123 = nil;
v_13878:
    if (v_14123 == nil) goto v_13876;
    v_14123 = lisp_true;
    goto v_13874;
v_13876:
    goto v_13925;
v_13921:
    v_14124 = v_14125;
    goto v_13922;
v_13923:
    v_14123 = elt(env, 7); // impl
    goto v_13924;
v_13925:
    goto v_13921;
v_13922:
    goto v_13923;
v_13924:
    if (v_14124 == v_14123) goto v_13919;
    else goto v_13920;
v_13919:
    v_14123 = lisp_true;
    goto v_13918;
v_13920:
    goto v_13939;
v_13935:
    v_14124 = v_14125;
    goto v_13936;
v_13937:
    v_14123 = elt(env, 8); // repl
    goto v_13938;
v_13939:
    goto v_13935;
v_13936:
    goto v_13937;
v_13938:
    if (v_14124 == v_14123) goto v_13933;
    else goto v_13934;
v_13933:
    v_14123 = lisp_true;
    goto v_13932;
v_13934:
    goto v_13949;
v_13945:
    v_14124 = v_14125;
    goto v_13946;
v_13947:
    v_14123 = elt(env, 9); // equiv
    goto v_13948;
v_13949:
    goto v_13945;
v_13946:
    goto v_13947;
v_13948:
    v_14123 = (v_14124 == v_14123 ? lisp_true : nil);
    goto v_13932;
    v_14123 = nil;
v_13932:
    goto v_13918;
    v_14123 = nil;
v_13918:
    goto v_13874;
    v_14123 = nil;
v_13874:
    if (v_14123 == nil) goto v_13872;
    goto v_13958;
v_13954:
    v_14123 = stack[0];
    v_14123 = qcdr(v_14123);
    stack[-4] = v_14123;
    v_14123 = stack[-4];
    if (v_14123 == nil) goto v_13969;
    else goto v_13970;
v_13969:
    v_14123 = nil;
    v_14124 = v_14123;
    goto v_13963;
v_13970:
    v_14123 = stack[-4];
    v_14123 = qcar(v_14123);
    goto v_13982;
v_13978:
    v_14124 = v_14123;
    goto v_13979;
v_13980:
    v_14123 = stack[-3];
    goto v_13981;
v_13982:
    goto v_13978;
v_13979:
    goto v_13980;
v_13981:
    v_14123 = CC_cl_f2ml(elt(env, 0), v_14124, v_14123);
    env = stack[-5];
    v_14123 = ncons(v_14123);
    env = stack[-5];
    stack[-1] = v_14123;
    stack[-2] = v_14123;
v_13964:
    v_14123 = stack[-4];
    v_14123 = qcdr(v_14123);
    stack[-4] = v_14123;
    v_14123 = stack[-4];
    if (v_14123 == nil) goto v_13989;
    else goto v_13990;
v_13989:
    v_14123 = stack[-2];
    v_14124 = v_14123;
    goto v_13963;
v_13990:
    goto v_13998;
v_13994:
    stack[0] = stack[-1];
    goto v_13995;
v_13996:
    v_14123 = stack[-4];
    v_14123 = qcar(v_14123);
    goto v_14009;
v_14005:
    v_14124 = v_14123;
    goto v_14006;
v_14007:
    v_14123 = stack[-3];
    goto v_14008;
v_14009:
    goto v_14005;
v_14006:
    goto v_14007;
v_14008:
    v_14123 = CC_cl_f2ml(elt(env, 0), v_14124, v_14123);
    env = stack[-5];
    v_14123 = ncons(v_14123);
    env = stack[-5];
    goto v_13997;
v_13998:
    goto v_13994;
v_13995:
    goto v_13996;
v_13997:
    v_14123 = Lrplacd(nil, stack[0], v_14123);
    env = stack[-5];
    v_14123 = stack[-1];
    v_14123 = qcdr(v_14123);
    stack[-1] = v_14123;
    goto v_13964;
v_13963:
    goto v_13955;
v_13956:
    v_14123 = elt(env, 10); // plus2
    goto v_13957;
v_13958:
    goto v_13954;
v_13955:
    goto v_13956;
v_13957:
    {
        fn = elt(env, 15); // lto_almerge
        return (*qfn2(fn))(fn, v_14124, v_14123);
    }
v_13872:
    goto v_14027;
v_14023:
    v_14124 = v_14125;
    goto v_14024;
v_14025:
    v_14123 = elt(env, 11); // ex
    goto v_14026;
v_14027:
    goto v_14023;
v_14024:
    goto v_14025;
v_14026:
    if (v_14124 == v_14123) goto v_14021;
    else goto v_14022;
v_14021:
    v_14123 = lisp_true;
    goto v_14020;
v_14022:
    goto v_14037;
v_14033:
    v_14124 = v_14125;
    goto v_14034;
v_14035:
    v_14123 = elt(env, 12); // all
    goto v_14036;
v_14037:
    goto v_14033;
v_14034:
    goto v_14035;
v_14036:
    v_14123 = (v_14124 == v_14123 ? lisp_true : nil);
    goto v_14020;
    v_14123 = nil;
v_14020:
    if (v_14123 == nil) goto v_14018;
    goto v_14046;
v_14042:
    v_14123 = stack[0];
    v_14123 = qcdr(v_14123);
    v_14123 = qcdr(v_14123);
    v_14124 = qcar(v_14123);
    goto v_14043;
v_14044:
    v_14123 = stack[-3];
    goto v_14045;
v_14046:
    goto v_14042;
v_14043:
    goto v_14044;
v_14045:
    stack[0] = v_14124;
    stack[-3] = v_14123;
    goto v_13824;
v_14018:
    goto v_14064;
v_14060:
    v_14124 = v_14125;
    goto v_14061;
v_14062:
    v_14123 = elt(env, 13); // bex
    goto v_14063;
v_14064:
    goto v_14060;
v_14061:
    goto v_14062;
v_14063:
    if (v_14124 == v_14123) goto v_14058;
    else goto v_14059;
v_14058:
    v_14123 = lisp_true;
    goto v_14057;
v_14059:
    goto v_14074;
v_14070:
    v_14124 = v_14125;
    goto v_14071;
v_14072:
    v_14123 = elt(env, 14); // ball
    goto v_14073;
v_14074:
    goto v_14070;
v_14071:
    goto v_14072;
v_14073:
    v_14123 = (v_14124 == v_14123 ? lisp_true : nil);
    goto v_14057;
    v_14123 = nil;
v_14057:
    if (v_14123 == nil) goto v_14055;
    goto v_14083;
v_14079:
    goto v_14089;
v_14085:
    goto v_14095;
v_14091:
    v_14123 = stack[0];
    v_14123 = qcdr(v_14123);
    v_14123 = qcdr(v_14123);
    v_14124 = qcar(v_14123);
    goto v_14092;
v_14093:
    v_14123 = stack[-3];
    goto v_14094;
v_14095:
    goto v_14091;
v_14092:
    goto v_14093;
v_14094:
    stack[-1] = CC_cl_f2ml(elt(env, 0), v_14124, v_14123);
    env = stack[-5];
    goto v_14086;
v_14087:
    goto v_14106;
v_14102:
    v_14123 = stack[0];
    v_14123 = qcdr(v_14123);
    v_14123 = qcdr(v_14123);
    v_14123 = qcdr(v_14123);
    v_14124 = qcar(v_14123);
    goto v_14103;
v_14104:
    v_14123 = stack[-3];
    goto v_14105;
v_14106:
    goto v_14102;
v_14103:
    goto v_14104;
v_14105:
    v_14123 = CC_cl_f2ml(elt(env, 0), v_14124, v_14123);
    env = stack[-5];
    goto v_14088;
v_14089:
    goto v_14085;
v_14086:
    goto v_14087;
v_14088:
    v_14124 = list2(stack[-1], v_14123);
    env = stack[-5];
    goto v_14080;
v_14081:
    v_14123 = elt(env, 10); // plus2
    goto v_14082;
v_14083:
    goto v_14079;
v_14080:
    goto v_14081;
v_14082:
    {
        fn = elt(env, 15); // lto_almerge
        return (*qfn2(fn))(fn, v_14124, v_14123);
    }
v_14055:
    goto v_14119;
v_14115:
    stack[-1] = stack[-3];
    goto v_14116;
v_14117:
    v_14123 = stack[0];
    v_14123 = ncons(v_14123);
    env = stack[-5];
    goto v_14118;
v_14119:
    goto v_14115;
v_14116:
    goto v_14117;
v_14118:
    {
        LispObject v_14131 = stack[-1];
        fn = elt(env, 16); // apply
        return (*qfn2(fn))(fn, v_14131, v_14123);
    }
v_13830:
    return onevalue(v_14123);
}



// Code for settinsert

static LispObject CC_settinsert(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13840, v_13841;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_13825;
// end of prologue
    v_13840 = stack[0];
    fn = elt(env, 2); // janettreeinsert
    v_13840 = (*qfn1(fn))(fn, v_13840);
    env = stack[-1];
    goto v_13837;
v_13833:
    v_13841 = stack[0];
    goto v_13834;
v_13835:
    v_13840 = qvalue(elt(env, 1)); // fluidbibasissett
    goto v_13836;
v_13837:
    goto v_13833;
v_13834:
    goto v_13835;
v_13836:
    v_13840 = cons(v_13841, v_13840);
    env = stack[-1];
    qvalue(elt(env, 1)) = v_13840; // fluidbibasissett
    v_13840 = nil;
    return onevalue(v_13840);
}



// Code for texstrlen

static LispObject CC_texstrlen(LispObject env,
                         LispObject v_13825)
{
    env = qenv(env);
    LispObject v_13878, v_13879, v_13880;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13825);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_13878 = v_13825;
// end of prologue
    v_13879 = (LispObject)0+TAG_FIXNUM; // 0
    v_13880 = v_13879;
    v_13879 = nil;
    stack[0] = v_13878;
v_13838:
    v_13878 = stack[0];
    if (v_13878 == nil) goto v_13842;
    else goto v_13843;
v_13842:
    goto v_13837;
v_13843:
    v_13878 = stack[0];
    v_13878 = qcar(v_13878);
    if (v_13879 == nil) goto v_13855;
    else goto v_13856;
v_13855:
    goto v_13862;
v_13858:
    v_13879 = v_13878;
    goto v_13859;
v_13860:
    v_13878 = elt(env, 2); // !!
    goto v_13861;
v_13862:
    goto v_13858;
v_13859:
    goto v_13860;
v_13861:
    v_13878 = (v_13879 == v_13878 ? lisp_true : nil);
    goto v_13854;
v_13856:
    v_13878 = nil;
    goto v_13854;
    v_13878 = nil;
v_13854:
    if (v_13878 == nil) goto v_13852;
    v_13878 = lisp_true;
    v_13879 = v_13878;
    goto v_13850;
v_13852:
    v_13878 = v_13880;
    v_13878 = add1(v_13878);
    env = stack[-1];
    v_13880 = v_13878;
    v_13878 = nil;
    v_13879 = v_13878;
    goto v_13850;
v_13850:
    v_13878 = stack[0];
    v_13878 = qcdr(v_13878);
    stack[0] = v_13878;
    goto v_13838;
v_13837:
    v_13878 = v_13880;
    return onevalue(v_13878);
}



// Code for cl_susiupdknowl1

static LispObject CC_cl_susiupdknowl1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13880, v_13881, v_13882;
    LispObject fn;
    LispObject v_13828, v_13827, v_13826, v_13825;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_susiupdknowl1");
    va_start(aa, nargs);
    v_13825 = va_arg(aa, LispObject);
    v_13826 = va_arg(aa, LispObject);
    v_13827 = va_arg(aa, LispObject);
    v_13828 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_13828,v_13827,v_13826,v_13825);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_13825,v_13826,v_13827,v_13828);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13828;
    stack[-1] = v_13827;
    v_13882 = v_13826;
    v_13880 = v_13825;
// end of prologue
    goto v_13838;
v_13834:
    v_13881 = v_13880;
    goto v_13835;
v_13836:
    v_13880 = elt(env, 1); // and
    goto v_13837;
v_13838:
    goto v_13834;
v_13835:
    goto v_13836;
v_13837:
    if (v_13881 == v_13880) goto v_13832;
    else goto v_13833;
v_13832:
    goto v_13848;
v_13842:
    goto v_13854;
v_13850:
    v_13881 = v_13882;
    goto v_13851;
v_13852:
    v_13880 = stack[0];
    goto v_13853;
v_13854:
    goto v_13850;
v_13851:
    goto v_13852;
v_13853:
    v_13882 = cons(v_13881, v_13880);
    env = stack[-2];
    goto v_13843;
v_13844:
    v_13881 = stack[-1];
    goto v_13845;
v_13846:
    v_13880 = stack[0];
    goto v_13847;
v_13848:
    goto v_13842;
v_13843:
    goto v_13844;
v_13845:
    goto v_13846;
v_13847:
    {
        fn = elt(env, 2); // cl_susiupdknowl2
        return (*qfnn(fn))(fn, 3, v_13882, v_13881, v_13880);
    }
v_13833:
    goto v_13868;
v_13862:
    goto v_13874;
v_13870:
    v_13880 = v_13882;
    fn = elt(env, 3); // rl_negateat
    v_13881 = (*qfn1(fn))(fn, v_13880);
    env = stack[-2];
    goto v_13871;
v_13872:
    v_13880 = stack[0];
    goto v_13873;
v_13874:
    goto v_13870;
v_13871:
    goto v_13872;
v_13873:
    v_13882 = cons(v_13881, v_13880);
    env = stack[-2];
    goto v_13863;
v_13864:
    v_13881 = stack[-1];
    goto v_13865;
v_13866:
    v_13880 = stack[0];
    goto v_13867;
v_13868:
    goto v_13862;
v_13863:
    goto v_13864;
v_13865:
    goto v_13866;
v_13867:
    {
        fn = elt(env, 2); // cl_susiupdknowl2
        return (*qfnn(fn))(fn, 3, v_13882, v_13881, v_13880);
    }
    v_13880 = nil;
    return onevalue(v_13880);
}



// Code for vdp_setsugar

static LispObject CC_vdp_setsugar(LispObject env,
                         LispObject v_13825, LispObject v_13826)
{
    env = qenv(env);
    LispObject v_13847, v_13848, v_13849;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13847 = v_13826;
    v_13849 = v_13825;
// end of prologue
    v_13848 = qvalue(elt(env, 1)); // !*cgbsugar
    if (v_13848 == nil) goto v_13830;
    else goto v_13831;
v_13830:
    v_13847 = v_13849;
    goto v_13829;
v_13831:
    goto v_13843;
v_13837:
    goto v_13838;
v_13839:
    v_13848 = elt(env, 2); // sugar
    goto v_13840;
v_13841:
    goto v_13842;
v_13843:
    goto v_13837;
v_13838:
    goto v_13839;
v_13840:
    goto v_13841;
v_13842:
    {
        fn = elt(env, 3); // vdp_putprop
        return (*qfnn(fn))(fn, 3, v_13849, v_13848, v_13847);
    }
    v_13847 = nil;
v_13829:
    return onevalue(v_13847);
}



// Code for rl_updcache

static LispObject CC_rl_updcache(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13942, v_13943;
    argcheck(nargs, 0, "rl_updcache");
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
    v_13942 = qvalue(elt(env, 1)); // rl_bbl!*
    stack[0] = v_13942;
v_13829:
    v_13942 = stack[0];
    if (v_13942 == nil) goto v_13833;
    else goto v_13834;
v_13833:
    goto v_13828;
v_13834:
    v_13942 = stack[0];
    v_13942 = qcar(v_13942);
    goto v_13845;
v_13841:
    v_13943 = v_13942;
    goto v_13842;
v_13843:
    v_13942 = nil;
    goto v_13844;
v_13845:
    goto v_13841;
v_13842:
    goto v_13843;
v_13844:
    v_13942 = Lset(nil, v_13943, v_13942);
    env = stack[-1];
    v_13942 = stack[0];
    v_13942 = qcdr(v_13942);
    stack[0] = v_13942;
    goto v_13829;
v_13828:
    goto v_13859;
v_13855:
    v_13942 = qvalue(elt(env, 2)); // rl_cid!*
    v_13943 = qcar(v_13942);
    goto v_13856;
v_13857:
    v_13942 = elt(env, 3); // rl_params
    goto v_13858;
v_13859:
    goto v_13855;
v_13856:
    goto v_13857;
v_13858:
    v_13942 = get(v_13943, v_13942);
    env = stack[-1];
    stack[0] = v_13942;
v_13853:
    v_13942 = stack[0];
    if (v_13942 == nil) goto v_13865;
    else goto v_13866;
v_13865:
    goto v_13852;
v_13866:
    v_13942 = stack[0];
    v_13942 = qcar(v_13942);
    goto v_13877;
v_13873:
    v_13943 = v_13942;
    v_13943 = qcar(v_13943);
    goto v_13874;
v_13875:
    v_13942 = qcdr(v_13942);
    goto v_13876;
v_13877:
    goto v_13873;
v_13874:
    goto v_13875;
v_13876:
    v_13942 = Lset(nil, v_13943, v_13942);
    env = stack[-1];
    v_13942 = stack[0];
    v_13942 = qcdr(v_13942);
    stack[0] = v_13942;
    goto v_13853;
v_13852:
    v_13942 = qvalue(elt(env, 4)); // rl_servl!*
    stack[0] = v_13942;
v_13887:
    v_13942 = stack[0];
    if (v_13942 == nil) goto v_13891;
    else goto v_13892;
v_13891:
    goto v_13886;
v_13892:
    v_13942 = stack[0];
    v_13942 = qcar(v_13942);
    goto v_13903;
v_13899:
    v_13943 = v_13942;
    goto v_13900;
v_13901:
    v_13942 = nil;
    goto v_13902;
v_13903:
    goto v_13899;
v_13900:
    goto v_13901;
v_13902:
    v_13942 = Lset(nil, v_13943, v_13942);
    env = stack[-1];
    v_13942 = stack[0];
    v_13942 = qcdr(v_13942);
    stack[0] = v_13942;
    goto v_13887;
v_13886:
    goto v_13917;
v_13913:
    v_13942 = qvalue(elt(env, 2)); // rl_cid!*
    v_13943 = qcar(v_13942);
    goto v_13914;
v_13915:
    v_13942 = elt(env, 5); // rl_services
    goto v_13916;
v_13917:
    goto v_13913;
v_13914:
    goto v_13915;
v_13916:
    v_13942 = get(v_13943, v_13942);
    env = stack[-1];
    stack[0] = v_13942;
v_13911:
    v_13942 = stack[0];
    if (v_13942 == nil) goto v_13923;
    else goto v_13924;
v_13923:
    v_13942 = nil;
    goto v_13910;
v_13924:
    v_13942 = stack[0];
    v_13942 = qcar(v_13942);
    goto v_13935;
v_13931:
    v_13943 = v_13942;
    v_13943 = qcar(v_13943);
    goto v_13932;
v_13933:
    v_13942 = qcdr(v_13942);
    goto v_13934;
v_13935:
    goto v_13931;
v_13932:
    goto v_13933;
v_13934:
    v_13942 = Lset(nil, v_13943, v_13942);
    env = stack[-1];
    v_13942 = stack[0];
    v_13942 = qcdr(v_13942);
    stack[0] = v_13942;
    goto v_13911;
v_13910:
    return onevalue(v_13942);
}



setup_type const u25_setup[] =
{
    {"polynomlistreduce",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_polynomlistreduce},
    {"rl_eqnrhskernels",        CC_rl_eqnrhskernels,TOO_MANY_1,WRONG_NO_1},
    {"pasf_vf",                 CC_pasf_vf,     TOO_MANY_1,    WRONG_NO_1},
    {"vdp_getprop",             TOO_FEW_2,      CC_vdp_getprop,WRONG_NO_2},
    {"unaryrd",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_unaryrd},
    {"rationalizesq",           CC_rationalizesq,TOO_MANY_1,   WRONG_NO_1},
    {"dipev2f",                 TOO_FEW_2,      CC_dipev2f,    WRONG_NO_2},
    {"cos*",                    CC_cosH,        TOO_MANY_1,    WRONG_NO_1},
    {"flatindl",                CC_flatindl,    TOO_MANY_1,    WRONG_NO_1},
    {"impartf",                 CC_impartf,     TOO_MANY_1,    WRONG_NO_1},
    {"red_topredbe",            TOO_FEW_2,      CC_red_topredbe,WRONG_NO_2},
    {"gcdout",                  CC_gcdout,      TOO_MANY_1,    WRONG_NO_1},
    {"numlist_ordp",            TOO_FEW_2,      CC_numlist_ordp,WRONG_NO_2},
    {"lambda_ygm6np4pcqv31",    TOO_FEW_2,      CC_lambda_ygm6np4pcqv31,WRONG_NO_2},
    {"ilog2",                   CC_ilog2,       TOO_MANY_1,    WRONG_NO_1},
    {"let2",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_let2},
    {"remlocs",                 CC_remlocs,     TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_ignshift",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_ignshift},
    {"cl_pnf",                  CC_cl_pnf,      TOO_MANY_1,    WRONG_NO_1},
    {"expnd",                   CC_expnd,       TOO_MANY_1,    WRONG_NO_1},
    {"pasf_mkpos",              CC_pasf_mkpos,  TOO_MANY_1,    WRONG_NO_1},
    {"diff-k-times-mod-p",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_diffKkKtimesKmodKp},
    {"row",                     CC_row,         TOO_MANY_1,    WRONG_NO_1},
    {":dmpluslst",              CC_Tdmpluslst,  TOO_MANY_1,    WRONG_NO_1},
    {"mktails1",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mktails1},
    {"cde_position",            TOO_FEW_2,      CC_cde_position,WRONG_NO_2},
    {"riv_mk",                  TOO_FEW_2,      CC_riv_mk,     WRONG_NO_2},
    {"lalr_prin_production",    CC_lalr_prin_production,TOO_MANY_1,WRONG_NO_1},
    {"rlis",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rlis},
    {"tripleisprolongedby",     TOO_FEW_2,      CC_tripleisprolongedby,WRONG_NO_2},
    {"ofsf_smupdknowl",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smupdknowl},
    {"evaluatecoeffts",         TOO_FEW_2,      CC_evaluatecoeffts,WRONG_NO_2},
    {"cl_smsimpl-junct1",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_smsimplKjunct1},
    {"mri_prepat",              CC_mri_prepat,  TOO_MANY_1,    WRONG_NO_1},
    {"distribute.multiplicity", TOO_FEW_2,      CC_distributeQmultiplicity,WRONG_NO_2},
    {"bvarml",                  CC_bvarml,      TOO_MANY_1,    WRONG_NO_1},
    {"bcneg",                   CC_bcneg,       TOO_MANY_1,    WRONG_NO_1},
    {"ev-denom2",               TOO_FEW_2,      CC_evKdenom2,  WRONG_NO_2},
    {"comblog",                 CC_comblog,     TOO_MANY_1,    WRONG_NO_1},
    {"copy-tree",               CC_copyKtree,   TOO_MANY_1,    WRONG_NO_1},
    {"merge",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_merge},
    {"safe-modrecip",           CC_safeKmodrecip,TOO_MANY_1,   WRONG_NO_1},
    {"setk_super_vectorfield",  TOO_FEW_2,      CC_setk_super_vectorfield,WRONG_NO_2},
    {"lex_cleanup",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex_cleanup},
    {"gcref_mkgraph-tgf",       CC_gcref_mkgraphKtgf,TOO_MANY_1,WRONG_NO_1},
    {"cl_f2ml",                 TOO_FEW_2,      CC_cl_f2ml,    WRONG_NO_2},
    {"settinsert",              CC_settinsert,  TOO_MANY_1,    WRONG_NO_1},
    {"texstrlen",               CC_texstrlen,   TOO_MANY_1,    WRONG_NO_1},
    {"cl_susiupdknowl1",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_susiupdknowl1},
    {"vdp_setsugar",            TOO_FEW_2,      CC_vdp_setsugar,WRONG_NO_2},
    {"rl_updcache",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rl_updcache},
    {NULL, (one_args *)"u25", (two_args *)"149423 5673073 6413632", 0}
};

// end of generated code
