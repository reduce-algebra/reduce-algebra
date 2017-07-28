
// $destdir/u40.c        Machine generated C code

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



// Code for formsetq0

static LispObject CC_formsetq0(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23440, v_23441, v_23442, v_23443;
    LispObject fn;
    LispObject v_22910, v_22909, v_22908;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formsetq0");
    va_start(aa, nargs);
    v_22908 = va_arg(aa, LispObject);
    v_22909 = va_arg(aa, LispObject);
    v_22910 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22910,v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22908,v_22909,v_22910);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_22910;
    stack[-4] = v_22909;
    stack[0] = v_22908;
// end of prologue
    stack[-1] = nil;
    v_23440 = stack[0];
    v_23440 = qcdr(v_23440);
    stack[0] = v_23440;
    v_23440 = qcar(v_23440);
    stack[-2] = v_23440;
    if (symbolp(v_23440)) goto v_22919;
    else goto v_22920;
v_22919:
    goto v_22928;
v_22924:
    v_23441 = stack[-2];
    goto v_22925;
v_22926:
    v_23440 = stack[-4];
    goto v_22927;
v_22928:
    goto v_22924;
v_22925:
    goto v_22926;
v_22927:
    v_23440 = Latsoc(nil, v_23441, v_23440);
    stack[-1] = v_23440;
    goto v_22918;
v_22920:
v_22918:
    goto v_22941;
v_22937:
    v_23440 = stack[0];
    v_23440 = qcdr(v_23440);
    v_23441 = qcar(v_23440);
    goto v_22938;
v_22939:
    v_23440 = elt(env, 1); // quote
    goto v_22940;
v_22941:
    goto v_22937;
v_22938:
    goto v_22939;
v_22940:
    if (!consp(v_23441)) goto v_22935;
    v_23441 = qcar(v_23441);
    if (v_23441 == v_23440) goto v_22934;
    else goto v_22935;
v_22934:
    v_23440 = elt(env, 2); // symbolic
    stack[-3] = v_23440;
    goto v_22933;
v_22935:
v_22933:
    goto v_22956;
v_22948:
    v_23440 = stack[0];
    v_23440 = qcdr(v_23440);
    v_23443 = qcar(v_23440);
    goto v_22949;
v_22950:
    v_23442 = stack[-4];
    goto v_22951;
v_22952:
    v_23441 = elt(env, 2); // symbolic
    goto v_22953;
v_22954:
    v_23440 = stack[-3];
    goto v_22955;
v_22956:
    goto v_22948;
v_22949:
    goto v_22950;
v_22951:
    goto v_22952;
v_22953:
    goto v_22954;
v_22955:
    fn = elt(env, 22); // convertmode
    v_23440 = (*qfnn(fn))(fn, 4, v_23443, v_23442, v_23441, v_23440);
    env = stack[-6];
    stack[-5] = v_23440;
    v_23440 = stack[-2];
    if (!consp(v_23440)) goto v_22970;
    v_23440 = qvalue(elt(env, 3)); // !*savedef
    if (v_23440 == nil) goto v_22975;
    goto v_22985;
v_22981:
    v_23440 = stack[-2];
    v_23441 = qcar(v_23440);
    goto v_22982;
v_22983:
    v_23440 = elt(env, 4); // inline
    goto v_22984;
v_22985:
    goto v_22981;
v_22982:
    goto v_22983;
v_22984:
    v_23440 = get(v_23441, v_23440);
    env = stack[-6];
    if (v_23440 == nil) goto v_22979;
    else goto v_22978;
v_22979:
    goto v_22995;
v_22991:
    v_23440 = stack[-2];
    v_23441 = qcar(v_23440);
    goto v_22992;
v_22993:
    v_23440 = elt(env, 5); // smacro
    goto v_22994;
v_22995:
    goto v_22991;
v_22992:
    goto v_22993;
v_22994:
    v_23440 = get(v_23441, v_23440);
    env = stack[-6];
    if (v_23440 == nil) goto v_22989;
    else goto v_22978;
v_22989:
    goto v_22975;
v_22978:
    v_23440 = Lposn(nil, 0);
    env = stack[-6];
    v_23440 = (LispObject)zerop(v_23440);
    v_23440 = v_23440 ? lisp_true : nil;
    env = stack[-6];
    if (v_23440 == nil) goto v_23001;
    else goto v_23002;
v_23001:
    v_23440 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_23000;
v_23002:
v_23000:
    v_23440 = elt(env, 6); // "+++ Assign via inline or smacro: "
    v_23440 = Lprinc(nil, v_23440);
    env = stack[-6];
    v_23440 = stack[-2];
    v_23440 = Lprint(nil, v_23440);
    env = stack[-6];
    goto v_22973;
v_22975:
v_22973:
    v_23440 = lisp_true;
    goto v_22968;
v_22970:
    v_23440 = nil;
    goto v_22968;
    v_23440 = nil;
v_22968:
    if (v_23440 == nil) goto v_22966;
    v_23440 = stack[-2];
    v_23440 = qcar(v_23440);
    if (symbolp(v_23440)) goto v_23017;
    goto v_23025;
v_23021:
    v_23441 = stack[-2];
    goto v_23022;
v_23023:
    v_23440 = elt(env, 7); // "assignment"
    goto v_23024;
v_23025:
    goto v_23021;
v_23022:
    goto v_23023;
v_23024:
    {
        fn = elt(env, 23); // typerr
        return (*qfn2(fn))(fn, v_23441, v_23440);
    }
v_23017:
    goto v_23039;
v_23035:
    v_23441 = stack[-2];
    goto v_23036;
v_23037:
    v_23440 = stack[-3];
    goto v_23038;
v_23039:
    goto v_23035;
v_23036:
    goto v_23037;
v_23038:
    fn = elt(env, 24); // macrochk
    v_23440 = (*qfn2(fn))(fn, v_23441, v_23440);
    env = stack[-6];
    stack[-2] = v_23440;
    if (!consp(v_23440)) goto v_23033;
    v_23440 = stack[-2];
    v_23440 = qcar(v_23440);
    fn = elt(env, 25); // arrayp
    v_23440 = (*qfn1(fn))(fn, v_23440);
    env = stack[-6];
    goto v_23031;
v_23033:
    v_23440 = nil;
    goto v_23031;
    v_23440 = nil;
v_23031:
    if (v_23440 == nil) goto v_23029;
    goto v_23055;
v_23049:
    stack[0] = elt(env, 8); // setel
    goto v_23050;
v_23051:
    goto v_23064;
v_23058:
    v_23442 = stack[-2];
    goto v_23059;
v_23060:
    v_23441 = stack[-4];
    goto v_23061;
v_23062:
    v_23440 = stack[-3];
    goto v_23063;
v_23064:
    goto v_23058;
v_23059:
    goto v_23060;
v_23061:
    goto v_23062;
v_23063:
    fn = elt(env, 26); // intargfn
    v_23441 = (*qfnn(fn))(fn, 3, v_23442, v_23441, v_23440);
    goto v_23052;
v_23053:
    v_23440 = stack[-5];
    goto v_23054;
v_23055:
    goto v_23049;
v_23050:
    goto v_23051;
v_23052:
    goto v_23053;
v_23054:
    {
        LispObject v_23450 = stack[0];
        return list3(v_23450, v_23441, v_23440);
    }
v_23029:
    v_23440 = stack[-2];
    if (!consp(v_23440)) goto v_23074;
    v_23440 = stack[-2];
    v_23440 = qcdr(v_23440);
    if (v_23440 == nil) goto v_23078;
    else goto v_23079;
v_23078:
    v_23440 = nil;
    goto v_23077;
v_23079:
    goto v_23093;
v_23089:
    v_23440 = stack[-2];
    v_23440 = qcar(v_23440);
    if (!symbolp(v_23440)) v_23441 = nil;
    else { v_23441 = qfastgets(v_23440);
           if (v_23441 != nil) { v_23441 = elt(v_23441, 2); // rtype
#ifdef RECORD_GET
             if (v_23441 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_23441 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_23441 == SPID_NOPROP) v_23441 = nil; }}
#endif
    goto v_23090;
v_23091:
    v_23440 = elt(env, 9); // vector
    goto v_23092;
v_23093:
    goto v_23089;
v_23090:
    goto v_23091;
v_23092:
    if (v_23441 == v_23440) goto v_23087;
    else goto v_23088;
v_23087:
    v_23440 = lisp_true;
    goto v_23086;
v_23088:
    v_23440 = stack[-2];
    v_23440 = qcdr(v_23440);
    v_23440 = qcar(v_23440);
    v_23440 = Lsimple_vectorp(nil, v_23440);
    env = stack[-6];
    if (v_23440 == nil) goto v_23103;
    else goto v_23102;
v_23103:
    goto v_23113;
v_23109:
    v_23440 = stack[-2];
    v_23440 = qcdr(v_23440);
    v_23441 = qcar(v_23440);
    goto v_23110;
v_23111:
    v_23440 = elt(env, 10); // vecfn
    goto v_23112;
v_23113:
    goto v_23109;
v_23110:
    goto v_23111;
v_23112:
    v_23440 = Lflagpcar(nil, v_23441, v_23440);
    env = stack[-6];
v_23102:
    goto v_23086;
    v_23440 = nil;
v_23086:
    goto v_23077;
    v_23440 = nil;
v_23077:
    goto v_23072;
v_23074:
    v_23440 = nil;
    goto v_23072;
    v_23440 = nil;
v_23072:
    if (v_23440 == nil) goto v_23070;
    goto v_23128;
v_23122:
    v_23442 = stack[0];
    goto v_23123;
v_23124:
    v_23441 = stack[-4];
    goto v_23125;
v_23126:
    v_23440 = stack[-3];
    goto v_23127;
v_23128:
    goto v_23122;
v_23123:
    goto v_23124;
v_23125:
    goto v_23126;
v_23127:
    {
        fn = elt(env, 27); // putvect
        return (*qfnn(fn))(fn, 3, v_23442, v_23441, v_23440);
    }
v_23070:
    goto v_23139;
v_23135:
    v_23441 = stack[-2];
    goto v_23136;
v_23137:
    v_23440 = elt(env, 11); // part
    goto v_23138;
v_23139:
    goto v_23135;
v_23136:
    goto v_23137;
v_23138:
    if (!consp(v_23441)) goto v_23133;
    v_23441 = qcar(v_23441);
    if (v_23441 == v_23440) goto v_23132;
    else goto v_23133;
v_23132:
    goto v_23147;
v_23143:
    goto v_23155;
v_23149:
    stack[-1] = elt(env, 12); // list
    goto v_23150;
v_23151:
    v_23440 = elt(env, 13); // setpart!*
    stack[0] = Lmkquote(nil, v_23440);
    env = stack[-6];
    goto v_23152;
v_23153:
    goto v_23166;
v_23160:
    v_23440 = stack[-2];
    v_23442 = qcdr(v_23440);
    goto v_23161;
v_23162:
    v_23441 = stack[-4];
    goto v_23163;
v_23164:
    v_23440 = stack[-3];
    goto v_23165;
v_23166:
    goto v_23160;
v_23161:
    goto v_23162;
v_23163:
    goto v_23164;
v_23165:
    fn = elt(env, 28); // formlis
    v_23440 = (*qfnn(fn))(fn, 3, v_23442, v_23441, v_23440);
    env = stack[-6];
    goto v_23154;
v_23155:
    goto v_23149;
v_23150:
    goto v_23151;
v_23152:
    goto v_23153;
v_23154:
    v_23441 = list2star(stack[-1], stack[0], v_23440);
    env = stack[-6];
    goto v_23144;
v_23145:
    v_23440 = stack[-5];
    goto v_23146;
v_23147:
    goto v_23143;
v_23144:
    goto v_23145;
v_23146:
    {
        fn = elt(env, 29); // aconc
        return (*qfn2(fn))(fn, v_23441, v_23440);
    }
v_23133:
    v_23440 = stack[-2];
    if (!consp(v_23440)) goto v_23177;
    goto v_23184;
v_23180:
    v_23440 = stack[-2];
    v_23441 = qcar(v_23440);
    goto v_23181;
v_23182:
    v_23440 = elt(env, 14); // setqfn
    goto v_23183;
v_23184:
    goto v_23180;
v_23181:
    goto v_23182;
v_23183:
    v_23440 = get(v_23441, v_23440);
    env = stack[-6];
    stack[-1] = v_23440;
    goto v_23175;
v_23177:
    v_23440 = nil;
    goto v_23175;
    v_23440 = nil;
v_23175:
    if (v_23440 == nil) goto v_23173;
    goto v_23198;
v_23192:
    goto v_23206;
v_23200:
    goto v_23201;
v_23202:
    goto v_23213;
v_23209:
    v_23440 = stack[-2];
    v_23441 = qcdr(v_23440);
    goto v_23210;
v_23211:
    v_23440 = stack[0];
    v_23440 = qcdr(v_23440);
    goto v_23212;
v_23213:
    goto v_23209;
v_23210:
    goto v_23211;
v_23212:
    v_23441 = Lappend(nil, v_23441, v_23440);
    env = stack[-6];
    goto v_23203;
v_23204:
    v_23440 = nil;
    goto v_23205;
v_23206:
    goto v_23200;
v_23201:
    goto v_23202;
v_23203:
    goto v_23204;
v_23205:
    fn = elt(env, 30); // applsmacro
    v_23442 = (*qfnn(fn))(fn, 3, stack[-1], v_23441, v_23440);
    env = stack[-6];
    goto v_23193;
v_23194:
    v_23441 = stack[-4];
    goto v_23195;
v_23196:
    v_23440 = stack[-3];
    goto v_23197;
v_23198:
    goto v_23192;
v_23193:
    goto v_23194;
v_23195:
    goto v_23196;
v_23197:
    {
        fn = elt(env, 31); // form1
        return (*qfnn(fn))(fn, 3, v_23442, v_23441, v_23440);
    }
v_23173:
    goto v_23231;
v_23227:
    v_23441 = stack[-3];
    goto v_23228;
v_23229:
    v_23440 = elt(env, 2); // symbolic
    goto v_23230;
v_23231:
    goto v_23227;
v_23228:
    goto v_23229;
v_23230:
    if (v_23441 == v_23440) goto v_23225;
    else goto v_23226;
v_23225:
    v_23440 = qvalue(elt(env, 15)); // !*rlisp88
    if (v_23440 == nil) goto v_23236;
    else goto v_23235;
v_23236:
    goto v_23243;
v_23239:
    v_23441 = stack[-2];
    goto v_23240;
v_23241:
    v_23440 = elt(env, 16); // structfetch
    goto v_23242;
v_23243:
    goto v_23239;
v_23240:
    goto v_23241;
v_23242:
    v_23440 = Leqcar(nil, v_23441, v_23440);
    env = stack[-6];
v_23235:
    goto v_23224;
v_23226:
    v_23440 = nil;
    goto v_23224;
    v_23440 = nil;
v_23224:
    if (v_23440 == nil) goto v_23222;
    goto v_23256;
v_23250:
    stack[0] = elt(env, 17); // rsetf
    goto v_23251;
v_23252:
    goto v_23265;
v_23259:
    v_23442 = stack[-2];
    goto v_23260;
v_23261:
    v_23441 = stack[-4];
    goto v_23262;
v_23263:
    v_23440 = stack[-3];
    goto v_23264;
v_23265:
    goto v_23259;
v_23260:
    goto v_23261;
v_23262:
    goto v_23263;
v_23264:
    fn = elt(env, 31); // form1
    v_23441 = (*qfnn(fn))(fn, 3, v_23442, v_23441, v_23440);
    goto v_23253;
v_23254:
    v_23440 = stack[-5];
    goto v_23255;
v_23256:
    goto v_23250;
v_23251:
    goto v_23252;
v_23253:
    goto v_23254;
v_23255:
    {
        LispObject v_23451 = stack[0];
        return list3(v_23451, v_23441, v_23440);
    }
v_23222:
    goto v_23279;
v_23273:
    stack[0] = elt(env, 18); // setk
    goto v_23274;
v_23275:
    goto v_23288;
v_23282:
    v_23442 = stack[-2];
    goto v_23283;
v_23284:
    v_23441 = stack[-4];
    goto v_23285;
v_23286:
    v_23440 = elt(env, 19); // algebraic
    goto v_23287;
v_23288:
    goto v_23282;
v_23283:
    goto v_23284;
v_23285:
    goto v_23286;
v_23287:
    fn = elt(env, 31); // form1
    v_23441 = (*qfnn(fn))(fn, 3, v_23442, v_23441, v_23440);
    goto v_23276;
v_23277:
    v_23440 = stack[-5];
    goto v_23278;
v_23279:
    goto v_23273;
v_23274:
    goto v_23275;
v_23276:
    goto v_23277;
v_23278:
    {
        LispObject v_23452 = stack[0];
        return list3(v_23452, v_23441, v_23440);
    }
    v_23440 = nil;
    goto v_22964;
v_22966:
    v_23440 = stack[-2];
    if (symbolp(v_23440)) goto v_23294;
    goto v_23301;
v_23297:
    v_23441 = stack[-2];
    goto v_23298;
v_23299:
    v_23440 = elt(env, 7); // "assignment"
    goto v_23300;
v_23301:
    goto v_23297;
v_23298:
    goto v_23299;
v_23300:
    {
        fn = elt(env, 23); // typerr
        return (*qfn2(fn))(fn, v_23441, v_23440);
    }
v_23294:
    goto v_23315;
v_23311:
    v_23441 = stack[-2];
    goto v_23312;
v_23313:
    v_23440 = elt(env, 20); // reserved
    goto v_23314;
v_23315:
    goto v_23311;
v_23312:
    goto v_23313;
v_23314:
    v_23440 = Lflagp(nil, v_23441, v_23440);
    env = stack[-6];
    if (v_23440 == nil) goto v_23309;
    goto v_23322;
v_23318:
    v_23441 = stack[-2];
    goto v_23319;
v_23320:
    v_23440 = stack[-4];
    goto v_23321;
v_23322:
    goto v_23318;
v_23319:
    goto v_23320;
v_23321:
    v_23440 = Latsoc(nil, v_23441, v_23440);
    v_23440 = (v_23440 == nil ? lisp_true : nil);
    goto v_23307;
v_23309:
    v_23440 = nil;
    goto v_23307;
    v_23440 = nil;
v_23307:
    if (v_23440 == nil) goto v_23305;
    v_23440 = stack[-2];
    {
        fn = elt(env, 32); // rsverr
        return (*qfn1(fn))(fn, v_23440);
    }
v_23305:
    v_23440 = stack[-2];
    if (!symbolp(v_23440)) v_23440 = nil;
    else { v_23440 = qfastgets(v_23440);
           if (v_23440 != nil) { v_23440 = elt(v_23440, 17); // share
#ifdef RECORD_GET
             if (v_23440 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v_23440 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v_23440 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v_23440 == SPID_NOPROP) v_23440 = nil; else v_23440 = lisp_true; }}
#endif
    if (v_23440 == nil) goto v_23333;
    goto v_23341;
v_23337:
    goto v_23347;
v_23343:
    v_23441 = stack[-2];
    goto v_23344;
v_23345:
    v_23440 = stack[-4];
    goto v_23346;
v_23347:
    goto v_23343;
v_23344:
    goto v_23345;
v_23346:
    fn = elt(env, 33); // symbid
    v_23441 = (*qfn2(fn))(fn, v_23441, v_23440);
    env = stack[-6];
    goto v_23338;
v_23339:
    v_23440 = stack[-5];
    goto v_23340;
v_23341:
    goto v_23337;
v_23338:
    goto v_23339;
v_23340:
    {
        fn = elt(env, 34); // mksetshare
        return (*qfn2(fn))(fn, v_23441, v_23440);
    }
v_23333:
    goto v_23361;
v_23357:
    v_23441 = stack[-3];
    goto v_23358;
v_23359:
    v_23440 = elt(env, 2); // symbolic
    goto v_23360;
v_23361:
    goto v_23357;
v_23358:
    goto v_23359;
v_23360:
    if (v_23441 == v_23440) goto v_23355;
    else goto v_23356;
v_23355:
    v_23440 = lisp_true;
    goto v_23354;
v_23356:
    v_23440 = stack[-1];
    if (v_23440 == nil) goto v_23369;
    else goto v_23368;
v_23369:
    goto v_23376;
v_23372:
    v_23441 = stack[-5];
    goto v_23373;
v_23374:
    v_23440 = elt(env, 1); // quote
    goto v_23375;
v_23376:
    goto v_23372;
v_23373:
    goto v_23374;
v_23375:
    v_23440 = Leqcar(nil, v_23441, v_23440);
    env = stack[-6];
v_23368:
    goto v_23354;
    v_23440 = nil;
v_23354:
    if (v_23440 == nil) goto v_23352;
    goto v_23384;
v_23380:
    goto v_23390;
v_23386:
    v_23441 = stack[-2];
    goto v_23387;
v_23388:
    v_23440 = stack[-4];
    goto v_23389;
v_23390:
    goto v_23386;
v_23387:
    goto v_23388;
v_23389:
    fn = elt(env, 33); // symbid
    v_23441 = (*qfn2(fn))(fn, v_23441, v_23440);
    env = stack[-6];
    goto v_23381;
v_23382:
    v_23440 = stack[-5];
    goto v_23383;
v_23384:
    goto v_23380;
v_23381:
    goto v_23382;
v_23383:
    {
        fn = elt(env, 35); // mksetq
        return (*qfn2(fn))(fn, v_23441, v_23440);
    }
v_23352:
    v_23440 = stack[0];
    v_23440 = qcdr(v_23440);
    v_23440 = qcar(v_23440);
    v_23440 = Lsimple_vectorp(nil, v_23440);
    env = stack[-6];
    if (v_23440 == nil) goto v_23396;
    else goto v_23394;
v_23396:
    goto v_23407;
v_23403:
    v_23440 = stack[0];
    v_23440 = qcdr(v_23440);
    v_23441 = qcar(v_23440);
    goto v_23404;
v_23405:
    v_23440 = elt(env, 10); // vecfn
    goto v_23406;
v_23407:
    goto v_23403;
v_23404:
    goto v_23405;
v_23406:
    v_23440 = Lflagpcar(nil, v_23441, v_23440);
    env = stack[-6];
    if (v_23440 == nil) goto v_23401;
    else goto v_23394;
v_23401:
    goto v_23395;
v_23394:
    goto v_23419;
v_23413:
    stack[-1] = elt(env, 21); // setv
    goto v_23414;
v_23415:
    v_23440 = stack[-2];
    v_23441 = Lmkquote(nil, v_23440);
    goto v_23416;
v_23417:
    v_23440 = stack[0];
    v_23440 = qcdr(v_23440);
    v_23440 = qcar(v_23440);
    goto v_23418;
v_23419:
    goto v_23413;
v_23414:
    goto v_23415;
v_23416:
    goto v_23417;
v_23418:
    {
        LispObject v_23453 = stack[-1];
        return list3(v_23453, v_23441, v_23440);
    }
v_23395:
    goto v_23435;
v_23429:
    stack[0] = elt(env, 18); // setk
    goto v_23430;
v_23431:
    v_23440 = stack[-2];
    v_23441 = Lmkquote(nil, v_23440);
    goto v_23432;
v_23433:
    v_23440 = stack[-5];
    goto v_23434;
v_23435:
    goto v_23429;
v_23430:
    goto v_23431;
v_23432:
    goto v_23433;
v_23434:
    {
        LispObject v_23454 = stack[0];
        return list3(v_23454, v_23441, v_23440);
    }
    v_23440 = nil;
v_22964:
    return onevalue(v_23440);
}



// Code for !*n2a

