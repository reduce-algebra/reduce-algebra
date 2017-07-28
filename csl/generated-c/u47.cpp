
// $destdir/u47.c        Machine generated C code

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



// Code for groebcplistmerge

static LispObject CC_groebcplistmerge(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27832, v_27833;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_27762;
    stack[-2] = v_27761;
// end of prologue
    v_27832 = stack[-2];
    if (v_27832 == nil) goto v_27771;
    else goto v_27772;
v_27771:
    v_27832 = stack[-1];
    goto v_27768;
v_27772:
    v_27832 = stack[-1];
    if (v_27832 == nil) goto v_27777;
    else goto v_27778;
v_27777:
    v_27832 = stack[-2];
    goto v_27768;
v_27778:
    v_27832 = stack[-2];
    v_27832 = qcar(v_27832);
    stack[-3] = v_27832;
    v_27832 = stack[-1];
    v_27832 = qcar(v_27832);
    stack[0] = v_27832;
    goto v_27790;
v_27786:
    v_27833 = stack[-3];
    goto v_27787;
v_27788:
    v_27832 = stack[0];
    goto v_27789;
v_27790:
    goto v_27786;
v_27787:
    goto v_27788;
v_27789:
    fn = elt(env, 1); // groebcpcompless!?
    v_27832 = (*qfn2(fn))(fn, v_27833, v_27832);
    env = stack[-4];
    if (v_27832 == nil) goto v_27796;
    goto v_27803;
v_27799:
    stack[0] = stack[-3];
    goto v_27800;
v_27801:
    goto v_27810;
v_27806:
    v_27832 = stack[-2];
    v_27833 = qcdr(v_27832);
    goto v_27807;
v_27808:
    v_27832 = stack[-1];
    goto v_27809;
v_27810:
    goto v_27806;
v_27807:
    goto v_27808;
v_27809:
    v_27832 = CC_groebcplistmerge(elt(env, 0), v_27833, v_27832);
    goto v_27802;
v_27803:
    goto v_27799;
v_27800:
    goto v_27801;
v_27802:
    {
        LispObject v_27838 = stack[0];
        return cons(v_27838, v_27832);
    }
v_27796:
    goto v_27821;
v_27817:
    goto v_27818;
v_27819:
    goto v_27828;
v_27824:
    v_27833 = stack[-2];
    goto v_27825;
v_27826:
    v_27832 = stack[-1];
    v_27832 = qcdr(v_27832);
    goto v_27827;
v_27828:
    goto v_27824;
v_27825:
    goto v_27826;
v_27827:
    v_27832 = CC_groebcplistmerge(elt(env, 0), v_27833, v_27832);
    goto v_27820;
v_27821:
    goto v_27817;
v_27818:
    goto v_27819;
v_27820:
    {
        LispObject v_27839 = stack[0];
        return cons(v_27839, v_27832);
    }
    v_27832 = nil;
v_27768:
    return onevalue(v_27832);
}



// Code for gfquotient

static LispObject CC_gfquotient(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27788, v_27789, v_27790;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27789 = v_27762;
    v_27790 = v_27761;
// end of prologue
    v_27788 = v_27790;
    v_27788 = qcar(v_27788);
    if (!consp(v_27788)) goto v_27766;
    else goto v_27767;
v_27766:
    goto v_27775;
v_27771:
    v_27788 = v_27790;
    goto v_27772;
v_27773:
    goto v_27774;
v_27775:
    goto v_27771;
v_27772:
    goto v_27773;
v_27774:
    {
        fn = elt(env, 1); // gffquot
        return (*qfn2(fn))(fn, v_27788, v_27789);
    }
v_27767:
    goto v_27785;
v_27781:
    v_27788 = v_27790;
    goto v_27782;
v_27783:
    goto v_27784;
v_27785:
    goto v_27781;
v_27782:
    goto v_27783;
v_27784:
    {
        fn = elt(env, 2); // gbfquot
        return (*qfn2(fn))(fn, v_27788, v_27789);
    }
    v_27788 = nil;
    return onevalue(v_27788);
}



// Code for mkdmoderr

static LispObject CC_mkdmoderr(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27787;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_27762;
    v_27787 = v_27761;
// end of prologue
    goto v_27771;
v_27765:
    stack[-4] = elt(env, 1); // lambda
    goto v_27766;
v_27767:
    stack[-2] = elt(env, 2); // (!*x!*)
    goto v_27768;
v_27769:
    goto v_27781;
v_27775:
    stack[-1] = elt(env, 3); // dmoderr
    goto v_27776;
v_27777:
    stack[0] = Lmkquote(nil, v_27787);
    env = stack[-5];
    goto v_27778;
v_27779:
    v_27787 = stack[-3];
    v_27787 = Lmkquote(nil, v_27787);
    env = stack[-5];
    goto v_27780;
v_27781:
    goto v_27775;
v_27776:
    goto v_27777;
v_27778:
    goto v_27779;
v_27780:
    v_27787 = list3(stack[-1], stack[0], v_27787);
    goto v_27770;
v_27771:
    goto v_27765;
v_27766:
    goto v_27767;
v_27768:
    goto v_27769;
v_27770:
    {
        LispObject v_27793 = stack[-4];
        LispObject v_27794 = stack[-2];
        return list3(v_27793, v_27794, v_27787);
    }
}



// Code for indordln

static LispObject CC_indordln(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27803, v_27804;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_27804 = v_27761;
// end of prologue
    v_27803 = v_27804;
    if (v_27803 == nil) goto v_27765;
    else goto v_27766;
v_27765:
    v_27803 = nil;
    goto v_27764;
v_27766:
    v_27803 = v_27804;
    v_27803 = qcdr(v_27803);
    if (v_27803 == nil) goto v_27769;
    else goto v_27770;
v_27769:
    v_27803 = v_27804;
    goto v_27764;
v_27770:
    v_27803 = v_27804;
    v_27803 = qcdr(v_27803);
    v_27803 = qcdr(v_27803);
    if (v_27803 == nil) goto v_27774;
    else goto v_27775;
v_27774:
    goto v_27784;
v_27780:
    v_27803 = v_27804;
    v_27803 = qcar(v_27803);
    goto v_27781;
v_27782:
    v_27804 = qcdr(v_27804);
    v_27804 = qcar(v_27804);
    goto v_27783;
v_27784:
    goto v_27780;
v_27781:
    goto v_27782;
v_27783:
    {
        fn = elt(env, 1); // indordl2
        return (*qfn2(fn))(fn, v_27803, v_27804);
    }
v_27775:
    goto v_27797;
v_27793:
    v_27803 = v_27804;
    stack[0] = qcar(v_27803);
    goto v_27794;
v_27795:
    v_27803 = v_27804;
    v_27803 = qcdr(v_27803);
    v_27803 = CC_indordln(elt(env, 0), v_27803);
    env = stack[-1];
    goto v_27796;
v_27797:
    goto v_27793;
v_27794:
    goto v_27795;
v_27796:
    {
        LispObject v_27806 = stack[0];
        fn = elt(env, 2); // indordlad
        return (*qfn2(fn))(fn, v_27806, v_27803);
    }
    v_27803 = nil;
v_27764:
    return onevalue(v_27803);
}



// Code for listquotient

static LispObject CC_listquotient(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27981, v_27982, v_27983;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_27762;
    stack[0] = v_27761;
// end of prologue
    goto v_27773;
v_27769:
    v_27981 = stack[0];
    v_27982 = qcar(v_27981);
    goto v_27770;
v_27771:
    v_27981 = stack[-4];
    goto v_27772;
v_27773:
    goto v_27769;
v_27770:
    goto v_27771;
v_27772:
    fn = elt(env, 3); // reval1
    v_27981 = (*qfn2(fn))(fn, v_27982, v_27981);
    env = stack[-7];
    stack[-3] = v_27981;
    goto v_27782;
v_27778:
    v_27981 = stack[0];
    v_27981 = qcdr(v_27981);
    v_27982 = qcar(v_27981);
    goto v_27779;
v_27780:
    v_27981 = stack[-4];
    goto v_27781;
v_27782:
    goto v_27778;
v_27779:
    goto v_27780;
v_27781:
    fn = elt(env, 3); // reval1
    v_27981 = (*qfn2(fn))(fn, v_27982, v_27981);
    env = stack[-7];
    stack[-6] = v_27981;
    goto v_27792;
v_27788:
    stack[-5] = elt(env, 1); // list
    goto v_27789;
v_27790:
    goto v_27803;
v_27799:
    v_27982 = stack[-3];
    goto v_27800;
v_27801:
    v_27981 = elt(env, 1); // list
    goto v_27802;
v_27803:
    goto v_27799;
v_27800:
    goto v_27801;
v_27802:
    if (!consp(v_27982)) goto v_27796;
    v_27982 = qcar(v_27982);
    if (v_27982 == v_27981) goto v_27797;
v_27796:
    v_27981 = stack[-6];
    v_27981 = qcdr(v_27981);
    stack[-6] = v_27981;
    v_27981 = stack[-6];
    if (v_27981 == nil) goto v_27816;
    else goto v_27817;
v_27816:
    v_27981 = nil;
    goto v_27810;
v_27817:
    v_27981 = stack[-6];
    v_27981 = qcar(v_27981);
    goto v_27829;
v_27825:
    goto v_27837;
v_27831:
    v_27983 = elt(env, 2); // quotient
    goto v_27832;
v_27833:
    v_27982 = stack[-3];
    goto v_27834;
v_27835:
    goto v_27836;
v_27837:
    goto v_27831;
v_27832:
    goto v_27833;
v_27834:
    goto v_27835;
v_27836:
    v_27982 = list3(v_27983, v_27982, v_27981);
    env = stack[-7];
    goto v_27826;
v_27827:
    v_27981 = stack[-4];
    goto v_27828;
v_27829:
    goto v_27825;
v_27826:
    goto v_27827;
v_27828:
    fn = elt(env, 3); // reval1
    v_27981 = (*qfn2(fn))(fn, v_27982, v_27981);
    env = stack[-7];
    v_27981 = ncons(v_27981);
    env = stack[-7];
    stack[-1] = v_27981;
    stack[-2] = v_27981;
v_27811:
    v_27981 = stack[-6];
    v_27981 = qcdr(v_27981);
    stack[-6] = v_27981;
    v_27981 = stack[-6];
    if (v_27981 == nil) goto v_27846;
    else goto v_27847;
v_27846:
    v_27981 = stack[-2];
    goto v_27810;
v_27847:
    goto v_27855;
v_27851:
    stack[0] = stack[-1];
    goto v_27852;
v_27853:
    v_27981 = stack[-6];
    v_27981 = qcar(v_27981);
    goto v_27866;
v_27862:
    goto v_27874;
v_27868:
    v_27983 = elt(env, 2); // quotient
    goto v_27869;
v_27870:
    v_27982 = stack[-3];
    goto v_27871;
v_27872:
    goto v_27873;
v_27874:
    goto v_27868;
v_27869:
    goto v_27870;
v_27871:
    goto v_27872;
v_27873:
    v_27982 = list3(v_27983, v_27982, v_27981);
    env = stack[-7];
    goto v_27863;
v_27864:
    v_27981 = stack[-4];
    goto v_27865;
v_27866:
    goto v_27862;
v_27863:
    goto v_27864;
v_27865:
    fn = elt(env, 3); // reval1
    v_27981 = (*qfn2(fn))(fn, v_27982, v_27981);
    env = stack[-7];
    v_27981 = ncons(v_27981);
    env = stack[-7];
    goto v_27854;
v_27855:
    goto v_27851;
v_27852:
    goto v_27853;
v_27854:
    v_27981 = Lrplacd(nil, stack[0], v_27981);
    env = stack[-7];
    v_27981 = stack[-1];
    v_27981 = qcdr(v_27981);
    stack[-1] = v_27981;
    goto v_27811;
v_27810:
    goto v_27795;
v_27797:
    goto v_27888;
v_27884:
    v_27982 = stack[-6];
    goto v_27885;
v_27886:
    v_27981 = elt(env, 1); // list
    goto v_27887;
v_27888:
    goto v_27884;
v_27885:
    goto v_27886;
v_27887:
    if (!consp(v_27982)) goto v_27882;
    v_27982 = qcar(v_27982);
    if (v_27982 == v_27981) goto v_27881;
    else goto v_27882;
v_27881:
    goto v_27898;
v_27892:
    v_27981 = stack[-3];
    v_27983 = qcdr(v_27981);
    goto v_27893;
v_27894:
    v_27981 = stack[-6];
    v_27982 = qcdr(v_27981);
    goto v_27895;
v_27896:
    v_27981 = stack[-4];
    goto v_27897;
v_27898:
    goto v_27892;
v_27893:
    goto v_27894;
v_27895:
    goto v_27896;
v_27897:
    fn = elt(env, 4); // listquotient2
    v_27981 = (*qfnn(fn))(fn, 3, v_27983, v_27982, v_27981);
    goto v_27795;
v_27882:
    v_27981 = stack[-3];
    v_27981 = qcdr(v_27981);
    stack[-3] = v_27981;
    v_27981 = stack[-3];
    if (v_27981 == nil) goto v_27916;
    else goto v_27917;
v_27916:
    v_27981 = nil;
    goto v_27910;
v_27917:
    v_27981 = stack[-3];
    v_27981 = qcar(v_27981);
    goto v_27929;
v_27925:
    goto v_27937;
v_27931:
    v_27983 = elt(env, 2); // quotient
    goto v_27932;
v_27933:
    v_27982 = v_27981;
    goto v_27934;
v_27935:
    v_27981 = stack[-6];
    goto v_27936;
v_27937:
    goto v_27931;
v_27932:
    goto v_27933;
v_27934:
    goto v_27935;
v_27936:
    v_27982 = list3(v_27983, v_27982, v_27981);
    env = stack[-7];
    goto v_27926;
v_27927:
    v_27981 = stack[-4];
    goto v_27928;
v_27929:
    goto v_27925;
v_27926:
    goto v_27927;
v_27928:
    fn = elt(env, 3); // reval1
    v_27981 = (*qfn2(fn))(fn, v_27982, v_27981);
    env = stack[-7];
    v_27981 = ncons(v_27981);
    env = stack[-7];
    stack[-1] = v_27981;
    stack[-2] = v_27981;
v_27911:
    v_27981 = stack[-3];
    v_27981 = qcdr(v_27981);
    stack[-3] = v_27981;
    v_27981 = stack[-3];
    if (v_27981 == nil) goto v_27946;
    else goto v_27947;
v_27946:
    v_27981 = stack[-2];
    goto v_27910;
v_27947:
    goto v_27955;
v_27951:
    stack[0] = stack[-1];
    goto v_27952;
v_27953:
    v_27981 = stack[-3];
    v_27981 = qcar(v_27981);
    goto v_27966;
v_27962:
    goto v_27974;
v_27968:
    v_27983 = elt(env, 2); // quotient
    goto v_27969;
v_27970:
    v_27982 = v_27981;
    goto v_27971;
v_27972:
    v_27981 = stack[-6];
    goto v_27973;
v_27974:
    goto v_27968;
v_27969:
    goto v_27970;
v_27971:
    goto v_27972;
v_27973:
    v_27982 = list3(v_27983, v_27982, v_27981);
    env = stack[-7];
    goto v_27963;
v_27964:
    v_27981 = stack[-4];
    goto v_27965;
v_27966:
    goto v_27962;
v_27963:
    goto v_27964;
v_27965:
    fn = elt(env, 3); // reval1
    v_27981 = (*qfn2(fn))(fn, v_27982, v_27981);
    env = stack[-7];
    v_27981 = ncons(v_27981);
    env = stack[-7];
    goto v_27954;
v_27955:
    goto v_27951;
v_27952:
    goto v_27953;
v_27954:
    v_27981 = Lrplacd(nil, stack[0], v_27981);
    env = stack[-7];
    v_27981 = stack[-1];
    v_27981 = qcdr(v_27981);
    stack[-1] = v_27981;
    goto v_27911;
v_27910:
    goto v_27795;
    v_27981 = nil;
v_27795:
    goto v_27791;
v_27792:
    goto v_27788;
v_27789:
    goto v_27790;
v_27791:
    {
        LispObject v_27991 = stack[-5];
        return cons(v_27991, v_27981);
    }
    return onevalue(v_27981);
}



// Code for fs!:prin!:

static LispObject CC_fsTprinT(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27770;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27761;
// end of prologue
    v_27770 = elt(env, 1); // "["
    fn = elt(env, 3); // prin2!*
    v_27770 = (*qfn1(fn))(fn, v_27770);
    env = stack[-1];
    v_27770 = stack[0];
    v_27770 = qcdr(v_27770);
    fn = elt(env, 4); // fs!:prin
    v_27770 = (*qfn1(fn))(fn, v_27770);
    env = stack[-1];
    v_27770 = elt(env, 2); // "]"
    {
        fn = elt(env, 3); // prin2!*
        return (*qfn1(fn))(fn, v_27770);
    }
}



// Code for groeb!=testb

static LispObject CC_groebMtestb(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27872, v_27873;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27762;
    stack[-1] = v_27761;
// end of prologue
    goto v_27772;
v_27768:
    v_27872 = stack[-1];
    fn = elt(env, 1); // mo_comp
    v_27873 = (*qfn1(fn))(fn, v_27872);
    env = stack[-3];
    goto v_27769;
v_27770:
    v_27872 = stack[0];
    v_27872 = qcar(v_27872);
    goto v_27771;
v_27772:
    goto v_27768;
v_27769:
    goto v_27770;
v_27771:
    if (equal(v_27873, v_27872)) goto v_27766;
    else goto v_27767;
v_27766:
    goto v_27786;
v_27782:
    stack[-2] = stack[-1];
    goto v_27783;
v_27784:
    goto v_27793;
v_27789:
    v_27873 = stack[0];
    goto v_27790;
v_27791:
    v_27872 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_27792;
v_27793:
    goto v_27789;
v_27790:
    goto v_27791;
v_27792:
    fn = elt(env, 2); // nth
    v_27872 = (*qfn2(fn))(fn, v_27873, v_27872);
    env = stack[-3];
    goto v_27785;
v_27786:
    goto v_27782;
v_27783:
    goto v_27784;
v_27785:
    fn = elt(env, 3); // mo_divides!?
    v_27872 = (*qfn2(fn))(fn, stack[-2], v_27872);
    env = stack[-3];
    if (v_27872 == nil) goto v_27779;
    else goto v_27780;
v_27779:
    v_27872 = nil;
    goto v_27778;
v_27780:
    goto v_27808;
v_27804:
    goto v_27814;
v_27810:
    goto v_27822;
v_27818:
    v_27873 = stack[0];
    goto v_27819;
v_27820:
    v_27872 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_27821;
v_27822:
    goto v_27818;
v_27819:
    goto v_27820;
v_27821:
    fn = elt(env, 2); // nth
    v_27872 = (*qfn2(fn))(fn, v_27873, v_27872);
    env = stack[-3];
    fn = elt(env, 4); // bas_dpoly
    v_27872 = (*qfn1(fn))(fn, v_27872);
    env = stack[-3];
    fn = elt(env, 5); // dp_lmon
    v_27873 = (*qfn1(fn))(fn, v_27872);
    env = stack[-3];
    goto v_27811;
v_27812:
    v_27872 = stack[-1];
    goto v_27813;
v_27814:
    goto v_27810;
v_27811:
    goto v_27812;
v_27813:
    fn = elt(env, 6); // mo_lcm
    stack[-2] = (*qfn2(fn))(fn, v_27873, v_27872);
    env = stack[-3];
    goto v_27805;
v_27806:
    goto v_27831;
v_27827:
    v_27873 = stack[0];
    goto v_27828;
v_27829:
    v_27872 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_27830;
v_27831:
    goto v_27827;
v_27828:
    goto v_27829;
v_27830:
    fn = elt(env, 2); // nth
    v_27872 = (*qfn2(fn))(fn, v_27873, v_27872);
    env = stack[-3];
    goto v_27807;
v_27808:
    goto v_27804;
v_27805:
    goto v_27806;
v_27807:
    fn = elt(env, 7); // mo_equal!?
    v_27872 = (*qfn2(fn))(fn, stack[-2], v_27872);
    env = stack[-3];
    if (v_27872 == nil) goto v_27801;
    else goto v_27802;
v_27801:
    goto v_27839;
v_27835:
    goto v_27845;
v_27841:
    goto v_27853;
v_27849:
    v_27873 = stack[0];
    goto v_27850;
v_27851:
    v_27872 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_27852;
v_27853:
    goto v_27849;
v_27850:
    goto v_27851;
v_27852:
    fn = elt(env, 2); // nth
    v_27872 = (*qfn2(fn))(fn, v_27873, v_27872);
    env = stack[-3];
    fn = elt(env, 4); // bas_dpoly
    v_27872 = (*qfn1(fn))(fn, v_27872);
    env = stack[-3];
    fn = elt(env, 5); // dp_lmon
    v_27873 = (*qfn1(fn))(fn, v_27872);
    env = stack[-3];
    goto v_27842;
v_27843:
    v_27872 = stack[-1];
    goto v_27844;
v_27845:
    goto v_27841;
v_27842:
    goto v_27843;
v_27844:
    fn = elt(env, 6); // mo_lcm
    stack[-1] = (*qfn2(fn))(fn, v_27873, v_27872);
    env = stack[-3];
    goto v_27836;
v_27837:
    goto v_27862;
v_27858:
    v_27873 = stack[0];
    goto v_27859;
v_27860:
    v_27872 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_27861;
v_27862:
    goto v_27858;
v_27859:
    goto v_27860;
v_27861:
    fn = elt(env, 2); // nth
    v_27872 = (*qfn2(fn))(fn, v_27873, v_27872);
    env = stack[-3];
    goto v_27838;
v_27839:
    goto v_27835;
v_27836:
    goto v_27837;
v_27838:
    fn = elt(env, 7); // mo_equal!?
    v_27872 = (*qfn2(fn))(fn, stack[-1], v_27872);
    v_27872 = (v_27872 == nil ? lisp_true : nil);
    goto v_27800;
v_27802:
    v_27872 = nil;
    goto v_27800;
    v_27872 = nil;
v_27800:
    goto v_27778;
    v_27872 = nil;
v_27778:
    goto v_27765;
v_27767:
    v_27872 = nil;
    goto v_27765;
    v_27872 = nil;
v_27765:
    return onevalue(v_27872);
}



// Code for verify_tens_ids

static LispObject CC_verify_tens_ids(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27815, v_27816;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_27761;
// end of prologue
    v_27815 = stack[-1];
    v_27815 = qcar(v_27815);
    v_27816 = v_27815;
    v_27815 = stack[-1];
    v_27815 = qcdr(v_27815);
    v_27815 = qcar(v_27815);
    stack[0] = v_27815;
    v_27815 = v_27816;
    fn = elt(env, 3); // extract_dummy_ids
    v_27815 = (*qfn1(fn))(fn, v_27815);
    env = stack[-3];
    fn = elt(env, 4); // repeats
    v_27815 = (*qfn1(fn))(fn, v_27815);
    env = stack[-3];
    if (v_27815 == nil) goto v_27776;
    else goto v_27774;
v_27776:
    v_27815 = stack[0];
    fn = elt(env, 3); // extract_dummy_ids
    v_27815 = (*qfn1(fn))(fn, v_27815);
    env = stack[-3];
    fn = elt(env, 4); // repeats
    v_27815 = (*qfn1(fn))(fn, v_27815);
    env = stack[-3];
    if (v_27815 == nil) goto v_27780;
    else goto v_27774;
v_27780:
    goto v_27775;
v_27774:
    goto v_27791;
v_27785:
    stack[-2] = elt(env, 1); // cantens
    goto v_27786;
v_27787:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_27788;
v_27789:
    goto v_27799;
v_27795:
    goto v_27805;
v_27801:
    v_27815 = stack[-1];
    v_27816 = qcar(v_27815);
    goto v_27802;
v_27803:
    v_27815 = stack[-1];
    v_27815 = qcdr(v_27815);
    v_27815 = qcar(v_27815);
    goto v_27804;
v_27805:
    goto v_27801;
v_27802:
    goto v_27803;
v_27804:
    v_27816 = list2(v_27816, v_27815);
    env = stack[-3];
    goto v_27796;
v_27797:
    v_27815 = elt(env, 2); // "are inconsistent lists of indices"
    goto v_27798;
v_27799:
    goto v_27795;
v_27796:
    goto v_27797;
v_27798:
    v_27815 = list2(v_27816, v_27815);
    env = stack[-3];
    goto v_27790;
v_27791:
    goto v_27785;
v_27786:
    goto v_27787;
v_27788:
    goto v_27789;
v_27790:
    fn = elt(env, 5); // rerror
    v_27815 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_27815);
    goto v_27773;
v_27775:
    v_27815 = lisp_true;
    goto v_27766;
v_27773:
    v_27815 = nil;
