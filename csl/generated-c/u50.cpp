
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



// Code for natnump

static LispObject CC_natnump(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28731, v_28732;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28731 = v_28712;
// end of prologue
    v_28732 = v_28731;
    v_28732 = integerp(v_28732);
    if (v_28732 == nil) goto v_28716;
    else goto v_28717;
v_28716:
    v_28731 = nil;
    goto v_28715;
v_28717:
    goto v_28728;
v_28724:
    v_28732 = v_28731;
    goto v_28725;
v_28726:
    v_28731 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28727;
v_28728:
    goto v_28724;
v_28725:
    goto v_28726;
v_28727:
        return Lgeq(nil, v_28732, v_28731);
    v_28731 = nil;
v_28715:
    return onevalue(v_28731);
}



// Code for taylorp

static LispObject CC_taylorp(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28722, v_28723;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28722 = v_28712;
// end of prologue
    goto v_28719;
v_28715:
    goto v_28716;
v_28717:
    v_28723 = elt(env, 1); // taylor
    goto v_28718;
v_28719:
    goto v_28715;
v_28716:
    goto v_28717;
v_28718:
        return Leqcar(nil, v_28722, v_28723);
}



// Code for monomcomparelex

static LispObject CC_monomcomparelex(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_28855, v_28856, v_28857;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_28713;
    v_28855 = v_28712;
// end of prologue
    goto v_28728;
v_28724:
    v_28857 = nil;
    goto v_28725;
v_28726:
    goto v_28734;
v_28730:
    v_28856 = v_28855;
    goto v_28731;
v_28732:
    v_28855 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28733;
v_28734:
    goto v_28730;
v_28731:
    goto v_28732;
v_28733:
    v_28855 = *(LispObject *)((char *)v_28856 + (CELL-TAG_VECTOR) + (((intptr_t)v_28855-TAG_FIXNUM)/(16/CELL)));
    goto v_28727;
v_28728:
    goto v_28724;
v_28725:
    goto v_28726;
v_28727:
    v_28855 = cons(v_28857, v_28855);
    env = stack[-3];
    v_28855 = Lreverse(nil, v_28855);
    env = stack[-3];
    v_28855 = qcdr(v_28855);
    stack[-2] = v_28855;
    goto v_28745;
v_28741:
    v_28857 = nil;
    goto v_28742;
v_28743:
    goto v_28751;
v_28747:
    v_28856 = stack[0];
    goto v_28748;
v_28749:
    v_28855 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28750;
v_28751:
    goto v_28747;
v_28748:
    goto v_28749;
v_28750:
    v_28855 = *(LispObject *)((char *)v_28856 + (CELL-TAG_VECTOR) + (((intptr_t)v_28855-TAG_FIXNUM)/(16/CELL)));
    goto v_28744;
v_28745:
    goto v_28741;
v_28742:
    goto v_28743;
v_28744:
    v_28855 = cons(v_28857, v_28855);
    env = stack[-3];
    v_28855 = Lreverse(nil, v_28855);
    env = stack[-3];
    v_28855 = qcdr(v_28855);
    stack[-1] = v_28855;
    v_28855 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_28855;
v_28759:
    v_28855 = stack[-2];
    v_28855 = qcar(v_28855);
    if (v_28855 == nil) goto v_28762;
    v_28855 = stack[-1];
    v_28855 = qcar(v_28855);
    if (v_28855 == nil) goto v_28762;
    goto v_28763;
v_28762:
    goto v_28758;
v_28763:
    goto v_28780;
v_28776:
    v_28855 = stack[-2];
    v_28856 = qcar(v_28855);
    goto v_28777;
v_28778:
    v_28855 = stack[-1];
    v_28855 = qcar(v_28855);
    goto v_28779;
v_28780:
    goto v_28776;
v_28777:
    goto v_28778;
v_28779:
    v_28855 = (LispObject)lessp2(v_28856, v_28855);
    v_28855 = v_28855 ? lisp_true : nil;
    env = stack[-3];
    if (v_28855 == nil) goto v_28774;
    v_28855 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_28855;
    v_28855 = nil;
    v_28855 = ncons(v_28855);
    env = stack[-3];
    stack[-2] = v_28855;
    goto v_28772;
v_28774:
    goto v_28796;
v_28792:
    v_28855 = stack[-2];
    v_28856 = qcar(v_28855);
    goto v_28793;
v_28794:
    v_28855 = stack[-1];
    v_28855 = qcar(v_28855);
    goto v_28795;
v_28796:
    goto v_28792;
v_28793:
    goto v_28794;
v_28795:
    v_28855 = (LispObject)greaterp2(v_28856, v_28855);
    v_28855 = v_28855 ? lisp_true : nil;
    env = stack[-3];
    if (v_28855 == nil) goto v_28790;
    v_28855 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[0] = v_28855;
    v_28855 = nil;
    v_28855 = ncons(v_28855);
    env = stack[-3];
    stack[-2] = v_28855;
    goto v_28772;
v_28790:
    v_28855 = stack[-2];
    v_28855 = qcdr(v_28855);
    stack[-2] = v_28855;
    v_28855 = stack[-1];
    v_28855 = qcdr(v_28855);
    stack[-1] = v_28855;
    goto v_28772;
v_28772:
    goto v_28759;
v_28758:
    goto v_28824;
v_28820:
    v_28856 = stack[0];
    goto v_28821;
v_28822:
    v_28855 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28823;
v_28824:
    goto v_28820;
v_28821:
    goto v_28822;
v_28823:
    if (v_28856 == v_28855) goto v_28818;
    else goto v_28819;
v_28818:
    v_28855 = stack[-2];
    v_28855 = qcar(v_28855);
    goto v_28817;
v_28819:
    v_28855 = nil;
    goto v_28817;
    v_28855 = nil;
v_28817:
    if (v_28855 == nil) goto v_28815;
    v_28855 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_28855;
    goto v_28813;
v_28815:
    goto v_28844;
v_28840:
    v_28856 = stack[0];
    goto v_28841;
v_28842:
    v_28855 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28843;
v_28844:
    goto v_28840;
v_28841:
    goto v_28842;
v_28843:
    if (v_28856 == v_28855) goto v_28838;
    else goto v_28839;
v_28838:
    v_28855 = stack[-1];
    v_28855 = qcar(v_28855);
    goto v_28837;
v_28839:
    v_28855 = nil;
    goto v_28837;
    v_28855 = nil;
v_28837:
    if (v_28855 == nil) goto v_28835;
    v_28855 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[0] = v_28855;
    goto v_28813;
v_28835:
v_28813:
    v_28855 = stack[0];
    return onevalue(v_28855);
}



// Code for makecoeffpairs

static LispObject CC_makecoeffpairs(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28733, v_28734, v_28735, v_28736;
    LispObject fn;
    LispObject v_28715, v_28714, v_28713, v_28712;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "makecoeffpairs");
    va_start(aa, nargs);
    v_28712 = va_arg(aa, LispObject);
    v_28713 = va_arg(aa, LispObject);
    v_28714 = va_arg(aa, LispObject);
    v_28715 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_28715,v_28714,v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_28712,v_28713,v_28714,v_28715);
    }
// copy arguments values to proper place
    v_28733 = v_28715;
    v_28734 = v_28714;
    v_28735 = v_28713;
    v_28736 = v_28712;
// end of prologue
    goto v_28727;
v_28719:
    goto v_28720;
v_28721:
    goto v_28722;
v_28723:
    goto v_28724;
v_28725:
    goto v_28726;
v_28727:
    goto v_28719;
v_28720:
    goto v_28721;
v_28722:
    goto v_28723;
v_28724:
    goto v_28725;
v_28726:
    fn = elt(env, 1); // makecoeffpairs1
    v_28733 = (*qfnn(fn))(fn, 4, v_28736, v_28735, v_28734, v_28733);
    v_28733 = qcdr(v_28733);
        return Lnreverse(nil, v_28733);
}



// Code for rat_abs

static LispObject CC_rat_abs(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28725, v_28726;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_28712;
// end of prologue
    goto v_28719;
v_28715:
    v_28725 = stack[0];
    v_28725 = qcar(v_28725);
    fn = elt(env, 1); // absf
    v_28726 = (*qfn1(fn))(fn, v_28725);
    goto v_28716;
v_28717:
    v_28725 = stack[0];
    v_28725 = qcdr(v_28725);
    goto v_28718;
v_28719:
    goto v_28715;
v_28716:
    goto v_28717;
v_28718:
    return cons(v_28726, v_28725);
}



// Code for parfool

static LispObject CC_parfool(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28755, v_28756, v_28757;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
// copy arguments values to proper place
    v_28757 = v_28712;
// end of prologue
    v_28755 = v_28757;
    v_28755 = qcar(v_28755);
    if (v_28755 == nil) goto v_28716;
    else goto v_28717;
v_28716:
    v_28755 = lisp_true;
    goto v_28715;
v_28717:
    v_28755 = v_28757;
    v_28755 = qcar(v_28755);
    if (is_number(v_28755)) goto v_28723;
    else goto v_28722;
v_28723:
    goto v_28735;
v_28731:
    v_28755 = v_28757;
    v_28756 = qcdr(v_28755);
    goto v_28732;
v_28733:
    v_28755 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28734;
v_28735:
    goto v_28731;
v_28732:
    goto v_28733;
v_28734:
    if (v_28756 == v_28755) goto v_28729;
    else goto v_28730;
v_28729:
    goto v_28744;
v_28740:
    v_28755 = v_28757;
    v_28756 = qcar(v_28755);
    goto v_28741;
v_28742:
    v_28755 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28743;
v_28744:
    goto v_28740;
v_28741:
    goto v_28742;
v_28743:
    v_28755 = (LispObject)lessp2(v_28756, v_28755);
    v_28755 = v_28755 ? lisp_true : nil;
    goto v_28728;
v_28730:
    v_28755 = nil;
    goto v_28728;
    v_28755 = nil;
v_28728:
    if (v_28755 == nil) goto v_28722;
    v_28755 = lisp_true;
    goto v_28715;
v_28722:
    v_28755 = nil;
    goto v_28715;
    v_28755 = nil;
v_28715:
    return onevalue(v_28755);
}



// Code for cr!:prep

static LispObject CC_crTprep(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28743, v_28744;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28712;
// end of prologue
    goto v_28720;
v_28716:
    goto v_28727;
v_28723:
    v_28744 = elt(env, 1); // !:rd!:
    goto v_28724;
v_28725:
    v_28743 = stack[0];
    v_28743 = qcdr(v_28743);
    v_28743 = qcar(v_28743);
    goto v_28726;
v_28727:
    goto v_28723;
v_28724:
    goto v_28725;
v_28726:
    v_28743 = cons(v_28744, v_28743);
    env = stack[-2];
    fn = elt(env, 2); // rd!:prep
    stack[-1] = (*qfn1(fn))(fn, v_28743);
    env = stack[-2];
    goto v_28717;
v_28718:
    goto v_28738;
v_28734:
    v_28744 = elt(env, 1); // !:rd!:
    goto v_28735;
v_28736:
    v_28743 = stack[0];
    v_28743 = qcdr(v_28743);
    v_28743 = qcdr(v_28743);
    goto v_28737;
v_28738:
    goto v_28734;
v_28735:
    goto v_28736;
v_28737:
    v_28743 = cons(v_28744, v_28743);
    env = stack[-2];
    fn = elt(env, 2); // rd!:prep
    v_28743 = (*qfn1(fn))(fn, v_28743);
    env = stack[-2];
    goto v_28719;
v_28720:
    goto v_28716;
v_28717:
    goto v_28718;
v_28719:
    v_28743 = cons(stack[-1], v_28743);
    env = stack[-2];
    {
        fn = elt(env, 3); // crprep1
        return (*qfn1(fn))(fn, v_28743);
    }
}



// Code for mkdmoderr

static LispObject CC_mkdmoderr(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_28738;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_28713;
    v_28738 = v_28712;
// end of prologue
    goto v_28722;
v_28716:
    stack[-4] = elt(env, 1); // lambda
    goto v_28717;
v_28718:
    stack[-2] = elt(env, 2); // (!*x!*)
    goto v_28719;
v_28720:
    goto v_28732;
v_28726:
    stack[-1] = elt(env, 3); // dmoderr
    goto v_28727;
v_28728:
    stack[0] = Lmkquote(nil, v_28738);
    env = stack[-5];
    goto v_28729;
v_28730:
    v_28738 = stack[-3];
    v_28738 = Lmkquote(nil, v_28738);
    env = stack[-5];
    goto v_28731;
v_28732:
    goto v_28726;
v_28727:
    goto v_28728;
v_28729:
    goto v_28730;
v_28731:
    v_28738 = list3(stack[-1], stack[0], v_28738);
    goto v_28721;
v_28722:
    goto v_28716;
v_28717:
    goto v_28718;
v_28719:
    goto v_28720;
v_28721:
    {
        LispObject v_28744 = stack[-4];
        LispObject v_28745 = stack[-2];
        return list3(v_28744, v_28745, v_28738);
    }
}



// Code for listquotient

static LispObject CC_listquotient(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_28933, v_28934, v_28935;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_28713;
    stack[0] = v_28712;
// end of prologue
    goto v_28725;
v_28721:
    v_28933 = stack[0];
    v_28934 = qcar(v_28933);
    goto v_28722;
v_28723:
    v_28933 = stack[-4];
    goto v_28724;
v_28725:
    goto v_28721;
v_28722:
    goto v_28723;
v_28724:
    fn = elt(env, 4); // reval1
    v_28933 = (*qfn2(fn))(fn, v_28934, v_28933);
    env = stack[-7];
    stack[-3] = v_28933;
    goto v_28734;
v_28730:
    v_28933 = stack[0];
    v_28933 = qcdr(v_28933);
    v_28934 = qcar(v_28933);
    goto v_28731;
v_28732:
    v_28933 = stack[-4];
    goto v_28733;
v_28734:
    goto v_28730;
v_28731:
    goto v_28732;
v_28733:
    fn = elt(env, 4); // reval1
    v_28933 = (*qfn2(fn))(fn, v_28934, v_28933);
    env = stack[-7];
    stack[-6] = v_28933;
    goto v_28744;
v_28740:
    stack[-5] = elt(env, 2); // list
    goto v_28741;
v_28742:
    goto v_28755;
v_28751:
    v_28934 = stack[-3];
    goto v_28752;
v_28753:
    v_28933 = elt(env, 2); // list
    goto v_28754;
v_28755:
    goto v_28751;
v_28752:
    goto v_28753;
v_28754:
    if (!consp(v_28934)) goto v_28748;
    v_28934 = qcar(v_28934);
    if (v_28934 == v_28933) goto v_28749;
v_28748:
    v_28933 = stack[-6];
    v_28933 = qcdr(v_28933);
    stack[-6] = v_28933;
    v_28933 = stack[-6];
    if (v_28933 == nil) goto v_28768;
    else goto v_28769;
v_28768:
    v_28933 = nil;
    goto v_28762;
v_28769:
    v_28933 = stack[-6];
    v_28933 = qcar(v_28933);
    goto v_28781;
v_28777:
    goto v_28789;
v_28783:
    v_28935 = elt(env, 3); // quotient
    goto v_28784;
v_28785:
    v_28934 = stack[-3];
    goto v_28786;
v_28787:
    goto v_28788;
v_28789:
    goto v_28783;
v_28784:
    goto v_28785;
v_28786:
    goto v_28787;
v_28788:
    v_28934 = list3(v_28935, v_28934, v_28933);
    env = stack[-7];
    goto v_28778;
v_28779:
    v_28933 = stack[-4];
    goto v_28780;
v_28781:
    goto v_28777;
v_28778:
    goto v_28779;
v_28780:
    fn = elt(env, 4); // reval1
    v_28933 = (*qfn2(fn))(fn, v_28934, v_28933);
    env = stack[-7];
    v_28933 = ncons(v_28933);
    env = stack[-7];
    stack[-1] = v_28933;
    stack[-2] = v_28933;
v_28763:
    v_28933 = stack[-6];
    v_28933 = qcdr(v_28933);
    stack[-6] = v_28933;
    v_28933 = stack[-6];
    if (v_28933 == nil) goto v_28798;
    else goto v_28799;
v_28798:
    v_28933 = stack[-2];
    goto v_28762;
v_28799:
    goto v_28807;
v_28803:
    stack[0] = stack[-1];
    goto v_28804;
v_28805:
    v_28933 = stack[-6];
    v_28933 = qcar(v_28933);
    goto v_28818;
v_28814:
    goto v_28826;
v_28820:
    v_28935 = elt(env, 3); // quotient
    goto v_28821;
v_28822:
    v_28934 = stack[-3];
    goto v_28823;
v_28824:
    goto v_28825;
v_28826:
    goto v_28820;
v_28821:
    goto v_28822;
v_28823:
    goto v_28824;
v_28825:
    v_28934 = list3(v_28935, v_28934, v_28933);
    env = stack[-7];
    goto v_28815;
v_28816:
    v_28933 = stack[-4];
    goto v_28817;
v_28818:
    goto v_28814;
v_28815:
    goto v_28816;
v_28817:
    fn = elt(env, 4); // reval1
    v_28933 = (*qfn2(fn))(fn, v_28934, v_28933);
    env = stack[-7];
    v_28933 = ncons(v_28933);
    env = stack[-7];
    goto v_28806;
v_28807:
    goto v_28803;
v_28804:
    goto v_28805;
v_28806:
    v_28933 = Lrplacd(nil, stack[0], v_28933);
    env = stack[-7];
    v_28933 = stack[-1];
    v_28933 = qcdr(v_28933);
    stack[-1] = v_28933;
    goto v_28763;
v_28762:
    goto v_28747;
v_28749:
    goto v_28840;
v_28836:
    v_28934 = stack[-6];
    goto v_28837;
v_28838:
    v_28933 = elt(env, 2); // list
    goto v_28839;
v_28840:
    goto v_28836;
v_28837:
    goto v_28838;
v_28839:
    if (!consp(v_28934)) goto v_28834;
    v_28934 = qcar(v_28934);
    if (v_28934 == v_28933) goto v_28833;
    else goto v_28834;
v_28833:
    goto v_28850;
v_28844:
    v_28933 = stack[-3];
    v_28935 = qcdr(v_28933);
    goto v_28845;
v_28846:
    v_28933 = stack[-6];
    v_28934 = qcdr(v_28933);
    goto v_28847;
v_28848:
    v_28933 = stack[-4];
    goto v_28849;
v_28850:
    goto v_28844;
v_28845:
    goto v_28846;
v_28847:
    goto v_28848;
v_28849:
    fn = elt(env, 5); // listquotient2
    v_28933 = (*qfnn(fn))(fn, 3, v_28935, v_28934, v_28933);
    goto v_28747;
v_28834:
    v_28933 = stack[-3];
    v_28933 = qcdr(v_28933);
    stack[-3] = v_28933;
    v_28933 = stack[-3];
    if (v_28933 == nil) goto v_28868;
    else goto v_28869;
v_28868:
    v_28933 = nil;
    goto v_28862;
v_28869:
    v_28933 = stack[-3];
    v_28933 = qcar(v_28933);
    goto v_28881;
v_28877:
    goto v_28889;
v_28883:
    v_28935 = elt(env, 3); // quotient
    goto v_28884;
v_28885:
    v_28934 = v_28933;
    goto v_28886;
v_28887:
    v_28933 = stack[-6];
    goto v_28888;
v_28889:
    goto v_28883;
v_28884:
    goto v_28885;
v_28886:
    goto v_28887;
v_28888:
    v_28934 = list3(v_28935, v_28934, v_28933);
    env = stack[-7];
    goto v_28878;
v_28879:
    v_28933 = stack[-4];
    goto v_28880;
v_28881:
    goto v_28877;
v_28878:
    goto v_28879;
v_28880:
    fn = elt(env, 4); // reval1
    v_28933 = (*qfn2(fn))(fn, v_28934, v_28933);
    env = stack[-7];
    v_28933 = ncons(v_28933);
    env = stack[-7];
    stack[-1] = v_28933;
    stack[-2] = v_28933;
v_28863:
    v_28933 = stack[-3];
    v_28933 = qcdr(v_28933);
    stack[-3] = v_28933;
    v_28933 = stack[-3];
    if (v_28933 == nil) goto v_28898;
    else goto v_28899;
v_28898:
    v_28933 = stack[-2];
    goto v_28862;
v_28899:
    goto v_28907;
v_28903:
    stack[0] = stack[-1];
    goto v_28904;
v_28905:
    v_28933 = stack[-3];
    v_28933 = qcar(v_28933);
    goto v_28918;
v_28914:
    goto v_28926;
v_28920:
    v_28935 = elt(env, 3); // quotient
    goto v_28921;
v_28922:
    v_28934 = v_28933;
    goto v_28923;
v_28924:
    v_28933 = stack[-6];
    goto v_28925;
v_28926:
    goto v_28920;
v_28921:
    goto v_28922;
v_28923:
    goto v_28924;
v_28925:
    v_28934 = list3(v_28935, v_28934, v_28933);
    env = stack[-7];
    goto v_28915;
v_28916:
    v_28933 = stack[-4];
    goto v_28917;
v_28918:
    goto v_28914;
v_28915:
    goto v_28916;
v_28917:
    fn = elt(env, 4); // reval1
    v_28933 = (*qfn2(fn))(fn, v_28934, v_28933);
    env = stack[-7];
    v_28933 = ncons(v_28933);
    env = stack[-7];
    goto v_28906;
v_28907:
    goto v_28903;
v_28904:
    goto v_28905;
v_28906:
    v_28933 = Lrplacd(nil, stack[0], v_28933);
    env = stack[-7];
    v_28933 = stack[-1];
    v_28933 = qcdr(v_28933);
    stack[-1] = v_28933;
    goto v_28863;
v_28862:
    goto v_28747;
    v_28933 = nil;
v_28747:
    goto v_28743;
v_28744:
    goto v_28740;
v_28741:
    goto v_28742;
v_28743:
    {
        LispObject v_28943 = stack[-5];
        return cons(v_28943, v_28933);
    }
    return onevalue(v_28933);
}



// Code for expand!-imrepartpow

