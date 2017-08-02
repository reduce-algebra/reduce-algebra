
// $destdir/u18.c        Machine generated C code

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



// Code for pv_times1

static LispObject CC_pv_times1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_9041, v_9042, v_9043;
    LispObject fn;
    LispObject v_9012, v_9011, v_9010;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pv_times1");
    va_start(aa, nargs);
    v_9010 = va_arg(aa, LispObject);
    v_9011 = va_arg(aa, LispObject);
    v_9012 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_9012,v_9011,v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_9010,v_9011,v_9012);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_9042 = v_9012;
    stack[0] = v_9011;
    v_9041 = v_9010;
// end of prologue
v_9017:
    v_9043 = v_9041;
    if (v_9043 == nil) goto v_9020;
    else goto v_9021;
v_9020:
    v_9041 = v_9042;
    goto v_9016;
v_9021:
    v_9043 = v_9041;
    v_9043 = qcdr(v_9043);
    stack[-1] = v_9043;
    goto v_9035;
v_9029:
    v_9043 = qcar(v_9041);
    goto v_9030;
v_9031:
    v_9041 = stack[0];
    goto v_9032;
v_9033:
    goto v_9034;
v_9035:
    goto v_9029;
v_9030:
    goto v_9031;
v_9032:
    goto v_9033;
v_9034:
    fn = elt(env, 1); // pv_times2
    v_9041 = (*qfnn(fn))(fn, 3, v_9043, v_9041, v_9042);
    env = stack[-2];
    v_9042 = v_9041;
    v_9041 = stack[-1];
    goto v_9017;
    v_9041 = nil;
v_9016:
    return onevalue(v_9041);
}



// Code for lex_restore_context

static LispObject CC_lex_restore_context(LispObject env,
                         LispObject v_9010)
{
    env = qenv(env);
    LispObject v_9110, v_9111, v_9112;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9010);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_9010;
// end of prologue
    fn = elt(env, 8); // lex_cleanup
    v_9110 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    v_9110 = stack[0];
    stack[0] = v_9110;
v_9022:
    v_9110 = stack[0];
    if (v_9110 == nil) goto v_9026;
    else goto v_9027;
v_9026:
    goto v_9021;
v_9027:
    v_9110 = stack[0];
    v_9110 = qcar(v_9110);
    v_9111 = v_9110;
    v_9110 = v_9111;
    v_9110 = qcar(v_9110);
    stack[-2] = v_9110;
    v_9110 = v_9111;
    v_9110 = qcdr(v_9110);
    v_9110 = qcar(v_9110);
    stack[-1] = v_9110;
    v_9110 = v_9111;
    v_9110 = qcdr(v_9110);
    v_9110 = qcdr(v_9110);
    v_9110 = Lintern(nil, v_9110);
    env = stack[-4];
    stack[-3] = v_9110;
    goto v_9051;
v_9047:
    v_9111 = stack[-3];
    goto v_9048;
v_9049:
    v_9110 = elt(env, 2); // lex_fixed_code
    goto v_9050;
v_9051:
    goto v_9047;
v_9048:
    goto v_9049;
v_9050:
    v_9110 = get(v_9111, v_9110);
    env = stack[-4];
    if (v_9110 == nil) goto v_9044;
    else goto v_9045;
v_9044:
    goto v_9063;
v_9059:
    v_9111 = stack[-1];
    goto v_9060;
v_9061:
    v_9110 = qvalue(elt(env, 3)); // lex_next_code
    goto v_9062;
v_9063:
    goto v_9059;
v_9060:
    goto v_9061;
v_9062:
    v_9110 = (LispObject)greaterp2(v_9111, v_9110);
    v_9110 = v_9110 ? lisp_true : nil;
    env = stack[-4];
    if (v_9110 == nil) goto v_9057;
    v_9110 = stack[-1];
    qvalue(elt(env, 3)) = v_9110; // lex_next_code
    goto v_9055;
v_9057:
v_9055:
    goto v_9074;
v_9068:
    v_9112 = stack[-3];
    goto v_9069;
v_9070:
    v_9111 = elt(env, 4); // lex_dipthong
    goto v_9071;
v_9072:
    v_9110 = stack[-2];
    goto v_9073;
v_9074:
    goto v_9068;
v_9069:
    goto v_9070;
v_9071:
    goto v_9072;
v_9073:
    v_9110 = Lputprop(nil, 3, v_9112, v_9111, v_9110);
    env = stack[-4];
    goto v_9085;
v_9079:
    v_9112 = stack[-3];
    goto v_9080;
v_9081:
    v_9111 = elt(env, 5); // lex_code
    goto v_9082;
v_9083:
    v_9110 = stack[-1];
    goto v_9084;
v_9085:
    goto v_9079;
v_9080:
    goto v_9081;
v_9082:
    goto v_9083;
v_9084:
    v_9110 = Lputprop(nil, 3, v_9112, v_9111, v_9110);
    env = stack[-4];
    goto v_9096;
v_9090:
    v_9112 = stack[-1];
    goto v_9091;
v_9092:
    v_9111 = stack[-3];
    goto v_9093;
v_9094:
    v_9110 = qvalue(elt(env, 6)); // lex_codename
    goto v_9095;
v_9096:
    goto v_9090;
v_9091:
    goto v_9092;
v_9093:
    goto v_9094;
v_9095:
    v_9110 = acons(v_9112, v_9111, v_9110);
    env = stack[-4];
    qvalue(elt(env, 6)) = v_9110; // lex_codename
    goto v_9105;
v_9101:
    v_9111 = stack[-3];
    goto v_9102;
v_9103:
    v_9110 = qvalue(elt(env, 7)); // lex_keyword_names
    goto v_9104;
v_9105:
    goto v_9101;
v_9102:
    goto v_9103;
v_9104:
    v_9110 = cons(v_9111, v_9110);
    env = stack[-4];
    qvalue(elt(env, 7)) = v_9110; // lex_keyword_names
    goto v_9043;
v_9045:
v_9043:
    v_9110 = stack[0];
    v_9110 = qcdr(v_9110);
    stack[0] = v_9110;
    goto v_9022;
v_9021:
    v_9110 = nil;
    return onevalue(v_9110);
}



// Code for sfto_kexp

static LispObject CC_sfto_kexp(LispObject env,
                         LispObject v_9010, LispObject v_9011)
{
    env = qenv(env);
    LispObject v_9049, v_9050;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9011,v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9010,v_9011);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_9011;
    stack[-1] = v_9010;
// end of prologue
    goto v_9016;
    goto v_9014;
v_9016:
v_9014:
    goto v_9027;
v_9023:
    v_9050 = stack[0];
    goto v_9024;
v_9025:
    v_9049 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9026;
v_9027:
    goto v_9023;
v_9024:
    goto v_9025;
v_9026:
    v_9049 = Leqn(nil, v_9050, v_9049);
    env = stack[-2];
    if (v_9049 == nil) goto v_9021;
    v_9049 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9019;
v_9021:
    goto v_9039;
v_9035:
    goto v_9045;
v_9041:
    v_9050 = stack[-1];
    goto v_9042;
v_9043:
    v_9049 = stack[0];
    goto v_9044;
v_9045:
    goto v_9041;
v_9042:
    goto v_9043;
v_9044:
    fn = elt(env, 1); // to
    v_9050 = (*qfn2(fn))(fn, v_9050, v_9049);
    env = stack[-2];
    goto v_9036;
v_9037:
    v_9049 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9038;
v_9039:
    goto v_9035;
v_9036:
    goto v_9037;
v_9038:
    v_9049 = cons(v_9050, v_9049);
    return ncons(v_9049);
    v_9049 = nil;
v_9019:
    return onevalue(v_9049);
}



// Code for collect_cars

static LispObject CC_collect_cars(LispObject env,
                         LispObject v_9010)
{
    env = qenv(env);
    LispObject v_9037, v_9038;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9010);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_9010;
// end of prologue
    v_9038 = nil;
v_9015:
    v_9037 = stack[0];
    if (v_9037 == nil) goto v_9018;
    else goto v_9019;
v_9018:
    v_9037 = v_9038;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_9037);
    }
v_9019:
    goto v_9030;
v_9026:
    v_9037 = stack[0];
    v_9037 = qcar(v_9037);
    v_9037 = qcar(v_9037);
    goto v_9027;
v_9028:
    goto v_9029;
v_9030:
    goto v_9026;
v_9027:
    goto v_9028;
v_9029:
    v_9037 = cons(v_9037, v_9038);
    env = stack[-1];
    v_9038 = v_9037;
    v_9037 = stack[0];
    v_9037 = qcdr(v_9037);
    stack[0] = v_9037;
    goto v_9015;
    v_9037 = nil;
    return onevalue(v_9037);
}



// Code for findremainder

static LispObject CC_findremainder(LispObject env,
                         LispObject v_9010, LispObject v_9011)
{
    env = qenv(env);
    LispObject v_9045, v_9046, v_9047;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9011,v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9010,v_9011);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_9045 = v_9011;
    v_9046 = v_9010;
// end of prologue
    stack[0] = v_9045;
v_9016:
    v_9045 = stack[0];
    if (v_9045 == nil) goto v_9020;
    else goto v_9021;
v_9020:
    goto v_9015;
v_9021:
    v_9045 = stack[0];
    v_9045 = qcar(v_9045);
    goto v_9034;
v_9028:
    v_9047 = v_9046;
    goto v_9029;
v_9030:
    v_9046 = v_9045;
    goto v_9031;
v_9032:
    v_9045 = qcar(v_9045);
    v_9045 = qcar(v_9045);
    v_9045 = qcar(v_9045);
    goto v_9033;
v_9034:
    goto v_9028;
v_9029:
    goto v_9030;
v_9031:
    goto v_9032;
v_9033:
    fn = elt(env, 1); // wupseudodivide
    v_9045 = (*qfnn(fn))(fn, 3, v_9047, v_9046, v_9045);
    env = stack[-1];
    v_9045 = qcdr(v_9045);
    v_9046 = v_9045;
    v_9045 = stack[0];
    v_9045 = qcdr(v_9045);
    stack[0] = v_9045;
    goto v_9016;
v_9015:
    v_9045 = v_9046;
    return onevalue(v_9045);
}



// Code for expnd1

static LispObject CC_expnd1(LispObject env,
                         LispObject v_9010)
{
    env = qenv(env);
    LispObject v_9136, v_9137;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9010);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_9010;
// end of prologue
    stack[-2] = nil;
v_9016:
    v_9136 = stack[-1];
    if (!consp(v_9136)) goto v_9025;
    else goto v_9026;
v_9025:
    v_9136 = lisp_true;
    goto v_9024;
v_9026:
    v_9136 = stack[-1];
    v_9136 = qcar(v_9136);
    v_9136 = (consp(v_9136) ? nil : lisp_true);
    goto v_9024;
    v_9136 = nil;
v_9024:
    if (v_9136 == nil) goto v_9022;
    goto v_9017;
v_9022:
    goto v_9039;
v_9035:
    v_9136 = stack[-1];
    v_9136 = qcar(v_9136);
    v_9136 = qcar(v_9136);
    v_9136 = qcar(v_9136);
    fn = elt(env, 1); // sfp
    v_9136 = (*qfn1(fn))(fn, v_9136);
    env = stack[-3];
    if (v_9136 == nil) goto v_9046;
    else goto v_9047;
v_9046:
    v_9136 = lisp_true;
    goto v_9045;
v_9047:
    goto v_9061;
v_9057:
    v_9136 = stack[-1];
    v_9136 = qcar(v_9136);
    v_9136 = qcar(v_9136);
    v_9137 = qcdr(v_9136);
    goto v_9058;
v_9059:
    v_9136 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9060;
v_9061:
    goto v_9057;
v_9058:
    goto v_9059;
v_9060:
    v_9136 = (LispObject)lessp2(v_9137, v_9136);
    v_9136 = v_9136 ? lisp_true : nil;
    env = stack[-3];
    goto v_9045;
    v_9136 = nil;
v_9045:
    if (v_9136 == nil) goto v_9043;
    goto v_9072;
v_9068:
    goto v_9079;
v_9075:
    v_9136 = stack[-1];
    v_9136 = qcar(v_9136);
    v_9137 = qcar(v_9136);
    goto v_9076;
v_9077:
    v_9136 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9078;
v_9079:
    goto v_9075;
v_9076:
    goto v_9077;
v_9078:
    v_9136 = cons(v_9137, v_9136);
    env = stack[-3];
    stack[0] = ncons(v_9136);
    env = stack[-3];
    goto v_9069;
v_9070:
    v_9136 = stack[-1];
    v_9136 = qcar(v_9136);
    v_9136 = qcdr(v_9136);
    v_9136 = CC_expnd1(elt(env, 0), v_9136);
    env = stack[-3];
    goto v_9071;
v_9072:
    goto v_9068;
v_9069:
    goto v_9070;
v_9071:
    fn = elt(env, 2); // multf
    v_9136 = (*qfn2(fn))(fn, stack[0], v_9136);
    env = stack[-3];
    v_9137 = v_9136;
    goto v_9041;
v_9043:
    goto v_9095;
v_9091:
    goto v_9101;
v_9097:
    v_9136 = stack[-1];
    v_9136 = qcar(v_9136);
    v_9136 = qcar(v_9136);
    v_9136 = qcar(v_9136);
    v_9137 = CC_expnd1(elt(env, 0), v_9136);
    env = stack[-3];
    goto v_9098;
v_9099:
    v_9136 = stack[-1];
    v_9136 = qcar(v_9136);
    v_9136 = qcar(v_9136);
    v_9136 = qcdr(v_9136);
    goto v_9100;
v_9101:
    goto v_9097;
v_9098:
    goto v_9099;
v_9100:
    fn = elt(env, 3); // exptf
    stack[0] = (*qfn2(fn))(fn, v_9137, v_9136);
    env = stack[-3];
    goto v_9092;
v_9093:
    v_9136 = stack[-1];
    v_9136 = qcar(v_9136);
    v_9136 = qcdr(v_9136);
    v_9136 = CC_expnd1(elt(env, 0), v_9136);
    env = stack[-3];
    goto v_9094;
v_9095:
    goto v_9091;
v_9092:
    goto v_9093;
v_9094:
    fn = elt(env, 2); // multf
    v_9136 = (*qfn2(fn))(fn, stack[0], v_9136);
    env = stack[-3];
    v_9137 = v_9136;
    goto v_9041;
    v_9137 = nil;
v_9041:
    goto v_9036;
v_9037:
    v_9136 = stack[-2];
    goto v_9038;
v_9039:
    goto v_9035;
v_9036:
    goto v_9037;
v_9038:
    v_9136 = cons(v_9137, v_9136);
    env = stack[-3];
    stack[-2] = v_9136;
    v_9136 = stack[-1];
    v_9136 = qcdr(v_9136);
    stack[-1] = v_9136;
    goto v_9016;
v_9017:
    v_9136 = stack[-1];
    v_9137 = v_9136;
v_9018:
    v_9136 = stack[-2];
    if (v_9136 == nil) goto v_9121;
    else goto v_9122;
v_9121:
    v_9136 = v_9137;
    goto v_9015;
v_9122:
    goto v_9130;
v_9126:
    v_9136 = stack[-2];
    v_9136 = qcar(v_9136);
    goto v_9127;
v_9128:
    goto v_9129;
v_9130:
    goto v_9126;
v_9127:
    goto v_9128;
v_9129:
    fn = elt(env, 4); // addf
    v_9136 = (*qfn2(fn))(fn, v_9136, v_9137);
    env = stack[-3];
    v_9137 = v_9136;
    v_9136 = stack[-2];
    v_9136 = qcdr(v_9136);
    stack[-2] = v_9136;
    goto v_9018;
v_9015:
    return onevalue(v_9136);
}



// Code for cl_smsimpl!-junct2

static LispObject CC_cl_smsimplKjunct2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_9127, v_9128, v_9129, v_9130;
    LispObject fn;
    LispObject v_9015, v_9014, v_9013, v_9012, v_9011, v_9010;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "cl_smsimpl-junct2");
    va_start(aa, nargs);
    v_9010 = va_arg(aa, LispObject);
    v_9011 = va_arg(aa, LispObject);
    v_9012 = va_arg(aa, LispObject);
    v_9013 = va_arg(aa, LispObject);
    v_9014 = va_arg(aa, LispObject);
    v_9015 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_9015,v_9014,v_9013,v_9012,v_9011,v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_9010,v_9011,v_9012,v_9013,v_9014,v_9015);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_9015;
    v_9127 = v_9014;
    v_9128 = v_9013;
    v_9129 = v_9012;
    stack[-2] = v_9011;
    v_9130 = v_9010;
// end of prologue
    goto v_9031;
v_9023:
    goto v_9024;
v_9025:
    goto v_9026;
v_9027:
    goto v_9028;
v_9029:
    goto v_9030;
v_9031:
    goto v_9023;
v_9024:
    goto v_9025;
v_9026:
    goto v_9027;
v_9028:
    goto v_9029;
v_9030:
    fn = elt(env, 7); // rl_smmkatl
    v_9127 = (*qfnn(fn))(fn, 4, v_9130, v_9129, v_9128, v_9127);
    env = stack[-4];
    stack[-3] = v_9127;
    goto v_9044;
v_9040:
    v_9128 = stack[-3];
    goto v_9041;
v_9042:
    v_9127 = stack[-1];
    goto v_9043;
v_9044:
    goto v_9040;
v_9041:
    goto v_9042;
v_9043:
    if (v_9128 == v_9127) goto v_9038;
    else goto v_9039;
v_9038:
    v_9127 = stack[-1];
    return ncons(v_9127);
v_9039:
    v_9127 = qvalue(elt(env, 2)); // !*rlsichk
    if (v_9127 == nil) goto v_9052;
    v_9127 = stack[-2];
    v_9128 = v_9127;
    v_9127 = nil;
    stack[-2] = v_9127;
    v_9127 = v_9128;
    stack[0] = v_9127;
v_9059:
    v_9127 = stack[0];
    if (v_9127 == nil) goto v_9063;
    else goto v_9064;
v_9063:
    goto v_9058;
v_9064:
    v_9127 = stack[0];
    v_9127 = qcar(v_9127);
    goto v_9075;
v_9071:
    v_9128 = v_9127;
    goto v_9072;
v_9073:
    v_9127 = stack[-2];
    goto v_9074;
v_9075:
    goto v_9071;
v_9072:
    goto v_9073;
v_9074:
    fn = elt(env, 8); // lto_insert
    v_9127 = (*qfn2(fn))(fn, v_9128, v_9127);
    env = stack[-4];
    stack[-2] = v_9127;
    v_9127 = stack[0];
    v_9127 = qcdr(v_9127);
    stack[0] = v_9127;
    goto v_9059;
v_9058:
    goto v_9050;
v_9052:
    v_9127 = stack[-2];
    v_9127 = Lnreverse(nil, v_9127);
    env = stack[-4];
    stack[-2] = v_9127;
    goto v_9050;
v_9050:
    v_9127 = qvalue(elt(env, 3)); // !*rlsiso
    if (v_9127 == nil) goto v_9087;
    goto v_9094;
v_9090:
    v_9128 = stack[-3];
    goto v_9091;
v_9092:
    v_9127 = elt(env, 4); // rl_ordatp
    goto v_9093;
v_9094:
    goto v_9090;
v_9091:
    goto v_9092;
v_9093:
    fn = elt(env, 9); // sort
    v_9127 = (*qfn2(fn))(fn, v_9128, v_9127);
    env = stack[-4];
    stack[-3] = v_9127;
    v_9127 = qvalue(elt(env, 5)); // !*rlsisocx
    if (v_9127 == nil) goto v_9100;
    goto v_9107;
v_9103:
    v_9128 = stack[-2];
    goto v_9104;
v_9105:
    v_9127 = elt(env, 6); // cl_sordp
    goto v_9106;
v_9107:
    goto v_9103;
v_9104:
    goto v_9105;
v_9106:
    fn = elt(env, 9); // sort
    v_9127 = (*qfn2(fn))(fn, v_9128, v_9127);
    env = stack[-4];
    stack[-2] = v_9127;
    goto v_9098;
v_9100:
v_9098:
    goto v_9085;
v_9087:
v_9085:
    goto v_9115;
v_9111:
    v_9128 = stack[-3];
    goto v_9112;
v_9113:
    v_9127 = stack[-2];
    goto v_9114;
v_9115:
    goto v_9111;
v_9112:
    goto v_9113;
v_9114:
    v_9127 = Lnconc(nil, v_9128, v_9127);
    env = stack[-4];
    v_9128 = v_9127;
    v_9127 = v_9128;
    if (v_9127 == nil) goto v_9121;
    v_9127 = v_9128;
    goto v_9020;
v_9121:
    v_9127 = stack[-1];
    fn = elt(env, 10); // cl_flip
    v_9127 = (*qfn1(fn))(fn, v_9127);
    return ncons(v_9127);
v_9020:
    return onevalue(v_9127);
}



// Code for ibalp_lenisone

static LispObject CC_ibalp_lenisone(LispObject env,
                         LispObject v_9010)
{
    env = qenv(env);
    LispObject v_9023, v_9024;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9023 = v_9010;
// end of prologue
    v_9024 = v_9023;
    if (v_9024 == nil) goto v_9014;
    else goto v_9015;
v_9014:
    v_9023 = nil;
    goto v_9013;
v_9015:
    v_9023 = qcdr(v_9023);
    v_9023 = (v_9023 == nil ? lisp_true : nil);
    goto v_9013;
    v_9023 = nil;
v_9013:
    return onevalue(v_9023);
}



// Code for attributesml

static LispObject CC_attributesml(LispObject env,
                         LispObject v_9010, LispObject v_9011)
{
    env = qenv(env);
    LispObject v_9091, v_9092;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9011,v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9010,v_9011);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_9011;
    stack[-1] = v_9010;
// end of prologue
    v_9091 = stack[-1];
    if (v_9091 == nil) goto v_9018;
    else goto v_9019;
v_9018:
    v_9091 = stack[0];
    v_9091 = Lprinc(nil, v_9091);
    env = stack[-2];
    v_9091 = elt(env, 1); // ">"
    v_9091 = Lprinc(nil, v_9091);
    goto v_9017;
v_9019:
    v_9091 = elt(env, 2); // " "
    v_9091 = Lprinc(nil, v_9091);
    env = stack[-2];
    v_9091 = stack[-1];
    v_9091 = qcar(v_9091);
    v_9091 = qcar(v_9091);
    v_9091 = Lprinc(nil, v_9091);
    env = stack[-2];
    v_9091 = elt(env, 3); // "="""
    v_9091 = Lprinc(nil, v_9091);
    env = stack[-2];
    goto v_9043;
v_9039:
    v_9091 = stack[-1];
    v_9091 = qcar(v_9091);
    v_9092 = qcar(v_9091);
    goto v_9040;
v_9041:
    v_9091 = elt(env, 4); // definitionurl
    goto v_9042;
v_9043:
    goto v_9039;
v_9040:
    goto v_9041;
v_9042:
    if (v_9092 == v_9091) goto v_9038;
    goto v_9056;
