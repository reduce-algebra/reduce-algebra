
// $destdir/u22.c        Machine generated C code

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



// Code for mchkopt1

static LispObject CC_mchkopt1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12906, v_12907, v_12908;
    LispObject fn;
    LispObject v_12721, v_12720, v_12719;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mchkopt1");
    va_start(aa, nargs);
    v_12719 = va_arg(aa, LispObject);
    v_12720 = va_arg(aa, LispObject);
    v_12721 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12721,v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12719,v_12720,v_12721);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_12721;
    v_12906 = v_12720;
    v_12908 = v_12719;
// end of prologue
    v_12906 = qcdr(v_12906);
    v_12907 = v_12906;
    if (v_12906 == nil) goto v_12730;
    else goto v_12731;
v_12730:
    v_12906 = nil;
    goto v_12727;
v_12731:
    v_12906 = v_12907;
    v_12906 = qcar(v_12906);
    stack[-3] = v_12906;
    v_12906 = v_12907;
    v_12906 = qcdr(v_12906);
    v_12907 = v_12906;
    if (v_12906 == nil) goto v_12739;
    else goto v_12740;
v_12739:
    v_12906 = nil;
    goto v_12727;
v_12740:
    v_12906 = v_12907;
    v_12906 = qcar(v_12906);
    stack[-5] = v_12906;
    v_12906 = v_12907;
    v_12906 = qcdr(v_12906);
    if (v_12906 == nil) goto v_12749;
    v_12906 = nil;
    goto v_12727;
v_12749:
    v_12906 = stack[-3];
    if (!symbolp(v_12906)) v_12906 = nil;
    else { v_12906 = qfastgets(v_12906);
           if (v_12906 != nil) { v_12906 = elt(v_12906, 6); // optional
#ifdef RECORD_GET
             if (v_12906 == SPID_NOPROP)
                record_get(elt(fastget_names, 6), 0),
                v_12906 = nil;
             else record_get(elt(fastget_names, 6), 1),
                v_12906 = lisp_true; }
           else record_get(elt(fastget_names, 6), 0); }
#else
             if (v_12906 == SPID_NOPROP) v_12906 = nil; else v_12906 = lisp_true; }}
#endif
    if (v_12906 == nil) goto v_12756;
    goto v_12770;
v_12766:
    v_12907 = v_12908;
    goto v_12767;
v_12768:
    v_12906 = stack[-5];
    goto v_12769;
v_12770:
    goto v_12766;
v_12767:
    goto v_12768;
v_12769:
    fn = elt(env, 1); // mchk
    v_12906 = (*qfn2(fn))(fn, v_12907, v_12906);
    env = stack[-6];
    stack[-5] = v_12906;
    v_12906 = stack[-5];
    if (v_12906 == nil) goto v_12775;
    else goto v_12776;
v_12775:
    v_12906 = nil;
    goto v_12763;
v_12776:
    v_12906 = stack[-5];
    v_12906 = qcar(v_12906);
    goto v_12790;
v_12784:
    v_12908 = stack[-3];
    goto v_12785;
v_12786:
    v_12907 = stack[-4];
    v_12907 = qcar(v_12907);
    goto v_12787;
v_12788:
    goto v_12789;
v_12790:
    goto v_12784;
v_12785:
    goto v_12786;
v_12787:
    goto v_12788;
v_12789:
    v_12906 = acons(v_12908, v_12907, v_12906);
    env = stack[-6];
    v_12906 = ncons(v_12906);
    env = stack[-6];
    stack[-1] = v_12906;
    stack[-2] = v_12906;
v_12764:
    v_12906 = stack[-5];
    v_12906 = qcdr(v_12906);
    stack[-5] = v_12906;
    v_12906 = stack[-5];
    if (v_12906 == nil) goto v_12799;
    else goto v_12800;
v_12799:
    v_12906 = stack[-2];
    goto v_12763;
v_12800:
    goto v_12808;
v_12804:
    stack[0] = stack[-1];
    goto v_12805;
v_12806:
    v_12906 = stack[-5];
    v_12906 = qcar(v_12906);
    goto v_12821;
v_12815:
    v_12908 = stack[-3];
    goto v_12816;
v_12817:
    v_12907 = stack[-4];
    v_12907 = qcar(v_12907);
    goto v_12818;
v_12819:
    goto v_12820;
v_12821:
    goto v_12815;
v_12816:
    goto v_12817;
v_12818:
    goto v_12819;
v_12820:
    v_12906 = acons(v_12908, v_12907, v_12906);
    env = stack[-6];
    v_12906 = ncons(v_12906);
    env = stack[-6];
    goto v_12807;
v_12808:
    goto v_12804;
v_12805:
    goto v_12806;
v_12807:
    v_12906 = Lrplacd(nil, stack[0], v_12906);
    env = stack[-6];
    v_12906 = stack[-1];
    v_12906 = qcdr(v_12906);
    stack[-1] = v_12906;
    goto v_12764;
v_12763:
    goto v_12754;
v_12756:
    v_12906 = stack[-5];
    if (!symbolp(v_12906)) v_12906 = nil;
    else { v_12906 = qfastgets(v_12906);
           if (v_12906 != nil) { v_12906 = elt(v_12906, 6); // optional
#ifdef RECORD_GET
             if (v_12906 == SPID_NOPROP)
                record_get(elt(fastget_names, 6), 0),
                v_12906 = nil;
             else record_get(elt(fastget_names, 6), 1),
                v_12906 = lisp_true; }
           else record_get(elt(fastget_names, 6), 0); }
#else
             if (v_12906 == SPID_NOPROP) v_12906 = nil; else v_12906 = lisp_true; }}
#endif
    if (v_12906 == nil) goto v_12829;
    goto v_12843;
v_12839:
    v_12907 = v_12908;
    goto v_12840;
v_12841:
    v_12906 = stack[-3];
    goto v_12842;
v_12843:
    goto v_12839;
v_12840:
    goto v_12841;
v_12842:
    fn = elt(env, 1); // mchk
    v_12906 = (*qfn2(fn))(fn, v_12907, v_12906);
    env = stack[-6];
    stack[-3] = v_12906;
    v_12906 = stack[-3];
    if (v_12906 == nil) goto v_12848;
    else goto v_12849;
v_12848:
    v_12906 = nil;
    goto v_12836;
v_12849:
    v_12906 = stack[-3];
    v_12906 = qcar(v_12906);
    goto v_12863;
v_12857:
    v_12908 = stack[-5];
    goto v_12858;
v_12859:
    v_12907 = stack[-4];
    v_12907 = qcdr(v_12907);
    v_12907 = qcar(v_12907);
    goto v_12860;
v_12861:
    goto v_12862;
v_12863:
    goto v_12857;
v_12858:
    goto v_12859;
v_12860:
    goto v_12861;
v_12862:
    v_12906 = acons(v_12908, v_12907, v_12906);
    env = stack[-6];
    v_12906 = ncons(v_12906);
    env = stack[-6];
    stack[-1] = v_12906;
    stack[-2] = v_12906;
v_12837:
    v_12906 = stack[-3];
    v_12906 = qcdr(v_12906);
    stack[-3] = v_12906;
    v_12906 = stack[-3];
    if (v_12906 == nil) goto v_12873;
    else goto v_12874;
v_12873:
    v_12906 = stack[-2];
    goto v_12836;
v_12874:
    goto v_12882;
v_12878:
    stack[0] = stack[-1];
    goto v_12879;
v_12880:
    v_12906 = stack[-3];
    v_12906 = qcar(v_12906);
    goto v_12895;
v_12889:
    v_12908 = stack[-5];
    goto v_12890;
v_12891:
    v_12907 = stack[-4];
    v_12907 = qcdr(v_12907);
    v_12907 = qcar(v_12907);
    goto v_12892;
v_12893:
    goto v_12894;
v_12895:
    goto v_12889;
v_12890:
    goto v_12891;
v_12892:
    goto v_12893;
v_12894:
    v_12906 = acons(v_12908, v_12907, v_12906);
    env = stack[-6];
    v_12906 = ncons(v_12906);
    env = stack[-6];
    goto v_12881;
v_12882:
    goto v_12878;
v_12879:
    goto v_12880;
v_12881:
    v_12906 = Lrplacd(nil, stack[0], v_12906);
    env = stack[-6];
    v_12906 = stack[-1];
    v_12906 = qcdr(v_12906);
    stack[-1] = v_12906;
    goto v_12837;
v_12836:
    goto v_12754;
v_12829:
    v_12906 = nil;
    goto v_12754;
    v_12906 = nil;
v_12754:
v_12727:
    return onevalue(v_12906);
}



// Code for ps!:evaluate

static LispObject CC_psTevaluate(LispObject env,
                         LispObject v_12720, LispObject v_12721)
{
    env = qenv(env);
    LispObject v_12776, v_12777;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12721,v_12720);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12720,v_12721);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_12721;
    v_12776 = v_12720;
// end of prologue
// Binding ps
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = v_12776; // ps
    goto v_12735;
v_12731:
    v_12777 = qvalue(elt(env, 1)); // ps
    goto v_12732;
v_12733:
    v_12776 = stack[-2];
    goto v_12734;
v_12735:
    goto v_12731;
v_12732:
    goto v_12733;
v_12734:
    fn = elt(env, 2); // ps!:get!-term
    v_12776 = (*qfn2(fn))(fn, v_12777, v_12776);
    env = stack[-4];
    stack[-1] = v_12776;
    v_12776 = stack[-1];
    if (v_12776 == nil) goto v_12741;
    v_12776 = stack[-1];
    goto v_12729;
v_12741:
    v_12776 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 3); // ps!:last!-term
    v_12776 = (*qfn1(fn))(fn, v_12776);
    env = stack[-4];
    v_12776 = add1(v_12776);
    env = stack[-4];
    stack[0] = v_12776;
v_12747:
    goto v_12761;
v_12757:
    v_12777 = stack[-2];
    goto v_12758;
v_12759:
    v_12776 = stack[0];
    goto v_12760;
v_12761:
    goto v_12757;
v_12758:
    goto v_12759;
v_12760:
    v_12776 = difference2(v_12777, v_12776);
    env = stack[-4];
    v_12776 = Lminusp(nil, v_12776);
    env = stack[-4];
    if (v_12776 == nil) goto v_12754;
    goto v_12746;
v_12754:
    goto v_12770;
v_12766:
    v_12777 = qvalue(elt(env, 1)); // ps
    goto v_12767;
v_12768:
    v_12776 = stack[0];
    goto v_12769;
v_12770:
    goto v_12766;
v_12767:
    goto v_12768;
v_12769:
    fn = elt(env, 4); // ps!:evaluate!-next
    v_12776 = (*qfn2(fn))(fn, v_12777, v_12776);
    env = stack[-4];
    stack[-1] = v_12776;
    v_12776 = stack[0];
    v_12776 = add1(v_12776);
    env = stack[-4];
    stack[0] = v_12776;
    goto v_12747;
v_12746:
    v_12776 = stack[-1];
v_12729:
    ;}  // end of a binding scope
    return onevalue(v_12776);
}



// Code for reform!-minus

static LispObject CC_reformKminus(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12831, v_12832, v_12833;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12720;
    stack[-1] = v_12719;
// end of prologue
    v_12831 = stack[0];
    if (v_12831 == nil) goto v_12728;
    else goto v_12729;
v_12728:
    v_12831 = lisp_true;
    goto v_12727;
v_12729:
    v_12831 = stack[-1];
    v_12831 = (v_12831 == nil ? lisp_true : nil);
    goto v_12727;
    v_12831 = nil;
v_12727:
    if (v_12831 == nil) goto v_12725;
    v_12831 = stack[-1];
    goto v_12723;
v_12725:
    v_12831 = stack[-1];
    v_12831 = qcar(v_12831);
    goto v_12747;
v_12743:
    goto v_12761;
v_12757:
    v_12832 = stack[0];
    v_12833 = qcar(v_12832);
    goto v_12758;
v_12759:
    v_12832 = elt(env, 1); // minus
    goto v_12760;
v_12761:
    goto v_12757;
v_12758:
    goto v_12759;
v_12760:
    if (!consp(v_12833)) goto v_12755;
    v_12833 = qcar(v_12833);
    if (v_12833 == v_12832) goto v_12754;
    else goto v_12755;
v_12754:
    goto v_12774;
v_12770:
    v_12833 = v_12831;
    goto v_12771;
v_12772:
    v_12832 = elt(env, 2); // quotient
    goto v_12773;
v_12774:
    goto v_12770;
v_12771:
    goto v_12772;
v_12773:
    if (!consp(v_12833)) goto v_12768;
    v_12833 = qcar(v_12833);
    if (v_12833 == v_12832) goto v_12767;
    else goto v_12768;
v_12767:
    goto v_12782;
v_12778:
    v_12832 = v_12831;
    v_12832 = qcdr(v_12832);
    v_12833 = qcar(v_12832);
    goto v_12779;
v_12780:
    v_12832 = elt(env, 1); // minus
    goto v_12781;
v_12782:
    goto v_12778;
v_12779:
    goto v_12780;
v_12781:
    v_12832 = Leqcar(nil, v_12833, v_12832);
    env = stack[-3];
    goto v_12766;
v_12768:
    v_12832 = nil;
    goto v_12766;
    v_12832 = nil;
v_12766:
    goto v_12753;
v_12755:
    v_12832 = nil;
    goto v_12753;
    v_12832 = nil;
v_12753:
    if (v_12832 == nil) goto v_12751;
    goto v_12798;
v_12794:
    stack[-2] = elt(env, 1); // minus
    goto v_12795;
v_12796:
    goto v_12807;
v_12801:
    v_12833 = elt(env, 2); // quotient
    goto v_12802;
v_12803:
    v_12832 = v_12831;
    v_12832 = qcdr(v_12832);
    v_12832 = qcar(v_12832);
    v_12832 = qcdr(v_12832);
    v_12832 = qcar(v_12832);
    goto v_12804;
v_12805:
    v_12831 = qcdr(v_12831);
    v_12831 = qcdr(v_12831);
    v_12831 = qcar(v_12831);
    goto v_12806;
v_12807:
    goto v_12801;
v_12802:
    goto v_12803;
v_12804:
    goto v_12805;
v_12806:
    v_12831 = list3(v_12833, v_12832, v_12831);
    env = stack[-3];
    goto v_12797;
v_12798:
    goto v_12794;
v_12795:
    goto v_12796;
v_12797:
    v_12831 = list2(stack[-2], v_12831);
    env = stack[-3];
    stack[-2] = v_12831;
    goto v_12749;
v_12751:
    stack[-2] = v_12831;
    goto v_12749;
    stack[-2] = nil;
v_12749:
    goto v_12744;
v_12745:
    goto v_12826;
v_12822:
    v_12831 = stack[-1];
    v_12832 = qcdr(v_12831);
    goto v_12823;
v_12824:
    v_12831 = stack[0];
    v_12831 = qcdr(v_12831);
    goto v_12825;
v_12826:
    goto v_12822;
v_12823:
    goto v_12824;
v_12825:
    v_12831 = CC_reformKminus(elt(env, 0), v_12832, v_12831);
    goto v_12746;
v_12747:
    goto v_12743;
v_12744:
    goto v_12745;
v_12746:
    {
        LispObject v_12837 = stack[-2];
        return cons(v_12837, v_12831);
    }
    v_12831 = nil;
v_12723:
    return onevalue(v_12831);
}



// Code for setmat

static LispObject CC_setmat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12778, v_12779, v_12780;
    LispObject fn;
    LispObject v_12722, v_12721, v_12720, v_12719;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "setmat");
    va_start(aa, nargs);
    v_12719 = va_arg(aa, LispObject);
    v_12720 = va_arg(aa, LispObject);
    v_12721 = va_arg(aa, LispObject);
    v_12722 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_12722,v_12721,v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_12719,v_12720,v_12721,v_12722);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_12722;
    stack[-1] = v_12721;
    stack[-2] = v_12720;
    stack[-3] = v_12719;
// end of prologue
    v_12778 = qvalue(elt(env, 1)); // !*modular
    if (v_12778 == nil) goto v_12727;
    v_12778 = elt(env, 2); // modular
    v_12778 = ncons(v_12778);
    env = stack[-4];
    fn = elt(env, 5); // off
    v_12778 = (*qfn1(fn))(fn, v_12778);
    env = stack[-4];
    v_12778 = elt(env, 3); // mod_was_on
    v_12778 = ncons(v_12778);
    env = stack[-4];
    fn = elt(env, 6); // on
    v_12778 = (*qfn1(fn))(fn, v_12778);
    env = stack[-4];
    goto v_12725;
v_12727:
v_12725:
    v_12778 = stack[-2];
    fn = elt(env, 7); // reval
    v_12778 = (*qfn1(fn))(fn, v_12778);
    env = stack[-4];
    stack[-2] = v_12778;
    v_12778 = stack[-1];
    fn = elt(env, 7); // reval
    v_12778 = (*qfn1(fn))(fn, v_12778);
    env = stack[-4];
    stack[-1] = v_12778;
    v_12778 = stack[0];
    fn = elt(env, 7); // reval
    v_12778 = (*qfn1(fn))(fn, v_12778);
    env = stack[-4];
    fn = elt(env, 8); // simp
    v_12778 = (*qfn1(fn))(fn, v_12778);
    env = stack[-4];
    fn = elt(env, 9); // mk!*sq
    v_12778 = (*qfn1(fn))(fn, v_12778);
    env = stack[-4];
    stack[0] = v_12778;
    goto v_12751;
v_12745:
    goto v_12759;
v_12753:
    v_12780 = stack[-3];
    goto v_12754;
v_12755:
    v_12779 = stack[-2];
    goto v_12756;
v_12757:
    v_12778 = stack[-1];
    goto v_12758;
v_12759:
    goto v_12753;
v_12754:
    goto v_12755;
v_12756:
    goto v_12757;
v_12758:
    v_12780 = list3(v_12780, v_12779, v_12778);
    env = stack[-4];
    goto v_12746;
v_12747:
    v_12779 = stack[0];
    goto v_12748;
v_12749:
    v_12778 = stack[-3];
    goto v_12750;
v_12751:
    goto v_12745;
v_12746:
    goto v_12747;
v_12748:
    goto v_12749;
v_12750:
    fn = elt(env, 10); // letmtr
    v_12778 = (*qfnn(fn))(fn, 3, v_12780, v_12779, v_12778);
    env = stack[-4];
    v_12778 = qvalue(elt(env, 4)); // !*mod_was_on
    if (v_12778 == nil) goto v_12768;
    v_12778 = elt(env, 2); // modular
    v_12778 = ncons(v_12778);
    env = stack[-4];
    fn = elt(env, 6); // on
    v_12778 = (*qfn1(fn))(fn, v_12778);
    env = stack[-4];
    v_12778 = elt(env, 3); // mod_was_on
    v_12778 = ncons(v_12778);
    env = stack[-4];
    fn = elt(env, 5); // off
    v_12778 = (*qfn1(fn))(fn, v_12778);
    goto v_12766;
v_12768:
v_12766:
    v_12778 = stack[-3];
    return onevalue(v_12778);
}



// Code for freeoffl

static LispObject CC_freeoffl(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12755, v_12756;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12720;
    stack[-1] = v_12719;
// end of prologue
v_12718:
    v_12755 = stack[0];
    if (v_12755 == nil) goto v_12724;
    else goto v_12725;
v_12724:
    v_12755 = lisp_true;
    goto v_12723;
v_12725:
    goto v_12739;
v_12735:
    v_12756 = stack[-1];
    goto v_12736;
v_12737:
    v_12755 = stack[0];
    v_12755 = qcar(v_12755);
    goto v_12738;
v_12739:
    goto v_12735;
v_12736:
    goto v_12737;
v_12738:
    fn = elt(env, 1); // freeoff
    v_12755 = (*qfn2(fn))(fn, v_12756, v_12755);
    env = stack[-2];
    if (v_12755 == nil) goto v_12732;
    else goto v_12733;
v_12732:
    v_12755 = nil;
    goto v_12731;
v_12733:
    goto v_12751;
v_12747:
    v_12756 = stack[-1];
    goto v_12748;
v_12749:
    v_12755 = stack[0];
    v_12755 = qcdr(v_12755);
    goto v_12750;
v_12751:
    goto v_12747;
v_12748:
    goto v_12749;
v_12750:
    stack[-1] = v_12756;
    stack[0] = v_12755;
    goto v_12718;
    v_12755 = nil;
v_12731:
    goto v_12723;
    v_12755 = nil;
v_12723:
    return onevalue(v_12755);
}



// Code for fortexp

static LispObject CC_fortexp(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12729, v_12730;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12729 = v_12719;
// end of prologue
    goto v_12726;
v_12722:
    v_12730 = v_12729;
    goto v_12723;
v_12724:
    v_12729 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12725;
v_12726:
    goto v_12722;
v_12723:
    goto v_12724;
v_12725:
    {
        fn = elt(env, 1); // fortexp1
        return (*qfn2(fn))(fn, v_12730, v_12729);
    }
}



// Code for indordp

static LispObject CC_indordp(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12779, v_12780, v_12781, v_12782, v_12783;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12781 = v_12720;
    v_12782 = v_12719;
// end of prologue
    v_12779 = qvalue(elt(env, 1)); // indxl!*
    v_12783 = v_12779;
    goto v_12735;
v_12731:
    v_12780 = v_12782;
    goto v_12732;
v_12733:
    v_12779 = v_12783;
    goto v_12734;
v_12735:
    goto v_12731;
v_12732:
    goto v_12733;
v_12734:
    v_12779 = Lmemq(nil, v_12780, v_12779);
    if (v_12779 == nil) goto v_12729;
    else goto v_12730;
v_12729:
    v_12779 = lisp_true;
    goto v_12724;
v_12730:
v_12725:
    v_12779 = v_12783;
    if (v_12779 == nil) goto v_12742;
    else goto v_12743;
v_12742:
    goto v_12750;
v_12746:
    v_12779 = v_12782;
    goto v_12747;
v_12748:
    v_12780 = v_12781;
    goto v_12749;
v_12750:
    goto v_12746;
v_12747:
    goto v_12748;
v_12749:
        return Lorderp(nil, v_12779, v_12780);
v_12743:
    goto v_12761;
v_12757:
    v_12780 = v_12782;
    goto v_12758;
v_12759:
    v_12779 = v_12783;
    v_12779 = qcar(v_12779);
    goto v_12760;
v_12761:
    goto v_12757;
v_12758:
    goto v_12759;
v_12760:
    if (v_12780 == v_12779) goto v_12755;
    else goto v_12756;
v_12755:
    v_12779 = lisp_true;
    goto v_12724;
v_12756:
    goto v_12772;
v_12768:
    v_12780 = v_12781;
    goto v_12769;
v_12770:
    v_12779 = v_12783;
    v_12779 = qcar(v_12779);
    goto v_12771;
v_12772:
    goto v_12768;
v_12769:
    goto v_12770;
v_12771:
    if (v_12780 == v_12779) goto v_12766;
    else goto v_12767;
v_12766:
    v_12779 = nil;
    goto v_12724;
v_12767:
    v_12779 = v_12783;
    v_12779 = qcdr(v_12779);
    v_12783 = v_12779;
    goto v_12725;
v_12724:
    return onevalue(v_12779);
}



