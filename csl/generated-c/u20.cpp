
// $destdir/u20.c        Machine generated C code

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



// Code for ofsf_entry2at

static LispObject CC_ofsf_entry2at(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10862, v_10863, v_10864, v_10865;
    LispObject fn;
    LispObject v_10830, v_10829, v_10828;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_entry2at");
    va_start(aa, nargs);
    v_10828 = va_arg(aa, LispObject);
    v_10829 = va_arg(aa, LispObject);
    v_10830 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_10830,v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_10828,v_10829,v_10830);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_10863 = v_10830;
    v_10864 = v_10829;
    v_10865 = v_10828;
// end of prologue
    v_10862 = qvalue(elt(env, 1)); // !*rlidentify
    if (v_10862 == nil) goto v_10835;
    goto v_10845;
v_10839:
    v_10862 = v_10865;
    goto v_10840;
v_10841:
    goto v_10842;
v_10843:
    goto v_10844;
v_10845:
    goto v_10839;
v_10840:
    goto v_10841;
v_10842:
    goto v_10843;
v_10844:
    fn = elt(env, 2); // ofsf_entry2at1
    v_10862 = (*qfnn(fn))(fn, 3, v_10862, v_10864, v_10863);
    env = stack[0];
    {
        fn = elt(env, 3); // cl_identifyat
        return (*qfn1(fn))(fn, v_10862);
    }
v_10835:
    goto v_10858;
v_10852:
    v_10862 = v_10865;
    goto v_10853;
v_10854:
    goto v_10855;
v_10856:
    goto v_10857;
v_10858:
    goto v_10852;
v_10853:
    goto v_10854;
v_10855:
    goto v_10856;
v_10857:
    {
        fn = elt(env, 2); // ofsf_entry2at1
        return (*qfnn(fn))(fn, 3, v_10862, v_10864, v_10863);
    }
    v_10862 = nil;
    return onevalue(v_10862);
}



// Code for rl_atl

static LispObject CC_rl_atl(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10839;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10828);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10839 = v_10828;
// end of prologue
    goto v_10835;
v_10831:
    stack[0] = qvalue(elt(env, 1)); // rl_atl!*
    goto v_10832;
v_10833:
    v_10839 = ncons(v_10839);
    env = stack[-1];
    goto v_10834;
v_10835:
    goto v_10831;
v_10832:
    goto v_10833;
v_10834:
    {
        LispObject v_10841 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_10841, v_10839);
    }
}



// Code for ibalp_unvar!-unsatlist

static LispObject CC_ibalp_unvarKunsatlist(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_11208, v_11209;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10828,v_10829);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_10829;
    v_11208 = v_10828;
// end of prologue
    stack[-5] = v_11208;
v_10838:
    v_11208 = stack[-5];
    if (v_11208 == nil) goto v_10842;
    else goto v_10843;
v_10842:
    goto v_10837;
v_10843:
    v_11208 = stack[-5];
    v_11208 = qcar(v_11208);
    stack[-3] = v_11208;
    goto v_10854;
v_10850:
    v_11208 = stack[-3];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    stack[0] = qcdr(v_11208);
    goto v_10851;
v_10852:
    goto v_10865;
v_10861:
    v_11209 = stack[-4];
    goto v_10862;
v_10863:
    v_11208 = stack[-3];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcar(v_11208);
    goto v_10864;
v_10865:
    goto v_10861;
v_10862:
    goto v_10863;
v_10864:
    fn = elt(env, 2); // lto_delq
    v_11208 = (*qfn2(fn))(fn, v_11209, v_11208);
    env = stack[-6];
    goto v_10853;
v_10854:
    goto v_10850;
v_10851:
    goto v_10852;
v_10853:
    fn = elt(env, 3); // setcar
    v_11208 = (*qfn2(fn))(fn, stack[0], v_11208);
    env = stack[-6];
    v_11208 = stack[-3];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcar(v_11208);
    if (v_11208 == nil) goto v_10875;
    else goto v_10876;
v_10875:
    v_11208 = stack[-3];
    v_11208 = qcar(v_11208);
    stack[-2] = v_11208;
v_10886:
    v_11208 = stack[-2];
    if (v_11208 == nil) goto v_10891;
    else goto v_10892;
v_10891:
    goto v_10885;
v_10892:
    v_11208 = stack[-2];
    v_11208 = qcar(v_11208);
    stack[-1] = v_11208;
    goto v_10903;
v_10899:
    v_11208 = stack[-1];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    stack[0] = qcdr(v_11208);
    goto v_10900;
v_10901:
    v_11208 = stack[-1];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcar(v_11208);
    v_11208 = add1(v_11208);
    env = stack[-6];
    goto v_10902;
v_10903:
    goto v_10899;
v_10900:
    goto v_10901;
v_10902:
    fn = elt(env, 3); // setcar
    v_11208 = (*qfn2(fn))(fn, stack[0], v_11208);
    env = stack[-6];
    goto v_10921;
v_10917:
    v_11208 = stack[-1];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    stack[0] = qcdr(v_11208);
    goto v_10918;
v_10919:
    v_11208 = stack[-1];
    fn = elt(env, 4); // ibalp_calcmom
    v_11208 = (*qfn1(fn))(fn, v_11208);
    env = stack[-6];
    goto v_10920;
v_10921:
    goto v_10917;
v_10918:
    goto v_10919;
v_10920:
    fn = elt(env, 3); // setcar
    v_11208 = (*qfn2(fn))(fn, stack[0], v_11208);
    env = stack[-6];
    v_11208 = stack[-2];
    v_11208 = qcdr(v_11208);
    stack[-2] = v_11208;
    goto v_10886;
v_10885:
    v_11208 = stack[-3];
    v_11208 = qcdr(v_11208);
    v_11208 = qcar(v_11208);
    stack[-2] = v_11208;
v_10941:
    v_11208 = stack[-2];
    if (v_11208 == nil) goto v_10947;
    else goto v_10948;
v_10947:
    goto v_10940;
v_10948:
    v_11208 = stack[-2];
    v_11208 = qcar(v_11208);
    stack[-1] = v_11208;
    goto v_10959;
v_10955:
    v_11208 = stack[-1];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    stack[0] = qcdr(v_11208);
    goto v_10956;
v_10957:
    v_11208 = stack[-1];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcar(v_11208);
    v_11208 = add1(v_11208);
    env = stack[-6];
    goto v_10958;
v_10959:
    goto v_10955;
v_10956:
    goto v_10957;
v_10958:
    fn = elt(env, 3); // setcar
    v_11208 = (*qfn2(fn))(fn, stack[0], v_11208);
    env = stack[-6];
    goto v_10979;
v_10975:
    v_11208 = stack[-1];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    stack[0] = qcdr(v_11208);
    goto v_10976;
v_10977:
    v_11208 = stack[-1];
    fn = elt(env, 4); // ibalp_calcmom
    v_11208 = (*qfn1(fn))(fn, v_11208);
    env = stack[-6];
    goto v_10978;
v_10979:
    goto v_10975;
v_10976:
    goto v_10977;
v_10978:
    fn = elt(env, 3); // setcar
    v_11208 = (*qfn2(fn))(fn, stack[0], v_11208);
    env = stack[-6];
    v_11208 = stack[-2];
    v_11208 = qcdr(v_11208);
    stack[-2] = v_11208;
    goto v_10941;
v_10940:
    v_11208 = stack[-3];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcar(v_11208);
    stack[-1] = v_11208;
v_10999:
    v_11208 = stack[-1];
    if (v_11208 == nil) goto v_11010;
    else goto v_11011;
v_11010:
    goto v_10998;
v_11011:
    v_11208 = stack[-1];
    v_11208 = qcar(v_11208);
    goto v_11022;
v_11018:
    v_11209 = v_11208;
    v_11209 = qcdr(v_11209);
    v_11209 = qcdr(v_11209);
    v_11209 = qcdr(v_11209);
    v_11209 = qcdr(v_11209);
    v_11209 = qcdr(v_11209);
    v_11209 = qcdr(v_11209);
    v_11209 = qcdr(v_11209);
    v_11209 = qcdr(v_11209);
    v_11209 = qcdr(v_11209);
    stack[0] = qcdr(v_11209);
    goto v_11019;
v_11020:
    goto v_11039;
v_11035:
    v_11209 = stack[-3];
    goto v_11036;
v_11037:
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcar(v_11208);
    goto v_11038;
v_11039:
    goto v_11035;
v_11036:
    goto v_11037;
v_11038:
    fn = elt(env, 2); // lto_delq
    v_11208 = (*qfn2(fn))(fn, v_11209, v_11208);
    env = stack[-6];
    goto v_11021;
v_11022:
    goto v_11018;
v_11019:
    goto v_11020;
v_11021:
    fn = elt(env, 3); // setcar
    v_11208 = (*qfn2(fn))(fn, stack[0], v_11208);
    env = stack[-6];
    v_11208 = stack[-1];
    v_11208 = qcdr(v_11208);
    stack[-1] = v_11208;
    goto v_10999;
v_10998:
    goto v_11060;
v_11056:
    v_11208 = stack[-3];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11209 = qcdr(v_11208);
    goto v_11057;
v_11058:
    v_11208 = nil;
    goto v_11059;
v_11060:
    goto v_11056;
v_11057:
    goto v_11058;
v_11059:
    fn = elt(env, 3); // setcar
    v_11208 = (*qfn2(fn))(fn, v_11209, v_11208);
    env = stack[-6];
    v_11208 = stack[-3];
    fn = elt(env, 5); // ibalp_getnewwl
    v_11208 = (*qfn1(fn))(fn, v_11208);
    env = stack[-6];
    stack[-1] = v_11208;
    goto v_11076;
v_11072:
    v_11208 = stack[-3];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    stack[0] = qcdr(v_11208);
    goto v_11073;
v_11074:
    goto v_11089;
v_11085:
    v_11209 = stack[-1];
    goto v_11086;
v_11087:
    v_11208 = stack[-3];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcar(v_11208);
    goto v_11088;
v_11089:
    goto v_11085;
v_11086:
    goto v_11087;
v_11088:
    v_11208 = cons(v_11209, v_11208);
    env = stack[-6];
    goto v_11075;
v_11076:
    goto v_11072;
v_11073:
    goto v_11074;
v_11075:
    fn = elt(env, 3); // setcar
    v_11208 = (*qfn2(fn))(fn, stack[0], v_11208);
    env = stack[-6];
    goto v_11104;
v_11100:
    v_11208 = stack[-1];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    stack[0] = qcdr(v_11208);
    goto v_11101;
v_11102:
    goto v_11121;
v_11117:
    v_11209 = stack[-3];
    goto v_11118;
v_11119:
    v_11208 = stack[-1];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcar(v_11208);
    goto v_11120;
v_11121:
    goto v_11117;
v_11118:
    goto v_11119;
v_11120:
    v_11208 = cons(v_11209, v_11208);
    env = stack[-6];
    goto v_11103;
v_11104:
    goto v_11100;
v_11101:
    goto v_11102;
v_11103:
    fn = elt(env, 3); // setcar
    v_11208 = (*qfn2(fn))(fn, stack[0], v_11208);
    env = stack[-6];
    v_11208 = stack[-3];
    fn = elt(env, 5); // ibalp_getnewwl
    v_11208 = (*qfn1(fn))(fn, v_11208);
    env = stack[-6];
    stack[-1] = v_11208;
    v_11208 = stack[-1];
    if (v_11208 == nil) goto v_11140;
    goto v_11147;
v_11143:
    v_11208 = stack[-3];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    stack[0] = qcdr(v_11208);
    goto v_11144;
v_11145:
    goto v_11160;
v_11156:
    v_11209 = stack[-1];
    goto v_11157;
v_11158:
    v_11208 = stack[-3];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcar(v_11208);
    goto v_11159;
v_11160:
    goto v_11156;
v_11157:
    goto v_11158;
v_11159:
    v_11208 = cons(v_11209, v_11208);
    env = stack[-6];
    goto v_11146;
v_11147:
    goto v_11143;
v_11144:
    goto v_11145;
v_11146:
    fn = elt(env, 3); // setcar
    v_11208 = (*qfn2(fn))(fn, stack[0], v_11208);
    env = stack[-6];
    goto v_11175;
v_11171:
    v_11208 = stack[-1];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    stack[0] = qcdr(v_11208);
    goto v_11172;
v_11173:
    goto v_11192;
v_11188:
    v_11209 = stack[-3];
    goto v_11189;
v_11190:
    v_11208 = stack[-1];
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcdr(v_11208);
    v_11208 = qcar(v_11208);
    goto v_11191;
v_11192:
    goto v_11188;
v_11189:
    goto v_11190;
v_11191:
    v_11208 = cons(v_11209, v_11208);
    env = stack[-6];
    goto v_11174;
v_11175:
    goto v_11171;
v_11172:
    goto v_11173;
v_11174:
    fn = elt(env, 3); // setcar
    v_11208 = (*qfn2(fn))(fn, stack[0], v_11208);
    env = stack[-6];
    goto v_11138;
v_11140:
v_11138:
    goto v_10874;
v_10876:
v_10874:
    v_11208 = stack[-5];
    v_11208 = qcdr(v_11208);
    stack[-5] = v_11208;
    goto v_10838;
v_10837:
    v_11208 = nil;
    return onevalue(v_11208);
}



// Code for !*wedgepf2pf

static LispObject CC_Hwedgepf2pf(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10861, v_10862, v_10863;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10828);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10828;
// end of prologue
    stack[-1] = nil;
v_10833:
    v_10861 = stack[0];
    if (v_10861 == nil) goto v_10836;
    else goto v_10837;
v_10836:
    v_10861 = stack[-1];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_10861);
    }
v_10837:
    goto v_10850;
v_10844:
    v_10861 = stack[0];
    v_10861 = qcar(v_10861);
    v_10861 = qcar(v_10861);
    fn = elt(env, 2); // mkuwedge
    v_10863 = (*qfn1(fn))(fn, v_10861);
    env = stack[-2];
    goto v_10845;
v_10846:
    v_10861 = stack[0];
    v_10861 = qcar(v_10861);
    v_10862 = qcdr(v_10861);
    goto v_10847;
v_10848:
    v_10861 = stack[-1];
    goto v_10849;
v_10850:
    goto v_10844;
v_10845:
    goto v_10846;
v_10847:
    goto v_10848;
v_10849:
    v_10861 = acons(v_10863, v_10862, v_10861);
    env = stack[-2];
    stack[-1] = v_10861;
    v_10861 = stack[0];
    v_10861 = qcdr(v_10861);
    stack[0] = v_10861;
    goto v_10833;
    v_10861 = nil;
    return onevalue(v_10861);
}



// Code for equalreplaceby

static LispObject CC_equalreplaceby(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10838, v_10839;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10838 = v_10828;
// end of prologue
    goto v_10835;
v_10831:
    v_10839 = elt(env, 1); // replaceby
    goto v_10832;
v_10833:
    goto v_10834;
v_10835:
    goto v_10831;
v_10832:
    goto v_10833;
v_10834:
    return cons(v_10839, v_10838);
}



// Code for inttovec

static LispObject CC_inttovec(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_10846, v_10847;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10828,v_10829);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10847 = v_10829;
    v_10846 = v_10828;
// end of prologue
    goto v_10836;
v_10832:
    stack[0] = v_10847;
    goto v_10833;
v_10834:
    goto v_10843;
v_10839:
    goto v_10840;
v_10841:
    goto v_10842;
v_10843:
    goto v_10839;
v_10840:
    goto v_10841;
v_10842:
    fn = elt(env, 1); // inttovec!-solve
    v_10846 = (*qfn2(fn))(fn, v_10847, v_10846);
    env = stack[-1];
    goto v_10835;
v_10836:
    goto v_10832;
v_10833:
    goto v_10834;
v_10835:
    {
        LispObject v_10849 = stack[0];
        fn = elt(env, 2); // inttovec1
        return (*qfn2(fn))(fn, v_10849, v_10846);
    }
}



// Code for physopaeval

static LispObject CC_physopaeval(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10927, v_10928, v_10929;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10828);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10828;
// end of prologue
    v_10927 = stack[0];
    fn = elt(env, 4); // physopp
    v_10927 = (*qfn1(fn))(fn, v_10927);
    env = stack[-1];
    if (v_10927 == nil) goto v_10837;
    v_10927 = stack[0];
    if (!symbolp(v_10927)) v_10927 = nil;
    else { v_10927 = qfastgets(v_10927);
           if (v_10927 != nil) { v_10927 = elt(v_10927, 46); // rvalue
#ifdef RECORD_GET
             if (v_10927 != SPID_NOPROP)
                record_get(elt(fastget_names, 46), 1);
             else record_get(elt(fastget_names, 46), 0),
                v_10927 = nil; }
           else record_get(elt(fastget_names, 46), 0); }
#else
             if (v_10927 == SPID_NOPROP) v_10927 = nil; }}
#endif
    v_10929 = v_10927;
    if (v_10927 == nil) goto v_10843;
    goto v_10854;
v_10850:
    v_10927 = v_10929;
    v_10928 = qcar(v_10927);
    goto v_10851;
v_10852:
    v_10927 = elt(env, 2); // !*sq
    goto v_10853;
v_10854:
    goto v_10850;
v_10851:
    goto v_10852;
v_10853:
    if (v_10928 == v_10927) goto v_10848;
    else goto v_10849;
v_10848:
    v_10927 = v_10929;
    v_10927 = qcdr(v_10927);
    v_10927 = qcar(v_10927);
    {
        fn = elt(env, 5); // !*q2a
        return (*qfn1(fn))(fn, v_10927);
    }
v_10849:
    v_10927 = v_10929;
    goto v_10847;
    v_10927 = nil;
v_10847:
    goto v_10841;
v_10843:
    v_10927 = stack[0];
    if (!consp(v_10927)) goto v_10865;
    else goto v_10866;
v_10865:
    v_10927 = stack[0];
    goto v_10841;
v_10866:
    goto v_10876;
v_10872:
    v_10927 = stack[0];
    v_10928 = qcar(v_10927);
    goto v_10873;
v_10874:
    v_10927 = elt(env, 3); // psimpfn
    goto v_10875;
v_10876:
    goto v_10872;
v_10873:
    goto v_10874;
v_10875:
    v_10927 = get(v_10928, v_10927);
    env = stack[-1];
    v_10929 = v_10927;
    if (v_10927 == nil) goto v_10870;
    goto v_10885;
v_10881:
    v_10928 = v_10929;
    goto v_10882;
v_10883:
    v_10927 = stack[0];
    goto v_10884;
v_10885:
    goto v_10881;
v_10882:
    goto v_10883;
v_10884:
        return Lapply1(nil, v_10928, v_10927);
v_10870:
    v_10927 = stack[0];
    v_10927 = qcar(v_10927);
    if (!symbolp(v_10927)) v_10927 = nil;
    else { v_10927 = qfastgets(v_10927);
           if (v_10927 != nil) { v_10927 = elt(v_10927, 9); // opmtch
#ifdef RECORD_GET
             if (v_10927 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_10927 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_10927 == SPID_NOPROP) v_10927 = nil; }}
#endif
    if (v_10927 == nil) goto v_10889;
    v_10927 = stack[0];
    fn = elt(env, 6); // opmtch!*
    v_10927 = (*qfn1(fn))(fn, v_10927);
    v_10929 = v_10927;
    if (v_10927 == nil) goto v_10889;
    v_10927 = v_10929;
    goto v_10841;
v_10889:
    v_10927 = stack[0];
    goto v_10841;
    v_10927 = nil;
v_10841:
    goto v_10835;
v_10837:
    v_10927 = stack[0];
    if (!consp(v_10927)) goto v_10906;
    goto v_10912;
v_10908:
    v_10927 = stack[0];
    v_10928 = qcar(v_10927);
    goto v_10909;
v_10910:
    v_10927 = elt(env, 2); // !*sq
    goto v_10911;
v_10912:
    goto v_10908;
v_10909:
    goto v_10910;
v_10911:
    v_10927 = (v_10928 == v_10927 ? lisp_true : nil);
    goto v_10904;
v_10906:
    v_10927 = nil;
    goto v_10904;
    v_10927 = nil;
v_10904:
    if (v_10927 == nil) goto v_10902;
    v_10927 = stack[0];
    v_10927 = qcdr(v_10927);
    v_10927 = qcar(v_10927);
    {
        fn = elt(env, 5); // !*q2a
        return (*qfn1(fn))(fn, v_10927);
    }
v_10902:
    v_10927 = stack[0];
    goto v_10835;
    v_10927 = nil;
v_10835:
    return onevalue(v_10927);
}



// Code for zero!-roads

static LispObject CC_zeroKroads(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10862, v_10863;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10828);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10828;
// end of prologue
v_10827:
    v_10862 = stack[0];
    if (v_10862 == nil) goto v_10832;
    else goto v_10833;
v_10832:
    v_10862 = nil;
    goto v_10831;
v_10833:
    v_10862 = stack[0];
    v_10862 = qcar(v_10862);
    fn = elt(env, 1); // z!-roads
    v_10862 = (*qfn1(fn))(fn, v_10862);
    env = stack[-2];
    v_10863 = v_10862;
    v_10862 = v_10863;
    if (v_10862 == nil) goto v_10845;
    goto v_10852;
v_10848:
    stack[-1] = v_10863;
    goto v_10849;
v_10850:
    v_10862 = stack[0];
    v_10862 = qcdr(v_10862);
    v_10862 = CC_zeroKroads(elt(env, 0), v_10862);
    goto v_10851;
v_10852:
    goto v_10848;
v_10849:
    goto v_10850;
v_10851:
    {
        LispObject v_10866 = stack[-1];
        return cons(v_10866, v_10862);
    }
v_10845:
    v_10862 = stack[0];
    v_10862 = qcdr(v_10862);
    stack[0] = v_10862;
    goto v_10827;
    v_10862 = nil;
    goto v_10831;
    v_10862 = nil;
v_10831:
    return onevalue(v_10862);
}



// Code for mo_times_ei

static LispObject CC_mo_times_ei(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_10870, v_10871, v_10872;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10828,v_10829);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10872 = v_10829;
    v_10871 = v_10828;
// end of prologue
    v_10870 = v_10872;
    v_10870 = qcar(v_10870);
    if (v_10870 == nil) goto v_10833;
    else goto v_10834;
