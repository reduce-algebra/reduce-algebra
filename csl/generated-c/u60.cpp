
// $destdir/u60.c        Machine generated C code

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



// Code for preproc1

static LispObject CC_preproc1(LispObject env,
                         LispObject v_35810)
{
    env = qenv(env);
    LispObject v_36605, v_36606, v_36607;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35810);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_35810;
// end of prologue
v_35814:
    v_36605 = stack[-1];
    if (!consp(v_36605)) goto v_35817;
    else goto v_35818;
v_35817:
    v_36605 = stack[-1];
    return ncons(v_36605);
v_35818:
    goto v_35828;
v_35824:
    v_36605 = stack[-1];
    v_36606 = qcar(v_36605);
    goto v_35825;
v_35826:
    v_36605 = elt(env, 1); // !:rd!:
    goto v_35827;
v_35828:
    goto v_35824;
v_35825:
    goto v_35826;
v_35827:
    if (v_36606 == v_36605) goto v_35822;
    else goto v_35823;
v_35822:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    if (!consp(v_36605)) goto v_35835;
    else goto v_35836;
v_35835:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    v_36605 = Lfloatp(nil, v_36605);
    env = stack[-5];
    if (v_36605 == nil) goto v_35842;
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    fn = elt(env, 20); // fl2bf
    v_36605 = (*qfn1(fn))(fn, v_36605);
    goto v_35840;
v_35842:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    if (!consp(v_36605)) goto v_35855;
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    goto v_35853;
v_35855:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    v_36605 = integerp(v_36605);
    if (v_36605 == nil) goto v_35861;
    goto v_35872;
v_35866:
    v_36607 = elt(env, 1); // !:rd!:
    goto v_35867;
v_35868:
    v_36605 = stack[-1];
    v_36606 = qcdr(v_36605);
    goto v_35869;
v_35870:
    v_36605 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35871;
v_35872:
    goto v_35866;
v_35867:
    goto v_35868;
v_35869:
    goto v_35870;
v_35871:
    v_36605 = list2star(v_36607, v_36606, v_36605);
    env = stack[-5];
    goto v_35853;
v_35861:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    fn = elt(env, 21); // read!:num
    v_36605 = (*qfn1(fn))(fn, v_36605);
    env = stack[-5];
    goto v_35853;
    v_36605 = nil;
v_35853:
    fn = elt(env, 22); // normbf
    v_36605 = (*qfn1(fn))(fn, v_36605);
    goto v_35840;
    v_36605 = nil;
v_35840:
    goto v_35834;
v_35836:
    v_36605 = stack[-1];
    goto v_35834;
    v_36605 = nil;
v_35834:
    return ncons(v_36605);
v_35823:
    goto v_35891;
v_35887:
    v_36605 = stack[-1];
    v_36606 = qcar(v_36605);
    goto v_35888;
v_35889:
    v_36605 = elt(env, 2); // !:dn!:
    goto v_35890;
v_35891:
    goto v_35887;
v_35888:
    goto v_35889;
v_35890:
    if (v_36606 == v_36605) goto v_35885;
    else goto v_35886;
v_35885:
    goto v_35900;
v_35896:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    v_36606 = qcar(v_36605);
    goto v_35897;
v_35898:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    v_36605 = qcdr(v_36605);
    goto v_35899;
v_35900:
    goto v_35896;
v_35897:
    goto v_35898;
v_35899:
    fn = elt(env, 23); // decimal2internal
    v_36605 = (*qfn2(fn))(fn, v_36606, v_36605);
    env = stack[-5];
    stack[-1] = v_36605;
    goto v_35814;
v_35886:
    goto v_35913;
v_35909:
    v_36605 = stack[-1];
    v_36606 = qcar(v_36605);
    goto v_35910;
v_35911:
    v_36605 = elt(env, 3); // !*sq
    goto v_35912;
v_35913:
    goto v_35909;
v_35910:
    goto v_35911;
v_35912:
    if (v_36606 == v_36605) goto v_35907;
    else goto v_35908;
v_35907:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    v_36605 = qcar(v_36605);
    fn = elt(env, 24); // prepsq
    v_36605 = (*qfn1(fn))(fn, v_36605);
    env = stack[-5];
    stack[-1] = v_36605;
    goto v_35814;
v_35908:
    goto v_35927;
v_35923:
    v_36605 = stack[-1];
    v_36606 = qcar(v_36605);
    goto v_35924;
v_35925:
    v_36605 = elt(env, 4); // procedure
    goto v_35926;
v_35927:
    goto v_35923;
v_35924:
    goto v_35925;
v_35926:
    if (v_36606 == v_36605) goto v_35921;
    else goto v_35922;
v_35921:
    goto v_35938;
v_35932:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    v_36607 = qcar(v_36605);
    goto v_35933;
v_35934:
    v_36606 = elt(env, 5); // !*params!*
    goto v_35935;
v_35936:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    v_36605 = qcdr(v_36605);
    v_36605 = qcdr(v_36605);
    v_36605 = qcdr(v_36605);
    v_36605 = qcar(v_36605);
    goto v_35937;
v_35938:
    goto v_35932;
v_35933:
    goto v_35934;
v_35935:
    goto v_35936;
v_35937:
    fn = elt(env, 25); // symtabput
    v_36605 = (*qfnn(fn))(fn, 3, v_36607, v_36606, v_36605);
    env = stack[-5];
    v_36605 = qvalue(elt(env, 6)); // !*getdecs
    if (v_36605 == nil) goto v_35952;
    goto v_35962;
v_35958:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    v_36605 = qcdr(v_36605);
    v_36606 = qcar(v_36605);
    goto v_35959;
v_35960:
    v_36605 = elt(env, 7); // (real integer)
    goto v_35961;
v_35962:
    goto v_35958;
v_35959:
    goto v_35960;
v_35961:
    v_36605 = Lmemq(nil, v_36606, v_36605);
    if (v_36605 == nil) goto v_35957;
    goto v_35976;
v_35970:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    stack[-2] = qcar(v_36605);
    goto v_35971;
v_35972:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    stack[0] = qcar(v_36605);
    goto v_35973;
v_35974:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    v_36605 = qcdr(v_36605);
    v_36605 = qcar(v_36605);
    v_36605 = ncons(v_36605);
    env = stack[-5];
    goto v_35975;
v_35976:
    goto v_35970;
v_35971:
    goto v_35972;
v_35973:
    goto v_35974;
v_35975:
    fn = elt(env, 25); // symtabput
    v_36605 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_36605);
    env = stack[-5];
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    v_36605 = qcdr(v_36605);
    v_36605 = qcdr(v_36605);
    v_36605 = qcdr(v_36605);
    v_36605 = qcar(v_36605);
    stack[-3] = v_36605;
v_35991:
    v_36605 = stack[-3];
    if (v_36605 == nil) goto v_36000;
    else goto v_36001;
v_36000:
    goto v_35990;
v_36001:
    v_36605 = stack[-3];
    v_36605 = qcar(v_36605);
    v_36606 = v_36605;
    goto v_36014;
v_36008:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    stack[-2] = qcar(v_36605);
    goto v_36009;
v_36010:
    stack[0] = v_36606;
    goto v_36011;
v_36012:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    v_36605 = qcdr(v_36605);
    v_36605 = qcar(v_36605);
    v_36605 = ncons(v_36605);
    env = stack[-5];
    goto v_36013;
v_36014:
    goto v_36008;
v_36009:
    goto v_36010;
v_36011:
    goto v_36012;
v_36013:
    fn = elt(env, 25); // symtabput
    v_36605 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_36605);
    env = stack[-5];
    v_36605 = stack[-3];
    v_36605 = qcdr(v_36605);
    stack[-3] = v_36605;
    goto v_35991;
v_35990:
    goto v_36032;
v_36028:
    goto v_36040;
v_36034:
    v_36607 = elt(env, 4); // procedure
    goto v_36035;
v_36036:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    v_36606 = qcar(v_36605);
    goto v_36037;
v_36038:
    v_36605 = nil;
    goto v_36039;
v_36040:
    goto v_36034;
v_36035:
    goto v_36036;
v_36037:
    goto v_36038;
v_36039:
    stack[-4] = list3(v_36607, v_36606, v_36605);
    env = stack[-5];
    goto v_36029;
v_36030:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    v_36605 = qcdr(v_36605);
    v_36605 = qcdr(v_36605);
    stack[-3] = v_36605;
v_36051:
    v_36605 = stack[-3];
    if (v_36605 == nil) goto v_36059;
    else goto v_36060;
v_36059:
    v_36605 = nil;
    goto v_36050;
v_36060:
    v_36605 = stack[-3];
    v_36605 = qcar(v_36605);
    v_36605 = CC_preproc1(elt(env, 0), v_36605);
    env = stack[-5];
    stack[-2] = v_36605;
    v_36605 = stack[-2];
    fn = elt(env, 26); // lastpair
    v_36605 = (*qfn1(fn))(fn, v_36605);
    env = stack[-5];
    stack[-1] = v_36605;
    v_36605 = stack[-3];
    v_36605 = qcdr(v_36605);
    stack[-3] = v_36605;
    v_36605 = stack[-1];
    if (!consp(v_36605)) goto v_36074;
    else goto v_36075;
v_36074:
    goto v_36051;
v_36075:
v_36052:
    v_36605 = stack[-3];
    if (v_36605 == nil) goto v_36079;
    else goto v_36080;
v_36079:
    v_36605 = stack[-2];
    goto v_36050;
v_36080:
    goto v_36088;
v_36084:
    stack[0] = stack[-1];
    goto v_36085;
v_36086:
    v_36605 = stack[-3];
    v_36605 = qcar(v_36605);
    v_36605 = CC_preproc1(elt(env, 0), v_36605);
    env = stack[-5];
    goto v_36087;
v_36088:
    goto v_36084;
v_36085:
    goto v_36086;
v_36087:
    v_36605 = Lrplacd(nil, stack[0], v_36605);
    env = stack[-5];
    v_36605 = stack[-1];
    fn = elt(env, 26); // lastpair
    v_36605 = (*qfn1(fn))(fn, v_36605);
    env = stack[-5];
    stack[-1] = v_36605;
    v_36605 = stack[-3];
    v_36605 = qcdr(v_36605);
    stack[-3] = v_36605;
    goto v_36052;
v_36050:
    goto v_36031;
v_36032:
    goto v_36028;
v_36029:
    goto v_36030;
v_36031:
    v_36605 = Lnconc(nil, stack[-4], v_36605);
    return ncons(v_36605);
v_35957:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    v_36605 = qcdr(v_36605);
    v_36605 = qcdr(v_36605);
    v_36605 = qcdr(v_36605);
    v_36605 = qcar(v_36605);
    stack[-3] = v_36605;
v_36104:
    v_36605 = stack[-3];
    if (v_36605 == nil) goto v_36113;
    else goto v_36114;
v_36113:
    goto v_36103;
v_36114:
    v_36605 = stack[-3];
    v_36605 = qcar(v_36605);
    v_36606 = v_36605;
    goto v_36127;
v_36121:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    stack[-2] = qcar(v_36605);
    goto v_36122;
v_36123:
    stack[0] = v_36606;
    goto v_36124;
v_36125:
    v_36605 = qvalue(elt(env, 8)); // deftype!*
    v_36605 = ncons(v_36605);
    env = stack[-5];
    goto v_36126;
v_36127:
    goto v_36121;
v_36122:
    goto v_36123;
v_36124:
    goto v_36125;
v_36126:
    fn = elt(env, 25); // symtabput
    v_36605 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_36605);
    env = stack[-5];
    v_36605 = stack[-3];
    v_36605 = qcdr(v_36605);
    stack[-3] = v_36605;
    goto v_36104;
v_36103:
    v_36605 = stack[-1];
    stack[-3] = v_36605;
v_36142:
    v_36605 = stack[-3];
    if (v_36605 == nil) goto v_36147;
    else goto v_36148;
v_36147:
    v_36605 = nil;
    goto v_36141;
v_36148:
    v_36605 = stack[-3];
    v_36605 = qcar(v_36605);
    v_36605 = CC_preproc1(elt(env, 0), v_36605);
    env = stack[-5];
    stack[-2] = v_36605;
    v_36605 = stack[-2];
    fn = elt(env, 26); // lastpair
    v_36605 = (*qfn1(fn))(fn, v_36605);
    env = stack[-5];
    stack[-1] = v_36605;
    v_36605 = stack[-3];
    v_36605 = qcdr(v_36605);
    stack[-3] = v_36605;
    v_36605 = stack[-1];
    if (!consp(v_36605)) goto v_36162;
    else goto v_36163;
v_36162:
    goto v_36142;
v_36163:
v_36143:
    v_36605 = stack[-3];
    if (v_36605 == nil) goto v_36167;
    else goto v_36168;
v_36167:
    v_36605 = stack[-2];
    goto v_36141;
v_36168:
    goto v_36176;
v_36172:
    stack[0] = stack[-1];
    goto v_36173;
v_36174:
    v_36605 = stack[-3];
    v_36605 = qcar(v_36605);
    v_36605 = CC_preproc1(elt(env, 0), v_36605);
    env = stack[-5];
    goto v_36175;
v_36176:
    goto v_36172;
v_36173:
    goto v_36174;
v_36175:
    v_36605 = Lrplacd(nil, stack[0], v_36605);
    env = stack[-5];
    v_36605 = stack[-1];
    fn = elt(env, 26); // lastpair
    v_36605 = (*qfn1(fn))(fn, v_36605);
    env = stack[-5];
    stack[-1] = v_36605;
    v_36605 = stack[-3];
    v_36605 = qcdr(v_36605);
    stack[-3] = v_36605;
    goto v_36143;
v_36141:
    return ncons(v_36605);
    goto v_35950;
v_35952:
    v_36605 = stack[-1];
    stack[-3] = v_36605;
v_36195:
    v_36605 = stack[-3];
    if (v_36605 == nil) goto v_36200;
    else goto v_36201;
v_36200:
    v_36605 = nil;
    goto v_36194;
v_36201:
    v_36605 = stack[-3];
    v_36605 = qcar(v_36605);
    v_36605 = CC_preproc1(elt(env, 0), v_36605);
    env = stack[-5];
    stack[-2] = v_36605;
    v_36605 = stack[-2];
    fn = elt(env, 26); // lastpair
    v_36605 = (*qfn1(fn))(fn, v_36605);
    env = stack[-5];
    stack[-1] = v_36605;
    v_36605 = stack[-3];
    v_36605 = qcdr(v_36605);
    stack[-3] = v_36605;
    v_36605 = stack[-1];
    if (!consp(v_36605)) goto v_36215;
    else goto v_36216;
v_36215:
    goto v_36195;
v_36216:
v_36196:
    v_36605 = stack[-3];
    if (v_36605 == nil) goto v_36220;
    else goto v_36221;
v_36220:
    v_36605 = stack[-2];
    goto v_36194;
v_36221:
    goto v_36229;
v_36225:
    stack[0] = stack[-1];
    goto v_36226;
v_36227:
    v_36605 = stack[-3];
    v_36605 = qcar(v_36605);
    v_36605 = CC_preproc1(elt(env, 0), v_36605);
    env = stack[-5];
    goto v_36228;
v_36229:
    goto v_36225;
v_36226:
    goto v_36227;
v_36228:
    v_36605 = Lrplacd(nil, stack[0], v_36605);
    env = stack[-5];
    v_36605 = stack[-1];
    fn = elt(env, 26); // lastpair
    v_36605 = (*qfn1(fn))(fn, v_36605);
    env = stack[-5];
    stack[-1] = v_36605;
    v_36605 = stack[-3];
    v_36605 = qcdr(v_36605);
    stack[-3] = v_36605;
    goto v_36196;
v_36194:
    return ncons(v_36605);
v_35950:
    goto v_35816;
v_35922:
    goto v_36246;
v_36242:
    v_36605 = stack[-1];
    v_36606 = qcar(v_36605);
    goto v_36243;
v_36244:
    v_36605 = elt(env, 9); // declare
    goto v_36245;
v_36246:
    goto v_36242;
v_36243:
    goto v_36244;
v_36245:
    if (v_36606 == v_36605) goto v_36240;
    else goto v_36241;
v_36240:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    v_36605 = CC_preproc1(elt(env, 0), v_36605);
    env = stack[-5];
    v_36605 = qcar(v_36605);
    stack[-1] = v_36605;
    v_36605 = stack[-1];
    fn = elt(env, 27); // preprocdec
    v_36605 = (*qfn1(fn))(fn, v_36605);
    env = stack[-5];
    stack[-1] = v_36605;
    v_36605 = stack[-1];
    stack[-4] = v_36605;
v_36259:
    v_36605 = stack[-4];
    if (v_36605 == nil) goto v_36263;
    else goto v_36264;
v_36263:
    goto v_36258;
v_36264:
    v_36605 = stack[-4];
    v_36605 = qcar(v_36605);
    stack[-3] = v_36605;
    v_36605 = stack[-3];
    v_36605 = qcdr(v_36605);
    stack[-2] = v_36605;
v_36273:
    v_36605 = stack[-2];
    if (v_36605 == nil) goto v_36278;
    else goto v_36279;
v_36278:
    goto v_36272;
v_36279:
    v_36605 = stack[-2];
    v_36605 = qcar(v_36605);
    v_36607 = v_36605;
    goto v_36293;
v_36289:
    v_36605 = stack[-3];
    v_36606 = qcar(v_36605);
    goto v_36290;
v_36291:
    v_36605 = elt(env, 10); // (subroutine function)
    goto v_36292;
v_36293:
    goto v_36289;
v_36290:
    goto v_36291;
v_36292:
    v_36605 = Lmemq(nil, v_36606, v_36605);
    if (v_36605 == nil) goto v_36288;
    goto v_36305;
v_36299:
    goto v_36300;
v_36301:
    v_36606 = elt(env, 11); // !*type!*
    goto v_36302;
v_36303:
    v_36605 = stack[-3];
    v_36605 = qcar(v_36605);
    goto v_36304;
v_36305:
    goto v_36299;
v_36300:
    goto v_36301;
v_36302:
    goto v_36303;
v_36304:
    fn = elt(env, 25); // symtabput
    v_36605 = (*qfnn(fn))(fn, 3, v_36607, v_36606, v_36605);
    env = stack[-5];
    goto v_36286;
v_36288:
    goto v_36319;
v_36313:
    stack[-1] = nil;
    goto v_36314;
v_36315:
    v_36605 = v_36607;
    if (!consp(v_36605)) goto v_36323;
    else goto v_36324;
v_36323:
    v_36605 = v_36607;
    stack[0] = v_36605;
    goto v_36322;
v_36324:
    v_36605 = v_36607;
    v_36605 = qcar(v_36605);
    stack[0] = v_36605;
    goto v_36322;
    stack[0] = nil;