// Code for lpriw

static LispObject CC_lpriw(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12783, v_12784;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_12784 = v_12720;
    stack[0] = v_12719;
// end of prologue
    goto v_12729;
v_12725:
    goto v_12726;
v_12727:
    v_12783 = v_12784;
    if (v_12783 == nil) goto v_12734;
    v_12783 = v_12784;
    if (!consp(v_12783)) goto v_12737;
    else goto v_12734;
v_12737:
    v_12783 = v_12784;
    v_12783 = ncons(v_12783);
    env = stack[-1];
    goto v_12732;
v_12734:
    v_12783 = v_12784;
    goto v_12732;
    v_12783 = nil;
v_12732:
    goto v_12728;
v_12729:
    goto v_12725;
v_12726:
    goto v_12727;
v_12728:
    v_12783 = cons(stack[0], v_12783);
    env = stack[-1];
    stack[0] = v_12783;
    v_12783 = qvalue(elt(env, 1)); // ofl!*
    if (v_12783 == nil) goto v_12746;
    else goto v_12747;
v_12746:
    v_12783 = Lterpri(nil, 0);
    env = stack[-1];
    v_12783 = stack[0];
    fn = elt(env, 5); // lpri
    v_12783 = (*qfn1(fn))(fn, v_12783);
    env = stack[-1];
    v_12783 = Lterpri(nil, 0);
    goto v_12745;
v_12747:
    v_12783 = qvalue(elt(env, 2)); // !*fort
    if (v_12783 == nil) goto v_12759;
    else goto v_12758;
v_12759:
    v_12783 = qvalue(elt(env, 3)); // !*nat
    if (v_12783 == nil) goto v_12764;
    else goto v_12765;
v_12764:
    v_12783 = lisp_true;
    goto v_12763;
v_12765:
    v_12783 = qvalue(elt(env, 4)); // !*defn
    goto v_12763;
    v_12783 = nil;
v_12763:
    if (v_12783 == nil) goto v_12761;
    else goto v_12758;
v_12761:
    v_12783 = Lterpri(nil, 0);
    env = stack[-1];
    v_12783 = stack[0];
    fn = elt(env, 5); // lpri
    v_12783 = (*qfn1(fn))(fn, v_12783);
    env = stack[-1];
    v_12783 = Lterpri(nil, 0);
    env = stack[-1];
    goto v_12756;
v_12758:
v_12756:
    v_12783 = nil;
    v_12783 = Lwrs(nil, v_12783);
    env = stack[-1];
    v_12783 = stack[0];
    fn = elt(env, 5); // lpri
    v_12783 = (*qfn1(fn))(fn, v_12783);
    env = stack[-1];
    v_12783 = Lterpri(nil, 0);
    env = stack[-1];
    v_12783 = qvalue(elt(env, 1)); // ofl!*
    v_12783 = qcdr(v_12783);
    v_12783 = Lwrs(nil, v_12783);
    goto v_12745;
v_12745:
    v_12783 = nil;
    return onevalue(v_12783);
}



// Code for mv!-domainlist!-!+

static LispObject CC_mvKdomainlistKL(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12756, v_12757;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12720;
    stack[-1] = v_12719;
// end of prologue
    stack[-2] = nil;
v_12725:
    v_12756 = stack[-1];
    if (v_12756 == nil) goto v_12728;
    else goto v_12729;
v_12728:
    v_12756 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12756);
    }
v_12729:
    goto v_12740;
v_12736:
    goto v_12746;
v_12742:
    v_12756 = stack[-1];
    v_12757 = qcar(v_12756);
    goto v_12743;
v_12744:
    v_12756 = stack[0];
    v_12756 = qcar(v_12756);
    goto v_12745;
v_12746:
    goto v_12742;
v_12743:
    goto v_12744;
v_12745:
    v_12757 = plus2(v_12757, v_12756);
    env = stack[-3];
    goto v_12737;
v_12738:
    v_12756 = stack[-2];
    goto v_12739;
v_12740:
    goto v_12736;
v_12737:
    goto v_12738;
v_12739:
    v_12756 = cons(v_12757, v_12756);
    env = stack[-3];
    stack[-2] = v_12756;
    v_12756 = stack[-1];
    v_12756 = qcdr(v_12756);
    stack[-1] = v_12756;
    v_12756 = stack[0];
    v_12756 = qcdr(v_12756);
    stack[0] = v_12756;
    goto v_12725;
    v_12756 = nil;
    return onevalue(v_12756);
}



// Code for mo_lcm

static LispObject CC_mo_lcm(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12800, v_12801;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_12801 = v_12720;
    v_12800 = v_12719;
// end of prologue
    stack[-2] = nil;
    v_12800 = qcar(v_12800);
    stack[-1] = v_12800;
    v_12800 = v_12801;
    v_12800 = qcar(v_12800);
    stack[0] = v_12800;
v_12733:
    v_12800 = stack[-1];
    if (v_12800 == nil) goto v_12736;
    v_12800 = stack[0];
    if (v_12800 == nil) goto v_12736;
    goto v_12737;
v_12736:
    goto v_12732;
v_12737:
    goto v_12748;
v_12744:
    goto v_12757;
v_12753:
    v_12800 = stack[-1];
    v_12801 = qcar(v_12800);
    goto v_12754;
v_12755:
    v_12800 = stack[0];
    v_12800 = qcar(v_12800);
    goto v_12756;
v_12757:
    goto v_12753;
v_12754:
    goto v_12755;
v_12756:
    if (((intptr_t)(v_12801)) > ((intptr_t)(v_12800))) goto v_12751;
    else goto v_12752;
v_12751:
    v_12800 = stack[-1];
    v_12800 = qcar(v_12800);
    v_12801 = v_12800;
    goto v_12750;
v_12752:
    v_12800 = stack[0];
    v_12800 = qcar(v_12800);
    v_12801 = v_12800;
    goto v_12750;
    v_12801 = nil;
v_12750:
    goto v_12745;
v_12746:
    v_12800 = stack[-2];
    goto v_12747;
v_12748:
    goto v_12744;
v_12745:
    goto v_12746;
v_12747:
    v_12800 = cons(v_12801, v_12800);
    env = stack[-3];
    stack[-2] = v_12800;
    v_12800 = stack[-1];
    v_12800 = qcdr(v_12800);
    stack[-1] = v_12800;
    v_12800 = stack[0];
    v_12800 = qcdr(v_12800);
    stack[0] = v_12800;
    goto v_12733;
v_12732:
    goto v_12778;
v_12774:
    v_12800 = stack[-2];
    v_12801 = Lnreverse(nil, v_12800);
    env = stack[-3];
    goto v_12775;
v_12776:
    v_12800 = stack[-1];
    if (v_12800 == nil) goto v_12784;
    v_12800 = stack[-1];
    goto v_12782;
v_12784:
    v_12800 = stack[0];
    goto v_12782;
    v_12800 = nil;
v_12782:
    goto v_12777;
v_12778:
    goto v_12774;
v_12775:
    goto v_12776;
v_12777:
    v_12800 = Lappend(nil, v_12801, v_12800);
    env = stack[-3];
    stack[-2] = v_12800;
    goto v_12795;
v_12791:
    v_12800 = stack[-2];
    fn = elt(env, 1); // mo!=shorten
    stack[0] = (*qfn1(fn))(fn, v_12800);
    env = stack[-3];
    goto v_12792;
v_12793:
    v_12800 = stack[-2];
    fn = elt(env, 2); // mo!=deglist
    v_12800 = (*qfn1(fn))(fn, v_12800);
    goto v_12794;
v_12795:
    goto v_12791;
v_12792:
    goto v_12793;
v_12794:
    {
        LispObject v_12805 = stack[0];
        return cons(v_12805, v_12800);
    }
    return onevalue(v_12800);
}



// Code for arglist_member

static LispObject CC_arglist_member(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12751, v_12752;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12720;
    stack[-1] = v_12719;
// end of prologue
v_12718:
    v_12751 = stack[0];
    if (!consp(v_12751)) goto v_12725;
    goto v_12735;
v_12731:
    v_12752 = stack[-1];
    goto v_12732;
v_12733:
    v_12751 = stack[0];
    v_12751 = qcar(v_12751);
    goto v_12734;
v_12735:
    goto v_12731;
v_12732:
    goto v_12733;
v_12734:
    fn = elt(env, 1); // mvar_member
    v_12751 = (*qfn2(fn))(fn, v_12752, v_12751);
    env = stack[-2];
    if (v_12751 == nil) goto v_12729;
    else goto v_12728;
v_12729:
    goto v_12744;
v_12740:
    v_12752 = stack[-1];
    goto v_12741;
v_12742:
    v_12751 = stack[0];
    v_12751 = qcdr(v_12751);
    goto v_12743;
v_12744:
    goto v_12740;
v_12741:
    goto v_12742;
v_12743:
    stack[-1] = v_12752;
    stack[0] = v_12751;
    goto v_12718;
v_12728:
    goto v_12723;
v_12725:
    v_12751 = nil;
    goto v_12723;
    v_12751 = nil;
v_12723:
    return onevalue(v_12751);
}



// Code for drop_rl_with

static LispObject CC_drop_rl_with(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12747, v_12748, v_12749;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_12747 = v_12720;
    v_12748 = v_12719;
// end of prologue
    goto v_12729;
v_12723:
    stack[-1] = v_12747;
    goto v_12724;
v_12725:
    stack[0] = elt(env, 1); // rl_with
    goto v_12726;
v_12727:
    goto v_12737;
v_12733:
    v_12749 = v_12748;
    goto v_12734;
v_12735:
    goto v_12744;
v_12740:
    v_12748 = v_12747;
    goto v_12741;
v_12742:
    v_12747 = elt(env, 1); // rl_with
    goto v_12743;
v_12744:
    goto v_12740;
v_12741:
    goto v_12742;
v_12743:
    v_12747 = get(v_12748, v_12747);
    env = stack[-2];
    goto v_12736;
v_12737:
    goto v_12733;
v_12734:
    goto v_12735;
v_12736:
    v_12747 = Ldelete(nil, v_12749, v_12747);
    goto v_12728;
v_12729:
    goto v_12723;
v_12724:
    goto v_12725;
v_12726:
    goto v_12727;
v_12728:
    {
        LispObject v_12752 = stack[-1];
        LispObject v_12753 = stack[0];
        return Lputprop(nil, 3, v_12752, v_12753, v_12747);
    }
}



// Code for remlocs

static LispObject CC_remlocs(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12817, v_12818;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12719);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_12818 = v_12719;
// end of prologue
    v_12817 = qvalue(elt(env, 1)); // !*globals
    if (v_12817 == nil) goto v_12727;
    v_12817 = v_12818;
    stack[-2] = v_12817;
v_12732:
    v_12817 = stack[-2];
    if (v_12817 == nil) goto v_12736;
    else goto v_12737;
v_12736:
    goto v_12731;
v_12737:
    v_12817 = stack[-2];
    v_12817 = qcar(v_12817);
    stack[-1] = v_12817;
    goto v_12747;
v_12743:
    v_12818 = stack[-1];
    goto v_12744;
v_12745:
    v_12817 = qvalue(elt(env, 2)); // locls!*
    goto v_12746;
v_12747:
    goto v_12743;
v_12744:
    goto v_12745;
v_12746:
    v_12817 = Lassoc(nil, v_12818, v_12817);
    stack[-3] = v_12817;
    v_12817 = stack[-3];
    if (v_12817 == nil) goto v_12753;
    else goto v_12754;
v_12753:
    v_12817 = elt(env, 3); // begin
    fn = elt(env, 5); // getd
    v_12817 = (*qfn1(fn))(fn, v_12817);
    env = stack[-4];
    if (v_12817 == nil) goto v_12759;
    goto v_12768;
v_12764:
    v_12818 = elt(env, 4); // " Lvar confused"
    goto v_12765;
v_12766:
    v_12817 = stack[-1];
    goto v_12767;
v_12768:
    goto v_12764;
v_12765:
    goto v_12766;
v_12767:
    v_12817 = list2(v_12818, v_12817);
    env = stack[-4];
    fn = elt(env, 6); // rederr
    v_12817 = (*qfn1(fn))(fn, v_12817);
    env = stack[-4];
    goto v_12757;
v_12759:
    goto v_12778;
v_12774:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12775;
v_12776:
    goto v_12785;
v_12781:
    v_12818 = elt(env, 4); // " Lvar confused"
    goto v_12782;
v_12783:
    v_12817 = stack[-1];
    goto v_12784;
v_12785:
    goto v_12781;
v_12782:
    goto v_12783;
v_12784:
    v_12817 = list2(v_12818, v_12817);
    env = stack[-4];
    goto v_12777;
v_12778:
    goto v_12774;
v_12775:
    goto v_12776;
v_12777:
    fn = elt(env, 7); // error
    v_12817 = (*qfn2(fn))(fn, stack[0], v_12817);
    env = stack[-4];
    goto v_12757;
v_12757:
    goto v_12752;
v_12754:
v_12752:
    v_12817 = stack[-3];
    v_12817 = qcdr(v_12817);
    v_12817 = qcdr(v_12817);
    if (v_12817 == nil) goto v_12791;
    goto v_12800;
v_12796:
    v_12818 = stack[-3];
    goto v_12797;
v_12798:
    v_12817 = stack[-3];
    v_12817 = qcdr(v_12817);
    v_12817 = qcdr(v_12817);
    goto v_12799;
v_12800:
    goto v_12796;
v_12797:
    goto v_12798;
v_12799:
    v_12817 = Lrplacd(nil, v_12818, v_12817);
    env = stack[-4];
    goto v_12789;
v_12791:
    goto v_12812;
v_12808:
    v_12818 = stack[-3];
    goto v_12809;
v_12810:
    v_12817 = qvalue(elt(env, 2)); // locls!*
    goto v_12811;
v_12812:
    goto v_12808;
v_12809:
    goto v_12810;
v_12811:
    fn = elt(env, 8); // efface1
    v_12817 = (*qfn2(fn))(fn, v_12818, v_12817);
    env = stack[-4];
    qvalue(elt(env, 2)) = v_12817; // locls!*
    goto v_12789;
v_12789:
    v_12817 = stack[-2];
    v_12817 = qcdr(v_12817);
    stack[-2] = v_12817;
    goto v_12732;
v_12731:
    goto v_12725;
v_12727:
v_12725:
    v_12817 = nil;
    return onevalue(v_12817);
}



// Code for setqget

static LispObject CC_setqget(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12747, v_12748;
    argcheck(nargs, 0, "setqget");
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
    v_12747 = qvalue(elt(env, 1)); // fluidbibasissetq
    v_12747 = qcar(v_12747);
    stack[-1] = v_12747;
    v_12747 = qvalue(elt(env, 1)); // fluidbibasissetq
    stack[0] = v_12747;
    goto v_12732;
v_12728:
    goto v_12738;
v_12734:
    v_12748 = stack[0];
    goto v_12735;
v_12736:
    v_12747 = stack[0];
    v_12747 = qcdr(v_12747);
    v_12747 = qcar(v_12747);
    goto v_12737;
v_12738:
    goto v_12734;
v_12735:
    goto v_12736;
v_12737:
    v_12748 = Lrplaca(nil, v_12748, v_12747);
    env = stack[-2];
    goto v_12729;
v_12730:
    v_12747 = stack[0];
    v_12747 = qcdr(v_12747);
    v_12747 = qcdr(v_12747);
    goto v_12731;
v_12732:
    goto v_12728;
v_12729:
    goto v_12730;
v_12731:
    v_12747 = Lrplacd(nil, v_12748, v_12747);
    v_12747 = stack[-1];
    return onevalue(v_12747);
}



// Code for ofsf_surep

static LispObject CC_ofsf_surep(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12740, v_12741, v_12742;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12740 = v_12720;
    v_12741 = v_12719;
// end of prologue
    goto v_12726;
v_12722:
    goto v_12734;
v_12728:
    v_12742 = v_12741;
    goto v_12729;
v_12730:
    v_12741 = v_12740;
    goto v_12731;
v_12732:
    v_12740 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_12733;
v_12734:
    goto v_12728;
v_12729:
    goto v_12730;
v_12731:
    goto v_12732;
v_12733:
    fn = elt(env, 2); // cl_simpl
    v_12740 = (*qfnn(fn))(fn, 3, v_12742, v_12741, v_12740);
    env = stack[0];
    goto v_12723;
v_12724:
    v_12741 = elt(env, 1); // true
    goto v_12725;
v_12726:
    goto v_12722;
v_12723:
    goto v_12724;
v_12725:
    v_12740 = (v_12740 == v_12741 ? lisp_true : nil);
    return onevalue(v_12740);
}



// Code for ibalp_negatet

static LispObject CC_ibalp_negatet(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12753, v_12754, v_12755;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12755 = v_12719;
// end of prologue
    goto v_12729;
v_12725:
    v_12754 = v_12755;
    goto v_12726;
v_12727:
    v_12753 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12728;
v_12729:
    goto v_12725;
v_12726:
    goto v_12727;
v_12728:
    if (v_12754 == v_12753) goto v_12723;
    else goto v_12724;
v_12723:
    v_12753 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12722;
v_12724:
    goto v_12739;
v_12735:
    v_12754 = v_12755;
    goto v_12736;
v_12737:
    v_12753 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12738;
v_12739:
    goto v_12735;
v_12736:
    goto v_12737;
v_12738:
    if (v_12754 == v_12753) goto v_12733;
    else goto v_12734;
v_12733:
    v_12753 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12722;
v_12734:
    goto v_12750;
v_12746:
    v_12753 = elt(env, 1); // bnot
    goto v_12747;
v_12748:
    v_12754 = v_12755;
    goto v_12749;
v_12750:
    goto v_12746;
v_12747:
    goto v_12748;
v_12749:
    return list2(v_12753, v_12754);
    v_12753 = nil;
v_12722:
    return onevalue(v_12753);
}



// Code for reln

static LispObject CC_reln(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12748, v_12749;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12720;
    stack[-1] = v_12719;
// end of prologue
    v_12748 = elt(env, 1); // "<apply>"
    fn = elt(env, 5); // printout
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-2];
    v_12748 = elt(env, 2); // "<"
    v_12748 = Lprinc(nil, v_12748);
    env = stack[-2];
    v_12748 = stack[0];
    v_12748 = Lprinc(nil, v_12748);
    env = stack[-2];
    goto v_12735;
v_12731:
    v_12748 = stack[-1];
    v_12749 = qcar(v_12748);
    goto v_12732;
v_12733:
    v_12748 = elt(env, 3); // "/"
    goto v_12734;
v_12735:
    goto v_12731;
v_12732:
    goto v_12733;
v_12734:
    fn = elt(env, 6); // attributesml
    v_12748 = (*qfn2(fn))(fn, v_12749, v_12748);
    env = stack[-2];
    v_12748 = lisp_true;
    fn = elt(env, 7); // indent!*
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-2];
    v_12748 = stack[-1];
    v_12748 = qcdr(v_12748);
    fn = elt(env, 8); // multi_elem
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-2];
    v_12748 = nil;
    fn = elt(env, 7); // indent!*
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-2];
    v_12748 = elt(env, 4); // "</apply>"
    fn = elt(env, 5); // printout
    v_12748 = (*qfn1(fn))(fn, v_12748);
    v_12748 = nil;
    return onevalue(v_12748);
}



// Code for diffsq

static LispObject CC_diffsq(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12769, v_12770;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_12720;
    stack[-2] = v_12719;
// end of prologue
    goto v_12727;
v_12723:
    goto v_12733;
v_12729:
    goto v_12739;
v_12735:
    v_12769 = stack[-2];
    v_12770 = qcar(v_12769);
    goto v_12736;
v_12737:
    v_12769 = stack[-1];
    goto v_12738;
v_12739:
    goto v_12735;
v_12736:
    goto v_12737;
v_12738:
    fn = elt(env, 1); // difff
    stack[-3] = (*qfn2(fn))(fn, v_12770, v_12769);
    env = stack[-4];
    goto v_12730;
v_12731:
    goto v_12749;
v_12745:
    stack[0] = stack[-2];
    goto v_12746;
v_12747:
    goto v_12756;
v_12752:
    v_12769 = stack[-2];
    v_12770 = qcdr(v_12769);
    goto v_12753;
v_12754:
    v_12769 = stack[-1];
    goto v_12755;
v_12756:
    goto v_12752;
v_12753:
    goto v_12754;
v_12755:
    fn = elt(env, 1); // difff
    v_12769 = (*qfn2(fn))(fn, v_12770, v_12769);
    env = stack[-4];
    goto v_12748;
v_12749:
    goto v_12745;
v_12746:
    goto v_12747;
v_12748:
    fn = elt(env, 2); // multsq
    v_12769 = (*qfn2(fn))(fn, stack[0], v_12769);
    env = stack[-4];
    fn = elt(env, 3); // negsq
    v_12769 = (*qfn1(fn))(fn, v_12769);
    env = stack[-4];
    goto v_12732;
v_12733:
    goto v_12729;
v_12730:
    goto v_12731;
v_12732:
    fn = elt(env, 4); // addsq
    stack[0] = (*qfn2(fn))(fn, stack[-3], v_12769);
    env = stack[-4];
    goto v_12724;
v_12725:
    goto v_12765;
v_12761:
    v_12770 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12762;
v_12763:
    v_12769 = stack[-2];
    v_12769 = qcdr(v_12769);
    goto v_12764;
v_12765:
    goto v_12761;
v_12762:
    goto v_12763;
v_12764:
    v_12769 = cons(v_12770, v_12769);
    env = stack[-4];
    goto v_12726;
v_12727:
    goto v_12723;
v_12724:
    goto v_12725;
v_12726:
    {
        LispObject v_12775 = stack[0];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_12775, v_12769);
    }
}



