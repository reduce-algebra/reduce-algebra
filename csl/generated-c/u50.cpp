
// $destdir/u50.c        Machine generated C code

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



// Code for xadd!*

static LispObject CC_xaddH(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30270, v_30271, v_30272;
    LispObject fn;
    LispObject v_30036, v_30035, v_30034;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xadd*");
    va_start(aa, nargs);
    v_30034 = va_arg(aa, LispObject);
    v_30035 = va_arg(aa, LispObject);
    v_30036 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30036,v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30034,v_30035,v_30036);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(14);
// copy arguments values to proper place
    stack[-9] = v_30036;
    stack[-10] = v_30035;
    stack[-11] = v_30034;
// end of prologue
    v_30270 = stack[-10];
    stack[-12] = v_30270;
v_30045:
    v_30270 = stack[-12];
    if (v_30270 == nil) goto v_30048;
    goto v_30061;
v_30057:
    v_30270 = stack[-11];
    v_30271 = qcar(v_30270);
    goto v_30058;
v_30059:
    v_30270 = stack[-12];
    v_30270 = qcar(v_30270);
    v_30270 = qcar(v_30270);
    goto v_30060;
v_30061:
    goto v_30057;
v_30058:
    goto v_30059;
v_30060:
    if (equal(v_30271, v_30270)) goto v_30055;
    else goto v_30056;
v_30055:
    goto v_30071;
v_30067:
    v_30270 = stack[-11];
    v_30270 = qcdr(v_30270);
    v_30271 = qcar(v_30270);
    goto v_30068;
v_30069:
    v_30270 = stack[-12];
    v_30270 = qcar(v_30270);
    v_30270 = qcdr(v_30270);
    v_30270 = qcar(v_30270);
    goto v_30070;
v_30071:
    goto v_30067;
v_30068:
    goto v_30069;
v_30070:
    v_30270 = (equal(v_30271, v_30270) ? lisp_true : nil);
    goto v_30054;
v_30056:
    v_30270 = nil;
    goto v_30054;
    v_30270 = nil;
v_30054:
    if (v_30270 == nil) goto v_30052;
    else goto v_30048;
v_30052:
    goto v_30049;
v_30048:
    goto v_30044;
v_30049:
    v_30270 = stack[-12];
    v_30270 = qcdr(v_30270);
    stack[-12] = v_30270;
    goto v_30045;
v_30044:
    v_30270 = stack[-12];
    if (v_30270 == nil) goto v_30089;
    goto v_30096;
v_30092:
    v_30270 = stack[-12];
    v_30271 = qcar(v_30270);
    goto v_30093;
v_30094:
    v_30270 = stack[-10];
    goto v_30095;
v_30096:
    goto v_30092;
v_30093:
    goto v_30094;
v_30095:
    v_30270 = Ldelete(nil, v_30271, v_30270);
    env = stack[-13];
    stack[-10] = v_30270;
    v_30270 = stack[-12];
    v_30270 = qcar(v_30270);
    stack[-12] = v_30270;
    v_30270 = stack[-9];
    if (v_30270 == nil) goto v_30105;
    v_30270 = qvalue(elt(env, 1)); // newrule!*
    if (v_30270 == nil) goto v_30105;
    goto v_30122;
v_30118:
    v_30270 = stack[-12];
    v_30271 = qcar(v_30270);
    goto v_30119;
v_30120:
    v_30270 = qvalue(elt(env, 1)); // newrule!*
    v_30270 = qcar(v_30270);
    stack[0] = v_30270;
    goto v_30121;
v_30122:
    goto v_30118;
v_30119:
    goto v_30120;
v_30121:
    if (equal(v_30271, v_30270)) goto v_30117;
    v_30270 = stack[-12];
    v_30270 = qcar(v_30270);
    fn = elt(env, 6); // powlisp
    v_30270 = (*qfn1(fn))(fn, v_30270);
    env = stack[-13];
    goto v_30115;
v_30117:
    v_30270 = nil;
    goto v_30115;
    v_30270 = nil;
v_30115:
    if (v_30270 == nil) goto v_30113;
    goto v_30138;
v_30134:
    goto v_30148;
v_30142:
    stack[-8] = elt(env, 2); // plus
    goto v_30143;
v_30144:
    stack[-7] = stack[0];
    goto v_30145;
v_30146:
    goto v_30158;
v_30152:
    stack[-6] = elt(env, 3); // difference
    goto v_30153;
v_30154:
    v_30270 = stack[-12];
    v_30270 = qcdr(v_30270);
    v_30270 = qcdr(v_30270);
    stack[-5] = qcar(v_30270);
    goto v_30155;
v_30156:
    goto v_30169;
v_30165:
    stack[-4] = elt(env, 4); // times
    goto v_30166;
v_30167:
    v_30270 = stack[-12];
    v_30270 = qcar(v_30270);
    stack[-3] = v_30270;
    v_30270 = stack[-3];
    if (v_30270 == nil) goto v_30181;
    else goto v_30182;
v_30181:
    v_30270 = nil;
    goto v_30175;
v_30182:
    v_30270 = stack[-3];
    v_30270 = qcar(v_30270);
    goto v_30196;
v_30190:
    v_30272 = elt(env, 5); // expt
    goto v_30191;
v_30192:
    v_30271 = v_30270;
    v_30271 = qcar(v_30271);
    goto v_30193;
v_30194:
    v_30270 = qcdr(v_30270);
    goto v_30195;
v_30196:
    goto v_30190;
v_30191:
    goto v_30192;
v_30193:
    goto v_30194;
v_30195:
    v_30270 = list3(v_30272, v_30271, v_30270);
    env = stack[-13];
    v_30270 = ncons(v_30270);
    env = stack[-13];
    stack[-1] = v_30270;
    stack[-2] = v_30270;
v_30176:
    v_30270 = stack[-3];
    v_30270 = qcdr(v_30270);
    stack[-3] = v_30270;
    v_30270 = stack[-3];
    if (v_30270 == nil) goto v_30206;
    else goto v_30207;
v_30206:
    v_30270 = stack[-2];
    goto v_30175;
v_30207:
    goto v_30215;
v_30211:
    stack[0] = stack[-1];
    goto v_30212;
v_30213:
    v_30270 = stack[-3];
    v_30270 = qcar(v_30270);
    goto v_30228;
v_30222:
    v_30272 = elt(env, 5); // expt
    goto v_30223;
v_30224:
    v_30271 = v_30270;
    v_30271 = qcar(v_30271);
    goto v_30225;
v_30226:
    v_30270 = qcdr(v_30270);
    goto v_30227;
v_30228:
    goto v_30222;
v_30223:
    goto v_30224;
v_30225:
    goto v_30226;
v_30227:
    v_30270 = list3(v_30272, v_30271, v_30270);
    env = stack[-13];
    v_30270 = ncons(v_30270);
    env = stack[-13];
    goto v_30214;
v_30215:
    goto v_30211;
v_30212:
    goto v_30213;
v_30214:
    v_30270 = Lrplacd(nil, stack[0], v_30270);
    env = stack[-13];
    v_30270 = stack[-1];
    v_30270 = qcdr(v_30270);
    stack[-1] = v_30270;
    goto v_30176;
v_30175:
    goto v_30168;
v_30169:
    goto v_30165;
v_30166:
    goto v_30167;
v_30168:
    v_30270 = cons(stack[-4], v_30270);
    env = stack[-13];
    goto v_30157;
v_30158:
    goto v_30152;
v_30153:
    goto v_30154;
v_30155:
    goto v_30156;
v_30157:
    v_30270 = list3(stack[-6], stack[-5], v_30270);
    env = stack[-13];
    goto v_30147;
v_30148:
    goto v_30142;
v_30143:
    goto v_30144;
v_30145:
    goto v_30146;
v_30147:
    v_30270 = list3(stack[-8], stack[-7], v_30270);
    env = stack[-13];
    fn = elt(env, 7); // simp
    v_30270 = (*qfn1(fn))(fn, v_30270);
    env = stack[-13];
    fn = elt(env, 8); // prepsq
    v_30271 = (*qfn1(fn))(fn, v_30270);
    env = stack[-13];
    goto v_30135;
v_30136:
    v_30270 = stack[-12];
    v_30270 = qcdr(v_30270);
    v_30270 = qcar(v_30270);
    v_30270 = qcdr(v_30270);
    goto v_30137;
v_30138:
    goto v_30134;
v_30135:
    goto v_30136;
v_30137:
    fn = elt(env, 9); // updoldrules
    v_30270 = (*qfn2(fn))(fn, v_30271, v_30270);
    env = stack[-13];
    goto v_30111;
v_30113:
    goto v_30247;
v_30243:
    v_30270 = stack[-12];
    v_30270 = qcdr(v_30270);
    v_30270 = qcdr(v_30270);
    v_30271 = qcar(v_30270);
    goto v_30244;
v_30245:
    v_30270 = stack[-12];
    v_30270 = qcdr(v_30270);
    v_30270 = qcar(v_30270);
    v_30270 = qcdr(v_30270);
    goto v_30246;
v_30247:
    goto v_30243;
v_30244:
    goto v_30245;
v_30246:
    fn = elt(env, 9); // updoldrules
    v_30270 = (*qfn2(fn))(fn, v_30271, v_30270);
    env = stack[-13];
    goto v_30111;
v_30111:
    goto v_30103;
v_30105:
v_30103:
    goto v_30087;
v_30089:
v_30087:
    v_30270 = stack[-9];
    if (v_30270 == nil) goto v_30259;
    goto v_30266;
v_30262:
    v_30271 = stack[-11];
    goto v_30263;
v_30264:
    v_30270 = stack[-10];
    goto v_30265;
v_30266:
    goto v_30262;
v_30263:
    goto v_30264;
v_30265:
    v_30270 = cons(v_30271, v_30270);
    stack[-10] = v_30270;
    goto v_30257;
v_30259:
v_30257:
    v_30270 = stack[-10];
    return onevalue(v_30270);
}



// Code for !*multsq

static LispObject CC_Hmultsq(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30240, v_30241;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30034,v_30035);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_30035;
    stack[-3] = v_30034;
// end of prologue
    v_30240 = stack[-3];
    v_30240 = qcar(v_30240);
    if (v_30240 == nil) goto v_30043;
    else goto v_30044;
v_30043:
    v_30240 = lisp_true;
    goto v_30042;
v_30044:
    v_30240 = stack[-2];
    v_30240 = qcar(v_30240);
    v_30240 = (v_30240 == nil ? lisp_true : nil);
    goto v_30042;
    v_30240 = nil;
v_30042:
    if (v_30240 == nil) goto v_30040;
    goto v_30058;
v_30054:
    v_30241 = nil;
    goto v_30055;
v_30056:
    v_30240 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30057;
v_30058:
    goto v_30054;
v_30055:
    goto v_30056;
v_30057:
    return cons(v_30241, v_30240);
v_30040:
    goto v_30071;
v_30067:
    v_30240 = stack[-3];
    v_30241 = qcdr(v_30240);
    goto v_30068;
v_30069:
    v_30240 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30070;
v_30071:
    goto v_30067;
v_30068:
    goto v_30069;
v_30070:
    if (v_30241 == v_30240) goto v_30065;
    else goto v_30066;
v_30065:
    goto v_30079;
v_30075:
    v_30240 = stack[-2];
    v_30241 = qcdr(v_30240);
    goto v_30076;
v_30077:
    v_30240 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30078;
v_30079:
    goto v_30075;
v_30076:
    goto v_30077;
v_30078:
    v_30240 = (v_30241 == v_30240 ? lisp_true : nil);
    goto v_30064;
v_30066:
    v_30240 = nil;
    goto v_30064;
    v_30240 = nil;
v_30064:
    if (v_30240 == nil) goto v_30062;
    goto v_30092;
v_30088:
    goto v_30098;
v_30094:
    v_30240 = stack[-3];
    v_30241 = qcar(v_30240);
    goto v_30095;
v_30096:
    v_30240 = stack[-2];
    v_30240 = qcar(v_30240);
    goto v_30097;
v_30098:
    goto v_30094;
v_30095:
    goto v_30096;
v_30097:
    fn = elt(env, 1); // !*multf
    v_30241 = (*qfn2(fn))(fn, v_30241, v_30240);
    goto v_30089;
v_30090:
    v_30240 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30091;
v_30092:
    goto v_30088;
v_30089:
    goto v_30090;
v_30091:
    return cons(v_30241, v_30240);
v_30062:
    goto v_30116;
v_30112:
    v_30240 = stack[-3];
    v_30241 = qcar(v_30240);
    goto v_30113;
v_30114:
    v_30240 = stack[-2];
    v_30240 = qcdr(v_30240);
    goto v_30115;
v_30116:
    goto v_30112;
v_30113:
    goto v_30114;
v_30115:
    fn = elt(env, 2); // gcdf
    v_30240 = (*qfn2(fn))(fn, v_30241, v_30240);
    env = stack[-5];
    stack[-4] = v_30240;
    goto v_30126;
v_30122:
    v_30240 = stack[-2];
    v_30241 = qcar(v_30240);
    goto v_30123;
v_30124:
    v_30240 = stack[-3];
    v_30240 = qcdr(v_30240);
    goto v_30125;
v_30126:
    goto v_30122;
v_30123:
    goto v_30124;
v_30125:
    fn = elt(env, 2); // gcdf
    v_30240 = (*qfn2(fn))(fn, v_30241, v_30240);
    env = stack[-5];
    stack[-1] = v_30240;
    goto v_30136;
v_30132:
    goto v_30142;
v_30138:
    v_30240 = stack[-3];
    v_30241 = qcar(v_30240);
    goto v_30139;
v_30140:
    v_30240 = stack[-4];
    goto v_30141;
v_30142:
    goto v_30138;
v_30139:
    goto v_30140;
v_30141:
    fn = elt(env, 3); // quotf!-fail
    stack[0] = (*qfn2(fn))(fn, v_30241, v_30240);
    env = stack[-5];
    goto v_30133;
v_30134:
    goto v_30151;
v_30147:
    v_30240 = stack[-2];
    v_30241 = qcar(v_30240);
    goto v_30148;
v_30149:
    v_30240 = stack[-1];
    goto v_30150;
v_30151:
    goto v_30147;
v_30148:
    goto v_30149;
v_30150:
    fn = elt(env, 3); // quotf!-fail
    v_30240 = (*qfn2(fn))(fn, v_30241, v_30240);
    env = stack[-5];
    goto v_30135;
v_30136:
    goto v_30132;
v_30133:
    goto v_30134;
v_30135:
    fn = elt(env, 1); // !*multf
    v_30240 = (*qfn2(fn))(fn, stack[0], v_30240);
    env = stack[-5];
    stack[0] = v_30240;
    goto v_30160;
v_30156:
    goto v_30166;
v_30162:
    v_30240 = stack[-3];
    v_30241 = qcdr(v_30240);
    goto v_30163;
v_30164:
    v_30240 = stack[-1];
    goto v_30165;
v_30166:
    goto v_30162;
v_30163:
    goto v_30164;
v_30165:
    fn = elt(env, 3); // quotf!-fail
    stack[-1] = (*qfn2(fn))(fn, v_30241, v_30240);
    env = stack[-5];
    goto v_30157;
v_30158:
    goto v_30175;
v_30171:
    v_30240 = stack[-2];
    v_30241 = qcdr(v_30240);
    goto v_30172;
v_30173:
    v_30240 = stack[-4];
    goto v_30174;
v_30175:
    goto v_30171;
v_30172:
    goto v_30173;
v_30174:
    fn = elt(env, 3); // quotf!-fail
    v_30240 = (*qfn2(fn))(fn, v_30241, v_30240);
    env = stack[-5];
    goto v_30159;
v_30160:
    goto v_30156;
v_30157:
    goto v_30158;
v_30159:
    fn = elt(env, 1); // !*multf
    v_30240 = (*qfn2(fn))(fn, stack[-1], v_30240);
    env = stack[-5];
    stack[-4] = v_30240;
    v_30240 = stack[-4];
    fn = elt(env, 4); // minusf
    v_30240 = (*qfn1(fn))(fn, v_30240);
    env = stack[-5];
    if (v_30240 == nil) goto v_30182;
    v_30240 = stack[0];
    fn = elt(env, 5); // negf
    v_30240 = (*qfn1(fn))(fn, v_30240);
    env = stack[-5];
    stack[0] = v_30240;
    v_30240 = stack[-4];
    fn = elt(env, 5); // negf
    v_30240 = (*qfn1(fn))(fn, v_30240);
    env = stack[-5];
    stack[-4] = v_30240;
    goto v_30180;
v_30182:
v_30180:
    goto v_30194;
v_30190:
    v_30241 = stack[0];
    goto v_30191;
v_30192:
    v_30240 = stack[-4];
    goto v_30193;
v_30194:
    goto v_30190;
v_30191:
    goto v_30192;
v_30193:
    fn = elt(env, 2); // gcdf
    v_30240 = (*qfn2(fn))(fn, v_30241, v_30240);
    env = stack[-5];
    stack[-1] = v_30240;
    goto v_30205;
v_30201:
    v_30241 = stack[-1];
    goto v_30202;
v_30203:
    v_30240 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30204;
v_30205:
    goto v_30201;
v_30202:
    goto v_30203;
v_30204:
    if (v_30241 == v_30240) goto v_30199;
    else goto v_30200;
v_30199:
    goto v_30213;
v_30209:
    v_30241 = stack[0];
    goto v_30210;
v_30211:
    v_30240 = stack[-4];
    goto v_30212;
v_30213:
    goto v_30209;
v_30210:
    goto v_30211;
v_30212:
    return cons(v_30241, v_30240);
v_30200:
    goto v_30223;
v_30219:
    goto v_30229;
v_30225:
    v_30241 = stack[0];
    goto v_30226;
v_30227:
    v_30240 = stack[-1];
    goto v_30228;
v_30229:
    goto v_30225;
v_30226:
    goto v_30227;
v_30228:
    fn = elt(env, 3); // quotf!-fail
    stack[0] = (*qfn2(fn))(fn, v_30241, v_30240);
    env = stack[-5];
    goto v_30220;
v_30221:
    goto v_30237;
v_30233:
    v_30241 = stack[-4];
    goto v_30234;
v_30235:
    v_30240 = stack[-1];
    goto v_30236;
v_30237:
    goto v_30233;
v_30234:
    goto v_30235;
v_30236:
    fn = elt(env, 3); // quotf!-fail
    v_30240 = (*qfn2(fn))(fn, v_30241, v_30240);
    goto v_30222;
v_30223:
    goto v_30219;
v_30220:
    goto v_30221;
v_30222:
    {
        LispObject v_30247 = stack[0];
        return cons(v_30247, v_30240);
    }
    v_30240 = nil;
    goto v_30038;
    v_30240 = nil;
v_30038:
    return onevalue(v_30240);
}



// Code for taymindegreel

static LispObject CC_taymindegreel(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30096, v_30097;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30034,v_30035);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_30035;
    stack[-2] = v_30034;
// end of prologue
    stack[-3] = nil;
v_30040:
    v_30096 = stack[-2];
    if (v_30096 == nil) goto v_30043;
    else goto v_30044;
v_30043:
    v_30096 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_30096);
    }
v_30044:
    goto v_30055;
v_30051:
    goto v_30061;
v_30057:
    v_30096 = stack[-2];
    v_30096 = qcar(v_30096);
    stack[0] = v_30096;
    v_30096 = (LispObject)0+TAG_FIXNUM; // 0
    v_30097 = v_30096;
v_30066:
    v_30096 = stack[0];
    if (v_30096 == nil) goto v_30072;
    else goto v_30073;
v_30072:
    v_30096 = v_30097;
    v_30097 = v_30096;
    goto v_30065;
v_30073:
    goto v_30081;
v_30077:
    v_30096 = stack[0];
    v_30096 = qcar(v_30096);
    goto v_30078;
v_30079:
    goto v_30080;
v_30081:
    goto v_30077;
v_30078:
    goto v_30079;
v_30080:
    fn = elt(env, 2); // tayexp!-plus2
    v_30096 = (*qfn2(fn))(fn, v_30096, v_30097);
    env = stack[-4];
    v_30097 = v_30096;
    v_30096 = stack[0];
    v_30096 = qcdr(v_30096);
    stack[0] = v_30096;
    goto v_30066;
v_30065:
    goto v_30058;
v_30059:
    v_30096 = stack[-1];
    v_30096 = qcar(v_30096);
    goto v_30060;
v_30061:
    goto v_30057;
v_30058:
    goto v_30059;
v_30060:
    fn = elt(env, 3); // tayexp!-min2
    v_30097 = (*qfn2(fn))(fn, v_30097, v_30096);
    env = stack[-4];
    goto v_30052;
v_30053:
    v_30096 = stack[-3];
    goto v_30054;
v_30055:
    goto v_30051;
v_30052:
    goto v_30053;
v_30054:
    v_30096 = cons(v_30097, v_30096);
    env = stack[-4];
    stack[-3] = v_30096;
    v_30096 = stack[-2];
    v_30096 = qcdr(v_30096);
    stack[-2] = v_30096;
    v_30096 = stack[-1];
    v_30096 = qcdr(v_30096);
    stack[-1] = v_30096;
    goto v_30040;
    v_30096 = nil;
    return onevalue(v_30096);
}



// Code for cl_susimkatl

static LispObject CC_cl_susimkatl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30308, v_30309, v_30310;
    LispObject fn;
    LispObject v_30037, v_30036, v_30035, v_30034;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_susimkatl");
    va_start(aa, nargs);
    v_30034 = va_arg(aa, LispObject);
    v_30035 = va_arg(aa, LispObject);
    v_30036 = va_arg(aa, LispObject);
    v_30037 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_30037,v_30036,v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_30034,v_30035,v_30036,v_30037);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_30037;
    v_30308 = v_30036;
    stack[-4] = v_30035;
    stack[-5] = v_30034;
// end of prologue
    stack[-6] = v_30308;
v_30047:
    v_30308 = stack[-6];
    if (v_30308 == nil) goto v_30052;
    else goto v_30053;
v_30052:
    v_30308 = nil;
    goto v_30046;
v_30053:
    v_30308 = stack[-6];
    v_30308 = qcar(v_30308);
    v_30310 = v_30308;
    goto v_30067;
v_30063:
    v_30308 = v_30310;
    v_30309 = qcdr(v_30308);
    goto v_30064;
