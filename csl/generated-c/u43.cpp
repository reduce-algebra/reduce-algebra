
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



// Code for redall

static LispObject CC_redall(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24297, v_24298, v_24299;
    LispObject fn;
    LispObject v_24035, v_24034, v_24033;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "redall");
    va_start(aa, nargs);
    v_24033 = va_arg(aa, LispObject);
    v_24034 = va_arg(aa, LispObject);
    v_24035 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24035,v_24034,v_24033);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24033,v_24034,v_24035);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_24035;
    v_24298 = v_24034;
    v_24297 = v_24033;
// end of prologue
// Binding gg!*
// FLUIDBIND: reloadenv=9 litvec-offset=1 saveloc=8
{   bind_fluid_stack bind_fluid_var(-9, 1, -8);
    qvalue(elt(env, 1)) = v_24297; // gg!*
    v_24297 = v_24298;
    stack[-6] = v_24297;
    v_24297 = nil;
    qvalue(elt(env, 3)) = v_24297; // shortway!*
    qvalue(elt(env, 4)) = v_24297; // thirdway!*
    v_24297 = lisp_true;
    stack[-1] = v_24297;
v_24055:
    v_24297 = stack[-6];
    if (v_24297 == nil) goto v_24058;
    else goto v_24059;
v_24058:
    goto v_24054;
v_24059:
    v_24297 = stack[-6];
    v_24297 = Lreverse(nil, v_24297);
    env = stack[-9];
    v_24297 = qcar(v_24297);
    stack[-5] = v_24297;
    goto v_24070;
v_24066:
    v_24298 = stack[-5];
    goto v_24067;
v_24068:
    v_24297 = stack[-6];
    goto v_24069;
v_24070:
    goto v_24066;
v_24067:
    goto v_24068;
v_24069:
    v_24297 = Ldelete(nil, v_24298, v_24297);
    env = stack[-9];
    stack[-6] = v_24297;
    v_24297 = stack[-5];
    v_24297 = qcar(v_24297);
    stack[-2] = v_24297;
    goto v_24079;
v_24075:
    v_24298 = qvalue(elt(env, 5)); // gv!*
    goto v_24076;
v_24077:
    v_24297 = stack[-2];
    goto v_24078;
v_24079:
    goto v_24075;
v_24076:
    goto v_24077;
v_24078:
    v_24297 = *(LispObject *)((char *)v_24298 + (CELL-TAG_VECTOR) + (((intptr_t)v_24297-TAG_FIXNUM)/(16/CELL)));
    stack[-4] = v_24297;
    v_24297 = qvalue(elt(env, 6)); // path
    if (v_24297 == nil) goto v_24086;
    v_24297 = stack[-1];
    if (v_24297 == nil) goto v_24091;
    v_24297 = stack[-4];
    fn = elt(env, 11); // ljet
    v_24297 = (*qfn1(fn))(fn, v_24297);
    env = stack[-9];
    v_24297 = Lprinc(nil, v_24297);
    env = stack[-9];
    v_24297 = elt(env, 7); // " ==> "
    v_24297 = Lprinc(nil, v_24297);
    env = stack[-9];
    goto v_24089;
v_24091:
    v_24297 = stack[-4];
    fn = elt(env, 11); // ljet
    v_24297 = (*qfn1(fn))(fn, v_24297);
    env = stack[-9];
    v_24297 = Lprinc(nil, v_24297);
    env = stack[-9];
    v_24297 = elt(env, 8); // " --> "
    v_24297 = Lprinc(nil, v_24297);
    env = stack[-9];
    goto v_24089;
v_24089:
    goto v_24084;
v_24086:
v_24084:
    goto v_24114;
v_24108:
    stack[-3] = qvalue(elt(env, 5)); // gv!*
    goto v_24109;
v_24110:
    stack[0] = stack[-2];
    goto v_24111;
v_24112:
    goto v_24124;
v_24118:
    v_24299 = stack[-4];
    goto v_24119;
v_24120:
    v_24298 = qvalue(elt(env, 1)); // gg!*
    goto v_24121;
v_24122:
    v_24297 = stack[-7];
    goto v_24123;
v_24124:
    goto v_24118;
v_24119:
    goto v_24120;
v_24121:
    goto v_24122;
v_24123:
    fn = elt(env, 12); // nf
    v_24297 = (*qfnn(fn))(fn, 3, v_24299, v_24298, v_24297);
    env = stack[-9];
    goto v_24113;
v_24114:
    goto v_24108;
v_24109:
    goto v_24110;
v_24111:
    goto v_24112;
v_24113:
    *(LispObject *)((char *)stack[-3] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_24297;
    stack[-5] = v_24297;
    v_24297 = stack[-5];
    if (v_24297 == nil) goto v_24131;
    v_24297 = stack[-5];
    fn = elt(env, 11); // ljet
    v_24297 = (*qfn1(fn))(fn, v_24297);
    env = stack[-9];
    goto v_24129;
v_24131:
    v_24297 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24129;
    v_24297 = nil;
v_24129:
    stack[-3] = v_24297;
    v_24297 = qvalue(elt(env, 6)); // path
    if (v_24297 == nil) goto v_24141;
    v_24297 = stack[-3];
    v_24297 = Lprinc(nil, v_24297);
    env = stack[-9];
    v_24297 = Lterpri(nil, 0);
    env = stack[-9];
    goto v_24139;
v_24141:
v_24139:
    v_24297 = stack[-5];
    if (v_24297 == nil) goto v_24149;
    else goto v_24150;
v_24149:
    goto v_24148;
v_24150:
    goto v_24159;
v_24155:
    v_24297 = stack[-3];
    fn = elt(env, 13); // ord
    v_24298 = (*qfn1(fn))(fn, v_24297);
    env = stack[-9];
    goto v_24156;
v_24157:
    v_24297 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24158;
v_24159:
    goto v_24155;
v_24156:
    goto v_24157;
v_24158:
    if (v_24298 == v_24297) goto v_24153;
    else goto v_24154;
v_24153:
    goto v_24168;
v_24164:
    v_24298 = stack[-5];
    goto v_24165;
v_24166:
    v_24297 = qvalue(elt(env, 9)); // conds!*
    goto v_24167;
v_24168:
    goto v_24164;
v_24165:
    goto v_24166;
v_24167:
    v_24297 = cons(v_24298, v_24297);
    env = stack[-9];
    qvalue(elt(env, 9)) = v_24297; // conds!*
    goto v_24148;
v_24154:
    goto v_24181;
v_24177:
    v_24297 = stack[-5];
    fn = elt(env, 11); // ljet
    stack[0] = (*qfn1(fn))(fn, v_24297);
    env = stack[-9];
    goto v_24178;
v_24179:
    v_24297 = stack[-4];
    fn = elt(env, 11); // ljet
    v_24297 = (*qfn1(fn))(fn, v_24297);
    env = stack[-9];
    goto v_24180;
v_24181:
    goto v_24177;
v_24178:
    goto v_24179;
v_24180:
    if (equal(stack[0], v_24297)) goto v_24176;
    v_24297 = lisp_true;
    qvalue(elt(env, 3)) = v_24297; // shortway!*
    goto v_24174;
v_24176:
v_24174:
    v_24297 = stack[-1];
    if (v_24297 == nil) goto v_24193;
    else goto v_24194;
v_24193:
    goto v_24201;
v_24197:
    v_24298 = stack[-5];
    goto v_24198;
v_24199:
    v_24297 = stack[-4];
    goto v_24200;
v_24201:
    goto v_24197;
v_24198:
    goto v_24199;
v_24200:
    v_24297 = Lneq(nil, v_24298, v_24297);
    env = stack[-9];
    goto v_24192;
v_24194:
    v_24297 = nil;
    goto v_24192;
    v_24297 = nil;
v_24192:
    if (v_24297 == nil) goto v_24190;
    v_24297 = lisp_true;
    qvalue(elt(env, 4)) = v_24297; // thirdway!*
    goto v_24188;
v_24190:
v_24188:
    v_24297 = qvalue(elt(env, 1)); // gg!*
    stack[-4] = v_24297;
v_24211:
    v_24297 = stack[-4];
    if (v_24297 == nil) goto v_24215;
    else goto v_24216;
v_24215:
    goto v_24210;
v_24216:
    v_24297 = stack[-4];
    v_24297 = qcar(v_24297);
    stack[-1] = v_24297;
    goto v_24231;
v_24227:
    goto v_24237;
v_24233:
    v_24298 = stack[-3];
    goto v_24234;
v_24235:
    v_24297 = stack[-1];
    v_24297 = qcdr(v_24297);
    goto v_24236;
v_24237:
    goto v_24233;
v_24234:
    goto v_24235;
v_24236:
    fn = elt(env, 14); // dd
    stack[0] = (*qfn2(fn))(fn, v_24298, v_24297);
    env = stack[-9];
    goto v_24228;
v_24229:
    goto v_24246;
v_24242:
    v_24298 = stack[-7];
    goto v_24243;
v_24244:
    v_24297 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_24245;
v_24246:
    goto v_24242;
v_24243:
    goto v_24244;
v_24245:
    v_24297 = plus2(v_24298, v_24297);
    env = stack[-9];
    goto v_24230;
v_24231:
    goto v_24227;
v_24228:
    goto v_24229;
v_24230:
    v_24297 = (LispObject)geq2(stack[0], v_24297);
    v_24297 = v_24297 ? lisp_true : nil;
    env = stack[-9];
    if (v_24297 == nil) goto v_24225;
    goto v_24254;
v_24250:
    v_24298 = stack[-1];
    goto v_24251;
v_24252:
    v_24297 = qvalue(elt(env, 1)); // gg!*
    goto v_24253;
v_24254:
    goto v_24250;
v_24251:
    goto v_24252;
v_24253:
    v_24297 = Ldelete(nil, v_24298, v_24297);
    env = stack[-9];
    qvalue(elt(env, 1)) = v_24297; // gg!*
    goto v_24262;
v_24258:
    v_24298 = stack[-1];
    goto v_24259;
v_24260:
    v_24297 = stack[-6];
    goto v_24261;
v_24262:
    goto v_24258;
v_24259:
    goto v_24260;
v_24261:
    fn = elt(env, 15); // insert
    v_24297 = (*qfn2(fn))(fn, v_24298, v_24297);
    env = stack[-9];
    stack[-6] = v_24297;
    goto v_24271;
v_24265:
    v_24299 = qvalue(elt(env, 10)); // bv!*
    goto v_24266;
v_24267:
    v_24297 = stack[-1];
    v_24298 = qcar(v_24297);
    goto v_24268;
v_24269:
    v_24297 = lisp_true;
    goto v_24270;
v_24271:
    goto v_24265;
v_24266:
    goto v_24267;
v_24268:
    goto v_24269;
v_24270:
    *(LispObject *)((char *)v_24299 + (CELL-TAG_VECTOR) + (((intptr_t)v_24298-TAG_FIXNUM)/(16/CELL))) = v_24297;
    goto v_24223;
v_24225:
v_24223:
    v_24297 = stack[-4];
    v_24297 = qcdr(v_24297);
    stack[-4] = v_24297;
    goto v_24211;
v_24210:
    goto v_24284;
v_24280:
    goto v_24290;
v_24286:
    v_24298 = stack[-2];
    goto v_24287;
v_24288:
    v_24297 = stack[-3];
    goto v_24289;
v_24290:
    goto v_24286;
v_24287:
    goto v_24288;
v_24289:
    v_24298 = cons(v_24298, v_24297);
    env = stack[-9];
    goto v_24281;
v_24282:
    v_24297 = qvalue(elt(env, 1)); // gg!*
    goto v_24283;
v_24284:
    goto v_24280;
v_24281:
    goto v_24282;
v_24283:
    fn = elt(env, 15); // insert
    v_24297 = (*qfn2(fn))(fn, v_24298, v_24297);
    env = stack[-9];
    qvalue(elt(env, 1)) = v_24297; // gg!*
    v_24297 = nil;
    stack[-1] = v_24297;
    goto v_24148;
v_24148:
    goto v_24055;
v_24054:
    v_24297 = qvalue(elt(env, 1)); // gg!*
    ;}  // end of a binding scope
    return onevalue(v_24297);
}



// Code for pa_list2vect

static LispObject CC_pa_list2vect(LispObject env,
                         LispObject v_24032, LispObject v_24033)
{
    env = qenv(env);
    LispObject v_24180, v_24181;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24033,v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24032,v_24033);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_24033;
    stack[0] = v_24032;
// end of prologue
    stack[-4] = nil;
    v_24180 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_24180;
    v_24180 = stack[-5];
    v_24180 = sub1(v_24180);
    env = stack[-7];
    v_24180 = Lmkvect(nil, v_24180);
    env = stack[-7];
    stack[-6] = v_24180;
    v_24180 = stack[0];
    stack[-2] = v_24180;
v_24048:
    v_24180 = stack[-2];
    if (v_24180 == nil) goto v_24052;
    else goto v_24053;
v_24052:
    goto v_24047;
v_24053:
    v_24180 = stack[-2];
    v_24180 = qcar(v_24180);
    stack[0] = v_24180;
    goto v_24064;
v_24060:
    goto v_24071;
v_24067:
    v_24181 = elt(env, 2); // min
    goto v_24068;
v_24069:
    v_24180 = stack[0];
    goto v_24070;
v_24071:
    goto v_24067;
v_24068:
    goto v_24069;
v_24070:
    v_24180 = cons(v_24181, v_24180);
    env = stack[-7];
    fn = elt(env, 3); // eval
    v_24181 = (*qfn1(fn))(fn, v_24180);
    env = stack[-7];
    goto v_24061;
v_24062:
    v_24180 = stack[-4];
    goto v_24063;
v_24064:
    goto v_24060;
v_24061:
    goto v_24062;
v_24063:
    v_24180 = cons(v_24181, v_24180);
    env = stack[-7];
    stack[-4] = v_24180;
    v_24180 = stack[0];
    stack[-1] = v_24180;
v_24078:
    v_24180 = stack[-1];
    if (v_24180 == nil) goto v_24082;
    else goto v_24083;
v_24082:
    goto v_24077;
v_24083:
    v_24180 = stack[-1];
    v_24180 = qcar(v_24180);
    goto v_24095;
v_24089:
    stack[0] = stack[-6];
    goto v_24090;
v_24091:
    v_24181 = sub1(v_24180);
    env = stack[-7];
    goto v_24092;
v_24093:
    v_24180 = stack[-4];
    v_24180 = qcar(v_24180);
    goto v_24094;
v_24095:
    goto v_24089;
v_24090:
    goto v_24091;
v_24092:
    goto v_24093;
v_24094:
    *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_24181-TAG_FIXNUM)/(16/CELL))) = v_24180;
    v_24180 = stack[-1];
    v_24180 = qcdr(v_24180);
    stack[-1] = v_24180;
    goto v_24078;
v_24077:
    v_24180 = stack[-2];
    v_24180 = qcdr(v_24180);
    stack[-2] = v_24180;
    goto v_24048;
v_24047:
    v_24180 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_24180;
v_24109:
    goto v_24121;
v_24117:
    v_24181 = stack[-5];
    goto v_24118;
v_24119:
    v_24180 = stack[-1];
    goto v_24120;
v_24121:
    goto v_24117;
v_24118:
    goto v_24119;
v_24120:
    v_24180 = difference2(v_24181, v_24180);
    env = stack[-7];
    v_24180 = Lminusp(nil, v_24180);
    env = stack[-7];
    if (v_24180 == nil) goto v_24114;
    goto v_24108;
v_24114:
    goto v_24133;
v_24129:
    stack[0] = stack[-6];
    goto v_24130;
v_24131:
    v_24180 = stack[-1];
    v_24180 = sub1(v_24180);
    env = stack[-7];
    goto v_24132;
v_24133:
    goto v_24129;
v_24130:
    goto v_24131;
v_24132:
    v_24180 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_24180-TAG_FIXNUM)/(16/CELL)));
    if (v_24180 == nil) goto v_24127;
    else goto v_24128;
v_24127:
    goto v_24146;
v_24142:
    v_24181 = stack[-3];
    goto v_24143;
v_24144:
    v_24180 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24145;
v_24146:
    goto v_24142;
v_24143:
    goto v_24144;
v_24145:
    if (v_24181 == v_24180) goto v_24140;
    else goto v_24141;
v_24140:
    v_24180 = stack[-1];
    stack[-3] = v_24180;
    goto v_24155;
v_24151:
    v_24181 = stack[-3];
    goto v_24152;
v_24153:
    v_24180 = stack[-4];
    goto v_24154;
v_24155:
    goto v_24151;
v_24152:
    goto v_24153;
v_24154:
    v_24180 = cons(v_24181, v_24180);
    env = stack[-7];
    stack[-4] = v_24180;
    goto v_24139;
v_24141:
v_24139:
    goto v_24164;
v_24158:
    stack[0] = stack[-6];
    goto v_24159;
v_24160:
    v_24180 = stack[-1];
    v_24181 = sub1(v_24180);
    env = stack[-7];
    goto v_24161;
v_24162:
    v_24180 = stack[-3];
    goto v_24163;
v_24164:
    goto v_24158;
v_24159:
    goto v_24160;
v_24161:
    goto v_24162;
v_24163:
    *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_24181-TAG_FIXNUM)/(16/CELL))) = v_24180;
    goto v_24126;
v_24128:
v_24126:
    v_24180 = stack[-1];
    v_24180 = add1(v_24180);
    env = stack[-7];
    stack[-1] = v_24180;
    goto v_24109;
v_24108:
    goto v_24176;
v_24172:
    v_24180 = stack[-4];
    v_24181 = Lreverse(nil, v_24180);
    goto v_24173;
v_24174:
    v_24180 = stack[-6];
    goto v_24175;
v_24176:
    goto v_24172;
v_24173:
    goto v_24174;
v_24175:
    return cons(v_24181, v_24180);
    return onevalue(v_24180);
}



// Code for get!-current!-representation

static LispObject CC_getKcurrentKrepresentation(LispObject env,
                         LispObject v_24032)
{
    env = qenv(env);
    LispObject v_24042, v_24043;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24042 = v_24032;
// end of prologue
    goto v_24039;
v_24035:
    goto v_24036;
v_24037:
    v_24043 = elt(env, 1); // currep
    goto v_24038;
v_24039:
    goto v_24035;
v_24036:
    goto v_24037;
v_24038:
    return get(v_24042, v_24043);
}



// Code for simpquot

static LispObject CC_simpquot(LispObject env,
                         LispObject v_24032)
{
    env = qenv(env);
    LispObject v_24222, v_24223, v_24224;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24032);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_24032;
// end of prologue
    v_24222 = stack[-1];
    fn = elt(env, 7); // simpcar
    stack[0] = (*qfn1(fn))(fn, v_24222);
    env = stack[-3];
    v_24222 = stack[-1];
    v_24222 = qcdr(v_24222);
    v_24222 = qcar(v_24222);
    fn = elt(env, 8); // simp
    v_24222 = (*qfn1(fn))(fn, v_24222);
    env = stack[-3];
    stack[-2] = stack[0];
    stack[0] = v_24222;
    v_24222 = stack[0];
    v_24222 = qcar(v_24222);
    if (v_24222 == nil) goto v_24044;
    else goto v_24045;
v_24044:
    v_24222 = stack[-2];
    v_24222 = qcar(v_24222);
    if (v_24222 == nil) goto v_24050;
    else goto v_24051;
v_24050:
    goto v_24061;
v_24055:
    v_24224 = elt(env, 1); // alg
    goto v_24056;
v_24057:
    v_24223 = (LispObject)304+TAG_FIXNUM; // 19
    goto v_24058;
v_24059:
    v_24222 = elt(env, 2); // "0/0 formed"
    goto v_24060;
v_24061:
    goto v_24055;
v_24056:
    goto v_24057;
v_24058:
    goto v_24059;
v_24060:
    {
        fn = elt(env, 9); // rerror
        return (*qfnn(fn))(fn, 3, v_24224, v_24223, v_24222);
    }
v_24051:
    goto v_24074;
v_24068:
    v_24224 = elt(env, 1); // alg
    goto v_24069;
v_24070:
    v_24223 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_24071;
v_24072:
    v_24222 = elt(env, 3); // "Zero divisor"
    goto v_24073;
v_24074:
    goto v_24068;
v_24069:
    goto v_24070;
v_24071:
    goto v_24072;
v_24073:
    {
        fn = elt(env, 9); // rerror
        return (*qfnn(fn))(fn, 3, v_24224, v_24223, v_24222);
    }
    v_24222 = nil;
    goto v_24043;
v_24045:
    goto v_24085;
v_24081:
    v_24223 = qvalue(elt(env, 4)); // dmode!*
    goto v_24082;
v_24083:
    v_24222 = elt(env, 5); // (!:rd!: !:cr!:)
    goto v_24084;
v_24085:
    goto v_24081;
v_24082:
    goto v_24083;
v_24084:
    v_24222 = Lmemq(nil, v_24223, v_24222);
    if (v_24222 == nil) goto v_24079;
    v_24222 = stack[0];
    v_24222 = qcar(v_24222);
    if (!consp(v_24222)) goto v_24096;
    else goto v_24097;
v_24096:
    v_24222 = lisp_true;
    goto v_24095;
v_24097:
    v_24222 = stack[0];
    v_24222 = qcar(v_24222);
    v_24222 = qcar(v_24222);
    v_24222 = (consp(v_24222) ? nil : lisp_true);
    goto v_24095;
    v_24222 = nil;
v_24095:
    if (v_24222 == nil) goto v_24093;
    v_24222 = stack[0];
    v_24222 = qcdr(v_24222);
    if (!consp(v_24222)) goto v_24113;
    else goto v_24114;
v_24113:
    v_24222 = lisp_true;
    goto v_24112;
v_24114:
    v_24222 = stack[0];
    v_24222 = qcdr(v_24222);
    v_24222 = qcar(v_24222);
    v_24222 = (consp(v_24222) ? nil : lisp_true);
    goto v_24112;
    v_24222 = nil;
v_24112:
    if (v_24222 == nil) goto v_24110;
    v_24222 = stack[-2];
    v_24222 = qcdr(v_24222);
    if (!consp(v_24222)) goto v_24130;
    else goto v_24131;
v_24130:
    v_24222 = lisp_true;
    goto v_24129;
v_24131:
    v_24222 = stack[-2];
    v_24222 = qcdr(v_24222);
    v_24222 = qcar(v_24222);
    v_24222 = (consp(v_24222) ? nil : lisp_true);
    goto v_24129;
    v_24222 = nil;
v_24129:
    if (v_24222 == nil) goto v_24127;
    v_24222 = stack[0];
    v_24222 = qcdr(v_24222);
    fn = elt(env, 10); // !:onep
    v_24222 = (*qfn1(fn))(fn, v_24222);
    env = stack[-3];
    if (v_24222 == nil) goto v_24143;
    else goto v_24144;
v_24143:
    v_24222 = nil;
    goto v_24142;