v_10833:
    v_10870 = v_10871;
    v_10870 = ncons(v_10870);
    env = stack[-1];
    goto v_10832;
v_10834:
    goto v_10846;
v_10842:
    goto v_10851;
v_10847:
    goto v_10848;
v_10849:
    v_10870 = v_10872;
    v_10870 = qcar(v_10870);
    v_10870 = qcar(v_10870);
    goto v_10850;
v_10851:
    goto v_10847;
v_10848:
    goto v_10849;
v_10850:
    v_10870 = (LispObject)(intptr_t)((intptr_t)v_10871 + (intptr_t)v_10870 - TAG_FIXNUM);
    goto v_10843;
v_10844:
    v_10871 = v_10872;
    v_10871 = qcar(v_10871);
    v_10871 = qcdr(v_10871);
    goto v_10845;
v_10846:
    goto v_10842;
v_10843:
    goto v_10844;
v_10845:
    v_10870 = cons(v_10870, v_10871);
    env = stack[-1];
    goto v_10832;
    v_10870 = nil;
v_10832:
    goto v_10866;
v_10862:
    stack[0] = v_10870;
    goto v_10863;
v_10864:
    fn = elt(env, 1); // mo!=deglist
    v_10870 = (*qfn1(fn))(fn, v_10870);
    goto v_10865;
v_10866:
    goto v_10862;
v_10863:
    goto v_10864;
v_10865:
    {
        LispObject v_10874 = stack[0];
        return cons(v_10874, v_10870);
    }
}



// Code for idcons_ordp

static LispObject CC_idcons_ordp(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_10842, v_10843, v_10844;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10842 = v_10829;
    v_10843 = v_10828;
// end of prologue
    goto v_10838;
v_10832:
    v_10844 = v_10843;
    goto v_10833;
v_10834:
    v_10843 = v_10842;
    goto v_10835;
v_10836:
    v_10842 = elt(env, 1); // atom_compare
    goto v_10837;
v_10838:
    goto v_10832;
v_10833:
    goto v_10834;
v_10835:
    goto v_10836;
v_10837:
    {
        fn = elt(env, 2); // cons_ordp
        return (*qfnn(fn))(fn, 3, v_10844, v_10843, v_10842);
    }
}



// Code for general!-reduce!-mod!-p

static LispObject CC_generalKreduceKmodKp(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10884, v_10885, v_10886;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10828);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10828;
// end of prologue
    v_10884 = stack[0];
    if (v_10884 == nil) goto v_10832;
    else goto v_10833;
v_10832:
    v_10884 = nil;
    goto v_10831;
v_10833:
    v_10884 = stack[0];
    if (!consp(v_10884)) goto v_10840;
    else goto v_10841;
v_10840:
    v_10884 = lisp_true;
    goto v_10839;
v_10841:
    v_10884 = stack[0];
    v_10884 = qcar(v_10884);
    v_10884 = (consp(v_10884) ? nil : lisp_true);
    goto v_10839;
    v_10884 = nil;
v_10839:
    if (v_10884 == nil) goto v_10837;
    v_10884 = stack[0];
    fn = elt(env, 1); // general!-modular!-number
    v_10884 = (*qfn1(fn))(fn, v_10884);
    env = stack[-2];
    {
        fn = elt(env, 2); // !*n2f
        return (*qfn1(fn))(fn, v_10884);
    }
v_10837:
    v_10884 = stack[0];
    v_10884 = qcar(v_10884);
    v_10884 = qcdr(v_10884);
    stack[-1] = CC_generalKreduceKmodKp(elt(env, 0), v_10884);
    env = stack[-2];
    v_10884 = stack[0];
    v_10884 = qcdr(v_10884);
    v_10884 = CC_generalKreduceKmodKp(elt(env, 0), v_10884);
    v_10885 = stack[-1];
    v_10886 = v_10885;
    if (v_10886 == nil) goto v_10865;
    else goto v_10866;
v_10865:
    goto v_10864;
v_10866:
    goto v_10878;
v_10872:
    v_10886 = stack[0];
    v_10886 = qcar(v_10886);
    v_10886 = qcar(v_10886);
    goto v_10873;
v_10874:
    goto v_10875;
v_10876:
    goto v_10877;
v_10878:
    goto v_10872;
v_10873:
    goto v_10874;
v_10875:
    goto v_10876;
v_10877:
    return acons(v_10886, v_10885, v_10884);
    v_10884 = nil;
v_10864:
    goto v_10831;
    v_10884 = nil;
v_10831:
    return onevalue(v_10884);
}



// Code for ordexn

static LispObject CC_ordexn(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_10921, v_10922;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10828,v_10829);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_10829;
    stack[-2] = v_10828;
// end of prologue
    stack[0] = nil;
    stack[-3] = nil;
v_10835:
    v_10921 = stack[-1];
    if (v_10921 == nil) goto v_10839;
    else goto v_10840;
v_10839:
    goto v_10847;
v_10843:
    goto v_10844;
v_10845:
    goto v_10855;
v_10851:
    v_10922 = stack[-2];
    goto v_10852;
v_10853:
    v_10921 = stack[-3];
    goto v_10854;
v_10855:
    goto v_10851;
v_10852:
    goto v_10853;
v_10854:
    v_10921 = cons(v_10922, v_10921);
    env = stack[-4];
    v_10921 = Lreverse(nil, v_10921);
    goto v_10846;
v_10847:
    goto v_10843;
v_10844:
    goto v_10845;
v_10846:
    {
        LispObject v_10927 = stack[0];
        return cons(v_10927, v_10921);
    }
v_10840:
    goto v_10864;
v_10860:
    v_10922 = stack[-2];
    goto v_10861;
v_10862:
    v_10921 = stack[-1];
    v_10921 = qcar(v_10921);
    goto v_10863;
v_10864:
    goto v_10860;
v_10861:
    goto v_10862;
v_10863:
    if (v_10922 == v_10921) goto v_10858;
    else goto v_10859;
v_10858:
    v_10921 = nil;
    goto v_10834;
v_10859:
    v_10921 = stack[-2];
    if (v_10921 == nil) goto v_10870;
    goto v_10879;
v_10875:
    v_10922 = stack[-2];
    goto v_10876;
v_10877:
    v_10921 = stack[-1];
    v_10921 = qcar(v_10921);
    goto v_10878;
v_10879:
    goto v_10875;
v_10876:
    goto v_10877;
v_10878:
    fn = elt(env, 2); // ordop
    v_10921 = (*qfn2(fn))(fn, v_10922, v_10921);
    env = stack[-4];
    if (v_10921 == nil) goto v_10870;
    goto v_10888;
v_10884:
    goto v_10885;
v_10886:
    goto v_10895;
v_10891:
    goto v_10902;
v_10898:
    v_10922 = stack[-2];
    goto v_10899;
v_10900:
    v_10921 = stack[-3];
    goto v_10901;
v_10902:
    goto v_10898;
v_10899:
    goto v_10900;
v_10901:
    v_10921 = cons(v_10922, v_10921);
    env = stack[-4];
    v_10922 = Lreverse(nil, v_10921);
    env = stack[-4];
    goto v_10892;
v_10893:
    v_10921 = stack[-1];
    goto v_10894;
v_10895:
    goto v_10891;
v_10892:
    goto v_10893;
v_10894:
    v_10921 = Lappend(nil, v_10922, v_10921);
    goto v_10887;
v_10888:
    goto v_10884;
v_10885:
    goto v_10886;
v_10887:
    {
        LispObject v_10928 = stack[0];
        return cons(v_10928, v_10921);
    }
v_10870:
    goto v_10913;
v_10909:
    v_10921 = stack[-1];
    v_10922 = qcar(v_10921);
    goto v_10910;
v_10911:
    v_10921 = stack[-3];
    goto v_10912;
v_10913:
    goto v_10909;
v_10910:
    goto v_10911;
v_10912:
    v_10921 = cons(v_10922, v_10921);
    env = stack[-4];
    stack[-3] = v_10921;
    v_10921 = stack[-1];
    v_10921 = qcdr(v_10921);
    stack[-1] = v_10921;
    v_10921 = stack[0];
    v_10921 = (v_10921 == nil ? lisp_true : nil);
    stack[0] = v_10921;
    goto v_10838;
v_10838:
    goto v_10835;
v_10834:
    return onevalue(v_10921);
}



// Code for next!-random!-number

static LispObject CC_nextKrandomKnumber(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10912, v_10913, v_10914, v_10915;
    argcheck(nargs, 0, "next-random-number");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    goto v_10841;
v_10837:
    v_10913 = qvalue(elt(env, 2)); // unidev_next!*
    goto v_10838;
v_10839:
    v_10912 = (LispObject)864+TAG_FIXNUM; // 54
    goto v_10840;
v_10841:
    goto v_10837;
v_10838:
    goto v_10839;
v_10840:
    if (v_10913 == v_10912) goto v_10835;
    else goto v_10836;
v_10835:
    v_10912 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 2)) = v_10912; // unidev_next!*
    goto v_10834;
v_10836:
    v_10912 = qvalue(elt(env, 2)); // unidev_next!*
    v_10912 = (LispObject)((intptr_t)(v_10912) + 0x10);
    qvalue(elt(env, 2)) = v_10912; // unidev_next!*
    goto v_10834;
v_10834:
    goto v_10857;
v_10853:
    v_10913 = qvalue(elt(env, 3)); // unidev_nextp!*
    goto v_10854;
v_10855:
    v_10912 = (LispObject)864+TAG_FIXNUM; // 54
    goto v_10856;
v_10857:
    goto v_10853;
v_10854:
    goto v_10855;
v_10856:
    if (v_10913 == v_10912) goto v_10851;
    else goto v_10852;
v_10851:
    v_10912 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 3)) = v_10912; // unidev_nextp!*
    goto v_10850;
v_10852:
    v_10912 = qvalue(elt(env, 3)); // unidev_nextp!*
    v_10912 = (LispObject)((intptr_t)(v_10912) + 0x10);
    qvalue(elt(env, 3)) = v_10912; // unidev_nextp!*
    goto v_10850;
v_10850:
    goto v_10869;
v_10865:
    goto v_10874;
v_10870:
    v_10913 = qvalue(elt(env, 4)); // unidev_vec!*
    goto v_10871;
v_10872:
    v_10912 = qvalue(elt(env, 2)); // unidev_next!*
    goto v_10873;
v_10874:
    goto v_10870;
v_10871:
    goto v_10872;
v_10873:
    v_10914 = *(LispObject *)((char *)v_10913 + (CELL-TAG_VECTOR) + (((intptr_t)v_10912-TAG_FIXNUM)/(16/CELL)));
    goto v_10866;
v_10867:
    goto v_10882;
v_10878:
    v_10913 = qvalue(elt(env, 4)); // unidev_vec!*
    goto v_10879;
v_10880:
    v_10912 = qvalue(elt(env, 3)); // unidev_nextp!*
    goto v_10881;
v_10882:
    goto v_10878;
v_10879:
    goto v_10880;
v_10881:
    v_10912 = *(LispObject *)((char *)v_10913 + (CELL-TAG_VECTOR) + (((intptr_t)v_10912-TAG_FIXNUM)/(16/CELL)));
    goto v_10868;
v_10869:
    goto v_10865;
v_10866:
    goto v_10867;
v_10868:
    v_10912 = (LispObject)(intptr_t)((intptr_t)v_10914 - (intptr_t)v_10912 + TAG_FIXNUM);
    v_10914 = v_10912;
    v_10912 = v_10914;
    v_10912 = ((intptr_t)(v_10912) < 0 ? lisp_true : nil);
    if (v_10912 == nil) goto v_10890;
    goto v_10897;
v_10893:
    v_10913 = v_10914;
    goto v_10894;
v_10895:
    v_10912 = qvalue(elt(env, 5)); // randommodulus!*
    goto v_10896;
v_10897:
    goto v_10893;
v_10894:
    goto v_10895;
v_10896:
    v_10912 = (LispObject)(intptr_t)((intptr_t)v_10913 + (intptr_t)v_10912 - TAG_FIXNUM);
    v_10914 = v_10912;
    goto v_10888;
v_10890:
v_10888:
    goto v_10907;
v_10901:
    v_10913 = qvalue(elt(env, 4)); // unidev_vec!*
    goto v_10902;
v_10903:
    v_10915 = qvalue(elt(env, 2)); // unidev_next!*
    goto v_10904;
v_10905:
    v_10912 = v_10914;
    goto v_10906;
v_10907:
    goto v_10901;
v_10902:
    goto v_10903;
v_10904:
    goto v_10905;
v_10906:
    *(LispObject *)((char *)v_10913 + (CELL-TAG_VECTOR) + (((intptr_t)v_10915-TAG_FIXNUM)/(16/CELL))) = v_10912;
    v_10912 = v_10914;
    return onevalue(v_10912);
}



// Code for rrdls

static LispObject CC_rrdls(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10925, v_10926, v_10927;
    LispObject fn;
    argcheck(nargs, 0, "rrdls");
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
    stack[0] = nil;
v_10834:
    fn = elt(env, 8); // rread1
    v_10925 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_10925;
    goto v_10846;
v_10842:
    v_10926 = qvalue(elt(env, 2)); // ttype!*
    goto v_10843;
v_10844:
    v_10925 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_10845;
v_10846:
    goto v_10842;
v_10843:
    goto v_10844;
v_10845:
    if (v_10926 == v_10925) goto v_10841;
    goto v_10835;
v_10841:
    goto v_10855;
v_10851:
    v_10926 = stack[-1];
    goto v_10852;
v_10853:
    v_10925 = elt(env, 3); // !)
    goto v_10854;
v_10855:
    goto v_10851;
v_10852:
    goto v_10853;
v_10854:
    if (v_10926 == v_10925) goto v_10849;
    else goto v_10850;
v_10849:
    v_10925 = stack[0];
    goto v_10833;
v_10850:
    goto v_10865;
v_10861:
    v_10926 = stack[-1];
    goto v_10862;
v_10863:
    v_10925 = elt(env, 4); // !.
    goto v_10864;
v_10865:
    goto v_10861;
v_10862:
    goto v_10863;
v_10864:
    if (v_10926 == v_10925) goto v_10860;
    goto v_10835;
v_10860:
    fn = elt(env, 8); // rread1
    v_10925 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_10925;
    fn = elt(env, 9); // ptoken
    v_10925 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_10927 = v_10925;
    goto v_10882;
v_10878:
    v_10926 = qvalue(elt(env, 2)); // ttype!*
    goto v_10879;
v_10880:
    v_10925 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_10881;
v_10882:
    goto v_10878;
v_10879:
    goto v_10880;
v_10881:
    if (v_10926 == v_10925) goto v_10877;
    v_10925 = lisp_true;
    goto v_10875;
v_10877:
    goto v_10892;
v_10888:
    v_10926 = v_10927;
    goto v_10889;
v_10890:
    v_10925 = elt(env, 3); // !)
    goto v_10891;
v_10892:
    goto v_10888;
v_10889:
    goto v_10890;
v_10891:
    v_10925 = (v_10926 == v_10925 ? lisp_true : nil);
    v_10925 = (v_10925 == nil ? lisp_true : nil);
    goto v_10875;
    v_10925 = nil;
v_10875:
    if (v_10925 == nil) goto v_10873;
    v_10925 = elt(env, 5); // " "
    qvalue(elt(env, 6)) = v_10925; // nxtsym!*
    goto v_10903;
v_10899:
    v_10926 = elt(env, 7); // "Invalid S-expression"
    goto v_10900;
v_10901:
    v_10925 = nil;
    goto v_10902;
v_10903:
    goto v_10899;
v_10900:
    goto v_10901;
v_10902:
    fn = elt(env, 10); // symerr
    v_10925 = (*qfn2(fn))(fn, v_10926, v_10925);
    env = stack[-2];
    goto v_10871;
v_10873:
    goto v_10913;
v_10909:
    v_10926 = stack[0];
    goto v_10910;
v_10911:
    v_10925 = stack[-1];
    goto v_10912;
v_10913:
    goto v_10909;
v_10910:
    goto v_10911;
v_10912:
        return Lnconc(nil, v_10926, v_10925);
v_10871:
v_10835:
    goto v_10921;
v_10917:
    goto v_10918;
v_10919:
    v_10925 = stack[-1];
    v_10925 = ncons(v_10925);
    env = stack[-2];
    goto v_10920;
v_10921:
    goto v_10917;
v_10918:
    goto v_10919;
v_10920:
    v_10925 = Lnconc(nil, stack[0], v_10925);
    env = stack[-2];
    stack[0] = v_10925;
    goto v_10834;
v_10833:
    return onevalue(v_10925);
}



// Code for aex_fvarl

static LispObject CC_aex_fvarl(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10841;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10828);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10828;
// end of prologue
    goto v_10835;
v_10831:
    v_10841 = stack[0];
    fn = elt(env, 1); // aex_varl
    stack[-1] = (*qfn1(fn))(fn, v_10841);
    env = stack[-2];
    goto v_10832;
v_10833:
    v_10841 = stack[0];
    fn = elt(env, 2); // aex_ctx
    v_10841 = (*qfn1(fn))(fn, v_10841);
    env = stack[-2];
    fn = elt(env, 3); // ctx_idl
    v_10841 = (*qfn1(fn))(fn, v_10841);
    env = stack[-2];
    goto v_10834;
v_10835:
    goto v_10831;
v_10832:
    goto v_10833;
v_10834:
    {
        LispObject v_10844 = stack[-1];
        fn = elt(env, 4); // lto_setminus
        return (*qfn2(fn))(fn, v_10844, v_10841);
    }
}



// Code for rl_nnf

static LispObject CC_rl_nnf(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10839;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10828);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10839 = v_10828;
// end of prologue
    goto v_10835;
v_10831:
    stack[0] = qvalue(elt(env, 1)); // rl_nnf!*
    goto v_10832;
v_10833:
    v_10839 = ncons(v_10839);
    env = stack[-1];
    goto v_10834;
v_10835:
    goto v_10831;
v_10832:
    goto v_10833;
v_10834:
    {
        LispObject v_10841 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_10841, v_10839);
    }
}



// Code for sfto_ucontentf1

static LispObject CC_sfto_ucontentf1(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_10901, v_10902;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10828,v_10829);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10829;
    stack[-1] = v_10828;
// end of prologue
    stack[-2] = nil;
v_10835:
    v_10901 = stack[-1];
    if (!consp(v_10901)) goto v_10848;
    else goto v_10849;
v_10848:
    v_10901 = lisp_true;
    goto v_10847;
v_10849:
    v_10901 = stack[-1];
    v_10901 = qcar(v_10901);
    v_10901 = (consp(v_10901) ? nil : lisp_true);
    goto v_10847;
    v_10901 = nil;
v_10847:
    if (v_10901 == nil) goto v_10845;
    v_10901 = lisp_true;
    goto v_10843;
v_10845:
    goto v_10865;
v_10861:
    v_10901 = stack[-1];
    v_10901 = qcar(v_10901);
    v_10901 = qcar(v_10901);
    v_10902 = qcar(v_10901);
    goto v_10862;
v_10863:
    v_10901 = stack[0];
    goto v_10864;
v_10865:
    goto v_10861;
v_10862:
    goto v_10863;
v_10864:
    v_10901 = Lneq(nil, v_10902, v_10901);
    env = stack[-3];
    goto v_10843;
    v_10901 = nil;
v_10843:
    if (v_10901 == nil) goto v_10841;
    goto v_10836;
v_10841:
    goto v_10876;
v_10872:
    v_10901 = stack[-1];
    v_10901 = qcar(v_10901);
    v_10902 = qcdr(v_10901);
    goto v_10873;
v_10874:
    v_10901 = stack[-2];
    goto v_10875;
v_10876:
    goto v_10872;
v_10873:
    goto v_10874;
v_10875:
    v_10901 = cons(v_10902, v_10901);
    env = stack[-3];
    stack[-2] = v_10901;
    v_10901 = stack[-1];
    v_10901 = qcdr(v_10901);
    stack[-1] = v_10901;
    goto v_10835;
v_10836:
    v_10901 = stack[-1];
    v_10902 = v_10901;
v_10837:
    v_10901 = stack[-2];
    if (v_10901 == nil) goto v_10886;
    else goto v_10887;
v_10886:
    v_10901 = v_10902;
    goto v_10834;
v_10887:
    goto v_10895;
v_10891:
    v_10901 = stack[-2];
    v_10901 = qcar(v_10901);
    goto v_10892;
v_10893:
    goto v_10894;
v_10895:
    goto v_10891;
v_10892:
    goto v_10893;
v_10894:
    fn = elt(env, 1); // sfto_gcdf!*
    v_10901 = (*qfn2(fn))(fn, v_10901, v_10902);
    env = stack[-3];
    v_10902 = v_10901;
    v_10901 = stack[-2];
    v_10901 = qcdr(v_10901);
    stack[-2] = v_10901;
    goto v_10837;
v_10834:
    return onevalue(v_10901);
}



// Code for findnthroot

static LispObject CC_findnthroot(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10831;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10831 = v_10828;
// end of prologue
    v_10831 = nil;
    return onevalue(v_10831);
}



// Code for lx2xx

static LispObject CC_lx2xx(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10906, v_10907;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10828);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_10828;
// end of prologue
    v_10906 = stack[-2];
    if (!consp(v_10906)) goto v_10845;
    else goto v_10846;
v_10845:
    v_10906 = lisp_true;
    goto v_10844;
v_10846:
    v_10906 = stack[-2];
    v_10906 = qcar(v_10906);
    v_10906 = (consp(v_10906) ? nil : lisp_true);
    goto v_10844;
    v_10906 = nil;
v_10844:
    if (v_10906 == nil) goto v_10842;
    v_10906 = lisp_true;
    goto v_10840;
v_10842:
    v_10906 = stack[-2];
    v_10906 = qcar(v_10906);
    if (!consp(v_10906)) goto v_10859;
    else goto v_10860;
v_10859:
    v_10906 = lisp_true;
    goto v_10858;
v_10860:
    v_10906 = stack[-2];
    v_10906 = qcar(v_10906);
    v_10906 = qcar(v_10906);
    v_10906 = (consp(v_10906) ? nil : lisp_true);
    goto v_10858;
    v_10906 = nil;
v_10858:
    goto v_10840;
    v_10906 = nil;
