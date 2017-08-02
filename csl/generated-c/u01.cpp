
// $destdir/u01.c        Machine generated C code

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



// Code for terminalp

static LispObject CC_terminalp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13;
    argcheck(nargs, 0, "terminalp");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_13 = qvalue(elt(env, 1)); // !*int
    if (v_13 == nil) goto v_5;
    else goto v_6;
v_5:
    v_13 = nil;
    goto v_4;
v_6:
    v_13 = qvalue(elt(env, 2)); // ifl!*
    v_13 = (v_13 == nil ? lisp_true : nil);
    goto v_4;
    v_13 = nil;
v_4:
    return onevalue(v_13);
}



// Code for smember

static LispObject CC_smember(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_44, v_45;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
v_1:
    goto v_13;
v_9:
    v_45 = stack[-1];
    goto v_10;
v_11:
    v_44 = stack[0];
    goto v_12;
v_13:
    goto v_9;
v_10:
    goto v_11;
v_12:
    if (equal(v_45, v_44)) goto v_7;
    else goto v_8;
v_7:
    v_44 = lisp_true;
    goto v_6;
v_8:
    v_44 = stack[0];
    if (!consp(v_44)) goto v_17;
    else goto v_18;
v_17:
    v_44 = nil;
    goto v_6;
v_18:
    goto v_31;
v_27:
    v_45 = stack[-1];
    goto v_28;
v_29:
    v_44 = stack[0];
    v_44 = qcar(v_44);
    goto v_30;
v_31:
    goto v_27;
v_28:
    goto v_29;
v_30:
    v_44 = CC_smember(elt(env, 0), v_45, v_44);
    env = stack[-2];
    if (v_44 == nil) goto v_25;
    else goto v_24;
v_25:
    goto v_40;
v_36:
    v_45 = stack[-1];
    goto v_37;
v_38:
    v_44 = stack[0];
    v_44 = qcdr(v_44);
    goto v_39;
v_40:
    goto v_36;
v_37:
    goto v_38;
v_39:
    stack[-1] = v_45;
    stack[0] = v_44;
    goto v_1;
v_24:
    goto v_6;
    v_44 = nil;
v_6:
    return onevalue(v_44);
}



// Code for !*n2f

static LispObject CC_Hn2f(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_14, v_15;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
// copy arguments values to proper place
    v_15 = v_2;
// end of prologue
    v_14 = v_15;
    v_14 = (LispObject)zerop(v_14);
    v_14 = v_14 ? lisp_true : nil;
    if (v_14 == nil) goto v_7;
    v_14 = nil;
    goto v_5;
v_7:
    v_14 = v_15;
    goto v_5;
    v_14 = nil;
v_5:
    return onevalue(v_14);
}



// Code for setdiff

static LispObject CC_setdiff(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_31, v_32;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_3;
    v_31 = v_2;
// end of prologue
v_7:
    v_32 = stack[0];
    if (v_32 == nil) goto v_10;
    else goto v_11;
v_10:
    goto v_6;
v_11:
    v_32 = v_31;
    if (v_32 == nil) goto v_14;
    else goto v_15;
v_14:
    v_31 = nil;
    goto v_6;
v_15:
    goto v_25;
v_21:
    v_32 = stack[0];
    v_32 = qcar(v_32);
    goto v_22;
v_23:
    goto v_24;
v_25:
    goto v_21;
v_22:
    goto v_23;
v_24:
    v_31 = Ldelete(nil, v_32, v_31);
    env = stack[-1];
    v_32 = stack[0];
    v_32 = qcdr(v_32);
    stack[0] = v_32;
    goto v_7;
    v_31 = nil;
v_6:
    return onevalue(v_31);
}



// Code for multf

static LispObject CC_multf(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_28, v_29, v_30;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29 = v_3;
    v_30 = v_2;
// end of prologue
    v_28 = qvalue(elt(env, 1)); // !*physop!-loaded
    if (v_28 == nil) goto v_8;
    goto v_15;
v_11:
    v_28 = v_30;
    goto v_12;
v_13:
    goto v_14;
v_15:
    goto v_11;
v_12:
    goto v_13;
v_14:
    {
        fn = elt(env, 2); // physop!-multf
        return (*qfn2(fn))(fn, v_28, v_29);
    }
v_8:
    goto v_25;
v_21:
    v_28 = v_30;
    goto v_22;
v_23:
    goto v_24;
v_25:
    goto v_21;
v_22:
    goto v_23;
v_24:
    {
        fn = elt(env, 3); // poly!-multf
        return (*qfn2(fn))(fn, v_28, v_29);
    }
    v_28 = nil;
    return onevalue(v_28);
}



// Code for quotelist

static LispObject CC_quotelist(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_5;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5 = v_2;
// end of prologue
    v_5 = elt(env, 1); // list
    return onevalue(v_5);
}



// Code for num!-exponents

static LispObject CC_numKexponents(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_48;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
v_1:
    v_48 = stack[0];
    if (!consp(v_48)) goto v_10;
    else goto v_11;
v_10:
    v_48 = lisp_true;
    goto v_9;
v_11:
    v_48 = stack[0];
    v_48 = qcar(v_48);
    v_48 = (consp(v_48) ? nil : lisp_true);
    goto v_9;
    v_48 = nil;
v_9:
    if (v_48 == nil) goto v_7;
    v_48 = lisp_true;
    goto v_5;
v_7:
    v_48 = stack[0];
    v_48 = qcar(v_48);
    v_48 = qcar(v_48);
    v_48 = qcdr(v_48);
    v_48 = integerp(v_48);
    if (v_48 == nil) goto v_24;
    else goto v_25;
v_24:
    v_48 = nil;
    goto v_23;
v_25:
    v_48 = stack[0];
    v_48 = qcar(v_48);
    v_48 = qcdr(v_48);
    v_48 = CC_numKexponents(elt(env, 0), v_48);
    env = stack[-1];
    if (v_48 == nil) goto v_36;
    else goto v_37;
v_36:
    v_48 = nil;
    goto v_35;
v_37:
    v_48 = stack[0];
    v_48 = qcdr(v_48);
    stack[0] = v_48;
    goto v_1;
    v_48 = nil;
v_35:
    goto v_23;
    v_48 = nil;
v_23:
    goto v_5;
    v_48 = nil;
v_5:
    return onevalue(v_48);
}



// Code for simpcar

static LispObject CC_simpcar(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_7;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7 = v_2;
// end of prologue
    v_7 = qcar(v_7);
    {
        fn = elt(env, 1); // simp
        return (*qfn1(fn))(fn, v_7);
    }
}



// Code for wuconstantp

static LispObject CC_wuconstantp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_34, v_35;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_35 = v_2;
// end of prologue
    v_34 = v_35;
    if (!consp(v_34)) goto v_10;
    else goto v_11;
v_10:
    v_34 = lisp_true;
    goto v_9;
v_11:
    v_34 = v_35;
    v_34 = qcar(v_34);
    v_34 = (consp(v_34) ? nil : lisp_true);
    goto v_9;
    v_34 = nil;
v_9:
    if (v_34 == nil) goto v_7;
    v_34 = lisp_true;
    goto v_5;
v_7:
    goto v_26;
v_22:
    v_34 = v_35;
    v_34 = qcar(v_34);
    v_34 = qcar(v_34);
    v_34 = qcar(v_34);
    goto v_23;
v_24:
    v_35 = qvalue(elt(env, 1)); // wuvarlist!*
    goto v_25;
v_26:
    goto v_22;
v_23:
    goto v_24;
v_25:
    v_34 = Lmemq(nil, v_34, v_35);
    v_34 = (v_34 == nil ? lisp_true : nil);
    goto v_5;
    v_34 = nil;
v_5:
    return onevalue(v_34);
}



// Code for mkcopy

static LispObject CC_mkcopy(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_35, v_36;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    stack[-1] = nil;
v_7:
    v_35 = stack[0];
    if (!consp(v_35)) goto v_10;
    else goto v_11;
v_10:
    goto v_18;
v_14:
    v_36 = stack[-1];
    goto v_15;
v_16:
    v_35 = stack[0];
    goto v_17;
v_18:
    goto v_14;
v_15:
    goto v_16;
v_17:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_36, v_35);
    }
v_11:
    goto v_28;
v_24:
    v_35 = stack[0];
    v_35 = qcar(v_35);
    v_36 = CC_mkcopy(elt(env, 0), v_35);
    env = stack[-2];
    goto v_25;
v_26:
    v_35 = stack[-1];
    goto v_27;
v_28:
    goto v_24;
v_25:
    goto v_26;
v_27:
    v_35 = cons(v_36, v_35);
    env = stack[-2];
    stack[-1] = v_35;
    v_35 = stack[0];
    v_35 = qcdr(v_35);
    stack[0] = v_35;
    goto v_7;
    v_35 = nil;
    return onevalue(v_35);
}



// Code for mchkopt

static LispObject CC_mchkopt(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_25, v_26, v_27, v_28;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27 = v_3;
    v_28 = v_2;
// end of prologue
    v_25 = v_27;
    v_25 = qcar(v_25);
    if (!symbolp(v_25)) v_25 = nil;
    else { v_25 = qfastgets(v_25);
           if (v_25 != nil) { v_25 = elt(v_25, 6); // optional
#ifdef RECORD_GET
             if (v_25 != SPID_NOPROP)
                record_get(elt(fastget_names, 6), 1);
             else record_get(elt(fastget_names, 6), 0),
                v_25 = nil; }
           else record_get(elt(fastget_names, 6), 0); }
#else
             if (v_25 == SPID_NOPROP) v_25 = nil; }}
#endif
    v_26 = v_25;
    v_25 = v_26;
    if (v_25 == nil) goto v_12;
    goto v_21;
v_15:
    v_25 = v_28;
    goto v_16;
v_17:
    goto v_18;
v_19:
    goto v_20;
v_21:
    goto v_15;
v_16:
    goto v_17;
v_18:
    goto v_19;
v_20:
    {
        fn = elt(env, 1); // mchkopt1
        return (*qfnn(fn))(fn, 3, v_25, v_27, v_26);
    }
v_12:
    v_25 = nil;
    return onevalue(v_25);
}



// Code for revpr

static LispObject CC_revpr(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_14, v_15;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14 = v_2;
// end of prologue
    goto v_9;
v_5:
    v_15 = v_14;
    v_15 = qcdr(v_15);
    goto v_6;
v_7:
    v_14 = qcar(v_14);
    goto v_8;
v_9:
    goto v_5;
v_6:
    goto v_7;
v_8:
    return cons(v_15, v_14);
}



// Code for nth

static LispObject CC_nth(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_14, v_15;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
// copy arguments values to proper place
    v_14 = v_3;
    v_15 = v_2;
// end of prologue
    goto v_10;
v_6:
    goto v_7;
v_8:
    goto v_9;
v_10:
    goto v_6;
v_7:
    goto v_8;
v_9:
    fn = elt(env, 1); // pnth
    v_14 = (*qfn2(fn))(fn, v_15, v_14);
    v_14 = qcar(v_14);
    return onevalue(v_14);
}



// Code for talp_getl

static LispObject CC_talp_getl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_4;
    argcheck(nargs, 0, "talp_getl");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_4 = qvalue(elt(env, 1)); // talp_lang!*
    return onevalue(v_4);
}



// Code for kernels

static LispObject CC_kernels(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_12, v_13;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12 = v_2;
// end of prologue
    goto v_9;
v_5:
    v_13 = v_12;
    goto v_6;
v_7:
    v_12 = nil;
    goto v_8;
v_9:
    goto v_5;
v_6:
    goto v_7;
v_8:
    {
        fn = elt(env, 1); // kernels1
        return (*qfn2(fn))(fn, v_13, v_12);
    }
}



// Code for qqe_rqopp

static LispObject CC_qqe_rqopp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_12, v_13;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12 = v_2;
// end of prologue
    goto v_8;
v_4:
    goto v_5;
v_6:
    v_13 = elt(env, 1); // (qequal qneq)
    goto v_7;
v_8:
    goto v_4;
v_5:
    goto v_6;
v_7:
    v_12 = Lmemq(nil, v_12, v_13);
    return onevalue(v_12);
}



// Code for lto_hashid

static LispObject CC_lto_hashid(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_7;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
// copy arguments values to proper place
    v_7 = v_2;
// end of prologue
    fn = elt(env, 1); // string2list
    v_7 = (*qfn1(fn))(fn, v_7);
    v_7 = qcar(v_7);
    return onevalue(v_7);
}



// Code for noncomfp

static LispObject CC_noncomfp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_14, v_15;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15 = v_2;
// end of prologue
    v_14 = qvalue(elt(env, 1)); // !*ncmp
    if (v_14 == nil) goto v_6;
    else goto v_7;
v_6:
    v_14 = nil;
    goto v_5;
v_7:
    v_14 = v_15;
    {
        fn = elt(env, 2); // noncomfp1
        return (*qfn1(fn))(fn, v_14);
    }
    v_14 = nil;
v_5:
    return onevalue(v_14);
}



// Code for delall

static LispObject CC_delall(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_46, v_47;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
v_7:
    v_46 = stack[0];
    if (v_46 == nil) goto v_10;
    else goto v_11;
v_10:
    v_46 = nil;
    goto v_6;
v_11:
    goto v_20;
v_16:
    v_47 = stack[-1];
    goto v_17;
v_18:
    v_46 = stack[0];
    v_46 = qcar(v_46);
    goto v_19;
v_20:
    goto v_16;
v_17:
    goto v_18;
v_19:
    if (equal(v_47, v_46)) goto v_14;
    else goto v_15;
v_14:
    v_46 = stack[0];
    v_46 = qcdr(v_46);
    stack[0] = v_46;
    goto v_7;
v_15:
    goto v_33;
v_29:
    v_46 = stack[0];
    v_46 = qcar(v_46);
    stack[-2] = ncons(v_46);
    env = stack[-3];
    goto v_30;
v_31:
    goto v_42;
v_38:
    v_47 = stack[-1];
    goto v_39;
v_40:
    v_46 = stack[0];
    v_46 = qcdr(v_46);
    goto v_41;
v_42:
    goto v_38;
v_39:
    goto v_40;
v_41:
    v_46 = CC_delall(elt(env, 0), v_47, v_46);
    goto v_32;
v_33:
    goto v_29;
v_30:
    goto v_31;
v_32:
    {
        LispObject v_51 = stack[-2];
        return Lappend(nil, v_51, v_46);
    }
    v_46 = nil;
v_6:
    return onevalue(v_46);
}



// Code for ordop

static LispObject CC_ordop(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_63, v_64, v_65, v_66, v_67;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_66 = v_3;
    v_67 = v_2;
// end of prologue
    v_63 = qvalue(elt(env, 1)); // !*physop!-loaded
    if (v_63 == nil) goto v_8;
    goto v_15;
v_11:
    v_63 = v_67;
    goto v_12;
v_13:
    v_64 = v_66;
    goto v_14;
v_15:
    goto v_11;
v_12:
    goto v_13;
v_14:
    {
        fn = elt(env, 4); // physop!-ordop
        return (*qfn2(fn))(fn, v_63, v_64);
    }
v_8:
    v_63 = qvalue(elt(env, 3)); // kord!*
    v_65 = v_63;
v_23:
    v_63 = v_65;
    if (v_63 == nil) goto v_28;
    else goto v_29;
v_28:
    goto v_36;
v_32:
    v_63 = v_67;
    goto v_33;
v_34:
    v_64 = v_66;
    goto v_35;
v_36:
    goto v_32;
v_33:
    goto v_34;
v_35:
    {
        fn = elt(env, 5); // ordp
        return (*qfn2(fn))(fn, v_63, v_64);
    }
v_29:
    goto v_45;
v_41:
    v_64 = v_67;
    goto v_42;
v_43:
    v_63 = v_65;
    v_63 = qcar(v_63);
    goto v_44;
v_45:
    goto v_41;
v_42:
    goto v_43;
v_44:
    if (v_64 == v_63) goto v_39;
    else goto v_40;
v_39:
    v_63 = lisp_true;
    goto v_22;
v_40:
    goto v_56;
v_52:
    v_64 = v_66;
    goto v_53;
v_54:
    v_63 = v_65;
    v_63 = qcar(v_63);
    goto v_55;
v_56:
    goto v_52;
v_53:
    goto v_54;
v_55:
    if (v_64 == v_63) goto v_50;
    else goto v_51;
v_50:
    v_63 = nil;
    goto v_22;
v_51:
    v_63 = v_65;
    v_63 = qcdr(v_63);
    v_65 = v_63;
    goto v_23;
v_22:
    goto v_6;
    v_63 = nil;
v_6:
    return onevalue(v_63);
}



// Code for prepf

static LispObject CC_prepf(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_13, v_14;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_13 = v_2;
// end of prologue
    goto v_10;
v_6:
    v_14 = v_13;
    goto v_7;
v_8:
    v_13 = nil;
    goto v_9;
v_10:
    goto v_6;
v_7:
    goto v_8;
v_9:
    fn = elt(env, 1); // prepf1a
    v_13 = (*qfn2(fn))(fn, v_14, v_13);
    env = stack[0];
    {
        fn = elt(env, 2); // replus1
        return (*qfn1(fn))(fn, v_13);
    }
}



// Code for c!:ordxp

static LispObject CC_cTordxp(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_45, v_46, v_47;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_45 = v_3;
    v_46 = v_2;
// end of prologue
    v_47 = v_46;
    v_47 = Lconsp(nil, v_47);
    env = stack[0];
    if (v_47 == nil) goto v_8;
    v_47 = v_45;
    v_47 = Lconsp(nil, v_47);
    if (v_47 == nil) goto v_14;
    goto v_22;
v_18:
    v_46 = qcdr(v_46);
    goto v_19;
v_20:
    v_45 = qcdr(v_45);
    goto v_21;
v_22:
    goto v_18;
v_19:
    goto v_20;
v_21:
        return Llessp(nil, v_46, v_45);
v_14:
    v_45 = nil;
    goto v_12;
    v_45 = nil;
v_12:
    goto v_6;
v_8:
    v_47 = v_45;
    v_47 = Lconsp(nil, v_47);
    if (v_47 == nil) goto v_31;
    v_45 = lisp_true;
    goto v_6;
v_31:
    goto v_42;
v_38:
    goto v_39;
v_40:
    goto v_41;
v_42:
    goto v_38;
v_39:
    goto v_40;
v_41:
        return Llessp(nil, v_46, v_45);
    v_45 = nil;
v_6:
    return onevalue(v_45);
}



// Code for ordad

static LispObject CC_ordad(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_70, v_71;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    stack[-2] = nil;
v_11:
    v_70 = stack[0];
    if (v_70 == nil) goto v_14;
    goto v_24;
v_20:
    v_71 = stack[-1];
    goto v_21;
v_22:
    v_70 = stack[0];
    v_70 = qcar(v_70);
    goto v_23;
v_24:
    goto v_20;
v_21:
    goto v_22;
v_23:
    fn = elt(env, 2); // ordp
    v_70 = (*qfn2(fn))(fn, v_71, v_70);
    env = stack[-3];
    if (v_70 == nil) goto v_18;
    else goto v_14;
v_18:
    goto v_15;
v_14:
    goto v_10;
v_15:
    goto v_34;
v_30:
    v_70 = stack[0];
    v_71 = qcar(v_70);
    goto v_31;
v_32:
    v_70 = stack[-2];
    goto v_33;
v_34:
    goto v_30;
v_31:
    goto v_32;
v_33:
    v_70 = cons(v_71, v_70);
    env = stack[-3];
    stack[-2] = v_70;
    v_70 = stack[0];
    v_70 = qcdr(v_70);
    stack[0] = v_70;
    goto v_11;
v_10:
    goto v_45;
v_41:
    v_71 = stack[-1];
    goto v_42;
v_43:
    v_70 = stack[0];
    goto v_44;
v_45:
    goto v_41;
v_42:
    goto v_43;
v_44:
    v_70 = cons(v_71, v_70);
    env = stack[-3];
    stack[0] = v_70;
v_50:
    v_70 = stack[-2];
    if (v_70 == nil) goto v_53;
    else goto v_54;
v_53:
    goto v_49;
v_54:
    v_70 = stack[-2];
    v_70 = qcdr(v_70);
    stack[-1] = v_70;
    goto v_64;
v_60:
    v_71 = stack[-2];
    goto v_61;
v_62:
    v_70 = stack[0];
    goto v_63;
v_64:
    goto v_60;
v_61:
    goto v_62;
v_63:
    v_70 = Lrplacd(nil, v_71, v_70);
    env = stack[-3];
    v_70 = stack[-2];
    stack[0] = v_70;
    v_70 = stack[-1];
    stack[-2] = v_70;
    goto v_50;
v_49:
    v_70 = stack[0];
    return onevalue(v_70);
}



// Code for reval

static LispObject CC_reval(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_12, v_13;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12 = v_2;
// end of prologue
    goto v_9;
v_5:
    v_13 = v_12;
    goto v_6;
v_7:
    v_12 = lisp_true;
    goto v_8;
v_9:
    goto v_5;
v_6:
    goto v_7;
v_8:
    {
        fn = elt(env, 1); // reval1
        return (*qfn2(fn))(fn, v_13, v_12);
    }
}



// Code for evcomp

static LispObject CC_evcomp(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_20, v_21;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_20 = v_3;
    v_21 = v_2;
// end of prologue
    goto v_10;
v_6:
    stack[0] = qvalue(elt(env, 1)); // dipsortevcomp!*
    goto v_7;
v_8:
    goto v_17;
v_13:
    goto v_14;
v_15:
    goto v_16;
v_17:
    goto v_13;
v_14:
    goto v_15;
v_16:
    v_20 = list2(v_21, v_20);
    env = stack[-1];
    goto v_9;
v_10:
    goto v_6;
v_7:
    goto v_8;
v_9:
    {
        LispObject v_23 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_23, v_20);
    }
}



