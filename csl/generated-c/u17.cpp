
// $destdir/u17.c        Machine generated C code

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



// Code for omsir

static LispObject CC_omsir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10024, v_10025;
    LispObject fn;
    argcheck(nargs, 0, "omsir");
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
    push(nil);
    stack_popper stack_popper_var(7);
// end of prologue
    stack[-1] = nil;
    v_10024 = nil;
    stack[-2] = v_10024;
    goto v_9866;
v_9862:
    v_10025 = qvalue(elt(env, 1)); // atts
    goto v_9863;
v_9864:
    v_10024 = elt(env, 2); // name
    goto v_9865;
v_9866:
    goto v_9862;
v_9863:
    goto v_9864;
v_9865:
    fn = elt(env, 10); // find
    v_10024 = (*qfn2(fn))(fn, v_10025, v_10024);
    env = stack[-6];
    v_10024 = Lintern(nil, v_10024);
    env = stack[-6];
    stack[-5] = v_10024;
    goto v_9875;
v_9871:
    v_10025 = qvalue(elt(env, 1)); // atts
    goto v_9872;
v_9873:
    v_10024 = elt(env, 3); // cd
    goto v_9874;
v_9875:
    goto v_9871;
v_9872:
    goto v_9873;
v_9874:
    fn = elt(env, 10); // find
    v_10024 = (*qfn2(fn))(fn, v_10025, v_10024);
    env = stack[-6];
    v_10024 = Lintern(nil, v_10024);
    env = stack[-6];
    stack[-3] = v_10024;
    goto v_9886;
v_9882:
    v_10024 = stack[-5];
    v_10025 = Lexplode(nil, v_10024);
    env = stack[-6];
    goto v_9883;
v_9884:
    v_10024 = elt(env, 4); // (v e c t o r)
    goto v_9885;
v_9886:
    goto v_9882;
v_9883:
    goto v_9884;
v_9885:
    if (equal(v_10025, v_10024)) goto v_9880;
    else goto v_9881;
v_9880:
    v_10024 = elt(env, 5); // (vectorml linalg1)
    stack[-4] = v_10024;
    goto v_9879;
v_9881:
    goto v_9897;
v_9893:
    v_10024 = stack[-5];
    v_10025 = Lintern(nil, v_10024);
    env = stack[-6];
    goto v_9894;
v_9895:
    v_10024 = qvalue(elt(env, 6)); // mmleq!*
    goto v_9896;
v_9897:
    goto v_9893;
v_9894:
    goto v_9895;
v_9896:
    v_10024 = Lmember(nil, v_10025, v_10024);
    stack[-4] = v_10024;
    goto v_9879;
v_9879:
    v_10024 = stack[-4];
    if (v_10024 == nil) goto v_9904;
    else goto v_9905;
v_9904:
    goto v_9915;
v_9911:
    v_10025 = stack[-5];
    goto v_9912;
v_9913:
    v_10024 = qvalue(elt(env, 7)); // special_cases!*
    goto v_9914;
v_9915:
    goto v_9911;
v_9912:
    goto v_9913;
v_9914:
    v_10024 = Lassoc(nil, v_10025, v_10024);
    stack[-4] = v_10024;
    if (v_10024 == nil) goto v_9910;
    v_10024 = stack[-4];
    v_10024 = Lreverse(nil, v_10024);
    env = stack[-6];
    v_10024 = qcar(v_10024);
    stack[-2] = v_10024;
    v_10024 = stack[-2];
    if (v_10024 == nil) goto v_9925;
    v_10024 = stack[-2];
    v_10024 = ncons(v_10024);
    env = stack[-6];
    stack[-2] = v_10024;
    goto v_9923;
v_9925:
v_9923:
    goto v_9934;
v_9930:
    v_10024 = stack[-4];
    v_10024 = Lreverse(nil, v_10024);
    env = stack[-6];
    v_10024 = qcdr(v_10024);
    stack[0] = qcar(v_10024);
    goto v_9931;
v_9932:
    v_10024 = stack[-4];
    v_10024 = qcdr(v_10024);
    v_10024 = Lreverse(nil, v_10024);
    env = stack[-6];
    v_10024 = qcdr(v_10024);
    v_10024 = qcdr(v_10024);
    v_10024 = Lreverse(nil, v_10024);
    env = stack[-6];
    goto v_9933;
v_9934:
    goto v_9930;
v_9931:
    goto v_9932;
v_9933:
    v_10024 = cons(stack[0], v_10024);
    env = stack[-6];
    stack[-4] = v_10024;
    goto v_9908;
v_9910:
    goto v_9951;
v_9947:
    v_10025 = stack[-5];
    goto v_9948;
v_9949:
    v_10024 = qvalue(elt(env, 8)); // special_cases2!*
    goto v_9950;
v_9951:
    goto v_9947;
v_9948:
    goto v_9949;
v_9950:
    v_10025 = Lassoc(nil, v_10025, v_10024);
    v_10024 = v_10025;
    if (v_10025 == nil) goto v_9946;
    goto v_9960;
v_9956:
    v_10025 = v_10024;
    v_10025 = qcdr(v_10025);
    v_10025 = qcar(v_10025);
    goto v_9957;
v_9958:
    v_10024 = qcdr(v_10024);
    v_10024 = qcdr(v_10024);
    goto v_9959;
v_9960:
    goto v_9956;
v_9957:
    goto v_9958;
v_9959:
    {
        fn = elt(env, 11); // apply
        return (*qfn2(fn))(fn, v_10025, v_10024);
    }
v_9946:
v_9908:
    goto v_9903;
v_9905:
v_9903:
    v_10024 = stack[-4];
    if (v_10024 == nil) goto v_9971;
    goto v_9977;
v_9973:
    v_10024 = stack[-4];
    v_10025 = qcar(v_10024);
    goto v_9974;
v_9975:
    v_10024 = qvalue(elt(env, 9)); // valid_om!*
    goto v_9976;
v_9977:
    goto v_9973;
v_9974:
    goto v_9975;
v_9976:
    v_10024 = Lassoc(nil, v_10025, v_10024);
    stack[-1] = v_10024;
    goto v_9969;
v_9971:
v_9969:
    v_10024 = stack[-1];
    if (v_10024 == nil) goto v_9985;
    v_10024 = stack[-1];
    v_10024 = qcdr(v_10024);
    v_10024 = qcar(v_10024);
    stack[-1] = v_10024;
    goto v_9983;
v_9985:
v_9983:
    v_10024 = stack[-4];
    if (v_10024 == nil) goto v_9996;
    else goto v_9997;
v_9996:
    v_10024 = lisp_true;
    goto v_9995;
v_9997:
    goto v_10006;
v_10002:
    v_10025 = stack[-3];
    goto v_10003;
v_10004:
    v_10024 = stack[-1];
    v_10024 = (v_10024 == nil ? lisp_true : nil);
    goto v_10005;
v_10006:
    goto v_10002;
v_10003:
    goto v_10004;
v_10005:
    v_10024 = (equal(v_10025, v_10024) ? lisp_true : nil);
    goto v_9995;
    v_10024 = nil;
v_9995:
    if (v_10024 == nil) goto v_9993;
    v_10024 = stack[-5];
    {
        fn = elt(env, 12); // encodeir
        return (*qfn1(fn))(fn, v_10024);
    }
v_9993:
    goto v_10020;
v_10016:
    v_10024 = stack[-4];
    v_10025 = qcar(v_10024);
    goto v_10017;
v_10018:
    v_10024 = stack[-2];
    goto v_10019;
v_10020:
    goto v_10016;
v_10017:
    goto v_10018;
v_10019:
    return list2(v_10025, v_10024);
    return onevalue(v_10024);
}



// Code for evallessp

static LispObject CC_evallessp(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9858, v_9859;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9859 = v_9848;
    v_9858 = v_9847;
// end of prologue
    goto v_9855;
v_9851:
    goto v_9852;
v_9853:
    goto v_9854;
v_9855:
    goto v_9851;
v_9852:
    goto v_9853;
v_9854:
    {
        fn = elt(env, 1); // evalgreaterp
        return (*qfn2(fn))(fn, v_9859, v_9858);
    }
}



// Code for ldt!-tvar

static LispObject CC_ldtKtvar(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9871, v_9872, v_9873;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9871 = v_9847;
// end of prologue
    v_9871 = qcar(v_9871);
    v_9871 = qcar(v_9871);
    v_9872 = v_9871;
    goto v_9862;
v_9858:
    v_9871 = v_9872;
    goto v_9859;
v_9860:
    v_9873 = elt(env, 1); // df
    goto v_9861;
v_9862:
    goto v_9858;
v_9859:
    goto v_9860;
v_9861:
    if (!consp(v_9871)) goto v_9856;
    v_9871 = qcar(v_9871);
    if (v_9871 == v_9873) goto v_9855;
    else goto v_9856;
v_9855:
    v_9871 = v_9872;
    v_9871 = qcdr(v_9871);
    v_9871 = qcar(v_9871);
    goto v_9854;
v_9856:
    v_9871 = v_9872;
    goto v_9854;
    v_9871 = nil;
v_9854:
    return onevalue(v_9871);
}



// Code for actual_alst

static LispObject CC_actual_alst(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9888, v_9889, v_9890;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_9848;
    stack[-1] = v_9847;
// end of prologue
    v_9890 = nil;
v_9853:
    v_9888 = stack[-1];
    if (v_9888 == nil) goto v_9856;
    else goto v_9857;
v_9856:
    v_9888 = v_9890;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_9888);
    }
v_9857:
    goto v_9867;
v_9863:
    v_9888 = stack[-1];
    v_9888 = qcar(v_9888);
    v_9889 = qcar(v_9888);
    goto v_9864;
v_9865:
    v_9888 = stack[0];
    goto v_9866;
v_9867:
    goto v_9863;
v_9864:
    goto v_9865;
v_9866:
    v_9888 = Lmemq(nil, v_9889, v_9888);
    if (v_9888 == nil) goto v_9862;
    goto v_9878;
v_9874:
    v_9888 = stack[-1];
    v_9888 = qcar(v_9888);
    goto v_9875;
v_9876:
    v_9889 = v_9890;
    goto v_9877;
v_9878:
    goto v_9874;
v_9875:
    goto v_9876;
v_9877:
    v_9888 = cons(v_9888, v_9889);
    env = stack[-2];
    v_9890 = v_9888;
    v_9888 = stack[-1];
    v_9888 = qcdr(v_9888);
    stack[-1] = v_9888;
    goto v_9853;
v_9862:
    v_9888 = stack[-1];
    v_9888 = qcdr(v_9888);
    stack[-1] = v_9888;
    goto v_9853;
    v_9888 = nil;
    return onevalue(v_9888);
}



// Code for simp!-sign

static LispObject CC_simpKsign(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9853;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_9853 = v_9847;
// end of prologue
    v_9853 = qcar(v_9853);
    fn = elt(env, 1); // reval
    v_9853 = (*qfn1(fn))(fn, v_9853);
    env = stack[0];
    {
        fn = elt(env, 2); // simp!-sign1
        return (*qfn1(fn))(fn, v_9853);
    }
}



// Code for symbid

static LispObject CC_symbid(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9957, v_9958, v_9959, v_9960;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_9959 = v_9848;
    stack[0] = v_9847;
// end of prologue
    v_9957 = qvalue(elt(env, 1)); // fname!*
    if (v_9957 == nil) goto v_9853;
    goto v_9865;
v_9861:
    v_9958 = qvalue(elt(env, 2)); // ftype!*
    goto v_9862;
v_9863:
    v_9957 = elt(env, 3); // (macro smacro inline)
    goto v_9864;
v_9865:
    goto v_9861;
v_9862:
    goto v_9863;
v_9864:
    v_9957 = Lmemq(nil, v_9958, v_9957);
    if (v_9957 == nil) goto v_9859;
    else goto v_9860;
v_9859:
    goto v_9876;
v_9872:
    v_9957 = stack[0];
    goto v_9873;
v_9874:
    v_9958 = v_9959;
    goto v_9875;
v_9876:
    goto v_9872;
v_9873:
    goto v_9874;
v_9875:
    v_9957 = Latsoc(nil, v_9957, v_9958);
    if (v_9957 == nil) goto v_9871;
    else goto v_9870;
v_9871:
    v_9957 = stack[0];
    v_9957 = Lsymbol_specialp(nil, v_9957);
    env = stack[-1];
    if (v_9957 == nil) goto v_9882;
    else goto v_9881;
v_9882:
    v_9957 = stack[0];
    v_9957 = Lsymbol_globalp(nil, v_9957);
    env = stack[-1];
    if (v_9957 == nil) goto v_9887;
    else goto v_9886;
v_9887:
    v_9957 = stack[0];
    if (v_9957 == nil) goto v_9892;
    else goto v_9893;
v_9892:
    v_9957 = lisp_true;
    goto v_9891;
v_9893:
    goto v_9906;
v_9902:
    v_9958 = stack[0];
    goto v_9903;
v_9904:
    v_9957 = lisp_true;
    goto v_9905;
v_9906:
    goto v_9902;
v_9903:
    goto v_9904;
v_9905:
    if (v_9958 == v_9957) goto v_9900;
    else goto v_9901;
v_9900:
    v_9957 = lisp_true;
    goto v_9899;
v_9901:
    v_9957 = stack[0];
    if (!symbolp(v_9957)) v_9957 = nil;
    else { v_9957 = qfastgets(v_9957);
           if (v_9957 != nil) { v_9957 = elt(v_9957, 17); // share
#ifdef RECORD_GET
             if (v_9957 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v_9957 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v_9957 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v_9957 == SPID_NOPROP) v_9957 = nil; else v_9957 = lisp_true; }}
#endif
    if (v_9957 == nil) goto v_9915;
    v_9957 = lisp_true;
    goto v_9913;
v_9915:
    v_9957 = qvalue(elt(env, 4)); // !*comp
    if (v_9957 == nil) goto v_9923;
    else goto v_9922;
v_9923:
    v_9957 = qvalue(elt(env, 5)); // !*cref
    if (v_9957 == nil) goto v_9927;
    else goto v_9926;
v_9927:
    goto v_9934;
v_9930:
    v_9958 = stack[0];
    goto v_9931;
v_9932:
    v_9957 = elt(env, 6); // constant!?
    goto v_9933;
v_9934:
    goto v_9930;
v_9931:
    goto v_9932;
v_9933:
    v_9957 = get(v_9958, v_9957);
    env = stack[-1];
v_9926:
v_9922:
    goto v_9913;
    v_9957 = nil;
v_9913:
    goto v_9899;
    v_9957 = nil;
v_9899:
    goto v_9891;
    v_9957 = nil;
v_9891:
v_9886:
v_9881:
v_9870:
    v_9957 = (v_9957 == nil ? lisp_true : nil);
    goto v_9858;
v_9860:
    v_9957 = nil;
    goto v_9858;
    v_9957 = nil;
v_9858:
    if (v_9957 == nil) goto v_9853;
    goto v_9951;
v_9943:
    v_9960 = elt(env, 7); // "nonlocal use of undeclared variable"
    goto v_9944;
v_9945:
    v_9959 = stack[0];
    goto v_9946;
v_9947:
    v_9958 = elt(env, 8); // "in procedure"
    goto v_9948;
v_9949:
    v_9957 = qvalue(elt(env, 1)); // fname!*
    goto v_9950;
v_9951:
    goto v_9943;
v_9944:
    goto v_9945;
v_9946:
    goto v_9947;
v_9948:
    goto v_9949;
v_9950:
    v_9957 = list4(v_9960, v_9959, v_9958, v_9957);
    env = stack[-1];
    fn = elt(env, 9); // lprim
    v_9957 = (*qfn1(fn))(fn, v_9957);
    goto v_9851;
v_9853:
v_9851:
    v_9957 = stack[0];
    return onevalue(v_9957);
}



// Code for getmatelem

static LispObject CC_getmatelem(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_10042, v_10043, v_10044;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_9847;
// end of prologue
v_9846:
    goto v_9861;
v_9857:
    v_10042 = stack[-2];
    v_10043 = Llength(nil, v_10042);
    env = stack[-4];
    goto v_9858;
v_9859:
    v_10042 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_9860;
v_9861:
    goto v_9857;
v_9858:
    goto v_9859;
v_9860:
    if (v_10043 == v_10042) goto v_9856;
    goto v_9870;
v_9866:
    v_10043 = stack[-2];
    goto v_9867;
v_9868:
    v_10042 = elt(env, 1); // "matrix element"
    goto v_9869;
v_9870:
    goto v_9866;
v_9867:
    goto v_9868;
v_9869:
    fn = elt(env, 8); // typerr
    v_10042 = (*qfn2(fn))(fn, v_10043, v_10042);
    env = stack[-4];
    goto v_9854;
v_9856:
v_9854:
    v_10042 = stack[-2];
    v_10042 = qcar(v_10042);
    if (!symbolp(v_10042)) v_10042 = nil;
    else { v_10042 = qfastgets(v_10042);
           if (v_10042 != nil) { v_10042 = elt(v_10042, 4); // avalue
#ifdef RECORD_GET
             if (v_10042 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_10042 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_10042 == SPID_NOPROP) v_10042 = nil; }}
#endif
    stack[-3] = v_10042;
    v_10042 = stack[-3];
    if (v_10042 == nil) goto v_9882;
    else goto v_9883;
v_9882:
    v_10042 = lisp_true;
    goto v_9881;
v_9883:
    goto v_9892;
v_9888:
    v_10042 = stack[-3];
    v_10043 = qcar(v_10042);
    goto v_9889;
v_9890:
    v_10042 = elt(env, 2); // matrix
    goto v_9891;
v_9892:
    goto v_9888;
v_9889:
    goto v_9890;
v_9891:
    v_10042 = (v_10043 == v_10042 ? lisp_true : nil);
    v_10042 = (v_10042 == nil ? lisp_true : nil);
    goto v_9881;
    v_10042 = nil;
v_9881:
    if (v_10042 == nil) goto v_9879;
    goto v_9903;
v_9899:
    v_10042 = stack[-2];
    v_10043 = qcar(v_10042);
    goto v_9900;
v_9901:
    v_10042 = elt(env, 3); // "matrix"
    goto v_9902;
v_9903:
    goto v_9899;
v_9900:
    goto v_9901;
v_9902:
    fn = elt(env, 8); // typerr
    v_10042 = (*qfn2(fn))(fn, v_10043, v_10042);
    env = stack[-4];
    goto v_9877;
v_9879:
    goto v_9914;
v_9910:
    v_10042 = stack[-3];
    v_10042 = qcdr(v_10042);
    v_10043 = qcar(v_10042);
    stack[-3] = v_10043;
    goto v_9911;
v_9912:
    v_10042 = elt(env, 4); // mat
    goto v_9913;
v_9914:
    goto v_9910;
v_9911:
    goto v_9912;
v_9913:
    if (!consp(v_10043)) goto v_9907;
    v_10043 = qcar(v_10043);
    if (v_10043 == v_10042) goto v_9908;
v_9907:
    v_10042 = stack[-3];
    if (symbolp(v_10042)) goto v_9921;
    else goto v_9922;
v_9921:
    goto v_9930;
v_9926:
    v_10043 = stack[-3];
    goto v_9927;
v_9928:
    v_10042 = stack[-2];
    v_10042 = qcdr(v_10042);
    goto v_9929;
v_9930:
    goto v_9926;
v_9927:
    goto v_9928;
v_9929:
    v_10042 = cons(v_10043, v_10042);
    env = stack[-4];
    stack[-2] = v_10042;
    goto v_9846;
v_9922:
    goto v_9943;
v_9937:
    stack[-1] = elt(env, 2); // matrix
    goto v_9938;
v_9939:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9940;
v_9941:
    goto v_9953;
v_9947:
    v_10044 = elt(env, 5); // "Matrix"
    goto v_9948;
v_9949:
    v_10042 = stack[-2];
    v_10043 = qcar(v_10042);
    goto v_9950;
v_9951:
    v_10042 = elt(env, 6); // "not set"
    goto v_9952;
v_9953:
    goto v_9947;
v_9948:
    goto v_9949;
v_9950:
    goto v_9951;
v_9952:
    v_10042 = list3(v_10044, v_10043, v_10042);
    env = stack[-4];
    goto v_9942;
v_9943:
    goto v_9937;
v_9938:
    goto v_9939;
v_9940:
    goto v_9941;
v_9942:
    fn = elt(env, 9); // rerror
    v_10042 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_10042);
    env = stack[-4];
    goto v_9920;
v_9920:
    goto v_9877;
v_9908:
v_9877:
    v_10042 = stack[-2];
    v_10042 = qcdr(v_10042);
    v_10042 = qcar(v_10042);
    fn = elt(env, 10); // reval_without_mod
    v_10042 = (*qfn1(fn))(fn, v_10042);
    env = stack[-4];
    stack[0] = v_10042;
    v_10042 = stack[0];
    v_10042 = integerp(v_10042);
    if (v_10042 == nil) goto v_9968;
    else goto v_9969;
v_9968:
    v_10042 = lisp_true;
    goto v_9967;
v_9969:
    goto v_9980;
v_9976:
    v_10043 = stack[0];
    goto v_9977;
v_9978:
    v_10042 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9979;
v_9980:
    goto v_9976;
v_9977:
    goto v_9978;
v_9979:
    v_10042 = (LispObject)lesseq2(v_10043, v_10042);
    v_10042 = v_10042 ? lisp_true : nil;
    env = stack[-4];
    goto v_9967;
    v_10042 = nil;
v_9967:
    if (v_10042 == nil) goto v_9965;
    goto v_9988;
v_9984:
    v_10043 = stack[0];
    goto v_9985;
v_9986:
    v_10042 = elt(env, 7); // "positive integer"
    goto v_9987;
v_9988:
    goto v_9984;
v_9985:
    goto v_9986;
v_9987:
    fn = elt(env, 8); // typerr
    v_10042 = (*qfn2(fn))(fn, v_10043, v_10042);
    env = stack[-4];
    goto v_9963;
v_9965:
v_9963:
    goto v_9996;
v_9992:
    v_10042 = stack[-3];
    v_10043 = qcdr(v_10042);
    goto v_9993;
v_9994:
    v_10042 = stack[0];
    goto v_9995;
v_9996:
    goto v_9992;
v_9993:
    goto v_9994;
v_9995:
    fn = elt(env, 11); // nth
    v_10042 = (*qfn2(fn))(fn, v_10043, v_10042);
    env = stack[-4];
    stack[-3] = v_10042;
    v_10042 = stack[-2];
    v_10042 = qcdr(v_10042);
    v_10042 = qcdr(v_10042);
    v_10042 = qcar(v_10042);
    fn = elt(env, 10); // reval_without_mod
    v_10042 = (*qfn1(fn))(fn, v_10042);
    env = stack[-4];
    stack[0] = v_10042;
    v_10042 = stack[0];
    v_10042 = integerp(v_10042);
    if (v_10042 == nil) goto v_10011;
    else goto v_10012;
v_10011:
    v_10042 = lisp_true;
    goto v_10010;
v_10012:
    goto v_10023;
v_10019:
    v_10043 = stack[0];
    goto v_10020;
v_10021:
    v_10042 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10022;
v_10023:
    goto v_10019;
v_10020:
    goto v_10021;
v_10022:
    v_10042 = (LispObject)lesseq2(v_10043, v_10042);
    v_10042 = v_10042 ? lisp_true : nil;
    env = stack[-4];
    goto v_10010;
    v_10042 = nil;
v_10010:
    if (v_10042 == nil) goto v_10008;
    goto v_10031;
v_10027:
    v_10043 = stack[0];
    goto v_10028;
v_10029:
    v_10042 = elt(env, 7); // "positive integer"
    goto v_10030;
v_10031:
    goto v_10027;
v_10028:
    goto v_10029;
v_10030:
    fn = elt(env, 8); // typerr
    v_10042 = (*qfn2(fn))(fn, v_10043, v_10042);
    env = stack[-4];
    goto v_10006;
v_10008:
v_10006:
    goto v_10039;
v_10035:
    v_10043 = stack[-3];
    goto v_10036;
v_10037:
    v_10042 = stack[0];
    goto v_10038;
v_10039:
    goto v_10035;
v_10036:
    goto v_10037;
v_10038:
    {
        fn = elt(env, 11); // nth
        return (*qfn2(fn))(fn, v_10043, v_10042);
    }
    return onevalue(v_10042);
}



// Code for dl_get2

