
// $destdir/u45.c        Machine generated C code

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



// Code for factor!-prim!-sqfree!-f

static LispObject CC_factorKprimKsqfreeKf(LispObject env,
                         LispObject v_26766)
{
    env = qenv(env);
    LispObject v_27099, v_27100, v_27101;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_26766);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_26766;
// end of prologue
// Binding !*msg
// FLUIDBIND: reloadenv=8 litvec-offset=1 saveloc=7
{   bind_fluid_stack bind_fluid_var(-8, 1, -7);
    qvalue(elt(env, 1)) = nil; // !*msg
    v_27099 = qvalue(elt(env, 2)); // !*rounded
    stack[-5] = v_27099;
    v_27099 = stack[-5];
    if (v_27099 == nil) goto v_26779;
    v_27099 = stack[-6];
    v_27099 = qcar(v_27099);
    fn = elt(env, 13); // univariatep
    v_27099 = (*qfn1(fn))(fn, v_27099);
    env = stack[-8];
    if (v_27099 == nil) goto v_26779;
    goto v_26796;
v_26792:
    v_27099 = stack[-6];
    v_27099 = qcar(v_27099);
    v_27099 = qcar(v_27099);
    v_27100 = qcdr(v_27099);
    goto v_26793;
v_26794:
    v_27099 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26795;
v_26796:
    goto v_26792;
v_26793:
    goto v_26794;
v_26795:
    if (v_27100 == v_27099) goto v_26790;
    else goto v_26791;
v_26790:
    goto v_26806;
v_26802:
    v_27099 = stack[-6];
    v_27100 = qcdr(v_27099);
    goto v_26803;
v_26804:
    v_27099 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26805;
v_26806:
    goto v_26802;
v_26803:
    goto v_26804;
v_26805:
    v_27099 = (v_27100 == v_27099 ? lisp_true : nil);
    goto v_26789;
v_26791:
    v_27099 = nil;
    goto v_26789;
    v_27099 = nil;
v_26789:
    if (v_27099 == nil) goto v_26779;
    v_27099 = stack[-6];
    fn = elt(env, 14); // unifactor
    v_27099 = (*qfn1(fn))(fn, v_27099);
    goto v_26773;
v_26779:
    v_27099 = stack[-5];
    if (v_27099 == nil) goto v_26818;
    else goto v_26816;
v_26818:
    v_27099 = qvalue(elt(env, 3)); // !*complex
    if (v_27099 == nil) goto v_26821;
    else goto v_26816;
v_26821:
    v_27099 = qvalue(elt(env, 4)); // !*rational
    if (v_27099 == nil) goto v_26823;
    else goto v_26816;
v_26823:
    goto v_26817;
v_26816:
    v_27099 = stack[-5];
    if (v_27099 == nil) goto v_26828;
    v_27099 = elt(env, 5); // rational
    v_27099 = ncons(v_27099);
    env = stack[-8];
    fn = elt(env, 15); // on
    v_27099 = (*qfn1(fn))(fn, v_27099);
    env = stack[-8];
    goto v_26826;
v_26828:
v_26826:
    goto v_26838;
v_26834:
    goto v_26845;
v_26841:
    v_27099 = stack[-6];
    v_27100 = qcar(v_27099);
    goto v_26842;
v_26843:
    v_27099 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26844;
v_26845:
    goto v_26841;
v_26842:
    goto v_26843;
v_26844:
    v_27099 = cons(v_27100, v_27099);
    env = stack[-8];
    fn = elt(env, 16); // resimp
    v_27099 = (*qfn1(fn))(fn, v_27099);
    env = stack[-8];
    v_27100 = qcar(v_27099);
    goto v_26835;
v_26836:
    v_27099 = stack[-6];
    v_27099 = qcdr(v_27099);
    goto v_26837;
v_26838:
    goto v_26834;
v_26835:
    goto v_26836;
v_26837:
    v_27099 = cons(v_27100, v_27099);
    env = stack[-8];
    stack[-6] = v_27099;
    goto v_26777;
v_26817:
v_26777:
    v_27099 = qvalue(elt(env, 6)); // !*limitedfactors
    if (v_27099 == nil) goto v_26854;
    else goto v_26855;
v_26854:
    v_27099 = qvalue(elt(env, 7)); // dmode!*
    if (v_27099 == nil) goto v_26859;
    else goto v_26860;
v_26859:
    v_27099 = elt(env, 8); // internal!-factorf
    stack[0] = v_27099;
    goto v_26858;
v_26860:
    goto v_26870;
v_26866:
    v_27100 = qvalue(elt(env, 7)); // dmode!*
    goto v_26867;
v_26868:
    v_27099 = elt(env, 9); // sqfrfactorfn
    goto v_26869;
v_26870:
    goto v_26866;
v_26867:
    goto v_26868;
v_26869:
    v_27099 = get(v_27100, v_27099);
    env = stack[-8];
    v_27101 = v_27099;
    goto v_26878;
v_26874:
    v_27100 = qvalue(elt(env, 7)); // dmode!*
    goto v_26875;
v_26876:
    v_27099 = elt(env, 10); // factorfn
    goto v_26877;
v_26878:
    goto v_26874;
v_26875:
    goto v_26876;
v_26877:
    v_27099 = get(v_27100, v_27099);
    env = stack[-8];
    stack[0] = v_27099;
    v_27099 = v_27101;
    if (v_27099 == nil) goto v_26884;
    goto v_26892;
v_26888:
    v_27100 = v_27101;
    goto v_26889;
v_26890:
    v_27099 = stack[0];
    goto v_26891;
v_26892:
    goto v_26888;
v_26889:
    goto v_26890;
v_26891:
    if (v_27100 == v_27099) goto v_26884;
    v_27099 = elt(env, 8); // internal!-factorf
    stack[0] = v_27099;
    goto v_26882;
v_26884:
    goto v_26902;
v_26898:
    v_27100 = stack[0];
    goto v_26899;
v_26900:
    v_27099 = elt(env, 11); // factorf
    goto v_26901;
v_26902:
    goto v_26898;
v_26899:
    goto v_26900;
v_26901:
    if (v_27100 == v_27099) goto v_26896;
    else goto v_26897;
v_26896:
    v_27099 = elt(env, 8); // internal!-factorf
    stack[0] = v_27099;
    goto v_26882;
v_26897:
v_26882:
    goto v_26858;
v_26858:
    v_27099 = stack[0];
    if (v_27099 == nil) goto v_26909;
    goto v_26916;
v_26912:
    v_27100 = stack[0];
    goto v_26913;
v_26914:
    v_27099 = stack[-6];
    v_27099 = qcar(v_27099);
    goto v_26915;
v_26916:
    goto v_26912;
v_26913:
    goto v_26914;
v_26915:
    v_27099 = Lapply1(nil, v_27100, v_27099);
    env = stack[-8];
    stack[0] = v_27099;
    goto v_26925;
v_26921:
    goto v_26931;
v_26927:
    v_27099 = stack[0];
    v_27100 = qcar(v_27099);
    goto v_26928;
v_26929:
    v_27099 = stack[-6];
    v_27099 = qcdr(v_27099);
    goto v_26930;
v_26931:
    goto v_26927;
v_26928:
    goto v_26929;
v_26930:
    fn = elt(env, 17); // exptf
    stack[-4] = (*qfn2(fn))(fn, v_27100, v_27099);
    env = stack[-8];
    goto v_26922;
v_26923:
    v_27099 = stack[0];
    v_27099 = qcdr(v_27099);
    stack[-3] = v_27099;
    v_27099 = stack[-3];
    if (v_27099 == nil) goto v_26946;
    else goto v_26947;
v_26946:
    v_27099 = nil;
    goto v_26940;
v_26947:
    v_27099 = stack[-3];
    v_27099 = qcar(v_27099);
    goto v_26959;
v_26955:
    v_27100 = qcar(v_27099);
    goto v_26956;
v_26957:
    v_27099 = stack[-6];
    v_27099 = qcdr(v_27099);
    goto v_26958;
v_26959:
    goto v_26955;
v_26956:
    goto v_26957;
v_26958:
    v_27099 = cons(v_27100, v_27099);
    env = stack[-8];
    v_27099 = ncons(v_27099);
    env = stack[-8];
    stack[-1] = v_27099;
    stack[-2] = v_27099;
v_26941:
    v_27099 = stack[-3];
    v_27099 = qcdr(v_27099);
    stack[-3] = v_27099;
    v_27099 = stack[-3];
    if (v_27099 == nil) goto v_26968;
    else goto v_26969;
v_26968:
    v_27099 = stack[-2];
    goto v_26940;
v_26969:
    goto v_26977;
v_26973:
    stack[0] = stack[-1];
    goto v_26974;
v_26975:
    v_27099 = stack[-3];
    v_27099 = qcar(v_27099);
    goto v_26988;
v_26984:
    v_27100 = qcar(v_27099);
    goto v_26985;
v_26986:
    v_27099 = stack[-6];
    v_27099 = qcdr(v_27099);
    goto v_26987;
v_26988:
    goto v_26984;
v_26985:
    goto v_26986;
v_26987:
    v_27099 = cons(v_27100, v_27099);
    env = stack[-8];
    v_27099 = ncons(v_27099);
    env = stack[-8];
    goto v_26976;
v_26977:
    goto v_26973;
v_26974:
    goto v_26975;
v_26976:
    v_27099 = Lrplacd(nil, stack[0], v_27099);
    env = stack[-8];
    v_27099 = stack[-1];
    v_27099 = qcdr(v_27099);
    stack[-1] = v_27099;
    goto v_26941;
v_26940:
    goto v_26924;
v_26925:
    goto v_26921;
v_26922:
    goto v_26923;
v_26924:
    v_27099 = cons(stack[-4], v_27099);
    env = stack[-8];
    stack[-6] = v_27099;
    goto v_26774;
v_26909:
    goto v_26853;
v_26855:
v_26853:
    goto v_27000;
v_26996:
    v_27099 = stack[-6];
    v_27100 = qcar(v_27099);
    goto v_26997;
v_26998:
    v_27099 = stack[-6];
    v_27099 = qcdr(v_27099);
    goto v_26999;
v_27000:
    goto v_26996;
v_26997:
    goto v_26998;
v_26999:
    fn = elt(env, 18); // factor!-prim!-sqfree!-f!-1
    v_27099 = (*qfn2(fn))(fn, v_27100, v_27099);
    env = stack[-8];
    stack[-6] = v_27099;
v_26774:
    v_27099 = stack[-5];
    if (v_27099 == nil) goto v_27008;
    v_27099 = elt(env, 12); // rounded
    v_27099 = ncons(v_27099);
    env = stack[-8];
    fn = elt(env, 15); // on
    v_27099 = (*qfn1(fn))(fn, v_27099);
    env = stack[-8];
    goto v_27018;
v_27014:
    v_27099 = stack[-6];
    stack[-4] = qcar(v_27099);
    goto v_27015;
v_27016:
    v_27099 = stack[-6];
    v_27099 = qcdr(v_27099);
    stack[-5] = v_27099;
    v_27099 = stack[-5];
    if (v_27099 == nil) goto v_27031;
    else goto v_27032;
v_27031:
    v_27099 = nil;
    goto v_27025;
v_27032:
    v_27099 = stack[-5];
    v_27099 = qcar(v_27099);
    stack[0] = v_27099;
    goto v_27044;
v_27040:
    goto v_27051;
v_27047:
    v_27099 = stack[0];
    v_27100 = qcar(v_27099);
    goto v_27048;
v_27049:
    v_27099 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27050;
v_27051:
    goto v_27047;
v_27048:
    goto v_27049;
v_27050:
    v_27099 = cons(v_27100, v_27099);
    env = stack[-8];
    fn = elt(env, 16); // resimp
    v_27099 = (*qfn1(fn))(fn, v_27099);
    env = stack[-8];
    v_27100 = qcar(v_27099);
    goto v_27041;
v_27042:
    v_27099 = stack[0];
    v_27099 = qcdr(v_27099);
    goto v_27043;
v_27044:
    goto v_27040;
v_27041:
    goto v_27042;
v_27043:
    v_27099 = cons(v_27100, v_27099);
    env = stack[-8];
    v_27099 = ncons(v_27099);
    env = stack[-8];
    stack[-2] = v_27099;
    stack[-3] = v_27099;
v_27026:
    v_27099 = stack[-5];
    v_27099 = qcdr(v_27099);
    stack[-5] = v_27099;
    v_27099 = stack[-5];
    if (v_27099 == nil) goto v_27062;
    else goto v_27063;
v_27062:
    v_27099 = stack[-3];
    goto v_27025;
v_27063:
    goto v_27071;
v_27067:
    stack[-1] = stack[-2];
    goto v_27068;
v_27069:
    v_27099 = stack[-5];
    v_27099 = qcar(v_27099);
    stack[0] = v_27099;
    goto v_27082;
v_27078:
    goto v_27089;
v_27085:
    v_27099 = stack[0];
    v_27100 = qcar(v_27099);
    goto v_27086;
v_27087:
    v_27099 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27088;
v_27089:
    goto v_27085;
v_27086:
    goto v_27087;
v_27088:
    v_27099 = cons(v_27100, v_27099);
    env = stack[-8];
    fn = elt(env, 16); // resimp
    v_27099 = (*qfn1(fn))(fn, v_27099);
    env = stack[-8];
    v_27100 = qcar(v_27099);
    goto v_27079;
v_27080:
    v_27099 = stack[0];
    v_27099 = qcdr(v_27099);
    goto v_27081;
v_27082:
    goto v_27078;
v_27079:
    goto v_27080;
v_27081:
    v_27099 = cons(v_27100, v_27099);
    env = stack[-8];
    v_27099 = ncons(v_27099);
    env = stack[-8];
    goto v_27070;
v_27071:
    goto v_27067;
v_27068:
    goto v_27069;
v_27070:
    v_27099 = Lrplacd(nil, stack[-1], v_27099);
    env = stack[-8];
    v_27099 = stack[-2];
    v_27099 = qcdr(v_27099);
    stack[-2] = v_27099;
    goto v_27026;
v_27025:
    goto v_27017;
v_27018:
    goto v_27014;
v_27015:
    goto v_27016;
v_27017:
    v_27099 = cons(stack[-4], v_27099);
    stack[-6] = v_27099;
    goto v_27006;
v_27008:
v_27006:
    v_27099 = stack[-6];
v_26773:
    ;}  // end of a binding scope
    return onevalue(v_27099);
}



// Code for findhc

static LispObject CC_findhc(LispObject env,
                         LispObject v_26766)
{
    env = qenv(env);
    LispObject v_26890, v_26891;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_26766);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_26890 = v_26766;
// end of prologue
    stack[-4] = nil;
    v_26891 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_26891; // njsi
    stack[-2] = v_26891;
    v_26891 = nil;
    qvalue(elt(env, 2)) = v_26891; // jsi
    goto v_26784;
v_26780:
    goto v_26789;
v_26785:
    stack[0] = qvalue(elt(env, 3)); // codmat
    goto v_26786;
v_26787:
    goto v_26796;
v_26792:
    v_26891 = qvalue(elt(env, 4)); // maxvar
    goto v_26793;
v_26794:
    goto v_26795;
v_26796:
    goto v_26792;
v_26793:
    goto v_26794;
v_26795:
    v_26890 = plus2(v_26891, v_26890);
    env = stack[-5];
    goto v_26788;
v_26789:
    goto v_26785;
v_26786:
    goto v_26787;
v_26788:
    v_26891 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_26890-TAG_FIXNUM)/(16/CELL)));
    goto v_26781;
v_26782:
    v_26890 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_26783;
v_26784:
    goto v_26780;
v_26781:
    goto v_26782;
v_26783:
    v_26890 = *(LispObject *)((char *)v_26891 + (CELL-TAG_VECTOR) + (((intptr_t)v_26890-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_26890;
v_26779:
    v_26890 = stack[-1];
    if (v_26890 == nil) goto v_26804;
    else goto v_26805;
v_26804:
    goto v_26778;
v_26805:
    v_26890 = stack[-1];
    v_26890 = qcar(v_26890);
    goto v_26819;
v_26815:
    goto v_26824;
v_26820:
    stack[0] = qvalue(elt(env, 3)); // codmat
    goto v_26821;
v_26822:
    goto v_26831;
v_26827:
    v_26891 = qvalue(elt(env, 4)); // maxvar
    goto v_26828;
v_26829:
    v_26890 = qcar(v_26890);
    stack[-3] = v_26890;
    goto v_26830;
v_26831:
    goto v_26827;
v_26828:
    goto v_26829;
v_26830:
    v_26890 = plus2(v_26891, v_26890);
    env = stack[-5];
    goto v_26823;
v_26824:
    goto v_26820;
v_26821:
    goto v_26822;
v_26823:
    v_26891 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_26890-TAG_FIXNUM)/(16/CELL)));
    goto v_26816;
v_26817:
    v_26890 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_26818;
v_26819:
    goto v_26815;
v_26816:
    goto v_26817;
v_26818:
    v_26890 = *(LispObject *)((char *)v_26891 + (CELL-TAG_VECTOR) + (((intptr_t)v_26890-TAG_FIXNUM)/(16/CELL)));
    if (v_26890 == nil) goto v_26814;
    goto v_26843;
v_26839:
    v_26891 = stack[-3];
    goto v_26840;
v_26841:
    v_26890 = qvalue(elt(env, 2)); // jsi
    goto v_26842;
v_26843:
    goto v_26839;
v_26840:
    goto v_26841;
v_26842:
    v_26890 = cons(v_26891, v_26890);
    env = stack[-5];
    qvalue(elt(env, 2)) = v_26890; // jsi
    v_26890 = qvalue(elt(env, 1)); // njsi
    v_26890 = add1(v_26890);
    env = stack[-5];
    qvalue(elt(env, 1)) = v_26890; // njsi
    goto v_26857;
v_26853:
    goto v_26862;
v_26858:
    goto v_26867;
v_26863:
    stack[0] = qvalue(elt(env, 3)); // codmat
    goto v_26864;
v_26865:
    goto v_26874;
v_26870:
    v_26891 = qvalue(elt(env, 4)); // maxvar
    goto v_26871;
v_26872:
    v_26890 = stack[-3];
    goto v_26873;
v_26874:
    goto v_26870;
v_26871:
    goto v_26872;
v_26873:
    v_26890 = plus2(v_26891, v_26890);
    env = stack[-5];
    goto v_26866;
v_26867:
    goto v_26863;
v_26864:
    goto v_26865;
v_26866:
    v_26891 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_26890-TAG_FIXNUM)/(16/CELL)));
    goto v_26859;
v_26860:
    v_26890 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26861;
v_26862:
    goto v_26858;
v_26859:
    goto v_26860;
v_26861:
    v_26890 = *(LispObject *)((char *)v_26891 + (CELL-TAG_VECTOR) + (((intptr_t)v_26890-TAG_FIXNUM)/(16/CELL)));
    v_26890 = qcar(v_26890);
    v_26891 = qcar(v_26890);
    stack[0] = v_26891;
    goto v_26854;
v_26855:
    v_26890 = stack[-2];
    goto v_26856;
v_26857:
    goto v_26853;
v_26854:
    goto v_26855;
v_26856:
    v_26890 = (LispObject)greaterp2(v_26891, v_26890);
    v_26890 = v_26890 ? lisp_true : nil;
    env = stack[-5];
    if (v_26890 == nil) goto v_26851;
    v_26890 = stack[0];
    stack[-2] = v_26890;
    v_26890 = stack[-3];
    stack[-4] = v_26890;
    goto v_26849;
v_26851:
v_26849:
    goto v_26812;
v_26814:
v_26812:
    v_26890 = stack[-1];
    v_26890 = qcdr(v_26890);
    stack[-1] = v_26890;
    goto v_26779;
v_26778:
    v_26890 = qvalue(elt(env, 2)); // jsi
    v_26890 = Lreverse(nil, v_26890);
    env = stack[-5];
    qvalue(elt(env, 2)) = v_26890; // jsi
    v_26890 = stack[-4];
    return onevalue(v_26890);
}



// Code for dipdivmon

static LispObject CC_dipdivmon(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_26819, v_26820;
    LispObject fn;
    LispObject v_26768, v_26767, v_26766;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dipdivmon");
    va_start(aa, nargs);
    v_26766 = va_arg(aa, LispObject);
    v_26767 = va_arg(aa, LispObject);
    v_26768 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_26768,v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_26766,v_26767,v_26768);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_26768;
    stack[-1] = v_26767;
    stack[-2] = v_26766;
// end of prologue
    stack[-3] = nil;
v_26773:
    v_26819 = stack[-2];
    if (v_26819 == nil) goto v_26776;
    else goto v_26777;
v_26776:
    v_26819 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_26819);
    }
v_26777:
    goto v_26788;
v_26784:
    goto v_26794;
v_26790:
    v_26819 = stack[-2];
    v_26820 = qcar(v_26819);
    goto v_26791;
v_26792:
    v_26819 = stack[0];
    goto v_26793;
v_26794:
    goto v_26790;
v_26791:
    goto v_26792;
v_26793:
    fn = elt(env, 2); // evdif
    v_26820 = (*qfn2(fn))(fn, v_26820, v_26819);
    env = stack[-4];
    goto v_26785;
v_26786:
    v_26819 = stack[-3];
    goto v_26787;
v_26788:
    goto v_26784;
v_26785:
    goto v_26786;
v_26787:
    v_26819 = cons(v_26820, v_26819);
    env = stack[-4];
    stack[-3] = v_26819;
    goto v_26804;
v_26800:
    goto v_26810;
v_26806:
    v_26819 = stack[-2];
    v_26819 = qcdr(v_26819);
    v_26820 = qcar(v_26819);
    goto v_26807;
v_26808:
    v_26819 = stack[-1];
    goto v_26809;
v_26810:
    goto v_26806;
v_26807:
    goto v_26808;
v_26809:
    fn = elt(env, 3); // bcquot
    v_26820 = (*qfn2(fn))(fn, v_26820, v_26819);
    env = stack[-4];
    goto v_26801;
v_26802:
    v_26819 = stack[-3];
    goto v_26803;
v_26804:
    goto v_26800;
v_26801:
    goto v_26802;