v_36322:
    goto v_36316;
v_36317:
    v_36605 = v_36607;
    if (!consp(v_36605)) goto v_36333;
    else goto v_36334;
v_36333:
    v_36605 = stack[-3];
    v_36605 = qcar(v_36605);
    v_36605 = ncons(v_36605);
    env = stack[-5];
    goto v_36332;
v_36334:
    goto v_36346;
v_36342:
    v_36605 = stack[-3];
    v_36605 = qcar(v_36605);
    goto v_36343;
v_36344:
    v_36606 = v_36607;
    v_36606 = qcdr(v_36606);
    goto v_36345;
v_36346:
    goto v_36342;
v_36343:
    goto v_36344;
v_36345:
    v_36605 = cons(v_36605, v_36606);
    env = stack[-5];
    goto v_36332;
    v_36605 = nil;
v_36332:
    goto v_36318;
v_36319:
    goto v_36313;
v_36314:
    goto v_36315;
v_36316:
    goto v_36317;
v_36318:
    fn = elt(env, 25); // symtabput
    v_36605 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_36605);
    env = stack[-5];
    goto v_36286;
v_36286:
    v_36605 = stack[-2];
    v_36605 = qcdr(v_36605);
    stack[-2] = v_36605;
    goto v_36273;
v_36272:
    v_36605 = stack[-4];
    v_36605 = qcdr(v_36605);
    stack[-4] = v_36605;
    goto v_36259;
v_36258:
    v_36605 = nil;
    goto v_35813;
v_36241:
    goto v_36366;
v_36362:
    v_36605 = stack[-1];
    v_36606 = qcar(v_36605);
    goto v_36363;
v_36364:
    v_36605 = elt(env, 12); // setq
    goto v_36365;
v_36366:
    goto v_36362;
v_36363:
    goto v_36364;
v_36365:
    if (v_36606 == v_36605) goto v_36360;
    else goto v_36361;
v_36360:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    v_36605 = qcdr(v_36605);
    v_36605 = qcar(v_36605);
    v_36605 = Lconsp(nil, v_36605);
    env = stack[-5];
    if (v_36605 == nil) goto v_36372;
    else goto v_36373;
v_36372:
    v_36605 = nil;
    goto v_36371;
v_36373:
    goto v_36386;
v_36382:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    v_36605 = qcdr(v_36605);
    v_36605 = qcar(v_36605);
    v_36606 = qcar(v_36605);
    goto v_36383;
v_36384:
    v_36605 = elt(env, 13); // (cond progn)
    goto v_36385;
v_36386:
    goto v_36382;
v_36383:
    goto v_36384;
v_36385:
    v_36605 = Lmemq(nil, v_36606, v_36605);
    goto v_36371;
    v_36605 = nil;
v_36371:
    goto v_36359;
v_36361:
    v_36605 = nil;
    goto v_36359;
    v_36605 = nil;
v_36359:
    if (v_36605 == nil) goto v_36357;
    v_36605 = stack[-1];
    {
        fn = elt(env, 28); // migrate!-setqs
        return (*qfn1(fn))(fn, v_36605);
    }
v_36357:
    goto v_36405;
v_36401:
    v_36605 = stack[-1];
    v_36606 = qcar(v_36605);
    goto v_36402;
v_36403:
    v_36605 = elt(env, 14); // (plus times difference quotient minus)
    goto v_36404;
v_36405:
    goto v_36401;
v_36402:
    goto v_36403;
v_36404:
    v_36605 = Lmemq(nil, v_36606, v_36605);
    if (v_36605 == nil) goto v_36400;
    v_36605 = stack[-1];
    fn = elt(env, 29); // simp!*
    v_36605 = (*qfn1(fn))(fn, v_36605);
    env = stack[-5];
    v_36607 = v_36605;
    v_36605 = qcar(v_36605);
    v_36605 = Lconsp(nil, v_36605);
    env = stack[-5];
    if (v_36605 == nil) goto v_36417;
    goto v_36428;
v_36424:
    v_36605 = v_36607;
    v_36605 = qcar(v_36605);
    v_36606 = qcar(v_36605);
    goto v_36425;
v_36426:
    v_36605 = elt(env, 16); // (!:cr!: !:crn!: !:gi!:)
    goto v_36427;
v_36428:
    goto v_36424;
v_36425:
    goto v_36426;
v_36427:
    v_36605 = Lmemq(nil, v_36606, v_36605);
    if (v_36605 == nil) goto v_36417;
    v_36605 = v_36607;
    v_36605 = qcdr(v_36605);
    v_36605 = Lonep(nil, v_36605);
    env = stack[-5];
    if (v_36605 == nil) goto v_36437;
    v_36605 = v_36607;
    v_36605 = qcar(v_36605);
    return ncons(v_36605);
v_36437:
    goto v_36454;
v_36448:
    stack[-1] = elt(env, 17); // quotient
    goto v_36449;
v_36450:
    v_36605 = v_36607;
    stack[0] = qcar(v_36605);
    goto v_36451;
v_36452:
    goto v_36465;
v_36461:
    v_36605 = v_36607;
    v_36606 = qcdr(v_36605);
    goto v_36462;
v_36463:
    v_36605 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36464;
v_36465:
    goto v_36461;
v_36462:
    goto v_36463;
v_36464:
    v_36605 = cons(v_36606, v_36605);
    env = stack[-5];
    fn = elt(env, 24); // prepsq
    v_36605 = (*qfn1(fn))(fn, v_36605);
    env = stack[-5];
    v_36605 = CC_preproc1(elt(env, 0), v_36605);
    env = stack[-5];
    v_36605 = qcar(v_36605);
    goto v_36453;
v_36454:
    goto v_36448;
v_36449:
    goto v_36450;
v_36451:
    goto v_36452;
v_36453:
    v_36605 = list3(stack[-1], stack[0], v_36605);
    return ncons(v_36605);
    v_36605 = nil;
    goto v_36415;
v_36417:
    v_36605 = stack[-1];
    stack[-3] = v_36605;
v_36478:
    v_36605 = stack[-3];
    if (v_36605 == nil) goto v_36483;
    else goto v_36484;
v_36483:
    v_36605 = nil;
    goto v_36477;
v_36484:
    v_36605 = stack[-3];
    v_36605 = qcar(v_36605);
    v_36605 = CC_preproc1(elt(env, 0), v_36605);
    env = stack[-5];
    stack[-2] = v_36605;
    v_36605 = stack[-2];
    fn = elt(env, 26); // lastpair
    v_36605 = (*qfn1(fn))(fn, v_36605);
    env = stack[-5];
    stack[-1] = v_36605;
    v_36605 = stack[-3];
    v_36605 = qcdr(v_36605);
    stack[-3] = v_36605;
    v_36605 = stack[-1];
    if (!consp(v_36605)) goto v_36498;
    else goto v_36499;
v_36498:
    goto v_36478;
v_36499:
v_36479:
    v_36605 = stack[-3];
    if (v_36605 == nil) goto v_36503;
    else goto v_36504;
v_36503:
    v_36605 = stack[-2];
    goto v_36477;
v_36504:
    goto v_36512;
v_36508:
    stack[0] = stack[-1];
    goto v_36509;
v_36510:
    v_36605 = stack[-3];
    v_36605 = qcar(v_36605);
    v_36605 = CC_preproc1(elt(env, 0), v_36605);
    env = stack[-5];
    goto v_36511;
v_36512:
    goto v_36508;
v_36509:
    goto v_36510;
v_36511:
    v_36605 = Lrplacd(nil, stack[0], v_36605);
    env = stack[-5];
    v_36605 = stack[-1];
    fn = elt(env, 26); // lastpair
    v_36605 = (*qfn1(fn))(fn, v_36605);
    env = stack[-5];
    stack[-1] = v_36605;
    v_36605 = stack[-3];
    v_36605 = qcdr(v_36605);
    stack[-3] = v_36605;
    goto v_36479;
v_36477:
    return ncons(v_36605);
    v_36605 = nil;
v_36415:
    goto v_35813;
v_36400:
    v_36605 = qvalue(elt(env, 6)); // !*getdecs
    if (v_36605 == nil) goto v_36528;
    goto v_36536;
v_36532:
    v_36605 = stack[-1];
    v_36606 = qcar(v_36605);
    goto v_36533;
v_36534:
    v_36605 = elt(env, 18); // (!~for for)
    goto v_36535;
v_36536:
    goto v_36532;
v_36533:
    goto v_36534;
v_36535:
    v_36605 = Lmemq(nil, v_36606, v_36605);
    if (v_36605 == nil) goto v_36528;
    goto v_36548;
v_36542:
    v_36607 = nil;
    goto v_36543;
v_36544:
    v_36605 = stack[-1];
    v_36605 = qcdr(v_36605);
    v_36606 = qcar(v_36605);
    goto v_36545;
v_36546:
    v_36605 = elt(env, 19); // (integer)
    goto v_36547;
v_36548:
    goto v_36542;
v_36543:
    goto v_36544;
v_36545:
    goto v_36546;
v_36547:
    fn = elt(env, 25); // symtabput
    v_36605 = (*qfnn(fn))(fn, 3, v_36607, v_36606, v_36605);
    env = stack[-5];
    goto v_36526;
v_36528:
v_36526:
    v_36605 = stack[-1];
    stack[-3] = v_36605;
v_36560:
    v_36605 = stack[-3];
    if (v_36605 == nil) goto v_36565;
    else goto v_36566;
v_36565:
    v_36605 = nil;
    goto v_36559;
v_36566:
    v_36605 = stack[-3];
    v_36605 = qcar(v_36605);
    v_36605 = CC_preproc1(elt(env, 0), v_36605);
    env = stack[-5];
    stack[-2] = v_36605;
    v_36605 = stack[-2];
    fn = elt(env, 26); // lastpair
    v_36605 = (*qfn1(fn))(fn, v_36605);
    env = stack[-5];
    stack[-1] = v_36605;
    v_36605 = stack[-3];
    v_36605 = qcdr(v_36605);
    stack[-3] = v_36605;
    v_36605 = stack[-1];
    if (!consp(v_36605)) goto v_36580;
    else goto v_36581;
v_36580:
    goto v_36560;
v_36581:
v_36561:
    v_36605 = stack[-3];
    if (v_36605 == nil) goto v_36585;
    else goto v_36586;
v_36585:
    v_36605 = stack[-2];
    goto v_36559;
v_36586:
    goto v_36594;
v_36590:
    stack[0] = stack[-1];
    goto v_36591;
v_36592:
    v_36605 = stack[-3];
    v_36605 = qcar(v_36605);
    v_36605 = CC_preproc1(elt(env, 0), v_36605);
    env = stack[-5];
    goto v_36593;
v_36594:
    goto v_36590;
v_36591:
    goto v_36592;
v_36593:
    v_36605 = Lrplacd(nil, stack[0], v_36605);
    env = stack[-5];
    v_36605 = stack[-1];
    fn = elt(env, 26); // lastpair
    v_36605 = (*qfn1(fn))(fn, v_36605);
    env = stack[-5];
    stack[-1] = v_36605;
    v_36605 = stack[-3];
    v_36605 = qcdr(v_36605);
    stack[-3] = v_36605;
    goto v_36561;
v_36559:
    return ncons(v_36605);
v_35816:
    v_36605 = nil;
v_35813:
    return onevalue(v_36605);
}



// Code for find_bubles1

static LispObject CC_find_bubles1(LispObject env,
                         LispObject v_35810, LispObject v_35811)
{
    env = qenv(env);
    LispObject v_35839, v_35840, v_35841, v_35842, v_35843, v_35844;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_35839 = v_35811;
    v_35840 = v_35810;
// end of prologue
    goto v_35826;
v_35814:
    v_35844 = nil;
    goto v_35815;
v_35816:
    v_35841 = v_35840;
    v_35843 = qcar(v_35841);
    goto v_35817;
v_35818:
    v_35842 = nil;
    goto v_35819;
v_35820:
    v_35841 = v_35840;
    v_35841 = qcdr(v_35841);
    v_35841 = qcar(v_35841);
    goto v_35821;
v_35822:
    v_35840 = qcdr(v_35840);
    v_35840 = qcdr(v_35840);
    v_35840 = qcar(v_35840);
    goto v_35823;
v_35824:
    goto v_35825;
v_35826:
    goto v_35814;
v_35815:
    goto v_35816;
v_35817:
    goto v_35818;
v_35819:
    goto v_35820;
v_35821:
    goto v_35822;
v_35823:
    goto v_35824;
v_35825:
    {
        fn = elt(env, 1); // select_bubles
        return (*qfnn(fn))(fn, 6, v_35844, v_35843, v_35842, v_35841, v_35840, v_35839);
    }
}



// Code for compactf1

static LispObject CC_compactf1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_35850, v_35851, v_35852, v_35853, v_35854;
    LispObject fn;
    LispObject v_35813, v_35812, v_35811, v_35810;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "compactf1");
    va_start(aa, nargs);
    v_35810 = va_arg(aa, LispObject);
    v_35811 = va_arg(aa, LispObject);
    v_35812 = va_arg(aa, LispObject);
    v_35813 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_35813,v_35812,v_35811,v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_35810,v_35811,v_35812,v_35813);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_35813;
    stack[-1] = v_35812;
    stack[-2] = v_35811;
    stack[-3] = v_35810;
// end of prologue
    goto v_35824;
v_35820:
    v_35851 = stack[-1];
    goto v_35821;
v_35822:
    v_35850 = stack[0];
    goto v_35823;
v_35824:
    goto v_35820;
v_35821:
    goto v_35822;
v_35823:
    fn = elt(env, 2); // intersection
    v_35850 = (*qfn2(fn))(fn, v_35851, v_35850);
    env = stack[-4];
    v_35851 = v_35850;
    if (v_35851 == nil) goto v_35829;
    else goto v_35830;
v_35829:
    v_35850 = stack[-3];
    goto v_35817;
v_35830:
    goto v_35844;
v_35834:
    v_35854 = stack[-3];
    goto v_35835;
v_35836:
    v_35853 = stack[-2];
    goto v_35837;
v_35838:
    v_35852 = stack[-1];
    goto v_35839;
v_35840:
    v_35851 = stack[0];
    goto v_35841;
v_35842:
    goto v_35843;
v_35844:
    goto v_35834;
v_35835:
    goto v_35836;
v_35837:
    goto v_35838;
v_35839:
    goto v_35840;
v_35841:
    goto v_35842;
v_35843:
    {
        fn = elt(env, 3); // compactf11
        return (*qfnn(fn))(fn, 5, v_35854, v_35853, v_35852, v_35851, v_35850);
    }
v_35817:
    return onevalue(v_35850);
}



// Code for solvevars

static LispObject CC_solvevars(LispObject env,
                         LispObject v_35810)
{
    env = qenv(env);
    LispObject v_35846, v_35847;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35810);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_35847 = v_35810;
// end of prologue
    v_35846 = nil;
    stack[-2] = v_35846;
    v_35846 = v_35847;
    fn = elt(env, 1); // allbkern
    v_35846 = (*qfn1(fn))(fn, v_35846);
    env = stack[-3];
    stack[-1] = v_35846;
v_35817:
    v_35846 = stack[-1];
    if (v_35846 == nil) goto v_35822;
    else goto v_35823;
v_35822:
    goto v_35816;
v_35823:
    v_35846 = stack[-1];
    v_35846 = qcar(v_35846);
    stack[0] = v_35846;
    v_35846 = stack[0];
    fn = elt(env, 2); // constant_exprp
    v_35846 = (*qfn1(fn))(fn, v_35846);
    env = stack[-3];
    if (v_35846 == nil) goto v_35831;
    else goto v_35832;
v_35831:
    goto v_35840;
v_35836:
    v_35847 = stack[0];
    goto v_35837;
v_35838:
    v_35846 = stack[-2];
    goto v_35839;
v_35840:
    goto v_35836;
v_35837:
    goto v_35838;
v_35839:
    fn = elt(env, 3); // ordad
    v_35846 = (*qfn2(fn))(fn, v_35847, v_35846);
    env = stack[-3];
    stack[-2] = v_35846;
    goto v_35830;
v_35832:
v_35830:
    v_35846 = stack[-1];
    v_35846 = qcdr(v_35846);
    stack[-1] = v_35846;
    goto v_35817;
v_35816:
    v_35846 = stack[-2];
    return onevalue(v_35846);
}



// Code for nrootnn

static LispObject CC_nrootnn(LispObject env,
                         LispObject v_35810, LispObject v_35811)
{
    env = qenv(env);
    LispObject v_36107, v_36108;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_35811,v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_35810,v_35811);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-6] = v_35811;
    stack[-7] = v_35810;
// end of prologue
    stack[-5] = nil;
    v_36107 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_36107;
    v_36107 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_36107;
    goto v_35841;
v_35837:
    v_36108 = stack[-7];
    goto v_35838;
v_35839:
    v_36107 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35840;
v_35841:
    goto v_35837;
v_35838:
    goto v_35839;
v_35840:
    v_36107 = (LispObject)lessp2(v_36108, v_36107);
    v_36107 = v_36107 ? lisp_true : nil;
    env = stack[-9];
    if (v_36107 == nil) goto v_35835;
    v_36107 = stack[-7];
    v_36107 = negate(v_36107);
    env = stack[-9];
    stack[-7] = v_36107;
    v_36107 = stack[-6];
    v_36107 = Levenp(nil, v_36107);
    env = stack[-9];
    if (v_36107 == nil) goto v_35849;
    v_36107 = lisp_true;
    stack[-5] = v_36107;
    goto v_35847;
v_35849:
    v_36107 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[0] = v_36107;
    goto v_35847;
v_35847:
    goto v_35833;
v_35835:
v_35833:
    v_36107 = qvalue(elt(env, 2)); // !*primelist!*
    stack[-8] = v_36107;
v_35823:
    v_36107 = stack[-8];
    v_36107 = qcar(v_36107);
    stack[-1] = v_36107;
    v_36107 = stack[-8];
    v_36107 = qcdr(v_36107);
    stack[-8] = v_36107;
    v_36107 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_36107;
v_35864:
    goto v_35873;
v_35869:
    goto v_35879;
v_35875:
    v_36108 = stack[-7];
    goto v_35876;
v_35877:
    v_36107 = stack[-1];
    goto v_35878;
v_35879:
    goto v_35875;
v_35876:
    goto v_35877;
v_35878:
    v_36107 = Ldivide(nil, v_36108, v_36107);
    env = stack[-9];
    stack[-4] = v_36107;
    v_36108 = qcdr(v_36107);
    goto v_35870;
v_35871:
    v_36107 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35872;
v_35873:
    goto v_35869;
v_35870:
    goto v_35871;
v_35872:
    if (v_36108 == v_36107) goto v_35868;
    goto v_35863;
