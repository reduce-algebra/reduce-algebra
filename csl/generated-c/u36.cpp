
// $destdir/u36.c        Machine generated C code

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



// Code for sublap

static LispObject CC_sublap(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20925, v_20926;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20836;
    stack[-1] = v_20835;
// end of prologue
    v_20925 = stack[-1];
    if (v_20925 == nil) goto v_20847;
    else goto v_20848;
v_20847:
    v_20925 = lisp_true;
    goto v_20846;
v_20848:
    v_20925 = stack[0];
    v_20925 = (v_20925 == nil ? lisp_true : nil);
    goto v_20846;
    v_20925 = nil;
v_20846:
    if (v_20925 == nil) goto v_20844;
    v_20925 = stack[0];
    goto v_20842;
v_20844:
    v_20925 = stack[0];
    if (!consp(v_20925)) goto v_20856;
    else goto v_20857;
v_20856:
    v_20925 = stack[0];
    if (is_number(v_20925)) goto v_20861;
    else goto v_20862;
v_20861:
    v_20925 = stack[0];
    goto v_20860;
v_20862:
    goto v_20871;
v_20867:
    v_20926 = stack[0];
    goto v_20868;
v_20869:
    v_20925 = stack[-1];
    goto v_20870;
v_20871:
    goto v_20867;
v_20868:
    goto v_20869;
v_20870:
    v_20925 = Latsoc(nil, v_20926, v_20925);
    v_20926 = v_20925;
    if (v_20925 == nil) goto v_20866;
    v_20925 = v_20926;
    v_20925 = qcdr(v_20925);
    goto v_20860;
v_20866:
    v_20925 = stack[0];
    goto v_20860;
    v_20925 = nil;
v_20860:
    goto v_20842;
v_20857:
    goto v_20887;
v_20883:
    v_20925 = stack[0];
    v_20926 = qcar(v_20925);
    goto v_20884;
v_20885:
    v_20925 = elt(env, 1); // app
    goto v_20886;
v_20887:
    goto v_20883;
v_20884:
    goto v_20885;
v_20886:
    v_20925 = Lflagp(nil, v_20926, v_20925);
    env = stack[-3];
    if (v_20925 == nil) goto v_20881;
    goto v_20896;
v_20892:
    v_20926 = stack[-1];
    goto v_20893;
v_20894:
    v_20925 = stack[0];
    goto v_20895;
v_20896:
    goto v_20892;
v_20893:
    goto v_20894;
v_20895:
    {
        fn = elt(env, 2); // sublap1
        return (*qfn2(fn))(fn, v_20926, v_20925);
    }
v_20881:
    goto v_20906;
v_20902:
    goto v_20912;
v_20908:
    v_20926 = stack[-1];
    goto v_20909;
v_20910:
    v_20925 = stack[0];
    v_20925 = qcar(v_20925);
    goto v_20911;
v_20912:
    goto v_20908;
v_20909:
    goto v_20910;
v_20911:
    stack[-2] = CC_sublap(elt(env, 0), v_20926, v_20925);
    env = stack[-3];
    goto v_20903;
v_20904:
    goto v_20921;
v_20917:
    v_20926 = stack[-1];
    goto v_20918;
v_20919:
    v_20925 = stack[0];
    v_20925 = qcdr(v_20925);
    goto v_20920;
v_20921:
    goto v_20917;
v_20918:
    goto v_20919;
v_20920:
    v_20925 = CC_sublap(elt(env, 0), v_20926, v_20925);
    goto v_20905;
v_20906:
    goto v_20902;
v_20903:
    goto v_20904;
v_20905:
    {
        LispObject v_20930 = stack[-2];
        return cons(v_20930, v_20925);
    }
    v_20925 = nil;
v_20842:
    return onevalue(v_20925);
}



// Code for deletez1

static LispObject CC_deletez1(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20883, v_20884, v_20885, v_20886;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_20836;
    stack[-1] = v_20835;
// end of prologue
    v_20886 = nil;
v_20841:
    v_20883 = stack[-1];
    if (v_20883 == nil) goto v_20844;
    else goto v_20845;
v_20844:
    v_20883 = v_20886;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_20883);
    }
v_20845:
    goto v_20855;
v_20851:
    v_20885 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20852;
v_20853:
    goto v_20861;
v_20857:
    v_20883 = stack[-1];
    v_20883 = qcar(v_20883);
    v_20884 = qcar(v_20883);
    goto v_20858;
v_20859:
    v_20883 = stack[0];
    goto v_20860;
v_20861:
    goto v_20857;
v_20858:
    goto v_20859;
v_20860:
    v_20883 = Lassoc(nil, v_20884, v_20883);
    v_20883 = qcdr(v_20883);
    goto v_20854;
v_20855:
    goto v_20851;
v_20852:
    goto v_20853;
v_20854:
    if (v_20885 == v_20883) goto v_20849;
    else goto v_20850;
v_20849:
    v_20883 = stack[-1];
    v_20883 = qcdr(v_20883);
    stack[-1] = v_20883;
    goto v_20841;
v_20850:
    goto v_20877;
v_20873:
    v_20883 = stack[-1];
    v_20883 = qcar(v_20883);
    goto v_20874;
v_20875:
    v_20884 = v_20886;
    goto v_20876;
v_20877:
    goto v_20873;
v_20874:
    goto v_20875;
v_20876:
    v_20883 = cons(v_20883, v_20884);
    env = stack[-2];
    v_20886 = v_20883;
    v_20883 = stack[-1];
    v_20883 = qcdr(v_20883);
    stack[-1] = v_20883;
    goto v_20841;
    v_20883 = nil;
    return onevalue(v_20883);
}



// Code for assert_kernelp

static LispObject CC_assert_kernelp(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20881, v_20882;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20881 = v_20835;
// end of prologue
    v_20882 = v_20881;
    if (symbolp(v_20882)) goto v_20842;
    else goto v_20843;
v_20842:
    v_20881 = lisp_true;
    goto v_20839;
v_20843:
    v_20882 = v_20881;
    v_20882 = Lconsp(nil, v_20882);
    env = stack[0];
    if (v_20882 == nil) goto v_20848;
    else goto v_20849;
v_20848:
    v_20881 = nil;
    goto v_20839;
v_20849:
    v_20882 = v_20881;
    v_20882 = qcar(v_20882);
    if (!symbolp(v_20882)) v_20882 = nil;
    else { v_20882 = qfastgets(v_20882);
           if (v_20882 != nil) { v_20882 = elt(v_20882, 38); // fkernfn
#ifdef RECORD_GET
             if (v_20882 != SPID_NOPROP)
                record_get(elt(fastget_names, 38), 1);
             else record_get(elt(fastget_names, 38), 0),
                v_20882 = nil; }
           else record_get(elt(fastget_names, 38), 0); }
#else
             if (v_20882 == SPID_NOPROP) v_20882 = nil; }}
#endif
    if (v_20882 == nil) goto v_20856;
    v_20881 = lisp_true;
    goto v_20839;
v_20856:
    v_20882 = v_20881;
    v_20882 = qcar(v_20882);
    if (!consp(v_20882)) goto v_20863;
    else goto v_20864;
v_20863:
    v_20882 = v_20881;
    v_20882 = qcar(v_20882);
    if (!symbolp(v_20882)) v_20882 = nil;
    else { v_20882 = qfastgets(v_20882);
           if (v_20882 != nil) { v_20882 = elt(v_20882, 24); // klist
#ifdef RECORD_GET
             if (v_20882 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v_20882 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v_20882 == SPID_NOPROP) v_20882 = nil; }}
#endif
    goto v_20862;
v_20864:
    v_20882 = qvalue(elt(env, 1)); // exlist!*
    goto v_20862;
    v_20882 = nil;
v_20862:
    goto v_20877;
v_20873:
    goto v_20874;
v_20875:
    goto v_20876;
v_20877:
    goto v_20873;
v_20874:
    goto v_20875;
v_20876:
    v_20881 = Latsoc(nil, v_20881, v_20882);
v_20839:
    return onevalue(v_20881);
}



// Code for !*!*a2i

static LispObject CC_HHa2i(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20861, v_20862;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_20861 = v_20836;
    stack[0] = v_20835;
// end of prologue
    goto v_20847;
v_20843:
    v_20862 = stack[0];
    goto v_20844;
v_20845:
    goto v_20846;
v_20847:
    goto v_20843;
v_20844:
    goto v_20845;
v_20846:
    fn = elt(env, 2); // intexprnp
    v_20861 = (*qfn2(fn))(fn, v_20862, v_20861);
    env = stack[-1];
    if (v_20861 == nil) goto v_20841;
    v_20861 = stack[0];
    goto v_20839;
v_20841:
    goto v_20858;
v_20854:
    v_20862 = elt(env, 1); // ieval
    goto v_20855;
v_20856:
    v_20861 = stack[0];
    goto v_20857;
v_20858:
    goto v_20854;
v_20855:
    goto v_20856;
v_20857:
    return list2(v_20862, v_20861);
    v_20861 = nil;
v_20839:
    return onevalue(v_20861);
}



// Code for gvar1

static LispObject CC_gvar1(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20960, v_20961, v_20962, v_20963;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20963 = v_20836;
    v_20962 = v_20835;
// end of prologue
v_20840:
    v_20960 = v_20962;
    if (v_20960 == nil) goto v_20847;
    else goto v_20848;
v_20847:
    v_20960 = lisp_true;
    goto v_20846;
v_20848:
    v_20960 = v_20962;
    v_20960 = (is_number(v_20960) ? lisp_true : nil);
    if (v_20960 == nil) goto v_20855;
    else goto v_20854;
v_20855:
    goto v_20866;
v_20862:
    v_20961 = v_20962;
    goto v_20863;
v_20864:
    v_20960 = elt(env, 1); // i
    goto v_20865;
v_20866:
    goto v_20862;
v_20863:
    goto v_20864;
v_20865:
    if (v_20961 == v_20960) goto v_20860;
    else goto v_20861;
v_20860:
    v_20960 = qvalue(elt(env, 2)); // !*complex
    goto v_20859;
v_20861:
    v_20960 = nil;
    goto v_20859;
    v_20960 = nil;
v_20859:
v_20854:
    goto v_20846;
    v_20960 = nil;
v_20846:
    if (v_20960 == nil) goto v_20844;
    v_20960 = v_20963;
    goto v_20839;
v_20844:
    v_20960 = v_20962;
    if (!consp(v_20960)) goto v_20874;
    else goto v_20875;
v_20874:
    goto v_20885;
v_20881:
    v_20961 = v_20962;
    goto v_20882;
v_20883:
    v_20960 = v_20963;
    goto v_20884;
v_20885:
    goto v_20881;
v_20882:
    goto v_20883;
v_20884:
    v_20960 = Lmember(nil, v_20961, v_20960);
    if (v_20960 == nil) goto v_20880;
    v_20960 = v_20963;
    goto v_20839;
v_20880:
    goto v_20897;
v_20893:
    v_20960 = v_20962;
    goto v_20894;
v_20895:
    v_20961 = v_20963;
    goto v_20896;
v_20897:
    goto v_20893;
v_20894:
    goto v_20895;
v_20896:
    return cons(v_20960, v_20961);
    goto v_20842;
v_20875:
    v_20960 = v_20962;
    v_20960 = qcar(v_20960);
    if (!symbolp(v_20960)) v_20960 = nil;
    else { v_20960 = qfastgets(v_20960);
           if (v_20960 != nil) { v_20960 = elt(v_20960, 8); // dname
#ifdef RECORD_GET
             if (v_20960 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_20960 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_20960 == SPID_NOPROP) v_20960 = nil; }}
#endif
    if (v_20960 == nil) goto v_20901;
    v_20960 = v_20963;
    goto v_20839;
v_20901:
    goto v_20912;
v_20908:
    v_20960 = v_20962;
    v_20961 = qcar(v_20960);
    goto v_20909;
v_20910:
    v_20960 = elt(env, 3); // (plus times expt difference minus)
    goto v_20911;
v_20912:
    goto v_20908;
v_20909:
    goto v_20910;
v_20911:
    v_20960 = Lmemq(nil, v_20961, v_20960);
    if (v_20960 == nil) goto v_20907;
    goto v_20922;
v_20918:
    v_20960 = v_20962;
    v_20960 = qcdr(v_20960);
    goto v_20919;
v_20920:
    v_20961 = v_20963;
    goto v_20921;
v_20922:
    goto v_20918;
v_20919:
    goto v_20920;
v_20921:
    {
        fn = elt(env, 5); // gvarlis1
        return (*qfn2(fn))(fn, v_20960, v_20961);
    }
v_20907:
    goto v_20932;
v_20928:
    v_20960 = v_20962;
    v_20961 = qcar(v_20960);
    goto v_20929;
v_20930:
    v_20960 = elt(env, 4); // quotient
    goto v_20931;
v_20932:
    goto v_20928;
v_20929:
    goto v_20930;
v_20931:
    if (v_20961 == v_20960) goto v_20926;
    else goto v_20927;
v_20926:
    v_20960 = v_20962;
    v_20960 = qcdr(v_20960);
    v_20960 = qcar(v_20960);
    v_20962 = v_20960;
    goto v_20840;
v_20927:
    goto v_20945;
v_20941:
    v_20961 = v_20962;
    goto v_20942;
v_20943:
    v_20960 = v_20963;
    goto v_20944;
v_20945:
    goto v_20941;
v_20942:
    goto v_20943;
v_20944:
    v_20960 = Lmember(nil, v_20961, v_20960);
    if (v_20960 == nil) goto v_20940;
    v_20960 = v_20963;
    goto v_20839;
v_20940:
    goto v_20957;
v_20953:
    v_20960 = v_20962;
    goto v_20954;
v_20955:
    v_20961 = v_20963;
    goto v_20956;
v_20957:
    goto v_20953;
v_20954:
    goto v_20955;
v_20956:
    return cons(v_20960, v_20961);
v_20842:
    v_20960 = nil;
v_20839:
    return onevalue(v_20960);
}



// Code for drnconv

static LispObject CC_drnconv(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20894, v_20895, v_20896;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20895 = v_20835;
// end of prologue
    v_20894 = v_20895;
    if (v_20894 == nil) goto v_20843;
    else goto v_20844;
v_20843:
    v_20894 = lisp_true;
    goto v_20842;
v_20844:
    v_20894 = v_20895;
    v_20894 = (is_number(v_20894) ? lisp_true : nil);
    if (v_20894 == nil) goto v_20851;
    else goto v_20850;
v_20851:
    goto v_20859;
v_20855:
    v_20896 = v_20895;
    goto v_20856;
v_20857:
    v_20894 = qvalue(elt(env, 1)); // dmd!*
    goto v_20858;
v_20859:
    goto v_20855;
v_20856:
    goto v_20857;
v_20858:
    v_20894 = Leqcar(nil, v_20896, v_20894);
    env = stack[0];
v_20850:
    goto v_20842;
    v_20894 = nil;
v_20842:
    if (v_20894 == nil) goto v_20840;
    v_20894 = v_20895;
    goto v_20838;
v_20840:
    goto v_20870;
v_20866:
    v_20894 = v_20895;
    v_20896 = qcar(v_20894);
    goto v_20867;
v_20868:
    v_20894 = qvalue(elt(env, 1)); // dmd!*
    goto v_20869;
v_20870:
    goto v_20866;
v_20867:
    goto v_20868;
v_20869:
    v_20894 = get(v_20896, v_20894);
    v_20896 = v_20894;
    v_20894 = v_20896;
    if (v_20894 == nil) goto v_20878;
    v_20894 = v_20896;
    if (!consp(v_20894)) goto v_20881;
    else goto v_20878;
v_20881:
    goto v_20888;
v_20884:
    v_20894 = v_20896;
    goto v_20885;
v_20886:
    goto v_20887;
v_20888:
    goto v_20884;
v_20885:
    goto v_20886;
v_20887:
        return Lapply1(nil, v_20894, v_20895);
v_20878:
    v_20894 = v_20895;
    goto v_20876;
    v_20894 = nil;
v_20876:
    goto v_20838;
    v_20894 = nil;
v_20838:
    return onevalue(v_20894);
}



// Code for split!-further

static LispObject CC_splitKfurther(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21048, v_21049, v_21050, v_21051;
    LispObject fn;
    LispObject v_20837, v_20836, v_20835;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "split-further");
    va_start(aa, nargs);
    v_20835 = va_arg(aa, LispObject);
    v_20836 = va_arg(aa, LispObject);
    v_20837 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20837,v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20835,v_20836,v_20837);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_20837;
    stack[-2] = v_20836;
    stack[-3] = v_20835;
// end of prologue
    v_21048 = stack[-3];
    if (v_21048 == nil) goto v_20841;
    else goto v_20842;
v_20841:
    v_21048 = nil;
    return ncons(v_21048);
v_20842:
    goto v_20862;
v_20856:
    v_21048 = stack[-3];
    v_21050 = qcdr(v_21048);
    goto v_20857;
v_20858:
    v_21049 = stack[-2];
    goto v_20859;
v_20860:
    v_21048 = stack[-1];
    goto v_20861;
v_20862:
    goto v_20856;
v_20857:
    goto v_20858;
v_20859:
    goto v_20860;
v_20861:
    v_21048 = CC_splitKfurther(elt(env, 0), 3, v_21050, v_21049, v_21048);
    env = stack[-5];
    stack[-4] = v_21048;
    v_21048 = stack[-4];
    v_21048 = qcdr(v_21048);
    stack[0] = v_21048;
    v_21048 = stack[-4];
    v_21048 = qcar(v_21048);
    stack[-4] = v_21048;
    goto v_20879;
v_20875:
    v_21049 = qvalue(elt(env, 1)); // number!-needed
    goto v_20876;
v_20877:
    v_21048 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20878;
v_20879:
    goto v_20875;
v_20876:
    goto v_20877;
v_20878:
    if (v_21049 == v_21048) goto v_20873;
    else goto v_20874;
v_20873:
    goto v_20854;
v_20874:
    goto v_20889;
v_20883:
    v_21050 = stack[-2];
    goto v_20884;
v_20885:
    v_21049 = stack[-1];
    goto v_20886;
v_20887:
    v_21048 = qvalue(elt(env, 2)); // work!-vector1
    goto v_20888;
v_20889:
    goto v_20883;
v_20884:
    goto v_20885;
v_20886:
    goto v_20887;
v_20888:
    fn = elt(env, 6); // copy!-vector
    v_21048 = (*qfnn(fn))(fn, 3, v_21050, v_21049, v_21048);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_21048; // dwork1
    goto v_20900;
v_20894:
    v_21048 = stack[-3];
    v_21048 = qcar(v_21048);
    v_21050 = qcar(v_21048);
    goto v_20895;
v_20896:
    v_21048 = stack[-3];
    v_21048 = qcar(v_21048);
    v_21049 = qcdr(v_21048);
    goto v_20897;
v_20898:
    v_21048 = qvalue(elt(env, 4)); // work!-vector2
    goto v_20899;
v_20900:
    goto v_20894;
v_20895:
    goto v_20896;
v_20897:
    goto v_20898;
v_20899:
    fn = elt(env, 6); // copy!-vector
    v_21048 = (*qfnn(fn))(fn, 3, v_21050, v_21049, v_21048);
    env = stack[-5];
    qvalue(elt(env, 5)) = v_21048; // dwork2
    goto v_20917;
v_20909:
    v_21051 = qvalue(elt(env, 2)); // work!-vector1
    goto v_20910;
v_20911:
    v_21050 = qvalue(elt(env, 3)); // dwork1
    goto v_20912;
v_20913:
    v_21049 = qvalue(elt(env, 4)); // work!-vector2
    goto v_20914;
v_20915:
    v_21048 = qvalue(elt(env, 5)); // dwork2
    goto v_20916;
v_20917:
    goto v_20909;
v_20910:
    goto v_20911;
v_20912:
    goto v_20913;
v_20914:
    goto v_20915;
v_20916:
    fn = elt(env, 7); // gcd!-in!-vector
    v_21048 = (*qfnn(fn))(fn, 4, v_21051, v_21050, v_21049, v_21048);
    env = stack[-5];
    qvalue(elt(env, 3)) = v_21048; // dwork1
    goto v_20934;
v_20930:
    v_21049 = qvalue(elt(env, 3)); // dwork1
    goto v_20931;
v_20932:
    v_21048 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20933;
v_20934:
    goto v_20930;
v_20931:
    goto v_20932;
v_20933:
    if (v_21049 == v_21048) goto v_20928;
    else goto v_20929;
v_20928:
    v_21048 = lisp_true;
    goto v_20927;
v_20929:
    goto v_20944;
v_20940:
    v_21049 = qvalue(elt(env, 3)); // dwork1
    goto v_20941;
v_20942:
    v_21048 = stack[-3];
    v_21048 = qcar(v_21048);
    v_21048 = qcdr(v_21048);
    goto v_20943;
v_20944:
    goto v_20940;
v_20941:
    goto v_20942;
v_20943:
    v_21048 = (equal(v_21049, v_21048) ? lisp_true : nil);
    goto v_20927;
    v_21048 = nil;
v_20927:
    if (v_21048 == nil) goto v_20925;
    goto v_20854;
v_20925:
    goto v_20957;
v_20951:
    v_21048 = stack[-3];
    v_21048 = qcar(v_21048);
    v_21050 = qcar(v_21048);
    goto v_20952;
v_20953:
    v_21048 = stack[-3];
    v_21048 = qcar(v_21048);
    v_21049 = qcdr(v_21048);
    goto v_20954;
v_20955:
    v_21048 = qvalue(elt(env, 4)); // work!-vector2
    goto v_20956;
v_20957:
    goto v_20951;
v_20952:
    goto v_20953;
v_20954:
    goto v_20955;
v_20956:
    fn = elt(env, 6); // copy!-vector
    v_21048 = (*qfnn(fn))(fn, 3, v_21050, v_21049, v_21048);
    env = stack[-5];
    qvalue(elt(env, 5)) = v_21048; // dwork2
    goto v_20974;
v_20966:
    v_21051 = qvalue(elt(env, 4)); // work!-vector2
    goto v_20967;
v_20968:
    v_21050 = qvalue(elt(env, 5)); // dwork2
    goto v_20969;
v_20970:
    v_21049 = qvalue(elt(env, 2)); // work!-vector1
    goto v_20971;
v_20972:
    v_21048 = qvalue(elt(env, 3)); // dwork1
    goto v_20973;
v_20974:
    goto v_20966;
v_20967:
    goto v_20968;
v_20969:
    goto v_20970;
v_20971:
    goto v_20972;
v_20973:
    fn = elt(env, 8); // quotfail!-in!-vector
    v_21048 = (*qfnn(fn))(fn, 4, v_21051, v_21050, v_21049, v_21048);
    env = stack[-5];
    qvalue(elt(env, 5)) = v_21048; // dwork2
    v_21048 = qvalue(elt(env, 3)); // dwork1
    v_21048 = Lmkvect(nil, v_21048);
    env = stack[-5];
    stack[-1] = v_21048;
    goto v_20988;
v_20982:
    v_21050 = qvalue(elt(env, 2)); // work!-vector1
    goto v_20983;
v_20984:
    v_21049 = qvalue(elt(env, 3)); // dwork1
    goto v_20985;
v_20986:
    v_21048 = stack[-1];
    goto v_20987;
v_20988:
    goto v_20982;
v_20983:
    goto v_20984;
v_20985:
    goto v_20986;
v_20987:
    fn = elt(env, 6); // copy!-vector
    v_21048 = (*qfnn(fn))(fn, 3, v_21050, v_21049, v_21048);
    env = stack[-5];
    goto v_20999;
v_20993:
    v_21050 = stack[-1];
    goto v_20994;
v_20995:
    v_21049 = qvalue(elt(env, 3)); // dwork1
    goto v_20996;
v_20997:
    v_21048 = stack[-4];
    goto v_20998;
v_20999:
    goto v_20993;
v_20994:
    goto v_20995;
v_20996:
    goto v_20997;
v_20998:
    v_21048 = acons(v_21050, v_21049, v_21048);
    env = stack[-5];
    stack[-4] = v_21048;
    goto v_21010;
v_21004:
    stack[-2] = qvalue(elt(env, 4)); // work!-vector2
    goto v_21005;
v_21006:
    stack[-1] = qvalue(elt(env, 5)); // dwork2
    goto v_21007;
v_21008:
    v_21048 = qvalue(elt(env, 5)); // dwork2
    v_21048 = Lmkvect(nil, v_21048);
    env = stack[-5];
    stack[-3] = v_21048;
    goto v_21009;