v_27766:
    return onevalue(v_27815);
}



// Code for nonlnr

static LispObject CC_nonlnr(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27875, v_27876;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27762;
    stack[-1] = v_27761;
// end of prologue
v_27760:
    v_27875 = stack[-1];
    if (!consp(v_27875)) goto v_27770;
    else goto v_27771;
v_27770:
    v_27875 = lisp_true;
    goto v_27769;
v_27771:
    v_27875 = stack[-1];
    v_27875 = qcar(v_27875);
    v_27875 = (consp(v_27875) ? nil : lisp_true);
    goto v_27769;
    v_27875 = nil;
v_27769:
    if (v_27875 == nil) goto v_27767;
    v_27875 = nil;
    goto v_27765;
v_27767:
    goto v_27786;
v_27782:
    v_27875 = stack[-1];
    v_27875 = qcar(v_27875);
    v_27875 = qcar(v_27875);
    v_27876 = qcar(v_27875);
    goto v_27783;
v_27784:
    v_27875 = stack[0];
    goto v_27785;
v_27786:
    goto v_27782;
v_27783:
    goto v_27784;
v_27785:
    v_27875 = Lmember(nil, v_27876, v_27875);
    if (v_27875 == nil) goto v_27781;
    goto v_27801;
v_27797:
    v_27875 = stack[-1];
    v_27875 = qcar(v_27875);
    v_27875 = qcar(v_27875);
    v_27876 = qcdr(v_27875);
    goto v_27798;
v_27799:
    v_27875 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27800;
v_27801:
    goto v_27797;
v_27798:
    goto v_27799;
v_27800:
    v_27875 = (LispObject)greaterp2(v_27876, v_27875);
    v_27875 = v_27875 ? lisp_true : nil;
    env = stack[-2];
    if (v_27875 == nil) goto v_27795;
    else goto v_27794;
v_27795:
    goto v_27816;
v_27812:
    v_27875 = stack[-1];
    v_27875 = qcar(v_27875);
    v_27876 = qcdr(v_27875);
    goto v_27813;
v_27814:
    v_27875 = stack[0];
    goto v_27815;
v_27816:
    goto v_27812;
v_27813:
    goto v_27814;
v_27815:
    fn = elt(env, 1); // freeofl
    v_27875 = (*qfn2(fn))(fn, v_27876, v_27875);
    env = stack[-2];
    if (v_27875 == nil) goto v_27809;
    else goto v_27810;
v_27809:
    v_27875 = lisp_true;
    goto v_27808;
v_27810:
    goto v_27829;
v_27825:
    v_27875 = stack[-1];
    v_27876 = qcdr(v_27875);
    goto v_27826;
v_27827:
    v_27875 = stack[0];
    goto v_27828;
v_27829:
    goto v_27825;
v_27826:
    goto v_27827;
v_27828:
    stack[-1] = v_27876;
    stack[0] = v_27875;
    goto v_27760;
    v_27875 = nil;
v_27808:
v_27794:
    goto v_27765;
v_27781:
    goto v_27844;
v_27840:
    v_27875 = stack[-1];
    v_27875 = qcar(v_27875);
    v_27875 = qcar(v_27875);
    v_27876 = qcar(v_27875);
    goto v_27841;
v_27842:
    v_27875 = stack[0];
    goto v_27843;
v_27844:
    goto v_27840;
v_27841:
    goto v_27842;
v_27843:
    fn = elt(env, 1); // freeofl
    v_27875 = (*qfn2(fn))(fn, v_27876, v_27875);
    env = stack[-2];
    if (v_27875 == nil) goto v_27837;
    else goto v_27838;
v_27837:
    v_27875 = lisp_true;
    goto v_27836;
v_27838:
    goto v_27861;
v_27857:
    v_27875 = stack[-1];
    v_27875 = qcar(v_27875);
    v_27876 = qcdr(v_27875);
    goto v_27858;
v_27859:
    v_27875 = stack[0];
    goto v_27860;
v_27861:
    goto v_27857;
v_27858:
    goto v_27859;
v_27860:
    v_27875 = CC_nonlnr(elt(env, 0), v_27876, v_27875);
    env = stack[-2];
    if (v_27875 == nil) goto v_27855;
    else goto v_27854;
v_27855:
    goto v_27871;
v_27867:
    v_27875 = stack[-1];
    v_27876 = qcdr(v_27875);
    goto v_27868;
v_27869:
    v_27875 = stack[0];
    goto v_27870;
v_27871:
    goto v_27867;
v_27868:
    goto v_27869;
v_27870:
    stack[-1] = v_27876;
    stack[0] = v_27875;
    goto v_27760;
v_27854:
    goto v_27836;
    v_27875 = nil;
v_27836:
    goto v_27765;
    v_27875 = nil;
v_27765:
    return onevalue(v_27875);
}



// Code for bfminus

static LispObject CC_bfminus(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27774, v_27775;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27775 = v_27761;
// end of prologue
    v_27774 = v_27775;
    if (!consp(v_27774)) goto v_27765;
    else goto v_27766;
v_27765:
    v_27774 = v_27775;
    return negate(v_27774);
v_27766:
    v_27774 = v_27775;
    {
        fn = elt(env, 1); // minus!:
        return (*qfn1(fn))(fn, v_27774);
    }
    v_27774 = nil;
    return onevalue(v_27774);
}



// Code for no_of_tm_sf_limited

static LispObject CC_no_of_tm_sf_limited(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27832, v_27833;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27762;
    stack[-1] = v_27761;
// end of prologue
    v_27832 = stack[-1];
    if (v_27832 == nil) goto v_27766;
    else goto v_27767;
v_27766:
    v_27832 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27765;
v_27767:
    v_27832 = stack[-1];
    v_27832 = Lconsp(nil, v_27832);
    env = stack[-3];
    if (v_27832 == nil) goto v_27774;
    else goto v_27775;
v_27774:
    v_27832 = lisp_true;
    goto v_27773;
v_27775:
    v_27832 = stack[-1];
    v_27832 = qcar(v_27832);
    v_27832 = Lconsp(nil, v_27832);
    env = stack[-3];
    v_27832 = (v_27832 == nil ? lisp_true : nil);
    goto v_27773;
    v_27832 = nil;
v_27773:
    if (v_27832 == nil) goto v_27771;
    v_27832 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27765;
v_27771:
    goto v_27796;
v_27792:
    v_27832 = stack[-1];
    v_27832 = qcar(v_27832);
    v_27833 = qcdr(v_27832);
    goto v_27793;
v_27794:
    v_27832 = stack[0];
    goto v_27795;
v_27796:
    goto v_27792;
v_27793:
    goto v_27794;
v_27795:
    v_27832 = CC_no_of_tm_sf_limited(elt(env, 0), v_27833, v_27832);
    env = stack[-3];
    stack[-2] = v_27832;
    goto v_27810;
v_27806:
    v_27833 = stack[-2];
    goto v_27807;
v_27808:
    v_27832 = stack[0];
    goto v_27809;
v_27810:
    goto v_27806;
v_27807:
    goto v_27808;
v_27809:
    v_27832 = (LispObject)greaterp2(v_27833, v_27832);
    v_27832 = v_27832 ? lisp_true : nil;
    env = stack[-3];
    if (v_27832 == nil) goto v_27804;
    v_27832 = stack[-2];
    goto v_27802;
v_27804:
    goto v_27821;
v_27817:
    goto v_27818;
v_27819:
    goto v_27828;
v_27824:
    v_27832 = stack[-1];
    v_27833 = qcdr(v_27832);
    goto v_27825;
v_27826:
    v_27832 = stack[0];
    goto v_27827;
v_27828:
    goto v_27824;
v_27825:
    goto v_27826;
v_27827:
    v_27832 = CC_no_of_tm_sf_limited(elt(env, 0), v_27833, v_27832);
    goto v_27820;
v_27821:
    goto v_27817;
v_27818:
    goto v_27819;
v_27820:
    {
        LispObject v_27837 = stack[-2];
        return plus2(v_27837, v_27832);
    }
    v_27832 = nil;
v_27802:
    goto v_27765;
    v_27832 = nil;
v_27765:
    return onevalue(v_27832);
}



// Code for dfdeg

static LispObject CC_dfdeg(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27799, v_27800;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27799 = v_27762;
    v_27800 = v_27761;
// end of prologue
    goto v_27772;
v_27768:
    goto v_27769;
v_27770:
    goto v_27771;
v_27772:
    goto v_27768;
v_27769:
    goto v_27770;
v_27771:
    v_27799 = Lmember(nil, v_27799, v_27800);
    v_27800 = v_27799;
    if (v_27799 == nil) goto v_27766;
    else goto v_27767;
v_27766:
    v_27799 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27765;
v_27767:
    v_27799 = v_27800;
    v_27799 = qcdr(v_27799);
    if (v_27799 == nil) goto v_27781;
    else goto v_27782;
v_27781:
    v_27799 = lisp_true;
    goto v_27780;
v_27782:
    v_27799 = v_27800;
    v_27799 = qcdr(v_27799);
    v_27799 = qcar(v_27799);
    v_27799 = integerp(v_27799);
    v_27799 = (v_27799 == nil ? lisp_true : nil);
    goto v_27780;
    v_27799 = nil;
v_27780:
    if (v_27799 == nil) goto v_27778;
    v_27799 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27765;
v_27778:
    v_27799 = v_27800;
    v_27799 = qcdr(v_27799);
    v_27799 = qcar(v_27799);
    goto v_27765;
    v_27799 = nil;
v_27765:
    return onevalue(v_27799);
}



// Code for makecoeffpairs

static LispObject CC_makecoeffpairs(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27782, v_27783, v_27784, v_27785;
    LispObject fn;
    LispObject v_27764, v_27763, v_27762, v_27761;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "makecoeffpairs");
    va_start(aa, nargs);
    v_27761 = va_arg(aa, LispObject);
    v_27762 = va_arg(aa, LispObject);
    v_27763 = va_arg(aa, LispObject);
    v_27764 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_27764,v_27763,v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_27761,v_27762,v_27763,v_27764);
    }
// copy arguments values to proper place
    v_27782 = v_27764;
    v_27783 = v_27763;
    v_27784 = v_27762;
    v_27785 = v_27761;
// end of prologue
    goto v_27776;
v_27768:
    goto v_27769;
v_27770:
    goto v_27771;
v_27772:
    goto v_27773;
v_27774:
    goto v_27775;
v_27776:
    goto v_27768;
v_27769:
    goto v_27770;
v_27771:
    goto v_27772;
v_27773:
    goto v_27774;
v_27775:
    fn = elt(env, 1); // makecoeffpairs1
    v_27782 = (*qfnn(fn))(fn, 4, v_27785, v_27784, v_27783, v_27782);
    v_27782 = qcdr(v_27782);
        return Lnreverse(nil, v_27782);
}



// Code for cl_sordp