static LispObject CC_expandKimrepartpow(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28820, v_28821;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_28712;
// end of prologue
// Binding !*exp
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = nil; // !*exp
    v_28820 = lisp_true;
    qvalue(elt(env, 1)) = v_28820; // !*exp
    v_28820 = stack[-2];
    v_28820 = qcar(v_28820);
    if (symbolp(v_28820)) goto v_28723;
    goto v_28731;
v_28727:
    v_28820 = stack[-2];
    v_28820 = qcar(v_28820);
    v_28821 = qcar(v_28820);
    goto v_28728;
v_28729:
    v_28820 = elt(env, 3); // cmpxsplitfn
    goto v_28730;
v_28731:
    goto v_28727;
v_28728:
    goto v_28729;
v_28730:
    v_28820 = get(v_28821, v_28820);
    env = stack[-4];
    goto v_28721;
v_28723:
    v_28820 = nil;
    goto v_28721;
    v_28820 = nil;
v_28721:
    v_28821 = v_28820;
    goto v_28744;
v_28740:
    v_28820 = v_28821;
    if (v_28820 == nil) goto v_28747;
    else goto v_28748;
v_28747:
    goto v_28758;
v_28754:
    v_28820 = stack[-2];
    v_28821 = qcar(v_28820);
    goto v_28755;
v_28756:
    v_28820 = elt(env, 4); // i
    goto v_28757;
v_28758:
    goto v_28754;
v_28755:
    goto v_28756;
v_28757:
    if (v_28821 == v_28820) goto v_28752;
    else goto v_28753;
v_28752:
    goto v_28767;
v_28763:
    goto v_28774;
v_28770:
    goto v_28780;
v_28776:
    v_28821 = elt(env, 4); // i
    goto v_28777;
v_28778:
    v_28820 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28779;
v_28780:
    goto v_28776;
v_28777:
    goto v_28778;
v_28779:
    fn = elt(env, 5); // to
    v_28821 = (*qfn2(fn))(fn, v_28821, v_28820);
    env = stack[-4];
    goto v_28771;
v_28772:
    v_28820 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28773;
v_28774:
    goto v_28770;
v_28771:
    goto v_28772;
v_28773:
    v_28820 = cons(v_28821, v_28820);
    env = stack[-4];
    v_28821 = ncons(v_28820);
    env = stack[-4];
    goto v_28764;
v_28765:
    v_28820 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28766;
v_28767:
    goto v_28763;
v_28764:
    goto v_28765;
v_28766:
    v_28820 = cons(v_28821, v_28820);
    env = stack[-4];
    goto v_28751;
v_28753:
    goto v_28792;
v_28788:
    v_28820 = stack[-2];
    v_28820 = qcar(v_28820);
    fn = elt(env, 6); // mkrepart
    stack[-1] = (*qfn1(fn))(fn, v_28820);
    env = stack[-4];
    goto v_28789;
v_28790:
    goto v_28801;
v_28797:
    v_28820 = elt(env, 4); // i
    fn = elt(env, 7); // simp
    stack[0] = (*qfn1(fn))(fn, v_28820);
    env = stack[-4];
    goto v_28798;
v_28799:
    v_28820 = stack[-2];
    v_28820 = qcar(v_28820);
    fn = elt(env, 8); // mkimpart
    v_28820 = (*qfn1(fn))(fn, v_28820);
    env = stack[-4];
    goto v_28800;
v_28801:
    goto v_28797;
v_28798:
    goto v_28799;
v_28800:
    fn = elt(env, 9); // multsq
    v_28820 = (*qfn2(fn))(fn, stack[0], v_28820);
    env = stack[-4];
    goto v_28791;
v_28792:
    goto v_28788;
v_28789:
    goto v_28790;
v_28791:
    fn = elt(env, 10); // addsq
    v_28820 = (*qfn2(fn))(fn, stack[-1], v_28820);
    env = stack[-4];
    goto v_28751;
    v_28820 = nil;
v_28751:
    v_28821 = v_28820;
    goto v_28746;
v_28748:
    goto v_28814;
v_28810:
    goto v_28811;
v_28812:
    v_28820 = stack[-2];
    v_28820 = qcar(v_28820);
    goto v_28813;
v_28814:
    goto v_28810;
v_28811:
    goto v_28812;
v_28813:
    v_28820 = Lapply1(nil, v_28821, v_28820);
    env = stack[-4];
    v_28821 = v_28820;
    goto v_28746;
    v_28821 = nil;
v_28746:
    goto v_28741;
v_28742:
    v_28820 = stack[-2];
    v_28820 = qcdr(v_28820);
    goto v_28743;
v_28744:
    goto v_28740;
v_28741:
    goto v_28742;
v_28743:
    fn = elt(env, 11); // exptsq
    v_28820 = (*qfn2(fn))(fn, v_28821, v_28820);
    ;}  // end of a binding scope
    return onevalue(v_28820);
}



// Code for fs!:prin!:

static LispObject CC_fsTprinT(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28721;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_28712;
// end of prologue
    v_28721 = elt(env, 1); // "["
    fn = elt(env, 3); // prin2!*
    v_28721 = (*qfn1(fn))(fn, v_28721);
    env = stack[-1];
    v_28721 = stack[0];
    v_28721 = qcdr(v_28721);
    fn = elt(env, 4); // fs!:prin
    v_28721 = (*qfn1(fn))(fn, v_28721);
    env = stack[-1];
    v_28721 = elt(env, 2); // "]"
    {
        fn = elt(env, 3); // prin2!*
        return (*qfn1(fn))(fn, v_28721);
    }
}



// Code for verify_tens_ids

static LispObject CC_verify_tens_ids(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28767, v_28768;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_28712;
// end of prologue
    v_28767 = stack[-1];
    v_28767 = qcar(v_28767);
    v_28768 = v_28767;
    v_28767 = stack[-1];
    v_28767 = qcdr(v_28767);
    v_28767 = qcar(v_28767);
    stack[0] = v_28767;
    v_28767 = v_28768;
    fn = elt(env, 4); // extract_dummy_ids
    v_28767 = (*qfn1(fn))(fn, v_28767);
    env = stack[-3];
    fn = elt(env, 5); // repeats
    v_28767 = (*qfn1(fn))(fn, v_28767);
    env = stack[-3];
    if (v_28767 == nil) goto v_28728;
    else goto v_28726;
v_28728:
    v_28767 = stack[0];
    fn = elt(env, 4); // extract_dummy_ids
    v_28767 = (*qfn1(fn))(fn, v_28767);
    env = stack[-3];
    fn = elt(env, 5); // repeats
    v_28767 = (*qfn1(fn))(fn, v_28767);
    env = stack[-3];
    if (v_28767 == nil) goto v_28732;
    else goto v_28726;
v_28732:
    goto v_28727;
v_28726:
    goto v_28743;
v_28737:
    stack[-2] = elt(env, 2); // cantens
    goto v_28738;
v_28739:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_28740;
v_28741:
    goto v_28751;
v_28747:
    goto v_28757;
v_28753:
    v_28767 = stack[-1];
    v_28768 = qcar(v_28767);
    goto v_28754;
v_28755:
    v_28767 = stack[-1];
    v_28767 = qcdr(v_28767);
    v_28767 = qcar(v_28767);
    goto v_28756;
v_28757:
    goto v_28753;
v_28754:
    goto v_28755;
v_28756:
    v_28768 = list2(v_28768, v_28767);
    env = stack[-3];
    goto v_28748;
v_28749:
    v_28767 = elt(env, 3); // "are inconsistent lists of indices"
    goto v_28750;
v_28751:
    goto v_28747;
v_28748:
    goto v_28749;
v_28750:
    v_28767 = list2(v_28768, v_28767);
    env = stack[-3];
    goto v_28742;
v_28743:
    goto v_28737;
v_28738:
    goto v_28739;
v_28740:
    goto v_28741;
v_28742:
    fn = elt(env, 6); // rerror
    v_28767 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_28767);
    goto v_28725;
v_28727:
    v_28767 = lisp_true;
    goto v_28717;
v_28725:
    v_28767 = nil;
v_28717:
    return onevalue(v_28767);
}



// Code for cl_sordp