v_9052:
    v_9091 = stack[-1];
    v_9091 = qcar(v_9091);
    v_9091 = qcdr(v_9091);
    v_9092 = qcar(v_9091);
    goto v_9053;
v_9054:
    v_9091 = elt(env, 5); // vectorml
    goto v_9055;
v_9056:
    goto v_9052;
v_9053:
    goto v_9054;
v_9055:
    if (v_9092 == v_9091) goto v_9050;
    else goto v_9051;
v_9050:
    v_9091 = elt(env, 6); // "vector"
    v_9091 = Lprinc(nil, v_9091);
    env = stack[-2];
    goto v_9049;
v_9051:
    v_9091 = stack[-1];
    v_9091 = qcar(v_9091);
    v_9091 = qcdr(v_9091);
    v_9091 = qcar(v_9091);
    v_9091 = Lprinc(nil, v_9091);
    env = stack[-2];
    goto v_9049;
v_9049:
    goto v_9036;
v_9038:
    v_9091 = stack[-1];
    v_9091 = qcar(v_9091);
    v_9091 = qcdr(v_9091);
    v_9091 = qcar(v_9091);
    fn = elt(env, 8); // mathml_list2string
    v_9091 = (*qfn1(fn))(fn, v_9091);
    env = stack[-2];
    goto v_9036;
v_9036:
    v_9091 = elt(env, 7); // """"
    v_9091 = Lprinc(nil, v_9091);
    env = stack[-2];
    goto v_9086;
v_9082:
    v_9091 = stack[-1];
    v_9092 = qcdr(v_9091);
    goto v_9083;
v_9084:
    v_9091 = stack[0];
    goto v_9085;
v_9086:
    goto v_9082;
v_9083:
    goto v_9084;
v_9085:
    v_9091 = CC_attributesml(elt(env, 0), v_9092, v_9091);
    goto v_9017;
v_9017:
    v_9091 = nil;
    return onevalue(v_9091);
}



// Code for spband_matrix

static LispObject CC_spband_matrix(LispObject env,
                         LispObject v_9010, LispObject v_9011)
{
    env = qenv(env);
    LispObject v_9289, v_9290, v_9291;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9011,v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9010,v_9011);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-7] = v_9011;
    stack[-8] = v_9010;
// end of prologue
    goto v_9032;
v_9028:
    stack[0] = stack[-7];
    goto v_9029;
v_9030:
    goto v_9041;
v_9035:
    v_9291 = elt(env, 2); // spm
    goto v_9036;
v_9037:
    v_9290 = stack[-7];
    goto v_9038;
v_9039:
    v_9289 = stack[-7];
    goto v_9040;
v_9041:
    goto v_9035;
v_9036:
    goto v_9037;
v_9038:
    goto v_9039;
v_9040:
    v_9289 = list3(v_9291, v_9290, v_9289);
    env = stack[-10];
    goto v_9031;
v_9032:
    goto v_9028;
v_9029:
    goto v_9030;
v_9031:
    fn = elt(env, 9); // mkempspmat
    v_9289 = (*qfn2(fn))(fn, stack[0], v_9289);
    env = stack[-10];
    stack[-9] = v_9289;
    v_9289 = stack[-7];
    v_9289 = integerp(v_9289);
    if (v_9289 == nil) goto v_9047;
    else goto v_9048;
v_9047:
    v_9289 = elt(env, 3); // "Error in spband_matrix(second argument): should be an integer."
    fn = elt(env, 10); // rederr
    v_9289 = (*qfn1(fn))(fn, v_9289);
    env = stack[-10];
    goto v_9046;
v_9048:
v_9046:
    v_9289 = stack[-8];
    if (!consp(v_9289)) goto v_9055;
    else goto v_9056;
v_9055:
    v_9289 = stack[-8];
    v_9289 = ncons(v_9289);
    env = stack[-10];
    stack[-8] = v_9289;
    goto v_9054;
v_9056:
    goto v_9066;
v_9062:
    v_9289 = stack[-8];
    v_9290 = qcar(v_9289);
    goto v_9063;
v_9064:
    v_9289 = elt(env, 4); // list
    goto v_9065;
v_9066:
    goto v_9062;
v_9063:
    goto v_9064;
v_9065:
    if (v_9290 == v_9289) goto v_9060;
    else goto v_9061;
v_9060:
    v_9289 = stack[-8];
    v_9289 = qcdr(v_9289);
    stack[-8] = v_9289;
    goto v_9054;
v_9061:
    v_9289 = elt(env, 5); // "Error in spband_matrix(first argument): should be single value or list."
    fn = elt(env, 10); // rederr
    v_9289 = (*qfn1(fn))(fn, v_9289);
    env = stack[-10];
    goto v_9054;
v_9054:
    v_9289 = stack[-8];
    v_9289 = Llength(nil, v_9289);
    env = stack[-10];
    stack[-4] = v_9289;
    v_9289 = stack[-4];
    v_9289 = Levenp(nil, v_9289);
    env = stack[-10];
    if (v_9289 == nil) goto v_9081;
    v_9289 = elt(env, 6); // "Error in spband matrix(first argument): number of elements must be odd."
    fn = elt(env, 10); // rederr
    v_9289 = (*qfn1(fn))(fn, v_9289);
    env = stack[-10];
    goto v_9079;
v_9081:
v_9079:
    goto v_9094;
v_9088:
    stack[0] = elt(env, 7); // quotient
    goto v_9089;
v_9090:
    v_9289 = stack[-4];
    v_9290 = add1(v_9289);
    env = stack[-10];
    goto v_9091;
v_9092:
    v_9289 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_9093;
v_9094:
    goto v_9088;
v_9089:
    goto v_9090;
v_9091:
    goto v_9092;
v_9093:
    v_9289 = list3(stack[0], v_9290, v_9289);
    env = stack[-10];
    fn = elt(env, 11); // reval
    v_9289 = (*qfn1(fn))(fn, v_9289);
    env = stack[-10];
    stack[-3] = v_9289;
    goto v_9108;
v_9104:
    v_9289 = stack[-3];
    v_9289 = integerp(v_9289);
    if (v_9289 == nil) goto v_9112;
    v_9289 = stack[-3];
    v_9290 = v_9289;
    goto v_9110;
v_9112:
    v_9289 = stack[-3];
    fn = elt(env, 11); // reval
    v_9289 = (*qfn1(fn))(fn, v_9289);
    env = stack[-10];
    v_9290 = v_9289;
    goto v_9110;
    v_9290 = nil;
v_9110:
    goto v_9105;
v_9106:
    v_9289 = stack[-7];
    goto v_9107;
v_9108:
    goto v_9104;
v_9105:
    goto v_9106;
v_9107:
    v_9289 = (LispObject)greaterp2(v_9290, v_9289);
    v_9289 = v_9289 ? lisp_true : nil;
    env = stack[-10];
    if (v_9289 == nil) goto v_9102;
    v_9289 = elt(env, 8); // "Error in spband_matrix: too many elements. Band matrix is overflowing."
    fn = elt(env, 10); // rederr
    v_9289 = (*qfn1(fn))(fn, v_9289);
    env = stack[-10];
    goto v_9100;
v_9102:
v_9100:
    v_9289 = (LispObject)32+TAG_FIXNUM; // 2
    stack[-5] = v_9289;
    v_9289 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_9289;
v_9127:
    goto v_9139;
v_9135:
    v_9290 = stack[-7];
    goto v_9136;
v_9137:
    v_9289 = stack[-2];
    goto v_9138;
v_9139:
    goto v_9135;
v_9136:
    goto v_9137;
v_9138:
    v_9289 = difference2(v_9290, v_9289);
    env = stack[-10];
    v_9289 = Lminusp(nil, v_9289);
    env = stack[-10];
    if (v_9289 == nil) goto v_9132;
    goto v_9126;
v_9132:
    goto v_9152;
v_9148:
    v_9290 = stack[-2];
    goto v_9149;
v_9150:
    v_9289 = stack[-3];
    goto v_9151;
v_9152:
    goto v_9148;
v_9149:
    goto v_9150;
v_9151:
    v_9289 = (LispObject)lesseq2(v_9290, v_9289);
    v_9289 = v_9289 ? lisp_true : nil;
    env = stack[-10];
    if (v_9289 == nil) goto v_9146;
    v_9289 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_9289;
    goto v_9144;
v_9146:
    v_9289 = stack[-5];
    stack[-6] = v_9289;
    goto v_9144;
v_9144:
v_9161:
    goto v_9172;
v_9168:
    goto v_9178;
v_9174:
    goto v_9184;
v_9180:
    v_9290 = stack[-3];
    goto v_9181;
v_9182:
    v_9289 = stack[-2];
    goto v_9183;
v_9184:
    goto v_9180;
v_9181:
    goto v_9182;
v_9183:
    v_9290 = difference2(v_9290, v_9289);
    env = stack[-10];
    goto v_9175;
v_9176:
    v_9289 = stack[-6];
    goto v_9177;
v_9178:
    goto v_9174;
v_9175:
    goto v_9176;
v_9177:
    v_9290 = plus2(v_9290, v_9289);
    env = stack[-10];
    goto v_9169;
v_9170:
    v_9289 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9171;
v_9172:
    goto v_9168;
v_9169:
    goto v_9170;
v_9171:
    v_9289 = (LispObject)greaterp2(v_9290, v_9289);
    v_9289 = v_9289 ? lisp_true : nil;
    env = stack[-10];
    if (v_9289 == nil) goto v_9164;
    goto v_9196;
v_9192:
    v_9290 = stack[-6];
    goto v_9193;
v_9194:
    v_9289 = stack[-7];
    goto v_9195;
v_9196:
    goto v_9192;
v_9193:
    goto v_9194;
v_9195:
    v_9289 = (LispObject)lesseq2(v_9290, v_9289);
    v_9289 = v_9289 ? lisp_true : nil;
    env = stack[-10];
    if (v_9289 == nil) goto v_9164;
    goto v_9205;
v_9201:
    goto v_9211;
v_9207:
    goto v_9217;
v_9213:
    v_9290 = stack[-3];
    goto v_9214;
v_9215:
    v_9289 = stack[-2];
    goto v_9216;
v_9217:
    goto v_9213;
v_9214:
    goto v_9215;
v_9216:
    v_9290 = difference2(v_9290, v_9289);
    env = stack[-10];
    goto v_9208;
v_9209:
    v_9289 = stack[-6];
    goto v_9210;
v_9211:
    goto v_9207;
v_9208:
    goto v_9209;
v_9210:
    v_9290 = plus2(v_9290, v_9289);
    env = stack[-10];
    goto v_9202;
v_9203:
    v_9289 = stack[-4];
    goto v_9204;
v_9205:
    goto v_9201;
v_9202:
    goto v_9203;
v_9204:
    v_9289 = (LispObject)lesseq2(v_9290, v_9289);
    v_9289 = v_9289 ? lisp_true : nil;
    env = stack[-10];
    if (v_9289 == nil) goto v_9164;
    goto v_9165;
v_9164:
    goto v_9160;
v_9165:
    goto v_9232;
v_9224:
    goto v_9240;
v_9234:
    v_9291 = stack[-9];
    goto v_9235;
v_9236:
    v_9290 = stack[-2];
    goto v_9237;
v_9238:
    v_9289 = stack[-6];
    goto v_9239;
v_9240:
    goto v_9234;
v_9235:
    goto v_9236;
v_9237:
    goto v_9238;
v_9239:
    stack[-1] = list3(v_9291, v_9290, v_9289);
    env = stack[-10];
    goto v_9225;
v_9226:
    goto v_9249;
v_9245:
    stack[0] = stack[-8];
    goto v_9246;
v_9247:
    goto v_9256;
v_9252:
    goto v_9262;
v_9258:
    v_9290 = stack[-3];
    goto v_9259;
v_9260:
    v_9289 = stack[-2];
    goto v_9261;
v_9262:
    goto v_9258;
v_9259:
    goto v_9260;
v_9261:
    v_9290 = difference2(v_9290, v_9289);
    env = stack[-10];
    goto v_9253;
v_9254:
    v_9289 = stack[-6];
    goto v_9255;
v_9256:
    goto v_9252;
v_9253:
    goto v_9254;
v_9255:
    v_9289 = plus2(v_9290, v_9289);
    env = stack[-10];
    goto v_9248;
v_9249:
    goto v_9245;
v_9246:
    goto v_9247;
v_9248:
    fn = elt(env, 12); // nth
    v_9291 = (*qfn2(fn))(fn, stack[0], v_9289);
    env = stack[-10];
    goto v_9227;
v_9228:
    v_9290 = stack[-9];
    goto v_9229;
v_9230:
    v_9289 = nil;
    goto v_9231;
v_9232:
    goto v_9224;
v_9225:
    goto v_9226;
v_9227:
    goto v_9228;
v_9229:
    goto v_9230;
v_9231:
    fn = elt(env, 13); // letmtr3
    v_9289 = (*qfnn(fn))(fn, 4, stack[-1], v_9291, v_9290, v_9289);
    env = stack[-10];
    v_9289 = stack[-6];
    v_9289 = add1(v_9289);
    env = stack[-10];
    stack[-6] = v_9289;
    goto v_9161;
v_9160:
    goto v_9280;
v_9276:
    v_9290 = stack[-2];
    goto v_9277;
v_9278:
    v_9289 = stack[-3];
    goto v_9279;
v_9280:
    goto v_9276;
v_9277:
    goto v_9278;
v_9279:
    v_9289 = (LispObject)greaterp2(v_9290, v_9289);
    v_9289 = v_9289 ? lisp_true : nil;
    env = stack[-10];
    if (v_9289 == nil) goto v_9274;
    v_9289 = stack[-5];
    v_9289 = add1(v_9289);
    env = stack[-10];
    stack[-5] = v_9289;
    goto v_9272;
v_9274:
v_9272:
    v_9289 = stack[-2];
    v_9289 = add1(v_9289);
    env = stack[-10];
    stack[-2] = v_9289;
    goto v_9127;
v_9126:
    v_9289 = stack[-9];
    return onevalue(v_9289);
}



// Code for dm!-eq

static LispObject CC_dmKeq(LispObject env,
                         LispObject v_9010, LispObject v_9011)
{
    env = qenv(env);
    LispObject v_9022, v_9023;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9011,v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9010,v_9011);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_9022 = v_9011;
    v_9023 = v_9010;
// end of prologue
    goto v_9019;
v_9015:
    goto v_9016;
v_9017:
    goto v_9018;
v_9019:
    goto v_9015;
v_9016:
    goto v_9017;
v_9018:
    fn = elt(env, 1); // dm!-difference
    v_9022 = (*qfn2(fn))(fn, v_9023, v_9022);
    env = stack[0];
    {
        fn = elt(env, 2); // !:zerop
        return (*qfn1(fn))(fn, v_9022);
    }
}



// Code for findnewvars

static LispObject CC_findnewvars(LispObject env,
                         LispObject v_9010)
{
    env = qenv(env);
    LispObject v_9080;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9010);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_9010;
// end of prologue
    v_9080 = stack[0];
    if (!consp(v_9080)) goto v_9014;
    else goto v_9015;
v_9014:
    v_9080 = stack[0];
    fn = elt(env, 1); // genp
    v_9080 = (*qfn1(fn))(fn, v_9080);
    if (v_9080 == nil) goto v_9020;
    v_9080 = stack[0];
    return ncons(v_9080);
v_9020:
    v_9080 = nil;
    goto v_9018;
    v_9080 = nil;
v_9018:
    goto v_9013;
v_9015:
    v_9080 = stack[0];
    stack[-3] = v_9080;
v_9035:
    v_9080 = stack[-3];
    if (v_9080 == nil) goto v_9040;
    else goto v_9041;
v_9040:
    v_9080 = nil;
    goto v_9034;
v_9041:
    v_9080 = stack[-3];
    v_9080 = qcar(v_9080);
    v_9080 = CC_findnewvars(elt(env, 0), v_9080);
    env = stack[-4];
    stack[-2] = v_9080;
    v_9080 = stack[-2];
    fn = elt(env, 2); // lastpair
    v_9080 = (*qfn1(fn))(fn, v_9080);
    env = stack[-4];
    stack[-1] = v_9080;
    v_9080 = stack[-3];
    v_9080 = qcdr(v_9080);
    stack[-3] = v_9080;
    v_9080 = stack[-1];
    if (!consp(v_9080)) goto v_9055;
    else goto v_9056;
v_9055:
    goto v_9035;
v_9056:
v_9036:
    v_9080 = stack[-3];
    if (v_9080 == nil) goto v_9060;
    else goto v_9061;
v_9060:
    v_9080 = stack[-2];
    goto v_9034;
v_9061:
    goto v_9069;
v_9065:
    stack[0] = stack[-1];
    goto v_9066;
v_9067:
    v_9080 = stack[-3];
    v_9080 = qcar(v_9080);
    v_9080 = CC_findnewvars(elt(env, 0), v_9080);
    env = stack[-4];
    goto v_9068;
v_9069:
    goto v_9065;
v_9066:
    goto v_9067;
v_9068:
    v_9080 = Lrplacd(nil, stack[0], v_9080);
    env = stack[-4];
    v_9080 = stack[-1];
    fn = elt(env, 2); // lastpair
    v_9080 = (*qfn1(fn))(fn, v_9080);
    env = stack[-4];
    stack[-1] = v_9080;
    v_9080 = stack[-3];
    v_9080 = qcdr(v_9080);
    stack[-3] = v_9080;
    goto v_9036;
v_9034:
    goto v_9013;
    v_9080 = nil;
v_9013:
    return onevalue(v_9080);
}



// Code for onoff

static LispObject CC_onoff(LispObject env,
                         LispObject v_9010, LispObject v_9011)
{
    env = qenv(env);
    LispObject v_9138, v_9139, v_9140;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9011,v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9010,v_9011);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_9011;
    stack[0] = v_9010;
// end of prologue
    v_9138 = stack[0];
    if (symbolp(v_9138)) goto v_9021;
    goto v_9028;
v_9024:
    v_9139 = stack[0];
    goto v_9025;
v_9026:
    v_9138 = elt(env, 2); // "switch"
    goto v_9027;
v_9028:
    goto v_9024;
v_9025:
    goto v_9026;
v_9027:
    fn = elt(env, 10); // typerr
    v_9138 = (*qfn2(fn))(fn, v_9139, v_9138);
    env = stack[-4];
    goto v_9019;
v_9021:
    v_9138 = stack[0];
    if (!symbolp(v_9138)) v_9138 = nil;
    else { v_9138 = qfastgets(v_9138);
           if (v_9138 != nil) { v_9138 = elt(v_9138, 51); // switch
#ifdef RECORD_GET
             if (v_9138 == SPID_NOPROP)
                record_get(elt(fastget_names, 51), 0),
                v_9138 = nil;
             else record_get(elt(fastget_names, 51), 1),
                v_9138 = lisp_true; }
           else record_get(elt(fastget_names, 51), 0); }
#else
             if (v_9138 == SPID_NOPROP) v_9138 = nil; else v_9138 = lisp_true; }}
#endif
    if (v_9138 == nil) goto v_9031;
    else goto v_9032;
v_9031:
    goto v_9042;
v_9036:
    stack[-3] = elt(env, 3); // rlisp
    goto v_9037;
v_9038:
    stack[-1] = (LispObject)400+TAG_FIXNUM; // 25
    goto v_9039;
v_9040:
    goto v_9050;
v_9046:
    v_9139 = stack[0];
    goto v_9047;
v_9048:
    v_9138 = elt(env, 4); // "not defined as switch"
    goto v_9049;
v_9050:
    goto v_9046;
v_9047:
    goto v_9048;
v_9049:
    v_9138 = list2(v_9139, v_9138);
    env = stack[-4];
    goto v_9041;
v_9042:
    goto v_9036;
v_9037:
    goto v_9038;
v_9039:
    goto v_9040;
v_9041:
    fn = elt(env, 11); // rerror
    v_9138 = (*qfnn(fn))(fn, 3, stack[-3], stack[-1], v_9138);
    env = stack[-4];
    goto v_9019;
v_9032:
v_9019:
    goto v_9060;
v_9056:
    stack[-1] = elt(env, 5); // !*
    goto v_9057;
v_9058:
    v_9138 = stack[0];
    v_9138 = Lexplodec(nil, v_9138);
    env = stack[-4];
    goto v_9059;
v_9060:
    goto v_9056;
v_9057:
    goto v_9058;
v_9059:
    v_9138 = cons(stack[-1], v_9138);
    env = stack[-4];
    fn = elt(env, 12); // list2string
    v_9138 = (*qfn1(fn))(fn, v_9138);
    env = stack[-4];
    v_9138 = Lintern(nil, v_9138);
    env = stack[-4];
    stack[-3] = v_9138;
    v_9138 = qvalue(elt(env, 6)); // !*switchcheck
    if (v_9138 == nil) goto v_9067;
    goto v_9075;
v_9071:
    v_9138 = stack[-3];
    fn = elt(env, 13); // lispeval
    v_9139 = (*qfn1(fn))(fn, v_9138);
    env = stack[-4];
    goto v_9072;
v_9073:
    v_9138 = stack[-2];
    goto v_9074;
v_9075:
    goto v_9071;
v_9072:
    goto v_9073;
v_9074:
    if (v_9139 == v_9138) goto v_9070;
    else goto v_9067;
v_9070:
    v_9138 = nil;
    goto v_9016;
v_9067:
    goto v_9086;
v_9082:
    v_9140 = stack[-2];
    goto v_9083;
v_9084:
    goto v_9093;
v_9089:
    v_9139 = stack[0];
    goto v_9090;
v_9091:
    v_9138 = elt(env, 7); // simpfg
    goto v_9092;
v_9093:
    goto v_9089;
v_9090:
    goto v_9091;
v_9092:
    v_9138 = get(v_9139, v_9138);
    env = stack[-4];
    goto v_9085;
v_9086:
    goto v_9082;
v_9083:
    goto v_9084;
v_9085:
    v_9138 = Latsoc(nil, v_9140, v_9138);
    v_9139 = v_9138;
    if (v_9138 == nil) goto v_9081;
    goto v_9103;
v_9099:
    stack[-1] = elt(env, 8); // progn
    goto v_9100;
v_9101:
    goto v_9110;
v_9106:
    v_9138 = v_9139;
    stack[0] = qcdr(v_9138);
    goto v_9107;
v_9108:
    v_9138 = nil;
    v_9138 = ncons(v_9138);
    env = stack[-4];
    goto v_9109;
v_9110:
    goto v_9106;
v_9107:
    goto v_9108;
v_9109:
    v_9138 = Lappend(nil, stack[0], v_9138);
    env = stack[-4];
    goto v_9102;
v_9103:
    goto v_9099;
v_9100:
    goto v_9101;
v_9102:
    v_9138 = cons(stack[-1], v_9138);
    env = stack[-4];
    fn = elt(env, 13); // lispeval
    v_9138 = (*qfn1(fn))(fn, v_9138);
    env = stack[-4];
    goto v_9065;