v_10840:
    if (v_10906 == nil) goto v_10838;
    v_10906 = stack[-2];
    goto v_10833;
v_10838:
    v_10906 = stack[-2];
    v_10906 = qcdr(v_10906);
    v_10906 = qcar(v_10906);
    stack[-3] = v_10906;
    v_10906 = stack[-3];
    fn = elt(env, 2); // lastnondomain
    v_10906 = (*qfn1(fn))(fn, v_10906);
    env = stack[-4];
    v_10906 = qcdr(v_10906);
    stack[-1] = v_10906;
    goto v_10884;
v_10878:
    v_10906 = stack[-2];
    stack[0] = qcar(v_10906);
    goto v_10879;
v_10880:
    goto v_10892;
v_10888:
    goto v_10899;
v_10895:
    v_10907 = stack[-1];
    goto v_10896;
v_10897:
    v_10906 = stack[-3];
    goto v_10898;
v_10899:
    goto v_10895;
v_10896:
    goto v_10897;
v_10898:
    fn = elt(env, 3); // delet
    v_10906 = (*qfn2(fn))(fn, v_10907, v_10906);
    env = stack[-4];
    fn = elt(env, 4); // xxsort
    v_10907 = (*qfn1(fn))(fn, v_10906);
    env = stack[-4];
    goto v_10889;
v_10890:
    v_10906 = stack[-1];
    goto v_10891;
v_10892:
    goto v_10888;
v_10889:
    goto v_10890;
v_10891:
    v_10907 = Lappend(nil, v_10907, v_10906);
    goto v_10881;
v_10882:
    v_10906 = stack[-2];
    v_10906 = qcdr(v_10906);
    v_10906 = qcdr(v_10906);
    goto v_10883;
v_10884:
    goto v_10878;
v_10879:
    goto v_10880;
v_10881:
    goto v_10882;
v_10883:
    {
        LispObject v_10912 = stack[0];
        return list2star(v_10912, v_10907, v_10906);
    }
v_10833:
    return onevalue(v_10906);
}



// Code for rl_simp1

static LispObject CC_rl_simp1(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_11111, v_11112, v_11113, v_11114;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10828);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_10828;
// end of prologue
v_10827:
    v_11111 = qvalue(elt(env, 2)); // rl_cid!*
    if (v_11111 == nil) goto v_10837;
    else goto v_10838;
v_10837:
    v_11111 = elt(env, 3); // "select a context"
    v_11111 = ncons(v_11111);
    env = stack[-5];
    fn = elt(env, 11); // rederr
    v_11111 = (*qfn1(fn))(fn, v_11111);
    env = stack[-5];
    goto v_10836;
v_10838:
v_10836:
    v_11111 = stack[0];
    if (!consp(v_11111)) goto v_10845;
    else goto v_10846;
v_10845:
    v_11111 = stack[0];
    {
        fn = elt(env, 12); // rl_simpatom
        return (*qfn1(fn))(fn, v_11111);
    }
v_10846:
    v_11111 = lisp_true;
// Binding !*strict_argcount
// FLUIDBIND: reloadenv=5 litvec-offset=4 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 4, -1);
    qvalue(elt(env, 4)) = v_11111; // !*strict_argcount
    v_11111 = stack[0];
    fn = elt(env, 13); // argnochk
    v_11111 = (*qfn1(fn))(fn, v_11111);
    env = stack[-5];
    ;}  // end of a binding scope
    goto v_10863;
v_10859:
    v_11111 = stack[0];
    v_11112 = qcar(v_11111);
    goto v_10860;
v_10861:
    v_11111 = elt(env, 5); // rl_simpfn
    goto v_10862;
v_10863:
    goto v_10859;
v_10860:
    goto v_10861;
v_10862:
    v_11111 = get(v_11112, v_11111);
    env = stack[-5];
    v_11112 = v_11111;
    if (v_11111 == nil) goto v_10857;
    v_11111 = v_11112;
    if (!symbolp(v_11111)) v_11111 = nil;
    else { v_11111 = qfastgets(v_11111);
           if (v_11111 != nil) { v_11111 = elt(v_11111, 62); // full
#ifdef RECORD_GET
             if (v_11111 == SPID_NOPROP)
                record_get(elt(fastget_names, 62), 0),
                v_11111 = nil;
             else record_get(elt(fastget_names, 62), 1),
                v_11111 = lisp_true; }
           else record_get(elt(fastget_names, 62), 0); }
#else
             if (v_11111 == SPID_NOPROP) v_11111 = nil; else v_11111 = lisp_true; }}
#endif
    if (v_11111 == nil) goto v_10870;
    goto v_10878;
v_10874:
    stack[-1] = v_11112;
    goto v_10875;
v_10876:
    v_11111 = stack[0];
    v_11111 = ncons(v_11111);
    env = stack[-5];
    goto v_10877;
v_10878:
    goto v_10874;
v_10875:
    goto v_10876;
v_10877:
    {
        LispObject v_11120 = stack[-1];
        fn = elt(env, 14); // apply
        return (*qfn2(fn))(fn, v_11120, v_11111);
    }
v_10870:
    goto v_10889;
v_10885:
    stack[-1] = v_11112;
    goto v_10886;
v_10887:
    v_11111 = stack[0];
    v_11111 = qcdr(v_11111);
    v_11111 = ncons(v_11111);
    env = stack[-5];
    goto v_10888;
v_10889:
    goto v_10885;
v_10886:
    goto v_10887;
v_10888:
    {
        LispObject v_11121 = stack[-1];
        fn = elt(env, 14); // apply
        return (*qfn2(fn))(fn, v_11121, v_11111);
    }
    v_11111 = nil;
    goto v_10833;
v_10857:
    goto v_10903;
v_10899:
    v_11111 = stack[0];
    v_11113 = qcar(v_11111);
    goto v_10900;
v_10901:
    goto v_10911;
v_10907:
    v_11111 = qvalue(elt(env, 2)); // rl_cid!*
    v_11112 = qcar(v_11111);
    goto v_10908;
v_10909:
    v_11111 = elt(env, 6); // simpfnname
    goto v_10910;
v_10911:
    goto v_10907;
v_10908:
    goto v_10909;
v_10910:
    v_11111 = get(v_11112, v_11111);
    env = stack[-5];
    goto v_10902;
v_10903:
    goto v_10899;
v_10900:
    goto v_10901;
v_10902:
    v_11111 = get(v_11113, v_11111);
    env = stack[-5];
    v_11112 = v_11111;
    if (v_11111 == nil) goto v_10897;
    v_11111 = v_11112;
    if (!symbolp(v_11111)) v_11111 = nil;
    else { v_11111 = qfastgets(v_11111);
           if (v_11111 != nil) { v_11111 = elt(v_11111, 62); // full
#ifdef RECORD_GET
             if (v_11111 == SPID_NOPROP)
                record_get(elt(fastget_names, 62), 0),
                v_11111 = nil;
             else record_get(elt(fastget_names, 62), 1),
                v_11111 = lisp_true; }
           else record_get(elt(fastget_names, 62), 0); }
#else
             if (v_11111 == SPID_NOPROP) v_11111 = nil; else v_11111 = lisp_true; }}
#endif
    if (v_11111 == nil) goto v_10918;
    goto v_10926;
v_10922:
    stack[-1] = v_11112;
    goto v_10923;
v_10924:
    v_11111 = stack[0];
    v_11111 = ncons(v_11111);
    env = stack[-5];
    goto v_10925;
v_10926:
    goto v_10922;
v_10923:
    goto v_10924;
v_10925:
    {
        LispObject v_11122 = stack[-1];
        fn = elt(env, 14); // apply
        return (*qfn2(fn))(fn, v_11122, v_11111);
    }
v_10918:
    goto v_10937;
v_10933:
    stack[-1] = v_11112;
    goto v_10934;
v_10935:
    v_11111 = stack[0];
    v_11111 = qcdr(v_11111);
    v_11111 = ncons(v_11111);
    env = stack[-5];
    goto v_10936;
v_10937:
    goto v_10933;
v_10934:
    goto v_10935;
v_10936:
    {
        LispObject v_11123 = stack[-1];
        fn = elt(env, 14); // apply
        return (*qfn2(fn))(fn, v_11123, v_11111);
    }
    v_11111 = nil;
    goto v_10833;
v_10897:
    v_11111 = stack[0];
    v_11111 = qcar(v_11111);
    if (!symbolp(v_11111)) v_11111 = nil;
    else { v_11111 = qfastgets(v_11111);
           if (v_11111 != nil) { v_11111 = elt(v_11111, 45); // psopfn
#ifdef RECORD_GET
             if (v_11111 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v_11111 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v_11111 == SPID_NOPROP) v_11111 = nil; }}
#endif
    v_11112 = v_11111;
    if (v_11111 == nil) goto v_10945;
    goto v_10954;
v_10950:
    goto v_10951;
v_10952:
    v_11111 = stack[0];
    v_11111 = qcdr(v_11111);
    goto v_10953;
v_10954:
    goto v_10950;
v_10951:
    goto v_10952;
v_10953:
    v_11111 = Lapply1(nil, v_11112, v_11111);
    env = stack[-5];
    stack[-1] = v_11111;
    goto v_10966;
v_10962:
    v_11112 = stack[-1];
    goto v_10963;
v_10964:
    v_11111 = stack[0];
    goto v_10965;
v_10966:
    goto v_10962;
v_10963:
    goto v_10964;
v_10965:
    if (equal(v_11112, v_11111)) goto v_10961;
    v_11111 = stack[-1];
    stack[0] = v_11111;
    goto v_10827;
v_10961:
    goto v_10943;
v_10945:
v_10943:
    v_11111 = stack[0];
    v_11111 = qcar(v_11111);
    if (!symbolp(v_11111)) v_11111 = nil;
    else { v_11111 = qfastgets(v_11111);
           if (v_11111 != nil) { v_11111 = elt(v_11111, 59); // opfn
#ifdef RECORD_GET
             if (v_11111 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v_11111 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v_11111 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v_11111 == SPID_NOPROP) v_11111 = nil; else v_11111 = lisp_true; }}
#endif
    if (v_11111 == nil) goto v_10974;
    goto v_10984;
v_10980:
    v_11111 = stack[0];
    stack[-4] = qcar(v_11111);
    goto v_10981;
v_10982:
    v_11111 = stack[0];
    v_11111 = qcdr(v_11111);
    stack[-3] = v_11111;
    v_11111 = stack[-3];
    if (v_11111 == nil) goto v_10997;
    else goto v_10998;
v_10997:
    v_11111 = nil;
    goto v_10991;
v_10998:
    v_11111 = stack[-3];
    v_11111 = qcar(v_11111);
    fn = elt(env, 15); // reval
    v_11111 = (*qfn1(fn))(fn, v_11111);
    env = stack[-5];
    v_11111 = ncons(v_11111);
    env = stack[-5];
    stack[-1] = v_11111;
    stack[-2] = v_11111;
v_10992:
    v_11111 = stack[-3];
    v_11111 = qcdr(v_11111);
    stack[-3] = v_11111;
    v_11111 = stack[-3];
    if (v_11111 == nil) goto v_11011;
    else goto v_11012;
v_11011:
    v_11111 = stack[-2];
    goto v_10991;
v_11012:
    goto v_11020;
v_11016:
    stack[0] = stack[-1];
    goto v_11017;
v_11018:
    v_11111 = stack[-3];
    v_11111 = qcar(v_11111);
    fn = elt(env, 15); // reval
    v_11111 = (*qfn1(fn))(fn, v_11111);
    env = stack[-5];
    v_11111 = ncons(v_11111);
    env = stack[-5];
    goto v_11019;
v_11020:
    goto v_11016;
v_11017:
    goto v_11018;
v_11019:
    v_11111 = Lrplacd(nil, stack[0], v_11111);
    env = stack[-5];
    v_11111 = stack[-1];
    v_11111 = qcdr(v_11111);
    stack[-1] = v_11111;
    goto v_10992;
v_10991:
    goto v_10983;
v_10984:
    goto v_10980;
v_10981:
    goto v_10982;
v_10983:
    fn = elt(env, 14); // apply
    v_11111 = (*qfn2(fn))(fn, stack[-4], v_11111);
    env = stack[-5];
    stack[0] = v_11111;
    goto v_10827;
v_10974:
    v_11111 = stack[0];
    v_11111 = qcar(v_11111);
    if (!symbolp(v_11111)) v_11111 = nil;
    else { v_11111 = qfastgets(v_11111);
           if (v_11111 != nil) { v_11111 = elt(v_11111, 44); // prepfn2
#ifdef RECORD_GET
             if (v_11111 != SPID_NOPROP)
                record_get(elt(fastget_names, 44), 1);
             else record_get(elt(fastget_names, 44), 0),
                v_11111 = nil; }
           else record_get(elt(fastget_names, 44), 0); }
#else
             if (v_11111 == SPID_NOPROP) v_11111 = nil; }}
#endif
    v_11112 = v_11111;
    if (v_11111 == nil) goto v_11033;
    goto v_11043;
v_11039:
    stack[-1] = v_11112;
    goto v_11040;
v_11041:
    v_11111 = stack[0];
    v_11111 = ncons(v_11111);
    env = stack[-5];
    goto v_11042;
v_11043:
    goto v_11039;
v_11040:
    goto v_11041;
v_11042:
    fn = elt(env, 14); // apply
    v_11111 = (*qfn2(fn))(fn, stack[-1], v_11111);
    env = stack[-5];
    stack[0] = v_11111;
    goto v_10827;
v_11033:
    v_11111 = stack[0];
    v_11111 = qcar(v_11111);
    fn = elt(env, 16); // ioto_form2str
    v_11111 = (*qfn1(fn))(fn, v_11111);
    env = stack[-5];
    stack[-1] = v_11111;
    v_11111 = stack[0];
    v_11111 = qcar(v_11111);
    if (!symbolp(v_11111)) v_11111 = nil;
    else { v_11111 = qfastgets(v_11111);
           if (v_11111 != nil) { v_11111 = elt(v_11111, 37); // prtch
#ifdef RECORD_GET
             if (v_11111 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v_11111 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v_11111 == SPID_NOPROP) v_11111 = nil; }}
#endif
    v_11112 = v_11111;
    if (v_11111 == nil) goto v_11053;
    goto v_11067;
v_11059:
    v_11111 = v_11112;
    fn = elt(env, 16); // ioto_form2str
    v_11114 = (*qfn1(fn))(fn, v_11111);
    env = stack[-5];
    goto v_11060;
v_11061:
    v_11113 = elt(env, 7); // " ("
    goto v_11062;
v_11063:
    v_11112 = stack[-1];
    goto v_11064;
v_11065:
    v_11111 = elt(env, 8); // ")"
    goto v_11066;
v_11067:
    goto v_11059;
v_11060:
    goto v_11061;
v_11062:
    goto v_11063;
v_11064:
    goto v_11065;
v_11066:
    v_11111 = list4(v_11114, v_11113, v_11112, v_11111);
    env = stack[-5];
    fn = elt(env, 17); // lto_sconcat
    v_11111 = (*qfn1(fn))(fn, v_11111);
    env = stack[-5];
    stack[-1] = v_11111;
    goto v_11051;
v_11053:
v_11051:
    goto v_11078;
v_11074:
    v_11112 = stack[-1];
    goto v_11075;
v_11076:
    v_11111 = elt(env, 9); // "predicate"
    goto v_11077;
v_11078:
    goto v_11074;
v_11075:
    goto v_11076;
v_11077:
    fn = elt(env, 18); // redmsg
    v_11111 = (*qfn2(fn))(fn, v_11112, v_11111);
    env = stack[-5];
    goto v_11088;
v_11082:
    v_11111 = stack[0];
    v_11114 = qcar(v_11111);
    goto v_11083;
v_11084:
    goto v_11096;
v_11092:
    v_11111 = qvalue(elt(env, 2)); // rl_cid!*
    v_11112 = qcar(v_11111);
    goto v_11093;
v_11094:
    v_11111 = elt(env, 6); // simpfnname
    goto v_11095;
v_11096:
    goto v_11092;
v_11093:
    goto v_11094;
v_11095:
    v_11113 = get(v_11112, v_11111);
    env = stack[-5];
    goto v_11085;
v_11086:
    goto v_11105;
v_11101:
    v_11111 = qvalue(elt(env, 2)); // rl_cid!*
    v_11112 = qcar(v_11111);
    goto v_11102;
v_11103:
    v_11111 = elt(env, 10); // simpdefault
    goto v_11104;
v_11105:
    goto v_11101;
v_11102:
    goto v_11103;
v_11104:
    v_11111 = get(v_11112, v_11111);
    env = stack[-5];
    goto v_11087;
v_11088:
    goto v_11082;
v_11083:
    goto v_11084;
v_11085:
    goto v_11086;
v_11087:
    v_11111 = Lputprop(nil, 3, v_11114, v_11113, v_11111);
    env = stack[-5];
    v_11111 = stack[0];
    stack[0] = v_11111;
    goto v_10827;
v_10833:
    return onevalue(v_11111);
}



// Code for mvar_member

static LispObject CC_mvar_member(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_10862, v_10863, v_10864, v_10865;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10864 = v_10829;
    v_10865 = v_10828;
// end of prologue
    goto v_10839;
v_10835:
    v_10863 = v_10865;
    goto v_10836;
v_10837:
    v_10862 = v_10864;
    goto v_10838;
v_10839:
    goto v_10835;
v_10836:
    goto v_10837;
v_10838:
    if (equal(v_10863, v_10862)) goto v_10833;
    else goto v_10834;
v_10833:
    v_10862 = lisp_true;
    goto v_10832;
v_10834:
    v_10862 = v_10864;
    if (!consp(v_10862)) goto v_10848;
    goto v_10855;
v_10851:
    v_10862 = v_10865;
    goto v_10852;
v_10853:
    v_10863 = v_10864;
    v_10863 = qcdr(v_10863);
    goto v_10854;
v_10855:
    goto v_10851;
v_10852:
    goto v_10853;
v_10854:
    {
        fn = elt(env, 1); // arglist_member
        return (*qfn2(fn))(fn, v_10862, v_10863);
    }
v_10848:
    v_10862 = nil;
    goto v_10846;
    v_10862 = nil;
v_10846:
    goto v_10832;
    v_10862 = nil;
v_10832:
    return onevalue(v_10862);
}



// Code for tobvarir

static LispObject CC_tobvarir(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10859, v_10860;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10828);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_10828;
// end of prologue
    v_10859 = stack[-1];
    if (v_10859 == nil) goto v_10836;
    goto v_10845;
v_10839:
    stack[-2] = elt(env, 1); // bvar
    goto v_10840;
v_10841:
    goto v_10852;
v_10848:
    v_10859 = stack[-1];
    v_10860 = qcar(v_10859);
    goto v_10849;
v_10850:
    v_10859 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10851;
v_10852:
    goto v_10848;
v_10849:
    goto v_10850;
v_10851:
    stack[0] = list2(v_10860, v_10859);
    env = stack[-3];
    goto v_10842;
v_10843:
    v_10859 = stack[-1];
    v_10859 = qcdr(v_10859);
    v_10859 = CC_tobvarir(elt(env, 0), v_10859);
    goto v_10844;
v_10845:
    goto v_10839;
v_10840:
    goto v_10841;
v_10842:
    goto v_10843;
v_10844:
    {
        LispObject v_10864 = stack[-2];
        LispObject v_10865 = stack[0];
        return acons(v_10864, v_10865, v_10859);
    }
v_10836:
    v_10859 = nil;
    return onevalue(v_10859);
}



// Code for floatprop

static LispObject CC_floatprop(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10843, v_10844;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10828);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_10843 = v_10828;
// end of prologue
    v_10844 = v_10843;
    v_10844 = Lfloatp(nil, v_10844);
    env = stack[0];
    if (v_10844 == nil) goto v_10832;
    else goto v_10831;
v_10832:
    goto v_10840;
v_10836:
    goto v_10837;
v_10838:
    v_10844 = elt(env, 1); // !:rd!:
    goto v_10839;
v_10840:
    goto v_10836;
v_10837:
    goto v_10838;
v_10839:
        return Leqcar(nil, v_10843, v_10844);
v_10831:
    return onevalue(v_10844);
}



// Code for gpexp1p

static LispObject CC_gpexp1p(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10851;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10828);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10828;
// end of prologue
v_10827:
    v_10851 = stack[0];
    if (v_10851 == nil) goto v_10832;
    else goto v_10833;
v_10832:
    v_10851 = lisp_true;
    goto v_10831;
v_10833:
    v_10851 = stack[0];
    v_10851 = qcar(v_10851);
    fn = elt(env, 1); // gpexpp
    v_10851 = (*qfn1(fn))(fn, v_10851);
    env = stack[-1];
    if (v_10851 == nil) goto v_10840;
    else goto v_10841;
v_10840:
    v_10851 = nil;
    goto v_10839;
v_10841:
    v_10851 = stack[0];
    v_10851 = qcdr(v_10851);
    stack[0] = v_10851;
    goto v_10827;
    v_10851 = nil;
v_10839:
    goto v_10831;
    v_10851 = nil;
v_10831:
    return onevalue(v_10851);
}



// Code for contr

static LispObject CC_contr(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_10862, v_10863;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10828,v_10829);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10829;
    stack[-1] = v_10828;
// end of prologue
    stack[-2] = nil;
v_10834:
    v_10862 = stack[0];
    if (v_10862 == nil) goto v_10837;
    else goto v_10838;
v_10837:
    v_10862 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_10862);
    }
v_10838:
    goto v_10849;
v_10845:
    goto v_10855;
v_10851:
    v_10863 = stack[-1];
    goto v_10852;
v_10853:
    v_10862 = stack[0];
    v_10862 = qcar(v_10862);
    goto v_10854;
v_10855:
    goto v_10851;
v_10852:
    goto v_10853;
v_10854:
    fn = elt(env, 2); // split!-road
    v_10863 = (*qfn2(fn))(fn, v_10863, v_10862);
    env = stack[-3];
    goto v_10846;
v_10847:
    v_10862 = stack[-2];
    goto v_10848;
v_10849:
    goto v_10845;
v_10846:
    goto v_10847;
v_10848:
    v_10862 = cons(v_10863, v_10862);
    env = stack[-3];
    stack[-2] = v_10862;
    v_10862 = stack[0];
    v_10862 = qcdr(v_10862);
    stack[0] = v_10862;
    goto v_10834;
    v_10862 = nil;
    return onevalue(v_10862);
}