static LispObject CC_dl_get2(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9884, v_9885, v_9886;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_9884 = v_9848;
    v_9885 = v_9847;
// end of prologue
v_9853:
    v_9886 = v_9885;
    if (v_9886 == nil) goto v_9856;
    else goto v_9857;
v_9856:
    goto v_9852;
v_9857:
    v_9886 = v_9885;
    v_9886 = qcar(v_9886);
    if (!symbolp(v_9886)) v_9886 = nil;
    else { v_9886 = qfastgets(v_9886);
           if (v_9886 != nil) { v_9886 = elt(v_9886, 32); // dummy
#ifdef RECORD_GET
             if (v_9886 != SPID_NOPROP)
                record_get(elt(fastget_names, 32), 1);
             else record_get(elt(fastget_names, 32), 0),
                v_9886 = nil; }
           else record_get(elt(fastget_names, 32), 0); }
#else
             if (v_9886 == SPID_NOPROP) v_9886 = nil; }}
#endif
    if (v_9886 == nil) goto v_9861;
    v_9886 = v_9885;
    v_9886 = qcdr(v_9886);
    stack[0] = v_9886;
    goto v_9874;
v_9868:
    v_9886 = qcar(v_9885);
    goto v_9869;
v_9870:
    v_9885 = v_9884;
    goto v_9871;
v_9872:
    v_9884 = nil;
    goto v_9873;
v_9874:
    goto v_9868;
v_9869:
    goto v_9870;
v_9871:
    goto v_9872;
v_9873:
    fn = elt(env, 1); // di_insert
    v_9884 = (*qfnn(fn))(fn, 3, v_9886, v_9885, v_9884);
    env = stack[-1];
    v_9885 = stack[0];
    goto v_9853;
v_9861:
    v_9885 = qcdr(v_9885);
    goto v_9853;
    v_9884 = nil;
v_9852:
    return onevalue(v_9884);
}



// Code for invbf

static LispObject CC_invbf(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9861, v_9862, v_9863;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_9861 = v_9847;
// end of prologue
    goto v_9857;
v_9851:
    v_9863 = qvalue(elt(env, 1)); // bfone!*
    goto v_9852;
v_9853:
    v_9862 = v_9861;
    goto v_9854;
v_9855:
    v_9861 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_9856;
v_9857:
    goto v_9851;
v_9852:
    goto v_9853;
v_9854:
    goto v_9855;
v_9856:
    fn = elt(env, 3); // divide!:
    v_9861 = (*qfnn(fn))(fn, 3, v_9863, v_9862, v_9861);
    env = stack[0];
    {
        fn = elt(env, 4); // normbf
        return (*qfn1(fn))(fn, v_9861);
    }
}



// Code for negate!-term

static LispObject CC_negateKterm(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9860, v_9861;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_9861 = v_9847;
// end of prologue
    goto v_9854;
v_9850:
    v_9860 = v_9861;
    stack[0] = qcar(v_9860);
    goto v_9851;
v_9852:
    v_9860 = v_9861;
    v_9860 = qcdr(v_9860);
    fn = elt(env, 1); // minus!-mod!-p
    v_9860 = (*qfn1(fn))(fn, v_9860);
    goto v_9853;
v_9854:
    goto v_9850;
v_9851:
    goto v_9852;
v_9853:
    {
        LispObject v_9863 = stack[0];
        return cons(v_9863, v_9860);
    }
}



// Code for lex_restore_context

static LispObject CC_lex_restore_context(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9946, v_9947, v_9948;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_9847;
// end of prologue
    fn = elt(env, 7); // lex_cleanup
    v_9946 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    v_9946 = stack[0];
    stack[0] = v_9946;
v_9858:
    v_9946 = stack[0];
    if (v_9946 == nil) goto v_9862;
    else goto v_9863;
v_9862:
    goto v_9857;
v_9863:
    v_9946 = stack[0];
    v_9946 = qcar(v_9946);
    v_9947 = v_9946;
    v_9946 = v_9947;
    v_9946 = qcar(v_9946);
    stack[-2] = v_9946;
    v_9946 = v_9947;
    v_9946 = qcdr(v_9946);
    v_9946 = qcar(v_9946);
    stack[-1] = v_9946;
    v_9946 = v_9947;
    v_9946 = qcdr(v_9946);
    v_9946 = qcdr(v_9946);
    v_9946 = Lintern(nil, v_9946);
    env = stack[-4];
    stack[-3] = v_9946;
    goto v_9887;
v_9883:
    v_9947 = stack[-3];
    goto v_9884;
v_9885:
    v_9946 = elt(env, 1); // lex_fixed_code
    goto v_9886;
v_9887:
    goto v_9883;
v_9884:
    goto v_9885;
v_9886:
    v_9946 = get(v_9947, v_9946);
    env = stack[-4];
    if (v_9946 == nil) goto v_9880;
    else goto v_9881;
v_9880:
    goto v_9899;
v_9895:
    v_9947 = stack[-1];
    goto v_9896;
v_9897:
    v_9946 = qvalue(elt(env, 2)); // lex_next_code
    goto v_9898;
v_9899:
    goto v_9895;
v_9896:
    goto v_9897;
v_9898:
    v_9946 = (LispObject)greaterp2(v_9947, v_9946);
    v_9946 = v_9946 ? lisp_true : nil;
    env = stack[-4];
    if (v_9946 == nil) goto v_9893;
    v_9946 = stack[-1];
    qvalue(elt(env, 2)) = v_9946; // lex_next_code
    goto v_9891;
v_9893:
v_9891:
    goto v_9910;
v_9904:
    v_9948 = stack[-3];
    goto v_9905;
v_9906:
    v_9947 = elt(env, 3); // lex_dipthong
    goto v_9907;
v_9908:
    v_9946 = stack[-2];
    goto v_9909;
v_9910:
    goto v_9904;
v_9905:
    goto v_9906;
v_9907:
    goto v_9908;
v_9909:
    v_9946 = Lputprop(nil, 3, v_9948, v_9947, v_9946);
    env = stack[-4];
    goto v_9921;
v_9915:
    v_9948 = stack[-3];
    goto v_9916;
v_9917:
    v_9947 = elt(env, 4); // lex_code
    goto v_9918;
v_9919:
    v_9946 = stack[-1];
    goto v_9920;
v_9921:
    goto v_9915;
v_9916:
    goto v_9917;
v_9918:
    goto v_9919;
v_9920:
    v_9946 = Lputprop(nil, 3, v_9948, v_9947, v_9946);
    env = stack[-4];
    goto v_9932;
v_9926:
    v_9948 = stack[-1];
    goto v_9927;
v_9928:
    v_9947 = stack[-3];
    goto v_9929;
v_9930:
    v_9946 = qvalue(elt(env, 5)); // lex_codename
    goto v_9931;
v_9932:
    goto v_9926;
v_9927:
    goto v_9928;
v_9929:
    goto v_9930;
v_9931:
    v_9946 = acons(v_9948, v_9947, v_9946);
    env = stack[-4];
    qvalue(elt(env, 5)) = v_9946; // lex_codename
    goto v_9941;
v_9937:
    v_9947 = stack[-3];
    goto v_9938;
v_9939:
    v_9946 = qvalue(elt(env, 6)); // lex_keyword_names
    goto v_9940;
v_9941:
    goto v_9937;
v_9938:
    goto v_9939;
v_9940:
    v_9946 = cons(v_9947, v_9946);
    env = stack[-4];
    qvalue(elt(env, 6)) = v_9946; // lex_keyword_names
    goto v_9879;
v_9881:
v_9879:
    v_9946 = stack[0];
    v_9946 = qcdr(v_9946);
    stack[0] = v_9946;
    goto v_9858;
v_9857:
    v_9946 = nil;
    return onevalue(v_9946);
}



// Code for talp_smwrmknowl

static LispObject CC_talp_smwrmknowl(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9873, v_9874, v_9875;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9874 = v_9848;
    v_9875 = v_9847;
// end of prologue
    v_9873 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_9873 == nil) goto v_9853;
    goto v_9860;
v_9856:
    v_9873 = v_9875;
    goto v_9857;
v_9858:
    goto v_9859;
v_9860:
    goto v_9856;
v_9857:
    goto v_9858;
v_9859:
    {
        fn = elt(env, 2); // cl_susirmknowl
        return (*qfn2(fn))(fn, v_9873, v_9874);
    }
v_9853:
    goto v_9870;
v_9866:
    v_9873 = v_9875;
    goto v_9867;
v_9868:
    goto v_9869;
v_9870:
    goto v_9866;
v_9867:
    goto v_9868;
v_9869:
    {
        fn = elt(env, 3); // cl_smrmknowl
        return (*qfn2(fn))(fn, v_9873, v_9874);
    }
    v_9873 = nil;
    return onevalue(v_9873);
}



// Code for qqe_simplat1

static LispObject CC_qqe_simplat1(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9900, v_9901, v_9902;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_9848;
    stack[-1] = v_9847;
// end of prologue
    v_9900 = stack[-1];
    fn = elt(env, 3); // qqe_op
    v_9900 = (*qfn1(fn))(fn, v_9900);
    env = stack[-2];
    v_9902 = v_9900;
    goto v_9861;
v_9857:
    v_9901 = v_9902;
    goto v_9858;
v_9859:
    v_9900 = elt(env, 1); // (qequal qneq)
    goto v_9860;
v_9861:
    goto v_9857;
v_9858:
    goto v_9859;
v_9860:
    v_9900 = Lmemq(nil, v_9901, v_9900);
    if (v_9900 == nil) goto v_9855;
    else goto v_9856;
v_9855:
    goto v_9870;
v_9866:
    v_9901 = stack[-1];
    goto v_9867;
v_9868:
    v_9900 = stack[0];
    goto v_9869;
v_9870:
    goto v_9866;
v_9867:
    goto v_9868;
v_9869:
    {
        fn = elt(env, 4); // qqe_simplbtat
        return (*qfn2(fn))(fn, v_9901, v_9900);
    }
v_9856:
    goto v_9879;
v_9875:
    v_9901 = v_9902;
    goto v_9876;
v_9877:
    v_9900 = elt(env, 2); // qequal
    goto v_9878;
v_9879:
    goto v_9875;
v_9876:
    goto v_9877;
v_9878:
    if (v_9901 == v_9900) goto v_9873;
    else goto v_9874;
v_9873:
    goto v_9887;
v_9883:
    v_9901 = stack[-1];
    goto v_9884;
v_9885:
    v_9900 = stack[0];
    goto v_9886;
v_9887:
    goto v_9883;
v_9884:
    goto v_9885;
v_9886:
    {
        fn = elt(env, 5); // qqe_simplqequal
        return (*qfn2(fn))(fn, v_9901, v_9900);
    }
v_9874:
    goto v_9897;
v_9893:
    v_9901 = stack[-1];
    goto v_9894;
v_9895:
    v_9900 = stack[0];
    goto v_9896;
v_9897:
    goto v_9893;
v_9894:
    goto v_9895;
v_9896:
    {
        fn = elt(env, 6); // qqe_simplqneq
        return (*qfn2(fn))(fn, v_9901, v_9900);
    }
    v_9900 = nil;
    return onevalue(v_9900);
}



// Code for sq2sspl

static LispObject CC_sq2sspl(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9908, v_9909;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_9848;
    stack[-1] = v_9847;
// end of prologue
    stack[-2] = nil;
v_9854:
    v_9908 = stack[-1];
    if (!consp(v_9908)) goto v_9863;
    else goto v_9864;
v_9863:
    v_9908 = lisp_true;
    goto v_9862;
v_9864:
    v_9908 = stack[-1];
    v_9908 = qcar(v_9908);
    v_9908 = (consp(v_9908) ? nil : lisp_true);
    goto v_9862;
    v_9908 = nil;
v_9862:
    if (v_9908 == nil) goto v_9860;
    goto v_9855;
v_9860:
    goto v_9877;
v_9873:
    goto v_9883;
v_9879:
    v_9908 = stack[-1];
    v_9909 = qcar(v_9908);
    goto v_9880;
v_9881:
    v_9908 = stack[0];
    goto v_9882;
v_9883:
    goto v_9879;
v_9880:
    goto v_9881;
v_9882:
    fn = elt(env, 1); // sq2sstm
    v_9909 = (*qfn2(fn))(fn, v_9909, v_9908);
    env = stack[-3];
    goto v_9874;
v_9875:
    v_9908 = stack[-2];
    goto v_9876;
v_9877:
    goto v_9873;
v_9874:
    goto v_9875;
v_9876:
    v_9908 = cons(v_9909, v_9908);
    env = stack[-3];
    stack[-2] = v_9908;
    v_9908 = stack[-1];
    v_9908 = qcdr(v_9908);
    stack[-1] = v_9908;
    goto v_9854;
v_9855:
    v_9908 = stack[-1];
    v_9909 = v_9908;
v_9856:
    v_9908 = stack[-2];
    if (v_9908 == nil) goto v_9893;
    else goto v_9894;
v_9893:
    v_9908 = v_9909;
    goto v_9853;
v_9894:
    goto v_9902;
v_9898:
    v_9908 = stack[-2];
    v_9908 = qcar(v_9908);
    goto v_9899;
v_9900:
    goto v_9901;
v_9902:
    goto v_9898;
v_9899:
    goto v_9900;
v_9901:
    v_9908 = Lappend(nil, v_9908, v_9909);
    env = stack[-3];
    v_9909 = v_9908;
    v_9908 = stack[-2];
    v_9908 = qcdr(v_9908);
    stack[-2] = v_9908;
    goto v_9856;
v_9853:
    return onevalue(v_9908);
}



// Code for attributesml

static LispObject CC_attributesml(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9927, v_9928;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_9848;
    stack[-1] = v_9847;
// end of prologue
    v_9927 = stack[-1];
    if (v_9927 == nil) goto v_9854;
    else goto v_9855;
v_9854:
    v_9927 = stack[0];
    v_9927 = Lprinc(nil, v_9927);
    env = stack[-2];
    v_9927 = elt(env, 1); // ">"
    v_9927 = Lprinc(nil, v_9927);
    goto v_9853;
v_9855:
    v_9927 = elt(env, 2); // " "
    v_9927 = Lprinc(nil, v_9927);
    env = stack[-2];
    v_9927 = stack[-1];
    v_9927 = qcar(v_9927);
    v_9927 = qcar(v_9927);
    v_9927 = Lprinc(nil, v_9927);
    env = stack[-2];
    v_9927 = elt(env, 3); // "="""
    v_9927 = Lprinc(nil, v_9927);
    env = stack[-2];
    goto v_9879;
v_9875:
    v_9927 = stack[-1];
    v_9927 = qcar(v_9927);
    v_9928 = qcar(v_9927);
    goto v_9876;
v_9877:
    v_9927 = elt(env, 4); // definitionurl
    goto v_9878;
v_9879:
    goto v_9875;
v_9876:
    goto v_9877;
v_9878:
    if (v_9928 == v_9927) goto v_9874;
    goto v_9892;
v_9888:
    v_9927 = stack[-1];
    v_9927 = qcar(v_9927);
    v_9927 = qcdr(v_9927);
    v_9928 = qcar(v_9927);
    goto v_9889;
v_9890:
    v_9927 = elt(env, 5); // vectorml
    goto v_9891;
v_9892:
    goto v_9888;
v_9889:
    goto v_9890;
v_9891:
    if (v_9928 == v_9927) goto v_9886;
    else goto v_9887;
v_9886:
    v_9927 = elt(env, 6); // "vector"
    v_9927 = Lprinc(nil, v_9927);
    env = stack[-2];
    goto v_9885;
v_9887:
    v_9927 = stack[-1];
    v_9927 = qcar(v_9927);
    v_9927 = qcdr(v_9927);
    v_9927 = qcar(v_9927);
    v_9927 = Lprinc(nil, v_9927);
    env = stack[-2];
    goto v_9885;
v_9885:
    goto v_9872;
v_9874:
    v_9927 = stack[-1];
    v_9927 = qcar(v_9927);
    v_9927 = qcdr(v_9927);
    v_9927 = qcar(v_9927);
    fn = elt(env, 8); // mathml_list2string
    v_9927 = (*qfn1(fn))(fn, v_9927);
    env = stack[-2];
    goto v_9872;
v_9872:
    v_9927 = elt(env, 7); // """"
    v_9927 = Lprinc(nil, v_9927);
    env = stack[-2];
    goto v_9922;
v_9918:
    v_9927 = stack[-1];
    v_9928 = qcdr(v_9927);
    goto v_9919;
v_9920:
    v_9927 = stack[0];
    goto v_9921;
v_9922:
    goto v_9918;
v_9919:
    goto v_9920;
v_9921:
    v_9927 = CC_attributesml(elt(env, 0), v_9928, v_9927);
    goto v_9853;
v_9853:
    v_9927 = nil;
    return onevalue(v_9927);
}



// Code for maprin

static LispObject CC_maprin(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9876, v_9877, v_9878;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9877 = v_9847;
// end of prologue
    v_9876 = qvalue(elt(env, 1)); // outputhandler!*
    if (v_9876 == nil) goto v_9852;
    goto v_9861;
v_9855:
    v_9876 = qvalue(elt(env, 1)); // outputhandler!*
    goto v_9856;
v_9857:
    v_9878 = elt(env, 0); // maprin
    goto v_9858;
v_9859:
    goto v_9860;
v_9861:
    goto v_9855;
v_9856:
    goto v_9857;
v_9858:
    goto v_9859;
v_9860:
        return Lapply2(nil, 3, v_9876, v_9878, v_9877);
v_9852:
    v_9876 = qvalue(elt(env, 2)); // overflowed!*
    if (v_9876 == nil) goto v_9865;
    else goto v_9866;
v_9865:
    goto v_9873;
v_9869:
    goto v_9870;
v_9871:
    v_9876 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9872;
v_9873:
    goto v_9869;
v_9870:
    goto v_9871;
v_9872:
    {
        fn = elt(env, 3); // maprint
        return (*qfn2(fn))(fn, v_9877, v_9876);
    }
v_9866:
    v_9876 = nil;
    return onevalue(v_9876);
}



// Code for dm!-eq

static LispObject CC_dmKeq(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9859, v_9860;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_9859 = v_9848;
    v_9860 = v_9847;
// end of prologue
    goto v_9856;
v_9852:
    goto v_9853;
v_9854:
    goto v_9855;
v_9856:
    goto v_9852;
v_9853:
    goto v_9854;
v_9855:
    fn = elt(env, 1); // dm!-difference
    v_9859 = (*qfn2(fn))(fn, v_9860, v_9859);
    env = stack[0];
    {
        fn = elt(env, 2); // !:zerop
        return (*qfn1(fn))(fn, v_9859);
    }
}



// Code for modminusp!:

static LispObject CC_modminuspT(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9873, v_9874;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_9873 = v_9847;
// end of prologue
    v_9874 = qvalue(elt(env, 1)); // !*balanced_mod
    if (v_9874 == nil) goto v_9852;
    goto v_9859;
v_9855:
    goto v_9865;
v_9861:
    v_9874 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_9862;
v_9863:
    v_9873 = qcdr(v_9873);
    goto v_9864;
v_9865:
    goto v_9861;
v_9862:
    goto v_9863;
v_9864:
    v_9873 = times2(v_9874, v_9873);
    env = stack[0];
    goto v_9856;
v_9857:
    v_9874 = qvalue(elt(env, 2)); // current!-modulus
    goto v_9858;
v_9859:
    goto v_9855;
v_9856:
    goto v_9857;
v_9858:
        return Lgreaterp(nil, v_9873, v_9874);
v_9852:
    v_9873 = nil;
    goto v_9850;
    v_9873 = nil;
v_9850:
    return onevalue(v_9873);
}



// Code for listeval

static LispObject CC_listeval(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9960, v_9961;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_9848;
    stack[0] = v_9847;
// end of prologue
    goto v_9859;
v_9855:
    v_9960 = qvalue(elt(env, 1)); // simpcount!*
    v_9961 = add1(v_9960);
    env = stack[-5];
    qvalue(elt(env, 1)) = v_9961; // simpcount!*
    goto v_9856;
v_9857:
    v_9960 = qvalue(elt(env, 2)); // simplimit!*
    goto v_9858;
v_9859:
    goto v_9855;
v_9856:
    goto v_9857;
v_9858:
    v_9960 = (LispObject)greaterp2(v_9961, v_9960);
    v_9960 = v_9960 ? lisp_true : nil;
    env = stack[-5];
    if (v_9960 == nil) goto v_9853;
    v_9960 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_9960; // simpcount!*
    v_9960 = elt(env, 3); // "Simplification recursion too deep"
    fn = elt(env, 4); // rederr
    v_9960 = (*qfn1(fn))(fn, v_9960);
    env = stack[-5];
    goto v_9851;
v_9853:
v_9851:
    v_9960 = stack[0];
    if (!consp(v_9960)) goto v_9868;
    else goto v_9869;
v_9868:
    goto v_9876;
v_9872:
    v_9960 = stack[0];
    if (!symbolp(v_9960)) v_9960 = nil;
    else { v_9960 = qfastgets(v_9960);
           if (v_9960 != nil) { v_9960 = elt(v_9960, 17); // share
#ifdef RECORD_GET
             if (v_9960 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v_9960 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v_9960 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v_9960 == SPID_NOPROP) v_9960 = nil; else v_9960 = lisp_true; }}
#endif
    if (v_9960 == nil) goto v_9880;
    v_9960 = stack[0];
    fn = elt(env, 5); // eval
    v_9960 = (*qfn1(fn))(fn, v_9960);
    env = stack[-5];
    v_9961 = v_9960;
    goto v_9878;
v_9880:
    v_9960 = stack[0];
    if (!symbolp(v_9960)) v_9960 = nil;
    else { v_9960 = qfastgets(v_9960);
           if (v_9960 != nil) { v_9960 = elt(v_9960, 4); // avalue
#ifdef RECORD_GET
             if (v_9960 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_9960 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_9960 == SPID_NOPROP) v_9960 = nil; }}
#endif
    v_9960 = qcdr(v_9960);
    v_9960 = qcar(v_9960);
    v_9961 = v_9960;
    goto v_9878;
    v_9961 = nil;
v_9878:
    goto v_9873;
v_9874:
    v_9960 = stack[-1];
    goto v_9875;
v_9876:
    goto v_9872;
v_9873:
    goto v_9874;
v_9875:
    v_9960 = CC_listeval(elt(env, 0), v_9961, v_9960);
    env = stack[-5];
    goto v_9867;
v_9869:
    goto v_9899;
v_9895:
    v_9960 = stack[0];
    stack[-4] = qcar(v_9960);
    goto v_9896;
v_9897:
    v_9960 = stack[0];
    v_9960 = qcdr(v_9960);
    stack[-3] = v_9960;
    v_9960 = stack[-3];
    if (v_9960 == nil) goto v_9912;
    else goto v_9913;
v_9912:
    v_9960 = nil;
    goto v_9906;
v_9913:
    v_9960 = stack[-3];
    v_9960 = qcar(v_9960);
    goto v_9925;
v_9921:
    v_9961 = v_9960;
    goto v_9922;
v_9923:
    v_9960 = lisp_true;
    goto v_9924;
v_9925:
    goto v_9921;
v_9922:
    goto v_9923;
v_9924:
    fn = elt(env, 6); // reval1
    v_9960 = (*qfn2(fn))(fn, v_9961, v_9960);
    env = stack[-5];
    v_9960 = ncons(v_9960);
    env = stack[-5];
    stack[-1] = v_9960;
    stack[-2] = v_9960;
v_9907:
    v_9960 = stack[-3];
    v_9960 = qcdr(v_9960);
    stack[-3] = v_9960;
    v_9960 = stack[-3];
    if (v_9960 == nil) goto v_9932;
    else goto v_9933;
v_9932:
    v_9960 = stack[-2];
    goto v_9906;
v_9933:
    goto v_9941;
v_9937:
    stack[0] = stack[-1];
    goto v_9938;
v_9939:
    v_9960 = stack[-3];
    v_9960 = qcar(v_9960);
    goto v_9952;
v_9948:
    v_9961 = v_9960;
    goto v_9949;
v_9950:
    v_9960 = lisp_true;
    goto v_9951;
v_9952:
    goto v_9948;
v_9949:
    goto v_9950;
v_9951:
    fn = elt(env, 6); // reval1
    v_9960 = (*qfn2(fn))(fn, v_9961, v_9960);
    env = stack[-5];
    v_9960 = ncons(v_9960);
    env = stack[-5];
    goto v_9940;
v_9941:
    goto v_9937;
v_9938:
    goto v_9939;
v_9940:
    v_9960 = Lrplacd(nil, stack[0], v_9960);
    env = stack[-5];
    v_9960 = stack[-1];
    v_9960 = qcdr(v_9960);
    stack[-1] = v_9960;
    goto v_9907;
v_9906:
    goto v_9898;
v_9899:
    goto v_9895;
v_9896:
    goto v_9897;
v_9898:
    v_9960 = cons(stack[-4], v_9960);
    env = stack[-5];
    goto v_9867;
    v_9960 = nil;
v_9867:
    stack[0] = v_9960;
    v_9960 = qvalue(elt(env, 1)); // simpcount!*
    v_9960 = sub1(v_9960);
    env = stack[-5];
    qvalue(elt(env, 1)) = v_9960; // simpcount!*
    v_9960 = stack[0];
    return onevalue(v_9960);
}