static LispObject CC_cl_sordp(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_29150, v_29151, v_29152, v_29153;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27762;
    stack[-1] = v_27761;
// end of prologue
v_27760:
    v_29150 = stack[-1];
    if (!consp(v_29150)) goto v_27770;
    else goto v_27771;
v_27770:
    v_29150 = stack[-1];
    goto v_27769;
v_27771:
    v_29150 = stack[-1];
    v_29150 = qcar(v_29150);
    goto v_27769;
    v_29150 = nil;
v_27769:
    v_29153 = v_29150;
    v_29150 = stack[0];
    if (!consp(v_29150)) goto v_27780;
    else goto v_27781;
v_27780:
    v_29150 = stack[0];
    goto v_27779;
v_27781:
    v_29150 = stack[0];
    v_29150 = qcar(v_29150);
    goto v_27779;
    v_29150 = nil;
v_27779:
    v_29152 = v_29150;
    goto v_27808;
v_27804:
    v_29151 = v_29153;
    goto v_27805;
v_27806:
    v_29150 = elt(env, 1); // true
    goto v_27807;
v_27808:
    goto v_27804;
v_27805:
    goto v_27806;
v_27807:
    if (v_29151 == v_29150) goto v_27802;
    else goto v_27803;
v_27802:
    v_29150 = lisp_true;
    goto v_27801;
v_27803:
    goto v_27818;
v_27814:
    v_29151 = v_29153;
    goto v_27815;
v_27816:
    v_29150 = elt(env, 2); // false
    goto v_27817;
v_27818:
    goto v_27814;
v_27815:
    goto v_27816;
v_27817:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_27801;
    v_29150 = nil;
v_27801:
    if (v_29150 == nil) goto v_27799;
    v_29150 = lisp_true;
    goto v_27797;
v_27799:
    goto v_27845;
v_27841:
    v_29151 = v_29153;
    goto v_27842;
v_27843:
    v_29150 = elt(env, 3); // or
    goto v_27844;
v_27845:
    goto v_27841;
v_27842:
    goto v_27843;
v_27844:
    if (v_29151 == v_29150) goto v_27839;
    else goto v_27840;
v_27839:
    v_29150 = lisp_true;
    goto v_27838;
v_27840:
    goto v_27855;
v_27851:
    v_29151 = v_29153;
    goto v_27852;
v_27853:
    v_29150 = elt(env, 4); // and
    goto v_27854;
v_27855:
    goto v_27851;
v_27852:
    goto v_27853;
v_27854:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_27838;
    v_29150 = nil;
v_27838:
    if (v_29150 == nil) goto v_27836;
    v_29150 = lisp_true;
    goto v_27834;
v_27836:
    goto v_27866;
v_27862:
    v_29151 = v_29153;
    goto v_27863;
v_27864:
    v_29150 = elt(env, 5); // not
    goto v_27865;
v_27866:
    goto v_27862;
v_27863:
    goto v_27864;
v_27865:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_27834;
    v_29150 = nil;
v_27834:
    if (v_29150 == nil) goto v_27832;
    v_29150 = lisp_true;
    goto v_27830;
v_27832:
    goto v_27881;
v_27877:
    v_29151 = v_29153;
    goto v_27878;
v_27879:
    v_29150 = elt(env, 6); // impl
    goto v_27880;
v_27881:
    goto v_27877;
v_27878:
    goto v_27879;
v_27880:
    if (v_29151 == v_29150) goto v_27875;
    else goto v_27876;
v_27875:
    v_29150 = lisp_true;
    goto v_27874;
v_27876:
    goto v_27895;
v_27891:
    v_29151 = v_29153;
    goto v_27892;
v_27893:
    v_29150 = elt(env, 7); // repl
    goto v_27894;
v_27895:
    goto v_27891;
v_27892:
    goto v_27893;
v_27894:
    if (v_29151 == v_29150) goto v_27889;
    else goto v_27890;
v_27889:
    v_29150 = lisp_true;
    goto v_27888;
v_27890:
    goto v_27905;
v_27901:
    v_29151 = v_29153;
    goto v_27902;
v_27903:
    v_29150 = elt(env, 8); // equiv
    goto v_27904;
v_27905:
    goto v_27901;
v_27902:
    goto v_27903;
v_27904:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_27888;
    v_29150 = nil;
v_27888:
    goto v_27874;
    v_29150 = nil;
v_27874:
    goto v_27830;
    v_29150 = nil;
v_27830:
    if (v_29150 == nil) goto v_27828;
    v_29150 = lisp_true;
    goto v_27826;
v_27828:
    goto v_27924;
v_27920:
    v_29151 = v_29153;
    goto v_27921;
v_27922:
    v_29150 = elt(env, 9); // ex
    goto v_27923;
v_27924:
    goto v_27920;
v_27921:
    goto v_27922;
v_27923:
    if (v_29151 == v_29150) goto v_27918;
    else goto v_27919;
v_27918:
    v_29150 = lisp_true;
    goto v_27917;
v_27919:
    goto v_27934;
v_27930:
    v_29151 = v_29153;
    goto v_27931;
v_27932:
    v_29150 = elt(env, 10); // all
    goto v_27933;
v_27934:
    goto v_27930;
v_27931:
    goto v_27932;
v_27933:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_27917;
    v_29150 = nil;
v_27917:
    if (v_29150 == nil) goto v_27915;
    v_29150 = lisp_true;
    goto v_27913;
v_27915:
    goto v_27953;
v_27949:
    v_29151 = v_29153;
    goto v_27950;
v_27951:
    v_29150 = elt(env, 11); // bex
    goto v_27952;
v_27953:
    goto v_27949;
v_27950:
    goto v_27951;
v_27952:
    if (v_29151 == v_29150) goto v_27947;
    else goto v_27948;
v_27947:
    v_29150 = lisp_true;
    goto v_27946;
v_27948:
    goto v_27963;
v_27959:
    v_29151 = v_29153;
    goto v_27960;
v_27961:
    v_29150 = elt(env, 12); // ball
    goto v_27962;
v_27963:
    goto v_27959;
v_27960:
    goto v_27961;
v_27962:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_27946;
    v_29150 = nil;
v_27946:
    if (v_29150 == nil) goto v_27944;
    v_29150 = lisp_true;
    goto v_27942;
v_27944:
    v_29150 = v_29153;
    if (!symbolp(v_29150)) v_29150 = nil;
    else { v_29150 = qfastgets(v_29150);
           if (v_29150 != nil) { v_29150 = elt(v_29150, 21); // rl_external
#ifdef RECORD_GET
             if (v_29150 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_29150 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_29150 == SPID_NOPROP) v_29150 = nil; }}
#endif
    goto v_27942;
    v_29150 = nil;
v_27942:
    goto v_27913;
    v_29150 = nil;
v_27913:
    goto v_27826;
    v_29150 = nil;
v_27826:
    goto v_27797;
    v_29150 = nil;
v_27797:
    if (v_29150 == nil) goto v_27794;
    else goto v_27795;
v_27794:
    goto v_27984;
v_27980:
    v_29151 = v_29152;
    goto v_27981;
v_27982:
    v_29150 = elt(env, 1); // true
    goto v_27983;
v_27984:
    goto v_27980;
v_27981:
    goto v_27982;
v_27983:
    if (v_29151 == v_29150) goto v_27978;
    else goto v_27979;
v_27978:
    v_29150 = lisp_true;
    goto v_27977;
v_27979:
    goto v_27994;
v_27990:
    v_29151 = v_29152;
    goto v_27991;
v_27992:
    v_29150 = elt(env, 2); // false
    goto v_27993;
v_27994:
    goto v_27990;
v_27991:
    goto v_27992;
v_27993:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_27977;
    v_29150 = nil;
v_27977:
    if (v_29150 == nil) goto v_27975;
    v_29150 = lisp_true;
    goto v_27973;
v_27975:
    goto v_28021;
v_28017:
    v_29151 = v_29152;
    goto v_28018;
v_28019:
    v_29150 = elt(env, 3); // or
    goto v_28020;
v_28021:
    goto v_28017;
v_28018:
    goto v_28019;
v_28020:
    if (v_29151 == v_29150) goto v_28015;
    else goto v_28016;
v_28015:
    v_29150 = lisp_true;
    goto v_28014;
v_28016:
    goto v_28031;
v_28027:
    v_29151 = v_29152;
    goto v_28028;
v_28029:
    v_29150 = elt(env, 4); // and
    goto v_28030;
v_28031:
    goto v_28027;
v_28028:
    goto v_28029;
v_28030:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28014;
    v_29150 = nil;
v_28014:
    if (v_29150 == nil) goto v_28012;
    v_29150 = lisp_true;
    goto v_28010;
v_28012:
    goto v_28042;
v_28038:
    v_29151 = v_29152;
    goto v_28039;
v_28040:
    v_29150 = elt(env, 5); // not
    goto v_28041;
v_28042:
    goto v_28038;
v_28039:
    goto v_28040;
v_28041:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28010;
    v_29150 = nil;
v_28010:
    if (v_29150 == nil) goto v_28008;
    v_29150 = lisp_true;
    goto v_28006;
v_28008:
    goto v_28057;
v_28053:
    v_29151 = v_29152;
    goto v_28054;
v_28055:
    v_29150 = elt(env, 6); // impl
    goto v_28056;
v_28057:
    goto v_28053;
v_28054:
    goto v_28055;
v_28056:
    if (v_29151 == v_29150) goto v_28051;
    else goto v_28052;
v_28051:
    v_29150 = lisp_true;
    goto v_28050;
v_28052:
    goto v_28071;
v_28067:
    v_29151 = v_29152;
    goto v_28068;
v_28069:
    v_29150 = elt(env, 7); // repl
    goto v_28070;
v_28071:
    goto v_28067;
v_28068:
    goto v_28069;
v_28070:
    if (v_29151 == v_29150) goto v_28065;
    else goto v_28066;
v_28065:
    v_29150 = lisp_true;
    goto v_28064;
v_28066:
    goto v_28081;
v_28077:
    v_29151 = v_29152;
    goto v_28078;
v_28079:
    v_29150 = elt(env, 8); // equiv
    goto v_28080;
v_28081:
    goto v_28077;
v_28078:
    goto v_28079;
v_28080:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28064;
    v_29150 = nil;
v_28064:
    goto v_28050;
    v_29150 = nil;
v_28050:
    goto v_28006;
    v_29150 = nil;
v_28006:
    if (v_29150 == nil) goto v_28004;
    v_29150 = lisp_true;
    goto v_28002;
v_28004:
    goto v_28100;
v_28096:
    v_29151 = v_29152;
    goto v_28097;
v_28098:
    v_29150 = elt(env, 9); // ex
    goto v_28099;
v_28100:
    goto v_28096;
v_28097:
    goto v_28098;
v_28099:
    if (v_29151 == v_29150) goto v_28094;
    else goto v_28095;
v_28094:
    v_29150 = lisp_true;
    goto v_28093;
v_28095:
    goto v_28110;
v_28106:
    v_29151 = v_29152;
    goto v_28107;
v_28108:
    v_29150 = elt(env, 10); // all
    goto v_28109;
v_28110:
    goto v_28106;
v_28107:
    goto v_28108;
v_28109:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28093;
    v_29150 = nil;
v_28093:
    if (v_29150 == nil) goto v_28091;
    v_29150 = lisp_true;
    goto v_28089;
v_28091:
    goto v_28129;
v_28125:
    v_29151 = v_29152;
    goto v_28126;
v_28127:
    v_29150 = elt(env, 11); // bex
    goto v_28128;
v_28129:
    goto v_28125;
v_28126:
    goto v_28127;
v_28128:
    if (v_29151 == v_29150) goto v_28123;
    else goto v_28124;
v_28123:
    v_29150 = lisp_true;
    goto v_28122;
v_28124:
    goto v_28139;
v_28135:
    v_29151 = v_29152;
    goto v_28136;
v_28137:
    v_29150 = elt(env, 12); // ball
    goto v_28138;
v_28139:
    goto v_28135;
v_28136:
    goto v_28137;
v_28138:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28122;
    v_29150 = nil;
v_28122:
    if (v_29150 == nil) goto v_28120;
    v_29150 = lisp_true;
    goto v_28118;
v_28120:
    v_29150 = v_29152;
    if (!symbolp(v_29150)) v_29150 = nil;
    else { v_29150 = qfastgets(v_29150);
           if (v_29150 != nil) { v_29150 = elt(v_29150, 21); // rl_external
#ifdef RECORD_GET
             if (v_29150 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_29150 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_29150 == SPID_NOPROP) v_29150 = nil; }}
#endif
    goto v_28118;
    v_29150 = nil;
v_28118:
    goto v_28089;
    v_29150 = nil;
v_28089:
    goto v_28002;
    v_29150 = nil;
v_28002:
    goto v_27973;
    v_29150 = nil;
v_27973:
    v_29150 = (v_29150 == nil ? lisp_true : nil);
    goto v_27793;
v_27795:
    v_29150 = nil;
    goto v_27793;
    v_29150 = nil;
v_27793:
    if (v_29150 == nil) goto v_27791;
    goto v_28157;
v_28153:
    v_29151 = stack[-1];
    goto v_28154;
v_28155:
    v_29150 = stack[0];
    goto v_28156;
v_28157:
    goto v_28153;
v_28154:
    goto v_28155;
v_28156:
    {
        fn = elt(env, 13); // rl_ordatp
        return (*qfn2(fn))(fn, v_29151, v_29150);
    }
v_27791:
    goto v_28180;
v_28176:
    v_29151 = v_29153;
    goto v_28177;
v_28178:
    v_29150 = elt(env, 1); // true
    goto v_28179;
v_28180:
    goto v_28176;
v_28177:
    goto v_28178;
v_28179:
    if (v_29151 == v_29150) goto v_28174;
    else goto v_28175;
v_28174:
    v_29150 = lisp_true;
    goto v_28173;
v_28175:
    goto v_28190;
v_28186:
    v_29151 = v_29153;
    goto v_28187;
v_28188:
    v_29150 = elt(env, 2); // false
    goto v_28189;
v_28190:
    goto v_28186;
v_28187:
    goto v_28188;
v_28189:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28173;
    v_29150 = nil;
v_28173:
    if (v_29150 == nil) goto v_28171;
    v_29150 = lisp_true;
    goto v_28169;
v_28171:
    goto v_28217;
v_28213:
    v_29151 = v_29153;
    goto v_28214;
v_28215:
    v_29150 = elt(env, 3); // or
    goto v_28216;
v_28217:
    goto v_28213;
v_28214:
    goto v_28215;
v_28216:
    if (v_29151 == v_29150) goto v_28211;
    else goto v_28212;
v_28211:
    v_29150 = lisp_true;
    goto v_28210;
v_28212:
    goto v_28227;
v_28223:
    v_29151 = v_29153;
    goto v_28224;
v_28225:
    v_29150 = elt(env, 4); // and
    goto v_28226;
v_28227:
    goto v_28223;
v_28224:
    goto v_28225;
v_28226:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28210;
    v_29150 = nil;
v_28210:
    if (v_29150 == nil) goto v_28208;
    v_29150 = lisp_true;
    goto v_28206;
v_28208:
    goto v_28238;
v_28234:
    v_29151 = v_29153;
    goto v_28235;
v_28236:
    v_29150 = elt(env, 5); // not
    goto v_28237;
v_28238:
    goto v_28234;
v_28235:
    goto v_28236;
v_28237:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28206;
    v_29150 = nil;
v_28206:
    if (v_29150 == nil) goto v_28204;
    v_29150 = lisp_true;
    goto v_28202;
v_28204:
    goto v_28253;
v_28249:
    v_29151 = v_29153;
    goto v_28250;
v_28251:
    v_29150 = elt(env, 6); // impl
    goto v_28252;
v_28253:
    goto v_28249;
v_28250:
    goto v_28251;
v_28252:
    if (v_29151 == v_29150) goto v_28247;
    else goto v_28248;
v_28247:
    v_29150 = lisp_true;
    goto v_28246;
v_28248:
    goto v_28267;
v_28263:
    v_29151 = v_29153;
    goto v_28264;
v_28265:
    v_29150 = elt(env, 7); // repl
    goto v_28266;
v_28267:
    goto v_28263;
v_28264:
    goto v_28265;
v_28266:
    if (v_29151 == v_29150) goto v_28261;
    else goto v_28262;
v_28261:
    v_29150 = lisp_true;
    goto v_28260;
v_28262:
    goto v_28277;
v_28273:
    v_29151 = v_29153;
    goto v_28274;
v_28275:
    v_29150 = elt(env, 8); // equiv
    goto v_28276;
v_28277:
    goto v_28273;
v_28274:
    goto v_28275;
v_28276:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28260;
    v_29150 = nil;
v_28260:
    goto v_28246;
    v_29150 = nil;
v_28246:
    goto v_28202;
    v_29150 = nil;
v_28202:
    if (v_29150 == nil) goto v_28200;
    v_29150 = lisp_true;
    goto v_28198;
v_28200:
    goto v_28296;
v_28292:
    v_29151 = v_29153;
    goto v_28293;
v_28294:
    v_29150 = elt(env, 9); // ex
    goto v_28295;
v_28296:
    goto v_28292;
v_28293:
    goto v_28294;
v_28295:
    if (v_29151 == v_29150) goto v_28290;
    else goto v_28291;
v_28290:
    v_29150 = lisp_true;
    goto v_28289;
v_28291:
    goto v_28306;
v_28302:
    v_29151 = v_29153;
    goto v_28303;
v_28304:
    v_29150 = elt(env, 10); // all
    goto v_28305;
v_28306:
    goto v_28302;
v_28303:
    goto v_28304;
v_28305:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28289;
    v_29150 = nil;
v_28289:
    if (v_29150 == nil) goto v_28287;
    v_29150 = lisp_true;
    goto v_28285;
v_28287:
    goto v_28325;
v_28321:
    v_29151 = v_29153;
    goto v_28322;
v_28323:
    v_29150 = elt(env, 11); // bex
    goto v_28324;
v_28325:
    goto v_28321;
v_28322:
    goto v_28323;
v_28324:
    if (v_29151 == v_29150) goto v_28319;
    else goto v_28320;
v_28319:
    v_29150 = lisp_true;
    goto v_28318;
v_28320:
    goto v_28335;
v_28331:
    v_29151 = v_29153;
    goto v_28332;
v_28333:
    v_29150 = elt(env, 12); // ball
    goto v_28334;
v_28335:
    goto v_28331;
v_28332:
    goto v_28333;
v_28334:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28318;
    v_29150 = nil;
v_28318:
    if (v_29150 == nil) goto v_28316;
    v_29150 = lisp_true;
    goto v_28314;
v_28316:
    v_29150 = v_29153;
    if (!symbolp(v_29150)) v_29150 = nil;
    else { v_29150 = qfastgets(v_29150);
           if (v_29150 != nil) { v_29150 = elt(v_29150, 21); // rl_external
#ifdef RECORD_GET
             if (v_29150 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_29150 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_29150 == SPID_NOPROP) v_29150 = nil; }}
#endif
    goto v_28314;
    v_29150 = nil;
v_28314:
    goto v_28285;
    v_29150 = nil;
v_28285:
    goto v_28198;
    v_29150 = nil;
v_28198:
    goto v_28169;
    v_29150 = nil;
v_28169:
    if (v_29150 == nil) goto v_28166;
    else goto v_28167;
v_28166:
    goto v_28356;
v_28352:
    v_29151 = v_29152;
    goto v_28353;
v_28354:
    v_29150 = elt(env, 1); // true
    goto v_28355;
v_28356:
    goto v_28352;
v_28353:
    goto v_28354;
v_28355:
    if (v_29151 == v_29150) goto v_28350;
    else goto v_28351;
v_28350:
    v_29150 = lisp_true;
    goto v_28349;
v_28351:
    goto v_28366;
v_28362:
    v_29151 = v_29152;
    goto v_28363;
v_28364:
    v_29150 = elt(env, 2); // false
    goto v_28365;
v_28366:
    goto v_28362;
v_28363:
    goto v_28364;
v_28365:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28349;
    v_29150 = nil;
v_28349:
    if (v_29150 == nil) goto v_28347;
    v_29150 = lisp_true;
    goto v_28345;
v_28347:
    goto v_28393;
v_28389:
    v_29151 = v_29152;
    goto v_28390;
v_28391:
    v_29150 = elt(env, 3); // or
    goto v_28392;
v_28393:
    goto v_28389;
v_28390:
    goto v_28391;
v_28392:
    if (v_29151 == v_29150) goto v_28387;
    else goto v_28388;
v_28387:
    v_29150 = lisp_true;
    goto v_28386;
v_28388:
    goto v_28403;
v_28399:
    v_29151 = v_29152;
    goto v_28400;
v_28401:
    v_29150 = elt(env, 4); // and
    goto v_28402;
v_28403:
    goto v_28399;
v_28400:
    goto v_28401;
v_28402:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28386;
    v_29150 = nil;
v_28386:
    if (v_29150 == nil) goto v_28384;
    v_29150 = lisp_true;
    goto v_28382;
v_28384:
    goto v_28414;
v_28410:
    v_29151 = v_29152;
    goto v_28411;
v_28412:
    v_29150 = elt(env, 5); // not
    goto v_28413;
v_28414:
    goto v_28410;
v_28411:
    goto v_28412;
v_28413:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28382;
    v_29150 = nil;
v_28382:
    if (v_29150 == nil) goto v_28380;
    v_29150 = lisp_true;
    goto v_28378;
v_28380:
    goto v_28429;
v_28425:
    v_29151 = v_29152;
    goto v_28426;
v_28427:
    v_29150 = elt(env, 6); // impl
    goto v_28428;
v_28429:
    goto v_28425;
v_28426:
    goto v_28427;
v_28428:
    if (v_29151 == v_29150) goto v_28423;
    else goto v_28424;
v_28423:
    v_29150 = lisp_true;
    goto v_28422;
v_28424:
    goto v_28443;
v_28439:
    v_29151 = v_29152;
    goto v_28440;
v_28441:
    v_29150 = elt(env, 7); // repl
    goto v_28442;
v_28443:
    goto v_28439;
v_28440:
    goto v_28441;
v_28442:
    if (v_29151 == v_29150) goto v_28437;
    else goto v_28438;
v_28437:
    v_29150 = lisp_true;
    goto v_28436;
v_28438:
    goto v_28453;
v_28449:
    v_29151 = v_29152;
    goto v_28450;
v_28451:
    v_29150 = elt(env, 8); // equiv
    goto v_28452;
v_28453:
    goto v_28449;
v_28450:
    goto v_28451;
v_28452:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28436;
    v_29150 = nil;
v_28436:
    goto v_28422;
    v_29150 = nil;
v_28422:
    goto v_28378;
    v_29150 = nil;
v_28378:
    if (v_29150 == nil) goto v_28376;
    v_29150 = lisp_true;
    goto v_28374;
v_28376:
    goto v_28472;
v_28468:
    v_29151 = v_29152;
    goto v_28469;
v_28470:
    v_29150 = elt(env, 9); // ex
    goto v_28471;
v_28472:
    goto v_28468;
v_28469:
    goto v_28470;
v_28471:
    if (v_29151 == v_29150) goto v_28466;
    else goto v_28467;
v_28466:
    v_29150 = lisp_true;
    goto v_28465;
v_28467:
    goto v_28482;
v_28478:
    v_29151 = v_29152;
    goto v_28479;
v_28480:
    v_29150 = elt(env, 10); // all
    goto v_28481;
v_28482:
    goto v_28478;
v_28479:
    goto v_28480;
v_28481:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28465;
    v_29150 = nil;
v_28465:
    if (v_29150 == nil) goto v_28463;
    v_29150 = lisp_true;
    goto v_28461;
v_28463:
    goto v_28501;
v_28497:
    v_29151 = v_29152;
    goto v_28498;
v_28499:
    v_29150 = elt(env, 11); // bex
    goto v_28500;
v_28501:
    goto v_28497;
v_28498:
    goto v_28499;
v_28500:
    if (v_29151 == v_29150) goto v_28495;
    else goto v_28496;
v_28495:
    v_29150 = lisp_true;
    goto v_28494;
v_28496:
    goto v_28511;
v_28507:
    v_29151 = v_29152;
    goto v_28508;
v_28509:
    v_29150 = elt(env, 12); // ball
    goto v_28510;
v_28511:
    goto v_28507;
v_28508:
    goto v_28509;
v_28510:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28494;
    v_29150 = nil;
v_28494:
    if (v_29150 == nil) goto v_28492;
    v_29150 = lisp_true;
    goto v_28490;
v_28492:
    v_29150 = v_29152;
    if (!symbolp(v_29150)) v_29150 = nil;
    else { v_29150 = qfastgets(v_29150);
           if (v_29150 != nil) { v_29150 = elt(v_29150, 21); // rl_external
#ifdef RECORD_GET
             if (v_29150 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_29150 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_29150 == SPID_NOPROP) v_29150 = nil; }}
#endif
    goto v_28490;
    v_29150 = nil;
v_28490:
    goto v_28461;
    v_29150 = nil;
v_28461:
    goto v_28374;
    v_29150 = nil;
v_28374:
    goto v_28345;
    v_29150 = nil;
v_28345:
    goto v_28165;
v_28167:
    v_29150 = nil;
    goto v_28165;
    v_29150 = nil;
v_28165:
    if (v_29150 == nil) goto v_28163;
    v_29150 = lisp_true;
    goto v_27767;
v_28163:
    goto v_28541;
v_28537:
    v_29151 = v_29153;
    goto v_28538;
v_28539:
    v_29150 = elt(env, 1); // true
    goto v_28540;
v_28541:
    goto v_28537;
v_28538:
    goto v_28539;
v_28540:
    if (v_29151 == v_29150) goto v_28535;
    else goto v_28536;
v_28535:
    v_29150 = lisp_true;
    goto v_28534;
v_28536:
    goto v_28551;
v_28547:
    v_29151 = v_29153;
    goto v_28548;
v_28549:
    v_29150 = elt(env, 2); // false
    goto v_28550;
v_28551:
    goto v_28547;
v_28548:
    goto v_28549;
v_28550:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28534;
    v_29150 = nil;
v_28534:
    if (v_29150 == nil) goto v_28532;
    v_29150 = lisp_true;
    goto v_28530;
v_28532:
    goto v_28578;
v_28574:
    v_29151 = v_29153;
    goto v_28575;
v_28576:
    v_29150 = elt(env, 3); // or
    goto v_28577;
v_28578:
    goto v_28574;
v_28575:
    goto v_28576;
v_28577:
    if (v_29151 == v_29150) goto v_28572;
    else goto v_28573;
v_28572:
    v_29150 = lisp_true;
    goto v_28571;
v_28573:
    goto v_28588;
v_28584:
    v_29151 = v_29153;
    goto v_28585;
v_28586:
    v_29150 = elt(env, 4); // and
    goto v_28587;
v_28588:
    goto v_28584;
v_28585:
    goto v_28586;
v_28587:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28571;
    v_29150 = nil;
v_28571:
    if (v_29150 == nil) goto v_28569;
    v_29150 = lisp_true;
    goto v_28567;
v_28569:
    goto v_28599;
v_28595:
    v_29151 = v_29153;
    goto v_28596;
v_28597:
    v_29150 = elt(env, 5); // not
    goto v_28598;
v_28599:
    goto v_28595;
v_28596:
    goto v_28597;
v_28598:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28567;
    v_29150 = nil;
v_28567:
    if (v_29150 == nil) goto v_28565;
    v_29150 = lisp_true;
    goto v_28563;
v_28565:
    goto v_28614;
v_28610:
    v_29151 = v_29153;
    goto v_28611;
v_28612:
    v_29150 = elt(env, 6); // impl
    goto v_28613;
v_28614:
    goto v_28610;
v_28611:
    goto v_28612;
v_28613:
    if (v_29151 == v_29150) goto v_28608;
    else goto v_28609;
v_28608:
    v_29150 = lisp_true;
    goto v_28607;
v_28609:
    goto v_28628;
v_28624:
    v_29151 = v_29153;
    goto v_28625;
v_28626:
    v_29150 = elt(env, 7); // repl
    goto v_28627;
v_28628:
    goto v_28624;
v_28625:
    goto v_28626;
v_28627:
    if (v_29151 == v_29150) goto v_28622;
    else goto v_28623;
v_28622:
    v_29150 = lisp_true;
    goto v_28621;
v_28623:
    goto v_28638;
v_28634:
    v_29151 = v_29153;
    goto v_28635;
v_28636:
    v_29150 = elt(env, 8); // equiv
    goto v_28637;
v_28638:
    goto v_28634;
v_28635:
    goto v_28636;
v_28637:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28621;
    v_29150 = nil;
v_28621:
    goto v_28607;
    v_29150 = nil;
v_28607:
    goto v_28563;
    v_29150 = nil;
v_28563:
    if (v_29150 == nil) goto v_28561;
    v_29150 = lisp_true;
    goto v_28559;
v_28561:
    goto v_28657;
v_28653:
    v_29151 = v_29153;
    goto v_28654;
v_28655:
    v_29150 = elt(env, 9); // ex
    goto v_28656;
v_28657:
    goto v_28653;
v_28654:
    goto v_28655;
v_28656:
    if (v_29151 == v_29150) goto v_28651;
    else goto v_28652;
v_28651:
    v_29150 = lisp_true;
    goto v_28650;
v_28652:
    goto v_28667;
v_28663:
    v_29151 = v_29153;
    goto v_28664;
v_28665:
    v_29150 = elt(env, 10); // all
    goto v_28666;
v_28667:
    goto v_28663;
v_28664:
    goto v_28665;
v_28666:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28650;
    v_29150 = nil;
v_28650:
    if (v_29150 == nil) goto v_28648;
    v_29150 = lisp_true;
    goto v_28646;
v_28648:
    goto v_28686;
v_28682:
    v_29151 = v_29153;
    goto v_28683;
v_28684:
    v_29150 = elt(env, 11); // bex
    goto v_28685;
v_28686:
    goto v_28682;
v_28683:
    goto v_28684;
v_28685:
    if (v_29151 == v_29150) goto v_28680;
    else goto v_28681;
v_28680:
    v_29150 = lisp_true;
    goto v_28679;
v_28681:
    goto v_28696;
v_28692:
    v_29151 = v_29153;
    goto v_28693;
v_28694:
    v_29150 = elt(env, 12); // ball
    goto v_28695;
v_28696:
    goto v_28692;
v_28693:
    goto v_28694;
v_28695:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28679;
    v_29150 = nil;
v_28679:
    if (v_29150 == nil) goto v_28677;
    v_29150 = lisp_true;
    goto v_28675;
v_28677:
    v_29150 = v_29153;
    if (!symbolp(v_29150)) v_29150 = nil;
    else { v_29150 = qfastgets(v_29150);
           if (v_29150 != nil) { v_29150 = elt(v_29150, 21); // rl_external
#ifdef RECORD_GET
             if (v_29150 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_29150 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_29150 == SPID_NOPROP) v_29150 = nil; }}
#endif
    goto v_28675;
    v_29150 = nil;
v_28675:
    goto v_28646;
    v_29150 = nil;
v_28646:
    goto v_28559;
    v_29150 = nil;
v_28559:
    goto v_28530;
    v_29150 = nil;
v_28530:
    if (v_29150 == nil) goto v_28527;
    goto v_28718;
v_28714:
    v_29151 = v_29152;
    goto v_28715;
v_28716:
    v_29150 = elt(env, 1); // true
    goto v_28717;
v_28718:
    goto v_28714;
v_28715:
    goto v_28716;
v_28717:
    if (v_29151 == v_29150) goto v_28712;
    else goto v_28713;
v_28712:
    v_29150 = lisp_true;
    goto v_28711;
v_28713:
    goto v_28728;
v_28724:
    v_29151 = v_29152;
    goto v_28725;
v_28726:
    v_29150 = elt(env, 2); // false
    goto v_28727;
v_28728:
    goto v_28724;
v_28725:
    goto v_28726;
v_28727:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28711;
    v_29150 = nil;
v_28711:
    if (v_29150 == nil) goto v_28709;
    v_29150 = lisp_true;
    goto v_28707;
v_28709:
    goto v_28755;
v_28751:
    v_29151 = v_29152;
    goto v_28752;
v_28753:
    v_29150 = elt(env, 3); // or
    goto v_28754;
v_28755:
    goto v_28751;
v_28752:
    goto v_28753;
v_28754:
    if (v_29151 == v_29150) goto v_28749;
    else goto v_28750;
v_28749:
    v_29150 = lisp_true;
    goto v_28748;
v_28750:
    goto v_28765;
v_28761:
    v_29151 = v_29152;
    goto v_28762;
v_28763:
    v_29150 = elt(env, 4); // and
    goto v_28764;
v_28765:
    goto v_28761;
v_28762:
    goto v_28763;
v_28764:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28748;
    v_29150 = nil;
v_28748:
    if (v_29150 == nil) goto v_28746;
    v_29150 = lisp_true;
    goto v_28744;
v_28746:
    goto v_28776;
v_28772:
    v_29151 = v_29152;
    goto v_28773;
v_28774:
    v_29150 = elt(env, 5); // not
    goto v_28775;
v_28776:
    goto v_28772;
v_28773:
    goto v_28774;
v_28775:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28744;
    v_29150 = nil;
v_28744:
    if (v_29150 == nil) goto v_28742;
    v_29150 = lisp_true;
    goto v_28740;
v_28742:
    goto v_28791;
v_28787:
    v_29151 = v_29152;
    goto v_28788;
v_28789:
    v_29150 = elt(env, 6); // impl
    goto v_28790;
v_28791:
    goto v_28787;
v_28788:
    goto v_28789;
v_28790:
    if (v_29151 == v_29150) goto v_28785;
    else goto v_28786;
v_28785:
    v_29150 = lisp_true;
    goto v_28784;
v_28786:
    goto v_28805;
v_28801:
    v_29151 = v_29152;
    goto v_28802;
v_28803:
    v_29150 = elt(env, 7); // repl
    goto v_28804;
v_28805:
    goto v_28801;
v_28802:
    goto v_28803;
v_28804:
    if (v_29151 == v_29150) goto v_28799;
    else goto v_28800;
v_28799:
    v_29150 = lisp_true;
    goto v_28798;
v_28800:
    goto v_28815;
v_28811:
    v_29151 = v_29152;
    goto v_28812;
v_28813:
    v_29150 = elt(env, 8); // equiv
    goto v_28814;
v_28815:
    goto v_28811;
v_28812:
    goto v_28813;
v_28814:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28798;
    v_29150 = nil;
v_28798:
    goto v_28784;
    v_29150 = nil;
v_28784:
    goto v_28740;
    v_29150 = nil;
v_28740:
    if (v_29150 == nil) goto v_28738;
    v_29150 = lisp_true;
    goto v_28736;
v_28738:
    goto v_28834;
v_28830:
    v_29151 = v_29152;
    goto v_28831;
v_28832:
    v_29150 = elt(env, 9); // ex
    goto v_28833;
v_28834:
    goto v_28830;
v_28831:
    goto v_28832;
v_28833:
    if (v_29151 == v_29150) goto v_28828;
    else goto v_28829;
v_28828:
    v_29150 = lisp_true;
    goto v_28827;
v_28829:
    goto v_28844;
v_28840:
    v_29151 = v_29152;
    goto v_28841;
v_28842:
    v_29150 = elt(env, 10); // all
    goto v_28843;
v_28844:
    goto v_28840;
v_28841:
    goto v_28842;
v_28843:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28827;
    v_29150 = nil;
v_28827:
    if (v_29150 == nil) goto v_28825;
    v_29150 = lisp_true;
    goto v_28823;
v_28825:
    goto v_28863;
v_28859:
    v_29151 = v_29152;
    goto v_28860;
v_28861:
    v_29150 = elt(env, 11); // bex
    goto v_28862;
v_28863:
    goto v_28859;
v_28860:
    goto v_28861;
v_28862:
    if (v_29151 == v_29150) goto v_28857;
    else goto v_28858;
v_28857:
    v_29150 = lisp_true;
    goto v_28856;
v_28858:
    goto v_28873;
v_28869:
    v_29151 = v_29152;
    goto v_28870;
v_28871:
    v_29150 = elt(env, 12); // ball
    goto v_28872;
v_28873:
    goto v_28869;
v_28870:
    goto v_28871;
v_28872:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28856;
    v_29150 = nil;
v_28856:
    if (v_29150 == nil) goto v_28854;
    v_29150 = lisp_true;
    goto v_28852;
v_28854:
    v_29150 = v_29152;
    if (!symbolp(v_29150)) v_29150 = nil;
    else { v_29150 = qfastgets(v_29150);
           if (v_29150 != nil) { v_29150 = elt(v_29150, 21); // rl_external
#ifdef RECORD_GET
             if (v_29150 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_29150 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_29150 == SPID_NOPROP) v_29150 = nil; }}
#endif
    goto v_28852;
    v_29150 = nil;
v_28852:
    goto v_28823;
    v_29150 = nil;
v_28823:
    goto v_28736;
    v_29150 = nil;
v_28736:
    goto v_28707;
    v_29150 = nil;
v_28707:
    if (v_29150 == nil) goto v_28705;
    else goto v_28527;
v_28705:
    v_29150 = nil;
    goto v_27767;
v_28527:
    goto v_28891;
v_28887:
    v_29151 = v_29153;
    goto v_28888;
v_28889:
    v_29150 = v_29152;
    goto v_28890;
v_28891:
    goto v_28887;
v_28888:
    goto v_28889;
v_28890:
    if (equal(v_29151, v_29150)) goto v_28886;
    goto v_28899;
v_28895:
    v_29150 = v_29153;
    goto v_28896;
v_28897:
    v_29151 = v_29152;
    goto v_28898;
v_28899:
    goto v_28895;
v_28896:
    goto v_28897;
v_28898:
    {
        fn = elt(env, 14); // cl_ordopp
        return (*qfn2(fn))(fn, v_29150, v_29151);
    }
v_28886:
    goto v_28914;
v_28910:
    v_29151 = v_29153;
    goto v_28911;
v_28912:
    v_29150 = elt(env, 1); // true
    goto v_28913;
v_28914:
    goto v_28910;
v_28911:
    goto v_28912;
v_28913:
    if (v_29151 == v_29150) goto v_28908;
    else goto v_28909;
v_28908:
    v_29150 = lisp_true;
    goto v_28907;
v_28909:
    goto v_28924;
v_28920:
    v_29151 = v_29153;
    goto v_28921;
v_28922:
    v_29150 = elt(env, 2); // false
    goto v_28923;
v_28924:
    goto v_28920;
v_28921:
    goto v_28922;
v_28923:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28907;
    v_29150 = nil;
v_28907:
    if (v_29150 == nil) goto v_28905;
    v_29150 = lisp_true;
    goto v_27767;
v_28905:
    goto v_28941;
v_28937:
    v_29151 = v_29153;
    goto v_28938;
v_28939:
    v_29150 = elt(env, 9); // ex
    goto v_28940;
v_28941:
    goto v_28937;
v_28938:
    goto v_28939;
v_28940:
    if (v_29151 == v_29150) goto v_28935;
    else goto v_28936;
v_28935:
    v_29150 = lisp_true;
    goto v_28934;
v_28936:
    goto v_28951;
v_28947:
    v_29151 = v_29153;
    goto v_28948;
v_28949:
    v_29150 = elt(env, 10); // all
    goto v_28950;
v_28951:
    goto v_28947;
v_28948:
    goto v_28949;
v_28950:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_28934;
    v_29150 = nil;
v_28934:
    if (v_29150 == nil) goto v_28932;
    goto v_28963;
v_28959:
    v_29150 = stack[-1];
    v_29150 = qcdr(v_29150);
    v_29151 = qcar(v_29150);
    goto v_28960;
v_28961:
    v_29150 = stack[0];
    v_29150 = qcdr(v_29150);
    v_29150 = qcar(v_29150);
    goto v_28962;
v_28963:
    goto v_28959;
v_28960:
    goto v_28961;
v_28962:
    if (equal(v_29151, v_29150)) goto v_28958;
    goto v_28979;
v_28975:
    v_29150 = stack[-1];
    v_29150 = qcdr(v_29150);
    v_29151 = qcar(v_29150);
    goto v_28976;
v_28977:
    v_29150 = stack[0];
    v_29150 = qcdr(v_29150);
    v_29150 = qcar(v_29150);
    goto v_28978;
v_28979:
    goto v_28975;
v_28976:
    goto v_28977;
v_28978:
    fn = elt(env, 15); // ordp
    v_29150 = (*qfn2(fn))(fn, v_29151, v_29150);
    env = stack[-2];
    if (v_29150 == nil) goto v_28972;
    else goto v_28973;
v_28972:
    v_29150 = nil;
    goto v_28971;
v_28973:
    goto v_28994;
v_28990:
    v_29150 = stack[-1];
    v_29150 = qcdr(v_29150);
    v_29151 = qcar(v_29150);
    goto v_28991;
v_28992:
    v_29150 = stack[0];
    v_29150 = qcdr(v_29150);
    v_29150 = qcar(v_29150);
    goto v_28993;
v_28994:
    goto v_28990;
v_28991:
    goto v_28992;
v_28993:
    v_29150 = Lneq(nil, v_29151, v_29150);
    goto v_28971;
    v_29150 = nil;
v_28971:
    v_29150 = (v_29150 == nil ? lisp_true : nil);
    goto v_27767;
v_28958:
    goto v_29009;
v_29005:
    v_29150 = stack[-1];
    v_29150 = qcdr(v_29150);
    v_29150 = qcdr(v_29150);
    v_29151 = qcar(v_29150);
    goto v_29006;
v_29007:
    v_29150 = stack[0];
    v_29150 = qcdr(v_29150);
    v_29150 = qcdr(v_29150);
    v_29150 = qcar(v_29150);
    goto v_29008;
v_29009:
    goto v_29005;
v_29006:
    goto v_29007;
v_29008:
    stack[-1] = v_29151;
    stack[0] = v_29150;
    goto v_27760;
    goto v_28930;
v_28932:
v_28930:
    goto v_29030;
v_29026:
    v_29151 = v_29153;
    goto v_29027;
v_29028:
    v_29150 = elt(env, 11); // bex
    goto v_29029;
v_29030:
    goto v_29026;
v_29027:
    goto v_29028;
v_29029:
    if (v_29151 == v_29150) goto v_29024;
    else goto v_29025;
v_29024:
    v_29150 = lisp_true;
    goto v_29023;
v_29025:
    goto v_29040;
v_29036:
    v_29151 = v_29153;
    goto v_29037;
v_29038:
    v_29150 = elt(env, 12); // ball
    goto v_29039;
v_29040:
    goto v_29036;
v_29037:
    goto v_29038;
v_29039:
    v_29150 = (v_29151 == v_29150 ? lisp_true : nil);
    goto v_29023;
    v_29150 = nil;
v_29023:
    if (v_29150 == nil) goto v_29021;
    goto v_29052;
v_29048:
    v_29150 = stack[-1];
    v_29150 = qcdr(v_29150);
    v_29151 = qcar(v_29150);
    goto v_29049;
v_29050:
    v_29150 = stack[0];
    v_29150 = qcdr(v_29150);
    v_29150 = qcar(v_29150);
    goto v_29051;
v_29052:
    goto v_29048;
v_29049:
    goto v_29050;
v_29051:
    if (equal(v_29151, v_29150)) goto v_29047;
    goto v_29068;
v_29064:
    v_29150 = stack[-1];
    v_29150 = qcdr(v_29150);
    v_29151 = qcar(v_29150);
    goto v_29065;
v_29066:
    v_29150 = stack[0];
    v_29150 = qcdr(v_29150);
    v_29150 = qcar(v_29150);
    goto v_29067;
v_29068:
    goto v_29064;
v_29065:
    goto v_29066;
v_29067:
    fn = elt(env, 15); // ordp
    v_29150 = (*qfn2(fn))(fn, v_29151, v_29150);
    env = stack[-2];
    if (v_29150 == nil) goto v_29061;
    else goto v_29062;
v_29061:
    v_29150 = nil;
    goto v_29060;
v_29062:
    goto v_29083;
v_29079:
    v_29150 = stack[-1];
    v_29150 = qcdr(v_29150);
    v_29151 = qcar(v_29150);
    goto v_29080;
v_29081:
    v_29150 = stack[0];
    v_29150 = qcdr(v_29150);
    v_29150 = qcar(v_29150);
    goto v_29082;
v_29083:
    goto v_29079;
v_29080:
    goto v_29081;
v_29082:
    v_29150 = Lneq(nil, v_29151, v_29150);
    goto v_29060;
    v_29150 = nil;
v_29060:
    v_29150 = (v_29150 == nil ? lisp_true : nil);
    goto v_27767;
v_29047:
    goto v_29097;
v_29093:
    v_29150 = stack[-1];
    v_29150 = qcdr(v_29150);
    v_29150 = qcdr(v_29150);
    v_29150 = qcdr(v_29150);
    v_29151 = qcar(v_29150);
    goto v_29094;
v_29095:
    v_29150 = stack[0];
    v_29150 = qcdr(v_29150);
    v_29150 = qcdr(v_29150);
    v_29150 = qcdr(v_29150);
    v_29150 = qcar(v_29150);
    goto v_29096;
v_29097:
    goto v_29093;
v_29094:
    goto v_29095;
v_29096:
    if (equal(v_29151, v_29150)) goto v_29092;
    goto v_29113;
v_29109:
    v_29150 = stack[-1];
    v_29150 = qcdr(v_29150);
    v_29150 = qcdr(v_29150);
    v_29150 = qcdr(v_29150);
    v_29151 = qcar(v_29150);
    goto v_29110;
v_29111:
    v_29150 = stack[0];
    v_29150 = qcdr(v_29150);
    v_29150 = qcdr(v_29150);
    v_29150 = qcdr(v_29150);
    v_29150 = qcar(v_29150);
    goto v_29112;
v_29113:
    goto v_29109;
v_29110:
    goto v_29111;
v_29112:
    stack[-1] = v_29151;
    stack[0] = v_29150;
    goto v_27760;
v_29092:
    goto v_29131;
v_29127:
    v_29150 = stack[-1];
    v_29150 = qcdr(v_29150);
    v_29150 = qcdr(v_29150);
    v_29151 = qcar(v_29150);
    goto v_29128;
v_29129:
    v_29150 = stack[0];
    v_29150 = qcdr(v_29150);
    v_29150 = qcdr(v_29150);
    v_29150 = qcar(v_29150);
    goto v_29130;
v_29131:
    goto v_29127;
v_29128:
    goto v_29129;
v_29130:
    stack[-1] = v_29151;
    stack[0] = v_29150;
    goto v_27760;
    goto v_29019;
v_29021:
v_29019:
    goto v_29145;
v_29141:
    v_29150 = stack[-1];
    v_29151 = qcdr(v_29150);
    goto v_29142;
v_29143:
    v_29150 = stack[0];
    v_29150 = qcdr(v_29150);
    goto v_29144;
v_29145:
    goto v_29141;
v_29142:
    goto v_29143;
v_29144:
    {
        fn = elt(env, 16); // cl_sordpl
        return (*qfn2(fn))(fn, v_29151, v_29150);
    }
v_27767:
    return onevalue(v_29150);
}



