
// $destdir/u42.c        Machine generated C code

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



// Code for lex_keywords

static LispObject CC_lex_keywords(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_24021, v_24022, v_24023, v_24024;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_24021 = v_23634;
// end of prologue
    stack[-4] = v_24021;
v_23639:
    v_24021 = stack[-4];
    if (v_24021 == nil) goto v_23643;
    else goto v_23644;
v_23643:
    v_24021 = nil;
    goto v_23638;
v_23644:
    v_24021 = stack[-4];
    v_24021 = qcar(v_24021);
    stack[-3] = v_24021;
    v_24021 = stack[-3];
    fn = elt(env, 15); // widestring2list
    v_24021 = (*qfn1(fn))(fn, v_24021);
    env = stack[-6];
    stack[-2] = v_24021;
    v_24021 = stack[-2];
    if (v_24021 == nil) goto v_23660;
    else goto v_23661;
v_23660:
    v_24021 = elt(env, 2); // "Empty string passed to lex_keywords"
    fn = elt(env, 16); // rederr
    v_24021 = (*qfn1(fn))(fn, v_24021);
    env = stack[-6];
    goto v_23659;
v_23661:
v_23659:
    goto v_23677;
v_23673:
    v_24021 = stack[-2];
    v_24022 = qcar(v_24021);
    goto v_23674;
v_23675:
    v_24021 = (LispObject)1040+TAG_FIXNUM; // 65
    goto v_23676;
v_23677:
    goto v_23673;
v_23674:
    goto v_23675;
v_23676:
    v_24021 = (LispObject)geq2(v_24022, v_24021);
    v_24021 = v_24021 ? lisp_true : nil;
    env = stack[-6];
    if (v_24021 == nil) goto v_23670;
    else goto v_23671;
v_23670:
    v_24021 = nil;
    goto v_23669;
v_23671:
    goto v_23689;
v_23685:
    v_24021 = stack[-2];
    v_24022 = qcar(v_24021);
    goto v_23686;
v_23687:
    v_24021 = (LispObject)1440+TAG_FIXNUM; // 90
    goto v_23688;
v_23689:
    goto v_23685;
v_23686:
    goto v_23687;
v_23688:
    v_24021 = (LispObject)lesseq2(v_24022, v_24021);
    v_24021 = v_24021 ? lisp_true : nil;
    env = stack[-6];
    goto v_23669;
    v_24021 = nil;
v_23669:
    if (v_24021 == nil) goto v_23667;
    else goto v_23666;
v_23667:
    goto v_23702;
v_23698:
    v_24021 = stack[-2];
    v_24022 = qcar(v_24021);
    goto v_23699;
v_23700:
    v_24021 = (LispObject)1552+TAG_FIXNUM; // 97
    goto v_23701;
v_23702:
    goto v_23698;
v_23699:
    goto v_23700;
v_23701:
    v_24021 = (LispObject)geq2(v_24022, v_24021);
    v_24021 = v_24021 ? lisp_true : nil;
    env = stack[-6];
    if (v_24021 == nil) goto v_23695;
    else goto v_23696;
v_23695:
    v_24021 = nil;
    goto v_23694;
v_23696:
    goto v_23714;
v_23710:
    v_24021 = stack[-2];
    v_24022 = qcar(v_24021);
    goto v_23711;
v_23712:
    v_24021 = (LispObject)1952+TAG_FIXNUM; // 122
    goto v_23713;
v_23714:
    goto v_23710;
v_23711:
    goto v_23712;
v_23713:
    v_24021 = (LispObject)lesseq2(v_24022, v_24021);
    v_24021 = v_24021 ? lisp_true : nil;
    env = stack[-6];
    goto v_23694;
    v_24021 = nil;
v_23694:
v_23666:
    stack[-5] = v_24021;
    v_24021 = stack[-2];
    v_24021 = qcdr(v_24021);
    stack[-1] = v_24021;
v_23721:
    v_24021 = stack[-1];
    if (v_24021 == nil) goto v_23726;
    else goto v_23727;
v_23726:
    goto v_23720;
v_23727:
    v_24021 = stack[-1];
    v_24021 = qcar(v_24021);
    stack[0] = v_24021;
    goto v_23748;
v_23744:
    v_24022 = stack[0];
    goto v_23745;
v_23746:
    v_24021 = (LispObject)1040+TAG_FIXNUM; // 65
    goto v_23747;
v_23748:
    goto v_23744;
v_23745:
    goto v_23746;
v_23747:
    v_24021 = (LispObject)geq2(v_24022, v_24021);
    v_24021 = v_24021 ? lisp_true : nil;
    env = stack[-6];
    if (v_24021 == nil) goto v_23741;
    goto v_23757;
v_23753:
    v_24022 = stack[0];
    goto v_23754;
v_23755:
    v_24021 = (LispObject)1440+TAG_FIXNUM; // 90
    goto v_23756;
v_23757:
    goto v_23753;
v_23754:
    goto v_23755;
v_23756:
    v_24021 = (LispObject)lesseq2(v_24022, v_24021);
    v_24021 = v_24021 ? lisp_true : nil;
    env = stack[-6];
    if (v_24021 == nil) goto v_23741;
    goto v_23740;
v_23741:
    goto v_23767;
v_23763:
    v_24022 = stack[0];
    goto v_23764;
v_23765:
    v_24021 = (LispObject)1552+TAG_FIXNUM; // 97
    goto v_23766;
v_23767:
    goto v_23763;
v_23764:
    goto v_23765;
v_23766:
    v_24021 = (LispObject)geq2(v_24022, v_24021);
    v_24021 = v_24021 ? lisp_true : nil;
    env = stack[-6];
    if (v_24021 == nil) goto v_23760;
    goto v_23776;
v_23772:
    v_24022 = stack[0];
    goto v_23773;
v_23774:
    v_24021 = (LispObject)1952+TAG_FIXNUM; // 122
    goto v_23775;
v_23776:
    goto v_23772;
v_23773:
    goto v_23774;
v_23775:
    v_24021 = (LispObject)lesseq2(v_24022, v_24021);
    v_24021 = v_24021 ? lisp_true : nil;
    env = stack[-6];
    if (v_24021 == nil) goto v_23760;
    goto v_23740;
v_23760:
    goto v_23789;
v_23785:
    v_24022 = stack[0];
    goto v_23786;
v_23787:
    v_24021 = (LispObject)768+TAG_FIXNUM; // 48
    goto v_23788;
v_23789:
    goto v_23785;
v_23786:
    goto v_23787;
v_23788:
    v_24021 = (LispObject)geq2(v_24022, v_24021);
    v_24021 = v_24021 ? lisp_true : nil;
    env = stack[-6];
    if (v_24021 == nil) goto v_23781;
    goto v_23798;
v_23794:
    v_24022 = stack[0];
    goto v_23795;
v_23796:
    v_24021 = (LispObject)912+TAG_FIXNUM; // 57
    goto v_23797;
v_23798:
    goto v_23794;
v_23795:
    goto v_23796;
v_23797:
    v_24021 = (LispObject)lesseq2(v_24022, v_24021);
    v_24021 = v_24021 ? lisp_true : nil;
    env = stack[-6];
    if (v_24021 == nil) goto v_23781;
    goto v_23782;
v_23781:
    goto v_23806;
v_23802:
    v_24022 = stack[0];
    goto v_23803;
v_23804:
    v_24021 = (LispObject)1520+TAG_FIXNUM; // 95
    goto v_23805;
v_23806:
    goto v_23802;
v_23803:
    goto v_23804;
v_23805:
    v_24021 = Lneq(nil, v_24022, v_24021);
    env = stack[-6];
    goto v_23780;
v_23782:
    v_24021 = nil;
    goto v_23780;
    v_24021 = nil;
v_23780:
    goto v_23738;
v_23740:
    v_24021 = nil;
    goto v_23738;
    v_24021 = nil;
v_23738:
    if (v_24021 == nil) goto v_23736;
    v_24021 = nil;
    stack[-5] = v_24021;
    goto v_23734;
v_23736:
v_23734:
    v_24021 = stack[-1];
    v_24021 = qcdr(v_24021);
    stack[-1] = v_24021;
    goto v_23721;
v_23720:
    v_24021 = stack[-2];
    v_24021 = qcdr(v_24021);
    if (v_24021 == nil) goto v_23824;
    else goto v_23825;
v_23824:
    v_24021 = lisp_true;
    goto v_23823;
v_23825:
    v_24021 = stack[-5];
    goto v_23823;
    v_24021 = nil;
v_23823:
    if (v_24021 == nil) goto v_23821;
    v_24021 = stack[-3];
    v_24021 = Lintern(nil, v_24021);
    env = stack[-6];
    stack[-2] = v_24021;
    goto v_23843;
v_23839:
    v_24022 = stack[-2];
    goto v_23840;
v_23841:
    v_24021 = elt(env, 3); // lex_code
    goto v_23842;
v_23843:
    goto v_23839;
v_23840:
    goto v_23841;
v_23842:
    v_24021 = get(v_24022, v_24021);
    env = stack[-6];
    if (v_24021 == nil) goto v_23836;
    else goto v_23837;
v_23836:
    goto v_23851;
v_23847:
    v_24022 = stack[-2];
    goto v_23848;
v_23849:
    v_24021 = qvalue(elt(env, 4)); // lex_keyword_names
    goto v_23850;
v_23851:
    goto v_23847;
v_23848:
    goto v_23849;
v_23850:
    v_24021 = cons(v_24022, v_24021);
    env = stack[-6];
    qvalue(elt(env, 4)) = v_24021; // lex_keyword_names
    goto v_23863;
v_23859:
    v_24022 = stack[-2];
    goto v_23860;
v_23861:
    v_24021 = elt(env, 5); // lex_next_code
    goto v_23862;
v_23863:
    goto v_23859;
v_23860:
    goto v_23861;
v_23862:
    v_24021 = get(v_24022, v_24021);
    env = stack[-6];
    if (v_24021 == nil) goto v_23856;
    else goto v_23857;
v_23856:
    goto v_23873;
v_23867:
    v_24023 = stack[-2];
    goto v_23868;
v_23869:
    v_24022 = elt(env, 3); // lex_code
    goto v_23870;
v_23871:
    v_24021 = qvalue(elt(env, 5)); // lex_next_code
    goto v_23872;
v_23873:
    goto v_23867;
v_23868:
    goto v_23869;
v_23870:
    goto v_23871;
v_23872:
    v_24021 = Lputprop(nil, 3, v_24023, v_24022, v_24021);
    env = stack[-6];
    goto v_23884;
v_23878:
    v_24023 = qvalue(elt(env, 5)); // lex_next_code
    goto v_23879;
v_23880:
    v_24022 = stack[-2];
    goto v_23881;
v_23882:
    v_24021 = qvalue(elt(env, 6)); // lex_codename
    goto v_23883;
v_23884:
    goto v_23878;
v_23879:
    goto v_23880;
v_23881:
    goto v_23882;
v_23883:
    v_24021 = acons(v_24023, v_24022, v_24021);
    env = stack[-6];
    qvalue(elt(env, 6)) = v_24021; // lex_codename
    v_24021 = qvalue(elt(env, 7)); // !*tracelex
    if (v_24021 == nil) goto v_23891;
    v_24021 = elt(env, 8); // "Token '"
    v_24021 = Lprinc(nil, v_24021);
    env = stack[-6];
    v_24021 = stack[-2];
    v_24021 = Lprin(nil, v_24021);
    env = stack[-6];
    v_24021 = elt(env, 9); // "' allocated code "
    v_24021 = Lprinc(nil, v_24021);
    env = stack[-6];
    v_24021 = qvalue(elt(env, 5)); // lex_next_code
    v_24021 = Lprint(nil, v_24021);
    env = stack[-6];
    goto v_23889;
v_23891:
v_23889:
    v_24021 = qvalue(elt(env, 5)); // lex_next_code
    v_24021 = add1(v_24021);
    env = stack[-6];
    qvalue(elt(env, 5)) = v_24021; // lex_next_code
    goto v_23855;
v_23857:
v_23855:
    goto v_23835;
v_23837:
v_23835:
    goto v_23654;
v_23821:
    v_24021 = stack[-3];
    v_24021 = Lintern(nil, v_24021);
    env = stack[-6];
    stack[-3] = v_24021;
    goto v_23915;
v_23911:
    v_24022 = stack[-3];
    goto v_23912;
v_23913:
    v_24021 = elt(env, 3); // lex_code
    goto v_23914;
v_23915:
    goto v_23911;
v_23912:
    goto v_23913;
v_23914:
    v_24021 = get(v_24022, v_24021);
    env = stack[-6];
    if (v_24021 == nil) goto v_23908;
    else goto v_23909;
v_23908:
    goto v_23923;
v_23919:
    v_24022 = stack[-3];
    goto v_23920;
v_23921:
    v_24021 = qvalue(elt(env, 4)); // lex_keyword_names
    goto v_23922;
v_23923:
    goto v_23919;
v_23920:
    goto v_23921;
v_23922:
    v_24021 = cons(v_24022, v_24021);
    env = stack[-6];
    qvalue(elt(env, 4)) = v_24021; // lex_keyword_names
    goto v_23933;
v_23927:
    v_24023 = stack[-3];
    goto v_23928;
v_23929:
    v_24022 = elt(env, 3); // lex_code
    goto v_23930;
v_23931:
    v_24021 = qvalue(elt(env, 5)); // lex_next_code
    goto v_23932;
v_23933:
    goto v_23927;
v_23928:
    goto v_23929;
v_23930:
    goto v_23931;
v_23932:
    v_24021 = Lputprop(nil, 3, v_24023, v_24022, v_24021);
    env = stack[-6];
    goto v_23944;
v_23938:
    v_24023 = qvalue(elt(env, 5)); // lex_next_code
    goto v_23939;
v_23940:
    v_24022 = stack[-3];
    goto v_23941;
v_23942:
    v_24021 = qvalue(elt(env, 6)); // lex_codename
    goto v_23943;
v_23944:
    goto v_23938;
v_23939:
    goto v_23940;
v_23941:
    goto v_23942;
v_23943:
    v_24021 = acons(v_24023, v_24022, v_24021);
    env = stack[-6];
    qvalue(elt(env, 6)) = v_24021; // lex_codename
    v_24021 = qvalue(elt(env, 5)); // lex_next_code
    v_24021 = add1(v_24021);
    env = stack[-6];
    qvalue(elt(env, 5)) = v_24021; // lex_next_code
    v_24021 = stack[-2];
    v_24021 = Lreverse(nil, v_24021);
    env = stack[-6];
    v_24021 = qcdr(v_24021);
    v_24021 = Lreverse(nil, v_24021);
    env = stack[-6];
    fn = elt(env, 17); // list2widestring
    v_24021 = (*qfn1(fn))(fn, v_24021);
    env = stack[-6];
    stack[-5] = v_24021;
    v_24021 = stack[-5];
    v_24021 = ncons(v_24021);
    env = stack[-6];
    v_24021 = CC_lex_keywords(elt(env, 0), v_24021);
    env = stack[-6];
    v_24021 = stack[-5];
    v_24021 = Lintern(nil, v_24021);
    env = stack[-6];
    stack[-5] = v_24021;
    v_24021 = stack[-2];
    fn = elt(env, 18); // lastcar
    v_24021 = (*qfn1(fn))(fn, v_24021);
    env = stack[-6];
    v_24021 = ncons(v_24021);
    env = stack[-6];
    fn = elt(env, 17); // list2widestring
    v_24021 = (*qfn1(fn))(fn, v_24021);
    env = stack[-6];
    v_24021 = Lintern(nil, v_24021);
    env = stack[-6];
    stack[-2] = v_24021;
    v_24021 = qvalue(elt(env, 7)); // !*tracelex
    if (v_24021 == nil) goto v_23968;
    v_24021 = Lposn(nil, 0);
    env = stack[-6];
    v_24021 = (LispObject)zerop(v_24021);
    v_24021 = v_24021 ? lisp_true : nil;
    env = stack[-6];
    if (v_24021 == nil) goto v_23972;
    else goto v_23973;
v_23972:
    v_24021 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_23971;
v_23973:
v_23971:
    v_24021 = elt(env, 10); // "dipthong data '"
    v_24021 = Lprinc(nil, v_24021);
    env = stack[-6];
    v_24021 = stack[-5];
    v_24021 = Lprin(nil, v_24021);
    env = stack[-6];
    v_24021 = elt(env, 11); // "' plus '"
    v_24021 = Lprinc(nil, v_24021);
    env = stack[-6];
    v_24021 = stack[-2];
    v_24021 = Lprin(nil, v_24021);
    env = stack[-6];
    v_24021 = elt(env, 12); // "' => '"
    v_24021 = Lprinc(nil, v_24021);
    env = stack[-6];
    v_24021 = stack[-3];
    v_24021 = Lprin(nil, v_24021);
    env = stack[-6];
    v_24021 = elt(env, 13); // "'"
    v_24021 = Lprintc(nil, v_24021);
    env = stack[-6];
    goto v_23966;
v_23968:
v_23966:
    goto v_23998;
v_23992:
    stack[-1] = stack[-5];
    goto v_23993;
v_23994:
    stack[0] = elt(env, 14); // lex_dipthong
    goto v_23995;
v_23996:
    goto v_24008;
v_24002:
    v_24024 = stack[-2];
    goto v_24003;
v_24004:
    v_24023 = stack[-3];
    goto v_24005;
v_24006:
    goto v_24016;
v_24012:
    v_24022 = stack[-5];
    goto v_24013;
v_24014:
    v_24021 = elt(env, 14); // lex_dipthong
    goto v_24015;
v_24016:
    goto v_24012;
v_24013:
    goto v_24014;
v_24015:
    v_24021 = get(v_24022, v_24021);
    env = stack[-6];
    goto v_24007;
v_24008:
    goto v_24002;
v_24003:
    goto v_24004;
v_24005:
    goto v_24006;
v_24007:
    v_24021 = acons(v_24024, v_24023, v_24021);
    env = stack[-6];
    goto v_23997;
v_23998:
    goto v_23992;
v_23993:
    goto v_23994;
v_23995:
    goto v_23996;
v_23997:
    v_24021 = Lputprop(nil, 3, stack[-1], stack[0], v_24021);
    env = stack[-6];
    goto v_23907;
v_23909:
v_23907:
v_23654:
    v_24021 = stack[-4];
    v_24021 = qcdr(v_24021);
    stack[-4] = v_24021;
    goto v_23639;
v_23638:
    return onevalue(v_24021);
}



// Code for repr_new

static LispObject CC_repr_new(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23672, v_23673, v_23674, v_23675;
    LispObject fn;
    LispObject v_23637, v_23636, v_23635, v_23634;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "repr_new");
    va_start(aa, nargs);
    v_23634 = va_arg(aa, LispObject);
    v_23635 = va_arg(aa, LispObject);
    v_23636 = va_arg(aa, LispObject);
    v_23637 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_23637,v_23636,v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_23634,v_23635,v_23636,v_23637);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_23672 = v_23637;
    v_23673 = v_23636;
    v_23674 = v_23635;
    v_23675 = v_23634;
// end of prologue
    goto v_23648;
v_23640:
    stack[-3] = v_23675;
    goto v_23641;
v_23642:
    stack[-2] = v_23674;
    goto v_23643;
v_23644:
    stack[-1] = v_23673;
    goto v_23645;
v_23646:
    goto v_23657;
v_23653:
    stack[0] = v_23672;
    goto v_23654;
v_23655:
    v_23672 = v_23673;
    if (v_23672 == nil) goto v_23661;
    else goto v_23662;
v_23661:
    v_23672 = elt(env, 1); // "repr_new : invalid coefficient list"
    v_23672 = ncons(v_23672);
    env = stack[-4];
    fn = elt(env, 2); // rederr
    v_23672 = (*qfn1(fn))(fn, v_23672);
    env = stack[-4];
    goto v_23660;
v_23662:
    v_23672 = v_23673;
    v_23672 = qcar(v_23672);
    v_23672 = qcdr(v_23672);
    goto v_23660;
    v_23672 = nil;
v_23660:
    goto v_23656;
v_23657:
    goto v_23653;
v_23654:
    goto v_23655;
v_23656:
    v_23672 = list2(stack[0], v_23672);
    goto v_23647;
v_23648:
    goto v_23640;
v_23641:
    goto v_23642;
v_23643:
    goto v_23644;
v_23645:
    goto v_23646;
v_23647:
    {
        LispObject v_23680 = stack[-3];
        LispObject v_23681 = stack[-2];
        LispObject v_23682 = stack[-1];
        return list3star(v_23680, v_23681, v_23682, v_23672);
    }
}



// Code for sfto_subfwd

static LispObject CC_sfto_subfwd(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23731, v_23732;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23634,v_23635);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_23635;
    stack[-2] = v_23634;
// end of prologue
    v_23731 = stack[-2];
    if (!consp(v_23731)) goto v_23649;
    else goto v_23650;
v_23649:
    v_23731 = lisp_true;
    goto v_23648;
v_23650:
    v_23731 = stack[-2];
    v_23731 = qcar(v_23731);
    v_23731 = (consp(v_23731) ? nil : lisp_true);
    goto v_23648;
    v_23731 = nil;
v_23648:
    if (v_23731 == nil) goto v_23646;
    v_23731 = stack[-2];
    goto v_23640;
v_23646:
    goto v_23663;
v_23659:
    v_23731 = stack[-2];
    v_23731 = qcar(v_23731);
    v_23731 = qcar(v_23731);
    v_23732 = qcar(v_23731);
    goto v_23660;
v_23661:
    v_23731 = stack[-1];
    goto v_23662;
v_23663:
    goto v_23659;
v_23660:
    goto v_23661;
v_23662:
    v_23731 = Latsoc(nil, v_23732, v_23731);
    v_23732 = v_23731;
    if (v_23732 == nil) goto v_23673;
    goto v_23680;
v_23676:
    v_23732 = stack[-2];
    v_23732 = qcar(v_23732);
    v_23732 = qcar(v_23732);
    v_23732 = qcdr(v_23732);
    goto v_23677;
v_23678:
    v_23731 = qcdr(v_23731);
    goto v_23679;
v_23680:
    goto v_23676;
v_23677:
    goto v_23678;
v_23679:
    v_23731 = quot2(v_23732, v_23731);
    env = stack[-4];
    goto v_23671;
v_23673:
    v_23731 = stack[-2];
    v_23731 = qcar(v_23731);
    v_23731 = qcar(v_23731);
    v_23731 = qcdr(v_23731);
    goto v_23671;
    v_23731 = nil;
v_23671:
    goto v_23700;
v_23694:
    goto v_23706;
v_23702:
    v_23732 = stack[-2];
    v_23732 = qcar(v_23732);
    v_23732 = qcar(v_23732);
    v_23732 = qcar(v_23732);
    goto v_23703;
v_23704:
    goto v_23705;
v_23706:
    goto v_23702;
v_23703:
    goto v_23704;
v_23705:
    fn = elt(env, 2); // to
    stack[-3] = (*qfn2(fn))(fn, v_23732, v_23731);
    env = stack[-4];
    goto v_23695;
v_23696:
    goto v_23717;
v_23713:
    v_23731 = stack[-2];
    v_23731 = qcar(v_23731);
    v_23732 = qcdr(v_23731);
    goto v_23714;
v_23715:
    v_23731 = stack[-1];
    goto v_23716;
v_23717:
    goto v_23713;
v_23714:
    goto v_23715;
v_23716:
    stack[0] = CC_sfto_subfwd(elt(env, 0), v_23732, v_23731);
    env = stack[-4];
    goto v_23697;
v_23698:
    goto v_23727;
v_23723:
    v_23731 = stack[-2];
    v_23732 = qcdr(v_23731);
    goto v_23724;
v_23725:
    v_23731 = stack[-1];
    goto v_23726;