v_21010:
    goto v_21004;
v_21005:
    goto v_21006;
v_21007:
    goto v_21008;
v_21009:
    fn = elt(env, 6); // copy!-vector
    v_21048 = (*qfnn(fn))(fn, 3, stack[-2], stack[-1], v_21048);
    env = stack[-5];
    goto v_21022;
v_21016:
    v_21050 = stack[-3];
    goto v_21017;
v_21018:
    v_21049 = qvalue(elt(env, 5)); // dwork2
    goto v_21019;
v_21020:
    v_21048 = stack[0];
    goto v_21021;
v_21022:
    goto v_21016;
v_21017:
    goto v_21018;
v_21019:
    goto v_21020;
v_21021:
    v_21048 = acons(v_21050, v_21049, v_21048);
    env = stack[-5];
    stack[0] = v_21048;
    v_21048 = qvalue(elt(env, 1)); // number!-needed
    v_21048 = (LispObject)((intptr_t)(v_21048) - 0x10);
    qvalue(elt(env, 1)) = v_21048; // number!-needed
    goto v_21033;
v_21029:
    v_21049 = stack[-4];
    goto v_21030;
v_21031:
    v_21048 = stack[0];
    goto v_21032;
v_21033:
    goto v_21029;
v_21030:
    goto v_21031;
v_21032:
    return cons(v_21049, v_21048);
v_20854:
    goto v_21043;
v_21037:
    v_21050 = stack[-4];
    goto v_21038;
v_21039:
    v_21048 = stack[-3];
    v_21049 = qcar(v_21048);
    goto v_21040;
v_21041:
    v_21048 = stack[0];
    goto v_21042;
v_21043:
    goto v_21037;
v_21038:
    goto v_21039;
v_21040:
    goto v_21041;
v_21042:
    return list2star(v_21050, v_21049, v_21048);
    goto v_20840;
    v_21048 = nil;
v_20840:
    return onevalue(v_21048);
}



// Code for lex_init

static LispObject CC_lex_init(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20862, v_20863;
    LispObject fn;
    argcheck(nargs, 0, "lex_init");
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
    v_20862 = (LispObject)1024+TAG_FIXNUM; // 64
    v_20862 = Lmkvect(nil, v_20862);
    env = stack[0];
    qvalue(elt(env, 1)) = v_20862; // last64
    v_20862 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 2)) = v_20862; // last64p
    v_20862 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 3)) = v_20862; // which_line
    v_20862 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 4)) = v_20862; // if_depth
    v_20862 = qvalue(elt(env, 5)); // !*tracelex
    if (v_20862 == nil) goto v_20844;
    goto v_20854;
v_20850:
    v_20863 = Lposn(nil, 0);
    env = stack[0];
    goto v_20851;
v_20852:
    v_20862 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20853;
v_20854:
    goto v_20850;
v_20851:
    goto v_20852;
v_20853:
    if (v_20863 == v_20862) goto v_20849;
    v_20862 = Lterpri(nil, 0);
    env = stack[0];
    goto v_20847;
v_20849:
v_20847:
    v_20862 = elt(env, 6); // "yylex initialized"
    v_20862 = Lprintc(nil, v_20862);
    env = stack[0];
    goto v_20842;
v_20844:
v_20842:
    v_20862 = nil;
    qvalue(elt(env, 7)) = v_20862; // lex_peeked
    {
        fn = elt(env, 8); // yyreadch
        return (*qfnn(fn))(fn, 0);
    }
}



// Code for give!*position

static LispObject CC_giveHposition(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20901, v_20902;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_20836;
    stack[-3] = v_20835;
// end of prologue
    v_20901 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_20901;
    v_20901 = nil;
    stack[-1] = v_20901;
v_20846:
    v_20901 = stack[-1];
    if (v_20901 == nil) goto v_20853;
    else goto v_20854;
v_20853:
    goto v_20861;
v_20857:
    stack[0] = stack[-4];
    goto v_20858;
v_20859:
    v_20901 = stack[-2];
    v_20901 = Llength(nil, v_20901);
    env = stack[-5];
    goto v_20860;
v_20861:
    goto v_20857;
v_20858:
    goto v_20859;
v_20860:
    v_20901 = (LispObject)lesseq2(stack[0], v_20901);
    v_20901 = v_20901 ? lisp_true : nil;
    env = stack[-5];
    goto v_20852;
v_20854:
    v_20901 = nil;
    goto v_20852;
    v_20901 = nil;
v_20852:
    if (v_20901 == nil) goto v_20849;
    else goto v_20850;
v_20849:
    goto v_20845;
v_20850:
    goto v_20877;
v_20873:
    goto v_20883;
v_20879:
    v_20902 = stack[-2];
    goto v_20880;
v_20881:
    v_20901 = stack[-4];
    goto v_20882;
v_20883:
    goto v_20879;
v_20880:
    goto v_20881;
v_20882:
    fn = elt(env, 2); // nth
    v_20902 = (*qfn2(fn))(fn, v_20902, v_20901);
    env = stack[-5];
    goto v_20874;
v_20875:
    v_20901 = stack[-3];
    goto v_20876;
v_20877:
    goto v_20873;
v_20874:
    goto v_20875;
v_20876:
    if (equal(v_20902, v_20901)) goto v_20871;
    else goto v_20872;
v_20871:
    v_20901 = lisp_true;
    stack[-1] = v_20901;
    goto v_20870;
v_20872:
    v_20901 = stack[-4];
    v_20901 = add1(v_20901);
    env = stack[-5];
    stack[-4] = v_20901;
    goto v_20870;
v_20870:
    goto v_20846;
v_20845:
    v_20901 = stack[-1];
    if (v_20901 == nil) goto v_20895;
    else goto v_20896;
v_20895:
    v_20901 = elt(env, 1); // "error in give position"
    fn = elt(env, 3); // rederr
    v_20901 = (*qfn1(fn))(fn, v_20901);
    goto v_20894;
v_20896:
v_20894:
    v_20901 = stack[-4];
    return onevalue(v_20901);
}



// Code for talp_specsub

static LispObject CC_talp_specsub(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20953, v_20954, v_20955;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[0] = v_20836;
    stack[-4] = v_20835;
// end of prologue
    goto v_20854;
v_20850:
    v_20954 = stack[0];
    goto v_20851;
v_20852:
    v_20953 = elt(env, 1); // true
    goto v_20853;
v_20854:
    goto v_20850;
v_20851:
    goto v_20852;
v_20853:
    if (v_20954 == v_20953) goto v_20848;
    else goto v_20849;
v_20848:
    v_20953 = lisp_true;
    goto v_20847;
v_20849:
    goto v_20864;
v_20860:
    v_20954 = stack[0];
    goto v_20861;
v_20862:
    v_20953 = elt(env, 2); // false
    goto v_20863;
v_20864:
    goto v_20860;
v_20861:
    goto v_20862;
v_20863:
    v_20953 = (v_20954 == v_20953 ? lisp_true : nil);
    goto v_20847;
    v_20953 = nil;
v_20847:
    if (v_20953 == nil) goto v_20845;
    v_20953 = stack[0];
    goto v_20841;
v_20845:
    v_20953 = stack[0];
    fn = elt(env, 3); // talp_atfp
    v_20953 = (*qfn1(fn))(fn, v_20953);
    env = stack[-6];
    if (v_20953 == nil) goto v_20872;
    goto v_20882;
v_20876:
    v_20953 = stack[-4];
    v_20955 = qcar(v_20953);
    goto v_20877;
v_20878:
    v_20953 = stack[-4];
    v_20954 = qcdr(v_20953);
    goto v_20879;
v_20880:
    v_20953 = stack[0];
    goto v_20881;
v_20882:
    goto v_20876;
v_20877:
    goto v_20878;
v_20879:
    goto v_20880;
v_20881:
    {
        fn = elt(env, 4); // talp_specsubat
        return (*qfnn(fn))(fn, 3, v_20955, v_20954, v_20953);
    }
v_20872:
    v_20953 = stack[0];
    fn = elt(env, 5); // talp_op
    v_20953 = (*qfn1(fn))(fn, v_20953);
    env = stack[-6];
    goto v_20895;
v_20891:
    stack[-5] = v_20953;
    goto v_20892;
v_20893:
    v_20953 = stack[0];
    fn = elt(env, 6); // talp_argl
    v_20953 = (*qfn1(fn))(fn, v_20953);
    env = stack[-6];
    stack[-3] = v_20953;
    v_20953 = stack[-3];
    if (v_20953 == nil) goto v_20907;
    else goto v_20908;
v_20907:
    v_20953 = nil;
    goto v_20901;
v_20908:
    v_20953 = stack[-3];
    v_20953 = qcar(v_20953);
    goto v_20920;
v_20916:
    v_20954 = stack[-4];
    goto v_20917;
v_20918:
    goto v_20919;
v_20920:
    goto v_20916;
v_20917:
    goto v_20918;
v_20919:
    v_20953 = CC_talp_specsub(elt(env, 0), v_20954, v_20953);
    env = stack[-6];
    v_20953 = ncons(v_20953);
    env = stack[-6];
    stack[-1] = v_20953;
    stack[-2] = v_20953;
v_20902:
    v_20953 = stack[-3];
    v_20953 = qcdr(v_20953);
    stack[-3] = v_20953;
    v_20953 = stack[-3];
    if (v_20953 == nil) goto v_20927;
    else goto v_20928;
v_20927:
    v_20953 = stack[-2];
    goto v_20901;
v_20928:
    goto v_20936;
v_20932:
    stack[0] = stack[-1];
    goto v_20933;
v_20934:
    v_20953 = stack[-3];
    v_20953 = qcar(v_20953);
    goto v_20947;
v_20943:
    v_20954 = stack[-4];
    goto v_20944;
v_20945:
    goto v_20946;
v_20947:
    goto v_20943;
v_20944:
    goto v_20945;
v_20946:
    v_20953 = CC_talp_specsub(elt(env, 0), v_20954, v_20953);
    env = stack[-6];
    v_20953 = ncons(v_20953);
    env = stack[-6];
    goto v_20935;
v_20936:
    goto v_20932;
v_20933:
    goto v_20934;
v_20935:
    v_20953 = Lrplacd(nil, stack[0], v_20953);
    env = stack[-6];
    v_20953 = stack[-1];
    v_20953 = qcdr(v_20953);
    stack[-1] = v_20953;
    goto v_20902;
v_20901:
    goto v_20894;
v_20895:
    goto v_20891;
v_20892:
    goto v_20893;
v_20894:
    {
        LispObject v_20962 = stack[-5];
        return cons(v_20962, v_20953);
    }
v_20841:
    return onevalue(v_20953);
}



// Code for mconv1

static LispObject CC_mconv1(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20885, v_20886;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_20835;
// end of prologue
    stack[-2] = nil;
v_20840:
    v_20885 = stack[-1];
    if (!consp(v_20885)) goto v_20847;
    else goto v_20848;
v_20847:
    v_20885 = lisp_true;
    goto v_20846;
v_20848:
    v_20885 = stack[-1];
    v_20885 = qcar(v_20885);
    v_20885 = (consp(v_20885) ? nil : lisp_true);
    goto v_20846;
    v_20885 = nil;
v_20846:
    if (v_20885 == nil) goto v_20844;
    goto v_20861;
v_20857:
    stack[0] = stack[-2];
    goto v_20858;
v_20859:
    v_20885 = stack[-1];
    fn = elt(env, 1); // drnconv
    v_20885 = (*qfn1(fn))(fn, v_20885);
    env = stack[-3];
    goto v_20860;
v_20861:
    goto v_20857;
v_20858:
    goto v_20859;
v_20860:
    {
        LispObject v_20890 = stack[0];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_20890, v_20885);
    }
v_20844:
    goto v_20874;
v_20868:
    v_20885 = stack[-1];
    v_20885 = qcar(v_20885);
    stack[0] = qcar(v_20885);
    goto v_20869;
v_20870:
    v_20885 = stack[-1];
    v_20885 = qcar(v_20885);
    v_20885 = qcdr(v_20885);
    v_20886 = CC_mconv1(elt(env, 0), v_20885);
    env = stack[-3];
    goto v_20871;
v_20872:
    v_20885 = stack[-2];
    goto v_20873;
v_20874:
    goto v_20868;
v_20869:
    goto v_20870;
v_20871:
    goto v_20872;
v_20873:
    v_20885 = acons(stack[0], v_20886, v_20885);
    env = stack[-3];
    stack[-2] = v_20885;
    v_20885 = stack[-1];
    v_20885 = qcdr(v_20885);
    stack[-1] = v_20885;
    goto v_20840;
    v_20885 = nil;
    return onevalue(v_20885);
}



// Code for pasf_uprap

static LispObject CC_pasf_uprap(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20845, v_20846;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20845 = v_20835;
// end of prologue
    goto v_20842;
v_20838:
    v_20846 = v_20845;
    goto v_20839;
v_20840:
    v_20845 = nil;
    goto v_20841;
v_20842:
    goto v_20838;
v_20839:
    goto v_20840;
v_20841:
    {
        fn = elt(env, 1); // pasf_uprap1
        return (*qfn2(fn))(fn, v_20846, v_20845);
    }
}



// Code for ciml

static LispObject CC_ciml(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20856, v_20857;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_20835;
// end of prologue
    v_20856 = elt(env, 1); // "<ci"
    fn = elt(env, 4); // printout
    v_20856 = (*qfn1(fn))(fn, v_20856);
    env = stack[-1];
    goto v_20846;
v_20842:
    v_20856 = stack[0];
    v_20857 = qcar(v_20856);
    goto v_20843;
v_20844:
    v_20856 = elt(env, 2); // ""
    goto v_20845;
v_20846:
    goto v_20842;
v_20843:
    goto v_20844;
v_20845:
    fn = elt(env, 5); // attributesml
    v_20856 = (*qfn2(fn))(fn, v_20857, v_20856);
    env = stack[-1];
    v_20856 = stack[0];
    v_20856 = qcdr(v_20856);
    v_20856 = qcar(v_20856);
    v_20856 = Lprinc(nil, v_20856);
    env = stack[-1];
    v_20856 = elt(env, 3); // "</ci>"
    v_20856 = Lprinc(nil, v_20856);
    v_20856 = nil;
    return onevalue(v_20856);
}



// Code for matrixp

static LispObject CC_matrixp(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20879, v_20880, v_20881;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20880 = v_20835;
// end of prologue
    v_20879 = v_20880;
    v_20879 = Lconsp(nil, v_20879);
    env = stack[0];
    if (v_20879 == nil) goto v_20841;
    else goto v_20842;
v_20841:
    v_20879 = v_20880;
    fn = elt(env, 3); // reval
    v_20879 = (*qfn1(fn))(fn, v_20879);
    env = stack[0];
    v_20880 = v_20879;
    goto v_20840;
v_20842:
v_20840:
    goto v_20860;
v_20856:
    v_20881 = v_20880;
    goto v_20857;
v_20858:
    v_20879 = elt(env, 1); // mat
    goto v_20859;
v_20860:
    goto v_20856;
v_20857:
    goto v_20858;
v_20859:
    if (!consp(v_20881)) goto v_20853;
    v_20881 = qcar(v_20881);
    if (v_20881 == v_20879) goto v_20854;
v_20853:
    goto v_20868;
v_20864:
    goto v_20865;
v_20866:
    v_20879 = elt(env, 2); // sparsemat
    goto v_20867;
v_20868:
    goto v_20864;
v_20865:
    goto v_20866;
v_20867:
    v_20879 = Leqcar(nil, v_20880, v_20879);
    v_20879 = (v_20879 == nil ? lisp_true : nil);
    goto v_20852;
v_20854:
    v_20879 = nil;
    goto v_20852;
    v_20879 = nil;
v_20852:
    if (v_20879 == nil) goto v_20850;
    v_20879 = nil;
    goto v_20838;
v_20850:
    v_20879 = lisp_true;
    goto v_20838;
    v_20879 = nil;
v_20838:
    return onevalue(v_20879);
}



// Code for evequal

static LispObject CC_evequal(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20893, v_20894, v_20895, v_20896, v_20897;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20895 = v_20836;
    v_20896 = v_20835;
// end of prologue
v_20840:
    v_20893 = v_20896;
    if (v_20893 == nil) goto v_20847;
    else goto v_20848;
v_20847:
    v_20893 = v_20895;
    v_20893 = (v_20893 == nil ? lisp_true : nil);
    goto v_20846;
v_20848:
    v_20893 = nil;
    goto v_20846;
    v_20893 = nil;
v_20846:
    if (v_20893 == nil) goto v_20844;
    v_20893 = lisp_true;
    goto v_20839;
v_20844:
    v_20893 = v_20896;
    if (v_20893 == nil) goto v_20856;
    else goto v_20857;
v_20856:
    v_20893 = elt(env, 1); // (0)
    v_20896 = v_20893;
    goto v_20840;
v_20857:
    v_20893 = v_20895;
    if (v_20893 == nil) goto v_20860;
    else goto v_20861;
v_20860:
    v_20893 = elt(env, 1); // (0)
    v_20895 = v_20893;
    goto v_20840;
v_20861:
    goto v_20874;
v_20870:
    v_20897 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20871;
v_20872:
    goto v_20880;
v_20876:
    v_20893 = v_20896;
    v_20894 = qcar(v_20893);
    goto v_20877;
v_20878:
    v_20893 = v_20895;
    v_20893 = qcar(v_20893);
    goto v_20879;
v_20880:
    goto v_20876;
v_20877:
    goto v_20878;
v_20879:
    v_20893 = (LispObject)(intptr_t)((intptr_t)v_20894 - (intptr_t)v_20893 + TAG_FIXNUM);
    goto v_20873;
v_20874:
    goto v_20870;
v_20871:
    goto v_20872;
v_20873:
    if (v_20897 == v_20893) goto v_20868;
    else goto v_20869;
v_20868:
    v_20893 = v_20896;
    v_20893 = qcdr(v_20893);
    v_20896 = v_20893;
    v_20893 = v_20895;
    v_20893 = qcdr(v_20893);
    v_20895 = v_20893;
    goto v_20840;
v_20869:
    v_20893 = nil;
    goto v_20839;
    goto v_20842;
v_20842:
    v_20893 = nil;
v_20839:
    return onevalue(v_20893);
}



// Code for exdff0

static LispObject CC_exdff0(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20940, v_20941;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_20835;
// end of prologue
    stack[-3] = nil;
v_20841:
    v_20940 = stack[-2];
    if (!consp(v_20940)) goto v_20850;
    else goto v_20851;
v_20850:
    v_20940 = lisp_true;
    goto v_20849;
v_20851:
    v_20940 = stack[-2];
    v_20940 = qcar(v_20940);
    v_20940 = (consp(v_20940) ? nil : lisp_true);
    goto v_20849;
    v_20940 = nil;
v_20849:
    if (v_20940 == nil) goto v_20847;
    goto v_20842;
v_20847:
    goto v_20864;
v_20860:
    goto v_20870;
v_20866:
    goto v_20876;
v_20872:
    goto v_20882;
v_20878:
    goto v_20889;
v_20885:
    v_20940 = stack[-2];
    v_20940 = qcar(v_20940);
    v_20941 = qcar(v_20940);
    goto v_20886;
v_20887:
    v_20940 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20888;
v_20889:
    goto v_20885;
v_20886:
    goto v_20887;
v_20888:
    v_20940 = cons(v_20941, v_20940);
    env = stack[-4];
    v_20941 = ncons(v_20940);
    env = stack[-4];
    goto v_20879;
v_20880:
    v_20940 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20881;
v_20882:
    goto v_20878;
v_20879:
    goto v_20880;
v_20881:
    stack[0] = cons(v_20941, v_20940);
    env = stack[-4];
    goto v_20873;
v_20874:
    v_20940 = stack[-2];
    v_20940 = qcar(v_20940);
    v_20940 = qcdr(v_20940);
    v_20940 = CC_exdff0(elt(env, 0), v_20940);
    env = stack[-4];
    goto v_20875;
v_20876:
    goto v_20872;
v_20873:
    goto v_20874;
v_20875:
    fn = elt(env, 1); // multsqpf
    stack[-1] = (*qfn2(fn))(fn, stack[0], v_20940);
    env = stack[-4];
    goto v_20867;
v_20868:
    goto v_20904;
v_20900:
    v_20940 = stack[-2];
    v_20940 = qcar(v_20940);
    v_20940 = qcar(v_20940);
    fn = elt(env, 2); // exdfp0
    stack[0] = (*qfn1(fn))(fn, v_20940);
    env = stack[-4];
    goto v_20901;
v_20902:
    goto v_20914;
v_20910:
    v_20940 = stack[-2];
    v_20940 = qcar(v_20940);
    v_20941 = qcdr(v_20940);
    goto v_20911;
v_20912:
    v_20940 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20913;
v_20914:
    goto v_20910;
v_20911:
    goto v_20912;
v_20913:
    v_20940 = cons(v_20941, v_20940);
    env = stack[-4];
    goto v_20903;
v_20904:
    goto v_20900;
v_20901:
    goto v_20902;
v_20903:
    fn = elt(env, 3); // multpfsq
    v_20940 = (*qfn2(fn))(fn, stack[0], v_20940);
    env = stack[-4];
    goto v_20869;
v_20870:
    goto v_20866;
v_20867:
    goto v_20868;
v_20869:
    fn = elt(env, 4); // addpf
    v_20941 = (*qfn2(fn))(fn, stack[-1], v_20940);
    env = stack[-4];
    goto v_20861;
v_20862:
    v_20940 = stack[-3];
    goto v_20863;
v_20864:
    goto v_20860;
v_20861:
    goto v_20862;
v_20863:
    v_20940 = cons(v_20941, v_20940);
    env = stack[-4];
    stack[-3] = v_20940;
    v_20940 = stack[-2];
    v_20940 = qcdr(v_20940);
    stack[-2] = v_20940;
    goto v_20841;
v_20842:
    v_20940 = nil;
    v_20941 = v_20940;
v_20843:
    v_20940 = stack[-3];
    if (v_20940 == nil) goto v_20925;
    else goto v_20926;
v_20925:
    v_20940 = v_20941;
    goto v_20840;
v_20926:
    goto v_20934;
v_20930:
    v_20940 = stack[-3];
    v_20940 = qcar(v_20940);
    goto v_20931;
v_20932:
    goto v_20933;
v_20934:
    goto v_20930;
v_20931:
    goto v_20932;
v_20933:
    fn = elt(env, 4); // addpf
    v_20940 = (*qfn2(fn))(fn, v_20940, v_20941);
    env = stack[-4];
    v_20941 = v_20940;
    v_20940 = stack[-3];
    v_20940 = qcdr(v_20940);
    stack[-3] = v_20940;
    goto v_20843;
v_20840:
    return onevalue(v_20940);
}



// Code for gftimes

static LispObject CC_gftimes(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20862, v_20863, v_20864;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20863 = v_20836;
    v_20864 = v_20835;
// end of prologue
    v_20862 = v_20864;
    v_20862 = qcar(v_20862);
    if (!consp(v_20862)) goto v_20840;
    else goto v_20841;
v_20840:
    goto v_20849;
v_20845:
    v_20862 = v_20864;
    goto v_20846;
v_20847:
    goto v_20848;
v_20849:
    goto v_20845;
v_20846:
    goto v_20847;
v_20848:
    {
        fn = elt(env, 1); // gfftimes
        return (*qfn2(fn))(fn, v_20862, v_20863);
    }
v_20841:
    goto v_20859;
v_20855:
    v_20862 = v_20864;
    goto v_20856;
v_20857:
    goto v_20858;
v_20859:
    goto v_20855;
v_20856:
    goto v_20857;
v_20858:
    {
        fn = elt(env, 2); // gbftimes
        return (*qfn2(fn))(fn, v_20862, v_20863);
    }
    v_20862 = nil;
    return onevalue(v_20862);
}



// Code for getphystypeall