// Code for simprepart

static LispObject CC_simprepart(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9855, v_9856;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_9856 = v_9847;
// end of prologue
    v_9855 = nil;
// Binding !*factor
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_9855; // !*factor
    v_9855 = v_9856;
    v_9855 = qcar(v_9855);
    fn = elt(env, 2); // simp!*
    v_9855 = (*qfn1(fn))(fn, v_9855);
    env = stack[-1];
    fn = elt(env, 3); // repartsq
    v_9855 = (*qfn1(fn))(fn, v_9855);
    ;}  // end of a binding scope
    return onevalue(v_9855);
}



// Code for mkprogn

static LispObject CC_mkprogn(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9887, v_9888, v_9889, v_9890;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9889 = v_9848;
    v_9890 = v_9847;
// end of prologue
    goto v_9859;
v_9855:
    v_9888 = v_9889;
    goto v_9856;
v_9857:
    v_9887 = elt(env, 1); // progn
    goto v_9858;
v_9859:
    goto v_9855;
v_9856:
    goto v_9857;
v_9858:
    if (!consp(v_9888)) goto v_9853;
    v_9888 = qcar(v_9888);
    if (v_9888 == v_9887) goto v_9852;
    else goto v_9853;
v_9852:
    goto v_9869;
v_9863:
    v_9887 = elt(env, 1); // progn
    goto v_9864;
v_9865:
    v_9888 = v_9890;
    goto v_9866;
v_9867:
    v_9889 = qcdr(v_9889);
    goto v_9868;
v_9869:
    goto v_9863;
v_9864:
    goto v_9865;
v_9866:
    goto v_9867;
v_9868:
    return list2star(v_9887, v_9888, v_9889);
v_9853:
    goto v_9883;
v_9877:
    v_9887 = elt(env, 1); // progn
    goto v_9878;
v_9879:
    v_9888 = v_9890;
    goto v_9880;
v_9881:
    goto v_9882;
v_9883:
    goto v_9877;
v_9878:
    goto v_9879;
v_9880:
    goto v_9881;
v_9882:
    return list3(v_9887, v_9888, v_9889);
    v_9887 = nil;
    return onevalue(v_9887);
}



// Code for dpmat_coldegs

static LispObject CC_dpmat_coldegs(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9857, v_9858;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9857 = v_9847;
// end of prologue
    goto v_9854;
v_9850:
    v_9858 = v_9857;
    goto v_9851;
v_9852:
    v_9857 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_9853;
v_9854:
    goto v_9850;
v_9851:
    goto v_9852;
v_9853:
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(fn, v_9858, v_9857);
    }
}



// Code for pv_times1

static LispObject CC_pv_times1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_9878, v_9879, v_9880;
    LispObject fn;
    LispObject v_9849, v_9848, v_9847;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pv_times1");
    va_start(aa, nargs);
    v_9847 = va_arg(aa, LispObject);
    v_9848 = va_arg(aa, LispObject);
    v_9849 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_9849,v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_9847,v_9848,v_9849);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_9879 = v_9849;
    stack[0] = v_9848;
    v_9878 = v_9847;
// end of prologue
v_9854:
    v_9880 = v_9878;
    if (v_9880 == nil) goto v_9857;
    else goto v_9858;
v_9857:
    v_9878 = v_9879;
    goto v_9853;
v_9858:
    v_9880 = v_9878;
    v_9880 = qcdr(v_9880);
    stack[-1] = v_9880;
    goto v_9872;
v_9866:
    v_9880 = qcar(v_9878);
    goto v_9867;
v_9868:
    v_9878 = stack[0];
    goto v_9869;
v_9870:
    goto v_9871;
v_9872:
    goto v_9866;
v_9867:
    goto v_9868;
v_9869:
    goto v_9870;
v_9871:
    fn = elt(env, 1); // pv_times2
    v_9878 = (*qfnn(fn))(fn, 3, v_9880, v_9878, v_9879);
    env = stack[-2];
    v_9879 = v_9878;
    v_9878 = stack[-1];
    goto v_9854;
    v_9878 = nil;
v_9853:
    return onevalue(v_9878);
}



// Code for b!:ordexp

static LispObject CC_bTordexp(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9897, v_9898;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_9848;
    stack[-1] = v_9847;
// end of prologue
v_9846:
    v_9897 = stack[-1];
    if (v_9897 == nil) goto v_9852;
    else goto v_9853;
v_9852:
    v_9897 = lisp_true;
    goto v_9851;
v_9853:
    goto v_9866;
v_9862:
    v_9897 = stack[-1];
    v_9898 = qcar(v_9897);
    goto v_9863;
v_9864:
    v_9897 = stack[0];
    v_9897 = qcar(v_9897);
    goto v_9865;
v_9866:
    goto v_9862;
v_9863:
    goto v_9864;
v_9865:
    v_9897 = (LispObject)greaterp2(v_9898, v_9897);
    v_9897 = v_9897 ? lisp_true : nil;
    env = stack[-2];
    if (v_9897 == nil) goto v_9860;
    else goto v_9859;
v_9860:
    goto v_9879;
v_9875:
    v_9897 = stack[-1];
    v_9898 = qcar(v_9897);
    goto v_9876;
v_9877:
    v_9897 = stack[0];
    v_9897 = qcar(v_9897);
    goto v_9878;
v_9879:
    goto v_9875;
v_9876:
    goto v_9877;
v_9878:
    if (equal(v_9898, v_9897)) goto v_9873;
    else goto v_9874;
v_9873:
    goto v_9889;
v_9885:
    v_9897 = stack[-1];
    v_9898 = qcdr(v_9897);
    goto v_9886;
v_9887:
    v_9897 = stack[0];
    v_9897 = qcdr(v_9897);
    goto v_9888;
v_9889:
    goto v_9885;
v_9886:
    goto v_9887;
v_9888:
    stack[-1] = v_9898;
    stack[0] = v_9897;
    goto v_9846;
v_9874:
    v_9897 = nil;
    goto v_9872;
    v_9897 = nil;
v_9872:
v_9859:
    goto v_9851;
    v_9897 = nil;
v_9851:
    return onevalue(v_9897);
}



// Code for simpatom

static LispObject CC_simpatom(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_10138, v_10139, v_10140;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_9847;
// end of prologue
    v_10138 = stack[-1];
    if (v_10138 == nil) goto v_9851;
    else goto v_9852;
v_9851:
    goto v_9859;
v_9855:
    v_10139 = nil;
    goto v_9856;
v_9857:
    v_10138 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9858;
v_9859:
    goto v_9855;
v_9856:
    goto v_9857;
v_9858:
    return cons(v_10139, v_10138);
v_9852:
    v_10138 = stack[-1];
    if (is_number(v_10138)) goto v_9862;
    else goto v_9863;
v_9862:
    goto v_9873;
v_9869:
    v_10139 = stack[-1];
    goto v_9870;
v_9871:
    v_10138 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9872;
v_9873:
    goto v_9869;
v_9870:
    goto v_9871;
v_9872:
    if (v_10139 == v_10138) goto v_9867;
    else goto v_9868;
v_9867:
    goto v_9881;
v_9877:
    v_10139 = nil;
    goto v_9878;
v_9879:
    v_10138 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9880;
v_9881:
    goto v_9877;
v_9878:
    goto v_9879;
v_9880:
    return cons(v_10139, v_10138);
v_9868:
    v_10138 = stack[-1];
    v_10138 = integerp(v_10138);
    if (v_10138 == nil) goto v_9884;
    else goto v_9885;
v_9884:
    v_10138 = stack[-1];
    {
        fn = elt(env, 11); // rd!:simp
        return (*qfn1(fn))(fn, v_10138);
    }
v_9885:
    goto v_9900;
v_9896:
    v_10139 = qvalue(elt(env, 1)); // dmode!*
    goto v_9897;
v_9898:
    v_10138 = elt(env, 2); // !:mod!:
    goto v_9899;
v_9900:
    goto v_9896;
v_9897:
    goto v_9898;
v_9899:
    if (v_10139 == v_10138) goto v_9894;
    else goto v_9895;
v_9894:
    goto v_9907;
v_9903:
    v_10139 = qvalue(elt(env, 3)); // current!-modulus
    goto v_9904;
v_9905:
    v_10138 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9906;
v_9907:
    goto v_9903;
v_9904:
    goto v_9905;
v_9906:
    v_10138 = (v_10139 == v_10138 ? lisp_true : nil);
    goto v_9893;
v_9895:
    v_10138 = nil;
    goto v_9893;
    v_10138 = nil;
v_9893:
    if (v_10138 == nil) goto v_9891;
    goto v_9919;
v_9915:
    v_10139 = nil;
    goto v_9916;
v_9917:
    v_10138 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9918;
v_9919:
    goto v_9915;
v_9916:
    goto v_9917;
v_9918:
    return cons(v_10139, v_10138);
v_9891:
    v_10138 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_10138)) v_10138 = nil;
    else { v_10138 = qfastgets(v_10138);
           if (v_10138 != nil) { v_10138 = elt(v_10138, 5); // convert
#ifdef RECORD_GET
             if (v_10138 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v_10138 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v_10138 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v_10138 == SPID_NOPROP) v_10138 = nil; else v_10138 = lisp_true; }}
#endif
    if (v_10138 == nil) goto v_9927;
    goto v_9935;
v_9931:
    v_10139 = stack[-1];
    goto v_9932;
v_9933:
    v_10138 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9934;
v_9935:
    goto v_9931;
v_9932:
    goto v_9933;
v_9934:
    v_10138 = Lneq(nil, v_10139, v_10138);
    env = stack[-3];
    goto v_9925;
v_9927:
    v_10138 = nil;
    goto v_9925;
    v_10138 = nil;
v_9925:
    if (v_10138 == nil) goto v_9923;
    goto v_9947;
v_9943:
    v_10138 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_10138)) v_10139 = nil;
    else { v_10139 = qfastgets(v_10138);
           if (v_10139 != nil) { v_10139 = elt(v_10139, 34); // i2d
#ifdef RECORD_GET
             if (v_10139 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_10139 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_10139 == SPID_NOPROP) v_10139 = nil; }}
#endif
    goto v_9944;
v_9945:
    v_10138 = stack[-1];
    goto v_9946;
v_9947:
    goto v_9943;
v_9944:
    goto v_9945;
v_9946:
    v_10138 = Lapply1(nil, v_10139, v_10138);
    env = stack[-3];
    {
        fn = elt(env, 12); // !*d2q
        return (*qfn1(fn))(fn, v_10138);
    }
v_9923:
    goto v_9958;
v_9954:
    v_10139 = stack[-1];
    goto v_9955;
v_9956:
    v_10138 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9957;
v_9958:
    goto v_9954;
v_9955:
    goto v_9956;
v_9957:
    return cons(v_10139, v_10138);
    v_10138 = nil;
    goto v_9850;
v_9863:
    v_10138 = stack[-1];
    v_10138 = Lstringp(nil, v_10138);
    env = stack[-3];
    if (v_10138 == nil) goto v_9962;
    goto v_9970;
v_9966:
    goto v_9976;
v_9972:
    v_10139 = elt(env, 4); // "String"
    goto v_9973;
v_9974:
    v_10138 = stack[-1];
    goto v_9975;
v_9976:
    goto v_9972;
v_9973:
    goto v_9974;
v_9975:
    v_10139 = list2(v_10139, v_10138);
    env = stack[-3];
    goto v_9967;
v_9968:
    v_10138 = elt(env, 5); // "identifier"
    goto v_9969;
v_9970:
    goto v_9966;
v_9967:
    goto v_9968;
v_9969:
    {
        fn = elt(env, 13); // typerr
        return (*qfn2(fn))(fn, v_10139, v_10138);
    }
v_9962:
    v_10138 = stack[-1];
    if (!symbolp(v_10138)) v_10138 = nil;
    else { v_10138 = qfastgets(v_10138);
           if (v_10138 != nil) { v_10138 = elt(v_10138, 17); // share
#ifdef RECORD_GET
             if (v_10138 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v_10138 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v_10138 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v_10138 == SPID_NOPROP) v_10138 = nil; else v_10138 = lisp_true; }}
#endif
    if (v_10138 == nil) goto v_9981;
    v_10138 = stack[-1];
    fn = elt(env, 14); // lispeval
    v_10138 = (*qfn1(fn))(fn, v_10138);
    env = stack[-3];
    v_10140 = v_10138;
    goto v_9995;
v_9991:
    v_10139 = v_10140;
    goto v_9992;
v_9993:
    v_10138 = stack[-1];
    goto v_9994;
v_9995:
    goto v_9991;
v_9992:
    goto v_9993;
v_9994:
    if (v_10139 == v_10138) goto v_9989;
    else goto v_9990;
v_9989:
    goto v_10003;
v_9999:
    v_10139 = stack[-1];
    goto v_10000;
v_10001:
    v_10138 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10002;
v_10003:
    goto v_9999;
v_10000:
    goto v_10001;
v_10002:
    {
        fn = elt(env, 15); // mksq
        return (*qfn2(fn))(fn, v_10139, v_10138);
    }
v_9990:
    v_10138 = v_10140;
    {
        fn = elt(env, 16); // simp
        return (*qfn1(fn))(fn, v_10138);
    }
    v_10138 = nil;
    goto v_9850;
v_9981:
    v_10138 = stack[-1];
    if (!symbolp(v_10138)) v_10138 = nil;
    else { v_10138 = qfastgets(v_10138);
           if (v_10138 != nil) { v_10138 = elt(v_10138, 56); // idvalfn
#ifdef RECORD_GET
             if (v_10138 != SPID_NOPROP)
                record_get(elt(fastget_names, 56), 1);
             else record_get(elt(fastget_names, 56), 0),
                v_10138 = nil; }
           else record_get(elt(fastget_names, 56), 0); }
#else
             if (v_10138 == SPID_NOPROP) v_10138 = nil; }}
#endif
    stack[-2] = v_10138;
    if (v_10138 == nil) goto v_10018;
    goto v_10026;
v_10022:
    v_10139 = stack[-2];
    goto v_10023;
v_10024:
    v_10138 = stack[-1];
    goto v_10025;
v_10026:
    goto v_10022;
v_10023:
    goto v_10024;
v_10025:
        return Lapply1(nil, v_10139, v_10138);
v_10018:
    v_10138 = qvalue(elt(env, 6)); // !*numval
    if (v_10138 == nil) goto v_10030;
    v_10138 = qvalue(elt(env, 1)); // dmode!*
    if (v_10138 == nil) goto v_10030;
    goto v_10046;
v_10042:
    v_10139 = stack[-1];
    goto v_10043;
v_10044:
    v_10138 = elt(env, 7); // constant
    goto v_10045;
v_10046:
    goto v_10042;
v_10043:
    goto v_10044;
v_10045:
    v_10138 = Lflagp(nil, v_10139, v_10138);
    env = stack[-3];
    if (v_10138 == nil) goto v_10040;
    goto v_10058;
v_10054:
    v_10139 = stack[-1];
    goto v_10055;
v_10056:
    v_10138 = qvalue(elt(env, 1)); // dmode!*
    goto v_10057;
v_10058:
    goto v_10054;
v_10055:
    goto v_10056;
v_10057:
    v_10138 = get(v_10139, v_10138);
    env = stack[-3];
    stack[-2] = v_10138;
    if (v_10138 == nil) goto v_10051;
    else goto v_10052;
v_10051:
    v_10138 = nil;
    goto v_10050;
v_10052:
    goto v_10074;
v_10070:
    goto v_10082;
v_10076:
    stack[0] = elt(env, 8); // lispapply
    goto v_10077;
v_10078:
    v_10138 = stack[-2];
    v_10139 = Lmkquote(nil, v_10138);
    env = stack[-3];
    goto v_10079;
v_10080:
    v_10138 = nil;
    goto v_10081;
v_10082:
    goto v_10076;
v_10077:
    goto v_10078;
v_10079:
    goto v_10080;
v_10081:
    v_10139 = list3(stack[0], v_10139, v_10138);
    env = stack[-3];
    goto v_10071;
v_10072:
    v_10138 = nil;
    goto v_10073;
v_10074:
    goto v_10070;
v_10071:
    goto v_10072;
v_10073:
    fn = elt(env, 17); // errorset!*
    v_10138 = (*qfn2(fn))(fn, v_10139, v_10138);
    env = stack[-3];
    stack[-2] = v_10138;
    fn = elt(env, 18); // errorp
    v_10138 = (*qfn1(fn))(fn, v_10138);
    env = stack[-3];
    if (v_10138 == nil) goto v_10066;
    else goto v_10067;
v_10066:
    goto v_10097;
v_10093:
    v_10138 = stack[-2];
    v_10139 = qcar(v_10138);
    stack[-2] = v_10139;
    goto v_10094;
v_10095:
    v_10138 = elt(env, 9); // !:rd!:
    goto v_10096;
v_10097:
    goto v_10093;
v_10094:
    goto v_10095;
v_10096:
    if (!consp(v_10139)) goto v_10090;
    v_10139 = qcar(v_10139);
    if (v_10139 == v_10138) goto v_10091;
v_10090:
    v_10138 = lisp_true;
    goto v_10089;
v_10091:
    v_10138 = stack[-2];
    v_10138 = qcdr(v_10138);
    fn = elt(env, 19); // complexp
    v_10138 = (*qfn1(fn))(fn, v_10138);
    env = stack[-3];
    v_10138 = (v_10138 == nil ? lisp_true : nil);
    goto v_10089;
    v_10138 = nil;
v_10089:
    goto v_10065;
v_10067:
    v_10138 = nil;
    goto v_10065;
    v_10138 = nil;
v_10065:
    goto v_10050;
    v_10138 = nil;
v_10050:
    goto v_10038;
v_10040:
    v_10138 = nil;
    goto v_10038;
    v_10138 = nil;
v_10038:
    if (v_10138 == nil) goto v_10030;
    v_10138 = stack[-2];
    {
        fn = elt(env, 12); // !*d2q
        return (*qfn1(fn))(fn, v_10138);
    }
v_10030:
    v_10138 = stack[-1];
    fn = elt(env, 20); // getrtype
    v_10138 = (*qfn1(fn))(fn, v_10138);
    env = stack[-3];
    if (v_10138 == nil) goto v_10117;
    goto v_10125;
v_10121:
    v_10139 = stack[-1];
    goto v_10122;
v_10123:
    v_10138 = elt(env, 10); // scalar
    goto v_10124;
v_10125:
    goto v_10121;
v_10122:
    goto v_10123;
v_10124:
    fn = elt(env, 13); // typerr
    v_10138 = (*qfn2(fn))(fn, v_10139, v_10138);
    goto v_10016;
v_10117:
    goto v_10135;
v_10131:
    v_10139 = stack[-1];
    goto v_10132;
v_10133:
    v_10138 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10134;
v_10135:
    goto v_10131;
v_10132:
    goto v_10133;
v_10134:
    {
        fn = elt(env, 15); // mksq
        return (*qfn2(fn))(fn, v_10139, v_10138);
    }
v_10016:
    v_10138 = nil;
    goto v_9850;
    v_10138 = nil;
v_9850:
    return onevalue(v_10138);
}



// Code for xremainder!-mod!-p

static LispObject CC_xremainderKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10013, v_10014, v_10015;
    LispObject fn;
    LispObject v_9849, v_9848, v_9847;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xremainder-mod-p");
    va_start(aa, nargs);
    v_9847 = va_arg(aa, LispObject);
    v_9848 = va_arg(aa, LispObject);
    v_9849 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_9849,v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_9847,v_9848,v_9849);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_9849;
    stack[-1] = v_9848;
    stack[-2] = v_9847;
// end of prologue
v_9846:
    v_10013 = stack[-2];
    if (!consp(v_10013)) goto v_9861;
    else goto v_9862;
v_9861:
    v_10013 = lisp_true;
    goto v_9860;
v_9862:
    v_10013 = stack[-2];
    v_10013 = qcar(v_10013);
    v_10013 = (consp(v_10013) ? nil : lisp_true);
    goto v_9860;
    v_10013 = nil;
v_9860:
    if (v_10013 == nil) goto v_9858;
    v_10013 = lisp_true;
    goto v_9856;
v_9858:
    goto v_9881;
v_9877:
    v_10013 = stack[-2];
    v_10013 = qcar(v_10013);
    v_10013 = qcar(v_10013);
    v_10014 = qcar(v_10013);
    goto v_9878;
v_9879:
    v_10013 = stack[0];
    goto v_9880;
v_9881:
    goto v_9877;
v_9878:
    goto v_9879;
v_9880:
    if (equal(v_10014, v_10013)) goto v_9876;
    v_10013 = lisp_true;
    goto v_9874;
v_9876:
    goto v_9894;
v_9890:
    v_10013 = stack[-2];
    v_10013 = qcar(v_10013);
    v_10013 = qcar(v_10013);
    v_10014 = qcdr(v_10013);
    goto v_9891;
v_9892:
    v_10013 = stack[-1];
    v_10013 = qcar(v_10013);
    v_10013 = qcar(v_10013);
    v_10013 = qcdr(v_10013);
    goto v_9893;
v_9894:
    goto v_9890;
v_9891:
    goto v_9892;
v_9893:
    v_10013 = ((intptr_t)v_10014 < (intptr_t)v_10013) ? lisp_true : nil;
    goto v_9874;
    v_10013 = nil;
v_9874:
    goto v_9856;
    v_10013 = nil;
v_9856:
    if (v_10013 == nil) goto v_9854;
    v_10013 = stack[-2];
    goto v_9852;
v_9854:
    goto v_9916;
v_9912:
    v_10013 = stack[-2];
    v_10013 = qcar(v_10013);
    v_10013 = qcdr(v_10013);
    fn = elt(env, 1); // minus!-mod!-p
    v_10014 = (*qfn1(fn))(fn, v_10013);
    env = stack[-4];
    goto v_9913;
v_9914:
    v_10013 = stack[-1];
    v_10013 = qcar(v_10013);
    v_10013 = qcdr(v_10013);
    goto v_9915;
v_9916:
    goto v_9912;
v_9913:
    goto v_9914;
v_9915:
    fn = elt(env, 2); // quotient!-mod!-p
    v_10013 = (*qfn2(fn))(fn, v_10014, v_10013);
    env = stack[-4];
    stack[-3] = v_10013;
    goto v_9928;
v_9924:
    v_10013 = stack[-2];
    v_10013 = qcar(v_10013);
    v_10013 = qcar(v_10013);
    v_10014 = qcdr(v_10013);
    goto v_9925;
v_9926:
    v_10013 = stack[-1];
    v_10013 = qcar(v_10013);
    v_10013 = qcar(v_10013);
    v_10013 = qcdr(v_10013);
    goto v_9927;
v_9928:
    goto v_9924;
v_9925:
    goto v_9926;
v_9927:
    v_10013 = (LispObject)(intptr_t)((intptr_t)v_10014 - (intptr_t)v_10013 + TAG_FIXNUM);
    v_10015 = v_10013;
    goto v_9946;
v_9942:
    v_10014 = v_10015;
    goto v_9943;
v_9944:
    v_10013 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9945;
v_9946:
    goto v_9942;
v_9943:
    goto v_9944;
v_9945:
    if (v_10014 == v_10013) goto v_9940;
    else goto v_9941;
v_9940:
    goto v_9954;
v_9950:
    v_10013 = stack[-2];
    stack[-2] = qcdr(v_10013);
    goto v_9951;
v_9952:
    goto v_9962;
v_9958:
    v_10013 = stack[-1];
    v_10014 = qcdr(v_10013);
    goto v_9959;
v_9960:
    v_10013 = stack[-3];
    goto v_9961;
v_9962:
    goto v_9958;
v_9959:
    goto v_9960;
v_9961:
    fn = elt(env, 3); // multiply!-by!-constant!-mod!-p
    v_10013 = (*qfn2(fn))(fn, v_10014, v_10013);
    env = stack[-4];
    goto v_9953;
v_9954:
    goto v_9950;
v_9951:
    goto v_9952;
v_9953:
    fn = elt(env, 4); // plus!-mod!-p
    v_10013 = (*qfn2(fn))(fn, stack[-2], v_10013);
    env = stack[-4];
    stack[-2] = v_10013;
    goto v_9939;
v_9941:
    goto v_9973;
v_9969:
    v_10013 = stack[-2];
    stack[-2] = qcdr(v_10013);
    goto v_9970;
v_9971:
    goto v_9981;
v_9977:
    goto v_9987;
v_9983:
    goto v_9993;
