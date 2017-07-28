
// $destdir/u27.c        Machine generated C code

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



// Code for string!-of!-list

static LispObject CC_stringKofKlist(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15110, v_15111;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_15111 = v_15034;
// end of prologue
    v_15110 = v_15111;
    if (v_15110 == nil) goto v_15038;
    else goto v_15039;
v_15038:
    v_15110 = elt(env, 1); // ""
    goto v_15037;
v_15039:
    v_15110 = v_15111;
    stack[-4] = v_15110;
v_15050:
    v_15110 = stack[-4];
    if (v_15110 == nil) goto v_15055;
    else goto v_15056;
v_15055:
    v_15110 = nil;
    goto v_15049;
v_15056:
    v_15110 = stack[-4];
    v_15110 = qcar(v_15110);
    goto v_15067;
v_15063:
    stack[0] = elt(env, 2); // !;
    goto v_15064;
v_15065:
    v_15110 = Lexplode(nil, v_15110);
    env = stack[-5];
    goto v_15066;
v_15067:
    goto v_15063;
v_15064:
    goto v_15065;
v_15066:
    v_15110 = cons(stack[0], v_15110);
    env = stack[-5];
    stack[-3] = v_15110;
    v_15110 = stack[-3];
    fn = elt(env, 3); // lastpair
    v_15110 = (*qfn1(fn))(fn, v_15110);
    env = stack[-5];
    stack[-2] = v_15110;
    v_15110 = stack[-4];
    v_15110 = qcdr(v_15110);
    stack[-4] = v_15110;
    v_15110 = stack[-2];
    if (!consp(v_15110)) goto v_15077;
    else goto v_15078;
v_15077:
    goto v_15050;
v_15078:
v_15051:
    v_15110 = stack[-4];
    if (v_15110 == nil) goto v_15082;
    else goto v_15083;
v_15082:
    v_15110 = stack[-3];
    goto v_15049;
v_15083:
    goto v_15091;
v_15087:
    stack[-1] = stack[-2];
    goto v_15088;
v_15089:
    v_15110 = stack[-4];
    v_15110 = qcar(v_15110);
    goto v_15101;
v_15097:
    stack[0] = elt(env, 2); // !;
    goto v_15098;
v_15099:
    v_15110 = Lexplode(nil, v_15110);
    env = stack[-5];
    goto v_15100;
v_15101:
    goto v_15097;
v_15098:
    goto v_15099;
v_15100:
    v_15110 = cons(stack[0], v_15110);
    env = stack[-5];
    goto v_15090;
v_15091:
    goto v_15087;
v_15088:
    goto v_15089;
v_15090:
    v_15110 = Lrplacd(nil, stack[-1], v_15110);
    env = stack[-5];
    v_15110 = stack[-2];
    fn = elt(env, 3); // lastpair
    v_15110 = (*qfn1(fn))(fn, v_15110);
    env = stack[-5];
    stack[-2] = v_15110;
    v_15110 = stack[-4];
    v_15110 = qcdr(v_15110);
    stack[-4] = v_15110;
    goto v_15051;
v_15049:
    v_15110 = qcdr(v_15110);
    {
        fn = elt(env, 4); // list2string
        return (*qfn1(fn))(fn, v_15110);
    }
    v_15110 = nil;
v_15037:
    return onevalue(v_15110);
}



// Code for yylex

static LispObject CC_yylex(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15226, v_15227, v_15228;
    LispObject fn;
    argcheck(nargs, 0, "yylex");
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
    stack[-2] = nil;
    fn = elt(env, 14); // lex_basic_token
    v_15226 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[0] = v_15226;
v_15043:
    v_15226 = stack[-2];
    if (v_15226 == nil) goto v_15050;
    else goto v_15051;
v_15050:
    goto v_15061;
v_15057:
    v_15227 = stack[0];
    goto v_15058;
v_15059:
    v_15226 = qvalue(elt(env, 1)); // lex_symbol_code
    goto v_15060;
v_15061:
    goto v_15057;
v_15058:
    goto v_15059;
v_15060:
    if (equal(v_15227, v_15226)) goto v_15055;
    else goto v_15056;
v_15055:
    v_15226 = qvalue(elt(env, 2)); // lex_escaped
    if (v_15226 == nil) goto v_15066;
    else goto v_15067;
v_15066:
    goto v_15075;
v_15071:
    v_15227 = qvalue(elt(env, 3)); // lexer_style!*
    goto v_15072;
v_15073:
    v_15226 = (LispObject)1024+TAG_FIXNUM; // 64
    goto v_15074;
v_15075:
    goto v_15071;
v_15072:
    goto v_15073;
v_15074:
    fn = elt(env, 15); // land
    v_15226 = (*qfn2(fn))(fn, v_15227, v_15226);
    env = stack[-4];
    v_15226 = (LispObject)zerop(v_15226);
    v_15226 = v_15226 ? lisp_true : nil;
    env = stack[-4];
    v_15226 = (v_15226 == nil ? lisp_true : nil);
    goto v_15065;
v_15067:
    v_15226 = nil;
    goto v_15065;
    v_15226 = nil;
v_15065:
    goto v_15054;
v_15056:
    v_15226 = nil;
    goto v_15054;
    v_15226 = nil;
v_15054:
    goto v_15049;
v_15051:
    v_15226 = nil;
    goto v_15049;
    v_15226 = nil;
v_15049:
    if (v_15226 == nil) goto v_15046;
    else goto v_15047;
v_15046:
    goto v_15042;
v_15047:
    fn = elt(env, 16); // lex_process_directive
    v_15226 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    if (v_15226 == nil) goto v_15092;
    fn = elt(env, 14); // lex_basic_token
    v_15226 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[0] = v_15226;
    goto v_15090;
v_15092:
    goto v_15101;
v_15097:
    v_15227 = qvalue(elt(env, 4)); // yylval
    goto v_15098;
v_15099:
    v_15226 = elt(env, 5); // !#define
    goto v_15100;
v_15101:
    goto v_15097;
v_15098:
    goto v_15099;
v_15100:
    if (v_15227 == v_15226) goto v_15095;
    else goto v_15096;
v_15095:
    fn = elt(env, 17); // read_s_expression
    v_15226 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    v_15226 = qvalue(elt(env, 4)); // yylval
    stack[0] = v_15226;
    fn = elt(env, 17); // read_s_expression
    v_15226 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    v_15226 = qvalue(elt(env, 4)); // yylval
    stack[-3] = v_15226;
    v_15226 = stack[0];
    if (symbolp(v_15226)) goto v_15112;
    else goto v_15111;
v_15112:
    v_15226 = stack[-3];
    if (symbolp(v_15226)) goto v_15114;
    v_15226 = stack[-3];
    if (is_number(v_15226)) goto v_15114;
    v_15226 = stack[-3];
    v_15226 = Lstringp(nil, v_15226);
    env = stack[-4];
    if (v_15226 == nil) goto v_15120;
    else goto v_15114;
v_15120:
    goto v_15111;
v_15114:
    v_15226 = Lposn(nil, 0);
    env = stack[-4];
    v_15226 = (LispObject)zerop(v_15226);
    v_15226 = v_15226 ? lisp_true : nil;
    env = stack[-4];
    if (v_15226 == nil) goto v_15125;
    else goto v_15126;
v_15125:
    v_15226 = Lterpri(nil, 0);
    env = stack[-4];
    goto v_15124;
v_15126:
v_15124:
    v_15226 = elt(env, 6); // "+++ "
    v_15226 = Lprinc(nil, v_15226);
    env = stack[-4];
    v_15226 = stack[0];
    v_15226 = Lprin(nil, v_15226);
    env = stack[-4];
    v_15226 = elt(env, 7); // " => "
    v_15226 = Lprinc(nil, v_15226);
    env = stack[-4];
    v_15226 = stack[-3];
    v_15226 = Lprint(nil, v_15226);
    env = stack[-4];
    goto v_15145;
v_15139:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15140;
v_15141:
    stack[0] = elt(env, 5); // !#define
    goto v_15142;
v_15143:
    v_15226 = stack[-3];
    v_15226 = ncons(v_15226);
    env = stack[-4];
    goto v_15144;
v_15145:
    goto v_15139;
v_15140:
    goto v_15141;
v_15142:
    goto v_15143;
v_15144:
    v_15226 = Lputprop(nil, 3, stack[-1], stack[0], v_15226);
    env = stack[-4];
    goto v_15109;
v_15111:
v_15109:
    fn = elt(env, 14); // lex_basic_token
    v_15226 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[0] = v_15226;
    goto v_15090;
v_15096:
    goto v_15157;
v_15153:
    v_15227 = qvalue(elt(env, 4)); // yylval
    goto v_15154;
v_15155:
    v_15226 = elt(env, 8); // !#eval
    goto v_15156;
v_15157:
    goto v_15153;
v_15154:
    goto v_15155;
v_15156:
    if (v_15227 == v_15226) goto v_15151;
    else goto v_15152;
v_15151:
    fn = elt(env, 17); // read_s_expression
    v_15226 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_15168;
v_15162:
    v_15228 = qvalue(elt(env, 4)); // yylval
    goto v_15163;
v_15164:
    v_15227 = nil;
    goto v_15165;
v_15166:
    v_15226 = nil;
    goto v_15167;
v_15168:
    goto v_15162;
v_15163:
    goto v_15164;
v_15165:
    goto v_15166;
v_15167:
    fn = elt(env, 18); // errorset
    v_15226 = (*qfnn(fn))(fn, 3, v_15228, v_15227, v_15226);
    env = stack[-4];
    fn = elt(env, 14); // lex_basic_token
    v_15226 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[0] = v_15226;
    goto v_15090;
v_15152:
    goto v_15180;
v_15176:
    v_15227 = qvalue(elt(env, 4)); // yylval
    goto v_15177;
v_15178:
    v_15226 = elt(env, 5); // !#define
    goto v_15179;
v_15180:
    goto v_15176;
v_15177:
    goto v_15178;
v_15179:
    v_15226 = get(v_15227, v_15226);
    env = stack[-4];
    stack[-3] = v_15226;
    if (v_15226 == nil) goto v_15174;
    v_15226 = stack[-3];
    v_15226 = qcar(v_15226);
    qvalue(elt(env, 4)) = v_15226; // yylval
    v_15226 = stack[-3];
    if (is_number(v_15226)) goto v_15187;
    else goto v_15188;
v_15187:
    v_15226 = qvalue(elt(env, 9)); // lex_number_code
    stack[0] = v_15226;
    goto v_15186;
v_15188:
    v_15226 = stack[-3];
    v_15226 = Lstringp(nil, v_15226);
    env = stack[-4];
    if (v_15226 == nil) goto v_15192;
    v_15226 = qvalue(elt(env, 10)); // lex_string_code
    stack[0] = v_15226;
    goto v_15186;
v_15192:
v_15186:
    v_15226 = lisp_true;
    stack[-2] = v_15226;
    goto v_15090;
v_15174:
    v_15226 = lisp_true;
    stack[-2] = v_15226;
    goto v_15090;
v_15090:
    goto v_15043;
v_15042:
    v_15226 = qvalue(elt(env, 11)); // !*tracelex
    if (v_15226 == nil) goto v_15203;
    goto v_15213;
v_15209:
    v_15227 = Lposn(nil, 0);
    env = stack[-4];
    goto v_15210;
v_15211:
    v_15226 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15212;
v_15213:
    goto v_15209;
v_15210:
    goto v_15211;
v_15212:
    if (v_15227 == v_15226) goto v_15208;
    v_15226 = Lterpri(nil, 0);
    env = stack[-4];
    goto v_15206;
v_15208:
v_15206:
    v_15226 = elt(env, 12); // "yylex = "
    v_15226 = Lprinc(nil, v_15226);
    env = stack[-4];
    v_15226 = qvalue(elt(env, 4)); // yylval
    v_15226 = Lprin(nil, v_15226);
    env = stack[-4];
    v_15226 = elt(env, 13); // " type "
    v_15226 = Lprinc(nil, v_15226);
    env = stack[-4];
    v_15226 = stack[0];
    v_15226 = Lprint(nil, v_15226);
    goto v_15201;
v_15203:
v_15201:
    v_15226 = stack[0];
    return onevalue(v_15226);
}



// Code for gcref_remprops

static LispObject CC_gcref_remprops(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15101, v_15102, v_15103;
    LispObject fn;
    argcheck(nargs, 0, "gcref_remprops");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
    stack_popper stack_popper_var(1);
// end of prologue
    goto v_15040;
v_15036:
    v_15102 = qvalue(elt(env, 1)); // seen!*
    goto v_15037;
v_15038:
    v_15101 = elt(env, 2); // (gall calls globs calledby alsois sameas)
    goto v_15039;
v_15040:
    goto v_15036;
v_15037:
    goto v_15038;
v_15039:
    fn = elt(env, 12); // rempropss
    v_15101 = (*qfn2(fn))(fn, v_15102, v_15101);
    env = stack[0];
    goto v_15048;
v_15044:
    v_15102 = qvalue(elt(env, 1)); // seen!*
    goto v_15045;
v_15046:
    v_15101 = elt(env, 3); // (seen cinthis defd)
    goto v_15047;
v_15048:
    goto v_15044;
v_15045:
    goto v_15046;
v_15047:
    fn = elt(env, 13); // remflagss
    v_15101 = (*qfn2(fn))(fn, v_15102, v_15101);
    env = stack[0];
    goto v_15056;
v_15052:
    v_15102 = qvalue(elt(env, 4)); // gcref_exportl!*
    goto v_15053;
v_15054:
    v_15101 = elt(env, 5); // (exported)
    goto v_15055;
v_15056:
    goto v_15052;
v_15053:
    goto v_15054;
v_15055:
    fn = elt(env, 13); // remflagss
    v_15101 = (*qfn2(fn))(fn, v_15102, v_15101);
    env = stack[0];
    goto v_15064;
v_15060:
    v_15102 = qvalue(elt(env, 6)); // gseen!*
    goto v_15061;
v_15062:
    v_15101 = elt(env, 7); // (usedby usedunby boundby setby)
    goto v_15063;
v_15064:
    goto v_15060;
v_15061:
    goto v_15062;
v_15063:
    fn = elt(env, 12); // rempropss
    v_15101 = (*qfn2(fn))(fn, v_15102, v_15101);
    env = stack[0];
    goto v_15072;
v_15068:
    v_15102 = qvalue(elt(env, 6)); // gseen!*
    goto v_15069;
v_15070:
    v_15101 = elt(env, 8); // (dclglb gseen glb2rf glb2bd glb2st)
    goto v_15071;
v_15072:
    goto v_15068;
v_15069:
    goto v_15070;
v_15071:
    fn = elt(env, 13); // remflagss
    v_15101 = (*qfn2(fn))(fn, v_15102, v_15101);
    env = stack[0];
    v_15101 = qvalue(elt(env, 9)); // tseen!*
    v_15103 = v_15101;
v_15078:
    v_15101 = v_15103;
    if (v_15101 == nil) goto v_15082;
    else goto v_15083;
v_15082:
    goto v_15077;
v_15083:
    v_15101 = v_15103;
    v_15101 = qcar(v_15101);
    goto v_15094;
v_15090:
    v_15102 = qcar(v_15101);
    goto v_15091;
v_15092:
    v_15101 = elt(env, 10); // funs
    goto v_15093;
v_15094:
    goto v_15090;
v_15091:
    goto v_15092;
v_15093:
    v_15101 = Lremprop(nil, v_15102, v_15101);
    env = stack[0];
    v_15101 = v_15103;
    v_15101 = qcdr(v_15101);
    v_15103 = v_15101;
    goto v_15078;
v_15077:
    v_15101 = nil;
    qvalue(elt(env, 9)) = v_15101; // tseen!*
    qvalue(elt(env, 1)) = v_15101; // seen!*
    qvalue(elt(env, 6)) = v_15101; // gseen!*
    qvalue(elt(env, 11)) = v_15101; // haveargs!*
    return onevalue(v_15101);
}



// Code for ofsf_smmkatl

static LispObject CC_ofsf_smmkatl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15084, v_15085, v_15086, v_15087;
    LispObject fn;
    LispObject v_15037, v_15036, v_15035, v_15034;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ofsf_smmkatl");
    va_start(aa, nargs);
    v_15034 = va_arg(aa, LispObject);
    v_15035 = va_arg(aa, LispObject);
    v_15036 = va_arg(aa, LispObject);
    v_15037 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_15037,v_15036,v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_15034,v_15035,v_15036,v_15037);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_15084 = v_15037;
    stack[0] = v_15036;
    v_15085 = v_15035;
    v_15087 = v_15034;
// end of prologue
    v_15086 = qvalue(elt(env, 1)); // !*rlsippatl
    if (v_15086 == nil) goto v_15042;
    goto v_15051;
v_15045:
    stack[-1] = v_15087;
    goto v_15046;
v_15047:
    goto v_15062;
v_15054:
    goto v_15055;
v_15056:
    v_15086 = v_15085;
    goto v_15057;
v_15058:
    v_15085 = stack[0];
    goto v_15059;
v_15060:
    goto v_15061;
v_15062:
    goto v_15054;
v_15055:
    goto v_15056;
v_15057:
    goto v_15058;
v_15059:
    goto v_15060;
v_15061:
    fn = elt(env, 2); // ofsf_smmkatl1
    v_15085 = (*qfnn(fn))(fn, 4, v_15087, v_15086, v_15085, v_15084);
    env = stack[-2];
    goto v_15048;
v_15049:
    v_15084 = stack[0];
    goto v_15050;
v_15051:
    goto v_15045;
v_15046:
    goto v_15047;
v_15048:
    goto v_15049;
v_15050:
    {
        LispObject v_15090 = stack[-1];
        fn = elt(env, 3); // ofsf_sippatl
        return (*qfnn(fn))(fn, 3, v_15090, v_15085, v_15084);
    }
v_15042:
    goto v_15079;
v_15071:
    goto v_15072;
v_15073:
    v_15086 = v_15085;
    goto v_15074;
v_15075:
    v_15085 = stack[0];
    goto v_15076;
v_15077:
    goto v_15078;
v_15079:
    goto v_15071;
v_15072:
    goto v_15073;
v_15074:
    goto v_15075;
v_15076:
    goto v_15077;
v_15078:
    {
        fn = elt(env, 2); // ofsf_smmkatl1
        return (*qfnn(fn))(fn, 4, v_15087, v_15086, v_15085, v_15084);
    }
    v_15084 = nil;
    return onevalue(v_15084);
}



// Code for talp_subat

static LispObject CC_talp_subat(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15065;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15034,v_15035);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_15035;
    stack[-2] = v_15034;
// end of prologue
    goto v_15044;
v_15038:
    v_15065 = stack[-1];
    fn = elt(env, 1); // talp_op
    stack[-3] = (*qfn1(fn))(fn, v_15065);
    env = stack[-4];
    goto v_15039;
v_15040:
    goto v_15052;
v_15048:
    stack[0] = stack[-2];
    goto v_15049;
v_15050:
    v_15065 = stack[-1];
    fn = elt(env, 2); // talp_arg2l
    v_15065 = (*qfn1(fn))(fn, v_15065);
    env = stack[-4];
    goto v_15051;
v_15052:
    goto v_15048;
v_15049:
    goto v_15050;
v_15051:
    fn = elt(env, 3); // talp_subt
    stack[0] = (*qfn2(fn))(fn, stack[0], v_15065);
    env = stack[-4];
    goto v_15041;
v_15042:
    goto v_15061;
v_15057:
    goto v_15058;
v_15059:
    v_15065 = stack[-1];
    fn = elt(env, 4); // talp_arg2r
    v_15065 = (*qfn1(fn))(fn, v_15065);
    env = stack[-4];
    goto v_15060;
v_15061:
    goto v_15057;
v_15058:
    goto v_15059;
v_15060:
    fn = elt(env, 3); // talp_subt
    v_15065 = (*qfn2(fn))(fn, stack[-2], v_15065);
    env = stack[-4];
    goto v_15043;
v_15044:
    goto v_15038;
v_15039:
    goto v_15040;
v_15041:
    goto v_15042;
v_15043:
    {
        LispObject v_15070 = stack[-3];
        LispObject v_15071 = stack[0];
        fn = elt(env, 5); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_15070, v_15071, v_15065);
    }
}



// Code for vsl_subatsq

static LispObject CC_vsl_subatsq(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15063, v_15064, v_15065, v_15066;
    LispObject fn;
    LispObject v_15036, v_15035, v_15034;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "vsl_subatsq");
    va_start(aa, nargs);
    v_15034 = va_arg(aa, LispObject);
    v_15035 = va_arg(aa, LispObject);
    v_15036 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15036,v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15034,v_15035,v_15036);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15064 = v_15036;
    v_15065 = v_15035;
    v_15066 = v_15034;
// end of prologue
    goto v_15045;
v_15039:
    v_15063 = v_15066;
    stack[0] = qcar(v_15063);
    goto v_15040;
v_15041:
    goto v_15055;
v_15049:
    v_15063 = v_15066;
    v_15063 = qcdr(v_15063);
    v_15063 = qcar(v_15063);
    goto v_15050;
v_15051:
    goto v_15052;
v_15053:
    goto v_15054;
v_15055:
    goto v_15049;
v_15050:
    goto v_15051;
v_15052:
    goto v_15053;
v_15054:
    fn = elt(env, 1); // ofsf_subf
    v_15063 = (*qfnn(fn))(fn, 3, v_15063, v_15065, v_15064);
    v_15064 = qcar(v_15063);
    goto v_15042;
v_15043:
    v_15063 = nil;
    goto v_15044;
v_15045:
    goto v_15039;
v_15040:
    goto v_15041;
v_15042:
    goto v_15043;
v_15044:
    {
        LispObject v_15068 = stack[0];
        return list3(v_15068, v_15064, v_15063);
    }
}



// Code for unaryir

static LispObject CC_unaryir(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15073, v_15074;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15034,v_15035);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15035;
    stack[-1] = v_15034;
// end of prologue
    goto v_15047;
v_15043:
    v_15074 = qvalue(elt(env, 1)); // atts
    goto v_15044;
v_15045:
    v_15073 = elt(env, 2); // name
    goto v_15046;
v_15047:
    goto v_15043;
v_15044:
    goto v_15045;