// Code for evmatrixcomp2

static LispObject CC_evmatrixcomp2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_98, v_99, v_100, v_101;
    LispObject fn;
    LispObject v_4, v_3, v_2;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "evmatrixcomp2");
    va_start(aa, nargs);
    v_2 = va_arg(aa, LispObject);
    v_3 = va_arg(aa, LispObject);
    v_4 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_4,v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_2,v_3,v_4);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_4;
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
v_1:
    v_98 = stack[-2];
    if (v_98 == nil) goto v_12;
    else goto v_13;
v_12:
    v_98 = lisp_true;
    goto v_11;
v_13:
    v_98 = stack[-1];
    v_98 = (v_98 == nil ? lisp_true : nil);
    goto v_11;
    v_98 = nil;
v_11:
    if (v_98 == nil) goto v_9;
    v_98 = stack[0];
    goto v_7;
v_9:
    v_98 = stack[-1];
    v_98 = qcar(v_98);
    stack[-3] = v_98;
    goto v_35;
v_31:
    v_99 = stack[-3];
    goto v_32;
v_33:
    v_98 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_34;
v_35:
    goto v_31;
v_32:
    goto v_33;
v_34:
    fn = elt(env, 1); // iequal
    v_98 = (*qfn2(fn))(fn, v_99, v_98);
    env = stack[-4];
    if (v_98 == nil) goto v_29;
    goto v_45;
v_39:
    v_98 = stack[-2];
    v_100 = qcdr(v_98);
    goto v_40;
v_41:
    v_98 = stack[-1];
    v_99 = qcdr(v_98);
    goto v_42;
v_43:
    v_98 = stack[0];
    goto v_44;
v_45:
    goto v_39;
v_40:
    goto v_41;
v_42:
    goto v_43;
v_44:
    stack[-2] = v_100;
    stack[-1] = v_99;
    stack[0] = v_98;
    goto v_1;
v_29:
    goto v_58;
v_54:
    v_99 = stack[-3];
    goto v_55;
v_56:
    v_98 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_57;
v_58:
    goto v_54;
v_55:
    goto v_56;
v_57:
    fn = elt(env, 1); // iequal
    v_98 = (*qfn2(fn))(fn, v_99, v_98);
    env = stack[-4];
    if (v_98 == nil) goto v_52;
    goto v_68;
v_62:
    v_98 = stack[-2];
    v_101 = qcdr(v_98);
    goto v_63;
v_64:
    v_98 = stack[-1];
    v_100 = qcdr(v_98);
    goto v_65;
v_66:
    goto v_77;
v_73:
    v_99 = stack[0];
    goto v_74;
v_75:
    v_98 = stack[-2];
    v_98 = qcar(v_98);
    goto v_76;
v_77:
    goto v_73;
v_74:
    goto v_75;
v_76:
    v_98 = (LispObject)(intptr_t)((intptr_t)v_99 + (intptr_t)v_98 - TAG_FIXNUM);
    goto v_67;
v_68:
    goto v_62;
v_63:
    goto v_64;
v_65:
    goto v_66;
v_67:
    stack[-2] = v_101;
    stack[-1] = v_100;
    stack[0] = v_98;
    goto v_1;
v_52:
    goto v_93;
v_85:
    v_101 = stack[-2];
    goto v_86;
v_87:
    v_100 = stack[-3];
    goto v_88;
v_89:
    v_99 = stack[-1];
    goto v_90;
v_91:
    v_98 = stack[0];
    goto v_92;
v_93:
    goto v_85;
v_86:
    goto v_87;
v_88:
    goto v_89;
v_90:
    goto v_91;
v_92:
    {
        fn = elt(env, 2); // evmatrixcomp3
        return (*qfnn(fn))(fn, 4, v_101, v_100, v_99, v_98);
    }
    v_98 = nil;
    goto v_7;
    v_98 = nil;
v_7:
    return onevalue(v_98);
}



// Code for xval

static LispObject CC_xval(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_8;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8 = v_2;
// end of prologue
    v_8 = qcar(v_8);
    v_8 = qcar(v_8);
    {
        fn = elt(env, 1); // wedgefax
        return (*qfn1(fn))(fn, v_8);
    }
}



// Code for times!:

static LispObject CC_timesT(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_38, v_39;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
    goto v_12;
v_6:
    stack[-3] = elt(env, 1); // !:rd!:
    goto v_7;
v_8:
    goto v_19;
v_15:
    v_38 = stack[-2];
    v_38 = qcdr(v_38);
    v_39 = qcar(v_38);
    goto v_16;
v_17:
    v_38 = stack[-1];
    v_38 = qcdr(v_38);
    v_38 = qcar(v_38);
    goto v_18;
v_19:
    goto v_15;
v_16:
    goto v_17;
v_18:
    stack[0] = times2(v_39, v_38);
    env = stack[-4];
    goto v_9;
v_10:
    goto v_31;
v_27:
    v_38 = stack[-2];
    v_38 = qcdr(v_38);
    v_39 = qcdr(v_38);
    goto v_28;
v_29:
    v_38 = stack[-1];
    v_38 = qcdr(v_38);
    v_38 = qcdr(v_38);
    goto v_30;
v_31:
    goto v_27;
v_28:
    goto v_29;
v_30:
    v_38 = plus2(v_39, v_38);
    goto v_11;
v_12:
    goto v_6;
v_7:
    goto v_8;
v_9:
    goto v_10;
v_11:
    {
        LispObject v_44 = stack[-3];
        LispObject v_45 = stack[0];
        return list2star(v_44, v_45, v_38);
    }
}



// Code for convprec

static LispObject CC_convprec(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_7;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7 = v_2;
// end of prologue
    fn = elt(env, 1); // round!*
    v_7 = (*qfn1(fn))(fn, v_7);
    env = stack[0];
    {
        fn = elt(env, 2); // convchk
        return (*qfn1(fn))(fn, v_7);
    }
}



// Code for physopp

static LispObject CC_physopp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_47, v_48;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_48 = v_2;
// end of prologue
    v_47 = v_48;
    if (!consp(v_47)) goto v_6;
    else goto v_7;
v_6:
    v_47 = v_48;
    if (symbolp(v_47)) goto v_12;
    v_47 = nil;
    goto v_10;
v_12:
    goto v_21;
v_17:
    v_47 = v_48;
    if (!symbolp(v_47)) v_47 = nil;
    else { v_47 = qfastgets(v_47);
           if (v_47 != nil) { v_47 = elt(v_47, 2); // rtype
#ifdef RECORD_GET
             if (v_47 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_47 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_47 == SPID_NOPROP) v_47 = nil; }}
#endif
    goto v_18;
v_19:
    v_48 = elt(env, 1); // physop
    goto v_20;
v_21:
    goto v_17;
v_18:
    goto v_19;
v_20:
    v_47 = (v_47 == v_48 ? lisp_true : nil);
    goto v_10;
    v_47 = nil;
v_10:
    goto v_5;
v_7:
    v_47 = v_48;
    v_47 = qcar(v_47);
    if (symbolp(v_47)) goto v_31;
    v_47 = nil;
    goto v_29;
v_31:
    goto v_41;
v_37:
    v_47 = v_48;
    v_47 = qcar(v_47);
    if (!symbolp(v_47)) v_47 = nil;
    else { v_47 = qfastgets(v_47);
           if (v_47 != nil) { v_47 = elt(v_47, 2); // rtype
#ifdef RECORD_GET
             if (v_47 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_47 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_47 == SPID_NOPROP) v_47 = nil; }}
#endif
    goto v_38;
v_39:
    v_48 = elt(env, 1); // physop
    goto v_40;
v_41:
    goto v_37;
v_38:
    goto v_39;
v_40:
    v_47 = (v_47 == v_48 ? lisp_true : nil);
    goto v_29;
    v_47 = nil;
v_29:
    goto v_5;
    v_47 = nil;
v_5:
    return onevalue(v_47);
}



// Code for memq_edgelist

static LispObject CC_memq_edgelist(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_14, v_15;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14 = v_3;
    v_15 = v_2;
// end of prologue
    goto v_9;
v_5:
    v_15 = qcar(v_15);
    goto v_6;
v_7:
    goto v_8;
v_9:
    goto v_5;
v_6:
    goto v_7;
v_8:
    v_14 = Lassoc(nil, v_15, v_14);
    return onevalue(v_14);
}



// Code for mo_comp

static LispObject CC_mo_comp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_16, v_17;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16 = v_2;
// end of prologue
    v_17 = v_16;
    v_17 = qcar(v_17);
    if (v_17 == nil) goto v_6;
    else goto v_7;
v_6:
    v_16 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5;
v_7:
    v_16 = qcar(v_16);
    v_16 = qcar(v_16);
    goto v_5;
    v_16 = nil;
v_5:
    return onevalue(v_16);
}



// Code for c_zero

static LispObject CC_c_zero(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_4;
    argcheck(nargs, 0, "c_zero");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_4 = nil;
    return onevalue(v_4);
}



// Code for sieve_pv0

static LispObject CC_sieve_pv0(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_68, v_69, v_70;
    LispObject fn;
    LispObject v_4, v_3, v_2;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sieve_pv0");
    va_start(aa, nargs);
    v_2 = va_arg(aa, LispObject);
    v_3 = va_arg(aa, LispObject);
    v_4 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_4,v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_2,v_3,v_4);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4;
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
    v_68 = stack[-2];
    if (v_68 == nil) goto v_8;
    else goto v_9;
v_8:
    v_68 = nil;
    goto v_7;
v_9:
v_16:
    v_68 = stack[-1];
    if (v_68 == nil) goto v_19;
    goto v_29;
v_25:
    v_68 = stack[-1];
    v_68 = qcar(v_68);
    v_68 = qcar(v_68);
    v_69 = qcdr(v_68);
    goto v_26;
v_27:
    v_68 = stack[-2];
    v_68 = qcar(v_68);
    v_68 = qcdr(v_68);
    goto v_28;
v_29:
    goto v_25;
v_26:
    goto v_27;
v_28:
    v_68 = (LispObject)greaterp2(v_69, v_68);
    v_68 = v_68 ? lisp_true : nil;
    env = stack[-3];
    if (v_68 == nil) goto v_19;
    goto v_20;
v_19:
    goto v_15;
v_20:
    v_68 = stack[-1];
    v_68 = qcdr(v_68);
    stack[-1] = v_68;
    goto v_16;
v_15:
v_42:
    v_68 = stack[-2];
    if (v_68 == nil) goto v_45;
    v_68 = stack[-1];
    if (v_68 == nil) goto v_45;
    goto v_46;
v_45:
    goto v_41;
v_46:
    goto v_59;
v_53:
    v_70 = stack[-2];
    goto v_54;
v_55:
    v_68 = stack[-1];
    v_69 = qcar(v_68);
    goto v_56;
v_57:
    v_68 = stack[0];
    goto v_58;
v_59:
    goto v_53;
v_54:
    goto v_55;
v_56:
    goto v_57;
v_58:
    fn = elt(env, 1); // reduce_pv0
    v_68 = (*qfnn(fn))(fn, 3, v_70, v_69, v_68);
    env = stack[-3];
    stack[-2] = v_68;
    v_68 = stack[-1];
    v_68 = qcdr(v_68);
    stack[-1] = v_68;
    goto v_42;
v_41:
    v_68 = stack[-2];
    goto v_7;
    v_68 = nil;
v_7:
    return onevalue(v_68);
}



// Code for wideid2list

static LispObject CC_wideid2list(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_7;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7 = v_2;
// end of prologue
    fn = elt(env, 1); // id2string
    v_7 = (*qfn1(fn))(fn, v_7);
    env = stack[0];
    {
        fn = elt(env, 2); // widestring2list
        return (*qfn1(fn))(fn, v_7);
    }
}



// Code for lalr_productions

static LispObject CC_lalr_productions(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_12, v_13;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12 = v_2;
// end of prologue
    goto v_9;
v_5:
    goto v_6;
v_7:
    v_13 = elt(env, 1); // lalr_produces
    goto v_8;
v_9:
    goto v_5;
v_6:
    goto v_7;
v_8:
    return get(v_12, v_13);
}



// Code for random_new_seed

static LispObject CC_random_new_seed(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_236, v_237, v_238;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_236 = stack[0];
    v_236 = integerp(v_236);
    if (v_236 == nil) goto v_17;
    else goto v_18;
v_17:
    v_236 = lisp_true;
    goto v_16;
v_18:
    goto v_29;
v_25:
    v_237 = stack[0];
    goto v_26;
v_27:
    v_236 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28;
v_29:
    goto v_25;
v_26:
    goto v_27;
v_28:
    v_236 = (LispObject)lesseq2(v_237, v_236);
    v_236 = v_236 ? lisp_true : nil;
    env = stack[-4];
    goto v_16;
    v_236 = nil;
v_16:
    if (v_236 == nil) goto v_14;
    goto v_37;
v_33:
    v_237 = stack[0];
    goto v_34;
v_35:
    v_236 = elt(env, 2); // "positive integer"
    goto v_36;
v_37:
    goto v_33;
v_34:
    goto v_35;
v_36:
    fn = elt(env, 7); // typerr
    v_236 = (*qfn2(fn))(fn, v_237, v_236);
    env = stack[-4];
    goto v_12;
v_14:
v_12:
    goto v_45;
v_41:
    v_237 = stack[0];
    goto v_42;
v_43:
    v_236 = qvalue(elt(env, 3)); // randommodulus!*
    goto v_44;
v_45:
    goto v_41;
v_42:
    goto v_43;
v_44:
    v_236 = Cremainder(v_237, v_236);
    env = stack[-4];
    stack[-3] = v_236;
    goto v_54;
v_48:
    v_238 = qvalue(elt(env, 4)); // unidev_vec!*
    goto v_49;
v_50:
    v_237 = (LispObject)864+TAG_FIXNUM; // 54
    goto v_51;
v_52:
    v_236 = stack[-3];
    goto v_53;
v_54:
    goto v_48;
v_49:
    goto v_50;
v_51:
    goto v_52;
v_53:
    *(LispObject *)((char *)v_238 + (CELL-TAG_VECTOR) + (((intptr_t)v_237-TAG_FIXNUM)/(16/CELL))) = v_236;
    v_236 = stack[-3];
    v_236 = add1(v_236);
    env = stack[-4];
    stack[-2] = v_236;
    v_236 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_236;
v_63:
    goto v_75;
v_71:
    v_237 = (LispObject)864+TAG_FIXNUM; // 54
    goto v_72;
v_73:
    v_236 = stack[0];
    goto v_74;
v_75:
    goto v_71;
v_72:
    goto v_73;
v_74:
    v_236 = difference2(v_237, v_236);
    env = stack[-4];
    v_236 = Lminusp(nil, v_236);
    env = stack[-4];
    if (v_236 == nil) goto v_68;
    goto v_62;
v_68:
    goto v_83;
v_79:
    v_237 = stack[-2];
    goto v_80;
v_81:
    v_236 = stack[-3];
    goto v_82;
v_83:
    goto v_79;
v_80:
    goto v_81;
v_82:
    v_236 = (LispObject)(intptr_t)((intptr_t)v_237 - (intptr_t)v_236 + TAG_FIXNUM);
    stack[-1] = v_236;
    v_236 = stack[-1];
    v_236 = ((intptr_t)(v_236) < 0 ? lisp_true : nil);
    if (v_236 == nil) goto v_90;
    goto v_97;
v_93:
    v_237 = stack[-1];
    goto v_94;
v_95:
    v_236 = qvalue(elt(env, 3)); // randommodulus!*
    goto v_96;
v_97:
    goto v_93;
v_94:
    goto v_95;
v_96:
    v_236 = (LispObject)(intptr_t)((intptr_t)v_237 + (intptr_t)v_236 - TAG_FIXNUM);
    stack[-1] = v_236;
    goto v_88;
v_90:
v_88:
    goto v_106;
v_102:
    goto v_112;
v_108:
    v_237 = (LispObject)336+TAG_FIXNUM; // 21
    goto v_109;
v_110:
    v_236 = stack[0];
    goto v_111;
v_112:
    goto v_108;
v_109:
    goto v_110;
v_111:
    v_237 = times2(v_237, v_236);
    env = stack[-4];
    goto v_103;
v_104:
    v_236 = (LispObject)880+TAG_FIXNUM; // 55
    goto v_105;
v_106:
    goto v_102;
v_103:
    goto v_104;
v_105:
    v_236 = Cremainder(v_237, v_236);
    env = stack[-4];
    goto v_122;
v_116:
    v_238 = qvalue(elt(env, 4)); // unidev_vec!*
    goto v_117;
v_118:
    v_237 = (LispObject)((intptr_t)(v_236) - 0x10);
    goto v_119;
v_120:
    v_236 = stack[-1];
    goto v_121;
v_122:
    goto v_116;
v_117:
    goto v_118;
v_119:
    goto v_120;
v_121:
    *(LispObject *)((char *)v_238 + (CELL-TAG_VECTOR) + (((intptr_t)v_237-TAG_FIXNUM)/(16/CELL))) = v_236;
    v_236 = stack[-3];
    stack[-2] = v_236;
    v_236 = stack[-1];
    stack[-3] = v_236;
    v_236 = stack[0];
    v_236 = add1(v_236);
    env = stack[-4];
    stack[0] = v_236;
    goto v_63;
v_62:
    v_236 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_236;
v_134:
    goto v_146;
v_142:
    v_237 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_143;
v_144:
    v_236 = stack[-3];
    goto v_145;
v_146:
    goto v_142;
v_143:
    goto v_144;
v_145:
    v_236 = difference2(v_237, v_236);
    env = stack[-4];
    v_236 = Lminusp(nil, v_236);
    env = stack[-4];
    if (v_236 == nil) goto v_139;
    goto v_133;
v_139:
    v_236 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_236;
v_153:
    goto v_165;
v_161:
    v_237 = (LispObject)864+TAG_FIXNUM; // 54
    goto v_162;
v_163:
    v_236 = stack[-2];
    goto v_164;
v_165:
    goto v_161;
v_162:
    goto v_163;
v_164:
    v_236 = difference2(v_237, v_236);
    env = stack[-4];
    v_236 = Lminusp(nil, v_236);
    env = stack[-4];
    if (v_236 == nil) goto v_158;
    goto v_152;
v_158:
    goto v_173;
v_169:
    goto v_178;
v_174:
    v_237 = qvalue(elt(env, 4)); // unidev_vec!*
    goto v_175;
v_176:
    v_236 = stack[-2];
    goto v_177;
v_178:
    goto v_174;
v_175:
    goto v_176;
v_177:
    stack[-1] = *(LispObject *)((char *)v_237 + (CELL-TAG_VECTOR) + (((intptr_t)v_236-TAG_FIXNUM)/(16/CELL)));
    goto v_170;
v_171:
    goto v_186;
v_182:
    stack[0] = qvalue(elt(env, 4)); // unidev_vec!*
    goto v_183;
v_184:
    goto v_193;
v_189:
    goto v_198;
v_194:
    v_237 = stack[-2];
    goto v_195;
v_196:
    v_236 = (LispObject)496+TAG_FIXNUM; // 31
    goto v_197;
v_198:
    goto v_194;
v_195:
    goto v_196;
v_197:
    v_237 = (LispObject)(intptr_t)((intptr_t)v_237 + (intptr_t)v_236 - TAG_FIXNUM);
    goto v_190;
v_191:
    v_236 = (LispObject)880+TAG_FIXNUM; // 55
    goto v_192;
v_193:
    goto v_189;
v_190:
    goto v_191;
v_192:
    v_236 = Cremainder(v_237, v_236);
    env = stack[-4];
    goto v_185;
v_186:
    goto v_182;
v_183:
    goto v_184;
v_185:
    v_236 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_236-TAG_FIXNUM)/(16/CELL)));
    goto v_172;
v_173:
    goto v_169;
v_170:
    goto v_171;
v_172:
    v_236 = (LispObject)(intptr_t)((intptr_t)stack[-1] - (intptr_t)v_236 + TAG_FIXNUM);
    stack[-1] = v_236;
    v_236 = stack[-1];
    v_236 = ((intptr_t)(v_236) < 0 ? lisp_true : nil);
    if (v_236 == nil) goto v_208;
    goto v_215;
v_211:
    v_237 = stack[-1];
    goto v_212;
v_213:
    v_236 = qvalue(elt(env, 3)); // randommodulus!*
    goto v_214;
v_215:
    goto v_211;
v_212:
    goto v_213;
v_214:
    v_236 = (LispObject)(intptr_t)((intptr_t)v_237 + (intptr_t)v_236 - TAG_FIXNUM);
    stack[-1] = v_236;
    goto v_206;
v_208:
v_206:
    goto v_225;
v_219:
    v_238 = qvalue(elt(env, 4)); // unidev_vec!*
    goto v_220;
v_221:
    v_237 = stack[-2];
    goto v_222;
v_223:
    v_236 = stack[-1];
    goto v_224;
v_225:
    goto v_219;
v_220:
    goto v_221;
v_222:
    goto v_223;
v_224:
    *(LispObject *)((char *)v_238 + (CELL-TAG_VECTOR) + (((intptr_t)v_237-TAG_FIXNUM)/(16/CELL))) = v_236;
    v_236 = stack[-2];
    v_236 = add1(v_236);
    env = stack[-4];
    stack[-2] = v_236;
    goto v_153;
v_152:
    v_236 = stack[-3];
    v_236 = add1(v_236);
    env = stack[-4];
    stack[-3] = v_236;
    goto v_134;
