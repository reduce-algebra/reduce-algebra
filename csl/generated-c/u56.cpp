
// $destdir/u56.c        Machine generated C code

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



// Code for equal!+matrices!+p

static LispObject CC_equalLmatricesLp(LispObject env,
                         LispObject v_33004, LispObject v_33005)
{
    env = qenv(env);
    LispObject v_33152, v_33153, v_33154;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33005,v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33004,v_33005);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_33005;
    stack[-1] = v_33004;
// end of prologue
    goto v_33027;
v_33023:
    v_33153 = stack[-1];
    goto v_33024;
v_33025:
    v_33152 = stack[0];
    goto v_33026;
v_33027:
    goto v_33023;
v_33024:
    goto v_33025;
v_33026:
    fn = elt(env, 3); // same!+dim!+squared!+p
    v_33152 = (*qfn2(fn))(fn, v_33153, v_33152);
    env = stack[-4];
    if (v_33152 == nil) goto v_33021;
    goto v_33035;
v_33031:
    goto v_33032;
v_33033:
    goto v_33042;
v_33038:
    goto v_33048;
v_33044:
    v_33153 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_33045;
v_33046:
    v_33152 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33047;
v_33048:
    goto v_33044;
v_33045:
    goto v_33046;
v_33047:
    v_33153 = cons(v_33153, v_33152);
    env = stack[-4];
    goto v_33039;
v_33040:
    v_33152 = stack[0];
    goto v_33041;
v_33042:
    goto v_33038;
v_33039:
    goto v_33040;
v_33041:
    fn = elt(env, 4); // mk!+scal!+mult!+mat
    v_33152 = (*qfn2(fn))(fn, v_33153, v_33152);
    env = stack[-4];
    goto v_33034;
v_33035:
    goto v_33031;
v_33032:
    goto v_33033;
v_33034:
    fn = elt(env, 5); // mk!+mat!+plus!+mat
    v_33152 = (*qfn2(fn))(fn, stack[-1], v_33152);
    env = stack[-4];
    stack[0] = v_33152;
    goto v_33057;
v_33053:
    v_33153 = nil;
    goto v_33054;
v_33055:
    v_33152 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33056;
v_33057:
    goto v_33053;
v_33054:
    goto v_33055;
v_33056:
    v_33152 = cons(v_33153, v_33152);
    env = stack[-4];
    v_33154 = v_33152;
    v_33152 = stack[0];
    stack[-3] = v_33152;
v_33063:
    v_33152 = stack[-3];
    if (v_33152 == nil) goto v_33067;
    else goto v_33068;
v_33067:
    goto v_33062;
v_33068:
    v_33152 = stack[-3];
    v_33152 = qcar(v_33152);
    stack[-2] = v_33152;
v_33077:
    v_33152 = stack[-2];
    if (v_33152 == nil) goto v_33081;
    else goto v_33082;
v_33081:
    goto v_33076;
v_33082:
    v_33152 = stack[-2];
    v_33152 = qcar(v_33152);
    v_33153 = v_33152;
    v_33152 = qvalue(elt(env, 2)); // !*complex
    if (v_33152 == nil) goto v_33091;
    goto v_33098;
v_33094:
    stack[-1] = v_33154;
    goto v_33095;
v_33096:
    goto v_33105;
v_33101:
    stack[0] = v_33153;
    goto v_33102;
v_33103:
    v_33152 = v_33153;
    fn = elt(env, 6); // mk!+conjugate!+sq
    v_33152 = (*qfn1(fn))(fn, v_33152);
    env = stack[-4];
    goto v_33104;
v_33105:
    goto v_33101;
v_33102:
    goto v_33103;
v_33104:
    fn = elt(env, 7); // multsq
    v_33152 = (*qfn2(fn))(fn, stack[0], v_33152);
    env = stack[-4];
    goto v_33097;
v_33098:
    goto v_33094;
v_33095:
    goto v_33096;
v_33097:
    fn = elt(env, 8); // addsq
    v_33152 = (*qfn2(fn))(fn, stack[-1], v_33152);
    env = stack[-4];
    v_33154 = v_33152;
    goto v_33089;
v_33091:
    goto v_33116;
v_33112:
    stack[0] = v_33154;
    goto v_33113;
v_33114:
    goto v_33123;
v_33119:
    v_33152 = v_33153;
    goto v_33120;
v_33121:
    goto v_33122;
v_33123:
    goto v_33119;
v_33120:
    goto v_33121;
v_33122:
    fn = elt(env, 7); // multsq
    v_33152 = (*qfn2(fn))(fn, v_33152, v_33153);
    env = stack[-4];
    goto v_33115;
v_33116:
    goto v_33112;
v_33113:
    goto v_33114;
v_33115:
    fn = elt(env, 8); // addsq
    v_33152 = (*qfn2(fn))(fn, stack[0], v_33152);
    env = stack[-4];
    v_33154 = v_33152;
    goto v_33089;
v_33089:
    v_33152 = stack[-2];
    v_33152 = qcdr(v_33152);
    stack[-2] = v_33152;
    goto v_33077;
v_33076:
    v_33152 = stack[-3];
    v_33152 = qcdr(v_33152);
    stack[-3] = v_33152;
    goto v_33063;
v_33062:
    v_33152 = v_33154;
    fn = elt(env, 9); // change!+sq!+to!+algnull
    v_33152 = (*qfn1(fn))(fn, v_33152);
    goto v_33140;
v_33136:
    v_33153 = v_33152;
    goto v_33137;
v_33138:
    v_33152 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33139;
v_33140:
    goto v_33136;
v_33137:
    goto v_33138;
v_33139:
    if (v_33153 == v_33152) goto v_33134;
    else goto v_33135;
v_33134:
    v_33152 = lisp_true;
    goto v_33133;
v_33135:
    v_33152 = nil;
    goto v_33133;
v_33133:
    goto v_33019;
v_33021:
    v_33152 = nil;
    goto v_33019;
v_33019:
    return onevalue(v_33152);
}



// Code for talp_try2

static LispObject CC_talp_try2(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33040, v_33041;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33004);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33004;
// end of prologue
    v_33040 = stack[0];
    fn = elt(env, 2); // cl_bvarl
    v_33040 = (*qfn1(fn))(fn, v_33040);
    env = stack[-2];
    stack[-1] = v_33040;
    v_33040 = stack[0];
    fn = elt(env, 3); // cl_fvarl
    v_33040 = (*qfn1(fn))(fn, v_33040);
    env = stack[-2];
    goto v_33021;
v_33017:
    v_33041 = stack[-1];
    goto v_33018;
v_33019:
    goto v_33020;
v_33021:
    goto v_33017;
v_33018:
    goto v_33019;
v_33020:
    v_33040 = Lappend(nil, v_33041, v_33040);
    env = stack[-2];
    v_33041 = v_33040;
    if (v_33041 == nil) goto v_33027;
    goto v_33034;
v_33030:
    v_33041 = stack[0];
    goto v_33031;
v_33032:
    goto v_33033;
v_33034:
    goto v_33030;
v_33031:
    goto v_33032;
v_33033:
    {
        fn = elt(env, 4); // talp_try3
        return (*qfn2(fn))(fn, v_33041, v_33040);
    }
v_33027:
    v_33040 = stack[0];
    goto v_33025;
    v_33040 = nil;
v_33025:
    return onevalue(v_33040);
}



// Code for parseml

static LispObject CC_parseml(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33067, v_33068;
    LispObject fn;
    argcheck(nargs, 0, "parseml");
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
    v_33067 = nil;
    stack[0] = v_33067;
    v_33067 = (LispObject)512+TAG_FIXNUM; // 32
    v_33067 = ncons(v_33067);
    env = stack[-1];
    fn = elt(env, 11); // list2string
    v_33067 = (*qfn1(fn))(fn, v_33067);
    env = stack[-1];
    v_33067 = Lintern(nil, v_33067);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_33067; // space
    v_33067 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 3)) = v_33067; // count
    v_33067 = Lreadch(nil, 0);
    env = stack[-1];
    qvalue(elt(env, 4)) = v_33067; // ch
    v_33067 = nil;
    qvalue(elt(env, 5)) = v_33067; // temp2
    fn = elt(env, 12); // lex
    v_33067 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_33028;
v_33024:
    v_33068 = qvalue(elt(env, 6)); // char
    goto v_33025;
v_33026:
    v_33067 = elt(env, 7); // (m a t h)
    goto v_33027;
v_33028:
    goto v_33024;
v_33025:
    goto v_33026;
v_33027:
    if (equal(v_33068, v_33067)) goto v_33022;
    else goto v_33023;
v_33022:
    fn = elt(env, 13); // mathml
    v_33067 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_33067;
    goto v_33021;
v_33023:
    goto v_33039;
v_33035:
    v_33068 = elt(env, 8); // "<math>"
    goto v_33036;
v_33037:
    v_33067 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_33038;
v_33039:
    goto v_33035;
v_33036:
    goto v_33037;
v_33038:
    fn = elt(env, 14); // errorml
    v_33067 = (*qfn2(fn))(fn, v_33068, v_33067);
    env = stack[-1];
    goto v_33021;
v_33021:
    fn = elt(env, 12); // lex
    v_33067 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_33051;
v_33047:
    v_33068 = qvalue(elt(env, 6)); // char
    goto v_33048;
v_33049:
    v_33067 = elt(env, 9); // (!/ m a t h)
    goto v_33050;
v_33051:
    goto v_33047;
v_33048:
    goto v_33049;
v_33050:
    if (equal(v_33068, v_33067)) goto v_33045;
    else goto v_33046;
v_33045:
    v_33067 = Lterpri(nil, 0);
    env = stack[-1];
    goto v_33044;
v_33046:
    goto v_33062;
v_33058:
    v_33068 = elt(env, 10); // "</math>"
    goto v_33059;
v_33060:
    v_33067 = (LispObject)304+TAG_FIXNUM; // 19
    goto v_33061;
v_33062:
    goto v_33058;
v_33059:
    goto v_33060;
v_33061:
    fn = elt(env, 14); // errorml
    v_33067 = (*qfn2(fn))(fn, v_33068, v_33067);
    env = stack[-1];
    goto v_33044;
v_33044:
    v_33067 = stack[0];
    {
        fn = elt(env, 15); // aeval
        return (*qfn1(fn))(fn, v_33067);
    }
    return onevalue(v_33067);
}



// Code for crprimp

static LispObject CC_crprimp(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33048, v_33049, v_33050;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33050 = v_33004;
// end of prologue
    goto v_33014;
v_33010:
    v_33049 = v_33050;
    goto v_33011;
v_33012:
    v_33048 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33013;
v_33014:
    goto v_33010;
v_33011:
    goto v_33012;
v_33013:
    if (v_33049 == v_33048) goto v_33008;
    else goto v_33009;
v_33008:
    v_33048 = elt(env, 1); // i
    goto v_33007;
v_33009:
    goto v_33024;
v_33020:
    v_33049 = v_33050;
    goto v_33021;
v_33022:
    v_33048 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_33023;
v_33024:
    goto v_33020;
v_33021:
    goto v_33022;
v_33023:
    if (v_33049 == v_33048) goto v_33018;
    else goto v_33019;
v_33018:
    goto v_33032;
v_33028:
    v_33048 = elt(env, 2); // minus
    goto v_33029;
v_33030:
    v_33049 = elt(env, 1); // i
    goto v_33031;
v_33032:
    goto v_33028;
v_33029:
    goto v_33030;
v_33031:
    return list2(v_33048, v_33049);
v_33019:
    goto v_33044;
v_33038:
    v_33048 = elt(env, 3); // times
    goto v_33039;
v_33040:
    v_33049 = v_33050;
    goto v_33041;
v_33042:
    v_33050 = elt(env, 1); // i
    goto v_33043;
v_33044:
    goto v_33038;
v_33039:
    goto v_33040;
v_33041:
    goto v_33042;
v_33043:
    return list3(v_33048, v_33049, v_33050);
    v_33048 = nil;
v_33007:
    return onevalue(v_33048);
}



// Code for mkratnum

static LispObject CC_mkratnum(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33056, v_33057, v_33058;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33004);
    }
// copy arguments values to proper place
    v_33058 = v_33004;
// end of prologue
    v_33056 = v_33058;
    if (!consp(v_33056)) goto v_33008;
    else goto v_33009;
v_33008:
    v_33056 = v_33058;
    {
        fn = elt(env, 4); // !*i2rn
        return (*qfn1(fn))(fn, v_33056);
    }
v_33009:
    goto v_33019;
v_33015:
    v_33056 = v_33058;
    v_33057 = qcar(v_33056);
    goto v_33016;
v_33017:
    v_33056 = elt(env, 1); // !:gi!:
    goto v_33018;
v_33019:
    goto v_33015;
v_33016:
    goto v_33017;
v_33018:
    if (v_33057 == v_33056) goto v_33013;
    else goto v_33014;
v_33013:
    goto v_33028;
v_33024:
    goto v_33034;
v_33030:
    v_33057 = elt(env, 1); // !:gi!:
    goto v_33031;
v_33032:
    v_33056 = elt(env, 2); // !:crn!:
    goto v_33033;
v_33034:
    goto v_33030;
v_33031:
    goto v_33032;
v_33033:
    v_33056 = get(v_33057, v_33056);
    goto v_33025;
v_33026:
    v_33057 = v_33058;
    goto v_33027;
v_33028:
    goto v_33024;
v_33025:
    goto v_33026;
v_33027:
        return Lapply1(nil, v_33056, v_33057);
v_33014:
    goto v_33045;
v_33041:
    goto v_33051;
v_33047:
    v_33056 = v_33058;
    v_33057 = qcar(v_33056);
    goto v_33048;
v_33049:
    v_33056 = elt(env, 3); // !:rn!:
    goto v_33050;
v_33051:
    goto v_33047;
v_33048:
    goto v_33049;
v_33050:
    v_33056 = get(v_33057, v_33056);
    goto v_33042;
v_33043:
    v_33057 = v_33058;
    goto v_33044;
v_33045:
    goto v_33041;
v_33042:
    goto v_33043;
v_33044:
        return Lapply1(nil, v_33056, v_33057);
    v_33056 = nil;
    return onevalue(v_33056);
}



// Code for fast!-augment!-columns

static LispObject CC_fastKaugmentKcolumns(LispObject env,
                         LispObject v_33004, LispObject v_33005)
{
    env = qenv(env);
    LispObject v_33181, v_33182, v_33183;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33005,v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33004,v_33005);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(13);
// copy arguments values to proper place
    stack[-9] = v_33005;
    stack[-10] = v_33004;
// end of prologue
    v_33181 = stack[-10];
    fn = elt(env, 2); // fast!-row!-dim
    v_33181 = (*qfn1(fn))(fn, v_33181);
    env = stack[-12];
    stack[-8] = v_33181;
    v_33181 = stack[-9];
    v_33181 = Llength(nil, v_33181);
    env = stack[-12];
    stack[-6] = v_33181;
    v_33181 = stack[-8];
    v_33181 = sub1(v_33181);
    env = stack[-12];
    v_33181 = Lmkvect(nil, v_33181);
    env = stack[-12];
    stack[-11] = v_33181;
    v_33181 = stack[-9];
    if (!consp(v_33181)) goto v_33024;
    else goto v_33025;
v_33024:
    v_33181 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_33181;
v_33030:
    goto v_33042;
v_33038:
    v_33181 = stack[-8];
    v_33182 = sub1(v_33181);
    env = stack[-12];
    goto v_33039;
v_33040:
    v_33181 = stack[-3];
    goto v_33041;
v_33042:
    goto v_33038;
v_33039:
    goto v_33040;
v_33041:
    v_33181 = difference2(v_33182, v_33181);
    env = stack[-12];
    v_33181 = Lminusp(nil, v_33181);
    env = stack[-12];
    if (v_33181 == nil) goto v_33035;
    goto v_33029;
v_33035:
    v_33181 = (LispObject)0+TAG_FIXNUM; // 0
    v_33181 = Lmkvect(nil, v_33181);
    env = stack[-12];
    stack[-7] = v_33181;
    goto v_33056;
v_33050:
    stack[-2] = stack[-7];
    goto v_33051;
v_33052:
    stack[-1] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33053;
v_33054:
    goto v_33066;
v_33060:
    stack[0] = stack[-10];
    goto v_33061;
v_33062:
    v_33181 = stack[-3];
    v_33182 = add1(v_33181);
    env = stack[-12];
    goto v_33063;
v_33064:
    v_33181 = stack[-9];
    goto v_33065;
v_33066:
    goto v_33060;
v_33061:
    goto v_33062;
v_33063:
    goto v_33064;
v_33065:
    fn = elt(env, 3); // sc_getmat
    v_33181 = (*qfnn(fn))(fn, 3, stack[0], v_33182, v_33181);
    env = stack[-12];
    goto v_33055;
v_33056:
    goto v_33050;
v_33051:
    goto v_33052;
v_33053:
    goto v_33054;
v_33055:
    fn = elt(env, 4); // sc_iputv
    v_33181 = (*qfnn(fn))(fn, 3, stack[-2], stack[-1], v_33181);
    env = stack[-12];
    goto v_33078;
v_33072:
    v_33183 = stack[-11];
    goto v_33073;
v_33074:
    v_33182 = stack[-3];
    goto v_33075;
v_33076:
    v_33181 = stack[-7];
    goto v_33077;
v_33078:
    goto v_33072;
v_33073:
    goto v_33074;
v_33075:
    goto v_33076;
v_33077:
    fn = elt(env, 4); // sc_iputv
    v_33181 = (*qfnn(fn))(fn, 3, v_33183, v_33182, v_33181);
    env = stack[-12];
    v_33181 = stack[-3];
    v_33181 = add1(v_33181);
    env = stack[-12];
    stack[-3] = v_33181;
    goto v_33030;
v_33029:
    goto v_33023;
v_33025:
    v_33181 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_33181;
v_33089:
    goto v_33101;
v_33097:
    v_33181 = stack[-8];
    v_33182 = sub1(v_33181);
    env = stack[-12];
    goto v_33098;
v_33099:
    v_33181 = stack[-5];
    goto v_33100;
v_33101:
    goto v_33097;
v_33098:
    goto v_33099;
v_33100:
    v_33181 = difference2(v_33182, v_33181);
    env = stack[-12];
    v_33181 = Lminusp(nil, v_33181);
    env = stack[-12];
    if (v_33181 == nil) goto v_33094;
    goto v_33088;
v_33094:
    v_33181 = stack[-6];
    v_33181 = sub1(v_33181);
    env = stack[-12];
    v_33181 = Lmkvect(nil, v_33181);
    env = stack[-12];
    stack[-7] = v_33181;
    v_33181 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_33181;
v_33112:
    goto v_33124;
v_33120:
    v_33181 = stack[-6];
    v_33182 = sub1(v_33181);
    env = stack[-12];
    goto v_33121;
v_33122:
    v_33181 = stack[-4];
    goto v_33123;
v_33124:
    goto v_33120;
v_33121:
    goto v_33122;
v_33123:
    v_33181 = difference2(v_33182, v_33181);
    env = stack[-12];
    v_33181 = Lminusp(nil, v_33181);
    env = stack[-12];
    if (v_33181 == nil) goto v_33117;
    goto v_33111;
v_33117:
    goto v_33134;
v_33130:
    stack[0] = stack[-10];
    goto v_33131;
v_33132:
    v_33181 = stack[-5];
    v_33181 = add1(v_33181);
    env = stack[-12];
    goto v_33133;
v_33134:
    goto v_33130;
v_33131:
    goto v_33132;
v_33133:
    fn = elt(env, 5); // sc_getrow
    v_33181 = (*qfn2(fn))(fn, stack[0], v_33181);
    env = stack[-12];
    goto v_33145;
v_33139:
    stack[-3] = stack[-7];
    goto v_33140;
v_33141:
    stack[-2] = stack[-4];
    goto v_33142;
v_33143:
    goto v_33153;
v_33149:
    stack[-1] = v_33181;
    goto v_33150;
v_33151:
    goto v_33161;
v_33157:
    stack[0] = stack[-9];
    goto v_33158;
v_33159:
    v_33181 = stack[-4];
    v_33181 = add1(v_33181);
    env = stack[-12];
    goto v_33160;
v_33161:
    goto v_33157;
v_33158:
    goto v_33159;
v_33160:
    fn = elt(env, 6); // nth
    v_33181 = (*qfn2(fn))(fn, stack[0], v_33181);
    env = stack[-12];
    v_33181 = sub1(v_33181);
    env = stack[-12];
    goto v_33152;
v_33153:
    goto v_33149;
v_33150:
    goto v_33151;
v_33152:
    fn = elt(env, 7); // sc_igetv
    v_33181 = (*qfn2(fn))(fn, stack[-1], v_33181);
    env = stack[-12];
    goto v_33144;
v_33145:
    goto v_33139;
v_33140:
    goto v_33141;
v_33142:
    goto v_33143;
v_33144:
    fn = elt(env, 4); // sc_iputv
    v_33181 = (*qfnn(fn))(fn, 3, stack[-3], stack[-2], v_33181);
    env = stack[-12];
    v_33181 = stack[-4];
    v_33181 = add1(v_33181);
    env = stack[-12];
    stack[-4] = v_33181;
    goto v_33112;
v_33111:
    goto v_33174;
v_33168:
    v_33183 = stack[-11];
    goto v_33169;
v_33170:
    v_33182 = stack[-5];
    goto v_33171;
v_33172:
    v_33181 = stack[-7];
    goto v_33173;
