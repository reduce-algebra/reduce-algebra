
// $destdir/u12.c        Machine generated C code

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



// Code for convertmode1

static LispObject CC_convertmode1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6062, v_6063, v_6064, v_6065, v_6066, v_6067, v_6068;
    LispObject fn;
    LispObject v_5933, v_5932, v_5931, v_5930;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "convertmode1");
    va_start(aa, nargs);
    v_5930 = va_arg(aa, LispObject);
    v_5931 = va_arg(aa, LispObject);
    v_5932 = va_arg(aa, LispObject);
    v_5933 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_5933,v_5932,v_5931,v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_5930,v_5931,v_5932,v_5933);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_6064 = v_5933;
    v_6065 = v_5932;
    v_6066 = v_5931;
    v_6067 = v_5930;
// end of prologue
    goto v_5947;
v_5943:
    v_6063 = v_6064;
    goto v_5944;
v_5945:
    v_6062 = elt(env, 2); // real
    goto v_5946;
v_5947:
    goto v_5943;
v_5944:
    goto v_5945;
v_5946:
    if (v_6063 == v_6062) goto v_5941;
    else goto v_5942;
v_5941:
    v_6062 = elt(env, 3); // algebraic
    v_6064 = v_6062;
    goto v_5940;
v_5942:
v_5940:
    goto v_5959;
v_5955:
    v_6063 = v_6065;
    goto v_5956;
v_5957:
    v_6062 = elt(env, 2); // real
    goto v_5958;
v_5959:
    goto v_5955;
v_5956:
    goto v_5957;
v_5958:
    if (v_6063 == v_6062) goto v_5953;
    else goto v_5954;
v_5953:
    v_6062 = elt(env, 3); // algebraic
    v_6065 = v_6062;
    goto v_5952;
v_5954:
v_5952:
    goto v_5971;
v_5967:
    v_6063 = v_6065;
    goto v_5968;
v_5969:
    v_6062 = v_6064;
    goto v_5970;
v_5971:
    goto v_5967;
v_5968:
    goto v_5969;
v_5970:
    if (v_6063 == v_6062) goto v_5965;
    else goto v_5966;
v_5965:
    v_6062 = v_6067;
    goto v_5937;
v_5966:
    v_6062 = v_6067;
    if (symbolp(v_6062)) goto v_5977;
    else goto v_5976;
v_5977:
    goto v_5985;
v_5981:
    v_6063 = v_6067;
    goto v_5982;
v_5983:
    v_6062 = v_6066;
    goto v_5984;
v_5985:
    goto v_5981;
v_5982:
    goto v_5983;
v_5984:
    v_6062 = Latsoc(nil, v_6063, v_6062);
    v_6068 = v_6062;
    if (v_6062 == nil) goto v_5976;
    goto v_5998;
v_5994:
    v_6062 = v_6068;
    v_6063 = qcdr(v_6062);
    goto v_5995;
v_5996:
    v_6062 = elt(env, 4); // (integer scalar real)
    goto v_5997;
v_5998:
    goto v_5994;
v_5995:
    goto v_5996;
v_5997:
    v_6062 = Lmemq(nil, v_6063, v_6062);
    if (v_6062 == nil) goto v_5992;
    else goto v_5993;
v_5992:
    goto v_6007;
v_6003:
    v_6062 = v_6068;
    v_6063 = qcdr(v_6062);
    goto v_6004;
v_6005:
    v_6062 = v_6064;
    goto v_6006;
v_6007:
    goto v_6003;
v_6004:
    goto v_6005;
v_6006:
    v_6062 = (v_6063 == v_6062 ? lisp_true : nil);
    v_6062 = (v_6062 == nil ? lisp_true : nil);
    goto v_5991;
v_5993:
    v_6062 = nil;
    goto v_5991;
    v_6062 = nil;
v_5991:
    if (v_6062 == nil) goto v_5976;
    goto v_6025;
v_6017:
    v_6062 = v_6067;
    goto v_6018;
v_6019:
    v_6063 = v_6066;
    goto v_6020;
v_6021:
    v_6064 = v_6065;
    goto v_6022;
v_6023:
    v_6065 = v_6068;
    v_6065 = qcdr(v_6065);
    goto v_6024;
v_6025:
    goto v_6017;
v_6018:
    goto v_6019;
v_6020:
    goto v_6021;
v_6022:
    goto v_6023;
v_6024:
    {
        fn = elt(env, 5); // convertmode
        return (*qfnn(fn))(fn, 4, v_6062, v_6063, v_6064, v_6065);
    }
v_5976:
    goto v_6038;
v_6034:
    v_6063 = v_6064;
    goto v_6035;
v_6036:
    v_6062 = v_6065;
    goto v_6037;
v_6038:
    goto v_6034;
v_6035:
    goto v_6036;
v_6037:
    v_6062 = get(v_6063, v_6062);
    env = stack[0];
    v_6068 = v_6062;
    if (v_6062 == nil) goto v_6031;
    else goto v_6032;
v_6031:
    goto v_6046;
v_6042:
    v_6062 = v_6064;
    goto v_6043;
v_6044:
    v_6063 = v_6065;
    goto v_6045;
v_6046:
    goto v_6042;
v_6043:
    goto v_6044;
v_6045:
    fn = elt(env, 6); // typerr
    v_6062 = (*qfn2(fn))(fn, v_6062, v_6063);
    goto v_5964;
v_6032:
    goto v_6058;
v_6052:
    v_6062 = v_6068;
    goto v_6053;
v_6054:
    v_6063 = v_6067;
    goto v_6055;
v_6056:
    v_6064 = v_6066;
    goto v_6057;
v_6058:
    goto v_6052;
v_6053:
    goto v_6054;
v_6055:
    goto v_6056;
v_6057:
        return Lapply2(nil, 3, v_6062, v_6063, v_6064);
v_5964:
    v_6062 = nil;
v_5937:
    return onevalue(v_6062);
}



// Code for simp

static LispObject CC_simp(LispObject env,
                         LispObject v_5930)
{
    env = qenv(env);
    LispObject v_6665, v_6666, v_6667;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5930);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_5930;
// end of prologue
    v_6665 = qvalue(elt(env, 1)); // varstack!*
// Binding varstack!*
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
    qvalue(elt(env, 1)) = v_6665; // varstack!*
    stack[-1] = nil;
    v_6665 = stack[-5];
    v_6665 = integerp(v_6665);
    if (v_6665 == nil) goto v_5942;
    goto v_5953;
v_5949:
    v_6666 = stack[-5];
    goto v_5950;
v_5951:
    v_6665 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5952;
v_5953:
    goto v_5949;
v_5950:
    goto v_5951;
v_5952:
    if (v_6666 == v_6665) goto v_5947;
    else goto v_5948;
v_5947:
    goto v_5961;
v_5957:
    v_6666 = nil;
    goto v_5958;
v_5959:
    v_6665 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5960;
v_5961:
    goto v_5957;
v_5958:
    goto v_5959;
v_5960:
    v_6665 = cons(v_6666, v_6665);
    goto v_5937;
v_5948:
    v_6665 = qvalue(elt(env, 3)); // dmode!*
    if (v_6665 == nil) goto v_5964;
    else goto v_5965;
v_5964:
    goto v_5972;
v_5968:
    v_6666 = stack[-5];
    goto v_5969;
v_5970:
    v_6665 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5971;
v_5972:
    goto v_5968;
v_5969:
    goto v_5970;
v_5971:
    v_6665 = cons(v_6666, v_6665);
    goto v_5937;
v_5965:
    goto v_5946;
v_5946:
    goto v_5940;
v_5942:
    goto v_5984;
v_5980:
    v_6666 = stack[-5];
    goto v_5981;
v_5982:
    v_6665 = qvalue(elt(env, 1)); // varstack!*
    goto v_5983;
v_5984:
    goto v_5980;
v_5981:
    goto v_5982;
v_5983:
    v_6665 = Lmember(nil, v_6666, v_6665);
    if (v_6665 == nil) goto v_5979;
    v_6665 = stack[-5];
    fn = elt(env, 23); // recursiveerror
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    goto v_5940;
v_5979:
v_5940:
    goto v_5995;
v_5991:
    v_6666 = stack[-5];
    goto v_5992;
v_5993:
    v_6665 = qvalue(elt(env, 1)); // varstack!*
    goto v_5994;
v_5995:
    goto v_5991;
v_5992:
    goto v_5993;
v_5994:
    v_6665 = cons(v_6666, v_6665);
    env = stack[-7];
    qvalue(elt(env, 1)) = v_6665; // varstack!*
    goto v_6007;
v_6003:
    v_6666 = qvalue(elt(env, 4)); // simpcount!*
    goto v_6004;
v_6005:
    v_6665 = qvalue(elt(env, 5)); // simplimit!*
    goto v_6006;
v_6007:
    goto v_6003;
v_6004:
    goto v_6005;
v_6006:
    v_6665 = (LispObject)greaterp2(v_6666, v_6665);
    v_6665 = v_6665 ? lisp_true : nil;
    env = stack[-7];
    if (v_6665 == nil) goto v_6001;
    v_6665 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 4)) = v_6665; // simpcount!*
    goto v_6018;
v_6012:
    v_6667 = elt(env, 6); // alg
    goto v_6013;
v_6014:
    v_6666 = (LispObject)192+TAG_FIXNUM; // 12
    goto v_6015;
v_6016:
    v_6665 = elt(env, 7); // "Simplification recursion too deep"
    goto v_6017;
v_6018:
    goto v_6012;
v_6013:
    goto v_6014;
v_6015:
    goto v_6016;
v_6017:
    fn = elt(env, 24); // rerror
    v_6665 = (*qfnn(fn))(fn, 3, v_6667, v_6666, v_6665);
    env = stack[-7];
    goto v_5999;
v_6001:
    goto v_6033;
v_6029:
    v_6666 = stack[-5];
    goto v_6030;
v_6031:
    v_6665 = elt(env, 8); // !*sq
    goto v_6032;
v_6033:
    goto v_6029;
v_6030:
    goto v_6031;
v_6032:
    if (!consp(v_6666)) goto v_6027;
    v_6666 = qcar(v_6666);
    if (v_6666 == v_6665) goto v_6026;
    else goto v_6027;
v_6026:
    v_6665 = stack[-5];
    v_6665 = qcdr(v_6665);
    v_6665 = qcdr(v_6665);
    v_6665 = qcar(v_6665);
    if (v_6665 == nil) goto v_6038;
    else goto v_6039;
v_6038:
    v_6665 = nil;
    goto v_6037;
v_6039:
    v_6665 = qvalue(elt(env, 9)); // !*resimp
    v_6665 = (v_6665 == nil ? lisp_true : nil);
    goto v_6037;
    v_6665 = nil;
v_6037:
    goto v_6025;
v_6027:
    v_6665 = nil;
    goto v_6025;
    v_6665 = nil;
v_6025:
    if (v_6665 == nil) goto v_6023;
    v_6665 = stack[-5];
    v_6665 = qcdr(v_6665);
    v_6665 = qcar(v_6665);
    goto v_5937;
v_6023:
    v_6665 = qvalue(elt(env, 10)); // !*uncached
    if (v_6665 == nil) goto v_6059;
    else goto v_6060;
v_6059:
    v_6665 = qvalue(elt(env, 11)); // alglist!*
    v_6665 = qcar(v_6665);
    v_6666 = v_6665;
    if (v_6666 == nil) goto v_6067;
    else goto v_6068;
v_6067:
    v_6665 = nil;
    goto v_6066;
v_6068:
    goto v_6078;
v_6074:
    v_6666 = stack[-5];
    goto v_6075;
v_6076:
    goto v_6077;
v_6078:
    goto v_6074;
v_6075:
    goto v_6076;
v_6077:
    fn = elt(env, 25); // gethash
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    env = stack[-7];
    goto v_6066;
    v_6665 = nil;
v_6066:
    stack[-1] = v_6665;
    goto v_6058;
v_6060:
    v_6665 = nil;
    goto v_6058;
    v_6665 = nil;
v_6058:
    if (v_6665 == nil) goto v_6056;
    v_6665 = stack[-1];
    v_6665 = qcar(v_6665);
    if (v_6665 == nil) goto v_6087;
    v_6665 = lisp_true;
    qvalue(elt(env, 12)) = v_6665; // !*sub2
    goto v_6085;
v_6087:
v_6085:
    v_6665 = stack[-1];
    v_6665 = qcdr(v_6665);
    goto v_5937;
v_6056:
v_5999:
    v_6665 = qvalue(elt(env, 4)); // simpcount!*
    v_6665 = add1(v_6665);
    env = stack[-7];
    qvalue(elt(env, 4)) = v_6665; // simpcount!*
    v_6665 = stack[-5];
    if (!consp(v_6665)) goto v_6097;
    else goto v_6098;
v_6097:
    goto v_6105;
v_6101:
    v_6665 = stack[-5];
    fn = elt(env, 26); // simpatom
    v_6666 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    goto v_6102;
v_6103:
    v_6665 = stack[-5];
    goto v_6104;
v_6105:
    goto v_6101;
v_6102:
    goto v_6103;
v_6104:
    fn = elt(env, 27); // !*ssave
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    goto v_5937;
v_6098:
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    if (symbolp(v_6665)) goto v_6114;
    v_6665 = lisp_true;
    goto v_6112;
v_6114:
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    v_6665 = (v_6665 == nil ? lisp_true : nil);
    goto v_6112;
    v_6665 = nil;
v_6112:
    if (v_6665 == nil) goto v_6110;
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    if (!consp(v_6665)) goto v_6125;
    else goto v_6126;
v_6125:
    goto v_6134;
v_6130:
    v_6665 = stack[-5];
    v_6666 = qcar(v_6665);
    goto v_6131;
v_6132:
    v_6665 = elt(env, 13); // "operator"
    goto v_6133;
v_6134:
    goto v_6130;
v_6131:
    goto v_6132;
v_6133:
    fn = elt(env, 28); // typerr
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    goto v_6124;
v_6126:
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    v_6665 = qcar(v_6665);
    if (symbolp(v_6665)) goto v_6140;
    else goto v_6139;
v_6140:
    goto v_6150;
v_6146:
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    v_6666 = qcar(v_6665);
    goto v_6147;
v_6148:
    v_6665 = elt(env, 14); // name
    goto v_6149;
v_6150:
    goto v_6146;
v_6147:
    goto v_6148;
v_6149:
    v_6665 = get(v_6666, v_6665);
    env = stack[-7];
    stack[-1] = v_6665;
    if (v_6665 == nil) goto v_6139;
    goto v_6160;
v_6156:
    v_6666 = stack[-5];
    goto v_6157;
v_6158:
    v_6665 = stack[-5];
    goto v_6159;
v_6160:
    goto v_6156;
v_6157:
    goto v_6158;
v_6159:
    fn = elt(env, 27); // !*ssave
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    goto v_5937;
v_6139:
    goto v_6174;
v_6170:
    v_6665 = stack[-5];
    v_6666 = qcar(v_6665);
    goto v_6171;
v_6172:
    v_6665 = elt(env, 15); // mat
    goto v_6173;
v_6174:
    goto v_6170;
v_6171:
    goto v_6172;
v_6173:
    if (!consp(v_6666)) goto v_6168;
    v_6666 = qcar(v_6666);
    if (v_6666 == v_6665) goto v_6167;
    else goto v_6168;
v_6167:
    v_6665 = stack[-5];
    v_6665 = qcdr(v_6665);
    fn = elt(env, 29); // revlis
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    stack[-1] = v_6665;
    fn = elt(env, 30); // numlis
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    if (v_6665 == nil) goto v_6180;
    else goto v_6181;
v_6180:
    v_6665 = nil;
    goto v_6179;
v_6181:
    goto v_6193;
v_6189:
    v_6665 = stack[-1];
    v_6666 = Llength(nil, v_6665);
    env = stack[-7];
    goto v_6190;
v_6191:
    v_6665 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_6192;
v_6193:
    goto v_6189;
v_6190:
    goto v_6191;
v_6192:
    v_6665 = (v_6666 == v_6665 ? lisp_true : nil);
    goto v_6179;
    v_6665 = nil;
v_6179:
    goto v_6166;
v_6168:
    v_6665 = nil;
    goto v_6166;
    v_6665 = nil;
v_6166:
    if (v_6665 == nil) goto v_6164;
    goto v_6206;
v_6202:
    goto v_6213;
v_6209:
    goto v_6219;
v_6215:
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    v_6666 = qcdr(v_6665);
    goto v_6216;
v_6217:
    v_6665 = stack[-1];
    v_6665 = qcar(v_6665);
    goto v_6218;
v_6219:
    goto v_6215;
v_6216:
    goto v_6217;
v_6218:
    fn = elt(env, 31); // nth
    v_6666 = (*qfn2(fn))(fn, v_6666, v_6665);
    env = stack[-7];
    goto v_6210;
v_6211:
    v_6665 = stack[-1];
    v_6665 = qcdr(v_6665);
    v_6665 = qcar(v_6665);
    goto v_6212;
v_6213:
    goto v_6209;
v_6210:
    goto v_6211;
v_6212:
    fn = elt(env, 31); // nth
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    env = stack[-7];
    v_6666 = CC_simp(elt(env, 0), v_6665);
    env = stack[-7];
    goto v_6203;
v_6204:
    v_6665 = stack[-5];
    goto v_6205;
v_6206:
    goto v_6202;
v_6203:
    goto v_6204;
v_6205:
    fn = elt(env, 27); // !*ssave
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    goto v_5937;
v_6164:
    goto v_6236;
v_6232:
    v_6666 = stack[-5];
    goto v_6233;
v_6234:
    v_6665 = lisp_true;
    goto v_6235;
v_6236:
    goto v_6232;
v_6233:
    goto v_6234;
v_6235:
    fn = elt(env, 32); // errpri2
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    goto v_6124;
v_6124:
    goto v_6096;
v_6110:
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    if (!symbolp(v_6665)) v_6665 = nil;
    else { v_6665 = qfastgets(v_6665);
           if (v_6665 != nil) { v_6665 = elt(v_6665, 59); // opfn
#ifdef RECORD_GET
             if (v_6665 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v_6665 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v_6665 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v_6665 == SPID_NOPROP) v_6665 = nil; else v_6665 = lisp_true; }}
#endif
    if (v_6665 == nil) goto v_6240;
    v_6665 = stack[-5];
    fn = elt(env, 33); // opfneval
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    stack[-1] = v_6665;
    fn = elt(env, 34); // getrtype
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    v_6666 = v_6665;
    if (v_6665 == nil) goto v_6246;
    else goto v_6247;
v_6246:
    goto v_6256;
v_6252:
    v_6665 = stack[-1];
    fn = elt(env, 35); // simp_without_resimp
    v_6666 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    goto v_6253;
v_6254:
    v_6665 = stack[-5];
    goto v_6255;
v_6256:
    goto v_6252;
v_6253:
    goto v_6254;
v_6255:
    fn = elt(env, 27); // !*ssave
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    goto v_5937;
v_6247:
    goto v_6270;
v_6266:
    goto v_6267;
v_6268:
    v_6665 = elt(env, 16); // yetunknowntype
    goto v_6269;
v_6270:
    goto v_6266;
v_6267:
    goto v_6268;
v_6269:
    if (v_6666 == v_6665) goto v_6264;
    else goto v_6265;
v_6264:
    v_6665 = stack[-1];
    fn = elt(env, 36); // reval
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    stack[-1] = v_6665;
    fn = elt(env, 34); // getrtype
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    v_6665 = (v_6665 == nil ? lisp_true : nil);
    goto v_6263;
v_6265:
    v_6665 = nil;
    goto v_6263;
    v_6665 = nil;
v_6263:
    if (v_6665 == nil) goto v_6261;
    v_6665 = stack[-1];
    v_6665 = CC_simp(elt(env, 0), v_6665);
    goto v_5937;
v_6261:
    goto v_6289;
v_6285:
    v_6666 = stack[-5];
    goto v_6286;
v_6287:
    v_6665 = elt(env, 17); // "scalar"
    goto v_6288;
v_6289:
    goto v_6285;
v_6286:
    goto v_6287;
v_6288:
    fn = elt(env, 28); // typerr
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    goto v_6245;
v_6245:
    goto v_6096;
v_6240:
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    if (!symbolp(v_6665)) v_6665 = nil;
    else { v_6665 = qfastgets(v_6665);
           if (v_6665 != nil) { v_6665 = elt(v_6665, 45); // psopfn
#ifdef RECORD_GET
             if (v_6665 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v_6665 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v_6665 == SPID_NOPROP) v_6665 = nil; }}
#endif
    stack[-1] = v_6665;
    if (v_6665 == nil) goto v_6293;
    goto v_6307;
v_6303:
    stack[0] = stack[-1];
    goto v_6304;
v_6305:
    v_6665 = stack[-5];
    fn = elt(env, 37); // argnochk
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    v_6665 = qcdr(v_6665);
    goto v_6306;
v_6307:
    goto v_6303;
v_6304:
    goto v_6305;
v_6306:
    v_6665 = Lapply1(nil, stack[0], v_6665);
    env = stack[-7];
    stack[-1] = v_6665;
    fn = elt(env, 34); // getrtype
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    if (v_6665 == nil) goto v_6300;
    goto v_6317;
v_6313:
    v_6666 = stack[-5];
    goto v_6314;
v_6315:
    v_6665 = elt(env, 17); // "scalar"
    goto v_6316;
v_6317:
    goto v_6313;
v_6314:
    goto v_6315;
v_6316:
    fn = elt(env, 28); // typerr
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    goto v_6298;
v_6300:
    goto v_6326;
v_6322:
    v_6666 = stack[-1];
    goto v_6323;
v_6324:
    v_6665 = stack[-5];
    goto v_6325;
v_6326:
    goto v_6322;
v_6323:
    goto v_6324;
v_6325:
    if (equal(v_6666, v_6665)) goto v_6320;
    else goto v_6321;
v_6320:
    goto v_6334;
v_6330:
    goto v_6340;
v_6336:
    goto v_6347;
v_6343:
    goto v_6353;
v_6349:
    v_6666 = stack[-1];
    goto v_6350;
v_6351:
    v_6665 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6352;
v_6353:
    goto v_6349;
v_6350:
    goto v_6351;
v_6352:
    fn = elt(env, 38); // to
    v_6666 = (*qfn2(fn))(fn, v_6666, v_6665);
    env = stack[-7];
    goto v_6344;
v_6345:
    v_6665 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6346;
v_6347:
    goto v_6343;
v_6344:
    goto v_6345;
v_6346:
    v_6665 = cons(v_6666, v_6665);
    env = stack[-7];
    v_6666 = ncons(v_6665);
    env = stack[-7];
    goto v_6337;
v_6338:
    v_6665 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6339;
v_6340:
    goto v_6336;
v_6337:
    goto v_6338;
v_6339:
    v_6666 = cons(v_6666, v_6665);
    env = stack[-7];
    goto v_6331;
v_6332:
    v_6665 = stack[-5];
    goto v_6333;
v_6334:
    goto v_6330;
v_6331:
    goto v_6332;
v_6333:
    fn = elt(env, 27); // !*ssave
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    goto v_5937;
v_6321:
    goto v_6366;
v_6362:
    v_6665 = stack[-1];
    fn = elt(env, 35); // simp_without_resimp
    v_6666 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    goto v_6363;
v_6364:
    v_6665 = stack[-5];
    goto v_6365;
v_6366:
    goto v_6362;
v_6363:
    goto v_6364;
v_6365:
    fn = elt(env, 27); // !*ssave
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    goto v_5937;
v_6298:
    goto v_6096;
v_6293:
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    if (!symbolp(v_6665)) v_6665 = nil;
    else { v_6665 = qfastgets(v_6665);
           if (v_6665 != nil) { v_6665 = elt(v_6665, 41); // polyfn
#ifdef RECORD_GET
             if (v_6665 != SPID_NOPROP)
                record_get(elt(fastget_names, 41), 1);
             else record_get(elt(fastget_names, 41), 0),
                v_6665 = nil; }
           else record_get(elt(fastget_names, 41), 0); }
#else
             if (v_6665 == SPID_NOPROP) v_6665 = nil; }}