v_26803:
    v_26819 = cons(v_26820, v_26819);
    env = stack[-4];
    stack[-3] = v_26819;
    v_26819 = stack[-2];
    v_26819 = qcdr(v_26819);
    v_26819 = qcdr(v_26819);
    stack[-2] = v_26819;
    goto v_26773;
    v_26819 = nil;
    return onevalue(v_26819);
}



// Code for gfftimes

static LispObject CC_gfftimes(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26833, v_26834, v_26835;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_26834 = v_26767;
    v_26835 = v_26766;
// end of prologue
    v_26833 = v_26835;
    v_26833 = qcar(v_26833);
    stack[-4] = v_26833;
    v_26833 = v_26835;
    v_26833 = qcdr(v_26833);
    stack[-3] = v_26833;
    v_26833 = v_26834;
    v_26833 = qcar(v_26833);
    stack[-2] = v_26833;
    v_26833 = v_26834;
    v_26833 = qcdr(v_26833);
    stack[-1] = v_26833;
    goto v_26788;
v_26784:
    goto v_26794;
v_26790:
    goto v_26800;
v_26796:
    v_26834 = stack[-4];
    goto v_26797;
v_26798:
    v_26833 = stack[-2];
    goto v_26799;
v_26800:
    goto v_26796;
v_26797:
    goto v_26798;
v_26799:
    stack[0] = times2(v_26834, v_26833);
    env = stack[-5];
    goto v_26791;
v_26792:
    goto v_26808;
v_26804:
    v_26834 = stack[-3];
    goto v_26805;
v_26806:
    v_26833 = stack[-1];
    goto v_26807;
v_26808:
    goto v_26804;
v_26805:
    goto v_26806;
v_26807:
    v_26833 = times2(v_26834, v_26833);
    env = stack[-5];
    goto v_26793;
v_26794:
    goto v_26790;
v_26791:
    goto v_26792;
v_26793:
    stack[0] = difference2(stack[0], v_26833);
    env = stack[-5];
    goto v_26785;
v_26786:
    goto v_26816;
v_26812:
    goto v_26822;
v_26818:
    v_26834 = stack[-4];
    goto v_26819;
v_26820:
    v_26833 = stack[-1];
    goto v_26821;
v_26822:
    goto v_26818;
v_26819:
    goto v_26820;
v_26821:
    stack[-1] = times2(v_26834, v_26833);
    env = stack[-5];
    goto v_26813;
v_26814:
    goto v_26830;
v_26826:
    v_26834 = stack[-3];
    goto v_26827;
v_26828:
    v_26833 = stack[-2];
    goto v_26829;
v_26830:
    goto v_26826;
v_26827:
    goto v_26828;
v_26829:
    v_26833 = times2(v_26834, v_26833);
    env = stack[-5];
    goto v_26815;
v_26816:
    goto v_26812;
v_26813:
    goto v_26814;
v_26815:
    v_26833 = plus2(stack[-1], v_26833);
    goto v_26787;
v_26788:
    goto v_26784;
v_26785:
    goto v_26786;
v_26787:
    {
        LispObject v_26841 = stack[0];
        return cons(v_26841, v_26833);
    }
    return onevalue(v_26833);
}



// Code for new_prove

static LispObject CC_new_prove(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26805, v_26806;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_26767;
    stack[-1] = v_26766;
// end of prologue
v_26765:
    v_26805 = stack[0];
    if (v_26805 == nil) goto v_26771;
    else goto v_26772;
v_26771:
    v_26805 = nil;
    goto v_26770;
v_26772:
    goto v_26782;
v_26778:
    v_26806 = stack[-1];
    goto v_26779;
v_26780:
    v_26805 = stack[0];
    v_26805 = qcar(v_26805);
    goto v_26781;
v_26782:
    goto v_26778;
v_26779:
    goto v_26780;
v_26781:
    fn = elt(env, 1); // new_provev
    v_26805 = (*qfn2(fn))(fn, v_26806, v_26805);
    env = stack[-2];
    v_26806 = v_26805;
    v_26805 = v_26806;
    if (v_26805 == nil) goto v_26790;
    v_26805 = v_26806;
    return ncons(v_26805);
v_26790:
    goto v_26801;
v_26797:
    v_26806 = stack[-1];
    goto v_26798;
v_26799:
    v_26805 = stack[0];
    v_26805 = qcdr(v_26805);
    goto v_26800;
v_26801:
    goto v_26797;
v_26798:
    goto v_26799;
v_26800:
    stack[-1] = v_26806;
    stack[0] = v_26805;
    goto v_26765;
    v_26805 = nil;
    goto v_26770;
    v_26805 = nil;
v_26770:
    return onevalue(v_26805);
}



// Code for mkrepart

static LispObject CC_mkrepart(LispObject env,
                         LispObject v_26766)
{
    env = qenv(env);
    LispObject v_26827, v_26828;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_26766);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_26766;
// end of prologue
    v_26827 = stack[0];
    fn = elt(env, 2); // realvaluedp
    v_26827 = (*qfn1(fn))(fn, v_26827);
    env = stack[-1];
    if (v_26827 == nil) goto v_26771;
    goto v_26779;
v_26775:
    goto v_26786;
v_26782:
    goto v_26792;
v_26788:
    v_26828 = stack[0];
    goto v_26789;
v_26790:
    v_26827 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26791;
v_26792:
    goto v_26788;
v_26789:
    goto v_26790;
v_26791:
    fn = elt(env, 3); // to
    v_26828 = (*qfn2(fn))(fn, v_26828, v_26827);
    env = stack[-1];
    goto v_26783;
v_26784:
    v_26827 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26785;
v_26786:
    goto v_26782;
v_26783:
    goto v_26784;
v_26785:
    v_26827 = cons(v_26828, v_26827);
    env = stack[-1];
    v_26828 = ncons(v_26827);
    goto v_26776;
v_26777:
    v_26827 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26778;
v_26779:
    goto v_26775;
v_26776:
    goto v_26777;
v_26778:
    return cons(v_26828, v_26827);
v_26771:
    v_26827 = stack[0];
    fn = elt(env, 4); // sfp
    v_26827 = (*qfn1(fn))(fn, v_26827);
    env = stack[-1];
    if (v_26827 == nil) goto v_26798;
    goto v_26807;
v_26803:
    v_26828 = stack[0];
    goto v_26804;
v_26805:
    v_26827 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26806;
v_26807:
    goto v_26803;
v_26804:
    goto v_26805;
v_26806:
    v_26827 = cons(v_26828, v_26827);
    env = stack[-1];
    {
        fn = elt(env, 5); // repartsq
        return (*qfn1(fn))(fn, v_26827);
    }
v_26798:
    goto v_26817;
v_26813:
    goto v_26823;
v_26819:
    v_26828 = elt(env, 1); // repart
    goto v_26820;
v_26821:
    v_26827 = stack[0];
    goto v_26822;
v_26823:
    goto v_26819;
v_26820:
    goto v_26821;
v_26822:
    v_26828 = list2(v_26828, v_26827);
    env = stack[-1];
    goto v_26814;
v_26815:
    v_26827 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26816;
v_26817:
    goto v_26813;
v_26814:
    goto v_26815;
v_26816:
    {
        fn = elt(env, 6); // mksq
        return (*qfn2(fn))(fn, v_26828, v_26827);
    }
    v_26827 = nil;
    return onevalue(v_26827);
}



// Code for prsum

static LispObject CC_prsum(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26814, v_26815, v_26816;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_26767;
    stack[-1] = v_26766;
// end of prologue
    stack[-2] = nil;
v_26772:
    v_26814 = stack[-1];
    if (v_26814 == nil) goto v_26775;
    else goto v_26776;
v_26775:
    v_26814 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_26814);
    }
v_26776:
    v_26814 = stack[0];
    v_26814 = qcar(v_26814);
    if (v_26814 == nil) goto v_26780;
    else goto v_26781;
v_26780:
    v_26814 = stack[-1];
    v_26814 = qcdr(v_26814);
    stack[-1] = v_26814;
    v_26814 = stack[0];
    v_26814 = qcdr(v_26814);
    stack[0] = v_26814;
    goto v_26772;
v_26781:
    goto v_26797;
v_26791:
    goto v_26803;
v_26799:
    v_26814 = stack[-1];
    v_26815 = qcar(v_26814);
    goto v_26800;
v_26801:
    v_26814 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26802;
v_26803:
    goto v_26799;
v_26800:
    goto v_26801;
v_26802:
    fn = elt(env, 2); // to
    v_26816 = (*qfn2(fn))(fn, v_26815, v_26814);
    env = stack[-3];
    goto v_26792;
v_26793:
    v_26814 = stack[0];
    v_26815 = qcar(v_26814);
    goto v_26794;
v_26795:
    v_26814 = stack[-2];
    goto v_26796;
v_26797:
    goto v_26791;
v_26792:
    goto v_26793;
v_26794:
    goto v_26795;
v_26796:
    v_26814 = acons(v_26816, v_26815, v_26814);
    env = stack[-3];
    stack[-2] = v_26814;
    v_26814 = stack[-1];
    v_26814 = qcdr(v_26814);
    stack[-1] = v_26814;
    v_26814 = stack[0];
    v_26814 = qcdr(v_26814);
    stack[0] = v_26814;
    goto v_26772;
    v_26814 = nil;
    return onevalue(v_26814);
}



// Code for rfirst

static LispObject CC_rfirst(LispObject env,
                         LispObject v_26766)
{
    env = qenv(env);
    LispObject v_26836, v_26837, v_26838;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_26766);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_26766;
// end of prologue
    v_26836 = stack[0];
    v_26836 = qcar(v_26836);
    fn = elt(env, 3); // reval
    v_26836 = (*qfn1(fn))(fn, v_26836);
    env = stack[-1];
    stack[0] = v_26836;
    fn = elt(env, 4); // bagp
    v_26836 = (*qfn1(fn))(fn, v_26836);
    env = stack[-1];
    if (v_26836 == nil) goto v_26771;
    v_26836 = stack[0];
    v_26836 = qcdr(v_26836);
    if (v_26836 == nil) goto v_26778;
    else goto v_26779;
v_26778:
    v_26836 = stack[0];
    v_26836 = qcar(v_26836);
    return ncons(v_26836);
v_26779:
    goto v_26794;
v_26788:
    v_26836 = stack[0];
    v_26838 = qcar(v_26836);
    goto v_26789;
v_26790:
    v_26836 = stack[0];
    v_26836 = qcdr(v_26836);
    v_26837 = qcar(v_26836);
    goto v_26791;
v_26792:
    v_26836 = nil;
    goto v_26793;
v_26794:
    goto v_26788;
v_26789:
    goto v_26790;
v_26791:
    goto v_26792;
v_26793:
    return list2star(v_26838, v_26837, v_26836);
    v_26836 = nil;
    goto v_26769;
v_26771:
    goto v_26807;
v_26803:
    v_26836 = stack[0];
    v_26837 = qcar(v_26836);
    goto v_26804;
v_26805:
    v_26836 = elt(env, 1); // list
    goto v_26806;
v_26807:
    goto v_26803;
v_26804:
    goto v_26805;
v_26806:
    if (v_26837 == v_26836) goto v_26802;
    goto v_26816;
v_26812:
    v_26837 = stack[0];
    goto v_26813;
v_26814:
    v_26836 = elt(env, 2); // "list or bag"
    goto v_26815;
v_26816:
    goto v_26812;
v_26813:
    goto v_26814;
v_26815:
    {
        fn = elt(env, 5); // typerr
        return (*qfn2(fn))(fn, v_26837, v_26836);
    }
v_26802:
    v_26836 = stack[0];
    v_26836 = qcdr(v_26836);
    if (v_26836 == nil) goto v_26819;
    else goto v_26820;
v_26819:
    goto v_26828;
v_26824:
    v_26837 = stack[0];
    goto v_26825;
v_26826:
    v_26836 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26827;
v_26828:
    goto v_26824;
v_26825:
    goto v_26826;
v_26827:
    {
        fn = elt(env, 6); // parterr
        return (*qfn2(fn))(fn, v_26837, v_26836);
    }
v_26820:
    v_26836 = stack[0];
    v_26836 = qcdr(v_26836);
    v_26836 = qcar(v_26836);
    goto v_26769;
    v_26836 = nil;
v_26769:
    return onevalue(v_26836);
}



// Code for subs2p

static LispObject CC_subs2p(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_26876, v_26877;
    LispObject fn;
    LispObject v_26768, v_26767, v_26766;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "subs2p");
    va_start(aa, nargs);
    v_26766 = va_arg(aa, LispObject);
    v_26767 = va_arg(aa, LispObject);
    v_26768 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_26768,v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_26766,v_26767,v_26768);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_26768;
    stack[-1] = v_26767;
    stack[-2] = v_26766;
// end of prologue
    v_26876 = stack[-2];
    v_26876 = qcdr(v_26876);
    v_26876 = integerp(v_26876);
    if (v_26876 == nil) goto v_26778;
    else goto v_26779;
v_26778:
    v_26876 = lisp_true;
    goto v_26777;
v_26779:
    goto v_26790;
v_26786:
    goto v_26796;
v_26792:
    v_26876 = stack[-2];
    v_26877 = qcdr(v_26876);
    goto v_26793;
v_26794:
    v_26876 = stack[-1];
    goto v_26795;
v_26796:
    goto v_26792;
v_26793:
    goto v_26794;
v_26795:
    v_26876 = Ldivide(nil, v_26877, v_26876);
    env = stack[-3];
    stack[-1] = v_26876;
    v_26877 = qcar(v_26876);
    goto v_26787;
v_26788:
    v_26876 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_26789;
v_26790:
    goto v_26786;
v_26787:
    goto v_26788;
v_26789:
    v_26876 = (v_26877 == v_26876 ? lisp_true : nil);
    goto v_26777;
    v_26876 = nil;
v_26777:
    if (v_26876 == nil) goto v_26775;
    goto v_26808;
v_26804:
    goto v_26815;
v_26811:
    v_26877 = stack[-2];
    goto v_26812;
v_26813:
    v_26876 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26814;
v_26815:
    goto v_26811;
v_26812:
    goto v_26813;
v_26814:
    v_26876 = cons(v_26877, v_26876);
    env = stack[-3];
    v_26877 = ncons(v_26876);
    goto v_26805;
v_26806:
    v_26876 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26807;
v_26808:
    goto v_26804;
v_26805:
    goto v_26806;
v_26807:
    return cons(v_26877, v_26876);
v_26775:
    goto v_26824;
v_26820:
    v_26876 = stack[0];
    fn = elt(env, 1); // simp
    v_26877 = (*qfn1(fn))(fn, v_26876);
    env = stack[-3];
    goto v_26821;
v_26822:
    v_26876 = stack[-1];
    v_26876 = qcar(v_26876);
    goto v_26823;
v_26824:
    goto v_26820;
v_26821:
    goto v_26822;
v_26823:
    fn = elt(env, 2); // exptsq
    v_26876 = (*qfn2(fn))(fn, v_26877, v_26876);
    env = stack[-3];
    stack[0] = v_26876;
    goto v_26837;
v_26833:
    v_26876 = stack[-1];
    v_26877 = qcdr(v_26876);
    goto v_26834;
v_26835:
    v_26876 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_26836;
v_26837:
    goto v_26833;
v_26834:
    goto v_26835;
v_26836:
    if (v_26877 == v_26876) goto v_26831;
    else goto v_26832;
v_26831:
    v_26876 = stack[0];
    goto v_26830;
v_26832:
    goto v_26849;
v_26845:
    goto v_26855;
v_26851:
    goto v_26862;
v_26858:
    goto v_26868;
v_26864:
    v_26876 = stack[-2];
    v_26877 = qcar(v_26876);
    goto v_26865;
v_26866:
    v_26876 = stack[-1];
    v_26876 = qcdr(v_26876);
    goto v_26867;
v_26868:
    goto v_26864;
v_26865:
    goto v_26866;
v_26867:
    fn = elt(env, 3); // to
    v_26877 = (*qfn2(fn))(fn, v_26877, v_26876);
    env = stack[-3];
    goto v_26859;
v_26860:
    v_26876 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26861;
v_26862:
    goto v_26858;
v_26859:
    goto v_26860;
v_26861:
    v_26876 = cons(v_26877, v_26876);
    env = stack[-3];
    v_26877 = ncons(v_26876);
    env = stack[-3];
    goto v_26852;
v_26853:
    v_26876 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26854;
v_26855:
    goto v_26851;
v_26852:
    goto v_26853;
v_26854:
    v_26877 = cons(v_26877, v_26876);
    env = stack[-3];
    goto v_26846;
v_26847:
    v_26876 = stack[0];
    goto v_26848;
v_26849:
    goto v_26845;
v_26846:
    goto v_26847;
v_26848:
    {
        fn = elt(env, 4); // multsq
        return (*qfn2(fn))(fn, v_26877, v_26876);
    }
    v_26876 = nil;
v_26830:
    return onevalue(v_26876);
}



// Code for settreset

static LispObject CC_settreset(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_26772;
    argcheck(nargs, 0, "settreset");
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
    v_26772 = nil;
    qvalue(elt(env, 1)) = v_26772; // fluidbibasisjanettreerootnode
    v_26772 = nil;
    v_26772 = ncons(v_26772);
    env = stack[0];
    qvalue(elt(env, 2)) = v_26772; // fluidbibasissett
    v_26772 = nil;
    return onevalue(v_26772);
}



// Code for pdiffvars

static LispObject CC_pdiffvars(LispObject env,
                         LispObject v_26767, LispObject v_26768)
{
    env = qenv(env);
    LispObject v_26805, v_26806;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26768,v_26767);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26767,v_26768);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_26768;
    v_26805 = v_26767;
// end of prologue
// Binding ind
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = v_26805; // ind
    v_26805 = qvalue(elt(env, 1)); // ind
    if (v_26805 == nil) goto v_26779;
    goto v_26786;
v_26782:
    goto v_26792;
v_26788:
    v_26806 = stack[-1];
    goto v_26789;
v_26790:
    v_26805 = qvalue(elt(env, 1)); // ind
    v_26805 = qcar(v_26805);
    goto v_26791;
v_26792:
    goto v_26788;
v_26789:
    goto v_26790;
v_26791:
    fn = elt(env, 2); // nth
    stack[0] = (*qfn2(fn))(fn, v_26806, v_26805);
    env = stack[-3];
    goto v_26783;
v_26784:
    goto v_26801;
v_26797:
    v_26805 = qvalue(elt(env, 1)); // ind
    v_26806 = qcdr(v_26805);
    goto v_26798;
v_26799:
    v_26805 = stack[-1];
    goto v_26800;
v_26801:
    goto v_26797;
v_26798:
    goto v_26799;
v_26800:
    v_26805 = CC_pdiffvars(elt(env, 0), v_26806, v_26805);
    env = stack[-3];
    goto v_26785;
v_26786:
    goto v_26782;
v_26783:
    goto v_26784;
v_26785:
    v_26805 = cons(stack[0], v_26805);
    goto v_26777;
v_26779:
    v_26805 = nil;
v_26777:
    ;}  // end of a binding scope
    return onevalue(v_26805);
}



// Code for ps!:evaluate!-next

static LispObject CC_psTevaluateKnext(LispObject env,
                         LispObject v_26767, LispObject v_26768)
{
    env = qenv(env);
    LispObject v_26822, v_26823;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26768,v_26767);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26767,v_26768);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_26768;
    v_26822 = v_26767;
// end of prologue
// Binding ps
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = v_26822; // ps
    goto v_26782;
v_26778:
    goto v_26788;
v_26784:
    goto v_26794;
v_26790:
    v_26823 = qvalue(elt(env, 1)); // ps
    goto v_26791;
v_26792:
    v_26822 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_26793;
v_26794:
    goto v_26790;
v_26791:
    goto v_26792;
v_26793:
    fn = elt(env, 3); // ps!:getv
    v_26822 = (*qfn2(fn))(fn, v_26823, v_26822);
    env = stack[-4];
    v_26823 = qcar(v_26822);
    goto v_26785;
v_26786:
    v_26822 = elt(env, 2); // ps!:erule
    goto v_26787;
v_26788:
    goto v_26784;
v_26785:
    goto v_26786;
v_26787:
    stack[0] = get(v_26823, v_26822);
    env = stack[-4];
    goto v_26779;
v_26780:
    goto v_26804;
v_26800:
    v_26822 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 4); // ps!:expression
    v_26823 = (*qfn1(fn))(fn, v_26822);
    env = stack[-4];
    goto v_26801;
v_26802:
    v_26822 = stack[-2];
    goto v_26803;
v_26804:
    goto v_26800;
v_26801:
    goto v_26802;
v_26803:
    v_26822 = list2(v_26823, v_26822);
    env = stack[-4];
    goto v_26781;
v_26782:
    goto v_26778;
v_26779:
    goto v_26780;
v_26781:
    fn = elt(env, 5); // apply
    v_26822 = (*qfn2(fn))(fn, stack[0], v_26822);
    env = stack[-4];
    stack[-1] = v_26822;
    goto v_26815;
v_26809:
    stack[0] = qvalue(elt(env, 1)); // ps
    goto v_26810;
v_26811:
    goto v_26812;
v_26813:
    v_26822 = stack[-1];
    fn = elt(env, 6); // prepsqxx
    v_26822 = (*qfn1(fn))(fn, v_26822);
    env = stack[-4];
    fn = elt(env, 7); // simp!*
    v_26822 = (*qfn1(fn))(fn, v_26822);
    env = stack[-4];
    stack[-1] = v_26822;
    goto v_26814;
v_26815:
    goto v_26809;
v_26810:
    goto v_26811;
v_26812:
    goto v_26813;
v_26814:
    fn = elt(env, 8); // ps!:set!-term
    v_26822 = (*qfnn(fn))(fn, 3, stack[0], stack[-2], v_26822);
    v_26822 = stack[-1];
    ;}  // end of a binding scope
    return onevalue(v_26822);
}



// Code for scar