static LispObject CC_getphystypeall(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20877, v_20878;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_20835;
// end of prologue
    goto v_20850;
v_20846:
    v_20878 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20847;
v_20848:
    v_20877 = stack[0];
    goto v_20849;
v_20850:
    goto v_20846;
v_20847:
    goto v_20848;
v_20849:
    fn = elt(env, 2); // deleteall
    v_20877 = (*qfn2(fn))(fn, v_20878, v_20877);
    env = stack[-2];
    fn = elt(env, 3); // collectphystype
    v_20877 = (*qfn1(fn))(fn, v_20877);
    env = stack[-2];
    v_20878 = v_20877;
    if (v_20877 == nil) goto v_20842;
    else goto v_20843;
v_20842:
    v_20877 = nil;
    goto v_20839;
v_20843:
    v_20877 = v_20878;
    v_20877 = qcdr(v_20877);
    if (v_20877 == nil) goto v_20855;
    goto v_20863;
v_20859:
    stack[-1] = elt(env, 0); // getphystypeall
    goto v_20860;
v_20861:
    goto v_20870;
v_20866:
    v_20878 = elt(env, 1); // "PHYSOP type mismatch in"
    goto v_20867;
v_20868:
    v_20877 = stack[0];
    goto v_20869;
v_20870:
    goto v_20866;
v_20867:
    goto v_20868;
v_20869:
    v_20877 = list2(v_20878, v_20877);
    env = stack[-2];
    goto v_20862;
v_20863:
    goto v_20859;
v_20860:
    goto v_20861;
v_20862:
    fn = elt(env, 4); // rederr2
    v_20877 = (*qfn2(fn))(fn, stack[-1], v_20877);
    goto v_20841;
v_20855:
    v_20877 = v_20878;
    v_20877 = qcar(v_20877);
    goto v_20839;
v_20841:
    v_20877 = nil;
v_20839:
    return onevalue(v_20877);
}



// Code for groeb!=crita

static LispObject CC_groebMcrita(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20845, v_20846;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20845 = v_20835;
// end of prologue
    goto v_20842;
v_20838:
    v_20846 = v_20845;
    goto v_20839;
v_20840:
    v_20845 = elt(env, 1); // groeb!=testa
    goto v_20841;
v_20842:
    goto v_20838;
v_20839:
    goto v_20840;
v_20841:
    {
        fn = elt(env, 2); // listminimize
        return (*qfn2(fn))(fn, v_20846, v_20845);
    }
}



// Code for taydegree!<

static LispObject CC_taydegreeR(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20894, v_20895;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_20836;
    stack[-2] = v_20835;
// end of prologue
v_20842:
    v_20894 = stack[-2];
    v_20894 = qcar(v_20894);
    stack[-3] = v_20894;
    v_20894 = stack[-1];
    v_20894 = qcar(v_20894);
    stack[0] = v_20894;
v_20843:
    goto v_20857;
v_20853:
    v_20894 = stack[-3];
    v_20895 = qcar(v_20894);
    goto v_20854;
v_20855:
    v_20894 = stack[0];
    v_20894 = qcar(v_20894);
    goto v_20856;
v_20857:
    goto v_20853;
v_20854:
    goto v_20855;
v_20856:
    fn = elt(env, 1); // tayexp!-greaterp
    v_20894 = (*qfn2(fn))(fn, v_20895, v_20894);
    env = stack[-4];
    if (v_20894 == nil) goto v_20851;
    v_20894 = nil;
    goto v_20841;
v_20851:
    goto v_20870;
v_20866:
    v_20894 = stack[-3];
    v_20895 = qcar(v_20894);
    goto v_20867;
v_20868:
    v_20894 = stack[0];
    v_20894 = qcar(v_20894);
    goto v_20869;
v_20870:
    goto v_20866;
v_20867:
    goto v_20868;
v_20869:
    fn = elt(env, 2); // tayexp!-lessp
    v_20894 = (*qfn2(fn))(fn, v_20895, v_20894);
    env = stack[-4];
    if (v_20894 == nil) goto v_20864;
    v_20894 = lisp_true;
    goto v_20841;
v_20864:
    v_20894 = stack[-3];
    v_20894 = qcdr(v_20894);
    stack[-3] = v_20894;
    v_20894 = stack[0];
    v_20894 = qcdr(v_20894);
    stack[0] = v_20894;
    v_20894 = stack[-3];
    if (v_20894 == nil) goto v_20883;
    goto v_20843;
v_20883:
    v_20894 = stack[-2];
    v_20894 = qcdr(v_20894);
    stack[-2] = v_20894;
    v_20894 = stack[-1];
    v_20894 = qcdr(v_20894);
    stack[-1] = v_20894;
    v_20894 = stack[-2];
    if (v_20894 == nil) goto v_20892;
    goto v_20842;
v_20892:
    v_20894 = nil;
v_20841:
    return onevalue(v_20894);
}



// Code for cl_pnf2

static LispObject CC_cl_pnf2(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_21150, v_21151, v_21152;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_20835;
// end of prologue
    v_21150 = stack[0];
    if (!consp(v_21150)) goto v_20843;
    else goto v_20844;
v_20843:
    v_21150 = stack[0];
    goto v_20842;
v_20844:
    v_21150 = stack[0];
    v_21150 = qcar(v_21150);
    goto v_20842;
    v_21150 = nil;
v_20842:
    stack[-1] = v_21150;
    goto v_20863;
v_20859:
    v_21151 = stack[-1];
    goto v_20860;
v_20861:
    v_21150 = elt(env, 1); // ex
    goto v_20862;
v_20863:
    goto v_20859;
v_20860:
    goto v_20861;
v_20862:
    if (v_21151 == v_21150) goto v_20857;
    else goto v_20858;
v_20857:
    v_21150 = lisp_true;
    goto v_20856;
v_20858:
    goto v_20873;
v_20869:
    v_21151 = stack[-1];
    goto v_20870;
v_20871:
    v_21150 = elt(env, 2); // all
    goto v_20872;
v_20873:
    goto v_20869;
v_20870:
    goto v_20871;
v_20872:
    v_21150 = (v_21151 == v_21150 ? lisp_true : nil);
    goto v_20856;
    v_21150 = nil;
v_20856:
    if (v_21150 == nil) goto v_20854;
    v_21150 = stack[0];
    {
        fn = elt(env, 15); // cl_pnf2!-quantifier
        return (*qfn1(fn))(fn, v_21150);
    }
v_20854:
    goto v_20891;
v_20887:
    v_21151 = stack[-1];
    goto v_20888;
v_20889:
    v_21150 = elt(env, 3); // or
    goto v_20890;
v_20891:
    goto v_20887;
v_20888:
    goto v_20889;
v_20890:
    if (v_21151 == v_21150) goto v_20885;
    else goto v_20886;
v_20885:
    v_21150 = lisp_true;
    goto v_20884;
v_20886:
    goto v_20901;
v_20897:
    v_21151 = stack[-1];
    goto v_20898;
v_20899:
    v_21150 = elt(env, 4); // and
    goto v_20900;
v_20901:
    goto v_20897;
v_20898:
    goto v_20899;
v_20900:
    v_21150 = (v_21151 == v_21150 ? lisp_true : nil);
    goto v_20884;
    v_21150 = nil;
v_20884:
    if (v_21150 == nil) goto v_20882;
    v_21150 = stack[0];
    {
        fn = elt(env, 16); // cl_pnf2!-junctor
        return (*qfn1(fn))(fn, v_21150);
    }
v_20882:
    goto v_20919;
v_20915:
    v_21151 = stack[-1];
    goto v_20916;
v_20917:
    v_21150 = elt(env, 5); // true
    goto v_20918;
v_20919:
    goto v_20915;
v_20916:
    goto v_20917;
v_20918:
    if (v_21151 == v_21150) goto v_20913;
    else goto v_20914;
v_20913:
    v_21150 = lisp_true;
    goto v_20912;
v_20914:
    goto v_20929;
v_20925:
    v_21151 = stack[-1];
    goto v_20926;
v_20927:
    v_21150 = elt(env, 6); // false
    goto v_20928;
v_20929:
    goto v_20925;
v_20926:
    goto v_20927;
v_20928:
    v_21150 = (v_21151 == v_21150 ? lisp_true : nil);
    goto v_20912;
    v_21150 = nil;
v_20912:
    if (v_21150 == nil) goto v_20910;
    v_21150 = stack[0];
    return ncons(v_21150);
v_20910:
    goto v_20944;
v_20940:
    v_21151 = stack[-1];
    goto v_20941;
v_20942:
    v_21150 = elt(env, 0); // cl_pnf2
    goto v_20943;
v_20944:
    goto v_20940;
v_20941:
    goto v_20942;
v_20943:
    fn = elt(env, 17); // rl_external
    v_21150 = (*qfn2(fn))(fn, v_21151, v_21150);
    env = stack[-2];
    v_21151 = v_21150;
    if (v_21150 == nil) goto v_20938;
    goto v_20952;
v_20948:
    stack[-1] = v_21151;
    goto v_20949;
v_20950:
    v_21150 = stack[0];
    v_21150 = ncons(v_21150);
    env = stack[-2];
    goto v_20951;
v_20952:
    goto v_20948;
v_20949:
    goto v_20950;
v_20951:
    {
        LispObject v_21155 = stack[-1];
        fn = elt(env, 18); // apply
        return (*qfn2(fn))(fn, v_21155, v_21150);
    }
v_20938:
    goto v_20972;
v_20968:
    v_21151 = stack[-1];
    goto v_20969;
v_20970:
    v_21150 = elt(env, 5); // true
    goto v_20971;
v_20972:
    goto v_20968;
v_20969:
    goto v_20970;
v_20971:
    if (v_21151 == v_21150) goto v_20966;
    else goto v_20967;
v_20966:
    v_21150 = lisp_true;
    goto v_20965;
v_20967:
    goto v_20982;
v_20978:
    v_21151 = stack[-1];
    goto v_20979;
v_20980:
    v_21150 = elt(env, 6); // false
    goto v_20981;
v_20982:
    goto v_20978;
v_20979:
    goto v_20980;
v_20981:
    v_21150 = (v_21151 == v_21150 ? lisp_true : nil);
    goto v_20965;
    v_21150 = nil;
v_20965:
    if (v_21150 == nil) goto v_20963;
    v_21150 = lisp_true;
    goto v_20961;
v_20963:
    goto v_21009;
v_21005:
    v_21151 = stack[-1];
    goto v_21006;
v_21007:
    v_21150 = elt(env, 3); // or
    goto v_21008;
v_21009:
    goto v_21005;
v_21006:
    goto v_21007;
v_21008:
    if (v_21151 == v_21150) goto v_21003;
    else goto v_21004;
v_21003:
    v_21150 = lisp_true;
    goto v_21002;
v_21004:
    goto v_21019;
v_21015:
    v_21151 = stack[-1];
    goto v_21016;
v_21017:
    v_21150 = elt(env, 4); // and
    goto v_21018;
v_21019:
    goto v_21015;
v_21016:
    goto v_21017;
v_21018:
    v_21150 = (v_21151 == v_21150 ? lisp_true : nil);
    goto v_21002;
    v_21150 = nil;
v_21002:
    if (v_21150 == nil) goto v_21000;
    v_21150 = lisp_true;
    goto v_20998;
v_21000:
    goto v_21030;
v_21026:
    v_21151 = stack[-1];
    goto v_21027;
v_21028:
    v_21150 = elt(env, 7); // not
    goto v_21029;
v_21030:
    goto v_21026;
v_21027:
    goto v_21028;
v_21029:
    v_21150 = (v_21151 == v_21150 ? lisp_true : nil);
    goto v_20998;
    v_21150 = nil;
v_20998:
    if (v_21150 == nil) goto v_20996;
    v_21150 = lisp_true;
    goto v_20994;
v_20996:
    goto v_21045;
v_21041:
    v_21151 = stack[-1];
    goto v_21042;
v_21043:
    v_21150 = elt(env, 8); // impl
    goto v_21044;
v_21045:
    goto v_21041;
v_21042:
    goto v_21043;
v_21044:
    if (v_21151 == v_21150) goto v_21039;
    else goto v_21040;
v_21039:
    v_21150 = lisp_true;
    goto v_21038;
v_21040:
    goto v_21059;
v_21055:
    v_21151 = stack[-1];
    goto v_21056;
v_21057:
    v_21150 = elt(env, 9); // repl
    goto v_21058;
v_21059:
    goto v_21055;
v_21056:
    goto v_21057;
v_21058:
    if (v_21151 == v_21150) goto v_21053;
    else goto v_21054;
v_21053:
    v_21150 = lisp_true;
    goto v_21052;
v_21054:
    goto v_21069;
v_21065:
    v_21151 = stack[-1];
    goto v_21066;
v_21067:
    v_21150 = elt(env, 10); // equiv
    goto v_21068;
v_21069:
    goto v_21065;
v_21066:
    goto v_21067;
v_21068:
    v_21150 = (v_21151 == v_21150 ? lisp_true : nil);
    goto v_21052;
    v_21150 = nil;
v_21052:
    goto v_21038;
    v_21150 = nil;
v_21038:
    goto v_20994;
    v_21150 = nil;
v_20994:
    if (v_21150 == nil) goto v_20992;
    v_21150 = lisp_true;
    goto v_20990;
v_20992:
    goto v_21088;
v_21084:
    v_21151 = stack[-1];
    goto v_21085;
v_21086:
    v_21150 = elt(env, 1); // ex
    goto v_21087;
v_21088:
    goto v_21084;
v_21085:
    goto v_21086;
v_21087:
    if (v_21151 == v_21150) goto v_21082;
    else goto v_21083;
v_21082:
    v_21150 = lisp_true;
    goto v_21081;
v_21083:
    goto v_21098;
v_21094:
    v_21151 = stack[-1];
    goto v_21095;
v_21096:
    v_21150 = elt(env, 2); // all
    goto v_21097;
v_21098:
    goto v_21094;
v_21095:
    goto v_21096;
v_21097:
    v_21150 = (v_21151 == v_21150 ? lisp_true : nil);
    goto v_21081;
    v_21150 = nil;
v_21081:
    if (v_21150 == nil) goto v_21079;
    v_21150 = lisp_true;
    goto v_21077;
v_21079:
    goto v_21117;
v_21113:
    v_21151 = stack[-1];
    goto v_21114;
v_21115:
    v_21150 = elt(env, 11); // bex
    goto v_21116;
v_21117:
    goto v_21113;
v_21114:
    goto v_21115;
v_21116:
    if (v_21151 == v_21150) goto v_21111;
    else goto v_21112;
v_21111:
    v_21150 = lisp_true;
    goto v_21110;
v_21112:
    goto v_21127;
v_21123:
    v_21151 = stack[-1];
    goto v_21124;
v_21125:
    v_21150 = elt(env, 12); // ball
    goto v_21126;
v_21127:
    goto v_21123;
v_21124:
    goto v_21125;
v_21126:
    v_21150 = (v_21151 == v_21150 ? lisp_true : nil);
    goto v_21110;
    v_21150 = nil;
v_21110:
    if (v_21150 == nil) goto v_21108;
    v_21150 = lisp_true;
    goto v_21106;
v_21108:
    v_21150 = stack[-1];
    if (!symbolp(v_21150)) v_21150 = nil;
    else { v_21150 = qfastgets(v_21150);
           if (v_21150 != nil) { v_21150 = elt(v_21150, 21); // rl_external
#ifdef RECORD_GET
             if (v_21150 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_21150 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_21150 == SPID_NOPROP) v_21150 = nil; }}
#endif
    goto v_21106;
    v_21150 = nil;
v_21106:
    goto v_21077;
    v_21150 = nil;
v_21077:
    goto v_20990;
    v_21150 = nil;
v_20990:
    goto v_20961;
    v_21150 = nil;
v_20961:
    if (v_21150 == nil) goto v_20959;
    goto v_21144;
v_21138:
    v_21152 = elt(env, 13); // "cl_pnf2():"
    goto v_21139;
v_21140:
    v_21151 = stack[-1];
    goto v_21141;
v_21142:
    v_21150 = elt(env, 14); // "invalid as operator"
    goto v_21143;
v_21144:
    goto v_21138;
v_21139:
    goto v_21140;
v_21141:
    goto v_21142;
v_21143:
    v_21150 = list3(v_21152, v_21151, v_21150);
    env = stack[-2];
    fn = elt(env, 19); // rederr
    v_21150 = (*qfn1(fn))(fn, v_21150);
    goto v_20957;
v_20959:
v_20957:
    v_21150 = stack[0];
    return ncons(v_21150);
    return onevalue(v_21150);
}



// Code for vdp_setsugar

static LispObject CC_vdp_setsugar(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20857, v_20858, v_20859;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20857 = v_20836;
    v_20859 = v_20835;
// end of prologue
    v_20858 = qvalue(elt(env, 1)); // !*cgbsugar
    if (v_20858 == nil) goto v_20840;
    else goto v_20841;
v_20840:
    v_20857 = v_20859;
    goto v_20839;
v_20841:
    goto v_20853;
v_20847:
    goto v_20848;
v_20849:
    v_20858 = elt(env, 2); // sugar
    goto v_20850;
v_20851:
    goto v_20852;
v_20853:
    goto v_20847;
v_20848:
    goto v_20849;
v_20850:
    goto v_20851;
v_20852:
    {
        fn = elt(env, 3); // vdp_putprop
        return (*qfnn(fn))(fn, 3, v_20859, v_20858, v_20857);
    }
    v_20857 = nil;
v_20839:
    return onevalue(v_20857);
}



// Code for setrd

static LispObject CC_setrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20860, v_20861;
    LispObject fn;
    argcheck(nargs, 0, "setrd");
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
    goto v_20845;
v_20841:
    v_20861 = qvalue(elt(env, 1)); // atts
    goto v_20842;
v_20843:
    v_20860 = elt(env, 2); // (type)
    goto v_20844;
v_20845:
    goto v_20841;
v_20842:
    goto v_20843;
v_20844:
    fn = elt(env, 4); // retattributes
    v_20860 = (*qfn2(fn))(fn, v_20861, v_20860);
    env = stack[-2];
    goto v_20855;
v_20849:
    stack[-1] = elt(env, 3); // set
    goto v_20850;
v_20851:
    stack[0] = v_20860;
    goto v_20852;
v_20853:
    fn = elt(env, 5); // stats_getargs
    v_20860 = (*qfnn(fn))(fn, 0);
    goto v_20854;
v_20855:
    goto v_20849;
v_20850:
    goto v_20851;
v_20852:
    goto v_20853;
v_20854:
    {
        LispObject v_20864 = stack[-1];
        LispObject v_20865 = stack[0];
        return list2star(v_20864, v_20865, v_20860);
    }
    return onevalue(v_20860);
}



// Code for collectphysops_reversed

static LispObject CC_collectphysops_reversed(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20903, v_20904;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20836;
    stack[-1] = v_20835;
// end of prologue
    v_20903 = stack[-1];
    if (!consp(v_20903)) goto v_20842;
    else goto v_20843;
v_20842:
    v_20903 = stack[-1];
    fn = elt(env, 1); // physopp
    v_20903 = (*qfn1(fn))(fn, v_20903);
    if (v_20903 == nil) goto v_20848;
    goto v_20856;
v_20852:
    v_20904 = stack[-1];
    goto v_20853;
v_20854:
    v_20903 = stack[0];
    goto v_20855;
v_20856:
    goto v_20852;
v_20853:
    goto v_20854;
v_20855:
    return cons(v_20904, v_20903);
v_20848:
    v_20903 = stack[0];
    goto v_20839;
    goto v_20841;
v_20843:
    v_20903 = stack[-1];
    fn = elt(env, 1); // physopp
    v_20903 = (*qfn1(fn))(fn, v_20903);
    env = stack[-3];
    if (v_20903 == nil) goto v_20863;
    goto v_20871;
v_20867:
    goto v_20877;
v_20873:
    stack[-2] = stack[-1];
    goto v_20874;
v_20875:
    v_20903 = stack[-1];
    fn = elt(env, 2); // collectindices
    v_20903 = (*qfn1(fn))(fn, v_20903);
    env = stack[-3];
    goto v_20876;
v_20877:
    goto v_20873;
v_20874:
    goto v_20875;
v_20876:
    fn = elt(env, 3); // removeindices
    v_20904 = (*qfn2(fn))(fn, stack[-2], v_20903);
    goto v_20868;
v_20869:
    v_20903 = stack[0];
    goto v_20870;
v_20871:
    goto v_20867;
v_20868:
    goto v_20869;
v_20870:
    return cons(v_20904, v_20903);
v_20863:
v_20841:
v_20884:
    v_20903 = stack[-1];
    if (!consp(v_20903)) goto v_20887;
    else goto v_20888;
v_20887:
    goto v_20883;
v_20888:
    goto v_20896;
v_20892:
    v_20903 = stack[-1];
    v_20904 = qcar(v_20903);
    goto v_20893;
v_20894:
    v_20903 = stack[0];
    goto v_20895;
v_20896:
    goto v_20892;
v_20893:
    goto v_20894;
v_20895:
    v_20903 = CC_collectphysops_reversed(elt(env, 0), v_20904, v_20903);
    env = stack[-3];
    stack[0] = v_20903;
    v_20903 = stack[-1];
    v_20903 = qcdr(v_20903);
    stack[-1] = v_20903;
    goto v_20884;
v_20883:
    v_20903 = stack[0];
v_20839:
    return onevalue(v_20903);
}



// Code for evalgreaterp

static LispObject CC_evalgreaterp(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20912, v_20913, v_20914;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_20913 = v_20836;
    v_20912 = v_20835;
// end of prologue
    goto v_20846;
v_20840:
    v_20914 = elt(env, 1); // difference
    goto v_20841;
v_20842:
    goto v_20843;
v_20844:
    goto v_20845;
v_20846:
    goto v_20840;
v_20841:
    goto v_20842;
v_20843:
    goto v_20844;
v_20845:
    v_20912 = list3(v_20914, v_20913, v_20912);
    env = stack[-1];
    fn = elt(env, 3); // simp!*
    v_20912 = (*qfn1(fn))(fn, v_20912);
    env = stack[-1];
    stack[0] = v_20912;
    v_20912 = stack[0];
    v_20912 = qcdr(v_20912);
    if (!consp(v_20912)) goto v_20858;
    v_20912 = lisp_true;
    goto v_20856;
v_20858:
    v_20912 = stack[0];
    v_20912 = qcar(v_20912);
    if (!consp(v_20912)) goto v_20866;
    else goto v_20867;
v_20866:
    v_20912 = lisp_true;
    goto v_20865;
v_20867:
    v_20912 = stack[0];
    v_20912 = qcar(v_20912);
    v_20912 = qcar(v_20912);
    v_20912 = (consp(v_20912) ? nil : lisp_true);
    goto v_20865;
    v_20912 = nil;
v_20865:
    v_20912 = (v_20912 == nil ? lisp_true : nil);
    goto v_20856;
    v_20912 = nil;
v_20856:
    if (v_20912 == nil) goto v_20854;
    goto v_20883;
v_20879:
    v_20912 = stack[0];
    v_20912 = qcar(v_20912);
    fn = elt(env, 4); // minusf
    v_20912 = (*qfn1(fn))(fn, v_20912);
    env = stack[-1];
    if (v_20912 == nil) goto v_20888;
    v_20912 = stack[0];
    fn = elt(env, 5); // negsq
    v_20912 = (*qfn1(fn))(fn, v_20912);
    env = stack[-1];
    goto v_20886;
v_20888:
    v_20912 = stack[0];
    goto v_20886;
    v_20912 = nil;
v_20886:
    fn = elt(env, 6); // mk!*sq
    v_20913 = (*qfn1(fn))(fn, v_20912);
    env = stack[-1];
    goto v_20880;
v_20881:
    v_20912 = elt(env, 2); // "number"
    goto v_20882;
v_20883:
    goto v_20879;
v_20880:
    goto v_20881;
v_20882:
    {
        fn = elt(env, 7); // typerr
        return (*qfn2(fn))(fn, v_20913, v_20912);
    }
v_20854:
    v_20912 = stack[0];
    v_20912 = qcar(v_20912);
    if (v_20912 == nil) goto v_20902;
    else goto v_20903;
v_20902:
    v_20912 = nil;
    goto v_20901;
v_20903:
    v_20912 = stack[0];
    v_20912 = qcar(v_20912);
    {
        fn = elt(env, 8); // !:minusp
        return (*qfn1(fn))(fn, v_20912);
    }
    v_20912 = nil;
v_20901:
    goto v_20852;
    v_20912 = nil;
v_20852:
    return onevalue(v_20912);
}



// Code for subcare

static LispObject CC_subcare(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20917, v_20918, v_20919;
    LispObject fn;
    LispObject v_20837, v_20836, v_20835;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "subcare");
    va_start(aa, nargs);
    v_20835 = va_arg(aa, LispObject);
    v_20836 = va_arg(aa, LispObject);
    v_20837 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20837,v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20835,v_20836,v_20837);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_20837;
    stack[-1] = v_20836;
    stack[-2] = v_20835;
// end of prologue
    stack[-3] = nil;
v_20842:
    v_20917 = stack[0];
    if (v_20917 == nil) goto v_20845;
    else goto v_20846;
