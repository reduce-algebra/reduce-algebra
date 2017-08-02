
// $destdir/u23.c        Machine generated C code

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



// Code for mv!-pow!-mv!-!+

static LispObject CC_mvKpowKmvKL(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12800, v_12801;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12767;
    stack[-1] = v_12766;
// end of prologue
    stack[-2] = nil;
v_12772:
    v_12800 = stack[0];
    if (v_12800 == nil) goto v_12775;
    else goto v_12776;
v_12775:
    v_12800 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12800);
    }
v_12776:
    goto v_12787;
v_12783:
    goto v_12793;
v_12789:
    v_12801 = stack[-1];
    goto v_12790;
v_12791:
    v_12800 = stack[0];
    v_12800 = qcar(v_12800);
    goto v_12792;
v_12793:
    goto v_12789;
v_12790:
    goto v_12791;
v_12792:
    fn = elt(env, 2); // mv!-pow!-mv!-term!-!+
    v_12801 = (*qfn2(fn))(fn, v_12801, v_12800);
    env = stack[-3];
    goto v_12784;
v_12785:
    v_12800 = stack[-2];
    goto v_12786;
v_12787:
    goto v_12783;
v_12784:
    goto v_12785;
v_12786:
    v_12800 = cons(v_12801, v_12800);
    env = stack[-3];
    stack[-2] = v_12800;
    v_12800 = stack[0];
    v_12800 = qcdr(v_12800);
    stack[0] = v_12800;
    goto v_12772;
    v_12800 = nil;
    return onevalue(v_12800);
}



// Code for tensorp

static LispObject CC_tensorp(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12785, v_12786;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12786 = v_12766;
// end of prologue
    v_12785 = v_12786;
    if (!consp(v_12785)) goto v_12771;
    goto v_12778;
v_12774:
    v_12785 = v_12786;
    v_12785 = qcar(v_12785);
    goto v_12775;
v_12776:
    v_12786 = elt(env, 1); // tensor
    goto v_12777;
v_12778:
    goto v_12774;
v_12775:
    goto v_12776;
v_12777:
        return Lflagp(nil, v_12785, v_12786);
v_12771:
    v_12785 = nil;
    goto v_12769;
    v_12785 = nil;
v_12769:
    return onevalue(v_12785);
}



// Code for lalr_precalculate_first_sets

static LispObject CC_lalr_precalculate_first_sets(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12954, v_12955, v_12956;
    LispObject fn;
    argcheck(nargs, 0, "lalr_precalculate_first_sets");
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
    stack[-3] = nil;
v_12776:
    v_12954 = nil;
    stack[-6] = v_12954;
    v_12954 = qvalue(elt(env, 2)); // nonterminals
    stack[-2] = v_12954;
v_12781:
    v_12954 = stack[-2];
    if (v_12954 == nil) goto v_12785;
    else goto v_12786;
v_12785:
    goto v_12780;
v_12786:
    v_12954 = stack[-2];
    v_12954 = qcar(v_12954);
    stack[-1] = v_12954;
    goto v_12797;
v_12793:
    v_12955 = stack[-1];
    goto v_12794;
v_12795:
    v_12954 = elt(env, 3); // lalr_first
    goto v_12796;
v_12797:
    goto v_12793;
v_12794:
    goto v_12795;
v_12796:
    v_12954 = get(v_12955, v_12954);
    env = stack[-7];
    stack[-5] = v_12954;
    v_12954 = stack[-1];
    fn = elt(env, 5); // lalr_productions
    v_12954 = (*qfn1(fn))(fn, v_12954);
    env = stack[-7];
    stack[0] = v_12954;
v_12803:
    v_12954 = stack[0];
    if (v_12954 == nil) goto v_12808;
    else goto v_12809;
v_12808:
    goto v_12802;
v_12809:
    v_12954 = stack[0];
    v_12954 = qcar(v_12954);
    v_12954 = qcar(v_12954);
    stack[-4] = v_12954;
v_12819:
    v_12954 = stack[-4];
    if (v_12954 == nil) goto v_12822;
    v_12954 = stack[-4];
    v_12954 = qcar(v_12954);
    if (is_number(v_12954)) goto v_12830;
    goto v_12837;
v_12833:
    v_12956 = nil;
    goto v_12834;
v_12835:
    goto v_12844;
v_12840:
    v_12954 = stack[-4];
    v_12955 = qcar(v_12954);
    goto v_12841;
v_12842:
    v_12954 = elt(env, 3); // lalr_first
    goto v_12843;
v_12844:
    goto v_12840;
v_12841:
    goto v_12842;
v_12843:
    v_12954 = get(v_12955, v_12954);
    env = stack[-7];
    stack[-3] = v_12954;
    goto v_12836;
v_12837:
    goto v_12833;
v_12834:
    goto v_12835;
v_12836:
    v_12954 = Lmember(nil, v_12956, v_12954);
    goto v_12828;
v_12830:
    v_12954 = nil;
    goto v_12828;
    v_12954 = nil;
v_12828:
    if (v_12954 == nil) goto v_12822;
    goto v_12823;
v_12822:
    goto v_12818;
v_12823:
    goto v_12858;
v_12854:
    goto v_12864;
v_12860:
    v_12955 = nil;
    goto v_12861;
v_12862:
    v_12954 = stack[-3];
    goto v_12863;
v_12864:
    goto v_12860;
v_12861:
    goto v_12862;
v_12863:
    v_12955 = Ldeleq(nil, v_12955, v_12954);
    env = stack[-7];
    goto v_12855;
v_12856:
    v_12954 = stack[-5];
    goto v_12857;
v_12858:
    goto v_12854;
v_12855:
    goto v_12856;
v_12857:
    fn = elt(env, 6); // union
    v_12954 = (*qfn2(fn))(fn, v_12955, v_12954);
    env = stack[-7];
    stack[-5] = v_12954;
    v_12954 = stack[-4];
    v_12954 = qcdr(v_12954);
    stack[-4] = v_12954;
    goto v_12819;
v_12818:
    v_12954 = stack[-4];
    if (v_12954 == nil) goto v_12872;
    else goto v_12873;
v_12872:
    goto v_12880;
v_12876:
    v_12955 = elt(env, 4); // (nil)
    goto v_12877;
v_12878:
    v_12954 = stack[-5];
    goto v_12879;
v_12880:
    goto v_12876;
v_12877:
    goto v_12878;
v_12879:
    fn = elt(env, 6); // union
    v_12954 = (*qfn2(fn))(fn, v_12955, v_12954);
    env = stack[-7];
    stack[-5] = v_12954;
    goto v_12871;
v_12873:
    v_12954 = stack[-4];
    v_12954 = qcar(v_12954);
    if (is_number(v_12954)) goto v_12883;
    else goto v_12884;
v_12883:
    goto v_12892;
v_12888:
    v_12954 = stack[-4];
    v_12954 = qcar(v_12954);
    v_12955 = ncons(v_12954);
    env = stack[-7];
    goto v_12889;
v_12890:
    v_12954 = stack[-5];
    goto v_12891;
v_12892:
    goto v_12888;
v_12889:
    goto v_12890;
v_12891:
    fn = elt(env, 6); // union
    v_12954 = (*qfn2(fn))(fn, v_12955, v_12954);
    env = stack[-7];
    stack[-5] = v_12954;
    goto v_12871;
v_12884:
    goto v_12904;
v_12900:
    goto v_12910;
v_12906:
    v_12954 = stack[-4];
    v_12955 = qcar(v_12954);
    goto v_12907;
v_12908:
    v_12954 = elt(env, 3); // lalr_first
    goto v_12909;
v_12910:
    goto v_12906;
v_12907:
    goto v_12908;
v_12909:
    v_12955 = get(v_12955, v_12954);
    env = stack[-7];
    goto v_12901;
v_12902:
    v_12954 = stack[-5];
    goto v_12903;
v_12904:
    goto v_12900;
v_12901:
    goto v_12902;
v_12903:
    fn = elt(env, 6); // union
    v_12954 = (*qfn2(fn))(fn, v_12955, v_12954);
    env = stack[-7];
    stack[-5] = v_12954;
    goto v_12871;
v_12871:
    v_12954 = stack[0];
    v_12954 = qcdr(v_12954);
    stack[0] = v_12954;
    goto v_12803;
v_12802:
    goto v_12925;
v_12921:
    v_12956 = stack[-5];
    goto v_12922;
v_12923:
    goto v_12932;
v_12928:
    v_12955 = stack[-1];
    goto v_12929;
v_12930:
    v_12954 = elt(env, 3); // lalr_first
    goto v_12931;
v_12932:
    goto v_12928;
v_12929:
    goto v_12930;
v_12931:
    v_12954 = get(v_12955, v_12954);
    env = stack[-7];
    goto v_12924;
v_12925:
    goto v_12921;
v_12922:
    goto v_12923;
v_12924:
    if (equal(v_12956, v_12954)) goto v_12920;
    v_12954 = lisp_true;
    stack[-6] = v_12954;
    goto v_12943;
v_12937:
    v_12956 = stack[-1];
    goto v_12938;
v_12939:
    v_12955 = elt(env, 3); // lalr_first
    goto v_12940;
v_12941:
    v_12954 = stack[-5];
    goto v_12942;
v_12943:
    goto v_12937;
v_12938:
    goto v_12939;
v_12940:
    goto v_12941;
v_12942:
    v_12954 = Lputprop(nil, 3, v_12956, v_12955, v_12954);
    env = stack[-7];
    goto v_12918;
v_12920:
v_12918:
    v_12954 = stack[-2];
    v_12954 = qcdr(v_12954);
    stack[-2] = v_12954;
    goto v_12781;
v_12780:
    v_12954 = stack[-6];
    if (v_12954 == nil) goto v_12952;
    goto v_12776;
v_12952:
    v_12954 = nil;
    return onevalue(v_12954);
}



// Code for aex_neg

static LispObject CC_aex_neg(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12779;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12766;
// end of prologue
    goto v_12773;
v_12769:
    v_12779 = stack[0];
    fn = elt(env, 1); // aex_ex
    v_12779 = (*qfn1(fn))(fn, v_12779);
    env = stack[-2];
    fn = elt(env, 2); // negsq
    stack[-1] = (*qfn1(fn))(fn, v_12779);
    env = stack[-2];
    goto v_12770;
v_12771:
    v_12779 = stack[0];
    fn = elt(env, 3); // aex_ctx
    v_12779 = (*qfn1(fn))(fn, v_12779);
    env = stack[-2];
    goto v_12772;
v_12773:
    goto v_12769;
v_12770:
    goto v_12771;
v_12772:
    {
        LispObject v_12782 = stack[-1];
        fn = elt(env, 4); // aex_mk
        return (*qfn2(fn))(fn, v_12782, v_12779);
    }
}



// Code for ofsf_surep

static LispObject CC_ofsf_surep(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12787, v_12788, v_12789;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12787 = v_12767;
    v_12788 = v_12766;
// end of prologue
    goto v_12773;
v_12769:
    goto v_12781;
v_12775:
    v_12789 = v_12788;
    goto v_12776;
v_12777:
    v_12788 = v_12787;
    goto v_12778;
v_12779:
    v_12787 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_12780;
v_12781:
    goto v_12775;
v_12776:
    goto v_12777;
v_12778:
    goto v_12779;
v_12780:
    fn = elt(env, 2); // cl_simpl
    v_12787 = (*qfnn(fn))(fn, 3, v_12789, v_12788, v_12787);
    env = stack[0];
    goto v_12770;
v_12771:
    v_12788 = elt(env, 1); // true
    goto v_12772;
v_12773:
    goto v_12769;
v_12770:
    goto v_12771;
v_12772:
    v_12787 = (v_12787 == v_12788 ? lisp_true : nil);
    return onevalue(v_12787);
}



// Code for simpexpt

static LispObject CC_simpexpt(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12804, v_12805, v_12806;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12766;
// end of prologue
    v_12804 = nil;
// Binding kord!*
// FLUIDBIND: reloadenv=2 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 2, -1);
    qvalue(elt(env, 2)) = v_12804; // kord!*
    goto v_12780;
v_12776:
    v_12804 = stack[0];
    v_12805 = qcdr(v_12804);
    goto v_12777;
v_12778:
    v_12804 = elt(env, 3); // expt
    goto v_12779;
v_12780:
    goto v_12776;
v_12777:
    goto v_12778;
v_12779:
    fn = elt(env, 5); // carx
    v_12804 = (*qfn2(fn))(fn, v_12805, v_12804);
    env = stack[-2];
    fn = elt(env, 6); // simpexpon
    v_12804 = (*qfn1(fn))(fn, v_12804);
    env = stack[-2];
    ;}  // end of a binding scope
    goto v_12789;
v_12785:
    v_12805 = v_12804;
    goto v_12786;
v_12787:
    v_12804 = elt(env, 4); // resimp
    goto v_12788;
v_12789:
    goto v_12785;
v_12786:
    goto v_12787;
v_12788:
    fn = elt(env, 7); // simpexpon1
    v_12804 = (*qfn2(fn))(fn, v_12805, v_12804);
    env = stack[-2];
    goto v_12799;
v_12793:
    v_12805 = stack[0];
    v_12806 = qcar(v_12805);
    goto v_12794;
v_12795:
    v_12805 = v_12804;
    goto v_12796;
v_12797:
    v_12804 = nil;
    goto v_12798;
v_12799:
    goto v_12793;
v_12794:
    goto v_12795;
v_12796:
    goto v_12797;
v_12798:
    {
        fn = elt(env, 8); // simpexpt1
        return (*qfnn(fn))(fn, 3, v_12806, v_12805, v_12804);
    }
    return onevalue(v_12804);
}



// Code for qqe_arg!-check

static LispObject CC_qqe_argKcheck(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12854, v_12855;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12766;
// end of prologue
    v_12854 = stack[0];
    v_12854 = qcar(v_12854);
    stack[-1] = v_12854;
    v_12854 = stack[-1];
    fn = elt(env, 3); // qqe_rqopp
    v_12854 = (*qfn1(fn))(fn, v_12854);
    env = stack[-2];
    if (v_12854 == nil) goto v_12774;
    v_12854 = stack[0];
    fn = elt(env, 4); // qqe_arg!-check!-lq!-rq
    v_12854 = (*qfn1(fn))(fn, v_12854);
    goto v_12772;
v_12774:
    v_12854 = stack[-1];
    fn = elt(env, 5); // qqe_rbopp
    v_12854 = (*qfn1(fn))(fn, v_12854);
    env = stack[-2];
    if (v_12854 == nil) goto v_12780;
    v_12854 = stack[0];
    fn = elt(env, 6); // qqe_arg!-check!-lb!-rb
    v_12854 = (*qfn1(fn))(fn, v_12854);
    goto v_12772;
v_12780:
    v_12854 = stack[-1];
    fn = elt(env, 7); // qqe_qopheadp
    v_12854 = (*qfn1(fn))(fn, v_12854);
    env = stack[-2];
    if (v_12854 == nil) goto v_12787;
    else goto v_12785;
v_12787:
    v_12854 = stack[-1];
    fn = elt(env, 8); // qqe_qoptailp
    v_12854 = (*qfn1(fn))(fn, v_12854);
    env = stack[-2];
    if (v_12854 == nil) goto v_12790;
    else goto v_12785;
v_12790:
    goto v_12786;
v_12785:
    v_12854 = stack[0];
    v_12854 = qcdr(v_12854);
    v_12854 = qcar(v_12854);
    fn = elt(env, 9); // qqe_arg!-check!-q
    v_12854 = (*qfn1(fn))(fn, v_12854);
    env = stack[-2];
    if (v_12854 == nil) goto v_12795;
    else goto v_12796;
v_12795:
    fn = elt(env, 10); // qqe_arg!-check!-marked!-ids!-rollback
    v_12854 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_12807;
v_12803:
    v_12855 = stack[0];
    goto v_12804;
v_12805:
    v_12854 = elt(env, 1); // "some arguments are not of queue type"
    goto v_12806;
v_12807:
    goto v_12803;
v_12804:
    goto v_12805;
v_12806:
    fn = elt(env, 11); // typerr
    v_12854 = (*qfn2(fn))(fn, v_12855, v_12854);
    goto v_12794;
v_12796:
v_12794:
    goto v_12772;
v_12786:
    v_12854 = stack[-1];
    fn = elt(env, 12); // qqe_qopaddp
    v_12854 = (*qfn1(fn))(fn, v_12854);
    env = stack[-2];
    if (v_12854 == nil) goto v_12813;
    v_12854 = stack[0];
    fn = elt(env, 13); // qqe_arg!-check!-lb!-rq
    v_12854 = (*qfn1(fn))(fn, v_12854);
    goto v_12772;
v_12813:
    v_12854 = stack[0];
    v_12854 = qcdr(v_12854);
    stack[-1] = v_12854;
v_12823:
    v_12854 = stack[-1];
    if (v_12854 == nil) goto v_12828;
    else goto v_12829;
v_12828:
    goto v_12822;
v_12829:
    v_12854 = stack[-1];
    v_12854 = qcar(v_12854);
    fn = elt(env, 14); // qqe_arg!-check!-b
    v_12854 = (*qfn1(fn))(fn, v_12854);
    env = stack[-2];
    if (v_12854 == nil) goto v_12837;
    else goto v_12838;
v_12837:
    fn = elt(env, 10); // qqe_arg!-check!-marked!-ids!-rollback
    v_12854 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_12847;
v_12843:
    v_12855 = stack[0];
    goto v_12844;
v_12845:
    v_12854 = elt(env, 2); // "some arguments are not of basic type"
    goto v_12846;
v_12847:
    goto v_12843;
v_12844:
    goto v_12845;
v_12846:
    fn = elt(env, 11); // typerr
    v_12854 = (*qfn2(fn))(fn, v_12855, v_12854);
    env = stack[-2];
    goto v_12836;
v_12838:
v_12836:
    v_12854 = stack[-1];
    v_12854 = qcdr(v_12854);
    stack[-1] = v_12854;
    goto v_12823;
v_12822:
    goto v_12772;
v_12772:
    v_12854 = nil;
    return onevalue(v_12854);
}



// Code for reform!-minus

static LispObject CC_reformKminus(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12878, v_12879, v_12880;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12767;
    stack[-1] = v_12766;
// end of prologue
    v_12878 = stack[0];
    if (v_12878 == nil) goto v_12775;
    else goto v_12776;
v_12775:
    v_12878 = lisp_true;
    goto v_12774;
v_12776:
    v_12878 = stack[-1];
    v_12878 = (v_12878 == nil ? lisp_true : nil);
    goto v_12774;
    v_12878 = nil;
v_12774:
    if (v_12878 == nil) goto v_12772;
    v_12878 = stack[-1];
    goto v_12770;
v_12772:
    v_12878 = stack[-1];
    v_12878 = qcar(v_12878);
    goto v_12794;
v_12790:
    goto v_12808;
v_12804:
    v_12879 = stack[0];
    v_12880 = qcar(v_12879);
    goto v_12805;
v_12806:
    v_12879 = elt(env, 1); // minus
    goto v_12807;
v_12808:
    goto v_12804;
v_12805:
    goto v_12806;
v_12807:
    if (!consp(v_12880)) goto v_12802;
    v_12880 = qcar(v_12880);
    if (v_12880 == v_12879) goto v_12801;
    else goto v_12802;
v_12801:
    goto v_12821;
v_12817:
    v_12880 = v_12878;
    goto v_12818;
v_12819:
    v_12879 = elt(env, 2); // quotient
    goto v_12820;
v_12821:
    goto v_12817;
v_12818:
    goto v_12819;
v_12820:
    if (!consp(v_12880)) goto v_12815;
    v_12880 = qcar(v_12880);
    if (v_12880 == v_12879) goto v_12814;
    else goto v_12815;
v_12814:
    goto v_12829;
v_12825:
    v_12879 = v_12878;
    v_12879 = qcdr(v_12879);
    v_12880 = qcar(v_12879);
    goto v_12826;
v_12827:
    v_12879 = elt(env, 1); // minus
    goto v_12828;
v_12829:
    goto v_12825;
v_12826:
    goto v_12827;
v_12828:
    v_12879 = Leqcar(nil, v_12880, v_12879);
    env = stack[-3];
    goto v_12813;
v_12815:
    v_12879 = nil;
    goto v_12813;
    v_12879 = nil;
v_12813:
    goto v_12800;
v_12802:
    v_12879 = nil;
    goto v_12800;
    v_12879 = nil;
v_12800:
    if (v_12879 == nil) goto v_12798;
    goto v_12845;
v_12841:
    stack[-2] = elt(env, 1); // minus
    goto v_12842;
v_12843:
    goto v_12854;
v_12848:
    v_12880 = elt(env, 2); // quotient
    goto v_12849;
v_12850:
    v_12879 = v_12878;
    v_12879 = qcdr(v_12879);
    v_12879 = qcar(v_12879);
    v_12879 = qcdr(v_12879);
    v_12879 = qcar(v_12879);
    goto v_12851;
v_12852:
    v_12878 = qcdr(v_12878);
    v_12878 = qcdr(v_12878);
    v_12878 = qcar(v_12878);
    goto v_12853;
v_12854:
    goto v_12848;
v_12849:
    goto v_12850;
v_12851:
    goto v_12852;
v_12853:
    v_12878 = list3(v_12880, v_12879, v_12878);
    env = stack[-3];
    goto v_12844;
v_12845:
    goto v_12841;
v_12842:
    goto v_12843;
v_12844:
    v_12878 = list2(stack[-2], v_12878);
    env = stack[-3];
    stack[-2] = v_12878;
    goto v_12796;
v_12798:
    stack[-2] = v_12878;
    goto v_12796;
    stack[-2] = nil;
v_12796:
    goto v_12791;
v_12792:
    goto v_12873;
v_12869:
    v_12878 = stack[-1];
    v_12879 = qcdr(v_12878);
    goto v_12870;
v_12871:
    v_12878 = stack[0];
    v_12878 = qcdr(v_12878);
    goto v_12872;
v_12873:
    goto v_12869;
v_12870:
    goto v_12871;
v_12872:
    v_12878 = CC_reformKminus(elt(env, 0), v_12879, v_12878);
    goto v_12793;
v_12794:
    goto v_12790;
v_12791:
    goto v_12792;
v_12793:
    {
        LispObject v_12884 = stack[-2];
        return cons(v_12884, v_12878);
    }
    v_12878 = nil;
v_12770:
    return onevalue(v_12878);
}



// Code for gfdot

static LispObject CC_gfdot(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12793, v_12794, v_12795;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12794 = v_12767;
    v_12795 = v_12766;
// end of prologue
    v_12793 = v_12795;
    v_12793 = qcar(v_12793);
    if (!consp(v_12793)) goto v_12771;
    else goto v_12772;
v_12771:
    goto v_12780;
v_12776:
    v_12793 = v_12795;
    goto v_12777;
v_12778:
    goto v_12779;
v_12780:
    goto v_12776;
v_12777:
    goto v_12778;
v_12779:
    {
        fn = elt(env, 1); // gffdot
        return (*qfn2(fn))(fn, v_12793, v_12794);
    }
v_12772:
    goto v_12790;
v_12786:
    v_12793 = v_12795;
    goto v_12787;
v_12788:
    goto v_12789;
v_12790:
    goto v_12786;
v_12787:
    goto v_12788;
v_12789:
    {
        fn = elt(env, 2); // gbfdot
        return (*qfn2(fn))(fn, v_12793, v_12794);
    }
    v_12793 = nil;
    return onevalue(v_12793);
}



