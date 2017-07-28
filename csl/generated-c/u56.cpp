
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



// Code for mkexpvec

static LispObject CC_mkexpvec(LispObject env,
                         LispObject v_34303)
{
    env = qenv(env);
    LispObject v_34395, v_34396;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34303);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_34303;
// end of prologue
    goto v_34313;
v_34309:
    v_34396 = stack[-3];
    goto v_34310;
v_34311:
    v_34395 = qvalue(elt(env, 1)); // dipvars!*
    goto v_34312;
v_34313:
    goto v_34309;
v_34310:
    goto v_34311;
v_34312:
    v_34395 = Lmember(nil, v_34396, v_34395);
    if (v_34395 == nil) goto v_34307;
    else goto v_34308;
v_34307:
    goto v_34322;
v_34318:
    v_34396 = stack[-3];
    goto v_34319;
v_34320:
    v_34395 = elt(env, 2); // "dipoly variable"
    goto v_34321;
v_34322:
    goto v_34318;
v_34319:
    goto v_34320;
v_34321:
    {
        fn = elt(env, 3); // typerr
        return (*qfn2(fn))(fn, v_34396, v_34395);
    }
v_34308:
    v_34395 = qvalue(elt(env, 1)); // dipvars!*
    stack[-4] = v_34395;
    v_34395 = stack[-4];
    if (v_34395 == nil) goto v_34336;
    else goto v_34337;
v_34336:
    v_34395 = nil;
    goto v_34331;
v_34337:
    v_34395 = stack[-4];
    v_34395 = qcar(v_34395);
    goto v_34352;
v_34348:
    v_34396 = v_34395;
    goto v_34349;
v_34350:
    v_34395 = stack[-3];
    goto v_34351;
v_34352:
    goto v_34348;
v_34349:
    goto v_34350;
v_34351:
    if (v_34396 == v_34395) goto v_34346;
    else goto v_34347;
v_34346:
    v_34395 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34345;
v_34347:
    v_34395 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34345;
    v_34395 = nil;
v_34345:
    v_34395 = ncons(v_34395);
    env = stack[-5];
    stack[-1] = v_34395;
    stack[-2] = v_34395;
v_34332:
    v_34395 = stack[-4];
    v_34395 = qcdr(v_34395);
    stack[-4] = v_34395;
    v_34395 = stack[-4];
    if (v_34395 == nil) goto v_34363;
    else goto v_34364;
v_34363:
    v_34395 = stack[-2];
    goto v_34331;
v_34364:
    goto v_34372;
v_34368:
    stack[0] = stack[-1];
    goto v_34369;
v_34370:
    v_34395 = stack[-4];
    v_34395 = qcar(v_34395);
    goto v_34386;
v_34382:
    v_34396 = v_34395;
    goto v_34383;
v_34384:
    v_34395 = stack[-3];
    goto v_34385;
v_34386:
    goto v_34382;
v_34383:
    goto v_34384;
v_34385:
    if (v_34396 == v_34395) goto v_34380;
    else goto v_34381;
v_34380:
    v_34395 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34379;
v_34381:
    v_34395 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34379;
    v_34395 = nil;
v_34379:
    v_34395 = ncons(v_34395);
    env = stack[-5];
    goto v_34371;
v_34372:
    goto v_34368;
v_34369:
    goto v_34370;
v_34371:
    v_34395 = Lrplacd(nil, stack[0], v_34395);
    env = stack[-5];
    v_34395 = stack[-1];
    v_34395 = qcdr(v_34395);
    stack[-1] = v_34395;
    goto v_34332;
v_34331:
    goto v_34306;
    v_34395 = nil;
v_34306:
    return onevalue(v_34395);
}



// Code for monomispommaretdivisibleby

static LispObject CC_monomispommaretdivisibleby(LispObject env,
                         LispObject v_34303, LispObject v_34304)
{
    env = qenv(env);
    LispObject v_34414, v_34415, v_34416;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34304,v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34303,v_34304);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_34416 = v_34304;
    v_34414 = v_34303;
// end of prologue
    stack[0] = nil;
    goto v_34315;
v_34311:
    v_34415 = v_34414;
    goto v_34312;
v_34313:
    v_34414 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34314;
v_34315:
    goto v_34311;
v_34312:
    goto v_34313;
v_34314:
    v_34414 = *(LispObject *)((char *)v_34415 + (CELL-TAG_VECTOR) + (((intptr_t)v_34414-TAG_FIXNUM)/(16/CELL)));
    stack[-2] = v_34414;
    goto v_34323;
v_34319:
    v_34415 = v_34416;
    goto v_34320;
v_34321:
    v_34414 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34322;
v_34323:
    goto v_34319;
v_34320:
    goto v_34321;
v_34322:
    v_34414 = *(LispObject *)((char *)v_34415 + (CELL-TAG_VECTOR) + (((intptr_t)v_34414-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_34414;
v_34329:
    v_34414 = stack[-2];
    v_34414 = qcar(v_34414);
    if (v_34414 == nil) goto v_34332;
    goto v_34343;
v_34339:
    v_34414 = stack[-2];
    v_34415 = qcar(v_34414);
    goto v_34340;
v_34341:
    v_34414 = stack[-1];
    v_34414 = qcar(v_34414);
    goto v_34342;
v_34343:
    goto v_34339;
v_34340:
    goto v_34341;
v_34342:
    v_34414 = (LispObject)greaterp2(v_34415, v_34414);
    v_34414 = v_34414 ? lisp_true : nil;
    env = stack[-3];
    if (v_34414 == nil) goto v_34332;
    goto v_34333;
v_34332:
    goto v_34328;
v_34333:
    v_34414 = stack[-2];
    v_34414 = qcdr(v_34414);
    stack[-2] = v_34414;
    goto v_34329;
v_34328:
v_34354:
    v_34414 = stack[0];
    if (v_34414 == nil) goto v_34361;
    else goto v_34362;
v_34361:
    v_34414 = stack[-2];
    v_34414 = qcar(v_34414);
    if (v_34414 == nil) goto v_34366;
    else goto v_34367;
v_34366:
    v_34414 = nil;
    goto v_34365;
v_34367:
    v_34414 = stack[-1];
    v_34414 = qcar(v_34414);
    goto v_34365;
    v_34414 = nil;
v_34365:
    goto v_34360;
v_34362:
    v_34414 = nil;
    goto v_34360;
    v_34414 = nil;
v_34360:
    if (v_34414 == nil) goto v_34357;
    else goto v_34358;
v_34357:
    goto v_34353;
v_34358:
    goto v_34387;
v_34383:
    v_34414 = stack[-2];
    v_34415 = qcar(v_34414);
    goto v_34384;
v_34385:
    v_34414 = stack[-1];
    v_34414 = qcar(v_34414);
    goto v_34386;
v_34387:
    goto v_34383;
v_34384:
    goto v_34385;
v_34386:
    if (equal(v_34415, v_34414)) goto v_34382;
    v_34414 = lisp_true;
    stack[0] = v_34414;
    goto v_34380;
v_34382:
    v_34414 = stack[-2];
    v_34414 = qcdr(v_34414);
    stack[-2] = v_34414;
    v_34414 = stack[-1];
    v_34414 = qcdr(v_34414);
    stack[-1] = v_34414;
    goto v_34380;
v_34380:
    goto v_34354;
v_34353:
    v_34414 = stack[-2];
    v_34414 = qcar(v_34414);
    if (v_34414 == nil) goto v_34404;
    else goto v_34405;
v_34404:
    v_34414 = stack[-1];
    v_34414 = qcar(v_34414);
    v_34414 = (v_34414 == nil ? lisp_true : nil);
    goto v_34403;
v_34405:
    v_34414 = nil;
    goto v_34403;
    v_34414 = nil;
v_34403:
    return onevalue(v_34414);
}



// Code for preptaylor!*2

static LispObject CC_preptaylorH2(LispObject env,
                         LispObject v_34303, LispObject v_34304)
{
    env = qenv(env);
    LispObject v_34398, v_34399, v_34400;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34304,v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34303,v_34304);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_34304;
    stack[-1] = v_34303;
// end of prologue
    v_34398 = stack[-1];
    v_34398 = qcdr(v_34398);
    fn = elt(env, 3); // prepsq!*
    v_34398 = (*qfn1(fn))(fn, v_34398);
    env = stack[-3];
    goto v_34318;
v_34314:
    v_34400 = v_34398;
    goto v_34315;
v_34316:
    v_34399 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34317;
v_34318:
    goto v_34314;
v_34315:
    goto v_34316;
v_34317:
    if (v_34400 == v_34399) goto v_34312;
    else goto v_34313;
v_34312:
    v_34398 = nil;
    goto v_34311;
v_34313:
    goto v_34331;
v_34327:
    goto v_34345;
v_34341:
    v_34400 = v_34398;
    goto v_34342;
v_34343:
    v_34399 = elt(env, 1); // quotient
    goto v_34344;
v_34345:
    goto v_34341;
v_34342:
    goto v_34343;
v_34344:
    if (!consp(v_34400)) goto v_34339;
    v_34400 = qcar(v_34400);
    if (v_34400 == v_34399) goto v_34338;
    else goto v_34339;
v_34338:
    goto v_34353;
v_34349:
    v_34399 = v_34398;
    v_34399 = qcdr(v_34399);
    v_34400 = qcar(v_34399);
    goto v_34350;
v_34351:
    v_34399 = elt(env, 2); // minus
    goto v_34352;
v_34353:
    goto v_34349;
v_34350:
    goto v_34351;
v_34352:
    v_34399 = Leqcar(nil, v_34400, v_34399);
    env = stack[-3];
    goto v_34337;
v_34339:
    v_34399 = nil;
    goto v_34337;
    v_34399 = nil;
v_34337:
    if (v_34399 == nil) goto v_34335;
    goto v_34366;
v_34362:
    stack[-2] = elt(env, 2); // minus
    goto v_34363;
v_34364:
    goto v_34375;
v_34369:
    v_34400 = elt(env, 1); // quotient
    goto v_34370;
v_34371:
    v_34399 = v_34398;
    v_34399 = qcdr(v_34399);
    v_34399 = qcar(v_34399);
    v_34399 = qcdr(v_34399);
    v_34399 = qcar(v_34399);
    goto v_34372;
v_34373:
    v_34398 = qcdr(v_34398);
    v_34398 = qcdr(v_34398);
    v_34398 = qcar(v_34398);
    goto v_34374;
v_34375:
    goto v_34369;
v_34370:
    goto v_34371;
v_34372:
    goto v_34373;
v_34374:
    v_34398 = list3(v_34400, v_34399, v_34398);
    env = stack[-3];
    goto v_34365;
v_34366:
    goto v_34362;
v_34363:
    goto v_34364;
v_34365:
    v_34398 = list2(stack[-2], v_34398);
    env = stack[-3];
    stack[-2] = v_34398;
    goto v_34333;
v_34335:
    stack[-2] = v_34398;
    goto v_34333;
    stack[-2] = nil;
v_34333:
    goto v_34328;
v_34329:
    goto v_34394;
v_34390:
    v_34398 = stack[-1];
    v_34399 = qcar(v_34398);
    goto v_34391;
v_34392:
    v_34398 = stack[0];
    goto v_34393;
v_34394:
    goto v_34390;
v_34391:
    goto v_34392;
v_34393:
    fn = elt(env, 4); // preptaycoeff
    v_34398 = (*qfn2(fn))(fn, v_34399, v_34398);
    env = stack[-3];
    goto v_34330;
v_34331:
    goto v_34327;
v_34328:
    goto v_34329;
v_34330:
    v_34398 = cons(stack[-2], v_34398);
    env = stack[-3];
    fn = elt(env, 5); // retimes
    v_34398 = (*qfn1(fn))(fn, v_34398);
    return ncons(v_34398);
    v_34398 = nil;
v_34311:
    return onevalue(v_34398);
}



// Code for rl_reval

static LispObject CC_rl_reval(LispObject env,
                         LispObject v_34303, LispObject v_34304)
{
    env = qenv(env);
    LispObject v_34319, v_34320;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34304,v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34303,v_34304);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_34319 = v_34304;
    v_34320 = v_34303;
// end of prologue
    if (v_34319 == nil) goto v_34309;
    v_34319 = v_34320;
    fn = elt(env, 1); // rl_simp1
    v_34319 = (*qfn1(fn))(fn, v_34319);
    env = stack[0];
    {
        fn = elt(env, 2); // rl_prepfof
        return (*qfn1(fn))(fn, v_34319);
    }
v_34309:
    v_34319 = v_34320;
    fn = elt(env, 1); // rl_simp1
    v_34319 = (*qfn1(fn))(fn, v_34319);
    env = stack[0];
    {
        fn = elt(env, 3); // rl_mk!*fof
        return (*qfn1(fn))(fn, v_34319);
    }
    v_34319 = nil;
    return onevalue(v_34319);
}



// Code for mri_irsplit

static LispObject CC_mri_irsplit(LispObject env,
                         LispObject v_34303)
{
    env = qenv(env);
    LispObject v_34384, v_34385, v_34386;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34303);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_34386 = v_34303;
// end of prologue
    goto v_34317;
v_34313:
    v_34385 = v_34386;
    goto v_34314;
v_34315:
    v_34384 = elt(env, 1); // floor
    goto v_34316;
v_34317:
    goto v_34313;
v_34314:
    goto v_34315;
v_34316:
    if (!consp(v_34385)) goto v_34310;
    v_34385 = qcar(v_34385);
    if (v_34385 == v_34384) goto v_34311;
v_34310:
    goto v_34327;
v_34323:
    goto v_34333;
v_34329:
    v_34385 = v_34386;
    goto v_34330;
v_34331:
    v_34384 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34332;
v_34333:
    goto v_34329;
v_34330:
    goto v_34331;
v_34332:
    fn = elt(env, 2); // to
    v_34385 = (*qfn2(fn))(fn, v_34385, v_34384);
    env = stack[-2];
    goto v_34324;
v_34325:
    v_34384 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34326;
v_34327:
    goto v_34323;
v_34324:
    goto v_34325;
v_34326:
    v_34384 = cons(v_34385, v_34384);
    env = stack[-2];
    v_34384 = ncons(v_34384);
    return ncons(v_34384);
v_34311:
    v_34384 = v_34386;
    v_34384 = qcdr(v_34384);
    v_34384 = qcar(v_34384);
    fn = elt(env, 3); // simp
    v_34384 = (*qfn1(fn))(fn, v_34384);
    env = stack[-2];
    v_34384 = qcar(v_34384);
    fn = elt(env, 4); // mri_simplfloor
    v_34384 = (*qfn1(fn))(fn, v_34384);
    env = stack[-2];
    fn = elt(env, 5); // mri_irsplit1
    v_34384 = (*qfn1(fn))(fn, v_34384);
    env = stack[-2];
    v_34385 = v_34384;
    goto v_34349;
v_34345:
    v_34384 = v_34385;
    stack[-1] = qcar(v_34384);
    goto v_34346;
v_34347:
    v_34384 = v_34385;
    v_34384 = qcdr(v_34384);
    if (v_34384 == nil) goto v_34355;
    goto v_34364;
v_34360:
    goto v_34370;
v_34366:
    goto v_34377;
v_34373:
    stack[0] = elt(env, 1); // floor
    goto v_34374;
v_34375:
    v_34384 = v_34385;
    v_34384 = qcdr(v_34384);
    fn = elt(env, 6); // prepf
    v_34384 = (*qfn1(fn))(fn, v_34384);
    env = stack[-2];
    goto v_34376;
v_34377:
    goto v_34373;
v_34374:
    goto v_34375;
v_34376:
    v_34384 = list2(stack[0], v_34384);
    env = stack[-2];
    fn = elt(env, 7); // !*a2k
    v_34385 = (*qfn1(fn))(fn, v_34384);
    env = stack[-2];
    goto v_34367;
v_34368:
    v_34384 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34369;
v_34370:
    goto v_34366;
v_34367:
    goto v_34368;
v_34369:
    fn = elt(env, 2); // to
    v_34385 = (*qfn2(fn))(fn, v_34385, v_34384);
    env = stack[-2];
    goto v_34361;
v_34362:
    v_34384 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34363;
v_34364:
    goto v_34360;
v_34361:
    goto v_34362;
v_34363:
    v_34384 = cons(v_34385, v_34384);
    env = stack[-2];
    v_34384 = ncons(v_34384);
    goto v_34353;
v_34355:
    v_34384 = nil;
v_34353:
    goto v_34348;
v_34349:
    goto v_34345;
v_34346:
    goto v_34347;
v_34348:
    {
        LispObject v_34389 = stack[-1];
        return cons(v_34389, v_34384);
    }
    return onevalue(v_34384);
}



// Code for expttermp1