v_35868:
    v_36107 = stack[-4];
    v_36107 = qcar(v_36107);
    stack[-7] = v_36107;
    v_36107 = stack[-3];
    v_36107 = (LispObject)((intptr_t)(v_36107) + 0x10);
    stack[-3] = v_36107;
    goto v_35864;
v_35863:
    goto v_35897;
v_35893:
    v_36108 = stack[-3];
    goto v_35894;
v_35895:
    v_36107 = stack[-6];
    goto v_35896;
v_35897:
    goto v_35893;
v_35894:
    goto v_35895;
v_35896:
    if (((intptr_t)(v_36108)) < ((intptr_t)(v_36107))) goto v_35892;
    goto v_35905;
v_35901:
    v_36108 = stack[-3];
    goto v_35902;
v_35903:
    v_36107 = stack[-6];
    goto v_35904;
v_35905:
    goto v_35901;
v_35902:
    goto v_35903;
v_35904:
    v_36107 = Ldivide(nil, v_36108, v_36107);
    env = stack[-9];
    stack[-3] = v_36107;
    goto v_35913;
v_35909:
    goto v_35910;
v_35911:
    goto v_35920;
v_35916:
    v_36108 = stack[-1];
    goto v_35917;
v_35918:
    v_36107 = stack[-3];
    v_36107 = qcar(v_36107);
    goto v_35919;
v_35920:
    goto v_35916;
v_35917:
    goto v_35918;
v_35919:
    v_36107 = Lexpt(nil, v_36108, v_36107);
    env = stack[-9];
    goto v_35912;
v_35913:
    goto v_35909;
v_35910:
    goto v_35911;
v_35912:
    v_36107 = times2(stack[0], v_36107);
    env = stack[-9];
    stack[0] = v_36107;
    v_36107 = stack[-3];
    v_36107 = qcdr(v_36107);
    stack[-3] = v_36107;
    goto v_35890;
v_35892:
v_35890:
v_35928:
    goto v_35937;
v_35933:
    v_36108 = stack[-3];
    goto v_35934;
v_35935:
    v_36107 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35936;
v_35937:
    goto v_35933;
v_35934:
    goto v_35935;
v_35936:
    if (((intptr_t)(v_36108)) > ((intptr_t)(v_36107))) goto v_35932;
    goto v_35927;
v_35932:
    goto v_35946;
v_35942:
    v_36108 = stack[-2];
    goto v_35943;
v_35944:
    v_36107 = stack[-1];
    goto v_35945;
v_35946:
    goto v_35942;
v_35943:
    goto v_35944;
v_35945:
    v_36107 = times2(v_36108, v_36107);
    env = stack[-9];
    stack[-2] = v_36107;
    v_36107 = stack[-3];
    v_36107 = (LispObject)((intptr_t)(v_36107) - 0x10);
    stack[-3] = v_36107;
    goto v_35928;
v_35927:
    goto v_35960;
v_35956:
    v_36107 = stack[-4];
    v_36108 = qcar(v_36107);
    goto v_35957;
v_35958:
    v_36107 = stack[-1];
    goto v_35959;
v_35960:
    goto v_35956;
v_35957:
    goto v_35958;
v_35959:
    v_36107 = (LispObject)lessp2(v_36108, v_36107);
    v_36107 = v_36107 ? lisp_true : nil;
    env = stack[-9];
    if (v_36107 == nil) goto v_35954;
    goto v_35969;
v_35965:
    v_36108 = stack[-7];
    goto v_35966;
v_35967:
    v_36107 = stack[-2];
    goto v_35968;
v_35969:
    goto v_35965;
v_35966:
    goto v_35967;
v_35968:
    v_36107 = times2(v_36108, v_36107);
    env = stack[-9];
    stack[-2] = v_36107;
    goto v_35824;
v_35954:
    v_36107 = stack[-8];
    if (v_36107 == nil) goto v_35975;
    goto v_35823;
v_35975:
    goto v_35986;
v_35982:
    goto v_35992;
v_35988:
    v_36108 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_35989;
v_35990:
    v_36107 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_35991;
v_35992:
    goto v_35988;
v_35989:
    goto v_35990;
v_35991:
    v_36108 = Lexpt(nil, v_36108, v_36107);
    env = stack[-9];
    goto v_35983;
v_35984:
    v_36107 = stack[-7];
    goto v_35985;
v_35986:
    goto v_35982;
v_35983:
    goto v_35984;
v_35985:
    v_36107 = (LispObject)greaterp2(v_36108, v_36107);
    v_36107 = v_36107 ? lisp_true : nil;
    env = stack[-9];
    if (v_36107 == nil) goto v_35980;
    goto v_36001;
v_35997:
    v_36108 = stack[-7];
    goto v_35998;
v_35999:
    v_36107 = nil;
    goto v_36000;
v_36001:
    goto v_35997;
v_35998:
    goto v_35999;
v_36000:
    fn = elt(env, 3); // mcfactor!*
    v_36107 = (*qfn2(fn))(fn, v_36108, v_36107);
    env = stack[-9];
    stack[-3] = v_36107;
    v_36107 = stack[-3];
    stack[-4] = v_36107;
v_36007:
    v_36107 = stack[-4];
    if (v_36107 == nil) goto v_36011;
    else goto v_36012;
v_36011:
    goto v_36006;
v_36012:
    v_36107 = stack[-4];
    v_36107 = qcar(v_36107);
    stack[-1] = v_36107;
    goto v_36023;
v_36019:
    v_36107 = stack[-1];
    v_36108 = qcdr(v_36107);
    goto v_36020;
v_36021:
    v_36107 = stack[-6];
    goto v_36022;
v_36023:
    goto v_36019;
v_36020:
    goto v_36021;
v_36022:
    v_36107 = Ldivide(nil, v_36108, v_36107);
    env = stack[-9];
    stack[-3] = v_36107;
    goto v_36032;
v_36028:
    goto v_36038;
v_36034:
    v_36107 = stack[-1];
    v_36108 = qcar(v_36107);
    goto v_36035;
v_36036:
    v_36107 = stack[-3];
    v_36107 = qcar(v_36107);
    goto v_36037;
v_36038:
    goto v_36034;
v_36035:
    goto v_36036;
v_36037:
    v_36108 = Lexpt(nil, v_36108, v_36107);
    env = stack[-9];
    goto v_36029;
v_36030:
    v_36107 = stack[0];
    goto v_36031;
v_36032:
    goto v_36028;
v_36029:
    goto v_36030;
v_36031:
    v_36107 = times2(v_36108, v_36107);
    env = stack[-9];
    stack[0] = v_36107;
    goto v_36049;
v_36045:
    goto v_36055;
v_36051:
    v_36107 = stack[-1];
    v_36108 = qcar(v_36107);
    goto v_36052;
v_36053:
    v_36107 = stack[-3];
    v_36107 = qcdr(v_36107);
    goto v_36054;
v_36055:
    goto v_36051;
v_36052:
    goto v_36053;
v_36054:
    v_36108 = Lexpt(nil, v_36108, v_36107);
    env = stack[-9];
    goto v_36046;
v_36047:
    v_36107 = stack[-2];
    goto v_36048;
v_36049:
    goto v_36045;
v_36046:
    goto v_36047;
v_36048:
    v_36107 = times2(v_36108, v_36107);
    env = stack[-9];
    stack[-2] = v_36107;
    v_36107 = stack[-4];
    v_36107 = qcdr(v_36107);
    stack[-4] = v_36107;
    goto v_36007;
v_36006:
    goto v_35978;
v_35980:
    goto v_36071;
v_36067:
    v_36108 = stack[-7];
    goto v_36068;
v_36069:
    v_36107 = stack[-6];
    goto v_36070;
v_36071:
    goto v_36067;
v_36068:
    goto v_36069;
v_36070:
    fn = elt(env, 4); // iroot
    v_36107 = (*qfn2(fn))(fn, v_36108, v_36107);
    env = stack[-9];
    stack[-3] = v_36107;
    if (v_36107 == nil) goto v_36065;
    goto v_36079;
v_36075:
    v_36108 = stack[0];
    goto v_36076;
v_36077:
    v_36107 = stack[-3];
    goto v_36078;
v_36079:
    goto v_36075;
v_36076:
    goto v_36077;
v_36078:
    v_36107 = times2(v_36108, v_36107);
    env = stack[-9];
    stack[0] = v_36107;
    goto v_35978;
v_36065:
    goto v_36089;
v_36085:
    v_36108 = stack[-7];
    goto v_36086;
v_36087:
    v_36107 = stack[-2];
    goto v_36088;
v_36089:
    goto v_36085;
v_36086:
    goto v_36087;
v_36088:
    v_36107 = times2(v_36108, v_36107);
    env = stack[-9];
    stack[-2] = v_36107;
    goto v_35978;
v_35978:
v_35824:
    v_36107 = stack[-5];
    if (v_36107 == nil) goto v_36095;
    v_36107 = stack[-2];
    v_36107 = negate(v_36107);
    stack[-2] = v_36107;
    goto v_36093;
v_36095:
v_36093:
    goto v_36104;
v_36100:
    v_36108 = stack[0];
    goto v_36101;
v_36102:
    v_36107 = stack[-2];
    goto v_36103;
v_36104:
    goto v_36100;
v_36101:
    goto v_36102;
v_36103:
    return cons(v_36108, v_36107);
    return onevalue(v_36107);
}



// Code for rat_min

static LispObject CC_rat_min(LispObject env,
                         LispObject v_35810, LispObject v_35811)
{
    env = qenv(env);
    LispObject v_35829, v_35830;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_35811,v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_35810,v_35811);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_35811;
    stack[-1] = v_35810;
// end of prologue
    goto v_35822;
v_35818:
    v_35830 = stack[-1];
    goto v_35819;
v_35820:
    v_35829 = stack[0];
    goto v_35821;
v_35822:
    goto v_35818;
v_35819:
    goto v_35820;
v_35821:
    fn = elt(env, 1); // rat_leq
    v_35829 = (*qfn2(fn))(fn, v_35830, v_35829);
    if (v_35829 == nil) goto v_35816;
    v_35829 = stack[-1];
    goto v_35814;
v_35816:
    v_35829 = stack[0];
    goto v_35814;
    v_35829 = nil;
v_35814:
    return onevalue(v_35829);
}



// Code for let0

static LispObject CC_let0(LispObject env,
                         LispObject v_35810)
{
    env = qenv(env);
    LispObject v_35816, v_35817;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35810);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_35817 = v_35810;
// end of prologue
    v_35816 = nil;
// Binding frasc!*
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_35816; // frasc!*
    v_35816 = v_35817;
    fn = elt(env, 2); // let00
    v_35816 = (*qfn1(fn))(fn, v_35816);
    ;}  // end of a binding scope
    return onevalue(v_35816);
}



// Code for get!-min!-degreelist

static LispObject CC_getKminKdegreelist(LispObject env,
                         LispObject v_35810)
{
    env = qenv(env);
    LispObject v_35929, v_35930;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35810);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_35930 = v_35810;
// end of prologue
    v_35929 = v_35930;
    if (v_35929 == nil) goto v_35814;
    else goto v_35815;
v_35814:
    v_35929 = elt(env, 0); // get!-min!-degreelist
    {
        fn = elt(env, 1); // confusion
        return (*qfn1(fn))(fn, v_35929);
    }
v_35815:
    v_35929 = v_35930;
    v_35929 = qcdr(v_35929);
    if (v_35929 == nil) goto v_35819;
    else goto v_35820;
v_35819:
    v_35929 = v_35930;
    v_35929 = qcar(v_35929);
    v_35929 = qcar(v_35929);
    stack[-4] = v_35929;
    v_35929 = stack[-4];
    if (v_35929 == nil) goto v_35834;
    else goto v_35835;
v_35834:
    v_35929 = nil;
    goto v_35827;
v_35835:
    v_35929 = stack[-4];
    v_35929 = qcar(v_35929);
    stack[0] = v_35929;
    v_35929 = (LispObject)0+TAG_FIXNUM; // 0
    v_35930 = v_35929;
v_35846:
    v_35929 = stack[0];
    if (v_35929 == nil) goto v_35851;
    else goto v_35852;
v_35851:
    v_35929 = v_35930;
    goto v_35845;
v_35852:
    goto v_35860;
v_35856:
    v_35929 = stack[0];
    v_35929 = qcar(v_35929);
    goto v_35857;
v_35858:
    goto v_35859;
v_35860:
    goto v_35856;
v_35857:
    goto v_35858;
v_35859:
    fn = elt(env, 2); // tayexp!-plus2
    v_35929 = (*qfn2(fn))(fn, v_35929, v_35930);
    env = stack[-5];
    v_35930 = v_35929;
    v_35929 = stack[0];
    v_35929 = qcdr(v_35929);
    stack[0] = v_35929;
    goto v_35846;
v_35845:
    v_35929 = ncons(v_35929);
    env = stack[-5];
    stack[-2] = v_35929;
    stack[-3] = v_35929;
v_35828:
    v_35929 = stack[-4];
    v_35929 = qcdr(v_35929);
    stack[-4] = v_35929;
    v_35929 = stack[-4];
    if (v_35929 == nil) goto v_35872;
    else goto v_35873;
v_35872:
    v_35929 = stack[-3];
    goto v_35827;
v_35873:
    goto v_35881;
v_35877:
    stack[-1] = stack[-2];
    goto v_35878;
v_35879:
    v_35929 = stack[-4];
    v_35929 = qcar(v_35929);
    stack[0] = v_35929;
    v_35929 = (LispObject)0+TAG_FIXNUM; // 0
    v_35930 = v_35929;
v_35891:
    v_35929 = stack[0];
    if (v_35929 == nil) goto v_35896;
    else goto v_35897;
v_35896:
    v_35929 = v_35930;
    goto v_35890;
v_35897:
    goto v_35905;
v_35901:
    v_35929 = stack[0];
    v_35929 = qcar(v_35929);
    goto v_35902;
v_35903:
    goto v_35904;
v_35905:
    goto v_35901;
v_35902:
    goto v_35903;
v_35904:
    fn = elt(env, 2); // tayexp!-plus2
    v_35929 = (*qfn2(fn))(fn, v_35929, v_35930);
    env = stack[-5];
    v_35930 = v_35929;
    v_35929 = stack[0];
    v_35929 = qcdr(v_35929);
    stack[0] = v_35929;
    goto v_35891;
v_35890:
    v_35929 = ncons(v_35929);
    env = stack[-5];
    goto v_35880;
v_35881:
    goto v_35877;
v_35878:
    goto v_35879;
v_35880:
    v_35929 = Lrplacd(nil, stack[-1], v_35929);
    env = stack[-5];
    v_35929 = stack[-2];
    v_35929 = qcdr(v_35929);
    stack[-2] = v_35929;
    goto v_35828;
v_35827:
    goto v_35813;
v_35820:
    goto v_35922;
v_35918:
    v_35929 = v_35930;
    v_35929 = qcar(v_35929);
    stack[0] = qcar(v_35929);
    goto v_35919;
v_35920:
    v_35929 = v_35930;
    v_35929 = qcdr(v_35929);
    v_35929 = CC_getKminKdegreelist(elt(env, 0), v_35929);
    env = stack[-5];
    goto v_35921;
v_35922:
    goto v_35918;
v_35919:
    goto v_35920;
v_35921:
    {
        LispObject v_35936 = stack[0];
        fn = elt(env, 3); // taymindegreel
        return (*qfn2(fn))(fn, v_35936, v_35929);
    }
    v_35929 = nil;
v_35813:
    return onevalue(v_35929);
}



// Code for cl_subfof1

static LispObject CC_cl_subfof1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_36545, v_36546, v_36547, v_36548;
    LispObject fn;
    LispObject v_35813, v_35812, v_35811, v_35810;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_subfof1");
    va_start(aa, nargs);
    v_35810 = va_arg(aa, LispObject);
    v_35811 = va_arg(aa, LispObject);
    v_35812 = va_arg(aa, LispObject);
    v_35813 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_35813,v_35812,v_35811,v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_35810,v_35811,v_35812,v_35813);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-7] = v_35813;
    stack[-2] = v_35812;
    v_36547 = v_35811;
    stack[-8] = v_35810;
// end of prologue
    v_36545 = v_36547;
    if (!consp(v_36545)) goto v_35825;
    else goto v_35826;
v_35825:
    v_36545 = v_36547;
    goto v_35824;
v_35826:
    v_36545 = v_36547;
    v_36545 = qcar(v_36545);
    goto v_35824;
    v_36545 = nil;
v_35824:
    stack[-9] = v_36545;
    goto v_35845;
v_35841:
    v_36546 = stack[-9];
    goto v_35842;
v_35843:
    v_36545 = elt(env, 2); // true
    goto v_35844;
v_35845:
    goto v_35841;
v_35842:
    goto v_35843;
v_35844:
    if (v_36546 == v_36545) goto v_35839;
    else goto v_35840;
v_35839:
    v_36545 = lisp_true;
    goto v_35838;
v_35840:
    goto v_35855;
v_35851:
    v_36546 = stack[-9];
    goto v_35852;
v_35853:
    v_36545 = elt(env, 3); // false
    goto v_35854;
v_35855:
    goto v_35851;
v_35852:
    goto v_35853;
v_35854:
    v_36545 = (v_36546 == v_36545 ? lisp_true : nil);
    goto v_35838;
    v_36545 = nil;
v_35838:
    if (v_36545 == nil) goto v_35836;
    v_36545 = v_36547;
    goto v_35821;
v_35836:
    goto v_35872;
v_35868:
    v_36546 = stack[-9];
    goto v_35869;
v_35870:
    v_36545 = elt(env, 4); // ex
    goto v_35871;
v_35872:
    goto v_35868;
v_35869:
    goto v_35870;
v_35871:
    if (v_36546 == v_36545) goto v_35866;
    else goto v_35867;
v_35866:
    v_36545 = lisp_true;
    goto v_35865;
v_35867:
    goto v_35882;
v_35878:
    v_36546 = stack[-9];
    goto v_35879;
v_35880:
    v_36545 = elt(env, 5); // all
    goto v_35881;
v_35882:
    goto v_35878;
v_35879:
    goto v_35880;
v_35881:
    v_36545 = (v_36546 == v_36545 ? lisp_true : nil);
    goto v_35865;
    v_36545 = nil;
v_35865:
    if (v_36545 == nil) goto v_35863;
    v_36545 = v_36547;
    v_36545 = qcdr(v_36545);
    v_36545 = qcar(v_36545);
    stack[-6] = v_36545;
    v_36545 = v_36547;
    v_36545 = qcdr(v_36545);
    v_36545 = qcdr(v_36545);
    v_36545 = qcar(v_36545);
    stack[-5] = v_36545;
    v_36545 = stack[-8];
    stack[-4] = v_36545;