// Code for rdcos!*

static LispObject CC_rdcosH(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12783, v_12784;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12783 = v_12766;
// end of prologue
    fn = elt(env, 1); // convprec
    v_12783 = (*qfn1(fn))(fn, v_12783);
    env = stack[0];
    v_12784 = v_12783;
    v_12783 = v_12784;
    if (!consp(v_12783)) goto v_12774;
    else goto v_12775;
v_12774:
    v_12783 = v_12784;
    fn = elt(env, 2); // cos
    v_12783 = (*qfn1(fn))(fn, v_12783);
    env = stack[0];
    goto v_12773;
v_12775:
    v_12783 = v_12784;
    fn = elt(env, 3); // cos!*
    v_12783 = (*qfn1(fn))(fn, v_12783);
    env = stack[0];
    goto v_12773;
    v_12783 = nil;
v_12773:
    {
        fn = elt(env, 4); // mkround
        return (*qfn1(fn))(fn, v_12783);
    }
}



// Code for begin11

static LispObject CC_begin11(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_13311, v_13312;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_12766;
// end of prologue
// Binding errmsg!*
// FLUIDBIND: reloadenv=6 litvec-offset=1 saveloc=5
{   bind_fluid_stack bind_fluid_var(-6, 1, -5);
    qvalue(elt(env, 1)) = nil; // errmsg!*
    stack[-3] = nil;
// Binding newrule!*
// FLUIDBIND: reloadenv=6 litvec-offset=2 saveloc=2
{   bind_fluid_stack bind_fluid_var(-6, 2, -2);
    qvalue(elt(env, 2)) = nil; // newrule!*
    goto v_12783;
v_12779:
    v_13312 = qvalue(elt(env, 4)); // cursym!*
    goto v_12780;
v_12781:
    v_13311 = elt(env, 5); // end
    goto v_12782;
v_12783:
    goto v_12779;
v_12780:
    goto v_12781;
v_12782:
    if (v_13312 == v_13311) goto v_12777;
    else goto v_12778;
v_12777:
    fn = elt(env, 48); // terminalp
    v_13311 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    if (v_13311 == nil) goto v_12789;
    v_13311 = qvalue(elt(env, 6)); // !*lisp_hook
    if (v_13311 == nil) goto v_12792;
    else goto v_12789;
v_12792:
    v_13311 = elt(env, 7); // !*semicol!*
    qvalue(elt(env, 4)) = v_13311; // cursym!*
    v_13311 = nil;
    qvalue(elt(env, 8)) = v_13311; // curescaped!*
    v_13311 = lisp_true;
    qvalue(elt(env, 9)) = v_13311; // !*nosave!*
    v_13311 = nil;
    goto v_12773;
v_12789:
    v_13311 = elt(env, 5); // end
    fn = elt(env, 49); // comm1
    v_13311 = (*qfn1(fn))(fn, v_13311);
    env = stack[-6];
    v_13311 = elt(env, 5); // end
    goto v_12773;
    goto v_12776;
v_12778:
    goto v_12810;
v_12806:
    v_13311 = qvalue(elt(env, 10)); // !*reduce4
    if (v_13311 == nil) goto v_12814;
    v_13311 = stack[-4];
    v_13312 = v_13311;
    goto v_12812;
v_12814:
    v_13311 = stack[-4];
    v_13311 = qcdr(v_13311);
    v_13311 = qcar(v_13311);
    v_13312 = v_13311;
    goto v_12812;
    v_13312 = nil;
v_12812:
    goto v_12807;
v_12808:
    v_13311 = elt(env, 11); // retry
    goto v_12809;
v_12810:
    goto v_12806;
v_12807:
    goto v_12808;
v_12809:
    if (!consp(v_13312)) goto v_12804;
    v_13312 = qcar(v_13312);
    if (v_13312 == v_13311) goto v_12803;
    else goto v_12804;
v_12803:
    v_13311 = qvalue(elt(env, 12)); // programl!*
    if (v_13311 == nil) goto v_12826;
    v_13311 = qvalue(elt(env, 12)); // programl!*
    stack[-4] = v_13311;
    goto v_12824;
v_12826:
    v_13311 = elt(env, 13); // "No previous expression"
    fn = elt(env, 50); // lprim
    v_13311 = (*qfn1(fn))(fn, v_13311);
    v_13311 = nil;
    goto v_12773;
v_12824:
    goto v_12776;
v_12804:
v_12776:
    v_13311 = qvalue(elt(env, 10)); // !*reduce4
    if (v_13311 == nil) goto v_12836;
    else goto v_12837;
v_12836:
    v_13311 = stack[-4];
    v_13311 = qcar(v_13311);
    stack[-3] = v_13311;
    v_13311 = stack[-4];
    v_13311 = qcdr(v_13311);
    v_13311 = qcar(v_13311);
    stack[-4] = v_13311;
    goto v_12835;
v_12837:
v_12835:
    v_13311 = stack[-4];
    qvalue(elt(env, 14)) = v_13311; // program!*
    fn = elt(env, 51); // eofcheck
    v_13311 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    if (v_13311 == nil) goto v_12848;
    v_13311 = elt(env, 15); // c
    goto v_12773;
v_12848:
    v_13311 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 16)) = v_13311; // eof!*
    goto v_12846;
v_12846:
    goto v_12859;
v_12855:
    v_13312 = stack[-4];
    goto v_12856;
v_12857:
    v_13311 = qvalue(elt(env, 10)); // !*reduce4
    if (v_13311 == nil) goto v_12864;
    v_13311 = nil;
    goto v_12862;
v_12864:
    v_13311 = stack[-3];
    goto v_12862;
    v_13311 = nil;
v_12862:
    goto v_12858;
v_12859:
    goto v_12855;
v_12856:
    goto v_12857;
v_12858:
    fn = elt(env, 52); // add2inputbuf
    v_13311 = (*qfn2(fn))(fn, v_13312, v_13311);
    env = stack[-6];
    v_13311 = stack[-4];
    if (!consp(v_13311)) goto v_12877;
    goto v_12883;
v_12879:
    v_13311 = stack[-4];
    v_13312 = qcar(v_13311);
    goto v_12880;
v_12881:
    v_13311 = elt(env, 17); // (bye quit)
    goto v_12882;
v_12883:
    goto v_12879;
v_12880:
    goto v_12881;
v_12882:
    v_13311 = Lmemq(nil, v_13312, v_13311);
    goto v_12875;
v_12877:
    v_13311 = nil;
    goto v_12875;
    v_13311 = nil;
v_12875:
    if (v_13311 == nil) goto v_12873;
    v_13311 = elt(env, 18); // bye
    fn = elt(env, 53); // getd
    v_13311 = (*qfn1(fn))(fn, v_13311);
    env = stack[-6];
    if (v_13311 == nil) goto v_12894;
    v_13311 = stack[-4];
    fn = elt(env, 54); // lispeval
    v_13311 = (*qfn1(fn))(fn, v_13311);
    env = stack[-6];
    v_13311 = lisp_true;
    qvalue(elt(env, 9)) = v_13311; // !*nosave!*
    v_13311 = nil;
    goto v_12773;
v_12894:
    v_13311 = lisp_true;
    qvalue(elt(env, 19)) = v_13311; // !*byeflag!*
    v_13311 = nil;
    goto v_12773;
    goto v_12871;
v_12873:
    v_13311 = qvalue(elt(env, 10)); // !*reduce4
    if (v_13311 == nil) goto v_12909;
    else goto v_12910;
v_12909:
    goto v_12917;
v_12913:
    v_13312 = stack[-4];
    goto v_12914;
v_12915:
    v_13311 = elt(env, 20); // ed
    goto v_12916;
v_12917:
    goto v_12913;
v_12914:
    goto v_12915;
v_12916:
    v_13311 = Leqcar(nil, v_13312, v_13311);
    env = stack[-6];
    goto v_12908;
v_12910:
    v_13311 = nil;
    goto v_12908;
    v_13311 = nil;
v_12908:
    if (v_13311 == nil) goto v_12906;
    v_13311 = elt(env, 21); // cedit
    fn = elt(env, 53); // getd
    v_13311 = (*qfn1(fn))(fn, v_13311);
    env = stack[-6];
    if (v_13311 == nil) goto v_12926;
    fn = elt(env, 48); // terminalp
    v_13311 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    if (v_13311 == nil) goto v_12926;
    v_13311 = stack[-4];
    v_13311 = qcdr(v_13311);
    fn = elt(env, 21); // cedit
    v_13311 = (*qfn1(fn))(fn, v_13311);
    env = stack[-6];
    goto v_12924;
v_12926:
    v_13311 = elt(env, 22); // "ED not supported"
    fn = elt(env, 50); // lprim
    v_13311 = (*qfn1(fn))(fn, v_13311);
    env = stack[-6];
    goto v_12924;
v_12924:
    v_13311 = lisp_true;
    qvalue(elt(env, 9)) = v_13311; // !*nosave!*
    v_13311 = nil;
    goto v_12773;
v_12906:
    v_13311 = qvalue(elt(env, 23)); // !*defn
    if (v_13311 == nil) goto v_12942;
    v_13311 = qvalue(elt(env, 24)); // erfg!*
    if (v_13311 == nil) goto v_12947;
    v_13311 = nil;
    goto v_12773;
v_12947:
    goto v_12961;
v_12957:
    v_13312 = qvalue(elt(env, 25)); // key!*
    goto v_12958;
v_12959:
    v_13311 = elt(env, 26); // ignore
    goto v_12960;
v_12961:
    goto v_12957;
v_12958:
    goto v_12959;
v_12960:
    v_13311 = Lflagp(nil, v_13312, v_13311);
    env = stack[-6];
    if (v_13311 == nil) goto v_12954;
    else goto v_12955;
v_12954:
    goto v_12969;
v_12965:
    v_13312 = stack[-4];
    goto v_12966;
v_12967:
    v_13311 = elt(env, 27); // quote
    goto v_12968;
v_12969:
    goto v_12965;
v_12966:
    goto v_12967;
v_12968:
    v_13311 = Leqcar(nil, v_13312, v_13311);
    env = stack[-6];
    v_13311 = (v_13311 == nil ? lisp_true : nil);
    goto v_12953;
v_12955:
    v_13311 = nil;
    goto v_12953;
    v_13311 = nil;
v_12953:
    if (v_13311 == nil) goto v_12951;
    v_13311 = stack[-4];
    if (v_13311 == nil) goto v_12979;
    v_13311 = stack[-4];
    fn = elt(env, 55); // dfprint
    v_13311 = (*qfn1(fn))(fn, v_13311);
    env = stack[-6];
    goto v_12977;
v_12979:
    goto v_12977;
v_12977:
    goto v_12995;
v_12991:
    v_13312 = qvalue(elt(env, 25)); // key!*
    goto v_12992;
v_12993:
    v_13311 = elt(env, 28); // eval
    goto v_12994;
v_12995:
    goto v_12991;
v_12992:
    goto v_12993;
v_12994:
    v_13311 = Lflagp(nil, v_13312, v_13311);
    env = stack[-6];
    if (v_13311 == nil) goto v_12988;
    else goto v_12989;
v_12988:
    v_13311 = nil;
    goto v_12773;
v_12989:
    goto v_12945;
v_12951:
v_12945:
    goto v_12871;
v_12942:
v_12871:
    v_13311 = qvalue(elt(env, 29)); // !*output
    if (v_13311 == nil) goto v_13002;
    v_13311 = qvalue(elt(env, 30)); // ifl!*
    if (v_13311 == nil) goto v_13002;
    v_13311 = qvalue(elt(env, 31)); // !*echo
    if (v_13311 == nil) goto v_13002;
    v_13311 = qvalue(elt(env, 32)); // !*lessspace
    if (v_13311 == nil) goto v_13011;
    else goto v_13002;
v_13011:
    v_13311 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_13000;
v_13002:
v_13000:
    v_13311 = qvalue(elt(env, 33)); // ulimit!*
    v_13311 = integerp(v_13311);
    if (v_13311 == nil) goto v_13017;
    goto v_13025;
v_13021:
    v_13312 = qvalue(elt(env, 33)); // ulimit!*
    goto v_13022;
v_13023:
    v_13311 = stack[-4];
    goto v_13024;
v_13025:
    goto v_13021;
v_13022:
    goto v_13023;
v_13024:
    fn = elt(env, 56); // errorset_with_timeout
    v_13311 = (*qfn2(fn))(fn, v_13312, v_13311);
    env = stack[-6];
    stack[0] = v_13311;
    v_13311 = stack[0];
    if (!consp(v_13311)) goto v_13031;
    v_13311 = stack[0];
    v_13311 = qcar(v_13311);
    stack[0] = v_13311;
    goto v_13029;
v_13031:
v_13029:
    goto v_13015;
v_13017:
    goto v_13042;
v_13038:
    v_13312 = stack[-4];
    goto v_13039;
v_13040:
    v_13311 = lisp_true;
    goto v_13041;
v_13042:
    goto v_13038;
v_13039:
    goto v_13040;
v_13041:
    fn = elt(env, 57); // errorset!*
    v_13311 = (*qfn2(fn))(fn, v_13312, v_13311);
    env = stack[-6];
    stack[0] = v_13311;
    goto v_13015;
v_13015:
    v_13311 = stack[0];
    fn = elt(env, 58); // errorp
    v_13311 = (*qfn1(fn))(fn, v_13311);
    env = stack[-6];
    if (v_13311 == nil) goto v_13049;
    else goto v_13047;
v_13049:
    v_13311 = qvalue(elt(env, 24)); // erfg!*
    if (v_13311 == nil) goto v_13052;
    else goto v_13047;
v_13052:
    goto v_13048;
v_13047:
    goto v_13059;
v_13055:
    v_13312 = stack[-3];
    goto v_13056;
v_13057:
    v_13311 = stack[-4];
    goto v_13058;
v_13059:
    goto v_13055;
v_13056:
    goto v_13057;
v_13058:
    v_13311 = list2(v_13312, v_13311);
    env = stack[-6];
    qvalue(elt(env, 12)) = v_13311; // programl!*
    v_13311 = elt(env, 34); // err2
    goto v_12773;
v_13048:
    v_13311 = qvalue(elt(env, 23)); // !*defn
    if (v_13311 == nil) goto v_13064;
    v_13311 = nil;
    goto v_12773;
v_13064:
    v_13311 = qvalue(elt(env, 10)); // !*reduce4
    if (v_13311 == nil) goto v_13069;
    else goto v_13070;
v_13069:
    goto v_13080;
v_13076:
    v_13312 = stack[-3];
    goto v_13077;
v_13078:
    v_13311 = elt(env, 35); // symbolic
    goto v_13079;
v_13080:
    goto v_13076;
v_13077:
    goto v_13078;
v_13079:
    if (v_13312 == v_13311) goto v_13075;
    v_13311 = stack[-4];
    fn = elt(env, 59); // getsetvars
    v_13311 = (*qfn1(fn))(fn, v_13311);
    env = stack[-6];
    stack[-4] = v_13311;
    goto v_13073;
v_13075:
    goto v_13073;
v_13073:
    goto v_13068;
v_13070:
    v_13311 = stack[0];
    v_13311 = qcar(v_13311);
    stack[0] = v_13311;
    v_13311 = stack[0];
    if (v_13311 == nil) goto v_13094;
    else goto v_13095;
v_13094:
    goto v_13102;
v_13098:
    v_13312 = nil;
    goto v_13099;
v_13100:
    v_13311 = elt(env, 36); // noval
    goto v_13101;
v_13102:
    goto v_13098;
v_13099:
    goto v_13100;
v_13101:
    fn = elt(env, 60); // mkobject
    v_13311 = (*qfn2(fn))(fn, v_13312, v_13311);
    env = stack[-6];
    stack[0] = v_13311;
    goto v_13093;
v_13095:
v_13093:
    v_13311 = stack[0];
    fn = elt(env, 61); // type
    v_13311 = (*qfn1(fn))(fn, v_13311);
    env = stack[-6];
    stack[-3] = v_13311;
    v_13311 = stack[0];
    fn = elt(env, 62); // value
    v_13311 = (*qfn1(fn))(fn, v_13311);
    env = stack[-6];
    stack[0] = v_13311;
    goto v_13068;
v_13068:
    goto v_13114;
v_13110:
    v_13311 = qvalue(elt(env, 10)); // !*reduce4
    if (v_13311 == nil) goto v_13117;
    else goto v_13118;
v_13117:
    v_13311 = stack[0];
    v_13311 = qcar(v_13311);
    v_13312 = v_13311;
    goto v_13116;
v_13118:
    v_13311 = stack[0];
    v_13312 = v_13311;
    goto v_13116;
    v_13312 = nil;
v_13116:
    goto v_13111;
v_13112:
    v_13311 = stack[-3];
    goto v_13113;
v_13114:
    goto v_13110;
v_13111:
    goto v_13112;
v_13113:
    fn = elt(env, 63); // add2resultbuf
    v_13311 = (*qfn2(fn))(fn, v_13312, v_13311);
    env = stack[-6];
    v_13311 = qvalue(elt(env, 29)); // !*output
    if (v_13311 == nil) goto v_13128;
    else goto v_13129;
v_13128:
    v_13311 = nil;
    goto v_12773;
v_13129:
    goto v_13138;
v_13134:
    v_13312 = qvalue(elt(env, 37)); // semic!*
    goto v_13135;
v_13136:
    v_13311 = elt(env, 38); // !$
    goto v_13137;
v_13138:
    goto v_13134;
v_13135:
    goto v_13136;
v_13137:
    if (v_13312 == v_13311) goto v_13133;
    v_13311 = qvalue(elt(env, 10)); // !*reduce4
    if (v_13311 == nil) goto v_13144;
    v_13311 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_13158;
v_13154:
    v_13312 = stack[-3];
    goto v_13155;
v_13156:
    v_13311 = elt(env, 36); // noval
    goto v_13157;
v_13158:
    goto v_13154;
v_13155:
    goto v_13156;
v_13157:
    if (v_13312 == v_13311) goto v_13152;
    else goto v_13153;
v_13152:
    goto v_13147;
v_13153:
    v_13311 = qvalue(elt(env, 39)); // !*debug
    if (v_13311 == nil) goto v_13163;
    v_13311 = elt(env, 40); // "Value:"
    fn = elt(env, 64); // prin2t
    v_13311 = (*qfn1(fn))(fn, v_13311);
    env = stack[-6];
    goto v_13151;
v_13163:
v_13151:
    goto v_13172;
v_13168:
    stack[-1] = elt(env, 41); // print
    goto v_13169;
v_13170:
    goto v_13180;
v_13176:
    v_13312 = stack[-3];
    goto v_13177;
v_13178:
    v_13311 = stack[0];
    goto v_13179;
v_13180:
    goto v_13176;
v_13177:
    goto v_13178;
v_13179:
    v_13311 = list2(v_13312, v_13311);
    env = stack[-6];
    v_13311 = ncons(v_13311);
    env = stack[-6];
    goto v_13171;
v_13172:
    goto v_13168;
v_13169:
    goto v_13170;
v_13171:
    fn = elt(env, 65); // rapply1
    v_13311 = (*qfn2(fn))(fn, stack[-1], v_13311);
    env = stack[-6];
v_13147:
    goto v_13142;
v_13144:
    goto v_13189;
v_13185:
    v_13312 = stack[-3];
    goto v_13186;
v_13187:
    v_13311 = elt(env, 35); // symbolic
    goto v_13188;
v_13189:
    goto v_13185;
v_13186:
    goto v_13187;
v_13188:
    if (v_13312 == v_13311) goto v_13183;
    else goto v_13184;
v_13183:
    v_13311 = stack[0];
    v_13311 = qcar(v_13311);
    if (v_13311 == nil) goto v_13198;
    else goto v_13199;
v_13198:
    goto v_13206;
v_13202:
    v_13312 = qvalue(elt(env, 42)); // !*mode
    goto v_13203;
v_13204:
    v_13311 = elt(env, 35); // symbolic
    goto v_13205;
v_13206:
    goto v_13202;
v_13203:
    goto v_13204;
v_13205:
    v_13311 = (v_13312 == v_13311 ? lisp_true : nil);
    v_13311 = (v_13311 == nil ? lisp_true : nil);
    goto v_13197;
v_13199:
    v_13311 = nil;
    goto v_13197;
    v_13311 = nil;
v_13197:
    if (v_13311 == nil) goto v_13195;
    goto v_13193;
v_13195:
    v_13311 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_13226;
v_13222:
    goto v_13232;
v_13228:
    stack[-1] = elt(env, 41); // print
    goto v_13229;
v_13230:
    v_13311 = stack[0];
    v_13311 = qcar(v_13311);
    v_13311 = Lmkquote(nil, v_13311);
    env = stack[-6];
    goto v_13231;
v_13232:
    goto v_13228;
v_13229:
    goto v_13230;
v_13231:
    v_13312 = list2(stack[-1], v_13311);
    env = stack[-6];
    goto v_13223;
v_13224:
    v_13311 = lisp_true;
    goto v_13225;
v_13226:
    goto v_13222;
v_13223:
    goto v_13224;
v_13225:
    fn = elt(env, 57); // errorset!*
    v_13311 = (*qfn2(fn))(fn, v_13312, v_13311);
    env = stack[-6];
    stack[0] = v_13311;
    goto v_13193;
v_13193:
    goto v_13142;
v_13184:
    v_13311 = stack[0];
    v_13311 = qcar(v_13311);
    if (v_13311 == nil) goto v_13239;
    goto v_13247;
v_13243:
    goto v_13257;
v_13249:
    stack[-1] = elt(env, 43); // assgnpri
    goto v_13250;
v_13251:
    v_13311 = stack[0];
    v_13311 = qcar(v_13311);
    stack[0] = Lmkquote(nil, v_13311);
    env = stack[-6];
    goto v_13252;
v_13253:
    v_13311 = stack[-4];
    if (v_13311 == nil) goto v_13265;
    goto v_13272;
v_13268:
    v_13312 = elt(env, 44); // list
    goto v_13269;
v_13270:
    v_13311 = stack[-4];
    goto v_13271;
v_13272:
    goto v_13268;
v_13269:
    goto v_13270;
v_13271:
    v_13311 = cons(v_13312, v_13311);
    env = stack[-6];
    stack[-4] = v_13311;
    goto v_13263;
v_13265:
    v_13311 = nil;
    stack[-4] = v_13311;
    goto v_13263;
    stack[-4] = nil;
v_13263:
    goto v_13254;
v_13255:
    v_13311 = elt(env, 45); // only
    v_13311 = Lmkquote(nil, v_13311);
    env = stack[-6];
    goto v_13256;
v_13257:
    goto v_13249;
v_13250:
    goto v_13251;
v_13252:
    goto v_13253;
v_13254:
    goto v_13255;
v_13256:
    v_13312 = list4(stack[-1], stack[0], stack[-4], v_13311);
    env = stack[-6];
    goto v_13244;
v_13245:
    v_13311 = lisp_true;
    goto v_13246;
v_13247:
    goto v_13243;
v_13244:
    goto v_13245;
v_13246:
    fn = elt(env, 57); // errorset!*
    v_13311 = (*qfn2(fn))(fn, v_13312, v_13311);
    env = stack[-6];
    stack[0] = v_13311;
    goto v_13142;
v_13239:
v_13142:
    goto v_13127;
v_13133:
v_13127:
    v_13311 = qvalue(elt(env, 10)); // !*reduce4
    if (v_13311 == nil) goto v_13283;
    else goto v_13284;
v_13283:
    v_13311 = stack[0];
    fn = elt(env, 58); // errorp
    v_13311 = (*qfn1(fn))(fn, v_13311);
    env = stack[-6];
    if (v_13311 == nil) goto v_13289;
    v_13311 = elt(env, 46); // err3
    goto v_13287;
v_13289:
    v_13311 = nil;
    goto v_13287;
    v_13311 = nil;
v_13287:
    goto v_12773;
v_13284:
    goto v_13302;
v_13298:
    v_13312 = qvalue(elt(env, 42)); // !*mode
    goto v_13299;
v_13300:
    v_13311 = elt(env, 36); // noval
    goto v_13301;
v_13302:
    goto v_13298;
v_13299:
    goto v_13300;
v_13301:
    if (v_13312 == v_13311) goto v_13297;
    v_13311 = Lterpri(nil, 0);
    env = stack[-6];
    v_13311 = elt(env, 47); // "of type: "
    v_13311 = Lprinc(nil, v_13311);
    env = stack[-6];
    v_13311 = stack[-3];
    v_13311 = Lprint(nil, v_13311);
    goto v_13282;
v_13297:
v_13282:
    v_13311 = nil;
v_12773:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_13311);
}



