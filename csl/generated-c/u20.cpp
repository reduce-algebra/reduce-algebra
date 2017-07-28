
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



// Code for ibalp_var!-unsatlist

static LispObject CC_ibalp_varKunsatlist(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11493, v_11494;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11430,v_11431);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_11431;
    v_11493 = v_11430;
// end of prologue
    stack[-3] = v_11493;
v_11436:
    v_11493 = stack[-3];
    if (v_11493 == nil) goto v_11440;
    else goto v_11441;
v_11440:
    v_11493 = nil;
    goto v_11435;
v_11441:
    v_11493 = stack[-3];
    v_11493 = qcar(v_11493);
    stack[-1] = v_11493;
    goto v_11456;
v_11452:
    v_11494 = stack[-2];
    goto v_11453;
v_11454:
    v_11493 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11455;
v_11456:
    goto v_11452;
v_11453:
    goto v_11454;
v_11455:
    v_11493 = Leqn(nil, v_11494, v_11493);
    env = stack[-4];
    if (v_11493 == nil) goto v_11450;
    goto v_11464;
v_11460:
    v_11493 = stack[-1];
    v_11493 = qcdr(v_11493);
    v_11493 = qcdr(v_11493);
    stack[0] = qcdr(v_11493);
    goto v_11461;
v_11462:
    v_11493 = stack[-1];
    v_11493 = qcdr(v_11493);
    v_11493 = qcdr(v_11493);
    v_11493 = qcdr(v_11493);
    v_11493 = qcar(v_11493);
    v_11493 = sub1(v_11493);
    env = stack[-4];
    goto v_11463;
v_11464:
    goto v_11460;
v_11461:
    goto v_11462;
v_11463:
    fn = elt(env, 1); // setcar
    v_11493 = (*qfn2(fn))(fn, stack[0], v_11493);
    env = stack[-4];
    goto v_11448;
v_11450:
    goto v_11482;
v_11478:
    v_11493 = stack[-1];
    v_11493 = qcdr(v_11493);
    stack[0] = qcdr(v_11493);
    goto v_11479;
v_11480:
    v_11493 = stack[-1];
    v_11493 = qcdr(v_11493);
    v_11493 = qcdr(v_11493);
    v_11493 = qcar(v_11493);
    v_11493 = sub1(v_11493);
    env = stack[-4];
    goto v_11481;
v_11482:
    goto v_11478;
v_11479:
    goto v_11480;
v_11481:
    fn = elt(env, 1); // setcar
    v_11493 = (*qfn2(fn))(fn, stack[0], v_11493);
    env = stack[-4];
    goto v_11448;
v_11448:
    v_11493 = stack[-3];
    v_11493 = qcdr(v_11493);
    stack[-3] = v_11493;
    goto v_11436;
v_11435:
    return onevalue(v_11493);
}



// Code for dvfsf_susitf

static LispObject CC_dvfsf_susitf(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11434, v_11435;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11434 = v_11431;
    v_11435 = v_11430;
// end of prologue
    v_11434 = v_11435;
    return onevalue(v_11434);
}



// Code for stats_getargs

static LispObject CC_stats_getargs(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11449, v_11450;
    LispObject fn;
    argcheck(nargs, 0, "stats_getargs");
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
    fn = elt(env, 1); // mathml
    v_11449 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_11450 = v_11449;
    v_11449 = v_11450;
    if (v_11449 == nil) goto v_11439;
    goto v_11446;
v_11442:
    stack[0] = v_11450;
    goto v_11443;
v_11444:
    v_11449 = CC_stats_getargs(elt(env, 0), 0);
    goto v_11445;
v_11446:
    goto v_11442;
v_11443:
    goto v_11444;
v_11445:
    {
        LispObject v_11452 = stack[0];
        return cons(v_11452, v_11449);
    }
v_11439:
    v_11449 = nil;
    return onevalue(v_11449);
}



// Code for list!-mgen

static LispObject CC_listKmgen(LispObject env,
                         LispObject v_11430)
{
    env = qenv(env);
    LispObject v_11469, v_11470;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11430);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_11470 = v_11430;
// end of prologue
// Binding i
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 1, -1);
    qvalue(elt(env, 1)) = nil; // i
    v_11469 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_11469; // i
    v_11469 = v_11470;
    stack[0] = v_11469;
v_11439:
    v_11469 = stack[0];
    if (v_11469 == nil) goto v_11443;
    else goto v_11444;
v_11443:
    goto v_11438;
v_11444:
    v_11469 = stack[0];
    v_11469 = qcar(v_11469);
    v_11470 = v_11469;
    v_11469 = v_11470;
    if (!consp(v_11469)) goto v_11456;
    else goto v_11457;
v_11456:
    v_11469 = v_11470;
    fn = elt(env, 2); // mgenp
    v_11469 = (*qfn1(fn))(fn, v_11469);
    env = stack[-2];
    goto v_11455;
v_11457:
    v_11469 = nil;
    goto v_11455;
    v_11469 = nil;
v_11455:
    if (v_11469 == nil) goto v_11453;
    v_11469 = qvalue(elt(env, 1)); // i
    v_11469 = add1(v_11469);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_11469; // i
    goto v_11451;
v_11453:
v_11451:
    v_11469 = stack[0];
    v_11469 = qcdr(v_11469);
    stack[0] = v_11469;
    goto v_11439;
v_11438:
    v_11469 = qvalue(elt(env, 1)); // i
    ;}  // end of a binding scope
    return onevalue(v_11469);
}



// Code for prinfit

static LispObject CC_prinfit(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11498, v_11499, v_11500;
    LispObject fn;
    LispObject v_11432, v_11431, v_11430;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "prinfit");
    va_start(aa, nargs);
    v_11430 = va_arg(aa, LispObject);
    v_11431 = va_arg(aa, LispObject);
    v_11432 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_11432,v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_11430,v_11431,v_11432);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11432;
    stack[-1] = v_11431;
    stack[-2] = v_11430;
// end of prologue
    v_11498 = qvalue(elt(env, 1)); // !*nat
    if (v_11498 == nil) goto v_11443;
    else goto v_11444;
v_11443:
    v_11498 = lisp_true;
    goto v_11442;
v_11444:
    v_11498 = qvalue(elt(env, 2)); // testing!-width!*
    goto v_11442;
    v_11498 = nil;
v_11442:
    if (v_11498 == nil) goto v_11440;
    v_11498 = stack[0];
    if (v_11498 == nil) goto v_11453;
    v_11498 = stack[0];
    fn = elt(env, 3); // oprin
    v_11498 = (*qfn1(fn))(fn, v_11498);
    env = stack[-3];
    goto v_11451;
v_11453:
v_11451:
    goto v_11462;
v_11458:
    v_11499 = stack[-2];
    goto v_11459;
v_11460:
    v_11498 = stack[-1];
    goto v_11461;
v_11462:
    goto v_11458;
v_11459:
    goto v_11460;
v_11461:
    {
        fn = elt(env, 4); // maprint
        return (*qfn2(fn))(fn, v_11499, v_11498);
    }
v_11440:
    goto v_11472;
v_11466:
    v_11500 = stack[-2];
    goto v_11467;
v_11468:
    v_11499 = stack[-1];
    goto v_11469;
v_11470:
    v_11498 = stack[0];
    goto v_11471;
v_11472:
    goto v_11466;
v_11467:
    goto v_11468;
v_11469:
    goto v_11470;
v_11471:
    fn = elt(env, 5); // layout!-formula
    v_11498 = (*qfnn(fn))(fn, 3, v_11500, v_11499, v_11498);
    env = stack[-3];
    v_11499 = v_11498;
    v_11498 = v_11499;
    if (v_11498 == nil) goto v_11478;
    else goto v_11479;
v_11478:
    v_11498 = stack[0];
    if (v_11498 == nil) goto v_11484;
    v_11498 = stack[0];
    fn = elt(env, 3); // oprin
    v_11498 = (*qfn1(fn))(fn, v_11498);
    env = stack[-3];
    goto v_11482;
v_11484:
v_11482:
    goto v_11493;
v_11489:
    v_11499 = stack[-2];
    goto v_11490;
v_11491:
    v_11498 = stack[-1];
    goto v_11492;
v_11493:
    goto v_11489;
v_11490:
    goto v_11491;
v_11492:
    {
        fn = elt(env, 4); // maprint
        return (*qfn2(fn))(fn, v_11499, v_11498);
    }
v_11479:
    v_11498 = v_11499;
    fn = elt(env, 6); // putpline
    v_11498 = (*qfn1(fn))(fn, v_11498);
    v_11498 = nil;
    return onevalue(v_11498);
}



// Code for lispassignp

static LispObject CC_lispassignp(LispObject env,
                         LispObject v_11430)
{
    env = qenv(env);
    LispObject v_11440, v_11441;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11440 = v_11430;
// end of prologue
    goto v_11437;
v_11433:
    goto v_11434;
v_11435:
    v_11441 = elt(env, 1); // setq
    goto v_11436;
v_11437:
    goto v_11433;
v_11434:
    goto v_11435;
v_11436:
        return Leqcar(nil, v_11440, v_11441);
}



// Code for assert_uninstall1

static LispObject CC_assert_uninstall1(LispObject env,
                         LispObject v_11430)
{
    env = qenv(env);
    LispObject v_11481, v_11482, v_11483;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11430);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_11430;
// end of prologue
    goto v_11441;
v_11437:
    v_11482 = stack[0];
    goto v_11438;
v_11439:
    v_11481 = elt(env, 1); // assert_installed
    goto v_11440;
v_11441:
    goto v_11437;
v_11438:
    goto v_11439;
v_11440:
    v_11481 = get(v_11482, v_11481);
    env = stack[-1];
    if (v_11481 == nil) goto v_11434;
    else goto v_11435;
v_11434:
    goto v_11450;
v_11446:
    v_11482 = elt(env, 2); // "assert not installed for"
    goto v_11447;
v_11448:
    v_11481 = stack[0];
    goto v_11449;
v_11450:
    goto v_11446;
v_11447:
    goto v_11448;
v_11449:
    v_11481 = list2(v_11482, v_11481);
    env = stack[-1];
    {
        fn = elt(env, 4); // lprim
        return (*qfn1(fn))(fn, v_11481);
    }
v_11435:
    goto v_11460;
v_11456:
    v_11483 = stack[0];
    goto v_11457;
v_11458:
    goto v_11467;
v_11463:
    v_11482 = stack[0];
    goto v_11464;
v_11465:
    v_11481 = elt(env, 3); // assert_noassertfn
    goto v_11466;
v_11467:
    goto v_11463;
v_11464:
    goto v_11465;
v_11466:
    v_11481 = get(v_11482, v_11481);
    env = stack[-1];
    goto v_11459;
v_11460:
    goto v_11456;
v_11457:
    goto v_11458;
v_11459:
    fn = elt(env, 5); // copyd
    v_11481 = (*qfn2(fn))(fn, v_11483, v_11481);
    env = stack[-1];
    goto v_11477;
v_11471:
    v_11482 = stack[0];
    goto v_11472;
v_11473:
    v_11483 = elt(env, 1); // assert_installed
    goto v_11474;
v_11475:
    v_11481 = nil;
    goto v_11476;
v_11477:
    goto v_11471;
v_11472:
    goto v_11473;
v_11474:
    goto v_11475;
v_11476:
        return Lputprop(nil, 3, v_11482, v_11483, v_11481);
    v_11481 = nil;
    return onevalue(v_11481);
}



// Code for evalequal

static LispObject CC_evalequal(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11484, v_11485, v_11486;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11430,v_11431);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11431;
    stack[-2] = v_11430;
// end of prologue
    goto v_11444;
v_11440:
    v_11484 = stack[-2];
    fn = elt(env, 2); // getrtype
    stack[0] = (*qfn1(fn))(fn, v_11484);
    env = stack[-4];
    stack[-3] = stack[0];
    goto v_11441;
v_11442:
    v_11484 = stack[-1];
    fn = elt(env, 2); // getrtype
    v_11484 = (*qfn1(fn))(fn, v_11484);
    env = stack[-4];
    goto v_11443;
v_11444:
    goto v_11440;
v_11441:
    goto v_11442;
v_11443:
    if (equal(stack[0], v_11484)) goto v_11439;
    v_11484 = nil;
    goto v_11437;
v_11439:
    v_11484 = stack[-3];
    if (v_11484 == nil) goto v_11450;
    else goto v_11451;
v_11450:
    goto v_11465;
v_11459:
    v_11486 = elt(env, 1); // difference
    goto v_11460;
v_11461:
    v_11485 = stack[-2];
    goto v_11462;
v_11463:
    v_11484 = stack[-1];
    goto v_11464;
v_11465:
    goto v_11459;
v_11460:
    goto v_11461;
v_11462:
    goto v_11463;
v_11464:
    v_11484 = list3(v_11486, v_11485, v_11484);
    env = stack[-4];
    fn = elt(env, 3); // reval
    v_11484 = (*qfn1(fn))(fn, v_11484);
    stack[-3] = v_11484;
    if (is_number(v_11484)) goto v_11456;
    v_11484 = nil;
    goto v_11454;
v_11456:
    v_11484 = stack[-3];
        return Lzerop(nil, v_11484);
    v_11484 = nil;
v_11454:
    goto v_11437;
v_11451:
    goto v_11480;
v_11476:
    v_11485 = stack[-2];
    goto v_11477;
v_11478:
    v_11484 = stack[-1];
    goto v_11479;
v_11480:
    goto v_11476;
v_11477:
    goto v_11478;
v_11479:
    v_11484 = (equal(v_11485, v_11484) ? lisp_true : nil);
    goto v_11437;
    v_11484 = nil;
v_11437:
    return onevalue(v_11484);
}



// Code for mv2sf1

static LispObject CC_mv2sf1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11489, v_11490, v_11491;
    LispObject fn;
    LispObject v_11432, v_11431, v_11430;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mv2sf1");
    va_start(aa, nargs);
    v_11430 = va_arg(aa, LispObject);
    v_11431 = va_arg(aa, LispObject);
    v_11432 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_11432,v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_11430,v_11431,v_11432);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_11432;
    stack[-1] = v_11431;
    stack[-2] = v_11430;
// end of prologue
v_11436:
    v_11489 = stack[-2];
    if (v_11489 == nil) goto v_11439;
    else goto v_11440;
v_11439:
    v_11489 = stack[-1];
    goto v_11435;
v_11440:
    goto v_11449;
v_11445:
    v_11489 = stack[-2];
    v_11490 = qcar(v_11489);
    goto v_11446;
v_11447:
    v_11489 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11448;
v_11449:
    goto v_11445;
v_11446:
    goto v_11447;
v_11448:
    if (v_11490 == v_11489) goto v_11443;
    else goto v_11444;
v_11443:
    v_11489 = stack[-2];
    v_11489 = qcdr(v_11489);
    stack[-2] = v_11489;
    v_11489 = stack[0];
    v_11489 = qcdr(v_11489);
    stack[0] = v_11489;
    goto v_11436;
v_11444:
    goto v_11465;
v_11461:
    goto v_11471;
v_11467:
    v_11489 = stack[0];
    v_11490 = qcar(v_11489);
    goto v_11468;
v_11469:
    v_11489 = stack[-2];
    v_11489 = qcar(v_11489);
    goto v_11470;
v_11471:
    goto v_11467;
v_11468:
    goto v_11469;
v_11470:
    fn = elt(env, 1); // to
    stack[-3] = (*qfn2(fn))(fn, v_11490, v_11489);
    env = stack[-4];
    goto v_11462;
v_11463:
    goto v_11483;
v_11477:
    v_11489 = stack[-2];
    v_11491 = qcdr(v_11489);
    goto v_11478;
v_11479:
    v_11490 = stack[-1];
    goto v_11480;
v_11481:
    v_11489 = stack[0];
    v_11489 = qcdr(v_11489);
    goto v_11482;
v_11483:
    goto v_11477;
v_11478:
    goto v_11479;
v_11480:
    goto v_11481;
v_11482:
    v_11489 = CC_mv2sf1(elt(env, 0), 3, v_11491, v_11490, v_11489);
    env = stack[-4];
    goto v_11464;
v_11465:
    goto v_11461;
v_11462:
    goto v_11463;
v_11464:
    v_11489 = cons(stack[-3], v_11489);
    return ncons(v_11489);
    v_11489 = nil;
v_11435:
    return onevalue(v_11489);
}



// Code for setk0

static LispObject CC_setk0(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11595, v_11596, v_11597, v_11598;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11430,v_11431);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11431;
    stack[-2] = v_11430;
// end of prologue
// Binding frasc!*
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 1, 0);
    qvalue(elt(env, 1)) = nil; // frasc!*
    v_11595 = stack[-1];
    fn = elt(env, 6); // getrtype
    v_11595 = (*qfn1(fn))(fn, v_11595);
    env = stack[-4];
    stack[-3] = v_11595;
    if (v_11595 == nil) goto v_11440;
    goto v_11450;
v_11446:
    v_11596 = stack[-3];
    goto v_11447;
v_11448:
    v_11595 = elt(env, 2); // setelemfn
    goto v_11449;
v_11450:
    goto v_11446;
v_11447:
    goto v_11448;
v_11449:
    v_11595 = get(v_11596, v_11595);
    env = stack[-4];
    if (v_11595 == nil) goto v_11440;
    v_11595 = nil;
    v_11595 = ncons(v_11595);
    env = stack[-4];
    qvalue(elt(env, 3)) = v_11595; // alglist!*
    goto v_11464;
v_11456:
    v_11598 = stack[-2];
    goto v_11457;
v_11458:
    v_11597 = stack[-1];
    goto v_11459;
v_11460:
    v_11596 = nil;
    goto v_11461;
v_11462:
    v_11595 = lisp_true;
    goto v_11463;
v_11464:
    goto v_11456;
v_11457:
    goto v_11458;
v_11459:
    goto v_11460;
v_11461:
    goto v_11462;
v_11463:
    fn = elt(env, 7); // let2
    v_11595 = (*qfnn(fn))(fn, 4, v_11598, v_11597, v_11596, v_11595);
    goto v_11438;
v_11440:
    v_11595 = stack[-2];
    if (!consp(v_11595)) goto v_11474;
    v_11595 = stack[-2];
    v_11595 = qcar(v_11595);
    if (symbolp(v_11595)) goto v_11479;
    v_11595 = nil;
    goto v_11477;
v_11479:
    v_11595 = stack[-2];
    fn = elt(env, 6); // getrtype
    v_11595 = (*qfn1(fn))(fn, v_11595);
    env = stack[-4];
    if (v_11595 == nil) goto v_11494;
    else goto v_11493;
v_11494:
    v_11595 = stack[-2];
    v_11595 = qcar(v_11595);
    if (!symbolp(v_11595)) v_11595 = nil;
    else { v_11595 = qfastgets(v_11595);
           if (v_11595 != nil) { v_11595 = elt(v_11595, 2); // rtype
#ifdef RECORD_GET
             if (v_11595 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_11595 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_11595 == SPID_NOPROP) v_11595 = nil; }}
#endif
v_11493:
    stack[-3] = v_11595;
    if (v_11595 == nil) goto v_11490;
    else goto v_11491;
v_11490:
    v_11595 = nil;
    goto v_11489;
v_11491:
    goto v_11508;
v_11504:
    v_11596 = stack[-3];
    goto v_11505;
v_11506:
    v_11595 = elt(env, 2); // setelemfn
    goto v_11507;
v_11508:
    goto v_11504;
v_11505:
    goto v_11506;
v_11507:
    v_11595 = get(v_11596, v_11595);
    env = stack[-4];
    stack[-3] = v_11595;
    goto v_11489;
    v_11595 = nil;
v_11489:
    if (v_11595 == nil) goto v_11487;
    else goto v_11486;
v_11487:
    goto v_11516;
v_11512:
    v_11595 = stack[-2];
    v_11596 = qcar(v_11595);
    goto v_11513;
v_11514:
    v_11595 = elt(env, 4); // setkfn
    goto v_11515;
v_11516:
    goto v_11512;
v_11513:
    goto v_11514;
v_11515:
    v_11595 = get(v_11596, v_11595);
    env = stack[-4];
    stack[-3] = v_11595;
v_11486:
    goto v_11477;
    v_11595 = nil;
v_11477:
    goto v_11472;
v_11474:
    v_11595 = nil;
    goto v_11472;
    v_11595 = nil;
v_11472:
    if (v_11595 == nil) goto v_11470;
    v_11595 = nil;
    v_11595 = ncons(v_11595);
    env = stack[-4];
    qvalue(elt(env, 3)) = v_11595; // alglist!*
    goto v_11532;
v_11526:
    v_11597 = stack[-3];
    goto v_11527;
v_11528:
    v_11596 = stack[-2];
    goto v_11529;
v_11530:
    v_11595 = stack[-1];
    goto v_11531;
v_11532:
    goto v_11526;
v_11527:
    goto v_11528;
v_11529:
    goto v_11530;
v_11531:
    v_11595 = Lapply2(nil, 3, v_11597, v_11596, v_11595);
    goto v_11438;
v_11470:
    v_11595 = stack[-2];
    if (!consp(v_11595)) goto v_11541;
    v_11595 = stack[-2];
    v_11595 = qcar(v_11595);
    if (!consp(v_11595)) goto v_11546;
    goto v_11554;
v_11550:
    v_11595 = stack[-2];
    v_11595 = qcar(v_11595);
    v_11596 = qcar(v_11595);
    goto v_11551;
v_11552:
    v_11595 = elt(env, 5); // setstructfn
    goto v_11553;
v_11554:
    goto v_11550;
v_11551:
    goto v_11552;
v_11553:
    v_11595 = get(v_11596, v_11595);
    env = stack[-4];
    stack[-3] = v_11595;
    goto v_11544;
v_11546:
    v_11595 = nil;
    goto v_11544;
    v_11595 = nil;
v_11544:
    goto v_11539;
v_11541:
    v_11595 = nil;
    goto v_11539;
    v_11595 = nil;
v_11539:
    if (v_11595 == nil) goto v_11537;
    v_11595 = nil;
    v_11595 = ncons(v_11595);
    env = stack[-4];
    qvalue(elt(env, 3)) = v_11595; // alglist!*
    goto v_11574;
v_11568:
    v_11597 = stack[-3];
    goto v_11569;
v_11570:
    v_11596 = stack[-2];
    goto v_11571;
v_11572:
    v_11595 = stack[-1];
    goto v_11573;
v_11574:
    goto v_11568;
v_11569:
    goto v_11570;
v_11571:
    goto v_11572;
v_11573:
    v_11595 = Lapply2(nil, 3, v_11597, v_11596, v_11595);
    goto v_11438;
v_11537:
    goto v_11589;
v_11581:
    v_11598 = stack[-2];
    goto v_11582;
v_11583:
    v_11597 = stack[-1];
    goto v_11584;
v_11585:
    v_11596 = nil;
    goto v_11586;
v_11587:
    v_11595 = lisp_true;
    goto v_11588;
v_11589:
    goto v_11581;
v_11582:
    goto v_11583;
v_11584:
    goto v_11585;
v_11586:
    goto v_11587;
v_11588:
    fn = elt(env, 7); // let2
    v_11595 = (*qfnn(fn))(fn, 4, v_11598, v_11597, v_11596, v_11595);
    goto v_11438;
v_11438:
    v_11595 = stack[-1];
    ;}  // end of a binding scope
    return onevalue(v_11595);
}



// Code for next!-random!-number