v_33174:
    goto v_33168;
v_33169:
    goto v_33170;
v_33171:
    goto v_33172;
v_33173:
    fn = elt(env, 4); // sc_iputv
    v_33181 = (*qfnn(fn))(fn, 3, v_33183, v_33182, v_33181);
    env = stack[-12];
    v_33181 = stack[-5];
    v_33181 = add1(v_33181);
    env = stack[-12];
    stack[-5] = v_33181;
    goto v_33089;
v_33088:
    goto v_33023;
v_33023:
    v_33181 = stack[-11];
    return onevalue(v_33181);
}



// Code for atlas_edges

static LispObject CC_atlas_edges(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33030;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33004);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33004;
// end of prologue
    goto v_33011;
v_33007:
    goto v_33017;
v_33013:
    v_33030 = stack[0];
    v_33030 = qcar(v_33030);
    fn = elt(env, 1); // map__edges
    stack[-1] = (*qfn1(fn))(fn, v_33030);
    env = stack[-2];
    goto v_33014;
v_33015:
    v_33030 = stack[0];
    v_33030 = qcdr(v_33030);
    v_33030 = qcdr(v_33030);
    v_33030 = qcar(v_33030);
    fn = elt(env, 2); // den__edges
    v_33030 = (*qfn1(fn))(fn, v_33030);
    env = stack[-2];
    goto v_33016;
v_33017:
    goto v_33013;
v_33014:
    goto v_33015;
v_33016:
    fn = elt(env, 3); // union_edges
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_33030);
    env = stack[-2];
    goto v_33008;
v_33009:
    v_33030 = stack[0];
    v_33030 = qcdr(v_33030);
    v_33030 = qcar(v_33030);
    fn = elt(env, 4); // coeff_edges
    v_33030 = (*qfn1(fn))(fn, v_33030);
    env = stack[-2];
    goto v_33010;
v_33011:
    goto v_33007;
v_33008:
    goto v_33009;
v_33010:
    {
        LispObject v_33033 = stack[-1];
        fn = elt(env, 3); // union_edges
        return (*qfn2(fn))(fn, v_33033, v_33030);
    }
}



// Code for compactf3

static LispObject CC_compactf3(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33038, v_33039, v_33040;
    LispObject fn;
    LispObject v_33006, v_33005, v_33004;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "compactf3");
    va_start(aa, nargs);
    v_33004 = va_arg(aa, LispObject);
    v_33005 = va_arg(aa, LispObject);
    v_33006 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_33006,v_33005,v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_33004,v_33005,v_33006);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_33006;
    stack[-1] = v_33005;
    v_33039 = v_33004;
// end of prologue
// Binding mv!-vars!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = nil; // mv!-vars!*
    v_33038 = stack[0];
    qvalue(elt(env, 1)) = v_33038; // mv!-vars!*
    goto v_33018;
v_33014:
    goto v_33026;
v_33020:
    goto v_33032;
v_33028:
    goto v_33029;
v_33030:
    v_33038 = stack[0];
    goto v_33031;
v_33032:
    goto v_33028;
v_33029:
    goto v_33030;
v_33031:
    fn = elt(env, 3); // sf2mv
    v_33040 = (*qfn2(fn))(fn, v_33039, v_33038);
    env = stack[-3];
    goto v_33021;
v_33022:
    v_33039 = stack[-1];
    goto v_33023;
v_33024:
    v_33038 = nil;
    goto v_33025;
v_33026:
    goto v_33020;
v_33021:
    goto v_33022;
v_33023:
    goto v_33024;
v_33025:
    fn = elt(env, 4); // mv!-compact
    v_33039 = (*qfnn(fn))(fn, 3, v_33040, v_33039, v_33038);
    env = stack[-3];
    goto v_33015;
v_33016:
    v_33038 = stack[0];
    goto v_33017;
v_33018:
    goto v_33014;
v_33015:
    goto v_33016;
v_33017:
    fn = elt(env, 5); // mv2sf
    v_33038 = (*qfn2(fn))(fn, v_33039, v_33038);
    ;}  // end of a binding scope
    return onevalue(v_33038);
}



// Code for dpmat_gbtag

static LispObject CC_dpmat_gbtag(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33014, v_33015;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33014 = v_33004;
// end of prologue
    goto v_33011;
v_33007:
    v_33015 = v_33014;
    goto v_33008;
v_33009:
    v_33014 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_33010;
v_33011:
    goto v_33007;
v_33008:
    goto v_33009;
v_33010:
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(fn, v_33015, v_33014);
    }
}



// Code for !*v2j

static LispObject CC_Hv2j(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33042, v_33043, v_33044;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33004);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33044 = v_33004;
// end of prologue
    goto v_33014;
v_33010:
    v_33043 = qvalue(elt(env, 1)); // ordering
    goto v_33011;
v_33012:
    v_33042 = elt(env, 2); // lex
    goto v_33013;
v_33014:
    goto v_33010;
v_33011:
    goto v_33012;
v_33013:
    if (v_33043 == v_33042) goto v_33008;
    else goto v_33009;
v_33008:
    goto v_33022;
v_33018:
    v_33043 = v_33044;
    goto v_33019;
v_33020:
    v_33042 = qvalue(elt(env, 3)); // varlist!*
    goto v_33021;
v_33022:
    goto v_33018;
v_33019:
    goto v_33020;
v_33021:
    {
        fn = elt(env, 4); // sub01
        return (*qfn2(fn))(fn, v_33043, v_33042);
    }
v_33009:
    goto v_33032;
v_33028:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33029;
v_33030:
    goto v_33039;
v_33035:
    v_33043 = v_33044;
    goto v_33036;
v_33037:
    v_33042 = qvalue(elt(env, 3)); // varlist!*
    goto v_33038;
v_33039:
    goto v_33035;
v_33036:
    goto v_33037;
v_33038:
    fn = elt(env, 4); // sub01
    v_33042 = (*qfn2(fn))(fn, v_33043, v_33042);
    goto v_33031;
v_33032:
    goto v_33028;
v_33029:
    goto v_33030;
v_33031:
    {
        LispObject v_33046 = stack[0];
        return cons(v_33046, v_33042);
    }
    v_33042 = nil;
    return onevalue(v_33042);
}



// Code for dummy_nam

static LispObject CC_dummy_nam(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33016, v_33017;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33004);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33016 = v_33004;
// end of prologue
    goto v_33011;
v_33007:
    fn = elt(env, 3); // ordn
    v_33017 = (*qfn1(fn))(fn, v_33016);
    env = stack[0];
    goto v_33008;
v_33009:
    v_33016 = elt(env, 1); // symbolic
    goto v_33010;
v_33011:
    goto v_33007;
v_33008:
    goto v_33009;
v_33010:
    fn = elt(env, 4); // list2vect!*
    v_33016 = (*qfn2(fn))(fn, v_33017, v_33016);
    env = stack[0];
    qvalue(elt(env, 2)) = v_33016; // g_dvnames
    v_33016 = lisp_true;
    return onevalue(v_33016);
}



// Code for general!-negate!-term

static LispObject CC_generalKnegateKterm(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33017, v_33018;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33004);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33018 = v_33004;
// end of prologue
    goto v_33011;
v_33007:
    v_33017 = v_33018;
    stack[0] = qcar(v_33017);
    goto v_33008;
v_33009:
    v_33017 = v_33018;
    v_33017 = qcdr(v_33017);
    fn = elt(env, 1); // general!-minus!-mod!-p
    v_33017 = (*qfn1(fn))(fn, v_33017);
    goto v_33010;
v_33011:
    goto v_33007;
v_33008:
    goto v_33009;
v_33010:
    {
        LispObject v_33020 = stack[0];
        return cons(v_33020, v_33017);
    }
}



// Code for cr2rderr

static LispObject CC_cr2rderr(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33013, v_33014;
    LispObject fn;
    argcheck(nargs, 0, "cr2rderr");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    goto v_33010;
v_33006:
    v_33014 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33007;
v_33008:
    v_33013 = elt(env, 1); // "complex to real type conversion requires zero imaginary part"
    goto v_33009;
v_33010:
    goto v_33006;
v_33007:
    goto v_33008;
v_33009:
    {
        fn = elt(env, 2); // error
        return (*qfn2(fn))(fn, v_33014, v_33013);
    }
}



// Code for sort_according_to

static LispObject CC_sort_according_to(LispObject env,
                         LispObject v_33004, LispObject v_33005)
{
    env = qenv(env);
    LispObject v_33050, v_33051, v_33052, v_33053;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33005,v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33004,v_33005);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_33050 = v_33005;
    stack[0] = v_33004;
// end of prologue
    v_33053 = nil;
    stack[-1] = v_33050;
v_33015:
    v_33050 = stack[-1];
    if (v_33050 == nil) goto v_33019;
    else goto v_33020;
v_33019:
    goto v_33014;
v_33020:
    v_33050 = stack[-1];
    v_33050 = qcar(v_33050);
    v_33052 = v_33050;
    goto v_33034;
v_33030:
    v_33051 = v_33052;
    goto v_33031;
v_33032:
    v_33050 = stack[0];
    goto v_33033;
v_33034:
    goto v_33030;
v_33031:
    goto v_33032;
v_33033:
    v_33050 = Lmember(nil, v_33051, v_33050);
    if (v_33050 == nil) goto v_33029;
    goto v_33043;
v_33039:
    v_33050 = v_33052;
    goto v_33040;
v_33041:
    v_33051 = v_33053;
    goto v_33042;
v_33043:
    goto v_33039;
v_33040:
    goto v_33041;
v_33042:
    v_33050 = cons(v_33050, v_33051);
    env = stack[-2];
    v_33053 = v_33050;
    goto v_33027;
v_33029:
v_33027:
    v_33050 = stack[-1];
    v_33050 = qcdr(v_33050);
    stack[-1] = v_33050;
    goto v_33015;
v_33014:
    v_33050 = v_33053;
        return Lreverse(nil, v_33050);
    return onevalue(v_33050);
}



// Code for square!-free!-mod!-p

static LispObject CC_squareKfreeKmodKp(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33045, v_33046;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33004);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_33046 = v_33004;
// end of prologue
    v_33045 = v_33046;
    if (!consp(v_33045)) goto v_33012;
    else goto v_33013;
v_33012:
    v_33045 = lisp_true;
    goto v_33011;
v_33013:
    v_33045 = v_33046;
    v_33045 = qcar(v_33045);
    v_33045 = (consp(v_33045) ? nil : lisp_true);
    goto v_33011;
    v_33045 = nil;
v_33011:
    if (v_33045 == nil) goto v_33009;
    v_33045 = lisp_true;
    goto v_33007;
v_33009:
    goto v_33029;
v_33025:
    stack[0] = v_33046;
    goto v_33026;
v_33027:
    v_33045 = v_33046;
    fn = elt(env, 1); // derivative!-mod!-p
    v_33045 = (*qfn1(fn))(fn, v_33045);
    env = stack[-1];
    goto v_33028;
v_33029:
    goto v_33025;
v_33026:
    goto v_33027;
v_33028:
    fn = elt(env, 2); // gcd!-mod!-p
    v_33045 = (*qfn2(fn))(fn, stack[0], v_33045);
    v_33046 = v_33045;
    v_33045 = v_33046;
    if (!consp(v_33045)) goto v_33036;
    else goto v_33037;
v_33036:
    v_33045 = lisp_true;
    goto v_33035;
v_33037:
    v_33045 = v_33046;
    v_33045 = qcar(v_33045);
    v_33045 = (consp(v_33045) ? nil : lisp_true);
    goto v_33035;
    v_33045 = nil;
v_33035:
    goto v_33007;
    v_33045 = nil;
v_33007:
    return onevalue(v_33045);
}



// Code for initmonomials

static LispObject CC_initmonomials(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33046, v_33047;
    LispObject fn;
    argcheck(nargs, 0, "initmonomials");
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
    v_33046 = qvalue(elt(env, 1)); // fluidbibasisvariables
    v_33046 = Llength(nil, v_33046);
    env = stack[-3];
    qvalue(elt(env, 2)) = v_33046; // fluidbibasisnumberofvariables
    v_33046 = qvalue(elt(env, 2)); // fluidbibasisnumberofvariables
    v_33046 = Lmkvect(nil, v_33046);
    env = stack[-3];
    qvalue(elt(env, 3)) = v_33046; // fluidbibasissinglevariablemonomialss
    v_33046 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_33046;
v_33015:
    goto v_33027;
v_33023:
    v_33047 = qvalue(elt(env, 2)); // fluidbibasisnumberofvariables
    goto v_33024;
v_33025:
    v_33046 = stack[-2];
    goto v_33026;
v_33027:
    goto v_33023;
v_33024:
    goto v_33025;
v_33026:
    v_33046 = difference2(v_33047, v_33046);
    env = stack[-3];
    v_33046 = Lminusp(nil, v_33046);
    env = stack[-3];
    if (v_33046 == nil) goto v_33020;
    goto v_33014;
v_33020:
    goto v_33037;
v_33031:
    stack[-1] = qvalue(elt(env, 3)); // fluidbibasissinglevariablemonomialss
    goto v_33032;
v_33033:
    stack[0] = stack[-2];
    goto v_33034;
v_33035:
    v_33046 = stack[-2];
    fn = elt(env, 5); // createsinglevariablemonom
    v_33046 = (*qfn1(fn))(fn, v_33046);
    env = stack[-3];
    goto v_33036;
v_33037:
    goto v_33031;
v_33032:
    goto v_33033;
v_33034:
    goto v_33035;
v_33036:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_33046;
    v_33046 = stack[-2];
    v_33046 = add1(v_33046);
    env = stack[-3];
    stack[-2] = v_33046;
    goto v_33015;
v_33014:
    v_33046 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 4)) = v_33046; // fluidbibasistripleid
    v_33046 = nil;
    return onevalue(v_33046);
}



// Code for ofsf_exploitknowl

static LispObject CC_ofsf_exploitknowl(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33372, v_33373, v_33374, v_33375;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33004);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(13);
// copy arguments values to proper place
    v_33372 = v_33004;
// end of prologue
    stack[-11] = nil;
    stack[-10] = nil;
    stack[-9] = nil;
    stack[-8] = nil;
    stack[-7] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-1] = v_33372;
v_33024:
    v_33372 = stack[-1];
    if (v_33372 == nil) goto v_33028;
    else goto v_33029;
v_33028:
    goto v_33023;
v_33029:
    v_33372 = stack[-1];
    v_33372 = qcar(v_33372);
    stack[0] = v_33372;
    v_33372 = stack[0];
    v_33372 = qcar(v_33372);
    fn = elt(env, 9); // sfto_varp
    v_33372 = (*qfn1(fn))(fn, v_33372);
    env = stack[-12];
    stack[-4] = v_33372;
    if (v_33372 == nil) goto v_33038;
    v_33372 = stack[0];
    v_33372 = qcdr(v_33372);
    stack[0] = v_33372;
v_33045:
    v_33372 = stack[0];
    if (v_33372 == nil) goto v_33050;
    else goto v_33051;
v_33050:
    goto v_33044;
v_33051:
    v_33372 = stack[0];
    v_33372 = qcar(v_33372);
    v_33372 = qcdr(v_33372);
    v_33373 = v_33372;
    v_33372 = v_33373;
    v_33372 = qcar(v_33372);
    stack[-3] = v_33372;
    v_33372 = v_33373;
    v_33372 = qcdr(v_33372);
    v_33373 = v_33372;
    v_33372 = v_33373;
    fn = elt(env, 10); // negsq
    v_33372 = (*qfn1(fn))(fn, v_33372);
    env = stack[-12];
    v_33373 = v_33372;
    v_33372 = v_33373;
    v_33372 = qcar(v_33372);
    if (v_33372 == nil) goto v_33071;
    else goto v_33070;
v_33071:
    v_33372 = (LispObject)0+TAG_FIXNUM; // 0
v_33070:
    stack[-2] = v_33372;
    goto v_33083;
v_33079:
    v_33374 = stack[-3];
    goto v_33080;
v_33081:
    v_33372 = elt(env, 2); // equal
    goto v_33082;
v_33083:
    goto v_33079;
v_33080:
    goto v_33081;
v_33082:
    if (v_33374 == v_33372) goto v_33077;
    else goto v_33078;
v_33077:
    v_33372 = qvalue(elt(env, 3)); // !*rlsippsubst
    if (v_33372 == nil) goto v_33089;
    goto v_33098;
v_33092:
    v_33374 = stack[-4];
    goto v_33093;
v_33094:
    goto v_33095;
v_33096:
    v_33372 = stack[-11];
    goto v_33097;
v_33098:
    goto v_33092;
v_33093:
    goto v_33094;
v_33095:
    goto v_33096;
v_33097:
    v_33372 = acons(v_33374, v_33373, v_33372);
    env = stack[-12];
    stack[-11] = v_33372;
    goto v_33087;
v_33089:
    goto v_33113;
v_33109:
    v_33373 = stack[-2];
    goto v_33110;
v_33111:
    v_33372 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33112;
v_33113:
    goto v_33109;
v_33110:
    goto v_33111;
v_33112:
    v_33372 = (LispObject)greaterp2(v_33373, v_33372);
    v_33372 = v_33372 ? lisp_true : nil;
    env = stack[-12];
    if (v_33372 == nil) goto v_33107;
    goto v_33121;
v_33117:
    v_33373 = stack[-4];
    goto v_33118;
v_33119:
    v_33372 = stack[-9];
    goto v_33120;
v_33121:
    goto v_33117;
v_33118:
    goto v_33119;
v_33120:
    fn = elt(env, 11); // lto_insertq
    v_33372 = (*qfn2(fn))(fn, v_33373, v_33372);
    env = stack[-12];
    stack[-9] = v_33372;
    goto v_33105;
v_33107:
    goto v_33131;
v_33127:
    v_33373 = stack[-2];
    goto v_33128;
v_33129:
    v_33372 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33130;
v_33131:
    goto v_33127;
v_33128:
    goto v_33129;
v_33130:
    v_33372 = (LispObject)lessp2(v_33373, v_33372);
    v_33372 = v_33372 ? lisp_true : nil;
    env = stack[-12];
    if (v_33372 == nil) goto v_33125;
    goto v_33139;
v_33135:
    v_33373 = stack[-4];
    goto v_33136;
v_33137:
    v_33372 = stack[-8];
    goto v_33138;
v_33139:
    goto v_33135;
v_33136:
    goto v_33137;
v_33138:
    fn = elt(env, 11); // lto_insertq
    v_33372 = (*qfn2(fn))(fn, v_33373, v_33372);
    env = stack[-12];
    stack[-8] = v_33372;
    goto v_33105;
v_33125:
    goto v_33149;
v_33145:
    v_33373 = stack[-2];
    goto v_33146;
v_33147:
    v_33372 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33148;
v_33149:
    goto v_33145;
v_33146:
    goto v_33147;
v_33148:
    v_33372 = Leqn(nil, v_33373, v_33372);
    env = stack[-12];
    if (v_33372 == nil) goto v_33143;
    goto v_33157;
v_33153:
    v_33373 = stack[-4];
    goto v_33154;
v_33155:
    v_33372 = stack[-10];
    goto v_33156;
v_33157:
    goto v_33153;
v_33154:
    goto v_33155;
v_33156:
    fn = elt(env, 11); // lto_insertq
    v_33372 = (*qfn2(fn))(fn, v_33373, v_33372);
    env = stack[-12];
    stack[-10] = v_33372;
    goto v_33105;
v_33143:
v_33105:
    goto v_33087;
v_33087:
    goto v_33076;
v_33078:
    goto v_33166;
v_33162:
    v_33373 = stack[-3];
    goto v_33163;
v_33164:
    v_33372 = elt(env, 4); // greaterp
    goto v_33165;
v_33166:
    goto v_33162;
v_33163:
    goto v_33164;
v_33165:
    if (v_33373 == v_33372) goto v_33160;
    else goto v_33161;
v_33160:
    goto v_33178;
v_33174:
    v_33373 = stack[-2];
    goto v_33175;
v_33176:
    v_33372 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33177;
v_33178:
    goto v_33174;
v_33175:
    goto v_33176;
v_33177:
    v_33372 = (LispObject)geq2(v_33373, v_33372);
    v_33372 = v_33372 ? lisp_true : nil;
    env = stack[-12];
    if (v_33372 == nil) goto v_33172;
    goto v_33186;
v_33182:
    v_33373 = stack[-4];
    goto v_33183;
v_33184:
    v_33372 = stack[-9];
    goto v_33185;
v_33186:
    goto v_33182;
v_33183:
    goto v_33184;
v_33185:
    fn = elt(env, 11); // lto_insertq
    v_33372 = (*qfn2(fn))(fn, v_33373, v_33372);
    env = stack[-12];
    stack[-9] = v_33372;
    goto v_33170;
v_33172:
v_33170:
    goto v_33076;
v_33161:
    goto v_33195;
v_33191:
    v_33373 = stack[-3];
    goto v_33192;
v_33193:
    v_33372 = elt(env, 5); // geq
    goto v_33194;
v_33195:
    goto v_33191;
v_33192:
    goto v_33193;
v_33194:
    if (v_33373 == v_33372) goto v_33189;
    else goto v_33190;
v_33189:
    goto v_33207;
v_33203:
    v_33373 = stack[-2];
    goto v_33204;
v_33205:
    v_33372 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33206;
v_33207:
    goto v_33203;
v_33204:
    goto v_33205;