v_15046:
    fn = elt(env, 4); // find
    v_15073 = (*qfn2(fn))(fn, v_15074, v_15073);
    env = stack[-3];
    v_15073 = Lintern(nil, v_15073);
    env = stack[-3];
    stack[-2] = v_15073;
    goto v_15056;
v_15052:
    v_15074 = qvalue(elt(env, 1)); // atts
    goto v_15053;
v_15054:
    v_15073 = elt(env, 3); // cd
    goto v_15055;
v_15056:
    goto v_15052;
v_15053:
    goto v_15054;
v_15055:
    fn = elt(env, 4); // find
    v_15073 = (*qfn2(fn))(fn, v_15074, v_15073);
    env = stack[-3];
    v_15073 = Lintern(nil, v_15073);
    env = stack[-3];
    goto v_15067;
v_15063:
    v_15074 = v_15073;
    goto v_15064;
v_15065:
    v_15073 = stack[-1];
    goto v_15066;
v_15067:
    goto v_15063;
v_15064:
    goto v_15065;
v_15066:
    if (equal(v_15074, v_15073)) goto v_15062;
    v_15073 = stack[-2];
    {
        fn = elt(env, 5); // encodeir
        return (*qfn1(fn))(fn, v_15073);
    }
v_15062:
    v_15073 = stack[0];
    return onevalue(v_15073);
}



// Code for rootextractsq

static LispObject CC_rootextractsq(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15060, v_15061;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_15061 = v_15034;
// end of prologue
    v_15060 = v_15061;
    v_15060 = qcar(v_15060);
    if (v_15060 == nil) goto v_15038;
    else goto v_15039;
v_15038:
    v_15060 = v_15061;
    goto v_15037;
v_15039:
    v_15060 = v_15061;
    fn = elt(env, 1); // subs2q
    v_15060 = (*qfn1(fn))(fn, v_15060);
    env = stack[-2];
    stack[-1] = v_15060;
    goto v_15053;
v_15049:
    v_15060 = stack[-1];
    v_15060 = qcar(v_15060);
    fn = elt(env, 2); // rootextractf
    stack[0] = (*qfn1(fn))(fn, v_15060);
    env = stack[-2];
    goto v_15050;
v_15051:
    v_15060 = stack[-1];
    v_15060 = qcdr(v_15060);
    fn = elt(env, 2); // rootextractf
    v_15060 = (*qfn1(fn))(fn, v_15060);
    goto v_15052;
v_15053:
    goto v_15049;
v_15050:
    goto v_15051;
v_15052:
    {
        LispObject v_15064 = stack[0];
        return cons(v_15064, v_15060);
    }
    v_15060 = nil;
v_15037:
    return onevalue(v_15060);
}



// Code for can_be_proved

static LispObject CC_can_be_proved(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15062, v_15063;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15034,v_15035);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15035;
    stack[-1] = v_15034;
// end of prologue
v_15039:
    v_15062 = stack[-1];
    if (v_15062 == nil) goto v_15042;
    else goto v_15043;
v_15042:
    v_15062 = lisp_true;
    goto v_15038;
v_15043:
    goto v_15053;
v_15049:
    v_15062 = stack[-1];
    v_15063 = qcar(v_15062);
    goto v_15050;
v_15051:
    v_15062 = stack[0];
    goto v_15052;
v_15053:
    goto v_15049;
v_15050:
    goto v_15051;
v_15052:
    fn = elt(env, 1); // can_be_p
    v_15062 = (*qfn2(fn))(fn, v_15063, v_15062);
    env = stack[-2];
    if (v_15062 == nil) goto v_15047;
    v_15062 = stack[-1];
    v_15062 = qcdr(v_15062);
    stack[-1] = v_15062;
    goto v_15039;
v_15047:
    v_15062 = nil;
    goto v_15038;
    v_15062 = nil;
v_15038:
    return onevalue(v_15062);
}



// Code for extract_dummy_ids

static LispObject CC_extract_dummy_ids(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15073, v_15074, v_15075;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15034;
// end of prologue
    v_15075 = nil;
v_15039:
    v_15073 = stack[0];
    if (v_15073 == nil) goto v_15042;
    else goto v_15043;
v_15042:
    v_15073 = v_15075;
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_15073);
    }
v_15043:
    goto v_15053;
v_15049:
    v_15073 = stack[0];
    v_15074 = qcar(v_15073);
    goto v_15050;
v_15051:
    v_15073 = qvalue(elt(env, 1)); // dummy_id!*
    goto v_15052;
v_15053:
    goto v_15049;
v_15050:
    goto v_15051;
v_15052:
    v_15073 = Lmemq(nil, v_15074, v_15073);
    if (v_15073 == nil) goto v_15048;
    goto v_15063;
v_15059:
    v_15073 = stack[0];
    v_15073 = qcar(v_15073);
    goto v_15060;
v_15061:
    v_15074 = v_15075;
    goto v_15062;
v_15063:
    goto v_15059;
v_15060:
    goto v_15061;
v_15062:
    v_15073 = cons(v_15073, v_15074);
    env = stack[-1];
    v_15075 = v_15073;
    v_15073 = stack[0];
    v_15073 = qcdr(v_15073);
    stack[0] = v_15073;
    goto v_15039;
v_15048:
    v_15073 = stack[0];
    v_15073 = qcdr(v_15073);
    stack[0] = v_15073;
    goto v_15039;
    v_15073 = nil;
    return onevalue(v_15073);
}



// Code for evaluate!-mod!-p

static LispObject CC_evaluateKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15157, v_15158, v_15159, v_15160, v_15161;
    LispObject fn;
    LispObject v_15036, v_15035, v_15034;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "evaluate-mod-p");
    va_start(aa, nargs);
    v_15034 = va_arg(aa, LispObject);
    v_15035 = va_arg(aa, LispObject);
    v_15036 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15036,v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15034,v_15035,v_15036);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15036;
    stack[-1] = v_15035;
    stack[-2] = v_15034;
// end of prologue
v_15040:
    v_15157 = stack[-2];
    if (!consp(v_15157)) goto v_15047;
    else goto v_15048;
v_15047:
    v_15157 = lisp_true;
    goto v_15046;
v_15048:
    v_15157 = stack[-2];
    v_15157 = qcar(v_15157);
    v_15157 = (consp(v_15157) ? nil : lisp_true);
    goto v_15046;
    v_15157 = nil;
v_15046:
    if (v_15157 == nil) goto v_15044;
    v_15157 = stack[-2];
    goto v_15039;
v_15044:
    goto v_15063;
v_15059:
    v_15158 = stack[0];
    goto v_15060;
v_15061:
    v_15157 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15062;
v_15063:
    goto v_15059;
v_15060:
    goto v_15061;
v_15062:
    if (v_15158 == v_15157) goto v_15057;
    else goto v_15058;
v_15057:
    v_15157 = nil;
    stack[0] = v_15157;
    goto v_15040;
v_15058:
    v_15157 = stack[-1];
    if (v_15157 == nil) goto v_15067;
    else goto v_15068;
v_15067:
    v_15157 = elt(env, 1); // "Variable=NIL in evaluate-mod-p"
    {
        fn = elt(env, 2); // errorf
        return (*qfn1(fn))(fn, v_15157);
    }
v_15068:
    goto v_15078;
v_15074:
    v_15157 = stack[-2];
    v_15157 = qcar(v_15157);
    v_15157 = qcar(v_15157);
    v_15158 = qcar(v_15157);
    goto v_15075;
v_15076:
    v_15157 = stack[-1];
    goto v_15077;
v_15078:
    goto v_15074;
v_15075:
    goto v_15076;
v_15077:
    if (equal(v_15158, v_15157)) goto v_15072;
    else goto v_15073;
v_15072:
    goto v_15095;
v_15085:
    v_15157 = stack[-2];
    v_15157 = qcar(v_15157);
    v_15161 = qcdr(v_15157);
    goto v_15086;
v_15087:
    v_15157 = stack[-2];
    v_15157 = qcar(v_15157);
    v_15157 = qcar(v_15157);
    v_15160 = qcdr(v_15157);
    goto v_15088;
v_15089:
    v_15157 = stack[-2];
    v_15159 = qcdr(v_15157);
    goto v_15090;
v_15091:
    v_15158 = stack[0];
    goto v_15092;
v_15093:
    v_15157 = stack[-1];
    goto v_15094;
v_15095:
    goto v_15085;
v_15086:
    goto v_15087;
v_15088:
    goto v_15089;
v_15090:
    goto v_15091;
v_15092:
    goto v_15093;
v_15094:
    {
        fn = elt(env, 3); // horner!-rule!-mod!-p
        return (*qfnn(fn))(fn, 5, v_15161, v_15160, v_15159, v_15158, v_15157);
    }
v_15073:
    goto v_15116;
v_15110:
    v_15157 = stack[-2];
    v_15157 = qcar(v_15157);
    v_15159 = qcdr(v_15157);
    goto v_15111;
v_15112:
    v_15158 = stack[-1];
    goto v_15113;
v_15114:
    v_15157 = stack[0];
    goto v_15115;
v_15116:
    goto v_15110;
v_15111:
    goto v_15112;
v_15113:
    goto v_15114;
v_15115:
    stack[-3] = CC_evaluateKmodKp(elt(env, 0), 3, v_15159, v_15158, v_15157);
    env = stack[-4];
    goto v_15129;
v_15123:
    v_15157 = stack[-2];
    v_15159 = qcdr(v_15157);
    goto v_15124;
v_15125:
    v_15158 = stack[-1];
    goto v_15126;
v_15127:
    v_15157 = stack[0];
    goto v_15128;
v_15129:
    goto v_15123;
v_15124:
    goto v_15125;
v_15126:
    goto v_15127;
v_15128:
    v_15157 = CC_evaluateKmodKp(elt(env, 0), 3, v_15159, v_15158, v_15157);
    v_15158 = stack[-3];
    v_15159 = v_15158;
    if (v_15159 == nil) goto v_15138;
    else goto v_15139;
v_15138:
    goto v_15137;
v_15139:
    goto v_15151;
v_15145:
    v_15159 = stack[-2];
    v_15159 = qcar(v_15159);
    v_15159 = qcar(v_15159);
    goto v_15146;
v_15147:
    goto v_15148;
v_15149:
    goto v_15150;
v_15151:
    goto v_15145;
v_15146:
    goto v_15147;
v_15148:
    goto v_15149;
v_15150:
    return acons(v_15159, v_15158, v_15157);
    v_15157 = nil;
v_15137:
    goto v_15039;
    v_15157 = nil;
v_15039:
    return onevalue(v_15157);
}



// Code for hasarg

static LispObject CC_hasarg(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15093, v_15094, v_15095;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15034,v_15035);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15035;
    stack[-1] = v_15034;
// end of prologue
    goto v_15042;
v_15038:
    v_15094 = stack[-1];
    goto v_15039;
v_15040:
    v_15093 = qvalue(elt(env, 1)); // haveargs!*
    goto v_15041;
v_15042:
    goto v_15038;
v_15039:
    goto v_15040;
v_15041:
    v_15093 = cons(v_15094, v_15093);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_15093; // haveargs!*
    goto v_15054;
v_15050:
    v_15094 = stack[0];
    goto v_15051;
v_15052:
    v_15093 = qvalue(elt(env, 2)); // maxarg!*
    goto v_15053;
v_15054:
    goto v_15050;
v_15051:
    goto v_15052;
v_15053:
    v_15093 = (LispObject)greaterp2(v_15094, v_15093);
    v_15093 = v_15093 ? lisp_true : nil;
    env = stack[-2];
    if (v_15093 == nil) goto v_15048;
    v_15093 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 8); // qerline
    v_15093 = (*qfn1(fn))(fn, v_15093);
    env = stack[-2];
    v_15093 = elt(env, 3); // "**** "
    v_15093 = Lprinc(nil, v_15093);
    env = stack[-2];
    v_15093 = stack[-1];
    v_15093 = Lprin(nil, v_15093);
    env = stack[-2];
    v_15093 = elt(env, 4); // " has "
    v_15093 = Lprinc(nil, v_15093);
    env = stack[-2];
    v_15093 = stack[0];
    v_15093 = Lprinc(nil, v_15093);
    env = stack[-2];
    v_15093 = elt(env, 5); // " arguments"
    v_15093 = Lprinc(nil, v_15093);
    env = stack[-2];
    v_15093 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 9); // newline
    v_15093 = (*qfn1(fn))(fn, v_15093);
    env = stack[-2];
    goto v_15046;
v_15048:
v_15046:
    goto v_15079;
v_15075:
    v_15094 = stack[-1];
    goto v_15076;
v_15077:
    v_15093 = elt(env, 6); // bldmsg
    goto v_15078;
v_15079:
    goto v_15075;
v_15076:
    goto v_15077;
v_15078:
    if (v_15094 == v_15093) goto v_15074;
    goto v_15089;
v_15083:
    v_15094 = stack[-1];
    goto v_15084;
v_15085:
    v_15095 = elt(env, 7); // number!-of!-args
    goto v_15086;
v_15087:
    v_15093 = stack[0];
    goto v_15088;
v_15089:
    goto v_15083;
v_15084:
    goto v_15085;
v_15086:
    goto v_15087;
v_15088:
        return Lputprop(nil, 3, v_15094, v_15095, v_15093);
v_15074:
    v_15093 = nil;
    return onevalue(v_15093);
}



// Code for createtriplewithancestor

static LispObject CC_createtriplewithancestor(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15086, v_15087, v_15088;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15034,v_15035);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15035;
    stack[-1] = v_15034;
// end of prologue
    v_15086 = (LispObject)48+TAG_FIXNUM; // 3
    v_15086 = Lmkvect(nil, v_15086);
    env = stack[-3];
    stack[-2] = v_15086;
    goto v_15048;
v_15042:
    v_15088 = stack[-2];
    goto v_15043;
v_15044:
    v_15087 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15045;
v_15046:
    v_15086 = qvalue(elt(env, 1)); // fluidbibasistripleid
    goto v_15047;
v_15048:
    goto v_15042;
v_15043:
    goto v_15044;
v_15045:
    goto v_15046;
v_15047:
    *(LispObject *)((char *)v_15088 + (CELL-TAG_VECTOR) + (((intptr_t)v_15087-TAG_FIXNUM)/(16/CELL))) = v_15086;
    goto v_15058;
v_15052:
    v_15088 = stack[-2];
    goto v_15053;
v_15054:
    v_15087 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15055;
v_15056:
    v_15086 = stack[-1];
    goto v_15057;
v_15058:
    goto v_15052;
v_15053:
    goto v_15054;
v_15055:
    goto v_15056;
v_15057:
    *(LispObject *)((char *)v_15088 + (CELL-TAG_VECTOR) + (((intptr_t)v_15087-TAG_FIXNUM)/(16/CELL))) = v_15086;
    goto v_15068;
v_15062:
    v_15088 = stack[-2];
    goto v_15063;
v_15064:
    v_15087 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_15065;
v_15066:
    v_15086 = stack[0];
    goto v_15067;
v_15068:
    goto v_15062;
v_15063:
    goto v_15064;
v_15065:
    goto v_15066;
v_15067:
    *(LispObject *)((char *)v_15088 + (CELL-TAG_VECTOR) + (((intptr_t)v_15087-TAG_FIXNUM)/(16/CELL))) = v_15086;
    goto v_15078;
v_15072:
    stack[-1] = stack[-2];
    goto v_15073;
v_15074:
    stack[0] = (LispObject)48+TAG_FIXNUM; // 3
    goto v_15075;
v_15076:
    v_15086 = nil;
    v_15086 = ncons(v_15086);
    env = stack[-3];
    goto v_15077;
v_15078:
    goto v_15072;
v_15073:
    goto v_15074;
v_15075:
    goto v_15076;
v_15077:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_15086;
    v_15086 = qvalue(elt(env, 1)); // fluidbibasistripleid
    v_15086 = (LispObject)((intptr_t)(v_15086) + 0x10);
    qvalue(elt(env, 1)) = v_15086; // fluidbibasistripleid
    v_15086 = stack[-2];
    return onevalue(v_15086);
}



// Code for ofsf_negateat

static LispObject CC_ofsf_negateat(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15066, v_15067, v_15068;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15034;
// end of prologue
    goto v_15041;
v_15037:
    v_15066 = stack[0];
    v_15066 = qcdr(v_15066);
    v_15067 = qcar(v_15066);
    goto v_15038;
v_15039:
    v_15066 = stack[0];
    v_15066 = qcdr(v_15066);
    v_15066 = qcdr(v_15066);
    v_15066 = qcar(v_15066);
    goto v_15040;
v_15041:
    goto v_15037;
v_15038:
    goto v_15039;
v_15040:
    v_15066 = list2(v_15067, v_15066);
    env = stack[-2];
    stack[-1] = v_15066;
    goto v_15057;
v_15051:
    v_15066 = stack[0];
    v_15066 = qcar(v_15066);
    fn = elt(env, 1); // ofsf_lnegrel
    v_15068 = (*qfn1(fn))(fn, v_15066);
    goto v_15052;
v_15053:
    v_15066 = stack[-1];
    v_15067 = qcar(v_15066);
    goto v_15054;
v_15055:
    v_15066 = stack[-1];
    v_15066 = qcdr(v_15066);
    v_15066 = qcar(v_15066);
    goto v_15056;
v_15057:
    goto v_15051;
v_15052:
    goto v_15053;
v_15054:
    goto v_15055;
v_15056:
    return list3(v_15068, v_15067, v_15066);
}



// Code for get!-free!-form

static LispObject CC_getKfreeKform(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15111, v_15112, v_15113;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_15034;
// end of prologue
    stack[-2] = nil;
    goto v_15048;
v_15044:
    v_15112 = stack[-1];
    goto v_15045;
v_15046:
    v_15111 = qvalue(elt(env, 1)); // frasc!*
    goto v_15047;
v_15048:
    goto v_15044;
v_15045:
    goto v_15046;
v_15047:
    v_15111 = Latsoc(nil, v_15112, v_15111);
    stack[0] = v_15111;
    if (v_15111 == nil) goto v_15043;
    v_15111 = stack[0];
    v_15111 = qcdr(v_15111);
    goto v_15039;
v_15043:
    goto v_15063;
v_15059:
    v_15112 = stack[-1];
    goto v_15060;
v_15061:
    v_15111 = elt(env, 2); // !~
    goto v_15062;
v_15063:
    goto v_15059;
v_15060:
    goto v_15061;
v_15062:
    if (!consp(v_15112)) goto v_15057;
    v_15112 = qcar(v_15112);
    if (v_15112 == v_15111) goto v_15056;
    else goto v_15057;
v_15056:
    v_15111 = stack[-1];
    v_15111 = qcdr(v_15111);
    v_15111 = qcar(v_15111);
    stack[-1] = v_15111;
    v_15111 = elt(env, 3); // (!! !~ !! !~)
    stack[0] = v_15111;
    v_15111 = lisp_true;
    stack[-2] = v_15111;
    goto v_15055;
v_15057:
    v_15111 = elt(env, 4); // (!! !~)
    stack[0] = v_15111;
    goto v_15055;
v_15055:
    goto v_15081;
v_15077:
    goto v_15078;
v_15079:
    v_15111 = stack[-1];
    v_15111 = Lexplode(nil, v_15111);
    env = stack[-3];
    goto v_15080;
v_15081:
    goto v_15077;
v_15078:
    goto v_15079;
v_15080:
    v_15111 = Lappend(nil, stack[0], v_15111);
    env = stack[-3];
    v_15111 = Lcompress(nil, v_15111);
    env = stack[-3];
    v_15111 = Lintern(nil, v_15111);
    env = stack[-3];
    stack[0] = v_15111;
    goto v_15092;
v_15086:
    v_15113 = stack[-1];
    goto v_15087;
v_15088:
    v_15112 = stack[0];
    goto v_15089;
v_15090:
    v_15111 = qvalue(elt(env, 1)); // frasc!*
    goto v_15091;
v_15092:
    goto v_15086;
v_15087:
    goto v_15088;
v_15089:
    goto v_15090;
v_15091:
    v_15111 = acons(v_15113, v_15112, v_15111);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_15111; // frasc!*
    v_15111 = stack[-2];
    if (v_15111 == nil) goto v_15099;
    goto v_15106;
v_15102:
    v_15111 = stack[0];
    v_15112 = ncons(v_15111);
    env = stack[-3];
    goto v_15103;
v_15104:
    v_15111 = elt(env, 5); // optional
    goto v_15105;
v_15106:
    goto v_15102;
v_15103:
    goto v_15104;
v_15105:
    v_15111 = Lflag(nil, v_15112, v_15111);
    goto v_15097;
v_15099:
v_15097:
    v_15111 = stack[0];
v_15039:
    return onevalue(v_15111);
}



// Code for matpri

static LispObject CC_matpri(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15045, v_15046;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15045 = v_15034;
// end of prologue
    goto v_15041;
v_15037:
    v_15046 = qcdr(v_15045);
    goto v_15038;
v_15039:
    v_15045 = nil;
    goto v_15040;
v_15041:
    goto v_15037;
v_15038:
    goto v_15039;
v_15040:
    {
        fn = elt(env, 1); // matpri1
        return (*qfn2(fn))(fn, v_15046, v_15045);
    }
}



// Code for talp_telp

static LispObject CC_talp_telp(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15088, v_15089;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15034,v_15035);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15035;
    stack[-1] = v_15034;
// end of prologue
    stack[-2] = nil;
    v_15088 = stack[0];
    if (!consp(v_15088)) goto v_15042;
    else goto v_15043;
v_15042:
    goto v_15049;
v_15045:
    v_15089 = stack[-1];
    goto v_15046;
v_15047:
    v_15088 = stack[0];
    goto v_15048;
v_15049:
    goto v_15045;
v_15046:
    goto v_15047;
v_15048:
    v_15088 = (v_15089 == v_15088 ? lisp_true : nil);
    goto v_15039;
v_15043:
    v_15088 = stack[0];
    fn = elt(env, 1); // talp_invp
    v_15088 = (*qfn1(fn))(fn, v_15088);
    env = stack[-3];
    if (v_15088 == nil) goto v_15053;
    else goto v_15054;