static LispObject CC_nextKrandomKnumber(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11513, v_11514, v_11515, v_11516;
    argcheck(nargs, 0, "next-random-number");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    goto v_11442;
v_11438:
    v_11514 = qvalue(elt(env, 1)); // unidev_next!*
    goto v_11439;
v_11440:
    v_11513 = (LispObject)864+TAG_FIXNUM; // 54
    goto v_11441;
v_11442:
    goto v_11438;
v_11439:
    goto v_11440;
v_11441:
    if (v_11514 == v_11513) goto v_11436;
    else goto v_11437;
v_11436:
    v_11513 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_11513; // unidev_next!*
    goto v_11435;
v_11437:
    v_11513 = qvalue(elt(env, 1)); // unidev_next!*
    v_11513 = (LispObject)((intptr_t)(v_11513) + 0x10);
    qvalue(elt(env, 1)) = v_11513; // unidev_next!*
    goto v_11435;
v_11435:
    goto v_11458;
v_11454:
    v_11514 = qvalue(elt(env, 2)); // unidev_nextp!*
    goto v_11455;
v_11456:
    v_11513 = (LispObject)864+TAG_FIXNUM; // 54
    goto v_11457;
v_11458:
    goto v_11454;
v_11455:
    goto v_11456;
v_11457:
    if (v_11514 == v_11513) goto v_11452;
    else goto v_11453;
v_11452:
    v_11513 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 2)) = v_11513; // unidev_nextp!*
    goto v_11451;
v_11453:
    v_11513 = qvalue(elt(env, 2)); // unidev_nextp!*
    v_11513 = (LispObject)((intptr_t)(v_11513) + 0x10);
    qvalue(elt(env, 2)) = v_11513; // unidev_nextp!*
    goto v_11451;
v_11451:
    goto v_11470;
v_11466:
    goto v_11475;
v_11471:
    v_11514 = qvalue(elt(env, 3)); // unidev_vec!*
    goto v_11472;
v_11473:
    v_11513 = qvalue(elt(env, 1)); // unidev_next!*
    goto v_11474;
v_11475:
    goto v_11471;
v_11472:
    goto v_11473;
v_11474:
    v_11515 = *(LispObject *)((char *)v_11514 + (CELL-TAG_VECTOR) + (((intptr_t)v_11513-TAG_FIXNUM)/(16/CELL)));
    goto v_11467;
v_11468:
    goto v_11483;
v_11479:
    v_11514 = qvalue(elt(env, 3)); // unidev_vec!*
    goto v_11480;
v_11481:
    v_11513 = qvalue(elt(env, 2)); // unidev_nextp!*
    goto v_11482;
v_11483:
    goto v_11479;
v_11480:
    goto v_11481;
v_11482:
    v_11513 = *(LispObject *)((char *)v_11514 + (CELL-TAG_VECTOR) + (((intptr_t)v_11513-TAG_FIXNUM)/(16/CELL)));
    goto v_11469;
v_11470:
    goto v_11466;
v_11467:
    goto v_11468;
v_11469:
    v_11513 = (LispObject)(intptr_t)((intptr_t)v_11515 - (intptr_t)v_11513 + TAG_FIXNUM);
    v_11515 = v_11513;
    v_11513 = v_11515;
    v_11513 = ((intptr_t)(v_11513) < 0 ? lisp_true : nil);
    if (v_11513 == nil) goto v_11491;
    goto v_11498;
v_11494:
    v_11514 = v_11515;
    goto v_11495;
v_11496:
    v_11513 = qvalue(elt(env, 4)); // randommodulus!*
    goto v_11497;
v_11498:
    goto v_11494;
v_11495:
    goto v_11496;
v_11497:
    v_11513 = (LispObject)(intptr_t)((intptr_t)v_11514 + (intptr_t)v_11513 - TAG_FIXNUM);
    v_11515 = v_11513;
    goto v_11489;
v_11491:
v_11489:
    goto v_11508;
v_11502:
    v_11514 = qvalue(elt(env, 3)); // unidev_vec!*
    goto v_11503;
v_11504:
    v_11516 = qvalue(elt(env, 1)); // unidev_next!*
    goto v_11505;
v_11506:
    v_11513 = v_11515;
    goto v_11507;
v_11508:
    goto v_11502;
v_11503:
    goto v_11504;
v_11505:
    goto v_11506;
v_11507:
    *(LispObject *)((char *)v_11514 + (CELL-TAG_VECTOR) + (((intptr_t)v_11516-TAG_FIXNUM)/(16/CELL))) = v_11513;
    v_11513 = v_11515;
    return onevalue(v_11513);
}



// Code for print_with_margin_sub

static LispObject CC_print_with_margin_sub(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11798, v_11799, v_11800, v_11801;
    LispObject fn;
    LispObject v_11433, v_11432, v_11431, v_11430;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "print_with_margin_sub");
    va_start(aa, nargs);
    v_11430 = va_arg(aa, LispObject);
    v_11431 = va_arg(aa, LispObject);
    v_11432 = va_arg(aa, LispObject);
    v_11433 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_11433,v_11432,v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_11430,v_11431,v_11432,v_11433);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_11433;
    stack[-2] = v_11432;
    stack[-3] = v_11431;
    stack[-4] = v_11430;
// end of prologue
    goto v_11448;
v_11444:
    v_11799 = stack[-2];
    goto v_11445;
v_11446:
    v_11798 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_11447;
v_11448:
    goto v_11444;
v_11445:
    goto v_11446;
v_11447:
    v_11798 = (LispObject)lessp2(v_11799, v_11798);
    v_11798 = v_11798 ? lisp_true : nil;
    env = stack[-6];
    if (v_11798 == nil) goto v_11442;
    v_11798 = (LispObject)160+TAG_FIXNUM; // 10
    stack[-2] = v_11798;
    goto v_11440;
v_11442:
v_11440:
    goto v_11461;
v_11457:
    stack[0] = stack[-3];
    goto v_11458;
v_11459:
    goto v_11468;
v_11464:
    v_11799 = stack[-2];
    goto v_11465;
v_11466:
    v_11798 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_11467;
v_11468:
    goto v_11464;
v_11465:
    goto v_11466;
v_11467:
    v_11798 = difference2(v_11799, v_11798);
    env = stack[-6];
    goto v_11460;
v_11461:
    goto v_11457;
v_11458:
    goto v_11459;
v_11460:
    v_11798 = (LispObject)greaterp2(stack[0], v_11798);
    v_11798 = v_11798 ? lisp_true : nil;
    env = stack[-6];
    if (v_11798 == nil) goto v_11455;
    goto v_11476;
v_11472:
    v_11799 = stack[-2];
    goto v_11473;
v_11474:
    v_11798 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_11475;
v_11476:
    goto v_11472;
v_11473:
    goto v_11474;
v_11475:
    v_11798 = difference2(v_11799, v_11798);
    env = stack[-6];
    stack[-3] = v_11798;
    goto v_11453;
v_11455:
v_11453:
    v_11798 = stack[-4];
    stack[-5] = v_11798;
    v_11798 = stack[-5];
    if (!consp(v_11798)) goto v_11483;
    goto v_11494;
v_11490:
    v_11799 = Lposn(nil, 0);
    env = stack[-6];
    goto v_11491;
v_11492:
    v_11798 = stack[-2];
    goto v_11493;
v_11494:
    goto v_11490;
v_11491:
    goto v_11492;
v_11493:
    v_11798 = (LispObject)geq2(v_11799, v_11798);
    v_11798 = v_11798 ? lisp_true : nil;
    env = stack[-6];
    if (v_11798 == nil) goto v_11488;
    v_11798 = Lterpri(nil, 0);
    env = stack[-6];
    v_11798 = stack[-3];
    v_11798 = Lttab(nil, v_11798);
    env = stack[-6];
    goto v_11486;
v_11488:
v_11486:
    v_11798 = elt(env, 1); // "("
    v_11798 = Lprinc(nil, v_11798);
    env = stack[-6];
    goto v_11511;
v_11503:
    v_11798 = stack[-5];
    v_11801 = qcar(v_11798);
    goto v_11504;
v_11505:
    v_11800 = stack[-3];
    goto v_11506;
v_11507:
    v_11799 = stack[-2];
    goto v_11508;
v_11509:
    v_11798 = stack[-1];
    goto v_11510;
v_11511:
    goto v_11503;
v_11504:
    goto v_11505;
v_11506:
    goto v_11507;
v_11508:
    goto v_11509;
v_11510:
    v_11798 = CC_print_with_margin_sub(elt(env, 0), 4, v_11801, v_11800, v_11799, v_11798);
    env = stack[-6];
v_11519:
    v_11798 = stack[-5];
    v_11798 = qcdr(v_11798);
    stack[-5] = v_11798;
    if (!consp(v_11798)) goto v_11522;
    else goto v_11523;
v_11522:
    goto v_11518;
v_11523:
    goto v_11536;
v_11532:
    v_11799 = Lposn(nil, 0);
    env = stack[-6];
    goto v_11533;
v_11534:
    v_11798 = stack[-2];
    goto v_11535;
v_11536:
    goto v_11532;
v_11533:
    goto v_11534;
v_11535:
    v_11798 = (LispObject)geq2(v_11799, v_11798);
    v_11798 = v_11798 ? lisp_true : nil;
    env = stack[-6];
    if (v_11798 == nil) goto v_11530;
    v_11798 = Lterpri(nil, 0);
    env = stack[-6];
    v_11798 = stack[-3];
    v_11798 = Lttab(nil, v_11798);
    env = stack[-6];
    goto v_11528;
v_11530:
    v_11798 = elt(env, 2); // " "
    v_11798 = Lprinc(nil, v_11798);
    env = stack[-6];
    goto v_11528;
v_11528:
    goto v_11555;
v_11547:
    v_11798 = stack[-5];
    v_11801 = qcar(v_11798);
    goto v_11548;
v_11549:
    v_11800 = stack[-3];
    goto v_11550;
v_11551:
    v_11799 = stack[-2];
    goto v_11552;
v_11553:
    v_11798 = stack[-1];
    goto v_11554;
v_11555:
    goto v_11547;
v_11548:
    goto v_11549;
v_11550:
    goto v_11551;
v_11552:
    goto v_11553;
v_11554:
    v_11798 = CC_print_with_margin_sub(elt(env, 0), 4, v_11801, v_11800, v_11799, v_11798);
    env = stack[-6];
    goto v_11519;
v_11518:
    v_11798 = stack[-5];
    if (v_11798 == nil) goto v_11564;
    goto v_11575;
v_11571:
    stack[0] = Lposn(nil, 0);
    env = stack[-6];
    goto v_11572;
v_11573:
    v_11798 = stack[-2];
    v_11798 = sub1(v_11798);
    env = stack[-6];
    goto v_11574;
v_11575:
    goto v_11571;
v_11572:
    goto v_11573;
v_11574:
    v_11798 = (LispObject)geq2(stack[0], v_11798);
    v_11798 = v_11798 ? lisp_true : nil;
    env = stack[-6];
    if (v_11798 == nil) goto v_11569;
    v_11798 = Lterpri(nil, 0);
    env = stack[-6];
    v_11798 = stack[-3];
    v_11798 = Lttab(nil, v_11798);
    env = stack[-6];
    v_11798 = elt(env, 3); // ". "
    v_11798 = Lprinc(nil, v_11798);
    env = stack[-6];
    goto v_11567;
v_11569:
    v_11798 = elt(env, 4); // " ."
    v_11798 = Lprinc(nil, v_11798);
    env = stack[-6];
    goto v_11567;
v_11567:
    goto v_11597;
v_11589:
    v_11801 = stack[-5];
    goto v_11590;
v_11591:
    v_11800 = stack[-3];
    goto v_11592;
v_11593:
    v_11799 = stack[-2];
    goto v_11594;
v_11595:
    v_11798 = stack[-1];
    goto v_11596;
v_11597:
    goto v_11589;
v_11590:
    goto v_11591;
v_11592:
    goto v_11593;
v_11594:
    goto v_11595;
v_11596:
    v_11798 = CC_print_with_margin_sub(elt(env, 0), 4, v_11801, v_11800, v_11799, v_11798);
    env = stack[-6];
    goto v_11562;
v_11564:
v_11562:
    goto v_11611;
v_11607:
    v_11799 = Lposn(nil, 0);
    env = stack[-6];
    goto v_11608;
v_11609:
    v_11798 = stack[-2];
    goto v_11610;
v_11611:
    goto v_11607;
v_11608:
    goto v_11609;
v_11610:
    v_11798 = (LispObject)geq2(v_11799, v_11798);
    v_11798 = v_11798 ? lisp_true : nil;
    env = stack[-6];
    if (v_11798 == nil) goto v_11605;
    v_11798 = Lterpri(nil, 0);
    env = stack[-6];
    v_11798 = stack[-3];
    v_11798 = Lttab(nil, v_11798);
    env = stack[-6];
    goto v_11603;
v_11605:
v_11603:
    v_11798 = elt(env, 5); // ")"
    v_11798 = Lprinc(nil, v_11798);
    v_11798 = stack[-4];
    goto v_11437;
v_11483:
    goto v_11625;
v_11621:
    stack[0] = stack[-1];
    goto v_11622;
v_11623:
    v_11798 = stack[-4];
    v_11798 = ncons(v_11798);
    env = stack[-6];
    goto v_11624;
v_11625:
    goto v_11621;
v_11622:
    goto v_11623;
v_11624:
    fn = elt(env, 7); // apply
    v_11798 = (*qfn2(fn))(fn, stack[0], v_11798);
    env = stack[-6];
    stack[-5] = v_11798;
v_11438:
    goto v_11638;
v_11634:
    goto v_11644;
v_11640:
    stack[0] = Lposn(nil, 0);
    env = stack[-6];
    goto v_11641;
v_11642:
    v_11798 = stack[-5];
    v_11798 = Llength(nil, v_11798);
    env = stack[-6];
    goto v_11643;
v_11644:
    goto v_11640;
v_11641:
    goto v_11642;
v_11643:
    v_11799 = plus2(stack[0], v_11798);
    env = stack[-6];
    goto v_11635;
v_11636:
    v_11798 = stack[-2];
    goto v_11637;
v_11638:
    goto v_11634;
v_11635:
    goto v_11636;
v_11637:
    v_11798 = (LispObject)lessp2(v_11799, v_11798);
    v_11798 = v_11798 ? lisp_true : nil;
    env = stack[-6];
    if (v_11798 == nil) goto v_11632;
    v_11798 = stack[-5];
    stack[0] = v_11798;
v_11652:
    v_11798 = stack[0];
    if (v_11798 == nil) goto v_11656;
    else goto v_11657;
v_11656:
    goto v_11651;
v_11657:
    v_11798 = stack[0];
    v_11798 = qcar(v_11798);
    v_11798 = Lprinc(nil, v_11798);
    env = stack[-6];
    v_11798 = stack[0];
    v_11798 = qcdr(v_11798);
    stack[0] = v_11798;
    goto v_11652;
v_11651:
    v_11798 = stack[-4];
    goto v_11437;
v_11632:
    goto v_11675;
v_11671:
    v_11798 = stack[-5];
    stack[0] = Llength(nil, v_11798);
    env = stack[-6];
    goto v_11672;
v_11673:
    goto v_11683;
v_11679:
    v_11799 = stack[-2];
    goto v_11680;
v_11681:
    v_11798 = stack[-3];
    goto v_11682;
v_11683:
    goto v_11679;
v_11680:
    goto v_11681;
v_11682:
    v_11798 = difference2(v_11799, v_11798);
    env = stack[-6];
    goto v_11674;
v_11675:
    goto v_11671;
v_11672:
    goto v_11673;
v_11674:
    v_11798 = (LispObject)lesseq2(stack[0], v_11798);
    v_11798 = v_11798 ? lisp_true : nil;
    env = stack[-6];
    if (v_11798 == nil) goto v_11669;
    v_11798 = Lterpri(nil, 0);
    env = stack[-6];
    v_11798 = stack[-3];
    v_11798 = Lttab(nil, v_11798);
    env = stack[-6];
    v_11798 = stack[-5];
    stack[0] = v_11798;
v_11692:
    v_11798 = stack[0];
    if (v_11798 == nil) goto v_11696;
    else goto v_11697;
v_11696:
    goto v_11691;
v_11697:
    v_11798 = stack[0];
    v_11798 = qcar(v_11798);
    v_11798 = Lprinc(nil, v_11798);
    env = stack[-6];
    v_11798 = stack[0];
    v_11798 = qcdr(v_11798);
    stack[0] = v_11798;
    goto v_11692;
v_11691:
    v_11798 = stack[-4];
    goto v_11437;
v_11669:
    goto v_11715;
v_11711:
    v_11798 = stack[-5];
    v_11799 = Llength(nil, v_11798);
    env = stack[-6];
    goto v_11712;
v_11713:
    v_11798 = stack[-2];
    goto v_11714;
v_11715:
    goto v_11711;
v_11712:
    goto v_11713;
v_11714:
    v_11798 = (LispObject)lessp2(v_11799, v_11798);
    v_11798 = v_11798 ? lisp_true : nil;
    env = stack[-6];
    if (v_11798 == nil) goto v_11709;
    v_11798 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_11726;
v_11722:
    stack[0] = stack[-2];
    goto v_11723;
v_11724:
    v_11798 = stack[-5];
    v_11798 = Llength(nil, v_11798);
    env = stack[-6];
    goto v_11725;
v_11726:
    goto v_11722;
v_11723:
    goto v_11724;
v_11725:
    v_11798 = difference2(stack[0], v_11798);
    env = stack[-6];
    v_11798 = Lttab(nil, v_11798);
    env = stack[-6];
    v_11798 = stack[-5];
    stack[0] = v_11798;
v_11733:
    v_11798 = stack[0];
    if (v_11798 == nil) goto v_11737;
    else goto v_11738;
v_11737:
    goto v_11732;
v_11738:
    v_11798 = stack[0];
    v_11798 = qcar(v_11798);
    v_11798 = Lprinc(nil, v_11798);
    env = stack[-6];
    v_11798 = stack[0];
    v_11798 = qcdr(v_11798);
    stack[0] = v_11798;
    goto v_11733;
v_11732:
    v_11798 = stack[-4];
    goto v_11437;
v_11709:
    goto v_11760;
v_11756:
    stack[0] = Lposn(nil, 0);
    env = stack[-6];
    goto v_11757;
v_11758:
    goto v_11767;
v_11763:
    v_11799 = stack[-2];
    goto v_11764;
v_11765:
    v_11798 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_11766;
v_11767:
    goto v_11763;
v_11764:
    goto v_11765;
v_11766:
    v_11798 = difference2(v_11799, v_11798);
    env = stack[-6];
    goto v_11759;
v_11760:
    goto v_11756;
v_11757:
    goto v_11758;
v_11759:
    v_11798 = (LispObject)geq2(stack[0], v_11798);
    v_11798 = v_11798 ? lisp_true : nil;
    env = stack[-6];
    if (v_11798 == nil) goto v_11754;
    v_11798 = Lterpri(nil, 0);
    env = stack[-6];
    v_11798 = stack[-3];
    v_11798 = Lttab(nil, v_11798);
    env = stack[-6];
    goto v_11752;
v_11754:
v_11752:
v_11775:
    goto v_11785;
v_11781:
    stack[0] = Lposn(nil, 0);
    env = stack[-6];
    goto v_11782;
v_11783:
    v_11798 = stack[-2];
    v_11798 = sub1(v_11798);
    env = stack[-6];
    goto v_11784;
v_11785:
    goto v_11781;
v_11782:
    goto v_11783;
v_11784:
    v_11798 = (LispObject)lessp2(stack[0], v_11798);
    v_11798 = v_11798 ? lisp_true : nil;
    env = stack[-6];
    if (v_11798 == nil) goto v_11778;
    else goto v_11779;
v_11778:
    goto v_11774;
v_11779:
    v_11798 = stack[-5];
    v_11798 = qcar(v_11798);
    v_11798 = Lprinc(nil, v_11798);
    env = stack[-6];
    v_11798 = stack[-5];
    v_11798 = qcdr(v_11798);
    stack[-5] = v_11798;
    goto v_11775;
v_11774:
    v_11798 = elt(env, 6); // "\"
    v_11798 = Lprinc(nil, v_11798);
    env = stack[-6];
    v_11798 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_11438;
    v_11798 = nil;
v_11437:
    return onevalue(v_11798);
}



// Code for cl_nnf

static LispObject CC_cl_nnf(LispObject env,
                         LispObject v_11430)
{
    env = qenv(env);
    LispObject v_11440, v_11441;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11440 = v_11430;
// end of prologue
    goto v_11437;
v_11433:
    v_11441 = v_11440;
    goto v_11434;
v_11435:
    v_11440 = lisp_true;
    goto v_11436;
v_11437:
    goto v_11433;
v_11434:
    goto v_11435;
v_11436:
    {
        fn = elt(env, 1); // cl_nnf1
        return (*qfn2(fn))(fn, v_11441, v_11440);
    }
}



// Code for subsublis

static LispObject CC_subsublis(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11657, v_11658, v_11659;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11430,v_11431);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_11431;
    stack[-3] = v_11430;
// end of prologue
v_11429:
    goto v_11444;
v_11440:
    v_11658 = stack[0];
    goto v_11441;
v_11442:
    v_11657 = stack[-3];
    goto v_11443;
v_11444:
    goto v_11440;
v_11441:
    goto v_11442;
v_11443:
    v_11657 = Lassoc(nil, v_11658, v_11657);
    v_11659 = v_11657;
    if (v_11657 == nil) goto v_11439;
    v_11657 = v_11659;
    v_11657 = qcdr(v_11657);
    goto v_11437;
v_11439:
    goto v_11461;
v_11457:
    v_11658 = stack[0];
    goto v_11458;
v_11459:
    v_11657 = elt(env, 1); // sqrt
    goto v_11460;
v_11461:
    goto v_11457;
v_11458:
    goto v_11459;
v_11460:
    if (!consp(v_11658)) goto v_11455;
    v_11658 = qcar(v_11658);
    if (v_11658 == v_11657) goto v_11454;
    else goto v_11455;
v_11454:
    goto v_11468;
v_11464:
    goto v_11476;
v_11470:
    v_11659 = elt(env, 2); // expt
    goto v_11471;
v_11472:
    v_11657 = stack[0];
    v_11657 = qcdr(v_11657);
    v_11658 = qcar(v_11657);
    goto v_11473;
v_11474:
    v_11657 = elt(env, 3); // (quotient 1 2)
    goto v_11475;
v_11476:
    goto v_11470;
v_11471:
    goto v_11472;
v_11473:
    goto v_11474;
v_11475:
    v_11658 = list3(v_11659, v_11658, v_11657);
    env = stack[-5];
    goto v_11465;
v_11466:
    v_11657 = stack[-3];
    goto v_11467;
v_11468:
    goto v_11464;
v_11465:
    goto v_11466;
v_11467:
    v_11657 = Lassoc(nil, v_11658, v_11657);
    v_11659 = v_11657;
    goto v_11453;
v_11455:
    v_11657 = nil;
    goto v_11453;
    v_11657 = nil;
v_11453:
    if (v_11657 == nil) goto v_11451;
    v_11657 = v_11659;
    v_11657 = qcdr(v_11657);
    goto v_11437;
v_11451:
    v_11657 = stack[0];
    if (!consp(v_11657)) goto v_11489;
    else goto v_11490;
v_11489:
    v_11657 = stack[0];
    goto v_11437;
v_11490:
    v_11657 = stack[0];
    v_11657 = qcar(v_11657);
    if (symbolp(v_11657)) goto v_11494;
    v_11657 = stack[0];
    stack[-4] = v_11657;
    v_11657 = stack[-4];
    if (v_11657 == nil) goto v_11506;
    else goto v_11507;
v_11506:
    v_11657 = nil;
    goto v_11501;
v_11507:
    v_11657 = stack[-4];
    v_11657 = qcar(v_11657);
    goto v_11519;