static LispObject CC_scar(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26809, v_26810;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_26767;
    stack[-1] = v_26766;
// end of prologue
v_26765:
    v_26809 = stack[0];
    if (!consp(v_26809)) goto v_26771;
    else goto v_26772;
v_26771:
    v_26809 = nil;
    goto v_26770;
v_26772:
    goto v_26781;
v_26777:
    v_26810 = stack[-1];
    goto v_26778;
v_26779:
    v_26809 = stack[0];
    v_26809 = qcar(v_26809);
    goto v_26780;
v_26781:
    goto v_26777;
v_26778:
    goto v_26779;
v_26780:
    if (equal(v_26810, v_26809)) goto v_26775;
    else goto v_26776;
v_26775:
    v_26809 = stack[0];
    goto v_26770;
v_26776:
    goto v_26796;
v_26792:
    v_26810 = stack[-1];
    goto v_26793;
v_26794:
    v_26809 = stack[0];
    v_26809 = qcar(v_26809);
    goto v_26795;
v_26796:
    goto v_26792;
v_26793:
    goto v_26794;
v_26795:
    v_26809 = CC_scar(elt(env, 0), v_26810, v_26809);
    env = stack[-2];
    if (v_26809 == nil) goto v_26790;
    else goto v_26789;
v_26790:
    goto v_26805;
v_26801:
    v_26810 = stack[-1];
    goto v_26802;
v_26803:
    v_26809 = stack[0];
    v_26809 = qcdr(v_26809);
    goto v_26804;
v_26805:
    goto v_26801;
v_26802:
    goto v_26803;
v_26804:
    stack[-1] = v_26810;
    stack[0] = v_26809;
    goto v_26765;
v_26789:
    goto v_26770;
    v_26809 = nil;
v_26770:
    return onevalue(v_26809);
}



// Code for partitwedge

static LispObject CC_partitwedge(LispObject env,
                         LispObject v_26766)
{
    env = qenv(env);
    LispObject v_26782, v_26783;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_26766);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_26783 = v_26766;
// end of prologue
    v_26782 = v_26783;
    v_26782 = qcdr(v_26782);
    if (v_26782 == nil) goto v_26770;
    else goto v_26771;
v_26770:
    v_26782 = v_26783;
    v_26782 = qcar(v_26782);
    {
        fn = elt(env, 1); // partitop
        return (*qfn1(fn))(fn, v_26782);
    }
v_26771:
    v_26782 = v_26783;
    fn = elt(env, 2); // xpndwedge
    v_26782 = (*qfn1(fn))(fn, v_26782);
    env = stack[0];
    {
        fn = elt(env, 3); // mkuniquewedge
        return (*qfn1(fn))(fn, v_26782);
    }
    v_26782 = nil;
    return onevalue(v_26782);
}



// Code for subfindices

static LispObject CC_subfindices(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26982, v_26983;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_26767;
    stack[-2] = v_26766;
// end of prologue
// Binding alglist!*
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = nil; // alglist!*
    v_26982 = nil;
    v_26982 = ncons(v_26982);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_26982; // alglist!*
    v_26982 = stack[-2];
    if (!consp(v_26982)) goto v_26780;
    else goto v_26781;
v_26780:
    v_26982 = lisp_true;
    goto v_26779;
v_26781:
    v_26982 = stack[-2];
    v_26982 = qcar(v_26982);
    v_26982 = (consp(v_26982) ? nil : lisp_true);
    goto v_26779;
    v_26982 = nil;
v_26779:
    if (v_26982 == nil) goto v_26777;
    goto v_26794;
v_26790:
    v_26983 = stack[-2];
    goto v_26791;
v_26792:
    v_26982 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26793;
v_26794:
    goto v_26790;
v_26791:
    goto v_26792;
v_26793:
    v_26982 = cons(v_26983, v_26982);
    goto v_26775;
v_26777:
    goto v_26804;
v_26800:
    goto v_26810;
v_26806:
    v_26982 = stack[-2];
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    if (!consp(v_26982)) goto v_26813;
    else goto v_26814;
v_26813:
    goto v_26824;
v_26820:
    goto v_26831;
v_26827:
    v_26982 = stack[-2];
    v_26982 = qcar(v_26982);
    v_26983 = qcar(v_26982);
    goto v_26828;
v_26829:
    v_26982 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26830;
v_26831:
    goto v_26827;
v_26828:
    goto v_26829;
v_26830:
    v_26982 = cons(v_26983, v_26982);
    env = stack[-4];
    v_26983 = ncons(v_26982);
    env = stack[-4];
    goto v_26821;
v_26822:
    v_26982 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26823;
v_26824:
    goto v_26820;
v_26821:
    goto v_26822;
v_26823:
    v_26982 = cons(v_26983, v_26982);
    env = stack[-4];
    stack[0] = v_26982;
    goto v_26812;
v_26814:
    v_26982 = stack[-2];
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    fn = elt(env, 3); // sfp
    v_26982 = (*qfn1(fn))(fn, v_26982);
    env = stack[-4];
    if (v_26982 == nil) goto v_26838;
    goto v_26849;
v_26845:
    goto v_26855;
v_26851:
    v_26982 = stack[-2];
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    v_26983 = qcar(v_26982);
    goto v_26852;
v_26853:
    v_26982 = stack[-1];
    goto v_26854;
v_26855:
    goto v_26851;
v_26852:
    goto v_26853;
v_26854:
    v_26983 = CC_subfindices(elt(env, 0), v_26983, v_26982);
    env = stack[-4];
    goto v_26846;
v_26847:
    v_26982 = stack[-2];
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    v_26982 = qcdr(v_26982);
    goto v_26848;
v_26849:
    goto v_26845;
v_26846:
    goto v_26847;
v_26848:
    fn = elt(env, 4); // exptsq
    v_26982 = (*qfn2(fn))(fn, v_26983, v_26982);
    env = stack[-4];
    stack[0] = v_26982;
    goto v_26812;
v_26838:
    v_26982 = stack[-2];
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    if (!symbolp(v_26982)) v_26982 = nil;
    else { v_26982 = qfastgets(v_26982);
           if (v_26982 != nil) { v_26982 = elt(v_26982, 16); // indexvar
#ifdef RECORD_GET
             if (v_26982 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v_26982 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v_26982 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v_26982 == SPID_NOPROP) v_26982 = nil; else v_26982 = lisp_true; }}
#endif
    if (v_26982 == nil) goto v_26866;
    goto v_26878;
v_26874:
    goto v_26885;
v_26881:
    v_26982 = stack[-2];
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    stack[0] = qcar(v_26982);
    goto v_26882;
v_26883:
    goto v_26896;
v_26892:
    v_26983 = stack[-1];
    goto v_26893;
v_26894:
    v_26982 = stack[-2];
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    v_26982 = qcdr(v_26982);
    goto v_26895;
v_26896:
    goto v_26892;
v_26893:
    goto v_26894;
v_26895:
    v_26982 = Lsubla(nil, v_26983, v_26982);
    env = stack[-4];
    goto v_26884;
v_26885:
    goto v_26881;
v_26882:
    goto v_26883;
v_26884:
    v_26982 = cons(stack[0], v_26982);
    env = stack[-4];
    fn = elt(env, 5); // simpindexvar
    v_26983 = (*qfn1(fn))(fn, v_26982);
    env = stack[-4];
    goto v_26875;
v_26876:
    v_26982 = stack[-2];
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    v_26982 = qcdr(v_26982);
    goto v_26877;
v_26878:
    goto v_26874;
v_26875:
    goto v_26876;
v_26877:
    fn = elt(env, 4); // exptsq
    v_26982 = (*qfn2(fn))(fn, v_26983, v_26982);
    env = stack[-4];
    stack[0] = v_26982;
    goto v_26812;
v_26866:
    goto v_26913;
v_26909:
    v_26982 = stack[-2];
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    v_26983 = qcar(v_26982);
    goto v_26910;
v_26911:
    v_26982 = elt(env, 2); // (wedge d partdf innerprod liedf hodge vardf)
    goto v_26912;
v_26913:
    goto v_26909;
v_26910:
    goto v_26911;
v_26912:
    v_26982 = Lmemq(nil, v_26983, v_26982);
    if (v_26982 == nil) goto v_26908;
    goto v_26926;
v_26922:
    goto v_26933;
v_26929:
    v_26983 = stack[-1];
    goto v_26930;
v_26931:
    v_26982 = stack[-2];
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    goto v_26932;
v_26933:
    goto v_26929;
v_26930:
    goto v_26931;
v_26932:
    fn = elt(env, 6); // subindk
    v_26982 = (*qfn2(fn))(fn, v_26983, v_26982);
    env = stack[-4];
    fn = elt(env, 7); // simp
    v_26983 = (*qfn1(fn))(fn, v_26982);
    env = stack[-4];
    goto v_26923;
v_26924:
    v_26982 = stack[-2];
    v_26982 = qcar(v_26982);
    v_26982 = qcar(v_26982);
    v_26982 = qcdr(v_26982);
    goto v_26925;
v_26926:
    goto v_26922;
v_26923:
    goto v_26924;
v_26925:
    fn = elt(env, 4); // exptsq
    v_26982 = (*qfn2(fn))(fn, v_26983, v_26982);
    env = stack[-4];
    stack[0] = v_26982;
    goto v_26812;
v_26908:
    goto v_26950;
v_26946:
    goto v_26957;
v_26953:
    v_26982 = stack[-2];
    v_26982 = qcar(v_26982);
    v_26983 = qcar(v_26982);
    goto v_26954;
v_26955:
    v_26982 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26956;
v_26957:
    goto v_26953;
v_26954:
    goto v_26955;
v_26956:
    v_26982 = cons(v_26983, v_26982);
    env = stack[-4];
    v_26983 = ncons(v_26982);
    env = stack[-4];
    goto v_26947;
v_26948:
    v_26982 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26949;
v_26950:
    goto v_26946;
v_26947:
    goto v_26948;
v_26949:
    v_26982 = cons(v_26983, v_26982);
    env = stack[-4];
    stack[0] = v_26982;
    goto v_26812;
    stack[0] = nil;
v_26812:
    goto v_26807;
v_26808:
    goto v_26968;
v_26964:
    v_26982 = stack[-2];
    v_26982 = qcar(v_26982);
    v_26983 = qcdr(v_26982);
    goto v_26965;
v_26966:
    v_26982 = stack[-1];
    goto v_26967;
v_26968:
    goto v_26964;
v_26965:
    goto v_26966;
v_26967:
    v_26982 = CC_subfindices(elt(env, 0), v_26983, v_26982);
    env = stack[-4];
    goto v_26809;
v_26810:
    goto v_26806;
v_26807:
    goto v_26808;
v_26809:
    fn = elt(env, 8); // multsq
    stack[0] = (*qfn2(fn))(fn, stack[0], v_26982);
    env = stack[-4];
    goto v_26801;
v_26802:
    goto v_26978;
v_26974:
    v_26982 = stack[-2];
    v_26983 = qcdr(v_26982);
    goto v_26975;
v_26976:
    v_26982 = stack[-1];
    goto v_26977;
v_26978:
    goto v_26974;
v_26975:
    goto v_26976;
v_26977:
    v_26982 = CC_subfindices(elt(env, 0), v_26983, v_26982);
    env = stack[-4];
    goto v_26803;
v_26804:
    goto v_26800;
v_26801:
    goto v_26802;
v_26803:
    fn = elt(env, 9); // addsq
    v_26982 = (*qfn2(fn))(fn, stack[0], v_26982);
    goto v_26775;
    v_26982 = nil;
v_26775:
    ;}  // end of a binding scope
    return onevalue(v_26982);
}



// Code for coeff_calc

static LispObject CC_coeff_calc(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_26789, v_26790, v_26791;
    LispObject fn;
    LispObject v_26768, v_26767, v_26766;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "coeff_calc");
    va_start(aa, nargs);
    v_26766 = va_arg(aa, LispObject);
    v_26767 = va_arg(aa, LispObject);
    v_26768 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_26768,v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_26766,v_26767,v_26768);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_26789 = v_26768;
    v_26790 = v_26767;
    v_26791 = v_26766;
// end of prologue
    goto v_26776;
v_26772:
    stack[0] = elt(env, 1); // plus
    goto v_26773;
v_26774:
    goto v_26785;
v_26779:
    goto v_26780;
v_26781:
    goto v_26782;
v_26783:
    goto v_26784;
v_26785:
    goto v_26779;
v_26780:
    goto v_26781;
v_26782:
    goto v_26783;
v_26784:
    fn = elt(env, 2); // coeff1_calc
    v_26789 = (*qfnn(fn))(fn, 3, v_26791, v_26790, v_26789);
    env = stack[-1];
    goto v_26775;
v_26776:
    goto v_26772;
v_26773:
    goto v_26774;
v_26775:
    v_26789 = cons(stack[0], v_26789);
    env = stack[-1];
    {
        fn = elt(env, 3); // reval
        return (*qfn1(fn))(fn, v_26789);
    }
}



// Code for fs!:timescoeff

static LispObject CC_fsTtimescoeff(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26895, v_26896, v_26897, v_26898;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_26767;
    stack[-3] = v_26766;
// end of prologue
v_26765:
    v_26895 = stack[-2];
    if (v_26895 == nil) goto v_26771;
    else goto v_26772;
v_26771:
    v_26895 = nil;
    goto v_26770;
v_26772:
    goto v_26786;
v_26782:
    v_26897 = stack[-3];
    goto v_26783;
v_26784:
    goto v_26792;
v_26788:
    v_26896 = stack[-2];
    goto v_26789;
v_26790:
    v_26895 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_26791;
v_26792:
    goto v_26788;
v_26789:
    goto v_26790;
v_26791:
    v_26895 = *(LispObject *)((char *)v_26896 + (CELL-TAG_VECTOR) + (((intptr_t)v_26895-TAG_FIXNUM)/(16/CELL)));
    goto v_26785;
v_26786:
    goto v_26782;
v_26783:
    goto v_26784;
v_26785:
    fn = elt(env, 3); // multsq
    v_26895 = (*qfn2(fn))(fn, v_26897, v_26895);
    env = stack[-5];
    stack[0] = v_26895;
    goto v_26804;
v_26800:
    v_26896 = stack[0];
    goto v_26801;
v_26802:
    v_26895 = elt(env, 1); // (nil . 1)
    goto v_26803;
v_26804:
    goto v_26800;
v_26801:
    goto v_26802;
v_26803:
    if (equal(v_26896, v_26895)) goto v_26798;
    else goto v_26799;
v_26798:
    v_26895 = elt(env, 2); // "zero in times"
    v_26895 = Lprint(nil, v_26895);
    env = stack[-5];
    goto v_26814;
v_26810:
    v_26897 = stack[-3];
    goto v_26811;
v_26812:
    goto v_26820;
v_26816:
    v_26896 = stack[-2];
    goto v_26817;
v_26818:
    v_26895 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_26819;
v_26820:
    goto v_26816;
v_26817:
    goto v_26818;
v_26819:
    v_26895 = *(LispObject *)((char *)v_26896 + (CELL-TAG_VECTOR) + (((intptr_t)v_26895-TAG_FIXNUM)/(16/CELL)));
    goto v_26813;
v_26814:
    goto v_26810;
v_26811:
    goto v_26812;
v_26813:
    stack[-3] = v_26897;
    stack[-2] = v_26895;
    goto v_26765;
v_26799:
    v_26895 = (LispObject)48+TAG_FIXNUM; // 3
    v_26895 = Lmkvect(nil, v_26895);
    env = stack[-5];
    stack[-4] = v_26895;
    goto v_26832;
v_26826:
    v_26897 = stack[-4];
    goto v_26827;
v_26828:
    v_26896 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_26829;
v_26830:
    v_26895 = stack[0];
    goto v_26831;
v_26832:
    goto v_26826;
v_26827:
    goto v_26828;
v_26829:
    goto v_26830;
v_26831:
    *(LispObject *)((char *)v_26897 + (CELL-TAG_VECTOR) + (((intptr_t)v_26896-TAG_FIXNUM)/(16/CELL))) = v_26895;
    goto v_26842;
v_26836:
    v_26898 = stack[-4];
    goto v_26837;
v_26838:
    v_26897 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26839;
v_26840:
    goto v_26849;
v_26845:
    v_26896 = stack[-2];
    goto v_26846;
v_26847:
    v_26895 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26848;
v_26849:
    goto v_26845;
v_26846:
    goto v_26847;
v_26848:
    v_26895 = *(LispObject *)((char *)v_26896 + (CELL-TAG_VECTOR) + (((intptr_t)v_26895-TAG_FIXNUM)/(16/CELL)));
    goto v_26841;
v_26842:
    goto v_26836;
v_26837:
    goto v_26838;
v_26839:
    goto v_26840;
v_26841:
    *(LispObject *)((char *)v_26898 + (CELL-TAG_VECTOR) + (((intptr_t)v_26897-TAG_FIXNUM)/(16/CELL))) = v_26895;
    goto v_26859;
v_26853:
    v_26898 = stack[-4];
    goto v_26854;
v_26855:
    v_26897 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_26856;
v_26857:
    goto v_26866;
v_26862:
    v_26896 = stack[-2];
    goto v_26863;
v_26864:
    v_26895 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_26865;
v_26866:
    goto v_26862;
v_26863:
    goto v_26864;
v_26865:
    v_26895 = *(LispObject *)((char *)v_26896 + (CELL-TAG_VECTOR) + (((intptr_t)v_26895-TAG_FIXNUM)/(16/CELL)));
    goto v_26858;
v_26859:
    goto v_26853;
v_26854:
    goto v_26855;
v_26856:
    goto v_26857;
v_26858:
    *(LispObject *)((char *)v_26898 + (CELL-TAG_VECTOR) + (((intptr_t)v_26897-TAG_FIXNUM)/(16/CELL))) = v_26895;
    goto v_26876;
v_26870:
    stack[-1] = stack[-4];
    goto v_26871;
v_26872:
    stack[0] = (LispObject)48+TAG_FIXNUM; // 3
    goto v_26873;
v_26874:
    goto v_26884;
v_26880:
    v_26897 = stack[-3];
    goto v_26881;
v_26882:
    goto v_26890;
v_26886:
    v_26896 = stack[-2];
    goto v_26887;
v_26888:
    v_26895 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_26889;
v_26890:
    goto v_26886;
v_26887:
    goto v_26888;
v_26889:
    v_26895 = *(LispObject *)((char *)v_26896 + (CELL-TAG_VECTOR) + (((intptr_t)v_26895-TAG_FIXNUM)/(16/CELL)));
    goto v_26883;
v_26884:
    goto v_26880;
v_26881:
    goto v_26882;
v_26883:
    v_26895 = CC_fsTtimescoeff(elt(env, 0), v_26897, v_26895);
    goto v_26875;
v_26876:
    goto v_26870;
v_26871:
    goto v_26872;
v_26873:
    goto v_26874;
v_26875:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_26895;
    v_26895 = stack[-4];
    goto v_26770;
    v_26895 = nil;
v_26770:
    return onevalue(v_26895);
}



// Code for mkindxlist

static LispObject CC_mkindxlist(LispObject env,
                         LispObject v_26766)
{
    env = qenv(env);
    LispObject v_26870, v_26871;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_26766);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_26870 = v_26766;
// end of prologue
    stack[-4] = v_26870;
    v_26870 = stack[-4];
    if (v_26870 == nil) goto v_26777;
    else goto v_26778;
v_26777:
    v_26870 = nil;
    goto v_26772;
v_26778:
    v_26870 = stack[-4];
    v_26870 = qcar(v_26870);
    v_26871 = v_26870;
    v_26870 = v_26871;
    v_26870 = integerp(v_26870);
    if (v_26870 == nil) goto v_26788;
    v_26870 = v_26871;
    fn = elt(env, 2); // !*num2id
    v_26870 = (*qfn1(fn))(fn, v_26870);
    env = stack[-5];
    goto v_26786;
v_26788:
    v_26870 = v_26871;
    v_26870 = Lconsp(nil, v_26870);
    env = stack[-5];
    if (v_26870 == nil) goto v_26794;
    v_26870 = v_26871;
    v_26870 = qcdr(v_26870);
    v_26870 = qcar(v_26870);
    v_26870 = integerp(v_26870);
    if (v_26870 == nil) goto v_26794;
    goto v_26808;
v_26804:
    stack[0] = elt(env, 1); // minus
    goto v_26805;
v_26806:
    v_26870 = v_26871;
    v_26870 = qcdr(v_26870);
    v_26870 = qcar(v_26870);
    fn = elt(env, 2); // !*num2id
    v_26870 = (*qfn1(fn))(fn, v_26870);
    env = stack[-5];
    goto v_26807;
v_26808:
    goto v_26804;
v_26805:
    goto v_26806;
v_26807:
    v_26870 = list2(stack[0], v_26870);
    env = stack[-5];
    goto v_26786;
v_26794:
    v_26870 = v_26871;
    goto v_26786;
    v_26870 = nil;
v_26786:
    v_26870 = ncons(v_26870);
    env = stack[-5];
    stack[-2] = v_26870;
    stack[-3] = v_26870;
v_26773:
    v_26870 = stack[-4];
    v_26870 = qcdr(v_26870);
    stack[-4] = v_26870;
    v_26870 = stack[-4];
    if (v_26870 == nil) goto v_26821;
    else goto v_26822;
v_26821:
    v_26870 = stack[-3];
    goto v_26772;
v_26822:
    goto v_26830;
v_26826:
    stack[-1] = stack[-2];
    goto v_26827;
v_26828:
    v_26870 = stack[-4];
    v_26870 = qcar(v_26870);
    v_26871 = v_26870;
    v_26870 = v_26871;
    v_26870 = integerp(v_26870);
    if (v_26870 == nil) goto v_26839;
    v_26870 = v_26871;
    fn = elt(env, 2); // !*num2id
    v_26870 = (*qfn1(fn))(fn, v_26870);
    env = stack[-5];
    goto v_26837;
v_26839:
    v_26870 = v_26871;
    v_26870 = Lconsp(nil, v_26870);
    env = stack[-5];
    if (v_26870 == nil) goto v_26845;
    v_26870 = v_26871;
    v_26870 = qcdr(v_26870);
    v_26870 = qcar(v_26870);
    v_26870 = integerp(v_26870);
    if (v_26870 == nil) goto v_26845;
    goto v_26859;
v_26855:
    stack[0] = elt(env, 1); // minus
    goto v_26856;
v_26857:
    v_26870 = v_26871;
    v_26870 = qcdr(v_26870);
    v_26870 = qcar(v_26870);
    fn = elt(env, 2); // !*num2id
    v_26870 = (*qfn1(fn))(fn, v_26870);
    env = stack[-5];
    goto v_26858;
v_26859:
    goto v_26855;
v_26856:
    goto v_26857;