v_24144:
    v_24222 = stack[-2];
    v_24222 = qcdr(v_24222);
    fn = elt(env, 10); // !:onep
    v_24222 = (*qfn1(fn))(fn, v_24222);
    env = stack[-3];
    goto v_24142;
    v_24222 = nil;
v_24142:
    goto v_24125;
v_24127:
    v_24222 = nil;
    goto v_24125;
    v_24222 = nil;
v_24125:
    goto v_24108;
v_24110:
    v_24222 = nil;
    goto v_24108;
    v_24222 = nil;
v_24108:
    goto v_24091;
v_24093:
    v_24222 = nil;
    goto v_24091;
    v_24222 = nil;
v_24091:
    if (v_24222 == nil) goto v_24079;
    goto v_24168;
v_24164:
    v_24222 = stack[-2];
    v_24222 = qcar(v_24222);
    if (v_24222 == nil) goto v_24171;
    else goto v_24172;
v_24171:
    v_24222 = nil;
    v_24223 = v_24222;
    goto v_24170;
v_24172:
    goto v_24183;
v_24179:
    v_24222 = stack[-2];
    v_24223 = qcar(v_24222);
    goto v_24180;
v_24181:
    v_24222 = stack[0];
    v_24222 = qcar(v_24222);
    goto v_24182;
v_24183:
    goto v_24179;
v_24180:
    goto v_24181;
v_24182:
    fn = elt(env, 11); // divd
    v_24222 = (*qfn2(fn))(fn, v_24223, v_24222);
    v_24223 = v_24222;
    goto v_24170;
    v_24223 = nil;
v_24170:
    goto v_24165;
v_24166:
    v_24222 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24167;
v_24168:
    goto v_24164;
v_24165:
    goto v_24166;
v_24167:
    return cons(v_24223, v_24222);
v_24079:
    goto v_24196;
v_24192:
    stack[0] = stack[-2];
    goto v_24193;
v_24194:
    v_24222 = stack[-1];
    v_24222 = qcdr(v_24222);
    fn = elt(env, 12); // simprecip
    v_24222 = (*qfn1(fn))(fn, v_24222);
    env = stack[-3];
    goto v_24195;
v_24196:
    goto v_24192;
v_24193:
    goto v_24194;
v_24195:
    fn = elt(env, 13); // multsq
    v_24222 = (*qfn2(fn))(fn, stack[0], v_24222);
    env = stack[-3];
    stack[-1] = v_24222;
    v_24222 = qvalue(elt(env, 6)); // !*modular
    if (v_24222 == nil) goto v_24204;
    v_24222 = stack[-1];
    v_24222 = qcdr(v_24222);
    if (v_24222 == nil) goto v_24207;
    else goto v_24204;
v_24207:
    goto v_24217;
v_24211:
    v_24224 = elt(env, 1); // alg
    goto v_24212;
v_24213:
    v_24223 = (LispObject)3216+TAG_FIXNUM; // 201
    goto v_24214;
v_24215:
    v_24222 = elt(env, 3); // "Zero divisor"
    goto v_24216;
v_24217:
    goto v_24211;
v_24212:
    goto v_24213;
v_24214:
    goto v_24215;
v_24216:
    fn = elt(env, 9); // rerror
    v_24222 = (*qfnn(fn))(fn, 3, v_24224, v_24223, v_24222);
    goto v_24202;
v_24204:
v_24202:
    v_24222 = stack[-1];
    goto v_24043;
    v_24222 = nil;
v_24043:
    return onevalue(v_24222);
}



// Code for dnform

static LispObject CC_dnform(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24050, v_24051, v_24052, v_24053;
    LispObject fn;
    LispObject v_24034, v_24033, v_24032;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dnform");
    va_start(aa, nargs);
    v_24032 = va_arg(aa, LispObject);
    v_24033 = va_arg(aa, LispObject);
    v_24034 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24050 = v_24034;
    v_24051 = v_24033;
    v_24052 = v_24032;
// end of prologue
    goto v_24045;
v_24037:
    v_24053 = v_24052;
    goto v_24038;
v_24039:
    v_24052 = v_24051;
    goto v_24040;
v_24041:
    v_24051 = v_24050;
    goto v_24042;
v_24043:
    v_24050 = elt(env, 1); // e
    goto v_24044;
v_24045:
    goto v_24037;
v_24038:
    goto v_24039;
v_24040:
    goto v_24041;
v_24042:
    goto v_24043;
v_24044:
    {
        fn = elt(env, 2); // dnform1
        return (*qfnn(fn))(fn, 4, v_24053, v_24052, v_24051, v_24050);
    }
}



// Code for mk!+mat!+plus!+mat

static LispObject CC_mkLmatLplusLmat(LispObject env,
                         LispObject v_24032, LispObject v_24033)
{
    env = qenv(env);
    LispObject v_24369, v_24370, v_24371;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24033,v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24032,v_24033);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(14);
// copy arguments values to proper place
    stack[-10] = v_24033;
    stack[-11] = v_24032;
// end of prologue
    v_24369 = stack[-11];
    fn = elt(env, 5); // matrix!+p
    v_24369 = (*qfn1(fn))(fn, v_24369);
    env = stack[-13];
    if (v_24369 == nil) goto v_24046;
    else goto v_24047;
v_24046:
    v_24369 = elt(env, 2); // "no matrix in add"
    fn = elt(env, 6); // rederr
    v_24369 = (*qfn1(fn))(fn, v_24369);
    env = stack[-13];
    goto v_24045;
v_24047:
v_24045:
    v_24369 = stack[-10];
    fn = elt(env, 5); // matrix!+p
    v_24369 = (*qfn1(fn))(fn, v_24369);
    env = stack[-13];
    if (v_24369 == nil) goto v_24054;
    else goto v_24055;
v_24054:
    v_24369 = elt(env, 2); // "no matrix in add"
    fn = elt(env, 6); // rederr
    v_24369 = (*qfn1(fn))(fn, v_24369);
    env = stack[-13];
    goto v_24053;
v_24055:
v_24053:
    v_24369 = stack[-11];
    fn = elt(env, 7); // get!+col!+nr
    v_24369 = (*qfn1(fn))(fn, v_24369);
    env = stack[-13];
    stack[-12] = v_24369;
    v_24369 = stack[-11];
    fn = elt(env, 8); // get!+row!+nr
    v_24369 = (*qfn1(fn))(fn, v_24369);
    env = stack[-13];
    stack[-9] = v_24369;
    goto v_24072;
v_24068:
    stack[0] = stack[-12];
    goto v_24069;
v_24070:
    v_24369 = stack[-10];
    fn = elt(env, 7); // get!+col!+nr
    v_24369 = (*qfn1(fn))(fn, v_24369);
    env = stack[-13];
    goto v_24071;
v_24072:
    goto v_24068;
v_24069:
    goto v_24070;
v_24071:
    if (equal(stack[0], v_24369)) goto v_24067;
    v_24369 = elt(env, 3); // "wrong dimensions in add"
    fn = elt(env, 6); // rederr
    v_24369 = (*qfn1(fn))(fn, v_24369);
    env = stack[-13];
    goto v_24065;
v_24067:
v_24065:
    goto v_24086;
v_24082:
    stack[0] = stack[-9];
    goto v_24083;
v_24084:
    v_24369 = stack[-10];
    fn = elt(env, 8); // get!+row!+nr
    v_24369 = (*qfn1(fn))(fn, v_24369);
    env = stack[-13];
    goto v_24085;
v_24086:
    goto v_24082;
v_24083:
    goto v_24084;
v_24085:
    if (equal(stack[0], v_24369)) goto v_24081;
    v_24369 = elt(env, 3); // "wrong dimensions in add"
    fn = elt(env, 6); // rederr
    v_24369 = (*qfn1(fn))(fn, v_24369);
    env = stack[-13];
    goto v_24079;
v_24081:
v_24079:
    v_24369 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_24369;
    goto v_24109;
v_24105:
    v_24370 = stack[-9];
    goto v_24106;
v_24107:
    v_24369 = stack[-8];
    goto v_24108;
v_24109:
    goto v_24105;
v_24106:
    goto v_24107;
v_24108:
    v_24369 = difference2(v_24370, v_24369);
    env = stack[-13];
    v_24369 = Lminusp(nil, v_24369);
    env = stack[-13];
    if (v_24369 == nil) goto v_24102;
    v_24369 = nil;
    goto v_24096;
v_24102:
    v_24369 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_24369;
    goto v_24131;
v_24127:
    v_24370 = stack[-12];
    goto v_24128;
v_24129:
    v_24369 = stack[-4];
    goto v_24130;
v_24131:
    goto v_24127;
v_24128:
    goto v_24129;
v_24130:
    v_24369 = difference2(v_24370, v_24369);
    env = stack[-13];
    v_24369 = Lminusp(nil, v_24369);
    env = stack[-13];
    if (v_24369 == nil) goto v_24124;
    v_24369 = nil;
    goto v_24118;
v_24124:
    goto v_24141;
v_24137:
    goto v_24149;
v_24143:
    v_24371 = stack[-11];
    goto v_24144;
v_24145:
    v_24370 = stack[-8];
    goto v_24146;
v_24147:
    v_24369 = stack[-4];
    goto v_24148;
v_24149:
    goto v_24143;
v_24144:
    goto v_24145;
v_24146:
    goto v_24147;
v_24148:
    fn = elt(env, 9); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(fn, 3, v_24371, v_24370, v_24369);
    env = stack[-13];
    goto v_24138;
v_24139:
    goto v_24160;
v_24154:
    v_24371 = stack[-10];
    goto v_24155;
v_24156:
    v_24370 = stack[-8];
    goto v_24157;
v_24158:
    v_24369 = stack[-4];
    goto v_24159;
v_24160:
    goto v_24154;
v_24155:
    goto v_24156;
v_24157:
    goto v_24158;
v_24159:
    fn = elt(env, 9); // get!+mat!+entry
    v_24369 = (*qfnn(fn))(fn, 3, v_24371, v_24370, v_24369);
    env = stack[-13];
    goto v_24140;
v_24141:
    goto v_24137;
v_24138:
    goto v_24139;
v_24140:
    fn = elt(env, 10); // addsq
    v_24369 = (*qfn2(fn))(fn, stack[0], v_24369);
    env = stack[-13];
    v_24370 = v_24369;
    v_24369 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=13 litvec-offset=4 saveloc=0
{   bind_fluid_stack bind_fluid_var(-13, 4, 0);
    qvalue(elt(env, 4)) = v_24369; // !*sub2
    v_24369 = v_24370;
    fn = elt(env, 11); // subs2
    v_24369 = (*qfn1(fn))(fn, v_24369);
    env = stack[-13];
    v_24370 = v_24369;
    ;}  // end of a binding scope
    v_24369 = v_24370;
    v_24369 = ncons(v_24369);
    env = stack[-13];
    stack[-2] = v_24369;
    stack[-3] = v_24369;
v_24119:
    v_24369 = stack[-4];
    v_24369 = add1(v_24369);
    env = stack[-13];
    stack[-4] = v_24369;
    goto v_24181;
v_24177:
    v_24370 = stack[-12];
    goto v_24178;
v_24179:
    v_24369 = stack[-4];
    goto v_24180;
v_24181:
    goto v_24177;
v_24178:
    goto v_24179;
v_24180:
    v_24369 = difference2(v_24370, v_24369);
    env = stack[-13];
    v_24369 = Lminusp(nil, v_24369);
    env = stack[-13];
    if (v_24369 == nil) goto v_24174;
    v_24369 = stack[-3];
    goto v_24118;
v_24174:
    goto v_24190;
v_24186:
    stack[-1] = stack[-2];
    goto v_24187;
v_24188:
    goto v_24198;
v_24194:
    goto v_24206;
v_24200:
    v_24371 = stack[-11];
    goto v_24201;
v_24202:
    v_24370 = stack[-8];
    goto v_24203;
v_24204:
    v_24369 = stack[-4];
    goto v_24205;
v_24206:
    goto v_24200;
v_24201:
    goto v_24202;
v_24203:
    goto v_24204;
v_24205:
    fn = elt(env, 9); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(fn, 3, v_24371, v_24370, v_24369);
    env = stack[-13];
    goto v_24195;
v_24196:
    goto v_24217;
v_24211:
    v_24371 = stack[-10];
    goto v_24212;
v_24213:
    v_24370 = stack[-8];
    goto v_24214;
v_24215:
    v_24369 = stack[-4];
    goto v_24216;
v_24217:
    goto v_24211;
v_24212:
    goto v_24213;
v_24214:
    goto v_24215;
v_24216:
    fn = elt(env, 9); // get!+mat!+entry
    v_24369 = (*qfnn(fn))(fn, 3, v_24371, v_24370, v_24369);
    env = stack[-13];
    goto v_24197;
v_24198:
    goto v_24194;
v_24195:
    goto v_24196;
v_24197:
    fn = elt(env, 10); // addsq
    v_24369 = (*qfn2(fn))(fn, stack[0], v_24369);
    env = stack[-13];
    v_24370 = v_24369;
    v_24369 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=13 litvec-offset=4 saveloc=0
{   bind_fluid_stack bind_fluid_var(-13, 4, 0);
    qvalue(elt(env, 4)) = v_24369; // !*sub2
    v_24369 = v_24370;
    fn = elt(env, 11); // subs2
    v_24369 = (*qfn1(fn))(fn, v_24369);
    env = stack[-13];
    v_24370 = v_24369;
    ;}  // end of a binding scope
    v_24369 = v_24370;
    v_24369 = ncons(v_24369);
    env = stack[-13];
    goto v_24189;
v_24190:
    goto v_24186;
v_24187:
    goto v_24188;
v_24189:
    v_24369 = Lrplacd(nil, stack[-1], v_24369);
    env = stack[-13];
    v_24369 = stack[-2];
    v_24369 = qcdr(v_24369);
    stack[-2] = v_24369;
    goto v_24119;
v_24118:
    v_24369 = ncons(v_24369);
    env = stack[-13];
    stack[-6] = v_24369;
    stack[-7] = v_24369;
v_24097:
    v_24369 = stack[-8];
    v_24369 = add1(v_24369);
    env = stack[-13];
    stack[-8] = v_24369;
    goto v_24240;
v_24236:
    v_24370 = stack[-9];
    goto v_24237;
v_24238:
    v_24369 = stack[-8];
    goto v_24239;
v_24240:
    goto v_24236;
v_24237:
    goto v_24238;
v_24239:
    v_24369 = difference2(v_24370, v_24369);
    env = stack[-13];
    v_24369 = Lminusp(nil, v_24369);
    env = stack[-13];
    if (v_24369 == nil) goto v_24233;
    v_24369 = stack[-7];
    goto v_24096;
v_24233:
    goto v_24249;
v_24245:
    stack[-5] = stack[-6];
    goto v_24246;
v_24247:
    v_24369 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_24369;
    goto v_24269;
v_24265:
    v_24370 = stack[-12];
    goto v_24266;
v_24267:
    v_24369 = stack[-4];
    goto v_24268;
v_24269:
    goto v_24265;
v_24266:
    goto v_24267;
v_24268:
    v_24369 = difference2(v_24370, v_24369);
    env = stack[-13];
    v_24369 = Lminusp(nil, v_24369);
    env = stack[-13];
    if (v_24369 == nil) goto v_24262;
    v_24369 = nil;
    goto v_24256;
v_24262:
    goto v_24279;
v_24275:
    goto v_24287;
v_24281:
    v_24371 = stack[-11];
    goto v_24282;
v_24283:
    v_24370 = stack[-8];
    goto v_24284;
v_24285:
    v_24369 = stack[-4];
    goto v_24286;
v_24287:
    goto v_24281;
v_24282:
    goto v_24283;
v_24284:
    goto v_24285;
v_24286:
    fn = elt(env, 9); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(fn, 3, v_24371, v_24370, v_24369);
    env = stack[-13];
    goto v_24276;
v_24277:
    goto v_24298;
v_24292:
    v_24371 = stack[-10];
    goto v_24293;
v_24294:
    v_24370 = stack[-8];
    goto v_24295;
v_24296:
    v_24369 = stack[-4];
    goto v_24297;
v_24298:
    goto v_24292;
v_24293:
    goto v_24294;
v_24295:
    goto v_24296;
v_24297:
    fn = elt(env, 9); // get!+mat!+entry
    v_24369 = (*qfnn(fn))(fn, 3, v_24371, v_24370, v_24369);
    env = stack[-13];
    goto v_24278;
v_24279:
    goto v_24275;
v_24276:
    goto v_24277;
v_24278:
    fn = elt(env, 10); // addsq
    v_24369 = (*qfn2(fn))(fn, stack[0], v_24369);
    env = stack[-13];
    v_24370 = v_24369;
    v_24369 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=13 litvec-offset=4 saveloc=0
{   bind_fluid_stack bind_fluid_var(-13, 4, 0);
    qvalue(elt(env, 4)) = v_24369; // !*sub2
    v_24369 = v_24370;
    fn = elt(env, 11); // subs2
    v_24369 = (*qfn1(fn))(fn, v_24369);
    env = stack[-13];
    v_24370 = v_24369;
    ;}  // end of a binding scope
    v_24369 = v_24370;
    v_24369 = ncons(v_24369);
    env = stack[-13];
    stack[-2] = v_24369;
    stack[-3] = v_24369;
v_24257:
    v_24369 = stack[-4];
    v_24369 = add1(v_24369);
    env = stack[-13];
    stack[-4] = v_24369;
    goto v_24319;
v_24315:
    v_24370 = stack[-12];
    goto v_24316;
v_24317:
    v_24369 = stack[-4];
    goto v_24318;
v_24319:
    goto v_24315;
v_24316:
    goto v_24317;
v_24318:
    v_24369 = difference2(v_24370, v_24369);
    env = stack[-13];
    v_24369 = Lminusp(nil, v_24369);
    env = stack[-13];
    if (v_24369 == nil) goto v_24312;
    v_24369 = stack[-3];
    goto v_24256;
v_24312:
    goto v_24328;
v_24324:
    stack[-1] = stack[-2];
    goto v_24325;
v_24326:
    goto v_24336;
v_24332:
    goto v_24344;
v_24338:
    v_24371 = stack[-11];
    goto v_24339;
v_24340:
    v_24370 = stack[-8];
    goto v_24341;
v_24342:
    v_24369 = stack[-4];
    goto v_24343;
v_24344:
    goto v_24338;
v_24339:
    goto v_24340;
v_24341:
    goto v_24342;
v_24343:
    fn = elt(env, 9); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(fn, 3, v_24371, v_24370, v_24369);
    env = stack[-13];
    goto v_24333;
v_24334:
    goto v_24355;
v_24349:
    v_24371 = stack[-10];
    goto v_24350;
v_24351:
    v_24370 = stack[-8];
    goto v_24352;
v_24353:
    v_24369 = stack[-4];
    goto v_24354;
v_24355:
    goto v_24349;
v_24350:
    goto v_24351;
v_24352:
    goto v_24353;
v_24354:
    fn = elt(env, 9); // get!+mat!+entry
    v_24369 = (*qfnn(fn))(fn, 3, v_24371, v_24370, v_24369);
    env = stack[-13];
    goto v_24335;
v_24336:
    goto v_24332;
v_24333:
    goto v_24334;
v_24335:
    fn = elt(env, 10); // addsq
    v_24369 = (*qfn2(fn))(fn, stack[0], v_24369);
    env = stack[-13];
    v_24370 = v_24369;
    v_24369 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=13 litvec-offset=4 saveloc=0
{   bind_fluid_stack bind_fluid_var(-13, 4, 0);
    qvalue(elt(env, 4)) = v_24369; // !*sub2
    v_24369 = v_24370;
    fn = elt(env, 11); // subs2
    v_24369 = (*qfn1(fn))(fn, v_24369);
    env = stack[-13];
    v_24370 = v_24369;
    ;}  // end of a binding scope
    v_24369 = v_24370;
    v_24369 = ncons(v_24369);
    env = stack[-13];
    goto v_24327;
v_24328:
    goto v_24324;
v_24325:
    goto v_24326;
v_24327:
    v_24369 = Lrplacd(nil, stack[-1], v_24369);
    env = stack[-13];
    v_24369 = stack[-2];
    v_24369 = qcdr(v_24369);
    stack[-2] = v_24369;
    goto v_24257;
v_24256:
    v_24369 = ncons(v_24369);
    env = stack[-13];
    goto v_24248;
v_24249:
    goto v_24245;
v_24246:
    goto v_24247;
v_24248:
    v_24369 = Lrplacd(nil, stack[-5], v_24369);
    env = stack[-13];
    v_24369 = stack[-6];
    v_24369 = qcdr(v_24369);
    stack[-6] = v_24369;
    goto v_24097;
v_24096:
    return onevalue(v_24369);
}



// Code for cl_sacatlp

static LispObject CC_cl_sacatlp(LispObject env,
                         LispObject v_24032, LispObject v_24033)
{
    env = qenv(env);
    LispObject v_24036, v_24037;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24036 = v_24033;
    v_24037 = v_24032;
// end of prologue
    v_24036 = lisp_true;
    return onevalue(v_24036);
}



// Code for make!-modular!-symmetric

static LispObject CC_makeKmodularKsymmetric(LispObject env,
                         LispObject v_24032)
{
    env = qenv(env);
    LispObject v_24109, v_24110, v_24111;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24032);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24032;
// end of prologue
    v_24109 = stack[0];
    if (v_24109 == nil) goto v_24036;
    else goto v_24037;
v_24036:
    v_24109 = nil;
    goto v_24035;
v_24037:
    v_24109 = stack[0];
    if (!consp(v_24109)) goto v_24044;
    else goto v_24045;
v_24044:
    v_24109 = lisp_true;
    goto v_24043;
v_24045:
    v_24109 = stack[0];
    v_24109 = qcar(v_24109);
    v_24109 = (consp(v_24109) ? nil : lisp_true);
    goto v_24043;
    v_24109 = nil;
v_24043:
    if (v_24109 == nil) goto v_24041;
    goto v_24062;
v_24058:
    v_24110 = stack[0];
    goto v_24059;
v_24060:
    v_24109 = qvalue(elt(env, 1)); // modulus!/2
    goto v_24061;
v_24062:
    goto v_24058;
v_24059:
    goto v_24060;
v_24061:
    v_24109 = (LispObject)greaterp2(v_24110, v_24109);
    v_24109 = v_24109 ? lisp_true : nil;
    env = stack[-2];
    if (v_24109 == nil) goto v_24056;
    goto v_24071;
v_24067:
    v_24110 = stack[0];
    goto v_24068;
v_24069:
    v_24109 = qvalue(elt(env, 2)); // current!-modulus
    goto v_24070;
v_24071:
    goto v_24067;
v_24068:
    goto v_24069;
v_24070:
    v_24109 = difference2(v_24110, v_24109);
    env = stack[-2];
    {
        fn = elt(env, 3); // !*n2f
        return (*qfn1(fn))(fn, v_24109);
    }