v_20845:
    v_20917 = stack[-3];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_20917);
    }
v_20846:
    goto v_20856;
v_20852:
    v_20918 = stack[-2];
    goto v_20853;
v_20854:
    v_20917 = stack[0];
    goto v_20855;
v_20856:
    goto v_20852;
v_20853:
    goto v_20854;
v_20855:
    if (equal(v_20918, v_20917)) goto v_20850;
    else goto v_20851;
v_20850:
    goto v_20864;
v_20860:
    v_20918 = stack[-3];
    goto v_20861;
v_20862:
    v_20917 = stack[-1];
    goto v_20863;
v_20864:
    goto v_20860;
v_20861:
    goto v_20862;
v_20863:
    {
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_20918, v_20917);
    }
v_20851:
    v_20917 = stack[0];
    if (!consp(v_20917)) goto v_20871;
    else goto v_20872;
v_20871:
    v_20917 = lisp_true;
    goto v_20870;
v_20872:
    goto v_20882;
v_20878:
    v_20917 = stack[0];
    v_20918 = qcar(v_20917);
    goto v_20879;
v_20880:
    v_20917 = elt(env, 1); // subfunc
    goto v_20881;
v_20882:
    goto v_20878;
v_20879:
    goto v_20880;
v_20881:
    v_20917 = get(v_20918, v_20917);
    env = stack[-4];
    goto v_20870;
    v_20917 = nil;
v_20870:
    if (v_20917 == nil) goto v_20868;
    goto v_20891;
v_20887:
    v_20918 = stack[-3];
    goto v_20888;
v_20889:
    v_20917 = stack[0];
    goto v_20890;
v_20891:
    goto v_20887;
v_20888:
    goto v_20889;
v_20890:
    {
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_20918, v_20917);
    }
v_20868:
    goto v_20901;
v_20897:
    goto v_20909;
v_20903:
    v_20919 = stack[-2];
    goto v_20904;
v_20905:
    v_20918 = stack[-1];
    goto v_20906;
v_20907:
    v_20917 = stack[0];
    v_20917 = qcar(v_20917);
    goto v_20908;
v_20909:
    goto v_20903;
v_20904:
    goto v_20905;
v_20906:
    goto v_20907;
v_20908:
    v_20918 = CC_subcare(elt(env, 0), 3, v_20919, v_20918, v_20917);
    env = stack[-4];
    goto v_20898;
v_20899:
    v_20917 = stack[-3];
    goto v_20900;
v_20901:
    goto v_20897;
v_20898:
    goto v_20899;
v_20900:
    v_20917 = cons(v_20918, v_20917);
    env = stack[-4];
    stack[-3] = v_20917;
    v_20917 = stack[0];
    v_20917 = qcdr(v_20917);
    stack[0] = v_20917;
    goto v_20842;
    v_20917 = nil;
    return onevalue(v_20917);
}



// Code for fs!:make!-nullangle

static LispObject CC_fsTmakeKnullangle(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20873, v_20874, v_20875;
    argcheck(nargs, 0, "fs:make-nullangle");
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
    v_20873 = (LispObject)112+TAG_FIXNUM; // 7
    v_20873 = Lmkvect(nil, v_20873);
    env = stack[-2];
    stack[-1] = v_20873;
    v_20873 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_20873;
v_20844:
    goto v_20856;
v_20852:
    v_20874 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_20853;
v_20854:
    v_20873 = stack[0];
    goto v_20855;
v_20856:
    goto v_20852;
v_20853:
    goto v_20854;
v_20855:
    v_20873 = difference2(v_20874, v_20873);
    env = stack[-2];
    v_20873 = Lminusp(nil, v_20873);
    env = stack[-2];
    if (v_20873 == nil) goto v_20849;
    goto v_20843;
v_20849:
    goto v_20866;
v_20860:
    v_20875 = stack[-1];
    goto v_20861;
v_20862:
    v_20874 = stack[0];
    goto v_20863;
v_20864:
    v_20873 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20865;
v_20866:
    goto v_20860;
v_20861:
    goto v_20862;
v_20863:
    goto v_20864;
v_20865:
    *(LispObject *)((char *)v_20875 + (CELL-TAG_VECTOR) + (((intptr_t)v_20874-TAG_FIXNUM)/(16/CELL))) = v_20873;
    v_20873 = stack[0];
    v_20873 = add1(v_20873);
    env = stack[-2];
    stack[0] = v_20873;
    goto v_20844;
v_20843:
    v_20873 = stack[-1];
    return onevalue(v_20873);
}



// Code for ratlessp

static LispObject CC_ratlessp(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20854, v_20855;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
// copy arguments values to proper place
    v_20854 = v_20836;
    v_20855 = v_20835;
// end of prologue
    goto v_20843;
v_20839:
    goto v_20849;
v_20845:
    goto v_20846;
v_20847:
    goto v_20848;
v_20849:
    goto v_20845;
v_20846:
    goto v_20847;
v_20848:
    fn = elt(env, 1); // ratdif
    v_20854 = (*qfn2(fn))(fn, v_20855, v_20854);
    v_20855 = qcar(v_20854);
    goto v_20840;
v_20841:
    v_20854 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20842;
v_20843:
    goto v_20839;
v_20840:
    goto v_20841;
v_20842:
        return Llessp(nil, v_20855, v_20854);
}



// Code for giplus!:

static LispObject CC_giplusT(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20868, v_20869;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20836;
    stack[-1] = v_20835;
// end of prologue
    goto v_20843;
v_20839:
    goto v_20849;
v_20845:
    v_20868 = stack[-1];
    v_20868 = qcdr(v_20868);
    v_20869 = qcar(v_20868);
    goto v_20846;
v_20847:
    v_20868 = stack[0];
    v_20868 = qcdr(v_20868);
    v_20868 = qcar(v_20868);
    goto v_20848;
v_20849:
    goto v_20845;
v_20846:
    goto v_20847;
v_20848:
    stack[-2] = plus2(v_20869, v_20868);
    env = stack[-3];
    goto v_20840;
v_20841:
    goto v_20861;
v_20857:
    v_20868 = stack[-1];
    v_20868 = qcdr(v_20868);
    v_20869 = qcdr(v_20868);
    goto v_20858;
v_20859:
    v_20868 = stack[0];
    v_20868 = qcdr(v_20868);
    v_20868 = qcdr(v_20868);
    goto v_20860;
v_20861:
    goto v_20857;
v_20858:
    goto v_20859;
v_20860:
    v_20868 = plus2(v_20869, v_20868);
    env = stack[-3];
    goto v_20842;
v_20843:
    goto v_20839;
v_20840:
    goto v_20841;
v_20842:
    {
        LispObject v_20873 = stack[-2];
        fn = elt(env, 1); // mkgi
        return (*qfn2(fn))(fn, v_20873, v_20868);
    }
}



// Code for multivariatep

static LispObject CC_multivariatep(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20887, v_20888;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_20836;
    stack[-1] = v_20835;
// end of prologue
v_20840:
    v_20887 = stack[-1];
    if (!consp(v_20887)) goto v_20847;
    else goto v_20848;
v_20847:
    v_20887 = lisp_true;
    goto v_20846;
v_20848:
    v_20887 = stack[-1];
    v_20887 = qcar(v_20887);
    v_20887 = (consp(v_20887) ? nil : lisp_true);
    goto v_20846;
    v_20887 = nil;
v_20846:
    if (v_20887 == nil) goto v_20844;
    v_20887 = nil;
    goto v_20839;
v_20844:
    goto v_20863;
v_20859:
    v_20887 = stack[-1];
    v_20887 = qcar(v_20887);
    v_20887 = qcar(v_20887);
    v_20888 = qcar(v_20887);
    goto v_20860;
v_20861:
    v_20887 = stack[0];
    goto v_20862;
v_20863:
    goto v_20859;
v_20860:
    goto v_20861;
v_20862:
    if (v_20888 == v_20887) goto v_20858;
    v_20887 = lisp_true;
    goto v_20839;
v_20858:
    goto v_20877;
v_20873:
    v_20887 = stack[-1];
    v_20887 = qcar(v_20887);
    v_20888 = qcdr(v_20887);
    goto v_20874;
v_20875:
    v_20887 = stack[0];
    goto v_20876;
v_20877:
    goto v_20873;
v_20874:
    goto v_20875;
v_20876:
    v_20887 = CC_multivariatep(elt(env, 0), v_20888, v_20887);
    env = stack[-2];
    if (v_20887 == nil) goto v_20871;
    v_20887 = lisp_true;
    goto v_20839;
v_20871:
    v_20887 = stack[-1];
    v_20887 = qcdr(v_20887);
    stack[-1] = v_20887;
    goto v_20840;
    v_20887 = nil;
v_20839:
    return onevalue(v_20887);
}



// Code for rl_qefsolset

static LispObject CC_rl_qefsolset(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20869, v_20870, v_20871, v_20872, v_20873;
    LispObject fn;
    LispObject v_20839, v_20838, v_20837, v_20836, v_20835;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "rl_qefsolset");
    va_start(aa, nargs);
    v_20835 = va_arg(aa, LispObject);
    v_20836 = va_arg(aa, LispObject);
    v_20837 = va_arg(aa, LispObject);
    v_20838 = va_arg(aa, LispObject);
    v_20839 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_20839,v_20838,v_20837,v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_20835,v_20836,v_20837,v_20838,v_20839);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_20869 = v_20839;
    v_20870 = v_20838;
    v_20871 = v_20837;
    v_20872 = v_20836;
    v_20873 = v_20835;
// end of prologue
    goto v_20846;
v_20842:
    stack[-3] = qvalue(elt(env, 1)); // rl_qefsolset!*
    goto v_20843;
v_20844:
    goto v_20857;
v_20849:
    stack[-2] = v_20873;
    goto v_20850;
v_20851:
    stack[-1] = v_20872;
    goto v_20852;
v_20853:
    stack[0] = v_20871;
    goto v_20854;
v_20855:
    goto v_20866;
v_20862:
    goto v_20863;
v_20864:
    goto v_20865;
v_20866:
    goto v_20862;
v_20863:
    goto v_20864;
v_20865:
    v_20869 = list2(v_20870, v_20869);
    env = stack[-4];
    goto v_20856;
v_20857:
    goto v_20849;
v_20850:
    goto v_20851;
v_20852:
    goto v_20853;
v_20854:
    goto v_20855;
v_20856:
    v_20869 = list3star(stack[-2], stack[-1], stack[0], v_20869);
    env = stack[-4];
    goto v_20845;
v_20846:
    goto v_20842;
v_20843:
    goto v_20844;
v_20845:
    {
        LispObject v_20878 = stack[-3];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_20878, v_20869);
    }
}



// Code for sfto_b!:extadd

static LispObject CC_sfto_bTextadd(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20969, v_20970, v_20971;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_20836;
    stack[-2] = v_20835;
// end of prologue
    stack[0] = nil;
v_20841:
    v_20969 = stack[-2];
    if (v_20969 == nil) goto v_20844;
    else goto v_20845;
v_20844:
    goto v_20852;
v_20848:
    v_20970 = stack[0];
    goto v_20849;
v_20850:
    v_20969 = stack[-1];
    goto v_20851;
v_20852:
    goto v_20848;
v_20849:
    goto v_20850;
v_20851:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_20970, v_20969);
    }
v_20845:
    v_20969 = stack[-1];
    if (v_20969 == nil) goto v_20855;
    else goto v_20856;
v_20855:
    goto v_20863;
v_20859:
    v_20970 = stack[0];
    goto v_20860;
v_20861:
    v_20969 = stack[-2];
    goto v_20862;
v_20863:
    goto v_20859;
v_20860:
    goto v_20861;
v_20862:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_20970, v_20969);
    }
v_20856:
    goto v_20872;
v_20868:
    v_20969 = stack[-2];
    v_20969 = qcar(v_20969);
    v_20970 = qcar(v_20969);
    goto v_20869;
v_20870:
    v_20969 = stack[-1];
    v_20969 = qcar(v_20969);
    v_20969 = qcar(v_20969);
    goto v_20871;
v_20872:
    goto v_20868;
v_20869:
    goto v_20870;
v_20871:
    if (equal(v_20970, v_20969)) goto v_20866;
    else goto v_20867;
v_20866:
    goto v_20884;
v_20880:
    stack[-3] = stack[0];
    goto v_20881;
v_20882:
    goto v_20891;
v_20887:
    v_20969 = stack[-2];
    v_20969 = qcar(v_20969);
    v_20970 = qcdr(v_20969);
    goto v_20888;
v_20889:
    v_20969 = stack[-1];
    v_20969 = qcar(v_20969);
    v_20969 = qcdr(v_20969);
    goto v_20890;
v_20891:
    goto v_20887;
v_20888:
    goto v_20889;
v_20890:
    fn = elt(env, 2); // addf
    stack[0] = (*qfn2(fn))(fn, v_20970, v_20969);
    env = stack[-4];
    goto v_20903;
v_20899:
    v_20969 = stack[-2];
    v_20970 = qcdr(v_20969);
    goto v_20900;
v_20901:
    v_20969 = stack[-1];
    v_20969 = qcdr(v_20969);
    goto v_20902;
v_20903:
    goto v_20899;
v_20900:
    goto v_20901;
v_20902:
    v_20969 = CC_sfto_bTextadd(elt(env, 0), v_20970, v_20969);
    env = stack[-4];
    v_20970 = stack[0];
    v_20971 = v_20970;
    if (v_20971 == nil) goto v_20912;
    else goto v_20913;
v_20912:
    goto v_20911;
v_20913:
    goto v_20925;
v_20919:
    v_20971 = stack[-2];
    v_20971 = qcar(v_20971);
    v_20971 = qcar(v_20971);
    goto v_20920;
v_20921:
    goto v_20922;
v_20923:
    goto v_20924;
v_20925:
    goto v_20919;
v_20920:
    goto v_20921;
v_20922:
    goto v_20923;
v_20924:
    v_20969 = acons(v_20971, v_20970, v_20969);
    env = stack[-4];
    goto v_20911;
    v_20969 = nil;
v_20911:
    goto v_20883;
v_20884:
    goto v_20880;
v_20881:
    goto v_20882;
v_20883:
    {
        LispObject v_20976 = stack[-3];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_20976, v_20969);
    }
v_20867:
    goto v_20938;
v_20934:
    v_20969 = stack[-2];
    v_20969 = qcar(v_20969);
    v_20970 = qcar(v_20969);
    goto v_20935;
v_20936:
    v_20969 = stack[-1];
    v_20969 = qcar(v_20969);
    v_20969 = qcar(v_20969);
    goto v_20937;
v_20938:
    goto v_20934;
v_20935:
    goto v_20936;
v_20937:
    fn = elt(env, 3); // sfto_b!:ordexp
    v_20969 = (*qfn2(fn))(fn, v_20970, v_20969);
    env = stack[-4];
    if (v_20969 == nil) goto v_20932;
    goto v_20950;
v_20946:
    v_20969 = stack[-2];
    v_20970 = qcar(v_20969);
    goto v_20947;
v_20948:
    v_20969 = stack[0];
    goto v_20949;
v_20950:
    goto v_20946;
v_20947:
    goto v_20948;
v_20949:
    v_20969 = cons(v_20970, v_20969);
    env = stack[-4];
    stack[0] = v_20969;
    v_20969 = stack[-2];
    v_20969 = qcdr(v_20969);
    stack[-2] = v_20969;
    goto v_20841;
v_20932:
    goto v_20963;
v_20959:
    v_20969 = stack[-1];
    v_20970 = qcar(v_20969);
    goto v_20960;
v_20961:
    v_20969 = stack[0];
    goto v_20962;
v_20963:
    goto v_20959;
v_20960:
    goto v_20961;
v_20962:
    v_20969 = cons(v_20970, v_20969);
    env = stack[-4];
    stack[0] = v_20969;
    v_20969 = stack[-1];
    v_20969 = qcdr(v_20969);
    stack[-1] = v_20969;
    goto v_20841;
    v_20969 = nil;
    return onevalue(v_20969);
}



// Code for bvarom

static LispObject CC_bvarom(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20867, v_20868;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_20835;
// end of prologue
    v_20867 = stack[0];
    v_20867 = qcar(v_20867);
    v_20867 = Lconsp(nil, v_20867);
    env = stack[-1];
    if (v_20867 == nil) goto v_20842;
    goto v_20854;
v_20850:
    v_20867 = stack[0];
    v_20867 = qcar(v_20867);
    v_20868 = qcar(v_20867);
    goto v_20851;
v_20852:
    v_20867 = elt(env, 1); // bvar
    goto v_20853;
v_20854:
    goto v_20850;
v_20851:
    goto v_20852;
v_20853:
    if (v_20868 == v_20867) goto v_20848;
    else goto v_20849;
v_20848:
    v_20867 = stack[0];
    v_20867 = qcar(v_20867);
    v_20867 = qcdr(v_20867);
    v_20867 = qcar(v_20867);
    fn = elt(env, 2); // objectom
    v_20867 = (*qfn1(fn))(fn, v_20867);
    env = stack[-1];
    v_20867 = stack[0];
    v_20867 = qcdr(v_20867);
    v_20867 = CC_bvarom(elt(env, 0), v_20867);
    goto v_20847;
v_20849:
v_20847:
    goto v_20840;
v_20842:
v_20840:
    v_20867 = nil;
    return onevalue(v_20867);
}



// Code for degreef

static LispObject CC_degreef(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20897, v_20898;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20836;
    stack[-1] = v_20835;
// end of prologue
    v_20897 = stack[-1];
    if (!consp(v_20897)) goto v_20844;
    else goto v_20845;
v_20844:
    v_20897 = lisp_true;
    goto v_20843;
v_20845:
    v_20897 = stack[-1];
    v_20897 = qcar(v_20897);
    v_20897 = (consp(v_20897) ? nil : lisp_true);
    goto v_20843;
    v_20897 = nil;
v_20843:
    if (v_20897 == nil) goto v_20841;
    v_20897 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20839;
v_20841:
    goto v_20860;
v_20856:
    v_20897 = stack[-1];
    v_20897 = qcar(v_20897);
    v_20897 = qcar(v_20897);
    v_20898 = qcar(v_20897);
    goto v_20857;
v_20858:
    v_20897 = stack[0];
    goto v_20859;
v_20860:
    goto v_20856;
v_20857:
    goto v_20858;
v_20859:
    if (v_20898 == v_20897) goto v_20854;
    else goto v_20855;
v_20854:
    v_20897 = stack[-1];
    v_20897 = qcar(v_20897);
    v_20897 = qcar(v_20897);
    v_20897 = qcdr(v_20897);
    goto v_20839;
v_20855:
    goto v_20877;
v_20873:
    goto v_20883;
v_20879:
    v_20897 = stack[-1];
    v_20897 = qcar(v_20897);
    v_20898 = qcdr(v_20897);
    goto v_20880;
v_20881:
    v_20897 = stack[0];
    goto v_20882;
v_20883:
    goto v_20879;
v_20880:
    goto v_20881;
v_20882:
    stack[-2] = CC_degreef(elt(env, 0), v_20898, v_20897);
    env = stack[-3];
    goto v_20874;
v_20875:
    goto v_20893;
v_20889:
    v_20897 = stack[-1];
    v_20898 = qcdr(v_20897);
    goto v_20890;
v_20891:
    v_20897 = stack[0];
    goto v_20892;
v_20893:
    goto v_20889;
v_20890:
    goto v_20891;
v_20892:
    v_20897 = CC_degreef(elt(env, 0), v_20898, v_20897);
    env = stack[-3];
    goto v_20876;
v_20877:
    goto v_20873;
v_20874:
    goto v_20875;
v_20876:
    {
        LispObject v_20902 = stack[-2];
        fn = elt(env, 1); // max
        return (*qfn2(fn))(fn, v_20902, v_20897);
    }
    v_20897 = nil;
v_20839:
    return onevalue(v_20897);
}



// Code for r2findindex1

static LispObject CC_r2findindex1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20866, v_20867, v_20868;
    LispObject fn;
    LispObject v_20837, v_20836, v_20835;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "r2findindex1");
    va_start(aa, nargs);
    v_20835 = va_arg(aa, LispObject);
    v_20836 = va_arg(aa, LispObject);
    v_20837 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20837,v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20835,v_20836,v_20837);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_20867 = v_20837;
    stack[0] = v_20836;
    stack[-1] = v_20835;
// end of prologue
v_20841:
    v_20866 = stack[0];
    if (v_20866 == nil) goto v_20844;
    else goto v_20845;
v_20844:
    v_20866 = elt(env, 1); // "index not found"
    {
        fn = elt(env, 2); // rederr
        return (*qfn1(fn))(fn, v_20866);
    }
v_20845:
    goto v_20855;
v_20851:
    v_20868 = stack[-1];
    goto v_20852;
v_20853:
    v_20866 = stack[0];
    v_20866 = qcar(v_20866);
    goto v_20854;
v_20855:
    goto v_20851;
v_20852:
    goto v_20853;
v_20854:
    if (equal(v_20868, v_20866)) goto v_20849;
    else goto v_20850;
v_20849:
    v_20866 = v_20867;
    goto v_20840;
v_20850:
    v_20866 = stack[0];
    v_20866 = qcdr(v_20866);
    stack[0] = v_20866;
    v_20866 = v_20867;
    v_20866 = add1(v_20866);
    env = stack[-2];
    v_20867 = v_20866;
    goto v_20841;
    v_20866 = nil;
v_20840:
    return onevalue(v_20866);
}



// Code for apply_e

static LispObject CC_apply_e(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20855, v_20856;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20855 = v_20835;
// end of prologue
    goto v_20846;
v_20842:
    v_20856 = v_20855;
    goto v_20843;
v_20844:
    v_20855 = nil;
    goto v_20845;
v_20846:
    goto v_20842;
v_20843:
    goto v_20844;
v_20845:
    fn = elt(env, 2); // apply
    v_20856 = (*qfn2(fn))(fn, v_20856, v_20855);
    env = stack[0];
    v_20855 = v_20856;
    v_20856 = integerp(v_20856);
    if (v_20856 == nil) goto v_20840;
    goto v_20838;
v_20840:
    v_20855 = elt(env, 1); // "randpoly expons function must return an integer"
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_20855);
    }
    v_20855 = nil;
v_20838:
    return onevalue(v_20855);
}



// Code for sqprint

static LispObject CC_sqprint(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20975, v_20976, v_20977;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_20835;
// end of prologue
// Binding !*prin!#
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-3, 1, 0);
    qvalue(elt(env, 1)) = nil; // !*prin!#
    v_20975 = lisp_true;
    qvalue(elt(env, 1)) = v_20975; // !*prin!#
    v_20975 = qvalue(elt(env, 2)); // orig!*
    stack[-2] = v_20975;
    v_20975 = qvalue(elt(env, 3)); // !*nat
    if (v_20975 == nil) goto v_20847;
    goto v_20856;
v_20852:
    v_20976 = qvalue(elt(env, 4)); // posn!*
    goto v_20853;
v_20854:
    v_20975 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_20855;
v_20856:
    goto v_20852;
v_20853:
    goto v_20854;
v_20855:
    v_20975 = (LispObject)lessp2(v_20976, v_20975);
    v_20975 = v_20975 ? lisp_true : nil;
    env = stack[-3];
    if (v_20975 == nil) goto v_20847;
    v_20975 = qvalue(elt(env, 4)); // posn!*
    qvalue(elt(env, 2)) = v_20975; // orig!*
    goto v_20845;
v_20847:
v_20845:
    v_20975 = qvalue(elt(env, 5)); // !*pri
    if (v_20975 == nil) goto v_20864;
    else goto v_20862;
v_20864:
    v_20975 = qvalue(elt(env, 6)); // wtl!*
    if (v_20975 == nil) goto v_20866;
    else goto v_20862;
v_20866:
    goto v_20863;
v_20862:
    v_20975 = stack[-1];
    fn = elt(env, 8); // sqhorner!*
    v_20975 = (*qfn1(fn))(fn, v_20975);
    env = stack[-3];
    fn = elt(env, 9); // prepsq!*
    v_20975 = (*qfn1(fn))(fn, v_20975);
    env = stack[-3];
    fn = elt(env, 10); // prepreform
    v_20975 = (*qfn1(fn))(fn, v_20975);
    env = stack[-3];
    fn = elt(env, 11); // maprin
    v_20975 = (*qfn1(fn))(fn, v_20975);
    env = stack[-3];
    goto v_20861;
v_20863:
    goto v_20879;
v_20875:
    v_20975 = stack[-1];
    v_20976 = qcdr(v_20975);
    goto v_20876;