v_15053:
    v_15088 = stack[0];
    fn = elt(env, 2); // talp_fargl
    v_15088 = (*qfn1(fn))(fn, v_15088);
    env = stack[-3];
    stack[0] = v_15088;
v_15061:
    v_15088 = stack[-2];
    if (v_15088 == nil) goto v_15068;
    else goto v_15069;
v_15068:
    v_15088 = stack[0];
    goto v_15067;
v_15069:
    v_15088 = nil;
    goto v_15067;
    v_15088 = nil;
v_15067:
    if (v_15088 == nil) goto v_15064;
    else goto v_15065;
v_15064:
    goto v_15060;
v_15065:
    goto v_15081;
v_15077:
    v_15089 = stack[-1];
    goto v_15078;
v_15079:
    v_15088 = stack[0];
    v_15088 = qcar(v_15088);
    goto v_15080;
v_15081:
    goto v_15077;
v_15078:
    goto v_15079;
v_15080:
    v_15088 = CC_talp_telp(elt(env, 0), v_15089, v_15088);
    env = stack[-3];
    stack[-2] = v_15088;
    v_15088 = stack[0];
    v_15088 = qcdr(v_15088);
    stack[0] = v_15088;
    goto v_15061;
v_15060:
    v_15088 = stack[-2];
    goto v_15039;
v_15054:
    v_15088 = nil;
v_15039:
    return onevalue(v_15088);
}



// Code for fctrf1

static LispObject CC_fctrf1(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15274, v_15275;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_15034;
// end of prologue
    stack[-1] = nil;
    v_15274 = stack[-3];
    if (!consp(v_15274)) goto v_15047;
    else goto v_15048;
v_15047:
    v_15274 = lisp_true;
    goto v_15046;
v_15048:
    v_15274 = stack[-3];
    v_15274 = qcar(v_15274);
    v_15274 = (consp(v_15274) ? nil : lisp_true);
    goto v_15046;
    v_15274 = nil;
v_15046:
    if (v_15274 == nil) goto v_15044;
    v_15274 = stack[-3];
    return ncons(v_15274);
v_15044:
    v_15274 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_15274)) v_15274 = nil;
    else { v_15274 = qfastgets(v_15274);
           if (v_15274 != nil) { v_15274 = elt(v_15274, 3); // field
#ifdef RECORD_GET
             if (v_15274 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_15274 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_15274 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_15274 == SPID_NOPROP) v_15274 = nil; else v_15274 = lisp_true; }}
#endif
    if (v_15274 == nil) goto v_15065;
    goto v_15073;
v_15069:
    v_15274 = stack[-3];
    fn = elt(env, 3); // lnc
    v_15275 = (*qfn1(fn))(fn, v_15274);
    env = stack[-5];
    stack[-1] = v_15275;
    goto v_15070;
v_15071:
    v_15274 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15072;
v_15073:
    goto v_15069;
v_15070:
    goto v_15071;
v_15072:
    v_15274 = Lneq(nil, v_15275, v_15274);
    env = stack[-5];
    goto v_15063;
v_15065:
    v_15274 = nil;
    goto v_15063;
    v_15274 = nil;
v_15063:
    if (v_15274 == nil) goto v_15061;
    goto v_15085;
v_15081:
    v_15274 = stack[-1];
    fn = elt(env, 4); // !:recip
    v_15275 = (*qfn1(fn))(fn, v_15274);
    env = stack[-5];
    goto v_15082;
v_15083:
    v_15274 = stack[-3];
    goto v_15084;
v_15085:
    goto v_15081;
v_15082:
    goto v_15083;
v_15084:
    fn = elt(env, 5); // multd
    v_15274 = (*qfn2(fn))(fn, v_15275, v_15274);
    env = stack[-5];
    stack[-3] = v_15274;
    goto v_15059;
v_15061:
    v_15274 = qvalue(elt(env, 1)); // dmode!*
    if (v_15274 == nil) goto v_15090;
    goto v_15099;
v_15095:
    v_15275 = qvalue(elt(env, 1)); // dmode!*
    goto v_15096;
v_15097:
    v_15274 = elt(env, 2); // unitsfn
    goto v_15098;
v_15099:
    goto v_15095;
v_15096:
    goto v_15097;
v_15098:
    v_15274 = get(v_15275, v_15274);
    env = stack[-5];
    stack[-2] = v_15274;
    if (v_15274 == nil) goto v_15090;
    goto v_15109;
v_15103:
    stack[-1] = stack[-2];
    goto v_15104;
v_15105:
    goto v_15116;
v_15112:
    v_15275 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15113;
v_15114:
    v_15274 = stack[-3];
    goto v_15115;
v_15116:
    goto v_15112;
v_15113:
    goto v_15114;
v_15115:
    stack[0] = cons(v_15275, v_15274);
    env = stack[-5];
    goto v_15106;
v_15107:
    v_15274 = stack[-3];
    fn = elt(env, 3); // lnc
    v_15274 = (*qfn1(fn))(fn, v_15274);
    env = stack[-5];
    goto v_15108;
v_15109:
    goto v_15103;
v_15104:
    goto v_15105;
v_15106:
    goto v_15107;
v_15108:
    v_15274 = Lapply2(nil, 3, stack[-1], stack[0], v_15274);
    env = stack[-5];
    stack[-4] = v_15274;
    v_15274 = stack[-4];
    v_15274 = qcdr(v_15274);
    stack[-3] = v_15274;
    v_15274 = stack[-4];
    v_15274 = qcar(v_15274);
    fn = elt(env, 4); // !:recip
    v_15274 = (*qfn1(fn))(fn, v_15274);
    env = stack[-5];
    stack[-1] = v_15274;
    goto v_15059;
v_15090:
v_15059:
    v_15274 = stack[-3];
    fn = elt(env, 6); // comfac
    v_15274 = (*qfn1(fn))(fn, v_15274);
    env = stack[-5];
    stack[-4] = v_15274;
    goto v_15133;
v_15129:
    stack[0] = stack[-3];
    goto v_15130;
v_15131:
    v_15274 = stack[-4];
    fn = elt(env, 7); // comfac!-to!-poly
    v_15274 = (*qfn1(fn))(fn, v_15274);
    env = stack[-5];
    goto v_15132;
v_15133:
    goto v_15129;
v_15130:
    goto v_15131;
v_15132:
    fn = elt(env, 8); // quotf
    v_15274 = (*qfn2(fn))(fn, stack[0], v_15274);
    env = stack[-5];
    stack[-3] = v_15274;
    v_15274 = stack[-4];
    v_15274 = qcdr(v_15274);
    v_15274 = CC_fctrf1(elt(env, 0), v_15274);
    env = stack[-5];
    stack[-2] = v_15274;
    v_15274 = stack[-4];
    v_15274 = qcar(v_15274);
    if (v_15274 == nil) goto v_15143;
    goto v_15153;
v_15147:
    v_15274 = stack[-2];
    stack[0] = qcar(v_15274);
    goto v_15148;
v_15149:
    goto v_15161;
v_15157:
    goto v_15168;
v_15164:
    goto v_15174;
v_15170:
    v_15274 = stack[-4];
    v_15274 = qcar(v_15274);
    v_15275 = qcar(v_15274);
    goto v_15171;
v_15172:
    v_15274 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15173;
v_15174:
    goto v_15170;
v_15171:
    goto v_15172;
v_15173:
    fn = elt(env, 9); // to
    v_15275 = (*qfn2(fn))(fn, v_15275, v_15274);
    env = stack[-5];
    goto v_15165;
v_15166:
    v_15274 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15167;
v_15168:
    goto v_15164;
v_15165:
    goto v_15166;
v_15167:
    v_15274 = cons(v_15275, v_15274);
    env = stack[-5];
    v_15275 = ncons(v_15274);
    env = stack[-5];
    goto v_15158;
v_15159:
    v_15274 = stack[-4];
    v_15274 = qcar(v_15274);
    v_15274 = qcdr(v_15274);
    goto v_15160;
v_15161:
    goto v_15157;
v_15158:
    goto v_15159;
v_15160:
    v_15275 = cons(v_15275, v_15274);
    env = stack[-5];
    goto v_15150;
v_15151:
    v_15274 = stack[-2];
    v_15274 = qcdr(v_15274);
    goto v_15152;
v_15153:
    goto v_15147;
v_15148:
    goto v_15149;
v_15150:
    goto v_15151;
v_15152:
    v_15274 = list2star(stack[0], v_15275, v_15274);
    env = stack[-5];
    stack[-2] = v_15274;
    goto v_15141;
v_15143:
v_15141:
    v_15274 = stack[-1];
    if (v_15274 == nil) goto v_15188;
    goto v_15196;
v_15192:
    v_15275 = stack[-1];
    goto v_15193;
v_15194:
    v_15274 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15195;
v_15196:
    goto v_15192;
v_15193:
    goto v_15194;
v_15195:
    if (v_15275 == v_15274) goto v_15188;
    goto v_15204;
v_15200:
    goto v_15210;
v_15206:
    v_15275 = stack[-1];
    goto v_15207;
v_15208:
    v_15274 = stack[-2];
    v_15274 = qcar(v_15274);
    goto v_15209;
v_15210:
    goto v_15206;
v_15207:
    goto v_15208;
v_15209:
    fn = elt(env, 5); // multd
    v_15275 = (*qfn2(fn))(fn, v_15275, v_15274);
    env = stack[-5];
    goto v_15201;
v_15202:
    v_15274 = stack[-2];
    v_15274 = qcdr(v_15274);
    goto v_15203;
v_15204:
    goto v_15200;
v_15201:
    goto v_15202;
v_15203:
    v_15274 = cons(v_15275, v_15274);
    env = stack[-5];
    stack[-2] = v_15274;
    goto v_15186;
v_15188:
v_15186:
    v_15274 = stack[-3];
    if (!consp(v_15274)) goto v_15222;
    else goto v_15223;
v_15222:
    v_15274 = lisp_true;
    goto v_15221;
v_15223:
    v_15274 = stack[-3];
    v_15274 = qcar(v_15274);
    v_15274 = (consp(v_15274) ? nil : lisp_true);
    goto v_15221;
    v_15274 = nil;
v_15221:
    if (v_15274 == nil) goto v_15219;
    goto v_15236;
v_15232:
    goto v_15242;
v_15238:
    v_15275 = stack[-3];
    goto v_15239;
v_15240:
    v_15274 = stack[-2];
    v_15274 = qcar(v_15274);
    goto v_15241;
v_15242:
    goto v_15238;
v_15239:
    goto v_15240;
v_15241:
    fn = elt(env, 10); // multf
    v_15275 = (*qfn2(fn))(fn, v_15275, v_15274);
    goto v_15233;
v_15234:
    v_15274 = stack[-2];
    v_15274 = qcdr(v_15274);
    goto v_15235;
v_15236:
    goto v_15232;
v_15233:
    goto v_15234;
v_15235:
    return cons(v_15275, v_15274);
v_15219:
    v_15274 = stack[-3];
    fn = elt(env, 11); // minusf
    v_15274 = (*qfn1(fn))(fn, v_15274);
    env = stack[-5];
    if (v_15274 == nil) goto v_15249;
    v_15274 = stack[-3];
    fn = elt(env, 12); // negf
    v_15274 = (*qfn1(fn))(fn, v_15274);
    env = stack[-5];
    stack[-3] = v_15274;
    goto v_15259;
v_15255:
    v_15274 = stack[-2];
    v_15274 = qcar(v_15274);
    fn = elt(env, 12); // negf
    v_15275 = (*qfn1(fn))(fn, v_15274);
    env = stack[-5];
    goto v_15256;
v_15257:
    v_15274 = stack[-2];
    v_15274 = qcdr(v_15274);
    goto v_15258;
v_15259:
    goto v_15255;
v_15256:
    goto v_15257;
v_15258:
    v_15274 = cons(v_15275, v_15274);
    env = stack[-5];
    stack[-2] = v_15274;
    goto v_15217;
v_15249:
v_15217:
    goto v_15270;
v_15266:
    v_15274 = stack[-3];
    fn = elt(env, 13); // factor!-prim!-f
    v_15275 = (*qfn1(fn))(fn, v_15274);
    env = stack[-5];
    goto v_15267;
v_15268:
    v_15274 = stack[-2];
    goto v_15269;
v_15270:
    goto v_15266;
v_15267:
    goto v_15268;
v_15269:
    {
        fn = elt(env, 14); // fac!-merge
        return (*qfn2(fn))(fn, v_15275, v_15274);
    }
    return onevalue(v_15274);
}



// Code for ofsf_updsigndom

static LispObject CC_ofsf_updsigndom(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15075, v_15076;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15034;
// end of prologue
    v_15075 = stack[0];
    if (v_15075 == nil) goto v_15038;
    else goto v_15039;
v_15038:
    v_15075 = elt(env, 1); // equal
    goto v_15037;
v_15039:
    goto v_15049;
v_15045:
    v_15076 = stack[0];
    goto v_15046;
v_15047:
    v_15075 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15048;
v_15049:
    goto v_15045;
v_15046:
    goto v_15047;
v_15048:
    v_15075 = (LispObject)greaterp2(v_15076, v_15075);
    v_15075 = v_15075 ? lisp_true : nil;
    env = stack[-1];
    if (v_15075 == nil) goto v_15043;
    v_15075 = elt(env, 2); // greaterp
    goto v_15037;
v_15043:
    goto v_15060;
v_15056:
    v_15076 = stack[0];
    goto v_15057;
v_15058:
    v_15075 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15059;
v_15060:
    goto v_15056;
v_15057:
    goto v_15058;
v_15059:
    v_15075 = (LispObject)lessp2(v_15076, v_15075);
    v_15075 = v_15075 ? lisp_true : nil;
    env = stack[-1];
    if (v_15075 == nil) goto v_15054;
    v_15075 = elt(env, 3); // lessp
    goto v_15037;
v_15054:
    goto v_15072;
v_15068:
    v_15076 = elt(env, 4); // "something wrong in ofsf_updSignDom:"
    goto v_15069;
v_15070:
    v_15075 = stack[0];
    goto v_15071;
v_15072:
    goto v_15068;
v_15069:
    goto v_15070;
v_15071:
    v_15075 = list2(v_15076, v_15075);
    env = stack[-1];
    {
        fn = elt(env, 5); // rederr
        return (*qfn1(fn))(fn, v_15075);
    }
    v_15075 = nil;
v_15037:
    return onevalue(v_15075);
}



// Code for oldmtch

static LispObject CC_oldmtch(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15107, v_15108, v_15109;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15034,v_15035);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_15035;
    stack[-2] = v_15034;
// end of prologue
    stack[-3] = nil;
    goto v_15048;
v_15042:
    v_15107 = stack[-2];
    v_15109 = qcdr(v_15107);
    goto v_15043;
v_15044:
    v_15107 = stack[-1];
    v_15108 = qcar(v_15107);
    goto v_15045;
v_15046:
    v_15107 = stack[-2];
    v_15107 = qcar(v_15107);
    goto v_15047;
v_15048:
    goto v_15042;
v_15043:
    goto v_15044;
v_15045:
    goto v_15046;
v_15047:
    fn = elt(env, 1); // mcharg
    v_15107 = (*qfnn(fn))(fn, 3, v_15109, v_15108, v_15107);
    env = stack[-4];
    stack[0] = v_15107;
v_15057:
    v_15107 = stack[0];
    if (v_15107 == nil) goto v_15060;
    v_15107 = stack[-3];
    if (v_15107 == nil) goto v_15064;
    else goto v_15060;
v_15064:
    goto v_15061;
v_15060:
    goto v_15056;
v_15061:
    goto v_15077;
v_15073:
    v_15107 = stack[0];
    v_15108 = qcar(v_15107);
    goto v_15074;
v_15075:
    v_15107 = stack[-1];
    v_15107 = qcdr(v_15107);
    v_15107 = qcar(v_15107);
    v_15107 = qcdr(v_15107);
    goto v_15076;
v_15077:
    goto v_15073;
v_15074:
    goto v_15075;
v_15076:
    v_15107 = Lsubla(nil, v_15108, v_15107);
    env = stack[-4];
    fn = elt(env, 2); // eval
    v_15107 = (*qfn1(fn))(fn, v_15107);
    env = stack[-4];
    if (v_15107 == nil) goto v_15070;
    goto v_15089;
v_15085:
    v_15107 = stack[0];
    v_15108 = qcar(v_15107);
    goto v_15086;
v_15087:
    v_15107 = stack[-1];
    v_15107 = qcdr(v_15107);
    v_15107 = qcdr(v_15107);
    v_15107 = qcar(v_15107);
    goto v_15088;
v_15089:
    goto v_15085;
v_15086:
    goto v_15087;
v_15088:
    v_15107 = Lsubla(nil, v_15108, v_15107);
    env = stack[-4];
    goto v_15068;
v_15070:
    v_15107 = nil;
v_15068:
    stack[-3] = v_15107;
    v_15107 = stack[0];
    v_15107 = qcdr(v_15107);
    stack[0] = v_15107;
    goto v_15057;
v_15056:
    v_15107 = stack[-3];
    if (v_15107 == nil) goto v_15101;
    v_15107 = stack[-3];
    goto v_15099;
v_15101:
    v_15107 = stack[-2];
    goto v_15099;
    v_15107 = nil;
v_15099:
    return onevalue(v_15107);
}



// Code for indxchk

static LispObject CC_indxchk(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15107, v_15108;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_15107 = v_15034;
// end of prologue
    stack[-1] = v_15107;
    goto v_15047;
v_15043:
    v_15108 = qvalue(elt(env, 1)); // indxl!*
    goto v_15044;
v_15045:
    v_15107 = qvalue(elt(env, 2)); // nosuml!*
    goto v_15046;
v_15047:
    goto v_15043;
v_15044:
    goto v_15045;
v_15046:
    fn = elt(env, 3); // union
    v_15107 = (*qfn2(fn))(fn, v_15108, v_15107);
    env = stack[-2];
    stack[0] = v_15107;
v_15040:
    v_15107 = stack[-1];
    if (v_15107 == nil) goto v_15052;
    else goto v_15053;
v_15052:
    v_15107 = nil;
    goto v_15039;
v_15053:
    goto v_15064;
v_15060:
    v_15107 = stack[-1];
    v_15107 = qcar(v_15107);
    if (!consp(v_15107)) goto v_15067;
    else goto v_15068;
v_15067:
    v_15107 = stack[-1];
    v_15107 = qcar(v_15107);
    if (is_number(v_15107)) goto v_15073;
    else goto v_15074;
v_15073:
    v_15107 = stack[-1];
    v_15107 = qcar(v_15107);
    v_15107 = Labsval(nil, v_15107);
    env = stack[-2];
    fn = elt(env, 4); // !*num2id
    v_15107 = (*qfn1(fn))(fn, v_15107);
    env = stack[-2];
    goto v_15072;
v_15074:
    v_15107 = stack[-1];
    v_15107 = qcar(v_15107);
    goto v_15072;
    v_15107 = nil;
v_15072:
    v_15108 = v_15107;
    goto v_15066;
v_15068:
    v_15107 = stack[-1];
    v_15107 = qcar(v_15107);
    v_15107 = qcdr(v_15107);
    v_15107 = qcar(v_15107);
    if (is_number(v_15107)) goto v_15085;
    else goto v_15086;
v_15085:
    v_15107 = stack[-1];
    v_15107 = qcar(v_15107);
    v_15107 = qcdr(v_15107);
    v_15107 = qcar(v_15107);
    fn = elt(env, 4); // !*num2id
    v_15107 = (*qfn1(fn))(fn, v_15107);
    env = stack[-2];
    v_15108 = v_15107;
    goto v_15066;
v_15086:
    v_15107 = stack[-1];
    v_15107 = qcar(v_15107);
    v_15107 = qcdr(v_15107);
    v_15107 = qcar(v_15107);
    v_15108 = v_15107;
    goto v_15066;
    v_15108 = nil;
v_15066:
    goto v_15061;
v_15062:
    v_15107 = stack[0];
    goto v_15063;
v_15064:
    goto v_15060;
v_15061:
    goto v_15062;
v_15063:
    v_15107 = Lmemq(nil, v_15108, v_15107);
    if (v_15107 == nil) goto v_15058;
    else goto v_15059;
v_15058:
    v_15107 = lisp_true;
    goto v_15039;
v_15059:
    v_15107 = stack[-1];
    v_15107 = qcdr(v_15107);
    stack[-1] = v_15107;
    goto v_15040;
v_15039:
    return onevalue(v_15107);
}



// Code for edge_new_parent

static LispObject CC_edge_new_parent(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15074, v_15075, v_15076;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15075 = v_15034;
// end of prologue
v_15033:
    v_15074 = v_15075;
    if (v_15074 == nil) goto v_15038;
    else goto v_15039;
v_15038:
    v_15074 = nil;
    goto v_15037;
v_15039:
    goto v_15048;
v_15044:
    v_15074 = v_15075;
    v_15076 = qcar(v_15074);
    goto v_15045;
v_15046:
    v_15074 = qvalue(elt(env, 1)); // new_edge_list
    goto v_15047;
v_15048:
    goto v_15044;
v_15045:
    goto v_15046;
v_15047:
    v_15074 = Lassoc(nil, v_15076, v_15074);
    v_15076 = v_15074;
    v_15074 = v_15076;
    if (v_15074 == nil) goto v_15057;
    goto v_15064;
v_15060:
    stack[0] = v_15076;
    goto v_15061;
v_15062:
    v_15074 = v_15075;
    v_15074 = qcdr(v_15074);
    v_15074 = CC_edge_new_parent(elt(env, 0), v_15074);
    goto v_15063;
v_15064:
    goto v_15060;
v_15061:
    goto v_15062;
v_15063:
    {
        LispObject v_15078 = stack[0];
        return cons(v_15078, v_15074);
    }
v_15057:
    v_15074 = v_15075;
    v_15074 = qcdr(v_15074);
    v_15075 = v_15074;
    goto v_15033;
    v_15074 = nil;
    goto v_15037;
    v_15074 = nil;
v_15037:
    return onevalue(v_15074);
}



// Code for pcdiv

static LispObject CC_pcdiv(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15109, v_15110;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15034,v_15035);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_15035;
    v_15109 = v_15034;