#endif
    stack[-1] = v_6665;
    if (v_6665 == nil) goto v_6371;
    v_6665 = stack[-5];
    fn = elt(env, 37); // argnochk
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    goto v_6382;
v_6378:
    goto v_6388;
v_6384:
    goto v_6394;
v_6390:
    stack[-4] = stack[-1];
    goto v_6391;
v_6392:
    v_6665 = stack[-5];
    v_6665 = qcdr(v_6665);
    stack[-3] = v_6665;
    v_6665 = stack[-3];
    if (v_6665 == nil) goto v_6406;
    else goto v_6407;
v_6406:
    v_6665 = nil;
    goto v_6400;
v_6407:
    v_6665 = stack[-3];
    v_6665 = qcar(v_6665);
    fn = elt(env, 39); // simp!*
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    fn = elt(env, 40); // !*q2f
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    v_6665 = ncons(v_6665);
    env = stack[-7];
    stack[-1] = v_6665;
    stack[-2] = v_6665;
v_6401:
    v_6665 = stack[-3];
    v_6665 = qcdr(v_6665);
    stack[-3] = v_6665;
    v_6665 = stack[-3];
    if (v_6665 == nil) goto v_6421;
    else goto v_6422;
v_6421:
    v_6665 = stack[-2];
    goto v_6400;
v_6422:
    goto v_6430;
v_6426:
    stack[0] = stack[-1];
    goto v_6427;
v_6428:
    v_6665 = stack[-3];
    v_6665 = qcar(v_6665);
    fn = elt(env, 39); // simp!*
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    fn = elt(env, 40); // !*q2f
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    v_6665 = ncons(v_6665);
    env = stack[-7];
    goto v_6429;
v_6430:
    goto v_6426;
v_6427:
    goto v_6428;
v_6429:
    v_6665 = Lrplacd(nil, stack[0], v_6665);
    env = stack[-7];
    v_6665 = stack[-1];
    v_6665 = qcdr(v_6665);
    stack[-1] = v_6665;
    goto v_6401;
v_6400:
    goto v_6393;
v_6394:
    goto v_6390;
v_6391:
    goto v_6392;
v_6393:
    fn = elt(env, 41); // lispapply
    v_6666 = (*qfn2(fn))(fn, stack[-4], v_6665);
    env = stack[-7];
    goto v_6385;
v_6386:
    v_6665 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6387;
v_6388:
    goto v_6384;
v_6385:
    goto v_6386;
v_6387:
    v_6666 = cons(v_6666, v_6665);
    env = stack[-7];
    goto v_6379;
v_6380:
    v_6665 = stack[-5];
    goto v_6381;
v_6382:
    goto v_6378;
v_6379:
    goto v_6380;
v_6381:
    fn = elt(env, 27); // !*ssave
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    goto v_5937;
v_6371:
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    if (!symbolp(v_6665)) v_6665 = nil;
    else { v_6665 = qfastgets(v_6665);
           if (v_6665 != nil) { v_6665 = elt(v_6665, 9); // opmtch
#ifdef RECORD_GET
             if (v_6665 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_6665 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_6665 == SPID_NOPROP) v_6665 = nil; }}
#endif
    if (v_6665 == nil) goto v_6444;
    goto v_6458;
v_6454:
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    if (!symbolp(v_6665)) v_6666 = nil;
    else { v_6666 = qfastgets(v_6665);
           if (v_6666 != nil) { v_6666 = elt(v_6666, 22); // simpfn
#ifdef RECORD_GET
             if (v_6666 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v_6666 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v_6666 == SPID_NOPROP) v_6666 = nil; }}
#endif
    goto v_6455;
v_6456:
    v_6665 = elt(env, 18); // simpiden
    goto v_6457;
v_6458:
    goto v_6454;
v_6455:
    goto v_6456;
v_6457:
    if (v_6666 == v_6665) goto v_6453;
    v_6665 = stack[-5];
    fn = elt(env, 42); // opmtchrevop
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    stack[-1] = v_6665;
    goto v_6451;
v_6453:
    v_6665 = nil;
    goto v_6451;
    v_6665 = nil;
v_6451:
    if (v_6665 == nil) goto v_6444;
    goto v_6473;
v_6469:
    v_6665 = stack[-1];
    v_6666 = CC_simp(elt(env, 0), v_6665);
    env = stack[-7];
    goto v_6470;
v_6471:
    v_6665 = stack[-5];
    goto v_6472;
v_6473:
    goto v_6469;
v_6470:
    goto v_6471;
v_6472:
    fn = elt(env, 27); // !*ssave
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    goto v_5937;
v_6444:
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    if (!symbolp(v_6665)) v_6665 = nil;
    else { v_6665 = qfastgets(v_6665);
           if (v_6665 != nil) { v_6665 = elt(v_6665, 22); // simpfn
#ifdef RECORD_GET
             if (v_6665 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v_6665 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v_6665 == SPID_NOPROP) v_6665 = nil; }}
#endif
    stack[-1] = v_6665;
    if (v_6665 == nil) goto v_6478;
    goto v_6487;
v_6483:
    goto v_6493;
v_6489:
    stack[0] = stack[-1];
    goto v_6490;
v_6491:
    goto v_6507;
v_6503:
    v_6666 = stack[-1];
    goto v_6504;
v_6505:
    v_6665 = elt(env, 18); // simpiden
    goto v_6506;
v_6507:
    goto v_6503;
v_6504:
    goto v_6505;
v_6506:
    if (v_6666 == v_6665) goto v_6501;
    else goto v_6502;
v_6501:
    v_6665 = lisp_true;
    goto v_6500;
v_6502:
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    if (!symbolp(v_6665)) v_6665 = nil;
    else { v_6665 = qfastgets(v_6665);
           if (v_6665 != nil) { v_6665 = elt(v_6665, 62); // full
#ifdef RECORD_GET
             if (v_6665 == SPID_NOPROP)
                record_get(elt(fastget_names, 62), 0),
                v_6665 = nil;
             else record_get(elt(fastget_names, 62), 1),
                v_6665 = lisp_true; }
           else record_get(elt(fastget_names, 62), 0); }
#else
             if (v_6665 == SPID_NOPROP) v_6665 = nil; else v_6665 = lisp_true; }}
#endif
    goto v_6500;
    v_6665 = nil;
v_6500:
    if (v_6665 == nil) goto v_6498;
    v_6665 = stack[-5];
    fn = elt(env, 37); // argnochk
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    goto v_6496;
v_6498:
    v_6665 = stack[-5];
    fn = elt(env, 37); // argnochk
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    v_6665 = qcdr(v_6665);
    goto v_6496;
    v_6665 = nil;
v_6496:
    goto v_6492;
v_6493:
    goto v_6489;
v_6490:
    goto v_6491;
v_6492:
    v_6666 = Lapply1(nil, stack[0], v_6665);
    env = stack[-7];
    goto v_6484;
v_6485:
    v_6665 = stack[-5];
    goto v_6486;
v_6487:
    goto v_6483;
v_6484:
    goto v_6485;
v_6486:
    fn = elt(env, 27); // !*ssave
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    goto v_5937;
v_6478:
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    if (!symbolp(v_6665)) v_6665 = nil;
    else { v_6665 = qfastgets(v_6665);
           if (v_6665 != nil) { v_6665 = elt(v_6665, 2); // rtype
#ifdef RECORD_GET
             if (v_6665 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_6665 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_6665 == SPID_NOPROP) v_6665 = nil; }}
#endif
    stack[-1] = v_6665;
    if (v_6665 == nil) goto v_6525;
    goto v_6536;
v_6532:
    v_6666 = stack[-1];
    goto v_6533;
v_6534:
    v_6665 = elt(env, 19); // getelemfn
    goto v_6535;
v_6536:
    goto v_6532;
v_6533:
    goto v_6534;
v_6535:
    v_6665 = get(v_6666, v_6665);
    env = stack[-7];
    stack[-1] = v_6665;
    if (v_6665 == nil) goto v_6525;
    goto v_6544;
v_6540:
    goto v_6551;
v_6547:
    v_6666 = stack[-1];
    goto v_6548;
v_6549:
    v_6665 = stack[-5];
    goto v_6550;
v_6551:
    goto v_6547;
v_6548:
    goto v_6549;
v_6550:
    v_6665 = Lapply1(nil, v_6666, v_6665);
    env = stack[-7];
    v_6666 = CC_simp(elt(env, 0), v_6665);
    env = stack[-7];
    goto v_6541;
v_6542:
    v_6665 = stack[-5];
    goto v_6543;
v_6544:
    goto v_6540;
v_6541:
    goto v_6542;
v_6543:
    fn = elt(env, 27); // !*ssave
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    goto v_5937;
v_6525:
    goto v_6566;
v_6562:
    v_6665 = stack[-5];
    v_6666 = qcar(v_6665);
    goto v_6563;
v_6564:
    v_6665 = elt(env, 20); // boolean
    goto v_6565;
v_6566:
    goto v_6562;
v_6563:
    goto v_6564;
v_6565:
    v_6665 = Lflagp(nil, v_6666, v_6665);
    env = stack[-7];
    if (v_6665 == nil) goto v_6560;
    v_6665 = lisp_true;
    goto v_6558;
v_6560:
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    if (!symbolp(v_6665)) v_6665 = nil;
    else { v_6665 = qfastgets(v_6665);
           if (v_6665 != nil) { v_6665 = elt(v_6665, 23); // infix
#ifdef RECORD_GET
             if (v_6665 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_6665 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_6665 == SPID_NOPROP) v_6665 = nil; }}
#endif
    goto v_6558;
    v_6665 = nil;
v_6558:
    if (v_6665 == nil) goto v_6556;
    goto v_6581;
v_6577:
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    if (!symbolp(v_6665)) v_6665 = nil;
    else { v_6665 = qfastgets(v_6665);
           if (v_6665 != nil) { v_6665 = elt(v_6665, 37); // prtch
#ifdef RECORD_GET
             if (v_6665 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v_6665 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v_6665 == SPID_NOPROP) v_6665 = nil; }}
#endif
    stack[-1] = v_6665;
    if (v_6665 == nil) goto v_6585;
    v_6665 = stack[-1];
    v_6666 = v_6665;
    goto v_6583;
v_6585:
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    v_6666 = v_6665;
    goto v_6583;
    v_6666 = nil;
v_6583:
    goto v_6578;
v_6579:
    v_6665 = elt(env, 21); // "algebraic operator"
    goto v_6580;
v_6581:
    goto v_6577;
v_6578:
    goto v_6579;
v_6580:
    fn = elt(env, 28); // typerr
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    goto v_6096;
v_6556:
    goto v_6602;
v_6598:
    v_6665 = stack[-5];
    v_6666 = qcar(v_6665);
    goto v_6599;
v_6600:
    v_6665 = elt(env, 22); // nochange
    goto v_6601;
v_6602:
    goto v_6598;
v_6599:
    goto v_6600;
v_6601:
    v_6665 = Lflagp(nil, v_6666, v_6665);
    env = stack[-7];
    if (v_6665 == nil) goto v_6596;
    goto v_6611;
v_6607:
    v_6665 = stack[-5];
    fn = elt(env, 43); // lispeval
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    v_6666 = CC_simp(elt(env, 0), v_6665);
    env = stack[-7];
    goto v_6608;
v_6609:
    v_6665 = stack[-5];
    goto v_6610;
v_6611:
    goto v_6607;
v_6608:
    goto v_6609;
v_6610:
    fn = elt(env, 27); // !*ssave
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    goto v_5937;
v_6596:
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    if (!symbolp(v_6665)) v_6665 = nil;
    else { v_6665 = qfastgets(v_6665);
           if (v_6665 != nil) { v_6665 = elt(v_6665, 45); // psopfn
#ifdef RECORD_GET
             if (v_6665 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v_6665 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v_6665 == SPID_NOPROP) v_6665 = nil; }}
#endif
    if (v_6665 == nil) goto v_6618;
    else goto v_6616;
v_6618:
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    if (!symbolp(v_6665)) v_6665 = nil;
    else { v_6665 = qfastgets(v_6665);
           if (v_6665 != nil) { v_6665 = elt(v_6665, 19); // rtypefn
#ifdef RECORD_GET
             if (v_6665 != SPID_NOPROP)
                record_get(elt(fastget_names, 19), 1);
             else record_get(elt(fastget_names, 19), 0),
                v_6665 = nil; }
           else record_get(elt(fastget_names, 19), 0); }
#else
             if (v_6665 == SPID_NOPROP) v_6665 = nil; }}
#endif
    if (v_6665 == nil) goto v_6622;
    else goto v_6616;
v_6622:
    goto v_6617;
v_6616:
    goto v_6631;
v_6627:
    v_6666 = stack[-5];
    goto v_6628;
v_6629:
    v_6665 = elt(env, 17); // "scalar"
    goto v_6630;
v_6631:
    goto v_6627;
v_6628:
    goto v_6629;
v_6630:
    fn = elt(env, 28); // typerr
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    goto v_6096;
v_6617:
    goto v_6641;
v_6637:
    v_6665 = stack[-5];
    v_6666 = qcar(v_6665);
    goto v_6638;
v_6639:
    v_6665 = elt(env, 13); // "operator"
    goto v_6640;
v_6641:
    goto v_6637;
v_6638:
    goto v_6639;
v_6640:
    fn = elt(env, 44); // redmsg
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    env = stack[-7];
    v_6665 = stack[-5];
    v_6665 = qcar(v_6665);
    fn = elt(env, 45); // mkop
    v_6665 = (*qfn1(fn))(fn, v_6665);
    env = stack[-7];
    goto v_6653;
v_6649:
    v_6666 = stack[-5];
    goto v_6650;
v_6651:
    v_6665 = qvalue(elt(env, 1)); // varstack!*
    goto v_6652;
v_6653:
    goto v_6649;
v_6650:
    goto v_6651;
v_6652:
    v_6665 = Ldelete(nil, v_6666, v_6665);
    env = stack[-7];
    qvalue(elt(env, 1)) = v_6665; // varstack!*
    goto v_6661;
v_6657:
    v_6665 = stack[-5];
    v_6666 = CC_simp(elt(env, 0), v_6665);
    env = stack[-7];
    goto v_6658;
v_6659:
    v_6665 = stack[-5];
    goto v_6660;
v_6661:
    goto v_6657;
v_6658:
    goto v_6659;
v_6660:
    fn = elt(env, 27); // !*ssave
    v_6665 = (*qfn2(fn))(fn, v_6666, v_6665);
    goto v_5937;
v_6096:
    v_6665 = nil;
v_5937:
    ;}  // end of a binding scope
    return onevalue(v_6665);
}



// Code for dp!=mocompare

static LispObject CC_dpMmocompare(LispObject env,
                         LispObject v_5930, LispObject v_5931)
{
    env = qenv(env);
    LispObject v_5950, v_5951;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5931,v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5930,v_5931);
    }
// copy arguments values to proper place
    v_5950 = v_5931;
    v_5951 = v_5930;
// end of prologue
    goto v_5938;
v_5934:
    goto v_5944;
v_5940:
    v_5951 = qcar(v_5951);
    goto v_5941;
v_5942:
    v_5950 = qcar(v_5950);
    goto v_5943;
v_5944:
    goto v_5940;
v_5941:
    goto v_5942;
v_5943:
    fn = elt(env, 1); // mo_compare
    v_5951 = (*qfn2(fn))(fn, v_5951, v_5950);
    goto v_5935;
v_5936:
    v_5950 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5937;
v_5938:
    goto v_5934;
v_5935:
    goto v_5936;
v_5937:
        return Leqn(nil, v_5951, v_5950);
}



// Code for pv_neg

static LispObject CC_pv_neg(LispObject env,
                         LispObject v_5930)
{
    env = qenv(env);
    LispObject v_5966, v_5967, v_5968;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5930);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5930;
// end of prologue
    stack[-1] = nil;
v_5938:
    v_5966 = stack[0];
    if (v_5966 == nil) goto v_5941;
    else goto v_5942;
v_5941:
    goto v_5937;
v_5942:
    goto v_5952;
v_5946:
    v_5966 = stack[0];
    v_5966 = qcar(v_5966);
    v_5966 = qcar(v_5966);
    v_5968 = negate(v_5966);
    env = stack[-2];
    goto v_5947;
v_5948:
    v_5966 = stack[0];
    v_5966 = qcar(v_5966);
    v_5967 = qcdr(v_5966);
    goto v_5949;
v_5950:
    v_5966 = stack[-1];
    goto v_5951;
v_5952:
    goto v_5946;
v_5947:
    goto v_5948;
v_5949:
    goto v_5950;
v_5951:
    v_5966 = acons(v_5968, v_5967, v_5966);
    env = stack[-2];
    stack[-1] = v_5966;
    v_5966 = stack[0];
    v_5966 = qcdr(v_5966);
    stack[0] = v_5966;
    goto v_5938;
v_5937:
    v_5966 = stack[-1];
        return Lnreverse(nil, v_5966);
    return onevalue(v_5966);
}



// Code for ra_budan!-transform

static LispObject CC_ra_budanKtransform(LispObject env,
                         LispObject v_5930)
{
    env = qenv(env);
    LispObject v_6039, v_6040;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5930);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_5930;
// end of prologue
    goto v_5943;
v_5939:
    goto v_5950;
v_5946:
    goto v_5956;
v_5952:
    v_6040 = elt(env, 2); // x
    goto v_5953;
v_5954:
    v_6039 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5955;
v_5956:
    goto v_5952;
v_5953:
    goto v_5954;
v_5955:
    fn = elt(env, 3); // to
    v_6040 = (*qfn2(fn))(fn, v_6040, v_6039);
    env = stack[-4];
    goto v_5947;
v_5948:
    v_6039 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5949;
v_5950:
    goto v_5946;
v_5947:
    goto v_5948;
v_5949:
    v_6039 = cons(v_6040, v_6039);
    env = stack[-4];
    v_6040 = ncons(v_6039);
    env = stack[-4];
    goto v_5940;
v_5941:
    v_6039 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5942;
v_5943:
    goto v_5939;
v_5940:
    goto v_5941;
v_5942:
    fn = elt(env, 4); // addf
    v_6039 = (*qfn2(fn))(fn, v_6040, v_6039);
    env = stack[-4];
    stack[0] = v_6039;
    v_6039 = stack[-2];
    if (!consp(v_6039)) goto v_5967;
    else goto v_5968;
v_5967:
    v_6039 = lisp_true;
    goto v_5966;
v_5968:
    v_6039 = stack[-2];
    v_6039 = qcar(v_6039);
    v_6039 = (consp(v_6039) ? nil : lisp_true);
    goto v_5966;
    v_6039 = nil;
v_5966:
    if (v_6039 == nil) goto v_5964;
    v_6039 = stack[-2];
    goto v_5936;
v_5964:
    v_6039 = stack[-2];
    v_6039 = qcdr(v_6039);
    v_6039 = CC_ra_budanKtransform(elt(env, 0), v_6039);
    env = stack[-4];
    stack[-3] = v_6039;
    v_6039 = stack[-2];
    v_6039 = qcdr(v_6039);
    if (!consp(v_6039)) goto v_5986;
    else goto v_5987;
v_5986:
    v_6039 = lisp_true;
    goto v_5985;
v_5987:
    v_6039 = stack[-2];
    v_6039 = qcdr(v_6039);
    v_6039 = qcar(v_6039);
    v_6039 = (consp(v_6039) ? nil : lisp_true);
    goto v_5985;
    v_6039 = nil;
v_5985:
    if (v_6039 == nil) goto v_5983;
    v_6039 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5981;
v_5983:
    v_6039 = stack[-2];
    v_6039 = qcdr(v_6039);
    v_6039 = qcar(v_6039);
    v_6039 = qcar(v_6039);
    v_6039 = qcdr(v_6039);
    goto v_5981;
    v_6039 = nil;
v_5981:
    goto v_6010;
v_6006:
    v_6040 = stack[-2];
    v_6040 = qcar(v_6040);
    stack[-1] = qcdr(v_6040);
    goto v_6007;
v_6008:
    goto v_6019;
v_6015:
    goto v_6025;
v_6021:
    goto v_6022;
v_6023:
    goto v_6032;
v_6028:
    v_6040 = stack[-2];
    v_6040 = qcar(v_6040);
    v_6040 = qcar(v_6040);
    v_6040 = qcdr(v_6040);
    goto v_6029;
v_6030:
    goto v_6031;
v_6032:
    goto v_6028;
v_6029:
    goto v_6030;
v_6031:
    v_6039 = difference2(v_6040, v_6039);
    env = stack[-4];
    goto v_6024;
v_6025:
    goto v_6021;
v_6022:
    goto v_6023;
v_6024:
    fn = elt(env, 5); // exptf
    v_6040 = (*qfn2(fn))(fn, stack[0], v_6039);
    env = stack[-4];
    goto v_6016;
v_6017:
    v_6039 = stack[-3];
    goto v_6018;
v_6019:
    goto v_6015;
v_6016:
    goto v_6017;
v_6018:
    fn = elt(env, 6); // multf
    v_6039 = (*qfn2(fn))(fn, v_6040, v_6039);
    env = stack[-4];
    goto v_6009;
v_6010:
    goto v_6006;
v_6007:
    goto v_6008;
v_6009:
    {
        LispObject v_6045 = stack[-1];
        fn = elt(env, 4); // addf
        return (*qfn2(fn))(fn, v_6045, v_6039);
    }
v_5936:
    return onevalue(v_6039);
}



// Code for lalr_lr0_itemset_to_lalr_kernel

static LispObject CC_lalr_lr0_itemset_to_lalr_kernel(LispObject env,
                         LispObject v_5930)
{
    env = qenv(env);
    LispObject v_5991, v_5992;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5930);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_5991 = v_5930;
// end of prologue
    stack[-2] = nil;
    stack[-1] = v_5991;
v_5939:
    v_5991 = stack[-1];
    if (v_5991 == nil) goto v_5943;
    else goto v_5944;
v_5943:
    goto v_5938;
v_5944:
    v_5991 = stack[-1];
    v_5991 = qcar(v_5991);
    stack[0] = v_5991;
    goto v_5962;
v_5958:
    v_5991 = stack[0];
    v_5992 = qcar(v_5991);
    goto v_5959;
v_5960:
    v_5991 = elt(env, 2); // !S!'
    goto v_5961;
v_5962:
    goto v_5958;
v_5959:
    goto v_5960;
v_5961:
    if (v_5992 == v_5991) goto v_5956;
    else goto v_5957;
v_5956:
    v_5991 = lisp_true;
    goto v_5955;
v_5957:
    goto v_5974;
v_5970:
    v_5991 = stack[0];
    v_5991 = qcdr(v_5991);
    v_5992 = qcar(v_5991);
    goto v_5971;
v_5972:
    v_5991 = elt(env, 3); // !.
    goto v_5973;
v_5974:
    goto v_5970;
v_5971:
    goto v_5972;
v_5973:
    v_5991 = Lneq(nil, v_5992, v_5991);
    env = stack[-3];
    goto v_5955;
    v_5991 = nil;
v_5955:
    if (v_5991 == nil) goto v_5953;
    goto v_5984;
v_5980:
    v_5991 = stack[0];
    v_5992 = ncons(v_5991);
    env = stack[-3];
    goto v_5981;
v_5982:
    v_5991 = stack[-2];
    goto v_5983;
v_5984:
    goto v_5980;
v_5981:
    goto v_5982;
v_5983:
    v_5991 = cons(v_5992, v_5991);
    env = stack[-3];
    stack[-2] = v_5991;
    goto v_5951;
v_5953:
v_5951:
    v_5991 = stack[-1];
    v_5991 = qcdr(v_5991);
    stack[-1] = v_5991;
    goto v_5939;
v_5938:
    v_5991 = stack[-2];
    return onevalue(v_5991);
}



// Code for monommultiplybyvariable

static LispObject CC_monommultiplybyvariable(LispObject env,
                         LispObject v_5930, LispObject v_5931)
{
    env = qenv(env);
    LispObject v_6028, v_6029;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5931,v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5930,v_5931);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_5931;
    stack[-2] = v_5930;
// end of prologue
    goto v_5941;
v_5937:
    v_6029 = stack[-2];
    goto v_5938;
v_5939:
    v_6028 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5940;
v_5941:
    goto v_5937;
v_5938:
    goto v_5939;