v_23727:
    goto v_23723;
v_23724:
    goto v_23725;
v_23726:
    v_23731 = CC_sfto_subfwd(elt(env, 0), v_23732, v_23731);
    goto v_23699;
v_23700:
    goto v_23694;
v_23695:
    goto v_23696;
v_23697:
    goto v_23698;
v_23699:
    {
        LispObject v_23737 = stack[-3];
        LispObject v_23738 = stack[0];
        return acons(v_23737, v_23738, v_23731);
    }
v_23640:
    return onevalue(v_23731);
}



// Code for fnom

static LispObject CC_fnom(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23678;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_23634;
// end of prologue
    v_23678 = elt(env, 1); // "<OMA>"
    fn = elt(env, 11); // printout
    v_23678 = (*qfn1(fn))(fn, v_23678);
    env = stack[-1];
    v_23678 = lisp_true;
    fn = elt(env, 12); // indent!*
    v_23678 = (*qfn1(fn))(fn, v_23678);
    env = stack[-1];
    v_23678 = elt(env, 2); // "<OMATTR>"
    fn = elt(env, 11); // printout
    v_23678 = (*qfn1(fn))(fn, v_23678);
    env = stack[-1];
    v_23678 = lisp_true;
    fn = elt(env, 12); // indent!*
    v_23678 = (*qfn1(fn))(fn, v_23678);
    env = stack[-1];
    v_23678 = elt(env, 3); // "<OMATP>"
    fn = elt(env, 11); // printout
    v_23678 = (*qfn1(fn))(fn, v_23678);
    env = stack[-1];
    v_23678 = lisp_true;
    fn = elt(env, 12); // indent!*
    v_23678 = (*qfn1(fn))(fn, v_23678);
    env = stack[-1];
    v_23678 = elt(env, 4); // "<OMS cd=""typmml"" name=""type""/>"
    fn = elt(env, 11); // printout
    v_23678 = (*qfn1(fn))(fn, v_23678);
    env = stack[-1];
    v_23678 = elt(env, 5); // "<OMS cd=""typmml"" name="""
    fn = elt(env, 11); // printout
    v_23678 = (*qfn1(fn))(fn, v_23678);
    env = stack[-1];
    v_23678 = elt(env, 6); // "fn_type"
    v_23678 = Lprinc(nil, v_23678);
    env = stack[-1];
    v_23678 = elt(env, 7); // """/>"
    v_23678 = Lprinc(nil, v_23678);
    env = stack[-1];
    v_23678 = nil;
    fn = elt(env, 12); // indent!*
    v_23678 = (*qfn1(fn))(fn, v_23678);
    env = stack[-1];
    v_23678 = elt(env, 8); // "</OMATP>"
    fn = elt(env, 11); // printout
    v_23678 = (*qfn1(fn))(fn, v_23678);
    env = stack[-1];
    v_23678 = stack[0];
    v_23678 = qcar(v_23678);
    fn = elt(env, 13); // objectom
    v_23678 = (*qfn1(fn))(fn, v_23678);
    env = stack[-1];
    v_23678 = nil;
    fn = elt(env, 12); // indent!*
    v_23678 = (*qfn1(fn))(fn, v_23678);
    env = stack[-1];
    v_23678 = elt(env, 9); // "</OMATTR>"
    fn = elt(env, 11); // printout
    v_23678 = (*qfn1(fn))(fn, v_23678);
    env = stack[-1];
    v_23678 = stack[0];
    v_23678 = qcdr(v_23678);
    v_23678 = qcdr(v_23678);
    fn = elt(env, 14); // multiom
    v_23678 = (*qfn1(fn))(fn, v_23678);
    env = stack[-1];
    v_23678 = nil;
    fn = elt(env, 12); // indent!*
    v_23678 = (*qfn1(fn))(fn, v_23678);
    env = stack[-1];
    v_23678 = elt(env, 10); // "</OMA>"
    fn = elt(env, 11); // printout
    v_23678 = (*qfn1(fn))(fn, v_23678);
    v_23678 = nil;
    return onevalue(v_23678);
}



// Code for ldf!-simp

static LispObject CC_ldfKsimp(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23705, v_23706;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_23706 = v_23634;
// end of prologue
    v_23705 = v_23706;
    if (v_23705 == nil) goto v_23638;
    else goto v_23639;
v_23638:
    v_23705 = nil;
    goto v_23637;
v_23639:
    v_23705 = v_23706;
    v_23705 = qcdr(v_23705);
    if (v_23705 == nil) goto v_23642;
    else goto v_23643;
v_23642:
    goto v_23654;
v_23650:
    goto v_23660;
v_23656:
    v_23705 = v_23706;
    v_23705 = qcar(v_23705);
    v_23705 = qcar(v_23705);
    v_23706 = qcar(v_23705);
    goto v_23657;
v_23658:
    v_23705 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23659;
v_23660:
    goto v_23656;
v_23657:
    goto v_23658;
v_23659:
    fn = elt(env, 2); // to
    v_23706 = (*qfn2(fn))(fn, v_23706, v_23705);
    env = stack[-1];
    goto v_23651;
v_23652:
    v_23705 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23653;
v_23654:
    goto v_23650;
v_23651:
    goto v_23652;
v_23653:
    v_23705 = cons(v_23706, v_23705);
    env = stack[-1];
    v_23705 = ncons(v_23705);
    env = stack[-1];
    fn = elt(env, 3); // prepf
    v_23705 = (*qfn1(fn))(fn, v_23705);
    env = stack[-1];
    fn = elt(env, 4); // simp
    v_23705 = (*qfn1(fn))(fn, v_23705);
    v_23705 = qcar(v_23705);
    goto v_23637;
v_23643:
    v_23705 = v_23706;
    fn = elt(env, 3); // prepf
    v_23705 = (*qfn1(fn))(fn, v_23705);
    env = stack[-1];
    fn = elt(env, 4); // simp
    v_23705 = (*qfn1(fn))(fn, v_23705);
    env = stack[-1];
    v_23705 = qcar(v_23705);
    v_23706 = v_23705;
    v_23705 = v_23706;
    if (!consp(v_23705)) goto v_23684;
    else goto v_23685;
v_23684:
    v_23705 = lisp_true;
    goto v_23683;
v_23685:
    v_23705 = v_23706;
    v_23705 = qcar(v_23705);
    v_23705 = (consp(v_23705) ? nil : lisp_true);
    goto v_23683;
    v_23705 = nil;
v_23683:
    if (v_23705 == nil) goto v_23680;
    else goto v_23681;
v_23680:
    goto v_23698;
v_23694:
    stack[0] = v_23706;
    goto v_23695;
v_23696:
    v_23705 = v_23706;
    fn = elt(env, 5); // comfac
    v_23705 = (*qfn1(fn))(fn, v_23705);
    env = stack[-1];
    v_23705 = qcdr(v_23705);
    goto v_23697;
v_23698:
    goto v_23694;
v_23695:
    goto v_23696;
v_23697:
    fn = elt(env, 6); // quotf
    v_23705 = (*qfn2(fn))(fn, stack[0], v_23705);
    env = stack[-1];
    v_23706 = v_23705;
    goto v_23679;
v_23681:
v_23679:
    v_23705 = v_23706;
    {
        fn = elt(env, 7); // absf
        return (*qfn1(fn))(fn, v_23705);
    }
    goto v_23637;
    v_23705 = nil;
v_23637:
    return onevalue(v_23705);
}



// Code for genexp

static LispObject CC_genexp(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23654;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_23634;
// end of prologue
v_23633:
    v_23654 = stack[0];
    if (!consp(v_23654)) goto v_23638;
    else goto v_23639;
v_23638:
    v_23654 = stack[0];
    {
        fn = elt(env, 1); // genp
        return (*qfn1(fn))(fn, v_23654);
    }
v_23639:
    v_23654 = stack[0];
    v_23654 = qcar(v_23654);
    v_23654 = CC_genexp(elt(env, 0), v_23654);
    env = stack[-1];
    if (v_23654 == nil) goto v_23647;
    else goto v_23646;
v_23647:
    v_23654 = stack[0];
    v_23654 = qcdr(v_23654);
    stack[0] = v_23654;
    goto v_23633;
v_23646:
    goto v_23637;
    v_23654 = nil;
v_23637:
    return onevalue(v_23654);
}



// Code for vdpmember

static LispObject CC_vdpmember(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23662, v_23663;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23634,v_23635);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_23635;
    stack[-1] = v_23634;
// end of prologue
v_23639:
    v_23662 = stack[0];
    if (v_23662 == nil) goto v_23642;
    else goto v_23643;
v_23642:
    v_23662 = nil;
    goto v_23638;
v_23643:
    goto v_23653;
v_23649:
    v_23663 = stack[-1];
    goto v_23650;
v_23651:
    v_23662 = stack[0];
    v_23662 = qcar(v_23662);
    goto v_23652;
v_23653:
    goto v_23649;
v_23650:
    goto v_23651;
v_23652:
    fn = elt(env, 1); // vdpequal
    v_23662 = (*qfn2(fn))(fn, v_23663, v_23662);
    env = stack[-2];
    if (v_23662 == nil) goto v_23647;
    v_23662 = stack[0];
    goto v_23638;
v_23647:
    v_23662 = stack[0];
    v_23662 = qcdr(v_23662);
    stack[0] = v_23662;
    goto v_23639;
    v_23662 = nil;
v_23638:
    return onevalue(v_23662);
}



// Code for evinsert

static LispObject CC_evinsert(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23700, v_23701, v_23702;
    LispObject fn;
    LispObject v_23637, v_23636, v_23635, v_23634;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "evinsert");
    va_start(aa, nargs);
    v_23634 = va_arg(aa, LispObject);
    v_23635 = va_arg(aa, LispObject);
    v_23636 = va_arg(aa, LispObject);
    v_23637 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_23637,v_23636,v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_23634,v_23635,v_23636,v_23637);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_23637;
    stack[-1] = v_23636;
    stack[-2] = v_23635;
    stack[-3] = v_23634;
// end of prologue
    v_23702 = nil;
v_23642:
    v_23700 = stack[-3];
    if (v_23700 == nil) goto v_23649;
    else goto v_23650;
v_23649:
    v_23700 = lisp_true;
    goto v_23648;
v_23650:
    v_23700 = stack[0];
    v_23700 = (v_23700 == nil ? lisp_true : nil);
    goto v_23648;
    v_23700 = nil;
v_23648:
    if (v_23700 == nil) goto v_23646;
    v_23700 = v_23702;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_23700);
    }
v_23646:
    goto v_23665;
v_23661:
    v_23700 = stack[0];
    v_23701 = qcar(v_23700);
    goto v_23662;
v_23663:
    v_23700 = stack[-2];
    goto v_23664;
v_23665:
    goto v_23661;
v_23662:
    goto v_23663;
v_23664:
    if (equal(v_23701, v_23700)) goto v_23659;
    else goto v_23660;
v_23659:
    goto v_23674;
v_23670:
    stack[0] = v_23702;
    goto v_23671;
v_23672:
    goto v_23681;
v_23677:
    v_23701 = stack[-1];
    goto v_23678;
v_23679:
    v_23700 = stack[-3];
    v_23700 = qcdr(v_23700);
    goto v_23680;
v_23681:
    goto v_23677;
v_23678:
    goto v_23679;
v_23680:
    v_23700 = cons(v_23701, v_23700);
    env = stack[-4];
    goto v_23673;
v_23674:
    goto v_23670;
v_23671:
    goto v_23672;
v_23673:
    {
        LispObject v_23707 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_23707, v_23700);
    }
v_23660:
    goto v_23692;
v_23688:
    v_23700 = stack[-3];
    v_23700 = qcar(v_23700);
    goto v_23689;
v_23690:
    v_23701 = v_23702;
    goto v_23691;
v_23692:
    goto v_23688;
v_23689:
    goto v_23690;
v_23691:
    v_23700 = cons(v_23700, v_23701);
    env = stack[-4];
    v_23702 = v_23700;
    v_23700 = stack[-3];
    v_23700 = qcdr(v_23700);
    stack[-3] = v_23700;
    v_23700 = stack[0];
    v_23700 = qcdr(v_23700);
    stack[0] = v_23700;
    goto v_23642;
    v_23700 = nil;
    return onevalue(v_23700);
}



// Code for aceq

static LispObject CC_aceq(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23678, v_23679, v_23680, v_23681;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23634,v_23635);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_23679 = v_23635;
    v_23680 = v_23634;
// end of prologue
v_23640:
    v_23678 = v_23680;
    if (v_23678 == nil) goto v_23643;
    else goto v_23644;
v_23643:
    v_23678 = v_23679;
    v_23678 = (v_23678 == nil ? lisp_true : nil);
    goto v_23639;
v_23644:
    v_23678 = v_23679;
    if (v_23678 == nil) goto v_23648;
    else goto v_23649;
v_23648:
    v_23678 = nil;
    goto v_23639;
v_23649:
    goto v_23658;
v_23654:
    v_23678 = v_23680;
    v_23681 = qcar(v_23678);
    goto v_23655;
v_23656:
    v_23678 = v_23679;
    goto v_23657;
v_23658:
    goto v_23654;
v_23655:
    goto v_23656;
v_23657:
    v_23678 = Lmember(nil, v_23681, v_23678);
    if (v_23678 == nil) goto v_23653;
    v_23678 = v_23680;
    v_23678 = qcdr(v_23678);
    stack[0] = v_23678;
    goto v_23670;
v_23666:
    v_23678 = v_23680;
    v_23678 = qcar(v_23678);
    goto v_23667;
v_23668:
    goto v_23669;
v_23670:
    goto v_23666;
v_23667:
    goto v_23668;
v_23669:
    v_23678 = Ldelete(nil, v_23678, v_23679);
    env = stack[-1];
    v_23679 = v_23678;
    v_23678 = stack[0];
    v_23680 = v_23678;
    goto v_23640;
v_23653:
    v_23678 = nil;
    goto v_23639;
    v_23678 = nil;
v_23639:
    return onevalue(v_23678);
}



// Code for calc_atlas

static LispObject CC_calc_atlas(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23657, v_23658, v_23659, v_23660;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23657 = v_23635;
    v_23658 = v_23634;
// end of prologue
    goto v_23646;
v_23638:
    v_23659 = v_23658;
    v_23660 = qcar(v_23659);
    goto v_23639;
v_23640:
    v_23659 = v_23658;
    v_23659 = qcdr(v_23659);
    v_23659 = qcdr(v_23659);
    v_23659 = qcar(v_23659);
    goto v_23641;
v_23642:
    v_23658 = qcdr(v_23658);
    v_23658 = qcar(v_23658);
    goto v_23643;
v_23644:
    goto v_23645;
v_23646:
    goto v_23638;
v_23639:
    goto v_23640;
v_23641:
    goto v_23642;
v_23643:
    goto v_23644;
v_23645:
    {
        fn = elt(env, 1); // calc_map_2d
        return (*qfnn(fn))(fn, 4, v_23660, v_23659, v_23658, v_23657);
    }
}



// Code for log_freevars

static LispObject CC_log_freevars(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23883, v_23884, v_23885;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23634,v_23635);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_23635;
    v_23884 = v_23634;
// end of prologue
    v_23883 = stack[0];
    if (!consp(v_23883)) goto v_23639;
    else goto v_23640;
v_23639:
    v_23883 = stack[0];
    if (symbolp(v_23883)) goto v_23649;
    v_23883 = lisp_true;
    goto v_23647;
v_23649:
    goto v_23661;
v_23657:
    v_23883 = stack[0];
    goto v_23658;
v_23659:
    goto v_23660;
v_23661:
    goto v_23657;
v_23658:
    goto v_23659;
v_23660:
    v_23883 = Lmember(nil, v_23883, v_23884);
    if (v_23883 == nil) goto v_23656;
    else goto v_23655;
v_23656:
    v_23883 = stack[0];
    v_23883 = Lsymbol_globalp(nil, v_23883);
    env = stack[-1];
    if (v_23883 == nil) goto v_23667;
    else goto v_23666;
v_23667:
    v_23883 = stack[0];
    v_23883 = Lsymbol_specialp(nil, v_23883);
    env = stack[-1];
    if (v_23883 == nil) goto v_23672;
    else goto v_23671;
v_23672:
    goto v_23683;
v_23679:
    v_23884 = stack[0];
    goto v_23680;
v_23681:
    v_23883 = elt(env, 1); // constant!?
    goto v_23682;
v_23683:
    goto v_23679;
v_23680:
    goto v_23681;
v_23682:
    v_23883 = get(v_23884, v_23883);
    env = stack[-1];
    if (v_23883 == nil) goto v_23677;
    else goto v_23676;
v_23677:
    v_23883 = stack[0];
    if (v_23883 == nil) goto v_23688;
    else goto v_23689;
v_23688:
    v_23883 = lisp_true;
    goto v_23687;
v_23689:
    goto v_23698;
v_23694:
    v_23884 = stack[0];
    goto v_23695;
v_23696:
    v_23883 = lisp_true;
    goto v_23697;
v_23698:
    goto v_23694;
v_23695:
    goto v_23696;
v_23697:
    v_23883 = (equal(v_23884, v_23883) ? lisp_true : nil);
    goto v_23687;
    v_23883 = nil;
v_23687:
v_23676:
v_23671:
v_23666:
v_23655:
    goto v_23647;
    v_23883 = nil;
v_23647:
    if (v_23883 == nil) goto v_23645;
    v_23883 = nil;
    goto v_23643;
v_23645:
    v_23883 = Lposn(nil, 0);
    env = stack[-1];
    v_23883 = (LispObject)zerop(v_23883);
    v_23883 = v_23883 ? lisp_true : nil;
    env = stack[-1];
    if (v_23883 == nil) goto v_23707;
    else goto v_23708;
v_23707:
    v_23883 = Lterpri(nil, 0);
    env = stack[-1];
    goto v_23706;
v_23708:
v_23706:
    v_23883 = elt(env, 2); // "+++ Use of free variable in smacro/inline body: "
    v_23883 = Lprinc(nil, v_23883);
    env = stack[-1];
    v_23883 = stack[0];
    v_23883 = Lprint(nil, v_23883);
    env = stack[-1];
    v_23883 = elt(env, 3); // "+++ Macro was: "
    v_23883 = Lprinc(nil, v_23883);
    env = stack[-1];
    v_23883 = qvalue(elt(env, 4)); // inlineinfo
    v_23883 = Lprint(nil, v_23883);
    v_23883 = lisp_true;
    goto v_23643;
    v_23883 = nil;
v_23643:
    goto v_23638;
v_23640:
    goto v_23732;
v_23728:
    v_23885 = stack[0];
    goto v_23729;
v_23730:
    v_23883 = elt(env, 5); // quote
    goto v_23731;
v_23732:
    goto v_23728;
v_23729:
    goto v_23730;
v_23731:
    if (!consp(v_23885)) goto v_23726;
    v_23885 = qcar(v_23885);
    if (v_23885 == v_23883) goto v_23725;
    else goto v_23726;
v_23725:
    v_23883 = lisp_true;
    goto v_23724;
v_23726:
    goto v_23751;
v_23747:
    v_23885 = stack[0];
    goto v_23748;
v_23749:
    v_23883 = elt(env, 6); // function
    goto v_23750;
v_23751:
    goto v_23747;
v_23748:
    goto v_23749;
v_23750:
    if (!consp(v_23885)) goto v_23745;
    v_23885 = qcar(v_23885);
    if (v_23885 == v_23883) goto v_23744;
    else goto v_23745;
v_23744:
    v_23883 = stack[0];
    v_23883 = qcdr(v_23883);
    v_23883 = qcar(v_23883);
    v_23883 = (consp(v_23883) ? nil : lisp_true);
    goto v_23743;
v_23745:
    v_23883 = nil;
    goto v_23743;
    v_23883 = nil;
v_23743:
    if (v_23883 == nil) goto v_23741;
    v_23883 = lisp_true;
    goto v_23739;
v_23741:
    goto v_23769;
v_23765:
    v_23885 = stack[0];
    goto v_23766;
v_23767:
    v_23883 = elt(env, 7); // go
    goto v_23768;
v_23769:
    goto v_23765;
v_23766:
    goto v_23767;
v_23768:
    v_23883 = Leqcar(nil, v_23885, v_23883);
    env = stack[-1];
    goto v_23739;
    v_23883 = nil;
v_23739:
    goto v_23724;
    v_23883 = nil;
v_23724:
    if (v_23883 == nil) goto v_23722;
    v_23883 = nil;
    goto v_23638;
v_23722:
    goto v_23780;
v_23776:
    v_23885 = stack[0];
    goto v_23777;
v_23778:
    v_23883 = elt(env, 8); // prog
    goto v_23779;
v_23780:
    goto v_23776;
v_23777:
    goto v_23778;
v_23779:
    if (!consp(v_23885)) goto v_23774;
    v_23885 = qcar(v_23885);
    if (v_23885 == v_23883) goto v_23773;
    else goto v_23774;
v_23773:
    goto v_23790;
v_23784:
    goto v_23796;
v_23792:
    v_23883 = stack[0];
    v_23883 = qcdr(v_23883);
    v_23883 = qcar(v_23883);
    goto v_23793;
v_23794:
    goto v_23795;
v_23796:
    goto v_23792;
v_23793:
    goto v_23794;
v_23795:
    v_23885 = Lappend(nil, v_23883, v_23884);
    env = stack[-1];
    goto v_23785;
v_23786:
    v_23883 = stack[0];
    v_23884 = qcdr(v_23883);
    goto v_23787;
v_23788:
    v_23883 = lisp_true;
    goto v_23789;
v_23790:
    goto v_23784;
v_23785:
    goto v_23786;
v_23787:
    goto v_23788;
v_23789:
    {
        fn = elt(env, 11); // log_freevars_list
        return (*qfnn(fn))(fn, 3, v_23885, v_23884, v_23883);
    }
v_23774:
    goto v_23811;
v_23807:
    v_23885 = stack[0];
    goto v_23808;
v_23809:
    v_23883 = elt(env, 9); // lambda
    goto v_23810;
v_23811:
    goto v_23807;
v_23808:
    goto v_23809;
v_23810:
    if (!consp(v_23885)) goto v_23805;
    v_23885 = qcar(v_23885);
    if (v_23885 == v_23883) goto v_23804;
    else goto v_23805;
v_23804:
    goto v_23821;
v_23815:
    goto v_23827;
v_23823:
    v_23883 = stack[0];
    v_23883 = qcdr(v_23883);
    v_23883 = qcar(v_23883);
    goto v_23824;
v_23825:
    goto v_23826;
v_23827:
    goto v_23823;
v_23824:
    goto v_23825;
v_23826:
    v_23885 = Lappend(nil, v_23883, v_23884);
    env = stack[-1];
    goto v_23816;
v_23817:
    v_23883 = stack[0];
    v_23884 = qcdr(v_23883);
    goto v_23818;
v_23819:
    v_23883 = nil;
    goto v_23820;
v_23821:
    goto v_23815;
v_23816:
    goto v_23817;
v_23818:
    goto v_23819;
v_23820:
    {
        fn = elt(env, 11); // log_freevars_list
        return (*qfnn(fn))(fn, 3, v_23885, v_23884, v_23883);
    }
v_23805:
    goto v_23842;
v_23838:
    v_23885 = stack[0];
    goto v_23839;
v_23840:
    v_23883 = elt(env, 10); // cond
    goto v_23841;
v_23842:
    goto v_23838;
v_23839:
    goto v_23840;
v_23841:
    if (!consp(v_23885)) goto v_23836;
    v_23885 = qcar(v_23885);
    if (v_23885 == v_23883) goto v_23835;
    else goto v_23836;
v_23835:
    goto v_23850;
v_23846:
    goto v_23847;