// Code for matsm!*

static LispObject CC_matsmH(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27767, v_27768;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_27767 = v_27762;
    v_27768 = v_27761;
// end of prologue
    v_27767 = v_27768;
    fn = elt(env, 1); // matsm
    v_27767 = (*qfn1(fn))(fn, v_27767);
    env = stack[0];
    {
        fn = elt(env, 2); // matsm!*1
        return (*qfn1(fn))(fn, v_27767);
    }
}



// Code for vdplsort

static LispObject CC_vdplsort(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27771, v_27772;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27771 = v_27761;
// end of prologue
    goto v_27768;
v_27764:
    v_27772 = v_27771;
    goto v_27765;
v_27766:
    v_27771 = elt(env, 1); // vdpvevlcomp
    goto v_27767;
v_27768:
    goto v_27764;
v_27765:
    goto v_27766;
v_27767:
    {
        fn = elt(env, 2); // sort
        return (*qfn2(fn))(fn, v_27772, v_27771);
    }
}



// Code for reset_opnums

static LispObject CC_reset_opnums(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27829, v_27830, v_27831;
    LispObject fn;
    argcheck(nargs, 0, "reset_opnums");
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
    stack_popper stack_popper_var(6);
// end of prologue
    v_27829 = qvalue(elt(env, 1)); // oporder!*
    stack[-4] = v_27829;
    v_27829 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_27829;
v_27769:
    v_27829 = stack[-4];
    if (v_27829 == nil) goto v_27774;
    else goto v_27775;
v_27774:
    v_27829 = nil;
    goto v_27768;
v_27775:
    v_27829 = stack[-4];
    v_27829 = qcar(v_27829);
    v_27830 = v_27829;
    v_27829 = stack[-4];
    v_27829 = qcdr(v_27829);
    stack[-4] = v_27829;
    v_27829 = v_27830;
    if (symbolp(v_27829)) goto v_27784;
    else goto v_27785;
v_27784:
    v_27829 = v_27830;
    stack[-2] = v_27829;
    v_27829 = nil;
    goto v_27783;
v_27785:
    v_27829 = v_27830;
    v_27829 = qcar(v_27829);
    stack[-2] = v_27829;
    v_27829 = v_27830;
    v_27829 = qcdr(v_27829);
    goto v_27783;
v_27783:
    goto v_27802;
v_27796:
    stack[-1] = stack[-2];
    goto v_27797;
v_27798:
    stack[0] = elt(env, 2); // opnum
    goto v_27799;
v_27800:
    goto v_27810;
v_27806:
    goto v_27816;
v_27812:
    v_27830 = v_27829;
    goto v_27813;
v_27814:
    v_27829 = stack[-3];
    goto v_27815;
v_27816:
    goto v_27812;
v_27813:
    goto v_27814;
v_27815:
    v_27831 = cons(v_27830, v_27829);
    env = stack[-5];
    goto v_27807;
v_27808:
    goto v_27824;
v_27820:
    v_27830 = stack[-2];
    goto v_27821;
v_27822:
    v_27829 = elt(env, 2); // opnum
    goto v_27823;
v_27824:
    goto v_27820;
v_27821:
    goto v_27822;
v_27823:
    v_27829 = get(v_27830, v_27829);
    env = stack[-5];
    goto v_27809;
v_27810:
    goto v_27806;
v_27807:
    goto v_27808;
v_27809:
    fn = elt(env, 3); // !*xadd
    v_27829 = (*qfn2(fn))(fn, v_27831, v_27829);
    env = stack[-5];
    goto v_27801;
v_27802:
    goto v_27796;
v_27797:
    goto v_27798;
v_27799:
    goto v_27800;
v_27801:
    v_27829 = Lputprop(nil, 3, stack[-1], stack[0], v_27829);
    env = stack[-5];
    v_27829 = stack[-3];
    v_27829 = add1(v_27829);
    env = stack[-5];
    stack[-3] = v_27829;
    goto v_27769;
v_27768:
    return onevalue(v_27829);
}



// Code for free

static LispObject CC_free(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27779;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27761;
// end of prologue
    v_27779 = stack[0];
    v_27779 = qcdr(v_27779);
    v_27779 = qcar(v_27779);
    fn = elt(env, 1); // freeind
    v_27779 = (*qfn1(fn))(fn, v_27779);
    env = stack[-1];
    if (v_27779 == nil) goto v_27765;
    else goto v_27766;
v_27765:
    v_27779 = nil;
    goto v_27764;
v_27766:
    v_27779 = stack[0];
    v_27779 = qcdr(v_27779);
    v_27779 = qcdr(v_27779);
    v_27779 = qcar(v_27779);
    {
        fn = elt(env, 1); // freeind
        return (*qfn1(fn))(fn, v_27779);
    }
    v_27779 = nil;
v_27764:
    return onevalue(v_27779);
}



// Code for expand!-imrepartpow

static LispObject CC_expandKimrepartpow(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27868, v_27869;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_27761;
// end of prologue
// Binding !*exp
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = nil; // !*exp
    v_27868 = lisp_true;
    qvalue(elt(env, 1)) = v_27868; // !*exp
    v_27868 = stack[-2];
    v_27868 = qcar(v_27868);
    if (symbolp(v_27868)) goto v_27771;
    goto v_27779;
v_27775:
    v_27868 = stack[-2];
    v_27868 = qcar(v_27868);
    v_27869 = qcar(v_27868);
    goto v_27776;
v_27777:
    v_27868 = elt(env, 2); // cmpxsplitfn
    goto v_27778;
v_27779:
    goto v_27775;
v_27776:
    goto v_27777;
v_27778:
    v_27868 = get(v_27869, v_27868);
    env = stack[-4];
    goto v_27769;
v_27771:
    v_27868 = nil;
    goto v_27769;
    v_27868 = nil;
v_27769:
    v_27869 = v_27868;
    goto v_27792;
v_27788:
    v_27868 = v_27869;
    if (v_27868 == nil) goto v_27795;
    else goto v_27796;
v_27795:
    goto v_27806;
v_27802:
    v_27868 = stack[-2];
    v_27869 = qcar(v_27868);
    goto v_27803;
v_27804:
    v_27868 = elt(env, 3); // i
    goto v_27805;
v_27806:
    goto v_27802;
v_27803:
    goto v_27804;
v_27805:
    if (v_27869 == v_27868) goto v_27800;
    else goto v_27801;
v_27800:
    goto v_27815;
v_27811:
    goto v_27822;
v_27818:
    goto v_27828;
v_27824:
    v_27869 = elt(env, 3); // i
    goto v_27825;
v_27826:
    v_27868 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27827;
v_27828:
    goto v_27824;
v_27825:
    goto v_27826;
v_27827:
    fn = elt(env, 4); // to
    v_27869 = (*qfn2(fn))(fn, v_27869, v_27868);
    env = stack[-4];
    goto v_27819;
v_27820:
    v_27868 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27821;
v_27822:
    goto v_27818;
v_27819:
    goto v_27820;
v_27821:
    v_27868 = cons(v_27869, v_27868);
    env = stack[-4];
    v_27869 = ncons(v_27868);
    env = stack[-4];
    goto v_27812;
v_27813:
    v_27868 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27814;
v_27815:
    goto v_27811;
v_27812:
    goto v_27813;
v_27814:
    v_27868 = cons(v_27869, v_27868);
    env = stack[-4];
    goto v_27799;
v_27801:
    goto v_27840;
v_27836:
    v_27868 = stack[-2];
    v_27868 = qcar(v_27868);
    fn = elt(env, 5); // mkrepart
    stack[-1] = (*qfn1(fn))(fn, v_27868);
    env = stack[-4];
    goto v_27837;
v_27838:
    goto v_27849;
v_27845:
    v_27868 = elt(env, 3); // i
    fn = elt(env, 6); // simp
    stack[0] = (*qfn1(fn))(fn, v_27868);
    env = stack[-4];
    goto v_27846;
v_27847:
    v_27868 = stack[-2];
    v_27868 = qcar(v_27868);
    fn = elt(env, 7); // mkimpart
    v_27868 = (*qfn1(fn))(fn, v_27868);
    env = stack[-4];
    goto v_27848;
v_27849:
    goto v_27845;
v_27846:
    goto v_27847;
v_27848:
    fn = elt(env, 8); // multsq
    v_27868 = (*qfn2(fn))(fn, stack[0], v_27868);
    env = stack[-4];
    goto v_27839;
v_27840:
    goto v_27836;
v_27837:
    goto v_27838;
v_27839:
    fn = elt(env, 9); // addsq
    v_27868 = (*qfn2(fn))(fn, stack[-1], v_27868);
    env = stack[-4];
    goto v_27799;
    v_27868 = nil;
v_27799:
    v_27869 = v_27868;
    goto v_27794;
v_27796:
    goto v_27862;
v_27858:
    goto v_27859;
v_27860:
    v_27868 = stack[-2];
    v_27868 = qcar(v_27868);
    goto v_27861;
v_27862:
    goto v_27858;
v_27859:
    goto v_27860;
v_27861:
    v_27868 = Lapply1(nil, v_27869, v_27868);
    env = stack[-4];
    v_27869 = v_27868;
    goto v_27794;
    v_27869 = nil;
v_27794:
    goto v_27789;
v_27790:
    v_27868 = stack[-2];
    v_27868 = qcdr(v_27868);
    goto v_27791;
v_27792:
    goto v_27788;
v_27789:
    goto v_27790;
v_27791:
    fn = elt(env, 10); // exptsq
    v_27868 = (*qfn2(fn))(fn, v_27869, v_27868);
    ;}  // end of a binding scope
    return onevalue(v_27868);
}



// Code for generic_arguments

static LispObject CC_generic_arguments(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27779, v_27780, v_27781;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
// copy arguments values to proper place
    v_27779 = v_27761;
// end of prologue
    goto v_27768;
v_27764:
    v_27781 = elt(env, 1); // list
    goto v_27765;
v_27766:
    goto v_27775;
v_27771:
    v_27780 = qcar(v_27779);
    goto v_27772;
v_27773:
    v_27779 = elt(env, 2); // generic_function
    goto v_27774;
v_27775:
    goto v_27771;
v_27772:
    goto v_27773;
v_27774:
    v_27779 = get(v_27780, v_27779);
    goto v_27767;
v_27768:
    goto v_27764;
v_27765:
    goto v_27766;
v_27767:
    return cons(v_27781, v_27779);
}



// Code for njets

static LispObject CC_njets(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27780, v_27781;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_27780 = v_27762;
    v_27781 = v_27761;
// end of prologue
    goto v_27769;
v_27765:
    stack[-1] = v_27780;
    goto v_27766;
v_27767:
    goto v_27776;
v_27772:
    stack[0] = v_27780;
    goto v_27773;
v_27774:
    v_27780 = v_27781;
    v_27780 = sub1(v_27780);
    env = stack[-2];
    goto v_27775;
v_27776:
    goto v_27772;
v_27773:
    goto v_27774;
v_27775:
    v_27780 = plus2(stack[0], v_27780);
    env = stack[-2];
    goto v_27768;
v_27769:
    goto v_27765;
v_27766:
    goto v_27767;
v_27768:
    {
        LispObject v_27784 = stack[-1];
        fn = elt(env, 1); // combin
        return (*qfn2(fn))(fn, v_27784, v_27780);
    }
}



// Code for domainp_list

static LispObject CC_domainp_list(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27794, v_27795;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27794 = v_27761;
// end of prologue
v_27760:
    v_27795 = v_27794;
    if (v_27795 == nil) goto v_27765;
    else goto v_27766;
v_27765:
    v_27794 = lisp_true;
    goto v_27764;
v_27766:
    v_27795 = v_27794;
    v_27795 = qcar(v_27795);
    if (!consp(v_27795)) goto v_27777;
    else goto v_27778;
v_27777:
    v_27795 = lisp_true;
    goto v_27776;
v_27778:
    v_27795 = v_27794;
    v_27795 = qcar(v_27795);
    v_27795 = qcar(v_27795);
    v_27795 = (consp(v_27795) ? nil : lisp_true);
    goto v_27776;
    v_27795 = nil;
v_27776:
    if (v_27795 == nil) goto v_27774;
    v_27794 = qcdr(v_27794);
    goto v_27760;
v_27774:
    v_27794 = nil;
    goto v_27772;
    v_27794 = nil;
v_27772:
    goto v_27764;
    v_27794 = nil;
v_27764:
    return onevalue(v_27794);
}



// Code for random!-small!-prime

static LispObject CC_randomKsmallKprime(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27784;
    LispObject fn;
    argcheck(nargs, 0, "random-small-prime");
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
v_27767:
    fn = elt(env, 1); // small!-random!-number
    v_27784 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_27784;
    v_27784 = stack[0];
    v_27784 = Levenp(nil, v_27784);
    env = stack[-1];
    if (v_27784 == nil) goto v_27772;
    v_27784 = stack[0];
    v_27784 = (LispObject)((intptr_t)(v_27784) + 0x10);
    stack[0] = v_27784;
    goto v_27770;
v_27772:
v_27770:
    v_27784 = stack[0];
    fn = elt(env, 2); // primep
    v_27784 = (*qfn1(fn))(fn, v_27784);
    env = stack[-1];
    if (v_27784 == nil) goto v_27779;
    else goto v_27780;
v_27779:
    goto v_27767;
v_27780:
    v_27784 = stack[0];
    return onevalue(v_27784);
}



// Code for janettreeinsert

