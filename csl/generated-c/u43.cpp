
// $destdir/u43.c        Machine generated C code

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



// Code for numir

static LispObject CC_numir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24739, v_24740, v_24741;
    LispObject fn;
    argcheck(nargs, 0, "numir");
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
    goto v_24539;
v_24535:
    v_24740 = qvalue(elt(env, 1)); // atts
    goto v_24536;
v_24537:
    v_24739 = elt(env, 2); // name
    goto v_24538;
v_24539:
    goto v_24535;
v_24536:
    goto v_24537;
v_24538:
    fn = elt(env, 11); // find
    v_24739 = (*qfn2(fn))(fn, v_24740, v_24739);
    env = stack[-7];
    v_24739 = Lintern(nil, v_24739);
    env = stack[-7];
    stack[-1] = v_24739;
    fn = elt(env, 12); // lex
    v_24739 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    fn = elt(env, 13); // omobj
    v_24739 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    stack[0] = v_24739;
    fn = elt(env, 12); // lex
    v_24739 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    fn = elt(env, 13); // omobj
    v_24739 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    goto v_24554;
v_24550:
    v_24741 = stack[-1];
    goto v_24551;
v_24552:
    v_24740 = elt(env, 3); // complex_cartesian
    goto v_24553;
v_24554:
    goto v_24550;
v_24551:
    goto v_24552;
v_24553:
    if (v_24741 == v_24740) goto v_24548;
    else goto v_24549;
v_24548:
    v_24740 = stack[0];
    if (symbolp(v_24740)) goto v_24559;
    v_24740 = v_24739;
    if (symbolp(v_24740)) goto v_24559;
    goto v_24560;
v_24559:
    goto v_24572;
v_24566:
    stack[-4] = elt(env, 4); // plus
    goto v_24567;
v_24568:
    stack[-3] = nil;
    goto v_24569;
v_24570:
    goto v_24582;
v_24576:
    stack[-2] = stack[0];
    goto v_24577;
v_24578:
    goto v_24591;
v_24585:
    stack[-1] = elt(env, 5); // times
    goto v_24586;
v_24587:
    stack[0] = nil;
    goto v_24588;
v_24589:
    goto v_24601;
v_24595:
    v_24741 = v_24739;
    goto v_24596;
v_24597:
    v_24740 = elt(env, 6); // !&imaginaryi!;
    goto v_24598;
v_24599:
    v_24739 = nil;
    goto v_24600;
v_24601:
    goto v_24595;
v_24596:
    goto v_24597;
v_24598:
    goto v_24599;
v_24600:
    v_24739 = list2star(v_24741, v_24740, v_24739);
    env = stack[-7];
    goto v_24590;
v_24591:
    goto v_24585;
v_24586:
    goto v_24587;
v_24588:
    goto v_24589;
v_24590:
    v_24740 = list2star(stack[-1], stack[0], v_24739);
    env = stack[-7];
    goto v_24579;
v_24580:
    v_24739 = nil;
    goto v_24581;
v_24582:
    goto v_24576;
v_24577:
    goto v_24578;
v_24579:
    goto v_24580;
v_24581:
    v_24739 = list2star(stack[-2], v_24740, v_24739);
    goto v_24571;
v_24572:
    goto v_24566;
v_24567:
    goto v_24568;
v_24569:
    goto v_24570;
v_24571:
    {
        LispObject v_24749 = stack[-4];
        LispObject v_24750 = stack[-3];
        return list2star(v_24749, v_24750, v_24739);
    }
v_24560:
    goto v_24547;
v_24549:
v_24547:
    goto v_24614;
v_24610:
    v_24741 = stack[-1];
    goto v_24611;
v_24612:
    v_24740 = elt(env, 7); // complex_polar
    goto v_24613;
v_24614:
    goto v_24610;
v_24611:
    goto v_24612;
v_24613:
    if (v_24741 == v_24740) goto v_24608;
    else goto v_24609;
v_24608:
    v_24740 = stack[0];
    if (symbolp(v_24740)) goto v_24619;
    v_24740 = v_24739;
    if (symbolp(v_24740)) goto v_24619;
    goto v_24620;
v_24619:
    goto v_24632;
v_24626:
    stack[-6] = elt(env, 5); // times
    goto v_24627;
v_24628:
    stack[-5] = nil;
    goto v_24629;
v_24630:
    goto v_24642;
v_24636:
    stack[-4] = stack[0];
    goto v_24637;
v_24638:
    goto v_24651;
v_24645:
    stack[-3] = elt(env, 8); // exp
    goto v_24646;
v_24647:
    stack[-2] = nil;
    goto v_24648;
v_24649:
    goto v_24662;
v_24656:
    stack[-1] = elt(env, 5); // times
    goto v_24657;
v_24658:
    stack[0] = nil;
    goto v_24659;
v_24660:
    goto v_24672;
v_24666:
    v_24741 = v_24739;
    goto v_24667;
v_24668:
    v_24740 = elt(env, 6); // !&imaginaryi!;
    goto v_24669;
v_24670:
    v_24739 = nil;
    goto v_24671;
v_24672:
    goto v_24666;
v_24667:
    goto v_24668;
v_24669:
    goto v_24670;
v_24671:
    v_24739 = list2star(v_24741, v_24740, v_24739);
    env = stack[-7];
    goto v_24661;
v_24662:
    goto v_24656;
v_24657:
    goto v_24658;
v_24659:
    goto v_24660;
v_24661:
    v_24739 = list2star(stack[-1], stack[0], v_24739);
    env = stack[-7];
    v_24739 = ncons(v_24739);
    env = stack[-7];
    goto v_24650;
v_24651:
    goto v_24645;
v_24646:
    goto v_24647;
v_24648:
    goto v_24649;
v_24650:
    v_24740 = list2star(stack[-3], stack[-2], v_24739);
    env = stack[-7];
    goto v_24639;
v_24640:
    v_24739 = nil;
    goto v_24641;
v_24642:
    goto v_24636;
v_24637:
    goto v_24638;
v_24639:
    goto v_24640;
v_24641:
    v_24739 = list2star(stack[-4], v_24740, v_24739);
    goto v_24631;
v_24632:
    goto v_24626;
v_24627:
    goto v_24628;
v_24629:
    goto v_24630;
v_24631:
    {
        LispObject v_24751 = stack[-6];
        LispObject v_24752 = stack[-5];
        return list2star(v_24751, v_24752, v_24739);
    }
v_24620:
    goto v_24607;
v_24609:
v_24607:
    goto v_24685;
v_24681:
    v_24741 = stack[-1];
    goto v_24682;
v_24683:
    v_24740 = elt(env, 9); // rational
    goto v_24684;
v_24685:
    goto v_24681;
v_24682:
    goto v_24683;
v_24684:
    if (v_24741 == v_24740) goto v_24679;
    else goto v_24680;
v_24679:
    v_24740 = stack[0];
    if (symbolp(v_24740)) goto v_24690;
    v_24740 = v_24739;
    if (symbolp(v_24740)) goto v_24690;
    goto v_24691;
v_24690:
    goto v_24703;
v_24697:
    stack[-2] = elt(env, 10); // divide
    goto v_24698;
v_24699:
    stack[-1] = nil;
    goto v_24700;
v_24701:
    goto v_24713;
v_24707:
    v_24741 = stack[0];
    goto v_24708;
v_24709:
    v_24740 = v_24739;
    goto v_24710;
v_24711:
    v_24739 = nil;
    goto v_24712;
v_24713:
    goto v_24707;
v_24708:
    goto v_24709;
v_24710:
    goto v_24711;
v_24712:
    v_24739 = list2star(v_24741, v_24740, v_24739);
    goto v_24702;
v_24703:
    goto v_24697;
v_24698:
    goto v_24699;
v_24700:
    goto v_24701;
v_24702:
    {
        LispObject v_24753 = stack[-2];
        LispObject v_24754 = stack[-1];
        return list2star(v_24753, v_24754, v_24739);
    }
v_24691:
    goto v_24678;
v_24680:
v_24678:
    goto v_24725;
v_24719:
    stack[-2] = stack[-1];
    goto v_24720;
v_24721:
    stack[-1] = nil;
    goto v_24722;
v_24723:
    goto v_24735;
v_24729:
    v_24741 = stack[0];
    goto v_24730;
v_24731:
    v_24740 = v_24739;
    goto v_24732;
v_24733:
    v_24739 = nil;
    goto v_24734;
v_24735:
    goto v_24729;
v_24730:
    goto v_24731;
v_24732:
    goto v_24733;
v_24734:
    v_24739 = list2star(v_24741, v_24740, v_24739);
    goto v_24724;
v_24725:
    goto v_24719;
v_24720:
    goto v_24721;
v_24722:
    goto v_24723;
v_24724:
    {
        LispObject v_24755 = stack[-2];
        LispObject v_24756 = stack[-1];
        return list2star(v_24755, v_24756, v_24739);
    }
    return onevalue(v_24739);
}



// Code for mkexpt

static LispObject CC_mkexpt(LispObject env,
                         LispObject v_24526, LispObject v_24527)
{
    env = qenv(env);
    LispObject v_24554, v_24555, v_24556, v_24557;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24556 = v_24527;
    v_24557 = v_24526;
// end of prologue
    goto v_24537;
v_24533:
    v_24555 = v_24556;
    goto v_24534;
v_24535:
    v_24554 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24536;
v_24537:
    goto v_24533;
v_24534:
    goto v_24535;
v_24536:
    if (v_24555 == v_24554) goto v_24531;
    else goto v_24532;
v_24531:
    v_24554 = v_24557;
    goto v_24530;
v_24532:
    goto v_24550;
v_24544:
    v_24554 = elt(env, 1); // expt
    goto v_24545;
v_24546:
    v_24555 = v_24557;
    goto v_24547;
v_24548:
    goto v_24549;
v_24550:
    goto v_24544;
v_24545:
    goto v_24546;
v_24547:
    goto v_24548;
v_24549:
    return list3(v_24554, v_24555, v_24556);
    v_24554 = nil;
v_24530:
    return onevalue(v_24554);
}



// Code for evalmember

static LispObject CC_evalmember(LispObject env,
                         LispObject v_24526, LispObject v_24527)
{
    env = qenv(env);
    LispObject v_24538, v_24539;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24527,v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24526,v_24527);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_24538 = v_24527;
    v_24539 = v_24526;
// end of prologue
    goto v_24533;
v_24529:
    stack[0] = v_24539;
    goto v_24530;
v_24531:
    fn = elt(env, 1); // getrlist
    v_24538 = (*qfn1(fn))(fn, v_24538);
    goto v_24532;
v_24533:
    goto v_24529;
v_24530:
    goto v_24531;
v_24532:
    v_24538 = Lmember(nil, stack[0], v_24538);
    return onevalue(v_24538);
}



// Code for e!*

static LispObject CC_eH(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24529;
    LispObject fn;
    argcheck(nargs, 0, "e*");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_24529 = qvalue(elt(env, 1)); // !:bprec!:
    {
        fn = elt(env, 2); // !:e
        return (*qfn1(fn))(fn, v_24529);
    }
}



// Code for gpargp

static LispObject CC_gpargp(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24540;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24526);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24526;
// end of prologue
    v_24540 = stack[0];
    v_24540 = Lstringp(nil, v_24540);
    env = stack[-1];
    if (v_24540 == nil) goto v_24530;
    else goto v_24529;
v_24530:
    v_24540 = stack[0];
    fn = elt(env, 1); // gpexpp
    v_24540 = (*qfn1(fn))(fn, v_24540);
    env = stack[-1];
    if (v_24540 == nil) goto v_24535;
    else goto v_24534;
v_24535:
    v_24540 = stack[0];
    {
        fn = elt(env, 2); // gplogexpp
        return (*qfn1(fn))(fn, v_24540);
    }
v_24534:
v_24529:
    return onevalue(v_24540);
}



// Code for indexvp

static LispObject CC_indexvp(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24539, v_24540;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24539 = v_24526;
// end of prologue
    v_24540 = v_24539;
    if (!consp(v_24540)) goto v_24531;
    v_24539 = qcar(v_24539);
    if (!symbolp(v_24539)) v_24539 = nil;
    else { v_24539 = qfastgets(v_24539);
           if (v_24539 != nil) { v_24539 = elt(v_24539, 16); // indexvar
#ifdef RECORD_GET
             if (v_24539 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v_24539 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v_24539 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v_24539 == SPID_NOPROP) v_24539 = nil; else v_24539 = lisp_true; }}
#endif
    goto v_24529;
v_24531:
    v_24539 = nil;
    goto v_24529;
    v_24539 = nil;
v_24529:
    return onevalue(v_24539);
}



// Code for extract_vars

static LispObject CC_extract_vars(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24566, v_24567;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24526);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24526;
// end of prologue
    stack[-1] = nil;
v_24531:
    v_24566 = stack[0];
    if (v_24566 == nil) goto v_24534;
    else goto v_24535;
v_24534:
    v_24566 = stack[-1];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_24566);
    }
v_24535:
    goto v_24546;
v_24542:
    v_24566 = stack[0];
    v_24566 = qcar(v_24566);
    fn = elt(env, 3); // raiseind!:
    v_24567 = (*qfn1(fn))(fn, v_24566);
    env = stack[-2];
    goto v_24543;
v_24544:
    v_24566 = elt(env, 1); // variable
    goto v_24545;
v_24546:
    goto v_24542;
v_24543:
    goto v_24544;
v_24545:
    v_24566 = Lflagp(nil, v_24567, v_24566);
    env = stack[-2];
    if (v_24566 == nil) goto v_24540;
    goto v_24556;
v_24552:
    v_24566 = stack[0];
    v_24567 = qcar(v_24566);
    goto v_24553;
v_24554:
    v_24566 = stack[-1];
    goto v_24555;
v_24556:
    goto v_24552;
v_24553:
    goto v_24554;
v_24555:
    v_24566 = cons(v_24567, v_24566);
    env = stack[-2];
    stack[-1] = v_24566;
    v_24566 = stack[0];
    v_24566 = qcdr(v_24566);
    stack[0] = v_24566;
    goto v_24531;
v_24540:
    v_24566 = stack[0];
    v_24566 = qcdr(v_24566);
    stack[0] = v_24566;
    goto v_24531;
    v_24566 = nil;
    return onevalue(v_24566);
}



// Code for ev_mtest!?

static LispObject CC_ev_mtestW(LispObject env,
                         LispObject v_24526, LispObject v_24527)
{
    env = qenv(env);
    LispObject v_24566, v_24567, v_24568, v_24569, v_24570;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24568 = v_24527;
    v_24569 = v_24526;
// end of prologue
    v_24566 = lisp_true;
    v_24570 = v_24566;
v_24535:
    v_24566 = v_24569;
    if (v_24566 == nil) goto v_24538;
    v_24566 = v_24570;
    if (v_24566 == nil) goto v_24538;
    goto v_24539;
v_24538:
    goto v_24534;
v_24539:
    goto v_24553;
v_24549:
    v_24566 = v_24569;
    v_24567 = qcar(v_24566);
    goto v_24550;
v_24551:
    v_24566 = v_24568;
    v_24566 = qcar(v_24566);
    goto v_24552;
v_24553:
    goto v_24549;
v_24550:
    goto v_24551;
v_24552:
    if (((intptr_t)(v_24567)) < ((intptr_t)(v_24566))) goto v_24547;
    else goto v_24548;
v_24547:
    v_24566 = nil;
    v_24570 = v_24566;
    v_24569 = v_24566;
    goto v_24546;
v_24548:
    v_24566 = v_24569;
    v_24566 = qcdr(v_24566);
    v_24569 = v_24566;
    v_24566 = v_24568;
    v_24566 = qcdr(v_24566);
    v_24568 = v_24566;
    goto v_24546;
v_24546:
    goto v_24535;
v_24534:
    v_24566 = v_24570;
    return onevalue(v_24566);
}



// Code for cgp_greenp

static LispObject CC_cgp_greenp(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24531;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24526);
    }
// copy arguments values to proper place
    v_24531 = v_24526;
// end of prologue
    fn = elt(env, 1); // cgp_rp
    v_24531 = (*qfn1(fn))(fn, v_24531);
    v_24531 = (v_24531 == nil ? lisp_true : nil);
    return onevalue(v_24531);
}



// Code for matrixml

static LispObject CC_matrixml(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24573, v_24574;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24526);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24526;
// end of prologue
    v_24573 = elt(env, 1); // "<matrix"
    fn = elt(env, 5); // printout
    v_24573 = (*qfn1(fn))(fn, v_24573);
    env = stack[-1];
    goto v_24537;
v_24533:
    v_24573 = stack[0];
    v_24574 = qcar(v_24573);
    goto v_24534;
v_24535:
    v_24573 = elt(env, 2); // ""
    goto v_24536;
v_24537:
    goto v_24533;
v_24534:
    goto v_24535;
v_24536:
    fn = elt(env, 6); // attributesml
    v_24573 = (*qfn2(fn))(fn, v_24574, v_24573);
    env = stack[-1];
    v_24573 = lisp_true;
    fn = elt(env, 7); // indent!*
    v_24573 = (*qfn1(fn))(fn, v_24573);
    env = stack[-1];
    goto v_24551;
v_24547:
    v_24573 = stack[0];
    v_24573 = qcdr(v_24573);
    v_24574 = qcar(v_24573);
    goto v_24548;
v_24549:
    v_24573 = elt(env, 3); // matrixrow
    goto v_24550;
v_24551:
    goto v_24547;
v_24548:
    goto v_24549;
v_24550:
    if (v_24574 == v_24573) goto v_24545;
    else goto v_24546;
v_24545:
    v_24573 = stack[0];
    v_24573 = qcdr(v_24573);
    v_24573 = qcdr(v_24573);
    v_24573 = qcar(v_24573);
    fn = elt(env, 8); // matrix_rows
    v_24573 = (*qfn1(fn))(fn, v_24573);
    env = stack[-1];
    goto v_24544;
v_24546:
    v_24573 = stack[0];
    v_24573 = qcdr(v_24573);
    v_24573 = qcdr(v_24573);
    v_24573 = qcar(v_24573);
    fn = elt(env, 9); // cols2rows
    v_24573 = (*qfn1(fn))(fn, v_24573);
    env = stack[-1];
    fn = elt(env, 8); // matrix_rows
    v_24573 = (*qfn1(fn))(fn, v_24573);
    env = stack[-1];
    goto v_24544;
v_24544:
    v_24573 = nil;
    fn = elt(env, 7); // indent!*
    v_24573 = (*qfn1(fn))(fn, v_24573);
    env = stack[-1];
    v_24573 = elt(env, 4); // "</matrix>"
    fn = elt(env, 5); // printout
    v_24573 = (*qfn1(fn))(fn, v_24573);
    v_24573 = nil;
    return onevalue(v_24573);
}



// Code for ps!:arg!-values

static LispObject CC_psTargKvalues(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24677, v_24678, v_24679;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24526);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_24678 = v_24526;
// end of prologue
    goto v_24533;
v_24529:
    v_24677 = v_24678;
    stack[-4] = qcar(v_24677);
    goto v_24530;
v_24531:
    v_24677 = v_24678;
    v_24677 = qcdr(v_24677);
    stack[-3] = v_24677;
    v_24677 = stack[-3];
    if (v_24677 == nil) goto v_24546;
    else goto v_24547;
v_24546:
    v_24677 = nil;
    goto v_24540;
v_24547:
    v_24677 = stack[-3];
    v_24677 = qcar(v_24677);
    v_24679 = v_24677;
    v_24677 = v_24679;
    if (!consp(v_24677)) goto v_24560;
    else goto v_24561;
v_24560:
    v_24677 = lisp_true;
    goto v_24559;
v_24561:
    goto v_24574;
v_24570:
    v_24677 = v_24679;
    v_24678 = qcar(v_24677);
    goto v_24571;
v_24572:
    v_24677 = elt(env, 1); // !:ps!:
    goto v_24573;
v_24574:
    goto v_24570;
v_24571:
    goto v_24572;
v_24573:
    if (v_24678 == v_24677) goto v_24569;
    v_24677 = v_24679;
    v_24677 = qcar(v_24677);
    if (!symbolp(v_24677)) v_24677 = nil;
    else { v_24677 = qfastgets(v_24677);
           if (v_24677 != nil) { v_24677 = elt(v_24677, 8); // dname
#ifdef RECORD_GET
             if (v_24677 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_24677 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_24677 == SPID_NOPROP) v_24677 = nil; }}
#endif
    goto v_24567;
v_24569:
    v_24677 = nil;
    goto v_24567;
    v_24677 = nil;
v_24567:
    goto v_24559;
    v_24677 = nil;
v_24559:
    if (v_24677 == nil) goto v_24557;
    v_24677 = v_24679;
    goto v_24555;
v_24557:
    v_24677 = v_24679;
    v_24677 = Lconsp(nil, v_24677);
    env = stack[-5];
    if (v_24677 == nil) goto v_24586;
    goto v_24595;
v_24591:
    v_24677 = v_24679;
    v_24678 = qcar(v_24677);
    goto v_24592;
v_24593:
    v_24677 = elt(env, 1); // !:ps!:
    goto v_24594;
v_24595:
    goto v_24591;
v_24592:
    goto v_24593;
v_24594:
    if (v_24678 == v_24677) goto v_24590;
    else goto v_24586;
v_24590:
    v_24677 = v_24679;
    fn = elt(env, 2); // ps!:value
    v_24677 = (*qfn1(fn))(fn, v_24677);
    env = stack[-5];
    goto v_24555;
