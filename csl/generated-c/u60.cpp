
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



// Code for comcom3

static LispObject CC_comcom3(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_40644, v_40645, v_40646, v_40647;
    LispObject fn;
    argcheck(nargs, 0, "comcom3");
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
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(17);
// end of prologue
    goto v_38193;
v_38189:
    goto v_38201;
v_38195:
    v_40646 = elt(env, 1); // l_k
    goto v_38196;
v_38197:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38198;
v_38199:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38200;
v_38201:
    goto v_38195;
v_38196:
    goto v_38197;
v_38198:
    goto v_38199;
v_38200:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38190;
v_38191:
    goto v_38212;
v_38206:
    v_40646 = elt(env, 2); // l_a
    goto v_38207;
v_38208:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38209;
v_38210:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38211;
v_38212:
    goto v_38206;
v_38207:
    goto v_38208;
v_38209:
    goto v_38210;
v_38211:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38192;
v_38193:
    goto v_38189;
v_38190:
    goto v_38191;
v_38192:
    v_40644 = list2(stack[0], v_40644);
    env = stack[-16];
    fn = elt(env, 31); // matrix
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    stack[-15] = v_40644;
    goto v_38223;
v_38219:
    goto v_38231;
v_38225:
    v_40646 = elt(env, 1); // l_k
    goto v_38226;
v_38227:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38228;
v_38229:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38230;
v_38231:
    goto v_38225;
v_38226:
    goto v_38227;
v_38228:
    goto v_38229;
v_38230:
    stack[-5] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38220;
v_38221:
    goto v_38245;
v_38237:
    stack[-4] = elt(env, 3); // plus
    goto v_38238;
v_38239:
    goto v_38254;
v_38248:
    stack[0] = elt(env, 4); // expt
    goto v_38249;
v_38250:
    goto v_38263;
v_38257:
    v_40646 = elt(env, 5); // ff
    goto v_38258;
v_38259:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38260;
v_38261:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38262;
v_38263:
    goto v_38257;
v_38258:
    goto v_38259;
v_38260:
    goto v_38261;
v_38262:
    v_40645 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38251;
v_38252:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38253;
v_38254:
    goto v_38248;
v_38249:
    goto v_38250;
v_38251:
    goto v_38252;
v_38253:
    stack[-3] = list3(stack[0], v_40645, v_40644);
    env = stack[-16];
    goto v_38240;
v_38241:
    goto v_38277;
v_38269:
    stack[-2] = elt(env, 6); // times
    goto v_38270;
v_38271:
    stack[-1] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38272;
v_38273:
    goto v_38287;
v_38281:
    v_40646 = elt(env, 5); // ff
    goto v_38282;
v_38283:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38284;
v_38285:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38286;
v_38287:
    goto v_38281;
v_38282:
    goto v_38283;
v_38284:
    goto v_38285;
v_38286:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38274;
v_38275:
    goto v_38298;
v_38292:
    v_40646 = elt(env, 5); // ff
    goto v_38293;
v_38294:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38295;
v_38296:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38297;
v_38298:
    goto v_38292;
v_38293:
    goto v_38294;
v_38295:
    goto v_38296;
v_38297:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38276;
v_38277:
    goto v_38269;
v_38270:
    goto v_38271;
v_38272:
    goto v_38273;
v_38274:
    goto v_38275;
v_38276:
    stack[-1] = list4(stack[-2], stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_38242;
v_38243:
    goto v_38309;
v_38303:
    stack[0] = elt(env, 4); // expt
    goto v_38304;
v_38305:
    goto v_38318;
v_38312:
    v_40646 = elt(env, 5); // ff
    goto v_38313;
v_38314:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38315;
v_38316:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38317;
v_38318:
    goto v_38312;
v_38313:
    goto v_38314;
v_38315:
    goto v_38316;
v_38317:
    v_40645 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38306;
v_38307:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38308;
v_38309:
    goto v_38303;
v_38304:
    goto v_38305;
v_38306:
    goto v_38307;
v_38308:
    v_40644 = list3(stack[0], v_40645, v_40644);
    env = stack[-16];
    goto v_38244;
v_38245:
    goto v_38237;
v_38238:
    goto v_38239;
v_38240:
    goto v_38241;
v_38242:
    goto v_38243;
v_38244:
    v_40644 = list4(stack[-4], stack[-3], stack[-1], v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_38222;
v_38223:
    goto v_38219;
v_38220:
    goto v_38221;
v_38222:
    fn = elt(env, 33); // setk
    v_40644 = (*qfn2(fn))(fn, stack[-5], v_40644);
    env = stack[-16];
    goto v_38328;
v_38324:
    goto v_38336;
v_38330:
    v_40646 = elt(env, 1); // l_k
    goto v_38331;
v_38332:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38333;
v_38334:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38335;
v_38336:
    goto v_38330;
v_38331:
    goto v_38332;
v_38333:
    goto v_38334;
v_38335:
    stack[-6] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38325;
v_38326:
    goto v_38350;
v_38342:
    stack[-5] = elt(env, 3); // plus
    goto v_38343;
v_38344:
    goto v_38357;
v_38353:
    stack[-2] = elt(env, 7); // minus
    goto v_38354;
v_38355:
    goto v_38366;
v_38360:
    stack[-1] = elt(env, 6); // times
    goto v_38361;
v_38362:
    goto v_38375;
v_38369:
    v_40646 = elt(env, 5); // ff
    goto v_38370;
v_38371:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38372;
v_38373:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38374;
v_38375:
    goto v_38369;
v_38370:
    goto v_38371;
v_38372:
    goto v_38373;
v_38374:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38363;
v_38364:
    goto v_38386;
v_38380:
    v_40646 = elt(env, 5); // ff
    goto v_38381;
v_38382:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38383;
v_38384:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38385;
v_38386:
    goto v_38380;
v_38381:
    goto v_38382;
v_38383:
    goto v_38384;
v_38385:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38365;
v_38366:
    goto v_38360;
v_38361:
    goto v_38362;
v_38363:
    goto v_38364;
v_38365:
    v_40644 = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_38356;
v_38357:
    goto v_38353;
v_38354:
    goto v_38355;
v_38356:
    stack[-4] = list2(stack[-2], v_40644);
    env = stack[-16];
    goto v_38345;
v_38346:
    goto v_38397;
v_38391:
    stack[-3] = elt(env, 8); // difference
    goto v_38392;
v_38393:
    goto v_38406;
v_38400:
    stack[-1] = elt(env, 6); // times
    goto v_38401;
v_38402:
    goto v_38415;
v_38409:
    v_40646 = elt(env, 5); // ff
    goto v_38410;
v_38411:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38412;
v_38413:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38414;
v_38415:
    goto v_38409;
v_38410:
    goto v_38411;
v_38412:
    goto v_38413;
v_38414:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38403;
v_38404:
    goto v_38426;
v_38420:
    v_40646 = elt(env, 5); // ff
    goto v_38421;
v_38422:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38423;
v_38424:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38425;
v_38426:
    goto v_38420;
v_38421:
    goto v_38422;
v_38423:
    goto v_38424;
v_38425:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38405;
v_38406:
    goto v_38400;
v_38401:
    goto v_38402;
v_38403:
    goto v_38404;
v_38405:
    stack[-2] = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_38394;
v_38395:
    goto v_38437;
v_38431:
    stack[-1] = elt(env, 6); // times
    goto v_38432;
v_38433:
    goto v_38446;
v_38440:
    v_40646 = elt(env, 5); // ff
    goto v_38441;
v_38442:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38443;
v_38444:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38445;
v_38446:
    goto v_38440;
v_38441:
    goto v_38442;
v_38443:
    goto v_38444;
v_38445:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38434;
v_38435:
    goto v_38457;
v_38451:
    v_40646 = elt(env, 5); // ff
    goto v_38452;
v_38453:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38454;
v_38455:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38456;
v_38457:
    goto v_38451;
v_38452:
    goto v_38453;
v_38454:
    goto v_38455;
v_38456:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38436;
v_38437:
    goto v_38431;
v_38432:
    goto v_38433;
v_38434:
    goto v_38435;
v_38436:
    v_40644 = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_38396;
v_38397:
    goto v_38391;
v_38392:
    goto v_38393;
v_38394:
    goto v_38395;
v_38396:
    stack[-2] = list3(stack[-3], stack[-2], v_40644);
    env = stack[-16];
    goto v_38347;
v_38348:
    goto v_38468;
v_38462:
    stack[-1] = elt(env, 6); // times
    goto v_38463;
v_38464:
    goto v_38477;
v_38471:
    v_40646 = elt(env, 5); // ff
    goto v_38472;
v_38473:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38474;
v_38475:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38476;
v_38477:
    goto v_38471;
v_38472:
    goto v_38473;
v_38474:
    goto v_38475;
v_38476:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38465;
v_38466:
    goto v_38488;
v_38482:
    v_40646 = elt(env, 5); // ff
    goto v_38483;
v_38484:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38485;
v_38486:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38487;
v_38488:
    goto v_38482;
v_38483:
    goto v_38484;
v_38485:
    goto v_38486;
v_38487:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38467;
v_38468:
    goto v_38462;
v_38463:
    goto v_38464;
v_38465:
    goto v_38466;
v_38467:
    v_40644 = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_38349;
v_38350:
    goto v_38342;
v_38343:
    goto v_38344;
v_38345:
    goto v_38346;
v_38347:
    goto v_38348;
v_38349:
    v_40644 = list4(stack[-5], stack[-4], stack[-2], v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_38327;
v_38328:
    goto v_38324;
v_38325:
    goto v_38326;
v_38327:
    fn = elt(env, 33); // setk
    v_40644 = (*qfn2(fn))(fn, stack[-6], v_40644);
    env = stack[-16];
    goto v_38497;
v_38493:
    goto v_38505;
v_38499:
    v_40646 = elt(env, 1); // l_k
    goto v_38500;
v_38501:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38502;
v_38503:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38504;
v_38505:
    goto v_38499;
v_38500:
    goto v_38501;
v_38502:
    goto v_38503;
v_38504:
    stack[-5] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38494;
v_38495:
    goto v_38517;
v_38511:
    stack[-4] = elt(env, 8); // difference
    goto v_38512;
v_38513:
    goto v_38526;
v_38520:
    stack[-3] = elt(env, 8); // difference
    goto v_38521;
v_38522:
    goto v_38535;
v_38529:
    stack[-2] = elt(env, 8); // difference
    goto v_38530;
v_38531:
    goto v_38542;
v_38538:
    stack[-6] = elt(env, 7); // minus
    goto v_38539;
v_38540:
    goto v_38551;
v_38545:
    stack[-1] = elt(env, 6); // times
    goto v_38546;
v_38547:
    goto v_38560;
v_38554:
    v_40646 = elt(env, 5); // ff
    goto v_38555;
v_38556:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38557;
v_38558:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38559;
v_38560:
    goto v_38554;
v_38555:
    goto v_38556;
v_38557:
    goto v_38558;
v_38559:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38548;
v_38549:
    goto v_38571;
v_38565:
    v_40646 = elt(env, 5); // ff
    goto v_38566;
v_38567:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38568;
v_38569:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38570;
v_38571:
    goto v_38565;
v_38566:
    goto v_38567;
v_38568:
    goto v_38569;
v_38570:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38550;
v_38551:
    goto v_38545;
v_38546:
    goto v_38547;
v_38548:
    goto v_38549;
v_38550:
    v_40644 = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_38541;
v_38542:
    goto v_38538;
v_38539:
    goto v_38540;
v_38541:
    stack[-6] = list2(stack[-6], v_40644);
    env = stack[-16];
    goto v_38532;
v_38533:
    goto v_38582;
v_38576:
    stack[-1] = elt(env, 6); // times
    goto v_38577;
v_38578:
    goto v_38591;
v_38585:
    v_40646 = elt(env, 5); // ff
    goto v_38586;
v_38587:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38588;
v_38589:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38590;
v_38591:
    goto v_38585;
v_38586:
    goto v_38587;
v_38588:
    goto v_38589;
v_38590:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38579;
v_38580:
    goto v_38602;
v_38596:
    v_40646 = elt(env, 5); // ff
    goto v_38597;
v_38598:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38599;
v_38600:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38601;
v_38602:
    goto v_38596;
v_38597:
    goto v_38598;
v_38599:
    goto v_38600;
v_38601:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38581;
v_38582:
    goto v_38576;
v_38577:
    goto v_38578;
v_38579:
    goto v_38580;
v_38581:
    v_40644 = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_38534;
v_38535:
    goto v_38529;
v_38530:
    goto v_38531;
v_38532:
    goto v_38533;
v_38534:
    stack[-2] = list3(stack[-2], stack[-6], v_40644);
    env = stack[-16];
    goto v_38523;
v_38524:
    goto v_38613;
v_38607:
    stack[-1] = elt(env, 6); // times
    goto v_38608;
v_38609:
    goto v_38622;
v_38616:
    v_40646 = elt(env, 5); // ff
    goto v_38617;
v_38618:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38619;
v_38620:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38621;
v_38622:
    goto v_38616;
v_38617:
    goto v_38618;
v_38619:
    goto v_38620;
v_38621:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38610;
v_38611:
    goto v_38633;
v_38627:
    v_40646 = elt(env, 5); // ff
    goto v_38628;
v_38629:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38630;
v_38631:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38632;
v_38633:
    goto v_38627;
v_38628:
    goto v_38629;
v_38630:
    goto v_38631;
v_38632:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38612;
v_38613:
    goto v_38607;
v_38608:
    goto v_38609;
v_38610:
    goto v_38611;
v_38612:
    v_40644 = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_38525;
v_38526:
    goto v_38520;
v_38521:
    goto v_38522;
v_38523:
    goto v_38524;
v_38525:
    stack[-2] = list3(stack[-3], stack[-2], v_40644);
    env = stack[-16];
    goto v_38514;
v_38515:
    goto v_38644;
v_38638:
    stack[-1] = elt(env, 6); // times
    goto v_38639;
v_38640:
    goto v_38653;
v_38647:
    v_40646 = elt(env, 5); // ff
    goto v_38648;
v_38649:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38650;
v_38651:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38652;
v_38653:
    goto v_38647;
v_38648:
    goto v_38649;
v_38650:
    goto v_38651;
v_38652:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38641;
v_38642:
    goto v_38664;
v_38658:
    v_40646 = elt(env, 5); // ff
    goto v_38659;
v_38660:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38661;
v_38662:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38663;
v_38664:
    goto v_38658;
v_38659:
    goto v_38660;
v_38661:
    goto v_38662;
v_38663:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38643;
v_38644:
    goto v_38638;
v_38639:
    goto v_38640;
v_38641:
    goto v_38642;
v_38643:
    v_40644 = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_38516;
v_38517:
    goto v_38511;
v_38512:
    goto v_38513;
v_38514:
    goto v_38515;
v_38516:
    v_40644 = list3(stack[-4], stack[-2], v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_38496;
v_38497:
    goto v_38493;
v_38494:
    goto v_38495;
v_38496:
    fn = elt(env, 33); // setk
    v_40644 = (*qfn2(fn))(fn, stack[-5], v_40644);
    env = stack[-16];
    goto v_38673;
v_38669:
    goto v_38681;
v_38675:
    v_40646 = elt(env, 1); // l_k
    goto v_38676;
v_38677:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38678;
v_38679:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38680;
v_38681:
    goto v_38675;
v_38676:
    goto v_38677;
v_38678:
    goto v_38679;
v_38680:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38670;
v_38671:
    goto v_38693;
v_38687:
    v_40646 = elt(env, 1); // l_k
    goto v_38688;
v_38689:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38690;
v_38691:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38692;
v_38693:
    goto v_38687;
v_38688:
    goto v_38689;
v_38690:
    goto v_38691;
v_38692:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_38672;
v_38673:
    goto v_38669;
v_38670:
    goto v_38671;
v_38672:
    fn = elt(env, 33); // setk
    v_40644 = (*qfn2(fn))(fn, stack[0], v_40644);
    env = stack[-16];
    goto v_38702;
v_38698:
    goto v_38710;
v_38704:
    v_40646 = elt(env, 1); // l_k
    goto v_38705;
v_38706:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38707;
v_38708:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38709;
v_38710:
    goto v_38704;
v_38705:
    goto v_38706;
v_38707:
    goto v_38708;
v_38709:
    stack[-6] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38699;
v_38700:
    goto v_38722;
v_38716:
    stack[-5] = elt(env, 3); // plus
    goto v_38717;
v_38718:
    goto v_38731;
v_38725:
    stack[-4] = elt(env, 8); // difference
    goto v_38726;
v_38727:
    goto v_38740;
v_38734:
    stack[0] = elt(env, 4); // expt
    goto v_38735;
v_38736:
    goto v_38749;
v_38743:
    v_40646 = elt(env, 5); // ff
    goto v_38744;
v_38745:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38746;
v_38747:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38748;
v_38749:
    goto v_38743;
v_38744:
    goto v_38745;
v_38746:
    goto v_38747;
v_38748:
    v_40645 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38737;
v_38738:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38739;
v_38740:
    goto v_38734;
v_38735:
    goto v_38736;
v_38737:
    goto v_38738;
v_38739:
    stack[-3] = list3(stack[0], v_40645, v_40644);
    env = stack[-16];
    goto v_38728;
v_38729:
    goto v_38763;
v_38755:
    stack[-2] = elt(env, 6); // times
    goto v_38756;
v_38757:
    stack[-1] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38758;
v_38759:
    goto v_38773;
v_38767:
    v_40646 = elt(env, 5); // ff
    goto v_38768;
v_38769:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38770;
v_38771:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38772;
v_38773:
    goto v_38767;
v_38768:
    goto v_38769;
v_38770:
    goto v_38771;
v_38772:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38760;
v_38761:
    goto v_38784;
v_38778:
    v_40646 = elt(env, 5); // ff
    goto v_38779;
v_38780:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38781;
v_38782:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38783;
v_38784:
    goto v_38778;
v_38779:
    goto v_38780;
v_38781:
    goto v_38782;
v_38783:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38762;
v_38763:
    goto v_38755;
v_38756:
    goto v_38757;
v_38758:
    goto v_38759;
v_38760:
    goto v_38761;
v_38762:
    v_40644 = list4(stack[-2], stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_38730;
v_38731:
    goto v_38725;
v_38726:
    goto v_38727;
v_38728:
    goto v_38729;
v_38730:
    stack[-1] = list3(stack[-4], stack[-3], v_40644);
    env = stack[-16];
    goto v_38719;
v_38720:
    goto v_38795;
v_38789:
    stack[0] = elt(env, 4); // expt
    goto v_38790;
v_38791:
    goto v_38804;
v_38798:
    v_40646 = elt(env, 5); // ff
    goto v_38799;
v_38800:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38801;
v_38802:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38803;
v_38804:
    goto v_38798;
v_38799:
    goto v_38800;
v_38801:
    goto v_38802;
v_38803:
    v_40645 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38792;
v_38793:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38794;
v_38795:
    goto v_38789;
v_38790:
    goto v_38791;
v_38792:
    goto v_38793;
v_38794:
    v_40644 = list3(stack[0], v_40645, v_40644);
    env = stack[-16];
    goto v_38721;
v_38722:
    goto v_38716;
v_38717:
    goto v_38718;
v_38719:
    goto v_38720;
v_38721:
    v_40644 = list3(stack[-5], stack[-1], v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_38701;
v_38702:
    goto v_38698;
v_38699:
    goto v_38700;
v_38701:
    fn = elt(env, 33); // setk
    v_40644 = (*qfn2(fn))(fn, stack[-6], v_40644);
    env = stack[-16];
    goto v_38814;
v_38810:
    goto v_38822;
v_38816:
    v_40646 = elt(env, 1); // l_k
    goto v_38817;
v_38818:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38819;
v_38820:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38821;
v_38822:
    goto v_38816;
v_38817:
    goto v_38818;
v_38819:
    goto v_38820;
v_38821:
    stack[-7] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38811;
v_38812:
    goto v_38834;
v_38828:
    stack[-6] = elt(env, 3); // plus
    goto v_38829;
v_38830:
    goto v_38843;
v_38837:
    stack[-1] = elt(env, 6); // times
    goto v_38838;
v_38839:
    goto v_38852;
v_38846:
    v_40646 = elt(env, 5); // ff
    goto v_38847;
v_38848:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38849;
v_38850:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38851;
v_38852:
    goto v_38846;
v_38847:
    goto v_38848;
v_38849:
    goto v_38850;
v_38851:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38840;
v_38841:
    goto v_38863;
v_38857:
    v_40646 = elt(env, 5); // ff
    goto v_38858;
v_38859:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38860;
v_38861:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38862;
v_38863:
    goto v_38857;
v_38858:
    goto v_38859;
v_38860:
    goto v_38861;
v_38862:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38842;
v_38843:
    goto v_38837;
v_38838:
    goto v_38839;
v_38840:
    goto v_38841;
v_38842:
    stack[-5] = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_38831;
v_38832:
    goto v_38874;
v_38868:
    stack[-4] = elt(env, 8); // difference
    goto v_38869;
v_38870:
    goto v_38883;
v_38877:
    stack[-3] = elt(env, 8); // difference
    goto v_38878;
v_38879:
    goto v_38892;
v_38886:
    stack[-1] = elt(env, 6); // times
    goto v_38887;
v_38888:
    goto v_38901;
v_38895:
    v_40646 = elt(env, 5); // ff
    goto v_38896;
v_38897:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38898;
v_38899:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38900;
v_38901:
    goto v_38895;
v_38896:
    goto v_38897;
v_38898:
    goto v_38899;
v_38900:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38889;
v_38890:
    goto v_38912;
v_38906:
    v_40646 = elt(env, 5); // ff
    goto v_38907;
v_38908:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38909;
v_38910:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38911;
v_38912:
    goto v_38906;
v_38907:
    goto v_38908;
v_38909:
    goto v_38910;
v_38911:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38891;
v_38892:
    goto v_38886;
v_38887:
    goto v_38888;
v_38889:
    goto v_38890;
v_38891:
    stack[-2] = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_38880;
v_38881:
    goto v_38923;
v_38917:
    stack[-1] = elt(env, 6); // times
    goto v_38918;
v_38919:
    goto v_38932;
v_38926:
    v_40646 = elt(env, 5); // ff
    goto v_38927;
v_38928:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38929;
v_38930:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38931;
v_38932:
    goto v_38926;
v_38927:
    goto v_38928;
v_38929:
    goto v_38930;
v_38931:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38920;
v_38921:
    goto v_38943;
v_38937:
    v_40646 = elt(env, 5); // ff
    goto v_38938;
v_38939:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38940;
v_38941:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38942;
v_38943:
    goto v_38937;
v_38938:
    goto v_38939;
v_38940:
    goto v_38941;
v_38942:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38922;
v_38923:
    goto v_38917;
v_38918:
    goto v_38919;
v_38920:
    goto v_38921;
v_38922:
    v_40644 = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_38882;
v_38883:
    goto v_38877;
v_38878:
    goto v_38879;
v_38880:
    goto v_38881;
v_38882:
    stack[-2] = list3(stack[-3], stack[-2], v_40644);
    env = stack[-16];
    goto v_38871;
v_38872:
    goto v_38954;
v_38948:
    stack[-1] = elt(env, 6); // times
    goto v_38949;
v_38950:
    goto v_38963;
v_38957:
    v_40646 = elt(env, 5); // ff
    goto v_38958;
v_38959:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38960;
v_38961:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38962;
v_38963:
    goto v_38957;
v_38958:
    goto v_38959;
v_38960:
    goto v_38961;
v_38962:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38951;
v_38952:
    goto v_38974;
v_38968:
    v_40646 = elt(env, 5); // ff
    goto v_38969;
v_38970:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38971;
v_38972:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38973;
v_38974:
    goto v_38968;
v_38969:
    goto v_38970;
v_38971:
    goto v_38972;
v_38973:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38953;
v_38954:
    goto v_38948;
v_38949:
    goto v_38950;
v_38951:
    goto v_38952;
v_38953:
    v_40644 = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_38873;
v_38874:
    goto v_38868;
v_38869:
    goto v_38870;
v_38871:
    goto v_38872;
v_38873:
    v_40644 = list3(stack[-4], stack[-2], v_40644);
    env = stack[-16];
    goto v_38833;
v_38834:
    goto v_38828;
v_38829:
    goto v_38830;
v_38831:
    goto v_38832;
v_38833:
    v_40644 = list3(stack[-6], stack[-5], v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_38813;
v_38814:
    goto v_38810;
v_38811:
    goto v_38812;
v_38813:
    fn = elt(env, 33); // setk
    v_40644 = (*qfn2(fn))(fn, stack[-7], v_40644);
    env = stack[-16];
    goto v_38983;
v_38979:
    goto v_38991;
v_38985:
    v_40646 = elt(env, 1); // l_k
    goto v_38986;
v_38987:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38988;
v_38989:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38990;
v_38991:
    goto v_38985;
v_38986:
    goto v_38987;
v_38988:
    goto v_38989;
v_38990:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_38980;
v_38981:
    goto v_39003;
v_38997:
    v_40646 = elt(env, 1); // l_k
    goto v_38998;
v_38999:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39000;
v_39001:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_39002;
v_39003:
    goto v_38997;
v_38998:
    goto v_38999;
v_39000:
    goto v_39001;
v_39002:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_38982;
v_38983:
    goto v_38979;
v_38980:
    goto v_38981;
v_38982:
    fn = elt(env, 33); // setk
    v_40644 = (*qfn2(fn))(fn, stack[0], v_40644);
    env = stack[-16];
    goto v_39012;
v_39008:
    goto v_39020;
v_39014:
    v_40646 = elt(env, 1); // l_k
    goto v_39015;
v_39016:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_39017;
v_39018:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39019;
v_39020:
    goto v_39014;
v_39015:
    goto v_39016;
v_39017:
    goto v_39018;
v_39019:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39009;
v_39010:
    goto v_39032;
v_39026:
    v_40646 = elt(env, 1); // l_k
    goto v_39027;
v_39028:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39029;
v_39030:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_39031;
v_39032:
    goto v_39026;
v_39027:
    goto v_39028;
v_39029:
    goto v_39030;
v_39031:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39011;
v_39012:
    goto v_39008;
v_39009:
    goto v_39010;
v_39011:
    fn = elt(env, 33); // setk
    v_40644 = (*qfn2(fn))(fn, stack[0], v_40644);
    env = stack[-16];
    goto v_39041;
v_39037:
    goto v_39049;
v_39043:
    v_40646 = elt(env, 1); // l_k
    goto v_39044;
v_39045:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_39046;
v_39047:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_39048;
v_39049:
    goto v_39043;
v_39044:
    goto v_39045;
v_39046:
    goto v_39047;
v_39048:
    stack[-5] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39038;
v_39039:
    goto v_39063;
v_39055:
    stack[-4] = elt(env, 3); // plus
    goto v_39056;
v_39057:
    goto v_39072;
v_39066:
    stack[0] = elt(env, 4); // expt
    goto v_39067;
v_39068:
    goto v_39081;
v_39075:
    v_40646 = elt(env, 5); // ff
    goto v_39076;
v_39077:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39078;
v_39079:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39080;
v_39081:
    goto v_39075;
v_39076:
    goto v_39077;
v_39078:
    goto v_39079;
v_39080:
    v_40645 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39069;
v_39070:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39071;
v_39072:
    goto v_39066;
v_39067:
    goto v_39068;
v_39069:
    goto v_39070;
v_39071:
    stack[-3] = list3(stack[0], v_40645, v_40644);
    env = stack[-16];
    goto v_39058;
v_39059:
    goto v_39095;
v_39087:
    stack[-2] = elt(env, 6); // times
    goto v_39088;
v_39089:
    stack[-1] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39090;
v_39091:
    goto v_39105;
v_39099:
    v_40646 = elt(env, 5); // ff
    goto v_39100;
v_39101:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39102;
v_39103:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39104;
v_39105:
    goto v_39099;
v_39100:
    goto v_39101;
v_39102:
    goto v_39103;
v_39104:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39092;
v_39093:
    goto v_39116;
v_39110:
    v_40646 = elt(env, 5); // ff
    goto v_39111;
v_39112:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_39113;
v_39114:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39115;
v_39116:
    goto v_39110;
v_39111:
    goto v_39112;
v_39113:
    goto v_39114;
v_39115:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39094;
v_39095:
    goto v_39087;
v_39088:
    goto v_39089;
v_39090:
    goto v_39091;
v_39092:
    goto v_39093;
v_39094:
    stack[-1] = list4(stack[-2], stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_39060;
v_39061:
    goto v_39127;
v_39121:
    stack[0] = elt(env, 4); // expt
    goto v_39122;
v_39123:
    goto v_39136;
v_39130:
    v_40646 = elt(env, 5); // ff
    goto v_39131;
v_39132:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_39133;
v_39134:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39135;
v_39136:
    goto v_39130;
v_39131:
    goto v_39132;
v_39133:
    goto v_39134;
v_39135:
    v_40645 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39124;
v_39125:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39126;
v_39127:
    goto v_39121;
v_39122:
    goto v_39123;
v_39124:
    goto v_39125;
v_39126:
    v_40644 = list3(stack[0], v_40645, v_40644);
    env = stack[-16];
    goto v_39062;
v_39063:
    goto v_39055;
v_39056:
    goto v_39057;
v_39058:
    goto v_39059;
v_39060:
    goto v_39061;
v_39062:
    v_40644 = list4(stack[-4], stack[-3], stack[-1], v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39040;
v_39041:
    goto v_39037;
v_39038:
    goto v_39039;
v_39040:
    fn = elt(env, 33); // setk
    v_40644 = (*qfn2(fn))(fn, stack[-5], v_40644);
    env = stack[-16];
    goto v_39155;
v_39149:
    v_40646 = elt(env, 1); // l_k
    goto v_39150;
v_39151:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39152;
v_39153:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39154;
v_39155:
    goto v_39149;
v_39150:
    goto v_39151;
v_39152:
    goto v_39153;
v_39154:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    fn = elt(env, 34); // evalnumberp
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    if (v_40644 == nil) goto v_39143;
    goto v_39170;
v_39164:
    stack[-3] = elt(env, 8); // difference
    goto v_39165;
v_39166:
    goto v_39179;
v_39173:
    stack[-1] = elt(env, 6); // times
    goto v_39174;
v_39175:
    goto v_39188;
v_39182:
    v_40646 = elt(env, 1); // l_k
    goto v_39183;
v_39184:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39185;
v_39186:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39187;
v_39188:
    goto v_39182;
v_39183:
    goto v_39184;
v_39185:
    goto v_39186;
v_39187:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39176;
v_39177:
    goto v_39199;
v_39193:
    v_40646 = elt(env, 1); // l_k
    goto v_39194;
v_39195:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39196;
v_39197:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39198;
v_39199:
    goto v_39193;
v_39194:
    goto v_39195;
v_39196:
    goto v_39197;
v_39198:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39178;
v_39179:
    goto v_39173;
v_39174:
    goto v_39175;
v_39176:
    goto v_39177;
v_39178:
    stack[-2] = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_39167;
v_39168:
    goto v_39210;
v_39204:
    stack[-1] = elt(env, 6); // times
    goto v_39205;
v_39206:
    goto v_39219;
v_39213:
    v_40646 = elt(env, 1); // l_k
    goto v_39214;
v_39215:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39216;
v_39217:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39218;
v_39219:
    goto v_39213;
v_39214:
    goto v_39215;
v_39216:
    goto v_39217;
v_39218:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39207;
v_39208:
    goto v_39230;
v_39224:
    v_40646 = elt(env, 1); // l_k
    goto v_39225;
v_39226:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39227;
v_39228:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39229;
v_39230:
    goto v_39224;
v_39225:
    goto v_39226;
v_39227:
    goto v_39228;
v_39229:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39209;
v_39210:
    goto v_39204;
v_39205:
    goto v_39206;
v_39207:
    goto v_39208;
v_39209:
    v_40644 = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_39169;
v_39170:
    goto v_39164;
v_39165:
    goto v_39166;
v_39167:
    goto v_39168;
v_39169:
    v_40644 = list3(stack[-3], stack[-2], v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    fn = elt(env, 34); // evalnumberp
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    if (v_40644 == nil) goto v_39143;
    goto v_39242;
v_39238:
    v_40645 = elt(env, 9); // det
    goto v_39239;
v_39240:
    v_40644 = elt(env, 1); // l_k
    goto v_39241;
v_39242:
    goto v_39238;
v_39239:
    goto v_39240;
v_39241:
    v_40644 = list2(v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    fn = elt(env, 34); // evalnumberp
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    if (v_40644 == nil) goto v_39143;
    goto v_39144;
v_39143:
    goto v_39252;
v_39246:
    v_40644 = elt(env, 10); // "Is "
    fn = elt(env, 32); // aeval
    v_40646 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39247;
v_39248:
    v_40645 = nil;
    goto v_39249;
v_39250:
    v_40644 = elt(env, 11); // first
    goto v_39251;
v_39252:
    goto v_39246;
v_39247:
    goto v_39248;
v_39249:
    goto v_39250;
v_39251:
    fn = elt(env, 35); // assgnpri
    v_40644 = (*qfnn(fn))(fn, 3, v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39264;
v_39258:
    goto v_39271;
v_39267:
    stack[0] = elt(env, 7); // minus
    goto v_39268;
v_39269:
    goto v_39280;
v_39274:
    v_40646 = elt(env, 1); // l_k
    goto v_39275;
v_39276:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39277;
v_39278:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39279;
v_39280:
    goto v_39274;
v_39275:
    goto v_39276;
v_39277:
    goto v_39278;
v_39279:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39270;
v_39271:
    goto v_39267;
v_39268:
    goto v_39269;
v_39270:
    v_40644 = list2(stack[0], v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40646 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39259;
v_39260:
    v_40645 = nil;
    goto v_39261;
v_39262:
    v_40644 = nil;
    goto v_39263;
v_39264:
    goto v_39258;
v_39259:
    goto v_39260;
v_39261:
    goto v_39262;
v_39263:
    fn = elt(env, 35); // assgnpri
    v_40644 = (*qfnn(fn))(fn, 3, v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39293;
v_39287:
    v_40644 = elt(env, 12); // ">0 and "
    fn = elt(env, 32); // aeval
    v_40646 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39288;
v_39289:
    v_40645 = nil;
    goto v_39290;
v_39291:
    v_40644 = nil;
    goto v_39292;
v_39293:
    goto v_39287;
v_39288:
    goto v_39289;
v_39290:
    goto v_39291;
v_39292:
    fn = elt(env, 35); // assgnpri
    v_40644 = (*qfnn(fn))(fn, 3, v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39305;
v_39299:
    goto v_39314;
v_39308:
    stack[-3] = elt(env, 8); // difference
    goto v_39309;
v_39310:
    goto v_39323;
v_39317:
    stack[-1] = elt(env, 6); // times
    goto v_39318;
v_39319:
    goto v_39332;
v_39326:
    v_40646 = elt(env, 1); // l_k
    goto v_39327;
v_39328:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39329;
v_39330:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39331;
v_39332:
    goto v_39326;
v_39327:
    goto v_39328;
v_39329:
    goto v_39330;
v_39331:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39320;
v_39321:
    goto v_39343;
v_39337:
    v_40646 = elt(env, 1); // l_k
    goto v_39338;
v_39339:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39340;
v_39341:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39342;
v_39343:
    goto v_39337;
v_39338:
    goto v_39339;
v_39340:
    goto v_39341;
v_39342:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39322;
v_39323:
    goto v_39317;
v_39318:
    goto v_39319;
v_39320:
    goto v_39321;
v_39322:
    stack[-2] = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_39311;
v_39312:
    goto v_39354;
v_39348:
    stack[-1] = elt(env, 6); // times
    goto v_39349;
v_39350:
    goto v_39363;
v_39357:
    v_40646 = elt(env, 1); // l_k
    goto v_39358;
v_39359:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39360;
v_39361:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39362;
v_39363:
    goto v_39357;
v_39358:
    goto v_39359;
v_39360:
    goto v_39361;
v_39362:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39351;
v_39352:
    goto v_39374;
v_39368:
    v_40646 = elt(env, 1); // l_k
    goto v_39369;
v_39370:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39371;
v_39372:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39373;
v_39374:
    goto v_39368;
v_39369:
    goto v_39370;
v_39371:
    goto v_39372;
v_39373:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39353;
v_39354:
    goto v_39348;
v_39349:
    goto v_39350;
v_39351:
    goto v_39352;
v_39353:
    v_40644 = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_39313;
v_39314:
    goto v_39308;
v_39309:
    goto v_39310;
v_39311:
    goto v_39312;
v_39313:
    v_40644 = list3(stack[-3], stack[-2], v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40646 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39300;
v_39301:
    v_40645 = nil;
    goto v_39302;
v_39303:
    v_40644 = nil;
    goto v_39304;
v_39305:
    goto v_39299;
v_39300:
    goto v_39301;
v_39302:
    goto v_39303;
v_39304:
    fn = elt(env, 35); // assgnpri
    v_40644 = (*qfnn(fn))(fn, 3, v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39387;
v_39381:
    v_40644 = elt(env, 12); // ">0 and "
    fn = elt(env, 32); // aeval
    v_40646 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39382;
v_39383:
    v_40645 = nil;
    goto v_39384;
v_39385:
    v_40644 = nil;
    goto v_39386;
v_39387:
    goto v_39381;
v_39382:
    goto v_39383;
v_39384:
    goto v_39385;
v_39386:
    fn = elt(env, 35); // assgnpri
    v_40644 = (*qfnn(fn))(fn, 3, v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39399;
v_39393:
    goto v_39406;
v_39402:
    stack[0] = elt(env, 7); // minus
    goto v_39403;
v_39404:
    goto v_39413;
v_39409:
    v_40645 = elt(env, 9); // det
    goto v_39410;
v_39411:
    v_40644 = elt(env, 1); // l_k
    goto v_39412;
v_39413:
    goto v_39409;
v_39410:
    goto v_39411;
v_39412:
    v_40644 = list2(v_40645, v_40644);
    env = stack[-16];
    goto v_39405;
v_39406:
    goto v_39402;
v_39403:
    goto v_39404;
v_39405:
    v_40644 = list2(stack[0], v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40646 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39394;
v_39395:
    v_40645 = nil;
    goto v_39396;
v_39397:
    v_40644 = nil;
    goto v_39398;
v_39399:
    goto v_39393;
v_39394:
    goto v_39395;
v_39396:
    goto v_39397;
v_39398:
    fn = elt(env, 35); // assgnpri
    v_40644 = (*qfnn(fn))(fn, 3, v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39425;
v_39419:
    v_40644 = elt(env, 13); // ">0 ? (y/n) and press <RETURN>"
    fn = elt(env, 32); // aeval
    v_40646 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39420;
v_39421:
    v_40645 = nil;
    goto v_39422;
v_39423:
    v_40644 = elt(env, 14); // last
    goto v_39424;
v_39425:
    goto v_39419;
v_39420:
    goto v_39421;
v_39422:
    goto v_39423;
v_39424:
    fn = elt(env, 35); // assgnpri
    v_40644 = (*qfnn(fn))(fn, 3, v_40646, v_40645, v_40644);
    env = stack[-16];
    v_40644 = Lread(nil, 0);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39441;
v_39437:
    fn = elt(env, 32); // aeval
    stack[0] = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39438;
v_39439:
    v_40644 = elt(env, 15); // y
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39440;
v_39441:
    goto v_39437;
v_39438:
    goto v_39439;
v_39440:
    fn = elt(env, 36); // evalequal
    v_40644 = (*qfn2(fn))(fn, stack[0], v_40644);
    env = stack[-16];
    if (v_40644 == nil) goto v_39435;
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    stack[-15] = v_40644;
    v_40644 = elt(env, 16); // lie4so3
    v_40644 = ncons(v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39433;
v_39435:
    v_40644 = elt(env, 17); // lie4so21
    v_40644 = ncons(v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39433;
v_39433:
    goto v_39142;
v_39144:
    goto v_39464;
v_39460:
    goto v_39471;
v_39467:
    stack[0] = elt(env, 7); // minus
    goto v_39468;
v_39469:
    goto v_39480;
v_39474:
    v_40646 = elt(env, 1); // l_k
    goto v_39475;
v_39476:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39477;
v_39478:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39479;
v_39480:
    goto v_39474;
v_39475:
    goto v_39476;
v_39477:
    goto v_39478;
v_39479:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39470;
v_39471:
    goto v_39467;
v_39468:
    goto v_39469;
v_39470:
    v_40644 = list2(stack[0], v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40645 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39461;
v_39462:
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_39463;
v_39464:
    goto v_39460;
v_39461:
    goto v_39462;
v_39463:
    fn = elt(env, 37); // evalgreaterp
    v_40644 = (*qfn2(fn))(fn, v_40645, v_40644);
    env = stack[-16];
    if (v_40644 == nil) goto v_39457;
    goto v_39492;
v_39488:
    goto v_39501;
v_39495:
    stack[-3] = elt(env, 8); // difference
    goto v_39496;
v_39497:
    goto v_39510;
v_39504:
    stack[-1] = elt(env, 6); // times
    goto v_39505;
v_39506:
    goto v_39519;
v_39513:
    v_40646 = elt(env, 1); // l_k
    goto v_39514;
v_39515:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39516;
v_39517:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39518;
v_39519:
    goto v_39513;
v_39514:
    goto v_39515;
v_39516:
    goto v_39517;
v_39518:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39507;
v_39508:
    goto v_39530;
v_39524:
    v_40646 = elt(env, 1); // l_k
    goto v_39525;
v_39526:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39527;
v_39528:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39529;
v_39530:
    goto v_39524;
v_39525:
    goto v_39526;
v_39527:
    goto v_39528;
v_39529:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39509;
v_39510:
    goto v_39504;
v_39505:
    goto v_39506;
v_39507:
    goto v_39508;
v_39509:
    stack[-2] = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_39498;
v_39499:
    goto v_39541;
v_39535:
    stack[-1] = elt(env, 6); // times
    goto v_39536;
v_39537:
    goto v_39550;
v_39544:
    v_40646 = elt(env, 1); // l_k
    goto v_39545;
v_39546:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39547;
v_39548:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39549;
v_39550:
    goto v_39544;
v_39545:
    goto v_39546;
v_39547:
    goto v_39548;
v_39549:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39538;
v_39539:
    goto v_39561;
v_39555:
    v_40646 = elt(env, 1); // l_k
    goto v_39556;
v_39557:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39558;
v_39559:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39560;
v_39561:
    goto v_39555;
v_39556:
    goto v_39557;
v_39558:
    goto v_39559;
v_39560:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39540;
v_39541:
    goto v_39535;
v_39536:
    goto v_39537;
v_39538:
    goto v_39539;
v_39540:
    v_40644 = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    goto v_39500;
v_39501:
    goto v_39495;
v_39496:
    goto v_39497;
v_39498:
    goto v_39499;
v_39500:
    v_40644 = list3(stack[-3], stack[-2], v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40645 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39489;
v_39490:
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_39491;
v_39492:
    goto v_39488;
v_39489:
    goto v_39490;
v_39491:
    fn = elt(env, 37); // evalgreaterp
    v_40644 = (*qfn2(fn))(fn, v_40645, v_40644);
    env = stack[-16];
    if (v_40644 == nil) goto v_39457;
    goto v_39572;
v_39568:
    goto v_39579;
v_39575:
    stack[0] = elt(env, 7); // minus
    goto v_39576;
v_39577:
    goto v_39586;
v_39582:
    v_40645 = elt(env, 9); // det
    goto v_39583;
v_39584:
    v_40644 = elt(env, 1); // l_k
    goto v_39585;
v_39586:
    goto v_39582;
v_39583:
    goto v_39584;
v_39585:
    v_40644 = list2(v_40645, v_40644);
    env = stack[-16];
    goto v_39578;
v_39579:
    goto v_39575;
v_39576:
    goto v_39577;
v_39578:
    v_40644 = list2(stack[0], v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40645 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39569;
v_39570:
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_39571;
v_39572:
    goto v_39568;
v_39569:
    goto v_39570;
v_39571:
    fn = elt(env, 37); // evalgreaterp
    v_40644 = (*qfn2(fn))(fn, v_40645, v_40644);
    env = stack[-16];
    if (v_40644 == nil) goto v_39457;
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    stack[-15] = v_40644;
    v_40644 = elt(env, 16); // lie4so3
    v_40644 = ncons(v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39142;
v_39457:
    v_40644 = elt(env, 17); // lie4so21
    v_40644 = ncons(v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39142;
v_39142:
    goto v_39605;
v_39601:
    stack[-6] = elt(env, 18); // liemat
    goto v_39602;
v_39603:
    goto v_39615;
v_39609:
    stack[-5] = elt(env, 6); // times
    goto v_39610;
v_39611:
    goto v_39626;
v_39618:
    stack[-4] = elt(env, 19); // mat
    goto v_39619;
v_39620:
    goto v_39637;
v_39629:
    goto v_39645;
v_39639:
    v_40646 = elt(env, 2); // l_a
    goto v_39640;
v_39641:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39642;
v_39643:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39644;
v_39645:
    goto v_39639;
v_39640:
    goto v_39641;
v_39642:
    goto v_39643;
v_39644:
    stack[-1] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39630;
v_39631:
    goto v_39656;
v_39650:
    v_40646 = elt(env, 2); // l_a
    goto v_39651;
v_39652:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39653;
v_39654:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39655;
v_39656:
    goto v_39650;
v_39651:
    goto v_39652;
v_39653:
    goto v_39654;
v_39655:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39632;
v_39633:
    goto v_39667;
v_39661:
    v_40646 = elt(env, 2); // l_a
    goto v_39662;
v_39663:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39664;
v_39665:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_39666;
v_39667:
    goto v_39661;
v_39662:
    goto v_39663;
v_39664:
    goto v_39665;
v_39666:
    v_40645 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39634;
v_39635:
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_39636;
v_39637:
    goto v_39629;
v_39630:
    goto v_39631;
v_39632:
    goto v_39633;
v_39634:
    goto v_39635;
v_39636:
    stack[-3] = list4(stack[-1], stack[0], v_40645, v_40644);
    env = stack[-16];
    goto v_39621;
v_39622:
    goto v_39681;
v_39673:
    goto v_39689;
v_39683:
    v_40646 = elt(env, 2); // l_a
    goto v_39684;
v_39685:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39686;
v_39687:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39688;
v_39689:
    goto v_39683;
v_39684:
    goto v_39685;
v_39686:
    goto v_39687;
v_39688:
    stack[-1] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39674;
v_39675:
    goto v_39700;
v_39694:
    v_40646 = elt(env, 2); // l_a
    goto v_39695;
v_39696:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39697;
v_39698:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39699;
v_39700:
    goto v_39694;
v_39695:
    goto v_39696;
v_39697:
    goto v_39698;
v_39699:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39676;
v_39677:
    goto v_39711;
v_39705:
    v_40646 = elt(env, 2); // l_a
    goto v_39706;
v_39707:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39708;
v_39709:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_39710;
v_39711:
    goto v_39705;
v_39706:
    goto v_39707;
v_39708:
    goto v_39709;
v_39710:
    v_40645 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39678;
v_39679:
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_39680;
v_39681:
    goto v_39673;
v_39674:
    goto v_39675;
v_39676:
    goto v_39677;
v_39678:
    goto v_39679;
v_39680:
    stack[-2] = list4(stack[-1], stack[0], v_40645, v_40644);
    env = stack[-16];
    goto v_39623;
v_39624:
    goto v_39721;
v_39717:
    goto v_39731;
v_39723:
    goto v_39739;
v_39733:
    v_40646 = elt(env, 2); // l_a
    goto v_39734;
v_39735:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_39736;
v_39737:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39738;
v_39739:
    goto v_39733;
v_39734:
    goto v_39735;
v_39736:
    goto v_39737;
v_39738:
    stack[-1] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39724;
v_39725:
    goto v_39750;
v_39744:
    v_40646 = elt(env, 2); // l_a
    goto v_39745;
v_39746:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_39747;
v_39748:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39749;
v_39750:
    goto v_39744;
v_39745:
    goto v_39746;
v_39747:
    goto v_39748;
v_39749:
    stack[0] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39726;
v_39727:
    goto v_39761;
v_39755:
    v_40646 = elt(env, 2); // l_a
    goto v_39756;
v_39757:
    v_40645 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_39758;
v_39759:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_39760;
v_39761:
    goto v_39755;
v_39756:
    goto v_39757;
v_39758:
    goto v_39759;
v_39760:
    v_40645 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39728;
v_39729:
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_39730;
v_39731:
    goto v_39723;
v_39724:
    goto v_39725;
v_39726:
    goto v_39727;
v_39728:
    goto v_39729;
v_39730:
    stack[0] = list4(stack[-1], stack[0], v_40645, v_40644);
    env = stack[-16];
    goto v_39718;
v_39719:
    goto v_39775;
v_39767:
    v_40647 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_39768;
v_39769:
    v_40646 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_39770;
v_39771:
    v_40645 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_39772;
v_39773:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39774;
v_39775:
    goto v_39767;
v_39768:
    goto v_39769;
v_39770:
    goto v_39771;
v_39772:
    goto v_39773;
v_39774:
    v_40644 = list4(v_40647, v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39720;
v_39721:
    goto v_39717;
v_39718:
    goto v_39719;
v_39720:
    v_40644 = list2(stack[0], v_40644);
    env = stack[-16];
    goto v_39625;
v_39626:
    goto v_39618;
v_39619:
    goto v_39620;
v_39621:
    goto v_39622;
v_39623:
    goto v_39624;
v_39625:
    v_40645 = list3star(stack[-4], stack[-3], stack[-2], v_40644);
    env = stack[-16];
    goto v_39612;
v_39613:
    v_40644 = elt(env, 18); // liemat
    goto v_39614;
v_39615:
    goto v_39609;
v_39610:
    goto v_39611;
v_39612:
    goto v_39613;
v_39614:
    v_40644 = list3(stack[-5], v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39604;
v_39605:
    goto v_39601;
v_39602:
    goto v_39603;
v_39604:
    fn = elt(env, 33); // setk
    v_40644 = (*qfn2(fn))(fn, stack[-6], v_40644);
    env = stack[-16];
    goto v_39786;
v_39782:
    stack[0] = elt(env, 20); // bb
    goto v_39783;
v_39784:
    goto v_39796;
v_39790:
    v_40646 = elt(env, 21); // quotient
    goto v_39791;
v_39792:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39793;
v_39794:
    v_40644 = elt(env, 18); // liemat
    goto v_39795;
v_39796:
    goto v_39790;
v_39791:
    goto v_39792;
v_39793:
    goto v_39794;
v_39795:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39785;
v_39786:
    goto v_39782;
v_39783:
    goto v_39784;
v_39785:
    fn = elt(env, 33); // setk
    v_40644 = (*qfn2(fn))(fn, stack[0], v_40644);
    env = stack[-16];
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-12] = v_40644;
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-11] = v_40644;
v_39804:
    goto v_39817;
v_39813:
    v_40645 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_39814;
v_39815:
    v_40644 = stack[-12];
    goto v_39816;
v_39817:
    goto v_39813;
v_39814:
    goto v_39815;
v_39816:
    v_40644 = difference2(v_40645, v_40644);
    env = stack[-16];
    v_40644 = Lminusp(nil, v_40644);
    env = stack[-16];
    if (v_40644 == nil) goto v_39810;
    v_40644 = stack[-11];
    goto v_39803;
v_39810:
    goto v_39829;
v_39823:
    stack[-10] = elt(env, 3); // plus
    goto v_39824;
v_39825:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-9] = v_40644;
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-8] = v_40644;
v_39835:
    goto v_39848;
v_39844:
    v_40645 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_39845;
v_39846:
    v_40644 = stack[-9];
    goto v_39847;
v_39848:
    goto v_39844;
v_39845:
    goto v_39846;
v_39847:
    v_40644 = difference2(v_40645, v_40644);
    env = stack[-16];
    v_40644 = Lminusp(nil, v_40644);
    env = stack[-16];
    if (v_40644 == nil) goto v_39841;
    v_40644 = stack[-8];
    v_40645 = v_40644;
    goto v_39834;
v_39841:
    goto v_39860;
v_39854:
    stack[-7] = elt(env, 3); // plus
    goto v_39855;
v_39856:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_40644;
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_40644;
v_39866:
    goto v_39879;
v_39875:
    v_40645 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_39876;
v_39877:
    v_40644 = stack[-6];
    goto v_39878;
v_39879:
    goto v_39875;
v_39876:
    goto v_39877;
v_39878:
    v_40644 = difference2(v_40645, v_40644);
    env = stack[-16];
    v_40644 = Lminusp(nil, v_40644);
    env = stack[-16];
    if (v_40644 == nil) goto v_39872;
    v_40644 = stack[-5];
    v_40645 = v_40644;
    goto v_39865;
v_39872:
    goto v_39891;
v_39885:
    stack[-4] = elt(env, 3); // plus
    goto v_39886;
v_39887:
    goto v_39903;
v_39895:
    stack[-3] = elt(env, 6); // times
    goto v_39896;
v_39897:
    goto v_39912;
v_39906:
    v_40646 = elt(env, 18); // liemat
    goto v_39907;
v_39908:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_39909;
v_39910:
    v_40644 = stack[-12];
    goto v_39911;
v_39912:
    goto v_39906;
v_39907:
    goto v_39908;
v_39909:
    goto v_39910;
v_39911:
    stack[-2] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39898;
v_39899:
    goto v_39923;
v_39917:
    v_40646 = elt(env, 18); // liemat
    goto v_39918;
v_39919:
    v_40645 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_39920;
v_39921:
    v_40644 = stack[-9];
    goto v_39922;
v_39923:
    goto v_39917;
v_39918:
    goto v_39919;
v_39920:
    goto v_39921;
v_39922:
    stack[-1] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39900;
v_39901:
    goto v_39932;
v_39928:
    goto v_39942;
v_39934:
    v_40647 = elt(env, 22); // cc
    goto v_39935;
v_39936:
    v_40646 = stack[-12];
    goto v_39937;
v_39938:
    v_40645 = stack[-9];
    goto v_39939;
v_39940:
    v_40644 = stack[-6];
    goto v_39941;
v_39942:
    goto v_39934;
v_39935:
    goto v_39936;
v_39937:
    goto v_39938;
v_39939:
    goto v_39940;
v_39941:
    stack[0] = list4(v_40647, v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39929;
v_39930:
    goto v_39954;
v_39948:
    v_40646 = elt(env, 20); // bb
    goto v_39949;
v_39950:
    v_40645 = stack[-6];
    goto v_39951;
v_39952:
    v_40644 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_39953;
v_39954:
    goto v_39948;
v_39949:
    goto v_39950;
v_39951:
    goto v_39952;
v_39953:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_39931;
v_39932:
    goto v_39928;
v_39929:
    goto v_39930;
v_39931:
    v_40644 = list2(stack[0], v_40644);
    env = stack[-16];
    goto v_39902;
v_39903:
    goto v_39895;
v_39896:
    goto v_39897;
v_39898:
    goto v_39899;
v_39900:
    goto v_39901;
v_39902:
    v_40644 = list3star(stack[-3], stack[-2], stack[-1], v_40644);
    env = stack[-16];
    fn = elt(env, 38); // aeval!*
    v_40645 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_39888;
v_39889:
    v_40644 = stack[-5];
    goto v_39890;
v_39891:
    goto v_39885;
v_39886:
    goto v_39887;
v_39888:
    goto v_39889;
v_39890:
    v_40644 = list3(stack[-4], v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 38); // aeval!*
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    stack[-5] = v_40644;
    v_40644 = stack[-6];
    v_40644 = add1(v_40644);
    env = stack[-16];
    stack[-6] = v_40644;
    goto v_39866;
v_39865:
    goto v_39857;
v_39858:
    v_40644 = stack[-8];
    goto v_39859;
v_39860:
    goto v_39854;
v_39855:
    goto v_39856;
v_39857:
    goto v_39858;
v_39859:
    v_40644 = list3(stack[-7], v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 38); // aeval!*
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    stack[-8] = v_40644;
    v_40644 = stack[-9];
    v_40644 = add1(v_40644);
    env = stack[-16];
    stack[-9] = v_40644;
    goto v_39835;
v_39834:
    goto v_39826;
v_39827:
    v_40644 = stack[-11];
    goto v_39828;
v_39829:
    goto v_39823;
v_39824:
    goto v_39825;
v_39826:
    goto v_39827;
v_39828:
    v_40644 = list3(stack[-10], v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 38); // aeval!*
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    stack[-11] = v_40644;
    v_40644 = stack[-12];
    v_40644 = add1(v_40644);
    env = stack[-16];
    stack[-12] = v_40644;
    goto v_39804;
v_39803:
    stack[-14] = v_40644;
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-12] = v_40644;
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-11] = v_40644;
v_39971:
    goto v_39984;
v_39980:
    v_40645 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_39981;
v_39982:
    v_40644 = stack[-12];
    goto v_39983;
v_39984:
    goto v_39980;
v_39981:
    goto v_39982;
v_39983:
    v_40644 = difference2(v_40645, v_40644);
    env = stack[-16];
    v_40644 = Lminusp(nil, v_40644);
    env = stack[-16];
    if (v_40644 == nil) goto v_39977;
    v_40644 = stack[-11];
    goto v_39970;
v_39977:
    goto v_39996;
v_39990:
    stack[-10] = elt(env, 3); // plus
    goto v_39991;
v_39992:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-9] = v_40644;
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-8] = v_40644;
v_40002:
    goto v_40015;
v_40011:
    v_40645 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_40012;
v_40013:
    v_40644 = stack[-9];
    goto v_40014;
v_40015:
    goto v_40011;
v_40012:
    goto v_40013;
v_40014:
    v_40644 = difference2(v_40645, v_40644);
    env = stack[-16];
    v_40644 = Lminusp(nil, v_40644);
    env = stack[-16];
    if (v_40644 == nil) goto v_40008;
    v_40644 = stack[-8];
    v_40645 = v_40644;
    goto v_40001;
v_40008:
    goto v_40027;
v_40021:
    stack[-7] = elt(env, 3); // plus
    goto v_40022;
v_40023:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_40644;
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_40644;
v_40033:
    goto v_40046;
v_40042:
    v_40645 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_40043;
v_40044:
    v_40644 = stack[-6];
    goto v_40045;
v_40046:
    goto v_40042;
v_40043:
    goto v_40044;
v_40045:
    v_40644 = difference2(v_40645, v_40644);
    env = stack[-16];
    v_40644 = Lminusp(nil, v_40644);
    env = stack[-16];
    if (v_40644 == nil) goto v_40039;
    v_40644 = stack[-5];
    v_40645 = v_40644;
    goto v_40032;
v_40039:
    goto v_40058;
v_40052:
    stack[-4] = elt(env, 3); // plus
    goto v_40053;
v_40054:
    goto v_40070;
v_40062:
    stack[-3] = elt(env, 6); // times
    goto v_40063;
v_40064:
    goto v_40079;
v_40073:
    v_40646 = elt(env, 18); // liemat
    goto v_40074;
v_40075:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_40076;
v_40077:
    v_40644 = stack[-12];
    goto v_40078;
v_40079:
    goto v_40073;
v_40074:
    goto v_40075;
v_40076:
    goto v_40077;
v_40078:
    stack[-2] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_40065;
v_40066:
    goto v_40090;
v_40084:
    v_40646 = elt(env, 18); // liemat
    goto v_40085;
v_40086:
    v_40645 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_40087;
v_40088:
    v_40644 = stack[-9];
    goto v_40089;
v_40090:
    goto v_40084;
v_40085:
    goto v_40086;
v_40087:
    goto v_40088;
v_40089:
    stack[-1] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_40067;
v_40068:
    goto v_40099;
v_40095:
    goto v_40109;
v_40101:
    v_40647 = elt(env, 22); // cc
    goto v_40102;
v_40103:
    v_40646 = stack[-12];
    goto v_40104;
v_40105:
    v_40645 = stack[-9];
    goto v_40106;
v_40107:
    v_40644 = stack[-6];
    goto v_40108;
v_40109:
    goto v_40101;
v_40102:
    goto v_40103;
v_40104:
    goto v_40105;
v_40106:
    goto v_40107;
v_40108:
    stack[0] = list4(v_40647, v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_40096;
v_40097:
    goto v_40121;
v_40115:
    v_40646 = elt(env, 20); // bb
    goto v_40116;
v_40117:
    v_40645 = stack[-6];
    goto v_40118;
v_40119:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_40120;
v_40121:
    goto v_40115;
v_40116:
    goto v_40117;
v_40118:
    goto v_40119;
v_40120:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_40098;
v_40099:
    goto v_40095;
v_40096:
    goto v_40097;
v_40098:
    v_40644 = list2(stack[0], v_40644);
    env = stack[-16];
    goto v_40069;
v_40070:
    goto v_40062;
v_40063:
    goto v_40064;
v_40065:
    goto v_40066;
v_40067:
    goto v_40068;
v_40069:
    v_40644 = list3star(stack[-3], stack[-2], stack[-1], v_40644);
    env = stack[-16];
    fn = elt(env, 38); // aeval!*
    v_40645 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_40055;
v_40056:
    v_40644 = stack[-5];
    goto v_40057;
v_40058:
    goto v_40052;
v_40053:
    goto v_40054;
v_40055:
    goto v_40056;
v_40057:
    v_40644 = list3(stack[-4], v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 38); // aeval!*
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    stack[-5] = v_40644;
    v_40644 = stack[-6];
    v_40644 = add1(v_40644);
    env = stack[-16];
    stack[-6] = v_40644;
    goto v_40033;
v_40032:
    goto v_40024;
v_40025:
    v_40644 = stack[-8];
    goto v_40026;
v_40027:
    goto v_40021;
v_40022:
    goto v_40023;
v_40024:
    goto v_40025;
v_40026:
    v_40644 = list3(stack[-7], v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 38); // aeval!*
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    stack[-8] = v_40644;
    v_40644 = stack[-9];
    v_40644 = add1(v_40644);
    env = stack[-16];
    stack[-9] = v_40644;
    goto v_40002;
v_40001:
    goto v_39993;
v_39994:
    v_40644 = stack[-11];
    goto v_39995;
v_39996:
    goto v_39990;
v_39991:
    goto v_39992;
v_39993:
    goto v_39994;
v_39995:
    v_40644 = list3(stack[-10], v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 38); // aeval!*
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    stack[-11] = v_40644;
    v_40644 = stack[-12];
    v_40644 = add1(v_40644);
    env = stack[-16];
    stack[-12] = v_40644;
    goto v_39971;
v_39970:
    stack[-13] = v_40644;
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-12] = v_40644;
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-11] = v_40644;
v_40138:
    goto v_40151;
v_40147:
    v_40645 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_40148;
v_40149:
    v_40644 = stack[-12];
    goto v_40150;
v_40151:
    goto v_40147;
v_40148:
    goto v_40149;
v_40150:
    v_40644 = difference2(v_40645, v_40644);
    env = stack[-16];
    v_40644 = Lminusp(nil, v_40644);
    env = stack[-16];
    if (v_40644 == nil) goto v_40144;
    v_40644 = stack[-11];
    goto v_40137;
v_40144:
    goto v_40163;
v_40157:
    stack[-10] = elt(env, 3); // plus
    goto v_40158;
v_40159:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-9] = v_40644;
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-8] = v_40644;
v_40169:
    goto v_40182;
v_40178:
    v_40645 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_40179;
v_40180:
    v_40644 = stack[-9];
    goto v_40181;
v_40182:
    goto v_40178;
v_40179:
    goto v_40180;
v_40181:
    v_40644 = difference2(v_40645, v_40644);
    env = stack[-16];
    v_40644 = Lminusp(nil, v_40644);
    env = stack[-16];
    if (v_40644 == nil) goto v_40175;
    v_40644 = stack[-8];
    v_40645 = v_40644;
    goto v_40168;
v_40175:
    goto v_40194;
v_40188:
    stack[-7] = elt(env, 3); // plus
    goto v_40189;
v_40190:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_40644;
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_40644;
v_40200:
    goto v_40213;
v_40209:
    v_40645 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_40210;
v_40211:
    v_40644 = stack[-6];
    goto v_40212;
v_40213:
    goto v_40209;
v_40210:
    goto v_40211;
v_40212:
    v_40644 = difference2(v_40645, v_40644);
    env = stack[-16];
    v_40644 = Lminusp(nil, v_40644);
    env = stack[-16];
    if (v_40644 == nil) goto v_40206;
    v_40644 = stack[-5];
    v_40645 = v_40644;
    goto v_40199;
v_40206:
    goto v_40225;
v_40219:
    stack[-4] = elt(env, 3); // plus
    goto v_40220;
v_40221:
    goto v_40237;
v_40229:
    stack[-3] = elt(env, 6); // times
    goto v_40230;
v_40231:
    goto v_40246;
v_40240:
    v_40646 = elt(env, 18); // liemat
    goto v_40241;
v_40242:
    v_40645 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_40243;
v_40244:
    v_40644 = stack[-12];
    goto v_40245;
v_40246:
    goto v_40240;
v_40241:
    goto v_40242;
v_40243:
    goto v_40244;
v_40245:
    stack[-2] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_40232;
v_40233:
    goto v_40257;
v_40251:
    v_40646 = elt(env, 18); // liemat
    goto v_40252;
v_40253:
    v_40645 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_40254;
v_40255:
    v_40644 = stack[-9];
    goto v_40256;
v_40257:
    goto v_40251;
v_40252:
    goto v_40253;
v_40254:
    goto v_40255;
v_40256:
    stack[-1] = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_40234;
v_40235:
    goto v_40266;
v_40262:
    goto v_40276;
v_40268:
    v_40647 = elt(env, 22); // cc
    goto v_40269;
v_40270:
    v_40646 = stack[-12];
    goto v_40271;
v_40272:
    v_40645 = stack[-9];
    goto v_40273;
v_40274:
    v_40644 = stack[-6];
    goto v_40275;
v_40276:
    goto v_40268;
v_40269:
    goto v_40270;
v_40271:
    goto v_40272;
v_40273:
    goto v_40274;
v_40275:
    stack[0] = list4(v_40647, v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_40263;
v_40264:
    goto v_40288;
v_40282:
    v_40646 = elt(env, 20); // bb
    goto v_40283;
v_40284:
    v_40645 = stack[-6];
    goto v_40285;
v_40286:
    v_40644 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_40287;
v_40288:
    goto v_40282;
v_40283:
    goto v_40284;
v_40285:
    goto v_40286;
v_40287:
    v_40644 = list3(v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_40265;
v_40266:
    goto v_40262;
v_40263:
    goto v_40264;
v_40265:
    v_40644 = list2(stack[0], v_40644);
    env = stack[-16];
    goto v_40236;
v_40237:
    goto v_40229;
v_40230:
    goto v_40231;
v_40232:
    goto v_40233;
v_40234:
    goto v_40235;
v_40236:
    v_40644 = list3star(stack[-3], stack[-2], stack[-1], v_40644);
    env = stack[-16];
    fn = elt(env, 38); // aeval!*
    v_40645 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_40222;
v_40223:
    v_40644 = stack[-5];
    goto v_40224;
v_40225:
    goto v_40219;
v_40220:
    goto v_40221;
v_40222:
    goto v_40223;
v_40224:
    v_40644 = list3(stack[-4], v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 38); // aeval!*
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    stack[-5] = v_40644;
    v_40644 = stack[-6];
    v_40644 = add1(v_40644);
    env = stack[-16];
    stack[-6] = v_40644;
    goto v_40200;
v_40199:
    goto v_40191;
v_40192:
    v_40644 = stack[-8];
    goto v_40193;
v_40194:
    goto v_40188;
v_40189:
    goto v_40190;
v_40191:
    goto v_40192;
v_40193:
    v_40644 = list3(stack[-7], v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 38); // aeval!*
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    stack[-8] = v_40644;
    v_40644 = stack[-9];
    v_40644 = add1(v_40644);
    env = stack[-16];
    stack[-9] = v_40644;
    goto v_40169;
v_40168:
    goto v_40160;
v_40161:
    v_40644 = stack[-11];
    goto v_40162;
v_40163:
    goto v_40157;
v_40158:
    goto v_40159;
v_40160:
    goto v_40161;
v_40162:
    v_40644 = list3(stack[-10], v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 38); // aeval!*
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    stack[-11] = v_40644;
    v_40644 = stack[-12];
    v_40644 = add1(v_40644);
    env = stack[-16];
    stack[-12] = v_40644;
    goto v_40138;
v_40137:
    stack[0] = v_40644;
    goto v_40309;
v_40305:
    v_40645 = stack[-15];
    goto v_40306;
v_40307:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_40308;
v_40309:
    goto v_40305;
v_40306:
    goto v_40307;
v_40308:
    if (v_40645 == v_40644) goto v_40303;
    else goto v_40304;
v_40303:
    goto v_40317;
v_40313:
    stack[-6] = elt(env, 18); // liemat
    goto v_40314;
v_40315:
    goto v_40327;
v_40321:
    stack[-5] = elt(env, 6); // times
    goto v_40322;
v_40323:
    goto v_40338;
v_40330:
    stack[-4] = elt(env, 19); // mat
    goto v_40331;
v_40332:
    goto v_40349;
v_40341:
    v_40647 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_40342;
v_40343:
    v_40646 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_40344;
v_40345:
    v_40645 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_40346;
v_40347:
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_40348;
v_40349:
    goto v_40341;
v_40342:
    goto v_40343;
v_40344:
    goto v_40345;
v_40346:
    goto v_40347;
v_40348:
    stack[-3] = list4(v_40647, v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_40333;
v_40334:
    goto v_40363;
v_40355:
    v_40647 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_40356;
v_40357:
    v_40646 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_40358;
v_40359:
    v_40645 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_40360;
v_40361:
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_40362;
v_40363:
    goto v_40355;
v_40356:
    goto v_40357;
v_40358:
    goto v_40359;
v_40360:
    goto v_40361;
v_40362:
    stack[-2] = list4(v_40647, v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_40335;
v_40336:
    goto v_40373;
v_40369:
    goto v_40383;
v_40375:
    v_40647 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_40376;
v_40377:
    v_40646 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_40378;
v_40379:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_40380;
v_40381:
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_40382;
v_40383:
    goto v_40375;
v_40376:
    goto v_40377;
v_40378:
    goto v_40379;
v_40380:
    goto v_40381;
v_40382:
    stack[-1] = list4(v_40647, v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_40370;
v_40371:
    goto v_40397;
v_40389:
    goto v_40390;
v_40391:
    goto v_40404;
v_40400:
    v_40645 = elt(env, 7); // minus
    goto v_40401;
v_40402:
    v_40644 = stack[-13];
    goto v_40403;
v_40404:
    goto v_40400;
v_40401:
    goto v_40402;
v_40403:
    v_40646 = list2(v_40645, v_40644);
    env = stack[-16];
    goto v_40392;
v_40393:
    v_40645 = stack[-14];
    goto v_40394;
v_40395:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_40396;
v_40397:
    goto v_40389;
v_40390:
    goto v_40391;
v_40392:
    goto v_40393;
v_40394:
    goto v_40395;
v_40396:
    v_40644 = list4(stack[0], v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_40372;
v_40373:
    goto v_40369;
v_40370:
    goto v_40371;
v_40372:
    v_40644 = list2(stack[-1], v_40644);
    env = stack[-16];
    goto v_40337;
v_40338:
    goto v_40330;
v_40331:
    goto v_40332;
v_40333:
    goto v_40334;
v_40335:
    goto v_40336;
v_40337:
    v_40645 = list3star(stack[-4], stack[-3], stack[-2], v_40644);
    env = stack[-16];
    goto v_40324;
v_40325:
    v_40644 = elt(env, 18); // liemat
    goto v_40326;
v_40327:
    goto v_40321;
v_40322:
    goto v_40323;
v_40324:
    goto v_40325;
v_40326:
    v_40644 = list3(stack[-5], v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_40316;
v_40317:
    goto v_40313;
v_40314:
    goto v_40315;
v_40316:
    fn = elt(env, 33); // setk
    v_40644 = (*qfn2(fn))(fn, stack[-6], v_40644);
    env = stack[-16];
    goto v_40302;
v_40304:
    goto v_40417;
v_40413:
    stack[-6] = elt(env, 18); // liemat
    goto v_40414;
v_40415:
    goto v_40427;
v_40421:
    stack[-5] = elt(env, 6); // times
    goto v_40422;
v_40423:
    goto v_40438;
v_40430:
    stack[-4] = elt(env, 19); // mat
    goto v_40431;
v_40432:
    goto v_40449;
v_40441:
    v_40647 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_40442;
v_40443:
    v_40646 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_40444;
v_40445:
    v_40645 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_40446;
v_40447:
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_40448;
v_40449:
    goto v_40441;
v_40442:
    goto v_40443;
v_40444:
    goto v_40445;
v_40446:
    goto v_40447;
v_40448:
    stack[-3] = list4(v_40647, v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_40433;
v_40434:
    goto v_40463;
v_40455:
    v_40647 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_40456;
v_40457:
    v_40646 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_40458;
v_40459:
    v_40645 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_40460;
v_40461:
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_40462;
v_40463:
    goto v_40455;
v_40456:
    goto v_40457;
v_40458:
    goto v_40459;
v_40460:
    goto v_40461;
v_40462:
    stack[-2] = list4(v_40647, v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_40435;
v_40436:
    goto v_40473;
v_40469:
    goto v_40483;
v_40475:
    v_40647 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_40476;
v_40477:
    v_40646 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_40478;
v_40479:
    v_40645 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_40480;
v_40481:
    v_40644 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_40482;
v_40483:
    goto v_40475;
v_40476:
    goto v_40477;
v_40478:
    goto v_40479;
v_40480:
    goto v_40481;
v_40482:
    stack[-1] = list4(v_40647, v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_40470;
v_40471:
    goto v_40497;
v_40489:
    goto v_40490;
v_40491:
    goto v_40504;
v_40500:
    v_40645 = elt(env, 7); // minus
    goto v_40501;
v_40502:
    v_40644 = stack[-13];
    goto v_40503;
v_40504:
    goto v_40500;
v_40501:
    goto v_40502;
v_40503:
    stack[-7] = list2(v_40645, v_40644);
    env = stack[-16];
    goto v_40492;
v_40493:
    goto v_40512;
v_40508:
    v_40645 = elt(env, 7); // minus
    goto v_40509;
v_40510:
    v_40644 = stack[-14];
    goto v_40511;
v_40512:
    goto v_40508;
v_40509:
    goto v_40510;
v_40511:
    v_40645 = list2(v_40645, v_40644);
    env = stack[-16];
    goto v_40494;
v_40495:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_40496;
v_40497:
    goto v_40489;
v_40490:
    goto v_40491;
v_40492:
    goto v_40493;
v_40494:
    goto v_40495;
v_40496:
    v_40644 = list4(stack[0], stack[-7], v_40645, v_40644);
    env = stack[-16];
    goto v_40472;
v_40473:
    goto v_40469;
v_40470:
    goto v_40471;
v_40472:
    v_40644 = list2(stack[-1], v_40644);
    env = stack[-16];
    goto v_40437;
v_40438:
    goto v_40430;
v_40431:
    goto v_40432;
v_40433:
    goto v_40434;
v_40435:
    goto v_40436;
v_40437:
    v_40645 = list3star(stack[-4], stack[-3], stack[-2], v_40644);
    env = stack[-16];
    goto v_40424;
v_40425:
    v_40644 = elt(env, 18); // liemat
    goto v_40426;
v_40427:
    goto v_40421;
v_40422:
    goto v_40423;
v_40424:
    goto v_40425;
v_40426:
    v_40644 = list3(stack[-5], v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_40416;
v_40417:
    goto v_40413;
v_40414:
    goto v_40415;
v_40416:
    fn = elt(env, 33); // setk
    v_40644 = (*qfn2(fn))(fn, stack[-6], v_40644);
    env = stack[-16];
    goto v_40302;
v_40302:
    goto v_40525;
v_40521:
    v_40645 = stack[-15];
    goto v_40522;
v_40523:
    v_40644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_40524;
v_40525:
    goto v_40521;
v_40522:
    goto v_40523;
v_40524:
    if (v_40645 == v_40644) goto v_40519;
    else goto v_40520;
v_40519:
    v_40644 = qvalue(elt(env, 23)); // !*tr_lie
    fn = elt(env, 39); // revalx
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    fn = elt(env, 40); // boolvalue!*
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    if (v_40644 == nil) goto v_40531;
    goto v_40542;
v_40536:
    v_40644 = elt(env, 24); // "[W,X]=Y, [W,Y]=-X, [X,Y]=W"
    fn = elt(env, 32); // aeval
    v_40646 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_40537;
v_40538:
    v_40645 = nil;
    goto v_40539;
v_40540:
    v_40644 = elt(env, 25); // only
    goto v_40541;
v_40542:
    goto v_40536;
v_40537:
    goto v_40538;
v_40539:
    goto v_40540;
v_40541:
    fn = elt(env, 35); // assgnpri
    v_40644 = (*qfnn(fn))(fn, 3, v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_40529;
v_40531:
v_40529:
    goto v_40552;
v_40548:
    stack[-2] = elt(env, 26); // lie_class
    goto v_40549;
v_40550:
    goto v_40562;
v_40556:
    stack[-1] = elt(env, 27); // list
    goto v_40557;
v_40558:
    goto v_40569;
v_40565:
    v_40645 = elt(env, 28); // liealg
    goto v_40566;
v_40567:
    v_40644 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_40568;
v_40569:
    goto v_40565;
v_40566:
    goto v_40567;
v_40568:
    stack[0] = list2(v_40645, v_40644);
    env = stack[-16];
    goto v_40559;
v_40560:
    goto v_40577;
v_40573:
    v_40645 = elt(env, 29); // comtab
    goto v_40574;
v_40575:
    v_40644 = (LispObject)336+TAG_FIXNUM; // 21
    goto v_40576;
v_40577:
    goto v_40573;
v_40574:
    goto v_40575;
v_40576:
    v_40644 = list2(v_40645, v_40644);
    env = stack[-16];
    goto v_40561;
v_40562:
    goto v_40556;
v_40557:
    goto v_40558;
v_40559:
    goto v_40560;
v_40561:
    v_40644 = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_40551;
v_40552:
    goto v_40548;
v_40549:
    goto v_40550;
v_40551:
    fn = elt(env, 33); // setk
    v_40644 = (*qfn2(fn))(fn, stack[-2], v_40644);
    env = stack[-16];
    goto v_40518;
v_40520:
    v_40644 = qvalue(elt(env, 23)); // !*tr_lie
    fn = elt(env, 39); // revalx
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    fn = elt(env, 40); // boolvalue!*
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    if (v_40644 == nil) goto v_40585;
    goto v_40596;
v_40590:
    v_40644 = elt(env, 30); // "[W,X]=Y, [W,Y]=X, [X,Y]=W"
    fn = elt(env, 32); // aeval
    v_40646 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_40591;
v_40592:
    v_40645 = nil;
    goto v_40593;
v_40594:
    v_40644 = elt(env, 25); // only
    goto v_40595;
v_40596:
    goto v_40590;
v_40591:
    goto v_40592;
v_40593:
    goto v_40594;
v_40595:
    fn = elt(env, 35); // assgnpri
    v_40644 = (*qfnn(fn))(fn, 3, v_40646, v_40645, v_40644);
    env = stack[-16];
    goto v_40583;
v_40585:
v_40583:
    goto v_40606;
v_40602:
    stack[-2] = elt(env, 26); // lie_class
    goto v_40603;
v_40604:
    goto v_40616;
v_40610:
    stack[-1] = elt(env, 27); // list
    goto v_40611;
v_40612:
    goto v_40623;
v_40619:
    v_40645 = elt(env, 28); // liealg
    goto v_40620;
v_40621:
    v_40644 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_40622;
v_40623:
    goto v_40619;
v_40620:
    goto v_40621;
v_40622:
    stack[0] = list2(v_40645, v_40644);
    env = stack[-16];
    goto v_40613;
v_40614:
    goto v_40631;
v_40627:
    v_40645 = elt(env, 29); // comtab
    goto v_40628;
v_40629:
    v_40644 = (LispObject)352+TAG_FIXNUM; // 22
    goto v_40630;
v_40631:
    goto v_40627;
v_40628:
    goto v_40629;
v_40630:
    v_40644 = list2(v_40645, v_40644);
    env = stack[-16];
    goto v_40615;
v_40616:
    goto v_40610;
v_40611:
    goto v_40612;
v_40613:
    goto v_40614;
v_40615:
    v_40644 = list3(stack[-1], stack[0], v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    goto v_40605;
v_40606:
    goto v_40602;
v_40603:
    goto v_40604;
v_40605:
    fn = elt(env, 33); // setk
    v_40644 = (*qfn2(fn))(fn, stack[-2], v_40644);
    env = stack[-16];
    goto v_40518;
v_40518:
    goto v_40641;
v_40637:
    v_40645 = elt(env, 1); // l_k
    goto v_40638;
v_40639:
    v_40644 = elt(env, 2); // l_a
    goto v_40640;
v_40641:
    goto v_40637;
v_40638:
    goto v_40639;
v_40640:
    v_40644 = list2(v_40645, v_40644);
    env = stack[-16];
    fn = elt(env, 41); // clear
    v_40644 = (*qfn1(fn))(fn, v_40644);
    env = stack[-16];
    fn = elt(env, 32); // aeval
    v_40644 = (*qfn1(fn))(fn, v_40644);
    v_40644 = nil;
    return onevalue(v_40644);
}



// Code for pst_partition

static LispObject CC_pst_partition(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_38308, v_38309, v_38310;
    LispObject fn;
    LispObject v_38179, v_38178, v_38177;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pst_partition");
    va_start(aa, nargs);
    v_38177 = va_arg(aa, LispObject);
    v_38178 = va_arg(aa, LispObject);
    v_38179 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_38179,v_38178,v_38177);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_38177,v_38178,v_38179);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_38179;
    stack[-4] = v_38178;
    v_38308 = v_38177;
// end of prologue
    stack[-5] = nil;
    stack[-2] = v_38308;
v_38189:
    v_38308 = stack[-2];
    if (v_38308 == nil) goto v_38193;
    else goto v_38194;
v_38193:
    goto v_38188;
v_38194:
    v_38308 = stack[-2];
    v_38308 = qcar(v_38308);
    stack[-1] = v_38308;
    goto v_38207;
v_38201:
    v_38310 = stack[-1];
    goto v_38202;
v_38203:
    v_38309 = stack[-4];
    goto v_38204;
v_38205:
    v_38308 = stack[-3];
    goto v_38206;
v_38207:
    goto v_38201;
v_38202:
    goto v_38203;
v_38204:
    goto v_38205;
v_38206:
    fn = elt(env, 2); // pst_d
    v_38308 = (*qfnn(fn))(fn, 3, v_38310, v_38309, v_38308);
    env = stack[-6];
    v_38309 = v_38308;
    goto v_38219;
v_38215:
    v_38310 = v_38309;
    goto v_38216;
v_38217:
    v_38308 = stack[-5];
    goto v_38218;
v_38219:
    goto v_38215;
v_38216:
    goto v_38217;
v_38218:
    v_38308 = Lassoc(nil, v_38310, v_38308);
    v_38310 = v_38308;
    if (v_38308 == nil) goto v_38214;
    goto v_38228;
v_38224:
    stack[0] = v_38310;
    goto v_38225;
v_38226:
    goto v_38235;
v_38231:
    v_38308 = stack[-1];
    goto v_38232;
v_38233:
    v_38309 = v_38310;
    v_38309 = qcdr(v_38309);
    goto v_38234;
v_38235:
    goto v_38231;
v_38232:
    goto v_38233;
v_38234:
    v_38308 = cons(v_38308, v_38309);
    env = stack[-6];
    goto v_38227;
v_38228:
    goto v_38224;
v_38225:
    goto v_38226;
v_38227:
    v_38308 = Lrplacd(nil, stack[0], v_38308);
    env = stack[-6];
    goto v_38212;
v_38214:
    goto v_38248;
v_38242:
    stack[0] = v_38309;
    goto v_38243;
v_38244:
    v_38308 = stack[-1];
    v_38309 = ncons(v_38308);
    env = stack[-6];
    goto v_38245;
v_38246:
    v_38308 = stack[-5];
    goto v_38247;
v_38248:
    goto v_38242;
v_38243:
    goto v_38244;
v_38245:
    goto v_38246;
v_38247:
    v_38308 = acons(stack[0], v_38309, v_38308);
    env = stack[-6];
    stack[-5] = v_38308;
    goto v_38212;
v_38212:
    v_38308 = stack[-2];
    v_38308 = qcdr(v_38308);
    stack[-2] = v_38308;
    goto v_38189;
v_38188:
    goto v_38261;
v_38257:
    v_38309 = stack[-5];
    goto v_38258;
v_38259:
    v_38308 = elt(env, 1); // lambda_sorneshiwvd12
    goto v_38260;
v_38261:
    goto v_38257;
v_38258:
    goto v_38259;
v_38260:
    fn = elt(env, 3); // sort
    v_38308 = (*qfn2(fn))(fn, v_38309, v_38308);
    env = stack[-6];
    stack[-5] = v_38308;
    v_38308 = stack[-5];
    stack[-3] = v_38308;
    v_38308 = stack[-3];
    if (v_38308 == nil) goto v_38273;
    else goto v_38274;
v_38273:
    v_38308 = nil;
    goto v_38268;
v_38274:
    v_38308 = stack[-3];
    v_38308 = qcar(v_38308);
    v_38308 = qcdr(v_38308);
    v_38308 = Lreverse(nil, v_38308);
    env = stack[-6];
    v_38308 = ncons(v_38308);
    env = stack[-6];
    stack[-1] = v_38308;
    stack[-2] = v_38308;
v_38269:
    v_38308 = stack[-3];
    v_38308 = qcdr(v_38308);
    stack[-3] = v_38308;
    v_38308 = stack[-3];
    if (v_38308 == nil) goto v_38288;
    else goto v_38289;
v_38288:
    v_38308 = stack[-2];
    goto v_38268;
v_38289:
    goto v_38297;
v_38293:
    stack[0] = stack[-1];
    goto v_38294;
v_38295:
    v_38308 = stack[-3];
    v_38308 = qcar(v_38308);
    v_38308 = qcdr(v_38308);
    v_38308 = Lreverse(nil, v_38308);
    env = stack[-6];
    v_38308 = ncons(v_38308);
    env = stack[-6];
    goto v_38296;
v_38297:
    goto v_38293;
v_38294:
    goto v_38295;
v_38296:
    v_38308 = Lrplacd(nil, stack[0], v_38308);
    env = stack[-6];
    v_38308 = stack[-1];
    v_38308 = qcdr(v_38308);
    stack[-1] = v_38308;
    goto v_38269;
v_38268:
    return onevalue(v_38308);
}



// Code for lambda_sorneshiwvd12

static LispObject CC_lambda_sorneshiwvd12(LispObject env,
                         LispObject v_38177, LispObject v_38178)
{
    env = qenv(env);
    LispObject v_38190, v_38191;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_38190 = v_38178;
    v_38191 = v_38177;
// end of prologue
    goto v_38185;
v_38181:
    v_38191 = qcar(v_38191);
    goto v_38182;
v_38183:
    v_38190 = qcar(v_38190);
    goto v_38184;
v_38185:
    goto v_38181;
v_38182:
    goto v_38183;
v_38184:
    {
        fn = elt(env, 1); // numlist_ordp
        return (*qfn2(fn))(fn, v_38191, v_38190);
    }
}



// Code for ratleqp

static LispObject CC_ratleqp(LispObject env,
                         LispObject v_38177, LispObject v_38178)
{
    env = qenv(env);
    LispObject v_38196, v_38197;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_38178,v_38177);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_38177,v_38178);
    }
// copy arguments values to proper place
    v_38196 = v_38178;
    v_38197 = v_38177;
// end of prologue
    goto v_38185;
v_38181:
    goto v_38191;
v_38187:
    goto v_38188;
v_38189:
    goto v_38190;
v_38191:
    goto v_38187;
v_38188:
    goto v_38189;
v_38190:
    fn = elt(env, 1); // ratdif
    v_38196 = (*qfn2(fn))(fn, v_38197, v_38196);
    v_38197 = qcar(v_38196);
    goto v_38182;
v_38183:
    v_38196 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_38184;
v_38185:
    goto v_38181;
v_38182:
    goto v_38183;
v_38184:
        return Lleq(nil, v_38197, v_38196);
}



// Code for reduce!-eival!-powers1

static LispObject CC_reduceKeivalKpowers1(LispObject env,
                         LispObject v_38177, LispObject v_38178)
{
    env = qenv(env);
    LispObject v_38352, v_38353;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_38178,v_38177);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_38177,v_38178);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_38178;
    stack[-1] = v_38177;
// end of prologue
v_38182:
    v_38352 = stack[0];
    v_38352 = qcar(v_38352);
    if (!consp(v_38352)) goto v_38193;
    else goto v_38194;
v_38193:
    v_38352 = lisp_true;
    goto v_38192;
v_38194:
    v_38352 = stack[0];
    v_38352 = qcar(v_38352);
    v_38352 = qcar(v_38352);
    v_38352 = (consp(v_38352) ? nil : lisp_true);
    goto v_38192;
    v_38352 = nil;
v_38192:
    if (v_38352 == nil) goto v_38190;
    v_38352 = lisp_true;
    goto v_38188;
v_38190:
    goto v_38212;
v_38208:
    v_38352 = stack[0];
    v_38352 = qcar(v_38352);
    v_38352 = qcar(v_38352);
    v_38352 = qcar(v_38352);
    v_38353 = qcdr(v_38352);
    goto v_38209;
v_38210:
    v_38352 = stack[-1];
    v_38352 = qcar(v_38352);
    v_38352 = qcdr(v_38352);
    goto v_38211;
v_38212:
    goto v_38208;
v_38209:
    goto v_38210;
v_38211:
    v_38352 = (LispObject)lessp2(v_38353, v_38352);
    v_38352 = v_38352 ? lisp_true : nil;
    env = stack[-3];
    goto v_38188;
    v_38352 = nil;
v_38188:
    if (v_38352 == nil) goto v_38186;
    v_38352 = stack[0];
    goto v_38181;
v_38186:
    goto v_38228;
v_38224:
    v_38352 = stack[0];
    v_38352 = qcar(v_38352);
    v_38352 = qcar(v_38352);
    v_38352 = qcar(v_38352);
    v_38353 = qcdr(v_38352);
    goto v_38225;
v_38226:
    v_38352 = stack[-1];
    v_38352 = qcar(v_38352);
    v_38352 = qcdr(v_38352);
    goto v_38227;
v_38228:
    goto v_38224;
v_38225:
    goto v_38226;
v_38227:
    if (equal(v_38353, v_38352)) goto v_38222;
    else goto v_38223;
v_38222:
    goto v_38242;
v_38238:
    goto v_38248;
v_38244:
    v_38352 = stack[-1];
    stack[-1] = qcdr(v_38352);
    goto v_38245;
v_38246:
    goto v_38256;
v_38252:
    v_38352 = stack[0];
    v_38352 = qcar(v_38352);
    v_38352 = qcar(v_38352);
    v_38353 = qcdr(v_38352);
    goto v_38253;
v_38254:
    v_38352 = stack[0];
    v_38352 = qcdr(v_38352);
    goto v_38255;
v_38256:
    goto v_38252;
v_38253:
    goto v_38254;
v_38255:
    v_38352 = cons(v_38353, v_38352);
    env = stack[-3];
    goto v_38247;
v_38248:
    goto v_38244;
v_38245:
    goto v_38246;
v_38247:
    fn = elt(env, 1); // multsq
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_38352);
    env = stack[-3];
    goto v_38239;
v_38240:
    goto v_38268;
v_38264:
    v_38352 = stack[0];
    v_38352 = qcar(v_38352);
    v_38353 = qcdr(v_38352);
    goto v_38265;
v_38266:
    v_38352 = stack[0];
    v_38352 = qcdr(v_38352);
    goto v_38267;
v_38268:
    goto v_38264;
v_38265:
    goto v_38266;
v_38267:
    v_38352 = cons(v_38353, v_38352);
    env = stack[-3];
    goto v_38241;
v_38242:
    goto v_38238;
v_38239:
    goto v_38240;
v_38241:
    {
        LispObject v_38357 = stack[-1];
        fn = elt(env, 2); // addsq
        return (*qfn2(fn))(fn, v_38357, v_38352);
    }
v_38223:
    goto v_38281;
v_38277:
    goto v_38287;
v_38283:
    goto v_38293;
v_38289:
    goto v_38299;
v_38295:
    goto v_38306;
v_38302:
    goto v_38312;
v_38308:
    v_38352 = stack[0];
    v_38352 = qcar(v_38352);
    v_38352 = qcar(v_38352);
    v_38352 = qcar(v_38352);
    stack[-2] = qcar(v_38352);
    goto v_38309;
v_38310:
    goto v_38323;
v_38319:
    v_38352 = stack[0];
    v_38352 = qcar(v_38352);
    v_38352 = qcar(v_38352);
    v_38352 = qcar(v_38352);
    v_38353 = qcdr(v_38352);
    goto v_38320;
v_38321:
    v_38352 = stack[-1];
    v_38352 = qcar(v_38352);
    v_38352 = qcdr(v_38352);
    goto v_38322;
v_38323:
    goto v_38319;
v_38320:
    goto v_38321;
v_38322:
    v_38352 = difference2(v_38353, v_38352);
    env = stack[-3];
    goto v_38311;
v_38312:
    goto v_38308;
v_38309:
    goto v_38310;
v_38311:
    fn = elt(env, 3); // to
    v_38353 = (*qfn2(fn))(fn, stack[-2], v_38352);
    env = stack[-3];
    goto v_38303;
v_38304:
    v_38352 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38305;
v_38306:
    goto v_38302;
v_38303:
    goto v_38304;
v_38305:
    v_38352 = cons(v_38353, v_38352);
    env = stack[-3];
    v_38353 = ncons(v_38352);
    env = stack[-3];
    goto v_38296;
v_38297:
    v_38352 = stack[0];
    v_38352 = qcar(v_38352);
    v_38352 = qcar(v_38352);
    v_38352 = qcdr(v_38352);
    goto v_38298;
v_38299:
    goto v_38295;
v_38296:
    goto v_38297;
v_38298:
    fn = elt(env, 4); // multf
    v_38353 = (*qfn2(fn))(fn, v_38353, v_38352);
    env = stack[-3];
    goto v_38290;
v_38291:
    v_38352 = stack[0];
    v_38352 = qcdr(v_38352);
    goto v_38292;
v_38293:
    goto v_38289;
v_38290:
    goto v_38291;
v_38292:
    v_38353 = cons(v_38353, v_38352);
    env = stack[-3];
    goto v_38284;
v_38285:
    v_38352 = stack[-1];
    v_38352 = qcdr(v_38352);
    goto v_38286;
v_38287:
    goto v_38283;
v_38284:
    goto v_38285;
v_38286:
    fn = elt(env, 1); // multsq
    stack[-2] = (*qfn2(fn))(fn, v_38353, v_38352);
    env = stack[-3];
    goto v_38278;
v_38279:
    goto v_38346;
v_38342:
    v_38352 = stack[0];
    v_38352 = qcar(v_38352);
    v_38353 = qcdr(v_38352);
    goto v_38343;
v_38344:
    v_38352 = stack[0];
    v_38352 = qcdr(v_38352);
    goto v_38345;
v_38346:
    goto v_38342;
v_38343:
    goto v_38344;
v_38345:
    v_38352 = cons(v_38353, v_38352);
    env = stack[-3];
    goto v_38280;
v_38281:
    goto v_38277;
v_38278:
    goto v_38279;
v_38280:
    fn = elt(env, 2); // addsq
    v_38352 = (*qfn2(fn))(fn, stack[-2], v_38352);
    env = stack[-3];
    stack[0] = v_38352;
    goto v_38182;
    v_38352 = nil;
v_38181:
    return onevalue(v_38352);
}



// Code for deg

static LispObject CC_deg(LispObject env,
                         LispObject v_38177, LispObject v_38178)
{
    env = qenv(env);
    LispObject v_38202, v_38203;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_38178,v_38177);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_38177,v_38178);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_38178;
    stack[-1] = v_38177;
// end of prologue
    v_38202 = qvalue(elt(env, 1)); // gdmode!*
// Binding dmode!*
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 2, -2);
    qvalue(elt(env, 2)) = v_38202; // dmode!*
    v_38202 = stack[-1];
    fn = elt(env, 3); // simp!*
    v_38202 = (*qfn1(fn))(fn, v_38202);
    env = stack[-3];
    stack[-1] = v_38202;
    goto v_38189;
v_38185:
    v_38202 = stack[-1];
    v_38203 = qcdr(v_38202);
    goto v_38186;
v_38187:
    v_38202 = stack[0];
    goto v_38188;
v_38189:
    goto v_38185;
v_38186:
    goto v_38187;
v_38188:
    fn = elt(env, 4); // tstpolyarg
    v_38202 = (*qfn2(fn))(fn, v_38203, v_38202);
    env = stack[-3];
    goto v_38198;
v_38194:
    v_38202 = stack[-1];
    v_38203 = qcar(v_38202);
    goto v_38195;
v_38196:
    v_38202 = stack[0];
    goto v_38197;
v_38198:
    goto v_38194;
v_38195:
    goto v_38196;
v_38197:
    fn = elt(env, 5); // numrdeg
    v_38202 = (*qfn2(fn))(fn, v_38203, v_38202);
    ;}  // end of a binding scope
    return onevalue(v_38202);
}



// Code for imports

static LispObject CC_imports(LispObject env,
                         LispObject v_38177)
{
    env = qenv(env);
    LispObject v_38189, v_38190;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_38177);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_38177);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_38189 = v_38177;
// end of prologue
    goto v_38186;
v_38182:
    v_38190 = v_38189;
    goto v_38183;
v_38184:
    v_38189 = qvalue(elt(env, 1)); // importslist!*
    goto v_38185;
v_38186:
    goto v_38182;
v_38183:
    goto v_38184;
v_38185:
    fn = elt(env, 2); // union
    v_38189 = (*qfn2(fn))(fn, v_38190, v_38189);
    env = stack[0];
    qvalue(elt(env, 1)) = v_38189; // importslist!*
    v_38189 = nil;
    return onevalue(v_38189);
}



// Code for lto_hentry

static LispObject CC_lto_hentry(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_38222, v_38223, v_38224, v_38225;
    LispObject v_38179, v_38178, v_38177;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "lto_hentry");
    va_start(aa, nargs);
    v_38177 = va_arg(aa, LispObject);
    v_38178 = va_arg(aa, LispObject);
    v_38179 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_38179,v_38178,v_38177);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_38177,v_38178,v_38179);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_38223 = v_38179;
    v_38224 = v_38178;
    v_38225 = v_38177;
// end of prologue
    v_38222 = v_38224;
    if (v_38222 == nil) goto v_38183;
    else goto v_38184;
v_38183:
    goto v_38193;
v_38187:
    v_38224 = v_38225;
    goto v_38188;
v_38189:
    goto v_38190;
v_38191:
    v_38222 = nil;
    goto v_38192;
v_38193:
    goto v_38187;
v_38188:
    goto v_38189;
v_38190:
    goto v_38191;
v_38192:
    return list2star(v_38224, v_38223, v_38222);
v_38184:
    goto v_38206;
v_38200:
    stack[0] = v_38225;
    goto v_38201;
v_38202:
    goto v_38215;
v_38209:
    v_38222 = v_38224;
    v_38222 = qcar(v_38222);
    goto v_38210;
v_38211:
    v_38224 = qcdr(v_38224);
    goto v_38212;
v_38213:
    goto v_38214;
v_38215:
    goto v_38209;
v_38210:
    goto v_38211;
v_38212:
    goto v_38213;
v_38214:
    v_38223 = CC_lto_hentry(elt(env, 0), 3, v_38222, v_38224, v_38223);
    goto v_38203;
v_38204:
    v_38222 = nil;
    goto v_38205;
v_38206:
    goto v_38200;
v_38201:
    goto v_38202;
v_38203:
    goto v_38204;
v_38205:
    {
        LispObject v_38227 = stack[0];
        return list2star(v_38227, v_38223, v_38222);
    }
    v_38222 = nil;
    return onevalue(v_38222);
}



// Code for preptaycoeff

static LispObject CC_preptaycoeff(LispObject env,
                         LispObject v_38177, LispObject v_38178)
{
    env = qenv(env);
    LispObject v_38299, v_38300, v_38301;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_38178,v_38177);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_38177,v_38178);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_38178;
    stack[-5] = v_38177;
// end of prologue
    stack[-6] = nil;
v_38185:
    v_38299 = stack[-4];
    if (v_38299 == nil) goto v_38188;
    else goto v_38189;
v_38188:
    goto v_38184;
v_38189:
    v_38299 = stack[-5];
    v_38299 = qcar(v_38299);
    stack[-3] = v_38299;
    v_38299 = stack[-4];
    v_38299 = qcar(v_38299);
    v_38299 = qcar(v_38299);
    stack[-2] = v_38299;
v_38200:
    v_38299 = stack[-2];
    if (v_38299 == nil) goto v_38206;
    else goto v_38207;
v_38206:
    goto v_38199;
v_38207:
    v_38299 = stack[-2];
    v_38299 = qcar(v_38299);
    v_38301 = v_38299;
    goto v_38218;
v_38214:
    goto v_38227;
v_38223:
    v_38299 = stack[-4];
    v_38299 = qcar(v_38299);
    v_38299 = qcdr(v_38299);
    v_38300 = qcar(v_38299);
    goto v_38224;
v_38225:
    v_38299 = elt(env, 1); // infinity
    goto v_38226;
v_38227:
    goto v_38223;
v_38224:
    goto v_38225;
v_38226:
    if (v_38300 == v_38299) goto v_38221;
    else goto v_38222;
v_38221:
    goto v_38241;
v_38237:
    v_38299 = stack[-3];
    v_38300 = qcar(v_38299);
    goto v_38238;
v_38239:
    v_38299 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_38240;
v_38241:
    goto v_38237;
v_38238:
    goto v_38239;
v_38240:
    if (v_38300 == v_38299) goto v_38235;
    else goto v_38236;
v_38235:
    v_38299 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38234;
v_38236:
    goto v_38255;
v_38249:
    stack[-1] = elt(env, 2); // quotient
    goto v_38250;
v_38251:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38252;
v_38253:
    goto v_38263;
v_38259:
    v_38300 = v_38301;
    goto v_38260;
v_38261:
    v_38299 = stack[-3];
    v_38299 = qcar(v_38299);
    goto v_38262;
v_38263:
    goto v_38259;
v_38260:
    goto v_38261;
v_38262:
    fn = elt(env, 3); // checkexp
    v_38299 = (*qfn2(fn))(fn, v_38300, v_38299);
    env = stack[-7];
    goto v_38254;
v_38255:
    goto v_38249;
v_38250:
    goto v_38251;
v_38252:
    goto v_38253;
v_38254:
    v_38299 = list3(stack[-1], stack[0], v_38299);
    env = stack[-7];
    goto v_38234;
    v_38299 = nil;
v_38234:
    v_38300 = v_38299;
    goto v_38220;
v_38222:
    goto v_38274;
v_38270:
    goto v_38280;
v_38276:
    stack[0] = v_38301;
    goto v_38277;
v_38278:
    v_38299 = stack[-4];
    v_38299 = qcar(v_38299);
    v_38299 = qcdr(v_38299);
    v_38299 = qcar(v_38299);
    fn = elt(env, 4); // reval
    v_38299 = (*qfn1(fn))(fn, v_38299);
    env = stack[-7];
    goto v_38279;
v_38280:
    goto v_38276;
v_38277:
    goto v_38278;
v_38279:
    fn = elt(env, 5); // checkdifference
    v_38300 = (*qfn2(fn))(fn, stack[0], v_38299);
    env = stack[-7];
    goto v_38271;
v_38272:
    v_38299 = stack[-3];
    v_38299 = qcar(v_38299);
    goto v_38273;
v_38274:
    goto v_38270;
v_38271:
    goto v_38272;
v_38273:
    fn = elt(env, 3); // checkexp
    v_38299 = (*qfn2(fn))(fn, v_38300, v_38299);
    env = stack[-7];
    v_38300 = v_38299;
    goto v_38220;
    v_38300 = nil;
v_38220:
    goto v_38215;
v_38216:
    v_38299 = stack[-6];
    goto v_38217;
v_38218:
    goto v_38214;
v_38215:
    goto v_38216;
v_38217:
    v_38299 = cons(v_38300, v_38299);
    env = stack[-7];
    stack[-6] = v_38299;
    v_38299 = stack[-3];
    v_38299 = qcdr(v_38299);
    stack[-3] = v_38299;
    v_38299 = stack[-2];
    v_38299 = qcdr(v_38299);
    stack[-2] = v_38299;
    goto v_38200;
v_38199:
    v_38299 = stack[-5];
    v_38299 = qcdr(v_38299);
    stack[-5] = v_38299;
    v_38299 = stack[-4];
    v_38299 = qcdr(v_38299);
    stack[-4] = v_38299;
    goto v_38185;
v_38184:
    v_38299 = stack[-6];
    return onevalue(v_38299);
}



// Code for taysimpsq!*

static LispObject CC_taysimpsqH(LispObject env,
                         LispObject v_38177)
{
    env = qenv(env);
    LispObject v_38183, v_38184;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_38177);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_38177);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_38184 = v_38177;
// end of prologue
    v_38183 = nil;
// Binding !*taylorautoexpand
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_38183; // !*taylorautoexpand
    v_38183 = v_38184;
    fn = elt(env, 2); // taysimpsq
    v_38183 = (*qfn1(fn))(fn, v_38183);
    ;}  // end of a binding scope
    return onevalue(v_38183);
}



// Code for talp_tcandt

static LispObject CC_talp_tcandt(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_38204, v_38205, v_38206;
    LispObject fn;
    LispObject v_38179, v_38178, v_38177;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_tcandt");
    va_start(aa, nargs);
    v_38177 = va_arg(aa, LispObject);
    v_38178 = va_arg(aa, LispObject);
    v_38179 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_38179,v_38178,v_38177);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_38177,v_38178,v_38179);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_38179;
    stack[-1] = v_38178;
    v_38205 = v_38177;
// end of prologue
    v_38204 = stack[-1];
    if (v_38204 == nil) goto v_38183;
    else goto v_38184;
v_38183:
    v_38204 = v_38205;
    goto v_38182;
v_38184:
    goto v_38198;
v_38190:
    stack[-2] = v_38205;
    goto v_38191;
v_38192:
    v_38204 = v_38205;
    fn = elt(env, 1); // talp_op
    v_38206 = (*qfn1(fn))(fn, v_38204);
    env = stack[-3];
    goto v_38193;
v_38194:
    v_38205 = stack[-1];
    goto v_38195;
v_38196:
    v_38204 = stack[0];
    goto v_38197;
v_38198:
    goto v_38190;
v_38191:
    goto v_38192;
v_38193:
    goto v_38194;
v_38195:
    goto v_38196;
v_38197:
    {
        LispObject v_38210 = stack[-2];
        fn = elt(env, 2); // talp_tcandt1
        return (*qfnn(fn))(fn, 4, v_38210, v_38206, v_38205, v_38204);
    }
    v_38204 = nil;
v_38182:
    return onevalue(v_38204);
}



// Code for pasf_exprng!-gball

static LispObject CC_pasf_exprngKgball(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_38381, v_38382, v_38383, v_38384;
    LispObject fn;
    LispObject v_38182, v_38181, v_38180, v_38179, v_38178, v_38177;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "pasf_exprng-gball");
    va_start(aa, nargs);
    v_38177 = va_arg(aa, LispObject);
    v_38178 = va_arg(aa, LispObject);
    v_38179 = va_arg(aa, LispObject);
    v_38180 = va_arg(aa, LispObject);
    v_38181 = va_arg(aa, LispObject);
    v_38182 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_38182,v_38181,v_38180,v_38179,v_38178,v_38177);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_38177,v_38178,v_38179,v_38180,v_38181,v_38182);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-4] = v_38182;
    stack[-5] = v_38181;
    stack[-6] = v_38180;
    stack[-7] = v_38179;
    stack[0] = v_38178;
    stack[-8] = v_38177;
// end of prologue
    stack[-2] = nil;
    v_38381 = stack[0];
    fn = elt(env, 7); // cl_fvarl
    v_38381 = (*qfn1(fn))(fn, v_38381);
    env = stack[-10];
    goto v_38207;
v_38203:
    v_38383 = v_38381;
    goto v_38204;
v_38205:
    v_38382 = stack[-8];
    goto v_38206;
v_38207:
    goto v_38203;
v_38204:
    goto v_38205;
v_38206:
    if (!consp(v_38383)) goto v_38200;
    v_38383 = qcar(v_38383);
    if (v_38383 == v_38382) goto v_38201;
v_38200:
    v_38382 = lisp_true;
    goto v_38199;
v_38201:
    v_38382 = v_38381;
    v_38382 = qcdr(v_38382);
    goto v_38199;
    v_38382 = nil;
v_38199:
    if (v_38382 == nil) goto v_38197;
    goto v_38225;
v_38217:
    v_38384 = elt(env, 1); // "pasf_exprng: bad bound "
    goto v_38218;
v_38219:
    v_38383 = stack[0];
    goto v_38220;
v_38221:
    v_38382 = elt(env, 2); // " with free variables "
    goto v_38222;
v_38223:
    goto v_38224;
v_38225:
    goto v_38217;
v_38218:
    goto v_38219;
v_38220:
    goto v_38221;
v_38222:
    goto v_38223;
v_38224:
    v_38381 = list4(v_38384, v_38383, v_38382, v_38381);
    env = stack[-10];
    fn = elt(env, 8); // rederr
    v_38381 = (*qfn1(fn))(fn, v_38381);
    env = stack[-10];
    goto v_38195;
v_38197:
v_38195:
    v_38381 = qvalue(elt(env, 3)); // !*rlexprngnatural
    if (v_38381 == nil) goto v_38233;
    v_38381 = stack[-7];
    fn = elt(env, 9); // pasf_exprng
    v_38381 = (*qfn1(fn))(fn, v_38381);
    env = stack[-10];
    stack[-7] = v_38381;
    goto v_38231;
v_38233:
v_38231:
    v_38381 = stack[0];
    fn = elt(env, 10); // pasf_qff2ivl
    v_38381 = (*qfn1(fn))(fn, v_38381);
    env = stack[-10];
    stack[-1] = v_38381;
    v_38381 = lisp_true;
    stack[-9] = v_38381;
v_38242:
    v_38381 = stack[-9];
    if (v_38381 == nil) goto v_38245;
    v_38381 = stack[-1];
    if (v_38381 == nil) goto v_38245;
    goto v_38246;
v_38245:
    goto v_38241;
v_38246:
    v_38381 = stack[-1];
    v_38381 = qcar(v_38381);
    v_38382 = v_38381;
    v_38381 = stack[-1];
    v_38381 = qcdr(v_38381);
    stack[-1] = v_38381;
    v_38381 = v_38382;
    stack[0] = v_38381;
    v_38381 = stack[0];
    v_38381 = qcar(v_38381);
    stack[-3] = v_38381;
v_38265:
    v_38381 = stack[-9];
    if (v_38381 == nil) goto v_38268;
    goto v_38278;
v_38274:
    v_38382 = stack[-3];
    goto v_38275;
v_38276:
    v_38381 = stack[0];
    v_38381 = qcdr(v_38381);
    goto v_38277;
v_38278:
    goto v_38274;
v_38275:
    goto v_38276;
v_38277:
    v_38381 = (LispObject)lesseq2(v_38382, v_38381);
    v_38381 = v_38381 ? lisp_true : nil;
    env = stack[-10];
    if (v_38381 == nil) goto v_38268;
    goto v_38269;
v_38268:
    goto v_38264;
v_38269:
    goto v_38290;
v_38284:
    v_38383 = stack[-7];
    goto v_38285;
v_38286:
    v_38382 = stack[-8];
    goto v_38287;
v_38288:
    v_38381 = stack[-3];
    goto v_38289;
v_38290:
    goto v_38284;
v_38285:
    goto v_38286;
v_38287:
    goto v_38288;
v_38289:
    fn = elt(env, 11); // pasf_sisub
    v_38381 = (*qfnn(fn))(fn, 3, v_38383, v_38382, v_38381);
    env = stack[-10];
    v_38382 = qvalue(elt(env, 3)); // !*rlexprngnatural
    if (v_38382 == nil) goto v_38296;
    else goto v_38297;
v_38296:
    fn = elt(env, 9); // pasf_exprng
    v_38381 = (*qfn1(fn))(fn, v_38381);
    env = stack[-10];
    goto v_38295;
v_38297:
v_38295:
    goto v_38309;
v_38305:
    v_38383 = v_38381;
    goto v_38306;
v_38307:
    v_38382 = stack[-4];
    goto v_38308;
v_38309:
    goto v_38305;
v_38306:
    goto v_38307;
v_38308:
    if (v_38383 == v_38382) goto v_38303;
    else goto v_38304;
v_38303:
    v_38381 = nil;
    stack[-9] = v_38381;
    goto v_38302;
v_38304:
    goto v_38323;
v_38319:
    v_38383 = v_38381;
    goto v_38320;
v_38321:
    v_38382 = stack[-5];
    goto v_38322;
v_38323:
    goto v_38319;
v_38320:
    goto v_38321;
v_38322:
    if (equal(v_38383, v_38382)) goto v_38318;
    goto v_38331;
v_38327:
    v_38382 = v_38381;
    goto v_38328;
v_38329:
    v_38381 = stack[-2];
    goto v_38330;
v_38331:
    goto v_38327;
v_38328:
    goto v_38329;
v_38330:
    v_38381 = cons(v_38382, v_38381);
    env = stack[-10];
    stack[-2] = v_38381;
    goto v_38316;
v_38318:
v_38316:
    v_38381 = stack[-3];
    v_38381 = add1(v_38381);
    env = stack[-10];
    stack[-3] = v_38381;
    goto v_38302;
v_38302:
    goto v_38265;
v_38264:
    goto v_38242;
v_38241:
    v_38381 = stack[-9];
    if (v_38381 == nil) goto v_38338;
    else goto v_38339;
v_38338:
    v_38381 = stack[-4];
    goto v_38191;
v_38339:
    v_38381 = stack[-2];
    if (v_38381 == nil) goto v_38345;
    v_38381 = stack[-2];
    v_38381 = qcdr(v_38381);
    if (v_38381 == nil) goto v_38345;
    goto v_38356;
v_38352:
    v_38382 = stack[-6];
    goto v_38353;
v_38354:
    v_38381 = stack[-2];
    goto v_38355;
v_38356:
    goto v_38352;
v_38353:
    goto v_38354;
v_38355:
    return cons(v_38382, v_38381);
v_38345:
    v_38381 = stack[-2];
    if (v_38381 == nil) goto v_38359;
    else goto v_38360;
v_38359:
    goto v_38370;
v_38366:
    v_38382 = stack[-6];
    goto v_38367;
v_38368:
    v_38381 = elt(env, 4); // and
    goto v_38369;
v_38370:
    goto v_38366;
v_38367:
    goto v_38368;
v_38369:
    if (v_38382 == v_38381) goto v_38364;
    else goto v_38365;
v_38364:
    v_38381 = elt(env, 5); // true
    goto v_38363;
v_38365:
    v_38381 = elt(env, 6); // false
    goto v_38363;
    v_38381 = nil;
v_38363:
    goto v_38343;
v_38360:
    v_38381 = stack[-2];
    v_38381 = qcar(v_38381);
    goto v_38343;
    v_38381 = nil;
v_38343:
v_38191:
    return onevalue(v_38381);
}



// Code for make!-ps

static LispObject CC_makeKps(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_38279, v_38280, v_38281;
    LispObject fn;
    LispObject v_38180, v_38179, v_38178, v_38177;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "make-ps");
    va_start(aa, nargs);
    v_38177 = va_arg(aa, LispObject);
    v_38178 = va_arg(aa, LispObject);
    v_38179 = va_arg(aa, LispObject);
    v_38180 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_38180,v_38179,v_38178,v_38177);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_38177,v_38178,v_38179,v_38180);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_38180;
    stack[-1] = v_38179;
    stack[-2] = v_38178;
    stack[-3] = v_38177;
// end of prologue
    goto v_38190;
v_38186:
    goto v_38196;
v_38192:
    v_38280 = elt(env, 1); // tps
    goto v_38193;
v_38194:
    v_38279 = elt(env, 2); // tag
    goto v_38195;
v_38196:
    goto v_38192;
v_38193:
    goto v_38194;
v_38195:
    stack[-4] = get(v_38280, v_38279);
    env = stack[-5];
    goto v_38187;
v_38188:
    v_38279 = (LispObject)112+TAG_FIXNUM; // 7
    v_38279 = Lmkvect(nil, v_38279);
    env = stack[-5];
    goto v_38189;
v_38190:
    goto v_38186;
v_38187:
    goto v_38188;
v_38189:
    v_38279 = cons(stack[-4], v_38279);
    env = stack[-5];
    stack[-4] = v_38279;
    goto v_38208;
v_38202:
    v_38281 = stack[-4];
    goto v_38203;
v_38204:
    v_38280 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_38205;
v_38206:
    v_38279 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_38207;
v_38208:
    goto v_38202;
v_38203:
    goto v_38204;
v_38205:
    goto v_38206;
v_38207:
    fn = elt(env, 4); // ps!:putv
    v_38279 = (*qfnn(fn))(fn, 3, v_38281, v_38280, v_38279);
    env = stack[-5];
    goto v_38219;
v_38213:
    v_38281 = stack[-4];
    goto v_38214;
v_38215:
    v_38280 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_38216;
v_38217:
    v_38279 = stack[-3];
    goto v_38218;
v_38219:
    goto v_38213;
v_38214:
    goto v_38215;
v_38216:
    goto v_38217;
v_38218:
    fn = elt(env, 4); // ps!:putv
    v_38279 = (*qfnn(fn))(fn, 3, v_38281, v_38280, v_38279);
    env = stack[-5];
    goto v_38230;
v_38224:
    v_38281 = stack[-4];
    goto v_38225;
v_38226:
    v_38280 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_38227;
v_38228:
    v_38279 = stack[-2];
    goto v_38229;
v_38230:
    goto v_38224;
v_38225:
    goto v_38226;
v_38227:
    goto v_38228;
v_38229:
    fn = elt(env, 4); // ps!:putv
    v_38279 = (*qfnn(fn))(fn, 3, v_38281, v_38280, v_38279);
    env = stack[-5];
    goto v_38241;
v_38235:
    v_38281 = stack[-4];
    goto v_38236;
v_38237:
    v_38280 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_38238;
v_38239:
    v_38279 = stack[-1];
    goto v_38240;
v_38241:
    goto v_38235;
v_38236:
    goto v_38237;
v_38238:
    goto v_38239;
v_38240:
    fn = elt(env, 4); // ps!:putv
    v_38279 = (*qfnn(fn))(fn, 3, v_38281, v_38280, v_38279);
    env = stack[-5];
    goto v_38252;
v_38246:
    v_38281 = stack[-4];
    goto v_38247;
v_38248:
    v_38280 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_38249;
v_38250:
    v_38279 = stack[0];
    goto v_38251;
v_38252:
    goto v_38246;
v_38247:
    goto v_38248;
v_38249:
    goto v_38250;
v_38251:
    fn = elt(env, 4); // ps!:putv
    v_38279 = (*qfnn(fn))(fn, 3, v_38281, v_38280, v_38279);
    env = stack[-5];
    goto v_38263;
v_38257:
    v_38281 = stack[-4];
    goto v_38258;
v_38259:
    v_38280 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38260;
v_38261:
    v_38279 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_38262;
v_38263:
    goto v_38257;
v_38258:
    goto v_38259;
v_38260:
    goto v_38261;
v_38262:
    fn = elt(env, 4); // ps!:putv
    v_38279 = (*qfnn(fn))(fn, 3, v_38281, v_38280, v_38279);
    env = stack[-5];
    goto v_38273;
v_38267:
    v_38279 = stack[-4];
    v_38280 = qcdr(v_38279);
    goto v_38268;
v_38269:
    v_38279 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_38270;
v_38271:
    v_38281 = qvalue(elt(env, 3)); // !*sqvar!*
    goto v_38272;
v_38273:
    goto v_38267;
v_38268:
    goto v_38269;
v_38270:
    goto v_38271;
v_38272:
    *(LispObject *)((char *)v_38280 + (CELL-TAG_VECTOR) + (((intptr_t)v_38279-TAG_FIXNUM)/(16/CELL))) = v_38281;
    v_38279 = stack[-4];
    return onevalue(v_38279);
}



// Code for nestprep!:

static LispObject CC_nestprepT(LispObject env,
                         LispObject v_38177)
{
    env = qenv(env);
    LispObject v_38215, v_38216;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_38177);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_38177);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_38216 = v_38177;