static LispObject CC_cl_sordp(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_30102, v_30103, v_30104, v_30105;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28713;
    stack[-1] = v_28712;
// end of prologue
v_28711:
    v_30102 = stack[-1];
    if (!consp(v_30102)) goto v_28722;
    else goto v_28723;
v_28722:
    v_30102 = stack[-1];
    goto v_28721;
v_28723:
    v_30102 = stack[-1];
    v_30102 = qcar(v_30102);
    goto v_28721;
    v_30102 = nil;
v_28721:
    v_30105 = v_30102;
    v_30102 = stack[0];
    if (!consp(v_30102)) goto v_28732;
    else goto v_28733;
v_28732:
    v_30102 = stack[0];
    goto v_28731;
v_28733:
    v_30102 = stack[0];
    v_30102 = qcar(v_30102);
    goto v_28731;
    v_30102 = nil;
v_28731:
    v_30104 = v_30102;
    goto v_28760;
v_28756:
    v_30103 = v_30105;
    goto v_28757;
v_28758:
    v_30102 = elt(env, 2); // true
    goto v_28759;
v_28760:
    goto v_28756;
v_28757:
    goto v_28758;
v_28759:
    if (v_30103 == v_30102) goto v_28754;
    else goto v_28755;
v_28754:
    v_30102 = lisp_true;
    goto v_28753;
v_28755:
    goto v_28770;
v_28766:
    v_30103 = v_30105;
    goto v_28767;
v_28768:
    v_30102 = elt(env, 3); // false
    goto v_28769;
v_28770:
    goto v_28766;
v_28767:
    goto v_28768;
v_28769:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_28753;
    v_30102 = nil;
v_28753:
    if (v_30102 == nil) goto v_28751;
    v_30102 = lisp_true;
    goto v_28749;
v_28751:
    goto v_28797;
v_28793:
    v_30103 = v_30105;
    goto v_28794;
v_28795:
    v_30102 = elt(env, 4); // or
    goto v_28796;
v_28797:
    goto v_28793;
v_28794:
    goto v_28795;
v_28796:
    if (v_30103 == v_30102) goto v_28791;
    else goto v_28792;
v_28791:
    v_30102 = lisp_true;
    goto v_28790;
v_28792:
    goto v_28807;
v_28803:
    v_30103 = v_30105;
    goto v_28804;
v_28805:
    v_30102 = elt(env, 5); // and
    goto v_28806;
v_28807:
    goto v_28803;
v_28804:
    goto v_28805;
v_28806:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_28790;
    v_30102 = nil;
v_28790:
    if (v_30102 == nil) goto v_28788;
    v_30102 = lisp_true;
    goto v_28786;
v_28788:
    goto v_28818;
v_28814:
    v_30103 = v_30105;
    goto v_28815;
v_28816:
    v_30102 = elt(env, 6); // not
    goto v_28817;
v_28818:
    goto v_28814;
v_28815:
    goto v_28816;
v_28817:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_28786;
    v_30102 = nil;
v_28786:
    if (v_30102 == nil) goto v_28784;
    v_30102 = lisp_true;
    goto v_28782;
v_28784:
    goto v_28833;
v_28829:
    v_30103 = v_30105;
    goto v_28830;
v_28831:
    v_30102 = elt(env, 7); // impl
    goto v_28832;
v_28833:
    goto v_28829;
v_28830:
    goto v_28831;
v_28832:
    if (v_30103 == v_30102) goto v_28827;
    else goto v_28828;
v_28827:
    v_30102 = lisp_true;
    goto v_28826;
v_28828:
    goto v_28847;
v_28843:
    v_30103 = v_30105;
    goto v_28844;
v_28845:
    v_30102 = elt(env, 8); // repl
    goto v_28846;
v_28847:
    goto v_28843;
v_28844:
    goto v_28845;
v_28846:
    if (v_30103 == v_30102) goto v_28841;
    else goto v_28842;
v_28841:
    v_30102 = lisp_true;
    goto v_28840;
v_28842:
    goto v_28857;
v_28853:
    v_30103 = v_30105;
    goto v_28854;
v_28855:
    v_30102 = elt(env, 9); // equiv
    goto v_28856;
v_28857:
    goto v_28853;
v_28854:
    goto v_28855;
v_28856:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_28840;
    v_30102 = nil;
v_28840:
    goto v_28826;
    v_30102 = nil;
v_28826:
    goto v_28782;
    v_30102 = nil;
v_28782:
    if (v_30102 == nil) goto v_28780;
    v_30102 = lisp_true;
    goto v_28778;
v_28780:
    goto v_28876;
v_28872:
    v_30103 = v_30105;
    goto v_28873;
v_28874:
    v_30102 = elt(env, 10); // ex
    goto v_28875;
v_28876:
    goto v_28872;
v_28873:
    goto v_28874;
v_28875:
    if (v_30103 == v_30102) goto v_28870;
    else goto v_28871;
v_28870:
    v_30102 = lisp_true;
    goto v_28869;
v_28871:
    goto v_28886;
v_28882:
    v_30103 = v_30105;
    goto v_28883;
v_28884:
    v_30102 = elt(env, 11); // all
    goto v_28885;
v_28886:
    goto v_28882;
v_28883:
    goto v_28884;
v_28885:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_28869;
    v_30102 = nil;
v_28869:
    if (v_30102 == nil) goto v_28867;
    v_30102 = lisp_true;
    goto v_28865;
v_28867:
    goto v_28905;
v_28901:
    v_30103 = v_30105;
    goto v_28902;
v_28903:
    v_30102 = elt(env, 12); // bex
    goto v_28904;
v_28905:
    goto v_28901;
v_28902:
    goto v_28903;
v_28904:
    if (v_30103 == v_30102) goto v_28899;
    else goto v_28900;
v_28899:
    v_30102 = lisp_true;
    goto v_28898;
v_28900:
    goto v_28915;
v_28911:
    v_30103 = v_30105;
    goto v_28912;
v_28913:
    v_30102 = elt(env, 13); // ball
    goto v_28914;
v_28915:
    goto v_28911;
v_28912:
    goto v_28913;
v_28914:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_28898;
    v_30102 = nil;
v_28898:
    if (v_30102 == nil) goto v_28896;
    v_30102 = lisp_true;
    goto v_28894;
v_28896:
    v_30102 = v_30105;
    if (!symbolp(v_30102)) v_30102 = nil;
    else { v_30102 = qfastgets(v_30102);
           if (v_30102 != nil) { v_30102 = elt(v_30102, 21); // rl_external
#ifdef RECORD_GET
             if (v_30102 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_30102 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_30102 == SPID_NOPROP) v_30102 = nil; }}
#endif
    goto v_28894;
    v_30102 = nil;
v_28894:
    goto v_28865;
    v_30102 = nil;
v_28865:
    goto v_28778;
    v_30102 = nil;
v_28778:
    goto v_28749;
    v_30102 = nil;
v_28749:
    if (v_30102 == nil) goto v_28746;
    else goto v_28747;
v_28746:
    goto v_28936;
v_28932:
    v_30103 = v_30104;
    goto v_28933;
v_28934:
    v_30102 = elt(env, 2); // true
    goto v_28935;
v_28936:
    goto v_28932;
v_28933:
    goto v_28934;
v_28935:
    if (v_30103 == v_30102) goto v_28930;
    else goto v_28931;
v_28930:
    v_30102 = lisp_true;
    goto v_28929;
v_28931:
    goto v_28946;
v_28942:
    v_30103 = v_30104;
    goto v_28943;
v_28944:
    v_30102 = elt(env, 3); // false
    goto v_28945;
v_28946:
    goto v_28942;
v_28943:
    goto v_28944;
v_28945:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_28929;
    v_30102 = nil;
v_28929:
    if (v_30102 == nil) goto v_28927;
    v_30102 = lisp_true;
    goto v_28925;
v_28927:
    goto v_28973;
v_28969:
    v_30103 = v_30104;
    goto v_28970;
v_28971:
    v_30102 = elt(env, 4); // or
    goto v_28972;
v_28973:
    goto v_28969;
v_28970:
    goto v_28971;
v_28972:
    if (v_30103 == v_30102) goto v_28967;
    else goto v_28968;
v_28967:
    v_30102 = lisp_true;
    goto v_28966;
v_28968:
    goto v_28983;
v_28979:
    v_30103 = v_30104;
    goto v_28980;
v_28981:
    v_30102 = elt(env, 5); // and
    goto v_28982;
v_28983:
    goto v_28979;
v_28980:
    goto v_28981;
v_28982:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_28966;
    v_30102 = nil;
v_28966:
    if (v_30102 == nil) goto v_28964;
    v_30102 = lisp_true;
    goto v_28962;
v_28964:
    goto v_28994;
v_28990:
    v_30103 = v_30104;
    goto v_28991;
v_28992:
    v_30102 = elt(env, 6); // not
    goto v_28993;
v_28994:
    goto v_28990;
v_28991:
    goto v_28992;
v_28993:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_28962;
    v_30102 = nil;
v_28962:
    if (v_30102 == nil) goto v_28960;
    v_30102 = lisp_true;
    goto v_28958;
v_28960:
    goto v_29009;
v_29005:
    v_30103 = v_30104;
    goto v_29006;
v_29007:
    v_30102 = elt(env, 7); // impl
    goto v_29008;
v_29009:
    goto v_29005;
v_29006:
    goto v_29007;
v_29008:
    if (v_30103 == v_30102) goto v_29003;
    else goto v_29004;
v_29003:
    v_30102 = lisp_true;
    goto v_29002;
v_29004:
    goto v_29023;
v_29019:
    v_30103 = v_30104;
    goto v_29020;
v_29021:
    v_30102 = elt(env, 8); // repl
    goto v_29022;
v_29023:
    goto v_29019;
v_29020:
    goto v_29021;
v_29022:
    if (v_30103 == v_30102) goto v_29017;
    else goto v_29018;
v_29017:
    v_30102 = lisp_true;
    goto v_29016;
v_29018:
    goto v_29033;
v_29029:
    v_30103 = v_30104;
    goto v_29030;
v_29031:
    v_30102 = elt(env, 9); // equiv
    goto v_29032;
v_29033:
    goto v_29029;
v_29030:
    goto v_29031;
v_29032:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29016;
    v_30102 = nil;
v_29016:
    goto v_29002;
    v_30102 = nil;
v_29002:
    goto v_28958;
    v_30102 = nil;
v_28958:
    if (v_30102 == nil) goto v_28956;
    v_30102 = lisp_true;
    goto v_28954;
v_28956:
    goto v_29052;
v_29048:
    v_30103 = v_30104;
    goto v_29049;
v_29050:
    v_30102 = elt(env, 10); // ex
    goto v_29051;
v_29052:
    goto v_29048;
v_29049:
    goto v_29050;
v_29051:
    if (v_30103 == v_30102) goto v_29046;
    else goto v_29047;
v_29046:
    v_30102 = lisp_true;
    goto v_29045;
v_29047:
    goto v_29062;
v_29058:
    v_30103 = v_30104;
    goto v_29059;
v_29060:
    v_30102 = elt(env, 11); // all
    goto v_29061;
v_29062:
    goto v_29058;
v_29059:
    goto v_29060;
v_29061:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29045;
    v_30102 = nil;
v_29045:
    if (v_30102 == nil) goto v_29043;
    v_30102 = lisp_true;
    goto v_29041;
v_29043:
    goto v_29081;
v_29077:
    v_30103 = v_30104;
    goto v_29078;
v_29079:
    v_30102 = elt(env, 12); // bex
    goto v_29080;
v_29081:
    goto v_29077;
v_29078:
    goto v_29079;
v_29080:
    if (v_30103 == v_30102) goto v_29075;
    else goto v_29076;
v_29075:
    v_30102 = lisp_true;
    goto v_29074;
v_29076:
    goto v_29091;
v_29087:
    v_30103 = v_30104;
    goto v_29088;
v_29089:
    v_30102 = elt(env, 13); // ball
    goto v_29090;
v_29091:
    goto v_29087;
v_29088:
    goto v_29089;
v_29090:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29074;
    v_30102 = nil;
v_29074:
    if (v_30102 == nil) goto v_29072;
    v_30102 = lisp_true;
    goto v_29070;
v_29072:
    v_30102 = v_30104;
    if (!symbolp(v_30102)) v_30102 = nil;
    else { v_30102 = qfastgets(v_30102);
           if (v_30102 != nil) { v_30102 = elt(v_30102, 21); // rl_external
#ifdef RECORD_GET
             if (v_30102 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_30102 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_30102 == SPID_NOPROP) v_30102 = nil; }}
#endif
    goto v_29070;
    v_30102 = nil;
v_29070:
    goto v_29041;
    v_30102 = nil;
v_29041:
    goto v_28954;
    v_30102 = nil;
v_28954:
    goto v_28925;
    v_30102 = nil;
v_28925:
    v_30102 = (v_30102 == nil ? lisp_true : nil);
    goto v_28745;
v_28747:
    v_30102 = nil;
    goto v_28745;
    v_30102 = nil;
v_28745:
    if (v_30102 == nil) goto v_28743;
    goto v_29109;
v_29105:
    v_30103 = stack[-1];
    goto v_29106;
v_29107:
    v_30102 = stack[0];
    goto v_29108;
v_29109:
    goto v_29105;
v_29106:
    goto v_29107;
v_29108:
    {
        fn = elt(env, 14); // rl_ordatp
        return (*qfn2(fn))(fn, v_30103, v_30102);
    }
v_28743:
    goto v_29132;
v_29128:
    v_30103 = v_30105;
    goto v_29129;
v_29130:
    v_30102 = elt(env, 2); // true
    goto v_29131;
v_29132:
    goto v_29128;
v_29129:
    goto v_29130;
v_29131:
    if (v_30103 == v_30102) goto v_29126;
    else goto v_29127;
v_29126:
    v_30102 = lisp_true;
    goto v_29125;
v_29127:
    goto v_29142;
v_29138:
    v_30103 = v_30105;
    goto v_29139;
v_29140:
    v_30102 = elt(env, 3); // false
    goto v_29141;
v_29142:
    goto v_29138;
v_29139:
    goto v_29140;
v_29141:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29125;
    v_30102 = nil;
v_29125:
    if (v_30102 == nil) goto v_29123;
    v_30102 = lisp_true;
    goto v_29121;
v_29123:
    goto v_29169;
v_29165:
    v_30103 = v_30105;
    goto v_29166;
v_29167:
    v_30102 = elt(env, 4); // or
    goto v_29168;
v_29169:
    goto v_29165;
v_29166:
    goto v_29167;
v_29168:
    if (v_30103 == v_30102) goto v_29163;
    else goto v_29164;
v_29163:
    v_30102 = lisp_true;
    goto v_29162;
v_29164:
    goto v_29179;
v_29175:
    v_30103 = v_30105;
    goto v_29176;
v_29177:
    v_30102 = elt(env, 5); // and
    goto v_29178;
v_29179:
    goto v_29175;
v_29176:
    goto v_29177;
v_29178:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29162;
    v_30102 = nil;
v_29162:
    if (v_30102 == nil) goto v_29160;
    v_30102 = lisp_true;
    goto v_29158;
v_29160:
    goto v_29190;
v_29186:
    v_30103 = v_30105;
    goto v_29187;
v_29188:
    v_30102 = elt(env, 6); // not
    goto v_29189;
v_29190:
    goto v_29186;
v_29187:
    goto v_29188;
v_29189:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29158;
    v_30102 = nil;
v_29158:
    if (v_30102 == nil) goto v_29156;
    v_30102 = lisp_true;
    goto v_29154;
v_29156:
    goto v_29205;
v_29201:
    v_30103 = v_30105;
    goto v_29202;
v_29203:
    v_30102 = elt(env, 7); // impl
    goto v_29204;
v_29205:
    goto v_29201;
v_29202:
    goto v_29203;
v_29204:
    if (v_30103 == v_30102) goto v_29199;
    else goto v_29200;
v_29199:
    v_30102 = lisp_true;
    goto v_29198;
v_29200:
    goto v_29219;
v_29215:
    v_30103 = v_30105;
    goto v_29216;
v_29217:
    v_30102 = elt(env, 8); // repl
    goto v_29218;
v_29219:
    goto v_29215;
v_29216:
    goto v_29217;
v_29218:
    if (v_30103 == v_30102) goto v_29213;
    else goto v_29214;
v_29213:
    v_30102 = lisp_true;
    goto v_29212;
v_29214:
    goto v_29229;
v_29225:
    v_30103 = v_30105;
    goto v_29226;
v_29227:
    v_30102 = elt(env, 9); // equiv
    goto v_29228;
v_29229:
    goto v_29225;
v_29226:
    goto v_29227;
v_29228:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29212;
    v_30102 = nil;
v_29212:
    goto v_29198;
    v_30102 = nil;
v_29198:
    goto v_29154;
    v_30102 = nil;
v_29154:
    if (v_30102 == nil) goto v_29152;
    v_30102 = lisp_true;
    goto v_29150;
v_29152:
    goto v_29248;
v_29244:
    v_30103 = v_30105;
    goto v_29245;
v_29246:
    v_30102 = elt(env, 10); // ex
    goto v_29247;
v_29248:
    goto v_29244;
v_29245:
    goto v_29246;
v_29247:
    if (v_30103 == v_30102) goto v_29242;
    else goto v_29243;
v_29242:
    v_30102 = lisp_true;
    goto v_29241;
v_29243:
    goto v_29258;
v_29254:
    v_30103 = v_30105;
    goto v_29255;
v_29256:
    v_30102 = elt(env, 11); // all
    goto v_29257;
v_29258:
    goto v_29254;
v_29255:
    goto v_29256;
v_29257:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29241;
    v_30102 = nil;
v_29241:
    if (v_30102 == nil) goto v_29239;
    v_30102 = lisp_true;
    goto v_29237;
v_29239:
    goto v_29277;
v_29273:
    v_30103 = v_30105;
    goto v_29274;
v_29275:
    v_30102 = elt(env, 12); // bex
    goto v_29276;
v_29277:
    goto v_29273;
v_29274:
    goto v_29275;
v_29276:
    if (v_30103 == v_30102) goto v_29271;
    else goto v_29272;
v_29271:
    v_30102 = lisp_true;
    goto v_29270;
v_29272:
    goto v_29287;
v_29283:
    v_30103 = v_30105;
    goto v_29284;
v_29285:
    v_30102 = elt(env, 13); // ball
    goto v_29286;
v_29287:
    goto v_29283;
v_29284:
    goto v_29285;
v_29286:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29270;
    v_30102 = nil;
v_29270:
    if (v_30102 == nil) goto v_29268;
    v_30102 = lisp_true;
    goto v_29266;
v_29268:
    v_30102 = v_30105;
    if (!symbolp(v_30102)) v_30102 = nil;
    else { v_30102 = qfastgets(v_30102);
           if (v_30102 != nil) { v_30102 = elt(v_30102, 21); // rl_external
#ifdef RECORD_GET
             if (v_30102 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_30102 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_30102 == SPID_NOPROP) v_30102 = nil; }}
#endif
    goto v_29266;
    v_30102 = nil;
v_29266:
    goto v_29237;
    v_30102 = nil;
v_29237:
    goto v_29150;
    v_30102 = nil;
v_29150:
    goto v_29121;
    v_30102 = nil;
v_29121:
    if (v_30102 == nil) goto v_29118;
    else goto v_29119;
v_29118:
    goto v_29308;
v_29304:
    v_30103 = v_30104;
    goto v_29305;
v_29306:
    v_30102 = elt(env, 2); // true
    goto v_29307;
v_29308:
    goto v_29304;
v_29305:
    goto v_29306;
v_29307:
    if (v_30103 == v_30102) goto v_29302;
    else goto v_29303;
v_29302:
    v_30102 = lisp_true;
    goto v_29301;
v_29303:
    goto v_29318;
v_29314:
    v_30103 = v_30104;
    goto v_29315;
v_29316:
    v_30102 = elt(env, 3); // false
    goto v_29317;
v_29318:
    goto v_29314;
v_29315:
    goto v_29316;
v_29317:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29301;
    v_30102 = nil;
v_29301:
    if (v_30102 == nil) goto v_29299;
    v_30102 = lisp_true;
    goto v_29297;
v_29299:
    goto v_29345;
v_29341:
    v_30103 = v_30104;
    goto v_29342;
v_29343:
    v_30102 = elt(env, 4); // or
    goto v_29344;
v_29345:
    goto v_29341;
v_29342:
    goto v_29343;
v_29344:
    if (v_30103 == v_30102) goto v_29339;
    else goto v_29340;
v_29339:
    v_30102 = lisp_true;
    goto v_29338;
v_29340:
    goto v_29355;
v_29351:
    v_30103 = v_30104;
    goto v_29352;
v_29353:
    v_30102 = elt(env, 5); // and
    goto v_29354;
v_29355:
    goto v_29351;
v_29352:
    goto v_29353;
v_29354:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29338;
    v_30102 = nil;
v_29338:
    if (v_30102 == nil) goto v_29336;
    v_30102 = lisp_true;
    goto v_29334;
v_29336:
    goto v_29366;
v_29362:
    v_30103 = v_30104;
    goto v_29363;
v_29364:
    v_30102 = elt(env, 6); // not
    goto v_29365;
v_29366:
    goto v_29362;
v_29363:
    goto v_29364;
v_29365:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29334;
    v_30102 = nil;
v_29334:
    if (v_30102 == nil) goto v_29332;
    v_30102 = lisp_true;
    goto v_29330;
v_29332:
    goto v_29381;
v_29377:
    v_30103 = v_30104;
    goto v_29378;
v_29379:
    v_30102 = elt(env, 7); // impl
    goto v_29380;
v_29381:
    goto v_29377;
v_29378:
    goto v_29379;
v_29380:
    if (v_30103 == v_30102) goto v_29375;
    else goto v_29376;
v_29375:
    v_30102 = lisp_true;
    goto v_29374;
v_29376:
    goto v_29395;
v_29391:
    v_30103 = v_30104;
    goto v_29392;
v_29393:
    v_30102 = elt(env, 8); // repl
    goto v_29394;
v_29395:
    goto v_29391;
v_29392:
    goto v_29393;
v_29394:
    if (v_30103 == v_30102) goto v_29389;
    else goto v_29390;
v_29389:
    v_30102 = lisp_true;
    goto v_29388;
v_29390:
    goto v_29405;
v_29401:
    v_30103 = v_30104;
    goto v_29402;
v_29403:
    v_30102 = elt(env, 9); // equiv
    goto v_29404;
v_29405:
    goto v_29401;
v_29402:
    goto v_29403;
v_29404:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29388;
    v_30102 = nil;
v_29388:
    goto v_29374;
    v_30102 = nil;
v_29374:
    goto v_29330;
    v_30102 = nil;
v_29330:
    if (v_30102 == nil) goto v_29328;
    v_30102 = lisp_true;
    goto v_29326;
v_29328:
    goto v_29424;
v_29420:
    v_30103 = v_30104;
    goto v_29421;
v_29422:
    v_30102 = elt(env, 10); // ex
    goto v_29423;
v_29424:
    goto v_29420;
v_29421:
    goto v_29422;
v_29423:
    if (v_30103 == v_30102) goto v_29418;
    else goto v_29419;
v_29418:
    v_30102 = lisp_true;
    goto v_29417;
v_29419:
    goto v_29434;
v_29430:
    v_30103 = v_30104;
    goto v_29431;
v_29432:
    v_30102 = elt(env, 11); // all
    goto v_29433;
v_29434:
    goto v_29430;
v_29431:
    goto v_29432;
v_29433:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29417;
    v_30102 = nil;
v_29417:
    if (v_30102 == nil) goto v_29415;
    v_30102 = lisp_true;
    goto v_29413;
v_29415:
    goto v_29453;
v_29449:
    v_30103 = v_30104;
    goto v_29450;
v_29451:
    v_30102 = elt(env, 12); // bex
    goto v_29452;
v_29453:
    goto v_29449;
v_29450:
    goto v_29451;
v_29452:
    if (v_30103 == v_30102) goto v_29447;
    else goto v_29448;
v_29447:
    v_30102 = lisp_true;
    goto v_29446;
v_29448:
    goto v_29463;
v_29459:
    v_30103 = v_30104;
    goto v_29460;
v_29461:
    v_30102 = elt(env, 13); // ball
    goto v_29462;
v_29463:
    goto v_29459;
v_29460:
    goto v_29461;
v_29462:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29446;
    v_30102 = nil;
v_29446:
    if (v_30102 == nil) goto v_29444;
    v_30102 = lisp_true;
    goto v_29442;
v_29444:
    v_30102 = v_30104;
    if (!symbolp(v_30102)) v_30102 = nil;
    else { v_30102 = qfastgets(v_30102);
           if (v_30102 != nil) { v_30102 = elt(v_30102, 21); // rl_external
#ifdef RECORD_GET
             if (v_30102 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_30102 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_30102 == SPID_NOPROP) v_30102 = nil; }}
#endif
    goto v_29442;
    v_30102 = nil;
v_29442:
    goto v_29413;
    v_30102 = nil;
v_29413:
    goto v_29326;
    v_30102 = nil;
v_29326:
    goto v_29297;
    v_30102 = nil;
v_29297:
    goto v_29117;
v_29119:
    v_30102 = nil;
    goto v_29117;
    v_30102 = nil;
v_29117:
    if (v_30102 == nil) goto v_29115;
    v_30102 = lisp_true;
    goto v_28718;
v_29115:
    goto v_29493;
v_29489:
    v_30103 = v_30105;
    goto v_29490;
v_29491:
    v_30102 = elt(env, 2); // true
    goto v_29492;
v_29493:
    goto v_29489;
v_29490:
    goto v_29491;
v_29492:
    if (v_30103 == v_30102) goto v_29487;
    else goto v_29488;
v_29487:
    v_30102 = lisp_true;
    goto v_29486;
v_29488:
    goto v_29503;
v_29499:
    v_30103 = v_30105;
    goto v_29500;
v_29501:
    v_30102 = elt(env, 3); // false
    goto v_29502;
v_29503:
    goto v_29499;
v_29500:
    goto v_29501;
v_29502:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29486;
    v_30102 = nil;
v_29486:
    if (v_30102 == nil) goto v_29484;
    v_30102 = lisp_true;
    goto v_29482;
v_29484:
    goto v_29530;
v_29526:
    v_30103 = v_30105;
    goto v_29527;
v_29528:
    v_30102 = elt(env, 4); // or
    goto v_29529;
v_29530:
    goto v_29526;
v_29527:
    goto v_29528;
v_29529:
    if (v_30103 == v_30102) goto v_29524;
    else goto v_29525;
v_29524:
    v_30102 = lisp_true;
    goto v_29523;
v_29525:
    goto v_29540;
v_29536:
    v_30103 = v_30105;
    goto v_29537;
v_29538:
    v_30102 = elt(env, 5); // and
    goto v_29539;
v_29540:
    goto v_29536;
v_29537:
    goto v_29538;
v_29539:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29523;
    v_30102 = nil;
v_29523:
    if (v_30102 == nil) goto v_29521;
    v_30102 = lisp_true;
    goto v_29519;
v_29521:
    goto v_29551;
v_29547:
    v_30103 = v_30105;
    goto v_29548;
v_29549:
    v_30102 = elt(env, 6); // not
    goto v_29550;
v_29551:
    goto v_29547;
v_29548:
    goto v_29549;
v_29550:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29519;
    v_30102 = nil;
v_29519:
    if (v_30102 == nil) goto v_29517;
    v_30102 = lisp_true;
    goto v_29515;
v_29517:
    goto v_29566;
v_29562:
    v_30103 = v_30105;
    goto v_29563;
v_29564:
    v_30102 = elt(env, 7); // impl
    goto v_29565;
v_29566:
    goto v_29562;
v_29563:
    goto v_29564;
v_29565:
    if (v_30103 == v_30102) goto v_29560;
    else goto v_29561;
v_29560:
    v_30102 = lisp_true;
    goto v_29559;
v_29561:
    goto v_29580;
v_29576:
    v_30103 = v_30105;
    goto v_29577;
v_29578:
    v_30102 = elt(env, 8); // repl
    goto v_29579;
v_29580:
    goto v_29576;
v_29577:
    goto v_29578;
v_29579:
    if (v_30103 == v_30102) goto v_29574;
    else goto v_29575;
v_29574:
    v_30102 = lisp_true;
    goto v_29573;
v_29575:
    goto v_29590;
v_29586:
    v_30103 = v_30105;
    goto v_29587;
v_29588:
    v_30102 = elt(env, 9); // equiv
    goto v_29589;
v_29590:
    goto v_29586;
v_29587:
    goto v_29588;
v_29589:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29573;
    v_30102 = nil;
v_29573:
    goto v_29559;
    v_30102 = nil;
v_29559:
    goto v_29515;
    v_30102 = nil;
v_29515:
    if (v_30102 == nil) goto v_29513;
    v_30102 = lisp_true;
    goto v_29511;
v_29513:
    goto v_29609;
v_29605:
    v_30103 = v_30105;
    goto v_29606;
v_29607:
    v_30102 = elt(env, 10); // ex
    goto v_29608;
v_29609:
    goto v_29605;
v_29606:
    goto v_29607;
v_29608:
    if (v_30103 == v_30102) goto v_29603;
    else goto v_29604;
v_29603:
    v_30102 = lisp_true;
    goto v_29602;
v_29604:
    goto v_29619;
v_29615:
    v_30103 = v_30105;
    goto v_29616;
v_29617:
    v_30102 = elt(env, 11); // all
    goto v_29618;
v_29619:
    goto v_29615;
v_29616:
    goto v_29617;
v_29618:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29602;
    v_30102 = nil;
v_29602:
    if (v_30102 == nil) goto v_29600;
    v_30102 = lisp_true;
    goto v_29598;
v_29600:
    goto v_29638;
v_29634:
    v_30103 = v_30105;
    goto v_29635;
v_29636:
    v_30102 = elt(env, 12); // bex
    goto v_29637;
v_29638:
    goto v_29634;
v_29635:
    goto v_29636;
v_29637:
    if (v_30103 == v_30102) goto v_29632;
    else goto v_29633;
v_29632:
    v_30102 = lisp_true;
    goto v_29631;
v_29633:
    goto v_29648;
v_29644:
    v_30103 = v_30105;
    goto v_29645;
v_29646:
    v_30102 = elt(env, 13); // ball
    goto v_29647;
v_29648:
    goto v_29644;
v_29645:
    goto v_29646;
v_29647:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29631;
    v_30102 = nil;
v_29631:
    if (v_30102 == nil) goto v_29629;
    v_30102 = lisp_true;
    goto v_29627;
v_29629:
    v_30102 = v_30105;
    if (!symbolp(v_30102)) v_30102 = nil;
    else { v_30102 = qfastgets(v_30102);
           if (v_30102 != nil) { v_30102 = elt(v_30102, 21); // rl_external
#ifdef RECORD_GET
             if (v_30102 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_30102 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_30102 == SPID_NOPROP) v_30102 = nil; }}
#endif
    goto v_29627;
    v_30102 = nil;
v_29627:
    goto v_29598;
    v_30102 = nil;
v_29598:
    goto v_29511;
    v_30102 = nil;
v_29511:
    goto v_29482;
    v_30102 = nil;
v_29482:
    if (v_30102 == nil) goto v_29479;
    goto v_29670;
v_29666:
    v_30103 = v_30104;
    goto v_29667;
v_29668:
    v_30102 = elt(env, 2); // true
    goto v_29669;
v_29670:
    goto v_29666;
v_29667:
    goto v_29668;
v_29669:
    if (v_30103 == v_30102) goto v_29664;
    else goto v_29665;
v_29664:
    v_30102 = lisp_true;
    goto v_29663;
v_29665:
    goto v_29680;
v_29676:
    v_30103 = v_30104;
    goto v_29677;
v_29678:
    v_30102 = elt(env, 3); // false
    goto v_29679;
v_29680:
    goto v_29676;
v_29677:
    goto v_29678;
v_29679:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29663;
    v_30102 = nil;
v_29663:
    if (v_30102 == nil) goto v_29661;
    v_30102 = lisp_true;
    goto v_29659;
v_29661:
    goto v_29707;
v_29703:
    v_30103 = v_30104;
    goto v_29704;
v_29705:
    v_30102 = elt(env, 4); // or
    goto v_29706;
v_29707:
    goto v_29703;
v_29704:
    goto v_29705;
v_29706:
    if (v_30103 == v_30102) goto v_29701;
    else goto v_29702;
v_29701:
    v_30102 = lisp_true;
    goto v_29700;
v_29702:
    goto v_29717;
v_29713:
    v_30103 = v_30104;
    goto v_29714;
v_29715:
    v_30102 = elt(env, 5); // and
    goto v_29716;
v_29717:
    goto v_29713;
v_29714:
    goto v_29715;
v_29716:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29700;
    v_30102 = nil;
v_29700:
    if (v_30102 == nil) goto v_29698;
    v_30102 = lisp_true;
    goto v_29696;
v_29698:
    goto v_29728;
v_29724:
    v_30103 = v_30104;
    goto v_29725;
v_29726:
    v_30102 = elt(env, 6); // not
    goto v_29727;
v_29728:
    goto v_29724;
v_29725:
    goto v_29726;
v_29727:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29696;
    v_30102 = nil;
v_29696:
    if (v_30102 == nil) goto v_29694;
    v_30102 = lisp_true;
    goto v_29692;
v_29694:
    goto v_29743;
v_29739:
    v_30103 = v_30104;
    goto v_29740;
v_29741:
    v_30102 = elt(env, 7); // impl
    goto v_29742;
v_29743:
    goto v_29739;
v_29740:
    goto v_29741;
v_29742:
    if (v_30103 == v_30102) goto v_29737;
    else goto v_29738;
v_29737:
    v_30102 = lisp_true;
    goto v_29736;
v_29738:
    goto v_29757;
v_29753:
    v_30103 = v_30104;
    goto v_29754;
v_29755:
    v_30102 = elt(env, 8); // repl
    goto v_29756;
v_29757:
    goto v_29753;
v_29754:
    goto v_29755;
v_29756:
    if (v_30103 == v_30102) goto v_29751;
    else goto v_29752;
v_29751:
    v_30102 = lisp_true;
    goto v_29750;
v_29752:
    goto v_29767;
v_29763:
    v_30103 = v_30104;
    goto v_29764;
v_29765:
    v_30102 = elt(env, 9); // equiv
    goto v_29766;
v_29767:
    goto v_29763;
v_29764:
    goto v_29765;
v_29766:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29750;
    v_30102 = nil;
v_29750:
    goto v_29736;
    v_30102 = nil;
v_29736:
    goto v_29692;
    v_30102 = nil;
v_29692:
    if (v_30102 == nil) goto v_29690;
    v_30102 = lisp_true;
    goto v_29688;
v_29690:
    goto v_29786;
v_29782:
    v_30103 = v_30104;
    goto v_29783;
v_29784:
    v_30102 = elt(env, 10); // ex
    goto v_29785;
v_29786:
    goto v_29782;
v_29783:
    goto v_29784;
v_29785:
    if (v_30103 == v_30102) goto v_29780;
    else goto v_29781;
v_29780:
    v_30102 = lisp_true;
    goto v_29779;
v_29781:
    goto v_29796;
v_29792:
    v_30103 = v_30104;
    goto v_29793;
v_29794:
    v_30102 = elt(env, 11); // all
    goto v_29795;
v_29796:
    goto v_29792;
v_29793:
    goto v_29794;
v_29795:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29779;
    v_30102 = nil;
v_29779:
    if (v_30102 == nil) goto v_29777;
    v_30102 = lisp_true;
    goto v_29775;
v_29777:
    goto v_29815;
v_29811:
    v_30103 = v_30104;
    goto v_29812;
v_29813:
    v_30102 = elt(env, 12); // bex
    goto v_29814;
v_29815:
    goto v_29811;
v_29812:
    goto v_29813;
v_29814:
    if (v_30103 == v_30102) goto v_29809;
    else goto v_29810;
v_29809:
    v_30102 = lisp_true;
    goto v_29808;
v_29810:
    goto v_29825;
v_29821:
    v_30103 = v_30104;
    goto v_29822;
v_29823:
    v_30102 = elt(env, 13); // ball
    goto v_29824;
v_29825:
    goto v_29821;
v_29822:
    goto v_29823;
v_29824:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29808;
    v_30102 = nil;
v_29808:
    if (v_30102 == nil) goto v_29806;
    v_30102 = lisp_true;
    goto v_29804;
v_29806:
    v_30102 = v_30104;
    if (!symbolp(v_30102)) v_30102 = nil;
    else { v_30102 = qfastgets(v_30102);
           if (v_30102 != nil) { v_30102 = elt(v_30102, 21); // rl_external
#ifdef RECORD_GET
             if (v_30102 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_30102 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_30102 == SPID_NOPROP) v_30102 = nil; }}
#endif
    goto v_29804;
    v_30102 = nil;
v_29804:
    goto v_29775;
    v_30102 = nil;
v_29775:
    goto v_29688;
    v_30102 = nil;
v_29688:
    goto v_29659;
    v_30102 = nil;
v_29659:
    if (v_30102 == nil) goto v_29657;
    else goto v_29479;
v_29657:
    v_30102 = nil;
    goto v_28718;
v_29479:
    goto v_29843;
v_29839:
    v_30103 = v_30105;
    goto v_29840;
v_29841:
    v_30102 = v_30104;
    goto v_29842;
v_29843:
    goto v_29839;
v_29840:
    goto v_29841;
v_29842:
    if (equal(v_30103, v_30102)) goto v_29838;
    goto v_29851;
v_29847:
    v_30102 = v_30105;
    goto v_29848;
v_29849:
    v_30103 = v_30104;
    goto v_29850;
v_29851:
    goto v_29847;
v_29848:
    goto v_29849;
v_29850:
    {
        fn = elt(env, 15); // cl_ordopp
        return (*qfn2(fn))(fn, v_30102, v_30103);
    }
v_29838:
    goto v_29866;
v_29862:
    v_30103 = v_30105;
    goto v_29863;
v_29864:
    v_30102 = elt(env, 2); // true
    goto v_29865;
v_29866:
    goto v_29862;
v_29863:
    goto v_29864;
v_29865:
    if (v_30103 == v_30102) goto v_29860;
    else goto v_29861;
v_29860:
    v_30102 = lisp_true;
    goto v_29859;
v_29861:
    goto v_29876;
v_29872:
    v_30103 = v_30105;
    goto v_29873;
v_29874:
    v_30102 = elt(env, 3); // false
    goto v_29875;
v_29876:
    goto v_29872;
v_29873:
    goto v_29874;
v_29875:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29859;
    v_30102 = nil;
v_29859:
    if (v_30102 == nil) goto v_29857;
    v_30102 = lisp_true;
    goto v_28718;
v_29857:
    goto v_29893;
v_29889:
    v_30103 = v_30105;
    goto v_29890;
v_29891:
    v_30102 = elt(env, 10); // ex
    goto v_29892;
v_29893:
    goto v_29889;
v_29890:
    goto v_29891;
v_29892:
    if (v_30103 == v_30102) goto v_29887;
    else goto v_29888;
v_29887:
    v_30102 = lisp_true;
    goto v_29886;
v_29888:
    goto v_29903;
v_29899:
    v_30103 = v_30105;
    goto v_29900;
v_29901:
    v_30102 = elt(env, 11); // all
    goto v_29902;
v_29903:
    goto v_29899;
v_29900:
    goto v_29901;
v_29902:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29886;
    v_30102 = nil;
v_29886:
    if (v_30102 == nil) goto v_29884;
    goto v_29915;
v_29911:
    v_30102 = stack[-1];
    v_30102 = qcdr(v_30102);
    v_30103 = qcar(v_30102);
    goto v_29912;
v_29913:
    v_30102 = stack[0];
    v_30102 = qcdr(v_30102);
    v_30102 = qcar(v_30102);
    goto v_29914;
v_29915:
    goto v_29911;
v_29912:
    goto v_29913;
v_29914:
    if (equal(v_30103, v_30102)) goto v_29910;
    goto v_29931;
v_29927:
    v_30102 = stack[-1];
    v_30102 = qcdr(v_30102);
    v_30103 = qcar(v_30102);
    goto v_29928;
v_29929:
    v_30102 = stack[0];
    v_30102 = qcdr(v_30102);
    v_30102 = qcar(v_30102);
    goto v_29930;
v_29931:
    goto v_29927;
v_29928:
    goto v_29929;
v_29930:
    fn = elt(env, 16); // ordp
    v_30102 = (*qfn2(fn))(fn, v_30103, v_30102);
    env = stack[-2];
    if (v_30102 == nil) goto v_29924;
    else goto v_29925;
v_29924:
    v_30102 = nil;
    goto v_29923;
v_29925:
    goto v_29946;
v_29942:
    v_30102 = stack[-1];
    v_30102 = qcdr(v_30102);
    v_30103 = qcar(v_30102);
    goto v_29943;
v_29944:
    v_30102 = stack[0];
    v_30102 = qcdr(v_30102);
    v_30102 = qcar(v_30102);
    goto v_29945;
v_29946:
    goto v_29942;
v_29943:
    goto v_29944;
v_29945:
    v_30102 = Lneq(nil, v_30103, v_30102);
    goto v_29923;
    v_30102 = nil;
v_29923:
    v_30102 = (v_30102 == nil ? lisp_true : nil);
    goto v_28718;
v_29910:
    goto v_29961;
v_29957:
    v_30102 = stack[-1];
    v_30102 = qcdr(v_30102);
    v_30102 = qcdr(v_30102);
    v_30103 = qcar(v_30102);
    goto v_29958;
v_29959:
    v_30102 = stack[0];
    v_30102 = qcdr(v_30102);
    v_30102 = qcdr(v_30102);
    v_30102 = qcar(v_30102);
    goto v_29960;
v_29961:
    goto v_29957;
v_29958:
    goto v_29959;
v_29960:
    stack[-1] = v_30103;
    stack[0] = v_30102;
    goto v_28711;
    goto v_29882;
v_29884:
v_29882:
    goto v_29982;
v_29978:
    v_30103 = v_30105;
    goto v_29979;
v_29980:
    v_30102 = elt(env, 12); // bex
    goto v_29981;
v_29982:
    goto v_29978;
v_29979:
    goto v_29980;
v_29981:
    if (v_30103 == v_30102) goto v_29976;
    else goto v_29977;
v_29976:
    v_30102 = lisp_true;
    goto v_29975;
v_29977:
    goto v_29992;
v_29988:
    v_30103 = v_30105;
    goto v_29989;
v_29990:
    v_30102 = elt(env, 13); // ball
    goto v_29991;
v_29992:
    goto v_29988;
v_29989:
    goto v_29990;
v_29991:
    v_30102 = (v_30103 == v_30102 ? lisp_true : nil);
    goto v_29975;
    v_30102 = nil;
v_29975:
    if (v_30102 == nil) goto v_29973;
    goto v_30004;
v_30000:
    v_30102 = stack[-1];
    v_30102 = qcdr(v_30102);
    v_30103 = qcar(v_30102);
    goto v_30001;
v_30002:
    v_30102 = stack[0];
    v_30102 = qcdr(v_30102);
    v_30102 = qcar(v_30102);
    goto v_30003;
v_30004:
    goto v_30000;
v_30001:
    goto v_30002;
v_30003:
    if (equal(v_30103, v_30102)) goto v_29999;
    goto v_30020;
v_30016:
    v_30102 = stack[-1];
    v_30102 = qcdr(v_30102);
    v_30103 = qcar(v_30102);
    goto v_30017;
v_30018:
    v_30102 = stack[0];
    v_30102 = qcdr(v_30102);
    v_30102 = qcar(v_30102);
    goto v_30019;
v_30020:
    goto v_30016;
v_30017:
    goto v_30018;
v_30019:
    fn = elt(env, 16); // ordp
    v_30102 = (*qfn2(fn))(fn, v_30103, v_30102);
    env = stack[-2];
    if (v_30102 == nil) goto v_30013;
    else goto v_30014;
v_30013:
    v_30102 = nil;
    goto v_30012;
v_30014:
    goto v_30035;
v_30031:
    v_30102 = stack[-1];
    v_30102 = qcdr(v_30102);
    v_30103 = qcar(v_30102);
    goto v_30032;
v_30033:
    v_30102 = stack[0];
    v_30102 = qcdr(v_30102);
    v_30102 = qcar(v_30102);
    goto v_30034;
v_30035:
    goto v_30031;
v_30032:
    goto v_30033;
v_30034:
    v_30102 = Lneq(nil, v_30103, v_30102);
    goto v_30012;
    v_30102 = nil;
v_30012:
    v_30102 = (v_30102 == nil ? lisp_true : nil);
    goto v_28718;
v_29999:
    goto v_30049;
v_30045:
    v_30102 = stack[-1];
    v_30102 = qcdr(v_30102);
    v_30102 = qcdr(v_30102);
    v_30102 = qcdr(v_30102);
    v_30103 = qcar(v_30102);
    goto v_30046;
v_30047:
    v_30102 = stack[0];
    v_30102 = qcdr(v_30102);
    v_30102 = qcdr(v_30102);
    v_30102 = qcdr(v_30102);
    v_30102 = qcar(v_30102);
    goto v_30048;
v_30049:
    goto v_30045;
v_30046:
    goto v_30047;
v_30048:
    if (equal(v_30103, v_30102)) goto v_30044;
    goto v_30065;
v_30061:
    v_30102 = stack[-1];
    v_30102 = qcdr(v_30102);
    v_30102 = qcdr(v_30102);
    v_30102 = qcdr(v_30102);
    v_30103 = qcar(v_30102);
    goto v_30062;
v_30063:
    v_30102 = stack[0];
    v_30102 = qcdr(v_30102);
    v_30102 = qcdr(v_30102);
    v_30102 = qcdr(v_30102);
    v_30102 = qcar(v_30102);
    goto v_30064;
v_30065:
    goto v_30061;
v_30062:
    goto v_30063;
v_30064:
    stack[-1] = v_30103;
    stack[0] = v_30102;
    goto v_28711;
v_30044:
    goto v_30083;
v_30079:
    v_30102 = stack[-1];
    v_30102 = qcdr(v_30102);
    v_30102 = qcdr(v_30102);
    v_30103 = qcar(v_30102);
    goto v_30080;
v_30081:
    v_30102 = stack[0];
    v_30102 = qcdr(v_30102);
    v_30102 = qcdr(v_30102);
    v_30102 = qcar(v_30102);
    goto v_30082;
v_30083:
    goto v_30079;
v_30080:
    goto v_30081;
v_30082:
    stack[-1] = v_30103;
    stack[0] = v_30102;
    goto v_28711;
    goto v_29971;
v_29973:
v_29971:
    goto v_30097;
v_30093:
    v_30102 = stack[-1];
    v_30103 = qcdr(v_30102);
    goto v_30094;
v_30095:
    v_30102 = stack[0];
    v_30102 = qcdr(v_30102);
    goto v_30096;
v_30097:
    goto v_30093;
v_30094:
    goto v_30095;
v_30096:
    {
        fn = elt(env, 17); // cl_sordpl
        return (*qfn2(fn))(fn, v_30103, v_30102);
    }
v_28718:
    return onevalue(v_30102);
}