static LispObject CC_janettreeinsert(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_28045, v_28046, v_28047;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_27761;
// end of prologue
    goto v_27776;
v_27772:
    v_28046 = stack[-7];
    goto v_27773;
v_27774:
    v_28045 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27775;
v_27776:
    goto v_27772;
v_27773:
    goto v_27774;
v_27775:
    v_28045 = *(LispObject *)((char *)v_28046 + (CELL-TAG_VECTOR) + (((intptr_t)v_28045-TAG_FIXNUM)/(16/CELL)));
    v_28045 = qcar(v_28045);
    stack[-3] = v_28045;
    goto v_27785;
v_27781:
    v_28046 = stack[-3];
    goto v_27782;
v_27783:
    v_28045 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27784;
v_27785:
    goto v_27781;
v_27782:
    goto v_27783;
v_27784:
    v_28045 = *(LispObject *)((char *)v_28046 + (CELL-TAG_VECTOR) + (((intptr_t)v_28045-TAG_FIXNUM)/(16/CELL)));
    stack[-6] = v_28045;
    v_28045 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_28045;
    v_28045 = qvalue(elt(env, 1)); // fluidbibasisjanettreerootnode
    if (v_28045 == nil) goto v_27792;
    else goto v_27793;
v_27792:
    goto v_27802;
v_27796:
    v_28047 = stack[-6];
    goto v_27797;
v_27798:
    v_28046 = stack[-8];
    goto v_27799;
v_27800:
    v_28045 = stack[-7];
    goto v_27801;
v_27802:
    goto v_27796;
v_27797:
    goto v_27798;
v_27799:
    goto v_27800;
v_27801:
    fn = elt(env, 2); // janettreenodebuild
    v_28045 = (*qfnn(fn))(fn, 3, v_28047, v_28046, v_28045);
    env = stack[-9];
    qvalue(elt(env, 1)) = v_28045; // fluidbibasisjanettreerootnode
    goto v_27791;
v_27793:
    v_28045 = qvalue(elt(env, 1)); // fluidbibasisjanettreerootnode
    stack[-5] = v_28045;
v_27812:
    goto v_27822;
v_27818:
    v_28046 = stack[-6];
    goto v_27819;
v_27820:
    v_28045 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27821;
v_27822:
    goto v_27818;
v_27819:
    goto v_27820;
v_27821:
    v_28045 = (LispObject)greaterp2(v_28046, v_28045);
    v_28045 = v_28045 ? lisp_true : nil;
    env = stack[-9];
    if (v_28045 == nil) goto v_27815;
    else goto v_27816;
v_27815:
    goto v_27811;
v_27816:
v_27828:
    v_28045 = stack[-5];
    if (v_28045 == nil) goto v_27831;
    goto v_27842;
v_27838:
    v_28045 = stack[-5];
    v_28045 = qcar(v_28045);
    stack[0] = qcar(v_28045);
    goto v_27839;
v_27840:
    goto v_27851;
v_27847:
    v_28046 = stack[-3];
    goto v_27848;
v_27849:
    v_28045 = stack[-8];
    goto v_27850;
v_27851:
    goto v_27847;
v_27848:
    goto v_27849;
v_27850:
    fn = elt(env, 3); // monomgetvariabledegree
    v_28045 = (*qfn2(fn))(fn, v_28046, v_28045);
    env = stack[-9];
    goto v_27841;
v_27842:
    goto v_27838;
v_27839:
    goto v_27840;
v_27841:
    v_28045 = (LispObject)lessp2(stack[0], v_28045);
    v_28045 = v_28045 ? lisp_true : nil;
    env = stack[-9];
    if (v_28045 == nil) goto v_27831;
    v_28045 = stack[-5];
    v_28045 = qcdr(v_28045);
    v_28045 = qcar(v_28045);
    if (v_28045 == nil) goto v_27831;
    goto v_27832;
v_27831:
    goto v_27827;
v_27832:
    v_28045 = stack[-5];
    v_28045 = qcdr(v_28045);
    v_28045 = qcar(v_28045);
    stack[-5] = v_28045;
    goto v_27828;
v_27827:
    v_28045 = stack[-5];
    if (v_28045 == nil) goto v_27866;
    goto v_27875;
v_27871:
    v_28045 = stack[-5];
    v_28045 = qcar(v_28045);
    stack[0] = qcar(v_28045);
    goto v_27872;
v_27873:
    goto v_27884;
v_27880:
    v_28046 = stack[-3];
    goto v_27881;
v_27882:
    v_28045 = stack[-8];
    goto v_27883;
v_27884:
    goto v_27880;
v_27881:
    goto v_27882;
v_27883:
    fn = elt(env, 3); // monomgetvariabledegree
    v_28045 = (*qfn2(fn))(fn, v_28046, v_28045);
    env = stack[-9];
    goto v_27874;
v_27875:
    goto v_27871;
v_27872:
    goto v_27873;
v_27874:
    v_28045 = (LispObject)greaterp2(stack[0], v_28045);
    v_28045 = v_28045 ? lisp_true : nil;
    env = stack[-9];
    if (v_28045 == nil) goto v_27866;
    goto v_27894;
v_27888:
    v_28047 = stack[-6];
    goto v_27889;
v_27890:
    v_28046 = stack[-8];
    goto v_27891;
v_27892:
    v_28045 = stack[-7];
    goto v_27893;
v_27894:
    goto v_27888;
v_27889:
    goto v_27890;
v_27891:
    goto v_27892;
v_27893:
    fn = elt(env, 2); // janettreenodebuild
    v_28045 = (*qfnn(fn))(fn, 3, v_28047, v_28046, v_28045);
    env = stack[-9];
    stack[-4] = v_28045;
    v_28045 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_28045;
    goto v_27904;
v_27900:
    v_28045 = stack[-5];
    stack[-2] = qcdr(v_28045);
    goto v_27901;
v_27902:
    goto v_27914;
v_27908:
    v_28045 = stack[-5];
    v_28045 = qcar(v_28045);
    stack[-1] = qcar(v_28045);
    goto v_27909;
v_27910:
    v_28045 = stack[-5];
    v_28045 = qcar(v_28045);
    stack[0] = qcdr(v_28045);
    goto v_27911;
v_27912:
    goto v_27926;
v_27922:
    v_28045 = stack[-5];
    v_28045 = qcdr(v_28045);
    v_28046 = qcar(v_28045);
    goto v_27923;
v_27924:
    v_28045 = stack[-5];
    v_28045 = qcdr(v_28045);
    v_28045 = qcdr(v_28045);
    goto v_27925;
v_27926:
    goto v_27922;
v_27923:
    goto v_27924;
v_27925:
    v_28045 = cons(v_28046, v_28045);
    env = stack[-9];
    goto v_27913;
v_27914:
    goto v_27908;
v_27909:
    goto v_27910;
v_27911:
    goto v_27912;
v_27913:
    v_28045 = acons(stack[-1], stack[0], v_28045);
    env = stack[-9];
    goto v_27903;
v_27904:
    goto v_27900;
v_27901:
    goto v_27902;
v_27903:
    fn = elt(env, 4); // setcar
    v_28045 = (*qfn2(fn))(fn, stack[-2], v_28045);
    env = stack[-9];
    goto v_27938;
v_27934:
    v_28045 = stack[-5];
    v_28046 = qcdr(v_28045);
    goto v_27935;
v_27936:
    v_28045 = stack[-4];
    v_28045 = qcdr(v_28045);
    v_28045 = qcdr(v_28045);
    goto v_27937;
v_27938:
    goto v_27934;
v_27935:
    goto v_27936;
v_27937:
    fn = elt(env, 5); // setcdr
    v_28045 = (*qfn2(fn))(fn, v_28046, v_28045);
    env = stack[-9];
    goto v_27949;
v_27945:
    v_28045 = stack[-5];
    v_28046 = qcar(v_28045);
    goto v_27946;
v_27947:
    v_28045 = stack[-4];
    v_28045 = qcar(v_28045);
    v_28045 = qcar(v_28045);
    goto v_27948;
v_27949:
    goto v_27945;
v_27946:
    goto v_27947;
v_27948:
    fn = elt(env, 4); // setcar
    v_28045 = (*qfn2(fn))(fn, v_28046, v_28045);
    env = stack[-9];
    goto v_27960;
v_27956:
    v_28045 = stack[-5];
    v_28046 = qcar(v_28045);
    goto v_27957;
v_27958:
    v_28045 = stack[-4];
    v_28045 = qcar(v_28045);
    v_28045 = qcdr(v_28045);
    goto v_27959;
v_27960:
    goto v_27956;
v_27957:
    goto v_27958;
v_27959:
    fn = elt(env, 5); // setcdr
    v_28045 = (*qfn2(fn))(fn, v_28046, v_28045);
    env = stack[-9];
    goto v_27864;
v_27866:
    v_28045 = stack[-5];
    if (v_28045 == nil) goto v_27968;
    goto v_27980;
v_27976:
    v_28045 = stack[-5];
    v_28045 = qcar(v_28045);
    stack[0] = qcar(v_28045);
    goto v_27977;
v_27978:
    goto v_27989;
v_27985:
    v_28046 = stack[-3];
    goto v_27986;
v_27987:
    v_28045 = stack[-8];
    goto v_27988;
v_27989:
    goto v_27985;
v_27986:
    goto v_27987;
v_27988:
    fn = elt(env, 3); // monomgetvariabledegree
    v_28045 = (*qfn2(fn))(fn, v_28046, v_28045);
    env = stack[-9];
    goto v_27979;
v_27980:
    goto v_27976;
v_27977:
    goto v_27978;
v_27979:
    if (equal(stack[0], v_28045)) goto v_27974;
    else goto v_27975;
v_27974:
    v_28045 = stack[-5];
    v_28045 = qcdr(v_28045);
    v_28045 = qcdr(v_28045);
    goto v_27973;
v_27975:
    v_28045 = nil;
    goto v_27973;
    v_28045 = nil;
v_27973:
    if (v_28045 == nil) goto v_27968;
    goto v_28003;
v_27999:
    stack[0] = stack[-6];
    goto v_28000;
v_28001:
    goto v_28010;
v_28006:
    v_28046 = stack[-3];
    goto v_28007;
v_28008:
    v_28045 = stack[-8];
    goto v_28009;
v_28010:
    goto v_28006;
v_28007:
    goto v_28008;
v_28009:
    fn = elt(env, 3); // monomgetvariabledegree
    v_28045 = (*qfn2(fn))(fn, v_28046, v_28045);
    env = stack[-9];
    goto v_28002;
v_28003:
    goto v_27999;
v_28000:
    goto v_28001;
v_28002:
    v_28045 = difference2(stack[0], v_28045);
    env = stack[-9];
    stack[-6] = v_28045;
    v_28045 = stack[-8];
    v_28045 = add1(v_28045);
    env = stack[-9];
    stack[-8] = v_28045;
    v_28045 = stack[-5];
    v_28045 = qcdr(v_28045);
    v_28045 = qcdr(v_28045);
    stack[-5] = v_28045;
    goto v_27864;
v_27968:
    v_28045 = stack[-5];
    if (v_28045 == nil) goto v_28020;
    goto v_28027;
v_28023:
    v_28045 = stack[-5];
    stack[0] = qcdr(v_28045);
    goto v_28024;
v_28025:
    goto v_28037;
v_28031:
    v_28047 = stack[-6];
    goto v_28032;
v_28033:
    v_28046 = stack[-8];
    goto v_28034;
v_28035:
    v_28045 = stack[-7];
    goto v_28036;
v_28037:
    goto v_28031;
v_28032:
    goto v_28033;
v_28034:
    goto v_28035;
v_28036:
    fn = elt(env, 2); // janettreenodebuild
    v_28045 = (*qfnn(fn))(fn, 3, v_28047, v_28046, v_28045);
    env = stack[-9];
    goto v_28026;
v_28027:
    goto v_28023;
v_28024:
    goto v_28025;
v_28026:
    fn = elt(env, 4); // setcar
    v_28045 = (*qfn2(fn))(fn, stack[0], v_28045);
    env = stack[-9];
    v_28045 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_28045;
    goto v_27864;
v_28020:
v_27864:
    goto v_27812;
v_27811:
    goto v_27791;
v_27791:
    v_28045 = nil;
    return onevalue(v_28045);
}



// Code for mri_simplat1

static LispObject CC_mri_simplat1(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27857, v_27858;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_27762;
    stack[-2] = v_27761;
// end of prologue
    v_27857 = qvalue(elt(env, 1)); // !*rlsimplfloor
    if (v_27857 == nil) goto v_27771;
    goto v_27780;
v_27774:
    v_27857 = stack[-2];
    fn = elt(env, 4); // mri_op
    stack[-3] = (*qfn1(fn))(fn, v_27857);
    env = stack[-4];
    goto v_27775;
v_27776:
    v_27857 = stack[-2];
    fn = elt(env, 5); // mri_arg2l
    v_27857 = (*qfn1(fn))(fn, v_27857);
    env = stack[-4];
    fn = elt(env, 6); // mri_simplfloor
    stack[0] = (*qfn1(fn))(fn, v_27857);
    env = stack[-4];
    goto v_27777;
v_27778:
    v_27857 = stack[-2];
    fn = elt(env, 7); // mri_type
    v_27857 = (*qfn1(fn))(fn, v_27857);
    env = stack[-4];
    goto v_27779;
v_27780:
    goto v_27774;
v_27775:
    goto v_27776;
v_27777:
    goto v_27778;
v_27779:
    fn = elt(env, 8); // mri_0mk2
    v_27857 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_27857);
    env = stack[-4];
    stack[-2] = v_27857;
    goto v_27769;
v_27771:
v_27769:
    v_27857 = stack[-2];
    fn = elt(env, 7); // mri_type
    v_27857 = (*qfn1(fn))(fn, v_27857);
    env = stack[-4];
    if (v_27857 == nil) goto v_27790;
    else goto v_27789;
v_27790:
    v_27857 = stack[-2];
    fn = elt(env, 9); // mri_dettype
    v_27857 = (*qfn1(fn))(fn, v_27857);
    env = stack[-4];
v_27789:
    stack[0] = v_27857;
    goto v_27803;
v_27799:
    v_27858 = stack[0];
    goto v_27800;
v_27801:
    v_27857 = elt(env, 2); // int
    goto v_27802;
v_27803:
    goto v_27799;
v_27800:
    goto v_27801;
v_27802:
    if (v_27858 == v_27857) goto v_27797;
    else goto v_27798;
v_27797:
    goto v_27811;
v_27807:
    goto v_27817;
v_27813:
    v_27857 = stack[-2];
    fn = elt(env, 10); // mri_2pasfat
    v_27858 = (*qfn1(fn))(fn, v_27857);
    env = stack[-4];
    goto v_27814;
v_27815:
    v_27857 = stack[-1];
    goto v_27816;
v_27817:
    goto v_27813;
v_27814:
    goto v_27815;
v_27816:
    fn = elt(env, 11); // pasf_simplat1
    v_27858 = (*qfn2(fn))(fn, v_27858, v_27857);
    env = stack[-4];
    goto v_27808;
v_27809:
    v_27857 = elt(env, 2); // int
    goto v_27810;
v_27811:
    goto v_27807;
v_27808:
    goto v_27809;
v_27810:
    {
        fn = elt(env, 12); // mri_pasf2mri
        return (*qfn2(fn))(fn, v_27858, v_27857);
    }
v_27798:
    v_27857 = stack[-2];
    fn = elt(env, 13); // mri_congp
    v_27857 = (*qfn1(fn))(fn, v_27857);
    env = stack[-4];
    if (v_27857 == nil) goto v_27824;
    else goto v_27825;
v_27824:
    goto v_27833;
v_27829:
    goto v_27839;
v_27835:
    v_27857 = stack[-2];
    fn = elt(env, 14); // mri_2ofsfat
    v_27858 = (*qfn1(fn))(fn, v_27857);
    env = stack[-4];
    goto v_27836;
v_27837:
    v_27857 = stack[-1];
    goto v_27838;
v_27839:
    goto v_27835;
v_27836:
    goto v_27837;
v_27838:
    fn = elt(env, 15); // ofsf_simplat1
    v_27858 = (*qfn2(fn))(fn, v_27858, v_27857);
    env = stack[-4];
    goto v_27830;
v_27831:
    v_27857 = elt(env, 3); // real
    goto v_27832;
v_27833:
    goto v_27829;
v_27830:
    goto v_27831;
v_27832:
    {
        fn = elt(env, 16); // mri_ofsf2mri
        return (*qfn2(fn))(fn, v_27858, v_27857);
    }
v_27825:
    goto v_27851;
v_27845:
    v_27857 = stack[-2];
    fn = elt(env, 4); // mri_op
    stack[-1] = (*qfn1(fn))(fn, v_27857);
    env = stack[-4];
    goto v_27846;
v_27847:
    v_27857 = stack[-2];
    fn = elt(env, 5); // mri_arg2l
    v_27858 = (*qfn1(fn))(fn, v_27857);
    env = stack[-4];
    goto v_27848;
v_27849:
    v_27857 = stack[0];
    goto v_27850;
v_27851:
    goto v_27845;
v_27846:
    goto v_27847;
v_27848:
    goto v_27849;
v_27850:
    {
        LispObject v_27863 = stack[-1];
        fn = elt(env, 8); // mri_0mk2
        return (*qfnn(fn))(fn, 3, v_27863, v_27858, v_27857);
    }
    return onevalue(v_27857);
}



// Code for ofsf_updsignpow

static LispObject CC_ofsf_updsignpow(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27800, v_27801, v_27802, v_27803;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_27802 = v_27762;
    v_27803 = v_27761;
// end of prologue
    goto v_27772;
v_27768:
    v_27801 = v_27803;
    goto v_27769;
v_27770:
    v_27800 = elt(env, 1); // (equal greaterp geq neq)
    goto v_27771;
v_27772:
    goto v_27768;
v_27769:
    goto v_27770;
v_27771:
    v_27800 = Lmemq(nil, v_27801, v_27800);
    if (v_27800 == nil) goto v_27767;
    v_27800 = v_27803;
    goto v_27765;
v_27767:
    goto v_27783;
v_27779:
    v_27801 = v_27803;
    goto v_27780;
v_27781:
    v_27800 = elt(env, 2); // (lessp leq)
    goto v_27782;
v_27783:
    goto v_27779;
v_27780:
    goto v_27781;
v_27782:
    v_27800 = Lmemq(nil, v_27801, v_27800);
    if (v_27800 == nil) goto v_27778;
    goto v_27792;
v_27788:
    v_27800 = v_27803;
    goto v_27789;
v_27790:
    v_27801 = v_27802;
    v_27801 = Levenp(nil, v_27801);
    env = stack[0];
    v_27801 = (v_27801 == nil ? lisp_true : nil);
    goto v_27791;
v_27792:
    goto v_27788;
v_27789:
    goto v_27790;
v_27791:
    {
        fn = elt(env, 4); // ofsf_canegrel
        return (*qfn2(fn))(fn, v_27800, v_27801);
    }
v_27778:
    v_27800 = elt(env, 3); // unknown
    goto v_27765;
    v_27800 = nil;
v_27765:
    return onevalue(v_27800);
}



// Code for cr!:prep

static LispObject CC_crTprep(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27792, v_27793;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27761;
// end of prologue
    goto v_27769;
v_27765:
    goto v_27776;
v_27772:
    v_27793 = elt(env, 1); // !:rd!:
    goto v_27773;
v_27774:
    v_27792 = stack[0];
    v_27792 = qcdr(v_27792);
    v_27792 = qcar(v_27792);
    goto v_27775;
v_27776:
    goto v_27772;
v_27773:
    goto v_27774;
v_27775:
    v_27792 = cons(v_27793, v_27792);
    env = stack[-2];
    fn = elt(env, 2); // rd!:prep
    stack[-1] = (*qfn1(fn))(fn, v_27792);
    env = stack[-2];
    goto v_27766;
v_27767:
    goto v_27787;
v_27783:
    v_27793 = elt(env, 1); // !:rd!:
    goto v_27784;
v_27785:
    v_27792 = stack[0];
    v_27792 = qcdr(v_27792);
    v_27792 = qcdr(v_27792);
    goto v_27786;
v_27787:
    goto v_27783;
v_27784:
    goto v_27785;
v_27786:
    v_27792 = cons(v_27793, v_27792);
    env = stack[-2];
    fn = elt(env, 2); // rd!:prep
    v_27792 = (*qfn1(fn))(fn, v_27792);
    env = stack[-2];
    goto v_27768;
v_27769:
    goto v_27765;
v_27766:
    goto v_27767;
v_27768:
    v_27792 = cons(stack[-1], v_27792);
    env = stack[-2];
    {
        fn = elt(env, 3); // crprep1
        return (*qfn1(fn))(fn, v_27792);
    }
}



// Code for spinnerprod

static LispObject CC_spinnerprod(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27897, v_27898, v_27899, v_27900;
    LispObject v_27766, v_27765, v_27764, v_27763, v_27762, v_27761;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "spinnerprod");
    va_start(aa, nargs);
    v_27761 = va_arg(aa, LispObject);
    v_27762 = va_arg(aa, LispObject);
    v_27763 = va_arg(aa, LispObject);
    v_27764 = va_arg(aa, LispObject);
    v_27765 = va_arg(aa, LispObject);
    v_27766 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_27766,v_27765,v_27764,v_27763,v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_27761,v_27762,v_27763,v_27764,v_27765,v_27766);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_27766;
    v_27897 = v_27765;
    v_27898 = v_27764;
    stack[-5] = v_27763;
    v_27899 = v_27762;
    v_27900 = v_27761;
// end of prologue
    stack[-6] = v_27898;
    v_27898 = stack[-6];
    stack[-3] = v_27898;
    v_27897 = qcdr(v_27897);
    stack[-1] = v_27897;
v_27780:
    v_27897 = stack[-1];
    if (v_27897 == nil) goto v_27785;
    else goto v_27786;
v_27785:
    goto v_27779;
v_27786:
    v_27897 = stack[-1];
    v_27897 = qcar(v_27897);
    v_27898 = v_27897;
    v_27897 = v_27898;
    v_27897 = qcar(v_27897);
    stack[-7] = v_27897;
    v_27897 = stack[-7];
    if (v_27897 == nil) goto v_27796;
    else goto v_27797;
v_27796:
    v_27897 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_27897;
    goto v_27795;
v_27797:
v_27795:
    v_27897 = v_27898;
    v_27897 = qcdr(v_27897);
    stack[-2] = v_27897;
    v_27897 = stack[-2];
    if (v_27897 == nil) goto v_27808;
    else goto v_27809;
v_27808:
    v_27897 = lisp_true;
    goto v_27807;
v_27809:
    goto v_27818;
v_27814:
    stack[0] = stack[-2];
    goto v_27815;
v_27816:
    v_27897 = nil;
    v_27897 = ncons(v_27897);
    env = stack[-8];
    goto v_27817;
v_27818:
    goto v_27814;
v_27815:
    goto v_27816;
v_27817:
    v_27897 = (equal(stack[0], v_27897) ? lisp_true : nil);
    goto v_27807;
    v_27897 = nil;
v_27807:
    if (v_27897 == nil) goto v_27805;
    v_27897 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_27897;
    goto v_27803;
v_27805:
v_27803:
    goto v_27833;
v_27829:
    v_27898 = stack[-7];
    goto v_27830;
v_27831:
    v_27897 = stack[-5];
    goto v_27832;
v_27833:
    goto v_27829;
v_27830:
    goto v_27831;
v_27832:
    v_27897 = (LispObject)lesseq2(v_27898, v_27897);
    v_27897 = v_27897 ? lisp_true : nil;
    env = stack[-8];
    if (v_27897 == nil) goto v_27827;
    goto v_27840;
v_27836:
    v_27898 = stack[-7];
    goto v_27837;
v_27838:
    v_27897 = stack[-4];
    goto v_27839;
v_27840:
    goto v_27836;
v_27837:
    goto v_27838;
v_27839:
    v_27897 = Latsoc(nil, v_27898, v_27897);
    stack[-7] = v_27897;
    v_27897 = stack[-7];
    if (v_27897 == nil) goto v_27850;
    else goto v_27851;
v_27850:
    v_27897 = lisp_true;
    goto v_27849;
v_27851:
    goto v_27860;
v_27856:
    stack[0] = stack[-7];
    goto v_27857;
v_27858:
    v_27897 = nil;
    v_27897 = ncons(v_27897);
    env = stack[-8];
    goto v_27859;
v_27860:
    goto v_27856;
v_27857:
    goto v_27858;
v_27859:
    v_27897 = (equal(stack[0], v_27897) ? lisp_true : nil);
    goto v_27849;
    v_27897 = nil;
v_27849:
    if (v_27897 == nil) goto v_27847;
    goto v_27845;
v_27847:
    goto v_27875;
v_27869:
    stack[0] = elt(env, 1); // plus
    goto v_27870;
v_27871:
    stack[-3] = stack[-6];
    goto v_27872;
v_27873:
    goto v_27885;
v_27879:
    v_27899 = elt(env, 2); // times
    goto v_27880;
v_27881:
    v_27898 = stack[-2];
    goto v_27882;
v_27883:
    v_27897 = stack[-7];
    v_27897 = qcdr(v_27897);
    goto v_27884;
v_27885:
    goto v_27879;
v_27880:
    goto v_27881;
v_27882:
    goto v_27883;
v_27884:
    v_27897 = list3(v_27899, v_27898, v_27897);
    env = stack[-8];
    goto v_27874;
v_27875:
    goto v_27869;
v_27870:
    goto v_27871;
v_27872:
    goto v_27873;
v_27874:
    v_27897 = list3(stack[0], stack[-3], v_27897);
    env = stack[-8];
    stack[-6] = v_27897;
    v_27897 = stack[-6];
    stack[-3] = v_27897;
    goto v_27845;
v_27845:
    goto v_27825;
v_27827:
v_27825:
    v_27897 = stack[-1];
    v_27897 = qcdr(v_27897);
    stack[-1] = v_27897;
    goto v_27780;
v_27779:
    v_27897 = stack[-3];
    return onevalue(v_27897);
}



// Code for safe!-fp!-quot