// end of prologue
    goto v_38186;
v_38180:
    stack[-1] = elt(env, 1); // co
    goto v_38181;
v_38182:
    v_38215 = v_38216;
    v_38215 = integerp(v_38215);
    if (v_38215 == nil) goto v_38191;
    v_38215 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_38215;
    goto v_38189;
v_38191:
    v_38215 = v_38216;
    v_38215 = qcdr(v_38215);
    v_38215 = qcar(v_38215);
    stack[0] = v_38215;
    goto v_38189;
    stack[0] = nil;
v_38189:
    goto v_38183;
v_38184:
    v_38215 = v_38216;
    v_38215 = integerp(v_38215);
    if (v_38215 == nil) goto v_38204;
    v_38215 = v_38216;
    fn = elt(env, 2); // simp
    v_38215 = (*qfn1(fn))(fn, v_38215);
    env = stack[-2];
    goto v_38202;
v_38204:
    v_38215 = v_38216;
    v_38215 = qcdr(v_38215);
    v_38215 = qcdr(v_38215);
    v_38215 = qcdr(v_38215);
    goto v_38202;
    v_38215 = nil;
v_38202:
    fn = elt(env, 3); // prepsq
    v_38215 = (*qfn1(fn))(fn, v_38215);
    goto v_38185;