v_11515:
    v_11658 = stack[-3];
    goto v_11516;
v_11517:
    goto v_11518;
v_11519:
    goto v_11515;
v_11516:
    goto v_11517;
v_11518:
    v_11657 = CC_subsublis(elt(env, 0), v_11658, v_11657);
    env = stack[-5];
    v_11657 = ncons(v_11657);
    env = stack[-5];
    stack[-1] = v_11657;
    stack[-2] = v_11657;
v_11502:
    v_11657 = stack[-4];
    v_11657 = qcdr(v_11657);
    stack[-4] = v_11657;
    v_11657 = stack[-4];
    if (v_11657 == nil) goto v_11526;
    else goto v_11527;
v_11526:
    v_11657 = stack[-2];
    goto v_11501;
v_11527:
    goto v_11535;
v_11531:
    stack[0] = stack[-1];
    goto v_11532;
v_11533:
    v_11657 = stack[-4];
    v_11657 = qcar(v_11657);
    goto v_11546;
v_11542:
    v_11658 = stack[-3];
    goto v_11543;
v_11544:
    goto v_11545;
v_11546:
    goto v_11542;
v_11543:
    goto v_11544;
v_11545:
    v_11657 = CC_subsublis(elt(env, 0), v_11658, v_11657);
    env = stack[-5];
    v_11657 = ncons(v_11657);
    env = stack[-5];
    goto v_11534;
v_11535:
    goto v_11531;
v_11532:
    goto v_11533;
v_11534:
    v_11657 = Lrplacd(nil, stack[0], v_11657);
    env = stack[-5];
    v_11657 = stack[-1];
    v_11657 = qcdr(v_11657);
    stack[-1] = v_11657;
    goto v_11502;
v_11501:
    goto v_11437;
v_11494:
    goto v_11558;
v_11554:
    v_11657 = stack[0];
    v_11658 = qcar(v_11657);
    goto v_11555;
v_11556:
    v_11657 = elt(env, 4); // subfunc
    goto v_11557;
v_11558:
    goto v_11554;
v_11555:
    goto v_11556;
v_11557:
    v_11657 = get(v_11658, v_11657);
    env = stack[-5];
    v_11659 = v_11657;
    if (v_11657 == nil) goto v_11552;
    goto v_11569;
v_11563:
    goto v_11564;
v_11565:
    v_11658 = stack[-3];
    goto v_11566;
v_11567:
    v_11657 = stack[0];
    goto v_11568;
v_11569:
    goto v_11563;
v_11564:
    goto v_11565;
v_11566:
    goto v_11567;
v_11568:
        return Lapply2(nil, 3, v_11659, v_11658, v_11657);
v_11552:
    v_11657 = stack[0];
    v_11657 = qcar(v_11657);
    if (!symbolp(v_11657)) v_11657 = nil;
    else { v_11657 = qfastgets(v_11657);
           if (v_11657 != nil) { v_11657 = elt(v_11657, 8); // dname
#ifdef RECORD_GET
             if (v_11657 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_11657 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_11657 == SPID_NOPROP) v_11657 = nil; }}
#endif
    if (v_11657 == nil) goto v_11574;
    v_11657 = stack[0];
    goto v_11437;
v_11574:
    goto v_11585;
v_11581:
    v_11657 = stack[0];
    v_11658 = qcar(v_11657);
    goto v_11582;
v_11583:
    v_11657 = elt(env, 5); // !*sq
    goto v_11584;
v_11585:
    goto v_11581;
v_11582:
    goto v_11583;
v_11584:
    if (v_11658 == v_11657) goto v_11579;
    else goto v_11580;
v_11579:
    goto v_11594;
v_11590:
    stack[-1] = stack[-3];
    goto v_11591;
v_11592:
    v_11657 = stack[0];
    v_11657 = qcdr(v_11657);
    v_11657 = qcar(v_11657);
    fn = elt(env, 6); // prepsq
    v_11657 = (*qfn1(fn))(fn, v_11657);
    env = stack[-5];
    goto v_11593;
v_11594:
    goto v_11590;
v_11591:
    goto v_11592;
v_11593:
    stack[-3] = stack[-1];
    stack[0] = v_11657;
    goto v_11429;
v_11580:
    v_11657 = stack[0];
    stack[-4] = v_11657;
    v_11657 = stack[-4];
    if (v_11657 == nil) goto v_11611;
    else goto v_11612;
v_11611:
    v_11657 = nil;
    goto v_11606;
v_11612:
    v_11657 = stack[-4];
    v_11657 = qcar(v_11657);
    goto v_11624;
v_11620:
    v_11658 = stack[-3];
    goto v_11621;
v_11622:
    goto v_11623;
v_11624:
    goto v_11620;
v_11621:
    goto v_11622;
v_11623:
    v_11657 = CC_subsublis(elt(env, 0), v_11658, v_11657);
    env = stack[-5];
    v_11657 = ncons(v_11657);
    env = stack[-5];
    stack[-1] = v_11657;
    stack[-2] = v_11657;
v_11607:
    v_11657 = stack[-4];
    v_11657 = qcdr(v_11657);
    stack[-4] = v_11657;
    v_11657 = stack[-4];
    if (v_11657 == nil) goto v_11631;
    else goto v_11632;
v_11631:
    v_11657 = stack[-2];
    goto v_11606;
v_11632:
    goto v_11640;
v_11636:
    stack[0] = stack[-1];
    goto v_11637;
v_11638:
    v_11657 = stack[-4];
    v_11657 = qcar(v_11657);
    goto v_11651;
v_11647:
    v_11658 = stack[-3];
    goto v_11648;
v_11649:
    goto v_11650;
v_11651:
    goto v_11647;
v_11648:
    goto v_11649;
v_11650:
    v_11657 = CC_subsublis(elt(env, 0), v_11658, v_11657);
    env = stack[-5];
    v_11657 = ncons(v_11657);
    env = stack[-5];
    goto v_11639;
v_11640:
    goto v_11636;
v_11637:
    goto v_11638;
v_11639:
    v_11657 = Lrplacd(nil, stack[0], v_11657);
    env = stack[-5];
    v_11657 = stack[-1];
    v_11657 = qcdr(v_11657);
    stack[-1] = v_11657;
    goto v_11607;
v_11606:
    goto v_11437;
    v_11657 = nil;
v_11437:
    v_11659 = v_11657;
    v_11657 = v_11659;
    return onevalue(v_11657);
}



// Code for applyrd

static LispObject CC_applyrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11497, v_11498;
    LispObject fn;
    argcheck(nargs, 0, "applyrd");
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
    fn = elt(env, 6); // lex
    v_11497 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_11441;
v_11437:
    v_11498 = qvalue(elt(env, 1)); // atts
    goto v_11438;
v_11439:
    v_11497 = elt(env, 2); // (type definitionurl encoding)
    goto v_11440;
v_11441:
    goto v_11437;
v_11438:
    goto v_11439;
v_11440:
    fn = elt(env, 7); // retattributes
    v_11497 = (*qfn2(fn))(fn, v_11498, v_11497);
    env = stack[-1];
    qvalue(elt(env, 3)) = v_11497; // mmlatts
    goto v_11452;
v_11448:
    v_11497 = qvalue(elt(env, 4)); // char
    fn = elt(env, 8); // compress!*
    v_11498 = (*qfn1(fn))(fn, v_11497);
    env = stack[-1];
    goto v_11449;
v_11450:
    v_11497 = qvalue(elt(env, 5)); // functions!*
    goto v_11451;
v_11452:
    goto v_11448;
v_11449:
    goto v_11450;
v_11451:
    v_11497 = Lassoc(nil, v_11498, v_11497);
    stack[0] = v_11497;
    if (v_11497 == nil) goto v_11447;
    goto v_11462;
v_11458:
    v_11497 = stack[0];
    v_11497 = qcdr(v_11497);
    v_11498 = qcar(v_11497);
    goto v_11459;
v_11460:
    v_11497 = nil;
    goto v_11461;
v_11462:
    goto v_11458;
v_11459:
    goto v_11460;
v_11461:
    fn = elt(env, 9); // apply
    v_11497 = (*qfn2(fn))(fn, v_11498, v_11497);
    env = stack[-1];
    v_11498 = v_11497;
    goto v_11472;
v_11468:
    v_11497 = qvalue(elt(env, 3)); // mmlatts
    goto v_11469;
v_11470:
    goto v_11471;
v_11472:
    goto v_11468;
v_11469:
    goto v_11470;
v_11471:
    v_11497 = cons(v_11497, v_11498);
    env = stack[-1];
    v_11498 = v_11497;
    v_11497 = nil;
    qvalue(elt(env, 3)) = v_11497; // mmlatts
    goto v_11481;
v_11477:
    v_11497 = stack[0];
    v_11497 = qcdr(v_11497);
    v_11497 = qcdr(v_11497);
    v_11497 = qcar(v_11497);
    goto v_11478;
v_11479:
    goto v_11480;
v_11481:
    goto v_11477;
v_11478:
    goto v_11479;
v_11480:
    return cons(v_11497, v_11498);
v_11447:
    goto v_11493;
v_11489:
    v_11497 = qvalue(elt(env, 4)); // char
    v_11498 = Lcompress(nil, v_11497);
    env = stack[-1];
    goto v_11490;
v_11491:
    v_11497 = (LispObject)272+TAG_FIXNUM; // 17
    goto v_11492;
v_11493:
    goto v_11489;
v_11490:
    goto v_11491;
v_11492:
    fn = elt(env, 10); // errorml
    v_11497 = (*qfn2(fn))(fn, v_11498, v_11497);
    v_11497 = nil;
    return onevalue(v_11497);
}



// Code for ps!:minusp!:

static LispObject CC_psTminuspT(LispObject env,
                         LispObject v_11430)
{
    env = qenv(env);
    LispObject v_11433;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11433 = v_11430;
// end of prologue
    v_11433 = nil;
    return onevalue(v_11433);
}



// Code for arg2of2

static LispObject CC_arg2of2(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11434, v_11435;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11434 = v_11431;
    v_11435 = v_11430;
// end of prologue
    return onevalue(v_11434);
}



// Code for cut!:mt

static LispObject CC_cutTmt(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11540, v_11541;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11430,v_11431);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11431;
    stack[-2] = v_11430;
// end of prologue
    goto v_11450;
v_11446:
    v_11541 = stack[-2];
    goto v_11447;
v_11448:
    v_11540 = elt(env, 1); // !:rd!:
    goto v_11449;
v_11450:
    goto v_11446;
v_11447:
    goto v_11448;
v_11449:
    if (!consp(v_11541)) goto v_11444;
    v_11541 = qcar(v_11541);
    if (v_11541 == v_11540) goto v_11443;
    else goto v_11444;
v_11443:
    v_11540 = stack[-2];
    v_11540 = qcdr(v_11540);
    v_11540 = (consp(v_11540) ? nil : lisp_true);
    v_11540 = (v_11540 == nil ? lisp_true : nil);
    goto v_11442;
v_11444:
    v_11540 = nil;
    goto v_11442;
    v_11540 = nil;
v_11442:
    if (v_11540 == nil) goto v_11440;
    v_11540 = stack[-1];
    v_11540 = integerp(v_11540);
    if (v_11540 == nil) goto v_11462;
    else goto v_11463;
v_11462:
    v_11540 = nil;
    goto v_11461;
v_11463:
    goto v_11474;
v_11470:
    v_11541 = stack[-1];
    goto v_11471;
v_11472:
    v_11540 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11473;
v_11474:
    goto v_11470;
v_11471:
    goto v_11472;
v_11473:
    v_11540 = (LispObject)greaterp2(v_11541, v_11540);
    v_11540 = v_11540 ? lisp_true : nil;
    env = stack[-4];
    goto v_11461;
    v_11540 = nil;
v_11461:
    goto v_11438;
v_11440:
    v_11540 = nil;
    goto v_11438;
    v_11540 = nil;
v_11438:
    if (v_11540 == nil) goto v_11436;
    goto v_11489;
v_11485:
    goto v_11495;
v_11491:
    v_11540 = stack[-2];
    v_11540 = qcdr(v_11540);
    v_11540 = qcar(v_11540);
    v_11540 = Labsval(nil, v_11540);
    env = stack[-4];
    fn = elt(env, 2); // msd
    v_11541 = (*qfn1(fn))(fn, v_11540);
    env = stack[-4];
    goto v_11492;
v_11493:
    v_11540 = stack[-1];
    goto v_11494;
v_11495:
    goto v_11491;
v_11492:
    goto v_11493;
v_11494:
    v_11541 = difference2(v_11541, v_11540);
    env = stack[-4];
    stack[-1] = v_11541;
    goto v_11486;
v_11487:
    v_11540 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11488;
v_11489:
    goto v_11485;
v_11486:
    goto v_11487;
v_11488:
    v_11540 = (LispObject)lesseq2(v_11541, v_11540);
    v_11540 = v_11540 ? lisp_true : nil;
    env = stack[-4];
    if (v_11540 == nil) goto v_11483;
    v_11540 = stack[-2];
    goto v_11481;
v_11483:
    goto v_11513;
v_11507:
    stack[-3] = elt(env, 1); // !:rd!:
    goto v_11508;
v_11509:
    goto v_11520;
v_11516:
    v_11540 = stack[-2];
    v_11540 = qcdr(v_11540);
    stack[0] = qcar(v_11540);
    goto v_11517;
v_11518:
    v_11540 = stack[-1];
    v_11540 = negate(v_11540);
    env = stack[-4];
    goto v_11519;
v_11520:
    goto v_11516;
v_11517:
    goto v_11518;
v_11519:
    fn = elt(env, 3); // ashift
    stack[0] = (*qfn2(fn))(fn, stack[0], v_11540);
    env = stack[-4];
    goto v_11510;
v_11511:
    goto v_11531;
v_11527:
    v_11540 = stack[-2];
    v_11540 = qcdr(v_11540);
    v_11541 = qcdr(v_11540);
    goto v_11528;
v_11529:
    v_11540 = stack[-1];
    goto v_11530;
v_11531:
    goto v_11527;
v_11528:
    goto v_11529;
v_11530:
    v_11540 = plus2(v_11541, v_11540);
    goto v_11512;
v_11513:
    goto v_11507;
v_11508:
    goto v_11509;
v_11510:
    goto v_11511;
v_11512:
    {
        LispObject v_11546 = stack[-3];
        LispObject v_11547 = stack[0];
        return list2star(v_11546, v_11547, v_11540);
    }
    v_11540 = nil;
v_11481:
    goto v_11434;
v_11436:
    v_11540 = elt(env, 0); // cut!:mt
    {
        fn = elt(env, 4); // bflerrmsg
        return (*qfn1(fn))(fn, v_11540);
    }
    v_11540 = nil;
v_11434:
    return onevalue(v_11540);
}



// Code for contr2!-strand

static LispObject CC_contr2Kstrand(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11547, v_11548, v_11549, v_11550;
    LispObject fn;
    LispObject v_11433, v_11432, v_11431, v_11430;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "contr2-strand");
    va_start(aa, nargs);
    v_11430 = va_arg(aa, LispObject);
    v_11431 = va_arg(aa, LispObject);
    v_11432 = va_arg(aa, LispObject);
    v_11433 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_11433,v_11432,v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_11430,v_11431,v_11432,v_11433);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_11433;
    stack[-1] = v_11432;
    stack[-2] = v_11431;
    stack[-3] = v_11430;
// end of prologue
v_11429:
    v_11547 = stack[-3];
    if (v_11547 == nil) goto v_11437;
    else goto v_11438;
v_11437:
    v_11547 = stack[-1];
    goto v_11436;
v_11438:
    goto v_11448;
v_11444:
    v_11547 = stack[-3];
    v_11548 = qcar(v_11547);
    goto v_11445;
v_11446:
    v_11547 = stack[-2];
    goto v_11447;
v_11448:
    goto v_11444;
v_11445:
    goto v_11446;
v_11447:
    fn = elt(env, 1); // contrsp
    v_11547 = (*qfn2(fn))(fn, v_11548, v_11547);
    env = stack[-4];
    v_11549 = v_11547;
    v_11547 = v_11549;
    if (v_11547 == nil) goto v_11456;
    goto v_11466;
v_11462:
    v_11547 = v_11549;
    v_11548 = qcar(v_11547);
    goto v_11463;
v_11464:
    v_11547 = v_11549;
    v_11547 = qcdr(v_11547);
    goto v_11465;
v_11466:
    goto v_11462;
v_11463:
    goto v_11464;
v_11465:
    v_11547 = Lmember(nil, v_11548, v_11547);
    if (v_11547 == nil) goto v_11461;
    goto v_11477;
v_11473:
    v_11548 = stack[-3];
    goto v_11474;
v_11475:
    v_11547 = stack[-1];
    goto v_11476;
v_11477:
    goto v_11473;
v_11474:
    goto v_11475;
v_11476:
        return Lappend(nil, v_11548, v_11547);
v_11461:
    v_11547 = stack[0];
    if (v_11547 == nil) goto v_11480;
    else goto v_11481;
v_11480:
    goto v_11492;
v_11484:
    goto v_11500;
v_11494:
    goto v_11495;
v_11496:
    v_11547 = stack[-3];
    v_11548 = qcdr(v_11547);
    goto v_11497;
v_11498:
    v_11547 = stack[-1];
    goto v_11499;
v_11500:
    goto v_11494;
v_11495:
    goto v_11496;
v_11497:
    goto v_11498;
v_11499:
    fn = elt(env, 2); // contr2
    v_11550 = (*qfnn(fn))(fn, 3, v_11549, v_11548, v_11547);
    env = stack[-4];
    goto v_11485;
v_11486:
    v_11549 = stack[-2];
    goto v_11487;
v_11488:
    v_11548 = nil;
    goto v_11489;
v_11490:
    v_11547 = lisp_true;
    goto v_11491;
v_11492:
    goto v_11484;
v_11485:
    goto v_11486;
v_11487:
    goto v_11488;
v_11489:
    goto v_11490;
v_11491:
    stack[-3] = v_11550;
    stack[-2] = v_11549;
    stack[-1] = v_11548;
    stack[0] = v_11547;
    goto v_11429;
v_11481:
    goto v_11517;
v_11511:
    goto v_11512;
v_11513:
    v_11547 = stack[-3];
    v_11548 = qcdr(v_11547);
    goto v_11514;
v_11515:
    v_11547 = stack[-1];
    goto v_11516;
v_11517:
    goto v_11511;
v_11512:
    goto v_11513;
v_11514:
    goto v_11515;
v_11516:
    {
        fn = elt(env, 2); // contr2
        return (*qfnn(fn))(fn, 3, v_11549, v_11548, v_11547);
    }
    v_11547 = nil;
    goto v_11454;
v_11456:
    goto v_11533;
v_11525:
    v_11547 = stack[-3];
    stack[0] = qcdr(v_11547);
    goto v_11526;
v_11527:
    goto v_11528;
v_11529:
    goto v_11542;
v_11538:
    v_11547 = stack[-3];
    v_11548 = qcar(v_11547);
    goto v_11539;
v_11540:
    v_11547 = stack[-1];
    goto v_11541;
v_11542:
    goto v_11538;
v_11539:
    goto v_11540;
v_11541:
    v_11548 = cons(v_11548, v_11547);
    env = stack[-4];
    goto v_11530;
v_11531:
    v_11547 = nil;
    goto v_11532;
v_11533:
    goto v_11525;
v_11526:
    goto v_11527;
v_11528:
    goto v_11529;
v_11530:
    goto v_11531;
v_11532:
    stack[-3] = stack[0];
    stack[-1] = v_11548;
    stack[0] = v_11547;
    goto v_11429;
    v_11547 = nil;
v_11454:
    goto v_11436;
    v_11547 = nil;
v_11436:
    return onevalue(v_11547);
}



// Code for rnminusp!:

static LispObject CC_rnminuspT(LispObject env,
                         LispObject v_11430)
{
    env = qenv(env);
    LispObject v_11459, v_11460;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11459 = v_11430;
// end of prologue
    v_11459 = qcdr(v_11459);
    v_11460 = qcar(v_11459);
    v_11459 = v_11460;
    if (!consp(v_11460)) goto v_11434;
    else goto v_11435;
v_11434:
    goto v_11444;
v_11440:
    v_11460 = v_11459;
    goto v_11441;
v_11442:
    v_11459 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11443;
v_11444:
    goto v_11440;
v_11441:
    goto v_11442;
v_11443:
        return Llessp(nil, v_11460, v_11459);
v_11435:
    goto v_11454;
v_11450:
    v_11460 = v_11459;
    v_11460 = qcar(v_11460);
    if (!symbolp(v_11460)) v_11460 = nil;
    else { v_11460 = qfastgets(v_11460);
           if (v_11460 != nil) { v_11460 = elt(v_11460, 30); // minusp
#ifdef RECORD_GET
             if (v_11460 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v_11460 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v_11460 == SPID_NOPROP) v_11460 = nil; }}
#endif
    goto v_11451;
v_11452:
    goto v_11453;
v_11454:
    goto v_11450;
v_11451:
    goto v_11452;
v_11453:
        return Lapply1(nil, v_11460, v_11459);
    v_11459 = nil;
    return onevalue(v_11459);
}



// Code for qremd

static LispObject CC_qremd(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11566, v_11567;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11430,v_11431);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11431;
    stack[-2] = v_11430;
// end of prologue
    v_11566 = stack[-2];
    if (v_11566 == nil) goto v_11435;
    else goto v_11436;
v_11435:
    goto v_11443;
v_11439:
    v_11567 = stack[-2];
    goto v_11440;
v_11441:
    v_11566 = stack[-2];
    goto v_11442;
v_11443:
    goto v_11439;
v_11440:
    goto v_11441;
v_11442:
    return cons(v_11567, v_11566);
v_11436:
    goto v_11452;
v_11448:
    v_11567 = stack[-1];
    goto v_11449;
v_11450:
    v_11566 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11451;
v_11452:
    goto v_11448;
v_11449:
    goto v_11450;
v_11451:
    if (v_11567 == v_11566) goto v_11446;
    else goto v_11447;
v_11446:
    v_11566 = stack[-2];
    return ncons(v_11566);
v_11447:
    v_11566 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_11566)) v_11566 = nil;
    else { v_11566 = qfastgets(v_11566);
           if (v_11566 != nil) { v_11566 = elt(v_11566, 3); // field
#ifdef RECORD_GET
             if (v_11566 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_11566 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_11566 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_11566 == SPID_NOPROP) v_11566 = nil; else v_11566 = lisp_true; }}
#endif
    if (v_11566 == nil) goto v_11458;
    goto v_11467;
v_11463:
    v_11566 = stack[-1];
    fn = elt(env, 2); // !:recip
    v_11567 = (*qfn1(fn))(fn, v_11566);
    env = stack[-4];
    goto v_11464;
v_11465:
    v_11566 = stack[-2];
    goto v_11466;
v_11467:
    goto v_11463;
v_11464:
    goto v_11465;
v_11466:
    fn = elt(env, 3); // multd
    v_11566 = (*qfn2(fn))(fn, v_11567, v_11566);
    return ncons(v_11566);
v_11458:
    v_11566 = stack[-2];
    if (!consp(v_11566)) goto v_11475;
    else goto v_11476;
v_11475:
    v_11566 = lisp_true;
    goto v_11474;
v_11476:
    v_11566 = stack[-2];
    v_11566 = qcar(v_11566);
    v_11566 = (consp(v_11566) ? nil : lisp_true);
    goto v_11474;
    v_11566 = nil;
v_11474:
    if (v_11566 == nil) goto v_11472;
    goto v_11489;
v_11485:
    v_11567 = stack[-2];
    goto v_11486;
v_11487:
    v_11566 = stack[-1];
    goto v_11488;