v_20877:
    v_20975 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20878;
v_20879:
    goto v_20875;
v_20876:
    goto v_20877;
v_20878:
    if (v_20976 == v_20975) goto v_20874;
    v_20975 = stack[-1];
    v_20975 = qcar(v_20975);
    if (!consp(v_20975)) goto v_20889;
    else goto v_20890;
v_20889:
    v_20975 = lisp_true;
    goto v_20888;
v_20890:
    v_20975 = stack[-1];
    v_20975 = qcar(v_20975);
    v_20975 = qcar(v_20975);
    v_20975 = (consp(v_20975) ? nil : lisp_true);
    goto v_20888;
    v_20975 = nil;
v_20888:
    if (v_20975 == nil) goto v_20885;
    else goto v_20886;
v_20885:
    v_20975 = stack[-1];
    v_20975 = qcar(v_20975);
    v_20975 = qcdr(v_20975);
    goto v_20884;
v_20886:
    v_20975 = nil;
    goto v_20884;
    v_20975 = nil;
v_20884:
    goto v_20913;
v_20907:
    v_20976 = stack[-1];
    v_20977 = qcar(v_20976);
    goto v_20908;
v_20909:
    v_20976 = v_20975;
    goto v_20910;
v_20911:
    v_20975 = nil;
    goto v_20912;
v_20913:
    goto v_20907;
v_20908:
    goto v_20909;
v_20910:
    goto v_20911;
v_20912:
    fn = elt(env, 12); // xprinf
    v_20975 = (*qfnn(fn))(fn, 3, v_20977, v_20976, v_20975);
    env = stack[-3];
    v_20975 = elt(env, 7); // " / "
    fn = elt(env, 13); // prin2!*
    v_20975 = (*qfn1(fn))(fn, v_20975);
    env = stack[-3];
    v_20975 = stack[-1];
    v_20975 = qcdr(v_20975);
    if (!consp(v_20975)) goto v_20926;
    else goto v_20927;
v_20926:
    v_20975 = lisp_true;
    goto v_20925;
v_20927:
    v_20975 = stack[-1];
    v_20975 = qcdr(v_20975);
    v_20975 = qcar(v_20975);
    v_20975 = (consp(v_20975) ? nil : lisp_true);
    goto v_20925;
    v_20975 = nil;
v_20925:
    if (v_20975 == nil) goto v_20922;
    else goto v_20923;
v_20922:
    v_20975 = stack[-1];
    v_20975 = qcdr(v_20975);
    v_20975 = qcdr(v_20975);
    if (v_20975 == nil) goto v_20939;
    else goto v_20938;
v_20939:
    goto v_20948;
v_20944:
    v_20975 = stack[-1];
    v_20975 = qcdr(v_20975);
    v_20975 = qcar(v_20975);
    v_20976 = qcdr(v_20975);
    goto v_20945;
v_20946:
    v_20975 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20947;
v_20948:
    goto v_20944;
v_20945:
    goto v_20946;
v_20947:
    v_20975 = Lneq(nil, v_20976, v_20975);
    env = stack[-3];
v_20938:
    goto v_20921;
v_20923:
    v_20975 = nil;
    goto v_20921;
    v_20975 = nil;
v_20921:
    goto v_20964;
v_20958:
    v_20976 = stack[-1];
    v_20977 = qcdr(v_20976);
    goto v_20959;
v_20960:
    v_20976 = v_20975;
    goto v_20961;
v_20962:
    v_20975 = nil;
    goto v_20963;
v_20964:
    goto v_20958;
v_20959:
    goto v_20960;
v_20961:
    goto v_20962;
v_20963:
    fn = elt(env, 12); // xprinf
    v_20975 = (*qfnn(fn))(fn, 3, v_20977, v_20976, v_20975);
    env = stack[-3];
    goto v_20861;
v_20874:
    v_20975 = stack[-1];
    v_20975 = qcar(v_20975);
    fn = elt(env, 14); // xprinf2
    v_20975 = (*qfn1(fn))(fn, v_20975);
    env = stack[-3];
    goto v_20861;
v_20861:
    v_20975 = stack[-2];
    qvalue(elt(env, 2)) = v_20975; // orig!*
    ;}  // end of a binding scope
    return onevalue(v_20975);
}



// Code for reduce!-eival!-powers

static LispObject CC_reduceKeivalKpowers(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20899, v_20900, v_20901, v_20902;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_20901 = v_20836;
    v_20902 = v_20835;
// end of prologue
    v_20899 = v_20901;
    if (!consp(v_20899)) goto v_20848;
    else goto v_20849;
v_20848:
    v_20899 = lisp_true;
    goto v_20847;
v_20849:
    v_20899 = v_20901;
    v_20899 = qcar(v_20899);
    v_20899 = (consp(v_20899) ? nil : lisp_true);
    goto v_20847;
    v_20899 = nil;
v_20847:
    if (v_20899 == nil) goto v_20845;
    v_20899 = lisp_true;
    goto v_20843;
v_20845:
    goto v_20864;
v_20860:
    v_20899 = v_20901;
    v_20899 = qcar(v_20899);
    v_20899 = qcar(v_20899);
    v_20900 = qcar(v_20899);
    goto v_20861;
v_20862:
    v_20899 = v_20902;
    v_20899 = qcar(v_20899);
    v_20899 = qcar(v_20899);
    goto v_20863;
v_20864:
    goto v_20860;
v_20861:
    goto v_20862;
v_20863:
    v_20899 = (v_20900 == v_20899 ? lisp_true : nil);
    v_20899 = (v_20899 == nil ? lisp_true : nil);
    goto v_20843;
    v_20899 = nil;
v_20843:
    if (v_20899 == nil) goto v_20841;
    goto v_20879;
v_20875:
    v_20900 = v_20901;
    goto v_20876;
v_20877:
    v_20899 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20878;
v_20879:
    goto v_20875;
v_20876:
    goto v_20877;
v_20878:
    return cons(v_20900, v_20899);
v_20841:
    goto v_20889;
v_20885:
    stack[0] = v_20902;
    goto v_20886;
v_20887:
    goto v_20896;
v_20892:
    v_20900 = v_20901;
    goto v_20893;
v_20894:
    v_20899 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20895;
v_20896:
    goto v_20892;
v_20893:
    goto v_20894;
v_20895:
    v_20899 = cons(v_20900, v_20899);
    env = stack[-1];
    goto v_20888;
v_20889:
    goto v_20885;
v_20886:
    goto v_20887;
v_20888:
    {
        LispObject v_20904 = stack[0];
        fn = elt(env, 1); // reduce!-eival!-powers1
        return (*qfn2(fn))(fn, v_20904, v_20899);
    }
    v_20899 = nil;
    return onevalue(v_20899);
}



// Code for make!-image

static LispObject CC_makeKimage(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20920, v_20921, v_20922;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20836;
    stack[-1] = v_20835;
// end of prologue
    v_20920 = stack[-1];
    if (!consp(v_20920)) goto v_20844;
    else goto v_20845;
v_20844:
    v_20920 = lisp_true;
    goto v_20843;
v_20845:
    v_20920 = stack[-1];
    v_20920 = qcar(v_20920);
    v_20920 = (consp(v_20920) ? nil : lisp_true);
    goto v_20843;
    v_20920 = nil;
v_20843:
    if (v_20920 == nil) goto v_20841;
    v_20920 = stack[-1];
    goto v_20839;
v_20841:
    goto v_20860;
v_20856:
    v_20920 = stack[-1];
    v_20920 = qcar(v_20920);
    v_20920 = qcar(v_20920);
    v_20921 = qcar(v_20920);
    goto v_20857;
v_20858:
    v_20920 = qvalue(elt(env, 1)); // m!-image!-variable
    goto v_20859;
v_20860:
    goto v_20856;
v_20857:
    goto v_20858;
v_20859:
    if (equal(v_20921, v_20920)) goto v_20854;
    else goto v_20855;
v_20854:
    goto v_20872;
v_20868:
    v_20920 = stack[-1];
    v_20920 = qcar(v_20920);
    v_20921 = qcdr(v_20920);
    goto v_20869;
v_20870:
    v_20920 = stack[0];
    goto v_20871;
v_20872:
    goto v_20868;
v_20869:
    goto v_20870;
v_20871:
    fn = elt(env, 2); // evaluate!-in!-order
    v_20920 = (*qfn2(fn))(fn, v_20921, v_20920);
    env = stack[-3];
    fn = elt(env, 3); // !*n2f
    stack[-2] = (*qfn1(fn))(fn, v_20920);
    env = stack[-3];
    goto v_20882;
v_20878:
    v_20920 = stack[-1];
    v_20921 = qcdr(v_20920);
    goto v_20879;
v_20880:
    v_20920 = stack[0];
    goto v_20881;
v_20882:
    goto v_20878;
v_20879:
    goto v_20880;
v_20881:
    v_20920 = CC_makeKimage(elt(env, 0), v_20921, v_20920);
    v_20921 = stack[-2];
    v_20922 = v_20921;
    if (v_20922 == nil) goto v_20890;
    else goto v_20891;
v_20890:
    goto v_20889;
v_20891:
    goto v_20903;
v_20897:
    v_20922 = stack[-1];
    v_20922 = qcar(v_20922);
    v_20922 = qcar(v_20922);
    goto v_20898;
v_20899:
    goto v_20900;
v_20901:
    goto v_20902;
v_20903:
    goto v_20897;
v_20898:
    goto v_20899;
v_20900:
    goto v_20901;
v_20902:
    return acons(v_20922, v_20921, v_20920);
    v_20920 = nil;
v_20889:
    goto v_20839;
v_20855:
    goto v_20917;
v_20913:
    v_20921 = stack[-1];
    goto v_20914;
v_20915:
    v_20920 = stack[0];
    goto v_20916;
v_20917:
    goto v_20913;
v_20914:
    goto v_20915;
v_20916:
    fn = elt(env, 2); // evaluate!-in!-order
    v_20920 = (*qfn2(fn))(fn, v_20921, v_20920);
    env = stack[-3];
    {
        fn = elt(env, 3); // !*n2f
        return (*qfn1(fn))(fn, v_20920);
    }
    v_20920 = nil;
v_20839:
    return onevalue(v_20920);
}



// Code for freeoflist

static LispObject CC_freeoflist(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20863, v_20864;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_20836;
    stack[-1] = v_20835;
// end of prologue
v_20840:
    v_20863 = stack[0];
    if (v_20863 == nil) goto v_20843;
    else goto v_20844;
v_20843:
    v_20863 = lisp_true;
    goto v_20839;
v_20844:
    goto v_20854;
v_20850:
    v_20864 = stack[-1];
    goto v_20851;
v_20852:
    v_20863 = stack[0];
    v_20863 = qcar(v_20863);
    goto v_20853;
v_20854:
    goto v_20850;
v_20851:
    goto v_20852;
v_20853:
    fn = elt(env, 1); // freeof
    v_20863 = (*qfn2(fn))(fn, v_20864, v_20863);
    env = stack[-2];
    if (v_20863 == nil) goto v_20848;
    v_20863 = stack[0];
    v_20863 = qcdr(v_20863);
    stack[0] = v_20863;
    goto v_20840;
v_20848:
    v_20863 = nil;
    goto v_20839;
    v_20863 = nil;
v_20839:
    return onevalue(v_20863);
}



// Code for ofsf_sippsubst1

static LispObject CC_ofsf_sippsubst1(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20868, v_20869, v_20870;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20869 = v_20836;
    v_20870 = v_20835;
// end of prologue
    goto v_20845;
v_20839:
    v_20868 = v_20870;
    if (!consp(v_20868)) goto v_20848;
    else goto v_20849;
v_20848:
    v_20868 = v_20870;
    stack[0] = v_20868;
    goto v_20847;
v_20849:
    v_20868 = v_20870;
    v_20868 = qcar(v_20868);
    stack[0] = v_20868;
    goto v_20847;
    stack[0] = nil;
v_20847:
    goto v_20840;
v_20841:
    goto v_20861;
v_20857:
    v_20868 = v_20870;
    v_20868 = qcdr(v_20868);
    v_20868 = qcar(v_20868);
    goto v_20858;
v_20859:
    goto v_20860;
v_20861:
    goto v_20857;
v_20858:
    goto v_20859;
v_20860:
    fn = elt(env, 1); // ofsf_siatsubf
    v_20868 = (*qfn2(fn))(fn, v_20868, v_20869);
    v_20869 = qcar(v_20868);
    goto v_20842;
v_20843:
    v_20868 = nil;
    goto v_20844;
v_20845:
    goto v_20839;
v_20840:
    goto v_20841;
v_20842:
    goto v_20843;
v_20844:
    {
        LispObject v_20872 = stack[0];
        return list3(v_20872, v_20869, v_20868);
    }
}



// Code for talp_maxd

static LispObject CC_talp_maxd(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20892, v_20893;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_20893 = v_20835;
// end of prologue
    v_20892 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_20892;
    v_20892 = v_20893;
    if (!consp(v_20892)) goto v_20846;
    else goto v_20847;
v_20846:
    v_20892 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20841;
v_20847:
    v_20892 = v_20893;
    fn = elt(env, 1); // rl_atl
    v_20892 = (*qfn1(fn))(fn, v_20892);
    env = stack[-3];
    stack[-2] = v_20892;
v_20854:
    v_20892 = stack[-2];
    if (v_20892 == nil) goto v_20857;
    else goto v_20858;
v_20857:
    goto v_20853;
v_20858:
    goto v_20866;
v_20862:
    v_20892 = stack[-2];
    v_20892 = qcar(v_20892);
    fn = elt(env, 2); // talp_arg2l
    v_20892 = (*qfn1(fn))(fn, v_20892);
    env = stack[-3];
    fn = elt(env, 3); // talp_td
    stack[0] = (*qfn1(fn))(fn, v_20892);
    env = stack[-3];
    goto v_20863;
v_20864:
    v_20892 = stack[-2];
    v_20892 = qcar(v_20892);
    fn = elt(env, 4); // talp_arg2r
    v_20892 = (*qfn1(fn))(fn, v_20892);
    env = stack[-3];
    fn = elt(env, 3); // talp_td
    v_20892 = (*qfn1(fn))(fn, v_20892);
    env = stack[-3];
    goto v_20865;
v_20866:
    goto v_20862;
v_20863:
    goto v_20864;
v_20865:
    v_20892 = Lmax2(nil, stack[0], v_20892);
    env = stack[-3];
    stack[0] = v_20892;
    goto v_20884;
v_20880:
    v_20893 = stack[0];
    goto v_20881;
v_20882:
    v_20892 = stack[-1];
    goto v_20883;
v_20884:
    goto v_20880;
v_20881:
    goto v_20882;
v_20883:
    v_20892 = (LispObject)greaterp2(v_20893, v_20892);
    v_20892 = v_20892 ? lisp_true : nil;
    env = stack[-3];
    if (v_20892 == nil) goto v_20878;
    v_20892 = stack[0];
    stack[-1] = v_20892;
    goto v_20876;
v_20878:
v_20876:
    v_20892 = stack[-2];
    v_20892 = qcdr(v_20892);
    stack[-2] = v_20892;
    goto v_20854;
v_20853:
    v_20892 = stack[-1];
v_20841:
    return onevalue(v_20892);
}



// Code for ctx_filter

static LispObject CC_ctx_filter(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20922, v_20923, v_20924;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_20922 = v_20836;
    stack[-4] = v_20835;
// end of prologue
    goto v_20843;
v_20839:
    stack[-5] = elt(env, 1); // ctx
    goto v_20840;
v_20841:
    fn = elt(env, 2); // ctx_ial
    v_20922 = (*qfn1(fn))(fn, v_20922);
    env = stack[-6];
    stack[-3] = v_20922;
v_20850:
    v_20922 = stack[-3];
    if (v_20922 == nil) goto v_20856;
    else goto v_20857;
v_20856:
    v_20922 = nil;
    goto v_20849;
v_20857:
    v_20922 = stack[-3];
    v_20922 = qcar(v_20922);
    v_20924 = v_20922;
    goto v_20871;
v_20867:
    v_20922 = v_20924;
    v_20923 = qcar(v_20922);
    goto v_20868;
v_20869:
    v_20922 = stack[-4];
    goto v_20870;
v_20871:
    goto v_20867;
v_20868:
    goto v_20869;
v_20870:
    v_20922 = Lmemq(nil, v_20923, v_20922);
    if (v_20922 == nil) goto v_20866;
    v_20922 = v_20924;
    v_20922 = ncons(v_20922);
    env = stack[-6];
    goto v_20864;
v_20866:
    v_20922 = nil;
v_20864:
    stack[-2] = v_20922;
    v_20922 = stack[-2];
    fn = elt(env, 3); // lastpair
    v_20922 = (*qfn1(fn))(fn, v_20922);
    env = stack[-6];
    stack[-1] = v_20922;
    v_20922 = stack[-3];
    v_20922 = qcdr(v_20922);
    stack[-3] = v_20922;
    v_20922 = stack[-1];
    if (!consp(v_20922)) goto v_20884;
    else goto v_20885;
v_20884:
    goto v_20850;
v_20885:
v_20851:
    v_20922 = stack[-3];
    if (v_20922 == nil) goto v_20889;
    else goto v_20890;
v_20889:
    v_20922 = stack[-2];
    goto v_20849;
v_20890:
    goto v_20898;
v_20894:
    stack[0] = stack[-1];
    goto v_20895;
v_20896:
    v_20922 = stack[-3];
    v_20922 = qcar(v_20922);
    v_20924 = v_20922;
    goto v_20911;
v_20907:
    v_20922 = v_20924;
    v_20923 = qcar(v_20922);
    goto v_20908;
v_20909:
    v_20922 = stack[-4];
    goto v_20910;
v_20911:
    goto v_20907;
v_20908:
    goto v_20909;
v_20910:
    v_20922 = Lmemq(nil, v_20923, v_20922);
    if (v_20922 == nil) goto v_20906;
    v_20922 = v_20924;
    v_20922 = ncons(v_20922);
    env = stack[-6];
    goto v_20904;
v_20906:
    v_20922 = nil;
v_20904:
    goto v_20897;
v_20898:
    goto v_20894;
v_20895:
    goto v_20896;
v_20897:
    v_20922 = Lrplacd(nil, stack[0], v_20922);
    env = stack[-6];
    v_20922 = stack[-1];
    fn = elt(env, 3); // lastpair
    v_20922 = (*qfn1(fn))(fn, v_20922);
    env = stack[-6];
    stack[-1] = v_20922;
    v_20922 = stack[-3];
    v_20922 = qcdr(v_20922);
    stack[-3] = v_20922;
    goto v_20851;
v_20849:
    goto v_20842;
v_20843:
    goto v_20839;
v_20840:
    goto v_20841;
v_20842:
    {
        LispObject v_20931 = stack[-5];
        return list2(v_20931, v_20922);
    }
}



// Code for containerom

static LispObject CC_containerom(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20963, v_20964;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_20835;
// end of prologue
    v_20963 = stack[-2];
    v_20963 = qcdr(v_20963);
    v_20963 = qcar(v_20963);
    stack[-1] = v_20963;
    v_20963 = stack[-2];
    v_20963 = qcar(v_20963);
    stack[0] = v_20963;
    v_20963 = elt(env, 1); // "<OMA>"
    fn = elt(env, 13); // printout
    v_20963 = (*qfn1(fn))(fn, v_20963);
    env = stack[-4];
    v_20963 = lisp_true;
    fn = elt(env, 14); // indent!*
    v_20963 = (*qfn1(fn))(fn, v_20963);
    env = stack[-4];
    goto v_20859;
v_20855:
    v_20964 = stack[0];
    goto v_20856;
v_20857:
    v_20963 = elt(env, 2); // vectorml
    goto v_20858;
v_20859:
    goto v_20855;
v_20856:
    goto v_20857;
v_20858:
    if (v_20964 == v_20963) goto v_20853;
    else goto v_20854;
v_20853:
    v_20963 = elt(env, 3); // vector
    stack[0] = v_20963;
    goto v_20852;
v_20854:
v_20852:
    goto v_20867;
v_20863:
    v_20964 = stack[0];
    goto v_20864;
v_20865:
    v_20963 = qvalue(elt(env, 4)); // valid_om!*
    goto v_20866;
v_20867:
    goto v_20863;
v_20864:
    goto v_20865;
v_20866:
    v_20963 = Lassoc(nil, v_20964, v_20963);
    v_20963 = qcdr(v_20963);
    v_20963 = qcar(v_20963);
    stack[-3] = v_20963;
    goto v_20885;
v_20881:
    v_20963 = stack[-2];
    v_20964 = qcar(v_20963);
    goto v_20882;
v_20883:
    v_20963 = elt(env, 5); // set
    goto v_20884;
v_20885:
    goto v_20881;
v_20882:
    goto v_20883;
v_20884:
    if (v_20964 == v_20963) goto v_20879;
    else goto v_20880;
v_20879:
    v_20963 = stack[-1];
    v_20963 = Lconsp(nil, v_20963);
    env = stack[-4];
    goto v_20878;
v_20880:
    v_20963 = nil;
    goto v_20878;
    v_20963 = nil;
v_20878:
    if (v_20963 == nil) goto v_20876;
    goto v_20902;
v_20898:
    v_20963 = stack[-1];
    v_20963 = qcar(v_20963);
    v_20963 = qcdr(v_20963);
    v_20963 = qcar(v_20963);
    v_20964 = Lintern(nil, v_20963);
    env = stack[-4];
    goto v_20899;
v_20900:
    v_20963 = elt(env, 6); // multiset
    goto v_20901;
v_20902:
    goto v_20898;
v_20899:
    goto v_20900;
v_20901:
    if (v_20964 == v_20963) goto v_20896;
    else goto v_20897;
v_20896:
    v_20963 = elt(env, 7); // multiset1
    stack[-3] = v_20963;
    goto v_20895;
v_20897:
v_20895:
    goto v_20874;
v_20876:
v_20874:
    goto v_20919;
v_20915:
    v_20963 = stack[-2];
    v_20964 = qcar(v_20963);
    goto v_20916;
v_20917:
    v_20963 = elt(env, 2); // vectorml
    goto v_20918;
v_20919:
    goto v_20915;
v_20916:
    goto v_20917;
v_20918:
    if (v_20964 == v_20963) goto v_20913;
    else goto v_20914;
v_20913:
    v_20963 = elt(env, 8); // "vector"
    stack[0] = v_20963;
    goto v_20912;
v_20914:
v_20912:
    goto v_20932;
v_20928:
    v_20963 = stack[-2];
    v_20964 = qcar(v_20963);
    goto v_20929;
v_20930:
    v_20963 = elt(env, 2); // vectorml
    goto v_20931;
v_20932:
    goto v_20928;
v_20929:
    goto v_20930;
v_20931:
    if (v_20964 == v_20963) goto v_20926;
    else goto v_20927;
v_20926:
    goto v_20941;
v_20937:
    v_20964 = elt(env, 3); // vector
    goto v_20938;
v_20939:
    v_20963 = stack[-2];
    v_20963 = qcdr(v_20963);
    goto v_20940;
v_20941:
    goto v_20937;
v_20938:
    goto v_20939;
v_20940:
    v_20963 = cons(v_20964, v_20963);
    env = stack[-4];
    stack[-2] = v_20963;
    goto v_20925;
v_20927:
v_20925:
    v_20963 = elt(env, 9); // "<OMS cd="""
    fn = elt(env, 13); // printout
    v_20963 = (*qfn1(fn))(fn, v_20963);
    env = stack[-4];
    v_20963 = stack[-3];
    v_20963 = Lprinc(nil, v_20963);
    env = stack[-4];
    v_20963 = elt(env, 10); // """ name="""
    v_20963 = Lprinc(nil, v_20963);
    env = stack[-4];
    v_20963 = stack[0];
    v_20963 = Lprinc(nil, v_20963);
    env = stack[-4];
    v_20963 = elt(env, 11); // """/>"
    v_20963 = Lprinc(nil, v_20963);
    env = stack[-4];
    v_20963 = stack[-2];
    v_20963 = qcdr(v_20963);
    v_20963 = qcdr(v_20963);
    fn = elt(env, 15); // multiom
    v_20963 = (*qfn1(fn))(fn, v_20963);
    env = stack[-4];
    v_20963 = nil;
    fn = elt(env, 14); // indent!*
    v_20963 = (*qfn1(fn))(fn, v_20963);
    env = stack[-4];
    v_20963 = elt(env, 12); // "</OMA>"
    fn = elt(env, 13); // printout
    v_20963 = (*qfn1(fn))(fn, v_20963);
    v_20963 = nil;
    return onevalue(v_20963);
}