static LispObject CC_safeKfpKquot(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27852, v_27853, v_27854;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_27854 = v_27762;
    stack[0] = v_27761;
// end of prologue
    goto v_27775;
v_27771:
    v_27853 = v_27854;
    goto v_27772;
v_27773:
    v_27852 = elt(env, 1); // 0.0
    goto v_27774;
v_27775:
    goto v_27771;
v_27772:
    goto v_27773;
v_27774:
    if (equal(v_27853, v_27852)) goto v_27769;
    else goto v_27770;
v_27769:
    v_27852 = nil;
    goto v_27766;
v_27770:
    v_27852 = qvalue(elt(env, 2)); // !*nonegzerotimes
    if (v_27852 == nil) goto v_27780;
    goto v_27788;
v_27784:
    v_27853 = stack[0];
    goto v_27785;
v_27786:
    v_27852 = elt(env, 1); // 0.0
    goto v_27787;
v_27788:
    goto v_27784;
v_27785:
    goto v_27786;
v_27787:
    if (equal(v_27853, v_27852)) goto v_27783;
    else goto v_27780;
v_27783:
    v_27852 = elt(env, 1); // 0.0
    goto v_27766;
v_27780:
    goto v_27797;
v_27793:
    v_27852 = stack[0];
    goto v_27794;
v_27795:
    v_27853 = v_27854;
    goto v_27796;
v_27797:
    goto v_27793;
v_27794:
    goto v_27795;
v_27796:
    v_27852 = quot2(v_27852, v_27853);
    env = stack[-2];
    stack[-1] = v_27852;
    goto v_27810;
v_27806:
    v_27853 = stack[-1];
    goto v_27807;
v_27808:
    v_27852 = qvalue(elt(env, 3)); // !!minnorm
    goto v_27809;
v_27810:
    goto v_27806;
v_27807:
    goto v_27808;
v_27809:
    v_27852 = (LispObject)lessp2(v_27853, v_27852);
    v_27852 = v_27852 ? lisp_true : nil;
    env = stack[-2];
    if (v_27852 == nil) goto v_27803;
    goto v_27820;
v_27816:
    v_27853 = stack[-1];
    goto v_27817;
v_27818:
    v_27852 = qvalue(elt(env, 4)); // !!minnegnorm
    goto v_27819;
v_27820:
    goto v_27816;
v_27817:
    goto v_27818;
v_27819:
    v_27852 = (LispObject)greaterp2(v_27853, v_27852);
    v_27852 = v_27852 ? lisp_true : nil;
    env = stack[-2];
    if (v_27852 == nil) goto v_27803;
    goto v_27828;
v_27824:
    v_27853 = stack[0];
    goto v_27825;
v_27826:
    v_27852 = elt(env, 1); // 0.0
    goto v_27827;
v_27828:
    goto v_27824;
v_27825:
    goto v_27826;
v_27827:
    if (equal(v_27853, v_27852)) goto v_27803;
    v_27852 = nil;
    goto v_27766;
v_27803:
    goto v_27838;
v_27834:
    goto v_27844;
v_27840:
    v_27853 = stack[-1];
    goto v_27841;
v_27842:
    v_27852 = stack[-1];
    goto v_27843;
v_27844:
    goto v_27840;
v_27841:
    goto v_27842;
v_27843:
    v_27852 = difference2(v_27853, v_27852);
    env = stack[-2];
    goto v_27835;
v_27836:
    v_27853 = elt(env, 1); // 0.0
    goto v_27837;
v_27838:
    goto v_27834;
v_27835:
    goto v_27836;
v_27837:
    if (equal(v_27852, v_27853)) goto v_27832;
    else goto v_27833;
v_27832:
    v_27852 = stack[-1];
    goto v_27766;
v_27833:
    v_27852 = nil;
    goto v_27766;
    v_27852 = nil;
v_27766:
    return onevalue(v_27852);
}



// Code for f2dip

static LispObject CC_f2dip(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27775;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_27775 = v_27761;
// end of prologue
    goto v_27770;
v_27764:
    stack[-1] = v_27775;
    goto v_27765;
v_27766:
    fn = elt(env, 1); // evzero
    stack[0] = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_27767;
v_27768:
    v_27775 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 2); // bcfd
    v_27775 = (*qfn1(fn))(fn, v_27775);
    env = stack[-2];
    goto v_27769;
v_27770:
    goto v_27764;
v_27765:
    goto v_27766;
v_27767:
    goto v_27768;
v_27769:
    {
        LispObject v_27778 = stack[-1];
        LispObject v_27779 = stack[0];
        fn = elt(env, 3); // f2dip1
        return (*qfnn(fn))(fn, 3, v_27778, v_27779, v_27775);
    }
}



// Code for delete_edge

static LispObject CC_delete_edge(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27809, v_27810, v_27811;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27762;
    stack[-1] = v_27761;
// end of prologue
    v_27811 = nil;
v_27767:
    v_27809 = stack[0];
    if (v_27809 == nil) goto v_27770;
    else goto v_27771;
v_27770:
    v_27809 = v_27811;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_27809);
    }
v_27771:
    goto v_27781;
v_27777:
    v_27809 = stack[-1];
    v_27810 = qcar(v_27809);
    goto v_27778;
v_27779:
    v_27809 = stack[0];
    v_27809 = qcar(v_27809);
    v_27809 = qcar(v_27809);
    goto v_27780;
v_27781:
    goto v_27777;
v_27778:
    goto v_27779;
v_27780:
    if (v_27810 == v_27809) goto v_27775;
    else goto v_27776;
v_27775:
    goto v_27792;
v_27788:
    v_27810 = v_27811;
    goto v_27789;
v_27790:
    v_27809 = stack[0];
    v_27809 = qcdr(v_27809);
    goto v_27791;
v_27792:
    goto v_27788;
v_27789:
    goto v_27790;
v_27791:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_27810, v_27809);
    }
v_27776:
    goto v_27803;
v_27799:
    v_27809 = stack[0];
    v_27809 = qcar(v_27809);
    goto v_27800;
v_27801:
    v_27810 = v_27811;
    goto v_27802;
v_27803:
    goto v_27799;
v_27800:
    goto v_27801;
v_27802:
    v_27809 = cons(v_27809, v_27810);
    env = stack[-2];
    v_27811 = v_27809;
    v_27809 = stack[0];
    v_27809 = qcdr(v_27809);
    stack[0] = v_27809;
    goto v_27767;
    v_27809 = nil;
    return onevalue(v_27809);
}



// Code for reduce!-ratios

static LispObject CC_reduceKratios(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27829, v_27830;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_27762;
    stack[-2] = v_27761;
// end of prologue
v_27760:
    goto v_27776;
v_27772:
    v_27830 = stack[-2];
    goto v_27773;
v_27774:
    v_27829 = stack[-1];
    goto v_27775;
v_27776:
    goto v_27772;
v_27773:
    goto v_27774;
v_27775:
    fn = elt(env, 1); // red!-ratios1
    v_27829 = (*qfn2(fn))(fn, v_27830, v_27829);
    env = stack[-4];
    stack[-3] = v_27829;
    if (v_27829 == nil) goto v_27769;
    else goto v_27770;
v_27769:
    v_27829 = stack[-2];
    goto v_27766;
v_27770:
    goto v_27785;
v_27781:
    goto v_27791;
v_27787:
    v_27829 = stack[-3];
    v_27830 = qcar(v_27829);
    goto v_27788;
v_27789:
    v_27829 = stack[-2];
    goto v_27790;
v_27791:
    goto v_27787;
v_27788:
    goto v_27789;
v_27790:
    fn = elt(env, 2); // mv!-domainlist!-!*
    stack[0] = (*qfn2(fn))(fn, v_27830, v_27829);
    env = stack[-4];
    goto v_27782;
v_27783:
    goto v_27800;
v_27796:
    v_27829 = stack[-3];
    v_27830 = qcdr(v_27829);
    goto v_27797;
v_27798:
    v_27829 = stack[-1];
    goto v_27799;
v_27800:
    goto v_27796;
v_27797:
    goto v_27798;
v_27799:
    fn = elt(env, 2); // mv!-domainlist!-!*
    v_27829 = (*qfn2(fn))(fn, v_27830, v_27829);
    env = stack[-4];
    goto v_27784;
v_27785:
    goto v_27781;
v_27782:
    goto v_27783;
v_27784:
    fn = elt(env, 3); // mv!-domainlist!-!-
    v_27829 = (*qfn2(fn))(fn, stack[0], v_27829);
    env = stack[-4];
    stack[-3] = v_27829;
    goto v_27813;
v_27809:
    v_27829 = stack[-2];
    fn = elt(env, 4); // reddom_zeros
    stack[0] = (*qfn1(fn))(fn, v_27829);
    env = stack[-4];
    goto v_27810;
v_27811:
    v_27829 = stack[-3];
    fn = elt(env, 4); // reddom_zeros
    v_27829 = (*qfn1(fn))(fn, v_27829);
    env = stack[-4];
    goto v_27812;
v_27813:
    goto v_27809;
v_27810:
    goto v_27811;
v_27812:
    v_27829 = (LispObject)geq2(stack[0], v_27829);
    v_27829 = v_27829 ? lisp_true : nil;
    env = stack[-4];
    if (v_27829 == nil) goto v_27807;
    v_27829 = stack[-2];
    goto v_27805;
v_27807:
    goto v_27826;
v_27822:
    v_27830 = stack[-3];
    goto v_27823;
v_27824:
    v_27829 = stack[-1];
    goto v_27825;
v_27826:
    goto v_27822;
v_27823:
    goto v_27824;
v_27825:
    stack[-2] = v_27830;
    stack[-1] = v_27829;
    goto v_27760;
    v_27829 = nil;
v_27805:
v_27766:
    return onevalue(v_27829);
}



// Code for fs!:subang

static LispObject CC_fsTsubang(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27946, v_27947, v_27948, v_27949;
    LispObject fn;
    LispObject v_27763, v_27762, v_27761;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "fs:subang");
    va_start(aa, nargs);
    v_27761 = va_arg(aa, LispObject);
    v_27762 = va_arg(aa, LispObject);
    v_27763 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27763,v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27761,v_27762,v_27763);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-5] = v_27763;
    stack[-6] = v_27762;
    stack[-7] = v_27761;
// end of prologue
    v_27946 = stack[-7];
    if (v_27946 == nil) goto v_27767;
    else goto v_27768;
v_27767:
    v_27946 = nil;
    goto v_27766;
v_27768:
    v_27946 = (LispObject)112+TAG_FIXNUM; // 7
    v_27946 = Lmkvect(nil, v_27946);
    env = stack[-9];
    stack[-8] = v_27946;
    goto v_27783;
v_27779:
    goto v_27788;
v_27784:
    v_27947 = stack[-7];
    goto v_27785;
v_27786:
    v_27946 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_27787;
v_27788:
    goto v_27784;
v_27785:
    goto v_27786;
v_27787:
    v_27947 = *(LispObject *)((char *)v_27947 + (CELL-TAG_VECTOR) + (((intptr_t)v_27946-TAG_FIXNUM)/(16/CELL)));
    goto v_27780;
v_27781:
    v_27946 = stack[-6];
    goto v_27782;
v_27783:
    goto v_27779;
v_27780:
    goto v_27781;
v_27782:
    v_27946 = *(LispObject *)((char *)v_27947 + (CELL-TAG_VECTOR) + (((intptr_t)v_27946-TAG_FIXNUM)/(16/CELL)));
    stack[-4] = v_27946;
    v_27946 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_27946;
v_27797:
    goto v_27809;
v_27805:
    v_27947 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_27806;
v_27807:
    v_27946 = stack[-3];
    goto v_27808;
v_27809:
    goto v_27805;
v_27806:
    goto v_27807;
v_27808:
    v_27946 = difference2(v_27947, v_27946);
    env = stack[-9];
    v_27946 = Lminusp(nil, v_27946);
    env = stack[-9];
    if (v_27946 == nil) goto v_27802;
    goto v_27796;
v_27802:
    goto v_27821;
v_27817:
    v_27947 = stack[-3];
    goto v_27818;
v_27819:
    v_27946 = stack[-6];
    goto v_27820;
v_27821:
    goto v_27817;
v_27818:
    goto v_27819;
v_27820:
    if (equal(v_27947, v_27946)) goto v_27815;
    else goto v_27816;
v_27815:
    goto v_27830;
v_27824:
    stack[-1] = stack[-8];
    goto v_27825;
v_27826:
    stack[0] = stack[-3];
    goto v_27827;
v_27828:
    goto v_27838;
v_27834:
    v_27948 = stack[-4];
    goto v_27835;
v_27836:
    goto v_27844;
v_27840:
    v_27947 = stack[-5];
    goto v_27841;
v_27842:
    v_27946 = stack[-3];
    goto v_27843;
v_27844:
    goto v_27840;
v_27841:
    goto v_27842;
v_27843:
    v_27946 = *(LispObject *)((char *)v_27947 + (CELL-TAG_VECTOR) + (((intptr_t)v_27946-TAG_FIXNUM)/(16/CELL)));
    goto v_27837;
v_27838:
    goto v_27834;
v_27835:
    goto v_27836;
v_27837:
    v_27946 = times2(v_27948, v_27946);
    env = stack[-9];
    goto v_27829;
v_27830:
    goto v_27824;
v_27825:
    goto v_27826;
v_27827:
    goto v_27828;
v_27829:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_27946;
    goto v_27814;
v_27816:
    goto v_27856;
v_27850:
    stack[-2] = stack[-8];
    goto v_27851;
v_27852:
    stack[-1] = stack[-3];
    goto v_27853;
v_27854:
    goto v_27864;
v_27860:
    goto v_27869;
v_27865:
    goto v_27874;
v_27870:
    v_27947 = stack[-7];
    goto v_27871;
v_27872:
    v_27946 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_27873;
v_27874:
    goto v_27870;
v_27871:
    goto v_27872;
v_27873:
    v_27947 = *(LispObject *)((char *)v_27947 + (CELL-TAG_VECTOR) + (((intptr_t)v_27946-TAG_FIXNUM)/(16/CELL)));
    goto v_27866;
v_27867:
    v_27946 = stack[-3];
    goto v_27868;
v_27869:
    goto v_27865;
v_27866:
    goto v_27867;
v_27868:
    stack[0] = *(LispObject *)((char *)v_27947 + (CELL-TAG_VECTOR) + (((intptr_t)v_27946-TAG_FIXNUM)/(16/CELL)));
    goto v_27861;
v_27862:
    goto v_27885;
v_27881:
    v_27948 = stack[-4];
    goto v_27882;
v_27883:
    goto v_27891;
v_27887:
    v_27947 = stack[-5];
    goto v_27888;
v_27889:
    v_27946 = stack[-3];
    goto v_27890;
v_27891:
    goto v_27887;
v_27888:
    goto v_27889;
v_27890:
    v_27946 = *(LispObject *)((char *)v_27947 + (CELL-TAG_VECTOR) + (((intptr_t)v_27946-TAG_FIXNUM)/(16/CELL)));
    goto v_27884;
v_27885:
    goto v_27881;
v_27882:
    goto v_27883;
v_27884:
    v_27946 = times2(v_27948, v_27946);
    env = stack[-9];
    goto v_27863;
v_27864:
    goto v_27860;
v_27861:
    goto v_27862;
v_27863:
    v_27946 = plus2(stack[0], v_27946);
    env = stack[-9];
    goto v_27855;
v_27856:
    goto v_27850;
v_27851:
    goto v_27852;
v_27853:
    goto v_27854;
v_27855:
    *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-1]-TAG_FIXNUM)/(16/CELL))) = v_27946;
    goto v_27814;
v_27814:
    v_27946 = stack[-3];
    v_27946 = add1(v_27946);
    env = stack[-9];
    stack[-3] = v_27946;
    goto v_27797;
v_27796:
    goto v_27902;
v_27898:
    goto v_27910;
v_27904:
    goto v_27915;
v_27911:
    v_27947 = stack[-7];
    goto v_27912;
v_27913:
    v_27946 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_27914;
v_27915:
    goto v_27911;
v_27912:
    goto v_27913;
v_27914:
    v_27948 = *(LispObject *)((char *)v_27947 + (CELL-TAG_VECTOR) + (((intptr_t)v_27946-TAG_FIXNUM)/(16/CELL)));
    goto v_27905;
v_27906:
    v_27947 = stack[-6];
    goto v_27907;
v_27908:
    v_27946 = stack[-5];
    goto v_27909;
v_27910:
    goto v_27904;
v_27905:
    goto v_27906;
v_27907:
    goto v_27908;
v_27909:
    stack[0] = CC_fsTsubang(elt(env, 0), 3, v_27948, v_27947, v_27946);
    env = stack[-9];
    goto v_27899;
v_27900:
    goto v_27928;
v_27922:
    goto v_27933;
v_27929:
    v_27947 = stack[-7];
    goto v_27930;
v_27931:
    v_27946 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27932;
v_27933:
    goto v_27929;
v_27930:
    goto v_27931;
v_27932:
    v_27949 = *(LispObject *)((char *)v_27947 + (CELL-TAG_VECTOR) + (((intptr_t)v_27946-TAG_FIXNUM)/(16/CELL)));
    goto v_27923;
v_27924:
    v_27948 = stack[-8];
    goto v_27925;
v_27926:
    goto v_27942;
v_27938:
    v_27947 = stack[-7];
    goto v_27939;
v_27940:
    v_27946 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27941;
v_27942:
    goto v_27938;
v_27939:
    goto v_27940;
v_27941:
    v_27946 = *(LispObject *)((char *)v_27947 + (CELL-TAG_VECTOR) + (((intptr_t)v_27946-TAG_FIXNUM)/(16/CELL)));
    goto v_27927;
v_27928:
    goto v_27922;
v_27923:
    goto v_27924;
v_27925:
    goto v_27926;
v_27927:
    fn = elt(env, 1); // make!-term
    v_27946 = (*qfnn(fn))(fn, 3, v_27949, v_27948, v_27946);
    env = stack[-9];
    goto v_27901;
v_27902:
    goto v_27898;
v_27899:
    goto v_27900;
v_27901:
    {
        LispObject v_27959 = stack[0];
        fn = elt(env, 2); // fs!:plus
        return (*qfn2(fn))(fn, v_27959, v_27946);
    }
    goto v_27766;
    v_27946 = nil;
v_27766:
    return onevalue(v_27946);
}



// Code for addnew

static LispObject CC_addnew(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27809, v_27810, v_27811, v_27812, v_27813;
    LispObject fn;
    LispObject v_27763, v_27762, v_27761;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "addnew");
    va_start(aa, nargs);
    v_27761 = va_arg(aa, LispObject);
    v_27762 = va_arg(aa, LispObject);
    v_27763 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27763,v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27761,v_27762,v_27763);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27763;
    v_27812 = v_27762;
    v_27813 = v_27761;
// end of prologue
    goto v_27771;
v_27765:
    v_27811 = qvalue(elt(env, 1)); // gv!*
    goto v_27766;
v_27767:
    v_27810 = v_27812;
    goto v_27768;
v_27769:
    v_27809 = v_27813;
    goto v_27770;
v_27771:
    goto v_27765;
v_27766:
    goto v_27767;
v_27768:
    goto v_27769;
v_27770:
    *(LispObject *)((char *)v_27811 + (CELL-TAG_VECTOR) + (((intptr_t)v_27810-TAG_FIXNUM)/(16/CELL))) = v_27809;
    goto v_27781;
v_27775:
    v_27811 = qvalue(elt(env, 2)); // bv!*
    goto v_27776;
v_27777:
    v_27810 = v_27812;
    goto v_27778;
v_27779:
    v_27809 = lisp_true;
    goto v_27780;
v_27781:
    goto v_27775;
v_27776:
    goto v_27777;
v_27778:
    goto v_27779;
v_27780:
    *(LispObject *)((char *)v_27811 + (CELL-TAG_VECTOR) + (((intptr_t)v_27810-TAG_FIXNUM)/(16/CELL))) = v_27809;
    v_27809 = v_27813;
    if (v_27809 == nil) goto v_27787;
    else goto v_27788;
v_27787:
    v_27809 = stack[0];
    goto v_27786;
v_27788:
    goto v_27798;
v_27794:
    goto v_27804;
v_27800:
    stack[-1] = v_27812;
    goto v_27801;
v_27802:
    v_27809 = v_27813;
    fn = elt(env, 3); // ljet
    v_27809 = (*qfn1(fn))(fn, v_27809);
    env = stack[-2];
    goto v_27803;
v_27804:
    goto v_27800;
v_27801:
    goto v_27802;
v_27803:
    v_27810 = cons(stack[-1], v_27809);
    env = stack[-2];
    goto v_27795;
v_27796:
    v_27809 = stack[0];
    goto v_27797;
v_27798:
    goto v_27794;
v_27795:
    goto v_27796;
v_27797:
    fn = elt(env, 4); // insert
    v_27809 = (*qfn2(fn))(fn, v_27810, v_27809);
    goto v_27786;
    v_27809 = nil;
v_27786:
    return onevalue(v_27809);
}



// Code for flattens1

static LispObject CC_flattens1(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27793;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27761;
// end of prologue
v_27765:
    v_27793 = stack[0];
    if (!consp(v_27793)) goto v_27768;
    else goto v_27769;
v_27768:
    v_27793 = stack[0];
    return ncons(v_27793);
v_27769:
    v_27793 = stack[0];
    v_27793 = qcdr(v_27793);
    if (v_27793 == nil) goto v_27774;
    goto v_27782;
v_27778:
    v_27793 = stack[0];
    v_27793 = qcar(v_27793);
    stack[-1] = CC_flattens1(elt(env, 0), v_27793);
    env = stack[-2];
    goto v_27779;
v_27780:
    v_27793 = stack[0];
    v_27793 = qcdr(v_27793);
    v_27793 = CC_flattens1(elt(env, 0), v_27793);
    goto v_27781;
v_27782:
    goto v_27778;
v_27779:
    goto v_27780;
v_27781:
    {
        LispObject v_27796 = stack[-1];
        return Lappend(nil, v_27796, v_27793);
    }
v_27774:
    v_27793 = stack[0];
    v_27793 = qcar(v_27793);
    stack[0] = v_27793;
    goto v_27765;
    v_27793 = nil;
    return onevalue(v_27793);
}



// Code for pst_mkpst

static LispObject CC_pst_mkpst(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27773;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_27773 = v_27761;
// end of prologue
    goto v_27769;
v_27765:
    stack[0] = nil;
    goto v_27766;
v_27767:
    fn = elt(env, 1); // pst_mkpst1
    v_27773 = (*qfn1(fn))(fn, v_27773);
    env = stack[-1];
    goto v_27768;
v_27769:
    goto v_27765;
v_27766:
    goto v_27767;
v_27768:
    v_27773 = cons(stack[0], v_27773);
    env = stack[-1];
    {
        fn = elt(env, 2); // pst_equitable
        return (*qfn1(fn))(fn, v_27773);
    }
}



// Code for taylorp

static LispObject CC_taylorp(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27771, v_27772;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27771 = v_27761;
// end of prologue
    goto v_27768;
v_27764:
    goto v_27765;
v_27766:
    v_27772 = elt(env, 1); // taylor
    goto v_27767;
v_27768:
    goto v_27764;
v_27765:
    goto v_27766;
v_27767:
        return Leqcar(nil, v_27771, v_27772);
}



// Code for get!-new!-prime

static LispObject CC_getKnewKprime(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27853, v_27854;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_27761;
// end of prologue
    v_27853 = qvalue(elt(env, 1)); // !*force!-prime
    if (v_27853 == nil) goto v_27766;
    v_27853 = qvalue(elt(env, 1)); // !*force!-prime
    goto v_27764;
v_27766:
    stack[-3] = nil;
    v_27853 = stack[-2];
    stack[-1] = v_27853;
v_27779:
    v_27853 = stack[-1];
    if (v_27853 == nil) goto v_27783;
    else goto v_27784;
v_27783:
    goto v_27778;
v_27784:
    v_27853 = stack[-1];
    v_27853 = qcar(v_27853);
    stack[0] = v_27853;
    goto v_27799;
v_27795:
    v_27854 = stack[0];
    goto v_27796;
v_27797:
    v_27853 = (LispObject)512+TAG_FIXNUM; // 32
    goto v_27798;
v_27799:
    goto v_27795;
v_27796:
    goto v_27797;
v_27798:
    v_27853 = (LispObject)lessp2(v_27854, v_27853);
    v_27853 = v_27853 ? lisp_true : nil;
    env = stack[-4];
    if (v_27853 == nil) goto v_27793;
    goto v_27807;
v_27803:
    v_27854 = stack[0];
    goto v_27804;
v_27805:
    v_27853 = stack[-3];
    goto v_27806;
v_27807:
    goto v_27803;
v_27804:
    goto v_27805;
v_27806:
    v_27853 = cons(v_27854, v_27853);
    env = stack[-4];
    stack[-3] = v_27853;
    goto v_27791;
v_27793:
v_27791:
    v_27853 = stack[-1];
    v_27853 = qcdr(v_27853);
    stack[-1] = v_27853;
    goto v_27779;
v_27778:
v_27775:
    v_27853 = stack[-3];
    fn = elt(env, 4); // random!-teeny!-prime
    v_27853 = (*qfn1(fn))(fn, v_27853);
    env = stack[-4];
    stack[0] = v_27853;
    if (v_27853 == nil) goto v_27814;
    else goto v_27815;
v_27814:
    fn = elt(env, 5); // random!-small!-prime
    v_27853 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[0] = v_27853;
    v_27853 = elt(env, 2); // all
    stack[-3] = v_27853;
    goto v_27813;
v_27815:
    goto v_27827;
v_27823:
    v_27854 = stack[0];
    goto v_27824;
v_27825:
    v_27853 = stack[-3];
    goto v_27826;
v_27827:
    goto v_27823;
v_27824:
    goto v_27825;
v_27826:
    v_27853 = cons(v_27854, v_27853);
    env = stack[-4];
    stack[-3] = v_27853;
    goto v_27813;
v_27813:
    goto v_27839;
v_27835:
    v_27854 = stack[0];
    goto v_27836;
v_27837:
    v_27853 = stack[-2];
    goto v_27838;
v_27839:
    goto v_27835;
v_27836:
    goto v_27837;
v_27838:
    v_27853 = Lmember(nil, v_27854, v_27853);
    if (v_27853 == nil) goto v_27834;
    else goto v_27832;
v_27834:
    goto v_27849;
v_27845:
    v_27854 = stack[0];
    goto v_27846;
v_27847:
    v_27853 = qvalue(elt(env, 3)); // smallest!-prime
    goto v_27848;
v_27849:
    goto v_27845;
v_27846:
    goto v_27847;
v_27848:
    v_27853 = (LispObject)lesseq2(v_27854, v_27853);
    v_27853 = v_27853 ? lisp_true : nil;
    env = stack[-4];
    if (v_27853 == nil) goto v_27843;
    else goto v_27832;
v_27843:
    goto v_27833;
v_27832:
    goto v_27775;
v_27833:
    v_27853 = stack[0];
    goto v_27764;
    v_27853 = nil;
v_27764:
    return onevalue(v_27853);
}