v_33206:
    v_33372 = (LispObject)greaterp2(v_33373, v_33372);
    v_33372 = v_33372 ? lisp_true : nil;
    env = stack[-12];
    if (v_33372 == nil) goto v_33201;
    goto v_33215;
v_33211:
    v_33373 = stack[-4];
    goto v_33212;
v_33213:
    v_33372 = stack[-9];
    goto v_33214;
v_33215:
    goto v_33211;
v_33212:
    goto v_33213;
v_33214:
    fn = elt(env, 11); // lto_insertq
    v_33372 = (*qfn2(fn))(fn, v_33373, v_33372);
    env = stack[-12];
    stack[-9] = v_33372;
    goto v_33199;
v_33201:
    goto v_33225;
v_33221:
    v_33373 = stack[-2];
    goto v_33222;
v_33223:
    v_33372 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33224;
v_33225:
    goto v_33221;
v_33222:
    goto v_33223;
v_33224:
    v_33372 = Leqn(nil, v_33373, v_33372);
    env = stack[-12];
    if (v_33372 == nil) goto v_33219;
    goto v_33233;
v_33229:
    v_33373 = stack[-4];
    goto v_33230;
v_33231:
    v_33372 = stack[-7];
    goto v_33232;
v_33233:
    goto v_33229;
v_33230:
    goto v_33231;
v_33232:
    fn = elt(env, 11); // lto_insertq
    v_33372 = (*qfn2(fn))(fn, v_33373, v_33372);
    env = stack[-12];
    stack[-7] = v_33372;
    goto v_33199;
v_33219:
v_33199:
    goto v_33076;
v_33190:
    goto v_33242;
v_33238:
    v_33373 = stack[-3];
    goto v_33239;
v_33240:
    v_33372 = elt(env, 6); // lessp
    goto v_33241;
v_33242:
    goto v_33238;
v_33239:
    goto v_33240;
v_33241:
    if (v_33373 == v_33372) goto v_33236;
    else goto v_33237;
v_33236:
    goto v_33254;
v_33250:
    v_33373 = stack[-2];
    goto v_33251;
v_33252:
    v_33372 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33253;
v_33254:
    goto v_33250;
v_33251:
    goto v_33252;
v_33253:
    v_33372 = (LispObject)lesseq2(v_33373, v_33372);
    v_33372 = v_33372 ? lisp_true : nil;
    env = stack[-12];
    if (v_33372 == nil) goto v_33248;
    goto v_33262;
v_33258:
    v_33373 = stack[-4];
    goto v_33259;
v_33260:
    v_33372 = stack[-8];
    goto v_33261;
v_33262:
    goto v_33258;
v_33259:
    goto v_33260;
v_33261:
    fn = elt(env, 11); // lto_insertq
    v_33372 = (*qfn2(fn))(fn, v_33373, v_33372);
    env = stack[-12];
    stack[-8] = v_33372;
    goto v_33246;
v_33248:
v_33246:
    goto v_33076;
v_33237:
    goto v_33271;
v_33267:
    v_33373 = stack[-3];
    goto v_33268;
v_33269:
    v_33372 = elt(env, 7); // leq
    goto v_33270;
v_33271:
    goto v_33267;
v_33268:
    goto v_33269;
v_33270:
    if (v_33373 == v_33372) goto v_33265;
    else goto v_33266;
v_33265:
    goto v_33283;
v_33279:
    v_33373 = stack[-2];
    goto v_33280;
v_33281:
    v_33372 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33282;
v_33283:
    goto v_33279;
v_33280:
    goto v_33281;
v_33282:
    v_33372 = (LispObject)lessp2(v_33373, v_33372);
    v_33372 = v_33372 ? lisp_true : nil;
    env = stack[-12];
    if (v_33372 == nil) goto v_33277;
    goto v_33291;
v_33287:
    v_33373 = stack[-4];
    goto v_33288;
v_33289:
    v_33372 = stack[-8];
    goto v_33290;
v_33291:
    goto v_33287;
v_33288:
    goto v_33289;
v_33290:
    fn = elt(env, 11); // lto_insertq
    v_33372 = (*qfn2(fn))(fn, v_33373, v_33372);
    env = stack[-12];
    stack[-8] = v_33372;
    goto v_33275;
v_33277:
    goto v_33301;
v_33297:
    v_33373 = stack[-2];
    goto v_33298;
v_33299:
    v_33372 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33300;
v_33301:
    goto v_33297;
v_33298:
    goto v_33299;
v_33300:
    v_33372 = Leqn(nil, v_33373, v_33372);
    env = stack[-12];
    if (v_33372 == nil) goto v_33295;
    goto v_33309;
v_33305:
    v_33373 = stack[-4];
    goto v_33306;
v_33307:
    v_33372 = stack[-6];
    goto v_33308;
v_33309:
    goto v_33305;
v_33306:
    goto v_33307;
v_33308:
    fn = elt(env, 11); // lto_insertq
    v_33372 = (*qfn2(fn))(fn, v_33373, v_33372);
    env = stack[-12];
    stack[-6] = v_33372;
    goto v_33275;
v_33295:
v_33275:
    goto v_33076;
v_33266:
    goto v_33318;
v_33314:
    v_33373 = stack[-3];
    goto v_33315;
v_33316:
    v_33372 = elt(env, 8); // neq
    goto v_33317;
v_33318:
    goto v_33314;
v_33315:
    goto v_33316;
v_33317:
    if (v_33373 == v_33372) goto v_33312;
    else goto v_33313;
v_33312:
    goto v_33330;
v_33326:
    v_33373 = stack[-2];
    goto v_33327;
v_33328:
    v_33372 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33329;
v_33330:
    goto v_33326;
v_33327:
    goto v_33328;
v_33329:
    v_33372 = Leqn(nil, v_33373, v_33372);
    env = stack[-12];
    if (v_33372 == nil) goto v_33324;
    goto v_33338;
v_33334:
    v_33373 = stack[-4];
    goto v_33335;
v_33336:
    v_33372 = stack[-5];
    goto v_33337;
v_33338:
    goto v_33334;
v_33335:
    goto v_33336;
v_33337:
    fn = elt(env, 11); // lto_insertq
    v_33372 = (*qfn2(fn))(fn, v_33373, v_33372);
    env = stack[-12];
    stack[-5] = v_33372;
    goto v_33322;
v_33324:
v_33322:
    goto v_33076;
v_33313:
v_33076:
    v_33372 = stack[0];
    v_33372 = qcdr(v_33372);
    stack[0] = v_33372;
    goto v_33045;
v_33044:
    goto v_33036;
v_33038:
v_33036:
    v_33372 = stack[-1];
    v_33372 = qcdr(v_33372);
    stack[-1] = v_33372;
    goto v_33024;
v_33023:
    goto v_33354;
v_33346:
    stack[0] = stack[-11];
    goto v_33347;
v_33348:
    stack[-1] = stack[-10];
    goto v_33349;
v_33350:
    stack[-2] = stack[-9];
    goto v_33351;
v_33352:
    goto v_33367;
v_33359:
    v_33375 = stack[-8];
    goto v_33360;
v_33361:
    v_33374 = stack[-7];
    goto v_33362;
v_33363:
    v_33373 = stack[-6];
    goto v_33364;
v_33365:
    v_33372 = stack[-5];
    goto v_33366;
v_33367:
    goto v_33359;
v_33360:
    goto v_33361;
v_33362:
    goto v_33363;
v_33364:
    goto v_33365;
v_33366:
    v_33372 = list4(v_33375, v_33374, v_33373, v_33372);
    goto v_33353;
v_33354:
    goto v_33346;
v_33347:
    goto v_33348;
v_33349:
    goto v_33350;
v_33351:
    goto v_33352;
v_33353:
    {
        LispObject v_33388 = stack[0];
        LispObject v_33389 = stack[-1];
        LispObject v_33390 = stack[-2];
        return list3star(v_33388, v_33389, v_33390, v_33372);
    }
    return onevalue(v_33372);
}



// Code for depend!-p

static LispObject CC_dependKp(LispObject env,
                         LispObject v_33004, LispObject v_33005)
{
    env = qenv(env);
    LispObject v_33066, v_33067, v_33068, v_33069;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33068 = v_33005;
    v_33069 = v_33004;
// end of prologue
    goto v_33015;
v_33011:
    v_33067 = v_33069;
    goto v_33012;
v_33013:
    v_33066 = v_33068;
    goto v_33014;
v_33015:
    goto v_33011;
v_33012:
    goto v_33013;
v_33014:
    if (v_33067 == v_33066) goto v_33009;
    else goto v_33010;
v_33009:
    v_33066 = lisp_true;
    goto v_33008;
v_33010:
    v_33066 = v_33069;
    if (!consp(v_33066)) goto v_33019;
    else goto v_33020;
v_33019:
    v_33066 = nil;
    goto v_33008;
v_33020:
    v_33066 = v_33069;
    v_33066 = qcar(v_33066);
    if (!consp(v_33066)) goto v_33024;
    goto v_33032;
v_33028:
    v_33066 = v_33069;
    goto v_33029;
v_33030:
    v_33067 = v_33068;
    goto v_33031;
v_33032:
    goto v_33028;
v_33029:
    goto v_33030;
v_33031:
    {
        fn = elt(env, 2); // depend!-f
        return (*qfn2(fn))(fn, v_33066, v_33067);
    }
v_33024:
    goto v_33041;
v_33037:
    v_33066 = v_33069;
    v_33067 = qcar(v_33066);
    goto v_33038;
v_33039:
    v_33066 = elt(env, 1); // !*sq
    goto v_33040;
v_33041:
    goto v_33037;
v_33038:
    goto v_33039;
v_33040:
    if (v_33067 == v_33066) goto v_33035;
    else goto v_33036;
v_33035:
    goto v_33050;
v_33046:
    v_33066 = v_33069;
    v_33066 = qcdr(v_33066);
    v_33066 = qcar(v_33066);
    goto v_33047;
v_33048:
    v_33067 = v_33068;
    goto v_33049;
v_33050:
    goto v_33046;
v_33047:
    goto v_33048;
v_33049:
    {
        fn = elt(env, 3); // depend!-sq
        return (*qfn2(fn))(fn, v_33066, v_33067);
    }
v_33036:
    goto v_33062;
v_33058:
    v_33066 = v_33069;
    v_33066 = qcdr(v_33066);
    goto v_33059;
v_33060:
    v_33067 = v_33068;
    goto v_33061;
v_33062:
    goto v_33058;
v_33059:
    goto v_33060;
v_33061:
    {
        fn = elt(env, 4); // depend!-l
        return (*qfn2(fn))(fn, v_33066, v_33067);
    }
    v_33066 = nil;
v_33008:
    return onevalue(v_33066);
}



// Code for ofsf_simpat

static LispObject CC_ofsf_simpat(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33287, v_33288, v_33289;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33004);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_33004;
// end of prologue
    v_33287 = stack[-2];
    v_33287 = qcar(v_33287);
    stack[-3] = v_33287;
    v_33287 = stack[-2];
    v_33287 = qcdr(v_33287);
    v_33287 = qcar(v_33287);
    fn = elt(env, 10); // simp
    v_33287 = (*qfn1(fn))(fn, v_33287);
    env = stack[-4];
    stack[-1] = v_33287;
    v_33287 = qvalue(elt(env, 2)); // !*rlnzden
    if (v_33287 == nil) goto v_33024;
    else goto v_33023;
v_33024:
    v_33287 = qvalue(elt(env, 3)); // !*rlposden
    if (v_33287 == nil) goto v_33027;
    else goto v_33023;
v_33027:
    v_33287 = stack[-1];
    v_33287 = qcdr(v_33287);
    if (!consp(v_33287)) goto v_33032;
    else goto v_33033;
v_33032:
    v_33287 = lisp_true;
    goto v_33031;
v_33033:
    v_33287 = stack[-1];
    v_33287 = qcdr(v_33287);
    v_33287 = qcar(v_33287);
    v_33287 = (consp(v_33287) ? nil : lisp_true);
    goto v_33031;
    v_33287 = nil;
v_33031:
    if (v_33287 == nil) goto v_33029;
    else goto v_33023;
v_33029:
    goto v_33048;
v_33044:
    v_33288 = stack[-2];
    goto v_33045;
v_33046:
    v_33287 = elt(env, 4); // "atomic formula"
    goto v_33047;
v_33048:
    goto v_33044;
v_33045:
    goto v_33046;
v_33047:
    fn = elt(env, 11); // typerr
    v_33287 = (*qfn2(fn))(fn, v_33288, v_33287);
    env = stack[-4];
    goto v_33021;
v_33023:
v_33021:
    v_33287 = stack[-2];
    v_33287 = qcdr(v_33287);
    v_33287 = qcdr(v_33287);
    v_33287 = qcar(v_33287);
    fn = elt(env, 10); // simp
    v_33287 = (*qfn1(fn))(fn, v_33287);
    env = stack[-4];
    stack[0] = v_33287;
    v_33287 = qvalue(elt(env, 2)); // !*rlnzden
    if (v_33287 == nil) goto v_33060;
    else goto v_33059;
v_33060:
    v_33287 = qvalue(elt(env, 3)); // !*rlposden
    if (v_33287 == nil) goto v_33063;
    else goto v_33059;
v_33063:
    v_33287 = stack[0];
    v_33287 = qcdr(v_33287);
    if (!consp(v_33287)) goto v_33068;
    else goto v_33069;
v_33068:
    v_33287 = lisp_true;
    goto v_33067;
v_33069:
    v_33287 = stack[0];
    v_33287 = qcdr(v_33287);
    v_33287 = qcar(v_33287);
    v_33287 = (consp(v_33287) ? nil : lisp_true);
    goto v_33067;
    v_33287 = nil;
v_33067:
    if (v_33287 == nil) goto v_33065;
    else goto v_33059;
v_33065:
    goto v_33084;
v_33080:
    v_33288 = stack[-2];
    goto v_33081;
v_33082:
    v_33287 = elt(env, 4); // "atomic formula"
    goto v_33083;
v_33084:
    goto v_33080;
v_33081:
    goto v_33082;
v_33083:
    fn = elt(env, 11); // typerr
    v_33287 = (*qfn2(fn))(fn, v_33288, v_33287);
    env = stack[-4];
    goto v_33057;
v_33059:
v_33057:
    goto v_33092;
v_33088:
    goto v_33089;
v_33090:
    v_33287 = stack[0];
    fn = elt(env, 12); // negsq
    v_33287 = (*qfn1(fn))(fn, v_33287);
    env = stack[-4];
    goto v_33091;
v_33092:
    goto v_33088;
v_33089:
    goto v_33090;
v_33091:
    fn = elt(env, 13); // addsq
    v_33287 = (*qfn2(fn))(fn, stack[-1], v_33287);
    env = stack[-4];
    stack[-1] = v_33287;
    v_33287 = stack[-1];
    v_33287 = qcar(v_33287);
    v_33288 = v_33287;
    v_33287 = qvalue(elt(env, 3)); // !*rlposden
    if (v_33287 == nil) goto v_33101;
    v_33287 = stack[-1];
    v_33287 = qcdr(v_33287);
    if (!consp(v_33287)) goto v_33107;
    else goto v_33108;
v_33107:
    v_33287 = lisp_true;
    goto v_33106;
v_33108:
    v_33287 = stack[-1];
    v_33287 = qcdr(v_33287);
    v_33287 = qcar(v_33287);
    v_33287 = (consp(v_33287) ? nil : lisp_true);
    goto v_33106;
    v_33287 = nil;
v_33106:
    if (v_33287 == nil) goto v_33104;
    else goto v_33101;
v_33104:
    goto v_33125;
v_33119:
    v_33289 = stack[-3];
    goto v_33120;
v_33121:
    goto v_33122;
v_33123:
    v_33287 = nil;
    goto v_33124;
v_33125:
    goto v_33119;
v_33120:
    goto v_33121;
v_33122:
    goto v_33123;
v_33124:
    v_33287 = list3(v_33289, v_33288, v_33287);
    env = stack[-4];
    stack[0] = v_33287;
    v_33287 = qvalue(elt(env, 5)); // !*rladdcond
    if (v_33287 == nil) goto v_33132;
    goto v_33142;
v_33138:
    v_33288 = stack[-3];
    goto v_33139;
v_33140:
    v_33287 = elt(env, 6); // (lessp leq greaterp geq)
    goto v_33141;
v_33142:
    goto v_33138;
v_33139:
    goto v_33140;
v_33141:
    v_33287 = Lmemq(nil, v_33288, v_33287);
    if (v_33287 == nil) goto v_33137;
    goto v_33153;
v_33147:
    stack[-2] = elt(env, 7); // and
    goto v_33148;
v_33149:
    goto v_33162;
v_33156:
    v_33289 = elt(env, 8); // greaterp
    goto v_33157;
v_33158:
    v_33287 = stack[-1];
    v_33288 = qcdr(v_33287);
    goto v_33159;
v_33160:
    v_33287 = nil;
    goto v_33161;
v_33162:
    goto v_33156;
v_33157:
    goto v_33158;
v_33159:
    goto v_33160;
v_33161:
    stack[-1] = list3(v_33289, v_33288, v_33287);
    env = stack[-4];
    goto v_33150;
v_33151:
    v_33287 = stack[0];
    v_33287 = ncons(v_33287);
    env = stack[-4];
    goto v_33152;
v_33153:
    goto v_33147;
v_33148:
    goto v_33149;
v_33150:
    goto v_33151;
v_33152:
    v_33287 = list2star(stack[-2], stack[-1], v_33287);
    goto v_33135;
v_33137:
    goto v_33178;
v_33172:
    stack[-2] = elt(env, 7); // and
    goto v_33173;
v_33174:
    goto v_33187;
v_33181:
    v_33289 = elt(env, 9); // neq
    goto v_33182;
v_33183:
    v_33287 = stack[-1];
    v_33288 = qcdr(v_33287);
    goto v_33184;
v_33185:
    v_33287 = nil;
    goto v_33186;
v_33187:
    goto v_33181;
v_33182:
    goto v_33183;
v_33184:
    goto v_33185;
v_33186:
    stack[-1] = list3(v_33289, v_33288, v_33287);
    env = stack[-4];
    goto v_33175;
v_33176:
    v_33287 = stack[0];
    v_33287 = ncons(v_33287);
    env = stack[-4];
    goto v_33177;
v_33178:
    goto v_33172;
v_33173:
    goto v_33174;
v_33175:
    goto v_33176;
v_33177:
    v_33287 = list2star(stack[-2], stack[-1], v_33287);
    goto v_33135;
    v_33287 = nil;
v_33135:
    stack[0] = v_33287;
    goto v_33130;
v_33132:
v_33130:
    v_33287 = stack[0];
    goto v_33012;
v_33101:
    v_33287 = qvalue(elt(env, 2)); // !*rlnzden
    if (v_33287 == nil) goto v_33198;
    v_33287 = stack[-1];
    v_33287 = qcdr(v_33287);
    if (!consp(v_33287)) goto v_33204;
    else goto v_33205;
v_33204:
    v_33287 = lisp_true;
    goto v_33203;
v_33205:
    v_33287 = stack[-1];
    v_33287 = qcdr(v_33287);
    v_33287 = qcar(v_33287);
    v_33287 = (consp(v_33287) ? nil : lisp_true);
    goto v_33203;
    v_33287 = nil;
v_33203:
    if (v_33287 == nil) goto v_33201;
    else goto v_33198;
v_33201:
    goto v_33223;
v_33219:
    v_33289 = stack[-3];
    goto v_33220;
v_33221:
    v_33287 = elt(env, 6); // (lessp leq greaterp geq)
    goto v_33222;
v_33223:
    goto v_33219;
v_33220:
    goto v_33221;
v_33222:
    v_33287 = Lmemq(nil, v_33289, v_33287);
    if (v_33287 == nil) goto v_33218;
    goto v_33232;
v_33228:
    goto v_33229;
v_33230:
    v_33287 = stack[-1];
    v_33287 = qcdr(v_33287);
    goto v_33231;
v_33232:
    goto v_33228;
v_33229:
    goto v_33230;
v_33231:
    fn = elt(env, 14); // multf
    v_33287 = (*qfn2(fn))(fn, v_33288, v_33287);
    env = stack[-4];
    v_33288 = v_33287;
    goto v_33216;
v_33218:
v_33216:
    goto v_33243;
v_33237:
    v_33289 = stack[-3];
    goto v_33238;
v_33239:
    goto v_33240;
v_33241:
    v_33287 = nil;
    goto v_33242;
v_33243:
    goto v_33237;
v_33238:
    goto v_33239;
v_33240:
    goto v_33241;
v_33242:
    v_33287 = list3(v_33289, v_33288, v_33287);
    env = stack[-4];
    stack[0] = v_33287;
    v_33287 = qvalue(elt(env, 5)); // !*rladdcond
    if (v_33287 == nil) goto v_33250;
    goto v_33259;
v_33253:
    stack[-2] = elt(env, 7); // and
    goto v_33254;
v_33255:
    goto v_33268;
v_33262:
    v_33289 = elt(env, 9); // neq
    goto v_33263;
v_33264:
    v_33287 = stack[-1];
    v_33288 = qcdr(v_33287);
    goto v_33265;
v_33266:
    v_33287 = nil;
    goto v_33267;
v_33268:
    goto v_33262;
v_33263:
    goto v_33264;
v_33265:
    goto v_33266;
v_33267:
    stack[-1] = list3(v_33289, v_33288, v_33287);
    env = stack[-4];
    goto v_33256;