// Code for s!-nextarg

static LispObject CC_sKnextarg(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_21051, v_21052, v_21053;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_20835;
// end of prologue
    v_21051 = qvalue(elt(env, 1)); // !*udebug
    if (v_21051 == nil) goto v_20844;
    v_21051 = nil;
    fn = elt(env, 12); // uprint
    v_21051 = (*qfn1(fn))(fn, v_21051);
    env = stack[-2];
    goto v_20842;
v_20844:
v_20842:
    v_21051 = qvalue(elt(env, 2)); // comb
    if (v_21051 == nil) goto v_20850;
    else goto v_20851;
v_20850:
    v_21051 = qvalue(elt(env, 3)); // i
    v_21051 = add1(v_21051);
    env = stack[-2];
    qvalue(elt(env, 3)) = v_21051; // i
    v_21051 = stack[0];
    fn = elt(env, 13); // initcomb
    v_21051 = (*qfn1(fn))(fn, v_21051);
    env = stack[-2];
    qvalue(elt(env, 2)) = v_21051; // comb
    goto v_20849;
v_20851:
v_20849:
    goto v_20866;
v_20862:
    v_21052 = stack[0];
    goto v_20863;
v_20864:
    v_21051 = qvalue(elt(env, 2)); // comb
    goto v_20865;
v_20866:
    goto v_20862;
v_20863:
    goto v_20864;
v_20865:
    fn = elt(env, 14); // getcomb
    v_21051 = (*qfn2(fn))(fn, v_21052, v_21051);
    env = stack[-2];
    stack[-1] = v_21051;
    if (v_21051 == nil) goto v_20860;
    goto v_20881;
v_20877:
    v_21052 = qvalue(elt(env, 3)); // i
    goto v_20878;
v_20879:
    v_21051 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20880;
v_20881:
    goto v_20877;
v_20878:
    goto v_20879;
v_20880:
    if (v_21052 == v_21051) goto v_20875;
    else goto v_20876;
v_20875:
    goto v_20889;
v_20885:
    v_21052 = qvalue(elt(env, 3)); // i
    goto v_20886;
v_20887:
    v_21051 = qvalue(elt(env, 4)); // upb
    goto v_20888;
v_20889:
    goto v_20885;
v_20886:
    goto v_20887;
v_20888:
    v_21051 = (LispObject)lesseq2(v_21052, v_21051);
    v_21051 = v_21051 ? lisp_true : nil;
    env = stack[-2];
    goto v_20874;
v_20876:
    v_21051 = nil;
    goto v_20874;
    v_21051 = nil;
v_20874:
    if (v_21051 == nil) goto v_20872;
    goto v_20900;
v_20896:
    v_21051 = stack[-1];
    v_21051 = qcar(v_21051);
    v_21052 = qcar(v_21051);
    goto v_20897;
v_20898:
    v_21051 = stack[-1];
    v_21051 = qcdr(v_21051);
    goto v_20899;
v_20900:
    goto v_20896;
v_20897:
    goto v_20898;
v_20899:
    return cons(v_21052, v_21051);
v_20872:
    goto v_20916;
v_20912:
    v_21052 = qvalue(elt(env, 3)); // i
    goto v_20913;
v_20914:
    v_21051 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20915;
v_20916:
    goto v_20912;
v_20913:
    goto v_20914;
v_20915:
    if (v_21052 == v_21051) goto v_20910;
    else goto v_20911;
v_20910:
    goto v_20924;
v_20920:
    v_21052 = qvalue(elt(env, 3)); // i
    goto v_20921;
v_20922:
    v_21051 = qvalue(elt(env, 4)); // upb
    goto v_20923;
v_20924:
    goto v_20920;
v_20921:
    goto v_20922;
v_20923:
    v_21051 = (LispObject)lesseq2(v_21052, v_21051);
    v_21051 = v_21051 ? lisp_true : nil;
    env = stack[-2];
    goto v_20909;
v_20911:
    v_21051 = nil;
    goto v_20909;
    v_21051 = nil;
v_20909:
    if (v_21051 == nil) goto v_20907;
    goto v_20935;
v_20931:
    v_21052 = elt(env, 5); // (null!-fn)
    goto v_20932;
v_20933:
    v_21051 = stack[0];
    goto v_20934;
v_20935:
    goto v_20931;
v_20932:
    goto v_20933;
v_20934:
    return cons(v_21052, v_21051);
v_20907:
    v_21051 = qvalue(elt(env, 6)); // acontract
    if (v_21051 == nil) goto v_20939;
    goto v_20948;
v_20944:
    v_21052 = qvalue(elt(env, 3)); // i
    goto v_20945;
v_20946:
    v_21051 = qvalue(elt(env, 4)); // upb
    goto v_20947;
v_20948:
    goto v_20944;
v_20945:
    goto v_20946;
v_20947:
    v_21051 = (LispObject)lesseq2(v_21052, v_21051);
    v_21051 = v_21051 ? lisp_true : nil;
    env = stack[-2];
    if (v_21051 == nil) goto v_20939;
    goto v_20959;
v_20953:
    v_21053 = qvalue(elt(env, 7)); // op
    goto v_20954;
v_20955:
    v_21051 = stack[-1];
    v_21052 = qcar(v_21051);
    goto v_20956;
v_20957:
    v_21051 = stack[-1];
    v_21051 = qcdr(v_21051);
    goto v_20958;
v_20959:
    goto v_20953;
v_20954:
    goto v_20955;
v_20956:
    goto v_20957;
v_20958:
    v_21051 = acons(v_21053, v_21052, v_21051);
    env = stack[-2];
    {
        fn = elt(env, 15); // mval
        return (*qfn1(fn))(fn, v_21051);
    }
v_20939:
    v_21051 = qvalue(elt(env, 8)); // mcontract
    if (v_21051 == nil) goto v_20966;
    goto v_20975;
v_20971:
    v_21052 = qvalue(elt(env, 3)); // i
    goto v_20972;
v_20973:
    v_21051 = qvalue(elt(env, 4)); // upb
    goto v_20974;
v_20975:
    goto v_20971;
v_20972:
    goto v_20973;
v_20974:
    v_21051 = (LispObject)lesseq2(v_21052, v_21051);
    v_21051 = v_21051 ? lisp_true : nil;
    env = stack[-2];
    if (v_21051 == nil) goto v_20966;
    goto v_20985;
v_20979:
    v_21053 = elt(env, 9); // null!-fn
    goto v_20980;
v_20981:
    v_21051 = stack[-1];
    v_21052 = qcar(v_21051);
    goto v_20982;
v_20983:
    v_21051 = stack[-1];
    v_21051 = qcdr(v_21051);
    goto v_20984;
v_20985:
    goto v_20979;
v_20980:
    goto v_20981;
v_20982:
    goto v_20983;
v_20984:
    return acons(v_21053, v_21052, v_21051);
v_20966:
    v_21051 = qvalue(elt(env, 10)); // expand
    if (v_21051 == nil) goto v_20992;
    v_21051 = nil;
    qvalue(elt(env, 10)) = v_21051; // expand
    goto v_21000;
v_20996:
    v_21052 = qvalue(elt(env, 11)); // identity
    goto v_20997;
v_20998:
    v_21051 = stack[0];
    goto v_20999;
v_21000:
    goto v_20996;
v_20997:
    goto v_20998;
v_20999:
    return cons(v_21052, v_21051);
v_20992:
    v_21051 = nil;
    goto v_20870;
    v_21051 = nil;
v_20870:
    goto v_20858;
v_20860:
    goto v_21016;
v_21012:
    v_21052 = qvalue(elt(env, 3)); // i
    goto v_21013;
v_21014:
    v_21051 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21015;
v_21016:
    goto v_21012;
v_21013:
    goto v_21014;
v_21015:
    if (v_21052 == v_21051) goto v_21010;
    else goto v_21011;
v_21010:
    goto v_21024;
v_21020:
    v_21052 = qvalue(elt(env, 3)); // i
    goto v_21021;
v_21022:
    v_21051 = qvalue(elt(env, 4)); // upb
    goto v_21023;
v_21024:
    goto v_21020;
v_21021:
    goto v_21022;
v_21023:
    v_21051 = (LispObject)lesseq2(v_21052, v_21051);
    v_21051 = v_21051 ? lisp_true : nil;
    env = stack[-2];
    goto v_21009;
v_21011:
    v_21051 = nil;
    goto v_21009;
    v_21051 = nil;
v_21009:
    if (v_21051 == nil) goto v_21007;
    goto v_21035;
v_21031:
    v_21052 = elt(env, 5); // (null!-fn)
    goto v_21032;
v_21033:
    v_21051 = stack[0];
    goto v_21034;
v_21035:
    goto v_21031;
v_21032:
    goto v_21033;
v_21034:
    return cons(v_21052, v_21051);
v_21007:
    v_21051 = qvalue(elt(env, 10)); // expand
    if (v_21051 == nil) goto v_21039;
    v_21051 = nil;
    qvalue(elt(env, 10)) = v_21051; // expand
    goto v_21047;
v_21043:
    v_21052 = qvalue(elt(env, 11)); // identity
    goto v_21044;
v_21045:
    v_21051 = stack[0];
    goto v_21046;
v_21047:
    goto v_21043;
v_21044:
    goto v_21045;
v_21046:
    return cons(v_21052, v_21051);
v_21039:
    v_21051 = nil;
v_20858:
    return onevalue(v_21051);
}



// Code for wedgef

static LispObject CC_wedgef(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_21069, v_21070, v_21071;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_20835;
// end of prologue
    v_21069 = stack[-1];
    fn = elt(env, 6); // dim!<deg
    v_21069 = (*qfn1(fn))(fn, v_21069);
    env = stack[-3];
    if (v_21069 == nil) goto v_20840;
    v_21069 = nil;
    goto v_20838;
v_20840:
    goto v_20851;
v_20847:
    v_21069 = stack[-1];
    v_21070 = qcar(v_21069);
    goto v_20848;
v_20849:
    v_21069 = elt(env, 1); // hodge
    goto v_20850;
v_20851:
    goto v_20847;
v_20848:
    goto v_20849;
v_20850:
    if (!consp(v_21070)) goto v_20845;
    v_21070 = qcar(v_21070);
    if (v_21070 == v_21069) goto v_20844;
    else goto v_20845;
v_20844:
    v_21069 = stack[-1];
    v_21069 = qcar(v_21069);
    v_21069 = qcdr(v_21069);
    v_21069 = qcar(v_21069);
    fn = elt(env, 7); // deg!*form
    v_21069 = (*qfn1(fn))(fn, v_21069);
    env = stack[-3];
    stack[-2] = v_21069;
    goto v_20869;
v_20865:
    stack[0] = stack[-2];
    goto v_20866;
v_20867:
    v_21069 = stack[-1];
    v_21069 = qcdr(v_21069);
    fn = elt(env, 8); // deg!*farg
    v_21069 = (*qfn1(fn))(fn, v_21069);
    env = stack[-3];
    goto v_20868;
v_20869:
    goto v_20865;
v_20866:
    goto v_20867;
v_20868:
    if (equal(stack[0], v_21069)) goto v_20863;
    else goto v_20864;
v_20863:
    goto v_20879;
v_20875:
    goto v_20885;
v_20881:
    goto v_20894;
v_20888:
    v_21069 = stack[-1];
    v_21069 = qcar(v_21069);
    v_21069 = qcdr(v_21069);
    v_21071 = qcar(v_21069);
    goto v_20889;
v_20890:
    v_21070 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20891;
v_20892:
    v_21069 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20893;
v_20894:
    goto v_20888;
v_20889:
    goto v_20890;
v_20891:
    goto v_20892;
v_20893:
    v_21069 = list2star(v_21071, v_21070, v_21069);
    env = stack[-3];
    stack[0] = ncons(v_21069);
    env = stack[-3];
    goto v_20882;
v_20883:
    v_21069 = stack[-1];
    v_21069 = qcdr(v_21069);
    v_21069 = qcdr(v_21069);
    if (v_21069 == nil) goto v_20906;
    v_21069 = stack[-1];
    v_21069 = qcdr(v_21069);
    fn = elt(env, 9); // mkuniquewedge1
    v_21069 = (*qfn1(fn))(fn, v_21069);
    env = stack[-3];
    goto v_20904;
v_20906:
    goto v_20923;
v_20917:
    v_21069 = stack[-1];
    v_21069 = qcdr(v_21069);
    v_21071 = qcar(v_21069);
    goto v_20918;
v_20919:
    v_21070 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20920;
v_20921:
    v_21069 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20922;
v_20923:
    goto v_20917;
v_20918:
    goto v_20919;
v_20920:
    goto v_20921;
v_20922:
    v_21069 = list2star(v_21071, v_21070, v_21069);
    env = stack[-3];
    v_21069 = ncons(v_21069);
    env = stack[-3];
    goto v_20904;
    v_21069 = nil;
v_20904:
    fn = elt(env, 10); // hodgepf
    v_21069 = (*qfn1(fn))(fn, v_21069);
    env = stack[-3];
    fn = elt(env, 11); // mkunarywedge
    v_21069 = (*qfn1(fn))(fn, v_21069);
    env = stack[-3];
    goto v_20884;
v_20885:
    goto v_20881;
v_20882:
    goto v_20883;
v_20884:
    fn = elt(env, 12); // wedgepf2
    stack[-1] = (*qfn2(fn))(fn, stack[0], v_21069);
    env = stack[-3];
    goto v_20876;
v_20877:
    goto v_20935;
v_20931:
    stack[0] = stack[-2];
    goto v_20932;
v_20933:
    goto v_20942;
v_20938:
    goto v_20939;
v_20940:
    v_21069 = qvalue(elt(env, 2)); // dimex!*
    fn = elt(env, 13); // negf
    v_21069 = (*qfn1(fn))(fn, v_21069);
    env = stack[-3];
    goto v_20941;
v_20942:
    goto v_20938;
v_20939:
    goto v_20940;
v_20941:
    fn = elt(env, 14); // addf
    v_21069 = (*qfn2(fn))(fn, stack[-2], v_21069);
    env = stack[-3];
    goto v_20934;
v_20935:
    goto v_20931;
v_20932:
    goto v_20933;
v_20934:
    fn = elt(env, 15); // multf
    v_21069 = (*qfn2(fn))(fn, stack[0], v_21069);
    env = stack[-3];
    fn = elt(env, 16); // mksgnsq
    v_21069 = (*qfn1(fn))(fn, v_21069);
    env = stack[-3];
    goto v_20878;
v_20879:
    goto v_20875;
v_20876:
    goto v_20877;
v_20878:
    {
        LispObject v_21075 = stack[-1];
        fn = elt(env, 17); // multpfsq
        return (*qfn2(fn))(fn, v_21075, v_21069);
    }
v_20864:
    v_21069 = stack[-1];
    {
        fn = elt(env, 18); // mkwedge
        return (*qfn1(fn))(fn, v_21069);
    }
    v_21069 = nil;
    goto v_20838;
v_20845:
    goto v_20961;
v_20957:
    v_21069 = stack[-1];
    v_21070 = qcar(v_21069);
    goto v_20958;
v_20959:
    v_21069 = elt(env, 3); // d
    goto v_20960;
v_20961:
    goto v_20957;
v_20958:
    goto v_20959;
v_20960:
    if (!consp(v_21070)) goto v_20955;
    v_21070 = qcar(v_21070);
    if (v_21070 == v_21069) goto v_20954;
    else goto v_20955;
v_20954:
    goto v_20974;
v_20970:
    v_21070 = elt(env, 3); // d
    goto v_20971;
v_20972:
    v_21069 = elt(env, 4); // noxpnd
    goto v_20973;
v_20974:
    goto v_20970;
v_20971:
    goto v_20972;
v_20973:
    v_21069 = Lflagp(nil, v_21070, v_21069);
    env = stack[-3];
    if (v_21069 == nil) goto v_20968;
    v_21069 = lisp_true;
    goto v_20966;
v_20968:
    goto v_20985;
v_20981:
    v_21070 = qvalue(elt(env, 5)); // lftshft!*
    goto v_20982;
v_20983:
    v_21069 = stack[-1];
    v_21069 = qcar(v_21069);
    v_21069 = qcdr(v_21069);
    v_21069 = qcar(v_21069);
    goto v_20984;
v_20985:
    goto v_20981;
v_20982:
    goto v_20983;
v_20984:
    fn = elt(env, 19); // smemqlp
    v_21069 = (*qfn2(fn))(fn, v_21070, v_21069);
    env = stack[-3];
    goto v_20966;
    v_21069 = nil;
v_20966:
    goto v_20953;
v_20955:
    v_21069 = nil;
    goto v_20953;
    v_21069 = nil;
v_20953:
    if (v_21069 == nil) goto v_20951;
    goto v_20999;
v_20995:
    goto v_21007;
v_21003:
    v_21069 = stack[-1];
    v_21069 = qcar(v_21069);
    v_21069 = qcdr(v_21069);
    v_21070 = qcar(v_21069);
    goto v_21004;
v_21005:
    v_21069 = stack[-1];
    v_21069 = qcdr(v_21069);
    goto v_21006;
v_21007:
    goto v_21003;
v_21004:
    goto v_21005;
v_21006:
    v_21069 = cons(v_21070, v_21069);
    env = stack[-3];
    fn = elt(env, 20); // dwedge
    v_21069 = (*qfn1(fn))(fn, v_21069);
    env = stack[-3];
    fn = elt(env, 11); // mkunarywedge
    stack[-2] = (*qfn1(fn))(fn, v_21069);
    env = stack[-3];
    goto v_20996;
v_20997:
    goto v_21019;
v_21015:
    goto v_21025;
v_21021:
    goto v_21034;
v_21028:
    v_21069 = stack[-1];
    v_21069 = qcar(v_21069);
    v_21069 = qcdr(v_21069);
    v_21071 = qcar(v_21069);
    goto v_21029;
v_21030:
    v_21070 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21031;
v_21032:
    v_21069 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21033;
v_21034:
    goto v_21028;
v_21029:
    goto v_21030;
v_21031:
    goto v_21032;
v_21033:
    v_21069 = list2star(v_21071, v_21070, v_21069);
    env = stack[-3];
    stack[0] = ncons(v_21069);
    env = stack[-3];
    goto v_21022;
v_21023:
    v_21069 = stack[-1];
    v_21069 = qcdr(v_21069);
    v_21069 = qcdr(v_21069);
    if (v_21069 == nil) goto v_21045;
    v_21069 = stack[-1];
    v_21069 = qcdr(v_21069);
    fn = elt(env, 20); // dwedge
    v_21069 = (*qfn1(fn))(fn, v_21069);
    env = stack[-3];
    goto v_21043;
v_21045:
    v_21069 = stack[-1];
    v_21069 = qcdr(v_21069);
    v_21069 = qcar(v_21069);
    fn = elt(env, 21); // exdfk
    v_21069 = (*qfn1(fn))(fn, v_21069);
    env = stack[-3];
    goto v_21043;
    v_21069 = nil;
v_21043:
    fn = elt(env, 11); // mkunarywedge
    v_21069 = (*qfn1(fn))(fn, v_21069);
    env = stack[-3];
    goto v_21024;
v_21025:
    goto v_21021;
v_21022:
    goto v_21023;
v_21024:
    fn = elt(env, 12); // wedgepf2
    stack[0] = (*qfn2(fn))(fn, stack[0], v_21069);
    env = stack[-3];
    goto v_21016;
v_21017:
    v_21069 = stack[-1];
    v_21069 = qcar(v_21069);
    v_21069 = qcdr(v_21069);
    v_21069 = qcar(v_21069);
    fn = elt(env, 7); // deg!*form
    v_21069 = (*qfn1(fn))(fn, v_21069);
    env = stack[-3];
    fn = elt(env, 16); // mksgnsq
    v_21069 = (*qfn1(fn))(fn, v_21069);
    env = stack[-3];
    fn = elt(env, 22); // negsq
    v_21069 = (*qfn1(fn))(fn, v_21069);
    env = stack[-3];
    goto v_21018;
v_21019:
    goto v_21015;
v_21016:
    goto v_21017;
v_21018:
    fn = elt(env, 17); // multpfsq
    v_21069 = (*qfn2(fn))(fn, stack[0], v_21069);
    env = stack[-3];
    goto v_20998;
v_20999:
    goto v_20995;
v_20996:
    goto v_20997;
v_20998:
    {
        LispObject v_21076 = stack[-2];
        fn = elt(env, 23); // addpf
        return (*qfn2(fn))(fn, v_21076, v_21069);
    }
v_20951:
    v_21069 = stack[-1];
    {
        fn = elt(env, 18); // mkwedge
        return (*qfn1(fn))(fn, v_21069);
    }
    v_21069 = nil;
v_20838:
    return onevalue(v_21069);
}



// Code for gbfplus

static LispObject CC_gbfplus(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20864, v_20865;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_20836;
    stack[-1] = v_20835;
// end of prologue
    goto v_20843;
v_20839:
    goto v_20849;
v_20845:
    v_20864 = stack[-1];
    v_20865 = qcar(v_20864);
    goto v_20846;
v_20847:
    v_20864 = stack[0];
    v_20864 = qcar(v_20864);
    goto v_20848;
v_20849:
    goto v_20845;
v_20846:
    goto v_20847;
v_20848:
    fn = elt(env, 1); // plubf
    stack[-2] = (*qfn2(fn))(fn, v_20865, v_20864);
    env = stack[-3];
    goto v_20840;
v_20841:
    goto v_20859;
v_20855:
    v_20864 = stack[-1];
    v_20865 = qcdr(v_20864);
    goto v_20856;
v_20857:
    v_20864 = stack[0];
    v_20864 = qcdr(v_20864);
    goto v_20858;
v_20859:
    goto v_20855;
v_20856:
    goto v_20857;
v_20858:
    fn = elt(env, 1); // plubf
    v_20864 = (*qfn2(fn))(fn, v_20865, v_20864);
    goto v_20842;
v_20843:
    goto v_20839;
v_20840:
    goto v_20841;
v_20842:
    {
        LispObject v_20869 = stack[-2];
        return cons(v_20869, v_20864);
    }
}



// Code for !:!:quotient

static LispObject CC_TTquotient(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20856, v_20857;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_20857 = v_20836;
    v_20856 = v_20835;
// end of prologue
    goto v_20843;
v_20839:
    stack[0] = v_20856;
    goto v_20840;
v_20841:
    v_20856 = v_20857;
    v_20856 = integerp(v_20856);
    if (v_20856 == nil) goto v_20848;
    v_20856 = v_20857;
    fn = elt(env, 1); // i2rd!*
    v_20856 = (*qfn1(fn))(fn, v_20856);
    env = stack[-1];
    goto v_20846;
v_20848:
    v_20856 = v_20857;
    goto v_20846;
    v_20856 = nil;
v_20846:
    goto v_20842;
v_20843:
    goto v_20839;
v_20840:
    goto v_20841;
v_20842:
    {
        LispObject v_20859 = stack[0];
        fn = elt(env, 2); // !:quotient
        return (*qfn2(fn))(fn, v_20859, v_20856);
    }
}



// Code for contr2

static LispObject CC_contr2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20901, v_20902;
    LispObject fn;
    LispObject v_20837, v_20836, v_20835;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "contr2");
    va_start(aa, nargs);
    v_20835 = va_arg(aa, LispObject);
    v_20836 = va_arg(aa, LispObject);
    v_20837 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20837,v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20835,v_20836,v_20837);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_20837;
    stack[-1] = v_20836;
    stack[-2] = v_20835;
// end of prologue
    stack[-3] = nil;
v_20842:
    v_20901 = stack[-1];
    if (v_20901 == nil) goto v_20845;
    else goto v_20846;
v_20845:
    goto v_20853;
v_20849:
    stack[-1] = stack[-3];
    goto v_20850;
v_20851:
    goto v_20860;
v_20856:
    v_20902 = stack[-2];
    goto v_20857;
v_20858:
    v_20901 = stack[0];
    goto v_20859;
v_20860:
    goto v_20856;
v_20857:
    goto v_20858;
v_20859:
    fn = elt(env, 1); // contr
    v_20901 = (*qfn2(fn))(fn, v_20902, v_20901);
    env = stack[-4];
    goto v_20852;
v_20853:
    goto v_20849;
v_20850:
    goto v_20851;
v_20852:
    {
        LispObject v_20907 = stack[-1];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_20907, v_20901);
    }
v_20846:
    v_20901 = stack[0];
    if (v_20901 == nil) goto v_20863;
    else goto v_20864;