v_26858:
    v_26870 = list2(stack[0], v_26870);
    env = stack[-5];
    goto v_26837;
v_26845:
    v_26870 = v_26871;
    goto v_26837;
    v_26870 = nil;
v_26837:
    v_26870 = ncons(v_26870);
    env = stack[-5];
    goto v_26829;
v_26830:
    goto v_26826;
v_26827:
    goto v_26828;
v_26829:
    v_26870 = Lrplacd(nil, stack[-1], v_26870);
    env = stack[-5];
    v_26870 = stack[-2];
    v_26870 = qcdr(v_26870);
    stack[-2] = v_26870;
    goto v_26773;
v_26772:
    return onevalue(v_26870);
}



// Code for mkrootsql

static LispObject CC_mkrootsql(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26849, v_26850;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_26767;
    stack[-1] = v_26766;
// end of prologue
    v_26849 = stack[-1];
    if (v_26849 == nil) goto v_26771;
    else goto v_26772;
v_26771:
    v_26849 = (LispObject)16+TAG_FIXNUM; // 1
    {
        fn = elt(env, 1); // !*d2q
        return (*qfn1(fn))(fn, v_26849);
    }
v_26772:
    goto v_26783;
v_26779:
    v_26849 = stack[-1];
    v_26849 = qcar(v_26849);
    v_26850 = qcdr(v_26849);
    goto v_26780;
v_26781:
    v_26849 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26782;
v_26783:
    goto v_26779;
v_26780:
    goto v_26781;
v_26782:
    v_26849 = (LispObject)greaterp2(v_26850, v_26849);
    v_26849 = v_26849 ? lisp_true : nil;
    env = stack[-3];
    if (v_26849 == nil) goto v_26777;
    goto v_26793;
v_26789:
    goto v_26799;
v_26795:
    goto v_26805;
v_26801:
    v_26849 = stack[-1];
    v_26849 = qcar(v_26849);
    v_26850 = qcar(v_26849);
    goto v_26802;
v_26803:
    v_26849 = stack[0];
    goto v_26804;
v_26805:
    goto v_26801;
v_26802:
    goto v_26803;
v_26804:
    fn = elt(env, 2); // mkrootsq
    v_26850 = (*qfn2(fn))(fn, v_26850, v_26849);
    env = stack[-3];
    goto v_26796;
v_26797:
    v_26849 = stack[-1];
    v_26849 = qcar(v_26849);
    v_26849 = qcdr(v_26849);
    goto v_26798;
v_26799:
    goto v_26795;
v_26796:
    goto v_26797;
v_26798:
    fn = elt(env, 3); // exptsq
    stack[-2] = (*qfn2(fn))(fn, v_26850, v_26849);
    env = stack[-3];
    goto v_26790;
v_26791:
    goto v_26818;
v_26814:
    v_26849 = stack[-1];
    v_26850 = qcdr(v_26849);
    goto v_26815;
v_26816:
    v_26849 = stack[0];
    goto v_26817;
v_26818:
    goto v_26814;
v_26815:
    goto v_26816;
v_26817:
    v_26849 = CC_mkrootsql(elt(env, 0), v_26850, v_26849);
    env = stack[-3];
    goto v_26792;
v_26793:
    goto v_26789;
v_26790:
    goto v_26791;
v_26792:
    {
        LispObject v_26854 = stack[-2];
        fn = elt(env, 4); // multsq
        return (*qfn2(fn))(fn, v_26854, v_26849);
    }
v_26777:
    goto v_26829;
v_26825:
    goto v_26835;
v_26831:
    v_26849 = stack[-1];
    v_26849 = qcar(v_26849);
    v_26850 = qcar(v_26849);
    goto v_26832;
v_26833:
    v_26849 = stack[0];
    goto v_26834;
v_26835:
    goto v_26831;
v_26832:
    goto v_26833;
v_26834:
    fn = elt(env, 2); // mkrootsq
    stack[-2] = (*qfn2(fn))(fn, v_26850, v_26849);
    env = stack[-3];
    goto v_26826;
v_26827:
    goto v_26845;
v_26841:
    v_26849 = stack[-1];
    v_26850 = qcdr(v_26849);
    goto v_26842;
v_26843:
    v_26849 = stack[0];
    goto v_26844;
v_26845:
    goto v_26841;
v_26842:
    goto v_26843;
v_26844:
    v_26849 = CC_mkrootsql(elt(env, 0), v_26850, v_26849);
    env = stack[-3];
    goto v_26828;
v_26829:
    goto v_26825;
v_26826:
    goto v_26827;
v_26828:
    {
        LispObject v_26855 = stack[-2];
        fn = elt(env, 4); // multsq
        return (*qfn2(fn))(fn, v_26855, v_26849);
    }
    v_26849 = nil;
    return onevalue(v_26849);
}



// Code for evaluate!-in!-order!-mod!-p

static LispObject CC_evaluateKinKorderKmodKp(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26835, v_26836, v_26837, v_26838;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_26767;
    stack[-1] = v_26766;
// end of prologue
v_26771:
    v_26835 = stack[-1];
    if (!consp(v_26835)) goto v_26778;
    else goto v_26779;
v_26778:
    v_26835 = lisp_true;
    goto v_26777;
v_26779:
    v_26835 = stack[-1];
    v_26835 = qcar(v_26835);
    v_26835 = (consp(v_26835) ? nil : lisp_true);
    goto v_26777;
    v_26835 = nil;
v_26777:
    if (v_26835 == nil) goto v_26775;
    v_26835 = stack[-1];
    {
        fn = elt(env, 1); // !*d2n
        return (*qfn1(fn))(fn, v_26835);
    }
v_26775:
    goto v_26795;
v_26791:
    v_26835 = stack[-1];
    v_26835 = qcar(v_26835);
    v_26835 = qcar(v_26835);
    v_26836 = qcar(v_26835);
    goto v_26792;
v_26793:
    v_26835 = stack[0];
    v_26835 = qcar(v_26835);
    v_26835 = qcar(v_26835);
    goto v_26794;
v_26795:
    goto v_26791;
v_26792:
    goto v_26793;
v_26794:
    if (equal(v_26836, v_26835)) goto v_26789;
    else goto v_26790;
v_26789:
    goto v_26812;
v_26804:
    goto v_26818;
v_26814:
    v_26835 = stack[-1];
    v_26835 = qcar(v_26835);
    v_26836 = qcdr(v_26835);
    goto v_26815;
v_26816:
    v_26835 = stack[0];
    v_26835 = qcdr(v_26835);
    goto v_26817;
v_26818:
    goto v_26814;
v_26815:
    goto v_26816;
v_26817:
    v_26838 = CC_evaluateKinKorderKmodKp(elt(env, 0), v_26836, v_26835);
    env = stack[-2];
    goto v_26805;
v_26806:
    v_26835 = stack[-1];
    v_26835 = qcar(v_26835);
    v_26835 = qcar(v_26835);
    v_26837 = qcdr(v_26835);
    goto v_26807;
v_26808:
    v_26835 = stack[-1];
    v_26836 = qcdr(v_26835);
    goto v_26809;
v_26810:
    v_26835 = stack[0];
    goto v_26811;
v_26812:
    goto v_26804;
v_26805:
    goto v_26806;
v_26807:
    goto v_26808;
v_26809:
    goto v_26810;
v_26811:
    {
        fn = elt(env, 2); // horner!-rule!-in!-order!-mod!-p
        return (*qfnn(fn))(fn, 4, v_26838, v_26837, v_26836, v_26835);
    }
v_26790:
    v_26835 = stack[0];
    v_26835 = qcdr(v_26835);
    stack[0] = v_26835;
    goto v_26771;
    v_26835 = nil;
    return onevalue(v_26835);
}



// Code for coeffs

static LispObject CC_coeffs(LispObject env,
                         LispObject v_26766)
{
    env = qenv(env);
    LispObject v_26914, v_26915;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_26766);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_26766;
// end of prologue
    stack[-2] = nil;
    v_26914 = stack[-4];
    v_26914 = qcar(v_26914);
    v_26914 = qcar(v_26914);
    v_26914 = qcar(v_26914);
    stack[-1] = v_26914;
    v_26914 = stack[-4];
    v_26914 = qcar(v_26914);
    v_26914 = qcar(v_26914);
    v_26914 = qcdr(v_26914);
    stack[-5] = v_26914;
v_26786:
    v_26914 = stack[-4];
    if (!consp(v_26914)) goto v_26797;
    else goto v_26798;
v_26797:
    v_26914 = lisp_true;
    goto v_26796;
v_26798:
    v_26914 = stack[-4];
    v_26914 = qcar(v_26914);
    v_26914 = (consp(v_26914) ? nil : lisp_true);
    goto v_26796;
    v_26914 = nil;
v_26796:
    if (v_26914 == nil) goto v_26793;
    else goto v_26794;
v_26793:
    goto v_26810;
v_26806:
    v_26914 = stack[-4];
    v_26914 = qcar(v_26914);
    v_26914 = qcar(v_26914);
    v_26915 = qcar(v_26914);
    goto v_26807;
v_26808:
    v_26914 = stack[-1];
    goto v_26809;
v_26810:
    goto v_26806;
v_26807:
    goto v_26808;
v_26809:
    v_26914 = (v_26915 == v_26914 ? lisp_true : nil);
    goto v_26792;
v_26794:
    v_26914 = nil;
    goto v_26792;
    v_26914 = nil;
v_26792:
    if (v_26914 == nil) goto v_26789;
    else goto v_26790;
v_26789:
    goto v_26785;
v_26790:
    v_26914 = stack[-4];
    v_26914 = qcar(v_26914);
    v_26914 = qcar(v_26914);
    v_26914 = qcdr(v_26914);
    stack[-3] = v_26914;
    v_26914 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_26914;
v_26828:
    goto v_26840;
v_26836:
    goto v_26847;
v_26843:
    v_26915 = stack[-5];
    goto v_26844;
v_26845:
    v_26914 = stack[-3];
    goto v_26846;
v_26847:
    goto v_26843;
v_26844:
    goto v_26845;
v_26846:
    v_26914 = difference2(v_26915, v_26914);
    env = stack[-6];
    v_26915 = sub1(v_26914);
    env = stack[-6];
    goto v_26837;
v_26838:
    v_26914 = stack[0];
    goto v_26839;
v_26840:
    goto v_26836;
v_26837:
    goto v_26838;
v_26839:
    v_26914 = difference2(v_26915, v_26914);
    env = stack[-6];
    v_26914 = Lminusp(nil, v_26914);
    env = stack[-6];
    if (v_26914 == nil) goto v_26833;
    goto v_26827;
v_26833:
    goto v_26857;
v_26853:
    v_26915 = nil;
    goto v_26854;
v_26855:
    v_26914 = stack[-2];
    goto v_26856;
v_26857:
    goto v_26853;
v_26854:
    goto v_26855;
v_26856:
    v_26914 = cons(v_26915, v_26914);
    env = stack[-6];
    stack[-2] = v_26914;
    v_26914 = stack[0];
    v_26914 = add1(v_26914);
    env = stack[-6];
    stack[0] = v_26914;
    goto v_26828;
v_26827:
    goto v_26867;
v_26863:
    v_26914 = stack[-4];
    v_26914 = qcar(v_26914);
    v_26915 = qcdr(v_26914);
    goto v_26864;
v_26865:
    v_26914 = stack[-2];
    goto v_26866;
v_26867:
    goto v_26863;
v_26864:
    goto v_26865;
v_26866:
    v_26914 = cons(v_26915, v_26914);
    env = stack[-6];
    stack[-2] = v_26914;
    v_26914 = stack[-4];
    v_26914 = qcdr(v_26914);
    stack[-4] = v_26914;
    v_26914 = stack[-3];
    stack[-5] = v_26914;
    goto v_26786;
v_26785:
    v_26914 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_26914;
v_26878:
    goto v_26890;
v_26886:
    v_26914 = stack[-5];
    v_26915 = sub1(v_26914);
    env = stack[-6];
    goto v_26887;
v_26888:
    v_26914 = stack[0];
    goto v_26889;
v_26890:
    goto v_26886;
v_26887:
    goto v_26888;
v_26889:
    v_26914 = difference2(v_26915, v_26914);
    env = stack[-6];
    v_26914 = Lminusp(nil, v_26914);
    env = stack[-6];
    if (v_26914 == nil) goto v_26883;
    goto v_26877;
v_26883:
    goto v_26900;
v_26896:
    v_26915 = nil;
    goto v_26897;
v_26898:
    v_26914 = stack[-2];
    goto v_26899;
v_26900:
    goto v_26896;
v_26897:
    goto v_26898;
v_26899:
    v_26914 = cons(v_26915, v_26914);
    env = stack[-6];
    stack[-2] = v_26914;
    v_26914 = stack[0];
    v_26914 = add1(v_26914);
    env = stack[-6];
    stack[0] = v_26914;
    goto v_26878;
v_26877:
    goto v_26911;
v_26907:
    v_26915 = stack[-4];
    goto v_26908;
v_26909:
    v_26914 = stack[-2];
    goto v_26910;
v_26911:
    goto v_26907;
v_26908:
    goto v_26909;
v_26910:
    v_26914 = cons(v_26915, v_26914);
        return Lnreverse(nil, v_26914);
    return onevalue(v_26914);
}



// Code for valuechk

static LispObject CC_valuechk(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26933, v_26934, v_26935;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_26767;
    stack[-2] = v_26766;
// end of prologue
    v_26933 = stack[-2];
    if (!symbolp(v_26933)) v_26933 = nil;
    else { v_26933 = qfastgets(v_26933);
           if (v_26933 != nil) { v_26933 = elt(v_26933, 42); // number!-of!-args
#ifdef RECORD_GET
             if (v_26933 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v_26933 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v_26933 == SPID_NOPROP) v_26933 = nil; }}
#endif
    stack[0] = v_26933;
    if (v_26933 == nil) goto v_26776;
    goto v_26789;
v_26785:
    v_26933 = stack[-1];
    v_26934 = Llength(nil, v_26933);
    env = stack[-4];
    goto v_26786;
v_26787:
    v_26933 = stack[0];
    goto v_26788;
v_26789:
    goto v_26785;
v_26786:
    goto v_26787;
v_26788:
    if (equal(v_26934, v_26933)) goto v_26784;
    goto v_26798;
v_26794:
    v_26934 = stack[-2];
    goto v_26795;
v_26796:
    v_26933 = elt(env, 1); // variadic
    goto v_26797;
v_26798:
    goto v_26794;
v_26795:
    goto v_26796;
v_26797:
    v_26933 = Lflagp(nil, v_26934, v_26933);
    env = stack[-4];
    v_26933 = (v_26933 == nil ? lisp_true : nil);
    goto v_26782;
v_26784:
    v_26933 = nil;
    goto v_26782;
    v_26933 = nil;
v_26782:
    if (v_26933 == nil) goto v_26776;
    goto v_26774;
v_26776:
    v_26933 = stack[0];
    if (v_26933 == nil) goto v_26808;
    else goto v_26809;
v_26808:
    v_26933 = stack[-1];
    if (v_26933 == nil) goto v_26813;
    else goto v_26814;
v_26813:
    v_26933 = nil;
    goto v_26812;
v_26814:
    v_26933 = stack[-1];
    v_26933 = qcdr(v_26933);
    if (v_26933 == nil) goto v_26821;
    else goto v_26822;
v_26821:
    v_26933 = nil;
    goto v_26820;
v_26822:
    goto v_26836;
v_26832:
    v_26934 = stack[-2];
    goto v_26833;
v_26834:
    v_26933 = elt(env, 2); // !:rd!:
    goto v_26835;
v_26836:
    goto v_26832;
v_26833:
    goto v_26834;
v_26835:
    v_26933 = get(v_26934, v_26933);
    env = stack[-4];
    if (v_26933 == nil) goto v_26830;
    else goto v_26829;
v_26830:
    goto v_26844;
v_26840:
    v_26934 = stack[-2];
    goto v_26841;
v_26842:
    v_26933 = elt(env, 3); // !:rn!:
    goto v_26843;
v_26844:
    goto v_26840;
v_26841:
    goto v_26842;
v_26843:
    v_26933 = get(v_26934, v_26933);
    env = stack[-4];
v_26829:
    goto v_26820;
    v_26933 = nil;
v_26820:
    goto v_26812;
    v_26933 = nil;
v_26812:
    goto v_26807;
v_26809:
    v_26933 = nil;
    goto v_26807;
    v_26933 = nil;
v_26807:
    if (v_26933 == nil) goto v_26805;
    else goto v_26774;
v_26805:
    goto v_26775;
v_26774:
    v_26933 = qvalue(elt(env, 4)); // !*strict_argcount
    if (v_26933 == nil) goto v_26853;
    goto v_26862;
v_26856:
    stack[-3] = elt(env, 5); // alg
    goto v_26857;
v_26858:
    stack[0] = (LispObject)272+TAG_FIXNUM; // 17
    goto v_26859;
v_26860:
    goto v_26870;
v_26866:
    v_26934 = elt(env, 6); // "Wrong number of arguments to"
    goto v_26867;
v_26868:
    v_26933 = stack[-2];
    goto v_26869;
v_26870:
    goto v_26866;
v_26867:
    goto v_26868;
v_26869:
    v_26933 = list2(v_26934, v_26933);
    env = stack[-4];
    goto v_26861;
v_26862:
    goto v_26856;
v_26857:
    goto v_26858;
v_26859:
    goto v_26860;
v_26861:
    fn = elt(env, 8); // rerror
    v_26933 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_26933);
    env = stack[-4];
    goto v_26851;
v_26853:
    goto v_26881;
v_26877:
    v_26934 = elt(env, 6); // "Wrong number of arguments to"
    goto v_26878;
v_26879:
    v_26933 = stack[-2];
    goto v_26880;
v_26881:
    goto v_26877;
v_26878:
    goto v_26879;
v_26880:
    v_26933 = list2(v_26934, v_26933);
    env = stack[-4];
    fn = elt(env, 9); // lprim
    v_26933 = (*qfn1(fn))(fn, v_26933);
    env = stack[-4];
    goto v_26851;
v_26851:
    goto v_26773;
v_26775:
v_26773:
    goto v_26890;
v_26886:
    v_26934 = stack[-2];
    goto v_26887;
v_26888:
    v_26933 = stack[-1];
    goto v_26889;
v_26890:
    goto v_26886;
v_26887:
    goto v_26888;
v_26889:
    v_26933 = cons(v_26934, v_26933);
    env = stack[-4];
    fn = elt(env, 10); // opfchk!!
    v_26933 = (*qfn1(fn))(fn, v_26933);
    env = stack[-4];
    stack[-1] = v_26933;
    v_26933 = stack[-1];
    if (v_26933 == nil) goto v_26896;
    goto v_26904;
v_26900:
    goto v_26914;
v_26910:
    v_26934 = stack[-1];
    goto v_26911;
v_26912:
    v_26933 = elt(env, 7); // list
    goto v_26913;
v_26914:
    goto v_26910;
v_26911:
    goto v_26912;
v_26913:
    if (!consp(v_26934)) goto v_26908;
    v_26934 = qcar(v_26934);
    if (v_26934 == v_26933) goto v_26907;
    else goto v_26908;
v_26907:
    goto v_26925;
v_26919:
    v_26935 = stack[-1];
    goto v_26920;
v_26921:
    v_26934 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26922;
v_26923:
    v_26933 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26924;
v_26925:
    goto v_26919;
v_26920:
    goto v_26921;
v_26922:
    goto v_26923;
v_26924:
    v_26933 = acons(v_26935, v_26934, v_26933);
    env = stack[-4];
    v_26933 = ncons(v_26933);
    env = stack[-4];
    v_26934 = v_26933;
    goto v_26906;
v_26908:
    v_26933 = stack[-1];
    v_26934 = v_26933;
    goto v_26906;
    v_26934 = nil;
v_26906:
    goto v_26901;
v_26902:
    v_26933 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26903;
v_26904:
    goto v_26900;
v_26901:
    goto v_26902;
v_26903:
    v_26933 = cons(v_26934, v_26933);
    env = stack[-4];
    {
        fn = elt(env, 11); // znumrnil
        return (*qfn1(fn))(fn, v_26933);
    }
v_26896:
    v_26933 = nil;
    return onevalue(v_26933);
}



// Code for iv_new

static LispObject CC_iv_new(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26794, v_26795, v_26796;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
// copy arguments values to proper place
    v_26795 = v_26767;
    v_26796 = v_26766;
// end of prologue
    goto v_26775;
v_26771:
    v_26794 = v_26796;
    if (v_26794 == nil) goto v_26779;
    v_26794 = v_26796;
    v_26796 = v_26794;
    goto v_26777;
v_26779:
    v_26794 = (LispObject)0+TAG_FIXNUM; // 0
    v_26796 = v_26794;
    goto v_26777;
    v_26796 = nil;
v_26777:
    goto v_26772;
v_26773:
    v_26794 = v_26795;
    if (v_26794 == nil) goto v_26788;
    v_26794 = v_26795;
    goto v_26786;
v_26788:
    v_26794 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_26786;
    v_26794 = nil;
v_26786:
    goto v_26774;
v_26775:
    goto v_26771;
v_26772:
    goto v_26773;
v_26774:
    v_26794 = cons(v_26796, v_26794);
    return ncons(v_26794);
}



// Code for ofsf_optfindeqsol