// Code for addgt

static LispObject CC_addgt(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10860, v_10861;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10828);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10828;
// end of prologue
    goto v_10838;
v_10834:
    v_10861 = qvalue(elt(env, 1)); // ordering
    goto v_10835;
v_10836:
    v_10860 = elt(env, 2); // lex
    goto v_10837;
v_10838:
    goto v_10834;
v_10835:
    goto v_10836;
v_10837:
    if (v_10861 == v_10860) goto v_10832;
    else goto v_10833;
v_10832:
    v_10860 = stack[0];
    goto v_10831;
v_10833:
    goto v_10849;
v_10845:
    goto v_10856;
v_10852:
    v_10861 = elt(env, 3); // plus
    goto v_10853;
v_10854:
    v_10860 = stack[0];
    goto v_10855;
v_10856:
    goto v_10852;
v_10853:
    goto v_10854;
v_10855:
    v_10860 = cons(v_10861, v_10860);
    env = stack[-1];
    fn = elt(env, 4); // eval
    v_10861 = (*qfn1(fn))(fn, v_10860);
    goto v_10846;
v_10847:
    v_10860 = stack[0];
    goto v_10848;
v_10849:
    goto v_10845;
v_10846:
    goto v_10847;
v_10848:
    return cons(v_10861, v_10860);
    v_10860 = nil;
v_10831:
    return onevalue(v_10860);
}



// Code for di_restore

static LispObject CC_di_restore(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10838, v_10839;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10838 = v_10828;
// end of prologue
    goto v_10835;
v_10831:
    v_10839 = v_10838;
    goto v_10832;
v_10833:
    v_10838 = nil;
    goto v_10834;
v_10835:
    goto v_10831;
v_10832:
    goto v_10833;
v_10834:
    {
        fn = elt(env, 1); // di_restore1
        return (*qfn2(fn))(fn, v_10839, v_10838);
    }
}



// Code for expt!-mod!-p

static LispObject CC_exptKmodKp(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_10906, v_10907, v_10908;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10828,v_10829);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_10908 = v_10829;
    stack[0] = v_10828;
// end of prologue
    goto v_10839;
v_10835:
    v_10907 = v_10908;
    goto v_10836;
v_10837:
    v_10906 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10838;
v_10839:
    goto v_10835;
v_10836:
    goto v_10837;
v_10838:
    if (v_10907 == v_10906) goto v_10833;
    else goto v_10834;
v_10833:
    v_10906 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10832;
v_10834:
    goto v_10849;
v_10845:
    v_10907 = v_10908;
    goto v_10846;
v_10847:
    v_10906 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10848;
v_10849:
    goto v_10845;
v_10846:
    goto v_10847;
v_10848:
    if (v_10907 == v_10906) goto v_10843;
    else goto v_10844;
v_10843:
    v_10906 = stack[0];
    goto v_10832;
v_10844:
    goto v_10865;
v_10861:
    v_10907 = v_10908;
    goto v_10862;
v_10863:
    v_10906 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10864;
v_10865:
    goto v_10861;
v_10862:
    goto v_10863;
v_10864:
    v_10906 = Ldivide(nil, v_10907, v_10906);
    env = stack[-2];
    stack[-1] = v_10906;
    goto v_10873;
v_10869:
    v_10907 = stack[0];
    goto v_10870;
v_10871:
    v_10906 = stack[-1];
    v_10906 = qcar(v_10906);
    goto v_10872;
v_10873:
    goto v_10869;
v_10870:
    goto v_10871;
v_10872:
    v_10906 = CC_exptKmodKp(elt(env, 0), v_10907, v_10906);
    env = stack[-2];
    v_10908 = v_10906;
    goto v_10882;
v_10878:
    v_10906 = v_10908;
    goto v_10879;
v_10880:
    v_10907 = v_10908;
    goto v_10881;
v_10882:
    goto v_10878;
v_10879:
    goto v_10880;
v_10881:
    fn = elt(env, 2); // times!-mod!-p
    v_10906 = (*qfn2(fn))(fn, v_10906, v_10907);
    env = stack[-2];
    v_10908 = v_10906;
    goto v_10893;
v_10889:
    v_10906 = stack[-1];
    v_10907 = qcdr(v_10906);
    goto v_10890;
v_10891:
    v_10906 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10892;
v_10893:
    goto v_10889;
v_10890:
    goto v_10891;
v_10892:
    if (v_10907 == v_10906) goto v_10888;
    goto v_10902;
v_10898:
    v_10907 = v_10908;
    goto v_10899;
v_10900:
    v_10906 = stack[0];
    goto v_10901;
v_10902:
    goto v_10898;
v_10899:
    goto v_10900;
v_10901:
    fn = elt(env, 2); // times!-mod!-p
    v_10906 = (*qfn2(fn))(fn, v_10907, v_10906);
    v_10908 = v_10906;
    goto v_10886;
v_10888:
v_10886:
    v_10906 = v_10908;
    goto v_10832;
    v_10906 = nil;
v_10832:
    return onevalue(v_10906);
}



// Code for lex_start_line_comment

static LispObject CC_lex_start_line_comment(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10930, v_10931;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10828);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10828;
// end of prologue
    goto v_10842;
v_10838:
    v_10931 = stack[0];
    goto v_10839;
v_10840:
    v_10930 = elt(env, 1); // !%
    goto v_10841;
v_10842:
    goto v_10838;
v_10839:
    goto v_10840;
v_10841:
    if (v_10931 == v_10930) goto v_10836;
    else goto v_10837;
v_10836:
    goto v_10851;
v_10847:
    v_10931 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_10848;
v_10849:
    v_10930 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10850;
v_10851:
    goto v_10847;
v_10848:
    goto v_10849;
v_10850:
    fn = elt(env, 5); // land
    v_10930 = (*qfn2(fn))(fn, v_10931, v_10930);
    env = stack[-1];
    v_10930 = (LispObject)zerop(v_10930);
    v_10930 = v_10930 ? lisp_true : nil;
    env = stack[-1];
    v_10930 = (v_10930 == nil ? lisp_true : nil);
    goto v_10835;
v_10837:
    v_10930 = nil;
    goto v_10835;
    v_10930 = nil;
v_10835:
    if (v_10930 == nil) goto v_10833;
    v_10930 = lisp_true;
    goto v_10831;
v_10833:
    goto v_10873;
v_10869:
    v_10931 = stack[0];
    goto v_10870;
v_10871:
    v_10930 = elt(env, 3); // !#
    goto v_10872;
v_10873:
    goto v_10869;
v_10870:
    goto v_10871;
v_10872:
    if (v_10931 == v_10930) goto v_10867;
    else goto v_10868;
v_10867:
    goto v_10882;
v_10878:
    v_10931 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_10879;
v_10880:
    v_10930 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10881;
v_10882:
    goto v_10878;
v_10879:
    goto v_10880;
v_10881:
    fn = elt(env, 5); // land
    v_10930 = (*qfn2(fn))(fn, v_10931, v_10930);
    env = stack[-1];
    v_10930 = (LispObject)zerop(v_10930);
    v_10930 = v_10930 ? lisp_true : nil;
    env = stack[-1];
    v_10930 = (v_10930 == nil ? lisp_true : nil);
    goto v_10866;
v_10868:
    v_10930 = nil;
    goto v_10866;
    v_10930 = nil;
v_10866:
    if (v_10930 == nil) goto v_10864;
    v_10930 = lisp_true;
    goto v_10862;
v_10864:
    goto v_10900;
v_10896:
    v_10931 = stack[0];
    goto v_10897;
v_10898:
    v_10930 = elt(env, 4); // !/
    goto v_10899;
v_10900:
    goto v_10896;
v_10897:
    goto v_10898;
v_10899:
    if (v_10931 == v_10930) goto v_10894;
    else goto v_10895;
v_10894:
    goto v_10913;
v_10909:
    v_10931 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_10910;
v_10911:
    v_10930 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_10912;
v_10913:
    goto v_10909;
v_10910:
    goto v_10911;
v_10912:
    fn = elt(env, 5); // land
    v_10930 = (*qfn2(fn))(fn, v_10931, v_10930);
    env = stack[-1];
    v_10930 = (LispObject)zerop(v_10930);
    v_10930 = v_10930 ? lisp_true : nil;
    env = stack[-1];
    if (v_10930 == nil) goto v_10905;
    else goto v_10906;
v_10905:
    goto v_10920;
v_10916:
    fn = elt(env, 6); // yypeek
    v_10930 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_10917;
v_10918:
    v_10931 = elt(env, 4); // !/
    goto v_10919;
v_10920:
    goto v_10916;
v_10917:
    goto v_10918;
v_10919:
    v_10930 = (v_10930 == v_10931 ? lisp_true : nil);
    goto v_10904;
v_10906:
    v_10930 = nil;
    goto v_10904;
    v_10930 = nil;
v_10904:
    goto v_10893;
v_10895:
    v_10930 = nil;
    goto v_10893;
    v_10930 = nil;
v_10893:
    goto v_10862;
    v_10930 = nil;
v_10862:
    goto v_10831;
    v_10930 = nil;
v_10831:
    return onevalue(v_10930);
}



// Code for read_namelist

static LispObject CC_read_namelist(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10863, v_10864;
    LispObject fn;
    argcheck(nargs, 0, "read_namelist");
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
    v_10863 = qvalue(elt(env, 2)); // cursym!*
    fn = elt(env, 4); // valid_as_variable
    v_10863 = (*qfn1(fn))(fn, v_10863);
    env = stack[-1];
    if (v_10863 == nil) goto v_10835;
    else goto v_10836;
v_10835:
    v_10863 = nil;
    goto v_10831;
v_10836:
    fn = elt(env, 5); // read_typed_name
    v_10863 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_10863;
    goto v_10849;
v_10845:
    v_10864 = qvalue(elt(env, 2)); // cursym!*
    goto v_10846;
v_10847:
    v_10863 = elt(env, 3); // !*comma!*
    goto v_10848;
v_10849:
    goto v_10845;
v_10846:
    goto v_10847;
v_10848:
    if (v_10864 == v_10863) goto v_10844;
    v_10863 = stack[0];
    return ncons(v_10863);
v_10844:
    fn = elt(env, 6); // scan
    v_10863 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_10860;
v_10856:
    goto v_10857;
v_10858:
    v_10863 = CC_read_namelist(elt(env, 0), 0);
    goto v_10859;
v_10860:
    goto v_10856;
v_10857:
    goto v_10858;
v_10859:
    {
        LispObject v_10866 = stack[0];
        return cons(v_10866, v_10863);
    }
v_10831:
    return onevalue(v_10863);
}



// Code for monomdivide

static LispObject CC_monomdivide(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_10950, v_10951, v_10952;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10828,v_10829);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_10829;
    stack[-4] = v_10828;
// end of prologue
    stack[-2] = nil;
    v_10950 = (LispObject)16+TAG_FIXNUM; // 1
    v_10950 = Lmkvect(nil, v_10950);
    env = stack[-6];
    stack[-5] = v_10950;
    goto v_10846;
v_10840:
    stack[-1] = stack[-5];
    goto v_10841;
v_10842:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10843;
v_10844:
    goto v_10854;
v_10850:
    goto v_10859;
v_10855:
    v_10951 = stack[-4];
    goto v_10856;
v_10857:
    v_10950 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10858;
v_10859:
    goto v_10855;
v_10856:
    goto v_10857;
v_10858:
    v_10952 = *(LispObject *)((char *)v_10951 + (CELL-TAG_VECTOR) + (((intptr_t)v_10950-TAG_FIXNUM)/(16/CELL)));
    goto v_10851;
v_10852:
    goto v_10867;
v_10863:
    v_10951 = stack[-3];
    goto v_10864;
v_10865:
    v_10950 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10866;
v_10867:
    goto v_10863;
v_10864:
    goto v_10865;
v_10866:
    v_10950 = *(LispObject *)((char *)v_10951 + (CELL-TAG_VECTOR) + (((intptr_t)v_10950-TAG_FIXNUM)/(16/CELL)));
    goto v_10853;
v_10854:
    goto v_10850;
v_10851:
    goto v_10852;
v_10853:
    v_10950 = difference2(v_10952, v_10950);
    env = stack[-6];
    goto v_10845;
v_10846:
    goto v_10840;
v_10841:
    goto v_10842;
v_10843:
    goto v_10844;
v_10845:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_10950;
    goto v_10875;
v_10871:
    v_10951 = stack[-4];
    goto v_10872;
v_10873:
    v_10950 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10874;
v_10875:
    goto v_10871;
v_10872:
    goto v_10873;