v_133:
    v_236 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 5)) = v_236; // unidev_next!*
    v_236 = (LispObject)496+TAG_FIXNUM; // 31
    qvalue(elt(env, 6)) = v_236; // unidev_nextp!*
    v_236 = nil;
    return onevalue(v_236);
}



// Code for monomgetvariabledegree

static LispObject CC_monomgetvariabledegree(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_63, v_64;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    v_63 = v_2;
// end of prologue
    goto v_13;
v_9:
    v_64 = v_63;
    goto v_10;
v_11:
    v_63 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12;
v_13:
    goto v_9;
v_10:
    goto v_11;
v_12:
    v_63 = *(LispObject *)((char *)v_64 + (CELL-TAG_VECTOR) + (((intptr_t)v_63-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_63;
v_19:
    v_63 = stack[-1];
    v_63 = qcar(v_63);
    if (v_63 == nil) goto v_22;
    goto v_33;
v_29:
    v_63 = stack[-1];
    v_64 = qcar(v_63);
    goto v_30;
v_31:
    v_63 = stack[0];
    goto v_32;
v_33:
    goto v_29;
v_30:
    goto v_31;
v_32:
    v_63 = (LispObject)greaterp2(v_64, v_63);
    v_63 = v_63 ? lisp_true : nil;
    env = stack[-2];
    if (v_63 == nil) goto v_22;
    goto v_23;
v_22:
    goto v_18;
v_23:
    v_63 = stack[-1];
    v_63 = qcdr(v_63);
    stack[-1] = v_63;
    goto v_19;
v_18:
    v_63 = stack[-1];
    v_63 = qcar(v_63);
    if (v_63 == nil) goto v_44;
    goto v_53;
v_49:
    v_63 = stack[-1];
    v_64 = qcar(v_63);
    goto v_50;
v_51:
    v_63 = stack[0];
    goto v_52;
v_53:
    goto v_49;
v_50:
    goto v_51;
v_52:
    if (equal(v_64, v_63)) goto v_48;
    else goto v_44;
v_48:
    v_63 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7;
v_44:
    v_63 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7;
    v_63 = nil;
v_7:
    return onevalue(v_63);
}



// Code for makelist

static LispObject CC_makelist(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_12, v_13;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12 = v_2;
// end of prologue
    goto v_9;
v_5:
    v_13 = elt(env, 1); // list
    goto v_6;
v_7:
    goto v_8;
v_9:
    goto v_5;
v_6:
    goto v_7;
v_8:
    return cons(v_13, v_12);
}



// Code for mchk!*

static LispObject CC_mchkH(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_46, v_47;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    goto v_18;
v_14:
    v_47 = stack[-1];
    goto v_15;
v_16:
    v_46 = stack[0];
    goto v_17;
v_18:
    goto v_14;
v_15:
    goto v_16;
v_17:
    fn = elt(env, 3); // mchk
    v_46 = (*qfn2(fn))(fn, v_47, v_46);
    env = stack[-2];
    v_47 = v_46;
    if (v_46 == nil) goto v_12;
    v_46 = v_47;
    goto v_7;
v_12:
    v_46 = qvalue(elt(env, 2)); // !*mcd
    if (v_46 == nil) goto v_24;
    else goto v_22;
v_24:
    v_46 = stack[-1];
    fn = elt(env, 4); // sfp
    v_46 = (*qfn1(fn))(fn, v_46);
    env = stack[-2];
    if (v_46 == nil) goto v_22;
    v_46 = stack[0];
    fn = elt(env, 4); // sfp
    v_46 = (*qfn1(fn))(fn, v_46);
    env = stack[-2];
    if (v_46 == nil) goto v_22;
    goto v_23;
v_22:
    v_46 = nil;
    goto v_7;
v_23:
    goto v_41;
v_37:
    v_46 = stack[-1];
    fn = elt(env, 5); // prepf
    stack[-1] = (*qfn1(fn))(fn, v_46);
    env = stack[-2];
    goto v_38;
v_39:
    v_46 = stack[0];
    fn = elt(env, 5); // prepf
    v_46 = (*qfn1(fn))(fn, v_46);
    env = stack[-2];
    goto v_40;
v_41:
    goto v_37;
v_38:
    goto v_39;
v_40:
    {
        LispObject v_50 = stack[-1];
        fn = elt(env, 3); // mchk
        return (*qfn2(fn))(fn, v_50, v_46);
    }
    v_46 = nil;
v_7:
    return onevalue(v_46);
}



// Code for get!+mat!+entry

static LispObject CC_getLmatLentry(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24, v_25;
    LispObject fn;
    LispObject v_4, v_3, v_2;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "get+mat+entry");
    va_start(aa, nargs);
    v_2 = va_arg(aa, LispObject);
    v_3 = va_arg(aa, LispObject);
    v_4 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_4,v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_2,v_3,v_4);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_4;
    v_24 = v_3;
    v_25 = v_2;
// end of prologue
    goto v_14;
v_10:
    goto v_20;
v_16:
    goto v_17;
v_18:
    goto v_19;
v_20:
    goto v_16;
v_17:
    goto v_18;
v_19:
    fn = elt(env, 1); // nth
    v_25 = (*qfn2(fn))(fn, v_25, v_24);
    env = stack[-1];
    goto v_11;
v_12:
    v_24 = stack[0];
    goto v_13;
v_14:
    goto v_10;
v_11:
    goto v_12;
v_13:
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(fn, v_25, v_24);
    }
    return onevalue(v_24);
}



// Code for talp_getextl

static LispObject CC_talp_getextl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_4;
    argcheck(nargs, 0, "talp_getextl");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_4 = qvalue(elt(env, 1)); // talp_extlang!*
    return onevalue(v_4);
}



// Code for powers

static LispObject CC_powers(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_12, v_13;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12 = v_2;
// end of prologue
    goto v_9;
v_5:
    v_13 = v_12;
    goto v_6;
v_7:
    v_12 = nil;
    goto v_8;
v_9:
    goto v_5;
v_6:
    goto v_7;
v_8:
    {
        fn = elt(env, 1); // powers0
        return (*qfn2(fn))(fn, v_13, v_12);
    }
}



// Code for ibalp_clmember

static LispObject CC_ibalp_clmember(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_34, v_35;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
v_1:
    v_34 = stack[0];
    if (v_34 == nil) goto v_7;
    else goto v_8;
v_7:
    v_34 = nil;
    goto v_6;
v_8:
    goto v_21;
v_17:
    v_35 = stack[-1];
    goto v_18;
v_19:
    v_34 = stack[0];
    v_34 = qcar(v_34);
    goto v_20;
v_21:
    goto v_17;
v_18:
    goto v_19;
v_20:
    fn = elt(env, 1); // ibalp_cequal
    v_34 = (*qfn2(fn))(fn, v_35, v_34);
    env = stack[-2];
    if (v_34 == nil) goto v_15;
    else goto v_14;
v_15:
    goto v_30;
v_26:
    v_35 = stack[-1];
    goto v_27;
v_28:
    v_34 = stack[0];
    v_34 = qcdr(v_34);
    goto v_29;
v_30:
    goto v_26;
v_27:
    goto v_28;
v_29:
    stack[-1] = v_35;
    stack[0] = v_34;
    goto v_1;
v_14:
    goto v_6;
    v_34 = nil;
v_6:
    return onevalue(v_34);
}



// Code for find2

static LispObject CC_find2(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_48, v_49, v_50, v_51;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_49 = v_3;
    v_50 = v_2;
// end of prologue
v_1:
    goto v_16;
v_12:
    v_51 = v_49;
    goto v_13;
v_14:
    v_48 = nil;
    goto v_15;
v_16:
    goto v_12;
v_13:
    goto v_14;
v_15:
    if (v_51 == v_48) goto v_10;
    else goto v_11;
v_10:
    v_48 = v_50;
    if (v_48 == nil) goto v_22;
    v_48 = v_50;
    v_48 = qcdr(v_48);
    goto v_20;
v_22:
    v_48 = elt(env, 1); // (stop)
    goto v_20;
    v_48 = nil;
v_20:
    goto v_9;
v_11:
    goto v_36;
v_32:
    goto v_41;
v_37:
    v_48 = v_49;
    v_48 = qcar(v_48);
    goto v_38;
v_39:
    goto v_40;
v_41:
    goto v_37;
v_38:
    goto v_39;
v_40:
    v_50 = Lmember(nil, v_48, v_50);
    goto v_33;
v_34:
    v_48 = v_49;
    v_48 = qcdr(v_48);
    goto v_35;
v_36:
    goto v_32;
v_33:
    goto v_34;
v_35:
    v_49 = v_48;
    goto v_1;
    v_48 = nil;
v_9:
    return onevalue(v_48);
}



// Code for exchk

static LispObject CC_exchk(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_18, v_19, v_20, v_21;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18 = v_2;
// end of prologue
    goto v_13;
v_5:
    v_21 = v_18;
    goto v_6;
v_7:
    v_20 = nil;
    goto v_8;
v_9:
    v_19 = nil;
    goto v_10;
v_11:
    v_18 = nil;
    goto v_12;
v_13:
    goto v_5;
v_6:
    goto v_7;
v_8:
    goto v_9;
v_10:
    goto v_11;
v_12:
    {
        fn = elt(env, 1); // exchk1
        return (*qfnn(fn))(fn, 4, v_21, v_20, v_19, v_18);
    }
}



// Code for zero2nil

static LispObject CC_zero2nil(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_14;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_14 = stack[0];
    fn = elt(env, 1); // !:zerop
    v_14 = (*qfn1(fn))(fn, v_14);
    if (v_14 == nil) goto v_7;
    v_14 = nil;
    goto v_5;
v_7:
    v_14 = stack[0];
    goto v_5;
    v_14 = nil;
v_5:
    return onevalue(v_14);
}



// Code for mval

static LispObject CC_mval(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_5;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5 = v_2;
// end of prologue
    return onevalue(v_5);
}



// Code for vbcsize

static LispObject CC_vbcsize(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_51, v_52, v_53;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_52 = v_3;
    stack[0] = v_2;
// end of prologue
v_1:
    goto v_13;
v_9:
    v_53 = v_52;
    goto v_10;
v_11:
    v_51 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_12;
v_13:
    goto v_9;
v_10:
    goto v_11;
v_12:
    if (((intptr_t)(v_53)) > ((intptr_t)(v_51))) goto v_7;
    else goto v_8;
v_7:
    v_51 = nil;
    goto v_6;
v_8:
    v_51 = stack[0];
    if (!consp(v_51)) goto v_17;
    else goto v_18;
v_17:
    v_51 = v_52;
    goto v_6;
v_18:
    goto v_31;
v_27:
    v_51 = stack[0];
    v_51 = qcar(v_51);
    goto v_28;
v_29:
    v_52 = (LispObject)((intptr_t)(v_52) + 0x10);
    goto v_30;
v_31:
    goto v_27;
v_28:
    goto v_29;
v_30:
    v_51 = CC_vbcsize(elt(env, 0), v_51, v_52);
    env = stack[-1];
    v_52 = v_51;
    v_51 = v_52;
    if (v_51 == nil) goto v_38;
    else goto v_39;
v_38:
    v_51 = nil;
    goto v_24;
v_39:
    goto v_47;
v_43:
    v_51 = stack[0];
    v_51 = qcdr(v_51);
    goto v_44;
v_45:
    goto v_46;
v_47:
    goto v_43;
v_44:
    goto v_45;
v_46:
    stack[0] = v_51;
    goto v_1;
v_24:
    goto v_6;
    v_51 = nil;
v_6:
    return onevalue(v_51);
}



// Code for pnth

static LispObject CC_pnth(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_40, v_41, v_42;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_41 = v_3;
    stack[0] = v_2;
// end of prologue
v_7:
    v_40 = stack[0];
    if (v_40 == nil) goto v_10;
    else goto v_11;
v_10:
    goto v_20;
v_14:
    v_42 = elt(env, 1); // alg
    goto v_15;
v_16:
    v_41 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_17;
v_18:
    v_40 = elt(env, 2); // "Index out of range"
    goto v_19;
v_20:
    goto v_14;
v_15:
    goto v_16;
v_17:
    goto v_18;
v_19:
    {
        fn = elt(env, 3); // rerror
        return (*qfnn(fn))(fn, 3, v_42, v_41, v_40);
    }
v_11:
    goto v_30;
v_26:
    v_42 = v_41;
    goto v_27;
v_28:
    v_40 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29;
v_30:
    goto v_26;
v_27:
    goto v_28;
v_29:
    if (v_42 == v_40) goto v_24;
    else goto v_25;
v_24:
    v_40 = stack[0];
    goto v_6;
v_25:
    v_40 = stack[0];
    v_40 = qcdr(v_40);
    stack[0] = v_40;
    v_40 = v_41;
    v_40 = sub1(v_40);
    env = stack[-1];
    v_41 = v_40;
    goto v_7;
    v_40 = nil;
v_6:
    return onevalue(v_40);
}



// Code for wedgefax

static LispObject CC_wedgefax(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_22, v_23, v_24;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23 = v_2;
// end of prologue
    goto v_13;
v_9:
    v_22 = v_23;
    goto v_10;
v_11:
    v_24 = elt(env, 1); // wedge
    goto v_12;
v_13:
    goto v_9;
v_10:
    goto v_11;
v_12:
    if (!consp(v_22)) goto v_7;
    v_22 = qcar(v_22);
    if (v_22 == v_24) goto v_6;
    else goto v_7;
v_6:
    v_22 = v_23;
    v_22 = qcdr(v_22);
    goto v_5;
v_7:
    v_22 = v_23;
    return ncons(v_22);
    v_22 = nil;
v_5:
    return onevalue(v_22);
}



// Code for mkvar

static LispObject CC_mkvar(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_6, v_7;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_6 = v_3;
    v_7 = v_2;
// end of prologue
    v_6 = v_7;
    return onevalue(v_6);
}



// Code for argsofopr

static LispObject CC_argsofopr(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_6;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_6 = v_2;
// end of prologue
    if (!symbolp(v_6)) v_6 = nil;
    else { v_6 = qfastgets(v_6);
           if (v_6 != nil) { v_6 = elt(v_6, 42); // number!-of!-args
#ifdef RECORD_GET
             if (v_6 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v_6 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v_6 == SPID_NOPROP) v_6 = nil; }}
#endif
    return onevalue(v_6);
}



// Code for termsf

static LispObject CC_termsf(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_51, v_52;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_51 = (LispObject)0+TAG_FIXNUM; // 0
    v_52 = v_51;
v_11:
    v_51 = stack[0];
    if (!consp(v_51)) goto v_18;
    else goto v_19;
v_18:
    v_51 = lisp_true;
    goto v_17;
v_19:
    v_51 = stack[0];
    v_51 = qcar(v_51);
    v_51 = (consp(v_51) ? nil : lisp_true);
    goto v_17;
    v_51 = nil;
v_17:
    if (v_51 == nil) goto v_15;
    goto v_10;
v_15:
    goto v_33;
v_29:
    stack[-1] = v_52;
    goto v_30;
v_31:
    v_51 = stack[0];
    v_51 = qcar(v_51);
    v_51 = qcdr(v_51);
    v_51 = CC_termsf(elt(env, 0), v_51);
    env = stack[-2];
    goto v_32;
v_33:
    goto v_29;
v_30:
    goto v_31;
v_32:
    v_51 = plus2(stack[-1], v_51);
    env = stack[-2];
    v_52 = v_51;
    v_51 = stack[0];
    v_51 = qcdr(v_51);
    stack[0] = v_51;
    goto v_11;
v_10:
    v_51 = stack[0];
    if (v_51 == nil) goto v_43;
    else goto v_44;
v_43:
    v_51 = v_52;
    goto v_42;
v_44:
    v_51 = v_52;
    return add1(v_51);
    v_51 = nil;
v_42:
    return onevalue(v_51);
}



// Code for mkspm

static LispObject CC_mkspm(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_60, v_61;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    goto v_13;
v_9:
    v_61 = stack[0];
    goto v_10;
v_11:
    v_60 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12;
v_13:
    goto v_9;
v_10:
    goto v_11;
v_12:
    if (v_61 == v_60) goto v_7;
    else goto v_8;
v_7:
    v_60 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6;
v_8:
    v_60 = qvalue(elt(env, 2)); // subfg!*
    if (v_60 == nil) goto v_26;
    goto v_35;
v_31:
    v_61 = stack[-1];
    goto v_32;
v_33:
    v_60 = qvalue(elt(env, 3)); // asymplis!*
    goto v_34;
v_35:
    goto v_31;
v_32:
    goto v_33;
v_34:
    v_60 = Latsoc(nil, v_61, v_60);
    v_61 = v_60;
    if (v_60 == nil) goto v_26;
    goto v_45;
v_41:
    v_60 = v_61;
    v_61 = qcdr(v_60);
    goto v_42;
v_43:
    v_60 = stack[0];
    goto v_44;
v_45:
    goto v_41;
v_42:
    goto v_43;
v_44:
    v_60 = (LispObject)lesseq2(v_61, v_60);
    v_60 = v_60 ? lisp_true : nil;
    env = stack[-2];
    if (v_60 == nil) goto v_26;
    v_60 = nil;
    goto v_21;
v_26:
    v_60 = stack[-1];
    fn = elt(env, 4); // sub2chk
    v_60 = (*qfn1(fn))(fn, v_60);
    env = stack[-2];
    goto v_57;
v_53:
    v_61 = stack[-1];
    goto v_54;
v_55:
    v_60 = stack[0];
    goto v_56;
v_57:
    goto v_53;
v_54:
    goto v_55;
v_56:
    {
        fn = elt(env, 5); // to
        return (*qfn2(fn))(fn, v_61, v_60);
    }
v_21:
    goto v_6;
    v_60 = nil;
v_6:
    return onevalue(v_60);
}



// Code for dssoc

static LispObject CC_dssoc(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_31, v_32, v_33, v_34;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_32 = v_3;
    v_33 = v_2;
// end of prologue
v_7:
    v_31 = v_32;
    if (v_31 == nil) goto v_10;
    else goto v_11;
v_10:
    v_31 = nil;
    goto v_6;
v_11:
    goto v_20;
v_16:
    v_34 = v_33;
    goto v_17;
v_18:
    v_31 = v_32;
    v_31 = qcar(v_31);
    v_31 = qcdr(v_31);
    goto v_19;
v_20:
    goto v_16;
v_17:
    goto v_18;
v_19:
    if (equal(v_34, v_31)) goto v_14;
    else goto v_15;
v_14:
    v_31 = v_32;
    v_31 = qcar(v_31);
    goto v_6;
v_15:
    v_31 = v_32;
    v_31 = qcdr(v_31);
    v_32 = v_31;
    goto v_7;
    v_31 = nil;
v_6:
    return onevalue(v_31);
}



// Code for listp

static LispObject CC_listp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_23, v_24;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23 = v_2;
// end of prologue
v_1:
    v_24 = v_23;
    if (v_24 == nil) goto v_6;
    else goto v_7;
v_6:
    v_23 = lisp_true;
    goto v_5;
v_7:
    v_24 = v_23;
    if (!consp(v_24)) goto v_15;
    v_23 = qcdr(v_23);
    goto v_1;
v_15:
    v_23 = nil;
    goto v_13;
    v_23 = nil;
v_13:
    goto v_5;
    v_23 = nil;
v_5:
    return onevalue(v_23);
}



// Code for rnzerop!:

static LispObject CC_rnzeropT(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_14, v_15;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14 = v_2;
// end of prologue
    goto v_8;
v_4:
    v_14 = qcdr(v_14);
    v_15 = qcar(v_14);
    goto v_5;
v_6:
    v_14 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7;
v_8:
    goto v_4;
v_5:
    goto v_6;
v_7:
    v_14 = (v_15 == v_14 ? lisp_true : nil);
    return onevalue(v_14);
}



// Code for modzerop!:

static LispObject CC_modzeropT(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_13, v_14;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13 = v_2;
// end of prologue
    goto v_8;
v_4:
    v_14 = qcdr(v_13);
    goto v_5;
v_6:
    v_13 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7;
v_8:
    goto v_4;
v_5:
    goto v_6;
v_7:
    v_13 = (v_14 == v_13 ? lisp_true : nil);
    return onevalue(v_13);
}



// Code for mksp

static LispObject CC_mksp(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_14, v_15;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_3;
    v_14 = v_2;
// end of prologue
    goto v_10;
v_6:
    fn = elt(env, 1); // fkern
    v_15 = (*qfn1(fn))(fn, v_14);
    env = stack[-1];
    goto v_7;
v_8:
    v_14 = stack[0];
    goto v_9;
v_10:
    goto v_6;
v_7:
    goto v_8;
v_9:
    {
        fn = elt(env, 2); // getpower
        return (*qfn2(fn))(fn, v_15, v_14);
    }
}



// Code for prin2x

static LispObject CC_prin2x(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_12, v_13;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12 = v_2;
// end of prologue
    goto v_9;
v_5:
    v_13 = v_12;
    goto v_6;
v_7:
    v_12 = qvalue(elt(env, 1)); // outl!*
    goto v_8;
v_9:
    goto v_5;
v_6:
    goto v_7;
v_8:
    v_12 = cons(v_13, v_12);
    env = stack[0];
    qvalue(elt(env, 1)) = v_12; // outl!*
    return onevalue(v_12);
}



// Code for aeval

static LispObject CC_aeval(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_12, v_13;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12 = v_2;
// end of prologue
    goto v_9;
v_5:
    v_13 = v_12;
    goto v_6;
v_7:
    v_12 = nil;
    goto v_8;
v_9:
    goto v_5;
v_6:
    goto v_7;
v_8:
    {
        fn = elt(env, 1); // reval1
        return (*qfn2(fn))(fn, v_13, v_12);
    }
}



// Code for lalr_first