v_9081:
v_9065:
    v_9138 = stack[-2];
    if (v_9138 == nil) goto v_9118;
    goto v_9126;
v_9122:
    v_9139 = stack[-3];
    goto v_9123;
v_9124:
    v_9138 = elt(env, 9); // !*raise
    goto v_9125;
v_9126:
    goto v_9122;
v_9123:
    goto v_9124;
v_9125:
    if (v_9139 == v_9138) goto v_9121;
    else goto v_9118;
v_9121:
    v_9138 = elt(env, 9); // !*raise
    stack[-3] = v_9138;
    goto v_9116;
v_9118:
v_9116:
    goto v_9135;
v_9131:
    v_9139 = stack[-3];
    goto v_9132;
v_9133:
    v_9138 = stack[-2];
    goto v_9134;
v_9135:
    goto v_9131;
v_9132:
    goto v_9133;
v_9134:
    v_9138 = Lset(nil, v_9139, v_9138);
    v_9138 = nil;
v_9016:
    return onevalue(v_9138);
}



// Code for bcplus!?

static LispObject CC_bcplusW(LispObject env,
                         LispObject v_9010)
{
    env = qenv(env);
    LispObject v_9031, v_9032;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9031 = v_9010;
// end of prologue
    v_9031 = qcar(v_9031);
    v_9032 = v_9031;
    v_9031 = v_9032;
    if (is_number(v_9031)) goto v_9018;
    v_9031 = nil;
    goto v_9016;
v_9018:
    goto v_9028;
v_9024:
    goto v_9025;
v_9026:
    v_9031 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9027;
v_9028:
    goto v_9024;
v_9025:
    goto v_9026;
v_9027:
        return Lgreaterp(nil, v_9032, v_9031);
    v_9031 = nil;
v_9016:
    return onevalue(v_9031);
}



// Code for groebbuchcrit4t

static LispObject CC_groebbuchcrit4t(LispObject env,
                         LispObject v_9010, LispObject v_9011)
{
    env = qenv(env);
    LispObject v_9064, v_9065;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9011,v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9010,v_9011);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_9011;
    stack[-1] = v_9010;
// end of prologue
v_9015:
    v_9064 = stack[-1];
    if (v_9064 == nil) goto v_9022;
    else goto v_9023;
v_9022:
    v_9064 = lisp_true;
    goto v_9021;
v_9023:
    v_9064 = stack[0];
    v_9064 = (v_9064 == nil ? lisp_true : nil);
    goto v_9021;
    v_9064 = nil;
v_9021:
    if (v_9064 == nil) goto v_9019;
    v_9064 = nil;
    goto v_9014;
v_9019:
    goto v_9041;
v_9037:
    v_9064 = stack[-1];
    v_9065 = qcar(v_9064);
    goto v_9038;
v_9039:
    v_9064 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9040;
v_9041:
    goto v_9037;
v_9038:
    goto v_9039;
v_9040:
    if (v_9065 == v_9064) goto v_9036;
    goto v_9050;
v_9046:
    v_9064 = stack[0];
    v_9065 = qcar(v_9064);
    goto v_9047;
v_9048:
    v_9064 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9049;
v_9050:
    goto v_9046;
v_9047:
    goto v_9048;
v_9049:
    v_9064 = Lneq(nil, v_9065, v_9064);
    env = stack[-2];
    goto v_9034;
v_9036:
    v_9064 = nil;
    goto v_9034;
    v_9064 = nil;
v_9034:
    if (v_9064 == nil) goto v_9032;
    v_9064 = lisp_true;
    goto v_9014;
v_9032:
    v_9064 = stack[-1];
    v_9064 = qcdr(v_9064);
    stack[-1] = v_9064;
    v_9064 = stack[0];
    v_9064 = qcdr(v_9064);
    stack[0] = v_9064;
    goto v_9015;
    v_9064 = nil;
v_9014:
    return onevalue(v_9064);
}



// Code for !*pf2wedgepf

static LispObject CC_Hpf2wedgepf(LispObject env,
                         LispObject v_9010)
{
    env = qenv(env);
    LispObject v_9043, v_9044, v_9045;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9010);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_9010;
// end of prologue
    stack[-1] = nil;
v_9015:
    v_9043 = stack[0];
    if (v_9043 == nil) goto v_9018;
    else goto v_9019;
v_9018:
    v_9043 = stack[-1];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_9043);
    }
v_9019:
    goto v_9032;
v_9026:
    v_9043 = stack[0];
    v_9043 = qcar(v_9043);
    v_9043 = qcar(v_9043);
    fn = elt(env, 2); // wedgefax
    v_9045 = (*qfn1(fn))(fn, v_9043);
    env = stack[-2];
    goto v_9027;
v_9028:
    v_9043 = stack[0];
    v_9043 = qcar(v_9043);
    v_9044 = qcdr(v_9043);
    goto v_9029;
v_9030:
    v_9043 = stack[-1];
    goto v_9031;
v_9032:
    goto v_9026;
v_9027:
    goto v_9028;
v_9029:
    goto v_9030;
v_9031:
    v_9043 = acons(v_9045, v_9044, v_9043);
    env = stack[-2];
    stack[-1] = v_9043;
    v_9043 = stack[0];
    v_9043 = qcdr(v_9043);
    stack[0] = v_9043;
    goto v_9015;
    v_9043 = nil;
    return onevalue(v_9043);
}



// Code for removeindices

static LispObject CC_removeindices(LispObject env,
                         LispObject v_9010, LispObject v_9011)
{
    env = qenv(env);
    LispObject v_9154, v_9155;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9011,v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9010,v_9011);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_9011;
    stack[-3] = v_9010;
// end of prologue
    v_9154 = elt(env, 0); // removeindices
    if (!symbolp(v_9154)) v_9154 = nil;
    else { v_9154 = qfastgets(v_9154);
           if (v_9154 != nil) { v_9154 = elt(v_9154, 53); // tracing
#ifdef RECORD_GET
             if (v_9154 == SPID_NOPROP)
                record_get(elt(fastget_names, 53), 0),
                v_9154 = nil;
             else record_get(elt(fastget_names, 53), 1),
                v_9154 = lisp_true; }
           else record_get(elt(fastget_names, 53), 0); }
#else
             if (v_9154 == SPID_NOPROP) v_9154 = nil; else v_9154 = lisp_true; }}
#endif
    if (v_9154 == nil) goto v_9020;
    goto v_9033;
v_9025:
    stack[-4] = elt(env, 0); // removeindices
    goto v_9026;
v_9027:
    stack[-1] = elt(env, 2); // "u= "
    goto v_9028;
v_9029:
    stack[0] = stack[-3];
    goto v_9030;
v_9031:
    goto v_9042;
v_9038:
    v_9155 = elt(env, 3); // " x= "
    goto v_9039;
v_9040:
    v_9154 = stack[-2];
    goto v_9041;
v_9042:
    goto v_9038;
v_9039:
    goto v_9040;
v_9041:
    v_9154 = list2(v_9155, v_9154);
    env = stack[-5];
    goto v_9032;
v_9033:
    goto v_9025;
v_9026:
    goto v_9027;
v_9028:
    goto v_9029;
v_9030:
    goto v_9031;
v_9032:
    v_9154 = list3star(stack[-4], stack[-1], stack[0], v_9154);
    env = stack[-5];
    fn = elt(env, 5); // trwrite
    v_9154 = (*qfn1(fn))(fn, v_9154);
    env = stack[-5];
    goto v_9018;
v_9020:
v_9018:
    v_9154 = stack[-2];
    if (v_9154 == nil) goto v_9051;
    else goto v_9052;
v_9051:
    v_9154 = lisp_true;
    goto v_9050;
v_9052:
    v_9154 = stack[-3];
    v_9154 = Lsymbolp(nil, v_9154);
    env = stack[-5];
    if (v_9154 == nil) goto v_9059;
    else goto v_9058;
v_9059:
    v_9154 = stack[-3];
    fn = elt(env, 6); // !*physopp
    v_9154 = (*qfn1(fn))(fn, v_9154);
    env = stack[-5];
    v_9154 = (v_9154 == nil ? lisp_true : nil);
v_9058:
    goto v_9050;
    v_9154 = nil;
v_9050:
    if (v_9154 == nil) goto v_9048;
    v_9154 = stack[-3];
    goto v_9015;
v_9048:
    v_9154 = stack[-2];
    if (symbolp(v_9154)) goto v_9071;
    else goto v_9070;
v_9071:
    v_9154 = stack[-2];
    fn = elt(env, 7); // isanindex
    v_9154 = (*qfn1(fn))(fn, v_9154);
    env = stack[-5];
    if (v_9154 == nil) goto v_9073;
    else goto v_9070;
v_9073:
    goto v_9068;
v_9070:
    v_9154 = stack[-2];
    fn = elt(env, 8); // idlistp
    v_9154 = (*qfn1(fn))(fn, v_9154);
    env = stack[-5];
    if (v_9154 == nil) goto v_9076;
    v_9154 = stack[-2];
    fn = elt(env, 9); // areallindices
    v_9154 = (*qfn1(fn))(fn, v_9154);
    env = stack[-5];
    if (v_9154 == nil) goto v_9080;
    else goto v_9076;
v_9080:
    goto v_9068;
v_9076:
    goto v_9069;
v_9068:
    goto v_9088;
v_9084:
    v_9155 = elt(env, 0); // removeindices
    goto v_9085;
v_9086:
    v_9154 = elt(env, 4); // "invalid arguments to removeindices"
    goto v_9087;
v_9088:
    goto v_9084;
v_9085:
    goto v_9086;
v_9087:
    fn = elt(env, 10); // rederr2
    v_9154 = (*qfn2(fn))(fn, v_9155, v_9154);
    env = stack[-5];
    goto v_9067;
v_9069:
v_9067:
    v_9154 = stack[-3];
    v_9154 = qcar(v_9154);
    stack[0] = v_9154;
    v_9154 = stack[-3];
    v_9154 = qcdr(v_9154);
    stack[-3] = v_9154;
    v_9154 = stack[-3];
    if (v_9154 == nil) goto v_9097;
    else goto v_9098;
v_9097:
    v_9154 = stack[0];
    goto v_9015;
v_9098:
    v_9154 = stack[-2];
    if (symbolp(v_9154)) goto v_9101;
    else goto v_9102;
v_9101:
    goto v_9109;
v_9105:
    v_9155 = stack[-2];
    goto v_9106;
v_9107:
    v_9154 = stack[-3];
    goto v_9108;
v_9109:
    goto v_9105;
v_9106:
    goto v_9107;
v_9108:
    v_9154 = Ldelete(nil, v_9155, v_9154);
    stack[-3] = v_9154;
    goto v_9096;
v_9102:
    v_9154 = stack[-2];
    stack[-1] = v_9154;
v_9117:
    v_9154 = stack[-1];
    if (v_9154 == nil) goto v_9121;
    else goto v_9122;
v_9121:
    goto v_9116;
v_9122:
    v_9154 = stack[-1];
    v_9154 = qcar(v_9154);
    goto v_9133;
v_9129:
    v_9155 = v_9154;
    goto v_9130;
v_9131:
    v_9154 = stack[-3];
    goto v_9132;
v_9133:
    goto v_9129;
v_9130:
    goto v_9131;
v_9132:
    v_9154 = Ldelete(nil, v_9155, v_9154);
    env = stack[-5];
    stack[-3] = v_9154;
    v_9154 = stack[-1];
    v_9154 = qcdr(v_9154);
    stack[-1] = v_9154;
    goto v_9117;
v_9116:
    goto v_9096;
v_9096:
    v_9154 = stack[-3];
    if (v_9154 == nil) goto v_9140;
    else goto v_9141;
v_9140:
    v_9154 = stack[0];
    goto v_9139;
v_9141:
    goto v_9151;
v_9147:
    v_9155 = stack[0];
    goto v_9148;
v_9149:
    v_9154 = stack[-3];
    goto v_9150;
v_9151:
    goto v_9147;
v_9148:
    goto v_9149;
v_9150:
    return cons(v_9155, v_9154);
    v_9154 = nil;
v_9139:
v_9015:
    return onevalue(v_9154);
}



// Code for simprepart

static LispObject CC_simprepart(LispObject env,
                         LispObject v_9010)
{
    env = qenv(env);
    LispObject v_9018, v_9019;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9010);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_9019 = v_9010;
// end of prologue
    v_9018 = nil;
// Binding !*factor
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_9018; // !*factor
    v_9018 = v_9019;
    v_9018 = qcar(v_9018);
    fn = elt(env, 2); // simp!*
    v_9018 = (*qfn1(fn))(fn, v_9018);
    env = stack[-1];
    fn = elt(env, 3); // repartsq
    v_9018 = (*qfn1(fn))(fn, v_9018);
    ;}  // end of a binding scope
    return onevalue(v_9018);
}



// Code for xread1

static LispObject CC_xread1(LispObject env,
                         LispObject v_9010)
{
    env = qenv(env);
    LispObject v_10386, v_10387, v_10388;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9010);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_9010;
// end of prologue
    stack[-8] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v_10386 = qvalue(elt(env, 2)); // commentlist!*
    if (v_10386 == nil) goto v_9048;
    v_10386 = qvalue(elt(env, 2)); // commentlist!*
    stack[-1] = v_10386;
    v_10386 = nil;
    qvalue(elt(env, 2)) = v_10386; // commentlist!*
    goto v_9046;
v_9048:
v_9046:
v_9022:
    v_10386 = qvalue(elt(env, 3)); // cursym!*
    stack[-3] = v_10386;
v_9023:
    v_10386 = stack[-3];
    if (symbolp(v_10386)) goto v_9056;
    goto v_9054;
v_9056:
    goto v_9065;
v_9061:
    v_10387 = stack[-3];
    goto v_9062;
v_9063:
    v_10386 = elt(env, 4); // !*lpar!*
    goto v_9064;
v_9065:
    goto v_9061;
v_9062:
    goto v_9063;
v_9064:
    if (v_10387 == v_10386) goto v_9059;
    else goto v_9060;
v_9059:
    goto v_9027;
v_9060:
    goto v_9074;
v_9070:
    v_10387 = stack[-3];
    goto v_9071;
v_9072:
    v_10386 = elt(env, 5); // !*rpar!*
    goto v_9073;
v_9074:
    goto v_9070;
v_9071:
    goto v_9072;
v_9073:
    if (v_10387 == v_10386) goto v_9068;
    else goto v_9069;
v_9068:
    goto v_9029;
v_9069:
    v_10386 = stack[-3];
    if (!symbolp(v_10386)) v_10386 = nil;
    else { v_10386 = qfastgets(v_10386);
           if (v_10386 != nil) { v_10386 = elt(v_10386, 23); // infix
#ifdef RECORD_GET
             if (v_10386 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_10386 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_10386 == SPID_NOPROP) v_10386 = nil; }}
#endif
    stack[-4] = v_10386;
    if (v_10386 == nil) goto v_9078;
    goto v_9030;
v_9078:
    v_10386 = stack[-3];
    if (!symbolp(v_10386)) v_10386 = nil;
    else { v_10386 = qfastgets(v_10386);
           if (v_10386 != nil) { v_10386 = elt(v_10386, 55); // delim
#ifdef RECORD_GET
             if (v_10386 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v_10386 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v_10386 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v_10386 == SPID_NOPROP) v_10386 = nil; else v_10386 = lisp_true; }}
#endif
    if (v_10386 == nil) goto v_9082;
    goto v_9041;
v_9082:
    v_10386 = stack[-3];
    if (!symbolp(v_10386)) v_10386 = nil;
    else { v_10386 = qfastgets(v_10386);
           if (v_10386 != nil) { v_10386 = elt(v_10386, 36); // stat
#ifdef RECORD_GET
             if (v_10386 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v_10386 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v_10386 == SPID_NOPROP) v_10386 = nil; }}
#endif
    stack[-4] = v_10386;
    if (v_10386 == nil) goto v_9086;
    goto v_9040;
v_9086:
    v_10386 = qvalue(elt(env, 6)); // !*reduce4
    if (v_10386 == nil) goto v_9093;
    else goto v_9094;
v_9093:
    goto v_9101;
v_9097:
    v_10387 = stack[-3];
    goto v_9098;
v_9099:
    v_10386 = elt(env, 7); // type
    goto v_9100;
v_9101:
    goto v_9097;
v_9098:
    goto v_9099;
v_9100:
    v_10386 = Lflagp(nil, v_10387, v_10386);
    env = stack[-9];
    goto v_9092;
v_9094:
    v_10386 = nil;
    goto v_9092;
    v_10386 = nil;
v_9092:
    if (v_10386 == nil) goto v_9090;
    goto v_9112;
v_9108:
    goto v_9118;
v_9114:
    v_10387 = elt(env, 8); // decstat
    goto v_9115;
v_9116:
    v_10386 = nil;
    goto v_9117;
v_9118:
    goto v_9114;
v_9115:
    goto v_9116;
v_9117:
    fn = elt(env, 49); // lispapply
    v_10387 = (*qfn2(fn))(fn, v_10387, v_10386);
    env = stack[-9];
    goto v_9109;
v_9110:
    v_10386 = stack[-6];
    goto v_9111;
v_9112:
    goto v_9108;
v_9109:
    goto v_9110;
v_9111:
    v_10386 = cons(v_10387, v_10386);
    env = stack[-9];
    stack[-6] = v_10386;
    goto v_9022;
v_9090:
v_9054:
v_9024:
    v_10386 = nil;
    stack[-4] = v_10386;
v_9025:
    goto v_9128;
v_9124:
    v_10387 = stack[-3];
    goto v_9125;
v_9126:
    v_10386 = stack[-6];
    goto v_9127;
v_9128:
    goto v_9124;
v_9125:
    goto v_9126;
v_9127:
    v_10386 = cons(v_10387, v_10386);
    env = stack[-9];
    stack[-6] = v_10386;
    v_10386 = stack[-3];
    fn = elt(env, 50); // toknump
    v_10386 = (*qfn1(fn))(fn, v_10386);
    env = stack[-9];
    if (v_10386 == nil) goto v_9134;
    goto v_9147;
v_9143:
    v_10387 = stack[-2];
    goto v_9144;
v_9145:
    v_10386 = qvalue(elt(env, 9)); // !$eol!$
    goto v_9146;
v_9147:
    goto v_9143;
v_9144:
    goto v_9145;
v_9146:
    if (v_10387 == v_10386) goto v_9142;
    v_10386 = qvalue(elt(env, 10)); // nxtsym!*
    fn = elt(env, 51); // chknewnam
    v_10386 = (*qfn1(fn))(fn, v_10386);
    env = stack[-9];
    stack[-2] = v_10386;
    if (symbolp(v_10386)) goto v_9153;
    v_10386 = nil;
    goto v_9151;
v_9153:
    v_10386 = stack[-2];
    if (!symbolp(v_10386)) v_10386 = nil;
    else { v_10386 = qfastgets(v_10386);
           if (v_10386 != nil) { v_10386 = elt(v_10386, 55); // delim
#ifdef RECORD_GET
             if (v_10386 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v_10386 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v_10386 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v_10386 == SPID_NOPROP) v_10386 = nil; else v_10386 = lisp_true; }}
#endif
    if (v_10386 == nil) goto v_9161;
    else goto v_9162;
v_9161:
    v_10386 = stack[-2];
    if (!symbolp(v_10386)) v_10386 = nil;
    else { v_10386 = qfastgets(v_10386);
           if (v_10386 != nil) { v_10386 = elt(v_10386, 11); // switch!*
#ifdef RECORD_GET
             if (v_10386 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v_10386 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v_10386 == SPID_NOPROP) v_10386 = nil; }}
#endif
    if (v_10386 == nil) goto v_9167;
    goto v_9177;
v_9173:
    v_10387 = stack[-2];
    goto v_9174;
v_9175:
    v_10386 = elt(env, 11); // !(
    goto v_9176;
v_9177:
    goto v_9173;
v_9174:
    goto v_9175;
v_9176:
    if (v_10387 == v_10386) goto v_9167;
    goto v_9168;
v_9167:
    v_10386 = stack[-2];
    if (!symbolp(v_10386)) v_10386 = nil;
    else { v_10386 = qfastgets(v_10386);
           if (v_10386 != nil) { v_10386 = elt(v_10386, 23); // infix
#ifdef RECORD_GET
             if (v_10386 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_10386 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_10386 == SPID_NOPROP) v_10386 = nil; }}
#endif
    if (v_10386 == nil) goto v_9182;
    else goto v_9183;
v_9182:
    v_10386 = qvalue(elt(env, 12)); // !*eoldelimp
    if (v_10386 == nil) goto v_9188;
    else goto v_9189;
v_9188:
    v_10386 = nil;
    goto v_9187;
v_9189:
    goto v_9198;
v_9194:
    v_10387 = stack[-2];
    goto v_9195;
v_9196:
    v_10386 = qvalue(elt(env, 9)); // !$eol!$
    goto v_9197;
v_9198:
    goto v_9194;
v_9195:
    goto v_9196;
v_9197:
    v_10386 = (v_10387 == v_10386 ? lisp_true : nil);
    goto v_9187;
    v_10386 = nil;
v_9187:
    v_10386 = (v_10386 == nil ? lisp_true : nil);
    goto v_9181;
v_9183:
    v_10386 = nil;
    goto v_9181;
    v_10386 = nil;
v_9181:
    goto v_9166;
v_9168:
    v_10386 = nil;
    goto v_9166;
    v_10386 = nil;
v_9166:
    goto v_9160;
v_9162:
    v_10386 = nil;
    goto v_9160;
    v_10386 = nil;
v_9160:
    goto v_9151;
    v_10386 = nil;
v_9151:
    goto v_9140;
v_9142:
    v_10386 = nil;
    goto v_9140;
    v_10386 = nil;
v_9140:
    if (v_10386 == nil) goto v_9134;
    v_10386 = elt(env, 13); // times
    qvalue(elt(env, 3)) = v_10386; // cursym!*
    v_10386 = nil;
    qvalue(elt(env, 14)) = v_10386; // curescaped!*
    goto v_9022;
v_9134:
    goto v_9227;
v_9223:
    v_10387 = stack[-7];
    goto v_9224;
v_9225:
    v_10386 = elt(env, 15); // proc
    goto v_9226;
v_9227:
    goto v_9223;
v_9224:
    goto v_9225;
v_9226:
    if (v_10387 == v_10386) goto v_9221;
    else goto v_9222;
v_9221:
    goto v_9235;
v_9231:
    v_10386 = stack[-6];
    v_10387 = Llength(nil, v_10386);
    env = stack[-9];
    goto v_9232;
v_9233:
    v_10386 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_9234;
v_9235:
    goto v_9231;
v_9232:
    goto v_9233;
v_9234:
    v_10386 = (LispObject)greaterp2(v_10387, v_10386);
    v_10386 = v_10386 ? lisp_true : nil;
    env = stack[-9];
    goto v_9220;
v_9222:
    v_10386 = nil;
    goto v_9220;
    v_10386 = nil;
v_9220:
    if (v_10386 == nil) goto v_9218;
    goto v_9247;