static LispObject CC_ofsf_optfindeqsol(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26859, v_26860;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_26767;
    stack[-2] = v_26766;
// end of prologue
v_26765:
    v_26859 = stack[-2];
    v_26859 = qcar(v_26859);
    stack[-3] = v_26859;
    goto v_26787;
v_26783:
    v_26859 = stack[-3];
    v_26860 = qcar(v_26859);
    goto v_26784;
v_26785:
    v_26859 = elt(env, 1); // equal
    goto v_26786;
v_26787:
    goto v_26783;
v_26784:
    goto v_26785;
v_26786:
    if (v_26860 == v_26859) goto v_26781;
    else goto v_26782;
v_26781:
    goto v_26795;
v_26791:
    stack[0] = stack[-1];
    goto v_26792;
v_26793:
    v_26859 = stack[-3];
    fn = elt(env, 2); // ofsf_varlat
    v_26859 = (*qfn1(fn))(fn, v_26859);
    env = stack[-4];
    goto v_26794;
v_26795:
    goto v_26791;
v_26792:
    goto v_26793;
v_26794:
    v_26859 = Lmemq(nil, stack[0], v_26859);
    goto v_26780;
v_26782:
    v_26859 = nil;
    goto v_26780;
    v_26859 = nil;
v_26780:
    if (v_26859 == nil) goto v_26778;
    goto v_26808;
v_26804:
    v_26859 = stack[-3];
    v_26859 = qcdr(v_26859);
    v_26860 = qcar(v_26859);
    goto v_26805;
v_26806:
    v_26859 = stack[-1];
    goto v_26807;
v_26808:
    goto v_26804;
v_26805:
    goto v_26806;
v_26807:
    fn = elt(env, 3); // ofsf_optmksol
    v_26859 = (*qfn2(fn))(fn, v_26860, v_26859);
    env = stack[-4];
    stack[-1] = v_26859;
    goto v_26818;
v_26814:
    stack[-2] = stack[-3];
    goto v_26815;
v_26816:
    goto v_26825;
v_26821:
    goto v_26831;
v_26827:
    v_26859 = stack[-1];
    v_26860 = qcar(v_26859);
    goto v_26828;
v_26829:
    v_26859 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26830;
v_26831:
    goto v_26827;
v_26828:
    goto v_26829;
v_26830:
    stack[0] = cons(v_26860, v_26859);
    env = stack[-4];
    goto v_26822;
v_26823:
    goto v_26840;
v_26836:
    v_26859 = stack[-1];
    v_26860 = qcdr(v_26859);
    goto v_26837;
v_26838:
    v_26859 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26839;
v_26840:
    goto v_26836;
v_26837:
    goto v_26838;
v_26839:
    v_26859 = cons(v_26860, v_26859);
    env = stack[-4];
    goto v_26824;
v_26825:
    goto v_26821;
v_26822:
    goto v_26823;
v_26824:
    fn = elt(env, 4); // quotsq
    v_26859 = (*qfn2(fn))(fn, stack[0], v_26859);
    goto v_26817;
v_26818:
    goto v_26814;
v_26815:
    goto v_26816;
v_26817:
    {
        LispObject v_26865 = stack[-2];
        return cons(v_26865, v_26859);
    }
v_26778:
    v_26859 = stack[-2];
    v_26859 = qcdr(v_26859);
    if (v_26859 == nil) goto v_26847;
    goto v_26855;
v_26851:
    v_26859 = stack[-2];
    v_26860 = qcdr(v_26859);
    goto v_26852;
v_26853:
    v_26859 = stack[-1];
    goto v_26854;
v_26855:
    goto v_26851;
v_26852:
    goto v_26853;
v_26854:
    stack[-2] = v_26860;
    stack[-1] = v_26859;
    goto v_26765;
v_26847:
    v_26859 = nil;
    return onevalue(v_26859);
}



// Code for csymbolrd

static LispObject CC_csymbolrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_26788, v_26789, v_26790;
    LispObject fn;
    argcheck(nargs, 0, "csymbolrd");
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
    v_26788 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_26788;
    fn = elt(env, 2); // stats_getargs
    v_26788 = (*qfnn(fn))(fn, 0);
    goto v_26784;
v_26778:
    v_26790 = stack[0];
    goto v_26779;
v_26780:
    v_26789 = nil;
    goto v_26781;
v_26782:
    goto v_26783;
v_26784:
    goto v_26778;
v_26779:
    goto v_26780;
v_26781:
    goto v_26782;
v_26783:
    return list2star(v_26790, v_26789, v_26788);
    return onevalue(v_26788);
}



// Code for sc_scalarproduct

static LispObject CC_sc_scalarproduct(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26832, v_26833, v_26834;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_26767;
    stack[-3] = v_26766;
// end of prologue
    v_26832 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 1); // sc_simp
    v_26832 = (*qfn1(fn))(fn, v_26832);
    env = stack[-5];
    stack[0] = v_26832;
    v_26832 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_26832;
v_26777:
    goto v_26789;
v_26785:
    v_26832 = stack[-2];
    fn = elt(env, 2); // fast!-row!-dim
    v_26833 = (*qfn1(fn))(fn, v_26832);
    env = stack[-5];
    goto v_26786;
v_26787:
    v_26832 = stack[-4];
    goto v_26788;
v_26789:
    goto v_26785;
v_26786:
    goto v_26787;
v_26788:
    v_26832 = difference2(v_26833, v_26832);
    env = stack[-5];
    v_26832 = Lminusp(nil, v_26832);
    env = stack[-5];
    if (v_26832 == nil) goto v_26782;
    goto v_26776;
v_26782:
    goto v_26799;
v_26795:
    stack[-1] = stack[0];
    goto v_26796;
v_26797:
    goto v_26806;
v_26802:
    goto v_26814;
v_26808:
    v_26834 = stack[-3];
    goto v_26809;
v_26810:
    v_26833 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26811;
v_26812:
    v_26832 = stack[-4];
    goto v_26813;
v_26814:
    goto v_26808;
v_26809:
    goto v_26810;
v_26811:
    goto v_26812;
v_26813:
    fn = elt(env, 3); // sc_getmat
    stack[0] = (*qfnn(fn))(fn, 3, v_26834, v_26833, v_26832);
    env = stack[-5];
    goto v_26803;
v_26804:
    goto v_26825;
v_26819:
    v_26834 = stack[-2];
    goto v_26820;
v_26821:
    v_26833 = stack[-4];
    goto v_26822;
v_26823:
    v_26832 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26824;
v_26825:
    goto v_26819;
v_26820:
    goto v_26821;
v_26822:
    goto v_26823;
v_26824:
    fn = elt(env, 3); // sc_getmat
    v_26832 = (*qfnn(fn))(fn, 3, v_26834, v_26833, v_26832);
    env = stack[-5];
    goto v_26805;
v_26806:
    goto v_26802;
v_26803:
    goto v_26804;
v_26805:
    fn = elt(env, 4); // sc_multsq
    v_26832 = (*qfn2(fn))(fn, stack[0], v_26832);
    env = stack[-5];
    goto v_26798;
v_26799:
    goto v_26795;
v_26796:
    goto v_26797;
v_26798:
    fn = elt(env, 5); // sc_addsq
    v_26832 = (*qfn2(fn))(fn, stack[-1], v_26832);
    env = stack[-5];
    stack[0] = v_26832;
    v_26832 = stack[-4];
    v_26832 = add1(v_26832);
    env = stack[-5];
    stack[-4] = v_26832;
    goto v_26777;
v_26776:
    v_26832 = stack[0];
    return onevalue(v_26832);
}



// Code for fortassign

static LispObject CC_fortassign(LispObject env,
                         LispObject v_26766)
{
    env = qenv(env);
    LispObject v_26781, v_26782;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_26781 = v_26766;
// end of prologue
    goto v_26773;
v_26769:
    v_26782 = v_26781;
    v_26782 = qcdr(v_26782);
    v_26782 = qcar(v_26782);
    goto v_26770;
v_26771:
    v_26781 = qcdr(v_26781);
    v_26781 = qcdr(v_26781);
    v_26781 = qcar(v_26781);
    goto v_26772;
v_26773:
    goto v_26769;
v_26770:
    goto v_26771;
v_26772:
    {
        fn = elt(env, 1); // mkffortassign
        return (*qfn2(fn))(fn, v_26782, v_26781);
    }
}



// Code for ordpl

static LispObject CC_ordpl(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26816, v_26817, v_26818, v_26819;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_26817 = v_26767;
    v_26818 = v_26766;
// end of prologue
v_26771:
    v_26816 = v_26818;
    if (!consp(v_26816)) goto v_26774;
    else goto v_26775;
v_26774:
    goto v_26782;
v_26778:
    v_26816 = v_26818;
    goto v_26779;
v_26780:
    goto v_26781;
v_26782:
    goto v_26778;
v_26779:
    goto v_26780;
v_26781:
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_26816, v_26817);
    }
v_26775:
    v_26816 = v_26817;
    if (!consp(v_26816)) goto v_26785;
    else goto v_26786;
v_26785:
    v_26816 = lisp_true;
    goto v_26770;
v_26786:
    goto v_26795;
v_26791:
    v_26816 = v_26818;
    v_26819 = qcar(v_26816);
    goto v_26792;
v_26793:
    v_26816 = v_26817;
    v_26816 = qcar(v_26816);
    goto v_26794;
v_26795:
    goto v_26791;
v_26792:
    goto v_26793;
v_26794:
    if (equal(v_26819, v_26816)) goto v_26789;
    else goto v_26790;
v_26789:
    v_26816 = v_26818;
    v_26816 = qcdr(v_26816);
    v_26818 = v_26816;
    v_26816 = v_26817;
    v_26816 = qcdr(v_26816);
    v_26817 = v_26816;
    goto v_26771;
v_26790:
    goto v_26811;
v_26807:
    v_26816 = v_26818;
    v_26816 = qcar(v_26816);
    goto v_26808;
v_26809:
    v_26817 = qcar(v_26817);
    goto v_26810;
v_26811:
    goto v_26807;
v_26808:
    goto v_26809;
v_26810:
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_26816, v_26817);
    }
    v_26816 = nil;
v_26770:
    return onevalue(v_26816);
}



// Code for strand!-alg!-top

static LispObject CC_strandKalgKtop(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_26811, v_26812, v_26813;
    LispObject fn;
    LispObject v_26768, v_26767, v_26766;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "strand-alg-top");
    va_start(aa, nargs);
    v_26766 = va_arg(aa, LispObject);
    v_26767 = va_arg(aa, LispObject);
    v_26768 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_26768,v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_26766,v_26767,v_26768);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_26768;
    stack[-1] = v_26767;
    stack[-2] = v_26766;
// end of prologue
    goto v_26778;
v_26774:
    v_26812 = stack[-2];
    goto v_26775;
v_26776:
    v_26811 = stack[0];
    goto v_26777;
v_26778:
    goto v_26774;
v_26775:
    goto v_26776;
v_26777:
    fn = elt(env, 1); // deletez1
    v_26811 = (*qfn2(fn))(fn, v_26812, v_26811);
    env = stack[-3];
    stack[-2] = v_26811;
    goto v_26788;
v_26782:
    v_26813 = stack[0];
    goto v_26783;
v_26784:
    v_26812 = stack[-1];
    goto v_26785;
v_26786:
    v_26811 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26787;
v_26788:
    goto v_26782;
v_26783:
    goto v_26784;
v_26785:
    goto v_26786;
v_26787:
    fn = elt(env, 2); // color!-strand
    v_26811 = (*qfnn(fn))(fn, 3, v_26813, v_26812, v_26811);
    env = stack[-3];
    stack[0] = v_26811;
    goto v_26797;
v_26793:
    v_26812 = stack[-2];
    goto v_26794;
v_26795:
    v_26811 = stack[0];
    goto v_26796;
v_26797:
    goto v_26793;
v_26794:
    goto v_26795;
v_26796:
    fn = elt(env, 3); // contract!-strand
    v_26811 = (*qfn2(fn))(fn, v_26812, v_26811);
    env = stack[-3];
    stack[-2] = v_26811;
    goto v_26807;
v_26801:
    v_26813 = stack[-2];
    goto v_26802;
v_26803:
    v_26812 = stack[0];
    goto v_26804;
v_26805:
    v_26811 = nil;
    goto v_26806;
v_26807:
    goto v_26801;
v_26802:
    goto v_26803;
v_26804:
    goto v_26805;
v_26806:
    {
        fn = elt(env, 4); // dstr!-to!-alg
        return (*qfnn(fn))(fn, 3, v_26813, v_26812, v_26811);
    }
    return onevalue(v_26811);
}



// Code for inormmat

static LispObject CC_inormmat(LispObject env,
                         LispObject v_26766)
{
    env = qenv(env);
    LispObject v_26896, v_26897;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_26766);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    v_26896 = v_26766;
// end of prologue
    stack[-6] = nil;
    stack[-5] = v_26896;
v_26776:
    v_26896 = stack[-5];
    if (v_26896 == nil) goto v_26780;
    else goto v_26781;
v_26780:
    goto v_26775;
v_26781:
    v_26896 = stack[-5];
    v_26896 = qcar(v_26896);
    stack[-1] = v_26896;
    v_26896 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-7] = v_26896;
    v_26896 = stack[-1];
    stack[0] = v_26896;
v_26791:
    v_26896 = stack[0];
    if (v_26896 == nil) goto v_26795;
    else goto v_26796;
v_26795:
    goto v_26790;
v_26796:
    v_26896 = stack[0];
    v_26896 = qcar(v_26896);
    goto v_26807;
v_26803:
    v_26897 = stack[-7];
    goto v_26804;
v_26805:
    v_26896 = qcdr(v_26896);
    goto v_26806;
v_26807:
    goto v_26803;
v_26804:
    goto v_26805;
v_26806:
    fn = elt(env, 1); // ilcm
    v_26896 = (*qfn2(fn))(fn, v_26897, v_26896);
    env = stack[-8];
    stack[-7] = v_26896;
    v_26896 = stack[0];
    v_26896 = qcdr(v_26896);
    stack[0] = v_26896;
    goto v_26791;
v_26790:
    goto v_26818;
v_26814:
    v_26896 = stack[-1];
    stack[-4] = v_26896;
    v_26896 = stack[-4];
    if (v_26896 == nil) goto v_26828;
    else goto v_26829;
v_26828:
    v_26896 = nil;
    v_26897 = v_26896;
    goto v_26823;
v_26829:
    v_26896 = stack[-4];
    v_26896 = qcar(v_26896);
    goto v_26841;
v_26837:
    v_26897 = v_26896;
    stack[0] = qcar(v_26897);
    goto v_26838;
v_26839:
    goto v_26849;
v_26845:
    v_26897 = stack[-7];
    goto v_26846;
v_26847:
    v_26896 = qcdr(v_26896);
    goto v_26848;
v_26849:
    goto v_26845;
v_26846:
    goto v_26847;
v_26848:
    v_26896 = quot2(v_26897, v_26896);
    env = stack[-8];
    goto v_26840;
v_26841:
    goto v_26837;
v_26838:
    goto v_26839;
v_26840:
    v_26896 = times2(stack[0], v_26896);
    env = stack[-8];
    v_26896 = ncons(v_26896);
    env = stack[-8];
    stack[-2] = v_26896;
    stack[-3] = v_26896;
v_26824:
    v_26896 = stack[-4];
    v_26896 = qcdr(v_26896);
    stack[-4] = v_26896;
    v_26896 = stack[-4];
    if (v_26896 == nil) goto v_26857;
    else goto v_26858;
v_26857:
    v_26896 = stack[-3];
    v_26897 = v_26896;
    goto v_26823;
v_26858:
    goto v_26866;
v_26862:
    stack[-1] = stack[-2];
    goto v_26863;
v_26864:
    v_26896 = stack[-4];
    v_26896 = qcar(v_26896);
    goto v_26877;
v_26873:
    v_26897 = v_26896;
    stack[0] = qcar(v_26897);
    goto v_26874;
v_26875:
    goto v_26885;
v_26881:
    v_26897 = stack[-7];
    goto v_26882;
v_26883:
    v_26896 = qcdr(v_26896);
    goto v_26884;
v_26885:
    goto v_26881;
v_26882:
    goto v_26883;
v_26884:
    v_26896 = quot2(v_26897, v_26896);
    env = stack[-8];
    goto v_26876;
v_26877:
    goto v_26873;
v_26874:
    goto v_26875;
v_26876:
    v_26896 = times2(stack[0], v_26896);
    env = stack[-8];
    v_26896 = ncons(v_26896);
    env = stack[-8];
    goto v_26865;
v_26866:
    goto v_26862;
v_26863:
    goto v_26864;
v_26865:
    v_26896 = Lrplacd(nil, stack[-1], v_26896);
    env = stack[-8];
    v_26896 = stack[-2];
    v_26896 = qcdr(v_26896);
    stack[-2] = v_26896;
    goto v_26824;
v_26823:
    goto v_26815;
v_26816:
    v_26896 = stack[-6];
    goto v_26817;
v_26818:
    goto v_26814;
v_26815:
    goto v_26816;
v_26817:
    v_26896 = cons(v_26897, v_26896);
    env = stack[-8];
    stack[-6] = v_26896;
    v_26896 = stack[-5];
    v_26896 = qcdr(v_26896);
    stack[-5] = v_26896;
    goto v_26776;
v_26775:
    v_26896 = stack[-6];
        return Lreverse(nil, v_26896);
    return onevalue(v_26896);
}



// Code for zfactor1

static LispObject CC_zfactor1(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26966, v_26967, v_26968;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_26767;
    stack[-4] = v_26766;
// end of prologue
    stack[0] = nil;
v_26772:
    goto v_26782;
v_26778:
    v_26967 = stack[-4];
    goto v_26779;
v_26780:
    v_26966 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_26781;
v_26782:
    goto v_26778;
v_26779:
    goto v_26780;
v_26781:
    v_26966 = (LispObject)lessp2(v_26967, v_26966);
    v_26966 = v_26966 ? lisp_true : nil;
    env = stack[-6];
    if (v_26966 == nil) goto v_26776;
    goto v_26792;
v_26786:
    v_26968 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_26787;
v_26788:
    v_26967 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26789;
v_26790:
    v_26966 = stack[0];
    goto v_26791;
v_26792:
    goto v_26786;
v_26787:
    goto v_26788;
v_26789:
    goto v_26790;
v_26791:
    v_26966 = acons(v_26968, v_26967, v_26966);
    env = stack[-6];
    stack[0] = v_26966;
    v_26966 = stack[-4];
    v_26966 = negate(v_26966);
    env = stack[-6];
    stack[-4] = v_26966;
    goto v_26772;
v_26776:
    goto v_26805;
v_26801:
    v_26967 = stack[-4];
    goto v_26802;
v_26803:
    v_26966 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_26804;
v_26805:
    goto v_26801;
v_26802:
    goto v_26803;
v_26804:
    v_26966 = (LispObject)lessp2(v_26967, v_26966);
    v_26966 = v_26966 ? lisp_true : nil;
    env = stack[-6];
    if (v_26966 == nil) goto v_26799;
    goto v_26813;
v_26809:
    goto v_26810;
v_26811:
    goto v_26821;
v_26817:
    v_26967 = stack[-4];
    goto v_26818;
v_26819:
    v_26966 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26820;
v_26821:
    goto v_26817;
v_26818:
    goto v_26819;
v_26820:
    v_26966 = cons(v_26967, v_26966);
    env = stack[-6];
    v_26966 = ncons(v_26966);
    env = stack[-6];
    goto v_26812;
v_26813:
    goto v_26809;
v_26810:
    goto v_26811;
v_26812:
    {
        LispObject v_26975 = stack[0];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_26975, v_26966);
    }
v_26799:
    goto v_26831;
v_26827:
    stack[-5] = stack[0];
    goto v_26828;
v_26829:
    v_26966 = qvalue(elt(env, 1)); // !*primelist!*
    stack[-2] = v_26966;
    v_26966 = nil;
    stack[-1] = v_26966;
v_26843:
    v_26966 = stack[-2];
    if (v_26966 == nil) goto v_26846;
    else goto v_26847;
v_26846:
    goto v_26842;
v_26847:
    v_26966 = stack[-2];
    v_26966 = qcar(v_26966);
    stack[0] = v_26966;
    v_26966 = stack[-2];
    v_26966 = qcdr(v_26966);
    stack[-2] = v_26966;
v_26856:
    goto v_26865;
v_26861:
    goto v_26871;
v_26867:
    v_26967 = stack[-4];
    goto v_26868;
v_26869:
    v_26966 = stack[0];
    goto v_26870;
v_26871:
    goto v_26867;
v_26868:
    goto v_26869;
v_26870:
    v_26966 = Ldivide(nil, v_26967, v_26966);
    env = stack[-6];
    v_26968 = v_26966;
    v_26967 = qcdr(v_26966);
    goto v_26862;
v_26863:
    v_26966 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_26864;
v_26865:
    goto v_26861;
v_26862:
    goto v_26863;
v_26864:
    if (v_26967 == v_26966) goto v_26860;
    goto v_26855;
v_26860:
    v_26966 = v_26968;
    v_26966 = qcar(v_26966);
    stack[-4] = v_26966;
    goto v_26884;
v_26880:
    v_26967 = stack[0];
    goto v_26881;
v_26882:
    v_26966 = stack[-1];
    goto v_26883;
v_26884:
    goto v_26880;
v_26881:
    goto v_26882;
v_26883:
    fn = elt(env, 3); // add!-factor
    v_26966 = (*qfn2(fn))(fn, v_26967, v_26966);
    env = stack[-6];
    stack[-1] = v_26966;
    goto v_26856;
v_26855:
    goto v_26899;
v_26895:
    v_26967 = stack[-4];
    goto v_26896;
v_26897:
    v_26966 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26898;
v_26899:
    goto v_26895;
v_26896:
    goto v_26897;
v_26898:
    if (v_26967 == v_26966) goto v_26894;
    goto v_26907;
v_26903:
    goto v_26913;
v_26909:
    v_26967 = stack[0];
    goto v_26910;
v_26911:
    v_26966 = stack[0];
    goto v_26912;
v_26913:
    goto v_26909;
v_26910:
    goto v_26911;
v_26912:
    v_26967 = times2(v_26967, v_26966);
    env = stack[-6];
    goto v_26904;
v_26905:
    v_26966 = stack[-4];
    goto v_26906;
v_26907:
    goto v_26903;
v_26904:
    goto v_26905;
v_26906:
    v_26966 = (LispObject)greaterp2(v_26967, v_26966);
    v_26966 = v_26966 ? lisp_true : nil;
    env = stack[-6];
    goto v_26892;
v_26894:
    v_26966 = nil;
    goto v_26892;
    v_26966 = nil;
v_26892:
    if (v_26966 == nil) goto v_26890;
    v_26966 = nil;
    stack[-2] = v_26966;
    goto v_26926;
v_26922:
    v_26967 = stack[-4];
    goto v_26923;
v_26924:
    v_26966 = stack[-1];
    goto v_26925;
v_26926:
    goto v_26922;
v_26923:
    goto v_26924;
v_26925:
    fn = elt(env, 3); // add!-factor
    v_26966 = (*qfn2(fn))(fn, v_26967, v_26966);
    env = stack[-6];
    stack[-1] = v_26966;
    v_26966 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_26966;
    goto v_26888;