v_5940:
    v_6028 = *(LispObject *)((char *)v_6029 + (CELL-TAG_VECTOR) + (((intptr_t)v_6028-TAG_FIXNUM)/(16/CELL)));
    stack[-3] = v_6028;
v_5947:
    v_6028 = stack[-3];
    v_6028 = qcar(v_6028);
    if (v_6028 == nil) goto v_5950;
    goto v_5961;
v_5957:
    v_6028 = stack[-3];
    v_6029 = qcar(v_6028);
    goto v_5958;
v_5959:
    v_6028 = stack[-1];
    goto v_5960;
v_5961:
    goto v_5957;
v_5958:
    goto v_5959;
v_5960:
    v_6028 = (LispObject)greaterp2(v_6029, v_6028);
    v_6028 = v_6028 ? lisp_true : nil;
    env = stack[-4];
    if (v_6028 == nil) goto v_5950;
    goto v_5951;
v_5950:
    goto v_5946;
v_5951:
    v_6028 = stack[-3];
    v_6028 = qcdr(v_6028);
    stack[-3] = v_6028;
    goto v_5947;
v_5946:
    v_6028 = stack[-3];
    v_6028 = qcar(v_6028);
    if (v_6028 == nil) goto v_5971;
    goto v_5981;
v_5977:
    v_6028 = stack[-3];
    v_6029 = qcar(v_6028);
    goto v_5978;
v_5979:
    v_6028 = stack[-1];
    goto v_5980;
v_5981:
    goto v_5977;
v_5978:
    goto v_5979;
v_5980:
    if (equal(v_6029, v_6028)) goto v_5976;
    else goto v_5971;
v_5976:
    goto v_5972;
v_5971:
    goto v_5990;
v_5986:
    goto v_5996;
v_5992:
    stack[0] = stack[-3];
    goto v_5993;
v_5994:
    goto v_6003;
v_5999:
    v_6028 = stack[-3];
    v_6029 = qcar(v_6028);
    goto v_6000;
v_6001:
    v_6028 = stack[-3];
    v_6028 = qcdr(v_6028);
    goto v_6002;
v_6003:
    goto v_5999;
v_6000:
    goto v_6001;
v_6002:
    v_6028 = cons(v_6029, v_6028);
    env = stack[-4];
    goto v_5995;
v_5996:
    goto v_5992;
v_5993:
    goto v_5994;
v_5995:
    v_6029 = Lrplacd(nil, stack[0], v_6028);
    env = stack[-4];
    goto v_5987;
v_5988:
    v_6028 = stack[-1];
    goto v_5989;
v_5990:
    goto v_5986;
v_5987:
    goto v_5988;
v_5989:
    v_6028 = Lrplaca(nil, v_6029, v_6028);
    env = stack[-4];
    goto v_6015;
v_6009:
    stack[-1] = stack[-2];
    goto v_6010;
v_6011:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6012;
v_6013:
    goto v_6023;
v_6019:
    v_6029 = stack[-2];
    goto v_6020;
v_6021:
    v_6028 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6022;
v_6023:
    goto v_6019;
v_6020:
    goto v_6021;
v_6022:
    v_6028 = *(LispObject *)((char *)v_6029 + (CELL-TAG_VECTOR) + (((intptr_t)v_6028-TAG_FIXNUM)/(16/CELL)));
    v_6028 = add1(v_6028);
    goto v_6014;
v_6015:
    goto v_6009;
v_6010:
    goto v_6011;
v_6012:
    goto v_6013;
v_6014:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_6028;
    goto v_5970;
v_5972:
v_5970:
    v_6028 = nil;
    return onevalue(v_6028);
}



// Code for ordpa

static LispObject CC_ordpa(LispObject env,
                         LispObject v_5930, LispObject v_5931)
{
    env = qenv(env);
    LispObject v_5941, v_5942;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5941 = v_5931;
    v_5942 = v_5930;
// end of prologue
    goto v_5938;
v_5934:
    goto v_5935;
v_5936:
    goto v_5937;
v_5938:
    goto v_5934;
v_5935:
    goto v_5936;
v_5937:
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_5942, v_5941);
    }
}



// Code for totalcompare

static LispObject CC_totalcompare(LispObject env,
                         LispObject v_5930, LispObject v_5931)
{
    env = qenv(env);
    LispObject v_6019, v_6020, v_6021;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5931,v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5930,v_5931);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5931;
    stack[-1] = v_5930;
// end of prologue
v_5929:
    goto v_5941;
v_5937:
    v_6020 = stack[-1];
    goto v_5938;
v_5939:
    v_6019 = stack[0];
    goto v_5940;
v_5941:
    goto v_5937;
v_5938:
    goto v_5939;
v_5940:
    if (equal(v_6020, v_6019)) goto v_5935;
    else goto v_5936;
v_5935:
    v_6019 = elt(env, 1); // equal
    goto v_5934;
v_5936:
    goto v_5952;
v_5948:
    v_6020 = stack[-1];
    goto v_5949;
v_5950:
    v_6019 = stack[0];
    goto v_5951;
v_5952:
    goto v_5948;
v_5949:
    goto v_5950;
v_5951:
    fn = elt(env, 5); // wulessp
    v_6019 = (*qfn2(fn))(fn, v_6020, v_6019);
    env = stack[-2];
    if (v_6019 == nil) goto v_5946;
    v_6019 = elt(env, 2); // less
    goto v_5934;
v_5946:
    goto v_5963;
v_5959:
    v_6020 = stack[0];
    goto v_5960;
v_5961:
    v_6019 = stack[-1];
    goto v_5962;
v_5963:
    goto v_5959;
v_5960:
    goto v_5961;
v_5962:
    fn = elt(env, 5); // wulessp
    v_6019 = (*qfn2(fn))(fn, v_6020, v_6019);
    env = stack[-2];
    if (v_6019 == nil) goto v_5957;
    v_6019 = elt(env, 3); // greater
    goto v_5934;
v_5957:
    v_6019 = stack[-1];
    fn = elt(env, 6); // wuconstantp
    v_6019 = (*qfn1(fn))(fn, v_6019);
    env = stack[-2];
    if (v_6019 == nil) goto v_5968;
    goto v_5976;
v_5972:
    v_6020 = stack[-1];
    goto v_5973;
v_5974:
    v_6019 = stack[0];
    goto v_5975;
v_5976:
    goto v_5972;
v_5973:
    goto v_5974;
v_5975:
    {
        fn = elt(env, 7); // totalcompareconstants
        return (*qfn2(fn))(fn, v_6020, v_6019);
    }
v_5968:
    goto v_5990;
v_5986:
    v_6019 = stack[-1];
    v_6019 = qcar(v_6019);
    v_6020 = qcdr(v_6019);
    goto v_5987;
v_5988:
    v_6019 = stack[0];
    v_6019 = qcar(v_6019);
    v_6019 = qcdr(v_6019);
    goto v_5989;
v_5990:
    goto v_5986;
v_5987:
    goto v_5988;
v_5989:
    v_6019 = CC_totalcompare(elt(env, 0), v_6020, v_6019);
    env = stack[-2];
    v_6021 = v_6019;
    goto v_6005;
v_6001:
    v_6020 = v_6021;
    goto v_6002;
v_6003:
    v_6019 = elt(env, 1); // equal
    goto v_6004;
v_6005:
    goto v_6001;
v_6002:
    goto v_6003;
v_6004:
    if (v_6020 == v_6019) goto v_6000;
    v_6019 = v_6021;
    goto v_5983;
v_6000:
    goto v_6014;
v_6010:
    v_6019 = stack[-1];
    v_6020 = qcdr(v_6019);
    goto v_6011;
v_6012:
    v_6019 = stack[0];
    v_6019 = qcdr(v_6019);
    goto v_6013;
v_6014:
    goto v_6010;
v_6011:
    goto v_6012;
v_6013:
    stack[-1] = v_6020;
    stack[0] = v_6019;
    goto v_5929;
v_5983:
    goto v_5934;
    v_6019 = nil;
v_5934:
    return onevalue(v_6019);
}



// Code for msappend

static LispObject CC_msappend(LispObject env,
                         LispObject v_5930, LispObject v_5931)
{
    env = qenv(env);
    LispObject v_6001, v_6002;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5931,v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5930,v_5931);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_5931;
    v_6001 = v_5930;
// end of prologue
    stack[-5] = v_6001;
    v_6001 = stack[-5];
    if (v_6001 == nil) goto v_5942;
    else goto v_5943;
v_5942:
    v_6001 = nil;
    goto v_5937;
v_5943:
    v_6001 = stack[-5];
    v_6001 = qcar(v_6001);
    goto v_5955;
v_5951:
    stack[0] = stack[-4];
    goto v_5952;
v_5953:
    goto v_5962;
v_5958:
    v_6002 = stack[-4];
    goto v_5959;
v_5960:
    goto v_5961;
v_5962:
    goto v_5958;
v_5959:
    goto v_5960;
v_5961:
    v_6001 = Lsublis(nil, v_6002, v_6001);
    env = stack[-6];
    goto v_5954;
v_5955:
    goto v_5951;
v_5952:
    goto v_5953;
v_5954:
    v_6001 = Lappend(nil, stack[0], v_6001);
    env = stack[-6];
    v_6001 = ncons(v_6001);
    env = stack[-6];
    stack[-2] = v_6001;
    stack[-3] = v_6001;
v_5938:
    v_6001 = stack[-5];
    v_6001 = qcdr(v_6001);
    stack[-5] = v_6001;
    v_6001 = stack[-5];
    if (v_6001 == nil) goto v_5969;
    else goto v_5970;
v_5969:
    v_6001 = stack[-3];
    goto v_5937;
v_5970:
    goto v_5978;
v_5974:
    stack[-1] = stack[-2];
    goto v_5975;
v_5976:
    v_6001 = stack[-5];
    v_6001 = qcar(v_6001);
    goto v_5989;
v_5985:
    stack[0] = stack[-4];
    goto v_5986;
v_5987:
    goto v_5996;
v_5992:
    v_6002 = stack[-4];
    goto v_5993;
v_5994:
    goto v_5995;
v_5996:
    goto v_5992;
v_5993:
    goto v_5994;
v_5995:
    v_6001 = Lsublis(nil, v_6002, v_6001);
    env = stack[-6];
    goto v_5988;
v_5989:
    goto v_5985;
v_5986:
    goto v_5987;
v_5988:
    v_6001 = Lappend(nil, stack[0], v_6001);
    env = stack[-6];
    v_6001 = ncons(v_6001);
    env = stack[-6];
    goto v_5977;
v_5978:
    goto v_5974;
v_5975:
    goto v_5976;
v_5977:
    v_6001 = Lrplacd(nil, stack[-1], v_6001);
    env = stack[-6];
    v_6001 = stack[-2];
    v_6001 = qcdr(v_6001);
    stack[-2] = v_6001;
    goto v_5938;
v_5937:
    return onevalue(v_6001);
}



// Code for rl_smrmknowl

static LispObject CC_rl_smrmknowl(LispObject env,
                         LispObject v_5930, LispObject v_5931)
{
    env = qenv(env);
    LispObject v_5948, v_5949;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5931,v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5930,v_5931);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_5948 = v_5931;
    v_5949 = v_5930;
// end of prologue
    goto v_5938;
v_5934:
    stack[0] = qvalue(elt(env, 1)); // rl_smrmknowl!*
    goto v_5935;
v_5936:
    goto v_5945;
v_5941:
    goto v_5942;
v_5943:
    goto v_5944;
v_5945:
    goto v_5941;
v_5942:
    goto v_5943;
v_5944:
    v_5948 = list2(v_5949, v_5948);
    env = stack[-1];
    goto v_5937;
v_5938:
    goto v_5934;
v_5935:
    goto v_5936;
v_5937:
    {
        LispObject v_5951 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_5951, v_5948);
    }
}



// Code for qsort

static LispObject CC_qsort(LispObject env,
                         LispObject v_5930)
{
    env = qenv(env);
    LispObject v_6008, v_6009;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5930);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_6009 = v_5930;
// end of prologue
    stack[-2] = nil;
    stack[-1] = nil;
    v_6008 = v_6009;
    if (v_6008 == nil) goto v_5943;
    else goto v_5944;
v_5943:
    v_6008 = nil;
    goto v_5937;
v_5944:
    v_6008 = v_6009;
    v_6008 = qcar(v_6008);
    stack[-3] = v_6008;
    v_6008 = v_6009;
    v_6008 = qcdr(v_6008);
    stack[0] = v_6008;
v_5938:
    v_6008 = stack[0];
    if (v_6008 == nil) goto v_5953;
    else goto v_5954;
v_5953:
    goto v_5939;
v_5954:
    goto v_5965;
v_5961:
    v_6009 = stack[-3];
    goto v_5962;
v_5963:
    v_6008 = stack[0];
    v_6008 = qcar(v_6008);
    goto v_5964;
v_5965:
    goto v_5961;
v_5962:
    goto v_5963;
v_5964:
    fn = elt(env, 2); // ordop
    v_6008 = (*qfn2(fn))(fn, v_6009, v_6008);
    env = stack[-4];
    if (v_6008 == nil) goto v_5959;
    goto v_5974;
v_5970:
    v_6008 = stack[0];
    v_6009 = qcar(v_6008);
    goto v_5971;
v_5972:
    v_6008 = stack[-1];
    goto v_5973;
v_5974:
    goto v_5970;
v_5971:
    goto v_5972;
v_5973:
    v_6008 = cons(v_6009, v_6008);
    env = stack[-4];
    stack[-1] = v_6008;
    goto v_5957;
v_5959:
    goto v_5985;
v_5981:
    v_6008 = stack[0];
    v_6009 = qcar(v_6008);
    goto v_5982;
v_5983:
    v_6008 = stack[-2];
    goto v_5984;
v_5985:
    goto v_5981;
v_5982:
    goto v_5983;
v_5984:
    v_6008 = cons(v_6009, v_6008);
    env = stack[-4];
    stack[-2] = v_6008;
    goto v_5957;
v_5957:
    v_6008 = stack[0];
    v_6008 = qcdr(v_6008);
    stack[0] = v_6008;
    goto v_5938;
v_5939:
    goto v_5996;
v_5992:
    v_6008 = stack[-2];
    stack[0] = CC_qsort(elt(env, 0), v_6008);
    env = stack[-4];
    goto v_5993;
v_5994:
    goto v_6004;
v_6000:
    stack[-2] = stack[-3];
    goto v_6001;
v_6002:
    v_6008 = stack[-1];
    v_6008 = CC_qsort(elt(env, 0), v_6008);
    env = stack[-4];
    goto v_6003;
v_6004:
    goto v_6000;
v_6001:
    goto v_6002;
v_6003:
    v_6008 = cons(stack[-2], v_6008);
    goto v_5995;
v_5996:
    goto v_5992;
v_5993:
    goto v_5994;
v_5995:
    {
        LispObject v_6014 = stack[0];
        return Lappend(nil, v_6014, v_6008);
    }
v_5937:
    return onevalue(v_6008);
}



// Code for ibalp_litp

static LispObject CC_ibalp_litp(LispObject env,
                         LispObject v_5930)
{
    env = qenv(env);
    LispObject v_5964, v_5965;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5930);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_5930;
// end of prologue
    v_5964 = stack[0];
    fn = elt(env, 2); // ibalp_atomp
    v_5964 = (*qfn1(fn))(fn, v_5964);
    env = stack[-1];
    if (v_5964 == nil) goto v_5934;
    else goto v_5933;
v_5934:
    goto v_5945;
v_5941:
    v_5964 = stack[0];
    if (!consp(v_5964)) goto v_5948;
    else goto v_5949;
v_5948:
    v_5964 = stack[0];
    v_5965 = v_5964;
    goto v_5947;
v_5949:
    v_5964 = stack[0];
    v_5964 = qcar(v_5964);
    v_5965 = v_5964;
    goto v_5947;
    v_5965 = nil;
v_5947:
    goto v_5942;
v_5943:
    v_5964 = elt(env, 1); // not
    goto v_5944;
v_5945:
    goto v_5941;
v_5942:
    goto v_5943;
v_5944:
    if (v_5965 == v_5964) goto v_5939;
    else goto v_5940;
v_5939:
    v_5964 = stack[0];
    v_5964 = qcdr(v_5964);
    v_5964 = qcar(v_5964);
    {
        fn = elt(env, 2); // ibalp_atomp
        return (*qfn1(fn))(fn, v_5964);
    }
v_5940:
    v_5964 = nil;
    goto v_5938;
    v_5964 = nil;
v_5938:
v_5933:
    return onevalue(v_5964);
}



// Code for comm_kernels1

static LispObject CC_comm_kernels1(LispObject env,
                         LispObject v_5930, LispObject v_5931)
{
    env = qenv(env);
    LispObject v_6001, v_6002;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5931,v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5930,v_5931);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_5931;
    v_6001 = v_5930;
// end of prologue
v_5929:
    v_6002 = v_6001;
    if (!consp(v_6002)) goto v_5939;
    else goto v_5940;
v_5939:
    v_6002 = lisp_true;
    goto v_5938;
v_5940:
    v_6002 = v_6001;
    v_6002 = qcar(v_6002);
    v_6002 = (consp(v_6002) ? nil : lisp_true);
    goto v_5938;
    v_6002 = nil;
v_5938:
    if (v_6002 == nil) goto v_5936;
    v_6001 = stack[-2];
    goto v_5934;
v_5936:
    v_6002 = v_6001;
    v_6002 = qcar(v_6002);
    v_6002 = qcar(v_6002);
    v_6002 = qcar(v_6002);
    stack[-3] = v_6002;
    goto v_5961;
v_5957:
    v_6002 = v_6001;
    v_6002 = qcar(v_6002);
    stack[-1] = qcdr(v_6002);
    goto v_5958;
v_5959:
    goto v_5970;
v_5966:
    stack[0] = qcdr(v_6001);
    goto v_5967;
v_5968:
    goto v_5982;
v_5978:
    v_6002 = stack[-3];
    goto v_5979;
v_5980:
    v_6001 = stack[-2];
    goto v_5981;
v_5982:
    goto v_5978;
v_5979:
    goto v_5980;
v_5981:
    v_6001 = Lmemq(nil, v_6002, v_6001);
    if (v_6001 == nil) goto v_5977;
    else goto v_5975;
v_5977:
    v_6001 = stack[-3];
    fn = elt(env, 1); // noncomp
    v_6001 = (*qfn1(fn))(fn, v_6001);
    env = stack[-4];
    if (v_6001 == nil) goto v_5986;
    else goto v_5975;
v_5986:
    goto v_5976;
v_5975:
    v_6001 = stack[-2];
    goto v_5974;
v_5976:
    goto v_5997;
v_5993:
    goto v_5994;
v_5995:
    v_6001 = stack[-3];
    v_6001 = ncons(v_6001);
    env = stack[-4];
    goto v_5996;
v_5997:
    goto v_5993;
v_5994:
    goto v_5995;
v_5996:
    v_6001 = Lappend(nil, stack[-2], v_6001);
    env = stack[-4];
    goto v_5974;
    v_6001 = nil;
v_5974:
    goto v_5969;
v_5970:
    goto v_5966;
v_5967:
    goto v_5968;
v_5969:
    v_6002 = CC_comm_kernels1(elt(env, 0), stack[0], v_6001);
    env = stack[-4];
    goto v_5960;
v_5961:
    goto v_5957;
v_5958:
    goto v_5959;
v_5960:
    v_6001 = stack[-1];
    stack[-2] = v_6002;
    goto v_5929;
    v_6001 = nil;
v_5934:
    return onevalue(v_6001);
}



// Code for id2bytelist

static LispObject CC_id2bytelist(LispObject env,
                         LispObject v_5930)
{
    env = qenv(env);
    LispObject v_5935;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5930);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_5935 = v_5930;
// end of prologue
    fn = elt(env, 1); // id2string
    v_5935 = (*qfn1(fn))(fn, v_5935);
    env = stack[0];
    {
        fn = elt(env, 2); // string2bytelist
        return (*qfn1(fn))(fn, v_5935);
    }
}



// Code for safe!-fp!-times

static LispObject CC_safeKfpKtimes(LispObject env,
                         LispObject v_5930, LispObject v_5931)
{
    env = qenv(env);
    LispObject v_6025, v_6026;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5931,v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5930,v_5931);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_5931;
    stack[-1] = v_5930;
// end of prologue
    goto v_5942;
v_5938:
    v_6026 = stack[-1];
    goto v_5939;
v_5940:
    v_6025 = stack[0];
    goto v_5941;
v_5942:
    goto v_5938;
v_5939:
    goto v_5940;
v_5941:
    v_6025 = times2(v_6026, v_6025);
    env = stack[-3];
    stack[-2] = v_6025;
    goto v_5955;
v_5951:
    v_6026 = stack[-2];
    goto v_5952;
v_5953:
    v_6025 = qvalue(elt(env, 2)); // !!minnorm
    goto v_5954;
v_5955:
    goto v_5951;
v_5952:
    goto v_5953;
v_5954:
    v_6025 = (LispObject)lessp2(v_6026, v_6025);
    v_6025 = v_6025 ? lisp_true : nil;
    env = stack[-3];
    if (v_6025 == nil) goto v_5948;
    goto v_5965;
v_5961:
    v_6026 = stack[-2];
    goto v_5962;
v_5963:
    v_6025 = qvalue(elt(env, 3)); // !!minnegnorm
    goto v_5964;
v_5965:
    goto v_5961;
v_5962:
    goto v_5963;
v_5964:
    v_6025 = (LispObject)greaterp2(v_6026, v_6025);
    v_6025 = v_6025 ? lisp_true : nil;
    env = stack[-3];
    if (v_6025 == nil) goto v_5948;
    goto v_5977;
v_5973:
    v_6026 = stack[-1];
    goto v_5974;
v_5975:
    v_6025 = elt(env, 4); // 0.0
    goto v_5976;
v_5977:
    goto v_5973;
v_5974:
    goto v_5975;
v_5976:
    if (equal(v_6026, v_6025)) goto v_5972;
    goto v_5985;
v_5981:
    v_6026 = stack[0];
    goto v_5982;
v_5983:
    v_6025 = elt(env, 4); // 0.0
    goto v_5984;
v_5985:
    goto v_5981;
v_5982:
    goto v_5983;
v_5984:
    v_6025 = Lneq(nil, v_6026, v_6025);
    env = stack[-3];
    goto v_5970;
v_5972:
    v_6025 = nil;
    goto v_5970;
    v_6025 = nil;
v_5970:
    if (v_6025 == nil) goto v_5948;
    v_6025 = nil;
    goto v_5935;
v_5948:
    v_6025 = qvalue(elt(env, 5)); // !*nonegzerotimes
    if (v_6025 == nil) goto v_5993;
    goto v_6001;
v_5997:
    v_6026 = stack[-2];
    goto v_5998;
v_5999:
    v_6025 = elt(env, 4); // 0.0
    goto v_6000;
v_6001:
    goto v_5997;
v_5998:
    goto v_5999;
v_6000:
    if (equal(v_6026, v_6025)) goto v_5996;
    else goto v_5993;
v_5996:
    v_6025 = elt(env, 4); // 0.0
    goto v_5935;
v_5993:
    goto v_6011;
v_6007:
    goto v_6017;
v_6013:
    v_6026 = stack[-2];
    goto v_6014;
v_6015:
    v_6025 = stack[-2];
    goto v_6016;
v_6017:
    goto v_6013;
v_6014:
    goto v_6015;
v_6016:
    v_6025 = difference2(v_6026, v_6025);
    env = stack[-3];
    goto v_6008;
v_6009:
    v_6026 = elt(env, 4); // 0.0
    goto v_6010;
v_6011:
    goto v_6007;
v_6008:
    goto v_6009;
v_6010:
    if (equal(v_6025, v_6026)) goto v_6005;
    else goto v_6006;
v_6005:
    v_6025 = stack[-2];
    goto v_5935;
v_6006:
    v_6025 = nil;
    goto v_5935;
    v_6025 = nil;
v_5935:
    return onevalue(v_6025);
}



// Code for contr1!-strand