// Code for xdegreecheck

static LispObject CC_xdegreecheck(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12738, v_12739;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12719);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12739 = v_12719;
// end of prologue
    v_12738 = qvalue(elt(env, 1)); // xtruncate!*
    if (v_12738 == nil) goto v_12723;
    else goto v_12724;
v_12723:
    v_12738 = nil;
    goto v_12722;
v_12724:
    goto v_12734;
v_12730:
    v_12738 = v_12739;
    fn = elt(env, 2); // xdegree
    v_12738 = (*qfn1(fn))(fn, v_12738);
    env = stack[0];
    goto v_12731;
v_12732:
    v_12739 = qvalue(elt(env, 1)); // xtruncate!*
    goto v_12733;
v_12734:
    goto v_12730;
v_12731:
    goto v_12732;
v_12733:
        return Lgreaterp(nil, v_12738, v_12739);
    v_12738 = nil;
v_12722:
    return onevalue(v_12738);
}



// Code for physopsm!*

static LispObject CC_physopsmH(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12986, v_12987, v_12988, v_12989;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12719);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_12719;
// end of prologue
    stack[0] = nil;
    v_12986 = stack[-3];
    if (v_12986 == nil) goto v_12734;
    else goto v_12735;
v_12734:
    v_12986 = lisp_true;
    goto v_12733;
v_12735:
    v_12986 = stack[-3];
    v_12986 = (is_number(v_12986) ? lisp_true : nil);
    goto v_12733;
    v_12986 = nil;
v_12733:
    if (v_12986 == nil) goto v_12731;
    v_12986 = stack[-3];
    stack[0] = v_12986;
    goto v_12729;
v_12731:
    v_12986 = stack[-3];
    fn = elt(env, 11); // physopp
    v_12986 = (*qfn1(fn))(fn, v_12986);
    env = stack[-5];
    if (v_12986 == nil) goto v_12744;
    v_12986 = stack[-3];
    if (!symbolp(v_12986)) v_12986 = nil;
    else { v_12986 = qfastgets(v_12986);
           if (v_12986 != nil) { v_12986 = elt(v_12986, 46); // rvalue
#ifdef RECORD_GET
             if (v_12986 != SPID_NOPROP)
                record_get(elt(fastget_names, 46), 1);
             else record_get(elt(fastget_names, 46), 0),
                v_12986 = nil; }
           else record_get(elt(fastget_names, 46), 0); }
#else
             if (v_12986 == SPID_NOPROP) v_12986 = nil; }}
#endif
    stack[-1] = v_12986;
    if (v_12986 == nil) goto v_12750;
    v_12986 = stack[-1];
    fn = elt(env, 12); // physopaeval
    v_12986 = (*qfn1(fn))(fn, v_12986);
    goto v_12748;
v_12750:
    v_12986 = stack[-3];
    if (symbolp(v_12986)) goto v_12755;
    else goto v_12756;
v_12755:
    v_12986 = stack[-3];
    goto v_12748;
v_12756:
    goto v_12766;
v_12762:
    v_12986 = stack[-3];
    v_12987 = qcar(v_12986);
    goto v_12763;
v_12764:
    v_12986 = elt(env, 1); // psimpfn
    goto v_12765;
v_12766:
    goto v_12762;
v_12763:
    goto v_12764;
v_12765:
    v_12986 = get(v_12987, v_12986);
    env = stack[-5];
    stack[-1] = v_12986;
    if (v_12986 == nil) goto v_12760;
    goto v_12775;
v_12771:
    v_12987 = stack[-1];
    goto v_12772;
v_12773:
    v_12986 = stack[-3];
    goto v_12774;
v_12775:
    goto v_12771;
v_12772:
    goto v_12773;
v_12774:
    v_12986 = Lapply1(nil, v_12987, v_12986);
    goto v_12748;
v_12760:
    v_12986 = stack[-3];
    v_12986 = qcar(v_12986);
    if (!symbolp(v_12986)) v_12986 = nil;
    else { v_12986 = qfastgets(v_12986);
           if (v_12986 != nil) { v_12986 = elt(v_12986, 9); // opmtch
#ifdef RECORD_GET
             if (v_12986 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_12986 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_12986 == SPID_NOPROP) v_12986 = nil; }}
#endif
    if (v_12986 == nil) goto v_12779;
    v_12986 = stack[-3];
    fn = elt(env, 13); // opmtch!*
    v_12986 = (*qfn1(fn))(fn, v_12986);
    stack[-1] = v_12986;
    if (v_12986 == nil) goto v_12779;
    v_12986 = stack[-1];
    goto v_12748;
v_12779:
    v_12986 = stack[-3];
    goto v_12748;
    v_12986 = nil;
v_12748:
    stack[0] = v_12986;
    goto v_12729;
v_12744:
    v_12986 = stack[-3];
    if (!consp(v_12986)) goto v_12791;
    else goto v_12792;
v_12791:
    v_12986 = stack[-3];
    fn = elt(env, 14); // aeval
    v_12986 = (*qfn1(fn))(fn, v_12986);
    stack[0] = v_12986;
    goto v_12729;
v_12792:
    v_12986 = stack[-3];
    v_12986 = qcar(v_12986);
    stack[-4] = v_12986;
    v_12986 = stack[-3];
    v_12986 = qcdr(v_12986);
    stack[-2] = v_12986;
    goto v_12811;
v_12807:
    v_12987 = stack[-4];
    goto v_12808;
v_12809:
    v_12986 = elt(env, 2); // physopfunction
    goto v_12810;
v_12811:
    goto v_12807;
v_12808:
    goto v_12809;
v_12810:
    v_12986 = get(v_12987, v_12986);
    env = stack[-5];
    stack[-1] = v_12986;
    if (v_12986 == nil) goto v_12805;
    goto v_12823;
v_12819:
    v_12987 = stack[-4];
    goto v_12820;
v_12821:
    v_12986 = elt(env, 3); // physoparith
    goto v_12822;
v_12823:
    goto v_12819;
v_12820:
    goto v_12821;
v_12822:
    v_12986 = Lflagp(nil, v_12987, v_12986);
    env = stack[-5];
    if (v_12986 == nil) goto v_12817;
    v_12986 = stack[-2];
    fn = elt(env, 15); // hasonephysop
    v_12986 = (*qfn1(fn))(fn, v_12986);
    env = stack[-5];
    if (v_12986 == nil) goto v_12829;
    goto v_12837;
v_12833:
    stack[0] = stack[-1];
    goto v_12834;
v_12835:
    v_12986 = stack[-2];
    v_12986 = ncons(v_12986);
    env = stack[-5];
    goto v_12836;
v_12837:
    goto v_12833;
v_12834:
    goto v_12835;
v_12836:
    fn = elt(env, 16); // apply
    v_12986 = (*qfn2(fn))(fn, stack[0], v_12986);
    stack[0] = v_12986;
    goto v_12827;
v_12829:
    goto v_12849;
v_12845:
    v_12987 = stack[-4];
    goto v_12846;
v_12847:
    v_12986 = stack[-2];
    goto v_12848;
v_12849:
    goto v_12845;
v_12846:
    goto v_12847;
v_12848:
    v_12986 = cons(v_12987, v_12986);
    env = stack[-5];
    fn = elt(env, 17); // reval3
    v_12986 = (*qfn1(fn))(fn, v_12986);
    stack[0] = v_12986;
    goto v_12827;
v_12827:
    goto v_12815;
v_12817:
    goto v_12859;
v_12855:
    v_12987 = stack[-4];
    goto v_12856;
v_12857:
    v_12986 = elt(env, 4); // physopfn
    goto v_12858;
v_12859:
    goto v_12855;
v_12856:
    goto v_12857;
v_12858:
    v_12986 = Lflagp(nil, v_12987, v_12986);
    env = stack[-5];
    if (v_12986 == nil) goto v_12853;
    v_12986 = stack[-2];
    fn = elt(env, 18); // areallphysops
    v_12986 = (*qfn1(fn))(fn, v_12986);
    env = stack[-5];
    if (v_12986 == nil) goto v_12865;
    goto v_12873;
v_12869:
    stack[0] = stack[-1];
    goto v_12870;
v_12871:
    v_12986 = stack[-2];
    v_12986 = ncons(v_12986);
    env = stack[-5];
    goto v_12872;
v_12873:
    goto v_12869;
v_12870:
    goto v_12871;
v_12872:
    fn = elt(env, 16); // apply
    v_12986 = (*qfn2(fn))(fn, stack[0], v_12986);
    stack[0] = v_12986;
    goto v_12863;
v_12865:
    goto v_12884;
v_12880:
    stack[-1] = elt(env, 0); // physopsm!*
    goto v_12881;
v_12882:
    goto v_12895;
v_12887:
    v_12989 = elt(env, 5); // "invalid call of "
    goto v_12888;
v_12889:
    v_12988 = stack[-4];
    goto v_12890;
v_12891:
    v_12987 = elt(env, 6); // " with args: "
    goto v_12892;
v_12893:
    v_12986 = stack[-2];
    goto v_12894;
v_12895:
    goto v_12887;
v_12888:
    goto v_12889;
v_12890:
    goto v_12891;
v_12892:
    goto v_12893;
v_12894:
    v_12986 = list4(v_12989, v_12988, v_12987, v_12986);
    env = stack[-5];
    goto v_12883;
v_12884:
    goto v_12880;
v_12881:
    goto v_12882;
v_12883:
    fn = elt(env, 19); // rederr2
    v_12986 = (*qfn2(fn))(fn, stack[-1], v_12986);
    goto v_12863;
v_12863:
    goto v_12815;
v_12853:
    goto v_12907;
v_12903:
    stack[-1] = elt(env, 0); // physopsm!*
    goto v_12904;
v_12905:
    goto v_12916;
v_12910:
    v_12988 = stack[-4];
    goto v_12911;
v_12912:
    v_12987 = elt(env, 7); // " has been flagged Physopfunction"
    goto v_12913;
v_12914:
    v_12986 = elt(env, 8); // " but is not defined"
    goto v_12915;
v_12916:
    goto v_12910;
v_12911:
    goto v_12912;
v_12913:
    goto v_12914;
v_12915:
    v_12986 = list3(v_12988, v_12987, v_12986);
    env = stack[-5];
    goto v_12906;
v_12907:
    goto v_12903;
v_12904:
    goto v_12905;
v_12906:
    fn = elt(env, 19); // rederr2
    v_12986 = (*qfn2(fn))(fn, stack[-1], v_12986);
    goto v_12815;
v_12815:
    goto v_12803;
v_12805:
    goto v_12931;
v_12927:
    v_12987 = stack[-4];
    goto v_12928;
v_12929:
    v_12986 = elt(env, 9); // physopmapping
    goto v_12930;
v_12931:
    goto v_12927;
v_12928:
    goto v_12929;
v_12930:
    v_12986 = Lflagp(nil, v_12987, v_12986);
    env = stack[-5];
    if (v_12986 == nil) goto v_12925;
    v_12986 = stack[-2];
    fn = elt(env, 20); // !*physopp!*
    v_12986 = (*qfn1(fn))(fn, v_12986);
    env = stack[-5];
    goto v_12923;
v_12925:
    v_12986 = nil;
    goto v_12923;
    v_12986 = nil;
v_12923:
    if (v_12986 == nil) goto v_12921;
    goto v_12945;
v_12941:
    goto v_12952;
v_12948:
    goto v_12958;
v_12954:
    goto v_12964;
v_12960:
    v_12987 = stack[-4];
    goto v_12961;
v_12962:
    v_12986 = stack[-2];
    goto v_12963;
v_12964:
    goto v_12960;
v_12961:
    goto v_12962;
v_12963:
    v_12987 = cons(v_12987, v_12986);
    env = stack[-5];
    goto v_12955;
v_12956:
    v_12986 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12957;
v_12958:
    goto v_12954;
v_12955:
    goto v_12956;
v_12957:
    fn = elt(env, 21); // to
    v_12987 = (*qfn2(fn))(fn, v_12987, v_12986);
    env = stack[-5];
    goto v_12949;
v_12950:
    v_12986 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12951;
v_12952:
    goto v_12948;
v_12949:
    goto v_12950;
v_12951:
    v_12986 = cons(v_12987, v_12986);
    env = stack[-5];
    v_12987 = ncons(v_12986);
    env = stack[-5];
    goto v_12942;
v_12943:
    v_12986 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12944;
v_12945:
    goto v_12941;
v_12942:
    goto v_12943;
v_12944:
    v_12986 = cons(v_12987, v_12986);
    env = stack[-5];
    fn = elt(env, 22); // mk!*sq
    v_12986 = (*qfn1(fn))(fn, v_12986);
    stack[0] = v_12986;
    goto v_12803;
v_12921:
    goto v_12976;
v_12972:
    v_12987 = stack[-4];
    goto v_12973;
v_12974:
    v_12986 = elt(env, 10); // prog
    goto v_12975;
v_12976:
    goto v_12972;
v_12973:
    goto v_12974;
v_12975:
    if (v_12987 == v_12986) goto v_12970;
    else goto v_12971;
v_12970:
    v_12986 = stack[-2];
    fn = elt(env, 23); // physopprog
    v_12986 = (*qfn1(fn))(fn, v_12986);
    stack[0] = v_12986;
    goto v_12803;
v_12971:
    v_12986 = stack[-3];
    fn = elt(env, 14); // aeval
    v_12986 = (*qfn1(fn))(fn, v_12986);
    stack[0] = v_12986;
    goto v_12803;
v_12803:
    goto v_12729;
v_12729:
    v_12986 = stack[0];
    return onevalue(v_12986);
}



// Code for prepd1

static LispObject CC_prepd1(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12745, v_12746, v_12747;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12719);
    }
// copy arguments values to proper place
    v_12747 = v_12719;
// end of prologue
    v_12745 = v_12747;
    if (!consp(v_12745)) goto v_12723;
    else goto v_12724;
v_12723:
    v_12745 = v_12747;
    goto v_12722;
v_12724:
    goto v_12734;
v_12730:
    goto v_12740;
v_12736:
    v_12745 = v_12747;
    v_12746 = qcar(v_12745);
    goto v_12737;
v_12738:
    v_12745 = elt(env, 1); // prepfn
    goto v_12739;
v_12740:
    goto v_12736;
v_12737:
    goto v_12738;
v_12739:
    v_12745 = get(v_12746, v_12745);
    goto v_12731;
v_12732:
    v_12746 = v_12747;
    goto v_12733;
v_12734:
    goto v_12730;
v_12731:
    goto v_12732;
v_12733:
        return Lapply1(nil, v_12745, v_12746);
    v_12745 = nil;
v_12722:
    return onevalue(v_12745);
}



// Code for ad_numsort

static LispObject CC_ad_numsort(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12729, v_12730;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12729 = v_12719;
// end of prologue
    goto v_12726;
v_12722:
    v_12730 = v_12729;
    goto v_12723;
v_12724:
    v_12729 = elt(env, 1); // lambda_ygm6np4pcqv31
    goto v_12725;
v_12726:
    goto v_12722;
v_12723:
    goto v_12724;
v_12725:
    {
        fn = elt(env, 2); // sort
        return (*qfn2(fn))(fn, v_12730, v_12729);
    }
}



// Code for lambda_ygm6np4pcqv31

static LispObject CC_lambda_ygm6np4pcqv31(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12730, v_12731;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12730 = v_12720;
    v_12731 = v_12719;
// end of prologue
    goto v_12727;
v_12723:
    goto v_12724;
v_12725:
    goto v_12726;
v_12727:
    goto v_12723;
v_12724:
    goto v_12725;
v_12726:
        return Lleq(nil, v_12731, v_12730);
}



// Code for rlis

static LispObject CC_rlis(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12770, v_12771;
    LispObject fn;
    argcheck(nargs, 0, "rlis");
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
    v_12770 = qvalue(elt(env, 1)); // cursym!*
    stack[0] = v_12770;
    fn = elt(env, 5); // scan
    v_12770 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (!symbolp(v_12770)) v_12770 = nil;
    else { v_12770 = qfastgets(v_12770);
           if (v_12770 != nil) { v_12770 = elt(v_12770, 55); // delim
#ifdef RECORD_GET
             if (v_12770 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v_12770 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v_12770 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v_12770 == SPID_NOPROP) v_12770 = nil; else v_12770 = lisp_true; }}
#endif
    if (v_12770 == nil) goto v_12727;
    goto v_12735;
v_12731:
    v_12771 = stack[0];
    goto v_12732;
v_12733:
    v_12770 = nil;
    goto v_12734;
v_12735:
    goto v_12731;
v_12732:
    goto v_12733;
v_12734:
    return list2(v_12771, v_12770);
v_12727:
    v_12770 = qvalue(elt(env, 2)); // !*reduce4
    if (v_12770 == nil) goto v_12739;
    goto v_12746;
v_12742:
    stack[-1] = stack[0];
    goto v_12743;
v_12744:
    goto v_12753;
v_12749:
    stack[0] = elt(env, 3); // list
    goto v_12750;
v_12751:
    v_12770 = elt(env, 4); // lambda
    fn = elt(env, 6); // xread1
    v_12770 = (*qfn1(fn))(fn, v_12770);
    env = stack[-2];
    fn = elt(env, 7); // remcomma
    v_12770 = (*qfn1(fn))(fn, v_12770);
    env = stack[-2];
    goto v_12752;
v_12753:
    goto v_12749;
v_12750:
    goto v_12751;
v_12752:
    v_12770 = cons(stack[0], v_12770);
    goto v_12745;
v_12746:
    goto v_12742;
v_12743:
    goto v_12744;
v_12745:
    {
        LispObject v_12774 = stack[-1];
        return list2(v_12774, v_12770);
    }
v_12739:
    goto v_12765;
v_12761:
    goto v_12762;
v_12763:
    v_12770 = elt(env, 4); // lambda
    fn = elt(env, 6); // xread1
    v_12770 = (*qfn1(fn))(fn, v_12770);
    env = stack[-2];
    fn = elt(env, 7); // remcomma
    v_12770 = (*qfn1(fn))(fn, v_12770);
    goto v_12764;
v_12765:
    goto v_12761;
v_12762:
    goto v_12763;
v_12764:
    {
        LispObject v_12775 = stack[0];
        return cons(v_12775, v_12770);
    }
    v_12770 = nil;
    return onevalue(v_12770);
}



// Code for ibalp_isinminclause