v_9243:
    v_10387 = elt(env, 16); // "Syntax error in procedure header"
    goto v_9244;
v_9245:
    v_10386 = nil;
    goto v_9246;
v_9247:
    goto v_9243;
v_9244:
    goto v_9245;
v_9246:
    fn = elt(env, 52); // symerr
    v_10386 = (*qfn2(fn))(fn, v_10387, v_10386);
    env = stack[-9];
    goto v_9132;
v_9218:
v_9132:
v_9026:
    fn = elt(env, 53); // scan
    v_10386 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    stack[-3] = v_10386;
    goto v_9023;
v_9027:
    fn = elt(env, 54); // eolcheck
    v_10386 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    v_10386 = nil;
    stack[-4] = v_10386;
    goto v_9261;
v_9257:
    fn = elt(env, 53); // scan
    v_10387 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    goto v_9258;
v_9259:
    v_10386 = elt(env, 5); // !*rpar!*
    goto v_9260;
v_9261:
    goto v_9257;
v_9258:
    goto v_9259;
v_9260:
    if (v_10387 == v_10386) goto v_9255;
    else goto v_9256;
v_9255:
    goto v_9028;
v_9256:
    goto v_9271;
v_9267:
    v_10387 = stack[-6];
    goto v_9268;
v_9269:
    v_10386 = elt(env, 17); // struct
    goto v_9270;
v_9271:
    goto v_9267;
v_9268:
    goto v_9269;
v_9270:
    v_10386 = Lflagpcar(nil, v_10387, v_10386);
    env = stack[-9];
    if (v_10386 == nil) goto v_9265;
    v_10386 = stack[-6];
    v_10386 = qcar(v_10386);
    v_10386 = CC_xread1(elt(env, 0), v_10386);
    env = stack[-9];
    stack[-3] = v_10386;
    goto v_9254;
v_9265:
    v_10386 = elt(env, 18); // paren
    v_10386 = CC_xread1(elt(env, 0), v_10386);
    env = stack[-9];
    stack[-3] = v_10386;
    goto v_9254;
v_9254:
    goto v_9290;
v_9286:
    v_10387 = stack[-7];
    goto v_9287;
v_9288:
    v_10386 = elt(env, 17); // struct
    goto v_9289;
v_9290:
    goto v_9286;
v_9287:
    goto v_9288;
v_9289:
    v_10386 = Lflagp(nil, v_10387, v_10386);
    env = stack[-9];
    if (v_10386 == nil) goto v_9284;
    v_10386 = stack[-3];
    fn = elt(env, 55); // remcomma
    v_10386 = (*qfn1(fn))(fn, v_10386);
    env = stack[-9];
    stack[-3] = v_10386;
    goto v_9025;
v_9284:
    goto v_9302;
v_9298:
    v_10387 = stack[-3];
    goto v_9299;
v_9300:
    v_10386 = elt(env, 19); // !*comma!*
    goto v_9301;
v_9302:
    goto v_9298;
v_9299:
    goto v_9300;
v_9301:
    if (!consp(v_10387)) goto v_9295;
    v_10387 = qcar(v_10387);
    if (v_10387 == v_10386) goto v_9296;
v_9295:
    goto v_9025;
v_9296:
    v_10386 = stack[-6];
    if (v_10386 == nil) goto v_9305;
    else goto v_9306;
v_9305:
    goto v_9316;
v_9312:
    v_10387 = stack[-7];
    goto v_9313;
v_9314:
    v_10386 = elt(env, 20); // lambda
    goto v_9315;
v_9316:
    goto v_9312;
v_9313:
    goto v_9314;
v_9315:
    if (v_10387 == v_10386) goto v_9310;
    else goto v_9311;
v_9310:
    goto v_9025;
v_9311:
    goto v_9326;
v_9322:
    v_10387 = elt(env, 21); // "Improper delimiter"
    goto v_9323;
v_9324:
    v_10386 = nil;
    goto v_9325;
v_9326:
    goto v_9322;
v_9323:
    goto v_9324;
v_9325:
    fn = elt(env, 52); // symerr
    v_10386 = (*qfn2(fn))(fn, v_10387, v_10386);
    env = stack[-9];
    goto v_9309;
v_9309:
    goto v_9282;
v_9306:
    goto v_9338;
v_9332:
    v_10386 = stack[-6];
    v_10388 = qcar(v_10386);
    goto v_9333;
v_9334:
    v_10386 = stack[-3];
    v_10387 = qcdr(v_10386);
    goto v_9335;
v_9336:
    v_10386 = stack[-6];
    v_10386 = qcdr(v_10386);
    goto v_9337;
v_9338:
    goto v_9332;
v_9333:
    goto v_9334;
v_9335:
    goto v_9336;
v_9337:
    v_10386 = acons(v_10388, v_10387, v_10386);
    env = stack[-9];
    stack[-6] = v_10386;
    goto v_9282;
v_9282:
    goto v_9026;
v_9028:
    v_10386 = stack[-6];
    if (v_10386 == nil) goto v_9348;
    goto v_9355;
v_9351:
    v_10386 = stack[-6];
    v_10386 = qcar(v_10386);
    v_10387 = ncons(v_10386);
    env = stack[-9];
    goto v_9352;
v_9353:
    v_10386 = stack[-6];
    v_10386 = qcdr(v_10386);
    goto v_9354;
v_9355:
    goto v_9351;
v_9352:
    goto v_9353;
v_9354:
    v_10386 = cons(v_10387, v_10386);
    env = stack[-9];
    stack[-6] = v_10386;
    goto v_9346;
v_9348:
v_9346:
    goto v_9026;
v_9029:
    v_10386 = stack[-7];
    if (v_10386 == nil) goto v_9367;
    else goto v_9368;
v_9367:
    v_10386 = lisp_true;
    goto v_9366;
v_9368:
    goto v_9381;
v_9377:
    v_10387 = stack[-7];
    goto v_9378;
v_9379:
    v_10386 = elt(env, 22); // group
    goto v_9380;
v_9381:
    goto v_9377;
v_9378:
    goto v_9379;
v_9380:
    if (v_10387 == v_10386) goto v_9375;
    else goto v_9376;
v_9375:
    v_10386 = lisp_true;
    goto v_9374;
v_9376:
    goto v_9391;
v_9387:
    v_10387 = stack[-7];
    goto v_9388;
v_9389:
    v_10386 = elt(env, 15); // proc
    goto v_9390;
v_9391:
    goto v_9387;
v_9388:
    goto v_9389;
v_9390:
    v_10386 = (v_10387 == v_10386 ? lisp_true : nil);
    goto v_9374;
    v_10386 = nil;
v_9374:
    goto v_9366;
    v_10386 = nil;
v_9366:
    if (v_10386 == nil) goto v_9364;
    goto v_9400;
v_9396:
    v_10387 = elt(env, 23); // "Too many right parentheses"
    goto v_9397;
v_9398:
    v_10386 = nil;
    goto v_9399;
v_9400:
    goto v_9396;
v_9397:
    goto v_9398;
v_9399:
    fn = elt(env, 52); // symerr
    v_10386 = (*qfn2(fn))(fn, v_10387, v_10386);
    env = stack[-9];
    goto v_9362;
v_9364:
    goto v_9042;
v_9362:
v_9030:
    fn = elt(env, 54); // eolcheck
    v_10386 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    goto v_9418;
v_9414:
    v_10387 = stack[-3];
    goto v_9415;
v_9416:
    v_10386 = elt(env, 19); // !*comma!*
    goto v_9417;
v_9418:
    goto v_9414;
v_9415:
    goto v_9416;
v_9417:
    if (v_10387 == v_10386) goto v_9412;
    else goto v_9413;
v_9412:
    v_10386 = lisp_true;
    goto v_9411;
v_9413:
    fn = elt(env, 53); // scan
    v_10386 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    stack[-2] = v_10386;
    if (!consp(v_10386)) goto v_9427;
    v_10386 = lisp_true;
    goto v_9425;
v_9427:
    v_10386 = stack[-2];
    fn = elt(env, 50); // toknump
    v_10386 = (*qfn1(fn))(fn, v_10386);
    env = stack[-9];
    goto v_9425;
    v_10386 = nil;
v_9425:
    goto v_9411;
    v_10386 = nil;
v_9411:
    if (v_10386 == nil) goto v_9409;
    goto v_9031;
v_9409:
    goto v_9444;
v_9440:
    v_10387 = stack[-2];
    goto v_9441;
v_9442:
    v_10386 = elt(env, 5); // !*rpar!*
    goto v_9443;
v_9444:
    goto v_9440;
v_9441:
    goto v_9442;
v_9443:
    if (v_10387 == v_10386) goto v_9438;
    else goto v_9439;
v_9438:
    v_10386 = lisp_true;
    goto v_9437;
v_9439:
    goto v_9458;
v_9454:
    v_10387 = stack[-2];
    goto v_9455;
v_9456:
    v_10386 = elt(env, 19); // !*comma!*
    goto v_9457;
v_9458:
    goto v_9454;
v_9455:
    goto v_9456;
v_9457:
    if (v_10387 == v_10386) goto v_9452;
    else goto v_9453;
v_9452:
    v_10386 = lisp_true;
    goto v_9451;
v_9453:
    v_10386 = stack[-2];
    if (!symbolp(v_10386)) v_10386 = nil;
    else { v_10386 = qfastgets(v_10386);
           if (v_10386 != nil) { v_10386 = elt(v_10386, 55); // delim
#ifdef RECORD_GET
             if (v_10386 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v_10386 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v_10386 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v_10386 == SPID_NOPROP) v_10386 = nil; else v_10386 = lisp_true; }}
#endif
    goto v_9451;
    v_10386 = nil;
v_9451:
    goto v_9437;
    v_10386 = nil;
v_9437:
    if (v_10386 == nil) goto v_9435;
    goto v_9032;
v_9435:
    goto v_9476;
v_9472:
    v_10387 = stack[-2];
    goto v_9473;
v_9474:
    v_10386 = elt(env, 4); // !*lpar!*
    goto v_9475;
v_9476:
    goto v_9472;
v_9473:
    goto v_9474;
v_9475:
    if (v_10387 == v_10386) goto v_9470;
    else goto v_9471;
v_9470:
    fn = elt(env, 54); // eolcheck
    v_10386 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    if (v_10386 == nil) goto v_9481;
    else goto v_9482;
v_9481:
    v_10386 = elt(env, 18); // paren
    fn = elt(env, 56); // xread
    v_10386 = (*qfn1(fn))(fn, v_10386);
    env = stack[-9];
    stack[-2] = v_10386;
    if (!consp(v_10386)) goto v_9487;
    goto v_9498;
v_9494:
    v_10386 = stack[-2];
    v_10387 = qcar(v_10386);
    goto v_9495;
v_9496:
    v_10386 = elt(env, 19); // !*comma!*
    goto v_9497;
v_9498:
    goto v_9494;
v_9495:
    goto v_9496;
v_9497:
    if (v_10387 == v_10386) goto v_9492;
    else goto v_9493;
v_9492:
    goto v_9507;
v_9503:
    v_10387 = stack[-3];
    goto v_9504;
v_9505:
    v_10386 = stack[-2];
    v_10386 = qcdr(v_10386);
    goto v_9506;
v_9507:
    goto v_9503;
v_9504:
    goto v_9505;
v_9506:
    v_10386 = cons(v_10387, v_10386);
    env = stack[-9];
    stack[-3] = v_10386;
    goto v_9491;
v_9493:
    v_10386 = nil;
    goto v_9491;
    v_10386 = nil;
v_9491:
    goto v_9485;
v_9487:
    v_10386 = nil;
    goto v_9485;
    v_10386 = nil;
v_9485:
    goto v_9480;
v_9482:
    v_10386 = nil;
    goto v_9480;
    v_10386 = nil;
v_9480:
    goto v_9469;
v_9471:
    v_10386 = nil;
    goto v_9469;
    v_10386 = nil;
v_9469:
    if (v_10386 == nil) goto v_9467;
    goto v_9023;
v_9467:
v_9031:
    v_10386 = stack[-6];
    if (v_10386 == nil) goto v_9526;
    goto v_9034;
v_9526:
    goto v_9535;
v_9531:
    v_10387 = stack[-3];
    goto v_9532;
v_9533:
    v_10386 = elt(env, 24); // unary
    goto v_9534;
v_9535:
    goto v_9531;
v_9532:
    goto v_9533;
v_9534:
    v_10386 = get(v_10387, v_10386);
    env = stack[-9];
    stack[-3] = v_10386;
    if (v_10386 == nil) goto v_9528;
    else goto v_9529;
v_9528:
    goto v_9543;
v_9539:
    v_10387 = elt(env, 25); // "Redundant operator"
    goto v_9540;
v_9541:
    v_10386 = nil;
    goto v_9542;
v_9543:
    goto v_9539;
v_9540:
    goto v_9541;
v_9542:
    fn = elt(env, 52); // symerr
    v_10386 = (*qfn2(fn))(fn, v_10387, v_10386);
    env = stack[-9];
    goto v_9524;
v_9529:
v_9524:
    goto v_9551;
v_9547:
    v_10387 = elt(env, 26); // !*!*un!*!*
    goto v_9548;
v_9549:
    v_10386 = stack[-8];
    goto v_9550;
v_9551:
    goto v_9547;
v_9548:
    goto v_9549;
v_9550:
    v_10386 = cons(v_10387, v_10386);
    env = stack[-9];
    stack[-8] = v_10386;
    goto v_9038;
v_9032:
    v_10386 = stack[-4];
    if (v_10386 == nil) goto v_9557;
    v_10386 = nil;
    stack[-4] = v_10386;
    goto v_9555;
v_9557:
v_9555:
    goto v_9565;
v_9561:
    v_10387 = stack[-3];
    goto v_9562;
v_9563:
    v_10386 = stack[-6];
    goto v_9564;
v_9565:
    goto v_9561;
v_9562:
    goto v_9563;
v_9564:
    v_10386 = cons(v_10387, v_10386);
    env = stack[-9];
    stack[-6] = v_10386;
v_9033:
    v_10386 = stack[-2];
    stack[-3] = v_10386;
    goto v_9023;
v_9034:
    v_10386 = stack[-6];
    if (v_10386 == nil) goto v_9571;
    else goto v_9572;
v_9571:
    goto v_9579;
v_9575:
    v_10387 = elt(env, 21); // "Improper delimiter"
    goto v_9576;
v_9577:
    v_10386 = nil;
    goto v_9578;
v_9579:
    goto v_9575;
v_9576:
    goto v_9577;
v_9578:
    fn = elt(env, 52); // symerr
    v_10386 = (*qfn2(fn))(fn, v_10387, v_10386);
    env = stack[-9];
    goto v_9570;
v_9572:
v_9570:
    goto v_9587;
v_9583:
    v_10386 = stack[-6];
    v_10387 = qcar(v_10386);
    goto v_9584;
v_9585:
    v_10386 = stack[-3];
    goto v_9586;
v_9587:
    goto v_9583;
v_9584:
    goto v_9585;
v_9586:
    fn = elt(env, 57); // mkvar
    v_10386 = (*qfn2(fn))(fn, v_10387, v_10386);
    env = stack[-9];
    stack[0] = v_10386;
v_9035:
    v_10386 = stack[-6];
    v_10386 = qcdr(v_10386);
    stack[-6] = v_10386;
    v_10386 = stack[-6];
    if (v_10386 == nil) goto v_9595;
    else goto v_9596;
v_9595:
    goto v_9036;
v_9596:
    v_10386 = stack[-6];
    v_10386 = qcar(v_10386);
    if (!consp(v_10386)) goto v_9602;
    else goto v_9603;
v_9602:
    v_10386 = stack[-6];
    v_10386 = qcar(v_10386);
    v_10386 = Lsymbolp(nil, v_10386);
    env = stack[-9];
    v_10386 = (v_10386 == nil ? lisp_true : nil);
    goto v_9601;
v_9603:
    v_10386 = nil;
    goto v_9601;
    v_10386 = nil;
v_9601:
    if (v_10386 == nil) goto v_9599;
    goto v_9618;
v_9614:
    v_10387 = elt(env, 27); // "Missing operator"
    goto v_9615;
v_9616:
    v_10386 = nil;
    goto v_9617;
v_9618:
    goto v_9614;
v_9615:
    goto v_9616;
v_9617:
    fn = elt(env, 52); // symerr
    v_10386 = (*qfn2(fn))(fn, v_10387, v_10386);
    env = stack[-9];
    goto v_9594;
v_9599:
v_9594:
    goto v_9626;
v_9622:
    v_10386 = stack[-6];
    v_10387 = qcar(v_10386);
    goto v_9623;
v_9624:
    v_10386 = stack[0];
    goto v_9625;
v_9626:
    goto v_9622;
v_9623:
    goto v_9624;
v_9625:
    v_10386 = list2(v_10387, v_10386);
    env = stack[-9];
    stack[0] = v_10386;
    goto v_9035;
v_9036:
    goto v_9635;
v_9631:
    v_10387 = stack[0];
    goto v_9632;
v_9633:
    v_10386 = stack[-8];
    goto v_9634;
v_9635:
    goto v_9631;
v_9632:
    goto v_9633;
v_9634:
    v_10386 = cons(v_10387, v_10386);
    env = stack[-9];
    stack[-8] = v_10386;
v_9037:
    v_10386 = stack[-5];
    if (v_10386 == nil) goto v_9640;
    else goto v_9641;
v_9640:
    goto v_9651;
v_9647:
    v_10387 = stack[-4];
    goto v_9648;
v_9649:
    v_10386 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9650;
v_9651:
    goto v_9647;
v_9648:
    goto v_9649;
v_9650:
    if (v_10387 == v_10386) goto v_9645;
    else goto v_9646;
v_9645:
    goto v_9043;
v_9646:
    goto v_9644;
v_9644:
    goto v_9639;
v_9641:
    v_10386 = stack[-8];
    if (v_10386 == nil) goto v_9658;
    goto v_9671;
v_9667:
    v_10386 = stack[-8];
    v_10387 = qcdr(v_10386);
    goto v_9668;
v_9669:
    v_10386 = elt(env, 26); // !*!*un!*!*
    goto v_9670;
v_9671:
    goto v_9667;
v_9668:
    goto v_9669;
v_9670:
    if (!consp(v_10387)) goto v_9665;
    v_10387 = qcar(v_10387);
    if (v_10387 == v_10386) goto v_9664;
    else goto v_9665;
v_9664:
    v_10386 = stack[-5];
    v_10386 = qcdr(v_10386);
    if (v_10386 == nil) goto v_9677;
    else goto v_9678;
v_9677:
    v_10386 = nil;
    goto v_9676;
v_9678:
    goto v_9693;
v_9689:
    v_10387 = stack[-4];
    goto v_9690;
v_9691:
    v_10386 = stack[-5];
    v_10386 = qcar(v_10386);
    v_10386 = qcar(v_10386);
    goto v_9692;
v_9693:
    goto v_9689;
v_9690:
    goto v_9691;
v_9692:
    v_10386 = (LispObject)geq2(v_10387, v_10386);
    v_10386 = v_10386 ? lisp_true : nil;
    env = stack[-9];
    if (v_10386 == nil) goto v_9686;
    else goto v_9687;
v_9686:
    v_10386 = nil;
    goto v_9685;
v_9687:
    goto v_9706;
v_9702:
    v_10387 = stack[-4];
    goto v_9703;
v_9704:
    v_10386 = stack[-5];
    v_10386 = qcdr(v_10386);
    v_10386 = qcar(v_10386);
    v_10386 = qcar(v_10386);
    goto v_9705;
v_9706:
    goto v_9702;
v_9703:
    goto v_9704;
v_9705:
    v_10386 = (LispObject)lesseq2(v_10387, v_10386);
    v_10386 = v_10386 ? lisp_true : nil;
    env = stack[-9];
    goto v_9685;
    v_10386 = nil;
v_9685:
    goto v_9676;
    v_10386 = nil;
v_9676:
    goto v_9663;
v_9665:
    v_10386 = nil;
    goto v_9663;
    v_10386 = nil;
v_9663:
    if (v_10386 == nil) goto v_9658;
    goto v_9720;
v_9716:
    v_10387 = elt(env, 28); // "Please use parentheses around use of the unary operator"
    goto v_9717;
v_9718:
    v_10386 = nil;
    goto v_9719;
v_9720:
    goto v_9716;
v_9717:
    goto v_9718;
v_9719:
    fn = elt(env, 52); // symerr
    v_10386 = (*qfn2(fn))(fn, v_10387, v_10386);
    env = stack[-9];
    goto v_9639;
v_9658:
    goto v_9731;
v_9727:
    v_10387 = stack[-4];
    goto v_9728;
v_9729:
    v_10386 = stack[-5];
    v_10386 = qcar(v_10386);
    v_10386 = qcar(v_10386);
    goto v_9730;
v_9731:
    goto v_9727;
v_9728:
    goto v_9729;
v_9730:
    v_10386 = (LispObject)lessp2(v_10387, v_10386);
    v_10386 = v_10386 ? lisp_true : nil;
    env = stack[-9];
    if (v_10386 == nil) goto v_9725;
    else goto v_9723;
v_9725:
    goto v_9745;
v_9741:
    v_10387 = stack[-4];
    goto v_9742;
v_9743:
    v_10386 = stack[-5];
    v_10386 = qcar(v_10386);
    v_10386 = qcar(v_10386);
    goto v_9744;
v_9745:
    goto v_9741;
v_9742:
    goto v_9743;
v_9744:
    if (equal(v_10387, v_10386)) goto v_9739;
    else goto v_9740;
v_9739:
    goto v_9762;
v_9758:
    v_10387 = stack[-3];
    goto v_9759;
v_9760:
    v_10386 = stack[-5];
    v_10386 = qcar(v_10386);
    v_10386 = qcdr(v_10386);
    goto v_9761;
v_9762:
    goto v_9758;
v_9759:
    goto v_9760;
v_9761:
    if (v_10387 == v_10386) goto v_9756;
    else goto v_9757;
v_9756:
    v_10386 = stack[-3];
    if (!symbolp(v_10386)) v_10386 = nil;
    else { v_10386 = qfastgets(v_10386);
           if (v_10386 != nil) { v_10386 = elt(v_10386, 35); // nary
#ifdef RECORD_GET
             if (v_10386 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v_10386 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v_10386 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v_10386 == SPID_NOPROP) v_10386 = nil; else v_10386 = lisp_true; }}
#endif
    if (v_10386 == nil) goto v_9769;
    else goto v_9770;
v_9769:
    goto v_9778;
v_9774:
    v_10387 = stack[-3];
    goto v_9775;
v_9776:
    v_10386 = elt(env, 29); // right
    goto v_9777;
v_9778:
    goto v_9774;
v_9775:
    goto v_9776;
v_9777:
    v_10386 = Lflagp(nil, v_10387, v_10386);
    env = stack[-9];
    v_10386 = (v_10386 == nil ? lisp_true : nil);
    goto v_9768;
v_9770:
    v_10386 = nil;
    goto v_9768;
    v_10386 = nil;