v_33257:
    v_33287 = stack[0];
    v_33287 = ncons(v_33287);
    env = stack[-4];
    goto v_33258;
v_33259:
    goto v_33253;
v_33254:
    goto v_33255;
v_33256:
    goto v_33257;
v_33258:
    v_33287 = list2star(stack[-2], stack[-1], v_33287);
    stack[0] = v_33287;
    goto v_33248;
v_33250:
v_33248:
    v_33287 = stack[0];
    goto v_33012;
v_33198:
    goto v_33283;
v_33277:
    v_33289 = stack[-3];
    goto v_33278;
v_33279:
    goto v_33280;
v_33281:
    v_33287 = nil;
    goto v_33282;
v_33283:
    goto v_33277;
v_33278:
    goto v_33279;
v_33280:
    goto v_33281;
v_33282:
    return list3(v_33289, v_33288, v_33287);
v_33012:
    return onevalue(v_33287);
}



// Code for pasf_ceeq

static LispObject CC_pasf_ceeq(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33118, v_33119;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33004);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33004;
// end of prologue
    goto v_33026;
v_33022:
    v_33119 = stack[0];
    goto v_33023;
v_33024:
    v_33118 = elt(env, 2); // true
    goto v_33025;
v_33026:
    goto v_33022;
v_33023:
    goto v_33024;
v_33025:
    if (v_33119 == v_33118) goto v_33020;
    else goto v_33021;
v_33020:
    v_33118 = lisp_true;
    goto v_33019;
v_33021:
    goto v_33036;
v_33032:
    v_33119 = stack[0];
    goto v_33033;
v_33034:
    v_33118 = elt(env, 3); // false
    goto v_33035;
v_33036:
    goto v_33032;
v_33033:
    goto v_33034;
v_33035:
    v_33118 = (v_33119 == v_33118 ? lisp_true : nil);
    goto v_33019;
    v_33118 = nil;
v_33019:
    if (v_33118 == nil) goto v_33017;
    v_33118 = lisp_true;
    goto v_33015;
v_33017:
    goto v_33047;
v_33043:
    goto v_33060;
v_33056:
    v_33119 = stack[0];
    goto v_33057;
v_33058:
    v_33118 = elt(env, 2); // true
    goto v_33059;
v_33060:
    goto v_33056;
v_33057:
    goto v_33058;
v_33059:
    if (v_33119 == v_33118) goto v_33054;
    else goto v_33055;
v_33054:
    v_33118 = lisp_true;
    goto v_33053;
v_33055:
    goto v_33070;
v_33066:
    v_33119 = stack[0];
    goto v_33067;
v_33068:
    v_33118 = elt(env, 3); // false
    goto v_33069;
v_33070:
    goto v_33066;
v_33067:
    goto v_33068;
v_33069:
    v_33118 = (v_33119 == v_33118 ? lisp_true : nil);
    goto v_33053;
    v_33118 = nil;
v_33053:
    if (v_33118 == nil) goto v_33051;
    v_33118 = stack[0];
    v_33119 = v_33118;
    goto v_33049;
v_33051:
    v_33118 = stack[0];
    v_33118 = qcar(v_33118);
    v_33118 = Lconsp(nil, v_33118);
    env = stack[-2];
    if (v_33118 == nil) goto v_33076;
    v_33118 = stack[0];
    v_33118 = qcar(v_33118);
    v_33118 = qcar(v_33118);
    v_33119 = v_33118;
    goto v_33049;
v_33076:
    v_33118 = stack[0];
    v_33118 = qcar(v_33118);
    v_33119 = v_33118;
    goto v_33049;
    v_33119 = nil;
v_33049:
    goto v_33044;
v_33045:
    v_33118 = elt(env, 4); // (equal neq)
    goto v_33046;
v_33047:
    goto v_33043;
v_33044:
    goto v_33045;
v_33046:
    v_33118 = Lmemq(nil, v_33119, v_33118);
    v_33118 = (v_33118 == nil ? lisp_true : nil);
    goto v_33015;
    v_33118 = nil;
v_33015:
    if (v_33118 == nil) goto v_33013;
    v_33118 = stack[0];
    goto v_33008;
v_33013:
    v_33118 = stack[0];
    v_33118 = qcdr(v_33118);
    v_33118 = qcar(v_33118);
    fn = elt(env, 5); // sfto_dcontentf
    v_33118 = (*qfn1(fn))(fn, v_33118);
    env = stack[-2];
    v_33119 = v_33118;
    goto v_33102;
v_33096:
    v_33118 = stack[0];
    stack[-1] = qcar(v_33118);
    goto v_33097;
v_33098:
    goto v_33110;
v_33106:
    v_33118 = stack[0];
    v_33118 = qcdr(v_33118);
    stack[0] = qcar(v_33118);
    goto v_33107;
v_33108:
    v_33118 = v_33119;
    fn = elt(env, 6); // simp
    v_33118 = (*qfn1(fn))(fn, v_33118);
    env = stack[-2];
    v_33118 = qcar(v_33118);
    goto v_33109;
v_33110:
    goto v_33106;
v_33107:
    goto v_33108;
v_33109:
    fn = elt(env, 7); // quotfx
    v_33119 = (*qfn2(fn))(fn, stack[0], v_33118);
    goto v_33099;
v_33100:
    v_33118 = nil;
    goto v_33101;
v_33102:
    goto v_33096;
v_33097:
    goto v_33098;
v_33099:
    goto v_33100;
v_33101:
    {
        LispObject v_33122 = stack[-1];
        return list3(v_33122, v_33119, v_33118);
    }
v_33008:
    return onevalue(v_33118);
}



// Code for bc_pmon

static LispObject CC_bc_pmon(LispObject env,
                         LispObject v_33004, LispObject v_33005)
{
    env = qenv(env);
    LispObject v_33032, v_33033, v_33034;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33005,v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33004,v_33005);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33032 = v_33005;
    v_33033 = v_33004;
// end of prologue
    goto v_33014;
v_33008:
    goto v_33020;
v_33016:
    goto v_33026;
v_33022:
    goto v_33023;
v_33024:
    goto v_33025;
v_33026:
    goto v_33022;
v_33023:
    goto v_33024;
v_33025:
    fn = elt(env, 1); // to
    v_33033 = (*qfn2(fn))(fn, v_33033, v_33032);
    env = stack[0];
    goto v_33017;
v_33018:
    v_33032 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33019;
v_33020:
    goto v_33016;
v_33017:
    goto v_33018;
v_33019:
    v_33034 = cons(v_33033, v_33032);
    goto v_33009;
v_33010:
    v_33033 = nil;
    goto v_33011;
v_33012:
    v_33032 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33013;
v_33014:
    goto v_33008;
v_33009:
    goto v_33010;
v_33011:
    goto v_33012;
v_33013:
    return acons(v_33034, v_33033, v_33032);
}



// Code for xpartitsq

static LispObject CC_xpartitsq(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33185, v_33186, v_33187;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33004);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_33187 = v_33004;
// end of prologue
    v_33185 = v_33187;
    v_33186 = qcar(v_33185);
    v_33185 = v_33187;
    v_33185 = qcdr(v_33185);
    stack[-2] = v_33186;
    stack[-1] = v_33185;
    v_33185 = stack[-2];
    if (v_33185 == nil) goto v_33014;
    else goto v_33015;
v_33014:
    v_33185 = nil;
    goto v_33013;
v_33015:
    v_33185 = stack[-2];
    if (!consp(v_33185)) goto v_33022;
    else goto v_33023;
v_33022:
    v_33185 = lisp_true;
    goto v_33021;
v_33023:
    v_33185 = stack[-2];
    v_33185 = qcar(v_33185);
    v_33185 = (consp(v_33185) ? nil : lisp_true);
    goto v_33021;
    v_33185 = nil;
v_33021:
    if (v_33185 == nil) goto v_33019;
    goto v_33037;
v_33033:
    v_33185 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33034;
v_33035:
    v_33186 = v_33187;
    goto v_33036;
v_33037:
    goto v_33033;
v_33034:
    goto v_33035;
v_33036:
    v_33185 = cons(v_33185, v_33186);
    return ncons(v_33185);
v_33019:
    goto v_33047;
v_33043:
    v_33185 = stack[-2];
    v_33185 = qcar(v_33185);
    v_33185 = qcar(v_33185);
    v_33185 = qcar(v_33185);
    fn = elt(env, 1); // sfp
    v_33185 = (*qfn1(fn))(fn, v_33185);
    env = stack[-3];
    if (v_33185 == nil) goto v_33051;
    goto v_33062;
v_33058:
    goto v_33068;
v_33064:
    goto v_33075;
v_33071:
    v_33185 = stack[-2];
    v_33185 = qcar(v_33185);
    v_33185 = qcar(v_33185);
    v_33186 = qcar(v_33185);
    goto v_33072;
v_33073:
    v_33185 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33074;
v_33075:
    goto v_33071;
v_33072:
    goto v_33073;
v_33074:
    v_33185 = cons(v_33186, v_33185);
    env = stack[-3];
    v_33186 = CC_xpartitsq(elt(env, 0), v_33185);
    env = stack[-3];
    goto v_33065;
v_33066:
    v_33185 = stack[-2];
    v_33185 = qcar(v_33185);
    v_33185 = qcar(v_33185);
    v_33185 = qcdr(v_33185);
    goto v_33067;
v_33068:
    goto v_33064;
v_33065:
    goto v_33066;
v_33067:
    fn = elt(env, 2); // xexptpf
    stack[0] = (*qfn2(fn))(fn, v_33186, v_33185);
    env = stack[-3];
    goto v_33059;
v_33060:
    goto v_33092;
v_33088:
    v_33185 = stack[-2];
    v_33185 = qcar(v_33185);
    v_33186 = qcdr(v_33185);
    goto v_33089;
v_33090:
    v_33185 = stack[-1];
    goto v_33091;
v_33092:
    goto v_33088;
v_33089:
    goto v_33090;
v_33091:
    v_33185 = cons(v_33186, v_33185);
    env = stack[-3];
    fn = elt(env, 3); // cancel
    v_33185 = (*qfn1(fn))(fn, v_33185);
    env = stack[-3];
    v_33185 = CC_xpartitsq(elt(env, 0), v_33185);
    env = stack[-3];
    goto v_33061;
v_33062:
    goto v_33058;
v_33059:
    goto v_33060;
v_33061:
    fn = elt(env, 4); // wedgepf
    v_33185 = (*qfn2(fn))(fn, stack[0], v_33185);
    env = stack[-3];
    stack[0] = v_33185;
    goto v_33049;
v_33051:
    v_33185 = stack[-2];
    v_33185 = qcar(v_33185);
    v_33185 = qcar(v_33185);
    v_33185 = qcar(v_33185);
    fn = elt(env, 5); // xvarp
    v_33185 = (*qfn1(fn))(fn, v_33185);
    env = stack[-3];
    if (v_33185 == nil) goto v_33098;
    goto v_33109;
v_33105:
    goto v_33115;
v_33111:
    v_33185 = stack[-2];
    v_33185 = qcar(v_33185);
    v_33185 = qcar(v_33185);
    v_33185 = qcar(v_33185);
    fn = elt(env, 6); // xpartitk
    v_33186 = (*qfn1(fn))(fn, v_33185);
    env = stack[-3];
    goto v_33112;
v_33113:
    v_33185 = stack[-2];
    v_33185 = qcar(v_33185);
    v_33185 = qcar(v_33185);
    v_33185 = qcdr(v_33185);
    goto v_33114;
v_33115:
    goto v_33111;
v_33112:
    goto v_33113;
v_33114:
    fn = elt(env, 2); // xexptpf
    stack[0] = (*qfn2(fn))(fn, v_33186, v_33185);
    env = stack[-3];
    goto v_33106;
v_33107:
    goto v_33132;
v_33128:
    v_33185 = stack[-2];
    v_33185 = qcar(v_33185);
    v_33186 = qcdr(v_33185);
    goto v_33129;
v_33130:
    v_33185 = stack[-1];
    goto v_33131;
v_33132:
    goto v_33128;
v_33129:
    goto v_33130;
v_33131:
    v_33185 = cons(v_33186, v_33185);
    env = stack[-3];
    fn = elt(env, 3); // cancel
    v_33185 = (*qfn1(fn))(fn, v_33185);
    env = stack[-3];
    v_33185 = CC_xpartitsq(elt(env, 0), v_33185);
    env = stack[-3];
    goto v_33108;
v_33109:
    goto v_33105;
v_33106:
    goto v_33107;
v_33108:
    fn = elt(env, 4); // wedgepf
    v_33185 = (*qfn2(fn))(fn, stack[0], v_33185);
    env = stack[-3];
    stack[0] = v_33185;
    goto v_33049;
v_33098:
    goto v_33144;
v_33140:
    goto v_33152;
v_33148:
    v_33185 = stack[-2];
    v_33185 = qcar(v_33185);
    v_33186 = qcdr(v_33185);
    goto v_33149;
v_33150:
    v_33185 = stack[-1];
    goto v_33151;
v_33152:
    goto v_33148;
v_33149:
    goto v_33150;
v_33151:
    v_33185 = cons(v_33186, v_33185);
    env = stack[-3];
    fn = elt(env, 3); // cancel
    v_33185 = (*qfn1(fn))(fn, v_33185);
    env = stack[-3];
    stack[0] = CC_xpartitsq(elt(env, 0), v_33185);
    env = stack[-3];
    goto v_33141;
v_33142:
    goto v_33162;
v_33158:
    goto v_33169;
v_33165:
    v_33185 = stack[-2];
    v_33185 = qcar(v_33185);
    v_33186 = qcar(v_33185);
    goto v_33166;
v_33167:
    v_33185 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33168;
v_33169:
    goto v_33165;
v_33166:
    goto v_33167;
v_33168:
    v_33185 = cons(v_33186, v_33185);
    env = stack[-3];
    v_33186 = ncons(v_33185);
    env = stack[-3];
    goto v_33159;
v_33160:
    v_33185 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33161;
v_33162:
    goto v_33158;
v_33159:
    goto v_33160;
v_33161:
    v_33185 = cons(v_33186, v_33185);
    env = stack[-3];
    goto v_33143;
v_33144:
    goto v_33140;
v_33141:
    goto v_33142;
v_33143:
    fn = elt(env, 7); // multpfsq
    v_33185 = (*qfn2(fn))(fn, stack[0], v_33185);
    env = stack[-3];
    stack[0] = v_33185;
    goto v_33049;
    stack[0] = nil;
v_33049:
    goto v_33044;
v_33045:
    goto v_33181;
v_33177:
    v_33185 = stack[-2];
    v_33186 = qcdr(v_33185);
    goto v_33178;
v_33179:
    v_33185 = stack[-1];
    goto v_33180;
v_33181:
    goto v_33177;
v_33178:
    goto v_33179;
v_33180:
    v_33185 = cons(v_33186, v_33185);
    env = stack[-3];
    v_33185 = CC_xpartitsq(elt(env, 0), v_33185);
    env = stack[-3];
    goto v_33046;
v_33047:
    goto v_33043;
v_33044:
    goto v_33045;
v_33046:
    {
        LispObject v_33191 = stack[0];
        fn = elt(env, 8); // addpf
        return (*qfn2(fn))(fn, v_33191, v_33185);
    }
    v_33185 = nil;
v_33013:
    return onevalue(v_33185);
}



// Code for binc

static LispObject CC_binc(LispObject env,
                         LispObject v_33004, LispObject v_33005)
{
    env = qenv(env);
    LispObject v_33041, v_33042, v_33043;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33005,v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33004,v_33005);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33005;
    v_33043 = v_33004;
// end of prologue
    goto v_33015;
v_33011:
    v_33042 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33012;
v_33013:
    v_33041 = stack[0];
    goto v_33014;
v_33015:
    goto v_33011;
v_33012:
    goto v_33013;
v_33014:
    if (v_33042 == v_33041) goto v_33009;
    else goto v_33010;
v_33009:
    v_33041 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33008;
v_33010:
    goto v_33026;
v_33022:
    goto v_33035;
v_33029:
    goto v_33030;
v_33031:
    v_33042 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33032;
v_33033:
    v_33041 = stack[0];
    goto v_33034;
v_33035:
    goto v_33029;
v_33030:
    goto v_33031;
v_33032:
    goto v_33033;
v_33034:
    fn = elt(env, 1); // mk!-numr
    v_33041 = (*qfnn(fn))(fn, 3, v_33043, v_33042, v_33041);
    env = stack[-2];
    fn = elt(env, 2); // constimes
    stack[-1] = (*qfn1(fn))(fn, v_33041);
    env = stack[-2];
    goto v_33023;
v_33024:
    v_33041 = stack[0];
    fn = elt(env, 3); // factorial
    v_33041 = (*qfn1(fn))(fn, v_33041);
    env = stack[-2];
    goto v_33025;
v_33026:
    goto v_33022;
v_33023:
    goto v_33024;
v_33025:
    {
        LispObject v_33046 = stack[-1];
        fn = elt(env, 4); // listquotient
        return (*qfn2(fn))(fn, v_33046, v_33041);
    }
    v_33041 = nil;
v_33008:
    return onevalue(v_33041);
}



// Code for gi

static LispObject CC_gi(LispObject env,
                         LispObject v_33005, LispObject v_33006)
{
    env = qenv(env);
    LispObject v_33054, v_33055;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33006,v_33005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33005,v_33006);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_33006;
    v_33054 = v_33005;
// end of prologue
// Binding gg!*
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = v_33054; // gg!*
    stack[-2] = nil;
    v_33054 = qvalue(elt(env, 1)); // gg!*
    stack[-1] = v_33054;
v_33019:
    v_33054 = stack[-1];
    if (v_33054 == nil) goto v_33023;
    else goto v_33024;
v_33023:
    goto v_33018;
v_33024:
    v_33054 = stack[-1];
    v_33054 = qcar(v_33054);
    stack[0] = v_33054;
    goto v_33038;
v_33034:
    v_33054 = stack[0];
    v_33054 = qcdr(v_33054);
    fn = elt(env, 3); // class
    v_33055 = (*qfn1(fn))(fn, v_33054);
    env = stack[-5];
    goto v_33035;
v_33036:
    v_33054 = stack[-3];
    goto v_33037;
v_33038:
    goto v_33034;
v_33035:
    goto v_33036;
v_33037:
    if (equal(v_33055, v_33054)) goto v_33032;
    else goto v_33033;
v_33032:
    goto v_33048;
v_33044:
    v_33055 = stack[0];
    goto v_33045;
v_33046:
    v_33054 = stack[-2];
    goto v_33047;
v_33048:
    goto v_33044;
v_33045:
    goto v_33046;
v_33047:
    v_33054 = cons(v_33055, v_33054);
    env = stack[-5];
    stack[-2] = v_33054;
    goto v_33031;
v_33033:
v_33031:
    v_33054 = stack[-1];
    v_33054 = qcdr(v_33054);
    stack[-1] = v_33054;
    goto v_33019;
v_33018:
    v_33054 = stack[-2];
    ;}  // end of a binding scope
    return onevalue(v_33054);
}



// Code for exports

static LispObject CC_exports(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33017, v_33018;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33004);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33017 = v_33004;
// end of prologue
    goto v_33014;
v_33010:
    v_33018 = v_33017;
    goto v_33011;
v_33012:
    v_33017 = qvalue(elt(env, 1)); // exportslist!*
    goto v_33013;
v_33014:
    goto v_33010;
v_33011:
    goto v_33012;
v_33013:
    fn = elt(env, 2); // union
    v_33017 = (*qfn2(fn))(fn, v_33018, v_33017);
    env = stack[0];
    qvalue(elt(env, 1)) = v_33017; // exportslist!*
    v_33017 = nil;
    return onevalue(v_33017);
}



// Code for sfto_deggcd1

static LispObject CC_sfto_deggcd1(LispObject env,
                         LispObject v_33004, LispObject v_33005)
{
    env = qenv(env);
    LispObject v_33097, v_33098, v_33099;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33005,v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33004,v_33005);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_33005;
    stack[-2] = v_33004;
// end of prologue
    v_33097 = (LispObject)0+TAG_FIXNUM; // 0
    v_33099 = v_33097;
    v_33097 = lisp_true;
    stack[-3] = v_33097;
v_33016:
    v_33097 = stack[-3];
    if (v_33097 == nil) goto v_33019;
    goto v_33028;
v_33024:
    v_33098 = v_33099;
    goto v_33025;
v_33026:
    v_33097 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33027;
v_33028:
    goto v_33024;
v_33025:
    goto v_33026;
v_33027:
    if (v_33098 == v_33097) goto v_33019;
    goto v_33020;
v_33019:
    goto v_33015;
v_33020:
    v_33097 = stack[-2];
    if (!consp(v_33097)) goto v_33038;
    else goto v_33039;
v_33038:
    v_33097 = lisp_true;
    goto v_33037;
v_33039:
    v_33097 = stack[-2];
    v_33097 = qcar(v_33097);
    v_33097 = (consp(v_33097) ? nil : lisp_true);
    goto v_33037;
    v_33097 = nil;
v_33037:
    if (v_33097 == nil) goto v_33035;
    v_33097 = nil;
    stack[-3] = v_33097;
    goto v_33033;
v_33035:
    goto v_33058;
v_33054:
    v_33097 = stack[-2];
    v_33097 = qcar(v_33097);
    v_33097 = qcar(v_33097);
    v_33098 = qcar(v_33097);
    goto v_33055;
v_33056:
    v_33097 = stack[-1];
    goto v_33057;