// Code for mv!-domainlist!-!+

static LispObject CC_mvKdomainlistKL(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12803, v_12804;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12767;
    stack[-1] = v_12766;
// end of prologue
    stack[-2] = nil;
v_12772:
    v_12803 = stack[-1];
    if (v_12803 == nil) goto v_12775;
    else goto v_12776;
v_12775:
    v_12803 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12803);
    }
v_12776:
    goto v_12787;
v_12783:
    goto v_12793;
v_12789:
    v_12803 = stack[-1];
    v_12804 = qcar(v_12803);
    goto v_12790;
v_12791:
    v_12803 = stack[0];
    v_12803 = qcar(v_12803);
    goto v_12792;
v_12793:
    goto v_12789;
v_12790:
    goto v_12791;
v_12792:
    v_12804 = plus2(v_12804, v_12803);
    env = stack[-3];
    goto v_12784;
v_12785:
    v_12803 = stack[-2];
    goto v_12786;
v_12787:
    goto v_12783;
v_12784:
    goto v_12785;
v_12786:
    v_12803 = cons(v_12804, v_12803);
    env = stack[-3];
    stack[-2] = v_12803;
    v_12803 = stack[-1];
    v_12803 = qcdr(v_12803);
    stack[-1] = v_12803;
    v_12803 = stack[0];
    v_12803 = qcdr(v_12803);
    stack[0] = v_12803;
    goto v_12772;
    v_12803 = nil;
    return onevalue(v_12803);
}



// Code for prepd1

static LispObject CC_prepd1(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12792, v_12793, v_12794;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
// copy arguments values to proper place
    v_12794 = v_12766;
// end of prologue
    v_12792 = v_12794;
    if (!consp(v_12792)) goto v_12770;
    else goto v_12771;
v_12770:
    v_12792 = v_12794;
    goto v_12769;
v_12771:
    goto v_12781;
v_12777:
    goto v_12787;
v_12783:
    v_12792 = v_12794;
    v_12793 = qcar(v_12792);
    goto v_12784;
v_12785:
    v_12792 = elt(env, 1); // prepfn
    goto v_12786;
v_12787:
    goto v_12783;
v_12784:
    goto v_12785;
v_12786:
    v_12792 = get(v_12793, v_12792);
    goto v_12778;
v_12779:
    v_12793 = v_12794;
    goto v_12780;
v_12781:
    goto v_12777;
v_12778:
    goto v_12779;
v_12780:
        return Lapply1(nil, v_12792, v_12793);
    v_12792 = nil;
v_12769:
    return onevalue(v_12792);
}



// Code for moid_member

static LispObject CC_moid_member(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12798, v_12799;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12767;
    stack[-1] = v_12766;
// end of prologue
v_12765:
    v_12798 = stack[0];
    if (v_12798 == nil) goto v_12771;
    else goto v_12772;
v_12771:
    v_12798 = nil;
    goto v_12770;
v_12772:
    goto v_12785;
v_12781:
    v_12798 = stack[0];
    v_12799 = qcar(v_12798);
    goto v_12782;
v_12783:
    v_12798 = stack[-1];
    goto v_12784;
v_12785:
    goto v_12781;
v_12782:
    goto v_12783;
v_12784:
    fn = elt(env, 1); // mo_vdivides!?
    v_12798 = (*qfn2(fn))(fn, v_12799, v_12798);
    env = stack[-2];
    if (v_12798 == nil) goto v_12779;
    else goto v_12778;
v_12779:
    goto v_12794;
v_12790:
    v_12799 = stack[-1];
    goto v_12791;
v_12792:
    v_12798 = stack[0];
    v_12798 = qcdr(v_12798);
    goto v_12793;
v_12794:
    goto v_12790;
v_12791:
    goto v_12792;
v_12793:
    stack[-1] = v_12799;
    stack[0] = v_12798;
    goto v_12765;
v_12778:
    goto v_12770;
    v_12798 = nil;
v_12770:
    return onevalue(v_12798);
}



// Code for arglist_member

static LispObject CC_arglist_member(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12798, v_12799;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12767;
    stack[-1] = v_12766;
// end of prologue
v_12765:
    v_12798 = stack[0];
    if (!consp(v_12798)) goto v_12772;
    goto v_12782;
v_12778:
    v_12799 = stack[-1];
    goto v_12779;
v_12780:
    v_12798 = stack[0];
    v_12798 = qcar(v_12798);
    goto v_12781;
v_12782:
    goto v_12778;
v_12779:
    goto v_12780;
v_12781:
    fn = elt(env, 1); // mvar_member
    v_12798 = (*qfn2(fn))(fn, v_12799, v_12798);
    env = stack[-2];
    if (v_12798 == nil) goto v_12776;
    else goto v_12775;
v_12776:
    goto v_12791;
v_12787:
    v_12799 = stack[-1];
    goto v_12788;
v_12789:
    v_12798 = stack[0];
    v_12798 = qcdr(v_12798);
    goto v_12790;
v_12791:
    goto v_12787;
v_12788:
    goto v_12789;
v_12790:
    stack[-1] = v_12799;
    stack[0] = v_12798;
    goto v_12765;
v_12775:
    goto v_12770;
v_12772:
    v_12798 = nil;
    goto v_12770;
    v_12798 = nil;
v_12770:
    return onevalue(v_12798);
}



// Code for gcref_mkgraph

static LispObject CC_gcref_mkgraph(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12779, v_12780;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12780 = v_12766;
// end of prologue
    v_12779 = qvalue(elt(env, 1)); // !*gcrefudg
    if (v_12779 == nil) goto v_12771;
    v_12779 = v_12780;
    {
        fn = elt(env, 2); // gcref_mkgraph!-udg
        return (*qfn1(fn))(fn, v_12779);
    }
v_12771:
    v_12779 = v_12780;
    {
        fn = elt(env, 3); // gcref_mkgraph!-tgf
        return (*qfn1(fn))(fn, v_12779);
    }
    v_12779 = nil;
    return onevalue(v_12779);
}



// Code for revalx

static LispObject CC_revalx(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12790, v_12791;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12791 = v_12766;
// end of prologue
    v_12790 = v_12791;
    if (!consp(v_12790)) goto v_12776;
    v_12790 = v_12791;
    v_12790 = qcar(v_12790);
    v_12790 = (consp(v_12790) ? nil : lisp_true);
    v_12790 = (v_12790 == nil ? lisp_true : nil);
    goto v_12774;
v_12776:
    v_12790 = nil;
    goto v_12774;
    v_12790 = nil;
v_12774:
    if (v_12790 == nil) goto v_12772;
    v_12790 = v_12791;
    fn = elt(env, 1); // prepf
    v_12790 = (*qfn1(fn))(fn, v_12790);
    env = stack[0];
    goto v_12770;
v_12772:
    v_12790 = v_12791;
    goto v_12770;
    v_12790 = nil;
v_12770:
    {
        fn = elt(env, 2); // reval
        return (*qfn1(fn))(fn, v_12790);
    }
}



// Code for getsetvars

static LispObject CC_getsetvars(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12834, v_12835;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12766;
// end of prologue
    stack[-1] = nil;
v_12771:
    v_12834 = stack[0];
    if (!consp(v_12834)) goto v_12774;
    else goto v_12775;
v_12774:
    v_12834 = stack[-1];
    {
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(fn, v_12834);
    }
v_12775:
    goto v_12785;
v_12781:
    v_12834 = stack[0];
    v_12835 = qcar(v_12834);
    goto v_12782;
v_12783:
    v_12834 = elt(env, 1); // (setel setk)
    goto v_12784;
v_12785:
    goto v_12781;
v_12782:
    goto v_12783;
v_12784:
    v_12834 = Lmemq(nil, v_12835, v_12834);
    if (v_12834 == nil) goto v_12780;
    goto v_12795;
v_12791:
    v_12834 = stack[0];
    v_12834 = qcdr(v_12834);
    v_12834 = qcar(v_12834);
    fn = elt(env, 4); // getsetvarlis
    v_12835 = (*qfn1(fn))(fn, v_12834);
    env = stack[-2];
    goto v_12792;
v_12793:
    v_12834 = stack[-1];
    goto v_12794;
v_12795:
    goto v_12791;
v_12792:
    goto v_12793;
v_12794:
    v_12834 = cons(v_12835, v_12834);
    env = stack[-2];
    stack[-1] = v_12834;
    v_12834 = stack[0];
    v_12834 = qcdr(v_12834);
    v_12834 = qcdr(v_12834);
    v_12834 = qcar(v_12834);
    stack[0] = v_12834;
    goto v_12771;
v_12780:
    goto v_12811;
v_12807:
    v_12834 = stack[0];
    v_12835 = qcar(v_12834);
    goto v_12808;
v_12809:
    v_12834 = elt(env, 2); // setq
    goto v_12810;
v_12811:
    goto v_12807;
v_12808:
    goto v_12809;
v_12810:
    if (v_12835 == v_12834) goto v_12805;
    else goto v_12806;
v_12805:
    goto v_12820;
v_12816:
    v_12834 = stack[0];
    v_12834 = qcdr(v_12834);
    v_12834 = qcar(v_12834);
    v_12835 = Lmkquote(nil, v_12834);
    env = stack[-2];
    goto v_12817;
v_12818:
    v_12834 = stack[-1];
    goto v_12819;
v_12820:
    goto v_12816;
v_12817:
    goto v_12818;
v_12819:
    v_12834 = cons(v_12835, v_12834);
    env = stack[-2];
    stack[-1] = v_12834;
    v_12834 = stack[0];
    v_12834 = qcdr(v_12834);
    v_12834 = qcdr(v_12834);
    v_12834 = qcar(v_12834);
    stack[0] = v_12834;
    goto v_12771;
v_12806:
    v_12834 = stack[-1];
    {
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(fn, v_12834);
    }
    v_12834 = nil;
    return onevalue(v_12834);
}



// Code for evdif

static LispObject CC_evdif(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12818, v_12819, v_12820;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12767;
    stack[-1] = v_12766;
// end of prologue
    v_12820 = nil;
v_12775:
    v_12818 = stack[0];
    if (v_12818 == nil) goto v_12778;
    else goto v_12779;
v_12778:
    goto v_12774;
v_12779:
    v_12818 = stack[-1];
    if (v_12818 == nil) goto v_12784;
    else goto v_12785;
v_12784:
    v_12818 = elt(env, 2); // (0)
    stack[-1] = v_12818;
    goto v_12783;
v_12785:
v_12783:
    goto v_12793;
v_12789:
    goto v_12798;
v_12794:
    v_12818 = stack[-1];
    v_12819 = qcar(v_12818);
    goto v_12795;
v_12796:
    v_12818 = stack[0];
    v_12818 = qcar(v_12818);
    goto v_12797;
v_12798:
    goto v_12794;
v_12795:
    goto v_12796;
v_12797:
    v_12818 = (LispObject)(intptr_t)((intptr_t)v_12819 - (intptr_t)v_12818 + TAG_FIXNUM);
    goto v_12790;
v_12791:
    v_12819 = v_12820;
    goto v_12792;
v_12793:
    goto v_12789;
v_12790:
    goto v_12791;
v_12792:
    v_12818 = cons(v_12818, v_12819);
    env = stack[-2];
    v_12820 = v_12818;
    v_12818 = stack[-1];
    v_12818 = qcdr(v_12818);
    stack[-1] = v_12818;
    v_12818 = stack[0];
    v_12818 = qcdr(v_12818);
    stack[0] = v_12818;
    goto v_12775;
v_12774:
    goto v_12814;
v_12810:
    v_12818 = v_12820;
    v_12819 = Lnreverse(nil, v_12818);
    goto v_12811;
v_12812:
    v_12818 = stack[-1];
    goto v_12813;
v_12814:
    goto v_12810;
v_12811:
    goto v_12812;
v_12813:
        return Lnconc(nil, v_12819, v_12818);
    return onevalue(v_12818);
}



// Code for xdegreecheck

static LispObject CC_xdegreecheck(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12785, v_12786;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12786 = v_12766;
// end of prologue
    v_12785 = qvalue(elt(env, 1)); // xtruncate!*
    if (v_12785 == nil) goto v_12770;
    else goto v_12771;
v_12770:
    v_12785 = nil;
    goto v_12769;
v_12771:
    goto v_12781;
v_12777:
    v_12785 = v_12786;
    fn = elt(env, 2); // xdegree
    v_12785 = (*qfn1(fn))(fn, v_12785);
    env = stack[0];
    goto v_12778;
v_12779:
    v_12786 = qvalue(elt(env, 1)); // xtruncate!*
    goto v_12780;
v_12781:
    goto v_12777;
v_12778:
    goto v_12779;
v_12780:
        return Lgreaterp(nil, v_12785, v_12786);
    v_12785 = nil;
v_12769:
    return onevalue(v_12785);
}



// Code for physopsm!*

static LispObject CC_physopsmH(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_13034, v_13035, v_13036, v_13037;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_12766;
// end of prologue
    stack[0] = nil;
    v_13034 = stack[-3];
    if (v_13034 == nil) goto v_12782;
    else goto v_12783;
v_12782:
    v_13034 = lisp_true;
    goto v_12781;
v_12783:
    v_13034 = stack[-3];
    v_13034 = (is_number(v_13034) ? lisp_true : nil);
    goto v_12781;
    v_13034 = nil;
v_12781:
    if (v_13034 == nil) goto v_12779;
    v_13034 = stack[-3];
    stack[0] = v_13034;
    goto v_12777;
v_12779:
    v_13034 = stack[-3];
    fn = elt(env, 12); // physopp
    v_13034 = (*qfn1(fn))(fn, v_13034);
    env = stack[-5];
    if (v_13034 == nil) goto v_12792;
    v_13034 = stack[-3];
    if (!symbolp(v_13034)) v_13034 = nil;
    else { v_13034 = qfastgets(v_13034);
           if (v_13034 != nil) { v_13034 = elt(v_13034, 46); // rvalue
#ifdef RECORD_GET
             if (v_13034 != SPID_NOPROP)
                record_get(elt(fastget_names, 46), 1);
             else record_get(elt(fastget_names, 46), 0),
                v_13034 = nil; }
           else record_get(elt(fastget_names, 46), 0); }
#else
             if (v_13034 == SPID_NOPROP) v_13034 = nil; }}
#endif
    stack[-1] = v_13034;
    if (v_13034 == nil) goto v_12798;
    v_13034 = stack[-1];
    fn = elt(env, 13); // physopaeval
    v_13034 = (*qfn1(fn))(fn, v_13034);
    goto v_12796;
v_12798:
    v_13034 = stack[-3];
    if (symbolp(v_13034)) goto v_12803;
    else goto v_12804;
v_12803:
    v_13034 = stack[-3];
    goto v_12796;
v_12804:
    goto v_12814;
v_12810:
    v_13034 = stack[-3];
    v_13035 = qcar(v_13034);
    goto v_12811;
v_12812:
    v_13034 = elt(env, 2); // psimpfn
    goto v_12813;
v_12814:
    goto v_12810;
v_12811:
    goto v_12812;
v_12813:
    v_13034 = get(v_13035, v_13034);
    env = stack[-5];
    stack[-1] = v_13034;
    if (v_13034 == nil) goto v_12808;
    goto v_12823;
v_12819:
    v_13035 = stack[-1];
    goto v_12820;
v_12821:
    v_13034 = stack[-3];
    goto v_12822;
v_12823:
    goto v_12819;
v_12820:
    goto v_12821;
v_12822:
    v_13034 = Lapply1(nil, v_13035, v_13034);
    goto v_12796;
v_12808:
    v_13034 = stack[-3];
    v_13034 = qcar(v_13034);
    if (!symbolp(v_13034)) v_13034 = nil;
    else { v_13034 = qfastgets(v_13034);
           if (v_13034 != nil) { v_13034 = elt(v_13034, 9); // opmtch
#ifdef RECORD_GET
             if (v_13034 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_13034 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_13034 == SPID_NOPROP) v_13034 = nil; }}
#endif
    if (v_13034 == nil) goto v_12827;
    v_13034 = stack[-3];
    fn = elt(env, 14); // opmtch!*
    v_13034 = (*qfn1(fn))(fn, v_13034);
    stack[-1] = v_13034;
    if (v_13034 == nil) goto v_12827;
    v_13034 = stack[-1];
    goto v_12796;
v_12827:
    v_13034 = stack[-3];
    goto v_12796;
    v_13034 = nil;
v_12796:
    stack[0] = v_13034;
    goto v_12777;
v_12792:
    v_13034 = stack[-3];
    if (!consp(v_13034)) goto v_12839;
    else goto v_12840;
v_12839:
    v_13034 = stack[-3];
    fn = elt(env, 15); // aeval
    v_13034 = (*qfn1(fn))(fn, v_13034);
    stack[0] = v_13034;
    goto v_12777;
v_12840:
    v_13034 = stack[-3];
    v_13034 = qcar(v_13034);
    stack[-4] = v_13034;
    v_13034 = stack[-3];
    v_13034 = qcdr(v_13034);
    stack[-2] = v_13034;
    goto v_12859;
v_12855:
    v_13035 = stack[-4];
    goto v_12856;
v_12857:
    v_13034 = elt(env, 3); // physopfunction
    goto v_12858;
v_12859:
    goto v_12855;
v_12856:
    goto v_12857;
v_12858:
    v_13034 = get(v_13035, v_13034);
    env = stack[-5];
    stack[-1] = v_13034;
    if (v_13034 == nil) goto v_12853;
    goto v_12871;
v_12867:
    v_13035 = stack[-4];
    goto v_12868;
v_12869:
    v_13034 = elt(env, 4); // physoparith
    goto v_12870;
v_12871:
    goto v_12867;
v_12868:
    goto v_12869;
v_12870:
    v_13034 = Lflagp(nil, v_13035, v_13034);
    env = stack[-5];
    if (v_13034 == nil) goto v_12865;
    v_13034 = stack[-2];
    fn = elt(env, 16); // hasonephysop
    v_13034 = (*qfn1(fn))(fn, v_13034);
    env = stack[-5];
    if (v_13034 == nil) goto v_12877;
    goto v_12885;
v_12881:
    stack[0] = stack[-1];
    goto v_12882;
v_12883:
    v_13034 = stack[-2];
    v_13034 = ncons(v_13034);
    env = stack[-5];
    goto v_12884;
v_12885:
    goto v_12881;
v_12882:
    goto v_12883;
v_12884:
    fn = elt(env, 17); // apply
    v_13034 = (*qfn2(fn))(fn, stack[0], v_13034);
    stack[0] = v_13034;
    goto v_12875;
v_12877:
    goto v_12897;
v_12893:
    v_13035 = stack[-4];
    goto v_12894;
v_12895:
    v_13034 = stack[-2];
    goto v_12896;
v_12897:
    goto v_12893;
v_12894:
    goto v_12895;
v_12896:
    v_13034 = cons(v_13035, v_13034);
    env = stack[-5];
    fn = elt(env, 18); // reval3
    v_13034 = (*qfn1(fn))(fn, v_13034);
    stack[0] = v_13034;
    goto v_12875;
v_12875:
    goto v_12863;
v_12865:
    goto v_12907;
v_12903:
    v_13035 = stack[-4];
    goto v_12904;
v_12905:
    v_13034 = elt(env, 5); // physopfn
    goto v_12906;
v_12907:
    goto v_12903;
v_12904:
    goto v_12905;
v_12906:
    v_13034 = Lflagp(nil, v_13035, v_13034);
    env = stack[-5];
    if (v_13034 == nil) goto v_12901;
    v_13034 = stack[-2];
    fn = elt(env, 19); // areallphysops
    v_13034 = (*qfn1(fn))(fn, v_13034);
    env = stack[-5];
    if (v_13034 == nil) goto v_12913;
    goto v_12921;
v_12917:
    stack[0] = stack[-1];
    goto v_12918;
v_12919:
    v_13034 = stack[-2];
    v_13034 = ncons(v_13034);
    env = stack[-5];
    goto v_12920;
v_12921:
    goto v_12917;
v_12918:
    goto v_12919;
v_12920:
    fn = elt(env, 17); // apply
    v_13034 = (*qfn2(fn))(fn, stack[0], v_13034);
    stack[0] = v_13034;
    goto v_12911;
v_12913:
    goto v_12932;
v_12928:
    stack[-1] = elt(env, 0); // physopsm!*
    goto v_12929;
v_12930:
    goto v_12943;
v_12935:
    v_13037 = elt(env, 6); // "invalid call of "
    goto v_12936;
v_12937:
    v_13036 = stack[-4];
    goto v_12938;
v_12939:
    v_13035 = elt(env, 7); // " with args: "
    goto v_12940;
v_12941:
    v_13034 = stack[-2];
    goto v_12942;
v_12943:
    goto v_12935;
v_12936:
    goto v_12937;
v_12938:
    goto v_12939;
v_12940:
    goto v_12941;
v_12942:
    v_13034 = list4(v_13037, v_13036, v_13035, v_13034);
    env = stack[-5];
    goto v_12931;
v_12932:
    goto v_12928;
v_12929:
    goto v_12930;
v_12931:
    fn = elt(env, 20); // rederr2
    v_13034 = (*qfn2(fn))(fn, stack[-1], v_13034);
    goto v_12911;
v_12911:
    goto v_12863;
v_12901:
    goto v_12955;
v_12951:
    stack[-1] = elt(env, 0); // physopsm!*
    goto v_12952;
v_12953:
    goto v_12964;
v_12958:
    v_13036 = stack[-4];
    goto v_12959;
v_12960:
    v_13035 = elt(env, 8); // " has been flagged Physopfunction"
    goto v_12961;
v_12962:
    v_13034 = elt(env, 9); // " but is not defined"
    goto v_12963;
v_12964:
    goto v_12958;
v_12959:
    goto v_12960;
v_12961:
    goto v_12962;
v_12963:
    v_13034 = list3(v_13036, v_13035, v_13034);
    env = stack[-5];
    goto v_12954;
v_12955:
    goto v_12951;
v_12952:
    goto v_12953;
v_12954:
    fn = elt(env, 20); // rederr2
    v_13034 = (*qfn2(fn))(fn, stack[-1], v_13034);
    goto v_12863;