v_9768:
    goto v_9755;
v_9757:
    v_10386 = nil;
    goto v_9755;
    v_10386 = nil;
v_9755:
    if (v_10386 == nil) goto v_9753;
    v_10386 = lisp_true;
    goto v_9751;
v_9753:
    v_10386 = stack[-5];
    v_10386 = qcar(v_10386);
    v_10386 = qcdr(v_10386);
    if (!symbolp(v_10386)) v_10386 = nil;
    else { v_10386 = qfastgets(v_10386);
           if (v_10386 != nil) { v_10386 = elt(v_10386, 49); // alt
#ifdef RECORD_GET
             if (v_10386 != SPID_NOPROP)
                record_get(elt(fastget_names, 49), 1);
             else record_get(elt(fastget_names, 49), 0),
                v_10386 = nil; }
           else record_get(elt(fastget_names, 49), 0); }
#else
             if (v_10386 == SPID_NOPROP) v_10386 = nil; }}
#endif
    goto v_9751;
    v_10386 = nil;
v_9751:
    goto v_9738;
v_9740:
    v_10386 = nil;
    goto v_9738;
    v_10386 = nil;
v_9738:
    if (v_10386 == nil) goto v_9736;
    else goto v_9723;
v_9736:
    goto v_9724;
v_9723:
    goto v_9039;
v_9724:
v_9639:
v_9038:
    goto v_9805;
v_9799:
    v_10388 = stack[-4];
    goto v_9800;
v_9801:
    v_10387 = stack[-3];
    goto v_9802;
v_9803:
    v_10386 = stack[-5];
    goto v_9804;
v_9805:
    goto v_9799;
v_9800:
    goto v_9801;
v_9802:
    goto v_9803;
v_9804:
    v_10386 = acons(v_10388, v_10387, v_10386);
    env = stack[-9];
    stack[-5] = v_10386;
    goto v_9817;
v_9813:
    v_10387 = stack[-3];
    goto v_9814;
v_9815:
    v_10386 = elt(env, 19); // !*comma!*
    goto v_9816;
v_9817:
    goto v_9813;
v_9814:
    goto v_9815;
v_9816:
    if (v_10387 == v_10386) goto v_9812;
    goto v_9033;
v_9812:
    v_10386 = stack[-5];
    v_10386 = qcdr(v_10386);
    if (v_10386 == nil) goto v_9822;
    else goto v_9820;
v_9822:
    v_10386 = stack[-7];
    if (v_10386 == nil) goto v_9828;
    else goto v_9829;
v_9828:
    v_10386 = lisp_true;
    goto v_9827;
v_9829:
    goto v_9841;
v_9837:
    v_10387 = stack[-7];
    goto v_9838;
v_9839:
    v_10386 = elt(env, 30); // (lambda paren)
    goto v_9840;
v_9841:
    goto v_9837;
v_9838:
    goto v_9839;
v_9840:
    v_10386 = Lmemq(nil, v_10387, v_10386);
    if (v_10386 == nil) goto v_9836;
    else goto v_9835;
v_9836:
    goto v_9850;
v_9846:
    v_10387 = stack[-7];
    goto v_9847;
v_9848:
    v_10386 = elt(env, 17); // struct
    goto v_9849;
v_9850:
    goto v_9846;
v_9847:
    goto v_9848;
v_9849:
    v_10386 = Lflagp(nil, v_10387, v_10386);
    env = stack[-9];
v_9835:
    goto v_9827;
    v_10386 = nil;
v_9827:
    if (v_10386 == nil) goto v_9825;
    else goto v_9820;
v_9825:
    goto v_9821;
v_9820:
    goto v_9026;
v_9821:
    goto v_9043;
v_9039:
    goto v_9868;
v_9864:
    v_10386 = stack[-8];
    v_10386 = qcdr(v_10386);
    v_10387 = qcar(v_10386);
    goto v_9865;
v_9866:
    v_10386 = elt(env, 31); // not
    goto v_9867;
v_9868:
    goto v_9864;
v_9865:
    goto v_9866;
v_9867:
    if (!consp(v_10387)) goto v_9862;
    v_10387 = qcar(v_10387);
    if (v_10387 == v_10386) goto v_9861;
    else goto v_9862;
v_9861:
    goto v_9878;
v_9874:
    v_10386 = stack[-5];
    v_10386 = qcar(v_10386);
    v_10387 = qcar(v_10386);
    goto v_9875;
v_9876:
    v_10386 = elt(env, 32); // member
    if (!symbolp(v_10386)) v_10386 = nil;
    else { v_10386 = qfastgets(v_10386);
           if (v_10386 != nil) { v_10386 = elt(v_10386, 23); // infix
#ifdef RECORD_GET
             if (v_10386 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_10386 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_10386 == SPID_NOPROP) v_10386 = nil; }}
#endif
    goto v_9877;
v_9878:
    goto v_9874;
v_9875:
    goto v_9876;
v_9877:
    v_10386 = (LispObject)geq2(v_10387, v_10386);
    v_10386 = v_10386 ? lisp_true : nil;
    env = stack[-9];
    goto v_9860;
v_9862:
    v_10386 = nil;
    goto v_9860;
    v_10386 = nil;
v_9860:
    if (v_10386 == nil) goto v_9858;
    goto v_9892;
v_9888:
    v_10387 = elt(env, 33); // "NOT"
    goto v_9889;
v_9890:
    v_10386 = elt(env, 34); // "infix operator"
    goto v_9891;
v_9892:
    goto v_9888;
v_9889:
    goto v_9890;
v_9891:
    fn = elt(env, 58); // typerr
    v_10386 = (*qfn2(fn))(fn, v_10387, v_10386);
    env = stack[-9];
    goto v_9856;
v_9858:
v_9856:
    goto v_9903;
v_9899:
    v_10386 = stack[-8];
    v_10386 = qcdr(v_10386);
    v_10387 = qcar(v_10386);
    goto v_9900;
v_9901:
    v_10386 = elt(env, 26); // !*!*un!*!*
    goto v_9902;
v_9903:
    goto v_9899;
v_9900:
    goto v_9901;
v_9902:
    if (v_10387 == v_10386) goto v_9897;
    else goto v_9898;
v_9897:
    goto v_9916;
v_9912:
    v_10386 = stack[-8];
    v_10387 = qcar(v_10386);
    goto v_9913;
v_9914:
    v_10386 = elt(env, 26); // !*!*un!*!*
    goto v_9915;
v_9916:
    goto v_9912;
v_9913:
    goto v_9914;
v_9915:
    if (v_10387 == v_10386) goto v_9910;
    else goto v_9911;
v_9910:
    goto v_9038;
v_9911:
    goto v_9927;
v_9923:
    v_10386 = stack[-5];
    v_10386 = qcar(v_10386);
    v_10387 = qcdr(v_10386);
    goto v_9924;
v_9925:
    v_10386 = stack[-8];
    v_10386 = qcar(v_10386);
    goto v_9926;
v_9927:
    goto v_9923;
v_9924:
    goto v_9925;
v_9926:
    v_10386 = list2(v_10387, v_10386);
    env = stack[-9];
    stack[0] = v_10386;
    goto v_9909;
v_9909:
    goto v_9896;
v_9898:
    goto v_9940;
v_9936:
    v_10386 = stack[-5];
    v_10386 = qcar(v_10386);
    stack[0] = qcdr(v_10386);
    goto v_9937;
v_9938:
    goto v_9957;
v_9953:
    v_10386 = stack[-8];
    v_10387 = qcar(v_10386);
    goto v_9954;
v_9955:
    v_10386 = stack[-5];
    v_10386 = qcar(v_10386);
    v_10386 = qcdr(v_10386);
    goto v_9956;
v_9957:
    goto v_9953;
v_9954:
    goto v_9955;
v_9956:
    if (!consp(v_10387)) goto v_9951;
    v_10387 = qcar(v_10387);
    if (v_10387 == v_10386) goto v_9950;
    else goto v_9951;
v_9950:
    v_10386 = stack[-5];
    v_10386 = qcar(v_10386);
    v_10386 = qcdr(v_10386);
    if (!symbolp(v_10386)) v_10386 = nil;
    else { v_10386 = qfastgets(v_10386);
           if (v_10386 != nil) { v_10386 = elt(v_10386, 35); // nary
#ifdef RECORD_GET
             if (v_10386 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v_10386 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v_10386 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v_10386 == SPID_NOPROP) v_10386 = nil; else v_10386 = lisp_true; }}
#endif
    goto v_9949;
v_9951:
    v_10386 = nil;
    goto v_9949;
    v_10386 = nil;
v_9949:
    if (v_10386 == nil) goto v_9947;
    goto v_9975;
v_9971:
    v_10386 = stack[-8];
    v_10386 = qcdr(v_10386);
    v_10387 = qcar(v_10386);
    goto v_9972;
v_9973:
    v_10386 = stack[-8];
    v_10386 = qcar(v_10386);
    v_10386 = qcdr(v_10386);
    goto v_9974;
v_9975:
    goto v_9971;
v_9972:
    goto v_9973;
v_9974:
    v_10386 = cons(v_10387, v_10386);
    env = stack[-9];
    goto v_9945;
v_9947:
    goto v_9989;
v_9985:
    v_10386 = stack[-8];
    v_10386 = qcdr(v_10386);
    v_10387 = qcar(v_10386);
    goto v_9986;
v_9987:
    v_10386 = stack[-8];
    v_10386 = qcar(v_10386);
    goto v_9988;
v_9989:
    goto v_9985;
v_9986:
    goto v_9987;
v_9988:
    v_10386 = list2(v_10387, v_10386);
    env = stack[-9];
    goto v_9945;
    v_10386 = nil;
v_9945:
    goto v_9939;
v_9940:
    goto v_9936;
v_9937:
    goto v_9938;
v_9939:
    v_10386 = cons(stack[0], v_10386);
    env = stack[-9];
    stack[0] = v_10386;
    goto v_9896;
v_9896:
    v_10386 = stack[-5];
    v_10386 = qcdr(v_10386);
    stack[-5] = v_10386;
    goto v_10002;
v_9998:
    v_10387 = stack[0];
    goto v_9999;
v_10000:
    v_10386 = stack[-8];
    v_10386 = qcdr(v_10386);
    v_10386 = qcdr(v_10386);
    goto v_10001;
v_10002:
    goto v_9998;
v_9999:
    goto v_10000;
v_10001:
    v_10386 = cons(v_10387, v_10386);
    env = stack[-9];
    stack[-8] = v_10386;
    goto v_9037;
v_9040:
    goto v_10015;
v_10011:
    v_10387 = stack[-4];
    goto v_10012;
v_10013:
    v_10386 = elt(env, 35); // endstat
    goto v_10014;
v_10015:
    goto v_10011;
v_10012:
    goto v_10013;
v_10014:
    if (v_10387 == v_10386) goto v_10010;
    fn = elt(env, 54); // eolcheck
    v_10386 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    goto v_10008;
v_10010:
v_10008:
    goto v_10032;
v_10028:
    v_10387 = stack[-3];
    goto v_10029;
v_10030:
    v_10386 = elt(env, 36); // go
    goto v_10031;
v_10032:
    goto v_10028;
v_10029:
    goto v_10030;
v_10031:
    v_10386 = Lflagp(nil, v_10387, v_10386);
    env = stack[-9];
    if (v_10386 == nil) goto v_10026;
    v_10386 = lisp_true;
    goto v_10024;
v_10026:
    goto v_10046;
v_10042:
    v_10387 = stack[-7];
    goto v_10043;
v_10044:
    v_10386 = elt(env, 15); // proc
    goto v_10045;
v_10046:
    goto v_10042;
v_10043:
    goto v_10044;
v_10045:
    if (v_10387 == v_10386) goto v_10041;
    goto v_10058;
v_10054:
    v_10387 = stack[-4];
    goto v_10055;
v_10056:
    v_10386 = elt(env, 37); // endstatfn
    goto v_10057;
v_10058:
    goto v_10054;
v_10055:
    goto v_10056;
v_10057:
    v_10386 = Lflagp(nil, v_10387, v_10386);
    env = stack[-9];
    if (v_10386 == nil) goto v_10052;
    v_10386 = lisp_true;
    goto v_10050;
v_10052:
    v_10386 = qvalue(elt(env, 10)); // nxtsym!*
    fn = elt(env, 59); // delcp
    v_10386 = (*qfn1(fn))(fn, v_10386);
    env = stack[-9];
    if (v_10386 == nil) goto v_10066;
    else goto v_10067;
v_10066:
    goto v_10074;
v_10070:
    v_10387 = qvalue(elt(env, 10)); // nxtsym!*
    goto v_10071;
v_10072:
    v_10386 = elt(env, 38); // !,
    goto v_10073;
v_10074:
    goto v_10070;
v_10071:
    goto v_10072;
v_10073:
    v_10386 = (v_10387 == v_10386 ? lisp_true : nil);
    v_10386 = (v_10386 == nil ? lisp_true : nil);
    goto v_10065;
v_10067:
    v_10386 = nil;
    goto v_10065;
    v_10386 = nil;
v_10065:
    goto v_10050;
    v_10386 = nil;
v_10050:
    goto v_10039;
v_10041:
    v_10386 = nil;
    goto v_10039;
    v_10386 = nil;
v_10039:
    goto v_10024;
    v_10386 = nil;
v_10024:
    if (v_10386 == nil) goto v_10021;
    else goto v_10022;
v_10021:
    goto v_9024;
v_10022:
    goto v_10097;
v_10093:
    v_10387 = stack[-3];
    goto v_10094;
v_10095:
    v_10386 = elt(env, 39); // procedure
    goto v_10096;
v_10097:
    goto v_10093;
v_10094:
    goto v_10095;
v_10096:
    if (v_10387 == v_10386) goto v_10091;
    else goto v_10092;
v_10091:
    v_10386 = qvalue(elt(env, 6)); // !*reduce4
    goto v_10090;
v_10092:
    v_10386 = nil;
    goto v_10090;
    v_10386 = nil;
v_10090:
    if (v_10386 == nil) goto v_10088;
    v_10386 = stack[-6];
    if (v_10386 == nil) goto v_10107;
    v_10386 = stack[-6];
    v_10386 = qcdr(v_10386);
    if (v_10386 == nil) goto v_10113;
    else goto v_10111;
v_10113:
    v_10386 = qvalue(elt(env, 6)); // !*reduce4
    if (v_10386 == nil) goto v_10116;
    else goto v_10111;
v_10116:
    goto v_10112;
v_10111:
    goto v_10123;
v_10119:
    v_10387 = elt(env, 40); // "proc form"
    goto v_10120;
v_10121:
    v_10386 = nil;
    goto v_10122;
v_10123:
    goto v_10119;
v_10120:
    goto v_10121;
v_10122:
    fn = elt(env, 52); // symerr
    v_10386 = (*qfn2(fn))(fn, v_10387, v_10386);
    env = stack[-9];
    goto v_10110;
v_10112:
    v_10386 = stack[-6];
    v_10386 = qcar(v_10386);
    fn = elt(env, 60); // procstat1
    v_10386 = (*qfn1(fn))(fn, v_10386);
    env = stack[-9];
    v_10386 = ncons(v_10386);
    env = stack[-9];
    stack[-6] = v_10386;
    goto v_10110;
v_10110:
    goto v_10105;
v_10107:
    v_10386 = nil;
    fn = elt(env, 60); // procstat1
    v_10386 = (*qfn1(fn))(fn, v_10386);
    env = stack[-9];
    v_10386 = ncons(v_10386);
    env = stack[-9];
    stack[-6] = v_10386;
    goto v_10105;
v_10105:
    goto v_10086;
v_10088:
    goto v_10144;
v_10140:
    goto v_10150;
v_10146:
    v_10387 = stack[-4];
    goto v_10147;
v_10148:
    v_10386 = nil;
    goto v_10149;
v_10150:
    goto v_10146;
v_10147:
    goto v_10148;
v_10149:
    fn = elt(env, 49); // lispapply
    v_10387 = (*qfn2(fn))(fn, v_10387, v_10386);
    env = stack[-9];
    goto v_10141;
v_10142:
    v_10386 = stack[-6];
    goto v_10143;
v_10144:
    goto v_10140;
v_10141:
    goto v_10142;
v_10143:
    v_10386 = cons(v_10387, v_10386);
    env = stack[-9];
    stack[-6] = v_10386;
    goto v_10086;
v_10086:
    v_10386 = nil;
    stack[-4] = v_10386;
    goto v_9022;
v_9041:
    goto v_10163;
v_10159:
    v_10387 = qvalue(elt(env, 3)); // cursym!*
    goto v_10160;
v_10161:
    v_10386 = elt(env, 41); // !*semicol!*
    goto v_10162;
v_10163:
    goto v_10159;
v_10160:
    goto v_10161;
v_10162:
    if (v_10387 == v_10386) goto v_10158;
    fn = elt(env, 54); // eolcheck
    v_10386 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    goto v_10156;
v_10158:
v_10156:
    goto v_10180;
v_10176:
    v_10387 = stack[-3];
    goto v_10177;
v_10178:
    v_10386 = elt(env, 42); // !*colon!*
    goto v_10179;
v_10180:
    goto v_10176;
v_10177:
    goto v_10178;
v_10179:
    if (v_10387 == v_10386) goto v_10174;
    else goto v_10175;
v_10174:
    goto v_10191;
v_10187:
    v_10387 = stack[-7];
    goto v_10188;
v_10189:
    v_10386 = elt(env, 43); // for
    goto v_10190;
v_10191:
    goto v_10187;
v_10188:
    goto v_10189;
v_10190:
    if (v_10387 == v_10386) goto v_10186;
    v_10386 = qvalue(elt(env, 44)); // !*blockp
    if (v_10386 == nil) goto v_10196;
    else goto v_10197;
v_10196:
    v_10386 = lisp_true;
    goto v_10195;
v_10197:
    v_10386 = stack[-6];
    if (v_10386 == nil) goto v_10204;
    else goto v_10205;
v_10204:
    v_10386 = lisp_true;
    goto v_10203;
v_10205:
    v_10386 = stack[-6];
    v_10386 = qcar(v_10386);
    if (!consp(v_10386)) goto v_10213;
    v_10386 = lisp_true;
    goto v_10211;
v_10213:
    v_10386 = stack[-6];
    v_10386 = qcdr(v_10386);
    goto v_10211;
    v_10386 = nil;
v_10211:
    goto v_10203;
    v_10386 = nil;
v_10203:
    goto v_10195;
    v_10386 = nil;
v_10195:
    goto v_10184;
v_10186:
    v_10386 = nil;
    goto v_10184;
    v_10386 = nil;
v_10184:
    goto v_10173;
v_10175:
    v_10386 = nil;
    goto v_10173;
    v_10386 = nil;
v_10173:
    if (v_10386 == nil) goto v_10171;
    else goto v_10169;
v_10171:
    goto v_10237;
v_10233:
    v_10387 = stack[-3];
    goto v_10234;
v_10235:
    v_10386 = elt(env, 45); // nodel
    goto v_10236;
v_10237:
    goto v_10233;
v_10234:
    goto v_10235;
v_10236:
    v_10386 = Lflagp(nil, v_10387, v_10386);
    env = stack[-9];
    if (v_10386 == nil) goto v_10231;
    v_10386 = stack[-7];
    if (v_10386 == nil) goto v_10242;
    else goto v_10243;
v_10242:
    v_10386 = lisp_true;
    goto v_10241;
v_10243:
    goto v_10256;
v_10252:
    v_10387 = stack[-7];
    goto v_10253;
v_10254:
    v_10386 = elt(env, 22); // group
    goto v_10255;
v_10256:
    goto v_10252;
v_10253:
    goto v_10254;
v_10255:
    if (v_10387 == v_10386) goto v_10250;
    else goto v_10251;
v_10250:
    goto v_10263;
v_10259:
    v_10387 = stack[-3];
    goto v_10260;
v_10261:
    v_10386 = elt(env, 46); // (!*rsqbkt!* !*rcbkt!* !*rsqb!*)
    goto v_10262;
v_10263:
    goto v_10259;
v_10260:
    goto v_10261;
v_10262:
    v_10386 = Lmemq(nil, v_10387, v_10386);
    v_10386 = (v_10386 == nil ? lisp_true : nil);
    goto v_10249;
v_10251:
    v_10386 = nil;
    goto v_10249;
    v_10386 = nil;
v_10249:
    goto v_10241;
    v_10386 = nil;
v_10241:
    goto v_10229;
v_10231:
    v_10386 = nil;
    goto v_10229;
    v_10386 = nil;
v_10229:
    if (v_10386 == nil) goto v_10227;
    else goto v_10169;
v_10227:
    goto v_10170;
v_10169:
    goto v_10279;
v_10275:
    v_10387 = elt(env, 21); // "Improper delimiter"
    goto v_10276;
v_10277:
    v_10386 = nil;
    goto v_10278;
v_10279:
    goto v_10275;
v_10276:
    goto v_10277;
v_10278:
    fn = elt(env, 52); // symerr
    v_10386 = (*qfn2(fn))(fn, v_10387, v_10386);
    env = stack[-9];
    goto v_10168;
v_10170:
    v_10386 = stack[-7];
    if (symbolp(v_10386)) goto v_10284;
    else goto v_10283;
v_10284:
    goto v_10295;
v_10291:
    v_10387 = stack[-7];
    goto v_10292;
v_10293:
    v_10386 = elt(env, 18); // paren
    goto v_10294;
v_10295:
    goto v_10291;
v_10292:
    goto v_10293;
v_10294:
    if (v_10387 == v_10386) goto v_10289;
    else goto v_10290;
v_10289:
    v_10386 = lisp_true;
    goto v_10288;
v_10290:
    goto v_10306;
v_10302:
    v_10387 = stack[-7];
    goto v_10303;
v_10304:
    v_10386 = elt(env, 17); // struct
    goto v_10305;
v_10306:
    goto v_10302;
v_10303:
    goto v_10304;
v_10305:
    v_10386 = Lflagp(nil, v_10387, v_10386);
    env = stack[-9];
    goto v_10288;
    v_10386 = nil;
v_10288:
    if (v_10386 == nil) goto v_10283;
    goto v_10314;
v_10310:
    v_10387 = elt(env, 47); // "Too few right parentheses"
    goto v_10311;
v_10312:
    v_10386 = nil;
    goto v_10313;
v_10314:
    goto v_10310;
v_10311:
    goto v_10312;
v_10313:
    fn = elt(env, 52); // symerr
    v_10386 = (*qfn2(fn))(fn, v_10387, v_10386);
    env = stack[-9];
    goto v_10168;
v_10283:
v_10168:
v_9042:
    v_10386 = stack[-4];
    if (v_10386 == nil) goto v_10320;
    goto v_10327;
v_10323:
    v_10387 = elt(env, 21); // "Improper delimiter"
    goto v_10324;
v_10325:
    v_10386 = nil;
    goto v_10326;
v_10327:
    goto v_10323;
v_10324:
    goto v_10325;
v_10326:
    fn = elt(env, 52); // symerr
    v_10386 = (*qfn2(fn))(fn, v_10387, v_10386);
    env = stack[-9];
    goto v_10318;