static LispObject CC_expttermp1(LispObject env,
                         LispObject v_34303, LispObject v_34304)
{
    env = qenv(env);
    LispObject v_34372, v_34373, v_34374, v_34375;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_34373 = v_34304;
    v_34374 = v_34303;
// end of prologue
v_34302:
    v_34372 = v_34373;
    if (v_34372 == nil) goto v_34308;
    else goto v_34309;
v_34308:
    v_34372 = nil;
    goto v_34307;
v_34309:
    goto v_34322;
v_34318:
    v_34375 = v_34374;
    goto v_34319;
v_34320:
    v_34372 = v_34373;
    v_34372 = qcar(v_34372);
    goto v_34321;
v_34322:
    goto v_34318;
v_34319:
    goto v_34320;
v_34321:
    if (equal(v_34375, v_34372)) goto v_34316;
    else goto v_34317;
v_34316:
    v_34372 = lisp_true;
    goto v_34315;
v_34317:
    goto v_34342;
v_34338:
    v_34372 = v_34373;
    v_34375 = qcar(v_34372);
    goto v_34339;
v_34340:
    v_34372 = elt(env, 1); // expt
    goto v_34341;
v_34342:
    goto v_34338;
v_34339:
    goto v_34340;
v_34341:
    if (!consp(v_34375)) goto v_34336;
    v_34375 = qcar(v_34375);
    if (v_34375 == v_34372) goto v_34335;
    else goto v_34336;
v_34335:
    goto v_34350;
v_34346:
    v_34375 = v_34374;
    goto v_34347;
v_34348:
    v_34372 = v_34373;
    v_34372 = qcar(v_34372);
    v_34372 = qcdr(v_34372);
    v_34372 = qcar(v_34372);
    goto v_34349;
v_34350:
    goto v_34346;
v_34347:
    goto v_34348;
v_34349:
    v_34372 = (equal(v_34375, v_34372) ? lisp_true : nil);
    goto v_34334;
v_34336:
    v_34372 = nil;
    goto v_34334;
    v_34372 = nil;
v_34334:
    if (v_34372 == nil) goto v_34332;
    v_34372 = lisp_true;
    goto v_34330;
v_34332:
    goto v_34368;
v_34364:
    goto v_34365;
v_34366:
    v_34372 = v_34373;
    v_34372 = qcdr(v_34372);
    goto v_34367;
v_34368:
    goto v_34364;
v_34365:
    goto v_34366;
v_34367:
    v_34373 = v_34372;
    goto v_34302;
    v_34372 = nil;
v_34330:
    goto v_34315;
    v_34372 = nil;
v_34315:
    goto v_34307;
    v_34372 = nil;
v_34307:
    return onevalue(v_34372);
}



// Code for xreduce1

static LispObject CC_xreduce1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_34341, v_34342, v_34343;
    LispObject fn;
    LispObject v_34305, v_34304, v_34303;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xreduce1");
    va_start(aa, nargs);
    v_34303 = va_arg(aa, LispObject);
    v_34304 = va_arg(aa, LispObject);
    v_34305 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_34305,v_34304,v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_34303,v_34304,v_34305);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_34305;
    stack[-1] = v_34304;
    stack[-2] = v_34303;
// end of prologue
    stack[-3] = nil;
v_34310:
    goto v_34322;
v_34316:
    v_34343 = stack[-2];
    goto v_34317;
v_34318:
    v_34342 = stack[-1];
    goto v_34319;
v_34320:
    v_34341 = stack[0];
    goto v_34321;
v_34322:
    goto v_34316;
v_34317:
    goto v_34318;
v_34319:
    goto v_34320;
v_34321:
    fn = elt(env, 1); // weak_xreduce1
    v_34341 = (*qfnn(fn))(fn, 3, v_34343, v_34342, v_34341);
    env = stack[-4];
    stack[-2] = v_34341;
    if (v_34341 == nil) goto v_34314;
    goto v_34331;
v_34327:
    v_34341 = stack[-2];
    v_34342 = qcar(v_34341);
    goto v_34328;
v_34329:
    v_34341 = stack[-3];
    goto v_34330;
v_34331:
    goto v_34327;
v_34328:
    goto v_34329;
v_34330:
    v_34341 = cons(v_34342, v_34341);
    env = stack[-4];
    stack[-3] = v_34341;
    v_34341 = stack[-2];
    v_34341 = qcdr(v_34341);
    stack[-2] = v_34341;
    goto v_34310;
v_34314:
    v_34341 = stack[-3];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_34341);
    }
    v_34341 = nil;
    return onevalue(v_34341);
}



// Code for quotient!:

static LispObject CC_quotientT(LispObject env,
                         LispObject v_34303, LispObject v_34304)
{
    env = qenv(env);
    LispObject v_34451, v_34452;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34304,v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34303,v_34304);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_34304;
    stack[-2] = v_34303;
// end of prologue
v_34302:
    goto v_34320;
v_34316:
    v_34451 = stack[-2];
    v_34451 = qcdr(v_34451);
    v_34452 = qcdr(v_34451);
    stack[-1] = v_34452;
    goto v_34317;
v_34318:
    v_34451 = stack[-3];
    v_34451 = qcdr(v_34451);
    v_34451 = qcdr(v_34451);
    stack[0] = v_34451;
    goto v_34319;
v_34320:
    goto v_34316;
v_34317:
    goto v_34318;
v_34319:
    if (equal(v_34452, v_34451)) goto v_34314;
    else goto v_34315;
v_34314:
    goto v_34334;
v_34328:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_34329;
v_34330:
    goto v_34341;
v_34337:
    v_34451 = stack[-2];
    v_34451 = qcdr(v_34451);
    v_34452 = qcar(v_34451);
    goto v_34338;
v_34339:
    v_34451 = stack[-3];
    v_34451 = qcdr(v_34451);
    v_34451 = qcar(v_34451);
    goto v_34340;
v_34341:
    goto v_34337;
v_34338:
    goto v_34339;
v_34340:
    v_34452 = quot2(v_34452, v_34451);
    goto v_34331;
v_34332:
    v_34451 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34333;
v_34334:
    goto v_34328;
v_34329:
    goto v_34330;
v_34331:
    goto v_34332;
v_34333:
    {
        LispObject v_34458 = stack[0];
        return list2star(v_34458, v_34452, v_34451);
    }
v_34315:
    goto v_34356;
v_34352:
    v_34452 = stack[-1];
    goto v_34353;
v_34354:
    v_34451 = stack[0];
    goto v_34355;
v_34356:
    goto v_34352;
v_34353:
    goto v_34354;
v_34355:
    v_34451 = (LispObject)greaterp2(v_34452, v_34451);
    v_34451 = v_34451 ? lisp_true : nil;
    env = stack[-5];
    if (v_34451 == nil) goto v_34350;
    goto v_34364;
v_34360:
    goto v_34370;
v_34366:
    v_34452 = stack[-1];
    goto v_34367;
v_34368:
    v_34451 = stack[0];
    goto v_34369;
v_34370:
    goto v_34366;
v_34367:
    goto v_34368;
v_34369:
    v_34451 = difference2(v_34452, v_34451);
    env = stack[-5];
    stack[-4] = v_34451;
    goto v_34381;
v_34375:
    stack[-1] = elt(env, 1); // !:rd!:
    goto v_34376;
v_34377:
    goto v_34388;
v_34384:
    v_34451 = stack[-2];
    v_34451 = qcdr(v_34451);
    v_34452 = qcar(v_34451);
    goto v_34385;
v_34386:
    v_34451 = stack[-4];
    goto v_34387;
v_34388:
    goto v_34384;
v_34385:
    goto v_34386;
v_34387:
    fn = elt(env, 2); // ashift
    stack[0] = (*qfn2(fn))(fn, v_34452, v_34451);
    env = stack[-5];
    goto v_34378;
v_34379:
    goto v_34398;
v_34394:
    v_34451 = stack[-2];
    v_34451 = qcdr(v_34451);
    v_34452 = qcdr(v_34451);
    goto v_34395;
v_34396:
    v_34451 = stack[-4];
    goto v_34397;
v_34398:
    goto v_34394;
v_34395:
    goto v_34396;
v_34397:
    v_34451 = difference2(v_34452, v_34451);
    env = stack[-5];
    goto v_34380;
v_34381:
    goto v_34375;
v_34376:
    goto v_34377;
v_34378:
    goto v_34379;
v_34380:
    v_34452 = list2star(stack[-1], stack[0], v_34451);
    env = stack[-5];
    goto v_34361;
v_34362:
    v_34451 = stack[-3];
    goto v_34363;
v_34364:
    goto v_34360;
v_34361:
    goto v_34362;
v_34363:
    stack[-2] = v_34452;
    stack[-3] = v_34451;
    goto v_34302;
v_34350:
    goto v_34411;
v_34407:
    stack[-4] = stack[-2];
    goto v_34408;
v_34409:
    goto v_34418;
v_34414:
    v_34452 = stack[0];
    goto v_34415;
v_34416:
    v_34451 = stack[-1];
    goto v_34417;
v_34418:
    goto v_34414;
v_34415:
    goto v_34416;
v_34417:
    v_34451 = difference2(v_34452, v_34451);
    env = stack[-5];
    stack[-2] = v_34451;
    goto v_34429;
v_34423:
    stack[-1] = elt(env, 1); // !:rd!:
    goto v_34424;
v_34425:
    goto v_34436;
v_34432:
    v_34451 = stack[-3];
    v_34451 = qcdr(v_34451);
    v_34452 = qcar(v_34451);
    goto v_34433;
v_34434:
    v_34451 = stack[-2];
    goto v_34435;
v_34436:
    goto v_34432;
v_34433:
    goto v_34434;
v_34435:
    fn = elt(env, 2); // ashift
    stack[0] = (*qfn2(fn))(fn, v_34452, v_34451);
    env = stack[-5];
    goto v_34426;
v_34427:
    goto v_34446;
v_34442:
    v_34451 = stack[-3];
    v_34451 = qcdr(v_34451);
    v_34452 = qcdr(v_34451);
    goto v_34443;
v_34444:
    v_34451 = stack[-2];
    goto v_34445;
v_34446:
    goto v_34442;
v_34443:
    goto v_34444;
v_34445:
    v_34451 = difference2(v_34452, v_34451);
    env = stack[-5];
    goto v_34428;
v_34429:
    goto v_34423;
v_34424:
    goto v_34425;
v_34426:
    goto v_34427;
v_34428:
    v_34451 = list2star(stack[-1], stack[0], v_34451);
    env = stack[-5];
    goto v_34410;
v_34411:
    goto v_34407;
v_34408:
    goto v_34409;
v_34410:
    stack[-2] = stack[-4];
    stack[-3] = v_34451;
    goto v_34302;
    v_34451 = nil;
    return onevalue(v_34451);
}



// Code for mk!-coeff1

static LispObject CC_mkKcoeff1(LispObject env,
                         LispObject v_34303, LispObject v_34304)
{
    env = qenv(env);
    LispObject v_34380, v_34381;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34304,v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34303,v_34304);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_34304;
    v_34381 = v_34303;
// end of prologue
    v_34380 = v_34381;
    if (v_34380 == nil) goto v_34308;
    else goto v_34309;
v_34308:
    v_34380 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34307;
v_34309:
    goto v_34320;
v_34316:
    stack[-5] = elt(env, 1); // times
    goto v_34317;
v_34318:
    v_34380 = v_34381;
    stack[-3] = v_34380;
    v_34380 = stack[-3];
    if (v_34380 == nil) goto v_34331;
    else goto v_34332;
v_34331:
    v_34380 = nil;
    goto v_34326;
v_34332:
    v_34380 = stack[-3];
    v_34380 = qcar(v_34380);
    goto v_34345;
v_34341:
    v_34381 = qcar(v_34380);
    goto v_34342;
v_34343:
    v_34380 = stack[-4];
    goto v_34344;
v_34345:
    goto v_34341;
v_34342:
    goto v_34343;
v_34344:
    fn = elt(env, 2); // getroad
    v_34380 = (*qfn2(fn))(fn, v_34381, v_34380);
    env = stack[-6];
    fn = elt(env, 3); // factorial
    v_34380 = (*qfn1(fn))(fn, v_34380);
    env = stack[-6];
    v_34380 = ncons(v_34380);
    env = stack[-6];
    stack[-1] = v_34380;
    stack[-2] = v_34380;
v_34327:
    v_34380 = stack[-3];
    v_34380 = qcdr(v_34380);
    stack[-3] = v_34380;
    v_34380 = stack[-3];
    if (v_34380 == nil) goto v_34353;
    else goto v_34354;
v_34353:
    v_34380 = stack[-2];
    goto v_34326;
v_34354:
    goto v_34362;
v_34358:
    stack[0] = stack[-1];
    goto v_34359;
v_34360:
    v_34380 = stack[-3];
    v_34380 = qcar(v_34380);
    goto v_34374;
v_34370:
    v_34381 = qcar(v_34380);
    goto v_34371;
v_34372:
    v_34380 = stack[-4];
    goto v_34373;
v_34374:
    goto v_34370;
v_34371:
    goto v_34372;
v_34373:
    fn = elt(env, 2); // getroad
    v_34380 = (*qfn2(fn))(fn, v_34381, v_34380);
    env = stack[-6];
    fn = elt(env, 3); // factorial
    v_34380 = (*qfn1(fn))(fn, v_34380);
    env = stack[-6];
    v_34380 = ncons(v_34380);
    env = stack[-6];
    goto v_34361;
v_34362:
    goto v_34358;
v_34359:
    goto v_34360;
v_34361:
    v_34380 = Lrplacd(nil, stack[0], v_34380);
    env = stack[-6];
    v_34380 = stack[-1];
    v_34380 = qcdr(v_34380);
    stack[-1] = v_34380;
    goto v_34327;
v_34326:
    goto v_34319;
v_34320:
    goto v_34316;
v_34317:
    goto v_34318;
v_34319:
    v_34380 = cons(stack[-5], v_34380);
    env = stack[-6];
    {
        fn = elt(env, 4); // eval
        return (*qfn1(fn))(fn, v_34380);
    }
    v_34380 = nil;
v_34307:
    return onevalue(v_34380);
}



// Code for depend1

static LispObject CC_depend1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_34431, v_34432, v_34433;
    LispObject fn;
    LispObject v_34305, v_34304, v_34303;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "depend1");
    va_start(aa, nargs);
    v_34303 = va_arg(aa, LispObject);
    v_34304 = va_arg(aa, LispObject);
    v_34305 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_34305,v_34304,v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_34303,v_34304,v_34305);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_34305;
    stack[-1] = v_34304;
    stack[-2] = v_34303;
// end of prologue
    v_34431 = stack[-2];
    fn = elt(env, 3); // !*a2k
    v_34431 = (*qfn1(fn))(fn, v_34431);
    env = stack[-4];
    stack[-2] = v_34431;
    v_34431 = stack[-1];
    fn = elt(env, 3); // !*a2k
    v_34431 = (*qfn1(fn))(fn, v_34431);
    env = stack[-4];
    stack[-1] = v_34431;
    goto v_34323;
v_34319:
    v_34432 = stack[-2];
    goto v_34320;
v_34321:
    v_34431 = stack[-1];
    goto v_34322;
v_34323:
    goto v_34319;
v_34320:
    goto v_34321;
v_34322:
    if (v_34432 == v_34431) goto v_34317;
    else goto v_34318;
v_34317:
    v_34431 = nil;
    goto v_34310;
v_34318:
    goto v_34331;
v_34327:
    v_34432 = stack[-2];
    goto v_34328;
v_34329:
    v_34431 = qvalue(elt(env, 1)); // depl!*
    goto v_34330;
v_34331:
    goto v_34327;
v_34328:
    goto v_34329;
v_34330:
    v_34431 = Lassoc(nil, v_34432, v_34431);
    stack[-3] = v_34431;
    v_34431 = stack[-3];
    if (v_34431 == nil) goto v_34338;
    v_34431 = stack[0];
    if (v_34431 == nil) goto v_34343;
    goto v_34352;
v_34346:
    v_34431 = stack[-3];
    stack[0] = qcar(v_34431);
    goto v_34347;
v_34348:
    goto v_34360;
v_34356:
    v_34431 = stack[-1];
    v_34432 = ncons(v_34431);
    env = stack[-4];
    goto v_34357;
v_34358:
    v_34431 = stack[-3];
    v_34431 = qcdr(v_34431);
    goto v_34359;
v_34360:
    goto v_34356;
v_34357:
    goto v_34358;
v_34359:
    fn = elt(env, 4); // union
    v_34432 = (*qfn2(fn))(fn, v_34432, v_34431);
    env = stack[-4];
    goto v_34349;
v_34350:
    v_34431 = qvalue(elt(env, 1)); // depl!*
    goto v_34351;
v_34352:
    goto v_34346;
v_34347:
    goto v_34348;
v_34349:
    goto v_34350;
v_34351:
    fn = elt(env, 5); // repasc
    v_34431 = (*qfnn(fn))(fn, 3, stack[0], v_34432, v_34431);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_34431; // depl!*
    goto v_34341;
v_34343:
    goto v_34373;
v_34369:
    v_34432 = stack[-1];
    goto v_34370;