v_10874:
    v_10950 = *(LispObject *)((char *)v_10951 + (CELL-TAG_VECTOR) + (((intptr_t)v_10950-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_10950;
    goto v_10883;
v_10879:
    v_10951 = stack[-3];
    goto v_10880;
v_10881:
    v_10950 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10882;
v_10883:
    goto v_10879;
v_10880:
    goto v_10881;
v_10882:
    v_10950 = *(LispObject *)((char *)v_10951 + (CELL-TAG_VECTOR) + (((intptr_t)v_10950-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_10950;
v_10889:
    v_10950 = stack[0];
    v_10950 = qcar(v_10950);
    if (v_10950 == nil) goto v_10892;
    else goto v_10893;
v_10892:
    goto v_10888;
v_10893:
    goto v_10905;
v_10901:
    v_10950 = stack[0];
    v_10951 = qcar(v_10950);
    goto v_10902;
v_10903:
    v_10950 = stack[-1];
    v_10950 = qcar(v_10950);
    goto v_10904;
v_10905:
    goto v_10901;
v_10902:
    goto v_10903;
v_10904:
    if (equal(v_10951, v_10950)) goto v_10899;
    else goto v_10900;
v_10899:
    v_10950 = stack[0];
    v_10950 = qcdr(v_10950);
    stack[0] = v_10950;
    v_10950 = stack[-1];
    v_10950 = qcdr(v_10950);
    stack[-1] = v_10950;
    goto v_10898;
v_10900:
    goto v_10922;
v_10918:
    v_10950 = stack[0];
    v_10951 = qcar(v_10950);
    goto v_10919;
v_10920:
    v_10950 = stack[-2];
    goto v_10921;
v_10922:
    goto v_10918;
v_10919:
    goto v_10920;
v_10921:
    v_10950 = cons(v_10951, v_10950);
    env = stack[-6];
    stack[-2] = v_10950;
    v_10950 = stack[0];
    v_10950 = qcdr(v_10950);
    stack[0] = v_10950;
    goto v_10898;
v_10898:
    goto v_10889;
v_10888:
    goto v_10935;
v_10931:
    v_10951 = nil;
    goto v_10932;
v_10933:
    v_10950 = stack[-2];
    goto v_10934;
v_10935:
    goto v_10931;
v_10932:
    goto v_10933;
v_10934:
    v_10950 = cons(v_10951, v_10950);
    env = stack[-6];
    stack[-2] = v_10950;
    goto v_10944;
v_10938:
    stack[-1] = stack[-5];
    goto v_10939;
v_10940:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10941;
v_10942:
    v_10950 = stack[-2];
    v_10950 = Lreverse(nil, v_10950);
    goto v_10943;
v_10944:
    goto v_10938;
v_10939:
    goto v_10940;
v_10941:
    goto v_10942;
v_10943:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_10950;
    v_10950 = stack[-5];
    return onevalue(v_10950);
}



// Code for ofsf_smmkatl1

static LispObject CC_ofsf_smmkatl1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10868, v_10869, v_10870, v_10871, v_10872;
    LispObject fn;
    LispObject v_10831, v_10830, v_10829, v_10828;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ofsf_smmkatl1");
    va_start(aa, nargs);
    v_10828 = va_arg(aa, LispObject);
    v_10829 = va_arg(aa, LispObject);
    v_10830 = va_arg(aa, LispObject);
    v_10831 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10870 = v_10831;
    v_10871 = v_10830;
    v_10872 = v_10829;
    v_10868 = v_10828;
// end of prologue
    goto v_10841;
v_10837:
    v_10869 = v_10868;
    goto v_10838;
v_10839:
    v_10868 = elt(env, 1); // and
    goto v_10840;
v_10841:
    goto v_10837;
v_10838:
    goto v_10839;
v_10840:
    if (v_10869 == v_10868) goto v_10835;
    else goto v_10836;
v_10835:
    goto v_10851;
v_10845:
    v_10868 = v_10872;
    goto v_10846;
v_10847:
    v_10869 = v_10871;
    goto v_10848;
v_10849:
    goto v_10850;
v_10851:
    goto v_10845;
v_10846:
    goto v_10847;
v_10848:
    goto v_10849;
v_10850:
    {
        fn = elt(env, 2); // ofsf_smmkatl!-and
        return (*qfnn(fn))(fn, 3, v_10868, v_10869, v_10870);
    }
v_10836:
    goto v_10864;
v_10858:
    v_10868 = v_10872;
    goto v_10859;
v_10860:
    v_10869 = v_10871;
    goto v_10861;
v_10862:
    goto v_10863;
v_10864:
    goto v_10858;
v_10859:
    goto v_10860;
v_10861:
    goto v_10862;
v_10863:
    {
        fn = elt(env, 3); // ofsf_smmkatl!-or
        return (*qfnn(fn))(fn, 3, v_10868, v_10869, v_10870);
    }
    v_10868 = nil;
    return onevalue(v_10868);
}



// Code for subsublis

static LispObject CC_subsublis(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_11056, v_11057, v_11058;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10828,v_10829);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_10829;
    stack[-3] = v_10828;
// end of prologue
v_10827:
    goto v_10843;
v_10839:
    v_11057 = stack[0];
    goto v_10840;
v_10841:
    v_11056 = stack[-3];
    goto v_10842;
v_10843:
    goto v_10839;
v_10840:
    goto v_10841;
v_10842:
    v_11056 = Lassoc(nil, v_11057, v_11056);
    v_11058 = v_11056;
    if (v_11056 == nil) goto v_10838;
    v_11056 = v_11058;
    v_11056 = qcdr(v_11056);
    goto v_10836;
v_10838:
    goto v_10860;
v_10856:
    v_11057 = stack[0];
    goto v_10857;
v_10858:
    v_11056 = elt(env, 2); // sqrt
    goto v_10859;
v_10860:
    goto v_10856;
v_10857:
    goto v_10858;
v_10859:
    if (!consp(v_11057)) goto v_10854;
    v_11057 = qcar(v_11057);
    if (v_11057 == v_11056) goto v_10853;
    else goto v_10854;
v_10853:
    goto v_10867;
v_10863:
    goto v_10875;
v_10869:
    v_11058 = elt(env, 3); // expt
    goto v_10870;
v_10871:
    v_11056 = stack[0];
    v_11056 = qcdr(v_11056);
    v_11057 = qcar(v_11056);
    goto v_10872;
v_10873:
    v_11056 = elt(env, 4); // (quotient 1 2)
    goto v_10874;
v_10875:
    goto v_10869;
v_10870:
    goto v_10871;
v_10872:
    goto v_10873;
v_10874:
    v_11057 = list3(v_11058, v_11057, v_11056);
    env = stack[-5];
    goto v_10864;
v_10865:
    v_11056 = stack[-3];
    goto v_10866;
v_10867:
    goto v_10863;
v_10864:
    goto v_10865;
v_10866:
    v_11056 = Lassoc(nil, v_11057, v_11056);
    v_11058 = v_11056;
    goto v_10852;
v_10854:
    v_11056 = nil;
    goto v_10852;
    v_11056 = nil;
v_10852:
    if (v_11056 == nil) goto v_10850;
    v_11056 = v_11058;
    v_11056 = qcdr(v_11056);
    goto v_10836;
v_10850:
    v_11056 = stack[0];
    if (!consp(v_11056)) goto v_10888;
    else goto v_10889;
v_10888:
    v_11056 = stack[0];
    goto v_10836;
v_10889:
    v_11056 = stack[0];
    v_11056 = qcar(v_11056);
    if (symbolp(v_11056)) goto v_10893;
    v_11056 = stack[0];
    stack[-4] = v_11056;
    v_11056 = stack[-4];
    if (v_11056 == nil) goto v_10905;
    else goto v_10906;
v_10905:
    v_11056 = nil;
    goto v_10900;
v_10906:
    v_11056 = stack[-4];
    v_11056 = qcar(v_11056);
    goto v_10918;
v_10914:
    v_11057 = stack[-3];
    goto v_10915;
v_10916:
    goto v_10917;
v_10918:
    goto v_10914;
v_10915:
    goto v_10916;
v_10917:
    v_11056 = CC_subsublis(elt(env, 0), v_11057, v_11056);
    env = stack[-5];
    v_11056 = ncons(v_11056);
    env = stack[-5];
    stack[-1] = v_11056;
    stack[-2] = v_11056;
v_10901:
    v_11056 = stack[-4];
    v_11056 = qcdr(v_11056);
    stack[-4] = v_11056;
    v_11056 = stack[-4];
    if (v_11056 == nil) goto v_10925;
    else goto v_10926;
v_10925:
    v_11056 = stack[-2];
    goto v_10900;
v_10926:
    goto v_10934;
v_10930:
    stack[0] = stack[-1];
    goto v_10931;
v_10932:
    v_11056 = stack[-4];
    v_11056 = qcar(v_11056);
    goto v_10945;
v_10941:
    v_11057 = stack[-3];
    goto v_10942;
v_10943:
    goto v_10944;
v_10945:
    goto v_10941;
v_10942:
    goto v_10943;
v_10944:
    v_11056 = CC_subsublis(elt(env, 0), v_11057, v_11056);
    env = stack[-5];
    v_11056 = ncons(v_11056);
    env = stack[-5];
    goto v_10933;
v_10934:
    goto v_10930;
v_10931:
    goto v_10932;
v_10933:
    v_11056 = Lrplacd(nil, stack[0], v_11056);
    env = stack[-5];
    v_11056 = stack[-1];
    v_11056 = qcdr(v_11056);
    stack[-1] = v_11056;
    goto v_10901;
v_10900:
    goto v_10836;
v_10893:
    goto v_10957;
v_10953:
    v_11056 = stack[0];
    v_11057 = qcar(v_11056);
    goto v_10954;
v_10955:
    v_11056 = elt(env, 5); // subfunc
    goto v_10956;
v_10957:
    goto v_10953;
v_10954:
    goto v_10955;
v_10956:
    v_11056 = get(v_11057, v_11056);
    env = stack[-5];
    v_11058 = v_11056;
    if (v_11056 == nil) goto v_10951;
    goto v_10968;
v_10962:
    goto v_10963;
v_10964:
    v_11057 = stack[-3];
    goto v_10965;
v_10966:
    v_11056 = stack[0];
    goto v_10967;
v_10968:
    goto v_10962;
v_10963:
    goto v_10964;
v_10965:
    goto v_10966;
v_10967:
        return Lapply2(nil, 3, v_11058, v_11057, v_11056);
v_10951:
    v_11056 = stack[0];
    v_11056 = qcar(v_11056);
    if (!symbolp(v_11056)) v_11056 = nil;
    else { v_11056 = qfastgets(v_11056);
           if (v_11056 != nil) { v_11056 = elt(v_11056, 8); // dname
#ifdef RECORD_GET
             if (v_11056 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_11056 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_11056 == SPID_NOPROP) v_11056 = nil; }}
#endif
    if (v_11056 == nil) goto v_10973;
    v_11056 = stack[0];
    goto v_10836;
v_10973:
    goto v_10984;
v_10980:
    v_11056 = stack[0];
    v_11057 = qcar(v_11056);
    goto v_10981;
v_10982:
    v_11056 = elt(env, 6); // !*sq
    goto v_10983;
v_10984:
    goto v_10980;
v_10981:
    goto v_10982;
v_10983:
    if (v_11057 == v_11056) goto v_10978;
    else goto v_10979;
v_10978:
    goto v_10993;
v_10989:
    stack[-1] = stack[-3];
    goto v_10990;
v_10991:
    v_11056 = stack[0];
    v_11056 = qcdr(v_11056);
    v_11056 = qcar(v_11056);
    fn = elt(env, 7); // prepsq
    v_11056 = (*qfn1(fn))(fn, v_11056);
    env = stack[-5];
    goto v_10992;
v_10993:
    goto v_10989;
v_10990:
    goto v_10991;
v_10992:
    stack[-3] = stack[-1];
    stack[0] = v_11056;
    goto v_10827;
v_10979:
    v_11056 = stack[0];
    stack[-4] = v_11056;
    v_11056 = stack[-4];
    if (v_11056 == nil) goto v_11010;
    else goto v_11011;
v_11010:
    v_11056 = nil;
    goto v_11005;
v_11011:
    v_11056 = stack[-4];
    v_11056 = qcar(v_11056);
    goto v_11023;
v_11019:
    v_11057 = stack[-3];
    goto v_11020;
v_11021:
    goto v_11022;
v_11023:
    goto v_11019;
v_11020:
    goto v_11021;
v_11022:
    v_11056 = CC_subsublis(elt(env, 0), v_11057, v_11056);
    env = stack[-5];
    v_11056 = ncons(v_11056);
    env = stack[-5];
    stack[-1] = v_11056;
    stack[-2] = v_11056;
v_11006:
    v_11056 = stack[-4];
    v_11056 = qcdr(v_11056);
    stack[-4] = v_11056;
    v_11056 = stack[-4];
    if (v_11056 == nil) goto v_11030;
    else goto v_11031;
v_11030:
    v_11056 = stack[-2];
    goto v_11005;
v_11031:
    goto v_11039;
v_11035:
    stack[0] = stack[-1];
    goto v_11036;
v_11037:
    v_11056 = stack[-4];
    v_11056 = qcar(v_11056);
    goto v_11050;
v_11046:
    v_11057 = stack[-3];
    goto v_11047;
v_11048:
    goto v_11049;
v_11050:
    goto v_11046;
v_11047:
    goto v_11048;
v_11049:
    v_11056 = CC_subsublis(elt(env, 0), v_11057, v_11056);
    env = stack[-5];
    v_11056 = ncons(v_11056);
    env = stack[-5];
    goto v_11038;
v_11039:
    goto v_11035;
v_11036:
    goto v_11037;
v_11038:
    v_11056 = Lrplacd(nil, stack[0], v_11056);
    env = stack[-5];
    v_11056 = stack[-1];
    v_11056 = qcdr(v_11056);
    stack[-1] = v_11056;
    goto v_11006;
v_11005:
    goto v_10836;
    v_11056 = nil;
v_10836:
    v_11058 = v_11056;
    v_11056 = v_11058;
    return onevalue(v_11056);
}



// Code for talp_rnf1

static LispObject CC_talp_rnf1(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10966, v_10967, v_10968;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10828);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_10967 = v_10828;
// end of prologue
    v_10966 = v_10967;
    if (!consp(v_10966)) goto v_10836;
    else goto v_10837;
v_10836:
    v_10966 = v_10967;
    goto v_10832;
v_10837:
    goto v_10847;
v_10841:
    v_10968 = v_10967;
    goto v_10842;
v_10843:
    v_10967 = nil;
    goto v_10844;
v_10845:
    v_10966 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_10846;
v_10847:
    goto v_10841;
v_10842:
    goto v_10843;
v_10844:
    goto v_10845;
v_10846:
    fn = elt(env, 4); // cl_simpl
    v_10966 = (*qfnn(fn))(fn, 3, v_10968, v_10967, v_10966);
    env = stack[-5];
    stack[0] = v_10966;
    goto v_10863;
v_10859:
    v_10967 = stack[0];
    goto v_10860;
v_10861:
    v_10966 = elt(env, 2); // true
    goto v_10862;
v_10863:
    goto v_10859;
v_10860:
    goto v_10861;
v_10862:
    if (v_10967 == v_10966) goto v_10857;
    else goto v_10858;
v_10857:
    v_10966 = lisp_true;
    goto v_10856;
v_10858:
    goto v_10873;
v_10869:
    v_10967 = stack[0];
    goto v_10870;
v_10871:
    v_10966 = elt(env, 3); // false
    goto v_10872;
v_10873:
    goto v_10869;
v_10870:
    goto v_10871;
v_10872:
    v_10966 = (v_10967 == v_10966 ? lisp_true : nil);
    goto v_10856;
    v_10966 = nil;
v_10856:
    if (v_10966 == nil) goto v_10854;
    v_10966 = stack[0];
    goto v_10832;
v_10854:
    v_10966 = stack[0];
    fn = elt(env, 5); // talp_atfp
    v_10966 = (*qfn1(fn))(fn, v_10966);
    env = stack[-5];
    if (v_10966 == nil) goto v_10881;
    v_10966 = stack[0];
    fn = elt(env, 6); // talp_acfrp
    v_10966 = (*qfn1(fn))(fn, v_10966);
    env = stack[-5];
    if (v_10966 == nil) goto v_10887;
    goto v_10897;
v_10891:
    v_10966 = stack[0];
    fn = elt(env, 7); // talp_raf
    v_10968 = (*qfn1(fn))(fn, v_10966);
    env = stack[-5];
    goto v_10892;
v_10893:
    v_10967 = nil;
    goto v_10894;
v_10895:
    v_10966 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_10896;
v_10897:
    goto v_10891;
v_10892:
    goto v_10893;
v_10894:
    goto v_10895;
v_10896:
    {
        fn = elt(env, 4); // cl_simpl
        return (*qfnn(fn))(fn, 3, v_10968, v_10967, v_10966);
    }
v_10887:
    v_10966 = stack[0];
    goto v_10885;
    v_10966 = nil;
v_10885:
    goto v_10832;
v_10881:
    goto v_10912;
v_10906:
    goto v_10918;
v_10914:
    v_10966 = stack[0];
    fn = elt(env, 8); // talp_op
    stack[-4] = (*qfn1(fn))(fn, v_10966);
    env = stack[-5];
    goto v_10915;
v_10916:
    v_10966 = stack[0];
    fn = elt(env, 9); // talp_argl
    v_10966 = (*qfn1(fn))(fn, v_10966);
    env = stack[-5];
    stack[-3] = v_10966;
    v_10966 = stack[-3];
    if (v_10966 == nil) goto v_10931;
    else goto v_10932;
v_10931:
    v_10966 = nil;
    goto v_10925;
v_10932:
    v_10966 = stack[-3];
    v_10966 = qcar(v_10966);
    v_10966 = CC_talp_rnf1(elt(env, 0), v_10966);
    env = stack[-5];
    v_10966 = ncons(v_10966);
    env = stack[-5];
    stack[-1] = v_10966;
    stack[-2] = v_10966;
v_10926:
    v_10966 = stack[-3];
    v_10966 = qcdr(v_10966);
    stack[-3] = v_10966;
    v_10966 = stack[-3];
    if (v_10966 == nil) goto v_10945;
    else goto v_10946;
v_10945:
    v_10966 = stack[-2];
    goto v_10925;
v_10946:
    goto v_10954;
v_10950:
    stack[0] = stack[-1];
    goto v_10951;
v_10952:
    v_10966 = stack[-3];
    v_10966 = qcar(v_10966);
    v_10966 = CC_talp_rnf1(elt(env, 0), v_10966);
    env = stack[-5];
    v_10966 = ncons(v_10966);
    env = stack[-5];
    goto v_10953;
v_10954:
    goto v_10950;
v_10951:
    goto v_10952;
v_10953:
    v_10966 = Lrplacd(nil, stack[0], v_10966);
    env = stack[-5];
    v_10966 = stack[-1];
    v_10966 = qcdr(v_10966);
    stack[-1] = v_10966;
    goto v_10926;
v_10925:
    goto v_10917;
v_10918:
    goto v_10914;
v_10915:
    goto v_10916;
v_10917:
    v_10968 = cons(stack[-4], v_10966);
    env = stack[-5];
    goto v_10907;
v_10908:
    v_10967 = nil;
    goto v_10909;
v_10910:
    v_10966 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_10911;
v_10912:
    goto v_10906;
v_10907:
    goto v_10908;
v_10909:
    goto v_10910;
v_10911:
    {
        fn = elt(env, 4); // cl_simpl
        return (*qfnn(fn))(fn, 3, v_10968, v_10967, v_10966);
    }
v_10832:
    return onevalue(v_10966);
}



// Code for ibalp_process!-var

static LispObject CC_ibalp_processKvar(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11122, v_11123, v_11124;
    LispObject fn;
    LispObject v_10831, v_10830, v_10829, v_10828;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ibalp_process-var");
    va_start(aa, nargs);
    v_10828 = va_arg(aa, LispObject);
    v_10829 = va_arg(aa, LispObject);
    v_10830 = va_arg(aa, LispObject);
    v_10831 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_10831,v_10830,v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_10828,v_10829,v_10830,v_10831);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(17);
// copy arguments values to proper place
    stack[-11] = v_10831;
    stack[-12] = v_10830;
    stack[-13] = v_10829;
    stack[-14] = v_10828;
// end of prologue
    goto v_10845;
v_10841:
    stack[0] = elt(env, 2); // !!
    goto v_10842;
v_10843:
    v_11122 = stack[-12];
    v_11122 = Lexplode(nil, v_11122);
    env = stack[-16];
    goto v_10844;
v_10845:
    goto v_10841;
v_10842:
    goto v_10843;
v_10844:
    v_11122 = cons(stack[0], v_11122);
    env = stack[-16];
    v_11122 = Lcompress(nil, v_11122);
    env = stack[-16];
    v_11122 = Lintern(nil, v_11122);
    env = stack[-16];
    stack[-12] = v_11122;
    goto v_10857;
v_10853:
    v_11123 = stack[-12];
    goto v_10854;
v_10855:
    v_11122 = stack[-13];
    goto v_10856;
v_10857:
    goto v_10853;
v_10854:
    goto v_10855;
v_10856:
    v_11122 = Latsoc(nil, v_11123, v_11122);
    v_11123 = v_11122;
    if (v_11122 == nil) goto v_10852;
    v_11122 = v_11123;
    v_11122 = qcdr(v_11122);
    stack[0] = v_11122;
    goto v_10850;
v_10852:
    goto v_10874;
v_10866:
    stack[-15] = stack[-12];
    goto v_10867;
v_10868:
    stack[-10] = nil;
    goto v_10869;
v_10870:
    stack[-9] = nil;
    goto v_10871;
v_10872:
    goto v_10887;
v_10879:
    stack[-8] = nil;
    goto v_10880;
v_10881:
    stack[-7] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10882;
v_10883:
    stack[-6] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10884;
v_10885:
    goto v_10900;
v_10892:
    stack[-5] = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_10893;
v_10894:
    stack[-4] = nil;
    goto v_10895;
v_10896:
    stack[-3] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10897;
v_10898:
    goto v_10913;
v_10905:
    stack[-2] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10906;
v_10907:
    stack[-1] = nil;
    goto v_10908;
v_10909:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10910;
v_10911:
    goto v_10924;
v_10918:
    v_11124 = nil;
    goto v_10919;
v_10920:
    v_11123 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10921;
v_10922:
    v_11122 = nil;
    goto v_10923;
v_10924:
    goto v_10918;
v_10919:
    goto v_10920;
v_10921:
    goto v_10922;
v_10923:
    v_11122 = list3(v_11124, v_11123, v_11122);
    env = stack[-16];
    goto v_10912;
v_10913:
    goto v_10905;
v_10906:
    goto v_10907;
v_10908:
    goto v_10909;
v_10910:
    goto v_10911;
v_10912:
    v_11122 = list3star(stack[-2], stack[-1], stack[0], v_11122);
    env = stack[-16];
    goto v_10899;
v_10900:
    goto v_10892;
v_10893:
    goto v_10894;
v_10895:
    goto v_10896;
v_10897:
    goto v_10898;
v_10899:
    v_11122 = list3star(stack[-5], stack[-4], stack[-3], v_11122);
    env = stack[-16];
    goto v_10886;
v_10887:
    goto v_10879;
v_10880:
    goto v_10881;
v_10882:
    goto v_10883;
v_10884:
    goto v_10885;
v_10886:
    v_11122 = list3star(stack[-8], stack[-7], stack[-6], v_11122);
    env = stack[-16];
    goto v_10873;
v_10874:
    goto v_10866;
v_10867:
    goto v_10868;
v_10869:
    goto v_10870;
v_10871:
    goto v_10872;
v_10873:
    v_11122 = list3star(stack[-15], stack[-10], stack[-9], v_11122);
    env = stack[-16];
    stack[0] = v_11122;
    goto v_10935;
v_10929:
    v_11124 = stack[-12];
    goto v_10930;
v_10931:
    v_11123 = stack[0];
    goto v_10932;
v_10933:
    v_11122 = stack[-13];
    goto v_10934;
v_10935:
    goto v_10929;
v_10930:
    goto v_10931;
v_10932:
    goto v_10933;
v_10934:
    v_11122 = acons(v_11124, v_11123, v_11122);
    env = stack[-16];
    stack[-13] = v_11122;
    goto v_10850;
v_10850:
    goto v_10948;
v_10944:
    v_11123 = stack[-11];
    goto v_10945;
v_10946:
    v_11122 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10947;
v_10948:
    goto v_10944;
v_10945:
    goto v_10946;
v_10947:
    v_11122 = Leqn(nil, v_11123, v_11122);
    env = stack[-16];
    if (v_11122 == nil) goto v_10942;
    goto v_10956;
v_10952:
    v_11122 = stack[0];
    v_11122 = qcdr(v_11122);
    stack[-1] = qcdr(v_11122);
    goto v_10953;
v_10954:
    goto v_10965;
v_10961:
    v_11123 = stack[-14];
    goto v_10962;
v_10963:
    v_11122 = stack[0];
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcar(v_11122);
    goto v_10964;
v_10965:
    goto v_10961;
v_10962:
    goto v_10963;
v_10964:
    v_11122 = cons(v_11123, v_11122);
    env = stack[-16];
    goto v_10955;
v_10956:
    goto v_10952;
v_10953:
    goto v_10954;
v_10955:
    fn = elt(env, 3); // setcar
    v_11122 = (*qfn2(fn))(fn, stack[-1], v_11122);
    env = stack[-16];
    goto v_10976;
v_10972:
    v_11122 = stack[0];
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    stack[-1] = qcdr(v_11122);
    goto v_10973;
v_10974:
    v_11122 = stack[0];
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcar(v_11122);
    v_11122 = add1(v_11122);
    env = stack[-16];
    goto v_10975;
v_10976:
    goto v_10972;
v_10973:
    goto v_10974;
v_10975:
    fn = elt(env, 3); // setcar
    v_11122 = (*qfn2(fn))(fn, stack[-1], v_11122);
    env = stack[-16];
    goto v_10994;
v_10990:
    v_11122 = stack[0];
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    stack[-1] = qcdr(v_11122);
    goto v_10991;
v_10992:
    v_11122 = stack[0];
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcar(v_11122);
    v_11122 = add1(v_11122);
    env = stack[-16];
    goto v_10993;
v_10994:
    goto v_10990;
v_10991:
    goto v_10992;
v_10993:
    fn = elt(env, 3); // setcar
    v_11122 = (*qfn2(fn))(fn, stack[-1], v_11122);
    env = stack[-16];
    goto v_11020;
v_11016:
    stack[-1] = stack[-14];
    goto v_11017;
v_11018:
    goto v_11027;
v_11023:
    v_11123 = stack[0];
    goto v_11024;
v_11025:
    v_11122 = stack[-14];
    v_11122 = qcar(v_11122);
    goto v_11026;
v_11027:
    goto v_11023;
v_11024:
    goto v_11025;
v_11026:
    v_11122 = cons(v_11123, v_11122);
    env = stack[-16];
    goto v_11019;
v_11020:
    goto v_11016;
v_11017:
    goto v_11018;
v_11019:
    fn = elt(env, 3); // setcar
    v_11122 = (*qfn2(fn))(fn, stack[-1], v_11122);
    goto v_10940;
v_10942:
    goto v_11038;
v_11034:
    v_11122 = stack[0];
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    stack[-1] = qcdr(v_11122);
    goto v_11035;
v_11036:
    goto v_11048;
v_11044:
    v_11123 = stack[-14];
    goto v_11045;
v_11046:
    v_11122 = stack[0];
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcar(v_11122);
    goto v_11047;
v_11048:
    goto v_11044;
v_11045:
    goto v_11046;
v_11047:
    v_11122 = cons(v_11123, v_11122);
    env = stack[-16];
    goto v_11037;
v_11038:
    goto v_11034;
v_11035:
    goto v_11036;
v_11037:
    fn = elt(env, 3); // setcar
    v_11122 = (*qfn2(fn))(fn, stack[-1], v_11122);
    env = stack[-16];
    goto v_11060;
v_11056:
    v_11122 = stack[0];
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    stack[-1] = qcdr(v_11122);
    goto v_11057;
v_11058:
    v_11122 = stack[0];
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcar(v_11122);
    v_11122 = add1(v_11122);
    env = stack[-16];
    goto v_11059;
v_11060:
    goto v_11056;
v_11057:
    goto v_11058;
v_11059:
    fn = elt(env, 3); // setcar
    v_11122 = (*qfn2(fn))(fn, stack[-1], v_11122);
    env = stack[-16];
    goto v_11080;
v_11076:
    v_11122 = stack[0];
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    stack[-1] = qcdr(v_11122);
    goto v_11077;
v_11078:
    v_11122 = stack[0];
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcdr(v_11122);
    v_11122 = qcar(v_11122);
    v_11122 = add1(v_11122);
    env = stack[-16];
    goto v_11079;
v_11080:
    goto v_11076;
v_11077:
    goto v_11078;
v_11079:
    fn = elt(env, 3); // setcar
    v_11122 = (*qfn2(fn))(fn, stack[-1], v_11122);
    env = stack[-16];
    goto v_11108;
v_11104:
    v_11122 = stack[-14];
    stack[-1] = qcdr(v_11122);
    goto v_11105;
v_11106:
    goto v_11116;
v_11112:
    v_11123 = stack[0];
    goto v_11113;
v_11114:
    v_11122 = stack[-14];
    v_11122 = qcdr(v_11122);
    v_11122 = qcar(v_11122);
    goto v_11115;
v_11116:
    goto v_11112;
v_11113:
    goto v_11114;
v_11115:
    v_11122 = cons(v_11123, v_11122);
    env = stack[-16];
    goto v_11107;
v_11108:
    goto v_11104;
v_11105:
    goto v_11106;
v_11107:
    fn = elt(env, 3); // setcar
    v_11122 = (*qfn2(fn))(fn, stack[-1], v_11122);
    goto v_10940;
v_10940:
    v_11122 = stack[-13];
    return onevalue(v_11122);
}



// Code for dvfsf_susitf

static LispObject CC_dvfsf_susitf(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_10832, v_10833;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10832 = v_10829;
    v_10833 = v_10828;
// end of prologue
    v_10832 = v_10833;
    return onevalue(v_10832);
}



// Code for binomial!-coefft!-mod!-p

static LispObject CC_binomialKcoefftKmodKp(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_10948, v_10949, v_10950, v_10951, v_10952;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10828,v_10829);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_10829;
    stack[-2] = v_10828;
// end of prologue
    goto v_10840;
v_10836:
    v_10949 = stack[-2];
    goto v_10837;
v_10838:
    v_10948 = stack[-1];
    goto v_10839;
v_10840:
    goto v_10836;
v_10837:
    goto v_10838;
v_10839:
    v_10948 = (LispObject)lessp2(v_10949, v_10948);
    v_10948 = v_10948 ? lisp_true : nil;
    env = stack[-4];
    if (v_10948 == nil) goto v_10834;
    v_10948 = nil;
    goto v_10832;
v_10834:
    goto v_10850;
v_10846:
    v_10949 = stack[-2];
    goto v_10847;
v_10848:
    v_10948 = stack[-1];
    goto v_10849;
v_10850:
    goto v_10846;
v_10847:
    goto v_10848;
v_10849:
    if (equal(v_10949, v_10948)) goto v_10844;
    else goto v_10845;
v_10844:
    v_10948 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10832;
v_10845:
    goto v_10860;
v_10856:
    v_10949 = stack[-1];
    goto v_10857;
v_10858:
    v_10948 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10859;
v_10860:
    goto v_10856;
v_10857:
    goto v_10858;
v_10859:
    if (v_10949 == v_10948) goto v_10854;
    else goto v_10855;
v_10854:
    v_10948 = stack[-2];
    v_10948 = Lmodular_number(nil, v_10948);
    env = stack[-4];
    {
        fn = elt(env, 2); // !*n2f
        return (*qfn1(fn))(fn, v_10948);
    }
v_10855:
    v_10948 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_10948;
    goto v_10880;
v_10876:
    stack[0] = stack[-1];
    goto v_10877;
v_10878:
    goto v_10887;
v_10883:
    v_10949 = stack[-2];
    goto v_10884;
v_10885:
    v_10948 = stack[-1];
    goto v_10886;
v_10887:
    goto v_10883;
v_10884:
    goto v_10885;
v_10886:
    v_10948 = difference2(v_10949, v_10948);
    env = stack[-4];
    goto v_10879;
v_10880:
    goto v_10876;
v_10877:
    goto v_10878;
v_10879:
    fn = elt(env, 3); // min
    v_10948 = (*qfn2(fn))(fn, stack[0], v_10948);
    env = stack[-4];
    stack[0] = v_10948;
    v_10948 = stack[-2];
    v_10948 = Lmodular_number(nil, v_10948);
    env = stack[-4];
    stack[-2] = v_10948;
    v_10948 = stack[-1];
    v_10948 = Lmodular_number(nil, v_10948);
    env = stack[-4];
    v_10948 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_10948;
v_10897:
    goto v_10909;
v_10905:
    v_10949 = stack[0];
    goto v_10906;
v_10907:
    v_10948 = stack[-1];
    goto v_10908;
v_10909:
    goto v_10905;
v_10906:
    goto v_10907;
v_10908:
    v_10948 = difference2(v_10949, v_10948);
    env = stack[-4];
    v_10948 = Lminusp(nil, v_10948);
    env = stack[-4];
    if (v_10948 == nil) goto v_10902;
    goto v_10896;
v_10902:
    v_10948 = stack[-1];
    v_10948 = Lmodular_number(nil, v_10948);
    env = stack[-4];
    v_10952 = v_10948;
    goto v_10920;
v_10916:
    goto v_10926;
v_10922:
    v_10951 = stack[-3];
    goto v_10923;
v_10924:
    goto v_10932;
v_10928:
    v_10950 = stack[-2];
    goto v_10929;
v_10930:
    goto v_10938;
v_10934:
    v_10949 = v_10952;
    goto v_10935;
v_10936:
    v_10948 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10937;
v_10938:
    goto v_10934;
v_10935:
    goto v_10936;
v_10937:
    {   intptr_t w = int_of_fixnum(v_10949) - int_of_fixnum(v_10948);
        if (w < 0) w += current_modulus;
        v_10948 = fixnum_of_int(w);
    }
    goto v_10931;
v_10932:
    goto v_10928;
v_10929:
    goto v_10930;
v_10931:
    {   intptr_t w = int_of_fixnum(v_10950) - int_of_fixnum(v_10948);
        if (w < 0) w += current_modulus;
        v_10948 = fixnum_of_int(w);
    }
    goto v_10925;
v_10926:
    goto v_10922;
v_10923:
    goto v_10924;
v_10925:
    v_10948 = Lmodular_times(nil, v_10951, v_10948);
    env = stack[-4];
    goto v_10917;
v_10918:
    v_10949 = v_10952;
    goto v_10919;
v_10920:
    goto v_10916;
v_10917:
    goto v_10918;
v_10919:
    v_10948 = Lmodular_quotient(nil, v_10948, v_10949);
    env = stack[-4];
    stack[-3] = v_10948;
    v_10948 = stack[-1];
    v_10948 = add1(v_10948);
    env = stack[-4];
    stack[-1] = v_10948;
    goto v_10897;
v_10896:
    v_10948 = stack[-3];
    {
        fn = elt(env, 2); // !*n2f
        return (*qfn1(fn))(fn, v_10948);
    }
    goto v_10832;
    v_10948 = nil;
v_10832:
    return onevalue(v_10948);
}