v_11489:
    goto v_11485;
v_11486:
    goto v_11487;
v_11488:
    {
        fn = elt(env, 4); // !:divide
        return (*qfn2(fn))(fn, v_11567, v_11566);
    }
v_11472:
    goto v_11502;
v_11498:
    v_11566 = stack[-2];
    v_11566 = qcar(v_11566);
    v_11567 = qcdr(v_11566);
    goto v_11499;
v_11500:
    v_11566 = stack[-1];
    goto v_11501;
v_11502:
    goto v_11498;
v_11499:
    goto v_11500;
v_11501:
    fn = elt(env, 5); // qremf
    v_11566 = (*qfn2(fn))(fn, v_11567, v_11566);
    env = stack[-4];
    stack[-3] = v_11566;
    goto v_11512;
v_11508:
    goto v_11518;
v_11514:
    goto v_11524;
v_11520:
    goto v_11531;
v_11527:
    v_11566 = stack[-2];
    v_11566 = qcar(v_11566);
    v_11567 = qcar(v_11566);
    goto v_11528;
v_11529:
    v_11566 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11530;
v_11531:
    goto v_11527;
v_11528:
    goto v_11529;
v_11530:
    v_11566 = cons(v_11567, v_11566);
    env = stack[-4];
    v_11567 = ncons(v_11566);
    env = stack[-4];
    goto v_11521;
v_11522:
    v_11566 = stack[-3];
    v_11566 = qcar(v_11566);
    goto v_11523;
v_11524:
    goto v_11520;
v_11521:
    goto v_11522;
v_11523:
    fn = elt(env, 6); // multf
    stack[0] = (*qfn2(fn))(fn, v_11567, v_11566);
    env = stack[-4];
    goto v_11515;
v_11516:
    goto v_11543;
v_11539:
    goto v_11550;
v_11546:
    v_11566 = stack[-2];
    v_11566 = qcar(v_11566);
    v_11567 = qcar(v_11566);
    goto v_11547;
v_11548:
    v_11566 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11549;
v_11550:
    goto v_11546;
v_11547:
    goto v_11548;
v_11549:
    v_11566 = cons(v_11567, v_11566);
    env = stack[-4];
    v_11567 = ncons(v_11566);
    env = stack[-4];
    goto v_11540;
v_11541:
    v_11566 = stack[-3];
    v_11566 = qcdr(v_11566);
    goto v_11542;
v_11543:
    goto v_11539;
v_11540:
    goto v_11541;
v_11542:
    fn = elt(env, 6); // multf
    v_11566 = (*qfn2(fn))(fn, v_11567, v_11566);
    env = stack[-4];
    goto v_11517;
v_11518:
    goto v_11514;
v_11515:
    goto v_11516;
v_11517:
    stack[0] = cons(stack[0], v_11566);
    env = stack[-4];
    goto v_11509;
v_11510:
    goto v_11562;
v_11558:
    v_11566 = stack[-2];
    v_11567 = qcdr(v_11566);
    goto v_11559;
v_11560:
    v_11566 = stack[-1];
    goto v_11561;
v_11562:
    goto v_11558;
v_11559:
    goto v_11560;
v_11561:
    v_11566 = CC_qremd(elt(env, 0), v_11567, v_11566);
    env = stack[-4];
    goto v_11511;
v_11512:
    goto v_11508;
v_11509:
    goto v_11510;
v_11511:
    {
        LispObject v_11572 = stack[0];
        fn = elt(env, 7); // praddf
        return (*qfn2(fn))(fn, v_11572, v_11566);
    }
    goto v_11434;
    v_11566 = nil;
v_11434:
    return onevalue(v_11566);
}



// Code for reverse!-num

static LispObject CC_reverseKnum(LispObject env,
                         LispObject v_11430)
{
    env = qenv(env);
    LispObject v_11479, v_11480;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11430);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11430;
// end of prologue
    goto v_11440;
v_11436:
    v_11480 = stack[0];
    goto v_11437;
v_11438:
    v_11479 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11439;
v_11440:
    goto v_11436;
v_11437:
    goto v_11438;
v_11439:
    if (v_11480 == v_11479) goto v_11434;
    else goto v_11435;
v_11434:
    v_11479 = stack[0];
    goto v_11433;
v_11435:
    goto v_11451;
v_11447:
    v_11480 = stack[0];
    goto v_11448;
v_11449:
    v_11479 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11450;
v_11451:
    goto v_11447;
v_11448:
    goto v_11449;
v_11450:
    v_11479 = (LispObject)lessp2(v_11480, v_11479);
    v_11479 = v_11479 ? lisp_true : nil;
    env = stack[-2];
    if (v_11479 == nil) goto v_11445;
    goto v_11460;
v_11456:
    v_11479 = stack[0];
    stack[-1] = negate(v_11479);
    env = stack[-2];
    goto v_11457;
v_11458:
    v_11479 = stack[0];
    v_11479 = negate(v_11479);
    env = stack[-2];
    fn = elt(env, 1); // ilog2
    v_11479 = (*qfn1(fn))(fn, v_11479);
    env = stack[-2];
    v_11479 = add1(v_11479);
    env = stack[-2];
    goto v_11459;
v_11460:
    goto v_11456;
v_11457:
    goto v_11458;
v_11459:
    fn = elt(env, 2); // reverse!-num1
    v_11479 = (*qfn2(fn))(fn, stack[-1], v_11479);
    return negate(v_11479);
v_11445:
    goto v_11474;
v_11470:
    stack[-1] = stack[0];
    goto v_11471;
v_11472:
    v_11479 = stack[0];
    fn = elt(env, 1); // ilog2
    v_11479 = (*qfn1(fn))(fn, v_11479);
    env = stack[-2];
    v_11479 = add1(v_11479);
    env = stack[-2];
    goto v_11473;
v_11474:
    goto v_11470;
v_11471:
    goto v_11472;
v_11473:
    {
        LispObject v_11483 = stack[-1];
        fn = elt(env, 2); // reverse!-num1
        return (*qfn2(fn))(fn, v_11483, v_11479);
    }
    v_11479 = nil;
v_11433:
    return onevalue(v_11479);
}



// Code for quotient!-mod!-p

static LispObject CC_quotientKmodKp(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11582, v_11583, v_11584;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11430,v_11431);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11431;
    stack[-1] = v_11430;
// end of prologue
    v_11582 = stack[0];
    if (v_11582 == nil) goto v_11435;
    else goto v_11436;
v_11435:
    v_11582 = elt(env, 1); // "b=0 in quotient-mod-p"
    {
        fn = elt(env, 3); // errorf
        return (*qfn1(fn))(fn, v_11582);
    }
v_11436:
    v_11582 = stack[0];
    if (!consp(v_11582)) goto v_11444;
    else goto v_11445;
v_11444:
    v_11582 = lisp_true;
    goto v_11443;
v_11445:
    v_11582 = stack[0];
    v_11582 = qcar(v_11582);
    v_11582 = (consp(v_11582) ? nil : lisp_true);
    goto v_11443;
    v_11582 = nil;
v_11443:
    if (v_11582 == nil) goto v_11441;
    v_11582 = stack[0];
    fn = elt(env, 4); // safe!-modular!-reciprocal
    v_11582 = (*qfn1(fn))(fn, v_11582);
    env = stack[-3];
    v_11583 = v_11582;
    if (v_11583 == nil) goto v_11460;
    else goto v_11461;
v_11460:
    v_11582 = nil;
    qvalue(elt(env, 2)) = v_11582; // exact!-quotient!-flag
    goto v_11455;
v_11461:
    goto v_11471;
v_11467:
    v_11583 = stack[-1];
    goto v_11468;
v_11469:
    goto v_11470;
v_11471:
    goto v_11467;
v_11468:
    goto v_11469;
v_11470:
    {
        fn = elt(env, 5); // multiply!-by!-constant!-mod!-p
        return (*qfn2(fn))(fn, v_11583, v_11582);
    }
    v_11582 = nil;
v_11455:
    goto v_11434;
v_11441:
    v_11582 = stack[-1];
    if (v_11582 == nil) goto v_11474;
    else goto v_11475;
v_11474:
    v_11582 = nil;
    goto v_11434;
v_11475:
    v_11582 = stack[-1];
    if (!consp(v_11582)) goto v_11482;
    else goto v_11483;
v_11482:
    v_11582 = lisp_true;
    goto v_11481;
v_11483:
    v_11582 = stack[-1];
    v_11582 = qcar(v_11582);
    v_11582 = (consp(v_11582) ? nil : lisp_true);
    goto v_11481;
    v_11582 = nil;
v_11481:
    if (v_11582 == nil) goto v_11479;
    v_11582 = nil;
    qvalue(elt(env, 2)) = v_11582; // exact!-quotient!-flag
    goto v_11434;
v_11479:
    goto v_11498;
v_11494:
    v_11582 = stack[-1];
    v_11582 = qcar(v_11582);
    v_11582 = qcar(v_11582);
    v_11583 = qcar(v_11582);
    goto v_11495;
v_11496:
    v_11582 = stack[0];
    v_11582 = qcar(v_11582);
    v_11582 = qcar(v_11582);
    v_11582 = qcar(v_11582);
    goto v_11497;
v_11498:
    goto v_11494;
v_11495:
    goto v_11496;
v_11497:
    if (equal(v_11583, v_11582)) goto v_11492;
    else goto v_11493;
v_11492:
    goto v_11514;
v_11508:
    v_11584 = stack[-1];
    goto v_11509;
v_11510:
    v_11583 = stack[0];
    goto v_11511;
v_11512:
    v_11582 = stack[0];
    v_11582 = qcar(v_11582);
    v_11582 = qcar(v_11582);
    v_11582 = qcar(v_11582);
    goto v_11513;
v_11514:
    goto v_11508;
v_11509:
    goto v_11510;
v_11511:
    goto v_11512;
v_11513:
    {
        fn = elt(env, 6); // xquotient!-mod!-p
        return (*qfnn(fn))(fn, 3, v_11584, v_11583, v_11582);
    }
v_11493:
    goto v_11528;
v_11524:
    v_11582 = stack[-1];
    v_11582 = qcar(v_11582);
    v_11582 = qcar(v_11582);
    v_11583 = qcar(v_11582);
    goto v_11525;
v_11526:
    v_11582 = stack[0];
    v_11582 = qcar(v_11582);
    v_11582 = qcar(v_11582);
    v_11582 = qcar(v_11582);
    goto v_11527;
v_11528:
    goto v_11524;
v_11525:
    goto v_11526;
v_11527:
    fn = elt(env, 7); // ordop
    v_11582 = (*qfn2(fn))(fn, v_11583, v_11582);
    env = stack[-3];
    if (v_11582 == nil) goto v_11522;
    goto v_11542;
v_11538:
    v_11582 = stack[-1];
    v_11582 = qcar(v_11582);
    v_11583 = qcdr(v_11582);
    goto v_11539;
v_11540:
    v_11582 = stack[0];
    goto v_11541;
v_11542:
    goto v_11538;
v_11539:
    goto v_11540;
v_11541:
    stack[-2] = CC_quotientKmodKp(elt(env, 0), v_11583, v_11582);
    env = stack[-3];
    goto v_11552;
v_11548:
    v_11582 = stack[-1];
    v_11583 = qcdr(v_11582);
    goto v_11549;
v_11550:
    v_11582 = stack[0];
    goto v_11551;
v_11552:
    goto v_11548;
v_11549:
    goto v_11550;
v_11551:
    v_11582 = CC_quotientKmodKp(elt(env, 0), v_11583, v_11582);
    v_11583 = stack[-2];
    v_11584 = v_11583;
    if (v_11584 == nil) goto v_11560;
    else goto v_11561;
v_11560:
    goto v_11559;
v_11561:
    goto v_11573;
v_11567:
    v_11584 = stack[-1];
    v_11584 = qcar(v_11584);
    v_11584 = qcar(v_11584);
    goto v_11568;
v_11569:
    goto v_11570;
v_11571:
    goto v_11572;
v_11573:
    goto v_11567;
v_11568:
    goto v_11569;
v_11570:
    goto v_11571;
v_11572:
    return acons(v_11584, v_11583, v_11582);
    v_11582 = nil;
v_11559:
    goto v_11434;
v_11522:
    v_11582 = nil;
    qvalue(elt(env, 2)) = v_11582; // exact!-quotient!-flag
    goto v_11434;
    v_11582 = nil;
v_11434:
    return onevalue(v_11582);
}



// Code for lto_max1

static LispObject CC_lto_max1(LispObject env,
                         LispObject v_11430)
{
    env = qenv(env);
    LispObject v_11475, v_11476;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11430);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11430;
// end of prologue
    stack[-1] = nil;
v_11436:
    v_11475 = stack[0];
    v_11475 = qcdr(v_11475);
    if (v_11475 == nil) goto v_11441;
    else goto v_11442;
v_11441:
    goto v_11437;
v_11442:
    goto v_11450;
v_11446:
    v_11475 = stack[0];
    v_11476 = qcar(v_11475);
    goto v_11447;
v_11448:
    v_11475 = stack[-1];
    goto v_11449;
v_11450:
    goto v_11446;
v_11447:
    goto v_11448;
v_11449:
    v_11475 = cons(v_11476, v_11475);
    env = stack[-2];
    stack[-1] = v_11475;
    v_11475 = stack[0];
    v_11475 = qcdr(v_11475);
    stack[0] = v_11475;
    goto v_11436;
v_11437:
    v_11475 = stack[0];
    v_11475 = qcar(v_11475);
    v_11476 = v_11475;
v_11438:
    v_11475 = stack[-1];
    if (v_11475 == nil) goto v_11460;
    else goto v_11461;
v_11460:
    v_11475 = v_11476;
    goto v_11435;
v_11461:
    goto v_11469;
v_11465:
    v_11475 = stack[-1];
    v_11475 = qcar(v_11475);
    goto v_11466;
v_11467:
    goto v_11468;
v_11469:
    goto v_11465;
v_11466:
    goto v_11467;
v_11468:
    fn = elt(env, 1); // max
    v_11475 = (*qfn2(fn))(fn, v_11475, v_11476);
    env = stack[-2];
    v_11476 = v_11475;
    v_11475 = stack[-1];
    v_11475 = qcdr(v_11475);
    stack[-1] = v_11475;
    goto v_11438;
v_11435:
    return onevalue(v_11475);
}



// Code for mapins

static LispObject CC_mapins(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11470, v_11471, v_11472;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11430,v_11431);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11431;
    stack[-1] = v_11430;
// end of prologue
    stack[-2] = nil;
v_11436:
    v_11470 = stack[0];
    if (v_11470 == nil) goto v_11439;
    else goto v_11440;
v_11439:
    v_11470 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_11470);
    }
v_11440:
    goto v_11453;
v_11447:
    goto v_11459;
v_11455:
    v_11471 = stack[-1];
    goto v_11456;
v_11457:
    v_11470 = stack[0];
    v_11470 = qcar(v_11470);
    v_11470 = qcar(v_11470);
    goto v_11458;
v_11459:
    goto v_11455;
v_11456:
    goto v_11457;
v_11458:
    v_11472 = cons(v_11471, v_11470);
    env = stack[-3];
    goto v_11448;
v_11449:
    v_11470 = stack[0];
    v_11470 = qcar(v_11470);
    v_11471 = qcdr(v_11470);
    goto v_11450;
v_11451:
    v_11470 = stack[-2];
    goto v_11452;
v_11453:
    goto v_11447;
v_11448:
    goto v_11449;
v_11450:
    goto v_11451;
v_11452:
    v_11470 = acons(v_11472, v_11471, v_11470);
    env = stack[-3];
    stack[-2] = v_11470;
    v_11470 = stack[0];
    v_11470 = qcdr(v_11470);
    stack[0] = v_11470;
    goto v_11436;
    v_11470 = nil;
    return onevalue(v_11470);
}



// Code for ibalp_tvb

static LispObject CC_ibalp_tvb(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11481, v_11482;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11430,v_11431);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_11431;
    v_11481 = v_11430;
// end of prologue
    stack[-2] = v_11481;
v_11436:
    v_11481 = stack[-2];
    if (v_11481 == nil) goto v_11440;
    else goto v_11441;
v_11440:
    v_11481 = nil;
    goto v_11435;
v_11441:
    v_11481 = stack[-2];
    v_11481 = qcar(v_11481);
    stack[0] = v_11481;
    goto v_11456;
v_11452:
    v_11481 = stack[0];
    v_11481 = qcdr(v_11481);
    v_11481 = qcdr(v_11481);
    v_11481 = qcdr(v_11481);
    v_11481 = qcdr(v_11481);
    v_11481 = qcdr(v_11481);
    v_11481 = qcdr(v_11481);
    v_11481 = qcdr(v_11481);
    v_11482 = qcar(v_11481);
    goto v_11453;
v_11454:
    v_11481 = stack[-1];
    goto v_11455;
v_11456:
    goto v_11452;
v_11453:
    goto v_11454;
v_11455:
    v_11481 = (LispObject)geq2(v_11482, v_11481);
    v_11481 = v_11481 ? lisp_true : nil;
    env = stack[-3];
    if (v_11481 == nil) goto v_11450;
    goto v_11472;
v_11468:
    v_11481 = stack[0];
    v_11482 = qcdr(v_11481);
    goto v_11469;
v_11470:
    v_11481 = stack[0];
    v_11481 = qcdr(v_11481);
    v_11481 = qcdr(v_11481);
    v_11481 = qcar(v_11481);
    goto v_11471;
v_11472:
    goto v_11468;
v_11469:
    goto v_11470;
v_11471:
    fn = elt(env, 1); // ibalp_var!-unset
    v_11481 = (*qfn2(fn))(fn, v_11482, v_11481);
    env = stack[-3];
    goto v_11448;
v_11450:
v_11448:
    v_11481 = stack[-2];
    v_11481 = qcdr(v_11481);
    stack[-2] = v_11481;
    goto v_11436;
v_11435:
    return onevalue(v_11481);
}



// Code for aex_fvarl

static LispObject CC_aex_fvarl(LispObject env,
                         LispObject v_11430)
{
    env = qenv(env);
    LispObject v_11443;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11430);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11430;
// end of prologue
    goto v_11437;
v_11433:
    v_11443 = stack[0];
    fn = elt(env, 1); // aex_varl
    stack[-1] = (*qfn1(fn))(fn, v_11443);
    env = stack[-2];
    goto v_11434;
v_11435:
    v_11443 = stack[0];
    fn = elt(env, 2); // aex_ctx
    v_11443 = (*qfn1(fn))(fn, v_11443);
    env = stack[-2];
    fn = elt(env, 3); // ctx_idl
    v_11443 = (*qfn1(fn))(fn, v_11443);
    env = stack[-2];
    goto v_11436;
v_11437:
    goto v_11433;
v_11434:
    goto v_11435;
v_11436:
    {
        LispObject v_11446 = stack[-1];
        fn = elt(env, 4); // lto_setminus
        return (*qfn2(fn))(fn, v_11446, v_11443);
    }
}



// Code for make!-univariate!-image!-mod!-p

static LispObject CC_makeKunivariateKimageKmodKp(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11672, v_11673, v_11674;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11430,v_11431);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11431;
    stack[-2] = v_11430;
// end of prologue
    v_11672 = stack[-2];
    if (!consp(v_11672)) goto v_11443;
    else goto v_11444;
v_11443:
    v_11672 = lisp_true;
    goto v_11442;
v_11444:
    v_11672 = stack[-2];
    v_11672 = qcar(v_11672);
    v_11672 = (consp(v_11672) ? nil : lisp_true);
    goto v_11442;
    v_11672 = nil;
v_11442:
    if (v_11672 == nil) goto v_11440;
    v_11672 = stack[-2];
    if (v_11672 == nil) goto v_11454;
    else goto v_11455;
v_11454:
    v_11672 = nil;
    goto v_11436;
v_11455:
    v_11672 = stack[-2];
    v_11672 = Lmodular_number(nil, v_11672);
    env = stack[-4];
    {
        fn = elt(env, 1); // !*n2f
        return (*qfn1(fn))(fn, v_11672);
    }
    goto v_11438;
v_11440:
v_11438:
    goto v_11471;
v_11467:
    v_11672 = stack[-2];
    v_11672 = qcar(v_11672);
    v_11672 = qcar(v_11672);
    v_11673 = qcar(v_11672);
    goto v_11468;
v_11469:
    v_11672 = stack[-1];
    goto v_11470;
v_11471:
    goto v_11467;
v_11468:
    goto v_11469;
v_11470:
    if (equal(v_11673, v_11672)) goto v_11465;
    else goto v_11466;
v_11465:
    v_11672 = nil;
    stack[0] = v_11672;
v_11480:
    v_11672 = stack[-2];
    if (!consp(v_11672)) goto v_11491;
    else goto v_11492;
v_11491:
    v_11672 = lisp_true;
    goto v_11490;
v_11492:
    v_11672 = stack[-2];
    v_11672 = qcar(v_11672);
    v_11672 = (consp(v_11672) ? nil : lisp_true);
    goto v_11490;
    v_11672 = nil;
v_11490:
    if (v_11672 == nil) goto v_11487;
    else goto v_11488;
v_11487:
    goto v_11504;
v_11500:
    v_11672 = stack[-2];
    v_11672 = qcar(v_11672);
    v_11672 = qcar(v_11672);
    v_11673 = qcar(v_11672);
    goto v_11501;
v_11502:
    v_11672 = stack[-1];
    goto v_11503;
v_11504:
    goto v_11500;
v_11501:
    goto v_11502;
v_11503:
    v_11672 = (equal(v_11673, v_11672) ? lisp_true : nil);
    goto v_11486;
v_11488:
    v_11672 = nil;
    goto v_11486;
    v_11672 = nil;
v_11486:
    if (v_11672 == nil) goto v_11483;
    else goto v_11484;
v_11483:
    goto v_11479;
v_11484:
    goto v_11520;
v_11516:
    v_11672 = stack[-2];
    v_11672 = qcar(v_11672);
    v_11673 = qcdr(v_11672);
    goto v_11517;
v_11518:
    v_11672 = stack[-1];
    goto v_11519;
v_11520:
    goto v_11516;
v_11517:
    goto v_11518;
v_11519:
    v_11672 = CC_makeKunivariateKimageKmodKp(elt(env, 0), v_11673, v_11672);
    env = stack[-4];
    stack[-3] = v_11672;
    v_11672 = stack[-3];
    if (v_11672 == nil) goto v_11528;
    goto v_11537;
v_11531:
    v_11672 = stack[-2];
    v_11672 = qcar(v_11672);
    v_11674 = qcar(v_11672);
    goto v_11532;
v_11533:
    v_11673 = stack[-3];
    goto v_11534;
v_11535:
    v_11672 = stack[0];
    goto v_11536;
v_11537:
    goto v_11531;
v_11532:
    goto v_11533;
v_11534:
    goto v_11535;
v_11536:
    v_11672 = acons(v_11674, v_11673, v_11672);
    env = stack[-4];
    stack[0] = v_11672;
    goto v_11526;
v_11528:
v_11526:
    v_11672 = stack[-2];
    v_11672 = qcdr(v_11672);
    stack[-2] = v_11672;
    goto v_11480;
v_11479:
    goto v_11550;
v_11546:
    v_11673 = stack[-2];
    goto v_11547;
v_11548:
    v_11672 = stack[-1];
    goto v_11549;
v_11550:
    goto v_11546;
v_11547:
    goto v_11548;
v_11549:
    v_11672 = CC_makeKunivariateKimageKmodKp(elt(env, 0), v_11673, v_11672);
    env = stack[-4];
    stack[-2] = v_11672;
v_11556:
    v_11672 = stack[0];
    if (v_11672 == nil) goto v_11559;
    else goto v_11560;