v_10320:
    v_10386 = stack[-8];
    if (v_10386 == nil) goto v_10334;
    else goto v_10335;
v_10334:
    v_10386 = stack[-6];
    if (v_10386 == nil) goto v_10339;
    else goto v_10340;
v_10339:
    v_10386 = stack[-5];
    v_10386 = (v_10386 == nil ? lisp_true : nil);
    goto v_10338;
v_10340:
    v_10386 = nil;
    goto v_10338;
    v_10386 = nil;
v_10338:
    goto v_10333;
v_10335:
    v_10386 = nil;
    goto v_10333;
    v_10386 = nil;
v_10333:
    if (v_10386 == nil) goto v_10331;
    goto v_10355;
v_10351:
    v_10387 = nil;
    goto v_10352;
v_10353:
    v_10386 = stack[-1];
    goto v_10354;
v_10355:
    goto v_10351;
v_10352:
    goto v_10353;
v_10354:
    {
        fn = elt(env, 61); // xcomment
        return (*qfn2(fn))(fn, v_10387, v_10386);
    }
v_10331:
v_10318:
    v_10386 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_10386;
    goto v_9034;
v_9043:
    v_10386 = stack[-8];
    v_10386 = qcdr(v_10386);
    if (v_10386 == nil) goto v_10361;
    else goto v_10362;
v_10361:
    goto v_10370;
v_10366:
    v_10386 = stack[-8];
    v_10387 = qcar(v_10386);
    goto v_10367;
v_10368:
    v_10386 = stack[-1];
    goto v_10369;
v_10370:
    goto v_10366;
v_10367:
    goto v_10368;
v_10369:
    {
        fn = elt(env, 61); // xcomment
        return (*qfn2(fn))(fn, v_10387, v_10386);
    }
v_10362:
    v_10386 = elt(env, 48); // "Please send hearn@rand.org your program!!"
    v_10386 = Lprint(nil, v_10386);
    env = stack[-9];
    goto v_10360;
v_10360:
    goto v_10383;
v_10379:
    v_10387 = elt(env, 21); // "Improper delimiter"
    goto v_10380;
v_10381:
    v_10386 = nil;
    goto v_10382;
v_10383:
    goto v_10379;
v_10380:
    goto v_10381;
v_10382:
    fn = elt(env, 52); // symerr
    v_10386 = (*qfn2(fn))(fn, v_10387, v_10386);
    v_10386 = nil;
    return onevalue(v_10386);
}



// Code for invbf

static LispObject CC_invbf(LispObject env,
                         LispObject v_9010)
{
    env = qenv(env);
    LispObject v_9024, v_9025, v_9026;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9010);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_9024 = v_9010;
// end of prologue
    goto v_9020;
v_9014:
    v_9026 = qvalue(elt(env, 1)); // bfone!*
    goto v_9015;
v_9016:
    v_9025 = v_9024;
    goto v_9017;
v_9018:
    v_9024 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_9019;
v_9020:
    goto v_9014;
v_9015:
    goto v_9016;
v_9017:
    goto v_9018;
v_9019:
    fn = elt(env, 3); // divide!:
    v_9024 = (*qfnn(fn))(fn, 3, v_9026, v_9025, v_9024);
    env = stack[0];
    {
        fn = elt(env, 4); // normbf
        return (*qfn1(fn))(fn, v_9024);
    }
}



// Code for degree!-in!-variable

static LispObject CC_degreeKinKvariable(LispObject env,
                         LispObject v_9010, LispObject v_9011)
{
    env = qenv(env);
    LispObject v_9085, v_9086;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9011,v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9010,v_9011);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_9011;
    stack[-1] = v_9010;
// end of prologue
    v_9085 = stack[-1];
    if (!consp(v_9085)) goto v_9019;
    else goto v_9020;
v_9019:
    v_9085 = lisp_true;
    goto v_9018;
v_9020:
    v_9085 = stack[-1];
    v_9085 = qcar(v_9085);
    v_9085 = (consp(v_9085) ? nil : lisp_true);
    goto v_9018;
    v_9085 = nil;
v_9018:
    if (v_9085 == nil) goto v_9016;
    v_9085 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9014;
v_9016:
    goto v_9035;
v_9031:
    v_9085 = stack[-1];
    v_9085 = qcar(v_9085);
    v_9086 = qcdr(v_9085);
    goto v_9032;
v_9033:
    v_9085 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9034;
v_9035:
    goto v_9031;
v_9032:
    goto v_9033;
v_9034:
    if (v_9086 == v_9085) goto v_9029;
    else goto v_9030;
v_9029:
    v_9085 = elt(env, 1); // "Polynomial with a zero coefficient found"
    {
        fn = elt(env, 2); // errorf
        return (*qfn1(fn))(fn, v_9085);
    }
v_9030:
    goto v_9048;
v_9044:
    v_9086 = stack[0];
    goto v_9045;
v_9046:
    v_9085 = stack[-1];
    v_9085 = qcar(v_9085);
    v_9085 = qcar(v_9085);
    v_9085 = qcar(v_9085);
    goto v_9047;
v_9048:
    goto v_9044;
v_9045:
    goto v_9046;
v_9047:
    if (equal(v_9086, v_9085)) goto v_9042;
    else goto v_9043;
v_9042:
    v_9085 = stack[-1];
    v_9085 = qcar(v_9085);
    v_9085 = qcar(v_9085);
    v_9085 = qcdr(v_9085);
    goto v_9014;
v_9043:
    goto v_9065;
v_9061:
    goto v_9071;
v_9067:
    v_9085 = stack[-1];
    v_9085 = qcar(v_9085);
    v_9086 = qcdr(v_9085);
    goto v_9068;
v_9069:
    v_9085 = stack[0];
    goto v_9070;
v_9071:
    goto v_9067;
v_9068:
    goto v_9069;
v_9070:
    stack[-2] = CC_degreeKinKvariable(elt(env, 0), v_9086, v_9085);
    env = stack[-3];
    goto v_9062;
v_9063:
    goto v_9081;
v_9077:
    v_9085 = stack[-1];
    v_9086 = qcdr(v_9085);
    goto v_9078;
v_9079:
    v_9085 = stack[0];
    goto v_9080;
v_9081:
    goto v_9077;
v_9078:
    goto v_9079;
v_9080:
    v_9085 = CC_degreeKinKvariable(elt(env, 0), v_9086, v_9085);
    env = stack[-3];
    goto v_9064;
v_9065:
    goto v_9061;
v_9062:
    goto v_9063;
v_9064:
    {
        LispObject v_9090 = stack[-2];
        fn = elt(env, 3); // max
        return (*qfn2(fn))(fn, v_9090, v_9085);
    }
    v_9085 = nil;
v_9014:
    return onevalue(v_9085);
}



// Code for ra_refine1

static LispObject CC_ra_refine1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_9114, v_9115, v_9116;
    LispObject fn;
    LispObject v_9013, v_9012, v_9011, v_9010;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ra_refine1");
    va_start(aa, nargs);
    v_9010 = va_arg(aa, LispObject);
    v_9011 = va_arg(aa, LispObject);
    v_9012 = va_arg(aa, LispObject);
    v_9013 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_9013,v_9012,v_9011,v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_9010,v_9011,v_9012,v_9013);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-2] = v_9013;
    stack[-3] = v_9012;
    stack[-4] = v_9011;
    stack[-5] = v_9010;
// end of prologue
    v_9114 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_9114;
v_9022:
    goto v_9034;
v_9030:
    v_9115 = stack[-2];
    goto v_9031;
v_9032:
    v_9114 = stack[-1];
    goto v_9033;
v_9034:
    goto v_9030;
v_9031:
    goto v_9032;
v_9033:
    v_9114 = difference2(v_9115, v_9114);
    env = stack[-7];
    v_9114 = Lminusp(nil, v_9114);
    env = stack[-7];
    if (v_9114 == nil) goto v_9027;
    goto v_9021;
v_9027:
    goto v_9043;
v_9039:
    v_9115 = stack[-4];
    goto v_9040;
v_9041:
    v_9114 = stack[-3];
    goto v_9042;
v_9043:
    goto v_9039;
v_9040:
    goto v_9041;
v_9042:
    fn = elt(env, 3); // sfto_avgq
    v_9114 = (*qfn2(fn))(fn, v_9115, v_9114);
    env = stack[-7];
    stack[-6] = v_9114;
    goto v_9055;
v_9051:
    stack[0] = stack[-5];
    goto v_9052;
v_9053:
    goto v_9063;
v_9059:
    v_9115 = elt(env, 2); // x
    goto v_9060;
v_9061:
    v_9114 = stack[-6];
    goto v_9062;
v_9063:
    goto v_9059;
v_9060:
    goto v_9061;
v_9062:
    v_9114 = cons(v_9115, v_9114);
    env = stack[-7];
    v_9114 = ncons(v_9114);
    env = stack[-7];
    goto v_9054;
v_9055:
    goto v_9051;
v_9052:
    goto v_9053;
v_9054:
    fn = elt(env, 4); // sfto_qsub1
    v_9114 = (*qfn2(fn))(fn, stack[0], v_9114);
    env = stack[-7];
    v_9114 = qcar(v_9114);
    if (v_9114 == nil) goto v_9048;
    else goto v_9049;
v_9048:
    goto v_9072;
v_9068:
    v_9115 = stack[-4];
    goto v_9069;
v_9070:
    v_9114 = stack[-6];
    goto v_9071;
v_9072:
    goto v_9068;
v_9069:
    goto v_9070;
v_9071:
    fn = elt(env, 3); // sfto_avgq
    v_9114 = (*qfn2(fn))(fn, v_9115, v_9114);
    env = stack[-7];
    stack[-4] = v_9114;
    goto v_9047;
v_9049:
    goto v_9082;
v_9078:
    goto v_9090;
v_9084:
    v_9116 = stack[-5];
    goto v_9085;
v_9086:
    v_9115 = stack[-4];
    goto v_9087;
v_9088:
    v_9114 = stack[-6];
    goto v_9089;
v_9090:
    goto v_9084;
v_9085:
    goto v_9086;
v_9087:
    goto v_9088;
v_9089:
    fn = elt(env, 5); // ra_budancount
    v_9115 = (*qfnn(fn))(fn, 3, v_9116, v_9115, v_9114);
    env = stack[-7];
    goto v_9079;
v_9080:
    v_9114 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9081;
v_9082:
    goto v_9078;
v_9079:
    goto v_9080;
v_9081:
    v_9114 = Leqn(nil, v_9115, v_9114);
    env = stack[-7];
    if (v_9114 == nil) goto v_9076;
    v_9114 = stack[-6];
    stack[-3] = v_9114;
    goto v_9047;
v_9076:
    goto v_9101;
    goto v_9099;
v_9101:
v_9099:
    v_9114 = stack[-6];
    stack[-4] = v_9114;
    goto v_9047;
v_9047:
    v_9114 = stack[-1];
    v_9114 = add1(v_9114);
    env = stack[-7];
    stack[-1] = v_9114;
    goto v_9022;
v_9021:
    goto v_9111;
v_9107:
    v_9115 = stack[-4];
    goto v_9108;
v_9109:
    v_9114 = stack[-3];
    goto v_9110;
v_9111:
    goto v_9107;
v_9108:
    goto v_9109;
v_9110:
    return cons(v_9115, v_9114);
    return onevalue(v_9114);
}



// Code for get_action

static LispObject CC_get_action(LispObject env,
                         LispObject v_9010, LispObject v_9011)
{
    env = qenv(env);
    LispObject v_9062, v_9063, v_9064, v_9065, v_9066;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9065 = v_9011;
    v_9062 = v_9010;
// end of prologue
    goto v_9023;
v_9019:
    v_9063 = qvalue(elt(env, 2)); // parser_action_table
    goto v_9020;
v_9021:
    goto v_9022;
v_9023:
    goto v_9019;
v_9020:
    goto v_9021;
v_9022:
    v_9062 = *(LispObject *)((char *)v_9063 + (CELL-TAG_VECTOR) + (((intptr_t)v_9062-TAG_FIXNUM)/(16/CELL)));
    v_9063 = v_9062;
    v_9063 = qcar(v_9063);
    v_9066 = v_9063;
    v_9062 = qcdr(v_9062);
    v_9064 = v_9062;
v_9033:
    v_9062 = v_9066;
    if (v_9062 == nil) goto v_9036;
    else goto v_9037;
v_9036:
    goto v_9032;
v_9037:
    goto v_9048;
v_9044:
    v_9062 = v_9066;
    v_9062 = qcar(v_9062);
    v_9063 = qcar(v_9062);
    goto v_9045;
v_9046:
    v_9062 = v_9065;
    goto v_9047;
v_9048:
    goto v_9044;
v_9045:
    goto v_9046;
v_9047:
    if (equal(v_9063, v_9062)) goto v_9042;
    else goto v_9043;
v_9042:
    v_9062 = v_9066;
    v_9062 = qcar(v_9062);
    v_9062 = qcdr(v_9062);
    v_9064 = v_9062;
    v_9062 = nil;
    v_9066 = v_9062;
    goto v_9041;
v_9043:
    v_9062 = v_9066;
    v_9062 = qcdr(v_9062);
    v_9066 = v_9062;
    goto v_9041;
v_9041:
    goto v_9033;
v_9032:
    v_9062 = v_9064;
    return onevalue(v_9062);
}



// Code for ctx_filter

static LispObject CC_ctx_filter(LispObject env,
                         LispObject v_9010, LispObject v_9011)
{
    env = qenv(env);
    LispObject v_9097, v_9098, v_9099;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9011,v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9010,v_9011);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_9097 = v_9011;
    stack[-4] = v_9010;
// end of prologue
    goto v_9018;
v_9014:
    stack[-5] = elt(env, 1); // ctx
    goto v_9015;
v_9016:
    fn = elt(env, 2); // ctx_ial
    v_9097 = (*qfn1(fn))(fn, v_9097);
    env = stack[-6];
    stack[-3] = v_9097;
v_9025:
    v_9097 = stack[-3];
    if (v_9097 == nil) goto v_9031;
    else goto v_9032;
v_9031:
    v_9097 = nil;
    goto v_9024;
v_9032:
    v_9097 = stack[-3];
    v_9097 = qcar(v_9097);
    v_9099 = v_9097;
    goto v_9046;
v_9042:
    v_9097 = v_9099;
    v_9098 = qcar(v_9097);
    goto v_9043;
v_9044:
    v_9097 = stack[-4];
    goto v_9045;
v_9046:
    goto v_9042;
v_9043:
    goto v_9044;
v_9045:
    v_9097 = Lmemq(nil, v_9098, v_9097);
    if (v_9097 == nil) goto v_9041;
    v_9097 = v_9099;
    v_9097 = ncons(v_9097);
    env = stack[-6];
    goto v_9039;
v_9041:
    v_9097 = nil;
v_9039:
    stack[-2] = v_9097;
    v_9097 = stack[-2];
    fn = elt(env, 3); // lastpair
    v_9097 = (*qfn1(fn))(fn, v_9097);
    env = stack[-6];
    stack[-1] = v_9097;
    v_9097 = stack[-3];
    v_9097 = qcdr(v_9097);
    stack[-3] = v_9097;
    v_9097 = stack[-1];
    if (!consp(v_9097)) goto v_9059;
    else goto v_9060;
v_9059:
    goto v_9025;
v_9060:
v_9026:
    v_9097 = stack[-3];
    if (v_9097 == nil) goto v_9064;
    else goto v_9065;
v_9064:
    v_9097 = stack[-2];
    goto v_9024;
v_9065:
    goto v_9073;
v_9069:
    stack[0] = stack[-1];
    goto v_9070;
v_9071:
    v_9097 = stack[-3];
    v_9097 = qcar(v_9097);
    v_9099 = v_9097;
    goto v_9086;
v_9082:
    v_9097 = v_9099;
    v_9098 = qcar(v_9097);
    goto v_9083;
v_9084:
    v_9097 = stack[-4];
    goto v_9085;
v_9086:
    goto v_9082;
v_9083:
    goto v_9084;
v_9085:
    v_9097 = Lmemq(nil, v_9098, v_9097);
    if (v_9097 == nil) goto v_9081;
    v_9097 = v_9099;
    v_9097 = ncons(v_9097);
    env = stack[-6];
    goto v_9079;
v_9081:
    v_9097 = nil;
v_9079:
    goto v_9072;
v_9073:
    goto v_9069;
v_9070:
    goto v_9071;
v_9072:
    v_9097 = Lrplacd(nil, stack[0], v_9097);
    env = stack[-6];
    v_9097 = stack[-1];
    fn = elt(env, 3); // lastpair
    v_9097 = (*qfn1(fn))(fn, v_9097);
    env = stack[-6];
    stack[-1] = v_9097;
    v_9097 = stack[-3];
    v_9097 = qcdr(v_9097);
    stack[-3] = v_9097;
    goto v_9026;
v_9024:
    goto v_9017;
v_9018:
    goto v_9014;
v_9015:
    goto v_9016;
v_9017:
    {
        LispObject v_9106 = stack[-5];
        return list2(v_9106, v_9097);
    }
}



// Code for rl_bestgaussp

static LispObject CC_rl_bestgaussp(LispObject env,
                         LispObject v_9010)
{
    env = qenv(env);
    LispObject v_9021;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9010);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_9021 = v_9010;
// end of prologue
    goto v_9017;
v_9013:
    stack[0] = qvalue(elt(env, 1)); // rl_bestgaussp!*
    goto v_9014;
v_9015:
    v_9021 = ncons(v_9021);
    env = stack[-1];
    goto v_9016;
v_9017:
    goto v_9013;
v_9014:
    goto v_9015;
v_9016:
    {
        LispObject v_9023 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_9023, v_9021);
    }
}



// Code for mkkl

static LispObject CC_mkkl(LispObject env,
                         LispObject v_9010, LispObject v_9011)
{
    env = qenv(env);
    LispObject v_9038, v_9039, v_9040;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9011,v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9010,v_9011);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_9038 = v_9011;
    v_9039 = v_9010;
// end of prologue
v_9016:
    v_9040 = v_9039;
    if (v_9040 == nil) goto v_9019;
    else goto v_9020;
v_9019:
    goto v_9015;
v_9020:
    v_9040 = v_9039;
    v_9040 = qcdr(v_9040);
    stack[0] = v_9040;
    goto v_9033;
v_9029:
    v_9039 = qcar(v_9039);
    goto v_9030;
v_9031:
    goto v_9032;
v_9033:
    goto v_9029;
v_9030:
    goto v_9031;
v_9032:
    v_9038 = cons(v_9039, v_9038);
    env = stack[-1];
    v_9038 = ncons(v_9038);
    env = stack[-1];
    v_9039 = stack[0];
    goto v_9016;
    v_9038 = nil;
v_9015:
    return onevalue(v_9038);
}



// Code for exptcompare

static LispObject CC_exptcompare(LispObject env,
                         LispObject v_9010, LispObject v_9011)
{
    env = qenv(env);
    LispObject v_9050, v_9051, v_9052;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9050 = v_9011;
    v_9051 = v_9010;
// end of prologue
    v_9052 = v_9051;
    if (!consp(v_9052)) goto v_9015;
    else goto v_9016;
v_9015:
    v_9052 = v_9050;
    if (!consp(v_9052)) goto v_9020;
    else goto v_9021;
v_9020:
    goto v_9028;
v_9024:
    goto v_9025;
v_9026:
    goto v_9027;
v_9028:
    goto v_9024;
v_9025:
    goto v_9026;
v_9027:
        return Lgreaterp(nil, v_9051, v_9050);
v_9021:
    v_9050 = nil;
    goto v_9019;
    v_9050 = nil;
v_9019:
    goto v_9014;
v_9016:
    v_9052 = v_9050;
    if (!consp(v_9052)) goto v_9034;
    else goto v_9035;
v_9034:
    v_9050 = lisp_true;
    goto v_9014;
v_9035:
    goto v_9045;
v_9041:
    v_9051 = qcar(v_9051);
    goto v_9042;
v_9043:
    v_9050 = qcar(v_9050);
    goto v_9044;
v_9045:
    goto v_9041;
v_9042:
    goto v_9043;
v_9044:
        return Lgreaterp(nil, v_9051, v_9050);
    v_9050 = nil;
v_9014:
    return onevalue(v_9050);
}



// Code for qqe_number!-of!-adds!-in!-qterm

static LispObject CC_qqe_numberKofKaddsKinKqterm(LispObject env,
                         LispObject v_9010)
{
    env = qenv(env);
    LispObject v_9040, v_9041;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9010);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_9010;
// end of prologue
v_9014:
    v_9040 = stack[0];
    if (!consp(v_9040)) goto v_9017;
    else goto v_9018;
v_9017:
    v_9040 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9013;
v_9018:
    goto v_9027;
v_9023:
    v_9040 = stack[0];
    fn = elt(env, 2); // qqe_op
    v_9041 = (*qfn1(fn))(fn, v_9040);
    env = stack[-1];
    goto v_9024;
v_9025:
    v_9040 = elt(env, 1); // (ladd radd)
    goto v_9026;
v_9027:
    goto v_9023;
v_9024:
    goto v_9025;
v_9026:
    v_9040 = Lmemq(nil, v_9041, v_9040);
    if (v_9040 == nil) goto v_9022;
    v_9040 = stack[0];
    fn = elt(env, 3); // qqe_arg2r
    v_9040 = (*qfn1(fn))(fn, v_9040);
    env = stack[-1];
    v_9040 = CC_qqe_numberKofKaddsKinKqterm(elt(env, 0), v_9040);
    return add1(v_9040);
v_9022:
    v_9040 = stack[0];
    fn = elt(env, 4); // qqe_arg2l
    v_9040 = (*qfn1(fn))(fn, v_9040);
    env = stack[-1];
    stack[0] = v_9040;
    goto v_9014;
    v_9040 = nil;
v_9013:
    return onevalue(v_9040);
}



// Code for sf2ss

static LispObject CC_sf2ss(LispObject env,
                         LispObject v_9010)
{
    env = qenv(env);
    LispObject v_9064, v_9065;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9010);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_9010;
// end of prologue
    v_9064 = stack[-1];
    if (!consp(v_9064)) goto v_9023;
    else goto v_9024;
v_9023:
    v_9064 = lisp_true;
    goto v_9022;
v_9024:
    v_9064 = stack[-1];
    v_9064 = qcar(v_9064);
    v_9064 = (consp(v_9064) ? nil : lisp_true);
    goto v_9022;
    v_9064 = nil;
v_9022:
    if (v_9064 == nil) goto v_9020;
    v_9064 = stack[-1];
    goto v_9015;
v_9020:
    v_9064 = stack[-1];
    fn = elt(env, 2); // searchpl
    v_9064 = (*qfn1(fn))(fn, v_9064);
    env = stack[-3];
    stack[-2] = v_9064;
    goto v_9040;
v_9036:
    v_9064 = stack[-2];
    fn = elt(env, 3); // qsort
    stack[0] = (*qfn1(fn))(fn, v_9064);
    env = stack[-3];
    goto v_9037;