// Code for min2!-order

static LispObject CC_min2Korder(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27845, v_27846;
    LispObject fn;
    LispObject v_27763, v_27762, v_27761;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "min2-order");
    va_start(aa, nargs);
    v_27761 = va_arg(aa, LispObject);
    v_27762 = va_arg(aa, LispObject);
    v_27763 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27763,v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27761,v_27762,v_27763);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_27763;
    stack[-2] = v_27762;
    stack[-3] = v_27761;
// end of prologue
    stack[-4] = nil;
v_27768:
    v_27845 = stack[-3];
    if (v_27845 == nil) goto v_27771;
    else goto v_27772;
v_27771:
    v_27845 = stack[-4];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_27845);
    }
v_27772:
    goto v_27783;
v_27779:
    v_27845 = stack[-1];
    v_27845 = qcar(v_27845);
    stack[0] = v_27845;
    v_27845 = (LispObject)0+TAG_FIXNUM; // 0
    v_27846 = v_27845;
v_27788:
    v_27845 = stack[0];
    if (v_27845 == nil) goto v_27794;
    else goto v_27795;
v_27794:
    v_27845 = v_27846;
    goto v_27787;
v_27795:
    goto v_27803;
v_27799:
    v_27845 = stack[0];
    v_27845 = qcar(v_27845);
    goto v_27800;
v_27801:
    goto v_27802;
v_27803:
    goto v_27799;
v_27800:
    goto v_27801;
v_27802:
    fn = elt(env, 2); // tayexp!-plus2
    v_27845 = (*qfn2(fn))(fn, v_27845, v_27846);
    env = stack[-5];
    v_27846 = v_27845;
    v_27845 = stack[0];
    v_27845 = qcdr(v_27845);
    stack[0] = v_27845;
    goto v_27788;
v_27787:
    stack[0] = v_27845;
    goto v_27821;
v_27817:
    v_27846 = stack[0];
    goto v_27818;
v_27819:
    v_27845 = stack[-2];
    v_27845 = qcar(v_27845);
    goto v_27820;
v_27821:
    goto v_27817;
v_27818:
    goto v_27819;
v_27820:
    fn = elt(env, 3); // tayexp!-greaterp
    v_27845 = (*qfn2(fn))(fn, v_27846, v_27845);
    env = stack[-5];
    if (v_27845 == nil) goto v_27815;
    goto v_27830;
v_27826:
    v_27846 = stack[0];
    goto v_27827;
v_27828:
    v_27845 = stack[-3];
    v_27845 = qcar(v_27845);
    goto v_27829;
v_27830:
    goto v_27826;
v_27827:
    goto v_27828;
v_27829:
    fn = elt(env, 4); // tayexp!-min2
    v_27845 = (*qfn2(fn))(fn, v_27846, v_27845);
    env = stack[-5];
    v_27846 = v_27845;
    goto v_27813;
v_27815:
    v_27845 = stack[-3];
    v_27845 = qcar(v_27845);
    v_27846 = v_27845;
    goto v_27813;
    v_27846 = nil;
v_27813:
    goto v_27780;
v_27781:
    v_27845 = stack[-4];
    goto v_27782;
v_27783:
    goto v_27779;
v_27780:
    goto v_27781;
v_27782:
    v_27845 = cons(v_27846, v_27845);
    env = stack[-5];
    stack[-4] = v_27845;
    v_27845 = stack[-3];
    v_27845 = qcdr(v_27845);
    stack[-3] = v_27845;
    v_27845 = stack[-2];
    v_27845 = qcdr(v_27845);
    stack[-2] = v_27845;
    v_27845 = stack[-1];
    v_27845 = qcdr(v_27845);
    stack[-1] = v_27845;
    goto v_27768;
    v_27845 = nil;
    return onevalue(v_27845);
}



// Code for bc_dcont

static LispObject CC_bc_dcont(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27766;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27766 = v_27761;
// end of prologue
    v_27766 = qcar(v_27766);
    {
        fn = elt(env, 1); // sfto_dcontentf
        return (*qfn1(fn))(fn, v_27766);
    }
}



// Code for evalgeq

static LispObject CC_evalgeq(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27773, v_27774;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
// copy arguments values to proper place
    v_27773 = v_27762;
    v_27774 = v_27761;
// end of prologue
    goto v_27769;
v_27765:
    goto v_27766;
v_27767:
    goto v_27768;
v_27769:
    goto v_27765;
v_27766:
    goto v_27767;
v_27768:
    fn = elt(env, 1); // evallessp
    v_27773 = (*qfn2(fn))(fn, v_27774, v_27773);
    v_27773 = (v_27773 == nil ? lisp_true : nil);
    return onevalue(v_27773);
}



// Code for exp!*

static LispObject CC_expH(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27771, v_27772;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27771 = v_27761;
// end of prologue
    goto v_27768;
v_27764:
    v_27772 = v_27771;
    goto v_27765;
v_27766:
    v_27771 = qvalue(elt(env, 1)); // !:bprec!:
    goto v_27767;
v_27768:
    goto v_27764;
v_27765:
    goto v_27766;
v_27767:
    {
        fn = elt(env, 2); // exp!:
        return (*qfn2(fn))(fn, v_27772, v_27771);
    }
}



// Code for mk_names_map_2

static LispObject CC_mk_names_map_2(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27814, v_27815;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_27814 = v_27761;
// end of prologue
    goto v_27774;
v_27770:
    v_27815 = v_27814;
    v_27815 = qcar(v_27815);
    goto v_27771;
v_27772:
    v_27814 = qcdr(v_27814);
    goto v_27773;
v_27774:
    goto v_27770;
v_27771:
    goto v_27772;
v_27773:
    v_27814 = Lappend(nil, v_27815, v_27814);
    env = stack[-4];
    stack[-3] = v_27814;
    v_27814 = stack[-3];
    if (v_27814 == nil) goto v_27781;
    else goto v_27782;
v_27781:
    v_27814 = nil;
    goto v_27767;
v_27782:
    v_27814 = stack[-3];
    v_27814 = qcar(v_27814);
    v_27814 = qcar(v_27814);
    v_27814 = ncons(v_27814);
    env = stack[-4];
    stack[-1] = v_27814;
    stack[-2] = v_27814;
v_27768:
    v_27814 = stack[-3];
    v_27814 = qcdr(v_27814);
    stack[-3] = v_27814;
    v_27814 = stack[-3];
    if (v_27814 == nil) goto v_27795;
    else goto v_27796;
v_27795:
    v_27814 = stack[-2];
    goto v_27767;
v_27796:
    goto v_27804;
v_27800:
    stack[0] = stack[-1];
    goto v_27801;
v_27802:
    v_27814 = stack[-3];
    v_27814 = qcar(v_27814);
    v_27814 = qcar(v_27814);
    v_27814 = ncons(v_27814);
    env = stack[-4];
    goto v_27803;
v_27804:
    goto v_27800;
v_27801:
    goto v_27802;
v_27803:
    v_27814 = Lrplacd(nil, stack[0], v_27814);
    env = stack[-4];
    v_27814 = stack[-1];
    v_27814 = qcdr(v_27814);
    stack[-1] = v_27814;
    goto v_27768;
v_27767:
    return onevalue(v_27814);
}



// Code for general!-modular!-difference

static LispObject CC_generalKmodularKdifference(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27796, v_27797;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_27796 = v_27762;
    v_27797 = v_27761;
// end of prologue
    goto v_27772;
v_27768:
    goto v_27769;
v_27770:
    goto v_27771;
v_27772:
    goto v_27768;
v_27769:
    goto v_27770;
v_27771:
    v_27796 = difference2(v_27797, v_27796);
    env = stack[-1];
    stack[0] = v_27796;
    goto v_27784;
v_27780:
    v_27797 = stack[0];
    goto v_27781;
v_27782:
    v_27796 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27783;
v_27784:
    goto v_27780;
v_27781:
    goto v_27782;
v_27783:
    v_27796 = (LispObject)lessp2(v_27797, v_27796);
    v_27796 = v_27796 ? lisp_true : nil;
    env = stack[-1];
    if (v_27796 == nil) goto v_27778;
    goto v_27792;
v_27788:
    v_27797 = stack[0];
    goto v_27789;
v_27790:
    v_27796 = qvalue(elt(env, 1)); // current!-modulus
    goto v_27791;
v_27792:
    goto v_27788;
v_27789:
    goto v_27790;
v_27791:
    v_27796 = plus2(v_27797, v_27796);
    stack[0] = v_27796;
    goto v_27776;
v_27778:
v_27776:
    v_27796 = stack[0];
    return onevalue(v_27796);
}



// Code for ofsf_smmkatl!-and1

static LispObject CC_ofsf_smmkatlKand1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27941, v_27942, v_27943;
    LispObject fn;
    LispObject v_27763, v_27762, v_27761;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_smmkatl-and1");
    va_start(aa, nargs);
    v_27761 = va_arg(aa, LispObject);
    v_27762 = va_arg(aa, LispObject);
    v_27763 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27763,v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27761,v_27762,v_27763);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_27763;
    stack[0] = v_27762;
    stack[-6] = v_27761;
// end of prologue
    goto v_27774;
v_27770:
    v_27941 = stack[0];
    v_27942 = qcar(v_27941);
    goto v_27771;
v_27772:
    v_27941 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27773;
v_27774:
    goto v_27770;
v_27771:
    goto v_27772;
v_27773:
    v_27941 = cons(v_27942, v_27941);
    env = stack[-8];
    stack[-7] = v_27941;
    v_27941 = stack[0];
    v_27941 = qcdr(v_27941);
    stack[-4] = v_27941;
v_27783:
    v_27941 = stack[-4];
    if (v_27941 == nil) goto v_27789;
    else goto v_27790;
v_27789:
    v_27941 = nil;
    goto v_27782;
v_27790:
    v_27941 = stack[-4];
    v_27941 = qcar(v_27941);
    stack[0] = v_27941;
    goto v_27804;
v_27800:
    v_27941 = stack[0];
    v_27942 = qcar(v_27941);
    goto v_27801;
v_27802:
    v_27941 = stack[-5];
    goto v_27803;
v_27804:
    goto v_27800;
v_27801:
    goto v_27802;
v_27803:
    if (equal(v_27942, v_27941)) goto v_27798;
    else goto v_27799;
v_27798:
    goto v_27817;
v_27813:
    v_27941 = stack[0];
    v_27941 = qcdr(v_27941);
    v_27942 = qcar(v_27941);
    goto v_27814;
v_27815:
    v_27941 = elt(env, 1); // (lessp greaterp)
    goto v_27816;
v_27817:
    goto v_27813;
v_27814:
    goto v_27815;
v_27816:
    v_27941 = Lmemq(nil, v_27942, v_27941);
    if (v_27941 == nil) goto v_27811;
    goto v_27831;
v_27825:
    v_27941 = stack[-6];
    v_27943 = qcdr(v_27941);
    goto v_27826;
v_27827:
    v_27941 = stack[0];
    v_27942 = qcdr(v_27941);
    goto v_27828;
v_27829:
    v_27941 = stack[-7];
    goto v_27830;
v_27831:
    goto v_27825;
v_27826:
    goto v_27827;
v_27828:
    goto v_27829;
v_27830:
    fn = elt(env, 3); // ofsf_smmkat!-and2
    v_27941 = (*qfnn(fn))(fn, 3, v_27943, v_27942, v_27941);
    env = stack[-8];
    v_27942 = v_27941;
    if (v_27941 == nil) goto v_27811;
    v_27941 = v_27942;
    v_27941 = ncons(v_27941);
    env = stack[-8];
    goto v_27809;
v_27811:
    goto v_27849;
v_27843:
    v_27943 = elt(env, 2); // and
    goto v_27844;
v_27845:
    v_27941 = stack[0];
    v_27942 = qcdr(v_27941);
    goto v_27846;
v_27847:
    v_27941 = stack[-7];
    goto v_27848;
v_27849:
    goto v_27843;
v_27844:
    goto v_27845;
v_27846:
    goto v_27847;
v_27848:
    fn = elt(env, 4); // ofsf_entry2at
    v_27941 = (*qfnn(fn))(fn, 3, v_27943, v_27942, v_27941);
    env = stack[-8];
    v_27941 = ncons(v_27941);
    env = stack[-8];
    goto v_27809;
    v_27941 = nil;
v_27809:
    goto v_27797;
v_27799:
    v_27941 = nil;
v_27797:
    stack[-3] = v_27941;
    v_27941 = stack[-3];
    fn = elt(env, 5); // lastpair
    v_27941 = (*qfn1(fn))(fn, v_27941);
    env = stack[-8];
    stack[-2] = v_27941;
    v_27941 = stack[-4];
    v_27941 = qcdr(v_27941);
    stack[-4] = v_27941;
    v_27941 = stack[-2];
    if (!consp(v_27941)) goto v_27860;
    else goto v_27861;
v_27860:
    goto v_27783;
v_27861:
v_27784:
    v_27941 = stack[-4];
    if (v_27941 == nil) goto v_27865;
    else goto v_27866;
v_27865:
    v_27941 = stack[-3];
    goto v_27782;
v_27866:
    goto v_27874;
v_27870:
    stack[-1] = stack[-2];
    goto v_27871;
v_27872:
    v_27941 = stack[-4];
    v_27941 = qcar(v_27941);
    stack[0] = v_27941;
    goto v_27887;
v_27883:
    v_27941 = stack[0];
    v_27942 = qcar(v_27941);
    goto v_27884;
v_27885:
    v_27941 = stack[-5];
    goto v_27886;
v_27887:
    goto v_27883;
v_27884:
    goto v_27885;
v_27886:
    if (equal(v_27942, v_27941)) goto v_27881;
    else goto v_27882;
v_27881:
    goto v_27900;
v_27896:
    v_27941 = stack[0];
    v_27941 = qcdr(v_27941);
    v_27942 = qcar(v_27941);
    goto v_27897;
v_27898:
    v_27941 = elt(env, 1); // (lessp greaterp)
    goto v_27899;
v_27900:
    goto v_27896;
v_27897:
    goto v_27898;
v_27899:
    v_27941 = Lmemq(nil, v_27942, v_27941);
    if (v_27941 == nil) goto v_27894;
    goto v_27914;
v_27908:
    v_27941 = stack[-6];
    v_27943 = qcdr(v_27941);
    goto v_27909;
v_27910:
    v_27941 = stack[0];
    v_27942 = qcdr(v_27941);
    goto v_27911;
v_27912:
    v_27941 = stack[-7];
    goto v_27913;
v_27914:
    goto v_27908;
v_27909:
    goto v_27910;
v_27911:
    goto v_27912;
v_27913:
    fn = elt(env, 3); // ofsf_smmkat!-and2
    v_27941 = (*qfnn(fn))(fn, 3, v_27943, v_27942, v_27941);
    env = stack[-8];
    v_27942 = v_27941;
    if (v_27941 == nil) goto v_27894;
    v_27941 = v_27942;
    v_27941 = ncons(v_27941);
    env = stack[-8];
    goto v_27892;
v_27894:
    goto v_27932;
v_27926:
    v_27943 = elt(env, 2); // and
    goto v_27927;
v_27928:
    v_27941 = stack[0];
    v_27942 = qcdr(v_27941);
    goto v_27929;
v_27930:
    v_27941 = stack[-7];
    goto v_27931;
v_27932:
    goto v_27926;
v_27927:
    goto v_27928;
v_27929:
    goto v_27930;
v_27931:
    fn = elt(env, 4); // ofsf_entry2at
    v_27941 = (*qfnn(fn))(fn, 3, v_27943, v_27942, v_27941);
    env = stack[-8];
    v_27941 = ncons(v_27941);
    env = stack[-8];
    goto v_27892;
    v_27941 = nil;
v_27892:
    goto v_27880;
v_27882:
    v_27941 = nil;
v_27880:
    goto v_27873;
v_27874:
    goto v_27870;
v_27871:
    goto v_27872;
v_27873:
    v_27941 = Lrplacd(nil, stack[-1], v_27941);
    env = stack[-8];
    v_27941 = stack[-2];
    fn = elt(env, 5); // lastpair
    v_27941 = (*qfn1(fn))(fn, v_27941);
    env = stack[-8];
    stack[-2] = v_27941;
    v_27941 = stack[-4];
    v_27941 = qcdr(v_27941);
    stack[-4] = v_27941;
    goto v_27784;
v_27782:
    return onevalue(v_27941);
}



// Code for sfchk

static LispObject CC_sfchk(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27774;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27761;
// end of prologue
    v_27774 = stack[0];
    fn = elt(env, 1); // sfp
    v_27774 = (*qfn1(fn))(fn, v_27774);
    env = stack[-1];
    if (v_27774 == nil) goto v_27766;
    v_27774 = stack[0];
    {
        fn = elt(env, 2); // prepf
        return (*qfn1(fn))(fn, v_27774);
    }
v_27766:
    v_27774 = stack[0];
    goto v_27764;
    v_27774 = nil;
v_27764:
    return onevalue(v_27774);
}



// Code for depend!-sq

static LispObject CC_dependKsq(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27785, v_27786;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27762;
    stack[-1] = v_27761;
// end of prologue
    goto v_27772;
v_27768:
    v_27785 = stack[-1];
    v_27786 = qcar(v_27785);
    goto v_27769;
v_27770:
    v_27785 = stack[0];
    goto v_27771;
v_27772:
    goto v_27768;
v_27769:
    goto v_27770;
v_27771:
    fn = elt(env, 1); // depend!-f
    v_27785 = (*qfn2(fn))(fn, v_27786, v_27785);
    env = stack[-2];
    if (v_27785 == nil) goto v_27766;
    else goto v_27765;
v_27766:
    goto v_27781;
v_27777:
    v_27785 = stack[-1];
    v_27786 = qcdr(v_27785);
    goto v_27778;
v_27779:
    v_27785 = stack[0];
    goto v_27780;
v_27781:
    goto v_27777;
v_27778:
    goto v_27779;
v_27780:
    {
        fn = elt(env, 1); // depend!-f
        return (*qfn2(fn))(fn, v_27786, v_27785);
    }
v_27765:
    return onevalue(v_27785);
}



// Code for talp_mkinvop

static LispObject CC_talp_mkinvop(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27786;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27762;
    stack[-1] = v_27761;
// end of prologue
    goto v_27771;
v_27767:
    goto v_27779;
v_27775:
    v_27786 = elt(env, 1); // inv_
    stack[-2] = Lexplode(nil, v_27786);
    env = stack[-3];
    goto v_27776;
v_27777:
    v_27786 = stack[-1];
    v_27786 = ncons(v_27786);
    env = stack[-3];
    goto v_27778;
v_27779:
    goto v_27775;
v_27776:
    goto v_27777;
v_27778:
    v_27786 = Lnconc(nil, stack[-2], v_27786);
    env = stack[-3];
    v_27786 = Lcompress(nil, v_27786);
    env = stack[-3];
    stack[-1] = Lexplode(nil, v_27786);
    env = stack[-3];
    goto v_27768;
v_27769:
    v_27786 = stack[0];
    v_27786 = Lexplode(nil, v_27786);
    env = stack[-3];
    goto v_27770;
v_27771:
    goto v_27767;
v_27768:
    goto v_27769;
v_27770:
    v_27786 = Lnconc(nil, stack[-1], v_27786);
    env = stack[-3];
    v_27786 = Lcompress(nil, v_27786);
        return Lintern(nil, v_27786);
}



// Code for mri_simplfloor1

static LispObject CC_mri_simplfloor1(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27830, v_27831;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_27761;
// end of prologue
    v_27830 = stack[-1];
    if (!consp(v_27830)) goto v_27774;
    else goto v_27775;
v_27774:
    v_27830 = lisp_true;
    goto v_27773;
v_27775:
    v_27830 = stack[-1];
    v_27830 = qcar(v_27830);
    v_27830 = (consp(v_27830) ? nil : lisp_true);
    goto v_27773;
    v_27830 = nil;
v_27773:
    if (v_27830 == nil) goto v_27771;
    v_27830 = stack[-1];
    goto v_27767;
v_27771:
    v_27830 = stack[-1];
    v_27830 = qcar(v_27830);
    v_27830 = qcdr(v_27830);
    fn = elt(env, 1); // mri_simplfloor
    v_27830 = (*qfn1(fn))(fn, v_27830);
    env = stack[-3];
    stack[0] = v_27830;
    v_27830 = stack[-1];
    v_27830 = qcdr(v_27830);
    fn = elt(env, 1); // mri_simplfloor
    v_27830 = (*qfn1(fn))(fn, v_27830);
    env = stack[-3];
    stack[-2] = v_27830;
    v_27830 = stack[-1];
    v_27830 = qcar(v_27830);
    v_27830 = qcar(v_27830);
    v_27830 = qcar(v_27830);
    fn = elt(env, 2); // mri_irsplit
    v_27830 = (*qfn1(fn))(fn, v_27830);
    env = stack[-3];
    goto v_27801;
v_27797:
    goto v_27807;
v_27803:
    goto v_27804;
v_27805:
    goto v_27814;
v_27810:
    goto v_27820;
v_27816:
    v_27831 = v_27830;
    v_27831 = qcar(v_27831);
    goto v_27817;
v_27818:
    v_27830 = qcdr(v_27830);
    goto v_27819;
v_27820:
    goto v_27816;
v_27817:
    goto v_27818;
v_27819:
    fn = elt(env, 3); // addf
    v_27831 = (*qfn2(fn))(fn, v_27831, v_27830);
    env = stack[-3];
    goto v_27811;
v_27812:
    v_27830 = stack[-1];
    v_27830 = qcar(v_27830);
    v_27830 = qcar(v_27830);
    v_27830 = qcdr(v_27830);
    goto v_27813;
v_27814:
    goto v_27810;
v_27811:
    goto v_27812;
v_27813:
    fn = elt(env, 4); // exptf
    v_27830 = (*qfn2(fn))(fn, v_27831, v_27830);
    env = stack[-3];
    goto v_27806;
v_27807:
    goto v_27803;
v_27804:
    goto v_27805;
v_27806:
    fn = elt(env, 5); // multf
    v_27831 = (*qfn2(fn))(fn, stack[0], v_27830);
    env = stack[-3];
    goto v_27798;
v_27799:
    v_27830 = stack[-2];
    goto v_27800;
v_27801:
    goto v_27797;
v_27798:
    goto v_27799;
v_27800:
    {
        fn = elt(env, 3); // addf
        return (*qfn2(fn))(fn, v_27831, v_27830);
    }
v_27767:
    return onevalue(v_27830);
}



// Code for countof

static LispObject CC_countof(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27806, v_27807;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27762;
    stack[-1] = v_27761;
// end of prologue
    goto v_27772;
v_27768:
    v_27807 = stack[-1];
    goto v_27769;
v_27770:
    v_27806 = stack[0];
    goto v_27771;
v_27772:
    goto v_27768;
v_27769:
    goto v_27770;
v_27771:
    if (equal(v_27807, v_27806)) goto v_27766;
    else goto v_27767;
v_27766:
    v_27806 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27765;
v_27767:
    v_27806 = stack[0];
    if (!consp(v_27806)) goto v_27776;
    else goto v_27777;
v_27776:
    v_27806 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27765;
v_27777:
    goto v_27787;
v_27783:
    goto v_27793;
v_27789:
    v_27807 = stack[-1];
    goto v_27790;
v_27791:
    v_27806 = stack[0];
    v_27806 = qcar(v_27806);
    goto v_27792;
v_27793:
    goto v_27789;
v_27790:
    goto v_27791;
v_27792:
    stack[-2] = CC_countof(elt(env, 0), v_27807, v_27806);
    env = stack[-3];
    goto v_27784;
v_27785:
    goto v_27802;
v_27798:
    v_27807 = stack[-1];
    goto v_27799;
v_27800:
    v_27806 = stack[0];
    v_27806 = qcdr(v_27806);
    goto v_27801;
v_27802:
    goto v_27798;
v_27799:
    goto v_27800;
v_27801:
    v_27806 = CC_countof(elt(env, 0), v_27807, v_27806);
    goto v_27786;
v_27787:
    goto v_27783;
v_27784:
    goto v_27785;
v_27786:
    {
        LispObject v_27811 = stack[-2];
        return plus2(v_27811, v_27806);
    }
    v_27806 = nil;
v_27765:
    return onevalue(v_27806);
}