// Code for pasf_lnegrel

static LispObject CC_pasf_lnegrel(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28807, v_28808, v_28809;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_28809 = v_28712;
// end of prologue
    goto v_28722;
v_28718:
    v_28808 = v_28809;
    goto v_28719;
v_28720:
    v_28807 = elt(env, 1); // equal
    goto v_28721;
v_28722:
    goto v_28718;
v_28719:
    goto v_28720;
v_28721:
    if (v_28808 == v_28807) goto v_28716;
    else goto v_28717;
v_28716:
    v_28807 = elt(env, 2); // neq
    goto v_28715;
v_28717:
    goto v_28732;
v_28728:
    v_28808 = v_28809;
    goto v_28729;
v_28730:
    v_28807 = elt(env, 2); // neq
    goto v_28731;
v_28732:
    goto v_28728;
v_28729:
    goto v_28730;
v_28731:
    if (v_28808 == v_28807) goto v_28726;
    else goto v_28727;
v_28726:
    v_28807 = elt(env, 1); // equal
    goto v_28715;
v_28727:
    goto v_28742;
v_28738:
    v_28808 = v_28809;
    goto v_28739;
v_28740:
    v_28807 = elt(env, 3); // leq
    goto v_28741;
v_28742:
    goto v_28738;
v_28739:
    goto v_28740;
v_28741:
    if (v_28808 == v_28807) goto v_28736;
    else goto v_28737;
v_28736:
    v_28807 = elt(env, 4); // greaterp
    goto v_28715;
v_28737:
    goto v_28752;
v_28748:
    v_28808 = v_28809;
    goto v_28749;
v_28750:
    v_28807 = elt(env, 5); // lessp
    goto v_28751;
v_28752:
    goto v_28748;
v_28749:
    goto v_28750;
v_28751:
    if (v_28808 == v_28807) goto v_28746;
    else goto v_28747;
v_28746:
    v_28807 = elt(env, 6); // geq
    goto v_28715;
v_28747:
    goto v_28762;
v_28758:
    v_28808 = v_28809;
    goto v_28759;
v_28760:
    v_28807 = elt(env, 6); // geq
    goto v_28761;
v_28762:
    goto v_28758;
v_28759:
    goto v_28760;
v_28761:
    if (v_28808 == v_28807) goto v_28756;
    else goto v_28757;
v_28756:
    v_28807 = elt(env, 5); // lessp
    goto v_28715;
v_28757:
    goto v_28772;
v_28768:
    v_28808 = v_28809;
    goto v_28769;
v_28770:
    v_28807 = elt(env, 4); // greaterp
    goto v_28771;
v_28772:
    goto v_28768;
v_28769:
    goto v_28770;
v_28771:
    if (v_28808 == v_28807) goto v_28766;
    else goto v_28767;
v_28766:
    v_28807 = elt(env, 3); // leq
    goto v_28715;
v_28767:
    goto v_28782;
v_28778:
    v_28808 = v_28809;
    goto v_28779;
v_28780:
    v_28807 = elt(env, 7); // cong
    goto v_28781;
v_28782:
    goto v_28778;
v_28779:
    goto v_28780;
v_28781:
    if (v_28808 == v_28807) goto v_28776;
    else goto v_28777;
v_28776:
    v_28807 = elt(env, 8); // ncong
    goto v_28715;
v_28777:
    goto v_28792;
v_28788:
    v_28808 = v_28809;
    goto v_28789;
v_28790:
    v_28807 = elt(env, 8); // ncong
    goto v_28791;
v_28792:
    goto v_28788;
v_28789:
    goto v_28790;
v_28791:
    if (v_28808 == v_28807) goto v_28786;
    else goto v_28787;
v_28786:
    v_28807 = elt(env, 7); // cong
    goto v_28715;
v_28787:
    goto v_28804;
v_28800:
    v_28807 = elt(env, 9); // "pasf_lnegrel: unknown operator"
    goto v_28801;
v_28802:
    v_28808 = v_28809;
    goto v_28803;
v_28804:
    goto v_28800;
v_28801:
    goto v_28802;
v_28803:
    v_28807 = list2(v_28807, v_28808);
    env = stack[0];
    {
        fn = elt(env, 10); // rederr
        return (*qfn1(fn))(fn, v_28807);
    }
    v_28807 = nil;
v_28715:
    return onevalue(v_28807);
}



// Code for countof

static LispObject CC_countof(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_28757, v_28758;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_28713;
    stack[-1] = v_28712;
// end of prologue
    goto v_28723;
v_28719:
    v_28758 = stack[-1];
    goto v_28720;
v_28721:
    v_28757 = stack[0];
    goto v_28722;
v_28723:
    goto v_28719;
v_28720:
    goto v_28721;
v_28722:
    if (equal(v_28758, v_28757)) goto v_28717;
    else goto v_28718;
v_28717:
    v_28757 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28716;
v_28718:
    v_28757 = stack[0];
    if (!consp(v_28757)) goto v_28727;
    else goto v_28728;
v_28727:
    v_28757 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28716;
v_28728:
    goto v_28738;
v_28734:
    goto v_28744;
v_28740:
    v_28758 = stack[-1];
    goto v_28741;
v_28742:
    v_28757 = stack[0];
    v_28757 = qcar(v_28757);
    goto v_28743;
v_28744:
    goto v_28740;
v_28741:
    goto v_28742;
v_28743:
    stack[-2] = CC_countof(elt(env, 0), v_28758, v_28757);
    env = stack[-3];
    goto v_28735;
v_28736:
    goto v_28753;
v_28749:
    v_28758 = stack[-1];
    goto v_28750;
v_28751:
    v_28757 = stack[0];
    v_28757 = qcdr(v_28757);
    goto v_28752;
v_28753:
    goto v_28749;
v_28750:
    goto v_28751;
v_28752:
    v_28757 = CC_countof(elt(env, 0), v_28758, v_28757);
    goto v_28737;
v_28738:
    goto v_28734;
v_28735:
    goto v_28736;
v_28737:
    {
        LispObject v_28762 = stack[-2];
        return plus2(v_28762, v_28757);
    }
    v_28757 = nil;
v_28716:
    return onevalue(v_28757);
}



// Code for matsm!*

static LispObject CC_matsmH(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_28718, v_28719;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_28718 = v_28713;
    v_28719 = v_28712;
// end of prologue
    v_28718 = v_28719;
    fn = elt(env, 1); // matsm
    v_28718 = (*qfn1(fn))(fn, v_28718);
    env = stack[0];
    {
        fn = elt(env, 2); // matsm!*1
        return (*qfn1(fn))(fn, v_28718);
    }
}



// Code for vdplsort

static LispObject CC_vdplsort(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28722, v_28723;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28722 = v_28712;
// end of prologue
    goto v_28719;
v_28715:
    v_28723 = v_28722;
    goto v_28716;
v_28717:
    v_28722 = elt(env, 1); // vdpvevlcomp
    goto v_28718;
v_28719:
    goto v_28715;
v_28716:
    goto v_28717;
v_28718:
    {
        fn = elt(env, 2); // sort
        return (*qfn2(fn))(fn, v_28723, v_28722);
    }
}



// Code for exp!*

static LispObject CC_expH(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28722, v_28723;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28722 = v_28712;
// end of prologue
    goto v_28719;
v_28715:
    v_28723 = v_28722;
    goto v_28716;
v_28717:
    v_28722 = qvalue(elt(env, 1)); // !:bprec!:
    goto v_28718;
v_28719:
    goto v_28715;
v_28716:
    goto v_28717;
v_28718:
    {
        fn = elt(env, 2); // exp!:
        return (*qfn2(fn))(fn, v_28723, v_28722);
    }
}



// Code for physopsubs

static LispObject CC_physopsubs(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28834, v_28835, v_28836;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_28712;
// end of prologue
// Binding alglist!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = nil; // alglist!*
    v_28834 = nil;
    v_28834 = ncons(v_28834);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_28834; // alglist!*
    v_28834 = stack[-1];
    fn = elt(env, 11); // physop2sq
    v_28834 = (*qfn1(fn))(fn, v_28834);
    env = stack[-3];
    stack[-1] = v_28834;
    v_28834 = qvalue(elt(env, 3)); // physoplist!*
    stack[0] = v_28834;
v_28727:
    v_28834 = stack[0];
    if (v_28834 == nil) goto v_28731;
    else goto v_28732;
v_28731:
    goto v_28726;
v_28732:
    v_28834 = stack[0];
    v_28834 = qcar(v_28834);
    v_28836 = v_28834;
    goto v_28743;
v_28739:
    v_28835 = v_28836;
    goto v_28740;
v_28741:
    v_28834 = elt(env, 4); // rtype
    goto v_28742;
v_28743:
    goto v_28739;
v_28740:
    goto v_28741;
v_28742:
    v_28834 = Lremprop(nil, v_28835, v_28834);
    env = stack[-3];
    goto v_28753;
v_28747:
    goto v_28748;
v_28749:
    v_28835 = elt(env, 5); // simpfn
    goto v_28750;
v_28751:
    v_28834 = elt(env, 6); // simpiden
    goto v_28752;
v_28753:
    goto v_28747;
v_28748:
    goto v_28749;
v_28750:
    goto v_28751;
v_28752:
    v_28834 = Lputprop(nil, 3, v_28836, v_28835, v_28834);
    env = stack[-3];
    v_28834 = stack[0];
    v_28834 = qcdr(v_28834);
    stack[0] = v_28834;
    goto v_28727;
v_28726:
    goto v_28764;
v_28760:
    v_28835 = elt(env, 7); // (dot)
    goto v_28761;
v_28762:
    v_28834 = elt(env, 8); // physopfn
    goto v_28763;
v_28764:
    goto v_28760;
v_28761:
    goto v_28762;
v_28763:
    v_28834 = Lremflag(nil, v_28835, v_28834);
    env = stack[-3];
    goto v_28774;
v_28768:
    v_28836 = elt(env, 9); // dot
    goto v_28769;
v_28770:
    v_28835 = elt(env, 5); // simpfn
    goto v_28771;
v_28772:
    v_28834 = elt(env, 6); // simpiden
    goto v_28773;
v_28774:
    goto v_28768;
v_28769:
    goto v_28770;
v_28771:
    goto v_28772;
v_28773:
    v_28834 = Lputprop(nil, 3, v_28836, v_28835, v_28834);
    env = stack[-3];
    v_28834 = stack[-1];
    fn = elt(env, 12); // subs2
    v_28834 = (*qfn1(fn))(fn, v_28834);
    env = stack[-3];
    stack[-1] = v_28834;
    v_28834 = stack[-1];
    fn = elt(env, 13); // !*q2a
    v_28834 = (*qfn1(fn))(fn, v_28834);
    env = stack[-3];
    stack[-1] = v_28834;
    v_28834 = qvalue(elt(env, 3)); // physoplist!*
    stack[0] = v_28834;
v_28785:
    v_28834 = stack[0];
    if (v_28834 == nil) goto v_28789;
    else goto v_28790;
v_28789:
    goto v_28784;
v_28790:
    v_28834 = stack[0];
    v_28834 = qcar(v_28834);
    v_28836 = v_28834;
    goto v_28801;
v_28797:
    v_28835 = v_28836;
    goto v_28798;
v_28799:
    v_28834 = elt(env, 5); // simpfn
    goto v_28800;
v_28801:
    goto v_28797;
v_28798:
    goto v_28799;
v_28800:
    v_28834 = Lremprop(nil, v_28835, v_28834);
    env = stack[-3];
    goto v_28811;
v_28805:
    goto v_28806;
v_28807:
    v_28835 = elt(env, 4); // rtype
    goto v_28808;
v_28809:
    v_28834 = elt(env, 10); // physop
    goto v_28810;
v_28811:
    goto v_28805;
v_28806:
    goto v_28807;
v_28808:
    goto v_28809;
v_28810:
    v_28834 = Lputprop(nil, 3, v_28836, v_28835, v_28834);
    env = stack[-3];
    v_28834 = stack[0];
    v_28834 = qcdr(v_28834);
    stack[0] = v_28834;
    goto v_28785;
v_28784:
    goto v_28822;
v_28818:
    v_28835 = elt(env, 9); // dot
    goto v_28819;
v_28820:
    v_28834 = elt(env, 5); // simpfn
    goto v_28821;
v_28822:
    goto v_28818;
v_28819:
    goto v_28820;
v_28821:
    v_28834 = Lremprop(nil, v_28835, v_28834);
    env = stack[-3];
    goto v_28830;
v_28826:
    v_28835 = elt(env, 7); // (dot)
    goto v_28827;
v_28828:
    v_28834 = elt(env, 8); // physopfn
    goto v_28829;
v_28830:
    goto v_28826;
v_28827:
    goto v_28828;
v_28829:
    v_28834 = Lflag(nil, v_28835, v_28834);
    v_28834 = stack[-1];
    ;}  // end of a binding scope
    return onevalue(v_28834);
}



// Code for free

static LispObject CC_free(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28730;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_28712;
// end of prologue
    v_28730 = stack[0];
    v_28730 = qcdr(v_28730);
    v_28730 = qcar(v_28730);
    fn = elt(env, 1); // freeind
    v_28730 = (*qfn1(fn))(fn, v_28730);
    env = stack[-1];
    if (v_28730 == nil) goto v_28716;
    else goto v_28717;
v_28716:
    v_28730 = nil;
    goto v_28715;
v_28717:
    v_28730 = stack[0];
    v_28730 = qcdr(v_28730);
    v_28730 = qcdr(v_28730);
    v_28730 = qcar(v_28730);
    {
        fn = elt(env, 1); // freeind
        return (*qfn1(fn))(fn, v_28730);
    }
    v_28730 = nil;
v_28715:
    return onevalue(v_28730);
}



// Code for njets

static LispObject CC_njets(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_28731, v_28732;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_28731 = v_28713;
    v_28732 = v_28712;
// end of prologue
    goto v_28720;
v_28716:
    stack[-1] = v_28731;
    goto v_28717;
v_28718:
    goto v_28727;
v_28723:
    stack[0] = v_28731;
    goto v_28724;
v_28725:
    v_28731 = v_28732;
    v_28731 = sub1(v_28731);
    env = stack[-2];
    goto v_28726;
v_28727:
    goto v_28723;
v_28724:
    goto v_28725;
v_28726:
    v_28731 = plus2(stack[0], v_28731);
    env = stack[-2];
    goto v_28719;
v_28720:
    goto v_28716;
v_28717:
    goto v_28718;
v_28719:
    {
        LispObject v_28735 = stack[-1];
        fn = elt(env, 1); // combin
        return (*qfn2(fn))(fn, v_28735, v_28731);
    }
}



// Code for simpsqrt2

static LispObject CC_simpsqrt2(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28761, v_28762;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_28712;
// end of prologue
    v_28761 = stack[0];
    fn = elt(env, 3); // minusf
    v_28761 = (*qfn1(fn))(fn, v_28761);
    env = stack[-1];
    if (v_28761 == nil) goto v_28717;
    goto v_28729;
v_28725:
    v_28762 = stack[0];
    goto v_28726;
v_28727:
    v_28761 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_28728;
v_28729:
    goto v_28725;
v_28726:
    goto v_28727;
v_28728:
    fn = elt(env, 4); // iequal
    v_28761 = (*qfn2(fn))(fn, v_28762, v_28761);
    env = stack[-1];
    if (v_28761 == nil) goto v_28723;
    v_28761 = qvalue(elt(env, 1)); // gaussiani
    goto v_28721;
v_28723:
    v_28761 = stack[0];
    fn = elt(env, 5); // negf
    v_28761 = (*qfn1(fn))(fn, v_28761);
    env = stack[-1];
    v_28762 = v_28761;
    v_28761 = v_28762;
    if (is_number(v_28761)) goto v_28743;
    else goto v_28744;
v_28743:
    goto v_28751;
v_28747:
    stack[0] = qvalue(elt(env, 1)); // gaussiani
    goto v_28748;
v_28749:
    v_28761 = v_28762;
    fn = elt(env, 6); // simpsqrt3
    v_28761 = (*qfn1(fn))(fn, v_28761);
    env = stack[-1];
    goto v_28750;
v_28751:
    goto v_28747;
v_28748:
    goto v_28749;
v_28750:
    {
        LispObject v_28764 = stack[0];
        fn = elt(env, 7); // multf
        return (*qfn2(fn))(fn, v_28764, v_28761);
    }
v_28744:
    v_28761 = stack[0];
    {
        fn = elt(env, 6); // simpsqrt3
        return (*qfn1(fn))(fn, v_28761);
    }
    goto v_28721;
    v_28761 = nil;
v_28721:
    goto v_28715;
v_28717:
    v_28761 = stack[0];
    {
        fn = elt(env, 6); // simpsqrt3
        return (*qfn1(fn))(fn, v_28761);
    }
    v_28761 = nil;
v_28715:
    return onevalue(v_28761);
}



// Code for add!-factor

static LispObject CC_addKfactor(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_28779, v_28780, v_28781;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28713;
    stack[-1] = v_28712;
// end of prologue
    v_28779 = stack[0];
    v_28779 = Lconsp(nil, v_28779);
    env = stack[-2];
    if (v_28779 == nil) goto v_28718;
    goto v_28730;
v_28726:
    v_28780 = stack[-1];
    goto v_28727;
v_28728:
    v_28779 = stack[0];
    v_28779 = qcar(v_28779);
    v_28779 = qcar(v_28779);
    goto v_28729;
v_28730:
    goto v_28726;
v_28727:
    goto v_28728;
v_28729:
    v_28779 = (LispObject)greaterp2(v_28780, v_28779);
    v_28779 = v_28779 ? lisp_true : nil;
    env = stack[-2];
    if (v_28779 == nil) goto v_28724;
    v_28779 = nil;
    goto v_28722;
v_28724:
    goto v_28742;
v_28738:
    v_28780 = stack[-1];
    goto v_28739;
v_28740:
    v_28779 = stack[0];
    goto v_28741;
v_28742:
    goto v_28738;
v_28739:
    goto v_28740;
v_28741:
    v_28779 = Lassoc(nil, v_28780, v_28779);
    goto v_28722;
    v_28779 = nil;
v_28722:
    goto v_28716;
v_28718:
    v_28779 = nil;
    goto v_28716;
    v_28779 = nil;
v_28716:
    v_28780 = v_28779;
    v_28779 = v_28780;
    if (v_28779 == nil) goto v_28753;
    goto v_28760;
v_28756:
    stack[-1] = v_28780;
    goto v_28757;
v_28758:
    v_28779 = v_28780;
    v_28779 = qcdr(v_28779);
    v_28779 = add1(v_28779);
    env = stack[-2];
    goto v_28759;
v_28760:
    goto v_28756;
v_28757:
    goto v_28758;
v_28759:
    v_28779 = Lrplacd(nil, stack[-1], v_28779);
    v_28779 = stack[0];
    goto v_28751;
v_28753:
    goto v_28775;
v_28769:
    v_28781 = stack[-1];
    goto v_28770;
v_28771:
    v_28780 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28772;
v_28773:
    v_28779 = stack[0];
    goto v_28774;
v_28775:
    goto v_28769;
v_28770:
    goto v_28771;
v_28772:
    goto v_28773;
v_28774:
    return acons(v_28781, v_28780, v_28779);
    v_28779 = nil;
v_28751:
    return onevalue(v_28779);
}