v_23848:
    v_23883 = stack[0];
    v_23883 = qcdr(v_23883);
    goto v_23849;
v_23850:
    goto v_23846;
v_23847:
    goto v_23848;
v_23849:
    {
        fn = elt(env, 12); // log_freevars_list_list
        return (*qfn2(fn))(fn, v_23884, v_23883);
    }
v_23836:
    v_23883 = stack[0];
    v_23883 = qcar(v_23883);
    if (!consp(v_23883)) goto v_23854;
    else goto v_23855;
v_23854:
    goto v_23865;
v_23859:
    v_23885 = v_23884;
    goto v_23860;
v_23861:
    v_23883 = stack[0];
    v_23884 = qcdr(v_23883);
    goto v_23862;
v_23863:
    v_23883 = nil;
    goto v_23864;
v_23865:
    goto v_23859;
v_23860:
    goto v_23861;
v_23862:
    goto v_23863;
v_23864:
    {
        fn = elt(env, 11); // log_freevars_list
        return (*qfnn(fn))(fn, 3, v_23885, v_23884, v_23883);
    }
v_23855:
    goto v_23879;
v_23873:
    v_23885 = v_23884;
    goto v_23874;
v_23875:
    v_23884 = stack[0];
    goto v_23876;
v_23877:
    v_23883 = nil;
    goto v_23878;
v_23879:
    goto v_23873;
v_23874:
    goto v_23875;
v_23876:
    goto v_23877;
v_23878:
    {
        fn = elt(env, 11); // log_freevars_list
        return (*qfnn(fn))(fn, 3, v_23885, v_23884, v_23883);
    }
    v_23883 = nil;
v_23638:
    return onevalue(v_23883);
}



// Code for reduce

static LispObject CC_reduce(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23691, v_23692, v_23693;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23634,v_23635);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_23635;
    v_23691 = v_23634;
// end of prologue
    stack[0] = v_23691;
    v_23691 = qvalue(elt(env, 2)); // !*yyy
    if (v_23691 == nil) goto v_23646;
    goto v_23653;
v_23649:
    v_23692 = stack[0];
    goto v_23650;
v_23651:
    v_23691 = stack[-1];
    goto v_23652;
v_23653:
    goto v_23649;
v_23650:
    goto v_23651;
v_23652:
    fn = elt(env, 4); // reduce!-ratios
    v_23691 = (*qfn2(fn))(fn, v_23692, v_23691);
    env = stack[-3];
    stack[0] = v_23691;
    goto v_23644;
v_23646:
v_23644:
    v_23691 = stack[-1];
    fn = elt(env, 5); // set!-weights
    v_23691 = (*qfn1(fn))(fn, v_23691);
    env = stack[-3];
    stack[-2] = v_23691;
    v_23691 = qvalue(elt(env, 3)); // !*xxx
    if (v_23691 == nil) goto v_23661;
    goto v_23670;
v_23664:
    v_23693 = stack[0];
    goto v_23665;
v_23666:
    v_23692 = stack[-1];
    goto v_23667;
v_23668:
    v_23691 = stack[-2];
    goto v_23669;
v_23670:
    goto v_23664;
v_23665:
    goto v_23666;
v_23667:
    goto v_23668;
v_23669:
    fn = elt(env, 6); // reduce!-columns
    v_23691 = (*qfnn(fn))(fn, 3, v_23693, v_23692, v_23691);
    env = stack[-3];
    stack[0] = v_23691;
    goto v_23659;
v_23661:
v_23659:
    v_23691 = qvalue(elt(env, 3)); // !*xxx
    if (v_23691 == nil) goto v_23677;
    goto v_23686;
v_23680:
    v_23693 = stack[0];
    goto v_23681;
v_23682:
    v_23692 = stack[-1];
    goto v_23683;
v_23684:
    v_23691 = stack[-2];
    goto v_23685;
v_23686:
    goto v_23680;
v_23681:
    goto v_23682;
v_23683:
    goto v_23684;
v_23685:
    fn = elt(env, 7); // reduce!-weights
    v_23691 = (*qfnn(fn))(fn, 3, v_23693, v_23692, v_23691);
    stack[0] = v_23691;
    goto v_23675;
v_23677:
v_23675:
    v_23691 = stack[0];
    return onevalue(v_23691);
}



// Code for oddext

static LispObject CC_oddext(LispObject env,
                         LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23704, v_23705;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23635);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23635);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_23704 = v_23635;
// end of prologue
// Binding odd_var
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = v_23704; // odd_var
    goto v_23649;
v_23645:
    v_23705 = qvalue(elt(env, 1)); // odd_var
    goto v_23646;
v_23647:
    v_23704 = qvalue(elt(env, 2)); // all_parametric_odd!*
    goto v_23648;
v_23649:
    goto v_23645;
v_23646:
    goto v_23647;
v_23648:
    v_23704 = Lmember(nil, v_23705, v_23704);
    if (v_23704 == nil) goto v_23644;
    goto v_23658;
v_23654:
    stack[0] = elt(env, 3); // ext
    goto v_23655;
v_23656:
    goto v_23665;
v_23661:
    v_23705 = qvalue(elt(env, 1)); // odd_var
    goto v_23662;
v_23663:
    v_23704 = qvalue(elt(env, 2)); // all_parametric_odd!*
    goto v_23664;
v_23665:
    goto v_23661;
v_23662:
    goto v_23663;
v_23664:
    fn = elt(env, 7); // cde_position
    v_23704 = (*qfn2(fn))(fn, v_23705, v_23704);
    env = stack[-3];
    goto v_23657;
v_23658:
    goto v_23654;
v_23655:
    goto v_23656;
v_23657:
    v_23704 = list2(stack[0], v_23704);
    goto v_23642;
v_23644:
    goto v_23674;
v_23670:
    v_23705 = qvalue(elt(env, 1)); // odd_var
    goto v_23671;
v_23672:
    v_23704 = qvalue(elt(env, 4)); // all_principal_odd!*
    goto v_23673;
v_23674:
    goto v_23670;
v_23671:
    goto v_23672;
v_23673:
    v_23704 = Lmember(nil, v_23705, v_23704);
    if (v_23704 == nil) goto v_23669;
    goto v_23683;
v_23679:
    stack[-1] = elt(env, 3); // ext
    goto v_23680;
v_23681:
    goto v_23690;
v_23686:
    stack[0] = qvalue(elt(env, 5)); // n_all_parametric_ext
    goto v_23687;
v_23688:
    goto v_23697;
v_23693:
    v_23705 = qvalue(elt(env, 1)); // odd_var
    goto v_23694;
v_23695:
    v_23704 = qvalue(elt(env, 4)); // all_principal_odd!*
    goto v_23696;
v_23697:
    goto v_23693;
v_23694:
    goto v_23695;
v_23696:
    fn = elt(env, 7); // cde_position
    v_23704 = (*qfn2(fn))(fn, v_23705, v_23704);
    env = stack[-3];
    goto v_23689;
v_23690:
    goto v_23686;
v_23687:
    goto v_23688;
v_23689:
    v_23704 = plus2(stack[0], v_23704);
    env = stack[-3];
    goto v_23682;
v_23683:
    goto v_23679;
v_23680:
    goto v_23681;
v_23682:
    v_23704 = list2(stack[-1], v_23704);
    goto v_23642;
v_23669:
    v_23704 = elt(env, 6); // "the argument of oddext must be an odd variable"
    fn = elt(env, 8); // rederr
    v_23704 = (*qfn1(fn))(fn, v_23704);
    goto v_23642;
    v_23704 = nil;
v_23642:
    ;}  // end of a binding scope
    return onevalue(v_23704);
}



// Code for ra_intequiv0

static LispObject CC_ra_intequiv0(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23794, v_23795, v_23796, v_23797;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_23634;
// end of prologue
    v_23794 = stack[-3];
    fn = elt(env, 3); // ra_zerop
    v_23794 = (*qfn1(fn))(fn, v_23794);
    env = stack[-5];
    if (v_23794 == nil) goto v_23646;
    v_23794 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23641;
v_23646:
    v_23794 = stack[-3];
    fn = elt(env, 4); // ra_f
    v_23794 = (*qfn1(fn))(fn, v_23794);
    env = stack[-5];
    stack[-4] = v_23794;
    goto v_23662;
v_23658:
    v_23794 = stack[-4];
    v_23794 = qcar(v_23794);
    v_23794 = qcar(v_23794);
    v_23795 = qcdr(v_23794);
    goto v_23659;
v_23660:
    v_23794 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23661;
v_23662:
    goto v_23658;
v_23659:
    goto v_23660;
v_23661:
    v_23794 = Leqn(nil, v_23795, v_23794);
    env = stack[-5];
    if (v_23794 == nil) goto v_23655;
    goto v_23674;
v_23670:
    v_23794 = stack[-4];
    v_23794 = qcar(v_23794);
    v_23795 = qcdr(v_23794);
    goto v_23671;
v_23672:
    v_23794 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23673;
v_23674:
    goto v_23670;
v_23671:
    goto v_23672;
v_23673:
    v_23794 = Leqn(nil, v_23795, v_23794);
    env = stack[-5];
    if (v_23794 == nil) goto v_23655;
    v_23794 = stack[-4];
    v_23794 = qcdr(v_23794);
    {
        fn = elt(env, 5); // negf
        return (*qfn1(fn))(fn, v_23794);
    }
v_23655:
    v_23794 = stack[-3];
    fn = elt(env, 6); // ra_iv
    v_23794 = (*qfn1(fn))(fn, v_23794);
    env = stack[-5];
    fn = elt(env, 7); // riv_l
    v_23794 = (*qfn1(fn))(fn, v_23794);
    env = stack[-5];
    stack[-2] = v_23794;
    v_23794 = stack[-3];
    fn = elt(env, 6); // ra_iv
    v_23794 = (*qfn1(fn))(fn, v_23794);
    env = stack[-5];
    fn = elt(env, 8); // riv_u
    v_23794 = (*qfn1(fn))(fn, v_23794);
    env = stack[-5];
    stack[-1] = v_23794;
v_23690:
    goto v_23700;
v_23696:
    goto v_23706;
v_23702:
    stack[0] = stack[-1];
    goto v_23703;
v_23704:
    v_23794 = stack[-2];
    fn = elt(env, 9); // negsq
    v_23794 = (*qfn1(fn))(fn, v_23794);
    env = stack[-5];
    goto v_23705;
v_23706:
    goto v_23702;
v_23703:
    goto v_23704;
v_23705:
    fn = elt(env, 10); // addsq
    stack[0] = (*qfn2(fn))(fn, stack[0], v_23794);
    env = stack[-5];
    goto v_23697;
v_23698:
    goto v_23715;
v_23711:
    v_23795 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23712;
v_23713:
    v_23794 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23714;
v_23715:
    goto v_23711;
v_23712:
    goto v_23713;
v_23714:
    v_23794 = cons(v_23795, v_23794);
    env = stack[-5];
    goto v_23699;
v_23700:
    goto v_23696;
v_23697:
    goto v_23698;
v_23699:
    fn = elt(env, 11); // sfto_greaterq
    v_23794 = (*qfn2(fn))(fn, stack[0], v_23794);
    env = stack[-5];
    if (v_23794 == nil) goto v_23693;
    else goto v_23694;
v_23693:
    goto v_23689;
v_23694:
    goto v_23731;
v_23723:
    v_23797 = stack[-4];
    goto v_23724;
v_23725:
    v_23796 = stack[-2];
    goto v_23726;
v_23727:
    v_23795 = stack[-1];
    goto v_23728;
v_23729:
    v_23794 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23730;
v_23731:
    goto v_23723;
v_23724:
    goto v_23725;
v_23726:
    goto v_23727;
v_23728:
    goto v_23729;
v_23730:
    fn = elt(env, 12); // ra_refine1
    v_23794 = (*qfnn(fn))(fn, 4, v_23797, v_23796, v_23795, v_23794);
    env = stack[-5];
    v_23795 = v_23794;
    v_23794 = v_23795;
    v_23794 = qcar(v_23794);
    stack[-2] = v_23794;
    v_23794 = v_23795;
    v_23794 = qcdr(v_23794);
    stack[-1] = v_23794;
    goto v_23690;
v_23689:
    goto v_23746;
v_23742:
    v_23794 = stack[-2];
    fn = elt(env, 13); // sfto_floorq
    v_23794 = (*qfn1(fn))(fn, v_23794);
    env = stack[-5];
    v_23795 = qcar(v_23794);
    goto v_23743;
v_23744:
    v_23794 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23745;
v_23746:
    goto v_23742;
v_23743:
    goto v_23744;
v_23745:
    fn = elt(env, 14); // addf
    v_23794 = (*qfn2(fn))(fn, v_23795, v_23794);
    env = stack[-5];
    stack[0] = v_23794;
    goto v_23761;
v_23757:
    goto v_23767;
v_23763:
    v_23795 = stack[0];
    goto v_23764;
v_23765:
    v_23794 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23766;
v_23767:
    goto v_23763;
v_23764:
    goto v_23765;
v_23766:
    v_23795 = cons(v_23795, v_23794);
    env = stack[-5];
    goto v_23758;
v_23759:
    v_23794 = stack[-1];
    goto v_23760;
v_23761:
    goto v_23757;
v_23758:
    goto v_23759;
v_23760:
    fn = elt(env, 15); // sfto_lessq
    v_23794 = (*qfn2(fn))(fn, v_23795, v_23794);
    env = stack[-5];
    if (v_23794 == nil) goto v_23754;
    goto v_23777;
v_23773:
    stack[-1] = stack[-4];
    goto v_23774;
v_23775:
    goto v_23785;
v_23781:
    v_23795 = elt(env, 2); // x
    goto v_23782;
v_23783:
    v_23794 = stack[0];
    goto v_23784;
v_23785:
    goto v_23781;
v_23782:
    goto v_23783;
v_23784:
    v_23794 = cons(v_23795, v_23794);
    env = stack[-5];
    v_23794 = ncons(v_23794);
    env = stack[-5];
    goto v_23776;
v_23777:
    goto v_23773;
v_23774:
    goto v_23775;
v_23776:
    fn = elt(env, 16); // sfto_fsub1
    v_23794 = (*qfn2(fn))(fn, stack[-1], v_23794);
    if (v_23794 == nil) goto v_23771;
    else goto v_23754;
v_23771:
    v_23794 = stack[0];
    if (v_23794 == nil) goto v_23790;
    else goto v_23789;
v_23790:
    v_23794 = (LispObject)0+TAG_FIXNUM; // 0
v_23789:
    goto v_23641;
v_23754:
    v_23794 = stack[-3];
v_23641:
    return onevalue(v_23794);
}



// Code for lalr_augment_grammar

static LispObject CC_lalr_augment_grammar(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23670, v_23671;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_23634;
// end of prologue
    goto v_23644;
v_23640:
    v_23671 = elt(env, 1); // !S!'
    goto v_23641;
v_23642:
    v_23670 = stack[0];
    goto v_23643;
v_23644:
    goto v_23640;
v_23641:
    goto v_23642;
v_23643:
    v_23670 = Lassoc(nil, v_23671, v_23670);
    if (v_23670 == nil) goto v_23639;
    v_23670 = stack[0];
    goto v_23637;
v_23639:
    goto v_23656;
v_23652:
    goto v_23662;
v_23658:
    stack[-1] = elt(env, 1); // !S!'
    goto v_23659;
v_23660:
    v_23670 = stack[0];
    v_23670 = qcar(v_23670);
    v_23670 = qcar(v_23670);
    v_23670 = ncons(v_23670);
    env = stack[-2];
    v_23670 = ncons(v_23670);
    env = stack[-2];
    goto v_23661;
v_23662:
    goto v_23658;
v_23659:
    goto v_23660;
v_23661:
    v_23671 = list2(stack[-1], v_23670);
    goto v_23653;
v_23654:
    v_23670 = stack[0];
    goto v_23655;
v_23656:
    goto v_23652;
v_23653:
    goto v_23654;
v_23655:
    return cons(v_23671, v_23670);
    v_23670 = nil;
v_23637:
    return onevalue(v_23670);
}



// Code for createsinglevariablemonom

static LispObject CC_createsinglevariablemonom(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23673, v_23674, v_23675;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_23634;
// end of prologue
    v_23673 = (LispObject)16+TAG_FIXNUM; // 1
    v_23673 = Lmkvect(nil, v_23673);
    env = stack[-4];
    stack[-3] = v_23673;
    goto v_23648;
v_23642:
    v_23675 = stack[-3];
    goto v_23643;
v_23644:
    v_23674 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23645;
v_23646:
    v_23673 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23647;
v_23648:
    goto v_23642;
v_23643:
    goto v_23644;
v_23645:
    goto v_23646;
v_23647:
    *(LispObject *)((char *)v_23675 + (CELL-TAG_VECTOR) + (((intptr_t)v_23674-TAG_FIXNUM)/(16/CELL))) = v_23673;
    goto v_23658;
v_23652:
    stack[-1] = stack[-3];
    goto v_23653;
v_23654:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23655;
v_23656:
    goto v_23668;
v_23662:
    v_23675 = stack[-2];
    goto v_23663;
v_23664:
    v_23674 = nil;
    goto v_23665;
v_23666:
    v_23673 = nil;
    goto v_23667;
v_23668:
    goto v_23662;
v_23663:
    goto v_23664;
v_23665:
    goto v_23666;
v_23667:
    v_23673 = list2star(v_23675, v_23674, v_23673);
    goto v_23657;
v_23658:
    goto v_23652;
v_23653:
    goto v_23654;
v_23655:
    goto v_23656;
v_23657:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_23673;
    v_23673 = stack[-3];
    return onevalue(v_23673);
}



// Code for orddf

static LispObject CC_orddf(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23693, v_23694;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23634,v_23635);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_23635;
    stack[-1] = v_23634;
// end of prologue
v_23639:
    v_23693 = stack[-1];
    if (v_23693 == nil) goto v_23642;
    else goto v_23643;
v_23642:
    v_23693 = stack[0];
    if (v_23693 == nil) goto v_23647;
    else goto v_23648;
v_23647:
    v_23693 = elt(env, 1); // "Orddf = case"
    {
        fn = elt(env, 4); // interr
        return (*qfn1(fn))(fn, v_23693);
    }
v_23648:
    v_23693 = elt(env, 2); // "Orddf v longer than u"
    {
        fn = elt(env, 4); // interr
        return (*qfn1(fn))(fn, v_23693);
    }
    goto v_23641;
v_23643:
    v_23693 = stack[0];
    if (v_23693 == nil) goto v_23656;
    else goto v_23657;
v_23656:
    v_23693 = elt(env, 3); // "Orddf u longer than v"
    {
        fn = elt(env, 4); // interr
        return (*qfn1(fn))(fn, v_23693);
    }
v_23657:
    goto v_23668;
v_23664:
    v_23693 = stack[-1];
    v_23694 = qcar(v_23693);
    goto v_23665;
v_23666:
    v_23693 = stack[0];
    v_23693 = qcar(v_23693);
    goto v_23667;
v_23668:
    goto v_23664;
v_23665:
    goto v_23666;
v_23667:
    fn = elt(env, 5); // exptcompare
    v_23693 = (*qfn2(fn))(fn, v_23694, v_23693);
    env = stack[-2];
    if (v_23693 == nil) goto v_23662;
    v_23693 = lisp_true;
    goto v_23638;
v_23662:
    goto v_23681;
v_23677:
    v_23693 = stack[0];
    v_23694 = qcar(v_23693);
    goto v_23678;
v_23679:
    v_23693 = stack[-1];
    v_23693 = qcar(v_23693);
    goto v_23680;
v_23681:
    goto v_23677;
v_23678:
    goto v_23679;
v_23680:
    fn = elt(env, 5); // exptcompare
    v_23693 = (*qfn2(fn))(fn, v_23694, v_23693);
    env = stack[-2];
    if (v_23693 == nil) goto v_23675;
    v_23693 = nil;
    goto v_23638;
v_23675:
    v_23693 = stack[-1];
    v_23693 = qcdr(v_23693);
    stack[-1] = v_23693;
    v_23693 = stack[0];
    v_23693 = qcdr(v_23693);
    stack[0] = v_23693;
    goto v_23639;
v_23641:
    v_23693 = nil;
v_23638:
    return onevalue(v_23693);
}



// Code for cl_pnf1

static LispObject CC_cl_pnf1(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23673;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_23673 = v_23634;
// end of prologue
    fn = elt(env, 1); // cl_rename!-vars
    v_23673 = (*qfn1(fn))(fn, v_23673);
    env = stack[-2];
    fn = elt(env, 2); // cl_pnf2
    v_23673 = (*qfn1(fn))(fn, v_23673);
    env = stack[-2];
    stack[-1] = v_23673;
    v_23673 = stack[-1];
    v_23673 = qcdr(v_23673);
    if (v_23673 == nil) goto v_23646;
    else goto v_23647;
v_23646:
    v_23673 = lisp_true;
    goto v_23645;
v_23647:
    goto v_23658;
v_23654:
    v_23673 = stack[-1];
    v_23673 = qcar(v_23673);
    fn = elt(env, 3); // cl_qb
    stack[0] = (*qfn1(fn))(fn, v_23673);
    env = stack[-2];
    goto v_23655;
v_23656:
    v_23673 = stack[-1];
    v_23673 = qcdr(v_23673);
    v_23673 = qcar(v_23673);
    fn = elt(env, 3); // cl_qb
    v_23673 = (*qfn1(fn))(fn, v_23673);
    env = stack[-2];
    goto v_23657;
v_23658:
    goto v_23654;
v_23655:
    goto v_23656;
v_23657:
    v_23673 = (LispObject)lessp2(stack[0], v_23673);
    v_23673 = v_23673 ? lisp_true : nil;
    goto v_23645;
    v_23673 = nil;
v_23645:
    if (v_23673 == nil) goto v_23643;
    v_23673 = stack[-1];
    v_23673 = qcar(v_23673);
    goto v_23641;
v_23643:
    v_23673 = stack[-1];
    v_23673 = qcdr(v_23673);
    v_23673 = qcar(v_23673);
    goto v_23641;
    v_23673 = nil;
v_23641:
    return onevalue(v_23673);
}



// Code for mri_2ofsfat

static LispObject CC_mri_2ofsfat(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23649, v_23650;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_23634;
// end of prologue
    goto v_23643;
v_23637:
    v_23649 = stack[0];
    fn = elt(env, 1); // mri_op
    stack[-1] = (*qfn1(fn))(fn, v_23649);
    env = stack[-2];
    goto v_23638;
v_23639:
    v_23649 = stack[0];
    fn = elt(env, 2); // mri_arg2l
    v_23650 = (*qfn1(fn))(fn, v_23649);
    goto v_23640;
v_23641:
    v_23649 = nil;
    goto v_23642;
v_23643:
    goto v_23637;
v_23638:
    goto v_23639;
v_23640:
    goto v_23641;
v_23642:
    {
        LispObject v_23653 = stack[-1];
        return list3(v_23653, v_23650, v_23649);
    }
}



// Code for iv_cutcongs2

static LispObject CC_iv_cutcongs2(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23703, v_23704, v_23705;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23634,v_23635);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_23635;
    v_23705 = v_23634;
// end of prologue
    goto v_23645;
v_23641:
    v_23703 = stack[0];
    v_23703 = qcar(v_23703);
    v_23704 = qcar(v_23703);
    goto v_23642;
v_23643:
    v_23703 = elt(env, 1); // cong
    goto v_23644;
v_23645:
    goto v_23641;
v_23642:
    goto v_23643;
v_23644:
    if (v_23704 == v_23703) goto v_23639;
    else goto v_23640;
v_23639:
    goto v_23654;
v_23650:
    goto v_23660;
v_23656:
    goto v_23666;