static LispObject CC_ibalp_isinminclause(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12852, v_12853;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_12720;
    stack[-2] = v_12719;
// end of prologue
    stack[0] = nil;
    v_12852 = stack[-2];
    v_12852 = qcdr(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcar(v_12852);
    stack[-3] = v_12852;
v_12732:
    v_12852 = stack[-3];
    if (v_12852 == nil) goto v_12735;
    v_12852 = stack[0];
    if (v_12852 == nil) goto v_12739;
    else goto v_12735;
v_12739:
    goto v_12736;
v_12735:
    goto v_12731;
v_12736:
    v_12852 = stack[-3];
    v_12852 = qcar(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcar(v_12852);
    if (v_12852 == nil) goto v_12748;
    else goto v_12749;
v_12748:
    goto v_12762;
v_12758:
    goto v_12768;
v_12764:
    v_12852 = stack[-3];
    v_12852 = qcar(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcdr(v_12852);
    v_12853 = qcar(v_12852);
    goto v_12765;
v_12766:
    v_12852 = stack[-3];
    v_12852 = qcar(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcar(v_12852);
    goto v_12767;
v_12768:
    goto v_12764;
v_12765:
    goto v_12766;
v_12767:
    v_12853 = plus2(v_12853, v_12852);
    env = stack[-4];
    goto v_12759;
v_12760:
    v_12852 = stack[-1];
    goto v_12761;
v_12762:
    goto v_12758;
v_12759:
    goto v_12760;
v_12761:
    v_12852 = Leqn(nil, v_12853, v_12852);
    env = stack[-4];
    goto v_12747;
v_12749:
    v_12852 = nil;
    goto v_12747;
    v_12852 = nil;
v_12747:
    if (v_12852 == nil) goto v_12745;
    v_12852 = lisp_true;
    stack[0] = v_12852;
    goto v_12743;
v_12745:
v_12743:
    v_12852 = stack[-3];
    v_12852 = qcdr(v_12852);
    stack[-3] = v_12852;
    goto v_12732;
v_12731:
    v_12852 = stack[-2];
    v_12852 = qcdr(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcar(v_12852);
    stack[-3] = v_12852;
v_12795:
    v_12852 = stack[-3];
    if (v_12852 == nil) goto v_12798;
    v_12852 = stack[0];
    if (v_12852 == nil) goto v_12802;
    else goto v_12798;
v_12802:
    goto v_12799;
v_12798:
    goto v_12794;
v_12799:
    v_12852 = stack[-3];
    v_12852 = qcar(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcar(v_12852);
    if (v_12852 == nil) goto v_12811;
    else goto v_12812;
v_12811:
    goto v_12825;
v_12821:
    goto v_12831;
v_12827:
    v_12852 = stack[-3];
    v_12852 = qcar(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcdr(v_12852);
    v_12853 = qcar(v_12852);
    goto v_12828;
v_12829:
    v_12852 = stack[-3];
    v_12852 = qcar(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcdr(v_12852);
    v_12852 = qcar(v_12852);
    goto v_12830;
v_12831:
    goto v_12827;
v_12828:
    goto v_12829;
v_12830:
    v_12853 = plus2(v_12853, v_12852);
    env = stack[-4];
    goto v_12822;
v_12823:
    v_12852 = stack[-1];
    goto v_12824;
v_12825:
    goto v_12821;
v_12822:
    goto v_12823;
v_12824:
    v_12852 = Leqn(nil, v_12853, v_12852);
    env = stack[-4];
    goto v_12810;
v_12812:
    v_12852 = nil;
    goto v_12810;
    v_12852 = nil;
v_12810:
    if (v_12852 == nil) goto v_12808;
    v_12852 = lisp_true;
    stack[0] = v_12852;
    goto v_12806;
v_12808:
v_12806:
    v_12852 = stack[-3];
    v_12852 = qcdr(v_12852);
    stack[-3] = v_12852;
    goto v_12795;
v_12794:
    v_12852 = stack[0];
    return onevalue(v_12852);
}



// Code for !*!*a2s

static LispObject CC_HHa2s(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12805, v_12806;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_12805 = v_12720;
    stack[-3] = v_12719;
// end of prologue
    v_12805 = stack[-3];
    if (v_12805 == nil) goto v_12724;
    else goto v_12725;
v_12724:
    v_12805 = elt(env, 1); // "tell Hearn!!"
    {
        fn = elt(env, 10); // rederr
        return (*qfn1(fn))(fn, v_12805);
    }
v_12725:
    goto v_12737;
v_12733:
    v_12806 = stack[-3];
    goto v_12734;
v_12735:
    v_12805 = elt(env, 2); // nochange
    goto v_12736;
v_12737:
    goto v_12733;
v_12734:
    goto v_12735;
v_12736:
    v_12805 = Lflagpcar(nil, v_12806, v_12805);
    env = stack[-5];
    if (v_12805 == nil) goto v_12730;
    goto v_12745;
v_12741:
    v_12805 = stack[-3];
    v_12806 = qcar(v_12805);
    goto v_12742;
v_12743:
    v_12805 = elt(env, 3); // getel
    goto v_12744;
v_12745:
    goto v_12741;
v_12742:
    goto v_12743;
v_12744:
    if (v_12806 == v_12805) goto v_12730;
    v_12805 = stack[-3];
    goto v_12723;
v_12730:
    goto v_12757;
v_12753:
    v_12806 = elt(env, 4); // random
    goto v_12754;
v_12755:
    v_12805 = stack[-3];
    goto v_12756;
v_12757:
    goto v_12753;
v_12754:
    goto v_12755;
v_12756:
    fn = elt(env, 11); // smember
    v_12805 = (*qfn2(fn))(fn, v_12806, v_12805);
    env = stack[-5];
    if (v_12805 == nil) goto v_12751;
    goto v_12765;
v_12761:
    goto v_12773;
v_12767:
    stack[-4] = elt(env, 5); // lambda
    goto v_12768;
v_12769:
    stack[-2] = elt(env, 6); // (!*uncached)
    goto v_12770;
v_12771:
    goto v_12783;
v_12777:
    stack[-1] = elt(env, 7); // progn
    goto v_12778;
v_12779:
    stack[0] = elt(env, 8); // (declare (special !*uncached))
    goto v_12780;
v_12781:
    goto v_12791;
v_12787:
    v_12806 = qvalue(elt(env, 9)); // !*!*a2sfn
    goto v_12788;
v_12789:
    v_12805 = stack[-3];
    goto v_12790;
v_12791:
    goto v_12787;
v_12788:
    goto v_12789;
v_12790:
    v_12805 = list2(v_12806, v_12805);
    env = stack[-5];
    goto v_12782;
v_12783:
    goto v_12777;
v_12778:
    goto v_12779;
v_12780:
    goto v_12781;
v_12782:
    v_12805 = list3(stack[-1], stack[0], v_12805);
    env = stack[-5];
    goto v_12772;
v_12773:
    goto v_12767;
v_12768:
    goto v_12769;
v_12770:
    goto v_12771;
v_12772:
    v_12806 = list3(stack[-4], stack[-2], v_12805);
    goto v_12762;
v_12763:
    v_12805 = lisp_true;
    goto v_12764;
v_12765:
    goto v_12761;
v_12762:
    goto v_12763;
v_12764:
    return list2(v_12806, v_12805);
v_12751:
    goto v_12802;
v_12798:
    v_12806 = qvalue(elt(env, 9)); // !*!*a2sfn
    goto v_12799;
v_12800:
    v_12805 = stack[-3];
    goto v_12801;
v_12802:
    goto v_12798;
v_12799:
    goto v_12800;
v_12801:
    return list2(v_12806, v_12805);
    v_12805 = nil;
v_12723:
    return onevalue(v_12805);
}



// Code for ps!:prepfn!:

static LispObject CC_psTprepfnT(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12722;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12722 = v_12719;
// end of prologue
    return onevalue(v_12722);
}



// Code for dm!-minus

static LispObject CC_dmKminus(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12733, v_12734;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12719);
    }
// copy arguments values to proper place
    v_12733 = v_12719;
// end of prologue
    fn = elt(env, 1); // !:minus
    v_12733 = (*qfn1(fn))(fn, v_12733);
    v_12734 = v_12733;
    v_12733 = v_12734;
    if (v_12733 == nil) goto v_12726;
    else goto v_12727;
v_12726:
    v_12733 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12725;
v_12727:
    v_12733 = v_12734;
    goto v_12725;
    v_12733 = nil;
v_12725:
    return onevalue(v_12733);
}



// Code for groebcplistsortin1

static LispObject CC_groebcplistsortin1(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12780, v_12781;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12720;
    stack[-1] = v_12719;
// end of prologue
v_12724:
    goto v_12734;
v_12730:
    v_12780 = stack[0];
    v_12781 = qcar(v_12780);
    goto v_12731;
v_12732:
    v_12780 = stack[-1];
    goto v_12733;
v_12734:
    goto v_12730;
v_12731:
    goto v_12732;
v_12733:
    fn = elt(env, 1); // groebcpcompless!?
    v_12780 = (*qfn2(fn))(fn, v_12781, v_12780);
    env = stack[-3];
    if (v_12780 == nil) goto v_12727;
    else goto v_12728;
v_12727:
    goto v_12743;
v_12739:
    stack[-2] = stack[0];
    goto v_12740;
v_12741:
    goto v_12750;
v_12746:
    v_12780 = stack[0];
    v_12781 = qcar(v_12780);
    goto v_12747;
v_12748:
    v_12780 = stack[0];
    v_12780 = qcdr(v_12780);
    goto v_12749;
v_12750:
    goto v_12746;
v_12747:
    goto v_12748;
v_12749:
    v_12780 = cons(v_12781, v_12780);
    env = stack[-3];
    goto v_12742;
v_12743:
    goto v_12739;
v_12740:
    goto v_12741;
v_12742:
    v_12780 = Lrplacd(nil, stack[-2], v_12780);
    goto v_12760;
v_12756:
    v_12781 = stack[0];
    goto v_12757;
v_12758:
    v_12780 = stack[-1];
    goto v_12759;
v_12760:
    goto v_12756;
v_12757:
    goto v_12758;
v_12759:
        return Lrplaca(nil, v_12781, v_12780);
v_12728:
    v_12780 = stack[0];
    v_12780 = qcdr(v_12780);
    if (v_12780 == nil) goto v_12763;
    else goto v_12764;
v_12763:
    goto v_12772;
v_12768:
    goto v_12769;
v_12770:
    v_12780 = stack[-1];
    v_12780 = ncons(v_12780);
    goto v_12771;
v_12772:
    goto v_12768;
v_12769:
    goto v_12770;
v_12771:
    {
        LispObject v_12785 = stack[0];
        return Lrplacd(nil, v_12785, v_12780);
    }
v_12764:
    v_12780 = stack[0];
    v_12780 = qcdr(v_12780);
    stack[0] = v_12780;
    goto v_12724;
    v_12780 = nil;
    return onevalue(v_12780);
}



// Code for bytelist2id

static LispObject CC_bytelist2id(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12724;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12719);
    }
// copy arguments values to proper place
    v_12724 = v_12719;
// end of prologue
    fn = elt(env, 1); // list2string
    v_12724 = (*qfn1(fn))(fn, v_12724);
        return Lintern(nil, v_12724);
}



// Code for gfdot

static LispObject CC_gfdot(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12746, v_12747, v_12748;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12747 = v_12720;
    v_12748 = v_12719;
// end of prologue
    v_12746 = v_12748;
    v_12746 = qcar(v_12746);
    if (!consp(v_12746)) goto v_12724;
    else goto v_12725;
v_12724:
    goto v_12733;
v_12729:
    v_12746 = v_12748;
    goto v_12730;
v_12731:
    goto v_12732;
v_12733:
    goto v_12729;
v_12730:
    goto v_12731;
v_12732:
    {
        fn = elt(env, 1); // gffdot
        return (*qfn2(fn))(fn, v_12746, v_12747);
    }
v_12725:
    goto v_12743;
v_12739:
    v_12746 = v_12748;
    goto v_12740;
v_12741:
    goto v_12742;
v_12743:
    goto v_12739;
v_12740:
    goto v_12741;
v_12742:
    {
        fn = elt(env, 2); // gbfdot
        return (*qfn2(fn))(fn, v_12746, v_12747);
    }
    v_12746 = nil;
    return onevalue(v_12746);
}



// Code for rdcos!*

static LispObject CC_rdcosH(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12736, v_12737;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12719);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12736 = v_12719;
// end of prologue
    fn = elt(env, 1); // convprec
    v_12736 = (*qfn1(fn))(fn, v_12736);
    env = stack[0];
    v_12737 = v_12736;
    v_12736 = v_12737;
    if (!consp(v_12736)) goto v_12727;
    else goto v_12728;
v_12727:
    v_12736 = v_12737;
    fn = elt(env, 2); // cos
    v_12736 = (*qfn1(fn))(fn, v_12736);
    env = stack[0];
    goto v_12726;
v_12728:
    v_12736 = v_12737;
    fn = elt(env, 3); // cos!*
    v_12736 = (*qfn1(fn))(fn, v_12736);
    env = stack[0];
    goto v_12726;
    v_12736 = nil;
v_12726:
    {
        fn = elt(env, 4); // mkround
        return (*qfn1(fn))(fn, v_12736);
    }
}



// Code for mkfortterpri

static LispObject CC_mkfortterpri(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12722;
    argcheck(nargs, 0, "mkfortterpri");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_12722 = elt(env, 1); // fortterpri
    return ncons(v_12722);
}



// Code for trwrite

static LispObject CC_trwrite(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12760;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12719);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_12719;
// end of prologue
    v_12760 = stack[0];
    v_12760 = qcar(v_12760);
    if (!symbolp(v_12760)) v_12760 = nil;
    else { v_12760 = qfastgets(v_12760);
           if (v_12760 != nil) { v_12760 = elt(v_12760, 53); // tracing
#ifdef RECORD_GET
             if (v_12760 == SPID_NOPROP)
                record_get(elt(fastget_names, 53), 0),
                v_12760 = nil;
             else record_get(elt(fastget_names, 53), 1),
                v_12760 = lisp_true; }
           else record_get(elt(fastget_names, 53), 0); }
#else
             if (v_12760 == SPID_NOPROP) v_12760 = nil; else v_12760 = lisp_true; }}
#endif
    if (v_12760 == nil) goto v_12726;
    else goto v_12727;
v_12726:
    v_12760 = nil;
    goto v_12723;
v_12727:
    v_12760 = elt(env, 1); // "**in procedure: "
    v_12760 = Lprinc(nil, v_12760);
    env = stack[-1];
    v_12760 = stack[0];
    v_12760 = qcar(v_12760);
    v_12760 = Lprinc(nil, v_12760);
    env = stack[-1];
    v_12760 = Lterpri(nil, 0);
    env = stack[-1];
    v_12760 = stack[0];
    v_12760 = qcdr(v_12760);
    stack[0] = v_12760;
v_12742:
    v_12760 = stack[0];
    if (v_12760 == nil) goto v_12747;
    else goto v_12748;
v_12747:
    goto v_12741;
v_12748:
    v_12760 = stack[0];
    v_12760 = qcar(v_12760);
    v_12760 = Lprinc(nil, v_12760);
    env = stack[-1];
    v_12760 = stack[0];
    v_12760 = qcdr(v_12760);
    stack[0] = v_12760;
    goto v_12742;
v_12741:
    v_12760 = Lterpri(nil, 0);
    v_12760 = nil;
v_12723:
    return onevalue(v_12760);
}



// Code for one!-entry!-listp

static LispObject CC_oneKentryKlistp(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12755, v_12756;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12720;
    stack[-1] = v_12719;
// end of prologue
v_12718:
    v_12755 = stack[-1];
    if (v_12755 == nil) goto v_12724;
    else goto v_12725;
v_12724:
    v_12755 = lisp_true;
    goto v_12723;
v_12725:
    goto v_12739;
v_12735:
    v_12755 = stack[-1];
    v_12756 = qcar(v_12755);
    goto v_12736;
v_12737:
    v_12755 = stack[0];
    goto v_12738;
v_12739:
    goto v_12735;
v_12736:
    goto v_12737;
v_12738:
    fn = elt(env, 1); // one!-entryp
    v_12755 = (*qfn2(fn))(fn, v_12756, v_12755);
    env = stack[-2];
    if (v_12755 == nil) goto v_12732;
    else goto v_12733;
v_12732:
    v_12755 = nil;
    goto v_12731;
v_12733:
    goto v_12751;
v_12747:
    v_12755 = stack[-1];
    v_12756 = qcdr(v_12755);
    goto v_12748;
v_12749:
    v_12755 = stack[0];
    goto v_12750;
v_12751:
    goto v_12747;
v_12748:
    goto v_12749;
v_12750:
    stack[-1] = v_12756;
    stack[0] = v_12755;
    goto v_12718;
    v_12755 = nil;
v_12731:
    goto v_12723;
    v_12755 = nil;
v_12723:
    return onevalue(v_12755);
}



// Code for fs!:times

static LispObject CC_fsTtimes(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12767, v_12768;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12720;
    stack[-1] = v_12719;
// end of prologue
    v_12767 = stack[-1];
    if (v_12767 == nil) goto v_12724;
    else goto v_12725;
v_12724:
    v_12767 = nil;
    goto v_12723;
v_12725:
    v_12767 = stack[0];
    if (v_12767 == nil) goto v_12728;
    else goto v_12729;
v_12728:
    v_12767 = nil;
    goto v_12723;
v_12729:
    goto v_12742;
v_12738:
    v_12768 = stack[-1];
    goto v_12739;
v_12740:
    v_12767 = stack[0];
    goto v_12741;
v_12742:
    goto v_12738;
v_12739:
    goto v_12740;
v_12741:
    fn = elt(env, 1); // fs!:timesterm
    v_12767 = (*qfn2(fn))(fn, v_12768, v_12767);
    env = stack[-3];
    goto v_12750;
v_12746:
    stack[-2] = v_12767;
    goto v_12747;
v_12748:
    goto v_12757;
v_12753:
    goto v_12762;
v_12758:
    v_12768 = stack[-1];
    goto v_12759;
v_12760:
    v_12767 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_12761;
v_12762:
    goto v_12758;
v_12759:
    goto v_12760;
v_12761:
    v_12768 = *(LispObject *)((char *)v_12768 + (CELL-TAG_VECTOR) + (((intptr_t)v_12767-TAG_FIXNUM)/(16/CELL)));
    goto v_12754;
v_12755:
    v_12767 = stack[0];
    goto v_12756;
v_12757:
    goto v_12753;
v_12754:
    goto v_12755;
v_12756:
    v_12767 = CC_fsTtimes(elt(env, 0), v_12768, v_12767);
    env = stack[-3];
    goto v_12749;
v_12750:
    goto v_12746;
v_12747:
    goto v_12748;
v_12749:
    {
        LispObject v_12772 = stack[-2];
        fn = elt(env, 2); // fs!:plus
        return (*qfn2(fn))(fn, v_12772, v_12767);
    }
    goto v_12723;
    v_12767 = nil;
v_12723:
    return onevalue(v_12767);
}



// Code for moid_member

static LispObject CC_moid_member(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12751, v_12752;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12720;
    stack[-1] = v_12719;
// end of prologue
v_12718:
    v_12751 = stack[0];
    if (v_12751 == nil) goto v_12724;
    else goto v_12725;
v_12724:
    v_12751 = nil;
    goto v_12723;
v_12725:
    goto v_12738;
v_12734:
    v_12751 = stack[0];
    v_12752 = qcar(v_12751);
    goto v_12735;
v_12736:
    v_12751 = stack[-1];
    goto v_12737;
v_12738:
    goto v_12734;
v_12735:
    goto v_12736;
v_12737:
    fn = elt(env, 1); // mo_vdivides!?
    v_12751 = (*qfn2(fn))(fn, v_12752, v_12751);
    env = stack[-2];
    if (v_12751 == nil) goto v_12732;
    else goto v_12731;
v_12732:
    goto v_12747;
v_12743:
    v_12752 = stack[-1];
    goto v_12744;
v_12745:
    v_12751 = stack[0];
    v_12751 = qcdr(v_12751);
    goto v_12746;
v_12747:
    goto v_12743;
v_12744:
    goto v_12745;
v_12746:
    stack[-1] = v_12752;
    stack[0] = v_12751;
    goto v_12718;
v_12731:
    goto v_12723;
    v_12751 = nil;
v_12723:
    return onevalue(v_12751);
}



// Code for splitlist!:

static LispObject CC_splitlistT(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12759, v_12760, v_12761;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12720;
    stack[-1] = v_12719;
// end of prologue
    v_12761 = nil;
v_12725:
    v_12759 = stack[-1];
    if (v_12759 == nil) goto v_12728;
    else goto v_12729;
v_12728:
    v_12759 = v_12761;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12759);
    }
v_12729:
    goto v_12740;
v_12736:
    v_12759 = stack[-1];
    v_12760 = qcar(v_12759);
    goto v_12737;
v_12738:
    v_12759 = stack[0];
    goto v_12739;
v_12740:
    goto v_12736;
v_12737:
    goto v_12738;
v_12739:
    if (!consp(v_12760)) goto v_12734;
    v_12760 = qcar(v_12760);
    if (v_12760 == v_12759) goto v_12733;
    else goto v_12734;
v_12733:
    goto v_12749;
v_12745:
    v_12759 = stack[-1];
    v_12759 = qcar(v_12759);
    goto v_12746;
v_12747:
    v_12760 = v_12761;
    goto v_12748;
v_12749:
    goto v_12745;
v_12746:
    goto v_12747;
v_12748:
    v_12759 = cons(v_12759, v_12760);
    env = stack[-2];
    v_12761 = v_12759;
    v_12759 = stack[-1];
    v_12759 = qcdr(v_12759);
    stack[-1] = v_12759;
    goto v_12725;
v_12734:
    v_12759 = stack[-1];
    v_12759 = qcdr(v_12759);
    stack[-1] = v_12759;
    goto v_12725;
    v_12759 = nil;
    return onevalue(v_12759);
}



// Code for resimpf

static LispObject CC_resimpf(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12732, v_12733;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12719);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_12733 = v_12719;
// end of prologue
    v_12732 = nil;
// Binding varstack!*
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_12732; // varstack!*
    goto v_12728;
v_12724:
    goto v_12725;
v_12726:
    v_12732 = nil;
    goto v_12727;
v_12728:
    goto v_12724;
v_12725:
    goto v_12726;
v_12727:
    fn = elt(env, 2); // subf1
    v_12732 = (*qfn2(fn))(fn, v_12733, v_12732);
    v_12732 = qcar(v_12732);
    ;}  // end of a binding scope
    return onevalue(v_12732);
}



// Code for gfk

static LispObject CC_gfk(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12797, v_12798, v_12799, v_12800, v_12801, v_12802;
    LispObject v_12721, v_12720, v_12719;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "gfk");
    va_start(aa, nargs);
    v_12719 = va_arg(aa, LispObject);
    v_12720 = va_arg(aa, LispObject);
    v_12721 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12721,v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12719,v_12720,v_12721);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_12800 = v_12721;
    v_12801 = v_12720;
    v_12797 = v_12719;
// end of prologue
v_12718:
    v_12798 = v_12800;
    if (v_12798 == nil) goto v_12727;
    else goto v_12725;
v_12727:
    v_12798 = v_12797;
    if (!consp(v_12798)) goto v_12732;
    else goto v_12733;
v_12732:
    v_12798 = lisp_true;
    goto v_12731;
v_12733:
    v_12798 = v_12797;
    v_12798 = qcar(v_12798);
    v_12798 = (consp(v_12798) ? nil : lisp_true);
    goto v_12731;
    v_12798 = nil;
v_12731:
    if (v_12798 == nil) goto v_12729;
    else goto v_12725;
v_12729:
    goto v_12726;
v_12725:
    v_12797 = v_12800;
    goto v_12724;
v_12726:
    v_12798 = v_12797;
    v_12798 = qcar(v_12798);
    v_12798 = qcar(v_12798);
    v_12798 = qcar(v_12798);
    v_12802 = v_12798;
    goto v_12756;
v_12750:
    v_12798 = v_12797;
    stack[-1] = qcdr(v_12798);
    goto v_12751;
v_12752:
    stack[0] = v_12801;
    goto v_12753;
v_12754:
    goto v_12767;
v_12761:
    v_12797 = qcar(v_12797);
    v_12799 = qcdr(v_12797);
    goto v_12762;
v_12763:
    v_12798 = v_12801;
    goto v_12764;
v_12765:
    v_12797 = v_12802;
    if (!consp(v_12797)) goto v_12779;
    goto v_12785;
v_12781:
    v_12797 = v_12802;
    v_12797 = qcar(v_12797);
    goto v_12782;
v_12783:
    goto v_12784;
v_12785:
    goto v_12781;
v_12782:
    goto v_12783;
v_12784:
    v_12797 = Lmember(nil, v_12797, v_12801);
    goto v_12777;
v_12779:
    v_12797 = nil;
    goto v_12777;
    v_12797 = nil;
v_12777:
    if (v_12797 == nil) goto v_12775;
    v_12797 = v_12802;
    goto v_12773;
v_12775:
    v_12797 = v_12800;
    goto v_12773;
    v_12797 = nil;
v_12773:
    goto v_12766;
v_12767:
    goto v_12761;
v_12762:
    goto v_12763;
v_12764:
    goto v_12765;
v_12766:
    v_12798 = CC_gfk(elt(env, 0), 3, v_12799, v_12798, v_12797);
    env = stack[-2];
    goto v_12755;
v_12756:
    goto v_12750;
v_12751:
    goto v_12752;
v_12753:
    goto v_12754;
v_12755:
    v_12797 = stack[-1];
    v_12801 = stack[0];
    v_12800 = v_12798;
    goto v_12718;
    v_12797 = nil;
v_12724:
    return onevalue(v_12797);
}



// Code for gcref_mkgraph!-tgf

static LispObject CC_gcref_mkgraphKtgf(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12773, v_12774;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12719);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12719;
// end of prologue
    v_12773 = stack[0];
    stack[-1] = v_12773;
v_12724:
    v_12773 = stack[-1];
    if (v_12773 == nil) goto v_12728;
    else goto v_12729;
v_12728:
    goto v_12723;
v_12729:
    v_12773 = stack[-1];
    v_12773 = qcar(v_12773);
    fn = elt(env, 3); // gcref_mknode!-tgf
    v_12773 = (*qfn1(fn))(fn, v_12773);
    env = stack[-2];
    v_12773 = stack[-1];
    v_12773 = qcdr(v_12773);
    stack[-1] = v_12773;
    goto v_12724;
