
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



// Code for ctx_union

static LispObject CC_ctx_union(LispObject env,
                         LispObject v_22277, LispObject v_22278)
{
    env = qenv(env);
    LispObject v_22434, v_22435;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22277,v_22278);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_22278;
    v_22434 = v_22277;
// end of prologue
    fn = elt(env, 5); // ctx_ial
    v_22434 = (*qfn1(fn))(fn, v_22434);
    env = stack[-5];
    stack[-4] = v_22434;
    v_22434 = stack[-4];
    if (v_22434 == nil) goto v_22296;
    else goto v_22297;
v_22296:
    v_22434 = nil;
    goto v_22290;
v_22297:
    v_22434 = stack[-4];
    v_22434 = qcar(v_22434);
    goto v_22309;
v_22305:
    v_22435 = v_22434;
    v_22435 = qcar(v_22435);
    goto v_22306;
v_22307:
    v_22434 = qcdr(v_22434);
    goto v_22308;
v_22309:
    goto v_22305;
v_22306:
    goto v_22307;
v_22308:
    v_22434 = cons(v_22435, v_22434);
    env = stack[-5];
    v_22434 = ncons(v_22434);
    env = stack[-5];
    stack[-1] = v_22434;
    stack[-3] = v_22434;
v_22291:
    v_22434 = stack[-4];
    v_22434 = qcdr(v_22434);
    stack[-4] = v_22434;
    v_22434 = stack[-4];
    if (v_22434 == nil) goto v_22318;
    else goto v_22319;
v_22318:
    v_22434 = stack[-3];
    goto v_22290;
v_22319:
    goto v_22327;
v_22323:
    stack[0] = stack[-1];
    goto v_22324;
v_22325:
    v_22434 = stack[-4];
    v_22434 = qcar(v_22434);
    goto v_22338;
v_22334:
    v_22435 = v_22434;
    v_22435 = qcar(v_22435);
    goto v_22335;
v_22336:
    v_22434 = qcdr(v_22434);
    goto v_22337;
v_22338:
    goto v_22334;
v_22335:
    goto v_22336;
v_22337:
    v_22434 = cons(v_22435, v_22434);
    env = stack[-5];
    v_22434 = ncons(v_22434);
    env = stack[-5];
    goto v_22326;
v_22327:
    goto v_22323;
v_22324:
    goto v_22325;
v_22326:
    v_22434 = Lrplacd(nil, stack[0], v_22434);
    env = stack[-5];
    v_22434 = stack[-1];
    v_22434 = qcdr(v_22434);
    stack[-1] = v_22434;
    goto v_22291;
v_22290:
    stack[-4] = v_22434;
    v_22434 = stack[-2];
    fn = elt(env, 5); // ctx_ial
    v_22434 = (*qfn1(fn))(fn, v_22434);
    env = stack[-5];
    stack[-3] = v_22434;
    v_22434 = stack[-3];
    if (v_22434 == nil) goto v_22355;
    else goto v_22356;
v_22355:
    v_22434 = nil;
    goto v_22349;
v_22356:
    v_22434 = stack[-3];
    v_22434 = qcar(v_22434);
    goto v_22368;
v_22364:
    v_22435 = v_22434;
    v_22435 = qcar(v_22435);
    goto v_22365;
v_22366:
    v_22434 = qcdr(v_22434);
    goto v_22367;
v_22368:
    goto v_22364;
v_22365:
    goto v_22366;
v_22367:
    v_22434 = cons(v_22435, v_22434);
    env = stack[-5];
    v_22434 = ncons(v_22434);
    env = stack[-5];
    stack[-1] = v_22434;
    stack[-2] = v_22434;
v_22350:
    v_22434 = stack[-3];
    v_22434 = qcdr(v_22434);
    stack[-3] = v_22434;
    v_22434 = stack[-3];
    if (v_22434 == nil) goto v_22377;
    else goto v_22378;
v_22377:
    v_22434 = stack[-2];
    goto v_22349;
v_22378:
    goto v_22386;
v_22382:
    stack[0] = stack[-1];
    goto v_22383;
v_22384:
    v_22434 = stack[-3];
    v_22434 = qcar(v_22434);
    goto v_22397;
v_22393:
    v_22435 = v_22434;
    v_22435 = qcar(v_22435);
    goto v_22394;
v_22395:
    v_22434 = qcdr(v_22434);
    goto v_22396;
v_22397:
    goto v_22393;
v_22394:
    goto v_22395;
v_22396:
    v_22434 = cons(v_22435, v_22434);
    env = stack[-5];
    v_22434 = ncons(v_22434);
    env = stack[-5];
    goto v_22385;
v_22386:
    goto v_22382;
v_22383:
    goto v_22384;
v_22385:
    v_22434 = Lrplacd(nil, stack[0], v_22434);
    env = stack[-5];
    v_22434 = stack[-1];
    v_22434 = qcdr(v_22434);
    stack[-1] = v_22434;
    goto v_22350;
v_22349:
    goto v_22409;
v_22405:
    goto v_22415;
v_22411:
    v_22435 = stack[-4];
    goto v_22412;
v_22413:
    goto v_22414;
v_22415:
    goto v_22411;
v_22412:
    goto v_22413;
v_22414:
    v_22435 = list2(v_22435, v_22434);
    env = stack[-5];
    goto v_22406;
v_22407:
    v_22434 = elt(env, 2); // arg1of2
    goto v_22408;
v_22409:
    goto v_22405;
v_22406:
    goto v_22407;
v_22408:
    fn = elt(env, 6); // lto_almerge
    v_22434 = (*qfn2(fn))(fn, v_22435, v_22434);
    env = stack[-5];
    goto v_22424;
v_22420:
    stack[0] = elt(env, 3); // ctx
    goto v_22421;
v_22422:
    goto v_22431;
v_22427:
    v_22435 = v_22434;
    goto v_22428;
v_22429:
    v_22434 = elt(env, 4); // ordopcar
    goto v_22430;
v_22431:
    goto v_22427;
v_22428:
    goto v_22429;
v_22430:
    fn = elt(env, 7); // sort
    v_22434 = (*qfn2(fn))(fn, v_22435, v_22434);
    goto v_22423;
v_22424:
    goto v_22420;
v_22421:
    goto v_22422;
v_22423:
    {
        LispObject v_22441 = stack[0];
        return list2(v_22441, v_22434);
    }
    return onevalue(v_22434);
}



// Code for janettreenodebuild

static LispObject CC_janettreenodebuild(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22396, v_22397;
    LispObject fn;
    LispObject v_22279, v_22278, v_22277;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "janettreenodebuild");
    va_start(aa, nargs);
    v_22277 = va_arg(aa, LispObject);
    v_22278 = va_arg(aa, LispObject);
    v_22279 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22279,v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22277,v_22278,v_22279);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-5] = v_22279;
    stack[-6] = v_22278;
    stack[-7] = v_22277;
// end of prologue
    goto v_22291;
v_22287:
    v_22397 = stack[-5];
    goto v_22288;
v_22289:
    v_22396 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22290;
v_22291:
    goto v_22287;
v_22288:
    goto v_22289;
v_22290:
    v_22396 = *(LispObject *)((char *)v_22397 + (CELL-TAG_VECTOR) + (((intptr_t)v_22396-TAG_FIXNUM)/(16/CELL)));
    v_22396 = qcar(v_22396);
    stack[-3] = v_22396;
    goto v_22303;
v_22297:
    goto v_22309;
v_22305:
    v_22397 = stack[-3];
    goto v_22306;
v_22307:
    v_22396 = stack[-6];
    goto v_22308;
v_22309:
    goto v_22305;
v_22306:
    goto v_22307;
v_22308:
    fn = elt(env, 2); // monomgetvariabledegree
    stack[-1] = (*qfn2(fn))(fn, v_22397, v_22396);
    env = stack[-9];
    goto v_22298;
v_22299:
    stack[0] = nil;
    goto v_22300;
v_22301:
    v_22396 = nil;
    v_22396 = ncons(v_22396);
    env = stack[-9];
    goto v_22302;
v_22303:
    goto v_22297;
v_22298:
    goto v_22299;
v_22300:
    goto v_22301;
v_22302:
    v_22396 = acons(stack[-1], stack[0], v_22396);
    env = stack[-9];
    stack[-8] = v_22396;
    v_22396 = stack[-8];
    stack[-4] = v_22396;
v_22318:
    goto v_22327;
v_22323:
    stack[0] = stack[-7];
    goto v_22324;
v_22325:
    goto v_22334;
v_22330:
    v_22397 = stack[-3];
    goto v_22331;
v_22332:
    v_22396 = stack[-6];
    goto v_22333;
v_22334:
    goto v_22330;
v_22331:
    goto v_22332;
v_22333:
    fn = elt(env, 2); // monomgetvariabledegree
    v_22396 = (*qfn2(fn))(fn, v_22397, v_22396);
    env = stack[-9];
    goto v_22326;
v_22327:
    goto v_22323;
v_22324:
    goto v_22325;
v_22326:
    if (((intptr_t)(stack[0])) > ((intptr_t)(v_22396))) goto v_22322;
    goto v_22317;
v_22322:
    goto v_22342;
v_22338:
    stack[0] = stack[-7];
    goto v_22339;
v_22340:
    goto v_22349;
v_22345:
    v_22397 = stack[-3];
    goto v_22346;
v_22347:
    v_22396 = stack[-6];
    goto v_22348;
v_22349:
    goto v_22345;
v_22346:
    goto v_22347;
v_22348:
    fn = elt(env, 2); // monomgetvariabledegree
    v_22396 = (*qfn2(fn))(fn, v_22397, v_22396);
    env = stack[-9];
    goto v_22341;
v_22342:
    goto v_22338;
v_22339:
    goto v_22340;
v_22341:
    v_22396 = (LispObject)(intptr_t)((intptr_t)stack[0] - (intptr_t)v_22396 + TAG_FIXNUM);
    stack[-7] = v_22396;
    v_22396 = stack[-6];
    v_22396 = (LispObject)((intptr_t)(v_22396) + 0x10);
    stack[-6] = v_22396;
    goto v_22360;
v_22356:
    v_22396 = stack[-4];
    stack[-2] = qcdr(v_22396);
    goto v_22357;
v_22358:
    goto v_22370;
v_22364:
    goto v_22376;
v_22372:
    v_22397 = stack[-3];
    goto v_22373;
v_22374:
    v_22396 = stack[-6];
    goto v_22375;
v_22376:
    goto v_22372;
v_22373:
    goto v_22374;
v_22375:
    fn = elt(env, 2); // monomgetvariabledegree
    stack[-1] = (*qfn2(fn))(fn, v_22397, v_22396);
    env = stack[-9];
    goto v_22365;
v_22366:
    stack[0] = nil;
    goto v_22367;
v_22368:
    v_22396 = nil;
    v_22396 = ncons(v_22396);
    env = stack[-9];
    goto v_22369;
v_22370:
    goto v_22364;
v_22365:
    goto v_22366;
v_22367:
    goto v_22368;
v_22369:
    v_22396 = acons(stack[-1], stack[0], v_22396);
    env = stack[-9];
    goto v_22359;
v_22360:
    goto v_22356;
v_22357:
    goto v_22358;
v_22359:
    fn = elt(env, 3); // setcdr
    v_22396 = (*qfn2(fn))(fn, stack[-2], v_22396);
    env = stack[-9];
    v_22396 = stack[-4];
    v_22396 = qcdr(v_22396);
    v_22396 = qcdr(v_22396);
    stack[-4] = v_22396;
    goto v_22318;
v_22317:
    goto v_22391;
v_22387:
    v_22396 = stack[-4];
    v_22397 = qcar(v_22396);
    goto v_22388;
v_22389:
    v_22396 = stack[-5];
    goto v_22390;
v_22391:
    goto v_22387;
v_22388:
    goto v_22389;
v_22390:
    fn = elt(env, 3); // setcdr
    v_22396 = (*qfn2(fn))(fn, v_22397, v_22396);
    v_22396 = stack[-8];
    return onevalue(v_22396);
}



// Code for tayfkern

static LispObject CC_tayfkern(LispObject env,
                         LispObject v_22277)
{
    env = qenv(env);
    LispObject v_22341, v_22342, v_22343;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22277);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_22343 = v_22277;
// end of prologue
    v_22341 = qvalue(elt(env, 2)); // !*tayinternal!*
    if (v_22341 == nil) goto v_22287;
    v_22341 = v_22343;
    goto v_22282;
v_22287:
    v_22341 = elt(env, 3); // taylor!*
    if (!symbolp(v_22341)) v_22341 = nil;
    else { v_22341 = qfastgets(v_22341);
           if (v_22341 != nil) { v_22341 = elt(v_22341, 24); // klist
#ifdef RECORD_GET
             if (v_22341 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v_22341 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v_22341 == SPID_NOPROP) v_22341 = nil; }}
#endif
    stack[0] = v_22341;
    goto v_22296;
v_22292:
    v_22342 = v_22343;
    goto v_22293;
v_22294:
    v_22341 = stack[0];
    goto v_22295;
v_22296:
    goto v_22292;
v_22293:
    goto v_22294;
v_22295:
    v_22341 = Lassoc(nil, v_22342, v_22341);
    stack[-1] = v_22341;
    v_22341 = stack[-1];
    if (v_22341 == nil) goto v_22302;
    else goto v_22303;
v_22302:
    goto v_22310;
v_22306:
    v_22342 = v_22343;
    goto v_22307;
v_22308:
    v_22341 = nil;
    goto v_22309;
v_22310:
    goto v_22306;
v_22307:
    goto v_22308;
v_22309:
    v_22341 = list2(v_22342, v_22341);
    env = stack[-2];
    stack[-1] = v_22341;
    goto v_22318;
v_22314:
    v_22342 = stack[-1];
    goto v_22315;
v_22316:
    v_22341 = stack[0];
    goto v_22317;
v_22318:
    goto v_22314;
v_22315:
    goto v_22316;
v_22317:
    fn = elt(env, 7); // ordad
    v_22341 = (*qfn2(fn))(fn, v_22342, v_22341);
    env = stack[-2];
    stack[0] = v_22341;
    goto v_22326;
v_22322:
    v_22342 = elt(env, 4); // (taylor!*)
    goto v_22323;
v_22324:
    v_22341 = qvalue(elt(env, 5)); // kprops!*
    goto v_22325;
v_22326:
    goto v_22322;
v_22323:
    goto v_22324;
v_22325:
    fn = elt(env, 8); // union
    v_22341 = (*qfn2(fn))(fn, v_22342, v_22341);
    env = stack[-2];
    qvalue(elt(env, 5)) = v_22341; // kprops!*
    goto v_22336;
v_22330:
    v_22343 = elt(env, 3); // taylor!*
    goto v_22331;
v_22332:
    v_22342 = elt(env, 6); // klist
    goto v_22333;
v_22334:
    v_22341 = stack[0];
    goto v_22335;
v_22336:
    goto v_22330;
v_22331:
    goto v_22332;
v_22333:
    goto v_22334;
v_22335:
    v_22341 = Lputprop(nil, 3, v_22343, v_22342, v_22341);
    goto v_22301;
v_22303:
v_22301:
    v_22341 = stack[-1];
v_22282:
    return onevalue(v_22341);
}



// Code for mri_ofsf2mriat

static LispObject CC_mri_ofsf2mriat(LispObject env,
                         LispObject v_22277, LispObject v_22278)
{
    env = qenv(env);
    LispObject v_22294, v_22295, v_22296;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22294 = v_22278;
    v_22295 = v_22277;
// end of prologue
    goto v_22287;
v_22281:
    v_22296 = v_22295;
    v_22296 = qcar(v_22296);
    goto v_22282;
v_22283:
    v_22295 = qcdr(v_22295);
    v_22295 = qcar(v_22295);
    goto v_22284;
v_22285:
    goto v_22286;
v_22287:
    goto v_22281;
v_22282:
    goto v_22283;
v_22284:
    goto v_22285;
v_22286:
    {
        fn = elt(env, 1); // mri_0mk2
        return (*qfnn(fn))(fn, 3, v_22296, v_22295, v_22294);
    }
}



// Code for dip_sum

static LispObject CC_dip_sum(LispObject env,
                         LispObject v_22277, LispObject v_22278)
{
    env = qenv(env);
    LispObject v_22432, v_22433, v_22434;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22277,v_22278);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_22278;
    stack[-6] = v_22277;
// end of prologue
    stack[-7] = nil;
    stack[-4] = nil;
    stack[0] = nil;
v_22293:
    v_22432 = stack[0];
    if (v_22432 == nil) goto v_22297;
    goto v_22292;
v_22297:
    v_22432 = stack[-6];
    if (v_22432 == nil) goto v_22302;
    else goto v_22303;
v_22302:
    v_22432 = stack[-5];
    stack[-1] = v_22432;
    v_22432 = lisp_true;
    stack[0] = v_22432;
    goto v_22301;
v_22303:
    v_22432 = stack[-5];
    if (v_22432 == nil) goto v_22307;
    else goto v_22308;
v_22307:
    v_22432 = stack[-6];
    stack[-1] = v_22432;
    v_22432 = lisp_true;
    stack[0] = v_22432;
    goto v_22301;
v_22308:
    v_22432 = stack[-6];
    fn = elt(env, 2); // dip_evlmon
    v_22432 = (*qfn1(fn))(fn, v_22432);
    env = stack[-8];
    stack[-2] = v_22432;
    v_22432 = stack[-5];
    fn = elt(env, 2); // dip_evlmon
    v_22432 = (*qfn1(fn))(fn, v_22432);
    env = stack[-8];
    stack[-1] = v_22432;
    goto v_22323;
v_22319:
    v_22433 = stack[-2];
    goto v_22320;
v_22321:
    v_22432 = stack[-1];
    goto v_22322;
v_22323:
    goto v_22319;
v_22320:
    goto v_22321;
v_22322:
    fn = elt(env, 3); // ev_comp
    v_22432 = (*qfn2(fn))(fn, v_22433, v_22432);
    env = stack[-8];
    stack[-3] = v_22432;
    goto v_22335;
v_22331:
    v_22433 = stack[-3];
    goto v_22332;
v_22333:
    v_22432 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22334;
v_22335:
    goto v_22331;
v_22332:
    goto v_22333;
v_22334:
    fn = elt(env, 4); // iequal
    v_22432 = (*qfn2(fn))(fn, v_22433, v_22432);
    env = stack[-8];
    if (v_22432 == nil) goto v_22329;
    goto v_22345;
v_22339:
    v_22432 = stack[-6];
    fn = elt(env, 5); // dip_lbc
    v_22434 = (*qfn1(fn))(fn, v_22432);
    env = stack[-8];
    goto v_22340;
v_22341:
    v_22433 = stack[-2];
    goto v_22342;
v_22343:
    v_22432 = nil;
    goto v_22344;
v_22345:
    goto v_22339;
v_22340:
    goto v_22341;
v_22342:
    goto v_22343;
v_22344:
    fn = elt(env, 6); // dip_moncomp
    v_22432 = (*qfnn(fn))(fn, 3, v_22434, v_22433, v_22432);
    env = stack[-8];
    stack[-1] = v_22432;
    v_22432 = stack[-6];
    fn = elt(env, 7); // dip_mred
    v_22432 = (*qfn1(fn))(fn, v_22432);
    env = stack[-8];
    stack[-6] = v_22432;
    goto v_22327;
v_22329:
    goto v_22359;
v_22355:
    v_22433 = stack[-3];
    goto v_22356;
v_22357:
    v_22432 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_22358;
v_22359:
    goto v_22355;
v_22356:
    goto v_22357;
v_22358:
    fn = elt(env, 4); // iequal
    v_22432 = (*qfn2(fn))(fn, v_22433, v_22432);
    env = stack[-8];
    if (v_22432 == nil) goto v_22353;
    goto v_22369;
v_22363:
    v_22432 = stack[-5];
    fn = elt(env, 5); // dip_lbc
    v_22434 = (*qfn1(fn))(fn, v_22432);
    env = stack[-8];
    goto v_22364;
v_22365:
    v_22433 = stack[-1];
    goto v_22366;
v_22367:
    v_22432 = nil;
    goto v_22368;
v_22369:
    goto v_22363;
v_22364:
    goto v_22365;
v_22366:
    goto v_22367;
v_22368:
    fn = elt(env, 6); // dip_moncomp
    v_22432 = (*qfnn(fn))(fn, 3, v_22434, v_22433, v_22432);
    env = stack[-8];
    stack[-1] = v_22432;
    v_22432 = stack[-5];
    fn = elt(env, 7); // dip_mred
    v_22432 = (*qfn1(fn))(fn, v_22432);
    env = stack[-8];
    stack[-5] = v_22432;
    goto v_22327;
v_22353:
    goto v_22383;
v_22379:
    v_22432 = stack[-6];
    fn = elt(env, 5); // dip_lbc
    stack[-1] = (*qfn1(fn))(fn, v_22432);
    env = stack[-8];
    goto v_22380;