v_26890:
v_26888:
    goto v_26843;
v_26842:
    goto v_26938;
v_26934:
    v_26967 = stack[-4];
    goto v_26935;
v_26936:
    v_26966 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26937;
v_26938:
    goto v_26934;
v_26935:
    goto v_26936;
v_26937:
    if (v_26967 == v_26966) goto v_26932;
    else goto v_26933;
v_26932:
    v_26966 = stack[-1];
    goto v_26931;
v_26933:
    v_26966 = stack[-3];
    if (v_26966 == nil) goto v_26942;
    else goto v_26943;
v_26942:
    goto v_26952;
v_26946:
    v_26968 = stack[-4];
    goto v_26947;
v_26948:
    v_26967 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26949;
v_26950:
    v_26966 = stack[-1];
    goto v_26951;
v_26952:
    goto v_26946;
v_26947:
    goto v_26948;
v_26949:
    goto v_26950;
v_26951:
    v_26966 = acons(v_26968, v_26967, v_26966);
    env = stack[-6];
    goto v_26931;
v_26943:
    goto v_26963;
v_26959:
    v_26967 = stack[-4];
    goto v_26960;
v_26961:
    v_26966 = stack[-1];
    goto v_26962;
v_26963:
    goto v_26959;
v_26960:
    goto v_26961;
v_26962:
    fn = elt(env, 4); // mcfactor!*
    v_26966 = (*qfn2(fn))(fn, v_26967, v_26966);
    env = stack[-6];
    goto v_26931;
    v_26966 = nil;
v_26931:
    goto v_26830;
v_26831:
    goto v_26827;
v_26828:
    goto v_26829;
v_26830:
    {
        LispObject v_26976 = stack[-5];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_26976, v_26966);
    }
    v_26966 = nil;
    return onevalue(v_26966);
}



// Code for noncomfree

static LispObject CC_noncomfree(LispObject env,
                         LispObject v_26766)
{
    env = qenv(env);
    LispObject v_26799;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_26766);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_26766;
// end of prologue
v_26765:
    v_26799 = stack[0];
    if (symbolp(v_26799)) goto v_26770;
    else goto v_26771;
v_26770:
    v_26799 = stack[0];
    if (!symbolp(v_26799)) v_26799 = nil;
    else { v_26799 = qfastgets(v_26799);
           if (v_26799 != nil) { v_26799 = elt(v_26799, 0); // noncom
#ifdef RECORD_GET
             if (v_26799 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_26799 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_26799 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_26799 == SPID_NOPROP) v_26799 = nil; else v_26799 = lisp_true; }}
#endif
    v_26799 = (v_26799 == nil ? lisp_true : nil);
    goto v_26769;
v_26771:
    v_26799 = stack[0];
    if (!consp(v_26799)) goto v_26780;
    else goto v_26781;
v_26780:
    v_26799 = lisp_true;
    goto v_26779;
v_26781:
    v_26799 = stack[0];
    v_26799 = qcar(v_26799);
    v_26799 = CC_noncomfree(elt(env, 0), v_26799);
    env = stack[-1];
    if (v_26799 == nil) goto v_26788;
    else goto v_26789;
v_26788:
    v_26799 = nil;
    goto v_26787;
v_26789:
    v_26799 = stack[0];
    v_26799 = qcdr(v_26799);
    stack[0] = v_26799;
    goto v_26765;
    v_26799 = nil;
v_26787:
    goto v_26779;
    v_26799 = nil;
v_26779:
    goto v_26769;
    v_26799 = nil;
v_26769:
    return onevalue(v_26799);
}



// Code for tayexp!-max2

static LispObject CC_tayexpKmax2(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26785, v_26786;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_26767;
    stack[-1] = v_26766;
// end of prologue
    goto v_26778;
v_26774:
    v_26786 = stack[-1];
    goto v_26775;
v_26776:
    v_26785 = stack[0];
    goto v_26777;
v_26778:
    goto v_26774;
v_26775:
    goto v_26776;
v_26777:
    fn = elt(env, 1); // tayexp!-lessp
    v_26785 = (*qfn2(fn))(fn, v_26786, v_26785);
    if (v_26785 == nil) goto v_26772;
    v_26785 = stack[0];
    goto v_26770;
v_26772:
    v_26785 = stack[-1];
    goto v_26770;
    v_26785 = nil;
v_26770:
    return onevalue(v_26785);
}



// Code for cl_replace!-varl

static LispObject CC_cl_replaceKvarl(LispObject env,
                         LispObject v_26766)
{
    env = qenv(env);
    LispObject v_26873, v_26874, v_26875;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_26766);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_26873 = v_26766;
// end of prologue
    stack[0] = nil;
    fn = elt(env, 1); // cl_varl1
    v_26873 = (*qfn1(fn))(fn, v_26873);
    env = stack[-4];
    v_26874 = v_26873;
    v_26873 = v_26874;
    v_26873 = qcar(v_26873);
    stack[-3] = v_26873;
    v_26873 = v_26874;
    v_26873 = qcdr(v_26873);
    stack[-2] = v_26873;
    goto v_26790;
v_26786:
    v_26874 = stack[-3];
    goto v_26787;
v_26788:
    v_26873 = stack[-2];
    goto v_26789;
v_26790:
    goto v_26786;
v_26787:
    goto v_26788;
v_26789:
    v_26873 = Lappend(nil, v_26874, v_26873);
    env = stack[-4];
    stack[-1] = v_26873;
v_26795:
    v_26873 = stack[-2];
    if (v_26873 == nil) goto v_26798;
    else goto v_26799;
v_26798:
    goto v_26794;
v_26799:
    v_26873 = stack[-2];
    v_26873 = qcar(v_26873);
    v_26874 = v_26873;
    v_26873 = stack[-2];
    v_26873 = qcdr(v_26873);
    stack[-2] = v_26873;
    v_26873 = v_26874;
    v_26875 = v_26873;
    goto v_26819;
v_26815:
    v_26874 = v_26875;
    goto v_26816;
v_26817:
    v_26873 = stack[-3];
    goto v_26818;
v_26819:
    goto v_26815;
v_26816:
    goto v_26817;
v_26818:
    v_26873 = Lmemq(nil, v_26874, v_26873);
    if (v_26873 == nil) goto v_26814;
    goto v_26831;
v_26827:
    v_26874 = v_26875;
    goto v_26828;
v_26829:
    v_26873 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26830;
v_26831:
    goto v_26827;
v_26828:
    goto v_26829;
v_26830:
    v_26873 = cons(v_26874, v_26873);
    env = stack[-4];
    goto v_26839;
v_26835:
    v_26874 = v_26873;
    goto v_26836;
v_26837:
    v_26873 = stack[0];
    goto v_26838;
v_26839:
    goto v_26835;
v_26836:
    goto v_26837;
v_26838:
    v_26873 = cons(v_26874, v_26873);
    env = stack[-4];
    stack[0] = v_26873;
    goto v_26812;
v_26814:
    goto v_26853;
v_26849:
    v_26874 = v_26875;
    goto v_26850;
v_26851:
    v_26873 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_26852;
v_26853:
    goto v_26849;
v_26850:
    goto v_26851;
v_26852:
    v_26873 = cons(v_26874, v_26873);
    env = stack[-4];
    goto v_26861;
v_26857:
    v_26874 = v_26873;
    goto v_26858;
v_26859:
    v_26873 = stack[0];
    goto v_26860;
v_26861:
    goto v_26857;
v_26858:
    goto v_26859;
v_26860:
    v_26873 = cons(v_26874, v_26873);
    env = stack[-4];
    stack[0] = v_26873;
    goto v_26812;
v_26812:
    goto v_26795;
v_26794:
    goto v_26870;
v_26866:
    v_26874 = stack[-1];
    goto v_26867;
v_26868:
    v_26873 = stack[0];
    goto v_26869;
v_26870:
    goto v_26866;
v_26867:
    goto v_26868;
v_26869:
    return cons(v_26874, v_26873);
    return onevalue(v_26873);
}



// Code for qqe_simplqneq

static LispObject CC_qqe_simplqneq(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26840, v_26841, v_26842;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_26841 = v_26767;
    v_26840 = v_26766;
// end of prologue
    v_26841 = v_26840;
    v_26841 = qcdr(v_26841);
    v_26841 = qcar(v_26841);
    v_26840 = qcdr(v_26840);
    v_26840 = qcdr(v_26840);
    v_26840 = qcar(v_26840);
    goto v_26789;
v_26785:
    goto v_26797;
v_26791:
    v_26842 = elt(env, 1); // qequal
    goto v_26792;
v_26793:
    goto v_26794;
v_26795:
    goto v_26796;
v_26797:
    goto v_26791;
v_26792:
    goto v_26793;
v_26794:
    goto v_26795;
v_26796:
    fn = elt(env, 5); // qqe_mk2
    v_26841 = (*qfnn(fn))(fn, 3, v_26842, v_26841, v_26840);
    env = stack[-3];
    goto v_26786;
v_26787:
    v_26840 = nil;
    goto v_26788;
v_26789:
    goto v_26785;
v_26786:
    goto v_26787;
v_26788:
    fn = elt(env, 6); // qqe_simplqequal
    v_26840 = (*qfn2(fn))(fn, v_26841, v_26840);
    env = stack[-3];
    stack[-2] = v_26840;
    goto v_26810;
v_26806:
    v_26841 = stack[-2];
    goto v_26807;
v_26808:
    v_26840 = elt(env, 2); // true
    goto v_26809;
v_26810:
    goto v_26806;
v_26807:
    goto v_26808;
v_26809:
    if (v_26841 == v_26840) goto v_26804;
    else goto v_26805;
v_26804:
    v_26840 = elt(env, 3); // false
    goto v_26803;
v_26805:
    goto v_26820;
v_26816:
    v_26841 = stack[-2];
    goto v_26817;
v_26818:
    v_26840 = elt(env, 3); // false
    goto v_26819;
v_26820:
    goto v_26816;
v_26817:
    goto v_26818;
v_26819:
    if (v_26841 == v_26840) goto v_26814;
    else goto v_26815;
v_26814:
    v_26840 = elt(env, 2); // true
    goto v_26803;
v_26815:
    goto v_26833;
v_26827:
    stack[-1] = elt(env, 4); // qneq
    goto v_26828;
v_26829:
    v_26840 = stack[-2];
    fn = elt(env, 7); // qqe_arg2l
    stack[0] = (*qfn1(fn))(fn, v_26840);
    env = stack[-3];
    goto v_26830;
v_26831:
    v_26840 = stack[-2];
    fn = elt(env, 8); // qqe_arg2r
    v_26840 = (*qfn1(fn))(fn, v_26840);
    env = stack[-3];
    goto v_26832;
v_26833:
    goto v_26827;
v_26828:
    goto v_26829;
v_26830:
    goto v_26831;
v_26832:
    fn = elt(env, 5); // qqe_mk2
    v_26840 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_26840);
    goto v_26803;
v_26803:
    return onevalue(v_26840);
}



// Code for cnml

static LispObject CC_cnml(LispObject env,
                         LispObject v_26766)
{
    env = qenv(env);
    LispObject v_26787, v_26788;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_26766);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_26766;
// end of prologue
    v_26787 = elt(env, 1); // "<cn"
    fn = elt(env, 4); // printout
    v_26787 = (*qfn1(fn))(fn, v_26787);
    env = stack[-1];
    goto v_26777;
v_26773:
    v_26787 = stack[0];
    v_26788 = qcar(v_26787);
    goto v_26774;
v_26775:
    v_26787 = elt(env, 2); // ""
    goto v_26776;
v_26777:
    goto v_26773;
v_26774:
    goto v_26775;
v_26776:
    fn = elt(env, 5); // attributesml
    v_26787 = (*qfn2(fn))(fn, v_26788, v_26787);
    env = stack[-1];
    v_26787 = stack[0];
    v_26787 = qcdr(v_26787);
    v_26787 = qcar(v_26787);
    v_26787 = Lprinc(nil, v_26787);
    env = stack[-1];
    v_26787 = elt(env, 3); // "</cn>"
    v_26787 = Lprinc(nil, v_26787);
    v_26787 = nil;
    return onevalue(v_26787);
}



// Code for d2int

static LispObject CC_d2int(LispObject env,
                         LispObject v_26766)
{
    env = qenv(env);
    LispObject v_26850, v_26851, v_26852;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_26766);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_26851 = v_26766;
// end of prologue
    goto v_26776;
v_26772:
    v_26850 = v_26851;
    v_26852 = qcdr(v_26850);
    goto v_26773;
v_26774:
    v_26850 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26775;
v_26776:
    goto v_26772;
v_26773:
    goto v_26774;
v_26775:
    if (v_26852 == v_26850) goto v_26771;
    v_26850 = nil;
    goto v_26769;
v_26771:
    v_26850 = v_26851;
    v_26850 = qcar(v_26850);
    v_26851 = v_26850;
    if (is_number(v_26850)) goto v_26781;
    else goto v_26782;
v_26781:
    v_26850 = v_26851;
    goto v_26769;
v_26782:
    v_26850 = v_26851;
    if (!consp(v_26850)) goto v_26794;
    else goto v_26795;
v_26794:
    v_26850 = lisp_true;
    goto v_26793;
v_26795:
    v_26850 = v_26851;
    v_26850 = qcar(v_26850);
    v_26850 = (consp(v_26850) ? nil : lisp_true);
    goto v_26793;
    v_26850 = nil;
v_26793:
    if (v_26850 == nil) goto v_26790;
    else goto v_26791;
v_26790:
    v_26850 = lisp_true;
    goto v_26789;
v_26791:
    goto v_26810;
v_26806:
    v_26850 = v_26851;
    v_26852 = qcar(v_26850);
    goto v_26807;
v_26808:
    v_26850 = elt(env, 1); // !:rd!:
    goto v_26809;
v_26810:
    goto v_26806;
v_26807:
    goto v_26808;
v_26809:
    v_26850 = (v_26852 == v_26850 ? lisp_true : nil);
    v_26850 = (v_26850 == nil ? lisp_true : nil);
    goto v_26789;
    v_26850 = nil;
v_26789:
    if (v_26850 == nil) goto v_26787;
    v_26850 = nil;
    goto v_26769;
v_26787:
    v_26850 = v_26851;
    v_26850 = qcdr(v_26850);
    stack[-1] = v_26850;
    v_26850 = stack[-1];
    v_26850 = Ltruncate(nil, v_26850);
    env = stack[-2];
    stack[0] = v_26850;
    goto v_26834;
v_26830:
    goto v_26841;
v_26837:
    v_26850 = stack[0];
    v_26851 = Lfloat(nil, v_26850);
    env = stack[-2];
    goto v_26838;
v_26839:
    v_26850 = stack[-1];
    goto v_26840;
v_26841:
    goto v_26837;
v_26838:
    goto v_26839;
v_26840:
    v_26850 = difference2(v_26851, v_26850);
    env = stack[-2];
    v_26851 = Labsval(nil, v_26850);
    env = stack[-2];
    goto v_26831;
v_26832:
    v_26850 = qvalue(elt(env, 2)); // !!fleps1
    goto v_26833;
v_26834:
    goto v_26830;
v_26831:
    goto v_26832;
v_26833:
    v_26850 = (LispObject)lessp2(v_26851, v_26850);
    v_26850 = v_26850 ? lisp_true : nil;
    if (v_26850 == nil) goto v_26828;
    v_26850 = stack[0];
    goto v_26826;
v_26828:
    v_26850 = nil;
    goto v_26826;
    v_26850 = nil;
v_26826:
    goto v_26769;
    v_26850 = nil;
v_26769:
    return onevalue(v_26850);
}



// Code for tchscheme2

static LispObject CC_tchscheme2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_26794, v_26795;
    LispObject fn;
    argcheck(nargs, 0, "tchscheme2");
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
    v_26794 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_26794;
v_26772:
    goto v_26784;
v_26780:
    v_26795 = qvalue(elt(env, 1)); // rowmax
    goto v_26781;
v_26782:
    v_26794 = stack[0];
    goto v_26783;
v_26784:
    goto v_26780;
v_26781:
    goto v_26782;
v_26783:
    v_26794 = difference2(v_26795, v_26794);
    env = stack[-1];
    v_26794 = Lminusp(nil, v_26794);
    env = stack[-1];
    if (v_26794 == nil) goto v_26777;
    goto v_26771;
v_26777:
    v_26794 = stack[0];
    fn = elt(env, 2); // removechild
    v_26794 = (*qfn1(fn))(fn, v_26794);
    env = stack[-1];
    v_26794 = stack[0];
    fn = elt(env, 3); // to!*scheme
    v_26794 = (*qfn1(fn))(fn, v_26794);
    env = stack[-1];
    v_26794 = stack[0];
    v_26794 = add1(v_26794);
    env = stack[-1];
    stack[0] = v_26794;
    goto v_26772;
v_26771:
    v_26794 = nil;
    return onevalue(v_26794);
}



// Code for sroot1

static LispObject CC_sroot1(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26951, v_26952, v_26953, v_26954;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_26767;
    stack[-3] = v_26766;
// end of prologue
// Binding freevars
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-5, 1, -2);
    qvalue(elt(env, 1)) = nil; // freevars
// Binding substitution
// FLUIDBIND: reloadenv=5 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 2, -1);
    qvalue(elt(env, 2)) = nil; // substitution
    goto v_26787;
v_26783:
    v_26952 = qvalue(elt(env, 3)); // rpt
    goto v_26784;
v_26785:
    v_26951 = elt(env, 4); // inf
    goto v_26786;
v_26787:
    goto v_26783;
v_26784:
    goto v_26785;
v_26786:
    if (v_26952 == v_26951) goto v_26782;
    goto v_26795;
v_26791:
    v_26952 = qvalue(elt(env, 3)); // rpt
    goto v_26792;
v_26793:
    v_26951 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_26794;
v_26795:
    goto v_26791;
v_26792:
    goto v_26793;
v_26794:
    v_26951 = (LispObject)lesseq2(v_26952, v_26951);
    v_26951 = v_26951 ? lisp_true : nil;
    env = stack[-5];
    goto v_26780;
v_26782:
    v_26951 = nil;
    goto v_26780;
    v_26951 = nil;
v_26780:
    if (v_26951 == nil) goto v_26778;
    else goto v_26776;
v_26778:
    v_26951 = stack[-3];
    if (!consp(v_26951)) goto v_26804;
    else goto v_26805;
v_26804:
    v_26951 = lisp_true;
    goto v_26803;
v_26805:
    goto v_26815;
v_26811:
    v_26951 = stack[-3];
    v_26952 = qcar(v_26951);
    goto v_26812;
v_26813:
    v_26951 = stack[0];
    v_26951 = qcdr(v_26951);
    v_26951 = qcar(v_26951);
    v_26951 = qcar(v_26951);
    goto v_26814;
v_26815:
    goto v_26811;
v_26812:
    goto v_26813;
v_26814:
    v_26951 = Lneq(nil, v_26952, v_26951);
    env = stack[-5];
    goto v_26803;
    v_26951 = nil;
v_26803:
    if (v_26951 == nil) goto v_26801;
    else goto v_26776;
v_26801:
    goto v_26777;
v_26776:
    v_26951 = stack[-3];
    goto v_26773;
v_26777:
    goto v_26828;
v_26824:
    v_26951 = stack[0];
    v_26951 = qcdr(v_26951);
    v_26951 = qcar(v_26951);
    fn = elt(env, 10); // findnewvars
    v_26952 = (*qfn1(fn))(fn, v_26951);
    env = stack[-5];
    goto v_26825;
v_26826:
    v_26951 = nil;
    goto v_26827;
v_26828:
    goto v_26824;
v_26825:
    goto v_26826;
v_26827:
    fn = elt(env, 11); // union
    v_26951 = (*qfn2(fn))(fn, v_26952, v_26951);
    env = stack[-5];
    qvalue(elt(env, 1)) = v_26951; // freevars
    v_26951 = stack[0];
    v_26951 = qcdr(v_26951);
    v_26951 = qcdr(v_26951);
    v_26951 = qcar(v_26951);
    qvalue(elt(env, 2)) = v_26951; // substitution
    v_26951 = qvalue(elt(env, 1)); // freevars
    stack[-4] = v_26951;
v_26841:
    v_26951 = stack[-4];
    if (v_26951 == nil) goto v_26845;
    else goto v_26846;
v_26845:
    goto v_26840;
v_26846:
    v_26951 = stack[-4];
    v_26951 = qcar(v_26951);
    fn = elt(env, 12); // newenv
    v_26951 = (*qfn1(fn))(fn, v_26951);
    env = stack[-5];
    v_26951 = stack[-4];
    v_26951 = qcdr(v_26951);
    stack[-4] = v_26951;
    goto v_26841;
v_26840:
    v_26951 = qvalue(elt(env, 5)); // !*trpm
    if (v_26951 == nil) goto v_26859;
    v_26951 = elt(env, 6); // "Trying rule  "
    v_26951 = Lprinc(nil, v_26951);
    env = stack[-5];
    v_26951 = stack[0];
    fn = elt(env, 13); // rprint
    v_26951 = (*qfn1(fn))(fn, v_26951);
    env = stack[-5];
    v_26951 = elt(env, 7); // "against      "
    v_26951 = Lprinc(nil, v_26951);
    env = stack[-5];
    v_26951 = stack[-3];
    fn = elt(env, 13); // rprint
    v_26951 = (*qfn1(fn))(fn, v_26951);
    env = stack[-5];
    goto v_26857;
v_26859:
v_26857:
    goto v_26880;
v_26872:
    v_26951 = stack[0];
    v_26951 = qcdr(v_26951);
    v_26954 = qcar(v_26951);
    goto v_26873;
v_26874:
    v_26953 = stack[-3];
    goto v_26875;
v_26876:
    v_26952 = lisp_true;
    goto v_26877;
v_26878:
    v_26951 = nil;
    goto v_26879;
v_26880:
    goto v_26872;
v_26873:
    goto v_26874;
v_26875:
    goto v_26876;
v_26877:
    goto v_26878;