v_23662:
    v_23703 = stack[0];
    v_23703 = qcdr(v_23703);
    goto v_23663;
v_23664:
    v_23704 = v_23705;
    goto v_23665;
v_23666:
    goto v_23662;
v_23663:
    goto v_23664;
v_23665:
    v_23704 = difference2(v_23703, v_23704);
    env = stack[-1];
    goto v_23657;
v_23658:
    v_23703 = stack[0];
    v_23703 = qcar(v_23703);
    v_23703 = qcdr(v_23703);
    goto v_23659;
v_23660:
    goto v_23656;
v_23657:
    goto v_23658;
v_23659:
    v_23704 = Cremainder(v_23704, v_23703);
    goto v_23651;
v_23652:
    v_23703 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23653;
v_23654:
    goto v_23650;
v_23651:
    goto v_23652;
v_23653:
    v_23703 = (v_23704 == v_23703 ? lisp_true : nil);
    goto v_23638;
v_23640:
    goto v_23681;
v_23677:
    goto v_23687;
v_23683:
    goto v_23693;
v_23689:
    v_23703 = stack[0];
    v_23703 = qcdr(v_23703);
    goto v_23690;
v_23691:
    v_23704 = v_23705;
    goto v_23692;
v_23693:
    goto v_23689;
v_23690:
    goto v_23691;
v_23692:
    v_23704 = difference2(v_23703, v_23704);
    env = stack[-1];
    goto v_23684;
v_23685:
    v_23703 = stack[0];
    v_23703 = qcar(v_23703);
    v_23703 = qcdr(v_23703);
    goto v_23686;
v_23687:
    goto v_23683;
v_23684:
    goto v_23685;
v_23686:
    v_23704 = Cremainder(v_23704, v_23703);
    goto v_23678;
v_23679:
    v_23703 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23680;
v_23681:
    goto v_23677;
v_23678:
    goto v_23679;
v_23680:
    v_23703 = (v_23704 == v_23703 ? lisp_true : nil);
    v_23703 = (v_23703 == nil ? lisp_true : nil);
    goto v_23638;
    v_23703 = nil;
v_23638:
    return onevalue(v_23703);
}



// Code for degree!-order

static LispObject CC_degreeKorder(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23683, v_23684, v_23685;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23683 = v_23635;
    v_23684 = v_23634;
// end of prologue
    v_23685 = v_23684;
    if (!consp(v_23685)) goto v_23643;
    else goto v_23644;
v_23643:
    v_23685 = lisp_true;
    goto v_23642;
v_23644:
    v_23685 = v_23684;
    v_23685 = qcar(v_23685);
    v_23685 = (consp(v_23685) ? nil : lisp_true);
    goto v_23642;
    v_23685 = nil;
v_23642:
    if (v_23685 == nil) goto v_23640;
    v_23683 = lisp_true;
    goto v_23638;
v_23640:
    v_23685 = v_23683;
    if (!consp(v_23685)) goto v_23657;
    else goto v_23658;
v_23657:
    v_23685 = lisp_true;
    goto v_23656;
v_23658:
    v_23685 = v_23683;
    v_23685 = qcar(v_23685);
    v_23685 = (consp(v_23685) ? nil : lisp_true);
    goto v_23656;
    v_23685 = nil;
v_23656:
    if (v_23685 == nil) goto v_23654;
    v_23683 = nil;
    goto v_23638;
v_23654:
    goto v_23674;
v_23670:
    v_23684 = qcar(v_23684);
    v_23684 = qcar(v_23684);
    v_23684 = qcdr(v_23684);
    goto v_23671;
v_23672:
    v_23683 = qcar(v_23683);
    v_23683 = qcar(v_23683);
    v_23683 = qcdr(v_23683);
    goto v_23673;
v_23674:
    goto v_23670;
v_23671:
    goto v_23672;
v_23673:
        return Llessp(nil, v_23684, v_23683);
    v_23683 = nil;
v_23638:
    return onevalue(v_23683);
}



// Code for vectorrd

static LispObject CC_vectorrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23662, v_23663, v_23664;
    LispObject fn;
    argcheck(nargs, 0, "vectorrd");
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
    goto v_23645;
v_23641:
    v_23663 = qvalue(elt(env, 2)); // atts
    goto v_23642;
v_23643:
    v_23662 = elt(env, 3); // (type other)
    goto v_23644;
v_23645:
    goto v_23641;
v_23642:
    goto v_23643;
v_23644:
    fn = elt(env, 5); // retattributes
    v_23662 = (*qfn2(fn))(fn, v_23663, v_23662);
    env = stack[-1];
    stack[0] = v_23662;
    fn = elt(env, 6); // matrixrowrd
    v_23662 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_23663 = v_23662;
    goto v_23657;
v_23651:
    v_23664 = elt(env, 4); // vectorml
    goto v_23652;
v_23653:
    v_23662 = stack[0];
    goto v_23654;
v_23655:
    goto v_23656;
v_23657:
    goto v_23651;
v_23652:
    goto v_23653;
v_23654:
    goto v_23655;
v_23656:
    return list2star(v_23664, v_23662, v_23663);
    return onevalue(v_23662);
}



// Code for compl

static LispObject CC_compl(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23674, v_23675, v_23676;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23634,v_23635);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_23635;
    stack[-1] = v_23634;
// end of prologue
    v_23676 = nil;
v_23640:
    v_23674 = stack[-1];
    if (v_23674 == nil) goto v_23643;
    else goto v_23644;
v_23643:
    v_23674 = v_23676;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_23674);
    }
v_23644:
    goto v_23654;
v_23650:
    v_23674 = stack[-1];
    v_23675 = qcar(v_23674);
    goto v_23651;
v_23652:
    v_23674 = stack[0];
    goto v_23653;
v_23654:
    goto v_23650;
v_23651:
    goto v_23652;
v_23653:
    v_23674 = Lmember(nil, v_23675, v_23674);
    if (v_23674 == nil) goto v_23649;
    v_23674 = stack[-1];
    v_23674 = qcdr(v_23674);
    stack[-1] = v_23674;
    goto v_23640;
v_23649:
    goto v_23668;
v_23664:
    v_23674 = stack[-1];
    v_23674 = qcar(v_23674);
    goto v_23665;
v_23666:
    v_23675 = v_23676;
    goto v_23667;
v_23668:
    goto v_23664;
v_23665:
    goto v_23666;
v_23667:
    v_23674 = cons(v_23674, v_23675);
    env = stack[-2];
    v_23676 = v_23674;
    v_23674 = stack[-1];
    v_23674 = qcdr(v_23674);
    stack[-1] = v_23674;
    goto v_23640;
    v_23674 = nil;
    return onevalue(v_23674);
}



// Code for simpimpart

static LispObject CC_simpimpart(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23642, v_23643;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_23643 = v_23634;
// end of prologue
    v_23642 = nil;
// Binding !*factor
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_23642; // !*factor
    v_23642 = v_23643;
    v_23642 = qcar(v_23642);
    fn = elt(env, 2); // simp!*
    v_23642 = (*qfn1(fn))(fn, v_23642);
    env = stack[-1];
    fn = elt(env, 3); // impartsq
    v_23642 = (*qfn1(fn))(fn, v_23642);
    ;}  // end of a binding scope
    return onevalue(v_23642);
}



// Code for suspend

static LispObject CC_suspend(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23694, v_23695, v_23696, v_23697;
    LispObject fn;
    LispObject v_23641, v_23640, v_23639, v_23638, v_23637;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "suspend");
    va_start(aa, nargs);
    v_23637 = va_arg(aa, LispObject);
    v_23638 = va_arg(aa, LispObject);
    v_23639 = va_arg(aa, LispObject);
    v_23640 = va_arg(aa, LispObject);
    v_23641 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_23641,v_23640,v_23639,v_23638,v_23637);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_23637,v_23638,v_23639,v_23640,v_23641);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_23641;
    v_23695 = v_23640;
    v_23696 = v_23639;
    v_23697 = v_23638;
    v_23694 = v_23637;
// end of prologue
// Binding op
// FLUIDBIND: reloadenv=9 litvec-offset=1 saveloc=8
{   bind_fluid_stack bind_fluid_var(-9, 1, -8);
// Binding r
// FLUIDBIND: reloadenv=9 litvec-offset=2 saveloc=6
{   bind_fluid_stack bind_fluid_var(-9, 2, -6);
// Binding p
// FLUIDBIND: reloadenv=9 litvec-offset=3 saveloc=5
{   bind_fluid_stack bind_fluid_var(-9, 3, -5);
    qvalue(elt(env, 1)) = v_23694; // op
    v_23694 = v_23697;
    qvalue(elt(env, 2)) = v_23694; // r
    v_23694 = v_23696;
    qvalue(elt(env, 3)) = v_23694; // p
    goto v_23660;
v_23652:
    v_23694 = qvalue(elt(env, 2)); // r
    stack[-4] = qcar(v_23694);
    goto v_23653;
v_23654:
    v_23694 = qvalue(elt(env, 3)); // p
    stack[-3] = qcar(v_23694);
    goto v_23655;
v_23656:
    stack[-2] = v_23695;
    goto v_23657;
v_23658:
    goto v_23671;
v_23667:
    goto v_23679;
v_23673:
    stack[-1] = qvalue(elt(env, 1)); // op
    goto v_23674;
v_23675:
    v_23694 = qvalue(elt(env, 2)); // r
    stack[0] = qcdr(v_23694);
    goto v_23676;
v_23677:
    goto v_23689;
v_23685:
    v_23695 = qvalue(elt(env, 1)); // op
    goto v_23686;
v_23687:
    v_23694 = qvalue(elt(env, 3)); // p
    v_23694 = qcdr(v_23694);
    goto v_23688;
v_23689:
    goto v_23685;
v_23686:
    goto v_23687;
v_23688:
    v_23694 = cons(v_23695, v_23694);
    env = stack[-9];
    v_23694 = ncons(v_23694);
    env = stack[-9];
    goto v_23678;
v_23679:
    goto v_23673;
v_23674:
    goto v_23675;
v_23676:
    goto v_23677;
v_23678:
    v_23695 = acons(stack[-1], stack[0], v_23694);
    env = stack[-9];
    goto v_23668;
v_23669:
    v_23694 = stack[-7];
    goto v_23670;
v_23671:
    goto v_23667;
v_23668:
    goto v_23669;
v_23670:
    v_23694 = cons(v_23695, v_23694);
    env = stack[-9];
    goto v_23659;
v_23660:
    goto v_23652;
v_23653:
    goto v_23654;
v_23655:
    goto v_23656;
v_23657:
    goto v_23658;
v_23659:
    fn = elt(env, 4); // amatch
    v_23694 = (*qfnn(fn))(fn, 4, stack[-4], stack[-3], stack[-2], v_23694);
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_23694);
}



// Code for sc_columnscalarproduct

static LispObject CC_sc_columnscalarproduct(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23701, v_23702, v_23703;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23634,v_23635);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_23635;
    stack[-3] = v_23634;
// end of prologue
    v_23701 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 2); // sc_simp
    v_23701 = (*qfn1(fn))(fn, v_23701);
    env = stack[-5];
    stack[0] = v_23701;
    v_23701 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_23701;
v_23646:
    goto v_23658;
v_23654:
    v_23701 = stack[-3];
    fn = elt(env, 3); // fast!-row!-dim
    v_23702 = (*qfn1(fn))(fn, v_23701);
    env = stack[-5];
    goto v_23655;
v_23656:
    v_23701 = stack[-4];
    goto v_23657;
v_23658:
    goto v_23654;
v_23655:
    goto v_23656;
v_23657:
    v_23701 = difference2(v_23702, v_23701);
    env = stack[-5];
    v_23701 = Lminusp(nil, v_23701);
    env = stack[-5];
    if (v_23701 == nil) goto v_23651;
    goto v_23645;
v_23651:
    goto v_23668;
v_23664:
    stack[-1] = stack[0];
    goto v_23665;
v_23666:
    goto v_23675;
v_23671:
    goto v_23683;
v_23677:
    v_23703 = stack[-3];
    goto v_23678;
v_23679:
    v_23702 = stack[-4];
    goto v_23680;
v_23681:
    v_23701 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23682;
v_23683:
    goto v_23677;
v_23678:
    goto v_23679;
v_23680:
    goto v_23681;
v_23682:
    fn = elt(env, 4); // sc_getmat
    stack[0] = (*qfnn(fn))(fn, 3, v_23703, v_23702, v_23701);
    env = stack[-5];
    goto v_23672;
v_23673:
    goto v_23694;
v_23688:
    v_23703 = stack[-2];
    goto v_23689;
v_23690:
    v_23702 = stack[-4];
    goto v_23691;
v_23692:
    v_23701 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23693;
v_23694:
    goto v_23688;
v_23689:
    goto v_23690;
v_23691:
    goto v_23692;
v_23693:
    fn = elt(env, 4); // sc_getmat
    v_23701 = (*qfnn(fn))(fn, 3, v_23703, v_23702, v_23701);
    env = stack[-5];
    goto v_23674;
v_23675:
    goto v_23671;
v_23672:
    goto v_23673;
v_23674:
    fn = elt(env, 5); // sc_multsq
    v_23701 = (*qfn2(fn))(fn, stack[0], v_23701);
    env = stack[-5];
    goto v_23667;
v_23668:
    goto v_23664;
v_23665:
    goto v_23666;
v_23667:
    fn = elt(env, 6); // sc_addsq
    v_23701 = (*qfn2(fn))(fn, stack[-1], v_23701);
    env = stack[-5];
    stack[0] = v_23701;
    v_23701 = stack[-4];
    v_23701 = add1(v_23701);
    env = stack[-5];
    stack[-4] = v_23701;
    goto v_23646;
v_23645:
    v_23701 = stack[0];
    return onevalue(v_23701);
}



// Code for a2bc

static LispObject CC_a2bc(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23673, v_23674;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_23673 = v_23634;
// end of prologue
    v_23674 = qvalue(elt(env, 1)); // !*grmod!*
    if (v_23674 == nil) goto v_23639;
    v_23674 = v_23673;
    if (!consp(v_23674)) goto v_23647;
    else goto v_23648;
v_23647:
    v_23674 = lisp_true;
    goto v_23646;
v_23648:
    v_23674 = v_23673;
    v_23674 = qcar(v_23674);
    v_23674 = (consp(v_23674) ? nil : lisp_true);
    goto v_23646;
    v_23674 = nil;
v_23646:
    if (v_23674 == nil) goto v_23643;
    else goto v_23644;
v_23643:
    goto v_23662;
v_23658:
    v_23674 = elt(env, 2); // " Invalid coefficient "
    goto v_23659;
v_23660:
    goto v_23661;
v_23662:
    goto v_23658;
v_23659:
    goto v_23660;
v_23661:
    v_23673 = list2(v_23674, v_23673);
    env = stack[0];
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_23673);
    }
v_23644:
    {
        fn = elt(env, 4); // bcfd
        return (*qfn1(fn))(fn, v_23673);
    }
    v_23673 = nil;
    goto v_23637;
v_23639:
    {
        fn = elt(env, 5); // simp!*
        return (*qfn1(fn))(fn, v_23673);
    }
    v_23673 = nil;
v_23637:
    return onevalue(v_23673);
}



// Code for simpwedge

static LispObject CC_simpwedge(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23639;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_23639 = v_23634;
// end of prologue
    fn = elt(env, 1); // partitwedge
    v_23639 = (*qfn1(fn))(fn, v_23639);
    env = stack[0];
    {
        fn = elt(env, 2); // !*pf2sq
        return (*qfn1(fn))(fn, v_23639);
    }
}



// Code for replace2_parents

static LispObject CC_replace2_parents(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23678, v_23679;
    LispObject v_23636, v_23635, v_23634;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "replace2_parents");
    va_start(aa, nargs);
    v_23634 = va_arg(aa, LispObject);
    v_23635 = va_arg(aa, LispObject);
    v_23636 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_23636,v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_23634,v_23635,v_23636);
    }
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_23636;
    stack[-1] = v_23635;
    stack[-2] = v_23634;
// end of prologue
    goto v_23646;
v_23642:
    v_23679 = stack[-2];
    goto v_23643;
v_23644:
    v_23678 = stack[0];
    v_23678 = qcar(v_23678);
    goto v_23645;
v_23646:
    goto v_23642;
v_23643:
    goto v_23644;
v_23645:
    if (equal(v_23679, v_23678)) goto v_23640;
    else goto v_23641;
v_23640:
    goto v_23655;
v_23651:
    v_23679 = stack[0];
    goto v_23652;
v_23653:
    v_23678 = stack[-1];
    goto v_23654;
v_23655:
    goto v_23651;
v_23652:
    goto v_23653;
v_23654:
    v_23678 = Lrplaca(nil, v_23679, v_23678);
    goto v_23639;
v_23641:
v_23639:
    goto v_23666;
v_23662:
    v_23679 = stack[-2];
    goto v_23663;
v_23664:
    v_23678 = stack[0];
    v_23678 = qcdr(v_23678);
    goto v_23665;
v_23666:
    goto v_23662;
v_23663:
    goto v_23664;
v_23665:
    if (equal(v_23679, v_23678)) goto v_23660;
    else goto v_23661;
v_23660:
    goto v_23675;
v_23671:
    v_23679 = stack[0];
    goto v_23672;
v_23673:
    v_23678 = stack[-1];
    goto v_23674;
v_23675:
    goto v_23671;
v_23672:
    goto v_23673;
v_23674:
        return Lrplacd(nil, v_23679, v_23678);
v_23661:
    v_23678 = nil;
    return onevalue(v_23678);
}



// Code for fs!:minusp!:

static LispObject CC_fsTminuspT(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23639;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23639 = v_23634;
// end of prologue
    v_23639 = qcdr(v_23639);
    {
        fn = elt(env, 1); // fs!:minusp
        return (*qfn1(fn))(fn, v_23639);
    }
}



// Code for pst_subpst

static LispObject CC_pst_subpst(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23647, v_23648;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23634,v_23635);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_23648 = v_23635;
    v_23647 = v_23634;
// end of prologue
    goto v_23641;
v_23637:
    stack[0] = qcdr(v_23647);
    goto v_23638;
v_23639:
    v_23647 = v_23648;
    v_23647 = sub1(v_23647);
    goto v_23640;
v_23641:
    goto v_23637;
v_23638:
    goto v_23639;
v_23640:
    v_23647 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_23647-TAG_FIXNUM)/(16/CELL)));
    return onevalue(v_23647);
}



// Code for !*n2a

static LispObject CC_Hn2a(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23647, v_23648;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23648 = v_23634;
// end of prologue
    v_23647 = v_23648;
    v_23647 = integerp(v_23647);
    if (v_23647 == nil) goto v_23639;
    v_23647 = v_23648;
    goto v_23637;
v_23639:
    v_23647 = v_23648;
    {
        fn = elt(env, 1); // !*q2a
        return (*qfn1(fn))(fn, v_23647);
    }
    v_23647 = nil;
v_23637:
    return onevalue(v_23647);
}



// Code for read!-comment1

static LispObject CC_readKcomment1(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23687, v_23688;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_23687 = v_23634;
// end of prologue
// Binding !*lower
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 1, -1);
    qvalue(elt(env, 1)) = nil; // !*lower
// Binding !*raise
// FLUIDBIND: reloadenv=2 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-2, 2, 0);
    qvalue(elt(env, 2)) = nil; // !*raise
    v_23687 = nil;
    qvalue(elt(env, 4)) = v_23687; // named!-character!*
v_23640:
    v_23687 = qvalue(elt(env, 4)); // named!-character!*
    if (v_23687 == nil) goto v_23647;
    else goto v_23645;
v_23647:
    goto v_23658;
v_23654:
    v_23687 = qvalue(elt(env, 5)); // crchar!*
    fn = elt(env, 8); // id2string
    v_23687 = (*qfn1(fn))(fn, v_23687);
    env = stack[-2];
    fn = elt(env, 9); // string!-length
    v_23688 = (*qfn1(fn))(fn, v_23687);
    env = stack[-2];
    goto v_23655;
v_23656:
    v_23687 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23657;
v_23658:
    goto v_23654;
v_23655:
    goto v_23656;
v_23657:
    if (v_23688 == v_23687) goto v_23653;
    v_23687 = lisp_true;
    goto v_23651;
v_23653:
    v_23687 = qvalue(elt(env, 5)); // crchar!*
    fn = elt(env, 10); // delcp
    v_23687 = (*qfn1(fn))(fn, v_23687);
    env = stack[-2];
    if (v_23687 == nil) goto v_23668;
    else goto v_23669;
v_23668:
    v_23687 = lisp_true;
    goto v_23667;
v_23669:
    goto v_23679;
v_23675:
    v_23688 = qvalue(elt(env, 5)); // crchar!*
    goto v_23676;
v_23677:
    v_23687 = qvalue(elt(env, 6)); // !$eol!$
    goto v_23678;
v_23679:
    goto v_23675;
v_23676:
    goto v_23677;
v_23678:
    v_23687 = (v_23688 == v_23687 ? lisp_true : nil);
    goto v_23667;
    v_23687 = nil;
v_23667:
    goto v_23651;
    v_23687 = nil;
v_23651:
    if (v_23687 == nil) goto v_23649;
    else goto v_23645;
v_23649:
    goto v_23646;
v_23645:
    v_23687 = nil;
    qvalue(elt(env, 4)) = v_23687; // named!-character!*
    fn = elt(env, 11); // readch1
    v_23687 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    qvalue(elt(env, 5)) = v_23687; // crchar!*
    goto v_23640;
v_23646:
    v_23687 = elt(env, 7); // ! 
    qvalue(elt(env, 5)) = v_23687; // crchar!*
    fn = elt(env, 12); // condterpri
    v_23687 = (*qfnn(fn))(fn, 0);
    v_23687 = nil;
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_23687);
}



// Code for ra_intequiv

static LispObject CC_ra_intequiv(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23645;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_23645 = v_23634;
// end of prologue
    goto v_23641;
v_23637:
    stack[0] = elt(env, 1); // ra_intequiv0
    goto v_23638;
v_23639:
    v_23645 = ncons(v_23645);
    env = stack[-1];
    goto v_23640;
v_23641:
    goto v_23637;
v_23638:
    goto v_23639;
v_23640:
    {
        LispObject v_23647 = stack[0];
        fn = elt(env, 2); // ra_wrapper
        return (*qfn2(fn))(fn, v_23647, v_23645);
    }
}



// Code for lalr_collect_nonterminals

static LispObject CC_lalr_collect_nonterminals(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23681;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_23681 = v_23634;
// end of prologue
    stack[-3] = v_23681;
    v_23681 = stack[-3];
    if (v_23681 == nil) goto v_23646;
    else goto v_23647;
v_23646:
    v_23681 = nil;
    goto v_23641;
v_23647:
    v_23681 = stack[-3];
    v_23681 = qcar(v_23681);
    v_23681 = qcar(v_23681);
    v_23681 = Lintern(nil, v_23681);
    env = stack[-4];
    v_23681 = ncons(v_23681);
    env = stack[-4];
    stack[-1] = v_23681;
    stack[-2] = v_23681;
v_23642:
    v_23681 = stack[-3];
    v_23681 = qcdr(v_23681);
    stack[-3] = v_23681;
    v_23681 = stack[-3];
    if (v_23681 == nil) goto v_23661;
    else goto v_23662;
v_23661:
    v_23681 = stack[-2];
    goto v_23641;
v_23662:
    goto v_23670;
v_23666:
    stack[0] = stack[-1];
    goto v_23667;
v_23668:
    v_23681 = stack[-3];
    v_23681 = qcar(v_23681);
    v_23681 = qcar(v_23681);
    v_23681 = Lintern(nil, v_23681);
    env = stack[-4];
    v_23681 = ncons(v_23681);
    env = stack[-4];
    goto v_23669;
v_23670:
    goto v_23666;
v_23667:
    goto v_23668;
v_23669:
    v_23681 = Lrplacd(nil, stack[0], v_23681);
    env = stack[-4];
    v_23681 = stack[-1];
    v_23681 = qcdr(v_23681);
    stack[-1] = v_23681;
    goto v_23642;
v_23641:
    {
        fn = elt(env, 1); // lalr_remove_duplicates
        return (*qfn1(fn))(fn, v_23681);
    }
}