v_22381:
    v_22432 = stack[-5];
    fn = elt(env, 5); // dip_lbc
    v_22432 = (*qfn1(fn))(fn, v_22432);
    env = stack[-8];
    goto v_22382;
v_22383:
    goto v_22379;
v_22380:
    goto v_22381;
v_22382:
    fn = elt(env, 8); // bc_sum
    v_22432 = (*qfn2(fn))(fn, stack[-1], v_22432);
    env = stack[-8];
    v_22433 = v_22432;
    v_22432 = v_22433;
    if (v_22432 == nil) goto v_22391;
    goto v_22400;
v_22394:
    v_22434 = v_22433;
    goto v_22395;
v_22396:
    v_22433 = stack[-2];
    goto v_22397;
v_22398:
    v_22432 = nil;
    goto v_22399;
v_22400:
    goto v_22394;
v_22395:
    goto v_22396;
v_22397:
    goto v_22398;
v_22399:
    fn = elt(env, 6); // dip_moncomp
    v_22432 = (*qfnn(fn))(fn, 3, v_22434, v_22433, v_22432);
    env = stack[-8];
    goto v_22389;
v_22391:
    v_22432 = nil;
v_22389:
    stack[-1] = v_22432;
    v_22432 = stack[-6];
    fn = elt(env, 7); // dip_mred
    v_22432 = (*qfn1(fn))(fn, v_22432);
    env = stack[-8];
    stack[-6] = v_22432;
    v_22432 = stack[-5];
    fn = elt(env, 7); // dip_mred
    v_22432 = (*qfn1(fn))(fn, v_22432);
    env = stack[-8];
    stack[-5] = v_22432;
    goto v_22327;
v_22327:
    goto v_22301;
v_22301:
    v_22432 = stack[-1];
    if (v_22432 == nil) goto v_22411;
    v_22432 = stack[-7];
    if (v_22432 == nil) goto v_22415;
    else goto v_22416;
v_22415:
    v_22432 = stack[-1];
    stack[-4] = v_22432;
    stack[-7] = v_22432;
    goto v_22414;
v_22416:
    goto v_22426;
v_22422:
    v_22432 = stack[-4];
    v_22433 = qcdr(v_22432);
    goto v_22423;
v_22424:
    v_22432 = stack[-1];
    goto v_22425;
v_22426:
    goto v_22422;
v_22423:
    goto v_22424;
v_22425:
    fn = elt(env, 9); // setcdr
    v_22432 = (*qfn2(fn))(fn, v_22433, v_22432);
    env = stack[-8];
    v_22432 = stack[-1];
    stack[-4] = v_22432;
    goto v_22414;
v_22414:
    goto v_22409;
v_22411:
v_22409:
    goto v_22293;
v_22292:
    v_22432 = stack[-7];
    return onevalue(v_22432);
}



// Code for dipcontevmin

static LispObject CC_dipcontevmin(LispObject env,
                         LispObject v_22277, LispObject v_22278)
{
    env = qenv(env);
    LispObject v_22349, v_22350, v_22351;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22277,v_22278);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22278;
    stack[-1] = v_22277;
// end of prologue
    v_22351 = nil;
v_22286:
    v_22349 = stack[-1];
    if (v_22349 == nil) goto v_22289;
    v_22349 = stack[0];
    if (v_22349 == nil) goto v_22289;
    goto v_22290;
v_22289:
    goto v_22285;
v_22290:
    goto v_22301;
v_22297:
    goto v_22310;
v_22306:
    v_22349 = stack[-1];
    v_22350 = qcar(v_22349);
    goto v_22307;
v_22308:
    v_22349 = stack[0];
    v_22349 = qcar(v_22349);
    goto v_22309;
v_22310:
    goto v_22306;
v_22307:
    goto v_22308;
v_22309:
    if (((intptr_t)(v_22350)) < ((intptr_t)(v_22349))) goto v_22304;
    else goto v_22305;
v_22304:
    v_22349 = stack[-1];
    v_22349 = qcar(v_22349);
    goto v_22303;
v_22305:
    v_22349 = stack[0];
    v_22349 = qcar(v_22349);
    goto v_22303;
    v_22349 = nil;
v_22303:
    goto v_22298;
v_22299:
    v_22350 = v_22351;
    goto v_22300;
v_22301:
    goto v_22297;
v_22298:
    goto v_22299;
v_22300:
    v_22349 = cons(v_22349, v_22350);
    env = stack[-2];
    v_22351 = v_22349;
    v_22349 = stack[-1];
    v_22349 = qcdr(v_22349);
    stack[-1] = v_22349;
    v_22349 = stack[0];
    v_22349 = qcdr(v_22349);
    stack[0] = v_22349;
    goto v_22286;
v_22285:
v_22328:
    v_22349 = v_22351;
    if (v_22349 == nil) goto v_22331;
    goto v_22340;
v_22336:
    v_22350 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22337;
v_22338:
    v_22349 = v_22351;
    v_22349 = qcar(v_22349);
    goto v_22339;
v_22340:
    goto v_22336;
v_22337:
    goto v_22338;
v_22339:
    if (v_22350 == v_22349) goto v_22335;
    else goto v_22331;
v_22335:
    goto v_22332;
v_22331:
    goto v_22327;
v_22332:
    v_22349 = v_22351;
    v_22349 = qcdr(v_22349);
    v_22351 = v_22349;
    goto v_22328;
v_22327:
    v_22349 = v_22351;
        return Lnreverse(nil, v_22349);
    return onevalue(v_22349);
}



// Code for multiply!-by!-power!-of!-ten

static LispObject CC_multiplyKbyKpowerKofKten(LispObject env,
                         LispObject v_22277, LispObject v_22278)
{
    env = qenv(env);
    LispObject v_22362, v_22363;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22277,v_22278);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_22278;
    stack[-1] = v_22277;
// end of prologue
    goto v_22289;
v_22285:
    v_22363 = stack[0];
    goto v_22286;
v_22287:
    v_22362 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22288;
v_22289:
    goto v_22285;
v_22286:
    goto v_22287;
v_22288:
    v_22362 = (LispObject)lessp2(v_22363, v_22362);
    v_22362 = v_22362 ? lisp_true : nil;
    env = stack[-3];
    if (v_22362 == nil) goto v_22283;
    v_22362 = elt(env, 0); // multiply!-by!-power!-of!-ten
    {
        fn = elt(env, 3); // bflerrmsg
        return (*qfn1(fn))(fn, v_22362);
    }
v_22283:
    v_22362 = qvalue(elt(env, 1)); // bften!*
    stack[-2] = v_22362;
v_22300:
    goto v_22310;
v_22306:
    v_22363 = stack[0];
    goto v_22307;
v_22308:
    v_22362 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22309;
v_22310:
    goto v_22306;
v_22307:
    goto v_22308;
v_22309:
    v_22362 = (LispObject)greaterp2(v_22363, v_22362);
    v_22362 = v_22362 ? lisp_true : nil;
    env = stack[-3];
    if (v_22362 == nil) goto v_22303;
    else goto v_22304;
v_22303:
    goto v_22299;
v_22304:
    v_22362 = stack[0];
    v_22362 = Levenp(nil, v_22362);
    env = stack[-3];
    if (v_22362 == nil) goto v_22316;
    else goto v_22317;
v_22316:
    goto v_22326;
v_22322:
    v_22363 = stack[-1];
    goto v_22323;
v_22324:
    v_22362 = stack[-2];
    goto v_22325;
v_22326:
    goto v_22322;
v_22323:
    goto v_22324;
v_22325:
    fn = elt(env, 4); // times!:
    v_22362 = (*qfn2(fn))(fn, v_22363, v_22362);
    env = stack[-3];
    fn = elt(env, 5); // normbf
    v_22362 = (*qfn1(fn))(fn, v_22362);
    env = stack[-3];
    stack[-1] = v_22362;
    goto v_22315;
v_22317:
v_22315:
    goto v_22334;
v_22330:
    v_22363 = stack[0];
    goto v_22331;
v_22332:
    v_22362 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_22333;
v_22334:
    goto v_22330;
v_22331:
    goto v_22332;
v_22333:
    fn = elt(env, 6); // lshift
    v_22362 = (*qfn2(fn))(fn, v_22363, v_22362);
    env = stack[-3];
    stack[0] = v_22362;
    goto v_22343;
v_22339:
    goto v_22349;
v_22345:
    v_22363 = stack[-2];
    goto v_22346;
v_22347:
    v_22362 = stack[-2];
    goto v_22348;
v_22349:
    goto v_22345;
v_22346:
    goto v_22347;
v_22348:
    fn = elt(env, 4); // times!:
    v_22363 = (*qfn2(fn))(fn, v_22363, v_22362);
    env = stack[-3];
    goto v_22340;
v_22341:
    v_22362 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_22342;
v_22343:
    goto v_22339;
v_22340:
    goto v_22341;
v_22342:
    fn = elt(env, 7); // cut!:mt
    v_22362 = (*qfn2(fn))(fn, v_22363, v_22362);
    env = stack[-3];
    fn = elt(env, 5); // normbf
    v_22362 = (*qfn1(fn))(fn, v_22362);
    env = stack[-3];
    stack[-2] = v_22362;
    goto v_22300;
v_22299:
    goto v_22359;
v_22355:
    v_22363 = stack[-1];
    goto v_22356;
v_22357:
    v_22362 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_22358;
v_22359:
    goto v_22355;
v_22356:
    goto v_22357;
v_22358:
    fn = elt(env, 7); // cut!:mt
    v_22362 = (*qfn2(fn))(fn, v_22363, v_22362);
    env = stack[-3];
    {
        fn = elt(env, 5); // normbf
        return (*qfn1(fn))(fn, v_22362);
    }
    v_22362 = nil;
    return onevalue(v_22362);
}



// Code for rd!:difference

static LispObject CC_rdTdifference(LispObject env,
                         LispObject v_22277, LispObject v_22278)
{
    env = qenv(env);
    LispObject v_22480, v_22481, v_22482;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22277,v_22278);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_22278;
    stack[-2] = v_22277;
// end of prologue
    v_22480 = nil;
    stack[-3] = v_22480;
    v_22480 = qvalue(elt(env, 1)); // !*!*roundbf
    if (v_22480 == nil) goto v_22288;
    else goto v_22289;
v_22288:
    v_22480 = stack[-2];
    v_22480 = qcdr(v_22480);
    if (!consp(v_22480)) goto v_22293;
    else goto v_22294;
v_22293:
    v_22480 = stack[0];
    v_22480 = qcdr(v_22480);
    if (!consp(v_22480)) goto v_22299;
    else goto v_22300;
v_22299:
    goto v_22308;
v_22304:
    v_22480 = stack[-2];
    stack[-1] = qcdr(v_22480);
    goto v_22305;
v_22306:
    v_22480 = stack[0];
    v_22480 = qcdr(v_22480);
    fn = elt(env, 5); // safe!-fp!-minus
    v_22480 = (*qfn1(fn))(fn, v_22480);
    env = stack[-4];
    goto v_22307;
v_22308:
    goto v_22304;
v_22305:
    goto v_22306;
v_22307:
    fn = elt(env, 6); // safe!-fp!-plus
    v_22480 = (*qfn2(fn))(fn, stack[-1], v_22480);
    env = stack[-4];
    stack[-3] = v_22480;
    goto v_22298;
v_22300:
    v_22480 = nil;
    goto v_22298;
    v_22480 = nil;
v_22298:
    goto v_22292;
v_22294:
    v_22480 = nil;
    goto v_22292;
    v_22480 = nil;
v_22292:
    goto v_22287;
v_22289:
    v_22480 = nil;
    goto v_22287;
    v_22480 = nil;
v_22287:
    if (v_22480 == nil) goto v_22285;
    goto v_22328;
v_22324:
    v_22481 = elt(env, 2); // !:rd!:
    goto v_22325;
v_22326:
    v_22480 = stack[-3];
    goto v_22327;
v_22328:
    goto v_22324;
v_22325:
    goto v_22326;
v_22327:
    return cons(v_22481, v_22480);
v_22285:
    goto v_22343;
v_22339:
    v_22481 = stack[-2];
    goto v_22340;
v_22341:
    v_22480 = stack[0];
    goto v_22342;
v_22343:
    goto v_22339;
v_22340:
    goto v_22341;
v_22342:
    fn = elt(env, 7); // convprc2
    v_22480 = (*qfn2(fn))(fn, v_22481, v_22480);
    env = stack[-4];
    stack[-1] = v_22480;
    v_22480 = qvalue(elt(env, 4)); // yy!!
    stack[0] = v_22480;
    v_22480 = stack[-1];
    if (!consp(v_22480)) goto v_22350;
    goto v_22357;
v_22353:
    v_22481 = stack[-1];
    goto v_22354;
v_22355:
    v_22480 = stack[0];
    goto v_22356;
v_22357:
    goto v_22353;
v_22354:
    goto v_22355;
v_22356:
    fn = elt(env, 8); // difbf
    v_22480 = (*qfn2(fn))(fn, v_22481, v_22480);
    env = stack[-4];
    goto v_22348;
v_22350:
    goto v_22367;
v_22363:
    v_22481 = stack[-1];
    goto v_22364;
v_22365:
    v_22480 = stack[0];
    goto v_22366;
v_22367:
    goto v_22363;
v_22364:
    goto v_22365;
v_22366:
    v_22480 = difference2(v_22481, v_22480);
    env = stack[-4];
    stack[-3] = v_22480;
    v_22480 = stack[-3];
    fn = elt(env, 9); // fp!-infinite
    v_22480 = (*qfn1(fn))(fn, v_22480);
    env = stack[-4];
    if (v_22480 == nil) goto v_22373;
    fn = elt(env, 10); // rndbfon
    v_22480 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_22382;
v_22378:
    v_22480 = stack[-1];
    v_22480 = Lfloatp(nil, v_22480);
    env = stack[-4];
    if (v_22480 == nil) goto v_22386;
    v_22480 = stack[-1];
    fn = elt(env, 11); // fl2bf
    v_22480 = (*qfn1(fn))(fn, v_22480);
    env = stack[-4];
    stack[-2] = v_22480;
    goto v_22384;
v_22386:
    v_22480 = stack[-1];
    if (!consp(v_22480)) goto v_22397;
    v_22480 = stack[-1];
    goto v_22395;
v_22397:
    v_22480 = stack[-1];
    v_22480 = integerp(v_22480);
    if (v_22480 == nil) goto v_22401;
    goto v_22411;
v_22405:
    v_22482 = elt(env, 2); // !:rd!:
    goto v_22406;
v_22407:
    v_22481 = stack[-1];
    goto v_22408;
v_22409:
    v_22480 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22410;
v_22411:
    goto v_22405;
v_22406:
    goto v_22407;
v_22408:
    goto v_22409;
v_22410:
    v_22480 = list2star(v_22482, v_22481, v_22480);
    env = stack[-4];
    goto v_22395;
v_22401:
    v_22480 = stack[-1];
    fn = elt(env, 12); // read!:num
    v_22480 = (*qfn1(fn))(fn, v_22480);
    env = stack[-4];
    goto v_22395;
    v_22480 = nil;
v_22395:
    fn = elt(env, 13); // normbf
    v_22480 = (*qfn1(fn))(fn, v_22480);
    env = stack[-4];
    stack[-2] = v_22480;
    goto v_22384;
    stack[-2] = nil;
v_22384:
    stack[-1] = stack[-2];
    goto v_22379;
v_22380:
    v_22480 = stack[0];
    v_22480 = Lfloatp(nil, v_22480);
    env = stack[-4];
    if (v_22480 == nil) goto v_22422;
    v_22480 = stack[0];
    fn = elt(env, 11); // fl2bf
    v_22480 = (*qfn1(fn))(fn, v_22480);
    env = stack[-4];
    goto v_22420;
v_22422:
    v_22480 = stack[0];
    if (!consp(v_22480)) goto v_22433;
    v_22480 = stack[0];
    goto v_22431;
v_22433:
    v_22480 = stack[0];
    v_22480 = integerp(v_22480);
    if (v_22480 == nil) goto v_22437;
    goto v_22447;
v_22441:
    v_22482 = elt(env, 2); // !:rd!:
    goto v_22442;
v_22443:
    v_22481 = stack[0];
    goto v_22444;
v_22445:
    v_22480 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22446;
v_22447:
    goto v_22441;
v_22442:
    goto v_22443;
v_22444:
    goto v_22445;
v_22446:
    v_22480 = list2star(v_22482, v_22481, v_22480);
    env = stack[-4];
    goto v_22431;
v_22437:
    v_22480 = stack[0];
    fn = elt(env, 12); // read!:num
    v_22480 = (*qfn1(fn))(fn, v_22480);
    env = stack[-4];
    goto v_22431;
    v_22480 = nil;
v_22431:
    fn = elt(env, 13); // normbf
    v_22480 = (*qfn1(fn))(fn, v_22480);
    env = stack[-4];
    goto v_22420;
    v_22480 = nil;
v_22420:
    stack[0] = v_22480;
    goto v_22381;
v_22382:
    goto v_22378;
v_22379:
    goto v_22380;
v_22381:
    fn = elt(env, 8); // difbf
    v_22480 = (*qfn2(fn))(fn, stack[-2], v_22480);
    env = stack[-4];
    goto v_22371;
v_22373:
    v_22480 = stack[-3];
    goto v_22371;
    v_22480 = nil;
v_22371:
    goto v_22348;
    v_22480 = nil;
v_22348:
    stack[-2] = v_22480;
    goto v_22466;
v_22460:
    goto v_22461;
v_22462:
    goto v_22463;
v_22464:
    v_22480 = stack[0];
    if (!consp(v_22480)) goto v_22471;
    else goto v_22472;
v_22471:
    v_22480 = stack[0];
    v_22480 = negate(v_22480);
    env = stack[-4];
    goto v_22470;
v_22472:
    v_22480 = stack[0];
    fn = elt(env, 14); // minus!:
    v_22480 = (*qfn1(fn))(fn, v_22480);
    env = stack[-4];
    goto v_22470;
    v_22480 = nil;
v_22470:
    goto v_22465;
v_22466:
    goto v_22460;
v_22461:
    goto v_22462;
v_22463:
    goto v_22464;
v_22465:
    fn = elt(env, 15); // rdzchk
    v_22480 = (*qfnn(fn))(fn, 3, stack[-2], stack[-1], v_22480);
    env = stack[-4];
    {
        fn = elt(env, 16); // mkround
        return (*qfn1(fn))(fn, v_22480);
    }
    goto v_22283;
    v_22480 = nil;
v_22283:
    return onevalue(v_22480);
}



// Code for simppartdf

static LispObject CC_simppartdf(LispObject env,
                         LispObject v_22277)
{
    env = qenv(env);
    LispObject v_22282;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22277);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_22282 = v_22277;
// end of prologue
    fn = elt(env, 1); // partitpartdf
    v_22282 = (*qfn1(fn))(fn, v_22282);
    env = stack[0];
    {
        fn = elt(env, 2); // !*pf2sq
        return (*qfn1(fn))(fn, v_22282);
    }
}



// Code for calc_den_tar

static LispObject CC_calc_den_tar(LispObject env,
                         LispObject v_22277, LispObject v_22278)
{
    env = qenv(env);
    LispObject v_22305, v_22306;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22277,v_22278);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_22305 = v_22278;
    v_22306 = v_22277;
// end of prologue
    goto v_22285;
v_22281:
    goto v_22282;
v_22283:
    goto v_22284;
v_22285:
    goto v_22281;
v_22282:
    goto v_22283;
v_22284:
    fn = elt(env, 1); // denlist
    v_22305 = (*qfn2(fn))(fn, v_22306, v_22305);
    env = stack[0];
    v_22306 = v_22305;
    v_22305 = v_22306;
    if (v_22305 == nil) goto v_22291;
    else goto v_22292;
v_22291:
    v_22305 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22290;
v_22292:
    v_22305 = v_22306;
    v_22305 = qcdr(v_22305);
    if (v_22305 == nil) goto v_22295;
    else goto v_22296;
v_22295:
    v_22305 = v_22306;
    v_22305 = qcar(v_22305);
    goto v_22290;
v_22296:
    v_22305 = v_22306;
    {
        fn = elt(env, 2); // constimes
        return (*qfn1(fn))(fn, v_22305);
    }
    v_22305 = nil;
v_22290:
    return onevalue(v_22305);
}



// Code for prepsq!*1

static LispObject CC_prepsqH1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22991, v_22992, v_22993;
    LispObject fn;
    LispObject v_22279, v_22278, v_22277;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "prepsq*1");
    va_start(aa, nargs);
    v_22277 = va_arg(aa, LispObject);
    v_22278 = va_arg(aa, LispObject);
    v_22279 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22279,v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22277,v_22278,v_22279);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_22279;
    stack[-5] = v_22278;
    stack[-6] = v_22277;
// end of prologue
    v_22991 = stack[-6];
    if (!consp(v_22991)) goto v_22297;
    else goto v_22298;
v_22297:
    v_22991 = lisp_true;
    goto v_22296;