v_34371:
    v_34431 = stack[-3];
    v_34431 = qcdr(v_34431);
    goto v_34372;
v_34373:
    goto v_34369;
v_34370:
    goto v_34371;
v_34372:
    v_34432 = Ldelete(nil, v_34432, v_34431);
    env = stack[-4];
    v_34431 = v_34432;
    if (v_34432 == nil) goto v_34367;
    goto v_34384;
v_34378:
    v_34432 = stack[-3];
    v_34433 = qcar(v_34432);
    goto v_34379;
v_34380:
    v_34432 = v_34431;
    goto v_34381;
v_34382:
    v_34431 = qvalue(elt(env, 1)); // depl!*
    goto v_34383;
v_34384:
    goto v_34378;
v_34379:
    goto v_34380;
v_34381:
    goto v_34382;
v_34383:
    fn = elt(env, 5); // repasc
    v_34431 = (*qfnn(fn))(fn, 3, v_34433, v_34432, v_34431);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_34431; // depl!*
    goto v_34341;
v_34367:
    goto v_34396;
v_34392:
    v_34432 = stack[-3];
    goto v_34393;
v_34394:
    v_34431 = qvalue(elt(env, 1)); // depl!*
    goto v_34395;
v_34396:
    goto v_34392;
v_34393:
    goto v_34394;
v_34395:
    v_34431 = Ldelete(nil, v_34432, v_34431);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_34431; // depl!*
    goto v_34341;
v_34341:
    goto v_34336;
v_34338:
    v_34431 = stack[0];
    if (v_34431 == nil) goto v_34399;
    else goto v_34400;
v_34399:
    goto v_34410;
v_34404:
    v_34433 = stack[-2];
    goto v_34405;
v_34406:
    v_34432 = elt(env, 2); // "has no prior dependence on"
    goto v_34407;
v_34408:
    v_34431 = stack[-1];
    goto v_34409;
v_34410:
    goto v_34404;
v_34405:
    goto v_34406;
v_34407:
    goto v_34408;
v_34409:
    v_34431 = list3(v_34433, v_34432, v_34431);
    env = stack[-4];
    fn = elt(env, 6); // lprim
    v_34431 = (*qfn1(fn))(fn, v_34431);
    goto v_34336;
v_34400:
    goto v_34421;
v_34417:
    goto v_34427;
v_34423:
    v_34432 = stack[-2];
    goto v_34424;
v_34425:
    v_34431 = stack[-1];
    goto v_34426;
v_34427:
    goto v_34423;
v_34424:
    goto v_34425;
v_34426:
    v_34432 = list2(v_34432, v_34431);
    env = stack[-4];
    goto v_34418;
v_34419:
    v_34431 = qvalue(elt(env, 1)); // depl!*
    goto v_34420;
v_34421:
    goto v_34417;
v_34418:
    goto v_34419;
v_34420:
    v_34431 = cons(v_34432, v_34431);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_34431; // depl!*
    goto v_34336;
v_34336:
    v_34431 = nil;
v_34310:
    return onevalue(v_34431);
}



// Code for lf!=less

static LispObject CC_lfMless(LispObject env,
                         LispObject v_34303, LispObject v_34304)
{
    env = qenv(env);
    LispObject v_34326, v_34327, v_34328;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34304,v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34303,v_34304);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_34304;
    v_34327 = v_34303;
// end of prologue
    goto v_34313;
v_34307:
    goto v_34319;
v_34315:
    v_34328 = elt(env, 1); // cali
    goto v_34316;
v_34317:
    v_34326 = elt(env, 2); // varlessp
    goto v_34318;
v_34319:
    goto v_34315;
v_34316:
    goto v_34317;
v_34318:
    stack[-2] = get(v_34328, v_34326);
    env = stack[-3];
    goto v_34308;
v_34309:
    v_34326 = v_34327;
    fn = elt(env, 3); // lf!=lvar
    stack[0] = (*qfn1(fn))(fn, v_34326);
    env = stack[-3];
    goto v_34310;
v_34311:
    v_34326 = stack[-1];
    fn = elt(env, 3); // lf!=lvar
    v_34326 = (*qfn1(fn))(fn, v_34326);
    goto v_34312;
v_34313:
    goto v_34307;
v_34308:
    goto v_34309;
v_34310:
    goto v_34311;
v_34312:
    {
        LispObject v_34332 = stack[-2];
        LispObject v_34333 = stack[0];
        return Lapply2(nil, 3, v_34332, v_34333, v_34326);
    }
}



// Code for sep_tens_from_other

static LispObject CC_sep_tens_from_other(LispObject env,
                         LispObject v_34303)
{
    env = qenv(env);
    LispObject v_34479, v_34480;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34303);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_34303;
// end of prologue
    stack[-4] = nil;
    v_34479 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 2); // !*n2f
    v_34479 = (*qfn1(fn))(fn, v_34479);
    env = stack[-5];
    stack[-2] = v_34479;
v_34311:
    v_34479 = stack[-3];
    if (is_number(v_34479)) goto v_34316;
    else goto v_34317;
v_34316:
    goto v_34324;
v_34320:
    v_34479 = stack[-4];
    stack[0] = Lnreverse(nil, v_34479);
    env = stack[-5];
    goto v_34321;
v_34322:
    goto v_34332;
v_34328:
    stack[-1] = stack[-2];
    goto v_34329;
v_34330:
    v_34479 = stack[-3];
    fn = elt(env, 2); // !*n2f
    v_34479 = (*qfn1(fn))(fn, v_34479);
    env = stack[-5];
    goto v_34331;
v_34332:
    goto v_34328;
v_34329:
    goto v_34330;
v_34331:
    fn = elt(env, 3); // multf
    v_34479 = (*qfn2(fn))(fn, stack[-1], v_34479);
    goto v_34323;
v_34324:
    goto v_34320;
v_34321:
    goto v_34322;
v_34323:
    {
        LispObject v_34486 = stack[0];
        return list2(v_34486, v_34479);
    }
v_34317:
    v_34479 = stack[-3];
    v_34479 = qcar(v_34479);
    v_34479 = qcar(v_34479);
    v_34479 = qcar(v_34479);
    if (!consp(v_34479)) goto v_34336;
    else goto v_34337;
v_34336:
    goto v_34347;
v_34343:
    stack[0] = stack[-2];
    goto v_34344;
v_34345:
    goto v_34355;
v_34351:
    v_34479 = stack[-3];
    v_34479 = qcar(v_34479);
    v_34480 = qcar(v_34479);
    goto v_34352;
v_34353:
    v_34479 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34354;
v_34355:
    goto v_34351;
v_34352:
    goto v_34353;
v_34354:
    v_34479 = cons(v_34480, v_34479);
    env = stack[-5];
    v_34479 = ncons(v_34479);
    env = stack[-5];
    goto v_34346;
v_34347:
    goto v_34343;
v_34344:
    goto v_34345;
v_34346:
    fn = elt(env, 3); // multf
    v_34479 = (*qfn2(fn))(fn, stack[0], v_34479);
    env = stack[-5];
    stack[-2] = v_34479;
    goto v_34315;
v_34337:
    goto v_34371;
v_34367:
    v_34479 = stack[-3];
    v_34479 = qcar(v_34479);
    v_34479 = qcar(v_34479);
    v_34479 = qcar(v_34479);
    v_34480 = qcar(v_34479);
    goto v_34368;
v_34369:
    v_34479 = elt(env, 1); // translate1
    goto v_34370;
v_34371:
    goto v_34367;
v_34368:
    goto v_34369;
v_34370:
    v_34479 = get(v_34480, v_34479);
    env = stack[-5];
    stack[-1] = v_34479;
    if (v_34479 == nil) goto v_34365;
    v_34479 = stack[-3];
    fn = elt(env, 4); // fullcopy
    v_34479 = (*qfn1(fn))(fn, v_34479);
    env = stack[-5];
    stack[-3] = v_34479;
    goto v_34385;
v_34381:
    v_34479 = stack[-3];
    v_34479 = qcar(v_34479);
    stack[0] = qcar(v_34479);
    goto v_34382;
v_34383:
    goto v_34394;
v_34390:
    v_34480 = stack[-1];
    goto v_34391;
v_34392:
    v_34479 = stack[-3];
    v_34479 = qcar(v_34479);
    v_34479 = qcar(v_34479);
    v_34479 = qcar(v_34479);
    goto v_34393;
v_34394:
    goto v_34390;
v_34391:
    goto v_34392;
v_34393:
    v_34479 = Lapply1(nil, v_34480, v_34479);
    env = stack[-5];
    goto v_34384;
v_34385:
    goto v_34381;
v_34382:
    goto v_34383;
v_34384:
    fn = elt(env, 5); // setcar
    v_34479 = (*qfn2(fn))(fn, stack[0], v_34479);
    env = stack[-5];
    goto v_34363;
v_34365:
v_34363:
    v_34479 = stack[-3];
    v_34479 = qcar(v_34479);
    v_34479 = qcar(v_34479);
    v_34479 = qcar(v_34479);
    stack[0] = v_34479;
    fn = elt(env, 6); // tensorp
    v_34479 = (*qfn1(fn))(fn, v_34479);
    env = stack[-5];
    if (v_34479 == nil) goto v_34403;
    v_34479 = stack[0];
    fn = elt(env, 7); // no_dum_varp
    v_34479 = (*qfn1(fn))(fn, v_34479);
    env = stack[-5];
    if (v_34479 == nil) goto v_34415;
    else goto v_34416;
v_34415:
    v_34479 = lisp_true;
    goto v_34414;
v_34416:
    v_34479 = stack[0];
    v_34479 = qcar(v_34479);
    if (!symbolp(v_34479)) v_34479 = nil;
    else { v_34479 = qfastgets(v_34479);
           if (v_34479 != nil) { v_34479 = elt(v_34479, 0); // noncom
#ifdef RECORD_GET
             if (v_34479 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_34479 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_34479 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_34479 == SPID_NOPROP) v_34479 = nil; else v_34479 = lisp_true; }}
#endif
    goto v_34414;
    v_34479 = nil;
v_34414:
    if (v_34479 == nil) goto v_34412;
    goto v_34430;
v_34426:
    v_34479 = stack[-3];
    v_34479 = qcar(v_34479);
    v_34479 = qcar(v_34479);
    v_34480 = qcar(v_34479);
    goto v_34427;
v_34428:
    v_34479 = stack[-4];
    goto v_34429;
v_34430:
    goto v_34426;
v_34427:
    goto v_34428;
v_34429:
    v_34479 = cons(v_34480, v_34479);
    env = stack[-5];
    stack[-4] = v_34479;
    goto v_34410;
v_34412:
    goto v_34443;
v_34439:
    stack[0] = stack[-2];
    goto v_34440;
v_34441:
    goto v_34451;
v_34447:
    v_34479 = stack[-3];
    v_34479 = qcar(v_34479);
    v_34480 = qcar(v_34479);
    goto v_34448;
v_34449:
    v_34479 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34450;
v_34451:
    goto v_34447;
v_34448:
    goto v_34449;
v_34450:
    v_34479 = cons(v_34480, v_34479);
    env = stack[-5];
    v_34479 = ncons(v_34479);
    env = stack[-5];
    goto v_34442;
v_34443:
    goto v_34439;
v_34440:
    goto v_34441;
v_34442:
    fn = elt(env, 3); // multf
    v_34479 = (*qfn2(fn))(fn, stack[0], v_34479);
    env = stack[-5];
    stack[-2] = v_34479;
    goto v_34410;
v_34410:
    goto v_34401;
v_34403:
    goto v_34463;
v_34459:
    stack[0] = stack[-2];
    goto v_34460;
v_34461:
    goto v_34471;
v_34467:
    v_34479 = stack[-3];
    v_34479 = qcar(v_34479);
    v_34480 = qcar(v_34479);
    goto v_34468;
v_34469:
    v_34479 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34470;
v_34471:
    goto v_34467;
v_34468:
    goto v_34469;
v_34470:
    v_34479 = cons(v_34480, v_34479);
    env = stack[-5];
    v_34479 = ncons(v_34479);
    env = stack[-5];
    goto v_34462;
v_34463:
    goto v_34459;
v_34460:
    goto v_34461;
v_34462:
    fn = elt(env, 3); // multf
    v_34479 = (*qfn2(fn))(fn, stack[0], v_34479);
    env = stack[-5];
    stack[-2] = v_34479;
    goto v_34401;
v_34401:
    goto v_34315;
v_34315:
    v_34479 = stack[-3];
    v_34479 = qcar(v_34479);
    v_34479 = qcdr(v_34479);
    stack[-3] = v_34479;
    goto v_34311;
    return onevalue(v_34479);
}



// Code for absodeg

static LispObject CC_absodeg(LispObject env,
                         LispObject v_34303)
{
    env = qenv(env);
    LispObject v_34382, v_34383;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34303);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_34382 = v_34303;
// end of prologue
    v_34383 = v_34382;
    v_34383 = Lconsp(nil, v_34383);
    env = stack[-5];
    if (v_34383 == nil) goto v_34307;
    else goto v_34308;
v_34307:
    v_34382 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34306;
v_34308:
    goto v_34320;
v_34316:
    stack[-4] = elt(env, 1); // plus
    goto v_34317;
v_34318:
    stack[-3] = v_34382;
    v_34382 = stack[-3];
    if (v_34382 == nil) goto v_34331;
    else goto v_34332;
v_34331:
    v_34382 = nil;
    goto v_34326;
v_34332:
    v_34382 = stack[-3];
    v_34382 = qcar(v_34382);
    v_34383 = v_34382;
    v_34382 = v_34383;
    v_34382 = integerp(v_34382);
    if (v_34382 == nil) goto v_34342;
    v_34382 = v_34383;
    v_34382 = sub1(v_34382);
    env = stack[-5];
    goto v_34340;
v_34342:
    v_34382 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34340;
    v_34382 = nil;
v_34340:
    v_34382 = ncons(v_34382);
    env = stack[-5];
    stack[-1] = v_34382;
    stack[-2] = v_34382;
v_34327:
    v_34382 = stack[-3];
    v_34382 = qcdr(v_34382);
    stack[-3] = v_34382;
    v_34382 = stack[-3];
    if (v_34382 == nil) goto v_34354;
    else goto v_34355;
v_34354:
    v_34382 = stack[-2];
    goto v_34326;
v_34355:
    goto v_34363;
v_34359:
    stack[0] = stack[-1];
    goto v_34360;
v_34361:
    v_34382 = stack[-3];
    v_34382 = qcar(v_34382);
    v_34383 = v_34382;
    v_34382 = v_34383;
    v_34382 = integerp(v_34382);
    if (v_34382 == nil) goto v_34372;
    v_34382 = v_34383;
    v_34382 = sub1(v_34382);
    env = stack[-5];
    goto v_34370;
v_34372:
    v_34382 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34370;
    v_34382 = nil;
v_34370:
    v_34382 = ncons(v_34382);
    env = stack[-5];
    goto v_34362;
v_34363:
    goto v_34359;
v_34360:
    goto v_34361;
v_34362:
    v_34382 = Lrplacd(nil, stack[0], v_34382);
    env = stack[-5];
    v_34382 = stack[-1];
    v_34382 = qcdr(v_34382);
    stack[-1] = v_34382;
    goto v_34327;
v_34326:
    goto v_34319;
v_34320:
    goto v_34316;
v_34317:
    goto v_34318;
v_34319:
    v_34382 = cons(stack[-4], v_34382);
    env = stack[-5];
    {
        fn = elt(env, 2); // eval
        return (*qfn1(fn))(fn, v_34382);
    }
    v_34382 = nil;
v_34306:
    return onevalue(v_34382);
}



// Code for talp_raf

static LispObject CC_talp_raf(LispObject env,
                         LispObject v_34303)
{
    env = qenv(env);
    LispObject v_34596, v_34597, v_34598;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34303);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[0] = v_34303;
// end of prologue
    v_34596 = stack[0];
    fn = elt(env, 5); // talp_op
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    stack[-9] = v_34596;
    v_34596 = stack[0];
    fn = elt(env, 6); // talp_arg2l
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    fn = elt(env, 7); // talp_tcfrp
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    if (v_34596 == nil) goto v_34320;
    v_34596 = stack[0];
    fn = elt(env, 8); // talp_arg2r
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    stack[-7] = v_34596;
    v_34596 = stack[0];
    fn = elt(env, 6); // talp_arg2l
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    goto v_34318;
v_34320:
    v_34596 = stack[0];
    fn = elt(env, 6); // talp_arg2l
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    stack[-7] = v_34596;
    v_34596 = stack[0];
    fn = elt(env, 8); // talp_arg2r
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    goto v_34318;
    v_34596 = nil;
v_34318:
    stack[-8] = v_34596;
    goto v_34339;
v_34335:
    goto v_34345;
v_34341:
    v_34596 = stack[-8];
    fn = elt(env, 5); // talp_op
    v_34597 = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    goto v_34342;
v_34343:
    v_34596 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34344;
v_34345:
    goto v_34341;
v_34342:
    goto v_34343;