v_9989:
    v_10013 = stack[-1];
    v_10013 = qcar(v_10013);
    v_10013 = qcar(v_10013);
    v_10013 = qcar(v_10013);
    goto v_9990;
v_9991:
    v_10014 = v_10015;
    goto v_9992;
v_9993:
    goto v_9989;
v_9990:
    goto v_9991;
v_9992:
    fn = elt(env, 5); // mksp
    v_10014 = (*qfn2(fn))(fn, v_10013, v_10014);
    env = stack[-4];
    goto v_9984;
v_9985:
    v_10013 = stack[-3];
    goto v_9986;
v_9987:
    goto v_9983;
v_9984:
    goto v_9985;
v_9986:
    v_10014 = cons(v_10014, v_10013);
    env = stack[-4];
    goto v_9978;
v_9979:
    v_10013 = stack[-1];
    v_10013 = qcdr(v_10013);
    goto v_9980;
v_9981:
    goto v_9977;
v_9978:
    goto v_9979;
v_9980:
    fn = elt(env, 6); // times!-term!-mod!-p
    v_10013 = (*qfn2(fn))(fn, v_10014, v_10013);
    env = stack[-4];
    goto v_9972;
v_9973:
    goto v_9969;
v_9970:
    goto v_9971;
v_9972:
    fn = elt(env, 4); // plus!-mod!-p
    v_10013 = (*qfn2(fn))(fn, stack[-2], v_10013);
    env = stack[-4];
    stack[-2] = v_10013;
    goto v_9939;
v_9939:
    goto v_10009;
v_10003:
    v_10015 = stack[-2];
    goto v_10004;
v_10005:
    v_10014 = stack[-1];
    goto v_10006;
v_10007:
    v_10013 = stack[0];
    goto v_10008;
v_10009:
    goto v_10003;
v_10004:
    goto v_10005;
v_10006:
    goto v_10007;
v_10008:
    stack[-2] = v_10015;
    stack[-1] = v_10014;
    stack[0] = v_10013;
    goto v_9846;
    goto v_9852;
    v_10013 = nil;
v_9852:
    return onevalue(v_10013);
}



// Code for update_kc_list

static LispObject CC_update_kc_list(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_9915, v_9916;
    LispObject fn;
    LispObject v_9849, v_9848, v_9847;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "update_kc_list");
    va_start(aa, nargs);
    v_9847 = va_arg(aa, LispObject);
    v_9848 = va_arg(aa, LispObject);
    v_9849 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_9849,v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_9847,v_9848,v_9849);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_9849;
    stack[-1] = v_9848;
    stack[-2] = v_9847;
// end of prologue
    goto v_9856;
v_9852:
    v_9916 = stack[-1];
    goto v_9853;
v_9854:
    v_9915 = stack[-2];
    v_9915 = qcdr(v_9915);
    goto v_9855;
v_9856:
    goto v_9852;
v_9853:
    goto v_9854;
v_9855:
    fn = elt(env, 1); // list_assoc
    v_9915 = (*qfn2(fn))(fn, v_9916, v_9915);
    env = stack[-4];
    v_9916 = v_9915;
    v_9915 = v_9916;
    if (v_9915 == nil) goto v_9864;
    goto v_9871;
v_9867:
    stack[-3] = v_9916;
    goto v_9868;
v_9869:
    goto v_9878;
v_9874:
    v_9915 = v_9916;
    v_9915 = qcar(v_9915);
    stack[-1] = qcar(v_9915);
    goto v_9875;
v_9876:
    goto v_9887;
v_9883:
    v_9915 = v_9916;
    v_9915 = qcar(v_9915);
    v_9916 = qcdr(v_9915);
    goto v_9884;
v_9885:
    v_9915 = stack[0];
    goto v_9886;
v_9887:
    goto v_9883;
v_9884:
    goto v_9885;
v_9886:
    fn = elt(env, 2); // addf
    v_9915 = (*qfn2(fn))(fn, v_9916, v_9915);
    env = stack[-4];
    goto v_9877;
v_9878:
    goto v_9874;
v_9875:
    goto v_9876;
v_9877:
    v_9915 = cons(stack[-1], v_9915);
    env = stack[-4];
    goto v_9870;
v_9871:
    goto v_9867;
v_9868:
    goto v_9869;
v_9870:
    v_9915 = Lrplaca(nil, stack[-3], v_9915);
    v_9915 = stack[-2];
    goto v_9862;
v_9864:
    goto v_9902;
v_9896:
    v_9915 = stack[-2];
    stack[-3] = qcar(v_9915);
    goto v_9897;
v_9898:
    goto v_9910;
v_9906:
    v_9916 = stack[-1];
    goto v_9907;
v_9908:
    v_9915 = stack[0];
    goto v_9909;
v_9910:
    goto v_9906;
v_9907:
    goto v_9908;
v_9909:
    v_9916 = cons(v_9916, v_9915);
    goto v_9899;
v_9900:
    v_9915 = stack[-2];
    v_9915 = qcdr(v_9915);
    goto v_9901;
v_9902:
    goto v_9896;
v_9897:
    goto v_9898;
v_9899:
    goto v_9900;
v_9901:
    {
        LispObject v_9921 = stack[-3];
        return list2star(v_9921, v_9916, v_9915);
    }
    v_9915 = nil;
v_9862:
    return onevalue(v_9915);
}



// Code for get_action

static LispObject CC_get_action(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9898, v_9899, v_9900, v_9901, v_9902;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9901 = v_9848;
    v_9898 = v_9847;
// end of prologue
    goto v_9859;
v_9855:
    v_9899 = qvalue(elt(env, 1)); // parser_action_table
    goto v_9856;
v_9857:
    goto v_9858;
v_9859:
    goto v_9855;
v_9856:
    goto v_9857;
v_9858:
    v_9898 = *(LispObject *)((char *)v_9899 + (CELL-TAG_VECTOR) + (((intptr_t)v_9898-TAG_FIXNUM)/(16/CELL)));
    v_9899 = v_9898;
    v_9899 = qcar(v_9899);
    v_9902 = v_9899;
    v_9898 = qcdr(v_9898);
    v_9900 = v_9898;
v_9869:
    v_9898 = v_9902;
    if (v_9898 == nil) goto v_9872;
    else goto v_9873;
v_9872:
    goto v_9868;
v_9873:
    goto v_9884;
v_9880:
    v_9898 = v_9902;
    v_9898 = qcar(v_9898);
    v_9899 = qcar(v_9898);
    goto v_9881;
v_9882:
    v_9898 = v_9901;
    goto v_9883;
v_9884:
    goto v_9880;
v_9881:
    goto v_9882;
v_9883:
    if (equal(v_9899, v_9898)) goto v_9878;
    else goto v_9879;
v_9878:
    v_9898 = v_9902;
    v_9898 = qcar(v_9898);
    v_9898 = qcdr(v_9898);
    v_9900 = v_9898;
    v_9898 = nil;
    v_9902 = v_9898;
    goto v_9877;
v_9879:
    v_9898 = v_9902;
    v_9898 = qcdr(v_9898);
    v_9902 = v_9898;
    goto v_9877;
v_9877:
    goto v_9869;
v_9868:
    v_9898 = v_9900;
    return onevalue(v_9898);
}



// Code for mkkl

static LispObject CC_mkkl(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9875, v_9876, v_9877;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_9875 = v_9848;
    v_9876 = v_9847;
// end of prologue
v_9853:
    v_9877 = v_9876;
    if (v_9877 == nil) goto v_9856;
    else goto v_9857;
v_9856:
    goto v_9852;
v_9857:
    v_9877 = v_9876;
    v_9877 = qcdr(v_9877);
    stack[0] = v_9877;
    goto v_9870;
v_9866:
    v_9876 = qcar(v_9876);
    goto v_9867;
v_9868:
    goto v_9869;
v_9870:
    goto v_9866;
v_9867:
    goto v_9868;
v_9869:
    v_9875 = cons(v_9876, v_9875);
    env = stack[-1];
    v_9875 = ncons(v_9875);
    env = stack[-1];
    v_9876 = stack[0];
    goto v_9853;
    v_9875 = nil;
v_9852:
    return onevalue(v_9875);
}



// Code for wureducedpolysp

static LispObject CC_wureducedpolysp(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9883, v_9884;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_9848;
    stack[-1] = v_9847;
// end of prologue
v_9846:
    v_9883 = stack[0];
    if (v_9883 == nil) goto v_9852;
    else goto v_9853;
v_9852:
    v_9883 = lisp_true;
    goto v_9851;
v_9853:
    goto v_9867;
v_9863:
    v_9884 = stack[-1];
    goto v_9864;
v_9865:
    v_9883 = stack[0];
    v_9883 = qcar(v_9883);
    goto v_9866;
v_9867:
    goto v_9863;
v_9864:
    goto v_9865;
v_9866:
    fn = elt(env, 1); // wureducedp
    v_9883 = (*qfn2(fn))(fn, v_9884, v_9883);
    env = stack[-2];
    if (v_9883 == nil) goto v_9860;
    else goto v_9861;
v_9860:
    v_9883 = nil;
    goto v_9859;
v_9861:
    goto v_9879;
v_9875:
    v_9884 = stack[-1];
    goto v_9876;
v_9877:
    v_9883 = stack[0];
    v_9883 = qcdr(v_9883);
    goto v_9878;
v_9879:
    goto v_9875;
v_9876:
    goto v_9877;
v_9878:
    stack[-1] = v_9884;
    stack[0] = v_9883;
    goto v_9846;
    v_9883 = nil;
v_9859:
    goto v_9851;
    v_9883 = nil;
v_9851:
    return onevalue(v_9883);
}



// Code for constsml

static LispObject CC_constsml(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9931, v_9932;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_9847;
// end of prologue
    v_9931 = stack[0];
    if (is_number(v_9931)) goto v_9853;
    else goto v_9854;
v_9853:
    v_9931 = elt(env, 1); // "<cn"
    fn = elt(env, 12); // printout
    v_9931 = (*qfn1(fn))(fn, v_9931);
    env = stack[-1];
    v_9931 = stack[0];
    v_9931 = Lfloatp(nil, v_9931);
    env = stack[-1];
    if (v_9931 == nil) goto v_9861;
    v_9931 = elt(env, 2); // " type=""real""> "
    v_9931 = Lprinc(nil, v_9931);
    env = stack[-1];
    goto v_9859;
v_9861:
    v_9931 = stack[0];
    v_9931 = integerp(v_9931);
    if (v_9931 == nil) goto v_9867;
    v_9931 = elt(env, 3); // " type=""integer""> "
    v_9931 = Lprinc(nil, v_9931);
    env = stack[-1];
    goto v_9859;
v_9867:
    v_9931 = elt(env, 4); // "> "
    v_9931 = Lprinc(nil, v_9931);
    env = stack[-1];
    goto v_9859;
v_9859:
    v_9931 = stack[0];
    v_9931 = Lprinc(nil, v_9931);
    env = stack[-1];
    v_9931 = elt(env, 5); // " </cn>"
    v_9931 = Lprinc(nil, v_9931);
    env = stack[-1];
    goto v_9852;
v_9854:
v_9852:
    v_9931 = stack[0];
    if (symbolp(v_9931)) goto v_9882;
    else goto v_9883;
v_9882:
    goto v_9893;
v_9889:
    v_9931 = stack[0];
    v_9932 = Lintern(nil, v_9931);
    env = stack[-1];
    goto v_9890;
v_9891:
    v_9931 = qvalue(elt(env, 6)); // constants!*
    goto v_9892;
v_9893:
    goto v_9889;
v_9890:
    goto v_9891;
v_9892:
    v_9931 = Lmember(nil, v_9932, v_9931);
    if (v_9931 == nil) goto v_9888;
    v_9931 = elt(env, 7); // "<cn type=""constant""> "
    fn = elt(env, 12); // printout
    v_9931 = (*qfn1(fn))(fn, v_9931);
    env = stack[-1];
    v_9931 = stack[0];
    v_9931 = Lprinc(nil, v_9931);
    env = stack[-1];
    v_9931 = elt(env, 5); // " </cn>"
    v_9931 = Lprinc(nil, v_9931);
    goto v_9886;
v_9888:
    v_9931 = elt(env, 8); // "<ci"
    fn = elt(env, 12); // printout
    v_9931 = (*qfn1(fn))(fn, v_9931);
    env = stack[-1];
    v_9931 = stack[0];
    fn = elt(env, 13); // listp
    v_9931 = (*qfn1(fn))(fn, v_9931);
    env = stack[-1];
    if (v_9931 == nil) goto v_9911;
    v_9931 = elt(env, 9); // " type=""list""> "
    v_9931 = Lprinc(nil, v_9931);
    env = stack[-1];
    goto v_9909;
v_9911:
    v_9931 = stack[0];
    v_9931 = Lsimple_vectorp(nil, v_9931);
    env = stack[-1];
    if (v_9931 == nil) goto v_9917;
    v_9931 = elt(env, 10); // " type=""vector""> "
    v_9931 = Lprinc(nil, v_9931);
    env = stack[-1];
    goto v_9909;
v_9917:
    v_9931 = elt(env, 4); // "> "
    v_9931 = Lprinc(nil, v_9931);
    env = stack[-1];
    goto v_9909;
v_9909:
    v_9931 = stack[0];
    v_9931 = Lprinc(nil, v_9931);
    env = stack[-1];
    v_9931 = elt(env, 11); // " </ci>"
    v_9931 = Lprinc(nil, v_9931);
    goto v_9886;
v_9886:
    goto v_9881;
v_9883:
v_9881:
    v_9931 = nil;
    return onevalue(v_9931);
}



// Code for sacar

static LispObject CC_sacar(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9903, v_9904;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_9848;
    stack[-1] = v_9847;
// end of prologue
    v_9903 = stack[0];
    if (!consp(v_9903)) goto v_9852;
    else goto v_9853;
v_9852:
    v_9903 = nil;
    goto v_9851;
v_9853:
    goto v_9866;
v_9862:
    v_9904 = stack[-1];
    goto v_9863;
v_9864:
    v_9903 = stack[0];
    v_9903 = qcar(v_9903);
    goto v_9865;
v_9866:
    goto v_9862;
v_9863:
    goto v_9864;
v_9865:
    if (v_9904 == v_9903) goto v_9860;
    else goto v_9861;
v_9860:
    v_9903 = stack[0];
    v_9903 = qcdr(v_9903);
    goto v_9859;
v_9861:
    v_9903 = nil;
    goto v_9859;
    v_9903 = nil;
v_9859:
    if (v_9903 == nil) goto v_9857;
    v_9903 = stack[0];
    return ncons(v_9903);
v_9857:
    goto v_9884;
v_9880:
    goto v_9890;
v_9886:
    v_9904 = stack[-1];
    goto v_9887;
v_9888:
    v_9903 = stack[0];
    v_9903 = qcar(v_9903);
    goto v_9889;
v_9890:
    goto v_9886;
v_9887:
    goto v_9888;
v_9889:
    stack[-2] = CC_sacar(elt(env, 0), v_9904, v_9903);
    env = stack[-3];
    goto v_9881;
v_9882:
    goto v_9899;
v_9895:
    v_9904 = stack[-1];
    goto v_9896;
v_9897:
    v_9903 = stack[0];
    v_9903 = qcdr(v_9903);
    goto v_9898;
v_9899:
    goto v_9895;
v_9896:
    goto v_9897;
v_9898:
    v_9903 = CC_sacar(elt(env, 0), v_9904, v_9903);
    goto v_9883;
v_9884:
    goto v_9880;
v_9881:
    goto v_9882;
v_9883:
    {
        LispObject v_9908 = stack[-2];
        return Lappend(nil, v_9908, v_9903);
    }
    v_9903 = nil;
v_9851:
    return onevalue(v_9903);
}



// Code for findnewvars

static LispObject CC_findnewvars(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9917;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_9847;
// end of prologue
    v_9917 = stack[0];
    if (!consp(v_9917)) goto v_9851;
    else goto v_9852;
v_9851:
    v_9917 = stack[0];
    fn = elt(env, 1); // genp
    v_9917 = (*qfn1(fn))(fn, v_9917);
    if (v_9917 == nil) goto v_9857;
    v_9917 = stack[0];
    return ncons(v_9917);
v_9857:
    v_9917 = nil;
    goto v_9855;
    v_9917 = nil;
v_9855:
    goto v_9850;
v_9852:
    v_9917 = stack[0];
    stack[-3] = v_9917;
v_9872:
    v_9917 = stack[-3];
    if (v_9917 == nil) goto v_9877;
    else goto v_9878;
v_9877:
    v_9917 = nil;
    goto v_9871;
v_9878:
    v_9917 = stack[-3];
    v_9917 = qcar(v_9917);
    v_9917 = CC_findnewvars(elt(env, 0), v_9917);
    env = stack[-4];
    stack[-2] = v_9917;
    v_9917 = stack[-2];
    fn = elt(env, 2); // lastpair
    v_9917 = (*qfn1(fn))(fn, v_9917);
    env = stack[-4];
    stack[-1] = v_9917;
    v_9917 = stack[-3];
    v_9917 = qcdr(v_9917);
    stack[-3] = v_9917;
    v_9917 = stack[-1];
    if (!consp(v_9917)) goto v_9892;
    else goto v_9893;
v_9892:
    goto v_9872;
v_9893:
v_9873:
    v_9917 = stack[-3];
    if (v_9917 == nil) goto v_9897;
    else goto v_9898;
v_9897:
    v_9917 = stack[-2];
    goto v_9871;
v_9898:
    goto v_9906;
v_9902:
    stack[0] = stack[-1];
    goto v_9903;
v_9904:
    v_9917 = stack[-3];
    v_9917 = qcar(v_9917);
    v_9917 = CC_findnewvars(elt(env, 0), v_9917);
    env = stack[-4];
    goto v_9905;
v_9906:
    goto v_9902;
v_9903:
    goto v_9904;
v_9905:
    v_9917 = Lrplacd(nil, stack[0], v_9917);
    env = stack[-4];
    v_9917 = stack[-1];
    fn = elt(env, 2); // lastpair
    v_9917 = (*qfn1(fn))(fn, v_9917);
    env = stack[-4];
    stack[-1] = v_9917;
    v_9917 = stack[-3];
    v_9917 = qcdr(v_9917);
    stack[-3] = v_9917;
    goto v_9873;
v_9871:
    goto v_9850;
    v_9917 = nil;
v_9850:
    return onevalue(v_9917);
}



// Code for vbcgcd

static LispObject CC_vbcgcd(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9969, v_9970;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_9848;
    stack[-1] = v_9847;
// end of prologue
    goto v_9866;
v_9862:
    v_9970 = stack[-1];
    goto v_9863;
v_9864:
    v_9969 = (LispObject)-1600+TAG_FIXNUM; // -100
    goto v_9865;
v_9866:
    goto v_9862;
v_9863:
    goto v_9864;
v_9865:
    fn = elt(env, 2); // vbcsize
    v_9969 = (*qfn2(fn))(fn, v_9970, v_9969);
    env = stack[-2];
    if (v_9969 == nil) goto v_9859;
    else goto v_9860;
v_9859:
    v_9969 = lisp_true;
    goto v_9858;
v_9860:
    goto v_9877;
v_9873:
    v_9970 = stack[0];
    goto v_9874;
v_9875:
    v_9969 = (LispObject)-1600+TAG_FIXNUM; // -100
    goto v_9876;
v_9877:
    goto v_9873;
v_9874:
    goto v_9875;
v_9876:
    fn = elt(env, 2); // vbcsize
    v_9969 = (*qfn2(fn))(fn, v_9970, v_9969);
    env = stack[-2];
    v_9969 = (v_9969 == nil ? lisp_true : nil);
    goto v_9858;
    v_9969 = nil;
v_9858:
    if (v_9969 == nil) goto v_9856;
    v_9969 = elt(env, 1); // (1 . 1)
    goto v_9852;
v_9856:
    goto v_9894;
v_9890:
    v_9969 = stack[-1];
    v_9970 = qcdr(v_9969);
    goto v_9891;
v_9892:
    v_9969 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9893;
v_9894:
    goto v_9890;
v_9891:
    goto v_9892;
v_9893:
    if (v_9970 == v_9969) goto v_9888;
    else goto v_9889;
v_9888:
    goto v_9902;
v_9898:
    v_9969 = stack[0];
    v_9970 = qcdr(v_9969);
    goto v_9899;
v_9900:
    v_9969 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9901;
v_9902:
    goto v_9898;
v_9899:
    goto v_9900;
v_9901:
    v_9969 = (v_9970 == v_9969 ? lisp_true : nil);
    goto v_9887;
v_9889:
    v_9969 = nil;
    goto v_9887;
    v_9969 = nil;
v_9887:
    if (v_9969 == nil) goto v_9885;
    v_9969 = stack[-1];
    v_9969 = qcar(v_9969);
    v_9969 = integerp(v_9969);
    if (v_9969 == nil) goto v_9913;
    v_9969 = stack[0];
    v_9969 = qcar(v_9969);
    v_9969 = integerp(v_9969);
    if (v_9969 == nil) goto v_9913;
    goto v_9927;
v_9923:
    goto v_9933;
v_9929:
    v_9969 = stack[-1];
    v_9970 = qcar(v_9969);
    goto v_9930;
v_9931:
    v_9969 = stack[0];
    v_9969 = qcar(v_9969);
    goto v_9932;
v_9933:
    goto v_9929;
v_9930:
    goto v_9931;
v_9932:
    v_9970 = Lgcd(nil, v_9970, v_9969);
    goto v_9924;
v_9925:
    v_9969 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9926;
v_9927:
    goto v_9923;
v_9924:
    goto v_9925;
v_9926:
    return cons(v_9970, v_9969);
v_9913:
    goto v_9946;
v_9942:
    goto v_9952;
v_9948:
    v_9969 = stack[-1];
    v_9970 = qcar(v_9969);
    goto v_9949;
v_9950:
    v_9969 = stack[0];
    v_9969 = qcar(v_9969);
    goto v_9951;
v_9952:
    goto v_9948;
v_9949:
    goto v_9950;
v_9951:
    fn = elt(env, 3); // gcdf!*
    v_9970 = (*qfn2(fn))(fn, v_9970, v_9969);
    goto v_9943;
v_9944:
    v_9969 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9945;
v_9946:
    goto v_9942;
v_9943:
    goto v_9944;
v_9945:
    return cons(v_9970, v_9969);
    v_9969 = nil;
    goto v_9883;
v_9885:
    goto v_9965;
v_9961:
    v_9970 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9962;
v_9963:
    v_9969 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9964;
v_9965:
    goto v_9961;
v_9962:
    goto v_9963;
v_9964:
    return cons(v_9970, v_9969);
    v_9969 = nil;
v_9883:
v_9852:
    return onevalue(v_9969);
}



// Code for vdpred

static LispObject CC_vdpred(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9935, v_9936;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_9847;
// end of prologue
    v_9935 = stack[-3];
    v_9935 = qcdr(v_9935);
    v_9935 = qcdr(v_9935);
    v_9935 = qcdr(v_9935);
    v_9935 = qcar(v_9935);
    v_9935 = qcdr(v_9935);
    v_9935 = qcdr(v_9935);
    stack[-4] = v_9935;
    v_9935 = stack[-4];
    if (v_9935 == nil) goto v_9862;
    else goto v_9863;
v_9862:
    goto v_9874;
v_9866:
    stack[-2] = elt(env, 1); // vdp
    goto v_9867;
v_9868:
    stack[-1] = nil;
    goto v_9869;
v_9870:
    v_9935 = nil;
    stack[0] = ncons(v_9935);
    env = stack[-5];
    goto v_9871;
v_9872:
    goto v_9884;
v_9880:
    v_9936 = nil;
    goto v_9881;
v_9882:
    v_9935 = nil;
    goto v_9883;
v_9884:
    goto v_9880;
v_9881:
    goto v_9882;
v_9883:
    v_9935 = list2(v_9936, v_9935);
    goto v_9873;
v_9874:
    goto v_9866;
v_9867:
    goto v_9868;
v_9869:
    goto v_9870;
v_9871:
    goto v_9872;
v_9873:
    {
        LispObject v_9942 = stack[-2];
        LispObject v_9943 = stack[-1];
        LispObject v_9944 = stack[0];
        return list3star(v_9942, v_9943, v_9944, v_9935);
    }
v_9863:
    goto v_9896;
v_9888:
    stack[-2] = elt(env, 1); // vdp
    goto v_9889;
v_9890:
    v_9935 = stack[-4];
    stack[-1] = qcar(v_9935);
    goto v_9891;
v_9892:
    v_9935 = stack[-4];
    v_9935 = qcdr(v_9935);
    stack[0] = qcar(v_9935);
    goto v_9893;
v_9894:
    goto v_9908;
v_9904:
    v_9936 = stack[-4];
    goto v_9905;
v_9906:
    v_9935 = nil;
    goto v_9907;
v_9908:
    goto v_9904;
v_9905:
    goto v_9906;
v_9907:
    v_9935 = list2(v_9936, v_9935);
    env = stack[-5];
    goto v_9895;
v_9896:
    goto v_9888;
v_9889:
    goto v_9890;
v_9891:
    goto v_9892;
v_9893:
    goto v_9894;
v_9895:
    v_9935 = list3star(stack[-2], stack[-1], stack[0], v_9935);
    env = stack[-5];
    stack[-4] = v_9935;
    v_9935 = qvalue(elt(env, 2)); // !*gsugar
    if (v_9935 == nil) goto v_9914;
    goto v_9923;
v_9919:
    v_9936 = stack[-3];
    goto v_9920;
v_9921:
    v_9935 = elt(env, 3); // sugar
    goto v_9922;
v_9923:
    goto v_9919;
v_9920:
    goto v_9921;
v_9922:
    fn = elt(env, 4); // vdpgetprop
    v_9936 = (*qfn2(fn))(fn, v_9936, v_9935);
    env = stack[-5];
    v_9935 = v_9936;
    if (v_9936 == nil) goto v_9914;
    goto v_9931;
v_9927:
    v_9936 = stack[-4];
    goto v_9928;
v_9929:
    goto v_9930;
v_9931:
    goto v_9927;
v_9928:
    goto v_9929;
v_9930:
    fn = elt(env, 5); // gsetsugar
    v_9935 = (*qfn2(fn))(fn, v_9936, v_9935);
    goto v_9912;
v_9914:
v_9912:
    v_9935 = stack[-4];
    return onevalue(v_9935);
}