v_24056:
    v_24109 = stack[0];
    goto v_24054;
    v_24109 = nil;
v_24054:
    goto v_24035;
v_24041:
    v_24109 = stack[0];
    v_24109 = qcar(v_24109);
    v_24109 = qcdr(v_24109);
    stack[-1] = CC_makeKmodularKsymmetric(elt(env, 0), v_24109);
    env = stack[-2];
    v_24109 = stack[0];
    v_24109 = qcdr(v_24109);
    v_24109 = CC_makeKmodularKsymmetric(elt(env, 0), v_24109);
    v_24110 = stack[-1];
    v_24111 = v_24110;
    if (v_24111 == nil) goto v_24090;
    else goto v_24091;
v_24090:
    goto v_24089;
v_24091:
    goto v_24103;
v_24097:
    v_24111 = stack[0];
    v_24111 = qcar(v_24111);
    v_24111 = qcar(v_24111);
    goto v_24098;
v_24099:
    goto v_24100;
v_24101:
    goto v_24102;
v_24103:
    goto v_24097;
v_24098:
    goto v_24099;
v_24100:
    goto v_24101;
v_24102:
    return acons(v_24111, v_24110, v_24109);
    v_24109 = nil;
v_24089:
    goto v_24035;
    v_24109 = nil;
v_24035:
    return onevalue(v_24109);
}



// Code for upperlimitrd

static LispObject CC_upperlimitrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24081, v_24082;
    LispObject fn;
    argcheck(nargs, 0, "upperlimitrd");
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
    fn = elt(env, 7); // lex
    v_24081 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_24046;
v_24042:
    v_24082 = qvalue(elt(env, 2)); // char
    goto v_24043;
v_24044:
    v_24081 = elt(env, 3); // (u p l i m i t)
    goto v_24045;
v_24046:
    goto v_24042;
v_24043:
    goto v_24044;
v_24045:
    if (equal(v_24082, v_24081)) goto v_24041;
    goto v_24054;
v_24050:
    v_24082 = elt(env, 4); // "<uplimit>"
    goto v_24051;
v_24052:
    v_24081 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_24053;
v_24054:
    goto v_24050;
v_24051:
    goto v_24052;
v_24053:
    fn = elt(env, 8); // errorml
    v_24081 = (*qfn2(fn))(fn, v_24082, v_24081);
    env = stack[-1];
    goto v_24039;
v_24041:
v_24039:
    fn = elt(env, 9); // mathml
    v_24081 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_24081;
    fn = elt(env, 7); // lex
    v_24081 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_24067;
v_24063:
    v_24082 = qvalue(elt(env, 2)); // char
    goto v_24064;
v_24065:
    v_24081 = elt(env, 5); // (!/ u p l i m i t)
    goto v_24066;
v_24067:
    goto v_24063;
v_24064:
    goto v_24065;
v_24066:
    if (equal(v_24082, v_24081)) goto v_24061;
    else goto v_24062;
v_24061:
    v_24081 = stack[0];
    goto v_24035;
v_24062:
    goto v_24078;
v_24074:
    v_24082 = elt(env, 6); // "</uplimit>"
    goto v_24075;
v_24076:
    v_24081 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_24077;
v_24078:
    goto v_24074;
v_24075:
    goto v_24076;
v_24077:
    fn = elt(env, 8); // errorml
    v_24081 = (*qfn2(fn))(fn, v_24082, v_24081);
    goto v_24060;
v_24060:
    v_24081 = nil;
v_24035:
    return onevalue(v_24081);
}



// Code for init

static LispObject CC_init(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24118;
    LispObject fn;
    argcheck(nargs, 0, "init");
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
    v_24118 = qvalue(elt(env, 2)); // fluidbibasisvariables
    v_24118 = Lreverse(nil, v_24118);
    env = stack[-7];
    qvalue(elt(env, 3)) = v_24118; // fluidbibasisreversedvariables
    fn = elt(env, 10); // initmonomials
    v_24118 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    v_24118 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_24118;
    v_24118 = qvalue(elt(env, 2)); // fluidbibasisvariables
    stack[-5] = v_24118;
    v_24118 = stack[-5];
    if (v_24118 == nil) goto v_24051;
    else goto v_24052;
v_24051:
    v_24118 = nil;
    goto v_24046;
v_24052:
    v_24118 = stack[-5];
    v_24118 = qcar(v_24118);
    goto v_24064;
v_24060:
    stack[-1] = v_24118;
    goto v_24061;
v_24062:
    goto v_24070;
v_24066:
    stack[0] = qvalue(elt(env, 4)); // fluidbibasissinglevariablemonomialss
    goto v_24067;
v_24068:
    v_24118 = stack[-6];
    v_24118 = add1(v_24118);
    env = stack[-7];
    stack[-6] = v_24118;
    goto v_24069;
v_24070:
    goto v_24066;
v_24067:
    goto v_24068;
v_24069:
    v_24118 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_24118-TAG_FIXNUM)/(16/CELL)));
    goto v_24063;
v_24064:
    goto v_24060;
v_24061:
    goto v_24062;
v_24063:
    v_24118 = cons(stack[-1], v_24118);
    env = stack[-7];
    v_24118 = ncons(v_24118);
    env = stack[-7];
    stack[-3] = v_24118;
    stack[-4] = v_24118;
v_24047:
    v_24118 = stack[-5];
    v_24118 = qcdr(v_24118);
    stack[-5] = v_24118;
    v_24118 = stack[-5];
    if (v_24118 == nil) goto v_24079;
    else goto v_24080;
v_24079:
    v_24118 = stack[-4];
    goto v_24046;
v_24080:
    goto v_24088;
v_24084:
    stack[-2] = stack[-3];
    goto v_24085;
v_24086:
    v_24118 = stack[-5];
    v_24118 = qcar(v_24118);
    goto v_24099;
v_24095:
    stack[-1] = v_24118;
    goto v_24096;
v_24097:
    goto v_24105;
v_24101:
    stack[0] = qvalue(elt(env, 4)); // fluidbibasissinglevariablemonomialss
    goto v_24102;
v_24103:
    v_24118 = stack[-6];
    v_24118 = add1(v_24118);
    env = stack[-7];
    stack[-6] = v_24118;
    goto v_24104;
v_24105:
    goto v_24101;
v_24102:
    goto v_24103;
v_24104:
    v_24118 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_24118-TAG_FIXNUM)/(16/CELL)));
    goto v_24098;
v_24099:
    goto v_24095;
v_24096:
    goto v_24097;
v_24098:
    v_24118 = cons(stack[-1], v_24118);
    env = stack[-7];
    v_24118 = ncons(v_24118);
    env = stack[-7];
    goto v_24087;
v_24088:
    goto v_24084;
v_24085:
    goto v_24086;
v_24087:
    v_24118 = Lrplacd(nil, stack[-2], v_24118);
    env = stack[-7];
    v_24118 = stack[-3];
    v_24118 = qcdr(v_24118);
    stack[-3] = v_24118;
    goto v_24047;
v_24046:
    qvalue(elt(env, 5)) = v_24118; // fluidbibasissinglevariablemonomialsa
    fn = elt(env, 11); // settreset
    v_24118 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    v_24118 = nil;
    v_24118 = ncons(v_24118);
    env = stack[-7];
    qvalue(elt(env, 6)) = v_24118; // fluidbibasissetq
    v_24118 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 7)) = v_24118; // fluidbibasisreductionsmade
    v_24118 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 8)) = v_24118; // fluidbibasisnormalforms
    v_24118 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 9)) = v_24118; // fluidbibasisnonzeronormalforms
    v_24118 = nil;
    return onevalue(v_24118);
}



// Code for fnreval

static LispObject CC_fnreval(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24160, v_24161;
    LispObject fn;
    LispObject v_24034, v_24033, v_24032;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "fnreval");
    va_start(aa, nargs);
    v_24032 = va_arg(aa, LispObject);
    v_24033 = va_arg(aa, LispObject);
    v_24034 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24034,v_24033,v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24032,v_24033,v_24034);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_24034;
    stack[-1] = v_24033;
    stack[0] = v_24032;
// end of prologue
    stack[-2] = nil;
v_24039:
    v_24160 = stack[0];
    if (v_24160 == nil) goto v_24042;
    else goto v_24043;
v_24042:
    v_24160 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_24160);
    }
v_24043:
    goto v_24053;
v_24049:
    v_24161 = stack[-1];
    goto v_24050;
v_24051:
    v_24160 = lisp_true;
    goto v_24052;
v_24053:
    goto v_24049;
v_24050:
    goto v_24051;
v_24052:
    if (v_24161 == v_24160) goto v_24047;
    else goto v_24048;
v_24047:
    goto v_24061;
v_24057:
    v_24161 = stack[-2];
    goto v_24058;
v_24059:
    v_24160 = stack[0];
    goto v_24060;
v_24061:
    goto v_24057;
v_24058:
    goto v_24059;
v_24060:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_24161, v_24160);
    }
v_24048:
    v_24160 = stack[-1];
    if (v_24160 == nil) goto v_24064;
    else goto v_24065;
v_24064:
    goto v_24072;
v_24068:
    stack[-5] = stack[-2];
    goto v_24069;
v_24070:
    v_24160 = stack[0];
    stack[-3] = v_24160;
    v_24160 = stack[-3];
    if (v_24160 == nil) goto v_24083;
    else goto v_24084;
v_24083:
    v_24160 = nil;
    goto v_24078;
v_24084:
    v_24160 = stack[-3];
    v_24160 = qcar(v_24160);
    goto v_24096;
v_24092:
    v_24161 = v_24160;
    goto v_24093;
v_24094:
    v_24160 = stack[-4];
    goto v_24095;
v_24096:
    goto v_24092;
v_24093:
    goto v_24094;
v_24095:
    fn = elt(env, 2); // reval1
    v_24160 = (*qfn2(fn))(fn, v_24161, v_24160);
    env = stack[-6];
    v_24160 = ncons(v_24160);
    env = stack[-6];
    stack[-1] = v_24160;
    stack[-2] = v_24160;
v_24079:
    v_24160 = stack[-3];
    v_24160 = qcdr(v_24160);
    stack[-3] = v_24160;
    v_24160 = stack[-3];
    if (v_24160 == nil) goto v_24103;
    else goto v_24104;
v_24103:
    v_24160 = stack[-2];
    goto v_24078;
v_24104:
    goto v_24112;
v_24108:
    stack[0] = stack[-1];
    goto v_24109;
v_24110:
    v_24160 = stack[-3];
    v_24160 = qcar(v_24160);
    goto v_24123;
v_24119:
    v_24161 = v_24160;
    goto v_24120;
v_24121:
    v_24160 = stack[-4];
    goto v_24122;
v_24123:
    goto v_24119;
v_24120:
    goto v_24121;
v_24122:
    fn = elt(env, 2); // reval1
    v_24160 = (*qfn2(fn))(fn, v_24161, v_24160);
    env = stack[-6];
    v_24160 = ncons(v_24160);
    env = stack[-6];
    goto v_24111;
v_24112:
    goto v_24108;
v_24109:
    goto v_24110;
v_24111:
    v_24160 = Lrplacd(nil, stack[0], v_24160);
    env = stack[-6];
    v_24160 = stack[-1];
    v_24160 = qcdr(v_24160);
    stack[-1] = v_24160;
    goto v_24079;
v_24078:
    goto v_24071;
v_24072:
    goto v_24068;
v_24069:
    goto v_24070;
v_24071:
    {
        LispObject v_24168 = stack[-5];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_24168, v_24160);
    }
v_24065:
    goto v_24135;
v_24131:
    v_24160 = stack[-1];
    v_24160 = qcar(v_24160);
    if (v_24160 == nil) goto v_24139;
    v_24160 = stack[0];
    v_24160 = qcar(v_24160);
    v_24161 = v_24160;
    goto v_24137;
v_24139:
    goto v_24151;
v_24147:
    v_24160 = stack[0];
    v_24161 = qcar(v_24160);
    goto v_24148;
v_24149:
    v_24160 = stack[-4];
    goto v_24150;
v_24151:
    goto v_24147;
v_24148:
    goto v_24149;
v_24150:
    fn = elt(env, 2); // reval1
    v_24160 = (*qfn2(fn))(fn, v_24161, v_24160);
    env = stack[-6];
    v_24161 = v_24160;
    goto v_24137;
    v_24161 = nil;
v_24137:
    goto v_24132;
v_24133:
    v_24160 = stack[-2];
    goto v_24134;
v_24135:
    goto v_24131;
v_24132:
    goto v_24133;
v_24134:
    v_24160 = cons(v_24161, v_24160);
    env = stack[-6];
    stack[-2] = v_24160;
    v_24160 = stack[0];
    v_24160 = qcdr(v_24160);
    stack[0] = v_24160;
    v_24160 = stack[-1];
    v_24160 = qcdr(v_24160);
    stack[-1] = v_24160;
    goto v_24039;
    v_24160 = nil;
    return onevalue(v_24160);
}



// Code for copy_mat

static LispObject CC_copy_mat(LispObject env,
                         LispObject v_24032)
{
    env = qenv(env);
    LispObject v_24128, v_24129, v_24130;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24032);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_24032;
// end of prologue
    v_24128 = stack[-7];
    fn = elt(env, 2); // matrix_input_test
    v_24128 = (*qfn1(fn))(fn, v_24128);
    env = stack[-9];
    v_24128 = stack[-7];
    fn = elt(env, 3); // size_of_matrix
    v_24128 = (*qfn1(fn))(fn, v_24128);
    env = stack[-9];
    v_24128 = qcar(v_24128);
    stack[-6] = v_24128;
    v_24128 = stack[-7];
    fn = elt(env, 3); // size_of_matrix
    v_24128 = (*qfn1(fn))(fn, v_24128);
    env = stack[-9];
    v_24128 = qcdr(v_24128);
    v_24128 = qcar(v_24128);
    stack[-5] = v_24128;
    goto v_24056;
v_24052:
    v_24129 = stack[-6];
    goto v_24053;
v_24054:
    v_24128 = stack[-5];
    goto v_24055;
v_24056:
    goto v_24052;
v_24053:
    goto v_24054;
v_24055:
    fn = elt(env, 4); // mkmatrix
    v_24128 = (*qfn2(fn))(fn, v_24129, v_24128);
    env = stack[-9];
    stack[-8] = v_24128;
    v_24128 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_24128;
v_24062:
    goto v_24074;
v_24070:
    v_24129 = stack[-6];
    goto v_24071;
v_24072:
    v_24128 = stack[-4];
    goto v_24073;
v_24074:
    goto v_24070;
v_24071:
    goto v_24072;
v_24073:
    v_24128 = difference2(v_24129, v_24128);
    env = stack[-9];
    v_24128 = Lminusp(nil, v_24128);
    env = stack[-9];
    if (v_24128 == nil) goto v_24067;
    goto v_24061;
v_24067:
    v_24128 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_24128;
v_24081:
    goto v_24093;
v_24089:
    v_24129 = stack[-5];
    goto v_24090;
v_24091:
    v_24128 = stack[-3];
    goto v_24092;
v_24093:
    goto v_24089;
v_24090:
    goto v_24091;
v_24092:
    v_24128 = difference2(v_24129, v_24128);
    env = stack[-9];
    v_24128 = Lminusp(nil, v_24128);
    env = stack[-9];
    if (v_24128 == nil) goto v_24086;
    goto v_24080;
v_24086:
    goto v_24106;
v_24098:
    stack[-2] = stack[-8];
    goto v_24099;
v_24100:
    stack[-1] = stack[-4];
    goto v_24101;
v_24102:
    stack[0] = stack[-3];
    goto v_24103;
v_24104:
    goto v_24117;
v_24111:
    v_24130 = stack[-7];
    goto v_24112;
v_24113:
    v_24129 = stack[-4];
    goto v_24114;
v_24115:
    v_24128 = stack[-3];
    goto v_24116;
v_24117:
    goto v_24111;
v_24112:
    goto v_24113;
v_24114:
    goto v_24115;
v_24116:
    fn = elt(env, 5); // getmat
    v_24128 = (*qfnn(fn))(fn, 3, v_24130, v_24129, v_24128);
    env = stack[-9];
    goto v_24105;
v_24106:
    goto v_24098;
v_24099:
    goto v_24100;
v_24101:
    goto v_24102;
v_24103:
    goto v_24104;
v_24105:
    fn = elt(env, 6); // setmat
    v_24128 = (*qfnn(fn))(fn, 4, stack[-2], stack[-1], stack[0], v_24128);
    env = stack[-9];
    v_24128 = stack[-3];
    v_24128 = add1(v_24128);
    env = stack[-9];
    stack[-3] = v_24128;
    goto v_24081;
v_24080:
    v_24128 = stack[-4];
    v_24128 = add1(v_24128);
    env = stack[-9];
    stack[-4] = v_24128;
    goto v_24062;
v_24061:
    v_24128 = stack[-8];
    return onevalue(v_24128);
}



// Code for evzero

static LispObject CC_evzero(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24068, v_24069;
    argcheck(nargs, 0, "evzero");
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
    v_24068 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_24068;
v_24040:
    goto v_24052;
v_24048:
    v_24068 = qvalue(elt(env, 2)); // dipvars!*
    v_24069 = Llength(nil, v_24068);
    env = stack[-2];
    goto v_24049;
v_24050:
    v_24068 = stack[0];
    goto v_24051;
v_24052:
    goto v_24048;
v_24049:
    goto v_24050;
v_24051:
    v_24068 = difference2(v_24069, v_24068);
    env = stack[-2];
    v_24068 = Lminusp(nil, v_24068);
    env = stack[-2];
    if (v_24068 == nil) goto v_24045;
    goto v_24039;
v_24045:
    goto v_24062;
v_24058:
    v_24069 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24059;
v_24060:
    v_24068 = stack[-1];
    goto v_24061;
v_24062:
    goto v_24058;
v_24059:
    goto v_24060;
v_24061:
    v_24068 = cons(v_24069, v_24068);
    env = stack[-2];
    stack[-1] = v_24068;
    v_24068 = stack[0];
    v_24068 = add1(v_24068);
    env = stack[-2];
    stack[0] = v_24068;
    goto v_24040;
v_24039:
    v_24068 = stack[-1];
    return onevalue(v_24068);
}



// Code for exdf0

static LispObject CC_exdf0(LispObject env,
                         LispObject v_24032)
{
    env = qenv(env);
    LispObject v_24069, v_24070;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24032);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24032;
// end of prologue
    goto v_24039;
v_24035:
    goto v_24045;
v_24041:
    v_24069 = stack[0];
    v_24069 = qcar(v_24069);
    fn = elt(env, 1); // exdff0
    stack[-1] = (*qfn1(fn))(fn, v_24069);
    env = stack[-2];
    goto v_24042;
v_24043:
    goto v_24054;
v_24050:
    v_24069 = stack[0];
    v_24069 = qcdr(v_24069);
    fn = elt(env, 2); // negf
    v_24069 = (*qfn1(fn))(fn, v_24069);
    env = stack[-2];
    fn = elt(env, 1); // exdff0
    v_24070 = (*qfn1(fn))(fn, v_24069);
    env = stack[-2];
    goto v_24051;
v_24052:
    v_24069 = stack[0];
    goto v_24053;
v_24054:
    goto v_24050;
v_24051:
    goto v_24052;
v_24053:
    fn = elt(env, 3); // multpfsq
    v_24069 = (*qfn2(fn))(fn, v_24070, v_24069);
    env = stack[-2];
    goto v_24044;
v_24045:
    goto v_24041;
v_24042:
    goto v_24043;
v_24044:
    fn = elt(env, 4); // addpf
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_24069);
    env = stack[-2];
    goto v_24036;
v_24037:
    goto v_24065;
v_24061:
    v_24070 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24062;
v_24063:
    v_24069 = stack[0];
    v_24069 = qcdr(v_24069);
    goto v_24064;
v_24065:
    goto v_24061;
v_24062:
    goto v_24063;
v_24064:
    v_24069 = cons(v_24070, v_24069);
    env = stack[-2];
    goto v_24038;
v_24039:
    goto v_24035;
v_24036:
    goto v_24037;
v_24038:
    {
        LispObject v_24073 = stack[-1];
        fn = elt(env, 3); // multpfsq
        return (*qfn2(fn))(fn, v_24073, v_24069);
    }
}



// Code for gbfdiff

static LispObject CC_gbfdiff(LispObject env,
                         LispObject v_24032, LispObject v_24033)
{
    env = qenv(env);
    LispObject v_24061, v_24062;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24033,v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24032,v_24033);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_24033;
    stack[-1] = v_24032;
// end of prologue
    goto v_24040;
v_24036:
    goto v_24046;
v_24042:
    v_24061 = stack[-1];
    v_24062 = qcar(v_24061);
    goto v_24043;
v_24044:
    v_24061 = stack[0];
    v_24061 = qcar(v_24061);
    goto v_24045;
v_24046:
    goto v_24042;
v_24043:
    goto v_24044;
v_24045:
    fn = elt(env, 1); // difbf
    stack[-2] = (*qfn2(fn))(fn, v_24062, v_24061);
    env = stack[-3];
    goto v_24037;
v_24038:
    goto v_24056;
v_24052:
    v_24061 = stack[-1];
    v_24062 = qcdr(v_24061);
    goto v_24053;
v_24054:
    v_24061 = stack[0];
    v_24061 = qcdr(v_24061);
    goto v_24055;
v_24056:
    goto v_24052;
v_24053:
    goto v_24054;
v_24055:
    fn = elt(env, 1); // difbf
    v_24061 = (*qfn2(fn))(fn, v_24062, v_24061);
    goto v_24039;
v_24040:
    goto v_24036;
v_24037:
    goto v_24038;
v_24039:
    {
        LispObject v_24066 = stack[-2];
        return cons(v_24066, v_24061);
    }
}



// Code for getphystypeexpt

static LispObject CC_getphystypeexpt(LispObject env,
                         LispObject v_24032)
{
    env = qenv(env);
    LispObject v_24061, v_24062;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24032);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24032;
// end of prologue
    v_24061 = stack[0];
    fn = elt(env, 3); // getphystypecar
    v_24061 = (*qfn1(fn))(fn, v_24061);
    env = stack[-1];
    v_24062 = v_24061;
    v_24061 = v_24062;
    if (v_24061 == nil) goto v_24042;
    else goto v_24043;
v_24042:
    v_24061 = nil;
    goto v_24041;
v_24043:
    v_24061 = stack[0];
    v_24061 = qcdr(v_24061);
    v_24061 = qcar(v_24061);
    if (is_number(v_24061)) goto v_24048;
    else goto v_24047;
v_24048:
    v_24061 = stack[0];
    v_24061 = qcdr(v_24061);
    v_24061 = qcar(v_24061);
    v_24061 = Levenp(nil, v_24061);
    env = stack[-1];
    if (v_24061 == nil) goto v_24047;
    v_24061 = elt(env, 2); // scalar
    goto v_24041;
v_24047:
    v_24061 = v_24062;
    goto v_24041;
    v_24061 = nil;