v_33058:
    goto v_33054;
v_33055:
    goto v_33056;
v_33057:
    if (v_33098 == v_33097) goto v_33052;
    else goto v_33053;
v_33052:
    goto v_33069;
v_33065:
    v_33098 = v_33099;
    goto v_33066;
v_33067:
    v_33097 = stack[-2];
    v_33097 = qcar(v_33097);
    v_33097 = qcar(v_33097);
    v_33097 = qcdr(v_33097);
    goto v_33068;
v_33069:
    goto v_33065;
v_33066:
    goto v_33067;
v_33068:
    v_33097 = Lgcd(nil, v_33098, v_33097);
    env = stack[-4];
    v_33099 = v_33097;
    goto v_33051;
v_33053:
    goto v_33082;
v_33078:
    stack[0] = v_33099;
    goto v_33079;
v_33080:
    goto v_33089;
v_33085:
    v_33097 = stack[-2];
    v_33097 = qcar(v_33097);
    v_33098 = qcdr(v_33097);
    goto v_33086;
v_33087:
    v_33097 = stack[-1];
    goto v_33088;
v_33089:
    goto v_33085;
v_33086:
    goto v_33087;
v_33088:
    v_33097 = CC_sfto_deggcd1(elt(env, 0), v_33098, v_33097);
    env = stack[-4];
    goto v_33081;
v_33082:
    goto v_33078;
v_33079:
    goto v_33080;
v_33081:
    v_33097 = Lgcd(nil, stack[0], v_33097);
    env = stack[-4];
    v_33099 = v_33097;
    goto v_33051;
v_33051:
    v_33097 = stack[-2];
    v_33097 = qcdr(v_33097);
    stack[-2] = v_33097;
    goto v_33033;
v_33033:
    goto v_33016;
v_33015:
    v_33097 = v_33099;
    return onevalue(v_33097);
}



// Code for rl_ex

static LispObject CC_rl_ex(LispObject env,
                         LispObject v_33004, LispObject v_33005)
{
    env = qenv(env);
    LispObject v_33022, v_33023;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33005,v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33004,v_33005);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_33022 = v_33005;
    v_33023 = v_33004;
// end of prologue
    goto v_33012;
v_33008:
    stack[0] = qvalue(elt(env, 1)); // rl_ex!*
    goto v_33009;
v_33010:
    goto v_33019;
v_33015:
    goto v_33016;
v_33017:
    goto v_33018;
v_33019:
    goto v_33015;
v_33016:
    goto v_33017;
v_33018:
    v_33022 = list2(v_33023, v_33022);
    env = stack[-1];
    goto v_33011;
v_33012:
    goto v_33008;
v_33009:
    goto v_33010;
v_33011:
    {
        LispObject v_33025 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_33025, v_33022);
    }
}



// Code for addcoeffs

static LispObject CC_addcoeffs(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33131, v_33132, v_33133, v_33134;
    LispObject fn;
    LispObject v_33007, v_33006, v_33005, v_33004;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "addcoeffs");
    va_start(aa, nargs);
    v_33004 = va_arg(aa, LispObject);
    v_33005 = va_arg(aa, LispObject);
    v_33006 = va_arg(aa, LispObject);
    v_33007 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_33007,v_33006,v_33005,v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_33004,v_33005,v_33006,v_33007);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_33007;
    stack[-2] = v_33006;
    stack[-3] = v_33005;
    stack[-4] = v_33004;
// end of prologue
    goto v_33019;
v_33015:
    v_33132 = nil;
    goto v_33016;
v_33017:
    v_33131 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33018;
v_33019:
    goto v_33015;
v_33016:
    goto v_33017;
v_33018:
    v_33131 = cons(v_33132, v_33131);
    env = stack[-6];
    stack[0] = v_33131;
    goto v_33027;
v_33023:
    v_33131 = stack[-4];
    fn = elt(env, 2); // smallest!-increment
    stack[-5] = (*qfn1(fn))(fn, v_33131);
    env = stack[-6];
    goto v_33024;
v_33025:
    v_33131 = stack[-3];
    fn = elt(env, 2); // smallest!-increment
    v_33131 = (*qfn1(fn))(fn, v_33131);
    env = stack[-6];
    goto v_33026;
v_33027:
    goto v_33023;
v_33024:
    goto v_33025;
v_33026:
    fn = elt(env, 3); // common!-increment
    v_33131 = (*qfn2(fn))(fn, stack[-5], v_33131);
    env = stack[-6];
    goto v_33045;
v_33037:
    v_33134 = stack[-2];
    goto v_33038;
v_33039:
    v_33133 = stack[-1];
    goto v_33040;
v_33041:
    v_33132 = stack[-3];
    v_33132 = qcar(v_33132);
    v_33132 = qcar(v_33132);
    goto v_33042;
v_33043:
    goto v_33044;
v_33045:
    goto v_33037;
v_33038:
    goto v_33039;
v_33040:
    goto v_33041;
v_33042:
    goto v_33043;
v_33044:
    fn = elt(env, 4); // makecoeffpairs
    v_33131 = (*qfnn(fn))(fn, 4, v_33134, v_33133, v_33132, v_33131);
    env = stack[-6];
    stack[-5] = v_33131;
v_33035:
    v_33131 = stack[-5];
    if (v_33131 == nil) goto v_33054;
    else goto v_33055;
v_33054:
    goto v_33034;
v_33055:
    v_33131 = stack[-5];
    v_33131 = qcar(v_33131);
    stack[-2] = v_33131;
    goto v_33066;
v_33062:
    stack[-1] = stack[0];
    goto v_33063;
v_33064:
    goto v_33073;
v_33069:
    goto v_33078;
v_33074:
    v_33131 = stack[-2];
    v_33132 = qcar(v_33131);
    goto v_33075;
v_33076:
    v_33131 = stack[-4];
    goto v_33077;
v_33078:
    goto v_33074;
v_33075:
    goto v_33076;
v_33077:
    v_33131 = Lassoc(nil, v_33132, v_33131);
    v_33132 = v_33131;
    v_33131 = v_33132;
    if (v_33131 == nil) goto v_33086;
    else goto v_33087;
v_33086:
    goto v_33094;
v_33090:
    v_33132 = nil;
    goto v_33091;
v_33092:
    v_33131 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33093;
v_33094:
    goto v_33090;
v_33091:
    goto v_33092;
v_33093:
    v_33131 = cons(v_33132, v_33131);
    env = stack[-6];
    stack[0] = v_33131;
    goto v_33085;
v_33087:
    v_33131 = v_33132;
    v_33131 = qcdr(v_33131);
    stack[0] = v_33131;
    goto v_33085;
    stack[0] = nil;
v_33085:
    goto v_33070;
v_33071:
    goto v_33105;
v_33101:
    v_33131 = stack[-2];
    v_33132 = qcdr(v_33131);
    goto v_33102;
v_33103:
    v_33131 = stack[-3];
    goto v_33104;
v_33105:
    goto v_33101;
v_33102:
    goto v_33103;
v_33104:
    v_33131 = Lassoc(nil, v_33132, v_33131);
    v_33132 = v_33131;
    v_33131 = v_33132;
    if (v_33131 == nil) goto v_33113;
    else goto v_33114;
v_33113:
    goto v_33121;
v_33117:
    v_33132 = nil;
    goto v_33118;
v_33119:
    v_33131 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33120;
v_33121:
    goto v_33117;
v_33118:
    goto v_33119;
v_33120:
    v_33131 = cons(v_33132, v_33131);
    env = stack[-6];
    goto v_33112;
v_33114:
    v_33131 = v_33132;
    v_33131 = qcdr(v_33131);
    goto v_33112;
    v_33131 = nil;
v_33112:
    goto v_33072;
v_33073:
    goto v_33069;
v_33070:
    goto v_33071;
v_33072:
    fn = elt(env, 5); // multsq
    v_33131 = (*qfn2(fn))(fn, stack[0], v_33131);
    env = stack[-6];
    goto v_33065;
v_33066:
    goto v_33062;
v_33063:
    goto v_33064;
v_33065:
    fn = elt(env, 6); // addsq
    v_33131 = (*qfn2(fn))(fn, stack[-1], v_33131);
    env = stack[-6];
    stack[0] = v_33131;
    v_33131 = stack[-5];
    v_33131 = qcdr(v_33131);
    stack[-5] = v_33131;
    goto v_33035;
v_33034:
    v_33131 = stack[0];
    return onevalue(v_33131);
}



// Code for !*invsq

static LispObject CC_Hinvsq(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33018, v_33019;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33004);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33019 = v_33004;
// end of prologue
    v_33018 = qvalue(elt(env, 1)); // sqrtflag
    if (v_33018 == nil) goto v_33009;
    v_33018 = v_33019;
    fn = elt(env, 2); // invsq
    v_33018 = (*qfn1(fn))(fn, v_33018);
    env = stack[0];
    {
        fn = elt(env, 3); // sqrt2top
        return (*qfn1(fn))(fn, v_33018);
    }
v_33009:
    v_33018 = v_33019;
    {
        fn = elt(env, 2); // invsq
        return (*qfn1(fn))(fn, v_33018);
    }
    v_33018 = nil;
    return onevalue(v_33018);
}



// Code for qqe_length!-graph!-bterm

static LispObject CC_qqe_lengthKgraphKbterm(LispObject env,
                         LispObject v_33004, LispObject v_33005)
{
    env = qenv(env);
    LispObject v_33074, v_33075;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33005,v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33004,v_33005);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33005;
    stack[-1] = v_33004;
// end of prologue
    v_33074 = stack[-1];
    if (v_33074 == nil) goto v_33016;
    else goto v_33017;
v_33016:
    v_33074 = lisp_true;
    goto v_33015;
v_33017:
    v_33074 = stack[-1];
    v_33074 = (consp(v_33074) ? nil : lisp_true);
    goto v_33015;
    v_33074 = nil;
v_33015:
    if (v_33074 == nil) goto v_33013;
    v_33074 = stack[0];
    goto v_33008;
v_33013:
    goto v_33033;
v_33029:
    v_33074 = stack[-1];
    fn = elt(env, 2); // qqe_op
    v_33075 = (*qfn1(fn))(fn, v_33074);
    env = stack[-2];
    goto v_33030;
v_33031:
    v_33074 = elt(env, 1); // (lhead rhead)
    goto v_33032;
v_33033:
    goto v_33029;
v_33030:
    goto v_33031;
v_33032:
    v_33074 = Lmemq(nil, v_33075, v_33074);
    if (v_33074 == nil) goto v_33028;
    goto v_33043;
v_33039:
    v_33075 = stack[-1];
    goto v_33040;
v_33041:
    v_33074 = stack[0];
    goto v_33042;
v_33043:
    goto v_33039;
v_33040:
    goto v_33041;
v_33042:
    fn = elt(env, 3); // qqe_length!-graph!-bterm!-update!-headmin
    v_33074 = (*qfn2(fn))(fn, v_33075, v_33074);
    stack[0] = v_33074;
    goto v_33026;
v_33028:
    v_33074 = stack[-1];
    v_33074 = qcdr(v_33074);
    stack[-1] = v_33074;
v_33051:
    v_33074 = stack[-1];
    if (v_33074 == nil) goto v_33056;
    else goto v_33057;
v_33056:
    goto v_33050;
v_33057:
    v_33074 = stack[-1];
    v_33074 = qcar(v_33074);
    goto v_33068;
v_33064:
    v_33075 = v_33074;
    goto v_33065;
v_33066:
    v_33074 = stack[0];
    goto v_33067;
v_33068:
    goto v_33064;
v_33065:
    goto v_33066;
v_33067:
    v_33074 = CC_qqe_lengthKgraphKbterm(elt(env, 0), v_33075, v_33074);
    env = stack[-2];
    stack[0] = v_33074;
    v_33074 = stack[-1];
    v_33074 = qcdr(v_33074);
    stack[-1] = v_33074;
    goto v_33051;
v_33050:
    goto v_33026;
v_33026:
    v_33074 = stack[0];
v_33008:
    return onevalue(v_33074);
}



// Code for tidysqrt

static LispObject CC_tidysqrt(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33039, v_33040;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33004);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33004;
// end of prologue
    v_33039 = stack[0];
    v_33039 = qcar(v_33039);
    fn = elt(env, 2); // tidysqrtf
    v_33039 = (*qfn1(fn))(fn, v_33039);
    env = stack[-2];
    stack[-1] = v_33039;
    v_33039 = stack[-1];
    if (v_33039 == nil) goto v_33016;
    else goto v_33017;
v_33016:
    goto v_33024;
v_33020:
    v_33040 = nil;
    goto v_33021;
v_33022:
    v_33039 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33023;
v_33024:
    goto v_33020;
v_33021:
    goto v_33022;
v_33023:
    return cons(v_33040, v_33039);
v_33017:
    v_33039 = stack[0];
    v_33039 = qcdr(v_33039);
    fn = elt(env, 2); // tidysqrtf
    v_33039 = (*qfn1(fn))(fn, v_33039);
    env = stack[-2];
    goto v_33035;
v_33031:
    stack[0] = stack[-1];
    goto v_33032;
v_33033:
    fn = elt(env, 3); // invsq
    v_33039 = (*qfn1(fn))(fn, v_33039);
    env = stack[-2];
    goto v_33034;
v_33035:
    goto v_33031;
v_33032:
    goto v_33033;
v_33034:
    {
        LispObject v_33043 = stack[0];
        fn = elt(env, 4); // multsq
        return (*qfn2(fn))(fn, v_33043, v_33039);
    }
    return onevalue(v_33039);
}



// Code for look_for_rational

static LispObject CC_look_for_rational(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33163, v_33164, v_33165;
    LispObject fn;
    LispObject v_33006, v_33005, v_33004;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "look_for_rational");
    va_start(aa, nargs);
    v_33004 = va_arg(aa, LispObject);
    v_33005 = va_arg(aa, LispObject);
    v_33006 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_33006,v_33005,v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_33004,v_33005,v_33006);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_33006;
    stack[-1] = v_33005;
    stack[-2] = v_33004;
// end of prologue
    goto v_33017;
v_33013:
    v_33164 = stack[-1];
    goto v_33014;
v_33015:
    v_33163 = elt(env, 1); // look_for_exponential
    goto v_33016;
v_33017:
    goto v_33013;
v_33014:
    goto v_33015;
v_33016:
    v_33163 = get(v_33164, v_33163);
    env = stack[-3];
    if (v_33163 == nil) goto v_33011;
    v_33163 = nil;
    goto v_33009;
v_33011:
    goto v_33031;
v_33027:
    v_33163 = stack[0];
    v_33164 = qcar(v_33163);
    goto v_33028;
v_33029:
    v_33163 = elt(env, 2); // sqrt
    goto v_33030;
v_33031:
    goto v_33027;
v_33028:
    goto v_33029;
v_33030:
    if (v_33164 == v_33163) goto v_33025;
    else goto v_33026;
v_33025:
    goto v_33039;
v_33035:
    v_33163 = stack[0];
    v_33163 = qcdr(v_33163);
    v_33164 = qcar(v_33163);
    goto v_33036;
v_33037:
    v_33163 = stack[-1];
    goto v_33038;
v_33039:
    goto v_33035;
v_33036:
    goto v_33037;
v_33038:
    v_33163 = (equal(v_33164, v_33163) ? lisp_true : nil);
    goto v_33024;
v_33026:
    v_33163 = nil;
    goto v_33024;
    v_33163 = nil;
v_33024:
    if (v_33163 == nil) goto v_33022;
    goto v_33055;
v_33049:
    v_33165 = stack[-2];
    goto v_33050;
v_33051:
    v_33164 = stack[-1];
    goto v_33052;
v_33053:
    v_33163 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_33054;
v_33055:
    goto v_33049;
v_33050:
    goto v_33051;
v_33052:
    goto v_33053;
v_33054:
    {
        fn = elt(env, 5); // look_for_rational1
        return (*qfnn(fn))(fn, 3, v_33165, v_33164, v_33163);
    }
v_33022:
    goto v_33069;
v_33065:
    v_33163 = stack[0];
    v_33164 = qcar(v_33163);
    goto v_33066;
v_33067:
    v_33163 = elt(env, 3); // expt
    goto v_33068;
v_33069:
    goto v_33065;
v_33066:
    goto v_33067;
v_33068:
    if (v_33164 == v_33163) goto v_33063;
    else goto v_33064;
v_33063:
    goto v_33081;
v_33077:
    v_33163 = stack[0];
    v_33163 = qcdr(v_33163);
    v_33164 = qcar(v_33163);
    goto v_33078;
v_33079:
    v_33163 = stack[-1];
    goto v_33080;
v_33081:
    goto v_33077;
v_33078:
    goto v_33079;
v_33080:
    if (equal(v_33164, v_33163)) goto v_33075;
    else goto v_33076;
v_33075:
    v_33163 = stack[0];
    v_33163 = qcdr(v_33163);
    v_33163 = qcdr(v_33163);
    v_33163 = qcar(v_33163);
    fn = elt(env, 6); // listp
    v_33163 = (*qfn1(fn))(fn, v_33163);
    env = stack[-3];
    if (v_33163 == nil) goto v_33088;
    else goto v_33089;
v_33088:
    v_33163 = nil;
    goto v_33087;
v_33089:
    goto v_33106;
v_33102:
    v_33163 = stack[0];
    v_33163 = qcdr(v_33163);
    v_33163 = qcdr(v_33163);
    v_33163 = qcar(v_33163);
    v_33164 = qcar(v_33163);
    goto v_33103;
v_33104:
    v_33163 = elt(env, 4); // quotient
    goto v_33105;
v_33106:
    goto v_33102;
v_33103:
    goto v_33104;
v_33105:
    if (v_33164 == v_33163) goto v_33100;
    else goto v_33101;
v_33100:
    v_33163 = stack[0];
    v_33163 = qcdr(v_33163);
    v_33163 = qcdr(v_33163);
    v_33163 = qcar(v_33163);
    v_33163 = qcdr(v_33163);
    v_33163 = qcar(v_33163);
    if (is_number(v_33163)) goto v_33116;
    v_33163 = nil;
    goto v_33114;
v_33116:
    v_33163 = stack[0];
    v_33163 = qcdr(v_33163);
    v_33163 = qcdr(v_33163);
    v_33163 = qcar(v_33163);
    v_33163 = qcdr(v_33163);
    v_33163 = qcdr(v_33163);
    v_33163 = qcar(v_33163);
    v_33163 = (is_number(v_33163) ? lisp_true : nil);
    goto v_33114;
    v_33163 = nil;
v_33114:
    goto v_33099;
v_33101:
    v_33163 = nil;
    goto v_33099;
    v_33163 = nil;
v_33099:
    goto v_33087;
    v_33163 = nil;
v_33087:
    goto v_33074;
v_33076:
    v_33163 = nil;
    goto v_33074;
    v_33163 = nil;
v_33074:
    goto v_33062;
v_33064:
    v_33163 = nil;
    goto v_33062;
    v_33163 = nil;
v_33062:
    if (v_33163 == nil) goto v_33060;
    goto v_33150;
v_33144:
    v_33165 = stack[-2];
    goto v_33145;
v_33146:
    v_33164 = stack[-1];
    goto v_33147;
v_33148:
    v_33163 = stack[0];
    v_33163 = qcdr(v_33163);
    v_33163 = qcdr(v_33163);
    v_33163 = qcar(v_33163);
    v_33163 = qcdr(v_33163);
    v_33163 = qcdr(v_33163);
    v_33163 = qcar(v_33163);
    goto v_33149;
v_33150:
    goto v_33144;
v_33145:
    goto v_33146;
v_33147:
    goto v_33148;
v_33149:
    {
        fn = elt(env, 5); // look_for_rational1
        return (*qfnn(fn))(fn, 3, v_33165, v_33164, v_33163);
    }
v_33060:
    v_33163 = nil;
    goto v_33009;
    v_33163 = nil;
v_33009:
    return onevalue(v_33163);
}



// Code for subscriptedvarp2

static LispObject CC_subscriptedvarp2(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33022, v_33023;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33004);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33022 = v_33004;
// end of prologue
    goto v_33011;
v_33007:
    goto v_33018;
v_33014:
    v_33023 = nil;
    goto v_33015;
v_33016:
    goto v_33017;
v_33018:
    goto v_33014;
v_33015:
    goto v_33016;
v_33017:
    fn = elt(env, 1); // symtabget
    v_33022 = (*qfn2(fn))(fn, v_33023, v_33022);
    env = stack[0];
    v_33023 = Llength(nil, v_33022);
    goto v_33008;
v_33009:
    v_33022 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_33010;
v_33011:
    goto v_33007;
v_33008:
    goto v_33009;
v_33010:
        return Lgreaterp(nil, v_33023, v_33022);
}



// Code for dip!-nc!-ev!-prod

static LispObject CC_dipKncKevKprod(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33037, v_33038, v_33039, v_33040;
    LispObject fn;
    LispObject v_33007, v_33006, v_33005, v_33004;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "dip-nc-ev-prod");
    va_start(aa, nargs);
    v_33004 = va_arg(aa, LispObject);
    v_33005 = va_arg(aa, LispObject);
    v_33006 = va_arg(aa, LispObject);
    v_33007 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_33007,v_33006,v_33005,v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_33004,v_33005,v_33006,v_33007);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_33037 = v_33007;
    v_33038 = v_33006;
    v_33039 = v_33005;
    v_33040 = v_33004;
// end of prologue
    goto v_33016;
v_33010:
    stack[-2] = v_33039;
    goto v_33011;