v_24586:
    v_24677 = v_24679;
    v_24677 = CC_psTargKvalues(elt(env, 0), v_24677);
    env = stack[-5];
    goto v_24555;
    v_24677 = nil;
v_24555:
    v_24677 = ncons(v_24677);
    env = stack[-5];
    stack[-1] = v_24677;
    stack[-2] = v_24677;
v_24541:
    v_24677 = stack[-3];
    v_24677 = qcdr(v_24677);
    stack[-3] = v_24677;
    v_24677 = stack[-3];
    if (v_24677 == nil) goto v_24609;
    else goto v_24610;
v_24609:
    v_24677 = stack[-2];
    goto v_24540;
v_24610:
    goto v_24618;
v_24614:
    stack[0] = stack[-1];
    goto v_24615;
v_24616:
    v_24677 = stack[-3];
    v_24677 = qcar(v_24677);
    v_24679 = v_24677;
    v_24677 = v_24679;
    if (!consp(v_24677)) goto v_24630;
    else goto v_24631;
v_24630:
    v_24677 = lisp_true;
    goto v_24629;
v_24631:
    goto v_24644;
v_24640:
    v_24677 = v_24679;
    v_24678 = qcar(v_24677);
    goto v_24641;
v_24642:
    v_24677 = elt(env, 1); // !:ps!:
    goto v_24643;
v_24644:
    goto v_24640;
v_24641:
    goto v_24642;
v_24643:
    if (v_24678 == v_24677) goto v_24639;
    v_24677 = v_24679;
    v_24677 = qcar(v_24677);
    if (!symbolp(v_24677)) v_24677 = nil;
    else { v_24677 = qfastgets(v_24677);
           if (v_24677 != nil) { v_24677 = elt(v_24677, 8); // dname
#ifdef RECORD_GET
             if (v_24677 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_24677 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_24677 == SPID_NOPROP) v_24677 = nil; }}
#endif
    goto v_24637;
v_24639:
    v_24677 = nil;
    goto v_24637;
    v_24677 = nil;
v_24637:
    goto v_24629;
    v_24677 = nil;
v_24629:
    if (v_24677 == nil) goto v_24627;
    v_24677 = v_24679;
    goto v_24625;
v_24627:
    v_24677 = v_24679;
    v_24677 = Lconsp(nil, v_24677);
    env = stack[-5];
    if (v_24677 == nil) goto v_24656;
    goto v_24665;
v_24661:
    v_24677 = v_24679;
    v_24678 = qcar(v_24677);
    goto v_24662;
v_24663:
    v_24677 = elt(env, 1); // !:ps!:
    goto v_24664;
v_24665:
    goto v_24661;
v_24662:
    goto v_24663;
v_24664:
    if (v_24678 == v_24677) goto v_24660;
    else goto v_24656;
v_24660:
    v_24677 = v_24679;
    fn = elt(env, 2); // ps!:value
    v_24677 = (*qfn1(fn))(fn, v_24677);
    env = stack[-5];
    goto v_24625;
v_24656:
    v_24677 = v_24679;
    v_24677 = CC_psTargKvalues(elt(env, 0), v_24677);
    env = stack[-5];
    goto v_24625;
    v_24677 = nil;
v_24625:
    v_24677 = ncons(v_24677);
    env = stack[-5];
    goto v_24617;
v_24618:
    goto v_24614;
v_24615:
    goto v_24616;
v_24617:
    v_24677 = Lrplacd(nil, stack[0], v_24677);
    env = stack[-5];
    v_24677 = stack[-1];
    v_24677 = qcdr(v_24677);
    stack[-1] = v_24677;
    goto v_24541;
v_24540:
    goto v_24532;
v_24533:
    goto v_24529;
v_24530:
    goto v_24531;
v_24532:
    {
        LispObject v_24685 = stack[-4];
        return cons(v_24685, v_24677);
    }
}



// Code for diford

static LispObject CC_diford(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24532;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24532 = v_24526;
// end of prologue
    v_24532 = qcdr(v_24532);
    v_24532 = qcdr(v_24532);
    {
        fn = elt(env, 1); // lengthn
        return (*qfn1(fn))(fn, v_24532);
    }
}



// Code for specrd!:times

static LispObject CC_specrdTtimes(LispObject env,
                         LispObject v_24526, LispObject v_24527)
{
    env = qenv(env);
    LispObject v_24615, v_24616;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24527,v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24526,v_24527);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_24527;
    stack[-1] = v_24526;
// end of prologue
    stack[-2] = nil;
    v_24615 = stack[-1];
    fn = elt(env, 2); // add_minus
    v_24615 = (*qfn1(fn))(fn, v_24615);
    env = stack[-3];
    stack[-1] = v_24615;
    v_24615 = stack[0];
    fn = elt(env, 2); // add_minus
    v_24615 = (*qfn1(fn))(fn, v_24615);
    env = stack[-3];
    stack[0] = v_24615;
    goto v_24545;
v_24541:
    v_24616 = stack[-1];
    goto v_24542;
v_24543:
    v_24615 = elt(env, 1); // minus
    goto v_24544;
v_24545:
    goto v_24541;
v_24542:
    goto v_24543;
v_24544:
    if (!consp(v_24616)) goto v_24539;
    v_24616 = qcar(v_24616);
    if (v_24616 == v_24615) goto v_24538;
    else goto v_24539;
v_24538:
    v_24615 = stack[-1];
    v_24615 = qcdr(v_24615);
    v_24615 = qcar(v_24615);
    stack[-1] = v_24615;
    v_24615 = lisp_true;
    stack[-2] = v_24615;
    goto v_24537;
v_24539:
v_24537:
    goto v_24561;
v_24557:
    v_24616 = stack[0];
    goto v_24558;
v_24559:
    v_24615 = elt(env, 1); // minus
    goto v_24560;
v_24561:
    goto v_24557;
v_24558:
    goto v_24559;
v_24560:
    if (!consp(v_24616)) goto v_24555;
    v_24616 = qcar(v_24616);
    if (v_24616 == v_24615) goto v_24554;
    else goto v_24555;
v_24554:
    v_24615 = stack[0];
    v_24615 = qcdr(v_24615);
    v_24615 = qcar(v_24615);
    stack[0] = v_24615;
    v_24615 = stack[-2];
    v_24615 = (v_24615 == nil ? lisp_true : nil);
    stack[-2] = v_24615;
    goto v_24553;
v_24555:
v_24553:
    v_24615 = stack[-1];
    if (!consp(v_24615)) goto v_24571;
    else goto v_24572;
v_24571:
    v_24615 = stack[-1];
    v_24615 = Lfloat(nil, v_24615);
    env = stack[-3];
    fn = elt(env, 3); // mkround
    v_24615 = (*qfn1(fn))(fn, v_24615);
    env = stack[-3];
    stack[-1] = v_24615;
    goto v_24570;
v_24572:
v_24570:
    v_24615 = stack[0];
    if (!consp(v_24615)) goto v_24579;
    else goto v_24580;
v_24579:
    v_24615 = stack[0];
    v_24615 = Lfloat(nil, v_24615);
    env = stack[-3];
    fn = elt(env, 3); // mkround
    v_24615 = (*qfn1(fn))(fn, v_24615);
    env = stack[-3];
    stack[0] = v_24615;
    goto v_24578;
v_24580:
v_24578:
    v_24615 = stack[-2];
    if (v_24615 == nil) goto v_24588;
    goto v_24595;
v_24591:
    stack[-2] = elt(env, 1); // minus
    goto v_24592;
v_24593:
    goto v_24602;
v_24598:
    v_24616 = stack[-1];
    goto v_24599;
v_24600:
    v_24615 = stack[0];
    goto v_24601;
v_24602:
    goto v_24598;
v_24599:
    goto v_24600;
v_24601:
    fn = elt(env, 4); // rd!:times
    v_24615 = (*qfn2(fn))(fn, v_24616, v_24615);
    goto v_24594;
v_24595:
    goto v_24591;
v_24592:
    goto v_24593;
v_24594:
    {
        LispObject v_24620 = stack[-2];
        return list2(v_24620, v_24615);
    }
v_24588:
    goto v_24612;
v_24608:
    v_24616 = stack[-1];
    goto v_24609;
v_24610:
    v_24615 = stack[0];
    goto v_24611;
v_24612:
    goto v_24608;
v_24609:
    goto v_24610;
v_24611:
    {
        fn = elt(env, 4); // rd!:times
        return (*qfn2(fn))(fn, v_24616, v_24615);
    }
    v_24615 = nil;
    return onevalue(v_24615);
}



// Code for remdiff

static LispObject CC_remdiff(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24630, v_24631;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24526);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_24526;
// end of prologue
    v_24630 = stack[-1];
    if (symbolp(v_24630)) goto v_24530;
    v_24630 = stack[-1];
    fn = elt(env, 4); // constp
    v_24630 = (*qfn1(fn))(fn, v_24630);
    env = stack[-5];
    if (v_24630 == nil) goto v_24534;
    else goto v_24530;
v_24534:
    goto v_24531;
v_24530:
    v_24630 = stack[-1];
    goto v_24529;
v_24531:
    goto v_24548;
v_24544:
    v_24630 = stack[-1];
    v_24631 = qcar(v_24630);
    goto v_24545;
v_24546:
    v_24630 = elt(env, 1); // difference
    goto v_24547;
v_24548:
    goto v_24544;
v_24545:
    goto v_24546;
v_24547:
    if (v_24631 == v_24630) goto v_24542;
    else goto v_24543;
v_24542:
    goto v_24559;
v_24553:
    stack[-3] = elt(env, 2); // plus
    goto v_24554;
v_24555:
    v_24630 = stack[-1];
    v_24630 = qcdr(v_24630);
    v_24630 = qcar(v_24630);
    stack[-2] = CC_remdiff(elt(env, 0), v_24630);
    env = stack[-5];
    goto v_24556;
v_24557:
    goto v_24570;
v_24566:
    stack[0] = elt(env, 3); // minus
    goto v_24567;
v_24568:
    v_24630 = stack[-1];
    v_24630 = qcdr(v_24630);
    v_24630 = qcdr(v_24630);
    v_24630 = qcar(v_24630);
    v_24630 = CC_remdiff(elt(env, 0), v_24630);
    env = stack[-5];
    goto v_24569;
v_24570:
    goto v_24566;
v_24567:
    goto v_24568;
v_24569:
    v_24630 = list2(stack[0], v_24630);
    env = stack[-5];
    goto v_24558;
v_24559:
    goto v_24553;
v_24554:
    goto v_24555;
v_24556:
    goto v_24557;
v_24558:
    v_24630 = list3(stack[-3], stack[-2], v_24630);
    goto v_24541;
v_24543:
    goto v_24584;
v_24580:
    v_24630 = stack[-1];
    stack[-4] = qcar(v_24630);
    goto v_24581;
v_24582:
    v_24630 = stack[-1];
    v_24630 = qcdr(v_24630);
    stack[-3] = v_24630;
    v_24630 = stack[-3];
    if (v_24630 == nil) goto v_24597;
    else goto v_24598;
v_24597:
    v_24630 = nil;
    goto v_24591;
v_24598:
    v_24630 = stack[-3];
    v_24630 = qcar(v_24630);
    v_24630 = CC_remdiff(elt(env, 0), v_24630);
    env = stack[-5];
    v_24630 = ncons(v_24630);
    env = stack[-5];
    stack[-1] = v_24630;
    stack[-2] = v_24630;
v_24592:
    v_24630 = stack[-3];
    v_24630 = qcdr(v_24630);
    stack[-3] = v_24630;
    v_24630 = stack[-3];
    if (v_24630 == nil) goto v_24611;
    else goto v_24612;
v_24611:
    v_24630 = stack[-2];
    goto v_24591;
v_24612:
    goto v_24620;
v_24616:
    stack[0] = stack[-1];
    goto v_24617;
v_24618:
    v_24630 = stack[-3];
    v_24630 = qcar(v_24630);
    v_24630 = CC_remdiff(elt(env, 0), v_24630);
    env = stack[-5];
    v_24630 = ncons(v_24630);
    env = stack[-5];
    goto v_24619;
v_24620:
    goto v_24616;
v_24617:
    goto v_24618;
v_24619:
    v_24630 = Lrplacd(nil, stack[0], v_24630);
    env = stack[-5];
    v_24630 = stack[-1];
    v_24630 = qcdr(v_24630);
    stack[-1] = v_24630;
    goto v_24592;
v_24591:
    goto v_24583;
v_24584:
    goto v_24580;
v_24581:
    goto v_24582;
v_24583:
    {
        LispObject v_24637 = stack[-4];
        return cons(v_24637, v_24630);
    }
    v_24630 = nil;
v_24541:
    goto v_24529;
    v_24630 = nil;
v_24529:
    return onevalue(v_24630);
}



// Code for remove_least_item

static LispObject CC_remove_least_item(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24552, v_24553;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24552 = v_24526;
// end of prologue
v_24530:
    v_24553 = v_24552;
    v_24553 = qcdr(v_24553);
    if (v_24553 == nil) goto v_24533;
    else goto v_24534;
v_24533:
    v_24552 = elt(env, 1); // "How did we get here?"
    {
        fn = elt(env, 2); // rederr
        return (*qfn1(fn))(fn, v_24552);
    }
v_24534:
    v_24553 = v_24552;
    v_24553 = qcdr(v_24553);
    v_24553 = qcar(v_24553);
    v_24553 = qcdr(v_24553);
    if (v_24553 == nil) goto v_24539;
    else goto v_24540;
v_24539:
    {
        fn = elt(env, 3); // remove_root_item
        return (*qfn1(fn))(fn, v_24552);
    }
v_24540:
    v_24552 = qcdr(v_24552);
    v_24552 = qcar(v_24552);
    goto v_24530;
    v_24552 = nil;
    return onevalue(v_24552);
}



// Code for nspaces

static LispObject CC_nspaces(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24566, v_24567, v_24568;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24526);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_24526;
// end of prologue
    stack[-2] = nil;
    v_24566 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_24566;
v_24534:
    goto v_24546;
v_24542:
    v_24567 = stack[-1];
    goto v_24543;
v_24544:
    v_24566 = stack[0];
    goto v_24545;
v_24546:
    goto v_24542;
v_24543:
    goto v_24544;
v_24545:
    v_24566 = difference2(v_24567, v_24566);
    env = stack[-3];
    v_24566 = Lminusp(nil, v_24566);
    env = stack[-3];
    if (v_24566 == nil) goto v_24539;
    goto v_24533;
v_24539:
    goto v_24557;
v_24551:
    v_24568 = elt(env, 1); // !!
    goto v_24552;
v_24553:
    v_24567 = elt(env, 2); // ! 
    goto v_24554;
v_24555:
    v_24566 = stack[-2];
    goto v_24556;
v_24557:
    goto v_24551;
v_24552:
    goto v_24553;
v_24554:
    goto v_24555;
v_24556:
    v_24566 = list2star(v_24568, v_24567, v_24566);
    env = stack[-3];
    stack[-2] = v_24566;
    v_24566 = stack[0];
    v_24566 = add1(v_24566);
    env = stack[-3];
    stack[0] = v_24566;
    goto v_24534;
v_24533:
    v_24566 = stack[-2];
    v_24566 = Lcompress(nil, v_24566);
        return Lintern(nil, v_24566);
    return onevalue(v_24566);
}



// Code for mk_simpl_map_

static LispObject CC_mk_simpl_map_(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24536, v_24537;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24536 = v_24526;
// end of prologue
    goto v_24533;
v_24529:
    v_24537 = v_24536;
    goto v_24530;
v_24531:
    v_24536 = nil;
    goto v_24532;
v_24533:
    goto v_24529;
v_24530:
    goto v_24531;
v_24532:
    {
        fn = elt(env, 1); // mk_simpl_map_1
        return (*qfn2(fn))(fn, v_24537, v_24536);
    }
}



// Code for mk_dummy_ids

static LispObject CC_mk_dummy_ids(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24567, v_24568;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24526);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_24567 = v_24526;
// end of prologue
    goto v_24537;
v_24533:
    v_24568 = v_24567;
    v_24568 = qcar(v_24568);
    goto v_24534;
v_24535:
    v_24567 = qcdr(v_24567);
    v_24567 = qcar(v_24567);
    goto v_24536;
v_24537:
    goto v_24533;
v_24534:
    goto v_24535;
v_24536:
    fn = elt(env, 4); // intersection
    v_24567 = (*qfn2(fn))(fn, v_24568, v_24567);
    env = stack[-1];
    fn = elt(env, 5); // clean_numid
    v_24567 = (*qfn1(fn))(fn, v_24567);
    env = stack[-1];
    stack[0] = v_24567;
    goto v_24548;
v_24544:
    v_24568 = stack[0];
    goto v_24545;
v_24546:
    v_24567 = elt(env, 1); // dummy
    goto v_24547;
v_24548:
    goto v_24544;
v_24545:
    goto v_24546;
v_24547:
    v_24567 = Lflag(nil, v_24568, v_24567);
    env = stack[-1];
    goto v_24556;
v_24552:
    v_24568 = stack[0];
    goto v_24553;
v_24554:
    v_24567 = elt(env, 2); // reserved
    goto v_24555;
v_24556:
    goto v_24552;
v_24553:
    goto v_24554;
v_24555:
    v_24567 = Lflag(nil, v_24568, v_24567);
    env = stack[-1];
    goto v_24564;
v_24560:
    v_24568 = stack[0];
    goto v_24561;
v_24562:
    v_24567 = qvalue(elt(env, 3)); // dummy_id!*
    goto v_24563;
v_24564:
    goto v_24560;
v_24561:
    goto v_24562;
v_24563:
    fn = elt(env, 6); // union
    v_24567 = (*qfn2(fn))(fn, v_24568, v_24567);
    env = stack[-1];
    qvalue(elt(env, 3)) = v_24567; // dummy_id!*
    v_24567 = nil;
    return onevalue(v_24567);
}



// Code for createtriple

static LispObject CC_createtriple(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24577, v_24578, v_24579;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24526);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_24526;
// end of prologue
    v_24577 = (LispObject)48+TAG_FIXNUM; // 3
    v_24577 = Lmkvect(nil, v_24577);
    env = stack[-3];
    stack[-2] = v_24577;
    goto v_24539;
v_24533:
    v_24579 = stack[-2];
    goto v_24534;
v_24535:
    v_24578 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24536;
v_24537:
    v_24577 = qvalue(elt(env, 1)); // fluidbibasistripleid
    goto v_24538;
v_24539:
    goto v_24533;
v_24534:
    goto v_24535;
v_24536:
    goto v_24537;
v_24538:
    *(LispObject *)((char *)v_24579 + (CELL-TAG_VECTOR) + (((intptr_t)v_24578-TAG_FIXNUM)/(16/CELL))) = v_24577;
    goto v_24549;
v_24543:
    v_24579 = stack[-2];
    goto v_24544;
v_24545:
    v_24578 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24546;
v_24547:
    v_24577 = stack[0];
    goto v_24548;
v_24549:
    goto v_24543;
v_24544:
    goto v_24545;
v_24546:
    goto v_24547;
v_24548:
    *(LispObject *)((char *)v_24579 + (CELL-TAG_VECTOR) + (((intptr_t)v_24578-TAG_FIXNUM)/(16/CELL))) = v_24577;
    goto v_24559;
v_24553:
    v_24579 = stack[-2];
    goto v_24554;
v_24555:
    v_24578 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_24556;
v_24557:
    v_24577 = qvalue(elt(env, 1)); // fluidbibasistripleid
    goto v_24558;
v_24559:
    goto v_24553;
v_24554:
    goto v_24555;
v_24556:
    goto v_24557;
v_24558:
    *(LispObject *)((char *)v_24579 + (CELL-TAG_VECTOR) + (((intptr_t)v_24578-TAG_FIXNUM)/(16/CELL))) = v_24577;
    goto v_24569;
v_24563:
    stack[-1] = stack[-2];
    goto v_24564;
v_24565:
    stack[0] = (LispObject)48+TAG_FIXNUM; // 3
    goto v_24566;
v_24567:
    v_24577 = nil;
    v_24577 = ncons(v_24577);
    env = stack[-3];
    goto v_24568;
v_24569:
    goto v_24563;
v_24564:
    goto v_24565;
v_24566:
    goto v_24567;
v_24568:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_24577;
    v_24577 = qvalue(elt(env, 1)); // fluidbibasistripleid
    v_24577 = (LispObject)((intptr_t)(v_24577) + 0x10);
    qvalue(elt(env, 1)) = v_24577; // fluidbibasistripleid
    v_24577 = stack[-2];
    return onevalue(v_24577);
}



// Code for totalcompareconstants

static LispObject CC_totalcompareconstants(LispObject env,
                         LispObject v_24526, LispObject v_24527)
{
    env = qenv(env);
    LispObject v_24697, v_24698, v_24699;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24527,v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24526,v_24527);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_24527;
    stack[-2] = v_24526;
// end of prologue
    goto v_24537;
v_24533:
    v_24698 = stack[-2];
    goto v_24534;
v_24535:
    v_24697 = stack[-1];
    goto v_24536;
v_24537:
    goto v_24533;
v_24534:
    goto v_24535;
v_24536:
    if (equal(v_24698, v_24697)) goto v_24531;
    else goto v_24532;
v_24531:
    v_24697 = elt(env, 1); // equal
    goto v_24530;