v_24041:
    return onevalue(v_24061);
}



// Code for mk_binding

static LispObject CC_mk_binding(LispObject env,
                         LispObject v_24032, LispObject v_24033)
{
    env = qenv(env);
    LispObject v_24060, v_24061;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24033,v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24032,v_24033);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24033;
    stack[-1] = v_24032;
// end of prologue
    goto v_24044;
v_24040:
    v_24060 = stack[-1];
    v_24061 = qcar(v_24060);
    goto v_24041;
v_24042:
    v_24060 = stack[0];
    goto v_24043;
v_24044:
    goto v_24040;
v_24041:
    goto v_24042;
v_24043:
    fn = elt(env, 1); // can_be_proved
    v_24060 = (*qfn2(fn))(fn, v_24061, v_24060);
    env = stack[-2];
    if (v_24060 == nil) goto v_24037;
    else goto v_24038;
v_24037:
    v_24060 = nil;
    goto v_24036;
v_24038:
    goto v_24056;
v_24052:
    v_24060 = stack[-1];
    v_24061 = qcdr(v_24060);
    goto v_24053;
v_24054:
    v_24060 = stack[0];
    goto v_24055;
v_24056:
    goto v_24052;
v_24053:
    goto v_24054;
v_24055:
    {
        fn = elt(env, 2); // edge_bind
        return (*qfn2(fn))(fn, v_24061, v_24060);
    }
    v_24060 = nil;
v_24036:
    return onevalue(v_24060);
}



// Code for ratnump

static LispObject CC_ratnump(LispObject env,
                         LispObject v_24032)
{
    env = qenv(env);
    LispObject v_24064, v_24065, v_24066;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24032);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_24064 = v_24032;
// end of prologue
    fn = elt(env, 2); // simp!*
    v_24065 = (*qfn1(fn))(fn, v_24064);
    env = stack[0];
    v_24064 = v_24065;
    v_24065 = qcar(v_24065);
    if (!consp(v_24065)) goto v_24040;
    else goto v_24041;
v_24040:
    v_24065 = lisp_true;
    goto v_24039;
v_24041:
    goto v_24052;
v_24048:
    v_24065 = v_24064;
    v_24065 = qcar(v_24065);
    v_24065 = qcar(v_24065);
    goto v_24049;
v_24050:
    v_24066 = elt(env, 1); // !:rn!:
    goto v_24051;
v_24052:
    goto v_24048;
v_24049:
    goto v_24050;
v_24051:
    v_24065 = (v_24065 == v_24066 ? lisp_true : nil);
    goto v_24039;
    v_24065 = nil;
v_24039:
    if (v_24065 == nil) goto v_24037;
    v_24064 = qcdr(v_24064);
    v_24064 = (consp(v_24064) ? nil : lisp_true);
    goto v_24035;
v_24037:
    v_24064 = nil;
    goto v_24035;
    v_24064 = nil;
v_24035:
    return onevalue(v_24064);
}



// Code for groeb!=testc1

static LispObject CC_groebMtestc1(LispObject env,
                         LispObject v_24032)
{
    env = qenv(env);
    LispObject v_24074, v_24075;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24032);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24032;
// end of prologue
    goto v_24039;
v_24035:
    goto v_24045;
v_24041:
    goto v_24053;
v_24049:
    v_24075 = stack[0];
    goto v_24050;
v_24051:
    v_24074 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_24052;
v_24053:
    goto v_24049;
v_24050:
    goto v_24051;
v_24052:
    fn = elt(env, 1); // nth
    v_24074 = (*qfn2(fn))(fn, v_24075, v_24074);
    env = stack[-2];
    fn = elt(env, 2); // bas_dpoly
    v_24074 = (*qfn1(fn))(fn, v_24074);
    env = stack[-2];
    fn = elt(env, 3); // dp_lmon
    stack[-1] = (*qfn1(fn))(fn, v_24074);
    env = stack[-2];
    goto v_24042;
v_24043:
    goto v_24063;
v_24059:
    v_24075 = stack[0];
    goto v_24060;
v_24061:
    v_24074 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_24062;
v_24063:
    goto v_24059;
v_24060:
    goto v_24061;
v_24062:
    fn = elt(env, 1); // nth
    v_24074 = (*qfn2(fn))(fn, v_24075, v_24074);
    env = stack[-2];
    fn = elt(env, 2); // bas_dpoly
    v_24074 = (*qfn1(fn))(fn, v_24074);
    env = stack[-2];
    fn = elt(env, 3); // dp_lmon
    v_24074 = (*qfn1(fn))(fn, v_24074);
    env = stack[-2];
    goto v_24044;
v_24045:
    goto v_24041;
v_24042:
    goto v_24043;
v_24044:
    fn = elt(env, 4); // mo_sum
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_24074);
    env = stack[-2];
    goto v_24036;
v_24037:
    goto v_24071;
v_24067:
    v_24075 = stack[0];
    goto v_24068;
v_24069:
    v_24074 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_24070;
v_24071:
    goto v_24067;
v_24068:
    goto v_24069;
v_24070:
    fn = elt(env, 1); // nth
    v_24074 = (*qfn2(fn))(fn, v_24075, v_24074);
    env = stack[-2];
    goto v_24038;
v_24039:
    goto v_24035;
v_24036:
    goto v_24037;
v_24038:
    {
        LispObject v_24078 = stack[-1];
        fn = elt(env, 5); // mo_equal!?
        return (*qfn2(fn))(fn, v_24078, v_24074);
    }
}



// Code for polynomread

static LispObject CC_polynomread(LispObject env,
                         LispObject v_24032)
{
    env = qenv(env);
    LispObject v_24155, v_24156, v_24157;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24032);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24032;
// end of prologue
    v_24155 = stack[0];
    if (v_24155 == nil) goto v_24036;
    else goto v_24037;
v_24036:
    v_24155 = nil;
    return ncons(v_24155);
v_24037:
    v_24155 = stack[0];
    if (!consp(v_24155)) goto v_24045;
    else goto v_24046;
v_24045:
    v_24155 = lisp_true;
    goto v_24044;
v_24046:
    v_24155 = stack[0];
    v_24155 = qcar(v_24155);
    v_24155 = (consp(v_24155) ? nil : lisp_true);
    goto v_24044;
    v_24155 = nil;
v_24044:
    if (v_24155 == nil) goto v_24042;
    goto v_24063;
v_24059:
    goto v_24069;
v_24065:
    v_24156 = stack[0];
    goto v_24066;
v_24067:
    v_24155 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_24068;
v_24069:
    goto v_24065;
v_24066:
    goto v_24067;
v_24068:
    v_24156 = Cremainder(v_24156, v_24155);
    env = stack[-2];
    goto v_24060;
v_24061:
    v_24155 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24062;
v_24063:
    goto v_24059;
v_24060:
    goto v_24061;
v_24062:
    v_24155 = Leqn(nil, v_24156, v_24155);
    env = stack[-2];
    if (v_24155 == nil) goto v_24057;
    goto v_24080;
v_24074:
    fn = elt(env, 3); // createmonomunit
    v_24157 = (*qfnn(fn))(fn, 0);
    goto v_24075;
v_24076:
    v_24156 = nil;
    goto v_24077;
v_24078:
    v_24155 = nil;
    goto v_24079;
v_24080:
    goto v_24074;
v_24075:
    goto v_24076;
v_24077:
    goto v_24078;
v_24079:
    return list2star(v_24157, v_24156, v_24155);
v_24057:
    v_24155 = nil;
    return ncons(v_24155);
    v_24155 = nil;
    goto v_24035;
v_24042:
    goto v_24094;
v_24090:
    v_24155 = stack[0];
    v_24155 = qcar(v_24155);
    v_24155 = qcar(v_24155);
    v_24156 = qcar(v_24155);
    goto v_24091;
v_24092:
    v_24155 = qvalue(elt(env, 1)); // fluidbibasisvariables
    goto v_24093;
v_24094:
    goto v_24090;
v_24091:
    goto v_24092;
v_24093:
    v_24155 = Lmember(nil, v_24156, v_24155);
    if (v_24155 == nil) goto v_24089;
    goto v_24106;
v_24102:
    goto v_24112;
v_24108:
    v_24155 = stack[0];
    v_24155 = qcar(v_24155);
    v_24155 = qcdr(v_24155);
    v_24157 = CC_polynomread(elt(env, 0), v_24155);
    env = stack[-2];
    goto v_24109;
v_24110:
    goto v_24121;
v_24117:
    v_24155 = stack[0];
    v_24155 = qcar(v_24155);
    v_24155 = qcar(v_24155);
    v_24156 = qcar(v_24155);
    goto v_24118;
v_24119:
    v_24155 = qvalue(elt(env, 2)); // fluidbibasissinglevariablemonomialsa
    goto v_24120;
v_24121:
    goto v_24117;
v_24118:
    goto v_24119;
v_24120:
    v_24155 = Lassoc(nil, v_24156, v_24155);
    v_24155 = qcdr(v_24155);
    goto v_24111;
v_24112:
    goto v_24108;
v_24109:
    goto v_24110;
v_24111:
    fn = elt(env, 4); // polynommultiplybymonom
    stack[-1] = (*qfn2(fn))(fn, v_24157, v_24155);
    env = stack[-2];
    goto v_24103;
v_24104:
    v_24155 = stack[0];
    v_24155 = qcdr(v_24155);
    v_24155 = CC_polynomread(elt(env, 0), v_24155);
    env = stack[-2];
    goto v_24105;
v_24106:
    goto v_24102;
v_24103:
    goto v_24104;
v_24105:
    {
        LispObject v_24160 = stack[-1];
        fn = elt(env, 5); // polynomadd
        return (*qfn2(fn))(fn, v_24160, v_24155);
    }
v_24089:
    goto v_24139;
v_24135:
    goto v_24145;
v_24141:
    v_24155 = stack[0];
    v_24155 = qcar(v_24155);
    v_24155 = qcdr(v_24155);
    stack[-1] = CC_polynomread(elt(env, 0), v_24155);
    env = stack[-2];
    goto v_24142;
v_24143:
    fn = elt(env, 3); // createmonomunit
    v_24155 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_24144;
v_24145:
    goto v_24141;
v_24142:
    goto v_24143;
v_24144:
    fn = elt(env, 4); // polynommultiplybymonom
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_24155);
    env = stack[-2];
    goto v_24136;
v_24137:
    v_24155 = stack[0];
    v_24155 = qcdr(v_24155);
    v_24155 = CC_polynomread(elt(env, 0), v_24155);
    env = stack[-2];
    goto v_24138;
v_24139:
    goto v_24135;
v_24136:
    goto v_24137;
v_24138:
    fn = elt(env, 5); // polynomadd
    v_24155 = (*qfn2(fn))(fn, stack[-1], v_24155);
    v_24155 = nil;
    goto v_24035;
    v_24155 = nil;
v_24035:
    return onevalue(v_24155);
}



// Code for fctlength

static LispObject CC_fctlength(LispObject env,
                         LispObject v_24032)
{
    env = qenv(env);
    LispObject v_24037;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24032);
    }
// copy arguments values to proper place
    v_24037 = v_24032;
// end of prologue
    fn = elt(env, 1); // fctargs
    v_24037 = (*qfn1(fn))(fn, v_24037);
        return Llength(nil, v_24037);
}



// Code for ofsf_anegrel

static LispObject CC_ofsf_anegrel(LispObject env,
                         LispObject v_24032)
{
    env = qenv(env);
    LispObject v_24055, v_24056, v_24057;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24032);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_24057 = v_24032;
// end of prologue
    goto v_24041;
v_24037:
    v_24056 = v_24057;
    goto v_24038;
v_24039:
    v_24055 = elt(env, 1); // ((equal . equal) (neq . neq) (leq . geq) (geq . leq) (lessp . greaterp) (greaterp . lessp))
    goto v_24040;
v_24041:
    goto v_24037;
v_24038:
    goto v_24039;
v_24040:
    v_24055 = Latsoc(nil, v_24056, v_24055);
    v_24055 = qcdr(v_24055);
    if (v_24055 == nil) goto v_24036;
    else goto v_24035;
v_24036:
    goto v_24052;
v_24048:
    v_24055 = elt(env, 2); // "ofsf_anegrel: unknown operator "
    goto v_24049;
v_24050:
    v_24056 = v_24057;
    goto v_24051;
v_24052:
    goto v_24048;
v_24049:
    goto v_24050;
v_24051:
    v_24055 = list2(v_24055, v_24056);
    env = stack[0];
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_24055);
    }
v_24035:
    return onevalue(v_24055);
}



// Code for intervalrd

static LispObject CC_intervalrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24089, v_24090;
    LispObject fn;
    argcheck(nargs, 0, "intervalrd");
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
    goto v_24044;
v_24040:
    v_24090 = qvalue(elt(env, 2)); // atts
    goto v_24041;
v_24042:
    v_24089 = elt(env, 3); // (closure)
    goto v_24043;
v_24044:
    goto v_24040;
v_24041:
    goto v_24042;
v_24043:
    fn = elt(env, 8); // retattributes
    v_24089 = (*qfn2(fn))(fn, v_24090, v_24089);
    env = stack[-4];
    stack[0] = v_24089;
    fn = elt(env, 9); // mathml
    v_24089 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_24089;
    fn = elt(env, 9); // mathml
    v_24089 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-2] = v_24089;
    fn = elt(env, 10); // lex
    v_24089 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_24058;
v_24054:
    v_24090 = qvalue(elt(env, 4)); // char
    goto v_24055;
v_24056:
    v_24089 = elt(env, 5); // (!/ i n t e r v a l)
    goto v_24057;
v_24058:
    goto v_24054;
v_24055:
    goto v_24056;
v_24057:
    if (equal(v_24090, v_24089)) goto v_24052;
    else goto v_24053;
v_24052:
    goto v_24068;
v_24062:
    stack[-1] = elt(env, 6); // interval
    goto v_24063;
v_24064:
    goto v_24065;
v_24066:
    goto v_24076;
v_24072:
    v_24090 = stack[-3];
    goto v_24073;
v_24074:
    v_24089 = stack[-2];
    goto v_24075;
v_24076:
    goto v_24072;
v_24073:
    goto v_24074;
v_24075:
    v_24089 = list2(v_24090, v_24089);
    goto v_24067;
v_24068:
    goto v_24062;
v_24063:
    goto v_24064;
v_24065:
    goto v_24066;
v_24067:
    {
        LispObject v_24095 = stack[-1];
        LispObject v_24096 = stack[0];
        return list2star(v_24095, v_24096, v_24089);
    }
v_24053:
    goto v_24086;
v_24082:
    v_24090 = elt(env, 7); // "</interval>"
    goto v_24083;
v_24084:
    v_24089 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_24085;
v_24086:
    goto v_24082;
v_24083:
    goto v_24084;
v_24085:
    fn = elt(env, 11); // errorml
    v_24089 = (*qfn2(fn))(fn, v_24090, v_24089);
    goto v_24051;
v_24051:
    v_24089 = nil;
    return onevalue(v_24089);
}



// Code for new_simpexpt

static LispObject CC_new_simpexpt(LispObject env,
                         LispObject v_24032)
{
    env = qenv(env);
    LispObject v_24134, v_24135;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24032);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_24032;
// end of prologue
// Binding !*precise
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
    qvalue(elt(env, 1)) = nil; // !*precise