// end of prologue
    stack[-5] = v_15109;
    v_15109 = stack[-5];
    if (v_15109 == nil) goto v_15046;
    else goto v_15047;
v_15046:
    v_15109 = nil;
    goto v_15041;
v_15047:
    v_15109 = stack[-5];
    v_15109 = qcar(v_15109);
    v_15110 = v_15109;
    goto v_15059;
v_15055:
    v_15109 = v_15110;
    stack[0] = qcar(v_15109);
    goto v_15056;
v_15057:
    goto v_15067;
v_15063:
    v_15109 = v_15110;
    v_15110 = qcdr(v_15109);
    goto v_15064;
v_15065:
    v_15109 = stack[-4];
    goto v_15066;
v_15067:
    goto v_15063;
v_15064:
    goto v_15065;
v_15066:
    fn = elt(env, 1); // cdiv
    v_15109 = (*qfn2(fn))(fn, v_15110, v_15109);
    env = stack[-6];
    goto v_15058;
v_15059:
    goto v_15055;
v_15056:
    goto v_15057;
v_15058:
    v_15109 = cons(stack[0], v_15109);
    env = stack[-6];
    v_15109 = ncons(v_15109);
    env = stack[-6];
    stack[-2] = v_15109;
    stack[-3] = v_15109;
v_15042:
    v_15109 = stack[-5];
    v_15109 = qcdr(v_15109);
    stack[-5] = v_15109;
    v_15109 = stack[-5];
    if (v_15109 == nil) goto v_15075;
    else goto v_15076;
v_15075:
    v_15109 = stack[-3];
    goto v_15041;
v_15076:
    goto v_15084;
v_15080:
    stack[-1] = stack[-2];
    goto v_15081;
v_15082:
    v_15109 = stack[-5];
    v_15109 = qcar(v_15109);
    v_15110 = v_15109;
    goto v_15095;
v_15091:
    v_15109 = v_15110;
    stack[0] = qcar(v_15109);
    goto v_15092;
v_15093:
    goto v_15103;
v_15099:
    v_15109 = v_15110;
    v_15110 = qcdr(v_15109);
    goto v_15100;
v_15101:
    v_15109 = stack[-4];
    goto v_15102;
v_15103:
    goto v_15099;
v_15100:
    goto v_15101;
v_15102:
    fn = elt(env, 1); // cdiv
    v_15109 = (*qfn2(fn))(fn, v_15110, v_15109);
    env = stack[-6];
    goto v_15094;
v_15095:
    goto v_15091;
v_15092:
    goto v_15093;
v_15094:
    v_15109 = cons(stack[0], v_15109);
    env = stack[-6];
    v_15109 = ncons(v_15109);
    env = stack[-6];
    goto v_15083;
v_15084:
    goto v_15080;
v_15081:
    goto v_15082;
v_15083:
    v_15109 = Lrplacd(nil, stack[-1], v_15109);
    env = stack[-6];
    v_15109 = stack[-2];
    v_15109 = qcdr(v_15109);
    stack[-2] = v_15109;
    goto v_15042;
v_15041:
    return onevalue(v_15109);
}



// Code for sc_rep

static LispObject CC_sc_rep(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15047;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15047 = v_15034;
// end of prologue
    goto v_15040;
v_15036:
    stack[0] = qvalue(elt(env, 1)); // g_sc_ve
    goto v_15037;
v_15038:
    v_15047 = sub1(v_15047);
    goto v_15039;
v_15040:
    goto v_15036;
v_15037:
    goto v_15038;
v_15039:
    v_15047 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_15047-TAG_FIXNUM)/(16/CELL)));
    v_15047 = qcdr(v_15047);
    v_15047 = qcar(v_15047);
    return onevalue(v_15047);
}



// Code for gcd!-in!-vector

static LispObject CC_gcdKinKvector(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15311, v_15312, v_15313, v_15314, v_15315, v_15316;
    LispObject fn;
    LispObject v_15037, v_15036, v_15035, v_15034;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "gcd-in-vector");
    va_start(aa, nargs);
    v_15034 = va_arg(aa, LispObject);
    v_15035 = va_arg(aa, LispObject);
    v_15036 = va_arg(aa, LispObject);
    v_15037 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_15037,v_15036,v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_15034,v_15035,v_15036,v_15037);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15037;
    stack[-1] = v_15036;
    stack[-2] = v_15035;
    stack[-3] = v_15034;
// end of prologue
    goto v_15055;
v_15051:
    v_15312 = stack[-2];
    goto v_15052;
v_15053:
    v_15311 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15054;
v_15055:
    goto v_15051;
v_15052:
    goto v_15053;
v_15054:
    if (v_15312 == v_15311) goto v_15049;
    else goto v_15050;
v_15049:
    v_15311 = lisp_true;
    goto v_15048;
v_15050:
    goto v_15065;
v_15061:
    v_15312 = stack[0];
    goto v_15062;
v_15063:
    v_15311 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15064;
v_15065:
    goto v_15061;
v_15062:
    goto v_15063;
v_15064:
    v_15311 = (v_15312 == v_15311 ? lisp_true : nil);
    goto v_15048;
    v_15311 = nil;
v_15048:
    if (v_15311 == nil) goto v_15046;
    goto v_15075;
v_15069:
    v_15313 = stack[-3];
    goto v_15070;
v_15071:
    v_15312 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15072;
v_15073:
    v_15311 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15074;
v_15075:
    goto v_15069;
v_15070:
    goto v_15071;
v_15072:
    goto v_15073;
v_15074:
    *(LispObject *)((char *)v_15313 + (CELL-TAG_VECTOR) + (((intptr_t)v_15312-TAG_FIXNUM)/(16/CELL))) = v_15311;
    v_15311 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15041;
v_15046:
    goto v_15087;
v_15083:
    v_15312 = stack[-2];
    goto v_15084;
v_15085:
    v_15311 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15086;
v_15087:
    goto v_15083;
v_15084:
    goto v_15085;
v_15086:
    if (((intptr_t)(v_15312)) < ((intptr_t)(v_15311))) goto v_15080;
    goto v_15095;
v_15091:
    v_15312 = stack[0];
    goto v_15092;
v_15093:
    v_15311 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15094;
v_15095:
    goto v_15091;
v_15092:
    goto v_15093;
v_15094:
    if (((intptr_t)(v_15312)) < ((intptr_t)(v_15311))) goto v_15080;
    goto v_15081;
v_15080:
    v_15311 = elt(env, 1); // "GCD with zero not allowed"
    fn = elt(env, 2); // errorf
    v_15311 = (*qfn1(fn))(fn, v_15311);
    env = stack[-4];
    goto v_15044;
v_15081:
v_15044:
v_15042:
    goto v_15109;
v_15101:
    v_15314 = stack[-3];
    goto v_15102;
v_15103:
    v_15313 = stack[-2];
    goto v_15104;
v_15105:
    v_15312 = stack[-1];
    goto v_15106;
v_15107:
    v_15311 = stack[0];
    goto v_15108;
v_15109:
    goto v_15101;
v_15102:
    goto v_15103;
v_15104:
    goto v_15105;
v_15106:
    goto v_15107;
v_15108:
    fn = elt(env, 3); // remainder!-in!-vector
    v_15311 = (*qfnn(fn))(fn, 4, v_15314, v_15313, v_15312, v_15311);
    env = stack[-4];
    stack[-2] = v_15311;
    goto v_15122;
v_15118:
    v_15312 = stack[-2];
    goto v_15119;
v_15120:
    v_15311 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15121;
v_15122:
    goto v_15118;
v_15119:
    goto v_15120;
v_15121:
    if (v_15312 == v_15311) goto v_15116;
    else goto v_15117;
v_15116:
    goto v_15131;
v_15125:
    v_15313 = stack[-3];
    goto v_15126;
v_15127:
    v_15312 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15128;
v_15129:
    v_15311 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15130;
v_15131:
    goto v_15125;
v_15126:
    goto v_15127;
v_15128:
    goto v_15129;
v_15130:
    *(LispObject *)((char *)v_15313 + (CELL-TAG_VECTOR) + (((intptr_t)v_15312-TAG_FIXNUM)/(16/CELL))) = v_15311;
    v_15311 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15041;
v_15117:
    goto v_15142;
v_15138:
    v_15312 = stack[-2];
    goto v_15139;
v_15140:
    v_15311 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_15141;
v_15142:
    goto v_15138;
v_15139:
    goto v_15140;
v_15141:
    if (v_15312 == v_15311) goto v_15136;
    else goto v_15137;
v_15136:
    goto v_15150;
v_15146:
    v_15312 = stack[-1];
    goto v_15147;
v_15148:
    v_15311 = stack[0];
    goto v_15149;
v_15150:
    goto v_15146;
v_15147:
    goto v_15148;
v_15149:
    v_15311 = *(LispObject *)((char *)v_15312 + (CELL-TAG_VECTOR) + (((intptr_t)v_15311-TAG_FIXNUM)/(16/CELL)));
    v_15311 = Lmodular_reciprocal(nil, v_15311);
    env = stack[-4];
    v_15316 = v_15311;
    v_15311 = (LispObject)0+TAG_FIXNUM; // 0
    v_15315 = v_15311;
v_15157:
    goto v_15167;
v_15163:
    v_15312 = stack[0];
    goto v_15164;
v_15165:
    v_15311 = v_15315;
    goto v_15166;
v_15167:
    goto v_15163;
v_15164:
    goto v_15165;
v_15166:
    v_15311 = (LispObject)(intptr_t)((intptr_t)v_15312 - (intptr_t)v_15311 + TAG_FIXNUM);
    v_15311 = ((intptr_t)(v_15311) < 0 ? lisp_true : nil);
    if (v_15311 == nil) goto v_15162;
    goto v_15156;
v_15162:
    goto v_15179;
v_15173:
    v_15314 = stack[-3];
    goto v_15174;
v_15175:
    v_15313 = v_15315;
    goto v_15176;
v_15177:
    goto v_15187;
v_15183:
    goto v_15192;
v_15188:
    v_15312 = stack[-1];
    goto v_15189;
v_15190:
    v_15311 = v_15315;
    goto v_15191;
v_15192:
    goto v_15188;
v_15189:
    goto v_15190;
v_15191:
    v_15312 = *(LispObject *)((char *)v_15312 + (CELL-TAG_VECTOR) + (((intptr_t)v_15311-TAG_FIXNUM)/(16/CELL)));
    goto v_15184;
v_15185:
    v_15311 = v_15316;
    goto v_15186;
v_15187:
    goto v_15183;
v_15184:
    goto v_15185;
v_15186:
    v_15311 = Lmodular_times(nil, v_15312, v_15311);
    env = stack[-4];
    goto v_15178;
v_15179:
    goto v_15173;
v_15174:
    goto v_15175;
v_15176:
    goto v_15177;
v_15178:
    *(LispObject *)((char *)v_15314 + (CELL-TAG_VECTOR) + (((intptr_t)v_15313-TAG_FIXNUM)/(16/CELL))) = v_15311;
    v_15311 = v_15315;
    v_15311 = (LispObject)((intptr_t)(v_15311) + 0x10);
    v_15315 = v_15311;
    goto v_15157;
v_15156:
    v_15311 = stack[0];
    goto v_15041;
v_15137:
    goto v_15209;
v_15201:
    v_15314 = stack[-1];
    goto v_15202;
v_15203:
    v_15313 = stack[0];
    goto v_15204;
v_15205:
    v_15312 = stack[-3];
    goto v_15206;
v_15207:
    v_15311 = stack[-2];
    goto v_15208;
v_15209:
    goto v_15201;
v_15202:
    goto v_15203;
v_15204:
    goto v_15205;
v_15206:
    goto v_15207;
v_15208:
    fn = elt(env, 3); // remainder!-in!-vector
    v_15311 = (*qfnn(fn))(fn, 4, v_15314, v_15313, v_15312, v_15311);
    env = stack[-4];
    stack[0] = v_15311;
    goto v_15222;
v_15218:
    v_15312 = stack[0];
    goto v_15219;
v_15220:
    v_15311 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15221;
v_15222:
    goto v_15218;
v_15219:
    goto v_15220;
v_15221:
    if (v_15312 == v_15311) goto v_15216;
    else goto v_15217;
v_15216:
    goto v_15231;
v_15225:
    v_15313 = stack[-3];
    goto v_15226;
v_15227:
    v_15312 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15228;
v_15229:
    v_15311 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15230;
v_15231:
    goto v_15225;
v_15226:
    goto v_15227;
v_15228:
    goto v_15229;
v_15230:
    *(LispObject *)((char *)v_15313 + (CELL-TAG_VECTOR) + (((intptr_t)v_15312-TAG_FIXNUM)/(16/CELL))) = v_15311;
    v_15311 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15041;
v_15217:
    goto v_15242;
v_15238:
    v_15312 = stack[0];
    goto v_15239;
v_15240:
    v_15311 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_15241;
v_15242:
    goto v_15238;
v_15239:
    goto v_15240;
v_15241:
    if (v_15312 == v_15311) goto v_15236;
    else goto v_15237;
v_15236:
    goto v_15250;
v_15246:
    v_15312 = stack[-3];
    goto v_15247;
v_15248:
    v_15311 = stack[-2];
    goto v_15249;
v_15250:
    goto v_15246;
v_15247:
    goto v_15248;
v_15249:
    v_15311 = *(LispObject *)((char *)v_15312 + (CELL-TAG_VECTOR) + (((intptr_t)v_15311-TAG_FIXNUM)/(16/CELL)));
    v_15311 = Lmodular_reciprocal(nil, v_15311);
    env = stack[-4];
    v_15316 = v_15311;
    goto v_15262;
v_15258:
    v_15312 = v_15316;
    goto v_15259;
v_15260:
    v_15311 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15261;
v_15262:
    goto v_15258;
v_15259:
    goto v_15260;
v_15261:
    if (v_15312 == v_15311) goto v_15257;
    v_15311 = (LispObject)0+TAG_FIXNUM; // 0
    v_15315 = v_15311;
v_15268:
    goto v_15278;
v_15274:
    v_15312 = stack[-2];
    goto v_15275;
v_15276:
    v_15311 = v_15315;
    goto v_15277;
v_15278:
    goto v_15274;
v_15275:
    goto v_15276;
v_15277:
    v_15311 = (LispObject)(intptr_t)((intptr_t)v_15312 - (intptr_t)v_15311 + TAG_FIXNUM);
    v_15311 = ((intptr_t)(v_15311) < 0 ? lisp_true : nil);
    if (v_15311 == nil) goto v_15273;
    goto v_15267;
v_15273:
    goto v_15290;
v_15284:
    v_15314 = stack[-3];
    goto v_15285;
v_15286:
    v_15313 = v_15315;
    goto v_15287;
v_15288:
    goto v_15298;
v_15294:
    goto v_15303;
v_15299:
    v_15312 = stack[-3];
    goto v_15300;
v_15301:
    v_15311 = v_15315;
    goto v_15302;
v_15303:
    goto v_15299;
v_15300:
    goto v_15301;
v_15302:
    v_15312 = *(LispObject *)((char *)v_15312 + (CELL-TAG_VECTOR) + (((intptr_t)v_15311-TAG_FIXNUM)/(16/CELL)));
    goto v_15295;
v_15296:
    v_15311 = v_15316;
    goto v_15297;
v_15298:
    goto v_15294;
v_15295:
    goto v_15296;
v_15297:
    v_15311 = Lmodular_times(nil, v_15312, v_15311);
    env = stack[-4];
    goto v_15289;
v_15290:
    goto v_15284;
v_15285:
    goto v_15286;
v_15287:
    goto v_15288;
v_15289:
    *(LispObject *)((char *)v_15314 + (CELL-TAG_VECTOR) + (((intptr_t)v_15313-TAG_FIXNUM)/(16/CELL))) = v_15311;
    v_15311 = v_15315;
    v_15311 = (LispObject)((intptr_t)(v_15311) + 0x10);
    v_15315 = v_15311;
    goto v_15268;
v_15267:
    goto v_15255;
v_15257:
v_15255:
    v_15311 = stack[-2];
    goto v_15041;
v_15237:
    goto v_15042;
v_15041:
    return onevalue(v_15311);
}



// Code for lalr_most_common_dest

static LispObject CC_lalr_most_common_dest(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15129, v_15130, v_15131;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_15129 = v_15034;
// end of prologue
    stack[-3] = nil;
    stack[-1] = v_15129;
v_15043:
    v_15129 = stack[-1];
    if (v_15129 == nil) goto v_15047;
    else goto v_15048;
v_15047:
    goto v_15042;
v_15048:
    v_15129 = stack[-1];
    v_15129 = qcar(v_15129);
    v_15131 = v_15129;
    goto v_15062;
v_15058:
    v_15129 = v_15131;
    v_15130 = qcdr(v_15129);
    goto v_15059;
v_15060:
    v_15129 = stack[-3];
    goto v_15061;
v_15062:
    goto v_15058;
v_15059:
    goto v_15060;
v_15061:
    v_15129 = Lassoc(nil, v_15130, v_15129);
    stack[-2] = v_15129;
    if (v_15129 == nil) goto v_15057;
    goto v_15072;
v_15068:
    stack[0] = stack[-2];
    goto v_15069;
v_15070:
    v_15129 = stack[-2];
    v_15129 = qcdr(v_15129);
    v_15129 = add1(v_15129);
    env = stack[-4];
    goto v_15071;
v_15072:
    goto v_15068;
v_15069:
    goto v_15070;
v_15071:
    v_15129 = Lrplacd(nil, stack[0], v_15129);
    env = stack[-4];
    goto v_15055;
v_15057:
    goto v_15086;
v_15080:
    v_15129 = v_15131;
    v_15131 = qcdr(v_15129);
    goto v_15081;
v_15082:
    v_15130 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15083;
v_15084:
    v_15129 = stack[-3];
    goto v_15085;
v_15086:
    goto v_15080;
v_15081:
    goto v_15082;
v_15083:
    goto v_15084;
v_15085:
    v_15129 = acons(v_15131, v_15130, v_15129);
    env = stack[-4];
    stack[-3] = v_15129;
    goto v_15055;
v_15055:
    v_15129 = stack[-1];
    v_15129 = qcdr(v_15129);
    stack[-1] = v_15129;
    goto v_15043;
v_15042:
    v_15129 = stack[-3];
    v_15129 = qcar(v_15129);
    stack[-2] = v_15129;
    v_15129 = stack[-3];
    v_15129 = qcdr(v_15129);
    stack[-1] = v_15129;
v_15098:
    v_15129 = stack[-1];
    if (v_15129 == nil) goto v_15103;
    else goto v_15104;
v_15103:
    goto v_15097;
v_15104:
    v_15129 = stack[-1];
    v_15129 = qcar(v_15129);
    stack[0] = v_15129;
    goto v_15119;
v_15115:
    v_15129 = stack[0];
    v_15130 = qcdr(v_15129);
    goto v_15116;
v_15117:
    v_15129 = stack[-2];
    v_15129 = qcdr(v_15129);
    goto v_15118;
v_15119:
    goto v_15115;
v_15116:
    goto v_15117;
v_15118:
    v_15129 = (LispObject)greaterp2(v_15130, v_15129);
    v_15129 = v_15129 ? lisp_true : nil;
    env = stack[-4];
    if (v_15129 == nil) goto v_15113;
    v_15129 = stack[0];
    stack[-2] = v_15129;
    goto v_15111;
v_15113:
v_15111:
    v_15129 = stack[-1];
    v_15129 = qcdr(v_15129);
    stack[-1] = v_15129;
    goto v_15098;
v_15097:
    v_15129 = stack[-2];
    v_15129 = qcar(v_15129);
    return onevalue(v_15129);
}



// Code for get_char_value

static LispObject CC_get_char_value(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15102, v_15103;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15034,v_15035);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_15035;
    v_15103 = v_15034;
// end of prologue
    stack[-1] = nil;
    v_15102 = nil;
    stack[-3] = v_15102;
    v_15102 = v_15103;
    v_15102 = qcdr(v_15102);
    stack[0] = v_15102;
v_15047:
    v_15102 = stack[-3];
    if (v_15102 == nil) goto v_15054;
    else goto v_15055;
v_15054:
    goto v_15062;
v_15058:
    v_15102 = stack[0];
    v_15103 = Llength(nil, v_15102);
    env = stack[-4];
    goto v_15059;
v_15060:
    v_15102 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15061;
v_15062:
    goto v_15058;
v_15059:
    goto v_15060;
v_15061:
    v_15102 = (LispObject)greaterp2(v_15103, v_15102);
    v_15102 = v_15102 ? lisp_true : nil;
    env = stack[-4];
    goto v_15053;
v_15055:
    v_15102 = nil;
    goto v_15053;
    v_15102 = nil;
v_15053:
    if (v_15102 == nil) goto v_15050;
    else goto v_15051;
v_15050:
    goto v_15046;
v_15051:
    goto v_15078;
v_15074:
    v_15102 = stack[0];
    v_15102 = qcar(v_15102);
    v_15103 = qcar(v_15102);
    goto v_15075;
v_15076:
    v_15102 = stack[-2];
    goto v_15077;
v_15078:
    goto v_15074;
v_15075:
    goto v_15076;
v_15077:
    if (equal(v_15103, v_15102)) goto v_15072;
    else goto v_15073;
v_15072:
    v_15102 = stack[0];
    v_15102 = qcar(v_15102);
    v_15102 = qcdr(v_15102);
    v_15102 = qcar(v_15102);
    stack[-1] = v_15102;
    v_15102 = lisp_true;
    stack[-3] = v_15102;
    goto v_15071;
v_15073:
v_15071:
    v_15102 = stack[0];
    v_15102 = qcdr(v_15102);
    stack[0] = v_15102;
    goto v_15047;
v_15046:
    v_15102 = stack[-3];
    if (v_15102 == nil) goto v_15095;
    v_15102 = stack[-1];
    goto v_15041;
v_15095:
    v_15102 = elt(env, 1); // "error in get character element"
    fn = elt(env, 2); // rederr
    v_15102 = (*qfn1(fn))(fn, v_15102);
    goto v_15093;
v_15093:
    v_15102 = nil;
v_15041:
    return onevalue(v_15102);
}



// Code for aex_mvartest

static LispObject CC_aex_mvartest(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15047, v_15048;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15034,v_15035);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15035;
    v_15047 = v_15034;