static LispObject CC_Hn2a(LispObject env,
                         LispObject v_22908)
{
    env = qenv(env);
    LispObject v_22921, v_22922;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22922 = v_22908;
// end of prologue
    v_22921 = v_22922;
    v_22921 = integerp(v_22921);
    if (v_22921 == nil) goto v_22913;
    v_22921 = v_22922;
    goto v_22911;
v_22913:
    v_22921 = v_22922;
    {
        fn = elt(env, 1); // !*q2a
        return (*qfn1(fn))(fn, v_22921);
    }
    v_22921 = nil;
v_22911:
    return onevalue(v_22921);
}



// Code for appn

static LispObject CC_appn(LispObject env,
                         LispObject v_22908, LispObject v_22909)
{
    env = qenv(env);
    LispObject v_22957, v_22958;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22908,v_22909);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_22909;
    stack[-1] = v_22908;
// end of prologue
    stack[-2] = nil;
v_22915:
    goto v_22926;
v_22922:
    v_22958 = stack[0];
    goto v_22923;
v_22924:
    v_22957 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22925;
v_22926:
    goto v_22922;
v_22923:
    goto v_22924;
v_22925:
    if (v_22958 == v_22957) goto v_22920;
    else goto v_22921;
v_22920:
    goto v_22916;
v_22921:
    goto v_22934;
v_22930:
    v_22958 = stack[-1];
    goto v_22931;
v_22932:
    v_22957 = stack[-2];
    goto v_22933;
v_22934:
    goto v_22930;
v_22931:
    goto v_22932;
v_22933:
    v_22957 = cons(v_22958, v_22957);
    env = stack[-3];
    stack[-2] = v_22957;
    v_22957 = stack[0];
    v_22957 = sub1(v_22957);
    env = stack[-3];
    stack[0] = v_22957;
    goto v_22915;
v_22916:
    v_22957 = stack[-1];
    v_22958 = v_22957;
v_22917:
    v_22957 = stack[-2];
    if (v_22957 == nil) goto v_22942;
    else goto v_22943;
v_22942:
    v_22957 = v_22958;
    goto v_22914;
v_22943:
    goto v_22951;
v_22947:
    v_22957 = stack[-2];
    v_22957 = qcar(v_22957);
    goto v_22948;
v_22949:
    goto v_22950;
v_22951:
    goto v_22947;
v_22948:
    goto v_22949;
v_22950:
    v_22957 = Lappend(nil, v_22957, v_22958);
    env = stack[-3];
    v_22958 = v_22957;
    v_22957 = stack[-2];
    v_22957 = qcdr(v_22957);
    stack[-2] = v_22957;
    goto v_22917;
v_22914:
    return onevalue(v_22957);
}



// Code for maxfrom

static LispObject CC_maxfrom(LispObject env,
                         LispObject v_22908, LispObject v_22909)
{
    env = qenv(env);
    LispObject v_22923, v_22924;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22908,v_22909);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_22923 = v_22909;
    v_22924 = v_22908;
// end of prologue
    goto v_22918;
v_22912:
    stack[0] = v_22924;
    goto v_22913;
v_22914:
    v_22924 = add1(v_22923);
    env = stack[-1];
    goto v_22915;
v_22916:
    v_22923 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22917;
v_22918:
    goto v_22912;
v_22913:
    goto v_22914;
v_22915:
    goto v_22916;
v_22917:
    {
        LispObject v_22926 = stack[0];
        fn = elt(env, 1); // maxfrom1
        return (*qfnn(fn))(fn, 3, v_22926, v_22924, v_22923);
    }
}



// Code for pasf_fact

static LispObject CC_pasf_fact(LispObject env,
                         LispObject v_22908)
{
    env = qenv(env);
    LispObject v_23091, v_23092, v_23093;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22908);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_22908;
// end of prologue
    goto v_22927;
v_22923:
    v_23092 = stack[-1];
    goto v_22924;
v_22925:
    v_23091 = elt(env, 1); // true
    goto v_22926;
v_22927:
    goto v_22923;
v_22924:
    goto v_22925;
v_22926:
    if (v_23092 == v_23091) goto v_22921;
    else goto v_22922;
v_22921:
    v_23091 = lisp_true;
    goto v_22920;
v_22922:
    goto v_22937;
v_22933:
    v_23092 = stack[-1];
    goto v_22934;
v_22935:
    v_23091 = elt(env, 2); // false
    goto v_22936;
v_22937:
    goto v_22933;
v_22934:
    goto v_22935;
v_22936:
    v_23091 = (v_23092 == v_23091 ? lisp_true : nil);
    goto v_22920;
    v_23091 = nil;
v_22920:
    if (v_23091 == nil) goto v_22918;
    v_23091 = stack[-1];
    goto v_22914;
v_22918:
    v_23091 = stack[-1];
    v_23091 = qcar(v_23091);
    stack[-5] = v_23091;
    v_23091 = stack[-1];
    v_23091 = qcdr(v_23091);
    v_23091 = qcar(v_23091);
    fn = elt(env, 8); // fctrf
    v_23091 = (*qfn1(fn))(fn, v_23091);
    env = stack[-6];
    stack[0] = v_23091;
    goto v_22957;
v_22953:
    v_23091 = stack[0];
    v_23092 = Llength(nil, v_23091);
    env = stack[-6];
    goto v_22954;
v_22955:
    v_23091 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_22956;
v_22957:
    goto v_22953;
v_22954:
    goto v_22955;
v_22956:
    v_23091 = (LispObject)lessp2(v_23092, v_23091);
    v_23091 = v_23091 ? lisp_true : nil;
    env = stack[-6];
    if (v_23091 == nil) goto v_22951;
    v_23091 = stack[-1];
    goto v_22914;
v_22951:
    goto v_22970;
v_22966:
    v_23092 = stack[-5];
    goto v_22967;
v_22968:
    v_23091 = elt(env, 3); // (equal neq)
    goto v_22969;
v_22970:
    goto v_22966;
v_22967:
    goto v_22968;
v_22969:
    v_23091 = Lmemq(nil, v_23092, v_23091);
    if (v_23091 == nil) goto v_22965;
    goto v_22979;
v_22975:
    goto v_22988;
v_22984:
    v_23092 = stack[-5];
    goto v_22985;
v_22986:
    v_23091 = elt(env, 4); // equal
    goto v_22987;
v_22988:
    goto v_22984;
v_22985:
    goto v_22986;
v_22987:
    if (v_23092 == v_23091) goto v_22982;
    else goto v_22983;
v_22982:
    v_23091 = elt(env, 5); // or
    stack[-4] = v_23091;
    goto v_22981;
v_22983:
    v_23091 = elt(env, 6); // and
    stack[-4] = v_23091;
    goto v_22981;
    stack[-4] = nil;
v_22981:
    goto v_22976;
v_22977:
    v_23091 = stack[0];
    v_23091 = qcdr(v_23091);
    stack[-3] = v_23091;
    v_23091 = stack[-3];
    if (v_23091 == nil) goto v_23005;
    else goto v_23006;
v_23005:
    v_23091 = nil;
    goto v_22999;
v_23006:
    v_23091 = stack[-3];
    v_23091 = qcar(v_23091);
    goto v_23020;
v_23014:
    v_23093 = stack[-5];
    goto v_23015;
v_23016:
    v_23092 = qcar(v_23091);
    goto v_23017;
v_23018:
    v_23091 = nil;
    goto v_23019;
v_23020:
    goto v_23014;
v_23015:
    goto v_23016;
v_23017:
    goto v_23018;
v_23019:
    v_23091 = list3(v_23093, v_23092, v_23091);
    env = stack[-6];
    v_23091 = ncons(v_23091);
    env = stack[-6];
    stack[-1] = v_23091;
    stack[-2] = v_23091;
v_23000:
    v_23091 = stack[-3];
    v_23091 = qcdr(v_23091);
    stack[-3] = v_23091;
    v_23091 = stack[-3];
    if (v_23091 == nil) goto v_23029;
    else goto v_23030;
v_23029:
    v_23091 = stack[-2];
    goto v_22999;
v_23030:
    goto v_23038;
v_23034:
    stack[0] = stack[-1];
    goto v_23035;
v_23036:
    v_23091 = stack[-3];
    v_23091 = qcar(v_23091);
    goto v_23051;
v_23045:
    v_23093 = stack[-5];
    goto v_23046;
v_23047:
    v_23092 = qcar(v_23091);
    goto v_23048;
v_23049:
    v_23091 = nil;
    goto v_23050;
v_23051:
    goto v_23045;
v_23046:
    goto v_23047;
v_23048:
    goto v_23049;
v_23050:
    v_23091 = list3(v_23093, v_23092, v_23091);
    env = stack[-6];
    v_23091 = ncons(v_23091);
    env = stack[-6];
    goto v_23037;
v_23038:
    goto v_23034;
v_23035:
    goto v_23036;
v_23037:
    v_23091 = Lrplacd(nil, stack[0], v_23091);
    env = stack[-6];
    v_23091 = stack[-1];
    v_23091 = qcdr(v_23091);
    stack[-1] = v_23091;
    goto v_23000;
v_22999:
    goto v_22978;
v_22979:
    goto v_22975;
v_22976:
    goto v_22977;
v_22978:
    {
        LispObject v_23100 = stack[-4];
        return cons(v_23100, v_23091);
    }
v_22965:
    goto v_23066;
v_23062:
    v_23092 = stack[-5];
    goto v_23063;
v_23064:
    v_23091 = elt(env, 7); // (leq lessp geq greaterp)
    goto v_23065;
v_23066:
    goto v_23062;
v_23063:
    goto v_23064;
v_23065:
    v_23091 = Lmemq(nil, v_23092, v_23091);
    if (v_23091 == nil) goto v_23061;
    goto v_23075;
v_23071:
    v_23091 = stack[0];
    stack[-1] = qcdr(v_23091);
    goto v_23072;
v_23073:
    v_23091 = stack[0];
    v_23091 = qcar(v_23091);
    fn = elt(env, 9); // minusf
    v_23091 = (*qfn1(fn))(fn, v_23091);
    env = stack[-6];
    if (v_23091 == nil) goto v_23081;
    v_23091 = stack[-5];
    fn = elt(env, 10); // pasf_anegrel
    v_23091 = (*qfn1(fn))(fn, v_23091);
    env = stack[-6];
    goto v_23079;
v_23081:
    v_23091 = stack[-5];
    goto v_23079;
    v_23091 = nil;
v_23079:
    goto v_23074;
v_23075:
    goto v_23071;
v_23072:
    goto v_23073;
v_23074:
    {
        LispObject v_23101 = stack[-1];
        fn = elt(env, 11); // pasf_fact1
        return (*qfn2(fn))(fn, v_23101, v_23091);
    }
v_23061:
    v_23091 = stack[-1];
v_22914:
    return onevalue(v_23091);
}



// Code for upperlimitrd

static LispObject CC_upperlimitrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22956, v_22957;
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
    fn = elt(env, 6); // lex
    v_22956 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_22921;
v_22917:
    v_22957 = qvalue(elt(env, 1)); // char
    goto v_22918;
v_22919:
    v_22956 = elt(env, 2); // (u p l i m i t)
    goto v_22920;
v_22921:
    goto v_22917;
v_22918:
    goto v_22919;
v_22920:
    if (equal(v_22957, v_22956)) goto v_22916;
    goto v_22929;
v_22925:
    v_22957 = elt(env, 3); // "<uplimit>"
    goto v_22926;
v_22927:
    v_22956 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_22928;
v_22929:
    goto v_22925;
v_22926:
    goto v_22927;
v_22928:
    fn = elt(env, 7); // errorml
    v_22956 = (*qfn2(fn))(fn, v_22957, v_22956);
    env = stack[-1];
    goto v_22914;
v_22916:
v_22914:
    fn = elt(env, 8); // mathml
    v_22956 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_22956;
    fn = elt(env, 6); // lex
    v_22956 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_22942;
v_22938:
    v_22957 = qvalue(elt(env, 1)); // char
    goto v_22939;
v_22940:
    v_22956 = elt(env, 4); // (!/ u p l i m i t)
    goto v_22941;
v_22942:
    goto v_22938;
v_22939:
    goto v_22940;
v_22941:
    if (equal(v_22957, v_22956)) goto v_22936;
    else goto v_22937;
v_22936:
    v_22956 = stack[0];
    goto v_22911;
v_22937:
    goto v_22953;
v_22949:
    v_22957 = elt(env, 5); // "</uplimit>"
    goto v_22950;
v_22951:
    v_22956 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_22952;
v_22953:
    goto v_22949;
v_22950:
    goto v_22951;
v_22952:
    fn = elt(env, 7); // errorml
    v_22956 = (*qfn2(fn))(fn, v_22957, v_22956);
    goto v_22935;
v_22935:
    v_22956 = nil;
v_22911:
    return onevalue(v_22956);
}



// Code for prlist

static LispObject CC_prlist(LispObject env,
                         LispObject v_22908)
{
    env = qenv(env);
    LispObject v_22941, v_22942;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22908);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_22908;
// end of prologue
    v_22942 = nil;
v_22913:
    v_22941 = stack[0];
    if (v_22941 == nil) goto v_22916;
    else goto v_22917;
v_22916:
    v_22941 = v_22942;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_22941);
    }
v_22917:
    v_22941 = stack[0];
    v_22941 = qcar(v_22941);
    v_22941 = Lconsp(nil, v_22941);
    env = stack[-1];
    if (v_22941 == nil) goto v_22922;
    goto v_22931;
v_22927:
    v_22941 = stack[0];
    v_22941 = qcar(v_22941);
    goto v_22928;
v_22929:
    goto v_22930;
v_22931:
    goto v_22927;
v_22928:
    goto v_22929;
v_22930:
    v_22941 = cons(v_22941, v_22942);
    env = stack[-1];
    v_22942 = v_22941;
    v_22941 = stack[0];
    v_22941 = qcdr(v_22941);
    stack[0] = v_22941;
    goto v_22913;
v_22922:
    v_22941 = stack[0];
    v_22941 = qcdr(v_22941);
    stack[0] = v_22941;
    goto v_22913;
    v_22941 = nil;
    return onevalue(v_22941);
}



// Code for copy_mat

static LispObject CC_copy_mat(LispObject env,
                         LispObject v_22908)
{
    env = qenv(env);
    LispObject v_23003, v_23004, v_23005;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22908);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_22908;
// end of prologue
    v_23003 = stack[-7];
    fn = elt(env, 1); // matrix_input_test
    v_23003 = (*qfn1(fn))(fn, v_23003);
    env = stack[-9];
    v_23003 = stack[-7];
    fn = elt(env, 2); // size_of_matrix
    v_23003 = (*qfn1(fn))(fn, v_23003);
    env = stack[-9];
    v_23003 = qcar(v_23003);
    stack[-6] = v_23003;
    v_23003 = stack[-7];
    fn = elt(env, 2); // size_of_matrix
    v_23003 = (*qfn1(fn))(fn, v_23003);
    env = stack[-9];
    v_23003 = qcdr(v_23003);
    v_23003 = qcar(v_23003);
    stack[-5] = v_23003;
    goto v_22931;
v_22927:
    v_23004 = stack[-6];
    goto v_22928;
v_22929:
    v_23003 = stack[-5];
    goto v_22930;
v_22931:
    goto v_22927;
v_22928:
    goto v_22929;
v_22930:
    fn = elt(env, 3); // mkmatrix
    v_23003 = (*qfn2(fn))(fn, v_23004, v_23003);
    env = stack[-9];
    stack[-8] = v_23003;
    v_23003 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_23003;
v_22937:
    goto v_22949;
v_22945:
    v_23004 = stack[-6];
    goto v_22946;
v_22947:
    v_23003 = stack[-4];
    goto v_22948;
v_22949:
    goto v_22945;
v_22946:
    goto v_22947;
v_22948:
    v_23003 = difference2(v_23004, v_23003);
    env = stack[-9];
    v_23003 = Lminusp(nil, v_23003);
    env = stack[-9];
    if (v_23003 == nil) goto v_22942;
    goto v_22936;
v_22942:
    v_23003 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_23003;
v_22956:
    goto v_22968;
v_22964:
    v_23004 = stack[-5];
    goto v_22965;
v_22966:
    v_23003 = stack[-3];
    goto v_22967;
v_22968:
    goto v_22964;
v_22965:
    goto v_22966;
v_22967:
    v_23003 = difference2(v_23004, v_23003);
    env = stack[-9];
    v_23003 = Lminusp(nil, v_23003);
    env = stack[-9];
    if (v_23003 == nil) goto v_22961;
    goto v_22955;
v_22961:
    goto v_22981;
v_22973:
    stack[-2] = stack[-8];
    goto v_22974;
v_22975:
    stack[-1] = stack[-4];
    goto v_22976;
v_22977:
    stack[0] = stack[-3];
    goto v_22978;
v_22979:
    goto v_22992;
v_22986:
    v_23005 = stack[-7];
    goto v_22987;
v_22988:
    v_23004 = stack[-4];
    goto v_22989;
v_22990:
    v_23003 = stack[-3];
    goto v_22991;
v_22992:
    goto v_22986;
v_22987:
    goto v_22988;
v_22989:
    goto v_22990;
v_22991:
    fn = elt(env, 4); // getmat
    v_23003 = (*qfnn(fn))(fn, 3, v_23005, v_23004, v_23003);
    env = stack[-9];
    goto v_22980;
v_22981:
    goto v_22973;
v_22974:
    goto v_22975;
v_22976:
    goto v_22977;
v_22978:
    goto v_22979;
v_22980:
    fn = elt(env, 5); // setmat
    v_23003 = (*qfnn(fn))(fn, 4, stack[-2], stack[-1], stack[0], v_23003);
    env = stack[-9];
    v_23003 = stack[-3];
    v_23003 = add1(v_23003);
    env = stack[-9];
    stack[-3] = v_23003;
    goto v_22956;
v_22955:
    v_23003 = stack[-4];
    v_23003 = add1(v_23003);
    env = stack[-9];
    stack[-4] = v_23003;
    goto v_22937;
v_22936:
    v_23003 = stack[-8];
    return onevalue(v_23003);
}



// Code for mkbc

static LispObject CC_mkbc(LispObject env,
                         LispObject v_22908, LispObject v_22909)
{
    env = qenv(env);
    LispObject v_23015, v_23016;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22908,v_22909);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_22909;
    stack[-1] = v_22908;
// end of prologue
v_22913:
    v_23015 = stack[-1];
    v_23015 = (is_number(v_23015) ? lisp_true : nil);
    if (v_23015 == nil) goto v_22916;
    else goto v_22915;
v_22916:
    v_23015 = stack[-1];
    fn = elt(env, 3); // f2dip11
    v_23015 = (*qfn1(fn))(fn, v_23015);
    env = stack[-3];
v_22915:
    v_23015 = stack[0];
    v_23015 = (is_number(v_23015) ? lisp_true : nil);
    if (v_23015 == nil) goto v_22923;
    else goto v_22922;
v_22923:
    v_23015 = stack[0];
    fn = elt(env, 3); // f2dip11
    v_23015 = (*qfn1(fn))(fn, v_23015);
    env = stack[-3];
v_22922:
    v_23015 = qvalue(elt(env, 1)); // !*grmod!*
    if (v_23015 == nil) goto v_22931;
    goto v_22939;
v_22935:
    goto v_22936;
v_22937:
    v_23015 = stack[0];
    v_23015 = Lmodular_reciprocal(nil, v_23015);
    env = stack[-3];
    goto v_22938;
v_22939:
    goto v_22935;
v_22936:
    goto v_22937;
v_22938:
    v_23015 = times2(stack[-1], v_23015);
    env = stack[-3];
    {
        fn = elt(env, 4); // bcfi
        return (*qfn1(fn))(fn, v_23015);
    }
v_22931:
    goto v_22949;
v_22945:
    v_23016 = stack[0];
    goto v_22946;
v_22947:
    v_23015 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22948;
v_22949:
    goto v_22945;
v_22946:
    goto v_22947;
v_22948:
    if (v_23016 == v_23015) goto v_22943;
    else goto v_22944;
v_22943:
    goto v_22960;
v_22956:
    v_23016 = stack[-1];
    goto v_22957;
v_22958:
    v_23015 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22959;
v_22960:
    goto v_22956;
v_22957:
    goto v_22958;
v_22959:
    if (v_23016 == v_23015) goto v_22954;
    else goto v_22955;
v_22954:
    v_23015 = elt(env, 2); // (1 . 1)
    goto v_22912;
v_22955:
    goto v_22971;
v_22967:
    v_23016 = stack[-1];
    goto v_22968;
v_22969:
    v_23015 = stack[0];
    goto v_22970;
v_22971:
    goto v_22967;
v_22968:
    goto v_22969;
v_22970:
    return cons(v_23016, v_23015);
    goto v_22929;
v_22944:
    v_23015 = stack[0];
    fn = elt(env, 5); // minusf
    v_23015 = (*qfn1(fn))(fn, v_23015);
    env = stack[-3];
    if (v_23015 == nil) goto v_22975;
    v_23015 = stack[-1];
    fn = elt(env, 6); // negf
    v_23015 = (*qfn1(fn))(fn, v_23015);
    env = stack[-3];
    stack[-1] = v_23015;
    v_23015 = stack[0];
    fn = elt(env, 6); // negf
    v_23015 = (*qfn1(fn))(fn, v_23015);
    env = stack[-3];
    stack[0] = v_23015;
    goto v_22913;
v_22975:
    goto v_22989;
v_22985:
    v_23016 = stack[-1];
    goto v_22986;
v_22987:
    v_23015 = stack[0];
    goto v_22988;
v_22989:
    goto v_22985;
v_22986:
    goto v_22987;
v_22988:
    fn = elt(env, 7); // gcdf
    v_23015 = (*qfn2(fn))(fn, v_23016, v_23015);
    env = stack[-3];
    stack[-2] = v_23015;
    goto v_22998;
v_22994:
    goto v_23004;
v_23000:
    v_23016 = stack[-1];
    goto v_23001;
v_23002:
    v_23015 = stack[-2];
    goto v_23003;
v_23004:
    goto v_23000;
v_23001:
    goto v_23002;
v_23003:
    fn = elt(env, 8); // quotfx
    stack[-1] = (*qfn2(fn))(fn, v_23016, v_23015);
    env = stack[-3];
    goto v_22995;
v_22996:
    goto v_23012;
v_23008:
    v_23016 = stack[0];
    goto v_23009;
v_23010:
    v_23015 = stack[-2];
    goto v_23011;
v_23012:
    goto v_23008;
v_23009:
    goto v_23010;
v_23011:
    fn = elt(env, 8); // quotfx
    v_23015 = (*qfn2(fn))(fn, v_23016, v_23015);
    goto v_22997;
v_22998:
    goto v_22994;
v_22995:
    goto v_22996;
v_22997:
    {
        LispObject v_23020 = stack[-1];
        return cons(v_23020, v_23015);
    }
v_22929:
    v_23015 = nil;
v_22912:
    return onevalue(v_23015);
}



// Code for evweightedcomp1

static LispObject CC_evweightedcomp1(LispObject env,
                         LispObject v_22908, LispObject v_22909)
{
    env = qenv(env);
    LispObject v_22922, v_22923, v_22924;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22922 = v_22909;
    v_22923 = v_22908;
// end of prologue
    goto v_22918;
v_22912:
    v_22924 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22913;
v_22914:
    goto v_22915;
v_22916:
    goto v_22917;
v_22918:
    goto v_22912;
v_22913:
    goto v_22914;
v_22915:
    goto v_22916;
v_22917:
    {
        fn = elt(env, 1); // evweightedcomp2
        return (*qfnn(fn))(fn, 3, v_22924, v_22923, v_22922);
    }
}