v_34344:
    fn = elt(env, 9); // talp_getinvfsym
    v_34597 = (*qfn2(fn))(fn, v_34597, v_34596);
    env = stack[-10];
    goto v_34336;
v_34337:
    v_34596 = stack[-7];
    goto v_34338;
v_34339:
    goto v_34335;
v_34336:
    goto v_34337;
v_34338:
    fn = elt(env, 10); // talp_mkinv
    v_34596 = (*qfn2(fn))(fn, v_34597, v_34596);
    env = stack[-10];
    goto v_34359;
v_34355:
    v_34598 = stack[-9];
    goto v_34356;
v_34357:
    v_34597 = elt(env, 1); // equal
    goto v_34358;
v_34359:
    goto v_34355;
v_34356:
    goto v_34357;
v_34358:
    if (v_34598 == v_34597) goto v_34353;
    else goto v_34354;
v_34353:
    goto v_34369;
v_34363:
    v_34598 = elt(env, 2); // neq
    goto v_34364;
v_34365:
    v_34597 = v_34596;
    goto v_34366;
v_34367:
    v_34596 = stack[-7];
    goto v_34368;
v_34369:
    goto v_34363;
v_34364:
    goto v_34365;
v_34366:
    goto v_34367;
v_34368:
    fn = elt(env, 11); // talp_mk2
    v_34596 = (*qfnn(fn))(fn, 3, v_34598, v_34597, v_34596);
    env = stack[-10];
    goto v_34352;
v_34354:
    goto v_34382;
v_34376:
    v_34598 = elt(env, 1); // equal
    goto v_34377;
v_34378:
    v_34597 = v_34596;
    goto v_34379;
v_34380:
    v_34596 = stack[-7];
    goto v_34381;
v_34382:
    goto v_34376;
v_34377:
    goto v_34378;
v_34379:
    goto v_34380;
v_34381:
    fn = elt(env, 11); // talp_mk2
    v_34596 = (*qfnn(fn))(fn, 3, v_34598, v_34597, v_34596);
    env = stack[-10];
    goto v_34352;
    v_34596 = nil;
v_34352:
    fn = elt(env, 12); // talp_simpat
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    stack[-6] = v_34596;
    v_34596 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_34596;
    goto v_34403;
v_34399:
    goto v_34408;
v_34404:
    v_34596 = stack[-8];
    fn = elt(env, 5); // talp_op
    stack[0] = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    goto v_34405;
v_34406:
    fn = elt(env, 13); // talp_getl
    v_34596 = (*qfnn(fn))(fn, 0);
    env = stack[-10];
    goto v_34407;
v_34408:
    goto v_34404;
v_34405:
    goto v_34406;
v_34407:
    v_34596 = Latsoc(nil, stack[0], v_34596);
    v_34597 = qcdr(v_34596);
    goto v_34400;
v_34401:
    v_34596 = stack[-5];
    goto v_34402;
v_34403:
    goto v_34399;
v_34400:
    goto v_34401;
v_34402:
    v_34596 = difference2(v_34597, v_34596);
    env = stack[-10];
    v_34596 = Lminusp(nil, v_34596);
    env = stack[-10];
    if (v_34596 == nil) goto v_34396;
    v_34596 = nil;
    goto v_34390;
v_34396:
    goto v_34422;
v_34418:
    v_34596 = stack[-8];
    fn = elt(env, 5); // talp_op
    v_34597 = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    goto v_34419;
v_34420:
    v_34596 = stack[-5];
    goto v_34421;
v_34422:
    goto v_34418;
v_34419:
    goto v_34420;
v_34421:
    fn = elt(env, 9); // talp_getinvfsym
    v_34596 = (*qfn2(fn))(fn, v_34597, v_34596);
    env = stack[-10];
    goto v_34434;
v_34428:
    stack[-1] = stack[-9];
    goto v_34429;
v_34430:
    goto v_34441;
v_34437:
    v_34597 = v_34596;
    goto v_34438;
v_34439:
    v_34596 = stack[-7];
    goto v_34440;
v_34441:
    goto v_34437;
v_34438:
    goto v_34439;
v_34440:
    fn = elt(env, 10); // talp_mkinv
    stack[0] = (*qfn2(fn))(fn, v_34597, v_34596);
    env = stack[-10];
    goto v_34431;
v_34432:
    goto v_34449;
v_34445:
    v_34596 = stack[-8];
    fn = elt(env, 14); // talp_fargl
    v_34597 = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    goto v_34446;
v_34447:
    v_34596 = stack[-5];
    goto v_34448;
v_34449:
    goto v_34445;
v_34446:
    goto v_34447;
v_34448:
    fn = elt(env, 15); // nth
    v_34596 = (*qfn2(fn))(fn, v_34597, v_34596);
    env = stack[-10];
    goto v_34433;
v_34434:
    goto v_34428;
v_34429:
    goto v_34430;
v_34431:
    goto v_34432;
v_34433:
    fn = elt(env, 11); // talp_mk2
    v_34596 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_34596);
    env = stack[-10];
    fn = elt(env, 12); // talp_simpat
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    v_34596 = ncons(v_34596);
    env = stack[-10];
    stack[-3] = v_34596;
    stack[-4] = v_34596;
v_34391:
    v_34596 = stack[-5];
    v_34596 = add1(v_34596);
    env = stack[-10];
    stack[-5] = v_34596;
    goto v_34465;
v_34461:
    goto v_34470;
v_34466:
    v_34596 = stack[-8];
    fn = elt(env, 5); // talp_op
    stack[0] = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    goto v_34467;
v_34468:
    fn = elt(env, 13); // talp_getl
    v_34596 = (*qfnn(fn))(fn, 0);
    env = stack[-10];
    goto v_34469;
v_34470:
    goto v_34466;
v_34467:
    goto v_34468;
v_34469:
    v_34596 = Latsoc(nil, stack[0], v_34596);
    v_34597 = qcdr(v_34596);
    goto v_34462;
v_34463:
    v_34596 = stack[-5];
    goto v_34464;
v_34465:
    goto v_34461;
v_34462:
    goto v_34463;
v_34464:
    v_34596 = difference2(v_34597, v_34596);
    env = stack[-10];
    v_34596 = Lminusp(nil, v_34596);
    env = stack[-10];
    if (v_34596 == nil) goto v_34458;
    v_34596 = stack[-4];
    goto v_34390;
v_34458:
    goto v_34483;
v_34479:
    stack[-2] = stack[-3];
    goto v_34480;
v_34481:
    goto v_34491;
v_34487:
    v_34596 = stack[-8];
    fn = elt(env, 5); // talp_op
    v_34597 = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    goto v_34488;
v_34489:
    v_34596 = stack[-5];
    goto v_34490;
v_34491:
    goto v_34487;
v_34488:
    goto v_34489;
v_34490:
    fn = elt(env, 9); // talp_getinvfsym
    v_34596 = (*qfn2(fn))(fn, v_34597, v_34596);
    env = stack[-10];
    goto v_34503;
v_34497:
    stack[-1] = stack[-9];
    goto v_34498;
v_34499:
    goto v_34510;
v_34506:
    v_34597 = v_34596;
    goto v_34507;
v_34508:
    v_34596 = stack[-7];
    goto v_34509;
v_34510:
    goto v_34506;
v_34507:
    goto v_34508;
v_34509:
    fn = elt(env, 10); // talp_mkinv
    stack[0] = (*qfn2(fn))(fn, v_34597, v_34596);
    env = stack[-10];
    goto v_34500;
v_34501:
    goto v_34518;
v_34514:
    v_34596 = stack[-8];
    fn = elt(env, 14); // talp_fargl
    v_34597 = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    goto v_34515;
v_34516:
    v_34596 = stack[-5];
    goto v_34517;
v_34518:
    goto v_34514;
v_34515:
    goto v_34516;
v_34517:
    fn = elt(env, 15); // nth
    v_34596 = (*qfn2(fn))(fn, v_34597, v_34596);
    env = stack[-10];
    goto v_34502;
v_34503:
    goto v_34497;
v_34498:
    goto v_34499;
v_34500:
    goto v_34501;
v_34502:
    fn = elt(env, 11); // talp_mk2
    v_34596 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_34596);
    env = stack[-10];
    fn = elt(env, 12); // talp_simpat
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    v_34596 = ncons(v_34596);
    env = stack[-10];
    goto v_34482;
v_34483:
    goto v_34479;
v_34480:
    goto v_34481;
v_34482:
    v_34596 = Lrplacd(nil, stack[-2], v_34596);
    env = stack[-10];
    v_34596 = stack[-3];
    v_34596 = qcdr(v_34596);
    stack[-3] = v_34596;
    goto v_34391;
v_34390:
    v_34598 = v_34596;
    v_34596 = v_34598;
    stack[-3] = v_34596;
    v_34596 = stack[-3];
    if (v_34596 == nil) goto v_34533;
    else goto v_34534;
v_34533:
    v_34596 = nil;
    goto v_34528;
v_34534:
    v_34596 = stack[-3];
    v_34596 = qcar(v_34596);
    fn = elt(env, 16); // talp_rnf1
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    v_34596 = ncons(v_34596);
    env = stack[-10];
    stack[-1] = v_34596;
    stack[-2] = v_34596;
v_34529:
    v_34596 = stack[-3];
    v_34596 = qcdr(v_34596);
    stack[-3] = v_34596;
    v_34596 = stack[-3];
    if (v_34596 == nil) goto v_34547;
    else goto v_34548;
v_34547:
    v_34596 = stack[-2];
    goto v_34528;
v_34548:
    goto v_34556;
v_34552:
    stack[0] = stack[-1];
    goto v_34553;
v_34554:
    v_34596 = stack[-3];
    v_34596 = qcar(v_34596);
    fn = elt(env, 16); // talp_rnf1
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-10];
    v_34596 = ncons(v_34596);
    env = stack[-10];
    goto v_34555;
v_34556:
    goto v_34552;
v_34553:
    goto v_34554;
v_34555:
    v_34596 = Lrplacd(nil, stack[0], v_34596);
    env = stack[-10];
    v_34596 = stack[-1];
    v_34596 = qcdr(v_34596);
    stack[-1] = v_34596;
    goto v_34529;
v_34528:
    v_34598 = v_34596;
    goto v_34571;
v_34567:
    goto v_34580;
v_34576:
    v_34597 = stack[-9];
    goto v_34577;
v_34578:
    v_34596 = elt(env, 1); // equal
    goto v_34579;
v_34580:
    goto v_34576;
v_34577:
    goto v_34578;
v_34579:
    if (v_34597 == v_34596) goto v_34574;
    else goto v_34575;
v_34574:
    v_34596 = elt(env, 3); // and
    stack[0] = v_34596;
    goto v_34573;
v_34575:
    v_34596 = elt(env, 4); // or
    stack[0] = v_34596;
    goto v_34573;
    stack[0] = nil;
v_34573:
    goto v_34568;
v_34569:
    goto v_34592;
v_34588:
    v_34596 = stack[-6];
    goto v_34589;
v_34590:
    v_34597 = v_34598;
    goto v_34591;
v_34592:
    goto v_34588;
v_34589:
    goto v_34590;
v_34591:
    v_34596 = cons(v_34596, v_34597);
    env = stack[-10];
    goto v_34570;
v_34571:
    goto v_34567;
v_34568:
    goto v_34569;
v_34570:
    {
        LispObject v_34609 = stack[0];
        fn = elt(env, 17); // talp_mkn
        return (*qfn2(fn))(fn, v_34609, v_34596);
    }
    return onevalue(v_34596);
}



// Code for pasf_qff2ivl

static LispObject CC_pasf_qff2ivl(LispObject env,
                         LispObject v_34303)
{
    env = qenv(env);
    LispObject v_34319;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34303);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_34303;
// end of prologue
    v_34319 = stack[0];
    fn = elt(env, 2); // pasf_uprap
    v_34319 = (*qfn1(fn))(fn, v_34319);
    env = stack[-1];
    if (v_34319 == nil) goto v_34308;
    v_34319 = elt(env, 1); // "pasf_qff2ivl : uniform Presburger arithmetic formula in input"
    v_34319 = ncons(v_34319);
    env = stack[-1];
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_34319);
    }
v_34308:
    v_34319 = stack[0];
    fn = elt(env, 4); // pasf_dnf
    v_34319 = (*qfn1(fn))(fn, v_34319);
    env = stack[-1];
    {
        fn = elt(env, 5); // pasf_qff2ivl1
        return (*qfn1(fn))(fn, v_34319);
    }
    v_34319 = nil;
    return onevalue(v_34319);
}



// Code for vdp_putprop

static LispObject CC_vdp_putprop(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_34360, v_34361, v_34362, v_34363, v_34364;
    LispObject v_34305, v_34304, v_34303;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "vdp_putprop");
    va_start(aa, nargs);
    v_34303 = va_arg(aa, LispObject);
    v_34304 = va_arg(aa, LispObject);
    v_34305 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_34305,v_34304,v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_34303,v_34304,v_34305);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_34362 = v_34305;
    v_34363 = v_34304;
    stack[0] = v_34303;
// end of prologue
    v_34360 = stack[0];
    v_34360 = qcdr(v_34360);
    v_34360 = qcdr(v_34360);
    v_34360 = qcdr(v_34360);
    v_34360 = qcdr(v_34360);
    v_34361 = v_34360;
    goto v_34320;
v_34316:
    v_34364 = v_34363;
    goto v_34317;
v_34318:
    v_34360 = v_34361;
    v_34360 = qcar(v_34360);
    goto v_34319;
v_34320:
    goto v_34316;
v_34317:
    goto v_34318;
v_34319:
    v_34360 = Latsoc(nil, v_34364, v_34360);
    v_34364 = v_34360;
    v_34360 = v_34364;
    if (v_34360 == nil) goto v_34328;
    goto v_34335;
v_34331:
    v_34360 = v_34364;
    goto v_34332;
v_34333:
    v_34361 = v_34362;
    goto v_34334;
v_34335:
    goto v_34331;
v_34332:
    goto v_34333;
v_34334:
    v_34360 = Lrplacd(nil, v_34360, v_34361);
    goto v_34326;
v_34328:
    goto v_34345;
v_34341:
    stack[-1] = v_34361;
    goto v_34342;
v_34343:
    goto v_34354;
v_34348:
    v_34360 = v_34363;
    goto v_34349;
v_34350:
    goto v_34351;
v_34352:
    v_34361 = qcar(v_34361);
    goto v_34353;
v_34354:
    goto v_34348;
v_34349:
    goto v_34350;
v_34351:
    goto v_34352;
v_34353:
    v_34360 = acons(v_34360, v_34362, v_34361);
    env = stack[-2];
    goto v_34344;
v_34345:
    goto v_34341;
v_34342:
    goto v_34343;
v_34344:
    v_34360 = Lrplaca(nil, stack[-1], v_34360);
    goto v_34326;
v_34326:
    v_34360 = stack[0];
    return onevalue(v_34360);
}



// Code for compute!:intlog

static LispObject CC_computeTintlog(LispObject env,
                         LispObject v_34303)
{
    env = qenv(env);
    LispObject v_34337, v_34338, v_34339;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34303);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_34303;
// end of prologue
    goto v_34315;
v_34311:
    v_34338 = stack[0];
    goto v_34312;
v_34313:
    v_34337 = qvalue(elt(env, 1)); // intlog!:rem
    goto v_34314;
v_34315:
    goto v_34311;
v_34312:
    goto v_34313;
v_34314:
    v_34337 = Latsoc(nil, v_34338, v_34337);
    stack[-1] = v_34337;
    if (v_34337 == nil) goto v_34310;
    v_34337 = stack[-1];
    v_34337 = qcdr(v_34337);
    goto v_34308;
v_34310:
    v_34337 = stack[0];
    fn = elt(env, 2); // compute!:intlog1
    v_34337 = (*qfn1(fn))(fn, v_34337);
    env = stack[-2];
    stack[-1] = v_34337;
    goto v_34332;
v_34326:
    v_34339 = stack[0];
    goto v_34327;
v_34328:
    v_34338 = stack[-1];
    goto v_34329;
v_34330:
    v_34337 = qvalue(elt(env, 1)); // intlog!:rem
    goto v_34331;
v_34332:
    goto v_34326;
v_34327:
    goto v_34328;
v_34329:
    goto v_34330;
v_34331:
    v_34337 = acons(v_34339, v_34338, v_34337);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_34337; // intlog!:rem
    v_34337 = stack[-1];
    goto v_34308;
    v_34337 = nil;
v_34308:
    return onevalue(v_34337);
}



// Code for product!-set2

static LispObject CC_productKset2(LispObject env,
                         LispObject v_34303, LispObject v_34304)
{
    env = qenv(env);
    LispObject v_34357, v_34358;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34304,v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34303,v_34304);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_34304;
    v_34357 = v_34303;
// end of prologue
    stack[-4] = nil;
    stack[-2] = v_34357;
v_34312:
    v_34357 = stack[-2];
    if (v_34357 == nil) goto v_34316;
    else goto v_34317;
