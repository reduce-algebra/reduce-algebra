
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



// Code for dipcondense

static LispObject CC_dipcondense(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12426, v_12427;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12334);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_12334;
// end of prologue
    v_12426 = qvalue(elt(env, 2)); // dipevlist!*
    stack[-3] = v_12426;
v_12344:
    v_12426 = stack[-2];
    if (v_12426 == nil) goto v_12347;
    else goto v_12348;
v_12347:
    goto v_12343;
v_12348:
    v_12426 = stack[-2];
    v_12426 = qcar(v_12426);
    stack[-1] = v_12426;
v_12355:
    v_12426 = stack[-3];
    v_12426 = qcdr(v_12426);
    if (v_12426 == nil) goto v_12358;
    goto v_12369;
v_12365:
    v_12426 = stack[-2];
    v_12427 = qcar(v_12426);
    goto v_12366;
v_12367:
    v_12426 = stack[-3];
    v_12426 = qcdr(v_12426);
    v_12426 = qcar(v_12426);
    goto v_12368;
v_12369:
    goto v_12365;
v_12366:
    goto v_12367;
v_12368:
    fn = elt(env, 3); // evcompless!?
    v_12426 = (*qfn2(fn))(fn, v_12427, v_12426);
    env = stack[-4];
    if (v_12426 == nil) goto v_12358;
    goto v_12359;
v_12358:
    goto v_12354;
v_12359:
    v_12426 = stack[-3];
    v_12426 = qcdr(v_12426);
    stack[-3] = v_12426;
    goto v_12355;
v_12354:
    v_12426 = stack[-3];
    v_12426 = qcdr(v_12426);
    if (v_12426 == nil) goto v_12381;
    goto v_12390;
v_12386:
    v_12427 = stack[-1];
    goto v_12387;
v_12388:
    v_12426 = stack[-3];
    v_12426 = qcdr(v_12426);
    v_12426 = qcar(v_12426);
    goto v_12389;
v_12390:
    goto v_12386;
v_12387:
    goto v_12388;
v_12389:
    if (equal(v_12427, v_12426)) goto v_12385;
    else goto v_12381;
v_12385:
    goto v_12400;
v_12396:
    v_12427 = stack[-2];
    goto v_12397;
v_12398:
    v_12426 = stack[-3];
    v_12426 = qcdr(v_12426);
    v_12426 = qcar(v_12426);
    goto v_12399;
v_12400:
    goto v_12396;
v_12397:
    goto v_12398;
v_12399:
    fn = elt(env, 4); // setcar
    v_12426 = (*qfn2(fn))(fn, v_12427, v_12426);
    env = stack[-4];
    goto v_12379;
v_12381:
    goto v_12412;
v_12408:
    stack[0] = stack[-3];
    goto v_12409;
v_12410:
    goto v_12419;
v_12415:
    v_12427 = stack[-1];
    goto v_12416;
v_12417:
    v_12426 = stack[-3];
    v_12426 = qcdr(v_12426);
    goto v_12418;
v_12419:
    goto v_12415;
v_12416:
    goto v_12417;
v_12418:
    v_12426 = cons(v_12427, v_12426);
    env = stack[-4];
    goto v_12411;
v_12412:
    goto v_12408;
v_12409:
    goto v_12410;
v_12411:
    fn = elt(env, 5); // setcdr
    v_12426 = (*qfn2(fn))(fn, stack[0], v_12426);
    env = stack[-4];
    goto v_12379;
v_12379:
    v_12426 = stack[-2];
    v_12426 = qcdr(v_12426);
    v_12426 = qcdr(v_12426);
    stack[-2] = v_12426;
    goto v_12344;
v_12343:
    v_12426 = nil;
    return onevalue(v_12426);
}



// Code for expvec2a

static LispObject CC_expvec2a(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12344, v_12345;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12344 = v_12334;
// end of prologue
    goto v_12341;
v_12337:
    v_12345 = v_12344;
    goto v_12338;
v_12339:
    v_12344 = qvalue(elt(env, 1)); // dipvars!*
    goto v_12340;
v_12341:
    goto v_12337;
v_12338:
    goto v_12339;
v_12340:
    {
        fn = elt(env, 2); // expvec2a1
        return (*qfn2(fn))(fn, v_12345, v_12344);
    }
}



// Code for indexvarordp

static LispObject CC_indexvarordp(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12452, v_12453;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12335;
    stack[-1] = v_12334;
// end of prologue
    goto v_12349;
v_12345:
    v_12452 = stack[-1];
    v_12453 = qcar(v_12452);
    goto v_12346;
v_12347:
    v_12452 = stack[0];
    v_12452 = qcar(v_12452);
    goto v_12348;
v_12349:
    goto v_12345;
v_12346:
    goto v_12347;
v_12348:
    if (v_12453 == v_12452) goto v_12344;
    v_12452 = lisp_true;
    goto v_12342;
v_12344:
    goto v_12364;
v_12360:
    v_12453 = stack[-1];
    goto v_12361;
v_12362:
    v_12452 = qvalue(elt(env, 1)); // kord!*
    goto v_12363;
v_12364:
    goto v_12360;
v_12361:
    goto v_12362;
v_12363:
    v_12452 = Lmemq(nil, v_12453, v_12452);
    if (v_12452 == nil) goto v_12359;
    else goto v_12358;
v_12359:
    goto v_12372;
v_12368:
    v_12453 = stack[0];
    goto v_12369;
v_12370:
    v_12452 = qvalue(elt(env, 1)); // kord!*
    goto v_12371;
v_12372:
    goto v_12368;
v_12369:
    goto v_12370;
v_12371:
    v_12452 = Lmemq(nil, v_12453, v_12452);
v_12358:
    goto v_12342;
    v_12452 = nil;
v_12342:
    if (v_12452 == nil) goto v_12340;
    goto v_12381;
v_12377:
    v_12453 = stack[-1];
    goto v_12378;
v_12379:
    v_12452 = stack[0];
    goto v_12380;
v_12381:
    goto v_12377;
v_12378:
    goto v_12379;
v_12380:
    {
        fn = elt(env, 3); // ordop
        return (*qfn2(fn))(fn, v_12453, v_12452);
    }
v_12340:
    v_12452 = stack[-1];
    v_12452 = qcdr(v_12452);
    fn = elt(env, 4); // flatindxl
    stack[-2] = (*qfn1(fn))(fn, v_12452);
    env = stack[-3];
    v_12452 = stack[0];
    v_12452 = qcdr(v_12452);
    fn = elt(env, 4); // flatindxl
    v_12453 = (*qfn1(fn))(fn, v_12452);
    env = stack[-3];
    v_12452 = stack[-2];
    stack[-2] = v_12453;
    goto v_12403;
v_12399:
    v_12453 = v_12452;
    goto v_12400;
v_12401:
    v_12452 = qvalue(elt(env, 2)); // indxl!*
    goto v_12402;
v_12403:
    goto v_12399;
v_12400:
    goto v_12401;
v_12402:
    fn = elt(env, 5); // boundindp
    v_12452 = (*qfn2(fn))(fn, v_12453, v_12452);
    env = stack[-3];
    if (v_12452 == nil) goto v_12397;
    goto v_12415;
v_12411:
    v_12453 = stack[-2];
    goto v_12412;
v_12413:
    v_12452 = qvalue(elt(env, 2)); // indxl!*
    goto v_12414;
v_12415:
    goto v_12411;
v_12412:
    goto v_12413;
v_12414:
    fn = elt(env, 5); // boundindp
    v_12452 = (*qfn2(fn))(fn, v_12453, v_12452);
    env = stack[-3];
    if (v_12452 == nil) goto v_12409;
    goto v_12423;
v_12419:
    v_12452 = stack[-1];
    v_12453 = qcdr(v_12452);
    goto v_12420;
v_12421:
    v_12452 = stack[0];
    v_12452 = qcdr(v_12452);
    goto v_12422;
v_12423:
    goto v_12419;
v_12420:
    goto v_12421;
v_12422:
    {
        fn = elt(env, 6); // indordlp
        return (*qfn2(fn))(fn, v_12453, v_12452);
    }
v_12409:
    v_12452 = lisp_true;
    goto v_12407;
    v_12452 = nil;
v_12407:
    goto v_12395;
v_12397:
    goto v_12438;
v_12434:
    v_12453 = stack[-2];
    goto v_12435;
v_12436:
    v_12452 = qvalue(elt(env, 2)); // indxl!*
    goto v_12437;
v_12438:
    goto v_12434;
v_12435:
    goto v_12436;
v_12437:
    fn = elt(env, 5); // boundindp
    v_12452 = (*qfn2(fn))(fn, v_12453, v_12452);
    env = stack[-3];
    if (v_12452 == nil) goto v_12432;
    v_12452 = nil;
    goto v_12395;
v_12432:
    goto v_12449;
v_12445:
    v_12453 = stack[-1];
    goto v_12446;
v_12447:
    v_12452 = stack[0];
    goto v_12448;
v_12449:
    goto v_12445;
v_12446:
    goto v_12447;
v_12448:
    {
        fn = elt(env, 3); // ordop
        return (*qfn2(fn))(fn, v_12453, v_12452);
    }
    v_12452 = nil;
v_12395:
    goto v_12338;
    v_12452 = nil;
v_12338:
    return onevalue(v_12452);
}



// Code for inttovec!-solve

static LispObject CC_inttovecKsolve(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12437, v_12438;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_12335;
    stack[-3] = v_12334;
// end of prologue
    goto v_12349;
v_12345:
    v_12438 = stack[-2];
    goto v_12346;
v_12347:
    v_12437 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12348;
v_12349:
    goto v_12345;
v_12346:
    goto v_12347;
v_12348:
    if (v_12438 == v_12437) goto v_12343;
    else goto v_12344;
v_12343:
    v_12437 = lisp_true;
    goto v_12342;
v_12344:
    goto v_12359;
v_12355:
    v_12438 = stack[-3];
    goto v_12356;
v_12357:
    v_12437 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12358;
v_12359:
    goto v_12355;
v_12356:
    goto v_12357;
v_12358:
    v_12437 = (v_12438 == v_12437 ? lisp_true : nil);
    goto v_12342;
    v_12437 = nil;
v_12342:
    if (v_12437 == nil) goto v_12340;
    goto v_12368;
v_12364:
    v_12438 = stack[-2];
    goto v_12365;
v_12366:
    v_12437 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12367;
v_12368:
    goto v_12364;
v_12365:
    goto v_12366;
v_12367:
    return cons(v_12438, v_12437);
v_12340:
    v_12437 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_12437;
    v_12437 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_12437;
v_12383:
    v_12437 = stack[0];
    stack[-1] = v_12437;
    v_12437 = stack[-4];
    v_12437 = add1(v_12437);
    env = stack[-5];
    stack[-4] = v_12437;
    goto v_12392;
v_12388:
    goto v_12398;
v_12394:
    goto v_12404;
v_12400:
    v_12438 = stack[-3];
    goto v_12401;
v_12402:
    v_12437 = stack[-4];
    goto v_12403;
v_12404:
    goto v_12400;
v_12401:
    goto v_12402;
v_12403:
    v_12438 = plus2(v_12438, v_12437);
    env = stack[-5];
    goto v_12395;
v_12396:
    v_12437 = stack[-1];
    goto v_12397;
v_12398:
    goto v_12394;
v_12395:
    goto v_12396;
v_12397:
    v_12438 = times2(v_12438, v_12437);
    env = stack[-5];
    goto v_12389;
v_12390:
    v_12437 = stack[-4];
    goto v_12391;
v_12392:
    goto v_12388;
v_12389:
    goto v_12390;
v_12391:
    v_12437 = quot2(v_12438, v_12437);
    env = stack[-5];
    stack[0] = v_12437;
    goto v_12419;
v_12415:
    v_12438 = stack[0];
    goto v_12416;
v_12417:
    v_12437 = stack[-2];
    goto v_12418;
v_12419:
    goto v_12415;
v_12416:
    goto v_12417;
v_12418:
    v_12437 = (LispObject)greaterp2(v_12438, v_12437);
    v_12437 = v_12437 ? lisp_true : nil;
    env = stack[-5];
    if (v_12437 == nil) goto v_12412;
    else goto v_12413;
v_12412:
    goto v_12383;
v_12413:
    goto v_12427;
v_12423:
    stack[0] = stack[-4];
    goto v_12424;
v_12425:
    goto v_12434;
v_12430:
    v_12438 = stack[-2];
    goto v_12431;
v_12432:
    v_12437 = stack[-1];
    goto v_12433;
v_12434:
    goto v_12430;
v_12431:
    goto v_12432;
v_12433:
    v_12437 = difference2(v_12438, v_12437);
    goto v_12426;
v_12427:
    goto v_12423;
v_12424:
    goto v_12425;
v_12426:
    {
        LispObject v_12444 = stack[0];
        return cons(v_12444, v_12437);
    }
    goto v_12338;
    v_12437 = nil;
v_12338:
    return onevalue(v_12437);
}



// Code for lispassignp

static LispObject CC_lispassignp(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12344, v_12345;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12344 = v_12334;
// end of prologue
    goto v_12341;
v_12337:
    goto v_12338;
v_12339:
    v_12345 = elt(env, 1); // setq
    goto v_12340;
v_12341:
    goto v_12337;
v_12338:
    goto v_12339;
v_12340:
        return Leqcar(nil, v_12344, v_12345);
}



// Code for nfactorial

static LispObject CC_nfactorial(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12393, v_12394;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12334);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_12334;
// end of prologue
    goto v_12345;
v_12341:
    v_12394 = stack[-1];
    goto v_12342;
v_12343:
    v_12393 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_12344;
v_12345:
    goto v_12341;
v_12342:
    goto v_12343;
v_12344:
    v_12393 = (LispObject)greaterp2(v_12394, v_12393);
    v_12393 = v_12393 ? lisp_true : nil;
    env = stack[-3];
    if (v_12393 == nil) goto v_12339;
    goto v_12353;
v_12349:
    v_12394 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12350;
v_12351:
    v_12393 = stack[-1];
    goto v_12352;
v_12353:
    goto v_12349;
v_12350:
    goto v_12351;
v_12352:
    {
        fn = elt(env, 2); // fac!-part
        return (*qfn2(fn))(fn, v_12394, v_12393);
    }
v_12339:
    v_12393 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_12393;
    v_12393 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_12393;
v_12366:
    goto v_12378;
v_12374:
    v_12394 = stack[-1];
    goto v_12375;
v_12376:
    v_12393 = stack[0];
    goto v_12377;
v_12378:
    goto v_12374;
v_12375:
    goto v_12376;
v_12377:
    v_12393 = difference2(v_12394, v_12393);
    env = stack[-3];
    v_12393 = Lminusp(nil, v_12393);
    env = stack[-3];
    if (v_12393 == nil) goto v_12371;
    goto v_12365;
v_12371:
    goto v_12387;
v_12383:
    v_12394 = stack[-2];
    goto v_12384;
v_12385:
    v_12393 = stack[0];
    goto v_12386;
v_12387:
    goto v_12383;
v_12384:
    goto v_12385;
v_12386:
    v_12393 = times2(v_12394, v_12393);
    env = stack[-3];
    stack[-2] = v_12393;
    v_12393 = stack[0];
    v_12393 = add1(v_12393);
    env = stack[-3];
    stack[0] = v_12393;
    goto v_12366;
v_12365:
    v_12393 = stack[-2];
    goto v_12337;
    v_12393 = nil;
v_12337:
    return onevalue(v_12393);
}



// Code for lpriw

static LispObject CC_lpriw(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12399, v_12400;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_12400 = v_12335;
    stack[0] = v_12334;
// end of prologue
    goto v_12345;
v_12341:
    goto v_12342;
v_12343:
    v_12399 = v_12400;
    if (v_12399 == nil) goto v_12350;
    v_12399 = v_12400;
    if (!consp(v_12399)) goto v_12353;
    else goto v_12350;
v_12353:
    v_12399 = v_12400;
    v_12399 = ncons(v_12399);
    env = stack[-1];
    goto v_12348;
v_12350:
    v_12399 = v_12400;
    goto v_12348;
    v_12399 = nil;
v_12348:
    goto v_12344;
v_12345:
    goto v_12341;
v_12342:
    goto v_12343;
v_12344:
    v_12399 = cons(stack[0], v_12399);
    env = stack[-1];
    stack[0] = v_12399;
    v_12399 = qvalue(elt(env, 1)); // ofl!*
    if (v_12399 == nil) goto v_12362;
    else goto v_12363;
v_12362:
    v_12399 = Lterpri(nil, 0);
    env = stack[-1];
    v_12399 = stack[0];
    fn = elt(env, 5); // lpri
    v_12399 = (*qfn1(fn))(fn, v_12399);
    env = stack[-1];
    v_12399 = Lterpri(nil, 0);
    goto v_12361;
v_12363:
    v_12399 = qvalue(elt(env, 2)); // !*fort
    if (v_12399 == nil) goto v_12375;
    else goto v_12374;
v_12375:
    v_12399 = qvalue(elt(env, 3)); // !*nat
    if (v_12399 == nil) goto v_12380;
    else goto v_12381;
v_12380:
    v_12399 = lisp_true;
    goto v_12379;
v_12381:
    v_12399 = qvalue(elt(env, 4)); // !*defn
    goto v_12379;
    v_12399 = nil;
v_12379:
    if (v_12399 == nil) goto v_12377;
    else goto v_12374;
v_12377:
    v_12399 = Lterpri(nil, 0);
    env = stack[-1];
    v_12399 = stack[0];
    fn = elt(env, 5); // lpri
    v_12399 = (*qfn1(fn))(fn, v_12399);
    env = stack[-1];
    v_12399 = Lterpri(nil, 0);
    env = stack[-1];
    goto v_12372;
v_12374:
v_12372:
    v_12399 = nil;
    v_12399 = Lwrs(nil, v_12399);
    env = stack[-1];
    v_12399 = stack[0];
    fn = elt(env, 5); // lpri
    v_12399 = (*qfn1(fn))(fn, v_12399);
    env = stack[-1];
    v_12399 = Lterpri(nil, 0);
    env = stack[-1];
    v_12399 = qvalue(elt(env, 1)); // ofl!*
    v_12399 = qcdr(v_12399);
    v_12399 = Lwrs(nil, v_12399);
    goto v_12361;
v_12361:
    v_12399 = nil;
    return onevalue(v_12399);
}



// Code for cde_delete

static LispObject CC_cde_delete(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12378, v_12379, v_12380, v_12381;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_12378 = v_12335;
    stack[0] = v_12334;
// end of prologue
    v_12381 = nil;
    stack[-1] = v_12378;
v_12344:
    v_12378 = stack[-1];
    if (v_12378 == nil) goto v_12348;
    else goto v_12349;
v_12348:
    goto v_12343;
v_12349:
    v_12378 = stack[-1];
    v_12378 = qcar(v_12378);
    v_12380 = v_12378;
    goto v_12363;
v_12359:
    v_12379 = v_12380;
    goto v_12360;
v_12361:
    v_12378 = stack[0];
    goto v_12362;
v_12363:
    goto v_12359;
v_12360:
    goto v_12361;
v_12362:
    if (equal(v_12379, v_12378)) goto v_12358;
    goto v_12371;
v_12367:
    v_12378 = v_12380;
    goto v_12368;
v_12369:
    v_12379 = v_12381;
    goto v_12370;
v_12371:
    goto v_12367;
v_12368:
    goto v_12369;
v_12370:
    v_12378 = cons(v_12378, v_12379);
    env = stack[-2];
    v_12381 = v_12378;
    goto v_12356;
v_12358:
v_12356:
    v_12378 = stack[-1];
    v_12378 = qcdr(v_12378);
    stack[-1] = v_12378;
    goto v_12344;
v_12343:
    v_12378 = v_12381;
        return Lnreverse(nil, v_12378);
    return onevalue(v_12378);
}



// Code for sfto_dgcd

static LispObject CC_sfto_dgcd(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12365, v_12366;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12335;
    v_12365 = v_12334;
// end of prologue
    fn = elt(env, 2); // sfto_dcontentf
    v_12365 = (*qfn1(fn))(fn, v_12365);
    env = stack[-2];
    stack[-1] = v_12365;
    goto v_12352;
v_12348:
    v_12366 = stack[-1];
    goto v_12349;
v_12350:
    v_12365 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12351;
v_12352:
    goto v_12348;
v_12349:
    goto v_12350;
v_12351:
    v_12365 = Leqn(nil, v_12366, v_12365);
    env = stack[-2];
    if (v_12365 == nil) goto v_12346;
    v_12365 = stack[-1];
    goto v_12339;
v_12346:
    goto v_12361;
v_12357:
    goto v_12358;
v_12359:
    v_12365 = stack[0];
    fn = elt(env, 2); // sfto_dcontentf
    v_12365 = (*qfn1(fn))(fn, v_12365);
    env = stack[-2];
    goto v_12360;
v_12361:
    goto v_12357;
v_12358:
    goto v_12359;
v_12360:
    {
        LispObject v_12369 = stack[-1];
        fn = elt(env, 3); // sfto_gcdf
        return (*qfn2(fn))(fn, v_12369, v_12365);
    }
v_12339:
    return onevalue(v_12365);
}



// Code for traput

static LispObject CC_traput(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12399, v_12400, v_12401, v_12402, v_12403;
    LispObject v_12336, v_12335, v_12334;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "traput");
    va_start(aa, nargs);
    v_12334 = va_arg(aa, LispObject);
    v_12335 = va_arg(aa, LispObject);
    v_12336 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12336,v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12334,v_12335,v_12336);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_12400 = v_12336;
    v_12401 = v_12335;
    v_12402 = v_12334;
// end of prologue
    goto v_12351;
v_12347:
    v_12403 = v_12402;
    goto v_12348;
v_12349:
    v_12399 = v_12401;
    goto v_12350;
v_12351:
    goto v_12347;
v_12348:
    goto v_12349;
v_12350:
    v_12399 = get(v_12403, v_12399);
    env = stack[-2];
    v_12403 = v_12399;
    if (v_12399 == nil) goto v_12345;
    v_12399 = qvalue(elt(env, 2)); // toplv!*
    if (v_12399 == nil) goto v_12358;
    else goto v_12357;
v_12358:
    goto v_12365;
v_12361:
    v_12401 = v_12400;
    goto v_12362;
v_12363:
    v_12399 = v_12403;
    goto v_12364;
v_12365:
    goto v_12361;
v_12362:
    goto v_12363;
v_12364:
    v_12399 = Lmemq(nil, v_12401, v_12399);
    if (v_12399 == nil) goto v_12360;
    else goto v_12357;
v_12360:
    goto v_12374;
v_12370:
    stack[0] = v_12403;
    goto v_12371;
v_12372:
    goto v_12381;
v_12377:
    v_12399 = v_12400;
    goto v_12378;
v_12379:
    v_12400 = v_12403;
    v_12400 = qcdr(v_12400);
    goto v_12380;
v_12381:
    goto v_12377;
v_12378:
    goto v_12379;
v_12380:
    v_12399 = cons(v_12399, v_12400);
    env = stack[-2];
    goto v_12373;
v_12374:
    goto v_12370;
v_12371:
    goto v_12372;