v_30065:
    v_30308 = stack[-3];
    goto v_30066;
v_30067:
    goto v_30063;
v_30064:
    goto v_30065;
v_30066:
    if (equal(v_30309, v_30308)) goto v_30061;
    else goto v_30062;
v_30061:
    v_30308 = v_30310;
    v_30308 = qcar(v_30308);
    v_30308 = ncons(v_30308);
    env = stack[-7];
    goto v_30060;
v_30062:
    v_30308 = nil;
v_30060:
    stack[-2] = v_30308;
    v_30308 = stack[-2];
    fn = elt(env, 6); // lastpair
    v_30308 = (*qfn1(fn))(fn, v_30308);
    env = stack[-7];
    stack[-1] = v_30308;
    v_30308 = stack[-6];
    v_30308 = qcdr(v_30308);
    stack[-6] = v_30308;
    v_30308 = stack[-1];
    if (!consp(v_30308)) goto v_30080;
    else goto v_30081;
v_30080:
    goto v_30047;
v_30081:
v_30048:
    v_30308 = stack[-6];
    if (v_30308 == nil) goto v_30085;
    else goto v_30086;
v_30085:
    v_30308 = stack[-2];
    goto v_30046;
v_30086:
    goto v_30094;
v_30090:
    stack[0] = stack[-1];
    goto v_30091;
v_30092:
    v_30308 = stack[-6];
    v_30308 = qcar(v_30308);
    v_30310 = v_30308;
    goto v_30107;
v_30103:
    v_30308 = v_30310;
    v_30309 = qcdr(v_30308);
    goto v_30104;
v_30105:
    v_30308 = stack[-3];
    goto v_30106;
v_30107:
    goto v_30103;
v_30104:
    goto v_30105;
v_30106:
    if (equal(v_30309, v_30308)) goto v_30101;
    else goto v_30102;
v_30101:
    v_30308 = v_30310;
    v_30308 = qcar(v_30308);
    v_30308 = ncons(v_30308);
    env = stack[-7];
    goto v_30100;
v_30102:
    v_30308 = nil;
v_30100:
    goto v_30093;
v_30094:
    goto v_30090;
v_30091:
    goto v_30092;
v_30093:
    v_30308 = Lrplacd(nil, stack[0], v_30308);
    env = stack[-7];
    v_30308 = stack[-1];
    fn = elt(env, 6); // lastpair
    v_30308 = (*qfn1(fn))(fn, v_30308);
    env = stack[-7];
    stack[-1] = v_30308;
    v_30308 = stack[-6];
    v_30308 = qcdr(v_30308);
    stack[-6] = v_30308;
    goto v_30048;
v_30046:
    v_30310 = v_30308;
    v_30308 = v_30310;
    if (v_30308 == nil) goto v_30120;
    else goto v_30121;
v_30120:
    v_30308 = nil;
    goto v_30041;
v_30121:
    goto v_30129;
v_30125:
    v_30309 = v_30310;
    goto v_30126;
v_30127:
    v_30308 = stack[-4];
    goto v_30128;
v_30129:
    goto v_30125;
v_30126:
    goto v_30127;
v_30128:
    fn = elt(env, 7); // rl_susipost
    v_30308 = (*qfn2(fn))(fn, v_30309, v_30308);
    env = stack[-7];
    v_30310 = v_30308;
    goto v_30144;
v_30140:
    v_30309 = v_30310;
    goto v_30141;
v_30142:
    v_30308 = elt(env, 1); // true
    goto v_30143;
v_30144:
    goto v_30140;
v_30141:
    goto v_30142;
v_30143:
    if (v_30309 == v_30308) goto v_30138;
    else goto v_30139;
v_30138:
    v_30308 = lisp_true;
    goto v_30137;
v_30139:
    goto v_30154;
v_30150:
    v_30309 = v_30310;
    goto v_30151;
v_30152:
    v_30308 = elt(env, 2); // false
    goto v_30153;
v_30154:
    goto v_30150;
v_30151:
    goto v_30152;
v_30153:
    v_30308 = (v_30309 == v_30308 ? lisp_true : nil);
    goto v_30137;
    v_30308 = nil;
v_30137:
    if (v_30308 == nil) goto v_30135;
    goto v_30164;
v_30160:
    goto v_30161;
v_30162:
    goto v_30170;
v_30166:
    v_30309 = stack[-5];
    goto v_30167;
v_30168:
    v_30308 = elt(env, 3); // and
    goto v_30169;
v_30170:
    goto v_30166;
v_30167:
    goto v_30168;
v_30169:
    v_30308 = (v_30309 == v_30308 ? lisp_true : nil);
    goto v_30163;
v_30164:
    goto v_30160;
v_30161:
    goto v_30162;
v_30163:
    fn = elt(env, 8); // cl_cflip
    v_30308 = (*qfn2(fn))(fn, v_30310, v_30308);
    return ncons(v_30308);
v_30135:
    goto v_30182;
v_30178:
    v_30309 = v_30310;
    goto v_30179;
v_30180:
    v_30308 = elt(env, 4); // inctheo
    goto v_30181;
v_30182:
    goto v_30178;
v_30179:
    goto v_30180;
v_30181:
    if (v_30309 == v_30308) goto v_30176;
    else goto v_30177;
v_30176:
    goto v_30190;
v_30186:
    v_30310 = elt(env, 2); // false
    goto v_30187;
v_30188:
    goto v_30196;
v_30192:
    v_30309 = stack[-5];
    goto v_30193;
v_30194:
    v_30308 = elt(env, 3); // and
    goto v_30195;
v_30196:
    goto v_30192;
v_30193:
    goto v_30194;
v_30195:
    v_30308 = (v_30309 == v_30308 ? lisp_true : nil);
    goto v_30189;
v_30190:
    goto v_30186;
v_30187:
    goto v_30188;
v_30189:
    {
        fn = elt(env, 8); // cl_cflip
        return (*qfn2(fn))(fn, v_30310, v_30308);
    }
v_30177:
    goto v_30208;
v_30204:
    v_30309 = stack[-5];
    goto v_30205;
v_30206:
    v_30308 = elt(env, 5); // or
    goto v_30207;
v_30208:
    goto v_30204;
v_30205:
    goto v_30206;
v_30207:
    if (v_30309 == v_30308) goto v_30202;
    else goto v_30203;
v_30202:
    v_30308 = v_30310;
    stack[-3] = v_30308;
    v_30308 = stack[-3];
    if (v_30308 == nil) goto v_30220;
    else goto v_30221;
v_30220:
    v_30308 = nil;
    goto v_30215;
v_30221:
    v_30308 = stack[-3];
    v_30308 = qcar(v_30308);
    fn = elt(env, 9); // rl_negateat
    v_30308 = (*qfn1(fn))(fn, v_30308);
    env = stack[-7];
    v_30308 = ncons(v_30308);
    env = stack[-7];
    stack[-1] = v_30308;
    stack[-2] = v_30308;
v_30216:
    v_30308 = stack[-3];
    v_30308 = qcdr(v_30308);
    stack[-3] = v_30308;
    v_30308 = stack[-3];
    if (v_30308 == nil) goto v_30234;
    else goto v_30235;
v_30234:
    v_30308 = stack[-2];
    goto v_30215;
v_30235:
    goto v_30243;
v_30239:
    stack[0] = stack[-1];
    goto v_30240;
v_30241:
    v_30308 = stack[-3];
    v_30308 = qcar(v_30308);
    fn = elt(env, 9); // rl_negateat
    v_30308 = (*qfn1(fn))(fn, v_30308);
    env = stack[-7];
    v_30308 = ncons(v_30308);
    env = stack[-7];
    goto v_30242;
v_30243:
    goto v_30239;
v_30240:
    goto v_30241;
v_30242:
    v_30308 = Lrplacd(nil, stack[0], v_30308);
    env = stack[-7];
    v_30308 = stack[-1];
    v_30308 = qcdr(v_30308);
    stack[-1] = v_30308;
    goto v_30216;
v_30215:
    v_30310 = v_30308;
    goto v_30201;
v_30203:
v_30201:
    v_30308 = v_30310;
    stack[-3] = v_30308;
    v_30308 = stack[-3];
    if (v_30308 == nil) goto v_30262;
    else goto v_30263;
v_30262:
    v_30308 = nil;
    goto v_30257;
v_30263:
    v_30308 = stack[-3];
    v_30308 = qcar(v_30308);
    goto v_30275;
v_30271:
    v_30309 = v_30308;
    goto v_30272;
v_30273:
    v_30308 = stack[-4];
    goto v_30274;
v_30275:
    goto v_30271;
v_30272:
    goto v_30273;
v_30274:
    fn = elt(env, 10); // rl_susitf
    v_30308 = (*qfn2(fn))(fn, v_30309, v_30308);
    env = stack[-7];
    v_30308 = ncons(v_30308);
    env = stack[-7];
    stack[-1] = v_30308;
    stack[-2] = v_30308;
v_30258:
    v_30308 = stack[-3];
    v_30308 = qcdr(v_30308);
    stack[-3] = v_30308;
    v_30308 = stack[-3];
    if (v_30308 == nil) goto v_30282;
    else goto v_30283;
v_30282:
    v_30308 = stack[-2];
    goto v_30257;
v_30283:
    goto v_30291;
v_30287:
    stack[0] = stack[-1];
    goto v_30288;
v_30289:
    v_30308 = stack[-3];
    v_30308 = qcar(v_30308);
    goto v_30302;
v_30298:
    v_30309 = v_30308;
    goto v_30299;
v_30300:
    v_30308 = stack[-4];
    goto v_30301;
v_30302:
    goto v_30298;
v_30299:
    goto v_30300;
v_30301:
    fn = elt(env, 10); // rl_susitf
    v_30308 = (*qfn2(fn))(fn, v_30309, v_30308);
    env = stack[-7];
    v_30308 = ncons(v_30308);
    env = stack[-7];
    goto v_30290;
v_30291:
    goto v_30287;
v_30288:
    goto v_30289;
v_30290:
    v_30308 = Lrplacd(nil, stack[0], v_30308);
    env = stack[-7];
    v_30308 = stack[-1];
    v_30308 = qcdr(v_30308);
    stack[-1] = v_30308;
    goto v_30258;
v_30257:
    v_30310 = v_30308;
    v_30308 = v_30310;
v_30041:
    return onevalue(v_30308);
}



// Code for sfto_kexp

static LispObject CC_sfto_kexp(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30073, v_30074;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30034,v_30035);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30035;
    stack[-1] = v_30034;
// end of prologue
    goto v_30040;
    goto v_30038;
v_30040:
v_30038:
    goto v_30051;
v_30047:
    v_30074 = stack[0];
    goto v_30048;
v_30049:
    v_30073 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30050;
v_30051:
    goto v_30047;
v_30048:
    goto v_30049;
v_30050:
    v_30073 = Leqn(nil, v_30074, v_30073);
    env = stack[-2];
    if (v_30073 == nil) goto v_30045;
    v_30073 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30043;
v_30045:
    goto v_30063;
v_30059:
    goto v_30069;
v_30065:
    v_30074 = stack[-1];
    goto v_30066;
v_30067:
    v_30073 = stack[0];
    goto v_30068;
v_30069:
    goto v_30065;
v_30066:
    goto v_30067;
v_30068:
    fn = elt(env, 1); // to
    v_30074 = (*qfn2(fn))(fn, v_30074, v_30073);
    env = stack[-2];
    goto v_30060;
v_30061:
    v_30073 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30062;
v_30063:
    goto v_30059;
v_30060:
    goto v_30061;
v_30062:
    v_30073 = cons(v_30074, v_30073);
    return ncons(v_30073);
    v_30073 = nil;
v_30043:
    return onevalue(v_30073);
}



// Code for acfsf_0mk2

static LispObject CC_acfsf_0mk2(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30048, v_30049, v_30050;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30048 = v_30035;
    v_30049 = v_30034;
// end of prologue
    goto v_30044;
v_30038:
    v_30050 = v_30049;
    goto v_30039;
v_30040:
    v_30049 = v_30048;
    goto v_30041;
v_30042:
    v_30048 = nil;
    goto v_30043;
v_30044:
    goto v_30038;
v_30039:
    goto v_30040;
v_30041:
    goto v_30042;
v_30043:
    return list3(v_30050, v_30049, v_30048);
}



// Code for latexprint

static LispObject CC_latexprint(LispObject env,
                         LispObject v_30034)
{
    env = qenv(env);
    LispObject v_30040;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30034);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_30034;
// end of prologue
    fn = elt(env, 1); // prinlabegin
    v_30040 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_30040 = stack[0];
    fn = elt(env, 2); // latexprin
    v_30040 = (*qfn1(fn))(fn, v_30040);
    env = stack[-1];
    {
        fn = elt(env, 3); // prinlaend
        return (*qfnn(fn))(fn, 0);
    }
}



// Code for decimal2internal

static LispObject CC_decimal2internal(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30095, v_30096, v_30097;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30034,v_30035);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30035;
    stack[-1] = v_30034;
// end of prologue
    goto v_30046;
v_30042:
    v_30096 = stack[0];
    goto v_30043;
v_30044:
    v_30095 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30045;
v_30046:
    goto v_30042;
v_30043:
    goto v_30044;
v_30045:
    v_30095 = (LispObject)geq2(v_30096, v_30095);
    v_30095 = v_30095 ? lisp_true : nil;
    env = stack[-3];
    if (v_30095 == nil) goto v_30040;
    goto v_30056;
v_30050:
    stack[-2] = elt(env, 1); // !:rd!:
    goto v_30051;
v_30052:
    goto v_30063;
v_30059:
    goto v_30060;
v_30061:
    goto v_30070;
v_30066:
    v_30096 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_30067;
v_30068:
    v_30095 = stack[0];
    goto v_30069;
v_30070:
    goto v_30066;
v_30067:
    goto v_30068;
v_30069:
    v_30095 = Lexpt(nil, v_30096, v_30095);
    env = stack[-3];
    goto v_30062;
v_30063:
    goto v_30059;
v_30060:
    goto v_30061;
v_30062:
    v_30096 = times2(stack[-1], v_30095);
    goto v_30053;
v_30054:
    v_30095 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30055;
v_30056:
    goto v_30050;
v_30051:
    goto v_30052;
v_30053:
    goto v_30054;
v_30055:
    {
        LispObject v_30101 = stack[-2];
        return list2star(v_30101, v_30096, v_30095);
    }
v_30040:
    goto v_30081;
v_30077:
    goto v_30089;
v_30083:
    v_30097 = elt(env, 1); // !:rd!:
    goto v_30084;
v_30085:
    v_30096 = stack[-1];
    goto v_30086;
v_30087:
    v_30095 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30088;
v_30089:
    goto v_30083;
v_30084:
    goto v_30085;
v_30086:
    goto v_30087;
v_30088:
    stack[-1] = list2star(v_30097, v_30096, v_30095);
    env = stack[-3];
    goto v_30078;
v_30079:
    v_30095 = stack[0];
    v_30095 = negate(v_30095);
    env = stack[-3];
    goto v_30080;
v_30081:
    goto v_30077;
v_30078:
    goto v_30079;
v_30080:
    {
        LispObject v_30102 = stack[-1];
        fn = elt(env, 2); // divide!-by!-power!-of!-ten
        return (*qfn2(fn))(fn, v_30102, v_30095);
    }
    v_30095 = nil;
    return onevalue(v_30095);
}



// Code for is_buble

static LispObject CC_is_buble(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30081, v_30082;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30034,v_30035);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30035;
    stack[-1] = v_30034;
// end of prologue
    goto v_30043;
v_30039:
    v_30082 = stack[-1];
    goto v_30040;
v_30041:
    v_30081 = stack[0];
    goto v_30042;
v_30043:
    goto v_30039;
v_30040:
    goto v_30041;
v_30042:
    fn = elt(env, 1); // diff_vertex
    v_30081 = (*qfn2(fn))(fn, v_30082, v_30081);
    env = stack[-3];
    v_30081 = Llength(nil, v_30081);
    env = stack[-3];
    stack[-2] = v_30081;
    goto v_30056;
v_30052:
    v_30082 = stack[-2];
    goto v_30053;
v_30054:
    v_30081 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_30055;
v_30056:
    goto v_30052;
v_30053:
    goto v_30054;
v_30055:
    v_30081 = (LispObject)geq2(v_30082, v_30081);
    v_30081 = v_30081 ? lisp_true : nil;
    env = stack[-3];
    if (v_30081 == nil) goto v_30050;
    v_30081 = nil;
    goto v_30048;
v_30050:
    goto v_30069;
v_30063:
    goto v_30075;
v_30071:
    v_30082 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_30072;
v_30073:
    v_30081 = stack[-2];
    goto v_30074;
v_30075:
    goto v_30071;
v_30072:
    goto v_30073;
v_30074:
    stack[-2] = times2(v_30082, v_30081);
    env = stack[-3];
    goto v_30064;
v_30065:
    goto v_30066;
v_30067:
    v_30081 = stack[0];
    v_30081 = ncons(v_30081);
    goto v_30068;
v_30069:
    goto v_30063;
v_30064:
    goto v_30065;
v_30066:
    goto v_30067;
v_30068:
    {
        LispObject v_30086 = stack[-2];
        LispObject v_30087 = stack[-1];
        return list2star(v_30086, v_30087, v_30081);
    }
    v_30081 = nil;
v_30048:
    return onevalue(v_30081);
}



// Code for tidysqrtf

static LispObject CC_tidysqrtf(LispObject env,
                         LispObject v_30034)
{
    env = qenv(env);
    LispObject v_30226, v_30227, v_30228;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30034);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_30034;
// end of prologue
    v_30226 = stack[-1];
    if (!consp(v_30226)) goto v_30042;
    else goto v_30043;
v_30042:
    v_30226 = lisp_true;
    goto v_30041;
v_30043:
    v_30226 = stack[-1];
    v_30226 = qcar(v_30226);
    v_30226 = (consp(v_30226) ? nil : lisp_true);
    goto v_30041;
    v_30226 = nil;
v_30041:
    if (v_30226 == nil) goto v_30039;
    goto v_30056;
v_30052:
    v_30227 = stack[-1];
    goto v_30053;
v_30054:
    v_30226 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30055;
v_30056:
    goto v_30052;
v_30053:
    goto v_30054;
v_30055:
    return cons(v_30227, v_30226);
v_30039:
    v_30226 = stack[-1];
    v_30226 = qcar(v_30226);
    v_30226 = qcar(v_30226);
    stack[-2] = v_30226;
    goto v_30076;
v_30072:
    v_30226 = stack[-2];
    v_30227 = qcar(v_30226);
    goto v_30073;
v_30074:
    v_30226 = elt(env, 1); // i
    goto v_30075;
v_30076:
    goto v_30072;
v_30073:
    goto v_30074;
v_30075:
    if (v_30227 == v_30226) goto v_30070;
    else goto v_30071;
v_30070:
    goto v_30085;
v_30081:
    v_30227 = elt(env, 2); // (sqrt -1)
    goto v_30082;
v_30083:
    v_30226 = stack[-2];
    v_30226 = qcdr(v_30226);
    goto v_30084;
v_30085:
    goto v_30081;
v_30082:
    goto v_30083;
v_30084:
    fn = elt(env, 4); // mksp
    v_30226 = (*qfn2(fn))(fn, v_30227, v_30226);
    env = stack[-3];
    stack[-2] = v_30226;
    goto v_30069;
v_30071:
v_30069:
    goto v_30102;
v_30098:
    v_30226 = stack[-2];
    v_30227 = qcar(v_30226);
    goto v_30099;
v_30100:
    v_30226 = elt(env, 3); // sqrt
    goto v_30101;
v_30102:
    goto v_30098;
v_30099:
    goto v_30100;
v_30101:
    if (!consp(v_30227)) goto v_30096;
    v_30227 = qcar(v_30227);
    if (v_30227 == v_30226) goto v_30095;
    else goto v_30096;
v_30095:
    v_30226 = stack[-2];
    v_30226 = qcdr(v_30226);
    v_30226 = Lonep(nil, v_30226);
    env = stack[-3];
    v_30226 = (v_30226 == nil ? lisp_true : nil);
    goto v_30094;
v_30096:
    v_30226 = nil;
    goto v_30094;
    v_30226 = nil;
v_30094:
    if (v_30226 == nil) goto v_30092;
    goto v_30121;
v_30117:
    v_30226 = stack[-2];
    v_30227 = qcdr(v_30226);
    goto v_30118;
v_30119:
    v_30226 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_30120;
v_30121:
    goto v_30117;
v_30118:
    goto v_30119;
v_30120:
    v_30226 = Ldivide(nil, v_30227, v_30226);
    env = stack[-3];
    stack[0] = v_30226;
    goto v_30130;
v_30126:
    v_30226 = stack[-2];
    v_30226 = qcar(v_30226);
    v_30226 = qcdr(v_30226);
    v_30226 = qcar(v_30226);
    fn = elt(env, 5); // simp
    v_30227 = (*qfn1(fn))(fn, v_30226);
    env = stack[-3];
    goto v_30127;
v_30128:
    v_30226 = stack[0];
    v_30226 = qcar(v_30226);
    goto v_30129;
v_30130:
    goto v_30126;
v_30127:
    goto v_30128;
v_30129:
    fn = elt(env, 6); // exptsq
    v_30226 = (*qfn2(fn))(fn, v_30227, v_30226);
    env = stack[-3];
    v_30228 = v_30226;
    goto v_30146;
v_30142:
    v_30226 = stack[0];
    v_30227 = qcdr(v_30226);
    goto v_30143;
v_30144:
    v_30226 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30145;
v_30146:
    goto v_30142;
v_30143:
    goto v_30144;
v_30145:
    if (v_30227 == v_30226) goto v_30141;
    goto v_30155;
v_30151:
    stack[0] = v_30228;
    goto v_30152;
v_30153:
    goto v_30164;
v_30158:
    goto v_30170;
v_30166:
    goto v_30176;
v_30172:
    v_30226 = stack[-2];
    v_30227 = qcar(v_30226);
    goto v_30173;
v_30174:
    v_30226 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30175;
v_30176:
    goto v_30172;
v_30173:
    goto v_30174;
v_30175:
    fn = elt(env, 4); // mksp
    v_30227 = (*qfn2(fn))(fn, v_30227, v_30226);
    env = stack[-3];
    goto v_30167;
v_30168:
    v_30226 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30169;
v_30170:
    goto v_30166;