v_34316:
    goto v_34311;
v_34317:
    v_34357 = stack[-2];
    v_34357 = qcar(v_34357);
    stack[-1] = v_34357;
    v_34357 = stack[-3];
    stack[0] = v_34357;
v_34326:
    v_34357 = stack[0];
    if (v_34357 == nil) goto v_34330;
    else goto v_34331;
v_34330:
    goto v_34325;
v_34331:
    v_34357 = stack[0];
    v_34357 = qcar(v_34357);
    goto v_34342;
v_34338:
    goto v_34348;
v_34344:
    v_34358 = stack[-1];
    goto v_34345;
v_34346:
    goto v_34347;
v_34348:
    goto v_34344;
v_34345:
    goto v_34346;
v_34347:
    v_34358 = list2(v_34358, v_34357);
    env = stack[-5];
    goto v_34339;
v_34340:
    v_34357 = stack[-4];
    goto v_34341;
v_34342:
    goto v_34338;
v_34339:
    goto v_34340;
v_34341:
    v_34357 = cons(v_34358, v_34357);
    env = stack[-5];
    stack[-4] = v_34357;
    v_34357 = stack[0];
    v_34357 = qcdr(v_34357);
    stack[0] = v_34357;
    goto v_34326;
v_34325:
    v_34357 = stack[-2];
    v_34357 = qcdr(v_34357);
    stack[-2] = v_34357;
    goto v_34312;
v_34311:
    v_34357 = stack[-4];
    return onevalue(v_34357);
}



// Code for vdplsortin

static LispObject CC_vdplsortin(LispObject env,
                         LispObject v_34303, LispObject v_34304)
{
    env = qenv(env);
    LispObject v_34327, v_34328, v_34329;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_34304,v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_34303,v_34304);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_34304;
    v_34328 = v_34303;
// end of prologue
    v_34327 = stack[0];
    if (v_34327 == nil) goto v_34308;
    else goto v_34309;
v_34308:
    v_34327 = v_34328;
    return ncons(v_34327);
v_34309:
    goto v_34322;
v_34316:
    v_34329 = v_34328;
    goto v_34317;
v_34318:
    v_34328 = stack[0];
    goto v_34319;
v_34320:
    v_34327 = stack[0];
    goto v_34321;
v_34322:
    goto v_34316;
v_34317:
    goto v_34318;
v_34319:
    goto v_34320;
v_34321:
    fn = elt(env, 1); // vdplsortin1
    v_34327 = (*qfnn(fn))(fn, 3, v_34329, v_34328, v_34327);
    v_34327 = stack[0];
    goto v_34307;
    v_34327 = nil;
v_34307:
    return onevalue(v_34327);
}



// Code for preproc1

static LispObject CC_preproc1(LispObject env,
                         LispObject v_34303)
{
    env = qenv(env);
    LispObject v_35097, v_35098, v_35099;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34303);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_34303;
// end of prologue
v_34307:
    v_35097 = stack[-1];
    if (!consp(v_35097)) goto v_34310;
    else goto v_34311;
v_34310:
    v_35097 = stack[-1];
    return ncons(v_35097);
v_34311:
    goto v_34321;
v_34317:
    v_35097 = stack[-1];
    v_35098 = qcar(v_35097);
    goto v_34318;
v_34319:
    v_35097 = elt(env, 1); // !:rd!:
    goto v_34320;
v_34321:
    goto v_34317;
v_34318:
    goto v_34319;
v_34320:
    if (v_35098 == v_35097) goto v_34315;
    else goto v_34316;
v_34315:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    if (!consp(v_35097)) goto v_34328;
    else goto v_34329;
v_34328:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    v_35097 = Lfloatp(nil, v_35097);
    env = stack[-5];
    if (v_35097 == nil) goto v_34335;
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    fn = elt(env, 19); // fl2bf
    v_35097 = (*qfn1(fn))(fn, v_35097);
    goto v_34333;
v_34335:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    if (!consp(v_35097)) goto v_34348;
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    goto v_34346;
v_34348:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    v_35097 = integerp(v_35097);
    if (v_35097 == nil) goto v_34354;
    goto v_34365;
v_34359:
    v_35099 = elt(env, 1); // !:rd!:
    goto v_34360;
v_34361:
    v_35097 = stack[-1];
    v_35098 = qcdr(v_35097);
    goto v_34362;
v_34363:
    v_35097 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34364;
v_34365:
    goto v_34359;
v_34360:
    goto v_34361;
v_34362:
    goto v_34363;
v_34364:
    v_35097 = list2star(v_35099, v_35098, v_35097);
    env = stack[-5];
    goto v_34346;
v_34354:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    fn = elt(env, 20); // read!:num
    v_35097 = (*qfn1(fn))(fn, v_35097);
    env = stack[-5];
    goto v_34346;
    v_35097 = nil;
v_34346:
    fn = elt(env, 21); // normbf
    v_35097 = (*qfn1(fn))(fn, v_35097);
    goto v_34333;
    v_35097 = nil;
v_34333:
    goto v_34327;
v_34329:
    v_35097 = stack[-1];
    goto v_34327;
    v_35097 = nil;
v_34327:
    return ncons(v_35097);
v_34316:
    goto v_34384;
v_34380:
    v_35097 = stack[-1];
    v_35098 = qcar(v_35097);
    goto v_34381;
v_34382:
    v_35097 = elt(env, 2); // !:dn!:
    goto v_34383;
v_34384:
    goto v_34380;
v_34381:
    goto v_34382;
v_34383:
    if (v_35098 == v_35097) goto v_34378;
    else goto v_34379;
v_34378:
    goto v_34393;
v_34389:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    v_35098 = qcar(v_35097);
    goto v_34390;
v_34391:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    v_35097 = qcdr(v_35097);
    goto v_34392;
v_34393:
    goto v_34389;
v_34390:
    goto v_34391;
v_34392:
    fn = elt(env, 22); // decimal2internal
    v_35097 = (*qfn2(fn))(fn, v_35098, v_35097);
    env = stack[-5];
    stack[-1] = v_35097;
    goto v_34307;
v_34379:
    goto v_34406;
v_34402:
    v_35097 = stack[-1];
    v_35098 = qcar(v_35097);
    goto v_34403;
v_34404:
    v_35097 = elt(env, 3); // !*sq
    goto v_34405;
v_34406:
    goto v_34402;
v_34403:
    goto v_34404;
v_34405:
    if (v_35098 == v_35097) goto v_34400;
    else goto v_34401;
v_34400:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    v_35097 = qcar(v_35097);
    fn = elt(env, 23); // prepsq
    v_35097 = (*qfn1(fn))(fn, v_35097);
    env = stack[-5];
    stack[-1] = v_35097;
    goto v_34307;
v_34401:
    goto v_34420;
v_34416:
    v_35097 = stack[-1];
    v_35098 = qcar(v_35097);
    goto v_34417;
v_34418:
    v_35097 = elt(env, 4); // procedure
    goto v_34419;
v_34420:
    goto v_34416;
v_34417:
    goto v_34418;
v_34419:
    if (v_35098 == v_35097) goto v_34414;
    else goto v_34415;
v_34414:
    goto v_34431;
v_34425:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    v_35099 = qcar(v_35097);
    goto v_34426;
v_34427:
    v_35098 = elt(env, 5); // !*params!*
    goto v_34428;
v_34429:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    v_35097 = qcdr(v_35097);
    v_35097 = qcdr(v_35097);
    v_35097 = qcdr(v_35097);
    v_35097 = qcar(v_35097);
    goto v_34430;
v_34431:
    goto v_34425;
v_34426:
    goto v_34427;
v_34428:
    goto v_34429;
v_34430:
    fn = elt(env, 24); // symtabput
    v_35097 = (*qfnn(fn))(fn, 3, v_35099, v_35098, v_35097);
    env = stack[-5];
    v_35097 = qvalue(elt(env, 6)); // !*getdecs
    if (v_35097 == nil) goto v_34445;
    goto v_34455;
v_34451:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    v_35097 = qcdr(v_35097);
    v_35098 = qcar(v_35097);
    goto v_34452;
v_34453:
    v_35097 = elt(env, 7); // (real integer)
    goto v_34454;
v_34455:
    goto v_34451;
v_34452:
    goto v_34453;
v_34454:
    v_35097 = Lmemq(nil, v_35098, v_35097);
    if (v_35097 == nil) goto v_34450;
    goto v_34469;
v_34463:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    stack[-2] = qcar(v_35097);
    goto v_34464;
v_34465:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    stack[0] = qcar(v_35097);
    goto v_34466;
v_34467:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    v_35097 = qcdr(v_35097);
    v_35097 = qcar(v_35097);
    v_35097 = ncons(v_35097);
    env = stack[-5];
    goto v_34468;
v_34469:
    goto v_34463;
v_34464:
    goto v_34465;
v_34466:
    goto v_34467;
v_34468:
    fn = elt(env, 24); // symtabput
    v_35097 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_35097);
    env = stack[-5];
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    v_35097 = qcdr(v_35097);
    v_35097 = qcdr(v_35097);
    v_35097 = qcdr(v_35097);
    v_35097 = qcar(v_35097);
    stack[-3] = v_35097;
v_34484:
    v_35097 = stack[-3];
    if (v_35097 == nil) goto v_34493;
    else goto v_34494;
v_34493:
    goto v_34483;
v_34494:
    v_35097 = stack[-3];
    v_35097 = qcar(v_35097);
    v_35098 = v_35097;
    goto v_34507;
v_34501:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    stack[-2] = qcar(v_35097);
    goto v_34502;
v_34503:
    stack[0] = v_35098;
    goto v_34504;
v_34505:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    v_35097 = qcdr(v_35097);
    v_35097 = qcar(v_35097);
    v_35097 = ncons(v_35097);
    env = stack[-5];
    goto v_34506;
v_34507:
    goto v_34501;
v_34502:
    goto v_34503;
v_34504:
    goto v_34505;
v_34506:
    fn = elt(env, 24); // symtabput
    v_35097 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_35097);
    env = stack[-5];
    v_35097 = stack[-3];
    v_35097 = qcdr(v_35097);
    stack[-3] = v_35097;
    goto v_34484;
v_34483:
    goto v_34525;
v_34521:
    goto v_34533;
v_34527:
    v_35099 = elt(env, 4); // procedure
    goto v_34528;
v_34529:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    v_35098 = qcar(v_35097);
    goto v_34530;
v_34531:
    v_35097 = nil;
    goto v_34532;
v_34533:
    goto v_34527;
v_34528:
    goto v_34529;
v_34530:
    goto v_34531;
v_34532:
    stack[-4] = list3(v_35099, v_35098, v_35097);
    env = stack[-5];
    goto v_34522;
v_34523:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    v_35097 = qcdr(v_35097);
    v_35097 = qcdr(v_35097);
    stack[-3] = v_35097;
v_34544:
    v_35097 = stack[-3];
    if (v_35097 == nil) goto v_34552;
    else goto v_34553;
v_34552:
    v_35097 = nil;
    goto v_34543;
v_34553:
    v_35097 = stack[-3];
    v_35097 = qcar(v_35097);
    v_35097 = CC_preproc1(elt(env, 0), v_35097);
    env = stack[-5];
    stack[-2] = v_35097;
    v_35097 = stack[-2];
    fn = elt(env, 25); // lastpair
    v_35097 = (*qfn1(fn))(fn, v_35097);
    env = stack[-5];
    stack[-1] = v_35097;
    v_35097 = stack[-3];
    v_35097 = qcdr(v_35097);
    stack[-3] = v_35097;
    v_35097 = stack[-1];
    if (!consp(v_35097)) goto v_34567;
    else goto v_34568;
v_34567:
    goto v_34544;
v_34568:
v_34545:
    v_35097 = stack[-3];
    if (v_35097 == nil) goto v_34572;
    else goto v_34573;
v_34572:
    v_35097 = stack[-2];
    goto v_34543;
v_34573:
    goto v_34581;
v_34577:
    stack[0] = stack[-1];
    goto v_34578;
v_34579:
    v_35097 = stack[-3];
    v_35097 = qcar(v_35097);
    v_35097 = CC_preproc1(elt(env, 0), v_35097);
    env = stack[-5];
    goto v_34580;
v_34581:
    goto v_34577;
v_34578:
    goto v_34579;
v_34580:
    v_35097 = Lrplacd(nil, stack[0], v_35097);
    env = stack[-5];
    v_35097 = stack[-1];
    fn = elt(env, 25); // lastpair
    v_35097 = (*qfn1(fn))(fn, v_35097);
    env = stack[-5];
    stack[-1] = v_35097;
    v_35097 = stack[-3];
    v_35097 = qcdr(v_35097);
    stack[-3] = v_35097;
    goto v_34545;
v_34543:
    goto v_34524;
v_34525:
    goto v_34521;
v_34522:
    goto v_34523;
v_34524:
    v_35097 = Lnconc(nil, stack[-4], v_35097);
    return ncons(v_35097);
v_34450:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    v_35097 = qcdr(v_35097);
    v_35097 = qcdr(v_35097);
    v_35097 = qcdr(v_35097);
    v_35097 = qcar(v_35097);
    stack[-3] = v_35097;
v_34597:
    v_35097 = stack[-3];
    if (v_35097 == nil) goto v_34606;
    else goto v_34607;
v_34606:
    goto v_34596;
v_34607:
    v_35097 = stack[-3];
    v_35097 = qcar(v_35097);
    v_35098 = v_35097;
    goto v_34620;
v_34614:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    stack[-2] = qcar(v_35097);
    goto v_34615;
v_34616:
    stack[0] = v_35098;
    goto v_34617;
v_34618:
    v_35097 = qvalue(elt(env, 8)); // deftype!*
    v_35097 = ncons(v_35097);
    env = stack[-5];
    goto v_34619;
v_34620:
    goto v_34614;
v_34615:
    goto v_34616;
v_34617:
    goto v_34618;
v_34619:
    fn = elt(env, 24); // symtabput
    v_35097 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_35097);
    env = stack[-5];
    v_35097 = stack[-3];
    v_35097 = qcdr(v_35097);
    stack[-3] = v_35097;
    goto v_34597;
v_34596:
    v_35097 = stack[-1];
    stack[-3] = v_35097;
v_34635:
    v_35097 = stack[-3];
    if (v_35097 == nil) goto v_34640;
    else goto v_34641;
v_34640:
    v_35097 = nil;
    goto v_34634;
v_34641:
    v_35097 = stack[-3];
    v_35097 = qcar(v_35097);
    v_35097 = CC_preproc1(elt(env, 0), v_35097);
    env = stack[-5];
    stack[-2] = v_35097;
    v_35097 = stack[-2];
    fn = elt(env, 25); // lastpair
    v_35097 = (*qfn1(fn))(fn, v_35097);
    env = stack[-5];
    stack[-1] = v_35097;
    v_35097 = stack[-3];
    v_35097 = qcdr(v_35097);
    stack[-3] = v_35097;
    v_35097 = stack[-1];
    if (!consp(v_35097)) goto v_34655;
    else goto v_34656;
v_34655:
    goto v_34635;
v_34656:
v_34636:
    v_35097 = stack[-3];
    if (v_35097 == nil) goto v_34660;
    else goto v_34661;
v_34660:
    v_35097 = stack[-2];
    goto v_34634;
v_34661:
    goto v_34669;
v_34665:
    stack[0] = stack[-1];
    goto v_34666;
v_34667:
    v_35097 = stack[-3];
    v_35097 = qcar(v_35097);
    v_35097 = CC_preproc1(elt(env, 0), v_35097);
    env = stack[-5];
    goto v_34668;
v_34669:
    goto v_34665;
v_34666:
    goto v_34667;
v_34668:
    v_35097 = Lrplacd(nil, stack[0], v_35097);
    env = stack[-5];
    v_35097 = stack[-1];
    fn = elt(env, 25); // lastpair
    v_35097 = (*qfn1(fn))(fn, v_35097);
    env = stack[-5];
    stack[-1] = v_35097;
    v_35097 = stack[-3];
    v_35097 = qcdr(v_35097);
    stack[-3] = v_35097;
    goto v_34636;
v_34634:
    return ncons(v_35097);
    goto v_34443;
v_34445:
    v_35097 = stack[-1];
    stack[-3] = v_35097;
v_34688:
    v_35097 = stack[-3];
    if (v_35097 == nil) goto v_34693;
    else goto v_34694;
v_34693:
    v_35097 = nil;
    goto v_34687;
v_34694:
    v_35097 = stack[-3];
    v_35097 = qcar(v_35097);
    v_35097 = CC_preproc1(elt(env, 0), v_35097);
    env = stack[-5];
    stack[-2] = v_35097;
    v_35097 = stack[-2];
    fn = elt(env, 25); // lastpair
    v_35097 = (*qfn1(fn))(fn, v_35097);
    env = stack[-5];
    stack[-1] = v_35097;
    v_35097 = stack[-3];
    v_35097 = qcdr(v_35097);
    stack[-3] = v_35097;
    v_35097 = stack[-1];
    if (!consp(v_35097)) goto v_34708;
    else goto v_34709;