// end of prologue
    goto v_15042;
v_15038:
    fn = elt(env, 1); // aex_ex
    v_15047 = (*qfn1(fn))(fn, v_15047);
    env = stack[-1];
    v_15048 = qcar(v_15047);
    goto v_15039;
v_15040:
    v_15047 = stack[0];
    goto v_15041;
v_15042:
    goto v_15038;
v_15039:
    goto v_15040;
v_15041:
    {
        fn = elt(env, 2); // sfto_mvartest
        return (*qfn2(fn))(fn, v_15048, v_15047);
    }
}



// Code for multi_args

static LispObject CC_multi_args(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15050;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15034;
// end of prologue
    v_15050 = stack[0];
    if (v_15050 == nil) goto v_15041;
    v_15050 = stack[0];
    v_15050 = qcar(v_15050);
    fn = elt(env, 1); // expression
    v_15050 = (*qfn1(fn))(fn, v_15050);
    env = stack[-1];
    v_15050 = stack[0];
    v_15050 = qcdr(v_15050);
    v_15050 = CC_multi_args(elt(env, 0), v_15050);
    goto v_15039;
v_15041:
v_15039:
    v_15050 = nil;
    return onevalue(v_15050);
}



// Code for n_nary

static LispObject CC_n_nary(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15105, v_15106;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15034,v_15035);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15035;
    stack[-1] = v_15034;
// end of prologue
    goto v_15051;
v_15047:
    v_15105 = stack[-1];
    v_15106 = qcar(v_15105);
    goto v_15048;
v_15049:
    v_15105 = elt(env, 1); // e
    goto v_15050;
v_15051:
    goto v_15047;
v_15048:
    goto v_15049;
v_15050:
    if (v_15106 == v_15105) goto v_15045;
    else goto v_15046;
v_15045:
    goto v_15059;
v_15055:
    v_15106 = stack[0];
    goto v_15056;
v_15057:
    v_15105 = elt(env, 2); // power
    goto v_15058;
v_15059:
    goto v_15055;
v_15056:
    goto v_15057;
v_15058:
    v_15105 = (v_15106 == v_15105 ? lisp_true : nil);
    goto v_15044;
v_15046:
    v_15105 = nil;
    goto v_15044;
    v_15105 = nil;
v_15044:
    if (v_15105 == nil) goto v_15042;
    goto v_15071;
v_15067:
    v_15105 = stack[-1];
    v_15106 = qcdr(v_15105);
    goto v_15068;
v_15069:
    v_15105 = elt(env, 3); // exp
    goto v_15070;
v_15071:
    goto v_15067;
v_15068:
    goto v_15069;
v_15070:
    fn = elt(env, 9); // unary
    v_15105 = (*qfn2(fn))(fn, v_15106, v_15105);
    goto v_15040;
v_15042:
    v_15105 = elt(env, 4); // "<apply>"
    fn = elt(env, 10); // printout
    v_15105 = (*qfn1(fn))(fn, v_15105);
    env = stack[-2];
    v_15105 = elt(env, 5); // "<"
    v_15105 = Lprinc(nil, v_15105);
    env = stack[-2];
    v_15105 = stack[0];
    v_15105 = Lprinc(nil, v_15105);
    env = stack[-2];
    v_15105 = elt(env, 6); // "/>"
    v_15105 = Lprinc(nil, v_15105);
    env = stack[-2];
    goto v_15090;
v_15086:
    v_15106 = qvalue(elt(env, 7)); // indent
    goto v_15087;
v_15088:
    v_15105 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_15089;
v_15090:
    goto v_15086;
v_15087:
    goto v_15088;
v_15089:
    v_15105 = plus2(v_15106, v_15105);
    env = stack[-2];
    qvalue(elt(env, 7)) = v_15105; // indent
    v_15105 = stack[-1];
    fn = elt(env, 11); // multi_elem
    v_15105 = (*qfn1(fn))(fn, v_15105);
    env = stack[-2];
    goto v_15100;
v_15096:
    v_15106 = qvalue(elt(env, 7)); // indent
    goto v_15097;
v_15098:
    v_15105 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_15099;
v_15100:
    goto v_15096;
v_15097:
    goto v_15098;
v_15099:
    v_15105 = difference2(v_15106, v_15105);
    env = stack[-2];
    qvalue(elt(env, 7)) = v_15105; // indent
    v_15105 = elt(env, 8); // "</apply>"
    fn = elt(env, 10); // printout
    v_15105 = (*qfn1(fn))(fn, v_15105);
    goto v_15040;
v_15040:
    v_15105 = nil;
    return onevalue(v_15105);
}



// Code for gcd2

static LispObject CC_gcd2(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15070, v_15071, v_15072;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15034,v_15035);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15035;
    v_15071 = v_15034;
// end of prologue
v_15033:
    goto v_15045;
v_15041:
    goto v_15042;
v_15043:
    v_15070 = stack[0];
    goto v_15044;
v_15045:
    goto v_15041;
v_15042:
    goto v_15043;
v_15044:
    v_15070 = Cremainder(v_15071, v_15070);
    env = stack[-1];
    v_15072 = v_15070;
    goto v_15056;
v_15052:
    v_15071 = v_15072;
    goto v_15053;
v_15054:
    v_15070 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15055;
v_15056:
    goto v_15052;
v_15053:
    goto v_15054;
v_15055:
    if (v_15071 == v_15070) goto v_15050;
    else goto v_15051;
v_15050:
    v_15070 = stack[0];
    goto v_15049;
v_15051:
    goto v_15067;
v_15063:
    v_15071 = stack[0];
    goto v_15064;
v_15065:
    v_15070 = v_15072;
    goto v_15066;
v_15067:
    goto v_15063;
v_15064:
    goto v_15065;
v_15066:
    stack[0] = v_15070;
    goto v_15033;
    v_15070 = nil;
v_15049:
    return onevalue(v_15070);
}



// Code for meq

static LispObject CC_meq(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15065, v_15066, v_15067;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15034,v_15035);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15035;
    stack[-1] = v_15034;
// end of prologue
    v_15065 = stack[-1];
    fn = elt(env, 2); // binding
    v_15065 = (*qfn1(fn))(fn, v_15065);
    env = stack[-2];
    v_15066 = v_15065;
    goto v_15044;
v_15040:
    v_15065 = v_15066;
    if (v_15065 == nil) goto v_15048;
    goto v_15056;
v_15052:
    v_15065 = v_15066;
    goto v_15053;
v_15054:
    v_15067 = elt(env, 1); // unbound
    goto v_15055;
v_15056:
    goto v_15052;
v_15053:
    goto v_15054;
v_15055:
    if (v_15065 == v_15067) goto v_15048;
    v_15065 = v_15066;
    v_15066 = v_15065;
    goto v_15046;
v_15048:
    v_15065 = stack[-1];
    v_15066 = v_15065;
    goto v_15046;
    v_15066 = nil;
v_15046:
    goto v_15041;
v_15042:
    v_15065 = stack[0];
    goto v_15043;
v_15044:
    goto v_15040;
v_15041:
    goto v_15042;
v_15043:
    v_15065 = (equal(v_15066, v_15065) ? lisp_true : nil);
    return onevalue(v_15065);
}



// Code for gcompatible

static LispObject CC_gcompatible(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15060, v_15061, v_15062;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15061 = v_15035;
    v_15062 = v_15034;
// end of prologue
    v_15060 = qvalue(elt(env, 1)); // gmodule!*
    if (v_15060 == nil) goto v_15039;
    else goto v_15040;
v_15039:
    v_15060 = lisp_true;
    goto v_15038;
v_15040:
    goto v_15052;
v_15046:
    v_15060 = v_15062;
    v_15060 = qcdr(v_15060);
    v_15062 = qcar(v_15060);
    goto v_15047;
v_15048:
    v_15060 = v_15061;
    v_15060 = qcdr(v_15060);
    v_15061 = qcar(v_15060);
    goto v_15049;
v_15050:
    v_15060 = qvalue(elt(env, 1)); // gmodule!*
    goto v_15051;
v_15052:
    goto v_15046;
v_15047:
    goto v_15048;
v_15049:
    goto v_15050;
v_15051:
    {
        fn = elt(env, 2); // gevcompatible1
        return (*qfnn(fn))(fn, 3, v_15062, v_15061, v_15060);
    }
    v_15060 = nil;
v_15038:
    return onevalue(v_15060);
}



// Code for groebnormalform

static LispObject CC_groebnormalform(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15052, v_15053, v_15054, v_15055;
    LispObject fn;
    LispObject v_15036, v_15035, v_15034;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "groebnormalform");
    va_start(aa, nargs);
    v_15034 = va_arg(aa, LispObject);
    v_15035 = va_arg(aa, LispObject);
    v_15036 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15052 = v_15036;
    v_15053 = v_15035;
    v_15054 = v_15034;
// end of prologue
    goto v_15047;
v_15039:
    v_15055 = v_15054;
    goto v_15040;
v_15041:
    v_15054 = v_15053;
    goto v_15042;
v_15043:
    v_15053 = v_15052;
    goto v_15044;
v_15045:
    v_15052 = nil;
    goto v_15046;
v_15047:
    goto v_15039;
v_15040:
    goto v_15041;
v_15042:
    goto v_15043;
v_15044:
    goto v_15045;
v_15046:
    {
        fn = elt(env, 1); // groebnormalform0
        return (*qfnn(fn))(fn, 4, v_15055, v_15054, v_15053, v_15052);
    }
}



// Code for memqcar

static LispObject CC_memqcar(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15054, v_15055, v_15056;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15054 = v_15035;
    v_15055 = v_15034;
// end of prologue
    v_15056 = v_15055;
    if (!consp(v_15056)) goto v_15040;
    goto v_15046;
v_15042:
    v_15055 = qcar(v_15055);
    goto v_15043;
v_15044:
    goto v_15045;
v_15046:
    goto v_15042;
v_15043:
    goto v_15044;
v_15045:
    v_15054 = Lmemq(nil, v_15055, v_15054);
    goto v_15038;
v_15040:
    v_15054 = nil;
    goto v_15038;
    v_15054 = nil;
v_15038:
    return onevalue(v_15054);
}



// Code for equalreval

static LispObject CC_equalreval(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15074, v_15075;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_15074 = v_15034;
// end of prologue
    v_15075 = qvalue(elt(env, 1)); // substitution
    if (v_15075 == nil) goto v_15038;
    else goto v_15039;
v_15038:
    goto v_15048;
v_15042:
    stack[-1] = elt(env, 2); // equal
    goto v_15043;
v_15044:
    v_15075 = v_15074;
    stack[0] = qcar(v_15075);
    goto v_15045;
v_15046:
    v_15074 = qcdr(v_15074);
    v_15074 = qcar(v_15074);
    fn = elt(env, 3); // reval
    v_15074 = (*qfn1(fn))(fn, v_15074);
    env = stack[-2];
    v_15074 = ncons(v_15074);
    goto v_15047;
v_15048:
    goto v_15042;
v_15043:
    goto v_15044;
v_15045:
    goto v_15046;
v_15047:
    {
        LispObject v_15078 = stack[-1];
        LispObject v_15079 = stack[0];
        return list2star(v_15078, v_15079, v_15074);
    }
v_15039:
    goto v_15064;
v_15060:
    v_15075 = v_15074;
    v_15075 = qcar(v_15075);
    goto v_15061;
v_15062:
    v_15074 = qcdr(v_15074);
    v_15074 = qcar(v_15074);
    goto v_15063;
v_15064:
    goto v_15060;
v_15061:
    goto v_15062;
v_15063:
    fn = elt(env, 4); // evalequal
    v_15074 = (*qfn2(fn))(fn, v_15075, v_15074);
    if (v_15074 == nil) goto v_15058;
    v_15074 = lisp_true;
    goto v_15037;
v_15058:
    v_15074 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15037;
    v_15074 = nil;
v_15037:
    return onevalue(v_15074);
}



// Code for log_assignment_list

static LispObject CC_log_assignment_list(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15062, v_15063;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15034,v_15035);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15035;
    stack[-1] = v_15034;
// end of prologue
v_15039:
    v_15062 = stack[0];
    if (!consp(v_15062)) goto v_15042;
    else goto v_15043;
v_15042:
    v_15062 = nil;
    goto v_15038;
v_15043:
    goto v_15053;
v_15049:
    v_15063 = stack[-1];
    goto v_15050;
v_15051:
    v_15062 = stack[0];
    v_15062 = qcar(v_15062);
    goto v_15052;
v_15053:
    goto v_15049;
v_15050:
    goto v_15051;
v_15052:
    fn = elt(env, 1); // log_assignment
    v_15062 = (*qfn2(fn))(fn, v_15063, v_15062);
    env = stack[-2];
    if (v_15062 == nil) goto v_15047;
    v_15062 = lisp_true;
    goto v_15038;
v_15047:
    v_15062 = stack[0];
    v_15062 = qcdr(v_15062);
    stack[0] = v_15062;
    goto v_15039;
    v_15062 = nil;
v_15038:
    return onevalue(v_15062);
}



// Code for red!=subst1

static LispObject CC_redMsubst1(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15224, v_15225, v_15226;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15034,v_15035);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_15035;
    stack[-6] = v_15034;
// end of prologue
    v_15224 = stack[-6];
    fn = elt(env, 5); // bas_dpoly
    v_15224 = (*qfn1(fn))(fn, v_15224);
    env = stack[-8];
    stack[0] = v_15224;
    v_15224 = stack[0];
    fn = elt(env, 6); // dp_lc
    v_15224 = (*qfn1(fn))(fn, v_15224);
    env = stack[-8];
    stack[-1] = v_15224;
    v_15224 = stack[-6];
    fn = elt(env, 7); // bas_rep
    v_15224 = (*qfn1(fn))(fn, v_15224);
    env = stack[-8];
    stack[-7] = v_15224;
    v_15224 = stack[-5];
    fn = elt(env, 5); // bas_dpoly
    v_15224 = (*qfn1(fn))(fn, v_15224);
    env = stack[-8];
    stack[-3] = v_15224;
    v_15224 = stack[-3];
    fn = elt(env, 6); // dp_lc
    v_15224 = (*qfn1(fn))(fn, v_15224);
    env = stack[-8];
    stack[-2] = v_15224;
    v_15224 = qvalue(elt(env, 1)); // !*bcsimp
    if (v_15224 == nil) goto v_15061;
    v_15224 = stack[-2];
    fn = elt(env, 8); // cali_bc_inv
    v_15224 = (*qfn1(fn))(fn, v_15224);
    env = stack[-8];
    stack[-4] = v_15224;
    if (v_15224 == nil) goto v_15066;
    goto v_15074;
v_15070:
    v_15225 = stack[-1];
    goto v_15071;
v_15072:
    v_15224 = stack[-4];
    goto v_15073;
v_15074:
    goto v_15070;
v_15071:
    goto v_15072;
v_15073:
    fn = elt(env, 9); // cali_bc_prod
    v_15224 = (*qfn2(fn))(fn, v_15225, v_15224);
    env = stack[-8];
    stack[-1] = v_15224;
    v_15224 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 10); // cali_bc_fi
    v_15224 = (*qfn1(fn))(fn, v_15224);
    env = stack[-8];
    stack[-2] = v_15224;
    goto v_15064;
v_15066:
    goto v_15086;
v_15082:
    v_15225 = stack[-2];
    goto v_15083;
v_15084:
    v_15224 = stack[-1];
    goto v_15085;
v_15086:
    goto v_15082;
v_15083:
    goto v_15084;
v_15085:
    fn = elt(env, 11); // cali_bc_gcd
    v_15224 = (*qfn2(fn))(fn, v_15225, v_15224);
    env = stack[-8];
    stack[-4] = v_15224;
    goto v_15094;
v_15090:
    v_15225 = stack[-2];
    goto v_15091;
v_15092:
    v_15224 = stack[-4];
    goto v_15093;
v_15094:
    goto v_15090;
v_15091:
    goto v_15092;
v_15093:
    fn = elt(env, 12); // cali_bc_divmod
    v_15224 = (*qfn2(fn))(fn, v_15225, v_15224);
    env = stack[-8];
    v_15224 = qcar(v_15224);
    stack[-2] = v_15224;
    goto v_15103;
v_15099:
    v_15225 = stack[-1];
    goto v_15100;
v_15101:
    v_15224 = stack[-4];
    goto v_15102;
v_15103:
    goto v_15099;
v_15100:
    goto v_15101;
v_15102:
    fn = elt(env, 12); // cali_bc_divmod
    v_15224 = (*qfn2(fn))(fn, v_15225, v_15224);
    env = stack[-8];
    v_15224 = qcar(v_15224);
    stack[-1] = v_15224;
    goto v_15064;
v_15064:
    goto v_15059;
v_15061:
v_15059:
    goto v_15112;
v_15108:
    v_15224 = stack[0];
    fn = elt(env, 13); // dp_lmon
    stack[-4] = (*qfn1(fn))(fn, v_15224);
    env = stack[-8];
    goto v_15109;
v_15110:
    v_15224 = stack[-3];
    fn = elt(env, 13); // dp_lmon
    v_15224 = (*qfn1(fn))(fn, v_15224);
    env = stack[-8];
    goto v_15111;
v_15112:
    goto v_15108;
v_15109:
    goto v_15110;
v_15111:
    fn = elt(env, 14); // mo_diff
    v_15224 = (*qfn2(fn))(fn, stack[-4], v_15224);
    env = stack[-8];
    stack[-4] = v_15224;
    goto v_15122;
v_15118:
    goto v_15128;
v_15124:
    v_15225 = stack[-2];
    goto v_15125;
v_15126:
    v_15224 = stack[0];
    goto v_15127;
v_15128:
    goto v_15124;
v_15125:
    goto v_15126;
v_15127:
    fn = elt(env, 15); // dp_times_bc
    stack[0] = (*qfn2(fn))(fn, v_15225, v_15224);
    env = stack[-8];
    goto v_15119;
v_15120:
    goto v_15138;
v_15132:
    v_15226 = stack[-1];
    goto v_15133;
v_15134:
    v_15225 = stack[-4];
    goto v_15135;
v_15136:
    v_15224 = stack[-3];
    goto v_15137;
v_15138:
    goto v_15132;
v_15133:
    goto v_15134;
v_15135:
    goto v_15136;
v_15137:
    fn = elt(env, 16); // dp_times_bcmo
    v_15224 = (*qfnn(fn))(fn, 3, v_15226, v_15225, v_15224);
    env = stack[-8];
    goto v_15121;
v_15122:
    goto v_15118;
v_15119:
    goto v_15120;
v_15121:
    fn = elt(env, 17); // dp_diff
    v_15224 = (*qfn2(fn))(fn, stack[0], v_15224);
    env = stack[-8];
    stack[0] = v_15224;
    goto v_15147;
v_15143:
    goto v_15153;
v_15149:
    v_15225 = stack[-2];
    goto v_15150;
v_15151:
    v_15224 = stack[-7];
    goto v_15152;
v_15153:
    goto v_15149;
v_15150:
    goto v_15151;
v_15152:
    fn = elt(env, 15); // dp_times_bc
    stack[-2] = (*qfn2(fn))(fn, v_15225, v_15224);
    env = stack[-8];
    goto v_15144;
v_15145:
    goto v_15163;
v_15157:
    goto v_15158;
v_15159:
    goto v_15160;
v_15161:
    v_15224 = stack[-5];
    fn = elt(env, 7); // bas_rep
    v_15224 = (*qfn1(fn))(fn, v_15224);
    env = stack[-8];
    goto v_15162;
v_15163:
    goto v_15157;
v_15158:
    goto v_15159;
v_15160:
    goto v_15161;
v_15162:
    fn = elt(env, 16); // dp_times_bcmo
    v_15224 = (*qfnn(fn))(fn, 3, stack[-1], stack[-4], v_15224);
    env = stack[-8];
    goto v_15146;
v_15147:
    goto v_15143;
v_15144:
    goto v_15145;
v_15146:
    fn = elt(env, 17); // dp_diff
    v_15224 = (*qfn2(fn))(fn, stack[-2], v_15224);
    env = stack[-8];
    stack[-1] = v_15224;
    goto v_15177;
v_15173:
    fn = elt(env, 18); // cali_trace
    v_15225 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_15174;
v_15175:
    v_15224 = (LispObject)1264+TAG_FIXNUM; // 79
    goto v_15176;
v_15177:
    goto v_15173;
v_15174:
    goto v_15175;
v_15176:
    v_15224 = (LispObject)greaterp2(v_15225, v_15224);
    v_15224 = v_15224 ? lisp_true : nil;
    env = stack[-8];
    if (v_15224 == nil) goto v_15171;
    v_15224 = elt(env, 2); // "---> "
    v_15224 = Lprinc(nil, v_15224);
    env = stack[-8];
    v_15224 = stack[0];
    fn = elt(env, 19); // dp_print
    v_15224 = (*qfn1(fn))(fn, v_15224);
    env = stack[-8];
    goto v_15169;
v_15171:
    goto v_15191;
v_15187:
    fn = elt(env, 18); // cali_trace
    v_15225 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_15188;
v_15189:
    v_15224 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15190;
v_15191:
    goto v_15187;
v_15188:
    goto v_15189;
v_15190:
    v_15224 = (LispObject)greaterp2(v_15225, v_15224);
    v_15224 = v_15224 ? lisp_true : nil;
    env = stack[-8];
    if (v_15224 == nil) goto v_15185;
    v_15224 = elt(env, 3); // "."
    v_15224 = Lprinc(nil, v_15224);
    env = stack[-8];
    goto v_15169;
v_15185:
v_15169:
    goto v_15205;
v_15201:
    fn = elt(env, 18); // cali_trace
    v_15225 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_15202;
v_15203:
    v_15224 = (LispObject)1424+TAG_FIXNUM; // 89
    goto v_15204;
v_15205:
    goto v_15201;
v_15202:
    goto v_15203;
v_15204:
    v_15224 = (LispObject)greaterp2(v_15225, v_15224);
    v_15224 = v_15224 ? lisp_true : nil;
    env = stack[-8];
    if (v_15224 == nil) goto v_15199;
    v_15224 = elt(env, 4); // " uses "
    v_15224 = Lprinc(nil, v_15224);
    env = stack[-8];
    v_15224 = stack[-3];
    fn = elt(env, 19); // dp_print
    v_15224 = (*qfn1(fn))(fn, v_15224);
    env = stack[-8];
    goto v_15197;