// Code for den

static LispObject CC_den(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27774, v_27775;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_27774 = v_27761;
// end of prologue
    goto v_27769;
v_27765:
    fn = elt(env, 1); // simp!*
    v_27774 = (*qfn1(fn))(fn, v_27774);
    env = stack[0];
    v_27775 = qcdr(v_27774);
    goto v_27766;
v_27767:
    v_27774 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27768;
v_27769:
    goto v_27765;
v_27766:
    goto v_27767;
v_27768:
    v_27774 = cons(v_27775, v_27774);
    env = stack[0];
    {
        fn = elt(env, 2); // mk!*sq
        return (*qfn1(fn))(fn, v_27774);
    }
}



// Code for !:log2

static LispObject CC_Tlog2(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27803, v_27804;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27761;
// end of prologue
    goto v_27771;
v_27767:
    v_27804 = elt(env, 0); // !:log2
    goto v_27768;
v_27769:
    v_27803 = stack[0];
    goto v_27770;
v_27771:
    goto v_27767;
v_27768:
    goto v_27769;
v_27770:
    fn = elt(env, 3); // get!:const
    v_27803 = (*qfn2(fn))(fn, v_27804, v_27803);
    env = stack[-2];
    stack[-1] = v_27803;
    goto v_27782;
v_27778:
    v_27804 = stack[-1];
    goto v_27779;
v_27780:
    v_27803 = elt(env, 1); // not_found
    goto v_27781;
v_27782:
    goto v_27778;
v_27779:
    goto v_27780;
v_27781:
    if (v_27804 == v_27803) goto v_27777;
    v_27803 = stack[-1];
    goto v_27765;
v_27777:
    goto v_27791;
v_27787:
    v_27804 = qvalue(elt(env, 2)); // bftwo!*
    goto v_27788;
v_27789:
    v_27803 = stack[0];
    goto v_27790;
v_27791:
    goto v_27787;
v_27788:
    goto v_27789;
v_27790:
    fn = elt(env, 4); // log!:
    v_27803 = (*qfn2(fn))(fn, v_27804, v_27803);
    env = stack[-2];
    stack[-1] = v_27803;
    goto v_27799;
v_27795:
    v_27804 = elt(env, 0); // !:log2
    goto v_27796;
v_27797:
    v_27803 = stack[-1];
    goto v_27798;
v_27799:
    goto v_27795;
v_27796:
    goto v_27797;
v_27798:
    fn = elt(env, 5); // save!:const
    v_27803 = (*qfn2(fn))(fn, v_27804, v_27803);
    v_27803 = stack[-1];
v_27765:
    return onevalue(v_27803);
}



// Code for exptbf

static LispObject CC_exptbf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27810, v_27811;
    LispObject fn;
    LispObject v_27763, v_27762, v_27761;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "exptbf");
    va_start(aa, nargs);
    v_27761 = va_arg(aa, LispObject);
    v_27762 = va_arg(aa, LispObject);
    v_27763 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_27763,v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_27761,v_27762,v_27763);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_27763;
    stack[-1] = v_27762;
    stack[-2] = v_27761;
// end of prologue
v_27767:
    v_27810 = stack[-1];
    v_27810 = Levenp(nil, v_27810);
    env = stack[-3];
    if (v_27810 == nil) goto v_27770;
    else goto v_27771;
v_27770:
    goto v_27779;
v_27775:
    v_27811 = stack[0];
    goto v_27776;
v_27777:
    v_27810 = stack[-2];
    goto v_27778;
v_27779:
    goto v_27775;
v_27776:
    goto v_27777;
v_27778:
    fn = elt(env, 1); // csl_timbf
    v_27810 = (*qfn2(fn))(fn, v_27811, v_27810);
    env = stack[-3];
    stack[0] = v_27810;
    goto v_27769;
v_27771:
v_27769:
    goto v_27787;
v_27783:
    v_27811 = stack[-1];
    goto v_27784;
v_27785:
    v_27810 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_27786;
v_27787:
    goto v_27783;
v_27784:
    goto v_27785;
v_27786:
    fn = elt(env, 2); // lshift
    v_27810 = (*qfn2(fn))(fn, v_27811, v_27810);
    env = stack[-3];
    stack[-1] = v_27810;
    goto v_27798;
v_27794:
    v_27811 = stack[-1];
    goto v_27795;
v_27796:
    v_27810 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_27797;
v_27798:
    goto v_27794;
v_27795:
    goto v_27796;
v_27797:
    if (v_27811 == v_27810) goto v_27792;
    else goto v_27793;
v_27792:
    v_27810 = stack[0];
    goto v_27766;
v_27793:
    goto v_27807;
v_27803:
    v_27811 = stack[-2];
    goto v_27804;
v_27805:
    v_27810 = stack[-2];
    goto v_27806;
v_27807:
    goto v_27803;
v_27804:
    goto v_27805;
v_27806:
    fn = elt(env, 1); // csl_timbf
    v_27810 = (*qfn2(fn))(fn, v_27811, v_27810);
    env = stack[-3];
    stack[-2] = v_27810;
    goto v_27767;
v_27766:
    return onevalue(v_27810);
}



// Code for find_triangl_coeff

static LispObject CC_find_triangl_coeff(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_27779, v_27780, v_27781, v_27782;
    LispObject fn;
    LispObject v_27763, v_27762, v_27761;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "find_triangl_coeff");
    va_start(aa, nargs);
    v_27761 = va_arg(aa, LispObject);
    v_27762 = va_arg(aa, LispObject);
    v_27763 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27779 = v_27763;
    v_27780 = v_27762;
    v_27781 = v_27761;
// end of prologue
    goto v_27774;
v_27766:
    v_27782 = v_27781;
    goto v_27767;
v_27768:
    v_27781 = nil;
    goto v_27769;
v_27770:
    goto v_27771;
v_27772:
    goto v_27773;
v_27774:
    goto v_27766;
v_27767:
    goto v_27768;
v_27769:
    goto v_27770;
v_27771:
    goto v_27772;
v_27773:
    {
        fn = elt(env, 1); // find_triangle_coeff
        return (*qfnn(fn))(fn, 4, v_27782, v_27781, v_27780, v_27779);
    }
}



// Code for mo_support

static LispObject CC_mo_support(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27806, v_27807;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_27761;
// end of prologue
    stack[-3] = nil;
    v_27806 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 2); // ring_names
    v_27806 = (*qfn1(fn))(fn, v_27806);
    env = stack[-4];
    stack[-1] = v_27806;
v_27769:
    v_27806 = stack[-1];
    if (v_27806 == nil) goto v_27774;
    else goto v_27775;
v_27774:
    goto v_27768;
v_27775:
    v_27806 = stack[-1];
    v_27806 = qcar(v_27806);
    stack[0] = v_27806;
    goto v_27790;
v_27786:
    v_27806 = stack[0];
    fn = elt(env, 3); // mo_from_a
    v_27807 = (*qfn1(fn))(fn, v_27806);
    env = stack[-4];
    goto v_27787;
v_27788:
    v_27806 = stack[-2];
    goto v_27789;
v_27790:
    goto v_27786;
v_27787:
    goto v_27788;
v_27789:
    fn = elt(env, 4); // mo_divides!?
    v_27806 = (*qfn2(fn))(fn, v_27807, v_27806);
    env = stack[-4];
    if (v_27806 == nil) goto v_27784;
    goto v_27799;
v_27795:
    v_27807 = stack[0];
    goto v_27796;
v_27797:
    v_27806 = stack[-3];
    goto v_27798;
v_27799:
    goto v_27795;
v_27796:
    goto v_27797;
v_27798:
    v_27806 = cons(v_27807, v_27806);
    env = stack[-4];
    stack[-3] = v_27806;
    goto v_27782;
v_27784:
v_27782:
    v_27806 = stack[-1];
    v_27806 = qcdr(v_27806);
    stack[-1] = v_27806;
    goto v_27769;
v_27768:
    v_27806 = stack[-3];
        return Lnreverse(nil, v_27806);
    return onevalue(v_27806);
}



// Code for dv_skel2factor

static LispObject CC_dv_skel2factor(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27848, v_27849;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_27849 = v_27762;
    stack[-4] = v_27761;
// end of prologue
    v_27848 = stack[-4];
    v_27848 = qcdr(v_27848);
    if (v_27848 == nil) goto v_27770;
    else goto v_27771;
v_27770:
    v_27848 = stack[-4];
    v_27848 = qcar(v_27848);
    goto v_27767;
v_27771:
    goto v_27781;
v_27777:
    goto v_27778;
v_27779:
    v_27848 = stack[-4];
    v_27848 = qcdr(v_27848);
    goto v_27780;
v_27781:
    goto v_27777;
v_27778:
    goto v_27779;
v_27780:
    v_27848 = Lsublis(nil, v_27849, v_27848);
    env = stack[-6];
    stack[-5] = v_27848;
    v_27848 = stack[-5];
    fn = elt(env, 1); // st_ad_numsorttree
    v_27848 = (*qfn1(fn))(fn, v_27848);
    env = stack[-6];
    stack[-5] = v_27848;
    v_27848 = stack[-5];
    v_27848 = qcdr(v_27848);
    fn = elt(env, 2); // st_flatten
    v_27848 = (*qfn1(fn))(fn, v_27848);
    env = stack[-6];
    stack[-3] = v_27848;
    v_27848 = stack[-3];
    if (v_27848 == nil) goto v_27798;
    else goto v_27799;
v_27798:
    v_27848 = nil;
    goto v_27791;
v_27799:
    v_27848 = stack[-3];
    v_27848 = qcar(v_27848);
    fn = elt(env, 3); // dv_ind2var
    v_27848 = (*qfn1(fn))(fn, v_27848);
    env = stack[-6];
    v_27848 = ncons(v_27848);
    env = stack[-6];
    stack[-1] = v_27848;
    stack[-2] = v_27848;
v_27792:
    v_27848 = stack[-3];
    v_27848 = qcdr(v_27848);
    stack[-3] = v_27848;
    v_27848 = stack[-3];
    if (v_27848 == nil) goto v_27812;
    else goto v_27813;
v_27812:
    v_27848 = stack[-2];
    goto v_27791;
v_27813:
    goto v_27821;
v_27817:
    stack[0] = stack[-1];
    goto v_27818;
v_27819:
    v_27848 = stack[-3];
    v_27848 = qcar(v_27848);
    fn = elt(env, 3); // dv_ind2var
    v_27848 = (*qfn1(fn))(fn, v_27848);
    env = stack[-6];
    v_27848 = ncons(v_27848);
    env = stack[-6];
    goto v_27820;
v_27821:
    goto v_27817;
v_27818:
    goto v_27819;
v_27820:
    v_27848 = Lrplacd(nil, stack[0], v_27848);
    env = stack[-6];
    v_27848 = stack[-1];
    v_27848 = qcdr(v_27848);
    stack[-1] = v_27848;
    goto v_27792;
v_27791:
    goto v_27836;
v_27832:
    v_27849 = stack[-5];
    stack[0] = qcar(v_27849);
    goto v_27833;
v_27834:
    goto v_27844;
v_27840:
    v_27849 = stack[-4];
    v_27849 = qcar(v_27849);
    goto v_27841;
v_27842:
    goto v_27843;
v_27844:
    goto v_27840;
v_27841:
    goto v_27842;
v_27843:
    fn = elt(env, 4); // dv_skel2factor1
    v_27848 = (*qfn2(fn))(fn, v_27849, v_27848);
    goto v_27835;
v_27836:
    goto v_27832;
v_27833:
    goto v_27834;
v_27835:
    {
        LispObject v_27856 = stack[0];
        return cons(v_27856, v_27848);
    }
v_27767:
    return onevalue(v_27848);
}



// Code for simpsqrt2

static LispObject CC_simpsqrt2(LispObject env,
                         LispObject v_27761)
{
    env = qenv(env);
    LispObject v_27809, v_27810;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_27761);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_27761;
// end of prologue
    v_27809 = stack[0];
    fn = elt(env, 2); // minusf
    v_27809 = (*qfn1(fn))(fn, v_27809);
    env = stack[-1];
    if (v_27809 == nil) goto v_27766;
    goto v_27778;
v_27774:
    v_27810 = stack[0];
    goto v_27775;
v_27776:
    v_27809 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_27777;
v_27778:
    goto v_27774;
v_27775:
    goto v_27776;
v_27777:
    fn = elt(env, 3); // iequal
    v_27809 = (*qfn2(fn))(fn, v_27810, v_27809);
    env = stack[-1];
    if (v_27809 == nil) goto v_27772;
    v_27809 = qvalue(elt(env, 1)); // gaussiani
    goto v_27770;
v_27772:
    v_27809 = stack[0];
    fn = elt(env, 4); // negf
    v_27809 = (*qfn1(fn))(fn, v_27809);
    env = stack[-1];
    v_27810 = v_27809;
    v_27809 = v_27810;
    if (is_number(v_27809)) goto v_27791;
    else goto v_27792;
v_27791:
    goto v_27799;
v_27795:
    stack[0] = qvalue(elt(env, 1)); // gaussiani
    goto v_27796;
v_27797:
    v_27809 = v_27810;
    fn = elt(env, 5); // simpsqrt3
    v_27809 = (*qfn1(fn))(fn, v_27809);
    env = stack[-1];
    goto v_27798;
v_27799:
    goto v_27795;
v_27796:
    goto v_27797;
v_27798:
    {
        LispObject v_27812 = stack[0];
        fn = elt(env, 6); // multf
        return (*qfn2(fn))(fn, v_27812, v_27809);
    }
v_27792:
    v_27809 = stack[0];
    {
        fn = elt(env, 5); // simpsqrt3
        return (*qfn1(fn))(fn, v_27809);
    }
    goto v_27770;
    v_27809 = nil;
v_27770:
    goto v_27764;
v_27766:
    v_27809 = stack[0];
    {
        fn = elt(env, 5); // simpsqrt3
        return (*qfn1(fn))(fn, v_27809);
    }
    v_27809 = nil;
v_27764:
    return onevalue(v_27809);
}



// Code for add!-factor

static LispObject CC_addKfactor(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27828, v_27829, v_27830;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27762;
    stack[-1] = v_27761;
// end of prologue
    v_27828 = stack[0];
    v_27828 = Lconsp(nil, v_27828);
    env = stack[-2];
    if (v_27828 == nil) goto v_27767;
    goto v_27779;
v_27775:
    v_27829 = stack[-1];
    goto v_27776;
v_27777:
    v_27828 = stack[0];
    v_27828 = qcar(v_27828);
    v_27828 = qcar(v_27828);
    goto v_27778;
v_27779:
    goto v_27775;
v_27776:
    goto v_27777;
v_27778:
    v_27828 = (LispObject)greaterp2(v_27829, v_27828);
    v_27828 = v_27828 ? lisp_true : nil;
    env = stack[-2];
    if (v_27828 == nil) goto v_27773;
    v_27828 = nil;
    goto v_27771;
v_27773:
    goto v_27791;
v_27787:
    v_27829 = stack[-1];
    goto v_27788;
v_27789:
    v_27828 = stack[0];
    goto v_27790;
v_27791:
    goto v_27787;
v_27788:
    goto v_27789;
v_27790:
    v_27828 = Lassoc(nil, v_27829, v_27828);
    goto v_27771;
    v_27828 = nil;
v_27771:
    goto v_27765;
v_27767:
    v_27828 = nil;
    goto v_27765;
    v_27828 = nil;
v_27765:
    v_27829 = v_27828;
    v_27828 = v_27829;
    if (v_27828 == nil) goto v_27802;
    goto v_27809;
v_27805:
    stack[-1] = v_27829;
    goto v_27806;
v_27807:
    v_27828 = v_27829;
    v_27828 = qcdr(v_27828);
    v_27828 = add1(v_27828);
    env = stack[-2];
    goto v_27808;
v_27809:
    goto v_27805;
v_27806:
    goto v_27807;
v_27808:
    v_27828 = Lrplacd(nil, stack[-1], v_27828);
    v_27828 = stack[0];
    goto v_27800;
v_27802:
    goto v_27824;
v_27818:
    v_27830 = stack[-1];
    goto v_27819;
v_27820:
    v_27829 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27821;
v_27822:
    v_27828 = stack[0];
    goto v_27823;
v_27824:
    goto v_27818;
v_27819:
    goto v_27820;
v_27821:
    goto v_27822;
v_27823:
    return acons(v_27830, v_27829, v_27828);
    v_27828 = nil;
v_27800:
    return onevalue(v_27828);
}



// Code for df_min

static LispObject CC_df_min(LispObject env,
                         LispObject v_27761, LispObject v_27762)
{
    env = qenv(env);
    LispObject v_27820, v_27821;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_27762,v_27761);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_27761,v_27762);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_27762;
    stack[-1] = v_27761;
// end of prologue
    v_27820 = stack[-1];
    v_27820 = Lconsp(nil, v_27820);
    env = stack[-2];
    if (v_27820 == nil) goto v_27766;
    else goto v_27767;
v_27766:
    v_27820 = stack[-1];
    v_27820 = ncons(v_27820);
    env = stack[-2];
    stack[-1] = v_27820;
    goto v_27765;
v_27767:
v_27765:
    v_27820 = stack[0];
    v_27820 = Lconsp(nil, v_27820);
    env = stack[-2];
    if (v_27820 == nil) goto v_27774;
    else goto v_27775;
v_27774:
    v_27820 = stack[0];
    v_27820 = ncons(v_27820);
    env = stack[-2];
    stack[0] = v_27820;
    goto v_27773;
v_27775:
v_27773:
    goto v_27788;
v_27784:
    v_27820 = stack[-1];
    v_27821 = qcar(v_27820);
    goto v_27785;
v_27786:
    v_27820 = stack[0];
    v_27820 = qcar(v_27820);
    goto v_27787;
v_27788:
    goto v_27784;
v_27785:
    goto v_27786;
v_27787:
    if (equal(v_27821, v_27820)) goto v_27782;
    else goto v_27783;
v_27782:
    goto v_27802;
v_27798:
    v_27820 = stack[-1];
    v_27821 = qcdr(v_27820);
    goto v_27799;
v_27800:
    v_27820 = stack[0];
    v_27820 = qcdr(v_27820);
    goto v_27801;
v_27802:
    goto v_27798;
v_27799:
    goto v_27800;
v_27801:
    fn = elt(env, 1); // df_min1
    v_27820 = (*qfn2(fn))(fn, v_27821, v_27820);
    stack[-1] = v_27820;
    if (v_27820 == nil) goto v_27796;
    goto v_27812;
v_27808:
    v_27820 = stack[0];
    v_27821 = qcar(v_27820);
    goto v_27809;
v_27810:
    v_27820 = stack[-1];
    goto v_27811;
v_27812:
    goto v_27808;
v_27809:
    goto v_27810;
v_27811:
    return cons(v_27821, v_27820);
v_27796:
    v_27820 = stack[0];
    v_27820 = qcar(v_27820);
    goto v_27794;
    v_27820 = nil;
v_27794:
    goto v_27781;
v_27783:
    v_27820 = nil;
v_27781:
    return onevalue(v_27820);
}



setup_type const u47_setup[] =
{
    {"groebcplistmerge",        TOO_FEW_2,      CC_groebcplistmerge,WRONG_NO_2},
    {"gfquotient",              TOO_FEW_2,      CC_gfquotient, WRONG_NO_2},
    {"mkdmoderr",               TOO_FEW_2,      CC_mkdmoderr,  WRONG_NO_2},
    {"indordln",                CC_indordln,    TOO_MANY_1,    WRONG_NO_1},
    {"listquotient",            TOO_FEW_2,      CC_listquotient,WRONG_NO_2},
    {"fs:prin:",                CC_fsTprinT,    TOO_MANY_1,    WRONG_NO_1},
    {"groeb=testb",             TOO_FEW_2,      CC_groebMtestb,WRONG_NO_2},
    {"verify_tens_ids",         CC_verify_tens_ids,TOO_MANY_1, WRONG_NO_1},
    {"nonlnr",                  TOO_FEW_2,      CC_nonlnr,     WRONG_NO_2},
    {"bfminus",                 CC_bfminus,     TOO_MANY_1,    WRONG_NO_1},
    {"no_of_tm_sf_limited",     TOO_FEW_2,      CC_no_of_tm_sf_limited,WRONG_NO_2},
    {"dfdeg",                   TOO_FEW_2,      CC_dfdeg,      WRONG_NO_2},
    {"makecoeffpairs",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_makecoeffpairs},
    {"cl_sordp",                TOO_FEW_2,      CC_cl_sordp,   WRONG_NO_2},
    {"matsm*",                  TOO_FEW_2,      CC_matsmH,     WRONG_NO_2},
    {"vdplsort",                CC_vdplsort,    TOO_MANY_1,    WRONG_NO_1},
    {"reset_opnums",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_reset_opnums},
    {"free",                    CC_free,        TOO_MANY_1,    WRONG_NO_1},
    {"expand-imrepartpow",      CC_expandKimrepartpow,TOO_MANY_1,WRONG_NO_1},
    {"generic_arguments",       CC_generic_arguments,TOO_MANY_1,WRONG_NO_1},
    {"njets",                   TOO_FEW_2,      CC_njets,      WRONG_NO_2},
    {"domainp_list",            CC_domainp_list,TOO_MANY_1,    WRONG_NO_1},
    {"random-small-prime",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_randomKsmallKprime},
    {"janettreeinsert",         CC_janettreeinsert,TOO_MANY_1, WRONG_NO_1},
    {"mri_simplat1",            TOO_FEW_2,      CC_mri_simplat1,WRONG_NO_2},
    {"ofsf_updsignpow",         TOO_FEW_2,      CC_ofsf_updsignpow,WRONG_NO_2},
    {"cr:prep",                 CC_crTprep,     TOO_MANY_1,    WRONG_NO_1},
    {"spinnerprod",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_spinnerprod},
    {"safe-fp-quot",            TOO_FEW_2,      CC_safeKfpKquot,WRONG_NO_2},
    {"f2dip",                   CC_f2dip,       TOO_MANY_1,    WRONG_NO_1},
    {"delete_edge",             TOO_FEW_2,      CC_delete_edge,WRONG_NO_2},
    {"reduce-ratios",           TOO_FEW_2,      CC_reduceKratios,WRONG_NO_2},
    {"fs:subang",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_fsTsubang},
    {"addnew",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_addnew},
    {"flattens1",               CC_flattens1,   TOO_MANY_1,    WRONG_NO_1},
    {"pst_mkpst",               CC_pst_mkpst,   TOO_MANY_1,    WRONG_NO_1},
    {"taylorp",                 CC_taylorp,     TOO_MANY_1,    WRONG_NO_1},
    {"get-new-prime",           CC_getKnewKprime,TOO_MANY_1,   WRONG_NO_1},
    {"min2-order",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_min2Korder},
    {"bc_dcont",                CC_bc_dcont,    TOO_MANY_1,    WRONG_NO_1},
    {"evalgeq",                 TOO_FEW_2,      CC_evalgeq,    WRONG_NO_2},
    {"exp*",                    CC_expH,        TOO_MANY_1,    WRONG_NO_1},
    {"mk_names_map_2",          CC_mk_names_map_2,TOO_MANY_1,  WRONG_NO_1},
    {"general-modular-difference",TOO_FEW_2,    CC_generalKmodularKdifference,WRONG_NO_2},
    {"ofsf_smmkatl-and1",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smmkatlKand1},
    {"sfchk",                   CC_sfchk,       TOO_MANY_1,    WRONG_NO_1},
    {"depend-sq",               TOO_FEW_2,      CC_dependKsq,  WRONG_NO_2},
    {"talp_mkinvop",            TOO_FEW_2,      CC_talp_mkinvop,WRONG_NO_2},
    {"mri_simplfloor1",         CC_mri_simplfloor1,TOO_MANY_1, WRONG_NO_1},
    {"countof",                 TOO_FEW_2,      CC_countof,    WRONG_NO_2},
    {"den",                     CC_den,         TOO_MANY_1,    WRONG_NO_1},
    {":log2",                   CC_Tlog2,       TOO_MANY_1,    WRONG_NO_1},
    {"exptbf",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_exptbf},
    {"find_triangl_coeff",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_find_triangl_coeff},
    {"mo_support",              CC_mo_support,  TOO_MANY_1,    WRONG_NO_1},
    {"dv_skel2factor",          TOO_FEW_2,      CC_dv_skel2factor,WRONG_NO_2},
    {"simpsqrt2",               CC_simpsqrt2,   TOO_MANY_1,    WRONG_NO_1},
    {"add-factor",              TOO_FEW_2,      CC_addKfactor, WRONG_NO_2},
    {"df_min",                  TOO_FEW_2,      CC_df_min,     WRONG_NO_2},
    {NULL, (one_args *)"u47", (two_args *)"171954 5640768 2373313", 0}
};

// end of generated code