v_35898:
    v_36545 = stack[-4];
    if (v_36545 == nil) goto v_35903;
    else goto v_35904;
v_35903:
    v_36545 = nil;
    goto v_35897;
v_35904:
    v_36545 = stack[-4];
    v_36545 = qcar(v_36545);
    v_36547 = v_36545;
    goto v_35919;
v_35915:
    v_36546 = v_36547;
    goto v_35916;
v_35917:
    v_36545 = stack[-6];
    goto v_35918;
v_35919:
    goto v_35915;
v_35916:
    goto v_35917;
v_35918:
    if (!consp(v_36546)) goto v_35912;
    v_36546 = qcar(v_36546);
    if (v_36546 == v_36545) goto v_35913;
v_35912:
    v_36545 = v_36547;
    v_36545 = ncons(v_36545);
    env = stack[-10];
    goto v_35911;
v_35913:
    v_36545 = nil;
v_35911:
    stack[-3] = v_36545;
    v_36545 = stack[-3];
    fn = elt(env, 14); // lastpair
    v_36545 = (*qfn1(fn))(fn, v_36545);
    env = stack[-10];
    stack[-1] = v_36545;
    v_36545 = stack[-4];
    v_36545 = qcdr(v_36545);
    stack[-4] = v_36545;
    v_36545 = stack[-1];
    if (!consp(v_36545)) goto v_35930;
    else goto v_35931;
v_35930:
    goto v_35898;
v_35931:
v_35899:
    v_36545 = stack[-4];
    if (v_36545 == nil) goto v_35935;
    else goto v_35936;
v_35935:
    v_36545 = stack[-3];
    goto v_35897;
v_35936:
    goto v_35944;
v_35940:
    stack[0] = stack[-1];
    goto v_35941;
v_35942:
    v_36545 = stack[-4];
    v_36545 = qcar(v_36545);
    v_36547 = v_36545;
    goto v_35958;
v_35954:
    v_36546 = v_36547;
    goto v_35955;
v_35956:
    v_36545 = stack[-6];
    goto v_35957;
v_35958:
    goto v_35954;
v_35955:
    goto v_35956;
v_35957:
    if (!consp(v_36546)) goto v_35951;
    v_36546 = qcar(v_36546);
    if (v_36546 == v_36545) goto v_35952;
v_35951:
    v_36545 = v_36547;
    v_36545 = ncons(v_36545);
    env = stack[-10];
    goto v_35950;
v_35952:
    v_36545 = nil;
v_35950:
    goto v_35943;
v_35944:
    goto v_35940;
v_35941:
    goto v_35942;
v_35943:
    v_36545 = Lrplacd(nil, stack[0], v_36545);
    env = stack[-10];
    v_36545 = stack[-1];
    fn = elt(env, 14); // lastpair
    v_36545 = (*qfn1(fn))(fn, v_36545);
    env = stack[-10];
    stack[-1] = v_36545;
    v_36545 = stack[-4];
    v_36545 = qcdr(v_36545);
    stack[-4] = v_36545;
    goto v_35899;
v_35897:
    stack[-8] = v_36545;
    v_36545 = stack[-2];
    stack[-3] = v_36545;
v_35972:
    v_36545 = stack[-3];
    if (v_36545 == nil) goto v_35977;
    else goto v_35978;
v_35977:
    v_36545 = nil;
    goto v_35971;
v_35978:
    v_36545 = stack[-3];
    v_36545 = qcar(v_36545);
    v_36547 = v_36545;
    goto v_35993;
v_35989:
    v_36546 = v_36547;
    goto v_35990;
v_35991:
    v_36545 = stack[-6];
    goto v_35992;
v_35993:
    goto v_35989;
v_35990:
    goto v_35991;
v_35992:
    if (!consp(v_36546)) goto v_35986;
    v_36546 = qcar(v_36546);
    if (v_36546 == v_36545) goto v_35987;
v_35986:
    v_36545 = v_36547;
    v_36545 = ncons(v_36545);
    env = stack[-10];
    goto v_35985;
v_35987:
    v_36545 = nil;
v_35985:
    stack[-2] = v_36545;
    v_36545 = stack[-2];
    fn = elt(env, 14); // lastpair
    v_36545 = (*qfn1(fn))(fn, v_36545);
    env = stack[-10];
    stack[-1] = v_36545;
    v_36545 = stack[-3];
    v_36545 = qcdr(v_36545);
    stack[-3] = v_36545;
    v_36545 = stack[-1];
    if (!consp(v_36545)) goto v_36004;
    else goto v_36005;
v_36004:
    goto v_35972;
v_36005:
v_35973:
    v_36545 = stack[-3];
    if (v_36545 == nil) goto v_36009;
    else goto v_36010;
v_36009:
    v_36545 = stack[-2];
    goto v_35971;
v_36010:
    goto v_36018;
v_36014:
    stack[0] = stack[-1];
    goto v_36015;
v_36016:
    v_36545 = stack[-3];
    v_36545 = qcar(v_36545);
    v_36547 = v_36545;
    goto v_36032;
v_36028:
    v_36546 = v_36547;
    goto v_36029;
v_36030:
    v_36545 = stack[-6];
    goto v_36031;
v_36032:
    goto v_36028;
v_36029:
    goto v_36030;
v_36031:
    if (!consp(v_36546)) goto v_36025;
    v_36546 = qcar(v_36546);
    if (v_36546 == v_36545) goto v_36026;
v_36025:
    v_36545 = v_36547;
    v_36545 = ncons(v_36545);
    env = stack[-10];
    goto v_36024;
v_36026:
    v_36545 = nil;
v_36024:
    goto v_36017;
v_36018:
    goto v_36014;
v_36015:
    goto v_36016;
v_36017:
    v_36545 = Lrplacd(nil, stack[0], v_36545);
    env = stack[-10];
    v_36545 = stack[-1];
    fn = elt(env, 14); // lastpair
    v_36545 = (*qfn1(fn))(fn, v_36545);
    env = stack[-10];
    stack[-1] = v_36545;
    v_36545 = stack[-3];
    v_36545 = qcdr(v_36545);
    stack[-3] = v_36545;
    goto v_35973;
v_35971:
    stack[-2] = v_36545;
    goto v_36050;
v_36042:
    v_36548 = stack[-6];
    goto v_36043;
v_36044:
    v_36547 = stack[-5];
    goto v_36045;
v_36046:
    v_36546 = stack[-2];
    goto v_36047;
v_36048:
    v_36545 = stack[-7];
    goto v_36049;
v_36050:
    goto v_36042;
v_36043:
    goto v_36044;
v_36045:
    goto v_36046;
v_36047:
    goto v_36048;
v_36049:
    fn = elt(env, 15); // cl_newv
    v_36545 = (*qfnn(fn))(fn, 4, v_36548, v_36547, v_36546, v_36545);
    env = stack[-10];
    stack[0] = v_36545;
    goto v_36063;
v_36059:
    v_36546 = stack[0];
    goto v_36060;
v_36061:
    v_36545 = stack[-6];
    goto v_36062;
v_36063:
    goto v_36059;
v_36060:
    goto v_36061;
v_36062:
    if (equal(v_36546, v_36545)) goto v_36058;
    goto v_36071;
v_36067:
    v_36546 = stack[0];
    goto v_36068;
v_36069:
    v_36545 = stack[-7];
    goto v_36070;
v_36071:
    goto v_36067;
v_36068:
    goto v_36069;
v_36070:
    v_36545 = cons(v_36546, v_36545);
    env = stack[-10];
    stack[-7] = v_36545;
    goto v_36081;
v_36075:
    v_36547 = stack[0];
    goto v_36076;
v_36077:
    v_36546 = stack[-6];
    goto v_36078;
v_36079:
    v_36545 = stack[-5];
    goto v_36080;
v_36081:
    goto v_36075;
v_36076:
    goto v_36077;
v_36078:
    goto v_36079;
v_36080:
    fn = elt(env, 16); // cl_subvarsubstat
    v_36545 = (*qfnn(fn))(fn, 3, v_36547, v_36546, v_36545);
    env = stack[-10];
    stack[-5] = v_36545;
    goto v_36056;
v_36058:
v_36056:
    goto v_36092;
v_36086:
    stack[-1] = stack[-9];
    goto v_36087;
v_36088:
    goto v_36089;
v_36090:
    goto v_36104;
v_36096:
    v_36548 = stack[-8];
    goto v_36097;
v_36098:
    v_36547 = stack[-5];
    goto v_36099;
v_36100:
    v_36546 = stack[-2];
    goto v_36101;
v_36102:
    v_36545 = stack[-7];
    goto v_36103;
v_36104:
    goto v_36096;
v_36097:
    goto v_36098;
v_36099:
    goto v_36100;
v_36101:
    goto v_36102;
v_36103:
    v_36545 = CC_cl_subfof1(elt(env, 0), 4, v_36548, v_36547, v_36546, v_36545);
    goto v_36091;
v_36092:
    goto v_36086;
v_36087:
    goto v_36088;
v_36089:
    goto v_36090;
v_36091:
    {
        LispObject v_36559 = stack[-1];
        LispObject v_36560 = stack[0];
        return list3(v_36559, v_36560, v_36545);
    }
v_35863:
    goto v_36121;
v_36117:
    v_36546 = stack[-9];
    goto v_36118;
v_36119:
    v_36545 = elt(env, 6); // bex
    goto v_36120;
v_36121:
    goto v_36117;
v_36118:
    goto v_36119;
v_36120:
    if (v_36546 == v_36545) goto v_36115;
    else goto v_36116;
v_36115:
    v_36545 = lisp_true;
    goto v_36114;
v_36116:
    goto v_36131;
v_36127:
    v_36546 = stack[-9];
    goto v_36128;
v_36129:
    v_36545 = elt(env, 7); // ball
    goto v_36130;
v_36131:
    goto v_36127;
v_36128:
    goto v_36129;
v_36130:
    v_36545 = (v_36546 == v_36545 ? lisp_true : nil);
    goto v_36114;
    v_36545 = nil;
v_36114:
    if (v_36545 == nil) goto v_36112;
    v_36545 = v_36547;
    v_36545 = qcdr(v_36545);
    v_36545 = qcar(v_36545);
    stack[-6] = v_36545;
    v_36545 = v_36547;
    v_36545 = qcdr(v_36545);
    v_36545 = qcdr(v_36545);
    v_36545 = qcar(v_36545);
    stack[-5] = v_36545;
    v_36545 = v_36547;
    v_36545 = qcdr(v_36545);
    v_36545 = qcdr(v_36545);
    v_36545 = qcdr(v_36545);
    v_36545 = qcar(v_36545);
    stack[-4] = v_36545;
    v_36545 = stack[-8];
    stack[-8] = v_36545;
v_36152:
    v_36545 = stack[-8];
    if (v_36545 == nil) goto v_36157;
    else goto v_36158;
v_36157:
    v_36545 = nil;
    goto v_36151;
v_36158:
    v_36545 = stack[-8];
    v_36545 = qcar(v_36545);
    v_36547 = v_36545;
    goto v_36173;
v_36169:
    v_36546 = v_36547;
    goto v_36170;
v_36171:
    v_36545 = stack[-6];
    goto v_36172;
v_36173:
    goto v_36169;
v_36170:
    goto v_36171;
v_36172:
    if (!consp(v_36546)) goto v_36166;
    v_36546 = qcar(v_36546);
    if (v_36546 == v_36545) goto v_36167;
v_36166:
    v_36545 = v_36547;
    v_36545 = ncons(v_36545);
    env = stack[-10];
    goto v_36165;
v_36167:
    v_36545 = nil;
v_36165:
    stack[-3] = v_36545;
    v_36545 = stack[-3];
    fn = elt(env, 14); // lastpair
    v_36545 = (*qfn1(fn))(fn, v_36545);
    env = stack[-10];
    stack[-1] = v_36545;
    v_36545 = stack[-8];
    v_36545 = qcdr(v_36545);
    stack[-8] = v_36545;
    v_36545 = stack[-1];
    if (!consp(v_36545)) goto v_36184;
    else goto v_36185;
v_36184:
    goto v_36152;
v_36185:
v_36153:
    v_36545 = stack[-8];
    if (v_36545 == nil) goto v_36189;
    else goto v_36190;
v_36189:
    v_36545 = stack[-3];
    goto v_36151;
v_36190:
    goto v_36198;
v_36194:
    stack[0] = stack[-1];
    goto v_36195;
v_36196:
    v_36545 = stack[-8];
    v_36545 = qcar(v_36545);
    v_36547 = v_36545;
    goto v_36212;
v_36208:
    v_36546 = v_36547;
    goto v_36209;
v_36210:
    v_36545 = stack[-6];
    goto v_36211;
v_36212:
    goto v_36208;
v_36209:
    goto v_36210;
v_36211:
    if (!consp(v_36546)) goto v_36205;
    v_36546 = qcar(v_36546);
    if (v_36546 == v_36545) goto v_36206;
v_36205:
    v_36545 = v_36547;
    v_36545 = ncons(v_36545);
    env = stack[-10];
    goto v_36204;
v_36206:
    v_36545 = nil;
v_36204:
    goto v_36197;
v_36198:
    goto v_36194;
v_36195:
    goto v_36196;
v_36197:
    v_36545 = Lrplacd(nil, stack[0], v_36545);
    env = stack[-10];
    v_36545 = stack[-1];
    fn = elt(env, 14); // lastpair
    v_36545 = (*qfn1(fn))(fn, v_36545);
    env = stack[-10];
    stack[-1] = v_36545;
    v_36545 = stack[-8];
    v_36545 = qcdr(v_36545);
    stack[-8] = v_36545;
    goto v_36153;
v_36151:
    stack[-8] = v_36545;
    v_36545 = stack[-2];
    stack[-3] = v_36545;
v_36226:
    v_36545 = stack[-3];
    if (v_36545 == nil) goto v_36231;
    else goto v_36232;
v_36231:
    v_36545 = nil;
    goto v_36225;
v_36232:
    v_36545 = stack[-3];
    v_36545 = qcar(v_36545);
    v_36547 = v_36545;
    goto v_36247;
v_36243:
    v_36546 = v_36547;
    goto v_36244;
v_36245:
    v_36545 = stack[-6];
    goto v_36246;
v_36247:
    goto v_36243;
v_36244:
    goto v_36245;
v_36246:
    if (!consp(v_36546)) goto v_36240;
    v_36546 = qcar(v_36546);
    if (v_36546 == v_36545) goto v_36241;
v_36240:
    v_36545 = v_36547;
    v_36545 = ncons(v_36545);
    env = stack[-10];
    goto v_36239;
v_36241:
    v_36545 = nil;
v_36239:
    stack[-2] = v_36545;
    v_36545 = stack[-2];
    fn = elt(env, 14); // lastpair
    v_36545 = (*qfn1(fn))(fn, v_36545);
    env = stack[-10];
    stack[-1] = v_36545;
    v_36545 = stack[-3];
    v_36545 = qcdr(v_36545);
    stack[-3] = v_36545;
    v_36545 = stack[-1];
    if (!consp(v_36545)) goto v_36258;
    else goto v_36259;
v_36258:
    goto v_36226;
v_36259:
v_36227:
    v_36545 = stack[-3];
    if (v_36545 == nil) goto v_36263;
    else goto v_36264;
v_36263:
    v_36545 = stack[-2];
    goto v_36225;
v_36264:
    goto v_36272;
v_36268:
    stack[0] = stack[-1];
    goto v_36269;
v_36270:
    v_36545 = stack[-3];
    v_36545 = qcar(v_36545);
    v_36547 = v_36545;
    goto v_36286;
v_36282:
    v_36546 = v_36547;
    goto v_36283;
v_36284:
    v_36545 = stack[-6];
    goto v_36285;
v_36286:
    goto v_36282;
v_36283:
    goto v_36284;
v_36285:
    if (!consp(v_36546)) goto v_36279;
    v_36546 = qcar(v_36546);
    if (v_36546 == v_36545) goto v_36280;
v_36279:
    v_36545 = v_36547;
    v_36545 = ncons(v_36545);
    env = stack[-10];
    goto v_36278;
v_36280:
    v_36545 = nil;
v_36278:
    goto v_36271;
v_36272:
    goto v_36268;
v_36269:
    goto v_36270;
v_36271:
    v_36545 = Lrplacd(nil, stack[0], v_36545);
    env = stack[-10];
    v_36545 = stack[-1];
    fn = elt(env, 14); // lastpair
    v_36545 = (*qfn1(fn))(fn, v_36545);
    env = stack[-10];
    stack[-1] = v_36545;
    v_36545 = stack[-3];
    v_36545 = qcdr(v_36545);
    stack[-3] = v_36545;
    goto v_36227;
v_36225:
    stack[-2] = v_36545;
    goto v_36304;
v_36296:
    v_36548 = stack[-6];
    goto v_36297;
v_36298:
    v_36547 = stack[-5];
    goto v_36299;
v_36300:
    v_36546 = stack[-2];
    goto v_36301;
v_36302:
    v_36545 = stack[-7];
    goto v_36303;
v_36304:
    goto v_36296;
v_36297:
    goto v_36298;
v_36299:
    goto v_36300;
v_36301:
    goto v_36302;
v_36303:
    fn = elt(env, 15); // cl_newv
    v_36545 = (*qfnn(fn))(fn, 4, v_36548, v_36547, v_36546, v_36545);
    env = stack[-10];
    stack[0] = v_36545;
    goto v_36317;
v_36313:
    v_36546 = stack[0];
    goto v_36314;
v_36315:
    v_36545 = stack[-6];
    goto v_36316;
v_36317:
    goto v_36313;
v_36314:
    goto v_36315;
v_36316:
    if (equal(v_36546, v_36545)) goto v_36312;
    goto v_36325;
v_36321:
    v_36546 = stack[0];
    goto v_36322;
v_36323:
    v_36545 = stack[-7];
    goto v_36324;
v_36325:
    goto v_36321;
v_36322:
    goto v_36323;
v_36324:
    v_36545 = cons(v_36546, v_36545);
    env = stack[-10];
    stack[-7] = v_36545;
    goto v_36335;
v_36329:
    v_36547 = stack[0];
    goto v_36330;
v_36331:
    v_36546 = stack[-6];
    goto v_36332;
v_36333:
    v_36545 = stack[-5];
    goto v_36334;
v_36335:
    goto v_36329;
v_36330:
    goto v_36331;
v_36332:
    goto v_36333;
v_36334:
    fn = elt(env, 16); // cl_subvarsubstat
    v_36545 = (*qfnn(fn))(fn, 3, v_36547, v_36546, v_36545);
    env = stack[-10];
    stack[-5] = v_36545;
    goto v_36310;
v_36312:
v_36310:
    goto v_36348;
v_36340:
    stack[-1] = stack[-9];
    goto v_36341;