// Code for xord_gradlex

static LispObject CC_xord_gradlex(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9905, v_9906;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_9848;
    stack[-1] = v_9847;
// end of prologue
    goto v_9858;
v_9854:
    v_9905 = stack[-1];
    v_9906 = qcar(v_9905);
    goto v_9855;
v_9856:
    v_9905 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9857;
v_9858:
    goto v_9854;
v_9855:
    goto v_9856;
v_9857:
    if (v_9906 == v_9905) goto v_9852;
    else goto v_9853;
v_9852:
    v_9905 = nil;
    goto v_9851;
v_9853:
    goto v_9869;
v_9865:
    v_9905 = stack[0];
    v_9906 = qcar(v_9905);
    goto v_9866;
v_9867:
    v_9905 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9868;
v_9869:
    goto v_9865;
v_9866:
    goto v_9867;
v_9868:
    if (v_9906 == v_9905) goto v_9863;
    else goto v_9864;
v_9863:
    v_9905 = lisp_true;
    goto v_9851;
v_9864:
    goto v_9880;
v_9876:
    v_9905 = stack[-1];
    stack[-2] = Llength(nil, v_9905);
    env = stack[-3];
    goto v_9877;
v_9878:
    v_9905 = stack[0];
    v_9905 = Llength(nil, v_9905);
    env = stack[-3];
    goto v_9879;
v_9880:
    goto v_9876;
v_9877:
    goto v_9878;
v_9879:
    if (equal(stack[-2], v_9905)) goto v_9874;
    else goto v_9875;
v_9874:
    goto v_9890;
v_9886:
    v_9906 = stack[-1];
    goto v_9887;
v_9888:
    v_9905 = stack[0];
    goto v_9889;
v_9890:
    goto v_9886;
v_9887:
    goto v_9888;
v_9889:
    {
        fn = elt(env, 1); // xord_lex
        return (*qfn2(fn))(fn, v_9906, v_9905);
    }
v_9875:
    goto v_9900;
v_9896:
    v_9905 = stack[-1];
    stack[-1] = Llength(nil, v_9905);
    env = stack[-3];
    goto v_9897;
v_9898:
    v_9905 = stack[0];
    v_9905 = Llength(nil, v_9905);
    goto v_9899;
v_9900:
    goto v_9896;
v_9897:
    goto v_9898;
v_9899:
    {
        LispObject v_9910 = stack[-1];
        return Lgreaterp(nil, v_9910, v_9905);
    }
    v_9905 = nil;
v_9851:
    return onevalue(v_9905);
}



// Code for removeindices

static LispObject CC_removeindices(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9990, v_9991;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_9848;
    stack[-3] = v_9847;
// end of prologue
    v_9990 = elt(env, 0); // removeindices
    if (!symbolp(v_9990)) v_9990 = nil;
    else { v_9990 = qfastgets(v_9990);
           if (v_9990 != nil) { v_9990 = elt(v_9990, 53); // tracing
#ifdef RECORD_GET
             if (v_9990 == SPID_NOPROP)
                record_get(elt(fastget_names, 53), 0),
                v_9990 = nil;
             else record_get(elt(fastget_names, 53), 1),
                v_9990 = lisp_true; }
           else record_get(elt(fastget_names, 53), 0); }
#else
             if (v_9990 == SPID_NOPROP) v_9990 = nil; else v_9990 = lisp_true; }}
#endif
    if (v_9990 == nil) goto v_9856;
    goto v_9869;
v_9861:
    stack[-4] = elt(env, 0); // removeindices
    goto v_9862;
v_9863:
    stack[-1] = elt(env, 1); // "u= "
    goto v_9864;
v_9865:
    stack[0] = stack[-3];
    goto v_9866;
v_9867:
    goto v_9878;
v_9874:
    v_9991 = elt(env, 2); // " x= "
    goto v_9875;
v_9876:
    v_9990 = stack[-2];
    goto v_9877;
v_9878:
    goto v_9874;
v_9875:
    goto v_9876;
v_9877:
    v_9990 = list2(v_9991, v_9990);
    env = stack[-5];
    goto v_9868;
v_9869:
    goto v_9861;
v_9862:
    goto v_9863;
v_9864:
    goto v_9865;
v_9866:
    goto v_9867;
v_9868:
    v_9990 = list3star(stack[-4], stack[-1], stack[0], v_9990);
    env = stack[-5];
    fn = elt(env, 4); // trwrite
    v_9990 = (*qfn1(fn))(fn, v_9990);
    env = stack[-5];
    goto v_9854;
v_9856:
v_9854:
    v_9990 = stack[-2];
    if (v_9990 == nil) goto v_9887;
    else goto v_9888;
v_9887:
    v_9990 = lisp_true;
    goto v_9886;
v_9888:
    v_9990 = stack[-3];
    v_9990 = Lsymbolp(nil, v_9990);
    env = stack[-5];
    if (v_9990 == nil) goto v_9895;
    else goto v_9894;
v_9895:
    v_9990 = stack[-3];
    fn = elt(env, 5); // !*physopp
    v_9990 = (*qfn1(fn))(fn, v_9990);
    env = stack[-5];
    v_9990 = (v_9990 == nil ? lisp_true : nil);
v_9894:
    goto v_9886;
    v_9990 = nil;
v_9886:
    if (v_9990 == nil) goto v_9884;
    v_9990 = stack[-3];
    goto v_9852;
v_9884:
    v_9990 = stack[-2];
    if (symbolp(v_9990)) goto v_9907;
    else goto v_9906;
v_9907:
    v_9990 = stack[-2];
    fn = elt(env, 6); // isanindex
    v_9990 = (*qfn1(fn))(fn, v_9990);
    env = stack[-5];
    if (v_9990 == nil) goto v_9909;
    else goto v_9906;
v_9909:
    goto v_9904;
v_9906:
    v_9990 = stack[-2];
    fn = elt(env, 7); // idlistp
    v_9990 = (*qfn1(fn))(fn, v_9990);
    env = stack[-5];
    if (v_9990 == nil) goto v_9912;
    v_9990 = stack[-2];
    fn = elt(env, 8); // areallindices
    v_9990 = (*qfn1(fn))(fn, v_9990);
    env = stack[-5];
    if (v_9990 == nil) goto v_9916;
    else goto v_9912;
v_9916:
    goto v_9904;
v_9912:
    goto v_9905;
v_9904:
    goto v_9924;
v_9920:
    v_9991 = elt(env, 0); // removeindices
    goto v_9921;
v_9922:
    v_9990 = elt(env, 3); // "invalid arguments to removeindices"
    goto v_9923;
v_9924:
    goto v_9920;
v_9921:
    goto v_9922;
v_9923:
    fn = elt(env, 9); // rederr2
    v_9990 = (*qfn2(fn))(fn, v_9991, v_9990);
    env = stack[-5];
    goto v_9903;
v_9905:
v_9903:
    v_9990 = stack[-3];
    v_9990 = qcar(v_9990);
    stack[0] = v_9990;
    v_9990 = stack[-3];
    v_9990 = qcdr(v_9990);
    stack[-3] = v_9990;
    v_9990 = stack[-3];
    if (v_9990 == nil) goto v_9933;
    else goto v_9934;
v_9933:
    v_9990 = stack[0];
    goto v_9852;
v_9934:
    v_9990 = stack[-2];
    if (symbolp(v_9990)) goto v_9937;
    else goto v_9938;
v_9937:
    goto v_9945;
v_9941:
    v_9991 = stack[-2];
    goto v_9942;
v_9943:
    v_9990 = stack[-3];
    goto v_9944;
v_9945:
    goto v_9941;
v_9942:
    goto v_9943;
v_9944:
    v_9990 = Ldelete(nil, v_9991, v_9990);
    stack[-3] = v_9990;
    goto v_9932;
v_9938:
    v_9990 = stack[-2];
    stack[-1] = v_9990;
v_9953:
    v_9990 = stack[-1];
    if (v_9990 == nil) goto v_9957;
    else goto v_9958;
v_9957:
    goto v_9952;
v_9958:
    v_9990 = stack[-1];
    v_9990 = qcar(v_9990);
    goto v_9969;
v_9965:
    v_9991 = v_9990;
    goto v_9966;
v_9967:
    v_9990 = stack[-3];
    goto v_9968;
v_9969:
    goto v_9965;
v_9966:
    goto v_9967;
v_9968:
    v_9990 = Ldelete(nil, v_9991, v_9990);
    env = stack[-5];
    stack[-3] = v_9990;
    v_9990 = stack[-1];
    v_9990 = qcdr(v_9990);
    stack[-1] = v_9990;
    goto v_9953;
v_9952:
    goto v_9932;
v_9932:
    v_9990 = stack[-3];
    if (v_9990 == nil) goto v_9976;
    else goto v_9977;
v_9976:
    v_9990 = stack[0];
    goto v_9975;
v_9977:
    goto v_9987;
v_9983:
    v_9991 = stack[0];
    goto v_9984;
v_9985:
    v_9990 = stack[-3];
    goto v_9986;
v_9987:
    goto v_9983;
v_9984:
    goto v_9985;
v_9986:
    return cons(v_9991, v_9990);
    v_9990 = nil;
v_9975:
v_9852:
    return onevalue(v_9990);
}



// Code for qcputx

static LispObject CC_qcputx(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9891, v_9892, v_9893;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_9892 = v_9847;
// end of prologue
    goto v_9858;
v_9854:
    v_9893 = v_9892;
    goto v_9855;
v_9856:
    v_9891 = elt(env, 1); // quote
    goto v_9857;
v_9858:
    goto v_9854;
v_9855:
    goto v_9856;
v_9857:
    if (!consp(v_9893)) goto v_9852;
    v_9893 = qcar(v_9893);
    if (v_9893 == v_9891) goto v_9851;
    else goto v_9852;
v_9851:
    goto v_9870;
v_9866:
    v_9891 = v_9892;
    v_9891 = qcdr(v_9891);
    v_9893 = qcar(v_9891);
    goto v_9867;
v_9868:
    v_9891 = elt(env, 2); // cref
    goto v_9869;
v_9870:
    goto v_9866;
v_9867:
    goto v_9868;
v_9869:
    v_9891 = Lflagp(nil, v_9893, v_9891);
    env = stack[0];
    if (v_9891 == nil) goto v_9864;
    v_9891 = lisp_true;
    goto v_9862;
v_9864:
    goto v_9883;
v_9879:
    v_9891 = v_9892;
    v_9891 = qcdr(v_9891);
    v_9891 = qcar(v_9891);
    goto v_9880;
v_9881:
    v_9892 = elt(env, 3); // compile
    goto v_9882;
v_9883:
    goto v_9879;
v_9880:
    goto v_9881;
v_9882:
        return Lflagp(nil, v_9891, v_9892);
    v_9891 = nil;
v_9862:
    goto v_9850;
v_9852:
    v_9891 = nil;
    goto v_9850;
    v_9891 = nil;
v_9850:
    return onevalue(v_9891);
}



// Code for prepreform

static LispObject CC_prepreform(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9864, v_9865;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_9864 = v_9847;
// end of prologue
    goto v_9854;
v_9850:
    stack[0] = v_9864;
    goto v_9851;
v_9852:
    goto v_9861;
v_9857:
    v_9865 = qvalue(elt(env, 1)); // ordl!*
    goto v_9858;
v_9859:
    v_9864 = qvalue(elt(env, 2)); // factors!*
    goto v_9860;
v_9861:
    goto v_9857;
v_9858:
    goto v_9859;
v_9860:
    v_9864 = Lappend(nil, v_9865, v_9864);
    env = stack[-1];
    goto v_9853;
v_9854:
    goto v_9850;
v_9851:
    goto v_9852;
v_9853:
    {
        LispObject v_9867 = stack[0];
        fn = elt(env, 3); // prepreform1
        return (*qfn2(fn))(fn, v_9867, v_9864);
    }
}



// Code for findremainder

static LispObject CC_findremainder(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9882, v_9883, v_9884;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_9882 = v_9848;
    v_9883 = v_9847;
// end of prologue
    stack[0] = v_9882;
v_9853:
    v_9882 = stack[0];
    if (v_9882 == nil) goto v_9857;
    else goto v_9858;
v_9857:
    goto v_9852;
v_9858:
    v_9882 = stack[0];
    v_9882 = qcar(v_9882);
    goto v_9871;
v_9865:
    v_9884 = v_9883;
    goto v_9866;
v_9867:
    v_9883 = v_9882;
    goto v_9868;
v_9869:
    v_9882 = qcar(v_9882);
    v_9882 = qcar(v_9882);
    v_9882 = qcar(v_9882);
    goto v_9870;
v_9871:
    goto v_9865;
v_9866:
    goto v_9867;
v_9868:
    goto v_9869;
v_9870:
    fn = elt(env, 1); // wupseudodivide
    v_9882 = (*qfnn(fn))(fn, 3, v_9884, v_9883, v_9882);
    env = stack[-1];
    v_9882 = qcdr(v_9882);
    v_9883 = v_9882;
    v_9882 = stack[0];
    v_9882 = qcdr(v_9882);
    stack[0] = v_9882;
    goto v_9853;
v_9852:
    v_9882 = v_9883;
    return onevalue(v_9882);
}



// Code for talp_eqtp

static LispObject CC_talp_eqtp(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9939, v_9940;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_9848;
    stack[-1] = v_9847;
// end of prologue
v_9852:
    v_9939 = stack[-1];
    if (!consp(v_9939)) goto v_9859;
    else goto v_9860;
v_9859:
    v_9939 = lisp_true;
    goto v_9858;
v_9860:
    v_9939 = stack[0];
    v_9939 = (consp(v_9939) ? nil : lisp_true);
    goto v_9858;
    v_9939 = nil;
v_9858:
    if (v_9939 == nil) goto v_9856;
    goto v_9875;
v_9871:
    v_9940 = stack[-1];
    goto v_9872;
v_9873:
    v_9939 = stack[0];
    goto v_9874;
v_9875:
    goto v_9871;
v_9872:
    goto v_9873;
v_9874:
    if (v_9940 == v_9939) goto v_9869;
    else goto v_9870;
v_9869:
    v_9939 = lisp_true;
    goto v_9851;
v_9870:
    v_9939 = nil;
    goto v_9851;
    goto v_9854;
v_9856:
    v_9939 = stack[-1];
    v_9939 = qcar(v_9939);
    if (!consp(v_9939)) goto v_9886;
    else goto v_9887;
v_9886:
    v_9939 = stack[0];
    v_9939 = qcar(v_9939);
    v_9939 = (consp(v_9939) ? nil : lisp_true);
    goto v_9885;
v_9887:
    v_9939 = nil;
    goto v_9885;
    v_9939 = nil;
v_9885:
    if (v_9939 == nil) goto v_9883;
    goto v_9904;
v_9900:
    v_9939 = stack[-1];
    v_9940 = qcar(v_9939);
    goto v_9901;
v_9902:
    v_9939 = stack[0];
    v_9939 = qcar(v_9939);
    goto v_9903;
v_9904:
    goto v_9900;
v_9901:
    goto v_9902;
v_9903:
    if (v_9940 == v_9939) goto v_9898;
    else goto v_9899;
v_9898:
    v_9939 = stack[-1];
    v_9939 = qcdr(v_9939);
    stack[-1] = v_9939;
    v_9939 = stack[0];
    v_9939 = qcdr(v_9939);
    stack[0] = v_9939;
    goto v_9852;
v_9899:
    v_9939 = nil;
    goto v_9851;
    goto v_9854;
v_9883:
    goto v_9927;
v_9923:
    v_9939 = stack[-1];
    v_9940 = qcar(v_9939);
    goto v_9924;
v_9925:
    v_9939 = stack[0];
    v_9939 = qcar(v_9939);
    goto v_9926;
v_9927:
    goto v_9923;
v_9924:
    goto v_9925;
v_9926:
    v_9939 = CC_talp_eqtp(elt(env, 0), v_9940, v_9939);
    env = stack[-2];
    if (v_9939 == nil) goto v_9921;
    v_9939 = stack[-1];
    v_9939 = qcdr(v_9939);
    stack[-1] = v_9939;
    v_9939 = stack[0];
    v_9939 = qcdr(v_9939);
    stack[0] = v_9939;
    goto v_9852;
v_9921:
    v_9939 = nil;
    goto v_9851;
    goto v_9854;
v_9854:
    v_9939 = nil;
v_9851:
    return onevalue(v_9939);
}



// Code for qqe_number!-of!-adds!-in!-qterm

static LispObject CC_qqe_numberKofKaddsKinKqterm(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9877, v_9878;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_9847;
// end of prologue
v_9851:
    v_9877 = stack[0];
    if (!consp(v_9877)) goto v_9854;
    else goto v_9855;
v_9854:
    v_9877 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9850;
v_9855:
    goto v_9864;
v_9860:
    v_9877 = stack[0];
    fn = elt(env, 2); // qqe_op
    v_9878 = (*qfn1(fn))(fn, v_9877);
    env = stack[-1];
    goto v_9861;
v_9862:
    v_9877 = elt(env, 1); // (ladd radd)
    goto v_9863;
v_9864:
    goto v_9860;
v_9861:
    goto v_9862;
v_9863:
    v_9877 = Lmemq(nil, v_9878, v_9877);
    if (v_9877 == nil) goto v_9859;
    v_9877 = stack[0];
    fn = elt(env, 3); // qqe_arg2r
    v_9877 = (*qfn1(fn))(fn, v_9877);
    env = stack[-1];
    v_9877 = CC_qqe_numberKofKaddsKinKqterm(elt(env, 0), v_9877);
    return add1(v_9877);
v_9859:
    v_9877 = stack[0];
    fn = elt(env, 4); // qqe_arg2l
    v_9877 = (*qfn1(fn))(fn, v_9877);
    env = stack[-1];
    stack[0] = v_9877;
    goto v_9851;
    v_9877 = nil;
v_9850:
    return onevalue(v_9877);
}



// Code for ibalp_initwl