// Code for mkupf

static LispObject CC_mkupf(LispObject env,
                         LispObject v_22908)
{
    env = qenv(env);
    LispObject v_23023, v_23024, v_23025;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22908);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_23023 = v_22908;
// end of prologue
    goto v_22918;
v_22914:
    v_23024 = v_23023;
    goto v_22915;
v_22916:
    v_23023 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22917;
v_22918:
    goto v_22914;
v_22915:
    goto v_22916;
v_22917:
    fn = elt(env, 1); // mksq
    v_23023 = (*qfn2(fn))(fn, v_23024, v_23023);
    env = stack[-1];
    stack[0] = v_23023;
    v_23023 = stack[0];
    v_23023 = qcar(v_23023);
    if (v_23023 == nil) goto v_22923;
    else goto v_22924;
v_22923:
    v_23023 = nil;
    goto v_22922;
v_22924:
    v_23023 = stack[0];
    v_23023 = qcar(v_23023);
    if (!consp(v_23023)) goto v_22932;
    else goto v_22933;
v_22932:
    v_23023 = lisp_true;
    goto v_22931;
v_22933:
    v_23023 = stack[0];
    v_23023 = qcar(v_23023);
    v_23023 = qcar(v_23023);
    v_23023 = (consp(v_23023) ? nil : lisp_true);
    goto v_22931;
    v_23023 = nil;
v_22931:
    if (v_23023 == nil) goto v_22929;
    goto v_22949;
v_22945:
    v_23024 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22946;
v_22947:
    v_23023 = stack[0];
    goto v_22948;
v_22949:
    goto v_22945;
v_22946:
    goto v_22947;
v_22948:
    v_23023 = cons(v_23024, v_23023);
    return ncons(v_23023);
v_22929:
    goto v_22962;
v_22958:
    v_23023 = stack[0];
    v_23024 = qcdr(v_23023);
    goto v_22959;
v_22960:
    v_23023 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22961;
v_22962:
    goto v_22958;
v_22959:
    goto v_22960;
v_22961:
    if (v_23024 == v_23023) goto v_22956;
    else goto v_22957;
v_22956:
    goto v_22974;
v_22970:
    v_23023 = stack[0];
    v_23023 = qcar(v_23023);
    v_23023 = qcar(v_23023);
    v_23024 = qcdr(v_23023);
    goto v_22971;
v_22972:
    v_23023 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22973;
v_22974:
    goto v_22970;
v_22971:
    goto v_22972;
v_22973:
    if (v_23024 == v_23023) goto v_22968;
    else goto v_22969;
v_22968:
    v_23023 = stack[0];
    v_23023 = qcar(v_23023);
    v_23023 = qcdr(v_23023);
    if (v_23023 == nil) goto v_22982;
    else goto v_22983;
v_22982:
    v_23023 = stack[0];
    v_23023 = qcar(v_23023);
    v_23023 = qcar(v_23023);
    v_23023 = qcar(v_23023);
    v_23023 = qcar(v_23023);
    fn = elt(env, 2); // sfp
    v_23023 = (*qfn1(fn))(fn, v_23023);
    env = stack[-1];
    v_23023 = (v_23023 == nil ? lisp_true : nil);
    goto v_22981;
v_22983:
    v_23023 = nil;
    goto v_22981;
    v_23023 = nil;
v_22981:
    goto v_22967;
v_22969:
    v_23023 = nil;
    goto v_22967;
    v_23023 = nil;
v_22967:
    goto v_22955;
v_22957:
    v_23023 = nil;
    goto v_22955;
    v_23023 = nil;
v_22955:
    if (v_23023 == nil) goto v_22953;
    goto v_23011;
v_23005:
    v_23023 = stack[0];
    v_23023 = qcar(v_23023);
    v_23023 = qcar(v_23023);
    v_23023 = qcar(v_23023);
    v_23025 = qcar(v_23023);
    goto v_23006;
v_23007:
    v_23024 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23008;
v_23009:
    v_23023 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23010;
v_23011:
    goto v_23005;
v_23006:
    goto v_23007;
v_23008:
    goto v_23009;
v_23010:
    v_23023 = list2star(v_23025, v_23024, v_23023);
    return ncons(v_23023);
v_22953:
    v_23023 = stack[0];
    {
        fn = elt(env, 3); // partitsq!*
        return (*qfn1(fn))(fn, v_23023);
    }
    v_23023 = nil;
v_22922:
    return onevalue(v_23023);
}



// Code for mod!-dump1

static LispObject CC_modKdump1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22952, v_22953, v_22954;
    LispObject fn;
    LispObject v_22910, v_22909, v_22908;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mod-dump1");
    va_start(aa, nargs);
    v_22908 = va_arg(aa, LispObject);
    v_22909 = va_arg(aa, LispObject);
    v_22910 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22910,v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22908,v_22909,v_22910);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_22910;
    stack[-2] = v_22909;
    stack[-3] = v_22908;
// end of prologue
    stack[-4] = nil;
v_22915:
    v_22952 = stack[-1];
    if (v_22952 == nil) goto v_22918;
    else goto v_22919;
v_22918:
    v_22952 = stack[-4];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_22952);
    }
v_22919:
    goto v_22932;
v_22926:
    v_22952 = stack[-1];
    v_22952 = qcar(v_22952);
    stack[0] = qcar(v_22952);
    goto v_22927;
v_22928:
    goto v_22943;
v_22937:
    v_22954 = stack[-3];
    goto v_22938;
v_22939:
    v_22953 = stack[-2];
    goto v_22940;
v_22941:
    v_22952 = stack[-1];
    v_22952 = qcar(v_22952);
    v_22952 = qcdr(v_22952);
    goto v_22942;
v_22943:
    goto v_22937;
v_22938:
    goto v_22939;
v_22940:
    goto v_22941;
v_22942:
    fn = elt(env, 2); // l!-subst
    v_22953 = (*qfnn(fn))(fn, 3, v_22954, v_22953, v_22952);
    env = stack[-5];
    goto v_22929;
v_22930:
    v_22952 = stack[-4];
    goto v_22931;
v_22932:
    goto v_22926;
v_22927:
    goto v_22928;
v_22929:
    goto v_22930;
v_22931:
    v_22952 = acons(stack[0], v_22953, v_22952);
    env = stack[-5];
    stack[-4] = v_22952;
    v_22952 = stack[-1];
    v_22952 = qcdr(v_22952);
    stack[-1] = v_22952;
    goto v_22915;
    v_22952 = nil;
    return onevalue(v_22952);
}



// Code for redall

static LispObject CC_redall(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23172, v_23173, v_23174;
    LispObject fn;
    LispObject v_22911, v_22910, v_22909;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "redall");
    va_start(aa, nargs);
    v_22909 = va_arg(aa, LispObject);
    v_22910 = va_arg(aa, LispObject);
    v_22911 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22911,v_22910,v_22909);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22909,v_22910,v_22911);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_22911;
    v_23173 = v_22910;
    v_23172 = v_22909;
// end of prologue
// Binding gg!*
// FLUIDBIND: reloadenv=9 litvec-offset=1 saveloc=8
{   bind_fluid_stack bind_fluid_var(-9, 1, -8);
    qvalue(elt(env, 1)) = v_23172; // gg!*
    v_23172 = v_23173;
    stack[-6] = v_23172;
    v_23172 = nil;
    qvalue(elt(env, 2)) = v_23172; // shortway!*
    qvalue(elt(env, 3)) = v_23172; // thirdway!*
    v_23172 = lisp_true;
    stack[-1] = v_23172;
v_22930:
    v_23172 = stack[-6];
    if (v_23172 == nil) goto v_22933;
    else goto v_22934;
v_22933:
    goto v_22929;
v_22934:
    v_23172 = stack[-6];
    v_23172 = Lreverse(nil, v_23172);
    env = stack[-9];
    v_23172 = qcar(v_23172);
    stack[-5] = v_23172;
    goto v_22945;
v_22941:
    v_23173 = stack[-5];
    goto v_22942;
v_22943:
    v_23172 = stack[-6];
    goto v_22944;
v_22945:
    goto v_22941;
v_22942:
    goto v_22943;
v_22944:
    v_23172 = Ldelete(nil, v_23173, v_23172);
    env = stack[-9];
    stack[-6] = v_23172;
    v_23172 = stack[-5];
    v_23172 = qcar(v_23172);
    stack[-2] = v_23172;
    goto v_22954;
v_22950:
    v_23173 = qvalue(elt(env, 4)); // gv!*
    goto v_22951;
v_22952:
    v_23172 = stack[-2];
    goto v_22953;
v_22954:
    goto v_22950;
v_22951:
    goto v_22952;
v_22953:
    v_23172 = *(LispObject *)((char *)v_23173 + (CELL-TAG_VECTOR) + (((intptr_t)v_23172-TAG_FIXNUM)/(16/CELL)));
    stack[-4] = v_23172;
    v_23172 = qvalue(elt(env, 5)); // path
    if (v_23172 == nil) goto v_22961;
    v_23172 = stack[-1];
    if (v_23172 == nil) goto v_22966;
    v_23172 = stack[-4];
    fn = elt(env, 10); // ljet
    v_23172 = (*qfn1(fn))(fn, v_23172);
    env = stack[-9];
    v_23172 = Lprinc(nil, v_23172);
    env = stack[-9];
    v_23172 = elt(env, 6); // " ==> "
    v_23172 = Lprinc(nil, v_23172);
    env = stack[-9];
    goto v_22964;
v_22966:
    v_23172 = stack[-4];
    fn = elt(env, 10); // ljet
    v_23172 = (*qfn1(fn))(fn, v_23172);
    env = stack[-9];
    v_23172 = Lprinc(nil, v_23172);
    env = stack[-9];
    v_23172 = elt(env, 7); // " --> "
    v_23172 = Lprinc(nil, v_23172);
    env = stack[-9];
    goto v_22964;
v_22964:
    goto v_22959;
v_22961:
v_22959:
    goto v_22989;
v_22983:
    stack[-3] = qvalue(elt(env, 4)); // gv!*
    goto v_22984;
v_22985:
    stack[0] = stack[-2];
    goto v_22986;
v_22987:
    goto v_22999;
v_22993:
    v_23174 = stack[-4];
    goto v_22994;
v_22995:
    v_23173 = qvalue(elt(env, 1)); // gg!*
    goto v_22996;
v_22997:
    v_23172 = stack[-7];
    goto v_22998;
v_22999:
    goto v_22993;
v_22994:
    goto v_22995;
v_22996:
    goto v_22997;
v_22998:
    fn = elt(env, 11); // nf
    v_23172 = (*qfnn(fn))(fn, 3, v_23174, v_23173, v_23172);
    env = stack[-9];
    goto v_22988;
v_22989:
    goto v_22983;
v_22984:
    goto v_22985;
v_22986:
    goto v_22987;
v_22988:
    *(LispObject *)((char *)stack[-3] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_23172;
    stack[-5] = v_23172;
    v_23172 = stack[-5];
    if (v_23172 == nil) goto v_23006;
    v_23172 = stack[-5];
    fn = elt(env, 10); // ljet
    v_23172 = (*qfn1(fn))(fn, v_23172);
    env = stack[-9];
    goto v_23004;
v_23006:
    v_23172 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23004;
    v_23172 = nil;
v_23004:
    stack[-3] = v_23172;
    v_23172 = qvalue(elt(env, 5)); // path
    if (v_23172 == nil) goto v_23016;
    v_23172 = stack[-3];
    v_23172 = Lprinc(nil, v_23172);
    env = stack[-9];
    v_23172 = Lterpri(nil, 0);
    env = stack[-9];
    goto v_23014;
v_23016:
v_23014:
    v_23172 = stack[-5];
    if (v_23172 == nil) goto v_23024;
    else goto v_23025;
v_23024:
    goto v_23023;
v_23025:
    goto v_23034;
v_23030:
    v_23172 = stack[-3];
    fn = elt(env, 12); // ord
    v_23173 = (*qfn1(fn))(fn, v_23172);
    env = stack[-9];
    goto v_23031;
v_23032:
    v_23172 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23033;
v_23034:
    goto v_23030;
v_23031:
    goto v_23032;
v_23033:
    if (v_23173 == v_23172) goto v_23028;
    else goto v_23029;
v_23028:
    goto v_23043;
v_23039:
    v_23173 = stack[-5];
    goto v_23040;
v_23041:
    v_23172 = qvalue(elt(env, 8)); // conds!*
    goto v_23042;
v_23043:
    goto v_23039;
v_23040:
    goto v_23041;
v_23042:
    v_23172 = cons(v_23173, v_23172);
    env = stack[-9];
    qvalue(elt(env, 8)) = v_23172; // conds!*
    goto v_23023;
v_23029:
    goto v_23056;
v_23052:
    v_23172 = stack[-5];
    fn = elt(env, 10); // ljet
    stack[0] = (*qfn1(fn))(fn, v_23172);
    env = stack[-9];
    goto v_23053;
v_23054:
    v_23172 = stack[-4];
    fn = elt(env, 10); // ljet
    v_23172 = (*qfn1(fn))(fn, v_23172);
    env = stack[-9];
    goto v_23055;
v_23056:
    goto v_23052;
v_23053:
    goto v_23054;
v_23055:
    if (equal(stack[0], v_23172)) goto v_23051;
    v_23172 = lisp_true;
    qvalue(elt(env, 2)) = v_23172; // shortway!*
    goto v_23049;
v_23051:
v_23049:
    v_23172 = stack[-1];
    if (v_23172 == nil) goto v_23068;
    else goto v_23069;
v_23068:
    goto v_23076;
v_23072:
    v_23173 = stack[-5];
    goto v_23073;
v_23074:
    v_23172 = stack[-4];
    goto v_23075;
v_23076:
    goto v_23072;
v_23073:
    goto v_23074;
v_23075:
    v_23172 = Lneq(nil, v_23173, v_23172);
    env = stack[-9];
    goto v_23067;
v_23069:
    v_23172 = nil;
    goto v_23067;
    v_23172 = nil;
v_23067:
    if (v_23172 == nil) goto v_23065;
    v_23172 = lisp_true;
    qvalue(elt(env, 3)) = v_23172; // thirdway!*
    goto v_23063;
v_23065:
v_23063:
    v_23172 = qvalue(elt(env, 1)); // gg!*
    stack[-4] = v_23172;
v_23086:
    v_23172 = stack[-4];
    if (v_23172 == nil) goto v_23090;
    else goto v_23091;
v_23090:
    goto v_23085;
v_23091:
    v_23172 = stack[-4];
    v_23172 = qcar(v_23172);
    stack[-1] = v_23172;
    goto v_23106;
v_23102:
    goto v_23112;
v_23108:
    v_23173 = stack[-3];
    goto v_23109;
v_23110:
    v_23172 = stack[-1];
    v_23172 = qcdr(v_23172);
    goto v_23111;
v_23112:
    goto v_23108;
v_23109:
    goto v_23110;
v_23111:
    fn = elt(env, 13); // dd
    stack[0] = (*qfn2(fn))(fn, v_23173, v_23172);
    env = stack[-9];
    goto v_23103;
v_23104:
    goto v_23121;
v_23117:
    v_23173 = stack[-7];
    goto v_23118;
v_23119:
    v_23172 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_23120;
v_23121:
    goto v_23117;
v_23118:
    goto v_23119;
v_23120:
    v_23172 = plus2(v_23173, v_23172);
    env = stack[-9];
    goto v_23105;
v_23106:
    goto v_23102;
v_23103:
    goto v_23104;
v_23105:
    v_23172 = (LispObject)geq2(stack[0], v_23172);
    v_23172 = v_23172 ? lisp_true : nil;
    env = stack[-9];
    if (v_23172 == nil) goto v_23100;
    goto v_23129;
v_23125:
    v_23173 = stack[-1];
    goto v_23126;
v_23127:
    v_23172 = qvalue(elt(env, 1)); // gg!*
    goto v_23128;
v_23129:
    goto v_23125;
v_23126:
    goto v_23127;
v_23128:
    v_23172 = Ldelete(nil, v_23173, v_23172);
    env = stack[-9];
    qvalue(elt(env, 1)) = v_23172; // gg!*
    goto v_23137;
v_23133:
    v_23173 = stack[-1];
    goto v_23134;
v_23135:
    v_23172 = stack[-6];
    goto v_23136;
v_23137:
    goto v_23133;
v_23134:
    goto v_23135;
v_23136:
    fn = elt(env, 14); // insert
    v_23172 = (*qfn2(fn))(fn, v_23173, v_23172);
    env = stack[-9];
    stack[-6] = v_23172;
    goto v_23146;
v_23140:
    v_23174 = qvalue(elt(env, 9)); // bv!*
    goto v_23141;
v_23142:
    v_23172 = stack[-1];
    v_23173 = qcar(v_23172);
    goto v_23143;
v_23144:
    v_23172 = lisp_true;
    goto v_23145;
v_23146:
    goto v_23140;
v_23141:
    goto v_23142;
v_23143:
    goto v_23144;
v_23145:
    *(LispObject *)((char *)v_23174 + (CELL-TAG_VECTOR) + (((intptr_t)v_23173-TAG_FIXNUM)/(16/CELL))) = v_23172;
    goto v_23098;
v_23100:
v_23098:
    v_23172 = stack[-4];
    v_23172 = qcdr(v_23172);
    stack[-4] = v_23172;
    goto v_23086;
v_23085:
    goto v_23159;
v_23155:
    goto v_23165;
v_23161:
    v_23173 = stack[-2];
    goto v_23162;
v_23163:
    v_23172 = stack[-3];
    goto v_23164;
v_23165:
    goto v_23161;
v_23162:
    goto v_23163;
v_23164:
    v_23173 = cons(v_23173, v_23172);
    env = stack[-9];
    goto v_23156;
v_23157:
    v_23172 = qvalue(elt(env, 1)); // gg!*
    goto v_23158;
v_23159:
    goto v_23155;
v_23156:
    goto v_23157;
v_23158:
    fn = elt(env, 14); // insert
    v_23172 = (*qfn2(fn))(fn, v_23173, v_23172);
    env = stack[-9];
    qvalue(elt(env, 1)) = v_23172; // gg!*
    v_23172 = nil;
    stack[-1] = v_23172;
    goto v_23023;
v_23023:
    goto v_22930;
v_22929:
    v_23172 = qvalue(elt(env, 1)); // gg!*
    ;}  // end of a binding scope
    return onevalue(v_23172);
}



// Code for pa_list2vect

static LispObject CC_pa_list2vect(LispObject env,
                         LispObject v_22908, LispObject v_22909)
{
    env = qenv(env);
    LispObject v_23055, v_23056;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22908,v_22909);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_22909;
    stack[0] = v_22908;
// end of prologue
    stack[-4] = nil;
    v_23055 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_23055;
    v_23055 = stack[-5];
    v_23055 = sub1(v_23055);
    env = stack[-7];
    v_23055 = Lmkvect(nil, v_23055);
    env = stack[-7];
    stack[-6] = v_23055;
    v_23055 = stack[0];
    stack[-2] = v_23055;
v_22923:
    v_23055 = stack[-2];
    if (v_23055 == nil) goto v_22927;
    else goto v_22928;
v_22927:
    goto v_22922;
v_22928:
    v_23055 = stack[-2];
    v_23055 = qcar(v_23055);
    stack[0] = v_23055;
    goto v_22939;
v_22935:
    goto v_22946;
v_22942:
    v_23056 = elt(env, 1); // min
    goto v_22943;
v_22944:
    v_23055 = stack[0];
    goto v_22945;
v_22946:
    goto v_22942;
v_22943:
    goto v_22944;
v_22945:
    v_23055 = cons(v_23056, v_23055);
    env = stack[-7];
    fn = elt(env, 2); // eval
    v_23056 = (*qfn1(fn))(fn, v_23055);
    env = stack[-7];
    goto v_22936;
v_22937:
    v_23055 = stack[-4];
    goto v_22938;
v_22939:
    goto v_22935;
v_22936:
    goto v_22937;
v_22938:
    v_23055 = cons(v_23056, v_23055);
    env = stack[-7];
    stack[-4] = v_23055;
    v_23055 = stack[0];
    stack[-1] = v_23055;
v_22953:
    v_23055 = stack[-1];
    if (v_23055 == nil) goto v_22957;
    else goto v_22958;
v_22957:
    goto v_22952;
v_22958:
    v_23055 = stack[-1];
    v_23055 = qcar(v_23055);
    goto v_22970;
v_22964:
    stack[0] = stack[-6];
    goto v_22965;
v_22966:
    v_23056 = sub1(v_23055);
    env = stack[-7];
    goto v_22967;
v_22968:
    v_23055 = stack[-4];
    v_23055 = qcar(v_23055);
    goto v_22969;
v_22970:
    goto v_22964;
v_22965:
    goto v_22966;
v_22967:
    goto v_22968;
v_22969:
    *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_23056-TAG_FIXNUM)/(16/CELL))) = v_23055;
    v_23055 = stack[-1];
    v_23055 = qcdr(v_23055);
    stack[-1] = v_23055;
    goto v_22953;
v_22952:
    v_23055 = stack[-2];
    v_23055 = qcdr(v_23055);
    stack[-2] = v_23055;
    goto v_22923;
v_22922:
    v_23055 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_23055;
v_22984:
    goto v_22996;
v_22992:
    v_23056 = stack[-5];
    goto v_22993;
v_22994:
    v_23055 = stack[-1];
    goto v_22995;
v_22996:
    goto v_22992;
v_22993:
    goto v_22994;
v_22995:
    v_23055 = difference2(v_23056, v_23055);
    env = stack[-7];
    v_23055 = Lminusp(nil, v_23055);
    env = stack[-7];
    if (v_23055 == nil) goto v_22989;
    goto v_22983;
v_22989:
    goto v_23008;
v_23004:
    stack[0] = stack[-6];
    goto v_23005;
v_23006:
    v_23055 = stack[-1];
    v_23055 = sub1(v_23055);
    env = stack[-7];
    goto v_23007;
v_23008:
    goto v_23004;
v_23005:
    goto v_23006;
v_23007:
    v_23055 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_23055-TAG_FIXNUM)/(16/CELL)));
    if (v_23055 == nil) goto v_23002;
    else goto v_23003;
v_23002:
    goto v_23021;
v_23017:
    v_23056 = stack[-3];
    goto v_23018;
v_23019:
    v_23055 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23020;
v_23021:
    goto v_23017;
v_23018:
    goto v_23019;
v_23020:
    if (v_23056 == v_23055) goto v_23015;
    else goto v_23016;
v_23015:
    v_23055 = stack[-1];
    stack[-3] = v_23055;
    goto v_23030;
v_23026:
    v_23056 = stack[-3];
    goto v_23027;
v_23028:
    v_23055 = stack[-4];
    goto v_23029;
v_23030:
    goto v_23026;
v_23027:
    goto v_23028;
v_23029:
    v_23055 = cons(v_23056, v_23055);
    env = stack[-7];
    stack[-4] = v_23055;
    goto v_23014;
v_23016:
v_23014:
    goto v_23039;
v_23033:
    stack[0] = stack[-6];
    goto v_23034;
v_23035:
    v_23055 = stack[-1];
    v_23056 = sub1(v_23055);
    env = stack[-7];
    goto v_23036;
v_23037:
    v_23055 = stack[-3];
    goto v_23038;
v_23039:
    goto v_23033;
v_23034:
    goto v_23035;
v_23036:
    goto v_23037;
v_23038:
    *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_23056-TAG_FIXNUM)/(16/CELL))) = v_23055;
    goto v_23001;
v_23003:
v_23001:
    v_23055 = stack[-1];
    v_23055 = add1(v_23055);
    env = stack[-7];
    stack[-1] = v_23055;
    goto v_22984;