// Code for bfminus

static LispObject CC_bfminus(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28725, v_28726;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28726 = v_28712;
// end of prologue
    v_28725 = v_28726;
    if (!consp(v_28725)) goto v_28716;
    else goto v_28717;
v_28716:
    v_28725 = v_28726;
    return negate(v_28725);
v_28717:
    v_28725 = v_28726;
    {
        fn = elt(env, 1); // minus!:
        return (*qfn1(fn))(fn, v_28725);
    }
    v_28725 = nil;
    return onevalue(v_28725);
}



// Code for domainp_list

static LispObject CC_domainp_list(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28745, v_28746;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28745 = v_28712;
// end of prologue
v_28711:
    v_28746 = v_28745;
    if (v_28746 == nil) goto v_28716;
    else goto v_28717;
v_28716:
    v_28745 = lisp_true;
    goto v_28715;
v_28717:
    v_28746 = v_28745;
    v_28746 = qcar(v_28746);
    if (!consp(v_28746)) goto v_28728;
    else goto v_28729;
v_28728:
    v_28746 = lisp_true;
    goto v_28727;
v_28729:
    v_28746 = v_28745;
    v_28746 = qcar(v_28746);
    v_28746 = qcar(v_28746);
    v_28746 = (consp(v_28746) ? nil : lisp_true);
    goto v_28727;
    v_28746 = nil;
v_28727:
    if (v_28746 == nil) goto v_28725;
    v_28745 = qcdr(v_28745);
    goto v_28711;
v_28725:
    v_28745 = nil;
    goto v_28723;
    v_28745 = nil;
v_28723:
    goto v_28715;
    v_28745 = nil;
v_28715:
    return onevalue(v_28745);
}



// Code for get!-new!-prime

static LispObject CC_getKnewKprime(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28805, v_28806;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_28712;
// end of prologue
    v_28805 = qvalue(elt(env, 1)); // !*force!-prime
    if (v_28805 == nil) goto v_28717;
    v_28805 = qvalue(elt(env, 1)); // !*force!-prime
    goto v_28715;
v_28717:
    stack[-3] = nil;
    v_28805 = stack[-2];
    stack[-1] = v_28805;
v_28731:
    v_28805 = stack[-1];
    if (v_28805 == nil) goto v_28735;
    else goto v_28736;
v_28735:
    goto v_28730;
v_28736:
    v_28805 = stack[-1];
    v_28805 = qcar(v_28805);
    stack[0] = v_28805;
    goto v_28751;
v_28747:
    v_28806 = stack[0];
    goto v_28748;
v_28749:
    v_28805 = (LispObject)512+TAG_FIXNUM; // 32
    goto v_28750;
v_28751:
    goto v_28747;
v_28748:
    goto v_28749;
v_28750:
    v_28805 = (LispObject)lessp2(v_28806, v_28805);
    v_28805 = v_28805 ? lisp_true : nil;
    env = stack[-4];
    if (v_28805 == nil) goto v_28745;
    goto v_28759;
v_28755:
    v_28806 = stack[0];
    goto v_28756;
v_28757:
    v_28805 = stack[-3];
    goto v_28758;
v_28759:
    goto v_28755;
v_28756:
    goto v_28757;
v_28758:
    v_28805 = cons(v_28806, v_28805);
    env = stack[-4];
    stack[-3] = v_28805;
    goto v_28743;
v_28745:
v_28743:
    v_28805 = stack[-1];
    v_28805 = qcdr(v_28805);
    stack[-1] = v_28805;
    goto v_28731;
v_28730:
v_28726:
    v_28805 = stack[-3];
    fn = elt(env, 5); // random!-teeny!-prime
    v_28805 = (*qfn1(fn))(fn, v_28805);
    env = stack[-4];
    stack[0] = v_28805;
    if (v_28805 == nil) goto v_28766;
    else goto v_28767;
v_28766:
    fn = elt(env, 6); // random!-small!-prime
    v_28805 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[0] = v_28805;
    v_28805 = elt(env, 3); // all
    stack[-3] = v_28805;
    goto v_28765;
v_28767:
    goto v_28779;
v_28775:
    v_28806 = stack[0];
    goto v_28776;
v_28777:
    v_28805 = stack[-3];
    goto v_28778;
v_28779:
    goto v_28775;
v_28776:
    goto v_28777;
v_28778:
    v_28805 = cons(v_28806, v_28805);
    env = stack[-4];
    stack[-3] = v_28805;
    goto v_28765;
v_28765:
    goto v_28791;
v_28787:
    v_28806 = stack[0];
    goto v_28788;
v_28789:
    v_28805 = stack[-2];
    goto v_28790;
v_28791:
    goto v_28787;
v_28788:
    goto v_28789;
v_28790:
    v_28805 = Lmember(nil, v_28806, v_28805);
    if (v_28805 == nil) goto v_28786;
    else goto v_28784;
v_28786:
    goto v_28801;
v_28797:
    v_28806 = stack[0];
    goto v_28798;
v_28799:
    v_28805 = qvalue(elt(env, 4)); // smallest!-prime
    goto v_28800;
v_28801:
    goto v_28797;
v_28798:
    goto v_28799;
v_28800:
    v_28805 = (LispObject)lesseq2(v_28806, v_28805);
    v_28805 = v_28805 ? lisp_true : nil;
    env = stack[-4];
    if (v_28805 == nil) goto v_28795;
    else goto v_28784;
v_28795:
    goto v_28785;
v_28784:
    goto v_28726;
v_28785:
    v_28805 = stack[0];
    goto v_28715;
    v_28805 = nil;
v_28715:
    return onevalue(v_28805);
}



// Code for janettreeinsert

static LispObject CC_janettreeinsert(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28997, v_28998, v_28999;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_28712;
// end of prologue
    goto v_28728;
v_28724:
    v_28998 = stack[-7];
    goto v_28725;
v_28726:
    v_28997 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28727;
v_28728:
    goto v_28724;
v_28725:
    goto v_28726;
v_28727:
    v_28997 = *(LispObject *)((char *)v_28998 + (CELL-TAG_VECTOR) + (((intptr_t)v_28997-TAG_FIXNUM)/(16/CELL)));
    v_28997 = qcar(v_28997);
    stack[-3] = v_28997;
    goto v_28737;
v_28733:
    v_28998 = stack[-3];
    goto v_28734;
v_28735:
    v_28997 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28736;
v_28737:
    goto v_28733;
v_28734:
    goto v_28735;
v_28736:
    v_28997 = *(LispObject *)((char *)v_28998 + (CELL-TAG_VECTOR) + (((intptr_t)v_28997-TAG_FIXNUM)/(16/CELL)));
    stack[-6] = v_28997;
    v_28997 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_28997;
    v_28997 = qvalue(elt(env, 2)); // fluidbibasisjanettreerootnode
    if (v_28997 == nil) goto v_28744;
    else goto v_28745;
v_28744:
    goto v_28754;
v_28748:
    v_28999 = stack[-6];
    goto v_28749;
v_28750:
    v_28998 = stack[-8];
    goto v_28751;
v_28752:
    v_28997 = stack[-7];
    goto v_28753;
v_28754:
    goto v_28748;
v_28749:
    goto v_28750;
v_28751:
    goto v_28752;
v_28753:
    fn = elt(env, 3); // janettreenodebuild
    v_28997 = (*qfnn(fn))(fn, 3, v_28999, v_28998, v_28997);
    env = stack[-9];
    qvalue(elt(env, 2)) = v_28997; // fluidbibasisjanettreerootnode
    goto v_28743;
v_28745:
    v_28997 = qvalue(elt(env, 2)); // fluidbibasisjanettreerootnode
    stack[-5] = v_28997;
v_28764:
    goto v_28774;
v_28770:
    v_28998 = stack[-6];
    goto v_28771;
v_28772:
    v_28997 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28773;
v_28774:
    goto v_28770;
v_28771:
    goto v_28772;
v_28773:
    v_28997 = (LispObject)greaterp2(v_28998, v_28997);
    v_28997 = v_28997 ? lisp_true : nil;
    env = stack[-9];
    if (v_28997 == nil) goto v_28767;
    else goto v_28768;
v_28767:
    goto v_28763;
v_28768:
v_28780:
    v_28997 = stack[-5];
    if (v_28997 == nil) goto v_28783;
    goto v_28794;
v_28790:
    v_28997 = stack[-5];
    v_28997 = qcar(v_28997);
    stack[0] = qcar(v_28997);
    goto v_28791;
v_28792:
    goto v_28803;
v_28799:
    v_28998 = stack[-3];
    goto v_28800;
v_28801:
    v_28997 = stack[-8];
    goto v_28802;
v_28803:
    goto v_28799;
v_28800:
    goto v_28801;
v_28802:
    fn = elt(env, 4); // monomgetvariabledegree
    v_28997 = (*qfn2(fn))(fn, v_28998, v_28997);
    env = stack[-9];
    goto v_28793;
v_28794:
    goto v_28790;
v_28791:
    goto v_28792;
v_28793:
    v_28997 = (LispObject)lessp2(stack[0], v_28997);
    v_28997 = v_28997 ? lisp_true : nil;
    env = stack[-9];
    if (v_28997 == nil) goto v_28783;
    v_28997 = stack[-5];
    v_28997 = qcdr(v_28997);
    v_28997 = qcar(v_28997);
    if (v_28997 == nil) goto v_28783;
    goto v_28784;
v_28783:
    goto v_28779;
v_28784:
    v_28997 = stack[-5];
    v_28997 = qcdr(v_28997);
    v_28997 = qcar(v_28997);
    stack[-5] = v_28997;
    goto v_28780;
v_28779:
    v_28997 = stack[-5];
    if (v_28997 == nil) goto v_28818;
    goto v_28827;
v_28823:
    v_28997 = stack[-5];
    v_28997 = qcar(v_28997);
    stack[0] = qcar(v_28997);
    goto v_28824;
v_28825:
    goto v_28836;
v_28832:
    v_28998 = stack[-3];
    goto v_28833;
v_28834:
    v_28997 = stack[-8];
    goto v_28835;
v_28836:
    goto v_28832;
v_28833:
    goto v_28834;
v_28835:
    fn = elt(env, 4); // monomgetvariabledegree
    v_28997 = (*qfn2(fn))(fn, v_28998, v_28997);
    env = stack[-9];
    goto v_28826;
v_28827:
    goto v_28823;
v_28824:
    goto v_28825;
v_28826:
    v_28997 = (LispObject)greaterp2(stack[0], v_28997);
    v_28997 = v_28997 ? lisp_true : nil;
    env = stack[-9];
    if (v_28997 == nil) goto v_28818;
    goto v_28846;
v_28840:
    v_28999 = stack[-6];
    goto v_28841;
v_28842:
    v_28998 = stack[-8];
    goto v_28843;
v_28844:
    v_28997 = stack[-7];
    goto v_28845;
v_28846:
    goto v_28840;
v_28841:
    goto v_28842;
v_28843:
    goto v_28844;
v_28845:
    fn = elt(env, 3); // janettreenodebuild
    v_28997 = (*qfnn(fn))(fn, 3, v_28999, v_28998, v_28997);
    env = stack[-9];
    stack[-4] = v_28997;
    v_28997 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_28997;
    goto v_28856;
v_28852:
    v_28997 = stack[-5];
    stack[-2] = qcdr(v_28997);
    goto v_28853;
v_28854:
    goto v_28866;
v_28860:
    v_28997 = stack[-5];
    v_28997 = qcar(v_28997);
    stack[-1] = qcar(v_28997);
    goto v_28861;
v_28862:
    v_28997 = stack[-5];
    v_28997 = qcar(v_28997);
    stack[0] = qcdr(v_28997);
    goto v_28863;
v_28864:
    goto v_28878;
v_28874:
    v_28997 = stack[-5];
    v_28997 = qcdr(v_28997);
    v_28998 = qcar(v_28997);
    goto v_28875;
v_28876:
    v_28997 = stack[-5];
    v_28997 = qcdr(v_28997);
    v_28997 = qcdr(v_28997);
    goto v_28877;
v_28878:
    goto v_28874;
v_28875:
    goto v_28876;
v_28877:
    v_28997 = cons(v_28998, v_28997);
    env = stack[-9];
    goto v_28865;
v_28866:
    goto v_28860;
v_28861:
    goto v_28862;
v_28863:
    goto v_28864;
v_28865:
    v_28997 = acons(stack[-1], stack[0], v_28997);
    env = stack[-9];
    goto v_28855;
v_28856:
    goto v_28852;
v_28853:
    goto v_28854;
v_28855:
    fn = elt(env, 5); // setcar
    v_28997 = (*qfn2(fn))(fn, stack[-2], v_28997);
    env = stack[-9];
    goto v_28890;
v_28886:
    v_28997 = stack[-5];
    v_28998 = qcdr(v_28997);
    goto v_28887;
v_28888:
    v_28997 = stack[-4];
    v_28997 = qcdr(v_28997);
    v_28997 = qcdr(v_28997);
    goto v_28889;
v_28890:
    goto v_28886;
v_28887:
    goto v_28888;
v_28889:
    fn = elt(env, 6); // setcdr
    v_28997 = (*qfn2(fn))(fn, v_28998, v_28997);
    env = stack[-9];
    goto v_28901;
v_28897:
    v_28997 = stack[-5];
    v_28998 = qcar(v_28997);
    goto v_28898;
v_28899:
    v_28997 = stack[-4];
    v_28997 = qcar(v_28997);
    v_28997 = qcar(v_28997);
    goto v_28900;
v_28901:
    goto v_28897;
v_28898:
    goto v_28899;
v_28900:
    fn = elt(env, 5); // setcar
    v_28997 = (*qfn2(fn))(fn, v_28998, v_28997);
    env = stack[-9];
    goto v_28912;
v_28908:
    v_28997 = stack[-5];
    v_28998 = qcar(v_28997);
    goto v_28909;
v_28910:
    v_28997 = stack[-4];
    v_28997 = qcar(v_28997);
    v_28997 = qcdr(v_28997);
    goto v_28911;
v_28912:
    goto v_28908;
v_28909:
    goto v_28910;
v_28911:
    fn = elt(env, 6); // setcdr
    v_28997 = (*qfn2(fn))(fn, v_28998, v_28997);
    env = stack[-9];
    goto v_28816;
v_28818:
    v_28997 = stack[-5];
    if (v_28997 == nil) goto v_28920;
    goto v_28932;
v_28928:
    v_28997 = stack[-5];
    v_28997 = qcar(v_28997);
    stack[0] = qcar(v_28997);
    goto v_28929;
v_28930:
    goto v_28941;
v_28937:
    v_28998 = stack[-3];
    goto v_28938;
v_28939:
    v_28997 = stack[-8];
    goto v_28940;
v_28941:
    goto v_28937;
v_28938:
    goto v_28939;
v_28940:
    fn = elt(env, 4); // monomgetvariabledegree
    v_28997 = (*qfn2(fn))(fn, v_28998, v_28997);
    env = stack[-9];
    goto v_28931;
v_28932:
    goto v_28928;
v_28929:
    goto v_28930;
v_28931:
    if (equal(stack[0], v_28997)) goto v_28926;
    else goto v_28927;
v_28926:
    v_28997 = stack[-5];
    v_28997 = qcdr(v_28997);
    v_28997 = qcdr(v_28997);
    goto v_28925;
v_28927:
    v_28997 = nil;
    goto v_28925;
    v_28997 = nil;
v_28925:
    if (v_28997 == nil) goto v_28920;
    goto v_28955;
v_28951:
    stack[0] = stack[-6];
    goto v_28952;
v_28953:
    goto v_28962;
v_28958:
    v_28998 = stack[-3];
    goto v_28959;
v_28960:
    v_28997 = stack[-8];
    goto v_28961;
v_28962:
    goto v_28958;
v_28959:
    goto v_28960;
v_28961:
    fn = elt(env, 4); // monomgetvariabledegree
    v_28997 = (*qfn2(fn))(fn, v_28998, v_28997);
    env = stack[-9];
    goto v_28954;
v_28955:
    goto v_28951;
v_28952:
    goto v_28953;
v_28954:
    v_28997 = difference2(stack[0], v_28997);
    env = stack[-9];
    stack[-6] = v_28997;
    v_28997 = stack[-8];
    v_28997 = add1(v_28997);
    env = stack[-9];
    stack[-8] = v_28997;
    v_28997 = stack[-5];
    v_28997 = qcdr(v_28997);
    v_28997 = qcdr(v_28997);
    stack[-5] = v_28997;
    goto v_28816;
v_28920:
    v_28997 = stack[-5];
    if (v_28997 == nil) goto v_28972;
    goto v_28979;
v_28975:
    v_28997 = stack[-5];
    stack[0] = qcdr(v_28997);
    goto v_28976;
v_28977:
    goto v_28989;
v_28983:
    v_28999 = stack[-6];
    goto v_28984;
v_28985:
    v_28998 = stack[-8];
    goto v_28986;
v_28987:
    v_28997 = stack[-7];
    goto v_28988;
v_28989:
    goto v_28983;
v_28984:
    goto v_28985;
v_28986:
    goto v_28987;
v_28988:
    fn = elt(env, 3); // janettreenodebuild
    v_28997 = (*qfnn(fn))(fn, 3, v_28999, v_28998, v_28997);
    env = stack[-9];
    goto v_28978;
v_28979:
    goto v_28975;
v_28976:
    goto v_28977;
v_28978:
    fn = elt(env, 5); // setcar
    v_28997 = (*qfn2(fn))(fn, stack[0], v_28997);
    env = stack[-9];
    v_28997 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_28997;
    goto v_28816;
v_28972:
v_28816:
    goto v_28764;
v_28763:
    goto v_28743;
v_28743:
    v_28997 = nil;
    return onevalue(v_28997);
}



// Code for ofsf_smmkatl!-and1

static LispObject CC_ofsf_smmkatlKand1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28893, v_28894, v_28895;
    LispObject fn;
    LispObject v_28714, v_28713, v_28712;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_smmkatl-and1");
    va_start(aa, nargs);
    v_28712 = va_arg(aa, LispObject);
    v_28713 = va_arg(aa, LispObject);
    v_28714 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_28714,v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_28712,v_28713,v_28714);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_28714;
    stack[0] = v_28713;
    stack[-6] = v_28712;
// end of prologue
    goto v_28726;
v_28722:
    v_28893 = stack[0];
    v_28894 = qcar(v_28893);
    goto v_28723;
v_28724:
    v_28893 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28725;
v_28726:
    goto v_28722;
v_28723:
    goto v_28724;
v_28725:
    v_28893 = cons(v_28894, v_28893);
    env = stack[-8];
    stack[-7] = v_28893;
    v_28893 = stack[0];
    v_28893 = qcdr(v_28893);
    stack[-4] = v_28893;
v_28735:
    v_28893 = stack[-4];
    if (v_28893 == nil) goto v_28741;
    else goto v_28742;
v_28741:
    v_28893 = nil;
    goto v_28734;
v_28742:
    v_28893 = stack[-4];
    v_28893 = qcar(v_28893);
    stack[0] = v_28893;
    goto v_28756;
v_28752:
    v_28893 = stack[0];
    v_28894 = qcar(v_28893);
    goto v_28753;
v_28754:
    v_28893 = stack[-5];
    goto v_28755;
v_28756:
    goto v_28752;
v_28753:
    goto v_28754;
v_28755:
    if (equal(v_28894, v_28893)) goto v_28750;
    else goto v_28751;
v_28750:
    goto v_28769;
v_28765:
    v_28893 = stack[0];
    v_28893 = qcdr(v_28893);
    v_28894 = qcar(v_28893);
    goto v_28766;
v_28767:
    v_28893 = elt(env, 2); // (lessp greaterp)
    goto v_28768;
v_28769:
    goto v_28765;
v_28766:
    goto v_28767;
v_28768:
    v_28893 = Lmemq(nil, v_28894, v_28893);
    if (v_28893 == nil) goto v_28763;
    goto v_28783;
v_28777:
    v_28893 = stack[-6];
    v_28895 = qcdr(v_28893);
    goto v_28778;
v_28779:
    v_28893 = stack[0];
    v_28894 = qcdr(v_28893);
    goto v_28780;
v_28781:
    v_28893 = stack[-7];
    goto v_28782;
v_28783:
    goto v_28777;
v_28778:
    goto v_28779;
v_28780:
    goto v_28781;
v_28782:
    fn = elt(env, 4); // ofsf_smmkat!-and2
    v_28893 = (*qfnn(fn))(fn, 3, v_28895, v_28894, v_28893);
    env = stack[-8];
    v_28894 = v_28893;
    if (v_28893 == nil) goto v_28763;
    v_28893 = v_28894;
    v_28893 = ncons(v_28893);
    env = stack[-8];
    goto v_28761;
v_28763:
    goto v_28801;
v_28795:
    v_28895 = elt(env, 3); // and
    goto v_28796;
v_28797:
    v_28893 = stack[0];
    v_28894 = qcdr(v_28893);
    goto v_28798;
v_28799:
    v_28893 = stack[-7];
    goto v_28800;
v_28801:
    goto v_28795;
v_28796:
    goto v_28797;
v_28798:
    goto v_28799;
v_28800:
    fn = elt(env, 5); // ofsf_entry2at
    v_28893 = (*qfnn(fn))(fn, 3, v_28895, v_28894, v_28893);
    env = stack[-8];
    v_28893 = ncons(v_28893);
    env = stack[-8];
    goto v_28761;
    v_28893 = nil;
v_28761:
    goto v_28749;
v_28751:
    v_28893 = nil;
v_28749:
    stack[-3] = v_28893;
    v_28893 = stack[-3];
    fn = elt(env, 6); // lastpair
    v_28893 = (*qfn1(fn))(fn, v_28893);
    env = stack[-8];
    stack[-2] = v_28893;
    v_28893 = stack[-4];
    v_28893 = qcdr(v_28893);
    stack[-4] = v_28893;
    v_28893 = stack[-2];
    if (!consp(v_28893)) goto v_28812;
    else goto v_28813;
v_28812:
    goto v_28735;
v_28813:
v_28736:
    v_28893 = stack[-4];
    if (v_28893 == nil) goto v_28817;
    else goto v_28818;
v_28817:
    v_28893 = stack[-3];
    goto v_28734;
v_28818:
    goto v_28826;
v_28822:
    stack[-1] = stack[-2];
    goto v_28823;
v_28824:
    v_28893 = stack[-4];
    v_28893 = qcar(v_28893);
    stack[0] = v_28893;
    goto v_28839;
v_28835:
    v_28893 = stack[0];
    v_28894 = qcar(v_28893);
    goto v_28836;
v_28837:
    v_28893 = stack[-5];
    goto v_28838;
v_28839:
    goto v_28835;
v_28836:
    goto v_28837;
v_28838:
    if (equal(v_28894, v_28893)) goto v_28833;
    else goto v_28834;
v_28833:
    goto v_28852;
v_28848:
    v_28893 = stack[0];
    v_28893 = qcdr(v_28893);
    v_28894 = qcar(v_28893);
    goto v_28849;