v_30167:
    goto v_30168;
v_30169:
    v_30228 = cons(v_30227, v_30226);
    env = stack[-3];
    goto v_30159;
v_30160:
    v_30227 = nil;
    goto v_30161;
v_30162:
    v_30226 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30163;
v_30164:
    goto v_30158;
v_30159:
    goto v_30160;
v_30161:
    goto v_30162;
v_30163:
    v_30226 = acons(v_30228, v_30227, v_30226);
    env = stack[-3];
    goto v_30154;
v_30155:
    goto v_30151;
v_30152:
    goto v_30153;
v_30154:
    fn = elt(env, 7); // multsq
    v_30226 = (*qfn2(fn))(fn, stack[0], v_30226);
    env = stack[-3];
    v_30228 = v_30226;
    goto v_30139;
v_30141:
v_30139:
    v_30226 = v_30228;
    fn = elt(env, 8); // tidysqrt
    v_30226 = (*qfn1(fn))(fn, v_30226);
    env = stack[-3];
    v_30228 = v_30226;
    goto v_30090;
v_30092:
    goto v_30194;
v_30188:
    goto v_30200;
v_30196:
    v_30227 = stack[-2];
    goto v_30197;
v_30198:
    v_30226 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30199;
v_30200:
    goto v_30196;
v_30197:
    goto v_30198;
v_30199:
    v_30228 = cons(v_30227, v_30226);
    env = stack[-3];
    goto v_30189;
v_30190:
    v_30227 = nil;
    goto v_30191;
v_30192:
    v_30226 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30193;
v_30194:
    goto v_30188;
v_30189:
    goto v_30190;
v_30191:
    goto v_30192;
v_30193:
    v_30226 = acons(v_30228, v_30227, v_30226);
    env = stack[-3];
    v_30228 = v_30226;
    goto v_30090;
v_30090:
    goto v_30210;
v_30206:
    stack[0] = v_30228;
    goto v_30207;
v_30208:
    v_30226 = stack[-1];
    v_30226 = qcar(v_30226);
    v_30226 = qcdr(v_30226);
    v_30226 = CC_tidysqrtf(elt(env, 0), v_30226);
    env = stack[-3];
    goto v_30209;
v_30210:
    goto v_30206;
v_30207:
    goto v_30208;
v_30209:
    fn = elt(env, 7); // multsq
    v_30226 = (*qfn2(fn))(fn, stack[0], v_30226);
    env = stack[-3];
    stack[-2] = v_30226;
    goto v_30221;
v_30217:
    stack[0] = stack[-2];
    goto v_30218;
v_30219:
    v_30226 = stack[-1];
    v_30226 = qcdr(v_30226);
    v_30226 = CC_tidysqrtf(elt(env, 0), v_30226);
    env = stack[-3];
    goto v_30220;
v_30221:
    goto v_30217;
v_30218:
    goto v_30219;
v_30220:
    {
        LispObject v_30232 = stack[0];
        fn = elt(env, 9); // addsq
        return (*qfn2(fn))(fn, v_30232, v_30226);
    }
    goto v_30037;
    v_30226 = nil;
v_30037:
    return onevalue(v_30226);
}



// Code for ofsf_smwrmknowl

static LispObject CC_ofsf_smwrmknowl(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30060, v_30061, v_30062;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30061 = v_30035;
    v_30062 = v_30034;
// end of prologue
    v_30060 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_30060 == nil) goto v_30040;
    goto v_30047;
v_30043:
    v_30060 = v_30062;
    goto v_30044;
v_30045:
    goto v_30046;
v_30047:
    goto v_30043;
v_30044:
    goto v_30045;
v_30046:
    {
        fn = elt(env, 2); // ofsf_susirmknowl
        return (*qfn2(fn))(fn, v_30060, v_30061);
    }
v_30040:
    goto v_30057;
v_30053:
    v_30060 = v_30062;
    goto v_30054;
v_30055:
    goto v_30056;
v_30057:
    goto v_30053;
v_30054:
    goto v_30055;
v_30056:
    {
        fn = elt(env, 3); // ofsf_smrmknowl
        return (*qfn2(fn))(fn, v_30060, v_30061);
    }
    v_30060 = nil;
    return onevalue(v_30060);
}



// Code for eval!-yetunknowntypeexpr

static LispObject CC_evalKyetunknowntypeexpr(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30191, v_30192;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30034,v_30035);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_30035;
    stack[0] = v_30034;
// end of prologue
v_30033:
    v_30191 = stack[0];
    if (!consp(v_30191)) goto v_30039;
    else goto v_30040;
v_30039:
    v_30191 = stack[0];
    if (!symbolp(v_30191)) v_30191 = nil;
    else { v_30191 = qfastgets(v_30191);
           if (v_30191 != nil) { v_30191 = elt(v_30191, 4); // avalue
#ifdef RECORD_GET
             if (v_30191 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_30191 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_30191 == SPID_NOPROP) v_30191 = nil; }}
#endif
    v_30192 = v_30191;
    v_30191 = v_30192;
    if (v_30191 == nil) goto v_30048;
    goto v_30055;
v_30051:
    v_30191 = v_30192;
    v_30191 = qcdr(v_30191);
    v_30192 = qcar(v_30191);
    goto v_30052;
v_30053:
    v_30191 = stack[-4];
    goto v_30054;
v_30055:
    goto v_30051;
v_30052:
    goto v_30053;
v_30054:
    stack[0] = v_30192;
    stack[-4] = v_30191;
    goto v_30033;
v_30048:
    v_30191 = stack[0];
    goto v_30046;
    v_30191 = nil;
v_30046:
    goto v_30038;
v_30040:
    goto v_30073;
v_30069:
    v_30191 = stack[0];
    v_30192 = qcar(v_30191);
    goto v_30070;
v_30071:
    v_30191 = elt(env, 1); // !*sq
    goto v_30072;
v_30073:
    goto v_30069;
v_30070:
    goto v_30071;
v_30072:
    if (v_30192 == v_30191) goto v_30067;
    else goto v_30068;
v_30067:
    v_30191 = lisp_true;
    goto v_30066;
v_30068:
    v_30191 = stack[0];
    v_30191 = qcar(v_30191);
    if (!symbolp(v_30191)) v_30191 = nil;
    else { v_30191 = qfastgets(v_30191);
           if (v_30191 != nil) { v_30191 = elt(v_30191, 8); // dname
#ifdef RECORD_GET
             if (v_30191 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_30191 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_30191 == SPID_NOPROP) v_30191 = nil; }}
#endif
    if (v_30191 == nil) goto v_30082;
    else goto v_30081;
v_30082:
    goto v_30090;
v_30086:
    v_30191 = stack[0];
    v_30192 = qcar(v_30191);
    goto v_30087;
v_30088:
    v_30191 = elt(env, 2); // !:dn!:
    goto v_30089;
v_30090:
    goto v_30086;
v_30087:
    goto v_30088;
v_30089:
    v_30191 = (v_30192 == v_30191 ? lisp_true : nil);
v_30081:
    goto v_30066;
    v_30191 = nil;
v_30066:
    if (v_30191 == nil) goto v_30064;
    v_30191 = stack[0];
    goto v_30038;
v_30064:
    v_30191 = stack[0];
    v_30191 = qcar(v_30191);
    if (!symbolp(v_30191)) v_30191 = nil;
    else { v_30191 = qfastgets(v_30191);
           if (v_30191 != nil) { v_30191 = elt(v_30191, 45); // psopfn
#ifdef RECORD_GET
             if (v_30191 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v_30191 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v_30191 == SPID_NOPROP) v_30191 = nil; }}
#endif
    stack[-1] = v_30191;
    v_30191 = stack[-1];
    if (v_30191 == nil) goto v_30105;
    goto v_30113;
v_30109:
    v_30191 = stack[0];
    fn = elt(env, 4); // getrtype
    v_30192 = (*qfn1(fn))(fn, v_30191);
    env = stack[-6];
    goto v_30110;
v_30111:
    v_30191 = elt(env, 3); // yetunknowntype
    goto v_30112;
v_30113:
    goto v_30109;
v_30110:
    goto v_30111;
v_30112:
    if (v_30192 == v_30191) goto v_30108;
    else goto v_30105;
v_30108:
    goto v_30122;
v_30118:
    v_30192 = stack[-1];
    goto v_30119;
v_30120:
    v_30191 = stack[0];
    v_30191 = qcdr(v_30191);
    goto v_30121;
v_30122:
    goto v_30118;
v_30119:
    goto v_30120;
v_30121:
        return Lapply1(nil, v_30192, v_30191);
v_30105:
    goto v_30133;
v_30129:
    v_30191 = stack[0];
    stack[-5] = qcar(v_30191);
    goto v_30130;
v_30131:
    v_30191 = stack[0];
    v_30191 = qcdr(v_30191);
    stack[-3] = v_30191;
    v_30191 = stack[-3];
    if (v_30191 == nil) goto v_30146;
    else goto v_30147;
v_30146:
    v_30191 = nil;
    goto v_30140;
v_30147:
    v_30191 = stack[-3];
    v_30191 = qcar(v_30191);
    goto v_30159;
v_30155:
    v_30192 = v_30191;
    goto v_30156;
v_30157:
    v_30191 = stack[-4];
    goto v_30158;
v_30159:
    goto v_30155;
v_30156:
    goto v_30157;
v_30158:
    v_30191 = CC_evalKyetunknowntypeexpr(elt(env, 0), v_30192, v_30191);
    env = stack[-6];
    v_30191 = ncons(v_30191);
    env = stack[-6];
    stack[-1] = v_30191;
    stack[-2] = v_30191;
v_30141:
    v_30191 = stack[-3];
    v_30191 = qcdr(v_30191);
    stack[-3] = v_30191;
    v_30191 = stack[-3];
    if (v_30191 == nil) goto v_30166;
    else goto v_30167;
v_30166:
    v_30191 = stack[-2];
    goto v_30140;
v_30167:
    goto v_30175;
v_30171:
    stack[0] = stack[-1];
    goto v_30172;
v_30173:
    v_30191 = stack[-3];
    v_30191 = qcar(v_30191);
    goto v_30186;
v_30182:
    v_30192 = v_30191;
    goto v_30183;
v_30184:
    v_30191 = stack[-4];
    goto v_30185;
v_30186:
    goto v_30182;
v_30183:
    goto v_30184;
v_30185:
    v_30191 = CC_evalKyetunknowntypeexpr(elt(env, 0), v_30192, v_30191);
    env = stack[-6];
    v_30191 = ncons(v_30191);
    env = stack[-6];
    goto v_30174;
v_30175:
    goto v_30171;
v_30172:
    goto v_30173;
v_30174:
    v_30191 = Lrplacd(nil, stack[0], v_30191);
    env = stack[-6];
    v_30191 = stack[-1];
    v_30191 = qcdr(v_30191);
    stack[-1] = v_30191;
    goto v_30141;
v_30140:
    goto v_30132;
v_30133:
    goto v_30129;
v_30130:
    goto v_30131;
v_30132:
    {
        LispObject v_30199 = stack[-5];
        return cons(v_30199, v_30191);
    }
    v_30191 = nil;
    goto v_30038;
    v_30191 = nil;
v_30038:
    return onevalue(v_30191);
}



// Code for qqe_simplqequal

static LispObject CC_qqe_simplqequal(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30428, v_30429, v_30430;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30034,v_30035);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    v_30428 = v_30035;
    stack[0] = v_30034;
// end of prologue
v_30033:
    v_30428 = stack[0];
    fn = elt(env, 5); // qqe_arg2r
    v_30428 = (*qfn1(fn))(fn, v_30428);
    env = stack[-9];
    stack[-7] = v_30428;
    v_30428 = stack[0];
    fn = elt(env, 6); // qqe_arg2l
    v_30428 = (*qfn1(fn))(fn, v_30428);
    env = stack[-9];
    stack[-8] = v_30428;
    goto v_30061;
v_30057:
    v_30429 = stack[-7];
    goto v_30058;
v_30059:
    v_30428 = stack[-8];
    goto v_30060;
v_30061:
    goto v_30057;
v_30058:
    goto v_30059;
v_30060:
    if (equal(v_30429, v_30428)) goto v_30055;
    else goto v_30056;
v_30055:
    v_30428 = elt(env, 1); // true
    goto v_30048;
v_30056:
    v_30428 = stack[-8];
    fn = elt(env, 7); // qqe_qprefix!-var
    v_30428 = (*qfn1(fn))(fn, v_30428);
    env = stack[-9];
    stack[-6] = v_30428;
    v_30428 = stack[-7];
    fn = elt(env, 7); // qqe_qprefix!-var
    v_30428 = (*qfn1(fn))(fn, v_30428);
    env = stack[-9];
    stack[-5] = v_30428;
    goto v_30081;
v_30077:
    v_30429 = stack[-6];
    goto v_30078;
v_30079:
    v_30428 = stack[-5];
    goto v_30080;
v_30081:
    goto v_30077;
v_30078:
    goto v_30079;
v_30080:
    if (v_30429 == v_30428) goto v_30075;
    else goto v_30076;
v_30075:
    v_30428 = lisp_true;
    goto v_30074;
v_30076:
    goto v_30095;
v_30091:
    v_30429 = stack[-6];
    goto v_30092;
v_30093:
    v_30428 = elt(env, 2); // qepsilon
    goto v_30094;
v_30095:
    goto v_30091;
v_30092:
    goto v_30093;
v_30094:
    if (v_30429 == v_30428) goto v_30089;
    else goto v_30090;
v_30089:
    v_30428 = lisp_true;
    goto v_30088;
v_30090:
    goto v_30105;
v_30101:
    v_30429 = stack[-5];
    goto v_30102;
v_30103:
    v_30428 = elt(env, 2); // qepsilon
    goto v_30104;
v_30105:
    goto v_30101;
v_30102:
    goto v_30103;
v_30104:
    v_30428 = (v_30429 == v_30428 ? lisp_true : nil);
    goto v_30088;
    v_30428 = nil;
v_30088:
    goto v_30074;
    v_30428 = nil;
v_30074:
    if (v_30428 == nil) goto v_30072;
    v_30428 = stack[-7];
    fn = elt(env, 8); // qqe_number!-of!-adds!-in!-qterm
    v_30428 = (*qfn1(fn))(fn, v_30428);
    env = stack[-9];
    stack[-3] = v_30428;
    v_30428 = stack[-8];
    fn = elt(env, 8); // qqe_number!-of!-adds!-in!-qterm
    v_30428 = (*qfn1(fn))(fn, v_30428);
    env = stack[-9];
    stack[-4] = v_30428;
    v_30428 = stack[-7];
    fn = elt(env, 9); // qqe_number!-of!-tails!-in!-qterm
    v_30428 = (*qfn1(fn))(fn, v_30428);
    env = stack[-9];
    stack[-1] = v_30428;
    v_30428 = stack[-8];
    fn = elt(env, 9); // qqe_number!-of!-tails!-in!-qterm
    v_30428 = (*qfn1(fn))(fn, v_30428);
    env = stack[-9];
    stack[-2] = v_30428;
    goto v_30129;
v_30125:
    v_30429 = stack[-6];
    goto v_30126;
v_30127:
    v_30428 = stack[-5];
    goto v_30128;
v_30129:
    goto v_30125;
v_30126:
    goto v_30127;
v_30128:
    if (v_30429 == v_30428) goto v_30123;
    else goto v_30124;
v_30123:
    goto v_30142;
v_30138:
    v_30429 = stack[-3];
    goto v_30139;
v_30140:
    v_30428 = stack[-1];
    goto v_30141;
v_30142:
    goto v_30138;
v_30139:
    goto v_30140;
v_30141:
    v_30428 = (LispObject)geq2(v_30429, v_30428);
    v_30428 = v_30428 ? lisp_true : nil;
    env = stack[-9];
    if (v_30428 == nil) goto v_30136;
    else goto v_30135;
v_30136:
    goto v_30151;
v_30147:
    v_30429 = stack[-4];
    goto v_30148;
v_30149:
    v_30428 = stack[-2];
    goto v_30150;
v_30151:
    goto v_30147;
v_30148:
    goto v_30149;
v_30150:
    v_30428 = (LispObject)geq2(v_30429, v_30428);
    v_30428 = v_30428 ? lisp_true : nil;
    env = stack[-9];
    if (v_30428 == nil) goto v_30145;
    else goto v_30135;
v_30145:
    v_30428 = nil;
    goto v_30133;
v_30135:
    goto v_30161;
v_30157:
    goto v_30167;
v_30163:
    v_30429 = stack[-3];
    goto v_30164;
v_30165:
    v_30428 = stack[-1];
    goto v_30166;
v_30167:
    goto v_30163;
v_30164:
    goto v_30165;
v_30166:
    stack[0] = difference2(v_30429, v_30428);
    env = stack[-9];
    goto v_30158;
v_30159:
    goto v_30175;
v_30171:
    v_30429 = stack[-4];
    goto v_30172;
v_30173:
    v_30428 = stack[-2];
    goto v_30174;
v_30175:
    goto v_30171;
v_30172:
    goto v_30173;
v_30174:
    v_30428 = difference2(v_30429, v_30428);
    env = stack[-9];
    goto v_30160;
v_30161:
    goto v_30157;
v_30158:
    goto v_30159;
v_30160:
    v_30428 = (equal(stack[0], v_30428) ? lisp_true : nil);
    v_30428 = (v_30428 == nil ? lisp_true : nil);
    goto v_30133;
    v_30428 = nil;
v_30133:
    goto v_30122;
v_30124:
    v_30428 = nil;
    goto v_30122;
    v_30428 = nil;
v_30122:
    if (v_30428 == nil) goto v_30120;
    v_30428 = elt(env, 3); // false
    goto v_30048;
v_30120:
    goto v_30195;
v_30191:
    v_30429 = stack[-7];
    goto v_30192;
v_30193:
    v_30428 = elt(env, 2); // qepsilon
    goto v_30194;
v_30195:
    goto v_30191;
v_30192:
    goto v_30193;
v_30194:
    if (v_30429 == v_30428) goto v_30189;
    else goto v_30190;
v_30189:
    goto v_30203;
v_30199:
    v_30429 = stack[-4];
    goto v_30200;
v_30201:
    v_30428 = stack[-2];
    goto v_30202;
v_30203:
    goto v_30199;
v_30200:
    goto v_30201;
v_30202:
    v_30428 = (LispObject)greaterp2(v_30429, v_30428);
    v_30428 = v_30428 ? lisp_true : nil;
    env = stack[-9];
    goto v_30188;
v_30190:
    v_30428 = nil;
    goto v_30188;
    v_30428 = nil;
v_30188:
    if (v_30428 == nil) goto v_30186;
    v_30428 = elt(env, 3); // false
    goto v_30048;
v_30186:
    goto v_30220;
v_30216:
    v_30429 = stack[-8];
    goto v_30217;
v_30218:
    v_30428 = elt(env, 2); // qepsilon
    goto v_30219;
v_30220:
    goto v_30216;
v_30217:
    goto v_30218;
v_30219:
    if (v_30429 == v_30428) goto v_30214;
    else goto v_30215;
v_30214:
    goto v_30228;
v_30224:
    v_30429 = stack[-3];
    goto v_30225;
v_30226:
    v_30428 = stack[-1];
    goto v_30227;
v_30228:
    goto v_30224;
v_30225:
    goto v_30226;
v_30227:
    v_30428 = (LispObject)greaterp2(v_30429, v_30428);
    v_30428 = v_30428 ? lisp_true : nil;
    env = stack[-9];
    goto v_30213;
v_30215:
    v_30428 = nil;
    goto v_30213;
    v_30428 = nil;
v_30213:
    if (v_30428 == nil) goto v_30211;
    v_30428 = elt(env, 3); // false
    goto v_30048;
v_30211:
    goto v_30245;
v_30241:
    v_30429 = stack[-7];
    goto v_30242;
v_30243:
    v_30428 = elt(env, 2); // qepsilon
    goto v_30244;
v_30245:
    goto v_30241;
v_30242:
    goto v_30243;
v_30244:
    if (v_30429 == v_30428) goto v_30239;
    else goto v_30240;
v_30239:
    goto v_30256;
v_30252:
    v_30429 = stack[-3];
    goto v_30253;
v_30254:
    v_30428 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30255;
v_30256:
    goto v_30252;
v_30253:
    goto v_30254;
v_30255:
    if (v_30429 == v_30428) goto v_30250;
    else goto v_30251;
v_30250:
    goto v_30263;
v_30259:
    v_30429 = stack[-4];
    goto v_30260;
v_30261:
    v_30428 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30262;
v_30263:
    goto v_30259;
v_30260:
    goto v_30261;
v_30262:
    v_30428 = (v_30429 == v_30428 ? lisp_true : nil);
    goto v_30249;
v_30251:
    v_30428 = nil;
    goto v_30249;
    v_30428 = nil;
v_30249:
    goto v_30238;
v_30240:
    v_30428 = nil;
    goto v_30238;
    v_30428 = nil;
v_30238:
    if (v_30428 == nil) goto v_30236;
    goto v_30281;
v_30277:
    v_30429 = stack[-6];
    goto v_30278;
v_30279:
    v_30428 = elt(env, 2); // qepsilon
    goto v_30280;
v_30281:
    goto v_30277;
v_30278:
    goto v_30279;
v_30280:
    if (v_30429 == v_30428) goto v_30275;
    else goto v_30276;
v_30275:
    v_30428 = elt(env, 1); // true
    goto v_30048;
v_30276:
    v_30428 = stack[-8];
    fn = elt(env, 10); // qqe_simplterm
    v_30428 = (*qfn1(fn))(fn, v_30428);
    env = stack[-9];
    goto v_30274;
v_30274:
    goto v_30296;
v_30290:
    v_30429 = elt(env, 4); // qequal
    goto v_30291;
v_30292:
    v_30430 = v_30428;
    goto v_30293;
v_30294:
    v_30428 = stack[-7];
    goto v_30295;
v_30296:
    goto v_30290;
v_30291:
    goto v_30292;
v_30293:
    goto v_30294;
v_30295:
    {
        fn = elt(env, 11); // qqe_mk2
        return (*qfnn(fn))(fn, 3, v_30429, v_30430, v_30428);
    }
v_30236:
    goto v_30311;
v_30307:
    v_30429 = stack[-8];
    goto v_30308;
v_30309:
    v_30428 = elt(env, 2); // qepsilon
    goto v_30310;