v_26879:
    fn = elt(env, 14); // amatch
    v_26951 = (*qfnn(fn))(fn, 4, v_26954, v_26953, v_26952, v_26951);
    env = stack[-5];
    stack[-4] = v_26951;
    v_26951 = qvalue(elt(env, 5)); // !*trpm
    if (v_26951 == nil) goto v_26890;
    v_26951 = stack[-4];
    if (v_26951 == nil) goto v_26895;
    v_26951 = elt(env, 8); // "producing    "
    v_26951 = Lprinc(nil, v_26951);
    env = stack[-5];
    v_26951 = stack[-4];
    fn = elt(env, 15); // embed!-null!-fn
    v_26951 = (*qfn1(fn))(fn, v_26951);
    env = stack[-5];
    stack[-4] = v_26951;
    fn = elt(env, 13); // rprint
    v_26951 = (*qfn1(fn))(fn, v_26951);
    env = stack[-5];
    goto v_26893;
v_26895:
    v_26951 = elt(env, 9); // "failed"
    v_26951 = Lprinc(nil, v_26951);
    env = stack[-5];
    v_26951 = Lterpri(nil, 0);
    env = stack[-5];
    goto v_26893;
v_26893:
    v_26951 = Lterpri(nil, 0);
    env = stack[-5];
    goto v_26888;
v_26890:
v_26888:
    v_26951 = qvalue(elt(env, 1)); // freevars
    stack[0] = v_26951;
v_26913:
    v_26951 = stack[0];
    if (v_26951 == nil) goto v_26917;
    else goto v_26918;
v_26917:
    goto v_26912;
v_26918:
    v_26951 = stack[0];
    v_26951 = qcar(v_26951);
    fn = elt(env, 16); // restorenv
    v_26951 = (*qfn1(fn))(fn, v_26951);
    env = stack[-5];
    v_26951 = stack[0];
    v_26951 = qcdr(v_26951);
    stack[0] = v_26951;
    goto v_26913;
v_26912:
    v_26951 = stack[-4];
    if (v_26951 == nil) goto v_26931;
    goto v_26941;
v_26937:
    v_26952 = qvalue(elt(env, 3)); // rpt
    goto v_26938;
v_26939:
    v_26951 = elt(env, 4); // inf
    goto v_26940;
v_26941:
    goto v_26937;
v_26938:
    goto v_26939;
v_26940:
    if (v_26952 == v_26951) goto v_26936;
    v_26951 = qvalue(elt(env, 3)); // rpt
    v_26951 = sub1(v_26951);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_26951; // rpt
    goto v_26934;
v_26936:
v_26934:
    v_26951 = stack[-4];
    fn = elt(env, 15); // embed!-null!-fn
    v_26951 = (*qfn1(fn))(fn, v_26951);
    goto v_26929;
v_26931:
    v_26951 = stack[-3];
    goto v_26929;
    v_26951 = nil;
v_26929:
v_26773:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_26951);
}



// Code for endmodule

static LispObject CC_endmodule(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_26784;
    LispObject fn;
    argcheck(nargs, 0, "endmodule");
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
    v_26784 = qvalue(elt(env, 1)); // mode!-list!*
    if (v_26784 == nil) goto v_26771;
    else goto v_26772;
v_26771:
    v_26784 = elt(env, 2); // "ENDMODULE called outside module"
    fn = elt(env, 7); // rederr
    v_26784 = (*qfn1(fn))(fn, v_26784);
    env = stack[0];
    goto v_26770;
v_26772:
v_26770:
    v_26784 = nil;
    qvalue(elt(env, 3)) = v_26784; // exportslist!*
    v_26784 = nil;
    qvalue(elt(env, 4)) = v_26784; // importslist!*
    v_26784 = nil;
    v_26784 = ncons(v_26784);
    env = stack[0];
    qvalue(elt(env, 5)) = v_26784; // alglist!*
    v_26784 = qvalue(elt(env, 1)); // mode!-list!*
    v_26784 = qcar(v_26784);
    qvalue(elt(env, 6)) = v_26784; // !*mode
    v_26784 = qvalue(elt(env, 1)); // mode!-list!*
    v_26784 = qcdr(v_26784);
    qvalue(elt(env, 1)) = v_26784; // mode!-list!*
    v_26784 = nil;
    return onevalue(v_26784);
}



// Code for mkprec

static LispObject CC_mkprec(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_26875, v_26876, v_26877;
    argcheck(nargs, 0, "mkprec");
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
    goto v_26778;
v_26774:
    v_26876 = qvalue(elt(env, 1)); // fixedpreclis!*
    goto v_26775;
v_26776:
    v_26875 = qvalue(elt(env, 2)); // preclis!*
    goto v_26777;
v_26778:
    goto v_26774;
v_26775:
    goto v_26776;
v_26777:
    v_26875 = Lappend(nil, v_26876, v_26875);
    env = stack[-4];
    stack[-3] = v_26875;
    v_26875 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_26875;
v_26772:
    v_26875 = stack[-3];
    if (v_26875 == nil) goto v_26784;
    else goto v_26785;
v_26784:
    v_26875 = nil;
    goto v_26771;
v_26785:
    goto v_26795;
v_26789:
    v_26875 = stack[-3];
    v_26877 = qcar(v_26875);
    goto v_26790;
v_26791:
    v_26876 = elt(env, 3); // infix
    goto v_26792;
v_26793:
    v_26875 = stack[-2];
    goto v_26794;
v_26795:
    goto v_26789;
v_26790:
    goto v_26791;
v_26792:
    goto v_26793;
v_26794:
    v_26875 = Lputprop(nil, 3, v_26877, v_26876, v_26875);
    env = stack[-4];
    goto v_26807;
v_26801:
    v_26875 = stack[-3];
    stack[-1] = qcar(v_26875);
    goto v_26802;
v_26803:
    stack[0] = elt(env, 4); // op
    goto v_26804;
v_26805:
    goto v_26817;
v_26813:
    v_26876 = stack[-2];
    goto v_26814;
v_26815:
    v_26875 = stack[-2];
    goto v_26816;
v_26817:
    goto v_26813;
v_26814:
    goto v_26815;
v_26816:
    v_26875 = list2(v_26876, v_26875);
    env = stack[-4];
    v_26875 = ncons(v_26875);
    env = stack[-4];
    goto v_26806;
v_26807:
    goto v_26801;
v_26802:
    goto v_26803;
v_26804:
    goto v_26805;
v_26806:
    v_26875 = Lputprop(nil, 3, stack[-1], stack[0], v_26875);
    env = stack[-4];
    goto v_26829;
v_26825:
    v_26875 = stack[-3];
    v_26876 = qcar(v_26875);
    goto v_26826;
v_26827:
    v_26875 = elt(env, 5); // unary
    goto v_26828;
v_26829:
    goto v_26825;
v_26826:
    goto v_26827;
v_26828:
    v_26875 = get(v_26876, v_26875);
    env = stack[-4];
    stack[0] = v_26875;
    if (v_26875 == nil) goto v_26823;
    goto v_26840;
v_26834:
    v_26877 = stack[0];
    goto v_26835;
v_26836:
    v_26876 = elt(env, 3); // infix
    goto v_26837;
v_26838:
    v_26875 = stack[-2];
    goto v_26839;
v_26840:
    goto v_26834;
v_26835:
    goto v_26836;
v_26837:
    goto v_26838;
v_26839:
    v_26875 = Lputprop(nil, 3, v_26877, v_26876, v_26875);
    env = stack[-4];
    goto v_26821;
v_26823:
v_26821:
    v_26875 = stack[0];
    if (v_26875 == nil) goto v_26847;
    v_26875 = stack[0];
    if (!symbolp(v_26875)) v_26875 = nil;
    else { v_26875 = qfastgets(v_26875);
           if (v_26875 != nil) { v_26875 = elt(v_26875, 35); // nary
#ifdef RECORD_GET
             if (v_26875 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v_26875 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v_26875 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v_26875 == SPID_NOPROP) v_26875 = nil; else v_26875 = lisp_true; }}
#endif
    if (v_26875 == nil) goto v_26850;
    else goto v_26847;
v_26850:
    goto v_26860;
v_26854:
    stack[-1] = stack[0];
    goto v_26855;
v_26856:
    stack[0] = elt(env, 4); // op
    goto v_26857;
v_26858:
    goto v_26868;
v_26864:
    v_26876 = nil;
    goto v_26865;
v_26866:
    v_26875 = stack[-2];
    goto v_26867;
v_26868:
    goto v_26864;
v_26865:
    goto v_26866;
v_26867:
    v_26875 = list2(v_26876, v_26875);
    env = stack[-4];
    goto v_26859;
v_26860:
    goto v_26854;
v_26855:
    goto v_26856;
v_26857:
    goto v_26858;
v_26859:
    v_26875 = Lputprop(nil, 3, stack[-1], stack[0], v_26875);
    env = stack[-4];
    goto v_26845;
v_26847:
v_26845:
    v_26875 = stack[-3];
    v_26875 = qcdr(v_26875);
    stack[-3] = v_26875;
    v_26875 = stack[-2];
    v_26875 = add1(v_26875);
    env = stack[-4];
    stack[-2] = v_26875;
    goto v_26772;
v_26771:
    return onevalue(v_26875);
}



// Code for setmatelem

static LispObject CC_setmatelem(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26952, v_26953, v_26954;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_26767;
    stack[-3] = v_26766;
// end of prologue
    goto v_26781;
v_26777:
    v_26952 = stack[-3];
    v_26953 = Llength(nil, v_26952);
    env = stack[-5];
    goto v_26778;
v_26779:
    v_26952 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_26780;
v_26781:
    goto v_26777;
v_26778:
    goto v_26779;
v_26780:
    if (v_26953 == v_26952) goto v_26776;
    goto v_26790;
v_26786:
    v_26953 = stack[-3];
    goto v_26787;
v_26788:
    v_26952 = elt(env, 1); // "matrix element"
    goto v_26789;
v_26790:
    goto v_26786;
v_26787:
    goto v_26788;
v_26789:
    fn = elt(env, 8); // typerr
    v_26952 = (*qfn2(fn))(fn, v_26953, v_26952);
    env = stack[-5];
    goto v_26774;
v_26776:
v_26774:
    v_26952 = stack[-3];
    v_26952 = qcar(v_26952);
    if (!symbolp(v_26952)) v_26952 = nil;
    else { v_26952 = qfastgets(v_26952);
           if (v_26952 != nil) { v_26952 = elt(v_26952, 4); // avalue
#ifdef RECORD_GET
             if (v_26952 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_26952 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_26952 == SPID_NOPROP) v_26952 = nil; }}
#endif
    stack[-4] = v_26952;
    v_26952 = stack[-4];
    if (v_26952 == nil) goto v_26802;
    else goto v_26803;
v_26802:
    v_26952 = lisp_true;
    goto v_26801;
v_26803:
    goto v_26812;
v_26808:
    v_26952 = stack[-4];
    v_26953 = qcar(v_26952);
    goto v_26809;
v_26810:
    v_26952 = elt(env, 2); // matrix
    goto v_26811;
v_26812:
    goto v_26808;
v_26809:
    goto v_26810;
v_26811:
    v_26952 = (v_26953 == v_26952 ? lisp_true : nil);
    v_26952 = (v_26952 == nil ? lisp_true : nil);
    goto v_26801;
    v_26952 = nil;
v_26801:
    if (v_26952 == nil) goto v_26799;
    goto v_26823;
v_26819:
    v_26952 = stack[-3];
    v_26953 = qcar(v_26952);
    goto v_26820;
v_26821:
    v_26952 = elt(env, 3); // "matrix"
    goto v_26822;
v_26823:
    goto v_26819;
v_26820:
    goto v_26821;
v_26822:
    fn = elt(env, 8); // typerr
    v_26952 = (*qfn2(fn))(fn, v_26953, v_26952);
    env = stack[-5];
    goto v_26797;
v_26799:
    goto v_26834;
v_26830:
    v_26952 = stack[-4];
    v_26952 = qcdr(v_26952);
    v_26953 = qcar(v_26952);
    stack[-4] = v_26953;
    goto v_26831;
v_26832:
    v_26952 = elt(env, 4); // mat
    goto v_26833;
v_26834:
    goto v_26830;
v_26831:
    goto v_26832;
v_26833:
    if (!consp(v_26953)) goto v_26827;
    v_26953 = qcar(v_26953);
    if (v_26953 == v_26952) goto v_26828;
v_26827:
    goto v_26846;
v_26840:
    stack[-1] = elt(env, 2); // matrix
    goto v_26841;
v_26842:
    stack[0] = (LispObject)160+TAG_FIXNUM; // 10
    goto v_26843;
v_26844:
    goto v_26856;
v_26850:
    v_26954 = elt(env, 5); // "Matrix"
    goto v_26851;
v_26852:
    v_26952 = stack[-3];
    v_26953 = qcar(v_26952);
    goto v_26853;
v_26854:
    v_26952 = elt(env, 6); // "not set"
    goto v_26855;
v_26856:
    goto v_26850;
v_26851:
    goto v_26852;
v_26853:
    goto v_26854;
v_26855:
    v_26952 = list3(v_26954, v_26953, v_26952);
    env = stack[-5];
    goto v_26845;
v_26846:
    goto v_26840;
v_26841:
    goto v_26842;
v_26843:
    goto v_26844;
v_26845:
    fn = elt(env, 9); // rerror
    v_26952 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_26952);
    env = stack[-5];
    goto v_26797;
v_26828:
v_26797:
    v_26952 = stack[-3];
    v_26952 = qcdr(v_26952);
    v_26952 = qcar(v_26952);
    fn = elt(env, 10); // reval_without_mod
    v_26952 = (*qfn1(fn))(fn, v_26952);
    env = stack[-5];
    stack[0] = v_26952;
    v_26952 = stack[0];
    v_26952 = integerp(v_26952);
    if (v_26952 == nil) goto v_26871;
    else goto v_26872;
v_26871:
    v_26952 = lisp_true;
    goto v_26870;
v_26872:
    goto v_26883;
v_26879:
    v_26953 = stack[0];
    goto v_26880;
v_26881:
    v_26952 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_26882;
v_26883:
    goto v_26879;
v_26880:
    goto v_26881;
v_26882:
    v_26952 = (LispObject)lesseq2(v_26953, v_26952);
    v_26952 = v_26952 ? lisp_true : nil;
    env = stack[-5];
    goto v_26870;
    v_26952 = nil;
v_26870:
    if (v_26952 == nil) goto v_26868;
    goto v_26891;
v_26887:
    v_26953 = stack[0];
    goto v_26888;
v_26889:
    v_26952 = elt(env, 7); // "positive integer"
    goto v_26890;
v_26891:
    goto v_26887;
v_26888:
    goto v_26889;
v_26890:
    fn = elt(env, 8); // typerr
    v_26952 = (*qfn2(fn))(fn, v_26953, v_26952);
    env = stack[-5];
    goto v_26866;
v_26868:
v_26866:
    goto v_26899;
v_26895:
    v_26952 = stack[-4];
    v_26953 = qcdr(v_26952);
    goto v_26896;
v_26897:
    v_26952 = stack[0];
    goto v_26898;
v_26899:
    goto v_26895;
v_26896:
    goto v_26897;
v_26898:
    fn = elt(env, 11); // nth
    v_26952 = (*qfn2(fn))(fn, v_26953, v_26952);
    env = stack[-5];
    stack[-4] = v_26952;
    v_26952 = stack[-3];
    v_26952 = qcdr(v_26952);
    v_26952 = qcdr(v_26952);
    v_26952 = qcar(v_26952);
    fn = elt(env, 10); // reval_without_mod
    v_26952 = (*qfn1(fn))(fn, v_26952);
    env = stack[-5];
    stack[0] = v_26952;
    v_26952 = stack[0];
    v_26952 = integerp(v_26952);
    if (v_26952 == nil) goto v_26914;
    else goto v_26915;
v_26914:
    v_26952 = lisp_true;
    goto v_26913;
v_26915:
    goto v_26926;
v_26922:
    v_26953 = stack[0];
    goto v_26923;
v_26924:
    v_26952 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_26925;
v_26926:
    goto v_26922;
v_26923:
    goto v_26924;
v_26925:
    v_26952 = (LispObject)lesseq2(v_26953, v_26952);
    v_26952 = v_26952 ? lisp_true : nil;
    env = stack[-5];
    goto v_26913;
    v_26952 = nil;
v_26913:
    if (v_26952 == nil) goto v_26911;
    goto v_26934;
v_26930:
    v_26953 = stack[0];
    goto v_26931;
v_26932:
    v_26952 = elt(env, 7); // "positive integer"
    goto v_26933;
v_26934:
    goto v_26930;
v_26931:
    goto v_26932;
v_26933:
    fn = elt(env, 8); // typerr
    v_26952 = (*qfn2(fn))(fn, v_26953, v_26952);
    env = stack[-5];
    goto v_26909;
v_26911:
v_26909:
    goto v_26942;
v_26938:
    goto v_26948;
v_26944:
    v_26953 = stack[-4];
    goto v_26945;
v_26946:
    v_26952 = stack[0];
    goto v_26947;
v_26948:
    goto v_26944;
v_26945:
    goto v_26946;
v_26947:
    fn = elt(env, 12); // pnth
    v_26953 = (*qfn2(fn))(fn, v_26953, v_26952);
    goto v_26939;
v_26940:
    v_26952 = stack[-2];
    goto v_26941;
v_26942:
    goto v_26938;
v_26939:
    goto v_26940;
v_26941:
        return Lrplaca(nil, v_26953, v_26952);
    return onevalue(v_26952);
}



// Code for mv2sf

static LispObject CC_mv2sf(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26823, v_26824, v_26825;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_26767;
    stack[-1] = v_26766;
// end of prologue
    stack[-2] = nil;
v_26773:
    v_26823 = stack[-1];
    if (v_26823 == nil) goto v_26778;
    else goto v_26779;
v_26778:
    goto v_26774;
v_26779:
    goto v_26786;
v_26782:
    goto v_26794;
v_26788:
    v_26823 = stack[-1];
    v_26823 = qcar(v_26823);
    v_26825 = qcar(v_26823);
    goto v_26789;
v_26790:
    v_26823 = stack[-1];
    v_26823 = qcar(v_26823);
    v_26824 = qcdr(v_26823);
    goto v_26791;
v_26792:
    v_26823 = stack[0];
    goto v_26793;
v_26794:
    goto v_26788;
v_26789:
    goto v_26790;
v_26791:
    goto v_26792;
v_26793:
    fn = elt(env, 1); // mv2sf1
    v_26824 = (*qfnn(fn))(fn, 3, v_26825, v_26824, v_26823);
    env = stack[-3];
    goto v_26783;
v_26784:
    v_26823 = stack[-2];
    goto v_26785;
v_26786:
    goto v_26782;
v_26783:
    goto v_26784;
v_26785:
    v_26823 = cons(v_26824, v_26823);
    env = stack[-3];
    stack[-2] = v_26823;
    v_26823 = stack[-1];
    v_26823 = qcdr(v_26823);
    stack[-1] = v_26823;
    goto v_26773;
v_26774:
    v_26823 = nil;
    v_26824 = v_26823;
v_26775:
    v_26823 = stack[-2];
    if (v_26823 == nil) goto v_26808;
    else goto v_26809;
v_26808:
    v_26823 = v_26824;
    goto v_26772;
v_26809:
    goto v_26817;
v_26813:
    v_26823 = stack[-2];
    v_26823 = qcar(v_26823);
    goto v_26814;
v_26815:
    goto v_26816;
v_26817:
    goto v_26813;
v_26814:
    goto v_26815;
v_26816:
    fn = elt(env, 2); // addf
    v_26823 = (*qfn2(fn))(fn, v_26823, v_26824);
    env = stack[-3];
    v_26824 = v_26823;
    v_26823 = stack[-2];
    v_26823 = qcdr(v_26823);
    stack[-2] = v_26823;
    goto v_26775;
v_26772:
    return onevalue(v_26823);
}



// Code for nodum_varp

static LispObject CC_nodum_varp(LispObject env,
                         LispObject v_26766)
{
    env = qenv(env);
    LispObject v_26821, v_26822;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_26766);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_26766;
// end of prologue
    v_26821 = stack[0];
    fn = elt(env, 4); // listp
    v_26821 = (*qfn1(fn))(fn, v_26821);
    env = stack[-1];
    if (v_26821 == nil) goto v_26771;
    v_26821 = lisp_true;
    goto v_26769;
v_26771:
    v_26821 = stack[0];
    if (!symbolp(v_26821)) v_26821 = nil;
    else { v_26821 = qfastgets(v_26821);
           if (v_26821 != nil) { v_26821 = elt(v_26821, 32); // dummy
#ifdef RECORD_GET
             if (v_26821 == SPID_NOPROP)
                record_get(elt(fastget_names, 32), 0),
                v_26821 = nil;
             else record_get(elt(fastget_names, 32), 1),
                v_26821 = lisp_true; }
           else record_get(elt(fastget_names, 32), 0); }
#else
             if (v_26821 == SPID_NOPROP) v_26821 = nil; else v_26821 = lisp_true; }}
#endif
    if (v_26821 == nil) goto v_26780;
    v_26821 = lisp_true;
    goto v_26778;
v_26780:
    goto v_26794;
v_26790:
    v_26821 = stack[0];
    fn = elt(env, 5); // ad_splitname
    v_26821 = (*qfn1(fn))(fn, v_26821);
    env = stack[-1];
    v_26822 = qcar(v_26821);
    goto v_26791;
v_26792:
    v_26821 = qvalue(elt(env, 1)); // g_dvbase
    goto v_26793;
v_26794:
    goto v_26790;
v_26791:
    goto v_26792;
v_26793:
    if (equal(v_26822, v_26821)) goto v_26788;
    else goto v_26789;
v_26788:
    v_26821 = lisp_true;
    goto v_26787;
v_26789:
    goto v_26806;
v_26802:
    goto v_26803;
v_26804:
    goto v_26813;
v_26809:
    v_26822 = elt(env, 2); // !~dv
    goto v_26810;
v_26811:
    v_26821 = elt(env, 3); // !~dva
    goto v_26812;
v_26813:
    goto v_26809;
v_26810:
    goto v_26811;
v_26812:
    v_26821 = list2(v_26822, v_26821);
    goto v_26805;
v_26806:
    goto v_26802;
v_26803:
    goto v_26804;
v_26805:
    v_26821 = Lmember(nil, stack[0], v_26821);
    goto v_26787;
    v_26821 = nil;
v_26787:
    goto v_26778;
    v_26821 = nil;