v_34708:
    goto v_34688;
v_34709:
v_34689:
    v_35097 = stack[-3];
    if (v_35097 == nil) goto v_34713;
    else goto v_34714;
v_34713:
    v_35097 = stack[-2];
    goto v_34687;
v_34714:
    goto v_34722;
v_34718:
    stack[0] = stack[-1];
    goto v_34719;
v_34720:
    v_35097 = stack[-3];
    v_35097 = qcar(v_35097);
    v_35097 = CC_preproc1(elt(env, 0), v_35097);
    env = stack[-5];
    goto v_34721;
v_34722:
    goto v_34718;
v_34719:
    goto v_34720;
v_34721:
    v_35097 = Lrplacd(nil, stack[0], v_35097);
    env = stack[-5];
    v_35097 = stack[-1];
    fn = elt(env, 25); // lastpair
    v_35097 = (*qfn1(fn))(fn, v_35097);
    env = stack[-5];
    stack[-1] = v_35097;
    v_35097 = stack[-3];
    v_35097 = qcdr(v_35097);
    stack[-3] = v_35097;
    goto v_34689;
v_34687:
    return ncons(v_35097);
v_34443:
    goto v_34309;
v_34415:
    goto v_34739;
v_34735:
    v_35097 = stack[-1];
    v_35098 = qcar(v_35097);
    goto v_34736;
v_34737:
    v_35097 = elt(env, 9); // declare
    goto v_34738;
v_34739:
    goto v_34735;
v_34736:
    goto v_34737;
v_34738:
    if (v_35098 == v_35097) goto v_34733;
    else goto v_34734;
v_34733:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    v_35097 = CC_preproc1(elt(env, 0), v_35097);
    env = stack[-5];
    v_35097 = qcar(v_35097);
    stack[-1] = v_35097;
    v_35097 = stack[-1];
    fn = elt(env, 26); // preprocdec
    v_35097 = (*qfn1(fn))(fn, v_35097);
    env = stack[-5];
    stack[-1] = v_35097;
    v_35097 = stack[-1];
    stack[-4] = v_35097;
v_34752:
    v_35097 = stack[-4];
    if (v_35097 == nil) goto v_34756;
    else goto v_34757;
v_34756:
    goto v_34751;
v_34757:
    v_35097 = stack[-4];
    v_35097 = qcar(v_35097);
    stack[-3] = v_35097;
    v_35097 = stack[-3];
    v_35097 = qcdr(v_35097);
    stack[-2] = v_35097;
v_34766:
    v_35097 = stack[-2];
    if (v_35097 == nil) goto v_34771;
    else goto v_34772;
v_34771:
    goto v_34765;
v_34772:
    v_35097 = stack[-2];
    v_35097 = qcar(v_35097);
    v_35099 = v_35097;
    goto v_34786;
v_34782:
    v_35097 = stack[-3];
    v_35098 = qcar(v_35097);
    goto v_34783;
v_34784:
    v_35097 = elt(env, 10); // (subroutine function)
    goto v_34785;
v_34786:
    goto v_34782;
v_34783:
    goto v_34784;
v_34785:
    v_35097 = Lmemq(nil, v_35098, v_35097);
    if (v_35097 == nil) goto v_34781;
    goto v_34798;
v_34792:
    goto v_34793;
v_34794:
    v_35098 = elt(env, 11); // !*type!*
    goto v_34795;
v_34796:
    v_35097 = stack[-3];
    v_35097 = qcar(v_35097);
    goto v_34797;
v_34798:
    goto v_34792;
v_34793:
    goto v_34794;
v_34795:
    goto v_34796;
v_34797:
    fn = elt(env, 24); // symtabput
    v_35097 = (*qfnn(fn))(fn, 3, v_35099, v_35098, v_35097);
    env = stack[-5];
    goto v_34779;
v_34781:
    goto v_34812;
v_34806:
    stack[-1] = nil;
    goto v_34807;
v_34808:
    v_35097 = v_35099;
    if (!consp(v_35097)) goto v_34816;
    else goto v_34817;
v_34816:
    v_35097 = v_35099;
    stack[0] = v_35097;
    goto v_34815;
v_34817:
    v_35097 = v_35099;
    v_35097 = qcar(v_35097);
    stack[0] = v_35097;
    goto v_34815;
    stack[0] = nil;
v_34815:
    goto v_34809;
v_34810:
    v_35097 = v_35099;
    if (!consp(v_35097)) goto v_34826;
    else goto v_34827;
v_34826:
    v_35097 = stack[-3];
    v_35097 = qcar(v_35097);
    v_35097 = ncons(v_35097);
    env = stack[-5];
    goto v_34825;
v_34827:
    goto v_34839;
v_34835:
    v_35097 = stack[-3];
    v_35097 = qcar(v_35097);
    goto v_34836;
v_34837:
    v_35098 = v_35099;
    v_35098 = qcdr(v_35098);
    goto v_34838;
v_34839:
    goto v_34835;
v_34836:
    goto v_34837;
v_34838:
    v_35097 = cons(v_35097, v_35098);
    env = stack[-5];
    goto v_34825;
    v_35097 = nil;
v_34825:
    goto v_34811;
v_34812:
    goto v_34806;
v_34807:
    goto v_34808;
v_34809:
    goto v_34810;
v_34811:
    fn = elt(env, 24); // symtabput
    v_35097 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_35097);
    env = stack[-5];
    goto v_34779;
v_34779:
    v_35097 = stack[-2];
    v_35097 = qcdr(v_35097);
    stack[-2] = v_35097;
    goto v_34766;
v_34765:
    v_35097 = stack[-4];
    v_35097 = qcdr(v_35097);
    stack[-4] = v_35097;
    goto v_34752;
v_34751:
    v_35097 = nil;
    goto v_34306;
v_34734:
    goto v_34859;
v_34855:
    v_35097 = stack[-1];
    v_35098 = qcar(v_35097);
    goto v_34856;
v_34857:
    v_35097 = elt(env, 12); // setq
    goto v_34858;
v_34859:
    goto v_34855;
v_34856:
    goto v_34857;
v_34858:
    if (v_35098 == v_35097) goto v_34853;
    else goto v_34854;
v_34853:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    v_35097 = qcdr(v_35097);
    v_35097 = qcar(v_35097);
    v_35097 = Lconsp(nil, v_35097);
    env = stack[-5];
    if (v_35097 == nil) goto v_34865;
    else goto v_34866;
v_34865:
    v_35097 = nil;
    goto v_34864;
v_34866:
    goto v_34879;
v_34875:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    v_35097 = qcdr(v_35097);
    v_35097 = qcar(v_35097);
    v_35098 = qcar(v_35097);
    goto v_34876;
v_34877:
    v_35097 = elt(env, 13); // (cond progn)
    goto v_34878;
v_34879:
    goto v_34875;
v_34876:
    goto v_34877;
v_34878:
    v_35097 = Lmemq(nil, v_35098, v_35097);
    goto v_34864;
    v_35097 = nil;
v_34864:
    goto v_34852;
v_34854:
    v_35097 = nil;
    goto v_34852;
    v_35097 = nil;
v_34852:
    if (v_35097 == nil) goto v_34850;
    v_35097 = stack[-1];
    {
        fn = elt(env, 27); // migrate!-setqs
        return (*qfn1(fn))(fn, v_35097);
    }
v_34850:
    goto v_34898;
v_34894:
    v_35097 = stack[-1];
    v_35098 = qcar(v_35097);
    goto v_34895;
v_34896:
    v_35097 = elt(env, 14); // (plus times difference quotient minus)
    goto v_34897;
v_34898:
    goto v_34894;
v_34895:
    goto v_34896;
v_34897:
    v_35097 = Lmemq(nil, v_35098, v_35097);
    if (v_35097 == nil) goto v_34893;
    v_35097 = stack[-1];
    fn = elt(env, 28); // simp!*
    v_35097 = (*qfn1(fn))(fn, v_35097);
    env = stack[-5];
    v_35099 = v_35097;
    v_35097 = qcar(v_35097);
    v_35097 = Lconsp(nil, v_35097);
    env = stack[-5];
    if (v_35097 == nil) goto v_34909;
    goto v_34920;
v_34916:
    v_35097 = v_35099;
    v_35097 = qcar(v_35097);
    v_35098 = qcar(v_35097);
    goto v_34917;
v_34918:
    v_35097 = elt(env, 15); // (!:cr!: !:crn!: !:gi!:)
    goto v_34919;
v_34920:
    goto v_34916;
v_34917:
    goto v_34918;
v_34919:
    v_35097 = Lmemq(nil, v_35098, v_35097);
    if (v_35097 == nil) goto v_34909;
    v_35097 = v_35099;
    v_35097 = qcdr(v_35097);
    v_35097 = Lonep(nil, v_35097);
    env = stack[-5];
    if (v_35097 == nil) goto v_34929;
    v_35097 = v_35099;
    v_35097 = qcar(v_35097);
    return ncons(v_35097);
v_34929:
    goto v_34946;
v_34940:
    stack[-1] = elt(env, 16); // quotient
    goto v_34941;
v_34942:
    v_35097 = v_35099;
    stack[0] = qcar(v_35097);
    goto v_34943;
v_34944:
    goto v_34957;
v_34953:
    v_35097 = v_35099;
    v_35098 = qcdr(v_35097);
    goto v_34954;
v_34955:
    v_35097 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34956;
v_34957:
    goto v_34953;
v_34954:
    goto v_34955;
v_34956:
    v_35097 = cons(v_35098, v_35097);
    env = stack[-5];
    fn = elt(env, 23); // prepsq
    v_35097 = (*qfn1(fn))(fn, v_35097);
    env = stack[-5];
    v_35097 = CC_preproc1(elt(env, 0), v_35097);
    env = stack[-5];
    v_35097 = qcar(v_35097);
    goto v_34945;
v_34946:
    goto v_34940;
v_34941:
    goto v_34942;
v_34943:
    goto v_34944;
v_34945:
    v_35097 = list3(stack[-1], stack[0], v_35097);
    return ncons(v_35097);
    v_35097 = nil;
    goto v_34907;
v_34909:
    v_35097 = stack[-1];
    stack[-3] = v_35097;
v_34970:
    v_35097 = stack[-3];
    if (v_35097 == nil) goto v_34975;
    else goto v_34976;
v_34975:
    v_35097 = nil;
    goto v_34969;
v_34976:
    v_35097 = stack[-3];
    v_35097 = qcar(v_35097);
    v_35097 = CC_preproc1(elt(env, 0), v_35097);
    env = stack[-5];
    stack[-2] = v_35097;
    v_35097 = stack[-2];
    fn = elt(env, 25); // lastpair
    v_35097 = (*qfn1(fn))(fn, v_35097);
    env = stack[-5];
    stack[-1] = v_35097;
    v_35097 = stack[-3];
    v_35097 = qcdr(v_35097);
    stack[-3] = v_35097;
    v_35097 = stack[-1];
    if (!consp(v_35097)) goto v_34990;
    else goto v_34991;
v_34990:
    goto v_34970;
v_34991:
v_34971:
    v_35097 = stack[-3];
    if (v_35097 == nil) goto v_34995;
    else goto v_34996;
v_34995:
    v_35097 = stack[-2];
    goto v_34969;
v_34996:
    goto v_35004;
v_35000:
    stack[0] = stack[-1];
    goto v_35001;
v_35002:
    v_35097 = stack[-3];
    v_35097 = qcar(v_35097);
    v_35097 = CC_preproc1(elt(env, 0), v_35097);
    env = stack[-5];
    goto v_35003;
v_35004:
    goto v_35000;
v_35001:
    goto v_35002;
v_35003:
    v_35097 = Lrplacd(nil, stack[0], v_35097);
    env = stack[-5];
    v_35097 = stack[-1];
    fn = elt(env, 25); // lastpair
    v_35097 = (*qfn1(fn))(fn, v_35097);
    env = stack[-5];
    stack[-1] = v_35097;
    v_35097 = stack[-3];
    v_35097 = qcdr(v_35097);
    stack[-3] = v_35097;
    goto v_34971;
v_34969:
    return ncons(v_35097);
    v_35097 = nil;
v_34907:
    goto v_34306;
v_34893:
    v_35097 = qvalue(elt(env, 6)); // !*getdecs
    if (v_35097 == nil) goto v_35020;
    goto v_35028;
v_35024:
    v_35097 = stack[-1];
    v_35098 = qcar(v_35097);
    goto v_35025;
v_35026:
    v_35097 = elt(env, 17); // (!~for for)
    goto v_35027;
v_35028:
    goto v_35024;
v_35025:
    goto v_35026;
v_35027:
    v_35097 = Lmemq(nil, v_35098, v_35097);
    if (v_35097 == nil) goto v_35020;
    goto v_35040;
v_35034:
    v_35099 = nil;
    goto v_35035;
v_35036:
    v_35097 = stack[-1];
    v_35097 = qcdr(v_35097);
    v_35098 = qcar(v_35097);
    goto v_35037;
v_35038:
    v_35097 = elt(env, 18); // (integer)
    goto v_35039;
v_35040:
    goto v_35034;
v_35035:
    goto v_35036;
v_35037:
    goto v_35038;
v_35039:
    fn = elt(env, 24); // symtabput
    v_35097 = (*qfnn(fn))(fn, 3, v_35099, v_35098, v_35097);
    env = stack[-5];
    goto v_35018;
v_35020:
v_35018:
    v_35097 = stack[-1];
    stack[-3] = v_35097;
v_35052:
    v_35097 = stack[-3];
    if (v_35097 == nil) goto v_35057;
    else goto v_35058;
v_35057:
    v_35097 = nil;
    goto v_35051;
v_35058:
    v_35097 = stack[-3];
    v_35097 = qcar(v_35097);
    v_35097 = CC_preproc1(elt(env, 0), v_35097);
    env = stack[-5];
    stack[-2] = v_35097;
    v_35097 = stack[-2];
    fn = elt(env, 25); // lastpair
    v_35097 = (*qfn1(fn))(fn, v_35097);
    env = stack[-5];
    stack[-1] = v_35097;
    v_35097 = stack[-3];
    v_35097 = qcdr(v_35097);
    stack[-3] = v_35097;
    v_35097 = stack[-1];
    if (!consp(v_35097)) goto v_35072;
    else goto v_35073;
v_35072:
    goto v_35052;
v_35073:
v_35053:
    v_35097 = stack[-3];
    if (v_35097 == nil) goto v_35077;
    else goto v_35078;
v_35077:
    v_35097 = stack[-2];
    goto v_35051;
v_35078:
    goto v_35086;
v_35082:
    stack[0] = stack[-1];
    goto v_35083;
v_35084:
    v_35097 = stack[-3];
    v_35097 = qcar(v_35097);
    v_35097 = CC_preproc1(elt(env, 0), v_35097);
    env = stack[-5];
    goto v_35085;
v_35086:
    goto v_35082;
v_35083:
    goto v_35084;
v_35085:
    v_35097 = Lrplacd(nil, stack[0], v_35097);
    env = stack[-5];
    v_35097 = stack[-1];
    fn = elt(env, 25); // lastpair
    v_35097 = (*qfn1(fn))(fn, v_35097);
    env = stack[-5];
    stack[-1] = v_35097;
    v_35097 = stack[-3];
    v_35097 = qcdr(v_35097);
    stack[-3] = v_35097;
    goto v_35053;
v_35051:
    return ncons(v_35097);
v_34309:
    v_35097 = nil;
v_34306:
    return onevalue(v_35097);
}



// Code for basisvectorp

static LispObject CC_basisvectorp(LispObject env,
                         LispObject v_34303)
{
    env = qenv(env);
    LispObject v_34321, v_34322;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_34322 = v_34303;
// end of prologue
    v_34321 = v_34322;
    if (!consp(v_34321)) goto v_34308;
    goto v_34314;
v_34310:
    v_34321 = v_34322;
    goto v_34311;
v_34312:
    v_34322 = qvalue(elt(env, 1)); // basisvectorl!*
    goto v_34313;
v_34314:
    goto v_34310;
v_34311:
    goto v_34312;
v_34313:
    v_34321 = Lmemq(nil, v_34321, v_34322);
    goto v_34306;
v_34308:
    v_34321 = nil;
    goto v_34306;
    v_34321 = nil;
v_34306:
    return onevalue(v_34321);
}



// Code for listofvarnames

static LispObject CC_listofvarnames(LispObject env,
                         LispObject v_34303)
{
    env = qenv(env);
    LispObject v_34459, v_34460;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34303);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_34303;
// end of prologue
    v_34459 = stack[0];
    fn = elt(env, 3); // listp
    v_34459 = (*qfn1(fn))(fn, v_34459);
    env = stack[-5];
    if (v_34459 == nil) goto v_34307;
    else goto v_34308;
v_34307:
    v_34459 = elt(env, 1); // "invalid argument to listofvarnames"
    {
        fn = elt(env, 4); // rederr
        return (*qfn1(fn))(fn, v_34459);
    }