v_22298:
    v_22991 = stack[-6];
    v_22991 = qcar(v_22991);
    v_22991 = (consp(v_22991) ? nil : lisp_true);
    goto v_22296;
    v_22991 = nil;
v_22296:
    if (v_22991 == nil) goto v_22293;
    else goto v_22294;
v_22293:
    goto v_22313;
v_22309:
    v_22991 = stack[-6];
    v_22991 = qcar(v_22991);
    v_22991 = qcar(v_22991);
    v_22992 = qcar(v_22991);
    goto v_22310;
v_22311:
    v_22991 = qvalue(elt(env, 2)); // factors!*
    goto v_22312;
v_22313:
    goto v_22309;
v_22310:
    goto v_22311;
v_22312:
    v_22991 = Lmember(nil, v_22992, v_22991);
    if (v_22991 == nil) goto v_22308;
    else goto v_22307;
v_22308:
    v_22991 = stack[-6];
    v_22991 = qcar(v_22991);
    v_22991 = qcar(v_22991);
    v_22991 = qcar(v_22991);
    if (!consp(v_22991)) goto v_22323;
    goto v_22332;
v_22328:
    v_22991 = stack[-6];
    v_22991 = qcar(v_22991);
    v_22991 = qcar(v_22991);
    v_22991 = qcar(v_22991);
    v_22992 = qcar(v_22991);
    goto v_22329;
v_22330:
    v_22991 = qvalue(elt(env, 2)); // factors!*
    goto v_22331;
v_22332:
    goto v_22328;
v_22329:
    goto v_22330;
v_22331:
    v_22991 = Lmember(nil, v_22992, v_22991);
    goto v_22321;
v_22323:
    v_22991 = nil;
    goto v_22321;
    v_22991 = nil;
v_22321:
v_22307:
    goto v_22292;
v_22294:
    v_22991 = nil;
    goto v_22292;
    v_22991 = nil;
v_22292:
    if (v_22991 == nil) goto v_22290;
    goto v_22351;
v_22347:
    goto v_22360;
v_22356:
    v_22992 = stack[-5];
    goto v_22357;
v_22358:
    v_22991 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22359;
v_22360:
    goto v_22356;
v_22357:
    goto v_22358;
v_22359:
    if (v_22992 == v_22991) goto v_22354;
    else goto v_22355;
v_22354:
    goto v_22368;
v_22364:
    goto v_22374;
v_22370:
    v_22991 = stack[-6];
    v_22991 = qcar(v_22991);
    v_22992 = qcdr(v_22991);
    goto v_22371;
v_22372:
    v_22991 = stack[-5];
    goto v_22373;
v_22374:
    goto v_22370;
v_22371:
    goto v_22372;
v_22373:
    stack[0] = cons(v_22992, v_22991);
    env = stack[-8];
    goto v_22365;
v_22366:
    goto v_22384;
v_22380:
    v_22991 = stack[-6];
    v_22991 = qcar(v_22991);
    v_22992 = qcar(v_22991);
    goto v_22381;
v_22382:
    v_22991 = stack[-4];
    goto v_22383;
v_22384:
    goto v_22380;
v_22381:
    goto v_22382;
v_22383:
    v_22991 = cons(v_22992, v_22991);
    env = stack[-8];
    goto v_22367;
v_22368:
    goto v_22364;
v_22365:
    goto v_22366;
v_22367:
    fn = elt(env, 13); // prepsq!*0
    v_22991 = (*qfn2(fn))(fn, stack[0], v_22991);
    env = stack[-8];
    stack[0] = v_22991;
    goto v_22353;
v_22355:
    v_22991 = stack[-6];
    v_22991 = qcar(v_22991);
    v_22991 = qcar(v_22991);
    v_22991 = qcdr(v_22991);
    stack[-2] = v_22991;
    v_22991 = stack[-5];
    stack[-1] = v_22991;
    goto v_22408;
v_22404:
    goto v_22414;
v_22410:
    v_22991 = stack[-6];
    v_22991 = qcar(v_22991);
    v_22991 = qcar(v_22991);
    v_22992 = qcar(v_22991);
    goto v_22411;
v_22412:
    v_22991 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22413;
v_22414:
    goto v_22410;
v_22411:
    goto v_22412;
v_22413:
    fn = elt(env, 14); // to
    v_22992 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    goto v_22405;
v_22406:
    v_22991 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22407;
v_22408:
    goto v_22404;
v_22405:
    goto v_22406;
v_22407:
    v_22991 = cons(v_22992, v_22991);
    env = stack[-8];
    v_22991 = ncons(v_22991);
    env = stack[-8];
    stack[0] = v_22991;
v_22423:
    goto v_22433;
v_22429:
    v_22992 = stack[-1];
    goto v_22430;
v_22431:
    v_22991 = stack[0];
    goto v_22432;
v_22433:
    goto v_22429;
v_22430:
    goto v_22431;
v_22432:
    fn = elt(env, 15); // quotfm
    v_22991 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    stack[-7] = v_22991;
    if (v_22991 == nil) goto v_22426;
    else goto v_22427;
v_22426:
    goto v_22422;
v_22427:
    v_22991 = stack[-7];
    stack[-1] = v_22991;
    v_22991 = stack[-2];
    v_22991 = sub1(v_22991);
    env = stack[-8];
    stack[-2] = v_22991;
    goto v_22423;
v_22422:
    goto v_22445;
v_22441:
    goto v_22451;
v_22447:
    v_22991 = stack[-6];
    v_22991 = qcar(v_22991);
    v_22992 = qcdr(v_22991);
    goto v_22448;
v_22449:
    v_22991 = stack[-1];
    goto v_22450;
v_22451:
    goto v_22447;
v_22448:
    goto v_22449;
v_22450:
    stack[0] = cons(v_22992, v_22991);
    env = stack[-8];
    goto v_22442;
v_22443:
    goto v_22465;
v_22461:
    v_22992 = stack[-2];
    goto v_22462;
v_22463:
    v_22991 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22464;
v_22465:
    goto v_22461;
v_22462:
    goto v_22463;
v_22464:
    v_22991 = (LispObject)greaterp2(v_22992, v_22991);
    v_22991 = v_22991 ? lisp_true : nil;
    env = stack[-8];
    if (v_22991 == nil) goto v_22459;
    goto v_22473;
v_22469:
    goto v_22479;
v_22475:
    v_22991 = stack[-6];
    v_22991 = qcar(v_22991);
    v_22991 = qcar(v_22991);
    v_22992 = qcar(v_22991);
    goto v_22476;
v_22477:
    v_22991 = stack[-2];
    goto v_22478;
v_22479:
    goto v_22475;
v_22476:
    goto v_22477;
v_22478:
    fn = elt(env, 14); // to
    v_22992 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    goto v_22470;
v_22471:
    v_22991 = stack[-4];
    goto v_22472;
v_22473:
    goto v_22469;
v_22470:
    goto v_22471;
v_22472:
    v_22991 = cons(v_22992, v_22991);
    env = stack[-8];
    goto v_22457;
v_22459:
    goto v_22493;
v_22489:
    v_22992 = stack[-2];
    goto v_22490;
v_22491:
    v_22991 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22492;
v_22493:
    goto v_22489;
v_22490:
    goto v_22491;
v_22492:
    v_22991 = (LispObject)lessp2(v_22992, v_22991);
    v_22991 = v_22991 ? lisp_true : nil;
    env = stack[-8];
    if (v_22991 == nil) goto v_22487;
    goto v_22501;
v_22497:
    goto v_22507;
v_22503:
    goto v_22515;
v_22509:
    v_22993 = elt(env, 4); // expt
    goto v_22510;
v_22511:
    v_22991 = stack[-6];
    v_22991 = qcar(v_22991);
    v_22991 = qcar(v_22991);
    v_22992 = qcar(v_22991);
    goto v_22512;
v_22513:
    v_22991 = stack[-2];
    goto v_22514;
v_22515:
    goto v_22509;
v_22510:
    goto v_22511;
v_22512:
    goto v_22513;
v_22514:
    v_22992 = list3(v_22993, v_22992, v_22991);
    env = stack[-8];
    goto v_22504;
v_22505:
    v_22991 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22506;
v_22507:
    goto v_22503;
v_22504:
    goto v_22505;
v_22506:
    fn = elt(env, 16); // mksp
    v_22992 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    goto v_22498;
v_22499:
    v_22991 = stack[-4];
    goto v_22500;
v_22501:
    goto v_22497;
v_22498:
    goto v_22499;
v_22500:
    v_22991 = cons(v_22992, v_22991);
    env = stack[-8];
    goto v_22457;
v_22487:
    v_22991 = stack[-4];
    goto v_22457;
    v_22991 = nil;
v_22457:
    goto v_22444;
v_22445:
    goto v_22441;
v_22442:
    goto v_22443;
v_22444:
    fn = elt(env, 13); // prepsq!*0
    v_22991 = (*qfn2(fn))(fn, stack[0], v_22991);
    env = stack[-8];
    stack[0] = v_22991;
    goto v_22353;
    stack[0] = nil;
v_22353:
    goto v_22348;
v_22349:
    goto v_22532;
v_22528:
    goto v_22538;
v_22534:
    v_22991 = stack[-6];
    v_22992 = qcdr(v_22991);
    goto v_22535;
v_22536:
    v_22991 = stack[-5];
    goto v_22537;
v_22538:
    goto v_22534;
v_22535:
    goto v_22536;
v_22537:
    v_22992 = cons(v_22992, v_22991);
    env = stack[-8];
    goto v_22529;
v_22530:
    v_22991 = stack[-4];
    goto v_22531;
v_22532:
    goto v_22528;
v_22529:
    goto v_22530;
v_22531:
    fn = elt(env, 13); // prepsq!*0
    v_22991 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    goto v_22350;
v_22351:
    goto v_22347;
v_22348:
    goto v_22349;
v_22350:
    {
        LispObject v_23002 = stack[0];
        fn = elt(env, 17); // nconc!*
        return (*qfn2(fn))(fn, v_23002, v_22991);
    }
v_22290:
    v_22991 = stack[-5];
    if (!consp(v_22991)) goto v_22549;
    else goto v_22550;
v_22549:
    v_22991 = lisp_true;
    goto v_22548;
v_22550:
    v_22991 = stack[-5];
    v_22991 = qcar(v_22991);
    v_22991 = (consp(v_22991) ? nil : lisp_true);
    goto v_22548;
    v_22991 = nil;
v_22548:
    if (v_22991 == nil) goto v_22545;
    else goto v_22546;
v_22545:
    v_22991 = qvalue(elt(env, 5)); // kord!*
    stack[-3] = v_22991;
v_22561:
    v_22991 = stack[-3];
    if (v_22991 == nil) goto v_22565;
    else goto v_22566;
v_22565:
    goto v_22560;
v_22566:
    v_22991 = stack[-3];
    v_22991 = qcar(v_22991);
    stack[-2] = v_22991;
    v_22991 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_22991;
    goto v_22585;
v_22581:
    goto v_22591;
v_22587:
    v_22992 = stack[-2];
    goto v_22588;
v_22589:
    v_22991 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22590;
v_22591:
    goto v_22587;
v_22588:
    goto v_22589;
v_22590:
    fn = elt(env, 14); // to
    v_22992 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    goto v_22582;
v_22583:
    v_22991 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22584;
v_22585:
    goto v_22581;
v_22582:
    goto v_22583;
v_22584:
    v_22991 = cons(v_22992, v_22991);
    env = stack[-8];
    v_22991 = ncons(v_22991);
    env = stack[-8];
    stack[0] = v_22991;
v_22597:
    goto v_22607;
v_22603:
    v_22992 = stack[-5];
    goto v_22604;
v_22605:
    v_22991 = stack[0];
    goto v_22606;
v_22607:
    goto v_22603;
v_22604:
    goto v_22605;
v_22606:
    fn = elt(env, 15); // quotfm
    v_22991 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    stack[-7] = v_22991;
    if (v_22991 == nil) goto v_22600;
    else goto v_22601;
v_22600:
    goto v_22596;
v_22601:
    v_22991 = stack[-1];
    v_22991 = sub1(v_22991);
    env = stack[-8];
    stack[-1] = v_22991;
    v_22991 = stack[-7];
    stack[-5] = v_22991;
    goto v_22597;
v_22596:
    goto v_22623;
v_22619:
    v_22992 = stack[-1];
    goto v_22620;
v_22621:
    v_22991 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22622;
v_22623:
    goto v_22619;
v_22620:
    goto v_22621;
v_22622:
    v_22991 = (LispObject)lessp2(v_22992, v_22991);
    v_22991 = v_22991 ? lisp_true : nil;
    env = stack[-8];
    if (v_22991 == nil) goto v_22617;
    goto v_22631;
v_22627:
    goto v_22637;
v_22633:
    goto v_22645;
v_22639:
    v_22993 = elt(env, 4); // expt
    goto v_22640;
v_22641:
    v_22992 = stack[-2];
    goto v_22642;
v_22643:
    v_22991 = stack[-1];
    goto v_22644;
v_22645:
    goto v_22639;
v_22640:
    goto v_22641;
v_22642:
    goto v_22643;
v_22644:
    v_22992 = list3(v_22993, v_22992, v_22991);
    env = stack[-8];
    goto v_22634;
v_22635:
    v_22991 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22636;
v_22637:
    goto v_22633;
v_22634:
    goto v_22635;
v_22636:
    fn = elt(env, 16); // mksp
    v_22992 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    goto v_22628;
v_22629:
    v_22991 = stack[-4];
    goto v_22630;
v_22631:
    goto v_22627;
v_22628:
    goto v_22629;
v_22630:
    v_22991 = cons(v_22992, v_22991);
    env = stack[-8];
    stack[-4] = v_22991;
    goto v_22615;
v_22617:
v_22615:
    v_22991 = stack[-3];
    v_22991 = qcdr(v_22991);
    stack[-3] = v_22991;
    goto v_22561;
v_22560:
    goto v_22544;
v_22546:
v_22544:
    v_22991 = stack[-6];
    fn = elt(env, 18); // kernlp
    v_22991 = (*qfn1(fn))(fn, v_22991);
    env = stack[-8];
    if (v_22991 == nil) goto v_22656;
    goto v_22664;
v_22660:
    v_22992 = stack[-4];
    goto v_22661;
v_22662:
    v_22991 = stack[-6];
    goto v_22663;
v_22664:
    goto v_22660;
v_22661:
    goto v_22662;
v_22663:
    fn = elt(env, 19); // mkkl
    v_22991 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    stack[-6] = v_22991;
    v_22991 = nil;
    stack[-4] = v_22991;
    goto v_22654;
v_22656:
v_22654:
    v_22991 = qvalue(elt(env, 7)); // dnl!*
    if (v_22991 == nil) goto v_22671;
    v_22991 = qvalue(elt(env, 8)); // !*allfac
    if (v_22991 == nil) goto v_22675;
    else goto v_22676;
v_22675:
    v_22991 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22674;
v_22676:
    v_22991 = stack[-6];
    fn = elt(env, 20); // ckrn
    v_22991 = (*qfn1(fn))(fn, v_22991);
    env = stack[-8];
    goto v_22674;
    v_22991 = nil;
v_22674:
    stack[-1] = v_22991;
    goto v_22688;
v_22684:
    v_22992 = stack[-1];
    goto v_22685;
v_22686:
    v_22991 = qvalue(elt(env, 7)); // dnl!*
    goto v_22687;
v_22688:
    goto v_22684;
v_22685:
    goto v_22686;
v_22687:
    fn = elt(env, 21); // ckrn!*
    v_22991 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    stack[-7] = v_22991;
    goto v_22696;
v_22692:
    v_22992 = stack[-1];
    goto v_22693;
v_22694:
    v_22991 = stack[-7];
    goto v_22695;
v_22696:
    goto v_22692;
v_22693:
    goto v_22694;
v_22695:
    fn = elt(env, 22); // quotof
    v_22991 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    goto v_22704;
v_22700:
    v_22992 = stack[-6];
    goto v_22701;
v_22702:
    v_22991 = stack[-7];
    goto v_22703;
v_22704:
    goto v_22700;
v_22701:
    goto v_22702;
v_22703:
    fn = elt(env, 22); // quotof
    v_22991 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    stack[-6] = v_22991;
    goto v_22712;
v_22708:
    v_22992 = stack[-5];
    goto v_22709;
v_22710:
    v_22991 = stack[-7];
    goto v_22711;
v_22712:
    goto v_22708;
v_22709:
    goto v_22710;
v_22711:
    fn = elt(env, 22); // quotof
    v_22991 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    stack[-5] = v_22991;
    goto v_22669;
v_22671:
v_22669:
    v_22991 = qvalue(elt(env, 9)); // upl!*
    if (v_22991 == nil) goto v_22718;
    v_22991 = stack[-5];
    fn = elt(env, 20); // ckrn
    v_22991 = (*qfn1(fn))(fn, v_22991);
    env = stack[-8];
    stack[0] = v_22991;
    goto v_22727;
v_22723:
    v_22992 = stack[0];
    goto v_22724;
v_22725:
    v_22991 = qvalue(elt(env, 9)); // upl!*
    goto v_22726;
v_22727:
    goto v_22723;
v_22724:
    goto v_22725;
v_22726:
    fn = elt(env, 21); // ckrn!*
    v_22991 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    stack[-7] = v_22991;
    goto v_22735;
v_22731:
    v_22992 = stack[0];
    goto v_22732;
v_22733:
    v_22991 = stack[-7];
    goto v_22734;
v_22735:
    goto v_22731;
v_22732:
    goto v_22733;
v_22734:
    fn = elt(env, 22); // quotof
    v_22991 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    stack[0] = v_22991;
    goto v_22743;
v_22739:
    v_22992 = stack[-6];
    goto v_22740;
v_22741:
    v_22991 = stack[-7];
    goto v_22742;
v_22743:
    goto v_22739;
v_22740:
    goto v_22741;
v_22742:
    fn = elt(env, 22); // quotof
    v_22991 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    stack[-6] = v_22991;
    goto v_22751;
v_22747:
    v_22992 = stack[-5];
    goto v_22748;
v_22749:
    v_22991 = stack[-7];
    goto v_22750;
v_22751:
    goto v_22747;
v_22748:
    goto v_22749;
v_22750:
    fn = elt(env, 22); // quotof
    v_22991 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    stack[-5] = v_22991;
    goto v_22716;
v_22718:
    v_22991 = qvalue(elt(env, 10)); // !*div
    if (v_22991 == nil) goto v_22755;
    v_22991 = stack[-5];
    fn = elt(env, 20); // ckrn
    v_22991 = (*qfn1(fn))(fn, v_22991);
    env = stack[-8];
    stack[0] = v_22991;
    goto v_22716;
v_22755:
    v_22991 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_22991;
    goto v_22716;
v_22716:
    goto v_22768;
v_22764:
    stack[-1] = stack[-6];
    goto v_22765;
v_22766:
    goto v_22775;
v_22771:
    v_22992 = stack[-5];
    goto v_22772;
v_22773:
    v_22991 = stack[0];
    goto v_22774;
v_22775:
    goto v_22771;
v_22772:
    goto v_22773;
v_22774:
    fn = elt(env, 22); // quotof
    v_22991 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    goto v_22767;
v_22768:
    goto v_22764;
v_22765:
    goto v_22766;
v_22767:
    v_22991 = cons(stack[-1], v_22991);
    env = stack[-8];
    fn = elt(env, 23); // canonsq
    v_22991 = (*qfn1(fn))(fn, v_22991);
    env = stack[-8];
    stack[-6] = v_22991;
    goto v_22783;
v_22779:
    goto v_22789;
v_22785:
    v_22991 = stack[-6];
    v_22992 = qcar(v_22991);
    goto v_22786;
v_22787:
    v_22991 = stack[0];
    goto v_22788;
v_22789:
    goto v_22785;
v_22786:
    goto v_22787;
v_22788:
    fn = elt(env, 22); // quotof
    v_22992 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    goto v_22780;
v_22781:
    v_22991 = stack[-6];
    v_22991 = qcdr(v_22991);
    goto v_22782;
v_22783:
    goto v_22779;
v_22780:
    goto v_22781;
v_22782:
    v_22991 = cons(v_22992, v_22991);
    env = stack[-8];
    stack[-6] = v_22991;
    v_22991 = qvalue(elt(env, 8)); // !*allfac
    if (v_22991 == nil) goto v_22798;
    v_22991 = stack[-6];
    v_22991 = qcar(v_22991);
    fn = elt(env, 20); // ckrn
    v_22991 = (*qfn1(fn))(fn, v_22991);
    env = stack[-8];
    stack[-1] = v_22991;
    v_22991 = stack[-6];
    v_22991 = qcdr(v_22991);
    fn = elt(env, 20); // ckrn
    v_22991 = (*qfn1(fn))(fn, v_22991);
    env = stack[-8];
    stack[0] = v_22991;
    goto v_22822;
v_22818:
    v_22992 = stack[-1];
    goto v_22819;
v_22820:
    v_22991 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22821;
v_22822:
    goto v_22818;
v_22819:
    goto v_22820;