v_12373:
    v_12399 = Lrplacd(nil, stack[0], v_12399);
    goto v_12355;
v_12357:
v_12355:
    goto v_12343;
v_12345:
    goto v_12394;
v_12388:
    stack[-1] = v_12402;
    goto v_12389;
v_12390:
    stack[0] = v_12401;
    goto v_12391;
v_12392:
    v_12399 = v_12400;
    v_12399 = ncons(v_12399);
    env = stack[-2];
    goto v_12393;
v_12394:
    goto v_12388;
v_12389:
    goto v_12390;
v_12391:
    goto v_12392;
v_12393:
    v_12399 = Lputprop(nil, 3, stack[-1], stack[0], v_12399);
    goto v_12343;
v_12343:
    v_12399 = nil;
    return onevalue(v_12399);
}



// Code for cl_atl

static LispObject CC_cl_atl(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12345, v_12346;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12334);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12345 = v_12334;
// end of prologue
    goto v_12341;
v_12337:
    fn = elt(env, 2); // cl_atl1
    v_12346 = (*qfn1(fn))(fn, v_12345);
    env = stack[0];
    goto v_12338;
v_12339:
    v_12345 = elt(env, 1); // rl_ordatp
    goto v_12340;
v_12341:
    goto v_12337;
v_12338:
    goto v_12339;
v_12340:
    {
        fn = elt(env, 3); // sort
        return (*qfn2(fn))(fn, v_12346, v_12345);
    }
}



// Code for diff!-over!-k!-mod!-p

static LispObject CC_diffKoverKkKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12509, v_12510, v_12511;
    LispObject fn;
    LispObject v_12336, v_12335, v_12334;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "diff-over-k-mod-p");
    va_start(aa, nargs);
    v_12334 = va_arg(aa, LispObject);
    v_12335 = va_arg(aa, LispObject);
    v_12336 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12336,v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12334,v_12335,v_12336);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_12336;
    stack[-1] = v_12335;
    stack[-2] = v_12334;
// end of prologue
    v_12509 = stack[-2];
    if (!consp(v_12509)) goto v_12344;
    else goto v_12345;
v_12344:
    v_12509 = lisp_true;
    goto v_12343;
v_12345:
    v_12509 = stack[-2];
    v_12509 = qcar(v_12509);
    v_12509 = (consp(v_12509) ? nil : lisp_true);
    goto v_12343;
    v_12509 = nil;
v_12343:
    if (v_12509 == nil) goto v_12341;
    v_12509 = nil;
    goto v_12339;
v_12341:
    goto v_12360;
v_12356:
    v_12509 = stack[-2];
    v_12509 = qcar(v_12509);
    v_12509 = qcar(v_12509);
    v_12510 = qcar(v_12509);
    goto v_12357;
v_12358:
    v_12509 = stack[0];
    goto v_12359;
v_12360:
    goto v_12356;
v_12357:
    goto v_12358;
v_12359:
    if (equal(v_12510, v_12509)) goto v_12354;
    else goto v_12355;
v_12354:
    goto v_12374;
v_12370:
    v_12509 = stack[-2];
    v_12509 = qcar(v_12509);
    v_12509 = qcar(v_12509);
    v_12510 = qcdr(v_12509);
    goto v_12371;
v_12372:
    v_12509 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12373;
v_12374:
    goto v_12370;
v_12371:
    goto v_12372;
v_12373:
    if (v_12510 == v_12509) goto v_12368;
    else goto v_12369;
v_12368:
    goto v_12385;
v_12381:
    v_12509 = stack[-2];
    v_12509 = qcar(v_12509);
    v_12510 = qcdr(v_12509);
    goto v_12382;
v_12383:
    v_12509 = stack[-1];
    v_12509 = Lmodular_number(nil, v_12509);
    env = stack[-4];
    goto v_12384;
v_12385:
    goto v_12381;
v_12382:
    goto v_12383;
v_12384:
    {
        fn = elt(env, 1); // quotfail!-mod!-p
        return (*qfn2(fn))(fn, v_12510, v_12509);
    }
v_12369:
    goto v_12398;
v_12394:
    goto v_12404;
v_12400:
    v_12509 = stack[-2];
    v_12509 = qcar(v_12509);
    v_12509 = qcar(v_12509);
    v_12509 = qcdr(v_12509);
    v_12510 = Lmodular_number(nil, v_12509);
    env = stack[-4];
    goto v_12401;
v_12402:
    v_12509 = stack[-2];
    v_12509 = qcar(v_12509);
    v_12509 = qcdr(v_12509);
    goto v_12403;
v_12404:
    goto v_12400;
v_12401:
    goto v_12402;
v_12403:
    fn = elt(env, 2); // times!-mod!-p
    v_12510 = (*qfn2(fn))(fn, v_12510, v_12509);
    env = stack[-4];
    goto v_12395;
v_12396:
    v_12509 = stack[-1];
    v_12509 = Lmodular_number(nil, v_12509);
    env = stack[-4];
    goto v_12397;
v_12398:
    goto v_12394;
v_12395:
    goto v_12396;
v_12397:
    fn = elt(env, 1); // quotfail!-mod!-p
    stack[-3] = (*qfn2(fn))(fn, v_12510, v_12509);
    env = stack[-4];
    goto v_12422;
v_12416:
    v_12509 = stack[-2];
    v_12511 = qcdr(v_12509);
    goto v_12417;
v_12418:
    v_12510 = stack[-1];
    goto v_12419;
v_12420:
    v_12509 = stack[0];
    goto v_12421;
v_12422:
    goto v_12416;
v_12417:
    goto v_12418;
v_12419:
    goto v_12420;
v_12421:
    v_12509 = CC_diffKoverKkKmodKp(elt(env, 0), 3, v_12511, v_12510, v_12509);
    env = stack[-4];
    stack[-1] = v_12509;
    v_12509 = stack[-3];
    if (v_12509 == nil) goto v_12431;
    else goto v_12432;
v_12431:
    v_12509 = stack[-1];
    goto v_12430;
v_12432:
    goto v_12444;
v_12438:
    goto v_12450;
v_12446:
    v_12510 = stack[0];
    goto v_12447;
v_12448:
    v_12509 = stack[-2];
    v_12509 = qcar(v_12509);
    v_12509 = qcar(v_12509);
    v_12509 = qcdr(v_12509);
    v_12509 = (LispObject)((intptr_t)(v_12509) - 0x10);
    goto v_12449;
v_12450:
    goto v_12446;
v_12447:
    goto v_12448;
v_12449:
    fn = elt(env, 3); // mksp
    v_12511 = (*qfn2(fn))(fn, v_12510, v_12509);
    goto v_12439;
v_12440:
    v_12510 = stack[-3];
    goto v_12441;
v_12442:
    v_12509 = stack[-1];
    goto v_12443;
v_12444:
    goto v_12438;
v_12439:
    goto v_12440;
v_12441:
    goto v_12442;
v_12443:
    return acons(v_12511, v_12510, v_12509);
    v_12509 = nil;
v_12430:
    goto v_12367;
    v_12509 = nil;
v_12367:
    goto v_12339;
v_12355:
    goto v_12468;
v_12462:
    v_12509 = stack[-2];
    v_12509 = qcar(v_12509);
    v_12511 = qcdr(v_12509);
    goto v_12463;
v_12464:
    v_12510 = stack[-1];
    goto v_12465;
v_12466:
    v_12509 = stack[0];
    goto v_12467;
v_12468:
    goto v_12462;
v_12463:
    goto v_12464;
v_12465:
    goto v_12466;
v_12467:
    stack[-3] = CC_diffKoverKkKmodKp(elt(env, 0), 3, v_12511, v_12510, v_12509);
    env = stack[-4];
    goto v_12481;
v_12475:
    v_12509 = stack[-2];
    v_12511 = qcdr(v_12509);
    goto v_12476;
v_12477:
    v_12510 = stack[-1];
    goto v_12478;
v_12479:
    v_12509 = stack[0];
    goto v_12480;
v_12481:
    goto v_12475;
v_12476:
    goto v_12477;
v_12478:
    goto v_12479;
v_12480:
    v_12509 = CC_diffKoverKkKmodKp(elt(env, 0), 3, v_12511, v_12510, v_12509);
    v_12510 = stack[-3];
    v_12511 = v_12510;
    if (v_12511 == nil) goto v_12490;
    else goto v_12491;
v_12490:
    goto v_12489;
v_12491:
    goto v_12503;
v_12497:
    v_12511 = stack[-2];
    v_12511 = qcar(v_12511);
    v_12511 = qcar(v_12511);
    goto v_12498;
v_12499:
    goto v_12500;
v_12501:
    goto v_12502;
v_12503:
    goto v_12497;
v_12498:
    goto v_12499;
v_12500:
    goto v_12501;
v_12502:
    return acons(v_12511, v_12510, v_12509);
    v_12509 = nil;
v_12489:
    goto v_12339;
    v_12509 = nil;
v_12339:
    return onevalue(v_12509);
}



// Code for testredzz

static LispObject CC_testredzz(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12376, v_12377;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12334);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_12376 = v_12334;
// end of prologue
    goto v_12344;
v_12340:
    goto v_12349;
v_12345:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_12346;
v_12347:
    goto v_12356;
v_12352:
    v_12377 = qvalue(elt(env, 2)); // maxvar
    goto v_12353;
v_12354:
    goto v_12355;
v_12356:
    goto v_12352;
v_12353:
    goto v_12354;
v_12355:
    v_12376 = plus2(v_12377, v_12376);
    env = stack[-1];
    goto v_12348;
v_12349:
    goto v_12345;
v_12346:
    goto v_12347;
v_12348:
    v_12377 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_12376-TAG_FIXNUM)/(16/CELL)));
    goto v_12341;
v_12342:
    v_12376 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_12343;
v_12344:
    goto v_12340;
v_12341:
    goto v_12342;
v_12343:
    v_12376 = *(LispObject *)((char *)v_12377 + (CELL-TAG_VECTOR) + (((intptr_t)v_12376-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_12376;
v_12339:
    v_12376 = stack[0];
    if (v_12376 == nil) goto v_12364;
    else goto v_12365;
v_12364:
    v_12376 = nil;
    goto v_12338;
v_12365:
    v_12376 = stack[0];
    v_12376 = qcar(v_12376);
    v_12376 = qcar(v_12376);
    fn = elt(env, 3); // testredh
    v_12376 = (*qfn1(fn))(fn, v_12376);
    env = stack[-1];
    v_12376 = stack[0];
    v_12376 = qcdr(v_12376);
    stack[0] = v_12376;
    goto v_12339;
v_12338:
    return onevalue(v_12376);
}



// Code for dipevlcomp

static LispObject CC_dipevlcomp(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12348, v_12349;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
// copy arguments values to proper place
    v_12348 = v_12335;
    v_12349 = v_12334;
// end of prologue
    goto v_12342;
v_12338:
    v_12349 = qcar(v_12349);
    goto v_12339;
v_12340:
    v_12348 = qcar(v_12348);
    goto v_12341;
v_12342:
    goto v_12338;
v_12339:
    goto v_12340;
v_12341:
    fn = elt(env, 1); // evcompless!?
    v_12348 = (*qfn2(fn))(fn, v_12349, v_12348);
    v_12348 = (v_12348 == nil ? lisp_true : nil);
    return onevalue(v_12348);
}



// Code for indord2

static LispObject CC_indord2(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12367, v_12368;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_12335;
    stack[-1] = v_12334;
// end of prologue
    goto v_12346;
v_12342:
    v_12368 = stack[-1];
    goto v_12343;
v_12344:
    v_12367 = stack[0];
    goto v_12345;
v_12346:
    goto v_12342;
v_12343:
    goto v_12344;
v_12345:
    fn = elt(env, 1); // indordp
    v_12367 = (*qfn2(fn))(fn, v_12368, v_12367);
    if (v_12367 == nil) goto v_12340;
    goto v_12354;
v_12350:
    v_12368 = stack[-1];
    goto v_12351;
v_12352:
    v_12367 = stack[0];
    goto v_12353;
v_12354:
    goto v_12350;
v_12351:
    goto v_12352;
v_12353:
    return list2(v_12368, v_12367);
v_12340:
    goto v_12364;
v_12360:
    v_12368 = stack[0];
    goto v_12361;
v_12362:
    v_12367 = stack[-1];
    goto v_12363;
v_12364:
    goto v_12360;
v_12361:
    goto v_12362;
v_12363:
    return list2(v_12368, v_12367);
    v_12367 = nil;
    return onevalue(v_12367);
}



// Code for begin1a

static LispObject CC_begin1a(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12698, v_12699, v_12700;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12334);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12334;
// end of prologue
    v_12698 = Ltime(nil, 0);
    env = stack[-2];
    qvalue(elt(env, 2)) = v_12698; // otime!*
    v_12698 = elt(env, 3); // gctime
    fn = elt(env, 54); // getd
    v_12698 = (*qfn1(fn))(fn, v_12698);
    env = stack[-2];
    if (v_12698 == nil) goto v_12352;
    v_12698 = Lgctime(nil, 0);
    env = stack[-2];
    qvalue(elt(env, 4)) = v_12698; // ogctime!*
    goto v_12350;
v_12352:
    v_12698 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 4)) = v_12698; // ogctime!*
    goto v_12350;
v_12350:
    v_12698 = qvalue(elt(env, 2)); // otime!*
    qvalue(elt(env, 5)) = v_12698; // otime3!*
    qvalue(elt(env, 6)) = v_12698; // otime2!*
    qvalue(elt(env, 7)) = v_12698; // otime1!*
    v_12698 = qvalue(elt(env, 4)); // ogctime!*
    qvalue(elt(env, 8)) = v_12698; // ogctime3!*
    qvalue(elt(env, 9)) = v_12698; // ogctime2!*
    qvalue(elt(env, 10)) = v_12698; // ogctime1!*
    v_12698 = stack[0];
    qvalue(elt(env, 11)) = v_12698; // peekchar!*
    v_12698 = elt(env, 12); // !*semicol!*
    qvalue(elt(env, 13)) = v_12698; // cursym!*
    v_12698 = nil;
    qvalue(elt(env, 14)) = v_12698; // curescaped!*
v_12341:
    fn = elt(env, 55); // terminalp
    v_12698 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_12698 == nil) goto v_12367;
    v_12698 = qvalue(elt(env, 15)); // !*nosave!*
    if (v_12698 == nil) goto v_12373;
    else goto v_12371;
v_12373:
    goto v_12380;
v_12376:
    v_12699 = qvalue(elt(env, 16)); // statcounter
    goto v_12377;
v_12378:
    v_12698 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12379;
v_12380:
    goto v_12376;
v_12377:
    goto v_12378;
v_12379:
    if (v_12699 == v_12698) goto v_12371;
    goto v_12372;
v_12371:
    goto v_12370;
v_12372:
    fn = elt(env, 56); // add2buflis
    v_12698 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_12370;
v_12370:
    fn = elt(env, 57); // update_prompt
    v_12698 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_12365;
v_12367:
v_12365:
    v_12698 = nil;
    qvalue(elt(env, 15)) = v_12698; // !*nosave!*
    v_12698 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 17)) = v_12698; // !*strind
    v_12698 = nil;
    stack[-1] = v_12698;
    v_12698 = qvalue(elt(env, 18)); // !*time
    if (v_12698 == nil) goto v_12394;
    v_12698 = elt(env, 19); // (showtime nil)
    fn = elt(env, 58); // lispeval
    v_12698 = (*qfn1(fn))(fn, v_12698);
    env = stack[-2];
    goto v_12392;
v_12394:
v_12392:
    v_12698 = qvalue(elt(env, 20)); // !*output
    if (v_12698 == nil) goto v_12401;
    v_12698 = qvalue(elt(env, 21)); // ofl!*
    if (v_12698 == nil) goto v_12407;
    else goto v_12408;
v_12407:
    fn = elt(env, 55); // terminalp
    v_12698 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_12698 == nil) goto v_12412;
    else goto v_12413;
v_12412:
    v_12698 = nil;
    goto v_12411;
v_12413:
    v_12698 = qvalue(elt(env, 22)); // !*defn
    if (v_12698 == nil) goto v_12420;
    else goto v_12421;
v_12420:
    v_12698 = qvalue(elt(env, 23)); // !*lessspace
    v_12698 = (v_12698 == nil ? lisp_true : nil);
    goto v_12419;
v_12421:
    v_12698 = nil;
    goto v_12419;
    v_12698 = nil;
v_12419:
    goto v_12411;
    v_12698 = nil;
v_12411:
    goto v_12406;
v_12408:
    v_12698 = nil;
    goto v_12406;
    v_12698 = nil;
v_12406:
    if (v_12698 == nil) goto v_12401;
    v_12698 = Lterpri(nil, 0);
    env = stack[-2];
    goto v_12399;
v_12401:
v_12399:
    v_12698 = qvalue(elt(env, 24)); // tslin!*
    if (v_12698 == nil) goto v_12435;
    v_12698 = qvalue(elt(env, 24)); // tslin!*
    v_12698 = qcar(v_12698);
    qvalue(elt(env, 25)) = v_12698; // !*slin
    v_12698 = qvalue(elt(env, 24)); // tslin!*
    v_12698 = qcdr(v_12698);
    qvalue(elt(env, 26)) = v_12698; // lreadfn!*
    v_12698 = nil;
    qvalue(elt(env, 24)) = v_12698; // tslin!*
    goto v_12433;
v_12435:
v_12433:
    v_12698 = qvalue(elt(env, 27)); // initl!*
    stack[0] = v_12698;
v_12342:
    v_12698 = stack[0];
    if (v_12698 == nil) goto v_12446;
    v_12698 = stack[0];
    v_12698 = qcar(v_12698);
    fn = elt(env, 59); // sinitl
    v_12698 = (*qfn1(fn))(fn, v_12698);
    env = stack[-2];
    v_12698 = stack[0];
    v_12698 = qcdr(v_12698);
    stack[0] = v_12698;
    goto v_12342;
v_12446:
    goto v_12458;
v_12454:
    v_12699 = qvalue(elt(env, 28)); // forkeywords!*
    goto v_12455;
v_12456:
    v_12698 = elt(env, 29); // delim
    goto v_12457;
v_12458:
    goto v_12454;
v_12455:
    goto v_12456;
v_12457:
    v_12698 = Lremflag(nil, v_12699, v_12698);
    env = stack[-2];
    goto v_12466;
v_12462:
    v_12699 = qvalue(elt(env, 30)); // repeatkeywords!*
    goto v_12463;
v_12464:
    v_12698 = elt(env, 29); // delim
    goto v_12465;
v_12466:
    goto v_12462;
v_12463:
    goto v_12464;
v_12465:
    v_12698 = Lremflag(nil, v_12699, v_12698);
    env = stack[-2];
    goto v_12474;
v_12470:
    v_12699 = qvalue(elt(env, 31)); // whilekeywords!*
    goto v_12471;
v_12472:
    v_12698 = elt(env, 29); // delim
    goto v_12473;
v_12474:
    goto v_12470;
v_12471:
    goto v_12472;
v_12473:
    v_12698 = Lremflag(nil, v_12699, v_12698);
    env = stack[-2];
    v_12698 = qvalue(elt(env, 32)); // !*int
    if (v_12698 == nil) goto v_12480;
    v_12698 = nil;
    qvalue(elt(env, 33)) = v_12698; // erfg!*
    goto v_12478;
v_12480:
v_12478:
    goto v_12491;
v_12487:
    v_12699 = qvalue(elt(env, 13)); // cursym!*
    goto v_12488;
v_12489:
    v_12698 = elt(env, 34); // end
    goto v_12490;
v_12491:
    goto v_12487;
v_12488:
    goto v_12489;
v_12490:
    if (v_12699 == v_12698) goto v_12485;
    else goto v_12486;
v_12485:
    v_12698 = elt(env, 34); // end
    fn = elt(env, 60); // comm1
    v_12698 = (*qfn1(fn))(fn, v_12698);
    v_12698 = nil;
    goto v_12340;
v_12486:
    fn = elt(env, 55); // terminalp
    v_12698 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_12698 == nil) goto v_12498;
    goto v_12506;
v_12502:
    v_12699 = qvalue(elt(env, 35)); // key!*
    goto v_12503;
v_12504:
    v_12698 = elt(env, 36); // ed
    goto v_12505;
v_12506:
    goto v_12502;
v_12503:
    goto v_12504;
v_12505:
    if (v_12699 == v_12698) goto v_12498;
    v_12698 = qvalue(elt(env, 37)); // promptexp!*
    fn = elt(env, 61); // printprompt
    v_12698 = (*qfn1(fn))(fn, v_12698);
    env = stack[-2];
    goto v_12484;
v_12498:
v_12484:
    goto v_12516;
v_12512:
    v_12699 = elt(env, 38); // (command)
    goto v_12513;
v_12514:
    v_12698 = lisp_true;
    goto v_12515;
v_12516:
    goto v_12512;
v_12513:
    goto v_12514;
v_12515:
    fn = elt(env, 62); // errorset!*
    v_12698 = (*qfn2(fn))(fn, v_12699, v_12698);
    env = stack[-2];
    stack[0] = v_12698;
    fn = elt(env, 63); // condterpri
    v_12698 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_12698 = stack[0];
    fn = elt(env, 64); // errorp
    v_12698 = (*qfn1(fn))(fn, v_12698);
    env = stack[-2];
    if (v_12698 == nil) goto v_12523;
    goto v_12344;
v_12523:
    v_12698 = stack[0];
    v_12698 = qcar(v_12698);
    stack[0] = v_12698;
    goto v_12540;
v_12536:
    v_12698 = stack[0];
    v_12699 = qcar(v_12698);
    goto v_12537;
v_12538:
    v_12698 = elt(env, 39); // symbolic
    goto v_12539;
v_12540:
    goto v_12536;
v_12537:
    goto v_12538;
v_12539:
    if (v_12699 == v_12698) goto v_12534;
    else goto v_12535;
v_12534:
    goto v_12549;
v_12545:
    v_12698 = stack[0];
    v_12698 = qcdr(v_12698);
    v_12699 = qcar(v_12698);
    goto v_12546;
v_12547:
    v_12698 = elt(env, 40); // xmodule
    goto v_12548;
v_12549:
    goto v_12545;
v_12546:
    goto v_12547;
v_12548:
    v_12698 = Leqcar(nil, v_12699, v_12698);
    env = stack[-2];
    goto v_12533;
v_12535:
    v_12698 = nil;
    goto v_12533;
    v_12698 = nil;
v_12533:
    if (v_12698 == nil) goto v_12531;
    v_12698 = stack[0];
    v_12698 = qcdr(v_12698);
    v_12698 = qcar(v_12698);
    fn = elt(env, 65); // eval
    v_12698 = (*qfn1(fn))(fn, v_12698);
    env = stack[-2];
    fn = elt(env, 66); // xmodloop
    v_12698 = (*qfn1(fn))(fn, v_12698);
    env = stack[-2];
    v_12700 = v_12698;
    goto v_12529;
v_12531:
    v_12698 = stack[0];
    fn = elt(env, 67); // begin11
    v_12698 = (*qfn1(fn))(fn, v_12698);
    env = stack[-2];
    v_12700 = v_12698;
    goto v_12529;
v_12529:
    v_12698 = v_12700;
    if (v_12698 == nil) goto v_12568;
    else goto v_12569;