static LispObject CC_contr1Kstrand(LispObject env,
                         LispObject v_5930, LispObject v_5931)
{
    env = qenv(env);
    LispObject v_5947, v_5948, v_5949, v_5950;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5947 = v_5931;
    v_5948 = v_5930;
// end of prologue
    goto v_5942;
v_5934:
    v_5950 = v_5948;
    goto v_5935;
v_5936:
    v_5949 = v_5947;
    goto v_5937;
v_5938:
    v_5948 = nil;
    goto v_5939;
v_5940:
    v_5947 = nil;
    goto v_5941;
v_5942:
    goto v_5934;
v_5935:
    goto v_5936;
v_5937:
    goto v_5938;
v_5939:
    goto v_5940;
v_5941:
    {
        fn = elt(env, 1); // contr2!-strand
        return (*qfnn(fn))(fn, 4, v_5950, v_5949, v_5948, v_5947);
    }
}



// Code for form1

static LispObject CC_form1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6499, v_6500, v_6501, v_6502;
    LispObject fn;
    LispObject v_5932, v_5931, v_5930;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "form1");
    va_start(aa, nargs);
    v_5930 = va_arg(aa, LispObject);
    v_5931 = va_arg(aa, LispObject);
    v_5932 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_5932,v_5931,v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_5930,v_5931,v_5932);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_5932;
    stack[-2] = v_5931;
    stack[-3] = v_5930;
// end of prologue
v_5929:
    v_6499 = stack[-3];
    if (!consp(v_6499)) goto v_5941;
    else goto v_5942;
v_5941:
    v_6499 = stack[-3];
    if (symbolp(v_6499)) goto v_5947;
    v_6499 = stack[-3];
    goto v_5945;
v_5947:
    goto v_5956;
v_5952:
    v_6500 = stack[-3];
    goto v_5953;
v_5954:
    v_6499 = elt(env, 2); // ed
    goto v_5955;
v_5956:
    goto v_5952;
v_5953:
    goto v_5954;
v_5955:
    if (v_6500 == v_6499) goto v_5950;
    else goto v_5951;
v_5950:
    v_6499 = stack[-3];
    return ncons(v_6499);
v_5951:
    v_6499 = stack[-3];
    if (!symbolp(v_6499)) v_6499 = nil;
    else { v_6499 = qfastgets(v_6499);
           if (v_6499 != nil) { v_6499 = elt(v_6499, 48); // modefn
#ifdef RECORD_GET
             if (v_6499 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v_6499 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v_6499 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v_6499 == SPID_NOPROP) v_6499 = nil; else v_6499 = lisp_true; }}
#endif
    if (v_6499 == nil) goto v_5962;
    v_6499 = stack[-3];
    {
        fn = elt(env, 24); // set!-global!-mode
        return (*qfn1(fn))(fn, v_6499);
    }
v_5962:
    goto v_5974;
v_5970:
    v_6500 = stack[-1];
    goto v_5971;
v_5972:
    v_6499 = elt(env, 3); // idfn
    goto v_5973;
v_5974:
    goto v_5970;
v_5971:
    goto v_5972;
v_5973:
    v_6499 = get(v_6500, v_6499);
    stack[-4] = v_6499;
    if (v_6499 == nil) goto v_5968;
    goto v_5984;
v_5978:
    v_6501 = stack[-4];
    goto v_5979;
v_5980:
    v_6500 = stack[-3];
    goto v_5981;
v_5982:
    v_6499 = stack[-2];
    goto v_5983;
v_5984:
    goto v_5978;
v_5979:
    goto v_5980;
v_5981:
    goto v_5982;
v_5983:
        return Lapply2(nil, 3, v_6501, v_6500, v_6499);
v_5968:
    v_6499 = stack[-3];
    goto v_5945;
    v_6499 = nil;
v_5945:
    goto v_5937;
v_5942:
    v_6499 = stack[-3];
    v_6499 = qcar(v_6499);
    if (!consp(v_6499)) goto v_5992;
    goto v_6002;
v_5996:
    v_6501 = stack[-3];
    goto v_5997;
v_5998:
    v_6500 = stack[-2];
    goto v_5999;
v_6000:
    v_6499 = stack[-1];
    goto v_6001;
v_6002:
    goto v_5996;
v_5997:
    goto v_5998;
v_5999:
    goto v_6000;
v_6001:
    {
        fn = elt(env, 25); // form2
        return (*qfnn(fn))(fn, 3, v_6501, v_6500, v_6499);
    }
v_5992:
    v_6499 = stack[-3];
    v_6499 = qcar(v_6499);
    if (symbolp(v_6499)) goto v_6007;
    goto v_6015;
v_6011:
    v_6499 = stack[-3];
    v_6500 = qcar(v_6499);
    goto v_6012;
v_6013:
    v_6499 = elt(env, 4); // "operator"
    goto v_6014;
v_6015:
    goto v_6011;
v_6012:
    goto v_6013;
v_6014:
    fn = elt(env, 26); // typerr
    v_6499 = (*qfn2(fn))(fn, v_6500, v_6499);
    env = stack[-5];
    goto v_5940;
v_6007:
    goto v_6025;
v_6021:
    v_6499 = stack[-3];
    v_6500 = qcar(v_6499);
    goto v_6022;
v_6023:
    v_6499 = elt(env, 5); // comment
    goto v_6024;
v_6025:
    goto v_6021;
v_6022:
    goto v_6023;
v_6024:
    if (v_6500 == v_6499) goto v_6019;
    else goto v_6020;
v_6019:
    goto v_6036;
v_6030:
    v_6499 = stack[-3];
    fn = elt(env, 27); // lastpair
    v_6499 = (*qfn1(fn))(fn, v_6499);
    env = stack[-5];
    v_6501 = qcar(v_6499);
    goto v_6031;
v_6032:
    v_6500 = stack[-2];
    goto v_6033;
v_6034:
    v_6499 = stack[-1];
    goto v_6035;
v_6036:
    goto v_6030;
v_6031:
    goto v_6032;
v_6033:
    goto v_6034;
v_6035:
    stack[-3] = v_6501;
    stack[-2] = v_6500;
    stack[-1] = v_6499;
    goto v_5929;
v_6020:
    goto v_6049;
v_6045:
    v_6499 = stack[-3];
    v_6500 = qcar(v_6499);
    goto v_6046;
v_6047:
    v_6499 = elt(env, 6); // noform
    goto v_6048;
v_6049:
    goto v_6045;
v_6046:
    goto v_6047;
v_6048:
    v_6499 = Lflagp(nil, v_6500, v_6499);
    env = stack[-5];
    if (v_6499 == nil) goto v_6043;
    v_6499 = stack[-3];
    goto v_5937;
v_6043:
    v_6499 = stack[-3];
    v_6499 = qcar(v_6499);
    fn = elt(env, 28); // arrayp
    v_6499 = (*qfn1(fn))(fn, v_6499);
    env = stack[-5];
    if (v_6499 == nil) goto v_6055;
    goto v_6065;
v_6061:
    v_6500 = stack[-1];
    goto v_6062;
v_6063:
    v_6499 = elt(env, 7); // symbolic
    goto v_6064;
v_6065:
    goto v_6061;
v_6062:
    goto v_6063;
v_6064:
    if (v_6500 == v_6499) goto v_6060;
    else goto v_6055;
v_6060:
    goto v_6073;
v_6069:
    stack[0] = elt(env, 8); // getel
    goto v_6070;
v_6071:
    goto v_6082;
v_6076:
    v_6501 = stack[-3];
    goto v_6077;
v_6078:
    v_6500 = stack[-2];
    goto v_6079;
v_6080:
    v_6499 = stack[-1];
    goto v_6081;
v_6082:
    goto v_6076;
v_6077:
    goto v_6078;
v_6079:
    goto v_6080;
v_6081:
    fn = elt(env, 29); // intargfn
    v_6499 = (*qfnn(fn))(fn, 3, v_6501, v_6500, v_6499);
    goto v_6072;
v_6073:
    goto v_6069;
v_6070:
    goto v_6071;
v_6072:
    {
        LispObject v_6508 = stack[0];
        return list2(v_6508, v_6499);
    }
v_6055:
    v_6499 = stack[-3];
    v_6499 = qcdr(v_6499);
    v_6499 = Lconsp(nil, v_6499);
    env = stack[-5];
    if (v_6499 == nil) goto v_6087;
    goto v_6101;
v_6097:
    v_6499 = stack[-3];
    v_6499 = qcar(v_6499);
    if (!symbolp(v_6499)) v_6500 = nil;
    else { v_6500 = qfastgets(v_6499);
           if (v_6500 != nil) { v_6500 = elt(v_6500, 2); // rtype
#ifdef RECORD_GET
             if (v_6500 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_6500 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_6500 == SPID_NOPROP) v_6500 = nil; }}
#endif
    goto v_6098;
v_6099:
    v_6499 = elt(env, 9); // vector
    goto v_6100;
v_6101:
    goto v_6097;
v_6098:
    goto v_6099;
v_6100:
    if (v_6500 == v_6499) goto v_6095;
    else goto v_6096;
v_6095:
    v_6499 = lisp_true;
    goto v_6094;
v_6096:
    v_6499 = stack[-3];
    v_6499 = qcdr(v_6499);
    v_6499 = qcar(v_6499);
    v_6499 = Lsimple_vectorp(nil, v_6499);
    env = stack[-5];
    if (v_6499 == nil) goto v_6111;
    else goto v_6110;
v_6111:
    goto v_6121;
v_6117:
    v_6499 = stack[-3];
    v_6499 = qcdr(v_6499);
    v_6500 = qcar(v_6499);
    goto v_6118;
v_6119:
    v_6499 = elt(env, 10); // vecfn
    goto v_6120;
v_6121:
    goto v_6117;
v_6118:
    goto v_6119;
v_6120:
    v_6499 = Lflagpcar(nil, v_6500, v_6499);
    env = stack[-5];
v_6110:
    goto v_6094;
    v_6499 = nil;
v_6094:
    if (v_6499 == nil) goto v_6087;
    goto v_6133;
v_6127:
    v_6501 = stack[-3];
    goto v_6128;
v_6129:
    v_6500 = stack[-2];
    goto v_6130;
v_6131:
    v_6499 = stack[-1];
    goto v_6132;
v_6133:
    goto v_6127;
v_6128:
    goto v_6129;
v_6130:
    goto v_6131;
v_6132:
    {
        fn = elt(env, 30); // getvect
        return (*qfnn(fn))(fn, 3, v_6501, v_6500, v_6499);
    }
v_6087:
    v_6499 = stack[-3];
    v_6499 = qcar(v_6499);
    if (!symbolp(v_6499)) v_6499 = nil;
    else { v_6499 = qfastgets(v_6499);
           if (v_6499 != nil) { v_6499 = elt(v_6499, 48); // modefn
#ifdef RECORD_GET
             if (v_6499 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v_6499 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v_6499 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v_6499 == SPID_NOPROP) v_6499 = nil; else v_6499 = lisp_true; }}
#endif
    if (v_6499 == nil) goto v_6138;
    goto v_6151;
v_6143:
    v_6499 = stack[-3];
    v_6499 = qcdr(v_6499);
    v_6502 = qcar(v_6499);
    goto v_6144;
v_6145:
    v_6501 = stack[-2];
    goto v_6146;
v_6147:
    v_6500 = stack[-1];
    goto v_6148;
v_6149:
    v_6499 = stack[-3];
    v_6499 = qcar(v_6499);
    goto v_6150;
v_6151:
    goto v_6143;
v_6144:
    goto v_6145;
v_6146:
    goto v_6147;
v_6148:
    goto v_6149;
v_6150:
    {
        fn = elt(env, 31); // convertmode
        return (*qfnn(fn))(fn, 4, v_6502, v_6501, v_6500, v_6499);
    }
v_6138:
    goto v_6166;
v_6162:
    v_6499 = stack[-3];
    v_6500 = qcar(v_6499);
    goto v_6163;
v_6164:
    v_6499 = elt(env, 11); // formfn
    goto v_6165;
v_6166:
    goto v_6162;
v_6163:
    goto v_6164;
v_6165:
    v_6499 = get(v_6500, v_6499);
    env = stack[-5];
    stack[-4] = v_6499;
    if (v_6499 == nil) goto v_6160;
    goto v_6175;
v_6171:
    goto v_6185;
v_6177:
    v_6502 = stack[-4];
    goto v_6178;
v_6179:
    v_6501 = stack[-3];
    goto v_6180;
v_6181:
    v_6500 = stack[-2];
    goto v_6182;
v_6183:
    v_6499 = stack[-1];
    goto v_6184;
v_6185:
    goto v_6177;
v_6178:
    goto v_6179;
v_6180:
    goto v_6181;
v_6182:
    goto v_6183;
v_6184:
    v_6500 = Lapply3(nil, 4, v_6502, v_6501, v_6500, v_6499);
    env = stack[-5];
    goto v_6172;
v_6173:
    v_6499 = stack[-1];
    goto v_6174;
v_6175:
    goto v_6171;
v_6172:
    goto v_6173;
v_6174:
    {
        fn = elt(env, 32); // macrochk
        return (*qfn2(fn))(fn, v_6500, v_6499);
    }
v_6160:
    goto v_6197;
v_6193:
    v_6499 = stack[-3];
    v_6499 = qcar(v_6499);
    if (!symbolp(v_6499)) v_6500 = nil;
    else { v_6500 = qfastgets(v_6499);
           if (v_6500 != nil) { v_6500 = elt(v_6500, 36); // stat
#ifdef RECORD_GET
             if (v_6500 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v_6500 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v_6500 == SPID_NOPROP) v_6500 = nil; }}
#endif
    goto v_6194;
v_6195:
    v_6499 = elt(env, 12); // rlis
    goto v_6196;
v_6197:
    goto v_6193;
v_6194:
    goto v_6195;
v_6196:
    if (v_6500 == v_6499) goto v_6191;
    else goto v_6192;
v_6191:
    goto v_6207;
v_6203:
    goto v_6215;
v_6209:
    v_6501 = stack[-3];
    goto v_6210;
v_6211:
    v_6500 = stack[-2];
    goto v_6212;
v_6213:
    v_6499 = stack[-1];
    goto v_6214;
v_6215:
    goto v_6209;
v_6210:
    goto v_6211;
v_6212:
    goto v_6213;
v_6214:
    fn = elt(env, 33); // formrlis
    v_6500 = (*qfnn(fn))(fn, 3, v_6501, v_6500, v_6499);
    env = stack[-5];
    goto v_6204;
v_6205:
    v_6499 = stack[-1];
    goto v_6206;
v_6207:
    goto v_6203;
v_6204:
    goto v_6205;
v_6206:
    {
        fn = elt(env, 32); // macrochk
        return (*qfn2(fn))(fn, v_6500, v_6499);
    }
v_6192:
    goto v_6226;
v_6222:
    v_6499 = stack[-3];
    v_6500 = qcar(v_6499);
    goto v_6223;
v_6224:
    v_6499 = elt(env, 13); // !*comma!*
    goto v_6225;
v_6226:
    goto v_6222;
v_6223:
    goto v_6224;
v_6225:
    if (v_6500 == v_6499) goto v_6220;
    else goto v_6221;
v_6220:
    v_6499 = stack[-3];
    v_6499 = qcdr(v_6499);
    v_6499 = qcar(v_6499);
    if (!consp(v_6499)) goto v_6237;
    v_6499 = stack[-3];
    v_6499 = qcdr(v_6499);
    v_6499 = qcdr(v_6499);
    v_6499 = qcar(v_6499);
    if (!consp(v_6499)) goto v_6243;
    else goto v_6244;
v_6243:
    goto v_6254;
v_6250:
    v_6499 = stack[-3];
    v_6499 = qcdr(v_6499);
    v_6499 = qcar(v_6499);
    v_6500 = qcar(v_6499);
    goto v_6251;
v_6252:
    v_6499 = elt(env, 14); // type
    goto v_6253;
v_6254:
    goto v_6250;
v_6251:
    goto v_6252;
v_6253:
    v_6499 = Lflagp(nil, v_6500, v_6499);
    env = stack[-5];
    goto v_6242;
v_6244:
    v_6499 = nil;
    goto v_6242;
    v_6499 = nil;
v_6242:
    goto v_6235;
v_6237:
    v_6499 = nil;
    goto v_6235;
    v_6499 = nil;
v_6235:
    if (v_6499 == nil) goto v_6233;
    v_6499 = stack[-3];
    v_6499 = qcdr(v_6499);
    v_6499 = qcar(v_6499);
    v_6499 = qcar(v_6499);
    fn = elt(env, 34); // blocktyperr
    v_6499 = (*qfn1(fn))(fn, v_6499);
    env = stack[-5];
    goto v_6231;
v_6233:
    goto v_6280;
v_6274:
    stack[-4] = elt(env, 15); // rlisp
    goto v_6275;
v_6276:
    stack[0] = (LispObject)160+TAG_FIXNUM; // 10
    goto v_6277;
v_6278:
    goto v_6288;
v_6284:
    v_6500 = elt(env, 16); // "Syntax error: , invalid after"
    goto v_6285;
v_6286:
    v_6499 = stack[-3];
    v_6499 = qcdr(v_6499);
    v_6499 = qcar(v_6499);
    goto v_6287;
v_6288:
    goto v_6284;
v_6285:
    goto v_6286;
v_6287:
    v_6499 = list2(v_6500, v_6499);
    env = stack[-5];
    goto v_6279;
v_6280:
    goto v_6274;
v_6275:
    goto v_6276;
v_6277:
    goto v_6278;
v_6279:
    fn = elt(env, 35); // rerror
    v_6499 = (*qfnn(fn))(fn, 3, stack[-4], stack[0], v_6499);
    env = stack[-5];
    goto v_6231;
v_6231:
    goto v_5940;
v_6221:
v_5940:
    goto v_6305;
v_6301:
    v_6500 = stack[-1];
    goto v_6302;
v_6303:
    v_6499 = elt(env, 7); // symbolic
    goto v_6304;
v_6305:
    goto v_6301;
v_6302:
    goto v_6303;
v_6304:
    if (v_6500 == v_6499) goto v_6299;
    else goto v_6300;
v_6299:
    v_6499 = lisp_true;
    goto v_6298;
v_6300:
    v_6499 = stack[-3];
    v_6499 = qcar(v_6499);
    if (!symbolp(v_6499)) v_6499 = nil;
    else { v_6499 = qfastgets(v_6499);
           if (v_6499 != nil) { v_6499 = elt(v_6499, 59); // opfn
#ifdef RECORD_GET
             if (v_6499 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v_6499 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v_6499 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v_6499 == SPID_NOPROP) v_6499 = nil; else v_6499 = lisp_true; }}
#endif
    goto v_6298;
    v_6499 = nil;
v_6298:
    if (v_6499 == nil) goto v_6296;
    v_6499 = stack[-3];
    fn = elt(env, 36); // argnochk
    v_6499 = (*qfn1(fn))(fn, v_6499);
    env = stack[-5];
    goto v_6294;
v_6296:
v_6294:
    goto v_6323;
v_6317:
    v_6499 = stack[-3];
    v_6501 = qcdr(v_6499);
    goto v_6318;
v_6319:
    v_6500 = stack[-2];
    goto v_6320;
v_6321:
    v_6499 = stack[-1];
    goto v_6322;
v_6323:
    goto v_6317;
v_6318:
    goto v_6319;
v_6320:
    goto v_6321;
v_6322:
    fn = elt(env, 37); // formlis
    v_6499 = (*qfnn(fn))(fn, 3, v_6501, v_6500, v_6499);
    env = stack[-5];
    stack[-4] = v_6499;
    goto v_6336;
v_6332:
    v_6500 = stack[-4];
    goto v_6333;
v_6334:
    v_6499 = stack[-3];
    v_6499 = qcdr(v_6499);
    goto v_6335;
v_6336:
    goto v_6332;
v_6333:
    goto v_6334;
v_6335:
    if (equal(v_6500, v_6499)) goto v_6330;
    else goto v_6331;
v_6330:
    v_6499 = stack[-3];
    goto v_6329;
v_6331:
    goto v_6348;
v_6344:
    v_6499 = stack[-3];
    v_6500 = qcar(v_6499);
    goto v_6345;
v_6346:
    v_6499 = stack[-4];
    goto v_6347;
v_6348:
    goto v_6344;
v_6345:
    goto v_6346;
v_6347:
    v_6499 = cons(v_6500, v_6499);
    env = stack[-5];
    goto v_6329;
    v_6499 = nil;
v_6329:
    stack[0] = v_6499;
    goto v_6364;
v_6360:
    v_6500 = stack[-1];
    goto v_6361;
v_6362:
    v_6499 = elt(env, 7); // symbolic
    goto v_6363;
v_6364:
    goto v_6360;
v_6361:
    goto v_6362;
v_6363:
    if (v_6500 == v_6499) goto v_6358;
    else goto v_6359;
v_6358:
    v_6499 = lisp_true;
    goto v_6357;
v_6359:
    v_6499 = stack[-3];
    v_6499 = qcar(v_6499);
    if (!symbolp(v_6499)) v_6499 = nil;
    else { v_6499 = qfastgets(v_6499);
           if (v_6499 != nil) { v_6499 = elt(v_6499, 36); // stat
#ifdef RECORD_GET
             if (v_6499 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v_6499 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v_6499 == SPID_NOPROP) v_6499 = nil; }}
#endif
    if (v_6499 == nil) goto v_6372;
    else goto v_6371;
v_6372:
    v_6499 = stack[-3];
    v_6499 = qcdr(v_6499);
    if (v_6499 == nil) goto v_6381;
    else goto v_6382;
v_6381:
    v_6499 = nil;
    goto v_6380;
v_6382:
    goto v_6397;
v_6393:
    v_6499 = stack[-3];
    v_6499 = qcdr(v_6499);
    v_6500 = qcar(v_6499);
    goto v_6394;
v_6395:
    v_6499 = elt(env, 17); // quote
    goto v_6396;
v_6397:
    goto v_6393;
v_6394:
    goto v_6395;
v_6396:
    if (!consp(v_6500)) goto v_6391;
    v_6500 = qcar(v_6500);
    if (v_6500 == v_6499) goto v_6390;
    else goto v_6391;
v_6390:
    v_6499 = qvalue(elt(env, 18)); // !*micro!-version
    if (v_6499 == nil) goto v_6404;
    else goto v_6405;
v_6404:
    v_6499 = nil;
    goto v_6403;
v_6405:
    v_6499 = qvalue(elt(env, 19)); // !*defn
    v_6499 = (v_6499 == nil ? lisp_true : nil);
    goto v_6403;
    v_6499 = nil;
v_6403:
    v_6499 = (v_6499 == nil ? lisp_true : nil);
    goto v_6389;
v_6391:
    v_6499 = nil;
    goto v_6389;
    v_6499 = nil;
v_6389:
    goto v_6380;
    v_6499 = nil;
v_6380:
    if (v_6499 == nil) goto v_6378;
    else goto v_6377;
v_6378:
    goto v_6425;
v_6421:
    v_6500 = stack[0];
    goto v_6422;
v_6423:
    v_6499 = stack[-2];
    goto v_6424;
v_6425:
    goto v_6421;
v_6422:
    goto v_6423;
v_6424:
    fn = elt(env, 38); // intexprnp
    v_6499 = (*qfn2(fn))(fn, v_6500, v_6499);
    env = stack[-5];
    if (v_6499 == nil) goto v_6418;
    else goto v_6419;
v_6418:
    v_6499 = nil;
    goto v_6417;
v_6419:
    v_6499 = qvalue(elt(env, 20)); // !*composites
    if (v_6499 == nil) goto v_6433;
    else goto v_6434;
v_6433:
    goto v_6440;
v_6436:
    v_6500 = qvalue(elt(env, 21)); // current!-modulus
    goto v_6437;
v_6438:
    v_6499 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6439;
v_6440:
    goto v_6436;
v_6437:
    goto v_6438;
v_6439:
    v_6499 = (v_6500 == v_6499 ? lisp_true : nil);
    goto v_6432;
v_6434:
    v_6499 = nil;
    goto v_6432;
    v_6499 = nil;
v_6432:
    goto v_6417;
    v_6499 = nil;
v_6417:
v_6377:
v_6371:
    goto v_6357;
    v_6499 = nil;
v_6357:
    if (v_6499 == nil) goto v_6355;
    goto v_6452;