v_22821:
    if (v_22992 == v_22991) goto v_22817;
    v_22991 = lisp_true;
    goto v_22815;
v_22817:
    goto v_22833;
v_22829:
    v_22992 = stack[0];
    goto v_22830;
v_22831:
    v_22991 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22832;
v_22833:
    goto v_22829;
v_22830:
    goto v_22831;
v_22832:
    v_22991 = Lneq(nil, v_22992, v_22991);
    env = stack[-8];
    goto v_22815;
    v_22991 = nil;
v_22815:
    if (v_22991 == nil) goto v_22813;
    goto v_22844;
v_22840:
    v_22992 = stack[-1];
    goto v_22841;
v_22842:
    v_22991 = stack[-6];
    v_22991 = qcar(v_22991);
    goto v_22843;
v_22844:
    goto v_22840;
v_22841:
    goto v_22842;
v_22843:
    if (equal(v_22992, v_22991)) goto v_22839;
    v_22991 = lisp_true;
    goto v_22837;
v_22839:
    goto v_22856;
v_22852:
    v_22992 = stack[0];
    goto v_22853;
v_22854:
    v_22991 = stack[-6];
    v_22991 = qcdr(v_22991);
    goto v_22855;
v_22856:
    goto v_22852;
v_22853:
    goto v_22854;
v_22855:
    v_22991 = Lneq(nil, v_22992, v_22991);
    env = stack[-8];
    goto v_22837;
    v_22991 = nil;
v_22837:
    goto v_22811;
v_22813:
    v_22991 = nil;
    goto v_22811;
    v_22991 = nil;
v_22811:
    if (v_22991 == nil) goto v_22809;
    goto v_22868;
v_22864:
    v_22991 = stack[-6];
    v_22992 = qcdr(v_22991);
    goto v_22865;
v_22866:
    v_22991 = stack[0];
    goto v_22867;
v_22868:
    goto v_22864;
v_22865:
    goto v_22866;
v_22867:
    fn = elt(env, 22); // quotof
    v_22991 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    stack[-5] = v_22991;
    goto v_22877;
v_22873:
    v_22991 = stack[-6];
    v_22992 = qcar(v_22991);
    goto v_22874;
v_22875:
    v_22991 = stack[-1];
    goto v_22876;
v_22877:
    goto v_22873;
v_22874:
    goto v_22875;
v_22876:
    fn = elt(env, 22); // quotof
    v_22991 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    stack[-6] = v_22991;
    goto v_22887;
v_22883:
    v_22992 = stack[-4];
    goto v_22884;
v_22885:
    v_22991 = stack[-1];
    goto v_22886;
v_22887:
    goto v_22883;
v_22884:
    goto v_22885;
v_22886:
    fn = elt(env, 19); // mkkl
    v_22991 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    fn = elt(env, 24); // prepf
    v_22991 = (*qfn1(fn))(fn, v_22991);
    env = stack[-8];
    stack[-4] = v_22991;
    v_22991 = stack[0];
    fn = elt(env, 24); // prepf
    v_22991 = (*qfn1(fn))(fn, v_22991);
    env = stack[-8];
    stack[-1] = v_22991;
    goto v_22897;
v_22893:
    v_22992 = stack[-4];
    goto v_22894;
v_22895:
    v_22991 = stack[-6];
    goto v_22896;
v_22897:
    goto v_22893;
v_22894:
    goto v_22895;
v_22896:
    fn = elt(env, 25); // addfactors
    v_22991 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    stack[-6] = v_22991;
    goto v_22905;
v_22901:
    v_22992 = stack[-1];
    goto v_22902;
v_22903:
    v_22991 = stack[-5];
    goto v_22904;
v_22905:
    goto v_22901;
v_22902:
    goto v_22903;
v_22904:
    fn = elt(env, 25); // addfactors
    v_22991 = (*qfn2(fn))(fn, v_22992, v_22991);
    env = stack[-8];
    stack[-5] = v_22991;
    goto v_22916;
v_22912:
    v_22992 = stack[-5];
    goto v_22913;
v_22914:
    v_22991 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22915;
v_22916:
    goto v_22912;
v_22913:
    goto v_22914;
v_22915:
    if (v_22992 == v_22991) goto v_22910;
    else goto v_22911;
v_22910:
    v_22991 = stack[-6];
    {
        fn = elt(env, 26); // rmplus
        return (*qfn1(fn))(fn, v_22991);
    }
v_22911:
    goto v_22933;
v_22929:
    v_22992 = stack[-6];
    goto v_22930;
v_22931:
    v_22991 = elt(env, 11); // minus
    goto v_22932;
v_22933:
    goto v_22929;
v_22930:
    goto v_22931;
v_22932:
    if (!consp(v_22992)) goto v_22927;
    v_22992 = qcar(v_22992);
    if (v_22992 == v_22991) goto v_22926;
    else goto v_22927;
v_22926:
    goto v_22941;
v_22937:
    stack[0] = elt(env, 11); // minus
    goto v_22938;
v_22939:
    goto v_22950;
v_22944:
    v_22993 = elt(env, 12); // quotient
    goto v_22945;
v_22946:
    v_22991 = stack[-6];
    v_22991 = qcdr(v_22991);
    v_22992 = qcar(v_22991);
    goto v_22947;
v_22948:
    v_22991 = stack[-5];
    goto v_22949;
v_22950:
    goto v_22944;
v_22945:
    goto v_22946;
v_22947:
    goto v_22948;
v_22949:
    v_22991 = list3(v_22993, v_22992, v_22991);
    env = stack[-8];
    goto v_22940;
v_22941:
    goto v_22937;
v_22938:
    goto v_22939;
v_22940:
    v_22991 = list2(stack[0], v_22991);
    goto v_22925;
v_22927:
    goto v_22965;
v_22959:
    v_22993 = elt(env, 12); // quotient
    goto v_22960;
v_22961:
    v_22992 = stack[-6];
    goto v_22962;
v_22963:
    v_22991 = stack[-5];
    goto v_22964;
v_22965:
    goto v_22959;
v_22960:
    goto v_22961;
v_22962:
    goto v_22963;
v_22964:
    v_22991 = list3(v_22993, v_22992, v_22991);
    goto v_22925;
    v_22991 = nil;
v_22925:
    return ncons(v_22991);
    v_22991 = nil;
    goto v_22285;
v_22809:
    goto v_22796;
v_22798:
v_22796:
    v_22991 = stack[-4];
    if (v_22991 == nil) goto v_22972;
    goto v_22981;
v_22977:
    v_22991 = stack[-4];
    fn = elt(env, 27); // exchk
    stack[0] = (*qfn1(fn))(fn, v_22991);
    env = stack[-8];
    goto v_22978;
v_22979:
    v_22991 = stack[-6];
    fn = elt(env, 28); // prepsq
    v_22991 = (*qfn1(fn))(fn, v_22991);
    env = stack[-8];
    goto v_22980;
v_22981:
    goto v_22977;
v_22978:
    goto v_22979;
v_22980:
    fn = elt(env, 29); // aconc!*
    v_22991 = (*qfn2(fn))(fn, stack[0], v_22991);
    env = stack[-8];
    fn = elt(env, 30); // retimes
    v_22991 = (*qfn1(fn))(fn, v_22991);
    return ncons(v_22991);
v_22972:
    v_22991 = stack[-6];
    fn = elt(env, 28); // prepsq
    v_22991 = (*qfn1(fn))(fn, v_22991);
    env = stack[-8];
    {
        fn = elt(env, 26); // rmplus
        return (*qfn1(fn))(fn, v_22991);
    }
    v_22991 = nil;
v_22285:
    return onevalue(v_22991);
}



// Code for atom_compare

static LispObject CC_atom_compare(LispObject env,
                         LispObject v_22277, LispObject v_22278)
{
    env = qenv(env);
    LispObject v_22317, v_22318, v_22319;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22277,v_22278);
    }
// copy arguments values to proper place
    v_22318 = v_22278;
    v_22319 = v_22277;
// end of prologue
    v_22317 = v_22319;
    if (is_number(v_22317)) goto v_22282;
    else goto v_22283;
v_22282:
    v_22317 = v_22318;
    if (is_number(v_22317)) goto v_22288;
    v_22317 = nil;
    goto v_22286;
v_22288:
    goto v_22298;
v_22294:
    v_22317 = v_22319;
    goto v_22295;
v_22296:
    goto v_22297;
v_22298:
    goto v_22294;
v_22295:
    goto v_22296;
v_22297:
    v_22317 = (LispObject)lessp2(v_22317, v_22318);
    v_22317 = v_22317 ? lisp_true : nil;
    v_22317 = (v_22317 == nil ? lisp_true : nil);
    goto v_22286;
    v_22317 = nil;
v_22286:
    goto v_22281;
v_22283:
    v_22317 = v_22318;
    if (symbolp(v_22317)) goto v_22302;
    else goto v_22303;
v_22302:
    goto v_22310;
v_22306:
    v_22317 = v_22319;
    goto v_22307;
v_22308:
    goto v_22309;
v_22310:
    goto v_22306;
v_22307:
    goto v_22308;
v_22309:
        return Lorderp(nil, v_22317, v_22318);
v_22303:
    v_22317 = v_22318;
    v_22317 = (is_number(v_22317) ? lisp_true : nil);
    goto v_22281;
    v_22317 = nil;
v_22281:
    return onevalue(v_22317);
}



// Code for makeqn!-maybe

static LispObject CC_makeqnKmaybe(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22300, v_22301, v_22302;
    LispObject v_22279, v_22278, v_22277;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "makeqn-maybe");
    va_start(aa, nargs);
    v_22277 = va_arg(aa, LispObject);
    v_22278 = va_arg(aa, LispObject);
    v_22279 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22300 = v_22279;
    v_22301 = v_22278;
    v_22302 = v_22277;
// end of prologue
    if (v_22300 == nil) goto v_22284;
    v_22300 = v_22301;
    goto v_22282;
v_22284:
    goto v_22296;
v_22290:
    v_22300 = elt(env, 1); // equal
    goto v_22291;
v_22292:
    goto v_22293;
v_22294:
    goto v_22295;
v_22296:
    goto v_22290;
v_22291:
    goto v_22292;
v_22293:
    goto v_22294;
v_22295:
    return list3(v_22300, v_22302, v_22301);
    v_22300 = nil;
v_22282:
    return onevalue(v_22300);
}



// Code for vector!-to!-poly

static LispObject CC_vectorKtoKpoly(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22371, v_22372, v_22373;
    LispObject fn;
    LispObject v_22279, v_22278, v_22277;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "vector-to-poly");
    va_start(aa, nargs);
    v_22277 = va_arg(aa, LispObject);
    v_22278 = va_arg(aa, LispObject);
    v_22279 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22279,v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22277,v_22278,v_22279);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_22279;
    stack[-2] = v_22278;
    stack[-3] = v_22277;
// end of prologue
    goto v_22293;
v_22289:
    v_22372 = stack[-2];
    goto v_22290;
v_22291:
    v_22371 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22292;
v_22293:
    goto v_22289;
v_22290:
    goto v_22291;
v_22292:
    if (((intptr_t)(v_22372)) < ((intptr_t)(v_22371))) goto v_22287;
    else goto v_22288;
v_22287:
    v_22371 = nil;
    goto v_22283;
v_22288:
    goto v_22302;
v_22298:
    v_22372 = stack[-3];
    goto v_22299;
v_22300:
    v_22371 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22301;
v_22302:
    goto v_22298;
v_22299:
    goto v_22300;
v_22301:
    v_22371 = *(LispObject *)((char *)v_22372 + (CELL-TAG_VECTOR) + (((intptr_t)v_22371-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 2); // !*n2f
    v_22371 = (*qfn1(fn))(fn, v_22371);
    env = stack[-5];
    stack[-4] = v_22371;
    v_22371 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_22371;
v_22309:
    goto v_22321;
v_22317:
    v_22372 = stack[-2];
    goto v_22318;
v_22319:
    v_22371 = stack[0];
    goto v_22320;
v_22321:
    goto v_22317;
v_22318:
    goto v_22319;
v_22320:
    v_22371 = difference2(v_22372, v_22371);
    env = stack[-5];
    v_22371 = Lminusp(nil, v_22371);
    env = stack[-5];
    if (v_22371 == nil) goto v_22314;
    goto v_22308;
v_22314:
    goto v_22333;
v_22329:
    goto v_22338;
v_22334:
    v_22372 = stack[-3];
    goto v_22335;
v_22336:
    v_22371 = stack[0];
    goto v_22337;
v_22338:
    goto v_22334;
v_22335:
    goto v_22336;
v_22337:
    v_22372 = *(LispObject *)((char *)v_22372 + (CELL-TAG_VECTOR) + (((intptr_t)v_22371-TAG_FIXNUM)/(16/CELL)));
    goto v_22330;
v_22331:
    v_22371 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22332;
v_22333:
    goto v_22329;
v_22330:
    goto v_22331;
v_22332:
    if (v_22372 == v_22371) goto v_22328;
    goto v_22350;
v_22344:
    goto v_22356;
v_22352:
    v_22372 = stack[-1];
    goto v_22353;
v_22354:
    v_22371 = stack[0];
    goto v_22355;
v_22356:
    goto v_22352;
v_22353:
    goto v_22354;
v_22355:
    fn = elt(env, 3); // to
    v_22373 = (*qfn2(fn))(fn, v_22372, v_22371);
    env = stack[-5];
    goto v_22345;
v_22346:
    goto v_22363;
v_22359:
    v_22372 = stack[-3];
    goto v_22360;
v_22361:
    v_22371 = stack[0];
    goto v_22362;
v_22363:
    goto v_22359;
v_22360:
    goto v_22361;
v_22362:
    v_22372 = *(LispObject *)((char *)v_22372 + (CELL-TAG_VECTOR) + (((intptr_t)v_22371-TAG_FIXNUM)/(16/CELL)));
    goto v_22347;
v_22348:
    v_22371 = stack[-4];
    goto v_22349;
v_22350:
    goto v_22344;
v_22345:
    goto v_22346;
v_22347:
    goto v_22348;
v_22349:
    v_22371 = acons(v_22373, v_22372, v_22371);
    env = stack[-5];
    stack[-4] = v_22371;
    goto v_22326;
v_22328:
v_22326:
    v_22371 = stack[0];
    v_22371 = add1(v_22371);
    env = stack[-5];
    stack[0] = v_22371;
    goto v_22309;
v_22308:
    v_22371 = stack[-4];
v_22283:
    return onevalue(v_22371);
}



// Code for set_parser

static LispObject CC_set_parser(LispObject env,
                         LispObject v_22277)
{
    env = qenv(env);
    LispObject v_22310, v_22311;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22277);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_22277;
// end of prologue
    v_22310 = stack[0];
    v_22310 = qcar(v_22310);
    fn = elt(env, 9); // lex_restore_context
    v_22310 = (*qfn1(fn))(fn, v_22310);
    env = stack[-1];
    v_22310 = stack[0];
    v_22310 = qcdr(v_22310);
    stack[0] = v_22310;
    v_22310 = qcar(v_22310);
    qvalue(elt(env, 2)) = v_22310; // parser_action_table
    v_22310 = stack[0];
    v_22310 = qcdr(v_22310);
    stack[0] = v_22310;
    v_22310 = qcar(v_22310);
    v_22311 = v_22310;
    v_22310 = v_22311;
    v_22310 = qcar(v_22310);
    qvalue(elt(env, 3)) = v_22310; // reduction_fn
    v_22310 = v_22311;
    v_22310 = qcdr(v_22310);
    v_22311 = v_22310;
    v_22310 = qcar(v_22310);
    qvalue(elt(env, 4)) = v_22310; // reduction_rhs_n
    v_22310 = v_22311;
    v_22310 = qcdr(v_22310);
    v_22310 = qcar(v_22310);
    qvalue(elt(env, 5)) = v_22310; // reduction_lhs
    v_22310 = stack[0];
    v_22310 = qcdr(v_22310);
    stack[0] = v_22310;
    v_22310 = qcar(v_22310);
    qvalue(elt(env, 6)) = v_22310; // parser_goto_table
    v_22310 = stack[0];
    v_22310 = qcdr(v_22310);
    stack[0] = v_22310;
    v_22310 = qcar(v_22310);
    qvalue(elt(env, 7)) = v_22310; // nonterminal_codes
    v_22310 = stack[0];
    v_22310 = qcdr(v_22310);
    v_22310 = qcar(v_22310);
    qvalue(elt(env, 8)) = v_22310; // terminal_codes
    v_22310 = nil;
    return onevalue(v_22310);
}



// Code for aex_psrem

static LispObject CC_aex_psrem(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22367, v_22368, v_22369, v_22370;
    LispObject fn;
    LispObject v_22279, v_22278, v_22277;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "aex_psrem");
    va_start(aa, nargs);
    v_22277 = va_arg(aa, LispObject);
    v_22278 = va_arg(aa, LispObject);
    v_22279 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22279,v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22277,v_22278,v_22279);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_22279;
    stack[-2] = v_22278;
    stack[-3] = v_22277;
// end of prologue
    goto v_22291;
    goto v_22289;
v_22291:
v_22289:
    v_22367 = stack[-2];
    fn = elt(env, 2); // aex_fvarl
    v_22367 = (*qfn1(fn))(fn, v_22367);
    env = stack[-5];
    if (v_22367 == nil) goto v_22295;
    else goto v_22296;
v_22295:
    {
        fn = elt(env, 3); // aex_0
        return (*qfnn(fn))(fn, 0);
    }
v_22296:
    v_22367 = stack[-3];
    fn = elt(env, 4); // aex_ex
    v_22367 = (*qfn1(fn))(fn, v_22367);
    env = stack[-5];
    v_22367 = qcar(v_22367);
    stack[-4] = v_22367;
    v_22367 = stack[-2];
    fn = elt(env, 4); // aex_ex
    v_22367 = (*qfn1(fn))(fn, v_22367);
    env = stack[-5];
    v_22367 = qcar(v_22367);
    stack[0] = v_22367;
    goto v_22312;
v_22308:
    v_22368 = stack[-2];
    goto v_22309;
v_22310:
    v_22367 = stack[-1];
    goto v_22311;
v_22312:
    goto v_22308;
v_22309:
    goto v_22310;
v_22311:
    fn = elt(env, 5); // aex_lc
    v_22367 = (*qfn2(fn))(fn, v_22368, v_22367);
    env = stack[-5];
    fn = elt(env, 6); // aex_sgn
    v_22367 = (*qfn1(fn))(fn, v_22367);
    env = stack[-5];
    goto v_22318;
    goto v_22316;
v_22318:
v_22316:
    goto v_22329;
v_22321:
    v_22370 = stack[-4];
    goto v_22322;
v_22323:
    v_22369 = stack[0];
    goto v_22324;
v_22325:
    v_22368 = stack[-1];
    goto v_22326;
v_22327:
    goto v_22328;
v_22329:
    goto v_22321;
v_22322:
    goto v_22323;
v_22324:
    goto v_22325;
v_22326:
    goto v_22327;
v_22328:
    fn = elt(env, 7); // sfto_psrem
    v_22367 = (*qfnn(fn))(fn, 4, v_22370, v_22369, v_22368, v_22367);
    env = stack[-5];
    stack[0] = v_22367;
    goto v_22340;
v_22336:
    goto v_22346;
v_22342:
    v_22368 = stack[0];
    goto v_22343;
v_22344:
    v_22367 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22345;
v_22346:
    goto v_22342;
v_22343:
    goto v_22344;
v_22345:
    stack[-1] = cons(v_22368, v_22367);
    env = stack[-5];
    goto v_22337;
v_22338:
    goto v_22354;
v_22350:
    v_22367 = stack[0];
    fn = elt(env, 8); // kernels
    stack[0] = (*qfn1(fn))(fn, v_22367);
    env = stack[-5];
    goto v_22351;
v_22352:
    goto v_22362;
v_22358:
    v_22367 = stack[-3];
    fn = elt(env, 9); // aex_ctx
    stack[-3] = (*qfn1(fn))(fn, v_22367);
    env = stack[-5];
    goto v_22359;
v_22360:
    v_22367 = stack[-2];
    fn = elt(env, 9); // aex_ctx
    v_22367 = (*qfn1(fn))(fn, v_22367);
    env = stack[-5];
    goto v_22361;
v_22362:
    goto v_22358;
v_22359:
    goto v_22360;
v_22361:
    fn = elt(env, 10); // ctx_union
    v_22367 = (*qfn2(fn))(fn, stack[-3], v_22367);
    env = stack[-5];
    goto v_22353;
v_22354:
    goto v_22350;
v_22351:
    goto v_22352;
v_22353:
    fn = elt(env, 11); // ctx_filter
    v_22367 = (*qfn2(fn))(fn, stack[0], v_22367);
    env = stack[-5];
    goto v_22339;
v_22340:
    goto v_22336;
v_22337:
    goto v_22338;