v_33012:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33013;
v_33014:
    goto v_33026;
v_33020:
    stack[0] = v_33037;
    goto v_33021;
v_33022:
    goto v_33033;
v_33029:
    v_33037 = v_33040;
    goto v_33030;
v_33031:
    goto v_33032;
v_33033:
    goto v_33029;
v_33030:
    goto v_33031;
v_33032:
    fn = elt(env, 1); // bcprod
    v_33038 = (*qfn2(fn))(fn, v_33037, v_33038);
    env = stack[-3];
    goto v_33023;
v_33024:
    v_33037 = nil;
    goto v_33025;
v_33026:
    goto v_33020;
v_33021:
    goto v_33022;
v_33023:
    goto v_33024;
v_33025:
    v_33037 = list2star(stack[0], v_33038, v_33037);
    env = stack[-3];
    goto v_33015;
v_33016:
    goto v_33010;
v_33011:
    goto v_33012;
v_33013:
    goto v_33014;
v_33015:
    {
        LispObject v_33044 = stack[-2];
        LispObject v_33045 = stack[-1];
        fn = elt(env, 2); // dip!-nc!-ev!-prod1
        return (*qfnn(fn))(fn, 3, v_33044, v_33045, v_33037);
    }
}



// Code for !*kp2q

static LispObject CC_Hkp2q(LispObject env,
                         LispObject v_33004, LispObject v_33005)
{
    env = qenv(env);
    LispObject v_33057, v_33058;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33005,v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33004,v_33005);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33005;
    stack[-1] = v_33004;
// end of prologue
    goto v_33016;
v_33012:
    v_33058 = stack[0];
    goto v_33013;
v_33014:
    v_33057 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33015;
v_33016:
    goto v_33012;
v_33013:
    goto v_33014;
v_33015:
    v_33057 = (LispObject)greaterp2(v_33058, v_33057);
    v_33057 = v_33057 ? lisp_true : nil;
    env = stack[-2];
    if (v_33057 == nil) goto v_33010;
    goto v_33024;
v_33020:
    v_33058 = stack[-1];
    goto v_33021;
v_33022:
    v_33057 = stack[0];
    goto v_33023;
v_33024:
    goto v_33020;
v_33021:
    goto v_33022;
v_33023:
    {
        fn = elt(env, 2); // mksq
        return (*qfn2(fn))(fn, v_33058, v_33057);
    }
v_33010:
    v_33057 = stack[0];
    v_33057 = (LispObject)zerop(v_33057);
    v_33057 = v_33057 ? lisp_true : nil;
    env = stack[-2];
    if (v_33057 == nil) goto v_33028;
    goto v_33036;
v_33032:
    v_33058 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33033;
v_33034:
    v_33057 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33035;
v_33036:
    goto v_33032;
v_33033:
    goto v_33034;
v_33035:
    return cons(v_33058, v_33057);
v_33028:
    goto v_33046;
v_33042:
    goto v_33043;
v_33044:
    v_33057 = stack[0];
    v_33057 = negate(v_33057);
    env = stack[-2];
    goto v_33045;
v_33046:
    goto v_33042;
v_33043:
    goto v_33044;
v_33045:
    fn = elt(env, 2); // mksq
    v_33057 = (*qfn2(fn))(fn, stack[-1], v_33057);
    env = stack[-2];
    stack[-1] = v_33057;
    v_33057 = qcar(v_33057);
    if (v_33057 == nil) goto v_33039;
    else goto v_33040;
v_33039:
    v_33057 = elt(env, 1); // "Zero divisor"
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_33057);
    }
v_33040:
    v_33057 = stack[-1];
    {
        fn = elt(env, 4); // revpr
        return (*qfn1(fn))(fn, v_33057);
    }
    v_33057 = nil;
    return onevalue(v_33057);
}



// Code for calc_world

static LispObject CC_calc_world(LispObject env,
                         LispObject v_33004, LispObject v_33005)
{
    env = qenv(env);
    LispObject v_33069, v_33070;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33005,v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33004,v_33005);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_33005;
    stack[-2] = v_33004;
// end of prologue
    goto v_33017;
v_33013:
    stack[0] = stack[-1];
    goto v_33014;
v_33015:
    v_33069 = stack[-2];
    fn = elt(env, 2); // s_world_names
    v_33069 = (*qfn1(fn))(fn, v_33069);
    env = stack[-4];
    goto v_33016;
v_33017:
    goto v_33013;
v_33014:
    goto v_33015;
v_33016:
    fn = elt(env, 3); // actual_alst
    v_33069 = (*qfn2(fn))(fn, stack[0], v_33069);
    env = stack[-4];
    stack[-1] = v_33069;
    v_33069 = stack[-2];
    v_33069 = qcdr(v_33069);
    v_33069 = qcar(v_33069);
    stack[0] = v_33069;
    goto v_33028;
v_33024:
    v_33070 = stack[-1];
    goto v_33025;
v_33026:
    v_33069 = stack[0];
    v_33069 = qcdr(v_33069);
    goto v_33027;
v_33028:
    goto v_33024;
v_33025:
    goto v_33026;
v_33027:
    v_33069 = Lassoc(nil, v_33070, v_33069);
    stack[-3] = v_33069;
    v_33069 = stack[-3];
    if (v_33069 == nil) goto v_33036;
    v_33069 = stack[-3];
    v_33069 = qcdr(v_33069);
    goto v_33010;
v_33036:
    goto v_33046;
v_33042:
    v_33069 = stack[-2];
    v_33069 = qcdr(v_33069);
    v_33069 = qcdr(v_33069);
    v_33070 = qcar(v_33069);
    goto v_33043;
v_33044:
    v_33069 = stack[-1];
    goto v_33045;
v_33046:
    goto v_33042;
v_33043:
    goto v_33044;
v_33045:
    fn = elt(env, 4); // calc_atlas
    v_33069 = (*qfn2(fn))(fn, v_33070, v_33069);
    env = stack[-4];
    fn = elt(env, 5); // reval
    v_33069 = (*qfn1(fn))(fn, v_33069);
    env = stack[-4];
    stack[-3] = v_33069;
    goto v_33057;
v_33053:
    goto v_33054;
v_33055:
    goto v_33065;
v_33061:
    v_33070 = stack[-1];
    goto v_33062;
v_33063:
    v_33069 = stack[-3];
    goto v_33064;
v_33065:
    goto v_33061;
v_33062:
    goto v_33063;
v_33064:
    v_33069 = cons(v_33070, v_33069);
    env = stack[-4];
    v_33069 = ncons(v_33069);
    env = stack[-4];
    goto v_33056;
v_33057:
    goto v_33053;
v_33054:
    goto v_33055;
v_33056:
    v_33069 = Lnconc(nil, stack[0], v_33069);
    v_33069 = stack[-3];
v_33010:
    return onevalue(v_33069);
}



// Code for liendimcom

static LispObject CC_liendimcom(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_34153, v_34154, v_34155, v_34156;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33004);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_33004;
// end of prologue
    v_34153 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-9] = v_34153;
    goto v_33016;
v_33012:
    stack[0] = elt(env, 1); // lie_dim
    goto v_33013;
v_33014:
    v_34153 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 14); // aeval
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33015;
v_33016:
    goto v_33012;
v_33013:
    goto v_33014;
v_33015:
    fn = elt(env, 15); // setk
    v_34153 = (*qfn2(fn))(fn, stack[0], v_34153);
    env = stack[-10];
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_34153;
v_33023:
    goto v_33037;
v_33031:
    stack[0] = elt(env, 2); // difference
    goto v_33032;
v_33033:
    goto v_33047;
v_33041:
    v_34155 = elt(env, 2); // difference
    goto v_33042;
v_33043:
    v_34154 = stack[-8];
    goto v_33044;
v_33045:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33046;
v_33047:
    goto v_33041;
v_33042:
    goto v_33043;
v_33044:
    goto v_33045;
v_33046:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33034;
v_33035:
    v_34153 = stack[-3];
    goto v_33036;
v_33037:
    goto v_33031;
v_33032:
    goto v_33033;
v_33034:
    goto v_33035;
v_33036:
    v_34153 = list3(stack[0], v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33028;
    goto v_33022;
v_33028:
    v_34153 = stack[-3];
    stack[-2] = v_34153;
v_33056:
    goto v_33070;
v_33064:
    stack[0] = elt(env, 2); // difference
    goto v_33065;
v_33066:
    v_34153 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33067;
v_33068:
    v_34153 = stack[-2];
    goto v_33069;
v_33070:
    goto v_33064;
v_33065:
    goto v_33066;
v_33067:
    goto v_33068;
v_33069:
    v_34153 = list3(stack[0], v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33061;
    goto v_33055;
v_33061:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_34153;
v_33079:
    goto v_33093;
v_33087:
    stack[0] = elt(env, 2); // difference
    goto v_33088;
v_33089:
    v_34153 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33090;
v_33091:
    v_34153 = stack[-1];
    goto v_33092;
v_33093:
    goto v_33087;
v_33088:
    goto v_33089;
v_33090:
    goto v_33091;
v_33092:
    v_34153 = list3(stack[0], v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33084;
    goto v_33078;
v_33084:
    goto v_33108;
v_33104:
    goto v_33119;
v_33111:
    v_34156 = elt(env, 3); // lie_cc
    goto v_33112;
v_33113:
    v_34155 = stack[-3];
    goto v_33114;
v_33115:
    v_34154 = stack[-2];
    goto v_33116;
v_33117:
    v_34153 = stack[-1];
    goto v_33118;
v_33119:
    goto v_33111;
v_33112:
    goto v_33113;
v_33114:
    goto v_33115;
v_33116:
    goto v_33117;
v_33118:
    v_34153 = list4(v_34156, v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33105;
v_33106:
    v_34153 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33107;
v_33108:
    goto v_33104;
v_33105:
    goto v_33106;
v_33107:
    fn = elt(env, 18); // evalneq
    v_34153 = (*qfn2(fn))(fn, v_34154, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33102;
    goto v_33130;
v_33126:
    stack[0] = elt(env, 1); // lie_dim
    goto v_33127;
v_33128:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33129;
v_33130:
    goto v_33126;
v_33127:
    goto v_33128;
v_33129:
    fn = elt(env, 15); // setk
    v_34153 = (*qfn2(fn))(fn, stack[0], v_34153);
    env = stack[-10];
    goto v_33139;
v_33135:
    stack[0] = elt(env, 4); // lie_p
    goto v_33136;
v_33137:
    v_34153 = stack[-3];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33138;
v_33139:
    goto v_33135;
v_33136:
    goto v_33137;
v_33138:
    fn = elt(env, 15); // setk
    v_34153 = (*qfn2(fn))(fn, stack[0], v_34153);
    env = stack[-10];
    goto v_33148;
v_33144:
    stack[0] = elt(env, 5); // lie_q
    goto v_33145;
v_33146:
    v_34153 = stack[-2];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33147;
v_33148:
    goto v_33144;
v_33145:
    goto v_33146;
v_33147:
    fn = elt(env, 15); // setk
    v_34153 = (*qfn2(fn))(fn, stack[0], v_34153);
    env = stack[-10];
    v_34153 = stack[-1];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-9] = v_34153;
    v_34153 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-3] = v_34153;
    goto v_33164;
v_33158:
    v_34155 = elt(env, 6); // plus
    goto v_33159;
v_33160:
    v_34154 = stack[-8];
    goto v_33161;
v_33162:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33163;
v_33164:
    goto v_33158;
v_33159:
    goto v_33160;
v_33161:
    goto v_33162;
v_33163:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-1] = v_34153;
    stack[-2] = v_34153;
    goto v_33100;
v_33102:
v_33100:
    v_34153 = stack[-1];
    goto v_33178;
v_33172:
    v_34155 = elt(env, 6); // plus
    goto v_33173;
v_33174:
    v_34154 = v_34153;
    goto v_33175;
v_33176:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33177;
v_33178:
    goto v_33172;
v_33173:
    goto v_33174;
v_33175:
    goto v_33176;
v_33177:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-1] = v_34153;
    goto v_33079;
v_33078:
    v_34153 = stack[-2];
    goto v_33192;
v_33186:
    v_34155 = elt(env, 6); // plus
    goto v_33187;
v_33188:
    v_34154 = v_34153;
    goto v_33189;
v_33190:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33191;
v_33192:
    goto v_33186;
v_33187:
    goto v_33188;
v_33189:
    goto v_33190;
v_33191:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-2] = v_34153;
    goto v_33056;
v_33055:
    v_34153 = stack[-3];
    goto v_33206;
v_33200:
    v_34155 = elt(env, 6); // plus
    goto v_33201;
v_33202:
    v_34154 = v_34153;
    goto v_33203;
v_33204:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33205;
v_33206:
    goto v_33200;
v_33201:
    goto v_33202;
v_33203:
    goto v_33204;
v_33205:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-3] = v_34153;
    goto v_33023;
v_33022:
    goto v_33219;
v_33215:
    v_34153 = elt(env, 1); // lie_dim
    fn = elt(env, 14); // aeval
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33216;
v_33217:
    v_34153 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33218;
v_33219:
    goto v_33215;
v_33216:
    goto v_33217;