v_22983:
    goto v_23051;
v_23047:
    v_23055 = stack[-4];
    v_23056 = Lreverse(nil, v_23055);
    goto v_23048;
v_23049:
    v_23055 = stack[-6];
    goto v_23050;
v_23051:
    goto v_23047;
v_23048:
    goto v_23049;
v_23050:
    return cons(v_23056, v_23055);
    return onevalue(v_23055);
}



// Code for fd2q

static LispObject CC_fd2q(LispObject env,
                         LispObject v_22908)
{
    env = qenv(env);
    LispObject v_22989, v_22990;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22908);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22908;
// end of prologue
v_22912:
    v_22989 = stack[0];
    if (!consp(v_22989)) goto v_22915;
    else goto v_22916;
v_22915:
    goto v_22923;
v_22919:
    v_22990 = stack[0];
    goto v_22920;
v_22921:
    v_22989 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22922;
v_22923:
    goto v_22919;
v_22920:
    goto v_22921;
v_22922:
    return cons(v_22990, v_22989);
v_22916:
    goto v_22932;
v_22928:
    v_22989 = stack[0];
    v_22990 = qcar(v_22989);
    goto v_22929;
v_22930:
    v_22989 = elt(env, 1); // !:ar!:
    goto v_22931;
v_22932:
    goto v_22928;
v_22929:
    goto v_22930;
v_22931:
    if (v_22990 == v_22989) goto v_22926;
    else goto v_22927;
v_22926:
    v_22989 = stack[0];
    v_22989 = qcdr(v_22989);
    stack[0] = v_22989;
    goto v_22912;
v_22927:
    goto v_22944;
v_22940:
    v_22989 = stack[0];
    v_22990 = qcar(v_22989);
    goto v_22941;
v_22942:
    v_22989 = elt(env, 2); // !:rn!:
    goto v_22943;
v_22944:
    goto v_22940;
v_22941:
    goto v_22942;
v_22943:
    if (v_22990 == v_22989) goto v_22938;
    else goto v_22939;
v_22938:
    v_22989 = stack[0];
    v_22989 = qcdr(v_22989);
    goto v_22911;
v_22939:
    goto v_22957;
v_22953:
    goto v_22963;
v_22959:
    goto v_22969;
v_22965:
    goto v_22976;
v_22972:
    v_22989 = stack[0];
    v_22989 = qcar(v_22989);
    v_22990 = qcar(v_22989);
    goto v_22973;
v_22974:
    v_22989 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22975;
v_22976:
    goto v_22972;
v_22973:
    goto v_22974;
v_22975:
    v_22989 = cons(v_22990, v_22989);
    env = stack[-2];
    v_22990 = ncons(v_22989);
    env = stack[-2];
    goto v_22966;
v_22967:
    v_22989 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22968;
v_22969:
    goto v_22965;
v_22966:
    goto v_22967;
v_22968:
    stack[-1] = cons(v_22990, v_22989);
    env = stack[-2];
    goto v_22960;
v_22961:
    v_22989 = stack[0];
    v_22989 = qcar(v_22989);
    v_22989 = qcdr(v_22989);
    v_22989 = CC_fd2q(elt(env, 0), v_22989);
    env = stack[-2];
    goto v_22962;
v_22963:
    goto v_22959;
v_22960:
    goto v_22961;
v_22962:
    fn = elt(env, 3); // multsq
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_22989);
    env = stack[-2];
    goto v_22954;
v_22955:
    v_22989 = stack[0];
    v_22989 = qcdr(v_22989);
    v_22989 = CC_fd2q(elt(env, 0), v_22989);
    env = stack[-2];
    goto v_22956;
v_22957:
    goto v_22953;
v_22954:
    goto v_22955;
v_22956:
    {
        LispObject v_22993 = stack[-1];
        fn = elt(env, 4); // addsq
        return (*qfn2(fn))(fn, v_22993, v_22989);
    }
    v_22989 = nil;
v_22911:
    return onevalue(v_22989);
}



// Code for repr_new

static LispObject CC_repr_new(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22946, v_22947, v_22948, v_22949;
    LispObject fn;
    LispObject v_22911, v_22910, v_22909, v_22908;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "repr_new");
    va_start(aa, nargs);
    v_22908 = va_arg(aa, LispObject);
    v_22909 = va_arg(aa, LispObject);
    v_22910 = va_arg(aa, LispObject);
    v_22911 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_22911,v_22910,v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_22908,v_22909,v_22910,v_22911);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_22946 = v_22911;
    v_22947 = v_22910;
    v_22948 = v_22909;
    v_22949 = v_22908;
// end of prologue
    goto v_22922;
v_22914:
    stack[-3] = v_22949;
    goto v_22915;
v_22916:
    stack[-2] = v_22948;
    goto v_22917;
v_22918:
    stack[-1] = v_22947;
    goto v_22919;
v_22920:
    goto v_22931;
v_22927:
    stack[0] = v_22946;
    goto v_22928;
v_22929:
    v_22946 = v_22947;
    if (v_22946 == nil) goto v_22935;
    else goto v_22936;
v_22935:
    v_22946 = elt(env, 1); // "repr_new : invalid coefficient list"
    v_22946 = ncons(v_22946);
    env = stack[-4];
    fn = elt(env, 2); // rederr
    v_22946 = (*qfn1(fn))(fn, v_22946);
    env = stack[-4];
    goto v_22934;
v_22936:
    v_22946 = v_22947;
    v_22946 = qcar(v_22946);
    v_22946 = qcdr(v_22946);
    goto v_22934;
    v_22946 = nil;
v_22934:
    goto v_22930;
v_22931:
    goto v_22927;
v_22928:
    goto v_22929;
v_22930:
    v_22946 = list2(stack[0], v_22946);
    goto v_22921;
v_22922:
    goto v_22914;
v_22915:
    goto v_22916;
v_22917:
    goto v_22918;
v_22919:
    goto v_22920;
v_22921:
    {
        LispObject v_22954 = stack[-3];
        LispObject v_22955 = stack[-2];
        LispObject v_22956 = stack[-1];
        return list3star(v_22954, v_22955, v_22956, v_22946);
    }
}



// Code for rl_multsurep

static LispObject CC_rl_multsurep(LispObject env,
                         LispObject v_22908, LispObject v_22909)
{
    env = qenv(env);
    LispObject v_22926, v_22927;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22908,v_22909);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_22926 = v_22909;
    v_22927 = v_22908;
// end of prologue
    goto v_22916;
v_22912:
    stack[0] = qvalue(elt(env, 1)); // rl_multsurep!*
    goto v_22913;
v_22914:
    goto v_22923;
v_22919:
    goto v_22920;
v_22921:
    goto v_22922;
v_22923:
    goto v_22919;
v_22920:
    goto v_22921;
v_22922:
    v_22926 = list2(v_22927, v_22926);
    env = stack[-1];
    goto v_22915;
v_22916:
    goto v_22912;
v_22913:
    goto v_22914;
v_22915:
    {
        LispObject v_22929 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_22929, v_22926);
    }
}



// Code for intervalrd

static LispObject CC_intervalrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22964, v_22965;
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
    goto v_22919;
v_22915:
    v_22965 = qvalue(elt(env, 1)); // atts
    goto v_22916;
v_22917:
    v_22964 = elt(env, 2); // (closure)
    goto v_22918;
v_22919:
    goto v_22915;
v_22916:
    goto v_22917;
v_22918:
    fn = elt(env, 7); // retattributes
    v_22964 = (*qfn2(fn))(fn, v_22965, v_22964);
    env = stack[-4];
    stack[0] = v_22964;
    fn = elt(env, 8); // mathml
    v_22964 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-3] = v_22964;
    fn = elt(env, 8); // mathml
    v_22964 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[-2] = v_22964;
    fn = elt(env, 9); // lex
    v_22964 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_22933;
v_22929:
    v_22965 = qvalue(elt(env, 3)); // char
    goto v_22930;
v_22931:
    v_22964 = elt(env, 4); // (!/ i n t e r v a l)
    goto v_22932;
v_22933:
    goto v_22929;
v_22930:
    goto v_22931;
v_22932:
    if (equal(v_22965, v_22964)) goto v_22927;
    else goto v_22928;
v_22927:
    goto v_22943;
v_22937:
    stack[-1] = elt(env, 5); // interval
    goto v_22938;
v_22939:
    goto v_22940;
v_22941:
    goto v_22951;
v_22947:
    v_22965 = stack[-3];
    goto v_22948;
v_22949:
    v_22964 = stack[-2];
    goto v_22950;
v_22951:
    goto v_22947;
v_22948:
    goto v_22949;
v_22950:
    v_22964 = list2(v_22965, v_22964);
    goto v_22942;
v_22943:
    goto v_22937;
v_22938:
    goto v_22939;
v_22940:
    goto v_22941;
v_22942:
    {
        LispObject v_22970 = stack[-1];
        LispObject v_22971 = stack[0];
        return list2star(v_22970, v_22971, v_22964);
    }
v_22928:
    goto v_22961;
v_22957:
    v_22965 = elt(env, 6); // "</interval>"
    goto v_22958;
v_22959:
    v_22964 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_22960;
v_22961:
    goto v_22957;
v_22958:
    goto v_22959;
v_22960:
    fn = elt(env, 10); // errorml
    v_22964 = (*qfn2(fn))(fn, v_22965, v_22964);
    goto v_22926;
v_22926:
    v_22964 = nil;
    return onevalue(v_22964);
}



// Code for init

static LispObject CC_init(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22993;
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
    v_22993 = qvalue(elt(env, 1)); // fluidbibasisvariables
    v_22993 = Lreverse(nil, v_22993);
    env = stack[-7];
    qvalue(elt(env, 2)) = v_22993; // fluidbibasisreversedvariables
    fn = elt(env, 9); // initmonomials
    v_22993 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    v_22993 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_22993;
    v_22993 = qvalue(elt(env, 1)); // fluidbibasisvariables
    stack[-5] = v_22993;
    v_22993 = stack[-5];
    if (v_22993 == nil) goto v_22926;
    else goto v_22927;
v_22926:
    v_22993 = nil;
    goto v_22921;
v_22927:
    v_22993 = stack[-5];
    v_22993 = qcar(v_22993);
    goto v_22939;
v_22935:
    stack[-1] = v_22993;
    goto v_22936;
v_22937:
    goto v_22945;
v_22941:
    stack[0] = qvalue(elt(env, 3)); // fluidbibasissinglevariablemonomialss
    goto v_22942;
v_22943:
    v_22993 = stack[-6];
    v_22993 = add1(v_22993);
    env = stack[-7];
    stack[-6] = v_22993;
    goto v_22944;
v_22945:
    goto v_22941;
v_22942:
    goto v_22943;
v_22944:
    v_22993 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_22993-TAG_FIXNUM)/(16/CELL)));
    goto v_22938;
v_22939:
    goto v_22935;
v_22936:
    goto v_22937;
v_22938:
    v_22993 = cons(stack[-1], v_22993);
    env = stack[-7];
    v_22993 = ncons(v_22993);
    env = stack[-7];
    stack[-3] = v_22993;
    stack[-4] = v_22993;
v_22922:
    v_22993 = stack[-5];
    v_22993 = qcdr(v_22993);
    stack[-5] = v_22993;
    v_22993 = stack[-5];
    if (v_22993 == nil) goto v_22954;
    else goto v_22955;
v_22954:
    v_22993 = stack[-4];
    goto v_22921;
v_22955:
    goto v_22963;
v_22959:
    stack[-2] = stack[-3];
    goto v_22960;
v_22961:
    v_22993 = stack[-5];
    v_22993 = qcar(v_22993);
    goto v_22974;
v_22970:
    stack[-1] = v_22993;
    goto v_22971;
v_22972:
    goto v_22980;
v_22976:
    stack[0] = qvalue(elt(env, 3)); // fluidbibasissinglevariablemonomialss
    goto v_22977;
v_22978:
    v_22993 = stack[-6];
    v_22993 = add1(v_22993);
    env = stack[-7];
    stack[-6] = v_22993;
    goto v_22979;
v_22980:
    goto v_22976;
v_22977:
    goto v_22978;
v_22979:
    v_22993 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_22993-TAG_FIXNUM)/(16/CELL)));
    goto v_22973;
v_22974:
    goto v_22970;
v_22971:
    goto v_22972;
v_22973:
    v_22993 = cons(stack[-1], v_22993);
    env = stack[-7];
    v_22993 = ncons(v_22993);
    env = stack[-7];
    goto v_22962;
v_22963:
    goto v_22959;
v_22960:
    goto v_22961;
v_22962:
    v_22993 = Lrplacd(nil, stack[-2], v_22993);
    env = stack[-7];
    v_22993 = stack[-3];
    v_22993 = qcdr(v_22993);
    stack[-3] = v_22993;
    goto v_22922;
v_22921:
    qvalue(elt(env, 4)) = v_22993; // fluidbibasissinglevariablemonomialsa
    fn = elt(env, 10); // settreset
    v_22993 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    v_22993 = nil;
    v_22993 = ncons(v_22993);
    env = stack[-7];
    qvalue(elt(env, 5)) = v_22993; // fluidbibasissetq
    v_22993 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 6)) = v_22993; // fluidbibasisreductionsmade
    v_22993 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 7)) = v_22993; // fluidbibasisnormalforms
    v_22993 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 8)) = v_22993; // fluidbibasisnonzeronormalforms
    v_22993 = nil;
    return onevalue(v_22993);
}



// Code for fnreval

static LispObject CC_fnreval(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23036, v_23037;
    LispObject fn;
    LispObject v_22910, v_22909, v_22908;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "fnreval");
    va_start(aa, nargs);
    v_22908 = va_arg(aa, LispObject);
    v_22909 = va_arg(aa, LispObject);
    v_22910 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22910,v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22908,v_22909,v_22910);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_22910;
    stack[-1] = v_22909;
    stack[0] = v_22908;
// end of prologue
    stack[-2] = nil;
v_22915:
    v_23036 = stack[0];
    if (v_23036 == nil) goto v_22918;
    else goto v_22919;
v_22918:
    v_23036 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_23036);
    }
v_22919:
    goto v_22929;
v_22925:
    v_23037 = stack[-1];
    goto v_22926;
v_22927:
    v_23036 = lisp_true;
    goto v_22928;
v_22929:
    goto v_22925;
v_22926:
    goto v_22927;
v_22928:
    if (v_23037 == v_23036) goto v_22923;
    else goto v_22924;
v_22923:
    goto v_22937;
v_22933:
    v_23037 = stack[-2];
    goto v_22934;
v_22935:
    v_23036 = stack[0];
    goto v_22936;
v_22937:
    goto v_22933;
v_22934:
    goto v_22935;
v_22936:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_23037, v_23036);
    }
v_22924:
    v_23036 = stack[-1];
    if (v_23036 == nil) goto v_22940;
    else goto v_22941;
v_22940:
    goto v_22948;
v_22944:
    stack[-5] = stack[-2];
    goto v_22945;
v_22946:
    v_23036 = stack[0];
    stack[-3] = v_23036;
    v_23036 = stack[-3];
    if (v_23036 == nil) goto v_22959;
    else goto v_22960;
v_22959:
    v_23036 = nil;
    goto v_22954;
v_22960:
    v_23036 = stack[-3];
    v_23036 = qcar(v_23036);
    goto v_22972;
v_22968:
    v_23037 = v_23036;
    goto v_22969;
v_22970:
    v_23036 = stack[-4];
    goto v_22971;
v_22972:
    goto v_22968;
v_22969:
    goto v_22970;
v_22971:
    fn = elt(env, 2); // reval1
    v_23036 = (*qfn2(fn))(fn, v_23037, v_23036);
    env = stack[-6];
    v_23036 = ncons(v_23036);
    env = stack[-6];
    stack[-1] = v_23036;
    stack[-2] = v_23036;
v_22955:
    v_23036 = stack[-3];
    v_23036 = qcdr(v_23036);
    stack[-3] = v_23036;
    v_23036 = stack[-3];
    if (v_23036 == nil) goto v_22979;
    else goto v_22980;
v_22979:
    v_23036 = stack[-2];
    goto v_22954;
v_22980:
    goto v_22988;
v_22984:
    stack[0] = stack[-1];
    goto v_22985;
v_22986:
    v_23036 = stack[-3];
    v_23036 = qcar(v_23036);
    goto v_22999;
v_22995:
    v_23037 = v_23036;
    goto v_22996;
v_22997:
    v_23036 = stack[-4];
    goto v_22998;
v_22999:
    goto v_22995;
v_22996:
    goto v_22997;
v_22998:
    fn = elt(env, 2); // reval1
    v_23036 = (*qfn2(fn))(fn, v_23037, v_23036);
    env = stack[-6];
    v_23036 = ncons(v_23036);
    env = stack[-6];
    goto v_22987;
v_22988:
    goto v_22984;
v_22985:
    goto v_22986;
v_22987:
    v_23036 = Lrplacd(nil, stack[0], v_23036);
    env = stack[-6];
    v_23036 = stack[-1];
    v_23036 = qcdr(v_23036);
    stack[-1] = v_23036;
    goto v_22955;
v_22954:
    goto v_22947;
v_22948:
    goto v_22944;
v_22945:
    goto v_22946;
v_22947:
    {
        LispObject v_23044 = stack[-5];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_23044, v_23036);
    }
v_22941:
    goto v_23011;
v_23007:
    v_23036 = stack[-1];
    v_23036 = qcar(v_23036);
    if (v_23036 == nil) goto v_23015;
    v_23036 = stack[0];
    v_23036 = qcar(v_23036);
    v_23037 = v_23036;
    goto v_23013;
v_23015:
    goto v_23027;
v_23023:
    v_23036 = stack[0];
    v_23037 = qcar(v_23036);
    goto v_23024;
v_23025:
    v_23036 = stack[-4];
    goto v_23026;
v_23027:
    goto v_23023;
v_23024:
    goto v_23025;
v_23026:
    fn = elt(env, 2); // reval1
    v_23036 = (*qfn2(fn))(fn, v_23037, v_23036);
    env = stack[-6];
    v_23037 = v_23036;
    goto v_23013;
    v_23037 = nil;
v_23013:
    goto v_23008;
v_23009:
    v_23036 = stack[-2];
    goto v_23010;
v_23011:
    goto v_23007;
v_23008:
    goto v_23009;
v_23010:
    v_23036 = cons(v_23037, v_23036);
    env = stack[-6];
    stack[-2] = v_23036;
    v_23036 = stack[0];
    v_23036 = qcdr(v_23036);
    stack[0] = v_23036;
    v_23036 = stack[-1];
    v_23036 = qcdr(v_23036);
    stack[-1] = v_23036;
    goto v_22915;
    v_23036 = nil;
    return onevalue(v_23036);
}



// Code for vdpmember

static LispObject CC_vdpmember(LispObject env,
                         LispObject v_22908, LispObject v_22909)
{
    env = qenv(env);
    LispObject v_22936, v_22937;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22908,v_22909);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22909;
    stack[-1] = v_22908;
// end of prologue
v_22913:
    v_22936 = stack[0];
    if (v_22936 == nil) goto v_22916;
    else goto v_22917;
v_22916:
    v_22936 = nil;
    goto v_22912;
v_22917:
    goto v_22927;
v_22923:
    v_22937 = stack[-1];
    goto v_22924;
v_22925:
    v_22936 = stack[0];
    v_22936 = qcar(v_22936);
    goto v_22926;
v_22927:
    goto v_22923;
v_22924:
    goto v_22925;
v_22926:
    fn = elt(env, 1); // vdpequal
    v_22936 = (*qfn2(fn))(fn, v_22937, v_22936);
    env = stack[-2];
    if (v_22936 == nil) goto v_22921;
    v_22936 = stack[0];
    goto v_22912;
v_22921:
    v_22936 = stack[0];
    v_22936 = qcdr(v_22936);
    stack[0] = v_22936;
    goto v_22913;
    v_22936 = nil;
v_22912:
    return onevalue(v_22936);
}



// Code for exdf0

static LispObject CC_exdf0(LispObject env,
                         LispObject v_22908)
{
    env = qenv(env);
    LispObject v_22945, v_22946;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22908);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22908;
// end of prologue
    goto v_22915;
v_22911:
    goto v_22921;
v_22917:
    v_22945 = stack[0];
    v_22945 = qcar(v_22945);
    fn = elt(env, 1); // exdff0
    stack[-1] = (*qfn1(fn))(fn, v_22945);
    env = stack[-2];
    goto v_22918;
v_22919:
    goto v_22930;
v_22926:
    v_22945 = stack[0];
    v_22945 = qcdr(v_22945);
    fn = elt(env, 2); // negf
    v_22945 = (*qfn1(fn))(fn, v_22945);
    env = stack[-2];
    fn = elt(env, 1); // exdff0
    v_22946 = (*qfn1(fn))(fn, v_22945);
    env = stack[-2];
    goto v_22927;
v_22928:
    v_22945 = stack[0];
    goto v_22929;
v_22930:
    goto v_22926;
v_22927:
    goto v_22928;
v_22929:
    fn = elt(env, 3); // multpfsq
    v_22945 = (*qfn2(fn))(fn, v_22946, v_22945);
    env = stack[-2];
    goto v_22920;
v_22921:
    goto v_22917;
v_22918:
    goto v_22919;
v_22920:
    fn = elt(env, 4); // addpf
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_22945);
    env = stack[-2];
    goto v_22912;
v_22913:
    goto v_22941;
v_22937:
    v_22946 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22938;
v_22939:
    v_22945 = stack[0];
    v_22945 = qcdr(v_22945);
    goto v_22940;
v_22941:
    goto v_22937;
v_22938:
    goto v_22939;
v_22940:
    v_22945 = cons(v_22946, v_22945);
    env = stack[-2];
    goto v_22914;
v_22915:
    goto v_22911;
v_22912:
    goto v_22913;
v_22914:
    {
        LispObject v_22949 = stack[-1];
        fn = elt(env, 3); // multpfsq
        return (*qfn2(fn))(fn, v_22949, v_22945);
    }
}



// Code for getphystypeexpt

static LispObject CC_getphystypeexpt(LispObject env,
                         LispObject v_22908)
{
    env = qenv(env);
    LispObject v_22936, v_22937;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22908);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_22908;
// end of prologue
    v_22936 = stack[0];
    fn = elt(env, 2); // getphystypecar
    v_22936 = (*qfn1(fn))(fn, v_22936);
    env = stack[-1];
    v_22937 = v_22936;
    v_22936 = v_22937;
    if (v_22936 == nil) goto v_22917;
    else goto v_22918;
v_22917:
    v_22936 = nil;
    goto v_22916;
v_22918:
    v_22936 = stack[0];
    v_22936 = qcdr(v_22936);
    v_22936 = qcar(v_22936);
    if (is_number(v_22936)) goto v_22923;
    else goto v_22922;
v_22923:
    v_22936 = stack[0];
    v_22936 = qcdr(v_22936);
    v_22936 = qcar(v_22936);
    v_22936 = Levenp(nil, v_22936);
    env = stack[-1];
    if (v_22936 == nil) goto v_22922;
    v_22936 = elt(env, 1); // scalar
    goto v_22916;
v_22922:
    v_22936 = v_22937;
    goto v_22916;
    v_22936 = nil;
v_22916:
    return onevalue(v_22936);
}



// Code for cvitimes2