v_22339:
    fn = elt(env, 12); // aex_mk
    v_22367 = (*qfn2(fn))(fn, stack[-1], v_22367);
    env = stack[-5];
    {
        fn = elt(env, 13); // aex_mklcnt
        return (*qfn1(fn))(fn, v_22367);
    }
    return onevalue(v_22367);
}



// Code for even_action_term

static LispObject CC_even_action_term(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22349, v_22350;
    LispObject fn;
    LispObject v_22280, v_22279, v_22278, v_22277;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "even_action_term");
    va_start(aa, nargs);
    v_22277 = va_arg(aa, LispObject);
    v_22278 = va_arg(aa, LispObject);
    v_22279 = va_arg(aa, LispObject);
    v_22280 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_22280,v_22279,v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_22277,v_22278,v_22279,v_22280);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-2] = v_22280;
    stack[-3] = v_22279;
    stack[-4] = v_22278;
    stack[-5] = v_22277;
// end of prologue
    goto v_22287;
v_22283:
    goto v_22297;
v_22289:
    stack[-6] = stack[-5];
    goto v_22290;
v_22291:
    v_22349 = stack[-4];
    stack[-1] = qcar(v_22349);
    goto v_22292;
v_22293:
    stack[0] = stack[-3];
    goto v_22294;
v_22295:
    goto v_22307;
v_22303:
    goto v_22313;
v_22309:
    v_22350 = stack[-2];
    goto v_22310;
v_22311:
    v_22349 = stack[-4];
    v_22349 = qcdr(v_22349);
    goto v_22312;
v_22313:
    goto v_22309;
v_22310:
    goto v_22311;
v_22312:
    fn = elt(env, 1); // multf
    v_22350 = (*qfn2(fn))(fn, v_22350, v_22349);
    env = stack[-7];
    goto v_22304;
v_22305:
    v_22349 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22306;
v_22307:
    goto v_22303;
v_22304:
    goto v_22305;
v_22306:
    v_22349 = cons(v_22350, v_22349);
    env = stack[-7];
    goto v_22296;
v_22297:
    goto v_22289;
v_22290:
    goto v_22291;
v_22292:
    goto v_22293;
v_22294:
    goto v_22295;
v_22296:
    fn = elt(env, 2); // even_action_pow
    stack[-1] = (*qfnn(fn))(fn, 4, stack[-6], stack[-1], stack[0], v_22349);
    env = stack[-7];
    goto v_22284;
v_22285:
    goto v_22327;
v_22319:
    goto v_22320;
v_22321:
    v_22349 = stack[-4];
    stack[0] = qcdr(v_22349);
    goto v_22322;
v_22323:
    goto v_22324;
v_22325:
    goto v_22337;
v_22333:
    goto v_22334;
v_22335:
    goto v_22345;
v_22341:
    v_22349 = stack[-4];
    v_22350 = qcar(v_22349);
    goto v_22342;
v_22343:
    v_22349 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22344;
v_22345:
    goto v_22341;
v_22342:
    goto v_22343;
v_22344:
    v_22349 = cons(v_22350, v_22349);
    env = stack[-7];
    v_22349 = ncons(v_22349);
    env = stack[-7];
    goto v_22336;
v_22337:
    goto v_22333;
v_22334:
    goto v_22335;
v_22336:
    fn = elt(env, 1); // multf
    v_22349 = (*qfn2(fn))(fn, stack[-2], v_22349);
    env = stack[-7];
    goto v_22326;
v_22327:
    goto v_22319;
v_22320:
    goto v_22321;
v_22322:
    goto v_22323;
v_22324:
    goto v_22325;
v_22326:
    fn = elt(env, 3); // even_action_sf
    v_22349 = (*qfnn(fn))(fn, 4, stack[-5], stack[0], stack[-3], v_22349);
    env = stack[-7];
    goto v_22286;
v_22287:
    goto v_22283;
v_22284:
    goto v_22285;
v_22286:
    {
        LispObject v_22358 = stack[-1];
        fn = elt(env, 4); // addsq
        return (*qfn2(fn))(fn, v_22358, v_22349);
    }
}



// Code for sq_member

static LispObject CC_sq_member(LispObject env,
                         LispObject v_22277, LispObject v_22278)
{
    env = qenv(env);
    LispObject v_22301, v_22302;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22277,v_22278);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22278;
    stack[-1] = v_22277;
// end of prologue
    goto v_22288;
v_22284:
    v_22302 = stack[-1];
    goto v_22285;
v_22286:
    v_22301 = stack[0];
    v_22301 = qcar(v_22301);
    goto v_22287;
v_22288:
    goto v_22284;
v_22285:
    goto v_22286;
v_22287:
    fn = elt(env, 1); // sf_member
    v_22301 = (*qfn2(fn))(fn, v_22302, v_22301);
    env = stack[-2];
    if (v_22301 == nil) goto v_22282;
    else goto v_22281;
v_22282:
    goto v_22297;
v_22293:
    v_22302 = stack[-1];
    goto v_22294;
v_22295:
    v_22301 = stack[0];
    v_22301 = qcdr(v_22301);
    goto v_22296;
v_22297:
    goto v_22293;
v_22294:
    goto v_22295;
v_22296:
    {
        fn = elt(env, 1); // sf_member
        return (*qfn2(fn))(fn, v_22302, v_22301);
    }
v_22281:
    return onevalue(v_22301);
}



// Code for my!+nullsq!+p

static LispObject CC_myLnullsqLp(LispObject env,
                         LispObject v_22277)
{
    env = qenv(env);
    LispObject v_22289;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22289 = v_22277;
// end of prologue
    v_22289 = qcar(v_22289);
    if (v_22289 == nil) goto v_22284;
    else goto v_22285;
v_22284:
    v_22289 = lisp_true;
    goto v_22280;
v_22285:
    v_22289 = nil;
v_22280:
    return onevalue(v_22289);
}



// Code for factor!-prim!-f

static LispObject CC_factorKprimKf(LispObject env,
                         LispObject v_22277)
{
    env = qenv(env);
    LispObject v_22483, v_22484, v_22485;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22277);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_22277;
// end of prologue
    stack[-3] = nil;
    stack[-1] = nil;
    v_22483 = qvalue(elt(env, 2)); // ncmp!*
    if (v_22483 == nil) goto v_22289;
    goto v_22296;
v_22292:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22293;
v_22294:
    goto v_22303;
v_22299:
    v_22484 = stack[-2];
    goto v_22300;
v_22301:
    v_22483 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22302;
v_22303:
    goto v_22299;
v_22300:
    goto v_22301;
v_22302:
    v_22483 = cons(v_22484, v_22483);
    goto v_22295;
v_22296:
    goto v_22292;
v_22293:
    goto v_22294;
v_22295:
    {
        LispObject v_22490 = stack[0];
        return list2(v_22490, v_22483);
    }
v_22289:
    v_22483 = qvalue(elt(env, 3)); // dmode!*
    if (v_22483 == nil) goto v_22309;
    goto v_22318;
v_22314:
    v_22484 = qvalue(elt(env, 3)); // dmode!*
    goto v_22315;
v_22316:
    v_22483 = elt(env, 4); // sqfrfactorfn
    goto v_22317;
v_22318:
    goto v_22314;
v_22315:
    goto v_22316;
v_22317:
    v_22483 = get(v_22484, v_22483);
    env = stack[-4];
    stack[-1] = v_22483;
    if (v_22483 == nil) goto v_22309;
    v_22483 = qvalue(elt(env, 5)); // !*factor
    if (v_22483 == nil) goto v_22324;
    goto v_22331;
v_22327:
    v_22484 = stack[-1];
    goto v_22328;
v_22329:
    v_22483 = stack[-2];
    goto v_22330;
v_22331:
    goto v_22327;
v_22328:
    goto v_22329;
v_22330:
    v_22483 = Lapply1(nil, v_22484, v_22483);
    env = stack[-4];
    stack[0] = v_22483;
    goto v_22322;
v_22324:
    goto v_22341;
v_22337:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22338;
v_22339:
    goto v_22348;
v_22344:
    v_22484 = stack[-2];
    goto v_22345;
v_22346:
    v_22483 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22347;
v_22348:
    goto v_22344;
v_22345:
    goto v_22346;
v_22347:
    v_22483 = cons(v_22484, v_22483);
    env = stack[-4];
    goto v_22340;
v_22341:
    goto v_22337;
v_22338:
    goto v_22339;
v_22340:
    v_22483 = list2(stack[0], v_22483);
    env = stack[-4];
    stack[0] = v_22483;
    goto v_22322;
v_22322:
    goto v_22307;
v_22309:
    v_22483 = qvalue(elt(env, 3)); // dmode!*
    if (!symbolp(v_22483)) v_22483 = nil;
    else { v_22483 = qfastgets(v_22483);
           if (v_22483 != nil) { v_22483 = elt(v_22483, 3); // field
#ifdef RECORD_GET
             if (v_22483 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_22483 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_22483 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_22483 == SPID_NOPROP) v_22483 = nil; else v_22483 = lisp_true; }}
#endif
    if (v_22483 == nil) goto v_22356;
    goto v_22364;
v_22360:
    v_22483 = stack[-2];
    fn = elt(env, 7); // lnc
    v_22484 = (*qfn1(fn))(fn, v_22483);
    env = stack[-4];
    stack[-3] = v_22484;
    goto v_22361;
v_22362:
    v_22483 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22363;
v_22364:
    goto v_22360;
v_22361:
    goto v_22362;
v_22363:
    v_22483 = Lneq(nil, v_22484, v_22483);
    env = stack[-4];
    goto v_22354;
v_22356:
    v_22483 = nil;
    goto v_22354;
    v_22483 = nil;
v_22354:
    if (v_22483 == nil) goto v_22352;
    goto v_22376;
v_22372:
    stack[0] = stack[-3];
    goto v_22373;
v_22374:
    goto v_22384;
v_22380:
    v_22483 = stack[-3];
    fn = elt(env, 8); // !:recip
    v_22484 = (*qfn1(fn))(fn, v_22483);
    env = stack[-4];
    goto v_22381;
v_22382:
    v_22483 = stack[-2];
    goto v_22383;
v_22384:
    goto v_22380;
v_22381:
    goto v_22382;
v_22383:
    fn = elt(env, 9); // multd
    v_22483 = (*qfn2(fn))(fn, v_22484, v_22483);
    env = stack[-4];
    fn = elt(env, 10); // sqfrf
    v_22483 = (*qfn1(fn))(fn, v_22483);
    env = stack[-4];
    goto v_22375;
v_22376:
    goto v_22372;
v_22373:
    goto v_22374;
v_22375:
    v_22483 = cons(stack[0], v_22483);
    env = stack[-4];
    stack[0] = v_22483;
    goto v_22307;
v_22352:
    v_22483 = qvalue(elt(env, 3)); // dmode!*
    if (!symbolp(v_22483)) v_22483 = nil;
    else { v_22483 = qfastgets(v_22483);
           if (v_22483 != nil) { v_22483 = elt(v_22483, 27); // units
#ifdef RECORD_GET
             if (v_22483 != SPID_NOPROP)
                record_get(elt(fastget_names, 27), 1);
             else record_get(elt(fastget_names, 27), 0),
                v_22483 = nil; }
           else record_get(elt(fastget_names, 27), 0); }
#else
             if (v_22483 == SPID_NOPROP) v_22483 = nil; }}
#endif
    stack[-3] = v_22483;
    if (v_22483 == nil) goto v_22389;
    goto v_22398;
v_22394:
    v_22483 = stack[-2];
    fn = elt(env, 7); // lnc
    v_22484 = (*qfn1(fn))(fn, v_22483);
    env = stack[-4];
    v_22485 = v_22484;
    goto v_22395;
v_22396:
    v_22483 = stack[-3];
    goto v_22397;
v_22398:
    goto v_22394;
v_22395:
    goto v_22396;
v_22397:
    v_22483 = Lassoc(nil, v_22484, v_22483);
    stack[-3] = v_22483;
    if (v_22483 == nil) goto v_22389;
    goto v_22408;
v_22404:
    stack[0] = v_22485;
    goto v_22405;
v_22406:
    goto v_22416;
v_22412:
    v_22483 = stack[-3];
    v_22484 = qcdr(v_22483);
    goto v_22413;
v_22414:
    v_22483 = stack[-2];
    goto v_22415;
v_22416:
    goto v_22412;
v_22413:
    goto v_22414;
v_22415:
    fn = elt(env, 9); // multd
    v_22483 = (*qfn2(fn))(fn, v_22484, v_22483);
    env = stack[-4];
    fn = elt(env, 10); // sqfrf
    v_22483 = (*qfn1(fn))(fn, v_22483);
    env = stack[-4];
    goto v_22407;
v_22408:
    goto v_22404;
v_22405:
    goto v_22406;
v_22407:
    v_22483 = cons(stack[0], v_22483);
    env = stack[-4];
    stack[0] = v_22483;
    goto v_22307;
v_22389:
    goto v_22427;
v_22423:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22424;
v_22425:
    v_22483 = stack[-2];
    fn = elt(env, 10); // sqfrf
    v_22483 = (*qfn1(fn))(fn, v_22483);
    env = stack[-4];
    goto v_22426;
v_22427:
    goto v_22423;
v_22424:
    goto v_22425;
v_22426:
    v_22483 = cons(stack[0], v_22483);
    env = stack[-4];
    stack[0] = v_22483;
    goto v_22307;
v_22307:
    v_22483 = stack[-1];
    if (v_22483 == nil) goto v_22434;
    goto v_22442;
v_22438:
    v_22485 = stack[-1];
    goto v_22439;
v_22440:
    goto v_22449;
v_22445:
    v_22484 = qvalue(elt(env, 3)); // dmode!*
    goto v_22446;
v_22447:
    v_22483 = elt(env, 6); // factorfn
    goto v_22448;
v_22449:
    goto v_22445;
v_22446:
    goto v_22447;
v_22448:
    v_22483 = get(v_22484, v_22483);
    env = stack[-4];
    goto v_22441;
v_22442:
    goto v_22438;
v_22439:
    goto v_22440;
v_22441:
    if (v_22485 == v_22483) goto v_22437;
    else goto v_22434;
v_22437:
    v_22483 = stack[0];
    goto v_22284;
v_22434:
    v_22483 = stack[0];
    v_22483 = qcar(v_22483);
    v_22483 = ncons(v_22483);
    env = stack[-4];
    stack[-3] = v_22483;
    v_22483 = stack[0];
    v_22483 = qcdr(v_22483);
    stack[0] = v_22483;
v_22459:
    v_22483 = stack[0];
    if (v_22483 == nil) goto v_22464;
    else goto v_22465;
v_22464:
    goto v_22458;
v_22465:
    v_22483 = stack[0];
    v_22483 = qcar(v_22483);
    goto v_22476;
v_22472:
    fn = elt(env, 11); // factor!-prim!-sqfree!-f
    v_22484 = (*qfn1(fn))(fn, v_22483);
    env = stack[-4];
    goto v_22473;
v_22474:
    v_22483 = stack[-3];
    goto v_22475;
v_22476:
    goto v_22472;
v_22473:
    goto v_22474;
v_22475:
    fn = elt(env, 12); // fac!-merge
    v_22483 = (*qfn2(fn))(fn, v_22484, v_22483);
    env = stack[-4];
    stack[-3] = v_22483;
    v_22483 = stack[0];
    v_22483 = qcdr(v_22483);
    stack[0] = v_22483;
    goto v_22459;
v_22458:
    v_22483 = stack[-3];
v_22284:
    return onevalue(v_22483);
}



// Code for ofsf_optsplitterm

static LispObject CC_ofsf_optsplitterm(LispObject env,
                         LispObject v_22277, LispObject v_22278)
{
    env = qenv(env);
    LispObject v_22361, v_22362, v_22363;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22277,v_22278);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_22278;
    stack[-3] = v_22277;
// end of prologue
    goto v_22289;
v_22285:
    v_22362 = stack[-3];
    goto v_22286;
v_22287:
    v_22361 = stack[0];
    goto v_22288;
v_22289:
    goto v_22285;
v_22286:
    goto v_22287;
v_22288:
    fn = elt(env, 5); // sfto_reorder
    v_22361 = (*qfn2(fn))(fn, v_22362, v_22361);
    env = stack[-5];
    stack[-3] = v_22361;
    goto v_22300;
v_22296:
    goto v_22306;
v_22302:
    v_22362 = stack[-3];
    goto v_22303;
v_22304:
    v_22361 = stack[0];
    goto v_22305;
v_22306:
    goto v_22302;
v_22303:
    goto v_22304;
v_22305:
    fn = elt(env, 6); // degr
    v_22362 = (*qfn2(fn))(fn, v_22362, v_22361);
    env = stack[-5];
    stack[-4] = v_22362;
    goto v_22297;
v_22298:
    v_22361 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22299;
v_22300:
    goto v_22296;
v_22297:
    goto v_22298;
v_22299:
    if (v_22362 == v_22361) goto v_22294;
    else goto v_22295;
v_22294:
    v_22361 = nil;
    goto v_22282;
v_22295:
    goto v_22320;
v_22316:
    v_22362 = stack[-4];
    goto v_22317;
v_22318:
    v_22361 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22319;
v_22320:
    goto v_22316;
v_22317:
    goto v_22318;
v_22319:
    v_22361 = (LispObject)greaterp2(v_22362, v_22361);
    v_22361 = v_22361 ? lisp_true : nil;
    env = stack[-5];
    if (v_22361 == nil) goto v_22314;
    goto v_22333;
v_22325:
    stack[-2] = elt(env, 2); // "ofsf_optsplitterm:"
    goto v_22326;
v_22327:
    stack[-1] = stack[0];
    goto v_22328;
v_22329:
    stack[0] = elt(env, 3); // "has degree"
    goto v_22330;
v_22331:
    goto v_22344;
v_22338:
    v_22363 = stack[-4];
    goto v_22339;
v_22340:
    v_22362 = elt(env, 4); // "in"
    goto v_22341;
v_22342:
    v_22361 = stack[-3];
    goto v_22343;
v_22344:
    goto v_22338;
v_22339:
    goto v_22340;
v_22341:
    goto v_22342;
v_22343:
    v_22361 = list3(v_22363, v_22362, v_22361);
    env = stack[-5];
    goto v_22332;
v_22333:
    goto v_22325;
v_22326:
    goto v_22327;
v_22328:
    goto v_22329;
v_22330:
    goto v_22331;
v_22332:
    v_22361 = list3star(stack[-2], stack[-1], stack[0], v_22361);
    env = stack[-5];
    fn = elt(env, 7); // rederr
    v_22361 = (*qfn1(fn))(fn, v_22361);
    env = stack[-5];
    goto v_22312;
v_22314:
v_22312:
    goto v_22353;
v_22349:
    v_22361 = stack[-3];
    v_22361 = qcar(v_22361);
    v_22361 = qcdr(v_22361);
    fn = elt(env, 8); // reorder
    stack[0] = (*qfn1(fn))(fn, v_22361);
    env = stack[-5];
    goto v_22350;
v_22351:
    v_22361 = stack[-3];
    v_22361 = qcdr(v_22361);
    fn = elt(env, 8); // reorder
    v_22361 = (*qfn1(fn))(fn, v_22361);
    goto v_22352;
v_22353:
    goto v_22349;
v_22350:
    goto v_22351;
v_22352:
    {
        LispObject v_22369 = stack[0];
        return cons(v_22369, v_22361);
    }
v_22282:
    return onevalue(v_22361);
}



// Code for sfto_b!:ordexp

static LispObject CC_sfto_bTordexp(LispObject env,
                         LispObject v_22277, LispObject v_22278)
{
    env = qenv(env);
    LispObject v_22320, v_22321;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22277,v_22278);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22278;
    stack[-1] = v_22277;
// end of prologue
v_22282:
    v_22320 = stack[-1];
    if (v_22320 == nil) goto v_22285;
    else goto v_22286;
v_22285:
    v_22320 = lisp_true;
    goto v_22281;
v_22286:
    goto v_22296;
v_22292:
    v_22320 = stack[-1];
    v_22321 = qcar(v_22320);
    goto v_22293;
v_22294:
    v_22320 = stack[0];
    v_22320 = qcar(v_22320);
    goto v_22295;
v_22296:
    goto v_22292;
v_22293:
    goto v_22294;
v_22295:
    v_22320 = (LispObject)greaterp2(v_22321, v_22320);
    v_22320 = v_22320 ? lisp_true : nil;
    env = stack[-2];
    if (v_22320 == nil) goto v_22290;
    v_22320 = lisp_true;
    goto v_22281;
v_22290:
    goto v_22308;
v_22304:
    v_22320 = stack[-1];
    v_22321 = qcar(v_22320);
    goto v_22305;
v_22306:
    v_22320 = stack[0];
    v_22320 = qcar(v_22320);
    goto v_22307;
v_22308:
    goto v_22304;
v_22305:
    goto v_22306;
v_22307:
    if (equal(v_22321, v_22320)) goto v_22302;
    else goto v_22303;
v_22302:
    v_22320 = stack[-1];
    v_22320 = qcdr(v_22320);
    stack[-1] = v_22320;
    v_22320 = stack[0];
    v_22320 = qcdr(v_22320);
    stack[0] = v_22320;
    goto v_22282;