v_15199:
v_15197:
    goto v_15219;
v_15213:
    v_15224 = stack[-6];
    fn = elt(env, 20); // bas_nr
    v_15226 = (*qfn1(fn))(fn, v_15224);
    env = stack[-8];
    goto v_15214;
v_15215:
    v_15225 = stack[0];
    goto v_15216;
v_15217:
    v_15224 = stack[-1];
    goto v_15218;
v_15219:
    goto v_15213;
v_15214:
    goto v_15215;
v_15216:
    goto v_15217;
v_15218:
    {
        fn = elt(env, 21); // bas_make1
        return (*qfnn(fn))(fn, 3, v_15226, v_15225, v_15224);
    }
    return onevalue(v_15224);
}



// Code for insert

static LispObject CC_insert(LispObject env,
                         LispObject v_15035, LispObject v_15036)
{
    env = qenv(env);
    LispObject v_15094, v_15095;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15036,v_15035);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15035,v_15036);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_15094 = v_15036;
    stack[-1] = v_15035;
// end of prologue
// Binding gg!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = v_15094; // gg!*
    stack[0] = nil;
v_15047:
    v_15094 = qvalue(elt(env, 1)); // gg!*
    if (v_15094 == nil) goto v_15050;
    goto v_15060;
v_15056:
    v_15094 = stack[-1];
    v_15095 = qcdr(v_15094);
    goto v_15057;
v_15058:
    v_15094 = qvalue(elt(env, 1)); // gg!*
    v_15094 = qcar(v_15094);
    v_15094 = qcdr(v_15094);
    goto v_15059;
v_15060:
    goto v_15056;
v_15057:
    goto v_15058;
v_15059:
    fn = elt(env, 2); // dless
    v_15094 = (*qfn2(fn))(fn, v_15095, v_15094);
    env = stack[-3];
    if (v_15094 == nil) goto v_15050;
    goto v_15051;
v_15050:
    goto v_15046;
v_15051:
    goto v_15072;
v_15068:
    v_15094 = qvalue(elt(env, 1)); // gg!*
    v_15095 = qcar(v_15094);
    goto v_15069;
v_15070:
    v_15094 = stack[0];
    goto v_15071;
v_15072:
    goto v_15068;
v_15069:
    goto v_15070;
v_15071:
    v_15094 = cons(v_15095, v_15094);
    env = stack[-3];
    stack[0] = v_15094;
    v_15094 = qvalue(elt(env, 1)); // gg!*
    v_15094 = qcdr(v_15094);
    qvalue(elt(env, 1)) = v_15094; // gg!*
    goto v_15047;
v_15046:
    goto v_15083;
v_15079:
    v_15094 = stack[0];
    stack[0] = Lnreverse(nil, v_15094);
    env = stack[-3];
    goto v_15080;
v_15081:
    goto v_15091;
v_15087:
    v_15095 = stack[-1];
    goto v_15088;
v_15089:
    v_15094 = qvalue(elt(env, 1)); // gg!*
    goto v_15090;
v_15091:
    goto v_15087;
v_15088:
    goto v_15089;
v_15090:
    v_15094 = cons(v_15095, v_15094);
    env = stack[-3];
    goto v_15082;
v_15083:
    goto v_15079;
v_15080:
    goto v_15081;
v_15082:
    v_15094 = Lappend(nil, stack[0], v_15094);
    ;}  // end of a binding scope
    return onevalue(v_15094);
}



// Code for dv_cambhead

static LispObject CC_dv_cambhead(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15077, v_15078;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15034;
// end of prologue
v_15033:
    v_15077 = stack[0];
    fn = elt(env, 3); // listp
    v_15077 = (*qfn1(fn))(fn, v_15077);
    env = stack[-2];
    if (v_15077 == nil) goto v_15041;
    goto v_15052;
v_15048:
    v_15077 = stack[0];
    stack[-1] = qcar(v_15077);
    goto v_15049;
v_15050:
    goto v_15060;
v_15056:
    v_15078 = elt(env, 1); // expt
    goto v_15057;
v_15058:
    v_15077 = elt(env, 2); // minus
    goto v_15059;
v_15060:
    goto v_15056;
v_15057:
    goto v_15058;
v_15059:
    v_15077 = list2(v_15078, v_15077);
    env = stack[-2];
    goto v_15051;
v_15052:
    goto v_15048;
v_15049:
    goto v_15050;
v_15051:
    v_15077 = Lmember(nil, stack[-1], v_15077);
    if (v_15077 == nil) goto v_15047;
    v_15077 = stack[0];
    v_15077 = qcdr(v_15077);
    v_15077 = qcar(v_15077);
    stack[0] = v_15077;
    goto v_15033;
v_15047:
    v_15077 = stack[0];
    fn = elt(env, 3); // listp
    v_15077 = (*qfn1(fn))(fn, v_15077);
    if (v_15077 == nil) goto v_15071;
    v_15077 = stack[0];
    v_15077 = qcar(v_15077);
    goto v_15037;
v_15071:
    goto v_15039;
v_15041:
v_15039:
    v_15077 = nil;
v_15037:
    return onevalue(v_15077);
}



// Code for lalr_make_compressed_action_table

static LispObject CC_lalr_make_compressed_action_table(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15078, v_15079;
    LispObject fn;
    argcheck(nargs, 0, "lalr_make_compressed_action_table");
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
    v_15078 = qvalue(elt(env, 1)); // itemset_collection
    v_15078 = Llength(nil, v_15078);
    env = stack[-4];
    v_15078 = sub1(v_15078);
    env = stack[-4];
    v_15078 = Lmkvect(nil, v_15078);
    env = stack[-4];
    stack[-3] = v_15078;
    v_15078 = qvalue(elt(env, 1)); // itemset_collection
    stack[-2] = v_15078;
v_15045:
    v_15078 = stack[-2];
    if (v_15078 == nil) goto v_15049;
    else goto v_15050;
v_15049:
    goto v_15044;
v_15050:
    v_15078 = stack[-2];
    v_15078 = qcar(v_15078);
    v_15079 = v_15078;
    goto v_15062;
v_15056:
    stack[-1] = stack[-3];
    goto v_15057;
v_15058:
    v_15078 = v_15079;
    stack[0] = qcdr(v_15078);
    goto v_15059;
v_15060:
    v_15078 = v_15079;
    fn = elt(env, 3); // lalr_make_compressed_action_row
    v_15078 = (*qfn1(fn))(fn, v_15078);
    env = stack[-4];
    goto v_15061;
v_15062:
    goto v_15056;
v_15057:
    goto v_15058;
v_15059:
    goto v_15060;
v_15061:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_15078;
    v_15078 = stack[-2];
    v_15078 = qcdr(v_15078);
    stack[-2] = v_15078;
    goto v_15045;
v_15044:
    v_15078 = qvalue(elt(env, 2)); // !*lalr_verbose
    if (v_15078 == nil) goto v_15073;
    v_15078 = stack[-3];
    fn = elt(env, 4); // lalr_print_compressed_action_table
    v_15078 = (*qfn1(fn))(fn, v_15078);
    goto v_15071;
v_15073:
v_15071:
    v_15078 = stack[-3];
    return onevalue(v_15078);
}



// Code for ifstat

static LispObject CC_ifstat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15124, v_15125;
    LispObject fn;
    argcheck(nargs, 0, "ifstat");
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
v_15039:
    v_15124 = lisp_true;
    fn = elt(env, 6); // xread
    v_15124 = (*qfn1(fn))(fn, v_15124);
    env = stack[-2];
    stack[0] = v_15124;
    goto v_15050;
v_15046:
    v_15125 = qvalue(elt(env, 1)); // cursym!*
    goto v_15047;
v_15048:
    v_15124 = elt(env, 2); // then
    goto v_15049;
v_15050:
    goto v_15046;
v_15047:
    goto v_15048;
v_15049:
    if (v_15125 == v_15124) goto v_15045;
    goto v_15058;
v_15054:
    v_15125 = elt(env, 3); // if
    goto v_15055;
v_15056:
    v_15124 = lisp_true;
    goto v_15057;
v_15058:
    goto v_15054;
v_15055:
    goto v_15056;
v_15057:
    fn = elt(env, 7); // symerr
    v_15124 = (*qfn2(fn))(fn, v_15125, v_15124);
    env = stack[-2];
    goto v_15043;
v_15045:
v_15043:
    goto v_15066;
v_15062:
    goto v_15063;
v_15064:
    goto v_15073;
v_15069:
    goto v_15070;
v_15071:
    v_15124 = lisp_true;
    fn = elt(env, 6); // xread
    v_15124 = (*qfn1(fn))(fn, v_15124);
    env = stack[-2];
    goto v_15072;
v_15073:
    goto v_15069;
v_15070:
    goto v_15071;
v_15072:
    v_15124 = list2(stack[0], v_15124);
    env = stack[-2];
    goto v_15065;
v_15066:
    goto v_15062;
v_15063:
    goto v_15064;
v_15065:
    fn = elt(env, 8); // aconc!*
    v_15124 = (*qfn2(fn))(fn, stack[-1], v_15124);
    env = stack[-2];
    stack[-1] = v_15124;
    goto v_15085;
v_15081:
    v_15125 = qvalue(elt(env, 1)); // cursym!*
    goto v_15082;
v_15083:
    v_15124 = elt(env, 4); // else
    goto v_15084;
v_15085:
    goto v_15081;
v_15082:
    goto v_15083;
v_15084:
    if (v_15125 == v_15124) goto v_15080;
    goto v_15078;
v_15080:
    goto v_15095;
v_15091:
    fn = elt(env, 9); // scan
    v_15125 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_15092;
v_15093:
    v_15124 = elt(env, 3); // if
    goto v_15094;
v_15095:
    goto v_15091;
v_15092:
    goto v_15093;
v_15094:
    if (v_15125 == v_15124) goto v_15089;
    else goto v_15090;
v_15089:
    goto v_15039;
v_15090:
    goto v_15105;
v_15101:
    goto v_15102;
v_15103:
    goto v_15112;
v_15108:
    stack[0] = lisp_true;
    goto v_15109;
v_15110:
    v_15124 = lisp_true;
    fn = elt(env, 10); // xread1
    v_15124 = (*qfn1(fn))(fn, v_15124);
    env = stack[-2];
    goto v_15111;
v_15112:
    goto v_15108;
v_15109:
    goto v_15110;
v_15111:
    v_15124 = list2(stack[0], v_15124);
    env = stack[-2];
    goto v_15104;
v_15105:
    goto v_15101;
v_15102:
    goto v_15103;
v_15104:
    fn = elt(env, 8); // aconc!*
    v_15124 = (*qfn2(fn))(fn, stack[-1], v_15124);
    env = stack[-2];
    stack[-1] = v_15124;
    goto v_15078;
v_15078:
    goto v_15121;
v_15117:
    v_15125 = elt(env, 5); // cond
    goto v_15118;
v_15119:
    v_15124 = stack[-1];
    goto v_15120;
v_15121:
    goto v_15117;
v_15118:
    goto v_15119;
v_15120:
    return cons(v_15125, v_15124);
    return onevalue(v_15124);
}



// Code for opmtchrevop

static LispObject CC_opmtchrevop(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15072, v_15073;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15034;
// end of prologue
    v_15072 = qvalue(elt(env, 1)); // !*val
    if (v_15072 == nil) goto v_15042;
    else goto v_15043;
v_15042:
    v_15072 = lisp_true;
    goto v_15041;
v_15043:
    goto v_15053;
v_15049:
    v_15073 = elt(env, 2); // cons
    goto v_15050;
v_15051:
    v_15072 = stack[0];
    goto v_15052;
v_15053:
    goto v_15049;
v_15050:
    goto v_15051;
v_15052:
    v_15072 = Lsmemq(nil, v_15073, v_15072);
    env = stack[-2];
    goto v_15041;
    v_15072 = nil;
v_15041:
    if (v_15072 == nil) goto v_15039;
    v_15072 = stack[0];
    {
        fn = elt(env, 3); // opmtch
        return (*qfn1(fn))(fn, v_15072);
    }
v_15039:
    goto v_15066;
v_15062:
    v_15072 = stack[0];
    stack[-1] = qcar(v_15072);
    goto v_15063;
v_15064:
    v_15072 = stack[0];
    v_15072 = qcdr(v_15072);
    fn = elt(env, 4); // revlis
    v_15072 = (*qfn1(fn))(fn, v_15072);
    env = stack[-2];
    goto v_15065;
v_15066:
    goto v_15062;
v_15063:
    goto v_15064;
v_15065:
    v_15072 = cons(stack[-1], v_15072);
    env = stack[-2];
    {
        fn = elt(env, 3); // opmtch
        return (*qfn1(fn))(fn, v_15072);
    }
    v_15072 = nil;
    return onevalue(v_15072);
}



// Code for ofsf_optsubstat

static LispObject CC_ofsf_optsubstat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15093, v_15094;
    LispObject fn;
    LispObject v_15036, v_15035, v_15034;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_optsubstat");
    va_start(aa, nargs);
    v_15034 = va_arg(aa, LispObject);
    v_15035 = va_arg(aa, LispObject);
    v_15036 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15036,v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15034,v_15035,v_15036);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_15093 = v_15036;
    stack[-2] = v_15035;
    stack[0] = v_15034;
// end of prologue
    goto v_15050;
v_15046:
    v_15094 = stack[0];
    v_15094 = qcdr(v_15094);
    v_15094 = qcar(v_15094);
    goto v_15047;
v_15048:
    goto v_15049;
v_15050:
    goto v_15046;
v_15047:
    goto v_15048;
v_15049:
    fn = elt(env, 1); // ofsf_optsplitterm
    v_15093 = (*qfn2(fn))(fn, v_15094, v_15093);
    env = stack[-4];
    stack[-3] = v_15093;
    if (v_15093 == nil) goto v_15043;
    else goto v_15044;
v_15043:
    v_15093 = stack[0];
    goto v_15040;
v_15044:
    goto v_15063;
v_15057:
    v_15093 = stack[0];
    stack[-1] = qcar(v_15093);
    goto v_15058;
v_15059:
    goto v_15071;
v_15067:
    goto v_15077;
v_15073:
    v_15093 = stack[-3];
    v_15094 = qcar(v_15093);
    goto v_15074;
v_15075:
    v_15093 = stack[-2];
    v_15093 = qcar(v_15093);
    goto v_15076;
v_15077:
    goto v_15073;
v_15074:
    goto v_15075;
v_15076:
    fn = elt(env, 2); // multf
    stack[0] = (*qfn2(fn))(fn, v_15094, v_15093);
    env = stack[-4];
    goto v_15068;
v_15069:
    goto v_15087;
v_15083:
    v_15093 = stack[-3];
    v_15094 = qcdr(v_15093);
    goto v_15084;
v_15085:
    v_15093 = stack[-2];
    v_15093 = qcdr(v_15093);
    goto v_15086;
v_15087:
    goto v_15083;
v_15084:
    goto v_15085;
v_15086:
    fn = elt(env, 2); // multf
    v_15093 = (*qfn2(fn))(fn, v_15094, v_15093);
    env = stack[-4];
    goto v_15070;
v_15071:
    goto v_15067;
v_15068:
    goto v_15069;
v_15070:
    fn = elt(env, 3); // addf
    v_15094 = (*qfn2(fn))(fn, stack[0], v_15093);
    goto v_15060;
v_15061:
    v_15093 = nil;
    goto v_15062;
v_15063:
    goto v_15057;
v_15058:
    goto v_15059;
v_15060:
    goto v_15061;
v_15062:
    {
        LispObject v_15099 = stack[-1];
        return list3(v_15099, v_15094, v_15093);
    }
v_15040:
    return onevalue(v_15093);
}



// Code for lambdavar

static LispObject CC_lambdavar(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15043;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
// copy arguments values to proper place
    v_15043 = v_15034;
// end of prologue
    v_15043 = qcdr(v_15043);
    v_15043 = qcdr(v_15043);
    v_15043 = Lreverse(nil, v_15043);
    v_15043 = qcdr(v_15043);
    return onevalue(v_15043);
}



// Code for rowdel

static LispObject CC_rowdel(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15110, v_15111, v_15112;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15034;
// end of prologue
    v_15110 = stack[0];
    fn = elt(env, 3); // delhisto
    v_15110 = (*qfn1(fn))(fn, v_15110);
    env = stack[-2];
    goto v_15044;
v_15038:
    goto v_15049;
v_15045:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_15046;
v_15047:
    goto v_15056;
v_15052:
    v_15111 = qvalue(elt(env, 2)); // maxvar
    goto v_15053;
v_15054:
    v_15110 = stack[0];
    goto v_15055;
v_15056:
    goto v_15052;
v_15053:
    goto v_15054;
v_15055:
    v_15110 = plus2(v_15111, v_15110);
    env = stack[-2];
    goto v_15048;
v_15049:
    goto v_15045;
v_15046:
    goto v_15047;
v_15048:
    v_15112 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_15110-TAG_FIXNUM)/(16/CELL)));
    goto v_15039;
v_15040:
    v_15111 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15041;
v_15042:
    v_15110 = nil;
    goto v_15043;
v_15044:
    goto v_15038;
v_15039:
    goto v_15040;
v_15041:
    goto v_15042;
v_15043:
    *(LispObject *)((char *)v_15112 + (CELL-TAG_VECTOR) + (((intptr_t)v_15111-TAG_FIXNUM)/(16/CELL))) = v_15110;
    goto v_15070;
v_15066:
    goto v_15075;
v_15071:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_15072;
v_15073:
    goto v_15082;
v_15078:
    v_15111 = qvalue(elt(env, 2)); // maxvar
    goto v_15079;
v_15080:
    v_15110 = stack[0];
    goto v_15081;
v_15082:
    goto v_15078;
v_15079:
    goto v_15080;
v_15081:
    v_15110 = plus2(v_15111, v_15110);
    env = stack[-2];
    goto v_15074;
v_15075:
    goto v_15071;
v_15072:
    goto v_15073;
v_15074:
    v_15111 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_15110-TAG_FIXNUM)/(16/CELL)));
    goto v_15067;
v_15068:
    v_15110 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_15069;
v_15070:
    goto v_15066;
v_15067:
    goto v_15068;
v_15069:
    v_15110 = *(LispObject *)((char *)v_15111 + (CELL-TAG_VECTOR) + (((intptr_t)v_15110-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_15110;
v_15065:
    v_15110 = stack[0];
    if (v_15110 == nil) goto v_15090;
    else goto v_15091;
v_15090:
    v_15110 = nil;
    goto v_15064;
v_15091:
    v_15110 = stack[0];
    v_15110 = qcar(v_15110);
    goto v_15102;
v_15098:
    v_15111 = v_15110;
    v_15111 = qcar(v_15111);
    goto v_15099;
v_15100:
    v_15110 = qcdr(v_15110);
    v_15110 = qcar(v_15110);
    goto v_15101;
v_15102:
    goto v_15098;
v_15099:
    goto v_15100;
v_15101:
    fn = elt(env, 4); // downwght
    v_15110 = (*qfn2(fn))(fn, v_15111, v_15110);
    env = stack[-2];
    v_15110 = stack[0];
    v_15110 = qcdr(v_15110);
    stack[0] = v_15110;
    goto v_15065;
v_15064:
    return onevalue(v_15110);
}



// Code for bfplusn

static LispObject CC_bfplusn(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15060, v_15061, v_15062;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15061 = v_15035;
    v_15062 = v_15034;
// end of prologue
    v_15060 = v_15062;
    if (!consp(v_15060)) goto v_15039;
    else goto v_15040;
v_15039:
    goto v_15047;
v_15043:
    v_15060 = v_15062;
    goto v_15044;
v_15045:
    goto v_15046;
v_15047:
    goto v_15043;
v_15044:
    goto v_15045;
v_15046:
    return plus2(v_15060, v_15061);
v_15040:
    goto v_15057;
v_15053:
    v_15060 = v_15062;
    goto v_15054;
v_15055:
    goto v_15056;
v_15057:
    goto v_15053;
v_15054:
    goto v_15055;
v_15056:
    {
        fn = elt(env, 1); // plus!:
        return (*qfn2(fn))(fn, v_15060, v_15061);
    }
    v_15060 = nil;
    return onevalue(v_15060);
}



// Code for fortranname

static LispObject CC_fortranname(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15099, v_15100;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15034;
// end of prologue
    v_15099 = stack[0];
    v_15099 = Lstringp(nil, v_15099);
    env = stack[-1];
    if (v_15099 == nil) goto v_15039;
    v_15099 = stack[0];
    {
        fn = elt(env, 8); // stringtoatom
        return (*qfn1(fn))(fn, v_15099);
    }
v_15039:
    goto v_15054;
v_15050:
    v_15100 = stack[0];
    goto v_15051;
v_15052:
    v_15099 = qvalue(elt(env, 1)); // !*notfortranfuns!*
    goto v_15053;
v_15054:
    goto v_15050;
v_15051:
    goto v_15052;
v_15053:
    v_15099 = Lmemq(nil, v_15100, v_15099);
    if (v_15099 == nil) goto v_15049;
    v_15099 = qvalue(elt(env, 2)); // !*stdout!*
    v_15099 = qcdr(v_15099);
    v_15099 = Lwrs(nil, v_15099);
    env = stack[-1];
    v_15099 = elt(env, 3); // "*** WARNING: "
    v_15099 = Lprinc(nil, v_15099);
    env = stack[-1];
    v_15099 = stack[0];
    v_15099 = Lprin(nil, v_15099);
    env = stack[-1];
    v_15099 = elt(env, 4); // " is not an intrinsic Fortran function"
    fn = elt(env, 9); // prin2t
    v_15099 = (*qfn1(fn))(fn, v_15099);
    env = stack[-1];
    goto v_15047;
v_15049:
v_15047:
    v_15099 = qvalue(elt(env, 5)); // !*double
    if (v_15099 == nil) goto v_15071;
    goto v_15081;
v_15077:
    v_15100 = stack[0];
    goto v_15078;
v_15079:
    v_15099 = elt(env, 6); // !*doublename!*
    goto v_15080;
v_15081:
    goto v_15077;
v_15078:
    goto v_15079;
v_15080:
    v_15099 = get(v_15100, v_15099);
    if (v_15099 == nil) goto v_15075;
    else goto v_15074;
v_15075:
    v_15099 = stack[0];
v_15074:
    goto v_15069;
v_15071:
    goto v_15095;
v_15091:
    v_15100 = stack[0];
    goto v_15092;
v_15093:
    v_15099 = elt(env, 7); // !*fortranname!*
    goto v_15094;
v_15095:
    goto v_15091;
v_15092:
    goto v_15093;
v_15094:
    v_15099 = get(v_15100, v_15099);
    if (v_15099 == nil) goto v_15089;
    else goto v_15088;
v_15089:
    v_15099 = stack[0];
v_15088:
    goto v_15069;
    v_15099 = nil;
v_15069:
    goto v_15037;
    v_15099 = nil;
v_15037:
    return onevalue(v_15099);
}



// Code for mk!-numr

static LispObject CC_mkKnumr(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15091, v_15092, v_15093;
    LispObject fn;
    LispObject v_15036, v_15035, v_15034;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mk-numr");
    va_start(aa, nargs);
    v_15034 = va_arg(aa, LispObject);
    v_15035 = va_arg(aa, LispObject);
    v_15036 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15036,v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15034,v_15035,v_15036);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15036;
    stack[-1] = v_15035;
    stack[-2] = v_15034;
// end of prologue
    stack[-3] = nil;
v_15041:
    goto v_15050;
v_15046:
    v_15092 = stack[-1];
    goto v_15047;
v_15048:
    v_15091 = stack[0];
    goto v_15049;
v_15050:
    goto v_15046;
v_15047:
    goto v_15048;
v_15049:
    if (equal(v_15092, v_15091)) goto v_15044;
    else goto v_15045;
v_15044:
    v_15091 = stack[-3];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_15091);
    }