v_12568:
    goto v_12341;
v_12569:
    goto v_12577;
v_12573:
    v_12699 = v_12700;
    goto v_12574;
v_12575:
    v_12698 = elt(env, 34); // end
    goto v_12576;
v_12577:
    goto v_12573;
v_12574:
    goto v_12575;
v_12576:
    if (v_12699 == v_12698) goto v_12571;
    else goto v_12572;
v_12571:
    v_12698 = nil;
    goto v_12340;
v_12572:
    goto v_12587;
v_12583:
    v_12699 = v_12700;
    goto v_12584;
v_12585:
    v_12698 = elt(env, 41); // err2
    goto v_12586;
v_12587:
    goto v_12583;
v_12584:
    goto v_12585;
v_12586:
    if (v_12699 == v_12698) goto v_12581;
    else goto v_12582;
v_12581:
    goto v_12345;
v_12582:
    goto v_12596;
v_12592:
    v_12699 = v_12700;
    goto v_12593;
v_12594:
    v_12698 = elt(env, 42); // err3
    goto v_12595;
v_12596:
    goto v_12592;
v_12593:
    goto v_12594;
v_12595:
    if (v_12699 == v_12698) goto v_12590;
    else goto v_12591;
v_12590:
    goto v_12346;
v_12591:
v_12343:
    v_12698 = qvalue(elt(env, 43)); // crbuf1!*
    if (v_12698 == nil) goto v_12602;
    v_12698 = elt(env, 44); // "Closing object improperly removed. Redo edit."
    fn = elt(env, 68); // lprim
    v_12698 = (*qfn1(fn))(fn, v_12698);
    env = stack[-2];
    v_12698 = nil;
    qvalue(elt(env, 43)) = v_12698; // crbuf1!*
    v_12698 = nil;
    goto v_12340;
v_12602:
    goto v_12615;
v_12611:
    v_12699 = qvalue(elt(env, 45)); // eof!*
    goto v_12612;
v_12613:
    v_12698 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_12614;
v_12615:
    goto v_12611;
v_12612:
    goto v_12613;
v_12614:
    v_12698 = (LispObject)greaterp2(v_12699, v_12698);
    v_12698 = v_12698 ? lisp_true : nil;
    env = stack[-2];
    if (v_12698 == nil) goto v_12609;
    v_12698 = elt(env, 46); // "End-of-file read"
    fn = elt(env, 68); // lprim
    v_12698 = (*qfn1(fn))(fn, v_12698);
    env = stack[-2];
    v_12698 = elt(env, 47); // (bye)
    {
        fn = elt(env, 58); // lispeval
        return (*qfn1(fn))(fn, v_12698);
    }
v_12609:
    fn = elt(env, 55); // terminalp
    v_12698 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_12698 == nil) goto v_12623;
    v_12698 = nil;
    qvalue(elt(env, 48)) = v_12698; // crbuf!*
    v_12698 = lisp_true;
    qvalue(elt(env, 15)) = v_12698; // !*nosave!*
    goto v_12341;
v_12623:
    v_12698 = nil;
    goto v_12340;
v_12344:
    fn = elt(env, 69); // eofcheck
    v_12698 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_12698 == nil) goto v_12634;
    else goto v_12632;
v_12634:
    goto v_12642;
v_12638:
    v_12699 = qvalue(elt(env, 45)); // eof!*
    goto v_12639;
v_12640:
    v_12698 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12641;
v_12642:
    goto v_12638;
v_12639:
    goto v_12640;
v_12641:
    v_12698 = (LispObject)greaterp2(v_12699, v_12698);
    v_12698 = v_12698 ? lisp_true : nil;
    env = stack[-2];
    if (v_12698 == nil) goto v_12636;
    else goto v_12632;
v_12636:
    goto v_12633;
v_12632:
    goto v_12343;
v_12633:
    goto v_12651;
v_12647:
    v_12699 = stack[0];
    goto v_12648;
v_12649:
    v_12698 = elt(env, 49); // "BEGIN invalid"
    goto v_12650;
v_12651:
    goto v_12647;
v_12648:
    goto v_12649;
v_12650:
    if (equal(v_12699, v_12698)) goto v_12645;
    else goto v_12646;
v_12645:
    goto v_12341;
v_12646:
    v_12698 = lisp_true;
    stack[-1] = v_12698;
v_12345:
    fn = elt(env, 70); // resetparser
    v_12698 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
v_12346:
    v_12698 = lisp_true;
    qvalue(elt(env, 33)) = v_12698; // erfg!*
    v_12698 = qvalue(elt(env, 32)); // !*int
    if (v_12698 == nil) goto v_12663;
    else goto v_12664;
v_12663:
    v_12698 = qvalue(elt(env, 50)); // !*errcont
    v_12698 = (v_12698 == nil ? lisp_true : nil);
    goto v_12662;
v_12664:
    v_12698 = nil;
    goto v_12662;
    v_12698 = nil;
v_12662:
    if (v_12698 == nil) goto v_12660;
    v_12698 = lisp_true;
    qvalue(elt(env, 22)) = v_12698; // !*defn
    v_12698 = lisp_true;
    qvalue(elt(env, 51)) = v_12698; // !*echo
    v_12698 = qvalue(elt(env, 52)); // cmsg!*
    if (v_12698 == nil) goto v_12675;
    else goto v_12676;
v_12675:
    v_12698 = elt(env, 53); // "Continuing with parsing only ..."
    fn = elt(env, 71); // lprie
    v_12698 = (*qfn1(fn))(fn, v_12698);
    env = stack[-2];
    goto v_12674;
v_12676:
v_12674:
    v_12698 = lisp_true;
    qvalue(elt(env, 52)) = v_12698; // cmsg!*
    goto v_12658;
v_12660:
    v_12698 = qvalue(elt(env, 50)); // !*errcont
    if (v_12698 == nil) goto v_12681;
    else goto v_12682;
v_12681:
    v_12698 = stack[-1];
    fn = elt(env, 72); // pause1
    v_12698 = (*qfn1(fn))(fn, v_12698);
    env = stack[-2];
    v_12700 = v_12698;
    v_12698 = v_12700;
    if (v_12698 == nil) goto v_12689;
    v_12698 = v_12700;
    fn = elt(env, 58); // lispeval
    v_12698 = (*qfn1(fn))(fn, v_12698);
    v_12698 = (v_12698 == nil ? lisp_true : nil);
    goto v_12340;
v_12689:
    v_12698 = nil;
    qvalue(elt(env, 33)) = v_12698; // erfg!*
    goto v_12658;
v_12682:
    v_12698 = nil;
    qvalue(elt(env, 33)) = v_12698; // erfg!*
    goto v_12658;
v_12658:
    goto v_12341;
v_12340:
    return onevalue(v_12698);
}



// Code for rnprep!:

static LispObject CC_rnprepT(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12371, v_12372, v_12373;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12334);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_12334;
// end of prologue
    v_12371 = stack[-1];
    v_12371 = qcdr(v_12371);
    v_12371 = qcar(v_12371);
    fn = elt(env, 2); // prepf
    v_12371 = (*qfn1(fn))(fn, v_12371);
    env = stack[-3];
    v_12373 = v_12371;
    goto v_12349;
v_12345:
    v_12371 = stack[-1];
    v_12371 = qcdr(v_12371);
    v_12372 = qcdr(v_12371);
    goto v_12346;
v_12347:
    v_12371 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12348;
v_12349:
    goto v_12345;
v_12346:
    goto v_12347;
v_12348:
    if (v_12372 == v_12371) goto v_12343;
    else goto v_12344;
v_12343:
    v_12371 = v_12373;
    goto v_12342;
v_12344:
    goto v_12364;
v_12358:
    stack[-2] = elt(env, 1); // quotient
    goto v_12359;
v_12360:
    stack[0] = v_12373;
    goto v_12361;
v_12362:
    v_12371 = stack[-1];
    v_12371 = qcdr(v_12371);
    v_12371 = qcdr(v_12371);
    fn = elt(env, 2); // prepf
    v_12371 = (*qfn1(fn))(fn, v_12371);
    goto v_12363;
v_12364:
    goto v_12358;
v_12359:
    goto v_12360;
v_12361:
    goto v_12362;
v_12363:
    {
        LispObject v_12377 = stack[-2];
        LispObject v_12378 = stack[0];
        return list3(v_12377, v_12378, v_12371);
    }
    v_12371 = nil;
v_12342:
    return onevalue(v_12371);
}



// Code for groeb!=weight

static LispObject CC_groebMweight(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12356;
    LispObject fn;
    LispObject v_12336, v_12335, v_12334;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "groeb=weight");
    va_start(aa, nargs);
    v_12334 = va_arg(aa, LispObject);
    v_12335 = va_arg(aa, LispObject);
    v_12336 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12336,v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12334,v_12335,v_12336);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12336;
    stack[-1] = v_12335;
    v_12356 = v_12334;
// end of prologue
    goto v_12343;
v_12339:
    fn = elt(env, 1); // mo_ecart
    stack[-2] = (*qfn1(fn))(fn, v_12356);
    env = stack[-3];
    goto v_12340;
v_12341:
    goto v_12351;
v_12347:
    v_12356 = stack[-1];
    fn = elt(env, 2); // bas_dpecart
    stack[-1] = (*qfn1(fn))(fn, v_12356);
    env = stack[-3];
    goto v_12348;
v_12349:
    v_12356 = stack[0];
    fn = elt(env, 2); // bas_dpecart
    v_12356 = (*qfn1(fn))(fn, v_12356);
    env = stack[-3];
    goto v_12350;
v_12351:
    goto v_12347;
v_12348:
    goto v_12349;
v_12350:
    v_12356 = Lmin2(nil, stack[-1], v_12356);
    goto v_12342;
v_12343:
    goto v_12339;
v_12340:
    goto v_12341;
v_12342:
    {
        LispObject v_12360 = stack[-2];
        return plus2(v_12360, v_12356);
    }
}



// Code for rootrnd

static LispObject CC_rootrnd(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12344, v_12345;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12344 = v_12334;
// end of prologue
    goto v_12341;
v_12337:
    v_12345 = v_12344;
    goto v_12338;
v_12339:
    v_12344 = qvalue(elt(env, 1)); // acc!#
    goto v_12340;
v_12341:
    goto v_12337;
v_12338:
    goto v_12339;
v_12340:
    {
        fn = elt(env, 2); // rtrnda
        return (*qfn2(fn))(fn, v_12345, v_12344);
    }
}



// Code for simpqg

static LispObject CC_simpqg(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12344, v_12345;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12344 = v_12334;
// end of prologue
    goto v_12341;
v_12337:
    v_12345 = v_12344;
    goto v_12338;
v_12339:
    v_12344 = elt(env, 1); // qg
    goto v_12340;
v_12341:
    goto v_12337;
v_12338:
    goto v_12339;
v_12340:
    {
        fn = elt(env, 2); // simpcv
        return (*qfn2(fn))(fn, v_12345, v_12344);
    }
}



// Code for ezgcdf1

static LispObject CC_ezgcdf1(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12349, v_12350, v_12351;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_12350 = v_12335;
    v_12351 = v_12334;
// end of prologue
    v_12349 = (LispObject)0+TAG_FIXNUM; // 0
// Binding factor!-level
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_12349; // factor!-level
    goto v_12346;
v_12342:
    v_12349 = v_12351;
    goto v_12343;
v_12344:
    goto v_12345;
v_12346:
    goto v_12342;
v_12343:
    goto v_12344;
v_12345:
    v_12349 = list2(v_12349, v_12350);
    env = stack[-1];
    fn = elt(env, 2); // gcdlist
    v_12349 = (*qfn1(fn))(fn, v_12349);
    env = stack[-1];
    fn = elt(env, 3); // poly!-abs
    v_12349 = (*qfn1(fn))(fn, v_12349);
    ;}  // end of a binding scope
    return onevalue(v_12349);
}



// Code for delet

static LispObject CC_delet(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12406, v_12407, v_12408;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12335;
    stack[-1] = v_12334;
// end of prologue
    v_12408 = nil;
v_12340:
    v_12406 = stack[-1];
    if (v_12406 == nil) goto v_12343;
    else goto v_12344;
v_12343:
    goto v_12351;
v_12347:
    v_12407 = v_12408;
    goto v_12348;
v_12349:
    v_12406 = stack[0];
    goto v_12350;
v_12351:
    goto v_12347;
v_12348:
    goto v_12349;
v_12350:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_12407, v_12406);
    }
v_12344:
    v_12406 = stack[0];
    if (v_12406 == nil) goto v_12358;
    else goto v_12359;
v_12358:
    v_12406 = lisp_true;
    goto v_12357;
v_12359:
    goto v_12368;
v_12364:
    v_12407 = stack[-1];
    goto v_12365;
v_12366:
    v_12406 = stack[0];
    goto v_12367;
v_12368:
    goto v_12364;
v_12365:
    goto v_12366;
v_12367:
    v_12406 = (equal(v_12407, v_12406) ? lisp_true : nil);
    goto v_12357;
    v_12406 = nil;
v_12357:
    if (v_12406 == nil) goto v_12355;
    v_12406 = v_12408;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12406);
    }
v_12355:
    goto v_12380;
v_12376:
    v_12407 = stack[-1];
    goto v_12377;
v_12378:
    v_12406 = stack[0];
    v_12406 = qcar(v_12406);
    goto v_12379;
v_12380:
    goto v_12376;
v_12377:
    goto v_12378;
v_12379:
    if (equal(v_12407, v_12406)) goto v_12374;
    else goto v_12375;
v_12374:
    goto v_12389;
v_12385:
    v_12407 = v_12408;
    goto v_12386;
v_12387:
    v_12406 = stack[0];
    v_12406 = qcdr(v_12406);
    goto v_12388;
v_12389:
    goto v_12385;
v_12386:
    goto v_12387;
v_12388:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_12407, v_12406);
    }
v_12375:
    goto v_12400;
v_12396:
    v_12406 = stack[0];
    v_12406 = qcar(v_12406);
    goto v_12397;
v_12398:
    v_12407 = v_12408;
    goto v_12399;
v_12400:
    goto v_12396;
v_12397:
    goto v_12398;
v_12399:
    v_12406 = cons(v_12406, v_12407);
    env = stack[-2];
    v_12408 = v_12406;
    v_12406 = stack[0];
    v_12406 = qcdr(v_12406);
    stack[0] = v_12406;
    goto v_12340;
    v_12406 = nil;
    return onevalue(v_12406);
}



// Code for quotofd

static LispObject CC_quotofd(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12402, v_12403;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_12335;
    stack[-2] = v_12334;
// end of prologue
    stack[-3] = nil;
v_12340:
    v_12402 = stack[-2];
    if (v_12402 == nil) goto v_12343;
    else goto v_12344;
v_12343:
    v_12402 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12402);
    }
v_12344:
    v_12402 = stack[-2];
    if (!consp(v_12402)) goto v_12352;
    else goto v_12353;
v_12352:
    v_12402 = lisp_true;
    goto v_12351;
v_12353:
    v_12402 = stack[-2];
    v_12402 = qcar(v_12402);
    v_12402 = (consp(v_12402) ? nil : lisp_true);
    goto v_12351;
    v_12402 = nil;
v_12351:
    if (v_12402 == nil) goto v_12349;
    goto v_12366;
v_12362:
    stack[0] = stack[-3];
    goto v_12363;
v_12364:
    goto v_12373;
v_12369:
    v_12403 = stack[-2];
    goto v_12370;
v_12371:
    v_12402 = stack[-1];
    goto v_12372;
v_12373:
    goto v_12369;
v_12370:
    goto v_12371;
v_12372:
    fn = elt(env, 2); // quotodd
    v_12402 = (*qfn2(fn))(fn, v_12403, v_12402);
    env = stack[-4];
    goto v_12365;
v_12366:
    goto v_12362;
v_12363:
    goto v_12364;
v_12365:
    {
        LispObject v_12408 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_12408, v_12402);
    }
v_12349:
    goto v_12385;
v_12379:
    v_12402 = stack[-2];
    v_12402 = qcar(v_12402);
    stack[0] = qcar(v_12402);
    goto v_12380;
v_12381:
    goto v_12394;
v_12390:
    v_12402 = stack[-2];
    v_12402 = qcar(v_12402);
    v_12403 = qcdr(v_12402);
    goto v_12391;
v_12392:
    v_12402 = stack[-1];
    goto v_12393;
v_12394:
    goto v_12390;
v_12391:
    goto v_12392;
v_12393:
    v_12403 = CC_quotofd(elt(env, 0), v_12403, v_12402);
    env = stack[-4];
    goto v_12382;
v_12383:
    v_12402 = stack[-3];
    goto v_12384;
v_12385:
    goto v_12379;
v_12380:
    goto v_12381;
v_12382:
    goto v_12383;
v_12384:
    v_12402 = acons(stack[0], v_12403, v_12402);
    env = stack[-4];
    stack[-3] = v_12402;
    v_12402 = stack[-2];
    v_12402 = qcdr(v_12402);
    stack[-2] = v_12402;
    goto v_12340;
    v_12402 = nil;
    return onevalue(v_12402);
}



// Code for ir2mml

static LispObject CC_ir2mml(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12353;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12334);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_12334;
// end of prologue
    v_12353 = elt(env, 1); // (indent)
    fn = elt(env, 6); // fluid
    v_12353 = (*qfn1(fn))(fn, v_12353);
    env = stack[-1];
    v_12353 = (LispObject)48+TAG_FIXNUM; // 3
    qvalue(elt(env, 2)) = v_12353; // ind
    v_12353 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 3)) = v_12353; // indent
    v_12353 = elt(env, 4); // "<math>"
    fn = elt(env, 7); // printout
    v_12353 = (*qfn1(fn))(fn, v_12353);
    env = stack[-1];
    v_12353 = lisp_true;
    fn = elt(env, 8); // indent!*
    v_12353 = (*qfn1(fn))(fn, v_12353);
    env = stack[-1];
    v_12353 = stack[0];
    fn = elt(env, 9); // expression
    v_12353 = (*qfn1(fn))(fn, v_12353);
    env = stack[-1];
    v_12353 = nil;
    fn = elt(env, 8); // indent!*
    v_12353 = (*qfn1(fn))(fn, v_12353);
    env = stack[-1];
    v_12353 = elt(env, 5); // "</math>"
    fn = elt(env, 7); // printout
    v_12353 = (*qfn1(fn))(fn, v_12353);
    v_12353 = nil;
    return onevalue(v_12353);
}



// Code for mchkopt1

static LispObject CC_mchkopt1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12522, v_12523, v_12524;
    LispObject fn;
    LispObject v_12336, v_12335, v_12334;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mchkopt1");
    va_start(aa, nargs);
    v_12334 = va_arg(aa, LispObject);
    v_12335 = va_arg(aa, LispObject);
    v_12336 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12336,v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12334,v_12335,v_12336);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_12336;
    v_12522 = v_12335;
    v_12524 = v_12334;
// end of prologue
    v_12522 = qcdr(v_12522);
    v_12523 = v_12522;
    if (v_12522 == nil) goto v_12346;
    else goto v_12347;
v_12346:
    v_12522 = nil;
    goto v_12342;
v_12347:
    v_12522 = v_12523;
    v_12522 = qcar(v_12522);
    stack[-3] = v_12522;
    v_12522 = v_12523;
    v_12522 = qcdr(v_12522);
    v_12523 = v_12522;
    if (v_12522 == nil) goto v_12355;
    else goto v_12356;
v_12355:
    v_12522 = nil;
    goto v_12342;
v_12356:
    v_12522 = v_12523;
    v_12522 = qcar(v_12522);
    stack[-5] = v_12522;
    v_12522 = v_12523;
    v_12522 = qcdr(v_12522);
    if (v_12522 == nil) goto v_12365;
    v_12522 = nil;
    goto v_12342;
v_12365:
    v_12522 = stack[-3];
    if (!symbolp(v_12522)) v_12522 = nil;
    else { v_12522 = qfastgets(v_12522);
           if (v_12522 != nil) { v_12522 = elt(v_12522, 6); // optional
#ifdef RECORD_GET
             if (v_12522 == SPID_NOPROP)
                record_get(elt(fastget_names, 6), 0),
                v_12522 = nil;
             else record_get(elt(fastget_names, 6), 1),
                v_12522 = lisp_true; }
           else record_get(elt(fastget_names, 6), 0); }
#else
             if (v_12522 == SPID_NOPROP) v_12522 = nil; else v_12522 = lisp_true; }}
#endif
    if (v_12522 == nil) goto v_12372;
    goto v_12386;
v_12382:
    v_12523 = v_12524;
    goto v_12383;
v_12384:
    v_12522 = stack[-5];
    goto v_12385;
v_12386:
    goto v_12382;
v_12383:
    goto v_12384;
v_12385:
    fn = elt(env, 2); // mchk
    v_12522 = (*qfn2(fn))(fn, v_12523, v_12522);
    env = stack[-6];
    stack[-5] = v_12522;
    v_12522 = stack[-5];
    if (v_12522 == nil) goto v_12391;
    else goto v_12392;
v_12391:
    v_12522 = nil;
    goto v_12379;
v_12392:
    v_12522 = stack[-5];
    v_12522 = qcar(v_12522);
    goto v_12406;
v_12400:
    v_12524 = stack[-3];
    goto v_12401;
v_12402:
    v_12523 = stack[-4];
    v_12523 = qcar(v_12523);
    goto v_12403;
v_12404:
    goto v_12405;
v_12406:
    goto v_12400;
v_12401:
    goto v_12402;
v_12403:
    goto v_12404;
v_12405:
    v_12522 = acons(v_12524, v_12523, v_12522);
    env = stack[-6];
    v_12522 = ncons(v_12522);
    env = stack[-6];
    stack[-1] = v_12522;
    stack[-2] = v_12522;
v_12380:
    v_12522 = stack[-5];
    v_12522 = qcdr(v_12522);
    stack[-5] = v_12522;
    v_12522 = stack[-5];
    if (v_12522 == nil) goto v_12415;
    else goto v_12416;
v_12415:
    v_12522 = stack[-2];
    goto v_12379;
v_12416:
    goto v_12424;
v_12420:
    stack[0] = stack[-1];
    goto v_12421;
v_12422:
    v_12522 = stack[-5];
    v_12522 = qcar(v_12522);
    goto v_12437;
v_12431:
    v_12524 = stack[-3];
    goto v_12432;
v_12433:
    v_12523 = stack[-4];
    v_12523 = qcar(v_12523);
    goto v_12434;
v_12435:
    goto v_12436;
v_12437:
    goto v_12431;
v_12432:
    goto v_12433;
v_12434:
    goto v_12435;
v_12436:
    v_12522 = acons(v_12524, v_12523, v_12522);
    env = stack[-6];
    v_12522 = ncons(v_12522);
    env = stack[-6];
    goto v_12423;
v_12424:
    goto v_12420;
v_12421:
    goto v_12422;
v_12423:
    v_12522 = Lrplacd(nil, stack[0], v_12522);
    env = stack[-6];
    v_12522 = stack[-1];
    v_12522 = qcdr(v_12522);
    stack[-1] = v_12522;
    goto v_12380;
v_12379:
    goto v_12370;