v_24532:
    v_24697 = stack[-2];
    if (!consp(v_24697)) goto v_24545;
    else goto v_24546;
v_24545:
    v_24697 = lisp_true;
    goto v_24544;
v_24546:
    v_24697 = stack[-2];
    v_24697 = qcar(v_24697);
    v_24697 = (consp(v_24697) ? nil : lisp_true);
    goto v_24544;
    v_24697 = nil;
v_24544:
    if (v_24697 == nil) goto v_24542;
    v_24697 = stack[-1];
    if (!consp(v_24697)) goto v_24560;
    else goto v_24561;
v_24560:
    v_24697 = lisp_true;
    goto v_24559;
v_24561:
    v_24697 = stack[-1];
    v_24697 = qcar(v_24697);
    v_24697 = (consp(v_24697) ? nil : lisp_true);
    goto v_24559;
    v_24697 = nil;
v_24559:
    if (v_24697 == nil) goto v_24557;
    goto v_24578;
v_24574:
    v_24697 = stack[-2];
    if (v_24697 == nil) goto v_24581;
    else goto v_24582;
v_24581:
    v_24697 = (LispObject)0+TAG_FIXNUM; // 0
    v_24698 = v_24697;
    goto v_24580;
v_24582:
    v_24697 = stack[-2];
    v_24698 = v_24697;
    goto v_24580;
    v_24698 = nil;
v_24580:
    goto v_24575;
v_24576:
    v_24697 = stack[-1];
    if (v_24697 == nil) goto v_24590;
    else goto v_24591;
v_24590:
    v_24697 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24589;
v_24591:
    v_24697 = stack[-1];
    goto v_24589;
    v_24697 = nil;
v_24589:
    goto v_24577;
v_24578:
    goto v_24574;
v_24575:
    goto v_24576;
v_24577:
    v_24697 = (LispObject)lessp2(v_24698, v_24697);
    v_24697 = v_24697 ? lisp_true : nil;
    env = stack[-4];
    if (v_24697 == nil) goto v_24572;
    v_24697 = elt(env, 2); // less
    goto v_24570;
v_24572:
    v_24697 = elt(env, 3); // greater
    goto v_24570;
    v_24697 = nil;
v_24570:
    goto v_24555;
v_24557:
    v_24697 = elt(env, 2); // less
    goto v_24555;
    v_24697 = nil;
v_24555:
    goto v_24530;
v_24542:
    v_24697 = stack[-1];
    if (!consp(v_24697)) goto v_24608;
    else goto v_24609;
v_24608:
    v_24697 = lisp_true;
    goto v_24607;
v_24609:
    v_24697 = stack[-1];
    v_24697 = qcar(v_24697);
    v_24697 = (consp(v_24697) ? nil : lisp_true);
    goto v_24607;
    v_24697 = nil;
v_24607:
    if (v_24697 == nil) goto v_24605;
    v_24697 = elt(env, 3); // greater
    goto v_24530;
v_24605:
// Binding wukord!*
// FLUIDBIND: reloadenv=4 litvec-offset=4 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 4, -3);
    qvalue(elt(env, 4)) = nil; // wukord!*
// Binding wuvarlist!*
// FLUIDBIND: reloadenv=4 litvec-offset=5 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 5, 0);
    qvalue(elt(env, 5)) = nil; // wuvarlist!*
    goto v_24634;
v_24630:
    v_24697 = stack[-2];
    v_24697 = qcar(v_24697);
    v_24697 = qcar(v_24697);
    v_24698 = qcar(v_24697);
    goto v_24631;
v_24632:
    v_24697 = stack[-1];
    v_24697 = qcar(v_24697);
    v_24697 = qcar(v_24697);
    v_24697 = qcar(v_24697);
    goto v_24633;
v_24634:
    goto v_24630;
v_24631:
    goto v_24632;
v_24633:
    fn = elt(env, 6); // symbollessp
    v_24697 = (*qfn2(fn))(fn, v_24698, v_24697);
    env = stack[-4];
    if (v_24697 == nil) goto v_24628;
    v_24697 = elt(env, 2); // less
    goto v_24624;
v_24628:
    goto v_24651;
v_24647:
    v_24697 = stack[-1];
    v_24697 = qcar(v_24697);
    v_24697 = qcar(v_24697);
    v_24698 = qcar(v_24697);
    goto v_24648;
v_24649:
    v_24697 = stack[-2];
    v_24697 = qcar(v_24697);
    v_24697 = qcar(v_24697);
    v_24697 = qcar(v_24697);
    goto v_24650;
v_24651:
    goto v_24647;
v_24648:
    goto v_24649;
v_24650:
    fn = elt(env, 6); // symbollessp
    v_24697 = (*qfn2(fn))(fn, v_24698, v_24697);
    env = stack[-4];
    if (v_24697 == nil) goto v_24645;
    v_24697 = elt(env, 3); // greater
    goto v_24624;
v_24645:
    goto v_24668;
v_24664:
    v_24697 = stack[-2];
    v_24697 = qcar(v_24697);
    v_24698 = qcdr(v_24697);
    goto v_24665;
v_24666:
    v_24697 = stack[-1];
    v_24697 = qcar(v_24697);
    v_24697 = qcdr(v_24697);
    goto v_24667;
v_24668:
    goto v_24664;
v_24665:
    goto v_24666;
v_24667:
    v_24697 = CC_totalcompareconstants(elt(env, 0), v_24698, v_24697);
    env = stack[-4];
    v_24699 = v_24697;
    goto v_24626;
v_24626:
    goto v_24683;
v_24679:
    v_24698 = v_24699;
    goto v_24680;
v_24681:
    v_24697 = elt(env, 1); // equal
    goto v_24682;
v_24683:
    goto v_24679;
v_24680:
    goto v_24681;
v_24682:
    if (v_24698 == v_24697) goto v_24678;
    v_24697 = v_24699;
    goto v_24624;
v_24678:
    goto v_24692;
v_24688:
    v_24697 = stack[-2];
    v_24698 = qcdr(v_24697);
    goto v_24689;
v_24690:
    v_24697 = stack[-1];
    v_24697 = qcdr(v_24697);
    goto v_24691;
v_24692:
    goto v_24688;
v_24689:
    goto v_24690;
v_24691:
    v_24697 = CC_totalcompareconstants(elt(env, 0), v_24698, v_24697);
v_24624:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_24530;
    v_24697 = nil;
v_24530:
    return onevalue(v_24697);
}



// Code for gigcdsq

static LispObject CC_gigcdsq(LispObject env,
                         LispObject v_24526, LispObject v_24527)
{
    env = qenv(env);
    LispObject v_24600, v_24601;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24527,v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24526,v_24527);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_24527;
    stack[-1] = v_24526;
// end of prologue
    v_24600 = stack[-1];
    if (v_24600 == nil) goto v_24532;
    goto v_24539;
v_24535:
    v_24601 = stack[0];
    goto v_24536;
v_24537:
    v_24600 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24538;
v_24539:
    goto v_24535;
v_24536:
    goto v_24537;
v_24538:
    fn = elt(env, 1); // giintgcd
    v_24600 = (*qfn2(fn))(fn, v_24601, v_24600);
    env = stack[-3];
    stack[-2] = v_24600;
    goto v_24555;
v_24551:
    v_24601 = stack[-2];
    goto v_24552;
v_24553:
    v_24600 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24554;
v_24555:
    goto v_24551;
v_24552:
    goto v_24553;
v_24554:
    if (v_24601 == v_24600) goto v_24550;
    goto v_24563;
v_24559:
    goto v_24569;
v_24565:
    v_24601 = stack[-1];
    goto v_24566;
v_24567:
    v_24600 = stack[-2];
    goto v_24568;
v_24569:
    goto v_24565;
v_24566:
    goto v_24567;
v_24568:
    fn = elt(env, 1); // giintgcd
    v_24601 = (*qfn2(fn))(fn, v_24601, v_24600);
    env = stack[-3];
    stack[-2] = v_24601;
    goto v_24560;
v_24561:
    v_24600 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24562;
v_24563:
    goto v_24559;
v_24560:
    goto v_24561;
v_24562:
    v_24600 = Lneq(nil, v_24601, v_24600);
    env = stack[-3];
    goto v_24548;
v_24550:
    v_24600 = nil;
    goto v_24548;
    v_24600 = nil;
v_24548:
    if (v_24600 == nil) goto v_24546;
    goto v_24581;
v_24577:
    v_24601 = stack[-1];
    goto v_24578;
v_24579:
    v_24600 = stack[-2];
    goto v_24580;
v_24581:
    goto v_24577;
v_24578:
    goto v_24579;
v_24580:
    fn = elt(env, 2); // quotf
    v_24600 = (*qfn2(fn))(fn, v_24601, v_24600);
    env = stack[-3];
    stack[-1] = v_24600;
    goto v_24589;
v_24585:
    v_24601 = stack[0];
    goto v_24586;
v_24587:
    v_24600 = stack[-2];
    goto v_24588;
v_24589:
    goto v_24585;
v_24586:
    goto v_24587;
v_24588:
    fn = elt(env, 2); // quotf
    v_24600 = (*qfn2(fn))(fn, v_24601, v_24600);
    stack[0] = v_24600;
    goto v_24544;
v_24546:
v_24544:
    goto v_24530;
v_24532:
v_24530:
    goto v_24597;
v_24593:
    v_24601 = stack[-1];
    goto v_24594;
v_24595:
    v_24600 = stack[0];
    goto v_24596;
v_24597:
    goto v_24593;
v_24594:
    goto v_24595;
v_24596:
    return cons(v_24601, v_24600);
}



// Code for simpexpt2

static LispObject CC_simpexpt2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25170, v_25171, v_25172;
    LispObject fn;
    LispObject v_24528, v_24527, v_24526;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "simpexpt2");
    va_start(aa, nargs);
    v_24526 = va_arg(aa, LispObject);
    v_24527 = va_arg(aa, LispObject);
    v_24528 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24528,v_24527,v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24526,v_24527,v_24528);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_24528;
    stack[-2] = v_24527;
    stack[-3] = v_24526;
// end of prologue
v_24525:
    stack[0] = nil;
    goto v_24543;
v_24539:
    v_25171 = stack[-3];
    goto v_24540;
v_24541:
    v_25170 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24542;
v_24543:
    goto v_24539;
v_24540:
    goto v_24541;
v_24542:
    if (v_25171 == v_25170) goto v_24537;
    else goto v_24538;
v_24537:
    goto v_24551;
v_24547:
    v_25171 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24548;
v_24549:
    v_25170 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24550;
v_24551:
    goto v_24547;
v_24548:
    goto v_24549;
v_24550:
    return cons(v_25171, v_25170);
v_24538:
    v_25170 = stack[-2];
    v_25170 = qcar(v_25170);
    stack[-4] = v_25170;
    v_25170 = stack[-3];
    v_25170 = Lconsp(nil, v_25170);
    env = stack[-5];
    if (v_25170 == nil) goto v_24559;
    goto v_24574;
v_24570:
    v_25170 = stack[-3];
    v_25171 = qcar(v_25170);
    goto v_24571;
v_24572:
    v_25170 = elt(env, 1); // expt
    goto v_24573;
v_24574:
    goto v_24570;
v_24571:
    goto v_24572;
v_24573:
    if (v_25171 == v_25170) goto v_24568;
    else goto v_24569;
v_24568:
    v_25170 = qvalue(elt(env, 2)); // !*precise_complex
    v_25170 = (v_25170 == nil ? lisp_true : nil);
    goto v_24567;
v_24569:
    v_25170 = nil;
    goto v_24567;
    v_25170 = nil;
v_24567:
    if (v_25170 == nil) goto v_24565;
    goto v_24588;
v_24584:
    v_25170 = stack[-3];
    v_25170 = qcdr(v_25170);
    v_25170 = qcdr(v_25170);
    v_25170 = qcar(v_25170);
    fn = elt(env, 14); // simp
    v_25171 = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    stack[-4] = v_25171;
    goto v_24585;
v_24586:
    v_25170 = stack[-2];
    goto v_24587;
v_24588:
    goto v_24584;
v_24585:
    goto v_24586;
v_24587:
    fn = elt(env, 15); // multsq
    v_25170 = (*qfn2(fn))(fn, v_25171, v_25170);
    env = stack[-5];
    stack[-2] = v_25170;
    v_25170 = qvalue(elt(env, 3)); // !*precise
    if (v_25170 == nil) goto v_24598;
    v_25170 = stack[-4];
    v_25170 = qcar(v_25170);
    if (is_number(v_25170)) goto v_24602;
    else goto v_24598;
v_24602:
    v_25170 = stack[-4];
    v_25170 = qcar(v_25170);
    v_25170 = Levenp(nil, v_25170);
    env = stack[-5];
    if (v_25170 == nil) goto v_24598;
    goto v_24614;
v_24610:
    v_25171 = elt(env, 4); // abs
    goto v_24611;
v_24612:
    v_25170 = stack[-3];
    v_25170 = qcdr(v_25170);
    v_25170 = qcar(v_25170);
    goto v_24613;
v_24614:
    goto v_24610;
v_24611:
    goto v_24612;
v_24613:
    v_25170 = list2(v_25171, v_25170);
    env = stack[-5];
    stack[-3] = v_25170;
    goto v_24596;
v_24598:
    v_25170 = stack[-3];
    v_25170 = qcdr(v_25170);
    v_25170 = qcar(v_25170);
    stack[-3] = v_25170;
    goto v_24596;
v_24596:
    goto v_24631;
v_24625:
    v_25172 = stack[-3];
    goto v_24626;
v_24627:
    v_25171 = stack[-2];
    goto v_24628;
v_24629:
    v_25170 = stack[-1];
    goto v_24630;
v_24631:
    goto v_24625;
v_24626:
    goto v_24627;
v_24628:
    goto v_24629;
v_24630:
    {
        fn = elt(env, 16); // simpexpt1
        return (*qfnn(fn))(fn, 3, v_25172, v_25171, v_25170);
    }
v_24565:
    goto v_24645;
v_24641:
    v_25170 = stack[-3];
    v_25171 = qcar(v_25170);
    goto v_24642;
v_24643:
    v_25170 = elt(env, 5); // sqrt
    goto v_24644;
v_24645:
    goto v_24641;
v_24642:
    goto v_24643;
v_24644:
    if (v_25171 == v_25170) goto v_24639;
    else goto v_24640;
v_24639:
    v_25170 = qvalue(elt(env, 6)); // !*keepsqrts
    v_25170 = (v_25170 == nil ? lisp_true : nil);
    goto v_24638;
v_24640:
    v_25170 = nil;
    goto v_24638;
    v_25170 = nil;
v_24638:
    if (v_25170 == nil) goto v_24636;
    goto v_24661;
v_24655:
    v_25170 = stack[-3];
    v_25170 = qcdr(v_25170);
    stack[0] = qcar(v_25170);
    goto v_24656;
v_24657:
    goto v_24670;
v_24666:
    goto v_24676;
v_24672:
    v_25171 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24673;
v_24674:
    v_25170 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_24675;
v_24676:
    goto v_24672;
v_24673:
    goto v_24674;
v_24675:
    v_25171 = cons(v_25171, v_25170);
    env = stack[-5];
    goto v_24667;
v_24668:
    v_25170 = stack[-2];
    goto v_24669;
v_24670:
    goto v_24666;
v_24667:
    goto v_24668;
v_24669:
    fn = elt(env, 15); // multsq
    v_25171 = (*qfn2(fn))(fn, v_25171, v_25170);
    env = stack[-5];
    goto v_24658;
v_24659:
    v_25170 = stack[-1];
    goto v_24660;
v_24661:
    goto v_24655;
v_24656:
    goto v_24657;
v_24658:
    goto v_24659;
v_24660:
    stack[-3] = stack[0];
    stack[-2] = v_25171;
    stack[-1] = v_25170;
    goto v_24525;
v_24636:
    goto v_24691;
v_24687:
    v_25170 = stack[-3];
    v_25171 = qcar(v_25170);
    goto v_24688;
v_24689:
    v_25170 = elt(env, 7); // times
    goto v_24690;
v_24691:
    goto v_24687;
v_24688:
    goto v_24689;
v_24690:
    if (v_25171 == v_25170) goto v_24685;
    else goto v_24686;
v_24685:
    v_25170 = qvalue(elt(env, 3)); // !*precise
    if (v_25170 == nil) goto v_24697;
    else goto v_24698;
v_24697:
    v_25170 = qvalue(elt(env, 8)); // !*modular
    v_25170 = (v_25170 == nil ? lisp_true : nil);
    goto v_24696;
v_24698:
    v_25170 = nil;
    goto v_24696;
    v_25170 = nil;
v_24696:
    goto v_24684;
v_24686:
    v_25170 = nil;
    goto v_24684;
    v_25170 = nil;
v_24684:
    if (v_25170 == nil) goto v_24682;
    goto v_24713;
v_24709:
    v_25171 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24710;
v_24711:
    v_25170 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24712;
v_24713:
    goto v_24709;
v_24710:
    goto v_24711;
v_24712:
    v_25170 = cons(v_25171, v_25170);
    env = stack[-5];
    stack[-4] = v_25170;
    v_25170 = stack[-3];
    v_25170 = qcdr(v_25170);
    stack[0] = v_25170;
v_24719:
    v_25170 = stack[0];
    if (v_25170 == nil) goto v_24724;
    else goto v_24725;
v_24724:
    goto v_24718;
v_24725:
    v_25170 = stack[0];
    v_25170 = qcar(v_25170);
    goto v_24736;
v_24732:
    goto v_24744;
v_24738:
    v_25172 = v_25170;
    goto v_24739;
v_24740:
    v_25171 = stack[-2];
    goto v_24741;
v_24742:
    v_25170 = stack[-1];
    goto v_24743;
v_24744:
    goto v_24738;
v_24739:
    goto v_24740;
v_24741:
    goto v_24742;
v_24743:
    fn = elt(env, 16); // simpexpt1
    v_25171 = (*qfnn(fn))(fn, 3, v_25172, v_25171, v_25170);
    env = stack[-5];
    goto v_24733;
v_24734:
    v_25170 = stack[-4];
    goto v_24735;
v_24736:
    goto v_24732;
v_24733:
    goto v_24734;
v_24735:
    fn = elt(env, 15); // multsq
    v_25170 = (*qfn2(fn))(fn, v_25171, v_25170);
    env = stack[-5];
    stack[-4] = v_25170;
    v_25170 = stack[0];
    v_25170 = qcdr(v_25170);
    stack[0] = v_25170;
    goto v_24719;
v_24718:
    v_25170 = stack[-4];
    goto v_24534;
v_24682:
    goto v_24762;
v_24758:
    v_25170 = stack[-3];
    v_25171 = qcar(v_25170);
    goto v_24759;
v_24760:
    v_25170 = elt(env, 7); // times
    goto v_24761;
v_24762:
    goto v_24758;
v_24759:
    goto v_24760;
v_24761:
    if (v_25171 == v_25170) goto v_24756;
    else goto v_24757;
v_24756:
    v_25170 = stack[-3];
    v_25170 = qcdr(v_25170);
    fn = elt(env, 17); // split!-sign
    v_25170 = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    stack[0] = v_25170;
    if (v_25170 == nil) goto v_24768;
    else goto v_24769;
v_24768:
    v_25170 = nil;
    goto v_24767;
v_24769:
    v_25170 = stack[0];
    v_25170 = qcar(v_25170);
    goto v_24767;
    v_25170 = nil;
v_24767:
    goto v_24755;
v_24757:
    v_25170 = nil;
    goto v_24755;
    v_25170 = nil;
v_24755:
    if (v_25170 == nil) goto v_24753;
    goto v_24788;
v_24782:
    goto v_24795;
v_24791:
    v_25170 = stack[0];
    v_25170 = qcdr(v_25170);
    v_25171 = qcar(v_25170);
    goto v_24792;
v_24793:
    v_25170 = stack[0];
    v_25170 = qcdr(v_25170);
    v_25170 = qcdr(v_25170);
    goto v_24794;
v_24795:
    goto v_24791;
v_24792:
    goto v_24793;
v_24794:
    v_25170 = Lappend(nil, v_25171, v_25170);
    env = stack[-5];
    fn = elt(env, 18); // retimes
    v_25172 = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    goto v_24783;
v_24784:
    v_25171 = stack[-2];
    goto v_24785;
v_24786:
    v_25170 = stack[-1];
    goto v_24787;
v_24788:
    goto v_24782;
v_24783:
    goto v_24784;
v_24785:
    goto v_24786;
v_24787:
    fn = elt(env, 16); // simpexpt1
    v_25170 = (*qfnn(fn))(fn, 3, v_25172, v_25171, v_25170);
    env = stack[-5];
    stack[-4] = v_25170;
    v_25170 = stack[0];
    v_25170 = qcar(v_25170);
    stack[0] = v_25170;
v_24807:
    v_25170 = stack[0];
    if (v_25170 == nil) goto v_24812;
    else goto v_24813;
v_24812:
    goto v_24806;
v_24813:
    v_25170 = stack[0];
    v_25170 = qcar(v_25170);
    goto v_24824;
v_24820:
    goto v_24832;
v_24826:
    v_25172 = v_25170;
    goto v_24827;
v_24828:
    v_25171 = stack[-2];
    goto v_24829;
v_24830:
    v_25170 = stack[-1];
    goto v_24831;
v_24832:
    goto v_24826;
v_24827:
    goto v_24828;
v_24829:
    goto v_24830;