// Code for om2mml

static LispObject CC_om2mml(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10846;
    LispObject fn;
    argcheck(nargs, 0, "om2mml");
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
    fn = elt(env, 3); // om2ir
    v_10846 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_10846;
    v_10846 = lisp_true;
    fn = elt(env, 4); // terpri!*
    v_10846 = (*qfn1(fn))(fn, v_10846);
    env = stack[-1];
    v_10846 = elt(env, 2); // "Intermediate representation:"
    v_10846 = Lprinc(nil, v_10846);
    env = stack[-1];
    v_10846 = lisp_true;
    fn = elt(env, 4); // terpri!*
    v_10846 = (*qfn1(fn))(fn, v_10846);
    env = stack[-1];
    v_10846 = stack[0];
    v_10846 = Lprinc(nil, v_10846);
    env = stack[-1];
    v_10846 = lisp_true;
    fn = elt(env, 4); // terpri!*
    v_10846 = (*qfn1(fn))(fn, v_10846);
    env = stack[-1];
    v_10846 = stack[0];
    fn = elt(env, 5); // ir2mml
    v_10846 = (*qfn1(fn))(fn, v_10846);
    v_10846 = nil;
    return onevalue(v_10846);
}



// Code for ps!:minusp!:

static LispObject CC_psTminuspT(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10831;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10831 = v_10828;
// end of prologue
    v_10831 = nil;
    return onevalue(v_10831);
}



// Code for groebcplistsortin

static LispObject CC_groebcplistsortin(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_10849, v_10850;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10828,v_10829);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_10829;
    v_10850 = v_10828;
// end of prologue
    v_10849 = stack[0];
    if (v_10849 == nil) goto v_10833;
    else goto v_10834;
v_10833:
    v_10849 = v_10850;
    return ncons(v_10849);
v_10834:
    goto v_10845;
v_10841:
    goto v_10842;
v_10843:
    v_10849 = stack[0];
    goto v_10844;
v_10845:
    goto v_10841;
v_10842:
    goto v_10843;
v_10844:
    fn = elt(env, 1); // groebcplistsortin1
    v_10849 = (*qfn2(fn))(fn, v_10850, v_10849);
    v_10849 = stack[0];
    goto v_10832;
    v_10849 = nil;
v_10832:
    return onevalue(v_10849);
}



// Code for arg2of2

static LispObject CC_arg2of2(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_10832, v_10833;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10832 = v_10829;
    v_10833 = v_10828;
// end of prologue
    return onevalue(v_10832);
}



// Code for xord_deglex

static LispObject CC_xord_deglex(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_10892, v_10893, v_10894, v_10895;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10828,v_10829);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10829;
    stack[-1] = v_10828;
// end of prologue
    goto v_10839;
v_10835:
    v_10892 = stack[-1];
    v_10893 = qcar(v_10892);
    goto v_10836;
v_10837:
    v_10892 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10838;
v_10839:
    goto v_10835;
v_10836:
    goto v_10837;
v_10838:
    if (v_10893 == v_10892) goto v_10833;
    else goto v_10834;
v_10833:
    v_10892 = nil;
    goto v_10832;
v_10834:
    goto v_10850;
v_10846:
    v_10892 = stack[0];
    v_10893 = qcar(v_10892);
    goto v_10847;
v_10848:
    v_10892 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10849;
v_10850:
    goto v_10846;
v_10847:
    goto v_10848;
v_10849:
    if (v_10893 == v_10892) goto v_10844;
    else goto v_10845;
v_10844:
    v_10892 = lisp_true;
    goto v_10832;
v_10845:
    v_10892 = stack[-1];
    fn = elt(env, 1); // xdegreemon
    stack[-2] = (*qfn1(fn))(fn, v_10892);
    env = stack[-3];
    v_10892 = stack[0];
    fn = elt(env, 1); // xdegreemon
    v_10892 = (*qfn1(fn))(fn, v_10892);
    env = stack[-3];
    v_10895 = stack[-2];
    v_10894 = v_10892;
    goto v_10871;
v_10867:
    v_10893 = v_10895;
    goto v_10868;
v_10869:
    v_10892 = v_10894;
    goto v_10870;
v_10871:
    goto v_10867;
v_10868:
    goto v_10869;
v_10870:
    if (equal(v_10893, v_10892)) goto v_10865;
    else goto v_10866;
v_10865:
    goto v_10879;
v_10875:
    v_10893 = stack[-1];
    goto v_10876;
v_10877:
    v_10892 = stack[0];
    goto v_10878;
v_10879:
    goto v_10875;
v_10876:
    goto v_10877;
v_10878:
    {
        fn = elt(env, 2); // xord_lex
        return (*qfn2(fn))(fn, v_10893, v_10892);
    }
v_10866:
    goto v_10889;
v_10885:
    v_10892 = v_10895;
    goto v_10886;
v_10887:
    v_10893 = v_10894;
    goto v_10888;
v_10889:
    goto v_10885;
v_10886:
    goto v_10887;
v_10888:
        return Lgreaterp(nil, v_10892, v_10893);
    v_10892 = nil;
    goto v_10832;
    v_10892 = nil;
v_10832:
    return onevalue(v_10892);
}



// Code for delete!-dups

static LispObject CC_deleteKdups(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10872, v_10873, v_10874;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10828);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10828;
// end of prologue
    v_10874 = nil;
v_10833:
    v_10872 = stack[0];
    if (v_10872 == nil) goto v_10837;
    goto v_10847;
v_10843:
    v_10872 = stack[0];
    v_10873 = qcar(v_10872);
    goto v_10844;
v_10845:
    v_10872 = stack[0];
    v_10872 = qcdr(v_10872);
    goto v_10846;
v_10847:
    goto v_10843;
v_10844:
    goto v_10845;
v_10846:
    v_10872 = Lmember(nil, v_10873, v_10872);
    if (v_10872 == nil) goto v_10842;
    v_10872 = stack[0];
    v_10872 = qcdr(v_10872);
    stack[0] = v_10872;
    goto v_10833;
v_10842:
    goto v_10862;
v_10858:
    v_10872 = stack[0];
    v_10872 = qcar(v_10872);
    goto v_10859;
v_10860:
    v_10873 = v_10874;
    goto v_10861;
v_10862:
    goto v_10858;
v_10859:
    goto v_10860;
v_10861:
    v_10872 = cons(v_10872, v_10873);
    env = stack[-1];
    v_10874 = v_10872;
    v_10872 = stack[0];
    v_10872 = qcdr(v_10872);
    stack[0] = v_10872;
    goto v_10833;
    goto v_10835;
v_10837:
    v_10872 = v_10874;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_10872);
    }
v_10835:
    v_10872 = nil;
    return onevalue(v_10872);
}



// Code for physop!-ordop

static LispObject CC_physopKordop(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_11017, v_11018;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10828,v_10829);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_10829;
    stack[-1] = v_10828;
// end of prologue
v_10827:
    v_11017 = stack[-1];
    fn = elt(env, 4); // !*physopp
    v_11017 = (*qfn1(fn))(fn, v_11017);
    env = stack[-4];
    if (v_11017 == nil) goto v_10841;
    v_11017 = stack[0];
    fn = elt(env, 4); // !*physopp
    v_11017 = (*qfn1(fn))(fn, v_11017);
    env = stack[-4];
    if (v_11017 == nil) goto v_10841;
    goto v_10842;
v_10841:
    v_11017 = stack[-1];
    fn = elt(env, 4); // !*physopp
    v_11017 = (*qfn1(fn))(fn, v_11017);
    env = stack[-4];
    if (v_11017 == nil) goto v_10852;
    v_11017 = nil;
    goto v_10850;
v_10852:
    v_11017 = stack[0];
    fn = elt(env, 4); // !*physopp
    v_11017 = (*qfn1(fn))(fn, v_11017);
    env = stack[-4];
    if (v_11017 == nil) goto v_10857;
    v_11017 = lisp_true;
    goto v_10850;
v_10857:
    goto v_10868;
v_10864:
    v_11018 = stack[-1];
    goto v_10865;
v_10866:
    v_11017 = stack[0];
    goto v_10867;
v_10868:
    goto v_10864;
v_10865:
    goto v_10866;
v_10867:
    {
        fn = elt(env, 5); // ordop2
        return (*qfn2(fn))(fn, v_11018, v_11017);
    }
    v_11017 = nil;
v_10850:
    goto v_10837;
v_10842:
    v_11017 = stack[-1];
    if (symbolp(v_11017)) goto v_10873;
    else goto v_10874;
v_10873:
    goto v_10881;
v_10877:
    v_11018 = stack[-1];
    goto v_10878;
v_10879:
    v_11017 = elt(env, 2); // physopname
    goto v_10880;
v_10881:
    goto v_10877;
v_10878:
    goto v_10879;
v_10880:
    v_11017 = get(v_11018, v_11017);
    env = stack[-4];
    stack[-3] = v_11017;
    goto v_10872;
v_10874:
    goto v_10891;
v_10887:
    v_11017 = stack[-1];
    v_11018 = qcar(v_11017);
    goto v_10888;
v_10889:
    v_11017 = elt(env, 2); // physopname
    goto v_10890;
v_10891:
    goto v_10887;
v_10888:
    goto v_10889;
v_10890:
    v_11017 = get(v_11018, v_11017);
    env = stack[-4];
    stack[-3] = v_11017;
    goto v_10900;
v_10896:
    v_11018 = stack[-3];
    goto v_10897;
v_10898:
    v_11017 = stack[-1];
    v_11017 = qcdr(v_11017);
    goto v_10899;
v_10900:
    goto v_10896;
v_10897:
    goto v_10898;
v_10899:
    v_11017 = cons(v_11018, v_11017);
    env = stack[-4];
    stack[-3] = v_11017;
    v_11017 = stack[-1];
    v_11017 = qcar(v_11017);
    stack[-1] = v_11017;
    goto v_10872;
v_10872:
    goto v_10915;
v_10911:
    v_11018 = stack[-1];
    goto v_10912;
v_10913:
    v_11017 = qvalue(elt(env, 3)); // specoplist!*
    goto v_10914;
v_10915:
    goto v_10911;
v_10912:
    goto v_10913;
v_10914:
    v_11017 = Lmember(nil, v_11018, v_11017);
    if (v_11017 == nil) goto v_10910;
    v_11017 = lisp_true;
    goto v_10837;
v_10910:
    v_11017 = stack[0];
    if (symbolp(v_11017)) goto v_10922;
    else goto v_10923;
v_10922:
    goto v_10930;
v_10926:
    v_11018 = stack[0];
    goto v_10927;
v_10928:
    v_11017 = elt(env, 2); // physopname
    goto v_10929;
v_10930:
    goto v_10926;
v_10927:
    goto v_10928;
v_10929:
    v_11017 = get(v_11018, v_11017);
    env = stack[-4];
    stack[-2] = v_11017;
    goto v_10921;
v_10923:
    goto v_10940;
v_10936:
    v_11017 = stack[0];
    v_11018 = qcar(v_11017);
    goto v_10937;
v_10938:
    v_11017 = elt(env, 2); // physopname
    goto v_10939;
v_10940:
    goto v_10936;
v_10937:
    goto v_10938;
v_10939:
    v_11017 = get(v_11018, v_11017);
    env = stack[-4];
    stack[-2] = v_11017;
    goto v_10949;
v_10945:
    v_11018 = stack[-2];
    goto v_10946;
v_10947:
    v_11017 = stack[0];
    v_11017 = qcdr(v_11017);
    goto v_10948;
v_10949:
    goto v_10945;
v_10946:
    goto v_10947;
v_10948:
    v_11017 = cons(v_11018, v_11017);
    env = stack[-4];
    stack[-2] = v_11017;
    v_11017 = stack[0];
    v_11017 = qcar(v_11017);
    stack[0] = v_11017;
    goto v_10921;
v_10921:
    goto v_10964;
v_10960:
    v_11018 = stack[0];
    goto v_10961;
v_10962:
    v_11017 = qvalue(elt(env, 3)); // specoplist!*
    goto v_10963;
v_10964:
    goto v_10960;
v_10961:
    goto v_10962;
v_10963:
    v_11017 = Lmember(nil, v_11018, v_11017);
    if (v_11017 == nil) goto v_10959;
    v_11017 = lisp_true;
    goto v_10837;
v_10959:
    v_11017 = stack[-3];
    fn = elt(env, 6); // opnum!*
    v_11017 = (*qfn1(fn))(fn, v_11017);
    env = stack[-4];
    stack[-1] = v_11017;
    v_11017 = stack[-2];
    fn = elt(env, 6); // opnum!*
    v_11017 = (*qfn1(fn))(fn, v_11017);
    env = stack[-4];
    stack[0] = v_11017;
    goto v_10982;
v_10978:
    v_11018 = stack[-1];
    goto v_10979;
v_10980:
    v_11017 = stack[0];
    goto v_10981;
v_10982:
    goto v_10978;
v_10979:
    goto v_10980;
v_10981:
    v_11017 = (LispObject)lessp2(v_11018, v_11017);
    v_11017 = v_11017 ? lisp_true : nil;
    env = stack[-4];
    if (v_11017 == nil) goto v_10976;
    v_11017 = lisp_true;
    goto v_10974;
v_10976:
    goto v_10993;
v_10989:
    v_11018 = stack[-1];
    goto v_10990;
v_10991:
    v_11017 = stack[0];
    goto v_10992;
v_10993:
    goto v_10989;
v_10990:
    goto v_10991;
v_10992:
    v_11017 = (LispObject)greaterp2(v_11018, v_11017);
    v_11017 = v_11017 ? lisp_true : nil;
    env = stack[-4];
    if (v_11017 == nil) goto v_10987;
    v_11017 = nil;
    goto v_10974;
v_10987:
    v_11017 = stack[-3];
    if (symbolp(v_11017)) goto v_10997;
    else goto v_10998;
v_10997:
    v_11017 = lisp_true;
    goto v_10974;
v_10998:
    v_11017 = stack[-2];
    if (symbolp(v_11017)) goto v_11001;
    else goto v_11002;
v_11001:
    v_11017 = nil;
    goto v_10974;
v_11002:
    goto v_11012;
v_11008:
    v_11017 = stack[-3];
    v_11018 = qcdr(v_11017);
    goto v_11009;
v_11010:
    v_11017 = stack[-2];
    v_11017 = qcdr(v_11017);
    goto v_11011;
v_11012:
    goto v_11008;
v_11009:
    goto v_11010;
v_11011:
    stack[-1] = v_11018;
    stack[0] = v_11017;
    goto v_10827;
    v_11017 = nil;
v_10974:
v_10837:
    return onevalue(v_11017);
}



// Code for repasc

static LispObject CC_repasc(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10912, v_10913, v_10914;
    LispObject fn;
    LispObject v_10830, v_10829, v_10828;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "repasc");
    va_start(aa, nargs);
    v_10828 = va_arg(aa, LispObject);
    v_10829 = va_arg(aa, LispObject);
    v_10830 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_10830,v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_10828,v_10829,v_10830);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_10830;
    stack[-1] = v_10829;
    stack[-2] = v_10828;
// end of prologue
    v_10914 = nil;
v_10835:
    v_10912 = stack[0];
    if (v_10912 == nil) goto v_10838;
    else goto v_10839;
v_10838:
    goto v_10846;
v_10842:
    stack[-3] = v_10914;
    goto v_10843;
v_10844:
    goto v_10855;
v_10849:
    stack[-1] = elt(env, 1); // alg
    goto v_10850;
v_10851:
    stack[0] = (LispObject)112+TAG_FIXNUM; // 7
    goto v_10852;
v_10853:
    goto v_10865;
v_10859:
    v_10914 = elt(env, 2); // "key"
    goto v_10860;
v_10861:
    v_10913 = stack[-2];
    goto v_10862;
v_10863:
    v_10912 = elt(env, 3); // "not found"
    goto v_10864;
v_10865:
    goto v_10859;
v_10860:
    goto v_10861;
v_10862:
    goto v_10863;
v_10864:
    v_10912 = list3(v_10914, v_10913, v_10912);
    env = stack[-4];
    goto v_10854;
v_10855:
    goto v_10849;
v_10850:
    goto v_10851;
v_10852:
    goto v_10853;
v_10854:
    fn = elt(env, 4); // rerror
    v_10912 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_10912);
    env = stack[-4];
    goto v_10845;
v_10846:
    goto v_10842;
v_10843:
    goto v_10844;
v_10845:
    {
        LispObject v_10919 = stack[-3];
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(fn, v_10919, v_10912);
    }
v_10839:
    goto v_10875;
v_10871:
    v_10913 = stack[-2];
    goto v_10872;
v_10873:
    v_10912 = stack[0];
    v_10912 = qcar(v_10912);
    v_10912 = qcar(v_10912);
    goto v_10874;
v_10875:
    goto v_10871;
v_10872:
    goto v_10873;
v_10874:
    if (equal(v_10913, v_10912)) goto v_10869;
    else goto v_10870;
v_10869:
    goto v_10885;
v_10881:
    stack[-3] = v_10914;
    goto v_10882;
v_10883:
    goto v_10894;
v_10888:
    v_10914 = stack[-2];
    goto v_10889;
v_10890:
    v_10913 = stack[-1];
    goto v_10891;
v_10892:
    v_10912 = stack[0];
    v_10912 = qcdr(v_10912);
    goto v_10893;
v_10894:
    goto v_10888;
v_10889:
    goto v_10890;
v_10891:
    goto v_10892;
v_10893:
    v_10912 = acons(v_10914, v_10913, v_10912);
    env = stack[-4];
    goto v_10884;
v_10885:
    goto v_10881;
v_10882:
    goto v_10883;
v_10884:
    {
        LispObject v_10920 = stack[-3];
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(fn, v_10920, v_10912);
    }
v_10870:
    goto v_10906;
v_10902:
    v_10912 = stack[0];
    v_10912 = qcar(v_10912);
    goto v_10903;
v_10904:
    v_10913 = v_10914;
    goto v_10905;
v_10906:
    goto v_10902;
v_10903:
    goto v_10904;
v_10905:
    v_10912 = cons(v_10912, v_10913);
    env = stack[-4];
    v_10914 = v_10912;
    v_10912 = stack[0];
    v_10912 = qcdr(v_10912);
    stack[0] = v_10912;
    goto v_10835;
    v_10912 = nil;
    return onevalue(v_10912);
}



// Code for qremd

static LispObject CC_qremd(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_10965, v_10966;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10828,v_10829);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_10829;
    stack[-2] = v_10828;