v_38186:
    goto v_38180;
v_38181:
    goto v_38182;
v_38183:
    goto v_38184;
v_38185:
    {
        LispObject v_38219 = stack[-1];
        LispObject v_38220 = stack[0];
        return list3(v_38219, v_38220, v_38215);
    }
}



// Code for calc_map_

static LispObject CC_calc_map_(LispObject env,
                         LispObject v_38177, LispObject v_38178)
{
    env = qenv(env);
    LispObject v_38300, v_38301, v_38302;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_38178,v_38177);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_38177,v_38178);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_38178;
    v_38301 = v_38177;
// end of prologue
    v_38300 = v_38301;
    v_38300 = qcar(v_38300);
    stack[-2] = v_38300;
    v_38300 = v_38301;
    v_38300 = qcdr(v_38300);
    v_38300 = qcar(v_38300);
    stack[-5] = v_38300;
    v_38300 = v_38301;
    v_38300 = qcdr(v_38300);
    v_38300 = qcdr(v_38300);
    v_38300 = qcar(v_38300);
    stack[-3] = v_38300;
    v_38300 = v_38301;
    v_38300 = qcdr(v_38300);
    v_38300 = qcdr(v_38300);
    v_38300 = qcdr(v_38300);
    stack[-1] = v_38300;
    goto v_38207;