v_11559:
    goto v_11555;
v_11560:
    v_11672 = stack[0];
    v_11672 = qcdr(v_11672);
    stack[-3] = v_11672;
    goto v_11570;
v_11566:
    v_11673 = stack[0];
    goto v_11567;
v_11568:
    v_11672 = stack[-2];
    goto v_11569;
v_11570:
    goto v_11566;
v_11567:
    goto v_11568;
v_11569:
    v_11672 = Lrplacd(nil, v_11673, v_11672);
    env = stack[-4];
    v_11672 = stack[0];
    stack[-2] = v_11672;
    v_11672 = stack[-3];
    stack[0] = v_11672;
    goto v_11556;
v_11555:
    v_11672 = stack[-2];
    goto v_11436;
v_11466:
    v_11672 = nil;
    stack[0] = v_11672;
v_11581:
    v_11672 = stack[-2];
    if (!consp(v_11672)) goto v_11592;
    else goto v_11593;
v_11592:
    v_11672 = lisp_true;
    goto v_11591;
v_11593:
    v_11672 = stack[-2];
    v_11672 = qcar(v_11672);
    v_11672 = (consp(v_11672) ? nil : lisp_true);
    goto v_11591;
    v_11672 = nil;
v_11591:
    if (v_11672 == nil) goto v_11588;
    else goto v_11589;
v_11588:
    goto v_11605;
v_11601:
    v_11672 = stack[-2];
    v_11672 = qcar(v_11672);
    v_11672 = qcar(v_11672);
    v_11673 = qcar(v_11672);
    goto v_11602;
v_11603:
    v_11672 = stack[-1];
    goto v_11604;
v_11605:
    goto v_11601;
v_11602:
    goto v_11603;
v_11604:
    v_11672 = (equal(v_11673, v_11672) ? lisp_true : nil);
    v_11672 = (v_11672 == nil ? lisp_true : nil);
    goto v_11587;
v_11589:
    v_11672 = nil;
    goto v_11587;
    v_11672 = nil;
v_11587:
    if (v_11672 == nil) goto v_11584;
    else goto v_11585;
v_11584:
    goto v_11580;
v_11585:
    goto v_11622;
v_11618:
    stack[-3] = stack[0];
    goto v_11619;
v_11620:
    goto v_11629;
v_11625:
    goto v_11635;
v_11631:
    v_11672 = stack[-2];
    v_11672 = qcar(v_11672);
    v_11672 = qcar(v_11672);
    v_11673 = qcar(v_11672);
    goto v_11632;
v_11633:
    v_11672 = stack[-2];
    v_11672 = qcar(v_11672);
    v_11672 = qcar(v_11672);
    v_11672 = qcdr(v_11672);
    goto v_11634;
v_11635:
    goto v_11631;
v_11632:
    goto v_11633;
v_11634:
    fn = elt(env, 2); // image!-of!-power
    stack[0] = (*qfn2(fn))(fn, v_11673, v_11672);
    env = stack[-4];
    goto v_11626;
v_11627:
    goto v_11649;
v_11645:
    v_11672 = stack[-2];
    v_11672 = qcar(v_11672);
    v_11673 = qcdr(v_11672);
    goto v_11646;
v_11647:
    v_11672 = stack[-1];
    goto v_11648;
v_11649:
    goto v_11645;
v_11646:
    goto v_11647;
v_11648:
    v_11672 = CC_makeKunivariateKimageKmodKp(elt(env, 0), v_11673, v_11672);
    env = stack[-4];
    goto v_11628;
v_11629:
    goto v_11625;
v_11626:
    goto v_11627;
v_11628:
    fn = elt(env, 3); // times!-mod!-p
    v_11672 = (*qfn2(fn))(fn, stack[0], v_11672);
    env = stack[-4];
    goto v_11621;
v_11622:
    goto v_11618;
v_11619:
    goto v_11620;
v_11621:
    fn = elt(env, 4); // plus!-mod!-p
    v_11672 = (*qfn2(fn))(fn, stack[-3], v_11672);
    env = stack[-4];
    stack[0] = v_11672;
    v_11672 = stack[-2];
    v_11672 = qcdr(v_11672);
    stack[-2] = v_11672;
    goto v_11581;
v_11580:
    goto v_11661;
v_11657:
    v_11673 = stack[-2];
    goto v_11658;
v_11659:
    v_11672 = stack[-1];
    goto v_11660;
v_11661:
    goto v_11657;
v_11658:
    goto v_11659;
v_11660:
    v_11672 = CC_makeKunivariateKimageKmodKp(elt(env, 0), v_11673, v_11672);
    env = stack[-4];
    stack[-2] = v_11672;
    goto v_11669;
v_11665:
    v_11673 = stack[0];
    goto v_11666;
v_11667:
    v_11672 = stack[-2];
    goto v_11668;
v_11669:
    goto v_11665;
v_11666:
    goto v_11667;
v_11668:
    {
        fn = elt(env, 4); // plus!-mod!-p
        return (*qfn2(fn))(fn, v_11673, v_11672);
    }
    v_11672 = nil;
v_11436:
    return onevalue(v_11672);
}



// Code for merge!-ind!-vars

static LispObject CC_mergeKindKvars(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11489, v_11490;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11430,v_11431);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11431;
    stack[-1] = v_11430;
// end of prologue
    v_11489 = qvalue(elt(env, 1)); // !*nocommutedf
    if (v_11489 == nil) goto v_11437;
    else goto v_11435;
v_11437:
    v_11489 = qvalue(elt(env, 2)); // !*commutedf
    if (v_11489 == nil) goto v_11442;
    else goto v_11443;
v_11442:
    goto v_11449;
v_11445:
    v_11489 = stack[-1];
    v_11489 = qcdr(v_11489);
    stack[-2] = qcar(v_11489);
    goto v_11446;
v_11447:
    goto v_11458;
v_11454:
    v_11490 = stack[0];
    goto v_11455;
v_11456:
    v_11489 = stack[-1];
    v_11489 = qcdr(v_11489);
    v_11489 = qcdr(v_11489);
    goto v_11457;
v_11458:
    goto v_11454;
v_11455:
    goto v_11456;
v_11457:
    v_11489 = cons(v_11490, v_11489);
    env = stack[-3];
    goto v_11448;
v_11449:
    goto v_11445;
v_11446:
    goto v_11447;
v_11448:
    v_11489 = Lmemq(nil, stack[-2], v_11489);
    goto v_11441;
v_11443:
    v_11489 = nil;
    goto v_11441;
    v_11489 = nil;
v_11441:
    if (v_11489 == nil) goto v_11439;
    else goto v_11435;
v_11439:
    goto v_11436;
v_11435:
    goto v_11472;
v_11468:
    v_11490 = stack[0];
    goto v_11469;
v_11470:
    v_11489 = stack[-1];
    v_11489 = qcdr(v_11489);
    v_11489 = qcdr(v_11489);
    goto v_11471;
v_11472:
    goto v_11468;
v_11469:
    goto v_11470;
v_11471:
    {
        fn = elt(env, 3); // derad!*
        return (*qfn2(fn))(fn, v_11490, v_11489);
    }
v_11436:
    goto v_11484;
v_11480:
    v_11490 = stack[0];
    goto v_11481;
v_11482:
    v_11489 = stack[-1];
    v_11489 = qcdr(v_11489);
    v_11489 = qcdr(v_11489);
    goto v_11483;
v_11484:
    goto v_11480;
v_11481:
    goto v_11482;
v_11483:
    {
        fn = elt(env, 4); // derad
        return (*qfn2(fn))(fn, v_11490, v_11489);
    }
    v_11489 = nil;
    return onevalue(v_11489);
}



// Code for testredzz

static LispObject CC_testredzz(LispObject env,
                         LispObject v_11430)
{
    env = qenv(env);
    LispObject v_11472, v_11473;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11430);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_11472 = v_11430;
// end of prologue
    goto v_11440;
v_11436:
    goto v_11445;
v_11441:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_11442;
v_11443:
    goto v_11452;
v_11448:
    v_11473 = qvalue(elt(env, 2)); // maxvar
    goto v_11449;
v_11450:
    goto v_11451;
v_11452:
    goto v_11448;
v_11449:
    goto v_11450;
v_11451:
    v_11472 = plus2(v_11473, v_11472);
    env = stack[-1];
    goto v_11444;
v_11445:
    goto v_11441;
v_11442:
    goto v_11443;
v_11444:
    v_11473 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_11472-TAG_FIXNUM)/(16/CELL)));
    goto v_11437;
v_11438:
    v_11472 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_11439;
v_11440:
    goto v_11436;
v_11437:
    goto v_11438;
v_11439:
    v_11472 = *(LispObject *)((char *)v_11473 + (CELL-TAG_VECTOR) + (((intptr_t)v_11472-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_11472;
v_11435:
    v_11472 = stack[0];
    if (v_11472 == nil) goto v_11460;
    else goto v_11461;
v_11460:
    v_11472 = nil;
    goto v_11434;
v_11461:
    v_11472 = stack[0];
    v_11472 = qcar(v_11472);
    v_11472 = qcar(v_11472);
    fn = elt(env, 3); // testredh
    v_11472 = (*qfn1(fn))(fn, v_11472);
    env = stack[-1];
    v_11472 = stack[0];
    v_11472 = qcdr(v_11472);
    stack[0] = v_11472;
    goto v_11435;
v_11434:
    return onevalue(v_11472);
}



// Code for indexvarordp

static LispObject CC_indexvarordp(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11548, v_11549;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11430,v_11431);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11431;
    stack[-1] = v_11430;
// end of prologue
    goto v_11445;
v_11441:
    v_11548 = stack[-1];
    v_11549 = qcar(v_11548);
    goto v_11442;
v_11443:
    v_11548 = stack[0];
    v_11548 = qcar(v_11548);
    goto v_11444;
v_11445:
    goto v_11441;
v_11442:
    goto v_11443;
v_11444:
    if (v_11549 == v_11548) goto v_11440;
    v_11548 = lisp_true;
    goto v_11438;
v_11440:
    goto v_11460;
v_11456:
    v_11549 = stack[-1];
    goto v_11457;
v_11458:
    v_11548 = qvalue(elt(env, 1)); // kord!*
    goto v_11459;
v_11460:
    goto v_11456;
v_11457:
    goto v_11458;
v_11459:
    v_11548 = Lmemq(nil, v_11549, v_11548);
    if (v_11548 == nil) goto v_11455;
    else goto v_11454;
v_11455:
    goto v_11468;
v_11464:
    v_11549 = stack[0];
    goto v_11465;
v_11466:
    v_11548 = qvalue(elt(env, 1)); // kord!*
    goto v_11467;
v_11468:
    goto v_11464;
v_11465:
    goto v_11466;
v_11467:
    v_11548 = Lmemq(nil, v_11549, v_11548);
v_11454:
    goto v_11438;
    v_11548 = nil;
v_11438:
    if (v_11548 == nil) goto v_11436;
    goto v_11477;
v_11473:
    v_11549 = stack[-1];
    goto v_11474;
v_11475:
    v_11548 = stack[0];
    goto v_11476;
v_11477:
    goto v_11473;
v_11474:
    goto v_11475;
v_11476:
    {
        fn = elt(env, 3); // ordop
        return (*qfn2(fn))(fn, v_11549, v_11548);
    }
v_11436:
    v_11548 = stack[-1];
    v_11548 = qcdr(v_11548);
    fn = elt(env, 4); // flatindxl
    stack[-2] = (*qfn1(fn))(fn, v_11548);
    env = stack[-3];
    v_11548 = stack[0];
    v_11548 = qcdr(v_11548);
    fn = elt(env, 4); // flatindxl
    v_11549 = (*qfn1(fn))(fn, v_11548);
    env = stack[-3];
    v_11548 = stack[-2];
    stack[-2] = v_11549;
    goto v_11499;
v_11495:
    v_11549 = v_11548;
    goto v_11496;
v_11497:
    v_11548 = qvalue(elt(env, 2)); // indxl!*
    goto v_11498;
v_11499:
    goto v_11495;
v_11496:
    goto v_11497;
v_11498:
    fn = elt(env, 5); // boundindp
    v_11548 = (*qfn2(fn))(fn, v_11549, v_11548);
    env = stack[-3];
    if (v_11548 == nil) goto v_11493;
    goto v_11511;
v_11507:
    v_11549 = stack[-2];
    goto v_11508;
v_11509:
    v_11548 = qvalue(elt(env, 2)); // indxl!*
    goto v_11510;
v_11511:
    goto v_11507;
v_11508:
    goto v_11509;
v_11510:
    fn = elt(env, 5); // boundindp
    v_11548 = (*qfn2(fn))(fn, v_11549, v_11548);
    env = stack[-3];
    if (v_11548 == nil) goto v_11505;
    goto v_11519;
v_11515:
    v_11548 = stack[-1];
    v_11549 = qcdr(v_11548);
    goto v_11516;
v_11517:
    v_11548 = stack[0];
    v_11548 = qcdr(v_11548);
    goto v_11518;
v_11519:
    goto v_11515;
v_11516:
    goto v_11517;
v_11518:
    {
        fn = elt(env, 6); // indordlp
        return (*qfn2(fn))(fn, v_11549, v_11548);
    }
v_11505:
    v_11548 = lisp_true;
    goto v_11503;
    v_11548 = nil;
v_11503:
    goto v_11491;
v_11493:
    goto v_11534;
v_11530:
    v_11549 = stack[-2];
    goto v_11531;
v_11532:
    v_11548 = qvalue(elt(env, 2)); // indxl!*
    goto v_11533;
v_11534:
    goto v_11530;
v_11531:
    goto v_11532;
v_11533:
    fn = elt(env, 5); // boundindp
    v_11548 = (*qfn2(fn))(fn, v_11549, v_11548);
    env = stack[-3];
    if (v_11548 == nil) goto v_11528;
    v_11548 = nil;
    goto v_11491;
v_11528:
    goto v_11545;
v_11541:
    v_11549 = stack[-1];
    goto v_11542;
v_11543:
    v_11548 = stack[0];
    goto v_11544;
v_11545:
    goto v_11541;
v_11542:
    goto v_11543;
v_11544:
    {
        fn = elt(env, 3); // ordop
        return (*qfn2(fn))(fn, v_11549, v_11548);
    }
    v_11548 = nil;
v_11491:
    goto v_11434;
    v_11548 = nil;
v_11434:
    return onevalue(v_11548);
}



// Code for inttovec!-solve

static LispObject CC_inttovecKsolve(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11532, v_11533;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11430,v_11431);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_11431;
    stack[-3] = v_11430;
// end of prologue
    goto v_11445;
v_11441:
    v_11533 = stack[-2];
    goto v_11442;
v_11443:
    v_11532 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11444;
v_11445:
    goto v_11441;
v_11442:
    goto v_11443;
v_11444:
    if (v_11533 == v_11532) goto v_11439;
    else goto v_11440;
v_11439:
    v_11532 = lisp_true;
    goto v_11438;
v_11440:
    goto v_11455;
v_11451:
    v_11533 = stack[-3];
    goto v_11452;
v_11453:
    v_11532 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11454;
v_11455:
    goto v_11451;
v_11452:
    goto v_11453;
v_11454:
    v_11532 = (v_11533 == v_11532 ? lisp_true : nil);
    goto v_11438;
    v_11532 = nil;
v_11438:
    if (v_11532 == nil) goto v_11436;
    goto v_11464;
v_11460:
    v_11533 = stack[-2];
    goto v_11461;
v_11462:
    v_11532 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11463;
v_11464:
    goto v_11460;
v_11461:
    goto v_11462;
v_11463:
    return cons(v_11533, v_11532);
v_11436:
    v_11532 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_11532;
    v_11532 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_11532;
v_11478:
    v_11532 = stack[0];
    stack[-1] = v_11532;
    v_11532 = stack[-4];
    v_11532 = add1(v_11532);
    env = stack[-5];
    stack[-4] = v_11532;
    goto v_11487;
v_11483:
    goto v_11493;
v_11489:
    goto v_11499;
v_11495:
    v_11533 = stack[-3];
    goto v_11496;
v_11497:
    v_11532 = stack[-4];
    goto v_11498;
v_11499:
    goto v_11495;
v_11496:
    goto v_11497;
v_11498:
    v_11533 = plus2(v_11533, v_11532);
    env = stack[-5];
    goto v_11490;
v_11491:
    v_11532 = stack[-1];
    goto v_11492;
v_11493:
    goto v_11489;
v_11490:
    goto v_11491;
v_11492:
    v_11533 = times2(v_11533, v_11532);
    env = stack[-5];
    goto v_11484;
v_11485:
    v_11532 = stack[-4];
    goto v_11486;
v_11487:
    goto v_11483;
v_11484:
    goto v_11485;
v_11486:
    v_11532 = quot2(v_11533, v_11532);
    env = stack[-5];
    stack[0] = v_11532;
    goto v_11514;
v_11510:
    v_11533 = stack[0];
    goto v_11511;
v_11512:
    v_11532 = stack[-2];
    goto v_11513;
v_11514:
    goto v_11510;
v_11511:
    goto v_11512;
v_11513:
    v_11532 = (LispObject)greaterp2(v_11533, v_11532);
    v_11532 = v_11532 ? lisp_true : nil;
    env = stack[-5];
    if (v_11532 == nil) goto v_11507;
    else goto v_11508;
v_11507:
    goto v_11478;
v_11508:
    goto v_11522;
v_11518:
    stack[0] = stack[-4];
    goto v_11519;
v_11520:
    goto v_11529;
v_11525:
    v_11533 = stack[-2];
    goto v_11526;
v_11527:
    v_11532 = stack[-1];
    goto v_11528;
v_11529:
    goto v_11525;
v_11526:
    goto v_11527;
v_11528:
    v_11532 = difference2(v_11533, v_11532);
    goto v_11521;
v_11522:
    goto v_11518;
v_11519:
    goto v_11520;
v_11521:
    {
        LispObject v_11539 = stack[0];
        return cons(v_11539, v_11532);
    }
    goto v_11434;
    v_11532 = nil;
v_11434:
    return onevalue(v_11532);
}



// Code for begin1a

static LispObject CC_begin1a(LispObject env,
                         LispObject v_11430)
{
    env = qenv(env);
    LispObject v_11793, v_11794, v_11795;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11430);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11430;
// end of prologue
    v_11793 = Ltime(nil, 0);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_11793; // otime!*
    v_11793 = elt(env, 2); // gctime
    fn = elt(env, 53); // getd
    v_11793 = (*qfn1(fn))(fn, v_11793);
    env = stack[-2];
    if (v_11793 == nil) goto v_11447;
    v_11793 = Lgctime(nil, 0);
    env = stack[-2];
    qvalue(elt(env, 3)) = v_11793; // ogctime!*
    goto v_11445;
v_11447:
    v_11793 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 3)) = v_11793; // ogctime!*
    goto v_11445;
v_11445:
    v_11793 = qvalue(elt(env, 1)); // otime!*
    qvalue(elt(env, 4)) = v_11793; // otime3!*
    qvalue(elt(env, 5)) = v_11793; // otime2!*
    qvalue(elt(env, 6)) = v_11793; // otime1!*
    v_11793 = qvalue(elt(env, 3)); // ogctime!*
    qvalue(elt(env, 7)) = v_11793; // ogctime3!*
    qvalue(elt(env, 8)) = v_11793; // ogctime2!*
    qvalue(elt(env, 9)) = v_11793; // ogctime1!*
    v_11793 = stack[0];
    qvalue(elt(env, 10)) = v_11793; // peekchar!*
    v_11793 = elt(env, 11); // !*semicol!*
    qvalue(elt(env, 12)) = v_11793; // cursym!*
    v_11793 = nil;
    qvalue(elt(env, 13)) = v_11793; // curescaped!*
v_11437:
    fn = elt(env, 54); // terminalp
    v_11793 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_11793 == nil) goto v_11462;
    v_11793 = qvalue(elt(env, 14)); // !*nosave!*
    if (v_11793 == nil) goto v_11468;
    else goto v_11466;
v_11468:
    goto v_11475;
v_11471:
    v_11794 = qvalue(elt(env, 15)); // statcounter
    goto v_11472;
v_11473:
    v_11793 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11474;
v_11475:
    goto v_11471;
v_11472:
    goto v_11473;
v_11474:
    if (v_11794 == v_11793) goto v_11466;
    goto v_11467;
v_11466:
    goto v_11465;
v_11467:
    fn = elt(env, 55); // add2buflis
    v_11793 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_11465;
v_11465:
    fn = elt(env, 56); // update_prompt
    v_11793 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_11460;
v_11462:
v_11460:
    v_11793 = nil;
    qvalue(elt(env, 14)) = v_11793; // !*nosave!*
    v_11793 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 16)) = v_11793; // !*strind
    v_11793 = nil;
    stack[-1] = v_11793;
    v_11793 = qvalue(elt(env, 17)); // !*time
    if (v_11793 == nil) goto v_11489;
    v_11793 = elt(env, 18); // (showtime nil)
    fn = elt(env, 57); // lispeval
    v_11793 = (*qfn1(fn))(fn, v_11793);
    env = stack[-2];
    goto v_11487;
v_11489:
v_11487:
    v_11793 = qvalue(elt(env, 19)); // !*output
    if (v_11793 == nil) goto v_11496;
    v_11793 = qvalue(elt(env, 20)); // ofl!*
    if (v_11793 == nil) goto v_11502;
    else goto v_11503;
v_11502:
    fn = elt(env, 54); // terminalp
    v_11793 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_11793 == nil) goto v_11507;
    else goto v_11508;
v_11507:
    v_11793 = nil;
    goto v_11506;
v_11508:
    v_11793 = qvalue(elt(env, 21)); // !*defn
    if (v_11793 == nil) goto v_11515;
    else goto v_11516;
v_11515:
    v_11793 = qvalue(elt(env, 22)); // !*lessspace
    v_11793 = (v_11793 == nil ? lisp_true : nil);
    goto v_11514;
v_11516:
    v_11793 = nil;
    goto v_11514;
    v_11793 = nil;
v_11514:
    goto v_11506;
    v_11793 = nil;
v_11506:
    goto v_11501;
v_11503:
    v_11793 = nil;
    goto v_11501;
    v_11793 = nil;
v_11501:
    if (v_11793 == nil) goto v_11496;
    v_11793 = Lterpri(nil, 0);
    env = stack[-2];
    goto v_11494;
v_11496:
v_11494:
    v_11793 = qvalue(elt(env, 23)); // tslin!*
    if (v_11793 == nil) goto v_11530;
    v_11793 = qvalue(elt(env, 23)); // tslin!*
    v_11793 = qcar(v_11793);
    qvalue(elt(env, 24)) = v_11793; // !*slin
    v_11793 = qvalue(elt(env, 23)); // tslin!*
    v_11793 = qcdr(v_11793);
    qvalue(elt(env, 25)) = v_11793; // lreadfn!*
    v_11793 = nil;
    qvalue(elt(env, 23)) = v_11793; // tslin!*
    goto v_11528;
v_11530:
v_11528:
    v_11793 = qvalue(elt(env, 26)); // initl!*
    stack[0] = v_11793;
v_11438:
    v_11793 = stack[0];
    if (v_11793 == nil) goto v_11541;
    v_11793 = stack[0];
    v_11793 = qcar(v_11793);
    fn = elt(env, 58); // sinitl
    v_11793 = (*qfn1(fn))(fn, v_11793);
    env = stack[-2];
    v_11793 = stack[0];
    v_11793 = qcdr(v_11793);
    stack[0] = v_11793;
    goto v_11438;
v_11541:
    goto v_11553;
v_11549:
    v_11794 = qvalue(elt(env, 27)); // forkeywords!*
    goto v_11550;