v_9038:
    v_9064 = stack[-2];
    v_9064 = Llength(nil, v_9064);
    env = stack[-3];
    goto v_9039;
v_9040:
    goto v_9036;
v_9037:
    goto v_9038;
v_9039:
    v_9064 = cons(stack[0], v_9064);
    env = stack[-3];
    goto v_9053;
v_9047:
    stack[0] = v_9064;
    goto v_9048;
v_9049:
    goto v_9060;
v_9056:
    v_9065 = stack[-1];
    goto v_9057;
v_9058:
    goto v_9059;
v_9060:
    goto v_9056;
v_9057:
    goto v_9058;
v_9059:
    fn = elt(env, 4); // sq2sspl
    v_9065 = (*qfn2(fn))(fn, v_9065, v_9064);
    env = stack[-3];
    goto v_9050;
v_9051:
    v_9064 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9052;
v_9053:
    goto v_9047;
v_9048:
    goto v_9049;
v_9050:
    goto v_9051;
v_9052:
    v_9064 = list2star(stack[0], v_9065, v_9064);
    env = stack[-3];
    {
        fn = elt(env, 5); // lx2xx
        return (*qfn1(fn))(fn, v_9064);
    }
v_9015:
    return onevalue(v_9064);
}



// Code for constsml

static LispObject CC_constsml(LispObject env,
                         LispObject v_9010)
{
    env = qenv(env);
    LispObject v_9095, v_9096;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9010);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_9010;
// end of prologue
    v_9095 = stack[0];
    if (is_number(v_9095)) goto v_9017;
    else goto v_9018;
v_9017:
    v_9095 = elt(env, 1); // "<cn"
    fn = elt(env, 12); // printout
    v_9095 = (*qfn1(fn))(fn, v_9095);
    env = stack[-1];
    v_9095 = stack[0];
    v_9095 = Lfloatp(nil, v_9095);
    env = stack[-1];
    if (v_9095 == nil) goto v_9025;
    v_9095 = elt(env, 2); // " type=""real""> "
    v_9095 = Lprinc(nil, v_9095);
    env = stack[-1];
    goto v_9023;
v_9025:
    v_9095 = stack[0];
    v_9095 = integerp(v_9095);
    if (v_9095 == nil) goto v_9031;
    v_9095 = elt(env, 3); // " type=""integer""> "
    v_9095 = Lprinc(nil, v_9095);
    env = stack[-1];
    goto v_9023;
v_9031:
    v_9095 = elt(env, 4); // "> "
    v_9095 = Lprinc(nil, v_9095);
    env = stack[-1];
    goto v_9023;
v_9023:
    v_9095 = stack[0];
    v_9095 = Lprinc(nil, v_9095);
    env = stack[-1];
    v_9095 = elt(env, 5); // " </cn>"
    v_9095 = Lprinc(nil, v_9095);
    env = stack[-1];
    goto v_9016;
v_9018:
v_9016:
    v_9095 = stack[0];
    if (symbolp(v_9095)) goto v_9046;
    else goto v_9047;
v_9046:
    goto v_9057;
v_9053:
    v_9095 = stack[0];
    v_9096 = Lintern(nil, v_9095);
    env = stack[-1];
    goto v_9054;
v_9055:
    v_9095 = qvalue(elt(env, 6)); // constants!*
    goto v_9056;
v_9057:
    goto v_9053;
v_9054:
    goto v_9055;
v_9056:
    v_9095 = Lmember(nil, v_9096, v_9095);
    if (v_9095 == nil) goto v_9052;
    v_9095 = elt(env, 7); // "<cn type=""constant""> "
    fn = elt(env, 12); // printout
    v_9095 = (*qfn1(fn))(fn, v_9095);
    env = stack[-1];
    v_9095 = stack[0];
    v_9095 = Lprinc(nil, v_9095);
    env = stack[-1];
    v_9095 = elt(env, 5); // " </cn>"
    v_9095 = Lprinc(nil, v_9095);
    goto v_9050;
v_9052:
    v_9095 = elt(env, 8); // "<ci"
    fn = elt(env, 12); // printout
    v_9095 = (*qfn1(fn))(fn, v_9095);
    env = stack[-1];
    v_9095 = stack[0];
    fn = elt(env, 13); // listp
    v_9095 = (*qfn1(fn))(fn, v_9095);
    env = stack[-1];
    if (v_9095 == nil) goto v_9075;
    v_9095 = elt(env, 9); // " type=""list""> "
    v_9095 = Lprinc(nil, v_9095);
    env = stack[-1];
    goto v_9073;
v_9075:
    v_9095 = stack[0];
    v_9095 = Lsimple_vectorp(nil, v_9095);
    env = stack[-1];
    if (v_9095 == nil) goto v_9081;
    v_9095 = elt(env, 10); // " type=""vector""> "
    v_9095 = Lprinc(nil, v_9095);
    env = stack[-1];
    goto v_9073;
v_9081:
    v_9095 = elt(env, 4); // "> "
    v_9095 = Lprinc(nil, v_9095);
    env = stack[-1];
    goto v_9073;
v_9073:
    v_9095 = stack[0];
    v_9095 = Lprinc(nil, v_9095);
    env = stack[-1];
    v_9095 = elt(env, 11); // " </ci>"
    v_9095 = Lprinc(nil, v_9095);
    goto v_9050;
v_9050:
    goto v_9045;
v_9047:
v_9045:
    v_9095 = nil;
    return onevalue(v_9095);
}



// Code for unchecked_getmatelem

static LispObject CC_unchecked_getmatelem(LispObject env,
                         LispObject v_9010)
{
    env = qenv(env);
    LispObject v_9074, v_9075, v_9076;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9010);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_9010;
// end of prologue
    goto v_9025;
v_9021:
    v_9074 = stack[-1];
    v_9075 = qcar(v_9074);
    v_9076 = v_9075;
    goto v_9022;
v_9023:
    v_9074 = elt(env, 2); // mat
    goto v_9024;
v_9025:
    goto v_9021;
v_9022:
    goto v_9023;
v_9024:
    if (!consp(v_9075)) goto v_9018;
    v_9075 = qcar(v_9075);
    if (v_9075 == v_9074) goto v_9019;
v_9018:
    goto v_9036;
v_9030:
    stack[-2] = elt(env, 3); // matrix
    goto v_9031;
v_9032:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9033;
v_9034:
    goto v_9046;
v_9040:
    v_9076 = elt(env, 4); // "Matrix"
    goto v_9041;
v_9042:
    v_9074 = stack[-1];
    v_9075 = qcar(v_9074);
    goto v_9043;
v_9044:
    v_9074 = elt(env, 5); // "not set"
    goto v_9045;
v_9046:
    goto v_9040;
v_9041:
    goto v_9042;
v_9043:
    goto v_9044;
v_9045:
    v_9074 = list3(v_9076, v_9075, v_9074);
    env = stack[-3];
    goto v_9035;
v_9036:
    goto v_9030;
v_9031:
    goto v_9032;
v_9033:
    goto v_9034;
v_9035:
    fn = elt(env, 6); // rerror
    v_9074 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_9074);
    goto v_9017;
v_9019:
    goto v_9058;
v_9054:
    goto v_9064;
v_9060:
    v_9074 = v_9076;
    v_9075 = qcdr(v_9074);
    goto v_9061;
v_9062:
    v_9074 = stack[-1];
    v_9074 = qcdr(v_9074);
    v_9074 = qcar(v_9074);
    goto v_9063;
v_9064:
    goto v_9060;
v_9061:
    goto v_9062;
v_9063:
    fn = elt(env, 7); // nth
    v_9075 = (*qfn2(fn))(fn, v_9075, v_9074);
    env = stack[-3];
    goto v_9055;
v_9056:
    v_9074 = stack[-1];
    v_9074 = qcdr(v_9074);
    v_9074 = qcdr(v_9074);
    v_9074 = qcar(v_9074);
    goto v_9057;
v_9058:
    goto v_9054;
v_9055:
    goto v_9056;
v_9057:
    {
        fn = elt(env, 7); // nth
        return (*qfn2(fn))(fn, v_9075, v_9074);
    }
v_9017:
    v_9074 = nil;
    return onevalue(v_9074);
}



// Code for guesspftype

static LispObject CC_guesspftype(LispObject env,
                         LispObject v_9010)
{
    env = qenv(env);
    LispObject v_9054, v_9055;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9010);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_9010;
// end of prologue
    v_9054 = stack[0];
    if (!consp(v_9054)) goto v_9014;
    else goto v_9015;
v_9014:
    v_9054 = stack[0];
    goto v_9013;
v_9015:
    goto v_9024;
v_9020:
    v_9054 = stack[0];
    v_9055 = qcar(v_9054);
    goto v_9021;
v_9022:
    v_9054 = elt(env, 1); // (wedge d partdf hodge innerprod liedf)
    goto v_9023;
v_9024:
    goto v_9020;
v_9021:
    goto v_9022;
v_9023:
    v_9054 = Lmemq(nil, v_9055, v_9054);
    if (v_9054 == nil) goto v_9019;
    v_9054 = stack[0];
    goto v_9013;
v_9019:
    goto v_9037;
v_9033:
    v_9054 = stack[0];
    v_9054 = qcdr(v_9054);
    v_9055 = Llength(nil, v_9054);
    env = stack[-1];
    goto v_9034;
v_9035:
    v_9054 = stack[0];
    v_9054 = qcar(v_9054);
    if (!symbolp(v_9054)) v_9054 = nil;
    else { v_9054 = qfastgets(v_9054);
           if (v_9054 != nil) { v_9054 = elt(v_9054, 25); // ifdegree
#ifdef RECORD_GET
             if (v_9054 != SPID_NOPROP)
                record_get(elt(fastget_names, 25), 1);
             else record_get(elt(fastget_names, 25), 0),
                v_9054 = nil; }
           else record_get(elt(fastget_names, 25), 0); }
#else
             if (v_9054 == SPID_NOPROP) v_9054 = nil; }}
#endif
    goto v_9036;
v_9037:
    goto v_9033;
v_9034:
    goto v_9035;
v_9036:
    v_9054 = Lassoc(nil, v_9055, v_9054);
    if (v_9054 == nil) goto v_9031;
    v_9054 = stack[0];
    v_9054 = qcdr(v_9054);
    fn = elt(env, 2); // xvarlistp
    v_9054 = (*qfn1(fn))(fn, v_9054);
    env = stack[-1];
    if (v_9054 == nil) goto v_9045;
    else goto v_9031;
v_9045:
    v_9054 = stack[0];
    goto v_9013;
v_9031:
    v_9054 = stack[0];
    {
        fn = elt(env, 3); // mknwedge
        return (*qfn1(fn))(fn, v_9054);
    }
    v_9054 = nil;
v_9013:
    return onevalue(v_9054);
}



// Code for cstimes

static LispObject CC_cstimes(LispObject env,
                         LispObject v_9010, LispObject v_9011)
{
    env = qenv(env);
    LispObject v_9070, v_9071, v_9072, v_9073;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9011,v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9010,v_9011);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_9071 = v_9011;
    v_9072 = v_9010;
// end of prologue
v_9016:
    v_9070 = v_9072;
    if (v_9070 == nil) goto v_9019;
    else goto v_9020;
v_9019:
    v_9070 = v_9071;
    if (v_9070 == nil) goto v_9024;
    else goto v_9025;
v_9024:
    v_9070 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9015;
v_9025:
    v_9070 = v_9071;
    v_9070 = qcdr(v_9070);
    if (v_9070 == nil) goto v_9028;
    else goto v_9029;
v_9028:
    v_9070 = v_9071;
    v_9070 = qcar(v_9070);
    goto v_9015;
v_9029:
    goto v_9041;
v_9037:
    v_9070 = elt(env, 1); // times
    goto v_9038;
v_9039:
    goto v_9040;
v_9041:
    goto v_9037;
v_9038:
    goto v_9039;
v_9040:
    return cons(v_9070, v_9071);
    goto v_9018;
v_9020:
    goto v_9050;
v_9046:
    v_9070 = v_9072;
    v_9073 = qcar(v_9070);
    goto v_9047;
v_9048:
    v_9070 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9049;
v_9050:
    goto v_9046;
v_9047:
    goto v_9048;
v_9049:
    if (v_9073 == v_9070) goto v_9044;
    else goto v_9045;
v_9044:
    v_9070 = v_9072;
    v_9070 = qcdr(v_9070);
    v_9072 = v_9070;
    goto v_9016;
v_9045:
    v_9070 = v_9072;
    v_9070 = qcdr(v_9070);
    stack[0] = v_9070;
    goto v_9065;
v_9061:
    v_9070 = v_9072;
    v_9070 = qcar(v_9070);
    goto v_9062;
v_9063:
    goto v_9064;
v_9065:
    goto v_9061;
v_9062:
    goto v_9063;
v_9064:
    v_9070 = cons(v_9070, v_9071);
    env = stack[-1];
    v_9071 = v_9070;
    v_9070 = stack[0];
    v_9072 = v_9070;
    goto v_9016;
v_9018:
    v_9070 = nil;
v_9015:
    return onevalue(v_9070);
}



// Code for sqp

static LispObject CC_sqp(LispObject env,
                         LispObject v_9010)
{
    env = qenv(env);
    LispObject v_9034;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9010);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_9010;
// end of prologue
    v_9034 = stack[0];
    v_9034 = Lconsp(nil, v_9034);
    env = stack[-1];
    if (v_9034 == nil) goto v_9014;
    else goto v_9015;
v_9014:
    v_9034 = nil;
    goto v_9013;
v_9015:
    v_9034 = stack[0];
    v_9034 = qcar(v_9034);
    fn = elt(env, 1); // sfpx
    v_9034 = (*qfn1(fn))(fn, v_9034);
    env = stack[-1];
    if (v_9034 == nil) goto v_9023;
    else goto v_9024;
v_9023:
    v_9034 = nil;
    goto v_9022;
v_9024:
    v_9034 = stack[0];
    v_9034 = qcdr(v_9034);
    {
        fn = elt(env, 1); // sfpx
        return (*qfn1(fn))(fn, v_9034);
    }
    v_9034 = nil;
v_9022:
    goto v_9013;
    v_9034 = nil;
v_9013:
    return onevalue(v_9034);
}



// Code for b!:extadd

static LispObject CC_bTextadd(LispObject env,
                         LispObject v_9010, LispObject v_9011)
{
    env = qenv(env);
    LispObject v_9138, v_9139, v_9140;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_9011,v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_9010,v_9011);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_9011;
    stack[-1] = v_9010;
// end of prologue
    stack[-2] = nil;
v_9018:
    v_9138 = stack[-1];
    if (v_9138 == nil) goto v_9023;
    else goto v_9024;
v_9023:
    v_9138 = stack[0];
    v_9139 = v_9138;
    goto v_9019;
v_9024:
    v_9138 = stack[0];
    if (v_9138 == nil) goto v_9027;
    else goto v_9028;
v_9027:
    v_9138 = stack[-1];
    v_9139 = v_9138;
    goto v_9019;
v_9028:
    goto v_9037;
v_9033:
    v_9138 = stack[-1];
    v_9138 = qcar(v_9138);
    v_9139 = qcar(v_9138);
    goto v_9034;
v_9035:
    v_9138 = stack[0];
    v_9138 = qcar(v_9138);
    v_9138 = qcar(v_9138);
    goto v_9036;
v_9037:
    goto v_9033;
v_9034:
    goto v_9035;
v_9036:
    if (equal(v_9139, v_9138)) goto v_9031;
    else goto v_9032;
v_9031:
    goto v_9049;
v_9045:
    v_9138 = stack[-1];
    v_9138 = qcar(v_9138);
    v_9139 = qcdr(v_9138);
    goto v_9046;
v_9047:
    v_9138 = stack[0];
    v_9138 = qcar(v_9138);
    v_9138 = qcdr(v_9138);
    goto v_9048;
v_9049:
    goto v_9045;
v_9046:
    goto v_9047;
v_9048:
    fn = elt(env, 2); // addf
    v_9138 = (*qfn2(fn))(fn, v_9139, v_9138);
    env = stack[-3];
    v_9139 = v_9138;
    if (v_9139 == nil) goto v_9059;
    goto v_9068;
v_9062:
    v_9139 = stack[-1];
    v_9139 = qcar(v_9139);
    v_9140 = qcar(v_9139);
    goto v_9063;
v_9064:
    v_9139 = v_9138;
    goto v_9065;
v_9066:
    v_9138 = stack[-2];
    goto v_9067;
v_9068:
    goto v_9062;
v_9063:
    goto v_9064;
v_9065:
    goto v_9066;
v_9067:
    v_9138 = acons(v_9140, v_9139, v_9138);
    env = stack[-3];
    stack[-2] = v_9138;
    goto v_9057;
v_9059:
v_9057:
    v_9138 = stack[-1];
    v_9138 = qcdr(v_9138);
    stack[-1] = v_9138;
    v_9138 = stack[0];
    v_9138 = qcdr(v_9138);
    stack[0] = v_9138;
    goto v_9018;
v_9032:
    goto v_9085;
v_9081:
    v_9138 = stack[-1];
    v_9138 = qcar(v_9138);
    v_9139 = qcar(v_9138);
    goto v_9082;
v_9083:
    v_9138 = stack[0];
    v_9138 = qcar(v_9138);
    v_9138 = qcar(v_9138);
    goto v_9084;
v_9085:
    goto v_9081;
v_9082:
    goto v_9083;
v_9084:
    fn = elt(env, 3); // b!:ordexp
    v_9138 = (*qfn2(fn))(fn, v_9139, v_9138);
    env = stack[-3];
    if (v_9138 == nil) goto v_9079;
    goto v_9097;
v_9093:
    v_9138 = stack[-1];
    v_9139 = qcar(v_9138);
    goto v_9094;
v_9095:
    v_9138 = stack[-2];
    goto v_9096;
v_9097:
    goto v_9093;
v_9094:
    goto v_9095;
v_9096:
    v_9138 = cons(v_9139, v_9138);
    env = stack[-3];
    stack[-2] = v_9138;
    v_9138 = stack[-1];
    v_9138 = qcdr(v_9138);
    stack[-1] = v_9138;
    goto v_9018;
v_9079:
    goto v_9110;
v_9106:
    v_9138 = stack[0];
    v_9139 = qcar(v_9138);
    goto v_9107;
v_9108:
    v_9138 = stack[-2];
    goto v_9109;
v_9110:
    goto v_9106;
v_9107:
    goto v_9108;
v_9109:
    v_9138 = cons(v_9139, v_9138);
    env = stack[-3];
    stack[-2] = v_9138;
    v_9138 = stack[0];
    v_9138 = qcdr(v_9138);
    stack[0] = v_9138;
    goto v_9018;
v_9019:
v_9118:
    v_9138 = stack[-2];
    if (v_9138 == nil) goto v_9121;
    else goto v_9122;
v_9121:
    goto v_9117;
v_9122:
    v_9138 = stack[-2];
    v_9138 = qcdr(v_9138);
    stack[-1] = v_9138;
    goto v_9132;
v_9128:
    v_9138 = stack[-2];
    goto v_9129;
v_9130:
    goto v_9131;
v_9132:
    goto v_9128;
v_9129:
    goto v_9130;
v_9131:
    v_9138 = Lrplacd(nil, v_9138, v_9139);
    env = stack[-3];
    v_9138 = stack[-2];
    v_9139 = v_9138;
    v_9138 = stack[-1];
    stack[-2] = v_9138;
    goto v_9118;
v_9117:
    v_9138 = v_9139;
    return onevalue(v_9138);
}



// Code for simpiden

static LispObject CC_simpiden(LispObject env,
                         LispObject v_9010)
{
    env = qenv(env);
    LispObject v_9518, v_9519, v_9520;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_9010);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9010);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[0] = v_9010;
// end of prologue
    stack[-5] = nil;
    stack[-4] = nil;
    v_9518 = stack[0];
    v_9518 = qcar(v_9518);
    stack[-7] = v_9518;
    v_9518 = stack[0];
    v_9518 = qcdr(v_9518);
    stack[0] = v_9518;
    goto v_9035;
v_9031:
    v_9519 = stack[-7];
    goto v_9032;
v_9033:
    v_9518 = stack[0];
    goto v_9034;
v_9035:
    goto v_9031;
v_9032:
    goto v_9033;
v_9034:
    fn = elt(env, 13); // valuechk
    v_9518 = (*qfn2(fn))(fn, v_9519, v_9518);
    env = stack[-8];
    stack[-6] = v_9518;
    if (v_9518 == nil) goto v_9029;
    v_9518 = stack[-6];
    goto v_9019;
v_9029:
    v_9518 = stack[0];
    if (v_9518 == nil) goto v_9046;
    goto v_9053;
v_9049:
    v_9518 = stack[0];
    v_9519 = qcar(v_9518);
    goto v_9050;
v_9051:
    v_9518 = elt(env, 2); // list
    goto v_9052;
v_9053:
    goto v_9049;
v_9050:
    goto v_9051;
v_9052:
    v_9518 = Leqcar(nil, v_9519, v_9518);
    env = stack[-8];
    goto v_9044;
v_9046:
    v_9518 = nil;
    goto v_9044;
    v_9518 = nil;
v_9044:
    if (v_9518 == nil) goto v_9042;
    goto v_9065;
v_9061:
    goto v_9071;
v_9067:
    stack[-1] = stack[-7];
    goto v_9068;
v_9069:
    v_9518 = stack[0];
    v_9518 = qcar(v_9518);
    fn = elt(env, 14); // aeval
    v_9518 = (*qfn1(fn))(fn, v_9518);
    env = stack[-8];
    goto v_9070;
v_9071:
    goto v_9067;
v_9068:
    goto v_9069;
v_9070:
    v_9519 = list2(stack[-1], v_9518);
    env = stack[-8];
    goto v_9062;
v_9063:
    v_9518 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9064;
v_9065:
    goto v_9061;
v_9062:
    goto v_9063;
v_9064:
    {
        fn = elt(env, 15); // mksq
        return (*qfn2(fn))(fn, v_9519, v_9518);
    }
v_9042:
    goto v_9084;
v_9078:
    v_9519 = stack[0];
    goto v_9079;
v_9080:
    goto v_9091;
v_9087:
    v_9520 = stack[-7];
    goto v_9088;
v_9089:
    v_9518 = elt(env, 3); // nosimp
    goto v_9090;
v_9091:
    goto v_9087;
v_9088:
    goto v_9089;
v_9090:
    v_9520 = get(v_9520, v_9518);
    env = stack[-8];
    goto v_9081;
v_9082:
    v_9518 = nil;
    goto v_9083;
v_9084:
    goto v_9078;
v_9079:
    goto v_9080;
v_9081:
    goto v_9082;
v_9083:
    fn = elt(env, 16); // fnreval
    v_9518 = (*qfnn(fn))(fn, 3, v_9519, v_9520, v_9518);
    env = stack[-8];
    stack[-6] = v_9518;
    v_9518 = stack[-6];
    stack[-3] = v_9518;
    v_9518 = stack[-3];
    if (v_9518 == nil) goto v_9104;
    else goto v_9105;