v_28850:
    v_28893 = elt(env, 2); // (lessp greaterp)
    goto v_28851;
v_28852:
    goto v_28848;
v_28849:
    goto v_28850;
v_28851:
    v_28893 = Lmemq(nil, v_28894, v_28893);
    if (v_28893 == nil) goto v_28846;
    goto v_28866;
v_28860:
    v_28893 = stack[-6];
    v_28895 = qcdr(v_28893);
    goto v_28861;
v_28862:
    v_28893 = stack[0];
    v_28894 = qcdr(v_28893);
    goto v_28863;
v_28864:
    v_28893 = stack[-7];
    goto v_28865;
v_28866:
    goto v_28860;
v_28861:
    goto v_28862;
v_28863:
    goto v_28864;
v_28865:
    fn = elt(env, 4); // ofsf_smmkat!-and2
    v_28893 = (*qfnn(fn))(fn, 3, v_28895, v_28894, v_28893);
    env = stack[-8];
    v_28894 = v_28893;
    if (v_28893 == nil) goto v_28846;
    v_28893 = v_28894;
    v_28893 = ncons(v_28893);
    env = stack[-8];
    goto v_28844;
v_28846:
    goto v_28884;
v_28878:
    v_28895 = elt(env, 3); // and
    goto v_28879;
v_28880:
    v_28893 = stack[0];
    v_28894 = qcdr(v_28893);
    goto v_28881;
v_28882:
    v_28893 = stack[-7];
    goto v_28883;
v_28884:
    goto v_28878;
v_28879:
    goto v_28880;
v_28881:
    goto v_28882;
v_28883:
    fn = elt(env, 5); // ofsf_entry2at
    v_28893 = (*qfnn(fn))(fn, 3, v_28895, v_28894, v_28893);
    env = stack[-8];
    v_28893 = ncons(v_28893);
    env = stack[-8];
    goto v_28844;
    v_28893 = nil;
v_28844:
    goto v_28832;
v_28834:
    v_28893 = nil;
v_28832:
    goto v_28825;
v_28826:
    goto v_28822;
v_28823:
    goto v_28824;
v_28825:
    v_28893 = Lrplacd(nil, stack[-1], v_28893);
    env = stack[-8];
    v_28893 = stack[-2];
    fn = elt(env, 6); // lastpair
    v_28893 = (*qfn1(fn))(fn, v_28893);
    env = stack[-8];
    stack[-2] = v_28893;
    v_28893 = stack[-4];
    v_28893 = qcdr(v_28893);
    stack[-4] = v_28893;
    goto v_28736;
v_28734:
    return onevalue(v_28893);
}



// Code for mri_simplat1

static LispObject CC_mri_simplat1(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_28809, v_28810;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_28713;
    stack[-2] = v_28712;
// end of prologue
    v_28809 = qvalue(elt(env, 2)); // !*rlsimplfloor
    if (v_28809 == nil) goto v_28723;
    goto v_28732;
v_28726:
    v_28809 = stack[-2];
    fn = elt(env, 5); // mri_op
    stack[-3] = (*qfn1(fn))(fn, v_28809);
    env = stack[-4];
    goto v_28727;
v_28728:
    v_28809 = stack[-2];
    fn = elt(env, 6); // mri_arg2l
    v_28809 = (*qfn1(fn))(fn, v_28809);
    env = stack[-4];
    fn = elt(env, 7); // mri_simplfloor
    stack[0] = (*qfn1(fn))(fn, v_28809);
    env = stack[-4];
    goto v_28729;
v_28730:
    v_28809 = stack[-2];
    fn = elt(env, 8); // mri_type
    v_28809 = (*qfn1(fn))(fn, v_28809);
    env = stack[-4];
    goto v_28731;
v_28732:
    goto v_28726;
v_28727:
    goto v_28728;
v_28729:
    goto v_28730;
v_28731:
    fn = elt(env, 9); // mri_0mk2
    v_28809 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_28809);
    env = stack[-4];
    stack[-2] = v_28809;
    goto v_28721;
v_28723:
v_28721:
    v_28809 = stack[-2];
    fn = elt(env, 8); // mri_type
    v_28809 = (*qfn1(fn))(fn, v_28809);
    env = stack[-4];
    if (v_28809 == nil) goto v_28742;
    else goto v_28741;
v_28742:
    v_28809 = stack[-2];
    fn = elt(env, 10); // mri_dettype
    v_28809 = (*qfn1(fn))(fn, v_28809);
    env = stack[-4];
v_28741:
    stack[0] = v_28809;
    goto v_28755;
v_28751:
    v_28810 = stack[0];
    goto v_28752;
v_28753:
    v_28809 = elt(env, 3); // int
    goto v_28754;
v_28755:
    goto v_28751;
v_28752:
    goto v_28753;
v_28754:
    if (v_28810 == v_28809) goto v_28749;
    else goto v_28750;
v_28749:
    goto v_28763;
v_28759:
    goto v_28769;
v_28765:
    v_28809 = stack[-2];
    fn = elt(env, 11); // mri_2pasfat
    v_28810 = (*qfn1(fn))(fn, v_28809);
    env = stack[-4];
    goto v_28766;
v_28767:
    v_28809 = stack[-1];
    goto v_28768;
v_28769:
    goto v_28765;
v_28766:
    goto v_28767;
v_28768:
    fn = elt(env, 12); // pasf_simplat1
    v_28810 = (*qfn2(fn))(fn, v_28810, v_28809);
    env = stack[-4];
    goto v_28760;
v_28761:
    v_28809 = elt(env, 3); // int
    goto v_28762;
v_28763:
    goto v_28759;
v_28760:
    goto v_28761;
v_28762:
    {
        fn = elt(env, 13); // mri_pasf2mri
        return (*qfn2(fn))(fn, v_28810, v_28809);
    }
v_28750:
    v_28809 = stack[-2];
    fn = elt(env, 14); // mri_congp
    v_28809 = (*qfn1(fn))(fn, v_28809);
    env = stack[-4];
    if (v_28809 == nil) goto v_28776;
    else goto v_28777;
v_28776:
    goto v_28785;
v_28781:
    goto v_28791;
v_28787:
    v_28809 = stack[-2];
    fn = elt(env, 15); // mri_2ofsfat
    v_28810 = (*qfn1(fn))(fn, v_28809);
    env = stack[-4];
    goto v_28788;
v_28789:
    v_28809 = stack[-1];
    goto v_28790;
v_28791:
    goto v_28787;
v_28788:
    goto v_28789;
v_28790:
    fn = elt(env, 16); // ofsf_simplat1
    v_28810 = (*qfn2(fn))(fn, v_28810, v_28809);
    env = stack[-4];
    goto v_28782;
v_28783:
    v_28809 = elt(env, 4); // real
    goto v_28784;
v_28785:
    goto v_28781;
v_28782:
    goto v_28783;
v_28784:
    {
        fn = elt(env, 17); // mri_ofsf2mri
        return (*qfn2(fn))(fn, v_28810, v_28809);
    }
v_28777:
    goto v_28803;
v_28797:
    v_28809 = stack[-2];
    fn = elt(env, 5); // mri_op
    stack[-1] = (*qfn1(fn))(fn, v_28809);
    env = stack[-4];
    goto v_28798;
v_28799:
    v_28809 = stack[-2];
    fn = elt(env, 6); // mri_arg2l
    v_28810 = (*qfn1(fn))(fn, v_28809);
    env = stack[-4];
    goto v_28800;
v_28801:
    v_28809 = stack[0];
    goto v_28802;
v_28803:
    goto v_28797;
v_28798:
    goto v_28799;
v_28800:
    goto v_28801;
v_28802:
    {
        LispObject v_28815 = stack[-1];
        fn = elt(env, 9); // mri_0mk2
        return (*qfnn(fn))(fn, 3, v_28815, v_28810, v_28809);
    }
    return onevalue(v_28809);
}



// Code for ofsf_updsignpow

static LispObject CC_ofsf_updsignpow(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_28751, v_28752, v_28753, v_28754;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_28753 = v_28713;
    v_28754 = v_28712;
// end of prologue
    goto v_28723;
v_28719:
    v_28752 = v_28754;
    goto v_28720;
v_28721:
    v_28751 = elt(env, 1); // (equal greaterp geq neq)
    goto v_28722;
v_28723:
    goto v_28719;
v_28720:
    goto v_28721;
v_28722:
    v_28751 = Lmemq(nil, v_28752, v_28751);
    if (v_28751 == nil) goto v_28718;
    v_28751 = v_28754;
    goto v_28716;
v_28718:
    goto v_28734;
v_28730:
    v_28752 = v_28754;
    goto v_28731;
v_28732:
    v_28751 = elt(env, 2); // (lessp leq)
    goto v_28733;
v_28734:
    goto v_28730;
v_28731:
    goto v_28732;
v_28733:
    v_28751 = Lmemq(nil, v_28752, v_28751);
    if (v_28751 == nil) goto v_28729;
    goto v_28743;
v_28739:
    v_28751 = v_28754;
    goto v_28740;
v_28741:
    v_28752 = v_28753;
    v_28752 = Levenp(nil, v_28752);
    env = stack[0];
    v_28752 = (v_28752 == nil ? lisp_true : nil);
    goto v_28742;
v_28743:
    goto v_28739;
v_28740:
    goto v_28741;
v_28742:
    {
        fn = elt(env, 4); // ofsf_canegrel
        return (*qfn2(fn))(fn, v_28751, v_28752);
    }
v_28729:
    v_28751 = elt(env, 3); // unknown
    goto v_28716;
    v_28751 = nil;
v_28716:
    return onevalue(v_28751);
}



// Code for addexptsdf

static LispObject CC_addexptsdf(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_28777, v_28778;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_28713;
    stack[-1] = v_28712;
// end of prologue
    stack[-2] = nil;
v_28718:
    v_28777 = stack[-1];
    if (v_28777 == nil) goto v_28721;
    else goto v_28722;
v_28721:
    v_28777 = stack[0];
    if (v_28777 == nil) goto v_28726;
    else goto v_28727;
v_28726:
    v_28777 = stack[-2];
    {
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(fn, v_28777);
    }
v_28727:
    goto v_28738;
v_28734:
    stack[0] = stack[-2];
    goto v_28735;
v_28736:
    v_28777 = elt(env, 1); // "X too long"
    fn = elt(env, 4); // interr
    v_28777 = (*qfn1(fn))(fn, v_28777);
    env = stack[-3];
    goto v_28737;
v_28738:
    goto v_28734;
v_28735:
    goto v_28736;
v_28737:
    {
        LispObject v_28782 = stack[0];
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(fn, v_28782, v_28777);
    }
    goto v_28720;
v_28722:
    v_28777 = stack[0];
    if (v_28777 == nil) goto v_28742;
    else goto v_28743;
v_28742:
    goto v_28750;
v_28746:
    stack[0] = stack[-2];
    goto v_28747;
v_28748:
    v_28777 = elt(env, 2); // "Y too long"
    fn = elt(env, 4); // interr
    v_28777 = (*qfn1(fn))(fn, v_28777);
    env = stack[-3];
    goto v_28749;
v_28750:
    goto v_28746;
v_28747:
    goto v_28748;
v_28749:
    {
        LispObject v_28783 = stack[0];
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(fn, v_28783, v_28777);
    }
v_28743:
    goto v_28761;
v_28757:
    goto v_28767;
v_28763:
    v_28777 = stack[-1];
    v_28778 = qcar(v_28777);
    goto v_28764;
v_28765:
    v_28777 = stack[0];
    v_28777 = qcar(v_28777);
    goto v_28766;
v_28767:
    goto v_28763;
v_28764:
    goto v_28765;
v_28766:
    fn = elt(env, 5); // exptplus
    v_28778 = (*qfn2(fn))(fn, v_28778, v_28777);
    env = stack[-3];
    goto v_28758;
v_28759:
    v_28777 = stack[-2];
    goto v_28760;
v_28761:
    goto v_28757;
v_28758:
    goto v_28759;
v_28760:
    v_28777 = cons(v_28778, v_28777);
    env = stack[-3];
    stack[-2] = v_28777;
    v_28777 = stack[-1];
    v_28777 = qcdr(v_28777);
    stack[-1] = v_28777;
    v_28777 = stack[0];
    v_28777 = qcdr(v_28777);
    stack[0] = v_28777;
    goto v_28718;
v_28720:
    v_28777 = nil;
    return onevalue(v_28777);
}



// Code for evalgeq

static LispObject CC_evalgeq(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_28724, v_28725;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
// copy arguments values to proper place
    v_28724 = v_28713;
    v_28725 = v_28712;
// end of prologue
    goto v_28720;
v_28716:
    goto v_28717;
v_28718:
    goto v_28719;
v_28720:
    goto v_28716;
v_28717:
    goto v_28718;
v_28719:
    fn = elt(env, 1); // evallessp
    v_28724 = (*qfn2(fn))(fn, v_28725, v_28724);
    v_28724 = (v_28724 == nil ? lisp_true : nil);
    return onevalue(v_28724);
}



// Code for spinnerprod

static LispObject CC_spinnerprod(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28849, v_28850, v_28851, v_28852;
    LispObject v_28717, v_28716, v_28715, v_28714, v_28713, v_28712;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "spinnerprod");
    va_start(aa, nargs);
    v_28712 = va_arg(aa, LispObject);
    v_28713 = va_arg(aa, LispObject);
    v_28714 = va_arg(aa, LispObject);
    v_28715 = va_arg(aa, LispObject);
    v_28716 = va_arg(aa, LispObject);
    v_28717 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_28717,v_28716,v_28715,v_28714,v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_28712,v_28713,v_28714,v_28715,v_28716,v_28717);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_28717;
    v_28849 = v_28716;
    v_28850 = v_28715;
    stack[-5] = v_28714;
    v_28851 = v_28713;
    v_28852 = v_28712;
// end of prologue
    stack[-6] = v_28850;
    v_28850 = stack[-6];
    stack[-3] = v_28850;
    v_28849 = qcdr(v_28849);
    stack[-1] = v_28849;
v_28732:
    v_28849 = stack[-1];
    if (v_28849 == nil) goto v_28737;
    else goto v_28738;
v_28737:
    goto v_28731;
v_28738:
    v_28849 = stack[-1];
    v_28849 = qcar(v_28849);
    v_28850 = v_28849;
    v_28849 = v_28850;
    v_28849 = qcar(v_28849);
    stack[-7] = v_28849;
    v_28849 = stack[-7];
    if (v_28849 == nil) goto v_28748;
    else goto v_28749;
v_28748:
    v_28849 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_28849;
    goto v_28747;
v_28749:
v_28747:
    v_28849 = v_28850;
    v_28849 = qcdr(v_28849);
    stack[-2] = v_28849;
    v_28849 = stack[-2];
    if (v_28849 == nil) goto v_28760;
    else goto v_28761;
v_28760:
    v_28849 = lisp_true;
    goto v_28759;
v_28761:
    goto v_28770;
v_28766:
    stack[0] = stack[-2];
    goto v_28767;
v_28768:
    v_28849 = nil;
    v_28849 = ncons(v_28849);
    env = stack[-8];
    goto v_28769;
v_28770:
    goto v_28766;
v_28767:
    goto v_28768;
v_28769:
    v_28849 = (equal(stack[0], v_28849) ? lisp_true : nil);
    goto v_28759;
    v_28849 = nil;
v_28759:
    if (v_28849 == nil) goto v_28757;
    v_28849 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_28849;
    goto v_28755;
v_28757:
v_28755:
    goto v_28785;
v_28781:
    v_28850 = stack[-7];
    goto v_28782;
v_28783:
    v_28849 = stack[-5];
    goto v_28784;
v_28785:
    goto v_28781;
v_28782:
    goto v_28783;
v_28784:
    v_28849 = (LispObject)lesseq2(v_28850, v_28849);
    v_28849 = v_28849 ? lisp_true : nil;
    env = stack[-8];
    if (v_28849 == nil) goto v_28779;
    goto v_28792;
v_28788:
    v_28850 = stack[-7];
    goto v_28789;
v_28790:
    v_28849 = stack[-4];
    goto v_28791;
v_28792:
    goto v_28788;
v_28789:
    goto v_28790;
v_28791:
    v_28849 = Latsoc(nil, v_28850, v_28849);
    stack[-7] = v_28849;
    v_28849 = stack[-7];
    if (v_28849 == nil) goto v_28802;
    else goto v_28803;
v_28802:
    v_28849 = lisp_true;
    goto v_28801;
v_28803:
    goto v_28812;
v_28808:
    stack[0] = stack[-7];
    goto v_28809;
v_28810:
    v_28849 = nil;
    v_28849 = ncons(v_28849);
    env = stack[-8];
    goto v_28811;
v_28812:
    goto v_28808;
v_28809:
    goto v_28810;
v_28811:
    v_28849 = (equal(stack[0], v_28849) ? lisp_true : nil);
    goto v_28801;
    v_28849 = nil;
v_28801:
    if (v_28849 == nil) goto v_28799;
    goto v_28797;
v_28799:
    goto v_28827;
v_28821:
    stack[0] = elt(env, 2); // plus
    goto v_28822;
v_28823:
    stack[-3] = stack[-6];
    goto v_28824;
v_28825:
    goto v_28837;
v_28831:
    v_28851 = elt(env, 3); // times
    goto v_28832;
v_28833:
    v_28850 = stack[-2];
    goto v_28834;
v_28835:
    v_28849 = stack[-7];
    v_28849 = qcdr(v_28849);
    goto v_28836;
v_28837:
    goto v_28831;
v_28832:
    goto v_28833;
v_28834:
    goto v_28835;
v_28836:
    v_28849 = list3(v_28851, v_28850, v_28849);
    env = stack[-8];
    goto v_28826;
v_28827:
    goto v_28821;
v_28822:
    goto v_28823;
v_28824:
    goto v_28825;
v_28826:
    v_28849 = list3(stack[0], stack[-3], v_28849);
    env = stack[-8];
    stack[-6] = v_28849;
    v_28849 = stack[-6];
    stack[-3] = v_28849;
    goto v_28797;
v_28797:
    goto v_28777;
v_28779:
v_28777:
    v_28849 = stack[-1];
    v_28849 = qcdr(v_28849);
    stack[-1] = v_28849;
    goto v_28732;
v_28731:
    v_28849 = stack[-3];
    return onevalue(v_28849);
}



// Code for safe!-fp!-quot

static LispObject CC_safeKfpKquot(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_28804, v_28805, v_28806;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_28806 = v_28713;
    stack[0] = v_28712;
// end of prologue
    goto v_28727;
v_28723:
    v_28805 = v_28806;
    goto v_28724;
v_28725:
    v_28804 = elt(env, 2); // 0.0
    goto v_28726;
v_28727:
    goto v_28723;
v_28724:
    goto v_28725;
v_28726:
    if (equal(v_28805, v_28804)) goto v_28721;
    else goto v_28722;
v_28721:
    v_28804 = nil;
    goto v_28717;
v_28722:
    v_28804 = qvalue(elt(env, 3)); // !*nonegzerotimes
    if (v_28804 == nil) goto v_28732;
    goto v_28740;
v_28736:
    v_28805 = stack[0];
    goto v_28737;
v_28738:
    v_28804 = elt(env, 2); // 0.0
    goto v_28739;
v_28740:
    goto v_28736;
v_28737:
    goto v_28738;
v_28739:
    if (equal(v_28805, v_28804)) goto v_28735;
    else goto v_28732;
v_28735:
    v_28804 = elt(env, 2); // 0.0
    goto v_28717;
v_28732:
    goto v_28749;
v_28745:
    v_28804 = stack[0];
    goto v_28746;
v_28747:
    v_28805 = v_28806;
    goto v_28748;
v_28749:
    goto v_28745;
v_28746:
    goto v_28747;
v_28748:
    v_28804 = quot2(v_28804, v_28805);
    env = stack[-2];
    stack[-1] = v_28804;
    goto v_28762;
v_28758:
    v_28805 = stack[-1];
    goto v_28759;
v_28760:
    v_28804 = qvalue(elt(env, 4)); // !!minnorm
    goto v_28761;
v_28762:
    goto v_28758;
v_28759:
    goto v_28760;
v_28761:
    v_28804 = (LispObject)lessp2(v_28805, v_28804);
    v_28804 = v_28804 ? lisp_true : nil;
    env = stack[-2];
    if (v_28804 == nil) goto v_28755;
    goto v_28772;
v_28768:
    v_28805 = stack[-1];
    goto v_28769;
v_28770:
    v_28804 = qvalue(elt(env, 5)); // !!minnegnorm
    goto v_28771;
v_28772:
    goto v_28768;
v_28769:
    goto v_28770;
v_28771:
    v_28804 = (LispObject)greaterp2(v_28805, v_28804);
    v_28804 = v_28804 ? lisp_true : nil;
    env = stack[-2];
    if (v_28804 == nil) goto v_28755;
    goto v_28780;
v_28776:
    v_28805 = stack[0];
    goto v_28777;
v_28778:
    v_28804 = elt(env, 2); // 0.0
    goto v_28779;
v_28780:
    goto v_28776;
v_28777:
    goto v_28778;
v_28779:
    if (equal(v_28805, v_28804)) goto v_28755;
    v_28804 = nil;
    goto v_28717;
v_28755:
    goto v_28790;
v_28786:
    goto v_28796;
v_28792:
    v_28805 = stack[-1];
    goto v_28793;
v_28794:
    v_28804 = stack[-1];
    goto v_28795;
v_28796:
    goto v_28792;
v_28793:
    goto v_28794;
v_28795:
    v_28804 = difference2(v_28805, v_28804);
    env = stack[-2];
    goto v_28787;
v_28788:
    v_28805 = elt(env, 2); // 0.0
    goto v_28789;
v_28790:
    goto v_28786;
v_28787:
    goto v_28788;
v_28789:
    if (equal(v_28804, v_28805)) goto v_28784;
    else goto v_28785;
v_28784:
    v_28804 = stack[-1];
    goto v_28717;
v_28785:
    v_28804 = nil;
    goto v_28717;
    v_28804 = nil;
v_28717:
    return onevalue(v_28804);
}



// Code for f2dip

static LispObject CC_f2dip(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28726;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_28726 = v_28712;
// end of prologue
    goto v_28721;
v_28715:
    stack[-1] = v_28726;
    goto v_28716;
v_28717:
    fn = elt(env, 1); // evzero
    stack[0] = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_28718;
v_28719:
    v_28726 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 2); // bcfd
    v_28726 = (*qfn1(fn))(fn, v_28726);
    env = stack[-2];
    goto v_28720;
v_28721:
    goto v_28715;
v_28716:
    goto v_28717;
v_28718:
    goto v_28719;
v_28720:
    {
        LispObject v_28729 = stack[-1];
        LispObject v_28730 = stack[0];
        fn = elt(env, 3); // f2dip1
        return (*qfnn(fn))(fn, 3, v_28729, v_28730, v_28726);
    }
}



// Code for exptbf

static LispObject CC_exptbf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28762, v_28763;
    LispObject fn;
    LispObject v_28714, v_28713, v_28712;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "exptbf");
    va_start(aa, nargs);
    v_28712 = va_arg(aa, LispObject);
    v_28713 = va_arg(aa, LispObject);
    v_28714 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_28714,v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_28712,v_28713,v_28714);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_28714;
    stack[-1] = v_28713;
    stack[-2] = v_28712;
// end of prologue
v_28718:
    v_28762 = stack[-1];
    v_28762 = Levenp(nil, v_28762);
    env = stack[-3];
    if (v_28762 == nil) goto v_28722;
    else goto v_28723;
v_28722:
    goto v_28731;
v_28727:
    v_28763 = stack[0];
    goto v_28728;
v_28729:
    v_28762 = stack[-2];
    goto v_28730;
v_28731:
    goto v_28727;
v_28728:
    goto v_28729;
v_28730:
    fn = elt(env, 1); // csl_timbf
    v_28762 = (*qfn2(fn))(fn, v_28763, v_28762);
    env = stack[-3];
    stack[0] = v_28762;
    goto v_28721;