v_36342:
    goto v_36343;
v_36344:
    goto v_36360;
v_36352:
    v_36548 = stack[-8];
    goto v_36353;
v_36354:
    v_36547 = stack[-5];
    goto v_36355;
v_36356:
    v_36546 = stack[-2];
    goto v_36357;
v_36358:
    v_36545 = stack[-7];
    goto v_36359;
v_36360:
    goto v_36352;
v_36353:
    goto v_36354;
v_36355:
    goto v_36356;
v_36357:
    goto v_36358;
v_36359:
    stack[-3] = CC_cl_subfof1(elt(env, 0), 4, v_36548, v_36547, v_36546, v_36545);
    env = stack[-10];
    goto v_36345;
v_36346:
    goto v_36374;
v_36366:
    v_36548 = stack[-8];
    goto v_36367;
v_36368:
    v_36547 = stack[-4];
    goto v_36369;
v_36370:
    v_36546 = stack[-2];
    goto v_36371;
v_36372:
    v_36545 = stack[-7];
    goto v_36373;
v_36374:
    goto v_36366;
v_36367:
    goto v_36368;
v_36369:
    goto v_36370;
v_36371:
    goto v_36372;
v_36373:
    v_36545 = CC_cl_subfof1(elt(env, 0), 4, v_36548, v_36547, v_36546, v_36545);
    goto v_36347;
v_36348:
    goto v_36340;
v_36341:
    goto v_36342;
v_36343:
    goto v_36344;
v_36345:
    goto v_36346;
v_36347:
    {
        LispObject v_36561 = stack[-1];
        LispObject v_36562 = stack[0];
        LispObject v_36563 = stack[-3];
        return list4(v_36561, v_36562, v_36563, v_36545);
    }
v_36112:
    goto v_36399;
v_36395:
    v_36546 = stack[-9];
    goto v_36396;
v_36397:
    v_36545 = elt(env, 8); // or
    goto v_36398;
v_36399:
    goto v_36395;
v_36396:
    goto v_36397;
v_36398:
    if (v_36546 == v_36545) goto v_36393;
    else goto v_36394;
v_36393:
    v_36545 = lisp_true;
    goto v_36392;
v_36394:
    goto v_36409;
v_36405:
    v_36546 = stack[-9];
    goto v_36406;
v_36407:
    v_36545 = elt(env, 9); // and
    goto v_36408;
v_36409:
    goto v_36405;
v_36406:
    goto v_36407;
v_36408:
    v_36545 = (v_36546 == v_36545 ? lisp_true : nil);
    goto v_36392;
    v_36545 = nil;
v_36392:
    if (v_36545 == nil) goto v_36390;
    v_36545 = lisp_true;
    goto v_36388;
v_36390:
    goto v_36420;
v_36416:
    v_36546 = stack[-9];
    goto v_36417;
v_36418:
    v_36545 = elt(env, 10); // not
    goto v_36419;
v_36420:
    goto v_36416;
v_36417:
    goto v_36418;
v_36419:
    v_36545 = (v_36546 == v_36545 ? lisp_true : nil);
    goto v_36388;
    v_36545 = nil;
v_36388:
    if (v_36545 == nil) goto v_36386;
    v_36545 = lisp_true;
    goto v_36384;
v_36386:
    goto v_36435;
v_36431:
    v_36546 = stack[-9];
    goto v_36432;
v_36433:
    v_36545 = elt(env, 11); // impl
    goto v_36434;
v_36435:
    goto v_36431;
v_36432:
    goto v_36433;
v_36434:
    if (v_36546 == v_36545) goto v_36429;
    else goto v_36430;
v_36429:
    v_36545 = lisp_true;
    goto v_36428;
v_36430:
    goto v_36449;
v_36445:
    v_36546 = stack[-9];
    goto v_36446;
v_36447:
    v_36545 = elt(env, 12); // repl
    goto v_36448;
v_36449:
    goto v_36445;
v_36446:
    goto v_36447;
v_36448:
    if (v_36546 == v_36545) goto v_36443;
    else goto v_36444;
v_36443:
    v_36545 = lisp_true;
    goto v_36442;
v_36444:
    goto v_36459;
v_36455:
    v_36546 = stack[-9];
    goto v_36456;
v_36457:
    v_36545 = elt(env, 13); // equiv
    goto v_36458;
v_36459:
    goto v_36455;
v_36456:
    goto v_36457;
v_36458:
    v_36545 = (v_36546 == v_36545 ? lisp_true : nil);
    goto v_36442;
    v_36545 = nil;
v_36442:
    goto v_36428;
    v_36545 = nil;
v_36428:
    goto v_36384;
    v_36545 = nil;
v_36384:
    if (v_36545 == nil) goto v_36382;
    goto v_36468;
v_36464:
    stack[-5] = stack[-9];
    goto v_36465;
v_36466:
    v_36545 = v_36547;
    v_36545 = qcdr(v_36545);
    stack[-4] = v_36545;
    v_36545 = stack[-4];
    if (v_36545 == nil) goto v_36480;
    else goto v_36481;
v_36480:
    v_36545 = nil;
    goto v_36474;
v_36481:
    v_36545 = stack[-4];
    v_36545 = qcar(v_36545);
    goto v_36497;
v_36489:
    v_36548 = stack[-8];
    goto v_36490;
v_36491:
    v_36547 = v_36545;
    goto v_36492;
v_36493:
    v_36546 = stack[-2];
    goto v_36494;
v_36495:
    v_36545 = stack[-7];
    goto v_36496;
v_36497:
    goto v_36489;
v_36490:
    goto v_36491;
v_36492:
    goto v_36493;
v_36494:
    goto v_36495;
v_36496:
    v_36545 = CC_cl_subfof1(elt(env, 0), 4, v_36548, v_36547, v_36546, v_36545);
    env = stack[-10];
    v_36545 = ncons(v_36545);
    env = stack[-10];
    stack[-1] = v_36545;
    stack[-3] = v_36545;
v_36475:
    v_36545 = stack[-4];
    v_36545 = qcdr(v_36545);
    stack[-4] = v_36545;
    v_36545 = stack[-4];
    if (v_36545 == nil) goto v_36506;
    else goto v_36507;
v_36506:
    v_36545 = stack[-3];
    goto v_36474;
v_36507:
    goto v_36515;
v_36511:
    stack[0] = stack[-1];
    goto v_36512;
v_36513:
    v_36545 = stack[-4];
    v_36545 = qcar(v_36545);
    goto v_36530;
v_36522:
    v_36548 = stack[-8];
    goto v_36523;
v_36524:
    v_36547 = v_36545;
    goto v_36525;
v_36526:
    v_36546 = stack[-2];
    goto v_36527;
v_36528:
    v_36545 = stack[-7];
    goto v_36529;
v_36530:
    goto v_36522;
v_36523:
    goto v_36524;
v_36525:
    goto v_36526;
v_36527:
    goto v_36528;
v_36529:
    v_36545 = CC_cl_subfof1(elt(env, 0), 4, v_36548, v_36547, v_36546, v_36545);
    env = stack[-10];
    v_36545 = ncons(v_36545);
    env = stack[-10];
    goto v_36514;
v_36515:
    goto v_36511;
v_36512:
    goto v_36513;
v_36514:
    v_36545 = Lrplacd(nil, stack[0], v_36545);
    env = stack[-10];
    v_36545 = stack[-1];
    v_36545 = qcdr(v_36545);
    stack[-1] = v_36545;
    goto v_36475;
v_36474:
    goto v_36467;
v_36468:
    goto v_36464;
v_36465:
    goto v_36466;
v_36467:
    {
        LispObject v_36564 = stack[-5];
        return cons(v_36564, v_36545);
    }
v_36382:
    goto v_36542;
v_36538:
    v_36545 = stack[-8];
    goto v_36539;
v_36540:
    v_36546 = v_36547;
    goto v_36541;
v_36542:
    goto v_36538;
v_36539:
    goto v_36540;
v_36541:
    {
        fn = elt(env, 17); // rl_subat
        return (*qfn2(fn))(fn, v_36545, v_36546);
    }
v_35821:
    return onevalue(v_36545);
}



// Code for ps!:find!-order

static LispObject CC_psTfindKorder(LispObject env,
                         LispObject v_35811)
{
    env = qenv(env);
    LispObject v_35905, v_35906, v_35907;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35811);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35811);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_35905 = v_35811;
// end of prologue
// Binding ps
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_35905; // ps
    v_35905 = qvalue(elt(env, 1)); // ps
    if (v_35905 == nil) goto v_35819;
    else goto v_35820;
v_35819:
    v_35905 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35818;
v_35820:
    v_35905 = qvalue(elt(env, 1)); // ps
    if (symbolp(v_35905)) goto v_35823;
    else goto v_35824;
v_35823:
    v_35905 = qvalue(elt(env, 1)); // ps
    goto v_35818;
v_35824:
    v_35905 = qvalue(elt(env, 1)); // ps
    v_35907 = v_35905;
    v_35905 = v_35907;
    v_35905 = (is_number(v_35905) ? lisp_true : nil);
    if (v_35905 == nil) goto v_35833;
    else goto v_35832;
v_35833:
    v_35905 = v_35907;
    v_35905 = Lconsp(nil, v_35905);
    env = stack[-1];
    if (v_35905 == nil) goto v_35838;
    else goto v_35839;
v_35838:
    v_35905 = nil;
    goto v_35837;
v_35839:
    goto v_35853;
v_35849:
    v_35905 = v_35907;
    v_35906 = qcar(v_35905);
    goto v_35850;
v_35851:
    v_35905 = elt(env, 2); // !:ps!:
    goto v_35852;
v_35853:
    goto v_35849;
v_35850:
    goto v_35851;
v_35852:
    if (v_35906 == v_35905) goto v_35848;
    v_35905 = v_35907;
    v_35905 = qcar(v_35905);
    if (!symbolp(v_35905)) v_35905 = nil;
    else { v_35905 = qfastgets(v_35905);
           if (v_35905 != nil) { v_35905 = elt(v_35905, 8); // dname
#ifdef RECORD_GET
             if (v_35905 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_35905 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_35905 == SPID_NOPROP) v_35905 = nil; }}
#endif
    goto v_35846;
v_35848:
    v_35905 = nil;
    goto v_35846;
    v_35905 = nil;
v_35846:
    goto v_35837;
    v_35905 = nil;
v_35837:
v_35832:
    if (v_35905 == nil) goto v_35828;
    v_35905 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35818;
v_35828:
    goto v_35871;
v_35867:
    v_35906 = qvalue(elt(env, 1)); // ps
    goto v_35868;
v_35869:
    v_35905 = elt(env, 2); // !:ps!:
    goto v_35870;
v_35871:
    goto v_35867;
v_35868:
    goto v_35869;
v_35870:
    if (!consp(v_35906)) goto v_35865;
    v_35906 = qcar(v_35906);
    if (v_35906 == v_35905) goto v_35864;
    else goto v_35865;
v_35864:
    v_35905 = qvalue(elt(env, 1)); // ps
    v_35905 = qcdr(v_35905);
    if (symbolp(v_35905)) goto v_35876;
    else goto v_35877;
v_35876:
    v_35905 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 5); // ps!:unknown!-order
    v_35905 = (*qfn1(fn))(fn, v_35905);
    goto v_35875;
v_35877:
    v_35905 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 6); // ps!:expression
    v_35905 = (*qfn1(fn))(fn, v_35905);
    env = stack[-1];
    if (!consp(v_35905)) goto v_35882;
    else goto v_35883;
v_35882:
    v_35905 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 7); // ps!:order
    v_35905 = (*qfn1(fn))(fn, v_35905);
    goto v_35875;
v_35883:
    v_35905 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 8); // ps!:find!-order1
    v_35905 = (*qfn1(fn))(fn, v_35905);
    goto v_35875;
    v_35905 = nil;
v_35875:
    goto v_35818;
v_35865:
    goto v_35901;
v_35895:
    v_35907 = elt(env, 3); // tps
    goto v_35896;
v_35897:
    v_35906 = (LispObject)336+TAG_FIXNUM; // 21
    goto v_35898;
v_35899:
    v_35905 = elt(env, 4); // "Unexpected form in ps!:find!-order"
    goto v_35900;
v_35901:
    goto v_35895;
v_35896:
    goto v_35897;
v_35898:
    goto v_35899;
v_35900:
    fn = elt(env, 9); // rerror
    v_35905 = (*qfnn(fn))(fn, 3, v_35907, v_35906, v_35905);
    goto v_35818;
    v_35905 = nil;
v_35818:
    ;}  // end of a binding scope
    return onevalue(v_35905);
}



// Code for vdpenumerate

static LispObject CC_vdpenumerate(LispObject env,
                         LispObject v_35810)
{
    env = qenv(env);
    LispObject v_35860, v_35861, v_35862;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35810);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_35810;
// end of prologue
    v_35860 = stack[0];
    if (v_35860 == nil) goto v_35818;
    else goto v_35819;
v_35818:
    v_35860 = lisp_true;
    goto v_35817;
v_35819:
    v_35860 = stack[0];
    v_35860 = qcdr(v_35860);
    v_35860 = qcdr(v_35860);
    v_35860 = qcdr(v_35860);
    v_35860 = qcar(v_35860);
    v_35860 = (v_35860 == nil ? lisp_true : nil);
    goto v_35817;
    v_35860 = nil;
v_35817:
    if (v_35860 == nil) goto v_35815;
    v_35860 = stack[0];
    goto v_35813;
v_35815:
    v_35860 = stack[0];
    fn = elt(env, 3); // vdpsave
    v_35860 = (*qfn1(fn))(fn, v_35860);
    env = stack[-1];
    stack[0] = v_35860;
    goto v_35844;
v_35840:
    v_35861 = stack[0];
    goto v_35841;
v_35842:
    v_35860 = elt(env, 1); // number
    goto v_35843;
v_35844:
    goto v_35840;
v_35841:
    goto v_35842;
v_35843:
    fn = elt(env, 4); // vdpgetprop
    v_35860 = (*qfn2(fn))(fn, v_35861, v_35860);
    env = stack[-1];
    if (v_35860 == nil) goto v_35837;
    else goto v_35838;
v_35837:
    goto v_35854;
v_35848:
    v_35862 = stack[0];
    goto v_35849;
v_35850:
    v_35861 = elt(env, 1); // number
    goto v_35851;
v_35852:
    v_35860 = qvalue(elt(env, 2)); // pcount!*
    v_35860 = (LispObject)((intptr_t)(v_35860) + 0x10);
    qvalue(elt(env, 2)) = v_35860; // pcount!*
    goto v_35853;
v_35854:
    goto v_35848;
v_35849:
    goto v_35850;
v_35851:
    goto v_35852;
v_35853:
    fn = elt(env, 5); // vdpputprop
    v_35860 = (*qfnn(fn))(fn, 3, v_35862, v_35861, v_35860);
    stack[0] = v_35860;
    goto v_35836;
v_35838:
v_35836:
    v_35860 = stack[0];
    goto v_35813;
    v_35860 = nil;
v_35813:
    return onevalue(v_35860);
}



// Code for xnormalise

static LispObject CC_xnormalise(LispObject env,
                         LispObject v_35810)
{
    env = qenv(env);
    LispObject v_35850, v_35851;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35810);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_35810;
// end of prologue
    v_35850 = stack[0];
    if (v_35850 == nil) goto v_35814;
    else goto v_35815;
v_35814:
    v_35850 = nil;
    goto v_35813;
v_35815:
    goto v_35824;
v_35820:
    v_35850 = stack[0];
    v_35850 = qcar(v_35850);
    stack[-1] = qcdr(v_35850);
    goto v_35821;
v_35822:
    goto v_35833;
v_35829:
    v_35851 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35830;
v_35831:
    v_35850 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35832;
v_35833:
    goto v_35829;
v_35830:
    goto v_35831;
v_35832:
    v_35850 = cons(v_35851, v_35850);
    env = stack[-2];
    goto v_35823;
v_35824:
    goto v_35820;
v_35821:
    goto v_35822;
v_35823:
    if (equal(stack[-1], v_35850)) goto v_35818;
    else goto v_35819;
v_35818:
    v_35850 = stack[0];
    goto v_35813;
v_35819:
    goto v_35844;
v_35840:
    stack[-1] = stack[0];
    goto v_35841;
v_35842:
    v_35850 = stack[0];
    v_35850 = qcar(v_35850);
    v_35850 = qcdr(v_35850);
    fn = elt(env, 1); // invsq
    v_35850 = (*qfn1(fn))(fn, v_35850);
    env = stack[-2];
    goto v_35843;
v_35844:
    goto v_35840;
v_35841:
    goto v_35842;
v_35843:
    {
        LispObject v_35854 = stack[-1];
        fn = elt(env, 2); // multpfsq
        return (*qfn2(fn))(fn, v_35854, v_35850);
    }
    v_35850 = nil;
v_35813:
    return onevalue(v_35850);
}



// Code for validrule

static LispObject CC_validrule(LispObject env,
                         LispObject v_35810)
{
    env = qenv(env);
    LispObject v_35825, v_35826;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35810);
    }
// copy arguments values to proper place
    v_35825 = v_35810;
// end of prologue
    fn = elt(env, 1); // validrule1
    v_35825 = (*qfn1(fn))(fn, v_35825);
    v_35826 = v_35825;
    v_35825 = v_35826;
    if (v_35825 == nil) goto v_35817;
    else goto v_35818;
v_35817:
    v_35825 = nil;
    goto v_35816;
v_35818:
    v_35825 = v_35826;
    return ncons(v_35825);
    v_35825 = nil;
v_35816:
    return onevalue(v_35825);
}



// Code for listofvarnames

static LispObject CC_listofvarnames(LispObject env,
                         LispObject v_35810)
{
    env = qenv(env);
    LispObject v_35966, v_35967;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35810);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_35810;
// end of prologue
    v_35966 = stack[0];
    fn = elt(env, 3); // listp
    v_35966 = (*qfn1(fn))(fn, v_35966);
    env = stack[-5];
    if (v_35966 == nil) goto v_35814;
    else goto v_35815;
v_35814:
    v_35966 = elt(env, 1); // "invalid argument to listofvarnames"
    {
        fn = elt(env, 4); // rederr
        return (*qfn1(fn))(fn, v_35966);
    }
v_35815:
    v_35966 = stack[0];
    stack[-4] = v_35966;
    v_35966 = stack[-4];
    if (v_35966 == nil) goto v_35831;
    else goto v_35832;
v_35831:
    v_35966 = nil;
    goto v_35826;
v_35832:
    v_35966 = stack[-4];
    v_35966 = qcar(v_35966);
    stack[0] = v_35966;
    v_35966 = stack[0];
    fn = elt(env, 5); // domain!*p
    v_35966 = (*qfn1(fn))(fn, v_35966);
    env = stack[-5];
    if (v_35966 == nil) goto v_35842;
    goto v_35850;