static LispObject CC_cvitimes2(LispObject env,
                         LispObject v_22908, LispObject v_22909)
{
    env = qenv(env);
    LispObject v_22971, v_22972, v_22973, v_22974;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22973 = v_22909;
    v_22974 = v_22908;
// end of prologue
    goto v_22923;
v_22919:
    v_22972 = v_22974;
    goto v_22920;
v_22921:
    v_22971 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22922;
v_22923:
    goto v_22919;
v_22920:
    goto v_22921;
v_22922:
    if (v_22972 == v_22971) goto v_22917;
    else goto v_22918;
v_22917:
    v_22971 = lisp_true;
    goto v_22916;
v_22918:
    goto v_22933;
v_22929:
    v_22972 = v_22973;
    goto v_22930;
v_22931:
    v_22971 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22932;
v_22933:
    goto v_22929;
v_22930:
    goto v_22931;
v_22932:
    v_22971 = (v_22972 == v_22971 ? lisp_true : nil);
    goto v_22916;
    v_22971 = nil;
v_22916:
    if (v_22971 == nil) goto v_22914;
    v_22971 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22912;
v_22914:
    goto v_22944;
v_22940:
    v_22972 = v_22974;
    goto v_22941;
v_22942:
    v_22971 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22943;
v_22944:
    goto v_22940;
v_22941:
    goto v_22942;
v_22943:
    if (v_22972 == v_22971) goto v_22938;
    else goto v_22939;
v_22938:
    v_22971 = v_22973;
    goto v_22912;
v_22939:
    goto v_22954;
v_22950:
    v_22972 = v_22973;
    goto v_22951;
v_22952:
    v_22971 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22953;
v_22954:
    goto v_22950;
v_22951:
    goto v_22952;
v_22953:
    if (v_22972 == v_22971) goto v_22948;
    else goto v_22949;
v_22948:
    v_22971 = v_22974;
    goto v_22912;
v_22949:
    goto v_22967;
v_22961:
    v_22971 = elt(env, 1); // times
    goto v_22962;
v_22963:
    v_22972 = v_22974;
    goto v_22964;
v_22965:
    goto v_22966;
v_22967:
    goto v_22961;
v_22962:
    goto v_22963;
v_22964:
    goto v_22965;
v_22966:
    return list3(v_22971, v_22972, v_22973);
    v_22971 = nil;
v_22912:
    return onevalue(v_22971);
}



// Code for get!-current!-representation

static LispObject CC_getKcurrentKrepresentation(LispObject env,
                         LispObject v_22908)
{
    env = qenv(env);
    LispObject v_22918, v_22919;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22918 = v_22908;
// end of prologue
    goto v_22915;
v_22911:
    goto v_22912;
v_22913:
    v_22919 = elt(env, 1); // currep
    goto v_22914;
v_22915:
    goto v_22911;
v_22912:
    goto v_22913;
v_22914:
    return get(v_22918, v_22919);
}



// Code for basic!-kern

static LispObject CC_basicKkern(LispObject env,
                         LispObject v_22908)
{
    env = qenv(env);
    LispObject v_22938, v_22939;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22908);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_22939 = v_22908;
// end of prologue
    v_22938 = nil;
    stack[-1] = v_22938;
    v_22938 = v_22939;
    stack[0] = v_22938;
v_22915:
    v_22938 = stack[0];
    if (v_22938 == nil) goto v_22919;
    else goto v_22920;
v_22919:
    goto v_22914;
v_22920:
    v_22938 = stack[0];
    v_22938 = qcar(v_22938);
    goto v_22931;
v_22927:
    fn = elt(env, 1); // basic!-kern1
    v_22939 = (*qfn1(fn))(fn, v_22938);
    env = stack[-2];
    goto v_22928;
v_22929:
    v_22938 = stack[-1];
    goto v_22930;
v_22931:
    goto v_22927;
v_22928:
    goto v_22929;
v_22930:
    fn = elt(env, 2); // union
    v_22938 = (*qfn2(fn))(fn, v_22939, v_22938);
    env = stack[-2];
    stack[-1] = v_22938;
    v_22938 = stack[0];
    v_22938 = qcdr(v_22938);
    stack[0] = v_22938;
    goto v_22915;
v_22914:
    v_22938 = stack[-1];
    return onevalue(v_22938);
}



// Code for lalr_set_nonterminal_codes

static LispObject CC_lalr_set_nonterminal_codes(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22998, v_22999, v_23000;
    argcheck(nargs, 0, "lalr_set_nonterminal_codes");
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
    v_22998 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_22998;
    v_22998 = qvalue(elt(env, 1)); // nonterminals
    stack[-1] = v_22998;
v_22916:
    v_22998 = stack[-1];
    if (v_22998 == nil) goto v_22920;
    else goto v_22921;
v_22920:
    goto v_22915;
v_22921:
    v_22998 = stack[-1];
    v_22998 = qcar(v_22998);
    stack[0] = v_22998;
    goto v_22935;
v_22931:
    v_22999 = stack[0];
    goto v_22932;
v_22933:
    v_22998 = elt(env, 2); // !S!'
    goto v_22934;
v_22935:
    goto v_22931;
v_22932:
    goto v_22933;
v_22934:
    if (v_22999 == v_22998) goto v_22929;
    else goto v_22930;
v_22929:
    goto v_22945;
v_22939:
    v_23000 = stack[0];
    goto v_22940;
v_22941:
    v_22999 = elt(env, 3); // lalr_nonterminal_code
    goto v_22942;
v_22943:
    v_22998 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_22944;
v_22945:
    goto v_22939;
v_22940:
    goto v_22941;
v_22942:
    goto v_22943;
v_22944:
    v_22998 = Lputprop(nil, 3, v_23000, v_22999, v_22998);
    env = stack[-3];
    goto v_22928;
v_22930:
    goto v_22958;
v_22952:
    v_23000 = stack[0];
    goto v_22953;
v_22954:
    v_22999 = elt(env, 3); // lalr_nonterminal_code
    goto v_22955;
v_22956:
    v_22998 = stack[-2];
    goto v_22957;
v_22958:
    goto v_22952;
v_22953:
    goto v_22954;
v_22955:
    goto v_22956;
v_22957:
    v_22998 = Lputprop(nil, 3, v_23000, v_22999, v_22998);
    env = stack[-3];
    v_22998 = qvalue(elt(env, 4)); // !*lalr_verbose
    if (v_22998 == nil) goto v_22965;
    goto v_22974;
v_22968:
    v_23000 = stack[-2];
    goto v_22969;
v_22970:
    v_22999 = stack[0];
    goto v_22971;
v_22972:
    v_22998 = qvalue(elt(env, 5)); // nonterminal_codes
    goto v_22973;
v_22974:
    goto v_22968;
v_22969:
    goto v_22970;
v_22971:
    goto v_22972;
v_22973:
    v_22998 = acons(v_23000, v_22999, v_22998);
    env = stack[-3];
    qvalue(elt(env, 5)) = v_22998; // nonterminal_codes
    goto v_22963;
v_22965:
v_22963:
    v_22998 = stack[-2];
    v_22998 = add1(v_22998);
    env = stack[-3];
    stack[-2] = v_22998;
    goto v_22928;
v_22928:
    v_22998 = stack[-1];
    v_22998 = qcdr(v_22998);
    stack[-1] = v_22998;
    goto v_22916;
v_22915:
    v_22998 = qvalue(elt(env, 4)); // !*lalr_verbose
    if (v_22998 == nil) goto v_22985;
    goto v_22994;
v_22988:
    v_23000 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_22989;
v_22990:
    v_22999 = elt(env, 2); // !S!'
    goto v_22991;
v_22992:
    v_22998 = qvalue(elt(env, 5)); // nonterminal_codes
    goto v_22993;
v_22994:
    goto v_22988;
v_22989:
    goto v_22990;
v_22991:
    goto v_22992;
v_22993:
    v_22998 = acons(v_23000, v_22999, v_22998);
    env = stack[-3];
    qvalue(elt(env, 5)) = v_22998; // nonterminal_codes
    goto v_22983;
v_22985:
v_22983:
    v_22998 = nil;
    return onevalue(v_22998);
}



// Code for polynomread

static LispObject CC_polynomread(LispObject env,
                         LispObject v_22908)
{
    env = qenv(env);
    LispObject v_23031, v_23032, v_23033;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22908);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22908;
// end of prologue
    v_23031 = stack[0];
    if (v_23031 == nil) goto v_22912;
    else goto v_22913;
v_22912:
    v_23031 = nil;
    return ncons(v_23031);
v_22913:
    v_23031 = stack[0];
    if (!consp(v_23031)) goto v_22921;
    else goto v_22922;
v_22921:
    v_23031 = lisp_true;
    goto v_22920;
v_22922:
    v_23031 = stack[0];
    v_23031 = qcar(v_23031);
    v_23031 = (consp(v_23031) ? nil : lisp_true);
    goto v_22920;
    v_23031 = nil;
v_22920:
    if (v_23031 == nil) goto v_22918;
    goto v_22939;
v_22935:
    goto v_22945;
v_22941:
    v_23032 = stack[0];
    goto v_22942;
v_22943:
    v_23031 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_22944;
v_22945:
    goto v_22941;
v_22942:
    goto v_22943;
v_22944:
    v_23032 = Cremainder(v_23032, v_23031);
    env = stack[-2];
    goto v_22936;
v_22937:
    v_23031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22938;
v_22939:
    goto v_22935;
v_22936:
    goto v_22937;
v_22938:
    v_23031 = Leqn(nil, v_23032, v_23031);
    env = stack[-2];
    if (v_23031 == nil) goto v_22933;
    goto v_22956;
v_22950:
    fn = elt(env, 3); // createmonomunit
    v_23033 = (*qfnn(fn))(fn, 0);
    goto v_22951;
v_22952:
    v_23032 = nil;
    goto v_22953;
v_22954:
    v_23031 = nil;
    goto v_22955;
v_22956:
    goto v_22950;
v_22951:
    goto v_22952;
v_22953:
    goto v_22954;
v_22955:
    return list2star(v_23033, v_23032, v_23031);
v_22933:
    v_23031 = nil;
    return ncons(v_23031);
    v_23031 = nil;
    goto v_22911;
v_22918:
    goto v_22970;
v_22966:
    v_23031 = stack[0];
    v_23031 = qcar(v_23031);
    v_23031 = qcar(v_23031);
    v_23032 = qcar(v_23031);
    goto v_22967;
v_22968:
    v_23031 = qvalue(elt(env, 1)); // fluidbibasisvariables
    goto v_22969;
v_22970:
    goto v_22966;
v_22967:
    goto v_22968;
v_22969:
    v_23031 = Lmember(nil, v_23032, v_23031);
    if (v_23031 == nil) goto v_22965;
    goto v_22982;
v_22978:
    goto v_22988;
v_22984:
    v_23031 = stack[0];
    v_23031 = qcar(v_23031);
    v_23031 = qcdr(v_23031);
    v_23033 = CC_polynomread(elt(env, 0), v_23031);
    env = stack[-2];
    goto v_22985;
v_22986:
    goto v_22997;
v_22993:
    v_23031 = stack[0];
    v_23031 = qcar(v_23031);
    v_23031 = qcar(v_23031);
    v_23032 = qcar(v_23031);
    goto v_22994;
v_22995:
    v_23031 = qvalue(elt(env, 2)); // fluidbibasissinglevariablemonomialsa
    goto v_22996;
v_22997:
    goto v_22993;
v_22994:
    goto v_22995;
v_22996:
    v_23031 = Lassoc(nil, v_23032, v_23031);
    v_23031 = qcdr(v_23031);
    goto v_22987;
v_22988:
    goto v_22984;
v_22985:
    goto v_22986;
v_22987:
    fn = elt(env, 4); // polynommultiplybymonom
    stack[-1] = (*qfn2(fn))(fn, v_23033, v_23031);
    env = stack[-2];
    goto v_22979;
v_22980:
    v_23031 = stack[0];
    v_23031 = qcdr(v_23031);
    v_23031 = CC_polynomread(elt(env, 0), v_23031);
    env = stack[-2];
    goto v_22981;
v_22982:
    goto v_22978;
v_22979:
    goto v_22980;
v_22981:
    {
        LispObject v_23036 = stack[-1];
        fn = elt(env, 5); // polynomadd
        return (*qfn2(fn))(fn, v_23036, v_23031);
    }
v_22965:
    goto v_23015;
v_23011:
    goto v_23021;
v_23017:
    v_23031 = stack[0];
    v_23031 = qcar(v_23031);
    v_23031 = qcdr(v_23031);
    stack[-1] = CC_polynomread(elt(env, 0), v_23031);
    env = stack[-2];
    goto v_23018;
v_23019:
    fn = elt(env, 3); // createmonomunit
    v_23031 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_23020;
v_23021:
    goto v_23017;
v_23018:
    goto v_23019;
v_23020:
    fn = elt(env, 4); // polynommultiplybymonom
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_23031);
    env = stack[-2];
    goto v_23012;
v_23013:
    v_23031 = stack[0];
    v_23031 = qcdr(v_23031);
    v_23031 = CC_polynomread(elt(env, 0), v_23031);
    env = stack[-2];
    goto v_23014;
v_23015:
    goto v_23011;
v_23012:
    goto v_23013;
v_23014:
    fn = elt(env, 5); // polynomadd
    v_23031 = (*qfn2(fn))(fn, stack[-1], v_23031);
    v_23031 = nil;
    goto v_22911;
    v_23031 = nil;
v_22911:
    return onevalue(v_23031);
}



// Code for ofsf_evalatp

static LispObject CC_ofsf_evalatp(LispObject env,
                         LispObject v_22908, LispObject v_22909)
{
    env = qenv(env);
    LispObject v_23003, v_23004, v_23005;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22908,v_22909);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_22909;
    v_23005 = v_22908;
// end of prologue
    goto v_22919;
v_22915:
    v_23004 = v_23005;
    goto v_22916;
v_22917:
    v_23003 = elt(env, 1); // equal
    goto v_22918;
v_22919:
    goto v_22915;
v_22916:
    goto v_22917;
v_22918:
    if (v_23004 == v_23003) goto v_22913;
    else goto v_22914;
v_22913:
    v_23003 = stack[0];
    v_23003 = (v_23003 == nil ? lisp_true : nil);
    goto v_22912;
v_22914:
    goto v_22930;
v_22926:
    v_23004 = v_23005;
    goto v_22927;
v_22928:
    v_23003 = elt(env, 2); // neq
    goto v_22929;
v_22930:
    goto v_22926;
v_22927:
    goto v_22928;
v_22929:
    if (v_23004 == v_23003) goto v_22924;
    else goto v_22925;
v_22924:
    v_23003 = stack[0];
    v_23003 = (v_23003 == nil ? lisp_true : nil);
    v_23003 = (v_23003 == nil ? lisp_true : nil);
    goto v_22912;
v_22925:
    goto v_22942;
v_22938:
    v_23004 = v_23005;
    goto v_22939;
v_22940:
    v_23003 = elt(env, 3); // leq
    goto v_22941;
v_22942:
    goto v_22938;
v_22939:
    goto v_22940;
v_22941:
    if (v_23004 == v_23003) goto v_22936;
    else goto v_22937;
v_22936:
    v_23003 = stack[0];
    fn = elt(env, 8); // minusf
    v_23003 = (*qfn1(fn))(fn, v_23003);
    if (v_23003 == nil) goto v_22947;
    else goto v_22946;
v_22947:
    v_23003 = stack[0];
    v_23003 = (v_23003 == nil ? lisp_true : nil);
v_22946:
    goto v_22912;
v_22937:
    goto v_22958;
v_22954:
    v_23004 = v_23005;
    goto v_22955;
v_22956:
    v_23003 = elt(env, 4); // geq
    goto v_22957;
v_22958:
    goto v_22954;
v_22955:
    goto v_22956;
v_22957:
    if (v_23004 == v_23003) goto v_22952;
    else goto v_22953;
v_22952:
    v_23003 = stack[0];
    fn = elt(env, 8); // minusf
    v_23003 = (*qfn1(fn))(fn, v_23003);
    v_23003 = (v_23003 == nil ? lisp_true : nil);
    goto v_22912;
v_22953:
    goto v_22970;
v_22966:
    v_23004 = v_23005;
    goto v_22967;
v_22968:
    v_23003 = elt(env, 5); // lessp
    goto v_22969;
v_22970:
    goto v_22966;
v_22967:
    goto v_22968;
v_22969:
    if (v_23004 == v_23003) goto v_22964;
    else goto v_22965;
v_22964:
    v_23003 = stack[0];
    {
        fn = elt(env, 8); // minusf
        return (*qfn1(fn))(fn, v_23003);
    }
v_22965:
    goto v_22981;
v_22977:
    v_23004 = v_23005;
    goto v_22978;
v_22979:
    v_23003 = elt(env, 6); // greaterp
    goto v_22980;
v_22981:
    goto v_22977;
v_22978:
    goto v_22979;
v_22980:
    if (v_23004 == v_23003) goto v_22975;
    else goto v_22976;
v_22975:
    v_23003 = stack[0];
    fn = elt(env, 8); // minusf
    v_23003 = (*qfn1(fn))(fn, v_23003);
    if (v_23003 == nil) goto v_22986;
    else goto v_22985;
v_22986:
    v_23003 = stack[0];
    v_23003 = (v_23003 == nil ? lisp_true : nil);
v_22985:
    v_23003 = (v_23003 == nil ? lisp_true : nil);
    goto v_22912;
v_22976:
    goto v_23000;
v_22996:
    v_23003 = elt(env, 7); // "ofsf_evalatp: unknown operator "
    goto v_22997;
v_22998:
    v_23004 = v_23005;
    goto v_22999;
v_23000:
    goto v_22996;
v_22997:
    goto v_22998;
v_22999:
    v_23003 = list2(v_23003, v_23004);
    env = stack[-1];
    {
        fn = elt(env, 9); // rederr
        return (*qfn1(fn))(fn, v_23003);
    }
    v_23003 = nil;
v_22912:
    return onevalue(v_23003);
}



// Code for mk!+mat!+plus!+mat

static LispObject CC_mkLmatLplusLmat(LispObject env,
                         LispObject v_22908, LispObject v_22909)
{
    env = qenv(env);
    LispObject v_23244, v_23245, v_23246;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22908,v_22909);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(14);
// copy arguments values to proper place
    stack[-10] = v_22909;
    stack[-11] = v_22908;
// end of prologue
    v_23244 = stack[-11];
    fn = elt(env, 4); // matrix!+p
    v_23244 = (*qfn1(fn))(fn, v_23244);
    env = stack[-13];
    if (v_23244 == nil) goto v_22921;
    else goto v_22922;
v_22921:
    v_23244 = elt(env, 1); // "no matrix in add"
    fn = elt(env, 5); // rederr
    v_23244 = (*qfn1(fn))(fn, v_23244);
    env = stack[-13];
    goto v_22920;
v_22922:
v_22920:
    v_23244 = stack[-10];
    fn = elt(env, 4); // matrix!+p
    v_23244 = (*qfn1(fn))(fn, v_23244);
    env = stack[-13];
    if (v_23244 == nil) goto v_22929;
    else goto v_22930;
v_22929:
    v_23244 = elt(env, 1); // "no matrix in add"
    fn = elt(env, 5); // rederr
    v_23244 = (*qfn1(fn))(fn, v_23244);
    env = stack[-13];
    goto v_22928;
v_22930:
v_22928:
    v_23244 = stack[-11];
    fn = elt(env, 6); // get!+col!+nr
    v_23244 = (*qfn1(fn))(fn, v_23244);
    env = stack[-13];
    stack[-12] = v_23244;
    v_23244 = stack[-11];
    fn = elt(env, 7); // get!+row!+nr
    v_23244 = (*qfn1(fn))(fn, v_23244);
    env = stack[-13];
    stack[-9] = v_23244;
    goto v_22947;
v_22943:
    stack[0] = stack[-12];
    goto v_22944;
v_22945:
    v_23244 = stack[-10];
    fn = elt(env, 6); // get!+col!+nr
    v_23244 = (*qfn1(fn))(fn, v_23244);
    env = stack[-13];
    goto v_22946;
v_22947:
    goto v_22943;
v_22944:
    goto v_22945;
v_22946:
    if (equal(stack[0], v_23244)) goto v_22942;
    v_23244 = elt(env, 2); // "wrong dimensions in add"
    fn = elt(env, 5); // rederr
    v_23244 = (*qfn1(fn))(fn, v_23244);
    env = stack[-13];
    goto v_22940;
v_22942:
v_22940:
    goto v_22961;
v_22957:
    stack[0] = stack[-9];
    goto v_22958;
v_22959:
    v_23244 = stack[-10];
    fn = elt(env, 7); // get!+row!+nr
    v_23244 = (*qfn1(fn))(fn, v_23244);
    env = stack[-13];
    goto v_22960;
v_22961:
    goto v_22957;
v_22958:
    goto v_22959;
v_22960:
    if (equal(stack[0], v_23244)) goto v_22956;
    v_23244 = elt(env, 2); // "wrong dimensions in add"
    fn = elt(env, 5); // rederr
    v_23244 = (*qfn1(fn))(fn, v_23244);
    env = stack[-13];
    goto v_22954;
v_22956:
v_22954:
    v_23244 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_23244;
    goto v_22984;
v_22980:
    v_23245 = stack[-9];
    goto v_22981;
v_22982:
    v_23244 = stack[-8];
    goto v_22983;
v_22984:
    goto v_22980;
v_22981:
    goto v_22982;
v_22983:
    v_23244 = difference2(v_23245, v_23244);
    env = stack[-13];
    v_23244 = Lminusp(nil, v_23244);
    env = stack[-13];
    if (v_23244 == nil) goto v_22977;
    v_23244 = nil;
    goto v_22971;
v_22977:
    v_23244 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_23244;
    goto v_23006;
v_23002:
    v_23245 = stack[-12];
    goto v_23003;
v_23004:
    v_23244 = stack[-4];
    goto v_23005;
v_23006:
    goto v_23002;
v_23003:
    goto v_23004;
v_23005:
    v_23244 = difference2(v_23245, v_23244);
    env = stack[-13];
    v_23244 = Lminusp(nil, v_23244);
    env = stack[-13];
    if (v_23244 == nil) goto v_22999;
    v_23244 = nil;
    goto v_22993;
v_22999:
    goto v_23016;
v_23012:
    goto v_23024;
v_23018:
    v_23246 = stack[-11];
    goto v_23019;
v_23020:
    v_23245 = stack[-8];
    goto v_23021;
v_23022:
    v_23244 = stack[-4];
    goto v_23023;
v_23024:
    goto v_23018;
v_23019:
    goto v_23020;
v_23021:
    goto v_23022;
v_23023:
    fn = elt(env, 8); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(fn, 3, v_23246, v_23245, v_23244);
    env = stack[-13];
    goto v_23013;
v_23014:
    goto v_23035;
v_23029:
    v_23246 = stack[-10];
    goto v_23030;
v_23031:
    v_23245 = stack[-8];
    goto v_23032;
v_23033:
    v_23244 = stack[-4];
    goto v_23034;
v_23035:
    goto v_23029;
v_23030:
    goto v_23031;
v_23032:
    goto v_23033;
v_23034:
    fn = elt(env, 8); // get!+mat!+entry
    v_23244 = (*qfnn(fn))(fn, 3, v_23246, v_23245, v_23244);
    env = stack[-13];
    goto v_23015;
v_23016:
    goto v_23012;
v_23013:
    goto v_23014;
v_23015:
    fn = elt(env, 9); // addsq
    v_23244 = (*qfn2(fn))(fn, stack[0], v_23244);
    env = stack[-13];
    v_23245 = v_23244;
    v_23244 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=13 litvec-offset=3 saveloc=0
{   bind_fluid_stack bind_fluid_var(-13, 3, 0);
    qvalue(elt(env, 3)) = v_23244; // !*sub2
    v_23244 = v_23245;
    fn = elt(env, 10); // subs2
    v_23244 = (*qfn1(fn))(fn, v_23244);
    env = stack[-13];
    v_23245 = v_23244;
    ;}  // end of a binding scope
    v_23244 = v_23245;
    v_23244 = ncons(v_23244);
    env = stack[-13];
    stack[-2] = v_23244;
    stack[-3] = v_23244;