v_30311:
    goto v_30307;
v_30308:
    goto v_30309;
v_30310:
    if (v_30429 == v_30428) goto v_30305;
    else goto v_30306;
v_30305:
    goto v_30322;
v_30318:
    v_30429 = stack[-3];
    goto v_30319;
v_30320:
    v_30428 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30321;
v_30322:
    goto v_30318;
v_30319:
    goto v_30320;
v_30321:
    if (v_30429 == v_30428) goto v_30316;
    else goto v_30317;
v_30316:
    goto v_30329;
v_30325:
    v_30429 = stack[-4];
    goto v_30326;
v_30327:
    v_30428 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30328;
v_30329:
    goto v_30325;
v_30326:
    goto v_30327;
v_30328:
    v_30428 = (v_30429 == v_30428 ? lisp_true : nil);
    goto v_30315;
v_30317:
    v_30428 = nil;
    goto v_30315;
    v_30428 = nil;
v_30315:
    goto v_30304;
v_30306:
    v_30428 = nil;
    goto v_30304;
    v_30428 = nil;
v_30304:
    if (v_30428 == nil) goto v_30302;
    goto v_30347;
v_30343:
    v_30429 = stack[-5];
    goto v_30344;
v_30345:
    v_30428 = elt(env, 2); // qepsilon
    goto v_30346;
v_30347:
    goto v_30343;
v_30344:
    goto v_30345;
v_30346:
    if (v_30429 == v_30428) goto v_30341;
    else goto v_30342;
v_30341:
    v_30428 = elt(env, 1); // true
    goto v_30048;
v_30342:
    v_30428 = stack[-7];
    fn = elt(env, 10); // qqe_simplterm
    v_30428 = (*qfn1(fn))(fn, v_30428);
    env = stack[-9];
    stack[0] = v_30428;
    goto v_30340;
v_30340:
    goto v_30362;
v_30356:
    v_30430 = elt(env, 4); // qequal
    goto v_30357;
v_30358:
    v_30429 = stack[-8];
    goto v_30359;
v_30360:
    v_30428 = stack[0];
    goto v_30361;
v_30362:
    goto v_30356;
v_30357:
    goto v_30358;
v_30359:
    goto v_30360;
v_30361:
    {
        fn = elt(env, 11); // qqe_mk2
        return (*qfnn(fn))(fn, 3, v_30430, v_30429, v_30428);
    }
v_30302:
    goto v_30070;
v_30072:
v_30070:
    v_30428 = stack[-7];
    fn = elt(env, 10); // qqe_simplterm
    v_30428 = (*qfn1(fn))(fn, v_30428);
    env = stack[-9];
    stack[0] = v_30428;
    v_30428 = stack[-8];
    fn = elt(env, 10); // qqe_simplterm
    v_30428 = (*qfn1(fn))(fn, v_30428);
    env = stack[-9];
    goto v_30383;
v_30379:
    v_30430 = stack[-7];
    goto v_30380;
v_30381:
    v_30429 = stack[0];
    goto v_30382;
v_30383:
    goto v_30379;
v_30380:
    goto v_30381;
v_30382:
    if (equal(v_30430, v_30429)) goto v_30377;
    else goto v_30378;
v_30377:
    goto v_30390;
v_30386:
    v_30430 = stack[-8];
    goto v_30387;
v_30388:
    v_30429 = v_30428;
    goto v_30389;
v_30390:
    goto v_30386;
v_30387:
    goto v_30388;
v_30389:
    v_30429 = (equal(v_30430, v_30429) ? lisp_true : nil);
    goto v_30376;
v_30378:
    v_30429 = nil;
    goto v_30376;
    v_30429 = nil;
v_30376:
    if (v_30429 == nil) goto v_30374;
    goto v_30404;
v_30398:
    v_30430 = elt(env, 4); // qequal
    goto v_30399;
v_30400:
    v_30429 = v_30428;
    goto v_30401;
v_30402:
    v_30428 = stack[0];
    goto v_30403;
v_30404:
    goto v_30398;
v_30399:
    goto v_30400;
v_30401:
    goto v_30402;
v_30403:
    {
        fn = elt(env, 11); // qqe_mk2
        return (*qfnn(fn))(fn, 3, v_30430, v_30429, v_30428);
    }
v_30374:
    goto v_30415;
v_30411:
    goto v_30423;
v_30417:
    v_30430 = elt(env, 4); // qequal
    goto v_30418;
v_30419:
    v_30429 = v_30428;
    goto v_30420;
v_30421:
    v_30428 = stack[0];
    goto v_30422;
v_30423:
    goto v_30417;
v_30418:
    goto v_30419;
v_30420:
    goto v_30421;
v_30422:
    fn = elt(env, 11); // qqe_mk2
    v_30428 = (*qfnn(fn))(fn, 3, v_30430, v_30429, v_30428);
    env = stack[-9];
    goto v_30412;
v_30413:
    goto v_30414;
v_30415:
    goto v_30411;
v_30412:
    goto v_30413;
v_30414:
    stack[0] = v_30428;
    goto v_30033;
    v_30428 = nil;
v_30048:
    return onevalue(v_30428);
}



// Code for vdpfmon

static LispObject CC_vdpfmon(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30081;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30034,v_30035);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_30035;
    v_30081 = v_30034;
// end of prologue
    goto v_30049;
v_30041:
    stack[-5] = elt(env, 1); // vdp
    goto v_30042;
v_30043:
    stack[-3] = stack[-4];
    goto v_30044;
v_30045:
    stack[-2] = v_30081;
    goto v_30046;
v_30047:
    goto v_30060;
v_30054:
    stack[-1] = stack[-4];
    goto v_30055;
v_30056:
    stack[0] = ncons(v_30081);
    env = stack[-6];
    goto v_30057;
v_30058:
    v_30081 = nil;
    v_30081 = ncons(v_30081);
    env = stack[-6];
    goto v_30059;
v_30060:
    goto v_30054;
v_30055:
    goto v_30056;
v_30057:
    goto v_30058;
v_30059:
    v_30081 = acons(stack[-1], stack[0], v_30081);
    env = stack[-6];
    goto v_30048;
v_30049:
    goto v_30041;
v_30042:
    goto v_30043;
v_30044:
    goto v_30045;
v_30046:
    goto v_30047;
v_30048:
    v_30081 = list3star(stack[-5], stack[-3], stack[-2], v_30081);
    env = stack[-6];
    stack[-1] = v_30081;
    v_30081 = qvalue(elt(env, 2)); // !*gsugar
    if (v_30081 == nil) goto v_30069;
    goto v_30076;
v_30072:
    stack[0] = stack[-1];
    goto v_30073;
v_30074:
    v_30081 = stack[-4];
    fn = elt(env, 3); // vevtdeg
    v_30081 = (*qfn1(fn))(fn, v_30081);
    env = stack[-6];
    goto v_30075;
v_30076:
    goto v_30072;
v_30073:
    goto v_30074;
v_30075:
    fn = elt(env, 4); // gsetsugar
    v_30081 = (*qfn2(fn))(fn, stack[0], v_30081);
    goto v_30067;
v_30069:
v_30067:
    v_30081 = stack[-1];
    return onevalue(v_30081);
}



// Code for xexptpf

static LispObject CC_xexptpf(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30083, v_30084;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30034,v_30035);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30035;
    stack[-1] = v_30034;
// end of prologue
    stack[-2] = nil;
v_30041:
    goto v_30052;
v_30048:
    v_30084 = stack[0];
    goto v_30049;
v_30050:
    v_30083 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30051;
v_30052:
    goto v_30048;
v_30049:
    goto v_30050;
v_30051:
    if (v_30084 == v_30083) goto v_30046;
    else goto v_30047;
v_30046:
    goto v_30042;
v_30047:
    goto v_30060;
v_30056:
    v_30084 = stack[-1];
    goto v_30057;
v_30058:
    v_30083 = stack[-2];
    goto v_30059;
v_30060:
    goto v_30056;
v_30057:
    goto v_30058;
v_30059:
    v_30083 = cons(v_30084, v_30083);
    env = stack[-3];
    stack[-2] = v_30083;
    v_30083 = stack[0];
    v_30083 = sub1(v_30083);
    env = stack[-3];
    stack[0] = v_30083;
    goto v_30041;
v_30042:
    v_30083 = stack[-1];
    v_30084 = v_30083;
v_30043:
    v_30083 = stack[-2];
    if (v_30083 == nil) goto v_30068;
    else goto v_30069;
v_30068:
    v_30083 = v_30084;
    goto v_30040;
v_30069:
    goto v_30077;
v_30073:
    v_30083 = stack[-2];
    v_30083 = qcar(v_30083);
    goto v_30074;
v_30075:
    goto v_30076;
v_30077:
    goto v_30073;
v_30074:
    goto v_30075;
v_30076:
    fn = elt(env, 1); // wedgepf
    v_30083 = (*qfn2(fn))(fn, v_30083, v_30084);
    env = stack[-3];
    v_30084 = v_30083;
    v_30083 = stack[-2];
    v_30083 = qcdr(v_30083);
    stack[-2] = v_30083;
    goto v_30043;
v_30040:
    return onevalue(v_30083);
}



// Code for mk!-contract!-coeff

static LispObject CC_mkKcontractKcoeff(LispObject env,
                         LispObject v_30034)
{
    env = qenv(env);
    LispObject v_30095, v_30096;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30034);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_30034;
// end of prologue
    goto v_30044;
v_30040:
    v_30095 = stack[0];
    v_30095 = qcar(v_30095);
    v_30096 = qcar(v_30095);
    goto v_30041;
v_30042:
    v_30095 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30043;
v_30044:
    goto v_30040;
v_30041:
    goto v_30042;
v_30043:
    if (v_30096 == v_30095) goto v_30038;
    else goto v_30039;
v_30038:
    v_30095 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30037;
v_30039:
    v_30095 = stack[0];
    v_30095 = qcar(v_30095);
    v_30095 = qcar(v_30095);
    stack[-3] = v_30095;
    v_30095 = stack[0];
    v_30095 = qcdr(v_30095);
    v_30095 = qcar(v_30095);
    v_30095 = Llength(nil, v_30095);
    env = stack[-4];
    v_30096 = v_30095;
    goto v_30071;
v_30067:
    v_30095 = stack[0];
    v_30095 = qcar(v_30095);
    v_30095 = qcdr(v_30095);
    stack[-2] = qcar(v_30095);
    goto v_30068;
v_30069:
    goto v_30083;
v_30077:
    stack[-1] = qvalue(elt(env, 1)); // ndim!*
    goto v_30078;
v_30079:
    stack[0] = v_30096;
    goto v_30080;
v_30081:
    goto v_30091;
v_30087:
    goto v_30088;
v_30089:
    v_30095 = stack[-3];
    goto v_30090;
v_30091:
    goto v_30087;
v_30088:
    goto v_30089;
v_30090:
    v_30095 = plus2(v_30096, v_30095);
    env = stack[-4];
    goto v_30082;
v_30083:
    goto v_30077;
v_30078:
    goto v_30079;
v_30080:
    goto v_30081;
v_30082:
    fn = elt(env, 2); // mk!-numr
    v_30095 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_30095);
    env = stack[-4];
    goto v_30070;
v_30071:
    goto v_30067;
v_30068:
    goto v_30069;
v_30070:
    v_30095 = cons(stack[-2], v_30095);
    env = stack[-4];
    {
        fn = elt(env, 3); // constimes
        return (*qfn1(fn))(fn, v_30095);
    }
    goto v_30037;
    v_30095 = nil;
v_30037:
    return onevalue(v_30095);
}



// Code for rule!-list

static LispObject CC_ruleKlist(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30234, v_30235, v_30236, v_30237, v_30238;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30034,v_30035);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_30035;
    stack[-2] = v_30034;
// end of prologue
v_30043:
    v_30234 = nil;
    qvalue(elt(env, 1)) = v_30234; // frasc!*
    v_30234 = stack[-2];
    if (v_30234 == nil) goto v_30051;
    else goto v_30052;
v_30051:
    v_30234 = lisp_true;
    goto v_30050;
v_30052:
    goto v_30061;
v_30057:
    stack[0] = stack[-2];
    goto v_30058;
v_30059:
    v_30234 = nil;
    v_30234 = ncons(v_30234);
    env = stack[-4];
    goto v_30060;
v_30061:
    goto v_30057;
v_30058:
    goto v_30059;
v_30060:
    v_30234 = (equal(stack[0], v_30234) ? lisp_true : nil);
    goto v_30050;
    v_30234 = nil;
v_30050:
    if (v_30234 == nil) goto v_30048;
    v_30234 = nil;
    qvalue(elt(env, 2)) = v_30234; // mcond!*
    goto v_30042;
v_30048:
    v_30234 = lisp_true;
    qvalue(elt(env, 2)) = v_30234; // mcond!*
    v_30234 = stack[-2];
    v_30234 = qcar(v_30234);
    stack[-3] = v_30234;
    v_30234 = stack[-3];
    if (symbolp(v_30234)) goto v_30072;
    else goto v_30073;
v_30072:
    v_30234 = stack[-3];
    if (!symbolp(v_30234)) v_30234 = nil;
    else { v_30234 = qfastgets(v_30234);
           if (v_30234 != nil) { v_30234 = elt(v_30234, 4); // avalue
#ifdef RECORD_GET
             if (v_30234 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_30234 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_30234 == SPID_NOPROP) v_30234 = nil; }}
#endif
    v_30236 = v_30234;
    if (v_30234 == nil) goto v_30078;
    goto v_30087;
v_30083:
    v_30234 = v_30236;
    v_30235 = qcar(v_30234);
    goto v_30084;
v_30085:
    v_30234 = elt(env, 3); // list
    goto v_30086;
v_30087:
    goto v_30083;
v_30084:
    goto v_30085;
v_30086:
    if (v_30235 == v_30234) goto v_30082;
    else goto v_30078;
v_30082:
    goto v_30096;
v_30092:
    v_30234 = v_30236;
    v_30234 = qcdr(v_30234);
    v_30234 = qcar(v_30234);
    v_30234 = qcdr(v_30234);
    v_30235 = Lreverse(nil, v_30234);
    env = stack[-4];
    goto v_30093;
v_30094:
    v_30234 = stack[-2];
    v_30234 = qcdr(v_30234);
    goto v_30095;
v_30096:
    goto v_30092;
v_30093:
    goto v_30094;
v_30095:
    v_30234 = Lappend(nil, v_30235, v_30234);
    env = stack[-4];
    stack[-2] = v_30234;
    goto v_30043;
v_30078:
    goto v_30111;
v_30107:
    v_30235 = stack[-3];
    goto v_30108;
v_30109:
    v_30234 = elt(env, 4); // "rule list"
    goto v_30110;
v_30111:
    goto v_30107;
v_30108:
    goto v_30109;
v_30110:
    fn = elt(env, 11); // typerr
    v_30234 = (*qfn2(fn))(fn, v_30235, v_30234);
    env = stack[-4];
    goto v_30076;
v_30076:
    goto v_30071;
v_30073:
    goto v_30120;
v_30116:
    v_30234 = stack[-3];
    v_30235 = qcar(v_30234);
    goto v_30117;
v_30118:
    v_30234 = elt(env, 3); // list
    goto v_30119;
v_30120:
    goto v_30116;
v_30117:
    goto v_30118;
v_30119:
    if (v_30235 == v_30234) goto v_30114;
    else goto v_30115;
v_30114:
    goto v_30129;
v_30125:
    v_30234 = stack[-3];
    v_30235 = qcdr(v_30234);
    goto v_30126;
v_30127:
    v_30234 = stack[-2];
    v_30234 = qcdr(v_30234);
    goto v_30128;
v_30129:
    goto v_30125;
v_30126:
    goto v_30127;
v_30128:
    v_30234 = Lappend(nil, v_30235, v_30234);
    env = stack[-4];
    stack[-2] = v_30234;
    goto v_30043;
v_30115:
    goto v_30140;
v_30136:
    v_30234 = stack[-3];
    v_30235 = qcar(v_30234);
    goto v_30137;
v_30138:
    v_30234 = elt(env, 5); // equal
    goto v_30139;
v_30140:
    goto v_30136;
v_30137:
    goto v_30138;
v_30139:
    if (v_30235 == v_30234) goto v_30134;
    else goto v_30135;
v_30134:
    v_30234 = elt(env, 6); // "Please use => instead of = in rules"
    fn = elt(env, 12); // lprim
    v_30234 = (*qfn1(fn))(fn, v_30234);
    env = stack[-4];
    goto v_30071;
v_30135:
    goto v_30152;
v_30148:
    v_30234 = stack[-3];
    v_30235 = qcar(v_30234);
    goto v_30149;
v_30150:
    v_30234 = elt(env, 7); // replaceby
    goto v_30151;
v_30152:
    goto v_30148;
v_30149:
    goto v_30150;
v_30151:
    if (v_30235 == v_30234) goto v_30147;
    goto v_30161;
v_30157:
    v_30235 = stack[-3];
    goto v_30158;
v_30159:
    v_30234 = elt(env, 8); // "rule"
    goto v_30160;
v_30161:
    goto v_30157;
v_30158:
    goto v_30159;
v_30160:
    fn = elt(env, 11); // typerr
    v_30234 = (*qfn2(fn))(fn, v_30235, v_30234);
    env = stack[-4];
    goto v_30071;
v_30147:
v_30071:
    v_30234 = stack[-3];
    v_30234 = qcdr(v_30234);
    v_30234 = qcar(v_30234);
    fn = elt(env, 13); // remove!-free!-vars
    v_30234 = (*qfn1(fn))(fn, v_30234);
    env = stack[-4];
    stack[0] = v_30234;
    goto v_30177;
v_30173:
    v_30234 = stack[-3];
    v_30234 = qcdr(v_30234);
    v_30234 = qcdr(v_30234);
    v_30235 = qcar(v_30234);
    goto v_30174;
v_30175:
    v_30234 = elt(env, 9); // when
    goto v_30176;
v_30177:
    goto v_30173;
v_30174:
    goto v_30175;
v_30176:
    if (!consp(v_30235)) goto v_30171;
    v_30235 = qcar(v_30235);
    if (v_30235 == v_30234) goto v_30170;
    else goto v_30171;
v_30170:
    goto v_30190;
v_30184:
    v_30234 = stack[-3];
    v_30234 = qcdr(v_30234);
    v_30234 = qcdr(v_30234);
    v_30234 = qcar(v_30234);
    v_30234 = qcdr(v_30234);
    v_30234 = qcdr(v_30234);
    v_30234 = qcar(v_30234);
    fn = elt(env, 14); // remove!-free!-vars!*
    v_30236 = (*qfn1(fn))(fn, v_30234);
    env = stack[-4];
    goto v_30185;
v_30186:
    v_30235 = nil;
    goto v_30187;
v_30188:
    v_30234 = elt(env, 10); // algebraic
    goto v_30189;
v_30190:
    goto v_30184;
v_30185:
    goto v_30186;
v_30187:
    goto v_30188;
v_30189:
    fn = elt(env, 15); // formbool
    v_30234 = (*qfnn(fn))(fn, 3, v_30236, v_30235, v_30234);
    env = stack[-4];
    qvalue(elt(env, 2)) = v_30234; // mcond!*
    v_30234 = stack[-3];
    v_30234 = qcdr(v_30234);
    v_30234 = qcdr(v_30234);
    v_30234 = qcar(v_30234);
    v_30234 = qcdr(v_30234);
    v_30234 = qcar(v_30234);
    fn = elt(env, 14); // remove!-free!-vars!*
    v_30234 = (*qfn1(fn))(fn, v_30234);
    env = stack[-4];
    goto v_30169;
v_30171:
    v_30234 = stack[-3];
    v_30234 = qcdr(v_30234);
    v_30234 = qcdr(v_30234);
    v_30234 = qcar(v_30234);
    fn = elt(env, 14); // remove!-free!-vars!*
    v_30234 = (*qfn1(fn))(fn, v_30234);
    env = stack[-4];
    goto v_30169;
v_30169:
    goto v_30226;
v_30216:
    v_30238 = stack[0];
    goto v_30217;
v_30218:
    v_30237 = v_30234;
    goto v_30219;
v_30220:
    v_30236 = qvalue(elt(env, 1)); // frasc!*
    goto v_30221;
v_30222:
    v_30235 = qvalue(elt(env, 2)); // mcond!*
    goto v_30223;
v_30224:
    v_30234 = stack[-1];
    goto v_30225;
v_30226:
    goto v_30216;
v_30217:
    goto v_30218;
v_30219:
    goto v_30220;
v_30221:
    goto v_30222;
v_30223:
    goto v_30224;
v_30225:
    fn = elt(env, 16); // rule!*
    v_30234 = (*qfnn(fn))(fn, 5, v_30238, v_30237, v_30236, v_30235, v_30234);
    env = stack[-4];
    v_30234 = stack[-2];
    v_30234 = qcdr(v_30234);
    stack[-2] = v_30234;
    goto v_30043;
v_30042:
    return onevalue(v_30234);
}



// Code for hdiff

static LispObject CC_hdiff(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30074, v_30075;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30034,v_30035);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30035;
    stack[-1] = v_30034;
// end of prologue
    v_30074 = stack[-1];
    if (v_30074 == nil) goto v_30039;
    else goto v_30040;
v_30039:
    v_30074 = nil;
    goto v_30038;
v_30040:
    goto v_30050;
v_30046:
    goto v_30056;
v_30052:
    goto v_30061;
v_30057:
    v_30075 = stack[-1];
    goto v_30058;
v_30059:
    v_30074 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_30060;
v_30061:
    goto v_30057;
v_30058:
    goto v_30059;
v_30060:
    v_30075 = *(LispObject *)((char *)v_30075 + (CELL-TAG_VECTOR) + (((intptr_t)v_30074-TAG_FIXNUM)/(16/CELL)));
    goto v_30053;
v_30054:
    v_30074 = stack[0];
    goto v_30055;
v_30056:
    goto v_30052;
v_30053:
    goto v_30054;
v_30055:
    stack[-2] = CC_hdiff(elt(env, 0), v_30075, v_30074);
    env = stack[-3];
    goto v_30047;
v_30048:
    goto v_30071;
v_30067:
    v_30075 = stack[-1];
    goto v_30068;
v_30069:
    v_30074 = stack[0];
    goto v_30070;
v_30071:
    goto v_30067;