// Binding !*factor
// FLUIDBIND: reloadenv=7 litvec-offset=2 saveloc=4
{   bind_fluid_stack bind_fluid_var(-7, 2, -4);
    qvalue(elt(env, 2)) = nil; // !*factor
// Binding !*exp
// FLUIDBIND: reloadenv=7 litvec-offset=3 saveloc=3
{   bind_fluid_stack bind_fluid_var(-7, 3, -3);
    qvalue(elt(env, 3)) = nil; // !*exp
// Binding !*mcd
// FLUIDBIND: reloadenv=7 litvec-offset=4 saveloc=2
{   bind_fluid_stack bind_fluid_var(-7, 4, -2);
    qvalue(elt(env, 4)) = nil; // !*mcd
// Binding !*allfac
// FLUIDBIND: reloadenv=7 litvec-offset=5 saveloc=1
{   bind_fluid_stack bind_fluid_var(-7, 5, -1);
    qvalue(elt(env, 5)) = nil; // !*allfac
    goto v_24049;
v_24045:
    v_24135 = elt(env, 7); // exp
    goto v_24046;
v_24047:
    v_24134 = elt(env, 8); // mcd
    goto v_24048;
v_24049:
    goto v_24045;
v_24046:
    goto v_24047;
v_24048:
    v_24134 = list2(v_24135, v_24134);
    env = stack[-7];
    fn = elt(env, 15); // on
    v_24134 = (*qfn1(fn))(fn, v_24134);
    env = stack[-7];
    goto v_24058;
v_24054:
    v_24135 = elt(env, 9); // precise
    goto v_24055;
v_24056:
    v_24134 = elt(env, 10); // allfac
    goto v_24057;
v_24058:
    goto v_24054;
v_24055:
    goto v_24056;
v_24057:
    v_24134 = list2(v_24135, v_24134);
    env = stack[-7];
    fn = elt(env, 16); // off
    v_24134 = (*qfn1(fn))(fn, v_24134);
    env = stack[-7];
    goto v_24070;
v_24066:
    v_24134 = stack[-5];
    v_24135 = qcar(v_24134);
    goto v_24067;
v_24068:
    v_24134 = elt(env, 11); // minus
    goto v_24069;
v_24070:
    goto v_24066;
v_24067:
    goto v_24068;
v_24069:
    if (!consp(v_24135)) goto v_24064;
    v_24135 = qcar(v_24135);
    if (v_24135 == v_24134) goto v_24063;
    else goto v_24064;
v_24063:
    goto v_24079;
v_24075:
    goto v_24086;
v_24082:
    goto v_24092;
v_24088:
    v_24135 = elt(env, 11); // minus
    goto v_24089;
v_24090:
    v_24134 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24091;
v_24092:
    goto v_24088;
v_24089:
    goto v_24090;
v_24091:
    v_24135 = list2(v_24135, v_24134);
    env = stack[-7];
    goto v_24083;
v_24084:
    v_24134 = stack[-5];
    v_24134 = qcdr(v_24134);
    v_24134 = qcar(v_24134);
    goto v_24085;
v_24086:
    goto v_24082;
v_24083:
    goto v_24084;
v_24085:
    v_24134 = list2(v_24135, v_24134);
    env = stack[-7];
    fn = elt(env, 14); // original_simpexpt
    stack[0] = (*qfn1(fn))(fn, v_24134);
    env = stack[-7];
    goto v_24076;
v_24077:
    goto v_24104;
v_24100:
    v_24134 = stack[-5];
    v_24134 = qcar(v_24134);
    v_24134 = qcdr(v_24134);
    v_24135 = qcar(v_24134);
    goto v_24101;
v_24102:
    v_24134 = stack[-5];
    v_24134 = qcdr(v_24134);
    v_24134 = qcar(v_24134);
    goto v_24103;
v_24104:
    goto v_24100;
v_24101:
    goto v_24102;
v_24103:
    v_24134 = list2(v_24135, v_24134);
    env = stack[-7];
    v_24134 = CC_new_simpexpt(elt(env, 0), v_24134);
    env = stack[-7];
    goto v_24078;
v_24079:
    goto v_24075;
v_24076:
    goto v_24077;
v_24078:
    fn = elt(env, 17); // multsq
    v_24134 = (*qfn2(fn))(fn, stack[0], v_24134);
    goto v_24041;
v_24064:
    v_24134 = qvalue(elt(env, 12)); // !*redefmsg
    stack[0] = v_24134;
    v_24134 = nil;
    qvalue(elt(env, 12)) = v_24134; // !*redefmsg
    goto v_24119;
v_24115:
    v_24135 = elt(env, 13); // simpexpt
    goto v_24116;
v_24117:
    v_24134 = elt(env, 14); // original_simpexpt
    goto v_24118;
v_24119:
    goto v_24115;
v_24116:
    goto v_24117;
v_24118:
    fn = elt(env, 18); // copyd
    v_24134 = (*qfn2(fn))(fn, v_24135, v_24134);
    env = stack[-7];
    v_24134 = stack[-5];
    fn = elt(env, 13); // simpexpt
    v_24134 = (*qfn1(fn))(fn, v_24134);
    env = stack[-7];
    stack[-5] = v_24134;
    goto v_24129;
v_24125:
    v_24135 = elt(env, 13); // simpexpt
    goto v_24126;
v_24127:
    v_24134 = elt(env, 0); // new_simpexpt
    goto v_24128;
v_24129:
    goto v_24125;
v_24126:
    goto v_24127;
v_24128:
    fn = elt(env, 18); // copyd
    v_24134 = (*qfn2(fn))(fn, v_24135, v_24134);
    env = stack[-7];
    v_24134 = stack[0];
    qvalue(elt(env, 12)) = v_24134; // !*redefmsg
    v_24134 = stack[-5];
v_24041:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_24134);
}



// Code for get!:const

static LispObject CC_getTconst(LispObject env,
                         LispObject v_24032, LispObject v_24033)
{
    env = qenv(env);
    LispObject v_24125, v_24126;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24033,v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24032,v_24033);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24033;
    stack[-1] = v_24032;
// end of prologue
    v_24125 = stack[-1];
    if (!consp(v_24125)) goto v_24041;
    else goto v_24042;
v_24041:
    v_24125 = stack[0];
    v_24125 = integerp(v_24125);
    if (v_24125 == nil) goto v_24046;
    else goto v_24047;
v_24046:
    v_24125 = nil;
    goto v_24045;
v_24047:
    goto v_24058;
v_24054:
    v_24126 = stack[0];
    goto v_24055;
v_24056:
    v_24125 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24057;
v_24058:
    goto v_24054;
v_24055:
    goto v_24056;
v_24057:
    v_24125 = (LispObject)greaterp2(v_24126, v_24125);
    v_24125 = v_24125 ? lisp_true : nil;
    env = stack[-2];
    goto v_24045;
    v_24125 = nil;
v_24045:
    goto v_24040;
v_24042:
    v_24125 = nil;
    goto v_24040;
    v_24125 = nil;
v_24040:
    if (v_24125 == nil) goto v_24038;
    goto v_24073;
v_24069:
    v_24126 = stack[-1];
    goto v_24070;
v_24071:
    v_24125 = elt(env, 2); // save!:c
    goto v_24072;
v_24073:
    goto v_24069;
v_24070:
    goto v_24071;
v_24072:
    v_24125 = get(v_24126, v_24125);
    env = stack[-2];
    stack[-1] = v_24125;
    v_24125 = stack[-1];
    if (v_24125 == nil) goto v_24082;
    else goto v_24083;
v_24082:
    v_24125 = lisp_true;
    goto v_24081;
v_24083:
    goto v_24093;
v_24089:
    v_24125 = stack[-1];
    v_24126 = qcar(v_24125);
    goto v_24090;
v_24091:
    v_24125 = stack[0];
    goto v_24092;
v_24093:
    goto v_24089;
v_24090:
    goto v_24091;
v_24092:
    v_24125 = (LispObject)lessp2(v_24126, v_24125);
    v_24125 = v_24125 ? lisp_true : nil;
    env = stack[-2];
    goto v_24081;
    v_24125 = nil;
v_24081:
    if (v_24125 == nil) goto v_24079;
    v_24125 = elt(env, 3); // not_found
    goto v_24066;
v_24079:
    goto v_24104;
v_24100:
    v_24125 = stack[-1];
    v_24126 = qcar(v_24125);
    goto v_24101;
v_24102:
    v_24125 = stack[0];
    goto v_24103;
v_24104:
    goto v_24100;
v_24101:
    goto v_24102;
v_24103:
    if (equal(v_24126, v_24125)) goto v_24098;
    else goto v_24099;
v_24098:
    v_24125 = stack[-1];
    v_24125 = qcdr(v_24125);
    goto v_24066;
v_24099:
    goto v_24117;
v_24113:
    v_24125 = stack[-1];
    v_24126 = qcdr(v_24125);
    goto v_24114;
v_24115:
    v_24125 = stack[0];
    goto v_24116;
v_24117:
    goto v_24113;
v_24114:
    goto v_24115;
v_24116:
    {
        fn = elt(env, 4); // round!:mt
        return (*qfn2(fn))(fn, v_24126, v_24125);
    }
    v_24125 = nil;
v_24066:
    goto v_24036;
v_24038:
    v_24125 = elt(env, 0); // get!:const
    {
        fn = elt(env, 5); // bflerrmsg
        return (*qfn1(fn))(fn, v_24125);
    }
    v_24125 = nil;
v_24036:
    return onevalue(v_24125);
}



// Code for numprintlen

static LispObject CC_numprintlen(LispObject env,
                         LispObject v_24032)
{
    env = qenv(env);
    LispObject v_24228, v_24229;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24032);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_24032;
// end of prologue
v_24036:
    v_24228 = stack[-1];
    if (!consp(v_24228)) goto v_24039;
    else goto v_24040;
v_24039:
    v_24228 = stack[-1];
    v_24228 = Lexplode(nil, v_24228);
        return Llength(nil, v_24228);
v_24040:
    v_24228 = stack[-1];
    v_24228 = Llength(nil, v_24228);
    env = stack[-6];
    v_24228 = Lonep(nil, v_24228);
    env = stack[-6];
    if (v_24228 == nil) goto v_24046;
    v_24228 = stack[-1];
    v_24228 = qcar(v_24228);
    stack[-1] = v_24228;
    goto v_24036;
v_24046:
    goto v_24058;
v_24054:
    v_24228 = stack[-1];
    v_24229 = qcar(v_24228);
    goto v_24055;
v_24056:
    v_24228 = elt(env, 1); // !:rd!:
    goto v_24057;
v_24058:
    goto v_24054;
v_24055:
    goto v_24056;
v_24057:
    if (v_24229 == v_24228) goto v_24052;
    else goto v_24053;
v_24052:
    v_24228 = stack[-1];
    fn = elt(env, 4); // rd!:explode
    v_24228 = (*qfn1(fn))(fn, v_24228);
    env = stack[-6];
    stack[-1] = v_24228;
    goto v_24069;
v_24065:
    stack[-2] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_24066;
v_24067:
    goto v_24076;
v_24072:
    v_24228 = stack[-1];
    v_24228 = qcar(v_24228);
    stack[0] = Llength(nil, v_24228);
    env = stack[-6];
    goto v_24073;
v_24074:
    v_24228 = stack[-1];
    v_24228 = qcdr(v_24228);
    v_24228 = qcar(v_24228);
    v_24228 = Lexplode(nil, v_24228);
    env = stack[-6];
    v_24228 = Llength(nil, v_24228);
    env = stack[-6];
    goto v_24075;
v_24076:
    goto v_24072;
v_24073:
    goto v_24074;
v_24075:
    v_24228 = plus2(stack[0], v_24228);
    goto v_24068;
v_24069:
    goto v_24065;
v_24066:
    goto v_24067;
v_24068:
    {
        LispObject v_24236 = stack[-2];
        return plus2(v_24236, v_24228);
    }
v_24053:
    goto v_24091;
v_24087:
    v_24228 = stack[-1];
    v_24229 = qcar(v_24228);
    goto v_24088;
v_24089:
    v_24228 = elt(env, 2); // (!:cr!: !:crn!: !:gi!:)
    goto v_24090;
v_24091:
    goto v_24087;
v_24088:
    goto v_24089;
v_24090:
    v_24228 = Lmemq(nil, v_24229, v_24228);
    if (v_24228 == nil) goto v_24086;
    goto v_24101;
v_24097:
    goto v_24108;
v_24104:
    v_24229 = elt(env, 1); // !:rd!:
    goto v_24105;
v_24106:
    v_24228 = stack[-1];
    v_24228 = qcdr(v_24228);
    v_24228 = qcar(v_24228);
    goto v_24107;
v_24108:
    goto v_24104;
v_24105:
    goto v_24106;
v_24107:
    v_24228 = cons(v_24229, v_24228);
    env = stack[-6];
    fn = elt(env, 4); // rd!:explode
    stack[0] = (*qfn1(fn))(fn, v_24228);
    env = stack[-6];
    goto v_24098;
v_24099:
    goto v_24119;
v_24115:
    v_24229 = elt(env, 1); // !:rd!:
    goto v_24116;
v_24117:
    v_24228 = stack[-1];
    v_24228 = qcdr(v_24228);
    v_24228 = qcdr(v_24228);
    goto v_24118;
v_24119:
    goto v_24115;
v_24116:
    goto v_24117;
v_24118:
    v_24228 = cons(v_24229, v_24228);
    env = stack[-6];
    fn = elt(env, 4); // rd!:explode
    v_24228 = (*qfn1(fn))(fn, v_24228);
    env = stack[-6];
    goto v_24100;
v_24101:
    goto v_24097;
v_24098:
    goto v_24099;
v_24100:
    v_24228 = cons(stack[0], v_24228);
    env = stack[-6];
    stack[-1] = v_24228;
    goto v_24129;
v_24125:
    stack[-4] = (LispObject)192+TAG_FIXNUM; // 12
    goto v_24126;
v_24127:
    goto v_24136;
v_24132:
    v_24228 = stack[-1];
    v_24228 = qcar(v_24228);
    v_24228 = qcar(v_24228);
    stack[-3] = Llength(nil, v_24228);
    env = stack[-6];
    goto v_24133;
v_24134:
    goto v_24146;
v_24142:
    v_24228 = stack[-1];
    v_24228 = qcar(v_24228);
    v_24228 = qcdr(v_24228);
    v_24228 = Lexplode(nil, v_24228);
    env = stack[-6];
    stack[-2] = Llength(nil, v_24228);
    env = stack[-6];
    goto v_24143;
v_24144:
    goto v_24157;
v_24153:
    v_24228 = stack[-1];
    v_24228 = qcdr(v_24228);
    v_24228 = qcar(v_24228);
    stack[0] = Llength(nil, v_24228);
    env = stack[-6];
    goto v_24154;
v_24155:
    v_24228 = stack[-1];
    v_24228 = qcdr(v_24228);
    v_24228 = qcdr(v_24228);
    v_24228 = Lexplode(nil, v_24228);
    env = stack[-6];
    v_24228 = Llength(nil, v_24228);
    env = stack[-6];
    goto v_24156;
v_24157:
    goto v_24153;
v_24154:
    goto v_24155;
v_24156:
    v_24228 = plus2(stack[0], v_24228);
    env = stack[-6];
    goto v_24145;
v_24146:
    goto v_24142;
v_24143:
    goto v_24144;
v_24145:
    v_24228 = plus2(stack[-2], v_24228);
    env = stack[-6];
    goto v_24135;
v_24136:
    goto v_24132;
v_24133:
    goto v_24134;
v_24135:
    v_24228 = plus2(stack[-3], v_24228);
    goto v_24128;
v_24129:
    goto v_24125;
v_24126:
    goto v_24127;
v_24128:
    {
        LispObject v_24237 = stack[-4];
        return plus2(v_24237, v_24228);
    }
v_24086:
    goto v_24174;
v_24170:
    v_24228 = stack[-1];
    stack[-5] = Llength(nil, v_24228);
    env = stack[-6];
    goto v_24171;
v_24172:
    goto v_24183;
v_24179:
    stack[-4] = elt(env, 3); // plus
    goto v_24180;
v_24181:
    v_24228 = stack[-1];
    v_24228 = qcdr(v_24228);
    stack[-3] = v_24228;
    v_24228 = stack[-3];
    if (v_24228 == nil) goto v_24195;
    else goto v_24196;
v_24195:
    v_24228 = nil;
    goto v_24189;
v_24196:
    v_24228 = stack[-3];
    v_24228 = qcar(v_24228);
    v_24228 = CC_numprintlen(elt(env, 0), v_24228);
    env = stack[-6];
    v_24228 = ncons(v_24228);
    env = stack[-6];
    stack[-1] = v_24228;
    stack[-2] = v_24228;
v_24190:
    v_24228 = stack[-3];
    v_24228 = qcdr(v_24228);
    stack[-3] = v_24228;
    v_24228 = stack[-3];
    if (v_24228 == nil) goto v_24209;
    else goto v_24210;
v_24209:
    v_24228 = stack[-2];
    goto v_24189;
v_24210:
    goto v_24218;
v_24214:
    stack[0] = stack[-1];
    goto v_24215;
v_24216:
    v_24228 = stack[-3];
    v_24228 = qcar(v_24228);
    v_24228 = CC_numprintlen(elt(env, 0), v_24228);
    env = stack[-6];
    v_24228 = ncons(v_24228);
    env = stack[-6];
    goto v_24217;
v_24218:
    goto v_24214;
v_24215:
    goto v_24216;
v_24217:
    v_24228 = Lrplacd(nil, stack[0], v_24228);
    env = stack[-6];
    v_24228 = stack[-1];
    v_24228 = qcdr(v_24228);
    stack[-1] = v_24228;
    goto v_24190;
v_24189:
    goto v_24182;
v_24183:
    goto v_24179;
v_24180:
    goto v_24181;
v_24182:
    v_24228 = cons(stack[-4], v_24228);
    env = stack[-6];
    fn = elt(env, 5); // lispeval
    v_24228 = (*qfn1(fn))(fn, v_24228);
    goto v_24173;
v_24174:
    goto v_24170;
v_24171:
    goto v_24172;
v_24173:
    {
        LispObject v_24238 = stack[-5];
        return plus2(v_24238, v_24228);
    }
    v_24228 = nil;
    return onevalue(v_24228);
}



// Code for miller!-rabin

static LispObject CC_millerKrabin(LispObject env,
                         LispObject v_24032, LispObject v_24033)
{
    env = qenv(env);
    LispObject v_24215, v_24216;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24033,v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24032,v_24033);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_24033;
    stack[0] = v_24032;
// end of prologue
    goto v_24050;
v_24046:
    v_24216 = stack[-2];
    goto v_24047;
v_24048:
    v_24215 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24049;
v_24050:
    goto v_24046;
v_24047:
    goto v_24048;
v_24049:
    if (v_24216 == v_24215) goto v_24044;
    else goto v_24045;
v_24044:
    v_24215 = nil;
    goto v_24039;
v_24045:
    goto v_24060;
v_24056:
    goto v_24066;
v_24062:
    v_24216 = stack[-2];
    goto v_24063;
v_24064:
    v_24215 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_24065;
v_24066:
    goto v_24062;
v_24063:
    goto v_24064;
v_24065:
    v_24216 = Cremainder(v_24216, v_24215);
    env = stack[-4];
    goto v_24057;
v_24058:
    v_24215 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24059;
v_24060:
    goto v_24056;
v_24057:
    goto v_24058;
v_24059:
    if (v_24216 == v_24215) goto v_24054;
    else goto v_24055;
v_24054:
    goto v_24074;
v_24070:
    v_24216 = stack[-2];
    goto v_24071;
v_24072:
    v_24215 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_24073;
v_24074:
    goto v_24070;
v_24071:
    goto v_24072;
v_24073:
    v_24215 = (v_24216 == v_24215 ? lisp_true : nil);
    goto v_24039;
v_24055:
    goto v_24085;
v_24081:
    v_24216 = stack[-2];
    goto v_24082;
v_24083:
    v_24215 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_24084;
v_24085:
    goto v_24081;
v_24082:
    goto v_24083;
v_24084:
    v_24215 = (LispObject)lesseq2(v_24216, v_24215);
    v_24215 = v_24215 ? lisp_true : nil;
    env = stack[-4];
    if (v_24215 == nil) goto v_24079;
    v_24215 = lisp_true;
    goto v_24039;
v_24079:
    v_24215 = stack[-2];
    v_24215 = sub1(v_24215);
    env = stack[-4];
    stack[-1] = v_24215;
    v_24215 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_24215;
v_24094:
    goto v_24103;
v_24099:
    goto v_24109;
v_24105:
    v_24216 = stack[-1];
    goto v_24106;
v_24107:
    v_24215 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_24108;
v_24109:
    goto v_24105;
v_24106:
    goto v_24107;
v_24108:
    v_24216 = Cremainder(v_24216, v_24215);
    env = stack[-4];
    goto v_24100;
v_24101:
    v_24215 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24102;
v_24103:
    goto v_24099;
v_24100:
    goto v_24101;
v_24102:
    if (v_24216 == v_24215) goto v_24098;
    goto v_24093;
v_24098:
    goto v_24119;
v_24115:
    v_24216 = stack[-1];
    goto v_24116;
v_24117:
    v_24215 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_24118;
v_24119:
    goto v_24115;
v_24116:
    goto v_24117;
v_24118:
    v_24215 = quot2(v_24216, v_24215);
    env = stack[-4];
    stack[-1] = v_24215;
    v_24215 = stack[-3];
    v_24215 = add1(v_24215);
    env = stack[-4];
    stack[-3] = v_24215;
    goto v_24094;
v_24093:
    v_24215 = stack[-2];
    fn = elt(env, 2); // set!-modulus
    v_24215 = (*qfn1(fn))(fn, v_24215);
    env = stack[-4];
    goto v_24131;
v_24127:
    v_24216 = stack[0];
    goto v_24128;
v_24129:
    v_24215 = stack[-2];
    goto v_24130;
v_24131:
    goto v_24127;
v_24128:
    goto v_24129;
v_24130:
    v_24215 = Cremainder(v_24216, v_24215);
    env = stack[-4];
    stack[0] = v_24215;
    goto v_24139;
v_24135:
    v_24216 = stack[0];
    goto v_24136;
v_24137:
    v_24215 = stack[-1];
    goto v_24138;
v_24139:
    goto v_24135;
v_24136:
    goto v_24137;
v_24138:
    v_24215 = Lmodular_expt(nil, v_24216, v_24215);
    env = stack[-4];
    stack[-1] = v_24215;
    goto v_24154;
v_24150:
    v_24216 = stack[-1];
    goto v_24151;
v_24152:
    v_24215 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24153;
v_24154:
    goto v_24150;
v_24151:
    goto v_24152;
v_24153:
    if (v_24216 == v_24215) goto v_24148;
    else goto v_24149;
v_24148:
    v_24215 = lisp_true;
    goto v_24147;
v_24149:
    goto v_24164;
v_24160:
    stack[0] = stack[-1];
    goto v_24161;
v_24162:
    v_24215 = stack[-2];
    v_24215 = sub1(v_24215);
    env = stack[-4];
    goto v_24163;
v_24164:
    goto v_24160;
v_24161:
    goto v_24162;
v_24163:
    v_24215 = (equal(stack[0], v_24215) ? lisp_true : nil);
    goto v_24147;
    v_24215 = nil;
v_24147:
    if (v_24215 == nil) goto v_24145;
    v_24215 = lisp_true;
    goto v_24039;
v_24145:
v_24040:
    goto v_24178;
v_24174:
    v_24216 = stack[-3];
    goto v_24175;
v_24176:
    v_24215 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24177;
v_24178:
    goto v_24174;
v_24175:
    goto v_24176;
v_24177:
    if (v_24216 == v_24215) goto v_24172;
    else goto v_24173;
v_24172:
    v_24215 = nil;
    goto v_24039;
v_24173:
    goto v_24187;
v_24183:
    v_24216 = stack[-1];
    goto v_24184;
v_24185:
    v_24215 = stack[-1];
    goto v_24186;
v_24187:
    goto v_24183;
v_24184:
    goto v_24185;
v_24186:
    v_24215 = Lmodular_times(nil, v_24216, v_24215);
    env = stack[-4];
    stack[-1] = v_24215;
    goto v_24198;
v_24194:
    v_24216 = stack[-1];
    goto v_24195;
v_24196:
    v_24215 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24197;
v_24198:
    goto v_24194;
v_24195:
    goto v_24196;
v_24197:
    if (v_24216 == v_24215) goto v_24192;
    else goto v_24193;
v_24192:
    v_24215 = nil;
    goto v_24039;
v_24193:
    goto v_24208;
v_24204:
    stack[0] = stack[-1];
    goto v_24205;
v_24206:
    v_24215 = stack[-2];
    v_24215 = sub1(v_24215);
    env = stack[-4];
    goto v_24207;
v_24208:
    goto v_24204;
v_24205:
    goto v_24206;
v_24207:
    if (equal(stack[0], v_24215)) goto v_24202;
    else goto v_24203;
v_24202:
    v_24215 = lisp_true;
    goto v_24039;
v_24203:
    v_24215 = stack[-3];
    v_24215 = sub1(v_24215);
    env = stack[-4];
    stack[-3] = v_24215;
    goto v_24040;
v_24039:
    return onevalue(v_24215);
}



// Code for revalpart

static LispObject CC_revalpart(LispObject env,
                         LispObject v_24032)
{
    env = qenv(env);
    LispObject v_24432, v_24433, v_24434, v_24435, v_24436;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24032);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[0] = v_24032;
// end of prologue
    v_24432 = stack[0];
    if (v_24432 == nil) goto v_24036;
    else goto v_24037;
v_24036:
    goto v_24046;
v_24040:
    v_24434 = elt(env, 1); // alg
    goto v_24041;
v_24042:
    v_24433 = (LispObject)3216+TAG_FIXNUM; // 201
    goto v_24043;
v_24044:
    v_24432 = elt(env, 2); // "part called without arguments"
    goto v_24045;
v_24046:
    goto v_24040;
v_24041:
    goto v_24042;
v_24043:
    goto v_24044;
v_24045:
    {
        fn = elt(env, 12); // rerror
        return (*qfnn(fn))(fn, 3, v_24434, v_24433, v_24432);
    }