v_15045:
    goto v_15062;
v_15058:
    goto v_15071;
v_15067:
    v_15092 = stack[-1];
    goto v_15068;
v_15069:
    v_15091 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15070;
v_15071:
    goto v_15067;
v_15068:
    goto v_15069;
v_15070:
    if (v_15092 == v_15091) goto v_15065;
    else goto v_15066;
v_15065:
    v_15091 = stack[-2];
    v_15092 = v_15091;
    goto v_15064;
v_15066:
    goto v_15084;
v_15078:
    v_15093 = elt(env, 1); // difference
    goto v_15079;
v_15080:
    v_15092 = stack[-2];
    goto v_15081;
v_15082:
    v_15091 = stack[-1];
    goto v_15083;
v_15084:
    goto v_15078;
v_15079:
    goto v_15080;
v_15081:
    goto v_15082;
v_15083:
    v_15091 = list3(v_15093, v_15092, v_15091);
    env = stack[-4];
    v_15092 = v_15091;
    goto v_15064;
    v_15092 = nil;
v_15064:
    goto v_15059;
v_15060:
    v_15091 = stack[-3];
    goto v_15061;
v_15062:
    goto v_15058;
v_15059:
    goto v_15060;
v_15061:
    v_15091 = cons(v_15092, v_15091);
    env = stack[-4];
    stack[-3] = v_15091;
    v_15091 = stack[-1];
    v_15091 = add1(v_15091);
    env = stack[-4];
    stack[-1] = v_15091;
    goto v_15041;
    v_15091 = nil;
    return onevalue(v_15091);
}



// Code for mksetq

static LispObject CC_mksetq(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15092, v_15093, v_15094, v_15095;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15034,v_15035);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15093 = v_15035;
    v_15094 = v_15034;
// end of prologue
    v_15092 = v_15094;
    if (!consp(v_15092)) goto v_15039;
    else goto v_15040;
v_15039:
    goto v_15049;
v_15043:
    v_15092 = elt(env, 1); // setq
    goto v_15044;
v_15045:
    goto v_15046;
v_15047:
    goto v_15048;
v_15049:
    goto v_15043;
v_15044:
    goto v_15045;
v_15046:
    goto v_15047;
v_15048:
    return list3(v_15092, v_15094, v_15093);
v_15040:
    goto v_15067;
v_15063:
    v_15092 = v_15094;
    v_15095 = qcar(v_15092);
    goto v_15064;
v_15065:
    v_15092 = elt(env, 2); // setfn
    goto v_15066;
v_15067:
    goto v_15063;
v_15064:
    goto v_15065;
v_15066:
    v_15092 = get(v_15095, v_15092);
    env = stack[0];
    v_15095 = v_15092;
    if (v_15092 == nil) goto v_15061;
    goto v_15078;
v_15072:
    v_15092 = v_15095;
    goto v_15073;
v_15074:
    goto v_15075;
v_15076:
    goto v_15077;
v_15078:
    goto v_15072;
v_15073:
    goto v_15074;
v_15075:
    goto v_15076;
v_15077:
        return Lapply2(nil, 3, v_15092, v_15094, v_15093);
v_15061:
    goto v_15089;
v_15085:
    v_15093 = v_15094;
    goto v_15086;
v_15087:
    v_15092 = elt(env, 3); // "assignment argument"
    goto v_15088;
v_15089:
    goto v_15085;
v_15086:
    goto v_15087;
v_15088:
    fn = elt(env, 4); // typerr
    v_15092 = (*qfn2(fn))(fn, v_15093, v_15092);
    goto v_15059;
v_15059:
    v_15092 = nil;
    goto v_15038;
    v_15092 = nil;
v_15038:
    return onevalue(v_15092);
}



// Code for bndtst

static LispObject CC_bndtst(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15045, v_15046;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15045 = v_15034;
// end of prologue
    goto v_15041;
v_15037:
    fn = elt(env, 2); // abs!:
    v_15046 = (*qfn1(fn))(fn, v_15045);
    env = stack[0];
    goto v_15038;
v_15039:
    v_15045 = qvalue(elt(env, 1)); // tentothetenth!*!*
    goto v_15040;
v_15041:
    goto v_15037;
v_15038:
    goto v_15039;
v_15040:
    {
        fn = elt(env, 3); // greaterp!:
        return (*qfn2(fn))(fn, v_15046, v_15045);
    }
}



// Code for termorder

static LispObject CC_termorder(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15103, v_15104, v_15105;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15034,v_15035);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15035;
    stack[-1] = v_15034;
// end of prologue
    v_15103 = stack[-1];
    if (v_15103 == nil) goto v_15043;
    else goto v_15044;
v_15043:
    goto v_15042;
v_15044:
    v_15103 = stack[-1];
    v_15103 = (LispObject)zerop(v_15103);
    v_15103 = v_15103 ? lisp_true : nil;
    env = stack[-3];
    if (v_15103 == nil) goto v_15048;
    v_15103 = stack[0];
    v_15103 = (LispObject)zerop(v_15103);
    v_15103 = v_15103 ? lisp_true : nil;
    env = stack[-3];
    if (v_15103 == nil) goto v_15048;
    goto v_15042;
v_15048:
    v_15103 = stack[-1];
    v_15103 = (LispObject)zerop(v_15103);
    v_15103 = v_15103 ? lisp_true : nil;
    env = stack[-3];
    if (v_15103 == nil) goto v_15057;
    goto v_15042;
v_15057:
    v_15103 = stack[0];
    v_15103 = (LispObject)zerop(v_15103);
    v_15103 = v_15103 ? lisp_true : nil;
    env = stack[-3];
    if (v_15103 == nil) goto v_15062;
    goto v_15042;
v_15062:
v_15042:
    v_15103 = stack[-1];
    fn = elt(env, 1); // listsum
    v_15103 = (*qfn1(fn))(fn, v_15103);
    env = stack[-3];
    stack[-2] = v_15103;
    v_15103 = stack[0];
    fn = elt(env, 1); // listsum
    v_15103 = (*qfn1(fn))(fn, v_15103);
    env = stack[-3];
    v_15105 = v_15103;
    goto v_15078;
v_15074:
    v_15104 = stack[-2];
    goto v_15075;
v_15076:
    v_15103 = v_15105;
    goto v_15077;
v_15078:
    goto v_15074;
v_15075:
    goto v_15076;
v_15077:
    if (equal(v_15104, v_15103)) goto v_15072;
    else goto v_15073;
v_15072:
    goto v_15086;
v_15082:
    v_15104 = stack[-1];
    goto v_15083;
v_15084:
    v_15103 = stack[0];
    goto v_15085;
v_15086:
    goto v_15082;
v_15083:
    goto v_15084;
v_15085:
    {
        fn = elt(env, 2); // termorder1
        return (*qfn2(fn))(fn, v_15104, v_15103);
    }
v_15073:
    goto v_15096;
v_15092:
    v_15103 = stack[-2];
    goto v_15093;
v_15094:
    v_15104 = v_15105;
    goto v_15095;
v_15096:
    goto v_15092;
v_15093:
    goto v_15094;
v_15095:
    v_15103 = (LispObject)lessp2(v_15103, v_15104);
    v_15103 = v_15103 ? lisp_true : nil;
    if (v_15103 == nil) goto v_15090;
    v_15103 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_15071;
v_15090:
    v_15103 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15071;
    v_15103 = nil;
v_15071:
    return onevalue(v_15103);
}



// Code for lalr_collect_terminals

static LispObject CC_lalr_collect_terminals(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15117, v_15118, v_15119, v_15120;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_15117 = v_15034;
// end of prologue
    v_15120 = nil;
    stack[-2] = v_15117;
v_15042:
    v_15117 = stack[-2];
    if (v_15117 == nil) goto v_15046;
    else goto v_15047;
v_15046:
    goto v_15041;
v_15047:
    v_15117 = stack[-2];
    v_15117 = qcar(v_15117);
    v_15117 = qcdr(v_15117);
    stack[-1] = v_15117;
v_15056:
    v_15117 = stack[-1];
    if (v_15117 == nil) goto v_15061;
    else goto v_15062;
v_15061:
    goto v_15055;
v_15062:
    v_15117 = stack[-1];
    v_15117 = qcar(v_15117);
    v_15117 = qcar(v_15117);
    stack[0] = v_15117;
v_15071:
    v_15117 = stack[0];
    if (v_15117 == nil) goto v_15076;
    else goto v_15077;
v_15076:
    goto v_15070;
v_15077:
    v_15117 = stack[0];
    v_15117 = qcar(v_15117);
    v_15119 = v_15117;
    goto v_15091;
v_15087:
    v_15118 = v_15119;
    goto v_15088;
v_15089:
    v_15117 = v_15120;
    goto v_15090;
v_15091:
    goto v_15087;
v_15088:
    goto v_15089;
v_15090:
    v_15117 = Lmember(nil, v_15118, v_15117);
    if (v_15117 == nil) goto v_15085;
    else goto v_15086;
v_15085:
    goto v_15100;
v_15096:
    v_15117 = v_15119;
    goto v_15097;
v_15098:
    v_15118 = v_15120;
    goto v_15099;
v_15100:
    goto v_15096;
v_15097:
    goto v_15098;
v_15099:
    v_15117 = cons(v_15117, v_15118);
    env = stack[-3];
    v_15120 = v_15117;
    goto v_15084;
v_15086:
v_15084:
    v_15117 = stack[0];
    v_15117 = qcdr(v_15117);
    stack[0] = v_15117;
    goto v_15071;
v_15070:
    v_15117 = stack[-1];
    v_15117 = qcdr(v_15117);
    stack[-1] = v_15117;
    goto v_15056;
v_15055:
    v_15117 = stack[-2];
    v_15117 = qcdr(v_15117);
    stack[-2] = v_15117;
    goto v_15042;
v_15041:
    goto v_15114;
v_15110:
    v_15118 = v_15120;
    goto v_15111;
v_15112:
    v_15117 = qvalue(elt(env, 1)); // nonterminals
    goto v_15113;
v_15114:
    goto v_15110;
v_15111:
    goto v_15112;
v_15113:
    {
        fn = elt(env, 2); // setdiff
        return (*qfn2(fn))(fn, v_15118, v_15117);
    }
    return onevalue(v_15117);
}



// Code for co_new

static LispObject CC_co_new(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15037;
    argcheck(nargs, 0, "co_new");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_15037 = nil;
    return ncons(v_15037);
}



// Code for homogp

static LispObject CC_homogp(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15123, v_15124;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15034;
// end of prologue
    v_15123 = stack[0];
    if (!consp(v_15123)) goto v_15046;
    else goto v_15047;
v_15046:
    v_15123 = lisp_true;
    goto v_15045;
v_15047:
    v_15123 = stack[0];
    v_15123 = qcar(v_15123);
    v_15123 = (consp(v_15123) ? nil : lisp_true);
    goto v_15045;
    v_15123 = nil;
v_15045:
    if (v_15123 == nil) goto v_15043;
    v_15123 = lisp_true;
    goto v_15041;
v_15043:
    v_15123 = stack[0];
    v_15123 = qcar(v_15123);
    if (!consp(v_15123)) goto v_15060;
    else goto v_15061;
v_15060:
    v_15123 = lisp_true;
    goto v_15059;
v_15061:
    v_15123 = stack[0];
    v_15123 = qcar(v_15123);
    v_15123 = qcar(v_15123);
    v_15123 = (consp(v_15123) ? nil : lisp_true);
    goto v_15059;
    v_15123 = nil;
v_15059:
    goto v_15041;
    v_15123 = nil;
v_15041:
    if (v_15123 == nil) goto v_15039;
    v_15123 = nil;
    goto v_15037;
v_15039:
    v_15123 = stack[0];
    v_15123 = qcdr(v_15123);
    v_15123 = qcar(v_15123);
    v_15123 = qcdr(v_15123);
    if (v_15123 == nil) goto v_15072;
    else goto v_15073;
v_15072:
    v_15123 = nil;
    goto v_15037;
v_15073:
    v_15123 = stack[0];
    v_15123 = qcdr(v_15123);
    v_15123 = qcar(v_15123);
    fn = elt(env, 1); // lastnondomain
    v_15123 = (*qfn1(fn))(fn, v_15123);
    env = stack[-2];
    v_15123 = qcdr(v_15123);
    v_15124 = v_15123;
    v_15123 = v_15124;
    if (!consp(v_15123)) goto v_15089;
    else goto v_15090;
v_15089:
    v_15123 = lisp_true;
    goto v_15088;
v_15090:
    v_15123 = v_15124;
    v_15123 = qcar(v_15123);
    v_15123 = (consp(v_15123) ? nil : lisp_true);
    goto v_15088;
    v_15123 = nil;
v_15088:
    if (v_15123 == nil) goto v_15080;
    v_15123 = nil;
    goto v_15037;
v_15080:
    goto v_15105;
v_15101:
    v_15123 = stack[0];
    v_15123 = qcdr(v_15123);
    v_15123 = qcar(v_15123);
    v_15123 = qcar(v_15123);
    v_15123 = qcar(v_15123);
    fn = elt(env, 2); // listsum
    stack[-1] = (*qfn1(fn))(fn, v_15123);
    env = stack[-2];
    goto v_15102;
v_15103:
    v_15123 = stack[0];
    v_15123 = qcdr(v_15123);
    v_15123 = qcar(v_15123);
    fn = elt(env, 1); // lastnondomain
    v_15123 = (*qfn1(fn))(fn, v_15123);
    env = stack[-2];
    v_15123 = qcar(v_15123);
    v_15123 = qcar(v_15123);
    fn = elt(env, 2); // listsum
    v_15123 = (*qfn1(fn))(fn, v_15123);
    goto v_15104;
v_15105:
    goto v_15101;
v_15102:
    goto v_15103;
v_15104:
    if (equal(stack[-1], v_15123)) goto v_15099;
    else goto v_15100;
v_15099:
    v_15123 = lisp_true;
    goto v_15037;
v_15100:
    v_15123 = nil;
    goto v_15037;
    v_15123 = nil;
v_15037:
    return onevalue(v_15123);
}



// Code for bc_2sq

static LispObject CC_bc_2sq(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15037;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15037 = v_15034;
// end of prologue
    return onevalue(v_15037);
}



// Code for atomlis

static LispObject CC_atomlis(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15056, v_15057;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15056 = v_15034;
// end of prologue
v_15033:
    v_15057 = v_15056;
    if (v_15057 == nil) goto v_15038;
    else goto v_15039;
v_15038:
    v_15056 = lisp_true;
    goto v_15037;
v_15039:
    v_15057 = v_15056;
    v_15057 = qcar(v_15057);
    if (!consp(v_15057)) goto v_15046;
    else goto v_15047;
v_15046:
    v_15056 = qcdr(v_15056);
    goto v_15033;
v_15047:
    v_15056 = nil;
    goto v_15045;
    v_15056 = nil;
v_15045:
    goto v_15037;
    v_15056 = nil;
v_15037:
    return onevalue(v_15056);
}



// Code for dip2vdp

static LispObject CC_dip2vdp(LispObject env,
                         LispObject v_15034)
{
    env = qenv(env);
    LispObject v_15100, v_15101;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15034);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_15101 = v_15034;
// end of prologue
    v_15100 = qvalue(elt(env, 1)); // !*groebsubs
    if (v_15100 == nil) goto v_15039;
    v_15100 = v_15101;
    fn = elt(env, 3); // dipsubs2
    v_15100 = (*qfn1(fn))(fn, v_15100);
    env = stack[-3];
    goto v_15037;
v_15039:
    v_15100 = v_15101;
    goto v_15037;
    v_15100 = nil;
v_15037:
    v_15101 = v_15100;
    v_15100 = v_15101;
    if (v_15100 == nil) goto v_15049;
    else goto v_15050;
v_15049:
    goto v_15061;
v_15053:
    stack[-2] = elt(env, 2); // vdp
    goto v_15054;
v_15055:
    stack[-1] = nil;
    goto v_15056;
v_15057:
    v_15100 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 4); // a2bc
    stack[0] = (*qfn1(fn))(fn, v_15100);
    env = stack[-3];
    goto v_15058;
v_15059:
    goto v_15071;
v_15067:
    v_15101 = nil;
    goto v_15068;
v_15069:
    v_15100 = nil;
    goto v_15070;
v_15071:
    goto v_15067;
v_15068:
    goto v_15069;
v_15070:
    v_15100 = list2(v_15101, v_15100);
    goto v_15060;
v_15061:
    goto v_15053;
v_15054:
    goto v_15055;
v_15056:
    goto v_15057;
v_15058:
    goto v_15059;
v_15060:
    {
        LispObject v_15105 = stack[-2];
        LispObject v_15106 = stack[-1];
        LispObject v_15107 = stack[0];
        return list3star(v_15105, v_15106, v_15107, v_15100);
    }
v_15050:
    goto v_15085;
v_15077:
    stack[-2] = elt(env, 2); // vdp
    goto v_15078;
v_15079:
    v_15100 = v_15101;
    stack[-1] = qcar(v_15100);
    goto v_15080;
v_15081:
    v_15100 = v_15101;
    v_15100 = qcdr(v_15100);
    stack[0] = qcar(v_15100);
    goto v_15082;
v_15083:
    goto v_15097;
v_15093:
    goto v_15094;
v_15095:
    v_15100 = nil;
    goto v_15096;
v_15097:
    goto v_15093;
v_15094:
    goto v_15095;
v_15096:
    v_15100 = list2(v_15101, v_15100);
    goto v_15084;
v_15085:
    goto v_15077;
v_15078:
    goto v_15079;
v_15080:
    goto v_15081;
v_15082:
    goto v_15083;
v_15084:
    {
        LispObject v_15108 = stack[-2];
        LispObject v_15109 = stack[-1];
        LispObject v_15110 = stack[0];
        return list3star(v_15108, v_15109, v_15110, v_15100);
    }
    v_15100 = nil;
    return onevalue(v_15100);
}



// Code for contr!-strand

static LispObject CC_contrKstrand(LispObject env,
                         LispObject v_15034, LispObject v_15035)
{
    env = qenv(env);
    LispObject v_15059, v_15060;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15035,v_15034);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15034,v_15035);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15035;
    v_15059 = v_15034;
// end of prologue
v_15039:
    v_15060 = stack[0];
    if (v_15060 == nil) goto v_15042;
    else goto v_15043;
v_15042:
    goto v_15038;
v_15043:
    goto v_15053;
v_15049:
    v_15060 = v_15059;
    goto v_15050;
v_15051:
    v_15059 = stack[0];
    v_15059 = qcar(v_15059);
    goto v_15052;
v_15053:
    goto v_15049;
v_15050:
    goto v_15051;
v_15052:
    fn = elt(env, 1); // contr1!-strand
    v_15059 = (*qfn2(fn))(fn, v_15060, v_15059);
    env = stack[-1];
    v_15060 = stack[0];
    v_15060 = qcdr(v_15060);
    stack[0] = v_15060;
    goto v_15039;
    v_15059 = nil;
v_15038:
    return onevalue(v_15059);
}



// Code for assert_stat1

static LispObject CC_assert_stat1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15142, v_15143;
    LispObject fn;
    argcheck(nargs, 0, "assert_stat1");
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
    stack[0] = nil;
    goto v_15046;
v_15042:
    fn = elt(env, 7); // scan
    v_15143 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_15043;
v_15044:
    v_15142 = elt(env, 1); // !*lpar!*
    goto v_15045;
v_15046:
    goto v_15042;
v_15043:
    goto v_15044;
v_15045:
    if (v_15143 == v_15142) goto v_15041;
    goto v_15055;
v_15051:
    v_15143 = elt(env, 2); // "expecting '(' in assert but found"
    goto v_15052;
v_15053:
    v_15142 = qvalue(elt(env, 3)); // cursym!*
    goto v_15054;
v_15055:
    goto v_15051;
v_15052:
    goto v_15053;
v_15054:
    v_15142 = list2(v_15143, v_15142);
    env = stack[-1];
    fn = elt(env, 8); // rederr
    v_15142 = (*qfn1(fn))(fn, v_15142);
    env = stack[-1];
    goto v_15039;
v_15041:
v_15039:
    goto v_15066;
v_15062:
    fn = elt(env, 7); // scan
    v_15143 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_15063;
v_15064:
    v_15142 = elt(env, 4); // !*rpar!*
    goto v_15065;