v_6448:
    v_6500 = stack[0];
    goto v_6449;
v_6450:
    v_6499 = stack[-1];
    goto v_6451;
v_6452:
    goto v_6448;
v_6449:
    goto v_6450;
v_6451:
    {
        fn = elt(env, 32); // macrochk
        return (*qfn2(fn))(fn, v_6500, v_6499);
    }
v_6355:
    goto v_6461;
v_6457:
    v_6500 = stack[-1];
    goto v_6458;
v_6459:
    v_6499 = elt(env, 22); // algebraic
    goto v_6460;
v_6461:
    goto v_6457;
v_6458:
    goto v_6459;
v_6460:
    if (v_6500 == v_6499) goto v_6456;
    goto v_6473;
v_6465:
    v_6502 = stack[0];
    goto v_6466;
v_6467:
    v_6501 = stack[-2];
    goto v_6468;
v_6469:
    v_6500 = stack[-1];
    goto v_6470;
v_6471:
    v_6499 = elt(env, 22); // algebraic
    goto v_6472;
v_6473:
    goto v_6465;
v_6466:
    goto v_6467;
v_6468:
    goto v_6469;
v_6470:
    goto v_6471;
v_6472:
    {
        fn = elt(env, 31); // convertmode
        return (*qfnn(fn))(fn, 4, v_6502, v_6501, v_6500, v_6499);
    }
v_6456:
    goto v_6487;
v_6481:
    stack[0] = elt(env, 23); // list
    goto v_6482;
v_6483:
    goto v_6494;
v_6490:
    v_6499 = stack[-3];
    v_6500 = qcar(v_6499);
    goto v_6491;
v_6492:
    v_6499 = stack[-2];
    goto v_6493;
v_6494:
    goto v_6490;
v_6491:
    goto v_6492;
v_6493:
    fn = elt(env, 39); // algid
    v_6500 = (*qfn2(fn))(fn, v_6500, v_6499);
    goto v_6484;
v_6485:
    v_6499 = stack[-4];
    goto v_6486;
v_6487:
    goto v_6481;
v_6482:
    goto v_6483;
v_6484:
    goto v_6485;
v_6486:
    {
        LispObject v_6509 = stack[0];
        return list2star(v_6509, v_6500, v_6499);
    }
    v_6499 = nil;
v_5937:
    return onevalue(v_6499);
}



// Code for argnochk

static LispObject CC_argnochk(LispObject env,
                         LispObject v_5930)
{
    env = qenv(env);
    LispObject v_6102, v_6103, v_6104;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5930);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_5930;
// end of prologue
    v_6102 = qvalue(elt(env, 2)); // !*argnochk
    if (v_6102 == nil) goto v_5938;
    else goto v_5939;
v_5938:
    v_6102 = stack[-5];
    goto v_5934;
v_5939:
    v_6102 = stack[-5];
    v_6102 = qcar(v_6102);
    fn = elt(env, 12); // argsofopr
    v_6102 = (*qfn1(fn))(fn, v_6102);
    env = stack[-7];
    stack[-6] = v_6102;
    if (v_6102 == nil) goto v_5943;
    goto v_5959;
v_5955:
    stack[0] = stack[-6];
    goto v_5956;
v_5957:
    v_6102 = stack[-5];
    v_6102 = qcdr(v_6102);
    v_6102 = Llength(nil, v_6102);
    env = stack[-7];
    goto v_5958;
v_5959:
    goto v_5955;
v_5956:
    goto v_5957;
v_5958:
    if (equal(stack[0], v_6102)) goto v_5954;
    v_6102 = stack[-5];
    v_6102 = qcar(v_6102);
    if (!symbolp(v_6102)) v_6102 = nil;
    else { v_6102 = qfastgets(v_6102);
           if (v_6102 != nil) { v_6102 = elt(v_6102, 22); // simpfn
#ifdef RECORD_GET
             if (v_6102 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v_6102 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v_6102 == SPID_NOPROP) v_6102 = nil; }}
#endif
    if (v_6102 == nil) goto v_5966;
    else goto v_5965;
v_5966:
    v_6102 = stack[-5];
    v_6102 = qcar(v_6102);
    if (!symbolp(v_6102)) v_6102 = nil;
    else { v_6102 = qfastgets(v_6102);
           if (v_6102 != nil) { v_6102 = elt(v_6102, 45); // psopfn
#ifdef RECORD_GET
             if (v_6102 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v_6102 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v_6102 == SPID_NOPROP) v_6102 = nil; }}
#endif
    if (v_6102 == nil) goto v_5972;
    else goto v_5971;
v_5972:
    goto v_5981;
v_5977:
    v_6102 = stack[-5];
    v_6103 = qcar(v_6102);
    goto v_5978;
v_5979:
    v_6102 = elt(env, 3); // variadic
    goto v_5980;
v_5981:
    goto v_5977;
v_5978:
    goto v_5979;
v_5980:
    v_6102 = Lflagp(nil, v_6103, v_6102);
    env = stack[-7];
v_5971:
v_5965:
    v_6102 = (v_6102 == nil ? lisp_true : nil);
    goto v_5952;
v_5954:
    v_6102 = nil;
    goto v_5952;
    v_6102 = nil;
v_5952:
    if (v_6102 == nil) goto v_5950;
    v_6102 = qvalue(elt(env, 4)); // !*strict_argcount
    if (v_6102 == nil) goto v_5992;
    v_6102 = elt(env, 5); // "+++++ "
    v_6102 = Lprinc(nil, v_6102);
    env = stack[-7];
    v_6102 = stack[-5];
    v_6102 = Lprint(nil, v_6102);
    env = stack[-7];
    goto v_6005;
v_5999:
    stack[-4] = elt(env, 6); // rlisp
    goto v_6000;
v_6001:
    stack[-3] = (LispObject)176+TAG_FIXNUM; // 11
    goto v_6002;
v_6003:
    goto v_6017;
v_6009:
    v_6102 = stack[-5];
    stack[-2] = qcar(v_6102);
    goto v_6010;
v_6011:
    stack[-1] = elt(env, 7); // "called with"
    goto v_6012;
v_6013:
    v_6102 = stack[-5];
    v_6102 = qcdr(v_6102);
    stack[0] = Llength(nil, v_6102);
    env = stack[-7];
    goto v_6014;
v_6015:
    goto v_6031;
v_6025:
    goto v_6040;
v_6036:
    v_6102 = stack[-5];
    v_6102 = qcdr(v_6102);
    v_6103 = Llength(nil, v_6102);
    env = stack[-7];
    goto v_6037;
v_6038:
    v_6102 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6039;
v_6040:
    goto v_6036;
v_6037:
    goto v_6038;
v_6039:
    if (v_6103 == v_6102) goto v_6034;
    else goto v_6035;
v_6034:
    v_6102 = elt(env, 8); // "argument"
    v_6104 = v_6102;
    goto v_6033;
v_6035:
    v_6102 = elt(env, 9); // "arguments"
    v_6104 = v_6102;
    goto v_6033;
    v_6104 = nil;
v_6033:
    goto v_6026;
v_6027:
    v_6103 = elt(env, 10); // "instead of"
    goto v_6028;
v_6029:
    v_6102 = stack[-6];
    goto v_6030;
v_6031:
    goto v_6025;
v_6026:
    goto v_6027;
v_6028:
    goto v_6029;
v_6030:
    v_6102 = list3(v_6104, v_6103, v_6102);
    env = stack[-7];
    goto v_6016;
v_6017:
    goto v_6009;
v_6010:
    goto v_6011;
v_6012:
    goto v_6013;
v_6014:
    goto v_6015;
v_6016:
    v_6102 = list3star(stack[-2], stack[-1], stack[0], v_6102);
    env = stack[-7];
    goto v_6004;
v_6005:
    goto v_5999;
v_6000:
    goto v_6001;
v_6002:
    goto v_6003;
v_6004:
    fn = elt(env, 13); // rerror
    v_6102 = (*qfnn(fn))(fn, 3, stack[-4], stack[-3], v_6102);
    goto v_5990;
v_5992:
    goto v_6063;
v_6055:
    v_6102 = stack[-5];
    stack[-2] = qcar(v_6102);
    goto v_6056;
v_6057:
    stack[-1] = elt(env, 7); // "called with"
    goto v_6058;
v_6059:
    v_6102 = stack[-5];
    v_6102 = qcdr(v_6102);
    stack[0] = Llength(nil, v_6102);
    env = stack[-7];
    goto v_6060;
v_6061:
    goto v_6077;
v_6071:
    v_6104 = elt(env, 10); // "instead of"
    goto v_6072;
v_6073:
    v_6103 = stack[-6];
    goto v_6074;
v_6075:
    v_6102 = elt(env, 9); // "arguments"
    goto v_6076;
v_6077:
    goto v_6071;
v_6072:
    goto v_6073;
v_6074:
    goto v_6075;
v_6076:
    v_6102 = list3(v_6104, v_6103, v_6102);
    env = stack[-7];
    goto v_6062;
v_6063:
    goto v_6055;
v_6056:
    goto v_6057;
v_6058:
    goto v_6059;
v_6060:
    goto v_6061;
v_6062:
    v_6102 = list3star(stack[-2], stack[-1], stack[0], v_6102);
    env = stack[-7];
    fn = elt(env, 14); // lprim
    v_6102 = (*qfn1(fn))(fn, v_6102);
    v_6102 = stack[-5];
    goto v_5934;
v_5990:
    goto v_5948;
v_5950:
    v_6102 = stack[-5];
    goto v_5934;
v_5948:
    goto v_5937;
v_5943:
    goto v_6094;
v_6088:
    v_6102 = stack[-5];
    stack[-1] = qcar(v_6102);
    goto v_6089;
v_6090:
    stack[0] = elt(env, 11); // number!-of!-args
    goto v_6091;
v_6092:
    v_6102 = stack[-5];
    v_6102 = qcdr(v_6102);
    v_6102 = Llength(nil, v_6102);
    env = stack[-7];
    goto v_6093;
v_6094:
    goto v_6088;
v_6089:
    goto v_6090;
v_6091:
    goto v_6092;
v_6093:
    v_6102 = Lputprop(nil, 3, stack[-1], stack[0], v_6102);
    v_6102 = stack[-5];
    goto v_5934;
v_5937:
    v_6102 = nil;
v_5934:
    return onevalue(v_6102);
}



// Code for red_divtest

static LispObject CC_red_divtest(LispObject env,
                         LispObject v_5930, LispObject v_5931)
{
    env = qenv(env);
    LispObject v_5961, v_5962;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5931,v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5930,v_5931);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5931;
    stack[-1] = v_5930;
// end of prologue
v_5935:
    v_5961 = stack[-1];
    if (v_5961 == nil) goto v_5938;
    else goto v_5939;
v_5938:
    v_5961 = nil;
    goto v_5934;
v_5939:
    goto v_5949;
v_5945:
    v_5961 = stack[-1];
    v_5961 = qcar(v_5961);
    fn = elt(env, 1); // bas_dpoly
    v_5961 = (*qfn1(fn))(fn, v_5961);
    env = stack[-2];
    fn = elt(env, 2); // dp_lmon
    v_5962 = (*qfn1(fn))(fn, v_5961);
    env = stack[-2];
    goto v_5946;
v_5947:
    v_5961 = stack[0];
    goto v_5948;
v_5949:
    goto v_5945;
v_5946:
    goto v_5947;
v_5948:
    fn = elt(env, 3); // mo_vdivides!?
    v_5961 = (*qfn2(fn))(fn, v_5962, v_5961);
    env = stack[-2];
    if (v_5961 == nil) goto v_5943;
    v_5961 = stack[-1];
    v_5961 = qcar(v_5961);
    goto v_5934;
v_5943:
    v_5961 = stack[-1];
    v_5961 = qcdr(v_5961);
    stack[-1] = v_5961;
    goto v_5935;
    v_5961 = nil;
v_5934:
    return onevalue(v_5961);
}



// Code for mconv

static LispObject CC_mconv(LispObject env,
                         LispObject v_5930)
{
    env = qenv(env);
    LispObject v_5936;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5930);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_5930;
// end of prologue
    v_5936 = qvalue(elt(env, 1)); // dmode!*
    fn = elt(env, 2); // dmconv0
    v_5936 = (*qfn1(fn))(fn, v_5936);
    env = stack[-1];
    v_5936 = stack[0];
    {
        fn = elt(env, 3); // mconv1
        return (*qfn1(fn))(fn, v_5936);
    }
}



// Code for lalr_prin_nonterminal

static LispObject CC_lalr_prin_nonterminal(LispObject env,
                         LispObject v_5930)
{
    env = qenv(env);
    LispObject v_5958, v_5959;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5930);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_5958 = v_5930;
// end of prologue
    goto v_5942;
v_5938:
    v_5959 = v_5958;
    goto v_5939;
v_5940:
    v_5958 = qvalue(elt(env, 1)); // nonterminal_codes
    goto v_5941;
v_5942:
    goto v_5938;
v_5939:
    goto v_5940;
v_5941:
    fn = elt(env, 2); // cdrassoc
    v_5958 = (*qfn2(fn))(fn, v_5959, v_5958);
    env = stack[-1];
    fn = elt(env, 3); // explode2uc
    v_5958 = (*qfn1(fn))(fn, v_5958);
    env = stack[-1];
    stack[0] = v_5958;
v_5935:
    v_5958 = stack[0];
    if (v_5958 == nil) goto v_5947;
    else goto v_5948;
v_5947:
    v_5958 = nil;
    goto v_5934;
v_5948:
    v_5958 = stack[0];
    v_5958 = qcar(v_5958);
    v_5958 = Lprinc(nil, v_5958);
    env = stack[-1];
    v_5958 = stack[0];
    v_5958 = qcdr(v_5958);
    stack[0] = v_5958;
    goto v_5935;
v_5934:
    return onevalue(v_5958);
}



// Code for processcarpartitie1

static LispObject CC_processcarpartitie1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_5981, v_5982, v_5983;
    LispObject fn;
    LispObject v_5934, v_5933, v_5932, v_5931, v_5930;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "processcarpartitie1");
    va_start(aa, nargs);
    v_5930 = va_arg(aa, LispObject);
    v_5931 = va_arg(aa, LispObject);
    v_5932 = va_arg(aa, LispObject);
    v_5933 = va_arg(aa, LispObject);
    v_5934 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_5934,v_5933,v_5932,v_5931,v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_5930,v_5931,v_5932,v_5933,v_5934);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-3] = v_5934;
    stack[-4] = v_5933;
    stack[-5] = v_5932;
    v_5981 = v_5931;
    stack[-6] = v_5930;
// end of prologue
v_5939:
    v_5982 = v_5981;
    if (v_5982 == nil) goto v_5942;
    else goto v_5943;
v_5942:
    v_5981 = stack[-3];
    goto v_5938;
v_5943:
    v_5982 = v_5981;
    v_5982 = qcdr(v_5982);
    stack[-7] = v_5982;
    goto v_5961;
v_5951:
    stack[-2] = stack[-5];
    goto v_5952;
v_5953:
    stack[-1] = stack[-6];
    goto v_5954;
v_5955:
    stack[0] = v_5981;
    goto v_5956;
v_5957:
    goto v_5972;
v_5966:
    v_5982 = stack[-4];
    v_5983 = qcar(v_5982);
    goto v_5967;
v_5968:
    v_5982 = qcar(v_5981);
    goto v_5969;
v_5970:
    v_5981 = stack[-4];
    v_5981 = qcdr(v_5981);
    goto v_5971;
v_5972:
    goto v_5966;
v_5967:
    goto v_5968;
v_5969:
    goto v_5970;
v_5971:
    v_5982 = list2star(v_5983, v_5982, v_5981);
    env = stack[-8];
    goto v_5958;
v_5959:
    v_5981 = stack[-3];
    goto v_5960;
v_5961:
    goto v_5951;
v_5952:
    goto v_5953;
v_5954:
    goto v_5955;
v_5956:
    goto v_5957;
v_5958:
    goto v_5959;
v_5960:
    fn = elt(env, 1); // processpartitie1
    v_5981 = (*qfnn(fn))(fn, 5, stack[-2], stack[-1], stack[0], v_5982, v_5981);
    env = stack[-8];
    stack[-3] = v_5981;
    v_5981 = stack[-7];
    goto v_5939;
    v_5981 = nil;
v_5938:
    return onevalue(v_5981);
}



// Code for color1

static LispObject CC_color1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6266, v_6267, v_6268, v_6269;
    LispObject fn;
    LispObject v_5932, v_5931, v_5930;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "color1");
    va_start(aa, nargs);
    v_5930 = va_arg(aa, LispObject);
    v_5931 = va_arg(aa, LispObject);
    v_5932 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_5932,v_5931,v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_5930,v_5931,v_5932);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_5932;
    stack[-1] = v_5931;
    v_6268 = v_5930;
// end of prologue
v_5929:
v_5937:
    v_6266 = v_6268;
    v_6266 = qcar(v_6266);
    v_6266 = qcar(v_6266);
    if (v_6266 == nil) goto v_5944;
    else goto v_5945;
v_5944:
    v_6266 = lisp_true;
    goto v_5943;
v_5945:
    v_6266 = v_6268;
    v_6266 = qcdr(v_6266);
    v_6266 = (v_6266 == nil ? lisp_true : nil);
    goto v_5943;
    v_6266 = nil;
v_5943:
    if (v_6266 == nil) goto v_5941;
    v_6266 = stack[-1];
    if (v_6266 == nil) goto v_5957;
    else goto v_5958;
v_5957:
    goto v_5965;
v_5961:
    v_6266 = v_6268;
    v_6267 = qcar(v_6266);
    goto v_5962;
v_5963:
    v_6266 = stack[0];
    goto v_5964;
v_5965:
    goto v_5961;
v_5962:
    goto v_5963;
v_5964:
    {
        fn = elt(env, 6); // addsq
        return (*qfn2(fn))(fn, v_6267, v_6266);
    }
v_5958:
    v_6266 = stack[-1];
    v_6266 = qcar(v_6266);
    stack[-2] = v_6266;
    v_6266 = stack[-1];
    v_6266 = qcdr(v_6266);
    stack[-1] = v_6266;
    goto v_5980;
v_5976:
    v_6266 = v_6268;
    v_6267 = qcar(v_6266);
    goto v_5977;
v_5978:
    v_6266 = stack[0];
    goto v_5979;
v_5980:
    goto v_5976;
v_5977:
    goto v_5978;
v_5979:
    fn = elt(env, 6); // addsq
    v_6266 = (*qfn2(fn))(fn, v_6267, v_6266);
    env = stack[-3];
    stack[0] = v_6266;
    v_6266 = stack[-2];
    v_6268 = v_6266;
    goto v_5937;
    goto v_5939;
v_5941:
    goto v_5999;
v_5995:
    v_6267 = elt(env, 2); // qg
    goto v_5996;
v_5997:
    v_6266 = v_6268;
    v_6266 = qcdr(v_6266);
    goto v_5998;
v_5999:
    goto v_5995;
v_5996:
    goto v_5997;
v_5998:
    v_6266 = Lassoc(nil, v_6267, v_6266);
    v_6269 = v_6266;
    if (v_6266 == nil) goto v_5994;
    goto v_6016;
v_6012:
    v_6266 = v_6269;
    v_6266 = qcdr(v_6266);
    v_6267 = qcar(v_6266);
    goto v_6013;
v_6014:
    v_6266 = v_6269;
    v_6266 = qcdr(v_6266);
    v_6266 = qcdr(v_6266);
    v_6266 = qcar(v_6266);
    goto v_6015;
v_6016:
    goto v_6012;
v_6013:
    goto v_6014;
v_6015:
    if (v_6267 == v_6266) goto v_6010;
    else goto v_6011;
v_6010:
    v_6266 = lisp_true;
    goto v_6009;
v_6011:
    goto v_6035;
v_6031:
    v_6266 = v_6269;
    v_6266 = qcdr(v_6266);
    v_6267 = qcar(v_6266);
    goto v_6032;
v_6033:
    v_6266 = v_6269;
    v_6266 = qcdr(v_6266);
    v_6266 = qcdr(v_6266);
    v_6266 = qcdr(v_6266);
    v_6266 = qcar(v_6266);
    goto v_6034;
v_6035:
    goto v_6031;
v_6032:
    goto v_6033;
v_6034:
    if (v_6267 == v_6266) goto v_6029;
    else goto v_6030;
v_6029:
    v_6266 = lisp_true;
    goto v_6028;
v_6030:
    goto v_6051;
v_6047:
    v_6266 = v_6269;
    v_6266 = qcdr(v_6266);
    v_6266 = qcdr(v_6266);
    v_6267 = qcar(v_6266);
    goto v_6048;
v_6049:
    v_6266 = v_6269;
    v_6266 = qcdr(v_6266);
    v_6266 = qcdr(v_6266);
    v_6266 = qcdr(v_6266);
    v_6266 = qcar(v_6266);
    goto v_6050;
v_6051:
    goto v_6047;
v_6048:
    goto v_6049;
v_6050:
    v_6266 = (v_6267 == v_6266 ? lisp_true : nil);
    goto v_6028;
    v_6266 = nil;
v_6028:
    goto v_6009;
    v_6266 = nil;
v_6009:
    if (v_6266 == nil) goto v_6007;
    goto v_6069;
v_6063:
    goto v_6076;
v_6072:
    v_6267 = nil;
    goto v_6073;
v_6074:
    v_6266 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6075;
v_6076:
    goto v_6072;
v_6073:
    goto v_6074;
v_6075:
    v_6266 = cons(v_6267, v_6266);
    env = stack[-3];
    v_6268 = ncons(v_6266);
    env = stack[-3];
    goto v_6064;
v_6065:
    v_6267 = stack[-1];
    goto v_6066;
v_6067:
    v_6266 = stack[0];
    goto v_6068;
v_6069:
    goto v_6063;
v_6064:
    goto v_6065;
v_6066:
    goto v_6067;
v_6068:
    stack[-1] = v_6267;
    stack[0] = v_6266;
    goto v_5929;
v_6007:
    goto v_6086;
v_6082:
    v_6266 = v_6268;
    goto v_6083;
v_6084:
    v_6267 = v_6269;
    goto v_6085;
v_6086:
    goto v_6082;
v_6083:
    goto v_6084;
v_6085:
    fn = elt(env, 7); // removeg
    v_6266 = (*qfn2(fn))(fn, v_6266, v_6267);
    env = stack[-3];
    v_6268 = v_6266;
    goto v_6096;
v_6090:
    v_6266 = v_6268;
    stack[-2] = qcar(v_6266);
    goto v_6091;
v_6092:
    v_6266 = v_6268;
    v_6266 = qcdr(v_6266);
    if (v_6266 == nil) goto v_6102;
    goto v_6110;
v_6106:
    v_6266 = v_6268;
    v_6267 = qcdr(v_6266);
    goto v_6107;
v_6108:
    v_6266 = stack[-1];
    goto v_6109;
v_6110:
    goto v_6106;
v_6107:
    goto v_6108;
v_6109:
    v_6266 = cons(v_6267, v_6266);
    env = stack[-3];
    v_6267 = v_6266;
    goto v_6100;
v_6102:
    v_6266 = stack[-1];
    v_6267 = v_6266;
    goto v_6100;
    v_6267 = nil;
v_6100:
    goto v_6093;
v_6094:
    v_6266 = stack[0];
    goto v_6095;
v_6096:
    goto v_6090;
v_6091:
    goto v_6092;
v_6093:
    goto v_6094;
v_6095:
    v_6268 = stack[-2];
    stack[-1] = v_6267;
    stack[0] = v_6266;
    goto v_5929;
v_5994:
    goto v_6124;
v_6120:
    v_6267 = elt(env, 3); // g3
    goto v_6121;
v_6122:
    v_6266 = v_6268;
    v_6266 = qcdr(v_6266);
    goto v_6123;
v_6124:
    goto v_6120;
v_6121:
    goto v_6122;
v_6123:
    v_6266 = Lassoc(nil, v_6267, v_6266);
    v_6269 = v_6266;
    if (v_6266 == nil) goto v_6119;
    goto v_6141;
v_6137:
    v_6266 = v_6269;
    v_6266 = qcdr(v_6266);
    v_6267 = qcar(v_6266);
    goto v_6138;