// Code for maxfrom

static LispObject CC_maxfrom(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23649, v_23650;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23634,v_23635);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_23649 = v_23635;
    v_23650 = v_23634;
// end of prologue
    goto v_23644;
v_23638:
    stack[0] = v_23650;
    goto v_23639;
v_23640:
    v_23650 = add1(v_23649);
    env = stack[-1];
    goto v_23641;
v_23642:
    v_23649 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23643;
v_23644:
    goto v_23638;
v_23639:
    goto v_23640;
v_23641:
    goto v_23642;
v_23643:
    {
        LispObject v_23652 = stack[0];
        fn = elt(env, 1); // maxfrom1
        return (*qfnn(fn))(fn, 3, v_23652, v_23650, v_23649);
    }
}



// Code for rl_mk!*fof

static LispObject CC_rl_mkHfof(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23639;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_23639 = v_23634;
// end of prologue
    fn = elt(env, 1); // rl_csimpl
    v_23639 = (*qfn1(fn))(fn, v_23639);
    env = stack[0];
    {
        fn = elt(env, 2); // rl_mk!*fof1
        return (*qfn1(fn))(fn, v_23639);
    }
}



// Code for repr_ldeg

static LispObject CC_repr_ldeg(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23642;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23642 = v_23634;
// end of prologue
    v_23642 = qcdr(v_23642);
    v_23642 = qcdr(v_23642);
    v_23642 = qcdr(v_23642);
    v_23642 = qcdr(v_23642);
    v_23642 = qcar(v_23642);
    return onevalue(v_23642);
}



// Code for rl_multsurep

static LispObject CC_rl_multsurep(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23652, v_23653;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23634,v_23635);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_23652 = v_23635;
    v_23653 = v_23634;
// end of prologue
    goto v_23642;
v_23638:
    stack[0] = qvalue(elt(env, 1)); // rl_multsurep!*
    goto v_23639;
v_23640:
    goto v_23649;
v_23645:
    goto v_23646;
v_23647:
    goto v_23648;
v_23649:
    goto v_23645;
v_23646:
    goto v_23647;
v_23648:
    v_23652 = list2(v_23653, v_23652);
    env = stack[-1];
    goto v_23641;
v_23642:
    goto v_23638;
v_23639:
    goto v_23640;
v_23641:
    {
        LispObject v_23655 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_23655, v_23652);
    }
}



// Code for lowupperlimitrd

static LispObject CC_lowupperlimitrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23676, v_23677;
    LispObject fn;
    argcheck(nargs, 0, "lowupperlimitrd");
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
    stack[-2] = nil;
    fn = elt(env, 6); // mathml
    v_23676 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[0] = v_23676;
    fn = elt(env, 7); // lex
    v_23676 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_23650;
v_23646:
    v_23677 = qvalue(elt(env, 2)); // char
    goto v_23647;
v_23648:
    v_23676 = elt(env, 3); // (!/ l o w l i m i t)
    goto v_23649;
v_23650:
    goto v_23646;
v_23647:
    goto v_23648;
v_23649:
    if (equal(v_23677, v_23676)) goto v_23644;
    else goto v_23645;
v_23644:
    fn = elt(env, 8); // upperlimitrd
    v_23676 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-2] = v_23676;
    goto v_23643;
v_23645:
    goto v_23661;
v_23657:
    v_23677 = elt(env, 4); // "</lowlimit>"
    goto v_23658;
v_23659:
    v_23676 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_23660;
v_23661:
    goto v_23657;
v_23658:
    goto v_23659;
v_23660:
    fn = elt(env, 9); // errorml
    v_23676 = (*qfn2(fn))(fn, v_23677, v_23676);
    env = stack[-3];
    goto v_23643;
v_23643:
    goto v_23671;
v_23665:
    stack[-1] = elt(env, 5); // lowupperlimit
    goto v_23666;
v_23667:
    goto v_23668;
v_23669:
    v_23676 = stack[-2];
    v_23676 = ncons(v_23676);
    goto v_23670;
v_23671:
    goto v_23665;
v_23666:
    goto v_23667;
v_23668:
    goto v_23669;
v_23670:
    {
        LispObject v_23681 = stack[-1];
        LispObject v_23682 = stack[0];
        return list2star(v_23681, v_23682, v_23676);
    }
    return onevalue(v_23676);
}



// Code for prlist

static LispObject CC_prlist(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23667, v_23668;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_23634;
// end of prologue
    v_23668 = nil;
v_23639:
    v_23667 = stack[0];
    if (v_23667 == nil) goto v_23642;
    else goto v_23643;
v_23642:
    v_23667 = v_23668;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_23667);
    }
v_23643:
    v_23667 = stack[0];
    v_23667 = qcar(v_23667);
    v_23667 = Lconsp(nil, v_23667);
    env = stack[-1];
    if (v_23667 == nil) goto v_23648;
    goto v_23657;
v_23653:
    v_23667 = stack[0];
    v_23667 = qcar(v_23667);
    goto v_23654;
v_23655:
    goto v_23656;
v_23657:
    goto v_23653;
v_23654:
    goto v_23655;
v_23656:
    v_23667 = cons(v_23667, v_23668);
    env = stack[-1];
    v_23668 = v_23667;
    v_23667 = stack[0];
    v_23667 = qcdr(v_23667);
    stack[0] = v_23667;
    goto v_23639;
v_23648:
    v_23667 = stack[0];
    v_23667 = qcdr(v_23667);
    stack[0] = v_23667;
    goto v_23639;
    v_23667 = nil;
    return onevalue(v_23667);
}



// Code for assgnpri

static LispObject CC_assgnpri(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23909, v_23910, v_23911;
    LispObject fn;
    LispObject v_23636, v_23635, v_23634;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "assgnpri");
    va_start(aa, nargs);
    v_23634 = va_arg(aa, LispObject);
    v_23635 = va_arg(aa, LispObject);
    v_23636 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_23636,v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_23634,v_23635,v_23636);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_23636;
    stack[-2] = v_23635;
    stack[-3] = v_23634;
// end of prologue
    stack[-4] = nil;
    v_23909 = nil;
    qvalue(elt(env, 2)) = v_23909; // overflowed!*
    qvalue(elt(env, 3)) = v_23909; // testing!-width!*
    v_23909 = stack[-3];
    if (v_23909 == nil) goto v_23646;
    else goto v_23647;
v_23646:
    v_23909 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_23909;
    goto v_23645;
v_23647:
v_23645:
    v_23909 = qvalue(elt(env, 4)); // !*nero
    if (v_23909 == nil) goto v_23653;
    goto v_23661;
v_23657:
    v_23910 = stack[-3];
    goto v_23658;
v_23659:
    v_23909 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23660;
v_23661:
    goto v_23657;
v_23658:
    goto v_23659;
v_23660:
    if (v_23910 == v_23909) goto v_23656;
    else goto v_23653;
v_23656:
    v_23909 = nil;
    goto v_23641;
v_23653:
    v_23909 = qvalue(elt(env, 5)); // !*tex
    if (v_23909 == nil) goto v_23668;
    goto v_23677;
v_23671:
    v_23911 = stack[-3];
    goto v_23672;
v_23673:
    v_23910 = stack[-2];
    goto v_23674;
v_23675:
    v_23909 = stack[-1];
    goto v_23676;
v_23677:
    goto v_23671;
v_23672:
    goto v_23673;
v_23674:
    goto v_23675;
v_23676:
    {
        fn = elt(env, 21); // texpri
        return (*qfnn(fn))(fn, 3, v_23911, v_23910, v_23909);
    }
v_23668:
    v_23909 = elt(env, 6); // vecp
    fn = elt(env, 22); // getd
    v_23909 = (*qfn1(fn))(fn, v_23909);
    env = stack[-5];
    if (v_23909 == nil) goto v_23682;
    v_23909 = stack[-3];
    fn = elt(env, 6); // vecp
    v_23909 = (*qfn1(fn))(fn, v_23909);
    env = stack[-5];
    if (v_23909 == nil) goto v_23682;
    goto v_23694;
v_23690:
    v_23910 = stack[-3];
    goto v_23691;
v_23692:
    v_23909 = elt(env, 7); // mat
    goto v_23693;
v_23694:
    goto v_23690;
v_23691:
    goto v_23692;
v_23693:
    {
        fn = elt(env, 23); // vecpri
        return (*qfn2(fn))(fn, v_23910, v_23909);
    }
v_23682:
    goto v_23706;
v_23702:
    v_23910 = elt(env, 8); // csl
    goto v_23703;
v_23704:
    v_23909 = qvalue(elt(env, 9)); // lispsystem!*
    goto v_23705;
v_23706:
    goto v_23702;
v_23703:
    goto v_23704;
v_23705:
    v_23909 = Lmemq(nil, v_23910, v_23909);
    if (v_23909 == nil) goto v_23700;
    v_23909 = elt(env, 10); // math!-display
    fn = elt(env, 22); // getd
    v_23909 = (*qfn1(fn))(fn, v_23909);
    env = stack[-5];
    if (v_23909 == nil) goto v_23700;
    v_23909 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 10); // math!-display
    v_23909 = (*qfn1(fn))(fn, v_23909);
    env = stack[-5];
    if (v_23909 == nil) goto v_23700;
    goto v_23727;
v_23723:
    v_23910 = qvalue(elt(env, 11)); // outputhandler!*
    goto v_23724;
v_23725:
    v_23909 = elt(env, 12); // fancy!-output
    goto v_23726;
v_23727:
    goto v_23723;
v_23724:
    goto v_23725;
v_23726:
    if (v_23910 == v_23909) goto v_23721;
    else goto v_23722;
v_23721:
    v_23909 = stack[-3];
    fn = elt(env, 24); // would!-be!-huge
    v_23909 = (*qfn1(fn))(fn, v_23909);
    env = stack[-5];
    goto v_23720;
v_23722:
    v_23909 = nil;
    goto v_23720;
    v_23909 = nil;
v_23720:
    if (v_23909 == nil) goto v_23700;
    v_23909 = nil;
    fn = elt(env, 25); // fmp!-switch
    v_23909 = (*qfn1(fn))(fn, v_23909);
    env = stack[-5];
    v_23909 = lisp_true;
    stack[-4] = v_23909;
    goto v_23698;
v_23700:
v_23698:
    v_23909 = stack[-3];
    fn = elt(env, 26); // getrtype
    v_23909 = (*qfn1(fn))(fn, v_23909);
    env = stack[-5];
    v_23911 = v_23909;
    if (v_23909 == nil) goto v_23741;
    goto v_23755;
v_23751:
    v_23910 = v_23911;
    goto v_23752;
v_23753:
    v_23909 = elt(env, 13); // sprifn
    goto v_23754;
v_23755:
    goto v_23751;
v_23752:
    goto v_23753;
v_23754:
    v_23909 = Lflagp(nil, v_23910, v_23909);
    env = stack[-5];
    if (v_23909 == nil) goto v_23749;
    v_23909 = qvalue(elt(env, 11)); // outputhandler!*
    v_23909 = (v_23909 == nil ? lisp_true : nil);
    goto v_23747;
v_23749:
    v_23909 = nil;
    goto v_23747;
    v_23909 = nil;
v_23747:
    if (v_23909 == nil) goto v_23741;
    v_23909 = stack[-2];
    if (v_23909 == nil) goto v_23765;
    else goto v_23766;
v_23765:
    goto v_23773;
v_23769:
    goto v_23780;
v_23776:
    v_23910 = v_23911;
    goto v_23777;
v_23778:
    v_23909 = elt(env, 14); // tag
    goto v_23779;
v_23780:
    goto v_23776;
v_23777:
    goto v_23778;
v_23779:
    v_23909 = get(v_23910, v_23909);
    env = stack[-5];
    if (!symbolp(v_23909)) v_23910 = nil;
    else { v_23910 = qfastgets(v_23909);
           if (v_23910 != nil) { v_23910 = elt(v_23910, 57); // prifn
#ifdef RECORD_GET
             if (v_23910 != SPID_NOPROP)
                record_get(elt(fastget_names, 57), 1);
             else record_get(elt(fastget_names, 57), 0),
                v_23910 = nil; }
           else record_get(elt(fastget_names, 57), 0); }
#else
             if (v_23910 == SPID_NOPROP) v_23910 = nil; }}
#endif
    goto v_23770;
v_23771:
    v_23909 = stack[-3];
    goto v_23772;
v_23773:
    goto v_23769;
v_23770:
    goto v_23771;
v_23772:
    v_23909 = Lapply1(nil, v_23910, v_23909);
    env = stack[-5];
    goto v_23764;
v_23766:
    goto v_23794;
v_23788:
    v_23911 = elt(env, 15); // setq
    goto v_23789;
v_23790:
    v_23909 = stack[-2];
    v_23910 = qcar(v_23909);
    goto v_23791;
v_23792:
    v_23909 = stack[-3];
    goto v_23793;
v_23794:
    goto v_23788;
v_23789:
    goto v_23790;
v_23791:
    goto v_23792;
v_23793:
    v_23909 = list3(v_23911, v_23910, v_23909);
    env = stack[-5];
    fn = elt(env, 27); // maprin
    v_23909 = (*qfn1(fn))(fn, v_23909);
    env = stack[-5];
    goto v_23764;
v_23764:
    goto v_23739;
v_23741:
    goto v_23809;
v_23805:
    v_23910 = stack[-1];
    goto v_23806;
v_23807:
    v_23909 = elt(env, 16); // (first only)
    goto v_23808;
v_23809:
    goto v_23805;
v_23806:
    goto v_23807;
v_23808:
    v_23909 = Lmemq(nil, v_23910, v_23909);
    if (v_23909 == nil) goto v_23804;
    v_23909 = lisp_true;
    fn = elt(env, 28); // terpri!*
    v_23909 = (*qfn1(fn))(fn, v_23909);
    env = stack[-5];
    goto v_23802;
v_23804:
v_23802:
    v_23909 = stack[-2];
    fn = elt(env, 29); // evalvars
    v_23909 = (*qfn1(fn))(fn, v_23909);
    env = stack[-5];
    stack[-2] = v_23909;
    v_23909 = qvalue(elt(env, 17)); // !*fort
    if (v_23909 == nil) goto v_23820;
    goto v_23829;
v_23823:
    v_23911 = stack[-3];
    goto v_23824;
v_23825:
    v_23910 = stack[-2];
    goto v_23826;
v_23827:
    v_23909 = stack[-1];
    goto v_23828;
v_23829:
    goto v_23823;
v_23824:
    goto v_23825;
v_23826:
    goto v_23827;
v_23828:
    fn = elt(env, 30); // fvarpri
    v_23909 = (*qfnn(fn))(fn, 3, v_23911, v_23910, v_23909);
    env = stack[-5];
    v_23909 = stack[-4];
    if (v_23909 == nil) goto v_23836;
    v_23909 = lisp_true;
    fn = elt(env, 25); // fmp!-switch
    v_23909 = (*qfn1(fn))(fn, v_23909);
    goto v_23834;
v_23836:
v_23834:
    v_23909 = nil;
    goto v_23641;
v_23820:
    v_23909 = stack[-2];
    if (v_23909 == nil) goto v_23845;
    goto v_23852;
v_23848:
    stack[0] = elt(env, 15); // setq
    goto v_23849;
v_23850:
    goto v_23859;
v_23855:
    v_23910 = stack[-2];
    goto v_23856;
v_23857:
    v_23909 = stack[-3];
    goto v_23858;
v_23859:
    goto v_23855;
v_23856:
    goto v_23857;
v_23858:
    fn = elt(env, 31); // aconc
    v_23909 = (*qfn2(fn))(fn, v_23910, v_23909);
    env = stack[-5];
    goto v_23851;
v_23852:
    goto v_23848;
v_23849:
    goto v_23850;
v_23851:
    v_23909 = cons(stack[0], v_23909);
    env = stack[-5];
    goto v_23843;
v_23845:
    v_23909 = stack[-3];
    goto v_23843;
    v_23909 = nil;
v_23843:
    fn = elt(env, 27); // maprin
    v_23909 = (*qfn1(fn))(fn, v_23909);
    env = stack[-5];
    v_23909 = stack[-1];
    if (v_23909 == nil) goto v_23871;
    else goto v_23872;
v_23871:
    v_23909 = lisp_true;
    goto v_23870;
v_23872:
    goto v_23881;
v_23877:
    v_23910 = stack[-1];
    goto v_23878;
v_23879:
    v_23909 = elt(env, 18); // first
    goto v_23880;
v_23881:
    goto v_23877;
v_23878:
    goto v_23879;
v_23880:
    v_23909 = (v_23910 == v_23909 ? lisp_true : nil);
    goto v_23870;
    v_23909 = nil;
v_23870:
    if (v_23909 == nil) goto v_23868;
    v_23909 = stack[-4];
    if (v_23909 == nil) goto v_23888;
    v_23909 = lisp_true;
    fn = elt(env, 25); // fmp!-switch
    v_23909 = (*qfn1(fn))(fn, v_23909);
    goto v_23886;
v_23888:
v_23886:
    v_23909 = nil;
    goto v_23641;
v_23868:
    v_23909 = qvalue(elt(env, 19)); // !*nat
    if (v_23909 == nil) goto v_23893;
    else goto v_23894;
v_23893:
    v_23909 = elt(env, 20); // "$"
    fn = elt(env, 32); // prin2!*
    v_23909 = (*qfn1(fn))(fn, v_23909);
    env = stack[-5];
    goto v_23866;
v_23894:
v_23866:
    v_23909 = qvalue(elt(env, 19)); // !*nat
    v_23909 = (v_23909 == nil ? lisp_true : nil);
    fn = elt(env, 28); // terpri!*
    v_23909 = (*qfn1(fn))(fn, v_23909);
    env = stack[-5];
    goto v_23739;
v_23739:
    v_23909 = stack[-4];
    if (v_23909 == nil) goto v_23904;
    v_23909 = lisp_true;
    fn = elt(env, 25); // fmp!-switch
    v_23909 = (*qfn1(fn))(fn, v_23909);
    goto v_23902;
v_23904:
v_23902:
    v_23909 = nil;
v_23641:
    return onevalue(v_23909);
}



// Code for extbrsea

static LispObject CC_extbrsea(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23932, v_23933, v_23934;
    LispObject fn;
    argcheck(nargs, 0, "extbrsea");
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
    v_23932 = qvalue(elt(env, 2)); // rowmin
    stack[-1] = v_23932;
v_23642:
    goto v_23654;
v_23650:
    v_23933 = qvalue(elt(env, 3)); // rowmax
    goto v_23651;
v_23652:
    v_23932 = stack[-1];
    goto v_23653;
v_23654:
    goto v_23650;
v_23651:
    goto v_23652;
v_23653:
    v_23932 = difference2(v_23933, v_23932);
    env = stack[-2];
    v_23932 = Lminusp(nil, v_23932);
    env = stack[-2];
    if (v_23932 == nil) goto v_23647;
    goto v_23641;
v_23647:
    goto v_23670;
v_23666:
    goto v_23675;
v_23671:
    goto v_23680;
v_23676:
    stack[0] = qvalue(elt(env, 4)); // codmat
    goto v_23677;
v_23678:
    goto v_23687;
v_23683:
    v_23933 = qvalue(elt(env, 5)); // maxvar
    goto v_23684;
v_23685:
    v_23932 = stack[-1];
    goto v_23686;
v_23687:
    goto v_23683;
v_23684:
    goto v_23685;
v_23686:
    v_23932 = plus2(v_23933, v_23932);
    env = stack[-2];
    goto v_23679;
v_23680:
    goto v_23676;
v_23677:
    goto v_23678;
v_23679:
    v_23933 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_23932-TAG_FIXNUM)/(16/CELL)));
    goto v_23672;
v_23673:
    v_23932 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_23674;
v_23675:
    goto v_23671;
v_23672:
    goto v_23673;
v_23674:
    v_23933 = *(LispObject *)((char *)v_23933 + (CELL-TAG_VECTOR) + (((intptr_t)v_23932-TAG_FIXNUM)/(16/CELL)));
    goto v_23667;
v_23668:
    v_23932 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_23669;
v_23670:
    goto v_23666;
v_23667:
    goto v_23668;
v_23669:
    if (v_23933 == v_23932) goto v_23664;
    else goto v_23665;
v_23664:
    v_23932 = lisp_true;
    goto v_23663;
v_23665:
    goto v_23701;
v_23697:
    goto v_23706;
v_23702:
    goto v_23711;
v_23707:
    stack[0] = qvalue(elt(env, 4)); // codmat
    goto v_23708;
v_23709:
    goto v_23718;
v_23714:
    v_23933 = qvalue(elt(env, 5)); // maxvar
    goto v_23715;
v_23716:
    v_23932 = stack[-1];
    goto v_23717;
v_23718:
    goto v_23714;
v_23715:
    goto v_23716;
v_23717:
    v_23932 = plus2(v_23933, v_23932);
    env = stack[-2];
    goto v_23710;
v_23711:
    goto v_23707;
v_23708:
    goto v_23709;
v_23710:
    v_23933 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_23932-TAG_FIXNUM)/(16/CELL)));
    goto v_23703;
v_23704:
    v_23932 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_23705;
v_23706:
    goto v_23702;
v_23703:
    goto v_23704;
v_23705:
    v_23933 = *(LispObject *)((char *)v_23933 + (CELL-TAG_VECTOR) + (((intptr_t)v_23932-TAG_FIXNUM)/(16/CELL)));
    goto v_23698;
v_23699:
    v_23932 = (LispObject)-32+TAG_FIXNUM; // -2
    goto v_23700;
v_23701:
    goto v_23697;
v_23698:
    goto v_23699;
v_23700:
    v_23932 = (v_23933 == v_23932 ? lisp_true : nil);
    goto v_23663;
    v_23932 = nil;
v_23663:
    if (v_23932 == nil) goto v_23661;
    goto v_23732;
v_23726:
    goto v_23737;
v_23733:
    stack[0] = qvalue(elt(env, 4)); // codmat
    goto v_23734;
v_23735:
    goto v_23744;
v_23740:
    v_23933 = qvalue(elt(env, 5)); // maxvar
    goto v_23741;
v_23742:
    v_23932 = stack[-1];
    goto v_23743;
v_23744:
    goto v_23740;
v_23741:
    goto v_23742;
v_23743:
    v_23932 = plus2(v_23933, v_23932);
    env = stack[-2];
    goto v_23736;
v_23737:
    goto v_23733;
v_23734:
    goto v_23735;
v_23736:
    v_23934 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_23932-TAG_FIXNUM)/(16/CELL)));
    goto v_23727;
v_23728:
    v_23933 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23729;
v_23730:
    v_23932 = nil;
    goto v_23731;
v_23732:
    goto v_23726;
v_23727:
    goto v_23728;
v_23729:
    goto v_23730;
v_23731:
    *(LispObject *)((char *)v_23934 + (CELL-TAG_VECTOR) + (((intptr_t)v_23933-TAG_FIXNUM)/(16/CELL))) = v_23932;
    goto v_23659;
v_23661:
    goto v_23758;
v_23752:
    goto v_23763;
v_23759:
    stack[0] = qvalue(elt(env, 4)); // codmat
    goto v_23760;
v_23761:
    goto v_23770;
v_23766:
    v_23933 = qvalue(elt(env, 5)); // maxvar
    goto v_23767;