v_22994:
    v_23244 = stack[-4];
    v_23244 = add1(v_23244);
    env = stack[-13];
    stack[-4] = v_23244;
    goto v_23056;
v_23052:
    v_23245 = stack[-12];
    goto v_23053;
v_23054:
    v_23244 = stack[-4];
    goto v_23055;
v_23056:
    goto v_23052;
v_23053:
    goto v_23054;
v_23055:
    v_23244 = difference2(v_23245, v_23244);
    env = stack[-13];
    v_23244 = Lminusp(nil, v_23244);
    env = stack[-13];
    if (v_23244 == nil) goto v_23049;
    v_23244 = stack[-3];
    goto v_22993;
v_23049:
    goto v_23065;
v_23061:
    stack[-1] = stack[-2];
    goto v_23062;
v_23063:
    goto v_23073;
v_23069:
    goto v_23081;
v_23075:
    v_23246 = stack[-11];
    goto v_23076;
v_23077:
    v_23245 = stack[-8];
    goto v_23078;
v_23079:
    v_23244 = stack[-4];
    goto v_23080;
v_23081:
    goto v_23075;
v_23076:
    goto v_23077;
v_23078:
    goto v_23079;
v_23080:
    fn = elt(env, 8); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(fn, 3, v_23246, v_23245, v_23244);
    env = stack[-13];
    goto v_23070;
v_23071:
    goto v_23092;
v_23086:
    v_23246 = stack[-10];
    goto v_23087;
v_23088:
    v_23245 = stack[-8];
    goto v_23089;
v_23090:
    v_23244 = stack[-4];
    goto v_23091;
v_23092:
    goto v_23086;
v_23087:
    goto v_23088;
v_23089:
    goto v_23090;
v_23091:
    fn = elt(env, 8); // get!+mat!+entry
    v_23244 = (*qfnn(fn))(fn, 3, v_23246, v_23245, v_23244);
    env = stack[-13];
    goto v_23072;
v_23073:
    goto v_23069;
v_23070:
    goto v_23071;
v_23072:
    fn = elt(env, 9); // addsq
    v_23244 = (*qfn2(fn))(fn, stack[0], v_23244);
    env = stack[-13];
    v_23245 = v_23244;
    v_23244 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=13 litvec-offset=3 saveloc=0
{   bind_fluid_stack bind_fluid_var(-13, 3, 0);
    qvalue(elt(env, 3)) = v_23244; // !*sub2
    v_23244 = v_23245;
    fn = elt(env, 10); // subs2
    v_23244 = (*qfn1(fn))(fn, v_23244);
    env = stack[-13];
    v_23245 = v_23244;
    ;}  // end of a binding scope
    v_23244 = v_23245;
    v_23244 = ncons(v_23244);
    env = stack[-13];
    goto v_23064;
v_23065:
    goto v_23061;
v_23062:
    goto v_23063;
v_23064:
    v_23244 = Lrplacd(nil, stack[-1], v_23244);
    env = stack[-13];
    v_23244 = stack[-2];
    v_23244 = qcdr(v_23244);
    stack[-2] = v_23244;
    goto v_22994;
v_22993:
    v_23244 = ncons(v_23244);
    env = stack[-13];
    stack[-6] = v_23244;
    stack[-7] = v_23244;
v_22972:
    v_23244 = stack[-8];
    v_23244 = add1(v_23244);
    env = stack[-13];
    stack[-8] = v_23244;
    goto v_23115;
v_23111:
    v_23245 = stack[-9];
    goto v_23112;
v_23113:
    v_23244 = stack[-8];
    goto v_23114;
v_23115:
    goto v_23111;
v_23112:
    goto v_23113;
v_23114:
    v_23244 = difference2(v_23245, v_23244);
    env = stack[-13];
    v_23244 = Lminusp(nil, v_23244);
    env = stack[-13];
    if (v_23244 == nil) goto v_23108;
    v_23244 = stack[-7];
    goto v_22971;
v_23108:
    goto v_23124;
v_23120:
    stack[-5] = stack[-6];
    goto v_23121;
v_23122:
    v_23244 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_23244;
    goto v_23144;
v_23140:
    v_23245 = stack[-12];
    goto v_23141;
v_23142:
    v_23244 = stack[-4];
    goto v_23143;
v_23144:
    goto v_23140;
v_23141:
    goto v_23142;
v_23143:
    v_23244 = difference2(v_23245, v_23244);
    env = stack[-13];
    v_23244 = Lminusp(nil, v_23244);
    env = stack[-13];
    if (v_23244 == nil) goto v_23137;
    v_23244 = nil;
    goto v_23131;
v_23137:
    goto v_23154;
v_23150:
    goto v_23162;
v_23156:
    v_23246 = stack[-11];
    goto v_23157;
v_23158:
    v_23245 = stack[-8];
    goto v_23159;
v_23160:
    v_23244 = stack[-4];
    goto v_23161;
v_23162:
    goto v_23156;
v_23157:
    goto v_23158;
v_23159:
    goto v_23160;
v_23161:
    fn = elt(env, 8); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(fn, 3, v_23246, v_23245, v_23244);
    env = stack[-13];
    goto v_23151;
v_23152:
    goto v_23173;
v_23167:
    v_23246 = stack[-10];
    goto v_23168;
v_23169:
    v_23245 = stack[-8];
    goto v_23170;
v_23171:
    v_23244 = stack[-4];
    goto v_23172;
v_23173:
    goto v_23167;
v_23168:
    goto v_23169;
v_23170:
    goto v_23171;
v_23172:
    fn = elt(env, 8); // get!+mat!+entry
    v_23244 = (*qfnn(fn))(fn, 3, v_23246, v_23245, v_23244);
    env = stack[-13];
    goto v_23153;
v_23154:
    goto v_23150;
v_23151:
    goto v_23152;
v_23153:
    fn = elt(env, 9); // addsq
    v_23244 = (*qfn2(fn))(fn, stack[0], v_23244);
    env = stack[-13];
    v_23245 = v_23244;
    v_23244 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=13 litvec-offset=3 saveloc=0
{   bind_fluid_stack bind_fluid_var(-13, 3, 0);
    qvalue(elt(env, 3)) = v_23244; // !*sub2
    v_23244 = v_23245;
    fn = elt(env, 10); // subs2
    v_23244 = (*qfn1(fn))(fn, v_23244);
    env = stack[-13];
    v_23245 = v_23244;
    ;}  // end of a binding scope
    v_23244 = v_23245;
    v_23244 = ncons(v_23244);
    env = stack[-13];
    stack[-2] = v_23244;
    stack[-3] = v_23244;
v_23132:
    v_23244 = stack[-4];
    v_23244 = add1(v_23244);
    env = stack[-13];
    stack[-4] = v_23244;
    goto v_23194;
v_23190:
    v_23245 = stack[-12];
    goto v_23191;
v_23192:
    v_23244 = stack[-4];
    goto v_23193;
v_23194:
    goto v_23190;
v_23191:
    goto v_23192;
v_23193:
    v_23244 = difference2(v_23245, v_23244);
    env = stack[-13];
    v_23244 = Lminusp(nil, v_23244);
    env = stack[-13];
    if (v_23244 == nil) goto v_23187;
    v_23244 = stack[-3];
    goto v_23131;
v_23187:
    goto v_23203;
v_23199:
    stack[-1] = stack[-2];
    goto v_23200;
v_23201:
    goto v_23211;
v_23207:
    goto v_23219;
v_23213:
    v_23246 = stack[-11];
    goto v_23214;
v_23215:
    v_23245 = stack[-8];
    goto v_23216;
v_23217:
    v_23244 = stack[-4];
    goto v_23218;
v_23219:
    goto v_23213;
v_23214:
    goto v_23215;
v_23216:
    goto v_23217;
v_23218:
    fn = elt(env, 8); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(fn, 3, v_23246, v_23245, v_23244);
    env = stack[-13];
    goto v_23208;
v_23209:
    goto v_23230;
v_23224:
    v_23246 = stack[-10];
    goto v_23225;
v_23226:
    v_23245 = stack[-8];
    goto v_23227;
v_23228:
    v_23244 = stack[-4];
    goto v_23229;
v_23230:
    goto v_23224;
v_23225:
    goto v_23226;
v_23227:
    goto v_23228;
v_23229:
    fn = elt(env, 8); // get!+mat!+entry
    v_23244 = (*qfnn(fn))(fn, 3, v_23246, v_23245, v_23244);
    env = stack[-13];
    goto v_23210;
v_23211:
    goto v_23207;
v_23208:
    goto v_23209;
v_23210:
    fn = elt(env, 9); // addsq
    v_23244 = (*qfn2(fn))(fn, stack[0], v_23244);
    env = stack[-13];
    v_23245 = v_23244;
    v_23244 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=13 litvec-offset=3 saveloc=0
{   bind_fluid_stack bind_fluid_var(-13, 3, 0);
    qvalue(elt(env, 3)) = v_23244; // !*sub2
    v_23244 = v_23245;
    fn = elt(env, 10); // subs2
    v_23244 = (*qfn1(fn))(fn, v_23244);
    env = stack[-13];
    v_23245 = v_23244;
    ;}  // end of a binding scope
    v_23244 = v_23245;
    v_23244 = ncons(v_23244);
    env = stack[-13];
    goto v_23202;
v_23203:
    goto v_23199;
v_23200:
    goto v_23201;
v_23202:
    v_23244 = Lrplacd(nil, stack[-1], v_23244);
    env = stack[-13];
    v_23244 = stack[-2];
    v_23244 = qcdr(v_23244);
    stack[-2] = v_23244;
    goto v_23132;
v_23131:
    v_23244 = ncons(v_23244);
    env = stack[-13];
    goto v_23123;
v_23124:
    goto v_23120;
v_23121:
    goto v_23122;
v_23123:
    v_23244 = Lrplacd(nil, stack[-5], v_23244);
    env = stack[-13];
    v_23244 = stack[-6];
    v_23244 = qcdr(v_23244);
    stack[-6] = v_23244;
    goto v_22972;
v_22971:
    return onevalue(v_23244);
}



// Code for iv_cutcongs2

static LispObject CC_iv_cutcongs2(LispObject env,
                         LispObject v_22908, LispObject v_22909)
{
    env = qenv(env);
    LispObject v_22977, v_22978, v_22979;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22908,v_22909);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_22909;
    v_22979 = v_22908;
// end of prologue
    goto v_22919;
v_22915:
    v_22977 = stack[0];
    v_22977 = qcar(v_22977);
    v_22978 = qcar(v_22977);
    goto v_22916;
v_22917:
    v_22977 = elt(env, 1); // cong
    goto v_22918;
v_22919:
    goto v_22915;
v_22916:
    goto v_22917;
v_22918:
    if (v_22978 == v_22977) goto v_22913;
    else goto v_22914;
v_22913:
    goto v_22928;
v_22924:
    goto v_22934;
v_22930:
    goto v_22940;
v_22936:
    v_22977 = stack[0];
    v_22977 = qcdr(v_22977);
    goto v_22937;
v_22938:
    v_22978 = v_22979;
    goto v_22939;
v_22940:
    goto v_22936;
v_22937:
    goto v_22938;
v_22939:
    v_22978 = difference2(v_22977, v_22978);
    env = stack[-1];
    goto v_22931;
v_22932:
    v_22977 = stack[0];
    v_22977 = qcar(v_22977);
    v_22977 = qcdr(v_22977);
    goto v_22933;
v_22934:
    goto v_22930;
v_22931:
    goto v_22932;
v_22933:
    v_22978 = Cremainder(v_22978, v_22977);
    goto v_22925;
v_22926:
    v_22977 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22927;
v_22928:
    goto v_22924;
v_22925:
    goto v_22926;
v_22927:
    v_22977 = (v_22978 == v_22977 ? lisp_true : nil);
    goto v_22912;
v_22914:
    goto v_22955;
v_22951:
    goto v_22961;
v_22957:
    goto v_22967;
v_22963:
    v_22977 = stack[0];
    v_22977 = qcdr(v_22977);
    goto v_22964;
v_22965:
    v_22978 = v_22979;
    goto v_22966;
v_22967:
    goto v_22963;
v_22964:
    goto v_22965;
v_22966:
    v_22978 = difference2(v_22977, v_22978);
    env = stack[-1];
    goto v_22958;
v_22959:
    v_22977 = stack[0];
    v_22977 = qcar(v_22977);
    v_22977 = qcdr(v_22977);
    goto v_22960;
v_22961:
    goto v_22957;
v_22958:
    goto v_22959;
v_22960:
    v_22978 = Cremainder(v_22978, v_22977);
    goto v_22952;
v_22953:
    v_22977 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22954;
v_22955:
    goto v_22951;
v_22952:
    goto v_22953;
v_22954:
    v_22977 = (v_22978 == v_22977 ? lisp_true : nil);
    v_22977 = (v_22977 == nil ? lisp_true : nil);
    goto v_22912;
    v_22977 = nil;
v_22912:
    return onevalue(v_22977);
}



// Code for symbolsrd

static LispObject CC_symbolsrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23082, v_23083, v_23084;
    LispObject fn;
    argcheck(nargs, 0, "symbolsrd");
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
    stack[-4] = nil;
    fn = elt(env, 8); // lex
    v_23082 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_22933;
v_22929:
    v_23083 = qvalue(elt(env, 1)); // char
    goto v_22930;
v_22931:
    v_23082 = elt(env, 2); // (b v a r)
    goto v_22932;
v_22933:
    goto v_22929;
v_22930:
    goto v_22931;
v_22932:
    if (equal(v_23083, v_23082)) goto v_22927;
    else goto v_22928;
v_22927:
    fn = elt(env, 9); // bvarrd
    v_23082 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[-4] = v_23082;
    goto v_22945;
v_22941:
    v_23082 = stack[-4];
    v_23082 = qcdr(v_23082);
    v_23082 = qcdr(v_23082);
    v_23083 = qcar(v_23082);
    goto v_22942;
v_22943:
    v_23082 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22944;
v_22945:
    goto v_22941;
v_22942:
    goto v_22943;
v_22944:
    if (v_23083 == v_23082) goto v_22939;
    else goto v_22940;
v_22939:
    v_23082 = stack[-4];
    stack[-4] = v_23082;
    goto v_22938;
v_22940:
    goto v_22959;
v_22955:
    v_23083 = elt(env, 3); // ""
    goto v_22956;
v_22957:
    v_23082 = (LispObject)208+TAG_FIXNUM; // 13
    goto v_22958;
v_22959:
    goto v_22955;
v_22956:
    goto v_22957;
v_22958:
    fn = elt(env, 10); // errorml
    v_23082 = (*qfn2(fn))(fn, v_23083, v_23082);
    env = stack[-5];
    goto v_22938;
v_22938:
    fn = elt(env, 8); // lex
    v_23082 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_22926;
v_22928:
    goto v_22970;
v_22966:
    v_23083 = elt(env, 4); // "<bvar>"
    goto v_22967;
v_22968:
    v_23082 = (LispObject)224+TAG_FIXNUM; // 14
    goto v_22969;
v_22970:
    goto v_22966;
v_22967:
    goto v_22968;
v_22969:
    fn = elt(env, 10); // errorml
    v_23082 = (*qfn2(fn))(fn, v_23083, v_23082);
    env = stack[-5];
    goto v_22926;
v_22926:
    goto v_22981;
v_22977:
    v_23083 = qvalue(elt(env, 1)); // char
    goto v_22978;
v_22979:
    v_23082 = elt(env, 5); // (l o w l i m i t)
    goto v_22980;
v_22981:
    goto v_22977;
v_22978:
    goto v_22979;
v_22980:
    if (equal(v_23083, v_23082)) goto v_22975;
    else goto v_22976;
v_22975:
    fn = elt(env, 11); // lowupperlimitrd
    v_23082 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[-3] = v_23082;
    fn = elt(env, 8); // lex
    v_23082 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_22974;
v_22976:
    v_23082 = nil;
    stack[-3] = v_23082;
    goto v_22974;
v_22974:
    goto v_22997;
v_22993:
    v_23083 = qvalue(elt(env, 1)); // char
    goto v_22994;
v_22995:
    v_23082 = elt(env, 6); // (i n t e r v a l)
    goto v_22996;
v_22997:
    goto v_22993;
v_22994:
    goto v_22995;
v_22996:
    if (equal(v_23083, v_23082)) goto v_22991;
    else goto v_22992;
v_22991:
    fn = elt(env, 12); // intervalrd
    v_23082 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[-2] = v_23082;
    fn = elt(env, 8); // lex
    v_23082 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_22990;
v_22992:
    v_23082 = nil;
    stack[-2] = v_23082;
    goto v_22990;
v_22990:
    goto v_23013;
v_23009:
    v_23083 = qvalue(elt(env, 1)); // char
    goto v_23010;
v_23011:
    v_23082 = elt(env, 7); // (c o n d i t i o n)
    goto v_23012;
v_23013:
    goto v_23009;
v_23010:
    goto v_23011;
v_23012:
    if (equal(v_23083, v_23082)) goto v_23007;
    else goto v_23008;
v_23007:
    fn = elt(env, 13); // conditionrd
    v_23082 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[0] = v_23082;
    fn = elt(env, 8); // lex
    v_23082 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_23006;
v_23008:
    v_23082 = nil;
    stack[0] = v_23082;
    goto v_23006;
v_23006:
    fn = elt(env, 14); // mathml2
    v_23082 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[-1] = v_23082;
    fn = elt(env, 8); // lex
    v_23082 = (*qfnn(fn))(fn, 0);
    v_23082 = stack[-3];
    if (v_23082 == nil) goto v_23026;
    goto v_23035;
v_23029:
    v_23084 = stack[-4];
    goto v_23030;
v_23031:
    v_23083 = stack[-3];
    goto v_23032;
v_23033:
    v_23082 = stack[-1];
    goto v_23034;
v_23035:
    goto v_23029;
v_23030:
    goto v_23031;
v_23032:
    goto v_23033;
v_23034:
    return list3(v_23084, v_23083, v_23082);
v_23026:
    v_23082 = stack[-2];
    if (v_23082 == nil) goto v_23042;
    goto v_23051;
v_23045:
    v_23084 = stack[-4];
    goto v_23046;
v_23047:
    v_23083 = stack[-2];
    goto v_23048;
v_23049:
    v_23082 = stack[-1];
    goto v_23050;
v_23051:
    goto v_23045;
v_23046:
    goto v_23047;
v_23048:
    goto v_23049;
v_23050:
    return list3(v_23084, v_23083, v_23082);
v_23042:
    v_23082 = stack[0];
    if (v_23082 == nil) goto v_23058;
    goto v_23067;
v_23061:
    v_23084 = stack[-4];
    goto v_23062;
v_23063:
    v_23083 = stack[0];
    goto v_23064;
v_23065:
    v_23082 = stack[-1];
    goto v_23066;
v_23067:
    goto v_23061;
v_23062:
    goto v_23063;
v_23064:
    goto v_23065;
v_23066:
    return list3(v_23084, v_23083, v_23082);
v_23058:
    goto v_23078;
v_23072:
    v_23084 = stack[-4];
    goto v_23073;
v_23074:
    v_23083 = nil;
    goto v_23075;
v_23076:
    v_23082 = stack[-1];
    goto v_23077;
v_23078:
    goto v_23072;
v_23073:
    goto v_23074;
v_23075:
    goto v_23076;
v_23077:
    return list3(v_23084, v_23083, v_23082);
    return onevalue(v_23082);
}



// Code for evzero

static LispObject CC_evzero(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22943, v_22944;
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
    v_22943 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_22943;
v_22915:
    goto v_22927;
v_22923:
    v_22943 = qvalue(elt(env, 1)); // dipvars!*
    v_22944 = Llength(nil, v_22943);
    env = stack[-2];
    goto v_22924;
v_22925:
    v_22943 = stack[0];
    goto v_22926;
v_22927:
    goto v_22923;
v_22924:
    goto v_22925;
v_22926:
    v_22943 = difference2(v_22944, v_22943);
    env = stack[-2];
    v_22943 = Lminusp(nil, v_22943);
    env = stack[-2];
    if (v_22943 == nil) goto v_22920;
    goto v_22914;
v_22920:
    goto v_22937;
v_22933:
    v_22944 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22934;
v_22935:
    v_22943 = stack[-1];
    goto v_22936;
v_22937:
    goto v_22933;
v_22934:
    goto v_22935;
v_22936:
    v_22943 = cons(v_22944, v_22943);
    env = stack[-2];
    stack[-1] = v_22943;
    v_22943 = stack[0];
    v_22943 = add1(v_22943);
    env = stack[-2];
    stack[0] = v_22943;
    goto v_22915;
v_22914:
    v_22943 = stack[-1];
    return onevalue(v_22943);
}



// Code for gbfdiff

static LispObject CC_gbfdiff(LispObject env,
                         LispObject v_22908, LispObject v_22909)
{
    env = qenv(env);
    LispObject v_22937, v_22938;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22908,v_22909);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_22909;
    stack[-1] = v_22908;
// end of prologue
    goto v_22916;
v_22912:
    goto v_22922;
v_22918:
    v_22937 = stack[-1];
    v_22938 = qcar(v_22937);
    goto v_22919;
v_22920:
    v_22937 = stack[0];
    v_22937 = qcar(v_22937);
    goto v_22921;
v_22922:
    goto v_22918;
v_22919:
    goto v_22920;
v_22921:
    fn = elt(env, 1); // difbf
    stack[-2] = (*qfn2(fn))(fn, v_22938, v_22937);
    env = stack[-3];
    goto v_22913;
v_22914:
    goto v_22932;
v_22928:
    v_22937 = stack[-1];
    v_22938 = qcdr(v_22937);
    goto v_22929;
v_22930:
    v_22937 = stack[0];
    v_22937 = qcdr(v_22937);
    goto v_22931;
v_22932:
    goto v_22928;
v_22929:
    goto v_22930;
v_22931:
    fn = elt(env, 1); // difbf
    v_22937 = (*qfn2(fn))(fn, v_22938, v_22937);
    goto v_22915;
v_22916:
    goto v_22912;
v_22913:
    goto v_22914;
v_22915:
    {
        LispObject v_22942 = stack[-2];
        return cons(v_22942, v_22937);
    }
}



// Code for numprintlen

static LispObject CC_numprintlen(LispObject env,
                         LispObject v_22908)
{
    env = qenv(env);
    LispObject v_23104, v_23105;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22908);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_22908;
// end of prologue
v_22912:
    v_23104 = stack[-1];
    if (!consp(v_23104)) goto v_22915;
    else goto v_22916;
v_22915:
    v_23104 = stack[-1];
    v_23104 = Lexplode(nil, v_23104);
        return Llength(nil, v_23104);
v_22916:
    v_23104 = stack[-1];
    v_23104 = Llength(nil, v_23104);
    env = stack[-6];
    v_23104 = Lonep(nil, v_23104);
    env = stack[-6];
    if (v_23104 == nil) goto v_22922;
    v_23104 = stack[-1];
    v_23104 = qcar(v_23104);
    stack[-1] = v_23104;
    goto v_22912;
v_22922:
    goto v_22934;
v_22930:
    v_23104 = stack[-1];
    v_23105 = qcar(v_23104);
    goto v_22931;
v_22932:
    v_23104 = elt(env, 1); // !:rd!:
    goto v_22933;