v_30068:
    goto v_30069;
v_30070:
    fn = elt(env, 1); // hdiffterm
    v_30074 = (*qfn2(fn))(fn, v_30075, v_30074);
    env = stack[-3];
    goto v_30049;
v_30050:
    goto v_30046;
v_30047:
    goto v_30048;
v_30049:
    {
        LispObject v_30079 = stack[-2];
        fn = elt(env, 2); // fs!:plus
        return (*qfn2(fn))(fn, v_30079, v_30074);
    }
    v_30074 = nil;
v_30038:
    return onevalue(v_30074);
}



// Code for test!-bool

static LispObject CC_testKbool(LispObject env,
                         LispObject v_30034)
{
    env = qenv(env);
    LispObject v_30042;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30034);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30042 = v_30034;
// end of prologue
    v_30042 = qcar(v_30042);
    fn = elt(env, 1); // boolean!-eval1
    v_30042 = (*qfn1(fn))(fn, v_30042);
    env = stack[0];
    v_30042 = ncons(v_30042);
    env = stack[0];
    fn = elt(env, 2); // simp!-prop
    v_30042 = (*qfn1(fn))(fn, v_30042);
    env = stack[0];
    {
        fn = elt(env, 3); // mk!*sq
        return (*qfn1(fn))(fn, v_30042);
    }
}



// Code for combin

static LispObject CC_combin(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30133, v_30134;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30034,v_30035);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_30035;
    stack[-3] = v_30034;
// end of prologue
    goto v_30046;
v_30042:
    v_30134 = stack[-3];
    goto v_30043;
v_30044:
    v_30133 = stack[-2];
    goto v_30045;
v_30046:
    goto v_30042;
v_30043:
    goto v_30044;
v_30045:
    v_30133 = (LispObject)greaterp2(v_30134, v_30133);
    v_30133 = v_30133 ? lisp_true : nil;
    env = stack[-5];
    if (v_30133 == nil) goto v_30040;
    v_30133 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30038;
v_30040:
    v_30133 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_30133;
    stack[-4] = v_30133;
    goto v_30069;
v_30065:
    v_30134 = stack[-2];
    goto v_30066;
v_30067:
    v_30133 = stack[-3];
    goto v_30068;
v_30069:
    goto v_30065;
v_30066:
    goto v_30067;
v_30068:
    v_30133 = difference2(v_30134, v_30133);
    env = stack[-5];
    v_30133 = add1(v_30133);
    env = stack[-5];
    stack[0] = v_30133;
v_30062:
    goto v_30082;
v_30078:
    v_30134 = stack[-2];
    goto v_30079;
v_30080:
    v_30133 = stack[0];
    goto v_30081;
v_30082:
    goto v_30078;
v_30079:
    goto v_30080;
v_30081:
    v_30133 = difference2(v_30134, v_30133);
    env = stack[-5];
    v_30133 = Lminusp(nil, v_30133);
    env = stack[-5];
    if (v_30133 == nil) goto v_30075;
    goto v_30061;
v_30075:
    goto v_30091;
v_30087:
    v_30134 = stack[-4];
    goto v_30088;
v_30089:
    v_30133 = stack[0];
    goto v_30090;
v_30091:
    goto v_30087;
v_30088:
    goto v_30089;
v_30090:
    v_30133 = times2(v_30134, v_30133);
    env = stack[-5];
    stack[-4] = v_30133;
    v_30133 = stack[0];
    v_30133 = add1(v_30133);
    env = stack[-5];
    stack[0] = v_30133;
    goto v_30062;
v_30061:
    v_30133 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_30133;
v_30099:
    goto v_30111;
v_30107:
    v_30134 = stack[-3];
    goto v_30108;
v_30109:
    v_30133 = stack[0];
    goto v_30110;
v_30111:
    goto v_30107;
v_30108:
    goto v_30109;
v_30110:
    v_30133 = difference2(v_30134, v_30133);
    env = stack[-5];
    v_30133 = Lminusp(nil, v_30133);
    env = stack[-5];
    if (v_30133 == nil) goto v_30104;
    goto v_30098;
v_30104:
    goto v_30120;
v_30116:
    v_30134 = stack[-1];
    goto v_30117;
v_30118:
    v_30133 = stack[0];
    goto v_30119;
v_30120:
    goto v_30116;
v_30117:
    goto v_30118;
v_30119:
    v_30133 = times2(v_30134, v_30133);
    env = stack[-5];
    stack[-1] = v_30133;
    v_30133 = stack[0];
    v_30133 = add1(v_30133);
    env = stack[-5];
    stack[0] = v_30133;
    goto v_30099;
v_30098:
    goto v_30130;
v_30126:
    v_30134 = stack[-4];
    goto v_30127;
v_30128:
    v_30133 = stack[-1];
    goto v_30129;
v_30130:
    goto v_30126;
v_30127:
    goto v_30128;
v_30129:
    return quot2(v_30134, v_30133);
    goto v_30038;
    v_30133 = nil;
v_30038:
    return onevalue(v_30133);
}



// Code for alistp

static LispObject CC_alistp(LispObject env,
                         LispObject v_30034)
{
    env = qenv(env);
    LispObject v_30066, v_30067;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30034);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30066 = v_30034;
// end of prologue
v_30033:
    v_30067 = v_30066;
    if (v_30067 == nil) goto v_30038;
    else goto v_30039;
v_30038:
    v_30066 = lisp_true;
    goto v_30037;
v_30039:
    v_30067 = v_30066;
    v_30067 = Lconsp(nil, v_30067);
    env = stack[0];
    if (v_30067 == nil) goto v_30046;
    else goto v_30047;
v_30046:
    v_30066 = nil;
    goto v_30045;
v_30047:
    v_30067 = v_30066;
    v_30067 = qcar(v_30067);
    v_30067 = Lconsp(nil, v_30067);
    env = stack[0];
    if (v_30067 == nil) goto v_30055;
    else goto v_30056;
v_30055:
    v_30066 = nil;
    goto v_30054;
v_30056:
    v_30066 = qcdr(v_30066);
    goto v_30033;
    v_30066 = nil;
v_30054:
    goto v_30045;
    v_30066 = nil;
v_30045:
    goto v_30037;
    v_30066 = nil;
v_30037:
    return onevalue(v_30066);
}



// Code for coeffs!-to!-form1

static LispObject CC_coeffsKtoKform1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30096, v_30097, v_30098;
    LispObject fn;
    LispObject v_30036, v_30035, v_30034;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "coeffs-to-form1");
    va_start(aa, nargs);
    v_30034 = va_arg(aa, LispObject);
    v_30035 = va_arg(aa, LispObject);
    v_30036 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30036,v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30034,v_30035,v_30036);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_30036;
    stack[-2] = v_30035;
    stack[-3] = v_30034;
// end of prologue
    goto v_30047;
v_30043:
    v_30097 = stack[-1];
    goto v_30044;
v_30045:
    v_30096 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30046;
v_30047:
    goto v_30043;
v_30044:
    goto v_30045;
v_30046:
    v_30096 = (LispObject)greaterp2(v_30097, v_30096);
    v_30096 = v_30096 ? lisp_true : nil;
    env = stack[-5];
    if (v_30096 == nil) goto v_30041;
    goto v_30057;
v_30051:
    v_30096 = stack[-3];
    stack[-4] = qcdr(v_30096);
    goto v_30052;
v_30053:
    stack[0] = stack[-2];
    goto v_30054;
v_30055:
    v_30096 = stack[-1];
    v_30096 = sub1(v_30096);
    env = stack[-5];
    goto v_30056;
v_30057:
    goto v_30051;
v_30052:
    goto v_30053;
v_30054:
    goto v_30055;
v_30056:
    v_30096 = CC_coeffsKtoKform1(elt(env, 0), 3, stack[-4], stack[0], v_30096);
    env = stack[-5];
    stack[0] = v_30096;
    v_30096 = stack[-3];
    v_30096 = qcar(v_30096);
    if (v_30096 == nil) goto v_30067;
    goto v_30077;
v_30071:
    goto v_30083;
v_30079:
    v_30097 = stack[-2];
    goto v_30080;
v_30081:
    v_30096 = stack[-1];
    goto v_30082;
v_30083:
    goto v_30079;
v_30080:
    goto v_30081;
v_30082:
    fn = elt(env, 1); // to
    v_30098 = (*qfn2(fn))(fn, v_30097, v_30096);
    goto v_30072;
v_30073:
    v_30096 = stack[-3];
    v_30097 = qcar(v_30096);
    goto v_30074;
v_30075:
    v_30096 = stack[0];
    goto v_30076;
v_30077:
    goto v_30071;
v_30072:
    goto v_30073;
v_30074:
    goto v_30075;
v_30076:
    return acons(v_30098, v_30097, v_30096);
v_30067:
    v_30096 = stack[0];
    goto v_30065;
    v_30096 = nil;
v_30065:
    goto v_30039;
v_30041:
    v_30096 = stack[-3];
    v_30096 = qcar(v_30096);
    goto v_30039;
    v_30096 = nil;
v_30039:
    return onevalue(v_30096);
}



// Code for small!-random!-number

static LispObject CC_smallKrandomKnumber(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30122, v_30123;
    LispObject fn;
    argcheck(nargs, 0, "small-random-number");
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
    goto v_30043;
v_30039:
    fn = elt(env, 4); // next!-random!-number
    v_30123 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_30040;
v_30041:
    v_30122 = (LispObject)16000+TAG_FIXNUM; // 1000
    goto v_30042;
v_30043:
    goto v_30039;
v_30040:
    goto v_30041;
v_30042:
    v_30122 = Cremainder(v_30123, v_30122);
    env = stack[-3];
    stack[-2] = v_30122;
    goto v_30051;
v_30047:
    goto v_30057;
v_30053:
    fn = elt(env, 4); // next!-random!-number
    v_30123 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_30054;
v_30055:
    v_30122 = (LispObject)16000+TAG_FIXNUM; // 1000
    goto v_30056;
v_30057:
    goto v_30053;
v_30054:
    goto v_30055;
v_30056:
    stack[0] = Cremainder(v_30123, v_30122);
    env = stack[-3];
    goto v_30048;
v_30049:
    goto v_30065;
v_30061:
    v_30123 = (LispObject)16000+TAG_FIXNUM; // 1000
    goto v_30062;
v_30063:
    v_30122 = stack[-2];
    goto v_30064;
v_30065:
    goto v_30061;
v_30062:
    goto v_30063;
v_30064:
    v_30122 = times2(v_30123, v_30122);
    env = stack[-3];
    goto v_30050;
v_30051:
    goto v_30047;
v_30048:
    goto v_30049;
v_30050:
    v_30122 = plus2(stack[0], v_30122);
    env = stack[-3];
    stack[-2] = v_30122;
    goto v_30077;
v_30073:
    v_30123 = stack[-2];
    goto v_30074;
v_30075:
    v_30122 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30076;
v_30077:
    goto v_30073;
v_30074:
    goto v_30075;
v_30076:
    v_30122 = (LispObject)lessp2(v_30123, v_30122);
    v_30122 = v_30122 ? lisp_true : nil;
    env = stack[-3];
    if (v_30122 == nil) goto v_30071;
    goto v_30085;
v_30081:
    v_30123 = stack[-2];
    goto v_30082;
v_30083:
    v_30122 = (LispObject)16000000+TAG_FIXNUM; // 1000000
    goto v_30084;
v_30085:
    goto v_30081;
v_30082:
    goto v_30083;
v_30084:
    v_30122 = plus2(v_30123, v_30122);
    env = stack[-3];
    stack[-2] = v_30122;
    goto v_30069;
v_30071:
v_30069:
    goto v_30093;
v_30089:
    stack[-1] = elt(env, 1); // 1.0
    goto v_30090;
v_30091:
    goto v_30100;
v_30096:
    stack[0] = elt(env, 2); // 1.5
    goto v_30097;
v_30098:
    goto v_30107;
v_30103:
    v_30122 = stack[-2];
    v_30123 = Lfloat(nil, v_30122);
    env = stack[-3];
    goto v_30104;
v_30105:
    v_30122 = elt(env, 3); // 1.0e+06
    goto v_30106;
v_30107:
    goto v_30103;
v_30104:
    goto v_30105;
v_30106:
    v_30122 = quot2(v_30123, v_30122);
    env = stack[-3];
    goto v_30099;
v_30100:
    goto v_30096;
v_30097:
    goto v_30098;
v_30099:
    v_30122 = times2(stack[0], v_30122);
    env = stack[-3];
    goto v_30092;
v_30093:
    goto v_30089;
v_30090:
    goto v_30091;
v_30092:
    v_30122 = plus2(stack[-1], v_30122);
    env = stack[-3];
    stack[-2] = v_30122;
    goto v_30116;
v_30112:
    v_30123 = stack[-2];
    goto v_30113;
v_30114:
    v_30122 = stack[-2];
    goto v_30115;
v_30116:
    goto v_30112;
v_30113:
    goto v_30114;
v_30115:
    v_30122 = times2(v_30123, v_30122);
    env = stack[-3];
    stack[-2] = v_30122;
    v_30122 = stack[-2];
    fn = elt(env, 5); // exp
    v_30122 = (*qfn1(fn))(fn, v_30122);
        return Ltruncate(nil, v_30122);
    return onevalue(v_30122);
}



// Code for quotf!*

static LispObject CC_quotfH(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30100, v_30101, v_30102;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30034,v_30035);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30035;
    stack[-1] = v_30034;
// end of prologue
    v_30100 = stack[-1];
    if (v_30100 == nil) goto v_30039;
    else goto v_30040;
v_30039:
    v_30100 = nil;
    goto v_30038;
v_30040:
    goto v_30050;
v_30046:
    v_30101 = stack[-1];
    goto v_30047;
v_30048:
    v_30100 = stack[0];
    goto v_30049;
v_30050:
    goto v_30046;
v_30047:
    goto v_30048;
v_30049:
    fn = elt(env, 2); // quotf
    v_30100 = (*qfn2(fn))(fn, v_30101, v_30100);
    env = stack[-2];
    v_30101 = v_30100;
    v_30100 = v_30101;
    if (v_30100 == nil) goto v_30057;
    v_30100 = v_30101;
    goto v_30055;
v_30057:
    goto v_30068;
v_30064:
    v_30101 = stack[-1];
    goto v_30065;
v_30066:
    v_30100 = stack[0];
    goto v_30067;
v_30068:
    goto v_30064;
v_30065:
    goto v_30066;
v_30067:
    v_30100 = cons(v_30101, v_30100);
    env = stack[-2];
    fn = elt(env, 3); // rationalizesq
    v_30100 = (*qfn1(fn))(fn, v_30100);
    env = stack[-2];
    v_30102 = v_30100;
    goto v_30080;
v_30076:
    v_30100 = v_30102;
    v_30101 = qcdr(v_30100);
    goto v_30077;
v_30078:
    v_30100 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30079;
v_30080:
    goto v_30076;
v_30077:
    goto v_30078;
v_30079:
    if (v_30101 == v_30100) goto v_30074;
    else goto v_30075;
v_30074:
    v_30100 = v_30102;
    v_30100 = qcar(v_30100);
    goto v_30073;
v_30075:
    goto v_30096;
v_30090:
    v_30102 = elt(env, 1); // "DIVISION FAILED"
    goto v_30091;
v_30092:
    v_30101 = stack[-1];
    goto v_30093;
v_30094:
    v_30100 = stack[0];
    goto v_30095;
v_30096:
    goto v_30090;
v_30091:
    goto v_30092;
v_30093:
    goto v_30094;
v_30095:
    v_30100 = list3(v_30102, v_30101, v_30100);
    env = stack[-2];
    {
        fn = elt(env, 4); // errach
        return (*qfn1(fn))(fn, v_30100);
    }
    v_30100 = nil;
v_30073:
    goto v_30055;
    v_30100 = nil;
v_30055:
    goto v_30038;
    v_30100 = nil;
v_30038:
    return onevalue(v_30100);
}



// Code for vsl_boundtype1

static LispObject CC_vsl_boundtype1(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30084, v_30085, v_30086, v_30087;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30034,v_30035);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30087 = v_30035;
    v_30086 = v_30034;
// end of prologue
v_30039:
    v_30084 = v_30086;
    if (!consp(v_30084)) goto v_30046;
    else goto v_30047;
v_30046:
    v_30084 = lisp_true;
    goto v_30045;
v_30047:
    v_30084 = v_30086;
    v_30084 = qcar(v_30084);
    v_30084 = (consp(v_30084) ? nil : lisp_true);
    goto v_30045;
    v_30084 = nil;
v_30045:
    if (v_30084 == nil) goto v_30043;
    v_30084 = nil;
    goto v_30038;
v_30043:
    goto v_30062;
v_30058:
    v_30084 = v_30086;
    v_30084 = qcar(v_30084);
    v_30084 = qcar(v_30084);
    v_30085 = qcar(v_30084);
    goto v_30059;
v_30060:
    v_30084 = v_30087;
    goto v_30061;
v_30062:
    goto v_30058;
v_30059:
    goto v_30060;
v_30061:
    if (v_30085 == v_30084) goto v_30056;
    else goto v_30057;
v_30056:
    v_30084 = v_30086;
    v_30084 = qcar(v_30084);
    v_30084 = qcdr(v_30084);
    fn = elt(env, 3); // minusf
    v_30084 = (*qfn1(fn))(fn, v_30084);
    env = stack[0];
    if (v_30084 == nil) goto v_30071;
    v_30084 = elt(env, 1); // ub
    goto v_30038;
v_30071:
    v_30084 = elt(env, 2); // lb
    goto v_30038;
    goto v_30041;
v_30057:
    v_30084 = v_30086;
    v_30084 = qcdr(v_30084);
    v_30086 = v_30084;
    goto v_30039;
v_30041:
    v_30084 = nil;
v_30038:
    return onevalue(v_30084);
}



// Code for ps!:value

static LispObject CC_psTvalue(LispObject env,
                         LispObject v_30034)
{
    env = qenv(env);
    LispObject v_30085, v_30086, v_30087;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30087 = v_30034;
// end of prologue
    v_30085 = v_30087;
    if (!consp(v_30085)) goto v_30042;
    else goto v_30043;
v_30042:
    v_30085 = lisp_true;
    goto v_30041;
v_30043:
    goto v_30056;
v_30052:
    v_30085 = v_30087;
    v_30086 = qcar(v_30085);
    goto v_30053;
v_30054:
    v_30085 = elt(env, 1); // !:ps!:
    goto v_30055;
v_30056:
    goto v_30052;
v_30053:
    goto v_30054;
v_30055:
    if (v_30086 == v_30085) goto v_30051;
    v_30085 = v_30087;
    v_30085 = qcar(v_30085);
    if (!symbolp(v_30085)) v_30085 = nil;
    else { v_30085 = qfastgets(v_30085);
           if (v_30085 != nil) { v_30085 = elt(v_30085, 8); // dname
#ifdef RECORD_GET
             if (v_30085 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_30085 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_30085 == SPID_NOPROP) v_30085 = nil; }}
#endif
    goto v_30049;
v_30051:
    v_30085 = nil;
    goto v_30049;
    v_30085 = nil;
v_30049:
    goto v_30041;
    v_30085 = nil;
v_30041:
    if (v_30085 == nil) goto v_30039;
    v_30085 = v_30087;
    if (v_30085 == nil) goto v_30069;
    v_30085 = v_30087;
    goto v_30067;
v_30069:
    v_30085 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30067;
    v_30085 = nil;
v_30067:
    goto v_30037;
v_30039:
    goto v_30082;
v_30078:
    v_30086 = v_30087;
    goto v_30079;
v_30080:
    v_30085 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_30081;
v_30082:
    goto v_30078;
v_30079:
    goto v_30080;
v_30081:
    {
        fn = elt(env, 2); // ps!:getv
        return (*qfn2(fn))(fn, v_30086, v_30085);
    }
    v_30085 = nil;
v_30037:
    return onevalue(v_30085);
}



// Code for ldf!-spf!-var

static LispObject CC_ldfKspfKvar(LispObject env,
                         LispObject v_30034)
{
    env = qenv(env);
    LispObject v_30141, v_30142;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30034);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_30141 = v_30034;
// end of prologue
    v_30142 = nil;
    stack[-3] = nil;
    stack[-1] = v_30141;
v_30043:
    v_30141 = stack[-1];
    if (v_30141 == nil) goto v_30047;
    else goto v_30048;
v_30047:
    goto v_30042;
v_30048:
    v_30141 = stack[-1];
    v_30141 = qcar(v_30141);
    goto v_30059;
v_30055:
    stack[0] = v_30142;
    goto v_30056;
v_30057:
    v_30141 = qcdr(v_30141);
    fn = elt(env, 3); // kernels
    v_30141 = (*qfn1(fn))(fn, v_30141);
    env = stack[-4];
    goto v_30058;
v_30059:
    goto v_30055;
v_30056:
    goto v_30057;
v_30058:
    v_30141 = Lappend(nil, stack[0], v_30141);
    env = stack[-4];
    v_30142 = v_30141;
    v_30141 = stack[-1];
    v_30141 = qcdr(v_30141);
    stack[-1] = v_30141;
    goto v_30043;
v_30042:
    v_30141 = v_30142;
    fn = elt(env, 4); // makeset
    v_30141 = (*qfn1(fn))(fn, v_30141);
    env = stack[-4];
    fn = elt(env, 5); // prlist
    v_30141 = (*qfn1(fn))(fn, v_30141);
    env = stack[-4];
    stack[-2] = v_30141;
v_30069:
    v_30141 = stack[-2];
    if (v_30141 == nil) goto v_30075;
    else goto v_30076;
v_30075:
    goto v_30068;
v_30076:
    v_30141 = stack[-2];
    v_30141 = qcar(v_30141);
    stack[-1] = v_30141;
    goto v_30095;
v_30091:
    v_30142 = stack[-1];
    goto v_30092;
v_30093:
    v_30141 = elt(env, 1); // x
    goto v_30094;
v_30095:
    goto v_30091;
v_30092:
    goto v_30093;
v_30094:
    if (!consp(v_30142)) goto v_30088;
    v_30142 = qcar(v_30142);
    if (v_30142 == v_30141) goto v_30089;
v_30088:
    goto v_30103;
v_30099:
    v_30142 = stack[-1];
    goto v_30100;
v_30101:
    v_30141 = elt(env, 2); // u
    goto v_30102;