v_23768:
    v_23932 = stack[-1];
    goto v_23769;
v_23770:
    goto v_23766;
v_23767:
    goto v_23768;
v_23769:
    v_23932 = plus2(v_23933, v_23932);
    env = stack[-2];
    goto v_23762;
v_23763:
    goto v_23759;
v_23760:
    goto v_23761;
v_23762:
    v_23934 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_23932-TAG_FIXNUM)/(16/CELL)));
    goto v_23753;
v_23754:
    v_23933 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23755;
v_23756:
    v_23932 = lisp_true;
    goto v_23757;
v_23758:
    goto v_23752;
v_23753:
    goto v_23754;
v_23755:
    goto v_23756;
v_23757:
    *(LispObject *)((char *)v_23934 + (CELL-TAG_VECTOR) + (((intptr_t)v_23933-TAG_FIXNUM)/(16/CELL))) = v_23932;
    goto v_23659;
v_23659:
    v_23932 = stack[-1];
    v_23932 = add1(v_23932);
    env = stack[-2];
    stack[-1] = v_23932;
    goto v_23642;
v_23641:
    fn = elt(env, 7); // initbrsea
    v_23932 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    fn = elt(env, 8); // extbrsea1
    v_23932 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
v_23782:
    fn = elt(env, 9); // expandprod
    v_23932 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_23932 = qvalue(elt(env, 2)); // rowmin
    stack[-1] = v_23932;
v_23787:
    goto v_23799;
v_23795:
    v_23933 = qvalue(elt(env, 3)); // rowmax
    goto v_23796;
v_23797:
    v_23932 = stack[-1];
    goto v_23798;
v_23799:
    goto v_23795;
v_23796:
    goto v_23797;
v_23798:
    v_23932 = difference2(v_23933, v_23932);
    env = stack[-2];
    v_23932 = Lminusp(nil, v_23932);
    env = stack[-2];
    if (v_23932 == nil) goto v_23792;
    goto v_23786;
v_23792:
    goto v_23815;
v_23811:
    goto v_23820;
v_23816:
    goto v_23825;
v_23821:
    stack[0] = qvalue(elt(env, 4)); // codmat
    goto v_23822;
v_23823:
    goto v_23832;
v_23828:
    v_23933 = qvalue(elt(env, 5)); // maxvar
    goto v_23829;
v_23830:
    v_23932 = stack[-1];
    goto v_23831;
v_23832:
    goto v_23828;
v_23829:
    goto v_23830;
v_23831:
    v_23932 = plus2(v_23933, v_23932);
    env = stack[-2];
    goto v_23824;
v_23825:
    goto v_23821;
v_23822:
    goto v_23823;
v_23824:
    v_23933 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_23932-TAG_FIXNUM)/(16/CELL)));
    goto v_23817;
v_23818:
    v_23932 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_23819;
v_23820:
    goto v_23816;
v_23817:
    goto v_23818;
v_23819:
    v_23933 = *(LispObject *)((char *)v_23933 + (CELL-TAG_VECTOR) + (((intptr_t)v_23932-TAG_FIXNUM)/(16/CELL)));
    goto v_23812;
v_23813:
    v_23932 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_23814;
v_23815:
    goto v_23811;
v_23812:
    goto v_23813;
v_23814:
    if (v_23933 == v_23932) goto v_23810;
    goto v_23843;
v_23839:
    goto v_23848;
v_23844:
    goto v_23853;
v_23849:
    stack[0] = qvalue(elt(env, 4)); // codmat
    goto v_23850;
v_23851:
    goto v_23860;
v_23856:
    v_23933 = qvalue(elt(env, 5)); // maxvar
    goto v_23857;
v_23858:
    v_23932 = stack[-1];
    goto v_23859;
v_23860:
    goto v_23856;
v_23857:
    goto v_23858;
v_23859:
    v_23932 = plus2(v_23933, v_23932);
    env = stack[-2];
    goto v_23852;
v_23853:
    goto v_23849;
v_23850:
    goto v_23851;
v_23852:
    v_23933 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_23932-TAG_FIXNUM)/(16/CELL)));
    goto v_23845;
v_23846:
    v_23932 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_23847;
v_23848:
    goto v_23844;
v_23845:
    goto v_23846;
v_23847:
    v_23933 = *(LispObject *)((char *)v_23933 + (CELL-TAG_VECTOR) + (((intptr_t)v_23932-TAG_FIXNUM)/(16/CELL)));
    goto v_23840;
v_23841:
    v_23932 = elt(env, 6); // times
    goto v_23842;
v_23843:
    goto v_23839;
v_23840:
    goto v_23841;
v_23842:
    v_23932 = (v_23933 == v_23932 ? lisp_true : nil);
    goto v_23808;
v_23810:
    v_23932 = nil;
    goto v_23808;
    v_23932 = nil;
v_23808:
    if (v_23932 == nil) goto v_23806;
    goto v_23877;
v_23871:
    goto v_23882;
v_23878:
    stack[0] = qvalue(elt(env, 4)); // codmat
    goto v_23879;
v_23880:
    goto v_23889;
v_23885:
    v_23933 = qvalue(elt(env, 5)); // maxvar
    goto v_23886;
v_23887:
    v_23932 = stack[-1];
    goto v_23888;
v_23889:
    goto v_23885;
v_23886:
    goto v_23887;
v_23888:
    v_23932 = plus2(v_23933, v_23932);
    env = stack[-2];
    goto v_23881;
v_23882:
    goto v_23878;
v_23879:
    goto v_23880;
v_23881:
    v_23934 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_23932-TAG_FIXNUM)/(16/CELL)));
    goto v_23872;
v_23873:
    v_23933 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23874;
v_23875:
    v_23932 = lisp_true;
    goto v_23876;
v_23877:
    goto v_23871;
v_23872:
    goto v_23873;
v_23874:
    goto v_23875;
v_23876:
    *(LispObject *)((char *)v_23934 + (CELL-TAG_VECTOR) + (((intptr_t)v_23933-TAG_FIXNUM)/(16/CELL))) = v_23932;
    goto v_23804;
v_23806:
    goto v_23903;
v_23897:
    goto v_23908;
v_23904:
    stack[0] = qvalue(elt(env, 4)); // codmat
    goto v_23905;
v_23906:
    goto v_23915;
v_23911:
    v_23933 = qvalue(elt(env, 5)); // maxvar
    goto v_23912;
v_23913:
    v_23932 = stack[-1];
    goto v_23914;
v_23915:
    goto v_23911;
v_23912:
    goto v_23913;
v_23914:
    v_23932 = plus2(v_23933, v_23932);
    env = stack[-2];
    goto v_23907;
v_23908:
    goto v_23904;
v_23905:
    goto v_23906;
v_23907:
    v_23934 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_23932-TAG_FIXNUM)/(16/CELL)));
    goto v_23898;
v_23899:
    v_23933 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23900;
v_23901:
    v_23932 = nil;
    goto v_23902;
v_23903:
    goto v_23897;
v_23898:
    goto v_23899;
v_23900:
    goto v_23901;
v_23902:
    *(LispObject *)((char *)v_23934 + (CELL-TAG_VECTOR) + (((intptr_t)v_23933-TAG_FIXNUM)/(16/CELL))) = v_23932;
    goto v_23804;
v_23804:
    v_23932 = stack[-1];
    v_23932 = add1(v_23932);
    env = stack[-2];
    stack[-1] = v_23932;
    goto v_23787;
v_23786:
    fn = elt(env, 7); // initbrsea
    v_23932 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    fn = elt(env, 8); // extbrsea1
    v_23932 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    fn = elt(env, 10); // shrinkprod
    v_23932 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_23932 == nil) goto v_23930;
    goto v_23782;
v_23930:
    v_23932 = nil;
    return onevalue(v_23932);
}



// Code for mkbc

static LispObject CC_mkbc(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23741, v_23742;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23634,v_23635);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_23635;
    stack[-1] = v_23634;
// end of prologue
v_23639:
    v_23741 = stack[-1];
    v_23741 = (is_number(v_23741) ? lisp_true : nil);
    if (v_23741 == nil) goto v_23642;
    else goto v_23641;
v_23642:
    v_23741 = stack[-1];
    fn = elt(env, 3); // f2dip11
    v_23741 = (*qfn1(fn))(fn, v_23741);
    env = stack[-3];
v_23641:
    v_23741 = stack[0];
    v_23741 = (is_number(v_23741) ? lisp_true : nil);
    if (v_23741 == nil) goto v_23649;
    else goto v_23648;
v_23649:
    v_23741 = stack[0];
    fn = elt(env, 3); // f2dip11
    v_23741 = (*qfn1(fn))(fn, v_23741);
    env = stack[-3];
v_23648:
    v_23741 = qvalue(elt(env, 1)); // !*grmod!*
    if (v_23741 == nil) goto v_23657;
    goto v_23665;
v_23661:
    goto v_23662;
v_23663:
    v_23741 = stack[0];
    v_23741 = Lmodular_reciprocal(nil, v_23741);
    env = stack[-3];
    goto v_23664;
v_23665:
    goto v_23661;
v_23662:
    goto v_23663;
v_23664:
    v_23741 = times2(stack[-1], v_23741);
    env = stack[-3];
    {
        fn = elt(env, 4); // bcfi
        return (*qfn1(fn))(fn, v_23741);
    }
v_23657:
    goto v_23675;
v_23671:
    v_23742 = stack[0];
    goto v_23672;
v_23673:
    v_23741 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23674;
v_23675:
    goto v_23671;
v_23672:
    goto v_23673;
v_23674:
    if (v_23742 == v_23741) goto v_23669;
    else goto v_23670;
v_23669:
    goto v_23686;
v_23682:
    v_23742 = stack[-1];
    goto v_23683;
v_23684:
    v_23741 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23685;
v_23686:
    goto v_23682;
v_23683:
    goto v_23684;
v_23685:
    if (v_23742 == v_23741) goto v_23680;
    else goto v_23681;
v_23680:
    v_23741 = elt(env, 2); // (1 . 1)
    goto v_23638;
v_23681:
    goto v_23697;
v_23693:
    v_23742 = stack[-1];
    goto v_23694;
v_23695:
    v_23741 = stack[0];
    goto v_23696;
v_23697:
    goto v_23693;
v_23694:
    goto v_23695;
v_23696:
    return cons(v_23742, v_23741);
    goto v_23655;
v_23670:
    v_23741 = stack[0];
    fn = elt(env, 5); // minusf
    v_23741 = (*qfn1(fn))(fn, v_23741);
    env = stack[-3];
    if (v_23741 == nil) goto v_23701;
    v_23741 = stack[-1];
    fn = elt(env, 6); // negf
    v_23741 = (*qfn1(fn))(fn, v_23741);
    env = stack[-3];
    stack[-1] = v_23741;
    v_23741 = stack[0];
    fn = elt(env, 6); // negf
    v_23741 = (*qfn1(fn))(fn, v_23741);
    env = stack[-3];
    stack[0] = v_23741;
    goto v_23639;
v_23701:
    goto v_23715;
v_23711:
    v_23742 = stack[-1];
    goto v_23712;
v_23713:
    v_23741 = stack[0];
    goto v_23714;
v_23715:
    goto v_23711;
v_23712:
    goto v_23713;
v_23714:
    fn = elt(env, 7); // gcdf
    v_23741 = (*qfn2(fn))(fn, v_23742, v_23741);
    env = stack[-3];
    stack[-2] = v_23741;
    goto v_23724;
v_23720:
    goto v_23730;
v_23726:
    v_23742 = stack[-1];
    goto v_23727;
v_23728:
    v_23741 = stack[-2];
    goto v_23729;
v_23730:
    goto v_23726;
v_23727:
    goto v_23728;
v_23729:
    fn = elt(env, 8); // quotfx
    stack[-1] = (*qfn2(fn))(fn, v_23742, v_23741);
    env = stack[-3];
    goto v_23721;
v_23722:
    goto v_23738;
v_23734:
    v_23742 = stack[0];
    goto v_23735;
v_23736:
    v_23741 = stack[-2];
    goto v_23737;
v_23738:
    goto v_23734;
v_23735:
    goto v_23736;
v_23737:
    fn = elt(env, 8); // quotfx
    v_23741 = (*qfn2(fn))(fn, v_23742, v_23741);
    goto v_23723;
v_23724:
    goto v_23720;
v_23721:
    goto v_23722;
v_23723:
    {
        LispObject v_23746 = stack[-1];
        return cons(v_23746, v_23741);
    }
v_23655:
    v_23741 = nil;
v_23638:
    return onevalue(v_23741);
}



// Code for applysetop

static LispObject CC_applysetop(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23916, v_23917, v_23918;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23634,v_23635);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    v_23917 = v_23635;
    stack[-6] = v_23634;
// end of prologue
    stack[-5] = nil;
    v_23916 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_23916;
    v_23916 = v_23917;
    stack[-4] = v_23916;
    v_23916 = stack[-4];
    if (v_23916 == nil) goto v_23653;
    else goto v_23654;
v_23653:
    v_23916 = nil;
    goto v_23648;
v_23654:
    v_23916 = stack[-4];
    v_23916 = qcar(v_23916);
    stack[0] = v_23916;
    goto v_23670;
v_23666:
    v_23916 = stack[0];
    fn = elt(env, 6); // reval
    v_23917 = (*qfn1(fn))(fn, v_23916);
    env = stack[-8];
    stack[0] = v_23917;
    goto v_23667;
v_23668:
    v_23916 = elt(env, 2); // list
    goto v_23669;
v_23670:
    goto v_23666;
v_23667:
    goto v_23668;
v_23669:
    if (!consp(v_23917)) goto v_23664;
    v_23917 = qcar(v_23917);
    if (v_23917 == v_23916) goto v_23663;
    else goto v_23664;
v_23663:
    v_23916 = stack[0];
    v_23916 = qcdr(v_23916);
    fn = elt(env, 7); // delete!-dups
    v_23916 = (*qfn1(fn))(fn, v_23916);
    env = stack[-8];
    stack[0] = v_23916;
    goto v_23685;
v_23681:
    v_23917 = stack[-7];
    goto v_23682;
v_23683:
    v_23916 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23684;
v_23685:
    goto v_23681;
v_23682:
    goto v_23683;
v_23684:
    if (v_23917 == v_23916) goto v_23679;
    else goto v_23680;
v_23679:
    v_23916 = stack[0];
    goto v_23678;
v_23680:
    goto v_23698;
v_23692:
    v_23918 = stack[-6];
    goto v_23693;
v_23694:
    v_23917 = stack[-7];
    goto v_23695;
v_23696:
    v_23916 = stack[0];
    goto v_23697;
v_23698:
    goto v_23692;
v_23693:
    goto v_23694;
v_23695:
    goto v_23696;
v_23697:
    v_23916 = Lapply2(nil, 3, v_23918, v_23917, v_23916);
    env = stack[-8];
    goto v_23678;
    v_23916 = nil;
v_23678:
    stack[-7] = v_23916;
    v_23916 = stack[0];
    fn = elt(env, 8); // make!-set
    v_23916 = (*qfn1(fn))(fn, v_23916);
    env = stack[-8];
    goto v_23662;
v_23664:
    v_23916 = stack[0];
    if (symbolp(v_23916)) goto v_23704;
    v_23916 = stack[0];
    v_23916 = Lconsp(nil, v_23916);
    env = stack[-8];
    if (v_23916 == nil) goto v_23708;
    goto v_23718;
v_23714:
    v_23916 = stack[0];
    v_23917 = qcar(v_23916);
    goto v_23715;
v_23716:
    v_23916 = elt(env, 3); // setvalued
    goto v_23717;
v_23718:
    goto v_23714;
v_23715:
    goto v_23716;
v_23717:
    v_23916 = Lflagp(nil, v_23917, v_23916);
    env = stack[-8];
    if (v_23916 == nil) goto v_23708;
    goto v_23704;
v_23708:
    goto v_23705;
v_23704:
    goto v_23730;
v_23726:
    v_23917 = stack[0];
    goto v_23727;
v_23728:
    v_23916 = stack[-5];
    goto v_23729;
v_23730:
    goto v_23726;
v_23727:
    goto v_23728;
v_23729:
    v_23916 = Lmember(nil, v_23917, v_23916);
    if (v_23916 == nil) goto v_23724;
    else goto v_23725;
v_23724:
    goto v_23739;
v_23735:
    v_23917 = stack[0];
    goto v_23736;
v_23737:
    v_23916 = stack[-5];
    goto v_23738;
v_23739:
    goto v_23735;
v_23736:
    goto v_23737;
v_23738:
    v_23916 = cons(v_23917, v_23916);
    env = stack[-8];
    stack[-5] = v_23916;
    goto v_23723;
v_23725:
v_23723:
    v_23916 = stack[0];
    goto v_23662;
v_23705:
    goto v_23750;
v_23746:
    v_23917 = stack[0];
    goto v_23747;
v_23748:
    v_23916 = elt(env, 4); // "set"
    goto v_23749;
v_23750:
    goto v_23746;
v_23747:
    goto v_23748;
v_23749:
    fn = elt(env, 9); // typerr
    v_23916 = (*qfn2(fn))(fn, v_23917, v_23916);
    env = stack[-8];
    goto v_23662;
    v_23916 = nil;
v_23662:
    v_23916 = ncons(v_23916);
    env = stack[-8];
    stack[-2] = v_23916;
    stack[-3] = v_23916;
v_23649:
    v_23916 = stack[-4];
    v_23916 = qcdr(v_23916);
    stack[-4] = v_23916;
    v_23916 = stack[-4];
    if (v_23916 == nil) goto v_23757;
    else goto v_23758;
v_23757:
    v_23916 = stack[-3];
    goto v_23648;
v_23758:
    goto v_23766;
v_23762:
    stack[-1] = stack[-2];
    goto v_23763;
v_23764:
    v_23916 = stack[-4];
    v_23916 = qcar(v_23916);
    stack[0] = v_23916;
    goto v_23781;
v_23777:
    v_23916 = stack[0];
    fn = elt(env, 6); // reval
    v_23917 = (*qfn1(fn))(fn, v_23916);
    env = stack[-8];
    stack[0] = v_23917;
    goto v_23778;
v_23779:
    v_23916 = elt(env, 2); // list
    goto v_23780;
v_23781:
    goto v_23777;
v_23778:
    goto v_23779;
v_23780:
    if (!consp(v_23917)) goto v_23775;
    v_23917 = qcar(v_23917);
    if (v_23917 == v_23916) goto v_23774;
    else goto v_23775;
v_23774:
    v_23916 = stack[0];
    v_23916 = qcdr(v_23916);
    fn = elt(env, 7); // delete!-dups
    v_23916 = (*qfn1(fn))(fn, v_23916);
    env = stack[-8];
    stack[0] = v_23916;
    goto v_23796;
v_23792:
    v_23917 = stack[-7];
    goto v_23793;
v_23794:
    v_23916 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23795;
v_23796:
    goto v_23792;
v_23793:
    goto v_23794;
v_23795:
    if (v_23917 == v_23916) goto v_23790;
    else goto v_23791;
v_23790:
    v_23916 = stack[0];
    goto v_23789;
v_23791:
    goto v_23809;
v_23803:
    v_23918 = stack[-6];
    goto v_23804;
v_23805:
    v_23917 = stack[-7];
    goto v_23806;
v_23807:
    v_23916 = stack[0];
    goto v_23808;
v_23809:
    goto v_23803;
v_23804:
    goto v_23805;
v_23806:
    goto v_23807;
v_23808:
    v_23916 = Lapply2(nil, 3, v_23918, v_23917, v_23916);
    env = stack[-8];
    goto v_23789;
    v_23916 = nil;
v_23789:
    stack[-7] = v_23916;
    v_23916 = stack[0];
    fn = elt(env, 8); // make!-set
    v_23916 = (*qfn1(fn))(fn, v_23916);
    env = stack[-8];
    goto v_23773;
v_23775:
    v_23916 = stack[0];
    if (symbolp(v_23916)) goto v_23815;
    v_23916 = stack[0];
    v_23916 = Lconsp(nil, v_23916);
    env = stack[-8];
    if (v_23916 == nil) goto v_23819;
    goto v_23829;
v_23825:
    v_23916 = stack[0];
    v_23917 = qcar(v_23916);
    goto v_23826;
v_23827:
    v_23916 = elt(env, 3); // setvalued
    goto v_23828;
v_23829:
    goto v_23825;
v_23826:
    goto v_23827;
v_23828:
    v_23916 = Lflagp(nil, v_23917, v_23916);
    env = stack[-8];
    if (v_23916 == nil) goto v_23819;
    goto v_23815;
v_23819:
    goto v_23816;
v_23815:
    goto v_23841;
v_23837:
    v_23917 = stack[0];
    goto v_23838;
v_23839:
    v_23916 = stack[-5];
    goto v_23840;
v_23841:
    goto v_23837;
v_23838:
    goto v_23839;
v_23840:
    v_23916 = Lmember(nil, v_23917, v_23916);
    if (v_23916 == nil) goto v_23835;
    else goto v_23836;
v_23835:
    goto v_23850;
v_23846:
    v_23917 = stack[0];
    goto v_23847;
v_23848:
    v_23916 = stack[-5];
    goto v_23849;
v_23850:
    goto v_23846;
v_23847:
    goto v_23848;
v_23849:
    v_23916 = cons(v_23917, v_23916);
    env = stack[-8];
    stack[-5] = v_23916;
    goto v_23834;
v_23836:
v_23834:
    v_23916 = stack[0];
    goto v_23773;
v_23816:
    goto v_23861;
v_23857:
    v_23917 = stack[0];
    goto v_23858;
v_23859:
    v_23916 = elt(env, 4); // "set"
    goto v_23860;
v_23861:
    goto v_23857;
v_23858:
    goto v_23859;
v_23860:
    fn = elt(env, 9); // typerr
    v_23916 = (*qfn2(fn))(fn, v_23917, v_23916);
    env = stack[-8];
    goto v_23773;
    v_23916 = nil;
v_23773:
    v_23916 = ncons(v_23916);
    env = stack[-8];
    goto v_23765;
v_23766:
    goto v_23762;
v_23763:
    goto v_23764;
v_23765:
    v_23916 = Lrplacd(nil, stack[-1], v_23916);
    env = stack[-8];
    v_23916 = stack[-2];
    v_23916 = qcdr(v_23916);
    stack[-2] = v_23916;
    goto v_23649;
v_23648:
    v_23918 = v_23916;
    v_23916 = stack[-5];
    if (v_23916 == nil) goto v_23869;
    goto v_23876;
v_23872:
    stack[0] = stack[-6];
    goto v_23873;
v_23874:
    goto v_23886;
v_23882:
    v_23917 = stack[-6];
    goto v_23883;
v_23884:
    v_23916 = elt(env, 5); // setdiff
    goto v_23885;
v_23886:
    goto v_23882;
v_23883:
    goto v_23884;
v_23885:
    if (v_23917 == v_23916) goto v_23880;
    else goto v_23881;
v_23880:
    v_23916 = v_23918;
    goto v_23879;
v_23881:
    goto v_23896;
v_23892:
    v_23917 = stack[-7];
    goto v_23893;
v_23894:
    v_23916 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23895;
v_23896:
    goto v_23892;
v_23893:
    goto v_23894;
v_23895:
    if (v_23917 == v_23916) goto v_23890;
    else goto v_23891;
v_23890:
    v_23916 = stack[-5];
    goto v_23879;
v_23891:
    goto v_23907;
v_23903:
    v_23916 = stack[-7];
    fn = elt(env, 8); // make!-set
    v_23917 = (*qfn1(fn))(fn, v_23916);
    env = stack[-8];
    goto v_23904;
v_23905:
    v_23916 = stack[-5];
    goto v_23906;
v_23907:
    goto v_23903;
v_23904:
    goto v_23905;