v_20863:
    goto v_20871;
v_20867:
    stack[0] = stack[-3];
    goto v_20868;
v_20869:
    goto v_20878;
v_20874:
    v_20902 = stack[-2];
    goto v_20875;
v_20876:
    v_20901 = stack[-1];
    goto v_20877;
v_20878:
    goto v_20874;
v_20875:
    goto v_20876;
v_20877:
    fn = elt(env, 1); // contr
    v_20901 = (*qfn2(fn))(fn, v_20902, v_20901);
    env = stack[-4];
    goto v_20870;
v_20871:
    goto v_20867;
v_20868:
    goto v_20869;
v_20870:
    {
        LispObject v_20908 = stack[0];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_20908, v_20901);
    }
v_20864:
    goto v_20888;
v_20884:
    goto v_20894;
v_20890:
    v_20902 = stack[-2];
    goto v_20891;
v_20892:
    v_20901 = stack[-1];
    v_20901 = qcar(v_20901);
    goto v_20893;
v_20894:
    goto v_20890;
v_20891:
    goto v_20892;
v_20893:
    fn = elt(env, 3); // split!-road
    v_20902 = (*qfn2(fn))(fn, v_20902, v_20901);
    env = stack[-4];
    goto v_20885;
v_20886:
    v_20901 = stack[-3];
    goto v_20887;
v_20888:
    goto v_20884;
v_20885:
    goto v_20886;
v_20887:
    v_20901 = cons(v_20902, v_20901);
    env = stack[-4];
    stack[-3] = v_20901;
    v_20901 = stack[-1];
    v_20901 = qcdr(v_20901);
    stack[-1] = v_20901;
    goto v_20842;
    v_20901 = nil;
    return onevalue(v_20901);
}



// Code for innprodpex

static LispObject CC_innprodpex(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20907, v_20908;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_20836;
    stack[-2] = v_20835;
// end of prologue
v_20834:
    v_20907 = stack[-1];
    if (v_20907 == nil) goto v_20840;
    else goto v_20841;
v_20840:
    v_20907 = nil;
    goto v_20839;
v_20841:
    goto v_20851;
v_20847:
    v_20908 = stack[-2];
    goto v_20848;
v_20849:
    v_20907 = stack[-1];
    v_20907 = qcar(v_20907);
    v_20907 = qcar(v_20907);
    goto v_20850;
v_20851:
    goto v_20847;
v_20848:
    goto v_20849;
v_20850:
    fn = elt(env, 1); // innprodp2
    v_20907 = (*qfn2(fn))(fn, v_20908, v_20907);
    env = stack[-4];
    v_20908 = v_20907;
    v_20907 = v_20908;
    if (v_20907 == nil) goto v_20860;
    goto v_20869;
v_20863:
    v_20907 = v_20908;
    stack[-3] = qcdr(v_20907);
    goto v_20864;
v_20865:
    v_20907 = v_20908;
    v_20907 = qcar(v_20907);
    if (v_20907 == nil) goto v_20875;
    v_20907 = stack[-1];
    v_20907 = qcar(v_20907);
    v_20907 = qcdr(v_20907);
    fn = elt(env, 2); // negf
    v_20907 = (*qfn1(fn))(fn, v_20907);
    env = stack[-4];
    stack[0] = v_20907;
    goto v_20873;
v_20875:
    v_20907 = stack[-1];
    v_20907 = qcar(v_20907);
    v_20907 = qcdr(v_20907);
    stack[0] = v_20907;
    goto v_20873;
    stack[0] = nil;
v_20873:
    goto v_20866;
v_20867:
    goto v_20892;
v_20888:
    v_20908 = stack[-2];
    goto v_20889;
v_20890:
    v_20907 = stack[-1];
    v_20907 = qcdr(v_20907);
    goto v_20891;
v_20892:
    goto v_20888;
v_20889:
    goto v_20890;
v_20891:
    v_20907 = CC_innprodpex(elt(env, 0), v_20908, v_20907);
    goto v_20868;
v_20869:
    goto v_20863;
v_20864:
    goto v_20865;
v_20866:
    goto v_20867;
v_20868:
    {
        LispObject v_20913 = stack[-3];
        LispObject v_20914 = stack[0];
        return acons(v_20913, v_20914, v_20907);
    }
v_20860:
    goto v_20903;
v_20899:
    v_20908 = stack[-2];
    goto v_20900;
v_20901:
    v_20907 = stack[-1];
    v_20907 = qcdr(v_20907);
    goto v_20902;
v_20903:
    goto v_20899;
v_20900:
    goto v_20901;
v_20902:
    stack[-2] = v_20908;
    stack[-1] = v_20907;
    goto v_20834;
    v_20907 = nil;
    goto v_20839;
    v_20907 = nil;
v_20839:
    return onevalue(v_20907);
}



// Code for listeval0

static LispObject CC_listeval0(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20917, v_20918, v_20919;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_20835;
// end of prologue
    goto v_20849;
v_20845:
    v_20917 = qvalue(elt(env, 1)); // simpcount!*
    v_20918 = add1(v_20917);
    env = stack[-1];
    qvalue(elt(env, 1)) = v_20918; // simpcount!*
    goto v_20846;
v_20847:
    v_20917 = qvalue(elt(env, 2)); // simplimit!*
    goto v_20848;
v_20849:
    goto v_20845;
v_20846:
    goto v_20847;
v_20848:
    v_20917 = (LispObject)greaterp2(v_20918, v_20917);
    v_20917 = v_20917 ? lisp_true : nil;
    env = stack[-1];
    if (v_20917 == nil) goto v_20843;
    v_20917 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_20917; // simpcount!*
    goto v_20861;
v_20855:
    v_20919 = elt(env, 3); // rlisp
    goto v_20856;
v_20857:
    v_20918 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_20858;
v_20859:
    v_20917 = elt(env, 4); // "Simplification recursion too deep"
    goto v_20860;
v_20861:
    goto v_20855;
v_20856:
    goto v_20857;
v_20858:
    goto v_20859;
v_20860:
    fn = elt(env, 6); // rerror
    v_20917 = (*qfnn(fn))(fn, 3, v_20919, v_20918, v_20917);
    env = stack[-1];
    goto v_20841;
v_20843:
v_20841:
    v_20917 = stack[0];
    if (symbolp(v_20917)) goto v_20867;
    else goto v_20868;
v_20867:
    v_20917 = stack[0];
    if (!symbolp(v_20917)) v_20917 = nil;
    else { v_20917 = qfastgets(v_20917);
           if (v_20917 != nil) { v_20917 = elt(v_20917, 17); // share
#ifdef RECORD_GET
             if (v_20917 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v_20917 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v_20917 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v_20917 == SPID_NOPROP) v_20917 = nil; else v_20917 = lisp_true; }}
#endif
    if (v_20917 == nil) goto v_20873;
    v_20917 = stack[0];
    fn = elt(env, 7); // eval
    v_20917 = (*qfn1(fn))(fn, v_20917);
    env = stack[-1];
    v_20917 = CC_listeval0(elt(env, 0), v_20917);
    env = stack[-1];
    stack[0] = v_20917;
    goto v_20871;
v_20873:
    v_20917 = stack[0];
    if (!symbolp(v_20917)) v_20917 = nil;
    else { v_20917 = qfastgets(v_20917);
           if (v_20917 != nil) { v_20917 = elt(v_20917, 4); // avalue
#ifdef RECORD_GET
             if (v_20917 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_20917 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_20917 == SPID_NOPROP) v_20917 = nil; }}
#endif
    v_20919 = v_20917;
    if (v_20917 == nil) goto v_20880;
    goto v_20889;
v_20885:
    v_20917 = v_20919;
    v_20917 = qcdr(v_20917);
    v_20918 = qcar(v_20917);
    goto v_20886;
v_20887:
    v_20917 = stack[0];
    goto v_20888;
v_20889:
    goto v_20885;
v_20886:
    goto v_20887;
v_20888:
    if (equal(v_20918, v_20917)) goto v_20880;
    v_20917 = v_20919;
    v_20917 = qcdr(v_20917);
    v_20917 = qcar(v_20917);
    v_20917 = CC_listeval0(elt(env, 0), v_20917);
    env = stack[-1];
    stack[0] = v_20917;
    goto v_20871;
v_20880:
v_20871:
    goto v_20866;
v_20868:
v_20866:
    goto v_20906;
v_20902:
    v_20917 = stack[0];
    v_20917 = qcar(v_20917);
    fn = elt(env, 8); // getrtype
    v_20918 = (*qfn1(fn))(fn, v_20917);
    env = stack[-1];
    goto v_20903;
v_20904:
    v_20917 = elt(env, 5); // array
    goto v_20905;
v_20906:
    goto v_20902;
v_20903:
    goto v_20904;
v_20905:
    if (v_20918 == v_20917) goto v_20900;
    else goto v_20901;
v_20900:
    v_20917 = stack[0];
    fn = elt(env, 9); // getelv
    v_20917 = (*qfn1(fn))(fn, v_20917);
    env = stack[-1];
    v_20917 = CC_listeval0(elt(env, 0), v_20917);
    env = stack[-1];
    stack[0] = v_20917;
    goto v_20899;
v_20901:
v_20899:
    v_20917 = qvalue(elt(env, 1)); // simpcount!*
    v_20917 = sub1(v_20917);
    env = stack[-1];
    qvalue(elt(env, 1)) = v_20917; // simpcount!*
    v_20917 = stack[0];
    return onevalue(v_20917);
}



// Code for bas_make

static LispObject CC_bas_make(LispObject env,
                         LispObject v_20835, LispObject v_20836)
{
    env = qenv(env);
    LispObject v_20861, v_20862;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_20835,v_20836);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_20836;
    v_20861 = v_20835;
// end of prologue
    goto v_20847;
v_20839:
    stack[-3] = v_20861;
    goto v_20840;
v_20841:
    stack[-1] = stack[-2];
    goto v_20842;
v_20843:
    v_20861 = stack[-2];
    stack[0] = Llength(nil, v_20861);
    env = stack[-4];
    goto v_20844;
v_20845:
    goto v_20857;
v_20853:
    v_20861 = stack[-2];
    fn = elt(env, 1); // dp_ecart
    v_20862 = (*qfn1(fn))(fn, v_20861);
    env = stack[-4];
    goto v_20854;
v_20855:
    v_20861 = nil;
    goto v_20856;
v_20857:
    goto v_20853;
v_20854:
    goto v_20855;
v_20856:
    v_20861 = list2(v_20862, v_20861);
    goto v_20846;
v_20847:
    goto v_20839;
v_20840:
    goto v_20841;
v_20842:
    goto v_20843;
v_20844:
    goto v_20845;
v_20846:
    {
        LispObject v_20867 = stack[-3];
        LispObject v_20868 = stack[-1];
        LispObject v_20869 = stack[0];
        return list3star(v_20867, v_20868, v_20869, v_20861);
    }
}



// Code for rootextractf

static LispObject CC_rootextractf(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_21149, v_21150, v_21151;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_20835;
// end of prologue
    v_21149 = stack[-3];
    if (!consp(v_21149)) goto v_20843;
    else goto v_20844;
v_20843:
    v_21149 = lisp_true;
    goto v_20842;
v_20844:
    v_21149 = stack[-3];
    v_21149 = qcar(v_21149);
    v_21149 = (consp(v_21149) ? nil : lisp_true);
    goto v_20842;
    v_21149 = nil;
v_20842:
    if (v_21149 == nil) goto v_20840;
    v_21149 = stack[-3];
    goto v_20838;
v_20840:
    v_21149 = stack[-3];
    v_21149 = qcar(v_21149);
    v_21149 = qcar(v_21149);
    v_21149 = qcar(v_21149);
    stack[-4] = v_21149;
    v_21149 = stack[-3];
    v_21149 = qcar(v_21149);
    v_21149 = qcar(v_21149);
    v_21149 = qcdr(v_21149);
    stack[0] = v_21149;
    v_21149 = stack[-3];
    v_21149 = qcdr(v_21149);
    v_21149 = CC_rootextractf(elt(env, 0), v_21149);
    env = stack[-5];
    stack[-2] = v_21149;
    v_21149 = stack[-3];
    v_21149 = qcar(v_21149);
    v_21149 = qcdr(v_21149);
    v_21149 = CC_rootextractf(elt(env, 0), v_21149);
    env = stack[-5];
    stack[-1] = v_21149;
    v_21149 = stack[-1];
    if (v_21149 == nil) goto v_20879;
    else goto v_20880;
v_20879:
    v_21149 = stack[-2];
    goto v_20861;
v_20880:
    v_21149 = stack[-4];
    if (!consp(v_21149)) goto v_20883;
    else goto v_20884;
v_20883:
    goto v_20893;
v_20887:
    v_21149 = stack[-3];
    v_21149 = qcar(v_21149);
    v_21151 = qcar(v_21149);
    goto v_20888;
v_20889:
    v_21150 = stack[-1];
    goto v_20890;
v_20891:
    v_21149 = stack[-2];
    goto v_20892;
v_20893:
    goto v_20887;
v_20888:
    goto v_20889;
v_20890:
    goto v_20891;
v_20892:
    return acons(v_21151, v_21150, v_21149);
v_20884:
    goto v_20909;
v_20905:
    v_21149 = stack[-4];
    v_21150 = qcar(v_21149);
    goto v_20906;
v_20907:
    v_21149 = elt(env, 1); // sqrt
    goto v_20908;
v_20909:
    goto v_20905;
v_20906:
    goto v_20907;
v_20908:
    if (v_21150 == v_21149) goto v_20903;
    else goto v_20904;
v_20903:
    v_21149 = lisp_true;
    goto v_20902;
v_20904:
    goto v_20924;
v_20920:
    v_21149 = stack[-4];
    v_21150 = qcar(v_21149);
    goto v_20921;
v_20922:
    v_21149 = elt(env, 2); // expt
    goto v_20923;
v_20924:
    goto v_20920;
v_20921:
    goto v_20922;
v_20923:
    if (v_21150 == v_21149) goto v_20918;
    else goto v_20919;
v_20918:
    goto v_20937;
v_20933:
    v_21149 = stack[-4];
    v_21149 = qcdr(v_21149);
    v_21149 = qcdr(v_21149);
    v_21150 = qcar(v_21149);
    goto v_20934;
v_20935:
    v_21149 = elt(env, 3); // quotient
    goto v_20936;
v_20937:
    goto v_20933;
v_20934:
    goto v_20935;
v_20936:
    if (!consp(v_21150)) goto v_20931;
    v_21150 = qcar(v_21150);
    if (v_21150 == v_21149) goto v_20930;
    else goto v_20931;
v_20930:
    goto v_20951;
v_20947:
    v_21149 = stack[-4];
    v_21149 = qcdr(v_21149);
    v_21149 = qcdr(v_21149);
    v_21149 = qcar(v_21149);
    v_21149 = qcdr(v_21149);
    v_21150 = qcar(v_21149);
    goto v_20948;
v_20949:
    v_21149 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20950;
v_20951:
    goto v_20947;
v_20948:
    goto v_20949;
v_20950:
    if (v_21150 == v_21149) goto v_20945;
    else goto v_20946;
v_20945:
    v_21149 = stack[-4];
    v_21149 = qcdr(v_21149);
    v_21149 = qcdr(v_21149);
    v_21149 = qcar(v_21149);
    v_21149 = qcdr(v_21149);
    v_21149 = qcdr(v_21149);
    v_21149 = qcar(v_21149);
    v_21149 = (is_number(v_21149) ? lisp_true : nil);
    goto v_20944;
v_20946:
    v_21149 = nil;
    goto v_20944;
    v_21149 = nil;
v_20944:
    goto v_20929;
v_20931:
    v_21149 = nil;
    goto v_20929;
    v_21149 = nil;
v_20929:
    goto v_20917;
v_20919:
    v_21149 = nil;
    goto v_20917;
    v_21149 = nil;
v_20917:
    goto v_20902;
    v_21149 = nil;
v_20902:
    if (v_21149 == nil) goto v_20900;
    goto v_20981;
v_20977:
    v_21151 = stack[0];
    goto v_20978;
v_20979:
    goto v_20991;
v_20987:
    v_21149 = stack[-4];
    v_21150 = qcar(v_21149);
    goto v_20988;
v_20989:
    v_21149 = elt(env, 1); // sqrt
    goto v_20990;
v_20991:
    goto v_20987;
v_20988:
    goto v_20989;
v_20990:
    if (v_21150 == v_21149) goto v_20985;
    else goto v_20986;
v_20985:
    v_21149 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_20984;
v_20986:
    v_21149 = stack[-4];
    v_21149 = qcdr(v_21149);
    v_21149 = qcdr(v_21149);
    v_21149 = qcar(v_21149);
    v_21149 = qcdr(v_21149);
    v_21149 = qcdr(v_21149);
    v_21149 = qcar(v_21149);
    goto v_20984;
    v_21149 = nil;
v_20984:
    goto v_20980;
v_20981:
    goto v_20977;
v_20978:
    goto v_20979;
v_20980:
    v_21149 = Ldivide(nil, v_21151, v_21149);
    env = stack[-5];
    stack[0] = v_21149;
    goto v_21013;
v_21009:
    v_21149 = stack[0];
    v_21150 = qcar(v_21149);
    goto v_21010;
v_21011:
    v_21149 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21012;
v_21013:
    goto v_21009;
v_21010:
    goto v_21011;
v_21012:
    if (v_21150 == v_21149) goto v_21007;
    else goto v_21008;
v_21007:
    v_21149 = stack[-1];
    if (v_21149 == nil) goto v_21019;
    else goto v_21020;
v_21019:
    v_21149 = stack[-2];
    goto v_21018;
v_21020:
    goto v_21032;
v_21026:
    v_21149 = stack[-3];
    v_21149 = qcar(v_21149);
    v_21151 = qcar(v_21149);
    goto v_21027;
v_21028:
    v_21150 = stack[-1];
    goto v_21029;
v_21030:
    v_21149 = stack[-2];
    goto v_21031;
v_21032:
    goto v_21026;
v_21027:
    goto v_21028;
v_21029:
    goto v_21030;
v_21031:
    return acons(v_21151, v_21150, v_21149);
    v_21149 = nil;
v_21018:
    goto v_20861;
v_21008:
    v_21149 = stack[-4];
    v_21149 = qcdr(v_21149);
    v_21149 = qcar(v_21149);
    if (is_number(v_21149)) goto v_21038;
    else goto v_21039;
v_21038:
    goto v_21048;
v_21044:
    goto v_21054;
v_21050:
    v_21149 = stack[-4];
    v_21149 = qcdr(v_21149);
    v_21150 = qcar(v_21149);
    goto v_21051;
v_21052:
    v_21149 = stack[0];
    v_21149 = qcar(v_21149);
    goto v_21053;
v_21054:
    goto v_21050;
v_21051:
    goto v_21052;
v_21053:
    v_21150 = Lexpt(nil, v_21150, v_21149);
    env = stack[-5];
    goto v_21045;
v_21046:
    v_21149 = stack[-1];
    goto v_21047;
v_21048:
    goto v_21044;
v_21045:
    goto v_21046;
v_21047:
    fn = elt(env, 4); // multd
    v_21149 = (*qfn2(fn))(fn, v_21150, v_21149);
    env = stack[-5];
    stack[-1] = v_21149;
    v_21149 = stack[0];
    v_21149 = qcdr(v_21149);
    stack[0] = v_21149;
    goto v_21006;
v_21039:
    goto v_21071;
v_21067:
    v_21149 = stack[-4];
    v_21149 = qcdr(v_21149);
    v_21150 = qcar(v_21149);
    goto v_21068;
v_21069:
    v_21149 = stack[0];
    v_21149 = qcar(v_21149);
    goto v_21070;
v_21071:
    goto v_21067;
v_21068:
    goto v_21069;
v_21070:
    v_21149 = list2(v_21150, v_21149);
    env = stack[-5];
    fn = elt(env, 5); // simpexpt
    v_21149 = (*qfn1(fn))(fn, v_21149);
    env = stack[-5];
    v_21151 = v_21149;
    goto v_21085;
v_21081:
    v_21149 = v_21151;
    v_21150 = qcdr(v_21149);
    goto v_21082;
v_21083:
    v_21149 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21084;
v_21085:
    goto v_21081;
v_21082:
    goto v_21083;
v_21084:
    if (v_21150 == v_21149) goto v_21079;
    else goto v_21080;
v_21079:
    goto v_21094;
v_21090:
    v_21149 = v_21151;
    v_21150 = qcar(v_21149);
    goto v_21091;
v_21092:
    v_21149 = stack[-1];
    goto v_21093;
v_21094:
    goto v_21090;
v_21091:
    goto v_21092;
v_21093:
    fn = elt(env, 6); // multf
    v_21149 = (*qfn2(fn))(fn, v_21150, v_21149);
    env = stack[-5];
    stack[-1] = v_21149;
    v_21149 = stack[0];
    v_21149 = qcdr(v_21149);
    stack[0] = v_21149;
    goto v_21078;
v_21080:
    v_21149 = stack[-3];
    v_21149 = qcar(v_21149);
    v_21149 = qcar(v_21149);
    v_21149 = qcdr(v_21149);
    stack[0] = v_21149;
    goto v_21078;
v_21078:
    goto v_21006;
v_21006:
    goto v_20878;
v_20900:
v_20878:
    goto v_21114;
v_21110:
    v_21150 = stack[0];
    goto v_21111;
v_21112:
    v_21149 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21113;
v_21114:
    goto v_21110;
v_21111:
    goto v_21112;
v_21113:
    if (v_21150 == v_21149) goto v_21108;
    else goto v_21109;
v_21108:
    goto v_21122;
v_21118:
    v_21150 = stack[-1];
    goto v_21119;
v_21120:
    v_21149 = stack[-2];
    goto v_21121;
v_21122:
    goto v_21118;
v_21119:
    goto v_21120;
v_21121:
    {
        fn = elt(env, 7); // addf
        return (*qfn2(fn))(fn, v_21150, v_21149);
    }
v_21109:
    v_21149 = stack[-1];
    if (v_21149 == nil) goto v_21125;
    else goto v_21126;
v_21125:
    v_21149 = stack[-2];
    goto v_21107;
v_21126:
    goto v_21138;
v_21132:
    goto v_21144;
v_21140:
    v_21150 = stack[-4];
    goto v_21141;
v_21142:
    v_21149 = stack[0];
    goto v_21143;
v_21144:
    goto v_21140;
v_21141:
    goto v_21142;
v_21143:
    fn = elt(env, 8); // to
    v_21151 = (*qfn2(fn))(fn, v_21150, v_21149);
    goto v_21133;
v_21134:
    v_21150 = stack[-1];
    goto v_21135;
v_21136:
    v_21149 = stack[-2];
    goto v_21137;
v_21138:
    goto v_21132;
v_21133:
    goto v_21134;
v_21135:
    goto v_21136;
v_21137:
    return acons(v_21151, v_21150, v_21149);
    v_21149 = nil;
v_21107:
v_20861:
    goto v_20838;
    v_21149 = nil;
v_20838:
    return onevalue(v_21149);
}



// Code for ra_u

static LispObject CC_ra_u(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20840;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_20840 = v_20835;
// end of prologue
    fn = elt(env, 1); // ra_iv
    v_20840 = (*qfn1(fn))(fn, v_20840);
    env = stack[0];
    {
        fn = elt(env, 2); // riv_u
        return (*qfn1(fn))(fn, v_20840);
    }
}



// Code for lastcar

static LispObject CC_lastcar(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20856, v_20857;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20856 = v_20835;
// end of prologue
v_20839:
    v_20857 = v_20856;
    if (v_20857 == nil) goto v_20842;
    else goto v_20843;
v_20842:
    v_20856 = nil;
    goto v_20838;
v_20843:
    v_20857 = v_20856;
    v_20857 = qcdr(v_20857);
    if (v_20857 == nil) goto v_20846;
    else goto v_20847;
v_20846:
    v_20856 = qcar(v_20856);
    goto v_20838;
v_20847:
    v_20856 = qcdr(v_20856);
    goto v_20839;
    v_20856 = nil;
v_20838:
    return onevalue(v_20856);
}



// Code for ofsf_decdeg2

static LispObject CC_ofsf_decdeg2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21053, v_21054, v_21055;
    LispObject fn;
    LispObject v_20837, v_20836, v_20835;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_decdeg2");
    va_start(aa, nargs);
    v_20835 = va_arg(aa, LispObject);
    v_20836 = va_arg(aa, LispObject);
    v_20837 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20837,v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20835,v_20836,v_20837);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_20837;
    stack[-5] = v_20836;
    stack[-3] = v_20835;