// end of prologue
    v_10965 = stack[-2];
    if (v_10965 == nil) goto v_10833;
    else goto v_10834;
v_10833:
    goto v_10841;
v_10837:
    v_10966 = stack[-2];
    goto v_10838;
v_10839:
    v_10965 = stack[-2];
    goto v_10840;
v_10841:
    goto v_10837;
v_10838:
    goto v_10839;
v_10840:
    return cons(v_10966, v_10965);
v_10834:
    goto v_10850;
v_10846:
    v_10966 = stack[-1];
    goto v_10847;
v_10848:
    v_10965 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10849;
v_10850:
    goto v_10846;
v_10847:
    goto v_10848;
v_10849:
    if (v_10966 == v_10965) goto v_10844;
    else goto v_10845;
v_10844:
    v_10965 = stack[-2];
    return ncons(v_10965);
v_10845:
    v_10965 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_10965)) v_10965 = nil;
    else { v_10965 = qfastgets(v_10965);
           if (v_10965 != nil) { v_10965 = elt(v_10965, 3); // field
#ifdef RECORD_GET
             if (v_10965 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_10965 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_10965 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_10965 == SPID_NOPROP) v_10965 = nil; else v_10965 = lisp_true; }}
#endif
    if (v_10965 == nil) goto v_10856;
    goto v_10865;
v_10861:
    v_10965 = stack[-1];
    fn = elt(env, 3); // !:recip
    v_10966 = (*qfn1(fn))(fn, v_10965);
    env = stack[-4];
    goto v_10862;
v_10863:
    v_10965 = stack[-2];
    goto v_10864;
v_10865:
    goto v_10861;
v_10862:
    goto v_10863;
v_10864:
    fn = elt(env, 4); // multd
    v_10965 = (*qfn2(fn))(fn, v_10966, v_10965);
    return ncons(v_10965);
v_10856:
    v_10965 = stack[-2];
    if (!consp(v_10965)) goto v_10873;
    else goto v_10874;
v_10873:
    v_10965 = lisp_true;
    goto v_10872;
v_10874:
    v_10965 = stack[-2];
    v_10965 = qcar(v_10965);
    v_10965 = (consp(v_10965) ? nil : lisp_true);
    goto v_10872;
    v_10965 = nil;
v_10872:
    if (v_10965 == nil) goto v_10870;
    goto v_10887;
v_10883:
    v_10966 = stack[-2];
    goto v_10884;
v_10885:
    v_10965 = stack[-1];
    goto v_10886;
v_10887:
    goto v_10883;
v_10884:
    goto v_10885;
v_10886:
    {
        fn = elt(env, 5); // !:divide
        return (*qfn2(fn))(fn, v_10966, v_10965);
    }
v_10870:
    goto v_10901;
v_10897:
    v_10965 = stack[-2];
    v_10965 = qcar(v_10965);
    v_10966 = qcdr(v_10965);
    goto v_10898;
v_10899:
    v_10965 = stack[-1];
    goto v_10900;
v_10901:
    goto v_10897;
v_10898:
    goto v_10899;
v_10900:
    fn = elt(env, 6); // qremf
    v_10965 = (*qfn2(fn))(fn, v_10966, v_10965);
    env = stack[-4];
    stack[-3] = v_10965;
    goto v_10911;
v_10907:
    goto v_10917;
v_10913:
    goto v_10923;
v_10919:
    goto v_10930;
v_10926:
    v_10965 = stack[-2];
    v_10965 = qcar(v_10965);
    v_10966 = qcar(v_10965);
    goto v_10927;
v_10928:
    v_10965 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10929;
v_10930:
    goto v_10926;
v_10927:
    goto v_10928;
v_10929:
    v_10965 = cons(v_10966, v_10965);
    env = stack[-4];
    v_10966 = ncons(v_10965);
    env = stack[-4];
    goto v_10920;
v_10921:
    v_10965 = stack[-3];
    v_10965 = qcar(v_10965);
    goto v_10922;
v_10923:
    goto v_10919;
v_10920:
    goto v_10921;
v_10922:
    fn = elt(env, 7); // multf
    stack[0] = (*qfn2(fn))(fn, v_10966, v_10965);
    env = stack[-4];
    goto v_10914;
v_10915:
    goto v_10942;
v_10938:
    goto v_10949;
v_10945:
    v_10965 = stack[-2];
    v_10965 = qcar(v_10965);
    v_10966 = qcar(v_10965);
    goto v_10946;
v_10947:
    v_10965 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10948;
v_10949:
    goto v_10945;
v_10946:
    goto v_10947;
v_10948:
    v_10965 = cons(v_10966, v_10965);
    env = stack[-4];
    v_10966 = ncons(v_10965);
    env = stack[-4];
    goto v_10939;
v_10940:
    v_10965 = stack[-3];
    v_10965 = qcdr(v_10965);
    goto v_10941;
v_10942:
    goto v_10938;
v_10939:
    goto v_10940;
v_10941:
    fn = elt(env, 7); // multf
    v_10965 = (*qfn2(fn))(fn, v_10966, v_10965);
    env = stack[-4];
    goto v_10916;
v_10917:
    goto v_10913;
v_10914:
    goto v_10915;
v_10916:
    stack[0] = cons(stack[0], v_10965);
    env = stack[-4];
    goto v_10908;
v_10909:
    goto v_10961;
v_10957:
    v_10965 = stack[-2];
    v_10966 = qcdr(v_10965);
    goto v_10958;
v_10959:
    v_10965 = stack[-1];
    goto v_10960;
v_10961:
    goto v_10957;
v_10958:
    goto v_10959;
v_10960:
    v_10965 = CC_qremd(elt(env, 0), v_10966, v_10965);
    env = stack[-4];
    goto v_10910;
v_10911:
    goto v_10907;
v_10908:
    goto v_10909;
v_10910:
    {
        LispObject v_10971 = stack[0];
        fn = elt(env, 8); // praddf
        return (*qfn2(fn))(fn, v_10971, v_10965);
    }
    goto v_10832;
    v_10965 = nil;
v_10832:
    return onevalue(v_10965);
}



// Code for il_simp

static LispObject CC_il_simp(LispObject env,
                         LispObject v_10828)
{
    env = qenv(env);
    LispObject v_10838, v_10839;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10838 = v_10828;
// end of prologue
    goto v_10835;
v_10831:
    v_10839 = v_10838;
    goto v_10832;
v_10833:
    v_10838 = nil;
    goto v_10834;
v_10835:
    goto v_10831;
v_10832:
    goto v_10833;
v_10834:
    {
        fn = elt(env, 1); // il_simp1
        return (*qfn2(fn))(fn, v_10839, v_10838);
    }
}



// Code for arplus!:

static LispObject CC_arplusT(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_10854, v_10855, v_10856;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10828,v_10829);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_10855 = v_10829;
    v_10856 = v_10828;
// end of prologue
// Binding dmode!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = nil; // dmode!*
// Binding !*exp
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-3, 2, -1);
    qvalue(elt(env, 2)) = nil; // !*exp
    v_10854 = lisp_true;
    qvalue(elt(env, 2)) = v_10854; // !*exp
    goto v_10842;
v_10838:
    stack[0] = elt(env, 4); // !:ar!:
    goto v_10839;
v_10840:
    goto v_10849;
v_10845:
    v_10854 = v_10856;
    v_10854 = qcdr(v_10854);
    goto v_10846;
v_10847:
    v_10855 = qcdr(v_10855);
    goto v_10848;
v_10849:
    goto v_10845;
v_10846:
    goto v_10847;
v_10848:
    fn = elt(env, 5); // addf
    v_10854 = (*qfn2(fn))(fn, v_10854, v_10855);
    env = stack[-3];
    goto v_10841;
v_10842:
    goto v_10838;
v_10839:
    goto v_10840;
v_10841:
    v_10854 = cons(stack[0], v_10854);
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_10854);
}



// Code for subf1

static LispObject CC_subf1(LispObject env,
                         LispObject v_10828, LispObject v_10829)
{
    env = qenv(env);
    LispObject v_11577, v_11578, v_11579;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10829,v_10828);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10828,v_10829);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(15);
// copy arguments values to proper place
    stack[-11] = v_10829;
    stack[-12] = v_10828;
// end of prologue
    v_11577 = stack[-12];
    if (v_11577 == nil) goto v_10833;
    else goto v_10834;
v_10833:
    goto v_10841;
v_10837:
    v_11578 = nil;
    goto v_10838;
v_10839:
    v_11577 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10840;
v_10841:
    goto v_10837;
v_10838:
    goto v_10839;
v_10840:
    return cons(v_11578, v_11577);
v_10834:
    v_11577 = stack[-12];
    if (!consp(v_11577)) goto v_10848;
    else goto v_10849;
v_10848:
    v_11577 = lisp_true;
    goto v_10847;
v_10849:
    v_11577 = stack[-12];
    v_11577 = qcar(v_11577);
    v_11577 = (consp(v_11577) ? nil : lisp_true);
    goto v_10847;
    v_11577 = nil;
v_10847:
    if (v_11577 == nil) goto v_10845;
    v_11577 = stack[-12];
    if (!consp(v_11577)) goto v_10859;
    else goto v_10860;
v_10859:
    v_11577 = qvalue(elt(env, 1)); // dmode!*
    if (v_11577 == nil) goto v_10864;
    else goto v_10865;
v_10864:
    goto v_10872;
v_10868:
    v_11578 = stack[-12];
    goto v_10869;
v_10870:
    v_11577 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10871;
v_10872:
    goto v_10868;
v_10869:
    goto v_10870;
v_10871:
    return cons(v_11578, v_11577);
v_10865:
    v_11577 = stack[-12];
    {
        fn = elt(env, 12); // simpatom
        return (*qfn1(fn))(fn, v_11577);
    }
    v_11577 = nil;
    goto v_10858;
v_10860:
    goto v_10889;
v_10885:
    v_11578 = qvalue(elt(env, 1)); // dmode!*
    goto v_10886;
v_10887:
    v_11577 = stack[-12];
    v_11577 = qcar(v_11577);
    goto v_10888;
v_10889:
    goto v_10885;
v_10886:
    goto v_10887;
v_10888:
    if (v_11578 == v_11577) goto v_10883;
    else goto v_10884;
v_10883:
    goto v_10898;
v_10894:
    v_11578 = qvalue(elt(env, 1)); // dmode!*
    goto v_10895;
v_10896:
    v_11577 = elt(env, 2); // resimplify
    goto v_10897;
v_10898:
    goto v_10894;
v_10895:
    goto v_10896;
v_10897:
    v_11577 = Lflagp(nil, v_11578, v_11577);
    env = stack[-14];
    v_11577 = (v_11577 == nil ? lisp_true : nil);
    goto v_10882;
v_10884:
    v_11577 = nil;
    goto v_10882;
    v_11577 = nil;
v_10882:
    if (v_11577 == nil) goto v_10880;
    v_11577 = stack[-12];
    {
        fn = elt(env, 13); // !*d2q
        return (*qfn1(fn))(fn, v_11577);
    }
v_10880:
    v_11577 = stack[-12];
    fn = elt(env, 14); // prepf
    v_11577 = (*qfn1(fn))(fn, v_11577);
    env = stack[-14];
    {
        fn = elt(env, 15); // simp
        return (*qfn1(fn))(fn, v_11577);
    }
    v_11577 = nil;
v_10858:
    goto v_10832;
v_10845:
// Binding varstack!*
// FLUIDBIND: reloadenv=14 litvec-offset=3 saveloc=9
{   bind_fluid_stack bind_fluid_var(-14, 3, -9);
    qvalue(elt(env, 3)) = nil; // varstack!*
    stack[-5] = nil;
    stack[-4] = nil;
    v_11577 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-13] = v_11577;
    goto v_10945;
v_10941:
    v_11578 = nil;
    goto v_10942;
v_10943:
    v_11577 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10944;
v_10945:
    goto v_10941;
v_10942:
    goto v_10943;
v_10944:
    v_11577 = cons(v_11578, v_11577);
    env = stack[-14];
    stack[-3] = v_11577;
v_10929:
    v_11577 = stack[-12];
    v_11577 = qcar(v_11577);
    v_11577 = qcar(v_11577);
    v_11577 = qcar(v_11577);
    stack[-2] = v_11577;
    v_11577 = nil;
    stack[0] = v_11577;
    goto v_10962;
v_10958:
    v_11578 = stack[-2];
    goto v_10959;
v_10960:
    v_11577 = stack[-11];
    goto v_10961;
v_10962:
    goto v_10958;
v_10959:
    goto v_10960;
v_10961:
    v_11577 = Lassoc(nil, v_11578, v_11577);
    if (v_11577 == nil) goto v_10956;
    goto v_10971;
v_10967:
    v_11578 = stack[-2];
    goto v_10968;
v_10969:
    v_11577 = qvalue(elt(env, 5)); // wtl!*
    goto v_10970;
v_10971:
    goto v_10967;
v_10968:
    goto v_10969;
v_10970:
    v_11577 = Lassoc(nil, v_11578, v_11577);
    stack[0] = v_11577;
    if (v_11577 == nil) goto v_10956;
    v_11577 = stack[0];
    v_11577 = qcdr(v_11577);
    stack[0] = v_11577;
    goto v_10954;
v_10956:
v_10954:
    goto v_10985;
v_10981:
    v_11578 = stack[-2];
    goto v_10982;
v_10983:
    v_11577 = qvalue(elt(env, 6)); // asymplis!*
    goto v_10984;
v_10985:
    goto v_10981;
v_10982:
    goto v_10983;
v_10984:
    v_11577 = Lassoc(nil, v_11578, v_11577);
    stack[-10] = v_11577;
    if (v_11577 == nil) goto v_10980;
    v_11577 = stack[-10];
    v_11577 = qcdr(v_11577);
    stack[-10] = v_11577;
    goto v_10978;
v_10980:
v_10978:
v_10930:
    v_11577 = stack[-12];
    if (v_11577 == nil) goto v_10997;
    else goto v_10998;
v_10997:
    v_11577 = lisp_true;
    goto v_10996;
v_10998:
    goto v_11007;
v_11003:
    goto v_11013;
v_11009:
    v_11578 = stack[-12];
    goto v_11010;
v_11011:
    v_11577 = stack[-2];
    goto v_11012;
v_11013:
    goto v_11009;
v_11010:
    goto v_11011;
v_11012:
    fn = elt(env, 16); // degr
    v_11578 = (*qfn2(fn))(fn, v_11578, v_11577);
    env = stack[-14];
    stack[-13] = v_11578;
    goto v_11004;
v_11005:
    v_11577 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11006;
v_11007:
    goto v_11003;
v_11004:
    goto v_11005;
v_11006:
    v_11577 = (v_11578 == v_11577 ? lisp_true : nil);
    goto v_10996;
    v_11577 = nil;
v_10996:
    if (v_11577 == nil) goto v_10994;
    goto v_10931;
v_10994:
    v_11577 = stack[-10];
    if (v_11577 == nil) goto v_11022;
    else goto v_11023;
v_11022:
    v_11577 = lisp_true;
    goto v_11021;
v_11023:
    goto v_11033;
v_11029:
    v_11578 = stack[-13];
    goto v_11030;
v_11031:
    v_11577 = stack[-10];
    goto v_11032;
v_11033:
    goto v_11029;
v_11030:
    goto v_11031;
v_11032:
    v_11577 = (LispObject)lessp2(v_11578, v_11577);
    v_11577 = v_11577 ? lisp_true : nil;
    env = stack[-14];
    goto v_11021;
    v_11577 = nil;
v_11021:
    if (v_11577 == nil) goto v_11019;
    goto v_11041;
v_11037:
    goto v_11047;
v_11043:
    v_11577 = stack[-12];
    v_11578 = qcar(v_11577);
    goto v_11044;
v_11045:
    v_11577 = stack[0];
    goto v_11046;
v_11047:
    goto v_11043;
v_11044:
    goto v_11045;
v_11046:
    fn = elt(env, 17); // wtchk
    v_11578 = (*qfn2(fn))(fn, v_11578, v_11577);
    env = stack[-14];
    goto v_11038;
v_11039:
    v_11577 = stack[-5];
    goto v_11040;
v_11041:
    goto v_11037;
v_11038:
    goto v_11039;
v_11040:
    v_11577 = cons(v_11578, v_11577);
    env = stack[-14];
    stack[-5] = v_11577;
    goto v_10992;
v_11019:
v_10992:
    v_11577 = stack[-12];
    v_11577 = qcdr(v_11577);
    stack[-12] = v_11577;
    goto v_10930;
v_10931:
    v_11577 = nil;
    v_11579 = v_11577;
v_11057:
    v_11577 = stack[-11];
    if (v_11577 == nil) goto v_11060;
    else goto v_11061;
v_11060:
    goto v_11056;
v_11061:
    goto v_11072;
v_11068:
    v_11577 = stack[-11];
    v_11577 = qcar(v_11577);
    v_11578 = qcar(v_11577);
    goto v_11069;
v_11070:
    v_11577 = stack[-11];
    v_11577 = qcar(v_11577);
    v_11577 = qcdr(v_11577);
    goto v_11071;
v_11072:
    goto v_11068;
v_11069:
    goto v_11070;
v_11071:
    if (equal(v_11578, v_11577)) goto v_11067;
    goto v_11084;
v_11080:
    v_11577 = stack[-11];
    v_11577 = qcar(v_11577);
    goto v_11081;
v_11082:
    v_11578 = v_11579;
    goto v_11083;
v_11084:
    goto v_11080;
v_11081:
    goto v_11082;
v_11083:
    v_11577 = cons(v_11577, v_11578);
    env = stack[-14];
    v_11579 = v_11577;
    goto v_11065;
v_11067:
v_11065:
    v_11577 = stack[-11];
    v_11577 = qcdr(v_11577);
    stack[-11] = v_11577;
    goto v_11057;
v_11056:
    v_11577 = v_11579;
    v_11577 = Lnreverse(nil, v_11577);
    env = stack[-14];
    stack[-11] = v_11577;
    v_11577 = stack[-2];
    if (!consp(v_11577)) goto v_11099;
    v_11577 = stack[-2];
    v_11577 = qcar(v_11577);
    v_11577 = (consp(v_11577) ? nil : lisp_true);
    v_11577 = (v_11577 == nil ? lisp_true : nil);
    goto v_11097;
v_11099:
    v_11577 = nil;
    goto v_11097;
    v_11577 = nil;
v_11097:
    if (v_11577 == nil) goto v_11095;
    v_11577 = stack[-2];
    fn = elt(env, 14); // prepf
    v_11577 = (*qfn1(fn))(fn, v_11577);
    env = stack[-14];
    stack[-2] = v_11577;
    goto v_11093;
v_11095:
v_11093:
    v_11577 = stack[-11];
    if (v_11577 == nil) goto v_11112;
    else goto v_11113;
v_11112:
    goto v_11123;
v_11119:
    v_11578 = stack[-2];
    goto v_11120;
v_11121:
    v_11577 = elt(env, 7); // k!*
    goto v_11122;
v_11123:
    goto v_11119;
v_11120:
    goto v_11121;
v_11122:
    if (v_11578 == v_11577) goto v_11117;
    else goto v_11118;
v_11117:
    v_11577 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11116;
v_11118:
    v_11577 = stack[-2];
    goto v_11116;
    v_11577 = nil;
v_11116:
    stack[-1] = v_11577;
    goto v_11111;
v_11113:
    goto v_11140;
v_11136:
    goto v_11146;
v_11142:
    v_11578 = stack[-11];
    goto v_11143;
v_11144:
    v_11577 = stack[-2];
    goto v_11145;
v_11146:
    goto v_11142;
v_11143:
    goto v_11144;
v_11145:
    fn = elt(env, 18); // subsublis
    v_11578 = (*qfn2(fn))(fn, v_11578, v_11577);
    env = stack[-14];
    stack[-1] = v_11578;
    goto v_11137;
v_11138:
    v_11577 = stack[-2];
    goto v_11139;
v_11140:
    goto v_11136;
v_11137:
    goto v_11138;
v_11139:
    if (equal(v_11578, v_11577)) goto v_11134;
    else goto v_11135;
v_11134:
    goto v_11154;
v_11150:
    v_11578 = stack[-2];
    goto v_11151;
v_11152:
    v_11577 = qvalue(elt(env, 6)); // asymplis!*
    goto v_11153;
v_11154:
    goto v_11150;
v_11151:
    goto v_11152;
v_11153:
    v_11577 = Lassoc(nil, v_11578, v_11577);
    v_11577 = (v_11577 == nil ? lisp_true : nil);
    goto v_11133;
v_11135:
    v_11577 = nil;
    goto v_11133;
    v_11577 = nil;
v_11133:
    if (v_11577 == nil) goto v_11131;
    goto v_10934;
v_11131:
v_11111:
v_10932:
    goto v_11167;
v_11163:
    v_11578 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11164;
v_11165:
    v_11577 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11166;
v_11167:
    goto v_11163;
v_11164:
    goto v_11165;
v_11166:
    v_11577 = cons(v_11578, v_11577);
    env = stack[-14];
    stack[-8] = v_11577;
    v_11577 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-13] = v_11577;
    v_11577 = stack[-5];
    if (v_11577 == nil) goto v_11174;
    v_11577 = stack[-5];
    v_11577 = qcar(v_11577);
    v_11577 = qcar(v_11577);
    v_11577 = qcdr(v_11577);
    v_11577 = Lminusp(nil, v_11577);
    env = stack[-14];
    if (v_11577 == nil) goto v_11174;
    goto v_10935;
v_11174:
    goto v_11191;
v_11187:
    v_11577 = stack[-1];
    fn = elt(env, 19); // getrtype
    v_11578 = (*qfn1(fn))(fn, v_11577);
    env = stack[-14];
    stack[-7] = v_11578;
    goto v_11188;
v_11189:
    v_11577 = elt(env, 8); // yetunknowntype
    goto v_11190;
v_11191:
    goto v_11187;
v_11188:
    goto v_11189;
v_11190:
    if (v_11578 == v_11577) goto v_11185;
    else goto v_11186;
v_11185:
    goto v_11201;
v_11197:
    v_11578 = stack[-1];
    goto v_11198;
v_11199:
    v_11577 = nil;
    goto v_11200;
v_11201:
    goto v_11197;
v_11198:
    goto v_11199;