v_22303:
    v_22320 = nil;
    goto v_22281;
    v_22320 = nil;
v_22281:
    return onevalue(v_22320);
}



// Code for minusrd

static LispObject CC_minusrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22307, v_22308, v_22309;
    LispObject fn;
    argcheck(nargs, 0, "minusrd");
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
    v_22307 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_22307;
    fn = elt(env, 2); // mathml
    v_22307 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_22308 = v_22307;
    if (v_22308 == nil) goto v_22287;
    else goto v_22288;
v_22287:
    v_22307 = stack[0];
    v_22307 = ncons(v_22307);
    stack[0] = v_22307;
    goto v_22286;
v_22288:
    goto v_22301;
v_22295:
    v_22309 = stack[0];
    goto v_22296;
v_22297:
    v_22308 = v_22307;
    goto v_22298;
v_22299:
    v_22307 = nil;
    goto v_22300;
v_22301:
    goto v_22295;
v_22296:
    goto v_22297;
v_22298:
    goto v_22299;
v_22300:
    v_22307 = list2star(v_22309, v_22308, v_22307);
    env = stack[-1];
    stack[0] = v_22307;
    fn = elt(env, 3); // lex
    v_22307 = (*qfnn(fn))(fn, 0);
    goto v_22286;
v_22286:
    v_22307 = stack[0];
    return onevalue(v_22307);
}



// Code for sptransmat

static LispObject CC_sptransmat(LispObject env,
                         LispObject v_22277)
{
    env = qenv(env);
    LispObject v_22435, v_22436, v_22437, v_22438;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22277);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-1] = v_22277;
// end of prologue
    v_22435 = stack[-1];
    v_22435 = Lconsp(nil, v_22435);
    env = stack[-7];
    if (v_22435 == nil) goto v_22293;
    v_22435 = stack[-1];
    stack[0] = v_22435;
    v_22435 = stack[-1];
    fn = elt(env, 3); // matlength
    v_22435 = (*qfn1(fn))(fn, v_22435);
    env = stack[-7];
    v_22435 = qcdr(v_22435);
    goto v_22291;
v_22293:
    v_22435 = stack[-1];
    fn = elt(env, 4); // aeval
    v_22435 = (*qfn1(fn))(fn, v_22435);
    env = stack[-7];
    stack[0] = v_22435;
    v_22435 = stack[-1];
    fn = elt(env, 4); // aeval
    v_22435 = (*qfn1(fn))(fn, v_22435);
    env = stack[-7];
    fn = elt(env, 3); // matlength
    v_22435 = (*qfn1(fn))(fn, v_22435);
    env = stack[-7];
    v_22435 = qcdr(v_22435);
    goto v_22291;
v_22291:
    v_22436 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_22436;
    v_22436 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_22436;
    goto v_22315;
v_22311:
    v_22436 = v_22435;
    stack[-1] = qcar(v_22436);
    goto v_22312;
v_22313:
    goto v_22323;
v_22319:
    v_22436 = elt(env, 2); // spm
    goto v_22320;
v_22321:
    goto v_22322;
v_22323:
    goto v_22319;
v_22320:
    goto v_22321;
v_22322:
    v_22435 = cons(v_22436, v_22435);
    env = stack[-7];
    goto v_22314;
v_22315:
    goto v_22311;
v_22312:
    goto v_22313;
v_22314:
    fn = elt(env, 5); // mkempspmat
    v_22435 = (*qfn2(fn))(fn, stack[-1], v_22435);
    env = stack[-7];
    stack[-2] = v_22435;
    v_22435 = nil;
    v_22435 = ncons(v_22435);
    env = stack[-7];
    v_22435 = ncons(v_22435);
    env = stack[-7];
    stack[-3] = v_22435;
    v_22435 = stack[0];
    v_22435 = qcdr(v_22435);
    stack[-1] = v_22435;
v_22332:
    v_22435 = stack[-1];
    if (v_22435 == nil) goto v_22337;
    else goto v_22338;
v_22337:
    goto v_22331;
v_22338:
    v_22435 = stack[-1];
    v_22435 = qcar(v_22435);
    stack[0] = v_22435;
    v_22435 = stack[-6];
    v_22435 = add1(v_22435);
    env = stack[-7];
    stack[-6] = v_22435;
    v_22435 = stack[0];
    stack[0] = v_22435;
v_22350:
    v_22435 = stack[0];
    if (v_22435 == nil) goto v_22354;
    else goto v_22355;
v_22354:
    goto v_22349;
v_22355:
    v_22435 = stack[0];
    v_22435 = qcar(v_22435);
    stack[-4] = v_22435;
    v_22435 = stack[-5];
    v_22435 = add1(v_22435);
    env = stack[-7];
    stack[-5] = v_22435;
    goto v_22372;
v_22368:
    v_22436 = stack[-4];
    goto v_22369;
v_22370:
    v_22435 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22371;
v_22372:
    goto v_22368;
v_22369:
    goto v_22370;
v_22371:
    if (v_22436 == v_22435) goto v_22366;
    else goto v_22367;
v_22366:
    goto v_22365;
v_22367:
    goto v_22385;
v_22379:
    v_22437 = stack[-5];
    goto v_22380;
v_22381:
    v_22436 = stack[-4];
    goto v_22382;
v_22383:
    v_22435 = stack[-3];
    goto v_22384;
v_22385:
    goto v_22379;
v_22380:
    goto v_22381;
v_22382:
    goto v_22383;
v_22384:
    v_22435 = acons(v_22437, v_22436, v_22435);
    env = stack[-7];
    stack[-3] = v_22435;
    goto v_22365;
v_22365:
    v_22435 = stack[0];
    v_22435 = qcdr(v_22435);
    stack[0] = v_22435;
    goto v_22350;
v_22349:
    v_22435 = stack[-3];
    v_22435 = Lreverse(nil, v_22435);
    env = stack[-7];
    stack[-3] = v_22435;
    goto v_22401;
v_22397:
    stack[0] = stack[-3];
    goto v_22398;
v_22399:
    v_22435 = nil;
    v_22435 = ncons(v_22435);
    env = stack[-7];
    v_22435 = ncons(v_22435);
    env = stack[-7];
    goto v_22400;
v_22401:
    goto v_22397;
v_22398:
    goto v_22399;
v_22400:
    if (equal(stack[0], v_22435)) goto v_22396;
    goto v_22415;
v_22407:
    goto v_22421;
v_22417:
    v_22436 = stack[-2];
    goto v_22418;
v_22419:
    v_22435 = stack[-6];
    goto v_22420;
v_22421:
    goto v_22417;
v_22418:
    goto v_22419;
v_22420:
    v_22438 = list2(v_22436, v_22435);
    env = stack[-7];
    goto v_22408;
v_22409:
    v_22437 = stack[-3];
    goto v_22410;
v_22411:
    v_22436 = stack[-2];
    goto v_22412;
v_22413:
    v_22435 = nil;
    goto v_22414;
v_22415:
    goto v_22407;
v_22408:
    goto v_22409;
v_22410:
    goto v_22411;
v_22412:
    goto v_22413;
v_22414:
    fn = elt(env, 6); // letmtr3
    v_22435 = (*qfnn(fn))(fn, 4, v_22438, v_22437, v_22436, v_22435);
    env = stack[-7];
    goto v_22394;
v_22396:
v_22394:
    v_22435 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_22435;
    v_22435 = nil;
    v_22435 = ncons(v_22435);
    env = stack[-7];
    v_22435 = ncons(v_22435);
    env = stack[-7];
    stack[-3] = v_22435;
    v_22435 = stack[-1];
    v_22435 = qcdr(v_22435);
    stack[-1] = v_22435;
    goto v_22332;
v_22331:
    v_22435 = stack[-2];
    return onevalue(v_22435);
}



// Code for greatertype

static LispObject CC_greatertype(LispObject env,
                         LispObject v_22277, LispObject v_22278)
{
    env = qenv(env);
    LispObject v_22468, v_22469, v_22470;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22277,v_22278);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_22278;
    stack[-6] = v_22277;
// end of prologue
    stack[-4] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    goto v_22295;
v_22291:
    v_22468 = qvalue(elt(env, 2)); // optlang!*
    if (v_22468 == nil) goto v_22299;
    v_22468 = qvalue(elt(env, 2)); // optlang!*
    v_22469 = v_22468;
    goto v_22297;
v_22299:
    v_22468 = elt(env, 3); // fortran
    v_22469 = v_22468;
    goto v_22297;
    v_22469 = nil;
v_22297:
    goto v_22292;
v_22293:
    v_22468 = elt(env, 4); // conversion
    goto v_22294;
v_22295:
    goto v_22291;
v_22292:
    goto v_22293;
v_22294:
    v_22468 = get(v_22469, v_22468);
    env = stack[-8];
    fn = elt(env, 5); // eval
    v_22468 = (*qfn1(fn))(fn, v_22468);
    env = stack[-8];
    stack[-7] = v_22468;
    goto v_22314;
v_22310:
    v_22468 = stack[-7];
    v_22469 = qcar(v_22468);
    goto v_22311;
v_22312:
    v_22468 = stack[-5];
    goto v_22313;
v_22314:
    goto v_22310;
v_22311:
    goto v_22312;
v_22313:
    if (equal(v_22469, v_22468)) goto v_22308;
    else goto v_22309;
v_22308:
    v_22468 = lisp_true;
    stack[-1] = v_22468;
    goto v_22307;
v_22309:
    goto v_22325;
v_22321:
    v_22468 = stack[-7];
    v_22469 = qcar(v_22468);
    goto v_22322;
v_22323:
    v_22468 = stack[-6];
    goto v_22324;
v_22325:
    goto v_22321;
v_22322:
    goto v_22323;
v_22324:
    if (equal(v_22469, v_22468)) goto v_22319;
    else goto v_22320;
v_22319:
    v_22468 = nil;
    stack[-1] = v_22468;
    goto v_22307;
v_22320:
v_22334:
    v_22468 = stack[-7];
    v_22468 = qcdr(v_22468);
    stack[-7] = v_22468;
    if (v_22468 == nil) goto v_22337;
    v_22468 = stack[-4];
    if (v_22468 == nil) goto v_22342;
    else goto v_22337;
v_22342:
    goto v_22338;
v_22337:
    goto v_22333;
v_22338:
    v_22468 = stack[-7];
    v_22468 = qcar(v_22468);
    v_22470 = v_22468;
v_22349:
    v_22468 = v_22470;
    if (v_22468 == nil) goto v_22352;
    v_22468 = stack[-2];
    if (v_22468 == nil) goto v_22356;
    else goto v_22352;
v_22356:
    goto v_22353;
v_22352:
    goto v_22348;
v_22353:
    goto v_22367;
v_22363:
    v_22468 = v_22470;
    v_22469 = qcar(v_22468);
    goto v_22364;
v_22365:
    v_22468 = stack[-6];
    goto v_22366;
v_22367:
    goto v_22363;
v_22364:
    goto v_22365;
v_22366:
    if (equal(v_22469, v_22468)) goto v_22361;
    else goto v_22362;
v_22361:
    v_22468 = lisp_true;
    stack[-3] = v_22468;
    goto v_22360;
v_22362:
v_22360:
    goto v_22380;
v_22376:
    v_22468 = v_22470;
    v_22469 = qcar(v_22468);
    goto v_22377;
v_22378:
    v_22468 = stack[-5];
    goto v_22379;
v_22380:
    goto v_22376;
v_22377:
    goto v_22378;
v_22379:
    if (equal(v_22469, v_22468)) goto v_22374;
    else goto v_22375;
v_22374:
    v_22468 = lisp_true;
    stack[-2] = v_22468;
    goto v_22373;
v_22375:
    v_22468 = v_22470;
    v_22468 = qcdr(v_22468);
    v_22470 = v_22468;
    goto v_22373;
v_22373:
    goto v_22349;
v_22348:
    v_22468 = stack[-2];
    if (v_22468 == nil) goto v_22392;
    v_22468 = v_22470;
    v_22468 = qcdr(v_22468);
    v_22470 = v_22468;
v_22398:
    v_22468 = v_22470;
    if (v_22468 == nil) goto v_22401;
    v_22468 = stack[-1];
    if (v_22468 == nil) goto v_22405;
    else goto v_22401;
v_22405:
    goto v_22402;
v_22401:
    goto v_22397;
v_22402:
    goto v_22416;
v_22412:
    v_22468 = v_22470;
    v_22469 = qcar(v_22468);
    goto v_22413;
v_22414:
    v_22468 = stack[-6];
    goto v_22415;
v_22416:
    goto v_22412;
v_22413:
    goto v_22414;
v_22415:
    if (equal(v_22469, v_22468)) goto v_22410;
    else goto v_22411;
v_22410:
    v_22468 = lisp_true;
    stack[-1] = v_22468;
    stack[-3] = v_22468;
    goto v_22409;
v_22411:
    v_22468 = v_22470;
    v_22468 = qcdr(v_22468);
    v_22470 = v_22468;
    goto v_22409;
v_22409:
    goto v_22398;
v_22397:
    goto v_22390;
v_22392:
v_22390:
    v_22468 = stack[-3];
    if (v_22468 == nil) goto v_22430;
    v_22468 = stack[-2];
    if (v_22468 == nil) goto v_22433;
    else goto v_22430;
v_22433:
    goto v_22428;
v_22430:
    v_22468 = stack[-3];
    if (v_22468 == nil) goto v_22438;
    else goto v_22439;
v_22438:
    v_22468 = stack[-2];
    goto v_22437;
v_22439:
    v_22468 = nil;
    goto v_22437;
    v_22468 = nil;
v_22437:
    if (v_22468 == nil) goto v_22435;
    else goto v_22428;
v_22435:
    goto v_22429;
v_22428:
    goto v_22450;
v_22446:
    stack[0] = (LispObject)64+TAG_FIXNUM; // 4
    goto v_22447;
v_22448:
    goto v_22457;
v_22453:
    v_22469 = stack[-6];
    goto v_22454;
v_22455:
    v_22468 = stack[-5];
    goto v_22456;
v_22457:
    goto v_22453;
v_22454:
    goto v_22455;
v_22456:
    v_22468 = cons(v_22469, v_22468);
    env = stack[-8];
    goto v_22449;
v_22450:
    goto v_22446;
v_22447:
    goto v_22448;
v_22449:
    fn = elt(env, 6); // typerror
    v_22468 = (*qfn2(fn))(fn, stack[0], v_22468);
    env = stack[-8];
    goto v_22427;
v_22429:
    v_22468 = stack[-3];
    if (v_22468 == nil) goto v_22461;
    v_22468 = stack[-2];
    if (v_22468 == nil) goto v_22461;
    v_22468 = lisp_true;
    stack[-4] = v_22468;
    goto v_22427;
v_22461:
v_22427:
    goto v_22334;
v_22333:
    goto v_22307;
v_22307:
    v_22468 = stack[-1];
    return onevalue(v_22468);
}



// Code for groebspolynom3

static LispObject CC_groebspolynom3(LispObject env,
                         LispObject v_22277, LispObject v_22278)
{
    env = qenv(env);
    LispObject v_22295, v_22296;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22277,v_22278);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_22295 = v_22278;
    v_22296 = v_22277;
// end of prologue
    goto v_22289;
v_22285:
    goto v_22286;
v_22287:
    goto v_22288;
v_22289:
    goto v_22285;
v_22286:
    goto v_22287;
v_22288:
    fn = elt(env, 2); // groebspolynom4
    v_22295 = (*qfn2(fn))(fn, v_22296, v_22295);
    env = stack[-1];
    stack[0] = v_22295;
    v_22295 = stack[0];
    fn = elt(env, 3); // groebsavelterm
    v_22295 = (*qfn1(fn))(fn, v_22295);
    v_22295 = stack[0];
    return onevalue(v_22295);
}



// Code for indxsymp

static LispObject CC_indxsymp(LispObject env,
                         LispObject v_22277, LispObject v_22278)
{
    env = qenv(env);
    LispObject v_22313, v_22314;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22277,v_22278);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22278;
    stack[-1] = v_22277;
// end of prologue
v_22276:
    v_22313 = stack[0];
    if (v_22313 == nil) goto v_22282;
    else goto v_22283;
v_22282:
    v_22313 = lisp_true;
    goto v_22281;
v_22283:
    goto v_22297;
v_22293:
    v_22313 = stack[0];
    v_22314 = qcar(v_22313);
    goto v_22294;
v_22295:
    v_22313 = stack[-1];
    goto v_22296;
v_22297:
    goto v_22293;
v_22294:
    goto v_22295;
v_22296:
    v_22313 = Lapply1(nil, v_22314, v_22313);
    env = stack[-2];
    if (v_22313 == nil) goto v_22290;
    else goto v_22291;
v_22290:
    v_22313 = nil;
    goto v_22289;
v_22291:
    goto v_22309;
v_22305:
    v_22314 = stack[-1];
    goto v_22306;
v_22307:
    v_22313 = stack[0];
    v_22313 = qcdr(v_22313);
    goto v_22308;
v_22309:
    goto v_22305;
v_22306:
    goto v_22307;
v_22308:
    stack[-1] = v_22314;
    stack[0] = v_22313;
    goto v_22276;
    v_22313 = nil;
v_22289:
    goto v_22281;
    v_22313 = nil;
v_22281:
    return onevalue(v_22313);
}



// Code for dfp!-sub

static LispObject CC_dfpKsub(LispObject env,
                         LispObject v_22277, LispObject v_22278)
{
    env = qenv(env);
    LispObject v_22456, v_22457, v_22458;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22277,v_22278);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_22278;
    stack[-4] = v_22277;
// end of prologue
    v_22456 = stack[-3];
    v_22456 = qcdr(v_22456);
    v_22456 = qcar(v_22456);
    v_22457 = v_22456;
    v_22456 = v_22457;
    v_22456 = qcdr(v_22456);
    stack[-5] = v_22456;
    goto v_22299;
v_22295:
    v_22456 = v_22457;
    v_22457 = qcar(v_22456);
    stack[-2] = v_22457;
    goto v_22296;
v_22297:
    v_22456 = elt(env, 2); // generic_function
    goto v_22298;
v_22299:
    goto v_22295;
v_22296:
    goto v_22297;
v_22298:
    v_22456 = get(v_22457, v_22456);
    env = stack[-6];
    stack[-1] = v_22456;
    v_22456 = stack[-5];
    if (v_22456 == nil) goto v_22305;
    else goto v_22306;
v_22305:
    v_22456 = nil;
    v_22457 = stack[-1];
    v_22458 = v_22457;
v_22312:
    v_22457 = v_22458;
    if (v_22457 == nil) goto v_22316;
    else goto v_22317;
v_22316:
    goto v_22311;
v_22317:
    v_22457 = v_22458;
    v_22457 = qcar(v_22457);
    if (v_22456 == nil) goto v_22325;
    else goto v_22324;
v_22325:
    goto v_22331;
v_22327:
    goto v_22328;
v_22329:
    v_22456 = stack[-4];
    goto v_22330;
v_22331:
    goto v_22327;
v_22328:
    goto v_22329;
v_22330:
    v_22456 = Lassoc(nil, v_22457, v_22456);
v_22324:
    v_22457 = v_22458;
    v_22457 = qcdr(v_22457);
    v_22458 = v_22457;
    goto v_22312;
v_22311:
    if (v_22456 == nil) goto v_22340;
    v_22456 = stack[-1];
    stack[-5] = v_22456;
    goto v_22338;
v_22340:
v_22338:
    goto v_22304;
v_22306:
v_22304:
    goto v_22349;
v_22345:
    stack[0] = stack[-4];
    goto v_22346;
v_22347:
    goto v_22356;
v_22352:
    v_22457 = elt(env, 3); // list
    goto v_22353;
v_22354:
    v_22456 = stack[-5];
    goto v_22355;
v_22356:
    goto v_22352;
v_22353:
    goto v_22354;
v_22355:
    v_22456 = cons(v_22457, v_22456);
    env = stack[-6];
    goto v_22348;
v_22349:
    goto v_22345;
v_22346:
    goto v_22347;
v_22348:
    fn = elt(env, 5); // listsub
    v_22456 = (*qfn2(fn))(fn, stack[0], v_22456);
    env = stack[-6];
    v_22456 = qcdr(v_22456);
    stack[-5] = v_22456;
    goto v_22372;
v_22368:
    v_22457 = stack[-2];
    goto v_22369;
v_22370:
    v_22456 = stack[-4];
    goto v_22371;
v_22372:
    goto v_22368;
v_22369:
    goto v_22370;
v_22371:
    v_22457 = Lassoc(nil, v_22457, v_22456);
    v_22456 = v_22457;
    if (v_22457 == nil) goto v_22366;
    else goto v_22367;
v_22366:
    goto v_22380;
v_22376:
    goto v_22386;
v_22382:
    v_22457 = stack[-2];
    goto v_22383;
v_22384:
    v_22456 = stack[-1];
    goto v_22385;