v_24037:
// Binding !*intstr
// FLUIDBIND: reloadenv=8 litvec-offset=3 saveloc=7
{   bind_fluid_stack bind_fluid_var(-8, 3, -7);
    qvalue(elt(env, 3)) = nil; // !*intstr
    stack[-6] = nil;
    v_24432 = lisp_true;
    qvalue(elt(env, 3)) = v_24432; // !*intstr
    goto v_24069;
v_24065:
    v_24432 = stack[0];
    v_24432 = qcar(v_24432);
    fn = elt(env, 13); // getrtype
    v_24433 = (*qfn1(fn))(fn, v_24432);
    env = stack[-8];
    stack[-3] = v_24433;
    goto v_24066;
v_24067:
    v_24432 = elt(env, 5); // list
    goto v_24068;
v_24069:
    goto v_24065;
v_24066:
    goto v_24067;
v_24068:
    if (v_24433 == v_24432) goto v_24063;
    else goto v_24064;
v_24063:
    v_24432 = stack[0];
    v_24432 = qcar(v_24432);
    if (!consp(v_24432)) goto v_24081;
    goto v_24089;
v_24085:
    v_24432 = stack[0];
    v_24432 = qcar(v_24432);
    v_24433 = qcar(v_24432);
    goto v_24086;
v_24087:
    v_24432 = elt(env, 6); // listfn
    goto v_24088;
v_24089:
    goto v_24085;
v_24086:
    goto v_24087;
v_24088:
    v_24432 = get(v_24433, v_24432);
    env = stack[-8];
    goto v_24079;
v_24081:
    v_24432 = nil;
    goto v_24079;
    v_24432 = nil;
v_24079:
    if (v_24432 == nil) goto v_24077;
    v_24432 = stack[0];
    v_24432 = qcar(v_24432);
    fn = elt(env, 14); // reval
    v_24432 = (*qfn1(fn))(fn, v_24432);
    env = stack[-8];
    goto v_24075;
v_24077:
    v_24432 = stack[0];
    v_24432 = qcar(v_24432);
    fn = elt(env, 15); // listeval0
    v_24432 = (*qfn1(fn))(fn, v_24432);
    env = stack[-8];
    goto v_24075;
    v_24432 = nil;
v_24075:
    goto v_24062;
v_24064:
    v_24432 = stack[0];
    v_24432 = qcar(v_24432);
    fn = elt(env, 14); // reval
    v_24432 = (*qfn1(fn))(fn, v_24432);
    env = stack[-8];
    goto v_24062;
    v_24432 = nil;
v_24062:
    stack[-5] = v_24432;
    v_24432 = nil;
    qvalue(elt(env, 3)) = v_24432; // !*intstr
    v_24432 = stack[0];
    v_24432 = qcdr(v_24432);
    stack[-4] = v_24432;
v_24115:
    v_24432 = stack[-4];
    if (v_24432 == nil) goto v_24118;
    else goto v_24119;
v_24118:
    goto v_24114;
v_24119:
    stack[-2] = nil;
    stack[-1] = nil;
    goto v_24133;
v_24129:
    v_24433 = stack[-5];
    goto v_24130;
v_24131:
    v_24432 = elt(env, 8); // !*hold
    goto v_24132;
v_24133:
    goto v_24129;
v_24130:
    goto v_24131;
v_24132:
    v_24432 = Leqcar(nil, v_24433, v_24432);
    env = stack[-8];
    stack[0] = v_24432;
    v_24432 = stack[-5];
    if (!consp(v_24432)) goto v_24138;
    else goto v_24139;
v_24138:
    goto v_24146;
v_24142:
    v_24433 = stack[-5];
    goto v_24143;
v_24144:
    v_24432 = stack[-4];
    v_24432 = qcar(v_24432);
    goto v_24145;
v_24146:
    goto v_24142;
v_24143:
    goto v_24144;
v_24145:
    fn = elt(env, 16); // parterr2
    v_24432 = (*qfn2(fn))(fn, v_24433, v_24432);
    env = stack[-8];
    v_24432 = lisp_true;
    stack[-6] = v_24432;
    goto v_24137;
v_24139:
    v_24432 = stack[-4];
    v_24432 = qcar(v_24432);
    fn = elt(env, 14); // reval
    v_24432 = (*qfn1(fn))(fn, v_24432);
    env = stack[-8];
    stack[-2] = v_24432;
    if (is_number(v_24432)) goto v_24152;
    goto v_24167;
v_24157:
    v_24436 = elt(env, 9); // "Invalid argument"
    goto v_24158;
v_24159:
    v_24432 = stack[-4];
    v_24435 = qcar(v_24432);
    goto v_24160;
v_24161:
    v_24434 = elt(env, 10); // "to part"
    goto v_24162;
v_24163:
    v_24433 = nil;
    goto v_24164;
v_24165:
    v_24432 = lisp_true;
    goto v_24166;
v_24167:
    goto v_24157;
v_24158:
    goto v_24159;
v_24160:
    goto v_24161;
v_24162:
    goto v_24163;
v_24164:
    goto v_24165;
v_24166:
    fn = elt(env, 17); // msgpri
    v_24432 = (*qfnn(fn))(fn, 5, v_24436, v_24435, v_24434, v_24433, v_24432);
    env = stack[-8];
    goto v_24137;
v_24152:
    goto v_24181;
v_24177:
    v_24432 = stack[-5];
    v_24433 = qcar(v_24432);
    goto v_24178;
v_24179:
    v_24432 = elt(env, 11); // partop
    goto v_24180;
v_24181:
    goto v_24177;
v_24178:
    goto v_24179;
v_24180:
    v_24432 = get(v_24433, v_24432);
    env = stack[-8];
    stack[-1] = v_24432;
    if (v_24432 == nil) goto v_24175;
    goto v_24192;
v_24186:
    v_24434 = stack[-1];
    goto v_24187;
v_24188:
    v_24433 = stack[-5];
    goto v_24189;
v_24190:
    v_24432 = stack[-2];
    goto v_24191;
v_24192:
    goto v_24186;
v_24187:
    goto v_24188;
v_24189:
    goto v_24190;
v_24191:
    v_24432 = Lapply2(nil, 3, v_24434, v_24433, v_24432);
    env = stack[-8];
    stack[-5] = v_24432;
    v_24432 = stack[-4];
    v_24432 = qcdr(v_24432);
    stack[-4] = v_24432;
    goto v_24126;
v_24175:
    goto v_24204;
v_24200:
    v_24433 = stack[-2];
    goto v_24201;
v_24202:
    v_24432 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24203;
v_24204:
    goto v_24200;
v_24201:
    goto v_24202;
v_24203:
    if (v_24433 == v_24432) goto v_24198;
    else goto v_24199;
v_24198:
    v_24432 = stack[-5];
    v_24432 = qcar(v_24432);
    stack[0] = v_24432;
    goto v_24222;
v_24218:
    v_24432 = stack[0];
    fn = elt(env, 13); // getrtype
    v_24433 = (*qfn1(fn))(fn, v_24432);
    env = stack[-8];
    goto v_24219;
v_24220:
    v_24432 = elt(env, 5); // list
    goto v_24221;
v_24222:
    goto v_24218;
v_24219:
    goto v_24220;
v_24221:
    if (v_24433 == v_24432) goto v_24216;
    else goto v_24217;
v_24216:
    v_24432 = elt(env, 5); // list
    stack[-3] = v_24432;
    goto v_24215;
v_24217:
    v_24432 = nil;
    goto v_24215;
    v_24432 = nil;
v_24215:
    if (v_24432 == nil) goto v_24213;
    v_24432 = stack[0];
    fn = elt(env, 15); // listeval0
    v_24432 = (*qfn1(fn))(fn, v_24432);
    env = stack[-8];
    goto v_24211;
v_24213:
    goto v_24238;
v_24234:
    v_24433 = stack[-3];
    goto v_24235;
v_24236:
    v_24432 = elt(env, 5); // list
    goto v_24237;
v_24238:
    goto v_24234;
v_24235:
    goto v_24236;
v_24237:
    if (v_24433 == v_24432) goto v_24232;
    else goto v_24233;
v_24232:
    v_24432 = lisp_true;
    qvalue(elt(env, 3)) = v_24432; // !*intstr
    v_24432 = stack[0];
    fn = elt(env, 14); // reval
    v_24432 = (*qfn1(fn))(fn, v_24432);
    env = stack[-8];
    stack[0] = v_24432;
    v_24432 = nil;
    stack[-3] = v_24432;
    qvalue(elt(env, 3)) = v_24432; // !*intstr
    v_24432 = stack[0];
    goto v_24211;
v_24233:
    v_24432 = stack[0];
    goto v_24211;
    v_24432 = nil;
v_24211:
    stack[-5] = v_24432;
    v_24432 = nil;
    stack[-4] = v_24432;
    goto v_24126;
v_24199:
    goto v_24257;
v_24253:
    v_24433 = stack[-2];
    goto v_24254;
v_24255:
    v_24432 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24256;
v_24257:
    goto v_24253;
v_24254:
    goto v_24255;
v_24256:
    v_24432 = (LispObject)lessp2(v_24433, v_24432);
    v_24432 = v_24432 ? lisp_true : nil;
    env = stack[-8];
    if (v_24432 == nil) goto v_24251;
    v_24432 = stack[-2];
    v_24432 = negate(v_24432);
    env = stack[-8];
    stack[-2] = v_24432;
    v_24432 = stack[-5];
    v_24432 = qcdr(v_24432);
    v_24432 = Lreverse(nil, v_24432);
    env = stack[-8];
    stack[-1] = v_24432;
    goto v_24137;
v_24251:
    v_24432 = stack[-5];
    v_24432 = qcdr(v_24432);
    stack[-1] = v_24432;
    goto v_24137;
v_24137:
    v_24432 = stack[0];
    if (v_24432 == nil) goto v_24272;
    v_24432 = stack[-1];
    v_24432 = qcar(v_24432);
    stack[-1] = v_24432;
    v_24432 = stack[-1];
    if (!consp(v_24432)) goto v_24278;
    else goto v_24279;
v_24278:
    goto v_24286;
v_24282:
    v_24433 = stack[-5];
    goto v_24283;
v_24284:
    v_24432 = stack[-4];
    v_24432 = qcar(v_24432);
    goto v_24285;
v_24286:
    goto v_24282;
v_24283:
    goto v_24284;
v_24285:
    fn = elt(env, 16); // parterr2
    v_24432 = (*qfn2(fn))(fn, v_24433, v_24432);
    env = stack[-8];
    v_24432 = lisp_true;
    stack[-6] = v_24432;
    goto v_24277;
v_24279:
    v_24432 = stack[-1];
    v_24432 = qcdr(v_24432);
    stack[-1] = v_24432;
    goto v_24277;
v_24277:
    goto v_24270;
v_24272:
v_24270:
    v_24432 = stack[-6];
    if (v_24432 == nil) goto v_24298;
    goto v_24296;
v_24298:
    goto v_24308;
v_24304:
    v_24432 = stack[-1];
    v_24433 = Llength(nil, v_24432);
    env = stack[-8];
    goto v_24305;
v_24306:
    v_24432 = stack[-2];
    goto v_24307;
v_24308:
    goto v_24304;
v_24305:
    goto v_24306;
v_24307:
    v_24432 = (LispObject)lessp2(v_24433, v_24432);
    v_24432 = v_24432 ? lisp_true : nil;
    env = stack[-8];
    if (v_24432 == nil) goto v_24302;
    goto v_24317;
v_24313:
    v_24433 = stack[-5];
    goto v_24314;
v_24315:
    v_24432 = stack[-4];
    v_24432 = qcar(v_24432);
    goto v_24316;
v_24317:
    goto v_24313;
v_24314:
    goto v_24315;
v_24316:
    fn = elt(env, 16); // parterr2
    v_24432 = (*qfn2(fn))(fn, v_24433, v_24432);
    env = stack[-8];
    v_24432 = lisp_true;
    stack[-6] = v_24432;
    goto v_24296;
v_24302:
    v_24432 = stack[0];
    if (v_24432 == nil) goto v_24323;
    goto v_24330;
v_24326:
    v_24433 = stack[-1];
    goto v_24327;
v_24328:
    v_24432 = stack[-2];
    goto v_24329;
v_24330:
    goto v_24326;
v_24327:
    goto v_24328;
v_24329:
    fn = elt(env, 18); // nth
    v_24432 = (*qfn2(fn))(fn, v_24433, v_24432);
    env = stack[-8];
    stack[-5] = v_24432;
    v_24432 = stack[-5];
    if (!consp(v_24432)) goto v_24340;
    goto v_24347;
v_24343:
    v_24433 = stack[-5];
    goto v_24344;
v_24345:
    v_24432 = elt(env, 8); // !*hold
    goto v_24346;
v_24347:
    goto v_24343;
v_24344:
    goto v_24345;
v_24346:
    v_24432 = Leqcar(nil, v_24433, v_24432);
    env = stack[-8];
    v_24432 = (v_24432 == nil ? lisp_true : nil);
    goto v_24338;
v_24340:
    v_24432 = nil;
    goto v_24338;
    v_24432 = nil;
v_24338:
    if (v_24432 == nil) goto v_24336;
    goto v_24359;
v_24355:
    v_24433 = elt(env, 8); // !*hold
    goto v_24356;
v_24357:
    v_24432 = stack[-5];
    goto v_24358;
v_24359:
    goto v_24355;
v_24356:
    goto v_24357;
v_24358:
    v_24432 = list2(v_24433, v_24432);
    env = stack[-8];
    stack[-5] = v_24432;
    goto v_24334;
v_24336:
v_24334:
    goto v_24296;
v_24323:
    goto v_24369;
v_24365:
    v_24433 = stack[-1];
    goto v_24366;
v_24367:
    v_24432 = stack[-2];
    goto v_24368;
v_24369:
    goto v_24365;
v_24366:
    goto v_24367;
v_24368:
    fn = elt(env, 18); // nth
    v_24432 = (*qfn2(fn))(fn, v_24433, v_24432);
    env = stack[-8];
    stack[0] = v_24432;
    goto v_24385;
v_24381:
    v_24432 = stack[0];
    fn = elt(env, 13); // getrtype
    v_24433 = (*qfn1(fn))(fn, v_24432);
    env = stack[-8];
    goto v_24382;
v_24383:
    v_24432 = elt(env, 5); // list
    goto v_24384;
v_24385:
    goto v_24381;
v_24382:
    goto v_24383;
v_24384:
    if (v_24433 == v_24432) goto v_24379;
    else goto v_24380;
v_24379:
    v_24432 = elt(env, 5); // list
    stack[-3] = v_24432;
    goto v_24378;
v_24380:
    v_24432 = nil;
    goto v_24378;
    v_24432 = nil;
v_24378:
    if (v_24432 == nil) goto v_24376;
    v_24432 = stack[0];
    fn = elt(env, 15); // listeval0
    v_24432 = (*qfn1(fn))(fn, v_24432);
    env = stack[-8];
    goto v_24374;
v_24376:
    goto v_24401;
v_24397:
    v_24433 = stack[-3];
    goto v_24398;
v_24399:
    v_24432 = elt(env, 5); // list
    goto v_24400;
v_24401:
    goto v_24397;
v_24398:
    goto v_24399;
v_24400:
    if (v_24433 == v_24432) goto v_24395;
    else goto v_24396;
v_24395:
    v_24432 = lisp_true;
    qvalue(elt(env, 3)) = v_24432; // !*intstr
    v_24432 = stack[0];
    fn = elt(env, 14); // reval
    v_24432 = (*qfn1(fn))(fn, v_24432);
    env = stack[-8];
    stack[0] = v_24432;
    v_24432 = nil;
    stack[-3] = v_24432;
    qvalue(elt(env, 3)) = v_24432; // !*intstr
    v_24432 = stack[0];
    goto v_24374;
v_24396:
    v_24432 = stack[0];
    goto v_24374;
    v_24432 = nil;
v_24374:
    stack[-5] = v_24432;
    goto v_24296;
v_24296:
    v_24432 = stack[-6];
    if (v_24432 == nil) goto v_24415;
    v_24432 = nil;
    goto v_24413;
v_24415:
    v_24432 = stack[-4];
    v_24432 = qcdr(v_24432);
    goto v_24413;
    v_24432 = nil;
v_24413:
    stack[-4] = v_24432;
v_24126:
    goto v_24115;
v_24114:
    v_24432 = stack[-6];
    if (v_24432 == nil) goto v_24425;
    v_24432 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24423;
v_24425:
    v_24432 = stack[-5];
    fn = elt(env, 14); // reval
    v_24432 = (*qfn1(fn))(fn, v_24432);
    goto v_24423;
    v_24432 = nil;
v_24423:
    ;}  // end of a binding scope
    goto v_24035;
    v_24432 = nil;
v_24035:
    return onevalue(v_24432);
}



// Code for equiv!-coeffs

static LispObject CC_equivKcoeffs(LispObject env,
                         LispObject v_24032, LispObject v_24033)
{
    env = qenv(env);
    LispObject v_24114, v_24115;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24033,v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24032,v_24033);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_24033;
    stack[-1] = v_24032;
// end of prologue
    stack[-2] = nil;
v_24038:
    v_24114 = stack[-1];
    if (v_24114 == nil) goto v_24041;
    else goto v_24042;
v_24041:
    goto v_24049;
v_24045:
    stack[-1] = stack[-2];
    goto v_24046;
v_24047:
    v_24114 = stack[0];
    v_24114 = Llength(nil, v_24114);
    env = stack[-3];
    fn = elt(env, 1); // nzeros
    v_24114 = (*qfn1(fn))(fn, v_24114);
    env = stack[-3];
    goto v_24048;
v_24049:
    goto v_24045;
v_24046:
    goto v_24047;
v_24048:
    {
        LispObject v_24119 = stack[-1];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_24119, v_24114);
    }
v_24042:
    v_24114 = stack[0];
    if (v_24114 == nil) goto v_24054;
    else goto v_24055;
v_24054:
    v_24114 = stack[-2];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_24114);
    }
v_24055:
    goto v_24065;
v_24061:
    v_24114 = stack[-1];
    v_24114 = qcar(v_24114);
    v_24115 = qcar(v_24114);
    goto v_24062;
v_24063:
    v_24114 = stack[0];
    v_24114 = qcar(v_24114);
    v_24114 = qcar(v_24114);
    goto v_24064;
v_24065:
    goto v_24061;
v_24062:
    goto v_24063;
v_24064:
    if (equal(v_24115, v_24114)) goto v_24059;
    else goto v_24060;
v_24059:
    goto v_24077;
v_24073:
    v_24114 = stack[-1];
    v_24114 = qcar(v_24114);
    v_24115 = qcdr(v_24114);
    goto v_24074;
v_24075:
    v_24114 = stack[-2];
    goto v_24076;
v_24077:
    goto v_24073;
v_24074:
    goto v_24075;
v_24076:
    v_24114 = cons(v_24115, v_24114);
    env = stack[-3];
    stack[-2] = v_24114;
    v_24114 = stack[-1];
    v_24114 = qcdr(v_24114);
    stack[-1] = v_24114;
    v_24114 = stack[0];
    v_24114 = qcdr(v_24114);
    stack[0] = v_24114;
    goto v_24038;
v_24060:
    goto v_24093;
v_24089:
    v_24114 = stack[-1];
    v_24114 = qcar(v_24114);
    v_24115 = qcar(v_24114);
    goto v_24090;
v_24091:
    v_24114 = stack[0];
    v_24114 = qcar(v_24114);
    v_24114 = qcar(v_24114);
    goto v_24092;
v_24093:
    goto v_24089;
v_24090:
    goto v_24091;
v_24092:
    fn = elt(env, 3); // mv!-pow!-!>
    v_24114 = (*qfn2(fn))(fn, v_24115, v_24114);
    env = stack[-3];
    if (v_24114 == nil) goto v_24087;
    v_24114 = stack[-1];
    v_24114 = qcdr(v_24114);
    stack[-1] = v_24114;
    goto v_24038;
v_24087:
    goto v_24109;
v_24105:
    v_24115 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24106;
v_24107:
    v_24114 = stack[-2];
    goto v_24108;
v_24109:
    goto v_24105;
v_24106:
    goto v_24107;
v_24108:
    v_24114 = cons(v_24115, v_24114);
    env = stack[-3];
    stack[-2] = v_24114;
    v_24114 = stack[0];
    v_24114 = qcdr(v_24114);
    stack[0] = v_24114;
    goto v_24038;
    v_24114 = nil;
    return onevalue(v_24114);
}



// Code for !*g2lex

static LispObject CC_Hg2lex(LispObject env,
                         LispObject v_24032)
{
    env = qenv(env);
    LispObject v_24074, v_24075;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24032);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_24074 = v_24032;
// end of prologue
    v_24075 = nil;
    stack[-1] = v_24074;
v_24041:
    v_24074 = stack[-1];
    if (v_24074 == nil) goto v_24045;
    else goto v_24046;
v_24045:
    goto v_24040;
v_24046:
    v_24074 = stack[-1];
    v_24074 = qcar(v_24074);
    goto v_24057;
v_24053:
    stack[0] = v_24075;
    goto v_24054;
v_24055:
    goto v_24065;
v_24061:
    v_24075 = v_24074;
    v_24075 = qcar(v_24075);
    v_24075 = qcdr(v_24075);
    goto v_24062;
v_24063:
    v_24074 = qcdr(v_24074);
    goto v_24064;
v_24065:
    goto v_24061;
v_24062:
    goto v_24063;
v_24064:
    v_24074 = cons(v_24075, v_24074);
    env = stack[-2];
    v_24074 = ncons(v_24074);
    env = stack[-2];
    goto v_24056;
v_24057:
    goto v_24053;
v_24054:
    goto v_24055;
v_24056:
    fn = elt(env, 2); // psum
    v_24074 = (*qfn2(fn))(fn, stack[0], v_24074);
    env = stack[-2];
    v_24075 = v_24074;
    v_24074 = stack[-1];
    v_24074 = qcdr(v_24074);
    stack[-1] = v_24074;
    goto v_24041;
v_24040:
    v_24074 = v_24075;
    return onevalue(v_24074);
}



// Code for isimp1

static LispObject CC_isimp1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24208, v_24209, v_24210, v_24211, v_24212;
    LispObject fn;
    LispObject v_24036, v_24035, v_24034, v_24033, v_24032;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "isimp1");
    va_start(aa, nargs);
    v_24032 = va_arg(aa, LispObject);
    v_24033 = va_arg(aa, LispObject);
    v_24034 = va_arg(aa, LispObject);
    v_24035 = va_arg(aa, LispObject);
    v_24036 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_24036,v_24035,v_24034,v_24033,v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_24032,v_24033,v_24034,v_24035,v_24036);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[0] = v_24036;
    stack[-1] = v_24035;
    stack[-2] = v_24034;
    stack[-3] = v_24033;
    stack[-4] = v_24032;
// end of prologue
    v_24208 = stack[-4];
    if (v_24208 == nil) goto v_24040;
    else goto v_24041;
v_24040:
    v_24208 = nil;
    goto v_24039;
v_24041:
    v_24208 = stack[-4];
    if (!consp(v_24208)) goto v_24048;
    else goto v_24049;
v_24048:
    v_24208 = lisp_true;
    goto v_24047;
v_24049:
    v_24208 = stack[-4];
    v_24208 = qcar(v_24208);
    v_24208 = (consp(v_24208) ? nil : lisp_true);
    goto v_24047;
    v_24208 = nil;
v_24047:
    if (v_24208 == nil) goto v_24045;
    v_24208 = stack[0];
    if (v_24208 == nil) goto v_24060;
    goto v_24067;
v_24063:
    goto v_24064;
v_24065:
    v_24208 = qvalue(elt(env, 1)); // !*cvit
    if (v_24208 == nil) goto v_24072;
    goto v_24083;
v_24075:
    v_24211 = stack[-3];
    goto v_24076;
v_24077:
    v_24210 = stack[-2];
    goto v_24078;
v_24079:
    v_24209 = stack[-1];
    goto v_24080;
v_24081:
    v_24208 = stack[0];
    goto v_24082;
v_24083:
    goto v_24075;
v_24076:
    goto v_24077;
v_24078:
    goto v_24079;
v_24080:
    goto v_24081;
v_24082:
    fn = elt(env, 2); // calc_spurx
    v_24208 = (*qfnn(fn))(fn, 4, v_24211, v_24210, v_24209, v_24208);
    env = stack[-6];
    goto v_24070;
v_24072:
    goto v_24101;
v_24091:
    v_24208 = stack[0];
    v_24212 = qcar(v_24208);
    goto v_24092;
v_24093:
    v_24211 = stack[-3];
    goto v_24094;
v_24095:
    v_24210 = stack[-2];
    goto v_24096;
v_24097:
    v_24209 = stack[-1];
    goto v_24098;
v_24099:
    v_24208 = stack[0];
    v_24208 = qcdr(v_24208);
    goto v_24100;
v_24101:
    goto v_24091;
v_24092:
    goto v_24093;
v_24094:
    goto v_24095;
v_24096:
    goto v_24097;
v_24098:
    goto v_24099;
v_24100:
    fn = elt(env, 3); // spur0
    v_24208 = (*qfnn(fn))(fn, 5, v_24212, v_24211, v_24210, v_24209, v_24208);
    env = stack[-6];
    goto v_24070;
    v_24208 = nil;
v_24070:
    goto v_24066;
v_24067:
    goto v_24063;
v_24064:
    goto v_24065;
v_24066:
    {
        LispObject v_24219 = stack[-4];
        fn = elt(env, 4); // multd
        return (*qfn2(fn))(fn, v_24219, v_24208);
    }
v_24060:
    v_24208 = stack[-2];
    if (v_24208 == nil) goto v_24110;
    goto v_24117;
v_24113:
    stack[0] = stack[-4];
    goto v_24114;
v_24115:
    goto v_24128;
v_24120:
    v_24211 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24121;
v_24122:
    v_24210 = stack[-3];
    goto v_24123;
v_24124:
    v_24209 = stack[-2];
    goto v_24125;
v_24126:
    v_24208 = stack[-1];
    goto v_24127;
v_24128:
    goto v_24120;
v_24121:
    goto v_24122;
v_24123:
    goto v_24124;
v_24125:
    goto v_24126;
v_24127:
    fn = elt(env, 5); // index_simp
    v_24208 = (*qfnn(fn))(fn, 4, v_24211, v_24210, v_24209, v_24208);
    env = stack[-6];
    goto v_24116;
v_24117:
    goto v_24113;
v_24114:
    goto v_24115;
v_24116:
    {
        LispObject v_24220 = stack[0];
        fn = elt(env, 4); // multd
        return (*qfn2(fn))(fn, v_24220, v_24208);
    }
v_24110:
    v_24208 = stack[-1];
    if (v_24208 == nil) goto v_24134;
    goto v_24141;
v_24137:
    v_24208 = stack[-1];
    fn = elt(env, 6); // emult
    stack[0] = (*qfn1(fn))(fn, v_24208);
    env = stack[-6];
    goto v_24138;
v_24139:
    goto v_24155;
v_24145:
    v_24212 = stack[-4];
    goto v_24146;
v_24147:
    v_24211 = stack[-3];
    goto v_24148;