v_38203:
    v_38301 = stack[-4];
    goto v_38204;
v_38205:
    v_38300 = stack[-2];
    goto v_38206;
v_38207:
    goto v_38203;
v_38204:
    goto v_38205;
v_38206:
    fn = elt(env, 2); // actual_alst
    v_38300 = (*qfn2(fn))(fn, v_38301, v_38300);
    env = stack[-6];
    stack[0] = v_38300;
    v_38300 = stack[0];
    if (v_38300 == nil) goto v_38216;
    else goto v_38217;
v_38216:
    v_38300 = stack[-2];
    goto v_38215;
v_38217:
    v_38300 = nil;
    goto v_38215;
    v_38300 = nil;
v_38215:
    if (v_38300 == nil) goto v_38213;
    v_38300 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_38188;
v_38213:
    goto v_38228;
v_38224:
    v_38301 = stack[0];
    goto v_38225;
v_38226:
    v_38300 = stack[-3];
    v_38300 = qcdr(v_38300);
    goto v_38227;
v_38228:
    goto v_38224;
v_38225:
    goto v_38226;
v_38227:
    v_38300 = Lassoc(nil, v_38301, v_38300);
    stack[-2] = v_38300;
    v_38300 = stack[-2];
    if (v_38300 == nil) goto v_38236;
    v_38300 = stack[-2];
    v_38300 = qcdr(v_38300);
    stack[-2] = v_38300;
    goto v_38234;