v_12863:
    goto v_12851;
v_12853:
    goto v_12979;
v_12975:
    v_13035 = stack[-4];
    goto v_12976;
v_12977:
    v_13034 = elt(env, 10); // physopmapping
    goto v_12978;
v_12979:
    goto v_12975;
v_12976:
    goto v_12977;
v_12978:
    v_13034 = Lflagp(nil, v_13035, v_13034);
    env = stack[-5];
    if (v_13034 == nil) goto v_12973;
    v_13034 = stack[-2];
    fn = elt(env, 21); // !*physopp!*
    v_13034 = (*qfn1(fn))(fn, v_13034);
    env = stack[-5];
    goto v_12971;
v_12973:
    v_13034 = nil;
    goto v_12971;
    v_13034 = nil;
v_12971:
    if (v_13034 == nil) goto v_12969;
    goto v_12993;
v_12989:
    goto v_13000;
v_12996:
    goto v_13006;
v_13002:
    goto v_13012;
v_13008:
    v_13035 = stack[-4];
    goto v_13009;
v_13010:
    v_13034 = stack[-2];
    goto v_13011;
v_13012:
    goto v_13008;
v_13009:
    goto v_13010;
v_13011:
    v_13035 = cons(v_13035, v_13034);
    env = stack[-5];
    goto v_13003;
v_13004:
    v_13034 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13005;
v_13006:
    goto v_13002;
v_13003:
    goto v_13004;
v_13005:
    fn = elt(env, 22); // to
    v_13035 = (*qfn2(fn))(fn, v_13035, v_13034);
    env = stack[-5];
    goto v_12997;
v_12998:
    v_13034 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12999;
v_13000:
    goto v_12996;
v_12997:
    goto v_12998;
v_12999:
    v_13034 = cons(v_13035, v_13034);
    env = stack[-5];
    v_13035 = ncons(v_13034);
    env = stack[-5];
    goto v_12990;
v_12991:
    v_13034 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12992;
v_12993:
    goto v_12989;
v_12990:
    goto v_12991;
v_12992:
    v_13034 = cons(v_13035, v_13034);
    env = stack[-5];
    fn = elt(env, 23); // mk!*sq
    v_13034 = (*qfn1(fn))(fn, v_13034);
    stack[0] = v_13034;
    goto v_12851;
v_12969:
    goto v_13024;
v_13020:
    v_13035 = stack[-4];
    goto v_13021;
v_13022:
    v_13034 = elt(env, 11); // prog
    goto v_13023;
v_13024:
    goto v_13020;
v_13021:
    goto v_13022;
v_13023:
    if (v_13035 == v_13034) goto v_13018;
    else goto v_13019;
v_13018:
    v_13034 = stack[-2];
    fn = elt(env, 24); // physopprog
    v_13034 = (*qfn1(fn))(fn, v_13034);
    stack[0] = v_13034;
    goto v_12851;
v_13019:
    v_13034 = stack[-3];
    fn = elt(env, 15); // aeval
    v_13034 = (*qfn1(fn))(fn, v_13034);
    stack[0] = v_13034;
    goto v_12851;
v_12851:
    goto v_12777;
v_12777:
    v_13034 = stack[0];
    return onevalue(v_13034);
}



// Code for repartf

static LispObject CC_repartf(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12888, v_12889;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_12766;
// end of prologue
    goto v_12773;
v_12769:
    v_12889 = elt(env, 1); // i
    goto v_12770;
v_12771:
    v_12888 = qvalue(elt(env, 2)); // kord!*
    goto v_12772;
v_12773:
    goto v_12769;
v_12770:
    goto v_12771;
v_12772:
    v_12888 = cons(v_12889, v_12888);
    env = stack[-4];
// Binding kord!*
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 2, -3);
    qvalue(elt(env, 2)) = v_12888; // kord!*
    v_12888 = stack[0];
    fn = elt(env, 4); // reorder
    v_12888 = (*qfn1(fn))(fn, v_12888);
    env = stack[-4];
    stack[-2] = v_12888;
    v_12888 = stack[-2];
    if (!consp(v_12888)) goto v_12786;
    else goto v_12787;
v_12786:
    v_12888 = lisp_true;
    goto v_12785;
v_12787:
    v_12888 = stack[-2];
    v_12888 = qcar(v_12888);
    v_12888 = (consp(v_12888) ? nil : lisp_true);
    goto v_12785;
    v_12888 = nil;
v_12785:
    if (v_12888 == nil) goto v_12783;
    v_12888 = stack[-2];
    if (!consp(v_12888)) goto v_12797;
    else goto v_12798;
v_12797:
    v_12888 = stack[-2];
    goto v_12796;
v_12798:
    goto v_12808;
v_12804:
    v_12888 = stack[-2];
    v_12889 = qcar(v_12888);
    goto v_12805;
v_12806:
    v_12888 = elt(env, 3); // cmpxfn
    goto v_12807;
v_12808:
    goto v_12804;
v_12805:
    goto v_12806;
v_12807:
    v_12888 = get(v_12889, v_12888);
    env = stack[-4];
    if (v_12888 == nil) goto v_12802;
    goto v_12820;
v_12814:
    v_12888 = stack[-2];
    stack[-1] = qcar(v_12888);
    goto v_12815;
v_12816:
    v_12888 = stack[-2];
    v_12888 = qcdr(v_12888);
    stack[0] = qcar(v_12888);
    goto v_12817;
v_12818:
    goto v_12831;
v_12827:
    v_12888 = stack[-2];
    v_12888 = qcar(v_12888);
    if (!symbolp(v_12888)) v_12889 = nil;
    else { v_12889 = qfastgets(v_12888);
           if (v_12889 != nil) { v_12889 = elt(v_12889, 34); // i2d
#ifdef RECORD_GET
             if (v_12889 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_12889 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_12889 == SPID_NOPROP) v_12889 = nil; }}
#endif
    goto v_12828;
v_12829:
    v_12888 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12830;
v_12831:
    goto v_12827;
v_12828:
    goto v_12829;
v_12830:
    v_12888 = Lapply1(nil, v_12889, v_12888);
    env = stack[-4];
    v_12888 = qcdr(v_12888);
    v_12888 = qcar(v_12888);
    goto v_12819;
v_12820:
    goto v_12814;
v_12815:
    goto v_12816;
v_12817:
    goto v_12818;
v_12819:
    v_12888 = list2star(stack[-1], stack[0], v_12888);
    env = stack[-4];
    fn = elt(env, 5); // int!-equiv!-chk
    v_12888 = (*qfn1(fn))(fn, v_12888);
    goto v_12796;
v_12802:
    v_12888 = stack[-2];
    goto v_12796;
    v_12888 = nil;
v_12796:
    goto v_12781;
v_12783:
    goto v_12847;
v_12843:
    v_12888 = stack[-2];
    v_12888 = qcar(v_12888);
    v_12888 = qcar(v_12888);
    v_12889 = qcar(v_12888);
    goto v_12844;
v_12845:
    v_12888 = elt(env, 1); // i
    goto v_12846;
v_12847:
    goto v_12843;
v_12844:
    goto v_12845;
v_12846:
    if (v_12889 == v_12888) goto v_12841;
    else goto v_12842;
v_12841:
    v_12888 = stack[-2];
    v_12888 = qcdr(v_12888);
    v_12888 = CC_repartf(elt(env, 0), v_12888);
    goto v_12781;
v_12842:
    goto v_12863;
v_12859:
    goto v_12869;
v_12865:
    goto v_12876;
v_12872:
    v_12888 = stack[-2];
    v_12888 = qcar(v_12888);
    v_12889 = qcar(v_12888);
    goto v_12873;
v_12874:
    v_12888 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12875;
v_12876:
    goto v_12872;
v_12873:
    goto v_12874;
v_12875:
    v_12888 = cons(v_12889, v_12888);
    env = stack[-4];
    stack[0] = ncons(v_12888);
    env = stack[-4];
    goto v_12866;
v_12867:
    v_12888 = stack[-2];
    v_12888 = qcar(v_12888);
    v_12888 = qcdr(v_12888);
    v_12888 = CC_repartf(elt(env, 0), v_12888);
    env = stack[-4];
    goto v_12868;
v_12869:
    goto v_12865;
v_12866:
    goto v_12867;
v_12868:
    fn = elt(env, 6); // multf
    stack[0] = (*qfn2(fn))(fn, stack[0], v_12888);
    env = stack[-4];
    goto v_12860;
v_12861:
    v_12888 = stack[-2];
    v_12888 = qcdr(v_12888);
    v_12888 = CC_repartf(elt(env, 0), v_12888);
    env = stack[-4];
    goto v_12862;
v_12863:
    goto v_12859;
v_12860:
    goto v_12861;
v_12862:
    fn = elt(env, 7); // addf
    v_12888 = (*qfn2(fn))(fn, stack[0], v_12888);
    goto v_12781;
    v_12888 = nil;
v_12781:
    ;}  // end of a binding scope
    return onevalue(v_12888);
}



// Code for symbvarlst

static LispObject CC_symbvarlst(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12874, v_12875, v_12876;
    LispObject fn;
    LispObject v_12768, v_12767, v_12766;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "symbvarlst");
    va_start(aa, nargs);
    v_12766 = va_arg(aa, LispObject);
    v_12767 = va_arg(aa, LispObject);
    v_12768 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12768,v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12766,v_12767,v_12768);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_12874 = v_12768;
    stack[-3] = v_12767;
    v_12876 = v_12766;
// end of prologue
    goto v_12783;
v_12779:
    v_12875 = v_12874;
    goto v_12780;
v_12781:
    v_12874 = elt(env, 2); // symbolic
    goto v_12782;
v_12783:
    goto v_12779;
v_12780:
    goto v_12781;
v_12782:
    if (v_12875 == v_12874) goto v_12778;
    v_12874 = nil;
    goto v_12773;
v_12778:
    v_12874 = v_12876;
    stack[-4] = v_12874;
v_12790:
    v_12874 = stack[-4];
    if (v_12874 == nil) goto v_12793;
    else goto v_12794;
v_12793:
    goto v_12789;
v_12794:
    v_12874 = stack[-4];
    v_12874 = qcar(v_12874);
    v_12874 = Lconsp(nil, v_12874);
    env = stack[-5];
    if (v_12874 == nil) goto v_12800;
    v_12874 = stack[-4];
    v_12874 = qcar(v_12874);
    v_12874 = qcar(v_12874);
    goto v_12798;
v_12800:
    v_12874 = stack[-4];
    v_12874 = qcar(v_12874);
    goto v_12798;
    v_12874 = nil;
v_12798:
    stack[0] = v_12874;
    v_12874 = stack[0];
    v_12874 = Lsymbol_specialp(nil, v_12874);
    env = stack[-5];
    if (v_12874 == nil) goto v_12817;
    else goto v_12818;
v_12817:
    v_12874 = stack[0];
    v_12874 = Lsymbol_globalp(nil, v_12874);
    env = stack[-5];
    if (v_12874 == nil) goto v_12823;
    else goto v_12824;
v_12823:
    goto v_12836;
v_12832:
    v_12875 = stack[0];
    goto v_12833;
v_12834:
    v_12874 = stack[-3];
    goto v_12835;
v_12836:
    goto v_12832;
v_12833:
    goto v_12834;
v_12835:
    v_12874 = Lsmemq(nil, v_12875, v_12874);
    env = stack[-5];
    if (v_12874 == nil) goto v_12829;
    else goto v_12830;
v_12829:
    v_12874 = qvalue(elt(env, 3)); // !*novarmsg
    v_12874 = (v_12874 == nil ? lisp_true : nil);
    goto v_12828;
v_12830:
    v_12874 = nil;
    goto v_12828;
    v_12874 = nil;
v_12828:
    goto v_12822;
v_12824:
    v_12874 = nil;
    goto v_12822;
    v_12874 = nil;
v_12822:
    goto v_12816;
v_12818:
    v_12874 = nil;
    goto v_12816;
    v_12874 = nil;
v_12816:
    if (v_12874 == nil) goto v_12814;
    goto v_12860;
v_12852:
    stack[-2] = elt(env, 4); // "local variable"
    goto v_12853;
v_12854:
    stack[-1] = stack[0];
    goto v_12855;
v_12856:
    stack[0] = elt(env, 5); // "in procedure"
    goto v_12857;
v_12858:
    goto v_12869;
v_12865:
    v_12875 = qvalue(elt(env, 6)); // fname!*
    goto v_12866;
v_12867:
    v_12874 = elt(env, 7); // "not used"
    goto v_12868;
v_12869:
    goto v_12865;
v_12866:
    goto v_12867;
v_12868:
    v_12874 = list2(v_12875, v_12874);
    env = stack[-5];
    goto v_12859;
v_12860:
    goto v_12852;
v_12853:
    goto v_12854;
v_12855:
    goto v_12856;
v_12857:
    goto v_12858;
v_12859:
    v_12874 = list3star(stack[-2], stack[-1], stack[0], v_12874);
    env = stack[-5];
    fn = elt(env, 8); // lprim
    v_12874 = (*qfn1(fn))(fn, v_12874);
    env = stack[-5];
    goto v_12812;
v_12814:
v_12812:
    v_12874 = stack[-4];
    v_12874 = qcdr(v_12874);
    stack[-4] = v_12874;
    goto v_12790;
v_12789:
    v_12874 = nil;
v_12773:
    return onevalue(v_12874);
}



// Code for fs!:times

static LispObject CC_fsTtimes(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12815, v_12816;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12767;
    stack[-1] = v_12766;
// end of prologue
    v_12815 = stack[-1];
    if (v_12815 == nil) goto v_12771;
    else goto v_12772;
v_12771:
    v_12815 = nil;
    goto v_12770;
v_12772:
    v_12815 = stack[0];
    if (v_12815 == nil) goto v_12775;
    else goto v_12776;
v_12775:
    v_12815 = nil;
    goto v_12770;
v_12776:
    goto v_12790;
v_12786:
    v_12816 = stack[-1];
    goto v_12787;
v_12788:
    v_12815 = stack[0];
    goto v_12789;
v_12790:
    goto v_12786;
v_12787:
    goto v_12788;
v_12789:
    fn = elt(env, 2); // fs!:timesterm
    v_12815 = (*qfn2(fn))(fn, v_12816, v_12815);
    env = stack[-3];
    goto v_12798;
v_12794:
    stack[-2] = v_12815;
    goto v_12795;
v_12796:
    goto v_12805;
v_12801:
    goto v_12810;
v_12806:
    v_12816 = stack[-1];
    goto v_12807;
v_12808:
    v_12815 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_12809;
v_12810:
    goto v_12806;
v_12807:
    goto v_12808;
v_12809:
    v_12816 = *(LispObject *)((char *)v_12816 + (CELL-TAG_VECTOR) + (((intptr_t)v_12815-TAG_FIXNUM)/(16/CELL)));
    goto v_12802;
v_12803:
    v_12815 = stack[0];
    goto v_12804;
v_12805:
    goto v_12801;
v_12802:
    goto v_12803;
v_12804:
    v_12815 = CC_fsTtimes(elt(env, 0), v_12816, v_12815);
    env = stack[-3];
    goto v_12797;
v_12798:
    goto v_12794;
v_12795:
    goto v_12796;
v_12797:
    {
        LispObject v_12820 = stack[-2];
        fn = elt(env, 3); // fs!:plus
        return (*qfn2(fn))(fn, v_12820, v_12815);
    }
    goto v_12770;
    v_12815 = nil;
v_12770:
    return onevalue(v_12815);
}



// Code for red!=cancelsimp

static LispObject CC_redMcancelsimp(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12796, v_12797;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12767;
    stack[-1] = v_12766;
// end of prologue
    goto v_12778;
v_12774:
    v_12797 = stack[-1];
    goto v_12775;
v_12776:
    v_12796 = stack[0];
    goto v_12777;
v_12778:
    goto v_12774;
v_12775:
    goto v_12776;
v_12777:
    fn = elt(env, 1); // red_better
    v_12796 = (*qfn2(fn))(fn, v_12797, v_12796);
    env = stack[-2];
    if (v_12796 == nil) goto v_12771;
    else goto v_12772;
v_12771:
    v_12796 = nil;
    goto v_12770;
v_12772:
    goto v_12789;
v_12785:
    v_12796 = stack[-1];
    fn = elt(env, 2); // bas_dpoly
    v_12796 = (*qfn1(fn))(fn, v_12796);
    env = stack[-2];
    fn = elt(env, 3); // dp_lmon
    stack[-1] = (*qfn1(fn))(fn, v_12796);
    env = stack[-2];
    goto v_12786;
v_12787:
    v_12796 = stack[0];
    fn = elt(env, 2); // bas_dpoly
    v_12796 = (*qfn1(fn))(fn, v_12796);
    env = stack[-2];
    fn = elt(env, 3); // dp_lmon
    v_12796 = (*qfn1(fn))(fn, v_12796);
    env = stack[-2];
    goto v_12788;
v_12789:
    goto v_12785;
v_12786:
    goto v_12787;
v_12788:
    {
        LispObject v_12800 = stack[-1];
        fn = elt(env, 4); // mo_vdivides!?
        return (*qfn2(fn))(fn, v_12800, v_12796);
    }
    v_12796 = nil;
v_12770:
    return onevalue(v_12796);
}



// Code for ad_numsort

static LispObject CC_ad_numsort(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12776, v_12777;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12776 = v_12766;
// end of prologue
    goto v_12773;
v_12769:
    v_12777 = v_12776;
    goto v_12770;
v_12771:
    v_12776 = elt(env, 1); // lambda_ygm6np4pcqv31
    goto v_12772;
v_12773:
    goto v_12769;
v_12770:
    goto v_12771;
v_12772:
    {
        fn = elt(env, 2); // sort
        return (*qfn2(fn))(fn, v_12777, v_12776);
    }
}



// Code for lambda_ygm6np4pcqv31

static LispObject CC_lambda_ygm6np4pcqv31(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12777, v_12778;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12777 = v_12767;
    v_12778 = v_12766;
// end of prologue
    goto v_12774;
v_12770:
    goto v_12771;
v_12772:
    goto v_12773;
v_12774:
    goto v_12770;
v_12771:
    goto v_12772;
v_12773:
        return Lleq(nil, v_12778, v_12777);
}



// Code for gfk

static LispObject CC_gfk(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12844, v_12845, v_12846, v_12847, v_12848, v_12849;
    LispObject v_12768, v_12767, v_12766;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "gfk");
    va_start(aa, nargs);
    v_12766 = va_arg(aa, LispObject);
    v_12767 = va_arg(aa, LispObject);
    v_12768 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12768,v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12766,v_12767,v_12768);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_12847 = v_12768;
    v_12848 = v_12767;
    v_12844 = v_12766;
// end of prologue
v_12765:
    v_12845 = v_12847;
    if (v_12845 == nil) goto v_12774;
    else goto v_12772;
v_12774:
    v_12845 = v_12844;
    if (!consp(v_12845)) goto v_12779;
    else goto v_12780;
v_12779:
    v_12845 = lisp_true;
    goto v_12778;
v_12780:
    v_12845 = v_12844;
    v_12845 = qcar(v_12845);
    v_12845 = (consp(v_12845) ? nil : lisp_true);
    goto v_12778;
    v_12845 = nil;
v_12778:
    if (v_12845 == nil) goto v_12776;
    else goto v_12772;
v_12776:
    goto v_12773;
v_12772:
    v_12844 = v_12847;
    goto v_12771;
v_12773:
    v_12845 = v_12844;
    v_12845 = qcar(v_12845);
    v_12845 = qcar(v_12845);
    v_12845 = qcar(v_12845);
    v_12849 = v_12845;
    goto v_12803;
v_12797:
    v_12845 = v_12844;
    stack[-1] = qcdr(v_12845);
    goto v_12798;
v_12799:
    stack[0] = v_12848;
    goto v_12800;
v_12801:
    goto v_12814;
v_12808:
    v_12844 = qcar(v_12844);
    v_12846 = qcdr(v_12844);
    goto v_12809;
v_12810:
    v_12845 = v_12848;
    goto v_12811;
v_12812:
    v_12844 = v_12849;
    if (!consp(v_12844)) goto v_12826;
    goto v_12832;
v_12828:
    v_12844 = v_12849;
    v_12844 = qcar(v_12844);
    goto v_12829;
v_12830:
    goto v_12831;
v_12832:
    goto v_12828;
v_12829:
    goto v_12830;
v_12831:
    v_12844 = Lmember(nil, v_12844, v_12848);
    goto v_12824;
v_12826:
    v_12844 = nil;
    goto v_12824;
    v_12844 = nil;
v_12824:
    if (v_12844 == nil) goto v_12822;
    v_12844 = v_12849;
    goto v_12820;
v_12822:
    v_12844 = v_12847;
    goto v_12820;
    v_12844 = nil;
v_12820:
    goto v_12813;
v_12814:
    goto v_12808;
v_12809:
    goto v_12810;
v_12811:
    goto v_12812;
v_12813:
    v_12845 = CC_gfk(elt(env, 0), 3, v_12846, v_12845, v_12844);
    env = stack[-2];
    goto v_12802;
v_12803:
    goto v_12797;
v_12798:
    goto v_12799;
v_12800:
    goto v_12801;
v_12802:
    v_12844 = stack[-1];
    v_12848 = stack[0];
    v_12847 = v_12845;
    goto v_12765;
    v_12844 = nil;
v_12771:
    return onevalue(v_12844);
}



// Code for yypeek

static LispObject CC_yypeek(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12778;
    LispObject fn;
    argcheck(nargs, 0, "yypeek");
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
// Binding lex_char
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = nil; // lex_char
    v_12778 = qvalue(elt(env, 3)); // lex_peek_char
    if (v_12778 == nil) goto v_12773;
    else goto v_12774;
v_12773:
    fn = elt(env, 4); // yyreadch
    v_12778 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    qvalue(elt(env, 3)) = v_12778; // lex_peek_char
    goto v_12772;
v_12774:
v_12772:
    v_12778 = qvalue(elt(env, 3)); // lex_peek_char
    ;}  // end of a binding scope
    return onevalue(v_12778);
}



// Code for collect_cdrs

static LispObject CC_collect_cdrs(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12793, v_12794;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_12766;
// end of prologue
    v_12794 = nil;
v_12771:
    v_12793 = stack[0];
    if (v_12793 == nil) goto v_12774;
    else goto v_12775;
v_12774:
    v_12793 = v_12794;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12793);
    }
v_12775:
    goto v_12786;
v_12782:
    v_12793 = stack[0];
    v_12793 = qcar(v_12793);
    v_12793 = qcdr(v_12793);
    goto v_12783;
v_12784:
    goto v_12785;
v_12786:
    goto v_12782;
v_12783:
    goto v_12784;
v_12785:
    v_12793 = cons(v_12793, v_12794);
    env = stack[-1];
    v_12794 = v_12793;
    v_12793 = stack[0];
    v_12793 = qcdr(v_12793);
    stack[0] = v_12793;
    goto v_12771;
    v_12793 = nil;
    return onevalue(v_12793);
}



// Code for setqget