v_15066:
    goto v_15062;
v_15063:
    goto v_15064;
v_15065:
    if (v_15143 == v_15142) goto v_15060;
    else goto v_15061;
v_15060:
    v_15142 = nil;
    goto v_15037;
v_15061:
v_15072:
    goto v_15078;
v_15074:
    v_15143 = qvalue(elt(env, 3)); // cursym!*
    goto v_15075;
v_15076:
    v_15142 = stack[0];
    goto v_15077;
v_15078:
    goto v_15074;
v_15075:
    goto v_15076;
v_15077:
    v_15142 = cons(v_15143, v_15142);
    env = stack[-1];
    stack[0] = v_15142;
    fn = elt(env, 7); // scan
    v_15142 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_15094;
v_15090:
    v_15143 = qvalue(elt(env, 3)); // cursym!*
    goto v_15091;
v_15092:
    v_15142 = elt(env, 5); // !*comma!*
    goto v_15093;
v_15094:
    goto v_15090;
v_15091:
    goto v_15092;
v_15093:
    if (v_15143 == v_15142) goto v_15089;
    goto v_15102;
v_15098:
    v_15143 = qvalue(elt(env, 3)); // cursym!*
    goto v_15099;
v_15100:
    v_15142 = elt(env, 4); // !*rpar!*
    goto v_15101;
v_15102:
    goto v_15098;
v_15099:
    goto v_15100;
v_15101:
    v_15142 = Lneq(nil, v_15143, v_15142);
    env = stack[-1];
    goto v_15087;
v_15089:
    v_15142 = nil;
    goto v_15087;
    v_15142 = nil;
v_15087:
    if (v_15142 == nil) goto v_15085;
    goto v_15114;
v_15110:
    v_15143 = elt(env, 6); // "expecting ',' or ')' in assert but found"
    goto v_15111;
v_15112:
    v_15142 = qvalue(elt(env, 3)); // cursym!*
    goto v_15113;
v_15114:
    goto v_15110;
v_15111:
    goto v_15112;
v_15113:
    v_15142 = list2(v_15143, v_15142);
    env = stack[-1];
    fn = elt(env, 8); // rederr
    v_15142 = (*qfn1(fn))(fn, v_15142);
    env = stack[-1];
    goto v_15083;
v_15085:
v_15083:
    goto v_15125;
v_15121:
    v_15143 = qvalue(elt(env, 3)); // cursym!*
    goto v_15122;
v_15123:
    v_15142 = elt(env, 5); // !*comma!*
    goto v_15124;
v_15125:
    goto v_15121;
v_15122:
    goto v_15123;
v_15124:
    if (v_15143 == v_15142) goto v_15119;
    else goto v_15120;
v_15119:
    fn = elt(env, 7); // scan
    v_15142 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_15118;
v_15120:
v_15118:
    goto v_15137;
v_15133:
    v_15143 = qvalue(elt(env, 3)); // cursym!*
    goto v_15134;
v_15135:
    v_15142 = elt(env, 4); // !*rpar!*
    goto v_15136;
v_15137:
    goto v_15133;
v_15134:
    goto v_15135;
v_15136:
    if (v_15143 == v_15142) goto v_15132;
    goto v_15072;
v_15132:
    v_15142 = stack[0];
        return Lnreverse(nil, v_15142);
v_15037:
    return onevalue(v_15142);
}



// Code for nf

static LispObject CC_nf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15327, v_15328, v_15329;
    LispObject fn;
    LispObject v_15037, v_15036, v_15035;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "nf");
    va_start(aa, nargs);
    v_15035 = va_arg(aa, LispObject);
    v_15036 = va_arg(aa, LispObject);
    v_15037 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15037,v_15036,v_15035);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15035,v_15036,v_15037);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_15037;
    v_15327 = v_15036;
    v_15328 = v_15035;
// end of prologue
// Binding gg!*
// FLUIDBIND: reloadenv=11 litvec-offset=1 saveloc=10
{   bind_fluid_stack bind_fluid_var(-11, 1, -10);
    qvalue(elt(env, 1)) = v_15327; // gg!*
    v_15327 = qvalue(elt(env, 1)); // gg!*
    if (v_15327 == nil) goto v_15045;
    else goto v_15046;
v_15045:
    v_15327 = v_15328;
    goto v_15044;
v_15046:
    stack[-3] = nil;
    v_15327 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_15327;
    v_15327 = v_15328;
    stack[-8] = v_15327;
    v_15327 = qvalue(elt(env, 1)); // gg!*
    stack[-2] = v_15327;
v_15064:
    v_15327 = stack[-8];
    if (v_15327 == nil) goto v_15071;
    else goto v_15072;
v_15071:
    goto v_15065;
v_15072:
    v_15327 = stack[-8];
    v_15327 = qcar(v_15327);
    v_15327 = qcar(v_15327);
    stack[-7] = v_15327;
v_15079:
    v_15327 = stack[-2];
    if (v_15327 == nil) goto v_15087;
    goto v_15094;
v_15090:
    v_15328 = stack[-7];
    goto v_15091;
v_15092:
    v_15327 = stack[-2];
    v_15327 = qcar(v_15327);
    v_15327 = qcdr(v_15327);
    goto v_15093;
v_15094:
    goto v_15090;
v_15091:
    goto v_15092;
v_15093:
    fn = elt(env, 12); // dless
    v_15327 = (*qfn2(fn))(fn, v_15328, v_15327);
    env = stack[-11];
    goto v_15085;
v_15087:
    v_15327 = nil;
    goto v_15085;
    v_15327 = nil;
v_15085:
    if (v_15327 == nil) goto v_15082;
    else goto v_15083;
v_15082:
    goto v_15078;
v_15083:
    v_15327 = stack[-2];
    v_15327 = qcdr(v_15327);
    stack[-2] = v_15327;
    goto v_15079;
v_15078:
    v_15327 = stack[-2];
    if (v_15327 == nil) goto v_15107;
    else goto v_15108;
v_15107:
    goto v_15065;
v_15108:
    v_15327 = stack[-2];
    stack[-1] = v_15327;
v_15113:
    v_15327 = stack[-1];
    if (v_15327 == nil) goto v_15116;
    goto v_15125;
v_15121:
    goto v_15131;
v_15127:
    v_15327 = stack[-1];
    v_15327 = qcar(v_15327);
    v_15328 = qcdr(v_15327);
    goto v_15128;
v_15129:
    v_15327 = stack[-7];
    goto v_15130;
v_15131:
    goto v_15127;
v_15128:
    goto v_15129;
v_15130:
    fn = elt(env, 13); // dd
    stack[-4] = (*qfn2(fn))(fn, v_15328, v_15327);
    env = stack[-11];
    goto v_15122;
v_15123:
    goto v_15141;
v_15137:
    v_15328 = stack[-9];
    goto v_15138;
v_15139:
    v_15327 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_15140;
v_15141:
    goto v_15137;
v_15138:
    goto v_15139;
v_15140:
    v_15327 = plus2(v_15328, v_15327);
    env = stack[-11];
    goto v_15124;
v_15125:
    goto v_15121;
v_15122:
    goto v_15123;
v_15124:
    if (((intptr_t)(stack[-4])) < ((intptr_t)(v_15327))) goto v_15120;
    else goto v_15116;
v_15120:
    goto v_15117;
v_15116:
    goto v_15112;
v_15117:
    v_15327 = stack[-1];
    v_15327 = qcdr(v_15327);
    stack[-1] = v_15327;
    goto v_15113;
v_15112:
    v_15327 = stack[-1];
    if (v_15327 == nil) goto v_15149;
    else goto v_15150;
v_15149:
    v_15327 = qvalue(elt(env, 2)); // redtails
    if (v_15327 == nil) goto v_15155;
    goto v_15164;
v_15158:
    v_15329 = stack[-7];
    goto v_15159;
v_15160:
    v_15327 = stack[-8];
    v_15327 = qcar(v_15327);
    v_15328 = qcdr(v_15327);
    goto v_15161;
v_15162:
    v_15327 = stack[-3];
    goto v_15163;
v_15164:
    goto v_15158;
v_15159:
    goto v_15160;
v_15161:
    goto v_15162;
v_15163:
    v_15327 = acons(v_15329, v_15328, v_15327);
    env = stack[-11];
    stack[-3] = v_15327;
    v_15327 = stack[-8];
    v_15327 = qcdr(v_15327);
    stack[-8] = v_15327;
    goto v_15153;
v_15155:
    goto v_15065;
v_15153:
    goto v_15148;
v_15150:
    goto v_15180;
v_15176:
    v_15328 = qvalue(elt(env, 3)); // gv!*
    goto v_15177;
v_15178:
    v_15327 = stack[-1];
    v_15327 = qcar(v_15327);
    v_15327 = qcar(v_15327);
    goto v_15179;
v_15180:
    goto v_15176;
v_15177:
    goto v_15178;
v_15179:
    v_15327 = *(LispObject *)((char *)v_15328 + (CELL-TAG_VECTOR) + (((intptr_t)v_15327-TAG_FIXNUM)/(16/CELL)));
    stack[-6] = v_15327;
    goto v_15191;
v_15187:
    v_15327 = stack[-8];
    v_15327 = qcar(v_15327);
    v_15328 = qcdr(v_15327);
    goto v_15188;
v_15189:
    v_15327 = stack[-6];
    v_15327 = qcar(v_15327);
    v_15327 = qcdr(v_15327);
    goto v_15190;
v_15191:
    goto v_15187;
v_15188:
    goto v_15189;
v_15190:
    fn = elt(env, 14); // gcdf!*
    v_15327 = (*qfn2(fn))(fn, v_15328, v_15327);
    env = stack[-11];
    stack[-4] = v_15327;
    goto v_15203;
v_15199:
    v_15327 = stack[-8];
    v_15327 = qcar(v_15327);
    v_15328 = qcdr(v_15327);
    goto v_15200;
v_15201:
    v_15327 = stack[-4];
    goto v_15202;
v_15203:
    goto v_15199;
v_15200:
    goto v_15201;
v_15202:
    fn = elt(env, 15); // cdiv
    v_15327 = (*qfn2(fn))(fn, v_15328, v_15327);
    env = stack[-11];
    stack[-5] = v_15327;
    goto v_15213;
v_15209:
    v_15327 = stack[-6];
    v_15327 = qcar(v_15327);
    v_15328 = qcdr(v_15327);
    goto v_15210;
v_15211:
    v_15327 = stack[-4];
    goto v_15212;
v_15213:
    goto v_15209;
v_15210:
    goto v_15211;
v_15212:
    fn = elt(env, 15); // cdiv
    v_15327 = (*qfn2(fn))(fn, v_15328, v_15327);
    env = stack[-11];
    stack[-4] = v_15327;
    goto v_15223;
v_15219:
    v_15328 = stack[-8];
    goto v_15220;
v_15221:
    v_15327 = stack[-4];
    goto v_15222;
v_15223:
    goto v_15219;
v_15220:
    goto v_15221;
v_15222:
    fn = elt(env, 16); // pcmult
    v_15327 = (*qfn2(fn))(fn, v_15328, v_15327);
    env = stack[-11];
    stack[-8] = v_15327;
    goto v_15231;
v_15227:
    v_15328 = stack[-3];
    goto v_15228;
v_15229:
    v_15327 = stack[-4];
    goto v_15230;
v_15231:
    goto v_15227;
v_15228:
    goto v_15229;
v_15230:
    fn = elt(env, 16); // pcmult
    v_15327 = (*qfn2(fn))(fn, v_15328, v_15327);
    env = stack[-11];
    stack[-3] = v_15327;
    goto v_15239;
v_15235:
    v_15328 = stack[-6];
    goto v_15236;
v_15237:
    v_15327 = stack[-5];
    goto v_15238;
v_15239:
    goto v_15235;
v_15236:
    goto v_15237;
v_15238:
    fn = elt(env, 16); // pcmult
    v_15327 = (*qfn2(fn))(fn, v_15328, v_15327);
    env = stack[-11];
    stack[-6] = v_15327;
    goto v_15247;
v_15243:
    v_15327 = stack[-6];
    stack[-4] = qcdr(v_15327);
    goto v_15244;
v_15245:
    goto v_15255;
v_15251:
    v_15328 = stack[-7];
    goto v_15252;
v_15253:
    v_15327 = stack[-1];
    v_15327 = qcar(v_15327);
    v_15327 = qcdr(v_15327);
    goto v_15254;
v_15255:
    goto v_15251;
v_15252:
    goto v_15253;
v_15254:
    fn = elt(env, 17); // dquot
    v_15327 = (*qfn2(fn))(fn, v_15328, v_15327);
    env = stack[-11];
    goto v_15246;
v_15247:
    goto v_15243;
v_15244:
    goto v_15245;
v_15246:
    fn = elt(env, 18); // pdmult
    v_15327 = (*qfn2(fn))(fn, stack[-4], v_15327);
    env = stack[-11];
    stack[-4] = v_15327;
    v_15327 = qvalue(elt(env, 4)); // tred
    if (v_15327 == nil) goto v_15263;
    v_15327 = Lterpri(nil, 0);
    env = stack[-11];
    v_15327 = elt(env, 5); // "r e d u c t i o n :  "
    v_15327 = Lprinc(nil, v_15327);
    env = stack[-11];
    v_15327 = stack[-7];
    v_15327 = Lprinc(nil, v_15327);
    env = stack[-11];
    v_15327 = elt(env, 6); // "/"
    v_15327 = Lprinc(nil, v_15327);
    env = stack[-11];
    v_15327 = stack[-1];
    v_15327 = qcar(v_15327);
    v_15327 = qcdr(v_15327);
    v_15327 = Lprinc(nil, v_15327);
    env = stack[-11];
    v_15327 = Lterpri(nil, 0);
    env = stack[-11];
    goto v_15261;
v_15263:
v_15261:
    v_15327 = qvalue(elt(env, 7)); // stars
    if (v_15327 == nil) goto v_15282;
    v_15327 = elt(env, 8); // "*"
    v_15327 = Lprinc(nil, v_15327);
    env = stack[-11];
    goto v_15280;
v_15282:
v_15280:
    v_15327 = stack[0];
    v_15327 = (LispObject)((intptr_t)(v_15327) + 0x10);
    stack[0] = v_15327;
    goto v_15294;
v_15290:
    v_15327 = stack[-8];
    v_15328 = qcdr(v_15327);
    goto v_15291;
v_15292:
    v_15327 = stack[-4];
    goto v_15293;
v_15294:
    goto v_15290;
v_15291:
    goto v_15292;
v_15293:
    fn = elt(env, 19); // pdif
    v_15327 = (*qfn2(fn))(fn, v_15328, v_15327);
    env = stack[-11];
    stack[-8] = v_15327;
    goto v_15148;
v_15148:
    goto v_15064;
v_15065:
    goto v_15303;
v_15299:
    v_15328 = qvalue(elt(env, 9)); // reductions!*
    goto v_15300;
v_15301:
    v_15327 = stack[0];
    goto v_15302;
v_15303:
    goto v_15299;
v_15300:
    goto v_15301;
v_15302:
    v_15327 = (LispObject)(intptr_t)((intptr_t)v_15328 + (intptr_t)v_15327 - TAG_FIXNUM);
    qvalue(elt(env, 9)) = v_15327; // reductions!*
    v_15327 = qvalue(elt(env, 10)); // nforms!*
    v_15327 = (LispObject)((intptr_t)(v_15327) + 0x10);
    qvalue(elt(env, 10)) = v_15327; // nforms!*
    goto v_15315;
v_15311:
    v_15327 = stack[-3];
    v_15328 = Lnreverse(nil, v_15327);
    env = stack[-11];
    goto v_15312;
v_15313:
    v_15327 = stack[-8];
    goto v_15314;
v_15315:
    goto v_15311;
v_15312:
    goto v_15313;
v_15314:
    v_15327 = Lappend(nil, v_15328, v_15327);
    env = stack[-11];
    fn = elt(env, 20); // gcdout
    v_15327 = (*qfn1(fn))(fn, v_15327);
    env = stack[-11];
    stack[-4] = v_15327;
    v_15327 = stack[-4];
    if (v_15327 == nil) goto v_15321;
    else goto v_15322;
v_15321:
    v_15327 = qvalue(elt(env, 11)); // zeros!*
    v_15327 = (LispObject)((intptr_t)(v_15327) + 0x10);
    qvalue(elt(env, 11)) = v_15327; // zeros!*
    goto v_15320;
v_15322:
v_15320:
    v_15327 = stack[-4];
    goto v_15044;
    v_15327 = nil;
v_15044:
    ;}  // end of a binding scope
    return onevalue(v_15327);
}



setup_type const u27_setup[] =
{
    {"string-of-list",          CC_stringKofKlist,TOO_MANY_1,  WRONG_NO_1},
    {"yylex",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_yylex},
    {"gcref_remprops",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gcref_remprops},
    {"ofsf_smmkatl",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smmkatl},
    {"talp_subat",              TOO_FEW_2,      CC_talp_subat, WRONG_NO_2},
    {"vsl_subatsq",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vsl_subatsq},
    {"unaryir",                 TOO_FEW_2,      CC_unaryir,    WRONG_NO_2},
    {"rootextractsq",           CC_rootextractsq,TOO_MANY_1,   WRONG_NO_1},
    {"can_be_proved",           TOO_FEW_2,      CC_can_be_proved,WRONG_NO_2},
    {"extract_dummy_ids",       CC_extract_dummy_ids,TOO_MANY_1,WRONG_NO_1},
    {"evaluate-mod-p",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_evaluateKmodKp},
    {"hasarg",                  TOO_FEW_2,      CC_hasarg,     WRONG_NO_2},
    {"createtriplewithancestor",TOO_FEW_2,      CC_createtriplewithancestor,WRONG_NO_2},
    {"ofsf_negateat",           CC_ofsf_negateat,TOO_MANY_1,   WRONG_NO_1},
    {"get-free-form",           CC_getKfreeKform,TOO_MANY_1,   WRONG_NO_1},
    {"matpri",                  CC_matpri,      TOO_MANY_1,    WRONG_NO_1},
    {"talp_telp",               TOO_FEW_2,      CC_talp_telp,  WRONG_NO_2},
    {"fctrf1",                  CC_fctrf1,      TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_updsigndom",         CC_ofsf_updsigndom,TOO_MANY_1, WRONG_NO_1},
    {"oldmtch",                 TOO_FEW_2,      CC_oldmtch,    WRONG_NO_2},
    {"indxchk",                 CC_indxchk,     TOO_MANY_1,    WRONG_NO_1},
    {"edge_new_parent",         CC_edge_new_parent,TOO_MANY_1, WRONG_NO_1},
    {"pcdiv",                   TOO_FEW_2,      CC_pcdiv,      WRONG_NO_2},
    {"sc_rep",                  CC_sc_rep,      TOO_MANY_1,    WRONG_NO_1},
    {"gcd-in-vector",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gcdKinKvector},
    {"lalr_most_common_dest",   CC_lalr_most_common_dest,TOO_MANY_1,WRONG_NO_1},
    {"get_char_value",          TOO_FEW_2,      CC_get_char_value,WRONG_NO_2},
    {"aex_mvartest",            TOO_FEW_2,      CC_aex_mvartest,WRONG_NO_2},
    {"multi_args",              CC_multi_args,  TOO_MANY_1,    WRONG_NO_1},
    {"n_nary",                  TOO_FEW_2,      CC_n_nary,     WRONG_NO_2},
    {"gcd2",                    TOO_FEW_2,      CC_gcd2,       WRONG_NO_2},
    {"meq",                     TOO_FEW_2,      CC_meq,        WRONG_NO_2},
    {"gcompatible",             TOO_FEW_2,      CC_gcompatible,WRONG_NO_2},
    {"groebnormalform",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_groebnormalform},
    {"memqcar",                 TOO_FEW_2,      CC_memqcar,    WRONG_NO_2},
    {"equalreval",              CC_equalreval,  TOO_MANY_1,    WRONG_NO_1},
    {"log_assignment_list",     TOO_FEW_2,      CC_log_assignment_list,WRONG_NO_2},
    {"red=subst1",              TOO_FEW_2,      CC_redMsubst1, WRONG_NO_2},
    {"insert",                  TOO_FEW_2,      CC_insert,     WRONG_NO_2},
    {"dv_cambhead",             CC_dv_cambhead, TOO_MANY_1,    WRONG_NO_1},
    {"lalr_make_compressed_action_table",WRONG_NO_NA,WRONG_NO_NB,(n_args *)CC_lalr_make_compressed_action_table},
    {"ifstat",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ifstat},
    {"opmtchrevop",             CC_opmtchrevop, TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_optsubstat",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_optsubstat},
    {"lambdavar",               CC_lambdavar,   TOO_MANY_1,    WRONG_NO_1},
    {"rowdel",                  CC_rowdel,      TOO_MANY_1,    WRONG_NO_1},
    {"bfplusn",                 TOO_FEW_2,      CC_bfplusn,    WRONG_NO_2},
    {"fortranname",             CC_fortranname, TOO_MANY_1,    WRONG_NO_1},
    {"mk-numr",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mkKnumr},
    {"mksetq",                  TOO_FEW_2,      CC_mksetq,     WRONG_NO_2},
    {"bndtst",                  CC_bndtst,      TOO_MANY_1,    WRONG_NO_1},
    {"termorder",               TOO_FEW_2,      CC_termorder,  WRONG_NO_2},
    {"lalr_collect_terminals",  CC_lalr_collect_terminals,TOO_MANY_1,WRONG_NO_1},
    {"co_new",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_co_new},
    {"homogp",                  CC_homogp,      TOO_MANY_1,    WRONG_NO_1},
    {"bc_2sq",                  CC_bc_2sq,      TOO_MANY_1,    WRONG_NO_1},
    {"atomlis",                 CC_atomlis,     TOO_MANY_1,    WRONG_NO_1},
    {"dip2vdp",                 CC_dip2vdp,     TOO_MANY_1,    WRONG_NO_1},
    {"contr-strand",            TOO_FEW_2,      CC_contrKstrand,WRONG_NO_2},
    {"assert_stat1",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_assert_stat1},
    {"nf",                      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_nf},
    {NULL, (one_args *)"u27", (two_args *)"2315 7805745 7549231", 0}
};

// end of generated code