static LispObject CC_lalr_first(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_100, v_101, v_102;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_2;
// end of prologue
    stack[-2] = nil;
    stack[0] = nil;
v_11:
    v_100 = stack[-1];
    if (v_100 == nil) goto v_14;
    v_100 = stack[-1];
    v_100 = qcar(v_100);
    if (is_number(v_100)) goto v_22;
    goto v_29;
v_25:
    v_102 = nil;
    goto v_26;
v_27:
    goto v_36;
v_32:
    v_100 = stack[-1];
    v_101 = qcar(v_100);
    goto v_33;
v_34:
    v_100 = elt(env, 0); // lalr_first
    goto v_35;
v_36:
    goto v_32;
v_33:
    goto v_34;
v_35:
    v_100 = get(v_101, v_100);
    env = stack[-3];
    stack[0] = v_100;
    goto v_28;
v_29:
    goto v_25;
v_26:
    goto v_27;
v_28:
    v_100 = Lmember(nil, v_102, v_100);
    goto v_20;
v_22:
    v_100 = nil;
    goto v_20;
    v_100 = nil;
v_20:
    if (v_100 == nil) goto v_14;
    goto v_15;
v_14:
    goto v_10;
v_15:
    goto v_50;
v_46:
    goto v_56;
v_52:
    v_101 = nil;
    goto v_53;
v_54:
    v_100 = stack[0];
    goto v_55;
v_56:
    goto v_52;
v_53:
    goto v_54;
v_55:
    v_101 = Ldeleq(nil, v_101, v_100);
    env = stack[-3];
    goto v_47;
v_48:
    v_100 = stack[-2];
    goto v_49;
v_50:
    goto v_46;
v_47:
    goto v_48;
v_49:
    fn = elt(env, 2); // union
    v_100 = (*qfn2(fn))(fn, v_101, v_100);
    env = stack[-3];
    stack[-2] = v_100;
    v_100 = stack[-1];
    v_100 = qcdr(v_100);
    stack[-1] = v_100;
    goto v_11;
v_10:
    v_100 = stack[-1];
    if (v_100 == nil) goto v_64;
    else goto v_65;
v_64:
    goto v_72;
v_68:
    v_101 = nil;
    goto v_69;
v_70:
    v_100 = stack[-2];
    goto v_71;
v_72:
    goto v_68;
v_69:
    goto v_70;
v_71:
    v_100 = cons(v_101, v_100);
    stack[-2] = v_100;
    goto v_63;
v_65:
    v_100 = stack[-1];
    v_100 = qcar(v_100);
    if (is_number(v_100)) goto v_75;
    else goto v_76;
v_75:
    goto v_84;
v_80:
    v_100 = stack[-1];
    v_100 = qcar(v_100);
    v_101 = ncons(v_100);
    env = stack[-3];
    goto v_81;
v_82:
    v_100 = stack[-2];
    goto v_83;
v_84:
    goto v_80;
v_81:
    goto v_82;
v_83:
    fn = elt(env, 2); // union
    v_100 = (*qfn2(fn))(fn, v_101, v_100);
    stack[-2] = v_100;
    goto v_63;
v_76:
    goto v_96;
v_92:
    v_101 = stack[0];
    goto v_93;
v_94:
    v_100 = stack[-2];
    goto v_95;
v_96:
    goto v_92;
v_93:
    goto v_94;
v_95:
    fn = elt(env, 2); // union
    v_100 = (*qfn2(fn))(fn, v_101, v_100);
    stack[-2] = v_100;
    goto v_63;
v_63:
    v_100 = stack[-2];
    return onevalue(v_100);
}



// Code for aex_ex

static LispObject CC_aex_ex(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_12, v_13;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12 = v_2;
// end of prologue
    goto v_9;
v_5:
    v_13 = v_12;
    goto v_6;
v_7:
    v_12 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_8;
v_9:
    goto v_5;
v_6:
    goto v_7;
v_8:
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(fn, v_13, v_12);
    }
}



// Code for monomcompare

static LispObject CC_monomcompare(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_57, v_58, v_59, v_60;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_59 = v_3;
    v_60 = v_2;
// end of prologue
    goto v_16;
v_12:
    v_58 = qvalue(elt(env, 1)); // fluidbibasismonomialorder
    goto v_13;
v_14:
    v_57 = elt(env, 2); // lex
    goto v_15;
v_16:
    goto v_12;
v_13:
    goto v_14;
v_15:
    if (v_58 == v_57) goto v_10;
    else goto v_11;
v_10:
    goto v_24;
v_20:
    v_57 = v_60;
    goto v_21;
v_22:
    v_58 = v_59;
    goto v_23;
v_24:
    goto v_20;
v_21:
    goto v_22;
v_23:
    {
        fn = elt(env, 4); // monomcomparelex
        return (*qfn2(fn))(fn, v_57, v_58);
    }
v_11:
    goto v_34;
v_30:
    v_58 = qvalue(elt(env, 1)); // fluidbibasismonomialorder
    goto v_31;
v_32:
    v_57 = elt(env, 3); // deglex
    goto v_33;
v_34:
    goto v_30;
v_31:
    goto v_32;
v_33:
    if (v_58 == v_57) goto v_28;
    else goto v_29;
v_28:
    goto v_42;
v_38:
    v_57 = v_60;
    goto v_39;
v_40:
    v_58 = v_59;
    goto v_41;
v_42:
    goto v_38;
v_39:
    goto v_40;
v_41:
    {
        fn = elt(env, 5); // monomcomparedeglex
        return (*qfn2(fn))(fn, v_57, v_58);
    }
v_29:
    goto v_53;
v_49:
    v_57 = v_60;
    goto v_50;
v_51:
    v_58 = v_59;
    goto v_52;
v_53:
    goto v_49;
v_50:
    goto v_51;
v_52:
    {
        fn = elt(env, 6); // monomcomparedegrevlex
        return (*qfn2(fn))(fn, v_57, v_58);
    }
    v_57 = nil;
    return onevalue(v_57);
}



// Code for arrayp

static LispObject CC_arrayp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_13, v_14;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13 = v_2;
// end of prologue
    goto v_8;
v_4:
    if (!symbolp(v_13)) v_13 = nil;
    else { v_13 = qfastgets(v_13);
           if (v_13 != nil) { v_13 = elt(v_13, 2); // rtype
#ifdef RECORD_GET
             if (v_13 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_13 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_13 == SPID_NOPROP) v_13 = nil; }}
#endif
    goto v_5;
v_6:
    v_14 = elt(env, 1); // array
    goto v_7;
v_8:
    goto v_4;
v_5:
    goto v_6;
v_7:
    v_13 = (v_13 == v_14 ? lisp_true : nil);
    return onevalue(v_13);
}



// Code for quotf

static LispObject CC_quotf(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_15, v_16, v_17;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_16 = v_3;
    v_17 = v_2;
// end of prologue
    v_15 = lisp_true;
// Binding !*exp
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_15; // !*exp
    goto v_12;
v_8:
    v_15 = v_17;
    goto v_9;
v_10:
    goto v_11;
v_12:
    goto v_8;
v_9:
    goto v_10;
v_11:
    fn = elt(env, 2); // quotf1
    v_15 = (*qfn2(fn))(fn, v_15, v_16);
    ;}  // end of a binding scope
    return onevalue(v_15);
}



// Code for subs3f

static LispObject CC_subs3f(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_15, v_16, v_17;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15 = v_2;
// end of prologue
    goto v_11;
v_5:
    v_17 = v_15;
    goto v_6;
v_7:
    v_16 = qvalue(elt(env, 1)); // !*match
    goto v_8;
v_9:
    v_15 = lisp_true;
    goto v_10;
v_11:
    goto v_5;
v_6:
    goto v_7;
v_8:
    goto v_9;
v_10:
    {
        fn = elt(env, 2); // subs3f1
        return (*qfnn(fn))(fn, 3, v_17, v_16, v_15);
    }
}



// Code for kernlp

static LispObject CC_kernlp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_33, v_34;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33 = v_2;
// end of prologue
v_6:
    v_34 = v_33;
    if (!consp(v_34)) goto v_13;
    else goto v_14;
v_13:
    v_34 = lisp_true;
    goto v_12;
v_14:
    v_34 = v_33;
    v_34 = qcar(v_34);
    v_34 = (consp(v_34) ? nil : lisp_true);
    goto v_12;
    v_34 = nil;
v_12:
    if (v_34 == nil) goto v_10;
    goto v_5;
v_10:
    v_34 = v_33;
    v_34 = qcdr(v_34);
    if (v_34 == nil) goto v_23;
    else goto v_24;
v_23:
    v_33 = qcar(v_33);
    v_33 = qcdr(v_33);
    goto v_6;
v_24:
    v_33 = nil;
    goto v_5;
    v_33 = nil;
v_5:
    return onevalue(v_33);
}



// Code for talp_invp

static LispObject CC_talp_invp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_38;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_38 = stack[0];
    v_38 = Lconsp(nil, v_38);
    env = stack[-2];
    if (v_38 == nil) goto v_6;
    else goto v_7;
v_6:
    v_38 = nil;
    goto v_5;
v_7:
    goto v_21;
v_17:
    v_38 = stack[0];
    fn = elt(env, 1); // talp_op
    stack[-1] = (*qfn1(fn))(fn, v_38);
    env = stack[-2];
    goto v_18;
v_19:
    fn = elt(env, 2); // talp_getl
    v_38 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_20;
v_21:
    goto v_17;
v_18:
    goto v_19;
v_20:
    v_38 = Latsoc(nil, stack[-1], v_38);
    if (v_38 == nil) goto v_15;
    else goto v_16;
v_15:
    goto v_30;
v_26:
    v_38 = stack[0];
    fn = elt(env, 1); // talp_op
    stack[0] = (*qfn1(fn))(fn, v_38);
    env = stack[-2];
    goto v_27;
v_28:
    fn = elt(env, 3); // talp_getextl
    v_38 = (*qfnn(fn))(fn, 0);
    goto v_29;
v_30:
    goto v_26;
v_27:
    goto v_28;
v_29:
    v_38 = Latsoc(nil, stack[0], v_38);
    goto v_14;
v_16:
    v_38 = nil;
    goto v_14;
    v_38 = nil;
v_14:
    goto v_5;
    v_38 = nil;
v_5:
    return onevalue(v_38);
}



// Code for qqe_rbopp

static LispObject CC_qqe_rbopp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_12, v_13;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12 = v_2;
// end of prologue
    goto v_8;
v_4:
    goto v_5;
v_6:
    v_13 = elt(env, 1); // (equal neq lessp leq geq greaterp)
    goto v_7;
v_8:
    goto v_4;
v_5:
    goto v_6;
v_7:
    v_12 = Lmemq(nil, v_12, v_13);
    return onevalue(v_12);
}



// Code for lto_hashequalq

static LispObject CC_lto_hashequalq(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_76, v_77;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_3;
    stack[-3] = v_2;
// end of prologue
    v_76 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_76;
    v_76 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_76;
v_16:
    v_76 = stack[-3];
    if (v_76 == nil) goto v_19;
    v_76 = stack[-2];
    if (v_76 == nil) goto v_19;
    goto v_20;
v_19:
    goto v_15;
v_20:
    v_76 = stack[-3];
    v_76 = qcar(v_76);
    v_77 = v_76;
    v_76 = stack[-2];
    v_76 = qcar(v_76);
    stack[-4] = v_76;
    v_76 = stack[-3];
    v_76 = qcdr(v_76);
    stack[-3] = v_76;
    v_76 = stack[-2];
    v_76 = qcdr(v_76);
    stack[-2] = v_76;
    goto v_38;
v_34:
    goto v_35;
v_36:
    v_76 = v_77;
    fn = elt(env, 2); // lto_hashid
    v_76 = (*qfn1(fn))(fn, v_76);
    env = stack[-5];
    goto v_37;
v_38:
    goto v_34;
v_35:
    goto v_36;
v_37:
    v_76 = (LispObject)(intptr_t)((intptr_t)stack[-1] + (intptr_t)v_76 - TAG_FIXNUM);
    stack[-1] = v_76;
    goto v_47;
v_43:
    goto v_44;
v_45:
    v_76 = stack[-4];
    fn = elt(env, 2); // lto_hashid
    v_76 = (*qfn1(fn))(fn, v_76);
    env = stack[-5];
    goto v_46;
v_47:
    goto v_43;
v_44:
    goto v_45;
v_46:
    v_76 = (LispObject)(intptr_t)((intptr_t)stack[0] + (intptr_t)v_76 - TAG_FIXNUM);
    stack[0] = v_76;
    goto v_16;
v_15:
    v_76 = stack[-3];
    if (v_76 == nil) goto v_54;
    else goto v_55;
v_54:
    v_76 = stack[-2];
    if (v_76 == nil) goto v_59;
    else goto v_60;
v_59:
    goto v_67;
v_63:
    v_77 = stack[-1];
    goto v_64;
v_65:
    v_76 = stack[0];
    goto v_66;
v_67:
    goto v_63;
v_64:
    goto v_65;
v_66:
    {
        fn = elt(env, 3); // iequal
        return (*qfn2(fn))(fn, v_77, v_76);
    }
v_60:
    v_76 = nil;
    goto v_58;
    v_76 = nil;
v_58:
    goto v_53;
v_55:
    v_76 = nil;
    goto v_53;
    v_76 = nil;
v_53:
    return onevalue(v_76);
}



// Code for sub2chk

static LispObject CC_sub2chk(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_39, v_40, v_41;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_41 = v_2;
// end of prologue
    v_39 = qvalue(elt(env, 1)); // subfg!*
    if (v_39 == nil) goto v_7;
    goto v_16;
v_12:
    v_40 = v_41;
    goto v_13;
v_14:
    v_39 = qvalue(elt(env, 2)); // powlis!*
    goto v_15;
v_16:
    goto v_12;
v_13:
    goto v_14;
v_15:
    v_39 = Latsoc(nil, v_40, v_39);
    if (v_39 == nil) goto v_11;
    else goto v_10;
v_11:
    v_39 = v_41;
    if (!consp(v_39)) goto v_24;
    goto v_30;
v_26:
    v_39 = v_41;
    v_40 = qcar(v_39);
    goto v_27;
v_28:
    v_39 = elt(env, 3); // (expt sqrt)
    goto v_29;
v_30:
    goto v_26;
v_27:
    goto v_28;
v_29:
    v_39 = Lmemq(nil, v_40, v_39);
    goto v_22;
v_24:
    v_39 = nil;
    goto v_22;
    v_39 = nil;
v_22:
    if (v_39 == nil) goto v_20;
    else goto v_10;
v_20:
    goto v_7;
v_10:
    v_39 = lisp_true;
    qvalue(elt(env, 4)) = v_39; // !*sub2
    goto v_5;
v_7:
    v_39 = nil;
v_5:
    return onevalue(v_39);
}



// Code for butes

static LispObject CC_butes(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_51, v_52, v_53, v_54;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_54 = v_2;
// end of prologue
    v_51 = v_54;
    v_51 = qcar(v_51);
    v_53 = v_51;
    goto v_22;
v_18:
    v_52 = v_53;
    goto v_19;
v_20:
    v_51 = elt(env, 2); // ! 
    goto v_21;
v_22:
    goto v_18;
v_19:
    goto v_20;
v_21:
    if (v_52 == v_51) goto v_16;
    else goto v_17;
v_16:
    v_51 = lisp_true;
    goto v_15;
v_17:
    goto v_32;
v_28:
    v_52 = v_53;
    goto v_29;
v_30:
    v_51 = elt(env, 3); // !$
    goto v_31;
v_32:
    goto v_28;
v_29:
    goto v_30;
v_31:
    v_51 = (v_52 == v_51 ? lisp_true : nil);
    goto v_15;
    v_51 = nil;
v_15:
    if (v_51 == nil) goto v_13;
    v_51 = nil;
    goto v_11;
v_13:
    goto v_45;
v_41:
    v_51 = v_54;
    stack[0] = qcar(v_51);
    goto v_42;
v_43:
    v_51 = v_54;
    v_51 = qcdr(v_51);
    v_51 = CC_butes(elt(env, 0), v_51);
    goto v_44;
v_45:
    goto v_41;
v_42:
    goto v_43;
v_44:
    {
        LispObject v_56 = stack[0];
        return cons(v_56, v_51);
    }
    v_51 = nil;
v_11:
    return onevalue(v_51);
}



// Code for noncomp

static LispObject CC_noncomp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_14, v_15;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15 = v_2;
// end of prologue
    v_14 = qvalue(elt(env, 1)); // !*ncmp
    if (v_14 == nil) goto v_6;
    else goto v_7;
v_6:
    v_14 = nil;
    goto v_5;
v_7:
    v_14 = v_15;
    {
        fn = elt(env, 2); // noncomp1
        return (*qfn1(fn))(fn, v_14);
    }
    v_14 = nil;
v_5:
    return onevalue(v_14);
}



// Code for prepf1a

static LispObject CC_prepf1a(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_17, v_18, v_19;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
// copy arguments values to proper place
    v_17 = v_3;
    v_18 = v_2;
// end of prologue
    goto v_13;
v_7:
    v_19 = v_18;
    goto v_8;
v_9:
    v_18 = v_17;
    goto v_10;
v_11:
    v_17 = nil;
    goto v_12;
v_13:
    goto v_7;
v_8:
    goto v_9;
v_10:
    goto v_11;
v_12:
    fn = elt(env, 1); // prepf1a_reversed
    v_17 = (*qfnn(fn))(fn, 3, v_19, v_18, v_17);
        return Lnreverse(nil, v_17);
}



// Code for expchk

static LispObject CC_expchk(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_14, v_15;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15 = v_2;
// end of prologue
    v_14 = qvalue(elt(env, 1)); // !*exp
    if (v_14 == nil) goto v_7;
    v_14 = v_15;
    goto v_5;
v_7:
    v_14 = v_15;
    {
        fn = elt(env, 2); // offexpchk
        return (*qfn1(fn))(fn, v_14);
    }
    v_14 = nil;
v_5:
    return onevalue(v_14);
}



// Code for pm!:free

static LispObject CC_pmTfree(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_13, v_14;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_13 = v_2;
// end of prologue
    goto v_8;
v_4:
    fn = elt(env, 2); // binding
    v_13 = (*qfn1(fn))(fn, v_13);
    env = stack[0];
    goto v_5;
v_6:
    v_14 = elt(env, 1); // unbound
    goto v_7;
v_8:
    goto v_4;
v_5:
    goto v_6;
v_7:
    v_13 = (v_13 == v_14 ? lisp_true : nil);
    return onevalue(v_13);
}



// Code for evlexcomp

static LispObject CC_evlexcomp(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_49, v_50;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
v_7:
    v_49 = stack[-1];
    if (v_49 == nil) goto v_10;
    else goto v_11;
v_10:
    v_49 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6;
v_11:
    v_49 = stack[0];
    if (v_49 == nil) goto v_14;
    else goto v_15;
v_14:
    v_49 = elt(env, 1); // (0)
    stack[0] = v_49;
    goto v_7;
v_15:
    goto v_25;
v_21:
    v_49 = stack[-1];
    v_50 = qcar(v_49);
    goto v_22;
v_23:
    v_49 = stack[0];
    v_49 = qcar(v_49);
    goto v_24;
v_25:
    goto v_21;
v_22:
    goto v_23;
v_24:
    fn = elt(env, 2); // iequal
    v_49 = (*qfn2(fn))(fn, v_50, v_49);
    env = stack[-2];
    if (v_49 == nil) goto v_19;
    v_49 = stack[-1];
    v_49 = qcdr(v_49);
    stack[-1] = v_49;
    v_49 = stack[0];
    v_49 = qcdr(v_49);
    stack[0] = v_49;
    goto v_7;
v_19:
    goto v_40;
v_36:
    v_49 = stack[-1];
    v_50 = qcar(v_49);
    goto v_37;
v_38:
    v_49 = stack[0];
    v_49 = qcar(v_49);
    goto v_39;
v_40:
    goto v_36;
v_37:
    goto v_38;
v_39:
    if (((intptr_t)(v_50)) > ((intptr_t)(v_49))) goto v_34;
    else goto v_35;
v_34:
    v_49 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6;
v_35:
    v_49 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_6;
    v_49 = nil;
v_6:
    return onevalue(v_49);
}



// Code for sc_getmat

static LispObject CC_sc_getmat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23, v_24;
    LispObject v_4, v_3, v_2;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sc_getmat");
    va_start(aa, nargs);
    v_2 = va_arg(aa, LispObject);
    v_3 = va_arg(aa, LispObject);
    v_4 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_4,v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_2,v_3,v_4);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_4;
    v_23 = v_3;
    v_24 = v_2;
// end of prologue
    goto v_10;
v_6:
    goto v_15;
v_11:
    stack[-1] = v_24;
    goto v_12;
v_13:
    v_23 = sub1(v_23);
    env = stack[-2];
    goto v_14;
v_15:
    goto v_11;
v_12:
    goto v_13;
v_14:
    stack[-1] = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_23-TAG_FIXNUM)/(16/CELL)));
    goto v_7;
v_8:
    v_23 = stack[0];
    v_23 = sub1(v_23);
    goto v_9;
v_10:
    goto v_6;
v_7:
    goto v_8;
v_9:
    v_23 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_23-TAG_FIXNUM)/(16/CELL)));
    return onevalue(v_23);
}



// Code for round!*

static LispObject CC_roundH(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_15, v_16;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15 = v_2;
// end of prologue
    v_16 = v_15;
    v_16 = qcdr(v_16);
    if (!consp(v_16)) goto v_6;
    else goto v_7;
v_6:
    v_15 = qcdr(v_15);
    goto v_5;
v_7:
    goto v_5;
    v_15 = nil;
v_5:
    return onevalue(v_15);
}