static LispObject CC_setqget(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12795, v_12796;
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
    v_12795 = qvalue(elt(env, 2)); // fluidbibasissetq
    v_12795 = qcar(v_12795);
    stack[-1] = v_12795;
    v_12795 = qvalue(elt(env, 2)); // fluidbibasissetq
    stack[0] = v_12795;
    goto v_12780;
v_12776:
    goto v_12786;
v_12782:
    v_12796 = stack[0];
    goto v_12783;
v_12784:
    v_12795 = stack[0];
    v_12795 = qcdr(v_12795);
    v_12795 = qcar(v_12795);
    goto v_12785;
v_12786:
    goto v_12782;
v_12783:
    goto v_12784;
v_12785:
    v_12796 = Lrplaca(nil, v_12796, v_12795);
    env = stack[-2];
    goto v_12777;
v_12778:
    v_12795 = stack[0];
    v_12795 = qcdr(v_12795);
    v_12795 = qcdr(v_12795);
    goto v_12779;
v_12780:
    goto v_12776;
v_12777:
    goto v_12778;
v_12779:
    v_12795 = Lrplacd(nil, v_12796, v_12795);
    v_12795 = stack[-1];
    return onevalue(v_12795);
}



// Code for ofsf_subf

static LispObject CC_ofsf_subf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12897, v_12898, v_12899;
    LispObject fn;
    LispObject v_12768, v_12767, v_12766;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_subf");
    va_start(aa, nargs);
    v_12766 = va_arg(aa, LispObject);
    v_12767 = va_arg(aa, LispObject);
    v_12768 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12768,v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12766,v_12767,v_12768);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_12768;
    stack[-1] = v_12767;
    stack[-2] = v_12766;
// end of prologue
    v_12897 = stack[-2];
    if (!consp(v_12897)) goto v_12780;
    else goto v_12781;
v_12780:
    v_12897 = lisp_true;
    goto v_12779;
v_12781:
    v_12897 = stack[-2];
    v_12897 = qcar(v_12897);
    v_12897 = (consp(v_12897) ? nil : lisp_true);
    goto v_12779;
    v_12897 = nil;
v_12779:
    if (v_12897 == nil) goto v_12777;
    goto v_12794;
v_12790:
    v_12898 = stack[-2];
    goto v_12791;
v_12792:
    v_12897 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12793;
v_12794:
    goto v_12790;
v_12791:
    goto v_12792;
v_12793:
    return cons(v_12898, v_12897);
v_12777:
    goto v_12804;
v_12798:
    v_12897 = stack[-2];
    v_12899 = qcdr(v_12897);
    goto v_12799;
v_12800:
    v_12898 = stack[-1];
    goto v_12801;
v_12802:
    v_12897 = stack[0];
    goto v_12803;
v_12804:
    goto v_12798;
v_12799:
    goto v_12800;
v_12801:
    goto v_12802;
v_12803:
    v_12897 = CC_ofsf_subf(elt(env, 0), 3, v_12899, v_12898, v_12897);
    env = stack[-4];
    stack[-3] = v_12897;
    goto v_12817;
v_12813:
    v_12897 = stack[-2];
    v_12897 = qcar(v_12897);
    v_12897 = qcar(v_12897);
    v_12898 = qcar(v_12897);
    goto v_12814;
v_12815:
    v_12897 = stack[-1];
    goto v_12816;
v_12817:
    goto v_12813;
v_12814:
    goto v_12815;
v_12816:
    if (v_12898 == v_12897) goto v_12811;
    else goto v_12812;
v_12811:
    goto v_12828;
v_12824:
    goto v_12834;
v_12830:
    goto v_12840;
v_12836:
    v_12897 = stack[-2];
    v_12897 = qcar(v_12897);
    v_12898 = qcdr(v_12897);
    goto v_12837;
v_12838:
    v_12897 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12839;
v_12840:
    goto v_12836;
v_12837:
    goto v_12838;
v_12839:
    stack[-1] = cons(v_12898, v_12897);
    env = stack[-4];
    goto v_12831;
v_12832:
    goto v_12850;
v_12846:
    v_12898 = stack[0];
    goto v_12847;
v_12848:
    v_12897 = stack[-2];
    v_12897 = qcar(v_12897);
    v_12897 = qcar(v_12897);
    v_12897 = qcdr(v_12897);
    goto v_12849;
v_12850:
    goto v_12846;
v_12847:
    goto v_12848;
v_12849:
    fn = elt(env, 2); // exptsq
    v_12897 = (*qfn2(fn))(fn, v_12898, v_12897);
    env = stack[-4];
    goto v_12833;
v_12834:
    goto v_12830;
v_12831:
    goto v_12832;
v_12833:
    fn = elt(env, 3); // multsq
    v_12898 = (*qfn2(fn))(fn, stack[-1], v_12897);
    env = stack[-4];
    goto v_12825;
v_12826:
    v_12897 = stack[-3];
    goto v_12827;
v_12828:
    goto v_12824;
v_12825:
    goto v_12826;
v_12827:
    {
        fn = elt(env, 4); // addsq
        return (*qfn2(fn))(fn, v_12898, v_12897);
    }
v_12812:
    goto v_12862;
v_12858:
    goto v_12868;
v_12864:
    goto v_12876;
v_12870:
    v_12897 = stack[-2];
    v_12897 = qcar(v_12897);
    v_12899 = qcdr(v_12897);
    goto v_12871;
v_12872:
    v_12898 = stack[-1];
    goto v_12873;
v_12874:
    v_12897 = stack[0];
    goto v_12875;
v_12876:
    goto v_12870;
v_12871:
    goto v_12872;
v_12873:
    goto v_12874;
v_12875:
    stack[0] = CC_ofsf_subf(elt(env, 0), 3, v_12899, v_12898, v_12897);
    env = stack[-4];
    goto v_12865;
v_12866:
    goto v_12887;
v_12883:
    v_12897 = stack[-2];
    v_12897 = qcar(v_12897);
    v_12897 = qcar(v_12897);
    v_12898 = qcar(v_12897);
    goto v_12884;
v_12885:
    v_12897 = stack[-2];
    v_12897 = qcar(v_12897);
    v_12897 = qcar(v_12897);
    v_12897 = qcdr(v_12897);
    goto v_12886;
v_12887:
    goto v_12883;
v_12884:
    goto v_12885;
v_12886:
    fn = elt(env, 5); // ofsf_pow2q
    v_12897 = (*qfn2(fn))(fn, v_12898, v_12897);
    env = stack[-4];
    goto v_12867;
v_12868:
    goto v_12864;
v_12865:
    goto v_12866;
v_12867:
    fn = elt(env, 3); // multsq
    v_12898 = (*qfn2(fn))(fn, stack[0], v_12897);
    env = stack[-4];
    goto v_12859;
v_12860:
    v_12897 = stack[-3];
    goto v_12861;
v_12862:
    goto v_12858;
v_12859:
    goto v_12860;
v_12861:
    {
        fn = elt(env, 4); // addsq
        return (*qfn2(fn))(fn, v_12898, v_12897);
    }
    return onevalue(v_12897);
}



// Code for reln

static LispObject CC_reln(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12796, v_12797;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12767;
    stack[-1] = v_12766;
// end of prologue
    v_12796 = elt(env, 1); // "<apply>"
    fn = elt(env, 5); // printout
    v_12796 = (*qfn1(fn))(fn, v_12796);
    env = stack[-2];
    v_12796 = elt(env, 2); // "<"
    v_12796 = Lprinc(nil, v_12796);
    env = stack[-2];
    v_12796 = stack[0];
    v_12796 = Lprinc(nil, v_12796);
    env = stack[-2];
    goto v_12783;
v_12779:
    v_12796 = stack[-1];
    v_12797 = qcar(v_12796);
    goto v_12780;
v_12781:
    v_12796 = elt(env, 3); // "/"
    goto v_12782;
v_12783:
    goto v_12779;
v_12780:
    goto v_12781;
v_12782:
    fn = elt(env, 6); // attributesml
    v_12796 = (*qfn2(fn))(fn, v_12797, v_12796);
    env = stack[-2];
    v_12796 = lisp_true;
    fn = elt(env, 7); // indent!*
    v_12796 = (*qfn1(fn))(fn, v_12796);
    env = stack[-2];
    v_12796 = stack[-1];
    v_12796 = qcdr(v_12796);
    fn = elt(env, 8); // multi_elem
    v_12796 = (*qfn1(fn))(fn, v_12796);
    env = stack[-2];
    v_12796 = nil;
    fn = elt(env, 7); // indent!*
    v_12796 = (*qfn1(fn))(fn, v_12796);
    env = stack[-2];
    v_12796 = elt(env, 4); // "</apply>"
    fn = elt(env, 5); // printout
    v_12796 = (*qfn1(fn))(fn, v_12796);
    v_12796 = nil;
    return onevalue(v_12796);
}



// Code for fortexp

static LispObject CC_fortexp(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12776, v_12777;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12776 = v_12766;
// end of prologue
    goto v_12773;
v_12769:
    v_12777 = v_12776;
    goto v_12770;
v_12771:
    v_12776 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12772;
v_12773:
    goto v_12769;
v_12770:
    goto v_12771;
v_12772:
    {
        fn = elt(env, 1); // fortexp1
        return (*qfn2(fn))(fn, v_12777, v_12776);
    }
}



// Code for trwrite

static LispObject CC_trwrite(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12808;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_12766;
// end of prologue
    v_12808 = stack[0];
    v_12808 = qcar(v_12808);
    if (!symbolp(v_12808)) v_12808 = nil;
    else { v_12808 = qfastgets(v_12808);
           if (v_12808 != nil) { v_12808 = elt(v_12808, 53); // tracing
#ifdef RECORD_GET
             if (v_12808 == SPID_NOPROP)
                record_get(elt(fastget_names, 53), 0),
                v_12808 = nil;
             else record_get(elt(fastget_names, 53), 1),
                v_12808 = lisp_true; }
           else record_get(elt(fastget_names, 53), 0); }
#else
             if (v_12808 == SPID_NOPROP) v_12808 = nil; else v_12808 = lisp_true; }}
#endif
    if (v_12808 == nil) goto v_12774;
    else goto v_12775;
v_12774:
    v_12808 = nil;
    goto v_12770;
v_12775:
    v_12808 = elt(env, 2); // "**in procedure: "
    v_12808 = Lprinc(nil, v_12808);
    env = stack[-1];
    v_12808 = stack[0];
    v_12808 = qcar(v_12808);
    v_12808 = Lprinc(nil, v_12808);
    env = stack[-1];
    v_12808 = Lterpri(nil, 0);
    env = stack[-1];
    v_12808 = stack[0];
    v_12808 = qcdr(v_12808);
    stack[0] = v_12808;
v_12790:
    v_12808 = stack[0];
    if (v_12808 == nil) goto v_12795;
    else goto v_12796;
v_12795:
    goto v_12789;
v_12796:
    v_12808 = stack[0];
    v_12808 = qcar(v_12808);
    v_12808 = Lprinc(nil, v_12808);
    env = stack[-1];
    v_12808 = stack[0];
    v_12808 = qcdr(v_12808);
    stack[0] = v_12808;
    goto v_12790;
v_12789:
    v_12808 = Lterpri(nil, 0);
    v_12808 = nil;
v_12770:
    return onevalue(v_12808);
}



// Code for assert_uninstall1

static LispObject CC_assert_uninstall1(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12817, v_12818, v_12819;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_12766;
// end of prologue
    goto v_12777;
v_12773:
    v_12818 = stack[0];
    goto v_12774;
v_12775:
    v_12817 = elt(env, 1); // assert_installed
    goto v_12776;
v_12777:
    goto v_12773;
v_12774:
    goto v_12775;
v_12776:
    v_12817 = get(v_12818, v_12817);
    env = stack[-1];
    if (v_12817 == nil) goto v_12770;
    else goto v_12771;
v_12770:
    goto v_12786;
v_12782:
    v_12818 = elt(env, 2); // "assert not installed for"
    goto v_12783;
v_12784:
    v_12817 = stack[0];
    goto v_12785;
v_12786:
    goto v_12782;
v_12783:
    goto v_12784;
v_12785:
    v_12817 = list2(v_12818, v_12817);
    env = stack[-1];
    {
        fn = elt(env, 4); // lprim
        return (*qfn1(fn))(fn, v_12817);
    }
v_12771:
    goto v_12796;
v_12792:
    v_12819 = stack[0];
    goto v_12793;
v_12794:
    goto v_12803;
v_12799:
    v_12818 = stack[0];
    goto v_12800;
v_12801:
    v_12817 = elt(env, 3); // assert_noassertfn
    goto v_12802;
v_12803:
    goto v_12799;
v_12800:
    goto v_12801;
v_12802:
    v_12817 = get(v_12818, v_12817);
    env = stack[-1];
    goto v_12795;
v_12796:
    goto v_12792;
v_12793:
    goto v_12794;
v_12795:
    fn = elt(env, 5); // copyd
    v_12817 = (*qfn2(fn))(fn, v_12819, v_12817);
    env = stack[-1];
    goto v_12813;
v_12807:
    v_12818 = stack[0];
    goto v_12808;
v_12809:
    v_12819 = elt(env, 1); // assert_installed
    goto v_12810;
v_12811:
    v_12817 = nil;
    goto v_12812;
v_12813:
    goto v_12807;
v_12808:
    goto v_12809;
v_12810:
    goto v_12811;
v_12812:
        return Lputprop(nil, 3, v_12818, v_12819, v_12817);
    v_12817 = nil;
    return onevalue(v_12817);
}



// Code for setelv

static LispObject CC_setelv(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12827, v_12828;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_12767;
    v_12828 = v_12766;
// end of prologue
    goto v_12774;
v_12770:
    goto v_12780;
v_12776:
    v_12827 = v_12828;
    stack[-5] = qcar(v_12827);
    goto v_12777;
v_12778:
    v_12827 = v_12828;
    v_12827 = qcdr(v_12827);
    stack[-3] = v_12827;
    v_12827 = stack[-3];
    if (v_12827 == nil) goto v_12793;
    else goto v_12794;
v_12793:
    v_12827 = nil;
    goto v_12787;
v_12794:
    v_12827 = stack[-3];
    v_12827 = qcar(v_12827);
    fn = elt(env, 1); // reval_without_mod
    v_12827 = (*qfn1(fn))(fn, v_12827);
    env = stack[-6];
    v_12827 = ncons(v_12827);
    env = stack[-6];
    stack[-1] = v_12827;
    stack[-2] = v_12827;
v_12788:
    v_12827 = stack[-3];
    v_12827 = qcdr(v_12827);
    stack[-3] = v_12827;
    v_12827 = stack[-3];
    if (v_12827 == nil) goto v_12807;
    else goto v_12808;
v_12807:
    v_12827 = stack[-2];
    goto v_12787;
v_12808:
    goto v_12816;
v_12812:
    stack[0] = stack[-1];
    goto v_12813;
v_12814:
    v_12827 = stack[-3];
    v_12827 = qcar(v_12827);
    fn = elt(env, 1); // reval_without_mod
    v_12827 = (*qfn1(fn))(fn, v_12827);
    env = stack[-6];
    v_12827 = ncons(v_12827);
    env = stack[-6];
    goto v_12815;
v_12816:
    goto v_12812;
v_12813:
    goto v_12814;
v_12815:
    v_12827 = Lrplacd(nil, stack[0], v_12827);
    env = stack[-6];
    v_12827 = stack[-1];
    v_12827 = qcdr(v_12827);
    stack[-1] = v_12827;
    goto v_12788;
v_12787:
    goto v_12779;
v_12780:
    goto v_12776;
v_12777:
    goto v_12778;
v_12779:
    v_12828 = cons(stack[-5], v_12827);
    env = stack[-6];
    goto v_12771;
v_12772:
    v_12827 = stack[-4];
    goto v_12773;
v_12774:
    goto v_12770;
v_12771:
    goto v_12772;
v_12773:
    {
        fn = elt(env, 2); // setel
        return (*qfn2(fn))(fn, v_12828, v_12827);
    }
}



// Code for ratn

static LispObject CC_ratn(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12817, v_12818, v_12819;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12819 = v_12766;
// end of prologue
    v_12817 = v_12819;
    if (v_12817 == nil) goto v_12770;
    else goto v_12771;
v_12770:
    goto v_12778;
v_12774:
    v_12818 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12775;
v_12776:
    v_12817 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12777;
v_12778:
    goto v_12774;
v_12775:
    goto v_12776;
v_12777:
    return cons(v_12818, v_12817);
v_12771:
    v_12817 = v_12819;
    if (!consp(v_12817)) goto v_12781;
    else goto v_12782;
v_12781:
    goto v_12789;
v_12785:
    v_12818 = v_12819;
    goto v_12786;
v_12787:
    v_12817 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12788;
v_12789:
    goto v_12785;
v_12786:
    goto v_12787;
v_12788:
    return cons(v_12818, v_12817);
v_12782:
    goto v_12798;
v_12794:
    v_12817 = v_12819;
    v_12818 = qcar(v_12817);
    goto v_12795;
v_12796:
    v_12817 = elt(env, 1); // !:rn!:
    goto v_12797;
v_12798:
    goto v_12794;
v_12795:
    goto v_12796;
v_12797:
    if (v_12818 == v_12817) goto v_12792;
    else goto v_12793;
v_12792:
    v_12817 = v_12819;
    v_12817 = qcdr(v_12817);
    goto v_12769;
v_12793:
    goto v_12813;
v_12807:
    v_12819 = elt(env, 2); // arnum
    goto v_12808;
v_12809:
    v_12818 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_12810;
v_12811:
    v_12817 = elt(env, 3); // "Illegal domain in :ar:"
    goto v_12812;
v_12813:
    goto v_12807;
v_12808:
    goto v_12809;
v_12810:
    goto v_12811;
v_12812:
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_12819, v_12818, v_12817);
    }
    v_12817 = nil;
v_12769:
    return onevalue(v_12817);
}



// Code for resimpf

static LispObject CC_resimpf(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12779, v_12780;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_12780 = v_12766;
// end of prologue
    v_12779 = nil;
// Binding varstack!*
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_12779; // varstack!*
    goto v_12775;
v_12771:
    goto v_12772;
v_12773:
    v_12779 = nil;
    goto v_12774;
v_12775:
    goto v_12771;
v_12772:
    goto v_12773;
v_12774:
    fn = elt(env, 2); // subf1
    v_12779 = (*qfn2(fn))(fn, v_12780, v_12779);
    v_12779 = qcar(v_12779);
    ;}  // end of a binding scope
    return onevalue(v_12779);
}



// Code for get!*elements

static LispObject CC_getHelements(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12780, v_12781;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12780 = v_12766;
// end of prologue
    goto v_12777;
v_12773:
    goto v_12774;
v_12775:
    v_12781 = elt(env, 2); // elems
    goto v_12776;
v_12777:
    goto v_12773;
v_12774:
    goto v_12775;
v_12776:
    return get(v_12780, v_12781);
    return onevalue(v_12780);
}



// Code for talp_subt

static LispObject CC_talp_subt(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12859, v_12860, v_12861;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_12860 = v_12767;
    stack[-4] = v_12766;
// end of prologue
    v_12859 = v_12860;
    if (symbolp(v_12859)) goto v_12777;
    else goto v_12776;
v_12777:
    goto v_12784;
v_12780:
    v_12861 = v_12860;
    goto v_12781;
v_12782:
    v_12859 = stack[-4];
    goto v_12783;
v_12784:
    goto v_12780;
v_12781:
    goto v_12782;
v_12783:
    v_12859 = Latsoc(nil, v_12861, v_12859);
    v_12861 = v_12859;
    if (v_12859 == nil) goto v_12776;
    v_12859 = v_12861;
    v_12859 = qcdr(v_12859);
    goto v_12771;
v_12776:
    v_12859 = v_12860;
    if (!consp(v_12859)) goto v_12792;
    else goto v_12793;
v_12792:
    v_12859 = v_12860;
    goto v_12771;
v_12793:
    goto v_12801;
v_12797:
    v_12859 = v_12860;
    stack[-5] = qcar(v_12859);
    goto v_12798;
v_12799:
    v_12859 = v_12860;
    v_12859 = qcdr(v_12859);
    stack[-3] = v_12859;
    v_12859 = stack[-3];
    if (v_12859 == nil) goto v_12814;
    else goto v_12815;
v_12814:
    v_12859 = nil;
    goto v_12808;
v_12815:
    v_12859 = stack[-3];
    v_12859 = qcar(v_12859);
    goto v_12827;
v_12823:
    v_12860 = stack[-4];
    goto v_12824;
v_12825:
    goto v_12826;
v_12827:
    goto v_12823;
v_12824:
    goto v_12825;
v_12826:
    v_12859 = CC_talp_subt(elt(env, 0), v_12860, v_12859);
    env = stack[-6];
    v_12859 = ncons(v_12859);
    env = stack[-6];
    stack[-1] = v_12859;
    stack[-2] = v_12859;
v_12809:
    v_12859 = stack[-3];
    v_12859 = qcdr(v_12859);
    stack[-3] = v_12859;
    v_12859 = stack[-3];
    if (v_12859 == nil) goto v_12834;
    else goto v_12835;
v_12834:
    v_12859 = stack[-2];
    goto v_12808;
v_12835:
    goto v_12843;
v_12839:
    stack[0] = stack[-1];
    goto v_12840;
v_12841:
    v_12859 = stack[-3];
    v_12859 = qcar(v_12859);
    goto v_12854;
v_12850:
    v_12860 = stack[-4];
    goto v_12851;
v_12852:
    goto v_12853;
v_12854:
    goto v_12850;
v_12851:
    goto v_12852;
v_12853:
    v_12859 = CC_talp_subt(elt(env, 0), v_12860, v_12859);
    env = stack[-6];
    v_12859 = ncons(v_12859);
    env = stack[-6];
    goto v_12842;
v_12843:
    goto v_12839;
v_12840:
    goto v_12841;
v_12842:
    v_12859 = Lrplacd(nil, stack[0], v_12859);
    env = stack[-6];
    v_12859 = stack[-1];
    v_12859 = qcdr(v_12859);
    stack[-1] = v_12859;
    goto v_12809;
v_12808:
    goto v_12800;
v_12801:
    goto v_12797;
v_12798:
    goto v_12799;
v_12800:
    {
        LispObject v_12868 = stack[-5];
        return cons(v_12868, v_12859);
    }
v_12771:
    return onevalue(v_12859);
}



// Code for vsl_boundtype

static LispObject CC_vsl_boundtype(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12779, v_12780;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12779 = v_12767;
    v_12780 = v_12766;
// end of prologue
    goto v_12774;
v_12770:
    v_12780 = qcdr(v_12780);
    v_12780 = qcar(v_12780);
    goto v_12771;
v_12772:
    goto v_12773;
v_12774:
    goto v_12770;
v_12771:
    goto v_12772;
v_12773:
    {
        fn = elt(env, 1); // vsl_boundtype1
        return (*qfn2(fn))(fn, v_12780, v_12779);
    }
}



// Code for !*!*a2s