v_38236:
    goto v_38248;
v_38244:
    v_38301 = stack[-5];
    goto v_38245;
v_38246:
    v_38300 = stack[0];
    goto v_38247;
v_38248:
    goto v_38244;
v_38245:
    goto v_38246;
v_38247:
    fn = elt(env, 3); // calc_map_tar
    v_38300 = (*qfn2(fn))(fn, v_38301, v_38300);
    env = stack[-6];
    fn = elt(env, 4); // reval
    v_38300 = (*qfn1(fn))(fn, v_38300);
    env = stack[-6];
    stack[-2] = v_38300;
    goto v_38256;
v_38252:
    goto v_38253;
v_38254:
    goto v_38264;
v_38260:
    v_38301 = stack[0];
    goto v_38261;
v_38262:
    v_38300 = stack[-2];
    goto v_38263;
v_38264:
    goto v_38260;
v_38261:
    goto v_38262;
v_38263:
    v_38300 = cons(v_38301, v_38300);
    env = stack[-6];
    v_38300 = ncons(v_38300);
    env = stack[-6];
    goto v_38255;
v_38256:
    goto v_38252;
v_38253:
    goto v_38254;
v_38255:
    v_38300 = Lnconc(nil, stack[-3], v_38300);
    env = stack[-6];
    goto v_38234;