v_9104:
    v_9518 = nil;
    goto v_9099;
v_9105:
    v_9518 = stack[-3];
    v_9518 = qcar(v_9518);
    v_9520 = v_9518;
    goto v_9121;
v_9117:
    v_9519 = v_9520;
    goto v_9118;
v_9119:
    v_9518 = elt(env, 4); // !*sq
    goto v_9120;
v_9121:
    goto v_9117;
v_9118:
    goto v_9119;
v_9120:
    if (!consp(v_9519)) goto v_9115;
    v_9519 = qcar(v_9519);
    if (v_9519 == v_9518) goto v_9114;
    else goto v_9115;
v_9114:
    v_9518 = v_9520;
    v_9518 = qcdr(v_9518);
    v_9518 = qcar(v_9518);
    fn = elt(env, 17); // prepsqxx
    v_9518 = (*qfn1(fn))(fn, v_9518);
    env = stack[-8];
    goto v_9113;
v_9115:
    v_9518 = v_9520;
    if (is_number(v_9518)) goto v_9128;
    else goto v_9129;
v_9128:
    v_9518 = v_9520;
    goto v_9113;
v_9129:
    v_9518 = v_9520;
    goto v_9113;
    v_9518 = nil;
v_9113:
    v_9518 = ncons(v_9518);
    env = stack[-8];
    stack[-1] = v_9518;
    stack[-2] = v_9518;
v_9100:
    v_9518 = stack[-3];
    v_9518 = qcdr(v_9518);
    stack[-3] = v_9518;
    v_9518 = stack[-3];
    if (v_9518 == nil) goto v_9140;
    else goto v_9141;
v_9140:
    v_9518 = stack[-2];
    goto v_9099;
v_9141:
    goto v_9149;
v_9145:
    stack[0] = stack[-1];
    goto v_9146;
v_9147:
    v_9518 = stack[-3];
    v_9518 = qcar(v_9518);
    v_9520 = v_9518;
    goto v_9164;
v_9160:
    v_9519 = v_9520;
    goto v_9161;
v_9162:
    v_9518 = elt(env, 4); // !*sq
    goto v_9163;
v_9164:
    goto v_9160;
v_9161:
    goto v_9162;
v_9163:
    if (!consp(v_9519)) goto v_9158;
    v_9519 = qcar(v_9519);
    if (v_9519 == v_9518) goto v_9157;
    else goto v_9158;
v_9157:
    v_9518 = v_9520;
    v_9518 = qcdr(v_9518);
    v_9518 = qcar(v_9518);
    fn = elt(env, 17); // prepsqxx
    v_9518 = (*qfn1(fn))(fn, v_9518);
    env = stack[-8];
    goto v_9156;
v_9158:
    v_9518 = v_9520;
    if (is_number(v_9518)) goto v_9171;
    else goto v_9172;
v_9171:
    v_9518 = v_9520;
    goto v_9156;
v_9172:
    v_9518 = v_9520;
    goto v_9156;
    v_9518 = nil;
v_9156:
    v_9518 = ncons(v_9518);
    env = stack[-8];
    goto v_9148;
v_9149:
    goto v_9145;
v_9146:
    goto v_9147;
v_9148:
    v_9518 = Lrplacd(nil, stack[0], v_9518);
    env = stack[-8];
    v_9518 = stack[-1];
    v_9518 = qcdr(v_9518);
    stack[-1] = v_9518;
    goto v_9100;
v_9099:
    stack[0] = v_9518;
    v_9518 = stack[0];
    if (v_9518 == nil) goto v_9184;
    goto v_9196;
v_9192:
    v_9518 = stack[0];
    v_9519 = qcar(v_9518);
    goto v_9193;
v_9194:
    v_9518 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9195;
v_9196:
    goto v_9192;
v_9193:
    goto v_9194;
v_9195:
    if (v_9519 == v_9518) goto v_9190;
    else goto v_9191;
v_9190:
    goto v_9209;
v_9205:
    v_9519 = stack[-7];
    goto v_9206;
v_9207:
    v_9518 = elt(env, 5); // odd
    goto v_9208;
v_9209:
    goto v_9205;
v_9206:
    goto v_9207;
v_9208:
    v_9518 = Lflagp(nil, v_9519, v_9518);
    env = stack[-8];
    if (v_9518 == nil) goto v_9203;
    goto v_9217;
v_9213:
    v_9519 = stack[-7];
    goto v_9214;
v_9215:
    v_9518 = elt(env, 6); // nonzero
    goto v_9216;
v_9217:
    goto v_9213;
v_9214:
    goto v_9215;
v_9216:
    v_9518 = Lflagp(nil, v_9519, v_9518);
    env = stack[-8];
    v_9518 = (v_9518 == nil ? lisp_true : nil);
    goto v_9201;
v_9203:
    v_9518 = nil;
    goto v_9201;
    v_9518 = nil;
v_9201:
    goto v_9189;
v_9191:
    v_9518 = nil;
    goto v_9189;
    v_9518 = nil;
v_9189:
    if (v_9518 == nil) goto v_9184;
    goto v_9232;
v_9228:
    v_9519 = nil;
    goto v_9229;
v_9230:
    v_9518 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9231;
v_9232:
    goto v_9228;
v_9229:
    goto v_9230;
v_9231:
    return cons(v_9519, v_9518);
v_9184:
    goto v_9240;
v_9236:
    v_9519 = stack[-7];
    goto v_9237;
v_9238:
    v_9518 = stack[0];
    goto v_9239;
v_9240:
    goto v_9236;
v_9237:
    goto v_9238;
v_9239:
    v_9518 = cons(v_9519, v_9518);
    env = stack[-8];
    stack[0] = v_9518;
    v_9518 = stack[-7];
    if (!symbolp(v_9518)) v_9518 = nil;
    else { v_9518 = qfastgets(v_9518);
           if (v_9518 != nil) { v_9518 = elt(v_9518, 0); // noncom
#ifdef RECORD_GET
             if (v_9518 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_9518 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_9518 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_9518 == SPID_NOPROP) v_9518 = nil; else v_9518 = lisp_true; }}
#endif
    if (v_9518 == nil) goto v_9246;
    v_9518 = lisp_true;
    qvalue(elt(env, 7)) = v_9518; // ncmp!*
    goto v_9244;
v_9246:
v_9244:
    v_9518 = qvalue(elt(env, 8)); // subfg!*
    if (v_9518 == nil) goto v_9252;
    else goto v_9253;
v_9252:
    goto v_9020;
v_9253:
    goto v_9266;
v_9262:
    v_9519 = stack[-7];
    goto v_9263;
v_9264:
    v_9518 = elt(env, 9); // linear
    goto v_9265;
v_9266:
    goto v_9262;
v_9263:
    goto v_9264;
v_9265:
    v_9518 = Lflagp(nil, v_9519, v_9518);
    env = stack[-8];
    if (v_9518 == nil) goto v_9260;
    goto v_9274;
v_9270:
    v_9518 = stack[0];
    fn = elt(env, 18); // formlnr
    v_9519 = (*qfn1(fn))(fn, v_9518);
    env = stack[-8];
    stack[-4] = v_9519;
    goto v_9271;
v_9272:
    v_9518 = stack[0];
    goto v_9273;
v_9274:
    goto v_9270;
v_9271:
    goto v_9272;
v_9273:
    v_9518 = Lneq(nil, v_9519, v_9518);
    env = stack[-8];
    goto v_9258;
v_9260:
    v_9518 = nil;
    goto v_9258;
    v_9518 = nil;
v_9258:
    if (v_9518 == nil) goto v_9256;
    v_9518 = stack[-4];
    {
        fn = elt(env, 19); // simp
        return (*qfn1(fn))(fn, v_9518);
    }
v_9256:
    v_9518 = stack[0];
    fn = elt(env, 20); // opmtch
    v_9518 = (*qfn1(fn))(fn, v_9518);
    env = stack[-8];
    stack[-4] = v_9518;
    if (v_9518 == nil) goto v_9284;
    v_9518 = stack[-4];
    {
        fn = elt(env, 19); // simp
        return (*qfn1(fn))(fn, v_9518);
    }
v_9284:
    goto v_9296;
v_9292:
    v_9518 = stack[0];
    v_9519 = qcar(v_9518);
    goto v_9293;
v_9294:
    v_9518 = elt(env, 10); // opvalfn
    goto v_9295;
v_9296:
    goto v_9292;
v_9293:
    goto v_9294;
v_9295:
    v_9518 = get(v_9519, v_9518);
    env = stack[-8];
    stack[-4] = v_9518;
    if (v_9518 == nil) goto v_9290;
    goto v_9305;
v_9301:
    v_9519 = stack[-4];
    goto v_9302;
v_9303:
    v_9518 = stack[0];
    goto v_9304;
v_9305:
    goto v_9301;
v_9302:
    goto v_9303;
v_9304:
        return Lapply1(nil, v_9519, v_9518);
v_9290:
v_9020:
    v_9518 = stack[-7];
    if (!symbolp(v_9518)) v_9518 = nil;
    else { v_9518 = qfastgets(v_9518);
           if (v_9518 != nil) { v_9518 = elt(v_9518, 43); // symmetric
#ifdef RECORD_GET
             if (v_9518 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v_9518 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v_9518 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v_9518 == SPID_NOPROP) v_9518 = nil; else v_9518 = lisp_true; }}
#endif
    if (v_9518 == nil) goto v_9311;
    goto v_9319;
v_9315:
    stack[-1] = stack[-7];
    goto v_9316;
v_9317:
    v_9518 = stack[0];
    v_9518 = qcdr(v_9518);
    fn = elt(env, 21); // ordn
    v_9518 = (*qfn1(fn))(fn, v_9518);
    env = stack[-8];
    goto v_9318;
v_9319:
    goto v_9315;
v_9316:
    goto v_9317;
v_9318:
    v_9518 = cons(stack[-1], v_9518);
    env = stack[-8];
    stack[0] = v_9518;
    goto v_9309;
v_9311:
    goto v_9331;
v_9327:
    v_9519 = stack[-7];
    goto v_9328;
v_9329:
    v_9518 = elt(env, 11); // antisymmetric
    goto v_9330;
v_9331:
    goto v_9327;
v_9328:
    goto v_9329;
v_9330:
    v_9518 = Lflagp(nil, v_9519, v_9518);
    env = stack[-8];
    if (v_9518 == nil) goto v_9325;
    v_9518 = stack[0];
    v_9518 = qcdr(v_9518);
    fn = elt(env, 22); // repeats
    v_9518 = (*qfn1(fn))(fn, v_9518);
    env = stack[-8];
    if (v_9518 == nil) goto v_9337;
    goto v_9346;
v_9342:
    v_9519 = nil;
    goto v_9343;
v_9344:
    v_9518 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9345;
v_9346:
    goto v_9342;
v_9343:
    goto v_9344;
v_9345:
    return cons(v_9519, v_9518);
v_9337:
    goto v_9356;
v_9352:
    v_9518 = stack[0];
    v_9518 = qcdr(v_9518);
    fn = elt(env, 21); // ordn
    v_9519 = (*qfn1(fn))(fn, v_9518);
    env = stack[-8];
    stack[-4] = v_9519;
    goto v_9353;
v_9354:
    v_9518 = stack[0];
    v_9518 = qcdr(v_9518);
    goto v_9355;
v_9356:
    goto v_9352;
v_9353:
    goto v_9354;
v_9355:
    fn = elt(env, 23); // permp
    v_9518 = (*qfn2(fn))(fn, v_9519, v_9518);
    env = stack[-8];
    if (v_9518 == nil) goto v_9349;
    else goto v_9350;
v_9349:
    v_9518 = lisp_true;
    stack[-5] = v_9518;
    goto v_9335;
v_9350:
v_9335:
    goto v_9368;
v_9364:
    v_9518 = stack[0];
    v_9519 = qcar(v_9518);
    goto v_9365;
v_9366:
    v_9518 = stack[-4];
    goto v_9367;
v_9368:
    goto v_9364;
v_9365:
    goto v_9366;
v_9367:
    v_9518 = cons(v_9519, v_9518);
    env = stack[-8];
    stack[-7] = v_9518;
    goto v_9384;
v_9380:
    v_9519 = stack[-4];
    goto v_9381;
v_9382:
    v_9518 = stack[0];
    v_9518 = qcdr(v_9518);
    goto v_9383;
v_9384:
    goto v_9380;
v_9381:
    goto v_9382;
v_9383:
    if (equal(v_9519, v_9518)) goto v_9379;
    v_9518 = stack[-7];
    fn = elt(env, 20); // opmtch
    v_9518 = (*qfn1(fn))(fn, v_9518);
    env = stack[-8];
    stack[-4] = v_9518;
    goto v_9377;
v_9379:
    v_9518 = nil;
    goto v_9377;
    v_9518 = nil;
v_9377:
    if (v_9518 == nil) goto v_9375;
    v_9518 = stack[-5];
    if (v_9518 == nil) goto v_9396;
    v_9518 = stack[-4];
    fn = elt(env, 19); // simp
    v_9518 = (*qfn1(fn))(fn, v_9518);
    env = stack[-8];
    {
        fn = elt(env, 24); // negsq
        return (*qfn1(fn))(fn, v_9518);
    }
v_9396:
    v_9518 = stack[-4];
    {
        fn = elt(env, 19); // simp
        return (*qfn1(fn))(fn, v_9518);
    }
    v_9518 = nil;
    goto v_9019;
v_9375:
    v_9518 = stack[-7];
    stack[0] = v_9518;
    goto v_9309;
v_9325:
v_9309:
    goto v_9423;
v_9419:
    v_9519 = stack[-7];
    goto v_9420;
v_9421:
    v_9518 = elt(env, 12); // even
    goto v_9422;
v_9423:
    goto v_9419;
v_9420:
    goto v_9421;
v_9422:
    v_9518 = Lflagp(nil, v_9519, v_9518);
    env = stack[-8];
    if (v_9518 == nil) goto v_9417;
    v_9518 = lisp_true;
    goto v_9415;
v_9417:
    goto v_9434;
v_9430:
    v_9519 = stack[-7];
    goto v_9431;
v_9432:
    v_9518 = elt(env, 5); // odd
    goto v_9433;
v_9434:
    goto v_9430;
v_9431:
    goto v_9432;
v_9433:
    v_9518 = Lflagp(nil, v_9519, v_9518);
    env = stack[-8];
    goto v_9415;
    v_9518 = nil;
v_9415:
    if (v_9518 == nil) goto v_9413;
    v_9518 = stack[-6];
    if (v_9518 == nil) goto v_9439;
    else goto v_9440;
v_9439:
    v_9518 = nil;
    goto v_9438;
v_9440:
    v_9518 = stack[-6];
    v_9518 = qcar(v_9518);
    fn = elt(env, 19); // simp
    v_9518 = (*qfn1(fn))(fn, v_9518);
    env = stack[-8];
    stack[-6] = v_9518;
    v_9518 = qcar(v_9518);
    fn = elt(env, 25); // minusf
    v_9518 = (*qfn1(fn))(fn, v_9518);
    env = stack[-8];
    goto v_9438;
    v_9518 = nil;
v_9438:
    goto v_9411;
v_9413:
    v_9518 = nil;
    goto v_9411;
    v_9518 = nil;
v_9411:
    if (v_9518 == nil) goto v_9409;
    goto v_9462;
v_9458:
    v_9519 = stack[-7];
    goto v_9459;
v_9460:
    v_9518 = elt(env, 5); // odd
    goto v_9461;
v_9462:
    goto v_9458;
v_9459:
    goto v_9460;
v_9461:
    v_9518 = Lflagp(nil, v_9519, v_9518);
    env = stack[-8];
    if (v_9518 == nil) goto v_9456;
    v_9518 = stack[-5];
    v_9518 = (v_9518 == nil ? lisp_true : nil);
    stack[-5] = v_9518;
    goto v_9454;
v_9456:
v_9454:
    goto v_9474;
v_9468:
    stack[-1] = stack[-7];
    goto v_9469;
v_9470:
    v_9518 = stack[-6];
    fn = elt(env, 24); // negsq
    v_9518 = (*qfn1(fn))(fn, v_9518);
    env = stack[-8];
    fn = elt(env, 17); // prepsqxx
    v_9519 = (*qfn1(fn))(fn, v_9518);
    env = stack[-8];
    goto v_9471;
v_9472:
    v_9518 = stack[0];
    v_9518 = qcdr(v_9518);
    v_9518 = qcdr(v_9518);
    goto v_9473;
v_9474:
    goto v_9468;
v_9469:
    goto v_9470;
v_9471:
    goto v_9472;
v_9473:
    v_9518 = list2star(stack[-1], v_9519, v_9518);
    env = stack[-8];
    stack[0] = v_9518;
    v_9518 = stack[0];
    fn = elt(env, 20); // opmtch
    v_9518 = (*qfn1(fn))(fn, v_9518);
    env = stack[-8];
    stack[-4] = v_9518;
    if (v_9518 == nil) goto v_9485;
    v_9518 = stack[-5];
    if (v_9518 == nil) goto v_9491;
    v_9518 = stack[-4];
    fn = elt(env, 19); // simp
    v_9518 = (*qfn1(fn))(fn, v_9518);
    env = stack[-8];
    {
        fn = elt(env, 24); // negsq
        return (*qfn1(fn))(fn, v_9518);
    }
v_9491:
    v_9518 = stack[-4];
    {
        fn = elt(env, 19); // simp
        return (*qfn1(fn))(fn, v_9518);
    }
    v_9518 = nil;
    goto v_9019;
v_9485:
    goto v_9407;
v_9409:
v_9407:
    goto v_9505;
v_9501:
    v_9519 = stack[0];
    goto v_9502;
v_9503:
    v_9518 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9504;
v_9505:
    goto v_9501;
v_9502:
    goto v_9503;
v_9504:
    fn = elt(env, 15); // mksq
    v_9518 = (*qfn2(fn))(fn, v_9519, v_9518);
    env = stack[-8];
    stack[0] = v_9518;
    v_9518 = stack[-5];
    if (v_9518 == nil) goto v_9511;
    v_9518 = stack[0];
    {
        fn = elt(env, 24); // negsq
        return (*qfn1(fn))(fn, v_9518);
    }
v_9511:
    v_9518 = stack[0];
    goto v_9509;
    v_9518 = nil;
v_9509:
v_9019:
    return onevalue(v_9518);
}



// Code for in_list1

static LispObject CC_in_list1(LispObject env,
                         LispObject v_9010, LispObject v_9011)
{
    env = qenv(env);
    LispObject v_9024, v_9025, v_9026;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9024 = v_9011;
    v_9025 = v_9010;
// end of prologue
    goto v_9020;
v_9014:
    v_9026 = v_9025;
    goto v_9015;
v_9016:
    v_9025 = v_9024;
    goto v_9017;
v_9018:
    v_9024 = nil;
    goto v_9019;
v_9020:
    goto v_9014;
v_9015:
    goto v_9016;
v_9017:
    goto v_9018;
v_9019:
    {
        fn = elt(env, 1); // in_list1a
        return (*qfnn(fn))(fn, 3, v_9026, v_9025, v_9024);
    }
}



setup_type const u18_setup[] =
{
    {"pv_times1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pv_times1},
    {"lex_restore_context",     CC_lex_restore_context,TOO_MANY_1,WRONG_NO_1},
    {"sfto_kexp",               TOO_FEW_2,      CC_sfto_kexp,  WRONG_NO_2},
    {"collect_cars",            CC_collect_cars,TOO_MANY_1,    WRONG_NO_1},
    {"findremainder",           TOO_FEW_2,      CC_findremainder,WRONG_NO_2},
    {"expnd1",                  CC_expnd1,      TOO_MANY_1,    WRONG_NO_1},
    {"cl_smsimpl-junct2",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_smsimplKjunct2},
    {"ibalp_lenisone",          CC_ibalp_lenisone,TOO_MANY_1,  WRONG_NO_1},
    {"attributesml",            TOO_FEW_2,      CC_attributesml,WRONG_NO_2},
    {"spband_matrix",           TOO_FEW_2,      CC_spband_matrix,WRONG_NO_2},
    {"dm-eq",                   TOO_FEW_2,      CC_dmKeq,      WRONG_NO_2},
    {"findnewvars",             CC_findnewvars, TOO_MANY_1,    WRONG_NO_1},
    {"onoff",                   TOO_FEW_2,      CC_onoff,      WRONG_NO_2},
    {"bcplus?",                 CC_bcplusW,     TOO_MANY_1,    WRONG_NO_1},
    {"groebbuchcrit4t",         TOO_FEW_2,      CC_groebbuchcrit4t,WRONG_NO_2},
    {"*pf2wedgepf",             CC_Hpf2wedgepf, TOO_MANY_1,    WRONG_NO_1},
    {"removeindices",           TOO_FEW_2,      CC_removeindices,WRONG_NO_2},
    {"simprepart",              CC_simprepart,  TOO_MANY_1,    WRONG_NO_1},
    {"xread1",                  CC_xread1,      TOO_MANY_1,    WRONG_NO_1},
    {"invbf",                   CC_invbf,       TOO_MANY_1,    WRONG_NO_1},
    {"degree-in-variable",      TOO_FEW_2,      CC_degreeKinKvariable,WRONG_NO_2},
    {"ra_refine1",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ra_refine1},
    {"get_action",              TOO_FEW_2,      CC_get_action, WRONG_NO_2},
    {"ctx_filter",              TOO_FEW_2,      CC_ctx_filter, WRONG_NO_2},
    {"rl_bestgaussp",           CC_rl_bestgaussp,TOO_MANY_1,   WRONG_NO_1},
    {"mkkl",                    TOO_FEW_2,      CC_mkkl,       WRONG_NO_2},
    {"exptcompare",             TOO_FEW_2,      CC_exptcompare,WRONG_NO_2},
    {"qqe_number-of-adds-in-qterm",CC_qqe_numberKofKaddsKinKqterm,TOO_MANY_1,WRONG_NO_1},
    {"sf2ss",                   CC_sf2ss,       TOO_MANY_1,    WRONG_NO_1},
    {"constsml",                CC_constsml,    TOO_MANY_1,    WRONG_NO_1},
    {"unchecked_getmatelem",    CC_unchecked_getmatelem,TOO_MANY_1,WRONG_NO_1},
    {"guesspftype",             CC_guesspftype, TOO_MANY_1,    WRONG_NO_1},
    {"cstimes",                 TOO_FEW_2,      CC_cstimes,    WRONG_NO_2},
    {"sqp",                     CC_sqp,         TOO_MANY_1,    WRONG_NO_1},
    {"b:extadd",                TOO_FEW_2,      CC_bTextadd,   WRONG_NO_2},
    {"simpiden",                CC_simpiden,    TOO_MANY_1,    WRONG_NO_1},
    {"in_list1",                TOO_FEW_2,      CC_in_list1,   WRONG_NO_2},
    {NULL, (one_args *)"u18", (two_args *)"37885 2120748 9777501", 0}
};

// end of generated code