v_12723:
    v_12773 = elt(env, 1); // "#"
    fn = elt(env, 4); // prin2t
    v_12773 = (*qfn1(fn))(fn, v_12773);
    env = stack[-2];
    v_12773 = stack[0];
    stack[-1] = v_12773;
v_12744:
    v_12773 = stack[-1];
    if (v_12773 == nil) goto v_12748;
    else goto v_12749;
v_12748:
    v_12773 = nil;
    goto v_12743;
v_12749:
    v_12773 = stack[-1];
    v_12773 = qcar(v_12773);
    goto v_12760;
v_12756:
    stack[0] = v_12773;
    goto v_12757;
v_12758:
    goto v_12768;
v_12764:
    v_12774 = v_12773;
    goto v_12765;
v_12766:
    v_12773 = elt(env, 2); // calls
    goto v_12767;
v_12768:
    goto v_12764;
v_12765:
    goto v_12766;
v_12767:
    v_12773 = get(v_12774, v_12773);
    env = stack[-2];
    fn = elt(env, 5); // gcref_select
    v_12773 = (*qfn1(fn))(fn, v_12773);
    env = stack[-2];
    goto v_12759;
v_12760:
    goto v_12756;
v_12757:
    goto v_12758;
v_12759:
    fn = elt(env, 6); // gcref_mkedges!-tgf
    v_12773 = (*qfn2(fn))(fn, stack[0], v_12773);
    env = stack[-2];
    v_12773 = stack[-1];
    v_12773 = qcdr(v_12773);
    stack[-1] = v_12773;
    goto v_12744;
v_12743:
    return onevalue(v_12773);
}



// Code for rl_atnum

static LispObject CC_rl_atnum(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12730;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12719);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_12730 = v_12719;
// end of prologue
    goto v_12726;
v_12722:
    stack[0] = qvalue(elt(env, 1)); // rl_atnum!*
    goto v_12723;
v_12724:
    v_12730 = ncons(v_12730);
    env = stack[-1];
    goto v_12725;
v_12726:
    goto v_12722;
v_12723:
    goto v_12724;
v_12725:
    {
        LispObject v_12732 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_12732, v_12730);
    }
}



// Code for ofsf_subf

static LispObject CC_ofsf_subf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12849, v_12850, v_12851;
    LispObject fn;
    LispObject v_12721, v_12720, v_12719;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_subf");
    va_start(aa, nargs);
    v_12719 = va_arg(aa, LispObject);
    v_12720 = va_arg(aa, LispObject);
    v_12721 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12721,v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12719,v_12720,v_12721);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_12721;
    stack[-1] = v_12720;
    stack[-2] = v_12719;
// end of prologue
    v_12849 = stack[-2];
    if (!consp(v_12849)) goto v_12732;
    else goto v_12733;
v_12732:
    v_12849 = lisp_true;
    goto v_12731;
v_12733:
    v_12849 = stack[-2];
    v_12849 = qcar(v_12849);
    v_12849 = (consp(v_12849) ? nil : lisp_true);
    goto v_12731;
    v_12849 = nil;
v_12731:
    if (v_12849 == nil) goto v_12729;
    goto v_12746;
v_12742:
    v_12850 = stack[-2];
    goto v_12743;
v_12744:
    v_12849 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12745;
v_12746:
    goto v_12742;
v_12743:
    goto v_12744;
v_12745:
    return cons(v_12850, v_12849);
v_12729:
    goto v_12756;
v_12750:
    v_12849 = stack[-2];
    v_12851 = qcdr(v_12849);
    goto v_12751;
v_12752:
    v_12850 = stack[-1];
    goto v_12753;
v_12754:
    v_12849 = stack[0];
    goto v_12755;
v_12756:
    goto v_12750;
v_12751:
    goto v_12752;
v_12753:
    goto v_12754;
v_12755:
    v_12849 = CC_ofsf_subf(elt(env, 0), 3, v_12851, v_12850, v_12849);
    env = stack[-4];
    stack[-3] = v_12849;
    goto v_12769;
v_12765:
    v_12849 = stack[-2];
    v_12849 = qcar(v_12849);
    v_12849 = qcar(v_12849);
    v_12850 = qcar(v_12849);
    goto v_12766;
v_12767:
    v_12849 = stack[-1];
    goto v_12768;
v_12769:
    goto v_12765;
v_12766:
    goto v_12767;
v_12768:
    if (v_12850 == v_12849) goto v_12763;
    else goto v_12764;
v_12763:
    goto v_12780;
v_12776:
    goto v_12786;
v_12782:
    goto v_12792;
v_12788:
    v_12849 = stack[-2];
    v_12849 = qcar(v_12849);
    v_12850 = qcdr(v_12849);
    goto v_12789;
v_12790:
    v_12849 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12791;
v_12792:
    goto v_12788;
v_12789:
    goto v_12790;
v_12791:
    stack[-1] = cons(v_12850, v_12849);
    env = stack[-4];
    goto v_12783;
v_12784:
    goto v_12802;
v_12798:
    v_12850 = stack[0];
    goto v_12799;
v_12800:
    v_12849 = stack[-2];
    v_12849 = qcar(v_12849);
    v_12849 = qcar(v_12849);
    v_12849 = qcdr(v_12849);
    goto v_12801;
v_12802:
    goto v_12798;
v_12799:
    goto v_12800;
v_12801:
    fn = elt(env, 1); // exptsq
    v_12849 = (*qfn2(fn))(fn, v_12850, v_12849);
    env = stack[-4];
    goto v_12785;
v_12786:
    goto v_12782;
v_12783:
    goto v_12784;
v_12785:
    fn = elt(env, 2); // multsq
    v_12850 = (*qfn2(fn))(fn, stack[-1], v_12849);
    env = stack[-4];
    goto v_12777;
v_12778:
    v_12849 = stack[-3];
    goto v_12779;
v_12780:
    goto v_12776;
v_12777:
    goto v_12778;
v_12779:
    {
        fn = elt(env, 3); // addsq
        return (*qfn2(fn))(fn, v_12850, v_12849);
    }
v_12764:
    goto v_12814;
v_12810:
    goto v_12820;
v_12816:
    goto v_12828;
v_12822:
    v_12849 = stack[-2];
    v_12849 = qcar(v_12849);
    v_12851 = qcdr(v_12849);
    goto v_12823;
v_12824:
    v_12850 = stack[-1];
    goto v_12825;
v_12826:
    v_12849 = stack[0];
    goto v_12827;
v_12828:
    goto v_12822;
v_12823:
    goto v_12824;
v_12825:
    goto v_12826;
v_12827:
    stack[0] = CC_ofsf_subf(elt(env, 0), 3, v_12851, v_12850, v_12849);
    env = stack[-4];
    goto v_12817;
v_12818:
    goto v_12839;
v_12835:
    v_12849 = stack[-2];
    v_12849 = qcar(v_12849);
    v_12849 = qcar(v_12849);
    v_12850 = qcar(v_12849);
    goto v_12836;
v_12837:
    v_12849 = stack[-2];
    v_12849 = qcar(v_12849);
    v_12849 = qcar(v_12849);
    v_12849 = qcdr(v_12849);
    goto v_12838;
v_12839:
    goto v_12835;
v_12836:
    goto v_12837;
v_12838:
    fn = elt(env, 4); // ofsf_pow2q
    v_12849 = (*qfn2(fn))(fn, v_12850, v_12849);
    env = stack[-4];
    goto v_12819;
v_12820:
    goto v_12816;
v_12817:
    goto v_12818;
v_12819:
    fn = elt(env, 2); // multsq
    v_12850 = (*qfn2(fn))(fn, stack[0], v_12849);
    env = stack[-4];
    goto v_12811;
v_12812:
    v_12849 = stack[-3];
    goto v_12813;
v_12814:
    goto v_12810;
v_12811:
    goto v_12812;
v_12813:
    {
        fn = elt(env, 3); // addsq
        return (*qfn2(fn))(fn, v_12850, v_12849);
    }
    return onevalue(v_12849);
}



// Code for simpexpt

static LispObject CC_simpexpt(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12756, v_12757, v_12758;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12719);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12719;
// end of prologue
    v_12756 = nil;
// Binding kord!*
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 1, -1);
    qvalue(elt(env, 1)) = v_12756; // kord!*
    goto v_12732;
v_12728:
    v_12756 = stack[0];
    v_12757 = qcdr(v_12756);
    goto v_12729;
v_12730:
    v_12756 = elt(env, 2); // expt
    goto v_12731;
v_12732:
    goto v_12728;
v_12729:
    goto v_12730;
v_12731:
    fn = elt(env, 4); // carx
    v_12756 = (*qfn2(fn))(fn, v_12757, v_12756);
    env = stack[-2];
    fn = elt(env, 5); // simpexpon
    v_12756 = (*qfn1(fn))(fn, v_12756);
    env = stack[-2];
    ;}  // end of a binding scope
    goto v_12741;
v_12737:
    v_12757 = v_12756;
    goto v_12738;
v_12739:
    v_12756 = elt(env, 3); // resimp
    goto v_12740;
v_12741:
    goto v_12737;
v_12738:
    goto v_12739;
v_12740:
    fn = elt(env, 6); // simpexpon1
    v_12756 = (*qfn2(fn))(fn, v_12757, v_12756);
    env = stack[-2];
    goto v_12751;
v_12745:
    v_12757 = stack[0];
    v_12758 = qcar(v_12757);
    goto v_12746;
v_12747:
    v_12757 = v_12756;
    goto v_12748;
v_12749:
    v_12756 = nil;
    goto v_12750;
v_12751:
    goto v_12745;
v_12746:
    goto v_12747;
v_12748:
    goto v_12749;
v_12750:
    {
        fn = elt(env, 7); // simpexpt1
        return (*qfnn(fn))(fn, 3, v_12758, v_12757, v_12756);
    }
    return onevalue(v_12756);
}



// Code for ibalp_var!-set

static LispObject CC_ibalp_varKset(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12854, v_12855;
    LispObject fn;
    LispObject v_12722, v_12721, v_12720, v_12719;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ibalp_var-set");
    va_start(aa, nargs);
    v_12719 = va_arg(aa, LispObject);
    v_12720 = va_arg(aa, LispObject);
    v_12721 = va_arg(aa, LispObject);
    v_12722 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_12722,v_12721,v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_12719,v_12720,v_12721,v_12722);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_12722;
    stack[-1] = v_12721;
    stack[-2] = v_12720;
    stack[-3] = v_12719;
// end of prologue
    goto v_12734;
v_12730:
    v_12854 = stack[-3];
    v_12855 = qcdr(v_12854);
    goto v_12731;
v_12732:
    v_12854 = stack[-2];
    goto v_12733;
v_12734:
    goto v_12730;
v_12731:
    goto v_12732;
v_12733:
    fn = elt(env, 1); // setcar
    v_12854 = (*qfn2(fn))(fn, v_12855, v_12854);
    env = stack[-4];
    goto v_12743;
v_12739:
    v_12854 = stack[-3];
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12855 = qcdr(v_12854);
    goto v_12740;
v_12741:
    v_12854 = stack[-1];
    goto v_12742;
v_12743:
    goto v_12739;
v_12740:
    goto v_12741;
v_12742:
    fn = elt(env, 1); // setcar
    v_12854 = (*qfn2(fn))(fn, v_12855, v_12854);
    env = stack[-4];
    goto v_12757;
v_12753:
    v_12854 = stack[-3];
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12855 = qcdr(v_12854);
    goto v_12754;
v_12755:
    v_12854 = stack[0];
    goto v_12756;
v_12757:
    goto v_12753;
v_12754:
    goto v_12755;
v_12756:
    fn = elt(env, 1); // setcar
    v_12854 = (*qfn2(fn))(fn, v_12855, v_12854);
    env = stack[-4];
    v_12854 = stack[-3];
    v_12854 = qcar(v_12854);
    stack[0] = v_12854;
    goto v_12778;
v_12774:
    v_12855 = stack[-2];
    goto v_12775;
v_12776:
    v_12854 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12777;
v_12778:
    goto v_12774;
v_12775:
    goto v_12776;
v_12777:
    v_12854 = Leqn(nil, v_12855, v_12854);
    env = stack[-4];
    if (v_12854 == nil) goto v_12772;
    v_12854 = stack[-3];
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcar(v_12854);
    goto v_12770;
v_12772:
    v_12854 = stack[-3];
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcar(v_12854);
    goto v_12770;
    v_12854 = nil;
v_12770:
    goto v_12797;
v_12793:
    v_12855 = v_12854;
    goto v_12794;
v_12795:
    v_12854 = stack[0];
    goto v_12796;
v_12797:
    goto v_12793;
v_12794:
    goto v_12795;
v_12796:
    fn = elt(env, 2); // ibalp_var!-satlist
    v_12854 = (*qfn2(fn))(fn, v_12855, v_12854);
    env = stack[-4];
    goto v_12809;
v_12805:
    v_12855 = stack[-2];
    goto v_12806;
v_12807:
    v_12854 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12808;
v_12809:
    goto v_12805;
v_12806:
    goto v_12807;
v_12808:
    v_12854 = Leqn(nil, v_12855, v_12854);
    env = stack[-4];
    if (v_12854 == nil) goto v_12803;
    v_12854 = stack[-3];
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcar(v_12854);
    goto v_12801;
v_12803:
    v_12854 = stack[-3];
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcar(v_12854);
    goto v_12801;
    v_12854 = nil;
v_12801:
    goto v_12828;
v_12824:
    v_12855 = v_12854;
    goto v_12825;
v_12826:
    v_12854 = stack[-2];
    goto v_12827;
v_12828:
    goto v_12824;
v_12825:
    goto v_12826;
v_12827:
    fn = elt(env, 3); // ibalp_var!-unsatlist
    v_12854 = (*qfn2(fn))(fn, v_12855, v_12854);
    env = stack[-4];
    v_12854 = stack[-3];
    fn = elt(env, 4); // ibalp_var!-wclist
    v_12854 = (*qfn1(fn))(fn, v_12854);
    env = stack[-4];
    stack[-1] = v_12854;
    goto v_12838;
v_12834:
    v_12854 = stack[-3];
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    v_12854 = qcdr(v_12854);
    stack[0] = qcdr(v_12854);
    goto v_12835;
v_12836:
    v_12854 = stack[-3];
    fn = elt(env, 5); // ibalp_calcmom
    v_12854 = (*qfn1(fn))(fn, v_12854);
    env = stack[-4];
    goto v_12837;
v_12838:
    goto v_12834;
v_12835:
    goto v_12836;
v_12837:
    fn = elt(env, 1); // setcar
    v_12854 = (*qfn2(fn))(fn, stack[0], v_12854);
    v_12854 = stack[-1];
    return onevalue(v_12854);
}



// Code for inttovec1

static LispObject CC_inttovec1(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12774, v_12775;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12720;
    stack[-1] = v_12719;
// end of prologue
    goto v_12730;
v_12726:
    v_12775 = stack[-1];
    goto v_12727;
v_12728:
    v_12774 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12729;
v_12730:
    goto v_12726;
v_12727:
    goto v_12728;
v_12729:
    if (v_12775 == v_12774) goto v_12724;
    else goto v_12725;
v_12724:
    v_12774 = stack[0];
    v_12774 = qcar(v_12774);
    return ncons(v_12774);
v_12725:
    goto v_12743;
v_12739:
    v_12774 = stack[-1];
    v_12775 = sub1(v_12774);
    env = stack[-3];
    goto v_12740;
v_12741:
    v_12774 = stack[0];
    v_12774 = qcdr(v_12774);
    goto v_12742;
v_12743:
    goto v_12739;
v_12740:
    goto v_12741;
v_12742:
    fn = elt(env, 1); // inttovec!-solve
    v_12774 = (*qfn2(fn))(fn, v_12775, v_12774);
    env = stack[-3];
    stack[-2] = v_12774;
    goto v_12754;
v_12750:
    goto v_12760;
v_12756:
    v_12774 = stack[0];
    v_12775 = qcar(v_12774);
    goto v_12757;
v_12758:
    v_12774 = stack[-2];
    v_12774 = qcar(v_12774);
    goto v_12759;
v_12760:
    goto v_12756;
v_12757:
    goto v_12758;
v_12759:
    stack[0] = difference2(v_12775, v_12774);
    env = stack[-3];
    goto v_12751;
v_12752:
    goto v_12770;
v_12766:
    v_12774 = stack[-1];
    v_12775 = sub1(v_12774);
    env = stack[-3];
    goto v_12767;
v_12768:
    v_12774 = stack[-2];
    goto v_12769;
v_12770:
    goto v_12766;
v_12767:
    goto v_12768;
v_12769:
    v_12774 = CC_inttovec1(elt(env, 0), v_12775, v_12774);
    goto v_12753;
v_12754:
    goto v_12750;
v_12751:
    goto v_12752;
v_12753:
    {
        LispObject v_12779 = stack[0];
        return cons(v_12779, v_12774);
    }
    v_12774 = nil;
    return onevalue(v_12774);
}



// Code for collectphystype

static LispObject CC_collectphystype(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12779;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12719);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_12719;
// end of prologue
    v_12779 = stack[0];
    fn = elt(env, 1); // physopp
    v_12779 = (*qfn1(fn))(fn, v_12779);
    env = stack[-4];
    if (v_12779 == nil) goto v_12724;
    v_12779 = stack[0];
    fn = elt(env, 2); // getphystype
    v_12779 = (*qfn1(fn))(fn, v_12779);
    return ncons(v_12779);
v_12724:
    v_12779 = stack[0];
    if (!consp(v_12779)) goto v_12730;
    else goto v_12731;
v_12730:
    v_12779 = nil;
    goto v_12722;
v_12731:
    v_12779 = stack[0];
    stack[-3] = v_12779;
    v_12779 = stack[-3];
    if (v_12779 == nil) goto v_12746;
    else goto v_12747;
v_12746:
    v_12779 = nil;
    goto v_12741;
v_12747:
    v_12779 = stack[-3];
    v_12779 = qcar(v_12779);
    fn = elt(env, 2); // getphystype
    v_12779 = (*qfn1(fn))(fn, v_12779);
    env = stack[-4];
    v_12779 = ncons(v_12779);
    env = stack[-4];
    stack[-1] = v_12779;
    stack[-2] = v_12779;
v_12742:
    v_12779 = stack[-3];
    v_12779 = qcdr(v_12779);
    stack[-3] = v_12779;
    v_12779 = stack[-3];
    if (v_12779 == nil) goto v_12760;
    else goto v_12761;
v_12760:
    v_12779 = stack[-2];
    goto v_12741;
v_12761:
    goto v_12769;
v_12765:
    stack[0] = stack[-1];
    goto v_12766;
v_12767:
    v_12779 = stack[-3];
    v_12779 = qcar(v_12779);
    fn = elt(env, 2); // getphystype
    v_12779 = (*qfn1(fn))(fn, v_12779);
    env = stack[-4];
    v_12779 = ncons(v_12779);
    env = stack[-4];
    goto v_12768;
v_12769:
    goto v_12765;
v_12766:
    goto v_12767;
v_12768:
    v_12779 = Lrplacd(nil, stack[0], v_12779);
    env = stack[-4];
    v_12779 = stack[-1];
    v_12779 = qcdr(v_12779);
    stack[-1] = v_12779;
    goto v_12742;
v_12741:
    {
        fn = elt(env, 3); // deletemult!*
        return (*qfn1(fn))(fn, v_12779);
    }
    v_12779 = nil;
v_12722:
    return onevalue(v_12779);
}



// Code for replace1_parents

static LispObject CC_replace1_parents(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12738, v_12739, v_12740;
    LispObject fn;
    LispObject v_12721, v_12720, v_12719;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "replace1_parents");
    va_start(aa, nargs);
    v_12719 = va_arg(aa, LispObject);
    v_12720 = va_arg(aa, LispObject);
    v_12721 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12738 = v_12721;
    v_12739 = v_12720;
    v_12740 = v_12719;
// end of prologue
    goto v_12730;
v_12724:
    v_12740 = qcar(v_12740);
    goto v_12725;
v_12726:
    v_12739 = qcar(v_12739);
    goto v_12727;
v_12728:
    v_12738 = qcdr(v_12738);
    v_12738 = qcar(v_12738);
    goto v_12729;
v_12730:
    goto v_12724;
v_12725:
    goto v_12726;
v_12727:
    goto v_12728;
v_12729:
    {
        fn = elt(env, 1); // replace2_parents
        return (*qfnn(fn))(fn, 3, v_12740, v_12739, v_12738);
    }
}



// Code for repartf

static LispObject CC_repartf(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12841, v_12842;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12719);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_12719;
// end of prologue
    goto v_12726;
v_12722:
    v_12842 = elt(env, 1); // i
    goto v_12723;
v_12724:
    v_12841 = qvalue(elt(env, 2)); // kord!*
    goto v_12725;
v_12726:
    goto v_12722;
v_12723:
    goto v_12724;
v_12725:
    v_12841 = cons(v_12842, v_12841);
    env = stack[-4];
// Binding kord!*
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 2, -3);
    qvalue(elt(env, 2)) = v_12841; // kord!*
    v_12841 = stack[0];
    fn = elt(env, 4); // reorder
    v_12841 = (*qfn1(fn))(fn, v_12841);
    env = stack[-4];
    stack[-2] = v_12841;
    v_12841 = stack[-2];
    if (!consp(v_12841)) goto v_12739;
    else goto v_12740;
v_12739:
    v_12841 = lisp_true;
    goto v_12738;
v_12740:
    v_12841 = stack[-2];
    v_12841 = qcar(v_12841);
    v_12841 = (consp(v_12841) ? nil : lisp_true);
    goto v_12738;
    v_12841 = nil;
v_12738:
    if (v_12841 == nil) goto v_12736;
    v_12841 = stack[-2];
    if (!consp(v_12841)) goto v_12750;
    else goto v_12751;
v_12750:
    v_12841 = stack[-2];
    goto v_12749;
v_12751:
    goto v_12761;
v_12757:
    v_12841 = stack[-2];
    v_12842 = qcar(v_12841);
    goto v_12758;
v_12759:
    v_12841 = elt(env, 3); // cmpxfn
    goto v_12760;
v_12761:
    goto v_12757;
v_12758:
    goto v_12759;
v_12760:
    v_12841 = get(v_12842, v_12841);
    env = stack[-4];
    if (v_12841 == nil) goto v_12755;
    goto v_12773;
v_12767:
    v_12841 = stack[-2];
    stack[-1] = qcar(v_12841);
    goto v_12768;