static LispObject CC_ibalp_initwl(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_10087, v_10088;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_10087 = v_9847;
// end of prologue
    stack[-4] = nil;
    stack[-2] = v_10087;
v_9857:
    v_10087 = stack[-2];
    if (v_10087 == nil) goto v_9861;
    else goto v_9862;
v_9861:
    goto v_9856;
v_9862:
    v_10087 = stack[-2];
    v_10087 = qcar(v_10087);
    stack[-1] = v_10087;
    v_10087 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_10087;
    v_10087 = stack[-1];
    v_10087 = qcar(v_10087);
    stack[-3] = v_10087;
v_9873:
    goto v_9887;
v_9883:
    v_10088 = stack[-5];
    goto v_9884;
v_9885:
    v_10087 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_9886;
v_9887:
    goto v_9883;
v_9884:
    goto v_9885;
v_9886:
    v_10087 = Leqn(nil, v_10088, v_10087);
    env = stack[-6];
    if (v_10087 == nil) goto v_9880;
    else goto v_9881;
v_9880:
    v_10087 = stack[-3];
    goto v_9879;
v_9881:
    v_10087 = nil;
    goto v_9879;
    v_10087 = nil;
v_9879:
    if (v_10087 == nil) goto v_9876;
    else goto v_9877;
v_9876:
    goto v_9872;
v_9877:
    goto v_9900;
v_9896:
    v_10087 = stack[-1];
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    stack[0] = qcdr(v_10087);
    goto v_9897;
v_9898:
    goto v_9913;
v_9909:
    v_10087 = stack[-3];
    v_10088 = qcar(v_10087);
    goto v_9910;
v_9911:
    v_10087 = stack[-1];
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcar(v_10087);
    goto v_9912;
v_9913:
    goto v_9909;
v_9910:
    goto v_9911;
v_9912:
    v_10087 = cons(v_10088, v_10087);
    env = stack[-6];
    goto v_9899;
v_9900:
    goto v_9896;
v_9897:
    goto v_9898;
v_9899:
    fn = elt(env, 1); // setcar
    v_10087 = (*qfn2(fn))(fn, stack[0], v_10087);
    env = stack[-6];
    goto v_9929;
v_9925:
    v_10087 = stack[-3];
    v_10087 = qcar(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    stack[0] = qcdr(v_10087);
    goto v_9926;
v_9927:
    goto v_9947;
v_9943:
    v_10088 = stack[-1];
    goto v_9944;
v_9945:
    v_10087 = stack[-3];
    v_10087 = qcar(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcar(v_10087);
    goto v_9946;
v_9947:
    goto v_9943;
v_9944:
    goto v_9945;
v_9946:
    v_10087 = cons(v_10088, v_10087);
    env = stack[-6];
    goto v_9928;
v_9929:
    goto v_9925;
v_9926:
    goto v_9927;
v_9928:
    fn = elt(env, 1); // setcar
    v_10087 = (*qfn2(fn))(fn, stack[0], v_10087);
    env = stack[-6];
    v_10087 = stack[-5];
    v_10087 = add1(v_10087);
    env = stack[-6];
    stack[-5] = v_10087;
    v_10087 = stack[-3];
    v_10087 = qcdr(v_10087);
    stack[-3] = v_10087;
    goto v_9873;
v_9872:
    v_10087 = stack[-1];
    v_10087 = qcdr(v_10087);
    v_10087 = qcar(v_10087);
    stack[-3] = v_10087;
v_9971:
    goto v_9985;
v_9981:
    v_10088 = stack[-5];
    goto v_9982;
v_9983:
    v_10087 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_9984;
v_9985:
    goto v_9981;
v_9982:
    goto v_9983;
v_9984:
    v_10087 = Leqn(nil, v_10088, v_10087);
    env = stack[-6];
    if (v_10087 == nil) goto v_9978;
    else goto v_9979;
v_9978:
    v_10087 = stack[-3];
    goto v_9977;
v_9979:
    v_10087 = nil;
    goto v_9977;
    v_10087 = nil;
v_9977:
    if (v_10087 == nil) goto v_9974;
    else goto v_9975;
v_9974:
    goto v_9970;
v_9975:
    goto v_9998;
v_9994:
    v_10087 = stack[-1];
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    stack[0] = qcdr(v_10087);
    goto v_9995;
v_9996:
    goto v_10011;
v_10007:
    v_10087 = stack[-3];
    v_10088 = qcar(v_10087);
    goto v_10008;
v_10009:
    v_10087 = stack[-1];
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcar(v_10087);
    goto v_10010;
v_10011:
    goto v_10007;
v_10008:
    goto v_10009;
v_10010:
    v_10087 = cons(v_10088, v_10087);
    env = stack[-6];
    goto v_9997;
v_9998:
    goto v_9994;
v_9995:
    goto v_9996;
v_9997:
    fn = elt(env, 1); // setcar
    v_10087 = (*qfn2(fn))(fn, stack[0], v_10087);
    env = stack[-6];
    goto v_10027;
v_10023:
    v_10087 = stack[-3];
    v_10087 = qcar(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    stack[0] = qcdr(v_10087);
    goto v_10024;
v_10025:
    goto v_10045;
v_10041:
    v_10088 = stack[-1];
    goto v_10042;
v_10043:
    v_10087 = stack[-3];
    v_10087 = qcar(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcdr(v_10087);
    v_10087 = qcar(v_10087);
    goto v_10044;
v_10045:
    goto v_10041;
v_10042:
    goto v_10043;
v_10044:
    v_10087 = cons(v_10088, v_10087);
    env = stack[-6];
    goto v_10026;
v_10027:
    goto v_10023;
v_10024:
    goto v_10025;
v_10026:
    fn = elt(env, 1); // setcar
    v_10087 = (*qfn2(fn))(fn, stack[0], v_10087);
    env = stack[-6];
    v_10087 = stack[-5];
    v_10087 = add1(v_10087);
    env = stack[-6];
    stack[-5] = v_10087;
    v_10087 = stack[-3];
    v_10087 = qcdr(v_10087);
    stack[-3] = v_10087;
    goto v_9971;
v_9970:
    goto v_10073;
v_10069:
    v_10088 = stack[-5];
    goto v_10070;
v_10071:
    v_10087 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10072;
v_10073:
    goto v_10069;
v_10070:
    goto v_10071;
v_10072:
    v_10087 = (LispObject)lessp2(v_10088, v_10087);
    v_10087 = v_10087 ? lisp_true : nil;
    env = stack[-6];
    if (v_10087 == nil) goto v_10067;
    goto v_10081;
v_10077:
    v_10088 = stack[-1];
    goto v_10078;
v_10079:
    v_10087 = stack[-4];
    goto v_10080;
v_10081:
    goto v_10077;
v_10078:
    goto v_10079;
v_10080:
    v_10087 = cons(v_10088, v_10087);
    env = stack[-6];
    stack[-4] = v_10087;
    goto v_10065;
v_10067:
v_10065:
    v_10087 = stack[-2];
    v_10087 = qcdr(v_10087);
    stack[-2] = v_10087;
    goto v_9857;
v_9856:
    v_10087 = stack[-4];
    return onevalue(v_10087);
}



// Code for cgp_number

static LispObject CC_cgp_number(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9857, v_9858;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9857 = v_9847;
// end of prologue
    goto v_9854;
v_9850:
    v_9858 = v_9857;
    goto v_9851;
v_9852:
    v_9857 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_9853;
v_9854:
    goto v_9850;
v_9851:
    goto v_9852;
v_9853:
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(fn, v_9858, v_9857);
    }
}



// Code for nary

static LispObject CC_nary(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9914, v_9915;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_9848;
    stack[-1] = v_9847;
// end of prologue
    goto v_9864;
v_9860:
    v_9914 = stack[-1];
    v_9915 = qcar(v_9914);
    goto v_9861;
v_9862:
    v_9914 = elt(env, 1); // e
    goto v_9863;
v_9864:
    goto v_9860;
v_9861:
    goto v_9862;
v_9863:
    if (v_9915 == v_9914) goto v_9858;
    else goto v_9859;
v_9858:
    goto v_9872;
v_9868:
    v_9915 = stack[0];
    goto v_9869;
v_9870:
    v_9914 = elt(env, 2); // power
    goto v_9871;
v_9872:
    goto v_9868;
v_9869:
    goto v_9870;
v_9871:
    v_9914 = (v_9915 == v_9914 ? lisp_true : nil);
    goto v_9857;
v_9859:
    v_9914 = nil;
    goto v_9857;
    v_9914 = nil;
v_9857:
    if (v_9914 == nil) goto v_9855;
    goto v_9884;
v_9880:
    v_9914 = stack[-1];
    v_9915 = qcdr(v_9914);
    goto v_9881;
v_9882:
    v_9914 = elt(env, 3); // exp
    goto v_9883;
v_9884:
    goto v_9880;
v_9881:
    goto v_9882;
v_9883:
    fn = elt(env, 8); // unary
    v_9914 = (*qfn2(fn))(fn, v_9915, v_9914);
    goto v_9853;
v_9855:
    v_9914 = elt(env, 4); // "<apply>"
    fn = elt(env, 9); // printout
    v_9914 = (*qfn1(fn))(fn, v_9914);
    env = stack[-2];
    v_9914 = elt(env, 5); // "<"
    v_9914 = Lprinc(nil, v_9914);
    env = stack[-2];
    v_9914 = stack[0];
    v_9914 = Lprinc(nil, v_9914);
    env = stack[-2];
    goto v_9901;
v_9897:
    v_9914 = stack[-1];
    v_9915 = qcar(v_9914);
    goto v_9898;
v_9899:
    v_9914 = elt(env, 6); // "/"
    goto v_9900;
v_9901:
    goto v_9897;
v_9898:
    goto v_9899;
v_9900:
    fn = elt(env, 10); // attributesml
    v_9914 = (*qfn2(fn))(fn, v_9915, v_9914);
    env = stack[-2];
    v_9914 = lisp_true;
    fn = elt(env, 11); // indent!*
    v_9914 = (*qfn1(fn))(fn, v_9914);
    env = stack[-2];
    v_9914 = stack[-1];
    v_9914 = qcdr(v_9914);
    fn = elt(env, 12); // multi_elem
    v_9914 = (*qfn1(fn))(fn, v_9914);
    env = stack[-2];
    v_9914 = nil;
    fn = elt(env, 11); // indent!*
    v_9914 = (*qfn1(fn))(fn, v_9914);
    env = stack[-2];
    v_9914 = elt(env, 7); // "</apply>"
    fn = elt(env, 9); // printout
    v_9914 = (*qfn1(fn))(fn, v_9914);
    goto v_9853;
v_9853:
    v_9914 = nil;
    return onevalue(v_9914);
}



// Code for spband_matrix

static LispObject CC_spband_matrix(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_10125, v_10126, v_10127;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-7] = v_9848;
    stack[-8] = v_9847;
// end of prologue
    goto v_9868;
v_9864:
    stack[0] = stack[-7];
    goto v_9865;
v_9866:
    goto v_9877;
v_9871:
    v_10127 = elt(env, 1); // spm
    goto v_9872;
v_9873:
    v_10126 = stack[-7];
    goto v_9874;
v_9875:
    v_10125 = stack[-7];
    goto v_9876;
v_9877:
    goto v_9871;
v_9872:
    goto v_9873;
v_9874:
    goto v_9875;
v_9876:
    v_10125 = list3(v_10127, v_10126, v_10125);
    env = stack[-10];
    goto v_9867;
v_9868:
    goto v_9864;
v_9865:
    goto v_9866;
v_9867:
    fn = elt(env, 8); // mkempspmat
    v_10125 = (*qfn2(fn))(fn, stack[0], v_10125);
    env = stack[-10];
    stack[-9] = v_10125;
    v_10125 = stack[-7];
    v_10125 = integerp(v_10125);
    if (v_10125 == nil) goto v_9883;
    else goto v_9884;
v_9883:
    v_10125 = elt(env, 2); // "Error in spband_matrix(second argument): should be an integer."
    fn = elt(env, 9); // rederr
    v_10125 = (*qfn1(fn))(fn, v_10125);
    env = stack[-10];
    goto v_9882;
v_9884:
v_9882:
    v_10125 = stack[-8];
    if (!consp(v_10125)) goto v_9891;
    else goto v_9892;
v_9891:
    v_10125 = stack[-8];
    v_10125 = ncons(v_10125);
    env = stack[-10];
    stack[-8] = v_10125;
    goto v_9890;
v_9892:
    goto v_9902;
v_9898:
    v_10125 = stack[-8];
    v_10126 = qcar(v_10125);
    goto v_9899;
v_9900:
    v_10125 = elt(env, 3); // list
    goto v_9901;
v_9902:
    goto v_9898;
v_9899:
    goto v_9900;
v_9901:
    if (v_10126 == v_10125) goto v_9896;
    else goto v_9897;
v_9896:
    v_10125 = stack[-8];
    v_10125 = qcdr(v_10125);
    stack[-8] = v_10125;
    goto v_9890;
v_9897:
    v_10125 = elt(env, 4); // "Error in spband_matrix(first argument): should be single value or list."
    fn = elt(env, 9); // rederr
    v_10125 = (*qfn1(fn))(fn, v_10125);
    env = stack[-10];
    goto v_9890;
v_9890:
    v_10125 = stack[-8];
    v_10125 = Llength(nil, v_10125);
    env = stack[-10];
    stack[-4] = v_10125;
    v_10125 = stack[-4];
    v_10125 = Levenp(nil, v_10125);
    env = stack[-10];
    if (v_10125 == nil) goto v_9917;
    v_10125 = elt(env, 5); // "Error in spband matrix(first argument): number of elements must be odd."
    fn = elt(env, 9); // rederr
    v_10125 = (*qfn1(fn))(fn, v_10125);
    env = stack[-10];
    goto v_9915;
v_9917:
v_9915:
    goto v_9930;
v_9924:
    stack[0] = elt(env, 6); // quotient
    goto v_9925;
v_9926:
    v_10125 = stack[-4];
    v_10126 = add1(v_10125);
    env = stack[-10];
    goto v_9927;
v_9928:
    v_10125 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_9929;
v_9930:
    goto v_9924;
v_9925:
    goto v_9926;
v_9927:
    goto v_9928;
v_9929:
    v_10125 = list3(stack[0], v_10126, v_10125);
    env = stack[-10];
    fn = elt(env, 10); // reval
    v_10125 = (*qfn1(fn))(fn, v_10125);
    env = stack[-10];
    stack[-3] = v_10125;
    goto v_9944;
v_9940:
    v_10125 = stack[-3];
    v_10125 = integerp(v_10125);
    if (v_10125 == nil) goto v_9948;
    v_10125 = stack[-3];
    v_10126 = v_10125;
    goto v_9946;
v_9948:
    v_10125 = stack[-3];
    fn = elt(env, 10); // reval
    v_10125 = (*qfn1(fn))(fn, v_10125);
    env = stack[-10];
    v_10126 = v_10125;
    goto v_9946;
    v_10126 = nil;
v_9946:
    goto v_9941;
v_9942:
    v_10125 = stack[-7];
    goto v_9943;
v_9944:
    goto v_9940;
v_9941:
    goto v_9942;
v_9943:
    v_10125 = (LispObject)greaterp2(v_10126, v_10125);
    v_10125 = v_10125 ? lisp_true : nil;
    env = stack[-10];
    if (v_10125 == nil) goto v_9938;
    v_10125 = elt(env, 7); // "Error in spband_matrix: too many elements. Band matrix is overflowing."
    fn = elt(env, 9); // rederr
    v_10125 = (*qfn1(fn))(fn, v_10125);
    env = stack[-10];
    goto v_9936;
v_9938:
v_9936:
    v_10125 = (LispObject)32+TAG_FIXNUM; // 2
    stack[-5] = v_10125;
    v_10125 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_10125;
v_9963:
    goto v_9975;
v_9971:
    v_10126 = stack[-7];
    goto v_9972;
v_9973:
    v_10125 = stack[-2];
    goto v_9974;
v_9975:
    goto v_9971;
v_9972:
    goto v_9973;
v_9974:
    v_10125 = difference2(v_10126, v_10125);
    env = stack[-10];
    v_10125 = Lminusp(nil, v_10125);
    env = stack[-10];
    if (v_10125 == nil) goto v_9968;
    goto v_9962;
v_9968:
    goto v_9988;
v_9984:
    v_10126 = stack[-2];
    goto v_9985;
v_9986:
    v_10125 = stack[-3];
    goto v_9987;
v_9988:
    goto v_9984;
v_9985:
    goto v_9986;
v_9987:
    v_10125 = (LispObject)lesseq2(v_10126, v_10125);
    v_10125 = v_10125 ? lisp_true : nil;
    env = stack[-10];
    if (v_10125 == nil) goto v_9982;
    v_10125 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_10125;
    goto v_9980;
v_9982:
    v_10125 = stack[-5];
    stack[-6] = v_10125;
    goto v_9980;
v_9980:
v_9997:
    goto v_10008;
v_10004:
    goto v_10014;
v_10010:
    goto v_10020;
v_10016:
    v_10126 = stack[-3];
    goto v_10017;
v_10018:
    v_10125 = stack[-2];
    goto v_10019;
v_10020:
    goto v_10016;
v_10017:
    goto v_10018;
v_10019:
    v_10126 = difference2(v_10126, v_10125);
    env = stack[-10];
    goto v_10011;
v_10012:
    v_10125 = stack[-6];
    goto v_10013;
v_10014:
    goto v_10010;
v_10011:
    goto v_10012;
v_10013:
    v_10126 = plus2(v_10126, v_10125);
    env = stack[-10];
    goto v_10005;
v_10006:
    v_10125 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10007;
v_10008:
    goto v_10004;
v_10005:
    goto v_10006;
v_10007:
    v_10125 = (LispObject)greaterp2(v_10126, v_10125);
    v_10125 = v_10125 ? lisp_true : nil;
    env = stack[-10];
    if (v_10125 == nil) goto v_10000;
    goto v_10032;
v_10028:
    v_10126 = stack[-6];
    goto v_10029;
v_10030:
    v_10125 = stack[-7];
    goto v_10031;
v_10032:
    goto v_10028;
v_10029:
    goto v_10030;
v_10031:
    v_10125 = (LispObject)lesseq2(v_10126, v_10125);
    v_10125 = v_10125 ? lisp_true : nil;
    env = stack[-10];
    if (v_10125 == nil) goto v_10000;
    goto v_10041;
v_10037:
    goto v_10047;
v_10043:
    goto v_10053;
v_10049:
    v_10126 = stack[-3];
    goto v_10050;
v_10051:
    v_10125 = stack[-2];
    goto v_10052;
v_10053:
    goto v_10049;
v_10050:
    goto v_10051;
v_10052:
    v_10126 = difference2(v_10126, v_10125);
    env = stack[-10];
    goto v_10044;
v_10045:
    v_10125 = stack[-6];
    goto v_10046;
v_10047:
    goto v_10043;
v_10044:
    goto v_10045;
v_10046:
    v_10126 = plus2(v_10126, v_10125);
    env = stack[-10];
    goto v_10038;
v_10039:
    v_10125 = stack[-4];
    goto v_10040;
v_10041:
    goto v_10037;
v_10038:
    goto v_10039;
v_10040:
    v_10125 = (LispObject)lesseq2(v_10126, v_10125);
    v_10125 = v_10125 ? lisp_true : nil;
    env = stack[-10];
    if (v_10125 == nil) goto v_10000;
    goto v_10001;
v_10000:
    goto v_9996;
v_10001:
    goto v_10068;
v_10060:
    goto v_10076;
v_10070:
    v_10127 = stack[-9];
    goto v_10071;
v_10072:
    v_10126 = stack[-2];
    goto v_10073;
v_10074:
    v_10125 = stack[-6];
    goto v_10075;
v_10076:
    goto v_10070;
v_10071:
    goto v_10072;
v_10073:
    goto v_10074;
v_10075:
    stack[-1] = list3(v_10127, v_10126, v_10125);
    env = stack[-10];
    goto v_10061;
v_10062:
    goto v_10085;
v_10081:
    stack[0] = stack[-8];
    goto v_10082;
v_10083:
    goto v_10092;
v_10088:
    goto v_10098;
v_10094:
    v_10126 = stack[-3];
    goto v_10095;
v_10096:
    v_10125 = stack[-2];
    goto v_10097;
v_10098:
    goto v_10094;
v_10095:
    goto v_10096;
v_10097:
    v_10126 = difference2(v_10126, v_10125);
    env = stack[-10];
    goto v_10089;
v_10090:
    v_10125 = stack[-6];
    goto v_10091;
v_10092:
    goto v_10088;
v_10089:
    goto v_10090;
v_10091:
    v_10125 = plus2(v_10126, v_10125);
    env = stack[-10];
    goto v_10084;
v_10085:
    goto v_10081;
v_10082:
    goto v_10083;
v_10084:
    fn = elt(env, 11); // nth
    v_10127 = (*qfn2(fn))(fn, stack[0], v_10125);
    env = stack[-10];
    goto v_10063;
v_10064:
    v_10126 = stack[-9];
    goto v_10065;
v_10066:
    v_10125 = nil;
    goto v_10067;
v_10068:
    goto v_10060;
v_10061:
    goto v_10062;
v_10063:
    goto v_10064;
v_10065:
    goto v_10066;
v_10067:
    fn = elt(env, 12); // letmtr3
    v_10125 = (*qfnn(fn))(fn, 4, stack[-1], v_10127, v_10126, v_10125);
    env = stack[-10];
    v_10125 = stack[-6];
    v_10125 = add1(v_10125);
    env = stack[-10];
    stack[-6] = v_10125;
    goto v_9997;
v_9996:
    goto v_10116;
v_10112:
    v_10126 = stack[-2];
    goto v_10113;
v_10114:
    v_10125 = stack[-3];
    goto v_10115;
v_10116:
    goto v_10112;
v_10113:
    goto v_10114;
v_10115:
    v_10125 = (LispObject)greaterp2(v_10126, v_10125);
    v_10125 = v_10125 ? lisp_true : nil;
    env = stack[-10];
    if (v_10125 == nil) goto v_10110;
    v_10125 = stack[-5];
    v_10125 = add1(v_10125);
    env = stack[-10];
    stack[-5] = v_10125;
    goto v_10108;
v_10110:
v_10108:
    v_10125 = stack[-2];
    v_10125 = add1(v_10125);
    env = stack[-10];
    stack[-2] = v_10125;
    goto v_9963;
v_9962:
    v_10125 = stack[-9];
    return onevalue(v_10125);
}



// Code for inshisto

static LispObject CC_inshisto(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_10011, v_10012, v_10013;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_9847;
// end of prologue
    goto v_9858;
v_9854:
    goto v_9863;
v_9859:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_9860;
v_9861:
    goto v_9870;
v_9866:
    v_10012 = qvalue(elt(env, 2)); // maxvar
    goto v_9867;
v_9868:
    v_10011 = stack[-3];
    goto v_9869;
v_9870:
    goto v_9866;
v_9867:
    goto v_9868;
v_9869:
    v_10011 = plus2(v_10012, v_10011);
    env = stack[-5];
    goto v_9862;
v_9863:
    goto v_9859;
v_9860:
    goto v_9861;
v_9862:
    v_10012 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_10011-TAG_FIXNUM)/(16/CELL)));
    goto v_9855;
v_9856:
    v_10011 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9857;
v_9858:
    goto v_9854;
v_9855:
    goto v_9856;
v_9857:
    v_10011 = *(LispObject *)((char *)v_10012 + (CELL-TAG_VECTOR) + (((intptr_t)v_10011-TAG_FIXNUM)/(16/CELL)));
    if (v_10011 == nil) goto v_9852;
    goto v_9882;
v_9878:
    v_10012 = stack[-3];
    goto v_9879;
v_9880:
    v_10011 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9881;
v_9882:
    goto v_9878;
v_9879:
    goto v_9880;
v_9881:
    v_10011 = (LispObject)geq2(v_10012, v_10011);
    v_10011 = v_10011 ? lisp_true : nil;
    env = stack[-5];
    if (v_10011 == nil) goto v_9852;
    goto v_9897;
v_9893:
    stack[0] = qvalue(elt(env, 3)); // codhisto
    goto v_9894;
v_9895:
    goto v_9904;
v_9900:
    goto v_9909;
v_9905:
    goto v_9914;
v_9910:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_9911;
v_9912:
    goto v_9921;
v_9917:
    v_10012 = qvalue(elt(env, 2)); // maxvar
    goto v_9918;
v_9919:
    v_10011 = stack[-3];
    goto v_9920;
v_9921:
    goto v_9917;
v_9918:
    goto v_9919;
v_9920:
    v_10011 = plus2(v_10012, v_10011);
    env = stack[-5];
    goto v_9913;
v_9914:
    goto v_9910;
v_9911:
    goto v_9912;
v_9913:
    v_10012 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_10011-TAG_FIXNUM)/(16/CELL)));
    goto v_9906;
v_9907:
    v_10011 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9908;
v_9909:
    goto v_9905;
v_9906:
    goto v_9907;
v_9908:
    v_10011 = *(LispObject *)((char *)v_10012 + (CELL-TAG_VECTOR) + (((intptr_t)v_10011-TAG_FIXNUM)/(16/CELL)));
    v_10012 = qcdr(v_10011);
    goto v_9901;
v_9902:
    v_10011 = (LispObject)3200+TAG_FIXNUM; // 200
    goto v_9903;
v_9904:
    goto v_9900;
v_9901:
    goto v_9902;
v_9903:
    fn = elt(env, 5); // min
    v_10011 = (*qfn2(fn))(fn, v_10012, v_10011);
    env = stack[-5];
    stack[-2] = v_10011;
    goto v_9896;
v_9897:
    goto v_9893;
v_9894:
    goto v_9895;
v_9896:
    v_10011 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_10011-TAG_FIXNUM)/(16/CELL)));
    stack[-4] = v_10011;
    if (v_10011 == nil) goto v_9892;
    goto v_9935;
v_9931:
    goto v_9940;
v_9936:
    goto v_9945;
v_9941:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_9942;
v_9943:
    goto v_9952;
v_9948:
    v_10012 = qvalue(elt(env, 2)); // maxvar
    goto v_9949;
v_9950:
    v_10011 = stack[-4];
    goto v_9951;
v_9952:
    goto v_9948;
v_9949:
    goto v_9950;
v_9951:
    v_10011 = plus2(v_10012, v_10011);
    env = stack[-5];
    goto v_9944;
v_9945:
    goto v_9941;
v_9942:
    goto v_9943;
v_9944:
    v_10012 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_10011-TAG_FIXNUM)/(16/CELL)));
    goto v_9937;
v_9938:
    v_10011 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_9939;
v_9940:
    goto v_9936;
v_9937:
    goto v_9938;
v_9939:
    v_10012 = *(LispObject *)((char *)v_10012 + (CELL-TAG_VECTOR) + (((intptr_t)v_10011-TAG_FIXNUM)/(16/CELL)));
    goto v_9932;
v_9933:
    v_10011 = stack[-3];
    goto v_9934;
v_9935:
    goto v_9931;
v_9932:
    goto v_9933;
v_9934:
    v_10011 = Lrplaca(nil, v_10012, v_10011);
    env = stack[-5];
    goto v_9890;
v_9892:
    goto v_9966;
v_9962:
    v_10012 = stack[-2];
    goto v_9963;
v_9964:
    v_10011 = qvalue(elt(env, 4)); // headhisto
    goto v_9965;
v_9966:
    goto v_9962;
v_9963:
    goto v_9964;
v_9965:
    v_10011 = (LispObject)greaterp2(v_10012, v_10011);
    v_10011 = v_10011 ? lisp_true : nil;
    env = stack[-5];
    if (v_10011 == nil) goto v_9960;
    v_10011 = stack[-2];
    qvalue(elt(env, 4)) = v_10011; // headhisto
    goto v_9890;
v_9960:
v_9890:
    goto v_9976;
v_9970:
    goto v_9981;
v_9977:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_9978;
v_9979:
    goto v_9988;
v_9984:
    v_10012 = qvalue(elt(env, 2)); // maxvar
    goto v_9985;
v_9986:
    v_10011 = stack[-3];
    goto v_9987;
v_9988:
    goto v_9984;
v_9985:
    goto v_9986;
v_9987:
    v_10011 = plus2(v_10012, v_10011);
    env = stack[-5];
    goto v_9980;
v_9981:
    goto v_9977;
v_9978:
    goto v_9979;
v_9980:
    stack[-1] = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_10011-TAG_FIXNUM)/(16/CELL)));
    goto v_9971;
v_9972:
    stack[0] = (LispObject)112+TAG_FIXNUM; // 7
    goto v_9973;
v_9974:
    goto v_9998;
v_9994:
    v_10012 = nil;
    goto v_9995;
v_9996:
    v_10011 = stack[-4];
    goto v_9997;
v_9998:
    goto v_9994;
v_9995:
    goto v_9996;
v_9997:
    v_10011 = cons(v_10012, v_10011);
    env = stack[-5];
    goto v_9975;
v_9976:
    goto v_9970;
v_9971:
    goto v_9972;
v_9973:
    goto v_9974;
v_9975:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_10011;
    goto v_10007;
v_10001:
    v_10013 = qvalue(elt(env, 3)); // codhisto
    goto v_10002;
v_10003:
    v_10012 = stack[-2];
    goto v_10004;
v_10005:
    v_10011 = stack[-3];
    goto v_10006;
v_10007:
    goto v_10001;
v_10002:
    goto v_10003;
v_10004:
    goto v_10005;
v_10006:
    *(LispObject *)((char *)v_10013 + (CELL-TAG_VECTOR) + (((intptr_t)v_10012-TAG_FIXNUM)/(16/CELL))) = v_10011;
    v_10011 = nil;
    goto v_9850;
v_9852:
    v_10011 = nil;
v_9850:
    return onevalue(v_10011);
}



// Code for bcquot