v_12372:
    v_12522 = stack[-5];
    if (!symbolp(v_12522)) v_12522 = nil;
    else { v_12522 = qfastgets(v_12522);
           if (v_12522 != nil) { v_12522 = elt(v_12522, 6); // optional
#ifdef RECORD_GET
             if (v_12522 == SPID_NOPROP)
                record_get(elt(fastget_names, 6), 0),
                v_12522 = nil;
             else record_get(elt(fastget_names, 6), 1),
                v_12522 = lisp_true; }
           else record_get(elt(fastget_names, 6), 0); }
#else
             if (v_12522 == SPID_NOPROP) v_12522 = nil; else v_12522 = lisp_true; }}
#endif
    if (v_12522 == nil) goto v_12445;
    goto v_12459;
v_12455:
    v_12523 = v_12524;
    goto v_12456;
v_12457:
    v_12522 = stack[-3];
    goto v_12458;
v_12459:
    goto v_12455;
v_12456:
    goto v_12457;
v_12458:
    fn = elt(env, 2); // mchk
    v_12522 = (*qfn2(fn))(fn, v_12523, v_12522);
    env = stack[-6];
    stack[-3] = v_12522;
    v_12522 = stack[-3];
    if (v_12522 == nil) goto v_12464;
    else goto v_12465;
v_12464:
    v_12522 = nil;
    goto v_12452;
v_12465:
    v_12522 = stack[-3];
    v_12522 = qcar(v_12522);
    goto v_12479;
v_12473:
    v_12524 = stack[-5];
    goto v_12474;
v_12475:
    v_12523 = stack[-4];
    v_12523 = qcdr(v_12523);
    v_12523 = qcar(v_12523);
    goto v_12476;
v_12477:
    goto v_12478;
v_12479:
    goto v_12473;
v_12474:
    goto v_12475;
v_12476:
    goto v_12477;
v_12478:
    v_12522 = acons(v_12524, v_12523, v_12522);
    env = stack[-6];
    v_12522 = ncons(v_12522);
    env = stack[-6];
    stack[-1] = v_12522;
    stack[-2] = v_12522;
v_12453:
    v_12522 = stack[-3];
    v_12522 = qcdr(v_12522);
    stack[-3] = v_12522;
    v_12522 = stack[-3];
    if (v_12522 == nil) goto v_12489;
    else goto v_12490;
v_12489:
    v_12522 = stack[-2];
    goto v_12452;
v_12490:
    goto v_12498;
v_12494:
    stack[0] = stack[-1];
    goto v_12495;
v_12496:
    v_12522 = stack[-3];
    v_12522 = qcar(v_12522);
    goto v_12511;
v_12505:
    v_12524 = stack[-5];
    goto v_12506;
v_12507:
    v_12523 = stack[-4];
    v_12523 = qcdr(v_12523);
    v_12523 = qcar(v_12523);
    goto v_12508;
v_12509:
    goto v_12510;
v_12511:
    goto v_12505;
v_12506:
    goto v_12507;
v_12508:
    goto v_12509;
v_12510:
    v_12522 = acons(v_12524, v_12523, v_12522);
    env = stack[-6];
    v_12522 = ncons(v_12522);
    env = stack[-6];
    goto v_12497;
v_12498:
    goto v_12494;
v_12495:
    goto v_12496;
v_12497:
    v_12522 = Lrplacd(nil, stack[0], v_12522);
    env = stack[-6];
    v_12522 = stack[-1];
    v_12522 = qcdr(v_12522);
    stack[-1] = v_12522;
    goto v_12453;
v_12452:
    goto v_12370;
v_12445:
    v_12522 = nil;
    goto v_12370;
    v_12522 = nil;
v_12370:
v_12342:
    return onevalue(v_12522);
}



// Code for simprecip

static LispObject CC_simprecip(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12369, v_12370;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12334);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12370 = v_12334;
// end of prologue
    v_12369 = qvalue(elt(env, 1)); // !*mcd
    if (v_12369 == nil) goto v_12338;
    else goto v_12339;
v_12338:
    goto v_12347;
v_12343:
    goto v_12353;
v_12349:
    goto v_12350;
v_12351:
    v_12369 = elt(env, 2); // recip
    goto v_12352;
v_12353:
    goto v_12349;
v_12350:
    goto v_12351;
v_12352:
    fn = elt(env, 3); // carx
    v_12370 = (*qfn2(fn))(fn, v_12370, v_12369);
    env = stack[0];
    goto v_12344;
v_12345:
    v_12369 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_12346;
v_12347:
    goto v_12343;
v_12344:
    goto v_12345;
v_12346:
    v_12369 = list2(v_12370, v_12369);
    env = stack[0];
    {
        fn = elt(env, 4); // simpexpt
        return (*qfn1(fn))(fn, v_12369);
    }
v_12339:
    goto v_12366;
v_12362:
    goto v_12363;
v_12364:
    v_12369 = elt(env, 2); // recip
    goto v_12365;
v_12366:
    goto v_12362;
v_12363:
    goto v_12364;
v_12365:
    fn = elt(env, 3); // carx
    v_12369 = (*qfn2(fn))(fn, v_12370, v_12369);
    env = stack[0];
    fn = elt(env, 5); // simp
    v_12369 = (*qfn1(fn))(fn, v_12369);
    env = stack[0];
    {
        fn = elt(env, 6); // invsq
        return (*qfn1(fn))(fn, v_12369);
    }
    v_12369 = nil;
    return onevalue(v_12369);
}



// Code for chk

static LispObject CC_chk(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12415, v_12416, v_12417;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12334);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12334;
// end of prologue
v_12333:
    v_12415 = stack[0];
    if (v_12415 == nil) goto v_12338;
    else goto v_12339;
v_12338:
    v_12415 = lisp_true;
    goto v_12337;
v_12339:
    goto v_12352;
v_12348:
    v_12416 = stack[0];
    goto v_12349;
v_12350:
    v_12415 = lisp_true;
    goto v_12351;
v_12352:
    goto v_12348;
v_12349:
    goto v_12350;
v_12351:
    if (v_12416 == v_12415) goto v_12346;
    else goto v_12347;
v_12346:
    v_12415 = lisp_true;
    goto v_12345;
v_12347:
    v_12415 = stack[0];
    v_12415 = qcar(v_12415);
    fn = elt(env, 1); // bsubs
    v_12415 = (*qfn1(fn))(fn, v_12415);
    env = stack[-2];
    stack[-1] = v_12415;
    v_12415 = stack[-1];
    fn = elt(env, 2); // freexp
    v_12415 = (*qfn1(fn))(fn, v_12415);
    env = stack[-2];
    if (v_12415 == nil) goto v_12365;
    v_12415 = stack[0];
    v_12415 = qcdr(v_12415);
    v_12415 = CC_chk(elt(env, 0), v_12415);
    v_12417 = v_12415;
    v_12415 = v_12417;
    if (v_12415 == nil) goto v_12374;
    else goto v_12375;
v_12374:
    v_12415 = nil;
    goto v_12373;
v_12375:
    goto v_12384;
v_12380:
    v_12416 = v_12417;
    goto v_12381;
v_12382:
    v_12415 = lisp_true;
    goto v_12383;
v_12384:
    goto v_12380;
v_12381:
    goto v_12382;
v_12383:
    if (v_12416 == v_12415) goto v_12378;
    else goto v_12379;
v_12378:
    v_12415 = stack[-1];
    return ncons(v_12415);
v_12379:
    goto v_12396;
v_12392:
    v_12415 = stack[-1];
    goto v_12393;
v_12394:
    v_12416 = v_12417;
    goto v_12395;
v_12396:
    goto v_12392;
v_12393:
    goto v_12394;
v_12395:
    return cons(v_12415, v_12416);
    v_12415 = nil;
v_12373:
    goto v_12363;
v_12365:
    goto v_12405;
v_12401:
    v_12415 = stack[-1];
    fn = elt(env, 3); // reval
    v_12416 = (*qfn1(fn))(fn, v_12415);
    env = stack[-2];
    goto v_12402;
v_12403:
    v_12415 = lisp_true;
    goto v_12404;
v_12405:
    goto v_12401;
v_12402:
    goto v_12403;
v_12404:
    if (v_12416 == v_12415) goto v_12399;
    else goto v_12400;
v_12399:
    v_12415 = stack[0];
    v_12415 = qcdr(v_12415);
    stack[0] = v_12415;
    goto v_12333;
v_12400:
    v_12415 = nil;
    goto v_12363;
    v_12415 = nil;
v_12363:
    goto v_12345;
    v_12415 = nil;
v_12345:
    goto v_12337;
    v_12415 = nil;
v_12337:
    return onevalue(v_12415);
}



// Code for freeoffl

static LispObject CC_freeoffl(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12370, v_12371;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12335;
    stack[-1] = v_12334;
// end of prologue
v_12333:
    v_12370 = stack[0];
    if (v_12370 == nil) goto v_12339;
    else goto v_12340;
v_12339:
    v_12370 = lisp_true;
    goto v_12338;
v_12340:
    goto v_12354;
v_12350:
    v_12371 = stack[-1];
    goto v_12351;
v_12352:
    v_12370 = stack[0];
    v_12370 = qcar(v_12370);
    goto v_12353;
v_12354:
    goto v_12350;
v_12351:
    goto v_12352;
v_12353:
    fn = elt(env, 1); // freeoff
    v_12370 = (*qfn2(fn))(fn, v_12371, v_12370);
    env = stack[-2];
    if (v_12370 == nil) goto v_12347;
    else goto v_12348;
v_12347:
    v_12370 = nil;
    goto v_12346;
v_12348:
    goto v_12366;
v_12362:
    v_12371 = stack[-1];
    goto v_12363;
v_12364:
    v_12370 = stack[0];
    v_12370 = qcdr(v_12370);
    goto v_12365;
v_12366:
    goto v_12362;
v_12363:
    goto v_12364;
v_12365:
    stack[-1] = v_12371;
    stack[0] = v_12370;
    goto v_12333;
    v_12370 = nil;
v_12346:
    goto v_12338;
    v_12370 = nil;
v_12338:
    return onevalue(v_12370);
}



// Code for treesizep

static LispObject CC_treesizep(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12352, v_12353;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
// copy arguments values to proper place
    v_12352 = v_12335;
    v_12353 = v_12334;
// end of prologue
    goto v_12341;
v_12337:
    goto v_12347;
v_12343:
    goto v_12344;
v_12345:
    goto v_12346;
v_12347:
    goto v_12343;
v_12344:
    goto v_12345;
v_12346:
    fn = elt(env, 1); // treesizep1
    v_12353 = (*qfn2(fn))(fn, v_12353, v_12352);
    goto v_12338;
v_12339:
    v_12352 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12340;
v_12341:
    goto v_12337;
v_12338:
    goto v_12339;
v_12340:
    v_12352 = (v_12353 == v_12352 ? lisp_true : nil);
    return onevalue(v_12352);
}



// Code for mv!-domainlist

static LispObject CC_mvKdomainlist(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12361, v_12362;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12334);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_12334;
// end of prologue
    v_12362 = nil;
v_12339:
    v_12361 = stack[0];
    if (v_12361 == nil) goto v_12342;
    else goto v_12343;
v_12342:
    v_12361 = v_12362;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12361);
    }
v_12343:
    goto v_12354;
v_12350:
    v_12361 = stack[0];
    v_12361 = qcar(v_12361);
    v_12361 = qcdr(v_12361);
    goto v_12351;
v_12352:
    goto v_12353;
v_12354:
    goto v_12350;
v_12351:
    goto v_12352;
v_12353:
    v_12361 = cons(v_12361, v_12362);
    env = stack[-1];
    v_12362 = v_12361;
    v_12361 = stack[0];
    v_12361 = qcdr(v_12361);
    stack[0] = v_12361;
    goto v_12339;
    v_12361 = nil;
    return onevalue(v_12361);
}



// Code for !:rn2rd

static LispObject CC_Trn2rd(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12349, v_12350;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12350 = v_12334;
// end of prologue
    v_12349 = qvalue(elt(env, 1)); // !*roundall
    if (v_12349 == nil) goto v_12339;
    v_12349 = qvalue(elt(env, 2)); // !*rounded
    if (v_12349 == nil) goto v_12339;
    v_12349 = v_12350;
    {
        fn = elt(env, 3); // !*rn2rd
        return (*qfn1(fn))(fn, v_12349);
    }
v_12339:
    v_12349 = v_12350;
    goto v_12337;
    v_12349 = nil;
v_12337:
    return onevalue(v_12349);
}



// Code for reducepowers

static LispObject CC_reducepowers(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12466, v_12467;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12334);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12334;
// end of prologue
v_12338:
    v_12466 = stack[0];
    if (!consp(v_12466)) goto v_12349;
    else goto v_12350;
v_12349:
    v_12466 = lisp_true;
    goto v_12348;
v_12350:
    v_12466 = stack[0];
    v_12466 = qcar(v_12466);
    v_12466 = (consp(v_12466) ? nil : lisp_true);
    goto v_12348;
    v_12466 = nil;
v_12348:
    if (v_12466 == nil) goto v_12346;
    v_12466 = lisp_true;
    goto v_12344;
v_12346:
    goto v_12366;
v_12362:
    v_12466 = stack[0];
    v_12466 = qcar(v_12466);
    v_12466 = qcar(v_12466);
    v_12467 = qcdr(v_12466);
    goto v_12363;
v_12364:
    v_12466 = qvalue(elt(env, 1)); // repowl!*
    v_12466 = qcar(v_12466);
    v_12466 = qcdr(v_12466);
    goto v_12365;
v_12366:
    goto v_12362;
v_12363:
    goto v_12364;
v_12365:
    v_12466 = (LispObject)lessp2(v_12467, v_12466);
    v_12466 = v_12466 ? lisp_true : nil;
    env = stack[-2];
    goto v_12344;
    v_12466 = nil;
v_12344:
    if (v_12466 == nil) goto v_12342;
    v_12466 = stack[0];
    goto v_12337;
v_12342:
    goto v_12381;
v_12377:
    v_12466 = stack[0];
    v_12466 = qcar(v_12466);
    v_12466 = qcar(v_12466);
    v_12467 = qcdr(v_12466);
    goto v_12378;
v_12379:
    v_12466 = qvalue(elt(env, 1)); // repowl!*
    v_12466 = qcar(v_12466);
    v_12466 = qcdr(v_12466);
    goto v_12380;
v_12381:
    goto v_12377;
v_12378:
    goto v_12379;
v_12380:
    if (equal(v_12467, v_12466)) goto v_12375;
    else goto v_12376;
v_12375:
    goto v_12394;
v_12390:
    goto v_12400;
v_12396:
    v_12466 = qvalue(elt(env, 1)); // repowl!*
    v_12467 = qcdr(v_12466);
    goto v_12397;
v_12398:
    v_12466 = stack[0];
    v_12466 = qcar(v_12466);
    v_12466 = qcdr(v_12466);
    goto v_12399;
v_12400:
    goto v_12396;
v_12397:
    goto v_12398;
v_12399:
    fn = elt(env, 2); // multf
    v_12467 = (*qfn2(fn))(fn, v_12467, v_12466);
    env = stack[-2];
    goto v_12391;
v_12392:
    v_12466 = stack[0];
    v_12466 = qcdr(v_12466);
    goto v_12393;
v_12394:
    goto v_12390;
v_12391:
    goto v_12392;
v_12393:
    {
        fn = elt(env, 3); // addf
        return (*qfn2(fn))(fn, v_12467, v_12466);
    }
v_12376:
    goto v_12415;
v_12411:
    goto v_12421;
v_12417:
    goto v_12427;
v_12423:
    goto v_12434;
v_12430:
    goto v_12440;
v_12436:
    v_12466 = stack[0];
    v_12466 = qcar(v_12466);
    v_12466 = qcar(v_12466);
    stack[-1] = qcar(v_12466);
    goto v_12437;
v_12438:
    goto v_12450;
v_12446:
    v_12466 = stack[0];
    v_12466 = qcar(v_12466);
    v_12466 = qcar(v_12466);
    v_12467 = qcdr(v_12466);
    goto v_12447;
v_12448:
    v_12466 = qvalue(elt(env, 1)); // repowl!*
    v_12466 = qcar(v_12466);
    v_12466 = qcdr(v_12466);
    goto v_12449;
v_12450:
    goto v_12446;
v_12447:
    goto v_12448;
v_12449:
    v_12466 = difference2(v_12467, v_12466);
    env = stack[-2];
    goto v_12439;
v_12440:
    goto v_12436;
v_12437:
    goto v_12438;
v_12439:
    fn = elt(env, 4); // to
    v_12467 = (*qfn2(fn))(fn, stack[-1], v_12466);
    env = stack[-2];
    goto v_12431;
v_12432:
    v_12466 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12433;
v_12434:
    goto v_12430;
v_12431:
    goto v_12432;
v_12433:
    v_12466 = cons(v_12467, v_12466);
    env = stack[-2];
    v_12467 = ncons(v_12466);
    env = stack[-2];
    goto v_12424;
v_12425:
    v_12466 = stack[0];
    v_12466 = qcar(v_12466);
    v_12466 = qcdr(v_12466);
    goto v_12426;
v_12427:
    goto v_12423;
v_12424:
    goto v_12425;
v_12426:
    fn = elt(env, 2); // multf
    v_12467 = (*qfn2(fn))(fn, v_12467, v_12466);
    env = stack[-2];
    goto v_12418;
v_12419:
    v_12466 = qvalue(elt(env, 1)); // repowl!*
    v_12466 = qcdr(v_12466);
    goto v_12420;
v_12421:
    goto v_12417;
v_12418:
    goto v_12419;
v_12420:
    fn = elt(env, 2); // multf
    v_12467 = (*qfn2(fn))(fn, v_12467, v_12466);
    env = stack[-2];
    goto v_12412;
v_12413:
    v_12466 = stack[0];
    v_12466 = qcdr(v_12466);
    goto v_12414;
v_12415:
    goto v_12411;
v_12412:
    goto v_12413;
v_12414:
    fn = elt(env, 3); // addf
    v_12466 = (*qfn2(fn))(fn, v_12467, v_12466);
    env = stack[-2];
    stack[0] = v_12466;
    goto v_12338;
    v_12466 = nil;
v_12337:
    return onevalue(v_12466);
}



// Code for general!-reciprocal!-by!-gcd

static LispObject CC_generalKreciprocalKbyKgcd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12441, v_12442, v_12443;
    LispObject fn;
    LispObject v_12337, v_12336, v_12335, v_12334;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "general-reciprocal-by-gcd");
    va_start(aa, nargs);
    v_12334 = va_arg(aa, LispObject);
    v_12335 = va_arg(aa, LispObject);
    v_12336 = va_arg(aa, LispObject);
    v_12337 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_12337,v_12336,v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_12334,v_12335,v_12336,v_12337);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_12337;
    stack[-2] = v_12336;
    stack[-3] = v_12335;
    stack[-4] = v_12334;
// end of prologue
v_12343:
    goto v_12353;
v_12349:
    v_12442 = stack[-3];
    goto v_12350;
v_12351:
    v_12441 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12352;
v_12353:
    goto v_12349;
v_12350:
    goto v_12351;
v_12352:
    if (v_12442 == v_12441) goto v_12347;
    else goto v_12348;
v_12347:
    goto v_12363;
v_12357:
    v_12443 = elt(env, 2); // alg
    goto v_12358;
v_12359:
    v_12442 = (LispObject)128+TAG_FIXNUM; // 8
    goto v_12360;
v_12361:
    v_12441 = elt(env, 3); // "Invalid modular division"
    goto v_12362;
v_12363:
    goto v_12357;
v_12358:
    goto v_12359;
v_12360:
    goto v_12361;
v_12362:
    {
        fn = elt(env, 5); // rerror
        return (*qfnn(fn))(fn, 3, v_12443, v_12442, v_12441);
    }
v_12348:
    goto v_12373;
v_12369:
    v_12442 = stack[-3];
    goto v_12370;
v_12371:
    v_12441 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12372;
v_12373:
    goto v_12369;
v_12370:
    goto v_12371;
v_12372:
    if (v_12442 == v_12441) goto v_12367;
    else goto v_12368;
v_12367:
    goto v_12385;
v_12381:
    v_12442 = stack[-1];
    goto v_12382;
v_12383:
    v_12441 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12384;
v_12385:
    goto v_12381;
v_12382:
    goto v_12383;
v_12384:
    v_12441 = (LispObject)lessp2(v_12442, v_12441);
    v_12441 = v_12441 ? lisp_true : nil;
    env = stack[-6];
    if (v_12441 == nil) goto v_12379;
    goto v_12393;
v_12389:
    v_12441 = stack[-1];
    goto v_12390;
v_12391:
    v_12442 = qvalue(elt(env, 4)); // current!-modulus
    goto v_12392;
v_12393:
    goto v_12389;
v_12390:
    goto v_12391;
v_12392:
    return plus2(v_12441, v_12442);
v_12379:
    v_12441 = stack[-1];
    goto v_12377;
    v_12441 = nil;
v_12377:
    goto v_12342;
v_12368:
    goto v_12404;
v_12400:
    v_12442 = stack[-4];
    goto v_12401;
v_12402:
    v_12441 = stack[-3];
    goto v_12403;
v_12404:
    goto v_12400;
v_12401:
    goto v_12402;
v_12403:
    v_12441 = quot2(v_12442, v_12441);
    env = stack[-6];
    stack[-5] = v_12441;
    v_12441 = stack[-4];
    v_12442 = v_12441;
    v_12441 = stack[-3];
    stack[-4] = v_12441;
    goto v_12414;
v_12410:
    stack[0] = v_12442;
    goto v_12411;
v_12412:
    goto v_12421;
v_12417:
    v_12442 = stack[-3];
    goto v_12418;
v_12419:
    v_12441 = stack[-5];
    goto v_12420;
v_12421:
    goto v_12417;
v_12418:
    goto v_12419;
v_12420:
    v_12441 = times2(v_12442, v_12441);
    env = stack[-6];
    goto v_12413;
v_12414:
    goto v_12410;
v_12411:
    goto v_12412;
v_12413:
    v_12441 = difference2(stack[0], v_12441);
    env = stack[-6];
    stack[-3] = v_12441;
    v_12441 = stack[-2];
    v_12442 = v_12441;
    v_12441 = stack[-1];
    stack[-2] = v_12441;
    goto v_12431;
v_12427:
    stack[0] = v_12442;
    goto v_12428;
v_12429:
    goto v_12438;
v_12434:
    v_12442 = stack[-1];
    goto v_12435;
v_12436:
    v_12441 = stack[-5];
    goto v_12437;
v_12438:
    goto v_12434;
v_12435:
    goto v_12436;
v_12437:
    v_12441 = times2(v_12442, v_12441);
    env = stack[-6];
    goto v_12430;
v_12431:
    goto v_12427;
v_12428:
    goto v_12429;
v_12430:
    v_12441 = difference2(stack[0], v_12441);
    env = stack[-6];
    stack[-1] = v_12441;
    goto v_12343;
v_12342:
    return onevalue(v_12441);
}



// Code for quotfail!-in!-vector