v_23906:
    v_23916 = cons(v_23917, v_23916);
    goto v_23879;
    v_23916 = nil;
v_23879:
    goto v_23875;
v_23876:
    goto v_23872;
v_23873:
    goto v_23874;
v_23875:
    {
        LispObject v_23927 = stack[0];
        return cons(v_23927, v_23916);
    }
v_23869:
    v_23916 = stack[-7];
    fn = elt(env, 8); // make!-set
    v_23916 = (*qfn1(fn))(fn, v_23916);
    env = stack[-8];
    {
        fn = elt(env, 10); // aeval
        return (*qfn1(fn))(fn, v_23916);
    }
    v_23916 = nil;
    return onevalue(v_23916);
}



// Code for mod!-dump1

static LispObject CC_modKdump1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23678, v_23679, v_23680;
    LispObject fn;
    LispObject v_23636, v_23635, v_23634;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mod-dump1");
    va_start(aa, nargs);
    v_23634 = va_arg(aa, LispObject);
    v_23635 = va_arg(aa, LispObject);
    v_23636 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_23636,v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_23634,v_23635,v_23636);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_23636;
    stack[-2] = v_23635;
    stack[-3] = v_23634;
// end of prologue
    stack[-4] = nil;
v_23641:
    v_23678 = stack[-1];
    if (v_23678 == nil) goto v_23644;
    else goto v_23645;
v_23644:
    v_23678 = stack[-4];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_23678);
    }
v_23645:
    goto v_23658;
v_23652:
    v_23678 = stack[-1];
    v_23678 = qcar(v_23678);
    stack[0] = qcar(v_23678);
    goto v_23653;
v_23654:
    goto v_23669;
v_23663:
    v_23680 = stack[-3];
    goto v_23664;
v_23665:
    v_23679 = stack[-2];
    goto v_23666;
v_23667:
    v_23678 = stack[-1];
    v_23678 = qcar(v_23678);
    v_23678 = qcdr(v_23678);
    goto v_23668;
v_23669:
    goto v_23663;
v_23664:
    goto v_23665;
v_23666:
    goto v_23667;
v_23668:
    fn = elt(env, 2); // l!-subst
    v_23679 = (*qfnn(fn))(fn, 3, v_23680, v_23679, v_23678);
    env = stack[-5];
    goto v_23655;
v_23656:
    v_23678 = stack[-4];
    goto v_23657;
v_23658:
    goto v_23652;
v_23653:
    goto v_23654;
v_23655:
    goto v_23656;
v_23657:
    v_23678 = acons(stack[0], v_23679, v_23678);
    env = stack[-5];
    stack[-4] = v_23678;
    v_23678 = stack[-1];
    v_23678 = qcdr(v_23678);
    stack[-1] = v_23678;
    goto v_23641;
    v_23678 = nil;
    return onevalue(v_23678);
}



// Code for fd2q

static LispObject CC_fd2q(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23715, v_23716;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_23634;
// end of prologue
v_23638:
    v_23715 = stack[0];
    if (!consp(v_23715)) goto v_23641;
    else goto v_23642;
v_23641:
    goto v_23649;
v_23645:
    v_23716 = stack[0];
    goto v_23646;
v_23647:
    v_23715 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23648;
v_23649:
    goto v_23645;
v_23646:
    goto v_23647;
v_23648:
    return cons(v_23716, v_23715);
v_23642:
    goto v_23658;
v_23654:
    v_23715 = stack[0];
    v_23716 = qcar(v_23715);
    goto v_23655;
v_23656:
    v_23715 = elt(env, 1); // !:ar!:
    goto v_23657;
v_23658:
    goto v_23654;
v_23655:
    goto v_23656;
v_23657:
    if (v_23716 == v_23715) goto v_23652;
    else goto v_23653;
v_23652:
    v_23715 = stack[0];
    v_23715 = qcdr(v_23715);
    stack[0] = v_23715;
    goto v_23638;
v_23653:
    goto v_23670;
v_23666:
    v_23715 = stack[0];
    v_23716 = qcar(v_23715);
    goto v_23667;
v_23668:
    v_23715 = elt(env, 2); // !:rn!:
    goto v_23669;
v_23670:
    goto v_23666;
v_23667:
    goto v_23668;
v_23669:
    if (v_23716 == v_23715) goto v_23664;
    else goto v_23665;
v_23664:
    v_23715 = stack[0];
    v_23715 = qcdr(v_23715);
    goto v_23637;
v_23665:
    goto v_23683;
v_23679:
    goto v_23689;
v_23685:
    goto v_23695;
v_23691:
    goto v_23702;
v_23698:
    v_23715 = stack[0];
    v_23715 = qcar(v_23715);
    v_23716 = qcar(v_23715);
    goto v_23699;
v_23700:
    v_23715 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23701;
v_23702:
    goto v_23698;
v_23699:
    goto v_23700;
v_23701:
    v_23715 = cons(v_23716, v_23715);
    env = stack[-2];
    v_23716 = ncons(v_23715);
    env = stack[-2];
    goto v_23692;
v_23693:
    v_23715 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23694;
v_23695:
    goto v_23691;
v_23692:
    goto v_23693;
v_23694:
    stack[-1] = cons(v_23716, v_23715);
    env = stack[-2];
    goto v_23686;
v_23687:
    v_23715 = stack[0];
    v_23715 = qcar(v_23715);
    v_23715 = qcdr(v_23715);
    v_23715 = CC_fd2q(elt(env, 0), v_23715);
    env = stack[-2];
    goto v_23688;
v_23689:
    goto v_23685;
v_23686:
    goto v_23687;
v_23688:
    fn = elt(env, 3); // multsq
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_23715);
    env = stack[-2];
    goto v_23680;
v_23681:
    v_23715 = stack[0];
    v_23715 = qcdr(v_23715);
    v_23715 = CC_fd2q(elt(env, 0), v_23715);
    env = stack[-2];
    goto v_23682;
v_23683:
    goto v_23679;
v_23680:
    goto v_23681;
v_23682:
    {
        LispObject v_23719 = stack[-1];
        fn = elt(env, 4); // addsq
        return (*qfn2(fn))(fn, v_23719, v_23715);
    }
    v_23715 = nil;
v_23637:
    return onevalue(v_23715);
}



// Code for appn

static LispObject CC_appn(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23683, v_23684;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23634,v_23635);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_23635;
    stack[-1] = v_23634;
// end of prologue
    stack[-2] = nil;
v_23641:
    goto v_23652;
v_23648:
    v_23684 = stack[0];
    goto v_23649;
v_23650:
    v_23683 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23651;
v_23652:
    goto v_23648;
v_23649:
    goto v_23650;
v_23651:
    if (v_23684 == v_23683) goto v_23646;
    else goto v_23647;
v_23646:
    goto v_23642;
v_23647:
    goto v_23660;
v_23656:
    v_23684 = stack[-1];
    goto v_23657;
v_23658:
    v_23683 = stack[-2];
    goto v_23659;
v_23660:
    goto v_23656;
v_23657:
    goto v_23658;
v_23659:
    v_23683 = cons(v_23684, v_23683);
    env = stack[-3];
    stack[-2] = v_23683;
    v_23683 = stack[0];
    v_23683 = sub1(v_23683);
    env = stack[-3];
    stack[0] = v_23683;
    goto v_23641;
v_23642:
    v_23683 = stack[-1];
    v_23684 = v_23683;
v_23643:
    v_23683 = stack[-2];
    if (v_23683 == nil) goto v_23668;
    else goto v_23669;
v_23668:
    v_23683 = v_23684;
    goto v_23640;
v_23669:
    goto v_23677;
v_23673:
    v_23683 = stack[-2];
    v_23683 = qcar(v_23683);
    goto v_23674;
v_23675:
    goto v_23676;
v_23677:
    goto v_23673;
v_23674:
    goto v_23675;
v_23676:
    v_23683 = Lappend(nil, v_23683, v_23684);
    env = stack[-3];
    v_23684 = v_23683;
    v_23683 = stack[-2];
    v_23683 = qcdr(v_23683);
    stack[-2] = v_23683;
    goto v_23643;
v_23640:
    return onevalue(v_23683);
}



// Code for component_action

static LispObject CC_component_action(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23709, v_23710, v_23711;
    LispObject fn;
    LispObject v_23636, v_23635, v_23634;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "component_action");
    va_start(aa, nargs);
    v_23634 = va_arg(aa, LispObject);
    v_23635 = va_arg(aa, LispObject);
    v_23636 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_23636,v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_23634,v_23635,v_23636);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_23636;
    stack[-3] = v_23635;
    stack[0] = v_23634;
// end of prologue
    goto v_23647;
v_23643:
    v_23710 = nil;
    goto v_23644;
v_23645:
    v_23709 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23646;
v_23647:
    goto v_23643;
v_23644:
    goto v_23645;
v_23646:
    v_23709 = cons(v_23710, v_23709);
    env = stack[-5];
    stack[-4] = v_23709;
    v_23709 = stack[0];
    v_23709 = qcdr(v_23709);
    stack[-1] = v_23709;
v_23653:
    v_23709 = stack[-1];
    if (v_23709 == nil) goto v_23658;
    else goto v_23659;
v_23658:
    goto v_23652;
v_23659:
    v_23709 = stack[-1];
    v_23709 = qcar(v_23709);
    stack[0] = v_23709;
    goto v_23670;
v_23666:
    v_23709 = stack[0];
    v_23710 = qcar(v_23709);
    goto v_23667;
v_23668:
    v_23709 = stack[-3];
    goto v_23669;
v_23670:
    goto v_23666;
v_23667:
    goto v_23668;
v_23669:
    fn = elt(env, 2); // ext_mult
    v_23710 = (*qfn2(fn))(fn, v_23710, v_23709);
    env = stack[-5];
    v_23709 = stack[0];
    v_23709 = qcdr(v_23709);
    v_23711 = v_23710;
    v_23710 = v_23709;
    v_23709 = v_23711;
    v_23709 = qcar(v_23709);
    if (v_23709 == nil) goto v_23681;
    goto v_23689;
v_23685:
    stack[0] = stack[-4];
    goto v_23686;
v_23687:
    goto v_23696;
v_23692:
    goto v_23702;
v_23698:
    v_23709 = v_23711;
    goto v_23699;
v_23700:
    goto v_23701;
v_23702:
    goto v_23698;
v_23699:
    goto v_23700;
v_23701:
    fn = elt(env, 3); // multsq
    v_23710 = (*qfn2(fn))(fn, v_23709, v_23710);
    env = stack[-5];
    goto v_23693;
v_23694:
    v_23709 = stack[-2];
    goto v_23695;
v_23696:
    goto v_23692;
v_23693:
    goto v_23694;
v_23695:
    fn = elt(env, 3); // multsq
    v_23709 = (*qfn2(fn))(fn, v_23710, v_23709);
    env = stack[-5];
    goto v_23688;
v_23689:
    goto v_23685;
v_23686:
    goto v_23687;
v_23688:
    fn = elt(env, 4); // addsq
    v_23709 = (*qfn2(fn))(fn, stack[0], v_23709);
    env = stack[-5];
    stack[-4] = v_23709;
    goto v_23679;
v_23681:
v_23679:
    v_23709 = stack[-1];
    v_23709 = qcdr(v_23709);
    stack[-1] = v_23709;
    goto v_23653;
v_23652:
    v_23709 = stack[-4];
    return onevalue(v_23709);
}



// Code for ofsf_evalatp

static LispObject CC_ofsf_evalatp(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23729, v_23730, v_23731;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23634,v_23635);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_23635;
    v_23731 = v_23634;
// end of prologue
    goto v_23645;
v_23641:
    v_23730 = v_23731;
    goto v_23642;
v_23643:
    v_23729 = elt(env, 1); // equal
    goto v_23644;
v_23645:
    goto v_23641;
v_23642:
    goto v_23643;
v_23644:
    if (v_23730 == v_23729) goto v_23639;
    else goto v_23640;
v_23639:
    v_23729 = stack[0];
    v_23729 = (v_23729 == nil ? lisp_true : nil);
    goto v_23638;
v_23640:
    goto v_23656;
v_23652:
    v_23730 = v_23731;
    goto v_23653;
v_23654:
    v_23729 = elt(env, 2); // neq
    goto v_23655;
v_23656:
    goto v_23652;
v_23653:
    goto v_23654;
v_23655:
    if (v_23730 == v_23729) goto v_23650;
    else goto v_23651;
v_23650:
    v_23729 = stack[0];
    v_23729 = (v_23729 == nil ? lisp_true : nil);
    v_23729 = (v_23729 == nil ? lisp_true : nil);
    goto v_23638;
v_23651:
    goto v_23668;
v_23664:
    v_23730 = v_23731;
    goto v_23665;
v_23666:
    v_23729 = elt(env, 3); // leq
    goto v_23667;
v_23668:
    goto v_23664;
v_23665:
    goto v_23666;
v_23667:
    if (v_23730 == v_23729) goto v_23662;
    else goto v_23663;
v_23662:
    v_23729 = stack[0];
    fn = elt(env, 8); // minusf
    v_23729 = (*qfn1(fn))(fn, v_23729);
    if (v_23729 == nil) goto v_23673;
    else goto v_23672;
v_23673:
    v_23729 = stack[0];
    v_23729 = (v_23729 == nil ? lisp_true : nil);
v_23672:
    goto v_23638;
v_23663:
    goto v_23684;
v_23680:
    v_23730 = v_23731;
    goto v_23681;
v_23682:
    v_23729 = elt(env, 4); // geq
    goto v_23683;
v_23684:
    goto v_23680;
v_23681:
    goto v_23682;
v_23683:
    if (v_23730 == v_23729) goto v_23678;
    else goto v_23679;
v_23678:
    v_23729 = stack[0];
    fn = elt(env, 8); // minusf
    v_23729 = (*qfn1(fn))(fn, v_23729);
    v_23729 = (v_23729 == nil ? lisp_true : nil);
    goto v_23638;
v_23679:
    goto v_23696;
v_23692:
    v_23730 = v_23731;
    goto v_23693;
v_23694:
    v_23729 = elt(env, 5); // lessp
    goto v_23695;
v_23696:
    goto v_23692;
v_23693:
    goto v_23694;
v_23695:
    if (v_23730 == v_23729) goto v_23690;
    else goto v_23691;
v_23690:
    v_23729 = stack[0];
    {
        fn = elt(env, 8); // minusf
        return (*qfn1(fn))(fn, v_23729);
    }
v_23691:
    goto v_23707;
v_23703:
    v_23730 = v_23731;
    goto v_23704;
v_23705:
    v_23729 = elt(env, 6); // greaterp
    goto v_23706;
v_23707:
    goto v_23703;
v_23704:
    goto v_23705;
v_23706:
    if (v_23730 == v_23729) goto v_23701;
    else goto v_23702;
v_23701:
    v_23729 = stack[0];
    fn = elt(env, 8); // minusf
    v_23729 = (*qfn1(fn))(fn, v_23729);
    if (v_23729 == nil) goto v_23712;
    else goto v_23711;
v_23712:
    v_23729 = stack[0];
    v_23729 = (v_23729 == nil ? lisp_true : nil);
v_23711:
    v_23729 = (v_23729 == nil ? lisp_true : nil);
    goto v_23638;
v_23702:
    goto v_23726;
v_23722:
    v_23729 = elt(env, 7); // "ofsf_evalatp: unknown operator "
    goto v_23723;
v_23724:
    v_23730 = v_23731;
    goto v_23725;
v_23726:
    goto v_23722;
v_23723:
    goto v_23724;
v_23725:
    v_23729 = list2(v_23729, v_23730);
    env = stack[-1];
    {
        fn = elt(env, 9); // rederr
        return (*qfn1(fn))(fn, v_23729);
    }
    v_23729 = nil;
v_23638:
    return onevalue(v_23729);
}



// Code for fctrf