v_30103:
    goto v_30099;
v_30100:
    goto v_30101;
v_30102:
    v_30141 = Leqcar(nil, v_30142, v_30141);
    env = stack[-4];
    v_30141 = (v_30141 == nil ? lisp_true : nil);
    goto v_30087;
v_30089:
    v_30141 = nil;
    goto v_30087;
    v_30141 = nil;
v_30087:
    if (v_30141 == nil) goto v_30085;
    goto v_30117;
v_30111:
    goto v_30123;
v_30119:
    v_30142 = elt(env, 1); // x
    goto v_30120;
v_30121:
    v_30141 = stack[-1];
    v_30141 = qcdr(v_30141);
    goto v_30122;
v_30123:
    goto v_30119;
v_30120:
    goto v_30121;
v_30122:
    fn = elt(env, 6); // sacar
    stack[0] = (*qfn2(fn))(fn, v_30142, v_30141);
    env = stack[-4];
    goto v_30112;
v_30113:
    goto v_30132;
v_30128:
    v_30142 = elt(env, 2); // u
    goto v_30129;
v_30130:
    v_30141 = stack[-1];
    v_30141 = qcdr(v_30141);
    goto v_30131;
v_30132:
    goto v_30128;
v_30129:
    goto v_30130;
v_30131:
    fn = elt(env, 6); // sacar
    v_30142 = (*qfn2(fn))(fn, v_30142, v_30141);
    env = stack[-4];
    goto v_30114;
v_30115:
    v_30141 = stack[-3];
    goto v_30116;
v_30117:
    goto v_30111;
v_30112:
    goto v_30113;
v_30114:
    goto v_30115;
v_30116:
    fn = elt(env, 7); // appends
    v_30141 = (*qfnn(fn))(fn, 3, stack[0], v_30142, v_30141);
    env = stack[-4];
    stack[-3] = v_30141;
    goto v_30083;
v_30085:
v_30083:
    v_30141 = stack[-2];
    v_30141 = qcdr(v_30141);
    stack[-2] = v_30141;
    goto v_30069;
v_30068:
    v_30141 = stack[-3];
    {
        fn = elt(env, 4); // makeset
        return (*qfn1(fn))(fn, v_30141);
    }
    return onevalue(v_30141);
}



// Code for al1_defined_vertex

static LispObject CC_al1_defined_vertex(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30118, v_30119;
    LispObject fn;
    LispObject v_30037, v_30036, v_30035, v_30034;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "al1_defined_vertex");
    va_start(aa, nargs);
    v_30034 = va_arg(aa, LispObject);
    v_30035 = va_arg(aa, LispObject);
    v_30036 = va_arg(aa, LispObject);
    v_30037 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_30037,v_30036,v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_30034,v_30035,v_30036,v_30037);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_30037;
    stack[-1] = v_30036;
    stack[-2] = v_30035;
    stack[-3] = v_30034;
// end of prologue
v_30042:
    v_30118 = stack[-3];
    if (v_30118 == nil) goto v_30045;
    else goto v_30046;
v_30045:
    v_30118 = stack[-2];
    if (v_30118 == nil) goto v_30050;
    else goto v_30051;
v_30050:
    v_30118 = lisp_true;
    goto v_30041;
v_30051:
    goto v_30061;
v_30057:
    v_30119 = stack[-2];
    goto v_30058;
v_30059:
    v_30118 = stack[-1];
    goto v_30060;
v_30061:
    goto v_30057;
v_30058:
    goto v_30059;
v_30060:
    {
        fn = elt(env, 1); // re_parents
        return (*qfn2(fn))(fn, v_30119, v_30118);
    }
    goto v_30044;
v_30046:
    goto v_30071;
v_30067:
    v_30118 = stack[-3];
    v_30119 = qcar(v_30118);
    goto v_30068;
v_30069:
    v_30118 = stack[0];
    goto v_30070;
v_30071:
    goto v_30067;
v_30068:
    goto v_30069;
v_30070:
    fn = elt(env, 2); // defined_edge
    v_30118 = (*qfn2(fn))(fn, v_30119, v_30118);
    env = stack[-5];
    if (v_30118 == nil) goto v_30065;
    goto v_30080;
v_30076:
    v_30119 = stack[-2];
    goto v_30077;
v_30078:
    v_30118 = stack[-3];
    v_30118 = qcdr(v_30118);
    goto v_30079;
v_30080:
    goto v_30076;
v_30077:
    goto v_30078;
v_30079:
    v_30118 = Lnconc(nil, v_30119, v_30118);
    env = stack[-5];
    stack[-4] = v_30118;
    v_30118 = nil;
    stack[-2] = v_30118;
    goto v_30090;
v_30086:
    v_30118 = stack[-3];
    v_30119 = qcar(v_30118);
    goto v_30087;
v_30088:
    v_30118 = stack[-1];
    goto v_30089;
v_30090:
    goto v_30086;
v_30087:
    goto v_30088;
v_30089:
    v_30118 = cons(v_30119, v_30118);
    env = stack[-5];
    stack[-1] = v_30118;
    goto v_30099;
v_30095:
    v_30118 = stack[-3];
    v_30119 = qcar(v_30118);
    goto v_30096;
v_30097:
    v_30118 = stack[0];
    goto v_30098;
v_30099:
    goto v_30095;
v_30096:
    goto v_30097;
v_30098:
    v_30118 = cons(v_30119, v_30118);
    env = stack[-5];
    stack[0] = v_30118;
    v_30118 = stack[-4];
    stack[-3] = v_30118;
    goto v_30042;
v_30065:
    v_30118 = stack[-3];
    v_30118 = qcdr(v_30118);
    stack[-4] = v_30118;
    goto v_30113;
v_30109:
    v_30118 = stack[-3];
    v_30119 = qcar(v_30118);
    goto v_30110;
v_30111:
    v_30118 = stack[-2];
    goto v_30112;
v_30113:
    goto v_30109;
v_30110:
    goto v_30111;
v_30112:
    v_30118 = cons(v_30119, v_30118);
    env = stack[-5];
    stack[-2] = v_30118;
    v_30118 = stack[-4];
    stack[-3] = v_30118;
    goto v_30042;
v_30044:
    v_30118 = nil;
v_30041:
    return onevalue(v_30118);
}



// Code for dp!=comp

static LispObject CC_dpMcomp(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30075, v_30076;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30034,v_30035);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30035;
    stack[-1] = v_30034;
// end of prologue
    stack[-2] = nil;
v_30040:
    v_30075 = stack[0];
    if (v_30075 == nil) goto v_30043;
    else goto v_30044;
v_30043:
    v_30075 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_30075);
    }
v_30044:
    goto v_30055;
v_30051:
    v_30075 = stack[0];
    fn = elt(env, 2); // dp_lmon
    v_30075 = (*qfn1(fn))(fn, v_30075);
    env = stack[-3];
    fn = elt(env, 3); // mo_comp
    v_30076 = (*qfn1(fn))(fn, v_30075);
    env = stack[-3];
    goto v_30052;
v_30053:
    v_30075 = stack[-1];
    goto v_30054;
v_30055:
    goto v_30051;
v_30052:
    goto v_30053;
v_30054:
    v_30075 = Leqn(nil, v_30076, v_30075);
    env = stack[-3];
    if (v_30075 == nil) goto v_30049;
    goto v_30065;
v_30061:
    v_30075 = stack[0];
    v_30076 = qcar(v_30075);
    goto v_30062;
v_30063:
    v_30075 = stack[-2];
    goto v_30064;
v_30065:
    goto v_30061;
v_30062:
    goto v_30063;
v_30064:
    v_30075 = cons(v_30076, v_30075);
    env = stack[-3];
    stack[-2] = v_30075;
    v_30075 = stack[0];
    v_30075 = qcdr(v_30075);
    stack[0] = v_30075;
    goto v_30040;
v_30049:
    v_30075 = stack[0];
    v_30075 = qcdr(v_30075);
    stack[0] = v_30075;
    goto v_30040;
    v_30075 = nil;
    return onevalue(v_30075);
}



// Code for simp!-prop!-form

static LispObject CC_simpKpropKform(LispObject env,
                         LispObject v_30034)
{
    env = qenv(env);
    LispObject v_30326, v_30327, v_30328;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30034);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    v_30327 = v_30034;
// end of prologue
    goto v_30044;
v_30040:
    v_30328 = v_30327;
    goto v_30041;
v_30042:
    v_30326 = elt(env, 1); // (nil)
    goto v_30043;
v_30044:
    goto v_30040;
v_30041:
    goto v_30042;
v_30043:
    if (equal(v_30328, v_30326)) goto v_30038;
    else goto v_30039;
v_30038:
    v_30326 = qvalue(elt(env, 2)); // !'true
    goto v_30037;
v_30039:
    v_30326 = v_30327;
    stack[-7] = v_30326;
    v_30326 = stack[-7];
    if (v_30326 == nil) goto v_30059;
    else goto v_30060;
v_30059:
    v_30326 = nil;
    goto v_30054;
v_30060:
    v_30326 = stack[-7];
    v_30326 = qcar(v_30326);
    stack[-3] = v_30326;
    v_30326 = stack[-3];
    if (v_30326 == nil) goto v_30076;
    else goto v_30077;
v_30076:
    v_30326 = nil;
    goto v_30071;
v_30077:
    v_30326 = stack[-3];
    v_30326 = qcar(v_30326);
    v_30328 = v_30326;
    goto v_30093;
v_30089:
    v_30327 = v_30328;
    goto v_30090;
v_30091:
    v_30326 = elt(env, 3); // not_prop!*
    goto v_30092;
v_30093:
    goto v_30089;
v_30090:
    goto v_30091;
v_30092:
    if (!consp(v_30327)) goto v_30087;
    v_30327 = qcar(v_30327);
    if (v_30327 == v_30326) goto v_30086;
    else goto v_30087;
v_30086:
    goto v_30101;
v_30097:
    v_30326 = elt(env, 4); // not
    goto v_30098;
v_30099:
    v_30327 = v_30328;
    v_30327 = qcdr(v_30327);
    v_30327 = qcar(v_30327);
    goto v_30100;
v_30101:
    goto v_30097;
v_30098:
    goto v_30099;
v_30100:
    v_30326 = list2(v_30326, v_30327);
    env = stack[-8];
    goto v_30085;
v_30087:
    v_30326 = v_30328;
    v_30326 = qcdr(v_30326);
    v_30326 = qcar(v_30326);
    goto v_30085;
    v_30326 = nil;
v_30085:
    v_30326 = ncons(v_30326);
    env = stack[-8];
    stack[-1] = v_30326;
    stack[-2] = v_30326;
v_30072:
    v_30326 = stack[-3];
    v_30326 = qcdr(v_30326);
    stack[-3] = v_30326;
    v_30326 = stack[-3];
    if (v_30326 == nil) goto v_30115;
    else goto v_30116;
v_30115:
    v_30326 = stack[-2];
    goto v_30071;
v_30116:
    goto v_30124;
v_30120:
    stack[0] = stack[-1];
    goto v_30121;
v_30122:
    v_30326 = stack[-3];
    v_30326 = qcar(v_30326);
    v_30328 = v_30326;
    goto v_30139;
v_30135:
    v_30327 = v_30328;
    goto v_30136;
v_30137:
    v_30326 = elt(env, 3); // not_prop!*
    goto v_30138;
v_30139:
    goto v_30135;
v_30136:
    goto v_30137;
v_30138:
    if (!consp(v_30327)) goto v_30133;
    v_30327 = qcar(v_30327);
    if (v_30327 == v_30326) goto v_30132;
    else goto v_30133;
v_30132:
    goto v_30147;
v_30143:
    v_30326 = elt(env, 4); // not
    goto v_30144;
v_30145:
    v_30327 = v_30328;
    v_30327 = qcdr(v_30327);
    v_30327 = qcar(v_30327);
    goto v_30146;
v_30147:
    goto v_30143;
v_30144:
    goto v_30145;
v_30146:
    v_30326 = list2(v_30326, v_30327);
    env = stack[-8];
    goto v_30131;
v_30133:
    v_30326 = v_30328;
    v_30326 = qcdr(v_30326);
    v_30326 = qcar(v_30326);
    goto v_30131;
    v_30326 = nil;
v_30131:
    v_30326 = ncons(v_30326);
    env = stack[-8];
    goto v_30123;
v_30124:
    goto v_30120;
v_30121:
    goto v_30122;
v_30123:
    v_30326 = Lrplacd(nil, stack[0], v_30326);
    env = stack[-8];
    v_30326 = stack[-1];
    v_30326 = qcdr(v_30326);
    stack[-1] = v_30326;
    goto v_30072;
v_30071:
    v_30327 = v_30326;
    v_30327 = qcdr(v_30327);
    if (v_30327 == nil) goto v_30162;
    goto v_30170;
v_30166:
    v_30327 = qvalue(elt(env, 5)); // !'and
    goto v_30167;
v_30168:
    goto v_30169;
v_30170:
    goto v_30166;
v_30167:
    goto v_30168;
v_30169:
    v_30326 = cons(v_30327, v_30326);
    env = stack[-8];
    goto v_30160;
v_30162:
    v_30326 = qcar(v_30326);
    goto v_30160;
    v_30326 = nil;
v_30160:
    v_30326 = ncons(v_30326);
    env = stack[-8];
    stack[-5] = v_30326;
    stack[-6] = v_30326;
v_30055:
    v_30326 = stack[-7];
    v_30326 = qcdr(v_30326);
    stack[-7] = v_30326;
    v_30326 = stack[-7];
    if (v_30326 == nil) goto v_30181;
    else goto v_30182;
v_30181:
    v_30326 = stack[-6];
    goto v_30054;
v_30182:
    goto v_30190;
v_30186:
    stack[-4] = stack[-5];
    goto v_30187;
v_30188:
    v_30326 = stack[-7];
    v_30326 = qcar(v_30326);
    stack[-3] = v_30326;
    v_30326 = stack[-3];
    if (v_30326 == nil) goto v_30205;
    else goto v_30206;
v_30205:
    v_30326 = nil;
    goto v_30200;
v_30206:
    v_30326 = stack[-3];
    v_30326 = qcar(v_30326);
    v_30328 = v_30326;
    goto v_30222;
v_30218:
    v_30327 = v_30328;
    goto v_30219;
v_30220:
    v_30326 = elt(env, 3); // not_prop!*
    goto v_30221;
v_30222:
    goto v_30218;
v_30219:
    goto v_30220;
v_30221:
    if (!consp(v_30327)) goto v_30216;
    v_30327 = qcar(v_30327);
    if (v_30327 == v_30326) goto v_30215;
    else goto v_30216;
v_30215:
    goto v_30230;
v_30226:
    v_30326 = elt(env, 4); // not
    goto v_30227;
v_30228:
    v_30327 = v_30328;
    v_30327 = qcdr(v_30327);
    v_30327 = qcar(v_30327);
    goto v_30229;
v_30230:
    goto v_30226;
v_30227:
    goto v_30228;
v_30229:
    v_30326 = list2(v_30326, v_30327);
    env = stack[-8];
    goto v_30214;
v_30216:
    v_30326 = v_30328;
    v_30326 = qcdr(v_30326);
    v_30326 = qcar(v_30326);
    goto v_30214;
    v_30326 = nil;
v_30214:
    v_30326 = ncons(v_30326);
    env = stack[-8];
    stack[-1] = v_30326;
    stack[-2] = v_30326;
v_30201:
    v_30326 = stack[-3];
    v_30326 = qcdr(v_30326);
    stack[-3] = v_30326;
    v_30326 = stack[-3];
    if (v_30326 == nil) goto v_30244;
    else goto v_30245;
v_30244:
    v_30326 = stack[-2];
    goto v_30200;
v_30245:
    goto v_30253;
v_30249:
    stack[0] = stack[-1];
    goto v_30250;
v_30251:
    v_30326 = stack[-3];
    v_30326 = qcar(v_30326);
    v_30328 = v_30326;
    goto v_30268;
v_30264:
    v_30327 = v_30328;
    goto v_30265;
v_30266:
    v_30326 = elt(env, 3); // not_prop!*
    goto v_30267;
v_30268:
    goto v_30264;
v_30265:
    goto v_30266;
v_30267:
    if (!consp(v_30327)) goto v_30262;
    v_30327 = qcar(v_30327);
    if (v_30327 == v_30326) goto v_30261;
    else goto v_30262;
v_30261:
    goto v_30276;
v_30272:
    v_30326 = elt(env, 4); // not
    goto v_30273;
v_30274:
    v_30327 = v_30328;
    v_30327 = qcdr(v_30327);
    v_30327 = qcar(v_30327);
    goto v_30275;
v_30276:
    goto v_30272;
v_30273:
    goto v_30274;
v_30275:
    v_30326 = list2(v_30326, v_30327);
    env = stack[-8];
    goto v_30260;
v_30262:
    v_30326 = v_30328;
    v_30326 = qcdr(v_30326);
    v_30326 = qcar(v_30326);
    goto v_30260;
    v_30326 = nil;
v_30260:
    v_30326 = ncons(v_30326);
    env = stack[-8];
    goto v_30252;
v_30253:
    goto v_30249;
v_30250:
    goto v_30251;
v_30252:
    v_30326 = Lrplacd(nil, stack[0], v_30326);
    env = stack[-8];
    v_30326 = stack[-1];
    v_30326 = qcdr(v_30326);
    stack[-1] = v_30326;
    goto v_30201;
v_30200:
    v_30327 = v_30326;
    v_30327 = qcdr(v_30327);
    if (v_30327 == nil) goto v_30291;
    goto v_30299;
v_30295:
    v_30327 = qvalue(elt(env, 5)); // !'and
    goto v_30296;
v_30297:
    goto v_30298;
v_30299:
    goto v_30295;
v_30296:
    goto v_30297;
v_30298:
    v_30326 = cons(v_30327, v_30326);
    env = stack[-8];
    goto v_30289;
v_30291:
    v_30326 = qcar(v_30326);
    goto v_30289;
    v_30326 = nil;
v_30289:
    v_30326 = ncons(v_30326);
    env = stack[-8];
    goto v_30189;
v_30190:
    goto v_30186;
v_30187:
    goto v_30188;
v_30189:
    v_30326 = Lrplacd(nil, stack[-4], v_30326);
    env = stack[-8];
    v_30326 = stack[-5];
    v_30326 = qcdr(v_30326);
    stack[-5] = v_30326;
    goto v_30055;
v_30054:
    v_30327 = v_30326;
    v_30326 = v_30327;
    v_30326 = qcdr(v_30326);
    if (v_30326 == nil) goto v_30311;
    goto v_30319;
v_30315:
    v_30326 = qvalue(elt(env, 6)); // !'or
    goto v_30316;
v_30317:
    goto v_30318;
v_30319:
    goto v_30315;
v_30316:
    goto v_30317;
v_30318:
    return cons(v_30326, v_30327);
v_30311:
    v_30326 = v_30327;
    v_30326 = qcar(v_30326);
    goto v_30309;
    v_30326 = nil;
v_30309:
    goto v_30037;
    v_30326 = nil;
v_30037:
    return onevalue(v_30326);
}



// Code for can_rep_cell

static LispObject CC_can_rep_cell(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30055, v_30056, v_30057;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30034,v_30035);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30057 = v_30035;
    v_30055 = v_30034;
// end of prologue
    goto v_30041;
v_30037:
    goto v_30046;
v_30042:
    v_30055 = qcdr(v_30055);
    v_30056 = qcar(v_30055);
    goto v_30043;
v_30044:
    v_30055 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30045;
v_30046:
    goto v_30042;
v_30043:
    goto v_30044;
v_30045:
    stack[0] = *(LispObject *)((char *)v_30056 + (CELL-TAG_VECTOR) + (((intptr_t)v_30055-TAG_FIXNUM)/(16/CELL)));
    goto v_30038;
v_30039:
    v_30055 = v_30057;
    v_30055 = sub1(v_30055);
    goto v_30040;
v_30041:
    goto v_30037;
v_30038:
    goto v_30039;
v_30040:
    v_30055 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_30055-TAG_FIXNUM)/(16/CELL)));
    return onevalue(v_30055);
}



// Code for simpdot

static LispObject CC_simpdot(LispObject env,
                         LispObject v_30034)
{
    env = qenv(env);
    LispObject v_30044, v_30045;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30044 = v_30034;
// end of prologue
    goto v_30041;
v_30037:
    v_30045 = v_30044;
    goto v_30038;
v_30039:
    v_30044 = elt(env, 1); // dotord
    goto v_30040;
v_30041:
    goto v_30037;
v_30038:
    goto v_30039;
v_30040:
    {
        fn = elt(env, 2); // mkvarg
        return (*qfn2(fn))(fn, v_30045, v_30044);
    }
}



// Code for ofsf_bestgaussp

static LispObject CC_ofsf_bestgaussp(LispObject env,
                         LispObject v_30034)
{
    env = qenv(env);
    LispObject v_30119, v_30120, v_30121;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30121 = v_30034;
// end of prologue
    goto v_30044;
v_30040:
    v_30119 = v_30121;
    v_30120 = qcar(v_30119);
    goto v_30041;
v_30042:
    v_30119 = elt(env, 1); // failed
    goto v_30043;
v_30044:
    goto v_30040;
v_30041:
    goto v_30042;
v_30043:
    if (v_30120 == v_30119) goto v_30039;
    goto v_30056;
v_30052:
    v_30119 = v_30121;
    v_30120 = qcar(v_30119);
    goto v_30053;
v_30054:
    v_30119 = elt(env, 2); // gignore
    goto v_30055;
v_30056:
    goto v_30052;
v_30053:
    goto v_30054;
v_30055:
    if (v_30120 == v_30119) goto v_30051;
    goto v_30068;
v_30064:
    v_30119 = v_30121;
    v_30119 = qcar(v_30119);
    v_30119 = qcdr(v_30119);
    v_30120 = qcar(v_30119);
    goto v_30065;
v_30066:
    v_30119 = elt(env, 3); // lin
    goto v_30067;
v_30068:
    goto v_30064;
v_30065:
    goto v_30066;
v_30067:
    if (v_30120 == v_30119) goto v_30062;
    else goto v_30063;
v_30062:
    goto v_30082;
v_30078:
    v_30119 = v_30121;
    v_30119 = qcar(v_30119);
    v_30119 = qcdr(v_30119);
    v_30119 = qcdr(v_30119);
    v_30119 = qcar(v_30119);
    goto v_30079;
v_30080:
    v_30120 = elt(env, 4); // con
    goto v_30081;
v_30082:
    goto v_30078;
v_30079:
    goto v_30080;
v_30081:
    if (v_30119 == v_30120) goto v_30076;
    else goto v_30077;
v_30076:
    v_30119 = v_30121;
    v_30119 = qcdr(v_30119);
    v_30119 = qcar(v_30119);
    v_30119 = qcdr(v_30119);
    if (v_30119 == nil) goto v_30091;
    else goto v_30092;
v_30091:
    v_30119 = v_30121;
    v_30119 = qcdr(v_30119);
    v_30119 = qcar(v_30119);
    v_30119 = qcar(v_30119);
    v_30119 = qcdr(v_30119);
    v_30119 = qcdr(v_30119);
    v_30119 = (v_30119 == nil ? lisp_true : nil);
    goto v_30090;
v_30092:
    v_30119 = nil;
    goto v_30090;
    v_30119 = nil;
v_30090:
    goto v_30075;
v_30077:
    v_30119 = nil;
    goto v_30075;
    v_30119 = nil;
v_30075:
    goto v_30061;
v_30063:
    v_30119 = nil;
    goto v_30061;
    v_30119 = nil;
v_30061:
    goto v_30049;
v_30051:
    v_30119 = nil;
    goto v_30049;
    v_30119 = nil;
v_30049:
    goto v_30037;
v_30039:
    v_30119 = nil;
    goto v_30037;
    v_30119 = nil;
v_30037:
    return onevalue(v_30119);
}