v_22934:
    goto v_22930;
v_22931:
    goto v_22932;
v_22933:
    if (v_23105 == v_23104) goto v_22928;
    else goto v_22929;
v_22928:
    v_23104 = stack[-1];
    fn = elt(env, 4); // rd!:explode
    v_23104 = (*qfn1(fn))(fn, v_23104);
    env = stack[-6];
    stack[-1] = v_23104;
    goto v_22945;
v_22941:
    stack[-2] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_22942;
v_22943:
    goto v_22952;
v_22948:
    v_23104 = stack[-1];
    v_23104 = qcar(v_23104);
    stack[0] = Llength(nil, v_23104);
    env = stack[-6];
    goto v_22949;
v_22950:
    v_23104 = stack[-1];
    v_23104 = qcdr(v_23104);
    v_23104 = qcar(v_23104);
    v_23104 = Lexplode(nil, v_23104);
    env = stack[-6];
    v_23104 = Llength(nil, v_23104);
    env = stack[-6];
    goto v_22951;
v_22952:
    goto v_22948;
v_22949:
    goto v_22950;
v_22951:
    v_23104 = plus2(stack[0], v_23104);
    goto v_22944;
v_22945:
    goto v_22941;
v_22942:
    goto v_22943;
v_22944:
    {
        LispObject v_23112 = stack[-2];
        return plus2(v_23112, v_23104);
    }
v_22929:
    goto v_22967;
v_22963:
    v_23104 = stack[-1];
    v_23105 = qcar(v_23104);
    goto v_22964;
v_22965:
    v_23104 = elt(env, 2); // (!:cr!: !:crn!: !:gi!:)
    goto v_22966;
v_22967:
    goto v_22963;
v_22964:
    goto v_22965;
v_22966:
    v_23104 = Lmemq(nil, v_23105, v_23104);
    if (v_23104 == nil) goto v_22962;
    goto v_22977;
v_22973:
    goto v_22984;
v_22980:
    v_23105 = elt(env, 1); // !:rd!:
    goto v_22981;
v_22982:
    v_23104 = stack[-1];
    v_23104 = qcdr(v_23104);
    v_23104 = qcar(v_23104);
    goto v_22983;
v_22984:
    goto v_22980;
v_22981:
    goto v_22982;
v_22983:
    v_23104 = cons(v_23105, v_23104);
    env = stack[-6];
    fn = elt(env, 4); // rd!:explode
    stack[0] = (*qfn1(fn))(fn, v_23104);
    env = stack[-6];
    goto v_22974;
v_22975:
    goto v_22995;
v_22991:
    v_23105 = elt(env, 1); // !:rd!:
    goto v_22992;
v_22993:
    v_23104 = stack[-1];
    v_23104 = qcdr(v_23104);
    v_23104 = qcdr(v_23104);
    goto v_22994;
v_22995:
    goto v_22991;
v_22992:
    goto v_22993;
v_22994:
    v_23104 = cons(v_23105, v_23104);
    env = stack[-6];
    fn = elt(env, 4); // rd!:explode
    v_23104 = (*qfn1(fn))(fn, v_23104);
    env = stack[-6];
    goto v_22976;
v_22977:
    goto v_22973;
v_22974:
    goto v_22975;
v_22976:
    v_23104 = cons(stack[0], v_23104);
    env = stack[-6];
    stack[-1] = v_23104;
    goto v_23005;
v_23001:
    stack[-4] = (LispObject)192+TAG_FIXNUM; // 12
    goto v_23002;
v_23003:
    goto v_23012;
v_23008:
    v_23104 = stack[-1];
    v_23104 = qcar(v_23104);
    v_23104 = qcar(v_23104);
    stack[-3] = Llength(nil, v_23104);
    env = stack[-6];
    goto v_23009;
v_23010:
    goto v_23022;
v_23018:
    v_23104 = stack[-1];
    v_23104 = qcar(v_23104);
    v_23104 = qcdr(v_23104);
    v_23104 = Lexplode(nil, v_23104);
    env = stack[-6];
    stack[-2] = Llength(nil, v_23104);
    env = stack[-6];
    goto v_23019;
v_23020:
    goto v_23033;
v_23029:
    v_23104 = stack[-1];
    v_23104 = qcdr(v_23104);
    v_23104 = qcar(v_23104);
    stack[0] = Llength(nil, v_23104);
    env = stack[-6];
    goto v_23030;
v_23031:
    v_23104 = stack[-1];
    v_23104 = qcdr(v_23104);
    v_23104 = qcdr(v_23104);
    v_23104 = Lexplode(nil, v_23104);
    env = stack[-6];
    v_23104 = Llength(nil, v_23104);
    env = stack[-6];
    goto v_23032;
v_23033:
    goto v_23029;
v_23030:
    goto v_23031;
v_23032:
    v_23104 = plus2(stack[0], v_23104);
    env = stack[-6];
    goto v_23021;
v_23022:
    goto v_23018;
v_23019:
    goto v_23020;
v_23021:
    v_23104 = plus2(stack[-2], v_23104);
    env = stack[-6];
    goto v_23011;
v_23012:
    goto v_23008;
v_23009:
    goto v_23010;
v_23011:
    v_23104 = plus2(stack[-3], v_23104);
    goto v_23004;
v_23005:
    goto v_23001;
v_23002:
    goto v_23003;
v_23004:
    {
        LispObject v_23113 = stack[-4];
        return plus2(v_23113, v_23104);
    }
v_22962:
    goto v_23050;
v_23046:
    v_23104 = stack[-1];
    stack[-5] = Llength(nil, v_23104);
    env = stack[-6];
    goto v_23047;
v_23048:
    goto v_23059;
v_23055:
    stack[-4] = elt(env, 3); // plus
    goto v_23056;
v_23057:
    v_23104 = stack[-1];
    v_23104 = qcdr(v_23104);
    stack[-3] = v_23104;
    v_23104 = stack[-3];
    if (v_23104 == nil) goto v_23071;
    else goto v_23072;
v_23071:
    v_23104 = nil;
    goto v_23065;
v_23072:
    v_23104 = stack[-3];
    v_23104 = qcar(v_23104);
    v_23104 = CC_numprintlen(elt(env, 0), v_23104);
    env = stack[-6];
    v_23104 = ncons(v_23104);
    env = stack[-6];
    stack[-1] = v_23104;
    stack[-2] = v_23104;
v_23066:
    v_23104 = stack[-3];
    v_23104 = qcdr(v_23104);
    stack[-3] = v_23104;
    v_23104 = stack[-3];
    if (v_23104 == nil) goto v_23085;
    else goto v_23086;
v_23085:
    v_23104 = stack[-2];
    goto v_23065;
v_23086:
    goto v_23094;
v_23090:
    stack[0] = stack[-1];
    goto v_23091;
v_23092:
    v_23104 = stack[-3];
    v_23104 = qcar(v_23104);
    v_23104 = CC_numprintlen(elt(env, 0), v_23104);
    env = stack[-6];
    v_23104 = ncons(v_23104);
    env = stack[-6];
    goto v_23093;
v_23094:
    goto v_23090;
v_23091:
    goto v_23092;
v_23093:
    v_23104 = Lrplacd(nil, stack[0], v_23104);
    env = stack[-6];
    v_23104 = stack[-1];
    v_23104 = qcdr(v_23104);
    stack[-1] = v_23104;
    goto v_23066;
v_23065:
    goto v_23058;
v_23059:
    goto v_23055;
v_23056:
    goto v_23057;
v_23058:
    v_23104 = cons(stack[-4], v_23104);
    env = stack[-6];
    fn = elt(env, 5); // lispeval
    v_23104 = (*qfn1(fn))(fn, v_23104);
    goto v_23049;
v_23050:
    goto v_23046;
v_23047:
    goto v_23048;
v_23049:
    {
        LispObject v_23114 = stack[-5];
        return plus2(v_23114, v_23104);
    }
    v_23104 = nil;
    return onevalue(v_23104);
}



// Code for mk_binding

static LispObject CC_mk_binding(LispObject env,
                         LispObject v_22908, LispObject v_22909)
{
    env = qenv(env);
    LispObject v_22936, v_22937;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22908,v_22909);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22909;
    stack[-1] = v_22908;
// end of prologue
    goto v_22920;
v_22916:
    v_22936 = stack[-1];
    v_22937 = qcar(v_22936);
    goto v_22917;
v_22918:
    v_22936 = stack[0];
    goto v_22919;
v_22920:
    goto v_22916;
v_22917:
    goto v_22918;
v_22919:
    fn = elt(env, 1); // can_be_proved
    v_22936 = (*qfn2(fn))(fn, v_22937, v_22936);
    env = stack[-2];
    if (v_22936 == nil) goto v_22913;
    else goto v_22914;
v_22913:
    v_22936 = nil;
    goto v_22912;
v_22914:
    goto v_22932;
v_22928:
    v_22936 = stack[-1];
    v_22937 = qcdr(v_22936);
    goto v_22929;
v_22930:
    v_22936 = stack[0];
    goto v_22931;
v_22932:
    goto v_22928;
v_22929:
    goto v_22930;
v_22931:
    {
        fn = elt(env, 2); // edge_bind
        return (*qfn2(fn))(fn, v_22937, v_22936);
    }
    v_22936 = nil;
v_22912:
    return onevalue(v_22936);
}



// Code for ratnump

static LispObject CC_ratnump(LispObject env,
                         LispObject v_22908)
{
    env = qenv(env);
    LispObject v_22940, v_22941, v_22942;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22908);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_22940 = v_22908;
// end of prologue
    fn = elt(env, 2); // simp!*
    v_22941 = (*qfn1(fn))(fn, v_22940);
    env = stack[0];
    v_22940 = v_22941;
    v_22941 = qcar(v_22941);
    if (!consp(v_22941)) goto v_22916;
    else goto v_22917;
v_22916:
    v_22941 = lisp_true;
    goto v_22915;
v_22917:
    goto v_22928;
v_22924:
    v_22941 = v_22940;
    v_22941 = qcar(v_22941);
    v_22941 = qcar(v_22941);
    goto v_22925;
v_22926:
    v_22942 = elt(env, 1); // !:rn!:
    goto v_22927;
v_22928:
    goto v_22924;
v_22925:
    goto v_22926;
v_22927:
    v_22941 = (v_22941 == v_22942 ? lisp_true : nil);
    goto v_22915;
    v_22941 = nil;
v_22915:
    if (v_22941 == nil) goto v_22913;
    v_22940 = qcdr(v_22940);
    v_22940 = (consp(v_22940) ? nil : lisp_true);
    goto v_22911;
v_22913:
    v_22940 = nil;
    goto v_22911;
    v_22940 = nil;
v_22911:
    return onevalue(v_22940);
}



// Code for miller!-rabin

static LispObject CC_millerKrabin(LispObject env,
                         LispObject v_22908, LispObject v_22909)
{
    env = qenv(env);
    LispObject v_23090, v_23091;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22908,v_22909);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_22909;
    stack[0] = v_22908;
// end of prologue
    goto v_22925;
v_22921:
    v_23091 = stack[-2];
    goto v_22922;
v_22923:
    v_23090 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22924;
v_22925:
    goto v_22921;
v_22922:
    goto v_22923;
v_22924:
    if (v_23091 == v_23090) goto v_22919;
    else goto v_22920;
v_22919:
    v_23090 = nil;
    goto v_22915;
v_22920:
    goto v_22935;
v_22931:
    goto v_22941;
v_22937:
    v_23091 = stack[-2];
    goto v_22938;
v_22939:
    v_23090 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_22940;
v_22941:
    goto v_22937;
v_22938:
    goto v_22939;
v_22940:
    v_23091 = Cremainder(v_23091, v_23090);
    env = stack[-4];
    goto v_22932;
v_22933:
    v_23090 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22934;
v_22935:
    goto v_22931;
v_22932:
    goto v_22933;
v_22934:
    if (v_23091 == v_23090) goto v_22929;
    else goto v_22930;
v_22929:
    goto v_22949;
v_22945:
    v_23091 = stack[-2];
    goto v_22946;
v_22947:
    v_23090 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_22948;
v_22949:
    goto v_22945;
v_22946:
    goto v_22947;
v_22948:
    v_23090 = (v_23091 == v_23090 ? lisp_true : nil);
    goto v_22915;
v_22930:
    goto v_22960;
v_22956:
    v_23091 = stack[-2];
    goto v_22957;
v_22958:
    v_23090 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_22959;
v_22960:
    goto v_22956;
v_22957:
    goto v_22958;
v_22959:
    v_23090 = (LispObject)lesseq2(v_23091, v_23090);
    v_23090 = v_23090 ? lisp_true : nil;
    env = stack[-4];
    if (v_23090 == nil) goto v_22954;
    v_23090 = lisp_true;
    goto v_22915;
v_22954:
    v_23090 = stack[-2];
    v_23090 = sub1(v_23090);
    env = stack[-4];
    stack[-1] = v_23090;
    v_23090 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_23090;
v_22969:
    goto v_22978;
v_22974:
    goto v_22984;
v_22980:
    v_23091 = stack[-1];
    goto v_22981;
v_22982:
    v_23090 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_22983;
v_22984:
    goto v_22980;
v_22981:
    goto v_22982;
v_22983:
    v_23091 = Cremainder(v_23091, v_23090);
    env = stack[-4];
    goto v_22975;
v_22976:
    v_23090 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22977;
v_22978:
    goto v_22974;
v_22975:
    goto v_22976;
v_22977:
    if (v_23091 == v_23090) goto v_22973;
    goto v_22968;
v_22973:
    goto v_22994;
v_22990:
    v_23091 = stack[-1];
    goto v_22991;
v_22992:
    v_23090 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_22993;
v_22994:
    goto v_22990;
v_22991:
    goto v_22992;
v_22993:
    v_23090 = quot2(v_23091, v_23090);
    env = stack[-4];
    stack[-1] = v_23090;
    v_23090 = stack[-3];
    v_23090 = add1(v_23090);
    env = stack[-4];
    stack[-3] = v_23090;
    goto v_22969;
v_22968:
    v_23090 = stack[-2];
    fn = elt(env, 1); // set!-modulus
    v_23090 = (*qfn1(fn))(fn, v_23090);
    env = stack[-4];
    goto v_23006;
v_23002:
    v_23091 = stack[0];
    goto v_23003;
v_23004:
    v_23090 = stack[-2];
    goto v_23005;
v_23006:
    goto v_23002;
v_23003:
    goto v_23004;
v_23005:
    v_23090 = Cremainder(v_23091, v_23090);
    env = stack[-4];
    stack[0] = v_23090;
    goto v_23014;
v_23010:
    v_23091 = stack[0];
    goto v_23011;
v_23012:
    v_23090 = stack[-1];
    goto v_23013;
v_23014:
    goto v_23010;
v_23011:
    goto v_23012;
v_23013:
    v_23090 = Lmodular_expt(nil, v_23091, v_23090);
    env = stack[-4];
    stack[-1] = v_23090;
    goto v_23029;
v_23025:
    v_23091 = stack[-1];
    goto v_23026;
v_23027:
    v_23090 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23028;
v_23029:
    goto v_23025;
v_23026:
    goto v_23027;
v_23028:
    if (v_23091 == v_23090) goto v_23023;
    else goto v_23024;
v_23023:
    v_23090 = lisp_true;
    goto v_23022;
v_23024:
    goto v_23039;
v_23035:
    stack[0] = stack[-1];
    goto v_23036;
v_23037:
    v_23090 = stack[-2];
    v_23090 = sub1(v_23090);
    env = stack[-4];
    goto v_23038;
v_23039:
    goto v_23035;
v_23036:
    goto v_23037;
v_23038:
    v_23090 = (equal(stack[0], v_23090) ? lisp_true : nil);
    goto v_23022;
    v_23090 = nil;
v_23022:
    if (v_23090 == nil) goto v_23020;
    v_23090 = lisp_true;
    goto v_22915;
v_23020:
v_22916:
    goto v_23053;
v_23049:
    v_23091 = stack[-3];
    goto v_23050;
v_23051:
    v_23090 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23052;
v_23053:
    goto v_23049;
v_23050:
    goto v_23051;
v_23052:
    if (v_23091 == v_23090) goto v_23047;
    else goto v_23048;
v_23047:
    v_23090 = nil;
    goto v_22915;
v_23048:
    goto v_23062;
v_23058:
    v_23091 = stack[-1];
    goto v_23059;
v_23060:
    v_23090 = stack[-1];
    goto v_23061;
v_23062:
    goto v_23058;
v_23059:
    goto v_23060;
v_23061:
    v_23090 = Lmodular_times(nil, v_23091, v_23090);
    env = stack[-4];
    stack[-1] = v_23090;
    goto v_23073;
v_23069:
    v_23091 = stack[-1];
    goto v_23070;
v_23071:
    v_23090 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23072;
v_23073:
    goto v_23069;
v_23070:
    goto v_23071;
v_23072:
    if (v_23091 == v_23090) goto v_23067;
    else goto v_23068;
v_23067:
    v_23090 = nil;
    goto v_22915;
v_23068:
    goto v_23083;
v_23079:
    stack[0] = stack[-1];
    goto v_23080;
v_23081:
    v_23090 = stack[-2];
    v_23090 = sub1(v_23090);
    env = stack[-4];
    goto v_23082;
v_23083:
    goto v_23079;
v_23080:
    goto v_23081;
v_23082:
    if (equal(stack[0], v_23090)) goto v_23077;
    else goto v_23078;
v_23077:
    v_23090 = lisp_true;
    goto v_22915;
v_23078:
    v_23090 = stack[-3];
    v_23090 = sub1(v_23090);
    env = stack[-4];
    stack[-3] = v_23090;
    goto v_22916;
v_22915:
    return onevalue(v_23090);
}



// Code for equiv!-coeffs

static LispObject CC_equivKcoeffs(LispObject env,
                         LispObject v_22908, LispObject v_22909)
{
    env = qenv(env);
    LispObject v_22990, v_22991;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22908,v_22909);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_22909;
    stack[-1] = v_22908;
// end of prologue
    stack[-2] = nil;
v_22914:
    v_22990 = stack[-1];
    if (v_22990 == nil) goto v_22917;
    else goto v_22918;
v_22917:
    goto v_22925;
v_22921:
    stack[-1] = stack[-2];
    goto v_22922;
v_22923:
    v_22990 = stack[0];
    v_22990 = Llength(nil, v_22990);
    env = stack[-3];
    fn = elt(env, 1); // nzeros
    v_22990 = (*qfn1(fn))(fn, v_22990);
    env = stack[-3];
    goto v_22924;
v_22925:
    goto v_22921;
v_22922:
    goto v_22923;
v_22924:
    {
        LispObject v_22995 = stack[-1];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_22995, v_22990);
    }
v_22918:
    v_22990 = stack[0];
    if (v_22990 == nil) goto v_22930;
    else goto v_22931;
v_22930:
    v_22990 = stack[-2];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_22990);
    }
v_22931:
    goto v_22941;
v_22937:
    v_22990 = stack[-1];
    v_22990 = qcar(v_22990);
    v_22991 = qcar(v_22990);
    goto v_22938;
v_22939:
    v_22990 = stack[0];
    v_22990 = qcar(v_22990);
    v_22990 = qcar(v_22990);
    goto v_22940;
v_22941:
    goto v_22937;
v_22938:
    goto v_22939;
v_22940:
    if (equal(v_22991, v_22990)) goto v_22935;
    else goto v_22936;
v_22935:
    goto v_22953;
v_22949:
    v_22990 = stack[-1];
    v_22990 = qcar(v_22990);
    v_22991 = qcdr(v_22990);
    goto v_22950;
v_22951:
    v_22990 = stack[-2];
    goto v_22952;
v_22953:
    goto v_22949;
v_22950:
    goto v_22951;
v_22952:
    v_22990 = cons(v_22991, v_22990);
    env = stack[-3];
    stack[-2] = v_22990;
    v_22990 = stack[-1];
    v_22990 = qcdr(v_22990);
    stack[-1] = v_22990;
    v_22990 = stack[0];
    v_22990 = qcdr(v_22990);
    stack[0] = v_22990;
    goto v_22914;
v_22936:
    goto v_22969;
v_22965:
    v_22990 = stack[-1];
    v_22990 = qcar(v_22990);
    v_22991 = qcar(v_22990);
    goto v_22966;
v_22967:
    v_22990 = stack[0];
    v_22990 = qcar(v_22990);
    v_22990 = qcar(v_22990);
    goto v_22968;
v_22969:
    goto v_22965;
v_22966:
    goto v_22967;
v_22968:
    fn = elt(env, 3); // mv!-pow!-!>
    v_22990 = (*qfn2(fn))(fn, v_22991, v_22990);
    env = stack[-3];
    if (v_22990 == nil) goto v_22963;
    v_22990 = stack[-1];
    v_22990 = qcdr(v_22990);
    stack[-1] = v_22990;
    goto v_22914;
v_22963:
    goto v_22985;
v_22981:
    v_22991 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22982;
v_22983:
    v_22990 = stack[-2];
    goto v_22984;
v_22985:
    goto v_22981;
v_22982:
    goto v_22983;
v_22984:
    v_22990 = cons(v_22991, v_22990);
    env = stack[-3];
    stack[-2] = v_22990;
    v_22990 = stack[0];
    v_22990 = qcdr(v_22990);
    stack[0] = v_22990;
    goto v_22914;
    v_22990 = nil;
    return onevalue(v_22990);
}



// Code for !*g2lex

static LispObject CC_Hg2lex(LispObject env,
                         LispObject v_22908)
{
    env = qenv(env);
    LispObject v_22949, v_22950;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22908);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_22949 = v_22908;
// end of prologue
    v_22950 = nil;
    stack[-1] = v_22949;
v_22916:
    v_22949 = stack[-1];
    if (v_22949 == nil) goto v_22920;
    else goto v_22921;
v_22920:
    goto v_22915;
v_22921:
    v_22949 = stack[-1];
    v_22949 = qcar(v_22949);
    goto v_22932;
v_22928:
    stack[0] = v_22950;
    goto v_22929;
v_22930:
    goto v_22940;
v_22936:
    v_22950 = v_22949;
    v_22950 = qcar(v_22950);
    v_22950 = qcdr(v_22950);
    goto v_22937;
v_22938:
    v_22949 = qcdr(v_22949);
    goto v_22939;
v_22940:
    goto v_22936;
v_22937:
    goto v_22938;
v_22939:
    v_22949 = cons(v_22950, v_22949);
    env = stack[-2];
    v_22949 = ncons(v_22949);
    env = stack[-2];
    goto v_22931;
v_22932:
    goto v_22928;
v_22929:
    goto v_22930;
v_22931:
    fn = elt(env, 1); // psum
    v_22949 = (*qfn2(fn))(fn, stack[0], v_22949);
    env = stack[-2];
    v_22950 = v_22949;
    v_22949 = stack[-1];
    v_22949 = qcdr(v_22949);
    stack[-1] = v_22949;
    goto v_22916;
v_22915:
    v_22949 = v_22950;
    return onevalue(v_22949);
}



// Code for simpquot

static LispObject CC_simpquot(LispObject env,
                         LispObject v_22908)
{
    env = qenv(env);
    LispObject v_23098, v_23099, v_23100;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22908);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_22908;
// end of prologue
    v_23098 = stack[-1];
    fn = elt(env, 7); // simpcar
    stack[0] = (*qfn1(fn))(fn, v_23098);
    env = stack[-3];
    v_23098 = stack[-1];
    v_23098 = qcdr(v_23098);
    v_23098 = qcar(v_23098);
    fn = elt(env, 8); // simp
    v_23098 = (*qfn1(fn))(fn, v_23098);
    env = stack[-3];
    stack[-2] = stack[0];
    stack[0] = v_23098;
    v_23098 = stack[0];
    v_23098 = qcar(v_23098);
    if (v_23098 == nil) goto v_22920;
    else goto v_22921;