v_38234:
    goto v_38272;
v_38268:
    v_38301 = stack[-1];
    goto v_38269;
v_38270:
    v_38300 = stack[-4];
    goto v_38271;
v_38272:
    goto v_38268;
v_38269:
    goto v_38270;
v_38271:
    fn = elt(env, 5); // calc_den_tar
    v_38300 = (*qfn2(fn))(fn, v_38301, v_38300);
    env = stack[-6];
    v_38302 = v_38300;
    goto v_38283;
v_38279:
    v_38301 = v_38302;
    goto v_38280;
v_38281:
    v_38300 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_38282;
v_38283:
    goto v_38279;
v_38280:
    goto v_38281;
v_38282:
    if (v_38301 == v_38300) goto v_38277;
    else goto v_38278;
v_38277:
    v_38300 = stack[-2];
    goto v_38276;
v_38278:
    goto v_38296;
v_38290:
    v_38301 = elt(env, 1); // quotient
    goto v_38291;
v_38292:
    v_38300 = stack[-2];
    goto v_38293;
v_38294:
    goto v_38295;
v_38296:
    goto v_38290;
v_38291:
    goto v_38292;
v_38293:
    goto v_38294;
v_38295:
    return list3(v_38301, v_38300, v_38302);
    v_38300 = nil;