v_35846:
    v_35967 = nil;
    goto v_35847;
v_35848:
    v_35966 = elt(env, 2); // free
    goto v_35849;
v_35850:
    goto v_35846;
v_35847:
    goto v_35848;
v_35849:
    v_35966 = cons(v_35967, v_35966);
    env = stack[-5];
    goto v_35840;
v_35842:
    v_35966 = stack[0];
    if (!consp(v_35966)) goto v_35853;
    else goto v_35854;
v_35853:
    goto v_35861;
v_35857:
    v_35967 = nil;
    goto v_35858;
v_35859:
    v_35966 = elt(env, 2); // free
    goto v_35860;
v_35861:
    goto v_35857;
v_35858:
    goto v_35859;
v_35860:
    v_35966 = cons(v_35967, v_35966);
    env = stack[-5];
    goto v_35840;
v_35854:
    v_35966 = stack[0];
    v_35966 = qcar(v_35966);
    if (symbolp(v_35966)) goto v_35864;
    else goto v_35865;
v_35864:
    goto v_35873;
v_35869:
    v_35966 = stack[0];
    v_35967 = qcar(v_35966);
    goto v_35870;
v_35871:
    v_35966 = elt(env, 2); // free
    goto v_35872;
v_35873:
    goto v_35869;
v_35870:
    goto v_35871;
v_35872:
    v_35966 = cons(v_35967, v_35966);
    env = stack[-5];
    goto v_35840;
v_35865:
    v_35966 = stack[0];
    v_35966 = qcar(v_35966);
    v_35966 = qcar(v_35966);
    if (symbolp(v_35966)) goto v_35877;
    else goto v_35878;
v_35877:
    goto v_35887;
v_35883:
    v_35966 = stack[0];
    v_35966 = qcar(v_35966);
    v_35967 = qcar(v_35966);
    goto v_35884;
v_35885:
    v_35966 = elt(env, 2); // free
    goto v_35886;
v_35887:
    goto v_35883;
v_35884:
    goto v_35885;
v_35886:
    v_35966 = cons(v_35967, v_35966);
    env = stack[-5];
    goto v_35840;
v_35878:
    v_35966 = nil;
v_35840:
    v_35966 = ncons(v_35966);
    env = stack[-5];
    stack[-2] = v_35966;
    stack[-3] = v_35966;
v_35827:
    v_35966 = stack[-4];
    v_35966 = qcdr(v_35966);
    stack[-4] = v_35966;
    v_35966 = stack[-4];
    if (v_35966 == nil) goto v_35896;
    else goto v_35897;
v_35896:
    v_35966 = stack[-3];
    goto v_35826;
v_35897:
    goto v_35905;
v_35901:
    stack[-1] = stack[-2];
    goto v_35902;
v_35903:
    v_35966 = stack[-4];
    v_35966 = qcar(v_35966);
    stack[0] = v_35966;
    v_35966 = stack[0];
    fn = elt(env, 5); // domain!*p
    v_35966 = (*qfn1(fn))(fn, v_35966);
    env = stack[-5];
    if (v_35966 == nil) goto v_35914;
    goto v_35922;
v_35918:
    v_35967 = nil;
    goto v_35919;
v_35920:
    v_35966 = elt(env, 2); // free
    goto v_35921;
v_35922:
    goto v_35918;
v_35919:
    goto v_35920;
v_35921:
    v_35966 = cons(v_35967, v_35966);
    env = stack[-5];
    goto v_35912;
v_35914:
    v_35966 = stack[0];
    if (!consp(v_35966)) goto v_35925;
    else goto v_35926;
v_35925:
    goto v_35933;
v_35929:
    v_35967 = nil;
    goto v_35930;
v_35931:
    v_35966 = elt(env, 2); // free
    goto v_35932;
v_35933:
    goto v_35929;
v_35930:
    goto v_35931;
v_35932:
    v_35966 = cons(v_35967, v_35966);
    env = stack[-5];
    goto v_35912;
v_35926:
    v_35966 = stack[0];
    v_35966 = qcar(v_35966);
    if (symbolp(v_35966)) goto v_35936;
    else goto v_35937;
v_35936:
    goto v_35945;
v_35941:
    v_35966 = stack[0];
    v_35967 = qcar(v_35966);
    goto v_35942;
v_35943:
    v_35966 = elt(env, 2); // free
    goto v_35944;
v_35945:
    goto v_35941;
v_35942:
    goto v_35943;
v_35944:
    v_35966 = cons(v_35967, v_35966);
    env = stack[-5];
    goto v_35912;
v_35937:
    v_35966 = stack[0];
    v_35966 = qcar(v_35966);
    v_35966 = qcar(v_35966);
    if (symbolp(v_35966)) goto v_35949;
    else goto v_35950;
v_35949:
    goto v_35959;
v_35955:
    v_35966 = stack[0];
    v_35966 = qcar(v_35966);
    v_35967 = qcar(v_35966);
    goto v_35956;
v_35957:
    v_35966 = elt(env, 2); // free
    goto v_35958;
v_35959:
    goto v_35955;
v_35956:
    goto v_35957;
v_35958:
    v_35966 = cons(v_35967, v_35966);
    env = stack[-5];
    goto v_35912;
v_35950:
    v_35966 = nil;
v_35912:
    v_35966 = ncons(v_35966);
    env = stack[-5];
    goto v_35904;
v_35905:
    goto v_35901;
v_35902:
    goto v_35903;
v_35904:
    v_35966 = Lrplacd(nil, stack[-1], v_35966);
    env = stack[-5];
    v_35966 = stack[-2];
    v_35966 = qcdr(v_35966);
    stack[-2] = v_35966;
    goto v_35827;
v_35826:
    goto v_35813;
    v_35966 = nil;
v_35813:
    return onevalue(v_35966);
}



// Code for calc_map_2d

static LispObject CC_calc_map_2d(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_35860, v_35861;
    LispObject fn;
    LispObject v_35813, v_35812, v_35811, v_35810;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "calc_map_2d");
    va_start(aa, nargs);
    v_35810 = va_arg(aa, LispObject);
    v_35811 = va_arg(aa, LispObject);
    v_35812 = va_arg(aa, LispObject);
    v_35813 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_35813,v_35812,v_35811,v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_35810,v_35811,v_35812,v_35813);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_35813;
    stack[-2] = v_35812;
    stack[-3] = v_35811;
    stack[-4] = v_35810;
// end of prologue
    goto v_35822;
v_35816:
    goto v_35830;
v_35824:
    v_35860 = stack[-4];
    v_35860 = qcar(v_35860);
    v_35860 = qcar(v_35860);
    fn = elt(env, 1); // mk_names_map_2
    stack[-5] = (*qfn1(fn))(fn, v_35860);
    env = stack[-6];
    goto v_35825;
v_35826:
    v_35860 = stack[-4];
    v_35860 = qcar(v_35860);
    stack[0] = qcdr(v_35860);
    goto v_35827;
v_35828:
    goto v_35843;
v_35839:
    v_35860 = stack[-4];
    v_35860 = qcdr(v_35860);
    v_35861 = qcar(v_35860);
    goto v_35840;
v_35841:
    v_35860 = stack[-3];
    goto v_35842;
v_35843:
    goto v_35839;
v_35840:
    goto v_35841;
v_35842:
    v_35860 = cons(v_35861, v_35860);
    env = stack[-6];
    goto v_35829;
v_35830:
    goto v_35824;
v_35825:
    goto v_35826;
v_35827:
    goto v_35828;
v_35829:
    stack[0] = list2star(stack[-5], stack[0], v_35860);
    env = stack[-6];
    goto v_35817;
v_35818:
    goto v_35819;
v_35820:
    goto v_35854;
v_35850:
    v_35860 = stack[-4];
    v_35860 = qcdr(v_35860);
    v_35860 = qcdr(v_35860);
    v_35861 = qcar(v_35860);
    goto v_35851;
v_35852:
    v_35860 = stack[-1];
    goto v_35853;
v_35854:
    goto v_35850;
v_35851:
    goto v_35852;
v_35853:
    fn = elt(env, 2); // mk_binding
    v_35860 = (*qfn2(fn))(fn, v_35861, v_35860);
    env = stack[-6];
    goto v_35821;
v_35822:
    goto v_35816;
v_35817:
    goto v_35818;
v_35819:
    goto v_35820;
v_35821:
    {
        LispObject v_35868 = stack[0];
        LispObject v_35869 = stack[-2];
        fn = elt(env, 3); // coeff_calc
        return (*qfnn(fn))(fn, 3, v_35868, v_35869, v_35860);
    }
}



// Code for !*sf2exb

static LispObject CC_Hsf2exb(LispObject env,
                         LispObject v_35810, LispObject v_35811)
{
    env = qenv(env);
    LispObject v_35882, v_35883, v_35884;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_35811,v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_35810,v_35811);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_35811;
    stack[-1] = v_35810;
// end of prologue
    stack[-2] = nil;
v_35816:
    goto v_35825;
v_35821:
    goto v_35831;
v_35827:
    v_35883 = stack[-1];
    goto v_35828;
v_35829:
    v_35882 = stack[0];
    goto v_35830;
v_35831:
    goto v_35827;
v_35828:
    goto v_35829;
v_35830:
    fn = elt(env, 1); // degr
    v_35883 = (*qfn2(fn))(fn, v_35883, v_35882);
    env = stack[-3];
    goto v_35822;
v_35823:
    v_35882 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35824;
v_35825:
    goto v_35821;
v_35822:
    goto v_35823;
v_35824:
    if (v_35883 == v_35882) goto v_35819;
    else goto v_35820;
v_35819:
    v_35882 = stack[-1];
    if (v_35882 == nil) goto v_35837;
    else goto v_35838;
v_35837:
    v_35882 = stack[-2];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_35882);
    }
v_35838:
    goto v_35849;
v_35845:
    stack[0] = stack[-2];
    goto v_35846;
v_35847:
    goto v_35857;
v_35853:
    v_35882 = (LispObject)0+TAG_FIXNUM; // 0
    v_35883 = ncons(v_35882);
    env = stack[-3];
    goto v_35854;
v_35855:
    v_35882 = stack[-1];
    goto v_35856;
v_35857:
    goto v_35853;
v_35854:
    goto v_35855;
v_35856:
    v_35882 = cons(v_35883, v_35882);
    env = stack[-3];
    v_35882 = ncons(v_35882);
    env = stack[-3];
    goto v_35848;
v_35849:
    goto v_35845;
v_35846:
    goto v_35847;
v_35848:
    {
        LispObject v_35888 = stack[0];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_35888, v_35882);
    }
    goto v_35818;
v_35820:
    goto v_35870;
v_35864:
    v_35882 = stack[-1];
    v_35882 = qcar(v_35882);
    v_35882 = qcar(v_35882);
    v_35882 = qcdr(v_35882);
    v_35884 = ncons(v_35882);
    env = stack[-3];
    goto v_35865;
v_35866:
    v_35882 = stack[-1];
    v_35882 = qcar(v_35882);
    v_35883 = qcdr(v_35882);
    goto v_35867;
v_35868:
    v_35882 = stack[-2];
    goto v_35869;
v_35870:
    goto v_35864;
v_35865:
    goto v_35866;
v_35867:
    goto v_35868;
v_35869:
    v_35882 = acons(v_35884, v_35883, v_35882);
    env = stack[-3];
    stack[-2] = v_35882;
    v_35882 = stack[-1];
    v_35882 = qcdr(v_35882);
    stack[-1] = v_35882;
    goto v_35816;
v_35818:
    v_35882 = nil;
    return onevalue(v_35882);
}



// Code for x!*!*p!-w

static LispObject CC_xHHpKw(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_35837, v_35838;
    LispObject fn;
    LispObject v_35812, v_35811, v_35810;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "x**p-w");
    va_start(aa, nargs);
    v_35810 = va_arg(aa, LispObject);
    v_35811 = va_arg(aa, LispObject);
    v_35812 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_35812,v_35811,v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_35810,v_35811,v_35812);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_35812;
    v_35837 = v_35811;
    v_35838 = v_35810;
// end of prologue
    goto v_35819;
v_35815:
    goto v_35826;
v_35822:
    goto v_35832;
v_35828:
    goto v_35829;
v_35830:
    goto v_35831;
v_35832:
    goto v_35828;
v_35829:
    goto v_35830;
v_35831:
    fn = elt(env, 1); // to
    v_35838 = (*qfn2(fn))(fn, v_35838, v_35837);
    env = stack[-1];
    goto v_35823;
v_35824:
    v_35837 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35825;
v_35826:
    goto v_35822;
v_35823:
    goto v_35824;
v_35825:
    v_35837 = cons(v_35838, v_35837);
    env = stack[-1];
    v_35838 = ncons(v_35837);
    env = stack[-1];
    goto v_35816;
v_35817:
    v_35837 = stack[0];
    goto v_35818;
v_35819:
    goto v_35815;
v_35816:
    goto v_35817;
v_35818:
    {
        fn = elt(env, 2); // general!-difference!-mod!-p
        return (*qfn2(fn))(fn, v_35838, v_35837);
    }
}



// Code for ofsf_ordrelp

static LispObject CC_ofsf_ordrelp(LispObject env,
                         LispObject v_35810, LispObject v_35811)
{
    env = qenv(env);
    LispObject v_35829, v_35830, v_35831;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_35830 = v_35811;
    v_35829 = v_35810;
// end of prologue
    goto v_35817;
v_35813:
    goto v_35814;
v_35815:
    goto v_35823;
v_35819:
    goto v_35820;
v_35821:
    v_35831 = elt(env, 1); // (equal neq leq lessp geq greaterp)
    goto v_35822;
v_35823:
    goto v_35819;
v_35820:
    goto v_35821;
v_35822:
    v_35829 = Lmemq(nil, v_35829, v_35831);
    v_35829 = qcdr(v_35829);
    goto v_35816;
v_35817:
    goto v_35813;
v_35814:
    goto v_35815;
v_35816:
    v_35829 = Lmemq(nil, v_35830, v_35829);
    return onevalue(v_35829);
}



// Code for makecoeffpairs1

static LispObject CC_makecoeffpairs1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_36086, v_36087, v_36088, v_36089;
    LispObject fn;
    LispObject v_35813, v_35812, v_35811, v_35810;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "makecoeffpairs1");
    va_start(aa, nargs);
    v_35810 = va_arg(aa, LispObject);
    v_35811 = va_arg(aa, LispObject);
    v_35812 = va_arg(aa, LispObject);
    v_35813 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_35813,v_35812,v_35811,v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_35810,v_35811,v_35812,v_35813);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(16);
// copy arguments values to proper place
    stack[-10] = v_35813;
    stack[-11] = v_35812;
    stack[-12] = v_35811;
    stack[-13] = v_35810;
// end of prologue
    v_36086 = stack[-12];
    if (v_36086 == nil) goto v_35817;
    else goto v_35818;
v_35817:
    v_36086 = elt(env, 1); // ((nil))
    goto v_35816;
v_35818:
    goto v_35839;
v_35831:
    v_36086 = stack[-13];
    v_36089 = qcdr(v_36086);
    goto v_35832;
v_35833:
    v_36086 = stack[-12];
    v_36088 = qcdr(v_36086);
    goto v_35834;
v_35835:
    v_36086 = stack[-11];
    v_36087 = qcdr(v_36086);
    goto v_35836;
v_35837:
    v_36086 = stack[-10];
    v_36086 = qcdr(v_36086);
    goto v_35838;
v_35839:
    goto v_35831;
v_35832:
    goto v_35833;
v_35834:
    goto v_35835;
v_35836:
    goto v_35837;
v_35838:
    v_36086 = CC_makecoeffpairs1(elt(env, 0), 4, v_36089, v_36088, v_36087, v_36086);
    env = stack[-15];
    stack[-14] = v_36086;
v_35828:
    v_36086 = stack[-14];
    if (v_36086 == nil) goto v_35850;
    else goto v_35851;
v_35850:
    v_36086 = nil;
    goto v_35827;
v_35851:
    v_36086 = stack[-14];
    v_36086 = qcar(v_36086);
    stack[-6] = v_36086;
    goto v_35872;
v_35864:
    v_36086 = stack[-13];
    stack[-2] = qcar(v_36086);
    goto v_35865;
v_35866:
    v_36086 = stack[-12];
    stack[-1] = qcar(v_36086);
    goto v_35867;
v_35868:
    v_36086 = stack[-11];
    stack[0] = qcar(v_36086);
    goto v_35869;
v_35870:
    v_36086 = stack[-10];
    v_36086 = qcar(v_36086);
    fn = elt(env, 2); // tayexp!-minus
    v_36086 = (*qfn1(fn))(fn, v_36086);
    env = stack[-15];
    goto v_35871;
v_35872:
    goto v_35864;
v_35865:
    goto v_35866;
v_35867:
    goto v_35868;
v_35869:
    goto v_35870;
v_35871:
    fn = elt(env, 3); // makecoeffpairshom
    v_36086 = (*qfnn(fn))(fn, 4, stack[-2], stack[-1], stack[0], v_36086);
    env = stack[-15];
    stack[-5] = v_36086;
    v_36086 = stack[-5];
    if (v_36086 == nil) goto v_35884;
    else goto v_35885;
v_35884:
    v_36086 = nil;
    goto v_35861;
v_35885:
    v_36086 = stack[-5];
    v_36086 = qcar(v_36086);
    v_36087 = v_36086;
    goto v_35899;
v_35893:
    v_36086 = v_36087;
    stack[-1] = qcar(v_36086);
    goto v_35894;
v_35895:
    v_36086 = stack[-6];
    stack[0] = qcar(v_36086);
    goto v_35896;
v_35897:
    goto v_35909;
v_35905:
    v_36086 = v_36087;
    v_36087 = qcdr(v_36086);
    goto v_35906;
v_35907:
    v_36086 = stack[-6];
    v_36086 = qcdr(v_36086);
    goto v_35908;
v_35909:
    goto v_35905;
v_35906:
    goto v_35907;
v_35908:
    v_36086 = cons(v_36087, v_36086);
    env = stack[-15];
    goto v_35898;
v_35899:
    goto v_35893;
v_35894:
    goto v_35895;
v_35896:
    goto v_35897;
v_35898:
    v_36086 = acons(stack[-1], stack[0], v_36086);
    env = stack[-15];
    v_36086 = ncons(v_36086);
    env = stack[-15];
    stack[-3] = v_36086;
    stack[-4] = v_36086;
v_35862:
    v_36086 = stack[-5];
    v_36086 = qcdr(v_36086);
    stack[-5] = v_36086;
    v_36086 = stack[-5];
    if (v_36086 == nil) goto v_35918;
    else goto v_35919;