// Code for !*physopp

static LispObject CC_Hphysopp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_33, v_34;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33 = v_2;
// end of prologue
    v_34 = v_33;
    if (!consp(v_34)) goto v_6;
    else goto v_7;
v_6:
    v_34 = v_33;
    if (symbolp(v_34)) goto v_12;
    v_33 = nil;
    goto v_10;
v_12:
    if (!symbolp(v_33)) v_33 = nil;
    else { v_33 = qfastgets(v_33);
           if (v_33 != nil) { v_33 = elt(v_33, 18); // phystype
#ifdef RECORD_GET
             if (v_33 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v_33 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v_33 == SPID_NOPROP) v_33 = nil; }}
#endif
    goto v_10;
    v_33 = nil;
v_10:
    goto v_5;
v_7:
    v_34 = v_33;
    v_34 = qcar(v_34);
    if (symbolp(v_34)) goto v_24;
    v_33 = nil;
    goto v_22;
v_24:
    v_33 = qcar(v_33);
    if (!symbolp(v_33)) v_33 = nil;
    else { v_33 = qfastgets(v_33);
           if (v_33 != nil) { v_33 = elt(v_33, 18); // phystype
#ifdef RECORD_GET
             if (v_33 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v_33 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v_33 == SPID_NOPROP) v_33 = nil; }}
#endif
    goto v_22;
    v_33 = nil;
v_22:
    goto v_5;
    v_33 = nil;
v_5:
    return onevalue(v_33);
}



// Code for getrtypecar

static LispObject CC_getrtypecar(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_7;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7 = v_2;
// end of prologue
    v_7 = qcar(v_7);
    {
        fn = elt(env, 1); // getrtype
        return (*qfn1(fn))(fn, v_7);
    }
}



// Code for mo_divides!?

static LispObject CC_mo_dividesW(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_15, v_16;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15 = v_3;
    v_16 = v_2;
// end of prologue
    goto v_10;
v_6:
    v_16 = qcar(v_16);
    goto v_7;
v_8:
    v_15 = qcar(v_15);
    goto v_9;
v_10:
    goto v_6;
v_7:
    goto v_8;
v_9:
    {
        fn = elt(env, 1); // mo!=modiv1
        return (*qfn2(fn))(fn, v_16, v_15);
    }
}



// Code for dlesslex

static LispObject CC_dlesslex(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_44, v_45, v_46, v_47;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_45 = v_3;
    v_46 = v_2;
// end of prologue
v_7:
    v_44 = v_46;
    if (v_44 == nil) goto v_10;
    else goto v_11;
v_10:
    v_44 = nil;
    goto v_6;
v_11:
    goto v_20;
v_16:
    v_44 = v_46;
    v_47 = qcar(v_44);
    goto v_17;
v_18:
    v_44 = v_45;
    v_44 = qcar(v_44);
    goto v_19;
v_20:
    goto v_16;
v_17:
    goto v_18;
v_19:
    if (((intptr_t)(v_47)) > ((intptr_t)(v_44))) goto v_14;
    else goto v_15;
v_14:
    v_44 = nil;
    goto v_6;
v_15:
    goto v_32;
v_28:
    v_44 = v_46;
    v_47 = qcar(v_44);
    goto v_29;
v_30:
    v_44 = v_45;
    v_44 = qcar(v_44);
    goto v_31;
v_32:
    goto v_28;
v_29:
    goto v_30;
v_31:
    if (((intptr_t)(v_47)) < ((intptr_t)(v_44))) goto v_26;
    else goto v_27;
v_26:
    v_44 = lisp_true;
    goto v_6;
v_27:
    v_44 = v_46;
    v_44 = qcdr(v_44);
    v_46 = v_44;
    v_44 = v_45;
    v_44 = qcdr(v_44);
    v_45 = v_44;
    goto v_7;
    v_44 = nil;
v_6:
    return onevalue(v_44);
}



// Code for hasonevector

static LispObject CC_hasonevector(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_21;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
v_1:
    v_21 = stack[0];
    if (v_21 == nil) goto v_6;
    else goto v_7;
v_6:
    v_21 = nil;
    goto v_5;
v_7:
    v_21 = stack[0];
    v_21 = qcar(v_21);
    fn = elt(env, 1); // vecp
    v_21 = (*qfn1(fn))(fn, v_21);
    env = stack[-1];
    if (v_21 == nil) goto v_14;
    else goto v_13;
v_14:
    v_21 = stack[0];
    v_21 = qcdr(v_21);
    stack[0] = v_21;
    goto v_1;
v_13:
    goto v_5;
    v_21 = nil;
v_5:
    return onevalue(v_21);
}



// Code for reduce_pv0

static LispObject CC_reduce_pv0(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_153, v_154;
    LispObject fn;
    LispObject v_4, v_3, v_2;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "reduce_pv0");
    va_start(aa, nargs);
    v_2 = va_arg(aa, LispObject);
    v_3 = va_arg(aa, LispObject);
    v_4 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_4,v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_2,v_3,v_4);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_4;
    stack[-4] = v_3;
    stack[0] = v_2;
// end of prologue
    v_153 = stack[-4];
    if (v_153 == nil) goto v_8;
    else goto v_9;
v_8:
    v_153 = stack[0];
    goto v_7;
v_9:
    v_153 = stack[0];
    if (v_153 == nil) goto v_12;
    else goto v_13;
v_12:
    v_153 = nil;
    goto v_7;
v_13:
    v_153 = stack[0];
    stack[-5] = v_153;
v_26:
    v_153 = stack[-5];
    if (v_153 == nil) goto v_29;
    v_153 = stack[-4];
    if (v_153 == nil) goto v_29;
    goto v_42;
v_38:
    v_153 = stack[-5];
    v_153 = qcar(v_153);
    v_154 = qcdr(v_153);
    goto v_39;
v_40:
    v_153 = stack[-4];
    v_153 = qcar(v_153);
    v_153 = qcdr(v_153);
    goto v_41;
v_42:
    goto v_38;
v_39:
    goto v_40;
v_41:
    v_153 = (LispObject)greaterp2(v_154, v_153);
    v_153 = v_153 ? lisp_true : nil;
    env = stack[-6];
    if (v_153 == nil) goto v_29;
    goto v_30;
v_29:
    goto v_25;
v_30:
    v_153 = stack[-5];
    v_153 = qcdr(v_153);
    stack[-5] = v_153;
    goto v_26;
v_25:
    v_153 = stack[-5];
    if (v_153 == nil) goto v_55;
    v_153 = stack[-4];
    if (v_153 == nil) goto v_55;
    goto v_66;
v_62:
    v_153 = stack[-4];
    v_153 = qcar(v_153);
    v_154 = qcdr(v_153);
    goto v_63;
v_64:
    v_153 = stack[-5];
    v_153 = qcar(v_153);
    v_153 = qcdr(v_153);
    goto v_65;
v_66:
    goto v_62;
v_63:
    goto v_64;
v_65:
    if (equal(v_154, v_153)) goto v_61;
    else goto v_55;
v_61:
    goto v_78;
v_74:
    v_153 = stack[-5];
    v_153 = qcar(v_153);
    v_154 = qcar(v_153);
    goto v_75;
v_76:
    v_153 = stack[-4];
    v_153 = qcar(v_153);
    v_153 = qcar(v_153);
    goto v_77;
v_78:
    goto v_74;
v_75:
    goto v_76;
v_77:
    fn = elt(env, 3); // lcm
    v_153 = (*qfn2(fn))(fn, v_154, v_153);
    env = stack[-6];
    stack[-2] = v_153;
    goto v_90;
v_86:
    goto v_96;
v_92:
    goto v_93;
v_94:
    goto v_103;
v_99:
    v_154 = stack[-2];
    goto v_100;
v_101:
    v_153 = stack[-5];
    v_153 = qcar(v_153);
    v_153 = qcar(v_153);
    goto v_102;
v_103:
    goto v_99;
v_100:
    goto v_101;
v_102:
    v_153 = quot2(v_154, v_153);
    env = stack[-6];
    goto v_95;
v_96:
    goto v_92;
v_93:
    goto v_94;
v_95:
    fn = elt(env, 4); // pv_multc
    stack[-1] = (*qfn2(fn))(fn, stack[0], v_153);
    env = stack[-6];
    goto v_87;
v_88:
    goto v_113;
v_109:
    stack[0] = stack[-4];
    goto v_110;
v_111:
    goto v_121;
v_117:
    v_154 = stack[-2];
    goto v_118;
v_119:
    v_153 = stack[-4];
    v_153 = qcar(v_153);
    v_153 = qcar(v_153);
    goto v_120;
v_121:
    goto v_117;
v_118:
    goto v_119;
v_120:
    v_153 = quot2(v_154, v_153);
    env = stack[-6];
    v_153 = negate(v_153);
    env = stack[-6];
    goto v_112;
v_113:
    goto v_109;
v_110:
    goto v_111;
v_112:
    fn = elt(env, 4); // pv_multc
    v_153 = (*qfn2(fn))(fn, stack[0], v_153);
    env = stack[-6];
    goto v_89;
v_90:
    goto v_86;
v_87:
    goto v_88;
v_89:
    fn = elt(env, 5); // pv_add
    v_153 = (*qfn2(fn))(fn, stack[-1], v_153);
    env = stack[-6];
    stack[0] = v_153;
    v_153 = stack[-3];
    if (v_153 == nil) goto v_128;
    else goto v_129;
v_128:
    goto v_136;
v_132:
    stack[-1] = qvalue(elt(env, 2)); // pv_den
    goto v_133;
v_134:
    goto v_143;
v_139:
    v_154 = stack[-2];
    goto v_140;
v_141:
    v_153 = stack[-5];
    v_153 = qcar(v_153);
    v_153 = qcar(v_153);
    goto v_142;
v_143:
    goto v_139;
v_140:
    goto v_141;
v_142:
    v_153 = quot2(v_154, v_153);
    env = stack[-6];
    goto v_135;
v_136:
    goto v_132;
v_133:
    goto v_134;
v_135:
    v_153 = times2(stack[-1], v_153);
    env = stack[-6];
    qvalue(elt(env, 2)) = v_153; // pv_den
    goto v_127;
v_129:
    v_153 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 2)) = v_153; // pv_den
    goto v_127;
v_127:
    goto v_53;
v_55:
v_53:
    v_153 = stack[0];
    goto v_7;
    v_153 = nil;
v_7:
    return onevalue(v_153);
}



// Code for noncomlistp

static LispObject CC_noncomlistp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_22;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
v_1:
    v_22 = stack[0];
    v_22 = Lconsp(nil, v_22);
    env = stack[-1];
    if (v_22 == nil) goto v_6;
    else goto v_7;
v_6:
    v_22 = nil;
    goto v_5;
v_7:
    v_22 = stack[0];
    v_22 = qcar(v_22);
    fn = elt(env, 1); // noncomp1
    v_22 = (*qfn1(fn))(fn, v_22);
    env = stack[-1];
    if (v_22 == nil) goto v_15;
    else goto v_14;
v_15:
    v_22 = stack[0];
    v_22 = qcdr(v_22);
    stack[0] = v_22;
    goto v_1;
v_14:
    goto v_5;
    v_22 = nil;
v_5:
    return onevalue(v_22);
}



// Code for remainder!-in!-vector

static LispObject CC_remainderKinKvector(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_201, v_202, v_203, v_204, v_205, v_206, v_207, v_208, v_209, v_210;
    LispObject fn;
    LispObject v_5, v_4, v_3, v_2;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "remainder-in-vector");
    va_start(aa, nargs);
    v_2 = va_arg(aa, LispObject);
    v_3 = va_arg(aa, LispObject);
    v_4 = va_arg(aa, LispObject);
    v_5 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_5,v_4,v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_2,v_3,v_4,v_5);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_5;
    stack[-1] = v_4;
    stack[-2] = v_3;
    stack[-3] = v_2;
// end of prologue
    goto v_22;
v_18:
    v_202 = stack[0];
    goto v_19;
v_20:
    v_201 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21;
v_22:
    goto v_18;
v_19:
    goto v_20;
v_21:
    if (v_202 == v_201) goto v_16;
    else goto v_17;
v_16:
    v_201 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_12;
v_17:
    goto v_32;
v_28:
    v_202 = stack[0];
    goto v_29;
v_30:
    v_201 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_31;
v_32:
    goto v_28;
v_29:
    goto v_30;
v_31:
    if (v_202 == v_201) goto v_26;
    else goto v_27;
v_26:
    v_201 = elt(env, 2); // "Attempt to divide by zero"
    fn = elt(env, 3); // errorf
    v_201 = (*qfn1(fn))(fn, v_201);
    env = stack[-4];
    goto v_15;
v_27:
v_15:
    goto v_42;
v_38:
    v_202 = stack[-1];
    goto v_39;
v_40:
    v_201 = stack[0];
    goto v_41;
v_42:
    goto v_38;
v_39:
    goto v_40;
v_41:
    v_201 = *(LispObject *)((char *)v_202 + (CELL-TAG_VECTOR) + (((intptr_t)v_201-TAG_FIXNUM)/(16/CELL)));
    v_201 = Lmodular_reciprocal(nil, v_201);
    env = stack[-4];
    {   intptr_t w = int_of_fixnum(v_201);
        if (w != 0) w = current_modulus - w;
        v_201 = fixnum_of_int(w);
    }
    v_208 = v_201;
    v_201 = stack[0];
    v_201 = (LispObject)((intptr_t)(v_201) - 0x10);
    v_209 = v_201;
v_51:
    goto v_60;
v_56:
    goto v_65;
v_61:
    v_202 = stack[-2];
    goto v_62;
v_63:
    v_201 = stack[0];
    goto v_64;
v_65:
    goto v_61;
v_62:
    goto v_63;
v_64:
    v_202 = (LispObject)(intptr_t)((intptr_t)v_202 - (intptr_t)v_201 + TAG_FIXNUM);
    v_210 = v_202;
    goto v_57;
v_58:
    v_201 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_59;
v_60:
    goto v_56;
v_57:
    goto v_58;
v_59:
    if (((intptr_t)(v_202)) < ((intptr_t)(v_201))) goto v_54;
    else goto v_55;
v_54:
    goto v_50;
v_55:
    goto v_76;
v_72:
    v_203 = v_208;
    goto v_73;
v_74:
    goto v_82;
v_78:
    v_202 = stack[-3];
    goto v_79;
v_80:
    v_201 = stack[-2];
    goto v_81;
v_82:
    goto v_78;
v_79:
    goto v_80;
v_81:
    v_201 = *(LispObject *)((char *)v_202 + (CELL-TAG_VECTOR) + (((intptr_t)v_201-TAG_FIXNUM)/(16/CELL)));
    goto v_75;
v_76:
    goto v_72;
v_73:
    goto v_74;
v_75:
    v_201 = Lmodular_times(nil, v_203, v_201);
    env = stack[-4];
    v_207 = v_201;
    v_201 = (LispObject)0+TAG_FIXNUM; // 0
    v_206 = v_201;
v_89:
    goto v_99;
v_95:
    v_202 = v_209;
    goto v_96;
v_97:
    v_201 = v_206;
    goto v_98;
v_99:
    goto v_95;
v_96:
    goto v_97;
v_98:
    v_201 = (LispObject)(intptr_t)((intptr_t)v_202 - (intptr_t)v_201 + TAG_FIXNUM);
    v_201 = ((intptr_t)(v_201) < 0 ? lisp_true : nil);
    if (v_201 == nil) goto v_94;
    goto v_88;
v_94:
    goto v_111;
v_105:
    v_205 = stack[-3];
    goto v_106;
v_107:
    goto v_117;
v_113:
    v_202 = v_206;
    goto v_114;
v_115:
    v_201 = v_210;
    goto v_116;
v_117:
    goto v_113;
v_114:
    goto v_115;
v_116:
    v_204 = (LispObject)(intptr_t)((intptr_t)v_202 + (intptr_t)v_201 - TAG_FIXNUM);
    goto v_108;
v_109:
    goto v_125;
v_121:
    goto v_130;
v_126:
    v_203 = stack[-3];
    goto v_127;
v_128:
    goto v_136;
v_132:
    v_202 = v_206;
    goto v_133;
v_134:
    v_201 = v_210;
    goto v_135;
v_136:
    goto v_132;
v_133:
    goto v_134;
v_135:
    v_201 = (LispObject)(intptr_t)((intptr_t)v_202 + (intptr_t)v_201 - TAG_FIXNUM);
    goto v_129;
v_130:
    goto v_126;
v_127:
    goto v_128;
v_129:
    v_203 = *(LispObject *)((char *)v_203 + (CELL-TAG_VECTOR) + (((intptr_t)v_201-TAG_FIXNUM)/(16/CELL)));
    goto v_122;
v_123:
    goto v_146;
v_142:
    goto v_151;
v_147:
    v_202 = stack[-1];
    goto v_148;
v_149:
    v_201 = v_206;
    goto v_150;
v_151:
    goto v_147;
v_148:
    goto v_149;
v_150:
    v_202 = *(LispObject *)((char *)v_202 + (CELL-TAG_VECTOR) + (((intptr_t)v_201-TAG_FIXNUM)/(16/CELL)));
    goto v_143;
v_144:
    v_201 = v_207;
    goto v_145;
v_146:
    goto v_142;
v_143:
    goto v_144;
v_145:
    v_201 = Lmodular_times(nil, v_202, v_201);
    env = stack[-4];
    goto v_124;
v_125:
    goto v_121;
v_122:
    goto v_123;
v_124:
    {   intptr_t w = int_of_fixnum(v_203) + int_of_fixnum(v_201);
        if (w >= current_modulus) w -= current_modulus;
        v_201 = fixnum_of_int(w);
    }
    goto v_110;
v_111:
    goto v_105;
v_106:
    goto v_107;
v_108:
    goto v_109;
v_110:
    *(LispObject *)((char *)v_205 + (CELL-TAG_VECTOR) + (((intptr_t)v_204-TAG_FIXNUM)/(16/CELL))) = v_201;
    v_201 = v_206;
    v_201 = (LispObject)((intptr_t)(v_201) + 0x10);
    v_206 = v_201;
    goto v_89;
v_88:
    v_201 = stack[-2];
    v_201 = (LispObject)((intptr_t)(v_201) - 0x10);
    stack[-2] = v_201;
v_163:
    goto v_176;
v_172:
    v_202 = stack[-2];
    goto v_173;
v_174:
    v_201 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_175;
v_176:
    goto v_172;
v_173:
    goto v_174;
v_175:
    if (((intptr_t)(v_202)) < ((intptr_t)(v_201))) goto v_171;
    goto v_183;
v_179:
    goto v_188;
v_184:
    v_202 = stack[-3];
    goto v_185;
v_186:
    v_201 = stack[-2];
    goto v_187;
v_188:
    goto v_184;
v_185:
    goto v_186;
v_187:
    v_202 = *(LispObject *)((char *)v_202 + (CELL-TAG_VECTOR) + (((intptr_t)v_201-TAG_FIXNUM)/(16/CELL)));
    goto v_180;
v_181:
    v_201 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_182;
v_183:
    goto v_179;
v_180:
    goto v_181;
v_182:
    v_201 = (v_202 == v_201 ? lisp_true : nil);
    goto v_169;
v_171:
    v_201 = nil;
    goto v_169;
    v_201 = nil;
v_169:
    if (v_201 == nil) goto v_166;
    else goto v_167;
v_166:
    goto v_162;
v_167:
    v_201 = stack[-2];
    v_201 = (LispObject)((intptr_t)(v_201) - 0x10);
    stack[-2] = v_201;
    goto v_163;
v_162:
    goto v_51;
v_50:
    v_201 = stack[-2];
v_12:
    return onevalue(v_201);
}



// Code for smemql

static LispObject CC_smemql(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_42, v_43;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    stack[-2] = nil;
v_8:
    v_42 = stack[-1];
    if (v_42 == nil) goto v_11;
    else goto v_12;
v_11:
    v_42 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_42);
    }
v_12:
    goto v_23;
v_19:
    v_42 = stack[-1];
    v_43 = qcar(v_42);
    goto v_20;
v_21:
    v_42 = stack[0];
    goto v_22;
v_23:
    goto v_19;
v_20:
    goto v_21;
v_22:
    v_42 = Lsmemq(nil, v_43, v_42);
    env = stack[-3];
    if (v_42 == nil) goto v_17;
    goto v_32;
v_28:
    v_42 = stack[-1];
    v_43 = qcar(v_42);
    goto v_29;
v_30:
    v_42 = stack[-2];
    goto v_31;
v_32:
    goto v_28;
v_29:
    goto v_30;
v_31:
    v_42 = cons(v_43, v_42);
    env = stack[-3];
    stack[-2] = v_42;
    v_42 = stack[-1];
    v_42 = qcdr(v_42);
    stack[-1] = v_42;
    goto v_8;
v_17:
    v_42 = stack[-1];
    v_42 = qcdr(v_42);
    stack[-1] = v_42;
    goto v_8;
    v_42 = nil;
    return onevalue(v_42);
}



// Code for getrtypeor

static LispObject CC_getrtypeor(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_21;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
v_1:
    v_21 = stack[0];
    if (v_21 == nil) goto v_6;
    else goto v_7;
v_6:
    v_21 = nil;
    goto v_5;
v_7:
    v_21 = stack[0];
    v_21 = qcar(v_21);
    fn = elt(env, 1); // getrtype
    v_21 = (*qfn1(fn))(fn, v_21);
    env = stack[-1];
    if (v_21 == nil) goto v_14;
    else goto v_13;
v_14:
    v_21 = stack[0];
    v_21 = qcdr(v_21);
    stack[0] = v_21;
    goto v_1;
v_13:
    goto v_5;
    v_21 = nil;
v_5:
    return onevalue(v_21);
}