static LispObject CC_quotfailKinKvector(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12613, v_12614, v_12615, v_12616, v_12617, v_12618, v_12619, v_12620;
    LispObject fn;
    LispObject v_12337, v_12336, v_12335, v_12334;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "quotfail-in-vector");
    va_start(aa, nargs);
    v_12334 = va_arg(aa, LispObject);
    v_12335 = va_arg(aa, LispObject);
    v_12336 = va_arg(aa, LispObject);
    v_12337 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_12337,v_12336,v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_12334,v_12335,v_12336,v_12337);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_12337;
    stack[-2] = v_12336;
    v_12615 = v_12335;
    stack[-3] = v_12334;
// end of prologue
    goto v_12347;
v_12343:
    v_12614 = v_12615;
    goto v_12344;
v_12345:
    v_12613 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12346;
v_12347:
    goto v_12343;
v_12344:
    goto v_12345;
v_12346:
    if (((intptr_t)(v_12614)) < ((intptr_t)(v_12613))) goto v_12341;
    else goto v_12342;
v_12341:
    v_12613 = v_12615;
    goto v_12340;
v_12342:
    goto v_12357;
v_12353:
    v_12614 = stack[-1];
    goto v_12354;
v_12355:
    v_12613 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12356;
v_12357:
    goto v_12353;
v_12354:
    goto v_12355;
v_12356:
    if (((intptr_t)(v_12614)) < ((intptr_t)(v_12613))) goto v_12351;
    else goto v_12352;
v_12351:
    v_12613 = elt(env, 1); // "Attempt to divide by zero"
    {
        fn = elt(env, 6); // errorf
        return (*qfn1(fn))(fn, v_12613);
    }
v_12352:
    goto v_12368;
v_12364:
    v_12614 = v_12615;
    goto v_12365;
v_12366:
    v_12613 = stack[-1];
    goto v_12367;
v_12368:
    goto v_12364;
v_12365:
    goto v_12366;
v_12367:
    if (((intptr_t)(v_12614)) < ((intptr_t)(v_12613))) goto v_12362;
    else goto v_12363;
v_12362:
    v_12613 = elt(env, 2); // "Bad degrees in quotfail-in-vector"
    {
        fn = elt(env, 6); // errorf
        return (*qfn1(fn))(fn, v_12613);
    }
v_12363:
    goto v_12383;
v_12379:
    v_12614 = v_12615;
    goto v_12380;
v_12381:
    v_12613 = stack[-1];
    goto v_12382;
v_12383:
    goto v_12379;
v_12380:
    goto v_12381;
v_12382:
    v_12613 = (LispObject)(intptr_t)((intptr_t)v_12614 - (intptr_t)v_12613 + TAG_FIXNUM);
    stack[-4] = v_12613;
    v_12613 = stack[-4];
    stack[0] = v_12613;
v_12390:
    v_12613 = stack[0];
    v_12613 = ((intptr_t)(v_12613) < 0 ? lisp_true : nil);
    if (v_12613 == nil) goto v_12395;
    goto v_12389;
v_12395:
    goto v_12408;
v_12404:
    goto v_12413;
v_12409:
    v_12615 = stack[-3];
    goto v_12410;
v_12411:
    goto v_12419;
v_12415:
    v_12614 = stack[-1];
    goto v_12416;
v_12417:
    v_12613 = stack[0];
    goto v_12418;
v_12419:
    goto v_12415;
v_12416:
    goto v_12417;
v_12418:
    v_12613 = (LispObject)(intptr_t)((intptr_t)v_12614 + (intptr_t)v_12613 - TAG_FIXNUM);
    goto v_12412;
v_12413:
    goto v_12409;
v_12410:
    goto v_12411;
v_12412:
    v_12615 = *(LispObject *)((char *)v_12615 + (CELL-TAG_VECTOR) + (((intptr_t)v_12613-TAG_FIXNUM)/(16/CELL)));
    goto v_12405;
v_12406:
    goto v_12428;
v_12424:
    v_12614 = stack[-2];
    goto v_12425;
v_12426:
    v_12613 = stack[-1];
    goto v_12427;
v_12428:
    goto v_12424;
v_12425:
    goto v_12426;
v_12427:
    v_12613 = *(LispObject *)((char *)v_12614 + (CELL-TAG_VECTOR) + (((intptr_t)v_12613-TAG_FIXNUM)/(16/CELL)));
    goto v_12407;
v_12408:
    goto v_12404;
v_12405:
    goto v_12406;
v_12407:
    v_12613 = Lmodular_quotient(nil, v_12615, v_12613);
    env = stack[-5];
    v_12620 = v_12613;
    v_12613 = (LispObject)0+TAG_FIXNUM; // 0
    v_12619 = v_12613;
v_12435:
    goto v_12445;
v_12441:
    v_12613 = stack[-1];
    v_12614 = (LispObject)((intptr_t)(v_12613) - 0x10);
    goto v_12442;
v_12443:
    v_12613 = v_12619;
    goto v_12444;
v_12445:
    goto v_12441;
v_12442:
    goto v_12443;
v_12444:
    v_12613 = (LispObject)(intptr_t)((intptr_t)v_12614 - (intptr_t)v_12613 + TAG_FIXNUM);
    v_12613 = ((intptr_t)(v_12613) < 0 ? lisp_true : nil);
    if (v_12613 == nil) goto v_12440;
    goto v_12434;
v_12440:
    goto v_12458;
v_12452:
    v_12618 = stack[-3];
    goto v_12453;
v_12454:
    goto v_12464;
v_12460:
    v_12614 = stack[0];
    goto v_12461;
v_12462:
    v_12613 = v_12619;
    goto v_12463;
v_12464:
    goto v_12460;
v_12461:
    goto v_12462;
v_12463:
    v_12617 = (LispObject)(intptr_t)((intptr_t)v_12614 + (intptr_t)v_12613 - TAG_FIXNUM);
    goto v_12455;
v_12456:
    goto v_12472;
v_12468:
    goto v_12477;
v_12473:
    v_12615 = stack[-3];
    goto v_12474;
v_12475:
    goto v_12483;
v_12479:
    v_12614 = stack[0];
    goto v_12480;
v_12481:
    v_12613 = v_12619;
    goto v_12482;
v_12483:
    goto v_12479;
v_12480:
    goto v_12481;
v_12482:
    v_12613 = (LispObject)(intptr_t)((intptr_t)v_12614 + (intptr_t)v_12613 - TAG_FIXNUM);
    goto v_12476;
v_12477:
    goto v_12473;
v_12474:
    goto v_12475;
v_12476:
    v_12616 = *(LispObject *)((char *)v_12615 + (CELL-TAG_VECTOR) + (((intptr_t)v_12613-TAG_FIXNUM)/(16/CELL)));
    goto v_12469;
v_12470:
    goto v_12493;
v_12489:
    v_12615 = v_12620;
    goto v_12490;
v_12491:
    goto v_12499;
v_12495:
    v_12614 = stack[-2];
    goto v_12496;
v_12497:
    v_12613 = v_12619;
    goto v_12498;
v_12499:
    goto v_12495;
v_12496:
    goto v_12497;
v_12498:
    v_12613 = *(LispObject *)((char *)v_12614 + (CELL-TAG_VECTOR) + (((intptr_t)v_12613-TAG_FIXNUM)/(16/CELL)));
    goto v_12492;
v_12493:
    goto v_12489;
v_12490:
    goto v_12491;
v_12492:
    v_12613 = Lmodular_times(nil, v_12615, v_12613);
    env = stack[-5];
    goto v_12471;
v_12472:
    goto v_12468;
v_12469:
    goto v_12470;
v_12471:
    {   intptr_t w = int_of_fixnum(v_12616) - int_of_fixnum(v_12613);
        if (w < 0) w += current_modulus;
        v_12613 = fixnum_of_int(w);
    }
    goto v_12457;
v_12458:
    goto v_12452;
v_12453:
    goto v_12454;
v_12455:
    goto v_12456;
v_12457:
    *(LispObject *)((char *)v_12618 + (CELL-TAG_VECTOR) + (((intptr_t)v_12617-TAG_FIXNUM)/(16/CELL))) = v_12613;
    v_12613 = v_12619;
    v_12613 = (LispObject)((intptr_t)(v_12613) + 0x10);
    v_12619 = v_12613;
    goto v_12435;
v_12434:
    goto v_12512;
v_12506:
    v_12615 = stack[-3];
    goto v_12507;
v_12508:
    goto v_12518;
v_12514:
    v_12614 = stack[-1];
    goto v_12515;
v_12516:
    v_12613 = stack[0];
    goto v_12517;
v_12518:
    goto v_12514;
v_12515:
    goto v_12516;
v_12517:
    v_12613 = (LispObject)(intptr_t)((intptr_t)v_12614 + (intptr_t)v_12613 - TAG_FIXNUM);
    goto v_12509;
v_12510:
    v_12614 = v_12620;
    goto v_12511;
v_12512:
    goto v_12506;
v_12507:
    goto v_12508;
v_12509:
    goto v_12510;
v_12511:
    *(LispObject *)((char *)v_12615 + (CELL-TAG_VECTOR) + (((intptr_t)v_12613-TAG_FIXNUM)/(16/CELL))) = v_12614;
    v_12613 = stack[0];
    v_12613 = (LispObject)((intptr_t)(v_12613) - 0x10);
    stack[0] = v_12613;
    goto v_12390;
v_12389:
    v_12613 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_12613;
v_12528:
    goto v_12538;
v_12534:
    v_12613 = stack[-1];
    v_12614 = (LispObject)((intptr_t)(v_12613) - 0x10);
    goto v_12535;
v_12536:
    v_12613 = stack[0];
    goto v_12537;
v_12538:
    goto v_12534;
v_12535:
    goto v_12536;
v_12537:
    v_12613 = (LispObject)(intptr_t)((intptr_t)v_12614 - (intptr_t)v_12613 + TAG_FIXNUM);
    v_12613 = ((intptr_t)(v_12613) < 0 ? lisp_true : nil);
    if (v_12613 == nil) goto v_12533;
    goto v_12527;
v_12533:
    goto v_12553;
v_12549:
    goto v_12558;
v_12554:
    v_12614 = stack[-3];
    goto v_12555;
v_12556:
    v_12613 = stack[0];
    goto v_12557;
v_12558:
    goto v_12554;
v_12555:
    goto v_12556;
v_12557:
    v_12614 = *(LispObject *)((char *)v_12614 + (CELL-TAG_VECTOR) + (((intptr_t)v_12613-TAG_FIXNUM)/(16/CELL)));
    goto v_12550;
v_12551:
    v_12613 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12552;
v_12553:
    goto v_12549;
v_12550:
    goto v_12551;
v_12552:
    if (v_12614 == v_12613) goto v_12548;
    v_12613 = elt(env, 5); // "Quotient not exact in quotfail!-in!-vector"
    fn = elt(env, 6); // errorf
    v_12613 = (*qfn1(fn))(fn, v_12613);
    env = stack[-5];
    goto v_12546;
v_12548:
v_12546:
    v_12613 = stack[0];
    v_12613 = (LispObject)((intptr_t)(v_12613) + 0x10);
    stack[0] = v_12613;
    goto v_12528;
v_12527:
    v_12613 = (LispObject)0+TAG_FIXNUM; // 0
    v_12618 = v_12613;
v_12570:
    goto v_12580;
v_12576:
    v_12614 = stack[-4];
    goto v_12577;
v_12578:
    v_12613 = v_12618;
    goto v_12579;
v_12580:
    goto v_12576;
v_12577:
    goto v_12578;
v_12579:
    v_12613 = (LispObject)(intptr_t)((intptr_t)v_12614 - (intptr_t)v_12613 + TAG_FIXNUM);
    v_12613 = ((intptr_t)(v_12613) < 0 ? lisp_true : nil);
    if (v_12613 == nil) goto v_12575;
    goto v_12569;
v_12575:
    goto v_12592;
v_12586:
    v_12617 = stack[-3];
    goto v_12587;
v_12588:
    v_12616 = v_12618;
    goto v_12589;
v_12590:
    goto v_12599;
v_12595:
    v_12615 = stack[-3];
    goto v_12596;
v_12597:
    goto v_12605;
v_12601:
    v_12614 = stack[-1];
    goto v_12602;
v_12603:
    v_12613 = v_12618;
    goto v_12604;
v_12605:
    goto v_12601;
v_12602:
    goto v_12603;
v_12604:
    v_12613 = (LispObject)(intptr_t)((intptr_t)v_12614 + (intptr_t)v_12613 - TAG_FIXNUM);
    goto v_12598;
v_12599:
    goto v_12595;
v_12596:
    goto v_12597;
v_12598:
    v_12613 = *(LispObject *)((char *)v_12615 + (CELL-TAG_VECTOR) + (((intptr_t)v_12613-TAG_FIXNUM)/(16/CELL)));
    goto v_12591;
v_12592:
    goto v_12586;
v_12587:
    goto v_12588;
v_12589:
    goto v_12590;
v_12591:
    *(LispObject *)((char *)v_12617 + (CELL-TAG_VECTOR) + (((intptr_t)v_12616-TAG_FIXNUM)/(16/CELL))) = v_12613;
    v_12613 = v_12618;
    v_12613 = (LispObject)((intptr_t)(v_12613) + 0x10);
    v_12618 = v_12613;
    goto v_12570;
v_12569:
    v_12613 = stack[-4];
    goto v_12340;
    v_12613 = nil;
v_12340:
    return onevalue(v_12613);
}



// Code for carrassoc

static LispObject CC_carrassoc(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12366, v_12367;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12335;
    stack[-1] = v_12334;
// end of prologue
    goto v_12350;
v_12346:
    v_12367 = stack[-1];
    goto v_12347;
v_12348:
    v_12366 = stack[0];
    goto v_12349;
v_12350:
    goto v_12346;
v_12347:
    goto v_12348;
v_12349:
    fn = elt(env, 5); // rassoc
    v_12366 = (*qfn2(fn))(fn, v_12367, v_12366);
    env = stack[-2];
    v_12367 = v_12366;
    if (!consp(v_12366)) goto v_12344;
    v_12366 = v_12367;
    v_12366 = qcar(v_12366);
    goto v_12339;
v_12344:
    v_12366 = Lterpri(nil, 0);
    env = stack[-2];
    v_12366 = elt(env, 2); // "RASSOC trouble: "
    v_12366 = Lprinc(nil, v_12366);
    env = stack[-2];
    v_12366 = stack[-1];
    v_12366 = Lprin(nil, v_12366);
    env = stack[-2];
    v_12366 = elt(env, 3); // " "
    v_12366 = Lprinc(nil, v_12366);
    env = stack[-2];
    v_12366 = stack[0];
    v_12366 = Lprint(nil, v_12366);
    env = stack[-2];
    v_12366 = elt(env, 4); // "rassoc trouble"
    fn = elt(env, 6); // rederr
    v_12366 = (*qfn1(fn))(fn, v_12366);
    v_12366 = nil;
v_12339:
    return onevalue(v_12366);
}



// Code for gcref_select

static LispObject CC_gcref_select(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12442, v_12443, v_12444;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12334);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_12442 = v_12334;
// end of prologue
    stack[-3] = v_12442;
v_12341:
    v_12442 = stack[-3];
    if (v_12442 == nil) goto v_12346;
    else goto v_12347;
v_12346:
    v_12442 = nil;
    goto v_12340;
v_12347:
    v_12442 = stack[-3];
    v_12442 = qcar(v_12442);
    v_12444 = v_12442;
    goto v_12366;
v_12362:
    v_12443 = v_12444;
    goto v_12363;
v_12364:
    v_12442 = elt(env, 1); // defd
    goto v_12365;
v_12366:
    goto v_12362;
v_12363:
    goto v_12364;
v_12365:
    v_12442 = Lflagp(nil, v_12443, v_12442);
    env = stack[-4];
    if (v_12442 == nil) goto v_12360;
    goto v_12373;
v_12369:
    v_12443 = v_12444;
    goto v_12370;
v_12371:
    v_12442 = qvalue(elt(env, 2)); // gcref_nolist!*
    goto v_12372;
v_12373:
    goto v_12369;
v_12370:
    goto v_12371;
v_12372:
    v_12442 = Lmemq(nil, v_12443, v_12442);
    v_12442 = (v_12442 == nil ? lisp_true : nil);
    goto v_12358;
v_12360:
    v_12442 = nil;
    goto v_12358;
    v_12442 = nil;
v_12358:
    if (v_12442 == nil) goto v_12356;
    v_12442 = v_12444;
    v_12442 = ncons(v_12442);
    env = stack[-4];
    goto v_12354;
v_12356:
    v_12442 = nil;
v_12354:
    stack[-2] = v_12442;
    v_12442 = stack[-2];
    fn = elt(env, 3); // lastpair
    v_12442 = (*qfn1(fn))(fn, v_12442);
    env = stack[-4];
    stack[-1] = v_12442;
    v_12442 = stack[-3];
    v_12442 = qcdr(v_12442);
    stack[-3] = v_12442;
    v_12442 = stack[-1];
    if (!consp(v_12442)) goto v_12389;
    else goto v_12390;
v_12389:
    goto v_12341;
v_12390:
v_12342:
    v_12442 = stack[-3];
    if (v_12442 == nil) goto v_12394;
    else goto v_12395;
v_12394:
    v_12442 = stack[-2];
    goto v_12340;
v_12395:
    goto v_12403;
v_12399:
    stack[0] = stack[-1];
    goto v_12400;
v_12401:
    v_12442 = stack[-3];
    v_12442 = qcar(v_12442);
    v_12444 = v_12442;
    goto v_12421;
v_12417:
    v_12443 = v_12444;
    goto v_12418;
v_12419:
    v_12442 = elt(env, 1); // defd
    goto v_12420;
v_12421:
    goto v_12417;
v_12418:
    goto v_12419;
v_12420:
    v_12442 = Lflagp(nil, v_12443, v_12442);
    env = stack[-4];
    if (v_12442 == nil) goto v_12415;
    goto v_12428;
v_12424:
    v_12443 = v_12444;
    goto v_12425;
v_12426:
    v_12442 = qvalue(elt(env, 2)); // gcref_nolist!*
    goto v_12427;
v_12428:
    goto v_12424;
v_12425:
    goto v_12426;
v_12427:
    v_12442 = Lmemq(nil, v_12443, v_12442);
    v_12442 = (v_12442 == nil ? lisp_true : nil);
    goto v_12413;
v_12415:
    v_12442 = nil;
    goto v_12413;
    v_12442 = nil;
v_12413:
    if (v_12442 == nil) goto v_12411;
    v_12442 = v_12444;
    v_12442 = ncons(v_12442);
    env = stack[-4];
    goto v_12409;
v_12411:
    v_12442 = nil;
v_12409:
    goto v_12402;
v_12403:
    goto v_12399;
v_12400:
    goto v_12401;
v_12402:
    v_12442 = Lrplacd(nil, stack[0], v_12442);
    env = stack[-4];
    v_12442 = stack[-1];
    fn = elt(env, 3); // lastpair
    v_12442 = (*qfn1(fn))(fn, v_12442);
    env = stack[-4];
    stack[-1] = v_12442;
    v_12442 = stack[-3];
    v_12442 = qcdr(v_12442);
    stack[-3] = v_12442;
    goto v_12342;
v_12340:
    return onevalue(v_12442);
}



// Code for mk!+unit!+mat

static LispObject CC_mkLunitLmat(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12341;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12341 = v_12334;
// end of prologue
    {
        fn = elt(env, 1); // gen!+can!+bas
        return (*qfn1(fn))(fn, v_12341);
    }
    return onevalue(v_12341);
}



// Code for cl_flip

static LispObject CC_cl_flip(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12429, v_12430, v_12431;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12334);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12431 = v_12334;
// end of prologue
    goto v_12344;
v_12340:
    v_12430 = v_12431;
    goto v_12341;
v_12342:
    v_12429 = elt(env, 1); // and
    goto v_12343;
v_12344:
    goto v_12340;
v_12341:
    goto v_12342;
v_12343:
    if (v_12430 == v_12429) goto v_12338;
    else goto v_12339;
v_12338:
    v_12429 = elt(env, 2); // or
    goto v_12337;
v_12339:
    goto v_12354;
v_12350:
    v_12430 = v_12431;
    goto v_12351;
v_12352:
    v_12429 = elt(env, 2); // or
    goto v_12353;
v_12354:
    goto v_12350;
v_12351:
    goto v_12352;
v_12353:
    if (v_12430 == v_12429) goto v_12348;
    else goto v_12349;
v_12348:
    v_12429 = elt(env, 1); // and
    goto v_12337;
v_12349:
    goto v_12364;
v_12360:
    v_12430 = v_12431;
    goto v_12361;
v_12362:
    v_12429 = elt(env, 3); // all
    goto v_12363;
v_12364:
    goto v_12360;
v_12361:
    goto v_12362;
v_12363:
    if (v_12430 == v_12429) goto v_12358;
    else goto v_12359;
v_12358:
    v_12429 = elt(env, 4); // ex
    goto v_12337;
v_12359:
    goto v_12374;
v_12370:
    v_12430 = v_12431;
    goto v_12371;
v_12372:
    v_12429 = elt(env, 4); // ex
    goto v_12373;
v_12374:
    goto v_12370;
v_12371:
    goto v_12372;
v_12373:
    if (v_12430 == v_12429) goto v_12368;
    else goto v_12369;
v_12368:
    v_12429 = elt(env, 3); // all
    goto v_12337;
v_12369:
    goto v_12384;
v_12380:
    v_12430 = v_12431;
    goto v_12381;
v_12382:
    v_12429 = elt(env, 5); // ball
    goto v_12383;
v_12384:
    goto v_12380;
v_12381:
    goto v_12382;
v_12383:
    if (v_12430 == v_12429) goto v_12378;
    else goto v_12379;
v_12378:
    v_12429 = elt(env, 6); // bex
    goto v_12337;
v_12379:
    goto v_12394;
v_12390:
    v_12430 = v_12431;
    goto v_12391;
v_12392:
    v_12429 = elt(env, 6); // bex
    goto v_12393;
v_12394:
    goto v_12390;
v_12391:
    goto v_12392;
v_12393:
    if (v_12430 == v_12429) goto v_12388;
    else goto v_12389;
v_12388:
    v_12429 = elt(env, 5); // ball
    goto v_12337;
v_12389:
    goto v_12404;
v_12400:
    v_12430 = v_12431;
    goto v_12401;
v_12402:
    v_12429 = elt(env, 7); // true
    goto v_12403;
v_12404:
    goto v_12400;
v_12401:
    goto v_12402;
v_12403:
    if (v_12430 == v_12429) goto v_12398;
    else goto v_12399;
v_12398:
    v_12429 = elt(env, 8); // false
    goto v_12337;
v_12399:
    goto v_12414;
v_12410:
    v_12430 = v_12431;
    goto v_12411;
v_12412:
    v_12429 = elt(env, 8); // false
    goto v_12413;
v_12414:
    goto v_12410;
v_12411:
    goto v_12412;
v_12413:
    if (v_12430 == v_12429) goto v_12408;
    else goto v_12409;
v_12408:
    v_12429 = elt(env, 7); // true
    goto v_12337;
v_12409:
    goto v_12426;
v_12422:
    v_12429 = elt(env, 9); // "cl_flip(): don't know"
    goto v_12423;