v_11551:
    v_11793 = elt(env, 28); // delim
    goto v_11552;
v_11553:
    goto v_11549;
v_11550:
    goto v_11551;
v_11552:
    v_11793 = Lremflag(nil, v_11794, v_11793);
    env = stack[-2];
    goto v_11561;
v_11557:
    v_11794 = qvalue(elt(env, 29)); // repeatkeywords!*
    goto v_11558;
v_11559:
    v_11793 = elt(env, 28); // delim
    goto v_11560;
v_11561:
    goto v_11557;
v_11558:
    goto v_11559;
v_11560:
    v_11793 = Lremflag(nil, v_11794, v_11793);
    env = stack[-2];
    goto v_11569;
v_11565:
    v_11794 = qvalue(elt(env, 30)); // whilekeywords!*
    goto v_11566;
v_11567:
    v_11793 = elt(env, 28); // delim
    goto v_11568;
v_11569:
    goto v_11565;
v_11566:
    goto v_11567;
v_11568:
    v_11793 = Lremflag(nil, v_11794, v_11793);
    env = stack[-2];
    v_11793 = qvalue(elt(env, 31)); // !*int
    if (v_11793 == nil) goto v_11575;
    v_11793 = nil;
    qvalue(elt(env, 32)) = v_11793; // erfg!*
    goto v_11573;
v_11575:
v_11573:
    goto v_11586;
v_11582:
    v_11794 = qvalue(elt(env, 12)); // cursym!*
    goto v_11583;
v_11584:
    v_11793 = elt(env, 33); // end
    goto v_11585;
v_11586:
    goto v_11582;
v_11583:
    goto v_11584;
v_11585:
    if (v_11794 == v_11793) goto v_11580;
    else goto v_11581;
v_11580:
    v_11793 = elt(env, 33); // end
    fn = elt(env, 59); // comm1
    v_11793 = (*qfn1(fn))(fn, v_11793);
    v_11793 = nil;
    goto v_11436;
v_11581:
    fn = elt(env, 54); // terminalp
    v_11793 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_11793 == nil) goto v_11593;
    goto v_11601;
v_11597:
    v_11794 = qvalue(elt(env, 34)); // key!*
    goto v_11598;
v_11599:
    v_11793 = elt(env, 35); // ed
    goto v_11600;
v_11601:
    goto v_11597;
v_11598:
    goto v_11599;
v_11600:
    if (v_11794 == v_11793) goto v_11593;
    v_11793 = qvalue(elt(env, 36)); // promptexp!*
    fn = elt(env, 60); // printprompt
    v_11793 = (*qfn1(fn))(fn, v_11793);
    env = stack[-2];
    goto v_11579;
v_11593:
v_11579:
    goto v_11611;
v_11607:
    v_11794 = elt(env, 37); // (command)
    goto v_11608;
v_11609:
    v_11793 = lisp_true;
    goto v_11610;
v_11611:
    goto v_11607;
v_11608:
    goto v_11609;
v_11610:
    fn = elt(env, 61); // errorset!*
    v_11793 = (*qfn2(fn))(fn, v_11794, v_11793);
    env = stack[-2];
    stack[0] = v_11793;
    fn = elt(env, 62); // condterpri
    v_11793 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_11793 = stack[0];
    fn = elt(env, 63); // errorp
    v_11793 = (*qfn1(fn))(fn, v_11793);
    env = stack[-2];
    if (v_11793 == nil) goto v_11618;
    goto v_11440;
v_11618:
    v_11793 = stack[0];
    v_11793 = qcar(v_11793);
    stack[0] = v_11793;
    goto v_11635;
v_11631:
    v_11793 = stack[0];
    v_11794 = qcar(v_11793);
    goto v_11632;
v_11633:
    v_11793 = elt(env, 38); // symbolic
    goto v_11634;
v_11635:
    goto v_11631;
v_11632:
    goto v_11633;
v_11634:
    if (v_11794 == v_11793) goto v_11629;
    else goto v_11630;
v_11629:
    goto v_11644;
v_11640:
    v_11793 = stack[0];
    v_11793 = qcdr(v_11793);
    v_11794 = qcar(v_11793);
    goto v_11641;
v_11642:
    v_11793 = elt(env, 39); // xmodule
    goto v_11643;
v_11644:
    goto v_11640;
v_11641:
    goto v_11642;
v_11643:
    v_11793 = Leqcar(nil, v_11794, v_11793);
    env = stack[-2];
    goto v_11628;
v_11630:
    v_11793 = nil;
    goto v_11628;
    v_11793 = nil;
v_11628:
    if (v_11793 == nil) goto v_11626;
    v_11793 = stack[0];
    v_11793 = qcdr(v_11793);
    v_11793 = qcar(v_11793);
    fn = elt(env, 64); // eval
    v_11793 = (*qfn1(fn))(fn, v_11793);
    env = stack[-2];
    fn = elt(env, 65); // xmodloop
    v_11793 = (*qfn1(fn))(fn, v_11793);
    env = stack[-2];
    v_11795 = v_11793;
    goto v_11624;
v_11626:
    v_11793 = stack[0];
    fn = elt(env, 66); // begin11
    v_11793 = (*qfn1(fn))(fn, v_11793);
    env = stack[-2];
    v_11795 = v_11793;
    goto v_11624;
v_11624:
    v_11793 = v_11795;
    if (v_11793 == nil) goto v_11663;
    else goto v_11664;
v_11663:
    goto v_11437;
v_11664:
    goto v_11672;
v_11668:
    v_11794 = v_11795;
    goto v_11669;
v_11670:
    v_11793 = elt(env, 33); // end
    goto v_11671;
v_11672:
    goto v_11668;
v_11669:
    goto v_11670;
v_11671:
    if (v_11794 == v_11793) goto v_11666;
    else goto v_11667;
v_11666:
    v_11793 = nil;
    goto v_11436;
v_11667:
    goto v_11682;
v_11678:
    v_11794 = v_11795;
    goto v_11679;
v_11680:
    v_11793 = elt(env, 40); // err2
    goto v_11681;
v_11682:
    goto v_11678;
v_11679:
    goto v_11680;
v_11681:
    if (v_11794 == v_11793) goto v_11676;
    else goto v_11677;
v_11676:
    goto v_11441;
v_11677:
    goto v_11691;
v_11687:
    v_11794 = v_11795;
    goto v_11688;
v_11689:
    v_11793 = elt(env, 41); // err3
    goto v_11690;
v_11691:
    goto v_11687;
v_11688:
    goto v_11689;
v_11690:
    if (v_11794 == v_11793) goto v_11685;
    else goto v_11686;
v_11685:
    goto v_11442;
v_11686:
v_11439:
    v_11793 = qvalue(elt(env, 42)); // crbuf1!*
    if (v_11793 == nil) goto v_11697;
    v_11793 = elt(env, 43); // "Closing object improperly removed. Redo edit."
    fn = elt(env, 67); // lprim
    v_11793 = (*qfn1(fn))(fn, v_11793);
    env = stack[-2];
    v_11793 = nil;
    qvalue(elt(env, 42)) = v_11793; // crbuf1!*
    v_11793 = nil;
    goto v_11436;
v_11697:
    goto v_11710;
v_11706:
    v_11794 = qvalue(elt(env, 44)); // eof!*
    goto v_11707;
v_11708:
    v_11793 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_11709;
v_11710:
    goto v_11706;
v_11707:
    goto v_11708;
v_11709:
    v_11793 = (LispObject)greaterp2(v_11794, v_11793);
    v_11793 = v_11793 ? lisp_true : nil;
    env = stack[-2];
    if (v_11793 == nil) goto v_11704;
    v_11793 = elt(env, 45); // "End-of-file read"
    fn = elt(env, 67); // lprim
    v_11793 = (*qfn1(fn))(fn, v_11793);
    env = stack[-2];
    v_11793 = elt(env, 46); // (bye)
    {
        fn = elt(env, 57); // lispeval
        return (*qfn1(fn))(fn, v_11793);
    }
v_11704:
    fn = elt(env, 54); // terminalp
    v_11793 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_11793 == nil) goto v_11718;
    v_11793 = nil;
    qvalue(elt(env, 47)) = v_11793; // crbuf!*
    v_11793 = lisp_true;
    qvalue(elt(env, 14)) = v_11793; // !*nosave!*
    goto v_11437;
v_11718:
    v_11793 = nil;
    goto v_11436;
v_11440:
    fn = elt(env, 68); // eofcheck
    v_11793 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_11793 == nil) goto v_11729;
    else goto v_11727;
v_11729:
    goto v_11737;
v_11733:
    v_11794 = qvalue(elt(env, 44)); // eof!*
    goto v_11734;
v_11735:
    v_11793 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11736;
v_11737:
    goto v_11733;
v_11734:
    goto v_11735;
v_11736:
    v_11793 = (LispObject)greaterp2(v_11794, v_11793);
    v_11793 = v_11793 ? lisp_true : nil;
    env = stack[-2];
    if (v_11793 == nil) goto v_11731;
    else goto v_11727;
v_11731:
    goto v_11728;
v_11727:
    goto v_11439;
v_11728:
    goto v_11746;
v_11742:
    v_11794 = stack[0];
    goto v_11743;
v_11744:
    v_11793 = elt(env, 48); // "BEGIN invalid"
    goto v_11745;
v_11746:
    goto v_11742;
v_11743:
    goto v_11744;
v_11745:
    if (equal(v_11794, v_11793)) goto v_11740;
    else goto v_11741;
v_11740:
    goto v_11437;
v_11741:
    v_11793 = lisp_true;
    stack[-1] = v_11793;
v_11441:
    fn = elt(env, 69); // resetparser
    v_11793 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
v_11442:
    v_11793 = lisp_true;
    qvalue(elt(env, 32)) = v_11793; // erfg!*
    v_11793 = qvalue(elt(env, 31)); // !*int
    if (v_11793 == nil) goto v_11758;
    else goto v_11759;
v_11758:
    v_11793 = qvalue(elt(env, 49)); // !*errcont
    v_11793 = (v_11793 == nil ? lisp_true : nil);
    goto v_11757;
v_11759:
    v_11793 = nil;
    goto v_11757;
    v_11793 = nil;
v_11757:
    if (v_11793 == nil) goto v_11755;
    v_11793 = lisp_true;
    qvalue(elt(env, 21)) = v_11793; // !*defn
    v_11793 = lisp_true;
    qvalue(elt(env, 50)) = v_11793; // !*echo
    v_11793 = qvalue(elt(env, 51)); // cmsg!*
    if (v_11793 == nil) goto v_11770;
    else goto v_11771;
v_11770:
    v_11793 = elt(env, 52); // "Continuing with parsing only ..."
    fn = elt(env, 70); // lprie
    v_11793 = (*qfn1(fn))(fn, v_11793);
    env = stack[-2];
    goto v_11769;
v_11771:
v_11769:
    v_11793 = lisp_true;
    qvalue(elt(env, 51)) = v_11793; // cmsg!*
    goto v_11753;
v_11755:
    v_11793 = qvalue(elt(env, 49)); // !*errcont
    if (v_11793 == nil) goto v_11776;
    else goto v_11777;
v_11776:
    v_11793 = stack[-1];
    fn = elt(env, 71); // pause1
    v_11793 = (*qfn1(fn))(fn, v_11793);
    env = stack[-2];
    v_11795 = v_11793;
    v_11793 = v_11795;
    if (v_11793 == nil) goto v_11784;
    v_11793 = v_11795;
    fn = elt(env, 57); // lispeval
    v_11793 = (*qfn1(fn))(fn, v_11793);
    v_11793 = (v_11793 == nil ? lisp_true : nil);
    goto v_11436;
v_11784:
    v_11793 = nil;
    qvalue(elt(env, 32)) = v_11793; // erfg!*
    goto v_11753;
v_11777:
    v_11793 = nil;
    qvalue(elt(env, 32)) = v_11793; // erfg!*
    goto v_11753;
v_11753:
    goto v_11437;
v_11436:
    return onevalue(v_11793);
}



// Code for bas_newnumber

static LispObject CC_bas_newnumber(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11442, v_11443;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11442 = v_11431;
    v_11443 = v_11430;
// end of prologue
    goto v_11438;
v_11434:
    goto v_11435;
v_11436:
    v_11442 = qcdr(v_11442);
    goto v_11437;
v_11438:
    goto v_11434;
v_11435:
    goto v_11436;
v_11437:
    return cons(v_11443, v_11442);
}



// Code for derivative!-mod!-p!-1

static LispObject CC_derivativeKmodKpK1(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11534, v_11535, v_11536;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11430,v_11431);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11431;
    stack[-2] = v_11430;
// end of prologue
    v_11534 = stack[-2];
    if (!consp(v_11534)) goto v_11439;
    else goto v_11440;
v_11439:
    v_11534 = lisp_true;
    goto v_11438;
v_11440:
    v_11534 = stack[-2];
    v_11534 = qcar(v_11534);
    v_11534 = (consp(v_11534) ? nil : lisp_true);
    goto v_11438;
    v_11534 = nil;
v_11438:
    if (v_11534 == nil) goto v_11436;
    v_11534 = nil;
    goto v_11434;
v_11436:
    goto v_11455;
v_11451:
    v_11534 = stack[-2];
    v_11534 = qcar(v_11534);
    v_11534 = qcar(v_11534);
    v_11535 = qcar(v_11534);
    goto v_11452;
v_11453:
    v_11534 = stack[-1];
    goto v_11454;
v_11455:
    goto v_11451;
v_11452:
    goto v_11453;
v_11454:
    if (equal(v_11535, v_11534)) goto v_11450;
    v_11534 = nil;
    goto v_11434;
v_11450:
    goto v_11468;
v_11464:
    v_11534 = stack[-2];
    v_11534 = qcar(v_11534);
    v_11534 = qcar(v_11534);
    v_11535 = qcdr(v_11534);
    goto v_11465;
v_11466:
    v_11534 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11467;
v_11468:
    goto v_11464;
v_11465:
    goto v_11466;
v_11467:
    if (v_11535 == v_11534) goto v_11462;
    else goto v_11463;
v_11462:
    v_11534 = stack[-2];
    v_11534 = qcar(v_11534);
    v_11534 = qcdr(v_11534);
    goto v_11434;
v_11463:
    goto v_11484;
v_11480:
    v_11534 = stack[-2];
    v_11534 = qcar(v_11534);
    v_11535 = qcdr(v_11534);
    goto v_11481;
v_11482:
    v_11534 = stack[-2];
    v_11534 = qcar(v_11534);
    v_11534 = qcar(v_11534);
    v_11534 = qcdr(v_11534);
    v_11534 = Lmodular_number(nil, v_11534);
    env = stack[-4];
    goto v_11483;
v_11484:
    goto v_11480;
v_11481:
    goto v_11482;
v_11483:
    fn = elt(env, 1); // multiply!-by!-constant!-mod!-p
    stack[0] = (*qfn2(fn))(fn, v_11535, v_11534);
    env = stack[-4];
    goto v_11498;
v_11494:
    v_11534 = stack[-2];
    v_11535 = qcdr(v_11534);
    goto v_11495;
v_11496:
    v_11534 = stack[-1];
    goto v_11497;
v_11498:
    goto v_11494;
v_11495:
    goto v_11496;
v_11497:
    v_11534 = CC_derivativeKmodKpK1(elt(env, 0), v_11535, v_11534);
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v_11534;
    v_11534 = stack[-3];
    if (v_11534 == nil) goto v_11506;
    else goto v_11507;
v_11506:
    v_11534 = stack[0];
    goto v_11505;
v_11507:
    goto v_11519;
v_11513:
    goto v_11525;
v_11521:
    v_11535 = stack[-1];
    goto v_11522;
v_11523:
    v_11534 = stack[-2];
    v_11534 = qcar(v_11534);
    v_11534 = qcar(v_11534);
    v_11534 = qcdr(v_11534);
    v_11534 = (LispObject)((intptr_t)(v_11534) - 0x10);
    goto v_11524;
v_11525:
    goto v_11521;
v_11522:
    goto v_11523;
v_11524:
    fn = elt(env, 2); // mksp
    v_11536 = (*qfn2(fn))(fn, v_11535, v_11534);
    goto v_11514;
v_11515:
    v_11535 = stack[-3];
    goto v_11516;
v_11517:
    v_11534 = stack[0];
    goto v_11518;
v_11519:
    goto v_11513;
v_11514:
    goto v_11515;
v_11516:
    goto v_11517;
v_11518:
    return acons(v_11536, v_11535, v_11534);
    v_11534 = nil;
v_11505:
    goto v_11434;
    v_11534 = nil;
v_11434:
    return onevalue(v_11534);
}



// Code for carrassoc

static LispObject CC_carrassoc(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11461, v_11462;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11430,v_11431);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11431;
    stack[-1] = v_11430;
// end of prologue
    goto v_11445;
v_11441:
    v_11462 = stack[-1];
    goto v_11442;
v_11443:
    v_11461 = stack[0];
    goto v_11444;
v_11445:
    goto v_11441;
v_11442:
    goto v_11443;
v_11444:
    fn = elt(env, 4); // rassoc
    v_11461 = (*qfn2(fn))(fn, v_11462, v_11461);
    env = stack[-2];
    v_11462 = v_11461;
    if (!consp(v_11461)) goto v_11439;
    v_11461 = v_11462;
    v_11461 = qcar(v_11461);
    goto v_11435;
v_11439:
    v_11461 = Lterpri(nil, 0);
    env = stack[-2];
    v_11461 = elt(env, 1); // "RASSOC trouble: "
    v_11461 = Lprinc(nil, v_11461);
    env = stack[-2];
    v_11461 = stack[-1];
    v_11461 = Lprin(nil, v_11461);
    env = stack[-2];
    v_11461 = elt(env, 2); // " "
    v_11461 = Lprinc(nil, v_11461);
    env = stack[-2];
    v_11461 = stack[0];
    v_11461 = Lprint(nil, v_11461);
    env = stack[-2];
    v_11461 = elt(env, 3); // "rassoc trouble"
    fn = elt(env, 5); // rederr
    v_11461 = (*qfn1(fn))(fn, v_11461);
    v_11461 = nil;
v_11435:
    return onevalue(v_11461);
}



// Code for simpqg

static LispObject CC_simpqg(LispObject env,
                         LispObject v_11430)
{
    env = qenv(env);
    LispObject v_11440, v_11441;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11440 = v_11430;
// end of prologue
    goto v_11437;
v_11433:
    v_11441 = v_11440;
    goto v_11434;
v_11435:
    v_11440 = elt(env, 1); // qg
    goto v_11436;
v_11437:
    goto v_11433;
v_11434:
    goto v_11435;
v_11436:
    {
        fn = elt(env, 2); // simpcv
        return (*qfn2(fn))(fn, v_11441, v_11440);
    }
}



// Code for mkprod

static LispObject CC_mkprod(LispObject env,
                         LispObject v_11430)
{
    env = qenv(env);
    LispObject v_11702, v_11703;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11430);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_11430;
// end of prologue
// Binding !*exp
// FLUIDBIND: reloadenv=6 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-6, 1, -2);
    qvalue(elt(env, 1)) = nil; // !*exp
// Binding !*sub2
// FLUIDBIND: reloadenv=6 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-6, 2, -1);
    qvalue(elt(env, 2)) = nil; // !*sub2
    v_11702 = stack[-4];
    if (v_11702 == nil) goto v_11446;
    else goto v_11447;
v_11446:
    v_11702 = lisp_true;
    goto v_11445;
v_11447:
    v_11702 = stack[-4];
    fn = elt(env, 8); // kernlp
    v_11702 = (*qfn1(fn))(fn, v_11702);
    env = stack[-6];
    goto v_11445;
    v_11702 = nil;
v_11445:
    if (v_11702 == nil) goto v_11443;
    v_11702 = stack[-4];
    goto v_11439;
v_11443:
    v_11702 = lisp_true;
    qvalue(elt(env, 2)) = v_11702; // !*sub2
    goto v_11462;
v_11458:
    v_11703 = stack[-4];
    goto v_11459;
v_11460:
    v_11702 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11461;
v_11462:
    goto v_11458;
v_11459:
    goto v_11460;
v_11461:
    v_11702 = cons(v_11703, v_11702);
    env = stack[-6];
    fn = elt(env, 9); // subs2
    v_11702 = (*qfn1(fn))(fn, v_11702);
    env = stack[-6];
    stack[0] = v_11702;
    goto v_11473;
v_11469:
    v_11702 = stack[0];
    v_11703 = qcdr(v_11702);
    goto v_11470;
v_11471:
    v_11702 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11472;
v_11473:
    goto v_11469;
v_11470:
    goto v_11471;
v_11472:
    if (v_11703 == v_11702) goto v_11468;
    v_11702 = stack[-4];
    goto v_11439;
v_11468:
    goto v_11484;
v_11480:
    v_11702 = stack[0];
    v_11703 = qcar(v_11702);
    goto v_11481;
v_11482:
    v_11702 = stack[-4];
    goto v_11483;
v_11484:
    goto v_11480;
v_11481:
    goto v_11482;
v_11483:
    if (equal(v_11703, v_11702)) goto v_11479;
    v_11702 = stack[0];
    v_11702 = qcar(v_11702);
    stack[-4] = v_11702;
    v_11702 = stack[-4];
    if (v_11702 == nil) goto v_11496;
    else goto v_11497;
v_11496:
    v_11702 = lisp_true;
    goto v_11495;
v_11497:
    v_11702 = stack[-4];
    fn = elt(env, 8); // kernlp
    v_11702 = (*qfn1(fn))(fn, v_11702);
    env = stack[-6];
    goto v_11495;
    v_11702 = nil;
v_11495:
    if (v_11702 == nil) goto v_11493;
    v_11702 = stack[-4];
    goto v_11439;
v_11493:
    goto v_11466;
v_11479:
v_11466:
    v_11702 = lisp_true;
    qvalue(elt(env, 1)) = v_11702; // !*exp
    v_11702 = stack[-4];
    fn = elt(env, 10); // ckrn
    v_11702 = (*qfn1(fn))(fn, v_11702);
    env = stack[-6];
    stack[-5] = v_11702;
    goto v_11513;
v_11509:
    v_11703 = stack[-4];
    goto v_11510;
v_11511:
    v_11702 = stack[-5];
    goto v_11512;
v_11513:
    goto v_11509;
v_11510:
    goto v_11511;
v_11512:
    fn = elt(env, 11); // quotf
    v_11702 = (*qfn2(fn))(fn, v_11703, v_11702);
    env = stack[-6];
    stack[-4] = v_11702;
    v_11702 = stack[-4];
    fn = elt(env, 12); // expnd
    v_11702 = (*qfn1(fn))(fn, v_11702);
    env = stack[-6];
    stack[0] = v_11702;
    v_11702 = stack[0];
    if (v_11702 == nil) goto v_11524;
    else goto v_11525;
v_11524:
    v_11702 = lisp_true;
    goto v_11523;
v_11525:
    v_11702 = stack[0];
    fn = elt(env, 8); // kernlp
    v_11702 = (*qfn1(fn))(fn, v_11702);
    env = stack[-6];
    goto v_11523;
    v_11702 = nil;
v_11523:
    if (v_11702 == nil) goto v_11521;
    goto v_11537;
v_11533:
    v_11703 = stack[-5];
    goto v_11534;
v_11535:
    v_11702 = stack[0];
    goto v_11536;
v_11537:
    goto v_11533;
v_11534:
    goto v_11535;
v_11536:
    fn = elt(env, 13); // multf
    v_11702 = (*qfn2(fn))(fn, v_11703, v_11702);
    goto v_11439;