// Code for multdm

static LispObject CC_multdm(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_68, v_69, v_70;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_69 = v_3;
    v_70 = v_2;
// end of prologue
    v_68 = v_70;
    if (!consp(v_68)) goto v_11;
    else goto v_12;
v_11:
    v_68 = v_69;
    v_68 = (consp(v_68) ? nil : lisp_true);
    goto v_10;
v_12:
    v_68 = nil;
    goto v_10;
    v_68 = nil;
v_10:
    if (v_68 == nil) goto v_8;
    goto v_24;
v_20:
    v_68 = v_70;
    goto v_21;
v_22:
    goto v_23;
v_24:
    goto v_20;
v_21:
    goto v_22;
v_23:
    v_68 = times2(v_68, v_69);
    env = stack[0];
    v_69 = v_68;
    v_68 = qvalue(elt(env, 1)); // dmode!*
    if (v_68 == nil) goto v_34;
    else goto v_35;
v_34:
    v_68 = lisp_true;
    goto v_33;
v_35:
    v_68 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_68)) v_68 = nil;
    else { v_68 = qfastgets(v_68);
           if (v_68 != nil) { v_68 = elt(v_68, 5); // convert
#ifdef RECORD_GET
             if (v_68 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v_68 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v_68 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v_68 == SPID_NOPROP) v_68 = nil; else v_68 = lisp_true; }}
#endif
    v_68 = (v_68 == nil ? lisp_true : nil);
    goto v_33;
    v_68 = nil;
v_33:
    if (v_68 == nil) goto v_31;
    v_68 = v_69;
    goto v_29;
v_31:
    goto v_51;
v_47:
    v_68 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_68)) v_68 = nil;
    else { v_68 = qfastgets(v_68);
           if (v_68 != nil) { v_68 = elt(v_68, 34); // i2d
#ifdef RECORD_GET
             if (v_68 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_68 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_68 == SPID_NOPROP) v_68 = nil; }}
#endif
    goto v_48;
v_49:
    goto v_50;
v_51:
    goto v_47;
v_48:
    goto v_49;
v_50:
        return Lapply1(nil, v_68, v_69);
    v_68 = nil;
v_29:
    goto v_6;
v_8:
    goto v_64;
v_58:
    goto v_59;
v_60:
    goto v_61;
v_62:
    v_68 = elt(env, 2); // times
    goto v_63;
v_64:
    goto v_58;
v_59:
    goto v_60;
v_61:
    goto v_62;
v_63:
    {
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(fn, 3, v_70, v_69, v_68);
    }
    v_68 = nil;
v_6:
    return onevalue(v_68);
}



// Code for lalr_add_lookahead

static LispObject CC_lalr_add_lookahead(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_37, v_38, v_39;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_38 = v_3;
    v_39 = v_2;
// end of prologue
    v_37 = v_39;
    if (v_37 == nil) goto v_8;
    goto v_15;
v_11:
    stack[0] = v_39;
    goto v_12;
v_13:
    goto v_22;
v_18:
    v_37 = v_38;
    goto v_19;
v_20:
    v_38 = v_39;
    v_38 = qcdr(v_38);
    goto v_21;
v_22:
    goto v_18;
v_19:
    goto v_20;
v_21:
    v_37 = cons(v_37, v_38);
    goto v_14;
v_15:
    goto v_11;
v_12:
    goto v_13;
v_14:
    {
        LispObject v_41 = stack[0];
        return Lrplacd(nil, v_41, v_37);
    }
v_8:
    goto v_33;
v_29:
    stack[0] = v_39;
    goto v_30;
v_31:
    v_37 = v_38;
    v_37 = ncons(v_37);
    goto v_32;
v_33:
    goto v_29;
v_30:
    goto v_31;
v_32:
    {
        LispObject v_42 = stack[0];
        return Lrplacd(nil, v_42, v_37);
    }
    v_37 = nil;
    return onevalue(v_37);
}



// Code for addcomment

static LispObject CC_addcomment(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_5;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5 = v_2;
// end of prologue
    qvalue(elt(env, 1)) = v_5; // cursym!*
    return onevalue(v_5);
}



// Code for setkorder

static LispObject CC_setkorder(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_25, v_26, v_27;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_27 = v_2;
// end of prologue
    v_25 = qvalue(elt(env, 2)); // kord!*
    stack[0] = v_25;
    goto v_17;
v_13:
    v_26 = v_27;
    goto v_14;
v_15:
    v_25 = stack[0];
    goto v_16;
v_17:
    goto v_13;
v_14:
    goto v_15;
v_16:
    if (equal(v_26, v_25)) goto v_11;
    else goto v_12;
v_11:
    v_25 = stack[0];
    goto v_6;
v_12:
    v_25 = v_27;
    qvalue(elt(env, 2)) = v_25; // kord!*
    v_25 = nil;
    v_25 = ncons(v_25);
    env = stack[-1];
    qvalue(elt(env, 3)) = v_25; // alglist!*
    v_25 = stack[0];
v_6:
    return onevalue(v_25);
}



// Code for cl_cflip

static LispObject CC_cl_cflip(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_15, v_16;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15 = v_3;
    v_16 = v_2;
// end of prologue
    if (v_15 == nil) goto v_8;
    v_15 = v_16;
    goto v_6;
v_8:
    v_15 = v_16;
    {
        fn = elt(env, 1); // cl_flip
        return (*qfn1(fn))(fn, v_15);
    }
    v_15 = nil;
v_6:
    return onevalue(v_15);
}



// Code for minusf

static LispObject CC_minusf(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_56, v_57;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_56 = v_2;
// end of prologue
v_6:
    v_57 = v_56;
    if (v_57 == nil) goto v_9;
    else goto v_10;
v_9:
    v_56 = nil;
    goto v_5;
v_10:
    v_57 = v_56;
    if (!consp(v_57)) goto v_17;
    else goto v_18;
v_17:
    v_57 = lisp_true;
    goto v_16;
v_18:
    v_57 = v_56;
    v_57 = qcar(v_57);
    v_57 = (consp(v_57) ? nil : lisp_true);
    goto v_16;
    v_57 = nil;
v_16:
    if (v_57 == nil) goto v_14;
    v_57 = v_56;
    if (!consp(v_57)) goto v_28;
    else goto v_29;
v_28:
    goto v_36;
v_32:
    v_57 = v_56;
    goto v_33;
v_34:
    v_56 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35;
v_36:
    goto v_32;
v_33:
    goto v_34;
v_35:
        return Llessp(nil, v_57, v_56);
v_29:
    goto v_46;
v_42:
    v_57 = v_56;
    v_57 = qcar(v_57);
    if (!symbolp(v_57)) v_57 = nil;
    else { v_57 = qfastgets(v_57);
           if (v_57 != nil) { v_57 = elt(v_57, 30); // minusp
#ifdef RECORD_GET
             if (v_57 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v_57 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v_57 == SPID_NOPROP) v_57 = nil; }}
#endif
    goto v_43;
v_44:
    goto v_45;
v_46:
    goto v_42;
v_43:
    goto v_44;
v_45:
        return Lapply1(nil, v_57, v_56);
    goto v_8;
v_14:
    v_56 = qcar(v_56);
    v_56 = qcdr(v_56);
    goto v_6;
v_8:
    v_56 = nil;
v_5:
    return onevalue(v_56);
}



// Code for mtchp1

static LispObject CC_mtchp1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_188, v_189, v_190;
    LispObject fn;
    LispObject v_5, v_4, v_3, v_2;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "mtchp1");
    va_start(aa, nargs);
    v_2 = va_arg(aa, LispObject);
    v_3 = va_arg(aa, LispObject);
    v_4 = va_arg(aa, LispObject);
    v_5 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_5,v_4,v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_2,v_3,v_4,v_5);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_188 = v_5;
    stack[0] = v_4;
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
    goto v_19;
v_15:
    v_189 = stack[-2];
    goto v_16;
v_17:
    v_188 = stack[-1];
    goto v_18;
v_19:
    goto v_15;
v_16:
    goto v_17;
v_18:
    if (equal(v_189, v_188)) goto v_13;
    else goto v_14;
v_13:
    v_188 = nil;
    return ncons(v_188);
v_14:
    goto v_31;
v_27:
    v_188 = stack[-2];
    v_189 = qcar(v_188);
    goto v_28;
v_29:
    v_188 = stack[-1];
    v_188 = qcar(v_188);
    goto v_30;
v_31:
    goto v_27;
v_28:
    goto v_29;
v_30:
    fn = elt(env, 4); // mchk!*
    v_188 = (*qfn2(fn))(fn, v_189, v_188);
    env = stack[-4];
    stack[-3] = v_188;
    if (v_188 == nil) goto v_24;
    else goto v_25;
v_24:
    v_188 = nil;
    goto v_9;
v_25:
    goto v_43;
v_39:
    v_188 = stack[-1];
    v_189 = qcdr(v_188);
    goto v_40;
v_41:
    v_188 = qvalue(elt(env, 2)); // frlis!*
    goto v_42;
v_43:
    goto v_39;
v_40:
    goto v_41;
v_42:
    v_188 = Lmemq(nil, v_189, v_188);
    if (v_188 == nil) goto v_38;
    goto v_60;
v_56:
    v_188 = stack[-2];
    v_189 = qcdr(v_188);
    goto v_57;
v_58:
    v_188 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_59;
v_60:
    goto v_56;
v_57:
    goto v_58;
v_59:
    if (v_189 == v_188) goto v_54;
    else goto v_55;
v_54:
    v_188 = lisp_true;
    goto v_53;
v_55:
    goto v_74;
v_68:
    v_188 = stack[-1];
    v_190 = qcdr(v_188);
    goto v_69;
v_70:
    v_189 = stack[-3];
    goto v_71;
v_72:
    v_188 = stack[-2];
    v_188 = qcdr(v_188);
    goto v_73;
v_74:
    goto v_68;
v_69:
    goto v_70;
v_71:
    goto v_72;
v_73:
    fn = elt(env, 5); // powmtch
    v_188 = (*qfnn(fn))(fn, 3, v_190, v_189, v_188);
    env = stack[-4];
    stack[-3] = v_188;
    v_188 = (v_188 == nil ? lisp_true : nil);
    goto v_53;
    v_188 = nil;
v_53:
    if (v_188 == nil) goto v_51;
    v_188 = nil;
    goto v_9;
v_51:
    goto v_89;
v_85:
    stack[0] = stack[-3];
    goto v_86;
v_87:
    goto v_96;
v_92:
    v_188 = stack[-1];
    v_189 = qcdr(v_188);
    goto v_93;
v_94:
    v_188 = stack[-2];
    v_188 = qcdr(v_188);
    goto v_95;
v_96:
    goto v_92;
v_93:
    goto v_94;
v_95:
    v_188 = cons(v_189, v_188);
    env = stack[-4];
    goto v_88;
v_89:
    goto v_85;
v_86:
    goto v_87;
v_88:
    {
        LispObject v_195 = stack[0];
        fn = elt(env, 6); // mapcons
        return (*qfn2(fn))(fn, v_195, v_188);
    }
    goto v_12;
v_38:
    v_188 = stack[0];
    if (v_188 == nil) goto v_103;
    goto v_111;
v_107:
    v_188 = stack[-2];
    v_189 = qcdr(v_188);
    goto v_108;
v_109:
    v_188 = stack[-1];
    v_188 = qcdr(v_188);
    goto v_110;
v_111:
    goto v_107;
v_108:
    goto v_109;
v_110:
    if (equal(v_189, v_188)) goto v_103;
    goto v_101;
v_103:
    v_188 = stack[-1];
    v_188 = qcdr(v_188);
    if (is_number(v_188)) goto v_120;
    v_188 = lisp_true;
    goto v_118;
v_120:
    v_188 = stack[-2];
    v_188 = qcdr(v_188);
    if (is_number(v_188)) goto v_129;
    v_188 = lisp_true;
    goto v_127;
v_129:
    v_188 = qvalue(elt(env, 3)); // !*mcd
    if (v_188 == nil) goto v_138;
    goto v_145;
v_141:
    v_188 = stack[-2];
    v_189 = qcdr(v_188);
    goto v_142;
v_143:
    v_188 = stack[-1];
    v_188 = qcdr(v_188);
    goto v_144;
v_145:
    goto v_141;
v_142:
    goto v_143;
v_144:
    v_188 = (LispObject)lessp2(v_189, v_188);
    v_188 = v_188 ? lisp_true : nil;
    goto v_136;
v_138:
    goto v_160;
v_156:
    goto v_166;
v_162:
    v_188 = stack[-2];
    v_189 = qcdr(v_188);
    goto v_163;
v_164:
    v_188 = stack[-1];
    v_188 = qcdr(v_188);
    goto v_165;
v_166:
    goto v_162;
v_163:
    goto v_164;
v_165:
    v_189 = times2(v_189, v_188);
    env = stack[-4];
    goto v_157;
v_158:
    v_188 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_159;
v_160:
    goto v_156;
v_157:
    goto v_158;
v_159:
    v_188 = (LispObject)lessp2(v_189, v_188);
    v_188 = v_188 ? lisp_true : nil;
    env = stack[-4];
    if (v_188 == nil) goto v_154;
    else goto v_153;
v_154:
    goto v_177;
v_173:
    v_188 = stack[-2];
    v_188 = qcdr(v_188);
    stack[0] = Labsval(nil, v_188);
    env = stack[-4];
    goto v_174;
v_175:
    v_188 = stack[-1];
    v_188 = qcdr(v_188);
    v_188 = Labsval(nil, v_188);
    env = stack[-4];
    goto v_176;
v_177:
    goto v_173;
v_174:
    goto v_175;
v_176:
    v_188 = (LispObject)lessp2(stack[0], v_188);
    v_188 = v_188 ? lisp_true : nil;
v_153:
    goto v_136;
    v_188 = nil;
v_136:
    goto v_127;
    v_188 = nil;
v_127:
    goto v_118;
    v_188 = nil;
v_118:
    if (v_188 == nil) goto v_116;
    else goto v_101;
v_116:
    goto v_102;
v_101:
    v_188 = nil;
    goto v_9;
v_102:
    v_188 = stack[-3];
    goto v_9;
v_12:
    v_188 = nil;
v_9:
    return onevalue(v_188);
}



// Code for get!+row!+nr

static LispObject CC_getLrowLnr(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_9;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9 = v_2;
// end of prologue
        return Llength(nil, v_9);
    return onevalue(v_9);
}



// Code for rl_negateat

static LispObject CC_rl_negateat(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_13;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_13 = v_2;
// end of prologue
    goto v_9;
v_5:
    stack[0] = qvalue(elt(env, 1)); // rl_negateat!*
    goto v_6;
v_7:
    v_13 = ncons(v_13);
    env = stack[-1];
    goto v_8;
v_9:
    goto v_5;
v_6:
    goto v_7;
v_8:
    {
        LispObject v_15 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_15, v_13);
    }
}



// Code for kernels1

static LispObject CC_kernels1(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_69, v_70, v_71, v_72;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_71 = v_3;
    v_69 = v_2;
// end of prologue
v_1:
    v_70 = v_69;
    if (!consp(v_70)) goto v_11;
    else goto v_12;
v_11:
    v_70 = lisp_true;
    goto v_10;
v_12:
    v_70 = v_69;
    v_70 = qcar(v_70);
    v_70 = (consp(v_70) ? nil : lisp_true);
    goto v_10;
    v_70 = nil;
v_10:
    if (v_70 == nil) goto v_8;
    v_69 = v_71;
    goto v_6;
v_8:
    v_70 = v_69;
    v_70 = qcar(v_70);
    v_70 = qcar(v_70);
    v_70 = qcar(v_70);
    v_72 = v_70;
    goto v_33;
v_29:
    v_70 = v_69;
    v_70 = qcar(v_70);
    stack[-2] = qcdr(v_70);
    goto v_30;
v_31:
    goto v_42;
v_38:
    stack[-1] = qcdr(v_69);
    goto v_39;
v_40:
    goto v_53;
v_49:
    v_70 = v_72;
    goto v_50;
v_51:
    v_69 = v_71;
    goto v_52;
v_53:
    goto v_49;
v_50:
    goto v_51;
v_52:
    v_69 = Lmemq(nil, v_70, v_69);
    if (v_69 == nil) goto v_48;
    v_69 = v_71;
    goto v_46;
v_48:
    goto v_65;
v_61:
    stack[0] = v_71;
    goto v_62;
v_63:
    v_69 = v_72;
    v_69 = ncons(v_69);
    env = stack[-3];
    goto v_64;
v_65:
    goto v_61;
v_62:
    goto v_63;
v_64:
    v_69 = Lappend(nil, stack[0], v_69);
    env = stack[-3];
    goto v_46;
    v_69 = nil;
v_46:
    goto v_41;
v_42:
    goto v_38;
v_39:
    goto v_40;
v_41:
    v_70 = CC_kernels1(elt(env, 0), stack[-1], v_69);
    env = stack[-3];
    goto v_32;
v_33:
    goto v_29;
v_30:
    goto v_31;
v_32:
    v_69 = stack[-2];
    v_71 = v_70;
    goto v_1;
    v_69 = nil;
v_6:
    return onevalue(v_69);
}



// Code for addf

static LispObject CC_addf(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_171, v_172, v_173;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    stack[-2] = nil;
v_9:
    v_171 = stack[-1];
    if (v_171 == nil) goto v_14;
    else goto v_15;
v_14:
    v_171 = stack[0];
    goto v_10;
v_15:
    v_171 = stack[0];
    if (v_171 == nil) goto v_18;
    else goto v_19;
v_18:
    v_171 = stack[-1];
    goto v_10;
v_19:
    v_171 = stack[-1];
    if (!consp(v_171)) goto v_26;
    else goto v_27;
v_26:
    v_171 = lisp_true;
    goto v_25;
v_27:
    v_171 = stack[-1];
    v_171 = qcar(v_171);
    v_171 = (consp(v_171) ? nil : lisp_true);
    goto v_25;
    v_171 = nil;
v_25:
    if (v_171 == nil) goto v_23;
    goto v_40;
v_36:
    v_172 = stack[-1];
    goto v_37;
v_38:
    v_171 = stack[0];
    goto v_39;
v_40:
    goto v_36;
v_37:
    goto v_38;
v_39:
    fn = elt(env, 2); // addd
    v_171 = (*qfn2(fn))(fn, v_172, v_171);
    env = stack[-3];
    goto v_10;
v_23:
    v_171 = stack[0];
    if (!consp(v_171)) goto v_47;
    else goto v_48;
v_47:
    v_171 = lisp_true;
    goto v_46;
v_48:
    v_171 = stack[0];
    v_171 = qcar(v_171);
    v_171 = (consp(v_171) ? nil : lisp_true);
    goto v_46;
    v_171 = nil;
v_46:
    if (v_171 == nil) goto v_44;
    goto v_61;
v_57:
    v_172 = stack[0];
    goto v_58;
v_59:
    v_171 = stack[-1];
    goto v_60;
v_61:
    goto v_57;
v_58:
    goto v_59;
v_60:
    fn = elt(env, 2); // addd
    v_171 = (*qfn2(fn))(fn, v_172, v_171);
    env = stack[-3];
    goto v_10;
v_44:
    goto v_70;
v_66:
    v_171 = stack[-1];
    v_171 = qcar(v_171);
    v_172 = qcar(v_171);
    goto v_67;
v_68:
    v_171 = stack[0];
    v_171 = qcar(v_171);
    v_171 = qcar(v_171);
    goto v_69;
v_70:
    goto v_66;
v_67:
    goto v_68;
v_69:
    if (equal(v_172, v_171)) goto v_64;
    else goto v_65;
v_64:
    goto v_82;
v_78:
    v_171 = stack[-1];
    v_171 = qcar(v_171);
    v_172 = qcdr(v_171);
    goto v_79;
v_80:
    v_171 = stack[0];
    v_171 = qcar(v_171);
    v_171 = qcdr(v_171);
    goto v_81;
v_82:
    goto v_78;
v_79:
    goto v_80;
v_81:
    v_171 = CC_addf(elt(env, 0), v_172, v_171);
    env = stack[-3];
    v_172 = v_171;
    if (v_172 == nil) goto v_92;
    goto v_101;
v_95:
    v_172 = stack[-1];
    v_172 = qcar(v_172);
    v_173 = qcar(v_172);
    goto v_96;
v_97:
    v_172 = v_171;
    goto v_98;
v_99:
    v_171 = stack[-2];
    goto v_100;
v_101:
    goto v_95;
v_96:
    goto v_97;
v_98:
    goto v_99;
v_100:
    v_171 = acons(v_173, v_172, v_171);
    env = stack[-3];
    stack[-2] = v_171;
    goto v_90;
v_92:
v_90:
    v_171 = stack[-1];
    v_171 = qcdr(v_171);
    stack[-1] = v_171;
    v_171 = stack[0];
    v_171 = qcdr(v_171);
    stack[0] = v_171;
    goto v_13;
v_65:
    goto v_118;
v_114:
    v_171 = stack[-1];
    v_171 = qcar(v_171);
    v_172 = qcar(v_171);
    goto v_115;
v_116:
    v_171 = stack[0];
    v_171 = qcar(v_171);
    v_171 = qcar(v_171);
    goto v_117;
v_118:
    goto v_114;
v_115:
    goto v_116;
v_117:
    fn = elt(env, 3); // ordpp
    v_171 = (*qfn2(fn))(fn, v_172, v_171);
    env = stack[-3];
    if (v_171 == nil) goto v_112;
    goto v_130;
v_126:
    v_171 = stack[-1];
    v_172 = qcar(v_171);
    goto v_127;
v_128:
    v_171 = stack[-2];
    goto v_129;
v_130:
    goto v_126;
v_127:
    goto v_128;
v_129:
    v_171 = cons(v_172, v_171);
    env = stack[-3];
    stack[-2] = v_171;
    v_171 = stack[-1];
    v_171 = qcdr(v_171);
    stack[-1] = v_171;
    goto v_13;
v_112:
    goto v_143;
v_139:
    v_171 = stack[0];
    v_172 = qcar(v_171);
    goto v_140;
v_141:
    v_171 = stack[-2];
    goto v_142;
v_143:
    goto v_139;
v_140:
    goto v_141;
v_142:
    v_171 = cons(v_172, v_171);
    env = stack[-3];
    stack[-2] = v_171;
    v_171 = stack[0];
    v_171 = qcdr(v_171);
    stack[0] = v_171;
    goto v_13;
v_13:
    goto v_9;
v_10:
v_151:
    v_172 = stack[-2];
    if (v_172 == nil) goto v_154;
    else goto v_155;
v_154:
    goto v_150;
v_155:
    v_172 = stack[-2];
    v_172 = qcdr(v_172);
    stack[-1] = v_172;
    goto v_165;
v_161:
    v_172 = stack[-2];
    goto v_162;
v_163:
    goto v_164;
v_165:
    goto v_161;
v_162:
    goto v_163;
v_164:
    v_171 = Lrplacd(nil, v_172, v_171);
    env = stack[-3];
    v_171 = stack[-2];
    v_172 = stack[-1];
    stack[-2] = v_172;
    goto v_151;
v_150:
    return onevalue(v_171);
}