// Code for texexplode

static LispObject CC_texexplode(LispObject env,
                         LispObject v_30034)
{
    env = qenv(env);
    LispObject v_30108, v_30109, v_30110;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30034);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30109 = v_30034;
// end of prologue
    v_30108 = v_30109;
    if (v_30108 == nil) goto v_30042;
    v_30108 = v_30109;
    if (!consp(v_30108)) goto v_30045;
    else goto v_30042;
v_30045:
    goto v_30058;
v_30054:
    v_30110 = v_30109;
    goto v_30055;
v_30056:
    v_30108 = elt(env, 1); // texname
    goto v_30057;
v_30058:
    goto v_30054;
v_30055:
    goto v_30056;
v_30057:
    v_30108 = get(v_30110, v_30108);
    env = stack[0];
    if (v_30108 == nil) goto v_30052;
    else goto v_30051;
v_30052:
    v_30108 = v_30109;
    if (!symbolp(v_30108)) v_30108 = nil;
    else { v_30108 = qfastgets(v_30108);
           if (v_30108 != nil) { v_30108 = elt(v_30108, 7); // class
#ifdef RECORD_GET
             if (v_30108 != SPID_NOPROP)
                record_get(elt(fastget_names, 7), 1);
             else record_get(elt(fastget_names, 7), 0),
                v_30108 = nil; }
           else record_get(elt(fastget_names, 7), 0); }
#else
             if (v_30108 == SPID_NOPROP) v_30108 = nil; }}
#endif
    if (v_30108 == nil) goto v_30063;
    else goto v_30064;
v_30063:
    v_30108 = nil;
    goto v_30062;
v_30064:
    v_30108 = v_30109;
    goto v_30062;
    v_30108 = nil;
v_30062:
v_30051:
    if (v_30108 == nil) goto v_30049;
    else goto v_30048;
v_30049:
    v_30108 = v_30109;
    if (is_number(v_30108)) goto v_30073;
    else goto v_30074;
v_30073:
    v_30108 = v_30109;
    v_30108 = Lexplode(nil, v_30108);
    env = stack[0];
    fn = elt(env, 3); // texcollect
    v_30108 = (*qfn1(fn))(fn, v_30108);
    env = stack[0];
    goto v_30072;
v_30074:
    v_30108 = v_30109;
    v_30108 = Lstringp(nil, v_30108);
    env = stack[0];
    if (v_30108 == nil) goto v_30080;
    v_30108 = v_30109;
    v_30108 = Lexplodec(nil, v_30108);
    env = stack[0];
    fn = elt(env, 4); // strcollect
    v_30108 = (*qfn1(fn))(fn, v_30108);
    env = stack[0];
    goto v_30072;
v_30080:
    v_30108 = v_30109;
    v_30108 = Lexplodec(nil, v_30108);
    env = stack[0];
    fn = elt(env, 3); // texcollect
    v_30108 = (*qfn1(fn))(fn, v_30108);
    env = stack[0];
    fn = elt(env, 5); // texexplist
    v_30108 = (*qfn1(fn))(fn, v_30108);
    env = stack[0];
    goto v_30072;
    v_30108 = nil;
v_30072:
v_30048:
    goto v_30040;
v_30042:
    v_30108 = nil;
v_30040:
    v_30109 = v_30108;
    v_30108 = v_30109;
    if (v_30108 == nil) goto v_30094;
    else goto v_30095;
v_30094:
    v_30108 = elt(env, 2); // ! 
    return ncons(v_30108);
v_30095:
    v_30108 = v_30109;
    if (!consp(v_30108)) goto v_30100;
    v_30108 = v_30109;
    goto v_30093;
v_30100:
    v_30108 = v_30109;
    return ncons(v_30108);
    v_30108 = nil;
v_30093:
    v_30109 = v_30108;
    v_30108 = v_30109;
    return onevalue(v_30108);
}



// Code for gigcd!:

static LispObject CC_gigcdT(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30061, v_30062;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30034,v_30035);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30035;
    stack[-1] = v_30034;
// end of prologue
v_30040:
    v_30061 = stack[0];
    fn = elt(env, 1); // gizerop!:
    v_30061 = (*qfn1(fn))(fn, v_30061);
    env = stack[-3];
    if (v_30061 == nil) goto v_30044;
    v_30061 = stack[-1];
    {
        fn = elt(env, 2); // fqa
        return (*qfn1(fn))(fn, v_30061);
    }
v_30044:
    v_30061 = stack[0];
    stack[-2] = v_30061;
    goto v_30057;
v_30053:
    v_30062 = stack[-1];
    goto v_30054;
v_30055:
    v_30061 = stack[0];
    goto v_30056;
v_30057:
    goto v_30053;
v_30054:
    goto v_30055;
v_30056:
    fn = elt(env, 3); // giremainder
    v_30061 = (*qfn2(fn))(fn, v_30062, v_30061);
    env = stack[-3];
    stack[0] = v_30061;
    v_30061 = stack[-2];
    stack[-1] = v_30061;
    goto v_30040;
    v_30061 = nil;
    return onevalue(v_30061);
}



// Code for simp!-sign2

static LispObject CC_simpKsign2(LispObject env,
                         LispObject v_30034)
{
    env = qenv(env);
    LispObject v_30063, v_30064;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30034);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_30034;
// end of prologue
    v_30063 = stack[0];
    fn = elt(env, 2); // rd!-sign
    v_30063 = (*qfn1(fn))(fn, v_30063);
    env = stack[-1];
    v_30064 = v_30063;
    v_30063 = v_30064;
    if (v_30063 == nil) goto v_30042;
    goto v_30049;
v_30045:
    goto v_30046;
v_30047:
    v_30063 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30048;
v_30049:
    goto v_30045;
v_30046:
    goto v_30047;
v_30048:
    return cons(v_30064, v_30063);
v_30042:
    goto v_30060;
v_30056:
    v_30064 = elt(env, 1); // sign
    goto v_30057;
v_30058:
    v_30063 = stack[0];
    goto v_30059;
v_30060:
    goto v_30056;
v_30057:
    goto v_30058;
v_30059:
    v_30063 = list2(v_30064, v_30063);
    env = stack[-1];
    {
        fn = elt(env, 3); // simpiden
        return (*qfn1(fn))(fn, v_30063);
    }
    v_30063 = nil;
    return onevalue(v_30063);
}



// Code for qqe_prefix!-length

static LispObject CC_qqe_prefixKlength(LispObject env,
                         LispObject v_30034)
{
    env = qenv(env);
    LispObject v_30083, v_30084, v_30085;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30034);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_30084 = v_30034;
// end of prologue
    v_30083 = (LispObject)0+TAG_FIXNUM; // 0
    v_30085 = v_30083;
    v_30083 = v_30084;
    if (v_30083 == nil) goto v_30043;
    else goto v_30044;
v_30043:
    v_30083 = nil;
    stack[0] = v_30083;
    goto v_30042;
v_30044:
    v_30083 = v_30084;
    stack[0] = v_30083;
    goto v_30042;
v_30042:
v_30053:
    v_30083 = stack[0];
    if (v_30083 == nil) goto v_30056;
    v_30083 = stack[0];
    if (!consp(v_30083)) goto v_30056;
    goto v_30057;
v_30056:
    goto v_30052;
v_30057:
    goto v_30071;
v_30067:
    v_30083 = stack[0];
    v_30084 = qcar(v_30083);
    goto v_30068;
v_30069:
    v_30083 = elt(env, 1); // (rtail ltail rhead lhead)
    goto v_30070;
v_30071:
    goto v_30067;
v_30068:
    goto v_30069;
v_30070:
    v_30083 = Lmemq(nil, v_30084, v_30083);
    if (v_30083 == nil) goto v_30066;
    v_30083 = v_30085;
    v_30083 = add1(v_30083);
    env = stack[-1];
    v_30085 = v_30083;
    goto v_30064;
v_30066:
v_30064:
    v_30083 = stack[0];
    v_30083 = qcdr(v_30083);
    v_30083 = qcar(v_30083);
    stack[0] = v_30083;
    goto v_30053;
v_30052:
    v_30083 = v_30085;
    return onevalue(v_30083);
}



// Code for transferrow1

static LispObject CC_transferrow1(LispObject env,
                         LispObject v_30034)
{
    env = qenv(env);
    LispObject v_30088, v_30089;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30034);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30034;
// end of prologue
    goto v_30044;
v_30040:
    goto v_30049;
v_30045:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_30046;
v_30047:
    goto v_30056;
v_30052:
    v_30089 = qvalue(elt(env, 2)); // maxvar
    goto v_30053;
v_30054:
    v_30088 = stack[0];
    goto v_30055;
v_30056:
    goto v_30052;
v_30053:
    goto v_30054;
v_30055:
    v_30088 = plus2(v_30089, v_30088);
    env = stack[-2];
    goto v_30048;
v_30049:
    goto v_30045;
v_30046:
    goto v_30047;
v_30048:
    v_30089 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_30088-TAG_FIXNUM)/(16/CELL)));
    goto v_30041;
v_30042:
    v_30088 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_30043;
v_30044:
    goto v_30040;
v_30041:
    goto v_30042;
v_30043:
    v_30088 = *(LispObject *)((char *)v_30089 + (CELL-TAG_VECTOR) + (((intptr_t)v_30088-TAG_FIXNUM)/(16/CELL)));
    if (v_30088 == nil) goto v_30038;
    else goto v_30039;
v_30038:
    goto v_30066;
v_30062:
    goto v_30071;
v_30067:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_30068;
v_30069:
    goto v_30078;
v_30074:
    v_30089 = qvalue(elt(env, 2)); // maxvar
    goto v_30075;
v_30076:
    v_30088 = stack[0];
    goto v_30077;
v_30078:
    goto v_30074;
v_30075:
    goto v_30076;
v_30077:
    v_30088 = plus2(v_30089, v_30088);
    goto v_30070;
v_30071:
    goto v_30067;
v_30068:
    goto v_30069;
v_30070:
    v_30089 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_30088-TAG_FIXNUM)/(16/CELL)));
    goto v_30063;
v_30064:
    v_30088 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_30065;
v_30066:
    goto v_30062;
v_30063:
    goto v_30064;
v_30065:
    v_30088 = *(LispObject *)((char *)v_30089 + (CELL-TAG_VECTOR) + (((intptr_t)v_30088-TAG_FIXNUM)/(16/CELL)));
    v_30088 = (is_number(v_30088) ? lisp_true : nil);
    goto v_30037;
v_30039:
    v_30088 = nil;
    goto v_30037;
    v_30088 = nil;
v_30037:
    return onevalue(v_30088);
}



// Code for f2dip2

static LispObject CC_f2dip2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30121, v_30122, v_30123, v_30124;
    LispObject fn;
    LispObject v_30038, v_30037, v_30036, v_30035, v_30034;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "f2dip2");
    va_start(aa, nargs);
    v_30034 = va_arg(aa, LispObject);
    v_30035 = va_arg(aa, LispObject);
    v_30036 = va_arg(aa, LispObject);
    v_30037 = va_arg(aa, LispObject);
    v_30038 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_30038,v_30037,v_30036,v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_30034,v_30035,v_30036,v_30037,v_30038);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_30038;
    stack[-1] = v_30037;
    stack[-2] = v_30036;
    stack[-3] = v_30035;
    stack[-4] = v_30034;
// end of prologue
    goto v_30048;
v_30044:
    v_30122 = stack[-4];
    goto v_30045;
v_30046:
    v_30121 = qvalue(elt(env, 1)); // dipvars!*
    goto v_30047;
v_30048:
    goto v_30044;
v_30045:
    goto v_30046;
v_30047:
    v_30121 = Lmemq(nil, v_30122, v_30121);
    if (v_30121 == nil) goto v_30043;
    goto v_30061;
v_30053:
    v_30124 = stack[-1];
    goto v_30054;
v_30055:
    v_30123 = stack[-4];
    goto v_30056;
v_30057:
    v_30122 = stack[-3];
    goto v_30058;
v_30059:
    v_30121 = qvalue(elt(env, 1)); // dipvars!*
    goto v_30060;
v_30061:
    goto v_30053;
v_30054:
    goto v_30055;
v_30056:
    goto v_30057;
v_30058:
    goto v_30059;
v_30060:
    fn = elt(env, 2); // evinsert
    v_30121 = (*qfnn(fn))(fn, 4, v_30124, v_30123, v_30122, v_30121);
    env = stack[-5];
    goto v_30041;
v_30043:
    v_30121 = nil;
    goto v_30041;
    v_30121 = nil;
v_30041:
    v_30122 = v_30121;
    v_30121 = v_30122;
    if (v_30121 == nil) goto v_30073;
    v_30121 = v_30122;
    stack[-1] = v_30121;
    goto v_30071;
v_30073:
    goto v_30083;
v_30079:
    goto v_30080;
v_30081:
    goto v_30092;
v_30086:
    goto v_30098;
v_30094:
    goto v_30104;
v_30100:
    v_30122 = stack[-4];
    goto v_30101;
v_30102:
    v_30121 = stack[-3];
    goto v_30103;
v_30104:
    goto v_30100;
v_30101:
    goto v_30102;
v_30103:
    fn = elt(env, 3); // to
    v_30122 = (*qfn2(fn))(fn, v_30122, v_30121);
    env = stack[-5];
    goto v_30095;
v_30096:
    v_30121 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30097;
v_30098:
    goto v_30094;
v_30095:
    goto v_30096;
v_30097:
    v_30123 = cons(v_30122, v_30121);
    env = stack[-5];
    goto v_30087;
v_30088:
    v_30122 = nil;
    goto v_30089;
v_30090:
    v_30121 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30091;
v_30092:
    goto v_30086;
v_30087:
    goto v_30088;
v_30089:
    goto v_30090;
v_30091:
    v_30121 = acons(v_30123, v_30122, v_30121);
    env = stack[-5];
    goto v_30082;
v_30083:
    goto v_30079;
v_30080:
    goto v_30081;
v_30082:
    fn = elt(env, 4); // multsq
    v_30121 = (*qfn2(fn))(fn, stack[0], v_30121);
    env = stack[-5];
    stack[0] = v_30121;
    goto v_30071;
v_30071:
    goto v_30117;
v_30111:
    v_30123 = stack[-2];
    goto v_30112;
v_30113:
    v_30122 = stack[-1];
    goto v_30114;
v_30115:
    v_30121 = stack[0];
    goto v_30116;
v_30117:
    goto v_30111;
v_30112:
    goto v_30113;
v_30114:
    goto v_30115;
v_30116:
    {
        fn = elt(env, 5); // f2dip1
        return (*qfnn(fn))(fn, 3, v_30123, v_30122, v_30121);
    }
}



// Code for symmetrize!-inds

static LispObject CC_symmetrizeKinds(LispObject env,
                         LispObject v_30034, LispObject v_30035)
{
    env = qenv(env);
    LispObject v_30346, v_30347;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30034,v_30035);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-8] = v_30035;
    stack[-9] = v_30034;
// end of prologue
    v_30346 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-10] = v_30346;
    v_30346 = stack[-9];
    stack[-7] = v_30346;
    v_30346 = stack[-7];
    if (v_30346 == nil) goto v_30053;
    else goto v_30054;
v_30053:
    v_30346 = nil;
    goto v_30048;
v_30054:
    v_30346 = stack[-7];
    v_30346 = qcar(v_30346);
    v_30347 = v_30346;
    if (!consp(v_30347)) goto v_30063;
    else goto v_30064;
v_30063:
    goto v_30071;
v_30067:
    v_30347 = stack[-8];
    goto v_30068;
v_30069:
    goto v_30070;
v_30071:
    goto v_30067;
v_30068:
    goto v_30069;
v_30070:
    fn = elt(env, 1); // nth
    v_30346 = (*qfn2(fn))(fn, v_30347, v_30346);
    env = stack[-11];
    goto v_30062;
v_30064:
    stack[-3] = v_30346;
    v_30346 = stack[-3];
    if (v_30346 == nil) goto v_30085;
    else goto v_30086;
v_30085:
    v_30346 = nil;
    goto v_30080;
v_30086:
    v_30346 = stack[-3];
    v_30346 = qcar(v_30346);
    goto v_30098;
v_30094:
    v_30347 = stack[-8];
    goto v_30095;
v_30096:
    goto v_30097;
v_30098:
    goto v_30094;
v_30095:
    goto v_30096;
v_30097:
    fn = elt(env, 1); // nth
    v_30346 = (*qfn2(fn))(fn, v_30347, v_30346);
    env = stack[-11];
    v_30346 = ncons(v_30346);
    env = stack[-11];
    stack[-1] = v_30346;
    stack[-2] = v_30346;
v_30081:
    v_30346 = stack[-3];
    v_30346 = qcdr(v_30346);
    stack[-3] = v_30346;
    v_30346 = stack[-3];
    if (v_30346 == nil) goto v_30105;
    else goto v_30106;
v_30105:
    v_30346 = stack[-2];
    goto v_30080;
v_30106:
    goto v_30114;
v_30110:
    stack[0] = stack[-1];
    goto v_30111;
v_30112:
    v_30346 = stack[-3];
    v_30346 = qcar(v_30346);
    goto v_30125;
v_30121:
    v_30347 = stack[-8];
    goto v_30122;
v_30123:
    goto v_30124;
v_30125:
    goto v_30121;
v_30122:
    goto v_30123;
v_30124:
    fn = elt(env, 1); // nth
    v_30346 = (*qfn2(fn))(fn, v_30347, v_30346);
    env = stack[-11];
    v_30346 = ncons(v_30346);
    env = stack[-11];
    goto v_30113;
v_30114:
    goto v_30110;
v_30111:
    goto v_30112;
v_30113:
    v_30346 = Lrplacd(nil, stack[0], v_30346);
    env = stack[-11];
    v_30346 = stack[-1];
    v_30346 = qcdr(v_30346);
    stack[-1] = v_30346;
    goto v_30081;
v_30080:
    goto v_30062;
    v_30346 = nil;
v_30062:
    v_30346 = ncons(v_30346);
    env = stack[-11];
    stack[-5] = v_30346;
    stack[-6] = v_30346;
v_30049:
    v_30346 = stack[-7];
    v_30346 = qcdr(v_30346);
    stack[-7] = v_30346;
    v_30346 = stack[-7];
    if (v_30346 == nil) goto v_30134;
    else goto v_30135;
v_30134:
    v_30346 = stack[-6];
    goto v_30048;
v_30135:
    goto v_30143;
v_30139:
    stack[-4] = stack[-5];
    goto v_30140;
v_30141:
    v_30346 = stack[-7];
    v_30346 = qcar(v_30346);
    v_30347 = v_30346;
    if (!consp(v_30347)) goto v_30151;
    else goto v_30152;
v_30151:
    goto v_30159;
v_30155:
    v_30347 = stack[-8];
    goto v_30156;
v_30157:
    goto v_30158;
v_30159:
    goto v_30155;
v_30156:
    goto v_30157;
v_30158:
    fn = elt(env, 1); // nth
    v_30346 = (*qfn2(fn))(fn, v_30347, v_30346);
    env = stack[-11];
    goto v_30150;
v_30152:
    stack[-3] = v_30346;
    v_30346 = stack[-3];
    if (v_30346 == nil) goto v_30173;
    else goto v_30174;
v_30173:
    v_30346 = nil;
    goto v_30168;
v_30174:
    v_30346 = stack[-3];
    v_30346 = qcar(v_30346);
    goto v_30186;
v_30182:
    v_30347 = stack[-8];
    goto v_30183;
v_30184:
    goto v_30185;
v_30186:
    goto v_30182;
v_30183:
    goto v_30184;
v_30185:
    fn = elt(env, 1); // nth
    v_30346 = (*qfn2(fn))(fn, v_30347, v_30346);
    env = stack[-11];
    v_30346 = ncons(v_30346);
    env = stack[-11];
    stack[-1] = v_30346;
    stack[-2] = v_30346;
v_30169:
    v_30346 = stack[-3];
    v_30346 = qcdr(v_30346);
    stack[-3] = v_30346;
    v_30346 = stack[-3];
    if (v_30346 == nil) goto v_30193;
    else goto v_30194;
v_30193:
    v_30346 = stack[-2];
    goto v_30168;
v_30194:
    goto v_30202;
v_30198:
    stack[0] = stack[-1];
    goto v_30199;
v_30200:
    v_30346 = stack[-3];
    v_30346 = qcar(v_30346);
    goto v_30213;
v_30209:
    v_30347 = stack[-8];
    goto v_30210;
v_30211:
    goto v_30212;
v_30213:
    goto v_30209;
v_30210:
    goto v_30211;
v_30212:
    fn = elt(env, 1); // nth
    v_30346 = (*qfn2(fn))(fn, v_30347, v_30346);
    env = stack[-11];
    v_30346 = ncons(v_30346);
    env = stack[-11];
    goto v_30201;