v_34308:
    v_34459 = stack[0];
    stack[-4] = v_34459;
    v_34459 = stack[-4];
    if (v_34459 == nil) goto v_34324;
    else goto v_34325;
v_34324:
    v_34459 = nil;
    goto v_34319;
v_34325:
    v_34459 = stack[-4];
    v_34459 = qcar(v_34459);
    stack[0] = v_34459;
    v_34459 = stack[0];
    fn = elt(env, 5); // domain!*p
    v_34459 = (*qfn1(fn))(fn, v_34459);
    env = stack[-5];
    if (v_34459 == nil) goto v_34335;
    goto v_34343;
v_34339:
    v_34460 = nil;
    goto v_34340;
v_34341:
    v_34459 = elt(env, 2); // free
    goto v_34342;
v_34343:
    goto v_34339;
v_34340:
    goto v_34341;
v_34342:
    v_34459 = cons(v_34460, v_34459);
    env = stack[-5];
    goto v_34333;
v_34335:
    v_34459 = stack[0];
    if (!consp(v_34459)) goto v_34346;
    else goto v_34347;
v_34346:
    goto v_34354;
v_34350:
    v_34460 = nil;
    goto v_34351;
v_34352:
    v_34459 = elt(env, 2); // free
    goto v_34353;
v_34354:
    goto v_34350;
v_34351:
    goto v_34352;
v_34353:
    v_34459 = cons(v_34460, v_34459);
    env = stack[-5];
    goto v_34333;
v_34347:
    v_34459 = stack[0];
    v_34459 = qcar(v_34459);
    if (symbolp(v_34459)) goto v_34357;
    else goto v_34358;
v_34357:
    goto v_34366;
v_34362:
    v_34459 = stack[0];
    v_34460 = qcar(v_34459);
    goto v_34363;
v_34364:
    v_34459 = elt(env, 2); // free
    goto v_34365;
v_34366:
    goto v_34362;
v_34363:
    goto v_34364;
v_34365:
    v_34459 = cons(v_34460, v_34459);
    env = stack[-5];
    goto v_34333;
v_34358:
    v_34459 = stack[0];
    v_34459 = qcar(v_34459);
    v_34459 = qcar(v_34459);
    if (symbolp(v_34459)) goto v_34370;
    else goto v_34371;
v_34370:
    goto v_34380;
v_34376:
    v_34459 = stack[0];
    v_34459 = qcar(v_34459);
    v_34460 = qcar(v_34459);
    goto v_34377;
v_34378:
    v_34459 = elt(env, 2); // free
    goto v_34379;
v_34380:
    goto v_34376;
v_34377:
    goto v_34378;
v_34379:
    v_34459 = cons(v_34460, v_34459);
    env = stack[-5];
    goto v_34333;
v_34371:
    v_34459 = nil;
v_34333:
    v_34459 = ncons(v_34459);
    env = stack[-5];
    stack[-2] = v_34459;
    stack[-3] = v_34459;
v_34320:
    v_34459 = stack[-4];
    v_34459 = qcdr(v_34459);
    stack[-4] = v_34459;
    v_34459 = stack[-4];
    if (v_34459 == nil) goto v_34389;
    else goto v_34390;
v_34389:
    v_34459 = stack[-3];
    goto v_34319;
v_34390:
    goto v_34398;
v_34394:
    stack[-1] = stack[-2];
    goto v_34395;
v_34396:
    v_34459 = stack[-4];
    v_34459 = qcar(v_34459);
    stack[0] = v_34459;
    v_34459 = stack[0];
    fn = elt(env, 5); // domain!*p
    v_34459 = (*qfn1(fn))(fn, v_34459);
    env = stack[-5];
    if (v_34459 == nil) goto v_34407;
    goto v_34415;
v_34411:
    v_34460 = nil;
    goto v_34412;
v_34413:
    v_34459 = elt(env, 2); // free
    goto v_34414;
v_34415:
    goto v_34411;
v_34412:
    goto v_34413;
v_34414:
    v_34459 = cons(v_34460, v_34459);
    env = stack[-5];
    goto v_34405;
v_34407:
    v_34459 = stack[0];
    if (!consp(v_34459)) goto v_34418;
    else goto v_34419;
v_34418:
    goto v_34426;
v_34422:
    v_34460 = nil;
    goto v_34423;
v_34424:
    v_34459 = elt(env, 2); // free
    goto v_34425;
v_34426:
    goto v_34422;
v_34423:
    goto v_34424;
v_34425:
    v_34459 = cons(v_34460, v_34459);
    env = stack[-5];
    goto v_34405;
v_34419:
    v_34459 = stack[0];
    v_34459 = qcar(v_34459);
    if (symbolp(v_34459)) goto v_34429;
    else goto v_34430;
v_34429:
    goto v_34438;
v_34434:
    v_34459 = stack[0];
    v_34460 = qcar(v_34459);
    goto v_34435;
v_34436:
    v_34459 = elt(env, 2); // free
    goto v_34437;
v_34438:
    goto v_34434;
v_34435:
    goto v_34436;
v_34437:
    v_34459 = cons(v_34460, v_34459);
    env = stack[-5];
    goto v_34405;
v_34430:
    v_34459 = stack[0];
    v_34459 = qcar(v_34459);
    v_34459 = qcar(v_34459);
    if (symbolp(v_34459)) goto v_34442;
    else goto v_34443;
v_34442:
    goto v_34452;
v_34448:
    v_34459 = stack[0];
    v_34459 = qcar(v_34459);
    v_34460 = qcar(v_34459);
    goto v_34449;
v_34450:
    v_34459 = elt(env, 2); // free
    goto v_34451;
v_34452:
    goto v_34448;
v_34449:
    goto v_34450;
v_34451:
    v_34459 = cons(v_34460, v_34459);
    env = stack[-5];
    goto v_34405;
v_34443:
    v_34459 = nil;
v_34405:
    v_34459 = ncons(v_34459);
    env = stack[-5];
    goto v_34397;
v_34398:
    goto v_34394;
v_34395:
    goto v_34396;
v_34397:
    v_34459 = Lrplacd(nil, stack[-1], v_34459);
    env = stack[-5];
    v_34459 = stack[-2];
    v_34459 = qcdr(v_34459);
    stack[-2] = v_34459;
    goto v_34320;
v_34319:
    goto v_34306;
    v_34459 = nil;
v_34306:
    return onevalue(v_34459);
}



// Code for find_bubles1

static LispObject CC_find_bubles1(LispObject env,
                         LispObject v_34303, LispObject v_34304)
{
    env = qenv(env);
    LispObject v_34332, v_34333, v_34334, v_34335, v_34336, v_34337;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_34332 = v_34304;
    v_34333 = v_34303;
// end of prologue
    goto v_34319;
v_34307:
    v_34337 = nil;
    goto v_34308;
v_34309:
    v_34334 = v_34333;
    v_34336 = qcar(v_34334);
    goto v_34310;
v_34311:
    v_34335 = nil;
    goto v_34312;
v_34313:
    v_34334 = v_34333;
    v_34334 = qcdr(v_34334);
    v_34334 = qcar(v_34334);
    goto v_34314;
v_34315:
    v_34333 = qcdr(v_34333);
    v_34333 = qcdr(v_34333);
    v_34333 = qcar(v_34333);
    goto v_34316;
v_34317:
    goto v_34318;
v_34319:
    goto v_34307;
v_34308:
    goto v_34309;
v_34310:
    goto v_34311;
v_34312:
    goto v_34313;
v_34314:
    goto v_34315;
v_34316:
    goto v_34317;
v_34318:
    {
        fn = elt(env, 1); // select_bubles
        return (*qfnn(fn))(fn, 6, v_34337, v_34336, v_34335, v_34334, v_34333, v_34332);
    }
}



// Code for compactf1

static LispObject CC_compactf1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_34342, v_34343, v_34344, v_34345, v_34346;
    LispObject fn;
    LispObject v_34306, v_34305, v_34304, v_34303;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "compactf1");
    va_start(aa, nargs);
    v_34303 = va_arg(aa, LispObject);
    v_34304 = va_arg(aa, LispObject);
    v_34305 = va_arg(aa, LispObject);
    v_34306 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_34306,v_34305,v_34304,v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_34303,v_34304,v_34305,v_34306);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_34306;
    stack[-1] = v_34305;
    stack[-2] = v_34304;
    stack[-3] = v_34303;
// end of prologue
    goto v_34316;
v_34312:
    v_34343 = stack[-1];
    goto v_34313;
v_34314:
    v_34342 = stack[0];
    goto v_34315;
v_34316:
    goto v_34312;
v_34313:
    goto v_34314;
v_34315:
    fn = elt(env, 1); // intersection
    v_34342 = (*qfn2(fn))(fn, v_34343, v_34342);
    env = stack[-4];
    v_34343 = v_34342;
    if (v_34343 == nil) goto v_34321;
    else goto v_34322;
v_34321:
    v_34342 = stack[-3];
    goto v_34310;
v_34322:
    goto v_34336;
v_34326:
    v_34346 = stack[-3];
    goto v_34327;
v_34328:
    v_34345 = stack[-2];
    goto v_34329;
v_34330:
    v_34344 = stack[-1];
    goto v_34331;
v_34332:
    v_34343 = stack[0];
    goto v_34333;
v_34334:
    goto v_34335;
v_34336:
    goto v_34326;
v_34327:
    goto v_34328;
v_34329:
    goto v_34330;
v_34331:
    goto v_34332;
v_34333:
    goto v_34334;
v_34335:
    {
        fn = elt(env, 2); // compactf11
        return (*qfnn(fn))(fn, 5, v_34346, v_34345, v_34344, v_34343, v_34342);
    }
v_34310:
    return onevalue(v_34342);
}



// Code for mo_deletecomp

static LispObject CC_mo_deletecomp(LispObject env,
                         LispObject v_34303)
{
    env = qenv(env);
    LispObject v_34348, v_34349;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34303);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_34348 = v_34303;
// end of prologue
    v_34349 = v_34348;
    v_34349 = qcar(v_34349);
    if (v_34349 == nil) goto v_34307;
    else goto v_34308;
v_34307:
    goto v_34306;
v_34308:
    v_34349 = v_34348;
    v_34349 = qcar(v_34349);
    v_34349 = qcdr(v_34349);
    if (v_34349 == nil) goto v_34312;
    else goto v_34313;
v_34312:
    goto v_34322;
v_34318:
    stack[0] = nil;
    goto v_34319;
v_34320:
    v_34348 = nil;
    fn = elt(env, 1); // mo!=deglist
    v_34348 = (*qfn1(fn))(fn, v_34348);
    goto v_34321;
v_34322:
    goto v_34318;
v_34319:
    goto v_34320;
v_34321:
    {
        LispObject v_34351 = stack[0];
        return cons(v_34351, v_34348);
    }
v_34313:
    goto v_34333;
v_34329:
    v_34349 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34330;
v_34331:
    v_34348 = qcar(v_34348);
    v_34348 = qcdr(v_34348);
    goto v_34332;
v_34333:
    goto v_34329;
v_34330:
    goto v_34331;
v_34332:
    v_34348 = cons(v_34349, v_34348);
    env = stack[-1];
    goto v_34344;
v_34340:
    stack[0] = v_34348;
    goto v_34341;
v_34342:
    fn = elt(env, 1); // mo!=deglist
    v_34348 = (*qfn1(fn))(fn, v_34348);
    goto v_34343;
v_34344:
    goto v_34340;
v_34341:
    goto v_34342;
v_34343:
    {
        LispObject v_34352 = stack[0];
        return cons(v_34352, v_34348);
    }
    v_34348 = nil;
v_34306:
    return onevalue(v_34348);
}



// Code for solvevars

static LispObject CC_solvevars(LispObject env,
                         LispObject v_34303)
{
    env = qenv(env);
    LispObject v_34339, v_34340;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34303);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_34340 = v_34303;
// end of prologue
    v_34339 = nil;
    stack[-2] = v_34339;
    v_34339 = v_34340;
    fn = elt(env, 1); // allbkern
    v_34339 = (*qfn1(fn))(fn, v_34339);
    env = stack[-3];
    stack[-1] = v_34339;
v_34310:
    v_34339 = stack[-1];
    if (v_34339 == nil) goto v_34315;
    else goto v_34316;
v_34315:
    goto v_34309;
v_34316:
    v_34339 = stack[-1];
    v_34339 = qcar(v_34339);
    stack[0] = v_34339;
    v_34339 = stack[0];
    fn = elt(env, 2); // constant_exprp
    v_34339 = (*qfn1(fn))(fn, v_34339);
    env = stack[-3];
    if (v_34339 == nil) goto v_34324;
    else goto v_34325;
v_34324:
    goto v_34333;
v_34329:
    v_34340 = stack[0];
    goto v_34330;
v_34331:
    v_34339 = stack[-2];
    goto v_34332;
v_34333:
    goto v_34329;
v_34330:
    goto v_34331;
v_34332:
    fn = elt(env, 3); // ordad
    v_34339 = (*qfn2(fn))(fn, v_34340, v_34339);
    env = stack[-3];
    stack[-2] = v_34339;
    goto v_34323;
v_34325:
v_34323:
    v_34339 = stack[-1];
    v_34339 = qcdr(v_34339);
    stack[-1] = v_34339;
    goto v_34310;
v_34309:
    v_34339 = stack[-2];
    return onevalue(v_34339);
}



// Code for gcdlist1

static LispObject CC_gcdlist1(LispObject env,
                         LispObject v_34303)
{
    env = qenv(env);
    LispObject v_34596, v_34597, v_34598;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34303);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[0] = v_34303;
// end of prologue
// Binding reduction!-count
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
    qvalue(elt(env, 1)) = nil; // reduction!-count
    v_34596 = stack[0];
    v_34596 = qcar(v_34596);
    v_34596 = qcdr(v_34596);
    stack[-4] = v_34596;
    stack[-2] = v_34596;
    v_34596 = stack[0];
    v_34596 = qcdr(v_34596);
    stack[-3] = v_34596;
v_34319:
    v_34596 = stack[-3];
    if (v_34596 == nil) goto v_34324;
    else goto v_34325;
v_34324:
    goto v_34318;
v_34325:
    v_34596 = stack[-3];
    v_34596 = qcar(v_34596);
    stack[-1] = v_34596;
    goto v_34336;
v_34332:
    v_34597 = stack[-2];
    goto v_34333;
v_34334:
    v_34596 = stack[-1];
    v_34596 = qcdr(v_34596);
    goto v_34335;
v_34336:
    goto v_34332;
v_34333:
    goto v_34334;
v_34335:
    fn = elt(env, 3); // vunion
    v_34596 = (*qfn2(fn))(fn, v_34597, v_34596);
    env = stack[-7];
    stack[-2] = v_34596;
    goto v_34345;
v_34341:
    v_34597 = stack[-4];
    goto v_34342;
v_34343:
    v_34596 = stack[-1];
    v_34596 = qcdr(v_34596);
    goto v_34344;
v_34345:
    goto v_34341;
v_34342:
    goto v_34343;
v_34344:
    fn = elt(env, 4); // vintersection
    v_34596 = (*qfn2(fn))(fn, v_34597, v_34596);
    env = stack[-7];
    stack[-4] = v_34596;
    v_34596 = stack[-3];
    v_34596 = qcdr(v_34596);
    stack[-3] = v_34596;
    goto v_34319;
v_34318:
    v_34596 = stack[-4];
    if (v_34596 == nil) goto v_34353;
    else goto v_34354;
v_34353:
    v_34596 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34312;
v_34354:
    v_34596 = stack[-4];
    stack[-1] = v_34596;
v_34360:
    v_34596 = stack[-1];
    if (v_34596 == nil) goto v_34364;
    else goto v_34365;
v_34364:
    goto v_34359;
v_34365:
    v_34596 = stack[-1];
    v_34596 = qcar(v_34596);
    goto v_34376;
v_34372:
    v_34597 = v_34596;
    goto v_34373;
v_34374:
    v_34596 = stack[-2];
    goto v_34375;
v_34376:
    goto v_34372;
v_34373:
    goto v_34374;
v_34375:
    fn = elt(env, 5); // vdelete
    v_34596 = (*qfn2(fn))(fn, v_34597, v_34596);
    env = stack[-7];
    stack[-2] = v_34596;
    v_34596 = stack[-1];
    v_34596 = qcdr(v_34596);
    stack[-1] = v_34596;
    goto v_34360;
v_34359:
    goto v_34386;
v_34382:
    v_34597 = stack[-4];
    goto v_34383;
v_34384:
    v_34596 = elt(env, 2); // lesspcdr
    goto v_34385;
v_34386:
    goto v_34382;
v_34383:
    goto v_34384;
v_34385:
    fn = elt(env, 6); // sort
    v_34596 = (*qfn2(fn))(fn, v_34597, v_34596);
    env = stack[-7];
    stack[-4] = v_34596;
    goto v_34397;