v_24831:
    fn = elt(env, 16); // simpexpt1
    v_25171 = (*qfnn(fn))(fn, 3, v_25172, v_25171, v_25170);
    env = stack[-5];
    goto v_24821;
v_24822:
    v_25170 = stack[-4];
    goto v_24823;
v_24824:
    goto v_24820;
v_24821:
    goto v_24822;
v_24823:
    fn = elt(env, 15); // multsq
    v_25170 = (*qfn2(fn))(fn, v_25171, v_25170);
    env = stack[-5];
    stack[-4] = v_25170;
    v_25170 = stack[0];
    v_25170 = qcdr(v_25170);
    stack[0] = v_25170;
    goto v_24807;
v_24806:
    v_25170 = stack[-4];
    goto v_24534;
v_24753:
    goto v_24850;
v_24846:
    v_25170 = stack[-3];
    v_25171 = qcar(v_25170);
    goto v_24847;
v_24848:
    v_25170 = elt(env, 9); // quotient
    goto v_24849;
v_24850:
    goto v_24846;
v_24847:
    goto v_24848;
v_24849:
    if (v_25171 == v_25170) goto v_24844;
    else goto v_24845;
v_24844:
    v_25170 = qvalue(elt(env, 3)); // !*precise
    if (v_25170 == nil) goto v_24856;
    else goto v_24857;
v_24856:
    v_25170 = lisp_true;
    goto v_24855;
v_24857:
    v_25170 = stack[-3];
    v_25170 = qcdr(v_25170);
    v_25170 = qcdr(v_25170);
    v_25170 = qcar(v_25170);
    fn = elt(env, 19); // posnump
    v_25170 = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    if (v_25170 == nil) goto v_24864;
    else goto v_24865;
v_24864:
    v_25170 = nil;
    goto v_24863;
v_24865:
    v_25170 = stack[-2];
    fn = elt(env, 20); // prepsq
    v_25170 = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    fn = elt(env, 19); // posnump
    v_25170 = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    goto v_24863;
    v_25170 = nil;
v_24863:
    goto v_24855;
    v_25170 = nil;
v_24855:
    goto v_24843;
v_24845:
    v_25170 = nil;
    goto v_24843;
    v_25170 = nil;
v_24843:
    if (v_25170 == nil) goto v_24841;
    v_25170 = stack[-1];
    if (v_25170 == nil) goto v_24886;
    else goto v_24887;
v_24886:
    v_25170 = qvalue(elt(env, 10)); // !*mcd
    goto v_24885;
v_24887:
    v_25170 = nil;
    goto v_24885;
    v_25170 = nil;
v_24885:
    if (v_25170 == nil) goto v_24883;
    goto v_24900;
v_24894:
    v_25170 = stack[-3];
    fn = elt(env, 21); // simp!*
    v_25170 = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    fn = elt(env, 20); // prepsq
    v_25172 = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    goto v_24895;
v_24896:
    v_25171 = stack[-2];
    goto v_24897;
v_24898:
    v_25170 = lisp_true;
    goto v_24899;
v_24900:
    goto v_24894;
v_24895:
    goto v_24896;
v_24897:
    goto v_24898;
v_24899:
    {
        fn = elt(env, 16); // simpexpt1
        return (*qfnn(fn))(fn, 3, v_25172, v_25171, v_25170);
    }
v_24883:
    v_25170 = stack[-2];
    fn = elt(env, 20); // prepsq
    v_25170 = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    stack[-2] = v_25170;
    goto v_24913;
v_24909:
    goto v_24920;
v_24916:
    v_25170 = stack[-3];
    v_25170 = qcdr(v_25170);
    v_25171 = qcar(v_25170);
    goto v_24917;
v_24918:
    v_25170 = stack[-2];
    goto v_24919;
v_24920:
    goto v_24916;
v_24917:
    goto v_24918;
v_24919:
    v_25170 = list2(v_25171, v_25170);
    env = stack[-5];
    fn = elt(env, 22); // simpexpt
    stack[0] = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    goto v_24910;
v_24911:
    goto v_24931;
v_24927:
    v_25170 = stack[-3];
    v_25170 = qcdr(v_25170);
    v_25170 = qcdr(v_25170);
    v_25171 = qcar(v_25170);
    goto v_24928;
v_24929:
    v_25170 = stack[-2];
    goto v_24930;
v_24931:
    goto v_24927;
v_24928:
    goto v_24929;
v_24930:
    v_25170 = list2(v_25171, v_25170);
    env = stack[-5];
    fn = elt(env, 22); // simpexpt
    v_25170 = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    goto v_24912;
v_24913:
    goto v_24909;
v_24910:
    goto v_24911;
v_24912:
    {
        LispObject v_25178 = stack[0];
        fn = elt(env, 23); // quotsq
        return (*qfn2(fn))(fn, v_25178, v_25170);
    }
v_24841:
    goto v_24947;
v_24943:
    v_25170 = stack[-3];
    v_25171 = qcar(v_25170);
    goto v_24944;
v_24945:
    v_25170 = elt(env, 11); // minus
    goto v_24946;
v_24947:
    goto v_24943;
v_24944:
    goto v_24945;
v_24946:
    if (v_25171 == v_25170) goto v_24941;
    else goto v_24942;
v_24941:
    v_25170 = qvalue(elt(env, 3)); // !*precise
    if (v_25170 == nil) goto v_24953;
    else goto v_24954;
v_24953:
    goto v_24960;
v_24956:
    v_25170 = stack[-3];
    v_25170 = qcdr(v_25170);
    v_25171 = qcar(v_25170);
    goto v_24957;
v_24958:
    v_25170 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24959;
v_24960:
    goto v_24956;
v_24957:
    goto v_24958;
v_24959:
    v_25170 = (v_25171 == v_25170 ? lisp_true : nil);
    v_25170 = (v_25170 == nil ? lisp_true : nil);
    goto v_24952;
v_24954:
    v_25170 = nil;
    goto v_24952;
    v_25170 = nil;
v_24952:
    goto v_24940;
v_24942:
    v_25170 = nil;
    goto v_24940;
    v_25170 = nil;
v_24940:
    if (v_25170 == nil) goto v_24938;
    v_25170 = stack[-2];
    fn = elt(env, 20); // prepsq
    v_25170 = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    stack[-1] = v_25170;
    goto v_24981;
v_24977:
    goto v_24988;
v_24984:
    v_25171 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_24985;
v_24986:
    v_25170 = stack[-1];
    goto v_24987;
v_24988:
    goto v_24984;
v_24985:
    goto v_24986;
v_24987:
    v_25170 = list2(v_25171, v_25170);
    env = stack[-5];
    fn = elt(env, 22); // simpexpt
    stack[0] = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    goto v_24978;
v_24979:
    goto v_24997;
v_24993:
    v_25170 = stack[-3];
    v_25170 = qcdr(v_25170);
    v_25171 = qcar(v_25170);
    goto v_24994;
v_24995:
    v_25170 = stack[-1];
    goto v_24996;
v_24997:
    goto v_24993;
v_24994:
    goto v_24995;
v_24996:
    v_25170 = list2(v_25171, v_25170);
    env = stack[-5];
    fn = elt(env, 22); // simpexpt
    v_25170 = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    goto v_24980;
v_24981:
    goto v_24977;
v_24978:
    goto v_24979;
v_24980:
    {
        LispObject v_25179 = stack[0];
        fn = elt(env, 15); // multsq
        return (*qfn2(fn))(fn, v_25179, v_25170);
    }
v_24938:
    goto v_24557;
v_24559:
v_24557:
    v_25170 = stack[-1];
    if (v_25170 == nil) goto v_25004;
    else goto v_25005;
v_25004:
    v_25170 = qvalue(elt(env, 12)); // dmode!*
    if (v_25170 == nil) goto v_25009;
    v_25170 = stack[-3];
    if (symbolp(v_25170)) goto v_25014;
    else goto v_25009;
v_25014:
    goto v_25022;
v_25018:
    v_25171 = stack[-3];
    goto v_25019;
v_25020:
    v_25170 = qvalue(elt(env, 12)); // dmode!*
    goto v_25021;
v_25022:
    goto v_25018;
v_25019:
    goto v_25020;
v_25021:
    v_25170 = get(v_25171, v_25170);
    env = stack[-5];
    if (v_25170 == nil) goto v_25009;
    goto v_25010;
v_25009:
    v_25170 = stack[-3];
    fn = elt(env, 21); // simp!*
    v_25170 = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    fn = elt(env, 20); // prepsq
    v_25170 = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    stack[-3] = v_25170;
    goto v_25008;
v_25010:
v_25008:
    goto v_25035;
v_25029:
    v_25172 = stack[-3];
    goto v_25030;
v_25031:
    v_25171 = stack[-2];
    goto v_25032;
v_25033:
    v_25170 = lisp_true;
    goto v_25034;
v_25035:
    goto v_25029;
v_25030:
    goto v_25031;
v_25032:
    goto v_25033;
v_25034:
    {
        fn = elt(env, 16); // simpexpt1
        return (*qfnn(fn))(fn, 3, v_25172, v_25171, v_25170);
    }
v_25005:
    v_25170 = stack[-3];
    if (is_number(v_25170)) goto v_25041;
    else goto v_25040;
v_25041:
    v_25170 = stack[-3];
    v_25170 = (LispObject)zerop(v_25170);
    v_25170 = v_25170 ? lisp_true : nil;
    env = stack[-5];
    if (v_25170 == nil) goto v_25040;
    goto v_25051;
v_25047:
    v_25171 = nil;
    goto v_25048;
v_25049:
    v_25170 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25050;
v_25051:
    goto v_25047;
v_25048:
    goto v_25049;
v_25050:
    return cons(v_25171, v_25170);
v_25040:
    v_25170 = stack[-4];
    if (is_number(v_25170)) goto v_25055;
    v_25170 = stack[-4];
    fn = elt(env, 24); // prepf
    v_25170 = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    stack[-4] = v_25170;
    goto v_25003;
v_25055:
v_25003:
    v_25170 = stack[-2];
    v_25170 = qcdr(v_25170);
    fn = elt(env, 24); // prepf
    v_25170 = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    stack[-2] = v_25170;
    goto v_25071;
v_25067:
    v_25171 = stack[-4];
    goto v_25068;
v_25069:
    v_25170 = qvalue(elt(env, 13)); // frlis!*
    goto v_25070;
v_25071:
    goto v_25067;
v_25068:
    goto v_25069;
v_25070:
    v_25170 = Lmemq(nil, v_25171, v_25170);
    if (v_25170 == nil) goto v_25065;
    goto v_25080;
v_25076:
    v_25171 = stack[-2];
    goto v_25077;
v_25078:
    v_25170 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25079;
v_25080:
    goto v_25076;
v_25077:
    goto v_25078;
v_25079:
    if (v_25171 == v_25170) goto v_25075;
    else goto v_25065;
v_25075:
    goto v_25088;
v_25084:
    goto v_25097;
v_25091:
    v_25172 = stack[-3];
    goto v_25092;
v_25093:
    v_25171 = stack[-4];
    goto v_25094;
v_25095:
    v_25170 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25096;
v_25097:
    goto v_25091;
v_25092:
    goto v_25093;
v_25094:
    goto v_25095;
v_25096:
    v_25170 = acons(v_25172, v_25171, v_25170);
    env = stack[-5];
    v_25171 = ncons(v_25170);
    goto v_25085;
v_25086:
    v_25170 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25087;
v_25088:
    goto v_25084;
v_25085:
    goto v_25086;
v_25087:
    return cons(v_25171, v_25170);
v_25065:
    v_25170 = qvalue(elt(env, 10)); // !*mcd
    if (v_25170 == nil) goto v_25106;
    else goto v_25104;
v_25106:
    v_25170 = stack[-4];
    if (is_number(v_25170)) goto v_25112;
    v_25170 = lisp_true;
    goto v_25110;
v_25112:
    goto v_25125;
v_25121:
    v_25171 = stack[-2];
    goto v_25122;
v_25123:
    v_25170 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25124;
v_25125:
    goto v_25121;
v_25122:
    goto v_25123;
v_25124:
    if (v_25171 == v_25170) goto v_25120;
    v_25170 = lisp_true;
    goto v_25118;
v_25120:
    v_25170 = stack[-3];
    if (!consp(v_25170)) goto v_25133;
    else goto v_25134;
v_25133:
    v_25170 = lisp_true;
    goto v_25132;
v_25134:
    goto v_25144;
v_25140:
    v_25170 = stack[-3];
    fn = elt(env, 21); // simp!*
    v_25170 = (*qfn1(fn))(fn, v_25170);
    env = stack[-5];
    v_25171 = qcdr(v_25170);
    goto v_25141;
v_25142:
    v_25170 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25143;
v_25144:
    goto v_25140;
v_25141:
    goto v_25142;
v_25143:
    v_25170 = Lneq(nil, v_25171, v_25170);
    env = stack[-5];
    goto v_25132;
    v_25170 = nil;
v_25132:
    goto v_25118;
    v_25170 = nil;
v_25118:
    goto v_25110;
    v_25170 = nil;
v_25110:
    if (v_25170 == nil) goto v_25108;
    else goto v_25104;
v_25108:
    goto v_25105;
v_25104:
    goto v_25156;
v_25150:
    v_25172 = stack[-3];
    goto v_25151;
v_25152:
    v_25171 = stack[-4];
    goto v_25153;
v_25154:
    v_25170 = stack[-2];
    goto v_25155;
v_25156:
    goto v_25150;
v_25151:
    goto v_25152;
v_25153:
    goto v_25154;
v_25155:
    {
        fn = elt(env, 25); // simpx1
        return (*qfnn(fn))(fn, 3, v_25172, v_25171, v_25170);
    }
v_25105:
    goto v_25167;
v_25163:
    v_25171 = stack[-3];
    goto v_25164;
v_25165:
    v_25170 = stack[-4];
    goto v_25166;
v_25167:
    goto v_25163;
v_25164:
    goto v_25165;
v_25166:
    {
        fn = elt(env, 26); // mksq
        return (*qfn2(fn))(fn, v_25171, v_25170);
    }
    v_25170 = nil;
v_24534:
    return onevalue(v_25170);
}



// Code for mk!+resimp!+mat

static LispObject CC_mkLresimpLmat(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24656;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24526);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    v_24656 = v_24526;
// end of prologue
    stack[-7] = v_24656;
    v_24656 = stack[-7];
    if (v_24656 == nil) goto v_24542;
    else goto v_24543;
v_24542:
    v_24656 = nil;
    goto v_24537;
v_24543:
    v_24656 = stack[-7];
    v_24656 = qcar(v_24656);
    stack[-3] = v_24656;
    v_24656 = stack[-3];
    if (v_24656 == nil) goto v_24559;
    else goto v_24560;
v_24559:
    v_24656 = nil;
    goto v_24554;
v_24560:
    v_24656 = stack[-3];
    v_24656 = qcar(v_24656);
    fn = elt(env, 1); // resimp
    v_24656 = (*qfn1(fn))(fn, v_24656);
    env = stack[-8];
    v_24656 = ncons(v_24656);
    env = stack[-8];
    stack[-1] = v_24656;
    stack[-2] = v_24656;
v_24555:
    v_24656 = stack[-3];
    v_24656 = qcdr(v_24656);
    stack[-3] = v_24656;
    v_24656 = stack[-3];
    if (v_24656 == nil) goto v_24573;
    else goto v_24574;
v_24573:
    v_24656 = stack[-2];
    goto v_24554;
v_24574:
    goto v_24582;
v_24578:
    stack[0] = stack[-1];
    goto v_24579;
v_24580:
    v_24656 = stack[-3];
    v_24656 = qcar(v_24656);
    fn = elt(env, 1); // resimp
    v_24656 = (*qfn1(fn))(fn, v_24656);
    env = stack[-8];
    v_24656 = ncons(v_24656);
    env = stack[-8];
    goto v_24581;
v_24582:
    goto v_24578;
v_24579:
    goto v_24580;
v_24581:
    v_24656 = Lrplacd(nil, stack[0], v_24656);
    env = stack[-8];
    v_24656 = stack[-1];
    v_24656 = qcdr(v_24656);
    stack[-1] = v_24656;
    goto v_24555;
v_24554:
    v_24656 = ncons(v_24656);
    env = stack[-8];
    stack[-5] = v_24656;
    stack[-6] = v_24656;
v_24538:
    v_24656 = stack[-7];
    v_24656 = qcdr(v_24656);
    stack[-7] = v_24656;
    v_24656 = stack[-7];
    if (v_24656 == nil) goto v_24596;
    else goto v_24597;
v_24596:
    v_24656 = stack[-6];
    goto v_24537;
v_24597:
    goto v_24605;
v_24601:
    stack[-4] = stack[-5];
    goto v_24602;
v_24603:
    v_24656 = stack[-7];
    v_24656 = qcar(v_24656);
    stack[-3] = v_24656;
    v_24656 = stack[-3];
    if (v_24656 == nil) goto v_24620;
    else goto v_24621;
v_24620:
    v_24656 = nil;
    goto v_24615;
v_24621:
    v_24656 = stack[-3];
    v_24656 = qcar(v_24656);
    fn = elt(env, 1); // resimp
    v_24656 = (*qfn1(fn))(fn, v_24656);
    env = stack[-8];
    v_24656 = ncons(v_24656);
    env = stack[-8];
    stack[-1] = v_24656;
    stack[-2] = v_24656;
v_24616:
    v_24656 = stack[-3];
    v_24656 = qcdr(v_24656);
    stack[-3] = v_24656;
    v_24656 = stack[-3];
    if (v_24656 == nil) goto v_24634;
    else goto v_24635;
v_24634:
    v_24656 = stack[-2];
    goto v_24615;
v_24635:
    goto v_24643;
v_24639:
    stack[0] = stack[-1];
    goto v_24640;
v_24641:
    v_24656 = stack[-3];
    v_24656 = qcar(v_24656);
    fn = elt(env, 1); // resimp
    v_24656 = (*qfn1(fn))(fn, v_24656);
    env = stack[-8];
    v_24656 = ncons(v_24656);
    env = stack[-8];
    goto v_24642;
v_24643:
    goto v_24639;
v_24640:
    goto v_24641;
v_24642:
    v_24656 = Lrplacd(nil, stack[0], v_24656);
    env = stack[-8];
    v_24656 = stack[-1];
    v_24656 = qcdr(v_24656);
    stack[-1] = v_24656;
    goto v_24616;
v_24615:
    v_24656 = ncons(v_24656);
    env = stack[-8];
    goto v_24604;
v_24605:
    goto v_24601;
v_24602:
    goto v_24603;
v_24604:
    v_24656 = Lrplacd(nil, stack[-4], v_24656);
    env = stack[-8];
    v_24656 = stack[-5];
    v_24656 = qcdr(v_24656);
    stack[-5] = v_24656;
    goto v_24538;
v_24537:
    return onevalue(v_24656);
}



// Code for talp_invtscsimpl

static LispObject CC_talp_invtscsimpl(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24667, v_24668, v_24669;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24526);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_24526;
// end of prologue
    v_24667 = stack[0];
    fn = elt(env, 4); // talp_rnf
    v_24667 = (*qfn1(fn))(fn, v_24667);
    env = stack[-5];
    stack[0] = v_24667;
    v_24667 = stack[0];
    if (!consp(v_24667)) goto v_24535;
    else goto v_24536;
v_24535:
    v_24667 = stack[0];
    goto v_24530;
v_24536:
    v_24667 = stack[0];
    fn = elt(env, 5); // talp_atfp
    v_24667 = (*qfn1(fn))(fn, v_24667);
    env = stack[-5];
    if (v_24667 == nil) goto v_24542;
    v_24667 = stack[0];
    fn = elt(env, 6); // talp_invtscc
    v_24667 = (*qfn1(fn))(fn, v_24667);
    env = stack[-5];
    if (v_24667 == nil) goto v_24548;
    v_24667 = stack[0];
    fn = elt(env, 7); // talp_simpat
    v_24667 = (*qfn1(fn))(fn, v_24667);
    env = stack[-5];
    fn = elt(env, 8); // talp_invtscsimplat
    v_24667 = (*qfn1(fn))(fn, v_24667);
    env = stack[-5];
    {
        fn = elt(env, 4); // talp_rnf
        return (*qfn1(fn))(fn, v_24667);
    }
v_24548:
    v_24667 = stack[0];
    {
        fn = elt(env, 7); // talp_simpat
        return (*qfn1(fn))(fn, v_24667);
    }
    goto v_24540;
v_24542:
v_24540:
    v_24667 = stack[0];
    fn = elt(env, 9); // talp_op
    v_24667 = (*qfn1(fn))(fn, v_24667);
    env = stack[-5];
    v_24669 = v_24667;
    goto v_24573;
v_24569:
    v_24668 = v_24669;
    goto v_24570;
v_24571:
    v_24667 = elt(env, 1); // or
    goto v_24572;
v_24573:
    goto v_24569;
v_24570:
    goto v_24571;
v_24572:
    if (v_24668 == v_24667) goto v_24567;
    else goto v_24568;
v_24567:
    v_24667 = lisp_true;
    goto v_24566;
v_24568:
    goto v_24583;
v_24579:
    v_24668 = v_24669;
    goto v_24580;
v_24581:
    v_24667 = elt(env, 2); // and
    goto v_24582;
v_24583:
    goto v_24579;
v_24580:
    goto v_24581;
v_24582:
    v_24667 = (v_24668 == v_24667 ? lisp_true : nil);
    goto v_24566;
    v_24667 = nil;