static LispObject CC_HHa2s(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12852, v_12853;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_12852 = v_12767;
    stack[-3] = v_12766;
// end of prologue
    v_12852 = stack[-3];
    if (v_12852 == nil) goto v_12771;
    else goto v_12772;
v_12771:
    v_12852 = elt(env, 1); // "tell Hearn!!"
    {
        fn = elt(env, 10); // rederr
        return (*qfn1(fn))(fn, v_12852);
    }
v_12772:
    goto v_12784;
v_12780:
    v_12853 = stack[-3];
    goto v_12781;
v_12782:
    v_12852 = elt(env, 2); // nochange
    goto v_12783;
v_12784:
    goto v_12780;
v_12781:
    goto v_12782;
v_12783:
    v_12852 = Lflagpcar(nil, v_12853, v_12852);
    env = stack[-5];
    if (v_12852 == nil) goto v_12777;
    goto v_12792;
v_12788:
    v_12852 = stack[-3];
    v_12853 = qcar(v_12852);
    goto v_12789;
v_12790:
    v_12852 = elt(env, 3); // getel
    goto v_12791;
v_12792:
    goto v_12788;
v_12789:
    goto v_12790;
v_12791:
    if (v_12853 == v_12852) goto v_12777;
    v_12852 = stack[-3];
    goto v_12770;
v_12777:
    goto v_12804;
v_12800:
    v_12853 = elt(env, 4); // random
    goto v_12801;
v_12802:
    v_12852 = stack[-3];
    goto v_12803;
v_12804:
    goto v_12800;
v_12801:
    goto v_12802;
v_12803:
    fn = elt(env, 11); // smember
    v_12852 = (*qfn2(fn))(fn, v_12853, v_12852);
    env = stack[-5];
    if (v_12852 == nil) goto v_12798;
    goto v_12812;
v_12808:
    goto v_12820;
v_12814:
    stack[-4] = elt(env, 5); // lambda
    goto v_12815;
v_12816:
    stack[-2] = elt(env, 6); // (!*uncached)
    goto v_12817;
v_12818:
    goto v_12830;
v_12824:
    stack[-1] = elt(env, 7); // progn
    goto v_12825;
v_12826:
    stack[0] = elt(env, 8); // (declare (special !*uncached))
    goto v_12827;
v_12828:
    goto v_12838;
v_12834:
    v_12853 = qvalue(elt(env, 9)); // !*!*a2sfn
    goto v_12835;
v_12836:
    v_12852 = stack[-3];
    goto v_12837;
v_12838:
    goto v_12834;
v_12835:
    goto v_12836;
v_12837:
    v_12852 = list2(v_12853, v_12852);
    env = stack[-5];
    goto v_12829;
v_12830:
    goto v_12824;
v_12825:
    goto v_12826;
v_12827:
    goto v_12828;
v_12829:
    v_12852 = list3(stack[-1], stack[0], v_12852);
    env = stack[-5];
    goto v_12819;
v_12820:
    goto v_12814;
v_12815:
    goto v_12816;
v_12817:
    goto v_12818;
v_12819:
    v_12853 = list3(stack[-4], stack[-2], v_12852);
    goto v_12809;
v_12810:
    v_12852 = lisp_true;
    goto v_12811;
v_12812:
    goto v_12808;
v_12809:
    goto v_12810;
v_12811:
    return list2(v_12853, v_12852);
v_12798:
    goto v_12849;
v_12845:
    v_12853 = qvalue(elt(env, 9)); // !*!*a2sfn
    goto v_12846;
v_12847:
    v_12852 = stack[-3];
    goto v_12848;
v_12849:
    goto v_12845;
v_12846:
    goto v_12847;
v_12848:
    return list2(v_12853, v_12852);
    v_12852 = nil;
v_12770:
    return onevalue(v_12852);
}



// Code for makeset

static LispObject CC_makeset(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12806, v_12807, v_12808;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_12766;
// end of prologue
    v_12808 = nil;
v_12771:
    v_12806 = stack[0];
    if (v_12806 == nil) goto v_12774;
    else goto v_12775;
v_12774:
    v_12806 = v_12808;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12806);
    }
v_12775:
    goto v_12785;
v_12781:
    v_12806 = stack[0];
    v_12807 = qcar(v_12806);
    goto v_12782;
v_12783:
    v_12806 = stack[0];
    v_12806 = qcdr(v_12806);
    goto v_12784;
v_12785:
    goto v_12781;
v_12782:
    goto v_12783;
v_12784:
    v_12806 = Lmember(nil, v_12807, v_12806);
    if (v_12806 == nil) goto v_12780;
    v_12806 = stack[0];
    v_12806 = qcdr(v_12806);
    stack[0] = v_12806;
    goto v_12771;
v_12780:
    goto v_12800;
v_12796:
    v_12806 = stack[0];
    v_12806 = qcar(v_12806);
    goto v_12797;
v_12798:
    v_12807 = v_12808;
    goto v_12799;
v_12800:
    goto v_12796;
v_12797:
    goto v_12798;
v_12799:
    v_12806 = cons(v_12806, v_12807);
    env = stack[-1];
    v_12808 = v_12806;
    v_12806 = stack[0];
    v_12806 = qcdr(v_12806);
    stack[0] = v_12806;
    goto v_12771;
    v_12806 = nil;
    return onevalue(v_12806);
}



// Code for dm!-minus

static LispObject CC_dmKminus(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12780, v_12781;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
// copy arguments values to proper place
    v_12780 = v_12766;
// end of prologue
    fn = elt(env, 1); // !:minus
    v_12780 = (*qfn1(fn))(fn, v_12780);
    v_12781 = v_12780;
    v_12780 = v_12781;
    if (v_12780 == nil) goto v_12773;
    else goto v_12774;
v_12773:
    v_12780 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12772;
v_12774:
    v_12780 = v_12781;
    goto v_12772;
    v_12780 = nil;
v_12772:
    return onevalue(v_12780);
}



// Code for evgradlexcomp

static LispObject CC_evgradlexcomp(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12848, v_12849;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_12767;
    stack[-2] = v_12766;
// end of prologue
v_12771:
    v_12848 = stack[-2];
    if (v_12848 == nil) goto v_12774;
    else goto v_12775;
v_12774:
    v_12848 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12770;
v_12775:
    v_12848 = stack[-1];
    if (v_12848 == nil) goto v_12778;
    else goto v_12779;
v_12778:
    v_12848 = elt(env, 1); // (0)
    stack[-1] = v_12848;
    goto v_12771;
v_12779:
    goto v_12789;
v_12785:
    v_12848 = stack[-2];
    v_12849 = qcar(v_12848);
    goto v_12786;
v_12787:
    v_12848 = stack[-1];
    v_12848 = qcar(v_12848);
    goto v_12788;
v_12789:
    goto v_12785;
v_12786:
    goto v_12787;
v_12788:
    fn = elt(env, 2); // iequal
    v_12848 = (*qfn2(fn))(fn, v_12849, v_12848);
    env = stack[-4];
    if (v_12848 == nil) goto v_12783;
    v_12848 = stack[-2];
    v_12848 = qcdr(v_12848);
    stack[-2] = v_12848;
    v_12848 = stack[-1];
    v_12848 = qcdr(v_12848);
    stack[-1] = v_12848;
    goto v_12771;
v_12783:
    v_12848 = stack[-2];
    fn = elt(env, 3); // evtdeg
    stack[0] = (*qfn1(fn))(fn, v_12848);
    env = stack[-4];
    v_12848 = stack[-1];
    fn = elt(env, 3); // evtdeg
    v_12848 = (*qfn1(fn))(fn, v_12848);
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v_12848;
    goto v_12815;
v_12811:
    v_12849 = stack[-3];
    goto v_12812;
v_12813:
    v_12848 = stack[0];
    goto v_12814;
v_12815:
    goto v_12811;
v_12812:
    goto v_12813;
v_12814:
    fn = elt(env, 2); // iequal
    v_12848 = (*qfn2(fn))(fn, v_12849, v_12848);
    if (v_12848 == nil) goto v_12809;
    goto v_12826;
v_12822:
    v_12848 = stack[-2];
    v_12849 = qcar(v_12848);
    goto v_12823;
v_12824:
    v_12848 = stack[-1];
    v_12848 = qcar(v_12848);
    goto v_12825;
v_12826:
    goto v_12822;
v_12823:
    goto v_12824;
v_12825:
    if (((intptr_t)(v_12849)) > ((intptr_t)(v_12848))) goto v_12820;
    else goto v_12821;
v_12820:
    v_12848 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12819;
v_12821:
    v_12848 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_12819;
    v_12848 = nil;
v_12819:
    goto v_12807;
v_12809:
    goto v_12841;
v_12837:
    v_12849 = stack[-3];
    goto v_12838;
v_12839:
    v_12848 = stack[0];
    goto v_12840;
v_12841:
    goto v_12837;
v_12838:
    goto v_12839;
v_12840:
    if (((intptr_t)(v_12849)) > ((intptr_t)(v_12848))) goto v_12835;
    else goto v_12836;
v_12835:
    v_12848 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12807;
v_12836:
    v_12848 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_12807;
    v_12848 = nil;
v_12807:
    goto v_12770;
    v_12848 = nil;
v_12770:
    return onevalue(v_12848);
}



// Code for bytelist2id

static LispObject CC_bytelist2id(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12771;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
// copy arguments values to proper place
    v_12771 = v_12766;
// end of prologue
    fn = elt(env, 1); // list2string
    v_12771 = (*qfn1(fn))(fn, v_12771);
        return Lintern(nil, v_12771);
}



// Code for collectphystype

static LispObject CC_collectphystype(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12826;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_12766;
// end of prologue
    v_12826 = stack[0];
    fn = elt(env, 1); // physopp
    v_12826 = (*qfn1(fn))(fn, v_12826);
    env = stack[-4];
    if (v_12826 == nil) goto v_12771;
    v_12826 = stack[0];
    fn = elt(env, 2); // getphystype
    v_12826 = (*qfn1(fn))(fn, v_12826);
    return ncons(v_12826);
v_12771:
    v_12826 = stack[0];
    if (!consp(v_12826)) goto v_12777;
    else goto v_12778;
v_12777:
    v_12826 = nil;
    goto v_12769;
v_12778:
    v_12826 = stack[0];
    stack[-3] = v_12826;
    v_12826 = stack[-3];
    if (v_12826 == nil) goto v_12793;
    else goto v_12794;
v_12793:
    v_12826 = nil;
    goto v_12788;
v_12794:
    v_12826 = stack[-3];
    v_12826 = qcar(v_12826);
    fn = elt(env, 2); // getphystype
    v_12826 = (*qfn1(fn))(fn, v_12826);
    env = stack[-4];
    v_12826 = ncons(v_12826);
    env = stack[-4];
    stack[-1] = v_12826;
    stack[-2] = v_12826;
v_12789:
    v_12826 = stack[-3];
    v_12826 = qcdr(v_12826);
    stack[-3] = v_12826;
    v_12826 = stack[-3];
    if (v_12826 == nil) goto v_12807;
    else goto v_12808;
v_12807:
    v_12826 = stack[-2];
    goto v_12788;
v_12808:
    goto v_12816;
v_12812:
    stack[0] = stack[-1];
    goto v_12813;
v_12814:
    v_12826 = stack[-3];
    v_12826 = qcar(v_12826);
    fn = elt(env, 2); // getphystype
    v_12826 = (*qfn1(fn))(fn, v_12826);
    env = stack[-4];
    v_12826 = ncons(v_12826);
    env = stack[-4];
    goto v_12815;
v_12816:
    goto v_12812;
v_12813:
    goto v_12814;
v_12815:
    v_12826 = Lrplacd(nil, stack[0], v_12826);
    env = stack[-4];
    v_12826 = stack[-1];
    v_12826 = qcdr(v_12826);
    stack[-1] = v_12826;
    goto v_12789;
v_12788:
    {
        fn = elt(env, 3); // deletemult!*
        return (*qfn1(fn))(fn, v_12826);
    }
    v_12826 = nil;
v_12769:
    return onevalue(v_12826);
}



// Code for replace1_parents

static LispObject CC_replace1_parents(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12785, v_12786, v_12787;
    LispObject fn;
    LispObject v_12768, v_12767, v_12766;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "replace1_parents");
    va_start(aa, nargs);
    v_12766 = va_arg(aa, LispObject);
    v_12767 = va_arg(aa, LispObject);
    v_12768 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12785 = v_12768;
    v_12786 = v_12767;
    v_12787 = v_12766;
// end of prologue
    goto v_12777;
v_12771:
    v_12787 = qcar(v_12787);
    goto v_12772;
v_12773:
    v_12786 = qcar(v_12786);
    goto v_12774;
v_12775:
    v_12785 = qcdr(v_12785);
    v_12785 = qcar(v_12785);
    goto v_12776;
v_12777:
    goto v_12771;
v_12772:
    goto v_12773;
v_12774:
    goto v_12775;
v_12776:
    {
        fn = elt(env, 1); // replace2_parents
        return (*qfnn(fn))(fn, 3, v_12787, v_12786, v_12785);
    }
}



// Code for one!-entry!-listp

static LispObject CC_oneKentryKlistp(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12802, v_12803;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12767;
    stack[-1] = v_12766;
// end of prologue
v_12765:
    v_12802 = stack[-1];
    if (v_12802 == nil) goto v_12771;
    else goto v_12772;
v_12771:
    v_12802 = lisp_true;
    goto v_12770;
v_12772:
    goto v_12786;
v_12782:
    v_12802 = stack[-1];
    v_12803 = qcar(v_12802);
    goto v_12783;
v_12784:
    v_12802 = stack[0];
    goto v_12785;
v_12786:
    goto v_12782;
v_12783:
    goto v_12784;
v_12785:
    fn = elt(env, 1); // one!-entryp
    v_12802 = (*qfn2(fn))(fn, v_12803, v_12802);
    env = stack[-2];
    if (v_12802 == nil) goto v_12779;
    else goto v_12780;
v_12779:
    v_12802 = nil;
    goto v_12778;
v_12780:
    goto v_12798;
v_12794:
    v_12802 = stack[-1];
    v_12803 = qcdr(v_12802);
    goto v_12795;
v_12796:
    v_12802 = stack[0];
    goto v_12797;
v_12798:
    goto v_12794;
v_12795:
    goto v_12796;
v_12797:
    stack[-1] = v_12803;
    stack[0] = v_12802;
    goto v_12765;
    v_12802 = nil;
v_12778:
    goto v_12770;
    v_12802 = nil;
v_12770:
    return onevalue(v_12802);
}



// Code for setel1

static LispObject CC_setel1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12854, v_12855, v_12856;
    LispObject fn;
    LispObject v_12769, v_12768, v_12767, v_12766;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "setel1");
    va_start(aa, nargs);
    v_12766 = va_arg(aa, LispObject);
    v_12767 = va_arg(aa, LispObject);
    v_12768 = va_arg(aa, LispObject);
    v_12769 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_12769,v_12768,v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_12766,v_12767,v_12768,v_12769);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_12769;
    stack[-1] = v_12768;
    stack[-2] = v_12767;
    stack[-3] = v_12766;
// end of prologue
v_12773:
    v_12854 = stack[-2];
    v_12854 = qcar(v_12854);
    v_12854 = integerp(v_12854);
    if (v_12854 == nil) goto v_12776;
    else goto v_12777;
v_12776:
    goto v_12786;
v_12782:
    v_12854 = stack[-2];
    v_12855 = qcar(v_12854);
    goto v_12783;
v_12784:
    v_12854 = elt(env, 1); // "array index"
    goto v_12785;
v_12786:
    goto v_12782;
v_12783:
    goto v_12784;
v_12785:
    {
        fn = elt(env, 4); // typerr
        return (*qfn2(fn))(fn, v_12855, v_12854);
    }
v_12777:
    goto v_12798;
v_12794:
    v_12854 = stack[-2];
    v_12855 = qcar(v_12854);
    goto v_12795;
v_12796:
    v_12854 = stack[0];
    v_12854 = qcar(v_12854);
    goto v_12797;
v_12798:
    goto v_12794;
v_12795:
    goto v_12796;
v_12797:
    v_12854 = (LispObject)geq2(v_12855, v_12854);
    v_12854 = v_12854 ? lisp_true : nil;
    env = stack[-4];
    if (v_12854 == nil) goto v_12792;
    else goto v_12790;
v_12792:
    goto v_12809;
v_12805:
    v_12854 = stack[-2];
    v_12855 = qcar(v_12854);
    goto v_12806;
v_12807:
    v_12854 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12808;
v_12809:
    goto v_12805;
v_12806:
    goto v_12807;
v_12808:
    v_12854 = (LispObject)lessp2(v_12855, v_12854);
    v_12854 = v_12854 ? lisp_true : nil;
    env = stack[-4];
    if (v_12854 == nil) goto v_12803;
    else goto v_12790;
v_12803:
    goto v_12791;
v_12790:
    goto v_12820;
v_12814:
    v_12856 = elt(env, 2); // rlisp
    goto v_12815;
v_12816:
    v_12855 = (LispObject)368+TAG_FIXNUM; // 23
    goto v_12817;
v_12818:
    v_12854 = elt(env, 3); // "Array out of bounds"
    goto v_12819;
v_12820:
    goto v_12814;
v_12815:
    goto v_12816;
v_12817:
    goto v_12818;
v_12819:
    {
        fn = elt(env, 5); // rerror
        return (*qfnn(fn))(fn, 3, v_12856, v_12855, v_12854);
    }
v_12791:
    v_12854 = stack[-2];
    v_12854 = qcdr(v_12854);
    if (v_12854 == nil) goto v_12824;
    else goto v_12825;
v_12824:
    goto v_12834;
v_12828:
    v_12856 = stack[-3];
    goto v_12829;
v_12830:
    v_12854 = stack[-2];
    v_12855 = qcar(v_12854);
    goto v_12831;
v_12832:
    v_12854 = stack[-1];
    goto v_12833;
v_12834:
    goto v_12828;
v_12829:
    goto v_12830;
v_12831:
    goto v_12832;
v_12833:
    *(LispObject *)((char *)v_12856 + (CELL-TAG_VECTOR) + (((intptr_t)v_12855-TAG_FIXNUM)/(16/CELL))) = v_12854;
    goto v_12772;
v_12825:
    goto v_12845;
v_12841:
    v_12855 = stack[-3];
    goto v_12842;
v_12843:
    v_12854 = stack[-2];
    v_12854 = qcar(v_12854);
    goto v_12844;
v_12845:
    goto v_12841;
v_12842:
    goto v_12843;
v_12844:
    v_12854 = *(LispObject *)((char *)v_12855 + (CELL-TAG_VECTOR) + (((intptr_t)v_12854-TAG_FIXNUM)/(16/CELL)));
    stack[-3] = v_12854;
    v_12854 = stack[-2];
    v_12854 = qcdr(v_12854);
    stack[-2] = v_12854;
    v_12854 = stack[0];
    v_12854 = qcdr(v_12854);
    stack[0] = v_12854;
    goto v_12773;
    v_12854 = nil;
v_12772:
    return onevalue(v_12854);
}



// Code for mo_equal!?

static LispObject CC_mo_equalW(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12781;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12767;
    v_12781 = v_12766;
// end of prologue
    goto v_12773;
v_12769:
    v_12781 = qcar(v_12781);
    fn = elt(env, 1); // mo!=shorten
    stack[-1] = (*qfn1(fn))(fn, v_12781);
    env = stack[-2];
    goto v_12770;
v_12771:
    v_12781 = stack[0];
    v_12781 = qcar(v_12781);
    fn = elt(env, 1); // mo!=shorten
    v_12781 = (*qfn1(fn))(fn, v_12781);
    goto v_12772;
v_12773:
    goto v_12769;
v_12770:
    goto v_12771;
v_12772:
    v_12781 = (equal(stack[-1], v_12781) ? lisp_true : nil);
    return onevalue(v_12781);
}



// Code for splitlist!:

static LispObject CC_splitlistT(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12806, v_12807, v_12808;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12767;
    stack[-1] = v_12766;
// end of prologue
    v_12808 = nil;
v_12772:
    v_12806 = stack[-1];
    if (v_12806 == nil) goto v_12775;
    else goto v_12776;
v_12775:
    v_12806 = v_12808;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12806);
    }
v_12776:
    goto v_12787;
v_12783:
    v_12806 = stack[-1];
    v_12807 = qcar(v_12806);
    goto v_12784;
v_12785:
    v_12806 = stack[0];
    goto v_12786;
v_12787:
    goto v_12783;
v_12784:
    goto v_12785;
v_12786:
    if (!consp(v_12807)) goto v_12781;
    v_12807 = qcar(v_12807);
    if (v_12807 == v_12806) goto v_12780;
    else goto v_12781;
v_12780:
    goto v_12796;
v_12792:
    v_12806 = stack[-1];
    v_12806 = qcar(v_12806);
    goto v_12793;
v_12794:
    v_12807 = v_12808;
    goto v_12795;
v_12796:
    goto v_12792;
v_12793:
    goto v_12794;
v_12795:
    v_12806 = cons(v_12806, v_12807);
    env = stack[-2];
    v_12808 = v_12806;
    v_12806 = stack[-1];
    v_12806 = qcdr(v_12806);
    stack[-1] = v_12806;
    goto v_12772;
v_12781:
    v_12806 = stack[-1];
    v_12806 = qcdr(v_12806);
    stack[-1] = v_12806;
    goto v_12772;
    v_12806 = nil;
    return onevalue(v_12806);
}



// Code for innprodkp

static LispObject CC_innprodkp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12821, v_12822, v_12823;
    LispObject fn;
    LispObject v_12769, v_12768, v_12767, v_12766;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "innprodkp");
    va_start(aa, nargs);
    v_12766 = va_arg(aa, LispObject);
    v_12767 = va_arg(aa, LispObject);
    v_12768 = va_arg(aa, LispObject);
    v_12769 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_12769,v_12768,v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_12766,v_12767,v_12768,v_12769);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12769;
    stack[-1] = v_12768;
    stack[-2] = v_12767;
    v_12822 = v_12766;
// end of prologue
v_12773:
    v_12821 = stack[-1];
    if (v_12821 == nil) goto v_12776;
    else goto v_12777;
v_12776:
    v_12821 = nil;
    goto v_12772;
v_12777:
    goto v_12786;
v_12782:
    v_12823 = stack[-2];
    goto v_12783;
v_12784:
    v_12821 = stack[-1];
    v_12821 = qcar(v_12821);
    goto v_12785;
v_12786:
    goto v_12782;
v_12783:
    goto v_12784;
v_12785:
    if (equal(v_12823, v_12821)) goto v_12780;
    else goto v_12781;
v_12780:
    goto v_12795;
v_12791:
    goto v_12792;
v_12793:
    goto v_12802;
v_12798:
    goto v_12799;
v_12800:
    v_12821 = stack[-1];
    v_12821 = qcdr(v_12821);
    goto v_12801;
v_12802:
    goto v_12798;
v_12799:
    goto v_12800;
v_12801:
    fn = elt(env, 1); // reversip2
    v_12821 = (*qfn2(fn))(fn, v_12822, v_12821);
    goto v_12794;
v_12795:
    goto v_12791;
v_12792:
    goto v_12793;
v_12794:
    {
        LispObject v_12827 = stack[0];
        return cons(v_12827, v_12821);
    }
v_12781:
    goto v_12813;
v_12809:
    v_12821 = stack[-1];
    v_12821 = qcar(v_12821);
    goto v_12810;
v_12811:
    goto v_12812;
v_12813:
    goto v_12809;
v_12810:
    goto v_12811;
v_12812:
    v_12821 = cons(v_12821, v_12822);
    env = stack[-3];
    v_12822 = v_12821;
    v_12821 = stack[-1];
    v_12821 = qcdr(v_12821);
    stack[-1] = v_12821;
    v_12821 = stack[0];
    v_12821 = (v_12821 == nil ? lisp_true : nil);
    stack[0] = v_12821;
    goto v_12773;
    v_12821 = nil;
v_12772:
    return onevalue(v_12821);
}