v_12424:
    v_12430 = v_12431;
    goto v_12425;
v_12426:
    goto v_12422;
v_12423:
    goto v_12424;
v_12425:
    v_12429 = list2(v_12429, v_12430);
    env = stack[0];
    {
        fn = elt(env, 10); // rederr
        return (*qfn1(fn))(fn, v_12429);
    }
    v_12429 = nil;
v_12337:
    return onevalue(v_12429);
}



// Code for ps!:prepfn!:

static LispObject CC_psTprepfnT(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12337;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12337 = v_12334;
// end of prologue
    return onevalue(v_12337);
}



// Code for ps!:evaluate

static LispObject CC_psTevaluate(LispObject env,
                         LispObject v_12335, LispObject v_12336)
{
    env = qenv(env);
    LispObject v_12392, v_12393;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12336,v_12335);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12335,v_12336);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_12336;
    v_12392 = v_12335;
// end of prologue
// Binding ps
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = v_12392; // ps
    goto v_12351;
v_12347:
    v_12393 = qvalue(elt(env, 1)); // ps
    goto v_12348;
v_12349:
    v_12392 = stack[-2];
    goto v_12350;
v_12351:
    goto v_12347;
v_12348:
    goto v_12349;
v_12350:
    fn = elt(env, 3); // ps!:get!-term
    v_12392 = (*qfn2(fn))(fn, v_12393, v_12392);
    env = stack[-4];
    stack[-1] = v_12392;
    v_12392 = stack[-1];
    if (v_12392 == nil) goto v_12357;
    v_12392 = stack[-1];
    goto v_12344;
v_12357:
    v_12392 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 4); // ps!:last!-term
    v_12392 = (*qfn1(fn))(fn, v_12392);
    env = stack[-4];
    v_12392 = add1(v_12392);
    env = stack[-4];
    stack[0] = v_12392;
v_12363:
    goto v_12377;
v_12373:
    v_12393 = stack[-2];
    goto v_12374;
v_12375:
    v_12392 = stack[0];
    goto v_12376;
v_12377:
    goto v_12373;
v_12374:
    goto v_12375;
v_12376:
    v_12392 = difference2(v_12393, v_12392);
    env = stack[-4];
    v_12392 = Lminusp(nil, v_12392);
    env = stack[-4];
    if (v_12392 == nil) goto v_12370;
    goto v_12362;
v_12370:
    goto v_12386;
v_12382:
    v_12393 = qvalue(elt(env, 1)); // ps
    goto v_12383;
v_12384:
    v_12392 = stack[0];
    goto v_12385;
v_12386:
    goto v_12382;
v_12383:
    goto v_12384;
v_12385:
    fn = elt(env, 5); // ps!:evaluate!-next
    v_12392 = (*qfn2(fn))(fn, v_12393, v_12392);
    env = stack[-4];
    stack[-1] = v_12392;
    v_12392 = stack[0];
    v_12392 = add1(v_12392);
    env = stack[-4];
    stack[0] = v_12392;
    goto v_12363;
v_12362:
    v_12392 = stack[-1];
v_12344:
    ;}  // end of a binding scope
    return onevalue(v_12392);
}



// Code for partitexdf

static LispObject CC_partitexdf(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12340;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12334);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12340 = v_12334;
// end of prologue
    v_12340 = qcar(v_12340);
    fn = elt(env, 1); // partitop
    v_12340 = (*qfn1(fn))(fn, v_12340);
    env = stack[0];
    {
        fn = elt(env, 2); // exdfpf
        return (*qfn1(fn))(fn, v_12340);
    }
}



// Code for indordp

static LispObject CC_indordp(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12395, v_12396, v_12397, v_12398, v_12399;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12397 = v_12335;
    v_12398 = v_12334;
// end of prologue
    v_12395 = qvalue(elt(env, 2)); // indxl!*
    v_12399 = v_12395;
    goto v_12351;
v_12347:
    v_12396 = v_12398;
    goto v_12348;
v_12349:
    v_12395 = v_12399;
    goto v_12350;
v_12351:
    goto v_12347;
v_12348:
    goto v_12349;
v_12350:
    v_12395 = Lmemq(nil, v_12396, v_12395);
    if (v_12395 == nil) goto v_12345;
    else goto v_12346;
v_12345:
    v_12395 = lisp_true;
    goto v_12339;
v_12346:
v_12340:
    v_12395 = v_12399;
    if (v_12395 == nil) goto v_12358;
    else goto v_12359;
v_12358:
    goto v_12366;
v_12362:
    v_12395 = v_12398;
    goto v_12363;
v_12364:
    v_12396 = v_12397;
    goto v_12365;
v_12366:
    goto v_12362;
v_12363:
    goto v_12364;
v_12365:
        return Lorderp(nil, v_12395, v_12396);
v_12359:
    goto v_12377;
v_12373:
    v_12396 = v_12398;
    goto v_12374;
v_12375:
    v_12395 = v_12399;
    v_12395 = qcar(v_12395);
    goto v_12376;
v_12377:
    goto v_12373;
v_12374:
    goto v_12375;
v_12376:
    if (v_12396 == v_12395) goto v_12371;
    else goto v_12372;
v_12371:
    v_12395 = lisp_true;
    goto v_12339;
v_12372:
    goto v_12388;
v_12384:
    v_12396 = v_12397;
    goto v_12385;
v_12386:
    v_12395 = v_12399;
    v_12395 = qcar(v_12395);
    goto v_12387;
v_12388:
    goto v_12384;
v_12385:
    goto v_12386;
v_12387:
    if (v_12396 == v_12395) goto v_12382;
    else goto v_12383;
v_12382:
    v_12395 = nil;
    goto v_12339;
v_12383:
    v_12395 = v_12399;
    v_12395 = qcdr(v_12395);
    v_12399 = v_12395;
    goto v_12340;
v_12339:
    return onevalue(v_12395);
}



// Code for assert_format

static LispObject CC_assert_format(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12488, v_12489, v_12490;
    LispObject v_12336, v_12335, v_12334;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "assert_format");
    va_start(aa, nargs);
    v_12334 = va_arg(aa, LispObject);
    v_12335 = va_arg(aa, LispObject);
    v_12336 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12336,v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12334,v_12335,v_12336);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    v_12488 = v_12336;
    stack[-8] = v_12335;
    stack[-9] = v_12334;
// end of prologue
    v_12488 = Lexplode(nil, v_12488);
    env = stack[-11];
    stack[-10] = v_12488;
    goto v_12351;
v_12345:
    stack[-7] = elt(env, 2); // !!
    goto v_12346;
v_12347:
    stack[-6] = elt(env, 3); // !)
    goto v_12348;
v_12349:
    goto v_12361;
v_12355:
    stack[-5] = elt(env, 2); // !!
    goto v_12356;
v_12357:
    stack[-4] = elt(env, 4); // ! 
    goto v_12358;
v_12359:
    goto v_12371;
v_12365:
    stack[-3] = elt(env, 2); // !!
    goto v_12366;
v_12367:
    stack[-2] = elt(env, 5); // !-
    goto v_12368;
v_12369:
    goto v_12381;
v_12375:
    stack[-1] = elt(env, 2); // !!
    goto v_12376;
v_12377:
    stack[0] = elt(env, 6); // !>
    goto v_12378;
v_12379:
    goto v_12391;
v_12385:
    v_12490 = elt(env, 2); // !!
    goto v_12386;
v_12387:
    v_12489 = elt(env, 4); // ! 
    goto v_12388;
v_12389:
    v_12488 = stack[-10];
    goto v_12390;
v_12391:
    goto v_12385;
v_12386:
    goto v_12387;
v_12388:
    goto v_12389;
v_12390:
    v_12488 = list2star(v_12490, v_12489, v_12488);
    env = stack[-11];
    goto v_12380;
v_12381:
    goto v_12375;
v_12376:
    goto v_12377;
v_12378:
    goto v_12379;
v_12380:
    v_12488 = list2star(stack[-1], stack[0], v_12488);
    env = stack[-11];
    goto v_12370;
v_12371:
    goto v_12365;
v_12366:
    goto v_12367;
v_12368:
    goto v_12369;
v_12370:
    v_12488 = list2star(stack[-3], stack[-2], v_12488);
    env = stack[-11];
    goto v_12360;
v_12361:
    goto v_12355;
v_12356:
    goto v_12357;
v_12358:
    goto v_12359;
v_12360:
    v_12488 = list2star(stack[-5], stack[-4], v_12488);
    env = stack[-11];
    goto v_12350;
v_12351:
    goto v_12345;
v_12346:
    goto v_12347;
v_12348:
    goto v_12349;
v_12350:
    v_12488 = list2star(stack[-7], stack[-6], v_12488);
    env = stack[-11];
    stack[-10] = v_12488;
    v_12488 = stack[-8];
    v_12488 = Lreverse(nil, v_12488);
    env = stack[-11];
    stack[-4] = v_12488;
v_12398:
    v_12488 = stack[-4];
    if (v_12488 == nil) goto v_12403;
    else goto v_12404;
v_12403:
    goto v_12397;
v_12404:
    v_12488 = stack[-4];
    v_12488 = qcar(v_12488);
    goto v_12417;
v_12411:
    stack[-3] = elt(env, 2); // !!
    goto v_12412;
v_12413:
    stack[-2] = elt(env, 7); // !,
    goto v_12414;
v_12415:
    goto v_12427;
v_12421:
    stack[-1] = elt(env, 2); // !!
    goto v_12422;
v_12423:
    stack[0] = elt(env, 4); // ! 
    goto v_12424;
v_12425:
    goto v_12435;
v_12431:
    v_12489 = Lexplode(nil, v_12488);
    env = stack[-11];
    goto v_12432;
v_12433:
    v_12488 = stack[-10];
    goto v_12434;
v_12435:
    goto v_12431;
v_12432:
    goto v_12433;
v_12434:
    v_12488 = Lnconc(nil, v_12489, v_12488);
    env = stack[-11];
    goto v_12426;
v_12427:
    goto v_12421;
v_12422:
    goto v_12423;
v_12424:
    goto v_12425;
v_12426:
    v_12488 = list2star(stack[-1], stack[0], v_12488);
    env = stack[-11];
    goto v_12416;
v_12417:
    goto v_12411;
v_12412:
    goto v_12413;
v_12414:
    goto v_12415;
v_12416:
    v_12488 = list2star(stack[-3], stack[-2], v_12488);
    env = stack[-11];
    stack[-10] = v_12488;
    v_12488 = stack[-4];
    v_12488 = qcdr(v_12488);
    stack[-4] = v_12488;
    goto v_12398;
v_12397:
    v_12488 = stack[-10];
    v_12488 = qcdr(v_12488);
    v_12488 = qcdr(v_12488);
    v_12488 = qcdr(v_12488);
    v_12488 = qcdr(v_12488);
    stack[-10] = v_12488;
    goto v_12453;
v_12447:
    stack[-3] = elt(env, 2); // !!
    goto v_12448;
v_12449:
    stack[-2] = elt(env, 8); // !:
    goto v_12450;
v_12451:
    goto v_12463;
v_12457:
    stack[-1] = elt(env, 2); // !!
    goto v_12458;
v_12459:
    stack[0] = elt(env, 4); // ! 
    goto v_12460;
v_12461:
    goto v_12473;
v_12467:
    v_12490 = elt(env, 2); // !!
    goto v_12468;
v_12469:
    v_12489 = elt(env, 9); // !(
    goto v_12470;
v_12471:
    v_12488 = stack[-10];
    goto v_12472;
v_12473:
    goto v_12467;
v_12468:
    goto v_12469;
v_12470:
    goto v_12471;
v_12472:
    v_12488 = list2star(v_12490, v_12489, v_12488);
    env = stack[-11];
    goto v_12462;
v_12463:
    goto v_12457;
v_12458:
    goto v_12459;
v_12460:
    goto v_12461;
v_12462:
    v_12488 = list2star(stack[-1], stack[0], v_12488);
    env = stack[-11];
    goto v_12452;
v_12453:
    goto v_12447;
v_12448:
    goto v_12449;
v_12450:
    goto v_12451;
v_12452:
    v_12488 = list2star(stack[-3], stack[-2], v_12488);
    env = stack[-11];
    stack[-10] = v_12488;
    goto v_12482;
v_12478:
    v_12488 = stack[-9];
    v_12489 = Lexplode(nil, v_12488);
    env = stack[-11];
    goto v_12479;
v_12480:
    v_12488 = stack[-10];
    goto v_12481;
v_12482:
    goto v_12478;
v_12479:
    goto v_12480;
v_12481:
    v_12488 = Lnconc(nil, v_12489, v_12488);
    stack[-10] = v_12488;
    v_12488 = stack[-10];
        return Lcompress(nil, v_12488);
    return onevalue(v_12488);
}



// Code for lienjactest

static LispObject CC_lienjactest(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12748, v_12749, v_12750, v_12751;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12334);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(14);
// copy arguments values to proper place
    stack[-11] = v_12334;
// end of prologue
    goto v_12343;
v_12339:
    stack[0] = elt(env, 1); // lie_jtest
    goto v_12340;
v_12341:
    v_12748 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 6); // aeval
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    goto v_12342;
v_12343:
    goto v_12339;
v_12340:
    goto v_12341;
v_12342:
    fn = elt(env, 7); // setk
    v_12748 = (*qfn2(fn))(fn, stack[0], v_12748);
    env = stack[-13];
    v_12748 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-12] = v_12748;
v_12350:
    goto v_12364;
v_12358:
    stack[0] = elt(env, 2); // difference
    goto v_12359;
v_12360:
    goto v_12374;
v_12368:
    v_12750 = elt(env, 2); // difference
    goto v_12369;
v_12370:
    v_12749 = stack[-11];
    goto v_12371;
v_12372:
    v_12748 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_12373;
v_12374:
    goto v_12368;
v_12369:
    goto v_12370;
v_12371:
    goto v_12372;
v_12373:
    v_12748 = list3(v_12750, v_12749, v_12748);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_12749 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    goto v_12361;
v_12362:
    v_12748 = stack[-12];
    goto v_12363;
v_12364:
    goto v_12358;
v_12359:
    goto v_12360;
v_12361:
    goto v_12362;
v_12363:
    v_12748 = list3(stack[0], v_12749, v_12748);
    env = stack[-13];
    fn = elt(env, 9); // aminusp!:
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    if (v_12748 == nil) goto v_12355;
    goto v_12349;
v_12355:
    v_12748 = stack[-12];
    v_12748 = add1(v_12748);
    env = stack[-13];
    stack[-10] = v_12748;
v_12383:
    goto v_12398;
v_12392:
    stack[0] = elt(env, 2); // difference
    goto v_12393;
v_12394:
    goto v_12408;
v_12402:
    v_12750 = elt(env, 2); // difference
    goto v_12403;
v_12404:
    v_12749 = stack[-11];
    goto v_12405;
v_12406:
    v_12748 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12407;
v_12408:
    goto v_12402;
v_12403:
    goto v_12404;
v_12405:
    goto v_12406;
v_12407:
    v_12748 = list3(v_12750, v_12749, v_12748);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_12749 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    goto v_12395;
v_12396:
    v_12748 = stack[-10];
    goto v_12397;
v_12398:
    goto v_12392;
v_12393:
    goto v_12394;
v_12395:
    goto v_12396;
v_12397:
    v_12748 = list3(stack[0], v_12749, v_12748);
    env = stack[-13];
    fn = elt(env, 9); // aminusp!:
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    if (v_12748 == nil) goto v_12389;
    goto v_12382;
v_12389:
    v_12748 = stack[-10];
    v_12748 = add1(v_12748);
    env = stack[-13];
    stack[-9] = v_12748;
v_12417:
    goto v_12432;
v_12426:
    stack[0] = elt(env, 2); // difference
    goto v_12427;
v_12428:
    v_12748 = stack[-11];
    fn = elt(env, 8); // aeval!*
    v_12749 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    goto v_12429;
v_12430:
    v_12748 = stack[-9];
    goto v_12431;
v_12432:
    goto v_12426;
v_12427:
    goto v_12428;
v_12429:
    goto v_12430;
v_12431:
    v_12748 = list3(stack[0], v_12749, v_12748);
    env = stack[-13];
    fn = elt(env, 9); // aminusp!:
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    if (v_12748 == nil) goto v_12423;
    goto v_12416;
v_12423:
    v_12748 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_12748;
v_12441:
    goto v_12455;
v_12449:
    stack[0] = elt(env, 2); // difference
    goto v_12450;
v_12451:
    v_12748 = stack[-11];
    fn = elt(env, 8); // aeval!*
    v_12749 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    goto v_12452;
v_12453:
    v_12748 = stack[-8];
    goto v_12454;
v_12455:
    goto v_12449;
v_12450:
    goto v_12451;
v_12452:
    goto v_12453;
v_12454:
    v_12748 = list3(stack[0], v_12749, v_12748);
    env = stack[-13];
    fn = elt(env, 9); // aminusp!:
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    if (v_12748 == nil) goto v_12446;
    goto v_12440;
v_12446:
    goto v_12470;
v_12466:
    v_12748 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-7] = v_12748;
    v_12748 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_12748;
v_12475:
    goto v_12490;
v_12484:
    stack[0] = elt(env, 2); // difference
    goto v_12485;
v_12486:
    v_12748 = stack[-11];
    fn = elt(env, 8); // aeval!*
    v_12749 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    goto v_12487;
v_12488:
    v_12748 = stack[-7];
    goto v_12489;
v_12490:
    goto v_12484;
v_12485:
    goto v_12486;
v_12487:
    goto v_12488;
v_12489:
    v_12748 = list3(stack[0], v_12749, v_12748);
    env = stack[-13];
    fn = elt(env, 9); // aminusp!:
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    if (v_12748 == nil) goto v_12481;
    v_12748 = stack[-6];
    v_12749 = v_12748;
    goto v_12474;
v_12481:
    goto v_12504;
v_12498:
    stack[-5] = elt(env, 3); // plus
    goto v_12499;
v_12500:
    goto v_12516;
v_12508:
    stack[-4] = elt(env, 3); // plus
    goto v_12509;
v_12510:
    goto v_12525;
v_12519:
    stack[-1] = elt(env, 4); // times
    goto v_12520;
v_12521:
    goto v_12536;
v_12528:
    v_12751 = elt(env, 5); // lie_cc
    goto v_12529;
v_12530:
    v_12750 = stack[-10];
    goto v_12531;
v_12532:
    v_12749 = stack[-9];
    goto v_12533;
v_12534:
    v_12748 = stack[-7];
    goto v_12535;
v_12536:
    goto v_12528;
v_12529:
    goto v_12530;
v_12531:
    goto v_12532;
v_12533:
    goto v_12534;
v_12535:
    stack[0] = list4(v_12751, v_12750, v_12749, v_12748);
    env = stack[-13];
    goto v_12522;
v_12523:
    goto v_12550;
v_12542:
    v_12751 = elt(env, 5); // lie_cc
    goto v_12543;
v_12544:
    v_12750 = stack[-12];
    goto v_12545;
v_12546:
    v_12749 = stack[-7];
    goto v_12547;
v_12548:
    v_12748 = stack[-8];
    goto v_12549;
v_12550:
    goto v_12542;
v_12543:
    goto v_12544;
v_12545:
    goto v_12546;
v_12547:
    goto v_12548;
v_12549:
    v_12748 = list4(v_12751, v_12750, v_12749, v_12748);
    env = stack[-13];
    goto v_12524;
v_12525:
    goto v_12519;
v_12520:
    goto v_12521;
v_12522:
    goto v_12523;
v_12524:
    stack[-3] = list3(stack[-1], stack[0], v_12748);
    env = stack[-13];
    goto v_12511;
v_12512:
    goto v_12562;
v_12556:
    stack[-1] = elt(env, 4); // times
    goto v_12557;
v_12558:
    goto v_12573;
v_12565:
    v_12751 = elt(env, 5); // lie_cc
    goto v_12566;
v_12567:
    v_12750 = stack[-12];
    goto v_12568;
v_12569:
    v_12749 = stack[-10];
    goto v_12570;
v_12571:
    v_12748 = stack[-7];
    goto v_12572;
v_12573:
    goto v_12565;
v_12566:
    goto v_12567;
v_12568:
    goto v_12569;
v_12570:
    goto v_12571;
v_12572:
    stack[0] = list4(v_12751, v_12750, v_12749, v_12748);
    env = stack[-13];
    goto v_12559;
v_12560:
    goto v_12587;
v_12579:
    v_12751 = elt(env, 5); // lie_cc
    goto v_12580;
v_12581:
    v_12750 = stack[-9];
    goto v_12582;
v_12583:
    v_12749 = stack[-7];
    goto v_12584;
v_12585:
    v_12748 = stack[-8];
    goto v_12586;
v_12587:
    goto v_12579;
v_12580:
    goto v_12581;
v_12582:
    goto v_12583;
v_12584:
    goto v_12585;
v_12586:
    v_12748 = list4(v_12751, v_12750, v_12749, v_12748);
    env = stack[-13];
    goto v_12561;
v_12562:
    goto v_12556;
v_12557:
    goto v_12558;
v_12559:
    goto v_12560;
v_12561:
    stack[-2] = list3(stack[-1], stack[0], v_12748);
    env = stack[-13];
    goto v_12513;
v_12514:
    goto v_12599;
v_12593:
    stack[-1] = elt(env, 4); // times
    goto v_12594;
v_12595:
    goto v_12610;
v_12602:
    v_12751 = elt(env, 5); // lie_cc
    goto v_12603;
v_12604:
    v_12750 = stack[-9];
    goto v_12605;
v_12606:
    v_12749 = stack[-12];
    goto v_12607;
v_12608:
    v_12748 = stack[-7];
    goto v_12609;
v_12610:
    goto v_12602;
v_12603:
    goto v_12604;
v_12605:
    goto v_12606;
v_12607:
    goto v_12608;
v_12609:
    stack[0] = list4(v_12751, v_12750, v_12749, v_12748);
    env = stack[-13];
    goto v_12596;
v_12597:
    goto v_12624;
v_12616:
    v_12751 = elt(env, 5); // lie_cc
    goto v_12617;
v_12618:
    v_12750 = stack[-10];
    goto v_12619;
v_12620:
    v_12749 = stack[-7];
    goto v_12621;
v_12622:
    v_12748 = stack[-8];
    goto v_12623;
v_12624:
    goto v_12616;
v_12617:
    goto v_12618;
v_12619:
    goto v_12620;
v_12621:
    goto v_12622;
v_12623:
    v_12748 = list4(v_12751, v_12750, v_12749, v_12748);
    env = stack[-13];
    goto v_12598;
v_12599:
    goto v_12593;
v_12594:
    goto v_12595;
v_12596:
    goto v_12597;
v_12598:
    v_12748 = list3(stack[-1], stack[0], v_12748);
    env = stack[-13];
    goto v_12515;
v_12516:
    goto v_12508;
v_12509:
    goto v_12510;
v_12511:
    goto v_12512;
v_12513:
    goto v_12514;
v_12515:
    v_12748 = list4(stack[-4], stack[-3], stack[-2], v_12748);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_12749 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    goto v_12501;
v_12502:
    v_12748 = stack[-6];
    goto v_12503;
v_12504:
    goto v_12498;
v_12499:
    goto v_12500;