// end of prologue
// Binding !*gcd
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-7, 1, -2);
    qvalue(elt(env, 1)) = nil; // !*gcd
    stack[-1] = nil;
    v_21053 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_21053;
    v_21053 = lisp_true;
    qvalue(elt(env, 1)) = v_21053; // !*gcd
    v_21053 = qvalue(elt(env, 2)); // !*rlbrkcxk
    if (v_21053 == nil) goto v_20852;
    goto v_20859;
v_20855:
    v_21054 = stack[-3];
    goto v_20856;
v_20857:
    v_21053 = stack[-5];
    goto v_20858;
v_20859:
    goto v_20855;
v_20856:
    goto v_20857;
v_20858:
    fn = elt(env, 4); // ofsf_cxkdgcd
    v_21053 = (*qfn2(fn))(fn, v_21054, v_21053);
    env = stack[-7];
    stack[0] = v_21053;
    goto v_20850;
v_20852:
v_20850:
    v_21053 = stack[-3];
    fn = elt(env, 5); // cl_atl1
    v_21053 = (*qfn1(fn))(fn, v_21053);
    env = stack[-7];
    stack[-3] = v_21053;
v_20866:
    v_21053 = stack[-3];
    if (v_21053 == nil) goto v_20869;
    goto v_20879;
v_20875:
    v_21054 = stack[0];
    goto v_20876;
v_20877:
    v_21053 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20878;
v_20879:
    goto v_20875;
v_20876:
    goto v_20877;
v_20878:
    v_21053 = Leqn(nil, v_21054, v_21053);
    env = stack[-7];
    if (v_21053 == nil) goto v_20873;
    else goto v_20869;
v_20873:
    goto v_20870;
v_20869:
    goto v_20865;
v_20870:
    v_21053 = stack[-3];
    v_21053 = qcar(v_21053);
    v_21054 = v_21053;
    v_21053 = stack[-3];
    v_21053 = qcdr(v_21053);
    stack[-3] = v_21053;
    v_21053 = v_21054;
    stack[-6] = v_21053;
    goto v_20899;
v_20893:
    v_21055 = stack[-6];
    goto v_20894;
v_20895:
    v_21054 = stack[-5];
    goto v_20896;
v_20897:
    v_21053 = stack[-4];
    goto v_20898;
v_20899:
    goto v_20893;
v_20894:
    goto v_20895;
v_20896:
    goto v_20897;
v_20898:
    fn = elt(env, 6); // ofsf_ignshift
    v_21053 = (*qfnn(fn))(fn, 3, v_21055, v_21054, v_21053);
    env = stack[-7];
    v_21055 = v_21053;
    goto v_20915;
v_20911:
    v_21054 = v_21055;
    goto v_20912;
v_20913:
    v_21053 = elt(env, 3); // odd
    goto v_20914;
v_20915:
    goto v_20911;
v_20912:
    goto v_20913;
v_20914:
    if (v_21054 == v_21053) goto v_20909;
    else goto v_20910;
v_20909:
    v_21053 = stack[-1];
    v_21053 = (v_21053 == nil ? lisp_true : nil);
    goto v_20908;
v_20910:
    v_21053 = nil;
    goto v_20908;
    v_21053 = nil;
v_20908:
    if (v_21053 == nil) goto v_20906;
    v_21053 = elt(env, 3); // odd
    stack[-1] = v_21053;
    goto v_20904;
v_20906:
    v_21053 = v_21055;
    if (v_21053 == nil) goto v_20924;
    else goto v_20925;
v_20924:
    goto v_20932;
v_20928:
    v_21053 = stack[-6];
    v_21053 = qcdr(v_21053);
    v_21054 = qcar(v_21053);
    goto v_20929;
v_20930:
    v_21053 = stack[-5];
    goto v_20931;
v_20932:
    goto v_20928;
v_20929:
    goto v_20930;
v_20931:
    fn = elt(env, 7); // sfto_reorder
    v_21053 = (*qfn2(fn))(fn, v_21054, v_21053);
    env = stack[-7];
    stack[-6] = v_21053;
v_20939:
    v_21053 = stack[-6];
    if (!consp(v_21053)) goto v_20950;
    else goto v_20951;
v_20950:
    v_21053 = lisp_true;
    goto v_20949;
v_20951:
    v_21053 = stack[-6];
    v_21053 = qcar(v_21053);
    v_21053 = (consp(v_21053) ? nil : lisp_true);
    goto v_20949;
    v_21053 = nil;
v_20949:
    if (v_21053 == nil) goto v_20946;
    else goto v_20947;
v_20946:
    goto v_20967;
v_20963:
    v_21053 = stack[-6];
    v_21053 = qcar(v_21053);
    v_21053 = qcar(v_21053);
    v_21054 = qcar(v_21053);
    goto v_20964;
v_20965:
    v_21053 = stack[-5];
    goto v_20966;
v_20967:
    goto v_20963;
v_20964:
    goto v_20965;
v_20966:
    if (v_21054 == v_21053) goto v_20961;
    else goto v_20962;
v_20961:
    goto v_20978;
v_20974:
    v_21054 = stack[0];
    goto v_20975;
v_20976:
    v_21053 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20977;
v_20978:
    goto v_20974;
v_20975:
    goto v_20976;
v_20977:
    v_21053 = Lneq(nil, v_21054, v_21053);
    env = stack[-7];
    goto v_20960;
v_20962:
    v_21053 = nil;
    goto v_20960;
    v_21053 = nil;
v_20960:
    goto v_20945;
v_20947:
    v_21053 = nil;
    goto v_20945;
    v_21053 = nil;
v_20945:
    if (v_21053 == nil) goto v_20942;
    else goto v_20943;
v_20942:
    goto v_20938;
v_20943:
    goto v_20993;
v_20989:
    v_21054 = stack[0];
    goto v_20990;
v_20991:
    v_21053 = stack[-6];
    v_21053 = qcar(v_21053);
    v_21053 = qcar(v_21053);
    v_21053 = qcdr(v_21053);
    goto v_20992;
v_20993:
    goto v_20989;
v_20990:
    goto v_20991;
v_20992:
    fn = elt(env, 8); // gcdf
    v_21053 = (*qfn2(fn))(fn, v_21054, v_21053);
    env = stack[-7];
    stack[0] = v_21053;
    v_21053 = stack[-6];
    v_21053 = qcdr(v_21053);
    stack[-6] = v_21053;
    goto v_20939;
v_20938:
    goto v_20904;
v_20925:
v_20904:
    goto v_21011;
v_21007:
    v_21054 = stack[0];
    goto v_21008;
v_21009:
    v_21053 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21010;
v_21011:
    goto v_21007;
v_21008:
    goto v_21009;
v_21010:
    v_21053 = (LispObject)greaterp2(v_21054, v_21053);
    v_21053 = v_21053 ? lisp_true : nil;
    env = stack[-7];
    if (v_21053 == nil) goto v_21004;
    goto v_21019;
v_21015:
    v_21054 = stack[-1];
    goto v_21016;
v_21017:
    v_21053 = elt(env, 3); // odd
    goto v_21018;
v_21019:
    goto v_21015;
v_21016:
    goto v_21017;
v_21018:
    if (v_21054 == v_21053) goto v_21014;
    else goto v_21004;
v_21014:
    v_21053 = lisp_true;
    stack[-1] = v_21053;
v_21025:
    goto v_21035;
v_21031:
    v_21054 = stack[0];
    goto v_21032;
v_21033:
    v_21053 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_21034;
v_21035:
    goto v_21031;
v_21032:
    goto v_21033;
v_21034:
    fn = elt(env, 9); // quotf
    v_21053 = (*qfn2(fn))(fn, v_21054, v_21053);
    env = stack[-7];
    v_21055 = v_21053;
    if (v_21053 == nil) goto v_21028;
    else goto v_21029;
v_21028:
    goto v_21024;
v_21029:
    v_21053 = v_21055;
    stack[0] = v_21053;
    goto v_21025;
v_21024:
    goto v_21002;
v_21004:
v_21002:
    goto v_20866;
v_20865:
    goto v_21048;
v_21044:
    v_21054 = stack[0];
    goto v_21045;
v_21046:
    v_21053 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21047;
v_21048:
    goto v_21044;
v_21045:
    goto v_21046;
v_21047:
    if (v_21054 == v_21053) goto v_21042;
    else goto v_21043;
v_21042:
    v_21053 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20846;
v_21043:
    v_21053 = stack[0];
v_20846:
    ;}  // end of a binding scope
    return onevalue(v_21053);
}



// Code for settcollectnonmultiprolongations

static LispObject CC_settcollectnonmultiprolongations(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20973, v_20974, v_20975;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_20835;
// end of prologue
    v_20973 = qvalue(elt(env, 1)); // fluidbibasissett
    v_20973 = qcar(v_20973);
    if (v_20973 == nil) goto v_20840;
    v_20973 = qvalue(elt(env, 1)); // fluidbibasissett
    v_20973 = qcar(v_20973);
    stack[-4] = v_20973;
    goto v_20857;
v_20853:
    v_20974 = stack[-4];
    goto v_20854;
v_20855:
    v_20973 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20856;
v_20857:
    goto v_20853;
v_20854:
    goto v_20855;
v_20856:
    v_20973 = *(LispObject *)((char *)v_20974 + (CELL-TAG_VECTOR) + (((intptr_t)v_20973-TAG_FIXNUM)/(16/CELL)));
    v_20973 = qcar(v_20973);
    fn = elt(env, 3); // monomgetfirstmultivar
    v_20973 = (*qfn1(fn))(fn, v_20973);
    env = stack[-5];
    v_20973 = (LispObject)((intptr_t)(v_20973) - 0x10);
    stack[-1] = v_20973;
    v_20973 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_20973;
v_20866:
    goto v_20878;
v_20874:
    v_20974 = stack[-1];
    goto v_20875;
v_20876:
    v_20973 = stack[0];
    goto v_20877;
v_20878:
    goto v_20874;
v_20875:
    goto v_20876;
v_20877:
    v_20973 = difference2(v_20974, v_20973);
    env = stack[-5];
    v_20973 = Lminusp(nil, v_20973);
    env = stack[-5];
    if (v_20973 == nil) goto v_20871;
    goto v_20865;
v_20871:
    goto v_20891;
v_20887:
    v_20974 = stack[-4];
    goto v_20888;
v_20889:
    v_20973 = stack[0];
    goto v_20890;
v_20891:
    goto v_20887;
v_20888:
    goto v_20889;
v_20890:
    fn = elt(env, 4); // tripleisprolongedby
    v_20973 = (*qfn2(fn))(fn, v_20974, v_20973);
    env = stack[-5];
    if (v_20973 == nil) goto v_20884;
    else goto v_20885;
v_20884:
    goto v_20899;
v_20895:
    goto v_20904;
v_20900:
    v_20974 = stack[-4];
    goto v_20901;
v_20902:
    v_20973 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_20903;
v_20904:
    goto v_20900;
v_20901:
    goto v_20902;
v_20903:
    v_20975 = *(LispObject *)((char *)v_20974 + (CELL-TAG_VECTOR) + (((intptr_t)v_20973-TAG_FIXNUM)/(16/CELL)));
    goto v_20896;
v_20897:
    goto v_20912;
v_20908:
    v_20974 = qvalue(elt(env, 2)); // fluidbibasissinglevariablemonomialss
    goto v_20909;
v_20910:
    v_20973 = stack[0];
    goto v_20911;
v_20912:
    goto v_20908;
v_20909:
    goto v_20910;
v_20911:
    v_20973 = *(LispObject *)((char *)v_20974 + (CELL-TAG_VECTOR) + (((intptr_t)v_20973-TAG_FIXNUM)/(16/CELL)));
    goto v_20898;
v_20899:
    goto v_20895;
v_20896:
    goto v_20897;
v_20898:
    fn = elt(env, 5); // polynommultiplybymonom
    v_20973 = (*qfn2(fn))(fn, v_20975, v_20973);
    env = stack[-5];
    stack[-2] = v_20973;
    goto v_20921;
v_20917:
    v_20974 = stack[-4];
    goto v_20918;
v_20919:
    v_20973 = stack[0];
    goto v_20920;
v_20921:
    goto v_20917;
v_20918:
    goto v_20919;
v_20920:
    fn = elt(env, 6); // triplesetprolongedby
    v_20973 = (*qfn2(fn))(fn, v_20974, v_20973);
    env = stack[-5];
    v_20973 = stack[-2];
    v_20973 = qcar(v_20973);
    if (v_20973 == nil) goto v_20927;
    goto v_20935;
v_20931:
    v_20975 = stack[-2];
    goto v_20932;
v_20933:
    goto v_20941;
v_20937:
    v_20974 = stack[-4];
    goto v_20938;
v_20939:
    v_20973 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_20940;
v_20941:
    goto v_20937;
v_20938:
    goto v_20939;
v_20940:
    v_20973 = *(LispObject *)((char *)v_20974 + (CELL-TAG_VECTOR) + (((intptr_t)v_20973-TAG_FIXNUM)/(16/CELL)));
    goto v_20934;
v_20935:
    goto v_20931;
v_20932:
    goto v_20933;
v_20934:
    fn = elt(env, 7); // createtriplewithancestor
    v_20973 = (*qfn2(fn))(fn, v_20975, v_20973);
    env = stack[-5];
    stack[-2] = v_20973;
    goto v_20950;
v_20946:
    v_20975 = stack[-2];
    goto v_20947;
v_20948:
    goto v_20956;
v_20952:
    v_20974 = stack[-4];
    goto v_20953;
v_20954:
    v_20973 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_20955;
v_20956:
    goto v_20952;
v_20953:
    goto v_20954;
v_20955:
    v_20973 = *(LispObject *)((char *)v_20974 + (CELL-TAG_VECTOR) + (((intptr_t)v_20973-TAG_FIXNUM)/(16/CELL)));
    goto v_20949;
v_20950:
    goto v_20946;
v_20947:
    goto v_20948;
v_20949:
    fn = elt(env, 8); // triplesetprolongset
    v_20973 = (*qfn2(fn))(fn, v_20975, v_20973);
    env = stack[-5];
    goto v_20965;
v_20961:
    v_20974 = stack[-3];
    goto v_20962;
v_20963:
    v_20973 = stack[-2];
    goto v_20964;
v_20965:
    goto v_20961;
v_20962:
    goto v_20963;
v_20964:
    fn = elt(env, 9); // sortedtriplelistinsert
    v_20973 = (*qfn2(fn))(fn, v_20974, v_20973);
    env = stack[-5];
    goto v_20925;
v_20927:
v_20925:
    goto v_20883;
v_20885:
v_20883:
    v_20973 = stack[0];
    v_20973 = add1(v_20973);
    env = stack[-5];
    stack[0] = v_20973;
    goto v_20866;
v_20865:
    v_20973 = nil;
    goto v_20838;
v_20840:
    v_20973 = nil;
v_20838:
    return onevalue(v_20973);
}



// Code for valuecoefft

static LispObject CC_valuecoefft(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20882, v_20883, v_20884, v_20885, v_20886;
    LispObject fn;
    LispObject v_20837, v_20836, v_20835;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "valuecoefft");
    va_start(aa, nargs);
    v_20835 = va_arg(aa, LispObject);
    v_20836 = va_arg(aa, LispObject);
    v_20837 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20884 = v_20837;
    v_20885 = v_20836;
    v_20886 = v_20835;
// end of prologue
v_20841:
    v_20882 = v_20884;
    if (v_20882 == nil) goto v_20844;
    else goto v_20845;
v_20844:
    v_20882 = elt(env, 1); // "Valuecoefft - no value"
    {
        fn = elt(env, 2); // interr
        return (*qfn1(fn))(fn, v_20882);
    }
v_20845:
    goto v_20855;
v_20851:
    v_20883 = v_20886;
    goto v_20852;
v_20853:
    v_20882 = v_20884;
    v_20882 = qcar(v_20882);
    goto v_20854;
v_20855:
    goto v_20851;
v_20852:
    goto v_20853;
v_20854:
    if (v_20883 == v_20882) goto v_20849;
    else goto v_20850;
v_20849:
    goto v_20867;
v_20863:
    v_20882 = v_20885;
    v_20883 = qcar(v_20882);
    goto v_20864;
v_20865:
    v_20882 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_20866;
v_20867:
    goto v_20863;
v_20864:
    goto v_20865;
v_20866:
    if (v_20883 == v_20882) goto v_20861;
    else goto v_20862;
v_20861:
    v_20882 = nil;
    goto v_20840;
v_20862:
    v_20882 = v_20885;
    v_20882 = qcar(v_20882);
    goto v_20840;
    goto v_20843;
v_20850:
    v_20882 = v_20885;
    v_20882 = qcdr(v_20882);
    v_20885 = v_20882;
    v_20882 = v_20884;
    v_20882 = qcdr(v_20882);
    v_20884 = v_20882;
    goto v_20841;
v_20843:
    v_20882 = nil;
v_20840:
    return onevalue(v_20882);
}



// Code for rl_convertarg

static LispObject CC_rl_convertarg(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_20855, v_20856;
    LispObject fn;
    LispObject v_20837, v_20836, v_20835;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "rl_convertarg");
    va_start(aa, nargs);
    v_20835 = va_arg(aa, LispObject);
    v_20836 = va_arg(aa, LispObject);
    v_20837 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_20837,v_20836,v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_20835,v_20836,v_20837);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_20855 = v_20837;
    v_20856 = v_20836;
    stack[0] = v_20835;
// end of prologue
    goto v_20844;
v_20840:
    goto v_20850;
v_20846:
    goto v_20847;
v_20848:
    goto v_20849;
v_20850:
    goto v_20846;
v_20847:
    goto v_20848;
v_20849:
    fn = elt(env, 1); // rl_conversionfunction
    stack[-1] = (*qfn2(fn))(fn, v_20856, v_20855);
    env = stack[-2];
    goto v_20841;
v_20842:
    v_20855 = stack[0];
    v_20855 = ncons(v_20855);
    env = stack[-2];
    goto v_20843;
v_20844:
    goto v_20840;
v_20841:
    goto v_20842;
v_20843:
    {
        LispObject v_20859 = stack[-1];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_20859, v_20855);
    }
}



// Code for mri_opn

static LispObject CC_mri_opn(LispObject env,
                         LispObject v_20835)
{
    env = qenv(env);
    LispObject v_20850, v_20851;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_20835);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_20835);
    }
// copy arguments values to proper place
    v_20850 = v_20835;
// end of prologue
    fn = elt(env, 1); // mri_op
    v_20850 = (*qfn1(fn))(fn, v_20850);
    v_20851 = v_20850;
    v_20850 = v_20851;
    if (!consp(v_20850)) goto v_20842;
    else goto v_20843;
v_20842:
    v_20850 = v_20851;
    goto v_20841;
v_20843:
    v_20850 = v_20851;
    v_20850 = qcar(v_20850);
    goto v_20841;
    v_20850 = nil;
v_20841:
    return onevalue(v_20850);
}



setup_type const u36_setup[] =
{
    {"sublap",                  TOO_FEW_2,      CC_sublap,     WRONG_NO_2},
    {"deletez1",                TOO_FEW_2,      CC_deletez1,   WRONG_NO_2},
    {"assert_kernelp",          CC_assert_kernelp,TOO_MANY_1,  WRONG_NO_1},
    {"**a2i",                   TOO_FEW_2,      CC_HHa2i,      WRONG_NO_2},
    {"gvar1",                   TOO_FEW_2,      CC_gvar1,      WRONG_NO_2},
    {"drnconv",                 CC_drnconv,     TOO_MANY_1,    WRONG_NO_1},
    {"split-further",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_splitKfurther},
    {"lex_init",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex_init},
    {"give*position",           TOO_FEW_2,      CC_giveHposition,WRONG_NO_2},
    {"talp_specsub",            TOO_FEW_2,      CC_talp_specsub,WRONG_NO_2},
    {"mconv1",                  CC_mconv1,      TOO_MANY_1,    WRONG_NO_1},
    {"pasf_uprap",              CC_pasf_uprap,  TOO_MANY_1,    WRONG_NO_1},
    {"ciml",                    CC_ciml,        TOO_MANY_1,    WRONG_NO_1},
    {"matrixp",                 CC_matrixp,     TOO_MANY_1,    WRONG_NO_1},
    {"evequal",                 TOO_FEW_2,      CC_evequal,    WRONG_NO_2},
    {"exdff0",                  CC_exdff0,      TOO_MANY_1,    WRONG_NO_1},
    {"gftimes",                 TOO_FEW_2,      CC_gftimes,    WRONG_NO_2},
    {"getphystypeall",          CC_getphystypeall,TOO_MANY_1,  WRONG_NO_1},
    {"groeb=crita",             CC_groebMcrita, TOO_MANY_1,    WRONG_NO_1},
    {"taydegree<",              TOO_FEW_2,      CC_taydegreeR, WRONG_NO_2},
    {"cl_pnf2",                 CC_cl_pnf2,     TOO_MANY_1,    WRONG_NO_1},
    {"vdp_setsugar",            TOO_FEW_2,      CC_vdp_setsugar,WRONG_NO_2},
    {"setrd",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setrd},
    {"collectphysops_reversed", TOO_FEW_2,      CC_collectphysops_reversed,WRONG_NO_2},
    {"evalgreaterp",            TOO_FEW_2,      CC_evalgreaterp,WRONG_NO_2},
    {"subcare",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_subcare},
    {"fs:make-nullangle",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_fsTmakeKnullangle},
    {"ratlessp",                TOO_FEW_2,      CC_ratlessp,   WRONG_NO_2},
    {"giplus:",                 TOO_FEW_2,      CC_giplusT,    WRONG_NO_2},
    {"multivariatep",           TOO_FEW_2,      CC_multivariatep,WRONG_NO_2},
    {"rl_qefsolset",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rl_qefsolset},
    {"sfto_b:extadd",           TOO_FEW_2,      CC_sfto_bTextadd,WRONG_NO_2},
    {"bvarom",                  CC_bvarom,      TOO_MANY_1,    WRONG_NO_1},
    {"degreef",                 TOO_FEW_2,      CC_degreef,    WRONG_NO_2},
    {"r2findindex1",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_r2findindex1},
    {"apply_e",                 CC_apply_e,     TOO_MANY_1,    WRONG_NO_1},
    {"sqprint",                 CC_sqprint,     TOO_MANY_1,    WRONG_NO_1},
    {"reduce-eival-powers",     TOO_FEW_2,      CC_reduceKeivalKpowers,WRONG_NO_2},
    {"make-image",              TOO_FEW_2,      CC_makeKimage, WRONG_NO_2},
    {"freeoflist",              TOO_FEW_2,      CC_freeoflist, WRONG_NO_2},
    {"ofsf_sippsubst1",         TOO_FEW_2,      CC_ofsf_sippsubst1,WRONG_NO_2},
    {"talp_maxd",               CC_talp_maxd,   TOO_MANY_1,    WRONG_NO_1},
    {"ctx_filter",              TOO_FEW_2,      CC_ctx_filter, WRONG_NO_2},
    {"containerom",             CC_containerom, TOO_MANY_1,    WRONG_NO_1},
    {"s-nextarg",               CC_sKnextarg,   TOO_MANY_1,    WRONG_NO_1},
    {"wedgef",                  CC_wedgef,      TOO_MANY_1,    WRONG_NO_1},
    {"gbfplus",                 TOO_FEW_2,      CC_gbfplus,    WRONG_NO_2},
    {"::quotient",              TOO_FEW_2,      CC_TTquotient, WRONG_NO_2},
    {"contr2",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_contr2},
    {"innprodpex",              TOO_FEW_2,      CC_innprodpex, WRONG_NO_2},
    {"listeval0",               CC_listeval0,   TOO_MANY_1,    WRONG_NO_1},
    {"bas_make",                TOO_FEW_2,      CC_bas_make,   WRONG_NO_2},
    {"rootextractf",            CC_rootextractf,TOO_MANY_1,    WRONG_NO_1},
    {"ra_u",                    CC_ra_u,        TOO_MANY_1,    WRONG_NO_1},
    {"lastcar",                 CC_lastcar,     TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_decdeg2",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_decdeg2},
    {"settcollectnonmultiprolongations",CC_settcollectnonmultiprolongations,TOO_MANY_1,WRONG_NO_1},
    {"valuecoefft",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_valuecoefft},
    {"rl_convertarg",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rl_convertarg},
    {"mri_opn",                 CC_mri_opn,     TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u36", (two_args *)"97672 4028610 792751", 0}
};

// end of generated code