v_28723:
v_28721:
    goto v_28739;
v_28735:
    v_28763 = stack[-1];
    goto v_28736;
v_28737:
    v_28762 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_28738;
v_28739:
    goto v_28735;
v_28736:
    goto v_28737;
v_28738:
    fn = elt(env, 2); // lshift
    v_28762 = (*qfn2(fn))(fn, v_28763, v_28762);
    env = stack[-3];
    stack[-1] = v_28762;
    goto v_28750;
v_28746:
    v_28763 = stack[-1];
    goto v_28747;
v_28748:
    v_28762 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28749;
v_28750:
    goto v_28746;
v_28747:
    goto v_28748;
v_28749:
    if (v_28763 == v_28762) goto v_28744;
    else goto v_28745;
v_28744:
    v_28762 = stack[0];
    goto v_28717;
v_28745:
    goto v_28759;
v_28755:
    v_28763 = stack[-2];
    goto v_28756;
v_28757:
    v_28762 = stack[-2];
    goto v_28758;
v_28759:
    goto v_28755;
v_28756:
    goto v_28757;
v_28758:
    fn = elt(env, 1); // csl_timbf
    v_28762 = (*qfn2(fn))(fn, v_28763, v_28762);
    env = stack[-3];
    stack[-2] = v_28762;
    goto v_28718;
v_28717:
    return onevalue(v_28762);
}



// Code for reset_opnums

static LispObject CC_reset_opnums(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28781, v_28782, v_28783;
    LispObject fn;
    argcheck(nargs, 0, "reset_opnums");
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
    v_28781 = qvalue(elt(env, 2)); // oporder!*
    stack[-4] = v_28781;
    v_28781 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_28781;
v_28720:
    v_28781 = stack[-4];
    if (v_28781 == nil) goto v_28726;
    else goto v_28727;
v_28726:
    v_28781 = nil;
    goto v_28719;
v_28727:
    v_28781 = stack[-4];
    v_28781 = qcar(v_28781);
    v_28782 = v_28781;
    v_28781 = stack[-4];
    v_28781 = qcdr(v_28781);
    stack[-4] = v_28781;
    v_28781 = v_28782;
    if (symbolp(v_28781)) goto v_28736;
    else goto v_28737;
v_28736:
    v_28781 = v_28782;
    stack[-2] = v_28781;
    v_28781 = nil;
    goto v_28735;
v_28737:
    v_28781 = v_28782;
    v_28781 = qcar(v_28781);
    stack[-2] = v_28781;
    v_28781 = v_28782;
    v_28781 = qcdr(v_28781);
    goto v_28735;
v_28735:
    goto v_28754;
v_28748:
    stack[-1] = stack[-2];
    goto v_28749;
v_28750:
    stack[0] = elt(env, 3); // opnum
    goto v_28751;
v_28752:
    goto v_28762;
v_28758:
    goto v_28768;
v_28764:
    v_28782 = v_28781;
    goto v_28765;
v_28766:
    v_28781 = stack[-3];
    goto v_28767;
v_28768:
    goto v_28764;
v_28765:
    goto v_28766;
v_28767:
    v_28783 = cons(v_28782, v_28781);
    env = stack[-5];
    goto v_28759;
v_28760:
    goto v_28776;
v_28772:
    v_28782 = stack[-2];
    goto v_28773;
v_28774:
    v_28781 = elt(env, 3); // opnum
    goto v_28775;
v_28776:
    goto v_28772;
v_28773:
    goto v_28774;
v_28775:
    v_28781 = get(v_28782, v_28781);
    env = stack[-5];
    goto v_28761;
v_28762:
    goto v_28758;
v_28759:
    goto v_28760;
v_28761:
    fn = elt(env, 4); // !*xadd
    v_28781 = (*qfn2(fn))(fn, v_28783, v_28781);
    env = stack[-5];
    goto v_28753;
v_28754:
    goto v_28748;
v_28749:
    goto v_28750;
v_28751:
    goto v_28752;
v_28753:
    v_28781 = Lputprop(nil, 3, stack[-1], stack[0], v_28781);
    env = stack[-5];
    v_28781 = stack[-3];
    v_28781 = add1(v_28781);
    env = stack[-5];
    stack[-3] = v_28781;
    goto v_28720;
v_28719:
    return onevalue(v_28781);
}



// Code for delete_edge

static LispObject CC_delete_edge(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_28760, v_28761, v_28762;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28713;
    stack[-1] = v_28712;
// end of prologue
    v_28762 = nil;
v_28718:
    v_28760 = stack[0];
    if (v_28760 == nil) goto v_28721;
    else goto v_28722;
v_28721:
    v_28760 = v_28762;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_28760);
    }
v_28722:
    goto v_28732;
v_28728:
    v_28760 = stack[-1];
    v_28761 = qcar(v_28760);
    goto v_28729;
v_28730:
    v_28760 = stack[0];
    v_28760 = qcar(v_28760);
    v_28760 = qcar(v_28760);
    goto v_28731;
v_28732:
    goto v_28728;
v_28729:
    goto v_28730;
v_28731:
    if (v_28761 == v_28760) goto v_28726;
    else goto v_28727;
v_28726:
    goto v_28743;
v_28739:
    v_28761 = v_28762;
    goto v_28740;
v_28741:
    v_28760 = stack[0];
    v_28760 = qcdr(v_28760);
    goto v_28742;
v_28743:
    goto v_28739;
v_28740:
    goto v_28741;
v_28742:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_28761, v_28760);
    }
v_28727:
    goto v_28754;
v_28750:
    v_28760 = stack[0];
    v_28760 = qcar(v_28760);
    goto v_28751;
v_28752:
    v_28761 = v_28762;
    goto v_28753;
v_28754:
    goto v_28750;
v_28751:
    goto v_28752;
v_28753:
    v_28760 = cons(v_28760, v_28761);
    env = stack[-2];
    v_28762 = v_28760;
    v_28760 = stack[0];
    v_28760 = qcdr(v_28760);
    stack[0] = v_28760;
    goto v_28718;
    v_28760 = nil;
    return onevalue(v_28760);
}



// Code for generic_arguments

static LispObject CC_generic_arguments(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28730, v_28731, v_28732;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
// copy arguments values to proper place
    v_28730 = v_28712;
// end of prologue
    goto v_28719;
v_28715:
    v_28732 = elt(env, 1); // list
    goto v_28716;
v_28717:
    goto v_28726;
v_28722:
    v_28731 = qcar(v_28730);
    goto v_28723;
v_28724:
    v_28730 = elt(env, 2); // generic_function
    goto v_28725;
v_28726:
    goto v_28722;
v_28723:
    goto v_28724;
v_28725:
    v_28730 = get(v_28731, v_28730);
    goto v_28718;
v_28719:
    goto v_28715;
v_28716:
    goto v_28717;
v_28718:
    return cons(v_28732, v_28730);
}



// Code for reduce!-ratios

static LispObject CC_reduceKratios(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_28781, v_28782;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_28713;
    stack[-2] = v_28712;
// end of prologue
v_28711:
    goto v_28728;
v_28724:
    v_28782 = stack[-2];
    goto v_28725;
v_28726:
    v_28781 = stack[-1];
    goto v_28727;
v_28728:
    goto v_28724;
v_28725:
    goto v_28726;
v_28727:
    fn = elt(env, 2); // red!-ratios1
    v_28781 = (*qfn2(fn))(fn, v_28782, v_28781);
    env = stack[-4];
    stack[-3] = v_28781;
    if (v_28781 == nil) goto v_28721;
    else goto v_28722;
v_28721:
    v_28781 = stack[-2];
    goto v_28717;
v_28722:
    goto v_28737;
v_28733:
    goto v_28743;
v_28739:
    v_28781 = stack[-3];
    v_28782 = qcar(v_28781);
    goto v_28740;
v_28741:
    v_28781 = stack[-2];
    goto v_28742;
v_28743:
    goto v_28739;
v_28740:
    goto v_28741;
v_28742:
    fn = elt(env, 3); // mv!-domainlist!-!*
    stack[0] = (*qfn2(fn))(fn, v_28782, v_28781);
    env = stack[-4];
    goto v_28734;
v_28735:
    goto v_28752;
v_28748:
    v_28781 = stack[-3];
    v_28782 = qcdr(v_28781);
    goto v_28749;
v_28750:
    v_28781 = stack[-1];
    goto v_28751;
v_28752:
    goto v_28748;
v_28749:
    goto v_28750;
v_28751:
    fn = elt(env, 3); // mv!-domainlist!-!*
    v_28781 = (*qfn2(fn))(fn, v_28782, v_28781);
    env = stack[-4];
    goto v_28736;
v_28737:
    goto v_28733;
v_28734:
    goto v_28735;
v_28736:
    fn = elt(env, 4); // mv!-domainlist!-!-
    v_28781 = (*qfn2(fn))(fn, stack[0], v_28781);
    env = stack[-4];
    stack[-3] = v_28781;
    goto v_28765;
v_28761:
    v_28781 = stack[-2];
    fn = elt(env, 5); // reddom_zeros
    stack[0] = (*qfn1(fn))(fn, v_28781);
    env = stack[-4];
    goto v_28762;
v_28763:
    v_28781 = stack[-3];
    fn = elt(env, 5); // reddom_zeros
    v_28781 = (*qfn1(fn))(fn, v_28781);
    env = stack[-4];
    goto v_28764;
v_28765:
    goto v_28761;
v_28762:
    goto v_28763;
v_28764:
    v_28781 = (LispObject)geq2(stack[0], v_28781);
    v_28781 = v_28781 ? lisp_true : nil;
    env = stack[-4];
    if (v_28781 == nil) goto v_28759;
    v_28781 = stack[-2];
    goto v_28757;
v_28759:
    goto v_28778;
v_28774:
    v_28782 = stack[-3];
    goto v_28775;
v_28776:
    v_28781 = stack[-1];
    goto v_28777;
v_28778:
    goto v_28774;
v_28775:
    goto v_28776;
v_28777:
    stack[-2] = v_28782;
    stack[-1] = v_28781;
    goto v_28711;
    v_28781 = nil;
v_28757:
v_28717:
    return onevalue(v_28781);
}



// Code for fs!:subang

static LispObject CC_fsTsubang(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28898, v_28899, v_28900, v_28901;
    LispObject fn;
    LispObject v_28714, v_28713, v_28712;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "fs:subang");
    va_start(aa, nargs);
    v_28712 = va_arg(aa, LispObject);
    v_28713 = va_arg(aa, LispObject);
    v_28714 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_28714,v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_28712,v_28713,v_28714);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-5] = v_28714;
    stack[-6] = v_28713;
    stack[-7] = v_28712;
// end of prologue
    v_28898 = stack[-7];
    if (v_28898 == nil) goto v_28718;
    else goto v_28719;
v_28718:
    v_28898 = nil;
    goto v_28717;
v_28719:
    v_28898 = (LispObject)112+TAG_FIXNUM; // 7
    v_28898 = Lmkvect(nil, v_28898);
    env = stack[-9];
    stack[-8] = v_28898;
    goto v_28735;
v_28731:
    goto v_28740;
v_28736:
    v_28899 = stack[-7];
    goto v_28737;
v_28738:
    v_28898 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_28739;
v_28740:
    goto v_28736;
v_28737:
    goto v_28738;
v_28739:
    v_28899 = *(LispObject *)((char *)v_28899 + (CELL-TAG_VECTOR) + (((intptr_t)v_28898-TAG_FIXNUM)/(16/CELL)));
    goto v_28732;
v_28733:
    v_28898 = stack[-6];
    goto v_28734;
v_28735:
    goto v_28731;
v_28732:
    goto v_28733;
v_28734:
    v_28898 = *(LispObject *)((char *)v_28899 + (CELL-TAG_VECTOR) + (((intptr_t)v_28898-TAG_FIXNUM)/(16/CELL)));
    stack[-4] = v_28898;
    v_28898 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_28898;
v_28749:
    goto v_28761;
v_28757:
    v_28899 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_28758;
v_28759:
    v_28898 = stack[-3];
    goto v_28760;
v_28761:
    goto v_28757;
v_28758:
    goto v_28759;
v_28760:
    v_28898 = difference2(v_28899, v_28898);
    env = stack[-9];
    v_28898 = Lminusp(nil, v_28898);
    env = stack[-9];
    if (v_28898 == nil) goto v_28754;
    goto v_28748;
v_28754:
    goto v_28773;
v_28769:
    v_28899 = stack[-3];
    goto v_28770;
v_28771:
    v_28898 = stack[-6];
    goto v_28772;
v_28773:
    goto v_28769;
v_28770:
    goto v_28771;
v_28772:
    if (equal(v_28899, v_28898)) goto v_28767;
    else goto v_28768;
v_28767:
    goto v_28782;
v_28776:
    stack[-1] = stack[-8];
    goto v_28777;
v_28778:
    stack[0] = stack[-3];
    goto v_28779;
v_28780:
    goto v_28790;
v_28786:
    v_28900 = stack[-4];
    goto v_28787;
v_28788:
    goto v_28796;
v_28792:
    v_28899 = stack[-5];
    goto v_28793;
v_28794:
    v_28898 = stack[-3];
    goto v_28795;
v_28796:
    goto v_28792;
v_28793:
    goto v_28794;
v_28795:
    v_28898 = *(LispObject *)((char *)v_28899 + (CELL-TAG_VECTOR) + (((intptr_t)v_28898-TAG_FIXNUM)/(16/CELL)));
    goto v_28789;
v_28790:
    goto v_28786;
v_28787:
    goto v_28788;
v_28789:
    v_28898 = times2(v_28900, v_28898);
    env = stack[-9];
    goto v_28781;
v_28782:
    goto v_28776;
v_28777:
    goto v_28778;
v_28779:
    goto v_28780;
v_28781:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_28898;
    goto v_28766;
v_28768:
    goto v_28808;
v_28802:
    stack[-2] = stack[-8];
    goto v_28803;
v_28804:
    stack[-1] = stack[-3];
    goto v_28805;
v_28806:
    goto v_28816;
v_28812:
    goto v_28821;
v_28817:
    goto v_28826;
v_28822:
    v_28899 = stack[-7];
    goto v_28823;
v_28824:
    v_28898 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_28825;
v_28826:
    goto v_28822;
v_28823:
    goto v_28824;
v_28825:
    v_28899 = *(LispObject *)((char *)v_28899 + (CELL-TAG_VECTOR) + (((intptr_t)v_28898-TAG_FIXNUM)/(16/CELL)));
    goto v_28818;
v_28819:
    v_28898 = stack[-3];
    goto v_28820;
v_28821:
    goto v_28817;
v_28818:
    goto v_28819;
v_28820:
    stack[0] = *(LispObject *)((char *)v_28899 + (CELL-TAG_VECTOR) + (((intptr_t)v_28898-TAG_FIXNUM)/(16/CELL)));
    goto v_28813;
v_28814:
    goto v_28837;
v_28833:
    v_28900 = stack[-4];
    goto v_28834;
v_28835:
    goto v_28843;
v_28839:
    v_28899 = stack[-5];
    goto v_28840;
v_28841:
    v_28898 = stack[-3];
    goto v_28842;
v_28843:
    goto v_28839;
v_28840:
    goto v_28841;
v_28842:
    v_28898 = *(LispObject *)((char *)v_28899 + (CELL-TAG_VECTOR) + (((intptr_t)v_28898-TAG_FIXNUM)/(16/CELL)));
    goto v_28836;
v_28837:
    goto v_28833;
v_28834:
    goto v_28835;
v_28836:
    v_28898 = times2(v_28900, v_28898);
    env = stack[-9];
    goto v_28815;
v_28816:
    goto v_28812;
v_28813:
    goto v_28814;
v_28815:
    v_28898 = plus2(stack[0], v_28898);
    env = stack[-9];
    goto v_28807;
v_28808:
    goto v_28802;
v_28803:
    goto v_28804;
v_28805:
    goto v_28806;
v_28807:
    *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-1]-TAG_FIXNUM)/(16/CELL))) = v_28898;
    goto v_28766;
v_28766:
    v_28898 = stack[-3];
    v_28898 = add1(v_28898);
    env = stack[-9];
    stack[-3] = v_28898;
    goto v_28749;
v_28748:
    goto v_28854;
v_28850:
    goto v_28862;
v_28856:
    goto v_28867;
v_28863:
    v_28899 = stack[-7];
    goto v_28864;
v_28865:
    v_28898 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_28866;
v_28867:
    goto v_28863;
v_28864:
    goto v_28865;
v_28866:
    v_28900 = *(LispObject *)((char *)v_28899 + (CELL-TAG_VECTOR) + (((intptr_t)v_28898-TAG_FIXNUM)/(16/CELL)));
    goto v_28857;
v_28858:
    v_28899 = stack[-6];
    goto v_28859;
v_28860:
    v_28898 = stack[-5];
    goto v_28861;
v_28862:
    goto v_28856;
v_28857:
    goto v_28858;
v_28859:
    goto v_28860;
v_28861:
    stack[0] = CC_fsTsubang(elt(env, 0), 3, v_28900, v_28899, v_28898);
    env = stack[-9];
    goto v_28851;
v_28852:
    goto v_28880;
v_28874:
    goto v_28885;
v_28881:
    v_28899 = stack[-7];
    goto v_28882;
v_28883:
    v_28898 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28884;
v_28885:
    goto v_28881;
v_28882:
    goto v_28883;
v_28884:
    v_28901 = *(LispObject *)((char *)v_28899 + (CELL-TAG_VECTOR) + (((intptr_t)v_28898-TAG_FIXNUM)/(16/CELL)));
    goto v_28875;
v_28876:
    v_28900 = stack[-8];
    goto v_28877;
v_28878:
    goto v_28894;
v_28890:
    v_28899 = stack[-7];
    goto v_28891;
v_28892:
    v_28898 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28893;
v_28894:
    goto v_28890;
v_28891:
    goto v_28892;
v_28893:
    v_28898 = *(LispObject *)((char *)v_28899 + (CELL-TAG_VECTOR) + (((intptr_t)v_28898-TAG_FIXNUM)/(16/CELL)));
    goto v_28879;
v_28880:
    goto v_28874;
v_28875:
    goto v_28876;
v_28877:
    goto v_28878;
v_28879:
    fn = elt(env, 2); // make!-term
    v_28898 = (*qfnn(fn))(fn, 3, v_28901, v_28900, v_28898);
    env = stack[-9];
    goto v_28853;
v_28854:
    goto v_28850;
v_28851:
    goto v_28852;
v_28853:
    {
        LispObject v_28911 = stack[0];
        fn = elt(env, 3); // fs!:plus
        return (*qfn2(fn))(fn, v_28911, v_28898);
    }
    goto v_28717;
    v_28898 = nil;
v_28717:
    return onevalue(v_28898);
}



// Code for mo_support

static LispObject CC_mo_support(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28758, v_28759;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_28712;
// end of prologue
    stack[-3] = nil;
    v_28758 = qvalue(elt(env, 2)); // cali!=basering
    fn = elt(env, 3); // ring_names
    v_28758 = (*qfn1(fn))(fn, v_28758);
    env = stack[-4];
    stack[-1] = v_28758;
v_28721:
    v_28758 = stack[-1];
    if (v_28758 == nil) goto v_28726;
    else goto v_28727;
v_28726:
    goto v_28720;
v_28727:
    v_28758 = stack[-1];
    v_28758 = qcar(v_28758);
    stack[0] = v_28758;
    goto v_28742;
v_28738:
    v_28758 = stack[0];
    fn = elt(env, 4); // mo_from_a
    v_28759 = (*qfn1(fn))(fn, v_28758);
    env = stack[-4];
    goto v_28739;
v_28740:
    v_28758 = stack[-2];
    goto v_28741;
v_28742:
    goto v_28738;
v_28739:
    goto v_28740;
v_28741:
    fn = elt(env, 5); // mo_divides!?
    v_28758 = (*qfn2(fn))(fn, v_28759, v_28758);
    env = stack[-4];
    if (v_28758 == nil) goto v_28736;
    goto v_28751;
v_28747:
    v_28759 = stack[0];
    goto v_28748;
v_28749:
    v_28758 = stack[-3];
    goto v_28750;
v_28751:
    goto v_28747;
v_28748:
    goto v_28749;
v_28750:
    v_28758 = cons(v_28759, v_28758);
    env = stack[-4];
    stack[-3] = v_28758;
    goto v_28734;
v_28736:
v_28734:
    v_28758 = stack[-1];
    v_28758 = qcdr(v_28758);
    stack[-1] = v_28758;
    goto v_28721;
v_28720:
    v_28758 = stack[-3];
        return Lnreverse(nil, v_28758);
    return onevalue(v_28758);
}



// Code for addnew

static LispObject CC_addnew(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28760, v_28761, v_28762, v_28763, v_28764;
    LispObject fn;
    LispObject v_28714, v_28713, v_28712;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "addnew");
    va_start(aa, nargs);
    v_28712 = va_arg(aa, LispObject);
    v_28713 = va_arg(aa, LispObject);
    v_28714 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_28714,v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_28712,v_28713,v_28714);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28714;
    v_28763 = v_28713;
    v_28764 = v_28712;
// end of prologue
    goto v_28722;
v_28716:
    v_28762 = qvalue(elt(env, 1)); // gv!*
    goto v_28717;
v_28718:
    v_28761 = v_28763;
    goto v_28719;
v_28720:
    v_28760 = v_28764;
    goto v_28721;
v_28722:
    goto v_28716;
v_28717:
    goto v_28718;
v_28719:
    goto v_28720;
v_28721:
    *(LispObject *)((char *)v_28762 + (CELL-TAG_VECTOR) + (((intptr_t)v_28761-TAG_FIXNUM)/(16/CELL))) = v_28760;
    goto v_28732;
v_28726:
    v_28762 = qvalue(elt(env, 2)); // bv!*
    goto v_28727;
v_28728:
    v_28761 = v_28763;
    goto v_28729;
v_28730:
    v_28760 = lisp_true;
    goto v_28731;
v_28732:
    goto v_28726;
v_28727:
    goto v_28728;
v_28729:
    goto v_28730;
v_28731:
    *(LispObject *)((char *)v_28762 + (CELL-TAG_VECTOR) + (((intptr_t)v_28761-TAG_FIXNUM)/(16/CELL))) = v_28760;
    v_28760 = v_28764;
    if (v_28760 == nil) goto v_28738;
    else goto v_28739;
v_28738:
    v_28760 = stack[0];
    goto v_28737;
v_28739:
    goto v_28749;
v_28745:
    goto v_28755;
v_28751:
    stack[-1] = v_28763;
    goto v_28752;
v_28753:
    v_28760 = v_28764;
    fn = elt(env, 3); // ljet
    v_28760 = (*qfn1(fn))(fn, v_28760);
    env = stack[-2];
    goto v_28754;
v_28755:
    goto v_28751;
v_28752:
    goto v_28753;
v_28754:
    v_28761 = cons(stack[-1], v_28760);
    env = stack[-2];
    goto v_28746;
v_28747:
    v_28760 = stack[0];
    goto v_28748;
v_28749:
    goto v_28745;
v_28746:
    goto v_28747;
v_28748:
    fn = elt(env, 4); // insert
    v_28760 = (*qfn2(fn))(fn, v_28761, v_28760);
    goto v_28737;
    v_28760 = nil;
v_28737:
    return onevalue(v_28760);
}



// Code for flattens1