static LispObject CC_bcquot(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9909, v_9910, v_9911;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_9848;
    stack[-1] = v_9847;
// end of prologue
    v_9909 = qvalue(elt(env, 1)); // !*grmod!*
    if (v_9909 == nil) goto v_9853;
    goto v_9861;
v_9857:
    goto v_9858;
v_9859:
    v_9909 = stack[0];
    v_9909 = Lmodular_reciprocal(nil, v_9909);
    env = stack[-2];
    goto v_9860;
v_9861:
    goto v_9857;
v_9858:
    goto v_9859;
v_9860:
    v_9909 = times2(stack[-1], v_9909);
    env = stack[-2];
    {
        fn = elt(env, 4); // bcfi
        return (*qfn1(fn))(fn, v_9909);
    }
v_9853:
    v_9909 = qvalue(elt(env, 2)); // !*vdpinteger
    if (v_9909 == nil) goto v_9866;
    goto v_9878;
v_9872:
    v_9911 = stack[-1];
    goto v_9873;
v_9874:
    v_9910 = stack[0];
    goto v_9875;
v_9876:
    v_9909 = elt(env, 3); // quotientx
    goto v_9877;
v_9878:
    goto v_9872;
v_9873:
    goto v_9874;
v_9875:
    goto v_9876;
v_9877:
    fn = elt(env, 5); // bcint2op
    v_9909 = (*qfnn(fn))(fn, 3, v_9911, v_9910, v_9909);
    env = stack[-2];
    if (v_9909 == nil) goto v_9870;
    else goto v_9869;
v_9870:
    goto v_9887;
v_9883:
    goto v_9893;
v_9889:
    v_9909 = stack[-1];
    v_9910 = qcar(v_9909);
    goto v_9890;
v_9891:
    v_9909 = stack[0];
    v_9909 = qcar(v_9909);
    goto v_9892;
v_9893:
    goto v_9889;
v_9890:
    goto v_9891;
v_9892:
    fn = elt(env, 6); // quotfx
    v_9910 = (*qfn2(fn))(fn, v_9910, v_9909);
    goto v_9884;
v_9885:
    v_9909 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9886;
v_9887:
    goto v_9883;
v_9884:
    goto v_9885;
v_9886:
    return cons(v_9910, v_9909);
v_9869:
    goto v_9851;
v_9866:
    goto v_9906;
v_9902:
    v_9910 = stack[-1];
    goto v_9903;
v_9904:
    v_9909 = stack[0];
    goto v_9905;
v_9906:
    goto v_9902;
v_9903:
    goto v_9904;
v_9905:
    {
        fn = elt(env, 7); // quotsq
        return (*qfn2(fn))(fn, v_9910, v_9909);
    }
    v_9909 = nil;
v_9851:
    return onevalue(v_9909);
}



// Code for bcplus!?

static LispObject CC_bcplusW(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9868, v_9869;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9868 = v_9847;
// end of prologue
    v_9868 = qcar(v_9868);
    v_9869 = v_9868;
    v_9868 = v_9869;
    if (is_number(v_9868)) goto v_9855;
    v_9868 = nil;
    goto v_9853;
v_9855:
    goto v_9865;
v_9861:
    goto v_9862;
v_9863:
    v_9868 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9864;
v_9865:
    goto v_9861;
v_9862:
    goto v_9863;
v_9864:
        return Lgreaterp(nil, v_9869, v_9868);
    v_9868 = nil;
v_9853:
    return onevalue(v_9868);
}



// Code for groebbuchcrit4t

static LispObject CC_groebbuchcrit4t(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9901, v_9902;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_9848;
    stack[-1] = v_9847;
// end of prologue
v_9852:
    v_9901 = stack[-1];
    if (v_9901 == nil) goto v_9859;
    else goto v_9860;
v_9859:
    v_9901 = lisp_true;
    goto v_9858;
v_9860:
    v_9901 = stack[0];
    v_9901 = (v_9901 == nil ? lisp_true : nil);
    goto v_9858;
    v_9901 = nil;
v_9858:
    if (v_9901 == nil) goto v_9856;
    v_9901 = nil;
    goto v_9851;
v_9856:
    goto v_9878;
v_9874:
    v_9901 = stack[-1];
    v_9902 = qcar(v_9901);
    goto v_9875;
v_9876:
    v_9901 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9877;
v_9878:
    goto v_9874;
v_9875:
    goto v_9876;
v_9877:
    if (v_9902 == v_9901) goto v_9873;
    goto v_9887;
v_9883:
    v_9901 = stack[0];
    v_9902 = qcar(v_9901);
    goto v_9884;
v_9885:
    v_9901 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9886;
v_9887:
    goto v_9883;
v_9884:
    goto v_9885;
v_9886:
    v_9901 = Lneq(nil, v_9902, v_9901);
    env = stack[-2];
    goto v_9871;
v_9873:
    v_9901 = nil;
    goto v_9871;
    v_9901 = nil;
v_9871:
    if (v_9901 == nil) goto v_9869;
    v_9901 = lisp_true;
    goto v_9851;
v_9869:
    v_9901 = stack[-1];
    v_9901 = qcdr(v_9901);
    stack[-1] = v_9901;
    v_9901 = stack[0];
    v_9901 = qcdr(v_9901);
    stack[0] = v_9901;
    goto v_9852;
    v_9901 = nil;
v_9851:
    return onevalue(v_9901);
}



// Code for !*pf2wedgepf

static LispObject CC_Hpf2wedgepf(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9880, v_9881, v_9882;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_9847;
// end of prologue
    stack[-1] = nil;
v_9852:
    v_9880 = stack[0];
    if (v_9880 == nil) goto v_9855;
    else goto v_9856;
v_9855:
    v_9880 = stack[-1];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_9880);
    }
v_9856:
    goto v_9869;
v_9863:
    v_9880 = stack[0];
    v_9880 = qcar(v_9880);
    v_9880 = qcar(v_9880);
    fn = elt(env, 2); // wedgefax
    v_9882 = (*qfn1(fn))(fn, v_9880);
    env = stack[-2];
    goto v_9864;
v_9865:
    v_9880 = stack[0];
    v_9880 = qcar(v_9880);
    v_9881 = qcdr(v_9880);
    goto v_9866;
v_9867:
    v_9880 = stack[-1];
    goto v_9868;
v_9869:
    goto v_9863;
v_9864:
    goto v_9865;
v_9866:
    goto v_9867;
v_9868:
    v_9880 = acons(v_9882, v_9881, v_9880);
    env = stack[-2];
    stack[-1] = v_9880;
    v_9880 = stack[0];
    v_9880 = qcdr(v_9880);
    stack[0] = v_9880;
    goto v_9852;
    v_9880 = nil;
    return onevalue(v_9880);
}



// Code for list!+list

static LispObject CC_listLlist(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9884, v_9885;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_9848;
    stack[-1] = v_9847;
// end of prologue
    stack[-2] = nil;
v_9853:
    v_9884 = stack[-1];
    if (v_9884 == nil) goto v_9856;
    else goto v_9857;
v_9856:
    v_9884 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_9884);
    }
v_9857:
    goto v_9868;
v_9864:
    goto v_9874;
v_9870:
    v_9884 = stack[-1];
    v_9885 = qcar(v_9884);
    goto v_9871;
v_9872:
    v_9884 = stack[0];
    v_9884 = qcar(v_9884);
    goto v_9873;
v_9874:
    goto v_9870;
v_9871:
    goto v_9872;
v_9873:
    fn = elt(env, 2); // !:plus
    v_9885 = (*qfn2(fn))(fn, v_9885, v_9884);
    env = stack[-3];
    goto v_9865;
v_9866:
    v_9884 = stack[-2];
    goto v_9867;
v_9868:
    goto v_9864;
v_9865:
    goto v_9866;
v_9867:
    v_9884 = cons(v_9885, v_9884);
    env = stack[-3];
    stack[-2] = v_9884;
    v_9884 = stack[-1];
    v_9884 = qcdr(v_9884);
    stack[-1] = v_9884;
    v_9884 = stack[0];
    v_9884 = qcdr(v_9884);
    stack[0] = v_9884;
    goto v_9853;
    v_9884 = nil;
    return onevalue(v_9884);
}



// Code for sqp

static LispObject CC_sqp(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9871;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_9847;
// end of prologue
    v_9871 = stack[0];
    v_9871 = Lconsp(nil, v_9871);
    env = stack[-1];
    if (v_9871 == nil) goto v_9851;
    else goto v_9852;
v_9851:
    v_9871 = nil;
    goto v_9850;
v_9852:
    v_9871 = stack[0];
    v_9871 = qcar(v_9871);
    fn = elt(env, 1); // sfpx
    v_9871 = (*qfn1(fn))(fn, v_9871);
    env = stack[-1];
    if (v_9871 == nil) goto v_9860;
    else goto v_9861;
v_9860:
    v_9871 = nil;
    goto v_9859;
v_9861:
    v_9871 = stack[0];
    v_9871 = qcdr(v_9871);
    {
        fn = elt(env, 1); // sfpx
        return (*qfn1(fn))(fn, v_9871);
    }
    v_9871 = nil;
v_9859:
    goto v_9850;
    v_9871 = nil;
v_9850:
    return onevalue(v_9871);
}



// Code for degree!-in!-variable

static LispObject CC_degreeKinKvariable(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9922, v_9923;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_9848;
    stack[-1] = v_9847;
// end of prologue
    v_9922 = stack[-1];
    if (!consp(v_9922)) goto v_9856;
    else goto v_9857;
v_9856:
    v_9922 = lisp_true;
    goto v_9855;
v_9857:
    v_9922 = stack[-1];
    v_9922 = qcar(v_9922);
    v_9922 = (consp(v_9922) ? nil : lisp_true);
    goto v_9855;
    v_9922 = nil;
v_9855:
    if (v_9922 == nil) goto v_9853;
    v_9922 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9851;
v_9853:
    goto v_9872;
v_9868:
    v_9922 = stack[-1];
    v_9922 = qcar(v_9922);
    v_9923 = qcdr(v_9922);
    goto v_9869;
v_9870:
    v_9922 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9871;
v_9872:
    goto v_9868;
v_9869:
    goto v_9870;
v_9871:
    if (v_9923 == v_9922) goto v_9866;
    else goto v_9867;
v_9866:
    v_9922 = elt(env, 1); // "Polynomial with a zero coefficient found"
    {
        fn = elt(env, 2); // errorf
        return (*qfn1(fn))(fn, v_9922);
    }
v_9867:
    goto v_9885;
v_9881:
    v_9923 = stack[0];
    goto v_9882;
v_9883:
    v_9922 = stack[-1];
    v_9922 = qcar(v_9922);
    v_9922 = qcar(v_9922);
    v_9922 = qcar(v_9922);
    goto v_9884;
v_9885:
    goto v_9881;
v_9882:
    goto v_9883;
v_9884:
    if (equal(v_9923, v_9922)) goto v_9879;
    else goto v_9880;
v_9879:
    v_9922 = stack[-1];
    v_9922 = qcar(v_9922);
    v_9922 = qcar(v_9922);
    v_9922 = qcdr(v_9922);
    goto v_9851;
v_9880:
    goto v_9902;
v_9898:
    goto v_9908;
v_9904:
    v_9922 = stack[-1];
    v_9922 = qcar(v_9922);
    v_9923 = qcdr(v_9922);
    goto v_9905;
v_9906:
    v_9922 = stack[0];
    goto v_9907;
v_9908:
    goto v_9904;
v_9905:
    goto v_9906;
v_9907:
    stack[-2] = CC_degreeKinKvariable(elt(env, 0), v_9923, v_9922);
    env = stack[-3];
    goto v_9899;
v_9900:
    goto v_9918;
v_9914:
    v_9922 = stack[-1];
    v_9923 = qcdr(v_9922);
    goto v_9915;
v_9916:
    v_9922 = stack[0];
    goto v_9917;
v_9918:
    goto v_9914;
v_9915:
    goto v_9916;
v_9917:
    v_9922 = CC_degreeKinKvariable(elt(env, 0), v_9923, v_9922);
    env = stack[-3];
    goto v_9901;
v_9902:
    goto v_9898;
v_9899:
    goto v_9900;
v_9901:
    {
        LispObject v_9927 = stack[-2];
        fn = elt(env, 3); // max
        return (*qfn2(fn))(fn, v_9927, v_9922);
    }
    v_9922 = nil;
v_9851:
    return onevalue(v_9922);
}



// Code for traput

static LispObject CC_traput(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_9911, v_9912, v_9913, v_9914, v_9915;
    LispObject v_9849, v_9848, v_9847;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "traput");
    va_start(aa, nargs);
    v_9847 = va_arg(aa, LispObject);
    v_9848 = va_arg(aa, LispObject);
    v_9849 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_9849,v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_9847,v_9848,v_9849);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_9912 = v_9849;
    v_9913 = v_9848;
    v_9914 = v_9847;
// end of prologue
    goto v_9863;
v_9859:
    v_9915 = v_9914;
    goto v_9860;
v_9861:
    v_9911 = v_9913;
    goto v_9862;
v_9863:
    goto v_9859;
v_9860:
    goto v_9861;
v_9862:
    v_9911 = get(v_9915, v_9911);
    env = stack[-2];
    v_9915 = v_9911;
    if (v_9911 == nil) goto v_9857;
    v_9911 = qvalue(elt(env, 1)); // toplv!*
    if (v_9911 == nil) goto v_9870;
    else goto v_9869;
v_9870:
    goto v_9877;
v_9873:
    v_9913 = v_9912;
    goto v_9874;
v_9875:
    v_9911 = v_9915;
    goto v_9876;
v_9877:
    goto v_9873;
v_9874:
    goto v_9875;
v_9876:
    v_9911 = Lmemq(nil, v_9913, v_9911);
    if (v_9911 == nil) goto v_9872;
    else goto v_9869;
v_9872:
    goto v_9886;
v_9882:
    stack[0] = v_9915;
    goto v_9883;
v_9884:
    goto v_9893;
v_9889:
    v_9911 = v_9912;
    goto v_9890;
v_9891:
    v_9912 = v_9915;
    v_9912 = qcdr(v_9912);
    goto v_9892;
v_9893:
    goto v_9889;
v_9890:
    goto v_9891;
v_9892:
    v_9911 = cons(v_9911, v_9912);
    env = stack[-2];
    goto v_9885;
v_9886:
    goto v_9882;
v_9883:
    goto v_9884;
v_9885:
    v_9911 = Lrplacd(nil, stack[0], v_9911);
    goto v_9867;
v_9869:
v_9867:
    goto v_9855;
v_9857:
    goto v_9906;
v_9900:
    stack[-1] = v_9914;
    goto v_9901;
v_9902:
    stack[0] = v_9913;
    goto v_9903;
v_9904:
    v_9911 = v_9912;
    v_9911 = ncons(v_9911);
    env = stack[-2];
    goto v_9905;
v_9906:
    goto v_9900;
v_9901:
    goto v_9902;
v_9903:
    goto v_9904;
v_9905:
    v_9911 = Lputprop(nil, 3, stack[-1], stack[0], v_9911);
    goto v_9855;
v_9855:
    v_9911 = nil;
    return onevalue(v_9911);
}



// Code for rl_bestgaussp

static LispObject CC_rl_bestgaussp(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9858;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_9858 = v_9847;
// end of prologue
    goto v_9854;
v_9850:
    stack[0] = qvalue(elt(env, 1)); // rl_bestgaussp!*
    goto v_9851;
v_9852:
    v_9858 = ncons(v_9858);
    env = stack[-1];
    goto v_9853;
v_9854:
    goto v_9850;
v_9851:
    goto v_9852;
v_9853:
    {
        LispObject v_9860 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_9860, v_9858);
    }
}



// Code for polynomheadreduceby

static LispObject CC_polynomheadreduceby(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9914, v_9915;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_9848;
    stack[-2] = v_9847;
// end of prologue
    stack[-3] = nil;
v_9856:
    v_9914 = stack[-2];
    v_9914 = qcar(v_9914);
    if (v_9914 == nil) goto v_9859;
    v_9914 = stack[-3];
    if (v_9914 == nil) goto v_9864;
    else goto v_9859;
v_9864:
    goto v_9860;
v_9859:
    goto v_9855;
v_9860:
    goto v_9876;
v_9872:
    v_9914 = stack[-2];
    v_9915 = qcar(v_9914);
    goto v_9873;
v_9874:
    v_9914 = stack[-1];
    v_9914 = qcar(v_9914);
    goto v_9875;
v_9876:
    goto v_9872;
v_9873:
    goto v_9874;
v_9875:
    fn = elt(env, 2); // monomisdivisibleby
    v_9914 = (*qfn2(fn))(fn, v_9915, v_9914);
    env = stack[-4];
    if (v_9914 == nil) goto v_9870;
    goto v_9886;
v_9882:
    v_9914 = stack[-2];
    v_9915 = qcar(v_9914);
    goto v_9883;
v_9884:
    v_9914 = stack[-1];
    v_9914 = qcar(v_9914);
    goto v_9885;
v_9886:
    goto v_9882;
v_9883:
    goto v_9884;
v_9885:
    fn = elt(env, 3); // monomdivide
    v_9914 = (*qfn2(fn))(fn, v_9915, v_9914);
    env = stack[-4];
    goto v_9896;
v_9892:
    stack[0] = stack[-2];
    goto v_9893;
v_9894:
    goto v_9903;
v_9899:
    v_9915 = stack[-1];
    goto v_9900;
v_9901:
    goto v_9902;
v_9903:
    goto v_9899;
v_9900:
    goto v_9901;
v_9902:
    fn = elt(env, 4); // polynommultiplybymonom
    v_9914 = (*qfn2(fn))(fn, v_9915, v_9914);
    env = stack[-4];
    goto v_9895;
v_9896:
    goto v_9892;
v_9893:
    goto v_9894;
v_9895:
    fn = elt(env, 5); // polynomadd
    v_9914 = (*qfn2(fn))(fn, stack[0], v_9914);
    env = stack[-4];
    goto v_9868;
v_9870:
    v_9914 = lisp_true;
    stack[-3] = v_9914;
    goto v_9868;
v_9868:
    goto v_9856;
v_9855:
    v_9914 = qvalue(elt(env, 1)); // fluidbibasisreductionsmade
    v_9914 = (LispObject)((intptr_t)(v_9914) + 0x10);
    qvalue(elt(env, 1)) = v_9914; // fluidbibasisreductionsmade
    v_9914 = nil;
    return onevalue(v_9914);
}



// Code for exptcompare

static LispObject CC_exptcompare(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9887, v_9888, v_9889;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9887 = v_9848;
    v_9888 = v_9847;
// end of prologue
    v_9889 = v_9888;
    if (!consp(v_9889)) goto v_9852;
    else goto v_9853;
v_9852:
    v_9889 = v_9887;
    if (!consp(v_9889)) goto v_9857;
    else goto v_9858;
v_9857:
    goto v_9865;
v_9861:
    goto v_9862;
v_9863:
    goto v_9864;
v_9865:
    goto v_9861;
v_9862:
    goto v_9863;
v_9864:
        return Lgreaterp(nil, v_9888, v_9887);
v_9858:
    v_9887 = nil;
    goto v_9856;
    v_9887 = nil;
v_9856:
    goto v_9851;
v_9853:
    v_9889 = v_9887;
    if (!consp(v_9889)) goto v_9871;
    else goto v_9872;
v_9871:
    v_9887 = lisp_true;
    goto v_9851;
v_9872:
    goto v_9882;
v_9878:
    v_9888 = qcar(v_9888);
    goto v_9879;
v_9880:
    v_9887 = qcar(v_9887);
    goto v_9881;
v_9882:
    goto v_9878;
v_9879:
    goto v_9880;
v_9881:
        return Lgreaterp(nil, v_9888, v_9887);
    v_9887 = nil;
v_9851:
    return onevalue(v_9887);
}



// Code for cl_smsimpl!-junct2

static LispObject CC_cl_smsimplKjunct2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_9963, v_9964, v_9965, v_9966;
    LispObject fn;
    LispObject v_9852, v_9851, v_9850, v_9849, v_9848, v_9847;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "cl_smsimpl-junct2");
    va_start(aa, nargs);
    v_9847 = va_arg(aa, LispObject);
    v_9848 = va_arg(aa, LispObject);
    v_9849 = va_arg(aa, LispObject);
    v_9850 = va_arg(aa, LispObject);
    v_9851 = va_arg(aa, LispObject);
    v_9852 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_9852,v_9851,v_9850,v_9849,v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_9847,v_9848,v_9849,v_9850,v_9851,v_9852);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_9852;
    v_9963 = v_9851;
    v_9964 = v_9850;
    v_9965 = v_9849;
    stack[-2] = v_9848;
    v_9966 = v_9847;
// end of prologue
    goto v_9867;
v_9859:
    goto v_9860;
v_9861:
    goto v_9862;
v_9863:
    goto v_9864;
v_9865:
    goto v_9866;
v_9867:
    goto v_9859;
v_9860:
    goto v_9861;
v_9862:
    goto v_9863;
v_9864:
    goto v_9865;
v_9866:
    fn = elt(env, 6); // rl_smmkatl
    v_9963 = (*qfnn(fn))(fn, 4, v_9966, v_9965, v_9964, v_9963);
    env = stack[-4];
    stack[-3] = v_9963;
    goto v_9880;
v_9876:
    v_9964 = stack[-3];
    goto v_9877;
v_9878:
    v_9963 = stack[-1];
    goto v_9879;
v_9880:
    goto v_9876;
v_9877:
    goto v_9878;
v_9879:
    if (v_9964 == v_9963) goto v_9874;
    else goto v_9875;
v_9874:
    v_9963 = stack[-1];
    return ncons(v_9963);
v_9875:
    v_9963 = qvalue(elt(env, 1)); // !*rlsichk
    if (v_9963 == nil) goto v_9888;
    v_9963 = stack[-2];
    v_9964 = v_9963;
    v_9963 = nil;
    stack[-2] = v_9963;
    v_9963 = v_9964;
    stack[0] = v_9963;
v_9895:
    v_9963 = stack[0];
    if (v_9963 == nil) goto v_9899;
    else goto v_9900;
v_9899:
    goto v_9894;
v_9900:
    v_9963 = stack[0];
    v_9963 = qcar(v_9963);
    goto v_9911;
v_9907:
    v_9964 = v_9963;
    goto v_9908;
v_9909:
    v_9963 = stack[-2];
    goto v_9910;
v_9911:
    goto v_9907;
v_9908:
    goto v_9909;
v_9910:
    fn = elt(env, 7); // lto_insert
    v_9963 = (*qfn2(fn))(fn, v_9964, v_9963);
    env = stack[-4];
    stack[-2] = v_9963;
    v_9963 = stack[0];
    v_9963 = qcdr(v_9963);
    stack[0] = v_9963;
    goto v_9895;
v_9894:
    goto v_9886;
v_9888:
    v_9963 = stack[-2];
    v_9963 = Lnreverse(nil, v_9963);
    env = stack[-4];
    stack[-2] = v_9963;
    goto v_9886;
v_9886:
    v_9963 = qvalue(elt(env, 2)); // !*rlsiso
    if (v_9963 == nil) goto v_9923;
    goto v_9930;
v_9926:
    v_9964 = stack[-3];
    goto v_9927;
v_9928:
    v_9963 = elt(env, 3); // rl_ordatp
    goto v_9929;
v_9930:
    goto v_9926;
v_9927:
    goto v_9928;
v_9929:
    fn = elt(env, 8); // sort
    v_9963 = (*qfn2(fn))(fn, v_9964, v_9963);
    env = stack[-4];
    stack[-3] = v_9963;
    v_9963 = qvalue(elt(env, 4)); // !*rlsisocx
    if (v_9963 == nil) goto v_9936;
    goto v_9943;
v_9939:
    v_9964 = stack[-2];
    goto v_9940;
v_9941:
    v_9963 = elt(env, 5); // cl_sordp
    goto v_9942;
v_9943:
    goto v_9939;
v_9940:
    goto v_9941;
v_9942:
    fn = elt(env, 8); // sort
    v_9963 = (*qfn2(fn))(fn, v_9964, v_9963);
    env = stack[-4];
    stack[-2] = v_9963;
    goto v_9934;
v_9936:
v_9934:
    goto v_9921;
v_9923:
v_9921:
    goto v_9951;
v_9947:
    v_9964 = stack[-3];
    goto v_9948;
v_9949:
    v_9963 = stack[-2];
    goto v_9950;
v_9951:
    goto v_9947;
v_9948:
    goto v_9949;
v_9950:
    v_9963 = Lnconc(nil, v_9964, v_9963);
    env = stack[-4];
    v_9964 = v_9963;
    v_9963 = v_9964;
    if (v_9963 == nil) goto v_9957;
    v_9963 = v_9964;
    goto v_9857;