v_12501:
    goto v_12502;
v_12503:
    v_12748 = list3(stack[-5], v_12749, v_12748);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    stack[-6] = v_12748;
    v_12748 = stack[-7];
    goto v_12640;
v_12634:
    v_12750 = elt(env, 3); // plus
    goto v_12635;
v_12636:
    v_12749 = v_12748;
    goto v_12637;
v_12638:
    v_12748 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12639;
v_12640:
    goto v_12634;
v_12635:
    goto v_12636;
v_12637:
    goto v_12638;
v_12639:
    v_12748 = list3(v_12750, v_12749, v_12748);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    stack[-7] = v_12748;
    goto v_12475;
v_12474:
    goto v_12467;
v_12468:
    v_12748 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12469;
v_12470:
    goto v_12466;
v_12467:
    goto v_12468;
v_12469:
    fn = elt(env, 10); // evalneq
    v_12748 = (*qfn2(fn))(fn, v_12749, v_12748);
    env = stack[-13];
    if (v_12748 == nil) goto v_12464;
    goto v_12650;
v_12646:
    stack[0] = elt(env, 1); // lie_jtest
    goto v_12647;
v_12648:
    v_12748 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 8); // aeval!*
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    goto v_12649;
v_12650:
    goto v_12646;
v_12647:
    goto v_12648;
v_12649:
    fn = elt(env, 7); // setk
    v_12748 = (*qfn2(fn))(fn, stack[0], v_12748);
    env = stack[-13];
    goto v_12662;
v_12656:
    v_12750 = elt(env, 2); // difference
    goto v_12657;
v_12658:
    v_12749 = stack[-11];
    goto v_12659;
v_12660:
    v_12748 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12661;
v_12662:
    goto v_12656;
v_12657:
    goto v_12658;
v_12659:
    goto v_12660;
v_12661:
    v_12748 = list3(v_12750, v_12749, v_12748);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    stack[-12] = v_12748;
    v_12748 = stack[-11];
    fn = elt(env, 8); // aeval!*
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    stack[-10] = v_12748;
    goto v_12676;
v_12670:
    v_12750 = elt(env, 3); // plus
    goto v_12671;
v_12672:
    v_12749 = stack[-11];
    goto v_12673;
v_12674:
    v_12748 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12675;
v_12676:
    goto v_12670;
v_12671:
    goto v_12672;
v_12673:
    goto v_12674;
v_12675:
    v_12748 = list3(v_12750, v_12749, v_12748);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    stack[-9] = v_12748;
    goto v_12688;
v_12682:
    v_12750 = elt(env, 3); // plus
    goto v_12683;
v_12684:
    v_12749 = stack[-11];
    goto v_12685;
v_12686:
    v_12748 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12687;
v_12688:
    goto v_12682;
v_12683:
    goto v_12684;
v_12685:
    goto v_12686;
v_12687:
    v_12748 = list3(v_12750, v_12749, v_12748);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    stack[-8] = v_12748;
    goto v_12462;
v_12464:
v_12462:
    v_12748 = stack[-8];
    goto v_12702;
v_12696:
    v_12750 = elt(env, 3); // plus
    goto v_12697;
v_12698:
    v_12749 = v_12748;
    goto v_12699;
v_12700:
    v_12748 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12701;
v_12702:
    goto v_12696;
v_12697:
    goto v_12698;
v_12699:
    goto v_12700;
v_12701:
    v_12748 = list3(v_12750, v_12749, v_12748);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    stack[-8] = v_12748;
    goto v_12441;
v_12440:
    v_12748 = stack[-9];
    goto v_12716;
v_12710:
    v_12750 = elt(env, 3); // plus
    goto v_12711;
v_12712:
    v_12749 = v_12748;
    goto v_12713;
v_12714:
    v_12748 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12715;
v_12716:
    goto v_12710;
v_12711:
    goto v_12712;
v_12713:
    goto v_12714;
v_12715:
    v_12748 = list3(v_12750, v_12749, v_12748);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    stack[-9] = v_12748;
    goto v_12417;
v_12416:
    v_12748 = stack[-10];
    goto v_12730;
v_12724:
    v_12750 = elt(env, 3); // plus
    goto v_12725;
v_12726:
    v_12749 = v_12748;
    goto v_12727;
v_12728:
    v_12748 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12729;
v_12730:
    goto v_12724;
v_12725:
    goto v_12726;
v_12727:
    goto v_12728;
v_12729:
    v_12748 = list3(v_12750, v_12749, v_12748);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    stack[-10] = v_12748;
    goto v_12383;
v_12382:
    v_12748 = stack[-12];
    goto v_12744;
v_12738:
    v_12750 = elt(env, 3); // plus
    goto v_12739;
v_12740:
    v_12749 = v_12748;
    goto v_12741;
v_12742:
    v_12748 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12743;
v_12744:
    goto v_12738;
v_12739:
    goto v_12740;
v_12741:
    goto v_12742;
v_12743:
    v_12748 = list3(v_12750, v_12749, v_12748);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_12748 = (*qfn1(fn))(fn, v_12748);
    env = stack[-13];
    stack[-12] = v_12748;
    goto v_12350;
v_12349:
    v_12748 = nil;
    return onevalue(v_12748);
}



// Code for sf2mv1

static LispObject CC_sf2mv1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12447, v_12448, v_12449;
    LispObject fn;
    LispObject v_12336, v_12335, v_12334;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sf2mv1");
    va_start(aa, nargs);
    v_12334 = va_arg(aa, LispObject);
    v_12335 = va_arg(aa, LispObject);
    v_12336 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12336,v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12334,v_12335,v_12336);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_12336;
    stack[-2] = v_12335;
    stack[-3] = v_12334;
// end of prologue
v_12340:
    v_12447 = stack[-3];
    if (v_12447 == nil) goto v_12343;
    else goto v_12344;
v_12343:
    v_12447 = nil;
    goto v_12339;
v_12344:
    v_12447 = stack[-3];
    if (!consp(v_12447)) goto v_12351;
    else goto v_12352;
v_12351:
    v_12447 = lisp_true;
    goto v_12350;
v_12352:
    v_12447 = stack[-3];
    v_12447 = qcar(v_12447);
    v_12447 = (consp(v_12447) ? nil : lisp_true);
    goto v_12350;
    v_12447 = nil;
v_12350:
    if (v_12447 == nil) goto v_12348;
    goto v_12366;
v_12362:
    goto v_12372;
v_12368:
    stack[0] = stack[-2];
    goto v_12369;
v_12370:
    v_12447 = stack[-1];
    v_12447 = Llength(nil, v_12447);
    env = stack[-5];
    fn = elt(env, 1); // nzeros
    v_12447 = (*qfn1(fn))(fn, v_12447);
    env = stack[-5];
    goto v_12371;
v_12372:
    goto v_12368;
v_12369:
    goto v_12370;
v_12371:
    v_12448 = Lappend(nil, stack[0], v_12447);
    env = stack[-5];
    goto v_12363;
v_12364:
    v_12447 = stack[-3];
    goto v_12365;
v_12366:
    goto v_12362;
v_12363:
    goto v_12364;
v_12365:
    v_12447 = cons(v_12448, v_12447);
    return ncons(v_12447);
v_12348:
    goto v_12384;
v_12380:
    v_12447 = stack[-3];
    v_12447 = qcar(v_12447);
    v_12447 = qcar(v_12447);
    v_12448 = qcar(v_12447);
    goto v_12381;
v_12382:
    v_12447 = stack[-1];
    v_12447 = qcar(v_12447);
    goto v_12383;
v_12384:
    goto v_12380;
v_12381:
    goto v_12382;
v_12383:
    if (equal(v_12448, v_12447)) goto v_12378;
    else goto v_12379;
v_12378:
    goto v_12396;
v_12392:
    goto v_12404;
v_12398:
    v_12447 = stack[-3];
    v_12447 = qcar(v_12447);
    stack[-4] = qcdr(v_12447);
    goto v_12399;
v_12400:
    goto v_12413;
v_12409:
    stack[0] = stack[-2];
    goto v_12410;
v_12411:
    v_12447 = stack[-3];
    v_12447 = qcar(v_12447);
    v_12447 = qcar(v_12447);
    v_12447 = qcdr(v_12447);
    v_12447 = ncons(v_12447);
    env = stack[-5];
    goto v_12412;
v_12413:
    goto v_12409;
v_12410:
    goto v_12411;
v_12412:
    v_12448 = Lappend(nil, stack[0], v_12447);
    env = stack[-5];
    goto v_12401;
v_12402:
    v_12447 = stack[-1];
    v_12447 = qcdr(v_12447);
    goto v_12403;
v_12404:
    goto v_12398;
v_12399:
    goto v_12400;
v_12401:
    goto v_12402;
v_12403:
    stack[0] = CC_sf2mv1(elt(env, 0), 3, stack[-4], v_12448, v_12447);
    env = stack[-5];
    goto v_12393;
v_12394:
    goto v_12429;
v_12423:
    v_12447 = stack[-3];
    v_12449 = qcdr(v_12447);
    goto v_12424;
v_12425:
    v_12448 = stack[-2];
    goto v_12426;
v_12427:
    v_12447 = stack[-1];
    goto v_12428;
v_12429:
    goto v_12423;
v_12424:
    goto v_12425;
v_12426:
    goto v_12427;
v_12428:
    v_12447 = CC_sf2mv1(elt(env, 0), 3, v_12449, v_12448, v_12447);
    goto v_12395;
v_12396:
    goto v_12392;
v_12393:
    goto v_12394;
v_12395:
    {
        LispObject v_12455 = stack[0];
        return Lappend(nil, v_12455, v_12447);
    }
v_12379:
    goto v_12441;
v_12437:
    stack[0] = stack[-2];
    goto v_12438;
v_12439:
    v_12447 = (LispObject)0+TAG_FIXNUM; // 0
    v_12447 = ncons(v_12447);
    env = stack[-5];
    goto v_12440;
v_12441:
    goto v_12437;
v_12438:
    goto v_12439;
v_12440:
    v_12447 = Lappend(nil, stack[0], v_12447);
    env = stack[-5];
    stack[-2] = v_12447;
    v_12447 = stack[-1];
    v_12447 = qcdr(v_12447);
    stack[-1] = v_12447;
    goto v_12340;
    v_12447 = nil;
v_12339:
    return onevalue(v_12447);
}



// Code for mo_lcm

static LispObject CC_mo_lcm(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12416, v_12417;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_12417 = v_12335;
    v_12416 = v_12334;
// end of prologue
    stack[-2] = nil;
    v_12416 = qcar(v_12416);
    stack[-1] = v_12416;
    v_12416 = v_12417;
    v_12416 = qcar(v_12416);
    stack[0] = v_12416;
v_12349:
    v_12416 = stack[-1];
    if (v_12416 == nil) goto v_12352;
    v_12416 = stack[0];
    if (v_12416 == nil) goto v_12352;
    goto v_12353;
v_12352:
    goto v_12348;
v_12353:
    goto v_12364;
v_12360:
    goto v_12373;
v_12369:
    v_12416 = stack[-1];
    v_12417 = qcar(v_12416);
    goto v_12370;
v_12371:
    v_12416 = stack[0];
    v_12416 = qcar(v_12416);
    goto v_12372;
v_12373:
    goto v_12369;
v_12370:
    goto v_12371;
v_12372:
    if (((intptr_t)(v_12417)) > ((intptr_t)(v_12416))) goto v_12367;
    else goto v_12368;
v_12367:
    v_12416 = stack[-1];
    v_12416 = qcar(v_12416);
    v_12417 = v_12416;
    goto v_12366;
v_12368:
    v_12416 = stack[0];
    v_12416 = qcar(v_12416);
    v_12417 = v_12416;
    goto v_12366;
    v_12417 = nil;
v_12366:
    goto v_12361;
v_12362:
    v_12416 = stack[-2];
    goto v_12363;
v_12364:
    goto v_12360;
v_12361:
    goto v_12362;
v_12363:
    v_12416 = cons(v_12417, v_12416);
    env = stack[-3];
    stack[-2] = v_12416;
    v_12416 = stack[-1];
    v_12416 = qcdr(v_12416);
    stack[-1] = v_12416;
    v_12416 = stack[0];
    v_12416 = qcdr(v_12416);
    stack[0] = v_12416;
    goto v_12349;
v_12348:
    goto v_12394;
v_12390:
    v_12416 = stack[-2];
    v_12417 = Lnreverse(nil, v_12416);
    env = stack[-3];
    goto v_12391;
v_12392:
    v_12416 = stack[-1];
    if (v_12416 == nil) goto v_12400;
    v_12416 = stack[-1];
    goto v_12398;
v_12400:
    v_12416 = stack[0];
    goto v_12398;
    v_12416 = nil;
v_12398:
    goto v_12393;
v_12394:
    goto v_12390;
v_12391:
    goto v_12392;
v_12393:
    v_12416 = Lappend(nil, v_12417, v_12416);
    env = stack[-3];
    stack[-2] = v_12416;
    goto v_12411;
v_12407:
    v_12416 = stack[-2];
    fn = elt(env, 2); // mo!=shorten
    stack[0] = (*qfn1(fn))(fn, v_12416);
    env = stack[-3];
    goto v_12408;
v_12409:
    v_12416 = stack[-2];
    fn = elt(env, 3); // mo!=deglist
    v_12416 = (*qfn1(fn))(fn, v_12416);
    goto v_12410;
v_12411:
    goto v_12407;
v_12408:
    goto v_12409;
v_12410:
    {
        LispObject v_12421 = stack[0];
        return cons(v_12421, v_12416);
    }
    return onevalue(v_12416);
}



// Code for ilcm

static LispObject CC_ilcm(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12408, v_12409, v_12410, v_12411;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_12410 = v_12335;
    v_12411 = v_12334;
// end of prologue
    goto v_12349;
v_12345:
    v_12409 = v_12411;
    goto v_12346;
v_12347:
    v_12408 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12348;
v_12349:
    goto v_12345;
v_12346:
    goto v_12347;
v_12348:
    if (v_12409 == v_12408) goto v_12343;
    else goto v_12344;
v_12343:
    v_12408 = lisp_true;
    goto v_12342;
v_12344:
    goto v_12359;
v_12355:
    v_12409 = v_12410;
    goto v_12356;
v_12357:
    v_12408 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12358;
v_12359:
    goto v_12355;
v_12356:
    goto v_12357;
v_12358:
    v_12408 = (v_12409 == v_12408 ? lisp_true : nil);
    goto v_12342;
    v_12408 = nil;
v_12342:
    if (v_12408 == nil) goto v_12340;
    v_12408 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12338;
v_12340:
    goto v_12370;
v_12366:
    v_12409 = v_12411;
    goto v_12367;
v_12368:
    v_12408 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12369;
v_12370:
    goto v_12366;
v_12367:
    goto v_12368;
v_12369:
    if (v_12409 == v_12408) goto v_12364;
    else goto v_12365;
v_12364:
    v_12408 = v_12410;
    goto v_12338;
v_12365:
    goto v_12380;
v_12376:
    v_12409 = v_12410;
    goto v_12377;
v_12378:
    v_12408 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12379;
v_12380:
    goto v_12376;
v_12377:
    goto v_12378;
v_12379:
    if (v_12409 == v_12408) goto v_12374;
    else goto v_12375;
v_12374:
    v_12408 = v_12411;
    goto v_12338;
v_12375:
    goto v_12391;
v_12387:
    stack[-1] = v_12411;
    goto v_12388;
v_12389:
    goto v_12398;
v_12394:
    stack[0] = v_12410;
    goto v_12395;
v_12396:
    goto v_12405;
v_12401:
    v_12408 = v_12411;
    goto v_12402;
v_12403:
    v_12409 = v_12410;
    goto v_12404;
v_12405:
    goto v_12401;
v_12402:
    goto v_12403;
v_12404:
    v_12408 = Lgcd(nil, v_12408, v_12409);
    env = stack[-2];
    goto v_12397;
v_12398:
    goto v_12394;
v_12395:
    goto v_12396;
v_12397:
    v_12408 = quot2(stack[0], v_12408);
    goto v_12390;
v_12391:
    goto v_12387;
v_12388:
    goto v_12389;
v_12390:
    {
        LispObject v_12414 = stack[-1];
        return times2(v_12414, v_12408);
    }
    v_12408 = nil;
v_12338:
    return onevalue(v_12408);
}



// Code for mkcr

static LispObject CC_mkcr(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12350;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_12335;
    v_12350 = v_12334;
// end of prologue
    goto v_12344;
v_12338:
    stack[-2] = elt(env, 1); // !:cr!:
    goto v_12339;
v_12340:
    fn = elt(env, 2); // striptag
    stack[0] = (*qfn1(fn))(fn, v_12350);
    env = stack[-3];
    goto v_12341;
v_12342:
    v_12350 = stack[-1];
    fn = elt(env, 2); // striptag
    v_12350 = (*qfn1(fn))(fn, v_12350);
    goto v_12343;
v_12344:
    goto v_12338;
v_12339:
    goto v_12340;
v_12341:
    goto v_12342;
v_12343:
    {
        LispObject v_12354 = stack[-2];
        LispObject v_12355 = stack[0];
        return list2star(v_12354, v_12355, v_12350);
    }
}



// Code for exc

static LispObject CC_exc(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12348, v_12349;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12348 = v_12335;
    v_12349 = v_12334;
// end of prologue
    v_12349 = qcdr(v_12349);
    if (v_12349 == nil) goto v_12339;
    else goto v_12340;
v_12339:
    goto v_12338;
v_12340:
    v_12348 = (v_12348 == nil ? lisp_true : nil);
    goto v_12338;
    v_12348 = nil;
v_12338:
    return onevalue(v_12348);
}



// Code for lalr_prin_rhs

static LispObject CC_lalr_prin_rhs(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12365, v_12366;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12334);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_12366 = v_12334;
// end of prologue
    v_12365 = v_12366;
    if (v_12365 == nil) goto v_12338;
    else goto v_12339;
v_12338:
    v_12365 = elt(env, 1); // "<empty>"
        return Lprinc(nil, v_12365);
v_12339:
    v_12365 = v_12366;
    stack[0] = v_12365;
v_12348:
    v_12365 = stack[0];
    if (v_12365 == nil) goto v_12352;
    else goto v_12353;
v_12352:
    v_12365 = nil;
    goto v_12347;
v_12353:
    v_12365 = stack[0];
    v_12365 = qcar(v_12365);
    fn = elt(env, 3); // lalr_prin_symbol
    v_12365 = (*qfn1(fn))(fn, v_12365);
    env = stack[-1];
    v_12365 = elt(env, 2); // " "
    v_12365 = Lprinc(nil, v_12365);
    env = stack[-1];
    v_12365 = stack[0];
    v_12365 = qcdr(v_12365);
    stack[0] = v_12365;
    goto v_12348;
v_12347:
    goto v_12337;
    v_12365 = nil;
v_12337:
    return onevalue(v_12365);
}



// Code for quotkx

static LispObject CC_quotkx(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12406, v_12407, v_12408;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12335;
    stack[-1] = v_12334;
// end of prologue
    goto v_12342;
v_12338:
    v_12406 = stack[-1];
    v_12406 = qcar(v_12406);
    v_12407 = qcdr(v_12406);
    goto v_12339;
v_12340:
    v_12406 = stack[0];
    goto v_12341;
v_12342:
    goto v_12338;
v_12339:
    goto v_12340;
v_12341:
    fn = elt(env, 1); // quotfx1
    v_12406 = (*qfn2(fn))(fn, v_12407, v_12406);
    env = stack[-3];
    stack[-2] = v_12406;
    v_12406 = stack[-2];
    if (v_12406 == nil) goto v_12351;
    v_12406 = stack[-1];
    v_12406 = qcdr(v_12406);
    if (v_12406 == nil) goto v_12355;
    else goto v_12356;
v_12355:
    goto v_12365;
v_12361:
    v_12406 = stack[-1];
    v_12406 = qcar(v_12406);
    v_12407 = qcar(v_12406);
    goto v_12362;
v_12363:
    v_12406 = stack[-2];
    goto v_12364;
v_12365:
    goto v_12361;
v_12362:
    goto v_12363;
v_12364:
    v_12406 = cons(v_12407, v_12406);
    return ncons(v_12406);
v_12356:
    goto v_12377;
v_12373:
    v_12406 = stack[-1];
    v_12407 = qcdr(v_12406);
    goto v_12374;
v_12375:
    v_12406 = stack[0];
    goto v_12376;
v_12377:
    goto v_12373;
v_12374:
    goto v_12375;
v_12376:
    fn = elt(env, 1); // quotfx1
    v_12406 = (*qfn2(fn))(fn, v_12407, v_12406);
    v_12407 = v_12406;
    if (v_12407 == nil) goto v_12385;
    goto v_12394;
v_12388:
    v_12407 = stack[-1];
    v_12407 = qcar(v_12407);
    v_12408 = qcar(v_12407);
    goto v_12389;
v_12390:
    v_12407 = stack[-2];
    goto v_12391;
v_12392:
    goto v_12393;
v_12394:
    goto v_12388;
v_12389:
    goto v_12390;
v_12391:
    goto v_12392;
v_12393:
    return acons(v_12408, v_12407, v_12406);
v_12385:
    v_12406 = nil;
    goto v_12383;
    v_12406 = nil;
v_12383:
    goto v_12354;
    v_12406 = nil;
v_12354:
    goto v_12349;
v_12351:
    v_12406 = nil;
    goto v_12349;
    v_12406 = nil;
v_12349:
    return onevalue(v_12406);
}



// Code for ofsf_smwmkatl

static LispObject CC_ofsf_smwmkatl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12374, v_12375, v_12376, v_12377, v_12378;
    LispObject fn;
    LispObject v_12337, v_12336, v_12335, v_12334;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ofsf_smwmkatl");
    va_start(aa, nargs);
    v_12334 = va_arg(aa, LispObject);
    v_12335 = va_arg(aa, LispObject);
    v_12336 = va_arg(aa, LispObject);
    v_12337 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12375 = v_12337;
    v_12376 = v_12336;
    v_12377 = v_12335;
    v_12378 = v_12334;
// end of prologue
    v_12374 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_12374 == nil) goto v_12342;
    goto v_12353;
v_12345:
    v_12374 = v_12378;
    goto v_12346;
v_12347:
    goto v_12348;
v_12349:
    goto v_12350;
v_12351:
    goto v_12352;
v_12353:
    goto v_12345;
v_12346:
    goto v_12347;
v_12348:
    goto v_12349;
v_12350:
    goto v_12351;
v_12352:
    {
        fn = elt(env, 2); // cl_susimkatl
        return (*qfnn(fn))(fn, 4, v_12374, v_12377, v_12376, v_12375);
    }
v_12342:
    goto v_12369;
v_12361:
    v_12374 = v_12378;
    goto v_12362;
v_12363:
    goto v_12364;
v_12365:
    goto v_12366;
v_12367:
    goto v_12368;
v_12369:
    goto v_12361;
v_12362:
    goto v_12363;
v_12364:
    goto v_12365;
v_12366:
    goto v_12367;
v_12368:
    {
        fn = elt(env, 3); // ofsf_smmkatl
        return (*qfnn(fn))(fn, 4, v_12374, v_12377, v_12376, v_12375);
    }
    v_12374 = nil;
    return onevalue(v_12374);
}