v_34393:
    v_34596 = stack[-4];
    v_34596 = qcar(v_34596);
    v_34597 = qcdr(v_34596);
    goto v_34394;
v_34395:
    v_34596 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34396;
v_34397:
    goto v_34393;
v_34394:
    goto v_34395;
v_34396:
    if (v_34597 == v_34596) goto v_34391;
    else goto v_34392;
v_34391:
    goto v_34408;
v_34404:
    v_34597 = stack[-4];
    goto v_34405;
v_34406:
    v_34596 = stack[-2];
    goto v_34407;
v_34408:
    goto v_34404;
v_34405:
    goto v_34406;
v_34407:
    v_34596 = Lappend(nil, v_34597, v_34596);
    env = stack[-7];
    fn = elt(env, 7); // mapcarcar
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-7];
    stack[-5] = v_34596;
    v_34596 = stack[-5];
    fn = elt(env, 8); // setkorder
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-7];
    stack[-4] = v_34596;
    goto v_34420;
v_34414:
    v_34596 = stack[0];
    stack[-3] = v_34596;
    v_34596 = stack[-3];
    if (v_34596 == nil) goto v_34430;
    else goto v_34431;
v_34430:
    v_34596 = nil;
    v_34598 = v_34596;
    goto v_34425;
v_34431:
    v_34596 = stack[-3];
    v_34596 = qcar(v_34596);
    v_34596 = qcar(v_34596);
    fn = elt(env, 9); // reorder
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-7];
    v_34596 = ncons(v_34596);
    env = stack[-7];
    stack[-1] = v_34596;
    stack[-2] = v_34596;
v_34426:
    v_34596 = stack[-3];
    v_34596 = qcdr(v_34596);
    stack[-3] = v_34596;
    v_34596 = stack[-3];
    if (v_34596 == nil) goto v_34445;
    else goto v_34446;
v_34445:
    v_34596 = stack[-2];
    v_34598 = v_34596;
    goto v_34425;
v_34446:
    goto v_34454;
v_34450:
    stack[0] = stack[-1];
    goto v_34451;
v_34452:
    v_34596 = stack[-3];
    v_34596 = qcar(v_34596);
    v_34596 = qcar(v_34596);
    fn = elt(env, 9); // reorder
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-7];
    v_34596 = ncons(v_34596);
    env = stack[-7];
    goto v_34453;
v_34454:
    goto v_34450;
v_34451:
    goto v_34452;
v_34453:
    v_34596 = Lrplacd(nil, stack[0], v_34596);
    env = stack[-7];
    v_34596 = stack[-1];
    v_34596 = qcdr(v_34596);
    stack[-1] = v_34596;
    goto v_34426;
v_34425:
    goto v_34415;
v_34416:
    v_34597 = nil;
    goto v_34417;
v_34418:
    v_34596 = stack[-5];
    goto v_34419;
v_34420:
    goto v_34414;
v_34415:
    goto v_34416;
v_34417:
    goto v_34418;
v_34419:
    fn = elt(env, 10); // gcdlist3
    v_34596 = (*qfnn(fn))(fn, 3, v_34598, v_34597, v_34596);
    env = stack[-7];
    stack[0] = v_34596;
    v_34596 = stack[-4];
    fn = elt(env, 8); // setkorder
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-7];
    v_34596 = stack[0];
    fn = elt(env, 9); // reorder
    v_34596 = (*qfn1(fn))(fn, v_34596);
    goto v_34312;
v_34392:
    v_34596 = stack[-2];
    if (v_34596 == nil) goto v_34471;
    else goto v_34472;
v_34471:
    goto v_34479;
v_34475:
    v_34597 = stack[0];
    goto v_34476;
v_34477:
    v_34596 = stack[-4];
    goto v_34478;
v_34479:
    goto v_34475;
v_34476:
    goto v_34477;
v_34478:
    fn = elt(env, 11); // gcdlist2
    v_34596 = (*qfn2(fn))(fn, v_34597, v_34596);
    goto v_34312;
v_34472:
    goto v_34489;
v_34485:
    v_34597 = stack[-2];
    goto v_34486;
v_34487:
    v_34596 = stack[-4];
    goto v_34488;
v_34489:
    goto v_34485;
v_34486:
    goto v_34487;
v_34488:
    v_34596 = Lappend(nil, v_34597, v_34596);
    env = stack[-7];
    fn = elt(env, 7); // mapcarcar
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-7];
    fn = elt(env, 8); // setkorder
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-7];
    stack[-5] = v_34596;
    v_34596 = nil;
    stack[-4] = v_34596;
    v_34596 = stack[0];
    stack[-1] = v_34596;
v_34496:
    v_34596 = stack[-1];
    if (v_34596 == nil) goto v_34500;
    else goto v_34501;
v_34500:
    goto v_34495;
v_34501:
    v_34596 = stack[-1];
    v_34596 = qcar(v_34596);
    goto v_34514;
v_34508:
    v_34596 = qcar(v_34596);
    fn = elt(env, 9); // reorder
    stack[0] = (*qfn1(fn))(fn, v_34596);
    env = stack[-7];
    goto v_34509;
v_34510:
    v_34596 = stack[-2];
    fn = elt(env, 7); // mapcarcar
    v_34597 = (*qfn1(fn))(fn, v_34596);
    env = stack[-7];
    goto v_34511;
v_34512:
    v_34596 = stack[-4];
    goto v_34513;
v_34514:
    goto v_34508;
v_34509:
    goto v_34510;
v_34511:
    goto v_34512;
v_34513:
    fn = elt(env, 12); // split!-wrt!-variables
    v_34596 = (*qfnn(fn))(fn, 3, stack[0], v_34597, v_34596);
    env = stack[-7];
    stack[-4] = v_34596;
    v_34596 = stack[-1];
    v_34596 = qcdr(v_34596);
    stack[-1] = v_34596;
    goto v_34496;
v_34495:
    v_34596 = stack[-5];
    fn = elt(env, 8); // setkorder
    v_34596 = (*qfn1(fn))(fn, v_34596);
    env = stack[-7];
    v_34596 = stack[-4];
    stack[-5] = v_34596;
    v_34596 = stack[-5];
    if (v_34596 == nil) goto v_34535;
    else goto v_34536;
v_34535:
    v_34596 = nil;
    goto v_34530;
v_34536:
    v_34596 = stack[-5];
    v_34596 = qcar(v_34596);
    stack[-1] = v_34596;
    goto v_34548;
v_34544:
    v_34596 = stack[-1];
    fn = elt(env, 9); // reorder
    stack[0] = (*qfn1(fn))(fn, v_34596);
    env = stack[-7];
    goto v_34545;
v_34546:
    goto v_34556;
v_34552:
    v_34597 = stack[-1];
    goto v_34553;
v_34554:
    v_34596 = nil;
    goto v_34555;
v_34556:
    goto v_34552;
v_34553:
    goto v_34554;
v_34555:
    fn = elt(env, 13); // total!-degree!-in!-powers
    v_34596 = (*qfn2(fn))(fn, v_34597, v_34596);
    env = stack[-7];
    goto v_34547;
v_34548:
    goto v_34544;
v_34545:
    goto v_34546;
v_34547:
    v_34596 = cons(stack[0], v_34596);
    env = stack[-7];
    v_34596 = ncons(v_34596);
    env = stack[-7];
    stack[-3] = v_34596;
    stack[-4] = v_34596;
v_34531:
    v_34596 = stack[-5];
    v_34596 = qcdr(v_34596);
    stack[-5] = v_34596;
    v_34596 = stack[-5];
    if (v_34596 == nil) goto v_34563;
    else goto v_34564;
v_34563:
    v_34596 = stack[-4];
    goto v_34530;
v_34564:
    goto v_34572;
v_34568:
    stack[-2] = stack[-3];
    goto v_34569;
v_34570:
    v_34596 = stack[-5];
    v_34596 = qcar(v_34596);
    stack[-1] = v_34596;
    goto v_34583;
v_34579:
    v_34596 = stack[-1];
    fn = elt(env, 9); // reorder
    stack[0] = (*qfn1(fn))(fn, v_34596);
    env = stack[-7];
    goto v_34580;
v_34581:
    goto v_34591;
v_34587:
    v_34597 = stack[-1];
    goto v_34588;
v_34589:
    v_34596 = nil;
    goto v_34590;
v_34591:
    goto v_34587;
v_34588:
    goto v_34589;
v_34590:
    fn = elt(env, 13); // total!-degree!-in!-powers
    v_34596 = (*qfn2(fn))(fn, v_34597, v_34596);
    env = stack[-7];
    goto v_34582;
v_34583:
    goto v_34579;
v_34580:
    goto v_34581;
v_34582:
    v_34596 = cons(stack[0], v_34596);
    env = stack[-7];
    v_34596 = ncons(v_34596);
    env = stack[-7];
    goto v_34571;
v_34572:
    goto v_34568;
v_34569:
    goto v_34570;
v_34571:
    v_34596 = Lrplacd(nil, stack[-2], v_34596);
    env = stack[-7];
    v_34596 = stack[-3];
    v_34596 = qcdr(v_34596);
    stack[-3] = v_34596;
    goto v_34531;
v_34530:
    v_34596 = CC_gcdlist1(elt(env, 0), v_34596);
v_34312:
    ;}  // end of a binding scope
    return onevalue(v_34596);
}



// Code for get!-min!-degreelist

static LispObject CC_getKminKdegreelist(LispObject env,
                         LispObject v_34303)
{
    env = qenv(env);
    LispObject v_34422, v_34423;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_34303);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_34303);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_34423 = v_34303;
// end of prologue
    v_34422 = v_34423;
    if (v_34422 == nil) goto v_34307;
    else goto v_34308;
v_34307:
    v_34422 = elt(env, 0); // get!-min!-degreelist
    {
        fn = elt(env, 1); // confusion
        return (*qfn1(fn))(fn, v_34422);
    }
v_34308:
    v_34422 = v_34423;
    v_34422 = qcdr(v_34422);
    if (v_34422 == nil) goto v_34312;
    else goto v_34313;
v_34312:
    v_34422 = v_34423;
    v_34422 = qcar(v_34422);
    v_34422 = qcar(v_34422);
    stack[-4] = v_34422;
    v_34422 = stack[-4];
    if (v_34422 == nil) goto v_34327;
    else goto v_34328;
v_34327:
    v_34422 = nil;
    goto v_34320;
v_34328:
    v_34422 = stack[-4];
    v_34422 = qcar(v_34422);
    stack[0] = v_34422;
    v_34422 = (LispObject)0+TAG_FIXNUM; // 0
    v_34423 = v_34422;
v_34339:
    v_34422 = stack[0];
    if (v_34422 == nil) goto v_34344;
    else goto v_34345;
v_34344:
    v_34422 = v_34423;
    goto v_34338;
v_34345:
    goto v_34353;
v_34349:
    v_34422 = stack[0];
    v_34422 = qcar(v_34422);
    goto v_34350;
v_34351:
    goto v_34352;
v_34353:
    goto v_34349;
v_34350:
    goto v_34351;
v_34352:
    fn = elt(env, 2); // tayexp!-plus2
    v_34422 = (*qfn2(fn))(fn, v_34422, v_34423);
    env = stack[-5];
    v_34423 = v_34422;
    v_34422 = stack[0];
    v_34422 = qcdr(v_34422);
    stack[0] = v_34422;
    goto v_34339;
v_34338:
    v_34422 = ncons(v_34422);
    env = stack[-5];
    stack[-2] = v_34422;
    stack[-3] = v_34422;
v_34321:
    v_34422 = stack[-4];
    v_34422 = qcdr(v_34422);
    stack[-4] = v_34422;
    v_34422 = stack[-4];
    if (v_34422 == nil) goto v_34365;
    else goto v_34366;
v_34365:
    v_34422 = stack[-3];
    goto v_34320;
v_34366:
    goto v_34374;
v_34370:
    stack[-1] = stack[-2];
    goto v_34371;
v_34372:
    v_34422 = stack[-4];
    v_34422 = qcar(v_34422);
    stack[0] = v_34422;
    v_34422 = (LispObject)0+TAG_FIXNUM; // 0
    v_34423 = v_34422;
v_34384:
    v_34422 = stack[0];
    if (v_34422 == nil) goto v_34389;
    else goto v_34390;
v_34389:
    v_34422 = v_34423;
    goto v_34383;
v_34390:
    goto v_34398;
v_34394:
    v_34422 = stack[0];
    v_34422 = qcar(v_34422);
    goto v_34395;
v_34396:
    goto v_34397;
v_34398:
    goto v_34394;
v_34395:
    goto v_34396;
v_34397:
    fn = elt(env, 2); // tayexp!-plus2
    v_34422 = (*qfn2(fn))(fn, v_34422, v_34423);
    env = stack[-5];
    v_34423 = v_34422;
    v_34422 = stack[0];
    v_34422 = qcdr(v_34422);
    stack[0] = v_34422;
    goto v_34384;
v_34383:
    v_34422 = ncons(v_34422);
    env = stack[-5];
    goto v_34373;
v_34374:
    goto v_34370;
v_34371:
    goto v_34372;
v_34373:
    v_34422 = Lrplacd(nil, stack[-1], v_34422);
    env = stack[-5];
    v_34422 = stack[-2];
    v_34422 = qcdr(v_34422);
    stack[-2] = v_34422;
    goto v_34321;
v_34320:
    goto v_34306;
v_34313:
    goto v_34415;
v_34411:
    v_34422 = v_34423;
    v_34422 = qcar(v_34422);
    stack[0] = qcar(v_34422);
    goto v_34412;
v_34413:
    v_34422 = v_34423;
    v_34422 = qcdr(v_34422);
    v_34422 = CC_getKminKdegreelist(elt(env, 0), v_34422);
    env = stack[-5];
    goto v_34414;
v_34415:
    goto v_34411;
v_34412:
    goto v_34413;
v_34414:
    {
        LispObject v_34429 = stack[0];
        fn = elt(env, 3); // taymindegreel
        return (*qfn2(fn))(fn, v_34429, v_34422);
    }
    v_34422 = nil;
v_34306:
    return onevalue(v_34422);
}



setup_type const u56_setup[] =
{
    {"mkexpvec",                CC_mkexpvec,    TOO_MANY_1,    WRONG_NO_1},
    {"monomispommaretdivisibleby",TOO_FEW_2,    CC_monomispommaretdivisibleby,WRONG_NO_2},
    {"preptaylor*2",            TOO_FEW_2,      CC_preptaylorH2,WRONG_NO_2},
    {"rl_reval",                TOO_FEW_2,      CC_rl_reval,   WRONG_NO_2},
    {"mri_irsplit",             CC_mri_irsplit, TOO_MANY_1,    WRONG_NO_1},
    {"expttermp1",              TOO_FEW_2,      CC_expttermp1, WRONG_NO_2},
    {"xreduce1",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xreduce1},
    {"quotient:",               TOO_FEW_2,      CC_quotientT,  WRONG_NO_2},
    {"mk-coeff1",               TOO_FEW_2,      CC_mkKcoeff1,  WRONG_NO_2},
    {"depend1",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_depend1},
    {"lf=less",                 TOO_FEW_2,      CC_lfMless,    WRONG_NO_2},
    {"sep_tens_from_other",     CC_sep_tens_from_other,TOO_MANY_1,WRONG_NO_1},
    {"absodeg",                 CC_absodeg,     TOO_MANY_1,    WRONG_NO_1},
    {"talp_raf",                CC_talp_raf,    TOO_MANY_1,    WRONG_NO_1},
    {"pasf_qff2ivl",            CC_pasf_qff2ivl,TOO_MANY_1,    WRONG_NO_1},
    {"vdp_putprop",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vdp_putprop},
    {"compute:intlog",          CC_computeTintlog,TOO_MANY_1,  WRONG_NO_1},
    {"product-set2",            TOO_FEW_2,      CC_productKset2,WRONG_NO_2},
    {"vdplsortin",              TOO_FEW_2,      CC_vdplsortin, WRONG_NO_2},
    {"preproc1",                CC_preproc1,    TOO_MANY_1,    WRONG_NO_1},
    {"basisvectorp",            CC_basisvectorp,TOO_MANY_1,    WRONG_NO_1},
    {"listofvarnames",          CC_listofvarnames,TOO_MANY_1,  WRONG_NO_1},
    {"find_bubles1",            TOO_FEW_2,      CC_find_bubles1,WRONG_NO_2},
    {"compactf1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_compactf1},
    {"mo_deletecomp",           CC_mo_deletecomp,TOO_MANY_1,   WRONG_NO_1},
    {"solvevars",               CC_solvevars,   TOO_MANY_1,    WRONG_NO_1},
    {"gcdlist1",                CC_gcdlist1,    TOO_MANY_1,    WRONG_NO_1},
    {"get-min-degreelist",      CC_getKminKdegreelist,TOO_MANY_1,WRONG_NO_1},
    {NULL, (one_args *)"u56", (two_args *)"130066 3087651 8156384", 0}
};

// end of generated code