v_11521:
    v_11702 = qvalue(elt(env, 3)); // !*mcd
    if (v_11702 == nil) goto v_11543;
    v_11702 = qvalue(elt(env, 4)); // !*sqfree
    if (v_11702 == nil) goto v_11547;
    else goto v_11546;
v_11547:
    v_11702 = qvalue(elt(env, 5)); // !*factor
    if (v_11702 == nil) goto v_11550;
    else goto v_11546;
v_11550:
    v_11702 = qvalue(elt(env, 6)); // !*gcd
    if (v_11702 == nil) goto v_11552;
    else goto v_11546;
v_11552:
    goto v_11543;
v_11546:
    v_11702 = stack[0];
    fn = elt(env, 14); // fctrf
    v_11702 = (*qfn1(fn))(fn, v_11702);
    env = stack[-6];
    stack[-3] = v_11702;
    goto v_11541;
v_11543:
    v_11702 = stack[0];
    fn = elt(env, 10); // ckrn
    v_11702 = (*qfn1(fn))(fn, v_11702);
    env = stack[-6];
    stack[-3] = v_11702;
    goto v_11565;
v_11561:
    v_11703 = stack[0];
    goto v_11562;
v_11563:
    v_11702 = stack[-3];
    goto v_11564;
v_11565:
    goto v_11561;
v_11562:
    goto v_11563;
v_11564:
    fn = elt(env, 11); // quotf
    v_11702 = (*qfn2(fn))(fn, v_11703, v_11702);
    env = stack[-6];
    stack[0] = v_11702;
    goto v_11573;
v_11569:
    goto v_11570;
v_11571:
    goto v_11580;
v_11576:
    v_11703 = stack[0];
    goto v_11577;
v_11578:
    v_11702 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11579;
v_11580:
    goto v_11576;
v_11577:
    goto v_11578;
v_11579:
    v_11702 = cons(v_11703, v_11702);
    env = stack[-6];
    goto v_11572;
v_11573:
    goto v_11569;
v_11570:
    goto v_11571;
v_11572:
    v_11702 = list2(stack[-3], v_11702);
    env = stack[-6];
    stack[-3] = v_11702;
    goto v_11541;
v_11541:
    goto v_11593;
v_11589:
    v_11702 = stack[-3];
    v_11702 = qcdr(v_11702);
    v_11702 = qcar(v_11702);
    v_11703 = qcdr(v_11702);
    goto v_11590;
v_11591:
    v_11702 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11592;
v_11593:
    goto v_11589;
v_11590:
    goto v_11591;
v_11592:
    v_11702 = (LispObject)greaterp2(v_11703, v_11702);
    v_11702 = v_11702 ? lisp_true : nil;
    env = stack[-6];
    if (v_11702 == nil) goto v_11587;
    else goto v_11585;
v_11587:
    v_11702 = stack[-3];
    v_11702 = qcdr(v_11702);
    v_11702 = qcdr(v_11702);
    if (v_11702 == nil) goto v_11599;
    else goto v_11585;
v_11599:
    goto v_11586;
v_11585:
    v_11702 = stack[-3];
    v_11702 = qcar(v_11702);
    stack[0] = v_11702;
    v_11702 = stack[-3];
    v_11702 = qcdr(v_11702);
    stack[-3] = v_11702;
v_11608:
    v_11702 = stack[-3];
    if (v_11702 == nil) goto v_11613;
    else goto v_11614;
v_11613:
    goto v_11607;
v_11614:
    v_11702 = stack[-3];
    v_11702 = qcar(v_11702);
    goto v_11625;
v_11621:
    goto v_11631;
v_11627:
    v_11703 = v_11702;
    v_11703 = qcar(v_11703);
    goto v_11628;
v_11629:
    v_11702 = qcdr(v_11702);
    goto v_11630;
v_11631:
    goto v_11627;
v_11628:
    goto v_11629;
v_11630:
    fn = elt(env, 15); // mksp!*
    v_11703 = (*qfn2(fn))(fn, v_11703, v_11702);
    env = stack[-6];
    goto v_11622;
v_11623:
    v_11702 = stack[0];
    goto v_11624;
v_11625:
    goto v_11621;
v_11622:
    goto v_11623;
v_11624:
    fn = elt(env, 13); // multf
    v_11702 = (*qfn2(fn))(fn, v_11703, v_11702);
    env = stack[-6];
    stack[0] = v_11702;
    v_11702 = stack[-3];
    v_11702 = qcdr(v_11702);
    stack[-3] = v_11702;
    goto v_11608;
v_11607:
    goto v_11584;
v_11586:
    v_11702 = qvalue(elt(env, 7)); // !*group
    if (v_11702 == nil) goto v_11643;
    else goto v_11644;
v_11643:
    goto v_11651;
v_11647:
    v_11702 = stack[-4];
    fn = elt(env, 16); // tmsf
    stack[0] = (*qfn1(fn))(fn, v_11702);
    env = stack[-6];
    goto v_11648;
v_11649:
    v_11702 = stack[-3];
    v_11702 = qcdr(v_11702);
    v_11702 = qcar(v_11702);
    v_11702 = qcar(v_11702);
    fn = elt(env, 16); // tmsf
    v_11702 = (*qfn1(fn))(fn, v_11702);
    env = stack[-6];
    goto v_11650;
v_11651:
    goto v_11647;
v_11648:
    goto v_11649;
v_11650:
    v_11702 = (LispObject)greaterp2(stack[0], v_11702);
    v_11702 = v_11702 ? lisp_true : nil;
    env = stack[-6];
    goto v_11642;
v_11644:
    v_11702 = nil;
    goto v_11642;
    v_11702 = nil;
v_11642:
    if (v_11702 == nil) goto v_11640;
    goto v_11667;
v_11663:
    goto v_11673;
v_11669:
    v_11702 = stack[-3];
    v_11702 = qcdr(v_11702);
    v_11702 = qcar(v_11702);
    v_11703 = qcar(v_11702);
    goto v_11670;
v_11671:
    v_11702 = stack[-3];
    v_11702 = qcdr(v_11702);
    v_11702 = qcar(v_11702);
    v_11702 = qcdr(v_11702);
    goto v_11672;
v_11673:
    goto v_11669;
v_11670:
    goto v_11671;
v_11672:
    fn = elt(env, 15); // mksp!*
    v_11703 = (*qfn2(fn))(fn, v_11703, v_11702);
    env = stack[-6];
    goto v_11664;
v_11665:
    v_11702 = stack[-3];
    v_11702 = qcar(v_11702);
    goto v_11666;
v_11667:
    goto v_11663;
v_11664:
    goto v_11665;
v_11666:
    fn = elt(env, 13); // multf
    v_11702 = (*qfn2(fn))(fn, v_11703, v_11702);
    env = stack[-6];
    stack[0] = v_11702;
    goto v_11584;
v_11640:
    goto v_11691;
v_11687:
    v_11703 = stack[-4];
    goto v_11688;
v_11689:
    v_11702 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11690;
v_11691:
    goto v_11687;
v_11688:
    goto v_11689;
v_11690:
    fn = elt(env, 15); // mksp!*
    v_11702 = (*qfn2(fn))(fn, v_11703, v_11702);
    env = stack[-6];
    stack[0] = v_11702;
    goto v_11584;
v_11584:
    goto v_11699;
v_11695:
    v_11703 = stack[-5];
    goto v_11696;
v_11697:
    v_11702 = stack[0];
    goto v_11698;
v_11699:
    goto v_11695;
v_11696:
    goto v_11697;
v_11698:
    fn = elt(env, 13); // multf
    v_11702 = (*qfn2(fn))(fn, v_11703, v_11702);
v_11439:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_11702);
}



// Code for cl_simpl1

static LispObject CC_cl_simpl1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12157, v_12158, v_12159, v_12160;
    LispObject fn;
    LispObject v_11433, v_11432, v_11431, v_11430;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_simpl1");
    va_start(aa, nargs);
    v_11430 = va_arg(aa, LispObject);
    v_11431 = va_arg(aa, LispObject);
    v_11432 = va_arg(aa, LispObject);
    v_11433 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_11433,v_11432,v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_11430,v_11431,v_11432,v_11433);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_11433;
    stack[-1] = v_11432;
    stack[-2] = v_11431;
    stack[-3] = v_11430;
// end of prologue
    goto v_11450;
v_11446:
    v_12158 = stack[-1];
    goto v_11447;
v_11448:
    v_12157 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11449;
v_11450:
    goto v_11446;
v_11447:
    goto v_11448;
v_11449:
    v_12157 = Leqn(nil, v_12158, v_12157);
    env = stack[-5];
    if (v_12157 == nil) goto v_11444;
    v_12157 = stack[-3];
    goto v_11440;
v_11444:
    v_12157 = stack[-3];
    if (!consp(v_12157)) goto v_11456;
    else goto v_11457;
v_11456:
    v_12157 = stack[-3];
    goto v_11455;
v_11457:
    v_12157 = stack[-3];
    v_12157 = qcar(v_12157);
    goto v_11455;
    v_12157 = nil;
v_11455:
    stack[-4] = v_12157;
    goto v_11476;
v_11472:
    v_12158 = stack[-4];
    goto v_11473;
v_11474:
    v_12157 = elt(env, 1); // true
    goto v_11475;
v_11476:
    goto v_11472;
v_11473:
    goto v_11474;
v_11475:
    if (v_12158 == v_12157) goto v_11470;
    else goto v_11471;
v_11470:
    v_12157 = lisp_true;
    goto v_11469;
v_11471:
    goto v_11486;
v_11482:
    v_12158 = stack[-4];
    goto v_11483;
v_11484:
    v_12157 = elt(env, 2); // false
    goto v_11485;
v_11486:
    goto v_11482;
v_11483:
    goto v_11484;
v_11485:
    v_12157 = (v_12158 == v_12157 ? lisp_true : nil);
    goto v_11469;
    v_12157 = nil;
v_11469:
    if (v_12157 == nil) goto v_11467;
    v_12157 = stack[-3];
    goto v_11440;
v_11467:
    goto v_11503;
v_11499:
    v_12158 = stack[-4];
    goto v_11500;
v_11501:
    v_12157 = elt(env, 3); // or
    goto v_11502;
v_11503:
    goto v_11499;
v_11500:
    goto v_11501;
v_11502:
    if (v_12158 == v_12157) goto v_11497;
    else goto v_11498;
v_11497:
    v_12157 = lisp_true;
    goto v_11496;
v_11498:
    goto v_11513;
v_11509:
    v_12158 = stack[-4];
    goto v_11510;
v_11511:
    v_12157 = elt(env, 4); // and
    goto v_11512;
v_11513:
    goto v_11509;
v_11510:
    goto v_11511;
v_11512:
    v_12157 = (v_12158 == v_12157 ? lisp_true : nil);
    goto v_11496;
    v_12157 = nil;
v_11496:
    if (v_12157 == nil) goto v_11494;
    goto v_11526;
v_11518:
    v_12160 = stack[-4];
    goto v_11519;
v_11520:
    v_12157 = stack[-3];
    v_12159 = qcdr(v_12157);
    goto v_11521;
v_11522:
    v_12158 = stack[-2];
    goto v_11523;
v_11524:
    v_12157 = stack[-1];
    goto v_11525;
v_11526:
    goto v_11518;
v_11519:
    goto v_11520;
v_11521:
    goto v_11522;
v_11523:
    goto v_11524;
v_11525:
    fn = elt(env, 16); // cl_smsimpl!-junct
    v_12157 = (*qfnn(fn))(fn, 4, v_12160, v_12159, v_12158, v_12157);
    env = stack[-5];
    v_12158 = v_12157;
    v_12157 = v_12158;
    if (v_12157 == nil) goto v_11536;
    v_12157 = v_12158;
    v_12157 = qcdr(v_12157);
    if (v_12157 == nil) goto v_11536;
    goto v_11547;
v_11543:
    v_12157 = stack[-4];
    goto v_11544;
v_11545:
    goto v_11546;
v_11547:
    goto v_11543;
v_11544:
    goto v_11545;
v_11546:
    return cons(v_12157, v_12158);
v_11536:
    v_12157 = v_12158;
    if (v_12157 == nil) goto v_11550;
    else goto v_11551;
v_11550:
    goto v_11561;
v_11557:
    v_12158 = stack[-4];
    goto v_11558;
v_11559:
    v_12157 = elt(env, 4); // and
    goto v_11560;
v_11561:
    goto v_11557;
v_11558:
    goto v_11559;
v_11560:
    if (v_12158 == v_12157) goto v_11555;
    else goto v_11556;
v_11555:
    v_12157 = elt(env, 1); // true
    goto v_11554;
v_11556:
    v_12157 = elt(env, 2); // false
    goto v_11554;
    v_12157 = nil;
v_11554:
    goto v_11534;
v_11551:
    v_12157 = v_12158;
    v_12157 = qcar(v_12157);
    goto v_11534;
    v_12157 = nil;
v_11534:
    goto v_11440;
v_11494:
    goto v_11580;
v_11576:
    v_12158 = stack[-4];
    goto v_11577;
v_11578:
    v_12157 = elt(env, 5); // not
    goto v_11579;
v_11580:
    goto v_11576;
v_11577:
    goto v_11578;
v_11579:
    if (v_12158 == v_12157) goto v_11574;
    else goto v_11575;
v_11574:
    goto v_11592;
v_11584:
    v_12157 = stack[-3];
    v_12157 = qcdr(v_12157);
    stack[0] = qcar(v_12157);
    goto v_11585;
v_11586:
    goto v_11587;
v_11588:
    v_12157 = stack[-1];
    v_12158 = sub1(v_12157);
    env = stack[-5];
    goto v_11589;
v_11590:
    v_12157 = elt(env, 5); // not
    goto v_11591;
v_11592:
    goto v_11584;
v_11585:
    goto v_11586;
v_11587:
    goto v_11588;
v_11589:
    goto v_11590;
v_11591:
    v_12157 = CC_cl_simpl1(elt(env, 0), 4, stack[0], stack[-2], v_12158, v_12157);
    env = stack[-5];
    stack[-1] = v_12157;
    goto v_11612;
v_11608:
    v_12158 = stack[-1];
    goto v_11609;
v_11610:
    v_12157 = elt(env, 1); // true
    goto v_11611;
v_11612:
    goto v_11608;
v_11609:
    goto v_11610;
v_11611:
    if (v_12158 == v_12157) goto v_11606;
    else goto v_11607;
v_11606:
    v_12157 = lisp_true;
    goto v_11605;
v_11607:
    goto v_11622;
v_11618:
    v_12158 = stack[-1];
    goto v_11619;
v_11620:
    v_12157 = elt(env, 2); // false
    goto v_11621;
v_11622:
    goto v_11618;
v_11619:
    goto v_11620;
v_11621:
    v_12157 = (v_12158 == v_12157 ? lisp_true : nil);
    goto v_11605;
    v_12157 = nil;
v_11605:
    if (v_12157 == nil) goto v_11603;
    v_12157 = stack[-1];
    {
        fn = elt(env, 17); // cl_flip
        return (*qfn1(fn))(fn, v_12157);
    }
v_11603:
    v_12157 = stack[-1];
    fn = elt(env, 18); // cl_atfp
    v_12157 = (*qfn1(fn))(fn, v_12157);
    env = stack[-5];
    if (v_12157 == nil) goto v_11631;
    v_12157 = stack[-1];
    {
        fn = elt(env, 19); // rl_negateat
        return (*qfn1(fn))(fn, v_12157);
    }
v_11631:
    v_12157 = stack[-1];
    {
        fn = elt(env, 20); // cl_negate!-invol
        return (*qfn1(fn))(fn, v_12157);
    }
v_11575:
    goto v_11650;
v_11646:
    v_12158 = stack[-4];
    goto v_11647;
v_11648:
    v_12157 = elt(env, 6); // ex
    goto v_11649;
v_11650:
    goto v_11646;
v_11647:
    goto v_11648;
v_11649:
    if (v_12158 == v_12157) goto v_11644;
    else goto v_11645;
v_11644:
    v_12157 = lisp_true;
    goto v_11643;
v_11645:
    goto v_11660;
v_11656:
    v_12158 = stack[-4];
    goto v_11657;
v_11658:
    v_12157 = elt(env, 7); // all
    goto v_11659;
v_11660:
    goto v_11656;
v_11657:
    goto v_11658;
v_11659:
    v_12157 = (v_12158 == v_12157 ? lisp_true : nil);
    goto v_11643;
    v_12157 = nil;
v_11643:
    if (v_12157 == nil) goto v_11641;
    v_12157 = qvalue(elt(env, 8)); // !*rlsism
    if (v_12157 == nil) goto v_11667;
    goto v_11674;
v_11670:
    v_12158 = stack[-2];
    goto v_11671;
v_11672:
    v_12157 = stack[-3];
    v_12157 = qcdr(v_12157);
    v_12157 = qcar(v_12157);
    goto v_11673;
v_11674:
    goto v_11670;
v_11671:
    goto v_11672;
v_11673:
    fn = elt(env, 21); // rl_smrmknowl
    v_12157 = (*qfn2(fn))(fn, v_12158, v_12157);
    env = stack[-5];
    stack[-2] = v_12157;
    goto v_11665;
v_11667:
v_11665:
    goto v_11688;
v_11680:
    v_12157 = stack[-3];
    v_12157 = qcdr(v_12157);
    v_12157 = qcdr(v_12157);
    stack[0] = qcar(v_12157);
    goto v_11681;
v_11682:
    goto v_11683;
v_11684:
    v_12157 = stack[-1];
    v_12158 = sub1(v_12157);
    env = stack[-5];
    goto v_11685;
v_11686:
    v_12157 = stack[-4];
    goto v_11687;
v_11688:
    goto v_11680;
v_11681:
    goto v_11682;
v_11683:
    goto v_11684;
v_11685:
    goto v_11686;
v_11687:
    v_12157 = CC_cl_simpl1(elt(env, 0), 4, stack[0], stack[-2], v_12158, v_12157);
    env = stack[-5];
    stack[-1] = v_12157;
    goto v_11709;
v_11705:
    v_12158 = stack[-1];
    goto v_11706;
v_11707:
    v_12157 = elt(env, 1); // true
    goto v_11708;
v_11709:
    goto v_11705;
v_11706:
    goto v_11707;
v_11708:
    if (v_12158 == v_12157) goto v_11703;
    else goto v_11704;
v_11703:
    v_12157 = lisp_true;
    goto v_11702;
v_11704:
    goto v_11719;
v_11715:
    v_12158 = stack[-1];
    goto v_11716;
v_11717:
    v_12157 = elt(env, 2); // false
    goto v_11718;
v_11719:
    goto v_11715;
v_11716:
    goto v_11717;
v_11718:
    v_12157 = (v_12158 == v_12157 ? lisp_true : nil);
    goto v_11702;
    v_12157 = nil;
v_11702:
    if (v_12157 == nil) goto v_11700;
    v_12157 = stack[-1];
    goto v_11440;
v_11700:
    goto v_11732;
v_11728:
    v_12157 = stack[-3];
    v_12157 = qcdr(v_12157);
    stack[0] = qcar(v_12157);
    goto v_11729;
v_11730:
    v_12157 = stack[-1];
    fn = elt(env, 22); // cl_fvarl
    v_12157 = (*qfn1(fn))(fn, v_12157);
    goto v_11731;
v_11732:
    goto v_11728;
v_11729:
    goto v_11730;
v_11731:
    v_12157 = Lmemq(nil, stack[0], v_12157);
    if (v_12157 == nil) goto v_11726;
    else goto v_11727;
v_11726:
    v_12157 = stack[-1];
    goto v_11440;
v_11727:
    goto v_11747;
v_11741:
    v_12159 = stack[-4];
    goto v_11742;
v_11743:
    v_12157 = stack[-3];
    v_12157 = qcdr(v_12157);
    v_12158 = qcar(v_12157);
    goto v_11744;
v_11745:
    v_12157 = stack[-1];
    goto v_11746;
v_11747:
    goto v_11741;
v_11742:
    goto v_11743;
v_11744:
    goto v_11745;
v_11746:
    return list3(v_12159, v_12158, v_12157);
v_11641:
    goto v_11765;
v_11761:
    v_12158 = stack[-4];
    goto v_11762;
v_11763:
    v_12157 = elt(env, 9); // bex
    goto v_11764;
v_11765:
    goto v_11761;
v_11762:
    goto v_11763;
v_11764:
    if (v_12158 == v_12157) goto v_11759;
    else goto v_11760;
v_11759:
    v_12157 = lisp_true;
    goto v_11758;
v_11760:
    goto v_11775;
v_11771:
    v_12158 = stack[-4];
    goto v_11772;
v_11773:
    v_12157 = elt(env, 10); // ball
    goto v_11774;
v_11775:
    goto v_11771;
v_11772:
    goto v_11773;
v_11774:
    v_12157 = (v_12158 == v_12157 ? lisp_true : nil);
    goto v_11758;
    v_12157 = nil;
v_11758:
    if (v_12157 == nil) goto v_11756;
    v_12157 = qvalue(elt(env, 8)); // !*rlsism
    if (v_12157 == nil) goto v_11782;
    goto v_11789;
v_11785:
    v_12158 = stack[-2];
    goto v_11786;
v_11787:
    v_12157 = stack[-3];
    v_12157 = qcdr(v_12157);
    v_12157 = qcar(v_12157);
    goto v_11788;
v_11789:
    goto v_11785;
v_11786:
    goto v_11787;
v_11788:
    fn = elt(env, 21); // rl_smrmknowl
    v_12157 = (*qfn2(fn))(fn, v_12158, v_12157);
    env = stack[-5];
    stack[-2] = v_12157;
    goto v_11780;
v_11782:
v_11780:
    goto v_11801;
v_11795:
    v_12159 = stack[-3];
    goto v_11796;
v_11797:
    v_12158 = stack[-2];
    goto v_11798;
v_11799:
    v_12157 = stack[-1];
    goto v_11800;
v_11801:
    goto v_11795;
v_11796:
    goto v_11797;
v_11798:
    goto v_11799;
v_11800:
    {
        fn = elt(env, 23); // cl_simplbq
        return (*qfnn(fn))(fn, 3, v_12159, v_12158, v_12157);
    }
v_11756:
    goto v_11813;
v_11809:
    v_12158 = stack[-4];
    goto v_11810;
v_11811:
    v_12157 = elt(env, 11); // impl
    goto v_11812;
v_11813:
    goto v_11809;
v_11810:
    goto v_11811;
v_11812:
    if (v_12158 == v_12157) goto v_11807;
    else goto v_11808;
v_11807:
    goto v_11825;
v_11817:
    v_12157 = stack[-3];
    v_12157 = qcdr(v_12157);
    v_12160 = qcar(v_12157);
    goto v_11818;
v_11819:
    v_12157 = stack[-3];
    v_12157 = qcdr(v_12157);
    v_12157 = qcdr(v_12157);
    v_12159 = qcar(v_12157);
    goto v_11820;
v_11821:
    v_12158 = stack[-2];
    goto v_11822;
v_11823:
    v_12157 = stack[-1];
    goto v_11824;
v_11825:
    goto v_11817;
v_11818:
    goto v_11819;
v_11820:
    goto v_11821;
v_11822:
    goto v_11823;
v_11824:
    {
        fn = elt(env, 24); // cl_smsimpl!-imprep
        return (*qfnn(fn))(fn, 4, v_12160, v_12159, v_12158, v_12157);
    }
v_11808:
    goto v_11843;
v_11839:
    v_12158 = stack[-4];
    goto v_11840;
v_11841:
    v_12157 = elt(env, 12); // repl
    goto v_11842;
v_11843:
    goto v_11839;
v_11840:
    goto v_11841;
v_11842:
    if (v_12158 == v_12157) goto v_11837;
    else goto v_11838;
v_11837:
    goto v_11855;