v_24566:
    if (v_24667 == nil) goto v_24564;
    goto v_24593;
v_24589:
    stack[-4] = v_24669;
    goto v_24590;
v_24591:
    v_24667 = stack[0];
    fn = elt(env, 10); // talp_argl
    v_24667 = (*qfn1(fn))(fn, v_24667);
    env = stack[-5];
    stack[-3] = v_24667;
    v_24667 = stack[-3];
    if (v_24667 == nil) goto v_24605;
    else goto v_24606;
v_24605:
    v_24667 = nil;
    goto v_24599;
v_24606:
    v_24667 = stack[-3];
    v_24667 = qcar(v_24667);
    v_24667 = CC_talp_invtscsimpl(elt(env, 0), v_24667);
    env = stack[-5];
    v_24667 = ncons(v_24667);
    env = stack[-5];
    stack[-1] = v_24667;
    stack[-2] = v_24667;
v_24600:
    v_24667 = stack[-3];
    v_24667 = qcdr(v_24667);
    stack[-3] = v_24667;
    v_24667 = stack[-3];
    if (v_24667 == nil) goto v_24619;
    else goto v_24620;
v_24619:
    v_24667 = stack[-2];
    goto v_24599;
v_24620:
    goto v_24628;
v_24624:
    stack[0] = stack[-1];
    goto v_24625;
v_24626:
    v_24667 = stack[-3];
    v_24667 = qcar(v_24667);
    v_24667 = CC_talp_invtscsimpl(elt(env, 0), v_24667);
    env = stack[-5];
    v_24667 = ncons(v_24667);
    env = stack[-5];
    goto v_24627;
v_24628:
    goto v_24624;
v_24625:
    goto v_24626;
v_24627:
    v_24667 = Lrplacd(nil, stack[0], v_24667);
    env = stack[-5];
    v_24667 = stack[-1];
    v_24667 = qcdr(v_24667);
    stack[-1] = v_24667;
    goto v_24600;
v_24599:
    goto v_24592;
v_24593:
    goto v_24589;
v_24590:
    goto v_24591;
v_24592:
    v_24667 = cons(stack[-4], v_24667);
    env = stack[-5];
    {
        fn = elt(env, 4); // talp_rnf
        return (*qfn1(fn))(fn, v_24667);
    }
v_24564:
    goto v_24644;
v_24640:
    v_24668 = v_24669;
    goto v_24641;
v_24642:
    v_24667 = elt(env, 3); // (ex all)
    goto v_24643;
v_24644:
    goto v_24640;
v_24641:
    goto v_24642;
v_24643:
    v_24667 = Lmemq(nil, v_24668, v_24667);
    if (v_24667 == nil) goto v_24639;
    goto v_24656;
v_24650:
    stack[-2] = v_24669;
    goto v_24651;
v_24652:
    v_24667 = stack[0];
    v_24667 = qcdr(v_24667);
    stack[-1] = qcar(v_24667);
    goto v_24653;
v_24654:
    v_24667 = stack[0];
    v_24667 = qcdr(v_24667);
    v_24667 = qcdr(v_24667);
    v_24667 = qcar(v_24667);
    v_24667 = CC_talp_invtscsimpl(elt(env, 0), v_24667);
    env = stack[-5];
    v_24667 = ncons(v_24667);
    env = stack[-5];
    goto v_24655;
v_24656:
    goto v_24650;
v_24651:
    goto v_24652;
v_24653:
    goto v_24654;
v_24655:
    v_24667 = list2star(stack[-2], stack[-1], v_24667);
    env = stack[-5];
    {
        fn = elt(env, 4); // talp_rnf
        return (*qfn1(fn))(fn, v_24667);
    }
v_24639:
    v_24667 = nil;
v_24530:
    return onevalue(v_24667);
}



// Code for conditionrd

static LispObject CC_conditionrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24562, v_24563, v_24564;
    LispObject fn;
    argcheck(nargs, 0, "conditionrd");
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
    fn = elt(env, 5); // mathml
    v_24562 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_24562;
    fn = elt(env, 6); // lex
    v_24562 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_24540;
v_24536:
    v_24563 = qvalue(elt(env, 1)); // char
    goto v_24537;
v_24538:
    v_24562 = elt(env, 2); // (!/ c o n d i t i o n)
    goto v_24539;
v_24540:
    goto v_24536;
v_24537:
    goto v_24538;
v_24539:
    if (equal(v_24563, v_24562)) goto v_24535;
    goto v_24548;
v_24544:
    v_24563 = elt(env, 3); // "</condition>"
    goto v_24545;
v_24546:
    v_24562 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_24547;
v_24548:
    goto v_24544;
v_24545:
    goto v_24546;
v_24547:
    fn = elt(env, 7); // errorml
    v_24562 = (*qfn2(fn))(fn, v_24563, v_24562);
    env = stack[-1];
    goto v_24533;
v_24535:
v_24533:
    goto v_24558;
v_24552:
    v_24564 = elt(env, 4); // condition
    goto v_24553;
v_24554:
    v_24563 = stack[0];
    goto v_24555;
v_24556:
    v_24562 = nil;
    goto v_24557;
v_24558:
    goto v_24552;
v_24553:
    goto v_24554;
v_24555:
    goto v_24556;
v_24557:
    return list2star(v_24564, v_24563, v_24562);
    return onevalue(v_24562);
}



// Code for ieval

static LispObject CC_ieval(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24531;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24526);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_24531 = v_24526;
// end of prologue
    fn = elt(env, 1); // reval
    v_24531 = (*qfn1(fn))(fn, v_24531);
    env = stack[0];
    {
        fn = elt(env, 2); // !*s2i
        return (*qfn1(fn))(fn, v_24531);
    }
}



// Code for znumrnil

static LispObject CC_znumrnil(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24545, v_24546;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24526);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_24526;
// end of prologue
    v_24545 = stack[0];
    fn = elt(env, 1); // znumr
    v_24545 = (*qfn1(fn))(fn, v_24545);
    if (v_24545 == nil) goto v_24531;
    goto v_24539;
v_24535:
    v_24546 = nil;
    goto v_24536;
v_24537:
    v_24545 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24538;
v_24539:
    goto v_24535;
v_24536:
    goto v_24537;
v_24538:
    return cons(v_24546, v_24545);
v_24531:
    v_24545 = stack[0];
    goto v_24529;
    v_24545 = nil;
v_24529:
    return onevalue(v_24545);
}



// Code for diffp

static LispObject CC_diffp(LispObject env,
                         LispObject v_24526, LispObject v_24527)
{
    env = qenv(env);
    LispObject v_26084, v_26085, v_26086, v_26087, v_26088;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24527,v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24526,v_24527);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-7] = v_24527;
    stack[-8] = v_24526;
// end of prologue
    stack[0] = nil;
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    stack[-9] = v_26084;
    v_26084 = stack[-8];
    v_26084 = qcar(v_26084);
    stack[-8] = v_26084;
    goto v_24558;
v_24554:
    v_26085 = stack[-9];
    goto v_24555;
v_24556:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24557;
v_24558:
    goto v_24554;
v_24555:
    goto v_24556;
v_24557:
    v_26084 = (LispObject)greaterp2(v_26085, v_26084);
    v_26084 = v_26084 ? lisp_true : nil;
    env = stack[-10];
    if (v_26084 == nil) goto v_24551;
    v_26084 = stack[-8];
    fn = elt(env, 22); // noncomp
    v_26084 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    if (v_26084 == nil) goto v_24551;
    goto v_24569;
v_24565:
    goto v_24575;
v_24571:
    goto v_24582;
v_24578:
    v_26085 = stack[-8];
    goto v_24579;
v_24580:
    v_26084 = stack[-7];
    goto v_24581;
v_24582:
    goto v_24578;
v_24579:
    goto v_24580;
v_24581:
    v_26084 = list2(v_26085, v_26084);
    env = stack[-10];
    fn = elt(env, 23); // simpdf
    stack[-1] = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    goto v_24572;
v_24573:
    goto v_24591;
v_24587:
    stack[0] = stack[-8];
    goto v_24588;
v_24589:
    v_26084 = stack[-9];
    v_26084 = sub1(v_26084);
    env = stack[-10];
    goto v_24590;
v_24591:
    goto v_24587;
v_24588:
    goto v_24589;
v_24590:
    v_26084 = list2(stack[0], v_26084);
    env = stack[-10];
    fn = elt(env, 24); // simpexpt
    v_26084 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    goto v_24574;
v_24575:
    goto v_24571;
v_24572:
    goto v_24573;
v_24574:
    fn = elt(env, 25); // multsq
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_26084);
    env = stack[-10];
    goto v_24566;
v_24567:
    goto v_24600;
v_24596:
    goto v_24606;
v_24602:
    goto v_24613;
v_24609:
    goto v_24619;
v_24615:
    v_26085 = stack[-8];
    goto v_24616;
v_24617:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24618;
v_24619:
    goto v_24615;
v_24616:
    goto v_24617;
v_24618:
    fn = elt(env, 26); // to
    v_26085 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    goto v_24610;
v_24611:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24612;
v_24613:
    goto v_24609;
v_24610:
    goto v_24611;
v_24612:
    v_26084 = cons(v_26085, v_26084);
    env = stack[-10];
    v_26085 = ncons(v_26084);
    env = stack[-10];
    goto v_24603;
v_24604:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24605;
v_24606:
    goto v_24602;
v_24603:
    goto v_24604;
v_24605:
    stack[0] = cons(v_26085, v_26084);
    env = stack[-10];
    goto v_24597;
v_24598:
    goto v_24629;
v_24625:
    goto v_24635;
v_24631:
    stack[-2] = stack[-8];
    goto v_24632;
v_24633:
    v_26084 = stack[-9];
    v_26084 = sub1(v_26084);
    env = stack[-10];
    goto v_24634;
v_24635:
    goto v_24631;
v_24632:
    goto v_24633;
v_24634:
    v_26085 = cons(stack[-2], v_26084);
    env = stack[-10];
    goto v_24626;
v_24627:
    v_26084 = stack[-7];
    goto v_24628;
v_24629:
    goto v_24625;
v_24626:
    goto v_24627;
v_24628:
    v_26084 = CC_diffp(elt(env, 0), v_26085, v_26084);
    env = stack[-10];
    goto v_24599;
v_24600:
    goto v_24596;
v_24597:
    goto v_24598;
v_24599:
    fn = elt(env, 25); // multsq
    v_26084 = (*qfn2(fn))(fn, stack[0], v_26084);
    env = stack[-10];
    goto v_24568;
v_24569:
    goto v_24565;
v_24566:
    goto v_24567;
v_24568:
    {
        LispObject v_26099 = stack[-1];
        fn = elt(env, 27); // addsq
        return (*qfn2(fn))(fn, v_26099, v_26084);
    }
v_24551:
    goto v_24650;
v_24646:
    v_26085 = stack[-8];
    goto v_24647;
v_24648:
    v_26084 = stack[-7];
    goto v_24649;
v_24650:
    goto v_24646;
v_24647:
    goto v_24648;
v_24649:
    if (v_26085 == v_26084) goto v_24644;
    else goto v_24645;
v_24644:
    goto v_24658;
v_24654:
    v_26085 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24655;
v_24656:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24657;
v_24658:
    goto v_24654;
v_24655:
    goto v_24656;