v_12769:
    v_12841 = stack[-2];
    v_12841 = qcdr(v_12841);
    stack[0] = qcar(v_12841);
    goto v_12770;
v_12771:
    goto v_12784;
v_12780:
    v_12841 = stack[-2];
    v_12841 = qcar(v_12841);
    if (!symbolp(v_12841)) v_12842 = nil;
    else { v_12842 = qfastgets(v_12841);
           if (v_12842 != nil) { v_12842 = elt(v_12842, 34); // i2d
#ifdef RECORD_GET
             if (v_12842 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_12842 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_12842 == SPID_NOPROP) v_12842 = nil; }}
#endif
    goto v_12781;
v_12782:
    v_12841 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12783;
v_12784:
    goto v_12780;
v_12781:
    goto v_12782;
v_12783:
    v_12841 = Lapply1(nil, v_12842, v_12841);
    env = stack[-4];
    v_12841 = qcdr(v_12841);
    v_12841 = qcar(v_12841);
    goto v_12772;
v_12773:
    goto v_12767;
v_12768:
    goto v_12769;
v_12770:
    goto v_12771;
v_12772:
    v_12841 = list2star(stack[-1], stack[0], v_12841);
    env = stack[-4];
    fn = elt(env, 5); // int!-equiv!-chk
    v_12841 = (*qfn1(fn))(fn, v_12841);
    goto v_12749;
v_12755:
    v_12841 = stack[-2];
    goto v_12749;
    v_12841 = nil;
v_12749:
    goto v_12734;
v_12736:
    goto v_12800;
v_12796:
    v_12841 = stack[-2];
    v_12841 = qcar(v_12841);
    v_12841 = qcar(v_12841);
    v_12842 = qcar(v_12841);
    goto v_12797;
v_12798:
    v_12841 = elt(env, 1); // i
    goto v_12799;
v_12800:
    goto v_12796;
v_12797:
    goto v_12798;
v_12799:
    if (v_12842 == v_12841) goto v_12794;
    else goto v_12795;
v_12794:
    v_12841 = stack[-2];
    v_12841 = qcdr(v_12841);
    v_12841 = CC_repartf(elt(env, 0), v_12841);
    goto v_12734;
v_12795:
    goto v_12816;
v_12812:
    goto v_12822;
v_12818:
    goto v_12829;
v_12825:
    v_12841 = stack[-2];
    v_12841 = qcar(v_12841);
    v_12842 = qcar(v_12841);
    goto v_12826;
v_12827:
    v_12841 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12828;
v_12829:
    goto v_12825;
v_12826:
    goto v_12827;
v_12828:
    v_12841 = cons(v_12842, v_12841);
    env = stack[-4];
    stack[0] = ncons(v_12841);
    env = stack[-4];
    goto v_12819;
v_12820:
    v_12841 = stack[-2];
    v_12841 = qcar(v_12841);
    v_12841 = qcdr(v_12841);
    v_12841 = CC_repartf(elt(env, 0), v_12841);
    env = stack[-4];
    goto v_12821;
v_12822:
    goto v_12818;
v_12819:
    goto v_12820;
v_12821:
    fn = elt(env, 6); // multf
    stack[0] = (*qfn2(fn))(fn, stack[0], v_12841);
    env = stack[-4];
    goto v_12813;
v_12814:
    v_12841 = stack[-2];
    v_12841 = qcdr(v_12841);
    v_12841 = CC_repartf(elt(env, 0), v_12841);
    env = stack[-4];
    goto v_12815;
v_12816:
    goto v_12812;
v_12813:
    goto v_12814;
v_12815:
    fn = elt(env, 7); // addf
    v_12841 = (*qfn2(fn))(fn, stack[0], v_12841);
    goto v_12734;
    v_12841 = nil;
v_12734:
    ;}  // end of a binding scope
    return onevalue(v_12841);
}



// Code for setelv

static LispObject CC_setelv(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12780, v_12781;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_12720;
    v_12781 = v_12719;
// end of prologue
    goto v_12727;
v_12723:
    goto v_12733;
v_12729:
    v_12780 = v_12781;
    stack[-5] = qcar(v_12780);
    goto v_12730;
v_12731:
    v_12780 = v_12781;
    v_12780 = qcdr(v_12780);
    stack[-3] = v_12780;
    v_12780 = stack[-3];
    if (v_12780 == nil) goto v_12746;
    else goto v_12747;
v_12746:
    v_12780 = nil;
    goto v_12740;
v_12747:
    v_12780 = stack[-3];
    v_12780 = qcar(v_12780);
    fn = elt(env, 1); // reval_without_mod
    v_12780 = (*qfn1(fn))(fn, v_12780);
    env = stack[-6];
    v_12780 = ncons(v_12780);
    env = stack[-6];
    stack[-1] = v_12780;
    stack[-2] = v_12780;
v_12741:
    v_12780 = stack[-3];
    v_12780 = qcdr(v_12780);
    stack[-3] = v_12780;
    v_12780 = stack[-3];
    if (v_12780 == nil) goto v_12760;
    else goto v_12761;
v_12760:
    v_12780 = stack[-2];
    goto v_12740;
v_12761:
    goto v_12769;
v_12765:
    stack[0] = stack[-1];
    goto v_12766;
v_12767:
    v_12780 = stack[-3];
    v_12780 = qcar(v_12780);
    fn = elt(env, 1); // reval_without_mod
    v_12780 = (*qfn1(fn))(fn, v_12780);
    env = stack[-6];
    v_12780 = ncons(v_12780);
    env = stack[-6];
    goto v_12768;
v_12769:
    goto v_12765;
v_12766:
    goto v_12767;
v_12768:
    v_12780 = Lrplacd(nil, stack[0], v_12780);
    env = stack[-6];
    v_12780 = stack[-1];
    v_12780 = qcdr(v_12780);
    stack[-1] = v_12780;
    goto v_12741;
v_12740:
    goto v_12732;
v_12733:
    goto v_12729;
v_12730:
    goto v_12731;
v_12732:
    v_12781 = cons(stack[-5], v_12780);
    env = stack[-6];
    goto v_12724;
v_12725:
    v_12780 = stack[-4];
    goto v_12726;
v_12727:
    goto v_12723;
v_12724:
    goto v_12725;
v_12726:
    {
        fn = elt(env, 2); // setel
        return (*qfn2(fn))(fn, v_12781, v_12780);
    }
}



// Code for red!=cancelsimp

static LispObject CC_redMcancelsimp(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12749, v_12750;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12720;
    stack[-1] = v_12719;
// end of prologue
    goto v_12731;
v_12727:
    v_12750 = stack[-1];
    goto v_12728;
v_12729:
    v_12749 = stack[0];
    goto v_12730;
v_12731:
    goto v_12727;
v_12728:
    goto v_12729;
v_12730:
    fn = elt(env, 1); // red_better
    v_12749 = (*qfn2(fn))(fn, v_12750, v_12749);
    env = stack[-2];
    if (v_12749 == nil) goto v_12724;
    else goto v_12725;
v_12724:
    v_12749 = nil;
    goto v_12723;
v_12725:
    goto v_12742;
v_12738:
    v_12749 = stack[-1];
    fn = elt(env, 2); // bas_dpoly
    v_12749 = (*qfn1(fn))(fn, v_12749);
    env = stack[-2];
    fn = elt(env, 3); // dp_lmon
    stack[-1] = (*qfn1(fn))(fn, v_12749);
    env = stack[-2];
    goto v_12739;
v_12740:
    v_12749 = stack[0];
    fn = elt(env, 2); // bas_dpoly
    v_12749 = (*qfn1(fn))(fn, v_12749);
    env = stack[-2];
    fn = elt(env, 3); // dp_lmon
    v_12749 = (*qfn1(fn))(fn, v_12749);
    env = stack[-2];
    goto v_12741;
v_12742:
    goto v_12738;
v_12739:
    goto v_12740;
v_12741:
    {
        LispObject v_12753 = stack[-1];
        fn = elt(env, 4); // mo_vdivides!?
        return (*qfn2(fn))(fn, v_12753, v_12749);
    }
    v_12749 = nil;
v_12723:
    return onevalue(v_12749);
}



// Code for pst_termnodep

static LispObject CC_pst_termnodep(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12732, v_12733;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12732 = v_12719;
// end of prologue
    goto v_12725;
v_12721:
    v_12733 = qcdr(v_12732);
    goto v_12722;
v_12723:
    v_12732 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12724;
v_12725:
    goto v_12721;
v_12722:
    goto v_12723;
v_12724:
    v_12732 = *(LispObject *)((char *)v_12733 + (CELL-TAG_VECTOR) + (((intptr_t)v_12732-TAG_FIXNUM)/(16/CELL)));
    v_12732 = qcdr(v_12732);
    v_12732 = (v_12732 == nil ? lisp_true : nil);
    return onevalue(v_12732);
}



// Code for ratn

static LispObject CC_ratn(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12770, v_12771, v_12772;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12772 = v_12719;
// end of prologue
    v_12770 = v_12772;
    if (v_12770 == nil) goto v_12723;
    else goto v_12724;
v_12723:
    goto v_12731;
v_12727:
    v_12771 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12728;
v_12729:
    v_12770 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12730;
v_12731:
    goto v_12727;
v_12728:
    goto v_12729;
v_12730:
    return cons(v_12771, v_12770);
v_12724:
    v_12770 = v_12772;
    if (!consp(v_12770)) goto v_12734;
    else goto v_12735;
v_12734:
    goto v_12742;
v_12738:
    v_12771 = v_12772;
    goto v_12739;
v_12740:
    v_12770 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12741;
v_12742:
    goto v_12738;
v_12739:
    goto v_12740;
v_12741:
    return cons(v_12771, v_12770);
v_12735:
    goto v_12751;
v_12747:
    v_12770 = v_12772;
    v_12771 = qcar(v_12770);
    goto v_12748;
v_12749:
    v_12770 = elt(env, 1); // !:rn!:
    goto v_12750;
v_12751:
    goto v_12747;
v_12748:
    goto v_12749;
v_12750:
    if (v_12771 == v_12770) goto v_12745;
    else goto v_12746;
v_12745:
    v_12770 = v_12772;
    v_12770 = qcdr(v_12770);
    goto v_12722;
v_12746:
    goto v_12766;
v_12760:
    v_12772 = elt(env, 2); // arnum
    goto v_12761;
v_12762:
    v_12771 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_12763;
v_12764:
    v_12770 = elt(env, 3); // "Illegal domain in :ar:"
    goto v_12765;
v_12766:
    goto v_12760;
v_12761:
    goto v_12762;
v_12763:
    goto v_12764;
v_12765:
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_12772, v_12771, v_12770);
    }
    v_12770 = nil;
v_12722:
    return onevalue(v_12770);
}



// Code for crprcd2

static LispObject CC_crprcd2(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12727;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12720;
    stack[-1] = v_12719;
// end of prologue
    v_12727 = stack[-1];
    fn = elt(env, 2); // crprcd
    v_12727 = (*qfn1(fn))(fn, v_12727);
    env = stack[-2];
    stack[-1] = v_12727;
    v_12727 = stack[0];
    fn = elt(env, 2); // crprcd
    v_12727 = (*qfn1(fn))(fn, v_12727);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_12727; // yy!!
    v_12727 = stack[-1];
    return onevalue(v_12727);
}



// Code for innprodkp

static LispObject CC_innprodkp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12774, v_12775, v_12776;
    LispObject fn;
    LispObject v_12722, v_12721, v_12720, v_12719;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "innprodkp");
    va_start(aa, nargs);
    v_12719 = va_arg(aa, LispObject);
    v_12720 = va_arg(aa, LispObject);
    v_12721 = va_arg(aa, LispObject);
    v_12722 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_12722,v_12721,v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_12719,v_12720,v_12721,v_12722);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12722;
    stack[-1] = v_12721;
    stack[-2] = v_12720;
    v_12775 = v_12719;
// end of prologue
v_12726:
    v_12774 = stack[-1];
    if (v_12774 == nil) goto v_12729;
    else goto v_12730;
v_12729:
    v_12774 = nil;
    goto v_12725;
v_12730:
    goto v_12739;
v_12735:
    v_12776 = stack[-2];
    goto v_12736;
v_12737:
    v_12774 = stack[-1];
    v_12774 = qcar(v_12774);
    goto v_12738;
v_12739:
    goto v_12735;
v_12736:
    goto v_12737;
v_12738:
    if (equal(v_12776, v_12774)) goto v_12733;
    else goto v_12734;
v_12733:
    goto v_12748;
v_12744:
    goto v_12745;
v_12746:
    goto v_12755;
v_12751:
    goto v_12752;
v_12753:
    v_12774 = stack[-1];
    v_12774 = qcdr(v_12774);
    goto v_12754;
v_12755:
    goto v_12751;
v_12752:
    goto v_12753;
v_12754:
    fn = elt(env, 1); // reversip2
    v_12774 = (*qfn2(fn))(fn, v_12775, v_12774);
    goto v_12747;
v_12748:
    goto v_12744;
v_12745:
    goto v_12746;
v_12747:
    {
        LispObject v_12780 = stack[0];
        return cons(v_12780, v_12774);
    }
v_12734:
    goto v_12766;
v_12762:
    v_12774 = stack[-1];
    v_12774 = qcar(v_12774);
    goto v_12763;
v_12764:
    goto v_12765;
v_12766:
    goto v_12762;
v_12763:
    goto v_12764;
v_12765:
    v_12774 = cons(v_12774, v_12775);
    env = stack[-3];
    v_12775 = v_12774;
    v_12774 = stack[-1];
    v_12774 = qcdr(v_12774);
    stack[-1] = v_12774;
    v_12774 = stack[0];
    v_12774 = (v_12774 == nil ? lisp_true : nil);
    stack[0] = v_12774;
    goto v_12726;
    v_12774 = nil;
v_12725:
    return onevalue(v_12774);
}



// Code for ordered!-gcd!-mod!-p

static LispObject CC_orderedKgcdKmodKp(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12799, v_12800;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12720;
    stack[-1] = v_12719;
// end of prologue
    v_12799 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_12799;
v_12725:
    goto v_12732;
v_12728:
    v_12800 = stack[-1];
    goto v_12729;
v_12730:
    v_12799 = stack[0];
    goto v_12731;
v_12732:
    goto v_12728;
v_12729:
    goto v_12730;
v_12731:
    fn = elt(env, 2); // reduce!-degree!-mod!-p
    v_12799 = (*qfn2(fn))(fn, v_12800, v_12799);
    env = stack[-3];
    stack[-1] = v_12799;
    v_12799 = stack[-1];
    if (v_12799 == nil) goto v_12737;
    else goto v_12738;
v_12737:
    v_12799 = stack[0];
    {
        fn = elt(env, 3); // monic!-mod!-p
        return (*qfn1(fn))(fn, v_12799);
    }
v_12738:
    v_12799 = stack[-2];
    v_12799 = add1(v_12799);
    env = stack[-3];
    stack[-2] = v_12799;
    v_12799 = stack[-1];
    if (!consp(v_12799)) goto v_12750;
    else goto v_12751;
v_12750:
    v_12799 = lisp_true;
    goto v_12749;
v_12751:
    v_12799 = stack[-1];
    v_12799 = qcar(v_12799);
    v_12799 = (consp(v_12799) ? nil : lisp_true);
    goto v_12749;
    v_12799 = nil;
v_12749:
    if (v_12799 == nil) goto v_12747;
    goto v_12764;
v_12760:
    v_12800 = qvalue(elt(env, 1)); // reduction!-count
    goto v_12761;
v_12762:
    v_12799 = stack[-2];
    goto v_12763;
v_12764:
    goto v_12760;
v_12761:
    goto v_12762;
v_12763:
    v_12799 = plus2(v_12800, v_12799);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_12799; // reduction!-count
    v_12799 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12724;
v_12747:
    goto v_12775;
v_12771:
    v_12799 = stack[-1];
    v_12799 = qcar(v_12799);
    v_12799 = qcar(v_12799);
    v_12800 = qcdr(v_12799);
    goto v_12772;
v_12773:
    v_12799 = stack[0];
    v_12799 = qcar(v_12799);
    v_12799 = qcar(v_12799);
    v_12799 = qcdr(v_12799);
    goto v_12774;
v_12775:
    goto v_12771;
v_12772:
    goto v_12773;
v_12774:
    v_12799 = (LispObject)lessp2(v_12800, v_12799);
    v_12799 = v_12799 ? lisp_true : nil;
    env = stack[-3];
    if (v_12799 == nil) goto v_12769;
    goto v_12792;
v_12788:
    v_12800 = qvalue(elt(env, 1)); // reduction!-count
    goto v_12789;
v_12790:
    v_12799 = stack[-2];
    goto v_12791;
v_12792:
    goto v_12788;
v_12789:
    goto v_12790;
v_12791:
    v_12799 = plus2(v_12800, v_12799);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_12799; // reduction!-count
    v_12799 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_12799;
    v_12799 = stack[-1];
    v_12800 = v_12799;
    v_12799 = stack[0];
    stack[-1] = v_12799;
    v_12799 = v_12800;
    stack[0] = v_12799;
    goto v_12745;
v_12769:
v_12745:
    goto v_12725;
v_12724:
    return onevalue(v_12799);
}



// Code for pairxvars

static LispObject CC_pairxvars(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12865, v_12866, v_12867;
    LispObject fn;
    LispObject v_12722, v_12721, v_12720, v_12719;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "pairxvars");
    va_start(aa, nargs);
    v_12719 = va_arg(aa, LispObject);
    v_12720 = va_arg(aa, LispObject);
    v_12721 = va_arg(aa, LispObject);
    v_12722 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_12722,v_12721,v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_12719,v_12720,v_12721,v_12722);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_12722;
    stack[-2] = v_12721;
    stack[-3] = v_12720;
    stack[-4] = v_12719;
// end of prologue
    stack[-5] = nil;
v_12730:
    v_12865 = stack[-4];
    if (v_12865 == nil) goto v_12733;
    else goto v_12734;
v_12733:
    goto v_12729;
v_12734:
    goto v_12745;
v_12741:
    v_12865 = stack[-4];
    v_12866 = qcar(v_12865);
    goto v_12742;
v_12743:
    v_12865 = stack[-3];
    goto v_12744;
v_12745:
    goto v_12741;
v_12742:
    goto v_12743;
v_12744:
    v_12865 = Latsoc(nil, v_12866, v_12865);
    stack[0] = v_12865;
    if (v_12865 == nil) goto v_12740;
    goto v_12755;
v_12751:
    v_12866 = stack[0];
    goto v_12752;
v_12753:
    v_12865 = stack[-3];
    goto v_12754;
v_12755:
    goto v_12751;
v_12752:
    goto v_12753;
v_12754:
    v_12865 = Ldelete(nil, v_12866, v_12865);
    env = stack[-6];
    stack[-3] = v_12865;
    goto v_12766;
v_12762:
    v_12865 = stack[0];
    v_12866 = qcdr(v_12865);
    goto v_12763;
v_12764:
    v_12865 = elt(env, 1); // scalar
    goto v_12765;
v_12766:
    goto v_12762;
v_12763:
    goto v_12764;
v_12765:
    if (v_12866 == v_12865) goto v_12761;
    goto v_12777;
v_12771:
    v_12865 = stack[-4];
    v_12867 = qcar(v_12865);
    goto v_12772;
v_12773:
    v_12865 = stack[0];
    v_12866 = qcdr(v_12865);
    goto v_12774;
v_12775:
    v_12865 = stack[-5];
    goto v_12776;
v_12777:
    goto v_12771;
v_12772:
    goto v_12773;
v_12774:
    goto v_12775;
v_12776:
    v_12865 = acons(v_12867, v_12866, v_12865);
    env = stack[-6];
    stack[-5] = v_12865;
    goto v_12759;
v_12761:
    goto v_12792;
v_12786:
    v_12865 = stack[-4];
    v_12867 = qcar(v_12865);
    goto v_12787;
v_12788:
    v_12866 = stack[-1];
    goto v_12789;
v_12790:
    v_12865 = stack[-5];
    goto v_12791;
v_12792:
    goto v_12786;
v_12787:
    goto v_12788;
v_12789:
    goto v_12790;
v_12791:
    v_12865 = acons(v_12867, v_12866, v_12865);
    env = stack[-6];
    stack[-5] = v_12865;
    goto v_12759;
v_12759:
    goto v_12738;
v_12740:
    v_12865 = stack[-4];
    v_12865 = qcar(v_12865);
    if (symbolp(v_12865)) goto v_12802;
    v_12865 = lisp_true;
    goto v_12800;
v_12802:
    v_12865 = stack[-4];
    v_12865 = qcar(v_12865);
    if (!symbolp(v_12865)) v_12865 = nil;
    else { v_12865 = qfastgets(v_12865);
           if (v_12865 != nil) { v_12865 = elt(v_12865, 23); // infix
#ifdef RECORD_GET
             if (v_12865 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_12865 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_12865 == SPID_NOPROP) v_12865 = nil; }}
#endif
    if (v_12865 == nil) goto v_12810;
    else goto v_12809;
v_12810:
    v_12865 = stack[-4];
    v_12865 = qcar(v_12865);
    if (!symbolp(v_12865)) v_12865 = nil;
    else { v_12865 = qfastgets(v_12865);
           if (v_12865 != nil) { v_12865 = elt(v_12865, 36); // stat
#ifdef RECORD_GET
             if (v_12865 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v_12865 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v_12865 == SPID_NOPROP) v_12865 = nil; }}
#endif
v_12809:
    goto v_12800;
    v_12865 = nil;
v_12800:
    if (v_12865 == nil) goto v_12798;
    goto v_12822;
v_12818:
    goto v_12828;
v_12824:
    v_12866 = elt(env, 2); // "Invalid parameter:"
    goto v_12825;
v_12826:
    v_12865 = stack[-4];
    v_12865 = qcar(v_12865);
    goto v_12827;
v_12828:
    goto v_12824;
v_12825:
    goto v_12826;
v_12827:
    v_12866 = list2(v_12866, v_12865);
    env = stack[-6];
    goto v_12819;
v_12820:
    v_12865 = nil;
    goto v_12821;
v_12822:
    goto v_12818;
v_12819:
    goto v_12820;
v_12821:
    fn = elt(env, 3); // symerr
    v_12865 = (*qfn2(fn))(fn, v_12866, v_12865);
    env = stack[-6];
    goto v_12738;
v_12798:
    goto v_12842;
v_12836:
    v_12865 = stack[-4];
    v_12867 = qcar(v_12865);
    goto v_12837;