v_6139:
    v_6266 = v_6269;
    v_6266 = qcdr(v_6266);
    v_6266 = qcdr(v_6266);
    v_6266 = qcar(v_6266);
    goto v_6140;
v_6141:
    goto v_6137;
v_6138:
    goto v_6139;
v_6140:
    if (v_6267 == v_6266) goto v_6135;
    else goto v_6136;
v_6135:
    v_6266 = lisp_true;
    goto v_6134;
v_6136:
    goto v_6160;
v_6156:
    v_6266 = v_6269;
    v_6266 = qcdr(v_6266);
    v_6267 = qcar(v_6266);
    goto v_6157;
v_6158:
    v_6266 = v_6269;
    v_6266 = qcdr(v_6266);
    v_6266 = qcdr(v_6266);
    v_6266 = qcdr(v_6266);
    v_6266 = qcar(v_6266);
    goto v_6159;
v_6160:
    goto v_6156;
v_6157:
    goto v_6158;
v_6159:
    if (v_6267 == v_6266) goto v_6154;
    else goto v_6155;
v_6154:
    v_6266 = lisp_true;
    goto v_6153;
v_6155:
    goto v_6176;
v_6172:
    v_6266 = v_6269;
    v_6266 = qcdr(v_6266);
    v_6266 = qcdr(v_6266);
    v_6267 = qcar(v_6266);
    goto v_6173;
v_6174:
    v_6266 = v_6269;
    v_6266 = qcdr(v_6266);
    v_6266 = qcdr(v_6266);
    v_6266 = qcdr(v_6266);
    v_6266 = qcar(v_6266);
    goto v_6175;
v_6176:
    goto v_6172;
v_6173:
    goto v_6174;
v_6175:
    v_6266 = (v_6267 == v_6266 ? lisp_true : nil);
    goto v_6153;
    v_6266 = nil;
v_6153:
    goto v_6134;
    v_6266 = nil;
v_6134:
    if (v_6266 == nil) goto v_6132;
    goto v_6194;
v_6188:
    goto v_6201;
v_6197:
    v_6267 = nil;
    goto v_6198;
v_6199:
    v_6266 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6200;
v_6201:
    goto v_6197;
v_6198:
    goto v_6199;
v_6200:
    v_6266 = cons(v_6267, v_6266);
    env = stack[-3];
    v_6268 = ncons(v_6266);
    env = stack[-3];
    goto v_6189;
v_6190:
    v_6267 = stack[-1];
    goto v_6191;
v_6192:
    v_6266 = stack[0];
    goto v_6193;
v_6194:
    goto v_6188;
v_6189:
    goto v_6190;
v_6191:
    goto v_6192;
v_6193:
    stack[-1] = v_6267;
    stack[0] = v_6266;
    goto v_5929;
v_6132:
    goto v_6211;
v_6207:
    v_6266 = v_6268;
    goto v_6208;
v_6209:
    v_6267 = v_6269;
    goto v_6210;
v_6211:
    goto v_6207;
v_6208:
    goto v_6209;
v_6210:
    fn = elt(env, 8); // split3gv
    v_6266 = (*qfn2(fn))(fn, v_6266, v_6267);
    env = stack[-3];
    v_6268 = v_6266;
    goto v_6221;
v_6215:
    v_6266 = v_6268;
    stack[-2] = qcar(v_6266);
    goto v_6216;
v_6217:
    goto v_6229;
v_6225:
    v_6266 = v_6268;
    v_6267 = qcdr(v_6266);
    goto v_6226;
v_6227:
    v_6266 = stack[-1];
    goto v_6228;
v_6229:
    goto v_6225;
v_6226:
    goto v_6227;
v_6228:
    v_6267 = cons(v_6267, v_6266);
    env = stack[-3];
    goto v_6218;
v_6219:
    v_6266 = stack[0];
    goto v_6220;
v_6221:
    goto v_6215;
v_6216:
    goto v_6217;
v_6218:
    goto v_6219;
v_6220:
    v_6268 = stack[-2];
    stack[-1] = v_6267;
    stack[0] = v_6266;
    goto v_5929;
v_6119:
    goto v_6242;
v_6238:
    stack[0] = elt(env, 4); // "Invalid structure of c0-graph."
    goto v_6239;
v_6240:
    v_6266 = v_6268;
    if (v_6266 == nil) goto v_6246;
    else goto v_6247;
v_6246:
    v_6266 = nil;
    goto v_6245;
v_6247:
    v_6266 = v_6268;
    v_6266 = qcdr(v_6266);
    if (v_6266 == nil) goto v_6250;
    else goto v_6251;
v_6250:
    v_6266 = v_6268;
    v_6266 = qcar(v_6266);
    goto v_6245;
v_6251:
    goto v_6263;
v_6259:
    v_6266 = elt(env, 5); // times
    goto v_6260;
v_6261:
    v_6267 = v_6268;
    goto v_6262;
v_6263:
    goto v_6259;
v_6260:
    goto v_6261;
v_6262:
    v_6266 = cons(v_6266, v_6267);
    env = stack[-3];
    goto v_6245;
    v_6266 = nil;
v_6245:
    goto v_6241;
v_6242:
    goto v_6238;
v_6239:
    goto v_6240;
v_6241:
    v_6266 = list2(stack[0], v_6266);
    env = stack[-3];
    fn = elt(env, 9); // cerror
    v_6266 = (*qfn1(fn))(fn, v_6266);
    goto v_5992;
v_5992:
    v_6266 = nil;
    goto v_5936;
v_5939:
    v_6266 = nil;
v_5936:
    return onevalue(v_6266);
}



// Code for cl_simpl

static LispObject CC_cl_simpl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6013, v_6014, v_6015, v_6016;
    LispObject fn;
    LispObject v_5932, v_5931, v_5930;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cl_simpl");
    va_start(aa, nargs);
    v_5930 = va_arg(aa, LispObject);
    v_5931 = va_arg(aa, LispObject);
    v_5932 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_5932,v_5931,v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_5930,v_5931,v_5932);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_5932;
    v_6014 = v_5931;
    stack[-3] = v_5930;
// end of prologue
    v_6013 = qvalue(elt(env, 2)); // !*rlsism
    if (v_6013 == nil) goto v_5940;
    else goto v_5941;
v_5940:
    goto v_5952;
v_5944:
    v_6016 = stack[-3];
    goto v_5945;
v_5946:
    v_6015 = nil;
    goto v_5947;
v_5948:
    v_6014 = stack[-2];
    goto v_5949;
v_5950:
    v_6013 = nil;
    goto v_5951;
v_5952:
    goto v_5944;
v_5945:
    goto v_5946;
v_5947:
    goto v_5948;
v_5949:
    goto v_5950;
v_5951:
    {
        fn = elt(env, 6); // cl_simpl1
        return (*qfnn(fn))(fn, 4, v_6016, v_6015, v_6014, v_6013);
    }
v_5941:
    v_6013 = v_6014;
    fn = elt(env, 7); // cl_sitheo
    v_6013 = (*qfn1(fn))(fn, v_6013);
    env = stack[-5];
    v_6014 = v_6013;
    goto v_5967;
v_5963:
    v_6015 = v_6014;
    goto v_5964;
v_5965:
    v_6013 = elt(env, 3); // inctheo
    goto v_5966;
v_5967:
    goto v_5963;
v_5964:
    goto v_5965;
v_5966:
    if (v_6015 == v_6013) goto v_5961;
    else goto v_5962;
v_5961:
    v_6013 = elt(env, 3); // inctheo
    {
        fn = elt(env, 8); // rl_exc
        return (*qfn1(fn))(fn, v_6013);
    }
v_5962:
    goto v_5981;
v_5973:
    stack[-4] = elt(env, 4); // and
    goto v_5974;
v_5975:
    stack[-1] = v_6014;
    goto v_5976;
v_5977:
    stack[0] = nil;
    goto v_5978;
v_5979:
    v_6013 = stack[-2];
    v_6013 = add1(v_6013);
    env = stack[-5];
    goto v_5980;
v_5981:
    goto v_5973;
v_5974:
    goto v_5975;
v_5976:
    goto v_5977;
v_5978:
    goto v_5979;
v_5980:
    fn = elt(env, 9); // rl_smupdknowl
    v_6013 = (*qfnn(fn))(fn, 4, stack[-4], stack[-1], stack[0], v_6013);
    env = stack[-5];
    v_6014 = v_6013;
    goto v_5995;
v_5991:
    v_6015 = v_6014;
    goto v_5992;
v_5993:
    v_6013 = elt(env, 5); // false
    goto v_5994;
v_5995:
    goto v_5991;
v_5992:
    goto v_5993;
v_5994:
    if (v_6015 == v_6013) goto v_5989;
    else goto v_5990;
v_5989:
    v_6013 = elt(env, 3); // inctheo
    goto v_5936;
v_5990:
    goto v_6008;
v_6000:
    v_6016 = stack[-3];
    goto v_6001;
v_6002:
    v_6015 = v_6014;
    goto v_6003;
v_6004:
    v_6014 = stack[-2];
    goto v_6005;
v_6006:
    v_6013 = nil;
    goto v_6007;
v_6008:
    goto v_6000;
v_6001:
    goto v_6002;
v_6003:
    goto v_6004;
v_6005:
    goto v_6006;
v_6007:
    {
        fn = elt(env, 6); // cl_simpl1
        return (*qfnn(fn))(fn, 4, v_6016, v_6015, v_6014, v_6013);
    }
v_5936:
    return onevalue(v_6013);
}



// Code for ibalp_atomp

static LispObject CC_ibalp_atomp(LispObject env,
                         LispObject v_5930)
{
    env = qenv(env);
    LispObject v_5996, v_5997;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5930);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_5930;
// end of prologue
    goto v_5944;
v_5940:
    v_5997 = stack[0];
    goto v_5941;
v_5942:
    v_5996 = elt(env, 1); // true
    goto v_5943;
v_5944:
    goto v_5940;
v_5941:
    goto v_5942;
v_5943:
    if (v_5997 == v_5996) goto v_5938;
    else goto v_5939;
v_5938:
    v_5996 = lisp_true;
    goto v_5937;
v_5939:
    goto v_5954;
v_5950:
    v_5997 = stack[0];
    goto v_5951;
v_5952:
    v_5996 = elt(env, 2); // false
    goto v_5953;
v_5954:
    goto v_5950;
v_5951:
    goto v_5952;
v_5953:
    v_5996 = (v_5997 == v_5996 ? lisp_true : nil);
    goto v_5937;
    v_5996 = nil;
v_5937:
    if (v_5996 == nil) goto v_5935;
    v_5996 = lisp_true;
    goto v_5933;
v_5935:
    goto v_5969;
v_5965:
    v_5996 = stack[0];
    if (!consp(v_5996)) goto v_5972;
    else goto v_5973;
v_5972:
    v_5996 = stack[0];
    v_5997 = v_5996;
    goto v_5971;
v_5973:
    v_5996 = stack[0];
    v_5996 = qcar(v_5996);
    v_5997 = v_5996;
    goto v_5971;
    v_5997 = nil;
v_5971:
    goto v_5966;
v_5967:
    v_5996 = elt(env, 3); // equal
    goto v_5968;
v_5969:
    goto v_5965;
v_5966:
    goto v_5967;
v_5968:
    if (v_5997 == v_5996) goto v_5963;
    else goto v_5964;
v_5963:
    v_5996 = stack[0];
    fn = elt(env, 4); // ibalp_arg2l
    v_5996 = (*qfn1(fn))(fn, v_5996);
    env = stack[-1];
    if (symbolp(v_5996)) goto v_5984;
    v_5996 = nil;
    goto v_5982;
v_5984:
    v_5996 = stack[0];
    fn = elt(env, 5); // ibalp_arg2r
    v_5996 = (*qfn1(fn))(fn, v_5996);
    v_5996 = (is_number(v_5996) ? lisp_true : nil);
    goto v_5982;
    v_5996 = nil;
v_5982:
    goto v_5962;
v_5964:
    v_5996 = nil;
    goto v_5962;
    v_5996 = nil;
v_5962:
    goto v_5933;
    v_5996 = nil;
v_5933:
    return onevalue(v_5996);
}



// Code for basicom

static LispObject CC_basicom(LispObject env,
                         LispObject v_5930)
{
    env = qenv(env);
    LispObject v_5961;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5930);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_5930;
// end of prologue
    v_5961 = stack[0];
    if (is_number(v_5961)) goto v_5937;
    else goto v_5938;
v_5937:
    v_5961 = stack[0];
    v_5961 = integerp(v_5961);
    if (v_5961 == nil) goto v_5943;
    v_5961 = stack[0];
    fn = elt(env, 1); // integerom
    v_5961 = (*qfn1(fn))(fn, v_5961);
    env = stack[-1];
    goto v_5941;
v_5943:
v_5941:
    v_5961 = stack[0];
    v_5961 = Lfloatp(nil, v_5961);
    env = stack[-1];
    if (v_5961 == nil) goto v_5951;
    v_5961 = stack[0];
    fn = elt(env, 2); // floatom
    v_5961 = (*qfn1(fn))(fn, v_5961);
    goto v_5949;
v_5951:
v_5949:
    goto v_5936;
v_5938:
    v_5961 = stack[0];
    if (symbolp(v_5961)) goto v_5956;
    else goto v_5957;
v_5956:
    v_5961 = stack[0];
    fn = elt(env, 3); // variableom
    v_5961 = (*qfn1(fn))(fn, v_5961);
    goto v_5936;
v_5957:
v_5936:
    v_5961 = nil;
    return onevalue(v_5961);
}



// Code for simpexpon1

static LispObject CC_simpexpon1(LispObject env,
                         LispObject v_5930, LispObject v_5931)
{
    env = qenv(env);
    LispObject v_5987, v_5988;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5931,v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5930,v_5931);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_5931;
    stack[-2] = v_5930;
// end of prologue
    v_5987 = qvalue(elt(env, 1)); // !*numval
    if (v_5987 == nil) goto v_5936;
    goto v_5948;
v_5944:
    v_5988 = qvalue(elt(env, 2)); // dmode!*
    goto v_5945;
v_5946:
    v_5987 = elt(env, 3); // !:rd!:
    goto v_5947;
v_5948:
    goto v_5944;
v_5945:
    goto v_5946;
v_5947:
    if (v_5988 == v_5987) goto v_5942;
    else goto v_5943;
v_5942:
    v_5987 = lisp_true;
    goto v_5941;
v_5943:
    goto v_5958;
v_5954:
    v_5988 = qvalue(elt(env, 2)); // dmode!*
    goto v_5955;
v_5956:
    v_5987 = elt(env, 4); // !:cr!:
    goto v_5957;
v_5958:
    goto v_5954;
v_5955:
    goto v_5956;
v_5957:
    v_5987 = (v_5988 == v_5987 ? lisp_true : nil);
    goto v_5941;
    v_5987 = nil;
v_5941:
    if (v_5987 == nil) goto v_5936;
    goto v_5967;
v_5963:
    v_5988 = stack[-1];
    goto v_5964;
v_5965:
    v_5987 = stack[-2];
    goto v_5966;
v_5967:
    goto v_5963;
v_5964:
    goto v_5965;
v_5966:
        return Lapply1(nil, v_5988, v_5987);
v_5936:
// Binding dmode!*
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 2, -3);
    qvalue(elt(env, 2)) = nil; // dmode!*
// Binding alglist!*
// FLUIDBIND: reloadenv=4 litvec-offset=5 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 5, 0);
    qvalue(elt(env, 5)) = nil; // alglist!*
    v_5987 = nil;
    v_5987 = ncons(v_5987);
    env = stack[-4];
    qvalue(elt(env, 5)) = v_5987; // alglist!*
    goto v_5984;
v_5980:
    v_5988 = stack[-1];
    goto v_5981;
v_5982:
    v_5987 = stack[-2];
    goto v_5983;
v_5984:
    goto v_5980;
v_5981:
    goto v_5982;
v_5983:
    v_5987 = Lapply1(nil, v_5988, v_5987);
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_5934;
    v_5987 = nil;
v_5934:
    return onevalue(v_5987);
}



// Code for writepri

static LispObject CC_writepri(LispObject env,
                         LispObject v_5930, LispObject v_5931)
{
    env = qenv(env);
    LispObject v_5945, v_5946, v_5947;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5931,v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5930,v_5931);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_5931;
    v_5945 = v_5930;
// end of prologue
    goto v_5940;
v_5934:
    fn = elt(env, 1); // eval
    v_5947 = (*qfn1(fn))(fn, v_5945);
    env = stack[-1];
    goto v_5935;
v_5936:
    v_5946 = nil;
    goto v_5937;
v_5938:
    v_5945 = stack[0];
    goto v_5939;
v_5940:
    goto v_5934;
v_5935:
    goto v_5936;
v_5937:
    goto v_5938;
v_5939:
    {
        fn = elt(env, 2); // assgnpri
        return (*qfnn(fn))(fn, 3, v_5947, v_5946, v_5945);
    }
}



// Code for initwght

static LispObject CC_initwght(LispObject env,
                         LispObject v_5930)
{
    env = qenv(env);
    LispObject v_6063, v_6064;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5930);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_5930;
// end of prologue
    v_6063 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_6063;
    stack[0] = v_6063;
    goto v_5946;
v_5942:
    goto v_5951;
v_5947:
    stack[-1] = qvalue(elt(env, 2)); // codmat
    goto v_5948;
v_5949:
    goto v_5958;
v_5954:
    v_6064 = qvalue(elt(env, 3)); // maxvar
    goto v_5955;
v_5956:
    v_6063 = stack[-3];
    goto v_5957;
v_5958:
    goto v_5954;
v_5955:
    goto v_5956;
v_5957:
    v_6063 = plus2(v_6064, v_6063);
    env = stack[-6];
    goto v_5950;
v_5951:
    goto v_5947;
v_5948:
    goto v_5949;
v_5950:
    v_6064 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_6063-TAG_FIXNUM)/(16/CELL)));
    goto v_5943;
v_5944:
    v_6063 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_5945;
v_5946:
    goto v_5942;
v_5943:
    goto v_5944;
v_5945:
    v_6063 = *(LispObject *)((char *)v_6064 + (CELL-TAG_VECTOR) + (((intptr_t)v_6063-TAG_FIXNUM)/(16/CELL)));
    stack[-4] = v_6063;
v_5941:
    v_6063 = stack[-4];
    if (v_6063 == nil) goto v_5966;
    else goto v_5967;
v_5966:
    goto v_5940;
v_5967:
    v_6063 = stack[-4];
    v_6063 = qcar(v_6063);
    stack[-2] = v_6063;
    goto v_5981;
v_5977:
    goto v_5986;
v_5982:
    stack[-1] = qvalue(elt(env, 2)); // codmat
    goto v_5983;
v_5984:
    goto v_5993;
v_5989:
    v_6064 = qvalue(elt(env, 3)); // maxvar
    goto v_5990;
v_5991:
    v_6063 = stack[-2];
    v_6063 = qcar(v_6063);
    goto v_5992;
v_5993:
    goto v_5989;
v_5990:
    goto v_5991;
v_5992:
    v_6063 = plus2(v_6064, v_6063);
    env = stack[-6];
    goto v_5985;
v_5986:
    goto v_5982;
v_5983:
    goto v_5984;
v_5985:
    v_6064 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_6063-TAG_FIXNUM)/(16/CELL)));
    goto v_5978;
v_5979:
    v_6063 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5980;
v_5981:
    goto v_5977;
v_5978:
    goto v_5979;
v_5980:
    v_6063 = *(LispObject *)((char *)v_6064 + (CELL-TAG_VECTOR) + (((intptr_t)v_6063-TAG_FIXNUM)/(16/CELL)));
    if (v_6063 == nil) goto v_5976;
    v_6063 = stack[-2];
    v_6063 = qcdr(v_6063);
    v_6063 = qcar(v_6063);
    fn = elt(env, 4); // dm!-abs
    v_6063 = (*qfn1(fn))(fn, v_6063);
    env = stack[-6];
    fn = elt(env, 5); // !:onep
    v_6063 = (*qfn1(fn))(fn, v_6063);
    env = stack[-6];
    if (v_6063 == nil) goto v_6002;
    else goto v_6003;
v_6002:
    v_6063 = stack[-5];
    v_6063 = add1(v_6063);
    env = stack[-6];
    stack[-5] = v_6063;
    goto v_6001;
v_6003:
v_6001:
    v_6063 = stack[0];
    v_6063 = add1(v_6063);
    env = stack[-6];
    stack[0] = v_6063;
    goto v_5974;
v_5976:
v_5974:
    v_6063 = stack[-4];
    v_6063 = qcdr(v_6063);
    stack[-4] = v_6063;
    goto v_5941;
v_5940:
    goto v_6021;
v_6015:
    goto v_6026;
v_6022:
    stack[-1] = qvalue(elt(env, 2)); // codmat
    goto v_6023;
v_6024:
    goto v_6033;
v_6029:
    v_6064 = qvalue(elt(env, 3)); // maxvar
    goto v_6030;
v_6031:
    v_6063 = stack[-3];
    goto v_6032;
v_6033:
    goto v_6029;
v_6030:
    goto v_6031;
v_6032:
    v_6063 = plus2(v_6064, v_6063);
    env = stack[-6];
    goto v_6025;
v_6026:
    goto v_6022;
v_6023:
    goto v_6024;
v_6025:
    stack[-4] = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_6063-TAG_FIXNUM)/(16/CELL)));
    goto v_6016;
v_6017:
    stack[-3] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6018;
v_6019:
    goto v_6045;
v_6039:
    stack[-2] = stack[0];
    goto v_6040;
v_6041:
    stack[-1] = stack[-5];
    goto v_6042;
v_6043:
    goto v_6053;
v_6049:
    goto v_6050;
v_6051:
    goto v_6060;
v_6056:
    v_6064 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_6057;
v_6058:
    v_6063 = stack[-5];
    goto v_6059;
v_6060:
    goto v_6056;
v_6057:
    goto v_6058;
v_6059:
    v_6063 = times2(v_6064, v_6063);
    env = stack[-6];
    goto v_6052;
v_6053:
    goto v_6049;
v_6050:
    goto v_6051;
v_6052:
    v_6063 = plus2(stack[0], v_6063);
    env = stack[-6];
    goto v_6044;
v_6045:
    goto v_6039;
v_6040:
    goto v_6041;
v_6042:
    goto v_6043;
v_6044:
    v_6063 = acons(stack[-2], stack[-1], v_6063);
    goto v_6020;
v_6021:
    goto v_6015;
v_6016:
    goto v_6017;
v_6018:
    goto v_6019;
v_6020:
    *(LispObject *)((char *)stack[-4] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-3]-TAG_FIXNUM)/(16/CELL))) = v_6063;
    v_6063 = nil;
    return onevalue(v_6063);
}



// Code for revalind

static LispObject CC_revalind(LispObject env,
                         LispObject v_5930)
{
    env = qenv(env);
    LispObject v_5959, v_5960, v_5961;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5930);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_5930;
// end of prologue
// Binding alglist!*
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 1, -1);
    qvalue(elt(env, 1)) = nil; // alglist!*
// Binding dmode!*
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 2, 0);
    qvalue(elt(env, 2)) = nil; // dmode!*
    v_5959 = nil;
    v_5959 = ncons(v_5959);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_5959; // alglist!*
    v_5959 = qvalue(elt(env, 4)); // subfg!*
    stack[-3] = v_5959;
    v_5959 = nil;
    qvalue(elt(env, 4)) = v_5959; // subfg!*
    goto v_5950;
v_5944:
    v_5961 = elt(env, 5); // !0
    goto v_5945;
v_5946:
    v_5960 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5947;
v_5948:
    v_5959 = stack[-2];
    goto v_5949;
v_5950:
    goto v_5944;
v_5945:
    goto v_5946;
v_5947:
    goto v_5948;
v_5949:
    v_5959 = Lsubst(nil, 3, v_5961, v_5960, v_5959);
    env = stack[-4];
    stack[-2] = v_5959;
    v_5959 = stack[-2];
    fn = elt(env, 6); // simp
    v_5959 = (*qfn1(fn))(fn, v_5959);
    env = stack[-4];
    fn = elt(env, 7); // prepsq
    v_5959 = (*qfn1(fn))(fn, v_5959);
    env = stack[-4];
    v_5960 = v_5959;
    v_5959 = stack[-3];
    qvalue(elt(env, 4)) = v_5959; // subfg!*
    v_5959 = v_5960;
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_5959);
}