v_24657:
    v_26084 = cons(v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_24643;
v_24645:
    v_26084 = nil;
    goto v_24643;
    v_26084 = nil;
v_24643:
    if (v_26084 == nil) goto v_24641;
    goto v_24539;
v_24641:
    v_26084 = stack[-8];
    if (!consp(v_26084)) goto v_24664;
    else goto v_24665;
v_24664:
    goto v_24540;
v_24665:
    v_26084 = stack[-8];
    v_26084 = qcar(v_26084);
    if (!consp(v_26084)) goto v_24673;
    goto v_24681;
v_24677:
    v_26085 = stack[-8];
    goto v_24678;
v_24679:
    v_26084 = stack[-7];
    goto v_24680;
v_24681:
    goto v_24677;
v_24678:
    goto v_24679;
v_24680:
    fn = elt(env, 28); // difff
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_24671;
v_24673:
    v_26084 = nil;
    goto v_24671;
    v_26084 = nil;
v_24671:
    if (v_26084 == nil) goto v_24669;
    else goto v_24667;
v_24669:
    goto v_24696;
v_24692:
    v_26084 = stack[-8];
    v_26085 = qcar(v_26084);
    goto v_24693;
v_24694:
    v_26084 = elt(env, 1); // !*sq
    goto v_24695;
v_24696:
    goto v_24692;
v_24693:
    goto v_24694;
v_24695:
    if (v_26085 == v_26084) goto v_24690;
    else goto v_24691;
v_24690:
    goto v_24705;
v_24701:
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    v_26085 = qcar(v_26084);
    goto v_24702;
v_24703:
    v_26084 = stack[-7];
    goto v_24704;
v_24705:
    goto v_24701;
v_24702:
    goto v_24703;
v_24704:
    fn = elt(env, 29); // diffsq
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_24689;
v_24691:
    v_26084 = nil;
    goto v_24689;
    v_26084 = nil;
v_24689:
    if (v_26084 == nil) goto v_24687;
    else goto v_24667;
v_24687:
    goto v_24668;
v_24667:
    goto v_24538;
v_24668:
    goto v_24720;
v_24716:
    v_26084 = stack[-8];
    v_26085 = qcar(v_26084);
    goto v_24717;
v_24718:
    v_26084 = elt(env, 2); // dfform
    goto v_24719;
v_24720:
    goto v_24716;
v_24717:
    goto v_24718;
v_24719:
    v_26084 = get(v_26085, v_26084);
    env = stack[-10];
    stack[-6] = v_26084;
    if (v_26084 == nil) goto v_24714;
    goto v_24733;
v_24725:
    v_26087 = stack[-6];
    goto v_24726;
v_24727:
    v_26086 = stack[-8];
    goto v_24728;
v_24729:
    v_26085 = stack[-7];
    goto v_24730;
v_24731:
    v_26084 = stack[-9];
    goto v_24732;
v_24733:
    goto v_24725;
v_24726:
    goto v_24727;
v_24728:
    goto v_24729;
v_24730:
    goto v_24731;
v_24732:
        return Lapply3(nil, 4, v_26087, v_26086, v_26085, v_26084);
v_24714:
    goto v_24745;
v_24741:
    v_26084 = stack[-8];
    stack[-1] = qcar(v_26084);
    goto v_24742;
v_24743:
    v_26084 = stack[-8];
    fn = elt(env, 30); // dfn_prop
    v_26084 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    goto v_24744;
v_24745:
    goto v_24741;
v_24742:
    goto v_24743;
v_24744:
    v_26084 = get(stack[-1], v_26084);
    env = stack[-10];
    stack[-6] = v_26084;
    if (v_26084 == nil) goto v_24739;
    goto v_24549;
v_24739:
    goto v_24761;
v_24757:
    v_26084 = stack[-8];
    v_26085 = qcar(v_26084);
    goto v_24758;
v_24759:
    v_26084 = elt(env, 3); // plus
    goto v_24760;
v_24761:
    goto v_24757;
v_24758:
    goto v_24759;
v_24760:
    if (v_26085 == v_26084) goto v_24755;
    else goto v_24756;
v_24755:
    goto v_24770;
v_24766:
    v_26084 = stack[-8];
    fn = elt(env, 31); // simp
    v_26085 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    goto v_24767;
v_24768:
    v_26084 = stack[-7];
    goto v_24769;
v_24770:
    goto v_24766;
v_24767:
    goto v_24768;
v_24769:
    fn = elt(env, 29); // diffsq
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_24754;
v_24756:
    v_26084 = nil;
    goto v_24754;
    v_26084 = nil;
v_24754:
    if (v_26084 == nil) goto v_24752;
    goto v_24538;
v_24752:
    goto v_24541;
v_24549:
    v_26084 = stack[-6];
    stack[-5] = v_26084;
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    stack[-4] = v_26084;
v_24537:
    goto v_24787;
v_24783:
    goto v_24793;
v_24789:
    v_26084 = stack[-4];
    v_26084 = qcar(v_26084);
    fn = elt(env, 31); // simp
    v_26085 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    goto v_24790;
v_24791:
    v_26084 = stack[-7];
    goto v_24792;
v_24793:
    goto v_24789;
v_24790:
    goto v_24791;
v_24792:
    fn = elt(env, 29); // diffsq
    v_26085 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    goto v_24784;
v_24785:
    v_26084 = stack[0];
    goto v_24786;
v_24787:
    goto v_24783;
v_24784:
    goto v_24785;
v_24786:
    v_26084 = cons(v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    v_26084 = stack[0];
    v_26084 = qcar(v_26084);
    v_26084 = qcar(v_26084);
    if (v_26084 == nil) goto v_24802;
    v_26084 = stack[-5];
    v_26084 = qcar(v_26084);
    if (v_26084 == nil) goto v_24807;
    else goto v_24802;
v_24807:
    goto v_24541;
v_24802:
    v_26084 = stack[-5];
    v_26084 = qcdr(v_26084);
    stack[-5] = v_26084;
    v_26084 = stack[-4];
    v_26084 = qcdr(v_26084);
    stack[-4] = v_26084;
    v_26084 = stack[-4];
    if (v_26084 == nil) goto v_24817;
    v_26084 = stack[-5];
    if (v_26084 == nil) goto v_24817;
    goto v_24537;
v_24817:
    v_26084 = stack[-4];
    if (v_26084 == nil) goto v_24824;
    else goto v_24822;
v_24824:
    v_26084 = stack[-5];
    if (v_26084 == nil) goto v_24826;
    else goto v_24822;
v_24826:
    goto v_24823;
v_24822:
    goto v_24541;
v_24823:
    v_26084 = stack[0];
    v_26084 = Lreverse(nil, v_26084);
    env = stack[-10];
    stack[-5] = v_26084;
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    stack[-4] = v_26084;
    goto v_24837;
v_24833:
    v_26085 = nil;
    goto v_24834;
v_24835:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24836;
v_24837:
    goto v_24833;
v_24834:
    goto v_24835;
v_24836:
    v_26084 = cons(v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
v_24842:
    v_26084 = stack[-5];
    v_26084 = qcar(v_26084);
    v_26084 = qcar(v_26084);
    if (v_26084 == nil) goto v_24846;
    goto v_24855;
v_24851:
    goto v_24861;
v_24857:
    v_26084 = stack[-5];
    stack[-1] = qcar(v_26084);
    goto v_24858;
v_24859:
    goto v_24870;
v_24866:
    goto v_24876;
v_24872:
    v_26084 = stack[-6];
    v_26084 = qcar(v_26084);
    v_26085 = qcar(v_26084);
    goto v_24873;
v_24874:
    v_26084 = stack[-4];
    goto v_24875;
v_24876:
    goto v_24872;
v_24873:
    goto v_24874;
v_24875:
    fn = elt(env, 32); // pair
    v_26085 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    goto v_24867;
v_24868:
    v_26084 = stack[-6];
    v_26084 = qcar(v_26084);
    v_26084 = qcdr(v_26084);
    goto v_24869;
v_24870:
    goto v_24866;
v_24867:
    goto v_24868;
v_24869:
    v_26084 = Lsubla(nil, v_26085, v_26084);
    env = stack[-10];
    fn = elt(env, 31); // simp
    v_26084 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    goto v_24860;
v_24861:
    goto v_24857;
v_24858:
    goto v_24859;
v_24860:
    fn = elt(env, 25); // multsq
    v_26085 = (*qfn2(fn))(fn, stack[-1], v_26084);
    env = stack[-10];
    goto v_24852;
v_24853:
    v_26084 = stack[0];
    goto v_24854;
v_24855:
    goto v_24851;
v_24852:
    goto v_24853;
v_24854:
    fn = elt(env, 27); // addsq
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_24844;
v_24846:
v_24844:
    v_26084 = stack[-6];
    v_26084 = qcdr(v_26084);
    stack[-6] = v_26084;
    v_26084 = stack[-5];
    v_26084 = qcdr(v_26084);
    stack[-5] = v_26084;
    v_26084 = stack[-5];
    if (v_26084 == nil) goto v_24892;
    goto v_24842;
v_24892:
v_24538:
v_24539:
    goto v_24902;
v_24898:
    v_26085 = stack[-8];
    goto v_24899;
v_24900:
    v_26084 = qvalue(elt(env, 4)); // wtl!*
    goto v_24901;
v_24902:
    goto v_24898;
v_24899:
    goto v_24900;
v_24901:
    v_26084 = Latsoc(nil, v_26085, v_26084);
    stack[-6] = v_26084;
    if (v_26084 == nil) goto v_24897;
    goto v_24911;
v_24907:
    goto v_24917;
v_24913:
    goto v_24924;
v_24920:
    goto v_24930;
v_24926:
    stack[-1] = elt(env, 5); // k!*
    goto v_24927;
v_24928:
    v_26084 = stack[-6];
    v_26084 = qcdr(v_26084);
    v_26084 = negate(v_26084);
    env = stack[-10];
    goto v_24929;
v_24930:
    goto v_24926;
v_24927:
    goto v_24928;
v_24929:
    fn = elt(env, 26); // to
    v_26085 = (*qfn2(fn))(fn, stack[-1], v_26084);
    env = stack[-10];
    goto v_24921;
v_24922:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24923;
v_24924:
    goto v_24920;
v_24921:
    goto v_24922;
v_24923:
    v_26084 = cons(v_26085, v_26084);
    env = stack[-10];
    v_26085 = ncons(v_26084);
    env = stack[-10];
    goto v_24914;
v_24915:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24916;
v_24917:
    goto v_24913;
v_24914:
    goto v_24915;
v_24916:
    v_26085 = cons(v_26085, v_26084);
    env = stack[-10];
    goto v_24908;
v_24909:
    v_26084 = stack[0];
    goto v_24910;
v_24911:
    goto v_24907;
v_24908:
    goto v_24909;
v_24910:
    fn = elt(env, 25); // multsq
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_24895;
v_24897:
v_24895:
    v_26084 = stack[-9];
    v_26084 = sub1(v_26084);
    env = stack[-10];
    stack[-3] = v_26084;
    goto v_24949;
v_24945:
    v_26085 = stack[-9];
    goto v_24946;
v_24947:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24948;
v_24949:
    goto v_24945;
v_24946:
    goto v_24947;
v_24948:
    if (v_26085 == v_26084) goto v_24943;
    else goto v_24944;
v_24943:
    v_26084 = stack[0];
    goto v_24942;
v_24944:
    v_26084 = qvalue(elt(env, 6)); // dmode!*
    if (!symbolp(v_26084)) v_26084 = nil;
    else { v_26084 = qfastgets(v_26084);
           if (v_26084 != nil) { v_26084 = elt(v_26084, 5); // convert
#ifdef RECORD_GET
             if (v_26084 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v_26084 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v_26084 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v_26084 == SPID_NOPROP) v_26084 = nil; else v_26084 = lisp_true; }}
#endif
    if (v_26084 == nil) goto v_24958;
    goto v_24967;
v_24963:
    v_26084 = qvalue(elt(env, 6)); // dmode!*
    if (!symbolp(v_26084)) v_26085 = nil;
    else { v_26085 = qfastgets(v_26084);
           if (v_26085 != nil) { v_26085 = elt(v_26085, 34); // i2d
#ifdef RECORD_GET
             if (v_26085 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_26085 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_26085 == SPID_NOPROP) v_26085 = nil; }}
#endif
    goto v_24964;
v_24965:
    v_26084 = stack[-9];
    goto v_24966;
v_24967:
    goto v_24963;
v_24964:
    goto v_24965;
v_24966:
    v_26084 = Lapply1(nil, v_26085, v_26084);
    env = stack[-10];
    fn = elt(env, 33); // int!-equiv!-chk
    v_26084 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    stack[-9] = v_26084;
    v_26084 = (v_26084 == nil ? lisp_true : nil);
    goto v_24956;
v_24958:
    v_26084 = nil;
    goto v_24956;
    v_26084 = nil;
v_24956:
    if (v_26084 == nil) goto v_24954;
    goto v_24980;
v_24976:
    v_26085 = nil;
    goto v_24977;
v_24978:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24979;
v_24980:
    goto v_24976;
v_24977:
    goto v_24978;
v_24979:
    v_26084 = cons(v_26085, v_26084);
    env = stack[-10];
    goto v_24942;
v_24954:
    goto v_24990;
v_24986:
    goto v_24996;
v_24992:
    goto v_25003;
v_24999:
    goto v_25009;
v_25005:
    v_26085 = stack[-8];
    goto v_25006;
v_25007:
    v_26084 = stack[-3];
    goto v_25008;
v_25009:
    goto v_25005;
v_25006:
    goto v_25007;
v_25008:
    fn = elt(env, 26); // to
    v_26085 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    goto v_25000;
v_25001:
    v_26084 = stack[-9];
    goto v_25002;
v_25003:
    goto v_24999;
v_25000:
    goto v_25001;
v_25002:
    v_26084 = cons(v_26085, v_26084);
    env = stack[-10];
    v_26085 = ncons(v_26084);
    env = stack[-10];
    goto v_24993;
v_24994:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24995;
v_24996:
    goto v_24992;
v_24993:
    goto v_24994;
v_24995:
    v_26085 = cons(v_26085, v_26084);
    env = stack[-10];
    goto v_24987;
v_24988:
    v_26084 = stack[0];
    goto v_24989;
v_24990:
    goto v_24986;
v_24987:
    goto v_24988;
v_24989:
    fn = elt(env, 25); // multsq
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    goto v_24942;
    v_26084 = nil;
v_24942:
    {
        fn = elt(env, 34); // rationalizesq
        return (*qfn1(fn))(fn, v_26084);
    }
v_24540:
    goto v_25028;
v_25024:
    v_26085 = stack[-8];
    goto v_25025;
v_25026:
    v_26084 = stack[-7];
    goto v_25027;
v_25028:
    goto v_25024;
v_25025:
    goto v_25026;
v_25027:
    fn = elt(env, 35); // depends
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    if (v_26084 == nil) goto v_25021;
    else goto v_25022;
v_25021:
    goto v_25043;
v_25039:
    v_26085 = stack[-8];
    goto v_25040;
v_25041:
    v_26084 = qvalue(elt(env, 7)); // powlis!*
    goto v_25042;
v_25043:
    goto v_25039;
v_25040:
    goto v_25041;
v_25042:
    v_26084 = Latsoc(nil, v_26085, v_26084);
    stack[-6] = v_26084;
    if (v_26084 == nil) goto v_25037;
    else goto v_25038;
v_25037:
    v_26084 = lisp_true;
    goto v_25036;
v_25038:
    goto v_25055;
v_25051:
    v_26084 = stack[-6];
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    v_26085 = qcar(v_26084);
    goto v_25052;
v_25053:
    v_26084 = stack[-7];
    goto v_25054;
v_25055:
    goto v_25051;
v_25052:
    goto v_25053;
v_25054:
    fn = elt(env, 35); // depends
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    v_26084 = (v_26084 == nil ? lisp_true : nil);
    goto v_25036;
    v_26084 = nil;
v_25036:
    if (v_26084 == nil) goto v_25034;
    v_26084 = qvalue(elt(env, 8)); // !*depend
    v_26084 = (v_26084 == nil ? lisp_true : nil);
    goto v_25032;
v_25034:
    v_26084 = nil;
    goto v_25032;
    v_26084 = nil;
v_25032:
    goto v_25020;
v_25022:
    v_26084 = nil;
    goto v_25020;
    v_26084 = nil;
v_25020:
    if (v_26084 == nil) goto v_25018;
    goto v_25076;
v_25072:
    v_26085 = nil;
    goto v_25073;
v_25074:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25075;
v_25076:
    goto v_25072;
v_25073:
    goto v_25074;
v_25075:
    return cons(v_26085, v_26084);
v_25018:
    v_26084 = qvalue(elt(env, 9)); // !*expanddf
    if (v_26084 == nil) goto v_25082;
    goto v_25098;
v_25094:
    v_26085 = stack[-8];
    goto v_25095;
v_25096:
    v_26084 = qvalue(elt(env, 7)); // powlis!*
    goto v_25097;
v_25098:
    goto v_25094;
v_25095:
    goto v_25096;
v_25097:
    v_26084 = Latsoc(nil, v_26085, v_26084);
    stack[-6] = v_26084;
    if (v_26084 == nil) goto v_25092;
    else goto v_25093;
v_25092:
    v_26084 = lisp_true;
    goto v_25091;
v_25093:
    goto v_25110;
v_25106:
    v_26084 = stack[-6];
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    v_26085 = qcar(v_26084);
    goto v_25107;
v_25108:
    v_26084 = stack[-7];
    goto v_25109;
v_25110:
    goto v_25106;
v_25107:
    goto v_25108;
v_25109:
    fn = elt(env, 35); // depends
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    v_26084 = (v_26084 == nil ? lisp_true : nil);
    goto v_25091;
    v_26084 = nil;
v_25091:
    if (v_26084 == nil) goto v_25089;
    goto v_25126;
v_25122:
    v_26085 = stack[-8];
    goto v_25123;
v_25124:
    v_26084 = qvalue(elt(env, 10)); // depl!*
    goto v_25125;
v_25126:
    goto v_25122;
v_25123:
    goto v_25124;
v_25125:
    v_26084 = Latsoc(nil, v_26085, v_26084);
    stack[-6] = v_26084;
    if (v_26084 == nil) goto v_25120;
    else goto v_25121;
v_25120:
    v_26084 = nil;
    goto v_25119;
v_25121:
    goto v_25137;
v_25133:
    v_26085 = stack[-7];
    goto v_25134;
v_25135:
    v_26084 = stack[-6];
    v_26084 = qcdr(v_26084);
    stack[-6] = v_26084;
    goto v_25136;
v_25137:
    goto v_25133;
v_25134:
    goto v_25135;
v_25136:
    v_26084 = Lmemq(nil, v_26085, v_26084);
    v_26084 = (v_26084 == nil ? lisp_true : nil);
    goto v_25119;
    v_26084 = nil;
v_25119:
    goto v_25087;
v_25089:
    v_26084 = nil;
    goto v_25087;
    v_26084 = nil;
v_25087:
    if (v_26084 == nil) goto v_25082;
    goto v_25153;
v_25147:
    v_26086 = stack[-8];
    goto v_25148;
v_25149:
    v_26085 = stack[-7];
    goto v_25150;
v_25151:
    v_26084 = stack[-6];
    goto v_25152;
v_25153:
    goto v_25147;
v_25148:
    goto v_25149;
v_25150:
    goto v_25151;
v_25152:
    fn = elt(env, 36); // df!-chain!-rule
    v_26084 = (*qfnn(fn))(fn, 3, v_26086, v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_24539;
v_25082:
    goto v_25164;
v_25158:
    v_26086 = elt(env, 11); // df
    goto v_25159;
v_25160:
    v_26085 = stack[-8];
    goto v_25161;
v_25162:
    v_26084 = stack[-7];
    goto v_25163;
v_25164:
    goto v_25158;
v_25159:
    goto v_25160;
v_25161:
    goto v_25162;
v_25163:
    v_26084 = list3(v_26086, v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    v_26084 = stack[0];
    fn = elt(env, 37); // opmtch
    v_26084 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    stack[-6] = v_26084;
    if (v_26084 == nil) goto v_25171;
    v_26084 = stack[-6];
    fn = elt(env, 31); // simp
    v_26084 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    goto v_25169;
v_25171:
    goto v_25183;
v_25179:
    v_26085 = stack[0];
    goto v_25180;
v_25181:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25182;
v_25183:
    goto v_25179;
v_25180:
    goto v_25181;
v_25182:
    fn = elt(env, 38); // mksq
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    goto v_25169;
    v_26084 = nil;
v_25169:
    stack[0] = v_26084;
    goto v_24539;
v_24541:
    goto v_25194;
v_25190:
    v_26084 = stack[-8];
    v_26085 = qcar(v_26084);
    goto v_25191;
v_25192:
    v_26084 = elt(env, 11); // df
    goto v_25193;
v_25194:
    goto v_25190;
v_25191:
    goto v_25192;
v_25193:
    if (v_26085 == v_26084) goto v_25188;
    else goto v_25189;
v_25188:
    goto v_25206;
v_25202:
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    v_26085 = qcar(v_26084);
    goto v_25203;
v_25204:
    v_26084 = stack[-7];
    goto v_25205;
v_25206:
    goto v_25202;
v_25203:
    goto v_25204;
v_25205:
    if (v_26085 == v_26084) goto v_25200;
    else goto v_25201;
v_25200:
    v_26084 = qvalue(elt(env, 12)); // !*commutedf
    if (v_26084 == nil) goto v_25214;
    v_26084 = qvalue(elt(env, 8)); // !*depend
    if (v_26084 == nil) goto v_25217;
    else goto v_25214;
v_25217:
    goto v_25224;
v_25220:
    v_26085 = nil;
    goto v_25221;
v_25222:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25223;
v_25224:
    goto v_25220;
v_25221:
    goto v_25222;
v_25223:
    return cons(v_26085, v_26084);
v_25214:
    v_26084 = qvalue(elt(env, 13)); // !*simpnoncomdf
    if (v_26084 == nil) goto v_25228;
    goto v_25237;
v_25233:
    v_26085 = stack[-7];
    goto v_25234;
v_25235:
    v_26084 = qvalue(elt(env, 10)); // depl!*
    goto v_25236;
v_25237:
    goto v_25233;
v_25234:
    goto v_25235;
v_25236:
    v_26084 = Latsoc(nil, v_26085, v_26084);
    stack[0] = v_26084;
    if (v_26084 == nil) goto v_25228;
    v_26084 = stack[0];
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    if (v_26084 == nil) goto v_25241;
    else goto v_25228;
v_25241:
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    v_26084 = qcar(v_26084);
    stack[-6] = v_26084;
    goto v_25254;
v_25250:
    goto v_25263;
v_25257:
    v_26086 = elt(env, 11); // df
    goto v_25258;
v_25259:
    v_26085 = stack[-8];
    goto v_25260;
v_25261:
    v_26084 = stack[-6];
    goto v_25262;
v_25263:
    goto v_25257;
v_25258:
    goto v_25259;
v_25260:
    goto v_25261;
v_25262:
    v_26084 = list3(v_26086, v_26085, v_26084);
    env = stack[-10];
    fn = elt(env, 31); // simp
    stack[0] = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    goto v_25251;
v_25252:
    goto v_25275;
v_25269:
    v_26086 = elt(env, 11); // df
    goto v_25270;
v_25271:
    v_26085 = stack[-7];
    goto v_25272;
v_25273:
    v_26084 = stack[-6];
    goto v_25274;
v_25275:
    goto v_25269;
v_25270:
    goto v_25271;
v_25272:
    goto v_25273;
v_25274:
    v_26084 = list3(v_26086, v_26085, v_26084);
    env = stack[-10];
    fn = elt(env, 31); // simp
    v_26084 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    goto v_25253;
v_25254:
    goto v_25250;
v_25251:
    goto v_25252;
v_25253:
    fn = elt(env, 39); // quotsq
    v_26084 = (*qfn2(fn))(fn, stack[0], v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_24539;
v_25228:
    goto v_25199;
v_25201:
    goto v_25286;
v_25282:
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    v_26085 = qcar(v_26084);
    goto v_25283;
v_25284:
    v_26084 = elt(env, 14); // int
    goto v_25285;
v_25286:
    goto v_25282;
v_25283:
    goto v_25284;
v_25285:
    if (!consp(v_26085)) goto v_25280;
    v_26085 = qcar(v_26085);
    if (v_26085 == v_26084) goto v_25279;
    else goto v_25280;
v_25279:
    goto v_25299;
v_25295:
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    v_26084 = qcar(v_26084);
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    v_26085 = qcar(v_26084);
    goto v_25296;
v_25297:
    v_26084 = stack[-7];
    goto v_25298;
v_25299:
    goto v_25295;
v_25296:
    goto v_25297;
v_25298:
    if (v_26085 == v_26084) goto v_25293;
    else goto v_25294;
v_25293:
    goto v_25314;
v_25308:
    v_26086 = elt(env, 11); // df
    goto v_25309;
v_25310:
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    v_26084 = qcar(v_26084);
    v_26084 = qcdr(v_26084);
    v_26085 = qcar(v_26084);
    goto v_25311;
v_25312:
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    goto v_25313;
v_25314:
    goto v_25308;
v_25309:
    goto v_25310;
v_25311:
    goto v_25312;
v_25313:
    v_26084 = list2star(v_26086, v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_24542;
v_25294:
    v_26084 = qvalue(elt(env, 15)); // !*allowdfint
    if (v_26084 == nil) goto v_25325;
    goto v_25335;
v_25331:
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    v_26084 = qcar(v_26084);
    v_26084 = qcdr(v_26084);
    v_26084 = qcar(v_26084);
    fn = elt(env, 40); // simp!*
    v_26085 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    goto v_25332;
v_25333:
    v_26084 = stack[-7];
    goto v_25334;
v_25335:
    goto v_25331;
v_25332:
    goto v_25333;
v_25334:
    fn = elt(env, 29); // diffsq
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    fn = elt(env, 41); // not_df_p
    v_26084 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    if (v_26084 == nil) goto v_25325;
    goto v_25350;
v_25344:
    stack[-2] = elt(env, 11); // df
    goto v_25345;
v_25346:
    goto v_25360;
v_25354:
    stack[-1] = elt(env, 14); // int
    goto v_25355;
v_25356:
    v_26084 = stack[0];
    fn = elt(env, 42); // mk!*sq
    v_26085 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    goto v_25357;
v_25358:
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    v_26084 = qcar(v_26084);
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    v_26084 = qcar(v_26084);
    goto v_25359;
v_25360:
    goto v_25354;
v_25355:
    goto v_25356;
v_25357:
    goto v_25358;
v_25359:
    v_26084 = list3(stack[-1], v_26085, v_26084);
    env = stack[-10];
    fn = elt(env, 43); // reval
    v_26085 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    goto v_25347;
v_25348:
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    goto v_25349;
v_25350:
    goto v_25344;
v_25345:
    goto v_25346;
v_25347:
    goto v_25348;
v_25349:
    v_26084 = list2star(stack[-2], v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_24542;
v_25325:
    goto v_25199;
v_25280:
v_25199:
    v_26084 = qvalue(elt(env, 9)); // !*expanddf
    if (v_26084 == nil) goto v_25376;
    goto v_25386;
v_25382:
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    v_26085 = qcar(v_26084);
    goto v_25383;
v_25384:
    v_26084 = stack[-7];
    goto v_25385;
v_25386:
    goto v_25382;
v_25383:
    goto v_25384;
v_25385:
    fn = elt(env, 35); // depends
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    if (v_26084 == nil) goto v_25376;
    goto v_25400;
v_25396:
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    v_26085 = qcar(v_26084);
    goto v_25397;
v_25398:
    v_26084 = qvalue(elt(env, 7)); // powlis!*
    goto v_25399;
v_25400:
    goto v_25396;
v_25397:
    goto v_25398;
v_25399:
    v_26084 = Latsoc(nil, v_26085, v_26084);
    stack[-6] = v_26084;
    if (v_26084 == nil) goto v_25394;
    else goto v_25395;
v_25394:
    v_26084 = lisp_true;
    goto v_25393;
v_25395:
    goto v_25414;
v_25410:
    v_26084 = stack[-6];
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    v_26085 = qcar(v_26084);
    goto v_25411;
v_25412:
    v_26084 = stack[-7];
    goto v_25413;
v_25414:
    goto v_25410;
v_25411:
    goto v_25412;
v_25413:
    fn = elt(env, 35); // depends
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    v_26084 = (v_26084 == nil ? lisp_true : nil);
    goto v_25393;
    v_26084 = nil;
v_25393:
    if (v_26084 == nil) goto v_25376;
    goto v_25431;
v_25427:
    v_26085 = stack[-7];
    goto v_25428;
v_25429:
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    v_26084 = qcar(v_26084);
    goto v_25430;
v_25431:
    goto v_25427;
v_25428:
    goto v_25429;
v_25430:
    fn = elt(env, 44); // smember
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    if (v_26084 == nil) goto v_25424;
    else goto v_25425;
v_25424:
    goto v_25440;
v_25436:
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    v_26085 = qcar(v_26084);
    goto v_25437;
v_25438:
    v_26084 = qvalue(elt(env, 10)); // depl!*
    goto v_25439;
v_25440:
    goto v_25436;
v_25437:
    goto v_25438;
v_25439:
    v_26084 = Lassoc(nil, v_26085, v_26084);
    stack[-6] = v_26084;
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    v_26084 = qcar(v_26084);
    if (!consp(v_26084)) goto v_25449;
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    v_26084 = qcar(v_26084);
    v_26084 = qcdr(v_26084);
    if (v_26084 == nil) goto v_25455;
    else goto v_25456;
v_25455:
    v_26084 = nil;
    goto v_25454;
v_25456:
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    v_26084 = qcar(v_26084);
    v_26084 = qcdr(v_26084);
    fn = elt(env, 45); // get!-all!-kernels
    v_26084 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    goto v_25454;
    v_26084 = nil;
v_25454:
    goto v_25447;
v_25449:
    v_26084 = nil;
    goto v_25447;
    v_26084 = nil;
v_25447:
    stack[-5] = v_26084;
    v_26084 = stack[-6];
    if (v_26084 == nil) goto v_25475;
    v_26084 = stack[-5];
    if (v_26084 == nil) goto v_25475;
    goto v_25487;
v_25483:
    goto v_25493;
v_25489:
    v_26085 = stack[-7];
    goto v_25490;
v_25491:
    v_26084 = stack[-5];
    goto v_25492;
v_25493:
    goto v_25489;
v_25490:
    goto v_25491;
v_25492:
    v_26085 = Ldelete(nil, v_26085, v_26084);
    env = stack[-10];
    goto v_25484;
v_25485:
    v_26084 = stack[-7];
    goto v_25486;
v_25487:
    goto v_25483;
v_25484:
    goto v_25485;
v_25486:
    fn = elt(env, 46); // ldepends
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    if (v_26084 == nil) goto v_25475;
    goto v_25473;
v_25475:
    v_26084 = stack[-6];
    if (v_26084 == nil) goto v_25499;
    goto v_25507;
v_25503:
    v_26085 = stack[-7];
    goto v_25504;
v_25505:
    v_26084 = stack[-6];
    v_26084 = qcdr(v_26084);
    stack[-6] = v_26084;
    goto v_25506;
v_25507:
    goto v_25503;
v_25504:
    goto v_25505;
v_25506:
    v_26084 = Lmemq(nil, v_26085, v_26084);
    if (v_26084 == nil) goto v_25502;
    else goto v_25499;
v_25502:
    goto v_25519;
v_25513:
    v_26086 = stack[-8];
    goto v_25514;
v_25515:
    v_26085 = stack[-7];
    goto v_25516;
v_25517:
    v_26084 = stack[-6];
    goto v_25518;
v_25519:
    goto v_25513;
v_25514:
    goto v_25515;
v_25516:
    goto v_25517;
v_25518:
    fn = elt(env, 36); // df!-chain!-rule
    v_26084 = (*qfnn(fn))(fn, 3, v_26086, v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_24539;
v_25499:
    v_26084 = stack[-5];
    if (v_26084 == nil) goto v_25524;
    goto v_25533;
v_25529:
    v_26085 = stack[-7];
    goto v_25530;
v_25531:
    v_26084 = stack[-5];
    goto v_25532;
v_25533:
    goto v_25529;
v_25530:
    goto v_25531;
v_25532:
    fn = elt(env, 44); // smember
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    if (v_26084 == nil) goto v_25527;
    else goto v_25524;
v_25527:
    goto v_25543;
v_25537:
    v_26086 = stack[-8];
    goto v_25538;
v_25539:
    v_26085 = stack[-7];
    goto v_25540;
v_25541:
    v_26084 = stack[-5];
    goto v_25542;
v_25543:
    goto v_25537;
v_25538:
    goto v_25539;
v_25540:
    goto v_25541;
v_25542:
    fn = elt(env, 36); // df!-chain!-rule
    v_26084 = (*qfnn(fn))(fn, 3, v_26086, v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_24539;
v_25524:
v_25473:
    goto v_25423;
v_25425:
v_25423:
    goto v_25374;
v_25376:
v_25374:
    goto v_25556;
v_25552:
    goto v_25562;
v_25558:
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    stack[0] = qcar(v_26084);
    goto v_25559;
v_25560:
    goto v_25571;
v_25567:
    v_26085 = stack[-8];
    goto v_25568;
v_25569:
    v_26084 = stack[-7];
    goto v_25570;
v_25571:
    goto v_25567;
v_25568:
    goto v_25569;
v_25570:
    fn = elt(env, 47); // merge!-ind!-vars
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    goto v_25561;
v_25562:
    goto v_25558;
v_25559:
    goto v_25560;
v_25561:
    v_26085 = cons(stack[0], v_26084);
    env = stack[-10];
    stack[0] = v_26085;
    goto v_25553;
v_25554:
    v_26084 = elt(env, 11); // df
    if (!symbolp(v_26084)) v_26084 = nil;
    else { v_26084 = qfastgets(v_26084);
           if (v_26084 != nil) { v_26084 = elt(v_26084, 50); // kvalue
#ifdef RECORD_GET
             if (v_26084 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v_26084 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v_26084 == SPID_NOPROP) v_26084 = nil; }}
#endif
    goto v_25555;
v_25556:
    goto v_25552;
v_25553:
    goto v_25554;
v_25555:
    fn = elt(env, 48); // find_sub_df
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    stack[-6] = v_26084;
    if (v_26084 == nil) goto v_25550;
    v_26084 = stack[-6];
    v_26084 = qcar(v_26084);
    fn = elt(env, 31); // simp
    v_26084 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    v_26084 = stack[-6];
    v_26084 = qcdr(v_26084);
    stack[-3] = v_26084;
v_25582:
    v_26084 = stack[-3];
    if (v_26084 == nil) goto v_25587;
    else goto v_25588;
v_25587:
    goto v_25581;
v_25588:
    v_26084 = stack[-3];
    v_26084 = qcar(v_26084);
    stack[-2] = v_26084;
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_26084;
v_25597:
    goto v_25609;
v_25605:
    v_26084 = stack[-2];
    v_26085 = qcdr(v_26084);
    goto v_25606;
v_25607:
    v_26084 = stack[-1];
    goto v_25608;
v_25609:
    goto v_25605;
v_25606:
    goto v_25607;
v_25608:
    v_26084 = difference2(v_26085, v_26084);
    env = stack[-10];
    v_26084 = Lminusp(nil, v_26084);
    env = stack[-10];
    if (v_26084 == nil) goto v_25602;
    goto v_25596;
v_25602:
    goto v_25619;
v_25615:
    v_26085 = stack[0];
    goto v_25616;
v_25617:
    v_26084 = stack[-2];
    v_26084 = qcar(v_26084);
    goto v_25618;
v_25619:
    goto v_25615;
v_25616:
    goto v_25617;
v_25618:
    fn = elt(env, 29); // diffsq
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    v_26084 = stack[-1];
    v_26084 = add1(v_26084);
    env = stack[-10];
    stack[-1] = v_26084;
    goto v_25597;
v_25596:
    v_26084 = stack[-3];
    v_26084 = qcdr(v_26084);
    stack[-3] = v_26084;
    goto v_25582;
v_25581:
    goto v_24539;
v_25550:
    goto v_25634;
v_25630:
    v_26085 = elt(env, 11); // df
    goto v_25631;
v_25632:
    v_26084 = stack[0];
    goto v_25633;
v_25634:
    goto v_25630;
v_25631:
    goto v_25632;
v_25633:
    v_26084 = cons(v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_25548;
v_25548:
    goto v_25187;
v_25189:
    v_26084 = qvalue(elt(env, 16)); // !*df_partial
    if (v_26084 == nil) goto v_25638;
    v_26084 = qvalue(elt(env, 9)); // !*expanddf
    if (v_26084 == nil) goto v_25638;
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    v_26084 = qcar(v_26084);
    if (!consp(v_26084)) goto v_25638;
    goto v_25655;
v_25651:
    v_26084 = stack[-8];
    v_26084 = qcar(v_26084);
    v_26085 = Lexplode(nil, v_26084);
    env = stack[-10];
    goto v_25652;
v_25653:
    v_26084 = elt(env, 17); // (!! !! !_)
    goto v_25654;
v_25655:
    goto v_25651;
v_25652:
    goto v_25653;
v_25654:
    v_26084 = Lnconc(nil, v_26085, v_26084);
    env = stack[-10];
    v_26084 = Lcompress(nil, v_26084);
    env = stack[-10];
    v_26084 = Lintern(nil, v_26084);
    env = stack[-10];
    stack[-6] = v_26084;
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    stack[-5] = v_26084;
    goto v_25667;
v_25663:
    v_26085 = nil;
    goto v_25664;
v_25665:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25666;
v_25667:
    goto v_25663;
v_25664:
    goto v_25665;
v_25666:
    v_26084 = cons(v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    v_26084 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_26084;
    v_26084 = stack[-5];
    stack[-2] = v_26084;
v_25674:
    v_26084 = stack[-2];
    if (v_26084 == nil) goto v_25678;
    else goto v_25679;
v_25678:
    goto v_25673;
v_25679:
    v_26084 = stack[-2];
    v_26084 = qcar(v_26084);
    stack[-1] = v_26084;
    v_26084 = stack[-3];
    v_26084 = add1(v_26084);
    env = stack[-10];
    stack[-3] = v_26084;
    goto v_25702;
v_25696:
    v_26086 = elt(env, 11); // df
    goto v_25697;
v_25698:
    v_26085 = stack[-1];
    goto v_25699;
v_25700:
    v_26084 = stack[-7];
    goto v_25701;
v_25702:
    goto v_25696;
v_25697:
    goto v_25698;
v_25699:
    goto v_25700;
v_25701:
    v_26084 = list3(v_26086, v_26085, v_26084);
    env = stack[-10];
    fn = elt(env, 31); // simp
    v_26084 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    stack[-1] = v_26084;
    v_26084 = qcar(v_26084);
    if (v_26084 == nil) goto v_25693;
    goto v_25712;
v_25708:
    v_26085 = stack[-6];
    goto v_25709;
v_25710:
    v_26084 = stack[-3];
    goto v_25711;
v_25712:
    goto v_25708;
v_25709:
    goto v_25710;
v_25711:
    fn = elt(env, 49); // mkid
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    stack[-4] = v_26084;
    goto v_25722;
v_25716:
    v_26086 = stack[-4];
    goto v_25717;
v_25718:
    v_26085 = elt(env, 18); // simpfn
    goto v_25719;
v_25720:
    v_26084 = elt(env, 19); // simpiden
    goto v_25721;
v_25722:
    goto v_25716;
v_25717:
    goto v_25718;
v_25719:
    goto v_25720;
v_25721:
    v_26084 = Lputprop(nil, 3, v_26086, v_26085, v_26084);
    env = stack[-10];
    goto v_25731;
v_25727:
    goto v_25728;
v_25729:
    goto v_25738;
v_25734:
    goto v_25745;
v_25741:
    v_26085 = stack[-4];
    goto v_25742;
v_25743:
    v_26084 = stack[-5];
    goto v_25744;
v_25745:
    goto v_25741;
v_25742:
    goto v_25743;
v_25744:
    v_26084 = cons(v_26085, v_26084);
    env = stack[-10];
    fn = elt(env, 31); // simp
    v_26085 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    goto v_25735;
v_25736:
    v_26084 = stack[-1];
    goto v_25737;
v_25738:
    goto v_25734;
v_25735:
    goto v_25736;
v_25737:
    fn = elt(env, 25); // multsq
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    goto v_25730;
v_25731:
    goto v_25727;
v_25728:
    goto v_25729;
v_25730:
    fn = elt(env, 27); // addsq
    v_26084 = (*qfn2(fn))(fn, stack[0], v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_25691;
v_25693:
v_25691:
    v_26084 = stack[-2];
    v_26084 = qcdr(v_26084);
    stack[-2] = v_26084;
    goto v_25674;
v_25673:
    goto v_24539;
v_25638:
    goto v_25760;
v_25754:
    v_26086 = elt(env, 11); // df
    goto v_25755;
v_25756:
    v_26085 = stack[-8];
    goto v_25757;
v_25758:
    v_26084 = stack[-7];
    goto v_25759;
v_25760:
    goto v_25754;
v_25755:
    goto v_25756;
v_25757:
    goto v_25758;
v_25759:
    v_26084 = list3(v_26086, v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_25187;
v_25187:
v_24542:
    v_26084 = stack[0];
    fn = elt(env, 37); // opmtch
    v_26084 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    stack[-6] = v_26084;
    if (v_26084 == nil) goto v_25767;
    v_26084 = stack[-6];
    fn = elt(env, 31); // simp
    v_26084 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_25765;
v_25767:
    goto v_25783;
v_25779:
    v_26085 = stack[-8];
    goto v_25780;
v_25781:
    v_26084 = stack[-7];
    goto v_25782;
v_25783:
    goto v_25779;
v_25780:
    goto v_25781;
v_25782:
    fn = elt(env, 35); // depends
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    if (v_26084 == nil) goto v_25776;
    else goto v_25777;
v_25776:
    goto v_25798;
v_25794:
    v_26084 = stack[0];
    v_26084 = qcdr(v_26084);
    v_26085 = qcar(v_26084);
    stack[-8] = v_26085;
    goto v_25795;
v_25796:
    v_26084 = qvalue(elt(env, 7)); // powlis!*
    goto v_25797;
v_25798:
    goto v_25794;
v_25795:
    goto v_25796;
v_25797:
    v_26084 = Latsoc(nil, v_26085, v_26084);
    stack[-6] = v_26084;
    if (v_26084 == nil) goto v_25792;
    else goto v_25793;
v_25792:
    v_26084 = lisp_true;
    goto v_25791;
v_25793:
    goto v_25812;
v_25808:
    v_26084 = stack[-6];
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    v_26085 = qcar(v_26084);
    goto v_25809;
v_25810:
    v_26084 = stack[0];
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    goto v_25811;
v_25812:
    goto v_25808;
v_25809:
    goto v_25810;
v_25811:
    fn = elt(env, 50); // dependsl
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    v_26084 = (v_26084 == nil ? lisp_true : nil);
    goto v_25791;
    v_26084 = nil;
v_25791:
    if (v_26084 == nil) goto v_25789;
    v_26084 = qvalue(elt(env, 8)); // !*depend
    v_26084 = (v_26084 == nil ? lisp_true : nil);
    goto v_25787;
v_25789:
    v_26084 = nil;
    goto v_25787;
    v_26084 = nil;
v_25787:
    goto v_25775;
v_25777:
    v_26084 = nil;
    goto v_25775;
    v_26084 = nil;
v_25775:
    if (v_26084 == nil) goto v_25773;
    goto v_25835;
v_25831:
    v_26085 = nil;
    goto v_25832;
v_25833:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25834;
v_25835:
    goto v_25831;
v_25832:
    goto v_25833;
v_25834:
    return cons(v_26085, v_26084);
v_25773:
    v_26084 = qvalue(elt(env, 9)); // !*expanddf
    if (v_26084 == nil) goto v_25839;
    v_26084 = stack[-8];
    if (!consp(v_26084)) goto v_25846;
    v_26084 = stack[0];
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    if (v_26084 == nil) goto v_25850;
    else goto v_25851;
v_25850:
    goto v_25864;
v_25860:
    v_26084 = stack[-8];
    v_26085 = qcar(v_26084);
    goto v_25861;
v_25862:
    v_26084 = elt(env, 20); // (df int)
    goto v_25863;
v_25864:
    goto v_25860;
v_25861:
    goto v_25862;
v_25863:
    v_26084 = Lmemq(nil, v_26085, v_26084);
    if (v_26084 == nil) goto v_25858;
    else goto v_25859;
v_25858:
    goto v_25878;
v_25874:
    v_26085 = stack[-7];
    goto v_25875;
v_25876:
    v_26084 = stack[-8];
    goto v_25877;
v_25878:
    goto v_25874;
v_25875:
    goto v_25876;
v_25877:
    fn = elt(env, 44); // smember
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    if (v_26084 == nil) goto v_25871;
    else goto v_25872;
v_25871:
    goto v_25889;
v_25885:
    v_26085 = stack[-8];
    goto v_25886;
v_25887:
    v_26084 = qvalue(elt(env, 7)); // powlis!*
    goto v_25888;
v_25889:
    goto v_25885;
v_25886:
    goto v_25887;
v_25888:
    v_26084 = Latsoc(nil, v_26085, v_26084);
    stack[-6] = v_26084;
    if (v_26084 == nil) goto v_25883;
    else goto v_25884;
v_25883:
    v_26084 = lisp_true;
    goto v_25882;
v_25884:
    goto v_25901;
v_25897:
    v_26084 = stack[-6];
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    v_26084 = qcdr(v_26084);
    v_26085 = qcar(v_26084);
    goto v_25898;
v_25899:
    v_26084 = stack[-7];
    goto v_25900;
v_25901:
    goto v_25897;
v_25898:
    goto v_25899;
v_25900:
    fn = elt(env, 35); // depends
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    v_26084 = (v_26084 == nil ? lisp_true : nil);
    goto v_25882;
    v_26084 = nil;
v_25882:
    goto v_25870;
v_25872:
    v_26084 = nil;
    goto v_25870;
    v_26084 = nil;
v_25870:
    goto v_25857;
v_25859:
    v_26084 = nil;
    goto v_25857;
    v_26084 = nil;
v_25857:
    goto v_25849;
v_25851:
    v_26084 = nil;
    goto v_25849;
    v_26084 = nil;
v_25849:
    goto v_25844;
v_25846:
    v_26084 = nil;
    goto v_25844;
    v_26084 = nil;
v_25844:
    if (v_26084 == nil) goto v_25839;
    goto v_25925;
v_25921:
    v_26085 = stack[-8];
    goto v_25922;
v_25923:
    v_26084 = qvalue(elt(env, 10)); // depl!*
    goto v_25924;
v_25925:
    goto v_25921;
v_25922:
    goto v_25923;
v_25924:
    v_26084 = Lassoc(nil, v_26085, v_26084);
    stack[-6] = v_26084;
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    if (v_26084 == nil) goto v_25931;
    else goto v_25932;
v_25931:
    v_26084 = nil;
    goto v_25930;
v_25932:
    v_26084 = stack[-8];
    v_26084 = qcdr(v_26084);
    fn = elt(env, 45); // get!-all!-kernels
    v_26084 = (*qfn1(fn))(fn, v_26084);
    env = stack[-10];
    goto v_25930;
    v_26084 = nil;
v_25930:
    stack[-5] = v_26084;
    v_26084 = stack[-6];
    if (v_26084 == nil) goto v_25944;
    v_26084 = stack[-5];
    if (v_26084 == nil) goto v_25944;
    goto v_25956;
v_25952:
    goto v_25962;
v_25958:
    v_26085 = stack[-7];
    goto v_25959;
v_25960:
    v_26084 = stack[-5];
    goto v_25961;
v_25962:
    goto v_25958;
v_25959:
    goto v_25960;
v_25961:
    v_26085 = Ldelete(nil, v_26085, v_26084);
    env = stack[-10];
    goto v_25953;
v_25954:
    v_26084 = stack[-7];
    goto v_25955;
v_25956:
    goto v_25952;
v_25953:
    goto v_25954;
v_25955:
    fn = elt(env, 46); // ldepends
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    if (v_26084 == nil) goto v_25944;
    goto v_25977;
v_25967:
    v_26088 = elt(env, 21); // "Possible inconsistent dependencies in"
    goto v_25968;
v_25969:
    v_26087 = stack[-8];
    goto v_25970;
v_25971:
    v_26086 = nil;
    goto v_25972;
v_25973:
    v_26085 = nil;
    goto v_25974;
v_25975:
    v_26084 = nil;
    goto v_25976;
v_25977:
    goto v_25967;
v_25968:
    goto v_25969;
v_25970:
    goto v_25971;
v_25972:
    goto v_25973;
v_25974:
    goto v_25975;
v_25976:
    fn = elt(env, 51); // msgpri
    v_26084 = (*qfnn(fn))(fn, 5, v_26088, v_26087, v_26086, v_26085, v_26084);
    env = stack[-10];
    goto v_25988;
v_25984:
    v_26085 = stack[0];
    goto v_25985;
v_25986:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25987;
v_25988:
    goto v_25984;
v_25985:
    goto v_25986;
v_25987:
    fn = elt(env, 38); // mksq
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_25942;
v_25944:
    v_26084 = stack[-6];
    if (v_26084 == nil) goto v_25992;
    goto v_26002;
v_25998:
    v_26085 = stack[-7];
    goto v_25999;
v_26000:
    v_26084 = stack[-6];
    v_26084 = qcdr(v_26084);
    stack[-6] = v_26084;
    goto v_26001;
v_26002:
    goto v_25998;
v_25999:
    goto v_26000;
v_26001:
    v_26084 = Lmemq(nil, v_26085, v_26084);
    if (v_26084 == nil) goto v_25997;
    goto v_26012;
v_26008:
    v_26085 = stack[0];
    goto v_26009;
v_26010:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26011;
v_26012:
    goto v_26008;
v_26009:
    goto v_26010;
v_26011:
    fn = elt(env, 38); // mksq
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_25995;
v_25997:
    goto v_26024;
v_26018:
    v_26086 = stack[-8];
    goto v_26019;
v_26020:
    v_26085 = stack[-7];
    goto v_26021;
v_26022:
    v_26084 = stack[-6];
    goto v_26023;
v_26024:
    goto v_26018;
v_26019:
    goto v_26020;
v_26021:
    goto v_26022;
v_26023:
    fn = elt(env, 36); // df!-chain!-rule
    v_26084 = (*qfnn(fn))(fn, 3, v_26086, v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_25995;
v_25995:
    goto v_25942;
v_25992:
    v_26084 = stack[-5];
    if (v_26084 == nil) goto v_26029;
    goto v_26040;
v_26036:
    v_26085 = stack[-7];
    goto v_26037;
v_26038:
    v_26084 = stack[-5];
    goto v_26039;
v_26040:
    goto v_26036;
v_26037:
    goto v_26038;
v_26039:
    fn = elt(env, 44); // smember
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    if (v_26084 == nil) goto v_26034;
    goto v_26048;
v_26044:
    v_26085 = stack[0];
    goto v_26045;
v_26046:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26047;
v_26048:
    goto v_26044;
v_26045:
    goto v_26046;
v_26047:
    fn = elt(env, 38); // mksq
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    goto v_26032;
v_26034:
    goto v_26060;
v_26054:
    v_26086 = stack[-8];
    goto v_26055;
v_26056:
    v_26085 = stack[-7];
    goto v_26057;
v_26058:
    v_26084 = stack[-5];
    goto v_26059;
v_26060:
    goto v_26054;
v_26055:
    goto v_26056;
v_26057:
    goto v_26058;
v_26059:
    fn = elt(env, 36); // df!-chain!-rule
    v_26084 = (*qfnn(fn))(fn, 3, v_26086, v_26085, v_26084);
    env = stack[-10];
    goto v_26032;
    v_26084 = nil;
v_26032:
    stack[0] = v_26084;
    goto v_25942;
v_26029:
    goto v_26071;
v_26067:
    v_26085 = stack[0];
    goto v_26068;
v_26069:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26070;
v_26071:
    goto v_26067;
v_26068:
    goto v_26069;
v_26070:
    fn = elt(env, 38); // mksq
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_25942;
v_25942:
    goto v_25765;
v_25839:
    goto v_26081;
v_26077:
    v_26085 = stack[0];
    goto v_26078;
v_26079:
    v_26084 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26080;
v_26081:
    goto v_26077;
v_26078:
    goto v_26079;
v_26080:
    fn = elt(env, 38); // mksq
    v_26084 = (*qfn2(fn))(fn, v_26085, v_26084);
    env = stack[-10];
    stack[0] = v_26084;
    goto v_25765;
v_25765:
    goto v_24539;
    return onevalue(v_26084);
}



// Code for letmtr

static LispObject CC_letmtr(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24623, v_24624, v_24625;
    LispObject fn;
    LispObject v_24528, v_24527, v_24526;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "letmtr");
    va_start(aa, nargs);
    v_24526 = va_arg(aa, LispObject);
    v_24527 = va_arg(aa, LispObject);
    v_24528 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24528,v_24527,v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24526,v_24527,v_24528);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_24528;
    stack[-3] = v_24527;
    stack[-4] = v_24526;
// end of prologue
    stack[-5] = nil;
    goto v_24542;
v_24538:
    v_24624 = stack[-2];
    goto v_24539;
v_24540:
    v_24623 = elt(env, 1); // mat
    goto v_24541;
v_24542:
    goto v_24538;
v_24539:
    goto v_24540;
v_24541:
    if (!consp(v_24624)) goto v_24535;
    v_24624 = qcar(v_24624);
    if (v_24624 == v_24623) goto v_24536;
v_24535:
    goto v_24552;
v_24546:
    stack[-1] = elt(env, 2); // matrix
    goto v_24547;
v_24548:
    stack[0] = (LispObject)160+TAG_FIXNUM; // 10
    goto v_24549;
v_24550:
    goto v_24562;
v_24556:
    v_24625 = elt(env, 3); // "Matrix"
    goto v_24557;
v_24558:
    v_24623 = stack[-4];
    v_24624 = qcar(v_24623);
    goto v_24559;
v_24560:
    v_24623 = elt(env, 4); // "not set"
    goto v_24561;
v_24562:
    goto v_24556;
v_24557:
    goto v_24558;
v_24559:
    goto v_24560;
v_24561:
    v_24623 = list3(v_24625, v_24624, v_24623);
    env = stack[-6];
    goto v_24551;
v_24552:
    goto v_24546;
v_24547:
    goto v_24548;
v_24549:
    goto v_24550;
v_24551:
    fn = elt(env, 6); // rerror
    v_24623 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_24623);
    env = stack[-6];
    goto v_24534;
v_24536:
    v_24623 = stack[-4];
    v_24623 = qcdr(v_24623);
    fn = elt(env, 7); // revlis
    v_24623 = (*qfn1(fn))(fn, v_24623);
    env = stack[-6];
    stack[-5] = v_24623;
    fn = elt(env, 8); // numlis
    v_24623 = (*qfn1(fn))(fn, v_24623);
    env = stack[-6];
    if (v_24623 == nil) goto v_24571;
    else goto v_24572;
v_24571:
    v_24623 = lisp_true;
    goto v_24570;
v_24572:
    goto v_24585;
v_24581:
    v_24623 = stack[-5];
    v_24624 = Llength(nil, v_24623);
    env = stack[-6];
    goto v_24582;
v_24583:
    v_24623 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_24584;
v_24585:
    goto v_24581;
v_24582:
    goto v_24583;
v_24584:
    v_24623 = Lneq(nil, v_24624, v_24623);
    env = stack[-6];
    goto v_24570;
    v_24623 = nil;
v_24570:
    if (v_24623 == nil) goto v_24568;
    goto v_24594;
v_24590:
    v_24624 = stack[-4];
    goto v_24591;
v_24592:
    v_24623 = elt(env, 5); // hold
    goto v_24593;
v_24594:
    goto v_24590;
v_24591:
    goto v_24592;
v_24593:
    {
        fn = elt(env, 9); // errpri2
        return (*qfn2(fn))(fn, v_24624, v_24623);
    }
v_24568:
v_24534:
    goto v_24602;
v_24598:
    goto v_24608;
v_24604:
    goto v_24614;
v_24610:
    v_24623 = stack[-2];
    v_24624 = qcdr(v_24623);
    goto v_24611;
v_24612:
    v_24623 = stack[-5];
    v_24623 = qcar(v_24623);
    goto v_24613;
v_24614:
    goto v_24610;
v_24611:
    goto v_24612;
v_24613:
    fn = elt(env, 10); // nth
    v_24624 = (*qfn2(fn))(fn, v_24624, v_24623);
    env = stack[-6];
    goto v_24605;
v_24606:
    v_24623 = stack[-5];
    v_24623 = qcdr(v_24623);
    v_24623 = qcar(v_24623);
    goto v_24607;
v_24608:
    goto v_24604;
v_24605:
    goto v_24606;
v_24607:
    fn = elt(env, 11); // pnth
    v_24624 = (*qfn2(fn))(fn, v_24624, v_24623);
    env = stack[-6];
    goto v_24599;
v_24600:
    v_24623 = stack[-3];
    goto v_24601;
v_24602:
    goto v_24598;
v_24599:
    goto v_24600;
v_24601:
    v_24623 = Lrplaca(nil, v_24624, v_24623);
    v_24623 = nil;
    return onevalue(v_24623);
}



// Code for xpartitop

static LispObject CC_xpartitop(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24531;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24526);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_24531 = v_24526;
// end of prologue
    fn = elt(env, 1); // simp!*
    v_24531 = (*qfn1(fn))(fn, v_24531);
    env = stack[0];
    {
        fn = elt(env, 2); // xpartitsq
        return (*qfn1(fn))(fn, v_24531);
    }
}



// Code for r2oaddspecies

static LispObject CC_r2oaddspecies(LispObject env,
                         LispObject v_24526, LispObject v_24527)
{
    env = qenv(env);
    LispObject v_24564, v_24565;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24527,v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24526,v_24527);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24527;
    stack[-1] = v_24526;
// end of prologue
    goto v_24537;
v_24533:
    v_24565 = stack[-1];
    goto v_24534;
v_24535:
    v_24564 = stack[0];
    goto v_24536;
v_24537:
    goto v_24533;
v_24534:
    goto v_24535;
v_24536:
    v_24564 = Lassoc(nil, v_24565, v_24564);
    if (v_24564 == nil) goto v_24532;
    v_24564 = stack[0];
    goto v_24530;
v_24532:
    v_24564 = elt(env, 1); // "new species: "
    v_24564 = Lprinc(nil, v_24564);
    env = stack[-2];
    v_24564 = stack[-1];
    fn = elt(env, 2); // prin2t
    v_24564 = (*qfn1(fn))(fn, v_24564);
    env = stack[-2];
    goto v_24553;
v_24549:
    goto v_24550;
v_24551:
    goto v_24561;
v_24557:
    v_24565 = stack[-1];
    goto v_24558;
v_24559:
    v_24564 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24560;
v_24561:
    goto v_24557;
v_24558:
    goto v_24559;
v_24560:
    v_24564 = cons(v_24565, v_24564);
    env = stack[-2];
    v_24564 = ncons(v_24564);
    goto v_24552;
v_24553:
    goto v_24549;
v_24550:
    goto v_24551;
v_24552:
    {
        LispObject v_24568 = stack[0];
        return Lappend(nil, v_24568, v_24564);
    }
    v_24564 = nil;
v_24530:
    return onevalue(v_24564);
}



// Code for ev!-poles

static LispObject CC_evKpoles(LispObject env,
                         LispObject v_24526, LispObject v_24527)
{
    env = qenv(env);
    LispObject v_24561, v_24562, v_24563, v_24564;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24562 = v_24527;
    v_24563 = v_24526;
// end of prologue
v_24531:
    v_24561 = v_24563;
    if (v_24561 == nil) goto v_24534;
    else goto v_24535;
v_24534:
    v_24561 = nil;
    goto v_24530;
v_24535:
    goto v_24544;
v_24540:
    goto v_24549;
v_24545:
    v_24561 = v_24563;
    v_24564 = qcar(v_24561);
    goto v_24546;
v_24547:
    v_24561 = v_24562;
    goto v_24548;
v_24549:
    goto v_24545;
v_24546:
    goto v_24547;
v_24548:
    v_24561 = Lassoc(nil, v_24564, v_24561);
    v_24564 = qcdr(v_24561);
    goto v_24541;
v_24542:
    v_24561 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24543;
v_24544:
    goto v_24540;
v_24541:
    goto v_24542;
v_24543:
    if (v_24564 == v_24561) goto v_24538;
    else goto v_24539;
v_24538:
    v_24561 = v_24563;
    v_24561 = qcdr(v_24561);
    v_24563 = v_24561;
    goto v_24531;
v_24539:
    v_24561 = v_24563;
    goto v_24530;
    v_24561 = nil;
v_24530:
    return onevalue(v_24561);
}



// Code for dfp!-rule!-found

static LispObject CC_dfpKruleKfound(LispObject env,
                         LispObject v_24526, LispObject v_24527)
{
    env = qenv(env);
    LispObject v_24554, v_24555, v_24556, v_24557;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24555 = v_24527;
    v_24556 = v_24526;
// end of prologue
    goto v_24538;
v_24534:
    v_24554 = v_24556;
    goto v_24535;
v_24536:
    v_24557 = elt(env, 1); // dfp
    goto v_24537;
v_24538:
    goto v_24534;
v_24535:
    goto v_24536;
v_24537:
    if (!consp(v_24554)) goto v_24531;
    v_24554 = qcar(v_24554);
    if (v_24554 == v_24557) goto v_24532;
v_24531:
    v_24554 = lisp_true;
    goto v_24530;
v_24532:
    goto v_24549;
v_24545:
    v_24554 = v_24556;
    v_24554 = qcdr(v_24554);
    v_24554 = qcar(v_24554);
    goto v_24546;
v_24547:
    goto v_24548;
v_24549:
    goto v_24545;
v_24546:
    goto v_24547;
v_24548:
        return Lneq(nil, v_24554, v_24555);
    v_24554 = nil;
v_24530:
    return onevalue(v_24554);
}



// Code for mv!-compact2

static LispObject CC_mvKcompact2(LispObject env,
                         LispObject v_24526, LispObject v_24527)
{
    env = qenv(env);
    LispObject v_24588, v_24589, v_24590;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24527,v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24526,v_24527);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_24527;
    stack[-1] = v_24526;
// end of prologue
    goto v_24539;
v_24535:
    v_24589 = stack[-1];
    goto v_24536;
v_24537:
    v_24588 = stack[0];
    goto v_24538;
v_24539:
    goto v_24535;
v_24536:
    goto v_24537;
v_24538:
    fn = elt(env, 1); // equiv!-coeffs
    v_24588 = (*qfn2(fn))(fn, v_24589, v_24588);
    env = stack[-3];
    stack[-2] = v_24588;
    v_24588 = stack[0];
    fn = elt(env, 2); // mv!-domainlist
    v_24588 = (*qfn1(fn))(fn, v_24588);
    env = stack[-3];
    goto v_24549;
v_24545:
    v_24589 = stack[-2];
    goto v_24546;
v_24547:
    goto v_24548;
v_24549:
    goto v_24545;
v_24546:
    goto v_24547;
v_24548:
    fn = elt(env, 3); // reduce
    v_24588 = (*qfn2(fn))(fn, v_24589, v_24588);
    env = stack[-3];
    v_24590 = v_24588;
    goto v_24560;
v_24556:
    v_24589 = v_24590;
    goto v_24557;
v_24558:
    v_24588 = stack[-2];
    goto v_24559;
v_24560:
    goto v_24556;
v_24557:
    goto v_24558;
v_24559:
    if (equal(v_24589, v_24588)) goto v_24554;
    else goto v_24555;
v_24554:
    v_24588 = nil;
    goto v_24553;
v_24555:
    goto v_24571;
v_24567:
    goto v_24577;
v_24573:
    goto v_24574;
v_24575:
    goto v_24584;
v_24580:
    v_24589 = v_24590;
    goto v_24581;
v_24582:
    v_24588 = stack[-2];
    goto v_24583;
v_24584:
    goto v_24580;
v_24581:
    goto v_24582;
v_24583:
    fn = elt(env, 4); // mv!-domainlist!-!-
    v_24588 = (*qfn2(fn))(fn, v_24589, v_24588);
    env = stack[-3];
    goto v_24576;
v_24577:
    goto v_24573;
v_24574:
    goto v_24575;
v_24576:
    fn = elt(env, 5); // mv!-coeff!-replace
    v_24589 = (*qfn2(fn))(fn, stack[0], v_24588);
    env = stack[-3];
    goto v_24568;
v_24569:
    v_24588 = stack[-1];
    goto v_24570;
v_24571:
    goto v_24567;
v_24568:
    goto v_24569;
v_24570:
    {
        fn = elt(env, 6); // mv!-!+
        return (*qfn2(fn))(fn, v_24589, v_24588);
    }
    v_24588 = nil;
v_24553:
    return onevalue(v_24588);
}



// Code for prepcadr

static LispObject CC_prepcadr(LispObject env,
                         LispObject v_24526)
{
    env = qenv(env);
    LispObject v_24532;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24532 = v_24526;
// end of prologue
    v_24532 = qcdr(v_24532);
    v_24532 = qcar(v_24532);
    {
        fn = elt(env, 1); // prepsq
        return (*qfn1(fn))(fn, v_24532);
    }
}



// Code for listminimize

static LispObject CC_listminimize(LispObject env,
                         LispObject v_24526, LispObject v_24527)
{
    env = qenv(env);
    LispObject v_24549, v_24550, v_24551;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24527,v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24526,v_24527);
    }
// copy arguments values to proper place
    v_24549 = v_24527;
    v_24550 = v_24526;
// end of prologue
    v_24551 = v_24550;
    if (v_24551 == nil) goto v_24531;
    else goto v_24532;
v_24531:
    v_24549 = nil;
    goto v_24530;
v_24532:
    goto v_24545;
v_24539:
    v_24551 = nil;
    goto v_24540;
v_24541:
    goto v_24542;
v_24543:
    goto v_24544;
v_24545:
    goto v_24539;
v_24540:
    goto v_24541;
v_24542:
    goto v_24543;
v_24544:
    fn = elt(env, 1); // cali!=min
    v_24549 = (*qfnn(fn))(fn, 3, v_24551, v_24550, v_24549);
        return Lreverse(nil, v_24549);
    v_24549 = nil;
v_24530:
    return onevalue(v_24549);
}



// Code for general!-multiply!-by!-constant!-mod!-p

static LispObject CC_generalKmultiplyKbyKconstantKmodKp(LispObject env,
                         LispObject v_24526, LispObject v_24527)
{
    env = qenv(env);
    LispObject v_24611, v_24612, v_24613;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24527,v_24526);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24526,v_24527);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_24527;
    stack[-1] = v_24526;
// end of prologue
    v_24611 = stack[-1];
    if (v_24611 == nil) goto v_24531;
    else goto v_24532;
v_24531:
    v_24611 = nil;
    goto v_24530;
v_24532:
    goto v_24541;
v_24537:
    v_24612 = stack[0];
    goto v_24538;
v_24539:
    v_24611 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24540;
v_24541:
    goto v_24537;
v_24538:
    goto v_24539;
v_24540:
    if (v_24612 == v_24611) goto v_24535;
    else goto v_24536;
v_24535:
    v_24611 = stack[-1];
    goto v_24530;
v_24536:
    v_24611 = stack[-1];
    if (!consp(v_24611)) goto v_24549;
    else goto v_24550;
v_24549:
    v_24611 = lisp_true;
    goto v_24548;
v_24550:
    v_24611 = stack[-1];
    v_24611 = qcar(v_24611);
    v_24611 = (consp(v_24611) ? nil : lisp_true);
    goto v_24548;
    v_24611 = nil;
v_24548:
    if (v_24611 == nil) goto v_24546;
    goto v_24564;
v_24560:
    v_24612 = stack[-1];
    goto v_24561;
v_24562:
    v_24611 = stack[0];
    goto v_24563;
v_24564:
    goto v_24560;
v_24561:
    goto v_24562;
v_24563:
    fn = elt(env, 1); // general!-modular!-times
    v_24611 = (*qfn2(fn))(fn, v_24612, v_24611);
    env = stack[-3];
    {
        fn = elt(env, 2); // !*n2f
        return (*qfn1(fn))(fn, v_24611);
    }
v_24546:
    goto v_24574;
v_24570:
    v_24611 = stack[-1];
    v_24611 = qcar(v_24611);
    v_24612 = qcdr(v_24611);
    goto v_24571;
v_24572:
    v_24611 = stack[0];
    goto v_24573;
v_24574:
    goto v_24570;
v_24571:
    goto v_24572;
v_24573:
    stack[-2] = CC_generalKmultiplyKbyKconstantKmodKp(elt(env, 0), v_24612, v_24611);
    env = stack[-3];
    goto v_24584;
v_24580:
    v_24611 = stack[-1];
    v_24612 = qcdr(v_24611);
    goto v_24581;
v_24582:
    v_24611 = stack[0];
    goto v_24583;
v_24584:
    goto v_24580;
v_24581:
    goto v_24582;
v_24583:
    v_24611 = CC_generalKmultiplyKbyKconstantKmodKp(elt(env, 0), v_24612, v_24611);
    v_24612 = stack[-2];
    v_24613 = v_24612;
    if (v_24613 == nil) goto v_24592;
    else goto v_24593;
v_24592:
    goto v_24591;
v_24593:
    goto v_24605;
v_24599:
    v_24613 = stack[-1];
    v_24613 = qcar(v_24613);
    v_24613 = qcar(v_24613);
    goto v_24600;
v_24601:
    goto v_24602;
v_24603:
    goto v_24604;
v_24605:
    goto v_24599;
v_24600:
    goto v_24601;
v_24602:
    goto v_24603;
v_24604:
    return acons(v_24613, v_24612, v_24611);
    v_24611 = nil;
v_24591:
    goto v_24530;
    v_24611 = nil;
v_24530:
    return onevalue(v_24611);
}



setup_type const u43_setup[] =
{
    {"numir",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_numir},
    {"mkexpt",                  TOO_FEW_2,      CC_mkexpt,     WRONG_NO_2},
    {"evalmember",              TOO_FEW_2,      CC_evalmember, WRONG_NO_2},
    {"e*",                      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_eH},
    {"gpargp",                  CC_gpargp,      TOO_MANY_1,    WRONG_NO_1},
    {"indexvp",                 CC_indexvp,     TOO_MANY_1,    WRONG_NO_1},
    {"extract_vars",            CC_extract_vars,TOO_MANY_1,    WRONG_NO_1},
    {"ev_mtest?",               TOO_FEW_2,      CC_ev_mtestW,  WRONG_NO_2},
    {"cgp_greenp",              CC_cgp_greenp,  TOO_MANY_1,    WRONG_NO_1},
    {"matrixml",                CC_matrixml,    TOO_MANY_1,    WRONG_NO_1},
    {"ps:arg-values",           CC_psTargKvalues,TOO_MANY_1,   WRONG_NO_1},
    {"diford",                  CC_diford,      TOO_MANY_1,    WRONG_NO_1},
    {"specrd:times",            TOO_FEW_2,      CC_specrdTtimes,WRONG_NO_2},
    {"remdiff",                 CC_remdiff,     TOO_MANY_1,    WRONG_NO_1},
    {"remove_least_item",       CC_remove_least_item,TOO_MANY_1,WRONG_NO_1},
    {"nspaces",                 CC_nspaces,     TOO_MANY_1,    WRONG_NO_1},
    {"mk_simpl_map_",           CC_mk_simpl_map_,TOO_MANY_1,   WRONG_NO_1},
    {"mk_dummy_ids",            CC_mk_dummy_ids,TOO_MANY_1,    WRONG_NO_1},
    {"createtriple",            CC_createtriple,TOO_MANY_1,    WRONG_NO_1},
    {"totalcompareconstants",   TOO_FEW_2,      CC_totalcompareconstants,WRONG_NO_2},
    {"gigcdsq",                 TOO_FEW_2,      CC_gigcdsq,    WRONG_NO_2},
    {"simpexpt2",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_simpexpt2},
    {"mk+resimp+mat",           CC_mkLresimpLmat,TOO_MANY_1,   WRONG_NO_1},
    {"talp_invtscsimpl",        CC_talp_invtscsimpl,TOO_MANY_1,WRONG_NO_1},
    {"conditionrd",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_conditionrd},
    {"ieval",                   CC_ieval,       TOO_MANY_1,    WRONG_NO_1},
    {"znumrnil",                CC_znumrnil,    TOO_MANY_1,    WRONG_NO_1},
    {"diffp",                   TOO_FEW_2,      CC_diffp,      WRONG_NO_2},
    {"letmtr",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_letmtr},
    {"xpartitop",               CC_xpartitop,   TOO_MANY_1,    WRONG_NO_1},
    {"r2oaddspecies",           TOO_FEW_2,      CC_r2oaddspecies,WRONG_NO_2},
    {"ev-poles",                TOO_FEW_2,      CC_evKpoles,   WRONG_NO_2},
    {"dfp-rule-found",          TOO_FEW_2,      CC_dfpKruleKfound,WRONG_NO_2},
    {"mv-compact2",             TOO_FEW_2,      CC_mvKcompact2,WRONG_NO_2},
    {"prepcadr",                CC_prepcadr,    TOO_MANY_1,    WRONG_NO_1},
    {"listminimize",            TOO_FEW_2,      CC_listminimize,WRONG_NO_2},
    {"general-multiply-by-constant-mod-p",TOO_FEW_2,CC_generalKmultiplyKbyKconstantKmodKp,WRONG_NO_2},
    {NULL, (one_args *)"u43", (two_args *)"45121 9993862 2917546", 0}
};

// end of generated code