v_22386:
    goto v_22382;
v_22383:
    goto v_22384;
v_22385:
    v_22457 = cons(v_22457, v_22456);
    env = stack[-6];
    goto v_22377;
v_22378:
    v_22456 = stack[-4];
    goto v_22379;
v_22380:
    goto v_22376;
v_22377:
    goto v_22378;
v_22379:
    v_22457 = Lassoc(nil, v_22457, v_22456);
    v_22456 = v_22457;
    v_22457 = (v_22457 == nil ? lisp_true : nil);
    goto v_22365;
v_22367:
    v_22457 = nil;
    goto v_22365;
    v_22457 = nil;
v_22365:
    if (v_22457 == nil) goto v_22363;
    goto v_22402;
v_22396:
    stack[0] = elt(env, 4); // dfp
    goto v_22397;
v_22398:
    goto v_22409;
v_22405:
    v_22457 = stack[-2];
    goto v_22406;
v_22407:
    v_22456 = stack[-5];
    goto v_22408;
v_22409:
    goto v_22405;
v_22406:
    goto v_22407;
v_22408:
    v_22457 = cons(v_22457, v_22456);
    goto v_22399;
v_22400:
    v_22456 = stack[-3];
    v_22456 = qcdr(v_22456);
    v_22456 = qcdr(v_22456);
    v_22456 = qcar(v_22456);
    goto v_22401;
v_22402:
    goto v_22396;
v_22397:
    goto v_22398;
v_22399:
    goto v_22400;
v_22401:
    {
        LispObject v_22465 = stack[0];
        return list3(v_22465, v_22457, v_22456);
    }
v_22363:
    v_22456 = qcdr(v_22456);
    fn = elt(env, 6); // reval
    v_22456 = (*qfn1(fn))(fn, v_22456);
    env = stack[-6];
    goto v_22426;
v_22420:
    stack[0] = v_22456;
    goto v_22421;
v_22422:
    v_22456 = stack[-5];
    if (v_22456 == nil) goto v_22431;
    goto v_22438;
v_22434:
    v_22457 = stack[-1];
    goto v_22435;
v_22436:
    v_22456 = stack[-5];
    goto v_22437;
v_22438:
    goto v_22434;
v_22435:
    goto v_22436;
v_22437:
    fn = elt(env, 7); // pair
    v_22456 = (*qfn2(fn))(fn, v_22457, v_22456);
    env = stack[-6];
    v_22457 = v_22456;
    goto v_22429;
v_22431:
    v_22457 = nil;
v_22429:
    goto v_22423;
v_22424:
    v_22456 = stack[-4];
    goto v_22425;
v_22426:
    goto v_22420;
v_22421:
    goto v_22422;
v_22423:
    goto v_22424;
v_22425:
    fn = elt(env, 8); // dfp!-sub1
    v_22456 = (*qfnn(fn))(fn, 3, stack[0], v_22457, v_22456);
    env = stack[-6];
    goto v_22449;
v_22443:
    v_22458 = elt(env, 4); // dfp
    goto v_22444;
v_22445:
    v_22457 = v_22456;
    goto v_22446;
v_22447:
    v_22456 = stack[-3];
    v_22456 = qcdr(v_22456);
    v_22456 = qcdr(v_22456);
    v_22456 = qcar(v_22456);
    goto v_22448;
v_22449:
    goto v_22443;
v_22444:
    goto v_22445;
v_22446:
    goto v_22447;
v_22448:
    return list3(v_22458, v_22457, v_22456);
    return onevalue(v_22456);
}



// Code for num_signsort

static LispObject CC_num_signsort(LispObject env,
                         LispObject v_22277)
{
    env = qenv(env);
    LispObject v_22287, v_22288;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22287 = v_22277;
// end of prologue
    goto v_22284;
v_22280:
    v_22288 = v_22287;
    goto v_22281;
v_22282:
    v_22287 = elt(env, 1); // lambda_ygm6np4pcqv31
    goto v_22283;
v_22284:
    goto v_22280;
v_22281:
    goto v_22282;
v_22283:
    {
        fn = elt(env, 2); // ad_signsort
        return (*qfn2(fn))(fn, v_22288, v_22287);
    }
}



// Code for lambda_ygm6np4pcqv31

static LispObject CC_lambda_ygm6np4pcqv31(LispObject env,
                         LispObject v_22277, LispObject v_22278)
{
    env = qenv(env);
    LispObject v_22288, v_22289;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22288 = v_22278;
    v_22289 = v_22277;
// end of prologue
    goto v_22285;
v_22281:
    goto v_22282;
v_22283:
    goto v_22284;
v_22285:
    goto v_22281;
v_22282:
    goto v_22283;
v_22284:
        return Lleq(nil, v_22289, v_22288);
}



// Code for lalr_make_compressed_goto_table

static LispObject CC_lalr_make_compressed_goto_table(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22341, v_22342, v_22343, v_22344;
    LispObject fn;
    argcheck(nargs, 0, "lalr_make_compressed_goto_table");
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
    v_22341 = qvalue(elt(env, 2)); // nonterminals
    v_22341 = Llength(nil, v_22341);
    env = stack[-3];
    v_22341 = sub1(v_22341);
    env = stack[-3];
    v_22341 = Lmkvect(nil, v_22341);
    env = stack[-3];
    stack[-2] = v_22341;
    v_22341 = qvalue(elt(env, 2)); // nonterminals
    stack[-1] = v_22341;
v_22290:
    v_22341 = stack[-1];
    if (v_22341 == nil) goto v_22294;
    else goto v_22295;
v_22294:
    goto v_22289;
v_22295:
    v_22341 = stack[-1];
    v_22341 = qcar(v_22341);
    stack[0] = v_22341;
    goto v_22309;
v_22305:
    v_22342 = stack[0];
    goto v_22306;
v_22307:
    v_22341 = elt(env, 3); // !S!'
    goto v_22308;
v_22309:
    goto v_22305;
v_22306:
    goto v_22307;
v_22308:
    if (v_22342 == v_22341) goto v_22304;
    v_22341 = stack[0];
    fn = elt(env, 6); // lalr_make_compressed_goto_column
    v_22341 = (*qfn1(fn))(fn, v_22341);
    env = stack[-3];
    v_22344 = v_22341;
    goto v_22320;
v_22314:
    v_22343 = stack[-2];
    goto v_22315;
v_22316:
    goto v_22327;
v_22323:
    v_22342 = stack[0];
    goto v_22324;
v_22325:
    v_22341 = elt(env, 4); // lalr_nonterminal_code
    goto v_22326;
v_22327:
    goto v_22323;
v_22324:
    goto v_22325;
v_22326:
    v_22341 = get(v_22342, v_22341);
    env = stack[-3];
    goto v_22317;
v_22318:
    v_22342 = v_22344;
    goto v_22319;
v_22320:
    goto v_22314;
v_22315:
    goto v_22316;
v_22317:
    goto v_22318;
v_22319:
    *(LispObject *)((char *)v_22343 + (CELL-TAG_VECTOR) + (((intptr_t)v_22341-TAG_FIXNUM)/(16/CELL))) = v_22342;
    goto v_22302;
v_22304:
v_22302:
    v_22341 = stack[-1];
    v_22341 = qcdr(v_22341);
    stack[-1] = v_22341;
    goto v_22290;
v_22289:
    v_22341 = qvalue(elt(env, 5)); // !*lalr_verbose
    if (v_22341 == nil) goto v_22336;
    v_22341 = stack[-2];
    fn = elt(env, 7); // lalr_print_compressed_goto_table
    v_22341 = (*qfn1(fn))(fn, v_22341);
    goto v_22334;
v_22336:
v_22334:
    v_22341 = stack[-2];
    return onevalue(v_22341);
}



// Code for sfto_yun!-updecf

static LispObject CC_sfto_yunKupdecf(LispObject env,
                         LispObject v_22277)
{
    env = qenv(env);
    LispObject v_22448, v_22449;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22277);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_22277;
// end of prologue
// Binding !*gcd
// FLUIDBIND: reloadenv=8 litvec-offset=1 saveloc=7
{   bind_fluid_stack bind_fluid_var(-8, 1, -7);
    qvalue(elt(env, 1)) = nil; // !*gcd
    stack[-1] = nil;
    v_22448 = lisp_true;
    qvalue(elt(env, 1)) = v_22448; // !*gcd
    goto v_22296;
v_22292:
    v_22449 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22293;
v_22294:
    v_22448 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22295;
v_22296:
    goto v_22292;
v_22293:
    goto v_22294;
v_22295:
    v_22448 = cons(v_22449, v_22448);
    env = stack[-8];
    stack[-2] = v_22448;
    v_22448 = stack[-6];
    v_22448 = qcar(v_22448);
    v_22448 = qcar(v_22448);
    v_22448 = qcar(v_22448);
    stack[-5] = v_22448;
    goto v_22308;
v_22304:
    stack[-3] = stack[-6];
    goto v_22305;
v_22306:
    goto v_22315;
v_22311:
    v_22449 = stack[-6];
    goto v_22312;
v_22313:
    v_22448 = stack[-5];
    goto v_22314;
v_22315:
    goto v_22311;
v_22312:
    goto v_22313;
v_22314:
    fn = elt(env, 3); // diff
    v_22448 = (*qfn2(fn))(fn, v_22449, v_22448);
    env = stack[-8];
    stack[0] = v_22448;
    goto v_22307;
v_22308:
    goto v_22304;
v_22305:
    goto v_22306;
v_22307:
    fn = elt(env, 4); // sfto_gcdf
    v_22448 = (*qfn2(fn))(fn, stack[-3], v_22448);
    env = stack[-8];
    stack[-3] = v_22448;
    goto v_22323;
v_22319:
    v_22449 = stack[-6];
    goto v_22320;
v_22321:
    v_22448 = stack[-3];
    goto v_22322;
v_22323:
    goto v_22319;
v_22320:
    goto v_22321;
v_22322:
    fn = elt(env, 5); // quotf
    v_22448 = (*qfn2(fn))(fn, v_22449, v_22448);
    env = stack[-8];
    stack[-4] = v_22448;
    goto v_22331;
v_22327:
    goto v_22337;
v_22333:
    v_22449 = stack[0];
    goto v_22334;
v_22335:
    v_22448 = stack[-3];
    goto v_22336;
v_22337:
    goto v_22333;
v_22334:
    goto v_22335;
v_22336:
    fn = elt(env, 5); // quotf
    stack[0] = (*qfn2(fn))(fn, v_22449, v_22448);
    env = stack[-8];
    goto v_22328;
v_22329:
    goto v_22346;
v_22342:
    v_22449 = stack[-4];
    goto v_22343;
v_22344:
    v_22448 = stack[-5];
    goto v_22345;
v_22346:
    goto v_22342;
v_22343:
    goto v_22344;
v_22345:
    fn = elt(env, 3); // diff
    v_22448 = (*qfn2(fn))(fn, v_22449, v_22448);
    env = stack[-8];
    fn = elt(env, 6); // negf
    v_22448 = (*qfn1(fn))(fn, v_22448);
    env = stack[-8];
    goto v_22330;
v_22331:
    goto v_22327;
v_22328:
    goto v_22329;
v_22330:
    fn = elt(env, 7); // addf
    v_22448 = (*qfn2(fn))(fn, stack[0], v_22448);
    env = stack[-8];
    stack[-3] = v_22448;
v_22351:
    v_22448 = stack[-1];
    v_22448 = (v_22448 == nil ? lisp_true : nil);
    stack[-1] = v_22448;
    goto v_22359;
v_22355:
    v_22449 = stack[-4];
    goto v_22356;
v_22357:
    v_22448 = stack[-3];
    goto v_22358;
v_22359:
    goto v_22355;
v_22356:
    goto v_22357;
v_22358:
    fn = elt(env, 4); // sfto_gcdf
    v_22448 = (*qfn2(fn))(fn, v_22449, v_22448);
    env = stack[-8];
    stack[-6] = v_22448;
    v_22448 = stack[-1];
    if (v_22448 == nil) goto v_22365;
    goto v_22372;
v_22368:
    stack[0] = stack[-2];
    goto v_22369;
v_22370:
    goto v_22379;
v_22375:
    v_22448 = stack[-2];
    v_22449 = qcar(v_22448);
    goto v_22376;
v_22377:
    v_22448 = stack[-6];
    goto v_22378;
v_22379:
    goto v_22375;
v_22376:
    goto v_22377;
v_22378:
    fn = elt(env, 8); // multf
    v_22448 = (*qfn2(fn))(fn, v_22449, v_22448);
    env = stack[-8];
    goto v_22371;
v_22372:
    goto v_22368;
v_22369:
    goto v_22370;
v_22371:
    fn = elt(env, 9); // setcar
    v_22448 = (*qfn2(fn))(fn, stack[0], v_22448);
    env = stack[-8];
    goto v_22363;
v_22365:
    goto v_22390;
v_22386:
    stack[0] = stack[-2];
    goto v_22387;
v_22388:
    goto v_22397;
v_22393:
    v_22448 = stack[-2];
    v_22449 = qcdr(v_22448);
    goto v_22394;
v_22395:
    v_22448 = stack[-6];
    goto v_22396;
v_22397:
    goto v_22393;
v_22394:
    goto v_22395;
v_22396:
    fn = elt(env, 8); // multf
    v_22448 = (*qfn2(fn))(fn, v_22449, v_22448);
    env = stack[-8];
    goto v_22389;
v_22390:
    goto v_22386;
v_22387:
    goto v_22388;
v_22389:
    fn = elt(env, 10); // setcdr
    v_22448 = (*qfn2(fn))(fn, stack[0], v_22448);
    env = stack[-8];
    goto v_22363;
v_22363:
    goto v_22406;
v_22402:
    v_22449 = stack[-4];
    goto v_22403;
v_22404:
    v_22448 = stack[-6];
    goto v_22405;
v_22406:
    goto v_22402;
v_22403:
    goto v_22404;
v_22405:
    fn = elt(env, 5); // quotf
    v_22448 = (*qfn2(fn))(fn, v_22449, v_22448);
    env = stack[-8];
    stack[-4] = v_22448;
    goto v_22414;
v_22410:
    goto v_22420;
v_22416:
    v_22449 = stack[-3];
    goto v_22417;
v_22418:
    v_22448 = stack[-6];
    goto v_22419;
v_22420:
    goto v_22416;
v_22417:
    goto v_22418;
v_22419:
    fn = elt(env, 5); // quotf
    stack[0] = (*qfn2(fn))(fn, v_22449, v_22448);
    env = stack[-8];
    goto v_22411;
v_22412:
    goto v_22429;
v_22425:
    v_22449 = stack[-4];
    goto v_22426;
v_22427:
    v_22448 = stack[-5];
    goto v_22428;
v_22429:
    goto v_22425;
v_22426:
    goto v_22427;
v_22428:
    fn = elt(env, 3); // diff
    v_22448 = (*qfn2(fn))(fn, v_22449, v_22448);
    env = stack[-8];
    fn = elt(env, 6); // negf
    v_22448 = (*qfn1(fn))(fn, v_22448);
    env = stack[-8];
    goto v_22413;
v_22414:
    goto v_22410;
v_22411:
    goto v_22412;
v_22413:
    fn = elt(env, 7); // addf
    v_22448 = (*qfn2(fn))(fn, stack[0], v_22448);
    env = stack[-8];
    stack[-3] = v_22448;
    v_22448 = stack[-4];
    if (!consp(v_22448)) goto v_22438;
    else goto v_22439;
v_22438:
    v_22448 = lisp_true;
    goto v_22437;
v_22439:
    v_22448 = stack[-4];
    v_22448 = qcar(v_22448);
    v_22448 = (consp(v_22448) ? nil : lisp_true);
    goto v_22437;
    v_22448 = nil;
v_22437:
    if (v_22448 == nil) goto v_22434;
    else goto v_22435;
v_22434:
    goto v_22351;
v_22435:
    v_22448 = stack[-2];
    ;}  // end of a binding scope
    return onevalue(v_22448);
}



// Code for dvfsf_simplat1

static LispObject CC_dvfsf_simplat1(LispObject env,
                         LispObject v_22277, LispObject v_22278)
{
    env = qenv(env);
    LispObject v_22340, v_22341, v_22342;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22277,v_22278);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_22278;
    stack[-2] = v_22277;
// end of prologue
    v_22340 = stack[-2];
    fn = elt(env, 4); // dvfsf_op
    v_22340 = (*qfn1(fn))(fn, v_22340);
    env = stack[-4];
    v_22342 = v_22340;
    goto v_22298;
v_22294:
    v_22341 = v_22342;
    goto v_22295;
v_22296:
    v_22340 = elt(env, 2); // equal
    goto v_22297;
v_22298:
    goto v_22294;
v_22295:
    goto v_22296;
v_22297:
    if (v_22341 == v_22340) goto v_22292;
    else goto v_22293;
v_22292:
    v_22340 = lisp_true;
    goto v_22291;
v_22293:
    goto v_22308;
v_22304:
    v_22341 = v_22342;
    goto v_22305;
v_22306:
    v_22340 = elt(env, 3); // neq
    goto v_22307;
v_22308:
    goto v_22304;
v_22305:
    goto v_22306;
v_22307:
    v_22340 = (v_22341 == v_22340 ? lisp_true : nil);
    goto v_22291;
    v_22340 = nil;
v_22291:
    if (v_22340 == nil) goto v_22289;
    goto v_22319;
v_22313:
    stack[0] = v_22342;
    goto v_22314;
v_22315:
    v_22340 = stack[-2];
    fn = elt(env, 5); // dvfsf_arg2l
    v_22341 = (*qfn1(fn))(fn, v_22340);
    env = stack[-4];
    goto v_22316;
v_22317:
    v_22340 = stack[-1];
    goto v_22318;
v_22319:
    goto v_22313;
v_22314:
    goto v_22315;
v_22316:
    goto v_22317;
v_22318:
    {
        LispObject v_22347 = stack[0];
        fn = elt(env, 6); // dvfsf_safield
        return (*qfnn(fn))(fn, 3, v_22347, v_22341, v_22340);
    }
v_22289:
    goto v_22333;
v_22325:
    stack[-3] = v_22342;
    goto v_22326;
v_22327:
    v_22340 = stack[-2];
    fn = elt(env, 5); // dvfsf_arg2l
    stack[0] = (*qfn1(fn))(fn, v_22340);
    env = stack[-4];
    goto v_22328;
v_22329:
    v_22340 = stack[-2];
    fn = elt(env, 7); // dvfsf_arg2r
    v_22341 = (*qfn1(fn))(fn, v_22340);
    env = stack[-4];
    goto v_22330;
v_22331:
    v_22340 = stack[-1];
    goto v_22332;
v_22333:
    goto v_22325;
v_22326:
    goto v_22327;
v_22328:
    goto v_22329;
v_22330:
    goto v_22331;
v_22332:
    {
        LispObject v_22348 = stack[-3];
        LispObject v_22349 = stack[0];
        fn = elt(env, 8); // dvfsf_saval
        return (*qfnn(fn))(fn, 4, v_22348, v_22349, v_22341, v_22340);
    }
    return onevalue(v_22340);
}



// Code for intervalom

static LispObject CC_intervalom(LispObject env,
                         LispObject v_22277)
{
    env = qenv(env);
    LispObject v_22370, v_22371, v_22372;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22277);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_22277;
// end of prologue
    v_22370 = stack[-2];
    v_22370 = qcdr(v_22370);
    v_22370 = qcar(v_22370);
    stack[-3] = v_22370;
    v_22370 = stack[-2];
    v_22370 = qcar(v_22370);
    stack[-1] = v_22370;
    goto v_22299;
v_22295:
    v_22371 = stack[-1];
    goto v_22296;
v_22297:
    v_22370 = elt(env, 2); // lowupperlimit
    goto v_22298;
v_22299:
    goto v_22295;
v_22296:
    goto v_22297;
v_22298:
    if (v_22371 == v_22370) goto v_22293;
    else goto v_22294;
v_22293:
    v_22370 = elt(env, 3); // integer_interval
    stack[-1] = v_22370;
    v_22370 = nil;
    stack[-3] = v_22370;
    goto v_22311;
v_22305:
    v_22370 = stack[-2];
    v_22372 = qcar(v_22370);
    goto v_22306;
v_22307:
    v_22371 = nil;
    goto v_22308;
v_22309:
    v_22370 = stack[-2];
    v_22370 = qcdr(v_22370);
    goto v_22310;
v_22311:
    goto v_22305;
v_22306:
    goto v_22307;
v_22308:
    goto v_22309;
v_22310:
    v_22370 = list2star(v_22372, v_22371, v_22370);
    env = stack[-4];
    stack[-2] = v_22370;
    goto v_22292;
v_22294:
v_22292:
    goto v_22321;
v_22317:
    v_22371 = stack[-1];
    goto v_22318;
v_22319:
    v_22370 = qvalue(elt(env, 4)); // valid_om!*
    goto v_22320;
v_22321:
    goto v_22317;
v_22318:
    goto v_22319;