v_35918:
    v_36086 = stack[-4];
    goto v_35861;
v_35919:
    goto v_35927;
v_35923:
    stack[-2] = stack[-3];
    goto v_35924;
v_35925:
    v_36086 = stack[-5];
    v_36086 = qcar(v_36086);
    v_36087 = v_36086;
    goto v_35940;
v_35934:
    v_36086 = v_36087;
    stack[-1] = qcar(v_36086);
    goto v_35935;
v_35936:
    v_36086 = stack[-6];
    stack[0] = qcar(v_36086);
    goto v_35937;
v_35938:
    goto v_35950;
v_35946:
    v_36086 = v_36087;
    v_36087 = qcdr(v_36086);
    goto v_35947;
v_35948:
    v_36086 = stack[-6];
    v_36086 = qcdr(v_36086);
    goto v_35949;
v_35950:
    goto v_35946;
v_35947:
    goto v_35948;
v_35949:
    v_36086 = cons(v_36087, v_36086);
    env = stack[-15];
    goto v_35939;
v_35940:
    goto v_35934;
v_35935:
    goto v_35936;
v_35937:
    goto v_35938;
v_35939:
    v_36086 = acons(stack[-1], stack[0], v_36086);
    env = stack[-15];
    v_36086 = ncons(v_36086);
    env = stack[-15];
    goto v_35926;
v_35927:
    goto v_35923;
v_35924:
    goto v_35925;
v_35926:
    v_36086 = Lrplacd(nil, stack[-2], v_36086);
    env = stack[-15];
    v_36086 = stack[-3];
    v_36086 = qcdr(v_36086);
    stack[-3] = v_36086;
    goto v_35862;
v_35861:
    stack[-9] = v_36086;
    v_36086 = stack[-9];
    fn = elt(env, 4); // lastpair
    v_36086 = (*qfn1(fn))(fn, v_36086);
    env = stack[-15];
    stack[-8] = v_36086;
    v_36086 = stack[-14];
    v_36086 = qcdr(v_36086);
    stack[-14] = v_36086;
    v_36086 = stack[-8];
    if (!consp(v_36086)) goto v_35963;
    else goto v_35964;
v_35963:
    goto v_35828;
v_35964:
v_35829:
    v_36086 = stack[-14];
    if (v_36086 == nil) goto v_35968;
    else goto v_35969;
v_35968:
    v_36086 = stack[-9];
    goto v_35827;
v_35969:
    goto v_35977;
v_35973:
    stack[-7] = stack[-8];
    goto v_35974;
v_35975:
    v_36086 = stack[-14];
    v_36086 = qcar(v_36086);
    stack[-6] = v_36086;
    goto v_35997;
v_35989:
    v_36086 = stack[-13];
    stack[-2] = qcar(v_36086);
    goto v_35990;
v_35991:
    v_36086 = stack[-12];
    stack[-1] = qcar(v_36086);
    goto v_35992;
v_35993:
    v_36086 = stack[-11];
    stack[0] = qcar(v_36086);
    goto v_35994;
v_35995:
    v_36086 = stack[-10];
    v_36086 = qcar(v_36086);
    fn = elt(env, 2); // tayexp!-minus
    v_36086 = (*qfn1(fn))(fn, v_36086);
    env = stack[-15];
    goto v_35996;
v_35997:
    goto v_35989;
v_35990:
    goto v_35991;
v_35992:
    goto v_35993;
v_35994:
    goto v_35995;
v_35996:
    fn = elt(env, 3); // makecoeffpairshom
    v_36086 = (*qfnn(fn))(fn, 4, stack[-2], stack[-1], stack[0], v_36086);
    env = stack[-15];
    stack[-5] = v_36086;
    v_36086 = stack[-5];
    if (v_36086 == nil) goto v_36009;
    else goto v_36010;
v_36009:
    v_36086 = nil;
    goto v_35986;
v_36010:
    v_36086 = stack[-5];
    v_36086 = qcar(v_36086);
    v_36087 = v_36086;
    goto v_36024;
v_36018:
    v_36086 = v_36087;
    stack[-1] = qcar(v_36086);
    goto v_36019;
v_36020:
    v_36086 = stack[-6];
    stack[0] = qcar(v_36086);
    goto v_36021;
v_36022:
    goto v_36034;
v_36030:
    v_36086 = v_36087;
    v_36087 = qcdr(v_36086);
    goto v_36031;
v_36032:
    v_36086 = stack[-6];
    v_36086 = qcdr(v_36086);
    goto v_36033;
v_36034:
    goto v_36030;
v_36031:
    goto v_36032;
v_36033:
    v_36086 = cons(v_36087, v_36086);
    env = stack[-15];
    goto v_36023;
v_36024:
    goto v_36018;
v_36019:
    goto v_36020;
v_36021:
    goto v_36022;
v_36023:
    v_36086 = acons(stack[-1], stack[0], v_36086);
    env = stack[-15];
    v_36086 = ncons(v_36086);
    env = stack[-15];
    stack[-3] = v_36086;
    stack[-4] = v_36086;
v_35987:
    v_36086 = stack[-5];
    v_36086 = qcdr(v_36086);
    stack[-5] = v_36086;
    v_36086 = stack[-5];
    if (v_36086 == nil) goto v_36043;
    else goto v_36044;
v_36043:
    v_36086 = stack[-4];
    goto v_35986;
v_36044:
    goto v_36052;
v_36048:
    stack[-2] = stack[-3];
    goto v_36049;
v_36050:
    v_36086 = stack[-5];
    v_36086 = qcar(v_36086);
    v_36087 = v_36086;
    goto v_36065;
v_36059:
    v_36086 = v_36087;
    stack[-1] = qcar(v_36086);
    goto v_36060;
v_36061:
    v_36086 = stack[-6];
    stack[0] = qcar(v_36086);
    goto v_36062;
v_36063:
    goto v_36075;
v_36071:
    v_36086 = v_36087;
    v_36087 = qcdr(v_36086);
    goto v_36072;
v_36073:
    v_36086 = stack[-6];
    v_36086 = qcdr(v_36086);
    goto v_36074;
v_36075:
    goto v_36071;
v_36072:
    goto v_36073;
v_36074:
    v_36086 = cons(v_36087, v_36086);
    env = stack[-15];
    goto v_36064;
v_36065:
    goto v_36059;
v_36060:
    goto v_36061;
v_36062:
    goto v_36063;
v_36064:
    v_36086 = acons(stack[-1], stack[0], v_36086);
    env = stack[-15];
    v_36086 = ncons(v_36086);
    env = stack[-15];
    goto v_36051;
v_36052:
    goto v_36048;
v_36049:
    goto v_36050;
v_36051:
    v_36086 = Lrplacd(nil, stack[-2], v_36086);
    env = stack[-15];
    v_36086 = stack[-3];
    v_36086 = qcdr(v_36086);
    stack[-3] = v_36086;
    goto v_35987;
v_35986:
    goto v_35976;
v_35977:
    goto v_35973;
v_35974:
    goto v_35975;
v_35976:
    v_36086 = Lrplacd(nil, stack[-7], v_36086);
    env = stack[-15];
    v_36086 = stack[-8];
    fn = elt(env, 4); // lastpair
    v_36086 = (*qfn1(fn))(fn, v_36086);
    env = stack[-15];
    stack[-8] = v_36086;
    v_36086 = stack[-14];
    v_36086 = qcdr(v_36086);
    stack[-14] = v_36086;
    goto v_35829;
v_35827:
    goto v_35816;
    v_36086 = nil;
v_35816:
    return onevalue(v_36086);
}



// Code for null!+vec!+p

static LispObject CC_nullLvecLp(LispObject env,
                         LispObject v_35810)
{
    env = qenv(env);
    LispObject v_35823;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35810);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_35823 = v_35810;
// end of prologue
    fn = elt(env, 1); // mk!+squared!+norm
    v_35823 = (*qfn1(fn))(fn, v_35823);
    env = stack[0];
    fn = elt(env, 2); // my!+nullsq!+p
    v_35823 = (*qfn1(fn))(fn, v_35823);
    if (v_35823 == nil) goto v_35818;
    v_35823 = lisp_true;
    goto v_35813;
v_35818:
    v_35823 = nil;
v_35813:
    return onevalue(v_35823);
}



// Code for talp_get!-minfct

static LispObject CC_talp_getKminfct(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_35925, v_35926, v_35927;
    LispObject fn;
    LispObject v_35813, v_35812, v_35811, v_35810;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "talp_get-minfct");
    va_start(aa, nargs);
    v_35810 = va_arg(aa, LispObject);
    v_35811 = va_arg(aa, LispObject);
    v_35812 = va_arg(aa, LispObject);
    v_35813 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_35813,v_35812,v_35811,v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_35810,v_35811,v_35812,v_35813);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_35813;
    stack[0] = v_35812;
    v_35926 = v_35811;
    v_35925 = v_35810;
// end of prologue
    goto v_35819;
v_35815:
    goto v_35816;
v_35817:
    goto v_35818;
v_35819:
    goto v_35815;
v_35816:
    goto v_35817;
v_35818:
    v_35925 = *(LispObject *)((char *)v_35926 + (CELL-TAG_VECTOR) + (((intptr_t)v_35925-TAG_FIXNUM)/(16/CELL)));
    stack[-6] = v_35925;
    v_35925 = stack[-6];
    fn = elt(env, 1); // talp_invp
    v_35925 = (*qfn1(fn))(fn, v_35925);
    env = stack[-7];
    if (v_35925 == nil) goto v_35827;
    goto v_35837;
v_35831:
    v_35925 = stack[-6];
    fn = elt(env, 2); // talp_fop
    v_35927 = (*qfn1(fn))(fn, v_35925);
    goto v_35832;
v_35833:
    goto v_35844;
v_35840:
    v_35926 = stack[0];
    goto v_35841;
v_35842:
    v_35925 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35843;
v_35844:
    goto v_35840;
v_35841:
    goto v_35842;
v_35843:
    v_35926 = *(LispObject *)((char *)v_35926 + (CELL-TAG_VECTOR) + (((intptr_t)v_35925-TAG_FIXNUM)/(16/CELL)));
    goto v_35834;
v_35835:
    v_35925 = nil;
    goto v_35836;
v_35837:
    goto v_35831;
v_35832:
    goto v_35833;
v_35834:
    goto v_35835;
v_35836:
    return list2star(v_35927, v_35926, v_35925);
v_35827:
    goto v_35856;
v_35852:
    v_35925 = stack[-6];
    fn = elt(env, 2); // talp_fop
    stack[-4] = (*qfn1(fn))(fn, v_35925);
    env = stack[-7];
    goto v_35853;
v_35854:
    v_35925 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_35925;
    goto v_35876;
v_35872:
    v_35925 = stack[-6];
    v_35926 = qcdr(v_35925);
    goto v_35873;
v_35874:
    v_35925 = stack[-3];
    goto v_35875;
v_35876:
    goto v_35872;
v_35873:
    goto v_35874;
v_35875:
    v_35925 = difference2(v_35926, v_35925);
    env = stack[-7];
    v_35925 = Lminusp(nil, v_35925);
    env = stack[-7];
    if (v_35925 == nil) goto v_35869;
    v_35925 = nil;
    goto v_35863;
v_35869:
    goto v_35886;
v_35882:
    v_35926 = stack[-5];
    goto v_35883;
v_35884:
    v_35925 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35885;
v_35886:
    goto v_35882;
v_35883:
    goto v_35884;
v_35885:
    v_35925 = *(LispObject *)((char *)v_35926 + (CELL-TAG_VECTOR) + (((intptr_t)v_35925-TAG_FIXNUM)/(16/CELL)));
    v_35925 = ncons(v_35925);
    env = stack[-7];
    stack[-1] = v_35925;
    stack[-2] = v_35925;
v_35864:
    v_35925 = stack[-3];
    v_35925 = add1(v_35925);
    env = stack[-7];
    stack[-3] = v_35925;
    goto v_35902;
v_35898:
    v_35925 = stack[-6];
    v_35926 = qcdr(v_35925);
    goto v_35899;
v_35900:
    v_35925 = stack[-3];
    goto v_35901;
v_35902:
    goto v_35898;
v_35899:
    goto v_35900;
v_35901:
    v_35925 = difference2(v_35926, v_35925);
    env = stack[-7];
    v_35925 = Lminusp(nil, v_35925);
    env = stack[-7];
    if (v_35925 == nil) goto v_35895;
    v_35925 = stack[-2];
    goto v_35863;
v_35895:
    goto v_35912;
v_35908:
    stack[0] = stack[-1];
    goto v_35909;
v_35910:
    goto v_35919;
v_35915:
    v_35926 = stack[-5];
    goto v_35916;
v_35917:
    v_35925 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35918;
v_35919:
    goto v_35915;
v_35916:
    goto v_35917;
v_35918:
    v_35925 = *(LispObject *)((char *)v_35926 + (CELL-TAG_VECTOR) + (((intptr_t)v_35925-TAG_FIXNUM)/(16/CELL)));
    v_35925 = ncons(v_35925);
    env = stack[-7];
    goto v_35911;
v_35912:
    goto v_35908;
v_35909:
    goto v_35910;
v_35911:
    v_35925 = Lrplacd(nil, stack[0], v_35925);
    env = stack[-7];
    v_35925 = stack[-1];
    v_35925 = qcdr(v_35925);
    stack[-1] = v_35925;
    goto v_35864;
v_35863:
    goto v_35855;
v_35856:
    goto v_35852;
v_35853:
    goto v_35854;
v_35855:
    {
        LispObject v_35935 = stack[-4];
        fn = elt(env, 3); // talp_mktn
        return (*qfn2(fn))(fn, v_35935, v_35925);
    }
    v_35925 = nil;
    return onevalue(v_35925);
}



// Code for xpwrlcmp

static LispObject CC_xpwrlcmp(LispObject env,
                         LispObject v_35810, LispObject v_35811)
{
    env = qenv(env);
    LispObject v_35897, v_35898;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_35811,v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_35810,v_35811);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_35811;
    stack[-1] = v_35810;
// end of prologue
    v_35897 = stack[-1];
    if (!consp(v_35897)) goto v_35815;
    else goto v_35816;
v_35815:
    v_35897 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35814;
v_35816:
    goto v_35830;
v_35826:
    v_35898 = stack[-1];
    goto v_35827;
v_35828:
    v_35897 = elt(env, 1); // expt
    goto v_35829;
v_35830:
    goto v_35826;
v_35827:
    goto v_35828;
v_35829:
    if (!consp(v_35898)) goto v_35824;
    v_35898 = qcar(v_35898);
    if (v_35898 == v_35897) goto v_35823;
    else goto v_35824;
v_35823:
    goto v_35837;
v_35833:
    v_35897 = stack[-1];
    v_35897 = qcdr(v_35897);
    v_35898 = qcar(v_35897);
    goto v_35834;
v_35835:
    v_35897 = stack[0];
    goto v_35836;
v_35837:
    goto v_35833;
v_35834:
    goto v_35835;
v_35836:
    v_35897 = (equal(v_35898, v_35897) ? lisp_true : nil);
    goto v_35822;
v_35824:
    v_35897 = nil;
    goto v_35822;
    v_35897 = nil;
v_35822:
    if (v_35897 == nil) goto v_35820;
    v_35897 = stack[-1];
    v_35897 = qcdr(v_35897);
    v_35897 = qcdr(v_35897);
    v_35897 = qcar(v_35897);
    {
        fn = elt(env, 3); // getdenom
        return (*qfn1(fn))(fn, v_35897);
    }
v_35820:
    goto v_35858;
v_35854:
    v_35898 = stack[-1];
    goto v_35855;
v_35856:
    v_35897 = elt(env, 2); // sqrt
    goto v_35857;
v_35858:
    goto v_35854;
v_35855:
    goto v_35856;
v_35857:
    if (!consp(v_35898)) goto v_35852;
    v_35898 = qcar(v_35898);
    if (v_35898 == v_35897) goto v_35851;
    else goto v_35852;
v_35851:
    goto v_35866;
v_35862:
    v_35897 = stack[-1];
    v_35897 = qcdr(v_35897);
    v_35898 = qcar(v_35897);
    goto v_35863;
v_35864:
    v_35897 = stack[0];
    goto v_35865;
v_35866:
    goto v_35862;
v_35863:
    goto v_35864;
v_35865:
    {
        fn = elt(env, 4); // getdenomx
        return (*qfn2(fn))(fn, v_35898, v_35897);
    }
v_35852:
    goto v_35878;
v_35874:
    goto v_35884;
v_35880:
    v_35897 = stack[-1];
    v_35898 = qcar(v_35897);
    goto v_35881;
v_35882:
    v_35897 = stack[0];
    goto v_35883;
v_35884:
    goto v_35880;
v_35881:
    goto v_35882;
v_35883:
    stack[-2] = CC_xpwrlcmp(elt(env, 0), v_35898, v_35897);
    env = stack[-3];
    goto v_35875;
v_35876:
    goto v_35893;
v_35889:
    v_35897 = stack[-1];
    v_35898 = qcdr(v_35897);
    goto v_35890;
v_35891:
    v_35897 = stack[0];
    goto v_35892;
v_35893:
    goto v_35889;
v_35890:
    goto v_35891;
v_35892:
    v_35897 = CC_xpwrlcmp(elt(env, 0), v_35898, v_35897);
    env = stack[-3];
    goto v_35877;
v_35878:
    goto v_35874;
v_35875:
    goto v_35876;
v_35877:
    {
        LispObject v_35902 = stack[-2];
        fn = elt(env, 5); // lcm
        return (*qfn2(fn))(fn, v_35902, v_35897);
    }
    v_35897 = nil;
v_35814:
    return onevalue(v_35897);
}



// Code for ps!:expansion!-point

static LispObject CC_psTexpansionKpoint(LispObject env,
                         LispObject v_35810)
{
    env = qenv(env);
    LispObject v_35853, v_35854, v_35855;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_35855 = v_35810;
// end of prologue
    v_35853 = v_35855;
    if (!consp(v_35853)) goto v_35818;
    else goto v_35819;
v_35818:
    v_35853 = lisp_true;
    goto v_35817;
v_35819:
    goto v_35832;
v_35828:
    v_35853 = v_35855;
    v_35854 = qcar(v_35853);
    goto v_35829;
v_35830:
    v_35853 = elt(env, 1); // !:ps!:
    goto v_35831;
v_35832:
    goto v_35828;
v_35829:
    goto v_35830;
v_35831:
    if (v_35854 == v_35853) goto v_35827;
    v_35853 = v_35855;
    v_35853 = qcar(v_35853);
    if (!symbolp(v_35853)) v_35853 = nil;
    else { v_35853 = qfastgets(v_35853);
           if (v_35853 != nil) { v_35853 = elt(v_35853, 8); // dname
#ifdef RECORD_GET
             if (v_35853 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_35853 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_35853 == SPID_NOPROP) v_35853 = nil; }}
#endif
    goto v_35825;
v_35827:
    v_35853 = nil;
    goto v_35825;
    v_35853 = nil;
v_35825:
    goto v_35817;
    v_35853 = nil;
v_35817:
    if (v_35853 == nil) goto v_35815;
    v_35853 = nil;
    goto v_35813;
v_35815:
    goto v_35850;
v_35846:
    v_35854 = v_35855;
    goto v_35847;
v_35848:
    v_35853 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_35849;
v_35850:
    goto v_35846;
v_35847:
    goto v_35848;
v_35849:
    {
        fn = elt(env, 2); // ps!:getv
        return (*qfn2(fn))(fn, v_35854, v_35853);
    }
    v_35853 = nil;
v_35813:
    return onevalue(v_35853);
}