static LispObject CC_flattens1(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28744;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28712;
// end of prologue
v_28716:
    v_28744 = stack[0];
    if (!consp(v_28744)) goto v_28719;
    else goto v_28720;
v_28719:
    v_28744 = stack[0];
    return ncons(v_28744);
v_28720:
    v_28744 = stack[0];
    v_28744 = qcdr(v_28744);
    if (v_28744 == nil) goto v_28725;
    goto v_28733;
v_28729:
    v_28744 = stack[0];
    v_28744 = qcar(v_28744);
    stack[-1] = CC_flattens1(elt(env, 0), v_28744);
    env = stack[-2];
    goto v_28730;
v_28731:
    v_28744 = stack[0];
    v_28744 = qcdr(v_28744);
    v_28744 = CC_flattens1(elt(env, 0), v_28744);
    goto v_28732;
v_28733:
    goto v_28729;
v_28730:
    goto v_28731;
v_28732:
    {
        LispObject v_28747 = stack[-1];
        return Lappend(nil, v_28747, v_28744);
    }
v_28725:
    v_28744 = stack[0];
    v_28744 = qcar(v_28744);
    stack[0] = v_28744;
    goto v_28716;
    v_28744 = nil;
    return onevalue(v_28744);
}



// Code for pst_mkpst

static LispObject CC_pst_mkpst(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28724;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_28724 = v_28712;
// end of prologue
    goto v_28720;
v_28716:
    stack[0] = nil;
    goto v_28717;
v_28718:
    fn = elt(env, 1); // pst_mkpst1
    v_28724 = (*qfn1(fn))(fn, v_28724);
    env = stack[-1];
    goto v_28719;
v_28720:
    goto v_28716;
v_28717:
    goto v_28718;
v_28719:
    v_28724 = cons(stack[0], v_28724);
    env = stack[-1];
    {
        fn = elt(env, 2); // pst_equitable
        return (*qfn1(fn))(fn, v_28724);
    }
}



// Code for nonlnr

static LispObject CC_nonlnr(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_28826, v_28827;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28713;
    stack[-1] = v_28712;
// end of prologue
v_28711:
    v_28826 = stack[-1];
    if (!consp(v_28826)) goto v_28721;
    else goto v_28722;
v_28721:
    v_28826 = lisp_true;
    goto v_28720;
v_28722:
    v_28826 = stack[-1];
    v_28826 = qcar(v_28826);
    v_28826 = (consp(v_28826) ? nil : lisp_true);
    goto v_28720;
    v_28826 = nil;
v_28720:
    if (v_28826 == nil) goto v_28718;
    v_28826 = nil;
    goto v_28716;
v_28718:
    goto v_28737;
v_28733:
    v_28826 = stack[-1];
    v_28826 = qcar(v_28826);
    v_28826 = qcar(v_28826);
    v_28827 = qcar(v_28826);
    goto v_28734;
v_28735:
    v_28826 = stack[0];
    goto v_28736;
v_28737:
    goto v_28733;
v_28734:
    goto v_28735;
v_28736:
    v_28826 = Lmember(nil, v_28827, v_28826);
    if (v_28826 == nil) goto v_28732;
    goto v_28752;
v_28748:
    v_28826 = stack[-1];
    v_28826 = qcar(v_28826);
    v_28826 = qcar(v_28826);
    v_28827 = qcdr(v_28826);
    goto v_28749;
v_28750:
    v_28826 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28751;
v_28752:
    goto v_28748;
v_28749:
    goto v_28750;
v_28751:
    v_28826 = (LispObject)greaterp2(v_28827, v_28826);
    v_28826 = v_28826 ? lisp_true : nil;
    env = stack[-2];
    if (v_28826 == nil) goto v_28746;
    else goto v_28745;
v_28746:
    goto v_28767;
v_28763:
    v_28826 = stack[-1];
    v_28826 = qcar(v_28826);
    v_28827 = qcdr(v_28826);
    goto v_28764;
v_28765:
    v_28826 = stack[0];
    goto v_28766;
v_28767:
    goto v_28763;
v_28764:
    goto v_28765;
v_28766:
    fn = elt(env, 1); // freeofl
    v_28826 = (*qfn2(fn))(fn, v_28827, v_28826);
    env = stack[-2];
    if (v_28826 == nil) goto v_28760;
    else goto v_28761;
v_28760:
    v_28826 = lisp_true;
    goto v_28759;
v_28761:
    goto v_28780;
v_28776:
    v_28826 = stack[-1];
    v_28827 = qcdr(v_28826);
    goto v_28777;
v_28778:
    v_28826 = stack[0];
    goto v_28779;
v_28780:
    goto v_28776;
v_28777:
    goto v_28778;
v_28779:
    stack[-1] = v_28827;
    stack[0] = v_28826;
    goto v_28711;
    v_28826 = nil;
v_28759:
v_28745:
    goto v_28716;
v_28732:
    goto v_28795;
v_28791:
    v_28826 = stack[-1];
    v_28826 = qcar(v_28826);
    v_28826 = qcar(v_28826);
    v_28827 = qcar(v_28826);
    goto v_28792;
v_28793:
    v_28826 = stack[0];
    goto v_28794;
v_28795:
    goto v_28791;
v_28792:
    goto v_28793;
v_28794:
    fn = elt(env, 1); // freeofl
    v_28826 = (*qfn2(fn))(fn, v_28827, v_28826);
    env = stack[-2];
    if (v_28826 == nil) goto v_28788;
    else goto v_28789;
v_28788:
    v_28826 = lisp_true;
    goto v_28787;
v_28789:
    goto v_28812;
v_28808:
    v_28826 = stack[-1];
    v_28826 = qcar(v_28826);
    v_28827 = qcdr(v_28826);
    goto v_28809;
v_28810:
    v_28826 = stack[0];
    goto v_28811;
v_28812:
    goto v_28808;
v_28809:
    goto v_28810;
v_28811:
    v_28826 = CC_nonlnr(elt(env, 0), v_28827, v_28826);
    env = stack[-2];
    if (v_28826 == nil) goto v_28806;
    else goto v_28805;
v_28806:
    goto v_28822;
v_28818:
    v_28826 = stack[-1];
    v_28827 = qcdr(v_28826);
    goto v_28819;
v_28820:
    v_28826 = stack[0];
    goto v_28821;
v_28822:
    goto v_28818;
v_28819:
    goto v_28820;
v_28821:
    stack[-1] = v_28827;
    stack[0] = v_28826;
    goto v_28711;
v_28805:
    goto v_28787;
    v_28826 = nil;
v_28787:
    goto v_28716;
    v_28826 = nil;
v_28716:
    return onevalue(v_28826);
}



// Code for sfchk

static LispObject CC_sfchk(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28725;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_28712;
// end of prologue
    v_28725 = stack[0];
    fn = elt(env, 1); // sfp
    v_28725 = (*qfn1(fn))(fn, v_28725);
    env = stack[-1];
    if (v_28725 == nil) goto v_28717;
    v_28725 = stack[0];
    {
        fn = elt(env, 2); // prepf
        return (*qfn1(fn))(fn, v_28725);
    }
v_28717:
    v_28725 = stack[0];
    goto v_28715;
    v_28725 = nil;
v_28715:
    return onevalue(v_28725);
}



// Code for depend!-sq

static LispObject CC_dependKsq(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_28736, v_28737;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28713;
    stack[-1] = v_28712;
// end of prologue
    goto v_28723;
v_28719:
    v_28736 = stack[-1];
    v_28737 = qcar(v_28736);
    goto v_28720;
v_28721:
    v_28736 = stack[0];
    goto v_28722;
v_28723:
    goto v_28719;
v_28720:
    goto v_28721;
v_28722:
    fn = elt(env, 1); // depend!-f
    v_28736 = (*qfn2(fn))(fn, v_28737, v_28736);
    env = stack[-2];
    if (v_28736 == nil) goto v_28717;
    else goto v_28716;
v_28717:
    goto v_28732;
v_28728:
    v_28736 = stack[-1];
    v_28737 = qcdr(v_28736);
    goto v_28729;
v_28730:
    v_28736 = stack[0];
    goto v_28731;
v_28732:
    goto v_28728;
v_28729:
    goto v_28730;
v_28731:
    {
        fn = elt(env, 1); // depend!-f
        return (*qfn2(fn))(fn, v_28737, v_28736);
    }
v_28716:
    return onevalue(v_28736);
}



// Code for talp_mkinvop

static LispObject CC_talp_mkinvop(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_28737;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_28713;
    stack[-1] = v_28712;
// end of prologue
    goto v_28722;
v_28718:
    goto v_28730;
v_28726:
    v_28737 = elt(env, 1); // inv_
    stack[-2] = Lexplode(nil, v_28737);
    env = stack[-3];
    goto v_28727;
v_28728:
    v_28737 = stack[-1];
    v_28737 = ncons(v_28737);
    env = stack[-3];
    goto v_28729;
v_28730:
    goto v_28726;
v_28727:
    goto v_28728;
v_28729:
    v_28737 = Lnconc(nil, stack[-2], v_28737);
    env = stack[-3];
    v_28737 = Lcompress(nil, v_28737);
    env = stack[-3];
    stack[-1] = Lexplode(nil, v_28737);
    env = stack[-3];
    goto v_28719;
v_28720:
    v_28737 = stack[0];
    v_28737 = Lexplode(nil, v_28737);
    env = stack[-3];
    goto v_28721;
v_28722:
    goto v_28718;
v_28719:
    goto v_28720;
v_28721:
    v_28737 = Lnconc(nil, stack[-1], v_28737);
    env = stack[-3];
    v_28737 = Lcompress(nil, v_28737);
        return Lintern(nil, v_28737);
}



// Code for pasf_dnf

static LispObject CC_pasf_dnf(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28738, v_28739;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_28712;
// end of prologue
    goto v_28723;
v_28719:
    v_28739 = stack[0];
    goto v_28720;
v_28721:
    v_28738 = elt(env, 1); // and
    goto v_28722;
v_28723:
    goto v_28719;
v_28720:
    goto v_28721;
v_28722:
    fn = elt(env, 3); // pasf_puregconp
    v_28738 = (*qfn2(fn))(fn, v_28739, v_28738);
    env = stack[-1];
    if (v_28738 == nil) goto v_28717;
    v_28738 = stack[0];
    goto v_28715;
v_28717:
    goto v_28734;
v_28730:
    v_28738 = stack[0];
    fn = elt(env, 4); // pasf_pnf
    v_28739 = (*qfn1(fn))(fn, v_28738);
    env = stack[-1];
    goto v_28731;
v_28732:
    v_28738 = elt(env, 2); // dnf
    goto v_28733;
v_28734:
    goto v_28730;
v_28731:
    goto v_28732;
v_28733:
    {
        fn = elt(env, 5); // pasf_pbnf
        return (*qfn2(fn))(fn, v_28739, v_28738);
    }
    v_28738 = nil;
v_28715:
    return onevalue(v_28738);
}



// Code for lengthn

static LispObject CC_lengthn(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28742;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28712;
// end of prologue
    v_28742 = stack[0];
    if (v_28742 == nil) goto v_28716;
    else goto v_28717;
v_28716:
    v_28742 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28715;
v_28717:
    v_28742 = stack[0];
    v_28742 = qcar(v_28742);
    if (is_number(v_28742)) goto v_28720;
    else goto v_28721;
v_28720:
    goto v_28729;
v_28725:
    v_28742 = stack[0];
    v_28742 = qcar(v_28742);
    stack[-1] = sub1(v_28742);
    env = stack[-2];
    goto v_28726;
v_28727:
    v_28742 = stack[0];
    v_28742 = qcdr(v_28742);
    v_28742 = CC_lengthn(elt(env, 0), v_28742);
    goto v_28728;
v_28729:
    goto v_28725;
v_28726:
    goto v_28727;
v_28728:
    {
        LispObject v_28745 = stack[-1];
        return plus2(v_28745, v_28742);
    }
v_28721:
    v_28742 = stack[0];
    v_28742 = qcdr(v_28742);
    v_28742 = CC_lengthn(elt(env, 0), v_28742);
    return add1(v_28742);
    v_28742 = nil;
v_28715:
    return onevalue(v_28742);
}



// Code for den

static LispObject CC_den(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28725, v_28726;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_28725 = v_28712;
// end of prologue
    goto v_28720;
v_28716:
    fn = elt(env, 1); // simp!*
    v_28725 = (*qfn1(fn))(fn, v_28725);
    env = stack[0];
    v_28726 = qcdr(v_28725);
    goto v_28717;
v_28718:
    v_28725 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28719;
v_28720:
    goto v_28716;
v_28717:
    goto v_28718;
v_28719:
    v_28725 = cons(v_28726, v_28725);
    env = stack[0];
    {
        fn = elt(env, 2); // mk!*sq
        return (*qfn1(fn))(fn, v_28725);
    }
}



// Code for !:log2

static LispObject CC_Tlog2(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28755, v_28756;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28712;
// end of prologue
    goto v_28723;
v_28719:
    v_28756 = elt(env, 0); // !:log2
    goto v_28720;
v_28721:
    v_28755 = stack[0];
    goto v_28722;
v_28723:
    goto v_28719;
v_28720:
    goto v_28721;
v_28722:
    fn = elt(env, 4); // get!:const
    v_28755 = (*qfn2(fn))(fn, v_28756, v_28755);
    env = stack[-2];
    stack[-1] = v_28755;
    goto v_28734;
v_28730:
    v_28756 = stack[-1];
    goto v_28731;
v_28732:
    v_28755 = elt(env, 2); // not_found
    goto v_28733;
v_28734:
    goto v_28730;
v_28731:
    goto v_28732;
v_28733:
    if (v_28756 == v_28755) goto v_28729;
    v_28755 = stack[-1];
    goto v_28716;
v_28729:
    goto v_28743;
v_28739:
    v_28756 = qvalue(elt(env, 3)); // bftwo!*
    goto v_28740;
v_28741:
    v_28755 = stack[0];
    goto v_28742;
v_28743:
    goto v_28739;
v_28740:
    goto v_28741;
v_28742:
    fn = elt(env, 5); // log!:
    v_28755 = (*qfn2(fn))(fn, v_28756, v_28755);
    env = stack[-2];
    stack[-1] = v_28755;
    goto v_28751;
v_28747:
    v_28756 = elt(env, 0); // !:log2
    goto v_28748;
v_28749:
    v_28755 = stack[-1];
    goto v_28750;
v_28751:
    goto v_28747;
v_28748:
    goto v_28749;
v_28750:
    fn = elt(env, 6); // save!:const
    v_28755 = (*qfn2(fn))(fn, v_28756, v_28755);
    v_28755 = stack[-1];
v_28716:
    return onevalue(v_28755);
}



// Code for mk_names_map_2

static LispObject CC_mk_names_map_2(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28765, v_28766;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28712);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_28765 = v_28712;
// end of prologue
    goto v_28725;
v_28721:
    v_28766 = v_28765;
    v_28766 = qcar(v_28766);
    goto v_28722;
v_28723:
    v_28765 = qcdr(v_28765);
    goto v_28724;
v_28725:
    goto v_28721;
v_28722:
    goto v_28723;
v_28724:
    v_28765 = Lappend(nil, v_28766, v_28765);
    env = stack[-4];
    stack[-3] = v_28765;
    v_28765 = stack[-3];
    if (v_28765 == nil) goto v_28732;
    else goto v_28733;
v_28732:
    v_28765 = nil;
    goto v_28718;
v_28733:
    v_28765 = stack[-3];
    v_28765 = qcar(v_28765);
    v_28765 = qcar(v_28765);
    v_28765 = ncons(v_28765);
    env = stack[-4];
    stack[-1] = v_28765;
    stack[-2] = v_28765;
v_28719:
    v_28765 = stack[-3];
    v_28765 = qcdr(v_28765);
    stack[-3] = v_28765;
    v_28765 = stack[-3];
    if (v_28765 == nil) goto v_28746;
    else goto v_28747;
v_28746:
    v_28765 = stack[-2];
    goto v_28718;
v_28747:
    goto v_28755;
v_28751:
    stack[0] = stack[-1];
    goto v_28752;
v_28753:
    v_28765 = stack[-3];
    v_28765 = qcar(v_28765);
    v_28765 = qcar(v_28765);
    v_28765 = ncons(v_28765);
    env = stack[-4];
    goto v_28754;
v_28755:
    goto v_28751;
v_28752:
    goto v_28753;
v_28754:
    v_28765 = Lrplacd(nil, stack[0], v_28765);
    env = stack[-4];
    v_28765 = stack[-1];
    v_28765 = qcdr(v_28765);
    stack[-1] = v_28765;
    goto v_28719;
v_28718:
    return onevalue(v_28765);
}



// Code for bagp

static LispObject CC_bagp(LispObject env,
                         LispObject v_28712)
{
    env = qenv(env);
    LispObject v_28731, v_28732;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28732 = v_28712;
// end of prologue
    v_28731 = v_28732;
    if (!consp(v_28731)) goto v_28717;
    goto v_28724;
v_28720:
    v_28731 = v_28732;
    v_28731 = qcar(v_28731);
    goto v_28721;
v_28722:
    v_28732 = elt(env, 1); // bag
    goto v_28723;
v_28724:
    goto v_28720;
v_28721:
    goto v_28722;
v_28723:
        return Lflagp(nil, v_28731, v_28732);
v_28717:
    v_28731 = nil;
    goto v_28715;
    v_28731 = nil;
v_28715:
    return onevalue(v_28731);
}



// Code for general!-modular!-difference

static LispObject CC_generalKmodularKdifference(LispObject env,
                         LispObject v_28712, LispObject v_28713)
{
    env = qenv(env);
    LispObject v_28748, v_28749;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28713,v_28712);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28712,v_28713);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_28748 = v_28713;
    v_28749 = v_28712;
// end of prologue
    goto v_28724;
v_28720:
    goto v_28721;
v_28722:
    goto v_28723;
v_28724:
    goto v_28720;
v_28721:
    goto v_28722;
v_28723:
    v_28748 = difference2(v_28749, v_28748);
    env = stack[-1];
    stack[0] = v_28748;
    goto v_28736;
v_28732:
    v_28749 = stack[0];
    goto v_28733;
v_28734:
    v_28748 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28735;
v_28736:
    goto v_28732;
v_28733:
    goto v_28734;
v_28735:
    v_28748 = (LispObject)lessp2(v_28749, v_28748);
    v_28748 = v_28748 ? lisp_true : nil;
    env = stack[-1];
    if (v_28748 == nil) goto v_28730;
    goto v_28744;
v_28740:
    v_28749 = stack[0];
    goto v_28741;
v_28742:
    v_28748 = qvalue(elt(env, 2)); // current!-modulus
    goto v_28743;
v_28744:
    goto v_28740;
v_28741:
    goto v_28742;
v_28743:
    v_28748 = plus2(v_28749, v_28748);
    stack[0] = v_28748;
    goto v_28728;
v_28730:
v_28728:
    v_28748 = stack[0];
    return onevalue(v_28748);
}



setup_type const u50_setup[] =
{
    {"natnump",                 CC_natnump,     TOO_MANY_1,    WRONG_NO_1},
    {"taylorp",                 CC_taylorp,     TOO_MANY_1,    WRONG_NO_1},
    {"monomcomparelex",         TOO_FEW_2,      CC_monomcomparelex,WRONG_NO_2},
    {"makecoeffpairs",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_makecoeffpairs},
    {"rat_abs",                 CC_rat_abs,     TOO_MANY_1,    WRONG_NO_1},
    {"parfool",                 CC_parfool,     TOO_MANY_1,    WRONG_NO_1},
    {"cr:prep",                 CC_crTprep,     TOO_MANY_1,    WRONG_NO_1},
    {"mkdmoderr",               TOO_FEW_2,      CC_mkdmoderr,  WRONG_NO_2},
    {"listquotient",            TOO_FEW_2,      CC_listquotient,WRONG_NO_2},
    {"expand-imrepartpow",      CC_expandKimrepartpow,TOO_MANY_1,WRONG_NO_1},
    {"fs:prin:",                CC_fsTprinT,    TOO_MANY_1,    WRONG_NO_1},
    {"verify_tens_ids",         CC_verify_tens_ids,TOO_MANY_1, WRONG_NO_1},
    {"cl_sordp",                TOO_FEW_2,      CC_cl_sordp,   WRONG_NO_2},
    {"pasf_lnegrel",            CC_pasf_lnegrel,TOO_MANY_1,    WRONG_NO_1},
    {"countof",                 TOO_FEW_2,      CC_countof,    WRONG_NO_2},
    {"matsm*",                  TOO_FEW_2,      CC_matsmH,     WRONG_NO_2},
    {"vdplsort",                CC_vdplsort,    TOO_MANY_1,    WRONG_NO_1},
    {"exp*",                    CC_expH,        TOO_MANY_1,    WRONG_NO_1},
    {"physopsubs",              CC_physopsubs,  TOO_MANY_1,    WRONG_NO_1},
    {"free",                    CC_free,        TOO_MANY_1,    WRONG_NO_1},
    {"njets",                   TOO_FEW_2,      CC_njets,      WRONG_NO_2},
    {"simpsqrt2",               CC_simpsqrt2,   TOO_MANY_1,    WRONG_NO_1},
    {"add-factor",              TOO_FEW_2,      CC_addKfactor, WRONG_NO_2},
    {"bfminus",                 CC_bfminus,     TOO_MANY_1,    WRONG_NO_1},
    {"domainp_list",            CC_domainp_list,TOO_MANY_1,    WRONG_NO_1},
    {"get-new-prime",           CC_getKnewKprime,TOO_MANY_1,   WRONG_NO_1},
    {"janettreeinsert",         CC_janettreeinsert,TOO_MANY_1, WRONG_NO_1},
    {"ofsf_smmkatl-and1",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smmkatlKand1},
    {"mri_simplat1",            TOO_FEW_2,      CC_mri_simplat1,WRONG_NO_2},
    {"ofsf_updsignpow",         TOO_FEW_2,      CC_ofsf_updsignpow,WRONG_NO_2},
    {"addexptsdf",              TOO_FEW_2,      CC_addexptsdf, WRONG_NO_2},
    {"evalgeq",                 TOO_FEW_2,      CC_evalgeq,    WRONG_NO_2},
    {"spinnerprod",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_spinnerprod},
    {"safe-fp-quot",            TOO_FEW_2,      CC_safeKfpKquot,WRONG_NO_2},
    {"f2dip",                   CC_f2dip,       TOO_MANY_1,    WRONG_NO_1},
    {"exptbf",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_exptbf},
    {"reset_opnums",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_reset_opnums},
    {"delete_edge",             TOO_FEW_2,      CC_delete_edge,WRONG_NO_2},
    {"generic_arguments",       CC_generic_arguments,TOO_MANY_1,WRONG_NO_1},
    {"reduce-ratios",           TOO_FEW_2,      CC_reduceKratios,WRONG_NO_2},
    {"fs:subang",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_fsTsubang},
    {"mo_support",              CC_mo_support,  TOO_MANY_1,    WRONG_NO_1},
    {"addnew",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_addnew},
    {"flattens1",               CC_flattens1,   TOO_MANY_1,    WRONG_NO_1},
    {"pst_mkpst",               CC_pst_mkpst,   TOO_MANY_1,    WRONG_NO_1},
    {"nonlnr",                  TOO_FEW_2,      CC_nonlnr,     WRONG_NO_2},
    {"sfchk",                   CC_sfchk,       TOO_MANY_1,    WRONG_NO_1},
    {"depend-sq",               TOO_FEW_2,      CC_dependKsq,  WRONG_NO_2},
    {"talp_mkinvop",            TOO_FEW_2,      CC_talp_mkinvop,WRONG_NO_2},
    {"pasf_dnf",                CC_pasf_dnf,    TOO_MANY_1,    WRONG_NO_1},
    {"lengthn",                 CC_lengthn,     TOO_MANY_1,    WRONG_NO_1},
    {"den",                     CC_den,         TOO_MANY_1,    WRONG_NO_1},
    {":log2",                   CC_Tlog2,       TOO_MANY_1,    WRONG_NO_1},
    {"mk_names_map_2",          CC_mk_names_map_2,TOO_MANY_1,  WRONG_NO_1},
    {"bagp",                    CC_bagp,        TOO_MANY_1,    WRONG_NO_1},
    {"general-modular-difference",TOO_FEW_2,    CC_generalKmodularKdifference,WRONG_NO_2},
    {NULL, (one_args *)"u50", (two_args *)"104689 3473363 944461", 0}
};

// end of generated code