v_26778:
    if (v_26821 == nil) goto v_26776;
    v_26821 = nil;
    goto v_26769;
v_26776:
    v_26821 = lisp_true;
    goto v_26769;
    v_26821 = nil;
v_26769:
    return onevalue(v_26821);
}



// Code for polynomlistautoreduce

static LispObject CC_polynomlistautoreduce(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26977, v_26978, v_26979;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_26767;
    stack[-4] = v_26766;
// end of prologue
    v_26977 = nil;
    v_26977 = ncons(v_26977);
    env = stack[-6];
    stack[-5] = v_26977;
v_26779:
    v_26977 = stack[-4];
    v_26977 = qcar(v_26977);
    if (v_26977 == nil) goto v_26782;
    else goto v_26783;
v_26782:
    goto v_26778;
v_26783:
    goto v_26794;
v_26788:
    v_26979 = stack[-5];
    goto v_26789;
v_26790:
    v_26977 = stack[-4];
    v_26978 = qcar(v_26977);
    goto v_26791;
v_26792:
    v_26977 = stack[-3];
    goto v_26793;
v_26794:
    goto v_26788;
v_26789:
    goto v_26790;
v_26791:
    goto v_26792;
v_26793:
    fn = elt(env, 1); // polynomlistreduce
    v_26977 = (*qfnn(fn))(fn, 3, v_26979, v_26978, v_26977);
    env = stack[-6];
    stack[-2] = v_26977;
    goto v_26804;
v_26800:
    goto v_26810;
v_26806:
    v_26978 = stack[-4];
    goto v_26807;
v_26808:
    v_26977 = stack[-4];
    v_26977 = qcdr(v_26977);
    v_26977 = qcar(v_26977);
    goto v_26809;
v_26810:
    goto v_26806;
v_26807:
    goto v_26808;
v_26809:
    v_26978 = Lrplaca(nil, v_26978, v_26977);
    env = stack[-6];
    goto v_26801;
v_26802:
    v_26977 = stack[-4];
    v_26977 = qcdr(v_26977);
    v_26977 = qcdr(v_26977);
    goto v_26803;
v_26804:
    goto v_26800;
v_26801:
    goto v_26802;
v_26803:
    v_26977 = Lrplacd(nil, v_26978, v_26977);
    env = stack[-6];
    v_26977 = stack[-2];
    v_26977 = qcar(v_26977);
    if (v_26977 == nil) goto v_26821;
    v_26977 = stack[-2];
    v_26977 = qcar(v_26977);
    stack[-1] = v_26977;
    v_26977 = stack[-5];
    stack[0] = v_26977;
v_26829:
    v_26977 = stack[0];
    v_26977 = qcar(v_26977);
    if (v_26977 == nil) goto v_26832;
    else goto v_26833;
v_26832:
    goto v_26828;
v_26833:
    goto v_26846;
v_26842:
    v_26977 = stack[0];
    v_26977 = qcar(v_26977);
    v_26978 = qcar(v_26977);
    goto v_26843;
v_26844:
    v_26977 = stack[-1];
    goto v_26845;
v_26846:
    goto v_26842;
v_26843:
    goto v_26844;
v_26845:
    fn = elt(env, 2); // monomisdivisibleby
    v_26977 = (*qfn2(fn))(fn, v_26978, v_26977);
    env = stack[-6];
    if (v_26977 == nil) goto v_26840;
    goto v_26856;
v_26852:
    v_26978 = stack[-4];
    goto v_26853;
v_26854:
    v_26977 = stack[0];
    v_26977 = qcar(v_26977);
    goto v_26855;
v_26856:
    goto v_26852;
v_26853:
    goto v_26854;
v_26855:
    fn = elt(env, 3); // pushback
    v_26977 = (*qfn2(fn))(fn, v_26978, v_26977);
    env = stack[-6];
    goto v_26865;
v_26861:
    goto v_26871;
v_26867:
    v_26978 = stack[0];
    goto v_26868;
v_26869:
    v_26977 = stack[0];
    v_26977 = qcdr(v_26977);
    v_26977 = qcar(v_26977);
    goto v_26870;
v_26871:
    goto v_26867;
v_26868:
    goto v_26869;
v_26870:
    v_26978 = Lrplaca(nil, v_26978, v_26977);
    env = stack[-6];
    goto v_26862;
v_26863:
    v_26977 = stack[0];
    v_26977 = qcdr(v_26977);
    v_26977 = qcdr(v_26977);
    goto v_26864;
v_26865:
    goto v_26861;
v_26862:
    goto v_26863;
v_26864:
    v_26977 = Lrplacd(nil, v_26978, v_26977);
    env = stack[-6];
    goto v_26838;
v_26840:
    v_26977 = stack[0];
    v_26977 = qcdr(v_26977);
    stack[0] = v_26977;
    goto v_26838;
v_26838:
    goto v_26829;
v_26828:
    goto v_26891;
v_26887:
    v_26978 = stack[-5];
    goto v_26888;
v_26889:
    v_26977 = stack[-2];
    goto v_26890;
v_26891:
    goto v_26887;
v_26888:
    goto v_26889;
v_26890:
    fn = elt(env, 3); // pushback
    v_26977 = (*qfn2(fn))(fn, v_26978, v_26977);
    env = stack[-6];
    goto v_26819;
v_26821:
v_26819:
    goto v_26779;
v_26778:
    v_26977 = stack[-5];
    stack[0] = v_26977;
v_26899:
    v_26977 = stack[0];
    v_26977 = qcar(v_26977);
    if (v_26977 == nil) goto v_26902;
    else goto v_26903;
v_26902:
    goto v_26898;
v_26903:
    v_26977 = stack[0];
    v_26977 = qcar(v_26977);
    stack[-2] = v_26977;
    goto v_26914;
v_26910:
    goto v_26920;
v_26916:
    v_26978 = stack[0];
    goto v_26917;
v_26918:
    v_26977 = stack[0];
    v_26977 = qcdr(v_26977);
    v_26977 = qcar(v_26977);
    goto v_26919;
v_26920:
    goto v_26916;
v_26917:
    goto v_26918;
v_26919:
    v_26978 = Lrplaca(nil, v_26978, v_26977);
    env = stack[-6];
    goto v_26911;
v_26912:
    v_26977 = stack[0];
    v_26977 = qcdr(v_26977);
    v_26977 = qcdr(v_26977);
    goto v_26913;
v_26914:
    goto v_26910;
v_26911:
    goto v_26912;
v_26913:
    v_26977 = Lrplacd(nil, v_26978, v_26977);
    env = stack[-6];
    goto v_26935;
v_26929:
    v_26979 = stack[-5];
    goto v_26930;
v_26931:
    v_26978 = stack[-2];
    goto v_26932;
v_26933:
    v_26977 = stack[-3];
    goto v_26934;
v_26935:
    goto v_26929;
v_26930:
    goto v_26931;
v_26932:
    goto v_26933;
v_26934:
    fn = elt(env, 1); // polynomlistreduce
    v_26977 = (*qfnn(fn))(fn, 3, v_26979, v_26978, v_26977);
    env = stack[-6];
    stack[-2] = v_26977;
    v_26977 = stack[-2];
    if (v_26977 == nil) goto v_26942;
    v_26977 = stack[-2];
    v_26977 = qcar(v_26977);
    if (v_26977 == nil) goto v_26942;
    goto v_26953;
v_26949:
    goto v_26959;
v_26955:
    stack[-1] = stack[0];
    goto v_26956;
v_26957:
    goto v_26966;
v_26962:
    v_26977 = stack[0];
    v_26978 = qcar(v_26977);
    goto v_26963;
v_26964:
    v_26977 = stack[0];
    v_26977 = qcdr(v_26977);
    goto v_26965;
v_26966:
    goto v_26962;
v_26963:
    goto v_26964;
v_26965:
    v_26977 = cons(v_26978, v_26977);
    env = stack[-6];
    goto v_26958;
v_26959:
    goto v_26955;
v_26956:
    goto v_26957;
v_26958:
    v_26978 = Lrplacd(nil, stack[-1], v_26977);
    env = stack[-6];
    goto v_26950;
v_26951:
    v_26977 = stack[-2];
    goto v_26952;
v_26953:
    goto v_26949;
v_26950:
    goto v_26951;
v_26952:
    v_26977 = Lrplaca(nil, v_26978, v_26977);
    env = stack[-6];
    v_26977 = stack[0];
    v_26977 = qcdr(v_26977);
    stack[0] = v_26977;
    goto v_26940;
v_26942:
v_26940:
    goto v_26899;
v_26898:
    v_26977 = stack[-5];
    return onevalue(v_26977);
}



// Code for talp_simplatlinv

static LispObject CC_talp_simplatlinv(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_26803, v_26804, v_26805;
    LispObject fn;
    LispObject v_26768, v_26767, v_26766;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_simplatlinv");
    va_start(aa, nargs);
    v_26766 = va_arg(aa, LispObject);
    v_26767 = va_arg(aa, LispObject);
    v_26768 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_26768,v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_26766,v_26767,v_26768);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_26768;
    stack[-1] = v_26767;
    stack[-2] = v_26766;
// end of prologue
    v_26803 = stack[-1];
    fn = elt(env, 1); // talp_simplt
    v_26803 = (*qfn1(fn))(fn, v_26803);
    env = stack[-3];
    stack[-1] = v_26803;
    v_26803 = stack[-1];
    fn = elt(env, 2); // talp_invp
    v_26803 = (*qfn1(fn))(fn, v_26803);
    env = stack[-3];
    if (v_26803 == nil) goto v_26775;
    goto v_26785;
v_26779:
    v_26805 = stack[-2];
    goto v_26780;
v_26781:
    v_26804 = stack[-1];
    goto v_26782;
v_26783:
    v_26803 = stack[0];
    goto v_26784;
v_26785:
    goto v_26779;
v_26780:
    goto v_26781;
v_26782:
    goto v_26783;
v_26784:
    {
        fn = elt(env, 3); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_26805, v_26804, v_26803);
    }
v_26775:
    goto v_26798;
v_26792:
    goto v_26793;
v_26794:
    goto v_26795;
v_26796:
    v_26803 = stack[0];
    fn = elt(env, 1); // talp_simplt
    v_26803 = (*qfn1(fn))(fn, v_26803);
    env = stack[-3];
    goto v_26797;
v_26798:
    goto v_26792;
v_26793:
    goto v_26794;
v_26795:
    goto v_26796;
v_26797:
    {
        LispObject v_26809 = stack[-2];
        LispObject v_26810 = stack[-1];
        fn = elt(env, 4); // talp_simplat2
        return (*qfnn(fn))(fn, 3, v_26809, v_26810, v_26803);
    }
    v_26803 = nil;
    return onevalue(v_26803);
}



// Code for cl_sacat

static LispObject CC_cl_sacat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_26785, v_26786, v_26787;
    LispObject v_26768, v_26767, v_26766;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cl_sacat");
    va_start(aa, nargs);
    v_26766 = va_arg(aa, LispObject);
    v_26767 = va_arg(aa, LispObject);
    v_26768 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_26785 = v_26768;
    v_26786 = v_26767;
    v_26787 = v_26766;
// end of prologue
    goto v_26778;
v_26774:
    v_26785 = v_26787;
    goto v_26775;
v_26776:
    goto v_26777;
v_26778:
    goto v_26774;
v_26775:
    goto v_26776;
v_26777:
    if (equal(v_26785, v_26786)) goto v_26772;
    else goto v_26773;
v_26772:
    v_26785 = elt(env, 1); // keep
    goto v_26771;
v_26773:
    v_26785 = nil;
    goto v_26771;
    v_26785 = nil;
v_26771:
    return onevalue(v_26785);
}



// Code for operator_fn

static LispObject CC_operator_fn(LispObject env,
                         LispObject v_26766)
{
    env = qenv(env);
    LispObject v_26796;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_26766);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_26766;
// end of prologue
    v_26796 = elt(env, 1); // "<apply>"
    fn = elt(env, 7); // printout
    v_26796 = (*qfn1(fn))(fn, v_26796);
    env = stack[-1];
    v_26796 = lisp_true;
    fn = elt(env, 8); // indent!*
    v_26796 = (*qfn1(fn))(fn, v_26796);
    env = stack[-1];
    v_26796 = elt(env, 2); // "<csymbol>"
    fn = elt(env, 7); // printout
    v_26796 = (*qfn1(fn))(fn, v_26796);
    env = stack[-1];
    v_26796 = lisp_true;
    fn = elt(env, 8); // indent!*
    v_26796 = (*qfn1(fn))(fn, v_26796);
    env = stack[-1];
    v_26796 = elt(env, 3); // "<ci>"
    fn = elt(env, 7); // printout
    v_26796 = (*qfn1(fn))(fn, v_26796);
    env = stack[-1];
    v_26796 = stack[0];
    v_26796 = qcar(v_26796);
    v_26796 = Lprinc(nil, v_26796);
    env = stack[-1];
    v_26796 = elt(env, 4); // "</ci>"
    v_26796 = Lprinc(nil, v_26796);
    env = stack[-1];
    v_26796 = nil;
    fn = elt(env, 8); // indent!*
    v_26796 = (*qfn1(fn))(fn, v_26796);
    env = stack[-1];
    v_26796 = elt(env, 5); // "</csymbol>"
    fn = elt(env, 7); // printout
    v_26796 = (*qfn1(fn))(fn, v_26796);
    env = stack[-1];
    v_26796 = stack[0];
    v_26796 = qcdr(v_26796);
    fn = elt(env, 9); // multi_args
    v_26796 = (*qfn1(fn))(fn, v_26796);
    env = stack[-1];
    v_26796 = nil;
    fn = elt(env, 8); // indent!*
    v_26796 = (*qfn1(fn))(fn, v_26796);
    env = stack[-1];
    v_26796 = elt(env, 6); // "</apply>"
    fn = elt(env, 7); // printout
    v_26796 = (*qfn1(fn))(fn, v_26796);
    v_26796 = nil;
    return onevalue(v_26796);
}



// Code for mulpower

static LispObject CC_mulpower(LispObject env,
                         LispObject v_26766, LispObject v_26767)
{
    env = qenv(env);
    LispObject v_26820, v_26821, v_26822;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_26767,v_26766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_26766,v_26767);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_26820 = v_26767;
    v_26821 = v_26766;
// end of prologue
    stack[0] = nil;
    goto v_26778;
v_26774:
    goto v_26775;
v_26776:
    goto v_26777;
v_26778:
    goto v_26774;
v_26775:
    goto v_26776;
v_26777:
    fn = elt(env, 3); // addexptsdf
    v_26820 = (*qfn2(fn))(fn, v_26821, v_26820);
    env = stack[-2];
    stack[-1] = v_26820;
    v_26820 = qvalue(elt(env, 1)); // sqrtlist
    if (v_26820 == nil) goto v_26784;
    goto v_26791;
v_26787:
    v_26821 = stack[-1];
    goto v_26788;
v_26789:
    v_26820 = qvalue(elt(env, 2)); // zlist
    goto v_26790;
v_26791:
    goto v_26787;
v_26788:
    goto v_26789;
v_26790:
    fn = elt(env, 4); // reduceroots
    v_26820 = (*qfn2(fn))(fn, v_26821, v_26820);
    env = stack[-2];
    stack[0] = v_26820;
    goto v_26782;
v_26784:
v_26782:
    goto v_26802;
v_26796:
    v_26822 = stack[-1];
    goto v_26797;
v_26798:
    v_26821 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26799;
v_26800:
    v_26820 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26801;
v_26802:
    goto v_26796;
v_26797:
    goto v_26798;
v_26799:
    goto v_26800;
v_26801:
    v_26820 = list2star(v_26822, v_26821, v_26820);
    env = stack[-2];
    v_26820 = ncons(v_26820);
    env = stack[-2];
    stack[-1] = v_26820;
    v_26820 = stack[0];
    if (v_26820 == nil) goto v_26809;
    goto v_26816;
v_26812:
    v_26821 = stack[-1];
    goto v_26813;
v_26814:
    v_26820 = stack[0];
    goto v_26815;
v_26816:
    goto v_26812;
v_26813:
    goto v_26814;
v_26815:
    fn = elt(env, 5); // multdf
    v_26820 = (*qfn2(fn))(fn, v_26821, v_26820);
    stack[-1] = v_26820;
    goto v_26807;
v_26809:
v_26807:
    v_26820 = stack[-1];
    return onevalue(v_26820);
}



// Code for newsym1

static LispObject CC_newsym1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_26783, v_26784;
    argcheck(nargs, 0, "newsym1");
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
    v_26783 = qvalue(elt(env, 1)); // cindex!*
    v_26783 = Lexplode(nil, v_26783);
    env = stack[-1];
    stack[0] = v_26783;
    v_26783 = qvalue(elt(env, 1)); // cindex!*
    v_26783 = add1(v_26783);
    env = stack[-1];
    qvalue(elt(env, 1)) = v_26783; // cindex!*
    goto v_26780;
v_26776:
    v_26784 = qvalue(elt(env, 2)); // cname!*
    goto v_26777;
v_26778:
    v_26783 = stack[0];
    goto v_26779;
v_26780:
    goto v_26776;
v_26777:
    goto v_26778;
v_26779:
    v_26783 = Lappend(nil, v_26784, v_26783);
        return Lcompress(nil, v_26783);
    return onevalue(v_26783);
}



// Code for xregister_spoly_pair

static LispObject CC_xregister_spoly_pair(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_26768;
    argcheck(nargs, 0, "xregister_spoly_pair");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_26768 = nil;
    return onevalue(v_26768);
}



setup_type const u45_setup[] =
{
    {"factor-prim-sqfree-f",    CC_factorKprimKsqfreeKf,TOO_MANY_1,WRONG_NO_1},
    {"findhc",                  CC_findhc,      TOO_MANY_1,    WRONG_NO_1},
    {"dipdivmon",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dipdivmon},
    {"gfftimes",                TOO_FEW_2,      CC_gfftimes,   WRONG_NO_2},
    {"new_prove",               TOO_FEW_2,      CC_new_prove,  WRONG_NO_2},
    {"mkrepart",                CC_mkrepart,    TOO_MANY_1,    WRONG_NO_1},
    {"prsum",                   TOO_FEW_2,      CC_prsum,      WRONG_NO_2},
    {"rfirst",                  CC_rfirst,      TOO_MANY_1,    WRONG_NO_1},
    {"subs2p",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_subs2p},
    {"settreset",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_settreset},
    {"pdiffvars",               TOO_FEW_2,      CC_pdiffvars,  WRONG_NO_2},
    {"ps:evaluate-next",        TOO_FEW_2,      CC_psTevaluateKnext,WRONG_NO_2},
    {"scar",                    TOO_FEW_2,      CC_scar,       WRONG_NO_2},
    {"partitwedge",             CC_partitwedge, TOO_MANY_1,    WRONG_NO_1},
    {"subfindices",             TOO_FEW_2,      CC_subfindices,WRONG_NO_2},
    {"coeff_calc",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_coeff_calc},
    {"fs:timescoeff",           TOO_FEW_2,      CC_fsTtimescoeff,WRONG_NO_2},
    {"mkindxlist",              CC_mkindxlist,  TOO_MANY_1,    WRONG_NO_1},
    {"mkrootsql",               TOO_FEW_2,      CC_mkrootsql,  WRONG_NO_2},
    {"evaluate-in-order-mod-p", TOO_FEW_2,      CC_evaluateKinKorderKmodKp,WRONG_NO_2},
    {"coeffs",                  CC_coeffs,      TOO_MANY_1,    WRONG_NO_1},
    {"valuechk",                TOO_FEW_2,      CC_valuechk,   WRONG_NO_2},
    {"iv_new",                  TOO_FEW_2,      CC_iv_new,     WRONG_NO_2},
    {"ofsf_optfindeqsol",       TOO_FEW_2,      CC_ofsf_optfindeqsol,WRONG_NO_2},
    {"csymbolrd",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_csymbolrd},
    {"sc_scalarproduct",        TOO_FEW_2,      CC_sc_scalarproduct,WRONG_NO_2},
    {"fortassign",              CC_fortassign,  TOO_MANY_1,    WRONG_NO_1},
    {"ordpl",                   TOO_FEW_2,      CC_ordpl,      WRONG_NO_2},
    {"strand-alg-top",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_strandKalgKtop},
    {"inormmat",                CC_inormmat,    TOO_MANY_1,    WRONG_NO_1},
    {"zfactor1",                TOO_FEW_2,      CC_zfactor1,   WRONG_NO_2},
    {"noncomfree",              CC_noncomfree,  TOO_MANY_1,    WRONG_NO_1},
    {"tayexp-max2",             TOO_FEW_2,      CC_tayexpKmax2,WRONG_NO_2},
    {"cl_replace-varl",         CC_cl_replaceKvarl,TOO_MANY_1, WRONG_NO_1},
    {"qqe_simplqneq",           TOO_FEW_2,      CC_qqe_simplqneq,WRONG_NO_2},
    {"cnml",                    CC_cnml,        TOO_MANY_1,    WRONG_NO_1},
    {"d2int",                   CC_d2int,       TOO_MANY_1,    WRONG_NO_1},
    {"tchscheme2",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_tchscheme2},
    {"sroot1",                  TOO_FEW_2,      CC_sroot1,     WRONG_NO_2},
    {"endmodule",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_endmodule},
    {"mkprec",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mkprec},
    {"setmatelem",              TOO_FEW_2,      CC_setmatelem, WRONG_NO_2},
    {"mv2sf",                   TOO_FEW_2,      CC_mv2sf,      WRONG_NO_2},
    {"nodum_varp",              CC_nodum_varp,  TOO_MANY_1,    WRONG_NO_1},
    {"polynomlistautoreduce",   TOO_FEW_2,      CC_polynomlistautoreduce,WRONG_NO_2},
    {"talp_simplatlinv",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_simplatlinv},
    {"cl_sacat",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_sacat},
    {"operator_fn",             CC_operator_fn, TOO_MANY_1,    WRONG_NO_1},
    {"mulpower",                TOO_FEW_2,      CC_mulpower,   WRONG_NO_2},
    {"newsym1",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_newsym1},
    {"xregister_spoly_pair",    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xregister_spoly_pair},
    {NULL, (one_args *)"u45", (two_args *)"132600 7841892 1974302", 0}
};

// end of generated code