// Code for drop_rl_with

static LispObject CC_drop_rl_with(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12794, v_12795, v_12796;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_12794 = v_12767;
    v_12795 = v_12766;
// end of prologue
    goto v_12776;
v_12770:
    stack[-1] = v_12794;
    goto v_12771;
v_12772:
    stack[0] = elt(env, 1); // rl_with
    goto v_12773;
v_12774:
    goto v_12784;
v_12780:
    v_12796 = v_12795;
    goto v_12781;
v_12782:
    goto v_12791;
v_12787:
    v_12795 = v_12794;
    goto v_12788;
v_12789:
    v_12794 = elt(env, 1); // rl_with
    goto v_12790;
v_12791:
    goto v_12787;
v_12788:
    goto v_12789;
v_12790:
    v_12794 = get(v_12795, v_12794);
    env = stack[-2];
    goto v_12783;
v_12784:
    goto v_12780;
v_12781:
    goto v_12782;
v_12783:
    v_12794 = Ldelete(nil, v_12796, v_12794);
    goto v_12775;
v_12776:
    goto v_12770;
v_12771:
    goto v_12772;
v_12773:
    goto v_12774;
v_12775:
    {
        LispObject v_12799 = stack[-1];
        LispObject v_12800 = stack[0];
        return Lputprop(nil, 3, v_12799, v_12800, v_12794);
    }
}



// Code for ordered!-gcd!-mod!-p

static LispObject CC_orderedKgcdKmodKp(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12848, v_12849;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12767;
    stack[-1] = v_12766;
// end of prologue
    v_12848 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_12848;
v_12772:
    goto v_12780;
v_12776:
    v_12849 = stack[-1];
    goto v_12777;
v_12778:
    v_12848 = stack[0];
    goto v_12779;
v_12780:
    goto v_12776;
v_12777:
    goto v_12778;
v_12779:
    fn = elt(env, 4); // reduce!-degree!-mod!-p
    v_12848 = (*qfn2(fn))(fn, v_12849, v_12848);
    env = stack[-3];
    stack[-1] = v_12848;
    v_12848 = stack[-1];
    if (v_12848 == nil) goto v_12785;
    else goto v_12786;
v_12785:
    v_12848 = stack[0];
    {
        fn = elt(env, 5); // monic!-mod!-p
        return (*qfn1(fn))(fn, v_12848);
    }
v_12786:
    v_12848 = stack[-2];
    v_12848 = add1(v_12848);
    env = stack[-3];
    stack[-2] = v_12848;
    v_12848 = stack[-1];
    if (!consp(v_12848)) goto v_12798;
    else goto v_12799;
v_12798:
    v_12848 = lisp_true;
    goto v_12797;
v_12799:
    v_12848 = stack[-1];
    v_12848 = qcar(v_12848);
    v_12848 = (consp(v_12848) ? nil : lisp_true);
    goto v_12797;
    v_12848 = nil;
v_12797:
    if (v_12848 == nil) goto v_12795;
    goto v_12812;
v_12808:
    v_12849 = qvalue(elt(env, 2)); // reduction!-count
    goto v_12809;
v_12810:
    v_12848 = stack[-2];
    goto v_12811;
v_12812:
    goto v_12808;
v_12809:
    goto v_12810;
v_12811:
    v_12848 = plus2(v_12849, v_12848);
    env = stack[-3];
    qvalue(elt(env, 2)) = v_12848; // reduction!-count
    v_12848 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12771;
v_12795:
    goto v_12823;
v_12819:
    v_12848 = stack[-1];
    v_12848 = qcar(v_12848);
    v_12848 = qcar(v_12848);
    v_12849 = qcdr(v_12848);
    goto v_12820;
v_12821:
    v_12848 = stack[0];
    v_12848 = qcar(v_12848);
    v_12848 = qcar(v_12848);
    v_12848 = qcdr(v_12848);
    goto v_12822;
v_12823:
    goto v_12819;
v_12820:
    goto v_12821;
v_12822:
    v_12848 = (LispObject)lessp2(v_12849, v_12848);
    v_12848 = v_12848 ? lisp_true : nil;
    env = stack[-3];
    if (v_12848 == nil) goto v_12817;
    goto v_12841;
v_12837:
    v_12849 = qvalue(elt(env, 2)); // reduction!-count
    goto v_12838;
v_12839:
    v_12848 = stack[-2];
    goto v_12840;
v_12841:
    goto v_12837;
v_12838:
    goto v_12839;
v_12840:
    v_12848 = plus2(v_12849, v_12848);
    env = stack[-3];
    qvalue(elt(env, 2)) = v_12848; // reduction!-count
    v_12848 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_12848;
    v_12848 = stack[-1];
    v_12849 = v_12848;
    v_12848 = stack[0];
    stack[-1] = v_12848;
    v_12848 = v_12849;
    stack[0] = v_12848;
    goto v_12793;
v_12817:
v_12793:
    goto v_12772;
v_12771:
    return onevalue(v_12848);
}



// Code for ctx_idl

static LispObject CC_ctx_idl(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12811;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_12811 = v_12766;
// end of prologue
    fn = elt(env, 1); // ctx_ial
    v_12811 = (*qfn1(fn))(fn, v_12811);
    env = stack[-4];
    stack[-3] = v_12811;
    v_12811 = stack[-3];
    if (v_12811 == nil) goto v_12778;
    else goto v_12779;
v_12778:
    v_12811 = nil;
    goto v_12772;
v_12779:
    v_12811 = stack[-3];
    v_12811 = qcar(v_12811);
    v_12811 = qcar(v_12811);
    v_12811 = ncons(v_12811);
    env = stack[-4];
    stack[-1] = v_12811;
    stack[-2] = v_12811;
v_12773:
    v_12811 = stack[-3];
    v_12811 = qcdr(v_12811);
    stack[-3] = v_12811;
    v_12811 = stack[-3];
    if (v_12811 == nil) goto v_12792;
    else goto v_12793;
v_12792:
    v_12811 = stack[-2];
    goto v_12772;
v_12793:
    goto v_12801;
v_12797:
    stack[0] = stack[-1];
    goto v_12798;
v_12799:
    v_12811 = stack[-3];
    v_12811 = qcar(v_12811);
    v_12811 = qcar(v_12811);
    v_12811 = ncons(v_12811);
    env = stack[-4];
    goto v_12800;
v_12801:
    goto v_12797;
v_12798:
    goto v_12799;
v_12800:
    v_12811 = Lrplacd(nil, stack[0], v_12811);
    env = stack[-4];
    v_12811 = stack[-1];
    v_12811 = qcdr(v_12811);
    stack[-1] = v_12811;
    goto v_12773;
v_12772:
    return onevalue(v_12811);
}



// Code for mkpartitions1

static LispObject CC_mkpartitions1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12894, v_12895, v_12896, v_12897;
    LispObject v_12771, v_12770, v_12769, v_12768, v_12767, v_12766;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "mkpartitions1");
    va_start(aa, nargs);
    v_12766 = va_arg(aa, LispObject);
    v_12767 = va_arg(aa, LispObject);
    v_12768 = va_arg(aa, LispObject);
    v_12769 = va_arg(aa, LispObject);
    v_12770 = va_arg(aa, LispObject);
    v_12771 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_12771,v_12770,v_12769,v_12768,v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_12766,v_12767,v_12768,v_12769,v_12770,v_12771);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-3] = v_12771;
    stack[-4] = v_12770;
    stack[-5] = v_12769;
    stack[-6] = v_12768;
    stack[-7] = v_12767;
    stack[-8] = v_12766;
// end of prologue
v_12779:
    goto v_12788;
v_12784:
    v_12895 = stack[-7];
    goto v_12785;
v_12786:
    v_12894 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12787;
v_12788:
    goto v_12784;
v_12785:
    goto v_12786;
v_12787:
    if (v_12895 == v_12894) goto v_12782;
    else goto v_12783;
v_12782:
    goto v_12800;
v_12796:
    v_12895 = stack[-8];
    goto v_12797;
v_12798:
    v_12894 = stack[-6];
    goto v_12799;
v_12800:
    goto v_12796;
v_12797:
    goto v_12798;
v_12799:
    v_12894 = (LispObject)geq2(v_12895, v_12894);
    v_12894 = v_12894 ? lisp_true : nil;
    env = stack[-10];
    if (v_12894 == nil) goto v_12794;
    goto v_12808;
v_12804:
    goto v_12815;
v_12811:
    v_12895 = stack[-8];
    goto v_12812;
v_12813:
    v_12894 = stack[-4];
    goto v_12814;
v_12815:
    goto v_12811;
v_12812:
    goto v_12813;
v_12814:
    v_12894 = cons(v_12895, v_12894);
    env = stack[-10];
    v_12895 = Lreverse(nil, v_12894);
    goto v_12805;
v_12806:
    v_12894 = stack[-3];
    goto v_12807;
v_12808:
    goto v_12804;
v_12805:
    goto v_12806;
v_12807:
    return cons(v_12895, v_12894);
v_12794:
    v_12894 = stack[-3];
    goto v_12778;
    goto v_12781;
v_12783:
    goto v_12829;
v_12825:
    v_12895 = stack[-6];
    goto v_12826;
v_12827:
    v_12894 = stack[-5];
    goto v_12828;
v_12829:
    goto v_12825;
v_12826:
    goto v_12827;
v_12828:
    v_12894 = (LispObject)greaterp2(v_12895, v_12894);
    v_12894 = v_12894 ? lisp_true : nil;
    env = stack[-10];
    if (v_12894 == nil) goto v_12823;
    v_12894 = stack[-3];
    goto v_12778;
v_12823:
    goto v_12840;
v_12836:
    v_12895 = stack[-8];
    goto v_12837;
v_12838:
    v_12894 = stack[-6];
    goto v_12839;
v_12840:
    goto v_12836;
v_12837:
    goto v_12838;
v_12839:
    v_12894 = difference2(v_12895, v_12894);
    env = stack[-10];
    stack[-9] = v_12894;
    v_12894 = stack[-7];
    v_12894 = sub1(v_12894);
    env = stack[-10];
    stack[-2] = v_12894;
    goto v_12850;
v_12846:
    goto v_12856;
v_12852:
    v_12895 = stack[-8];
    goto v_12853;
v_12854:
    v_12894 = stack[-6];
    goto v_12855;
v_12856:
    goto v_12852;
v_12853:
    goto v_12854;
v_12855:
    stack[0] = difference2(v_12895, v_12894);
    env = stack[-10];
    goto v_12847;
v_12848:
    v_12894 = stack[-7];
    v_12894 = sub1(v_12894);
    env = stack[-10];
    goto v_12849;
v_12850:
    goto v_12846;
v_12847:
    goto v_12848;
v_12849:
    v_12894 = quot2(stack[0], v_12894);
    env = stack[-10];
    stack[-1] = v_12894;
    goto v_12866;
v_12862:
    v_12895 = stack[-6];
    goto v_12863;
v_12864:
    v_12894 = stack[-4];
    goto v_12865;
v_12866:
    goto v_12862;
v_12863:
    goto v_12864;
v_12865:
    v_12894 = cons(v_12895, v_12894);
    env = stack[-10];
    stack[0] = v_12894;
    goto v_12882;
v_12870:
    goto v_12871;
v_12872:
    goto v_12873;
v_12874:
    v_12894 = stack[-6];
    v_12897 = add1(v_12894);
    env = stack[-10];
    goto v_12875;
v_12876:
    v_12896 = stack[-5];
    goto v_12877;
v_12878:
    v_12895 = stack[-4];
    goto v_12879;
v_12880:
    v_12894 = stack[-3];
    goto v_12881;
v_12882:
    goto v_12870;
v_12871:
    goto v_12872;
v_12873:
    goto v_12874;
v_12875:
    goto v_12876;
v_12877:
    goto v_12878;
v_12879:
    goto v_12880;
v_12881:
    v_12894 = CC_mkpartitions1(elt(env, 0), 6, stack[-8], stack[-7], v_12897, v_12896, v_12895, v_12894);
    env = stack[-10];
    stack[-3] = v_12894;
    v_12894 = stack[0];
    stack[-4] = v_12894;
    v_12894 = stack[-1];
    stack[-5] = v_12894;
    v_12894 = stack[-2];
    stack[-7] = v_12894;
    v_12894 = stack[-9];
    stack[-8] = v_12894;
    goto v_12779;
v_12781:
    v_12894 = nil;
v_12778:
    return onevalue(v_12894);
}



// Code for rl_atnum

static LispObject CC_rl_atnum(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12777;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_12777 = v_12766;
// end of prologue
    goto v_12773;
v_12769:
    stack[0] = qvalue(elt(env, 1)); // rl_atnum!*
    goto v_12770;
v_12771:
    v_12777 = ncons(v_12777);
    env = stack[-1];
    goto v_12772;
v_12773:
    goto v_12769;
v_12770:
    goto v_12771;
v_12772:
    {
        LispObject v_12779 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_12779, v_12777);
    }
}



// Code for squared!+matrix!+p

static LispObject CC_squaredLmatrixLp(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12789;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12766;
// end of prologue
    v_12789 = stack[0];
    fn = elt(env, 1); // matrix!+p
    v_12789 = (*qfn1(fn))(fn, v_12789);
    env = stack[-2];
    if (v_12789 == nil) goto v_12774;
    goto v_12783;
v_12779:
    v_12789 = stack[0];
    fn = elt(env, 2); // get!+row!+nr
    stack[-1] = (*qfn1(fn))(fn, v_12789);
    env = stack[-2];
    goto v_12780;
v_12781:
    v_12789 = stack[0];
    fn = elt(env, 3); // get!+col!+nr
    v_12789 = (*qfn1(fn))(fn, v_12789);
    goto v_12782;
v_12783:
    goto v_12779;
v_12780:
    goto v_12781;
v_12782:
    if (equal(stack[-1], v_12789)) goto v_12778;
    else goto v_12774;
v_12778:
    v_12789 = lisp_true;
    goto v_12769;
v_12774:
    v_12789 = nil;
v_12769:
    return onevalue(v_12789);
}



// Code for rl_pnf

static LispObject CC_rl_pnf(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12777;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_12777 = v_12766;
// end of prologue
    goto v_12773;
v_12769:
    stack[0] = qvalue(elt(env, 1)); // rl_pnf!*
    goto v_12770;
v_12771:
    v_12777 = ncons(v_12777);
    env = stack[-1];
    goto v_12772;
v_12773:
    goto v_12769;
v_12770:
    goto v_12771;
v_12772:
    {
        LispObject v_12779 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_12779, v_12777);
    }
}



// Code for pasf_sacat

static LispObject CC_pasf_sacat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12771, v_12772, v_12773;
    LispObject v_12768, v_12767, v_12766;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pasf_sacat");
    va_start(aa, nargs);
    v_12766 = va_arg(aa, LispObject);
    v_12767 = va_arg(aa, LispObject);
    v_12768 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12771 = v_12768;
    v_12772 = v_12767;
    v_12773 = v_12766;
// end of prologue
    v_12771 = nil;
    return onevalue(v_12771);
}



// Code for ev_lexcomp

static LispObject CC_ev_lexcomp(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12809, v_12810;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12767;
    stack[-1] = v_12766;
// end of prologue
v_12771:
    v_12809 = stack[-1];
    if (v_12809 == nil) goto v_12774;
    else goto v_12775;
v_12774:
    v_12809 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12770;
v_12775:
    goto v_12785;
v_12781:
    v_12809 = stack[-1];
    v_12810 = qcar(v_12809);
    goto v_12782;
v_12783:
    v_12809 = stack[0];
    v_12809 = qcar(v_12809);
    goto v_12784;
v_12785:
    goto v_12781;
v_12782:
    goto v_12783;
v_12784:
    fn = elt(env, 1); // iequal
    v_12809 = (*qfn2(fn))(fn, v_12810, v_12809);
    env = stack[-2];
    if (v_12809 == nil) goto v_12779;
    v_12809 = stack[-1];
    v_12809 = qcdr(v_12809);
    stack[-1] = v_12809;
    v_12809 = stack[0];
    v_12809 = qcdr(v_12809);
    stack[0] = v_12809;
    goto v_12771;
v_12779:
    goto v_12800;
v_12796:
    v_12809 = stack[-1];
    v_12810 = qcar(v_12809);
    goto v_12797;
v_12798:
    v_12809 = stack[0];
    v_12809 = qcar(v_12809);
    goto v_12799;
v_12800:
    goto v_12796;
v_12797:
    goto v_12798;
v_12799:
    if (((intptr_t)(v_12810)) > ((intptr_t)(v_12809))) goto v_12794;
    else goto v_12795;
v_12794:
    v_12809 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12770;
v_12795:
    v_12809 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_12770;
    v_12809 = nil;
v_12770:
    return onevalue(v_12809);
}



// Code for subs4q

static LispObject CC_subs4q(LispObject env,
                         LispObject v_12766)
{
    env = qenv(env);
    LispObject v_12913, v_12914, v_12915;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12766);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_12766;
// end of prologue
    stack[-3] = nil;
    stack[-2] = nil;
    v_12913 = elt(env, 2); // slash
    if (!symbolp(v_12913)) v_12913 = nil;
    else { v_12913 = qfastgets(v_12913);
           if (v_12913 != nil) { v_12913 = elt(v_12913, 9); // opmtch
#ifdef RECORD_GET
             if (v_12913 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_12913 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_12913 == SPID_NOPROP) v_12913 = nil; }}
#endif
    stack[-6] = v_12913;
    if (v_12913 == nil) goto v_12777;
    else goto v_12778;
v_12777:
    v_12913 = stack[-5];
    goto v_12773;
v_12778:
    v_12913 = stack[-5];
    fn = elt(env, 7); // prepsq
    v_12913 = (*qfn1(fn))(fn, v_12913);
    env = stack[-7];
    stack[-4] = v_12913;
    goto v_12789;
v_12785:
    v_12914 = elt(env, 2); // slash
    goto v_12786;
v_12787:
    v_12913 = elt(env, 3); // opmtch
    goto v_12788;
v_12789:
    goto v_12785;
v_12786:
    goto v_12787;
v_12788:
    v_12913 = Lremprop(nil, v_12914, v_12913);
    env = stack[-7];
    goto v_12799;
v_12793:
    v_12915 = elt(env, 4); // slash!*
    goto v_12794;
v_12795:
    v_12914 = elt(env, 3); // opmtch
    goto v_12796;
v_12797:
    v_12913 = stack[-6];
    goto v_12798;
v_12799:
    goto v_12793;
v_12794:
    goto v_12795;
v_12796:
    goto v_12797;
v_12798:
    v_12913 = Lputprop(nil, 3, v_12915, v_12914, v_12913);
    env = stack[-7];
v_12805:
    v_12913 = stack[-4];
    if (v_12913 == nil) goto v_12808;
    goto v_12818;
v_12814:
    v_12914 = stack[-4];
    stack[-3] = v_12914;
    goto v_12815;
v_12816:
    v_12913 = elt(env, 5); // quotient
    goto v_12817;
v_12818:
    goto v_12814;
v_12815:
    goto v_12816;
v_12817:
    if (!consp(v_12914)) goto v_12808;
    v_12914 = qcar(v_12914);
    if (v_12914 == v_12913) goto v_12812;
    else goto v_12808;
v_12812:
    goto v_12809;
v_12808:
    goto v_12804;
v_12809:
    goto v_12831;
v_12827:
    v_12914 = elt(env, 4); // slash!*
    goto v_12828;
v_12829:
    v_12913 = stack[-4];
    v_12913 = qcdr(v_12913);
    goto v_12830;
v_12831:
    goto v_12827;
v_12828:
    goto v_12829;
v_12830:
    v_12913 = cons(v_12914, v_12913);
    env = stack[-7];
    fn = elt(env, 3); // opmtch
    v_12913 = (*qfn1(fn))(fn, v_12913);
    env = stack[-7];
    if (v_12913 == nil) goto v_12824;
    else goto v_12823;
v_12824:
    goto v_12844;
v_12840:
    v_12914 = elt(env, 6); // minus
    goto v_12841;
v_12842:
    v_12913 = stack[-4];
    v_12913 = qcdr(v_12913);
    v_12913 = qcdr(v_12913);
    v_12913 = qcar(v_12913);
    goto v_12843;
v_12844:
    goto v_12840;
v_12841:
    goto v_12842;
v_12843:
    v_12913 = Lsmemq(nil, v_12914, v_12913);
    env = stack[-7];
    if (v_12913 == nil) goto v_12837;
    else goto v_12838;
v_12837:
    v_12913 = nil;
    goto v_12836;
v_12838:
    goto v_12861;
v_12855:
    stack[-1] = elt(env, 4); // slash!*
    goto v_12856;
v_12857:
    goto v_12869;
v_12865:
    v_12914 = elt(env, 6); // minus
    goto v_12866;
v_12867:
    v_12913 = stack[-4];
    v_12913 = qcdr(v_12913);
    v_12913 = qcar(v_12913);
    goto v_12868;
v_12869:
    goto v_12865;
v_12866:
    goto v_12867;
v_12868:
    v_12913 = list2(v_12914, v_12913);
    env = stack[-7];
    fn = elt(env, 8); // reval
    stack[0] = (*qfn1(fn))(fn, v_12913);
    env = stack[-7];
    goto v_12858;
v_12859:
    goto v_12880;
v_12876:
    v_12914 = elt(env, 6); // minus
    goto v_12877;
v_12878:
    v_12913 = stack[-4];
    v_12913 = qcdr(v_12913);
    v_12913 = qcdr(v_12913);
    v_12913 = qcar(v_12913);
    goto v_12879;
v_12880:
    goto v_12876;
v_12877:
    goto v_12878;
v_12879:
    v_12913 = list2(v_12914, v_12913);
    env = stack[-7];
    fn = elt(env, 8); // reval
    v_12913 = (*qfn1(fn))(fn, v_12913);
    env = stack[-7];
    goto v_12860;
v_12861:
    goto v_12855;
v_12856:
    goto v_12857;
v_12858:
    goto v_12859;
v_12860:
    v_12913 = list3(stack[-1], stack[0], v_12913);
    env = stack[-7];
    fn = elt(env, 3); // opmtch
    v_12913 = (*qfn1(fn))(fn, v_12913);
    env = stack[-7];
    goto v_12836;
    v_12913 = nil;
v_12836:
v_12823:
    stack[-4] = v_12913;
    v_12913 = stack[-2];
    if (v_12913 == nil) goto v_12888;
    else goto v_12887;
v_12888:
    v_12913 = stack[-4];
v_12887:
    stack[-2] = v_12913;
    goto v_12805;
v_12804:
    v_12913 = stack[-2];
    if (v_12913 == nil) goto v_12894;
    v_12913 = stack[-3];
    fn = elt(env, 9); // simp!*
    v_12913 = (*qfn1(fn))(fn, v_12913);
    env = stack[-7];
    goto v_12892;
v_12894:
    v_12913 = stack[-5];
    goto v_12892;
    v_12913 = nil;
v_12892:
    stack[-5] = v_12913;
    goto v_12908;
v_12902:
    v_12915 = elt(env, 2); // slash
    goto v_12903;
v_12904:
    v_12914 = elt(env, 3); // opmtch
    goto v_12905;
v_12906:
    v_12913 = stack[-6];
    goto v_12907;
v_12908:
    goto v_12902;
v_12903:
    goto v_12904;
v_12905:
    goto v_12906;