v_30202:
    goto v_30198;
v_30199:
    goto v_30200;
v_30201:
    v_30346 = Lrplacd(nil, stack[0], v_30346);
    env = stack[-11];
    v_30346 = stack[-1];
    v_30346 = qcdr(v_30346);
    stack[-1] = v_30346;
    goto v_30169;
v_30168:
    goto v_30150;
    v_30346 = nil;
v_30150:
    v_30346 = ncons(v_30346);
    env = stack[-11];
    goto v_30142;
v_30143:
    goto v_30139;
v_30140:
    goto v_30141;
v_30142:
    v_30346 = Lrplacd(nil, stack[-4], v_30346);
    env = stack[-11];
    v_30346 = stack[-5];
    v_30346 = qcdr(v_30346);
    stack[-5] = v_30346;
    goto v_30049;
v_30048:
    stack[-5] = v_30346;
    v_30346 = stack[-5];
    v_30346 = qcar(v_30346);
    if (!consp(v_30346)) goto v_30222;
    else goto v_30223;
v_30222:
    v_30346 = stack[-5];
    fn = elt(env, 2); // indordn
    v_30346 = (*qfn1(fn))(fn, v_30346);
    env = stack[-11];
    goto v_30221;
v_30223:
    v_30346 = stack[-5];
    fn = elt(env, 3); // indordln
    v_30346 = (*qfn1(fn))(fn, v_30346);
    env = stack[-11];
    fn = elt(env, 4); // flatindl
    v_30346 = (*qfn1(fn))(fn, v_30346);
    env = stack[-11];
    goto v_30221;
    v_30346 = nil;
v_30221:
    stack[0] = v_30346;
    v_30346 = stack[-9];
    v_30346 = qcar(v_30346);
    if (!consp(v_30346)) goto v_30236;
    v_30346 = stack[-9];
    fn = elt(env, 4); // flatindl
    v_30346 = (*qfn1(fn))(fn, v_30346);
    env = stack[-11];
    stack[-9] = v_30346;
    goto v_30234;
v_30236:
v_30234:
    goto v_30246;
v_30242:
    v_30347 = stack[-9];
    goto v_30243;
v_30244:
    v_30346 = stack[0];
    goto v_30245;
v_30246:
    goto v_30242;
v_30243:
    goto v_30244;
v_30245:
    fn = elt(env, 5); // pair
    v_30346 = (*qfn2(fn))(fn, v_30347, v_30346);
    env = stack[-11];
    stack[-5] = v_30346;
    goto v_30254;
v_30250:
    stack[-6] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30251;
v_30252:
    v_30346 = stack[-8];
    stack[-7] = v_30346;
    v_30346 = stack[-7];
    if (v_30346 == nil) goto v_30265;
    else goto v_30266;
v_30265:
    v_30346 = nil;
    goto v_30260;
v_30266:
    v_30346 = stack[-7];
    v_30346 = qcar(v_30346);
    stack[-1] = v_30346;
    v_30346 = stack[-5];
    if (v_30346 == nil) goto v_30276;
    goto v_30284;
v_30280:
    v_30346 = stack[-5];
    v_30346 = qcar(v_30346);
    stack[0] = qcar(v_30346);
    goto v_30281;
v_30282:
    v_30346 = stack[-10];
    v_30346 = add1(v_30346);
    env = stack[-11];
    stack[-10] = v_30346;
    goto v_30283;
v_30284:
    goto v_30280;
v_30281:
    goto v_30282;
v_30283:
    if (equal(stack[0], v_30346)) goto v_30279;
    else goto v_30276;
v_30279:
    v_30346 = stack[-5];
    v_30346 = qcar(v_30346);
    v_30346 = qcdr(v_30346);
    v_30347 = v_30346;
    v_30346 = stack[-5];
    v_30346 = qcdr(v_30346);
    stack[-5] = v_30346;
    v_30346 = v_30347;
    goto v_30274;
v_30276:
    v_30346 = stack[-1];
    goto v_30274;
    v_30346 = nil;
v_30274:
    v_30346 = ncons(v_30346);
    env = stack[-11];
    stack[-3] = v_30346;
    stack[-4] = v_30346;
v_30261:
    v_30346 = stack[-7];
    v_30346 = qcdr(v_30346);
    stack[-7] = v_30346;
    v_30346 = stack[-7];
    if (v_30346 == nil) goto v_30303;
    else goto v_30304;
v_30303:
    v_30346 = stack[-4];
    goto v_30260;
v_30304:
    goto v_30312;
v_30308:
    stack[-2] = stack[-3];
    goto v_30309;
v_30310:
    v_30346 = stack[-7];
    v_30346 = qcar(v_30346);
    stack[-1] = v_30346;
    v_30346 = stack[-5];
    if (v_30346 == nil) goto v_30321;
    goto v_30329;
v_30325:
    v_30346 = stack[-5];
    v_30346 = qcar(v_30346);
    stack[0] = qcar(v_30346);
    goto v_30326;
v_30327:
    v_30346 = stack[-10];
    v_30346 = add1(v_30346);
    env = stack[-11];
    stack[-10] = v_30346;
    goto v_30328;
v_30329:
    goto v_30325;
v_30326:
    goto v_30327;
v_30328:
    if (equal(stack[0], v_30346)) goto v_30324;
    else goto v_30321;
v_30324:
    v_30346 = stack[-5];
    v_30346 = qcar(v_30346);
    v_30346 = qcdr(v_30346);
    v_30347 = v_30346;
    v_30346 = stack[-5];
    v_30346 = qcdr(v_30346);
    stack[-5] = v_30346;
    v_30346 = v_30347;
    goto v_30319;
v_30321:
    v_30346 = stack[-1];
    goto v_30319;
    v_30346 = nil;
v_30319:
    v_30346 = ncons(v_30346);
    env = stack[-11];
    goto v_30311;
v_30312:
    goto v_30308;
v_30309:
    goto v_30310;
v_30311:
    v_30346 = Lrplacd(nil, stack[-2], v_30346);
    env = stack[-11];
    v_30346 = stack[-3];
    v_30346 = qcdr(v_30346);
    stack[-3] = v_30346;
    goto v_30261;
v_30260:
    goto v_30253;
v_30254:
    goto v_30250;
v_30251:
    goto v_30252;
v_30253:
    {
        LispObject v_30359 = stack[-6];
        return cons(v_30359, v_30346);
    }
    return onevalue(v_30346);
}



// Code for coeff_sortl

static LispObject CC_coeff_sortl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30056, v_30057, v_30058;
    LispObject fn;
    LispObject v_30036, v_30035, v_30034;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "coeff_sortl");
    va_start(aa, nargs);
    v_30034 = va_arg(aa, LispObject);
    v_30035 = va_arg(aa, LispObject);
    v_30036 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30036,v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30034,v_30035,v_30036);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30036;
    stack[-1] = v_30035;
    v_30056 = v_30034;
// end of prologue
    goto v_30045;
v_30039:
    goto v_30051;
v_30047:
    v_30057 = v_30056;
    goto v_30048;
v_30049:
    v_30056 = stack[0];
    goto v_30050;
v_30051:
    goto v_30047;
v_30048:
    goto v_30049;
v_30050:
    fn = elt(env, 1); // coeff_ordn
    v_30058 = (*qfn2(fn))(fn, v_30057, v_30056);
    env = stack[-2];
    goto v_30040;
v_30041:
    v_30057 = stack[-1];
    goto v_30042;
v_30043:
    v_30056 = stack[0];
    goto v_30044;
v_30045:
    goto v_30039;
v_30040:
    goto v_30041;
v_30042:
    goto v_30043;
v_30044:
    {
        fn = elt(env, 2); // coeff_sortl1
        return (*qfnn(fn))(fn, 3, v_30058, v_30057, v_30056);
    }
}



// Code for subs2chkex

static LispObject CC_subs2chkex(LispObject env,
                         LispObject v_30034)
{
    env = qenv(env);
    LispObject v_30073, v_30074, v_30075;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30034);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_30034;
// end of prologue
v_30033:
    v_30073 = stack[0];
    if (v_30073 == nil) goto v_30038;
    else goto v_30039;
v_30038:
    v_30073 = nil;
    goto v_30037;
v_30039:
    v_30073 = stack[0];
    v_30073 = qcar(v_30073);
    v_30073 = qcdr(v_30073);
    fn = elt(env, 1); // subs2chk
    v_30073 = (*qfn1(fn))(fn, v_30073);
    env = stack[-1];
    v_30074 = v_30073;
    if (v_30074 == nil) goto v_30052;
    goto v_30061;
v_30055:
    v_30074 = stack[0];
    v_30074 = qcar(v_30074);
    v_30075 = qcar(v_30074);
    goto v_30056;
v_30057:
    v_30074 = v_30073;
    goto v_30058;
v_30059:
    v_30073 = stack[0];
    v_30073 = qcdr(v_30073);
    goto v_30060;
v_30061:
    goto v_30055;
v_30056:
    goto v_30057;
v_30058:
    goto v_30059;
v_30060:
    return acons(v_30075, v_30074, v_30073);
v_30052:
    v_30073 = stack[0];
    v_30073 = qcdr(v_30073);
    stack[0] = v_30073;
    goto v_30033;
    v_30073 = nil;
    goto v_30037;
    v_30073 = nil;
v_30037:
    return onevalue(v_30073);
}



// Code for simpsqrt3

static LispObject CC_simpsqrt3(LispObject env,
                         LispObject v_30034)
{
    env = qenv(env);
    LispObject v_30106, v_30107, v_30108;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30034);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30034;
// end of prologue
    goto v_30044;
v_30040:
    v_30107 = stack[0];
    goto v_30041;
v_30042:
    v_30106 = qvalue(elt(env, 1)); // listofallsqrts
    goto v_30043;
v_30044:
    goto v_30040;
v_30041:
    goto v_30042;
v_30043:
    v_30106 = Lassoc(nil, v_30107, v_30106);
    stack[-1] = v_30106;
    v_30106 = stack[-1];
    if (v_30106 == nil) goto v_30051;
    v_30106 = stack[-1];
    v_30106 = qcdr(v_30106);
    goto v_30038;
v_30051:
    goto v_30059;
v_30055:
    v_30107 = qvalue(elt(env, 2)); // listofnewsqrts
    goto v_30056;
v_30057:
    v_30106 = qvalue(elt(env, 3)); // knowntobeindep
    goto v_30058;
v_30059:
    goto v_30055;
v_30056:
    goto v_30057;
v_30058:
    v_30106 = Latsoc(nil, v_30107, v_30106);
    stack[-1] = v_30106;
    v_30106 = stack[-1];
    if (v_30106 == nil) goto v_30065;
    else goto v_30066;
v_30065:
    goto v_30039;
v_30066:
    goto v_30072;
v_30068:
    v_30107 = stack[0];
    goto v_30069;
v_30070:
    v_30106 = stack[-1];
    v_30106 = qcdr(v_30106);
    goto v_30071;
v_30072:
    goto v_30068;
v_30069:
    goto v_30070;
v_30071:
    v_30106 = Lassoc(nil, v_30107, v_30106);
    stack[-1] = v_30106;
    v_30106 = stack[-1];
    if (v_30106 == nil) goto v_30080;
    goto v_30087;
v_30083:
    v_30107 = stack[-1];
    goto v_30084;
v_30085:
    v_30106 = qvalue(elt(env, 1)); // listofallsqrts
    goto v_30086;
v_30087:
    goto v_30083;
v_30084:
    goto v_30085;
v_30086:
    v_30106 = cons(v_30107, v_30106);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_30106; // listofallsqrts
    v_30106 = stack[-1];
    v_30106 = qcdr(v_30106);
    goto v_30038;
v_30080:
v_30039:
    v_30106 = stack[0];
    fn = elt(env, 4); // actualsimpsqrt
    v_30106 = (*qfn1(fn))(fn, v_30106);
    env = stack[-2];
    stack[-1] = v_30106;
    goto v_30101;
v_30095:
    v_30108 = stack[0];
    goto v_30096;
v_30097:
    v_30107 = stack[-1];
    goto v_30098;
v_30099:
    v_30106 = qvalue(elt(env, 1)); // listofallsqrts
    goto v_30100;
v_30101:
    goto v_30095;
v_30096:
    goto v_30097;
v_30098:
    goto v_30099;
v_30100:
    v_30106 = acons(v_30108, v_30107, v_30106);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_30106; // listofallsqrts
    v_30106 = stack[-1];
v_30038:
    return onevalue(v_30106);
}



// Code for ofsf_smmkatl!-or

static LispObject CC_ofsf_smmkatlKor(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30163, v_30164, v_30165;
    LispObject fn;
    LispObject v_30036, v_30035, v_30034;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_smmkatl-or");
    va_start(aa, nargs);
    v_30034 = va_arg(aa, LispObject);
    v_30035 = va_arg(aa, LispObject);
    v_30036 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30036,v_30035,v_30034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30034,v_30035,v_30036);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_30036;
    v_30163 = v_30035;
    stack[-4] = v_30034;
// end of prologue
    stack[-5] = v_30163;
v_30046:
    v_30163 = stack[-5];
    if (v_30163 == nil) goto v_30051;
    else goto v_30052;
v_30051:
    v_30163 = nil;
    goto v_30045;
v_30052:
    v_30163 = stack[-5];
    v_30163 = qcar(v_30163);
    goto v_30062;
v_30058:
    v_30164 = v_30163;
    v_30165 = qcar(v_30164);
    goto v_30059;
v_30060:
    v_30164 = stack[-4];
    goto v_30061;
v_30062:
    goto v_30058;
v_30059:
    goto v_30060;
v_30061:
    v_30164 = Latsoc(nil, v_30165, v_30164);
    v_30165 = v_30164;
    v_30164 = v_30165;
    if (v_30164 == nil) goto v_30069;
    else goto v_30070;
v_30069:
    goto v_30079;
v_30073:
    v_30164 = elt(env, 1); // or
    goto v_30074;
v_30075:
    v_30165 = v_30163;
    goto v_30076;
v_30077:
    v_30163 = stack[-3];
    goto v_30078;
v_30079:
    goto v_30073;
v_30074:
    goto v_30075;
v_30076:
    goto v_30077;
v_30078:
    fn = elt(env, 2); // ofsf_ir2atl
    v_30163 = (*qfnn(fn))(fn, 3, v_30164, v_30165, v_30163);
    env = stack[-6];
    goto v_30068;
v_30070:
    goto v_30092;
v_30086:
    goto v_30087;
v_30088:
    v_30164 = v_30163;
    goto v_30089;
v_30090:
    v_30163 = stack[-3];
    goto v_30091;
v_30092:
    goto v_30086;
v_30087:
    goto v_30088;
v_30089:
    goto v_30090;
v_30091:
    fn = elt(env, 3); // ofsf_smmkatl!-or1
    v_30163 = (*qfnn(fn))(fn, 3, v_30165, v_30164, v_30163);
    env = stack[-6];
    goto v_30068;
    v_30163 = nil;
v_30068:
    stack[-2] = v_30163;
    v_30163 = stack[-2];
    fn = elt(env, 4); // lastpair
    v_30163 = (*qfn1(fn))(fn, v_30163);
    env = stack[-6];
    stack[-1] = v_30163;
    v_30163 = stack[-5];
    v_30163 = qcdr(v_30163);
    stack[-5] = v_30163;
    v_30163 = stack[-1];
    if (!consp(v_30163)) goto v_30102;
    else goto v_30103;
v_30102:
    goto v_30046;
v_30103:
v_30047:
    v_30163 = stack[-5];
    if (v_30163 == nil) goto v_30107;
    else goto v_30108;
v_30107:
    v_30163 = stack[-2];
    goto v_30045;
v_30108:
    goto v_30116;
v_30112:
    stack[0] = stack[-1];
    goto v_30113;
v_30114:
    v_30163 = stack[-5];
    v_30163 = qcar(v_30163);
    goto v_30125;
v_30121:
    v_30164 = v_30163;
    v_30165 = qcar(v_30164);
    goto v_30122;
v_30123:
    v_30164 = stack[-4];
    goto v_30124;
v_30125:
    goto v_30121;
v_30122:
    goto v_30123;
v_30124:
    v_30164 = Latsoc(nil, v_30165, v_30164);
    v_30165 = v_30164;
    v_30164 = v_30165;
    if (v_30164 == nil) goto v_30132;
    else goto v_30133;
v_30132:
    goto v_30142;
v_30136:
    v_30165 = elt(env, 1); // or
    goto v_30137;
v_30138:
    v_30164 = v_30163;
    goto v_30139;
v_30140:
    v_30163 = stack[-3];
    goto v_30141;
v_30142:
    goto v_30136;
v_30137:
    goto v_30138;
v_30139:
    goto v_30140;
v_30141:
    fn = elt(env, 2); // ofsf_ir2atl
    v_30163 = (*qfnn(fn))(fn, 3, v_30165, v_30164, v_30163);
    env = stack[-6];
    goto v_30131;
v_30133:
    goto v_30155;
v_30149:
    goto v_30150;
v_30151:
    v_30164 = v_30163;
    goto v_30152;
v_30153:
    v_30163 = stack[-3];
    goto v_30154;
v_30155:
    goto v_30149;
v_30150:
    goto v_30151;
v_30152:
    goto v_30153;
v_30154:
    fn = elt(env, 3); // ofsf_smmkatl!-or1
    v_30163 = (*qfnn(fn))(fn, 3, v_30165, v_30164, v_30163);
    env = stack[-6];
    goto v_30131;
    v_30163 = nil;
v_30131:
    goto v_30115;
v_30116:
    goto v_30112;
v_30113:
    goto v_30114;
v_30115:
    v_30163 = Lrplacd(nil, stack[0], v_30163);
    env = stack[-6];
    v_30163 = stack[-1];
    fn = elt(env, 4); // lastpair
    v_30163 = (*qfn1(fn))(fn, v_30163);
    env = stack[-6];
    stack[-1] = v_30163;
    v_30163 = stack[-5];
    v_30163 = qcdr(v_30163);
    stack[-5] = v_30163;
    goto v_30047;
v_30045:
    return onevalue(v_30163);
}



setup_type const u50_setup[] =
{
    {"xadd*",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xaddH},
    {"*multsq",                 TOO_FEW_2,      CC_Hmultsq,    WRONG_NO_2},
    {"taymindegreel",           TOO_FEW_2,      CC_taymindegreel,WRONG_NO_2},
    {"cl_susimkatl",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_susimkatl},
    {"sfto_kexp",               TOO_FEW_2,      CC_sfto_kexp,  WRONG_NO_2},
    {"acfsf_0mk2",              TOO_FEW_2,      CC_acfsf_0mk2, WRONG_NO_2},
    {"latexprint",              CC_latexprint,  TOO_MANY_1,    WRONG_NO_1},
    {"decimal2internal",        TOO_FEW_2,      CC_decimal2internal,WRONG_NO_2},
    {"is_buble",                TOO_FEW_2,      CC_is_buble,   WRONG_NO_2},
    {"tidysqrtf",               CC_tidysqrtf,   TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_smwrmknowl",         TOO_FEW_2,      CC_ofsf_smwrmknowl,WRONG_NO_2},
    {"eval-yetunknowntypeexpr", TOO_FEW_2,      CC_evalKyetunknowntypeexpr,WRONG_NO_2},
    {"qqe_simplqequal",         TOO_FEW_2,      CC_qqe_simplqequal,WRONG_NO_2},
    {"vdpfmon",                 TOO_FEW_2,      CC_vdpfmon,    WRONG_NO_2},
    {"xexptpf",                 TOO_FEW_2,      CC_xexptpf,    WRONG_NO_2},
    {"mk-contract-coeff",       CC_mkKcontractKcoeff,TOO_MANY_1,WRONG_NO_1},
    {"rule-list",               TOO_FEW_2,      CC_ruleKlist,  WRONG_NO_2},
    {"hdiff",                   TOO_FEW_2,      CC_hdiff,      WRONG_NO_2},
    {"test-bool",               CC_testKbool,   TOO_MANY_1,    WRONG_NO_1},
    {"combin",                  TOO_FEW_2,      CC_combin,     WRONG_NO_2},
    {"alistp",                  CC_alistp,      TOO_MANY_1,    WRONG_NO_1},
    {"coeffs-to-form1",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_coeffsKtoKform1},
    {"small-random-number",     WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_smallKrandomKnumber},
    {"quotf*",                  TOO_FEW_2,      CC_quotfH,     WRONG_NO_2},
    {"vsl_boundtype1",          TOO_FEW_2,      CC_vsl_boundtype1,WRONG_NO_2},
    {"ps:value",                CC_psTvalue,    TOO_MANY_1,    WRONG_NO_1},
    {"ldf-spf-var",             CC_ldfKspfKvar, TOO_MANY_1,    WRONG_NO_1},
    {"al1_defined_vertex",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_al1_defined_vertex},
    {"dp=comp",                 TOO_FEW_2,      CC_dpMcomp,    WRONG_NO_2},
    {"simp-prop-form",          CC_simpKpropKform,TOO_MANY_1,  WRONG_NO_1},
    {"can_rep_cell",            TOO_FEW_2,      CC_can_rep_cell,WRONG_NO_2},
    {"simpdot",                 CC_simpdot,     TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_bestgaussp",         CC_ofsf_bestgaussp,TOO_MANY_1, WRONG_NO_1},
    {"texexplode",              CC_texexplode,  TOO_MANY_1,    WRONG_NO_1},
    {"gigcd:",                  TOO_FEW_2,      CC_gigcdT,     WRONG_NO_2},
    {"simp-sign2",              CC_simpKsign2,  TOO_MANY_1,    WRONG_NO_1},
    {"qqe_prefix-length",       CC_qqe_prefixKlength,TOO_MANY_1,WRONG_NO_1},
    {"transferrow1",            CC_transferrow1,TOO_MANY_1,    WRONG_NO_1},
    {"f2dip2",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_f2dip2},
    {"symmetrize-inds",         TOO_FEW_2,      CC_symmetrizeKinds,WRONG_NO_2},
    {"coeff_sortl",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_coeff_sortl},
    {"subs2chkex",              CC_subs2chkex,  TOO_MANY_1,    WRONG_NO_1},
    {"simpsqrt3",               CC_simpsqrt3,   TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_smmkatl-or",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smmkatlKor},
    {NULL, (one_args *)"u50", (two_args *)"87667 2904888 5811806", 0}
};

// end of generated code