// Code for talp_eqnrhskernels

static LispObject CC_talp_eqnrhskernels(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12339;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12339 = v_12334;
// end of prologue
    v_12339 = qcdr(v_12339);
    {
        fn = elt(env, 1); // talp_varlt
        return (*qfn1(fn))(fn, v_12339);
    }
}



// Code for horner!-rule!-mod!-p

static LispObject CC_hornerKruleKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12491, v_12492, v_12493, v_12494, v_12495;
    LispObject fn;
    LispObject v_12338, v_12337, v_12336, v_12335, v_12334;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "horner-rule-mod-p");
    va_start(aa, nargs);
    v_12334 = va_arg(aa, LispObject);
    v_12335 = va_arg(aa, LispObject);
    v_12336 = va_arg(aa, LispObject);
    v_12337 = va_arg(aa, LispObject);
    v_12338 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_12338,v_12337,v_12336,v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_12334,v_12335,v_12336,v_12337,v_12338);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_12338;
    stack[-3] = v_12337;
    stack[-4] = v_12336;
    v_12493 = v_12335;
    v_12494 = v_12334;
// end of prologue
v_12333:
    v_12491 = stack[-4];
    if (!consp(v_12491)) goto v_12350;
    else goto v_12351;
v_12350:
    v_12491 = lisp_true;
    goto v_12349;
v_12351:
    v_12491 = stack[-4];
    v_12491 = qcar(v_12491);
    v_12491 = (consp(v_12491) ? nil : lisp_true);
    goto v_12349;
    v_12491 = nil;
v_12349:
    if (v_12491 == nil) goto v_12347;
    v_12491 = lisp_true;
    goto v_12345;
v_12347:
    goto v_12366;
v_12362:
    v_12491 = stack[-4];
    v_12491 = qcar(v_12491);
    v_12491 = qcar(v_12491);
    v_12492 = qcar(v_12491);
    goto v_12363;
v_12364:
    v_12491 = stack[-2];
    goto v_12365;
v_12366:
    goto v_12362;
v_12363:
    goto v_12364;
v_12365:
    v_12491 = (equal(v_12492, v_12491) ? lisp_true : nil);
    v_12491 = (v_12491 == nil ? lisp_true : nil);
    goto v_12345;
    v_12491 = nil;
v_12345:
    if (v_12491 == nil) goto v_12343;
    v_12491 = stack[-3];
    if (v_12491 == nil) goto v_12380;
    else goto v_12381;
v_12380:
    v_12491 = lisp_true;
    goto v_12379;
v_12381:
    v_12491 = stack[-3];
    v_12491 = (LispObject)zerop(v_12491);
    v_12491 = v_12491 ? lisp_true : nil;
    env = stack[-6];
    goto v_12379;
    v_12491 = nil;
v_12379:
    if (v_12491 == nil) goto v_12377;
    v_12491 = stack[-4];
    goto v_12375;
v_12377:
    goto v_12396;
v_12392:
    stack[0] = v_12494;
    goto v_12393;
v_12394:
    goto v_12403;
v_12399:
    v_12491 = stack[-3];
    goto v_12400;
v_12401:
    v_12492 = v_12493;
    goto v_12402;
v_12403:
    goto v_12399;
v_12400:
    goto v_12401;
v_12402:
    fn = elt(env, 2); // expt!-mod!-p
    v_12491 = (*qfn2(fn))(fn, v_12491, v_12492);
    env = stack[-6];
    goto v_12395;
v_12396:
    goto v_12392;
v_12393:
    goto v_12394;
v_12395:
    fn = elt(env, 3); // times!-mod!-p
    v_12491 = (*qfn2(fn))(fn, stack[0], v_12491);
    env = stack[-6];
    v_12494 = v_12491;
    goto v_12411;
v_12407:
    v_12491 = stack[-4];
    goto v_12408;
v_12409:
    v_12492 = v_12494;
    goto v_12410;
v_12411:
    goto v_12407;
v_12408:
    goto v_12409;
v_12410:
    {
        fn = elt(env, 4); // plus!-mod!-p
        return (*qfn2(fn))(fn, v_12491, v_12492);
    }
    v_12491 = nil;
v_12375:
    goto v_12341;
v_12343:
    v_12491 = stack[-4];
    v_12491 = qcar(v_12491);
    v_12491 = qcar(v_12491);
    v_12491 = qcdr(v_12491);
    stack[-5] = v_12491;
    goto v_12435;
v_12425:
    v_12491 = stack[-3];
    if (v_12491 == nil) goto v_12442;
    else goto v_12443;
v_12442:
    v_12491 = lisp_true;
    goto v_12441;
v_12443:
    v_12491 = stack[-3];
    v_12491 = (LispObject)zerop(v_12491);
    v_12491 = v_12491 ? lisp_true : nil;
    env = stack[-6];
    goto v_12441;
    v_12491 = nil;
v_12441:
    if (v_12491 == nil) goto v_12439;
    v_12491 = stack[-4];
    v_12491 = qcar(v_12491);
    v_12491 = qcdr(v_12491);
    v_12494 = v_12491;
    goto v_12437;
v_12439:
    goto v_12460;
v_12456:
    v_12491 = stack[-4];
    v_12491 = qcar(v_12491);
    stack[-1] = qcdr(v_12491);
    goto v_12457;
v_12458:
    goto v_12469;
v_12465:
    stack[0] = v_12494;
    goto v_12466;
v_12467:
    goto v_12476;
v_12472:
    v_12492 = stack[-3];
    goto v_12473;
v_12474:
    goto v_12482;
v_12478:
    goto v_12479;
v_12480:
    v_12491 = stack[-5];
    goto v_12481;
v_12482:
    goto v_12478;
v_12479:
    goto v_12480;
v_12481:
    v_12491 = (LispObject)(intptr_t)((intptr_t)v_12493 - (intptr_t)v_12491 + TAG_FIXNUM);
    goto v_12475;
v_12476:
    goto v_12472;
v_12473:
    goto v_12474;
v_12475:
    fn = elt(env, 2); // expt!-mod!-p
    v_12491 = (*qfn2(fn))(fn, v_12492, v_12491);
    env = stack[-6];
    goto v_12468;
v_12469:
    goto v_12465;
v_12466:
    goto v_12467;
v_12468:
    fn = elt(env, 3); // times!-mod!-p
    v_12491 = (*qfn2(fn))(fn, stack[0], v_12491);
    env = stack[-6];
    goto v_12459;
v_12460:
    goto v_12456;
v_12457:
    goto v_12458;
v_12459:
    fn = elt(env, 4); // plus!-mod!-p
    v_12491 = (*qfn2(fn))(fn, stack[-1], v_12491);
    env = stack[-6];
    v_12494 = v_12491;
    goto v_12437;
    v_12494 = nil;
v_12437:
    goto v_12426;
v_12427:
    v_12493 = stack[-5];
    goto v_12428;
v_12429:
    v_12491 = stack[-4];
    v_12495 = qcdr(v_12491);
    goto v_12430;
v_12431:
    v_12492 = stack[-3];
    goto v_12432;
v_12433:
    v_12491 = stack[-2];
    goto v_12434;
v_12435:
    goto v_12425;
v_12426:
    goto v_12427;
v_12428:
    goto v_12429;
v_12430:
    goto v_12431;
v_12432:
    goto v_12433;
v_12434:
    stack[-4] = v_12495;
    stack[-3] = v_12492;
    stack[-2] = v_12491;
    goto v_12333;
    goto v_12341;
    v_12491 = nil;
v_12341:
    return onevalue(v_12491);
}



// Code for diffsq

static LispObject CC_diffsq(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12384, v_12385;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_12335;
    stack[-2] = v_12334;
// end of prologue
    goto v_12342;
v_12338:
    goto v_12348;
v_12344:
    goto v_12354;
v_12350:
    v_12384 = stack[-2];
    v_12385 = qcar(v_12384);
    goto v_12351;
v_12352:
    v_12384 = stack[-1];
    goto v_12353;
v_12354:
    goto v_12350;
v_12351:
    goto v_12352;
v_12353:
    fn = elt(env, 1); // difff
    stack[-3] = (*qfn2(fn))(fn, v_12385, v_12384);
    env = stack[-4];
    goto v_12345;
v_12346:
    goto v_12364;
v_12360:
    stack[0] = stack[-2];
    goto v_12361;
v_12362:
    goto v_12371;
v_12367:
    v_12384 = stack[-2];
    v_12385 = qcdr(v_12384);
    goto v_12368;
v_12369:
    v_12384 = stack[-1];
    goto v_12370;
v_12371:
    goto v_12367;
v_12368:
    goto v_12369;
v_12370:
    fn = elt(env, 1); // difff
    v_12384 = (*qfn2(fn))(fn, v_12385, v_12384);
    env = stack[-4];
    goto v_12363;
v_12364:
    goto v_12360;
v_12361:
    goto v_12362;
v_12363:
    fn = elt(env, 2); // multsq
    v_12384 = (*qfn2(fn))(fn, stack[0], v_12384);
    env = stack[-4];
    fn = elt(env, 3); // negsq
    v_12384 = (*qfn1(fn))(fn, v_12384);
    env = stack[-4];
    goto v_12347;
v_12348:
    goto v_12344;
v_12345:
    goto v_12346;
v_12347:
    fn = elt(env, 4); // addsq
    stack[0] = (*qfn2(fn))(fn, stack[-3], v_12384);
    env = stack[-4];
    goto v_12339;
v_12340:
    goto v_12380;
v_12376:
    v_12385 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12377;
v_12378:
    v_12384 = stack[-2];
    v_12384 = qcdr(v_12384);
    goto v_12379;
v_12380:
    goto v_12376;
v_12377:
    goto v_12378;
v_12379:
    v_12384 = cons(v_12385, v_12384);
    env = stack[-4];
    goto v_12341;
v_12342:
    goto v_12338;
v_12339:
    goto v_12340;
v_12341:
    {
        LispObject v_12390 = stack[0];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_12390, v_12384);
    }
}



// Code for dm!-gt

static LispObject CC_dmKgt(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12346, v_12347;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12347 = v_12335;
    v_12346 = v_12334;
// end of prologue
    goto v_12343;
v_12339:
    goto v_12340;
v_12341:
    goto v_12342;
v_12343:
    goto v_12339;
v_12340:
    goto v_12341;
v_12342:
    fn = elt(env, 1); // dm!-difference
    v_12346 = (*qfn2(fn))(fn, v_12347, v_12346);
    env = stack[0];
    {
        fn = elt(env, 2); // !:minusp
        return (*qfn1(fn))(fn, v_12346);
    }
}



// Code for groebcplistsortin1

static LispObject CC_groebcplistsortin1(LispObject env,
                         LispObject v_12334, LispObject v_12335)
{
    env = qenv(env);
    LispObject v_12395, v_12396;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12334,v_12335);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12335;
    stack[-1] = v_12334;
// end of prologue
v_12339:
    goto v_12349;
v_12345:
    v_12395 = stack[0];
    v_12396 = qcar(v_12395);
    goto v_12346;
v_12347:
    v_12395 = stack[-1];
    goto v_12348;
v_12349:
    goto v_12345;
v_12346:
    goto v_12347;
v_12348:
    fn = elt(env, 1); // groebcpcompless!?
    v_12395 = (*qfn2(fn))(fn, v_12396, v_12395);
    env = stack[-3];
    if (v_12395 == nil) goto v_12342;
    else goto v_12343;
v_12342:
    goto v_12358;
v_12354:
    stack[-2] = stack[0];
    goto v_12355;
v_12356:
    goto v_12365;
v_12361:
    v_12395 = stack[0];
    v_12396 = qcar(v_12395);
    goto v_12362;
v_12363:
    v_12395 = stack[0];
    v_12395 = qcdr(v_12395);
    goto v_12364;
v_12365:
    goto v_12361;
v_12362:
    goto v_12363;
v_12364:
    v_12395 = cons(v_12396, v_12395);
    env = stack[-3];
    goto v_12357;
v_12358:
    goto v_12354;
v_12355:
    goto v_12356;
v_12357:
    v_12395 = Lrplacd(nil, stack[-2], v_12395);
    goto v_12375;
v_12371:
    v_12396 = stack[0];
    goto v_12372;
v_12373:
    v_12395 = stack[-1];
    goto v_12374;
v_12375:
    goto v_12371;
v_12372:
    goto v_12373;
v_12374:
        return Lrplaca(nil, v_12396, v_12395);
v_12343:
    v_12395 = stack[0];
    v_12395 = qcdr(v_12395);
    if (v_12395 == nil) goto v_12378;
    else goto v_12379;
v_12378:
    goto v_12387;
v_12383:
    goto v_12384;
v_12385:
    v_12395 = stack[-1];
    v_12395 = ncons(v_12395);
    goto v_12386;
v_12387:
    goto v_12383;
v_12384:
    goto v_12385;
v_12386:
    {
        LispObject v_12400 = stack[0];
        return Lrplacd(nil, v_12400, v_12395);
    }
v_12379:
    v_12395 = stack[0];
    v_12395 = qcdr(v_12395);
    stack[0] = v_12395;
    goto v_12339;
    v_12395 = nil;
    return onevalue(v_12395);
}



// Code for setmat

static LispObject CC_setmat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12393, v_12394, v_12395;
    LispObject fn;
    LispObject v_12337, v_12336, v_12335, v_12334;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "setmat");
    va_start(aa, nargs);
    v_12334 = va_arg(aa, LispObject);
    v_12335 = va_arg(aa, LispObject);
    v_12336 = va_arg(aa, LispObject);
    v_12337 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_12337,v_12336,v_12335,v_12334);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_12334,v_12335,v_12336,v_12337);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_12337;
    stack[-1] = v_12336;
    stack[-2] = v_12335;
    stack[-3] = v_12334;
// end of prologue
    v_12393 = qvalue(elt(env, 1)); // !*modular
    if (v_12393 == nil) goto v_12342;
    v_12393 = elt(env, 2); // modular
    v_12393 = ncons(v_12393);
    env = stack[-4];
    fn = elt(env, 5); // off
    v_12393 = (*qfn1(fn))(fn, v_12393);
    env = stack[-4];
    v_12393 = elt(env, 3); // mod_was_on
    v_12393 = ncons(v_12393);
    env = stack[-4];
    fn = elt(env, 6); // on
    v_12393 = (*qfn1(fn))(fn, v_12393);
    env = stack[-4];
    goto v_12340;
v_12342:
v_12340:
    v_12393 = stack[-2];
    fn = elt(env, 7); // reval
    v_12393 = (*qfn1(fn))(fn, v_12393);
    env = stack[-4];
    stack[-2] = v_12393;
    v_12393 = stack[-1];
    fn = elt(env, 7); // reval
    v_12393 = (*qfn1(fn))(fn, v_12393);
    env = stack[-4];
    stack[-1] = v_12393;
    v_12393 = stack[0];
    fn = elt(env, 7); // reval
    v_12393 = (*qfn1(fn))(fn, v_12393);
    env = stack[-4];
    fn = elt(env, 8); // simp
    v_12393 = (*qfn1(fn))(fn, v_12393);
    env = stack[-4];
    fn = elt(env, 9); // mk!*sq
    v_12393 = (*qfn1(fn))(fn, v_12393);
    env = stack[-4];
    stack[0] = v_12393;
    goto v_12366;
v_12360:
    goto v_12374;
v_12368:
    v_12395 = stack[-3];
    goto v_12369;
v_12370:
    v_12394 = stack[-2];
    goto v_12371;
v_12372:
    v_12393 = stack[-1];
    goto v_12373;
v_12374:
    goto v_12368;
v_12369:
    goto v_12370;
v_12371:
    goto v_12372;
v_12373:
    v_12395 = list3(v_12395, v_12394, v_12393);
    env = stack[-4];
    goto v_12361;
v_12362:
    v_12394 = stack[0];
    goto v_12363;
v_12364:
    v_12393 = stack[-3];
    goto v_12365;
v_12366:
    goto v_12360;
v_12361:
    goto v_12362;
v_12363:
    goto v_12364;
v_12365:
    fn = elt(env, 10); // letmtr
    v_12393 = (*qfnn(fn))(fn, 3, v_12395, v_12394, v_12393);
    env = stack[-4];
    v_12393 = qvalue(elt(env, 4)); // !*mod_was_on
    if (v_12393 == nil) goto v_12383;
    v_12393 = elt(env, 2); // modular
    v_12393 = ncons(v_12393);
    env = stack[-4];
    fn = elt(env, 6); // on
    v_12393 = (*qfn1(fn))(fn, v_12393);
    env = stack[-4];
    v_12393 = elt(env, 3); // mod_was_on
    v_12393 = ncons(v_12393);
    env = stack[-4];
    fn = elt(env, 5); // off
    v_12393 = (*qfn1(fn))(fn, v_12393);
    goto v_12381;
v_12383:
v_12381:
    v_12393 = stack[-3];
    return onevalue(v_12393);
}



// Code for coordp

static LispObject CC_coordp(LispObject env,
                         LispObject v_12334)
{
    env = qenv(env);
    LispObject v_12344, v_12345;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12344 = v_12334;
// end of prologue
    goto v_12340;
v_12336:
    goto v_12337;
v_12338:
    v_12345 = qvalue(elt(env, 1)); // coord!*
    goto v_12339;
v_12340:
    goto v_12336;
v_12337:
    goto v_12338;
v_12339:
    v_12344 = Lmemq(nil, v_12344, v_12345);
    return onevalue(v_12344);
}



setup_type const u22_setup[] =
{
    {"dipcondense",             CC_dipcondense, TOO_MANY_1,    WRONG_NO_1},
    {"expvec2a",                CC_expvec2a,    TOO_MANY_1,    WRONG_NO_1},
    {"indexvarordp",            TOO_FEW_2,      CC_indexvarordp,WRONG_NO_2},
    {"inttovec-solve",          TOO_FEW_2,      CC_inttovecKsolve,WRONG_NO_2},
    {"lispassignp",             CC_lispassignp, TOO_MANY_1,    WRONG_NO_1},
    {"nfactorial",              CC_nfactorial,  TOO_MANY_1,    WRONG_NO_1},
    {"lpriw",                   TOO_FEW_2,      CC_lpriw,      WRONG_NO_2},
    {"cde_delete",              TOO_FEW_2,      CC_cde_delete, WRONG_NO_2},
    {"sfto_dgcd",               TOO_FEW_2,      CC_sfto_dgcd,  WRONG_NO_2},
    {"traput",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_traput},
    {"cl_atl",                  CC_cl_atl,      TOO_MANY_1,    WRONG_NO_1},
    {"diff-over-k-mod-p",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_diffKoverKkKmodKp},
    {"testredzz",               CC_testredzz,   TOO_MANY_1,    WRONG_NO_1},
    {"dipevlcomp",              TOO_FEW_2,      CC_dipevlcomp, WRONG_NO_2},
    {"indord2",                 TOO_FEW_2,      CC_indord2,    WRONG_NO_2},
    {"begin1a",                 CC_begin1a,     TOO_MANY_1,    WRONG_NO_1},
    {"rnprep:",                 CC_rnprepT,     TOO_MANY_1,    WRONG_NO_1},
    {"groeb=weight",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_groebMweight},
    {"rootrnd",                 CC_rootrnd,     TOO_MANY_1,    WRONG_NO_1},
    {"simpqg",                  CC_simpqg,      TOO_MANY_1,    WRONG_NO_1},
    {"ezgcdf1",                 TOO_FEW_2,      CC_ezgcdf1,    WRONG_NO_2},
    {"delet",                   TOO_FEW_2,      CC_delet,      WRONG_NO_2},
    {"quotofd",                 TOO_FEW_2,      CC_quotofd,    WRONG_NO_2},
    {"ir2mml",                  CC_ir2mml,      TOO_MANY_1,    WRONG_NO_1},
    {"mchkopt1",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mchkopt1},
    {"simprecip",               CC_simprecip,   TOO_MANY_1,    WRONG_NO_1},
    {"chk",                     CC_chk,         TOO_MANY_1,    WRONG_NO_1},
    {"freeoffl",                TOO_FEW_2,      CC_freeoffl,   WRONG_NO_2},
    {"treesizep",               TOO_FEW_2,      CC_treesizep,  WRONG_NO_2},
    {"mv-domainlist",           CC_mvKdomainlist,TOO_MANY_1,   WRONG_NO_1},
    {":rn2rd",                  CC_Trn2rd,      TOO_MANY_1,    WRONG_NO_1},
    {"reducepowers",            CC_reducepowers,TOO_MANY_1,    WRONG_NO_1},
    {"general-reciprocal-by-gcd",WRONG_NO_NA,   WRONG_NO_NB,   (n_args *)CC_generalKreciprocalKbyKgcd},
    {"quotfail-in-vector",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_quotfailKinKvector},
    {"carrassoc",               TOO_FEW_2,      CC_carrassoc,  WRONG_NO_2},
    {"gcref_select",            CC_gcref_select,TOO_MANY_1,    WRONG_NO_1},
    {"mk+unit+mat",             CC_mkLunitLmat, TOO_MANY_1,    WRONG_NO_1},
    {"cl_flip",                 CC_cl_flip,     TOO_MANY_1,    WRONG_NO_1},
    {"ps:prepfn:",              CC_psTprepfnT,  TOO_MANY_1,    WRONG_NO_1},
    {"ps:evaluate",             TOO_FEW_2,      CC_psTevaluate,WRONG_NO_2},
    {"partitexdf",              CC_partitexdf,  TOO_MANY_1,    WRONG_NO_1},
    {"indordp",                 TOO_FEW_2,      CC_indordp,    WRONG_NO_2},
    {"assert_format",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_assert_format},
    {"lienjactest",             CC_lienjactest, TOO_MANY_1,    WRONG_NO_1},
    {"sf2mv1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_sf2mv1},
    {"mo_lcm",                  TOO_FEW_2,      CC_mo_lcm,     WRONG_NO_2},
    {"ilcm",                    TOO_FEW_2,      CC_ilcm,       WRONG_NO_2},
    {"mkcr",                    TOO_FEW_2,      CC_mkcr,       WRONG_NO_2},
    {"exc",                     TOO_FEW_2,      CC_exc,        WRONG_NO_2},
    {"lalr_prin_rhs",           CC_lalr_prin_rhs,TOO_MANY_1,   WRONG_NO_1},
    {"quotkx",                  TOO_FEW_2,      CC_quotkx,     WRONG_NO_2},
    {"ofsf_smwmkatl",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smwmkatl},
    {"talp_eqnrhskernels",      CC_talp_eqnrhskernels,TOO_MANY_1,WRONG_NO_1},
    {"horner-rule-mod-p",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_hornerKruleKmodKp},
    {"diffsq",                  TOO_FEW_2,      CC_diffsq,     WRONG_NO_2},
    {"dm-gt",                   TOO_FEW_2,      CC_dmKgt,      WRONG_NO_2},
    {"groebcplistsortin1",      TOO_FEW_2,      CC_groebcplistsortin1,WRONG_NO_2},
    {"setmat",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setmat},
    {"coordp",                  CC_coordp,      TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u22", (two_args *)"14184 2922128 6973923", 0}
};

// end of generated code