v_12907:
    v_12913 = Lputprop(nil, 3, v_12915, v_12914, v_12913);
    v_12913 = stack[-5];
v_12773:
    return onevalue(v_12913);
}



// Code for groedeletip

static LispObject CC_groedeletip(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12839, v_12840;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12767;
    stack[-1] = v_12766;
// end of prologue
v_12775:
    v_12839 = stack[0];
    if (v_12839 == nil) goto v_12778;
    goto v_12787;
v_12783:
    v_12840 = stack[-1];
    goto v_12784;
v_12785:
    v_12839 = stack[0];
    v_12839 = qcar(v_12839);
    goto v_12786;
v_12787:
    goto v_12783;
v_12784:
    goto v_12785;
v_12786:
    if (equal(v_12840, v_12839)) goto v_12782;
    else goto v_12778;
v_12782:
    goto v_12779;
v_12778:
    goto v_12774;
v_12779:
    v_12839 = stack[0];
    v_12839 = qcdr(v_12839);
    stack[0] = v_12839;
    goto v_12775;
v_12774:
    v_12839 = stack[0];
    if (v_12839 == nil) goto v_12796;
    else goto v_12797;
v_12796:
    v_12839 = nil;
    goto v_12771;
v_12797:
    v_12839 = stack[0];
    stack[-2] = v_12839;
v_12803:
    v_12839 = stack[0];
    v_12839 = qcdr(v_12839);
    if (v_12839 == nil) goto v_12806;
    else goto v_12807;
v_12806:
    goto v_12802;
v_12807:
    goto v_12819;
v_12815:
    v_12840 = stack[-1];
    goto v_12816;
v_12817:
    v_12839 = stack[0];
    v_12839 = qcdr(v_12839);
    v_12839 = qcar(v_12839);
    goto v_12818;
v_12819:
    goto v_12815;
v_12816:
    goto v_12817;
v_12818:
    if (equal(v_12840, v_12839)) goto v_12813;
    else goto v_12814;
v_12813:
    goto v_12829;
v_12825:
    v_12840 = stack[0];
    goto v_12826;
v_12827:
    v_12839 = stack[0];
    v_12839 = qcdr(v_12839);
    v_12839 = qcdr(v_12839);
    goto v_12828;
v_12829:
    goto v_12825;
v_12826:
    goto v_12827;
v_12828:
    fn = elt(env, 2); // setcdr
    v_12839 = (*qfn2(fn))(fn, v_12840, v_12839);
    env = stack[-3];
    goto v_12812;
v_12814:
    v_12839 = stack[0];
    v_12839 = qcdr(v_12839);
    stack[0] = v_12839;
    goto v_12812;
v_12812:
    goto v_12803;
v_12802:
    v_12839 = stack[-2];
v_12771:
    return onevalue(v_12839);
}



// Code for wedgek2

static LispObject CC_wedgek2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12997, v_12998, v_12999;
    LispObject fn;
    LispObject v_12768, v_12767, v_12766;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "wedgek2");
    va_start(aa, nargs);
    v_12766 = va_arg(aa, LispObject);
    v_12767 = va_arg(aa, LispObject);
    v_12768 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12768,v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12766,v_12767,v_12768);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_12768;
    stack[-3] = v_12767;
    stack[-4] = v_12766;
// end of prologue
v_12772:
    goto v_12785;
v_12781:
    v_12998 = stack[-4];
    goto v_12782;
v_12783:
    v_12997 = stack[-3];
    v_12997 = qcar(v_12997);
    goto v_12784;
v_12785:
    goto v_12781;
v_12782:
    goto v_12783;
v_12784:
    if (v_12998 == v_12997) goto v_12779;
    else goto v_12780;
v_12779:
    goto v_12794;
v_12790:
    v_12998 = stack[-4];
    goto v_12791;
v_12792:
    v_12997 = elt(env, 1); // wedge
    goto v_12793;
v_12794:
    goto v_12790;
v_12791:
    goto v_12792;
v_12793:
    v_12997 = Leqcar(nil, v_12998, v_12997);
    env = stack[-6];
    v_12997 = (v_12997 == nil ? lisp_true : nil);
    goto v_12778;
v_12780:
    v_12997 = nil;
    goto v_12778;
    v_12997 = nil;
v_12778:
    if (v_12997 == nil) goto v_12776;
    v_12997 = stack[-4];
    fn = elt(env, 2); // deg!*form
    v_12997 = (*qfn1(fn))(fn, v_12997);
    env = stack[-6];
    v_12998 = v_12997;
    v_12997 = v_12998;
    v_12997 = integerp(v_12997);
    if (v_12997 == nil) goto v_12810;
    else goto v_12811;
v_12810:
    v_12997 = nil;
    goto v_12809;
v_12811:
    v_12997 = v_12998;
    v_12997 = Loddp(nil, v_12997);
    env = stack[-6];
    goto v_12809;
    v_12997 = nil;
v_12809:
    if (v_12997 == nil) goto v_12804;
    v_12997 = nil;
    goto v_12771;
v_12804:
    goto v_12827;
v_12823:
    goto v_12834;
v_12830:
    v_12998 = stack[-4];
    goto v_12831;
v_12832:
    v_12997 = stack[-3];
    goto v_12833;
v_12834:
    goto v_12830;
v_12831:
    goto v_12832;
v_12833:
    v_12997 = cons(v_12998, v_12997);
    env = stack[-6];
    fn = elt(env, 3); // wedgef
    stack[0] = (*qfn1(fn))(fn, v_12997);
    env = stack[-6];
    goto v_12824;
v_12825:
    v_12997 = stack[-2];
    fn = elt(env, 4); // mksgnsq
    v_12997 = (*qfn1(fn))(fn, v_12997);
    env = stack[-6];
    goto v_12826;
v_12827:
    goto v_12823;
v_12824:
    goto v_12825;
v_12826:
    {
        LispObject v_13006 = stack[0];
        fn = elt(env, 5); // multpfsq
        return (*qfn2(fn))(fn, v_13006, v_12997);
    }
    goto v_12774;
v_12776:
    goto v_12846;
v_12842:
    v_12997 = stack[-3];
    v_12998 = qcar(v_12997);
    goto v_12843;
v_12844:
    v_12997 = elt(env, 1); // wedge
    goto v_12845;
v_12846:
    goto v_12842;
v_12843:
    goto v_12844;
v_12845:
    if (!consp(v_12998)) goto v_12840;
    v_12998 = qcar(v_12998);
    if (v_12998 == v_12997) goto v_12839;
    else goto v_12840;
v_12839:
    v_12997 = stack[-3];
    v_12997 = qcar(v_12997);
    v_12997 = qcdr(v_12997);
    stack[-3] = v_12997;
    goto v_12772;
v_12840:
    goto v_12860;
v_12856:
    v_12998 = stack[-4];
    goto v_12857;
v_12858:
    v_12997 = elt(env, 1); // wedge
    goto v_12859;
v_12860:
    goto v_12856;
v_12857:
    goto v_12858;
v_12859:
    if (!consp(v_12998)) goto v_12854;
    v_12998 = qcar(v_12998);
    if (v_12998 == v_12997) goto v_12853;
    else goto v_12854;
v_12853:
    goto v_12868;
v_12864:
    goto v_12874;
v_12870:
    v_12997 = stack[-4];
    v_12998 = qcdr(v_12997);
    goto v_12871;
v_12872:
    v_12997 = stack[-3];
    goto v_12873;
v_12874:
    goto v_12870;
v_12871:
    goto v_12872;
v_12873:
    fn = elt(env, 6); // wedgewedge
    stack[0] = (*qfn2(fn))(fn, v_12998, v_12997);
    env = stack[-6];
    goto v_12865;
v_12866:
    v_12997 = stack[-2];
    fn = elt(env, 4); // mksgnsq
    v_12997 = (*qfn1(fn))(fn, v_12997);
    env = stack[-6];
    goto v_12867;
v_12868:
    goto v_12864;
v_12865:
    goto v_12866;
v_12867:
    {
        LispObject v_13007 = stack[0];
        fn = elt(env, 5); // multpfsq
        return (*qfn2(fn))(fn, v_13007, v_12997);
    }
v_12854:
    goto v_12887;
v_12883:
    v_12998 = stack[-4];
    goto v_12884;
v_12885:
    v_12997 = stack[-3];
    v_12997 = qcar(v_12997);
    goto v_12886;
v_12887:
    goto v_12883;
v_12884:
    goto v_12885;
v_12886:
    fn = elt(env, 7); // worderp
    v_12997 = (*qfn2(fn))(fn, v_12998, v_12997);
    env = stack[-6];
    if (v_12997 == nil) goto v_12881;
    goto v_12896;
v_12892:
    goto v_12903;
v_12899:
    v_12998 = stack[-4];
    goto v_12900;
v_12901:
    v_12997 = stack[-3];
    goto v_12902;
v_12903:
    goto v_12899;
v_12900:
    goto v_12901;
v_12902:
    v_12997 = cons(v_12998, v_12997);
    env = stack[-6];
    fn = elt(env, 3); // wedgef
    stack[0] = (*qfn1(fn))(fn, v_12997);
    env = stack[-6];
    goto v_12893;
v_12894:
    v_12997 = stack[-2];
    fn = elt(env, 4); // mksgnsq
    v_12997 = (*qfn1(fn))(fn, v_12997);
    env = stack[-6];
    goto v_12895;
v_12896:
    goto v_12892;
v_12893:
    goto v_12894;
v_12895:
    {
        LispObject v_13008 = stack[0];
        fn = elt(env, 5); // multpfsq
        return (*qfn2(fn))(fn, v_13008, v_12997);
    }
v_12881:
    v_12997 = stack[-3];
    v_12997 = qcdr(v_12997);
    if (v_12997 == nil) goto v_12909;
    goto v_12917;
v_12913:
    goto v_12926;
v_12920:
    v_12997 = stack[-3];
    v_12999 = qcar(v_12997);
    goto v_12921;
v_12922:
    v_12998 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12923;
v_12924:
    v_12997 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12925;
v_12926:
    goto v_12920;
v_12921:
    goto v_12922;
v_12923:
    goto v_12924;
v_12925:
    v_12997 = list2star(v_12999, v_12998, v_12997);
    env = stack[-6];
    stack[-5] = ncons(v_12997);
    env = stack[-6];
    goto v_12914;
v_12915:
    goto v_12938;
v_12932:
    stack[-1] = stack[-4];
    goto v_12933;
v_12934:
    v_12997 = stack[-3];
    stack[0] = qcdr(v_12997);
    goto v_12935;
v_12936:
    goto v_12947;
v_12943:
    goto v_12944;
v_12945:
    goto v_12954;
v_12950:
    v_12997 = stack[-4];
    fn = elt(env, 2); // deg!*form
    stack[-4] = (*qfn1(fn))(fn, v_12997);
    env = stack[-6];
    goto v_12951;
v_12952:
    v_12997 = stack[-3];
    v_12997 = qcar(v_12997);
    fn = elt(env, 2); // deg!*form
    v_12997 = (*qfn1(fn))(fn, v_12997);
    env = stack[-6];
    goto v_12953;
v_12954:
    goto v_12950;
v_12951:
    goto v_12952;
v_12953:
    fn = elt(env, 8); // multf
    v_12997 = (*qfn2(fn))(fn, stack[-4], v_12997);
    env = stack[-6];
    goto v_12946;
v_12947:
    goto v_12943;
v_12944:
    goto v_12945;
v_12946:
    fn = elt(env, 9); // addf
    v_12997 = (*qfn2(fn))(fn, stack[-2], v_12997);
    env = stack[-6];
    goto v_12937;
v_12938:
    goto v_12932;
v_12933:
    goto v_12934;
v_12935:
    goto v_12936;
v_12937:
    v_12997 = CC_wedgek2(elt(env, 0), 3, stack[-1], stack[0], v_12997);
    env = stack[-6];
    goto v_12916;
v_12917:
    goto v_12913;
v_12914:
    goto v_12915;
v_12916:
    {
        LispObject v_13009 = stack[-5];
        fn = elt(env, 10); // wedgepf2
        return (*qfn2(fn))(fn, v_13009, v_12997);
    }
v_12909:
    goto v_12967;
v_12963:
    goto v_12974;
v_12970:
    v_12997 = stack[-3];
    v_12998 = qcar(v_12997);
    goto v_12971;
v_12972:
    v_12997 = stack[-4];
    goto v_12973;
v_12974:
    goto v_12970;
v_12971:
    goto v_12972;
v_12973:
    v_12997 = list2(v_12998, v_12997);
    env = stack[-6];
    fn = elt(env, 3); // wedgef
    stack[0] = (*qfn1(fn))(fn, v_12997);
    env = stack[-6];
    goto v_12964;
v_12965:
    goto v_12984;
v_12980:
    stack[-1] = stack[-2];
    goto v_12981;
v_12982:
    goto v_12991;
v_12987:
    v_12997 = stack[-4];
    fn = elt(env, 2); // deg!*form
    stack[-2] = (*qfn1(fn))(fn, v_12997);
    env = stack[-6];
    goto v_12988;
v_12989:
    v_12997 = stack[-3];
    v_12997 = qcar(v_12997);
    fn = elt(env, 2); // deg!*form
    v_12997 = (*qfn1(fn))(fn, v_12997);
    env = stack[-6];
    goto v_12990;
v_12991:
    goto v_12987;
v_12988:
    goto v_12989;
v_12990:
    fn = elt(env, 8); // multf
    v_12997 = (*qfn2(fn))(fn, stack[-2], v_12997);
    env = stack[-6];
    goto v_12983;
v_12984:
    goto v_12980;
v_12981:
    goto v_12982;
v_12983:
    fn = elt(env, 9); // addf
    v_12997 = (*qfn2(fn))(fn, stack[-1], v_12997);
    env = stack[-6];
    fn = elt(env, 4); // mksgnsq
    v_12997 = (*qfn1(fn))(fn, v_12997);
    env = stack[-6];
    goto v_12966;
v_12967:
    goto v_12963;
v_12964:
    goto v_12965;
v_12966:
    {
        LispObject v_13010 = stack[0];
        fn = elt(env, 5); // multpfsq
        return (*qfn2(fn))(fn, v_13010, v_12997);
    }
v_12774:
    v_12997 = nil;
v_12771:
    return onevalue(v_12997);
}



// Code for inttovec1

static LispObject CC_inttovec1(LispObject env,
                         LispObject v_12766, LispObject v_12767)
{
    env = qenv(env);
    LispObject v_12821, v_12822;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12767,v_12766);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12766,v_12767);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12767;
    stack[-1] = v_12766;
// end of prologue
    goto v_12777;
v_12773:
    v_12822 = stack[-1];
    goto v_12774;
v_12775:
    v_12821 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12776;
v_12777:
    goto v_12773;
v_12774:
    goto v_12775;
v_12776:
    if (v_12822 == v_12821) goto v_12771;
    else goto v_12772;
v_12771:
    v_12821 = stack[0];
    v_12821 = qcar(v_12821);
    return ncons(v_12821);
v_12772:
    goto v_12790;
v_12786:
    v_12821 = stack[-1];
    v_12822 = sub1(v_12821);
    env = stack[-3];
    goto v_12787;
v_12788:
    v_12821 = stack[0];
    v_12821 = qcdr(v_12821);
    goto v_12789;
v_12790:
    goto v_12786;
v_12787:
    goto v_12788;
v_12789:
    fn = elt(env, 1); // inttovec!-solve
    v_12821 = (*qfn2(fn))(fn, v_12822, v_12821);
    env = stack[-3];
    stack[-2] = v_12821;
    goto v_12801;
v_12797:
    goto v_12807;
v_12803:
    v_12821 = stack[0];
    v_12822 = qcar(v_12821);
    goto v_12804;
v_12805:
    v_12821 = stack[-2];
    v_12821 = qcar(v_12821);
    goto v_12806;
v_12807:
    goto v_12803;
v_12804:
    goto v_12805;
v_12806:
    stack[0] = difference2(v_12822, v_12821);
    env = stack[-3];
    goto v_12798;
v_12799:
    goto v_12817;
v_12813:
    v_12821 = stack[-1];
    v_12822 = sub1(v_12821);
    env = stack[-3];
    goto v_12814;
v_12815:
    v_12821 = stack[-2];
    goto v_12816;
v_12817:
    goto v_12813;
v_12814:
    goto v_12815;
v_12816:
    v_12821 = CC_inttovec1(elt(env, 0), v_12822, v_12821);
    goto v_12800;
v_12801:
    goto v_12797;
v_12798:
    goto v_12799;
v_12800:
    {
        LispObject v_12826 = stack[0];
        return cons(v_12826, v_12821);
    }
    v_12821 = nil;
    return onevalue(v_12821);
}



// Code for mkfortterpri

static LispObject CC_mkfortterpri(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12769;
    argcheck(nargs, 0, "mkfortterpri");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_12769 = elt(env, 1); // fortterpri
    return ncons(v_12769);
}



setup_type const u23_setup[] =
{
    {"mv-pow-mv-+",             TOO_FEW_2,      CC_mvKpowKmvKL,WRONG_NO_2},
    {"tensorp",                 CC_tensorp,     TOO_MANY_1,    WRONG_NO_1},
    {"lalr_precalculate_first_sets",WRONG_NO_NA,WRONG_NO_NB,   (n_args *)CC_lalr_precalculate_first_sets},
    {"aex_neg",                 CC_aex_neg,     TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_surep",              TOO_FEW_2,      CC_ofsf_surep, WRONG_NO_2},
    {"simpexpt",                CC_simpexpt,    TOO_MANY_1,    WRONG_NO_1},
    {"qqe_arg-check",           CC_qqe_argKcheck,TOO_MANY_1,   WRONG_NO_1},
    {"reform-minus",            TOO_FEW_2,      CC_reformKminus,WRONG_NO_2},
    {"gfdot",                   TOO_FEW_2,      CC_gfdot,      WRONG_NO_2},
    {"rdcos*",                  CC_rdcosH,      TOO_MANY_1,    WRONG_NO_1},
    {"begin11",                 CC_begin11,     TOO_MANY_1,    WRONG_NO_1},
    {"mv-domainlist-+",         TOO_FEW_2,      CC_mvKdomainlistKL,WRONG_NO_2},
    {"prepd1",                  CC_prepd1,      TOO_MANY_1,    WRONG_NO_1},
    {"moid_member",             TOO_FEW_2,      CC_moid_member,WRONG_NO_2},
    {"arglist_member",          TOO_FEW_2,      CC_arglist_member,WRONG_NO_2},
    {"gcref_mkgraph",           CC_gcref_mkgraph,TOO_MANY_1,   WRONG_NO_1},
    {"revalx",                  CC_revalx,      TOO_MANY_1,    WRONG_NO_1},
    {"getsetvars",              CC_getsetvars,  TOO_MANY_1,    WRONG_NO_1},
    {"evdif",                   TOO_FEW_2,      CC_evdif,      WRONG_NO_2},
    {"xdegreecheck",            CC_xdegreecheck,TOO_MANY_1,    WRONG_NO_1},
    {"physopsm*",               CC_physopsmH,   TOO_MANY_1,    WRONG_NO_1},
    {"repartf",                 CC_repartf,     TOO_MANY_1,    WRONG_NO_1},
    {"symbvarlst",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_symbvarlst},
    {"fs:times",                TOO_FEW_2,      CC_fsTtimes,   WRONG_NO_2},
    {"red=cancelsimp",          TOO_FEW_2,      CC_redMcancelsimp,WRONG_NO_2},
    {"ad_numsort",              CC_ad_numsort,  TOO_MANY_1,    WRONG_NO_1},
    {"lambda_ygm6np4pcqv31",    TOO_FEW_2,      CC_lambda_ygm6np4pcqv31,WRONG_NO_2},
    {"gfk",                     WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gfk},
    {"yypeek",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_yypeek},
    {"collect_cdrs",            CC_collect_cdrs,TOO_MANY_1,    WRONG_NO_1},
    {"setqget",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setqget},
    {"ofsf_subf",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_subf},
    {"reln",                    TOO_FEW_2,      CC_reln,       WRONG_NO_2},
    {"fortexp",                 CC_fortexp,     TOO_MANY_1,    WRONG_NO_1},
    {"trwrite",                 CC_trwrite,     TOO_MANY_1,    WRONG_NO_1},
    {"assert_uninstall1",       CC_assert_uninstall1,TOO_MANY_1,WRONG_NO_1},
    {"setelv",                  TOO_FEW_2,      CC_setelv,     WRONG_NO_2},
    {"ratn",                    CC_ratn,        TOO_MANY_1,    WRONG_NO_1},
    {"resimpf",                 CC_resimpf,     TOO_MANY_1,    WRONG_NO_1},
    {"get*elements",            CC_getHelements,TOO_MANY_1,    WRONG_NO_1},
    {"talp_subt",               TOO_FEW_2,      CC_talp_subt,  WRONG_NO_2},
    {"vsl_boundtype",           TOO_FEW_2,      CC_vsl_boundtype,WRONG_NO_2},
    {"**a2s",                   TOO_FEW_2,      CC_HHa2s,      WRONG_NO_2},
    {"makeset",                 CC_makeset,     TOO_MANY_1,    WRONG_NO_1},
    {"dm-minus",                CC_dmKminus,    TOO_MANY_1,    WRONG_NO_1},
    {"evgradlexcomp",           TOO_FEW_2,      CC_evgradlexcomp,WRONG_NO_2},
    {"bytelist2id",             CC_bytelist2id, TOO_MANY_1,    WRONG_NO_1},
    {"collectphystype",         CC_collectphystype,TOO_MANY_1, WRONG_NO_1},
    {"replace1_parents",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_replace1_parents},
    {"one-entry-listp",         TOO_FEW_2,      CC_oneKentryKlistp,WRONG_NO_2},
    {"setel1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setel1},
    {"mo_equal?",               TOO_FEW_2,      CC_mo_equalW,  WRONG_NO_2},
    {"splitlist:",              TOO_FEW_2,      CC_splitlistT, WRONG_NO_2},
    {"innprodkp",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_innprodkp},
    {"drop_rl_with",            TOO_FEW_2,      CC_drop_rl_with,WRONG_NO_2},
    {"ordered-gcd-mod-p",       TOO_FEW_2,      CC_orderedKgcdKmodKp,WRONG_NO_2},
    {"ctx_idl",                 CC_ctx_idl,     TOO_MANY_1,    WRONG_NO_1},
    {"mkpartitions1",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mkpartitions1},
    {"rl_atnum",                CC_rl_atnum,    TOO_MANY_1,    WRONG_NO_1},
    {"squared+matrix+p",        CC_squaredLmatrixLp,TOO_MANY_1,WRONG_NO_1},
    {"rl_pnf",                  CC_rl_pnf,      TOO_MANY_1,    WRONG_NO_1},
    {"pasf_sacat",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pasf_sacat},
    {"ev_lexcomp",              TOO_FEW_2,      CC_ev_lexcomp, WRONG_NO_2},
    {"subs4q",                  CC_subs4q,      TOO_MANY_1,    WRONG_NO_1},
    {"groedeletip",             TOO_FEW_2,      CC_groedeletip,WRONG_NO_2},
    {"wedgek2",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_wedgek2},
    {"inttovec1",               TOO_FEW_2,      CC_inttovec1,  WRONG_NO_2},
    {"mkfortterpri",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mkfortterpri},
    {NULL, (one_args *)"u23", (two_args *)"106493 3382470 4053272", 0}
};

// end of generated code