v_22920:
    v_23098 = stack[-2];
    v_23098 = qcar(v_23098);
    if (v_23098 == nil) goto v_22926;
    else goto v_22927;
v_22926:
    goto v_22937;
v_22931:
    v_23100 = elt(env, 1); // alg
    goto v_22932;
v_22933:
    v_23099 = (LispObject)304+TAG_FIXNUM; // 19
    goto v_22934;
v_22935:
    v_23098 = elt(env, 2); // "0/0 formed"
    goto v_22936;
v_22937:
    goto v_22931;
v_22932:
    goto v_22933;
v_22934:
    goto v_22935;
v_22936:
    {
        fn = elt(env, 9); // rerror
        return (*qfnn(fn))(fn, 3, v_23100, v_23099, v_23098);
    }
v_22927:
    goto v_22950;
v_22944:
    v_23100 = elt(env, 1); // alg
    goto v_22945;
v_22946:
    v_23099 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_22947;
v_22948:
    v_23098 = elt(env, 3); // "Zero divisor"
    goto v_22949;
v_22950:
    goto v_22944;
v_22945:
    goto v_22946;
v_22947:
    goto v_22948;
v_22949:
    {
        fn = elt(env, 9); // rerror
        return (*qfnn(fn))(fn, 3, v_23100, v_23099, v_23098);
    }
    v_23098 = nil;
    goto v_22919;
v_22921:
    goto v_22961;
v_22957:
    v_23099 = qvalue(elt(env, 4)); // dmode!*
    goto v_22958;
v_22959:
    v_23098 = elt(env, 5); // (!:rd!: !:cr!:)
    goto v_22960;
v_22961:
    goto v_22957;
v_22958:
    goto v_22959;
v_22960:
    v_23098 = Lmemq(nil, v_23099, v_23098);
    if (v_23098 == nil) goto v_22955;
    v_23098 = stack[0];
    v_23098 = qcar(v_23098);
    if (!consp(v_23098)) goto v_22972;
    else goto v_22973;
v_22972:
    v_23098 = lisp_true;
    goto v_22971;
v_22973:
    v_23098 = stack[0];
    v_23098 = qcar(v_23098);
    v_23098 = qcar(v_23098);
    v_23098 = (consp(v_23098) ? nil : lisp_true);
    goto v_22971;
    v_23098 = nil;
v_22971:
    if (v_23098 == nil) goto v_22969;
    v_23098 = stack[0];
    v_23098 = qcdr(v_23098);
    if (!consp(v_23098)) goto v_22989;
    else goto v_22990;
v_22989:
    v_23098 = lisp_true;
    goto v_22988;
v_22990:
    v_23098 = stack[0];
    v_23098 = qcdr(v_23098);
    v_23098 = qcar(v_23098);
    v_23098 = (consp(v_23098) ? nil : lisp_true);
    goto v_22988;
    v_23098 = nil;
v_22988:
    if (v_23098 == nil) goto v_22986;
    v_23098 = stack[-2];
    v_23098 = qcdr(v_23098);
    if (!consp(v_23098)) goto v_23006;
    else goto v_23007;
v_23006:
    v_23098 = lisp_true;
    goto v_23005;
v_23007:
    v_23098 = stack[-2];
    v_23098 = qcdr(v_23098);
    v_23098 = qcar(v_23098);
    v_23098 = (consp(v_23098) ? nil : lisp_true);
    goto v_23005;
    v_23098 = nil;
v_23005:
    if (v_23098 == nil) goto v_23003;
    v_23098 = stack[0];
    v_23098 = qcdr(v_23098);
    fn = elt(env, 10); // !:onep
    v_23098 = (*qfn1(fn))(fn, v_23098);
    env = stack[-3];
    if (v_23098 == nil) goto v_23019;
    else goto v_23020;
v_23019:
    v_23098 = nil;
    goto v_23018;
v_23020:
    v_23098 = stack[-2];
    v_23098 = qcdr(v_23098);
    fn = elt(env, 10); // !:onep
    v_23098 = (*qfn1(fn))(fn, v_23098);
    env = stack[-3];
    goto v_23018;
    v_23098 = nil;
v_23018:
    goto v_23001;
v_23003:
    v_23098 = nil;
    goto v_23001;
    v_23098 = nil;
v_23001:
    goto v_22984;
v_22986:
    v_23098 = nil;
    goto v_22984;
    v_23098 = nil;
v_22984:
    goto v_22967;
v_22969:
    v_23098 = nil;
    goto v_22967;
    v_23098 = nil;
v_22967:
    if (v_23098 == nil) goto v_22955;
    goto v_23044;
v_23040:
    v_23098 = stack[-2];
    v_23098 = qcar(v_23098);
    if (v_23098 == nil) goto v_23047;
    else goto v_23048;
v_23047:
    v_23098 = nil;
    v_23099 = v_23098;
    goto v_23046;
v_23048:
    goto v_23059;
v_23055:
    v_23098 = stack[-2];
    v_23099 = qcar(v_23098);
    goto v_23056;
v_23057:
    v_23098 = stack[0];
    v_23098 = qcar(v_23098);
    goto v_23058;
v_23059:
    goto v_23055;
v_23056:
    goto v_23057;
v_23058:
    fn = elt(env, 11); // divd
    v_23098 = (*qfn2(fn))(fn, v_23099, v_23098);
    v_23099 = v_23098;
    goto v_23046;
    v_23099 = nil;
v_23046:
    goto v_23041;
v_23042:
    v_23098 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23043;
v_23044:
    goto v_23040;
v_23041:
    goto v_23042;
v_23043:
    return cons(v_23099, v_23098);
v_22955:
    goto v_23072;
v_23068:
    stack[0] = stack[-2];
    goto v_23069;
v_23070:
    v_23098 = stack[-1];
    v_23098 = qcdr(v_23098);
    fn = elt(env, 12); // simprecip
    v_23098 = (*qfn1(fn))(fn, v_23098);
    env = stack[-3];
    goto v_23071;
v_23072:
    goto v_23068;
v_23069:
    goto v_23070;
v_23071:
    fn = elt(env, 13); // multsq
    v_23098 = (*qfn2(fn))(fn, stack[0], v_23098);
    env = stack[-3];
    stack[-1] = v_23098;
    v_23098 = qvalue(elt(env, 6)); // !*modular
    if (v_23098 == nil) goto v_23080;
    v_23098 = stack[-1];
    v_23098 = qcdr(v_23098);
    if (v_23098 == nil) goto v_23083;
    else goto v_23080;
v_23083:
    goto v_23093;
v_23087:
    v_23100 = elt(env, 1); // alg
    goto v_23088;
v_23089:
    v_23099 = (LispObject)3216+TAG_FIXNUM; // 201
    goto v_23090;
v_23091:
    v_23098 = elt(env, 3); // "Zero divisor"
    goto v_23092;
v_23093:
    goto v_23087;
v_23088:
    goto v_23089;
v_23090:
    goto v_23091;
v_23092:
    fn = elt(env, 9); // rerror
    v_23098 = (*qfnn(fn))(fn, 3, v_23100, v_23099, v_23098);
    goto v_23078;
v_23080:
v_23078:
    v_23098 = stack[-1];
    goto v_22919;
    v_23098 = nil;
v_22919:
    return onevalue(v_23098);
}



// Code for isimp1

static LispObject CC_isimp1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23084, v_23085, v_23086, v_23087, v_23088;
    LispObject fn;
    LispObject v_22912, v_22911, v_22910, v_22909, v_22908;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "isimp1");
    va_start(aa, nargs);
    v_22908 = va_arg(aa, LispObject);
    v_22909 = va_arg(aa, LispObject);
    v_22910 = va_arg(aa, LispObject);
    v_22911 = va_arg(aa, LispObject);
    v_22912 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_22912,v_22911,v_22910,v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_22908,v_22909,v_22910,v_22911,v_22912);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[0] = v_22912;
    stack[-1] = v_22911;
    stack[-2] = v_22910;
    stack[-3] = v_22909;
    stack[-4] = v_22908;
// end of prologue
    v_23084 = stack[-4];
    if (v_23084 == nil) goto v_22916;
    else goto v_22917;
v_22916:
    v_23084 = nil;
    goto v_22915;
v_22917:
    v_23084 = stack[-4];
    if (!consp(v_23084)) goto v_22924;
    else goto v_22925;
v_22924:
    v_23084 = lisp_true;
    goto v_22923;
v_22925:
    v_23084 = stack[-4];
    v_23084 = qcar(v_23084);
    v_23084 = (consp(v_23084) ? nil : lisp_true);
    goto v_22923;
    v_23084 = nil;
v_22923:
    if (v_23084 == nil) goto v_22921;
    v_23084 = stack[0];
    if (v_23084 == nil) goto v_22936;
    goto v_22943;
v_22939:
    goto v_22940;
v_22941:
    v_23084 = qvalue(elt(env, 1)); // !*cvit
    if (v_23084 == nil) goto v_22948;
    goto v_22959;
v_22951:
    v_23087 = stack[-3];
    goto v_22952;
v_22953:
    v_23086 = stack[-2];
    goto v_22954;
v_22955:
    v_23085 = stack[-1];
    goto v_22956;
v_22957:
    v_23084 = stack[0];
    goto v_22958;
v_22959:
    goto v_22951;
v_22952:
    goto v_22953;
v_22954:
    goto v_22955;
v_22956:
    goto v_22957;
v_22958:
    fn = elt(env, 2); // calc_spurx
    v_23084 = (*qfnn(fn))(fn, 4, v_23087, v_23086, v_23085, v_23084);
    env = stack[-6];
    goto v_22946;
v_22948:
    goto v_22977;
v_22967:
    v_23084 = stack[0];
    v_23088 = qcar(v_23084);
    goto v_22968;
v_22969:
    v_23087 = stack[-3];
    goto v_22970;
v_22971:
    v_23086 = stack[-2];
    goto v_22972;
v_22973:
    v_23085 = stack[-1];
    goto v_22974;
v_22975:
    v_23084 = stack[0];
    v_23084 = qcdr(v_23084);
    goto v_22976;
v_22977:
    goto v_22967;
v_22968:
    goto v_22969;
v_22970:
    goto v_22971;
v_22972:
    goto v_22973;
v_22974:
    goto v_22975;
v_22976:
    fn = elt(env, 3); // spur0
    v_23084 = (*qfnn(fn))(fn, 5, v_23088, v_23087, v_23086, v_23085, v_23084);
    env = stack[-6];
    goto v_22946;
    v_23084 = nil;
v_22946:
    goto v_22942;
v_22943:
    goto v_22939;
v_22940:
    goto v_22941;
v_22942:
    {
        LispObject v_23095 = stack[-4];
        fn = elt(env, 4); // multd
        return (*qfn2(fn))(fn, v_23095, v_23084);
    }
v_22936:
    v_23084 = stack[-2];
    if (v_23084 == nil) goto v_22986;
    goto v_22993;
v_22989:
    stack[0] = stack[-4];
    goto v_22990;
v_22991:
    goto v_23004;
v_22996:
    v_23087 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22997;
v_22998:
    v_23086 = stack[-3];
    goto v_22999;
v_23000:
    v_23085 = stack[-2];
    goto v_23001;
v_23002:
    v_23084 = stack[-1];
    goto v_23003;
v_23004:
    goto v_22996;
v_22997:
    goto v_22998;
v_22999:
    goto v_23000;
v_23001:
    goto v_23002;
v_23003:
    fn = elt(env, 5); // index_simp
    v_23084 = (*qfnn(fn))(fn, 4, v_23087, v_23086, v_23085, v_23084);
    env = stack[-6];
    goto v_22992;
v_22993:
    goto v_22989;
v_22990:
    goto v_22991;
v_22992:
    {
        LispObject v_23096 = stack[0];
        fn = elt(env, 4); // multd
        return (*qfn2(fn))(fn, v_23096, v_23084);
    }
v_22986:
    v_23084 = stack[-1];
    if (v_23084 == nil) goto v_23010;
    goto v_23017;
v_23013:
    v_23084 = stack[-1];
    fn = elt(env, 6); // emult
    stack[0] = (*qfn1(fn))(fn, v_23084);
    env = stack[-6];
    goto v_23014;
v_23015:
    goto v_23031;
v_23021:
    v_23088 = stack[-4];
    goto v_23022;
v_23023:
    v_23087 = stack[-3];
    goto v_23024;
v_23025:
    v_23086 = stack[-2];
    goto v_23026;
v_23027:
    v_23085 = nil;
    goto v_23028;
v_23029:
    v_23084 = nil;
    goto v_23030;
v_23031:
    goto v_23021;
v_23022:
    goto v_23023;
v_23024:
    goto v_23025;
v_23026:
    goto v_23027;
v_23028:
    goto v_23029;
v_23030:
    v_23084 = CC_isimp1(elt(env, 0), 5, v_23088, v_23087, v_23086, v_23085, v_23084);
    env = stack[-6];
    goto v_23016;
v_23017:
    goto v_23013;
v_23014:
    goto v_23015;
v_23016:
    {
        LispObject v_23097 = stack[0];
        fn = elt(env, 7); // multf
        return (*qfn2(fn))(fn, v_23097, v_23084);
    }
v_23010:
    v_23084 = stack[-4];
    goto v_22934;
    v_23084 = nil;
v_22934:
    goto v_22915;
v_22921:
    goto v_23047;
v_23043:
    goto v_23059;
v_23049:
    v_23084 = stack[-4];
    v_23088 = qcar(v_23084);
    goto v_23050;
v_23051:
    v_23087 = stack[-3];
    goto v_23052;
v_23053:
    v_23086 = stack[-2];
    goto v_23054;
v_23055:
    v_23085 = stack[-1];
    goto v_23056;
v_23057:
    v_23084 = stack[0];
    goto v_23058;
v_23059:
    goto v_23049;
v_23050:
    goto v_23051;
v_23052:
    goto v_23053;
v_23054:
    goto v_23055;
v_23056:
    goto v_23057;
v_23058:
    fn = elt(env, 8); // isimp2
    stack[-5] = (*qfnn(fn))(fn, 5, v_23088, v_23087, v_23086, v_23085, v_23084);
    env = stack[-6];
    goto v_23044;
v_23045:
    goto v_23077;
v_23067:
    v_23084 = stack[-4];
    v_23088 = qcdr(v_23084);
    goto v_23068;
v_23069:
    v_23087 = stack[-3];
    goto v_23070;
v_23071:
    v_23086 = stack[-2];
    goto v_23072;
v_23073:
    v_23085 = stack[-1];
    goto v_23074;
v_23075:
    v_23084 = stack[0];
    goto v_23076;
v_23077:
    goto v_23067;
v_23068:
    goto v_23069;
v_23070:
    goto v_23071;
v_23072:
    goto v_23073;
v_23074:
    goto v_23075;
v_23076:
    v_23084 = CC_isimp1(elt(env, 0), 5, v_23088, v_23087, v_23086, v_23085, v_23084);
    env = stack[-6];
    goto v_23046;
v_23047:
    goto v_23043;
v_23044:
    goto v_23045;
v_23046:
    {
        LispObject v_23098 = stack[-5];
        fn = elt(env, 9); // addf
        return (*qfn2(fn))(fn, v_23098, v_23084);
    }
    v_23084 = nil;
v_22915:
    return onevalue(v_23084);
}



// Code for drop_dec_with

static LispObject CC_drop_dec_with(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23015, v_23016, v_23017;
    LispObject v_22910, v_22909, v_22908;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "drop_dec_with");
    va_start(aa, nargs);
    v_22908 = va_arg(aa, LispObject);
    v_22909 = va_arg(aa, LispObject);
    v_22910 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22910,v_22909,v_22908);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22908,v_22909,v_22910);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_22910;
    stack[-3] = v_22909;
    stack[-4] = v_22908;
// end of prologue
    stack[-5] = nil;
    v_23015 = stack[-2];
    if (v_23015 == nil) goto v_22920;
    goto v_22927;
v_22923:
    v_23016 = stack[-3];
    goto v_22924;
v_22925:
    v_23015 = elt(env, 1); // dec_with_rl
    goto v_22926;
v_22927:
    goto v_22923;
v_22924:
    goto v_22925;
v_22926:
    v_23015 = get(v_23016, v_23015);
    env = stack[-6];
    goto v_22918;
v_22920:
    goto v_22937;
v_22933:
    v_23016 = stack[-3];
    goto v_22934;
v_22935:
    v_23015 = elt(env, 2); // dec_with
    goto v_22936;
v_22937:
    goto v_22933;
v_22934:
    goto v_22935;
v_22936:
    v_23015 = get(v_23016, v_23015);
    env = stack[-6];
    goto v_22918;
    v_23015 = nil;
v_22918:
    stack[-1] = v_23015;
v_22943:
    v_23015 = stack[-1];
    if (v_23015 == nil) goto v_22947;
    else goto v_22948;
v_22947:
    goto v_22942;
v_22948:
    v_23015 = stack[-1];
    v_23015 = qcar(v_23015);
    stack[0] = v_23015;
    goto v_22959;
v_22955:
    v_23016 = stack[-4];
    goto v_22956;
v_22957:
    v_23015 = stack[0];
    goto v_22958;
v_22959:
    goto v_22955;
v_22956:
    goto v_22957;
v_22958:
    v_23015 = Ldelete(nil, v_23016, v_23015);
    env = stack[-6];
    stack[0] = v_23015;
    goto v_22971;
v_22967:
    v_23015 = stack[0];
    v_23016 = Llength(nil, v_23015);
    env = stack[-6];
    goto v_22968;
v_22969:
    v_23015 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22970;
v_22971:
    goto v_22967;
v_22968:
    goto v_22969;
v_22970:
    v_23015 = (LispObject)greaterp2(v_23016, v_23015);
    v_23015 = v_23015 ? lisp_true : nil;
    env = stack[-6];
    if (v_23015 == nil) goto v_22965;
    goto v_22980;
v_22976:
    v_23016 = stack[0];
    goto v_22977;
v_22978:
    v_23015 = stack[-5];
    goto v_22979;
v_22980:
    goto v_22976;
v_22977:
    goto v_22978;
v_22979:
    v_23015 = cons(v_23016, v_23015);
    env = stack[-6];
    stack[-5] = v_23015;
    goto v_22963;
v_22965:
v_22963:
    v_23015 = stack[-1];
    v_23015 = qcdr(v_23015);
    stack[-1] = v_23015;
    goto v_22943;
v_22942:
    v_23015 = stack[-2];
    if (v_23015 == nil) goto v_22989;
    goto v_22998;
v_22992:
    v_23017 = stack[-3];
    goto v_22993;
v_22994:
    v_23016 = elt(env, 1); // dec_with_rl
    goto v_22995;
v_22996:
    v_23015 = stack[-5];
    goto v_22997;
v_22998:
    goto v_22992;
v_22993:
    goto v_22994;
v_22995:
    goto v_22996;
v_22997:
    v_23015 = Lputprop(nil, 3, v_23017, v_23016, v_23015);
    goto v_22987;
v_22989:
    goto v_23011;
v_23005:
    v_23017 = stack[-3];
    goto v_23006;
v_23007:
    v_23016 = elt(env, 2); // dec_with
    goto v_23008;
v_23009:
    v_23015 = stack[-5];
    goto v_23010;
v_23011:
    goto v_23005;
v_23006:
    goto v_23007;
v_23008:
    goto v_23009;
v_23010:
    v_23015 = Lputprop(nil, 3, v_23017, v_23016, v_23015);
    goto v_22987;
v_22987:
    v_23015 = nil;
    return onevalue(v_23015);
}



setup_type const u40_setup[] =
{
    {"formsetq0",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formsetq0},
    {"*n2a",                    CC_Hn2a,        TOO_MANY_1,    WRONG_NO_1},
    {"appn",                    TOO_FEW_2,      CC_appn,       WRONG_NO_2},
    {"maxfrom",                 TOO_FEW_2,      CC_maxfrom,    WRONG_NO_2},
    {"pasf_fact",               CC_pasf_fact,   TOO_MANY_1,    WRONG_NO_1},
    {"upperlimitrd",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_upperlimitrd},
    {"prlist",                  CC_prlist,      TOO_MANY_1,    WRONG_NO_1},
    {"copy_mat",                CC_copy_mat,    TOO_MANY_1,    WRONG_NO_1},
    {"mkbc",                    TOO_FEW_2,      CC_mkbc,       WRONG_NO_2},
    {"evweightedcomp1",         TOO_FEW_2,      CC_evweightedcomp1,WRONG_NO_2},
    {"mkupf",                   CC_mkupf,       TOO_MANY_1,    WRONG_NO_1},
    {"mod-dump1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_modKdump1},
    {"redall",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_redall},
    {"pa_list2vect",            TOO_FEW_2,      CC_pa_list2vect,WRONG_NO_2},
    {"fd2q",                    CC_fd2q,        TOO_MANY_1,    WRONG_NO_1},
    {"repr_new",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_repr_new},
    {"rl_multsurep",            TOO_FEW_2,      CC_rl_multsurep,WRONG_NO_2},
    {"intervalrd",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_intervalrd},
    {"init",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_init},
    {"fnreval",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_fnreval},
    {"vdpmember",               TOO_FEW_2,      CC_vdpmember,  WRONG_NO_2},
    {"exdf0",                   CC_exdf0,       TOO_MANY_1,    WRONG_NO_1},
    {"getphystypeexpt",         CC_getphystypeexpt,TOO_MANY_1, WRONG_NO_1},
    {"cvitimes2",               TOO_FEW_2,      CC_cvitimes2,  WRONG_NO_2},
    {"get-current-representation",CC_getKcurrentKrepresentation,TOO_MANY_1,WRONG_NO_1},
    {"basic-kern",              CC_basicKkern,  TOO_MANY_1,    WRONG_NO_1},
    {"lalr_set_nonterminal_codes",WRONG_NO_NA,  WRONG_NO_NB,   (n_args *)CC_lalr_set_nonterminal_codes},
    {"polynomread",             CC_polynomread, TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_evalatp",            TOO_FEW_2,      CC_ofsf_evalatp,WRONG_NO_2},
    {"mk+mat+plus+mat",         TOO_FEW_2,      CC_mkLmatLplusLmat,WRONG_NO_2},
    {"iv_cutcongs2",            TOO_FEW_2,      CC_iv_cutcongs2,WRONG_NO_2},
    {"symbolsrd",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_symbolsrd},
    {"evzero",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_evzero},
    {"gbfdiff",                 TOO_FEW_2,      CC_gbfdiff,    WRONG_NO_2},
    {"numprintlen",             CC_numprintlen, TOO_MANY_1,    WRONG_NO_1},
    {"mk_binding",              TOO_FEW_2,      CC_mk_binding, WRONG_NO_2},
    {"ratnump",                 CC_ratnump,     TOO_MANY_1,    WRONG_NO_1},
    {"miller-rabin",            TOO_FEW_2,      CC_millerKrabin,WRONG_NO_2},
    {"equiv-coeffs",            TOO_FEW_2,      CC_equivKcoeffs,WRONG_NO_2},
    {"*g2lex",                  CC_Hg2lex,      TOO_MANY_1,    WRONG_NO_1},
    {"simpquot",                CC_simpquot,    TOO_MANY_1,    WRONG_NO_1},
    {"isimp1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_isimp1},
    {"drop_dec_with",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_drop_dec_with},
    {NULL, (one_args *)"u40", (two_args *)"40130 7845140 503350", 0}
};

// end of generated code