v_24149:
    v_24210 = stack[-2];
    goto v_24150;
v_24151:
    v_24209 = nil;
    goto v_24152;
v_24153:
    v_24208 = nil;
    goto v_24154;
v_24155:
    goto v_24145;
v_24146:
    goto v_24147;
v_24148:
    goto v_24149;
v_24150:
    goto v_24151;
v_24152:
    goto v_24153;
v_24154:
    v_24208 = CC_isimp1(elt(env, 0), 5, v_24212, v_24211, v_24210, v_24209, v_24208);
    env = stack[-6];
    goto v_24140;
v_24141:
    goto v_24137;
v_24138:
    goto v_24139;
v_24140:
    {
        LispObject v_24221 = stack[0];
        fn = elt(env, 7); // multf
        return (*qfn2(fn))(fn, v_24221, v_24208);
    }
v_24134:
    v_24208 = stack[-4];
    goto v_24058;
    v_24208 = nil;
v_24058:
    goto v_24039;
v_24045:
    goto v_24171;
v_24167:
    goto v_24183;
v_24173:
    v_24208 = stack[-4];
    v_24212 = qcar(v_24208);
    goto v_24174;
v_24175:
    v_24211 = stack[-3];
    goto v_24176;
v_24177:
    v_24210 = stack[-2];
    goto v_24178;
v_24179:
    v_24209 = stack[-1];
    goto v_24180;
v_24181:
    v_24208 = stack[0];
    goto v_24182;
v_24183:
    goto v_24173;
v_24174:
    goto v_24175;
v_24176:
    goto v_24177;
v_24178:
    goto v_24179;
v_24180:
    goto v_24181;
v_24182:
    fn = elt(env, 8); // isimp2
    stack[-5] = (*qfnn(fn))(fn, 5, v_24212, v_24211, v_24210, v_24209, v_24208);
    env = stack[-6];
    goto v_24168;
v_24169:
    goto v_24201;
v_24191:
    v_24208 = stack[-4];
    v_24212 = qcdr(v_24208);
    goto v_24192;
v_24193:
    v_24211 = stack[-3];
    goto v_24194;
v_24195:
    v_24210 = stack[-2];
    goto v_24196;
v_24197:
    v_24209 = stack[-1];
    goto v_24198;
v_24199:
    v_24208 = stack[0];
    goto v_24200;
v_24201:
    goto v_24191;
v_24192:
    goto v_24193;
v_24194:
    goto v_24195;
v_24196:
    goto v_24197;
v_24198:
    goto v_24199;
v_24200:
    v_24208 = CC_isimp1(elt(env, 0), 5, v_24212, v_24211, v_24210, v_24209, v_24208);
    env = stack[-6];
    goto v_24170;
v_24171:
    goto v_24167;
v_24168:
    goto v_24169;
v_24170:
    {
        LispObject v_24222 = stack[-5];
        fn = elt(env, 9); // addf
        return (*qfn2(fn))(fn, v_24222, v_24208);
    }
    v_24208 = nil;
v_24039:
    return onevalue(v_24208);
}



// Code for rl_qe

static LispObject CC_rl_qe(LispObject env,
                         LispObject v_24032, LispObject v_24033)
{
    env = qenv(env);
    LispObject v_24050, v_24051;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24033,v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24032,v_24033);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_24050 = v_24033;
    v_24051 = v_24032;
// end of prologue
    goto v_24040;
v_24036:
    stack[0] = qvalue(elt(env, 1)); // rl_qe!*
    goto v_24037;
v_24038:
    goto v_24047;
v_24043:
    goto v_24044;
v_24045:
    goto v_24046;
v_24047:
    goto v_24043;
v_24044:
    goto v_24045;
v_24046:
    v_24050 = list2(v_24051, v_24050);
    env = stack[-1];
    goto v_24039;
v_24040:
    goto v_24036;
v_24037:
    goto v_24038;
v_24039:
    {
        LispObject v_24053 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_24053, v_24050);
    }
}



// Code for cl_nnf1

static LispObject CC_cl_nnf1(LispObject env,
                         LispObject v_24032, LispObject v_24033)
{
    env = qenv(env);
    LispObject v_24542, v_24543, v_24544;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24033,v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24032,v_24033);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_24033;
    stack[-2] = v_24032;
// end of prologue
v_24031:
    v_24542 = stack[-2];
    if (!consp(v_24542)) goto v_24041;
    else goto v_24042;
v_24041:
    v_24542 = stack[-2];
    goto v_24040;
v_24042:
    v_24542 = stack[-2];
    v_24542 = qcar(v_24542);
    goto v_24040;
    v_24542 = nil;
v_24040:
    v_24544 = v_24542;
    goto v_24057;
v_24053:
    v_24543 = v_24544;
    goto v_24054;
v_24055:
    v_24542 = elt(env, 2); // not
    goto v_24056;
v_24057:
    goto v_24053;
v_24054:
    goto v_24055;
v_24056:
    if (v_24543 == v_24542) goto v_24051;
    else goto v_24052;
v_24051:
    goto v_24065;
v_24061:
    v_24542 = stack[-2];
    v_24542 = qcdr(v_24542);
    v_24543 = qcar(v_24542);
    goto v_24062;
v_24063:
    v_24542 = stack[-4];
    v_24542 = (v_24542 == nil ? lisp_true : nil);
    goto v_24064;
v_24065:
    goto v_24061;
v_24062:
    goto v_24063;
v_24064:
    stack[-2] = v_24543;
    stack[-4] = v_24542;
    goto v_24031;
v_24052:
    goto v_24079;
v_24075:
    v_24543 = v_24544;
    goto v_24076;
v_24077:
    v_24542 = elt(env, 3); // impl
    goto v_24078;
v_24079:
    goto v_24075;
v_24076:
    goto v_24077;
v_24078:
    if (v_24543 == v_24542) goto v_24073;
    else goto v_24074;
v_24073:
    goto v_24089;
v_24083:
    goto v_24095;
v_24091:
    v_24543 = elt(env, 4); // or
    goto v_24092;
v_24093:
    v_24542 = stack[-4];
    goto v_24094;
v_24095:
    goto v_24091;
v_24092:
    goto v_24093;
v_24094:
    fn = elt(env, 14); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_24543, v_24542);
    env = stack[-6];
    goto v_24084;
v_24085:
    goto v_24103;
v_24099:
    v_24542 = stack[-2];
    v_24542 = qcdr(v_24542);
    v_24543 = qcar(v_24542);
    goto v_24100;
v_24101:
    v_24542 = stack[-4];
    v_24542 = (v_24542 == nil ? lisp_true : nil);
    goto v_24102;
v_24103:
    goto v_24099;
v_24100:
    goto v_24101;
v_24102:
    stack[0] = CC_cl_nnf1(elt(env, 0), v_24543, v_24542);
    env = stack[-6];
    goto v_24086;
v_24087:
    goto v_24115;
v_24111:
    v_24542 = stack[-2];
    v_24542 = qcdr(v_24542);
    v_24542 = qcdr(v_24542);
    v_24543 = qcar(v_24542);
    goto v_24112;
v_24113:
    v_24542 = stack[-4];
    goto v_24114;
v_24115:
    goto v_24111;
v_24112:
    goto v_24113;
v_24114:
    v_24542 = CC_cl_nnf1(elt(env, 0), v_24543, v_24542);
    env = stack[-6];
    v_24542 = ncons(v_24542);
    goto v_24088;
v_24089:
    goto v_24083;
v_24084:
    goto v_24085;
v_24086:
    goto v_24087;
v_24088:
    {
        LispObject v_24551 = stack[-1];
        LispObject v_24552 = stack[0];
        return list2star(v_24551, v_24552, v_24542);
    }
v_24074:
    goto v_24129;
v_24125:
    v_24543 = v_24544;
    goto v_24126;
v_24127:
    v_24542 = elt(env, 5); // repl
    goto v_24128;
v_24129:
    goto v_24125;
v_24126:
    goto v_24127;
v_24128:
    if (v_24543 == v_24542) goto v_24123;
    else goto v_24124;
v_24123:
    goto v_24139;
v_24133:
    goto v_24145;
v_24141:
    v_24543 = elt(env, 4); // or
    goto v_24142;
v_24143:
    v_24542 = stack[-4];
    goto v_24144;
v_24145:
    goto v_24141;
v_24142:
    goto v_24143;
v_24144:
    fn = elt(env, 14); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_24543, v_24542);
    env = stack[-6];
    goto v_24134;
v_24135:
    goto v_24153;
v_24149:
    v_24542 = stack[-2];
    v_24542 = qcdr(v_24542);
    v_24543 = qcar(v_24542);
    goto v_24150;
v_24151:
    v_24542 = stack[-4];
    goto v_24152;
v_24153:
    goto v_24149;
v_24150:
    goto v_24151;
v_24152:
    stack[0] = CC_cl_nnf1(elt(env, 0), v_24543, v_24542);
    env = stack[-6];
    goto v_24136;
v_24137:
    goto v_24164;
v_24160:
    v_24542 = stack[-2];
    v_24542 = qcdr(v_24542);
    v_24542 = qcdr(v_24542);
    v_24543 = qcar(v_24542);
    goto v_24161;
v_24162:
    v_24542 = stack[-4];
    v_24542 = (v_24542 == nil ? lisp_true : nil);
    goto v_24163;
v_24164:
    goto v_24160;
v_24161:
    goto v_24162;
v_24163:
    v_24542 = CC_cl_nnf1(elt(env, 0), v_24543, v_24542);
    env = stack[-6];
    v_24542 = ncons(v_24542);
    goto v_24138;
v_24139:
    goto v_24133;
v_24134:
    goto v_24135;
v_24136:
    goto v_24137;
v_24138:
    {
        LispObject v_24553 = stack[-1];
        LispObject v_24554 = stack[0];
        return list2star(v_24553, v_24554, v_24542);
    }
v_24124:
    goto v_24179;
v_24175:
    v_24543 = v_24544;
    goto v_24176;
v_24177:
    v_24542 = elt(env, 6); // equiv
    goto v_24178;
v_24179:
    goto v_24175;
v_24176:
    goto v_24177;
v_24178:
    if (v_24543 == v_24542) goto v_24173;
    else goto v_24174;
v_24173:
    goto v_24189;
v_24183:
    goto v_24195;
v_24191:
    v_24543 = elt(env, 4); // or
    goto v_24192;
v_24193:
    v_24542 = stack[-4];
    goto v_24194;
v_24195:
    goto v_24191;
v_24192:
    goto v_24193;
v_24194:
    fn = elt(env, 14); // cl_cflip
    stack[-5] = (*qfn2(fn))(fn, v_24543, v_24542);
    env = stack[-6];
    goto v_24184;
v_24185:
    goto v_24205;
v_24199:
    goto v_24211;
v_24207:
    v_24543 = elt(env, 7); // and
    goto v_24208;
v_24209:
    v_24542 = stack[-4];
    goto v_24210;
v_24211:
    goto v_24207;
v_24208:
    goto v_24209;
v_24210:
    fn = elt(env, 14); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_24543, v_24542);
    env = stack[-6];
    goto v_24200;
v_24201:
    goto v_24219;
v_24215:
    v_24542 = stack[-2];
    v_24542 = qcdr(v_24542);
    v_24543 = qcar(v_24542);
    goto v_24216;
v_24217:
    v_24542 = stack[-4];
    goto v_24218;
v_24219:
    goto v_24215;
v_24216:
    goto v_24217;
v_24218:
    stack[0] = CC_cl_nnf1(elt(env, 0), v_24543, v_24542);
    env = stack[-6];
    goto v_24202;
v_24203:
    goto v_24230;
v_24226:
    v_24542 = stack[-2];
    v_24542 = qcdr(v_24542);
    v_24542 = qcdr(v_24542);
    v_24543 = qcar(v_24542);
    goto v_24227;
v_24228:
    v_24542 = stack[-4];
    goto v_24229;
v_24230:
    goto v_24226;
v_24227:
    goto v_24228;
v_24229:
    v_24542 = CC_cl_nnf1(elt(env, 0), v_24543, v_24542);
    env = stack[-6];
    v_24542 = ncons(v_24542);
    env = stack[-6];
    goto v_24204;
v_24205:
    goto v_24199;
v_24200:
    goto v_24201;
v_24202:
    goto v_24203;
v_24204:
    stack[-3] = list2star(stack[-1], stack[0], v_24542);
    env = stack[-6];
    goto v_24186;
v_24187:
    goto v_24244;
v_24238:
    goto v_24250;
v_24246:
    v_24543 = elt(env, 7); // and
    goto v_24247;
v_24248:
    v_24542 = stack[-4];
    goto v_24249;
v_24250:
    goto v_24246;
v_24247:
    goto v_24248;
v_24249:
    fn = elt(env, 14); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_24543, v_24542);
    env = stack[-6];
    goto v_24239;
v_24240:
    goto v_24258;
v_24254:
    v_24542 = stack[-2];
    v_24542 = qcdr(v_24542);
    v_24543 = qcar(v_24542);
    goto v_24255;
v_24256:
    v_24542 = stack[-4];
    v_24542 = (v_24542 == nil ? lisp_true : nil);
    goto v_24257;
v_24258:
    goto v_24254;
v_24255:
    goto v_24256;
v_24257:
    stack[0] = CC_cl_nnf1(elt(env, 0), v_24543, v_24542);
    env = stack[-6];
    goto v_24241;
v_24242:
    goto v_24270;
v_24266:
    v_24542 = stack[-2];
    v_24542 = qcdr(v_24542);
    v_24542 = qcdr(v_24542);
    v_24543 = qcar(v_24542);
    goto v_24267;
v_24268:
    v_24542 = stack[-4];
    v_24542 = (v_24542 == nil ? lisp_true : nil);
    goto v_24269;
v_24270:
    goto v_24266;
v_24267:
    goto v_24268;
v_24269:
    v_24542 = CC_cl_nnf1(elt(env, 0), v_24543, v_24542);
    env = stack[-6];
    v_24542 = ncons(v_24542);
    env = stack[-6];
    goto v_24243;
v_24244:
    goto v_24238;
v_24239:
    goto v_24240;
v_24241:
    goto v_24242;
v_24243:
    v_24542 = list2star(stack[-1], stack[0], v_24542);
    env = stack[-6];
    v_24542 = ncons(v_24542);
    goto v_24188;
v_24189:
    goto v_24183;
v_24184:
    goto v_24185;
v_24186:
    goto v_24187;
v_24188:
    {
        LispObject v_24555 = stack[-5];
        LispObject v_24556 = stack[-3];
        return list2star(v_24555, v_24556, v_24542);
    }
v_24174:
    goto v_24289;
v_24285:
    v_24543 = v_24544;
    goto v_24286;
v_24287:
    v_24542 = elt(env, 8); // true
    goto v_24288;
v_24289:
    goto v_24285;
v_24286:
    goto v_24287;
v_24288:
    if (v_24543 == v_24542) goto v_24283;
    else goto v_24284;
v_24283:
    v_24542 = lisp_true;
    goto v_24282;
v_24284:
    goto v_24299;
v_24295:
    v_24543 = v_24544;
    goto v_24296;
v_24297:
    v_24542 = elt(env, 9); // false
    goto v_24298;
v_24299:
    goto v_24295;
v_24296:
    goto v_24297;
v_24298:
    v_24542 = (v_24543 == v_24542 ? lisp_true : nil);
    goto v_24282;
    v_24542 = nil;
v_24282:
    if (v_24542 == nil) goto v_24280;
    goto v_24308;
v_24304:
    v_24543 = stack[-2];
    goto v_24305;
v_24306:
    v_24542 = stack[-4];
    goto v_24307;
v_24308:
    goto v_24304;
v_24305:
    goto v_24306;
v_24307:
    {
        fn = elt(env, 14); // cl_cflip
        return (*qfn2(fn))(fn, v_24543, v_24542);
    }
v_24280:
    goto v_24323;
v_24319:
    v_24543 = v_24544;
    goto v_24320;
v_24321:
    v_24542 = elt(env, 10); // ex
    goto v_24322;
v_24323:
    goto v_24319;
v_24320:
    goto v_24321;
v_24322:
    if (v_24543 == v_24542) goto v_24317;
    else goto v_24318;
v_24317:
    v_24542 = lisp_true;
    goto v_24316;
v_24318:
    goto v_24333;
v_24329:
    v_24543 = v_24544;
    goto v_24330;
v_24331:
    v_24542 = elt(env, 11); // all
    goto v_24332;
v_24333:
    goto v_24329;
v_24330:
    goto v_24331;
v_24332:
    v_24542 = (v_24543 == v_24542 ? lisp_true : nil);
    goto v_24316;
    v_24542 = nil;
v_24316:
    if (v_24542 == nil) goto v_24314;
    goto v_24344;
v_24338:
    goto v_24350;
v_24346:
    v_24543 = v_24544;
    goto v_24347;
v_24348:
    v_24542 = stack[-4];
    goto v_24349;
v_24350:
    goto v_24346;
v_24347:
    goto v_24348;
v_24349:
    fn = elt(env, 14); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_24543, v_24542);
    env = stack[-6];
    goto v_24339;
v_24340:
    v_24542 = stack[-2];
    v_24542 = qcdr(v_24542);
    stack[0] = qcar(v_24542);
    goto v_24341;
v_24342:
    goto v_24361;
v_24357:
    v_24542 = stack[-2];
    v_24542 = qcdr(v_24542);
    v_24542 = qcdr(v_24542);
    v_24543 = qcar(v_24542);
    goto v_24358;
v_24359:
    v_24542 = stack[-4];
    goto v_24360;
v_24361:
    goto v_24357;
v_24358:
    goto v_24359;
v_24360:
    v_24542 = CC_cl_nnf1(elt(env, 0), v_24543, v_24542);
    goto v_24343;
v_24344:
    goto v_24338;
v_24339:
    goto v_24340;
v_24341:
    goto v_24342;
v_24343:
    {
        LispObject v_24557 = stack[-1];
        LispObject v_24558 = stack[0];
        return list3(v_24557, v_24558, v_24542);
    }
v_24314:
    goto v_24379;
v_24375:
    v_24543 = v_24544;
    goto v_24376;
v_24377:
    v_24542 = elt(env, 12); // bex
    goto v_24378;
v_24379:
    goto v_24375;
v_24376:
    goto v_24377;
v_24378:
    if (v_24543 == v_24542) goto v_24373;
    else goto v_24374;
v_24373:
    v_24542 = lisp_true;
    goto v_24372;
v_24374:
    goto v_24389;
v_24385:
    v_24543 = v_24544;
    goto v_24386;
v_24387:
    v_24542 = elt(env, 13); // ball
    goto v_24388;
v_24389:
    goto v_24385;
v_24386:
    goto v_24387;
v_24388:
    v_24542 = (v_24543 == v_24542 ? lisp_true : nil);
    goto v_24372;
    v_24542 = nil;
v_24372:
    if (v_24542 == nil) goto v_24370;
    goto v_24402;
v_24394:
    goto v_24408;
v_24404:
    v_24543 = v_24544;
    goto v_24405;
v_24406:
    v_24542 = stack[-4];
    goto v_24407;
v_24408:
    goto v_24404;
v_24405:
    goto v_24406;
v_24407:
    fn = elt(env, 14); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_24543, v_24542);
    env = stack[-6];
    goto v_24395;
v_24396:
    v_24542 = stack[-2];
    v_24542 = qcdr(v_24542);
    stack[0] = qcar(v_24542);
    goto v_24397;
v_24398:
    goto v_24419;
v_24415:
    v_24542 = stack[-2];
    v_24542 = qcdr(v_24542);
    v_24542 = qcdr(v_24542);
    v_24543 = qcar(v_24542);
    goto v_24416;
v_24417:
    v_24542 = stack[-4];
    goto v_24418;
v_24419:
    goto v_24415;
v_24416:
    goto v_24417;
v_24418:
    stack[-3] = CC_cl_nnf1(elt(env, 0), v_24543, v_24542);
    env = stack[-6];
    goto v_24399;
v_24400:
    goto v_24430;
v_24426:
    v_24542 = stack[-2];
    v_24542 = qcdr(v_24542);
    v_24542 = qcdr(v_24542);
    v_24542 = qcdr(v_24542);
    v_24543 = qcar(v_24542);
    goto v_24427;
v_24428:
    v_24542 = lisp_true;
    goto v_24429;
v_24430:
    goto v_24426;
v_24427:
    goto v_24428;
v_24429:
    v_24542 = CC_cl_nnf1(elt(env, 0), v_24543, v_24542);
    goto v_24401;
v_24402:
    goto v_24394;
v_24395:
    goto v_24396;
v_24397:
    goto v_24398;
v_24399:
    goto v_24400;
v_24401:
    {
        LispObject v_24559 = stack[-1];
        LispObject v_24560 = stack[0];
        LispObject v_24561 = stack[-3];
        return list4(v_24559, v_24560, v_24561, v_24542);
    }
v_24370:
    goto v_24449;
v_24445:
    v_24543 = v_24544;
    goto v_24446;
v_24447:
    v_24542 = elt(env, 4); // or
    goto v_24448;
v_24449:
    goto v_24445;
v_24446:
    goto v_24447;
v_24448:
    if (v_24543 == v_24542) goto v_24443;
    else goto v_24444;
v_24443:
    v_24542 = lisp_true;
    goto v_24442;
v_24444:
    goto v_24459;
v_24455:
    v_24543 = v_24544;
    goto v_24456;
v_24457:
    v_24542 = elt(env, 7); // and
    goto v_24458;
v_24459:
    goto v_24455;
v_24456:
    goto v_24457;
v_24458:
    v_24542 = (v_24543 == v_24542 ? lisp_true : nil);
    goto v_24442;
    v_24542 = nil;
v_24442:
    if (v_24542 == nil) goto v_24440;
    goto v_24468;
v_24464:
    goto v_24474;
v_24470:
    v_24543 = v_24544;
    goto v_24471;
v_24472:
    v_24542 = stack[-4];
    goto v_24473;
v_24474:
    goto v_24470;
v_24471:
    goto v_24472;
v_24473:
    fn = elt(env, 14); // cl_cflip
    stack[-5] = (*qfn2(fn))(fn, v_24543, v_24542);
    env = stack[-6];
    goto v_24465;
v_24466:
    v_24542 = stack[-2];
    v_24542 = qcdr(v_24542);
    stack[-3] = v_24542;
    v_24542 = stack[-3];
    if (v_24542 == nil) goto v_24487;
    else goto v_24488;
v_24487:
    v_24542 = nil;
    goto v_24481;
v_24488:
    v_24542 = stack[-3];
    v_24542 = qcar(v_24542);
    goto v_24500;
v_24496:
    v_24543 = v_24542;
    goto v_24497;
v_24498:
    v_24542 = stack[-4];
    goto v_24499;
v_24500:
    goto v_24496;
v_24497:
    goto v_24498;