v_12838:
    v_12866 = stack[-1];
    goto v_12839;
v_12840:
    v_12865 = stack[-5];
    goto v_12841;
v_12842:
    goto v_12836;
v_12837:
    goto v_12838;
v_12839:
    goto v_12840;
v_12841:
    v_12865 = acons(v_12867, v_12866, v_12865);
    env = stack[-6];
    stack[-5] = v_12865;
    goto v_12738;
v_12738:
    v_12865 = stack[-4];
    v_12865 = qcdr(v_12865);
    stack[-4] = v_12865;
    goto v_12730;
v_12729:
    goto v_12854;
v_12850:
    goto v_12860;
v_12856:
    v_12865 = stack[-5];
    fn = elt(env, 4); // reversip!*
    v_12866 = (*qfn1(fn))(fn, v_12865);
    env = stack[-6];
    goto v_12857;
v_12858:
    v_12865 = stack[-2];
    goto v_12859;
v_12860:
    goto v_12856;
v_12857:
    goto v_12858;
v_12859:
    v_12866 = Lappend(nil, v_12866, v_12865);
    goto v_12851;
v_12852:
    v_12865 = stack[-3];
    goto v_12853;
v_12854:
    goto v_12850;
v_12851:
    goto v_12852;
v_12853:
    return cons(v_12866, v_12865);
    return onevalue(v_12865);
}



// Code for monomwrite

static LispObject CC_monomwrite(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12819, v_12820, v_12821;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12719);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_12820 = v_12719;
// end of prologue
    stack[-5] = nil;
    v_12819 = qvalue(elt(env, 1)); // fluidbibasisnumberofvariables
    stack[-2] = v_12819;
    v_12819 = qvalue(elt(env, 2)); // fluidbibasisreversedvariables
    stack[-4] = v_12819;
    goto v_12734;
v_12730:
    goto v_12731;
v_12732:
    v_12819 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12733;
v_12734:
    goto v_12730;
v_12731:
    goto v_12732;
v_12733:
    v_12819 = *(LispObject *)((char *)v_12820 + (CELL-TAG_VECTOR) + (((intptr_t)v_12819-TAG_FIXNUM)/(16/CELL)));
    stack[-3] = v_12819;
v_12740:
    v_12819 = stack[-3];
    v_12819 = qcar(v_12819);
    if (v_12819 == nil) goto v_12743;
    else goto v_12744;
v_12743:
    goto v_12739;
v_12744:
    v_12819 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_12819;
v_12751:
    goto v_12763;
v_12759:
    goto v_12769;
v_12765:
    v_12820 = stack[-2];
    goto v_12766;
v_12767:
    v_12819 = stack[-3];
    v_12819 = qcar(v_12819);
    goto v_12768;
v_12769:
    goto v_12765;
v_12766:
    goto v_12767;
v_12768:
    v_12820 = difference2(v_12820, v_12819);
    env = stack[-6];
    goto v_12760;
v_12761:
    v_12819 = stack[0];
    goto v_12762;
v_12763:
    goto v_12759;
v_12760:
    goto v_12761;
v_12762:
    v_12819 = difference2(v_12820, v_12819);
    env = stack[-6];
    v_12819 = Lminusp(nil, v_12819);
    env = stack[-6];
    if (v_12819 == nil) goto v_12756;
    goto v_12750;
v_12756:
    v_12819 = stack[-4];
    v_12819 = qcdr(v_12819);
    stack[-4] = v_12819;
    v_12819 = stack[0];
    v_12819 = add1(v_12819);
    env = stack[-6];
    stack[0] = v_12819;
    goto v_12751;
v_12750:
    v_12819 = stack[-3];
    v_12819 = qcar(v_12819);
    stack[-2] = v_12819;
    v_12819 = stack[-5];
    if (v_12819 == nil) goto v_12785;
    goto v_12794;
v_12788:
    v_12819 = stack[-4];
    stack[-1] = qcar(v_12819);
    goto v_12789;
v_12790:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12791;
v_12792:
    v_12819 = stack[-5];
    v_12819 = ncons(v_12819);
    env = stack[-6];
    goto v_12793;
v_12794:
    goto v_12788;
v_12789:
    goto v_12790;
v_12791:
    goto v_12792;
v_12793:
    v_12819 = acons(stack[-1], stack[0], v_12819);
    env = stack[-6];
    stack[-5] = v_12819;
    goto v_12783;
v_12785:
    goto v_12809;
v_12803:
    v_12819 = stack[-4];
    v_12821 = qcar(v_12819);
    goto v_12804;
v_12805:
    v_12820 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12806;
v_12807:
    v_12819 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12808;
v_12809:
    goto v_12803;
v_12804:
    goto v_12805;
v_12806:
    goto v_12807;
v_12808:
    v_12819 = acons(v_12821, v_12820, v_12819);
    env = stack[-6];
    stack[-5] = v_12819;
    goto v_12783;
v_12783:
    v_12819 = stack[-3];
    v_12819 = qcdr(v_12819);
    stack[-3] = v_12819;
    goto v_12740;
v_12739:
    v_12819 = stack[-5];
    return onevalue(v_12819);
}



// Code for super_der_simp

static LispObject CC_super_der_simp(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_13146, v_13147, v_13148;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12719);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_12719;
// end of prologue
    goto v_12729;
v_12725:
    v_13146 = stack[-9];
    v_13147 = Llength(nil, v_13146);
    env = stack[-11];
    goto v_12726;
v_12727:
    v_13146 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_12728;
v_12729:
    goto v_12725;
v_12726:
    goto v_12727;
v_12728:
    if (v_13147 == v_13146) goto v_12723;
    else goto v_12724;
v_12723:
    v_13146 = stack[-9];
    v_13146 = qcar(v_13146);
    fn = elt(env, 6); // reval
    v_13146 = (*qfn1(fn))(fn, v_13146);
    env = stack[-11];
    stack[-10] = v_13146;
    goto v_12749;
v_12745:
    v_13147 = stack[-10];
    goto v_12746;
v_12747:
    v_13146 = elt(env, 1); // variables
    goto v_12748;
v_12749:
    goto v_12745;
v_12746:
    goto v_12747;
v_12748:
    v_13146 = get(v_13147, v_13146);
    env = stack[-11];
    stack[-8] = v_13146;
    v_13146 = stack[-9];
    v_13146 = qcdr(v_13146);
    v_13146 = qcar(v_13146);
    fn = elt(env, 7); // simp!*
    v_13146 = (*qfn1(fn))(fn, v_13146);
    env = stack[-11];
    stack[-9] = v_13146;
    goto v_12761;
v_12757:
    v_13146 = stack[-9];
    v_13147 = qcar(v_13146);
    goto v_12758;
v_12759:
    v_13146 = elt(env, 2); // (ext)
    goto v_12760;
v_12761:
    goto v_12757;
v_12758:
    goto v_12759;
v_12760:
    fn = elt(env, 8); // split_form
    v_13146 = (*qfn2(fn))(fn, v_13147, v_13146);
    env = stack[-11];
    stack[-7] = v_13146;
    goto v_12772;
v_12766:
    v_13146 = elt(env, 3); // ext
    v_13148 = ncons(v_13146);
    env = stack[-11];
    goto v_12767;
v_12768:
    v_13146 = stack[-7];
    v_13147 = qcar(v_13146);
    goto v_12769;
v_12770:
    v_13146 = stack[-7];
    v_13146 = qcdr(v_13146);
    goto v_12771;
v_12772:
    goto v_12766;
v_12767:
    goto v_12768;
v_12769:
    goto v_12770;
v_12771:
    v_13146 = acons(v_13148, v_13147, v_13146);
    env = stack[-11];
    stack[-7] = v_13146;
    goto v_12784;
v_12780:
    v_13146 = stack[-9];
    v_13147 = qcdr(v_13146);
    goto v_12781;
v_12782:
    v_13146 = elt(env, 2); // (ext)
    goto v_12783;
v_12784:
    goto v_12780;
v_12781:
    goto v_12782;
v_12783:
    fn = elt(env, 8); // split_form
    v_13146 = (*qfn2(fn))(fn, v_13147, v_13146);
    env = stack[-11];
    stack[-6] = v_13146;
    goto v_12795;
v_12789:
    v_13146 = elt(env, 3); // ext
    v_13148 = ncons(v_13146);
    env = stack[-11];
    goto v_12790;
v_12791:
    v_13146 = stack[-6];
    v_13147 = qcar(v_13146);
    goto v_12792;
v_12793:
    v_13146 = stack[-6];
    v_13146 = qcdr(v_13146);
    goto v_12794;
v_12795:
    goto v_12789;
v_12790:
    goto v_12791;
v_12792:
    goto v_12793;
v_12794:
    v_13146 = acons(v_13148, v_13147, v_13146);
    env = stack[-11];
    stack[-6] = v_13146;
    v_13146 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_13146;
    goto v_12819;
v_12815:
    goto v_12825;
v_12821:
    v_13147 = stack[-10];
    goto v_12822;
v_12823:
    v_13146 = elt(env, 4); // even_dimension
    goto v_12824;
v_12825:
    goto v_12821;
v_12822:
    goto v_12823;
v_12824:
    v_13147 = get(v_13147, v_13146);
    env = stack[-11];
    goto v_12816;
v_12817:
    v_13146 = stack[-5];
    goto v_12818;
v_12819:
    goto v_12815;
v_12816:
    goto v_12817;
v_12818:
    v_13146 = difference2(v_13147, v_13146);
    env = stack[-11];
    v_13146 = Lminusp(nil, v_13146);
    env = stack[-11];
    if (v_13146 == nil) goto v_12812;
    v_13146 = nil;
    goto v_12806;
v_12812:
    goto v_12839;
v_12833:
    v_13148 = stack[-10];
    goto v_12834;
v_12835:
    v_13147 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12836;
v_12837:
    v_13146 = stack[-5];
    goto v_12838;
v_12839:
    goto v_12833;
v_12834:
    goto v_12835;
v_12836:
    goto v_12837;
v_12838:
    v_13146 = list3(v_13148, v_13147, v_13146);
    env = stack[-11];
    fn = elt(env, 7); // simp!*
    v_13146 = (*qfn1(fn))(fn, v_13146);
    env = stack[-11];
    stack[-1] = v_13146;
    goto v_12849;
v_12845:
    goto v_12855;
v_12851:
    v_13147 = stack[-8];
    goto v_12852;
v_12853:
    v_13146 = stack[-5];
    goto v_12854;
v_12855:
    goto v_12851;
v_12852:
    goto v_12853;
v_12854:
    fn = elt(env, 9); // nth
    stack[0] = (*qfn2(fn))(fn, v_13147, v_13146);
    env = stack[-11];
    goto v_12846;
v_12847:
    goto v_12863;
v_12859:
    v_13147 = stack[-1];
    goto v_12860;
v_12861:
    v_13146 = elt(env, 2); // (ext)
    goto v_12862;
v_12863:
    goto v_12859;
v_12860:
    goto v_12861;
v_12862:
    fn = elt(env, 10); // split_ext
    v_13146 = (*qfn2(fn))(fn, v_13147, v_13146);
    env = stack[-11];
    goto v_12848;
v_12849:
    goto v_12845;
v_12846:
    goto v_12847;
v_12848:
    v_13146 = cons(stack[0], v_13146);
    env = stack[-11];
    v_13146 = ncons(v_13146);
    env = stack[-11];
    stack[-3] = v_13146;
    stack[-4] = v_13146;
v_12807:
    v_13146 = stack[-5];
    v_13146 = add1(v_13146);
    env = stack[-11];
    stack[-5] = v_13146;
    goto v_12878;
v_12874:
    goto v_12884;
v_12880:
    v_13147 = stack[-10];
    goto v_12881;
v_12882:
    v_13146 = elt(env, 4); // even_dimension
    goto v_12883;
v_12884:
    goto v_12880;
v_12881:
    goto v_12882;
v_12883:
    v_13147 = get(v_13147, v_13146);
    env = stack[-11];
    goto v_12875;
v_12876:
    v_13146 = stack[-5];
    goto v_12877;
v_12878:
    goto v_12874;
v_12875:
    goto v_12876;
v_12877:
    v_13146 = difference2(v_13147, v_13146);
    env = stack[-11];
    v_13146 = Lminusp(nil, v_13146);
    env = stack[-11];
    if (v_13146 == nil) goto v_12871;
    v_13146 = stack[-4];
    goto v_12806;
v_12871:
    goto v_12894;
v_12890:
    stack[-2] = stack[-3];
    goto v_12891;
v_12892:
    goto v_12905;
v_12899:
    v_13148 = stack[-10];
    goto v_12900;
v_12901:
    v_13147 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12902;
v_12903:
    v_13146 = stack[-5];
    goto v_12904;
v_12905:
    goto v_12899;
v_12900:
    goto v_12901;
v_12902:
    goto v_12903;
v_12904:
    v_13146 = list3(v_13148, v_13147, v_13146);
    env = stack[-11];
    fn = elt(env, 7); // simp!*
    v_13146 = (*qfn1(fn))(fn, v_13146);
    env = stack[-11];
    stack[-1] = v_13146;
    goto v_12915;
v_12911:
    goto v_12921;
v_12917:
    v_13147 = stack[-8];
    goto v_12918;
v_12919:
    v_13146 = stack[-5];
    goto v_12920;
v_12921:
    goto v_12917;
v_12918:
    goto v_12919;
v_12920:
    fn = elt(env, 9); // nth
    stack[0] = (*qfn2(fn))(fn, v_13147, v_13146);
    env = stack[-11];
    goto v_12912;
v_12913:
    goto v_12929;
v_12925:
    v_13147 = stack[-1];
    goto v_12926;
v_12927:
    v_13146 = elt(env, 2); // (ext)
    goto v_12928;
v_12929:
    goto v_12925;
v_12926:
    goto v_12927;
v_12928:
    fn = elt(env, 10); // split_ext
    v_13146 = (*qfn2(fn))(fn, v_13147, v_13146);
    env = stack[-11];
    goto v_12914;
v_12915:
    goto v_12911;
v_12912:
    goto v_12913;
v_12914:
    v_13146 = cons(stack[0], v_13146);
    env = stack[-11];
    v_13146 = ncons(v_13146);
    env = stack[-11];
    goto v_12893;
v_12894:
    goto v_12890;
v_12891:
    goto v_12892;
v_12893:
    v_13146 = Lrplacd(nil, stack[-2], v_13146);
    env = stack[-11];
    v_13146 = stack[-3];
    v_13146 = qcdr(v_13146);
    stack[-3] = v_13146;
    goto v_12807;
v_12806:
    stack[-5] = v_13146;
    v_13146 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_13146;
    goto v_12951;
v_12947:
    goto v_12957;
v_12953:
    v_13147 = stack[-10];
    goto v_12954;
v_12955:
    v_13146 = elt(env, 5); // odd_dimension
    goto v_12956;
v_12957:
    goto v_12953;
v_12954:
    goto v_12955;
v_12956:
    v_13147 = get(v_13147, v_13146);
    env = stack[-11];
    goto v_12948;
v_12949:
    v_13146 = stack[-4];
    goto v_12950;
v_12951:
    goto v_12947;
v_12948:
    goto v_12949;
v_12950:
    v_13146 = difference2(v_13147, v_13146);
    env = stack[-11];
    v_13146 = Lminusp(nil, v_13146);
    env = stack[-11];
    if (v_13146 == nil) goto v_12944;
    v_13146 = nil;
    goto v_12938;
v_12944:
    goto v_12971;
v_12965:
    v_13148 = stack[-10];
    goto v_12966;
v_12967:
    v_13147 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12968;
v_12969:
    v_13146 = stack[-4];
    goto v_12970;
v_12971:
    goto v_12965;
v_12966:
    goto v_12967;
v_12968:
    goto v_12969;
v_12970:
    v_13146 = list3(v_13148, v_13147, v_13146);
    env = stack[-11];
    fn = elt(env, 7); // simp!*
    v_13146 = (*qfn1(fn))(fn, v_13146);
    env = stack[-11];
    goto v_12981;
v_12977:
    stack[0] = stack[-4];
    goto v_12978;
v_12979:
    goto v_12988;
v_12984:
    v_13147 = v_13146;
    goto v_12985;
v_12986:
    v_13146 = elt(env, 2); // (ext)
    goto v_12987;
v_12988:
    goto v_12984;
v_12985:
    goto v_12986;
v_12987:
    fn = elt(env, 10); // split_ext
    v_13146 = (*qfn2(fn))(fn, v_13147, v_13146);
    env = stack[-11];
    goto v_12980;
v_12981:
    goto v_12977;
v_12978:
    goto v_12979;
v_12980:
    v_13146 = cons(stack[0], v_13146);
    env = stack[-11];
    v_13146 = ncons(v_13146);
    env = stack[-11];
    stack[-2] = v_13146;
    stack[-3] = v_13146;
v_12939:
    v_13146 = stack[-4];
    v_13146 = add1(v_13146);
    env = stack[-11];
    stack[-4] = v_13146;
    goto v_13003;
v_12999:
    goto v_13009;
v_13005:
    v_13147 = stack[-10];
    goto v_13006;
v_13007:
    v_13146 = elt(env, 5); // odd_dimension
    goto v_13008;
v_13009:
    goto v_13005;
v_13006:
    goto v_13007;
v_13008:
    v_13147 = get(v_13147, v_13146);
    env = stack[-11];
    goto v_13000;
v_13001:
    v_13146 = stack[-4];
    goto v_13002;
v_13003:
    goto v_12999;
v_13000:
    goto v_13001;
v_13002:
    v_13146 = difference2(v_13147, v_13146);
    env = stack[-11];
    v_13146 = Lminusp(nil, v_13146);
    env = stack[-11];
    if (v_13146 == nil) goto v_12996;
    v_13146 = stack[-3];
    goto v_12938;
v_12996:
    goto v_13019;
v_13015:
    stack[-1] = stack[-2];
    goto v_13016;
v_13017:
    goto v_13030;
v_13024:
    v_13148 = stack[-10];
    goto v_13025;
v_13026:
    v_13147 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13027;
v_13028:
    v_13146 = stack[-4];
    goto v_13029;
v_13030:
    goto v_13024;
v_13025:
    goto v_13026;
v_13027:
    goto v_13028;
v_13029:
    v_13146 = list3(v_13148, v_13147, v_13146);
    env = stack[-11];
    fn = elt(env, 7); // simp!*
    v_13146 = (*qfn1(fn))(fn, v_13146);
    env = stack[-11];
    goto v_13040;
v_13036:
    stack[0] = stack[-4];
    goto v_13037;
v_13038:
    goto v_13047;
v_13043:
    v_13147 = v_13146;
    goto v_13044;
v_13045:
    v_13146 = elt(env, 2); // (ext)
    goto v_13046;
v_13047:
    goto v_13043;
v_13044:
    goto v_13045;
v_13046:
    fn = elt(env, 10); // split_ext
    v_13146 = (*qfn2(fn))(fn, v_13147, v_13146);
    env = stack[-11];
    goto v_13039;
v_13040:
    goto v_13036;
v_13037:
    goto v_13038;
v_13039:
    v_13146 = cons(stack[0], v_13146);
    env = stack[-11];
    v_13146 = ncons(v_13146);
    env = stack[-11];
    goto v_13018;
v_13019:
    goto v_13015;
v_13016:
    goto v_13017;
v_13018:
    v_13146 = Lrplacd(nil, stack[-1], v_13146);
    env = stack[-11];
    v_13146 = stack[-2];
    v_13146 = qcdr(v_13146);
    stack[-2] = v_13146;
    goto v_12939;
v_12938:
    stack[-1] = v_13146;
    goto v_13057;
v_13053:
    goto v_13063;
v_13059:
    goto v_13069;
v_13065:
    goto v_13075;
v_13071:
    v_13147 = stack[-5];
    goto v_13072;
v_13073:
    v_13146 = stack[-7];
    goto v_13074;
v_13075:
    goto v_13071;
v_13072:
    goto v_13073;
v_13074:
    fn = elt(env, 11); // even_action
    stack[0] = (*qfn2(fn))(fn, v_13147, v_13146);
    env = stack[-11];
    goto v_13066;
v_13067:
    goto v_13083;
v_13079:
    v_13147 = stack[-1];
    goto v_13080;
v_13081:
    v_13146 = stack[-7];
    goto v_13082;
v_13083:
    goto v_13079;
v_13080:
    goto v_13081;
v_13082:
    fn = elt(env, 12); // odd_action
    v_13146 = (*qfn2(fn))(fn, v_13147, v_13146);
    env = stack[-11];
    goto v_13068;
v_13069:
    goto v_13065;
v_13066:
    goto v_13067;
v_13068:
    fn = elt(env, 13); // addsq
    stack[0] = (*qfn2(fn))(fn, stack[0], v_13146);
    env = stack[-11];
    goto v_13060;
v_13061:
    goto v_13091;
v_13087:
    v_13146 = stack[-9];
    v_13147 = qcdr(v_13146);
    goto v_13088;
v_13089:
    v_13146 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13090;
v_13091:
    goto v_13087;
v_13088:
    goto v_13089;
v_13090:
    v_13146 = cons(v_13147, v_13146);
    env = stack[-11];
    goto v_13062;
v_13063:
    goto v_13059;
v_13060:
    goto v_13061;
v_13062:
    fn = elt(env, 14); // quotsq
    stack[0] = (*qfn2(fn))(fn, stack[0], v_13146);
    env = stack[-11];
    goto v_13054;
v_13055:
    goto v_13101;
v_13097:
    goto v_13107;
v_13103:
    goto v_13113;
v_13109:
    v_13147 = stack[-5];
    goto v_13110;
v_13111:
    v_13146 = stack[-6];
    goto v_13112;
v_13113:
    goto v_13109;
v_13110:
    goto v_13111;
v_13112:
    fn = elt(env, 11); // even_action
    stack[-1] = (*qfn2(fn))(fn, v_13147, v_13146);
    env = stack[-11];
    goto v_13104;
v_13105:
    goto v_13121;
v_13117:
    v_13146 = stack[-9];
    v_13147 = qcar(v_13146);
    goto v_13118;
v_13119:
    v_13146 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13120;
v_13121:
    goto v_13117;
v_13118:
    goto v_13119;
v_13120:
    v_13146 = cons(v_13147, v_13146);
    env = stack[-11];
    goto v_13106;
v_13107:
    goto v_13103;
v_13104:
    goto v_13105;