v_11200:
    fn = elt(env, 20); // eval!-yetunknowntypeexpr
    v_11577 = (*qfn2(fn))(fn, v_11578, v_11577);
    env = stack[-14];
    stack[-1] = v_11577;
    fn = elt(env, 19); // getrtype
    v_11577 = (*qfn1(fn))(fn, v_11577);
    env = stack[-14];
    stack[-7] = v_11577;
    goto v_11184;
v_11186:
v_11184:
    v_11577 = stack[-7];
    if (v_11577 == nil) goto v_11207;
    goto v_11215;
v_11211:
    v_11578 = stack[-7];
    goto v_11212;
v_11213:
    v_11577 = elt(env, 9); // list
    goto v_11214;
v_11215:
    goto v_11211;
v_11212:
    goto v_11213;
v_11214:
    if (v_11578 == v_11577) goto v_11207;
    goto v_11223;
v_11219:
    goto v_11229;
v_11225:
    v_11578 = stack[-7];
    goto v_11226;
v_11227:
    v_11577 = stack[-1];
    goto v_11228;
v_11229:
    goto v_11225;
v_11226:
    goto v_11227;
v_11228:
    v_11578 = list2(v_11578, v_11577);
    env = stack[-14];
    goto v_11220;
v_11221:
    v_11577 = elt(env, 10); // "substituted expression"
    goto v_11222;
v_11223:
    goto v_11219;
v_11220:
    goto v_11221;
v_11222:
    fn = elt(env, 21); // typerr
    v_11577 = (*qfn2(fn))(fn, v_11578, v_11577);
    env = stack[-14];
    goto v_11205;
v_11207:
v_11205:
    v_11577 = nil;
    fn = elt(env, 22); // setkorder
    v_11577 = (*qfn1(fn))(fn, v_11577);
    env = stack[-14];
    stack[0] = v_11577;
    v_11577 = stack[-1];
    fn = elt(env, 15); // simp
    v_11577 = (*qfn1(fn))(fn, v_11577);
    env = stack[-14];
    stack[-7] = v_11577;
    v_11577 = stack[0];
    fn = elt(env, 22); // setkorder
    v_11577 = (*qfn1(fn))(fn, v_11577);
    env = stack[-14];
    v_11577 = stack[-7];
    fn = elt(env, 23); // reordsq
    v_11577 = (*qfn1(fn))(fn, v_11577);
    env = stack[-14];
    stack[-7] = v_11577;
    v_11577 = stack[-11];
    if (v_11577 == nil) goto v_11247;
    else goto v_11248;
v_11247:
    v_11577 = stack[-7];
    fn = elt(env, 24); // kernp
    v_11577 = (*qfn1(fn))(fn, v_11577);
    env = stack[-14];
    if (v_11577 == nil) goto v_11252;
    else goto v_11253;
v_11252:
    v_11577 = nil;
    goto v_11251;
v_11253:
    goto v_11263;
v_11259:
    v_11577 = stack[-7];
    v_11577 = qcar(v_11577);
    v_11577 = qcar(v_11577);
    v_11577 = qcar(v_11577);
    v_11578 = qcar(v_11577);
    goto v_11260;
v_11261:
    v_11577 = stack[-2];
    goto v_11262;
v_11263:
    goto v_11259;
v_11260:
    goto v_11261;
v_11262:
    v_11577 = (v_11578 == v_11577 ? lisp_true : nil);
    goto v_11251;
    v_11577 = nil;
v_11251:
    goto v_11246;
v_11248:
    v_11577 = nil;
    goto v_11246;
    v_11577 = nil;
v_11246:
    if (v_11577 == nil) goto v_11244;
    goto v_10934;
v_11244:
    v_11577 = stack[-7];
    v_11577 = qcar(v_11577);
    if (v_11577 == nil) goto v_11274;
    else goto v_11275;
v_11274:
    goto v_10933;
v_11275:
    v_11577 = stack[-7];
    stack[-6] = v_11577;
    v_11577 = stack[-5];
    stack[-2] = v_11577;
v_11282:
    v_11577 = stack[-2];
    if (v_11577 == nil) goto v_11286;
    else goto v_11287;
v_11286:
    goto v_11281;
v_11287:
    v_11577 = stack[-2];
    v_11577 = qcar(v_11577);
    stack[-1] = v_11577;
    v_11577 = stack[-1];
    v_11577 = qcar(v_11577);
    v_11577 = qcdr(v_11577);
    stack[-10] = v_11577;
    goto v_11304;
v_11300:
    v_11578 = stack[-10];
    goto v_11301;
v_11302:
    v_11577 = qvalue(elt(env, 11)); // frlis!*
    goto v_11303;
v_11304:
    goto v_11300;
v_11301:
    goto v_11302;
v_11303:
    v_11577 = Lmemq(nil, v_11578, v_11577);
    if (v_11577 == nil) goto v_11299;
    goto v_11314;
v_11310:
    v_11577 = stack[-6];
    fn = elt(env, 25); // prepsq
    v_11578 = (*qfn1(fn))(fn, v_11577);
    env = stack[-14];
    goto v_11311;
v_11312:
    v_11577 = stack[-10];
    goto v_11313;
v_11314:
    goto v_11310;
v_11311:
    goto v_11312;
v_11313:
    v_11577 = list2(v_11578, v_11577);
    env = stack[-14];
    fn = elt(env, 26); // simpexpt
    v_11577 = (*qfn1(fn))(fn, v_11577);
    env = stack[-14];
    stack[-7] = v_11577;
    v_11577 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-10] = v_11577;
    goto v_11297;
v_11299:
v_11297:
    goto v_11324;
v_11320:
    goto v_11331;
v_11327:
    stack[0] = stack[-7];
    goto v_11328;
v_11329:
    goto v_11338;
v_11334:
    v_11578 = stack[-10];
    goto v_11335;
v_11336:
    v_11577 = stack[-13];
    goto v_11337;
v_11338:
    goto v_11334;
v_11335:
    goto v_11336;
v_11337:
    v_11577 = difference2(v_11578, v_11577);
    env = stack[-14];
    goto v_11330;
v_11331:
    goto v_11327;
v_11328:
    goto v_11329;
v_11330:
    fn = elt(env, 27); // exptsq
    v_11577 = (*qfn2(fn))(fn, stack[0], v_11577);
    env = stack[-14];
    fn = elt(env, 28); // subs2
    v_11578 = (*qfn1(fn))(fn, v_11577);
    env = stack[-14];
    goto v_11321;
v_11322:
    v_11577 = stack[-8];
    goto v_11323;
v_11324:
    goto v_11320;
v_11321:
    goto v_11322;
v_11323:
    fn = elt(env, 29); // multsq
    v_11577 = (*qfn2(fn))(fn, v_11578, v_11577);
    env = stack[-14];
    stack[-8] = v_11577;
    v_11577 = stack[-10];
    stack[-13] = v_11577;
    goto v_11348;
v_11344:
    goto v_11354;
v_11350:
    stack[0] = stack[-8];
    goto v_11351;
v_11352:
    goto v_11361;
v_11357:
    v_11577 = stack[-1];
    v_11578 = qcdr(v_11577);
    goto v_11358;
v_11359:
    v_11577 = stack[-11];
    goto v_11360;
v_11361:
    goto v_11357;
v_11358:
    goto v_11359;
v_11360:
    v_11577 = CC_subf1(elt(env, 0), v_11578, v_11577);
    env = stack[-14];
    goto v_11353;
v_11354:
    goto v_11350;
v_11351:
    goto v_11352;
v_11353:
    fn = elt(env, 29); // multsq
    v_11578 = (*qfn2(fn))(fn, stack[0], v_11577);
    env = stack[-14];
    goto v_11345;
v_11346:
    v_11577 = stack[-3];
    goto v_11347;
v_11348:
    goto v_11344;
v_11345:
    goto v_11346;
v_11347:
    fn = elt(env, 30); // addsq
    v_11577 = (*qfn2(fn))(fn, v_11578, v_11577);
    env = stack[-14];
    stack[-3] = v_11577;
    v_11577 = stack[-2];
    v_11577 = qcdr(v_11577);
    stack[-2] = v_11577;
    goto v_11282;
v_11281:
v_10933:
v_11370:
    v_11577 = stack[-5];
    if (v_11577 == nil) goto v_11373;
    else goto v_11374;
v_11373:
    goto v_11369;
v_11374:
    goto v_11382;
v_11378:
    v_11577 = stack[-5];
    v_11577 = qcar(v_11577);
    v_11578 = qcdr(v_11577);
    goto v_11379;
v_11380:
    v_11577 = stack[-11];
    goto v_11381;
v_11382:
    goto v_11378;
v_11379:
    goto v_11380;
v_11381:
    v_11577 = CC_subf1(elt(env, 0), v_11578, v_11577);
    env = stack[-14];
    v_11577 = stack[-5];
    v_11577 = qcdr(v_11577);
    stack[-5] = v_11577;
    goto v_11370;
v_11369:
    v_11577 = stack[-12];
    if (v_11577 == nil) goto v_11391;
    else goto v_11392;
v_11391:
    v_11577 = stack[-3];
    goto v_10928;
v_11392:
    v_11577 = stack[-12];
    if (!consp(v_11577)) goto v_11399;
    else goto v_11400;
v_11399:
    v_11577 = lisp_true;
    goto v_11398;
v_11400:
    v_11577 = stack[-12];
    v_11577 = qcar(v_11577);
    v_11577 = (consp(v_11577) ? nil : lisp_true);
    goto v_11398;
    v_11577 = nil;
v_11398:
    if (v_11577 == nil) goto v_11396;
    goto v_11413;
v_11409:
    goto v_11419;
v_11415:
    v_11578 = stack[-12];
    goto v_11416;
v_11417:
    v_11577 = stack[-11];
    goto v_11418;
v_11419:
    goto v_11415;
v_11416:
    goto v_11417;
v_11418:
    v_11578 = CC_subf1(elt(env, 0), v_11578, v_11577);
    env = stack[-14];
    goto v_11410;
v_11411:
    v_11577 = stack[-3];
    goto v_11412;
v_11413:
    goto v_11409;
v_11410:
    goto v_11411;
v_11412:
    fn = elt(env, 30); // addsq
    v_11577 = (*qfn2(fn))(fn, v_11578, v_11577);
    goto v_10928;
v_11396:
    goto v_10929;
v_10934:
    v_11577 = stack[-2];
    fn = elt(env, 31); // sub2chk
    v_11577 = (*qfn1(fn))(fn, v_11577);
    env = stack[-14];
    v_11577 = stack[-5];
    stack[-2] = v_11577;
v_11428:
    v_11577 = stack[-2];
    if (v_11577 == nil) goto v_11432;
    else goto v_11433;
v_11432:
    goto v_11427;
v_11433:
    v_11577 = stack[-2];
    v_11577 = qcar(v_11577);
    stack[-1] = v_11577;
    goto v_11444;
v_11440:
    goto v_11450;
v_11446:
    goto v_11456;
v_11452:
    goto v_11463;
v_11459:
    v_11577 = stack[-1];
    v_11578 = qcar(v_11577);
    goto v_11460;
v_11461:
    v_11577 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11462;
v_11463:
    goto v_11459;
v_11460:
    goto v_11461;
v_11462:
    v_11577 = cons(v_11578, v_11577);
    env = stack[-14];
    v_11578 = ncons(v_11577);
    env = stack[-14];
    goto v_11453;
v_11454:
    v_11577 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11455;
v_11456:
    goto v_11452;
v_11453:
    goto v_11454;
v_11455:
    stack[0] = cons(v_11578, v_11577);
    env = stack[-14];
    goto v_11447;
v_11448:
    goto v_11473;
v_11469:
    v_11577 = stack[-1];
    v_11578 = qcdr(v_11577);
    goto v_11470;
v_11471:
    v_11577 = stack[-11];
    goto v_11472;
v_11473:
    goto v_11469;
v_11470:
    goto v_11471;
v_11472:
    v_11577 = CC_subf1(elt(env, 0), v_11578, v_11577);
    env = stack[-14];
    goto v_11449;
v_11450:
    goto v_11446;
v_11447:
    goto v_11448;
v_11449:
    fn = elt(env, 29); // multsq
    v_11578 = (*qfn2(fn))(fn, stack[0], v_11577);
    env = stack[-14];
    goto v_11441;
v_11442:
    v_11577 = stack[-3];
    goto v_11443;
v_11444:
    goto v_11440;
v_11441:
    goto v_11442;
v_11443:
    fn = elt(env, 30); // addsq
    v_11577 = (*qfn2(fn))(fn, v_11578, v_11577);
    env = stack[-14];
    stack[-3] = v_11577;
    v_11577 = stack[-2];
    v_11577 = qcdr(v_11577);
    stack[-2] = v_11577;
    goto v_11428;
v_11427:
    goto v_10933;
v_10935:
    v_11577 = stack[-1];
    v_11577 = ncons(v_11577);
    env = stack[-14];
    fn = elt(env, 32); // simprecip
    v_11577 = (*qfn1(fn))(fn, v_11577);
    env = stack[-14];
    stack[-7] = v_11577;
v_10936:
    goto v_11488;
v_11484:
    v_11577 = stack[-5];
    v_11578 = qcar(v_11577);
    goto v_11485;
v_11486:
    v_11577 = stack[-4];
    goto v_11487;
v_11488:
    goto v_11484;
v_11485:
    goto v_11486;
v_11487:
    v_11577 = cons(v_11578, v_11577);
    env = stack[-14];
    stack[-4] = v_11577;
    v_11577 = stack[-5];
    v_11577 = qcdr(v_11577);
    stack[-5] = v_11577;
    v_11577 = stack[-5];
    if (v_11577 == nil) goto v_11497;
    goto v_11506;
v_11502:
    v_11577 = stack[-5];
    v_11577 = qcar(v_11577);
    v_11577 = qcar(v_11577);
    v_11578 = qcdr(v_11577);
    goto v_11503;
v_11504:
    v_11577 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11505;
v_11506:
    goto v_11502;
v_11503:
    goto v_11504;
v_11505:
    v_11577 = (LispObject)lessp2(v_11578, v_11577);
    v_11577 = v_11577 ? lisp_true : nil;
    env = stack[-14];
    if (v_11577 == nil) goto v_11497;
    goto v_10936;
v_11497:
v_10937:
    v_11577 = stack[-4];
    v_11577 = qcar(v_11577);
    v_11577 = qcar(v_11577);
    v_11577 = qcdr(v_11577);
    v_11577 = negate(v_11577);
    env = stack[-14];
    stack[-10] = v_11577;
    goto v_11522;
v_11518:
    goto v_11529;
v_11525:
    stack[0] = stack[-7];
    goto v_11526;
v_11527:
    goto v_11536;
v_11532:
    v_11578 = stack[-10];
    goto v_11533;
v_11534:
    v_11577 = stack[-13];
    goto v_11535;
v_11536:
    goto v_11532;
v_11533:
    goto v_11534;
v_11535:
    v_11577 = difference2(v_11578, v_11577);
    env = stack[-14];
    goto v_11528;
v_11529:
    goto v_11525;
v_11526:
    goto v_11527;
v_11528:
    fn = elt(env, 27); // exptsq
    v_11577 = (*qfn2(fn))(fn, stack[0], v_11577);
    env = stack[-14];
    fn = elt(env, 28); // subs2
    v_11578 = (*qfn1(fn))(fn, v_11577);
    env = stack[-14];
    goto v_11519;
v_11520:
    v_11577 = stack[-8];
    goto v_11521;
v_11522:
    goto v_11518;
v_11519:
    goto v_11520;
v_11521:
    fn = elt(env, 29); // multsq
    v_11577 = (*qfn2(fn))(fn, v_11578, v_11577);
    env = stack[-14];
    stack[-8] = v_11577;
    v_11577 = stack[-10];
    stack[-13] = v_11577;
    goto v_11546;
v_11542:
    goto v_11552;
v_11548:
    stack[0] = stack[-8];
    goto v_11549;
v_11550:
    goto v_11559;
v_11555:
    v_11577 = stack[-4];
    v_11577 = qcar(v_11577);
    v_11578 = qcdr(v_11577);
    goto v_11556;
v_11557:
    v_11577 = stack[-11];
    goto v_11558;
v_11559:
    goto v_11555;
v_11556:
    goto v_11557;
v_11558:
    v_11577 = CC_subf1(elt(env, 0), v_11578, v_11577);
    env = stack[-14];
    goto v_11551;
v_11552:
    goto v_11548;
v_11549:
    goto v_11550;
v_11551:
    fn = elt(env, 29); // multsq
    v_11578 = (*qfn2(fn))(fn, stack[0], v_11577);
    env = stack[-14];
    goto v_11543;
v_11544:
    v_11577 = stack[-3];
    goto v_11545;
v_11546:
    goto v_11542;
v_11543:
    goto v_11544;
v_11545:
    fn = elt(env, 30); // addsq
    v_11577 = (*qfn2(fn))(fn, v_11578, v_11577);
    env = stack[-14];
    stack[-3] = v_11577;
    v_11577 = stack[-4];
    v_11577 = qcdr(v_11577);
    stack[-4] = v_11577;
    v_11577 = stack[-4];
    if (v_11577 == nil) goto v_11570;
    goto v_10937;
v_11570:
    v_11577 = stack[-5];
    if (v_11577 == nil) goto v_11573;
    goto v_10932;
v_11573:
    goto v_10933;
    v_11577 = nil;
v_10928:
    ;}  // end of a binding scope
    goto v_10832;
    v_11577 = nil;
v_10832:
    return onevalue(v_11577);
}



setup_type const u20_setup[] =
{
    {"ofsf_entry2at",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_entry2at},
    {"rl_atl",                  CC_rl_atl,      TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_unvar-unsatlist",   TOO_FEW_2,      CC_ibalp_unvarKunsatlist,WRONG_NO_2},
    {"*wedgepf2pf",             CC_Hwedgepf2pf, TOO_MANY_1,    WRONG_NO_1},
    {"equalreplaceby",          CC_equalreplaceby,TOO_MANY_1,  WRONG_NO_1},
    {"inttovec",                TOO_FEW_2,      CC_inttovec,   WRONG_NO_2},
    {"physopaeval",             CC_physopaeval, TOO_MANY_1,    WRONG_NO_1},
    {"zero-roads",              CC_zeroKroads,  TOO_MANY_1,    WRONG_NO_1},
    {"mo_times_ei",             TOO_FEW_2,      CC_mo_times_ei,WRONG_NO_2},
    {"idcons_ordp",             TOO_FEW_2,      CC_idcons_ordp,WRONG_NO_2},
    {"general-reduce-mod-p",    CC_generalKreduceKmodKp,TOO_MANY_1,WRONG_NO_1},
    {"ordexn",                  TOO_FEW_2,      CC_ordexn,     WRONG_NO_2},
    {"next-random-number",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_nextKrandomKnumber},
    {"rrdls",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rrdls},
    {"aex_fvarl",               CC_aex_fvarl,   TOO_MANY_1,    WRONG_NO_1},
    {"rl_nnf",                  CC_rl_nnf,      TOO_MANY_1,    WRONG_NO_1},
    {"sfto_ucontentf1",         TOO_FEW_2,      CC_sfto_ucontentf1,WRONG_NO_2},
    {"findnthroot",             CC_findnthroot, TOO_MANY_1,    WRONG_NO_1},
    {"lx2xx",                   CC_lx2xx,       TOO_MANY_1,    WRONG_NO_1},
    {"rl_simp1",                CC_rl_simp1,    TOO_MANY_1,    WRONG_NO_1},
    {"mvar_member",             TOO_FEW_2,      CC_mvar_member,WRONG_NO_2},
    {"tobvarir",                CC_tobvarir,    TOO_MANY_1,    WRONG_NO_1},
    {"floatprop",               CC_floatprop,   TOO_MANY_1,    WRONG_NO_1},
    {"gpexp1p",                 CC_gpexp1p,     TOO_MANY_1,    WRONG_NO_1},
    {"contr",                   TOO_FEW_2,      CC_contr,      WRONG_NO_2},
    {"addgt",                   CC_addgt,       TOO_MANY_1,    WRONG_NO_1},
    {"di_restore",              CC_di_restore,  TOO_MANY_1,    WRONG_NO_1},
    {"expt-mod-p",              TOO_FEW_2,      CC_exptKmodKp, WRONG_NO_2},
    {"lex_start_line_comment",  CC_lex_start_line_comment,TOO_MANY_1,WRONG_NO_1},
    {"read_namelist",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_read_namelist},
    {"monomdivide",             TOO_FEW_2,      CC_monomdivide,WRONG_NO_2},
    {"ofsf_smmkatl1",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smmkatl1},
    {"subsublis",               TOO_FEW_2,      CC_subsublis,  WRONG_NO_2},
    {"talp_rnf1",               CC_talp_rnf1,   TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_process-var",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ibalp_processKvar},
    {"dvfsf_susitf",            TOO_FEW_2,      CC_dvfsf_susitf,WRONG_NO_2},
    {"binomial-coefft-mod-p",   TOO_FEW_2,      CC_binomialKcoefftKmodKp,WRONG_NO_2},
    {"om2mml",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_om2mml},
    {"ps:minusp:",              CC_psTminuspT,  TOO_MANY_1,    WRONG_NO_1},
    {"groebcplistsortin",       TOO_FEW_2,      CC_groebcplistsortin,WRONG_NO_2},
    {"arg2of2",                 TOO_FEW_2,      CC_arg2of2,    WRONG_NO_2},
    {"xord_deglex",             TOO_FEW_2,      CC_xord_deglex,WRONG_NO_2},
    {"delete-dups",             CC_deleteKdups, TOO_MANY_1,    WRONG_NO_1},
    {"physop-ordop",            TOO_FEW_2,      CC_physopKordop,WRONG_NO_2},
    {"repasc",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_repasc},
    {"qremd",                   TOO_FEW_2,      CC_qremd,      WRONG_NO_2},
    {"il_simp",                 CC_il_simp,     TOO_MANY_1,    WRONG_NO_1},
    {"arplus:",                 TOO_FEW_2,      CC_arplusT,    WRONG_NO_2},
    {"subf1",                   TOO_FEW_2,      CC_subf1,      WRONG_NO_2},
    {NULL, (one_args *)"u20", (two_args *)"91568 6930952 3438715", 0}
};

// end of generated code