v_11847:
    v_12157 = stack[-3];
    v_12157 = qcdr(v_12157);
    v_12157 = qcdr(v_12157);
    v_12160 = qcar(v_12157);
    goto v_11848;
v_11849:
    v_12157 = stack[-3];
    v_12157 = qcdr(v_12157);
    v_12159 = qcar(v_12157);
    goto v_11850;
v_11851:
    v_12158 = stack[-2];
    goto v_11852;
v_11853:
    v_12157 = stack[-1];
    goto v_11854;
v_11855:
    goto v_11847;
v_11848:
    goto v_11849;
v_11850:
    goto v_11851;
v_11852:
    goto v_11853;
v_11854:
    {
        fn = elt(env, 24); // cl_smsimpl!-imprep
        return (*qfnn(fn))(fn, 4, v_12160, v_12159, v_12158, v_12157);
    }
v_11838:
    goto v_11873;
v_11869:
    v_12158 = stack[-4];
    goto v_11870;
v_11871:
    v_12157 = elt(env, 13); // equiv
    goto v_11872;
v_11873:
    goto v_11869;
v_11870:
    goto v_11871;
v_11872:
    if (v_12158 == v_12157) goto v_11867;
    else goto v_11868;
v_11867:
    goto v_11885;
v_11877:
    v_12157 = stack[-3];
    v_12157 = qcdr(v_12157);
    v_12160 = qcar(v_12157);
    goto v_11878;
v_11879:
    v_12157 = stack[-3];
    v_12157 = qcdr(v_12157);
    v_12157 = qcdr(v_12157);
    v_12159 = qcar(v_12157);
    goto v_11880;
v_11881:
    v_12158 = stack[-2];
    goto v_11882;
v_11883:
    v_12157 = stack[-1];
    goto v_11884;
v_11885:
    goto v_11877;
v_11878:
    goto v_11879;
v_11880:
    goto v_11881;
v_11882:
    goto v_11883;
v_11884:
    {
        fn = elt(env, 25); // cl_smsimpl!-equiv
        return (*qfnn(fn))(fn, 4, v_12160, v_12159, v_12158, v_12157);
    }
v_11868:
    goto v_11904;
v_11900:
    v_12158 = stack[-4];
    goto v_11901;
v_11902:
    v_12157 = elt(env, 14); // cl_simpl
    goto v_11903;
v_11904:
    goto v_11900;
v_11901:
    goto v_11902;
v_11903:
    fn = elt(env, 26); // rl_external
    v_12157 = (*qfn2(fn))(fn, v_12158, v_12157);
    env = stack[-5];
    v_12158 = v_12157;
    if (v_12157 == nil) goto v_11898;
    goto v_11912;
v_11908:
    stack[0] = v_12158;
    goto v_11909;
v_11910:
    v_12157 = stack[-3];
    v_12157 = ncons(v_12157);
    env = stack[-5];
    goto v_11911;
v_11912:
    goto v_11908;
v_11909:
    goto v_11910;
v_11911:
    {
        LispObject v_12166 = stack[0];
        fn = elt(env, 27); // apply
        return (*qfn2(fn))(fn, v_12166, v_12157);
    }
v_11898:
    goto v_11921;
v_11917:
    v_12158 = stack[-3];
    goto v_11918;
v_11919:
    v_12157 = stack[0];
    goto v_11920;
v_11921:
    goto v_11917;
v_11918:
    goto v_11919;
v_11920:
    fn = elt(env, 28); // cl_simplat
    v_12157 = (*qfn2(fn))(fn, v_12158, v_12157);
    env = stack[-5];
    v_12158 = v_12157;
    v_12157 = qvalue(elt(env, 8)); // !*rlsism
    if (v_12157 == nil) goto v_11927;
    v_12157 = v_12158;
    if (!consp(v_12157)) goto v_11931;
    else goto v_11932;
v_11931:
    v_12157 = v_12158;
    goto v_11930;
v_11932:
    v_12157 = v_12158;
    v_12157 = qcar(v_12157);
    goto v_11930;
    v_12157 = nil;
v_11930:
    stack[-4] = v_12157;
    goto v_11951;
v_11947:
    v_12159 = stack[-4];
    goto v_11948;
v_11949:
    v_12157 = elt(env, 3); // or
    goto v_11950;
v_11951:
    goto v_11947;
v_11948:
    goto v_11949;
v_11950:
    if (v_12159 == v_12157) goto v_11945;
    else goto v_11946;
v_11945:
    v_12157 = lisp_true;
    goto v_11944;
v_11946:
    goto v_11961;
v_11957:
    v_12159 = stack[-4];
    goto v_11958;
v_11959:
    v_12157 = elt(env, 4); // and
    goto v_11960;
v_11961:
    goto v_11957;
v_11958:
    goto v_11959;
v_11960:
    v_12157 = (v_12159 == v_12157 ? lisp_true : nil);
    goto v_11944;
    v_12157 = nil;
v_11944:
    if (v_12157 == nil) goto v_11942;
    goto v_11974;
v_11966:
    v_12160 = stack[-4];
    goto v_11967;
v_11968:
    v_12157 = v_12158;
    v_12159 = qcdr(v_12157);
    goto v_11969;
v_11970:
    v_12158 = stack[-2];
    goto v_11971;
v_11972:
    v_12157 = stack[-1];
    goto v_11973;
v_11974:
    goto v_11966;
v_11967:
    goto v_11968;
v_11969:
    goto v_11970;
v_11971:
    goto v_11972;
v_11973:
    fn = elt(env, 16); // cl_smsimpl!-junct
    v_12157 = (*qfnn(fn))(fn, 4, v_12160, v_12159, v_12158, v_12157);
    env = stack[-5];
    v_12158 = v_12157;
    v_12157 = v_12158;
    if (v_12157 == nil) goto v_11984;
    v_12157 = v_12158;
    v_12157 = qcdr(v_12157);
    if (v_12157 == nil) goto v_11984;
    goto v_11995;
v_11991:
    v_12157 = stack[-4];
    goto v_11992;
v_11993:
    goto v_11994;
v_11995:
    goto v_11991;
v_11992:
    goto v_11993;
v_11994:
    return cons(v_12157, v_12158);
v_11984:
    v_12157 = v_12158;
    if (v_12157 == nil) goto v_11998;
    else goto v_11999;
v_11998:
    goto v_12009;
v_12005:
    v_12158 = stack[-4];
    goto v_12006;
v_12007:
    v_12157 = elt(env, 4); // and
    goto v_12008;
v_12009:
    goto v_12005;
v_12006:
    goto v_12007;
v_12008:
    if (v_12158 == v_12157) goto v_12003;
    else goto v_12004;
v_12003:
    v_12157 = elt(env, 1); // true
    goto v_12002;
v_12004:
    v_12157 = elt(env, 2); // false
    goto v_12002;
    v_12157 = nil;
v_12002:
    goto v_11982;
v_11999:
    v_12157 = v_12158;
    v_12157 = qcar(v_12157);
    goto v_11982;
    v_12157 = nil;
v_11982:
    goto v_11440;
v_11942:
    goto v_12032;
v_12028:
    v_12159 = stack[-4];
    goto v_12029;
v_12030:
    v_12157 = elt(env, 1); // true
    goto v_12031;
v_12032:
    goto v_12028;
v_12029:
    goto v_12030;
v_12031:
    if (v_12159 == v_12157) goto v_12026;
    else goto v_12027;
v_12026:
    v_12157 = lisp_true;
    goto v_12025;
v_12027:
    goto v_12042;
v_12038:
    v_12159 = stack[-4];
    goto v_12039;
v_12040:
    v_12157 = elt(env, 2); // false
    goto v_12041;
v_12042:
    goto v_12038;
v_12039:
    goto v_12040;
v_12041:
    v_12157 = (v_12159 == v_12157 ? lisp_true : nil);
    goto v_12025;
    v_12157 = nil;
v_12025:
    if (v_12157 == nil) goto v_12023;
    v_12157 = v_12158;
    goto v_11440;
v_12023:
    goto v_12056;
v_12048:
    stack[-3] = elt(env, 4); // and
    goto v_12049;
v_12050:
    v_12157 = v_12158;
    stack[0] = ncons(v_12157);
    env = stack[-5];
    goto v_12051;
v_12052:
    v_12157 = stack[-2];
    fn = elt(env, 29); // rl_smcpknowl
    v_12158 = (*qfn1(fn))(fn, v_12157);
    env = stack[-5];
    goto v_12053;
v_12054:
    v_12157 = stack[-1];
    goto v_12055;
v_12056:
    goto v_12048;
v_12049:
    goto v_12050;
v_12051:
    goto v_12052;
v_12053:
    goto v_12054;
v_12055:
    fn = elt(env, 30); // rl_smupdknowl
    v_12157 = (*qfnn(fn))(fn, 4, stack[-3], stack[0], v_12158, v_12157);
    env = stack[-5];
    goto v_12071;
v_12067:
    v_12159 = v_12157;
    goto v_12068;
v_12069:
    v_12158 = elt(env, 2); // false
    goto v_12070;
v_12071:
    goto v_12067;
v_12068:
    goto v_12069;
v_12070:
    if (v_12159 == v_12158) goto v_12065;
    else goto v_12066;
v_12065:
    v_12157 = elt(env, 2); // false
    goto v_11440;
v_12066:
    goto v_12084;
v_12076:
    v_12160 = elt(env, 4); // and
    goto v_12077;
v_12078:
    v_12159 = stack[-2];
    goto v_12079;
v_12080:
    v_12158 = v_12157;
    goto v_12081;
v_12082:
    v_12157 = stack[-1];
    goto v_12083;
v_12084:
    goto v_12076;
v_12077:
    goto v_12078;
v_12079:
    goto v_12080;
v_12081:
    goto v_12082;
v_12083:
    fn = elt(env, 31); // rl_smmkatl
    v_12157 = (*qfnn(fn))(fn, 4, v_12160, v_12159, v_12158, v_12157);
    env = stack[-5];
    v_12158 = v_12157;
    goto v_12097;
v_12093:
    v_12159 = v_12158;
    goto v_12094;
v_12095:
    v_12157 = elt(env, 2); // false
    goto v_12096;
v_12097:
    goto v_12093;
v_12094:
    goto v_12095;
v_12096:
    if (v_12159 == v_12157) goto v_12091;
    else goto v_12092;
v_12091:
    v_12157 = elt(env, 2); // false
    goto v_12090;
v_12092:
    v_12157 = v_12158;
    if (v_12157 == nil) goto v_12106;
    v_12157 = v_12158;
    v_12157 = qcdr(v_12157);
    if (v_12157 == nil) goto v_12106;
    goto v_12117;
v_12113:
    v_12157 = elt(env, 4); // and
    goto v_12114;
v_12115:
    goto v_12116;
v_12117:
    goto v_12113;
v_12114:
    goto v_12115;
v_12116:
    return cons(v_12157, v_12158);
v_12106:
    v_12157 = v_12158;
    if (v_12157 == nil) goto v_12120;
    else goto v_12121;
v_12120:
    goto v_12131;
v_12127:
    v_12158 = elt(env, 4); // and
    goto v_12128;
v_12129:
    v_12157 = elt(env, 4); // and
    goto v_12130;
v_12131:
    goto v_12127;
v_12128:
    goto v_12129;
v_12130:
    if (v_12158 == v_12157) goto v_12125;
    else goto v_12126;
v_12125:
    v_12157 = elt(env, 1); // true
    goto v_12124;
v_12126:
    v_12157 = elt(env, 2); // false
    goto v_12124;
    v_12157 = nil;
v_12124:
    goto v_12104;
v_12121:
    v_12157 = v_12158;
    v_12157 = qcar(v_12157);
    goto v_12104;
    v_12157 = nil;
v_12104:
    goto v_12090;
    v_12157 = nil;
v_12090:
    goto v_11440;
v_11927:
    v_12157 = v_12158;
    if (v_12157 == nil) goto v_12145;
    v_12157 = v_12158;
    goto v_11440;
v_12145:
    goto v_12154;
v_12150:
    v_12158 = elt(env, 15); // "cl_simpl1(): unknown operator"
    goto v_12151;
v_12152:
    v_12157 = stack[-4];
    goto v_12153;
v_12154:
    goto v_12150;
v_12151:
    goto v_12152;
v_12153:
    v_12157 = list2(v_12158, v_12157);
    env = stack[-5];
    fn = elt(env, 32); // rederr
    v_12157 = (*qfn1(fn))(fn, v_12157);
    v_12157 = nil;
v_11440:
    return onevalue(v_12157);
}



// Code for gb_buch!-ev_divides!?

static LispObject CC_gb_buchKev_dividesW(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11441, v_11442;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11442 = v_11431;
    v_11441 = v_11430;
// end of prologue
    goto v_11438;
v_11434:
    goto v_11435;
v_11436:
    goto v_11437;
v_11438:
    goto v_11434;
v_11435:
    goto v_11436;
v_11437:
    {
        fn = elt(env, 1); // ev_mtest!?
        return (*qfn2(fn))(fn, v_11442, v_11441);
    }
}



// Code for ev_invlexcomp

static LispObject CC_ev_invlexcomp(LispObject env,
                         LispObject v_11430, LispObject v_11431)
{
    env = qenv(env);
    LispObject v_11519, v_11520;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11431,v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11430,v_11431);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11431;
    stack[-1] = v_11430;
// end of prologue
v_11429:
    v_11519 = stack[-1];
    if (v_11519 == nil) goto v_11438;
    else goto v_11439;
v_11438:
    v_11519 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11435;
v_11439:
    goto v_11451;
v_11447:
    v_11519 = stack[-1];
    v_11520 = qcar(v_11519);
    goto v_11448;
v_11449:
    v_11519 = stack[0];
    v_11519 = qcar(v_11519);
    goto v_11450;
v_11451:
    goto v_11447;
v_11448:
    goto v_11449;
v_11450:
    fn = elt(env, 1); // iequal
    v_11519 = (*qfn2(fn))(fn, v_11520, v_11519);
    env = stack[-3];
    if (v_11519 == nil) goto v_11445;
    goto v_11461;
v_11457:
    v_11519 = stack[-1];
    v_11520 = qcdr(v_11519);
    goto v_11458;
v_11459:
    v_11519 = stack[0];
    v_11519 = qcdr(v_11519);
    goto v_11460;
v_11461:
    goto v_11457;
v_11458:
    goto v_11459;
v_11460:
    stack[-1] = v_11520;
    stack[0] = v_11519;
    goto v_11429;
v_11445:
    goto v_11471;
v_11467:
    v_11519 = stack[-1];
    v_11520 = qcdr(v_11519);
    goto v_11468;
v_11469:
    v_11519 = stack[0];
    v_11519 = qcdr(v_11519);
    goto v_11470;
v_11471:
    goto v_11467;
v_11468:
    goto v_11469;
v_11470:
    v_11519 = CC_ev_invlexcomp(elt(env, 0), v_11520, v_11519);
    env = stack[-3];
    stack[-2] = v_11519;
    goto v_11485;
v_11481:
    v_11520 = stack[-2];
    goto v_11482;
v_11483:
    v_11519 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11484;
v_11485:
    goto v_11481;
v_11482:
    goto v_11483;
v_11484:
    fn = elt(env, 1); // iequal
    v_11519 = (*qfn2(fn))(fn, v_11520, v_11519);
    env = stack[-3];
    if (v_11519 == nil) goto v_11478;
    else goto v_11479;
v_11478:
    v_11519 = stack[-2];
    goto v_11435;
v_11479:
    goto v_11498;
v_11494:
    v_11519 = stack[0];
    v_11520 = qcar(v_11519);
    goto v_11495;
v_11496:
    v_11519 = stack[-1];
    v_11519 = qcar(v_11519);
    goto v_11497;
v_11498:
    goto v_11494;
v_11495:
    goto v_11496;
v_11497:
    fn = elt(env, 1); // iequal
    v_11519 = (*qfn2(fn))(fn, v_11520, v_11519);
    if (v_11519 == nil) goto v_11492;
    v_11519 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11435;
v_11492:
    goto v_11512;
v_11508:
    v_11519 = stack[0];
    v_11520 = qcar(v_11519);
    goto v_11509;
v_11510:
    v_11519 = stack[-1];
    v_11519 = qcar(v_11519);
    goto v_11511;
v_11512:
    goto v_11508;
v_11509:
    goto v_11510;
v_11511:
    if (((intptr_t)(v_11520)) > ((intptr_t)(v_11519))) goto v_11506;
    else goto v_11507;
v_11506:
    v_11519 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11435;
v_11507:
    v_11519 = (LispObject)-16+TAG_FIXNUM; // -1
v_11435:
    return onevalue(v_11519);
}



// Code for ir2mml

static LispObject CC_ir2mml(LispObject env,
                         LispObject v_11430)
{
    env = qenv(env);
    LispObject v_11448;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11430);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_11430;
// end of prologue
    v_11448 = elt(env, 1); // (indent)
    fn = elt(env, 6); // fluid
    v_11448 = (*qfn1(fn))(fn, v_11448);
    env = stack[-1];
    v_11448 = (LispObject)48+TAG_FIXNUM; // 3
    qvalue(elt(env, 2)) = v_11448; // ind
    v_11448 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 3)) = v_11448; // indent
    v_11448 = elt(env, 4); // "<math>"
    fn = elt(env, 7); // printout
    v_11448 = (*qfn1(fn))(fn, v_11448);
    env = stack[-1];
    v_11448 = lisp_true;
    fn = elt(env, 8); // indent!*
    v_11448 = (*qfn1(fn))(fn, v_11448);
    env = stack[-1];
    v_11448 = stack[0];
    fn = elt(env, 9); // expression
    v_11448 = (*qfn1(fn))(fn, v_11448);
    env = stack[-1];
    v_11448 = nil;
    fn = elt(env, 8); // indent!*
    v_11448 = (*qfn1(fn))(fn, v_11448);
    env = stack[-1];
    v_11448 = elt(env, 5); // "</math>"
    fn = elt(env, 7); // printout
    v_11448 = (*qfn1(fn))(fn, v_11448);
    v_11448 = nil;
    return onevalue(v_11448);
}



// Code for rd!:prep

static LispObject CC_rdTprep(LispObject env,
                         LispObject v_11430)
{
    env = qenv(env);
    LispObject v_11454;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11430);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11430);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_11430;
// end of prologue
    v_11454 = qvalue(elt(env, 1)); // !*noconvert
    if (v_11454 == nil) goto v_11435;
    v_11454 = stack[0];
    {
        fn = elt(env, 2); // rdprep1
        return (*qfn1(fn))(fn, v_11454);
    }
v_11435:
    v_11454 = stack[0];
    fn = elt(env, 3); // rd!:onep
    v_11454 = (*qfn1(fn))(fn, v_11454);
    env = stack[-1];
    if (v_11454 == nil) goto v_11440;
    v_11454 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11433;
v_11440:
    v_11454 = stack[0];
    fn = elt(env, 4); // rd!:minus
    v_11454 = (*qfn1(fn))(fn, v_11454);
    env = stack[-1];
    fn = elt(env, 3); // rd!:onep
    v_11454 = (*qfn1(fn))(fn, v_11454);
    env = stack[-1];
    if (v_11454 == nil) goto v_11445;
    v_11454 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_11433;
v_11445:
    v_11454 = stack[0];
    {
        fn = elt(env, 2); // rdprep1
        return (*qfn1(fn))(fn, v_11454);
    }
    v_11454 = nil;
v_11433:
    return onevalue(v_11454);
}



setup_type const u20_setup[] =
{
    {"ibalp_var-unsatlist",     TOO_FEW_2,      CC_ibalp_varKunsatlist,WRONG_NO_2},
    {"dvfsf_susitf",            TOO_FEW_2,      CC_dvfsf_susitf,WRONG_NO_2},
    {"stats_getargs",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_stats_getargs},
    {"list-mgen",               CC_listKmgen,   TOO_MANY_1,    WRONG_NO_1},
    {"prinfit",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_prinfit},
    {"lispassignp",             CC_lispassignp, TOO_MANY_1,    WRONG_NO_1},
    {"assert_uninstall1",       CC_assert_uninstall1,TOO_MANY_1,WRONG_NO_1},
    {"evalequal",               TOO_FEW_2,      CC_evalequal,  WRONG_NO_2},
    {"mv2sf1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mv2sf1},
    {"setk0",                   TOO_FEW_2,      CC_setk0,      WRONG_NO_2},
    {"next-random-number",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_nextKrandomKnumber},
    {"print_with_margin_sub",   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_print_with_margin_sub},
    {"cl_nnf",                  CC_cl_nnf,      TOO_MANY_1,    WRONG_NO_1},
    {"subsublis",               TOO_FEW_2,      CC_subsublis,  WRONG_NO_2},
    {"applyrd",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_applyrd},
    {"ps:minusp:",              CC_psTminuspT,  TOO_MANY_1,    WRONG_NO_1},
    {"arg2of2",                 TOO_FEW_2,      CC_arg2of2,    WRONG_NO_2},
    {"cut:mt",                  TOO_FEW_2,      CC_cutTmt,     WRONG_NO_2},
    {"contr2-strand",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_contr2Kstrand},
    {"rnminusp:",               CC_rnminuspT,   TOO_MANY_1,    WRONG_NO_1},
    {"qremd",                   TOO_FEW_2,      CC_qremd,      WRONG_NO_2},
    {"reverse-num",             CC_reverseKnum, TOO_MANY_1,    WRONG_NO_1},
    {"quotient-mod-p",          TOO_FEW_2,      CC_quotientKmodKp,WRONG_NO_2},
    {"lto_max1",                CC_lto_max1,    TOO_MANY_1,    WRONG_NO_1},
    {"mapins",                  TOO_FEW_2,      CC_mapins,     WRONG_NO_2},
    {"ibalp_tvb",               TOO_FEW_2,      CC_ibalp_tvb,  WRONG_NO_2},
    {"aex_fvarl",               CC_aex_fvarl,   TOO_MANY_1,    WRONG_NO_1},
    {"make-univariate-image-mod-p",TOO_FEW_2,   CC_makeKunivariateKimageKmodKp,WRONG_NO_2},
    {"merge-ind-vars",          TOO_FEW_2,      CC_mergeKindKvars,WRONG_NO_2},
    {"testredzz",               CC_testredzz,   TOO_MANY_1,    WRONG_NO_1},
    {"indexvarordp",            TOO_FEW_2,      CC_indexvarordp,WRONG_NO_2},
    {"inttovec-solve",          TOO_FEW_2,      CC_inttovecKsolve,WRONG_NO_2},
    {"begin1a",                 CC_begin1a,     TOO_MANY_1,    WRONG_NO_1},
    {"bas_newnumber",           TOO_FEW_2,      CC_bas_newnumber,WRONG_NO_2},
    {"derivative-mod-p-1",      TOO_FEW_2,      CC_derivativeKmodKpK1,WRONG_NO_2},
    {"carrassoc",               TOO_FEW_2,      CC_carrassoc,  WRONG_NO_2},
    {"simpqg",                  CC_simpqg,      TOO_MANY_1,    WRONG_NO_1},
    {"mkprod",                  CC_mkprod,      TOO_MANY_1,    WRONG_NO_1},
    {"cl_simpl1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_simpl1},
    {"gb_buch-ev_divides?",     TOO_FEW_2,      CC_gb_buchKev_dividesW,WRONG_NO_2},
    {"ev_invlexcomp",           TOO_FEW_2,      CC_ev_invlexcomp,WRONG_NO_2},
    {"ir2mml",                  CC_ir2mml,      TOO_MANY_1,    WRONG_NO_1},
    {"rd:prep",                 CC_rdTprep,     TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u20", (two_args *)"63977 1225651 7504586", 0}
};

// end of generated code