v_24499:
    v_24542 = CC_cl_nnf1(elt(env, 0), v_24543, v_24542);
    env = stack[-6];
    v_24542 = ncons(v_24542);
    env = stack[-6];
    stack[-1] = v_24542;
    stack[-2] = v_24542;
v_24482:
    v_24542 = stack[-3];
    v_24542 = qcdr(v_24542);
    stack[-3] = v_24542;
    v_24542 = stack[-3];
    if (v_24542 == nil) goto v_24507;
    else goto v_24508;
v_24507:
    v_24542 = stack[-2];
    goto v_24481;
v_24508:
    goto v_24516;
v_24512:
    stack[0] = stack[-1];
    goto v_24513;
v_24514:
    v_24542 = stack[-3];
    v_24542 = qcar(v_24542);
    goto v_24527;
v_24523:
    v_24543 = v_24542;
    goto v_24524;
v_24525:
    v_24542 = stack[-4];
    goto v_24526;
v_24527:
    goto v_24523;
v_24524:
    goto v_24525;
v_24526:
    v_24542 = CC_cl_nnf1(elt(env, 0), v_24543, v_24542);
    env = stack[-6];
    v_24542 = ncons(v_24542);
    env = stack[-6];
    goto v_24515;
v_24516:
    goto v_24512;
v_24513:
    goto v_24514;
v_24515:
    v_24542 = Lrplacd(nil, stack[0], v_24542);
    env = stack[-6];
    v_24542 = stack[-1];
    v_24542 = qcdr(v_24542);
    stack[-1] = v_24542;
    goto v_24482;
v_24481:
    goto v_24467;
v_24468:
    goto v_24464;
v_24465:
    goto v_24466;
v_24467:
    {
        LispObject v_24562 = stack[-5];
        return cons(v_24562, v_24542);
    }
v_24440:
    v_24542 = stack[-4];
    if (v_24542 == nil) goto v_24535;
    v_24542 = stack[-2];
    goto v_24533;
v_24535:
    v_24542 = stack[-2];
    {
        fn = elt(env, 15); // rl_negateat
        return (*qfn1(fn))(fn, v_24542);
    }
    v_24542 = nil;
v_24533:
    return onevalue(v_24542);
}



// Code for pasf_or

static LispObject CC_pasf_or(LispObject env,
                         LispObject v_24032)
{
    env = qenv(env);
    LispObject v_24474, v_24475;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24032);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24032);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24032;
// end of prologue
    goto v_24054;
v_24050:
    v_24475 = stack[0];
    goto v_24051;
v_24052:
    v_24474 = elt(env, 2); // true
    goto v_24053;
v_24054:
    goto v_24050;
v_24051:
    goto v_24052;
v_24053:
    if (v_24475 == v_24474) goto v_24048;
    else goto v_24049;
v_24048:
    v_24474 = lisp_true;
    goto v_24047;
v_24049:
    goto v_24064;
v_24060:
    v_24475 = stack[0];
    goto v_24061;
v_24062:
    v_24474 = elt(env, 3); // false
    goto v_24063;
v_24064:
    goto v_24060;
v_24061:
    goto v_24062;
v_24063:
    v_24474 = (v_24475 == v_24474 ? lisp_true : nil);
    goto v_24047;
    v_24474 = nil;
v_24047:
    if (v_24474 == nil) goto v_24045;
    v_24474 = lisp_true;
    goto v_24043;
v_24045:
    goto v_24075;
v_24071:
    goto v_24088;
v_24084:
    v_24475 = stack[0];
    goto v_24085;
v_24086:
    v_24474 = elt(env, 2); // true
    goto v_24087;
v_24088:
    goto v_24084;
v_24085:
    goto v_24086;
v_24087:
    if (v_24475 == v_24474) goto v_24082;
    else goto v_24083;
v_24082:
    v_24474 = lisp_true;
    goto v_24081;
v_24083:
    goto v_24098;
v_24094:
    v_24475 = stack[0];
    goto v_24095;
v_24096:
    v_24474 = elt(env, 3); // false
    goto v_24097;
v_24098:
    goto v_24094;
v_24095:
    goto v_24096;
v_24097:
    v_24474 = (v_24475 == v_24474 ? lisp_true : nil);
    goto v_24081;
    v_24474 = nil;
v_24081:
    if (v_24474 == nil) goto v_24079;
    v_24474 = stack[0];
    v_24475 = v_24474;
    goto v_24077;
v_24079:
    v_24474 = stack[0];
    v_24474 = qcar(v_24474);
    v_24474 = Lconsp(nil, v_24474);
    env = stack[-2];
    if (v_24474 == nil) goto v_24104;
    v_24474 = stack[0];
    v_24474 = qcar(v_24474);
    v_24474 = qcar(v_24474);
    v_24475 = v_24474;
    goto v_24077;
v_24104:
    v_24474 = stack[0];
    v_24474 = qcar(v_24474);
    v_24475 = v_24474;
    goto v_24077;
    v_24475 = nil;
v_24077:
    goto v_24072;
v_24073:
    v_24474 = elt(env, 4); // (lessp greaterp leq geq)
    goto v_24074;
v_24075:
    goto v_24071;
v_24072:
    goto v_24073;
v_24074:
    v_24474 = Lmemq(nil, v_24475, v_24474);
    v_24474 = (v_24474 == nil ? lisp_true : nil);
    goto v_24043;
    v_24474 = nil;
v_24043:
    if (v_24474 == nil) goto v_24041;
    v_24474 = stack[0];
    goto v_24036;
v_24041:
    v_24474 = stack[0];
    v_24474 = qcdr(v_24474);
    v_24474 = qcar(v_24474);
    fn = elt(env, 9); // pasf_deci
    v_24474 = (*qfn1(fn))(fn, v_24474);
    env = stack[-2];
    stack[-1] = v_24474;
    goto v_24135;
v_24131:
    goto v_24148;
v_24144:
    v_24475 = stack[0];
    goto v_24145;
v_24146:
    v_24474 = elt(env, 2); // true
    goto v_24147;
v_24148:
    goto v_24144;
v_24145:
    goto v_24146;
v_24147:
    if (v_24475 == v_24474) goto v_24142;
    else goto v_24143;
v_24142:
    v_24474 = lisp_true;
    goto v_24141;
v_24143:
    goto v_24158;
v_24154:
    v_24475 = stack[0];
    goto v_24155;
v_24156:
    v_24474 = elt(env, 3); // false
    goto v_24157;
v_24158:
    goto v_24154;
v_24155:
    goto v_24156;
v_24157:
    v_24474 = (v_24475 == v_24474 ? lisp_true : nil);
    goto v_24141;
    v_24474 = nil;
v_24141:
    if (v_24474 == nil) goto v_24139;
    v_24474 = stack[0];
    v_24475 = v_24474;
    goto v_24137;
v_24139:
    v_24474 = stack[0];
    v_24474 = qcar(v_24474);
    v_24474 = Lconsp(nil, v_24474);
    env = stack[-2];
    if (v_24474 == nil) goto v_24164;
    v_24474 = stack[0];
    v_24474 = qcar(v_24474);
    v_24474 = qcar(v_24474);
    v_24475 = v_24474;
    goto v_24137;
v_24164:
    v_24474 = stack[0];
    v_24474 = qcar(v_24474);
    v_24475 = v_24474;
    goto v_24137;
    v_24475 = nil;
v_24137:
    goto v_24132;
v_24133:
    v_24474 = elt(env, 5); // lessp
    goto v_24134;
v_24135:
    goto v_24131;
v_24132:
    goto v_24133;
v_24134:
    if (v_24475 == v_24474) goto v_24129;
    else goto v_24130;
v_24129:
    goto v_24181;
v_24177:
    v_24474 = stack[-1];
    v_24475 = qcdr(v_24474);
    goto v_24178;
v_24179:
    v_24474 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24180;
v_24181:
    goto v_24177;
v_24178:
    goto v_24179;
v_24180:
    v_24474 = (LispObject)lessp2(v_24475, v_24474);
    v_24474 = v_24474 ? lisp_true : nil;
    env = stack[-2];
    goto v_24128;
v_24130:
    v_24474 = nil;
    goto v_24128;
    v_24474 = nil;
v_24128:
    if (v_24474 == nil) goto v_24126;
    goto v_24195;
v_24189:
    stack[-1] = elt(env, 6); // leq
    goto v_24190;
v_24191:
    goto v_24202;
v_24198:
    v_24474 = stack[0];
    v_24474 = qcdr(v_24474);
    stack[0] = qcar(v_24474);
    goto v_24199;
v_24200:
    v_24474 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 10); // simp
    v_24474 = (*qfn1(fn))(fn, v_24474);
    env = stack[-2];
    v_24474 = qcar(v_24474);
    goto v_24201;
v_24202:
    goto v_24198;
v_24199:
    goto v_24200;
v_24201:
    fn = elt(env, 11); // addf
    v_24475 = (*qfn2(fn))(fn, stack[0], v_24474);
    goto v_24192;
v_24193:
    v_24474 = nil;
    goto v_24194;
v_24195:
    goto v_24189;
v_24190:
    goto v_24191;
v_24192:
    goto v_24193;
v_24194:
    {
        LispObject v_24478 = stack[-1];
        return list3(v_24478, v_24475, v_24474);
    }
v_24126:
    goto v_24222;
v_24218:
    goto v_24235;
v_24231:
    v_24475 = stack[0];
    goto v_24232;
v_24233:
    v_24474 = elt(env, 2); // true
    goto v_24234;
v_24235:
    goto v_24231;
v_24232:
    goto v_24233;
v_24234:
    if (v_24475 == v_24474) goto v_24229;
    else goto v_24230;
v_24229:
    v_24474 = lisp_true;
    goto v_24228;
v_24230:
    goto v_24245;
v_24241:
    v_24475 = stack[0];
    goto v_24242;
v_24243:
    v_24474 = elt(env, 3); // false
    goto v_24244;
v_24245:
    goto v_24241;
v_24242:
    goto v_24243;
v_24244:
    v_24474 = (v_24475 == v_24474 ? lisp_true : nil);
    goto v_24228;
    v_24474 = nil;
v_24228:
    if (v_24474 == nil) goto v_24226;
    v_24474 = stack[0];
    v_24475 = v_24474;
    goto v_24224;
v_24226:
    v_24474 = stack[0];
    v_24474 = qcar(v_24474);
    v_24474 = Lconsp(nil, v_24474);
    env = stack[-2];
    if (v_24474 == nil) goto v_24251;
    v_24474 = stack[0];
    v_24474 = qcar(v_24474);
    v_24474 = qcar(v_24474);
    v_24475 = v_24474;
    goto v_24224;
v_24251:
    v_24474 = stack[0];
    v_24474 = qcar(v_24474);
    v_24475 = v_24474;
    goto v_24224;
    v_24475 = nil;
v_24224:
    goto v_24219;
v_24220:
    v_24474 = elt(env, 6); // leq
    goto v_24221;
v_24222:
    goto v_24218;
v_24219:
    goto v_24220;
v_24221:
    if (v_24475 == v_24474) goto v_24216;
    else goto v_24217;
v_24216:
    goto v_24268;
v_24264:
    v_24474 = stack[-1];
    v_24475 = qcdr(v_24474);
    goto v_24265;
v_24266:
    v_24474 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24267;
v_24268:
    goto v_24264;
v_24265:
    goto v_24266;
v_24267:
    v_24474 = (LispObject)greaterp2(v_24475, v_24474);
    v_24474 = v_24474 ? lisp_true : nil;
    env = stack[-2];
    goto v_24215;
v_24217:
    v_24474 = nil;
    goto v_24215;
    v_24474 = nil;
v_24215:
    if (v_24474 == nil) goto v_24213;
    goto v_24282;
v_24276:
    stack[-1] = elt(env, 5); // lessp
    goto v_24277;
v_24278:
    goto v_24289;
v_24285:
    v_24474 = stack[0];
    v_24474 = qcdr(v_24474);
    stack[0] = qcar(v_24474);
    goto v_24286;
v_24287:
    v_24474 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 10); // simp
    v_24474 = (*qfn1(fn))(fn, v_24474);
    env = stack[-2];
    v_24474 = qcar(v_24474);
    fn = elt(env, 12); // negf
    v_24474 = (*qfn1(fn))(fn, v_24474);
    env = stack[-2];
    goto v_24288;
v_24289:
    goto v_24285;
v_24286:
    goto v_24287;
v_24288:
    fn = elt(env, 11); // addf
    v_24475 = (*qfn2(fn))(fn, stack[0], v_24474);
    goto v_24279;
v_24280:
    v_24474 = nil;
    goto v_24281;
v_24282:
    goto v_24276;
v_24277:
    goto v_24278;
v_24279:
    goto v_24280;
v_24281:
    {
        LispObject v_24479 = stack[-1];
        return list3(v_24479, v_24475, v_24474);
    }
v_24213:
    goto v_24310;
v_24306:
    goto v_24323;
v_24319:
    v_24475 = stack[0];
    goto v_24320;
v_24321:
    v_24474 = elt(env, 2); // true
    goto v_24322;
v_24323:
    goto v_24319;
v_24320:
    goto v_24321;
v_24322:
    if (v_24475 == v_24474) goto v_24317;
    else goto v_24318;
v_24317:
    v_24474 = lisp_true;
    goto v_24316;
v_24318:
    goto v_24333;
v_24329:
    v_24475 = stack[0];
    goto v_24330;
v_24331:
    v_24474 = elt(env, 3); // false
    goto v_24332;
v_24333:
    goto v_24329;
v_24330:
    goto v_24331;
v_24332:
    v_24474 = (v_24475 == v_24474 ? lisp_true : nil);
    goto v_24316;
    v_24474 = nil;
v_24316:
    if (v_24474 == nil) goto v_24314;
    v_24474 = stack[0];
    v_24475 = v_24474;
    goto v_24312;
v_24314:
    v_24474 = stack[0];
    v_24474 = qcar(v_24474);
    v_24474 = Lconsp(nil, v_24474);
    env = stack[-2];
    if (v_24474 == nil) goto v_24339;
    v_24474 = stack[0];
    v_24474 = qcar(v_24474);
    v_24474 = qcar(v_24474);
    v_24475 = v_24474;
    goto v_24312;
v_24339:
    v_24474 = stack[0];
    v_24474 = qcar(v_24474);
    v_24475 = v_24474;
    goto v_24312;
    v_24475 = nil;
v_24312:
    goto v_24307;
v_24308:
    v_24474 = elt(env, 7); // greaterp
    goto v_24309;
v_24310:
    goto v_24306;
v_24307:
    goto v_24308;
v_24309:
    if (v_24475 == v_24474) goto v_24304;
    else goto v_24305;
v_24304:
    goto v_24356;
v_24352:
    v_24474 = stack[-1];
    v_24475 = qcdr(v_24474);
    goto v_24353;
v_24354:
    v_24474 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24355;
v_24356:
    goto v_24352;
v_24353:
    goto v_24354;
v_24355:
    v_24474 = (LispObject)greaterp2(v_24475, v_24474);
    v_24474 = v_24474 ? lisp_true : nil;
    env = stack[-2];
    goto v_24303;
v_24305:
    v_24474 = nil;
    goto v_24303;
    v_24474 = nil;
v_24303:
    if (v_24474 == nil) goto v_24301;
    goto v_24370;
v_24364:
    stack[-1] = elt(env, 8); // geq
    goto v_24365;
v_24366:
    goto v_24377;
v_24373:
    v_24474 = stack[0];
    v_24474 = qcdr(v_24474);
    stack[0] = qcar(v_24474);
    goto v_24374;
v_24375:
    v_24474 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 10); // simp
    v_24474 = (*qfn1(fn))(fn, v_24474);
    env = stack[-2];
    v_24474 = qcar(v_24474);
    fn = elt(env, 12); // negf
    v_24474 = (*qfn1(fn))(fn, v_24474);
    env = stack[-2];
    goto v_24376;
v_24377:
    goto v_24373;
v_24374:
    goto v_24375;
v_24376:
    fn = elt(env, 11); // addf
    v_24475 = (*qfn2(fn))(fn, stack[0], v_24474);
    goto v_24367;
v_24368:
    v_24474 = nil;
    goto v_24369;
v_24370:
    goto v_24364;
v_24365:
    goto v_24366;
v_24367:
    goto v_24368;
v_24369:
    {
        LispObject v_24480 = stack[-1];
        return list3(v_24480, v_24475, v_24474);
    }
v_24301:
    goto v_24398;
v_24394:
    goto v_24411;
v_24407:
    v_24475 = stack[0];
    goto v_24408;
v_24409:
    v_24474 = elt(env, 2); // true
    goto v_24410;
v_24411:
    goto v_24407;
v_24408:
    goto v_24409;
v_24410:
    if (v_24475 == v_24474) goto v_24405;
    else goto v_24406;
v_24405:
    v_24474 = lisp_true;
    goto v_24404;
v_24406:
    goto v_24421;
v_24417:
    v_24475 = stack[0];
    goto v_24418;
v_24419:
    v_24474 = elt(env, 3); // false
    goto v_24420;
v_24421:
    goto v_24417;
v_24418:
    goto v_24419;
v_24420:
    v_24474 = (v_24475 == v_24474 ? lisp_true : nil);
    goto v_24404;
    v_24474 = nil;
v_24404:
    if (v_24474 == nil) goto v_24402;
    v_24474 = stack[0];
    v_24475 = v_24474;
    goto v_24400;
v_24402:
    v_24474 = stack[0];
    v_24474 = qcar(v_24474);
    v_24474 = Lconsp(nil, v_24474);
    env = stack[-2];
    if (v_24474 == nil) goto v_24427;
    v_24474 = stack[0];
    v_24474 = qcar(v_24474);
    v_24474 = qcar(v_24474);
    v_24475 = v_24474;
    goto v_24400;
v_24427:
    v_24474 = stack[0];
    v_24474 = qcar(v_24474);
    v_24475 = v_24474;
    goto v_24400;
    v_24475 = nil;
v_24400:
    goto v_24395;
v_24396:
    v_24474 = elt(env, 8); // geq
    goto v_24397;
v_24398:
    goto v_24394;
v_24395:
    goto v_24396;
v_24397:
    if (v_24475 == v_24474) goto v_24392;
    else goto v_24393;
v_24392:
    goto v_24444;
v_24440:
    v_24474 = stack[-1];
    v_24475 = qcdr(v_24474);
    goto v_24441;
v_24442:
    v_24474 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24443;
v_24444:
    goto v_24440;
v_24441:
    goto v_24442;
v_24443:
    v_24474 = (LispObject)lessp2(v_24475, v_24474);
    v_24474 = v_24474 ? lisp_true : nil;
    env = stack[-2];
    goto v_24391;
v_24393:
    v_24474 = nil;
    goto v_24391;
    v_24474 = nil;
v_24391:
    if (v_24474 == nil) goto v_24389;
    goto v_24458;
v_24452:
    stack[-1] = elt(env, 7); // greaterp
    goto v_24453;
v_24454:
    goto v_24465;
v_24461:
    v_24474 = stack[0];
    v_24474 = qcdr(v_24474);
    stack[0] = qcar(v_24474);
    goto v_24462;
v_24463:
    v_24474 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 10); // simp
    v_24474 = (*qfn1(fn))(fn, v_24474);
    env = stack[-2];
    v_24474 = qcar(v_24474);
    goto v_24464;
v_24465:
    goto v_24461;
v_24462:
    goto v_24463;
v_24464:
    fn = elt(env, 11); // addf
    v_24475 = (*qfn2(fn))(fn, stack[0], v_24474);
    goto v_24455;
v_24456:
    v_24474 = nil;
    goto v_24457;
v_24458:
    goto v_24452;
v_24453:
    goto v_24454;
v_24455:
    goto v_24456;
v_24457:
    {
        LispObject v_24481 = stack[-1];
        return list3(v_24481, v_24475, v_24474);
    }
v_24389:
    v_24474 = stack[0];
v_24036:
    return onevalue(v_24474);
}



setup_type const u43_setup[] =
{
    {"redall",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_redall},
    {"pa_list2vect",            TOO_FEW_2,      CC_pa_list2vect,WRONG_NO_2},
    {"get-current-representation",CC_getKcurrentKrepresentation,TOO_MANY_1,WRONG_NO_1},
    {"simpquot",                CC_simpquot,    TOO_MANY_1,    WRONG_NO_1},
    {"dnform",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dnform},
    {"mk+mat+plus+mat",         TOO_FEW_2,      CC_mkLmatLplusLmat,WRONG_NO_2},
    {"cl_sacatlp",              TOO_FEW_2,      CC_cl_sacatlp, WRONG_NO_2},
    {"make-modular-symmetric",  CC_makeKmodularKsymmetric,TOO_MANY_1,WRONG_NO_1},
    {"upperlimitrd",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_upperlimitrd},
    {"init",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_init},
    {"fnreval",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_fnreval},
    {"copy_mat",                CC_copy_mat,    TOO_MANY_1,    WRONG_NO_1},
    {"evzero",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_evzero},
    {"exdf0",                   CC_exdf0,       TOO_MANY_1,    WRONG_NO_1},
    {"gbfdiff",                 TOO_FEW_2,      CC_gbfdiff,    WRONG_NO_2},
    {"getphystypeexpt",         CC_getphystypeexpt,TOO_MANY_1, WRONG_NO_1},
    {"mk_binding",              TOO_FEW_2,      CC_mk_binding, WRONG_NO_2},
    {"ratnump",                 CC_ratnump,     TOO_MANY_1,    WRONG_NO_1},
    {"groeb=testc1",            CC_groebMtestc1,TOO_MANY_1,    WRONG_NO_1},
    {"polynomread",             CC_polynomread, TOO_MANY_1,    WRONG_NO_1},
    {"fctlength",               CC_fctlength,   TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_anegrel",            CC_ofsf_anegrel,TOO_MANY_1,    WRONG_NO_1},
    {"intervalrd",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_intervalrd},
    {"new_simpexpt",            CC_new_simpexpt,TOO_MANY_1,    WRONG_NO_1},
    {"get:const",               TOO_FEW_2,      CC_getTconst,  WRONG_NO_2},
    {"numprintlen",             CC_numprintlen, TOO_MANY_1,    WRONG_NO_1},
    {"miller-rabin",            TOO_FEW_2,      CC_millerKrabin,WRONG_NO_2},
    {"revalpart",               CC_revalpart,   TOO_MANY_1,    WRONG_NO_1},
    {"equiv-coeffs",            TOO_FEW_2,      CC_equivKcoeffs,WRONG_NO_2},
    {"*g2lex",                  CC_Hg2lex,      TOO_MANY_1,    WRONG_NO_1},
    {"isimp1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_isimp1},
    {"rl_qe",                   TOO_FEW_2,      CC_rl_qe,      WRONG_NO_2},
    {"cl_nnf1",                 TOO_FEW_2,      CC_cl_nnf1,    WRONG_NO_2},
    {"pasf_or",                 CC_pasf_or,     TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u43", (two_args *)"97119 4221058 7161180", 0}
};

// end of generated code