// Code for addd

static LispObject CC_addd(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_63, v_64;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_64 = nil;
v_8:
    v_63 = stack[0];
    if (v_63 == nil) goto v_11;
    else goto v_12;
v_11:
    goto v_19;
v_15:
    goto v_16;
v_17:
    v_63 = stack[-1];
    goto v_18;
v_19:
    goto v_15;
v_16:
    goto v_17;
v_18:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_64, v_63);
    }
v_12:
    v_63 = stack[0];
    if (!consp(v_63)) goto v_26;
    else goto v_27;
v_26:
    v_63 = lisp_true;
    goto v_25;
v_27:
    v_63 = stack[0];
    v_63 = qcar(v_63);
    v_63 = (consp(v_63) ? nil : lisp_true);
    goto v_25;
    v_63 = nil;
v_25:
    if (v_63 == nil) goto v_23;
    goto v_40;
v_36:
    stack[-2] = v_64;
    goto v_37;
v_38:
    goto v_47;
v_43:
    v_64 = stack[-1];
    goto v_44;
v_45:
    v_63 = stack[0];
    goto v_46;
v_47:
    goto v_43;
v_44:
    goto v_45;
v_46:
    fn = elt(env, 2); // adddm
    v_63 = (*qfn2(fn))(fn, v_64, v_63);
    env = stack[-3];
    goto v_39;
v_40:
    goto v_36;
v_37:
    goto v_38;
v_39:
    {
        LispObject v_68 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_68, v_63);
    }
v_23:
    goto v_57;
v_53:
    v_63 = stack[0];
    v_63 = qcar(v_63);
    goto v_54;
v_55:
    goto v_56;
v_57:
    goto v_53;
v_54:
    goto v_55;
v_56:
    v_63 = cons(v_63, v_64);
    env = stack[-3];
    v_64 = v_63;
    v_63 = stack[0];
    v_63 = qcdr(v_63);
    stack[0] = v_63;
    goto v_8;
    v_63 = nil;
    return onevalue(v_63);
}



// Code for ldepends

static LispObject CC_ldepends(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_45, v_46;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
v_1:
    v_45 = stack[-1];
    if (v_45 == nil) goto v_7;
    else goto v_8;
v_7:
    v_45 = nil;
    goto v_6;
v_8:
    v_45 = stack[-1];
    if (!consp(v_45)) goto v_11;
    else goto v_12;
v_11:
    goto v_19;
v_15:
    v_46 = stack[-1];
    goto v_16;
v_17:
    v_45 = stack[0];
    goto v_18;
v_19:
    goto v_15;
v_16:
    goto v_17;
v_18:
    {
        fn = elt(env, 1); // depends
        return (*qfn2(fn))(fn, v_46, v_45);
    }
v_12:
    goto v_32;
v_28:
    v_45 = stack[-1];
    v_46 = qcar(v_45);
    goto v_29;
v_30:
    v_45 = stack[0];
    goto v_31;
v_32:
    goto v_28;
v_29:
    goto v_30;
v_31:
    fn = elt(env, 1); // depends
    v_45 = (*qfn2(fn))(fn, v_46, v_45);
    env = stack[-2];
    if (v_45 == nil) goto v_26;
    else goto v_25;
v_26:
    goto v_41;
v_37:
    v_45 = stack[-1];
    v_46 = qcdr(v_45);
    goto v_38;
v_39:
    v_45 = stack[0];
    goto v_40;
v_41:
    goto v_37;
v_38:
    goto v_39;
v_40:
    stack[-1] = v_46;
    stack[0] = v_45;
    goto v_1;
v_25:
    goto v_6;
    v_45 = nil;
v_6:
    return onevalue(v_45);
}



// Code for numlis

static LispObject CC_numlis(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_24, v_25;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24 = v_2;
// end of prologue
v_1:
    v_25 = v_24;
    if (v_25 == nil) goto v_6;
    else goto v_7;
v_6:
    v_24 = lisp_true;
    goto v_5;
v_7:
    v_25 = v_24;
    v_25 = qcar(v_25);
    if (is_number(v_25)) goto v_15;
    v_24 = nil;
    goto v_13;
v_15:
    v_24 = qcdr(v_24);
    goto v_1;
    v_24 = nil;
v_13:
    goto v_5;
    v_24 = nil;
v_5:
    return onevalue(v_24);
}



// Code for dm!-abs

static LispObject CC_dmKabs(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_15;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_15 = stack[0];
    fn = elt(env, 1); // !:minusp
    v_15 = (*qfn1(fn))(fn, v_15);
    env = stack[-1];
    if (v_15 == nil) goto v_7;
    v_15 = stack[0];
    {
        fn = elt(env, 2); // dm!-minus
        return (*qfn1(fn))(fn, v_15);
    }
v_7:
    v_15 = stack[0];
    goto v_5;
    v_15 = nil;
v_5:
    return onevalue(v_15);
}



// Code for binding

static LispObject CC_binding(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_14, v_15;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14 = v_2;
// end of prologue
    if (!symbolp(v_14)) v_14 = nil;
    else { v_14 = qfastgets(v_14);
           if (v_14 != nil) { v_14 = elt(v_14, 13); // binding
#ifdef RECORD_GET
             if (v_14 != SPID_NOPROP)
                record_get(elt(fastget_names, 13), 1);
             else record_get(elt(fastget_names, 13), 0),
                v_14 = nil; }
           else record_get(elt(fastget_names, 13), 0); }
#else
             if (v_14 == SPID_NOPROP) v_14 = nil; }}
#endif
    v_15 = v_14;
    v_14 = v_15;
    if (v_14 == nil) goto v_10;
    v_14 = v_15;
    v_14 = qcar(v_14);
    goto v_8;
v_10:
    v_14 = nil;
v_8:
    return onevalue(v_14);
}



// Code for evzero!?

static LispObject CC_evzeroW(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_30, v_31, v_32;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31 = v_2;
// end of prologue
v_1:
    v_30 = v_31;
    if (v_30 == nil) goto v_6;
    else goto v_7;
v_6:
    v_30 = lisp_true;
    goto v_5;
v_7:
    goto v_20;
v_16:
    v_30 = v_31;
    v_32 = qcar(v_30);
    goto v_17;
v_18:
    v_30 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19;
v_20:
    goto v_16;
v_17:
    goto v_18;
v_19:
    if (v_32 == v_30) goto v_14;
    else goto v_15;
v_14:
    v_30 = v_31;
    v_30 = qcdr(v_30);
    v_31 = v_30;
    goto v_1;
v_15:
    v_30 = nil;
    goto v_13;
    v_30 = nil;
v_13:
    goto v_5;
    v_30 = nil;
v_5:
    return onevalue(v_30);
}



// Code for mkround

static LispObject CC_mkround(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_20, v_21;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21 = v_2;
// end of prologue
    v_20 = v_21;
    if (!consp(v_20)) goto v_6;
    else goto v_7;
v_6:
    goto v_14;
v_10:
    v_20 = elt(env, 1); // !:rd!:
    goto v_11;
v_12:
    goto v_13;
v_14:
    goto v_10;
v_11:
    goto v_12;
v_13:
    return cons(v_20, v_21);
v_7:
    v_20 = v_21;
    goto v_5;
    v_20 = nil;
v_5:
    return onevalue(v_20);
}



// Code for degr

static LispObject CC_degr(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_46, v_47, v_48;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_46 = v_3;
    v_47 = v_2;
// end of prologue
    v_48 = v_47;
    if (!consp(v_48)) goto v_15;
    else goto v_16;
v_15:
    v_48 = lisp_true;
    goto v_14;
v_16:
    v_48 = v_47;
    v_48 = qcar(v_48);
    v_48 = (consp(v_48) ? nil : lisp_true);
    goto v_14;
    v_48 = nil;
v_14:
    if (v_48 == nil) goto v_12;
    v_46 = lisp_true;
    goto v_10;
v_12:
    goto v_31;
v_27:
    v_48 = v_47;
    v_48 = qcar(v_48);
    v_48 = qcar(v_48);
    v_48 = qcar(v_48);
    goto v_28;
v_29:
    goto v_30;
v_31:
    goto v_27;
v_28:
    goto v_29;
v_30:
    v_46 = (v_48 == v_46 ? lisp_true : nil);
    v_46 = (v_46 == nil ? lisp_true : nil);
    goto v_10;
    v_46 = nil;
v_10:
    if (v_46 == nil) goto v_8;
    v_46 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6;
v_8:
    v_46 = v_47;
    v_46 = qcar(v_46);
    v_46 = qcar(v_46);
    v_46 = qcdr(v_46);
    goto v_6;
    v_46 = nil;
v_6:
    return onevalue(v_46);
}



// Code for isanindex

static LispObject CC_isanindex(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_64, v_65, v_66;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_66 = v_2;
// end of prologue
    v_64 = v_66;
    if (symbolp(v_64)) goto v_7;
    v_64 = nil;
    goto v_5;
v_7:
    goto v_19;
v_15:
    v_65 = v_66;
    goto v_16;
v_17:
    v_64 = qvalue(elt(env, 1)); // physopindices!*
    goto v_18;
v_19:
    goto v_15;
v_16:
    goto v_17;
v_18:
    v_64 = Lmemq(nil, v_65, v_64);
    if (v_64 == nil) goto v_14;
    else goto v_13;
v_14:
    goto v_30;
v_26:
    v_65 = v_66;
    goto v_27;
v_28:
    v_64 = qvalue(elt(env, 2)); // physopvarind!*
    goto v_29;
v_30:
    goto v_26;
v_27:
    goto v_28;
v_29:
    v_64 = Lmember(nil, v_65, v_64);
    if (v_64 == nil) goto v_25;
    else goto v_24;
v_25:
    goto v_42;
v_38:
    v_65 = v_66;
    goto v_39;
v_40:
    v_64 = qvalue(elt(env, 3)); // frlis!*
    goto v_41;
v_42:
    goto v_38;
v_39:
    goto v_40;
v_41:
    v_64 = Lmemq(nil, v_65, v_64);
    if (v_64 == nil) goto v_36;
    else goto v_37;
v_36:
    v_64 = nil;
    goto v_35;
v_37:
    goto v_53;
v_49:
    goto v_59;
v_55:
    v_65 = v_66;
    goto v_56;
v_57:
    v_64 = qvalue(elt(env, 4)); // frasc!*
    goto v_58;
v_59:
    goto v_55;
v_56:
    goto v_57;
v_58:
    fn = elt(env, 5); // revassoc
    v_64 = (*qfn2(fn))(fn, v_65, v_64);
    env = stack[0];
    goto v_50;
v_51:
    v_65 = qvalue(elt(env, 1)); // physopindices!*
    goto v_52;
v_53:
    goto v_49;
v_50:
    goto v_51;
v_52:
    v_64 = Lmember(nil, v_64, v_65);
    goto v_35;
    v_64 = nil;
v_35:
v_24:
v_13:
    goto v_5;
    v_64 = nil;
v_5:
    return onevalue(v_64);
}



// Code for union_edge

static LispObject CC_union_edge(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_28, v_29;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    goto v_14;
v_10:
    v_29 = stack[-1];
    goto v_11;
v_12:
    v_28 = stack[0];
    goto v_13;
v_14:
    goto v_10;
v_11:
    goto v_12;
v_13:
    fn = elt(env, 1); // memq_edgelist
    v_28 = (*qfn2(fn))(fn, v_29, v_28);
    if (v_28 == nil) goto v_8;
    v_28 = stack[0];
    goto v_6;
v_8:
    goto v_25;
v_21:
    v_29 = stack[-1];
    goto v_22;
v_23:
    v_28 = stack[0];
    goto v_24;
v_25:
    goto v_21;
v_22:
    goto v_23;
v_24:
    return cons(v_29, v_28);
    v_28 = nil;
v_6:
    return onevalue(v_28);
}



// Code for poly!-multf

static LispObject CC_polyKmultf(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_405, v_406, v_407;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
    stack[-3] = nil;
v_9:
    v_405 = stack[-2];
    if (v_405 == nil) goto v_17;
    else goto v_18;
v_17:
    v_405 = lisp_true;
    goto v_16;
v_18:
    v_405 = stack[-1];
    v_405 = (v_405 == nil ? lisp_true : nil);
    goto v_16;
    v_405 = nil;
v_16:
    if (v_405 == nil) goto v_14;
    v_405 = nil;
    goto v_8;
v_14:
    goto v_32;
v_28:
    v_406 = stack[-2];
    goto v_29;
v_30:
    v_405 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31;
v_32:
    goto v_28;
v_29:
    goto v_30;
v_31:
    if (v_406 == v_405) goto v_26;
    else goto v_27;
v_26:
    v_405 = stack[-1];
    goto v_8;
v_27:
    goto v_42;
v_38:
    v_406 = stack[-1];
    goto v_39;
v_40:
    v_405 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_41;
v_42:
    goto v_38;
v_39:
    goto v_40;
v_41:
    if (v_406 == v_405) goto v_36;
    else goto v_37;
v_36:
    v_405 = stack[-2];
    goto v_8;
v_37:
    v_405 = stack[-2];
    if (!consp(v_405)) goto v_50;
    else goto v_51;
v_50:
    v_405 = lisp_true;
    goto v_49;
v_51:
    v_405 = stack[-2];
    v_405 = qcar(v_405);
    v_405 = (consp(v_405) ? nil : lisp_true);
    goto v_49;
    v_405 = nil;
v_49:
    if (v_405 == nil) goto v_47;
    goto v_64;
v_60:
    v_406 = stack[-2];
    goto v_61;
v_62:
    v_405 = stack[-1];
    goto v_63;
v_64:
    goto v_60;
v_61:
    goto v_62;
v_63:
    {
        fn = elt(env, 9); // multd
        return (*qfn2(fn))(fn, v_406, v_405);
    }
v_47:
    v_405 = stack[-1];
    if (!consp(v_405)) goto v_71;
    else goto v_72;
v_71:
    v_405 = lisp_true;
    goto v_70;
v_72:
    v_405 = stack[-1];
    v_405 = qcar(v_405);
    v_405 = (consp(v_405) ? nil : lisp_true);
    goto v_70;
    v_405 = nil;
v_70:
    if (v_405 == nil) goto v_68;
    goto v_85;
v_81:
    v_406 = stack[-1];
    goto v_82;
v_83:
    v_405 = stack[-2];
    goto v_84;
v_85:
    goto v_81;
v_82:
    goto v_83;
v_84:
    {
        fn = elt(env, 9); // multd
        return (*qfn2(fn))(fn, v_406, v_405);
    }
v_68:
    v_405 = qvalue(elt(env, 2)); // !*exp
    if (v_405 == nil) goto v_90;
    else goto v_89;
v_90:
    v_405 = qvalue(elt(env, 3)); // ncmp!*
    if (v_405 == nil) goto v_93;
    else goto v_89;
v_93:
    v_405 = qvalue(elt(env, 4)); // wtl!*
    if (v_405 == nil) goto v_96;
    else goto v_89;
v_96:
    v_405 = stack[-3];
    if (v_405 == nil) goto v_98;
    else goto v_89;
v_98:
    v_405 = stack[-2];
    fn = elt(env, 10); // mkprod
    v_405 = (*qfn1(fn))(fn, v_405);
    env = stack[-4];
    stack[-2] = v_405;
    v_405 = stack[-1];
    fn = elt(env, 10); // mkprod
    v_405 = (*qfn1(fn))(fn, v_405);
    env = stack[-4];
    stack[-1] = v_405;
    v_405 = lisp_true;
    stack[-3] = v_405;
    goto v_9;
v_89:
    v_405 = stack[-2];
    v_405 = qcar(v_405);
    v_405 = qcar(v_405);
    v_405 = qcar(v_405);
    stack[-3] = v_405;
    v_405 = stack[-1];
    v_405 = qcar(v_405);
    v_405 = qcar(v_405);
    v_405 = qcar(v_405);
    stack[0] = v_405;
    v_405 = stack[-1];
    fn = elt(env, 11); // noncomfp
    v_405 = (*qfn1(fn))(fn, v_405);
    env = stack[-4];
    if (v_405 == nil) goto v_116;
    v_405 = stack[-3];
    fn = elt(env, 12); // noncomp
    v_405 = (*qfn1(fn))(fn, v_405);
    env = stack[-4];
    if (v_405 == nil) goto v_121;
    else goto v_120;
v_121:
    v_405 = qvalue(elt(env, 5)); // !*!*processed
    if (v_405 == nil) goto v_120;
    goto v_116;
v_120:
    goto v_131;
v_127:
    v_406 = stack[-2];
    goto v_128;
v_129:
    v_405 = stack[-1];
    goto v_130;
v_131:
    goto v_127;
v_128:
    goto v_129;
v_130:
    {
        fn = elt(env, 13); // poly!-multfnc
        return (*qfn2(fn))(fn, v_406, v_405);
    }
v_116:
    goto v_140;
v_136:
    v_406 = stack[-3];
    goto v_137;
v_138:
    v_405 = stack[0];
    goto v_139;
v_140:
    goto v_136;
v_137:
    goto v_138;
v_139:
    if (v_406 == v_405) goto v_134;
    else goto v_135;
v_134:
    v_405 = stack[-2];
    v_405 = qcar(v_405);
    v_405 = qcar(v_405);
    v_405 = qcdr(v_405);
    v_405 = integerp(v_405);
    if (v_405 == nil) goto v_149;
    else goto v_150;
v_149:
    v_405 = lisp_true;
    goto v_148;
v_150:
    v_405 = stack[-1];
    v_405 = qcar(v_405);
    v_405 = qcar(v_405);
    v_405 = qcdr(v_405);
    v_405 = integerp(v_405);
    v_405 = (v_405 == nil ? lisp_true : nil);
    goto v_148;
    v_405 = nil;
v_148:
    if (v_405 == nil) goto v_146;
    goto v_170;
v_166:
    stack[0] = stack[-3];
    goto v_167;
v_168:
    goto v_180;
v_174:
    v_407 = elt(env, 6); // plus
    goto v_175;
v_176:
    v_405 = stack[-2];
    v_405 = qcar(v_405);
    v_405 = qcar(v_405);
    v_406 = qcdr(v_405);
    goto v_177;
v_178:
    v_405 = stack[-1];
    v_405 = qcar(v_405);
    v_405 = qcar(v_405);
    v_405 = qcdr(v_405);
    goto v_179;
v_180:
    goto v_174;
v_175:
    goto v_176;
v_177:
    goto v_178;
v_179:
    v_405 = list3(v_407, v_406, v_405);
    env = stack[-4];
    fn = elt(env, 14); // reval
    v_405 = (*qfn1(fn))(fn, v_405);
    env = stack[-4];
    goto v_169;
v_170:
    goto v_166;
v_167:
    goto v_168;
v_169:
    fn = elt(env, 15); // to
    v_405 = (*qfn2(fn))(fn, stack[0], v_405);
    env = stack[-4];
    stack[-3] = v_405;
    goto v_144;
v_146:
    goto v_197;
v_193:
    stack[0] = stack[-3];
    goto v_194;
v_195:
    goto v_204;
v_200:
    v_405 = stack[-2];
    v_405 = qcar(v_405);
    v_405 = qcar(v_405);
    v_406 = qcdr(v_405);
    goto v_201;
v_202:
    v_405 = stack[-1];
    v_405 = qcar(v_405);
    v_405 = qcar(v_405);
    v_405 = qcdr(v_405);
    goto v_203;
v_204:
    goto v_200;
v_201:
    goto v_202;
v_203:
    v_405 = plus2(v_406, v_405);
    env = stack[-4];
    goto v_196;
v_197:
    goto v_193;
v_194:
    goto v_195;
v_196:
    fn = elt(env, 16); // mkspm
    v_405 = (*qfn2(fn))(fn, stack[0], v_405);
    env = stack[-4];
    stack[-3] = v_405;
    goto v_144;
v_144:
    goto v_218;
v_214:
    goto v_224;
v_220:
    v_405 = stack[-2];
    v_406 = qcdr(v_405);
    goto v_221;
v_222:
    v_405 = stack[-1];
    goto v_223;
v_224:
    goto v_220;
v_221:
    goto v_222;
v_223:
    stack[0] = CC_polyKmultf(elt(env, 0), v_406, v_405);
    env = stack[-4];
    goto v_215;
v_216:
    goto v_233;
v_229:
    v_405 = stack[-2];
    v_405 = qcar(v_405);
    v_406 = ncons(v_405);
    env = stack[-4];
    goto v_230;
v_231:
    v_405 = stack[-1];
    v_405 = qcdr(v_405);
    goto v_232;
v_233:
    goto v_229;
v_230:
    goto v_231;
v_232:
    v_405 = CC_polyKmultf(elt(env, 0), v_406, v_405);
    env = stack[-4];
    goto v_217;
v_218:
    goto v_214;
v_215:
    goto v_216;
v_217:
    fn = elt(env, 17); // addf
    v_405 = (*qfn2(fn))(fn, stack[0], v_405);
    env = stack[-4];
    stack[0] = v_405;
    v_405 = stack[-3];
    if (v_405 == nil) goto v_245;
    else goto v_246;
v_245:
    v_405 = lisp_true;
    goto v_244;
v_246:
    goto v_256;
v_252:
    v_405 = stack[-2];
    v_405 = qcar(v_405);
    v_406 = qcdr(v_405);
    goto v_253;
v_254:
    v_405 = stack[-1];
    v_405 = qcar(v_405);
    v_405 = qcdr(v_405);
    goto v_255;
v_256:
    goto v_252;
v_253:
    goto v_254;
v_255:
    v_405 = CC_polyKmultf(elt(env, 0), v_406, v_405);
    env = stack[-4];
    stack[-2] = v_405;
    v_405 = (v_405 == nil ? lisp_true : nil);
    goto v_244;
    v_405 = nil;
v_244:
    if (v_405 == nil) goto v_242;
    v_405 = lisp_true;
    qvalue(elt(env, 7)) = v_405; // !*asymp!*
    v_405 = stack[0];
    goto v_240;
v_242:
    goto v_272;
v_268:
    v_406 = stack[-3];
    goto v_269;
v_270:
    v_405 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_271;
v_272:
    goto v_268;
v_269:
    goto v_270;
v_271:
    if (v_406 == v_405) goto v_266;
    else goto v_267;
v_266:
    goto v_280;
v_276:
    v_406 = stack[-2];
    goto v_277;
v_278:
    v_405 = stack[0];
    goto v_279;
v_280:
    goto v_276;
v_277:
    goto v_278;
v_279:
    {
        fn = elt(env, 17); // addf
        return (*qfn2(fn))(fn, v_406, v_405);
    }
v_267:
    v_405 = qvalue(elt(env, 8)); // !*mcd
    if (v_405 == nil) goto v_283;
    else goto v_284;
v_283:
    goto v_291;
v_287:
    goto v_298;
v_294:
    v_406 = stack[-3];
    goto v_295;
v_296:
    v_405 = stack[-2];
    goto v_297;
v_298:
    goto v_294;
v_295:
    goto v_296;
v_297:
    v_405 = cons(v_406, v_405);
    env = stack[-4];
    v_406 = ncons(v_405);
    env = stack[-4];
    goto v_288;
v_289:
    v_405 = stack[0];
    goto v_290;
v_291:
    goto v_287;
v_288:
    goto v_289;
v_290:
    {
        fn = elt(env, 17); // addf
        return (*qfn2(fn))(fn, v_406, v_405);
    }
v_284:
    goto v_311;
v_305:
    v_407 = stack[-3];
    goto v_306;
v_307:
    v_406 = stack[-2];
    goto v_308;
v_309:
    v_405 = stack[0];
    goto v_310;
v_311:
    goto v_305;
v_306:
    goto v_307;
v_308:
    goto v_309;
v_310:
    return acons(v_407, v_406, v_405);
    v_405 = nil;
v_240:
    goto v_8;
v_135:
    goto v_322;
v_318:
    v_406 = stack[-3];
    goto v_319;
v_320:
    v_405 = stack[0];
    goto v_321;
v_322:
    goto v_318;
v_319:
    goto v_320;
v_321:
    fn = elt(env, 18); // ordop
    v_405 = (*qfn2(fn))(fn, v_406, v_405);
    env = stack[-4];
    if (v_405 == nil) goto v_316;
    goto v_330;
v_326:
    v_405 = stack[-2];
    v_405 = qcar(v_405);
    v_406 = qcdr(v_405);
    goto v_327;
v_328:
    v_405 = stack[-1];
    goto v_329;
v_330:
    goto v_326;
v_327:
    goto v_328;
v_329:
    v_405 = CC_polyKmultf(elt(env, 0), v_406, v_405);
    env = stack[-4];
    stack[-3] = v_405;
    goto v_340;
v_336:
    v_405 = stack[-2];
    v_406 = qcdr(v_405);
    goto v_337;
v_338:
    v_405 = stack[-1];
    goto v_339;
v_340:
    goto v_336;
v_337:
    goto v_338;
v_339:
    v_405 = CC_polyKmultf(elt(env, 0), v_406, v_405);
    stack[0] = v_405;
    v_405 = stack[-3];
    if (v_405 == nil) goto v_346;
    else goto v_347;
v_346:
    v_405 = stack[0];
    goto v_345;
v_347:
    goto v_359;
v_353:
    v_405 = stack[-2];
    v_405 = qcar(v_405);
    v_407 = qcar(v_405);
    goto v_354;
v_355:
    v_406 = stack[-3];
    goto v_356;
v_357:
    v_405 = stack[0];
    goto v_358;
v_359:
    goto v_353;
v_354:
    goto v_355;
v_356:
    goto v_357;
v_358:
    return acons(v_407, v_406, v_405);
    v_405 = nil;
v_345:
    goto v_8;
v_316:
    goto v_370;
v_366:
    v_406 = stack[-2];
    goto v_367;
v_368:
    v_405 = stack[-1];
    v_405 = qcar(v_405);
    v_405 = qcdr(v_405);
    goto v_369;
v_370:
    goto v_366;
v_367:
    goto v_368;
v_369:
    v_405 = CC_polyKmultf(elt(env, 0), v_406, v_405);
    env = stack[-4];
    stack[-3] = v_405;
    goto v_380;
v_376:
    v_406 = stack[-2];
    goto v_377;
v_378:
    v_405 = stack[-1];
    v_405 = qcdr(v_405);
    goto v_379;
v_380:
    goto v_376;
v_377:
    goto v_378;
v_379:
    v_405 = CC_polyKmultf(elt(env, 0), v_406, v_405);
    stack[0] = v_405;
    v_405 = stack[-3];
    if (v_405 == nil) goto v_386;
    else goto v_387;
v_386:
    v_405 = stack[0];
    goto v_385;
v_387:
    goto v_399;
v_393:
    v_405 = stack[-1];
    v_405 = qcar(v_405);
    v_407 = qcar(v_405);
    goto v_394;
v_395:
    v_406 = stack[-3];
    goto v_396;
v_397:
    v_405 = stack[0];
    goto v_398;
v_399:
    goto v_393;
v_394:
    goto v_395;
v_396:
    goto v_397;
v_398:
    return acons(v_407, v_406, v_405);
    v_405 = nil;
v_385:
v_8:
    return onevalue(v_405);
}