// Code for frlp

static LispObject CC_frlp(LispObject env,
                         LispObject v_35810)
{
    env = qenv(env);
    LispObject v_35839, v_35840, v_35841;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_35840 = v_35810;
// end of prologue
v_35809:
    v_35839 = v_35840;
    if (v_35839 == nil) goto v_35814;
    else goto v_35815;
v_35814:
    v_35839 = lisp_true;
    goto v_35813;
v_35815:
    goto v_35828;
v_35824:
    v_35839 = v_35840;
    v_35841 = qcar(v_35839);
    goto v_35825;
v_35826:
    v_35839 = qvalue(elt(env, 1)); // frlis!*
    goto v_35827;
v_35828:
    goto v_35824;
v_35825:
    goto v_35826;
v_35827:
    v_35839 = Lmemq(nil, v_35841, v_35839);
    if (v_35839 == nil) goto v_35822;
    else goto v_35823;
v_35822:
    v_35839 = nil;
    goto v_35821;
v_35823:
    v_35839 = v_35840;
    v_35839 = qcdr(v_35839);
    v_35840 = v_35839;
    goto v_35809;
    v_35839 = nil;
v_35821:
    goto v_35813;
    v_35839 = nil;
v_35813:
    return onevalue(v_35839);
}



// Code for dm!-quotient

static LispObject CC_dmKquotient(LispObject env,
                         LispObject v_35810, LispObject v_35811)
{
    env = qenv(env);
    LispObject v_35840, v_35841;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_35811,v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_35810,v_35811);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_35811;
    v_35841 = v_35810;
// end of prologue
    v_35840 = nil;
    qvalue(elt(env, 2)) = v_35840; // !*noequiv
    goto v_35824;
v_35820:
    v_35840 = v_35841;
    fn = elt(env, 3); // dm!-mkfloat
    stack[-1] = (*qfn1(fn))(fn, v_35840);
    env = stack[-2];
    goto v_35821;
v_35822:
    v_35840 = stack[0];
    fn = elt(env, 3); // dm!-mkfloat
    v_35840 = (*qfn1(fn))(fn, v_35840);
    env = stack[-2];
    goto v_35823;
v_35824:
    goto v_35820;
v_35821:
    goto v_35822;
v_35823:
    fn = elt(env, 4); // !:quotient
    v_35840 = (*qfn2(fn))(fn, stack[-1], v_35840);
    v_35841 = v_35840;
    v_35840 = v_35841;
    if (v_35840 == nil) goto v_35832;
    else goto v_35833;
v_35832:
    v_35840 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_35831;
v_35833:
    v_35840 = v_35841;
    goto v_35831;
    v_35840 = nil;
v_35831:
    return onevalue(v_35840);
}



// Code for groebsaveltermbc

static LispObject CC_groebsaveltermbc(LispObject env,
                         LispObject v_35810)
{
    env = qenv(env);
    LispObject v_35873, v_35874, v_35875;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35810);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_35810;
// end of prologue
    v_35873 = stack[0];
    fn = elt(env, 2); // vbc2a
    v_35873 = (*qfn1(fn))(fn, v_35873);
    env = stack[-2];
    stack[0] = v_35873;
    v_35873 = stack[0];
    if (is_number(v_35873)) goto v_35821;
    v_35873 = stack[0];
    fn = elt(env, 3); // constant_exprp
    v_35873 = (*qfn1(fn))(fn, v_35873);
    env = stack[-2];
    v_35873 = (v_35873 == nil ? lisp_true : nil);
    goto v_35819;
v_35821:
    v_35873 = nil;
    goto v_35819;
    v_35873 = nil;
v_35819:
    if (v_35873 == nil) goto v_35817;
    v_35873 = stack[0];
    fn = elt(env, 4); // simp
    v_35873 = (*qfn1(fn))(fn, v_35873);
    env = stack[-2];
    v_35873 = qcar(v_35873);
    fn = elt(env, 5); // fctrf
    v_35873 = (*qfn1(fn))(fn, v_35873);
    env = stack[-2];
    v_35873 = qcdr(v_35873);
    stack[-1] = v_35873;
v_35832:
    v_35873 = stack[-1];
    if (v_35873 == nil) goto v_35840;
    else goto v_35841;
v_35840:
    v_35873 = nil;
    goto v_35831;
v_35841:
    v_35873 = stack[-1];
    v_35873 = qcar(v_35873);
    v_35875 = v_35873;
    v_35873 = v_35875;
    v_35873 = qcar(v_35873);
    fn = elt(env, 6); // prepf
    v_35873 = (*qfn1(fn))(fn, v_35873);
    env = stack[-2];
    v_35875 = v_35873;
    goto v_35858;
v_35854:
    v_35874 = v_35875;
    goto v_35855;
v_35856:
    v_35873 = qvalue(elt(env, 1)); // glterms
    goto v_35857;
v_35858:
    goto v_35854;
v_35855:
    goto v_35856;
v_35857:
    v_35873 = Lmember(nil, v_35874, v_35873);
    if (v_35873 == nil) goto v_35852;
    else goto v_35853;
v_35852:
    goto v_35867;
v_35863:
    stack[0] = qvalue(elt(env, 1)); // glterms
    goto v_35864;
v_35865:
    v_35873 = v_35875;
    v_35873 = ncons(v_35873);
    env = stack[-2];
    goto v_35866;
v_35867:
    goto v_35863;
v_35864:
    goto v_35865;
v_35866:
    v_35873 = Lnconc(nil, stack[0], v_35873);
    env = stack[-2];
    goto v_35851;
v_35853:
v_35851:
    v_35873 = stack[-1];
    v_35873 = qcdr(v_35873);
    stack[-1] = v_35873;
    goto v_35832;
v_35831:
    goto v_35815;
v_35817:
    v_35873 = nil;
v_35815:
    return onevalue(v_35873);
}



// Code for lispcondp

static LispObject CC_lispcondp(LispObject env,
                         LispObject v_35810)
{
    env = qenv(env);
    LispObject v_35820, v_35821;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_35820 = v_35810;
// end of prologue
    goto v_35817;
v_35813:
    goto v_35814;
v_35815:
    v_35821 = elt(env, 1); // cond
    goto v_35816;
v_35817:
    goto v_35813;
v_35814:
    goto v_35815;
v_35816:
        return Leqcar(nil, v_35820, v_35821);
}



// Code for tot!-asym!-indp

static LispObject CC_totKasymKindp(LispObject env,
                         LispObject v_35810)
{
    env = qenv(env);
    LispObject v_35899, v_35900;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35810);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_35810;
// end of prologue
v_35809:
    v_35899 = stack[0];
    if (v_35899 == nil) goto v_35814;
    else goto v_35815;
v_35814:
    v_35899 = lisp_true;
    goto v_35813;
v_35815:
    v_35899 = stack[0];
    v_35899 = qcdr(v_35899);
    if (v_35899 == nil) goto v_35822;
    else goto v_35823;
v_35822:
    v_35899 = lisp_true;
    goto v_35821;
v_35823:
    goto v_35841;
v_35837:
    v_35899 = stack[0];
    v_35900 = qcar(v_35899);
    goto v_35838;
v_35839:
    v_35899 = stack[0];
    v_35899 = qcdr(v_35899);
    v_35899 = qcar(v_35899);
    goto v_35840;
v_35841:
    goto v_35837;
v_35838:
    goto v_35839;
v_35840:
    if (equal(v_35900, v_35899)) goto v_35836;
    v_35899 = stack[0];
    v_35899 = qcar(v_35899);
    if (!consp(v_35899)) goto v_35849;
    else goto v_35850;
v_35849:
    goto v_35858;
v_35854:
    v_35899 = stack[0];
    v_35900 = qcar(v_35899);
    goto v_35855;
v_35856:
    v_35899 = stack[0];
    v_35899 = qcdr(v_35899);
    v_35899 = qcar(v_35899);
    goto v_35857;
v_35858:
    goto v_35854;
v_35855:
    goto v_35856;
v_35857:
    fn = elt(env, 1); // indordp
    v_35899 = (*qfn2(fn))(fn, v_35900, v_35899);
    env = stack[-1];
    goto v_35848;
v_35850:
    v_35899 = stack[0];
    v_35899 = qcar(v_35899);
    fn = elt(env, 2); // indxchk
    v_35899 = (*qfn1(fn))(fn, v_35899);
    env = stack[-1];
    if (v_35899 == nil) goto v_35868;
    else goto v_35867;
v_35868:
    v_35899 = stack[0];
    v_35899 = qcdr(v_35899);
    v_35899 = qcar(v_35899);
    fn = elt(env, 2); // indxchk
    v_35899 = (*qfn1(fn))(fn, v_35899);
    env = stack[-1];
    if (v_35899 == nil) goto v_35874;
    else goto v_35873;
v_35874:
    goto v_35884;
v_35880:
    v_35899 = stack[0];
    v_35900 = qcar(v_35899);
    goto v_35881;
v_35882:
    v_35899 = stack[0];
    v_35899 = qcdr(v_35899);
    v_35899 = qcar(v_35899);
    goto v_35883;
v_35884:
    goto v_35880;
v_35881:
    goto v_35882;
v_35883:
    fn = elt(env, 3); // indordlp
    v_35899 = (*qfn2(fn))(fn, v_35900, v_35899);
    env = stack[-1];
v_35873:
v_35867:
    goto v_35848;
    v_35899 = nil;
v_35848:
    goto v_35834;
v_35836:
    v_35899 = nil;
    goto v_35834;
    v_35899 = nil;
v_35834:
    if (v_35899 == nil) goto v_35831;
    else goto v_35832;
v_35831:
    v_35899 = nil;
    goto v_35830;
v_35832:
    v_35899 = stack[0];
    v_35899 = qcdr(v_35899);
    stack[0] = v_35899;
    goto v_35809;
    v_35899 = nil;
v_35830:
    goto v_35821;
    v_35899 = nil;
v_35821:
    goto v_35813;
    v_35899 = nil;
v_35813:
    return onevalue(v_35899);
}



// Code for simpabs

static LispObject CC_simpabs(LispObject env,
                         LispObject v_35810)
{
    env = qenv(env);
    LispObject v_35899, v_35900;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_35810);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_35810;
// end of prologue
    v_35899 = stack[0];
    if (v_35899 == nil) goto v_35818;
    else goto v_35819;
v_35818:
    v_35899 = lisp_true;
    goto v_35817;
v_35819:
    v_35899 = stack[0];
    v_35899 = qcdr(v_35899);
    goto v_35817;
    v_35899 = nil;
v_35817:
    if (v_35899 == nil) goto v_35815;
    goto v_35831;
v_35827:
    goto v_35837;
v_35833:
    stack[-1] = elt(env, 1); // abs
    goto v_35834;
v_35835:
    v_35899 = stack[0];
    fn = elt(env, 3); // revlis
    v_35899 = (*qfn1(fn))(fn, v_35899);
    env = stack[-2];
    goto v_35836;
v_35837:
    goto v_35833;
v_35834:
    goto v_35835;
v_35836:
    v_35900 = cons(stack[-1], v_35899);
    env = stack[-2];
    goto v_35828;
v_35829:
    v_35899 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35830;
v_35831:
    goto v_35827;
v_35828:
    goto v_35829;
v_35830:
    {
        fn = elt(env, 4); // mksq
        return (*qfn2(fn))(fn, v_35900, v_35899);
    }
v_35815:
    v_35899 = stack[0];
    v_35899 = qcar(v_35899);
    stack[0] = v_35899;
    v_35899 = stack[0];
    if (is_number(v_35899)) goto v_35852;
    else goto v_35853;
v_35852:
    goto v_35860;
v_35856:
    v_35899 = stack[0];
    v_35900 = Labsval(nil, v_35899);
    goto v_35857;
v_35858:
    v_35899 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35859;
v_35860:
    goto v_35856;
v_35857:
    goto v_35858;
v_35859:
    return cons(v_35900, v_35899);
v_35853:
    v_35899 = stack[0];
    fn = elt(env, 5); // sign!-abs
    v_35899 = (*qfn1(fn))(fn, v_35899);
    env = stack[-2];
    v_35900 = v_35899;
    if (v_35899 == nil) goto v_35865;
    v_35899 = v_35900;
    goto v_35846;
v_35865:
    v_35899 = stack[0];
    fn = elt(env, 6); // simp!*
    v_35899 = (*qfn1(fn))(fn, v_35899);
    env = stack[-2];
    stack[0] = v_35899;
    v_35899 = stack[0];
    v_35899 = qcar(v_35899);
    if (v_35899 == nil) goto v_35873;
    else goto v_35874;
v_35873:
    goto v_35882;
v_35878:
    v_35900 = nil;
    goto v_35879;
v_35880:
    v_35899 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_35881;
v_35882:
    goto v_35878;
v_35879:
    goto v_35880;
v_35881:
    return cons(v_35900, v_35899);
v_35874:
    goto v_35892;
v_35888:
    v_35899 = stack[0];
    v_35899 = qcar(v_35899);
    fn = elt(env, 7); // simpabs1
    stack[-1] = (*qfn1(fn))(fn, v_35899);
    env = stack[-2];
    goto v_35889;
v_35890:
    v_35899 = stack[0];
    v_35899 = qcdr(v_35899);
    fn = elt(env, 7); // simpabs1
    v_35899 = (*qfn1(fn))(fn, v_35899);
    env = stack[-2];
    goto v_35891;
v_35892:
    goto v_35888;
v_35889:
    goto v_35890;
v_35891:
    {
        LispObject v_35903 = stack[-1];
        fn = elt(env, 8); // quotsq
        return (*qfn2(fn))(fn, v_35903, v_35899);
    }
    v_35899 = nil;
v_35846:
    goto v_35813;
    v_35899 = nil;
v_35813:
    return onevalue(v_35899);
}



// Code for formclear

static LispObject CC_formclear(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_35833, v_35834, v_35835;
    LispObject fn;
    LispObject v_35812, v_35811, v_35810;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formclear");
    va_start(aa, nargs);
    v_35810 = va_arg(aa, LispObject);
    v_35811 = va_arg(aa, LispObject);
    v_35812 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_35812,v_35811,v_35810);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_35810,v_35811,v_35812);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_35833 = v_35812;
    v_35834 = v_35811;
    v_35835 = v_35810;
// end of prologue
    goto v_35819;
v_35815:
    stack[0] = elt(env, 1); // clear
    goto v_35816;
v_35817:
    goto v_35828;
v_35822:
    v_35835 = qcdr(v_35835);
    goto v_35823;
v_35824:
    goto v_35825;
v_35826:
    goto v_35827;
v_35828:
    goto v_35822;
v_35823:
    goto v_35824;
v_35825:
    goto v_35826;
v_35827:
    fn = elt(env, 2); // formclear1
    v_35833 = (*qfnn(fn))(fn, 3, v_35835, v_35834, v_35833);
    goto v_35818;
v_35819:
    goto v_35815;
v_35816:
    goto v_35817;
v_35818:
    {
        LispObject v_35837 = stack[0];
        return list2(v_35837, v_35833);
    }
}



setup_type const u60_setup[] =
{
    {"preproc1",                CC_preproc1,    TOO_MANY_1,    WRONG_NO_1},
    {"find_bubles1",            TOO_FEW_2,      CC_find_bubles1,WRONG_NO_2},
    {"compactf1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_compactf1},
    {"solvevars",               CC_solvevars,   TOO_MANY_1,    WRONG_NO_1},
    {"nrootnn",                 TOO_FEW_2,      CC_nrootnn,    WRONG_NO_2},
    {"rat_min",                 TOO_FEW_2,      CC_rat_min,    WRONG_NO_2},
    {"let0",                    CC_let0,        TOO_MANY_1,    WRONG_NO_1},
    {"get-min-degreelist",      CC_getKminKdegreelist,TOO_MANY_1,WRONG_NO_1},
    {"cl_subfof1",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_subfof1},
    {"ps:find-order",           CC_psTfindKorder,TOO_MANY_1,   WRONG_NO_1},
    {"vdpenumerate",            CC_vdpenumerate,TOO_MANY_1,    WRONG_NO_1},
    {"xnormalise",              CC_xnormalise,  TOO_MANY_1,    WRONG_NO_1},
    {"validrule",               CC_validrule,   TOO_MANY_1,    WRONG_NO_1},
    {"listofvarnames",          CC_listofvarnames,TOO_MANY_1,  WRONG_NO_1},
    {"calc_map_2d",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_calc_map_2d},
    {"*sf2exb",                 TOO_FEW_2,      CC_Hsf2exb,    WRONG_NO_2},
    {"x**p-w",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xHHpKw},
    {"ofsf_ordrelp",            TOO_FEW_2,      CC_ofsf_ordrelp,WRONG_NO_2},
    {"makecoeffpairs1",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_makecoeffpairs1},
    {"null+vec+p",              CC_nullLvecLp,  TOO_MANY_1,    WRONG_NO_1},
    {"talp_get-minfct",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_getKminfct},
    {"xpwrlcmp",                TOO_FEW_2,      CC_xpwrlcmp,   WRONG_NO_2},
    {"ps:expansion-point",      CC_psTexpansionKpoint,TOO_MANY_1,WRONG_NO_1},
    {"frlp",                    CC_frlp,        TOO_MANY_1,    WRONG_NO_1},
    {"dm-quotient",             TOO_FEW_2,      CC_dmKquotient,WRONG_NO_2},
    {"groebsaveltermbc",        CC_groebsaveltermbc,TOO_MANY_1,WRONG_NO_1},
    {"lispcondp",               CC_lispcondp,   TOO_MANY_1,    WRONG_NO_1},
    {"tot-asym-indp",           CC_totKasymKindp,TOO_MANY_1,   WRONG_NO_1},
    {"simpabs",                 CC_simpabs,     TOO_MANY_1,    WRONG_NO_1},
    {"formclear",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formclear},
    {NULL, (one_args *)"u60", (two_args *)"23040 7621367 6545458", 0}
};

// end of generated code