// Code for gfrsq

static LispObject CC_gfrsq(LispObject env,
                         LispObject v_5930)
{
    env = qenv(env);
    LispObject v_5940, v_5941;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5940 = v_5930;
// end of prologue
    goto v_5937;
v_5933:
    v_5941 = v_5940;
    goto v_5934;
v_5935:
    goto v_5936;
v_5937:
    goto v_5933;
v_5934:
    goto v_5935;
v_5936:
    {
        fn = elt(env, 1); // gfdot
        return (*qfn2(fn))(fn, v_5941, v_5940);
    }
}



// Code for convchk

static LispObject CC_convchk(LispObject env,
                         LispObject v_5930)
{
    env = qenv(env);
    LispObject v_5989, v_5990, v_5991;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5930);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_5989 = v_5930;
// end of prologue
    v_5990 = qvalue(elt(env, 1)); // !*!*roundbf
    if (v_5990 == nil) goto v_5935;
    v_5990 = v_5989;
    if (!consp(v_5990)) goto v_5939;
    else goto v_5940;
v_5939:
    v_5990 = v_5989;
    v_5990 = Lfloatp(nil, v_5990);
    env = stack[0];
    if (v_5990 == nil) goto v_5945;
    {
        fn = elt(env, 3); // fl2bf
        return (*qfn1(fn))(fn, v_5989);
    }
v_5945:
    v_5990 = v_5989;
    if (!consp(v_5990)) goto v_5956;
    goto v_5954;
v_5956:
    v_5990 = v_5989;
    v_5990 = integerp(v_5990);
    if (v_5990 == nil) goto v_5960;
    goto v_5970;
v_5964:
    v_5991 = elt(env, 2); // !:rd!:
    goto v_5965;
v_5966:
    v_5990 = v_5989;
    goto v_5967;
v_5968:
    v_5989 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5969;
v_5970:
    goto v_5964;
v_5965:
    goto v_5966;
v_5967:
    goto v_5968;
v_5969:
    v_5989 = list2star(v_5991, v_5990, v_5989);
    env = stack[0];
    goto v_5954;
v_5960:
    fn = elt(env, 4); // read!:num
    v_5989 = (*qfn1(fn))(fn, v_5989);
    env = stack[0];
    goto v_5954;
    v_5989 = nil;
v_5954:
    {
        fn = elt(env, 5); // normbf
        return (*qfn1(fn))(fn, v_5989);
    }
    v_5989 = nil;
    goto v_5938;
v_5940:
    goto v_5938;
    v_5989 = nil;
v_5938:
    goto v_5933;
v_5935:
    v_5990 = v_5989;
    if (!consp(v_5990)) goto v_5981;
    else goto v_5982;
v_5981:
    goto v_5933;
v_5982:
    {
        fn = elt(env, 6); // bf2flck
        return (*qfn1(fn))(fn, v_5989);
    }
    v_5989 = nil;
v_5933:
    return onevalue(v_5989);
}



// Code for getphystypesf

static LispObject CC_getphystypesf(LispObject env,
                         LispObject v_5930)
{
    env = qenv(env);
    LispObject v_5961;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5930);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_5930;
// end of prologue
v_5929:
    v_5961 = stack[0];
    if (v_5961 == nil) goto v_5938;
    else goto v_5939;
v_5938:
    v_5961 = lisp_true;
    goto v_5937;
v_5939:
    v_5961 = stack[0];
    fn = elt(env, 1); // domain!*p
    v_5961 = (*qfn1(fn))(fn, v_5961);
    env = stack[-1];
    goto v_5937;
    v_5961 = nil;
v_5937:
    if (v_5961 == nil) goto v_5935;
    v_5961 = nil;
    goto v_5933;
v_5935:
    v_5961 = stack[0];
    v_5961 = qcar(v_5961);
    v_5961 = qcar(v_5961);
    v_5961 = qcar(v_5961);
    fn = elt(env, 2); // getphystype
    v_5961 = (*qfn1(fn))(fn, v_5961);
    env = stack[-1];
    if (v_5961 == nil) goto v_5951;
    else goto v_5950;
v_5951:
    v_5961 = stack[0];
    v_5961 = qcar(v_5961);
    v_5961 = qcdr(v_5961);
    stack[0] = v_5961;
    goto v_5929;
v_5950:
    goto v_5933;
    v_5961 = nil;
v_5933:
    return onevalue(v_5961);
}



// Code for split!-road

static LispObject CC_splitKroad(LispObject env,
                         LispObject v_5930, LispObject v_5931)
{
    env = qenv(env);
    LispObject v_5974, v_5975, v_5976;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5931,v_5930);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5930,v_5931);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_5931;
    stack[-2] = v_5930;
// end of prologue
    goto v_5940;
v_5934:
    v_5974 = stack[-1];
    stack[-3] = qcar(v_5974);
    goto v_5935;
v_5936:
    goto v_5950;
v_5944:
    v_5974 = stack[-2];
    v_5976 = qcar(v_5974);
    goto v_5945;
v_5946:
    v_5974 = stack[-2];
    v_5975 = qcdr(v_5974);
    goto v_5947;
v_5948:
    v_5974 = stack[-1];
    v_5974 = qcdr(v_5974);
    v_5974 = qcar(v_5974);
    goto v_5949;
v_5950:
    goto v_5944;
v_5945:
    goto v_5946;
v_5947:
    goto v_5948;
v_5949:
    fn = elt(env, 1); // sroad
    stack[0] = (*qfnn(fn))(fn, 3, v_5976, v_5975, v_5974);
    env = stack[-4];
    goto v_5937;
v_5938:
    goto v_5965;
v_5959:
    v_5974 = stack[-2];
    v_5976 = qcar(v_5974);
    goto v_5960;
v_5961:
    v_5974 = stack[-2];
    v_5975 = qcdr(v_5974);
    goto v_5962;
v_5963:
    v_5974 = stack[-1];
    v_5974 = qcdr(v_5974);
    v_5974 = qcdr(v_5974);
    v_5974 = qcar(v_5974);
    goto v_5964;
v_5965:
    goto v_5959;
v_5960:
    goto v_5961;
v_5962:
    goto v_5963;
v_5964:
    fn = elt(env, 1); // sroad
    v_5974 = (*qfnn(fn))(fn, 3, v_5976, v_5975, v_5974);
    goto v_5939;
v_5940:
    goto v_5934;
v_5935:
    goto v_5936;
v_5937:
    goto v_5938;
v_5939:
    {
        LispObject v_5981 = stack[-3];
        LispObject v_5982 = stack[0];
        return list3(v_5981, v_5982, v_5974);
    }
}



// Code for scan

static LispObject CC_scan(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6825, v_6826, v_6827;
    LispObject fn;
    argcheck(nargs, 0, "scan");
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
    goto v_5960;
v_5956:
    v_6826 = qvalue(elt(env, 2)); // cursym!*
    goto v_5957;
v_5958:
    v_6825 = elt(env, 3); // !*semicol!*
    goto v_5959;
v_5960:
    goto v_5956;
v_5957:
    goto v_5958;
v_5959:
    if (v_6826 == v_6825) goto v_5955;
    goto v_5937;
v_5955:
v_5936:
    v_6825 = nil;
    qvalue(elt(env, 4)) = v_6825; // escaped!*
    fn = elt(env, 45); // token
    v_6825 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    qvalue(elt(env, 5)) = v_6825; // nxtsym!*
v_5937:
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    if (!consp(v_6825)) goto v_5972;
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    fn = elt(env, 46); // toknump
    v_6825 = (*qfn1(fn))(fn, v_6825);
    env = stack[-3];
    v_6825 = (v_6825 == nil ? lisp_true : nil);
    goto v_5970;
v_5972:
    v_6825 = nil;
    goto v_5970;
    v_6825 = nil;
v_5970:
    if (v_6825 == nil) goto v_5968;
    goto v_5948;
v_5968:
    goto v_5990;
v_5986:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_5987;
v_5988:
    v_6825 = elt(env, 6); // else
    goto v_5989;
v_5990:
    goto v_5986;
v_5987:
    goto v_5988;
v_5989:
    if (v_6826 == v_6825) goto v_5984;
    else goto v_5985;
v_5984:
    v_6825 = lisp_true;
    goto v_5983;
v_5985:
    goto v_6000;
v_5996:
    v_6826 = qvalue(elt(env, 2)); // cursym!*
    goto v_5997;
v_5998:
    v_6825 = elt(env, 3); // !*semicol!*
    goto v_5999;
v_6000:
    goto v_5996;
v_5997:
    goto v_5998;
v_5999:
    v_6825 = (v_6826 == v_6825 ? lisp_true : nil);
    goto v_5983;
    v_6825 = nil;
v_5983:
    if (v_6825 == nil) goto v_5981;
    v_6825 = nil;
    qvalue(elt(env, 7)) = v_6825; // outl!*
    goto v_5966;
v_5981:
v_5966:
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    fn = elt(env, 47); // prin2x
    v_6825 = (*qfn1(fn))(fn, v_6825);
    env = stack[-3];
v_5938:
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    if (symbolp(v_6825)) goto v_6010;
    goto v_5949;
v_6010:
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    if (!symbolp(v_6825)) v_6825 = nil;
    else { v_6825 = qfastgets(v_6825);
           if (v_6825 != nil) { v_6825 = elt(v_6825, 28); // newnam
#ifdef RECORD_GET
             if (v_6825 != SPID_NOPROP)
                record_get(elt(fastget_names, 28), 1);
             else record_get(elt(fastget_names, 28), 0),
                v_6825 = nil; }
           else record_get(elt(fastget_names, 28), 0); }
#else
             if (v_6825 == SPID_NOPROP) v_6825 = nil; }}
#endif
    stack[-1] = v_6825;
    if (v_6825 == nil) goto v_6013;
    goto v_6022;
v_6018:
    v_6826 = stack[-1];
    goto v_6019;
v_6020:
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6021;
v_6022:
    goto v_6018;
v_6019:
    goto v_6020;
v_6021:
    if (equal(v_6826, v_6825)) goto v_6013;
    goto v_5947;
v_6013:
    goto v_6035;
v_6031:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6032;
v_6033:
    v_6825 = elt(env, 8); // comment
    goto v_6034;
v_6035:
    goto v_6031;
v_6032:
    goto v_6033;
v_6034:
    if (v_6826 == v_6825) goto v_6029;
    else goto v_6030;
v_6029:
    v_6825 = lisp_true;
    goto v_6028;
v_6030:
    goto v_6049;
v_6045:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6046;
v_6047:
    v_6825 = elt(env, 9); // !C!O!M!M!E!N!T
    goto v_6048;
v_6049:
    goto v_6045;
v_6046:
    goto v_6047;
v_6048:
    if (v_6826 == v_6825) goto v_6043;
    else goto v_6044;
v_6043:
    v_6825 = lisp_true;
    goto v_6042;
v_6044:
    goto v_6059;
v_6055:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6056;
v_6057:
    v_6825 = elt(env, 10); // !Comment
    goto v_6058;
v_6059:
    goto v_6055;
v_6056:
    goto v_6057;
v_6058:
    v_6825 = (v_6826 == v_6825 ? lisp_true : nil);
    goto v_6042;
    v_6825 = nil;
v_6042:
    goto v_6028;
    v_6825 = nil;
v_6028:
    if (v_6825 == nil) goto v_6026;
    v_6825 = elt(env, 8); // comment
    fn = elt(env, 48); // read!-comment1
    v_6825 = (*qfn1(fn))(fn, v_6825);
    env = stack[-3];
    stack[-1] = v_6825;
    v_6825 = qvalue(elt(env, 11)); // !*comment
    if (v_6825 == nil) goto v_6068;
    v_6825 = stack[-1];
    goto v_5935;
v_6068:
    goto v_5936;
    goto v_6008;
v_6026:
    goto v_6083;
v_6079:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6080;
v_6081:
    v_6825 = elt(env, 12); // !%
    goto v_6082;
v_6083:
    goto v_6079;
v_6080:
    goto v_6081;
v_6082:
    if (v_6826 == v_6825) goto v_6077;
    else goto v_6078;
v_6077:
    goto v_6090;
v_6086:
    v_6826 = qvalue(elt(env, 13)); // ttype!*
    goto v_6087;
v_6088:
    v_6825 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_6089;
v_6090:
    goto v_6086;
v_6087:
    goto v_6088;
v_6089:
    v_6825 = (v_6826 == v_6825 ? lisp_true : nil);
    goto v_6076;
v_6078:
    v_6825 = nil;
    goto v_6076;
    v_6825 = nil;
v_6076:
    if (v_6825 == nil) goto v_6074;
    v_6825 = elt(env, 14); // percent_comment
    fn = elt(env, 48); // read!-comment1
    v_6825 = (*qfn1(fn))(fn, v_6825);
    env = stack[-3];
    stack[-1] = v_6825;
    v_6825 = qvalue(elt(env, 11)); // !*comment
    if (v_6825 == nil) goto v_6102;
    v_6825 = stack[-1];
    goto v_5935;
v_6102:
    goto v_5936;
    goto v_6008;
v_6074:
    goto v_6113;
v_6109:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6110;
v_6111:
    v_6825 = elt(env, 15); // !#if
    goto v_6112;
v_6113:
    goto v_6109;
v_6110:
    goto v_6111;
v_6112:
    if (v_6826 == v_6825) goto v_6107;
    else goto v_6108;
v_6107:
    goto v_5944;
v_6108:
    goto v_6126;
v_6122:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6123;
v_6124:
    v_6825 = elt(env, 16); // !#else
    goto v_6125;
v_6126:
    goto v_6122;
v_6123:
    goto v_6124;
v_6125:
    if (v_6826 == v_6825) goto v_6120;
    else goto v_6121;
v_6120:
    v_6825 = lisp_true;
    goto v_6119;
v_6121:
    goto v_6136;
v_6132:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6133;
v_6134:
    v_6825 = elt(env, 17); // !#elif
    goto v_6135;
v_6136:
    goto v_6132;
v_6133:
    goto v_6134;
v_6135:
    v_6825 = (v_6826 == v_6825 ? lisp_true : nil);
    goto v_6119;
    v_6825 = nil;
v_6119:
    if (v_6825 == nil) goto v_6117;
    v_6825 = nil;
    stack[-2] = v_6825;
    stack[-1] = v_6825;
    qvalue(elt(env, 5)) = v_6825; // nxtsym!*
    goto v_5945;
v_6117:
    goto v_6147;
v_6143:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6144;
v_6145:
    v_6825 = elt(env, 18); // !#endif
    goto v_6146;
v_6147:
    goto v_6143;
v_6144:
    goto v_6145;
v_6146:
    if (v_6826 == v_6825) goto v_6141;
    else goto v_6142;
v_6141:
    goto v_5936;
v_6142:
    goto v_6156;
v_6152:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6153;
v_6154:
    v_6825 = elt(env, 19); // !#eval
    goto v_6155;
v_6156:
    goto v_6152;
v_6153:
    goto v_6154;
v_6155:
    if (v_6826 == v_6825) goto v_6150;
    else goto v_6151;
v_6150:
    goto v_6166;
v_6160:
    fn = elt(env, 49); // rread
    v_6827 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_6161;
v_6162:
    v_6826 = qvalue(elt(env, 20)); // !*backtrace
    goto v_6163;
v_6164:
    v_6825 = nil;
    goto v_6165;
v_6166:
    goto v_6160;
v_6161:
    goto v_6162;
v_6163:
    goto v_6164;
v_6165:
    fn = elt(env, 50); // errorset
    v_6825 = (*qfnn(fn))(fn, 3, v_6827, v_6826, v_6825);
    env = stack[-3];
    v_6825 = nil;
    qvalue(elt(env, 4)) = v_6825; // escaped!*
    qvalue(elt(env, 21)) = v_6825; // curescaped!*
    goto v_5936;
v_6151:
    goto v_6177;
v_6173:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6174;
v_6175:
    v_6825 = elt(env, 22); // !#define
    goto v_6176;
v_6177:
    goto v_6173;
v_6174:
    goto v_6175;
v_6176:
    if (v_6826 == v_6825) goto v_6171;
    else goto v_6172;
v_6171:
    goto v_6187;
v_6181:
    v_6827 = elt(env, 23); // (rread)
    goto v_6182;
v_6183:
    v_6826 = qvalue(elt(env, 20)); // !*backtrace
    goto v_6184;
v_6185:
    v_6825 = nil;
    goto v_6186;
v_6187:
    goto v_6181;
v_6182:
    goto v_6183;
v_6184:
    goto v_6185;
v_6186:
    fn = elt(env, 50); // errorset
    v_6825 = (*qfnn(fn))(fn, 3, v_6827, v_6826, v_6825);
    env = stack[-3];
    stack[-1] = v_6825;
    v_6825 = nil;
    qvalue(elt(env, 4)) = v_6825; // escaped!*
    qvalue(elt(env, 21)) = v_6825; // curescaped!*
    v_6825 = stack[-1];
    fn = elt(env, 51); // errorp
    v_6825 = (*qfn1(fn))(fn, v_6825);
    env = stack[-3];
    if (v_6825 == nil) goto v_6195;
    goto v_5936;
v_6195:
    goto v_6205;
v_6199:
    v_6827 = elt(env, 23); // (rread)
    goto v_6200;
v_6201:
    v_6826 = qvalue(elt(env, 20)); // !*backtrace
    goto v_6202;
v_6203:
    v_6825 = nil;
    goto v_6204;
v_6205:
    goto v_6199;
v_6200:
    goto v_6201;
v_6202:
    goto v_6203;
v_6204:
    fn = elt(env, 50); // errorset
    v_6825 = (*qfnn(fn))(fn, 3, v_6827, v_6826, v_6825);
    env = stack[-3];
    stack[0] = v_6825;
    v_6825 = nil;
    qvalue(elt(env, 4)) = v_6825; // escaped!*
    qvalue(elt(env, 21)) = v_6825; // curescaped!*
    v_6825 = stack[0];
    fn = elt(env, 51); // errorp
    v_6825 = (*qfn1(fn))(fn, v_6825);
    env = stack[-3];
    if (v_6825 == nil) goto v_6213;
    goto v_5936;
v_6213:
    goto v_6223;
v_6217:
    v_6825 = stack[-1];
    v_6827 = qcar(v_6825);
    goto v_6218;
v_6219:
    v_6826 = elt(env, 24); // newnam
    goto v_6220;
v_6221:
    v_6825 = stack[0];
    v_6825 = qcar(v_6825);
    goto v_6222;
v_6223:
    goto v_6217;
v_6218:
    goto v_6219;
v_6220:
    goto v_6221;
v_6222:
    v_6825 = Lputprop(nil, 3, v_6827, v_6826, v_6825);
    env = stack[-3];
    v_6825 = elt(env, 25); // "*** "
    v_6825 = Lprinc(nil, v_6825);
    env = stack[-3];
    v_6825 = stack[-1];
    v_6825 = qcar(v_6825);
    v_6825 = Lprin(nil, v_6825);
    env = stack[-3];
    v_6825 = elt(env, 26); // " => "
    v_6825 = Lprinc(nil, v_6825);
    env = stack[-3];
    v_6825 = stack[0];
    v_6825 = qcar(v_6825);
    v_6825 = Lprint(nil, v_6825);
    env = stack[-3];
    goto v_5936;
v_6172:
    goto v_6245;
v_6241:
    v_6826 = qvalue(elt(env, 13)); // ttype!*
    goto v_6242;
v_6243:
    v_6825 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_6244;
v_6245:
    goto v_6241;
v_6242:
    goto v_6243;
v_6244:
    if (v_6826 == v_6825) goto v_6240;
    goto v_5949;
v_6240:
    goto v_6254;
v_6250:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6251;
v_6252:
    v_6825 = qvalue(elt(env, 27)); // !$eof!$
    goto v_6253;
v_6254:
    goto v_6250;
v_6251:
    goto v_6252;
v_6253:
    if (v_6826 == v_6825) goto v_6248;
    else goto v_6249;
v_6248:
    {
        fn = elt(env, 52); // filenderr
        return (*qfnn(fn))(fn, 0);
    }
v_6249:
    goto v_6264;
v_6260:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6261;
v_6262:
    v_6825 = elt(env, 28); // !'
    goto v_6263;
v_6264:
    goto v_6260;
v_6261:
    goto v_6262;
v_6263:
    if (v_6826 == v_6825) goto v_6258;
    else goto v_6259;
v_6258:
    v_6825 = elt(env, 29); // "Invalid QUOTE"
    fn = elt(env, 53); // rederr
    v_6825 = (*qfn1(fn))(fn, v_6825);
    env = stack[-3];
    goto v_6008;
v_6259:
    v_6825 = qvalue(elt(env, 30)); // !*eoldelimp
    if (v_6825 == nil) goto v_6270;
    goto v_6278;
v_6274:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6275;
v_6276:
    v_6825 = qvalue(elt(env, 31)); // !$eol!$
    goto v_6277;
v_6278:
    goto v_6274;
v_6275:
    goto v_6276;
v_6277:
    if (v_6826 == v_6825) goto v_6273;
    else goto v_6270;
v_6273:
    goto v_5946;
v_6270:
    goto v_6291;
v_6287:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6288;
v_6289:
    v_6825 = elt(env, 32); // !#
    goto v_6290;
v_6291:
    goto v_6287;
v_6288:
    goto v_6289;
v_6290:
    if (v_6826 == v_6825) goto v_6285;
    else goto v_6286;
v_6285:
    v_6825 = qvalue(elt(env, 33)); // crchar!*
    v_6825 = Lwhitespace_char_p(nil, v_6825);
    env = stack[-3];
    v_6825 = (v_6825 == nil ? lisp_true : nil);
    goto v_6284;
v_6286:
    v_6825 = nil;
    goto v_6284;
    v_6825 = nil;
v_6284:
    if (v_6825 == nil) goto v_6282;
    goto v_5942;
v_6282:
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    if (!symbolp(v_6825)) v_6825 = nil;
    else { v_6825 = qfastgets(v_6825);
           if (v_6825 != nil) { v_6825 = elt(v_6825, 11); // switch!*
#ifdef RECORD_GET
             if (v_6825 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v_6825 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v_6825 == SPID_NOPROP) v_6825 = nil; }}
#endif
    stack[-1] = v_6825;
    if (v_6825 == nil) goto v_6300;
    else goto v_6301;
v_6300:
    goto v_5949;
v_6301:
    goto v_6311;
v_6307:
    v_6825 = stack[-1];
    v_6826 = qcdr(v_6825);
    goto v_6308;
v_6309:
    v_6825 = elt(env, 3); // !*semicol!*
    goto v_6310;
v_6311:
    goto v_6307;
v_6308:
    goto v_6309;
v_6310:
    if (!consp(v_6826)) goto v_6305;
    v_6826 = qcar(v_6826);
    if (v_6826 == v_6825) goto v_6304;
    else goto v_6305;
v_6304:
    goto v_5946;
v_6305:
v_6008:
    v_6825 = qvalue(elt(env, 33)); // crchar!*
    v_6825 = Lwhitespace_char_p(nil, v_6825);
    env = stack[-3];
    stack[-2] = v_6825;
v_5939:
    fn = elt(env, 45); // token
    v_6825 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    qvalue(elt(env, 5)) = v_6825; // nxtsym!*
    goto v_6326;
v_6322:
    v_6826 = qvalue(elt(env, 13)); // ttype!*
    goto v_6323;
v_6324:
    v_6825 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_6325;
v_6326:
    goto v_6322;
v_6323:
    goto v_6324;
v_6325:
    if (v_6826 == v_6825) goto v_6321;
    goto v_5940;
v_6321:
    goto v_6335;
v_6331:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6332;
v_6333:
    v_6825 = qvalue(elt(env, 27)); // !$eof!$
    goto v_6334;
v_6335:
    goto v_6331;
v_6332:
    goto v_6333;
v_6334:
    if (v_6826 == v_6825) goto v_6329;
    else goto v_6330;