v_33218:
    fn = elt(env, 18); // evalneq
    v_34153 = (*qfn2(fn))(fn, v_34154, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33213;
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_34153;
v_33226:
    goto v_33240;
v_33234:
    stack[0] = elt(env, 2); // difference
    goto v_33235;
v_33236:
    goto v_33250;
v_33244:
    v_34155 = elt(env, 2); // difference
    goto v_33245;
v_33246:
    v_34154 = stack[-8];
    goto v_33247;
v_33248:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33249;
v_33250:
    goto v_33244;
v_33245:
    goto v_33246;
v_33247:
    goto v_33248;
v_33249:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33237;
v_33238:
    v_34153 = stack[-5];
    goto v_33239;
v_33240:
    goto v_33234;
v_33235:
    goto v_33236;
v_33237:
    goto v_33238;
v_33239:
    v_34153 = list3(stack[0], v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33231;
    goto v_33225;
v_33231:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_34153;
v_33259:
    goto v_33273;
v_33267:
    stack[0] = elt(env, 2); // difference
    goto v_33268;
v_33269:
    v_34153 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33270;
v_33271:
    v_34153 = stack[-4];
    goto v_33272;
v_33273:
    goto v_33267;
v_33268:
    goto v_33269;
v_33270:
    goto v_33271;
v_33272:
    v_34153 = list3(stack[0], v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33264;
    goto v_33258;
v_33264:
    goto v_33287;
v_33281:
    stack[-1] = elt(env, 7); // quotient
    goto v_33282;
v_33283:
    goto v_33298;
v_33290:
    v_34156 = elt(env, 3); // lie_cc
    goto v_33291;
v_33292:
    v_34155 = stack[-5];
    goto v_33293;
v_33294:
    v_34154 = stack[-4];
    goto v_33295;
v_33296:
    v_34153 = stack[-9];
    goto v_33297;
v_33298:
    goto v_33290;
v_33291:
    goto v_33292;
v_33293:
    goto v_33294;
v_33295:
    goto v_33296;
v_33297:
    stack[0] = list4(v_34156, v_34155, v_34154, v_34153);
    env = stack[-10];
    goto v_33284;
v_33285:
    goto v_33312;
v_33304:
    v_34156 = elt(env, 3); // lie_cc
    goto v_33305;
v_33306:
    v_34155 = elt(env, 4); // lie_p
    goto v_33307;
v_33308:
    v_34154 = elt(env, 5); // lie_q
    goto v_33309;
v_33310:
    v_34153 = stack[-9];
    goto v_33311;
v_33312:
    goto v_33304;
v_33305:
    goto v_33306;
v_33307:
    goto v_33308;
v_33309:
    goto v_33310;
v_33311:
    v_34153 = list4(v_34156, v_34155, v_34154, v_34153);
    env = stack[-10];
    goto v_33286;
v_33287:
    goto v_33281;
v_33282:
    goto v_33283;
v_33284:
    goto v_33285;
v_33286:
    v_34153 = list3(stack[-1], stack[0], v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-6] = v_34153;
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_34153;
v_33320:
    goto v_33334;
v_33328:
    stack[0] = elt(env, 2); // difference
    goto v_33329;
v_33330:
    v_34153 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33331;
v_33332:
    v_34153 = stack[-3];
    goto v_33333;
v_33334:
    goto v_33328;
v_33329:
    goto v_33330;
v_33331:
    goto v_33332;
v_33333:
    v_34153 = list3(stack[0], v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33325;
    goto v_33319;
v_33325:
    goto v_33349;
v_33345:
    goto v_33360;
v_33352:
    v_34156 = elt(env, 3); // lie_cc
    goto v_33353;
v_33354:
    v_34155 = stack[-5];
    goto v_33355;
v_33356:
    v_34154 = stack[-4];
    goto v_33357;
v_33358:
    v_34153 = stack[-3];
    goto v_33359;
v_33360:
    goto v_33352;
v_33353:
    goto v_33354;
v_33355:
    goto v_33356;
v_33357:
    goto v_33358;
v_33359:
    v_34153 = list4(v_34156, v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    stack[-2] = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33346;
v_33347:
    goto v_33373;
v_33367:
    stack[-1] = elt(env, 8); // times
    goto v_33368;
v_33369:
    stack[0] = stack[-6];
    goto v_33370;
v_33371:
    goto v_33385;
v_33377:
    v_34156 = elt(env, 3); // lie_cc
    goto v_33378;
v_33379:
    v_34155 = elt(env, 4); // lie_p
    goto v_33380;
v_33381:
    v_34154 = elt(env, 5); // lie_q
    goto v_33382;
v_33383:
    v_34153 = stack[-3];
    goto v_33384;
v_33385:
    goto v_33377;
v_33378:
    goto v_33379;
v_33380:
    goto v_33381;
v_33382:
    goto v_33383;
v_33384:
    v_34153 = list4(v_34156, v_34155, v_34154, v_34153);
    env = stack[-10];
    goto v_33372;
v_33373:
    goto v_33367;
v_33368:
    goto v_33369;
v_33370:
    goto v_33371;
v_33372:
    v_34153 = list3(stack[-1], stack[0], v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33348;
v_33349:
    goto v_33345;
v_33346:
    goto v_33347;
v_33348:
    fn = elt(env, 18); // evalneq
    v_34153 = (*qfn2(fn))(fn, stack[-2], v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33343;
    goto v_33395;
v_33391:
    stack[0] = elt(env, 1); // lie_dim
    goto v_33392;
v_33393:
    v_34153 = (LispObject)32+TAG_FIXNUM; // 2
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33394;
v_33395:
    goto v_33391;
v_33392:
    goto v_33393;
v_33394:
    fn = elt(env, 15); // setk
    v_34153 = (*qfn2(fn))(fn, stack[0], v_34153);
    env = stack[-10];
    v_34153 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-5] = v_34153;
    goto v_33409;
v_33403:
    v_34155 = elt(env, 6); // plus
    goto v_33404;
v_33405:
    v_34154 = stack[-8];
    goto v_33406;
v_33407:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33408;
v_33409:
    goto v_33403;
v_33404:
    goto v_33405;
v_33406:
    goto v_33407;
v_33408:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-4] = v_34153;
    goto v_33421;
v_33415:
    v_34155 = elt(env, 6); // plus
    goto v_33416;
v_33417:
    v_34154 = stack[-8];
    goto v_33418;
v_33419:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33420;
v_33421:
    goto v_33415;
v_33416:
    goto v_33417;
v_33418:
    goto v_33419;
v_33420:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-3] = v_34153;
    goto v_33341;
v_33343:
v_33341:
    v_34153 = stack[-3];
    goto v_33435;
v_33429:
    v_34155 = elt(env, 6); // plus
    goto v_33430;
v_33431:
    v_34154 = v_34153;
    goto v_33432;
v_33433:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33434;
v_33435:
    goto v_33429;
v_33430:
    goto v_33431;
v_33432:
    goto v_33433;
v_33434:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-3] = v_34153;
    goto v_33320;
v_33319:
    v_34153 = stack[-4];
    goto v_33449;
v_33443:
    v_34155 = elt(env, 6); // plus
    goto v_33444;
v_33445:
    v_34154 = v_34153;
    goto v_33446;
v_33447:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33448;
v_33449:
    goto v_33443;
v_33444:
    goto v_33445;
v_33446:
    goto v_33447;
v_33448:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-4] = v_34153;
    goto v_33259;
v_33258:
    v_34153 = stack[-5];
    goto v_33463;
v_33457:
    v_34155 = elt(env, 6); // plus
    goto v_33458;
v_33459:
    v_34154 = v_34153;
    goto v_33460;
v_33461:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33462;
v_33463:
    goto v_33457;
v_33458:
    goto v_33459;
v_33460:
    goto v_33461;
v_33462:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-5] = v_34153;
    goto v_33226;
v_33225:
    goto v_33476;
v_33472:
    v_34153 = elt(env, 1); // lie_dim
    fn = elt(env, 14); // aeval
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33473;
v_33474:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33475;
v_33476:
    goto v_33472;
v_33473:
    goto v_33474;
v_33475:
    fn = elt(env, 19); // evalequal
    v_34153 = (*qfn2(fn))(fn, v_34154, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33470;
    goto v_33485;
v_33481:
    stack[0] = elt(env, 9); // lie_help
    goto v_33482;
v_33483:
    v_34153 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 14); // aeval
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33484;
v_33485:
    goto v_33481;
v_33482:
    goto v_33483;
v_33484:
    fn = elt(env, 15); // setk
    v_34153 = (*qfn2(fn))(fn, stack[0], v_34153);
    env = stack[-10];
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_34153;
v_33492:
    goto v_33506;
v_33500:
    stack[0] = elt(env, 2); // difference
    goto v_33501;
v_33502:
    v_34153 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33503;
v_33504:
    v_34153 = stack[-6];
    goto v_33505;
v_33506:
    goto v_33500;
v_33501:
    goto v_33502;
v_33503:
    goto v_33504;
v_33505:
    v_34153 = list3(stack[0], v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33497;
    goto v_33491;
v_33497:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_34153;
v_33515:
    goto v_33529;
v_33523:
    stack[0] = elt(env, 2); // difference
    goto v_33524;
v_33525:
    v_34153 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33526;
v_33527:
    v_34153 = stack[-5];
    goto v_33528;
v_33529:
    goto v_33523;
v_33524:
    goto v_33525;
v_33526:
    goto v_33527;
v_33528:
    v_34153 = list3(stack[0], v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33520;
    goto v_33514;
v_33520:
    goto v_33544;
v_33540:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_34153;
    v_34153 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_34153;
v_33549:
    goto v_33564;
v_33558:
    stack[0] = elt(env, 2); // difference
    goto v_33559;
v_33560:
    v_34153 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33561;
v_33562:
    v_34153 = stack[-4];
    goto v_33563;
v_33564:
    goto v_33558;
v_33559:
    goto v_33560;
v_33561:
    goto v_33562;
v_33563:
    v_34153 = list3(stack[0], v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33555;
    v_34153 = stack[-3];
    v_34154 = v_34153;
    goto v_33548;
v_33555:
    goto v_33578;
v_33572:
    stack[-2] = elt(env, 6); // plus
    goto v_33573;
v_33574:
    goto v_33588;
v_33582:
    stack[-1] = elt(env, 8); // times
    goto v_33583;
v_33584:
    goto v_33599;
v_33591:
    v_34156 = elt(env, 3); // lie_cc
    goto v_33592;
v_33593:
    v_34155 = elt(env, 4); // lie_p
    goto v_33594;
v_33595:
    v_34154 = elt(env, 5); // lie_q
    goto v_33596;
v_33597:
    v_34153 = stack[-4];
    goto v_33598;
v_33599:
    goto v_33591;
v_33592:
    goto v_33593;
v_33594:
    goto v_33595;
v_33596:
    goto v_33597;
v_33598:
    stack[0] = list4(v_34156, v_34155, v_34154, v_34153);
    env = stack[-10];
    goto v_33585;
v_33586:
    goto v_33613;
v_33605:
    v_34156 = elt(env, 3); // lie_cc
    goto v_33606;
v_33607:
    v_34155 = stack[-4];
    goto v_33608;
v_33609:
    v_34154 = stack[-6];
    goto v_33610;
v_33611:
    v_34153 = stack[-5];
    goto v_33612;
v_33613:
    goto v_33605;
v_33606:
    goto v_33607;
v_33608:
    goto v_33609;
v_33610:
    goto v_33611;
v_33612:
    v_34153 = list4(v_34156, v_34155, v_34154, v_34153);
    env = stack[-10];
    goto v_33587;
v_33588:
    goto v_33582;
v_33583:
    goto v_33584;
v_33585:
    goto v_33586;
v_33587:
    v_34153 = list3(stack[-1], stack[0], v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33575;
v_33576:
    v_34153 = stack[-3];
    goto v_33577;
v_33578:
    goto v_33572;
v_33573:
    goto v_33574;
v_33575:
    goto v_33576;
v_33577:
    v_34153 = list3(stack[-2], v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-3] = v_34153;
    v_34153 = stack[-4];
    goto v_33629;
v_33623:
    v_34155 = elt(env, 6); // plus
    goto v_33624;
v_33625:
    v_34154 = v_34153;
    goto v_33626;
v_33627:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33628;
v_33629:
    goto v_33623;
v_33624:
    goto v_33625;
v_33626:
    goto v_33627;
v_33628:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-4] = v_34153;
    goto v_33549;
v_33548:
    goto v_33541;
v_33542:
    v_34153 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33543;
v_33544:
    goto v_33540;
v_33541:
    goto v_33542;
v_33543:
    fn = elt(env, 18); // evalneq
    v_34153 = (*qfn2(fn))(fn, v_34154, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33538;
    goto v_33639;
v_33635:
    stack[0] = elt(env, 9); // lie_help
    goto v_33636;
v_33637:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33638;
v_33639:
    goto v_33635;
v_33636:
    goto v_33637;
v_33638:
    fn = elt(env, 15); // setk
    v_34153 = (*qfn2(fn))(fn, stack[0], v_34153);
    env = stack[-10];
    goto v_33648;
v_33644:
    stack[0] = elt(env, 10); // lie_s
    goto v_33645;
v_33646:
    v_34153 = stack[-6];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33647;
v_33648:
    goto v_33644;
v_33645:
    goto v_33646;
v_33647:
    fn = elt(env, 15); // setk
    v_34153 = (*qfn2(fn))(fn, stack[0], v_34153);
    env = stack[-10];
    v_34153 = stack[-5];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-9] = v_34153;
    goto v_33662;
v_33656:
    v_34155 = elt(env, 6); // plus
    goto v_33657;
v_33658:
    v_34154 = stack[-8];
    goto v_33659;
v_33660:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33661;
v_33662:
    goto v_33656;
v_33657:
    goto v_33658;
v_33659:
    goto v_33660;
v_33661:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-5] = v_34153;
    stack[-6] = v_34153;
    goto v_33536;
v_33538:
v_33536:
    v_34153 = stack[-5];
    goto v_33676;
v_33670:
    v_34155 = elt(env, 6); // plus
    goto v_33671;
v_33672:
    v_34154 = v_34153;
    goto v_33673;
v_33674:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33675;
v_33676:
    goto v_33670;
v_33671:
    goto v_33672;
v_33673:
    goto v_33674;
v_33675:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-5] = v_34153;
    goto v_33515;
v_33514:
    v_34153 = stack[-6];
    goto v_33690;
v_33684:
    v_34155 = elt(env, 6); // plus
    goto v_33685;
v_33686:
    v_34154 = v_34153;
    goto v_33687;
v_33688:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33689;
v_33690:
    goto v_33684;
v_33685:
    goto v_33686;
v_33687:
    goto v_33688;
v_33689:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-6] = v_34153;
    goto v_33492;
v_33491:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_34153;
v_33697:
    goto v_33711;
v_33705:
    stack[0] = elt(env, 2); // difference
    goto v_33706;
v_33707:
    v_34153 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33708;
v_33709:
    v_34153 = stack[-1];
    goto v_33710;
v_33711:
    goto v_33705;
v_33706:
    goto v_33707;
v_33708:
    goto v_33709;
v_33710:
    v_34153 = list3(stack[0], v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33702;
    goto v_33696;
v_33702:
    goto v_33722;
v_33718:
    goto v_33730;
v_33724:
    v_34155 = elt(env, 11); // lientrans
    goto v_33725;
v_33726:
    v_34154 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33727;
v_33728:
    v_34153 = stack[-1];
    goto v_33729;
v_33730:
    goto v_33724;
v_33725:
    goto v_33726;
v_33727:
    goto v_33728;
v_33729:
    stack[0] = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    goto v_33719;
v_33720:
    goto v_33744;
v_33736:
    v_34156 = elt(env, 3); // lie_cc
    goto v_33737;
v_33738:
    v_34155 = elt(env, 4); // lie_p
    goto v_33739;
v_33740:
    v_34154 = elt(env, 5); // lie_q
    goto v_33741;
v_33742:
    v_34153 = stack[-1];
    goto v_33743;
v_33744:
    goto v_33736;
v_33737:
    goto v_33738;
v_33739:
    goto v_33740;
v_33741:
    goto v_33742;
v_33743:
    v_34153 = list4(v_34156, v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33721;
v_33722:
    goto v_33718;
v_33719:
    goto v_33720;
v_33721:
    fn = elt(env, 15); // setk
    v_34153 = (*qfn2(fn))(fn, stack[0], v_34153);
    env = stack[-10];
    v_34153 = stack[-1];
    goto v_33759;
v_33753:
    v_34155 = elt(env, 6); // plus
    goto v_33754;
v_33755:
    v_34154 = v_34153;
    goto v_33756;
v_33757:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33758;
v_33759:
    goto v_33753;
v_33754:
    goto v_33755;
v_33756:
    goto v_33757;
v_33758:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-1] = v_34153;
    goto v_33697;
v_33696:
    goto v_33772;
v_33768:
    v_34153 = elt(env, 9); // lie_help
    fn = elt(env, 14); // aeval
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33769;
v_33770:
    v_34153 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33771;
v_33772:
    goto v_33768;
v_33769:
    goto v_33770;
v_33771:
    fn = elt(env, 19); // evalequal
    v_34153 = (*qfn2(fn))(fn, v_34154, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33766;
    goto v_33781;
v_33777:
    goto v_33789;
v_33783:
    v_34155 = elt(env, 11); // lientrans
    goto v_33784;
v_33785:
    v_34154 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_33786;
v_33787:
    v_34153 = elt(env, 4); // lie_p
    goto v_33788;
v_33789:
    goto v_33783;
v_33784:
    goto v_33785;
v_33786:
    goto v_33787;
v_33788:
    stack[-1] = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    goto v_33778;
v_33779:
    goto v_33798;
v_33794:
    goto v_33806;
v_33800:
    v_34155 = elt(env, 11); // lientrans
    goto v_33801;
v_33802:
    v_34154 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_33803;
v_33804:
    v_34153 = elt(env, 5); // lie_q
    goto v_33805;
v_33806:
    goto v_33800;
v_33801:
    goto v_33802;
v_33803:
    goto v_33804;
v_33805:
    stack[0] = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    goto v_33795;
v_33796:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 14); // aeval
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33797;
v_33798:
    goto v_33794;
v_33795:
    goto v_33796;
v_33797:
    fn = elt(env, 15); // setk
    v_34153 = (*qfn2(fn))(fn, stack[0], v_34153);
    env = stack[-10];
    goto v_33780;
v_33781:
    goto v_33777;
v_33778:
    goto v_33779;
v_33780:
    fn = elt(env, 15); // setk
    v_34153 = (*qfn2(fn))(fn, stack[-1], v_34153);
    env = stack[-10];
    goto v_33817;
v_33813:
    stack[0] = elt(env, 12); // lie_kk!*
    goto v_33814;
v_33815:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 14); // aeval
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33816;
v_33817:
    goto v_33813;
v_33814:
    goto v_33815;
v_33816:
    fn = elt(env, 15); // setk
    v_34153 = (*qfn2(fn))(fn, stack[0], v_34153);
    env = stack[-10];
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_34153;
v_33824:
    goto v_33838;
v_33832:
    stack[0] = elt(env, 2); // difference
    goto v_33833;
v_33834:
    v_34153 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33835;
v_33836:
    v_34153 = stack[-1];
    goto v_33837;
v_33838:
    goto v_33832;
v_33833:
    goto v_33834;
v_33835:
    goto v_33836;
v_33837:
    v_34153 = list3(stack[0], v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33829;
    goto v_33823;
v_33829:
    goto v_33854;
v_33850:
    goto v_33865;
v_33857:
    v_34156 = elt(env, 3); // lie_cc
    goto v_33858;
v_33859:
    v_34155 = elt(env, 4); // lie_p
    goto v_33860;
v_33861:
    v_34154 = elt(env, 5); // lie_q
    goto v_33862;
v_33863:
    v_34153 = stack[-1];
    goto v_33864;
v_33865:
    goto v_33857;
v_33858:
    goto v_33859;
v_33860:
    goto v_33861;
v_33862:
    goto v_33863;
v_33864:
    v_34153 = list4(v_34156, v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33851;
v_33852:
    v_34153 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33853;
v_33854:
    goto v_33850;
v_33851:
    goto v_33852;
v_33853:
    fn = elt(env, 18); // evalneq
    v_34153 = (*qfn2(fn))(fn, v_34154, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33847;
    goto v_33878;
v_33874:
    stack[0] = stack[-1];
    goto v_33875;
v_33876:
    v_34153 = elt(env, 4); // lie_p
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33877;
v_33878:
    goto v_33874;
v_33875:
    goto v_33876;
v_33877:
    fn = elt(env, 18); // evalneq
    v_34153 = (*qfn2(fn))(fn, stack[0], v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33847;
    goto v_33888;
v_33884:
    stack[0] = stack[-1];
    goto v_33885;
v_33886:
    v_34153 = elt(env, 5); // lie_q
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33887;
v_33888:
    goto v_33884;
v_33885:
    goto v_33886;
v_33887:
    fn = elt(env, 18); // evalneq
    v_34153 = (*qfn2(fn))(fn, stack[0], v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33847;
    goto v_33897;
v_33893:
    stack[0] = elt(env, 13); // lie_tt
    goto v_33894;
v_33895:
    v_34153 = stack[-1];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33896;
v_33897:
    goto v_33893;
v_33894:
    goto v_33895;
v_33896:
    fn = elt(env, 15); // setk
    v_34153 = (*qfn2(fn))(fn, stack[0], v_34153);
    env = stack[-10];
    goto v_33909;
v_33903:
    v_34155 = elt(env, 6); // plus
    goto v_33904;
v_33905:
    v_34154 = stack[-8];
    goto v_33906;
v_33907:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33908;
v_33909:
    goto v_33903;
v_33904:
    goto v_33905;
v_33906:
    goto v_33907;
v_33908:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-1] = v_34153;
    goto v_33845;
v_33847:
v_33845:
    v_34153 = stack[-1];
    goto v_33923;
v_33917:
    v_34155 = elt(env, 6); // plus
    goto v_33918;
v_33919:
    v_34154 = v_34153;
    goto v_33920;
v_33921:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33922;
v_33923:
    goto v_33917;
v_33918:
    goto v_33919;
v_33920:
    goto v_33921;
v_33922:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-1] = v_34153;
    goto v_33824;
v_33823:
    goto v_33764;
v_33766:
    goto v_33934;
v_33930:
    goto v_33942;
v_33936:
    v_34155 = elt(env, 11); // lientrans
    goto v_33937;
v_33938:
    v_34154 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_33939;
v_33940:
    v_34153 = elt(env, 10); // lie_s
    goto v_33941;
v_33942:
    goto v_33936;
v_33937:
    goto v_33938;
v_33939:
    goto v_33940;
v_33941:
    stack[-7] = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    goto v_33931;
v_33932:
    goto v_33954;
v_33948:
    stack[-6] = elt(env, 7); // quotient
    goto v_33949;
v_33950:
    goto v_33965;
v_33957:
    v_34156 = elt(env, 3); // lie_cc
    goto v_33958;
v_33959:
    v_34155 = elt(env, 4); // lie_p
    goto v_33960;
v_33961:
    v_34154 = elt(env, 5); // lie_q
    goto v_33962;
v_33963:
    v_34153 = stack[-9];
    goto v_33964;
v_33965:
    goto v_33957;
v_33958:
    goto v_33959;
v_33960:
    goto v_33961;
v_33962:
    goto v_33963;
v_33964:
    stack[-5] = list4(v_34156, v_34155, v_34154, v_34153);
    env = stack[-10];
    goto v_33951;
v_33952:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_34153;
    v_34153 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_34153;
v_33974:
    goto v_33989;
v_33983:
    stack[0] = elt(env, 2); // difference
    goto v_33984;
v_33985:
    v_34153 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33986;
v_33987:
    v_34153 = stack[-4];
    goto v_33988;
v_33989:
    goto v_33983;
v_33984:
    goto v_33985;
v_33986:
    goto v_33987;
v_33988:
    v_34153 = list3(stack[0], v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_33980;
    v_34153 = stack[-3];
    goto v_33973;
v_33980:
    goto v_34003;
v_33997:
    stack[-2] = elt(env, 6); // plus
    goto v_33998;
v_33999:
    goto v_34013;
v_34007:
    stack[-1] = elt(env, 8); // times
    goto v_34008;
v_34009:
    goto v_34024;
v_34016:
    v_34156 = elt(env, 3); // lie_cc
    goto v_34017;
v_34018:
    v_34155 = elt(env, 4); // lie_p
    goto v_34019;
v_34020:
    v_34154 = elt(env, 5); // lie_q
    goto v_34021;
v_34022:
    v_34153 = stack[-4];
    goto v_34023;
v_34024:
    goto v_34016;
v_34017:
    goto v_34018;
v_34019:
    goto v_34020;
v_34021:
    goto v_34022;
v_34023:
    stack[0] = list4(v_34156, v_34155, v_34154, v_34153);
    env = stack[-10];
    goto v_34010;
v_34011:
    goto v_34038;
v_34030:
    v_34156 = elt(env, 3); // lie_cc
    goto v_34031;
v_34032:
    v_34155 = stack[-4];
    goto v_34033;
v_34034:
    v_34154 = elt(env, 10); // lie_s
    goto v_34035;
v_34036:
    v_34153 = stack[-9];
    goto v_34037;
v_34038:
    goto v_34030;
v_34031:
    goto v_34032;
v_34033:
    goto v_34034;
v_34035:
    goto v_34036;
v_34037:
    v_34153 = list4(v_34156, v_34155, v_34154, v_34153);
    env = stack[-10];
    goto v_34012;
v_34013:
    goto v_34007;
v_34008:
    goto v_34009;
v_34010:
    goto v_34011;
v_34012:
    v_34153 = list3(stack[-1], stack[0], v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_34000;
v_34001:
    v_34153 = stack[-3];
    goto v_34002;
v_34003:
    goto v_33997;
v_33998:
    goto v_33999;
v_34000:
    goto v_34001;
v_34002:
    v_34153 = list3(stack[-2], v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-3] = v_34153;
    v_34153 = stack[-4];
    goto v_34054;
v_34048:
    v_34155 = elt(env, 6); // plus
    goto v_34049;
v_34050:
    v_34154 = v_34153;
    goto v_34051;
v_34052:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34053;
v_34054:
    goto v_34048;
v_34049:
    goto v_34050;
v_34051:
    goto v_34052;
v_34053:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-4] = v_34153;
    goto v_33974;
v_33973:
    goto v_33953;
v_33954:
    goto v_33948;
v_33949:
    goto v_33950;
v_33951:
    goto v_33952;
v_33953:
    v_34153 = list3(stack[-6], stack[-5], v_34153);
    env = stack[-10];
    fn = elt(env, 14); // aeval
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_33933;
v_33934:
    goto v_33930;
v_33931:
    goto v_33932;
v_33933:
    fn = elt(env, 15); // setk
    v_34153 = (*qfn2(fn))(fn, stack[-7], v_34153);
    env = stack[-10];
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_34153;
v_34061:
    goto v_34075;
v_34069:
    stack[0] = elt(env, 2); // difference
    goto v_34070;
v_34071:
    v_34153 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_34072;
v_34073:
    v_34153 = stack[-1];
    goto v_34074;
v_34075:
    goto v_34069;
v_34070:
    goto v_34071;
v_34072:
    goto v_34073;
v_34074:
    v_34153 = list3(stack[0], v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_34066;
    goto v_34060;
v_34066:
    goto v_34091;
v_34087:
    goto v_34102;
v_34094:
    v_34156 = elt(env, 3); // lie_cc
    goto v_34095;
v_34096:
    v_34155 = elt(env, 4); // lie_p
    goto v_34097;
v_34098:
    v_34154 = elt(env, 5); // lie_q
    goto v_34099;
v_34100:
    v_34153 = stack[-1];
    goto v_34101;
v_34102:
    goto v_34094;
v_34095:
    goto v_34096;
v_34097:
    goto v_34098;
v_34099:
    goto v_34100;
v_34101:
    v_34153 = list4(v_34156, v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34154 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_34088;
v_34089:
    v_34153 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34090;
v_34091:
    goto v_34087;
v_34088:
    goto v_34089;
v_34090:
    fn = elt(env, 18); // evalneq
    v_34153 = (*qfn2(fn))(fn, v_34154, v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_34084;
    goto v_34114;
v_34110:
    stack[0] = stack[-1];
    goto v_34111;
v_34112:
    v_34153 = elt(env, 10); // lie_s
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_34113;
v_34114:
    goto v_34110;
v_34111:
    goto v_34112;
v_34113:
    fn = elt(env, 18); // evalneq
    v_34153 = (*qfn2(fn))(fn, stack[0], v_34153);
    env = stack[-10];
    if (v_34153 == nil) goto v_34084;
    goto v_34123;
v_34119:
    stack[0] = elt(env, 13); // lie_tt
    goto v_34120;
v_34121:
    v_34153 = stack[-1];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    goto v_34122;
v_34123:
    goto v_34119;
v_34120:
    goto v_34121;
v_34122:
    fn = elt(env, 15); // setk
    v_34153 = (*qfn2(fn))(fn, stack[0], v_34153);
    env = stack[-10];
    goto v_34135;
v_34129:
    v_34155 = elt(env, 6); // plus
    goto v_34130;
v_34131:
    v_34154 = stack[-8];
    goto v_34132;
v_34133:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34134;
v_34135:
    goto v_34129;
v_34130:
    goto v_34131;
v_34132:
    goto v_34133;
v_34134:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-1] = v_34153;
    goto v_34082;
v_34084:
v_34082:
    v_34153 = stack[-1];
    goto v_34149;
v_34143:
    v_34155 = elt(env, 6); // plus
    goto v_34144;
v_34145:
    v_34154 = v_34153;
    goto v_34146;
v_34147:
    v_34153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34148;
v_34149:
    goto v_34143;
v_34144:
    goto v_34145;
v_34146:
    goto v_34147;
v_34148:
    v_34153 = list3(v_34155, v_34154, v_34153);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_34153 = (*qfn1(fn))(fn, v_34153);
    env = stack[-10];
    stack[-1] = v_34153;
    goto v_34061;
v_34060:
    goto v_33764;
v_33764:
    goto v_33468;
v_33470:
v_33468:
    goto v_33211;
v_33213:
v_33211:
    v_34153 = nil;
    return onevalue(v_34153);
}



// Code for st_extract_symcells1

static LispObject CC_st_extract_symcells1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33174, v_33175, v_33176;
    LispObject fn;
    LispObject v_33006, v_33005, v_33004;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "st_extract_symcells1");
    va_start(aa, nargs);
    v_33004 = va_arg(aa, LispObject);
    v_33005 = va_arg(aa, LispObject);
    v_33006 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_33006,v_33005,v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_33004,v_33005,v_33006);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_33006;
    stack[-5] = v_33005;
    stack[0] = v_33004;
// end of prologue
    v_33174 = stack[0];
    v_33174 = qcdr(v_33174);
    v_33174 = qcar(v_33174);
    fn = elt(env, 3); // listp
    v_33174 = (*qfn1(fn))(fn, v_33174);
    env = stack[-7];
    if (v_33174 == nil) goto v_33015;
    else goto v_33016;
v_33015:
    goto v_33028;
v_33022:
    stack[-1] = stack[-4];
    goto v_33023;
v_33024:
    goto v_33035;
v_33031:
    v_33175 = stack[0];
    goto v_33032;
v_33033:
    v_33174 = stack[-5];
    goto v_33034;
v_33035:
    goto v_33031;
v_33032:
    goto v_33033;
v_33034:
    stack[0] = cons(v_33175, v_33174);
    env = stack[-7];
    goto v_33025;
v_33026:
    v_33174 = stack[-4];
    v_33174 = add1(v_33174);
    goto v_33027;
v_33028:
    goto v_33022;
v_33023:
    goto v_33024;
v_33025:
    goto v_33026;
v_33027:
    {
        LispObject v_33184 = stack[-1];
        LispObject v_33185 = stack[0];
        return list3(v_33184, v_33185, v_33174);
    }
v_33016:
    goto v_33047;
v_33043:
    v_33174 = stack[0];
    stack[-6] = qcar(v_33174);
    goto v_33044;
v_33045:
    v_33174 = stack[0];
    v_33174 = qcdr(v_33174);
    stack[-3] = v_33174;
    v_33174 = stack[-3];
    if (v_33174 == nil) goto v_33060;
    else goto v_33061;
v_33060:
    v_33174 = nil;
    goto v_33054;
v_33061:
    v_33174 = stack[-3];
    v_33174 = qcar(v_33174);
    goto v_33075;
v_33069:
    v_33176 = v_33174;
    goto v_33070;
v_33071:
    v_33175 = stack[-5];
    goto v_33072;
v_33073:
    v_33174 = stack[-4];
    goto v_33074;
v_33075:
    goto v_33069;
v_33070:
    goto v_33071;
v_33072:
    goto v_33073;
v_33074:
    v_33174 = CC_st_extract_symcells1(elt(env, 0), 3, v_33176, v_33175, v_33174);
    env = stack[-7];
    v_33175 = v_33174;
    v_33175 = qcdr(v_33175);
    v_33175 = qcar(v_33175);
    stack[-5] = v_33175;
    v_33175 = v_33174;
    v_33175 = qcdr(v_33175);
    v_33175 = qcdr(v_33175);
    v_33175 = qcar(v_33175);
    stack[-4] = v_33175;
    v_33175 = v_33174;
    v_33175 = qcar(v_33175);
    if (is_number(v_33175)) goto v_33088;
    else goto v_33089;
v_33088:
    goto v_33097;
v_33093:
    v_33175 = elt(env, 2); // !*
    goto v_33094;
v_33095:
    v_33174 = qcar(v_33174);
    goto v_33096;
v_33097:
    goto v_33093;
v_33094:
    goto v_33095;
v_33096:
    v_33174 = list2(v_33175, v_33174);
    env = stack[-7];
    goto v_33087;
v_33089:
    v_33174 = qcar(v_33174);
    goto v_33087;
    v_33174 = nil;
v_33087:
    v_33174 = ncons(v_33174);
    env = stack[-7];
    stack[-1] = v_33174;
    stack[-2] = v_33174;
v_33055:
    v_33174 = stack[-3];
    v_33174 = qcdr(v_33174);
    stack[-3] = v_33174;
    v_33174 = stack[-3];
    if (v_33174 == nil) goto v_33109;
    else goto v_33110;
v_33109:
    v_33174 = stack[-2];
    goto v_33054;
v_33110:
    goto v_33118;
v_33114:
    stack[0] = stack[-1];
    goto v_33115;
v_33116:
    v_33174 = stack[-3];
    v_33174 = qcar(v_33174);
    goto v_33131;
v_33125:
    v_33176 = v_33174;
    goto v_33126;
v_33127:
    v_33175 = stack[-5];
    goto v_33128;
v_33129:
    v_33174 = stack[-4];
    goto v_33130;
v_33131:
    goto v_33125;
v_33126:
    goto v_33127;
v_33128:
    goto v_33129;
v_33130:
    v_33174 = CC_st_extract_symcells1(elt(env, 0), 3, v_33176, v_33175, v_33174);
    env = stack[-7];
    v_33175 = v_33174;
    v_33175 = qcdr(v_33175);
    v_33175 = qcar(v_33175);
    stack[-5] = v_33175;
    v_33175 = v_33174;
    v_33175 = qcdr(v_33175);
    v_33175 = qcdr(v_33175);
    v_33175 = qcar(v_33175);
    stack[-4] = v_33175;
    v_33175 = v_33174;
    v_33175 = qcar(v_33175);
    if (is_number(v_33175)) goto v_33144;
    else goto v_33145;
v_33144:
    goto v_33153;
v_33149:
    v_33175 = elt(env, 2); // !*
    goto v_33150;
v_33151:
    v_33174 = qcar(v_33174);
    goto v_33152;
v_33153:
    goto v_33149;
v_33150:
    goto v_33151;
v_33152:
    v_33174 = list2(v_33175, v_33174);
    env = stack[-7];
    goto v_33143;
v_33145:
    v_33174 = qcar(v_33174);
    goto v_33143;
    v_33174 = nil;
v_33143:
    v_33174 = ncons(v_33174);
    env = stack[-7];
    goto v_33117;
v_33118:
    goto v_33114;
v_33115:
    goto v_33116;
v_33117:
    v_33174 = Lrplacd(nil, stack[0], v_33174);
    env = stack[-7];
    v_33174 = stack[-1];
    v_33174 = qcdr(v_33174);
    stack[-1] = v_33174;
    goto v_33055;
v_33054:
    goto v_33046;
v_33047:
    goto v_33043;
v_33044:
    goto v_33045;
v_33046:
    v_33174 = cons(stack[-6], v_33174);
    goto v_33170;
v_33164:
    v_33176 = v_33174;
    goto v_33165;
v_33166:
    v_33175 = stack[-5];
    goto v_33167;
v_33168:
    v_33174 = stack[-4];
    goto v_33169;
v_33170:
    goto v_33164;
v_33165:
    goto v_33166;
v_33167:
    goto v_33168;
v_33169:
    return list3(v_33176, v_33175, v_33174);
    v_33174 = nil;
    return onevalue(v_33174);
}



// Code for addinds

static LispObject CC_addinds(LispObject env,
                         LispObject v_33004, LispObject v_33005)
{
    env = qenv(env);
    LispObject v_33070, v_33071;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33005,v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33004,v_33005);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_33005;
    stack[-1] = v_33004;
// end of prologue
    stack[-2] = nil;
v_33010:
    v_33070 = stack[-1];
    if (v_33070 == nil) goto v_33013;
    else goto v_33014;
v_33013:
    v_33070 = stack[0];
    if (v_33070 == nil) goto v_33018;
    else goto v_33019;
v_33018:
    v_33070 = stack[-2];
    {
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(fn, v_33070);
    }
v_33019:
    goto v_33030;
v_33026:
    stack[0] = stack[-2];
    goto v_33027;
v_33028:
    v_33070 = elt(env, 1); // "Powrhs too long"
    fn = elt(env, 4); // interr
    v_33070 = (*qfn1(fn))(fn, v_33070);
    env = stack[-3];
    goto v_33029;
v_33030:
    goto v_33026;
v_33027:
    goto v_33028;
v_33029:
    {
        LispObject v_33075 = stack[0];
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(fn, v_33075, v_33070);
    }
    goto v_33012;
v_33014:
    v_33070 = stack[0];
    if (v_33070 == nil) goto v_33034;
    else goto v_33035;
v_33034:
    goto v_33042;
v_33038:
    stack[0] = stack[-2];
    goto v_33039;
v_33040:
    v_33070 = elt(env, 2); // "Powu too long"
    fn = elt(env, 4); // interr
    v_33070 = (*qfn1(fn))(fn, v_33070);
    env = stack[-3];
    goto v_33041;
v_33042:
    goto v_33038;
v_33039:
    goto v_33040;
v_33041:
    {
        LispObject v_33076 = stack[0];
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(fn, v_33076, v_33070);
    }
v_33035:
    goto v_33053;
v_33049:
    goto v_33059;
v_33055:
    v_33070 = stack[-1];
    v_33071 = qcar(v_33070);
    goto v_33056;
v_33057:
    v_33070 = stack[0];
    v_33070 = qcar(v_33070);
    v_33070 = qcar(v_33070);
    goto v_33058;
v_33059:
    goto v_33055;
v_33056:
    goto v_33057;
v_33058:
    v_33071 = plus2(v_33071, v_33070);
    env = stack[-3];
    goto v_33050;
v_33051:
    v_33070 = stack[-2];
    goto v_33052;
v_33053:
    goto v_33049;
v_33050:
    goto v_33051;
v_33052:
    v_33070 = cons(v_33071, v_33070);
    env = stack[-3];
    stack[-2] = v_33070;
    v_33070 = stack[-1];
    v_33070 = qcdr(v_33070);
    stack[-1] = v_33070;
    v_33070 = stack[0];
    v_33070 = qcdr(v_33070);
    stack[0] = v_33070;
    goto v_33010;
v_33012:
    v_33070 = nil;
    return onevalue(v_33070);
}



// Code for ofsf_factsf

static LispObject CC_ofsf_factsf(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33060, v_33061;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33004);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33004;
// end of prologue
    stack[-1] = nil;
v_33010:
    goto v_33022;
v_33018:
    v_33061 = stack[0];
    goto v_33019;
v_33020:
    v_33060 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33021;
v_33022:
    goto v_33018;
v_33019:
    goto v_33020;
v_33021:
    v_33060 = (LispObject)lesseq2(v_33061, v_33060);
    v_33060 = v_33060 ? lisp_true : nil;
    env = stack[-2];
    if (v_33060 == nil) goto v_33016;
    goto v_33011;
v_33016:
    goto v_33030;
v_33026:
    v_33061 = stack[0];
    goto v_33027;
v_33028:
    v_33060 = stack[-1];
    goto v_33029;
v_33030:
    goto v_33026;
v_33027:
    goto v_33028;
v_33029:
    v_33060 = cons(v_33061, v_33060);
    env = stack[-2];
    stack[-1] = v_33060;
    goto v_33038;
v_33034:
    goto v_33035;
v_33036:
    v_33060 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 1); // negf
    v_33060 = (*qfn1(fn))(fn, v_33060);
    env = stack[-2];
    goto v_33037;
v_33038:
    goto v_33034;
v_33035:
    goto v_33036;
v_33037:
    fn = elt(env, 2); // addf
    v_33060 = (*qfn2(fn))(fn, stack[0], v_33060);
    env = stack[-2];
    stack[0] = v_33060;
    goto v_33010;
v_33011:
    v_33060 = (LispObject)16+TAG_FIXNUM; // 1
    v_33061 = v_33060;
v_33012:
    v_33060 = stack[-1];
    if (v_33060 == nil) goto v_33045;
    else goto v_33046;
v_33045:
    v_33060 = v_33061;
    goto v_33009;
v_33046:
    goto v_33054;
v_33050:
    v_33060 = stack[-1];
    v_33060 = qcar(v_33060);
    goto v_33051;
v_33052:
    goto v_33053;
v_33054:
    goto v_33050;
v_33051:
    goto v_33052;
v_33053:
    fn = elt(env, 3); // multf
    v_33060 = (*qfn2(fn))(fn, v_33060, v_33061);
    env = stack[-2];
    v_33061 = v_33060;
    v_33060 = stack[-1];
    v_33060 = qcdr(v_33060);
    stack[-1] = v_33060;
    goto v_33012;
v_33009:
    return onevalue(v_33060);
}