v_13106:
    fn = elt(env, 15); // super_product_sq
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_13146);
    env = stack[-11];
    goto v_13098;
v_13099:
    goto v_13130;
v_13126:
    goto v_13136;
v_13132:
    v_13146 = stack[-9];
    v_13147 = qcdr(v_13146);
    goto v_13133;
v_13134:
    v_13146 = stack[-9];
    v_13146 = qcdr(v_13146);
    goto v_13135;
v_13136:
    goto v_13132;
v_13133:
    goto v_13134;
v_13135:
    fn = elt(env, 16); // multf
    v_13147 = (*qfn2(fn))(fn, v_13147, v_13146);
    env = stack[-11];
    goto v_13127;
v_13128:
    v_13146 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13129;
v_13130:
    goto v_13126;
v_13127:
    goto v_13128;
v_13129:
    v_13146 = cons(v_13147, v_13146);
    env = stack[-11];
    goto v_13100;
v_13101:
    goto v_13097;
v_13098:
    goto v_13099;
v_13100:
    fn = elt(env, 14); // quotsq
    v_13146 = (*qfn2(fn))(fn, stack[-1], v_13146);
    env = stack[-11];
    fn = elt(env, 17); // negsq
    v_13146 = (*qfn1(fn))(fn, v_13146);
    env = stack[-11];
    goto v_13056;
v_13057:
    goto v_13053;
v_13054:
    goto v_13055;
v_13056:
    {
        LispObject v_13160 = stack[0];
        fn = elt(env, 13); // addsq
        return (*qfn2(fn))(fn, v_13160, v_13146);
    }
    goto v_12722;
v_12724:
    v_13146 = stack[-9];
    {
        fn = elt(env, 18); // simpiden
        return (*qfn1(fn))(fn, v_13146);
    }
    v_13146 = nil;
v_12722:
    return onevalue(v_13146);
}



// Code for tayexp!-times2

static LispObject CC_tayexpKtimes2(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12802, v_12803, v_12804;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12720;
    v_12803 = v_12719;
// end of prologue
    v_12802 = v_12803;
    if (!consp(v_12802)) goto v_12728;
    else goto v_12729;
v_12728:
    v_12802 = stack[0];
    v_12802 = (consp(v_12802) ? nil : lisp_true);
    goto v_12727;
v_12729:
    v_12802 = nil;
    goto v_12727;
    v_12802 = nil;
v_12727:
    if (v_12802 == nil) goto v_12725;
    goto v_12741;
v_12737:
    goto v_12738;
v_12739:
    v_12802 = stack[0];
    goto v_12740;
v_12741:
    goto v_12737;
v_12738:
    goto v_12739;
v_12740:
    return times2(v_12803, v_12802);
v_12725:
    v_12802 = v_12803;
    if (!consp(v_12802)) goto v_12748;
    else goto v_12749;
v_12748:
    goto v_12756;
v_12752:
    v_12802 = v_12803;
    fn = elt(env, 1); // !*i2rn
    v_12803 = (*qfn1(fn))(fn, v_12802);
    env = stack[-2];
    goto v_12753;
v_12754:
    v_12802 = stack[0];
    goto v_12755;
v_12756:
    goto v_12752;
v_12753:
    goto v_12754;
v_12755:
    fn = elt(env, 2); // rntimes!:
    v_12802 = (*qfn2(fn))(fn, v_12803, v_12802);
    goto v_12747;
v_12749:
    v_12802 = stack[0];
    if (!consp(v_12802)) goto v_12760;
    else goto v_12761;
v_12760:
    goto v_12768;
v_12764:
    stack[-1] = v_12803;
    goto v_12765;
v_12766:
    v_12802 = stack[0];
    fn = elt(env, 1); // !*i2rn
    v_12802 = (*qfn1(fn))(fn, v_12802);
    env = stack[-2];
    goto v_12767;
v_12768:
    goto v_12764;
v_12765:
    goto v_12766;
v_12767:
    fn = elt(env, 2); // rntimes!:
    v_12802 = (*qfn2(fn))(fn, stack[-1], v_12802);
    goto v_12747;
v_12761:
    goto v_12779;
v_12775:
    goto v_12776;
v_12777:
    v_12802 = stack[0];
    goto v_12778;
v_12779:
    goto v_12775;
v_12776:
    goto v_12777;
v_12778:
    fn = elt(env, 2); // rntimes!:
    v_12802 = (*qfn2(fn))(fn, v_12803, v_12802);
    goto v_12747;
    v_12802 = nil;
v_12747:
    v_12804 = v_12802;
    goto v_12791;
v_12787:
    v_12802 = v_12804;
    v_12802 = qcdr(v_12802);
    v_12803 = qcdr(v_12802);
    goto v_12788;
v_12789:
    v_12802 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12790;
v_12791:
    goto v_12787;
v_12788:
    goto v_12789;
v_12790:
    if (v_12803 == v_12802) goto v_12785;
    else goto v_12786;
v_12785:
    v_12802 = v_12804;
    v_12802 = qcdr(v_12802);
    v_12802 = qcar(v_12802);
    goto v_12784;
v_12786:
    v_12802 = v_12804;
    goto v_12784;
    v_12802 = nil;
v_12784:
    goto v_12723;
    v_12802 = nil;
v_12723:
    return onevalue(v_12802);
}



// Code for get!*elements

static LispObject CC_getHelements(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12732, v_12733;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12732 = v_12719;
// end of prologue
    goto v_12729;
v_12725:
    goto v_12726;
v_12727:
    v_12733 = elt(env, 1); // elems
    goto v_12728;
v_12729:
    goto v_12725;
v_12726:
    goto v_12727;
v_12728:
    return get(v_12732, v_12733);
    return onevalue(v_12732);
}



// Code for talp_subt

static LispObject CC_talp_subt(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12811, v_12812, v_12813;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12720,v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12719,v_12720);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_12812 = v_12720;
    stack[-4] = v_12719;
// end of prologue
    v_12811 = v_12812;
    if (symbolp(v_12811)) goto v_12729;
    else goto v_12728;
v_12729:
    goto v_12736;
v_12732:
    v_12813 = v_12812;
    goto v_12733;
v_12734:
    v_12811 = stack[-4];
    goto v_12735;
v_12736:
    goto v_12732;
v_12733:
    goto v_12734;
v_12735:
    v_12811 = Latsoc(nil, v_12813, v_12811);
    v_12813 = v_12811;
    if (v_12811 == nil) goto v_12728;
    v_12811 = v_12813;
    v_12811 = qcdr(v_12811);
    goto v_12724;
v_12728:
    v_12811 = v_12812;
    if (!consp(v_12811)) goto v_12744;
    else goto v_12745;
v_12744:
    v_12811 = v_12812;
    goto v_12724;
v_12745:
    goto v_12753;
v_12749:
    v_12811 = v_12812;
    stack[-5] = qcar(v_12811);
    goto v_12750;
v_12751:
    v_12811 = v_12812;
    v_12811 = qcdr(v_12811);
    stack[-3] = v_12811;
    v_12811 = stack[-3];
    if (v_12811 == nil) goto v_12766;
    else goto v_12767;
v_12766:
    v_12811 = nil;
    goto v_12760;
v_12767:
    v_12811 = stack[-3];
    v_12811 = qcar(v_12811);
    goto v_12779;
v_12775:
    v_12812 = stack[-4];
    goto v_12776;
v_12777:
    goto v_12778;
v_12779:
    goto v_12775;
v_12776:
    goto v_12777;
v_12778:
    v_12811 = CC_talp_subt(elt(env, 0), v_12812, v_12811);
    env = stack[-6];
    v_12811 = ncons(v_12811);
    env = stack[-6];
    stack[-1] = v_12811;
    stack[-2] = v_12811;
v_12761:
    v_12811 = stack[-3];
    v_12811 = qcdr(v_12811);
    stack[-3] = v_12811;
    v_12811 = stack[-3];
    if (v_12811 == nil) goto v_12786;
    else goto v_12787;
v_12786:
    v_12811 = stack[-2];
    goto v_12760;
v_12787:
    goto v_12795;
v_12791:
    stack[0] = stack[-1];
    goto v_12792;
v_12793:
    v_12811 = stack[-3];
    v_12811 = qcar(v_12811);
    goto v_12806;
v_12802:
    v_12812 = stack[-4];
    goto v_12803;
v_12804:
    goto v_12805;
v_12806:
    goto v_12802;
v_12803:
    goto v_12804;
v_12805:
    v_12811 = CC_talp_subt(elt(env, 0), v_12812, v_12811);
    env = stack[-6];
    v_12811 = ncons(v_12811);
    env = stack[-6];
    goto v_12794;
v_12795:
    goto v_12791;
v_12792:
    goto v_12793;
v_12794:
    v_12811 = Lrplacd(nil, stack[0], v_12811);
    env = stack[-6];
    v_12811 = stack[-1];
    v_12811 = qcdr(v_12811);
    stack[-1] = v_12811;
    goto v_12761;
v_12760:
    goto v_12752;
v_12753:
    goto v_12749;
v_12750:
    goto v_12751;
v_12752:
    {
        LispObject v_12820 = stack[-5];
        return cons(v_12820, v_12811);
    }
v_12724:
    return onevalue(v_12811);
}



// Code for ibalp_readform

static LispObject CC_ibalp_readform(LispObject env,
                         LispObject v_12719)
{
    env = qenv(env);
    LispObject v_12875, v_12876;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12719);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12719);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    v_12875 = v_12719;
// end of prologue
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-3] = nil;
    v_12876 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_12876;
    goto v_12737;
v_12733:
    v_12876 = v_12875;
    goto v_12734;
v_12735:
    v_12875 = elt(env, 1); // and
    goto v_12736;
v_12737:
    goto v_12733;
v_12734:
    goto v_12735;
v_12736:
    fn = elt(env, 7); // cl_mkstrict
    v_12875 = (*qfn2(fn))(fn, v_12876, v_12875);
    env = stack[-7];
    v_12875 = qcdr(v_12875);
    stack[-2] = v_12875;
    v_12875 = lisp_true;
    stack[-1] = v_12875;
v_12745:
    v_12875 = stack[-1];
    if (v_12875 == nil) goto v_12748;
    v_12875 = stack[-2];
    if (v_12875 == nil) goto v_12748;
    goto v_12749;
v_12748:
    goto v_12744;
v_12749:
    v_12875 = stack[-2];
    v_12875 = qcar(v_12875);
    v_12876 = v_12875;
    v_12875 = stack[-2];
    v_12875 = qcdr(v_12875);
    stack[-2] = v_12875;
    goto v_12764;
v_12760:
    goto v_12761;
v_12762:
    v_12875 = stack[-4];
    goto v_12763;
v_12764:
    goto v_12760;
v_12761:
    goto v_12762;
v_12763:
    fn = elt(env, 8); // ibalp_readclause
    v_12875 = (*qfn2(fn))(fn, v_12876, v_12875);
    env = stack[-7];
    stack[-6] = v_12875;
    v_12875 = stack[-6];
    v_12875 = qcar(v_12875);
    stack[-3] = v_12875;
    v_12875 = stack[-6];
    v_12875 = qcdr(v_12875);
    stack[-4] = v_12875;
    goto v_12779;
v_12775:
    v_12876 = stack[-3];
    goto v_12776;
v_12777:
    v_12875 = elt(env, 2); // true
    goto v_12778;
v_12779:
    goto v_12775;
v_12776:
    goto v_12777;
v_12778:
    if (v_12876 == v_12875) goto v_12774;
    v_12875 = stack[-3];
    fn = elt(env, 9); // ibalp_emptyclausep
    v_12875 = (*qfn1(fn))(fn, v_12875);
    env = stack[-7];
    if (v_12875 == nil) goto v_12785;
    v_12875 = nil;
    stack[-1] = v_12875;
    goto v_12783;
v_12785:
    goto v_12801;
v_12797:
    v_12876 = stack[-3];
    goto v_12798;
v_12799:
    v_12875 = stack[-5];
    goto v_12800;
v_12801:
    goto v_12797;
v_12798:
    goto v_12799;
v_12800:
    fn = elt(env, 10); // ibalp_clmember
    v_12875 = (*qfn2(fn))(fn, v_12876, v_12875);
    env = stack[-7];
    if (v_12875 == nil) goto v_12795;
    else goto v_12793;
v_12795:
    v_12875 = stack[-3];
    fn = elt(env, 11); // ibalp_redclause
    v_12875 = (*qfn1(fn))(fn, v_12875);
    env = stack[-7];
    if (v_12875 == nil) goto v_12804;
    else goto v_12793;
v_12804:
    goto v_12794;
v_12793:
    v_12875 = stack[-3];
    fn = elt(env, 12); // ibalp_undoclause
    v_12875 = (*qfn1(fn))(fn, v_12875);
    env = stack[-7];
    v_12875 = stack[0];
    v_12875 = add1(v_12875);
    env = stack[-7];
    stack[0] = v_12875;
    goto v_12792;
v_12794:
    goto v_12818;
v_12814:
    v_12875 = stack[-6];
    v_12876 = qcar(v_12875);
    goto v_12815;
v_12816:
    v_12875 = stack[-5];
    goto v_12817;
v_12818:
    goto v_12814;
v_12815:
    goto v_12816;
v_12817:
    v_12875 = cons(v_12876, v_12875);
    env = stack[-7];
    stack[-5] = v_12875;
    goto v_12792;
v_12792:
    goto v_12783;
v_12783:
    goto v_12772;
v_12774:
v_12772:
    goto v_12745;
v_12744:
    v_12875 = stack[-1];
    if (v_12875 == nil) goto v_12824;
    else goto v_12825;
v_12824:
    v_12875 = qvalue(elt(env, 3)); // !*rlverbose
    if (v_12875 == nil) goto v_12830;
    v_12875 = elt(env, 4); // "Detected empty clause"
    v_12875 = ncons(v_12875);
    env = stack[-7];
    fn = elt(env, 13); // ioto_tprin2t
    v_12875 = (*qfn1(fn))(fn, v_12875);
    env = stack[-7];
    goto v_12828;
v_12830:
v_12828:
    v_12875 = stack[-3];
    v_12875 = ncons(v_12875);
    return ncons(v_12875);
v_12825:
    v_12875 = stack[-5];
    if (v_12875 == nil) goto v_12840;
    else goto v_12841;
v_12840:
    v_12875 = qvalue(elt(env, 3)); // !*rlverbose
    if (v_12875 == nil) goto v_12846;
    v_12875 = elt(env, 5); // "Tautology detected"
    v_12875 = ncons(v_12875);
    env = stack[-7];
    fn = elt(env, 13); // ioto_tprin2t
    v_12875 = (*qfn1(fn))(fn, v_12875);
    goto v_12844;
v_12846:
v_12844:
    v_12875 = nil;
    return ncons(v_12875);
v_12841:
    v_12875 = qvalue(elt(env, 3)); // !*rlverbose
    if (v_12875 == nil) goto v_12856;
    goto v_12864;
v_12860:
    v_12876 = elt(env, 6); // "Deleted redundant clauses: "
    goto v_12861;
v_12862:
    v_12875 = stack[0];
    goto v_12863;
v_12864:
    goto v_12860;
v_12861:
    goto v_12862;
v_12863:
    v_12875 = list2(v_12876, v_12875);
    env = stack[-7];
    fn = elt(env, 13); // ioto_tprin2t
    v_12875 = (*qfn1(fn))(fn, v_12875);
    goto v_12854;
v_12856:
v_12854:
    goto v_12872;
v_12868:
    v_12876 = stack[-5];
    goto v_12869;
v_12870:
    v_12875 = stack[-4];
    goto v_12871;
v_12872:
    goto v_12868;
v_12869:
    goto v_12870;
v_12871:
    return cons(v_12876, v_12875);
    return onevalue(v_12875);
}



// Code for vsl_boundtype

static LispObject CC_vsl_boundtype(LispObject env,
                         LispObject v_12719, LispObject v_12720)
{
    env = qenv(env);
    LispObject v_12732, v_12733;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12732 = v_12720;
    v_12733 = v_12719;
// end of prologue
    goto v_12727;
v_12723:
    v_12733 = qcdr(v_12733);
    v_12733 = qcar(v_12733);
    goto v_12724;
v_12725:
    goto v_12726;
v_12727:
    goto v_12723;
v_12724:
    goto v_12725;
v_12726:
    {
        fn = elt(env, 1); // vsl_boundtype1
        return (*qfn2(fn))(fn, v_12733, v_12732);
    }
}



setup_type const u22_setup[] =
{
    {"mchkopt1",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mchkopt1},
    {"ps:evaluate",             TOO_FEW_2,      CC_psTevaluate,WRONG_NO_2},
    {"reform-minus",            TOO_FEW_2,      CC_reformKminus,WRONG_NO_2},
    {"setmat",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setmat},
    {"freeoffl",                TOO_FEW_2,      CC_freeoffl,   WRONG_NO_2},
    {"fortexp",                 CC_fortexp,     TOO_MANY_1,    WRONG_NO_1},
    {"indordp",                 TOO_FEW_2,      CC_indordp,    WRONG_NO_2},
    {"lpriw",                   TOO_FEW_2,      CC_lpriw,      WRONG_NO_2},
    {"mv-domainlist-+",         TOO_FEW_2,      CC_mvKdomainlistKL,WRONG_NO_2},
    {"mo_lcm",                  TOO_FEW_2,      CC_mo_lcm,     WRONG_NO_2},
    {"arglist_member",          TOO_FEW_2,      CC_arglist_member,WRONG_NO_2},
    {"drop_rl_with",            TOO_FEW_2,      CC_drop_rl_with,WRONG_NO_2},
    {"remlocs",                 CC_remlocs,     TOO_MANY_1,    WRONG_NO_1},
    {"setqget",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setqget},
    {"ofsf_surep",              TOO_FEW_2,      CC_ofsf_surep, WRONG_NO_2},
    {"ibalp_negatet",           CC_ibalp_negatet,TOO_MANY_1,   WRONG_NO_1},
    {"reln",                    TOO_FEW_2,      CC_reln,       WRONG_NO_2},
    {"diffsq",                  TOO_FEW_2,      CC_diffsq,     WRONG_NO_2},
    {"xdegreecheck",            CC_xdegreecheck,TOO_MANY_1,    WRONG_NO_1},
    {"physopsm*",               CC_physopsmH,   TOO_MANY_1,    WRONG_NO_1},
    {"prepd1",                  CC_prepd1,      TOO_MANY_1,    WRONG_NO_1},
    {"ad_numsort",              CC_ad_numsort,  TOO_MANY_1,    WRONG_NO_1},
    {"lambda_ygm6np4pcqv31",    TOO_FEW_2,      CC_lambda_ygm6np4pcqv31,WRONG_NO_2},
    {"rlis",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rlis},
    {"ibalp_isinminclause",     TOO_FEW_2,      CC_ibalp_isinminclause,WRONG_NO_2},
    {"**a2s",                   TOO_FEW_2,      CC_HHa2s,      WRONG_NO_2},
    {"ps:prepfn:",              CC_psTprepfnT,  TOO_MANY_1,    WRONG_NO_1},
    {"dm-minus",                CC_dmKminus,    TOO_MANY_1,    WRONG_NO_1},
    {"groebcplistsortin1",      TOO_FEW_2,      CC_groebcplistsortin1,WRONG_NO_2},
    {"bytelist2id",             CC_bytelist2id, TOO_MANY_1,    WRONG_NO_1},
    {"gfdot",                   TOO_FEW_2,      CC_gfdot,      WRONG_NO_2},
    {"rdcos*",                  CC_rdcosH,      TOO_MANY_1,    WRONG_NO_1},
    {"mkfortterpri",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mkfortterpri},
    {"trwrite",                 CC_trwrite,     TOO_MANY_1,    WRONG_NO_1},
    {"one-entry-listp",         TOO_FEW_2,      CC_oneKentryKlistp,WRONG_NO_2},
    {"fs:times",                TOO_FEW_2,      CC_fsTtimes,   WRONG_NO_2},
    {"moid_member",             TOO_FEW_2,      CC_moid_member,WRONG_NO_2},
    {"splitlist:",              TOO_FEW_2,      CC_splitlistT, WRONG_NO_2},
    {"resimpf",                 CC_resimpf,     TOO_MANY_1,    WRONG_NO_1},
    {"gfk",                     WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gfk},
    {"gcref_mkgraph-tgf",       CC_gcref_mkgraphKtgf,TOO_MANY_1,WRONG_NO_1},
    {"rl_atnum",                CC_rl_atnum,    TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_subf",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_subf},
    {"simpexpt",                CC_simpexpt,    TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_var-set",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ibalp_varKset},
    {"inttovec1",               TOO_FEW_2,      CC_inttovec1,  WRONG_NO_2},
    {"collectphystype",         CC_collectphystype,TOO_MANY_1, WRONG_NO_1},
    {"replace1_parents",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_replace1_parents},
    {"repartf",                 CC_repartf,     TOO_MANY_1,    WRONG_NO_1},
    {"setelv",                  TOO_FEW_2,      CC_setelv,     WRONG_NO_2},
    {"red=cancelsimp",          TOO_FEW_2,      CC_redMcancelsimp,WRONG_NO_2},
    {"pst_termnodep",           CC_pst_termnodep,TOO_MANY_1,   WRONG_NO_1},
    {"ratn",                    CC_ratn,        TOO_MANY_1,    WRONG_NO_1},
    {"crprcd2",                 TOO_FEW_2,      CC_crprcd2,    WRONG_NO_2},
    {"innprodkp",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_innprodkp},
    {"ordered-gcd-mod-p",       TOO_FEW_2,      CC_orderedKgcdKmodKp,WRONG_NO_2},
    {"pairxvars",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pairxvars},
    {"monomwrite",              CC_monomwrite,  TOO_MANY_1,    WRONG_NO_1},
    {"super_der_simp",          CC_super_der_simp,TOO_MANY_1,  WRONG_NO_1},
    {"tayexp-times2",           TOO_FEW_2,      CC_tayexpKtimes2,WRONG_NO_2},
    {"get*elements",            CC_getHelements,TOO_MANY_1,    WRONG_NO_1},
    {"talp_subt",               TOO_FEW_2,      CC_talp_subt,  WRONG_NO_2},
    {"ibalp_readform",          CC_ibalp_readform,TOO_MANY_1,  WRONG_NO_1},
    {"vsl_boundtype",           TOO_FEW_2,      CC_vsl_boundtype,WRONG_NO_2},
    {NULL, (one_args *)"u22", (two_args *)"122006 2917369 1019535", 0}
};

// end of generated code