v_38276:
v_38188:
    return onevalue(v_38300);
}



setup_type const u60_setup[] =
{
    {"comcom3",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_comcom3},
    {"pst_partition",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pst_partition},
    {"lambda_sorneshiwvd12",    TOO_FEW_2,      CC_lambda_sorneshiwvd12,WRONG_NO_2},
    {"ratleqp",                 TOO_FEW_2,      CC_ratleqp,    WRONG_NO_2},
    {"reduce-eival-powers1",    TOO_FEW_2,      CC_reduceKeivalKpowers1,WRONG_NO_2},
    {"deg",                     TOO_FEW_2,      CC_deg,        WRONG_NO_2},
    {"imports",                 CC_imports,     TOO_MANY_1,    WRONG_NO_1},
    {"lto_hentry",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lto_hentry},
    {"preptaycoeff",            TOO_FEW_2,      CC_preptaycoeff,WRONG_NO_2},
    {"taysimpsq*",              CC_taysimpsqH,  TOO_MANY_1,    WRONG_NO_1},
    {"talp_tcandt",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_tcandt},
    {"pasf_exprng-gball",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pasf_exprngKgball},
    {"make-ps",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_makeKps},
    {"nestprep:",               CC_nestprepT,   TOO_MANY_1,    WRONG_NO_1},
    {"calc_map_",               TOO_FEW_2,      CC_calc_map_,  WRONG_NO_2},
    {NULL, (one_args *)"u60", (two_args *)"142385 6511438 5329825", 0}
};

// end of generated code