// Code for matrix_input_test

static LispObject CC_matrix_input_test(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33036, v_33037, v_33038;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33004);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33037 = v_33004;
// end of prologue
    goto v_33018;
v_33014:
    v_33038 = v_33037;
    goto v_33015;
v_33016:
    v_33036 = elt(env, 1); // mat
    goto v_33017;
v_33018:
    goto v_33014;
v_33015:
    goto v_33016;
v_33017:
    if (!consp(v_33038)) goto v_33011;
    v_33038 = qcar(v_33038);
    if (v_33038 == v_33036) goto v_33012;
v_33011:
    goto v_33029;
v_33023:
    v_33038 = elt(env, 2); // "ERROR: `"
    goto v_33024;
v_33025:
    goto v_33026;
v_33027:
    v_33036 = elt(env, 3); // "' is non matrix input."
    goto v_33028;
v_33029:
    goto v_33023;
v_33024:
    goto v_33025;
v_33026:
    goto v_33027;
v_33028:
    v_33036 = list3(v_33038, v_33037, v_33036);
    env = stack[0];
    fn = elt(env, 4); // rederr
    v_33036 = (*qfn1(fn))(fn, v_33036);
    goto v_33010;
v_33012:
    v_33036 = v_33037;
    goto v_33007;
v_33010:
    v_33036 = nil;
v_33007:
    return onevalue(v_33036);
}



// Code for vevzero!?1

static LispObject CC_vevzeroW1(LispObject env,
                         LispObject v_33004)
{
    env = qenv(env);
    LispObject v_33058, v_33059, v_33060;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33059 = v_33004;
// end of prologue
v_33003:
    v_33058 = v_33059;
    if (v_33058 == nil) goto v_33008;
    else goto v_33009;
v_33008:
    v_33058 = lisp_true;
    goto v_33007;
v_33009:
    goto v_33022;
v_33018:
    v_33058 = v_33059;
    v_33060 = qcar(v_33058);
    goto v_33019;
v_33020:
    v_33058 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33021;
v_33022:
    goto v_33018;
v_33019:
    goto v_33020;
v_33021:
    if (v_33060 == v_33058) goto v_33016;
    else goto v_33017;
v_33016:
    v_33058 = v_33059;
    v_33058 = qcdr(v_33058);
    if (v_33058 == nil) goto v_33028;
    else goto v_33029;
v_33028:
    v_33058 = lisp_true;
    goto v_33027;
v_33029:
    goto v_33043;
v_33039:
    v_33058 = v_33059;
    v_33058 = qcdr(v_33058);
    v_33060 = qcar(v_33058);
    goto v_33040;
v_33041:
    v_33058 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33042;
v_33043:
    goto v_33039;
v_33040:
    goto v_33041;
v_33042:
    if (v_33060 == v_33058) goto v_33037;
    else goto v_33038;
v_33037:
    v_33058 = v_33059;
    v_33058 = qcdr(v_33058);
    v_33058 = qcdr(v_33058);
    v_33059 = v_33058;
    goto v_33003;
v_33038:
    v_33058 = nil;
    goto v_33036;
    v_33058 = nil;
v_33036:
    goto v_33027;
    v_33058 = nil;
v_33027:
    goto v_33015;
v_33017:
    v_33058 = nil;
    goto v_33015;
    v_33058 = nil;
v_33015:
    goto v_33007;
    v_33058 = nil;
v_33007:
    return onevalue(v_33058);
}



// Code for remove_critical_pairs

static LispObject CC_remove_critical_pairs(LispObject env,
                         LispObject v_33004, LispObject v_33005)
{
    env = qenv(env);
    LispObject v_33021, v_33022;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33005,v_33004);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33004,v_33005);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_33005;
    v_33021 = v_33004;
// end of prologue
    v_33022 = v_33021;
    if (v_33022 == nil) goto v_33010;
    goto v_33017;
v_33013:
    v_33022 = stack[0];
    goto v_33014;
v_33015:
    goto v_33016;
v_33017:
    goto v_33013;
v_33014:
    goto v_33015;
v_33016:
    fn = elt(env, 1); // remove_items
    v_33021 = (*qfn2(fn))(fn, v_33022, v_33021);
    goto v_33008;
v_33010:
v_33008:
    v_33021 = stack[0];
    return onevalue(v_33021);
}



setup_type const u56_setup[] =
{
    {"equal+matrices+p",        TOO_FEW_2,      CC_equalLmatricesLp,WRONG_NO_2},
    {"talp_try2",               CC_talp_try2,   TOO_MANY_1,    WRONG_NO_1},
    {"parseml",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_parseml},
    {"crprimp",                 CC_crprimp,     TOO_MANY_1,    WRONG_NO_1},
    {"mkratnum",                CC_mkratnum,    TOO_MANY_1,    WRONG_NO_1},
    {"fast-augment-columns",    TOO_FEW_2,      CC_fastKaugmentKcolumns,WRONG_NO_2},
    {"atlas_edges",             CC_atlas_edges, TOO_MANY_1,    WRONG_NO_1},
    {"compactf3",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_compactf3},
    {"dpmat_gbtag",             CC_dpmat_gbtag, TOO_MANY_1,    WRONG_NO_1},
    {"*v2j",                    CC_Hv2j,        TOO_MANY_1,    WRONG_NO_1},
    {"dummy_nam",               CC_dummy_nam,   TOO_MANY_1,    WRONG_NO_1},
    {"general-negate-term",     CC_generalKnegateKterm,TOO_MANY_1,WRONG_NO_1},
    {"cr2rderr",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cr2rderr},
    {"sort_according_to",       TOO_FEW_2,      CC_sort_according_to,WRONG_NO_2},
    {"square-free-mod-p",       CC_squareKfreeKmodKp,TOO_MANY_1,WRONG_NO_1},
    {"initmonomials",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_initmonomials},
    {"ofsf_exploitknowl",       CC_ofsf_exploitknowl,TOO_MANY_1,WRONG_NO_1},
    {"depend-p",                TOO_FEW_2,      CC_dependKp,   WRONG_NO_2},
    {"ofsf_simpat",             CC_ofsf_simpat, TOO_MANY_1,    WRONG_NO_1},
    {"pasf_ceeq",               CC_pasf_ceeq,   TOO_MANY_1,    WRONG_NO_1},
    {"bc_pmon",                 TOO_FEW_2,      CC_bc_pmon,    WRONG_NO_2},
    {"xpartitsq",               CC_xpartitsq,   TOO_MANY_1,    WRONG_NO_1},
    {"binc",                    TOO_FEW_2,      CC_binc,       WRONG_NO_2},
    {"gi",                      TOO_FEW_2,      CC_gi,         WRONG_NO_2},
    {"exports",                 CC_exports,     TOO_MANY_1,    WRONG_NO_1},
    {"sfto_deggcd1",            TOO_FEW_2,      CC_sfto_deggcd1,WRONG_NO_2},
    {"rl_ex",                   TOO_FEW_2,      CC_rl_ex,      WRONG_NO_2},
    {"addcoeffs",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_addcoeffs},
    {"*invsq",                  CC_Hinvsq,      TOO_MANY_1,    WRONG_NO_1},
    {"qqe_length-graph-bterm",  TOO_FEW_2,      CC_qqe_lengthKgraphKbterm,WRONG_NO_2},
    {"tidysqrt",                CC_tidysqrt,    TOO_MANY_1,    WRONG_NO_1},
    {"look_for_rational",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_look_for_rational},
    {"subscriptedvarp2",        CC_subscriptedvarp2,TOO_MANY_1,WRONG_NO_1},
    {"dip-nc-ev-prod",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dipKncKevKprod},
    {"*kp2q",                   TOO_FEW_2,      CC_Hkp2q,      WRONG_NO_2},
    {"calc_world",              TOO_FEW_2,      CC_calc_world, WRONG_NO_2},
    {"liendimcom",              CC_liendimcom,  TOO_MANY_1,    WRONG_NO_1},
    {"st_extract_symcells1",    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_st_extract_symcells1},
    {"addinds",                 TOO_FEW_2,      CC_addinds,    WRONG_NO_2},
    {"ofsf_factsf",             CC_ofsf_factsf, TOO_MANY_1,    WRONG_NO_1},
    {"matrix_input_test",       CC_matrix_input_test,TOO_MANY_1,WRONG_NO_1},
    {"vevzero?1",               CC_vevzeroW1,   TOO_MANY_1,    WRONG_NO_1},
    {"remove_critical_pairs",   TOO_FEW_2,      CC_remove_critical_pairs,WRONG_NO_2},
    {NULL, (one_args *)"u56", (two_args *)"119727 5875061 2902816", 0}
};

// end of generated code