// Code for ring_ecart

static LispObject CC_ring_ecart(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_12, v_13;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12 = v_2;
// end of prologue
    goto v_9;
v_5:
    v_13 = v_12;
    goto v_6;
v_7:
    v_12 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_8;
v_9:
    goto v_5;
v_6:
    goto v_7;
v_8:
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(fn, v_13, v_12);
    }
}



// Code for pappl

static LispObject CC_pappl(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
    LispObject v_63, v_64;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_3,v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_3;
    stack[-3] = v_2;
// end of prologue
    stack[-4] = nil;
    v_63 = stack[-3];
    fn = elt(env, 2); // unpkp
    v_63 = (*qfn1(fn))(fn, v_63);
    env = stack[-5];
    stack[-3] = v_63;
v_16:
    v_63 = stack[-3];
    if (v_63 == nil) goto v_19;
    else goto v_20;
v_19:
    goto v_15;
v_20:
    v_63 = stack[-2];
    stack[-1] = v_63;
    v_63 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_63;
v_27:
    goto v_39;
v_35:
    v_63 = stack[-3];
    v_63 = qcar(v_63);
    v_64 = sub1(v_63);
    env = stack[-5];
    goto v_36;
v_37:
    v_63 = stack[0];
    goto v_38;
v_39:
    goto v_35;
v_36:
    goto v_37;
v_38:
    v_63 = difference2(v_64, v_63);
    env = stack[-5];
    v_63 = Lminusp(nil, v_63);
    env = stack[-5];
    if (v_63 == nil) goto v_32;
    goto v_26;
v_32:
    v_63 = stack[-1];
    v_63 = qcdr(v_63);
    stack[-1] = v_63;
    v_63 = stack[0];
    v_63 = add1(v_63);
    env = stack[-5];
    stack[0] = v_63;
    goto v_27;
v_26:
    goto v_54;
v_50:
    v_63 = stack[-1];
    v_64 = qcar(v_63);
    goto v_51;
v_52:
    v_63 = stack[-4];
    goto v_53;
v_54:
    goto v_50;
v_51:
    goto v_52;
v_53:
    v_63 = cons(v_64, v_63);
    env = stack[-5];
    stack[-4] = v_63;
    v_63 = stack[-3];
    v_63 = qcdr(v_63);
    stack[-3] = v_63;
    goto v_16;
v_15:
    v_63 = stack[-4];
        return Lnreverse(nil, v_63);
    return onevalue(v_63);
}



// Code for rnequiv

static LispObject CC_rnequiv(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_22, v_23, v_24;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23 = v_2;
// end of prologue
    goto v_12;
v_8:
    v_22 = v_23;
    v_22 = qcdr(v_22);
    v_23 = v_22;
    v_24 = qcdr(v_22);
    goto v_9;
v_10:
    v_22 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11;
v_12:
    goto v_8;
v_9:
    goto v_10;
v_11:
    if (v_24 == v_22) goto v_6;
    else goto v_7;
v_6:
    v_22 = v_23;
    v_22 = qcar(v_22);
    goto v_5;
v_7:
    v_22 = nil;
    goto v_5;
    v_22 = nil;
v_5:
    return onevalue(v_22);
}



// Code for modonep!:

static LispObject CC_modonepT(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
    LispObject v_13, v_14;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13 = v_2;
// end of prologue
    goto v_8;
v_4:
    v_14 = qcdr(v_13);
    goto v_5;
v_6:
    v_13 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7;
v_8:
    goto v_4;
v_5:
    goto v_6;
v_7:
    v_13 = (v_14 == v_13 ? lisp_true : nil);
    return onevalue(v_13);
}



setup_type const u01_setup[] =
{
    {"terminalp",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_terminalp},
    {"smember",                 TOO_FEW_2,      CC_smember,    WRONG_NO_2},
    {"*n2f",                    CC_Hn2f,        TOO_MANY_1,    WRONG_NO_1},
    {"setdiff",                 TOO_FEW_2,      CC_setdiff,    WRONG_NO_2},
    {"multf",                   TOO_FEW_2,      CC_multf,      WRONG_NO_2},
    {"quotelist",               CC_quotelist,   TOO_MANY_1,    WRONG_NO_1},
    {"num-exponents",           CC_numKexponents,TOO_MANY_1,   WRONG_NO_1},
    {"simpcar",                 CC_simpcar,     TOO_MANY_1,    WRONG_NO_1},
    {"wuconstantp",             CC_wuconstantp, TOO_MANY_1,    WRONG_NO_1},
    {"mkcopy",                  CC_mkcopy,      TOO_MANY_1,    WRONG_NO_1},
    {"mchkopt",                 TOO_FEW_2,      CC_mchkopt,    WRONG_NO_2},
    {"revpr",                   CC_revpr,       TOO_MANY_1,    WRONG_NO_1},
    {"nth",                     TOO_FEW_2,      CC_nth,        WRONG_NO_2},
    {"talp_getl",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_getl},
    {"kernels",                 CC_kernels,     TOO_MANY_1,    WRONG_NO_1},
    {"qqe_rqopp",               CC_qqe_rqopp,   TOO_MANY_1,    WRONG_NO_1},
    {"lto_hashid",              CC_lto_hashid,  TOO_MANY_1,    WRONG_NO_1},
    {"noncomfp",                CC_noncomfp,    TOO_MANY_1,    WRONG_NO_1},
    {"delall",                  TOO_FEW_2,      CC_delall,     WRONG_NO_2},
    {"ordop",                   TOO_FEW_2,      CC_ordop,      WRONG_NO_2},
    {"prepf",                   CC_prepf,       TOO_MANY_1,    WRONG_NO_1},
    {"c:ordxp",                 TOO_FEW_2,      CC_cTordxp,    WRONG_NO_2},
    {"ordad",                   TOO_FEW_2,      CC_ordad,      WRONG_NO_2},
    {"reval",                   CC_reval,       TOO_MANY_1,    WRONG_NO_1},
    {"evcomp",                  TOO_FEW_2,      CC_evcomp,     WRONG_NO_2},
    {"evmatrixcomp2",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_evmatrixcomp2},
    {"xval",                    CC_xval,        TOO_MANY_1,    WRONG_NO_1},
    {"times:",                  TOO_FEW_2,      CC_timesT,     WRONG_NO_2},
    {"convprec",                CC_convprec,    TOO_MANY_1,    WRONG_NO_1},
    {"physopp",                 CC_physopp,     TOO_MANY_1,    WRONG_NO_1},
    {"memq_edgelist",           TOO_FEW_2,      CC_memq_edgelist,WRONG_NO_2},
    {"mo_comp",                 CC_mo_comp,     TOO_MANY_1,    WRONG_NO_1},
    {"c_zero",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_c_zero},
    {"sieve_pv0",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_sieve_pv0},
    {"wideid2list",             CC_wideid2list, TOO_MANY_1,    WRONG_NO_1},
    {"lalr_productions",        CC_lalr_productions,TOO_MANY_1,WRONG_NO_1},
    {"random_new_seed",         CC_random_new_seed,TOO_MANY_1, WRONG_NO_1},
    {"monomgetvariabledegree",  TOO_FEW_2,      CC_monomgetvariabledegree,WRONG_NO_2},
    {"makelist",                CC_makelist,    TOO_MANY_1,    WRONG_NO_1},
    {"mchk*",                   TOO_FEW_2,      CC_mchkH,      WRONG_NO_2},
    {"get+mat+entry",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_getLmatLentry},
    {"talp_getextl",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_getextl},
    {"powers",                  CC_powers,      TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_clmember",          TOO_FEW_2,      CC_ibalp_clmember,WRONG_NO_2},
    {"find2",                   TOO_FEW_2,      CC_find2,      WRONG_NO_2},
    {"exchk",                   CC_exchk,       TOO_MANY_1,    WRONG_NO_1},
    {"zero2nil",                CC_zero2nil,    TOO_MANY_1,    WRONG_NO_1},
    {"mval",                    CC_mval,        TOO_MANY_1,    WRONG_NO_1},
    {"vbcsize",                 TOO_FEW_2,      CC_vbcsize,    WRONG_NO_2},
    {"pnth",                    TOO_FEW_2,      CC_pnth,       WRONG_NO_2},
    {"wedgefax",                CC_wedgefax,    TOO_MANY_1,    WRONG_NO_1},
    {"mkvar",                   TOO_FEW_2,      CC_mkvar,      WRONG_NO_2},
    {"argsofopr",               CC_argsofopr,   TOO_MANY_1,    WRONG_NO_1},
    {"termsf",                  CC_termsf,      TOO_MANY_1,    WRONG_NO_1},
    {"mkspm",                   TOO_FEW_2,      CC_mkspm,      WRONG_NO_2},
    {"dssoc",                   TOO_FEW_2,      CC_dssoc,      WRONG_NO_2},
    {"listp",                   CC_listp,       TOO_MANY_1,    WRONG_NO_1},
    {"rnzerop:",                CC_rnzeropT,    TOO_MANY_1,    WRONG_NO_1},
    {"modzerop:",               CC_modzeropT,   TOO_MANY_1,    WRONG_NO_1},
    {"mksp",                    TOO_FEW_2,      CC_mksp,       WRONG_NO_2},
    {"prin2x",                  CC_prin2x,      TOO_MANY_1,    WRONG_NO_1},
    {"aeval",                   CC_aeval,       TOO_MANY_1,    WRONG_NO_1},
    {"lalr_first",              CC_lalr_first,  TOO_MANY_1,    WRONG_NO_1},
    {"aex_ex",                  CC_aex_ex,      TOO_MANY_1,    WRONG_NO_1},
    {"monomcompare",            TOO_FEW_2,      CC_monomcompare,WRONG_NO_2},
    {"arrayp",                  CC_arrayp,      TOO_MANY_1,    WRONG_NO_1},
    {"quotf",                   TOO_FEW_2,      CC_quotf,      WRONG_NO_2},
    {"subs3f",                  CC_subs3f,      TOO_MANY_1,    WRONG_NO_1},
    {"kernlp",                  CC_kernlp,      TOO_MANY_1,    WRONG_NO_1},
    {"talp_invp",               CC_talp_invp,   TOO_MANY_1,    WRONG_NO_1},
    {"qqe_rbopp",               CC_qqe_rbopp,   TOO_MANY_1,    WRONG_NO_1},
    {"lto_hashequalq",          TOO_FEW_2,      CC_lto_hashequalq,WRONG_NO_2},
    {"sub2chk",                 CC_sub2chk,     TOO_MANY_1,    WRONG_NO_1},
    {"butes",                   CC_butes,       TOO_MANY_1,    WRONG_NO_1},
    {"noncomp",                 CC_noncomp,     TOO_MANY_1,    WRONG_NO_1},
    {"prepf1a",                 TOO_FEW_2,      CC_prepf1a,    WRONG_NO_2},
    {"expchk",                  CC_expchk,      TOO_MANY_1,    WRONG_NO_1},
    {"pm:free",                 CC_pmTfree,     TOO_MANY_1,    WRONG_NO_1},
    {"evlexcomp",               TOO_FEW_2,      CC_evlexcomp,  WRONG_NO_2},
    {"sc_getmat",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_sc_getmat},
    {"round*",                  CC_roundH,      TOO_MANY_1,    WRONG_NO_1},
    {"*physopp",                CC_Hphysopp,    TOO_MANY_1,    WRONG_NO_1},
    {"getrtypecar",             CC_getrtypecar, TOO_MANY_1,    WRONG_NO_1},
    {"mo_divides?",             TOO_FEW_2,      CC_mo_dividesW,WRONG_NO_2},
    {"dlesslex",                TOO_FEW_2,      CC_dlesslex,   WRONG_NO_2},
    {"hasonevector",            CC_hasonevector,TOO_MANY_1,    WRONG_NO_1},
    {"reduce_pv0",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_reduce_pv0},
    {"noncomlistp",             CC_noncomlistp, TOO_MANY_1,    WRONG_NO_1},
    {"remainder-in-vector",     WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_remainderKinKvector},
    {"smemql",                  TOO_FEW_2,      CC_smemql,     WRONG_NO_2},
    {"getrtypeor",              CC_getrtypeor,  TOO_MANY_1,    WRONG_NO_1},
    {"multdm",                  TOO_FEW_2,      CC_multdm,     WRONG_NO_2},
    {"lalr_add_lookahead",      TOO_FEW_2,      CC_lalr_add_lookahead,WRONG_NO_2},
    {"addcomment",              CC_addcomment,  TOO_MANY_1,    WRONG_NO_1},
    {"setkorder",               CC_setkorder,   TOO_MANY_1,    WRONG_NO_1},
    {"cl_cflip",                TOO_FEW_2,      CC_cl_cflip,   WRONG_NO_2},
    {"minusf",                  CC_minusf,      TOO_MANY_1,    WRONG_NO_1},
    {"mtchp1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mtchp1},
    {"get+row+nr",              CC_getLrowLnr,  TOO_MANY_1,    WRONG_NO_1},
    {"rl_negateat",             CC_rl_negateat, TOO_MANY_1,    WRONG_NO_1},
    {"kernels1",                TOO_FEW_2,      CC_kernels1,   WRONG_NO_2},
    {"addf",                    TOO_FEW_2,      CC_addf,       WRONG_NO_2},
    {"addd",                    TOO_FEW_2,      CC_addd,       WRONG_NO_2},
    {"ldepends",                TOO_FEW_2,      CC_ldepends,   WRONG_NO_2},
    {"numlis",                  CC_numlis,      TOO_MANY_1,    WRONG_NO_1},
    {"dm-abs",                  CC_dmKabs,      TOO_MANY_1,    WRONG_NO_1},
    {"binding",                 CC_binding,     TOO_MANY_1,    WRONG_NO_1},
    {"evzero?",                 CC_evzeroW,     TOO_MANY_1,    WRONG_NO_1},
    {"mkround",                 CC_mkround,     TOO_MANY_1,    WRONG_NO_1},
    {"degr",                    TOO_FEW_2,      CC_degr,       WRONG_NO_2},
    {"isanindex",               CC_isanindex,   TOO_MANY_1,    WRONG_NO_1},
    {"union_edge",              TOO_FEW_2,      CC_union_edge, WRONG_NO_2},
    {"poly-multf",              TOO_FEW_2,      CC_polyKmultf, WRONG_NO_2},
    {"ring_ecart",              CC_ring_ecart,  TOO_MANY_1,    WRONG_NO_1},
    {"pappl",                   TOO_FEW_2,      CC_pappl,      WRONG_NO_2},
    {"rnequiv",                 CC_rnequiv,     TOO_MANY_1,    WRONG_NO_1},
    {"modonep:",                CC_modonepT,    TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u01", (two_args *)"106164 8077101 1572621", 0}
};

// end of generated code