v_6329:
    {
        fn = elt(env, 52); // filenderr
        return (*qfnn(fn))(fn, 0);
    }
v_6330:
    v_6825 = stack[-1];
    v_6825 = qcar(v_6825);
    if (v_6825 == nil) goto v_6340;
    goto v_5941;
v_6340:
v_5940:
    v_6825 = stack[-1];
    v_6825 = qcdr(v_6825);
    v_6825 = qcar(v_6825);
    qvalue(elt(env, 2)) = v_6825; // cursym!*
    v_6825 = nil;
    qvalue(elt(env, 21)) = v_6825; // curescaped!*
    goto v_6356;
v_6352:
    v_6826 = qvalue(elt(env, 2)); // cursym!*
    goto v_6353;
v_6354:
    v_6825 = elt(env, 34); // !*rpar!*
    goto v_6355;
v_6356:
    goto v_6352;
v_6353:
    goto v_6354;
v_6355:
    if (v_6826 == v_6825) goto v_6350;
    else goto v_6351;
v_6350:
    goto v_5950;
v_6351:
    v_6825 = qvalue(elt(env, 2)); // cursym!*
    {
        fn = elt(env, 54); // addcomment
        return (*qfn1(fn))(fn, v_6825);
    }
v_5941:
    v_6825 = stack[-2];
    if (v_6825 == nil) goto v_6367;
    else goto v_6365;
v_6367:
    goto v_6374;
v_6370:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6371;
v_6372:
    v_6825 = stack[-1];
    v_6825 = qcar(v_6825);
    goto v_6373;
v_6374:
    goto v_6370;
v_6371:
    goto v_6372;
v_6373:
    v_6825 = Latsoc(nil, v_6826, v_6825);
    stack[0] = v_6825;
    if (v_6825 == nil) goto v_6365;
    goto v_6366;
v_6365:
    goto v_5940;
v_6366:
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    fn = elt(env, 47); // prin2x
    v_6825 = (*qfn1(fn))(fn, v_6825);
    env = stack[-3];
    v_6825 = stack[0];
    v_6825 = qcdr(v_6825);
    stack[-1] = v_6825;
    v_6825 = stack[-1];
    v_6825 = qcar(v_6825);
    if (v_6825 == nil) goto v_6389;
    else goto v_6390;
v_6389:
    goto v_6397;
v_6393:
    v_6825 = stack[-1];
    v_6825 = qcdr(v_6825);
    v_6826 = qcar(v_6825);
    goto v_6394;
v_6395:
    v_6825 = elt(env, 35); // !*comment!*
    goto v_6396;
v_6397:
    goto v_6393;
v_6394:
    goto v_6395;
v_6396:
    v_6825 = (v_6826 == v_6825 ? lisp_true : nil);
    goto v_6388;
v_6390:
    v_6825 = nil;
    goto v_6388;
    v_6825 = nil;
v_6388:
    if (v_6825 == nil) goto v_6386;
    fn = elt(env, 55); // read!-comment
    v_6825 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    qvalue(elt(env, 36)) = v_6825; // comment!*
    goto v_5936;
v_6386:
    goto v_5939;
v_5942:
    v_6825 = nil;
    stack[-2] = v_6825;
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    if (!symbolp(v_6825)) v_6825 = nil;
    else { v_6825 = qfastgets(v_6825);
           if (v_6825 != nil) { v_6825 = elt(v_6825, 11); // switch!*
#ifdef RECORD_GET
             if (v_6825 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v_6825 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v_6825 == SPID_NOPROP) v_6825 = nil; }}
#endif
    stack[-1] = v_6825;
    fn = elt(env, 45); // token
    v_6825 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    qvalue(elt(env, 5)) = v_6825; // nxtsym!*
    goto v_6423;
v_6419:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6420;
v_6421:
    v_6825 = elt(env, 37); // if
    goto v_6422;
v_6423:
    goto v_6419;
v_6420:
    goto v_6421;
v_6422:
    if (v_6826 == v_6825) goto v_6417;
    else goto v_6418;
v_6417:
    v_6825 = lisp_true;
    goto v_6416;
v_6418:
    goto v_6437;
v_6433:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6434;
v_6435:
    v_6825 = elt(env, 6); // else
    goto v_6436;
v_6437:
    goto v_6433;
v_6434:
    goto v_6435;
v_6436:
    if (v_6826 == v_6825) goto v_6431;
    else goto v_6432;
v_6431:
    v_6825 = lisp_true;
    goto v_6430;
v_6432:
    goto v_6451;
v_6447:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6448;
v_6449:
    v_6825 = elt(env, 38); // elif
    goto v_6450;
v_6451:
    goto v_6447;
v_6448:
    goto v_6449;
v_6450:
    if (v_6826 == v_6825) goto v_6445;
    else goto v_6446;
v_6445:
    v_6825 = lisp_true;
    goto v_6444;
v_6446:
    goto v_6465;
v_6461:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6462;
v_6463:
    v_6825 = elt(env, 39); // endif
    goto v_6464;
v_6465:
    goto v_6461;
v_6462:
    goto v_6463;
v_6464:
    if (v_6826 == v_6825) goto v_6459;
    else goto v_6460;
v_6459:
    v_6825 = lisp_true;
    goto v_6458;
v_6460:
    goto v_6479;
v_6475:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6476;
v_6477:
    v_6825 = elt(env, 40); // eval
    goto v_6478;
v_6479:
    goto v_6475;
v_6476:
    goto v_6477;
v_6478:
    if (v_6826 == v_6825) goto v_6473;
    else goto v_6474;
v_6473:
    v_6825 = lisp_true;
    goto v_6472;
v_6474:
    goto v_6489;
v_6485:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6486;
v_6487:
    v_6825 = elt(env, 41); // define
    goto v_6488;
v_6489:
    goto v_6485;
v_6486:
    goto v_6487;
v_6488:
    v_6825 = (v_6826 == v_6825 ? lisp_true : nil);
    goto v_6472;
    v_6825 = nil;
v_6472:
    goto v_6458;
    v_6825 = nil;
v_6458:
    goto v_6444;
    v_6825 = nil;
v_6444:
    goto v_6430;
    v_6825 = nil;
v_6430:
    goto v_6416;
    v_6825 = nil;
v_6416:
    if (v_6825 == nil) goto v_6414;
    goto v_5943;
v_6414:
    goto v_6501;
v_6497:
    v_6826 = qvalue(elt(env, 13)); // ttype!*
    goto v_6498;
v_6499:
    v_6825 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_6500;
v_6501:
    goto v_6497;
v_6498:
    goto v_6499;
v_6500:
    if (v_6826 == v_6825) goto v_6496;
    goto v_5940;
v_6496:
    goto v_6510;
v_6506:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6507;
v_6508:
    v_6825 = qvalue(elt(env, 27)); // !$eof!$
    goto v_6509;
v_6510:
    goto v_6506;
v_6507:
    goto v_6508;
v_6509:
    if (v_6826 == v_6825) goto v_6504;
    else goto v_6505;
v_6504:
    {
        fn = elt(env, 52); // filenderr
        return (*qfnn(fn))(fn, 0);
    }
v_6505:
    v_6825 = stack[-1];
    v_6825 = qcar(v_6825);
    if (v_6825 == nil) goto v_6515;
    goto v_5941;
v_6515:
    goto v_5940;
v_5943:
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    fn = elt(env, 47); // prin2x
    v_6825 = (*qfn1(fn))(fn, v_6825);
    env = stack[-3];
    goto v_6527;
v_6523:
    stack[0] = elt(env, 32); // !#
    goto v_6524;
v_6525:
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    v_6825 = Lexplodec(nil, v_6825);
    env = stack[-3];
    goto v_6526;
v_6527:
    goto v_6523;
v_6524:
    goto v_6525;
v_6526:
    v_6825 = cons(stack[0], v_6825);
    env = stack[-3];
    fn = elt(env, 56); // list2string
    v_6825 = (*qfn1(fn))(fn, v_6825);
    env = stack[-3];
    v_6825 = Lintern(nil, v_6825);
    env = stack[-3];
    qvalue(elt(env, 5)) = v_6825; // nxtsym!*
    goto v_5938;
v_5944:
    goto v_6538;
v_6532:
    fn = elt(env, 49); // rread
    v_6827 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_6533;
v_6534:
    v_6826 = qvalue(elt(env, 20)); // !*backtrace
    goto v_6535;
v_6536:
    v_6825 = nil;
    goto v_6537;
v_6538:
    goto v_6532;
v_6533:
    goto v_6534;
v_6535:
    goto v_6536;
v_6537:
    fn = elt(env, 50); // errorset
    v_6825 = (*qfnn(fn))(fn, 3, v_6827, v_6826, v_6825);
    env = stack[-3];
    stack[-1] = v_6825;
    v_6825 = nil;
    qvalue(elt(env, 4)) = v_6825; // escaped!*
    qvalue(elt(env, 21)) = v_6825; // curescaped!*
    v_6825 = stack[-1];
    fn = elt(env, 51); // errorp
    v_6825 = (*qfn1(fn))(fn, v_6825);
    env = stack[-3];
    if (v_6825 == nil) goto v_6549;
    else goto v_6550;
v_6549:
    v_6825 = stack[-1];
    v_6825 = qcar(v_6825);
    goto v_6548;
v_6550:
    v_6825 = nil;
    goto v_6548;
    v_6825 = nil;
v_6548:
    if (v_6825 == nil) goto v_6546;
    goto v_5936;
v_6546:
    v_6825 = nil;
    stack[-1] = v_6825;
    v_6825 = lisp_true;
    stack[-2] = v_6825;
v_5945:
    goto v_6572;
v_6568:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6569;
v_6570:
    v_6825 = elt(env, 32); // !#
    goto v_6571;
v_6572:
    goto v_6568;
v_6569:
    goto v_6570;
v_6571:
    if (v_6826 == v_6825) goto v_6566;
    else goto v_6567;
v_6566:
    goto v_6583;
v_6579:
    v_6826 = qvalue(elt(env, 13)); // ttype!*
    goto v_6580;
v_6581:
    v_6825 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_6582;
v_6583:
    goto v_6579;
v_6580:
    goto v_6581;
v_6582:
    if (v_6826 == v_6825) goto v_6577;
    else goto v_6578;
v_6577:
    v_6825 = qvalue(elt(env, 33)); // crchar!*
    v_6825 = Lwhitespace_char_p(nil, v_6825);
    env = stack[-3];
    v_6825 = (v_6825 == nil ? lisp_true : nil);
    goto v_6576;
v_6578:
    v_6825 = nil;
    goto v_6576;
    v_6825 = nil;
v_6576:
    goto v_6565;
v_6567:
    v_6825 = nil;
    goto v_6565;
    v_6825 = nil;
v_6565:
    if (v_6825 == nil) goto v_6563;
    fn = elt(env, 45); // token
    v_6825 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    qvalue(elt(env, 5)) = v_6825; // nxtsym!*
    goto v_6604;
v_6600:
    v_6826 = qvalue(elt(env, 13)); // ttype!*
    goto v_6601;
v_6602:
    v_6825 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6603;
v_6604:
    goto v_6600;
v_6601:
    goto v_6602;
v_6603:
    if (v_6826 == v_6825) goto v_6598;
    else goto v_6599;
v_6598:
    goto v_6614;
v_6610:
    stack[0] = elt(env, 32); // !#
    goto v_6611;
v_6612:
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    v_6825 = Lexplodec(nil, v_6825);
    env = stack[-3];
    goto v_6613;
v_6614:
    goto v_6610;
v_6611:
    goto v_6612;
v_6613:
    v_6825 = cons(stack[0], v_6825);
    env = stack[-3];
    fn = elt(env, 56); // list2string
    v_6825 = (*qfn1(fn))(fn, v_6825);
    env = stack[-3];
    v_6825 = Lintern(nil, v_6825);
    env = stack[-3];
    qvalue(elt(env, 5)) = v_6825; // nxtsym!*
    goto v_6597;
v_6599:
v_6597:
    goto v_6561;
v_6563:
v_6561:
    goto v_6626;
v_6622:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6623;
v_6624:
    v_6825 = elt(env, 18); // !#endif
    goto v_6625;
v_6626:
    goto v_6622;
v_6623:
    goto v_6624;
v_6625:
    if (v_6826 == v_6825) goto v_6620;
    else goto v_6621;
v_6620:
    v_6825 = stack[-1];
    if (v_6825 == nil) goto v_6631;
    else goto v_6632;
v_6631:
    goto v_5936;
v_6632:
    v_6825 = stack[-1];
    v_6825 = qcdr(v_6825);
    stack[-1] = v_6825;
    goto v_6630;
v_6630:
    goto v_6619;
v_6621:
    goto v_6644;
v_6640:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6641;
v_6642:
    v_6825 = elt(env, 15); // !#if
    goto v_6643;
v_6644:
    goto v_6640;
v_6641:
    goto v_6642;
v_6643:
    if (v_6826 == v_6825) goto v_6638;
    else goto v_6639;
v_6638:
    goto v_6652;
v_6648:
    v_6826 = nil;
    goto v_6649;
v_6650:
    v_6825 = stack[-1];
    goto v_6651;
v_6652:
    goto v_6648;
v_6649:
    goto v_6650;
v_6651:
    v_6825 = cons(v_6826, v_6825);
    env = stack[-3];
    stack[-1] = v_6825;
    goto v_6619;
v_6639:
    goto v_6665;
v_6661:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6662;
v_6663:
    v_6825 = elt(env, 16); // !#else
    goto v_6664;
v_6665:
    goto v_6661;
v_6662:
    goto v_6663;
v_6664:
    if (v_6826 == v_6825) goto v_6659;
    else goto v_6660;
v_6659:
    v_6825 = stack[-1];
    if (v_6825 == nil) goto v_6670;
    else goto v_6671;
v_6670:
    v_6825 = stack[-2];
    goto v_6669;
v_6671:
    v_6825 = nil;
    goto v_6669;
    v_6825 = nil;
v_6669:
    goto v_6658;
v_6660:
    v_6825 = nil;
    goto v_6658;
    v_6825 = nil;
v_6658:
    if (v_6825 == nil) goto v_6656;
    goto v_5936;
v_6656:
    goto v_6690;
v_6686:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6687;
v_6688:
    v_6825 = elt(env, 17); // !#elif
    goto v_6689;
v_6690:
    goto v_6686;
v_6687:
    goto v_6688;
v_6689:
    if (v_6826 == v_6825) goto v_6684;
    else goto v_6685;
v_6684:
    v_6825 = stack[-1];
    if (v_6825 == nil) goto v_6695;
    else goto v_6696;
v_6695:
    v_6825 = stack[-2];
    goto v_6694;
v_6696:
    v_6825 = nil;
    goto v_6694;
    v_6825 = nil;
v_6694:
    goto v_6683;
v_6685:
    v_6825 = nil;
    goto v_6683;
    v_6825 = nil;
v_6683:
    if (v_6825 == nil) goto v_6681;
    goto v_5944;
v_6681:
v_6619:
    fn = elt(env, 45); // token
    v_6825 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    qvalue(elt(env, 5)) = v_6825; // nxtsym!*
    goto v_6718;
v_6714:
    v_6826 = qvalue(elt(env, 13)); // ttype!*
    goto v_6715;
v_6716:
    v_6825 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_6717;
v_6718:
    goto v_6714;
v_6715:
    goto v_6716;
v_6717:
    if (v_6826 == v_6825) goto v_6712;
    else goto v_6713;
v_6712:
    goto v_6725;
v_6721:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6722;
v_6723:
    v_6825 = qvalue(elt(env, 27)); // !$eof!$
    goto v_6724;
v_6725:
    goto v_6721;
v_6722:
    goto v_6723;
v_6724:
    v_6825 = (v_6826 == v_6825 ? lisp_true : nil);
    goto v_6711;
v_6713:
    v_6825 = nil;
    goto v_6711;
    v_6825 = nil;
v_6711:
    if (v_6825 == nil) goto v_6709;
    {
        fn = elt(env, 52); // filenderr
        return (*qfnn(fn))(fn, 0);
    }
v_6709:
    goto v_5945;
v_5946:
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    qvalue(elt(env, 42)) = v_6825; // semic!*
    v_6825 = nil;
    qvalue(elt(env, 21)) = v_6825; // curescaped!*
    v_6825 = elt(env, 3); // !*semicol!*
    {
        fn = elt(env, 54); // addcomment
        return (*qfn1(fn))(fn, v_6825);
    }
v_5947:
    v_6825 = stack[-1];
    qvalue(elt(env, 5)) = v_6825; // nxtsym!*
    v_6825 = stack[-1];
    v_6825 = Lstringp(nil, v_6825);
    env = stack[-3];
    if (v_6825 == nil) goto v_6743;
    goto v_5949;
v_6743:
    v_6825 = stack[-1];
    if (!consp(v_6825)) goto v_6746;
    else goto v_6747;
v_6746:
    goto v_5938;
v_6747:
    goto v_5949;
v_5948:
    goto v_6759;
v_6755:
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    v_6826 = qcar(v_6825);
    goto v_6756;
v_6757:
    v_6825 = elt(env, 43); // string
    goto v_6758;
v_6759:
    goto v_6755;
v_6756:
    goto v_6757;
v_6758:
    if (v_6826 == v_6825) goto v_6754;
    goto v_5949;
v_6754:
    v_6825 = elt(env, 44); // " "
    fn = elt(env, 47); // prin2x
    v_6825 = (*qfn1(fn))(fn, v_6825);
    env = stack[-3];
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    v_6825 = qcdr(v_6825);
    v_6825 = qcar(v_6825);
    v_6825 = Lmkquote(nil, v_6825);
    env = stack[-3];
    qvalue(elt(env, 5)) = v_6825; // nxtsym!*
    v_6825 = qcdr(v_6825);
    v_6825 = qcar(v_6825);
    fn = elt(env, 47); // prin2x
    v_6825 = (*qfn1(fn))(fn, v_6825);
    env = stack[-3];
v_5949:
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    qvalue(elt(env, 2)) = v_6825; // cursym!*
    v_6825 = qvalue(elt(env, 4)); // escaped!*
    qvalue(elt(env, 21)) = v_6825; // curescaped!*
    v_6825 = nil;
    qvalue(elt(env, 4)) = v_6825; // escaped!*
    fn = elt(env, 45); // token
    v_6825 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    qvalue(elt(env, 5)) = v_6825; // nxtsym!*
    goto v_6788;
v_6784:
    v_6826 = qvalue(elt(env, 5)); // nxtsym!*
    goto v_6785;
v_6786:
    v_6825 = qvalue(elt(env, 27)); // !$eof!$
    goto v_6787;
v_6788:
    goto v_6784;
v_6785:
    goto v_6786;
v_6787:
    if (v_6826 == v_6825) goto v_6782;
    else goto v_6783;
v_6782:
    goto v_6795;
v_6791:
    v_6826 = qvalue(elt(env, 13)); // ttype!*
    goto v_6792;
v_6793:
    v_6825 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_6794;
v_6795:
    goto v_6791;
v_6792:
    goto v_6793;
v_6794:
    v_6825 = (v_6826 == v_6825 ? lisp_true : nil);
    goto v_6781;
v_6783:
    v_6825 = nil;
    goto v_6781;
    v_6825 = nil;
v_6781:
    if (v_6825 == nil) goto v_6779;
    {
        fn = elt(env, 52); // filenderr
        return (*qfnn(fn))(fn, 0);
    }
v_6779:
v_5950:
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    if (is_number(v_6825)) goto v_6805;
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    if (!consp(v_6825)) goto v_6812;
    else goto v_6813;
v_6812:
    v_6825 = qvalue(elt(env, 5)); // nxtsym!*
    if (!symbolp(v_6825)) v_6825 = nil;
    else { v_6825 = qfastgets(v_6825);
           if (v_6825 != nil) { v_6825 = elt(v_6825, 11); // switch!*
#ifdef RECORD_GET
             if (v_6825 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v_6825 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v_6825 == SPID_NOPROP) v_6825 = nil; }}
#endif
    v_6825 = (v_6825 == nil ? lisp_true : nil);
    goto v_6811;
v_6813:
    v_6825 = nil;
    goto v_6811;
    v_6825 = nil;
v_6811:
    if (v_6825 == nil) goto v_6809;
    else goto v_6805;
v_6809:
    goto v_6806;
v_6805:
    v_6825 = elt(env, 44); // " "
    fn = elt(env, 47); // prin2x
    v_6825 = (*qfn1(fn))(fn, v_6825);
    env = stack[-3];
    goto v_6804;
v_6806:
v_6804:
    v_6825 = qvalue(elt(env, 2)); // cursym!*
    {
        fn = elt(env, 54); // addcomment
        return (*qfn1(fn))(fn, v_6825);
    }
v_5935:
    return onevalue(v_6825);
}



setup_type const u12_setup[] =
{
    {"convertmode1",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_convertmode1},
    {"simp",                    CC_simp,        TOO_MANY_1,    WRONG_NO_1},
    {"dp=mocompare",            TOO_FEW_2,      CC_dpMmocompare,WRONG_NO_2},
    {"pv_neg",                  CC_pv_neg,      TOO_MANY_1,    WRONG_NO_1},
    {"ra_budan-transform",      CC_ra_budanKtransform,TOO_MANY_1,WRONG_NO_1},
    {"lalr_lr0_itemset_to_lalr_kernel",CC_lalr_lr0_itemset_to_lalr_kernel,TOO_MANY_1,WRONG_NO_1},
    {"monommultiplybyvariable", TOO_FEW_2,      CC_monommultiplybyvariable,WRONG_NO_2},
    {"ordpa",                   TOO_FEW_2,      CC_ordpa,      WRONG_NO_2},
    {"totalcompare",            TOO_FEW_2,      CC_totalcompare,WRONG_NO_2},
    {"msappend",                TOO_FEW_2,      CC_msappend,   WRONG_NO_2},
    {"rl_smrmknowl",            TOO_FEW_2,      CC_rl_smrmknowl,WRONG_NO_2},
    {"qsort",                   CC_qsort,       TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_litp",              CC_ibalp_litp,  TOO_MANY_1,    WRONG_NO_1},
    {"comm_kernels1",           TOO_FEW_2,      CC_comm_kernels1,WRONG_NO_2},
    {"id2bytelist",             CC_id2bytelist, TOO_MANY_1,    WRONG_NO_1},
    {"safe-fp-times",           TOO_FEW_2,      CC_safeKfpKtimes,WRONG_NO_2},
    {"contr1-strand",           TOO_FEW_2,      CC_contr1Kstrand,WRONG_NO_2},
    {"form1",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_form1},
    {"argnochk",                CC_argnochk,    TOO_MANY_1,    WRONG_NO_1},
    {"red_divtest",             TOO_FEW_2,      CC_red_divtest,WRONG_NO_2},
    {"mconv",                   CC_mconv,       TOO_MANY_1,    WRONG_NO_1},
    {"lalr_prin_nonterminal",   CC_lalr_prin_nonterminal,TOO_MANY_1,WRONG_NO_1},
    {"processcarpartitie1",     WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_processcarpartitie1},
    {"color1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_color1},
    {"cl_simpl",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_simpl},
    {"ibalp_atomp",             CC_ibalp_atomp, TOO_MANY_1,    WRONG_NO_1},
    {"basicom",                 CC_basicom,     TOO_MANY_1,    WRONG_NO_1},
    {"simpexpon1",              TOO_FEW_2,      CC_simpexpon1, WRONG_NO_2},
    {"writepri",                TOO_FEW_2,      CC_writepri,   WRONG_NO_2},
    {"initwght",                CC_initwght,    TOO_MANY_1,    WRONG_NO_1},
    {"revalind",                CC_revalind,    TOO_MANY_1,    WRONG_NO_1},
    {"gfrsq",                   CC_gfrsq,       TOO_MANY_1,    WRONG_NO_1},
    {"convchk",                 CC_convchk,     TOO_MANY_1,    WRONG_NO_1},
    {"getphystypesf",           CC_getphystypesf,TOO_MANY_1,   WRONG_NO_1},
    {"split-road",              TOO_FEW_2,      CC_splitKroad, WRONG_NO_2},
    {"scan",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_scan},
    {NULL, (one_args *)"u12", (two_args *)"155578 4435517 38431", 0}
};

// end of generated code