static LispObject CC_fctrf(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23859, v_23860, v_23861;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_23634;
// end of prologue
    v_23860 = qvalue(elt(env, 1)); // !*exp
    v_23859 = qvalue(elt(env, 2)); // ncmp!*
// Binding !*exp
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
    qvalue(elt(env, 1)) = v_23860; // !*exp
// Binding ncmp!*
// FLUIDBIND: reloadenv=7 litvec-offset=2 saveloc=4
{   bind_fluid_stack bind_fluid_var(-7, 2, -4);
    qvalue(elt(env, 2)) = v_23859; // ncmp!*
// Binding !*ezgcd
// FLUIDBIND: reloadenv=7 litvec-offset=3 saveloc=3
{   bind_fluid_stack bind_fluid_var(-7, 3, -3);
    qvalue(elt(env, 3)) = nil; // !*ezgcd
// Binding !*gcd
// FLUIDBIND: reloadenv=7 litvec-offset=4 saveloc=2
{   bind_fluid_stack bind_fluid_var(-7, 4, -2);
    qvalue(elt(env, 4)) = nil; // !*gcd
    stack[-1] = nil;
    v_23859 = stack[-5];
    if (!consp(v_23859)) goto v_23654;
    else goto v_23655;
v_23654:
    v_23859 = lisp_true;
    goto v_23653;
v_23655:
    v_23859 = stack[-5];
    v_23859 = qcar(v_23859);
    v_23859 = (consp(v_23859) ? nil : lisp_true);
    goto v_23653;
    v_23859 = nil;
v_23653:
    if (v_23859 == nil) goto v_23651;
    v_23859 = stack[-5];
    v_23859 = ncons(v_23859);
    goto v_23646;
v_23651:
    v_23859 = qvalue(elt(env, 2)); // ncmp!*
    if (v_23859 == nil) goto v_23666;
    v_23859 = stack[-5];
    fn = elt(env, 15); // noncomfp
    v_23859 = (*qfn1(fn))(fn, v_23859);
    env = stack[-7];
    if (v_23859 == nil) goto v_23669;
    else goto v_23666;
v_23669:
    v_23859 = nil;
    qvalue(elt(env, 2)) = v_23859; // ncmp!*
    goto v_23649;
v_23666:
v_23649:
    v_23859 = lisp_true;
    qvalue(elt(env, 4)) = v_23859; // !*gcd
    v_23859 = qvalue(elt(env, 6)); // !*limitedfactors
    if (v_23859 == nil) goto v_23680;
    else goto v_23681;
v_23680:
    v_23859 = qvalue(elt(env, 7)); // dmode!*
    v_23859 = (v_23859 == nil ? lisp_true : nil);
    goto v_23679;
v_23681:
    v_23859 = nil;
    goto v_23679;
    v_23859 = nil;
v_23679:
    if (v_23859 == nil) goto v_23677;
    v_23859 = lisp_true;
    qvalue(elt(env, 3)) = v_23859; // !*ezgcd
    goto v_23675;
v_23677:
v_23675:
    v_23859 = qvalue(elt(env, 8)); // !*mcd
    if (v_23859 == nil) goto v_23691;
    else goto v_23692;
v_23691:
    goto v_23701;
v_23695:
    v_23861 = elt(env, 9); // poly
    goto v_23696;
v_23697:
    v_23860 = (LispObject)240+TAG_FIXNUM; // 15
    goto v_23698;
v_23699:
    v_23859 = elt(env, 10); // "Factorization invalid with MCD off"
    goto v_23700;
v_23701:
    goto v_23695;
v_23696:
    goto v_23697;
v_23698:
    goto v_23699;
v_23700:
    fn = elt(env, 16); // rerror
    v_23859 = (*qfnn(fn))(fn, 3, v_23861, v_23860, v_23859);
    env = stack[-7];
    goto v_23690;
v_23692:
    v_23859 = qvalue(elt(env, 1)); // !*exp
    if (v_23859 == nil) goto v_23705;
    else goto v_23706;
v_23705:
    v_23859 = lisp_true;
    qvalue(elt(env, 1)) = v_23859; // !*exp
    goto v_23716;
v_23712:
    v_23860 = stack[-5];
    goto v_23713;
v_23714:
    v_23859 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23715;
v_23716:
    goto v_23712;
v_23713:
    goto v_23714;
v_23715:
    v_23859 = cons(v_23860, v_23859);
    env = stack[-7];
    fn = elt(env, 17); // resimp
    v_23859 = (*qfn1(fn))(fn, v_23859);
    env = stack[-7];
    fn = elt(env, 18); // !*q2f
    v_23859 = (*qfn1(fn))(fn, v_23859);
    env = stack[-7];
    stack[-5] = v_23859;
    goto v_23690;
v_23706:
v_23690:
    goto v_23727;
v_23723:
    v_23860 = qvalue(elt(env, 7)); // dmode!*
    goto v_23724;
v_23725:
    v_23859 = elt(env, 11); // !:rn!:
    goto v_23726;
v_23727:
    goto v_23723;
v_23724:
    goto v_23725;
v_23726:
    if (v_23860 == v_23859) goto v_23721;
    else goto v_23722;
v_23721:
    v_23859 = nil;
    qvalue(elt(env, 7)) = v_23859; // dmode!*
    v_23859 = nil;
    v_23859 = ncons(v_23859);
    env = stack[-7];
    qvalue(elt(env, 12)) = v_23859; // alglist!*
    v_23859 = stack[-5];
    fn = elt(env, 19); // prepf
    v_23859 = (*qfn1(fn))(fn, v_23859);
    env = stack[-7];
    fn = elt(env, 20); // simp
    v_23859 = (*qfn1(fn))(fn, v_23859);
    env = stack[-7];
    stack[0] = v_23859;
    v_23859 = stack[0];
    v_23859 = qcdr(v_23859);
    if (!consp(v_23859)) goto v_23738;
    else goto v_23739;
v_23738:
    v_23859 = stack[0];
    v_23859 = qcdr(v_23859);
    stack[-1] = v_23859;
    v_23859 = stack[0];
    v_23859 = qcar(v_23859);
    stack[-5] = v_23859;
    goto v_23737;
v_23739:
    v_23859 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_23859;
    goto v_23737;
v_23737:
    goto v_23720;
v_23722:
v_23720:
    v_23859 = qvalue(elt(env, 2)); // ncmp!*
    if (v_23859 == nil) goto v_23751;
    else goto v_23752;
v_23751:
    v_23859 = stack[-5];
    fn = elt(env, 21); // sf2ss
    v_23859 = (*qfn1(fn))(fn, v_23859);
    env = stack[-7];
    stack[0] = v_23859;
    v_23859 = stack[0];
    fn = elt(env, 22); // homogp
    v_23859 = (*qfn1(fn))(fn, v_23859);
    env = stack[-7];
    if (v_23859 == nil) goto v_23759;
    v_23859 = qvalue(elt(env, 13)); // !*trfac
    if (v_23859 == nil) goto v_23765;
    v_23859 = elt(env, 14); // "This polynomial is homogeneous - variables scaled"
    fn = elt(env, 23); // prin2t
    v_23859 = (*qfn1(fn))(fn, v_23859);
    env = stack[-7];
    goto v_23763;
v_23765:
v_23763:
    goto v_23774;
v_23770:
    v_23859 = stack[0];
    v_23859 = qcar(v_23859);
    v_23859 = qcar(v_23859);
    stack[-1] = qcar(v_23859);
    goto v_23771;
v_23772:
    v_23859 = stack[0];
    v_23859 = qcdr(v_23859);
    v_23859 = qcar(v_23859);
    v_23859 = qcar(v_23859);
    v_23859 = qcar(v_23859);
    fn = elt(env, 24); // listsum
    v_23859 = (*qfn1(fn))(fn, v_23859);
    env = stack[-7];
    goto v_23773;
v_23774:
    goto v_23770;
v_23771:
    goto v_23772;
v_23773:
    v_23859 = cons(stack[-1], v_23859);
    env = stack[-7];
    stack[-5] = v_23859;
    goto v_23794;
v_23788:
    v_23859 = stack[0];
    stack[-1] = qcar(v_23859);
    goto v_23789;
v_23790:
    v_23859 = stack[0];
    v_23859 = qcdr(v_23859);
    v_23859 = qcar(v_23859);
    fn = elt(env, 25); // subs0
    v_23859 = (*qfn1(fn))(fn, v_23859);
    env = stack[-7];
    v_23860 = Lreverse(nil, v_23859);
    env = stack[-7];
    goto v_23791;
v_23792:
    v_23859 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23793;
v_23794:
    goto v_23788;
v_23789:
    goto v_23790;
v_23791:
    goto v_23792;
v_23793:
    v_23859 = list2star(stack[-1], v_23860, v_23859);
    env = stack[-7];
    fn = elt(env, 26); // ss2sf
    v_23859 = (*qfn1(fn))(fn, v_23859);
    env = stack[-7];
    fn = elt(env, 27); // fctrf1
    v_23859 = (*qfn1(fn))(fn, v_23859);
    env = stack[-7];
    stack[0] = v_23859;
    goto v_23808;
v_23804:
    v_23860 = stack[-5];
    goto v_23805;
v_23806:
    v_23859 = stack[0];
    goto v_23807;
v_23808:
    goto v_23804;
v_23805:
    goto v_23806;
v_23807:
    fn = elt(env, 28); // rconst
    v_23859 = (*qfn2(fn))(fn, v_23860, v_23859);
    env = stack[-7];
    stack[0] = v_23859;
    goto v_23816;
v_23812:
    v_23859 = stack[0];
    stack[-1] = qcar(v_23859);
    goto v_23813;
v_23814:
    v_23859 = stack[0];
    v_23859 = qcdr(v_23859);
    fn = elt(env, 29); // sort!-factors
    v_23859 = (*qfn1(fn))(fn, v_23859);
    env = stack[-7];
    goto v_23815;
v_23816:
    goto v_23812;
v_23813:
    goto v_23814;
v_23815:
    v_23859 = cons(stack[-1], v_23859);
    goto v_23646;
v_23759:
    goto v_23750;
v_23752:
v_23750:
    v_23859 = stack[-5];
    fn = elt(env, 27); // fctrf1
    v_23859 = (*qfn1(fn))(fn, v_23859);
    env = stack[-7];
    stack[-5] = v_23859;
    v_23859 = stack[-1];
    if (v_23859 == nil) goto v_23827;
    v_23859 = nil;
    v_23859 = ncons(v_23859);
    env = stack[-7];
    qvalue(elt(env, 12)) = v_23859; // alglist!*
    v_23859 = elt(env, 11); // !:rn!:
    qvalue(elt(env, 7)) = v_23859; // dmode!*
    goto v_23837;
v_23833:
    stack[0] = stack[-5];
    goto v_23834;
v_23835:
    goto v_23844;
v_23840:
    v_23859 = stack[-5];
    v_23860 = qcar(v_23859);
    goto v_23841;
v_23842:
    v_23859 = stack[-1];
    goto v_23843;
v_23844:
    goto v_23840;
v_23841:
    goto v_23842;
v_23843:
    fn = elt(env, 30); // quotf!*
    v_23859 = (*qfn2(fn))(fn, v_23860, v_23859);
    env = stack[-7];
    goto v_23836;
v_23837:
    goto v_23833;
v_23834:
    goto v_23835;
v_23836:
    fn = elt(env, 31); // setcar
    v_23859 = (*qfn2(fn))(fn, stack[0], v_23859);
    env = stack[-7];
    goto v_23825;
v_23827:
v_23825:
    goto v_23853;
v_23849:
    v_23859 = stack[-5];
    stack[0] = qcar(v_23859);
    goto v_23850;
v_23851:
    v_23859 = stack[-5];
    v_23859 = qcdr(v_23859);
    fn = elt(env, 29); // sort!-factors
    v_23859 = (*qfn1(fn))(fn, v_23859);
    env = stack[-7];
    goto v_23852;
v_23853:
    goto v_23849;
v_23850:
    goto v_23851;
v_23852:
    v_23859 = cons(stack[0], v_23859);
v_23646:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_23859);
}



// Code for matrixrd

static LispObject CC_matrixrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23742, v_23743, v_23744;
    LispObject fn;
    argcheck(nargs, 0, "matrixrd");
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
    goto v_23647;
v_23643:
    v_23743 = qvalue(elt(env, 2)); // atts
    goto v_23644;
v_23645:
    v_23742 = elt(env, 3); // (type)
    goto v_23646;
v_23647:
    goto v_23643;
v_23644:
    goto v_23645;
v_23646:
    fn = elt(env, 10); // retattributes
    v_23742 = (*qfn2(fn))(fn, v_23743, v_23742);
    env = stack[-3];
    stack[0] = v_23742;
    v_23742 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_23742;
    v_23742 = nil;
    stack[-2] = v_23742;
v_23655:
    goto v_23664;
v_23660:
    v_23743 = stack[-1];
    goto v_23661;
v_23662:
    v_23742 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23663;
v_23664:
    goto v_23660;
v_23661:
    goto v_23662;
v_23663:
    if (v_23743 == v_23742) goto v_23659;
    goto v_23654;
v_23659:
    fn = elt(env, 11); // lex
    v_23742 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_23677;
v_23673:
    v_23743 = qvalue(elt(env, 4)); // char
    goto v_23674;
v_23675:
    v_23742 = elt(env, 5); // (m a t r i x r o w)
    goto v_23676;
v_23677:
    goto v_23673;
v_23674:
    goto v_23675;
v_23676:
    if (equal(v_23743, v_23742)) goto v_23671;
    else goto v_23672;
v_23671:
    fn = elt(env, 12); // matrixrowrd
    v_23742 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    v_23743 = v_23742;
    v_23742 = stack[-2];
    if (v_23742 == nil) goto v_23684;
    goto v_23691;
v_23687:
    goto v_23688;
v_23689:
    v_23742 = v_23743;
    v_23742 = ncons(v_23742);
    env = stack[-3];
    goto v_23690;
v_23691:
    goto v_23687;
v_23688:
    goto v_23689;
v_23690:
    v_23742 = Lappend(nil, stack[-2], v_23742);
    env = stack[-3];
    stack[-2] = v_23742;
    goto v_23682;
v_23684:
    v_23742 = v_23743;
    v_23742 = ncons(v_23742);
    env = stack[-3];
    stack[-2] = v_23742;
    goto v_23682;
v_23682:
    goto v_23707;
v_23703:
    v_23743 = qvalue(elt(env, 4)); // char
    goto v_23704;
v_23705:
    v_23742 = elt(env, 6); // (!/ m a t r i x r o w)
    goto v_23706;
v_23707:
    goto v_23703;
v_23704:
    goto v_23705;
v_23706:
    if (equal(v_23743, v_23742)) goto v_23702;
    goto v_23715;
v_23711:
    v_23743 = elt(env, 7); // "</matrixrow>"
    goto v_23712;
v_23713:
    v_23742 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_23714;
v_23715:
    goto v_23711;
v_23712:
    goto v_23713;
v_23714:
    fn = elt(env, 13); // errorml
    v_23742 = (*qfn2(fn))(fn, v_23743, v_23742);
    env = stack[-3];
    goto v_23700;
v_23702:
v_23700:
    goto v_23670;
v_23672:
    v_23742 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_23742;
    goto v_23670;
v_23670:
    goto v_23655;
v_23654:
    goto v_23728;
v_23722:
    stack[-1] = elt(env, 8); // matrix
    goto v_23723;
v_23724:
    goto v_23725;
v_23726:
    goto v_23738;
v_23732:
    v_23744 = elt(env, 9); // matrixrow
    goto v_23733;
v_23734:
    v_23743 = stack[-2];
    goto v_23735;
v_23736:
    v_23742 = nil;
    goto v_23737;
v_23738:
    goto v_23732;
v_23733:
    goto v_23734;
v_23735:
    goto v_23736;
v_23737:
    v_23742 = list2star(v_23744, v_23743, v_23742);
    goto v_23727;
v_23728:
    goto v_23722;
v_23723:
    goto v_23724;
v_23725:
    goto v_23726;
v_23727:
    {
        LispObject v_23748 = stack[-1];
        LispObject v_23749 = stack[0];
        return list2star(v_23748, v_23749, v_23742);
    }
    return onevalue(v_23742);
}



// Code for evweightedcomp1

static LispObject CC_evweightedcomp1(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23648, v_23649, v_23650;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23648 = v_23635;
    v_23649 = v_23634;
// end of prologue
    goto v_23644;
v_23638:
    v_23650 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23639;
v_23640:
    goto v_23641;
v_23642:
    goto v_23643;
v_23644:
    goto v_23638;
v_23639:
    goto v_23640;
v_23641:
    goto v_23642;
v_23643:
    {
        fn = elt(env, 1); // evweightedcomp2
        return (*qfnn(fn))(fn, 3, v_23650, v_23649, v_23648);
    }
}



// Code for mkupf

static LispObject CC_mkupf(LispObject env,
                         LispObject v_23634)
{
    env = qenv(env);
    LispObject v_23750, v_23751, v_23752;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23634);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_23750 = v_23634;
// end of prologue
    goto v_23645;
v_23641:
    v_23751 = v_23750;
    goto v_23642;
v_23643:
    v_23750 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23644;
v_23645:
    goto v_23641;
v_23642:
    goto v_23643;
v_23644:
    fn = elt(env, 2); // mksq
    v_23750 = (*qfn2(fn))(fn, v_23751, v_23750);
    env = stack[-1];
    stack[0] = v_23750;
    v_23750 = stack[0];
    v_23750 = qcar(v_23750);
    if (v_23750 == nil) goto v_23650;
    else goto v_23651;
v_23650:
    v_23750 = nil;
    goto v_23649;
v_23651:
    v_23750 = stack[0];
    v_23750 = qcar(v_23750);
    if (!consp(v_23750)) goto v_23659;
    else goto v_23660;
v_23659:
    v_23750 = lisp_true;
    goto v_23658;
v_23660:
    v_23750 = stack[0];
    v_23750 = qcar(v_23750);
    v_23750 = qcar(v_23750);
    v_23750 = (consp(v_23750) ? nil : lisp_true);
    goto v_23658;
    v_23750 = nil;
v_23658:
    if (v_23750 == nil) goto v_23656;
    goto v_23676;
v_23672:
    v_23751 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23673;
v_23674:
    v_23750 = stack[0];
    goto v_23675;
v_23676:
    goto v_23672;
v_23673:
    goto v_23674;
v_23675:
    v_23750 = cons(v_23751, v_23750);
    return ncons(v_23750);
v_23656:
    goto v_23689;
v_23685:
    v_23750 = stack[0];
    v_23751 = qcdr(v_23750);
    goto v_23686;
v_23687:
    v_23750 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23688;
v_23689:
    goto v_23685;
v_23686:
    goto v_23687;
v_23688:
    if (v_23751 == v_23750) goto v_23683;
    else goto v_23684;
v_23683:
    goto v_23701;
v_23697:
    v_23750 = stack[0];
    v_23750 = qcar(v_23750);
    v_23750 = qcar(v_23750);
    v_23751 = qcdr(v_23750);
    goto v_23698;
v_23699:
    v_23750 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23700;
v_23701:
    goto v_23697;
v_23698:
    goto v_23699;
v_23700:
    if (v_23751 == v_23750) goto v_23695;
    else goto v_23696;
v_23695:
    v_23750 = stack[0];
    v_23750 = qcar(v_23750);
    v_23750 = qcdr(v_23750);
    if (v_23750 == nil) goto v_23709;
    else goto v_23710;
v_23709:
    v_23750 = stack[0];
    v_23750 = qcar(v_23750);
    v_23750 = qcar(v_23750);
    v_23750 = qcar(v_23750);
    v_23750 = qcar(v_23750);
    fn = elt(env, 3); // sfp
    v_23750 = (*qfn1(fn))(fn, v_23750);
    env = stack[-1];
    v_23750 = (v_23750 == nil ? lisp_true : nil);
    goto v_23708;
v_23710:
    v_23750 = nil;
    goto v_23708;
    v_23750 = nil;
v_23708:
    goto v_23694;
v_23696:
    v_23750 = nil;
    goto v_23694;
    v_23750 = nil;
v_23694:
    goto v_23682;
v_23684:
    v_23750 = nil;
    goto v_23682;
    v_23750 = nil;
v_23682:
    if (v_23750 == nil) goto v_23680;
    goto v_23738;
v_23732:
    v_23750 = stack[0];
    v_23750 = qcar(v_23750);
    v_23750 = qcar(v_23750);
    v_23750 = qcar(v_23750);
    v_23752 = qcar(v_23750);
    goto v_23733;
v_23734:
    v_23751 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23735;
v_23736:
    v_23750 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23737;
v_23738:
    goto v_23732;
v_23733:
    goto v_23734;
v_23735:
    goto v_23736;
v_23737:
    v_23750 = list2star(v_23752, v_23751, v_23750);
    return ncons(v_23750);
v_23680:
    v_23750 = stack[0];
    {
        fn = elt(env, 4); // partitsq!*
        return (*qfn1(fn))(fn, v_23750);
    }
    v_23750 = nil;
v_23649:
    return onevalue(v_23750);
}



// Code for list!-evaluate

static LispObject CC_listKevaluate(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23698, v_23699, v_23700;
    LispObject fn;
    LispObject v_23636, v_23635, v_23634;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "list-evaluate");
    va_start(aa, nargs);
    v_23634 = va_arg(aa, LispObject);
    v_23635 = va_arg(aa, LispObject);
    v_23636 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_23636,v_23635,v_23634);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_23634,v_23635,v_23636);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_23636;
    stack[-4] = v_23635;
    v_23698 = v_23634;
// end of prologue
    stack[-5] = v_23698;
    v_23698 = stack[-5];
    if (v_23698 == nil) goto v_23647;
    else goto v_23648;
v_23647:
    v_23698 = nil;
    goto v_23642;
v_23648:
    v_23698 = stack[-5];
    v_23698 = qcar(v_23698);
    goto v_23662;
v_23656:
    v_23700 = v_23698;
    goto v_23657;
v_23658:
    v_23699 = stack[-4];
    goto v_23659;
v_23660:
    v_23698 = stack[-3];
    goto v_23661;
v_23662:
    goto v_23656;
v_23657:
    goto v_23658;
v_23659:
    goto v_23660;
v_23661:
    fn = elt(env, 1); // evaluate
    v_23698 = (*qfnn(fn))(fn, 3, v_23700, v_23699, v_23698);
    env = stack[-6];
    v_23698 = ncons(v_23698);
    env = stack[-6];
    stack[-1] = v_23698;
    stack[-2] = v_23698;
v_23643:
    v_23698 = stack[-5];
    v_23698 = qcdr(v_23698);
    stack[-5] = v_23698;
    v_23698 = stack[-5];
    if (v_23698 == nil) goto v_23670;
    else goto v_23671;
v_23670:
    v_23698 = stack[-2];
    goto v_23642;
v_23671:
    goto v_23679;
v_23675:
    stack[0] = stack[-1];
    goto v_23676;
v_23677:
    v_23698 = stack[-5];
    v_23698 = qcar(v_23698);
    goto v_23692;
v_23686:
    v_23700 = v_23698;
    goto v_23687;
v_23688:
    v_23699 = stack[-4];
    goto v_23689;
v_23690:
    v_23698 = stack[-3];
    goto v_23691;
v_23692:
    goto v_23686;
v_23687:
    goto v_23688;
v_23689:
    goto v_23690;
v_23691:
    fn = elt(env, 1); // evaluate
    v_23698 = (*qfnn(fn))(fn, 3, v_23700, v_23699, v_23698);
    env = stack[-6];
    v_23698 = ncons(v_23698);
    env = stack[-6];
    goto v_23678;
v_23679:
    goto v_23675;
v_23676:
    goto v_23677;
v_23678:
    v_23698 = Lrplacd(nil, stack[0], v_23698);
    env = stack[-6];
    v_23698 = stack[-1];
    v_23698 = qcdr(v_23698);
    stack[-1] = v_23698;
    goto v_23643;
v_23642:
    return onevalue(v_23698);
}



// Code for cvitimes2

static LispObject CC_cvitimes2(LispObject env,
                         LispObject v_23634, LispObject v_23635)
{
    env = qenv(env);
    LispObject v_23697, v_23698, v_23699, v_23700;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23699 = v_23635;
    v_23700 = v_23634;
// end of prologue
    goto v_23649;
v_23645:
    v_23698 = v_23700;
    goto v_23646;
v_23647:
    v_23697 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23648;
v_23649:
    goto v_23645;
v_23646:
    goto v_23647;
v_23648:
    if (v_23698 == v_23697) goto v_23643;
    else goto v_23644;
v_23643:
    v_23697 = lisp_true;
    goto v_23642;
v_23644:
    goto v_23659;
v_23655:
    v_23698 = v_23699;
    goto v_23656;
v_23657:
    v_23697 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23658;
v_23659:
    goto v_23655;
v_23656:
    goto v_23657;
v_23658:
    v_23697 = (v_23698 == v_23697 ? lisp_true : nil);
    goto v_23642;
    v_23697 = nil;
v_23642:
    if (v_23697 == nil) goto v_23640;
    v_23697 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23638;
v_23640:
    goto v_23670;
v_23666:
    v_23698 = v_23700;
    goto v_23667;
v_23668:
    v_23697 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23669;
v_23670:
    goto v_23666;
v_23667:
    goto v_23668;
v_23669:
    if (v_23698 == v_23697) goto v_23664;
    else goto v_23665;
v_23664:
    v_23697 = v_23699;
    goto v_23638;
v_23665:
    goto v_23680;
v_23676:
    v_23698 = v_23699;
    goto v_23677;
v_23678:
    v_23697 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23679;
v_23680:
    goto v_23676;
v_23677:
    goto v_23678;
v_23679:
    if (v_23698 == v_23697) goto v_23674;
    else goto v_23675;
v_23674:
    v_23697 = v_23700;
    goto v_23638;
v_23675:
    goto v_23693;
v_23687:
    v_23697 = elt(env, 1); // times
    goto v_23688;
v_23689:
    v_23698 = v_23700;
    goto v_23690;
v_23691:
    goto v_23692;
v_23693:
    goto v_23687;
v_23688:
    goto v_23689;
v_23690:
    goto v_23691;
v_23692:
    return list3(v_23697, v_23698, v_23699);
    v_23697 = nil;
v_23638:
    return onevalue(v_23697);
}



setup_type const u42_setup[] =
{
    {"lex_keywords",            CC_lex_keywords,TOO_MANY_1,    WRONG_NO_1},
    {"repr_new",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_repr_new},
    {"sfto_subfwd",             TOO_FEW_2,      CC_sfto_subfwd,WRONG_NO_2},
    {"fnom",                    CC_fnom,        TOO_MANY_1,    WRONG_NO_1},
    {"ldf-simp",                CC_ldfKsimp,    TOO_MANY_1,    WRONG_NO_1},
    {"genexp",                  CC_genexp,      TOO_MANY_1,    WRONG_NO_1},
    {"vdpmember",               TOO_FEW_2,      CC_vdpmember,  WRONG_NO_2},
    {"evinsert",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_evinsert},
    {"aceq",                    TOO_FEW_2,      CC_aceq,       WRONG_NO_2},
    {"calc_atlas",              TOO_FEW_2,      CC_calc_atlas, WRONG_NO_2},
    {"log_freevars",            TOO_FEW_2,      CC_log_freevars,WRONG_NO_2},
    {"reduce",                  TOO_FEW_2,      CC_reduce,     WRONG_NO_2},
    {"oddext",                  CC_oddext,      TOO_MANY_1,    WRONG_NO_1},
    {"ra_intequiv0",            CC_ra_intequiv0,TOO_MANY_1,    WRONG_NO_1},
    {"lalr_augment_grammar",    CC_lalr_augment_grammar,TOO_MANY_1,WRONG_NO_1},
    {"createsinglevariablemonom",CC_createsinglevariablemonom,TOO_MANY_1,WRONG_NO_1},
    {"orddf",                   TOO_FEW_2,      CC_orddf,      WRONG_NO_2},
    {"cl_pnf1",                 CC_cl_pnf1,     TOO_MANY_1,    WRONG_NO_1},
    {"mri_2ofsfat",             CC_mri_2ofsfat, TOO_MANY_1,    WRONG_NO_1},
    {"iv_cutcongs2",            TOO_FEW_2,      CC_iv_cutcongs2,WRONG_NO_2},
    {"degree-order",            TOO_FEW_2,      CC_degreeKorder,WRONG_NO_2},
    {"vectorrd",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vectorrd},
    {"compl",                   TOO_FEW_2,      CC_compl,      WRONG_NO_2},
    {"simpimpart",              CC_simpimpart,  TOO_MANY_1,    WRONG_NO_1},
    {"suspend",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_suspend},
    {"sc_columnscalarproduct",  TOO_FEW_2,      CC_sc_columnscalarproduct,WRONG_NO_2},
    {"a2bc",                    CC_a2bc,        TOO_MANY_1,    WRONG_NO_1},
    {"simpwedge",               CC_simpwedge,   TOO_MANY_1,    WRONG_NO_1},
    {"replace2_parents",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_replace2_parents},
    {"fs:minusp:",              CC_fsTminuspT,  TOO_MANY_1,    WRONG_NO_1},
    {"pst_subpst",              TOO_FEW_2,      CC_pst_subpst, WRONG_NO_2},
    {"*n2a",                    CC_Hn2a,        TOO_MANY_1,    WRONG_NO_1},
    {"read-comment1",           CC_readKcomment1,TOO_MANY_1,   WRONG_NO_1},
    {"ra_intequiv",             CC_ra_intequiv, TOO_MANY_1,    WRONG_NO_1},
    {"lalr_collect_nonterminals",CC_lalr_collect_nonterminals,TOO_MANY_1,WRONG_NO_1},
    {"maxfrom",                 TOO_FEW_2,      CC_maxfrom,    WRONG_NO_2},
    {"rl_mk*fof",               CC_rl_mkHfof,   TOO_MANY_1,    WRONG_NO_1},
    {"repr_ldeg",               CC_repr_ldeg,   TOO_MANY_1,    WRONG_NO_1},
    {"rl_multsurep",            TOO_FEW_2,      CC_rl_multsurep,WRONG_NO_2},
    {"lowupperlimitrd",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lowupperlimitrd},
    {"prlist",                  CC_prlist,      TOO_MANY_1,    WRONG_NO_1},
    {"assgnpri",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_assgnpri},
    {"extbrsea",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_extbrsea},
    {"mkbc",                    TOO_FEW_2,      CC_mkbc,       WRONG_NO_2},
    {"applysetop",              TOO_FEW_2,      CC_applysetop, WRONG_NO_2},
    {"mod-dump1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_modKdump1},
    {"fd2q",                    CC_fd2q,        TOO_MANY_1,    WRONG_NO_1},
    {"appn",                    TOO_FEW_2,      CC_appn,       WRONG_NO_2},
    {"component_action",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_component_action},
    {"ofsf_evalatp",            TOO_FEW_2,      CC_ofsf_evalatp,WRONG_NO_2},
    {"fctrf",                   CC_fctrf,       TOO_MANY_1,    WRONG_NO_1},
    {"matrixrd",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_matrixrd},
    {"evweightedcomp1",         TOO_FEW_2,      CC_evweightedcomp1,WRONG_NO_2},
    {"mkupf",                   CC_mkupf,       TOO_MANY_1,    WRONG_NO_1},
    {"list-evaluate",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_listKevaluate},
    {"cvitimes2",               TOO_FEW_2,      CC_cvitimes2,  WRONG_NO_2},
    {NULL, (one_args *)"u42", (two_args *)"6654 1857534 9213309", 0}
};

// end of generated code