v_9957:
    v_9963 = stack[-1];
    fn = elt(env, 9); // cl_flip
    v_9963 = (*qfn1(fn))(fn, v_9963);
    return ncons(v_9963);
v_9857:
    return onevalue(v_9963);
}



// Code for variableom

static LispObject CC_variableom(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9902, v_9903;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_9847;
// end of prologue
    goto v_9856;
v_9852:
    v_9902 = stack[0];
    v_9903 = Lintern(nil, v_9902);
    env = stack[-2];
    goto v_9853;
v_9854:
    v_9902 = qvalue(elt(env, 1)); // constantsom!*
    goto v_9855;
v_9856:
    goto v_9852;
v_9853:
    goto v_9854;
v_9855:
    v_9902 = Lassoc(nil, v_9903, v_9902);
    stack[-1] = v_9902;
    v_9902 = stack[-1];
    if (v_9902 == nil) goto v_9864;
    v_9902 = elt(env, 2); // "<OMS "
    fn = elt(env, 8); // printout
    v_9902 = (*qfn1(fn))(fn, v_9902);
    env = stack[-2];
    v_9902 = elt(env, 3); // "cd="""
    v_9902 = Lprinc(nil, v_9902);
    env = stack[-2];
    v_9902 = stack[-1];
    v_9902 = qcdr(v_9902);
    v_9902 = qcar(v_9902);
    v_9902 = Lprinc(nil, v_9902);
    env = stack[-2];
    v_9902 = elt(env, 4); // """ "
    v_9902 = Lprinc(nil, v_9902);
    env = stack[-2];
    v_9902 = elt(env, 5); // "name="""
    v_9902 = Lprinc(nil, v_9902);
    env = stack[-2];
    v_9902 = stack[-1];
    v_9902 = qcdr(v_9902);
    v_9902 = qcdr(v_9902);
    v_9902 = qcar(v_9902);
    v_9902 = Lprinc(nil, v_9902);
    env = stack[-2];
    v_9902 = elt(env, 6); // """/>"
    v_9902 = Lprinc(nil, v_9902);
    goto v_9862;
v_9864:
    v_9902 = stack[0];
    if (v_9902 == nil) goto v_9891;
    v_9902 = elt(env, 7); // "<OMV "
    fn = elt(env, 8); // printout
    v_9902 = (*qfn1(fn))(fn, v_9902);
    env = stack[-2];
    v_9902 = elt(env, 5); // "name="""
    v_9902 = Lprinc(nil, v_9902);
    env = stack[-2];
    v_9902 = stack[0];
    v_9902 = Lprinc(nil, v_9902);
    env = stack[-2];
    v_9902 = elt(env, 6); // """/>"
    v_9902 = Lprinc(nil, v_9902);
    goto v_9889;
v_9891:
v_9889:
    goto v_9862;
v_9862:
    v_9902 = nil;
    return onevalue(v_9902);
}



// Code for onoff

static LispObject CC_onoff(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9974, v_9975, v_9976;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_9848;
    stack[0] = v_9847;
// end of prologue
    v_9974 = stack[0];
    if (symbolp(v_9974)) goto v_9857;
    goto v_9864;
v_9860:
    v_9975 = stack[0];
    goto v_9861;
v_9862:
    v_9974 = elt(env, 1); // "switch"
    goto v_9863;
v_9864:
    goto v_9860;
v_9861:
    goto v_9862;
v_9863:
    fn = elt(env, 9); // typerr
    v_9974 = (*qfn2(fn))(fn, v_9975, v_9974);
    env = stack[-4];
    goto v_9855;
v_9857:
    v_9974 = stack[0];
    if (!symbolp(v_9974)) v_9974 = nil;
    else { v_9974 = qfastgets(v_9974);
           if (v_9974 != nil) { v_9974 = elt(v_9974, 51); // switch
#ifdef RECORD_GET
             if (v_9974 == SPID_NOPROP)
                record_get(elt(fastget_names, 51), 0),
                v_9974 = nil;
             else record_get(elt(fastget_names, 51), 1),
                v_9974 = lisp_true; }
           else record_get(elt(fastget_names, 51), 0); }
#else
             if (v_9974 == SPID_NOPROP) v_9974 = nil; else v_9974 = lisp_true; }}
#endif
    if (v_9974 == nil) goto v_9867;
    else goto v_9868;
v_9867:
    goto v_9878;
v_9872:
    stack[-3] = elt(env, 2); // rlisp
    goto v_9873;
v_9874:
    stack[-1] = (LispObject)400+TAG_FIXNUM; // 25
    goto v_9875;
v_9876:
    goto v_9886;
v_9882:
    v_9975 = stack[0];
    goto v_9883;
v_9884:
    v_9974 = elt(env, 3); // "not defined as switch"
    goto v_9885;
v_9886:
    goto v_9882;
v_9883:
    goto v_9884;
v_9885:
    v_9974 = list2(v_9975, v_9974);
    env = stack[-4];
    goto v_9877;
v_9878:
    goto v_9872;
v_9873:
    goto v_9874;
v_9875:
    goto v_9876;
v_9877:
    fn = elt(env, 10); // rerror
    v_9974 = (*qfnn(fn))(fn, 3, stack[-3], stack[-1], v_9974);
    env = stack[-4];
    goto v_9855;
v_9868:
v_9855:
    goto v_9896;
v_9892:
    stack[-1] = elt(env, 4); // !*
    goto v_9893;
v_9894:
    v_9974 = stack[0];
    v_9974 = Lexplodec(nil, v_9974);
    env = stack[-4];
    goto v_9895;
v_9896:
    goto v_9892;
v_9893:
    goto v_9894;
v_9895:
    v_9974 = cons(stack[-1], v_9974);
    env = stack[-4];
    fn = elt(env, 11); // list2string
    v_9974 = (*qfn1(fn))(fn, v_9974);
    env = stack[-4];
    v_9974 = Lintern(nil, v_9974);
    env = stack[-4];
    stack[-3] = v_9974;
    v_9974 = qvalue(elt(env, 5)); // !*switchcheck
    if (v_9974 == nil) goto v_9903;
    goto v_9911;
v_9907:
    v_9974 = stack[-3];
    fn = elt(env, 12); // lispeval
    v_9975 = (*qfn1(fn))(fn, v_9974);
    env = stack[-4];
    goto v_9908;
v_9909:
    v_9974 = stack[-2];
    goto v_9910;
v_9911:
    goto v_9907;
v_9908:
    goto v_9909;
v_9910:
    if (v_9975 == v_9974) goto v_9906;
    else goto v_9903;
v_9906:
    v_9974 = nil;
    goto v_9853;
v_9903:
    goto v_9922;
v_9918:
    v_9976 = stack[-2];
    goto v_9919;
v_9920:
    goto v_9929;
v_9925:
    v_9975 = stack[0];
    goto v_9926;
v_9927:
    v_9974 = elt(env, 6); // simpfg
    goto v_9928;
v_9929:
    goto v_9925;
v_9926:
    goto v_9927;
v_9928:
    v_9974 = get(v_9975, v_9974);
    env = stack[-4];
    goto v_9921;
v_9922:
    goto v_9918;
v_9919:
    goto v_9920;
v_9921:
    v_9974 = Latsoc(nil, v_9976, v_9974);
    v_9975 = v_9974;
    if (v_9974 == nil) goto v_9917;
    goto v_9939;
v_9935:
    stack[-1] = elt(env, 7); // progn
    goto v_9936;
v_9937:
    goto v_9946;
v_9942:
    v_9974 = v_9975;
    stack[0] = qcdr(v_9974);
    goto v_9943;
v_9944:
    v_9974 = nil;
    v_9974 = ncons(v_9974);
    env = stack[-4];
    goto v_9945;
v_9946:
    goto v_9942;
v_9943:
    goto v_9944;
v_9945:
    v_9974 = Lappend(nil, stack[0], v_9974);
    env = stack[-4];
    goto v_9938;
v_9939:
    goto v_9935;
v_9936:
    goto v_9937;
v_9938:
    v_9974 = cons(stack[-1], v_9974);
    env = stack[-4];
    fn = elt(env, 12); // lispeval
    v_9974 = (*qfn1(fn))(fn, v_9974);
    env = stack[-4];
    goto v_9901;
v_9917:
v_9901:
    v_9974 = stack[-2];
    if (v_9974 == nil) goto v_9954;
    goto v_9962;
v_9958:
    v_9975 = stack[-3];
    goto v_9959;
v_9960:
    v_9974 = elt(env, 8); // !*raise
    goto v_9961;
v_9962:
    goto v_9958;
v_9959:
    goto v_9960;
v_9961:
    if (v_9975 == v_9974) goto v_9957;
    else goto v_9954;
v_9957:
    v_9974 = elt(env, 8); // !*raise
    stack[-3] = v_9974;
    goto v_9952;
v_9954:
v_9952:
    goto v_9971;
v_9967:
    v_9975 = stack[-3];
    goto v_9968;
v_9969:
    v_9974 = stack[-2];
    goto v_9970;
v_9971:
    goto v_9967;
v_9968:
    goto v_9969;
v_9970:
    v_9974 = Lset(nil, v_9975, v_9974);
    v_9974 = nil;
v_9853:
    return onevalue(v_9974);
}



// Code for unchecked_getmatelem

static LispObject CC_unchecked_getmatelem(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9910, v_9911, v_9912;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_9847;
// end of prologue
    goto v_9861;
v_9857:
    v_9910 = stack[-1];
    v_9911 = qcar(v_9910);
    v_9912 = v_9911;
    goto v_9858;
v_9859:
    v_9910 = elt(env, 1); // mat
    goto v_9860;
v_9861:
    goto v_9857;
v_9858:
    goto v_9859;
v_9860:
    if (!consp(v_9911)) goto v_9854;
    v_9911 = qcar(v_9911);
    if (v_9911 == v_9910) goto v_9855;
v_9854:
    goto v_9872;
v_9866:
    stack[-2] = elt(env, 2); // matrix
    goto v_9867;
v_9868:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9869;
v_9870:
    goto v_9882;
v_9876:
    v_9912 = elt(env, 3); // "Matrix"
    goto v_9877;
v_9878:
    v_9910 = stack[-1];
    v_9911 = qcar(v_9910);
    goto v_9879;
v_9880:
    v_9910 = elt(env, 4); // "not set"
    goto v_9881;
v_9882:
    goto v_9876;
v_9877:
    goto v_9878;
v_9879:
    goto v_9880;
v_9881:
    v_9910 = list3(v_9912, v_9911, v_9910);
    env = stack[-3];
    goto v_9871;
v_9872:
    goto v_9866;
v_9867:
    goto v_9868;
v_9869:
    goto v_9870;
v_9871:
    fn = elt(env, 5); // rerror
    v_9910 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_9910);
    goto v_9853;
v_9855:
    goto v_9894;
v_9890:
    goto v_9900;
v_9896:
    v_9910 = v_9912;
    v_9911 = qcdr(v_9910);
    goto v_9897;
v_9898:
    v_9910 = stack[-1];
    v_9910 = qcdr(v_9910);
    v_9910 = qcar(v_9910);
    goto v_9899;
v_9900:
    goto v_9896;
v_9897:
    goto v_9898;
v_9899:
    fn = elt(env, 6); // nth
    v_9911 = (*qfn2(fn))(fn, v_9911, v_9910);
    env = stack[-3];
    goto v_9891;
v_9892:
    v_9910 = stack[-1];
    v_9910 = qcdr(v_9910);
    v_9910 = qcdr(v_9910);
    v_9910 = qcar(v_9910);
    goto v_9893;
v_9894:
    goto v_9890;
v_9891:
    goto v_9892;
v_9893:
    {
        fn = elt(env, 6); // nth
        return (*qfn2(fn))(fn, v_9911, v_9910);
    }
v_9853:
    v_9910 = nil;
    return onevalue(v_9910);
}



// Code for guesspftype

static LispObject CC_guesspftype(LispObject env,
                         LispObject v_9847)
{
    env = qenv(env);
    LispObject v_9891, v_9892;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9847);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_9847;
// end of prologue
    v_9891 = stack[0];
    if (!consp(v_9891)) goto v_9851;
    else goto v_9852;
v_9851:
    v_9891 = stack[0];
    goto v_9850;
v_9852:
    goto v_9861;
v_9857:
    v_9891 = stack[0];
    v_9892 = qcar(v_9891);
    goto v_9858;
v_9859:
    v_9891 = elt(env, 1); // (wedge d partdf hodge innerprod liedf)
    goto v_9860;
v_9861:
    goto v_9857;
v_9858:
    goto v_9859;
v_9860:
    v_9891 = Lmemq(nil, v_9892, v_9891);
    if (v_9891 == nil) goto v_9856;
    v_9891 = stack[0];
    goto v_9850;
v_9856:
    goto v_9874;
v_9870:
    v_9891 = stack[0];
    v_9891 = qcdr(v_9891);
    v_9892 = Llength(nil, v_9891);
    env = stack[-1];
    goto v_9871;
v_9872:
    v_9891 = stack[0];
    v_9891 = qcar(v_9891);
    if (!symbolp(v_9891)) v_9891 = nil;
    else { v_9891 = qfastgets(v_9891);
           if (v_9891 != nil) { v_9891 = elt(v_9891, 25); // ifdegree
#ifdef RECORD_GET
             if (v_9891 != SPID_NOPROP)
                record_get(elt(fastget_names, 25), 1);
             else record_get(elt(fastget_names, 25), 0),
                v_9891 = nil; }
           else record_get(elt(fastget_names, 25), 0); }
#else
             if (v_9891 == SPID_NOPROP) v_9891 = nil; }}
#endif
    goto v_9873;
v_9874:
    goto v_9870;
v_9871:
    goto v_9872;
v_9873:
    v_9891 = Lassoc(nil, v_9892, v_9891);
    if (v_9891 == nil) goto v_9868;
    v_9891 = stack[0];
    v_9891 = qcdr(v_9891);
    fn = elt(env, 2); // xvarlistp
    v_9891 = (*qfn1(fn))(fn, v_9891);
    env = stack[-1];
    if (v_9891 == nil) goto v_9882;
    else goto v_9868;
v_9882:
    v_9891 = stack[0];
    goto v_9850;
v_9868:
    v_9891 = stack[0];
    {
        fn = elt(env, 3); // mknwedge
        return (*qfn1(fn))(fn, v_9891);
    }
    v_9891 = nil;
v_9850:
    return onevalue(v_9891);
}



// Code for deleteall

static LispObject CC_deleteall(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9885, v_9886, v_9887, v_9888;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_9848;
    stack[-1] = v_9847;
// end of prologue
    v_9887 = nil;
v_9854:
    v_9885 = stack[0];
    if (v_9885 == nil) goto v_9857;
    else goto v_9858;
v_9857:
    v_9885 = v_9887;
    goto v_9853;
v_9858:
    v_9885 = stack[0];
    v_9885 = qcar(v_9885);
    v_9888 = v_9885;
    v_9885 = stack[0];
    v_9885 = qcdr(v_9885);
    stack[0] = v_9885;
    goto v_9873;
v_9869:
    v_9886 = v_9888;
    goto v_9870;
v_9871:
    v_9885 = stack[-1];
    goto v_9872;
v_9873:
    goto v_9869;
v_9870:
    goto v_9871;
v_9872:
    if (equal(v_9886, v_9885)) goto v_9868;
    goto v_9881;
v_9877:
    stack[-2] = v_9887;
    goto v_9878;
v_9879:
    v_9885 = v_9888;
    v_9885 = ncons(v_9885);
    env = stack[-3];
    goto v_9880;
v_9881:
    goto v_9877;
v_9878:
    goto v_9879;
v_9880:
    v_9885 = Lnconc(nil, stack[-2], v_9885);
    env = stack[-3];
    v_9887 = v_9885;
    goto v_9866;
v_9868:
v_9866:
    goto v_9854;
v_9853:
    return onevalue(v_9885);
}



// Code for cstimes

static LispObject CC_cstimes(LispObject env,
                         LispObject v_9847, LispObject v_9848)
{
    env = qenv(env);
    LispObject v_9907, v_9908, v_9909, v_9910;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9848,v_9847);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9847,v_9848);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_9908 = v_9848;
    v_9909 = v_9847;
// end of prologue
v_9853:
    v_9907 = v_9909;
    if (v_9907 == nil) goto v_9856;
    else goto v_9857;
v_9856:
    v_9907 = v_9908;
    if (v_9907 == nil) goto v_9861;
    else goto v_9862;
v_9861:
    v_9907 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9852;
v_9862:
    v_9907 = v_9908;
    v_9907 = qcdr(v_9907);
    if (v_9907 == nil) goto v_9865;
    else goto v_9866;
v_9865:
    v_9907 = v_9908;
    v_9907 = qcar(v_9907);
    goto v_9852;
v_9866:
    goto v_9878;
v_9874:
    v_9907 = elt(env, 1); // times
    goto v_9875;
v_9876:
    goto v_9877;
v_9878:
    goto v_9874;
v_9875:
    goto v_9876;
v_9877:
    return cons(v_9907, v_9908);
    goto v_9855;
v_9857:
    goto v_9887;
v_9883:
    v_9907 = v_9909;
    v_9910 = qcar(v_9907);
    goto v_9884;
v_9885:
    v_9907 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9886;
v_9887:
    goto v_9883;
v_9884:
    goto v_9885;
v_9886:
    if (v_9910 == v_9907) goto v_9881;
    else goto v_9882;
v_9881:
    v_9907 = v_9909;
    v_9907 = qcdr(v_9907);
    v_9909 = v_9907;
    goto v_9853;
v_9882:
    v_9907 = v_9909;
    v_9907 = qcdr(v_9907);
    stack[0] = v_9907;
    goto v_9902;
v_9898:
    v_9907 = v_9909;
    v_9907 = qcar(v_9907);
    goto v_9899;
v_9900:
    goto v_9901;
v_9902:
    goto v_9898;
v_9899:
    goto v_9900;
v_9901:
    v_9907 = cons(v_9907, v_9908);
    env = stack[-1];
    v_9908 = v_9907;
    v_9907 = stack[0];
    v_9909 = v_9907;
    goto v_9853;
v_9855:
    v_9907 = nil;
v_9852:
    return onevalue(v_9907);
}



setup_type const u17_setup[] =
{
    {"omsir",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_omsir},
    {"evallessp",               TOO_FEW_2,      CC_evallessp,  WRONG_NO_2},
    {"ldt-tvar",                CC_ldtKtvar,    TOO_MANY_1,    WRONG_NO_1},
    {"actual_alst",             TOO_FEW_2,      CC_actual_alst,WRONG_NO_2},
    {"simp-sign",               CC_simpKsign,   TOO_MANY_1,    WRONG_NO_1},
    {"symbid",                  TOO_FEW_2,      CC_symbid,     WRONG_NO_2},
    {"getmatelem",              CC_getmatelem,  TOO_MANY_1,    WRONG_NO_1},
    {"dl_get2",                 TOO_FEW_2,      CC_dl_get2,    WRONG_NO_2},
    {"invbf",                   CC_invbf,       TOO_MANY_1,    WRONG_NO_1},
    {"negate-term",             CC_negateKterm, TOO_MANY_1,    WRONG_NO_1},
    {"lex_restore_context",     CC_lex_restore_context,TOO_MANY_1,WRONG_NO_1},
    {"talp_smwrmknowl",         TOO_FEW_2,      CC_talp_smwrmknowl,WRONG_NO_2},
    {"qqe_simplat1",            TOO_FEW_2,      CC_qqe_simplat1,WRONG_NO_2},
    {"sq2sspl",                 TOO_FEW_2,      CC_sq2sspl,    WRONG_NO_2},
    {"attributesml",            TOO_FEW_2,      CC_attributesml,WRONG_NO_2},
    {"maprin",                  CC_maprin,      TOO_MANY_1,    WRONG_NO_1},
    {"dm-eq",                   TOO_FEW_2,      CC_dmKeq,      WRONG_NO_2},
    {"modminusp:",              CC_modminuspT,  TOO_MANY_1,    WRONG_NO_1},
    {"listeval",                TOO_FEW_2,      CC_listeval,   WRONG_NO_2},
    {"simprepart",              CC_simprepart,  TOO_MANY_1,    WRONG_NO_1},
    {"mkprogn",                 TOO_FEW_2,      CC_mkprogn,    WRONG_NO_2},
    {"dpmat_coldegs",           CC_dpmat_coldegs,TOO_MANY_1,   WRONG_NO_1},
    {"pv_times1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pv_times1},
    {"b:ordexp",                TOO_FEW_2,      CC_bTordexp,   WRONG_NO_2},
    {"simpatom",                CC_simpatom,    TOO_MANY_1,    WRONG_NO_1},
    {"xremainder-mod-p",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xremainderKmodKp},
    {"update_kc_list",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_update_kc_list},
    {"get_action",              TOO_FEW_2,      CC_get_action, WRONG_NO_2},
    {"mkkl",                    TOO_FEW_2,      CC_mkkl,       WRONG_NO_2},
    {"wureducedpolysp",         TOO_FEW_2,      CC_wureducedpolysp,WRONG_NO_2},
    {"constsml",                CC_constsml,    TOO_MANY_1,    WRONG_NO_1},
    {"sacar",                   TOO_FEW_2,      CC_sacar,      WRONG_NO_2},
    {"findnewvars",             CC_findnewvars, TOO_MANY_1,    WRONG_NO_1},
    {"vbcgcd",                  TOO_FEW_2,      CC_vbcgcd,     WRONG_NO_2},
    {"vdpred",                  CC_vdpred,      TOO_MANY_1,    WRONG_NO_1},
    {"xord_gradlex",            TOO_FEW_2,      CC_xord_gradlex,WRONG_NO_2},
    {"removeindices",           TOO_FEW_2,      CC_removeindices,WRONG_NO_2},
    {"qcputx",                  CC_qcputx,      TOO_MANY_1,    WRONG_NO_1},
    {"prepreform",              CC_prepreform,  TOO_MANY_1,    WRONG_NO_1},
    {"findremainder",           TOO_FEW_2,      CC_findremainder,WRONG_NO_2},
    {"talp_eqtp",               TOO_FEW_2,      CC_talp_eqtp,  WRONG_NO_2},
    {"qqe_number-of-adds-in-qterm",CC_qqe_numberKofKaddsKinKqterm,TOO_MANY_1,WRONG_NO_1},
    {"ibalp_initwl",            CC_ibalp_initwl,TOO_MANY_1,    WRONG_NO_1},
    {"cgp_number",              CC_cgp_number,  TOO_MANY_1,    WRONG_NO_1},
    {"nary",                    TOO_FEW_2,      CC_nary,       WRONG_NO_2},
    {"spband_matrix",           TOO_FEW_2,      CC_spband_matrix,WRONG_NO_2},
    {"inshisto",                CC_inshisto,    TOO_MANY_1,    WRONG_NO_1},
    {"bcquot",                  TOO_FEW_2,      CC_bcquot,     WRONG_NO_2},
    {"bcplus?",                 CC_bcplusW,     TOO_MANY_1,    WRONG_NO_1},
    {"groebbuchcrit4t",         TOO_FEW_2,      CC_groebbuchcrit4t,WRONG_NO_2},
    {"*pf2wedgepf",             CC_Hpf2wedgepf, TOO_MANY_1,    WRONG_NO_1},
    {"list+list",               TOO_FEW_2,      CC_listLlist,  WRONG_NO_2},
    {"sqp",                     CC_sqp,         TOO_MANY_1,    WRONG_NO_1},
    {"degree-in-variable",      TOO_FEW_2,      CC_degreeKinKvariable,WRONG_NO_2},
    {"traput",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_traput},
    {"rl_bestgaussp",           CC_rl_bestgaussp,TOO_MANY_1,   WRONG_NO_1},
    {"polynomheadreduceby",     TOO_FEW_2,      CC_polynomheadreduceby,WRONG_NO_2},
    {"exptcompare",             TOO_FEW_2,      CC_exptcompare,WRONG_NO_2},
    {"cl_smsimpl-junct2",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_smsimplKjunct2},
    {"variableom",              CC_variableom,  TOO_MANY_1,    WRONG_NO_1},
    {"onoff",                   TOO_FEW_2,      CC_onoff,      WRONG_NO_2},
    {"unchecked_getmatelem",    CC_unchecked_getmatelem,TOO_MANY_1,WRONG_NO_1},
    {"guesspftype",             CC_guesspftype, TOO_MANY_1,    WRONG_NO_1},
    {"deleteall",               TOO_FEW_2,      CC_deleteall,  WRONG_NO_2},
    {"cstimes",                 TOO_FEW_2,      CC_cstimes,    WRONG_NO_2},
    {NULL, (one_args *)"u17", (two_args *)"35911 7024711 6246756", 0}
};

// end of generated code