v_22320:
    v_22370 = Lassoc(nil, v_22371, v_22370);
    v_22370 = qcdr(v_22370);
    v_22370 = qcar(v_22370);
    stack[0] = v_22370;
    v_22370 = stack[-3];
    if (v_22370 == nil) goto v_22330;
    goto v_22336;
v_22332:
    v_22370 = stack[-3];
    v_22370 = qcar(v_22370);
    v_22370 = qcdr(v_22370);
    v_22370 = qcar(v_22370);
    v_22371 = Lintern(nil, v_22370);
    env = stack[-4];
    goto v_22333;
v_22334:
    v_22370 = qvalue(elt(env, 5)); // interval!*
    goto v_22335;
v_22336:
    goto v_22332;
v_22333:
    goto v_22334;
v_22335:
    v_22370 = Lassoc(nil, v_22371, v_22370);
    v_22370 = qcdr(v_22370);
    v_22370 = qcar(v_22370);
    stack[-1] = v_22370;
    goto v_22328;
v_22330:
v_22328:
    v_22370 = elt(env, 6); // "<OMA>"
    fn = elt(env, 11); // printout
    v_22370 = (*qfn1(fn))(fn, v_22370);
    env = stack[-4];
    v_22370 = lisp_true;
    fn = elt(env, 12); // indent!*
    v_22370 = (*qfn1(fn))(fn, v_22370);
    env = stack[-4];
    v_22370 = elt(env, 7); // "<OMS cd="""
    fn = elt(env, 11); // printout
    v_22370 = (*qfn1(fn))(fn, v_22370);
    env = stack[-4];
    v_22370 = stack[0];
    v_22370 = Lprinc(nil, v_22370);
    env = stack[-4];
    v_22370 = elt(env, 8); // """ name="""
    v_22370 = Lprinc(nil, v_22370);
    env = stack[-4];
    v_22370 = stack[-1];
    v_22370 = Lprinc(nil, v_22370);
    env = stack[-4];
    v_22370 = elt(env, 9); // """/>"
    v_22370 = Lprinc(nil, v_22370);
    env = stack[-4];
    v_22370 = stack[-2];
    v_22370 = qcdr(v_22370);
    v_22370 = qcdr(v_22370);
    fn = elt(env, 13); // multiom
    v_22370 = (*qfn1(fn))(fn, v_22370);
    env = stack[-4];
    v_22370 = nil;
    fn = elt(env, 12); // indent!*
    v_22370 = (*qfn1(fn))(fn, v_22370);
    env = stack[-4];
    v_22370 = elt(env, 10); // "</OMA>"
    fn = elt(env, 11); // printout
    v_22370 = (*qfn1(fn))(fn, v_22370);
    v_22370 = nil;
    return onevalue(v_22370);
}



// Code for exdfprn

static LispObject CC_exdfprn(LispObject env,
                         LispObject v_22277)
{
    env = qenv(env);
    LispObject v_22285;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22277);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_22277;
// end of prologue
    v_22285 = elt(env, 1); // "d"
    fn = elt(env, 2); // prin2!*
    v_22285 = (*qfn1(fn))(fn, v_22285);
    env = stack[-1];
    v_22285 = stack[0];
    v_22285 = qcdr(v_22285);
    v_22285 = qcar(v_22285);
    {
        fn = elt(env, 3); // rembras
        return (*qfn1(fn))(fn, v_22285);
    }
}



// Code for xnsiz

static LispObject CC_xnsiz(LispObject env,
                         LispObject v_22277)
{
    env = qenv(env);
    LispObject v_22289, v_22290;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22277);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_22289 = v_22277;
// end of prologue
    goto v_22285;
v_22281:
    fn = elt(env, 2); // xnsiz1
    v_22290 = (*qfn1(fn))(fn, v_22289);
    env = stack[0];
    goto v_22282;
v_22283:
    v_22289 = qvalue(elt(env, 1)); // !!log2of10
    goto v_22284;
v_22285:
    goto v_22281;
v_22282:
    goto v_22283;
v_22284:
    v_22289 = quot2(v_22290, v_22289);
    env = stack[0];
    {
        fn = elt(env, 3); // ceiling
        return (*qfn1(fn))(fn, v_22289);
    }
}



// Code for toolongassignp

static LispObject CC_toolongassignp(LispObject env,
                         LispObject v_22277)
{
    env = qenv(env);
    LispObject v_22284;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_22284 = v_22277;
// end of prologue
    v_22284 = qcdr(v_22284);
    v_22284 = qcdr(v_22284);
    v_22284 = qcar(v_22284);
    {
        fn = elt(env, 1); // toolongexpp
        return (*qfn1(fn))(fn, v_22284);
    }
}



// Code for calc_coeffmap_

static LispObject CC_calc_coeffmap_(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22322, v_22323, v_22324;
    LispObject fn;
    LispObject v_22279, v_22278, v_22277;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "calc_coeffmap_");
    va_start(aa, nargs);
    v_22277 = va_arg(aa, LispObject);
    v_22278 = va_arg(aa, LispObject);
    v_22279 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_22279,v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_22277,v_22278,v_22279);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_22279;
    stack[-2] = v_22278;
    v_22322 = v_22277;
// end of prologue
    goto v_22286;
v_22282:
    v_22323 = v_22322;
    goto v_22283;
v_22284:
    v_22322 = stack[-1];
    goto v_22285;
v_22286:
    goto v_22282;
v_22283:
    goto v_22284;
v_22285:
    fn = elt(env, 2); // calc_map_
    v_22322 = (*qfn2(fn))(fn, v_22323, v_22322);
    env = stack[-4];
    v_22324 = v_22322;
    goto v_22298;
v_22294:
    v_22323 = v_22324;
    goto v_22295;
v_22296:
    v_22322 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22297;
v_22298:
    goto v_22294;
v_22295:
    goto v_22296;
v_22297:
    if (v_22323 == v_22322) goto v_22292;
    else goto v_22293;
v_22292:
    v_22322 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22291;
v_22293:
    goto v_22311;
v_22305:
    stack[-3] = elt(env, 1); // times
    goto v_22306;
v_22307:
    stack[0] = v_22324;
    goto v_22308;
v_22309:
    goto v_22319;
v_22315:
    v_22323 = stack[-2];
    goto v_22316;
v_22317:
    v_22322 = stack[-1];
    goto v_22318;
v_22319:
    goto v_22315;
v_22316:
    goto v_22317;
v_22318:
    fn = elt(env, 3); // calc_coeff
    v_22322 = (*qfn2(fn))(fn, v_22323, v_22322);
    goto v_22310;
v_22311:
    goto v_22305;
v_22306:
    goto v_22307;
v_22308:
    goto v_22309;
v_22310:
    {
        LispObject v_22329 = stack[-3];
        LispObject v_22330 = stack[0];
        return list2star(v_22329, v_22330, v_22322);
    }
    v_22322 = nil;
v_22291:
    return onevalue(v_22322);
}



// Code for lengthreval

static LispObject CC_lengthreval(LispObject env,
                         LispObject v_22277)
{
    env = qenv(env);
    LispObject v_22441, v_22442, v_22443;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_22277);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_22277;
// end of prologue
    stack[0] = nil;
    goto v_22293;
v_22289:
    v_22441 = stack[-1];
    v_22442 = Llength(nil, v_22441);
    env = stack[-3];
    goto v_22290;
v_22291:
    v_22441 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22292;
v_22293:
    goto v_22289;
v_22290:
    goto v_22291;
v_22292:
    if (v_22442 == v_22441) goto v_22288;
    goto v_22304;
v_22298:
    v_22443 = elt(env, 2); // alg
    goto v_22299;
v_22300:
    v_22442 = (LispObject)176+TAG_FIXNUM; // 11
    goto v_22301;
v_22302:
    v_22441 = elt(env, 3); // "LENGTH called with wrong number of arguments"
    goto v_22303;
v_22304:
    goto v_22298;
v_22299:
    goto v_22300;
v_22301:
    goto v_22302;
v_22303:
    fn = elt(env, 10); // rerror
    v_22441 = (*qfnn(fn))(fn, 3, v_22443, v_22442, v_22441);
    env = stack[-3];
    goto v_22286;
v_22288:
v_22286:
    v_22441 = stack[-1];
    v_22441 = qcar(v_22441);
    stack[-1] = v_22441;
    v_22441 = stack[-1];
    if (symbolp(v_22441)) goto v_22314;
    else goto v_22313;
v_22314:
    v_22441 = stack[-1];
    fn = elt(env, 11); // arrayp
    v_22441 = (*qfn1(fn))(fn, v_22441);
    env = stack[-3];
    if (v_22441 == nil) goto v_22313;
    goto v_22324;
v_22320:
    v_22443 = elt(env, 4); // list
    goto v_22321;
v_22322:
    goto v_22331;
v_22327:
    v_22442 = stack[-1];
    goto v_22328;
v_22329:
    v_22441 = elt(env, 5); // dimension
    goto v_22330;
v_22331:
    goto v_22327;
v_22328:
    goto v_22329;
v_22330:
    v_22441 = get(v_22442, v_22441);
    goto v_22323;
v_22324:
    goto v_22320;
v_22321:
    goto v_22322;
v_22323:
    return cons(v_22443, v_22441);
v_22313:
    v_22441 = stack[-1];
    fn = elt(env, 12); // aeval
    v_22441 = (*qfn1(fn))(fn, v_22441);
    env = stack[-3];
    stack[-2] = v_22441;
    v_22441 = stack[-2];
    fn = elt(env, 13); // getrtype
    v_22441 = (*qfn1(fn))(fn, v_22441);
    env = stack[-3];
    v_22443 = v_22441;
    if (v_22441 == nil) goto v_22339;
    goto v_22349;
v_22345:
    v_22442 = v_22443;
    goto v_22346;
v_22347:
    v_22441 = elt(env, 6); // lengthfn
    goto v_22348;
v_22349:
    goto v_22345;
v_22346:
    goto v_22347;
v_22348:
    v_22441 = get(v_22442, v_22441);
    env = stack[-3];
    stack[0] = v_22441;
    if (v_22441 == nil) goto v_22339;
    goto v_22360;
v_22356:
    v_22441 = v_22443;
    goto v_22357;
v_22358:
    v_22442 = elt(env, 7); // sparse
    goto v_22359;
v_22360:
    goto v_22356;
v_22357:
    goto v_22358;
v_22359:
    if (v_22441 == v_22442) goto v_22354;
    else goto v_22355;
v_22354:
    goto v_22368;
v_22364:
    v_22442 = stack[0];
    goto v_22365;
v_22366:
    v_22441 = stack[-1];
    goto v_22367;
v_22368:
    goto v_22364;
v_22365:
    goto v_22366;
v_22367:
        return Lapply1(nil, v_22442, v_22441);
v_22355:
    goto v_22378;
v_22374:
    v_22442 = stack[0];
    goto v_22375;
v_22376:
    v_22441 = stack[-2];
    goto v_22377;
v_22378:
    goto v_22374;
v_22375:
    goto v_22376;
v_22377:
        return Lapply1(nil, v_22442, v_22441);
    goto v_22337;
v_22339:
    v_22441 = stack[-2];
    if (!consp(v_22441)) goto v_22381;
    else goto v_22382;
v_22381:
    v_22441 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22283;
v_22382:
    v_22441 = stack[-2];
    v_22441 = qcar(v_22441);
    if (symbolp(v_22441)) goto v_22390;
    v_22441 = lisp_true;
    goto v_22388;
v_22390:
    goto v_22401;
v_22397:
    v_22441 = stack[-2];
    v_22442 = qcar(v_22441);
    goto v_22398;
v_22399:
    v_22441 = elt(env, 6); // lengthfn
    goto v_22400;
v_22401:
    goto v_22397;
v_22398:
    goto v_22399;
v_22400:
    v_22441 = get(v_22442, v_22441);
    env = stack[-3];
    stack[0] = v_22441;
    v_22441 = (v_22441 == nil ? lisp_true : nil);
    goto v_22388;
    v_22441 = nil;
v_22388:
    if (v_22441 == nil) goto v_22386;
    v_22441 = v_22443;
    if (v_22441 == nil) goto v_22409;
    goto v_22417;
v_22413:
    v_22441 = elt(env, 8); // "LENGTH not defined for argument of type"
    goto v_22414;
v_22415:
    v_22442 = v_22443;
    goto v_22416;
v_22417:
    goto v_22413;
v_22414:
    goto v_22415;
v_22416:
    v_22441 = list2(v_22441, v_22442);
    env = stack[-3];
    fn = elt(env, 14); // lprie
    v_22441 = (*qfn1(fn))(fn, v_22441);
    goto v_22407;
v_22409:
    goto v_22427;
v_22423:
    v_22442 = stack[-1];
    goto v_22424;
v_22425:
    v_22441 = elt(env, 9); // "LENGTH argument"
    goto v_22426;
v_22427:
    goto v_22423;
v_22424:
    goto v_22425;
v_22426:
    fn = elt(env, 15); // typerr
    v_22441 = (*qfn2(fn))(fn, v_22442, v_22441);
    goto v_22407;
v_22407:
    goto v_22337;
v_22386:
    goto v_22437;
v_22433:
    v_22442 = stack[0];
    goto v_22434;
v_22435:
    v_22441 = stack[-2];
    v_22441 = qcdr(v_22441);
    goto v_22436;
v_22437:
    goto v_22433;
v_22434:
    goto v_22435;
v_22436:
        return Lapply1(nil, v_22442, v_22441);
v_22337:
    v_22441 = nil;
v_22283:
    return onevalue(v_22441);
}



// Code for solvealgdepends

static LispObject CC_solvealgdepends(LispObject env,
                         LispObject v_22277, LispObject v_22278)
{
    env = qenv(env);
    LispObject v_22361, v_22362;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_22278,v_22277);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_22277,v_22278);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_22278;
    stack[-1] = v_22277;
// end of prologue
v_22283:
    goto v_22292;
v_22288:
    v_22362 = stack[-1];
    goto v_22289;
v_22290:
    v_22361 = stack[0];
    goto v_22291;
v_22292:
    goto v_22288;
v_22289:
    goto v_22290;
v_22291:
    if (equal(v_22362, v_22361)) goto v_22286;
    else goto v_22287;
v_22286:
    v_22361 = lisp_true;
    goto v_22282;
v_22287:
    v_22361 = stack[-1];
    if (!consp(v_22361)) goto v_22296;
    else goto v_22297;
v_22296:
    v_22361 = nil;
    goto v_22282;
v_22297:
    goto v_22307;
v_22303:
    v_22362 = stack[-1];
    goto v_22304;
v_22305:
    v_22361 = elt(env, 1); // root_of
    goto v_22306;
v_22307:
    goto v_22303;
v_22304:
    goto v_22305;
v_22306:
    if (!consp(v_22362)) goto v_22301;
    v_22362 = qcar(v_22362);
    if (v_22362 == v_22361) goto v_22300;
    else goto v_22301;
v_22300:
    goto v_22318;
v_22314:
    v_22362 = stack[0];
    goto v_22315;
v_22316:
    v_22361 = stack[-1];
    v_22361 = qcdr(v_22361);
    v_22361 = qcdr(v_22361);
    v_22361 = qcar(v_22361);
    goto v_22317;
v_22318:
    goto v_22314;
v_22315:
    goto v_22316;
v_22317:
    if (equal(v_22362, v_22361)) goto v_22312;
    else goto v_22313;
v_22312:
    v_22361 = nil;
    goto v_22282;
v_22313:
    v_22361 = stack[-1];
    v_22361 = qcdr(v_22361);
    v_22361 = qcar(v_22361);
    stack[-1] = v_22361;
    goto v_22283;
    goto v_22285;
v_22301:
    goto v_22341;
v_22337:
    v_22361 = stack[-1];
    v_22362 = qcar(v_22361);
    goto v_22338;
v_22339:
    v_22361 = stack[0];
    goto v_22340;
v_22341:
    goto v_22337;
v_22338:
    goto v_22339;
v_22340:
    v_22361 = CC_solvealgdepends(elt(env, 0), v_22362, v_22361);
    env = stack[-2];
    v_22362 = v_22361;
    if (v_22361 == nil) goto v_22335;
    v_22361 = v_22362;
    goto v_22282;
v_22335:
    goto v_22353;
v_22349:
    v_22361 = stack[-1];
    v_22362 = qcdr(v_22361);
    goto v_22350;
v_22351:
    v_22361 = stack[0];
    goto v_22352;
v_22353:
    goto v_22349;
v_22350:
    goto v_22351;
v_22352:
    v_22361 = CC_solvealgdepends(elt(env, 0), v_22362, v_22361);
    v_22362 = v_22361;
    if (v_22361 == nil) goto v_22347;
    v_22361 = v_22362;
    goto v_22282;
v_22347:
    v_22361 = nil;
    goto v_22282;
    goto v_22285;
v_22285:
    v_22361 = nil;
v_22282:
    return onevalue(v_22361);
}



setup_type const u40_setup[] =
{
    {"ctx_union",               TOO_FEW_2,      CC_ctx_union,  WRONG_NO_2},
    {"janettreenodebuild",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_janettreenodebuild},
    {"tayfkern",                CC_tayfkern,    TOO_MANY_1,    WRONG_NO_1},
    {"mri_ofsf2mriat",          TOO_FEW_2,      CC_mri_ofsf2mriat,WRONG_NO_2},
    {"dip_sum",                 TOO_FEW_2,      CC_dip_sum,    WRONG_NO_2},
    {"dipcontevmin",            TOO_FEW_2,      CC_dipcontevmin,WRONG_NO_2},
    {"multiply-by-power-of-ten",TOO_FEW_2,      CC_multiplyKbyKpowerKofKten,WRONG_NO_2},
    {"rd:difference",           TOO_FEW_2,      CC_rdTdifference,WRONG_NO_2},
    {"simppartdf",              CC_simppartdf,  TOO_MANY_1,    WRONG_NO_1},
    {"calc_den_tar",            TOO_FEW_2,      CC_calc_den_tar,WRONG_NO_2},
    {"prepsq*1",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_prepsqH1},
    {"atom_compare",            TOO_FEW_2,      CC_atom_compare,WRONG_NO_2},
    {"makeqn-maybe",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_makeqnKmaybe},
    {"vector-to-poly",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vectorKtoKpoly},
    {"set_parser",              CC_set_parser,  TOO_MANY_1,    WRONG_NO_1},
    {"aex_psrem",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_aex_psrem},
    {"even_action_term",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_even_action_term},
    {"sq_member",               TOO_FEW_2,      CC_sq_member,  WRONG_NO_2},
    {"my+nullsq+p",             CC_myLnullsqLp, TOO_MANY_1,    WRONG_NO_1},
    {"factor-prim-f",           CC_factorKprimKf,TOO_MANY_1,   WRONG_NO_1},
    {"ofsf_optsplitterm",       TOO_FEW_2,      CC_ofsf_optsplitterm,WRONG_NO_2},
    {"sfto_b:ordexp",           TOO_FEW_2,      CC_sfto_bTordexp,WRONG_NO_2},
    {"minusrd",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_minusrd},
    {"sptransmat",              CC_sptransmat,  TOO_MANY_1,    WRONG_NO_1},
    {"greatertype",             TOO_FEW_2,      CC_greatertype,WRONG_NO_2},
    {"groebspolynom3",          TOO_FEW_2,      CC_groebspolynom3,WRONG_NO_2},
    {"indxsymp",                TOO_FEW_2,      CC_indxsymp,   WRONG_NO_2},
    {"dfp-sub",                 TOO_FEW_2,      CC_dfpKsub,    WRONG_NO_2},
    {"num_signsort",            CC_num_signsort,TOO_MANY_1,    WRONG_NO_1},
    {"lambda_ygm6np4pcqv31",    TOO_FEW_2,      CC_lambda_ygm6np4pcqv31,WRONG_NO_2},
    {"lalr_make_compressed_goto_table",WRONG_NO_NA,WRONG_NO_NB,(n_args *)CC_lalr_make_compressed_goto_table},
    {"sfto_yun-updecf",         CC_sfto_yunKupdecf,TOO_MANY_1, WRONG_NO_1},
    {"dvfsf_simplat1",          TOO_FEW_2,      CC_dvfsf_simplat1,WRONG_NO_2},
    {"intervalom",              CC_intervalom,  TOO_MANY_1,    WRONG_NO_1},
    {"exdfprn",                 CC_exdfprn,     TOO_MANY_1,    WRONG_NO_1},
    {"xnsiz",                   CC_xnsiz,       TOO_MANY_1,    WRONG_NO_1},
    {"toolongassignp",          CC_toolongassignp,TOO_MANY_1,  WRONG_NO_1},
    {"calc_coeffmap_",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_calc_coeffmap_},
    {"lengthreval",             CC_lengthreval, TOO_MANY_1,    WRONG_NO_1},
    {"solvealgdepends",         TOO_FEW_2,      CC_solvealgdepends,WRONG_NO_2},
    {NULL, (one_args *)"u40", (two_args *)"104393 5655922 8119793", 0}
};

// end of generated code
