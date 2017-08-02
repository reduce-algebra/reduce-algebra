
// $destdir/u28.c        Machine generated C code

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



// Code for super_der_simp

static LispObject CC_super_der_simp(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15624, v_15625, v_15626;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_15196;
// end of prologue
    goto v_15206;
v_15202:
    v_15624 = stack[-9];
    v_15625 = Llength(nil, v_15624);
    env = stack[-11];
    goto v_15203;
v_15204:
    v_15624 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_15205;
v_15206:
    goto v_15202;
v_15203:
    goto v_15204;
v_15205:
    if (v_15625 == v_15624) goto v_15200;
    else goto v_15201;
v_15200:
    v_15624 = stack[-9];
    v_15624 = qcar(v_15624);
    fn = elt(env, 7); // reval
    v_15624 = (*qfn1(fn))(fn, v_15624);
    env = stack[-11];
    stack[-10] = v_15624;
    goto v_15227;
v_15223:
    v_15625 = stack[-10];
    goto v_15224;
v_15225:
    v_15624 = elt(env, 2); // variables
    goto v_15226;
v_15227:
    goto v_15223;
v_15224:
    goto v_15225;
v_15226:
    v_15624 = get(v_15625, v_15624);
    env = stack[-11];
    stack[-8] = v_15624;
    v_15624 = stack[-9];
    v_15624 = qcdr(v_15624);
    v_15624 = qcar(v_15624);
    fn = elt(env, 8); // simp!*
    v_15624 = (*qfn1(fn))(fn, v_15624);
    env = stack[-11];
    stack[-9] = v_15624;
    goto v_15239;
v_15235:
    v_15624 = stack[-9];
    v_15625 = qcar(v_15624);
    goto v_15236;
v_15237:
    v_15624 = elt(env, 3); // (ext)
    goto v_15238;
v_15239:
    goto v_15235;
v_15236:
    goto v_15237;
v_15238:
    fn = elt(env, 9); // split_form
    v_15624 = (*qfn2(fn))(fn, v_15625, v_15624);
    env = stack[-11];
    stack[-7] = v_15624;
    goto v_15250;
v_15244:
    v_15624 = elt(env, 4); // ext
    v_15626 = ncons(v_15624);
    env = stack[-11];
    goto v_15245;
v_15246:
    v_15624 = stack[-7];
    v_15625 = qcar(v_15624);
    goto v_15247;
v_15248:
    v_15624 = stack[-7];
    v_15624 = qcdr(v_15624);
    goto v_15249;
v_15250:
    goto v_15244;
v_15245:
    goto v_15246;
v_15247:
    goto v_15248;
v_15249:
    v_15624 = acons(v_15626, v_15625, v_15624);
    env = stack[-11];
    stack[-7] = v_15624;
    goto v_15262;
v_15258:
    v_15624 = stack[-9];
    v_15625 = qcdr(v_15624);
    goto v_15259;
v_15260:
    v_15624 = elt(env, 3); // (ext)
    goto v_15261;
v_15262:
    goto v_15258;
v_15259:
    goto v_15260;
v_15261:
    fn = elt(env, 9); // split_form
    v_15624 = (*qfn2(fn))(fn, v_15625, v_15624);
    env = stack[-11];
    stack[-6] = v_15624;
    goto v_15273;
v_15267:
    v_15624 = elt(env, 4); // ext
    v_15626 = ncons(v_15624);
    env = stack[-11];
    goto v_15268;
v_15269:
    v_15624 = stack[-6];
    v_15625 = qcar(v_15624);
    goto v_15270;
v_15271:
    v_15624 = stack[-6];
    v_15624 = qcdr(v_15624);
    goto v_15272;
v_15273:
    goto v_15267;
v_15268:
    goto v_15269;
v_15270:
    goto v_15271;
v_15272:
    v_15624 = acons(v_15626, v_15625, v_15624);
    env = stack[-11];
    stack[-6] = v_15624;
    v_15624 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_15624;
    goto v_15297;
v_15293:
    goto v_15303;
v_15299:
    v_15625 = stack[-10];
    goto v_15300;
v_15301:
    v_15624 = elt(env, 5); // even_dimension
    goto v_15302;
v_15303:
    goto v_15299;
v_15300:
    goto v_15301;
v_15302:
    v_15625 = get(v_15625, v_15624);
    env = stack[-11];
    goto v_15294;
v_15295:
    v_15624 = stack[-5];
    goto v_15296;
v_15297:
    goto v_15293;
v_15294:
    goto v_15295;
v_15296:
    v_15624 = difference2(v_15625, v_15624);
    env = stack[-11];
    v_15624 = Lminusp(nil, v_15624);
    env = stack[-11];
    if (v_15624 == nil) goto v_15290;
    v_15624 = nil;
    goto v_15284;
v_15290:
    goto v_15317;
v_15311:
    v_15626 = stack[-10];
    goto v_15312;
v_15313:
    v_15625 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15314;
v_15315:
    v_15624 = stack[-5];
    goto v_15316;
v_15317:
    goto v_15311;
v_15312:
    goto v_15313;
v_15314:
    goto v_15315;
v_15316:
    v_15624 = list3(v_15626, v_15625, v_15624);
    env = stack[-11];
    fn = elt(env, 8); // simp!*
    v_15624 = (*qfn1(fn))(fn, v_15624);
    env = stack[-11];
    stack[-1] = v_15624;
    goto v_15327;
v_15323:
    goto v_15333;
v_15329:
    v_15625 = stack[-8];
    goto v_15330;
v_15331:
    v_15624 = stack[-5];
    goto v_15332;
v_15333:
    goto v_15329;
v_15330:
    goto v_15331;
v_15332:
    fn = elt(env, 10); // nth
    stack[0] = (*qfn2(fn))(fn, v_15625, v_15624);
    env = stack[-11];
    goto v_15324;
v_15325:
    goto v_15341;
v_15337:
    v_15625 = stack[-1];
    goto v_15338;
v_15339:
    v_15624 = elt(env, 3); // (ext)
    goto v_15340;
v_15341:
    goto v_15337;
v_15338:
    goto v_15339;
v_15340:
    fn = elt(env, 11); // split_ext
    v_15624 = (*qfn2(fn))(fn, v_15625, v_15624);
    env = stack[-11];
    goto v_15326;
v_15327:
    goto v_15323;
v_15324:
    goto v_15325;
v_15326:
    v_15624 = cons(stack[0], v_15624);
    env = stack[-11];
    v_15624 = ncons(v_15624);
    env = stack[-11];
    stack[-3] = v_15624;
    stack[-4] = v_15624;
v_15285:
    v_15624 = stack[-5];
    v_15624 = add1(v_15624);
    env = stack[-11];
    stack[-5] = v_15624;
    goto v_15356;
v_15352:
    goto v_15362;
v_15358:
    v_15625 = stack[-10];
    goto v_15359;
v_15360:
    v_15624 = elt(env, 5); // even_dimension
    goto v_15361;
v_15362:
    goto v_15358;
v_15359:
    goto v_15360;
v_15361:
    v_15625 = get(v_15625, v_15624);
    env = stack[-11];
    goto v_15353;
v_15354:
    v_15624 = stack[-5];
    goto v_15355;
v_15356:
    goto v_15352;
v_15353:
    goto v_15354;
v_15355:
    v_15624 = difference2(v_15625, v_15624);
    env = stack[-11];
    v_15624 = Lminusp(nil, v_15624);
    env = stack[-11];
    if (v_15624 == nil) goto v_15349;
    v_15624 = stack[-4];
    goto v_15284;
v_15349:
    goto v_15372;
v_15368:
    stack[-2] = stack[-3];
    goto v_15369;
v_15370:
    goto v_15383;
v_15377:
    v_15626 = stack[-10];
    goto v_15378;
v_15379:
    v_15625 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15380;
v_15381:
    v_15624 = stack[-5];
    goto v_15382;
v_15383:
    goto v_15377;
v_15378:
    goto v_15379;
v_15380:
    goto v_15381;
v_15382:
    v_15624 = list3(v_15626, v_15625, v_15624);
    env = stack[-11];
    fn = elt(env, 8); // simp!*
    v_15624 = (*qfn1(fn))(fn, v_15624);
    env = stack[-11];
    stack[-1] = v_15624;
    goto v_15393;
v_15389:
    goto v_15399;
v_15395:
    v_15625 = stack[-8];
    goto v_15396;
v_15397:
    v_15624 = stack[-5];
    goto v_15398;
v_15399:
    goto v_15395;
v_15396:
    goto v_15397;
v_15398:
    fn = elt(env, 10); // nth
    stack[0] = (*qfn2(fn))(fn, v_15625, v_15624);
    env = stack[-11];
    goto v_15390;
v_15391:
    goto v_15407;
v_15403:
    v_15625 = stack[-1];
    goto v_15404;
v_15405:
    v_15624 = elt(env, 3); // (ext)
    goto v_15406;
v_15407:
    goto v_15403;
v_15404:
    goto v_15405;
v_15406:
    fn = elt(env, 11); // split_ext
    v_15624 = (*qfn2(fn))(fn, v_15625, v_15624);
    env = stack[-11];
    goto v_15392;
v_15393:
    goto v_15389;
v_15390:
    goto v_15391;
v_15392:
    v_15624 = cons(stack[0], v_15624);
    env = stack[-11];
    v_15624 = ncons(v_15624);
    env = stack[-11];
    goto v_15371;
v_15372:
    goto v_15368;
v_15369:
    goto v_15370;
v_15371:
    v_15624 = Lrplacd(nil, stack[-2], v_15624);
    env = stack[-11];
    v_15624 = stack[-3];
    v_15624 = qcdr(v_15624);
    stack[-3] = v_15624;
    goto v_15285;
v_15284:
    stack[-5] = v_15624;
    v_15624 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_15624;
    goto v_15429;
v_15425:
    goto v_15435;
v_15431:
    v_15625 = stack[-10];
    goto v_15432;
v_15433:
    v_15624 = elt(env, 6); // odd_dimension
    goto v_15434;
v_15435:
    goto v_15431;
v_15432:
    goto v_15433;
v_15434:
    v_15625 = get(v_15625, v_15624);
    env = stack[-11];
    goto v_15426;
v_15427:
    v_15624 = stack[-4];
    goto v_15428;
v_15429:
    goto v_15425;
v_15426:
    goto v_15427;
v_15428:
    v_15624 = difference2(v_15625, v_15624);
    env = stack[-11];
    v_15624 = Lminusp(nil, v_15624);
    env = stack[-11];
    if (v_15624 == nil) goto v_15422;
    v_15624 = nil;
    goto v_15416;
v_15422:
    goto v_15449;
v_15443:
    v_15626 = stack[-10];
    goto v_15444;
v_15445:
    v_15625 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15446;
v_15447:
    v_15624 = stack[-4];
    goto v_15448;
v_15449:
    goto v_15443;
v_15444:
    goto v_15445;
v_15446:
    goto v_15447;
v_15448:
    v_15624 = list3(v_15626, v_15625, v_15624);
    env = stack[-11];
    fn = elt(env, 8); // simp!*
    v_15624 = (*qfn1(fn))(fn, v_15624);
    env = stack[-11];
    goto v_15459;
v_15455:
    stack[0] = stack[-4];
    goto v_15456;
v_15457:
    goto v_15466;
v_15462:
    v_15625 = v_15624;
    goto v_15463;
v_15464:
    v_15624 = elt(env, 3); // (ext)
    goto v_15465;
v_15466:
    goto v_15462;
v_15463:
    goto v_15464;
v_15465:
    fn = elt(env, 11); // split_ext
    v_15624 = (*qfn2(fn))(fn, v_15625, v_15624);
    env = stack[-11];
    goto v_15458;
v_15459:
    goto v_15455;
v_15456:
    goto v_15457;
v_15458:
    v_15624 = cons(stack[0], v_15624);
    env = stack[-11];
    v_15624 = ncons(v_15624);
    env = stack[-11];
    stack[-2] = v_15624;
    stack[-3] = v_15624;
v_15417:
    v_15624 = stack[-4];
    v_15624 = add1(v_15624);
    env = stack[-11];
    stack[-4] = v_15624;
    goto v_15481;
v_15477:
    goto v_15487;
v_15483:
    v_15625 = stack[-10];
    goto v_15484;
v_15485:
    v_15624 = elt(env, 6); // odd_dimension
    goto v_15486;
v_15487:
    goto v_15483;
v_15484:
    goto v_15485;
v_15486:
    v_15625 = get(v_15625, v_15624);
    env = stack[-11];
    goto v_15478;
v_15479:
    v_15624 = stack[-4];
    goto v_15480;
v_15481:
    goto v_15477;
v_15478:
    goto v_15479;
v_15480:
    v_15624 = difference2(v_15625, v_15624);
    env = stack[-11];
    v_15624 = Lminusp(nil, v_15624);
    env = stack[-11];
    if (v_15624 == nil) goto v_15474;
    v_15624 = stack[-3];
    goto v_15416;
v_15474:
    goto v_15497;
v_15493:
    stack[-1] = stack[-2];
    goto v_15494;
v_15495:
    goto v_15508;
v_15502:
    v_15626 = stack[-10];
    goto v_15503;
v_15504:
    v_15625 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15505;
v_15506:
    v_15624 = stack[-4];
    goto v_15507;
v_15508:
    goto v_15502;
v_15503:
    goto v_15504;
v_15505:
    goto v_15506;
v_15507:
    v_15624 = list3(v_15626, v_15625, v_15624);
    env = stack[-11];
    fn = elt(env, 8); // simp!*
    v_15624 = (*qfn1(fn))(fn, v_15624);
    env = stack[-11];
    goto v_15518;
v_15514:
    stack[0] = stack[-4];
    goto v_15515;
v_15516:
    goto v_15525;
v_15521:
    v_15625 = v_15624;
    goto v_15522;
v_15523:
    v_15624 = elt(env, 3); // (ext)
    goto v_15524;
v_15525:
    goto v_15521;
v_15522:
    goto v_15523;
v_15524:
    fn = elt(env, 11); // split_ext
    v_15624 = (*qfn2(fn))(fn, v_15625, v_15624);
    env = stack[-11];
    goto v_15517;
v_15518:
    goto v_15514;
v_15515:
    goto v_15516;
v_15517:
    v_15624 = cons(stack[0], v_15624);
    env = stack[-11];
    v_15624 = ncons(v_15624);
    env = stack[-11];
    goto v_15496;
v_15497:
    goto v_15493;
v_15494:
    goto v_15495;
v_15496:
    v_15624 = Lrplacd(nil, stack[-1], v_15624);
    env = stack[-11];
    v_15624 = stack[-2];
    v_15624 = qcdr(v_15624);
    stack[-2] = v_15624;
    goto v_15417;
v_15416:
    stack[-1] = v_15624;
    goto v_15535;
v_15531:
    goto v_15541;
v_15537:
    goto v_15547;
v_15543:
    goto v_15553;
v_15549:
    v_15625 = stack[-5];
    goto v_15550;
v_15551:
    v_15624 = stack[-7];
    goto v_15552;
v_15553:
    goto v_15549;
v_15550:
    goto v_15551;
v_15552:
    fn = elt(env, 12); // even_action
    stack[0] = (*qfn2(fn))(fn, v_15625, v_15624);
    env = stack[-11];
    goto v_15544;
v_15545:
    goto v_15561;
v_15557:
    v_15625 = stack[-1];
    goto v_15558;
v_15559:
    v_15624 = stack[-7];
    goto v_15560;
v_15561:
    goto v_15557;
v_15558:
    goto v_15559;
v_15560:
    fn = elt(env, 13); // odd_action
    v_15624 = (*qfn2(fn))(fn, v_15625, v_15624);
    env = stack[-11];
    goto v_15546;
v_15547:
    goto v_15543;
v_15544:
    goto v_15545;
v_15546:
    fn = elt(env, 14); // addsq
    stack[0] = (*qfn2(fn))(fn, stack[0], v_15624);
    env = stack[-11];
    goto v_15538;
v_15539:
    goto v_15569;
v_15565:
    v_15624 = stack[-9];
    v_15625 = qcdr(v_15624);
    goto v_15566;
v_15567:
    v_15624 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15568;
v_15569:
    goto v_15565;
v_15566:
    goto v_15567;
v_15568:
    v_15624 = cons(v_15625, v_15624);
    env = stack[-11];
    goto v_15540;
v_15541:
    goto v_15537;
v_15538:
    goto v_15539;
v_15540:
    fn = elt(env, 15); // quotsq
    stack[0] = (*qfn2(fn))(fn, stack[0], v_15624);
    env = stack[-11];
    goto v_15532;
v_15533:
    goto v_15579;
v_15575:
    goto v_15585;
v_15581:
    goto v_15591;
v_15587:
    v_15625 = stack[-5];
    goto v_15588;
v_15589:
    v_15624 = stack[-6];
    goto v_15590;
v_15591:
    goto v_15587;
v_15588:
    goto v_15589;
v_15590:
    fn = elt(env, 12); // even_action
    stack[-1] = (*qfn2(fn))(fn, v_15625, v_15624);
    env = stack[-11];
    goto v_15582;
v_15583:
    goto v_15599;
v_15595:
    v_15624 = stack[-9];
    v_15625 = qcar(v_15624);
    goto v_15596;
v_15597:
    v_15624 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15598;
v_15599:
    goto v_15595;
v_15596:
    goto v_15597;
v_15598:
    v_15624 = cons(v_15625, v_15624);
    env = stack[-11];
    goto v_15584;
v_15585:
    goto v_15581;
v_15582:
    goto v_15583;
v_15584:
    fn = elt(env, 16); // super_product_sq
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_15624);
    env = stack[-11];
    goto v_15576;
v_15577:
    goto v_15608;
v_15604:
    goto v_15614;
v_15610:
    v_15624 = stack[-9];
    v_15625 = qcdr(v_15624);
    goto v_15611;
v_15612:
    v_15624 = stack[-9];
    v_15624 = qcdr(v_15624);
    goto v_15613;
v_15614:
    goto v_15610;
v_15611:
    goto v_15612;
v_15613:
    fn = elt(env, 17); // multf
    v_15625 = (*qfn2(fn))(fn, v_15625, v_15624);
    env = stack[-11];
    goto v_15605;
v_15606:
    v_15624 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15607;
v_15608:
    goto v_15604;
v_15605:
    goto v_15606;
v_15607:
    v_15624 = cons(v_15625, v_15624);
    env = stack[-11];
    goto v_15578;
v_15579:
    goto v_15575;
v_15576:
    goto v_15577;
v_15578:
    fn = elt(env, 15); // quotsq
    v_15624 = (*qfn2(fn))(fn, stack[-1], v_15624);
    env = stack[-11];
    fn = elt(env, 18); // negsq
    v_15624 = (*qfn1(fn))(fn, v_15624);
    env = stack[-11];
    goto v_15534;
v_15535:
    goto v_15531;
v_15532:
    goto v_15533;
v_15534:
    {
        LispObject v_15638 = stack[0];
        fn = elt(env, 14); // addsq
        return (*qfn2(fn))(fn, v_15638, v_15624);
    }
    goto v_15199;
v_15201:
    v_15624 = stack[-9];
    {
        fn = elt(env, 19); // simpiden
        return (*qfn1(fn))(fn, v_15624);
    }
    v_15624 = nil;
v_15199:
    return onevalue(v_15624);
}



// Code for string!-of!-list

static LispObject CC_stringKofKlist(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15272, v_15273;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_15273 = v_15196;
// end of prologue
    v_15272 = v_15273;
    if (v_15272 == nil) goto v_15200;
    else goto v_15201;
v_15200:
    v_15272 = elt(env, 1); // ""
    goto v_15199;
v_15201:
    v_15272 = v_15273;
    stack[-4] = v_15272;
v_15212:
    v_15272 = stack[-4];
    if (v_15272 == nil) goto v_15217;
    else goto v_15218;
v_15217:
    v_15272 = nil;
    goto v_15211;
v_15218:
    v_15272 = stack[-4];
    v_15272 = qcar(v_15272);
    goto v_15229;
v_15225:
    stack[0] = elt(env, 2); // !;
    goto v_15226;
v_15227:
    v_15272 = Lexplode(nil, v_15272);
    env = stack[-5];
    goto v_15228;
v_15229:
    goto v_15225;
v_15226:
    goto v_15227;
v_15228:
    v_15272 = cons(stack[0], v_15272);
    env = stack[-5];
    stack[-3] = v_15272;
    v_15272 = stack[-3];
    fn = elt(env, 3); // lastpair
    v_15272 = (*qfn1(fn))(fn, v_15272);
    env = stack[-5];
    stack[-2] = v_15272;
    v_15272 = stack[-4];
    v_15272 = qcdr(v_15272);
    stack[-4] = v_15272;
    v_15272 = stack[-2];
    if (!consp(v_15272)) goto v_15239;
    else goto v_15240;
v_15239:
    goto v_15212;
v_15240:
v_15213:
    v_15272 = stack[-4];
    if (v_15272 == nil) goto v_15244;
    else goto v_15245;
v_15244:
    v_15272 = stack[-3];
    goto v_15211;
v_15245:
    goto v_15253;
v_15249:
    stack[-1] = stack[-2];
    goto v_15250;
v_15251:
    v_15272 = stack[-4];
    v_15272 = qcar(v_15272);
    goto v_15263;
v_15259:
    stack[0] = elt(env, 2); // !;
    goto v_15260;
v_15261:
    v_15272 = Lexplode(nil, v_15272);
    env = stack[-5];
    goto v_15262;
v_15263:
    goto v_15259;
v_15260:
    goto v_15261;
v_15262:
    v_15272 = cons(stack[0], v_15272);
    env = stack[-5];
    goto v_15252;
v_15253:
    goto v_15249;
v_15250:
    goto v_15251;
v_15252:
    v_15272 = Lrplacd(nil, stack[-1], v_15272);
    env = stack[-5];
    v_15272 = stack[-2];
    fn = elt(env, 3); // lastpair
    v_15272 = (*qfn1(fn))(fn, v_15272);
    env = stack[-5];
    stack[-2] = v_15272;
    v_15272 = stack[-4];
    v_15272 = qcdr(v_15272);
    stack[-4] = v_15272;
    goto v_15213;
v_15211:
    v_15272 = qcdr(v_15272);
    {
        fn = elt(env, 4); // list2string
        return (*qfn1(fn))(fn, v_15272);
    }
    v_15272 = nil;
v_15199:
    return onevalue(v_15272);
}



// Code for outrefend

static LispObject CC_outrefend(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15498, v_15499, v_15500;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_15196;
// end of prologue
    v_15498 = qvalue(elt(env, 1)); // calls!*
    v_15499 = v_15498;
    v_15498 = v_15499;
    if (v_15498 == nil) goto v_15203;
    goto v_15212;
v_15206:
    stack[-1] = stack[-2];
    goto v_15207;
v_15208:
    stack[0] = elt(env, 2); // calls
    goto v_15209;
v_15210:
    v_15498 = qvalue(elt(env, 3)); // toplv!*
    if (v_15498 == nil) goto v_15218;
    goto v_15225;
v_15221:
    v_15500 = v_15499;
    goto v_15222;
v_15223:
    goto v_15232;
v_15228:
    v_15499 = stack[-2];
    goto v_15229;
v_15230:
    v_15498 = elt(env, 2); // calls
    goto v_15231;
v_15232:
    goto v_15228;
v_15229:
    goto v_15230;
v_15231:
    v_15498 = get(v_15499, v_15498);
    env = stack[-4];
    goto v_15224;
v_15225:
    goto v_15221;
v_15222:
    goto v_15223;
v_15224:
    fn = elt(env, 20); // union
    v_15498 = (*qfn2(fn))(fn, v_15500, v_15498);
    env = stack[-4];
    goto v_15216;
v_15218:
    v_15498 = v_15499;
    goto v_15216;
    v_15498 = nil;
v_15216:
    goto v_15211;
v_15212:
    goto v_15206;
v_15207:
    goto v_15208;
v_15209:
    goto v_15210;
v_15211:
    v_15498 = Lputprop(nil, 3, stack[-1], stack[0], v_15498);
    env = stack[-4];
    goto v_15201;
v_15203:
v_15201:
    v_15498 = qvalue(elt(env, 1)); // calls!*
    stack[-1] = v_15498;
v_15241:
    v_15498 = stack[-1];
    if (v_15498 == nil) goto v_15245;
    else goto v_15246;
v_15245:
    goto v_15240;
v_15246:
    v_15498 = stack[-1];
    v_15498 = qcar(v_15498);
    stack[0] = v_15498;
    goto v_15257;
v_15253:
    v_15498 = stack[0];
    v_15499 = ncons(v_15498);
    env = stack[-4];
    goto v_15254;
v_15255:
    v_15498 = elt(env, 4); // cinthis
    goto v_15256;
v_15257:
    goto v_15253;
v_15254:
    goto v_15255;
v_15256:
    v_15498 = Lremflag(nil, v_15499, v_15498);
    env = stack[-4];
    goto v_15269;
v_15265:
    v_15499 = stack[0];
    goto v_15266;
v_15267:
    v_15498 = stack[-2];
    goto v_15268;
v_15269:
    goto v_15265;
v_15266:
    goto v_15267;
v_15268:
    if (v_15499 == v_15498) goto v_15264;
    goto v_15281;
v_15277:
    v_15499 = stack[0];
    goto v_15278;
v_15279:
    v_15498 = elt(env, 5); // seen
    goto v_15280;
v_15281:
    goto v_15277;
v_15278:
    goto v_15279;
v_15280:
    v_15498 = Lflagp(nil, v_15499, v_15498);
    env = stack[-4];
    if (v_15498 == nil) goto v_15274;
    else goto v_15275;
v_15274:
    goto v_15289;
v_15285:
    v_15498 = stack[0];
    v_15499 = ncons(v_15498);
    env = stack[-4];
    goto v_15286;
v_15287:
    v_15498 = elt(env, 5); // seen
    goto v_15288;
v_15289:
    goto v_15285;
v_15286:
    goto v_15287;
v_15288:
    v_15498 = Lflag(nil, v_15499, v_15498);
    env = stack[-4];
    goto v_15298;
v_15294:
    v_15499 = stack[0];
    goto v_15295;
v_15296:
    v_15498 = qvalue(elt(env, 6)); // seen!*
    goto v_15297;
v_15298:
    goto v_15294;
v_15295:
    goto v_15296;
v_15297:
    v_15498 = cons(v_15499, v_15498);
    env = stack[-4];
    qvalue(elt(env, 6)) = v_15498; // seen!*
    goto v_15273;
v_15275:
v_15273:
    goto v_15308;
v_15302:
    v_15500 = stack[0];
    goto v_15303;
v_15304:
    v_15499 = elt(env, 7); // calledby
    goto v_15305;
v_15306:
    v_15498 = stack[-2];
    goto v_15307;
v_15308:
    goto v_15302;
v_15303:
    goto v_15304;
v_15305:
    goto v_15306;
v_15307:
    fn = elt(env, 21); // traput
    v_15498 = (*qfnn(fn))(fn, 3, v_15500, v_15499, v_15498);
    env = stack[-4];
    goto v_15262;
v_15264:
v_15262:
    v_15498 = stack[-1];
    v_15498 = qcdr(v_15498);
    stack[-1] = v_15498;
    goto v_15241;
v_15240:
    v_15498 = qvalue(elt(env, 8)); // globs!*
    v_15499 = v_15498;
    v_15498 = v_15499;
    if (v_15498 == nil) goto v_15319;
    goto v_15328;
v_15322:
    stack[-1] = stack[-2];
    goto v_15323;
v_15324:
    stack[0] = elt(env, 9); // globs
    goto v_15325;
v_15326:
    v_15498 = qvalue(elt(env, 3)); // toplv!*
    if (v_15498 == nil) goto v_15334;
    goto v_15341;
v_15337:
    v_15500 = v_15499;
    goto v_15338;
v_15339:
    goto v_15348;
v_15344:
    v_15499 = stack[-2];
    goto v_15345;
v_15346:
    v_15498 = elt(env, 9); // globs
    goto v_15347;
v_15348:
    goto v_15344;
v_15345:
    goto v_15346;
v_15347:
    v_15498 = get(v_15499, v_15498);
    env = stack[-4];
    goto v_15340;
v_15341:
    goto v_15337;
v_15338:
    goto v_15339;
v_15340:
    fn = elt(env, 20); // union
    v_15498 = (*qfn2(fn))(fn, v_15500, v_15498);
    env = stack[-4];
    goto v_15332;
v_15334:
    v_15498 = v_15499;
    goto v_15332;
    v_15498 = nil;
v_15332:
    goto v_15327;
v_15328:
    goto v_15322;
v_15323:
    goto v_15324;
v_15325:
    goto v_15326;
v_15327:
    v_15498 = Lputprop(nil, 3, stack[-1], stack[0], v_15498);
    env = stack[-4];
    goto v_15317;
v_15319:
v_15317:
    v_15498 = qvalue(elt(env, 8)); // globs!*
    stack[-3] = v_15498;
v_15357:
    v_15498 = stack[-3];
    if (v_15498 == nil) goto v_15361;
    else goto v_15362;
v_15361:
    v_15498 = nil;
    goto v_15356;
v_15362:
    v_15498 = stack[-3];
    v_15498 = qcar(v_15498);
    stack[-1] = v_15498;
    goto v_15375;
v_15369:
    stack[0] = stack[-1];
    goto v_15370;
v_15371:
    goto v_15386;
v_15382:
    v_15499 = stack[-1];
    goto v_15383;
v_15384:
    v_15498 = elt(env, 10); // dclglb
    goto v_15385;
v_15386:
    goto v_15382;
v_15383:
    goto v_15384;
v_15385:
    v_15498 = Lflagp(nil, v_15499, v_15498);
    env = stack[-4];
    if (v_15498 == nil) goto v_15380;
    v_15498 = elt(env, 11); // usedby
    v_15499 = v_15498;
    goto v_15378;
v_15380:
    goto v_15401;
v_15397:
    v_15499 = stack[-1];
    goto v_15398;
v_15399:
    v_15498 = elt(env, 12); // gseen
    goto v_15400;
v_15401:
    goto v_15397;
v_15398:
    goto v_15399;
v_15400:
    v_15498 = Lflagp(nil, v_15499, v_15498);
    env = stack[-4];
    if (v_15498 == nil) goto v_15394;
    else goto v_15395;
v_15394:
    goto v_15409;
v_15405:
    v_15499 = stack[-1];
    goto v_15406;
v_15407:
    v_15498 = qvalue(elt(env, 13)); // gseen!*
    goto v_15408;
v_15409:
    goto v_15405;
v_15406:
    goto v_15407;
v_15408:
    v_15498 = cons(v_15499, v_15498);
    env = stack[-4];
    qvalue(elt(env, 13)) = v_15498; // gseen!*
    goto v_15417;
v_15413:
    v_15498 = stack[-1];
    v_15499 = ncons(v_15498);
    env = stack[-4];
    goto v_15414;
v_15415:
    v_15498 = elt(env, 12); // gseen
    goto v_15416;
v_15417:
    goto v_15413;
v_15414:
    goto v_15415;
v_15416:
    v_15498 = Lflag(nil, v_15499, v_15498);
    env = stack[-4];
    goto v_15393;
v_15395:
v_15393:
    v_15498 = elt(env, 14); // usedunby
    v_15499 = v_15498;
    goto v_15378;
    v_15499 = nil;
v_15378:
    goto v_15372;
v_15373:
    v_15498 = stack[-2];
    goto v_15374;
v_15375:
    goto v_15369;
v_15370:
    goto v_15371;
v_15372:
    goto v_15373;
v_15374:
    fn = elt(env, 21); // traput
    v_15498 = (*qfnn(fn))(fn, 3, stack[0], v_15499, v_15498);
    env = stack[-4];
    goto v_15428;
v_15424:
    v_15498 = stack[-1];
    v_15499 = ncons(v_15498);
    env = stack[-4];
    goto v_15425;
v_15426:
    v_15498 = elt(env, 15); // glb2rf
    goto v_15427;
v_15428:
    goto v_15424;
v_15425:
    goto v_15426;
v_15427:
    v_15498 = Lremflag(nil, v_15499, v_15498);
    env = stack[-4];
    goto v_15441;
v_15437:
    v_15499 = stack[-1];
    goto v_15438;
v_15439:
    v_15498 = elt(env, 16); // glb2bd
    goto v_15440;
v_15441:
    goto v_15437;
v_15438:
    goto v_15439;
v_15440:
    v_15498 = Lflagp(nil, v_15499, v_15498);
    env = stack[-4];
    if (v_15498 == nil) goto v_15435;
    goto v_15449;
v_15445:
    v_15498 = stack[-1];
    v_15499 = ncons(v_15498);
    env = stack[-4];
    goto v_15446;
v_15447:
    v_15498 = elt(env, 16); // glb2bd
    goto v_15448;
v_15449:
    goto v_15445;
v_15446:
    goto v_15447;
v_15448:
    v_15498 = Lremflag(nil, v_15499, v_15498);
    env = stack[-4];
    goto v_15460;
v_15454:
    v_15500 = stack[-1];
    goto v_15455;
v_15456:
    v_15499 = elt(env, 17); // boundby
    goto v_15457;
v_15458:
    v_15498 = stack[-2];
    goto v_15459;
v_15460:
    goto v_15454;
v_15455:
    goto v_15456;
v_15457:
    goto v_15458;
v_15459:
    fn = elt(env, 21); // traput
    v_15498 = (*qfnn(fn))(fn, 3, v_15500, v_15499, v_15498);
    env = stack[-4];
    goto v_15433;
v_15435:
v_15433:
    goto v_15473;
v_15469:
    v_15499 = stack[-1];
    goto v_15470;
v_15471:
    v_15498 = elt(env, 18); // glb2st
    goto v_15472;
v_15473:
    goto v_15469;
v_15470:
    goto v_15471;
v_15472:
    v_15498 = Lflagp(nil, v_15499, v_15498);
    env = stack[-4];
    if (v_15498 == nil) goto v_15467;
    goto v_15481;
v_15477:
    v_15498 = stack[-1];
    v_15499 = ncons(v_15498);
    env = stack[-4];
    goto v_15478;
v_15479:
    v_15498 = elt(env, 18); // glb2st
    goto v_15480;
v_15481:
    goto v_15477;
v_15478:
    goto v_15479;
v_15480:
    v_15498 = Lremflag(nil, v_15499, v_15498);
    env = stack[-4];
    goto v_15492;
v_15486:
    v_15500 = stack[-1];
    goto v_15487;
v_15488:
    v_15499 = elt(env, 19); // setby
    goto v_15489;
v_15490:
    v_15498 = stack[-2];
    goto v_15491;
v_15492:
    goto v_15486;
v_15487:
    goto v_15488;
v_15489:
    goto v_15490;
v_15491:
    fn = elt(env, 21); // traput
    v_15498 = (*qfnn(fn))(fn, 3, v_15500, v_15499, v_15498);
    env = stack[-4];
    goto v_15465;
v_15467:
v_15465:
    v_15498 = stack[-3];
    v_15498 = qcdr(v_15498);
    stack[-3] = v_15498;
    goto v_15357;
v_15356:
    return onevalue(v_15498);
}



// Code for ofsf_negateat

static LispObject CC_ofsf_negateat(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15228, v_15229, v_15230;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15196;
// end of prologue
    goto v_15203;
v_15199:
    v_15228 = stack[0];
    v_15228 = qcdr(v_15228);
    v_15229 = qcar(v_15228);
    goto v_15200;
v_15201:
    v_15228 = stack[0];
    v_15228 = qcdr(v_15228);
    v_15228 = qcdr(v_15228);
    v_15228 = qcar(v_15228);
    goto v_15202;
v_15203:
    goto v_15199;
v_15200:
    goto v_15201;
v_15202:
    v_15228 = list2(v_15229, v_15228);
    env = stack[-2];
    stack[-1] = v_15228;
    goto v_15219;
v_15213:
    v_15228 = stack[0];
    v_15228 = qcar(v_15228);
    fn = elt(env, 1); // ofsf_lnegrel
    v_15230 = (*qfn1(fn))(fn, v_15228);
    goto v_15214;
v_15215:
    v_15228 = stack[-1];
    v_15229 = qcar(v_15228);
    goto v_15216;
v_15217:
    v_15228 = stack[-1];
    v_15228 = qcdr(v_15228);
    v_15228 = qcar(v_15228);
    goto v_15218;
v_15219:
    goto v_15213;
v_15214:
    goto v_15215;
v_15216:
    goto v_15217;
v_15218:
    return list3(v_15230, v_15229, v_15228);
}



// Code for simpcv

static LispObject CC_simpcv(LispObject env,
                         LispObject v_15196, LispObject v_15197)
{
    env = qenv(env);
    LispObject v_15272, v_15273;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15196,v_15197);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15197;
    stack[-1] = v_15196;
// end of prologue
    goto v_15207;
v_15203:
    v_15272 = stack[-1];
    v_15273 = Llength(nil, v_15272);
    env = stack[-2];
    goto v_15204;
v_15205:
    v_15272 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_15206;
v_15207:
    goto v_15203;
v_15204:
    goto v_15205;
v_15206:
    if (v_15273 == v_15272) goto v_15202;
    goto v_15217;
v_15213:
    v_15273 = elt(env, 1); // "Invalid number of edges in vertex"
    goto v_15214;
v_15215:
    v_15272 = stack[-1];
    goto v_15216;
v_15217:
    goto v_15213;
v_15214:
    goto v_15215;
v_15216:
    v_15272 = list2(v_15273, v_15272);
    env = stack[-2];
    {
        fn = elt(env, 4); // cerror
        return (*qfn1(fn))(fn, v_15272);
    }
v_15202:
    goto v_15230;
v_15226:
    v_15273 = elt(env, 2); // simpcgraph
    goto v_15227;
v_15228:
    v_15272 = qvalue(elt(env, 3)); // mul!*
    goto v_15229;
v_15230:
    goto v_15226;
v_15227:
    goto v_15228;
v_15229:
    v_15272 = Lmemq(nil, v_15273, v_15272);
    if (v_15272 == nil) goto v_15224;
    else goto v_15225;
v_15224:
    goto v_15239;
v_15235:
    v_15273 = qvalue(elt(env, 3)); // mul!*
    goto v_15236;
v_15237:
    v_15272 = elt(env, 2); // simpcgraph
    goto v_15238;
v_15239:
    goto v_15235;
v_15236:
    goto v_15237;
v_15238:
    fn = elt(env, 5); // aconc!*
    v_15272 = (*qfn2(fn))(fn, v_15273, v_15272);
    env = stack[-2];
    qvalue(elt(env, 3)) = v_15272; // mul!*
    goto v_15223;
v_15225:
v_15223:
    goto v_15247;
v_15243:
    goto v_15254;
v_15250:
    goto v_15260;
v_15256:
    goto v_15266;
v_15262:
    v_15273 = stack[0];
    goto v_15263;
v_15264:
    v_15272 = stack[-1];
    goto v_15265;
v_15266:
    goto v_15262;
v_15263:
    goto v_15264;
v_15265:
    v_15273 = cons(v_15273, v_15272);
    env = stack[-2];
    goto v_15257;
v_15258:
    v_15272 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15259;
v_15260:
    goto v_15256;
v_15257:
    goto v_15258;
v_15259:
    fn = elt(env, 6); // to
    v_15273 = (*qfn2(fn))(fn, v_15273, v_15272);
    env = stack[-2];
    goto v_15251;
v_15252:
    v_15272 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15253;
v_15254:
    goto v_15250;
v_15251:
    goto v_15252;
v_15253:
    v_15272 = cons(v_15273, v_15272);
    env = stack[-2];
    v_15273 = ncons(v_15272);
    goto v_15244;
v_15245:
    v_15272 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15246;
v_15247:
    goto v_15243;
v_15244:
    goto v_15245;
v_15246:
    return cons(v_15273, v_15272);
    v_15272 = nil;
    return onevalue(v_15272);
}



// Code for matpri

static LispObject CC_matpri(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15207, v_15208;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15207 = v_15196;
// end of prologue
    goto v_15203;
v_15199:
    v_15208 = qcdr(v_15207);
    goto v_15200;
v_15201:
    v_15207 = nil;
    goto v_15202;
v_15203:
    goto v_15199;
v_15200:
    goto v_15201;
v_15202:
    {
        fn = elt(env, 1); // matpri1
        return (*qfn2(fn))(fn, v_15208, v_15207);
    }
}



// Code for talp_telp

static LispObject CC_talp_telp(LispObject env,
                         LispObject v_15196, LispObject v_15197)
{
    env = qenv(env);
    LispObject v_15251, v_15252;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15196,v_15197);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15197;
    stack[-1] = v_15196;
// end of prologue
    stack[-2] = nil;
    v_15251 = stack[0];
    if (!consp(v_15251)) goto v_15205;
    else goto v_15206;
v_15205:
    goto v_15212;
v_15208:
    v_15252 = stack[-1];
    goto v_15209;
v_15210:
    v_15251 = stack[0];
    goto v_15211;
v_15212:
    goto v_15208;
v_15209:
    goto v_15210;
v_15211:
    v_15251 = (v_15252 == v_15251 ? lisp_true : nil);
    goto v_15201;
v_15206:
    v_15251 = stack[0];
    fn = elt(env, 2); // talp_invp
    v_15251 = (*qfn1(fn))(fn, v_15251);
    env = stack[-3];
    if (v_15251 == nil) goto v_15216;
    else goto v_15217;
v_15216:
    v_15251 = stack[0];
    fn = elt(env, 3); // talp_fargl
    v_15251 = (*qfn1(fn))(fn, v_15251);
    env = stack[-3];
    stack[0] = v_15251;
v_15224:
    v_15251 = stack[-2];
    if (v_15251 == nil) goto v_15231;
    else goto v_15232;
v_15231:
    v_15251 = stack[0];
    goto v_15230;
v_15232:
    v_15251 = nil;
    goto v_15230;
    v_15251 = nil;
v_15230:
    if (v_15251 == nil) goto v_15227;
    else goto v_15228;
v_15227:
    goto v_15223;
v_15228:
    goto v_15244;
v_15240:
    v_15252 = stack[-1];
    goto v_15241;
v_15242:
    v_15251 = stack[0];
    v_15251 = qcar(v_15251);
    goto v_15243;
v_15244:
    goto v_15240;
v_15241:
    goto v_15242;
v_15243:
    v_15251 = CC_talp_telp(elt(env, 0), v_15252, v_15251);
    env = stack[-3];
    stack[-2] = v_15251;
    v_15251 = stack[0];
    v_15251 = qcdr(v_15251);
    stack[0] = v_15251;
    goto v_15224;
v_15223:
    v_15251 = stack[-2];
    goto v_15201;
v_15217:
    v_15251 = nil;
v_15201:
    return onevalue(v_15251);
}



// Code for matrixrowom

static LispObject CC_matrixrowom(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15223;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15196;
// end of prologue
    v_15223 = stack[0];
    if (v_15223 == nil) goto v_15204;
    v_15223 = elt(env, 1); // "<OMA>"
    fn = elt(env, 4); // printout
    v_15223 = (*qfn1(fn))(fn, v_15223);
    env = stack[-1];
    v_15223 = lisp_true;
    fn = elt(env, 5); // indent!*
    v_15223 = (*qfn1(fn))(fn, v_15223);
    env = stack[-1];
    v_15223 = elt(env, 2); // "<OMS cd=""linalg1"" name=""matrixrow""/>"
    fn = elt(env, 4); // printout
    v_15223 = (*qfn1(fn))(fn, v_15223);
    env = stack[-1];
    v_15223 = stack[0];
    v_15223 = qcar(v_15223);
    fn = elt(env, 6); // multiom
    v_15223 = (*qfn1(fn))(fn, v_15223);
    env = stack[-1];
    v_15223 = nil;
    fn = elt(env, 5); // indent!*
    v_15223 = (*qfn1(fn))(fn, v_15223);
    env = stack[-1];
    v_15223 = elt(env, 3); // "</OMA>"
    fn = elt(env, 4); // printout
    v_15223 = (*qfn1(fn))(fn, v_15223);
    env = stack[-1];
    v_15223 = stack[0];
    v_15223 = qcdr(v_15223);
    v_15223 = CC_matrixrowom(elt(env, 0), v_15223);
    goto v_15202;
v_15204:
v_15202:
    v_15223 = nil;
    return onevalue(v_15223);
}



// Code for oprinla

static LispObject CC_oprinla(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15240, v_15241, v_15242;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15241 = v_15196;
// end of prologue
    goto v_15211;
v_15207:
    v_15242 = v_15241;
    goto v_15208;
v_15209:
    v_15240 = elt(env, 2); // lapr
    goto v_15210;
v_15211:
    goto v_15207;
v_15208:
    goto v_15209;
v_15210:
    v_15240 = get(v_15242, v_15240);
    env = stack[0];
    v_15242 = v_15240;
    if (v_15240 == nil) goto v_15205;
    v_15240 = v_15242;
    fn = elt(env, 5); // prin2la
    v_15240 = (*qfn1(fn))(fn, v_15240);
    goto v_15203;
v_15205:
    v_15240 = v_15241;
    if (!symbolp(v_15240)) v_15240 = nil;
    else { v_15240 = qfastgets(v_15240);
           if (v_15240 != nil) { v_15240 = elt(v_15240, 37); // prtch
#ifdef RECORD_GET
             if (v_15240 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v_15240 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v_15240 == SPID_NOPROP) v_15240 = nil; }}
#endif
    v_15242 = v_15240;
    if (v_15240 == nil) goto v_15217;
    v_15240 = v_15242;
    fn = elt(env, 5); // prin2la
    v_15240 = (*qfn1(fn))(fn, v_15240);
    goto v_15203;
v_15217:
    goto v_15229;
v_15225:
    v_15242 = v_15241;
    goto v_15226;
v_15227:
    v_15240 = elt(env, 3); // lapop
    goto v_15228;
v_15229:
    goto v_15225;
v_15226:
    goto v_15227;
v_15228:
    v_15240 = get(v_15242, v_15240);
    env = stack[0];
    v_15242 = v_15240;
    if (v_15240 == nil) goto v_15223;
    v_15240 = v_15242;
    fn = elt(env, 5); // prin2la
    v_15240 = (*qfn1(fn))(fn, v_15240);
    env = stack[0];
    v_15240 = elt(env, 4); // ! 
    fn = elt(env, 5); // prin2la
    v_15240 = (*qfn1(fn))(fn, v_15240);
    goto v_15203;
v_15223:
    v_15240 = v_15241;
    fn = elt(env, 6); // prinlatom
    v_15240 = (*qfn1(fn))(fn, v_15240);
    goto v_15203;
v_15203:
    v_15240 = nil;
    return onevalue(v_15240);
}



// Code for can_be_proved

static LispObject CC_can_be_proved(LispObject env,
                         LispObject v_15196, LispObject v_15197)
{
    env = qenv(env);
    LispObject v_15224, v_15225;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15196,v_15197);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15197;
    stack[-1] = v_15196;
// end of prologue
v_15201:
    v_15224 = stack[-1];
    if (v_15224 == nil) goto v_15204;
    else goto v_15205;
v_15204:
    v_15224 = lisp_true;
    goto v_15200;
v_15205:
    goto v_15215;
v_15211:
    v_15224 = stack[-1];
    v_15225 = qcar(v_15224);
    goto v_15212;
v_15213:
    v_15224 = stack[0];
    goto v_15214;
v_15215:
    goto v_15211;
v_15212:
    goto v_15213;
v_15214:
    fn = elt(env, 1); // can_be_p
    v_15224 = (*qfn2(fn))(fn, v_15225, v_15224);
    env = stack[-2];
    if (v_15224 == nil) goto v_15209;
    v_15224 = stack[-1];
    v_15224 = qcdr(v_15224);
    stack[-1] = v_15224;
    goto v_15201;
v_15209:
    v_15224 = nil;
    goto v_15200;
    v_15224 = nil;
v_15200:
    return onevalue(v_15224);
}



// Code for red!=subst1

static LispObject CC_redMsubst1(LispObject env,
                         LispObject v_15196, LispObject v_15197)
{
    env = qenv(env);
    LispObject v_15387, v_15388, v_15389;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15196,v_15197);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_15197;
    stack[-6] = v_15196;
// end of prologue
    v_15387 = stack[-6];
    fn = elt(env, 6); // bas_dpoly
    v_15387 = (*qfn1(fn))(fn, v_15387);
    env = stack[-8];
    stack[0] = v_15387;
    v_15387 = stack[0];
    fn = elt(env, 7); // dp_lc
    v_15387 = (*qfn1(fn))(fn, v_15387);
    env = stack[-8];
    stack[-1] = v_15387;
    v_15387 = stack[-6];
    fn = elt(env, 8); // bas_rep
    v_15387 = (*qfn1(fn))(fn, v_15387);
    env = stack[-8];
    stack[-7] = v_15387;
    v_15387 = stack[-5];
    fn = elt(env, 6); // bas_dpoly
    v_15387 = (*qfn1(fn))(fn, v_15387);
    env = stack[-8];
    stack[-3] = v_15387;
    v_15387 = stack[-3];
    fn = elt(env, 7); // dp_lc
    v_15387 = (*qfn1(fn))(fn, v_15387);
    env = stack[-8];
    stack[-2] = v_15387;
    v_15387 = qvalue(elt(env, 2)); // !*bcsimp
    if (v_15387 == nil) goto v_15224;
    v_15387 = stack[-2];
    fn = elt(env, 9); // cali_bc_inv
    v_15387 = (*qfn1(fn))(fn, v_15387);
    env = stack[-8];
    stack[-4] = v_15387;
    if (v_15387 == nil) goto v_15229;
    goto v_15237;
v_15233:
    v_15388 = stack[-1];
    goto v_15234;
v_15235:
    v_15387 = stack[-4];
    goto v_15236;
v_15237:
    goto v_15233;
v_15234:
    goto v_15235;
v_15236:
    fn = elt(env, 10); // cali_bc_prod
    v_15387 = (*qfn2(fn))(fn, v_15388, v_15387);
    env = stack[-8];
    stack[-1] = v_15387;
    v_15387 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 11); // cali_bc_fi
    v_15387 = (*qfn1(fn))(fn, v_15387);
    env = stack[-8];
    stack[-2] = v_15387;
    goto v_15227;
v_15229:
    goto v_15249;
v_15245:
    v_15388 = stack[-2];
    goto v_15246;
v_15247:
    v_15387 = stack[-1];
    goto v_15248;
v_15249:
    goto v_15245;
v_15246:
    goto v_15247;
v_15248:
    fn = elt(env, 12); // cali_bc_gcd
    v_15387 = (*qfn2(fn))(fn, v_15388, v_15387);
    env = stack[-8];
    stack[-4] = v_15387;
    goto v_15257;
v_15253:
    v_15388 = stack[-2];
    goto v_15254;
v_15255:
    v_15387 = stack[-4];
    goto v_15256;
v_15257:
    goto v_15253;
v_15254:
    goto v_15255;
v_15256:
    fn = elt(env, 13); // cali_bc_divmod
    v_15387 = (*qfn2(fn))(fn, v_15388, v_15387);
    env = stack[-8];
    v_15387 = qcar(v_15387);
    stack[-2] = v_15387;
    goto v_15266;
v_15262:
    v_15388 = stack[-1];
    goto v_15263;
v_15264:
    v_15387 = stack[-4];
    goto v_15265;
v_15266:
    goto v_15262;
v_15263:
    goto v_15264;
v_15265:
    fn = elt(env, 13); // cali_bc_divmod
    v_15387 = (*qfn2(fn))(fn, v_15388, v_15387);
    env = stack[-8];
    v_15387 = qcar(v_15387);
    stack[-1] = v_15387;
    goto v_15227;
v_15227:
    goto v_15222;
v_15224:
v_15222:
    goto v_15275;
v_15271:
    v_15387 = stack[0];
    fn = elt(env, 14); // dp_lmon
    stack[-4] = (*qfn1(fn))(fn, v_15387);
    env = stack[-8];
    goto v_15272;
v_15273:
    v_15387 = stack[-3];
    fn = elt(env, 14); // dp_lmon
    v_15387 = (*qfn1(fn))(fn, v_15387);
    env = stack[-8];
    goto v_15274;
v_15275:
    goto v_15271;
v_15272:
    goto v_15273;
v_15274:
    fn = elt(env, 15); // mo_diff
    v_15387 = (*qfn2(fn))(fn, stack[-4], v_15387);
    env = stack[-8];
    stack[-4] = v_15387;
    goto v_15285;
v_15281:
    goto v_15291;
v_15287:
    v_15388 = stack[-2];
    goto v_15288;
v_15289:
    v_15387 = stack[0];
    goto v_15290;
v_15291:
    goto v_15287;
v_15288:
    goto v_15289;
v_15290:
    fn = elt(env, 16); // dp_times_bc
    stack[0] = (*qfn2(fn))(fn, v_15388, v_15387);
    env = stack[-8];
    goto v_15282;
v_15283:
    goto v_15301;
v_15295:
    v_15389 = stack[-1];
    goto v_15296;
v_15297:
    v_15388 = stack[-4];
    goto v_15298;
v_15299:
    v_15387 = stack[-3];
    goto v_15300;
v_15301:
    goto v_15295;
v_15296:
    goto v_15297;
v_15298:
    goto v_15299;
v_15300:
    fn = elt(env, 17); // dp_times_bcmo
    v_15387 = (*qfnn(fn))(fn, 3, v_15389, v_15388, v_15387);
    env = stack[-8];
    goto v_15284;
v_15285:
    goto v_15281;
v_15282:
    goto v_15283;
v_15284:
    fn = elt(env, 18); // dp_diff
    v_15387 = (*qfn2(fn))(fn, stack[0], v_15387);
    env = stack[-8];
    stack[0] = v_15387;
    goto v_15310;
v_15306:
    goto v_15316;
v_15312:
    v_15388 = stack[-2];
    goto v_15313;
v_15314:
    v_15387 = stack[-7];
    goto v_15315;
v_15316:
    goto v_15312;
v_15313:
    goto v_15314;
v_15315:
    fn = elt(env, 16); // dp_times_bc
    stack[-2] = (*qfn2(fn))(fn, v_15388, v_15387);
    env = stack[-8];
    goto v_15307;
v_15308:
    goto v_15326;
v_15320:
    goto v_15321;
v_15322:
    goto v_15323;
v_15324:
    v_15387 = stack[-5];
    fn = elt(env, 8); // bas_rep
    v_15387 = (*qfn1(fn))(fn, v_15387);
    env = stack[-8];
    goto v_15325;
v_15326:
    goto v_15320;
v_15321:
    goto v_15322;
v_15323:
    goto v_15324;
v_15325:
    fn = elt(env, 17); // dp_times_bcmo
    v_15387 = (*qfnn(fn))(fn, 3, stack[-1], stack[-4], v_15387);
    env = stack[-8];
    goto v_15309;
v_15310:
    goto v_15306;
v_15307:
    goto v_15308;
v_15309:
    fn = elt(env, 18); // dp_diff
    v_15387 = (*qfn2(fn))(fn, stack[-2], v_15387);
    env = stack[-8];
    stack[-1] = v_15387;
    goto v_15340;
v_15336:
    fn = elt(env, 19); // cali_trace
    v_15388 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_15337;
v_15338:
    v_15387 = (LispObject)1264+TAG_FIXNUM; // 79
    goto v_15339;
v_15340:
    goto v_15336;
v_15337:
    goto v_15338;
v_15339:
    v_15387 = (LispObject)greaterp2(v_15388, v_15387);
    v_15387 = v_15387 ? lisp_true : nil;
    env = stack[-8];
    if (v_15387 == nil) goto v_15334;
    v_15387 = elt(env, 3); // "---> "
    v_15387 = Lprinc(nil, v_15387);
    env = stack[-8];
    v_15387 = stack[0];
    fn = elt(env, 20); // dp_print
    v_15387 = (*qfn1(fn))(fn, v_15387);
    env = stack[-8];
    goto v_15332;
v_15334:
    goto v_15354;
v_15350:
    fn = elt(env, 19); // cali_trace
    v_15388 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_15351;
v_15352:
    v_15387 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15353;
v_15354:
    goto v_15350;
v_15351:
    goto v_15352;
v_15353:
    v_15387 = (LispObject)greaterp2(v_15388, v_15387);
    v_15387 = v_15387 ? lisp_true : nil;
    env = stack[-8];
    if (v_15387 == nil) goto v_15348;
    v_15387 = elt(env, 4); // "."
    v_15387 = Lprinc(nil, v_15387);
    env = stack[-8];
    goto v_15332;
v_15348:
v_15332:
    goto v_15368;
v_15364:
    fn = elt(env, 19); // cali_trace
    v_15388 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_15365;
v_15366:
    v_15387 = (LispObject)1424+TAG_FIXNUM; // 89
    goto v_15367;
v_15368:
    goto v_15364;
v_15365:
    goto v_15366;
v_15367:
    v_15387 = (LispObject)greaterp2(v_15388, v_15387);
    v_15387 = v_15387 ? lisp_true : nil;
    env = stack[-8];
    if (v_15387 == nil) goto v_15362;
    v_15387 = elt(env, 5); // " uses "
    v_15387 = Lprinc(nil, v_15387);
    env = stack[-8];
    v_15387 = stack[-3];
    fn = elt(env, 20); // dp_print
    v_15387 = (*qfn1(fn))(fn, v_15387);
    env = stack[-8];
    goto v_15360;
v_15362:
v_15360:
    goto v_15382;
v_15376:
    v_15387 = stack[-6];
    fn = elt(env, 21); // bas_nr
    v_15389 = (*qfn1(fn))(fn, v_15387);
    env = stack[-8];
    goto v_15377;
v_15378:
    v_15388 = stack[0];
    goto v_15379;
v_15380:
    v_15387 = stack[-1];
    goto v_15381;
v_15382:
    goto v_15376;
v_15377:
    goto v_15378;
v_15379:
    goto v_15380;
v_15381:
    {
        fn = elt(env, 22); // bas_make1
        return (*qfnn(fn))(fn, 3, v_15389, v_15388, v_15387);
    }
    return onevalue(v_15387);
}



// Code for evaluate!-mod!-p

static LispObject CC_evaluateKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15319, v_15320, v_15321, v_15322, v_15323;
    LispObject fn;
    LispObject v_15198, v_15197, v_15196;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "evaluate-mod-p");
    va_start(aa, nargs);
    v_15196 = va_arg(aa, LispObject);
    v_15197 = va_arg(aa, LispObject);
    v_15198 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15198,v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15196,v_15197,v_15198);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15198;
    stack[-1] = v_15197;
    stack[-2] = v_15196;
// end of prologue
v_15202:
    v_15319 = stack[-2];
    if (!consp(v_15319)) goto v_15209;
    else goto v_15210;
v_15209:
    v_15319 = lisp_true;
    goto v_15208;
v_15210:
    v_15319 = stack[-2];
    v_15319 = qcar(v_15319);
    v_15319 = (consp(v_15319) ? nil : lisp_true);
    goto v_15208;
    v_15319 = nil;
v_15208:
    if (v_15319 == nil) goto v_15206;
    v_15319 = stack[-2];
    goto v_15201;
v_15206:
    goto v_15225;
v_15221:
    v_15320 = stack[0];
    goto v_15222;
v_15223:
    v_15319 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15224;
v_15225:
    goto v_15221;
v_15222:
    goto v_15223;
v_15224:
    if (v_15320 == v_15319) goto v_15219;
    else goto v_15220;
v_15219:
    v_15319 = nil;
    stack[0] = v_15319;
    goto v_15202;
v_15220:
    v_15319 = stack[-1];
    if (v_15319 == nil) goto v_15229;
    else goto v_15230;
v_15229:
    v_15319 = elt(env, 1); // "Variable=NIL in evaluate-mod-p"
    {
        fn = elt(env, 2); // errorf
        return (*qfn1(fn))(fn, v_15319);
    }
v_15230:
    goto v_15240;
v_15236:
    v_15319 = stack[-2];
    v_15319 = qcar(v_15319);
    v_15319 = qcar(v_15319);
    v_15320 = qcar(v_15319);
    goto v_15237;
v_15238:
    v_15319 = stack[-1];
    goto v_15239;
v_15240:
    goto v_15236;
v_15237:
    goto v_15238;
v_15239:
    if (equal(v_15320, v_15319)) goto v_15234;
    else goto v_15235;
v_15234:
    goto v_15257;
v_15247:
    v_15319 = stack[-2];
    v_15319 = qcar(v_15319);
    v_15323 = qcdr(v_15319);
    goto v_15248;
v_15249:
    v_15319 = stack[-2];
    v_15319 = qcar(v_15319);
    v_15319 = qcar(v_15319);
    v_15322 = qcdr(v_15319);
    goto v_15250;
v_15251:
    v_15319 = stack[-2];
    v_15321 = qcdr(v_15319);
    goto v_15252;
v_15253:
    v_15320 = stack[0];
    goto v_15254;
v_15255:
    v_15319 = stack[-1];
    goto v_15256;
v_15257:
    goto v_15247;
v_15248:
    goto v_15249;
v_15250:
    goto v_15251;
v_15252:
    goto v_15253;
v_15254:
    goto v_15255;
v_15256:
    {
        fn = elt(env, 3); // horner!-rule!-mod!-p
        return (*qfnn(fn))(fn, 5, v_15323, v_15322, v_15321, v_15320, v_15319);
    }
v_15235:
    goto v_15278;
v_15272:
    v_15319 = stack[-2];
    v_15319 = qcar(v_15319);
    v_15321 = qcdr(v_15319);
    goto v_15273;
v_15274:
    v_15320 = stack[-1];
    goto v_15275;
v_15276:
    v_15319 = stack[0];
    goto v_15277;
v_15278:
    goto v_15272;
v_15273:
    goto v_15274;
v_15275:
    goto v_15276;
v_15277:
    stack[-3] = CC_evaluateKmodKp(elt(env, 0), 3, v_15321, v_15320, v_15319);
    env = stack[-4];
    goto v_15291;
v_15285:
    v_15319 = stack[-2];
    v_15321 = qcdr(v_15319);
    goto v_15286;
v_15287:
    v_15320 = stack[-1];
    goto v_15288;
v_15289:
    v_15319 = stack[0];
    goto v_15290;
v_15291:
    goto v_15285;
v_15286:
    goto v_15287;
v_15288:
    goto v_15289;
v_15290:
    v_15319 = CC_evaluateKmodKp(elt(env, 0), 3, v_15321, v_15320, v_15319);
    v_15320 = stack[-3];
    v_15321 = v_15320;
    if (v_15321 == nil) goto v_15300;
    else goto v_15301;
v_15300:
    goto v_15299;
v_15301:
    goto v_15313;
v_15307:
    v_15321 = stack[-2];
    v_15321 = qcar(v_15321);
    v_15321 = qcar(v_15321);
    goto v_15308;
v_15309:
    goto v_15310;
v_15311:
    goto v_15312;
v_15313:
    goto v_15307;
v_15308:
    goto v_15309;
v_15310:
    goto v_15311;
v_15312:
    return acons(v_15321, v_15320, v_15319);
    v_15319 = nil;
v_15299:
    goto v_15201;
    v_15319 = nil;
v_15201:
    return onevalue(v_15319);
}



// Code for gf2cr!:

static LispObject CC_gf2crT(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15213;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_15196;
// end of prologue
    goto v_15205;
v_15199:
    stack[-2] = elt(env, 1); // !:cr!:
    goto v_15200;
v_15201:
    v_15213 = stack[-1];
    v_15213 = qcar(v_15213);
    fn = elt(env, 2); // striptag
    stack[0] = (*qfn1(fn))(fn, v_15213);
    env = stack[-3];
    goto v_15202;
v_15203:
    v_15213 = stack[-1];
    v_15213 = qcdr(v_15213);
    fn = elt(env, 2); // striptag
    v_15213 = (*qfn1(fn))(fn, v_15213);
    goto v_15204;
v_15205:
    goto v_15199;
v_15200:
    goto v_15201;
v_15202:
    goto v_15203;
v_15204:
    {
        LispObject v_15217 = stack[-2];
        LispObject v_15218 = stack[0];
        return list2star(v_15217, v_15218, v_15213);
    }
}



// Code for lalr_make_compressed_goto_column

static LispObject CC_lalr_make_compressed_goto_column(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15319, v_15320, v_15321;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_15319 = v_15196;
// end of prologue
    stack[-4] = nil;
    goto v_15215;
v_15211:
    v_15320 = v_15319;
    goto v_15212;
v_15213:
    v_15319 = qvalue(elt(env, 2)); // goto_table
    goto v_15214;
v_15215:
    goto v_15211;
v_15212:
    goto v_15213;
v_15214:
    fn = elt(env, 3); // gethash
    v_15319 = (*qfn2(fn))(fn, v_15320, v_15319);
    env = stack[-5];
    stack[-3] = v_15319;
    v_15319 = stack[-3];
    if (v_15319 == nil) goto v_15220;
    else goto v_15221;
v_15220:
    v_15319 = nil;
    goto v_15208;
v_15221:
    v_15319 = stack[-3];
    v_15319 = qcar(v_15319);
    goto v_15233;
v_15229:
    v_15320 = v_15319;
    v_15320 = qcar(v_15320);
    v_15320 = qcdr(v_15320);
    goto v_15230;
v_15231:
    v_15319 = qcdr(v_15319);
    v_15319 = qcdr(v_15319);
    goto v_15232;
v_15233:
    goto v_15229;
v_15230:
    goto v_15231;
v_15232:
    v_15319 = cons(v_15320, v_15319);
    env = stack[-5];
    v_15319 = ncons(v_15319);
    env = stack[-5];
    stack[-1] = v_15319;
    stack[-2] = v_15319;
v_15209:
    v_15319 = stack[-3];
    v_15319 = qcdr(v_15319);
    stack[-3] = v_15319;
    v_15319 = stack[-3];
    if (v_15319 == nil) goto v_15244;
    else goto v_15245;
v_15244:
    v_15319 = stack[-2];
    goto v_15208;
v_15245:
    goto v_15253;
v_15249:
    stack[0] = stack[-1];
    goto v_15250;
v_15251:
    v_15319 = stack[-3];
    v_15319 = qcar(v_15319);
    goto v_15264;
v_15260:
    v_15320 = v_15319;
    v_15320 = qcar(v_15320);
    v_15320 = qcdr(v_15320);
    goto v_15261;
v_15262:
    v_15319 = qcdr(v_15319);
    v_15319 = qcdr(v_15319);
    goto v_15263;
v_15264:
    goto v_15260;
v_15261:
    goto v_15262;
v_15263:
    v_15319 = cons(v_15320, v_15319);
    env = stack[-5];
    v_15319 = ncons(v_15319);
    env = stack[-5];
    goto v_15252;
v_15253:
    goto v_15249;
v_15250:
    goto v_15251;
v_15252:
    v_15319 = Lrplacd(nil, stack[0], v_15319);
    env = stack[-5];
    v_15319 = stack[-1];
    v_15319 = qcdr(v_15319);
    stack[-1] = v_15319;
    goto v_15209;
v_15208:
    stack[0] = v_15319;
    v_15319 = stack[0];
    fn = elt(env, 4); // lalr_most_common_dest
    v_15319 = (*qfn1(fn))(fn, v_15319);
    env = stack[-5];
    stack[-1] = v_15319;
    v_15319 = stack[0];
    stack[0] = v_15319;
v_15278:
    v_15319 = stack[0];
    if (v_15319 == nil) goto v_15282;
    else goto v_15283;
v_15282:
    goto v_15277;
v_15283:
    v_15319 = stack[0];
    v_15319 = qcar(v_15319);
    v_15321 = v_15319;
    goto v_15297;
v_15293:
    v_15319 = v_15321;
    v_15320 = qcdr(v_15319);
    goto v_15294;
v_15295:
    v_15319 = stack[-1];
    goto v_15296;
v_15297:
    goto v_15293;
v_15294:
    goto v_15295;
v_15296:
    if (equal(v_15320, v_15319)) goto v_15292;
    goto v_15306;
v_15302:
    v_15320 = v_15321;
    goto v_15303;
v_15304:
    v_15319 = stack[-4];
    goto v_15305;
v_15306:
    goto v_15302;
v_15303:
    goto v_15304;
v_15305:
    v_15319 = cons(v_15320, v_15319);
    env = stack[-5];
    stack[-4] = v_15319;
    goto v_15290;
v_15292:
v_15290:
    v_15319 = stack[0];
    v_15319 = qcdr(v_15319);
    stack[0] = v_15319;
    goto v_15278;
v_15277:
    goto v_15316;
v_15312:
    v_15320 = stack[-4];
    goto v_15313;
v_15314:
    v_15319 = stack[-1];
    goto v_15315;
v_15316:
    goto v_15312;
v_15313:
    goto v_15314;
v_15315:
    return cons(v_15320, v_15319);
    return onevalue(v_15319);
}



// Code for add2locs

static LispObject CC_add2locs(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15340, v_15341;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_15341 = v_15196;
// end of prologue
    v_15340 = qvalue(elt(env, 2)); // !*globals
    if (v_15340 == nil) goto v_15205;
    v_15340 = v_15341;
    stack[-2] = v_15340;
v_15210:
    v_15340 = stack[-2];
    if (v_15340 == nil) goto v_15214;
    else goto v_15215;
v_15214:
    goto v_15209;
v_15215:
    v_15340 = stack[-2];
    v_15340 = qcar(v_15340);
    stack[-1] = v_15340;
    goto v_15225;
v_15221:
    v_15341 = stack[-1];
    goto v_15222;
v_15223:
    v_15340 = qvalue(elt(env, 3)); // locls!*
    goto v_15224;
v_15225:
    goto v_15221;
v_15222:
    goto v_15223;
v_15224:
    v_15340 = Lassoc(nil, v_15341, v_15340);
    stack[-3] = v_15340;
    v_15340 = stack[-3];
    if (v_15340 == nil) goto v_15232;
    goto v_15241;
v_15237:
    v_15341 = stack[-1];
    goto v_15238;
v_15239:
    v_15340 = elt(env, 4); // dclglb
    goto v_15240;
v_15241:
    goto v_15237;
v_15238:
    goto v_15239;
v_15240:
    v_15340 = Lflagp(nil, v_15341, v_15340);
    env = stack[-4];
    if (v_15340 == nil) goto v_15232;
    v_15340 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 12); // qerline
    v_15340 = (*qfn1(fn))(fn, v_15340);
    env = stack[-4];
    v_15340 = elt(env, 5); // "*** Variable "
    v_15340 = Lprinc(nil, v_15340);
    env = stack[-4];
    v_15340 = stack[-1];
    v_15340 = Lprin(nil, v_15340);
    env = stack[-4];
    v_15340 = elt(env, 6); // " nested declaration in "
    v_15340 = Lprinc(nil, v_15340);
    env = stack[-4];
    v_15340 = qvalue(elt(env, 7)); // curfun!*
    fn = elt(env, 13); // princng
    v_15340 = (*qfn1(fn))(fn, v_15340);
    env = stack[-4];
    v_15340 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 14); // newline
    v_15340 = (*qfn1(fn))(fn, v_15340);
    env = stack[-4];
    goto v_15261;
v_15257:
    stack[0] = stack[-3];
    goto v_15258;
v_15259:
    goto v_15268;
v_15264:
    v_15341 = nil;
    goto v_15265;
v_15266:
    v_15340 = stack[-3];
    goto v_15267;
v_15268:
    goto v_15264;
v_15265:
    goto v_15266;
v_15267:
    v_15340 = cons(v_15341, v_15340);
    env = stack[-4];
    goto v_15260;
v_15261:
    goto v_15257;
v_15258:
    goto v_15259;
v_15260:
    v_15340 = Lrplacd(nil, stack[0], v_15340);
    env = stack[-4];
    goto v_15230;
v_15232:
    goto v_15280;
v_15274:
    stack[0] = stack[-1];
    goto v_15275;
v_15276:
    v_15340 = nil;
    v_15341 = ncons(v_15340);
    env = stack[-4];
    goto v_15277;
v_15278:
    v_15340 = qvalue(elt(env, 3)); // locls!*
    goto v_15279;
v_15280:
    goto v_15274;
v_15275:
    goto v_15276;
v_15277:
    goto v_15278;
v_15279:
    v_15340 = acons(stack[0], v_15341, v_15340);
    env = stack[-4];
    qvalue(elt(env, 3)) = v_15340; // locls!*
    goto v_15230;
v_15230:
    goto v_15298;
v_15294:
    v_15341 = stack[-1];
    goto v_15295;
v_15296:
    v_15340 = elt(env, 4); // dclglb
    goto v_15297;
v_15298:
    goto v_15294;
v_15295:
    goto v_15296;
v_15297:
    v_15340 = Lflagp(nil, v_15341, v_15340);
    env = stack[-4];
    if (v_15340 == nil) goto v_15292;
    v_15340 = lisp_true;
    goto v_15290;
v_15292:
    goto v_15309;
v_15305:
    v_15341 = stack[-1];
    goto v_15306;
v_15307:
    v_15340 = elt(env, 8); // glb2rf
    goto v_15308;
v_15309:
    goto v_15305;
v_15306:
    goto v_15307;
v_15308:
    v_15340 = Lflagp(nil, v_15341, v_15340);
    env = stack[-4];
    goto v_15290;
    v_15340 = nil;
v_15290:
    if (v_15340 == nil) goto v_15288;
    v_15340 = stack[-1];
    fn = elt(env, 15); // globind
    v_15340 = (*qfn1(fn))(fn, v_15340);
    env = stack[-4];
    goto v_15286;
v_15288:
v_15286:
    goto v_15323;
v_15319:
    v_15341 = stack[-1];
    goto v_15320;
v_15321:
    v_15340 = elt(env, 9); // seen
    goto v_15322;
v_15323:
    goto v_15319;
v_15320:
    goto v_15321;
v_15322:
    v_15340 = Lflagp(nil, v_15341, v_15340);
    env = stack[-4];
    if (v_15340 == nil) goto v_15317;
    v_15340 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 12); // qerline
    v_15340 = (*qfn1(fn))(fn, v_15340);
    env = stack[-4];
    v_15340 = elt(env, 10); // "*** Function "
    v_15340 = Lprinc(nil, v_15340);
    env = stack[-4];
    v_15340 = stack[-1];
    fn = elt(env, 13); // princng
    v_15340 = (*qfn1(fn))(fn, v_15340);
    env = stack[-4];
    v_15340 = elt(env, 11); // " used as variable in "
    v_15340 = Lprinc(nil, v_15340);
    env = stack[-4];
    v_15340 = qvalue(elt(env, 7)); // curfun!*
    fn = elt(env, 13); // princng
    v_15340 = (*qfn1(fn))(fn, v_15340);
    env = stack[-4];
    v_15340 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 14); // newline
    v_15340 = (*qfn1(fn))(fn, v_15340);
    env = stack[-4];
    goto v_15315;
v_15317:
v_15315:
    v_15340 = stack[-2];
    v_15340 = qcdr(v_15340);
    stack[-2] = v_15340;
    goto v_15210;
v_15209:
    goto v_15203;
v_15205:
v_15203:
    v_15340 = nil;
    return onevalue(v_15340);
}



// Code for opmtchrevop

static LispObject CC_opmtchrevop(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15234, v_15235;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15196;
// end of prologue
    v_15234 = qvalue(elt(env, 1)); // !*val
    if (v_15234 == nil) goto v_15204;
    else goto v_15205;
v_15204:
    v_15234 = lisp_true;
    goto v_15203;
v_15205:
    goto v_15215;
v_15211:
    v_15235 = elt(env, 2); // cons
    goto v_15212;
v_15213:
    v_15234 = stack[0];
    goto v_15214;
v_15215:
    goto v_15211;
v_15212:
    goto v_15213;
v_15214:
    v_15234 = Lsmemq(nil, v_15235, v_15234);
    env = stack[-2];
    goto v_15203;
    v_15234 = nil;
v_15203:
    if (v_15234 == nil) goto v_15201;
    v_15234 = stack[0];
    {
        fn = elt(env, 3); // opmtch
        return (*qfn1(fn))(fn, v_15234);
    }
v_15201:
    goto v_15228;
v_15224:
    v_15234 = stack[0];
    stack[-1] = qcar(v_15234);
    goto v_15225;
v_15226:
    v_15234 = stack[0];
    v_15234 = qcdr(v_15234);
    fn = elt(env, 4); // revlis
    v_15234 = (*qfn1(fn))(fn, v_15234);
    env = stack[-2];
    goto v_15227;
v_15228:
    goto v_15224;
v_15225:
    goto v_15226;
v_15227:
    v_15234 = cons(stack[-1], v_15234);
    env = stack[-2];
    {
        fn = elt(env, 3); // opmtch
        return (*qfn1(fn))(fn, v_15234);
    }
    v_15234 = nil;
    return onevalue(v_15234);
}



// Code for get_char_value

static LispObject CC_get_char_value(LispObject env,
                         LispObject v_15196, LispObject v_15197)
{
    env = qenv(env);
    LispObject v_15265, v_15266;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15196,v_15197);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_15197;
    v_15266 = v_15196;
// end of prologue
    stack[-1] = nil;
    v_15265 = nil;
    stack[-3] = v_15265;
    v_15265 = v_15266;
    v_15265 = qcdr(v_15265);
    stack[0] = v_15265;
v_15210:
    v_15265 = stack[-3];
    if (v_15265 == nil) goto v_15217;
    else goto v_15218;
v_15217:
    goto v_15225;
v_15221:
    v_15265 = stack[0];
    v_15266 = Llength(nil, v_15265);
    env = stack[-4];
    goto v_15222;
v_15223:
    v_15265 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15224;
v_15225:
    goto v_15221;
v_15222:
    goto v_15223;
v_15224:
    v_15265 = (LispObject)greaterp2(v_15266, v_15265);
    v_15265 = v_15265 ? lisp_true : nil;
    env = stack[-4];
    goto v_15216;
v_15218:
    v_15265 = nil;
    goto v_15216;
    v_15265 = nil;
v_15216:
    if (v_15265 == nil) goto v_15213;
    else goto v_15214;
v_15213:
    goto v_15209;
v_15214:
    goto v_15241;
v_15237:
    v_15265 = stack[0];
    v_15265 = qcar(v_15265);
    v_15266 = qcar(v_15265);
    goto v_15238;
v_15239:
    v_15265 = stack[-2];
    goto v_15240;
v_15241:
    goto v_15237;
v_15238:
    goto v_15239;
v_15240:
    if (equal(v_15266, v_15265)) goto v_15235;
    else goto v_15236;
v_15235:
    v_15265 = stack[0];
    v_15265 = qcar(v_15265);
    v_15265 = qcdr(v_15265);
    v_15265 = qcar(v_15265);
    stack[-1] = v_15265;
    v_15265 = lisp_true;
    stack[-3] = v_15265;
    goto v_15234;
v_15236:
v_15234:
    v_15265 = stack[0];
    v_15265 = qcdr(v_15265);
    stack[0] = v_15265;
    goto v_15210;
v_15209:
    v_15265 = stack[-3];
    if (v_15265 == nil) goto v_15258;
    v_15265 = stack[-1];
    goto v_15203;
v_15258:
    v_15265 = elt(env, 2); // "error in get character element"
    fn = elt(env, 3); // rederr
    v_15265 = (*qfn1(fn))(fn, v_15265);
    goto v_15256;
v_15256:
    v_15265 = nil;
v_15203:
    return onevalue(v_15265);
}



// Code for homogp

static LispObject CC_homogp(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15285, v_15286;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15196;
// end of prologue
    v_15285 = stack[0];
    if (!consp(v_15285)) goto v_15208;
    else goto v_15209;
v_15208:
    v_15285 = lisp_true;
    goto v_15207;
v_15209:
    v_15285 = stack[0];
    v_15285 = qcar(v_15285);
    v_15285 = (consp(v_15285) ? nil : lisp_true);
    goto v_15207;
    v_15285 = nil;
v_15207:
    if (v_15285 == nil) goto v_15205;
    v_15285 = lisp_true;
    goto v_15203;
v_15205:
    v_15285 = stack[0];
    v_15285 = qcar(v_15285);
    if (!consp(v_15285)) goto v_15222;
    else goto v_15223;
v_15222:
    v_15285 = lisp_true;
    goto v_15221;
v_15223:
    v_15285 = stack[0];
    v_15285 = qcar(v_15285);
    v_15285 = qcar(v_15285);
    v_15285 = (consp(v_15285) ? nil : lisp_true);
    goto v_15221;
    v_15285 = nil;
v_15221:
    goto v_15203;
    v_15285 = nil;
v_15203:
    if (v_15285 == nil) goto v_15201;
    v_15285 = nil;
    goto v_15199;
v_15201:
    v_15285 = stack[0];
    v_15285 = qcdr(v_15285);
    v_15285 = qcar(v_15285);
    v_15285 = qcdr(v_15285);
    if (v_15285 == nil) goto v_15234;
    else goto v_15235;
v_15234:
    v_15285 = nil;
    goto v_15199;
v_15235:
    v_15285 = stack[0];
    v_15285 = qcdr(v_15285);
    v_15285 = qcar(v_15285);
    fn = elt(env, 1); // lastnondomain
    v_15285 = (*qfn1(fn))(fn, v_15285);
    env = stack[-2];
    v_15285 = qcdr(v_15285);
    v_15286 = v_15285;
    v_15285 = v_15286;
    if (!consp(v_15285)) goto v_15251;
    else goto v_15252;
v_15251:
    v_15285 = lisp_true;
    goto v_15250;
v_15252:
    v_15285 = v_15286;
    v_15285 = qcar(v_15285);
    v_15285 = (consp(v_15285) ? nil : lisp_true);
    goto v_15250;
    v_15285 = nil;
v_15250:
    if (v_15285 == nil) goto v_15242;
    v_15285 = nil;
    goto v_15199;
v_15242:
    goto v_15267;
v_15263:
    v_15285 = stack[0];
    v_15285 = qcdr(v_15285);
    v_15285 = qcar(v_15285);
    v_15285 = qcar(v_15285);
    v_15285 = qcar(v_15285);
    fn = elt(env, 2); // listsum
    stack[-1] = (*qfn1(fn))(fn, v_15285);
    env = stack[-2];
    goto v_15264;
v_15265:
    v_15285 = stack[0];
    v_15285 = qcdr(v_15285);
    v_15285 = qcar(v_15285);
    fn = elt(env, 1); // lastnondomain
    v_15285 = (*qfn1(fn))(fn, v_15285);
    env = stack[-2];
    v_15285 = qcar(v_15285);
    v_15285 = qcar(v_15285);
    fn = elt(env, 2); // listsum
    v_15285 = (*qfn1(fn))(fn, v_15285);
    goto v_15266;
v_15267:
    goto v_15263;
v_15264:
    goto v_15265;
v_15266:
    if (equal(stack[-1], v_15285)) goto v_15261;
    else goto v_15262;
v_15261:
    v_15285 = lisp_true;
    goto v_15199;
v_15262:
    v_15285 = nil;
    goto v_15199;
    v_15285 = nil;
v_15199:
    return onevalue(v_15285);
}



// Code for ofsf_optsubstat

static LispObject CC_ofsf_optsubstat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15256, v_15257;
    LispObject fn;
    LispObject v_15198, v_15197, v_15196;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_optsubstat");
    va_start(aa, nargs);
    v_15196 = va_arg(aa, LispObject);
    v_15197 = va_arg(aa, LispObject);
    v_15198 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15198,v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15196,v_15197,v_15198);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_15256 = v_15198;
    stack[-2] = v_15197;
    stack[0] = v_15196;
// end of prologue
    goto v_15213;
v_15209:
    v_15257 = stack[0];
    v_15257 = qcdr(v_15257);
    v_15257 = qcar(v_15257);
    goto v_15210;
v_15211:
    goto v_15212;
v_15213:
    goto v_15209;
v_15210:
    goto v_15211;
v_15212:
    fn = elt(env, 2); // ofsf_optsplitterm
    v_15256 = (*qfn2(fn))(fn, v_15257, v_15256);
    env = stack[-4];
    stack[-3] = v_15256;
    if (v_15256 == nil) goto v_15206;
    else goto v_15207;
v_15206:
    v_15256 = stack[0];
    goto v_15202;
v_15207:
    goto v_15226;
v_15220:
    v_15256 = stack[0];
    stack[-1] = qcar(v_15256);
    goto v_15221;
v_15222:
    goto v_15234;
v_15230:
    goto v_15240;
v_15236:
    v_15256 = stack[-3];
    v_15257 = qcar(v_15256);
    goto v_15237;
v_15238:
    v_15256 = stack[-2];
    v_15256 = qcar(v_15256);
    goto v_15239;
v_15240:
    goto v_15236;
v_15237:
    goto v_15238;
v_15239:
    fn = elt(env, 3); // multf
    stack[0] = (*qfn2(fn))(fn, v_15257, v_15256);
    env = stack[-4];
    goto v_15231;
v_15232:
    goto v_15250;
v_15246:
    v_15256 = stack[-3];
    v_15257 = qcdr(v_15256);
    goto v_15247;
v_15248:
    v_15256 = stack[-2];
    v_15256 = qcdr(v_15256);
    goto v_15249;
v_15250:
    goto v_15246;
v_15247:
    goto v_15248;
v_15249:
    fn = elt(env, 3); // multf
    v_15256 = (*qfn2(fn))(fn, v_15257, v_15256);
    env = stack[-4];
    goto v_15233;
v_15234:
    goto v_15230;
v_15231:
    goto v_15232;
v_15233:
    fn = elt(env, 4); // addf
    v_15257 = (*qfn2(fn))(fn, stack[0], v_15256);
    goto v_15223;
v_15224:
    v_15256 = nil;
    goto v_15225;
v_15226:
    goto v_15220;
v_15221:
    goto v_15222;
v_15223:
    goto v_15224;
v_15225:
    {
        LispObject v_15262 = stack[-1];
        return list3(v_15262, v_15257, v_15256);
    }
v_15202:
    return onevalue(v_15256);
}



// Code for unaryir

static LispObject CC_unaryir(LispObject env,
                         LispObject v_15196, LispObject v_15197)
{
    env = qenv(env);
    LispObject v_15236, v_15237;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15196,v_15197);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15197;
    stack[-1] = v_15196;
// end of prologue
    goto v_15210;
v_15206:
    v_15237 = qvalue(elt(env, 2)); // atts
    goto v_15207;
v_15208:
    v_15236 = elt(env, 3); // name
    goto v_15209;
v_15210:
    goto v_15206;
v_15207:
    goto v_15208;
v_15209:
    fn = elt(env, 5); // find
    v_15236 = (*qfn2(fn))(fn, v_15237, v_15236);
    env = stack[-3];
    v_15236 = Lintern(nil, v_15236);
    env = stack[-3];
    stack[-2] = v_15236;
    goto v_15219;
v_15215:
    v_15237 = qvalue(elt(env, 2)); // atts
    goto v_15216;
v_15217:
    v_15236 = elt(env, 4); // cd
    goto v_15218;
v_15219:
    goto v_15215;
v_15216:
    goto v_15217;
v_15218:
    fn = elt(env, 5); // find
    v_15236 = (*qfn2(fn))(fn, v_15237, v_15236);
    env = stack[-3];
    v_15236 = Lintern(nil, v_15236);
    env = stack[-3];
    goto v_15230;
v_15226:
    v_15237 = v_15236;
    goto v_15227;
v_15228:
    v_15236 = stack[-1];
    goto v_15229;
v_15230:
    goto v_15226;
v_15227:
    goto v_15228;
v_15229:
    if (equal(v_15237, v_15236)) goto v_15225;
    v_15236 = stack[-2];
    {
        fn = elt(env, 6); // encodeir
        return (*qfn1(fn))(fn, v_15236);
    }
v_15225:
    v_15236 = stack[0];
    return onevalue(v_15236);
}



// Code for atomlis

static LispObject CC_atomlis(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15218, v_15219;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15218 = v_15196;
// end of prologue
v_15195:
    v_15219 = v_15218;
    if (v_15219 == nil) goto v_15200;
    else goto v_15201;
v_15200:
    v_15218 = lisp_true;
    goto v_15199;
v_15201:
    v_15219 = v_15218;
    v_15219 = qcar(v_15219);
    if (!consp(v_15219)) goto v_15208;
    else goto v_15209;
v_15208:
    v_15218 = qcdr(v_15218);
    goto v_15195;
v_15209:
    v_15218 = nil;
    goto v_15207;
    v_15218 = nil;
v_15207:
    goto v_15199;
    v_15218 = nil;
v_15199:
    return onevalue(v_15218);
}



// Code for ft!:zerop

static LispObject CC_ftTzerop(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15240, v_15241;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_15240 = v_15196;
// end of prologue
    goto v_15207;
v_15203:
    stack[0] = v_15240;
    goto v_15204;
v_15205:
    goto v_15214;
v_15210:
    v_15241 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_15211;
v_15212:
    v_15240 = qvalue(elt(env, 2)); // !:prec!:
    goto v_15213;
v_15214:
    goto v_15210;
v_15211:
    goto v_15212;
v_15213:
    v_15240 = Lexpt(nil, v_15241, v_15240);
    env = stack[-1];
    goto v_15206;
v_15207:
    goto v_15203;
v_15204:
    goto v_15205;
v_15206:
    v_15240 = times2(stack[0], v_15240);
    env = stack[-1];
    stack[0] = v_15240;
    goto v_15226;
v_15222:
    v_15241 = stack[0];
    goto v_15223;
v_15224:
    v_15240 = (LispObject)-800+TAG_FIXNUM; // -50
    goto v_15225;
v_15226:
    goto v_15222;
v_15223:
    goto v_15224;
v_15225:
    v_15240 = (LispObject)greaterp2(v_15241, v_15240);
    v_15240 = v_15240 ? lisp_true : nil;
    if (v_15240 == nil) goto v_15219;
    else goto v_15220;
v_15219:
    v_15240 = nil;
    goto v_15218;
v_15220:
    goto v_15237;
v_15233:
    v_15241 = stack[0];
    goto v_15234;
v_15235:
    v_15240 = (LispObject)800+TAG_FIXNUM; // 50
    goto v_15236;
v_15237:
    goto v_15233;
v_15234:
    goto v_15235;
v_15236:
        return Llessp(nil, v_15241, v_15240);
    v_15240 = nil;
v_15218:
    return onevalue(v_15240);
}



// Code for dip2vdp

static LispObject CC_dip2vdp(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15262, v_15263;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_15263 = v_15196;
// end of prologue
    v_15262 = qvalue(elt(env, 1)); // !*groebsubs
    if (v_15262 == nil) goto v_15201;
    v_15262 = v_15263;
    fn = elt(env, 3); // dipsubs2
    v_15262 = (*qfn1(fn))(fn, v_15262);
    env = stack[-3];
    goto v_15199;
v_15201:
    v_15262 = v_15263;
    goto v_15199;
    v_15262 = nil;
v_15199:
    v_15263 = v_15262;
    v_15262 = v_15263;
    if (v_15262 == nil) goto v_15211;
    else goto v_15212;
v_15211:
    goto v_15223;
v_15215:
    stack[-2] = elt(env, 2); // vdp
    goto v_15216;
v_15217:
    stack[-1] = nil;
    goto v_15218;
v_15219:
    v_15262 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 4); // a2bc
    stack[0] = (*qfn1(fn))(fn, v_15262);
    env = stack[-3];
    goto v_15220;
v_15221:
    goto v_15233;
v_15229:
    v_15263 = nil;
    goto v_15230;
v_15231:
    v_15262 = nil;
    goto v_15232;
v_15233:
    goto v_15229;
v_15230:
    goto v_15231;
v_15232:
    v_15262 = list2(v_15263, v_15262);
    goto v_15222;
v_15223:
    goto v_15215;
v_15216:
    goto v_15217;
v_15218:
    goto v_15219;
v_15220:
    goto v_15221;
v_15222:
    {
        LispObject v_15267 = stack[-2];
        LispObject v_15268 = stack[-1];
        LispObject v_15269 = stack[0];
        return list3star(v_15267, v_15268, v_15269, v_15262);
    }
v_15212:
    goto v_15247;
v_15239:
    stack[-2] = elt(env, 2); // vdp
    goto v_15240;
v_15241:
    v_15262 = v_15263;
    stack[-1] = qcar(v_15262);
    goto v_15242;
v_15243:
    v_15262 = v_15263;
    v_15262 = qcdr(v_15262);
    stack[0] = qcar(v_15262);
    goto v_15244;
v_15245:
    goto v_15259;
v_15255:
    goto v_15256;
v_15257:
    v_15262 = nil;
    goto v_15258;
v_15259:
    goto v_15255;
v_15256:
    goto v_15257;
v_15258:
    v_15262 = list2(v_15263, v_15262);
    goto v_15246;
v_15247:
    goto v_15239;
v_15240:
    goto v_15241;
v_15242:
    goto v_15243;
v_15244:
    goto v_15245;
v_15246:
    {
        LispObject v_15270 = stack[-2];
        LispObject v_15271 = stack[-1];
        LispObject v_15272 = stack[0];
        return list3star(v_15270, v_15271, v_15272, v_15262);
    }
    v_15262 = nil;
    return onevalue(v_15262);
}



// Code for equalreval

static LispObject CC_equalreval(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15236, v_15237;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_15236 = v_15196;
// end of prologue
    v_15237 = qvalue(elt(env, 1)); // substitution
    if (v_15237 == nil) goto v_15200;
    else goto v_15201;
v_15200:
    goto v_15210;
v_15204:
    stack[-1] = elt(env, 2); // equal
    goto v_15205;
v_15206:
    v_15237 = v_15236;
    stack[0] = qcar(v_15237);
    goto v_15207;
v_15208:
    v_15236 = qcdr(v_15236);
    v_15236 = qcar(v_15236);
    fn = elt(env, 3); // reval
    v_15236 = (*qfn1(fn))(fn, v_15236);
    env = stack[-2];
    v_15236 = ncons(v_15236);
    goto v_15209;
v_15210:
    goto v_15204;
v_15205:
    goto v_15206;
v_15207:
    goto v_15208;
v_15209:
    {
        LispObject v_15240 = stack[-1];
        LispObject v_15241 = stack[0];
        return list2star(v_15240, v_15241, v_15236);
    }
v_15201:
    goto v_15226;
v_15222:
    v_15237 = v_15236;
    v_15237 = qcar(v_15237);
    goto v_15223;
v_15224:
    v_15236 = qcdr(v_15236);
    v_15236 = qcar(v_15236);
    goto v_15225;
v_15226:
    goto v_15222;
v_15223:
    goto v_15224;
v_15225:
    fn = elt(env, 4); // evalequal
    v_15236 = (*qfn2(fn))(fn, v_15237, v_15236);
    if (v_15236 == nil) goto v_15220;
    v_15236 = lisp_true;
    goto v_15199;
v_15220:
    v_15236 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15199;
    v_15236 = nil;
v_15199:
    return onevalue(v_15236);
}



// Code for edge_new_parent

static LispObject CC_edge_new_parent(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15236, v_15237, v_15238;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15237 = v_15196;
// end of prologue
v_15195:
    v_15236 = v_15237;
    if (v_15236 == nil) goto v_15200;
    else goto v_15201;
v_15200:
    v_15236 = nil;
    goto v_15199;
v_15201:
    goto v_15210;
v_15206:
    v_15236 = v_15237;
    v_15238 = qcar(v_15236);
    goto v_15207;
v_15208:
    v_15236 = qvalue(elt(env, 1)); // new_edge_list
    goto v_15209;
v_15210:
    goto v_15206;
v_15207:
    goto v_15208;
v_15209:
    v_15236 = Lassoc(nil, v_15238, v_15236);
    v_15238 = v_15236;
    v_15236 = v_15238;
    if (v_15236 == nil) goto v_15219;
    goto v_15226;
v_15222:
    stack[0] = v_15238;
    goto v_15223;
v_15224:
    v_15236 = v_15237;
    v_15236 = qcdr(v_15236);
    v_15236 = CC_edge_new_parent(elt(env, 0), v_15236);
    goto v_15225;
v_15226:
    goto v_15222;
v_15223:
    goto v_15224;
v_15225:
    {
        LispObject v_15240 = stack[0];
        return cons(v_15240, v_15236);
    }
v_15219:
    v_15236 = v_15237;
    v_15236 = qcdr(v_15236);
    v_15237 = v_15236;
    goto v_15195;
    v_15236 = nil;
    goto v_15199;
    v_15236 = nil;
v_15199:
    return onevalue(v_15236);
}



// Code for pcdiv

static LispObject CC_pcdiv(LispObject env,
                         LispObject v_15196, LispObject v_15197)
{
    env = qenv(env);
    LispObject v_15271, v_15272;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15196,v_15197);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_15197;
    v_15271 = v_15196;
// end of prologue
    stack[-5] = v_15271;
    v_15271 = stack[-5];
    if (v_15271 == nil) goto v_15208;
    else goto v_15209;
v_15208:
    v_15271 = nil;
    goto v_15203;
v_15209:
    v_15271 = stack[-5];
    v_15271 = qcar(v_15271);
    v_15272 = v_15271;
    goto v_15221;
v_15217:
    v_15271 = v_15272;
    stack[0] = qcar(v_15271);
    goto v_15218;
v_15219:
    goto v_15229;
v_15225:
    v_15271 = v_15272;
    v_15272 = qcdr(v_15271);
    goto v_15226;
v_15227:
    v_15271 = stack[-4];
    goto v_15228;
v_15229:
    goto v_15225;
v_15226:
    goto v_15227;
v_15228:
    fn = elt(env, 1); // cdiv
    v_15271 = (*qfn2(fn))(fn, v_15272, v_15271);
    env = stack[-6];
    goto v_15220;
v_15221:
    goto v_15217;
v_15218:
    goto v_15219;
v_15220:
    v_15271 = cons(stack[0], v_15271);
    env = stack[-6];
    v_15271 = ncons(v_15271);
    env = stack[-6];
    stack[-2] = v_15271;
    stack[-3] = v_15271;
v_15204:
    v_15271 = stack[-5];
    v_15271 = qcdr(v_15271);
    stack[-5] = v_15271;
    v_15271 = stack[-5];
    if (v_15271 == nil) goto v_15237;
    else goto v_15238;
v_15237:
    v_15271 = stack[-3];
    goto v_15203;
v_15238:
    goto v_15246;
v_15242:
    stack[-1] = stack[-2];
    goto v_15243;
v_15244:
    v_15271 = stack[-5];
    v_15271 = qcar(v_15271);
    v_15272 = v_15271;
    goto v_15257;
v_15253:
    v_15271 = v_15272;
    stack[0] = qcar(v_15271);
    goto v_15254;
v_15255:
    goto v_15265;
v_15261:
    v_15271 = v_15272;
    v_15272 = qcdr(v_15271);
    goto v_15262;
v_15263:
    v_15271 = stack[-4];
    goto v_15264;
v_15265:
    goto v_15261;
v_15262:
    goto v_15263;
v_15264:
    fn = elt(env, 1); // cdiv
    v_15271 = (*qfn2(fn))(fn, v_15272, v_15271);
    env = stack[-6];
    goto v_15256;
v_15257:
    goto v_15253;
v_15254:
    goto v_15255;
v_15256:
    v_15271 = cons(stack[0], v_15271);
    env = stack[-6];
    v_15271 = ncons(v_15271);
    env = stack[-6];
    goto v_15245;
v_15246:
    goto v_15242;
v_15243:
    goto v_15244;
v_15245:
    v_15271 = Lrplacd(nil, stack[-1], v_15271);
    env = stack[-6];
    v_15271 = stack[-2];
    v_15271 = qcdr(v_15271);
    stack[-2] = v_15271;
    goto v_15204;
v_15203:
    return onevalue(v_15271);
}



// Code for extract_dummy_ids

static LispObject CC_extract_dummy_ids(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15235, v_15236, v_15237;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15196;
// end of prologue
    v_15237 = nil;
v_15201:
    v_15235 = stack[0];
    if (v_15235 == nil) goto v_15204;
    else goto v_15205;
v_15204:
    v_15235 = v_15237;
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_15235);
    }
v_15205:
    goto v_15215;
v_15211:
    v_15235 = stack[0];
    v_15236 = qcar(v_15235);
    goto v_15212;
v_15213:
    v_15235 = qvalue(elt(env, 1)); // dummy_id!*
    goto v_15214;
v_15215:
    goto v_15211;
v_15212:
    goto v_15213;
v_15214:
    v_15235 = Lmemq(nil, v_15236, v_15235);
    if (v_15235 == nil) goto v_15210;
    goto v_15225;
v_15221:
    v_15235 = stack[0];
    v_15235 = qcar(v_15235);
    goto v_15222;
v_15223:
    v_15236 = v_15237;
    goto v_15224;
v_15225:
    goto v_15221;
v_15222:
    goto v_15223;
v_15224:
    v_15235 = cons(v_15235, v_15236);
    env = stack[-1];
    v_15237 = v_15235;
    v_15235 = stack[0];
    v_15235 = qcdr(v_15235);
    stack[0] = v_15235;
    goto v_15201;
v_15210:
    v_15235 = stack[0];
    v_15235 = qcdr(v_15235);
    stack[0] = v_15235;
    goto v_15201;
    v_15235 = nil;
    return onevalue(v_15235);
}



// Code for yylex

static LispObject CC_yylex(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15389, v_15390, v_15391;
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
    fn = elt(env, 15); // lex_basic_token
    v_15389 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[0] = v_15389;
v_15206:
    v_15389 = stack[-2];
    if (v_15389 == nil) goto v_15213;
    else goto v_15214;
v_15213:
    goto v_15224;
v_15220:
    v_15390 = stack[0];
    goto v_15221;
v_15222:
    v_15389 = qvalue(elt(env, 2)); // lex_symbol_code
    goto v_15223;
v_15224:
    goto v_15220;
v_15221:
    goto v_15222;
v_15223:
    if (equal(v_15390, v_15389)) goto v_15218;
    else goto v_15219;
v_15218:
    v_15389 = qvalue(elt(env, 3)); // lex_escaped
    if (v_15389 == nil) goto v_15229;
    else goto v_15230;
v_15229:
    goto v_15238;
v_15234:
    v_15390 = qvalue(elt(env, 4)); // lexer_style!*
    goto v_15235;
v_15236:
    v_15389 = (LispObject)1024+TAG_FIXNUM; // 64
    goto v_15237;
v_15238:
    goto v_15234;
v_15235:
    goto v_15236;
v_15237:
    fn = elt(env, 16); // land
    v_15389 = (*qfn2(fn))(fn, v_15390, v_15389);
    env = stack[-4];
    v_15389 = (LispObject)zerop(v_15389);
    v_15389 = v_15389 ? lisp_true : nil;
    env = stack[-4];
    v_15389 = (v_15389 == nil ? lisp_true : nil);
    goto v_15228;
v_15230:
    v_15389 = nil;
    goto v_15228;
    v_15389 = nil;
v_15228:
    goto v_15217;
v_15219:
    v_15389 = nil;
    goto v_15217;
    v_15389 = nil;
v_15217:
    goto v_15212;
v_15214:
    v_15389 = nil;
    goto v_15212;
    v_15389 = nil;
v_15212:
    if (v_15389 == nil) goto v_15209;
    else goto v_15210;
v_15209:
    goto v_15205;
v_15210:
    fn = elt(env, 17); // lex_process_directive
    v_15389 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    if (v_15389 == nil) goto v_15255;
    fn = elt(env, 15); // lex_basic_token
    v_15389 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[0] = v_15389;
    goto v_15253;
v_15255:
    goto v_15264;
v_15260:
    v_15390 = qvalue(elt(env, 5)); // yylval
    goto v_15261;
v_15262:
    v_15389 = elt(env, 6); // !#define
    goto v_15263;
v_15264:
    goto v_15260;
v_15261:
    goto v_15262;
v_15263:
    if (v_15390 == v_15389) goto v_15258;
    else goto v_15259;
v_15258:
    fn = elt(env, 18); // read_s_expression
    v_15389 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    v_15389 = qvalue(elt(env, 5)); // yylval
    stack[0] = v_15389;
    fn = elt(env, 18); // read_s_expression
    v_15389 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    v_15389 = qvalue(elt(env, 5)); // yylval
    stack[-3] = v_15389;
    v_15389 = stack[0];
    if (symbolp(v_15389)) goto v_15275;
    else goto v_15274;
v_15275:
    v_15389 = stack[-3];
    if (symbolp(v_15389)) goto v_15277;
    v_15389 = stack[-3];
    if (is_number(v_15389)) goto v_15277;
    v_15389 = stack[-3];
    v_15389 = Lstringp(nil, v_15389);
    env = stack[-4];
    if (v_15389 == nil) goto v_15283;
    else goto v_15277;
v_15283:
    goto v_15274;
v_15277:
    v_15389 = Lposn(nil, 0);
    env = stack[-4];
    v_15389 = (LispObject)zerop(v_15389);
    v_15389 = v_15389 ? lisp_true : nil;
    env = stack[-4];
    if (v_15389 == nil) goto v_15288;
    else goto v_15289;
v_15288:
    v_15389 = Lterpri(nil, 0);
    env = stack[-4];
    goto v_15287;
v_15289:
v_15287:
    v_15389 = elt(env, 7); // "+++ "
    v_15389 = Lprinc(nil, v_15389);
    env = stack[-4];
    v_15389 = stack[0];
    v_15389 = Lprin(nil, v_15389);
    env = stack[-4];
    v_15389 = elt(env, 8); // " => "
    v_15389 = Lprinc(nil, v_15389);
    env = stack[-4];
    v_15389 = stack[-3];
    v_15389 = Lprint(nil, v_15389);
    env = stack[-4];
    goto v_15308;
v_15302:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15303;
v_15304:
    stack[0] = elt(env, 6); // !#define
    goto v_15305;
v_15306:
    v_15389 = stack[-3];
    v_15389 = ncons(v_15389);
    env = stack[-4];
    goto v_15307;
v_15308:
    goto v_15302;
v_15303:
    goto v_15304;
v_15305:
    goto v_15306;
v_15307:
    v_15389 = Lputprop(nil, 3, stack[-1], stack[0], v_15389);
    env = stack[-4];
    goto v_15272;
v_15274:
v_15272:
    fn = elt(env, 15); // lex_basic_token
    v_15389 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[0] = v_15389;
    goto v_15253;
v_15259:
    goto v_15320;
v_15316:
    v_15390 = qvalue(elt(env, 5)); // yylval
    goto v_15317;
v_15318:
    v_15389 = elt(env, 9); // !#eval
    goto v_15319;
v_15320:
    goto v_15316;
v_15317:
    goto v_15318;
v_15319:
    if (v_15390 == v_15389) goto v_15314;
    else goto v_15315;
v_15314:
    fn = elt(env, 18); // read_s_expression
    v_15389 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_15331;
v_15325:
    v_15391 = qvalue(elt(env, 5)); // yylval
    goto v_15326;
v_15327:
    v_15390 = nil;
    goto v_15328;
v_15329:
    v_15389 = nil;
    goto v_15330;
v_15331:
    goto v_15325;
v_15326:
    goto v_15327;
v_15328:
    goto v_15329;
v_15330:
    fn = elt(env, 19); // errorset
    v_15389 = (*qfnn(fn))(fn, 3, v_15391, v_15390, v_15389);
    env = stack[-4];
    fn = elt(env, 15); // lex_basic_token
    v_15389 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[0] = v_15389;
    goto v_15253;
v_15315:
    goto v_15343;
v_15339:
    v_15390 = qvalue(elt(env, 5)); // yylval
    goto v_15340;
v_15341:
    v_15389 = elt(env, 6); // !#define
    goto v_15342;
v_15343:
    goto v_15339;
v_15340:
    goto v_15341;
v_15342:
    v_15389 = get(v_15390, v_15389);
    env = stack[-4];
    stack[-3] = v_15389;
    if (v_15389 == nil) goto v_15337;
    v_15389 = stack[-3];
    v_15389 = qcar(v_15389);
    qvalue(elt(env, 5)) = v_15389; // yylval
    v_15389 = stack[-3];
    if (is_number(v_15389)) goto v_15350;
    else goto v_15351;
v_15350:
    v_15389 = qvalue(elt(env, 10)); // lex_number_code
    stack[0] = v_15389;
    goto v_15349;
v_15351:
    v_15389 = stack[-3];
    v_15389 = Lstringp(nil, v_15389);
    env = stack[-4];
    if (v_15389 == nil) goto v_15355;
    v_15389 = qvalue(elt(env, 11)); // lex_string_code
    stack[0] = v_15389;
    goto v_15349;
v_15355:
v_15349:
    v_15389 = lisp_true;
    stack[-2] = v_15389;
    goto v_15253;
v_15337:
    v_15389 = lisp_true;
    stack[-2] = v_15389;
    goto v_15253;
v_15253:
    goto v_15206;
v_15205:
    v_15389 = qvalue(elt(env, 12)); // !*tracelex
    if (v_15389 == nil) goto v_15366;
    goto v_15376;
v_15372:
    v_15390 = Lposn(nil, 0);
    env = stack[-4];
    goto v_15373;
v_15374:
    v_15389 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15375;
v_15376:
    goto v_15372;
v_15373:
    goto v_15374;
v_15375:
    if (v_15390 == v_15389) goto v_15371;
    v_15389 = Lterpri(nil, 0);
    env = stack[-4];
    goto v_15369;
v_15371:
v_15369:
    v_15389 = elt(env, 13); // "yylex = "
    v_15389 = Lprinc(nil, v_15389);
    env = stack[-4];
    v_15389 = qvalue(elt(env, 5)); // yylval
    v_15389 = Lprin(nil, v_15389);
    env = stack[-4];
    v_15389 = elt(env, 14); // " type "
    v_15389 = Lprinc(nil, v_15389);
    env = stack[-4];
    v_15389 = stack[0];
    v_15389 = Lprint(nil, v_15389);
    goto v_15364;
v_15366:
v_15364:
    v_15389 = stack[0];
    return onevalue(v_15389);
}



// Code for aex_lc

static LispObject CC_aex_lc(LispObject env,
                         LispObject v_15196, LispObject v_15197)
{
    env = qenv(env);
    LispObject v_15262, v_15263;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15196,v_15197);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_15262 = v_15197;
    stack[-1] = v_15196;
// end of prologue
    goto v_15213;
v_15209:
    v_15263 = stack[-1];
    goto v_15210;
v_15211:
    goto v_15212;
v_15213:
    goto v_15209;
v_15210:
    goto v_15211;
v_15212:
    fn = elt(env, 2); // aex_mvartest
    v_15262 = (*qfn2(fn))(fn, v_15263, v_15262);
    env = stack[-3];
    if (v_15262 == nil) goto v_15207;
    v_15262 = stack[-1];
    fn = elt(env, 3); // aex_ex
    v_15262 = (*qfn1(fn))(fn, v_15262);
    env = stack[-3];
    stack[-2] = v_15262;
    goto v_15223;
v_15219:
    goto v_15229;
v_15225:
    v_15262 = stack[-2];
    v_15262 = qcar(v_15262);
    fn = elt(env, 4); // sfto_lcx
    v_15263 = (*qfn1(fn))(fn, v_15262);
    env = stack[-3];
    goto v_15226;
v_15227:
    v_15262 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15228;
v_15229:
    goto v_15225;
v_15226:
    goto v_15227;
v_15228:
    stack[0] = cons(v_15263, v_15262);
    env = stack[-3];
    goto v_15220;
v_15221:
    goto v_15239;
v_15235:
    v_15262 = stack[-2];
    v_15263 = qcdr(v_15262);
    goto v_15236;
v_15237:
    v_15262 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15238;
v_15239:
    goto v_15235;
v_15236:
    goto v_15237;
v_15238:
    v_15262 = cons(v_15263, v_15262);
    env = stack[-3];
    goto v_15222;
v_15223:
    goto v_15219;
v_15220:
    goto v_15221;
v_15222:
    fn = elt(env, 5); // quotsq
    v_15262 = (*qfn2(fn))(fn, stack[0], v_15262);
    env = stack[-3];
    goto v_15248;
v_15244:
    stack[-2] = v_15262;
    goto v_15245;
v_15246:
    goto v_15255;
v_15251:
    v_15262 = qcar(v_15262);
    fn = elt(env, 6); // kernels
    stack[0] = (*qfn1(fn))(fn, v_15262);
    env = stack[-3];
    goto v_15252;
v_15253:
    v_15262 = stack[-1];
    fn = elt(env, 7); // aex_ctx
    v_15262 = (*qfn1(fn))(fn, v_15262);
    env = stack[-3];
    goto v_15254;
v_15255:
    goto v_15251;
v_15252:
    goto v_15253;
v_15254:
    fn = elt(env, 8); // ctx_filter
    v_15262 = (*qfn2(fn))(fn, stack[0], v_15262);
    env = stack[-3];
    goto v_15247;
v_15248:
    goto v_15244;
v_15245:
    goto v_15246;
v_15247:
    {
        LispObject v_15267 = stack[-2];
        fn = elt(env, 9); // aex_mk
        return (*qfn2(fn))(fn, v_15267, v_15262);
    }
v_15207:
    v_15262 = stack[-1];
    return onevalue(v_15262);
}



// Code for outref

static LispObject CC_outref(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15310, v_15311, v_15312;
    LispObject fn;
    LispObject v_15199, v_15198, v_15197, v_15196;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "outref");
    va_start(aa, nargs);
    v_15196 = va_arg(aa, LispObject);
    v_15197 = va_arg(aa, LispObject);
    v_15198 = va_arg(aa, LispObject);
    v_15199 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_15199,v_15198,v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_15196,v_15197,v_15198,v_15199);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-5] = v_15199;
    stack[-6] = v_15198;
    stack[-7] = v_15197;
    stack[-8] = v_15196;
// end of prologue
// Binding curfun!*
// FLUIDBIND: reloadenv=10 litvec-offset=1 saveloc=9
{   bind_fluid_stack bind_fluid_var(-10, 1, -9);
    qvalue(elt(env, 1)) = nil; // curfun!*
// Binding calls!*
// FLUIDBIND: reloadenv=10 litvec-offset=2 saveloc=4
{   bind_fluid_stack bind_fluid_var(-10, 2, -4);
    qvalue(elt(env, 2)) = nil; // calls!*
// Binding globs!*
// FLUIDBIND: reloadenv=10 litvec-offset=3 saveloc=3
{   bind_fluid_stack bind_fluid_var(-10, 3, -3);
    qvalue(elt(env, 3)) = nil; // globs!*
// Binding locls!*
// FLUIDBIND: reloadenv=10 litvec-offset=4 saveloc=2
{   bind_fluid_stack bind_fluid_var(-10, 4, -2);
    qvalue(elt(env, 4)) = nil; // locls!*
// Binding toplv!*
// FLUIDBIND: reloadenv=10 litvec-offset=5 saveloc=1
{   bind_fluid_stack bind_fluid_var(-10, 5, -1);
    qvalue(elt(env, 5)) = nil; // toplv!*
    goto v_15218;
v_15214:
    v_15311 = stack[-7];
    goto v_15215;
v_15216:
    v_15310 = elt(env, 7); // (anp!!atom anp!!idb anp!!eq anp!!unknown)
    goto v_15217;
v_15218:
    goto v_15214;
v_15215:
    goto v_15216;
v_15217:
    v_15310 = Lmemq(nil, v_15311, v_15310);
    if (v_15310 == nil) goto v_15213;
    v_15310 = nil;
    goto v_15211;
v_15213:
    v_15310 = stack[-7];
    v_15310 = Llength(nil, v_15310);
    env = stack[-10];
    goto v_15211;
    v_15310 = nil;
v_15211:
    stack[0] = v_15310;
    goto v_15234;
v_15228:
    v_15312 = stack[-8];
    goto v_15229;
v_15230:
    v_15311 = stack[-5];
    goto v_15231;
v_15232:
    v_15310 = stack[0];
    if (v_15310 == nil) goto v_15240;
    v_15310 = stack[0];
    goto v_15238;
v_15240:
    v_15310 = stack[-6];
    if (!symbolp(v_15310)) v_15310 = nil;
    else { v_15310 = qfastgets(v_15310);
           if (v_15310 != nil) { v_15310 = elt(v_15310, 42); // number!-of!-args
#ifdef RECORD_GET
             if (v_15310 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v_15310 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v_15310 == SPID_NOPROP) v_15310 = nil; }}
#endif
    goto v_15238;
    v_15310 = nil;
v_15238:
    goto v_15233;
v_15234:
    goto v_15228;
v_15229:
    goto v_15230;
v_15231:
    goto v_15232;
v_15233:
    fn = elt(env, 11); // outrdefun
    v_15310 = (*qfnn(fn))(fn, 3, v_15312, v_15311, v_15310);
    env = stack[-10];
    stack[-8] = v_15310;
    v_15310 = stack[0];
    if (v_15310 == nil) goto v_15250;
    v_15310 = stack[-7];
    fn = elt(env, 12); // add2locs
    v_15310 = (*qfn1(fn))(fn, v_15310);
    env = stack[-10];
    v_15310 = stack[-6];
    fn = elt(env, 13); // anform
    v_15310 = (*qfn1(fn))(fn, v_15310);
    env = stack[-10];
    v_15310 = stack[-7];
    fn = elt(env, 14); // remlocs
    v_15310 = (*qfn1(fn))(fn, v_15310);
    env = stack[-10];
    goto v_15248;
v_15250:
    v_15310 = stack[-6];
    if (v_15310 == nil) goto v_15262;
    else goto v_15263;
v_15262:
    v_15310 = lisp_true;
    goto v_15261;
v_15263:
    v_15310 = stack[-6];
    v_15310 = Lsymbolp(nil, v_15310);
    env = stack[-10];
    v_15310 = (v_15310 == nil ? lisp_true : nil);
    goto v_15261;
    v_15310 = nil;
v_15261:
    if (v_15310 == nil) goto v_15259;
    goto v_15248;
v_15259:
    goto v_15278;
v_15274:
    v_15311 = stack[-7];
    goto v_15275;
v_15276:
    v_15310 = elt(env, 8); // anp!!eq
    goto v_15277;
v_15278:
    goto v_15274;
v_15275:
    goto v_15276;
v_15277:
    if (v_15311 == v_15310) goto v_15272;
    else goto v_15273;
v_15272:
    goto v_15288;
v_15282:
    stack[-5] = stack[-8];
    goto v_15283;
v_15284:
    stack[0] = elt(env, 9); // sameas
    goto v_15285;
v_15286:
    v_15310 = stack[-6];
    v_15310 = ncons(v_15310);
    env = stack[-10];
    goto v_15287;
v_15288:
    goto v_15282;
v_15283:
    goto v_15284;
v_15285:
    goto v_15286;
v_15287:
    v_15310 = Lputprop(nil, 3, stack[-5], stack[0], v_15310);
    env = stack[-10];
    goto v_15300;
v_15294:
    v_15312 = stack[-6];
    goto v_15295;
v_15296:
    v_15311 = elt(env, 10); // alsois
    goto v_15297;
v_15298:
    v_15310 = stack[-8];
    goto v_15299;
v_15300:
    goto v_15294;
v_15295:
    goto v_15296;
v_15297:
    goto v_15298;
v_15299:
    fn = elt(env, 15); // traput
    v_15310 = (*qfnn(fn))(fn, 3, v_15312, v_15311, v_15310);
    env = stack[-10];
    goto v_15248;
v_15273:
    v_15310 = stack[-6];
    fn = elt(env, 16); // add2calls
    v_15310 = (*qfn1(fn))(fn, v_15310);
    env = stack[-10];
    goto v_15248;
v_15248:
    v_15310 = stack[-8];
    fn = elt(env, 17); // outrefend
    v_15310 = (*qfn1(fn))(fn, v_15310);
    v_15310 = nil;
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_15310);
}



// Code for createtriplewithancestor

static LispObject CC_createtriplewithancestor(LispObject env,
                         LispObject v_15196, LispObject v_15197)
{
    env = qenv(env);
    LispObject v_15249, v_15250, v_15251;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15196,v_15197);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15197;
    stack[-1] = v_15196;
// end of prologue
    v_15249 = (LispObject)48+TAG_FIXNUM; // 3
    v_15249 = Lmkvect(nil, v_15249);
    env = stack[-3];
    stack[-2] = v_15249;
    goto v_15211;
v_15205:
    v_15251 = stack[-2];
    goto v_15206;
v_15207:
    v_15250 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15208;
v_15209:
    v_15249 = qvalue(elt(env, 2)); // fluidbibasistripleid
    goto v_15210;
v_15211:
    goto v_15205;
v_15206:
    goto v_15207;
v_15208:
    goto v_15209;
v_15210:
    *(LispObject *)((char *)v_15251 + (CELL-TAG_VECTOR) + (((intptr_t)v_15250-TAG_FIXNUM)/(16/CELL))) = v_15249;
    goto v_15221;
v_15215:
    v_15251 = stack[-2];
    goto v_15216;
v_15217:
    v_15250 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15218;
v_15219:
    v_15249 = stack[-1];
    goto v_15220;
v_15221:
    goto v_15215;
v_15216:
    goto v_15217;
v_15218:
    goto v_15219;
v_15220:
    *(LispObject *)((char *)v_15251 + (CELL-TAG_VECTOR) + (((intptr_t)v_15250-TAG_FIXNUM)/(16/CELL))) = v_15249;
    goto v_15231;
v_15225:
    v_15251 = stack[-2];
    goto v_15226;
v_15227:
    v_15250 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_15228;
v_15229:
    v_15249 = stack[0];
    goto v_15230;
v_15231:
    goto v_15225;
v_15226:
    goto v_15227;
v_15228:
    goto v_15229;
v_15230:
    *(LispObject *)((char *)v_15251 + (CELL-TAG_VECTOR) + (((intptr_t)v_15250-TAG_FIXNUM)/(16/CELL))) = v_15249;
    goto v_15241;
v_15235:
    stack[-1] = stack[-2];
    goto v_15236;
v_15237:
    stack[0] = (LispObject)48+TAG_FIXNUM; // 3
    goto v_15238;
v_15239:
    v_15249 = nil;
    v_15249 = ncons(v_15249);
    env = stack[-3];
    goto v_15240;
v_15241:
    goto v_15235;
v_15236:
    goto v_15237;
v_15238:
    goto v_15239;
v_15240:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_15249;
    v_15249 = qvalue(elt(env, 2)); // fluidbibasistripleid
    v_15249 = (LispObject)((intptr_t)(v_15249) + 0x10);
    qvalue(elt(env, 2)) = v_15249; // fluidbibasistripleid
    v_15249 = stack[-2];
    return onevalue(v_15249);
}



// Code for ofsf_smmkatl

static LispObject CC_ofsf_smmkatl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15246, v_15247, v_15248, v_15249;
    LispObject fn;
    LispObject v_15199, v_15198, v_15197, v_15196;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ofsf_smmkatl");
    va_start(aa, nargs);
    v_15196 = va_arg(aa, LispObject);
    v_15197 = va_arg(aa, LispObject);
    v_15198 = va_arg(aa, LispObject);
    v_15199 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_15199,v_15198,v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_15196,v_15197,v_15198,v_15199);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_15246 = v_15199;
    stack[0] = v_15198;
    v_15247 = v_15197;
    v_15249 = v_15196;
// end of prologue
    v_15248 = qvalue(elt(env, 1)); // !*rlsippatl
    if (v_15248 == nil) goto v_15204;
    goto v_15213;
v_15207:
    stack[-1] = v_15249;
    goto v_15208;
v_15209:
    goto v_15224;
v_15216:
    goto v_15217;
v_15218:
    v_15248 = v_15247;
    goto v_15219;
v_15220:
    v_15247 = stack[0];
    goto v_15221;
v_15222:
    goto v_15223;
v_15224:
    goto v_15216;
v_15217:
    goto v_15218;
v_15219:
    goto v_15220;
v_15221:
    goto v_15222;
v_15223:
    fn = elt(env, 2); // ofsf_smmkatl1
    v_15247 = (*qfnn(fn))(fn, 4, v_15249, v_15248, v_15247, v_15246);
    env = stack[-2];
    goto v_15210;
v_15211:
    v_15246 = stack[0];
    goto v_15212;
v_15213:
    goto v_15207;
v_15208:
    goto v_15209;
v_15210:
    goto v_15211;
v_15212:
    {
        LispObject v_15252 = stack[-1];
        fn = elt(env, 3); // ofsf_sippatl
        return (*qfnn(fn))(fn, 3, v_15252, v_15247, v_15246);
    }
v_15204:
    goto v_15241;
v_15233:
    goto v_15234;
v_15235:
    v_15248 = v_15247;
    goto v_15236;
v_15237:
    v_15247 = stack[0];
    goto v_15238;
v_15239:
    goto v_15240;
v_15241:
    goto v_15233;
v_15234:
    goto v_15235;
v_15236:
    goto v_15237;
v_15238:
    goto v_15239;
v_15240:
    {
        fn = elt(env, 2); // ofsf_smmkatl1
        return (*qfnn(fn))(fn, 4, v_15249, v_15248, v_15247, v_15246);
    }
    v_15246 = nil;
    return onevalue(v_15246);
}



// Code for bc_2sq

static LispObject CC_bc_2sq(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15199;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15199 = v_15196;
// end of prologue
    return onevalue(v_15199);
}



// Code for oldmtch

static LispObject CC_oldmtch(LispObject env,
                         LispObject v_15196, LispObject v_15197)
{
    env = qenv(env);
    LispObject v_15270, v_15271, v_15272;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15196,v_15197);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_15197;
    stack[-2] = v_15196;
// end of prologue
    stack[-3] = nil;
    goto v_15211;
v_15205:
    v_15270 = stack[-2];
    v_15272 = qcdr(v_15270);
    goto v_15206;
v_15207:
    v_15270 = stack[-1];
    v_15271 = qcar(v_15270);
    goto v_15208;
v_15209:
    v_15270 = stack[-2];
    v_15270 = qcar(v_15270);
    goto v_15210;
v_15211:
    goto v_15205;
v_15206:
    goto v_15207;
v_15208:
    goto v_15209;
v_15210:
    fn = elt(env, 2); // mcharg
    v_15270 = (*qfnn(fn))(fn, 3, v_15272, v_15271, v_15270);
    env = stack[-4];
    stack[0] = v_15270;
v_15220:
    v_15270 = stack[0];
    if (v_15270 == nil) goto v_15223;
    v_15270 = stack[-3];
    if (v_15270 == nil) goto v_15227;
    else goto v_15223;
v_15227:
    goto v_15224;
v_15223:
    goto v_15219;
v_15224:
    goto v_15240;
v_15236:
    v_15270 = stack[0];
    v_15271 = qcar(v_15270);
    goto v_15237;
v_15238:
    v_15270 = stack[-1];
    v_15270 = qcdr(v_15270);
    v_15270 = qcar(v_15270);
    v_15270 = qcdr(v_15270);
    goto v_15239;
v_15240:
    goto v_15236;
v_15237:
    goto v_15238;
v_15239:
    v_15270 = Lsubla(nil, v_15271, v_15270);
    env = stack[-4];
    fn = elt(env, 3); // eval
    v_15270 = (*qfn1(fn))(fn, v_15270);
    env = stack[-4];
    if (v_15270 == nil) goto v_15233;
    goto v_15252;
v_15248:
    v_15270 = stack[0];
    v_15271 = qcar(v_15270);
    goto v_15249;
v_15250:
    v_15270 = stack[-1];
    v_15270 = qcdr(v_15270);
    v_15270 = qcdr(v_15270);
    v_15270 = qcar(v_15270);
    goto v_15251;
v_15252:
    goto v_15248;
v_15249:
    goto v_15250;
v_15251:
    v_15270 = Lsubla(nil, v_15271, v_15270);
    env = stack[-4];
    goto v_15231;
v_15233:
    v_15270 = nil;
v_15231:
    stack[-3] = v_15270;
    v_15270 = stack[0];
    v_15270 = qcdr(v_15270);
    stack[0] = v_15270;
    goto v_15220;
v_15219:
    v_15270 = stack[-3];
    if (v_15270 == nil) goto v_15264;
    v_15270 = stack[-3];
    goto v_15262;
v_15264:
    v_15270 = stack[-2];
    goto v_15262;
    v_15270 = nil;
v_15262:
    return onevalue(v_15270);
}



// Code for dip!-nc!-ev!-prod1

static LispObject CC_dipKncKevKprod1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15232, v_15233, v_15234, v_15235;
    LispObject fn;
    LispObject v_15198, v_15197, v_15196;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dip-nc-ev-prod1");
    va_start(aa, nargs);
    v_15196 = va_arg(aa, LispObject);
    v_15197 = va_arg(aa, LispObject);
    v_15198 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15198,v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15196,v_15197,v_15198);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_15233 = v_15198;
    v_15234 = v_15197;
    v_15235 = v_15196;
// end of prologue
    v_15232 = v_15235;
    if (v_15232 == nil) goto v_15202;
    else goto v_15203;
v_15202:
    v_15232 = v_15233;
    goto v_15201;
v_15203:
    goto v_15215;
v_15209:
    v_15232 = v_15235;
    stack[-1] = qcar(v_15232);
    goto v_15210;
v_15211:
    stack[0] = v_15234;
    goto v_15212;
v_15213:
    goto v_15226;
v_15220:
    v_15232 = v_15235;
    v_15232 = qcdr(v_15232);
    goto v_15221;
v_15222:
    v_15234 = (LispObject)((intptr_t)(v_15234) + 0x10);
    goto v_15223;
v_15224:
    goto v_15225;
v_15226:
    goto v_15220;
v_15221:
    goto v_15222;
v_15223:
    goto v_15224;
v_15225:
    v_15232 = CC_dipKncKevKprod1(elt(env, 0), 3, v_15232, v_15234, v_15233);
    env = stack[-2];
    goto v_15214;
v_15215:
    goto v_15209;
v_15210:
    goto v_15211;
v_15212:
    goto v_15213;
v_15214:
    {
        LispObject v_15238 = stack[-1];
        LispObject v_15239 = stack[0];
        fn = elt(env, 1); // dip!-nc!-ev!-prod2
        return (*qfnn(fn))(fn, 3, v_15238, v_15239, v_15232);
    }
    v_15232 = nil;
v_15201:
    return onevalue(v_15232);
}



// Code for memqcar

static LispObject CC_memqcar(LispObject env,
                         LispObject v_15196, LispObject v_15197)
{
    env = qenv(env);
    LispObject v_15216, v_15217, v_15218;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15216 = v_15197;
    v_15217 = v_15196;
// end of prologue
    v_15218 = v_15217;
    if (!consp(v_15218)) goto v_15202;
    goto v_15208;
v_15204:
    v_15217 = qcar(v_15217);
    goto v_15205;
v_15206:
    goto v_15207;
v_15208:
    goto v_15204;
v_15205:
    goto v_15206;
v_15207:
    v_15216 = Lmemq(nil, v_15217, v_15216);
    goto v_15200;
v_15202:
    v_15216 = nil;
    goto v_15200;
    v_15216 = nil;
v_15200:
    return onevalue(v_15216);
}



// Code for bfplusn

static LispObject CC_bfplusn(LispObject env,
                         LispObject v_15196, LispObject v_15197)
{
    env = qenv(env);
    LispObject v_15222, v_15223, v_15224;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15223 = v_15197;
    v_15224 = v_15196;
// end of prologue
    v_15222 = v_15224;
    if (!consp(v_15222)) goto v_15201;
    else goto v_15202;
v_15201:
    goto v_15209;
v_15205:
    v_15222 = v_15224;
    goto v_15206;
v_15207:
    goto v_15208;
v_15209:
    goto v_15205;
v_15206:
    goto v_15207;
v_15208:
    return plus2(v_15222, v_15223);
v_15202:
    goto v_15219;
v_15215:
    v_15222 = v_15224;
    goto v_15216;
v_15217:
    goto v_15218;
v_15219:
    goto v_15215;
v_15216:
    goto v_15217;
v_15218:
    {
        fn = elt(env, 1); // plus!:
        return (*qfn2(fn))(fn, v_15222, v_15223);
    }
    v_15222 = nil;
    return onevalue(v_15222);
}



// Code for log_assignment_list

static LispObject CC_log_assignment_list(LispObject env,
                         LispObject v_15196, LispObject v_15197)
{
    env = qenv(env);
    LispObject v_15224, v_15225;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15196,v_15197);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15197;
    stack[-1] = v_15196;
// end of prologue
v_15201:
    v_15224 = stack[0];
    if (!consp(v_15224)) goto v_15204;
    else goto v_15205;
v_15204:
    v_15224 = nil;
    goto v_15200;
v_15205:
    goto v_15215;
v_15211:
    v_15225 = stack[-1];
    goto v_15212;
v_15213:
    v_15224 = stack[0];
    v_15224 = qcar(v_15224);
    goto v_15214;
v_15215:
    goto v_15211;
v_15212:
    goto v_15213;
v_15214:
    fn = elt(env, 1); // log_assignment
    v_15224 = (*qfn2(fn))(fn, v_15225, v_15224);
    env = stack[-2];
    if (v_15224 == nil) goto v_15209;
    v_15224 = lisp_true;
    goto v_15200;
v_15209:
    v_15224 = stack[0];
    v_15224 = qcdr(v_15224);
    stack[0] = v_15224;
    goto v_15201;
    v_15224 = nil;
v_15200:
    return onevalue(v_15224);
}



// Code for insert

static LispObject CC_insert(LispObject env,
                         LispObject v_15197, LispObject v_15198)
{
    env = qenv(env);
    LispObject v_15257, v_15258;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15198,v_15197);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15197,v_15198);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_15257 = v_15198;
    stack[-1] = v_15197;
// end of prologue
// Binding gg!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = v_15257; // gg!*
    stack[0] = nil;
v_15210:
    v_15257 = qvalue(elt(env, 1)); // gg!*
    if (v_15257 == nil) goto v_15213;
    goto v_15223;
v_15219:
    v_15257 = stack[-1];
    v_15258 = qcdr(v_15257);
    goto v_15220;
v_15221:
    v_15257 = qvalue(elt(env, 1)); // gg!*
    v_15257 = qcar(v_15257);
    v_15257 = qcdr(v_15257);
    goto v_15222;
v_15223:
    goto v_15219;
v_15220:
    goto v_15221;
v_15222:
    fn = elt(env, 3); // dless
    v_15257 = (*qfn2(fn))(fn, v_15258, v_15257);
    env = stack[-3];
    if (v_15257 == nil) goto v_15213;
    goto v_15214;
v_15213:
    goto v_15209;
v_15214:
    goto v_15235;
v_15231:
    v_15257 = qvalue(elt(env, 1)); // gg!*
    v_15258 = qcar(v_15257);
    goto v_15232;
v_15233:
    v_15257 = stack[0];
    goto v_15234;
v_15235:
    goto v_15231;
v_15232:
    goto v_15233;
v_15234:
    v_15257 = cons(v_15258, v_15257);
    env = stack[-3];
    stack[0] = v_15257;
    v_15257 = qvalue(elt(env, 1)); // gg!*
    v_15257 = qcdr(v_15257);
    qvalue(elt(env, 1)) = v_15257; // gg!*
    goto v_15210;
v_15209:
    goto v_15246;
v_15242:
    v_15257 = stack[0];
    stack[0] = Lnreverse(nil, v_15257);
    env = stack[-3];
    goto v_15243;
v_15244:
    goto v_15254;
v_15250:
    v_15258 = stack[-1];
    goto v_15251;
v_15252:
    v_15257 = qvalue(elt(env, 1)); // gg!*
    goto v_15253;
v_15254:
    goto v_15250;
v_15251:
    goto v_15252;
v_15253:
    v_15257 = cons(v_15258, v_15257);
    env = stack[-3];
    goto v_15245;
v_15246:
    goto v_15242;
v_15243:
    goto v_15244;
v_15245:
    v_15257 = Lappend(nil, stack[0], v_15257);
    ;}  // end of a binding scope
    return onevalue(v_15257);
}



// Code for sc_rep

static LispObject CC_sc_rep(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15209;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15209 = v_15196;
// end of prologue
    goto v_15202;
v_15198:
    stack[0] = qvalue(elt(env, 1)); // g_sc_ve
    goto v_15199;
v_15200:
    v_15209 = sub1(v_15209);
    goto v_15201;
v_15202:
    goto v_15198;
v_15199:
    goto v_15200;
v_15201:
    v_15209 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_15209-TAG_FIXNUM)/(16/CELL)));
    v_15209 = qcdr(v_15209);
    v_15209 = qcar(v_15209);
    return onevalue(v_15209);
}



// Code for gcd!-in!-vector

static LispObject CC_gcdKinKvector(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15474, v_15475, v_15476, v_15477, v_15478, v_15479;
    LispObject fn;
    LispObject v_15199, v_15198, v_15197, v_15196;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "gcd-in-vector");
    va_start(aa, nargs);
    v_15196 = va_arg(aa, LispObject);
    v_15197 = va_arg(aa, LispObject);
    v_15198 = va_arg(aa, LispObject);
    v_15199 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_15199,v_15198,v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_15196,v_15197,v_15198,v_15199);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15199;
    stack[-1] = v_15198;
    stack[-2] = v_15197;
    stack[-3] = v_15196;
// end of prologue
    goto v_15218;
v_15214:
    v_15475 = stack[-2];
    goto v_15215;
v_15216:
    v_15474 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15217;
v_15218:
    goto v_15214;
v_15215:
    goto v_15216;
v_15217:
    if (v_15475 == v_15474) goto v_15212;
    else goto v_15213;
v_15212:
    v_15474 = lisp_true;
    goto v_15211;
v_15213:
    goto v_15228;
v_15224:
    v_15475 = stack[0];
    goto v_15225;
v_15226:
    v_15474 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15227;
v_15228:
    goto v_15224;
v_15225:
    goto v_15226;
v_15227:
    v_15474 = (v_15475 == v_15474 ? lisp_true : nil);
    goto v_15211;
    v_15474 = nil;
v_15211:
    if (v_15474 == nil) goto v_15209;
    goto v_15238;
v_15232:
    v_15476 = stack[-3];
    goto v_15233;
v_15234:
    v_15475 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15235;
v_15236:
    v_15474 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15237;
v_15238:
    goto v_15232;
v_15233:
    goto v_15234;
v_15235:
    goto v_15236;
v_15237:
    *(LispObject *)((char *)v_15476 + (CELL-TAG_VECTOR) + (((intptr_t)v_15475-TAG_FIXNUM)/(16/CELL))) = v_15474;
    v_15474 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15203;
v_15209:
    goto v_15250;
v_15246:
    v_15475 = stack[-2];
    goto v_15247;
v_15248:
    v_15474 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15249;
v_15250:
    goto v_15246;
v_15247:
    goto v_15248;
v_15249:
    if (((intptr_t)(v_15475)) < ((intptr_t)(v_15474))) goto v_15243;
    goto v_15258;
v_15254:
    v_15475 = stack[0];
    goto v_15255;
v_15256:
    v_15474 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15257;
v_15258:
    goto v_15254;
v_15255:
    goto v_15256;
v_15257:
    if (((intptr_t)(v_15475)) < ((intptr_t)(v_15474))) goto v_15243;
    goto v_15244;
v_15243:
    v_15474 = elt(env, 2); // "GCD with zero not allowed"
    fn = elt(env, 3); // errorf
    v_15474 = (*qfn1(fn))(fn, v_15474);
    env = stack[-4];
    goto v_15207;
v_15244:
v_15207:
v_15204:
    goto v_15272;
v_15264:
    v_15477 = stack[-3];
    goto v_15265;
v_15266:
    v_15476 = stack[-2];
    goto v_15267;
v_15268:
    v_15475 = stack[-1];
    goto v_15269;
v_15270:
    v_15474 = stack[0];
    goto v_15271;
v_15272:
    goto v_15264;
v_15265:
    goto v_15266;
v_15267:
    goto v_15268;
v_15269:
    goto v_15270;
v_15271:
    fn = elt(env, 4); // remainder!-in!-vector
    v_15474 = (*qfnn(fn))(fn, 4, v_15477, v_15476, v_15475, v_15474);
    env = stack[-4];
    stack[-2] = v_15474;
    goto v_15285;
v_15281:
    v_15475 = stack[-2];
    goto v_15282;
v_15283:
    v_15474 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15284;
v_15285:
    goto v_15281;
v_15282:
    goto v_15283;
v_15284:
    if (v_15475 == v_15474) goto v_15279;
    else goto v_15280;
v_15279:
    goto v_15294;
v_15288:
    v_15476 = stack[-3];
    goto v_15289;
v_15290:
    v_15475 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15291;
v_15292:
    v_15474 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15293;
v_15294:
    goto v_15288;
v_15289:
    goto v_15290;
v_15291:
    goto v_15292;
v_15293:
    *(LispObject *)((char *)v_15476 + (CELL-TAG_VECTOR) + (((intptr_t)v_15475-TAG_FIXNUM)/(16/CELL))) = v_15474;
    v_15474 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15203;
v_15280:
    goto v_15305;
v_15301:
    v_15475 = stack[-2];
    goto v_15302;
v_15303:
    v_15474 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_15304;
v_15305:
    goto v_15301;
v_15302:
    goto v_15303;
v_15304:
    if (v_15475 == v_15474) goto v_15299;
    else goto v_15300;
v_15299:
    goto v_15313;
v_15309:
    v_15475 = stack[-1];
    goto v_15310;
v_15311:
    v_15474 = stack[0];
    goto v_15312;
v_15313:
    goto v_15309;
v_15310:
    goto v_15311;
v_15312:
    v_15474 = *(LispObject *)((char *)v_15475 + (CELL-TAG_VECTOR) + (((intptr_t)v_15474-TAG_FIXNUM)/(16/CELL)));
    v_15474 = Lmodular_reciprocal(nil, v_15474);
    env = stack[-4];
    v_15479 = v_15474;
    v_15474 = (LispObject)0+TAG_FIXNUM; // 0
    v_15478 = v_15474;
v_15320:
    goto v_15330;
v_15326:
    v_15475 = stack[0];
    goto v_15327;
v_15328:
    v_15474 = v_15478;
    goto v_15329;
v_15330:
    goto v_15326;
v_15327:
    goto v_15328;
v_15329:
    v_15474 = (LispObject)(intptr_t)((intptr_t)v_15475 - (intptr_t)v_15474 + TAG_FIXNUM);
    v_15474 = ((intptr_t)(v_15474) < 0 ? lisp_true : nil);
    if (v_15474 == nil) goto v_15325;
    goto v_15319;
v_15325:
    goto v_15342;
v_15336:
    v_15477 = stack[-3];
    goto v_15337;
v_15338:
    v_15476 = v_15478;
    goto v_15339;
v_15340:
    goto v_15350;
v_15346:
    goto v_15355;
v_15351:
    v_15475 = stack[-1];
    goto v_15352;
v_15353:
    v_15474 = v_15478;
    goto v_15354;
v_15355:
    goto v_15351;
v_15352:
    goto v_15353;
v_15354:
    v_15475 = *(LispObject *)((char *)v_15475 + (CELL-TAG_VECTOR) + (((intptr_t)v_15474-TAG_FIXNUM)/(16/CELL)));
    goto v_15347;
v_15348:
    v_15474 = v_15479;
    goto v_15349;
v_15350:
    goto v_15346;
v_15347:
    goto v_15348;
v_15349:
    v_15474 = Lmodular_times(nil, v_15475, v_15474);
    env = stack[-4];
    goto v_15341;
v_15342:
    goto v_15336;
v_15337:
    goto v_15338;
v_15339:
    goto v_15340;
v_15341:
    *(LispObject *)((char *)v_15477 + (CELL-TAG_VECTOR) + (((intptr_t)v_15476-TAG_FIXNUM)/(16/CELL))) = v_15474;
    v_15474 = v_15478;
    v_15474 = (LispObject)((intptr_t)(v_15474) + 0x10);
    v_15478 = v_15474;
    goto v_15320;
v_15319:
    v_15474 = stack[0];
    goto v_15203;
v_15300:
    goto v_15372;
v_15364:
    v_15477 = stack[-1];
    goto v_15365;
v_15366:
    v_15476 = stack[0];
    goto v_15367;
v_15368:
    v_15475 = stack[-3];
    goto v_15369;
v_15370:
    v_15474 = stack[-2];
    goto v_15371;
v_15372:
    goto v_15364;
v_15365:
    goto v_15366;
v_15367:
    goto v_15368;
v_15369:
    goto v_15370;
v_15371:
    fn = elt(env, 4); // remainder!-in!-vector
    v_15474 = (*qfnn(fn))(fn, 4, v_15477, v_15476, v_15475, v_15474);
    env = stack[-4];
    stack[0] = v_15474;
    goto v_15385;
v_15381:
    v_15475 = stack[0];
    goto v_15382;
v_15383:
    v_15474 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15384;
v_15385:
    goto v_15381;
v_15382:
    goto v_15383;
v_15384:
    if (v_15475 == v_15474) goto v_15379;
    else goto v_15380;
v_15379:
    goto v_15394;
v_15388:
    v_15476 = stack[-3];
    goto v_15389;
v_15390:
    v_15475 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15391;
v_15392:
    v_15474 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15393;
v_15394:
    goto v_15388;
v_15389:
    goto v_15390;
v_15391:
    goto v_15392;
v_15393:
    *(LispObject *)((char *)v_15476 + (CELL-TAG_VECTOR) + (((intptr_t)v_15475-TAG_FIXNUM)/(16/CELL))) = v_15474;
    v_15474 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15203;
v_15380:
    goto v_15405;
v_15401:
    v_15475 = stack[0];
    goto v_15402;
v_15403:
    v_15474 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_15404;
v_15405:
    goto v_15401;
v_15402:
    goto v_15403;
v_15404:
    if (v_15475 == v_15474) goto v_15399;
    else goto v_15400;
v_15399:
    goto v_15413;
v_15409:
    v_15475 = stack[-3];
    goto v_15410;
v_15411:
    v_15474 = stack[-2];
    goto v_15412;
v_15413:
    goto v_15409;
v_15410:
    goto v_15411;
v_15412:
    v_15474 = *(LispObject *)((char *)v_15475 + (CELL-TAG_VECTOR) + (((intptr_t)v_15474-TAG_FIXNUM)/(16/CELL)));
    v_15474 = Lmodular_reciprocal(nil, v_15474);
    env = stack[-4];
    v_15479 = v_15474;
    goto v_15425;
v_15421:
    v_15475 = v_15479;
    goto v_15422;
v_15423:
    v_15474 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15424;
v_15425:
    goto v_15421;
v_15422:
    goto v_15423;
v_15424:
    if (v_15475 == v_15474) goto v_15420;
    v_15474 = (LispObject)0+TAG_FIXNUM; // 0
    v_15478 = v_15474;
v_15431:
    goto v_15441;
v_15437:
    v_15475 = stack[-2];
    goto v_15438;
v_15439:
    v_15474 = v_15478;
    goto v_15440;
v_15441:
    goto v_15437;
v_15438:
    goto v_15439;
v_15440:
    v_15474 = (LispObject)(intptr_t)((intptr_t)v_15475 - (intptr_t)v_15474 + TAG_FIXNUM);
    v_15474 = ((intptr_t)(v_15474) < 0 ? lisp_true : nil);
    if (v_15474 == nil) goto v_15436;
    goto v_15430;
v_15436:
    goto v_15453;
v_15447:
    v_15477 = stack[-3];
    goto v_15448;
v_15449:
    v_15476 = v_15478;
    goto v_15450;
v_15451:
    goto v_15461;
v_15457:
    goto v_15466;
v_15462:
    v_15475 = stack[-3];
    goto v_15463;
v_15464:
    v_15474 = v_15478;
    goto v_15465;
v_15466:
    goto v_15462;
v_15463:
    goto v_15464;
v_15465:
    v_15475 = *(LispObject *)((char *)v_15475 + (CELL-TAG_VECTOR) + (((intptr_t)v_15474-TAG_FIXNUM)/(16/CELL)));
    goto v_15458;
v_15459:
    v_15474 = v_15479;
    goto v_15460;
v_15461:
    goto v_15457;
v_15458:
    goto v_15459;
v_15460:
    v_15474 = Lmodular_times(nil, v_15475, v_15474);
    env = stack[-4];
    goto v_15452;
v_15453:
    goto v_15447;
v_15448:
    goto v_15449;
v_15450:
    goto v_15451;
v_15452:
    *(LispObject *)((char *)v_15477 + (CELL-TAG_VECTOR) + (((intptr_t)v_15476-TAG_FIXNUM)/(16/CELL))) = v_15474;
    v_15474 = v_15478;
    v_15474 = (LispObject)((intptr_t)(v_15474) + 0x10);
    v_15478 = v_15474;
    goto v_15431;
v_15430:
    goto v_15418;
v_15420:
v_15418:
    v_15474 = stack[-2];
    goto v_15203;
v_15400:
    goto v_15204;
v_15203:
    return onevalue(v_15474);
}



// Code for lalr_most_common_dest

static LispObject CC_lalr_most_common_dest(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15292, v_15293, v_15294;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_15292 = v_15196;
// end of prologue
    stack[-3] = nil;
    stack[-1] = v_15292;
v_15206:
    v_15292 = stack[-1];
    if (v_15292 == nil) goto v_15210;
    else goto v_15211;
v_15210:
    goto v_15205;
v_15211:
    v_15292 = stack[-1];
    v_15292 = qcar(v_15292);
    v_15294 = v_15292;
    goto v_15225;
v_15221:
    v_15292 = v_15294;
    v_15293 = qcdr(v_15292);
    goto v_15222;
v_15223:
    v_15292 = stack[-3];
    goto v_15224;
v_15225:
    goto v_15221;
v_15222:
    goto v_15223;
v_15224:
    v_15292 = Lassoc(nil, v_15293, v_15292);
    stack[-2] = v_15292;
    if (v_15292 == nil) goto v_15220;
    goto v_15235;
v_15231:
    stack[0] = stack[-2];
    goto v_15232;
v_15233:
    v_15292 = stack[-2];
    v_15292 = qcdr(v_15292);
    v_15292 = add1(v_15292);
    env = stack[-4];
    goto v_15234;
v_15235:
    goto v_15231;
v_15232:
    goto v_15233;
v_15234:
    v_15292 = Lrplacd(nil, stack[0], v_15292);
    env = stack[-4];
    goto v_15218;
v_15220:
    goto v_15249;
v_15243:
    v_15292 = v_15294;
    v_15294 = qcdr(v_15292);
    goto v_15244;
v_15245:
    v_15293 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15246;
v_15247:
    v_15292 = stack[-3];
    goto v_15248;
v_15249:
    goto v_15243;
v_15244:
    goto v_15245;
v_15246:
    goto v_15247;
v_15248:
    v_15292 = acons(v_15294, v_15293, v_15292);
    env = stack[-4];
    stack[-3] = v_15292;
    goto v_15218;
v_15218:
    v_15292 = stack[-1];
    v_15292 = qcdr(v_15292);
    stack[-1] = v_15292;
    goto v_15206;
v_15205:
    v_15292 = stack[-3];
    v_15292 = qcar(v_15292);
    stack[-2] = v_15292;
    v_15292 = stack[-3];
    v_15292 = qcdr(v_15292);
    stack[-1] = v_15292;
v_15261:
    v_15292 = stack[-1];
    if (v_15292 == nil) goto v_15266;
    else goto v_15267;
v_15266:
    goto v_15260;
v_15267:
    v_15292 = stack[-1];
    v_15292 = qcar(v_15292);
    stack[0] = v_15292;
    goto v_15282;
v_15278:
    v_15292 = stack[0];
    v_15293 = qcdr(v_15292);
    goto v_15279;
v_15280:
    v_15292 = stack[-2];
    v_15292 = qcdr(v_15292);
    goto v_15281;
v_15282:
    goto v_15278;
v_15279:
    goto v_15280;
v_15281:
    v_15292 = (LispObject)greaterp2(v_15293, v_15292);
    v_15292 = v_15292 ? lisp_true : nil;
    env = stack[-4];
    if (v_15292 == nil) goto v_15276;
    v_15292 = stack[0];
    stack[-2] = v_15292;
    goto v_15274;
v_15276:
v_15274:
    v_15292 = stack[-1];
    v_15292 = qcdr(v_15292);
    stack[-1] = v_15292;
    goto v_15261;
v_15260:
    v_15292 = stack[-2];
    v_15292 = qcar(v_15292);
    return onevalue(v_15292);
}



// Code for outrdefun

static LispObject CC_outrdefun(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15373, v_15374;
    LispObject fn;
    LispObject v_15198, v_15197, v_15196;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "outrdefun");
    va_start(aa, nargs);
    v_15196 = va_arg(aa, LispObject);
    v_15197 = va_arg(aa, LispObject);
    v_15198 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15198,v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15196,v_15197,v_15198);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15198;
    stack[-1] = v_15197;
    stack[-2] = v_15196;
// end of prologue
    goto v_15208;
v_15204:
    v_15374 = stack[-2];
    goto v_15205;
v_15206:
    v_15373 = stack[-1];
    goto v_15207;
v_15208:
    goto v_15204;
v_15205:
    goto v_15206;
v_15207:
    fn = elt(env, 14); // qtypnm
    v_15373 = (*qfn2(fn))(fn, v_15374, v_15373);
    env = stack[-4];
    stack[-2] = v_15373;
    goto v_15220;
v_15216:
    v_15374 = stack[-2];
    goto v_15217;
v_15218:
    v_15373 = elt(env, 1); // defd
    goto v_15219;
v_15220:
    goto v_15216;
v_15217:
    goto v_15218;
v_15219:
    v_15373 = Lflagp(nil, v_15374, v_15373);
    env = stack[-4];
    if (v_15373 == nil) goto v_15214;
    goto v_15228;
v_15224:
    v_15374 = stack[-2];
    goto v_15225;
v_15226:
    v_15373 = stack[-1];
    goto v_15227;
v_15228:
    goto v_15224;
v_15225:
    goto v_15226;
v_15227:
    fn = elt(env, 15); // recref
    v_15373 = (*qfn2(fn))(fn, v_15374, v_15373);
    env = stack[-4];
    goto v_15212;
v_15214:
    goto v_15238;
v_15234:
    v_15373 = stack[-2];
    v_15374 = ncons(v_15373);
    env = stack[-4];
    goto v_15235;
v_15236:
    v_15373 = elt(env, 1); // defd
    goto v_15237;
v_15238:
    goto v_15234;
v_15235:
    goto v_15236;
v_15237:
    v_15373 = Lflag(nil, v_15374, v_15373);
    env = stack[-4];
    goto v_15212;
v_15212:
    goto v_15255;
v_15251:
    v_15374 = stack[-1];
    goto v_15252;
v_15253:
    v_15373 = elt(env, 2); // function
    goto v_15254;
v_15255:
    goto v_15251;
v_15252:
    goto v_15253;
v_15254:
    v_15373 = Lflagp(nil, v_15374, v_15373);
    env = stack[-4];
    if (v_15373 == nil) goto v_15249;
    goto v_15267;
v_15263:
    v_15374 = stack[-2];
    goto v_15264;
v_15265:
    v_15373 = elt(env, 3); // dclglb
    goto v_15266;
v_15267:
    goto v_15263;
v_15264:
    goto v_15265;
v_15266:
    v_15373 = Lflagp(nil, v_15374, v_15373);
    env = stack[-4];
    if (v_15373 == nil) goto v_15261;
    v_15373 = lisp_true;
    goto v_15259;
v_15261:
    goto v_15277;
v_15273:
    v_15374 = stack[-2];
    goto v_15274;
v_15275:
    v_15373 = qvalue(elt(env, 4)); // locls!*
    goto v_15276;
v_15277:
    goto v_15273;
v_15274:
    goto v_15275;
v_15276:
    v_15373 = Lassoc(nil, v_15374, v_15373);
    goto v_15259;
    v_15373 = nil;
v_15259:
    goto v_15247;
v_15249:
    v_15373 = nil;
    goto v_15247;
    v_15373 = nil;
v_15247:
    if (v_15373 == nil) goto v_15245;
    v_15373 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 16); // qerline
    v_15373 = (*qfn1(fn))(fn, v_15373);
    env = stack[-4];
    v_15373 = elt(env, 5); // "**** Variable "
    v_15373 = Lprinc(nil, v_15373);
    env = stack[-4];
    v_15373 = stack[-2];
    fn = elt(env, 17); // princng
    v_15373 = (*qfn1(fn))(fn, v_15373);
    env = stack[-4];
    v_15373 = elt(env, 6); // " defined as function"
    v_15373 = Lprinc(nil, v_15373);
    env = stack[-4];
    v_15373 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 18); // newline
    v_15373 = (*qfn1(fn))(fn, v_15373);
    env = stack[-4];
    goto v_15243;
v_15245:
v_15243:
    v_15373 = stack[0];
    if (v_15373 == nil) goto v_15297;
    goto v_15306;
v_15302:
    v_15374 = stack[-1];
    goto v_15303;
v_15304:
    v_15373 = elt(env, 7); // naryarg
    goto v_15305;
v_15306:
    goto v_15302;
v_15303:
    goto v_15304;
v_15305:
    v_15373 = Lflagp(nil, v_15374, v_15373);
    env = stack[-4];
    if (v_15373 == nil) goto v_15300;
    else goto v_15297;
v_15300:
    goto v_15314;
v_15310:
    v_15374 = stack[-2];
    goto v_15311;
v_15312:
    v_15373 = stack[0];
    goto v_15313;
v_15314:
    goto v_15310;
v_15311:
    goto v_15312;
v_15313:
    fn = elt(env, 19); // defineargs
    v_15373 = (*qfn2(fn))(fn, v_15374, v_15373);
    env = stack[-4];
    goto v_15295;
v_15297:
    goto v_15328;
v_15324:
    v_15374 = stack[-1];
    goto v_15325;
v_15326:
    v_15373 = elt(env, 7); // naryarg
    goto v_15327;
v_15328:
    goto v_15324;
v_15325:
    goto v_15326;
v_15327:
    v_15373 = Lflagp(nil, v_15374, v_15373);
    env = stack[-4];
    if (v_15373 == nil) goto v_15322;
    goto v_15336;
v_15332:
    v_15374 = stack[-2];
    goto v_15333;
v_15334:
    v_15373 = elt(env, 8); // naryargs
    goto v_15335;
v_15336:
    goto v_15332;
v_15333:
    goto v_15334;
v_15335:
    v_15373 = Lflagp(nil, v_15374, v_15373);
    env = stack[-4];
    v_15373 = (v_15373 == nil ? lisp_true : nil);
    goto v_15320;
v_15322:
    v_15373 = nil;
    goto v_15320;
    v_15373 = nil;
v_15320:
    if (v_15373 == nil) goto v_15318;
    goto v_15348;
v_15344:
    v_15373 = stack[-2];
    v_15374 = ncons(v_15373);
    env = stack[-4];
    goto v_15345;
v_15346:
    v_15373 = elt(env, 8); // naryargs
    goto v_15347;
v_15348:
    goto v_15344;
v_15345:
    goto v_15346;
v_15347:
    v_15373 = Lflag(nil, v_15374, v_15373);
    env = stack[-4];
    goto v_15295;
v_15318:
v_15295:
    goto v_15359;
v_15353:
    stack[-3] = stack[-2];
    goto v_15354;
v_15355:
    stack[0] = elt(env, 9); // gall
    goto v_15356;
v_15357:
    goto v_15367;
v_15363:
    v_15374 = qvalue(elt(env, 10)); // curlin!*
    goto v_15364;
v_15365:
    v_15373 = stack[-1];
    goto v_15366;
v_15367:
    goto v_15363;
v_15364:
    goto v_15365;
v_15366:
    v_15373 = cons(v_15374, v_15373);
    env = stack[-4];
    goto v_15358;
v_15359:
    goto v_15353;
v_15354:
    goto v_15355;
v_15356:
    goto v_15357;
v_15358:
    v_15373 = Lputprop(nil, 3, stack[-3], stack[0], v_15373);
    env = stack[-4];
    v_15373 = nil;
    qvalue(elt(env, 11)) = v_15373; // globs!*
    v_15373 = nil;
    qvalue(elt(env, 12)) = v_15373; // calls!*
    v_15373 = stack[-2];
    qvalue(elt(env, 13)) = v_15373; // curfun!*
    return onevalue(v_15373);
}



// Code for pasf_varlat

static LispObject CC_pasf_varlat(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15298, v_15299;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15196;
// end of prologue
    goto v_15207;
v_15203:
    v_15298 = stack[0];
    v_15298 = qcdr(v_15298);
    v_15298 = qcar(v_15298);
    fn = elt(env, 4); // kernels
    stack[-1] = (*qfn1(fn))(fn, v_15298);
    env = stack[-4];
    goto v_15204;
v_15205:
    v_15298 = stack[0];
    v_15298 = Lconsp(nil, v_15298);
    env = stack[-4];
    if (v_15298 == nil) goto v_15215;
    v_15298 = stack[0];
    v_15298 = qcar(v_15298);
    v_15298 = Lconsp(nil, v_15298);
    env = stack[-4];
    if (v_15298 == nil) goto v_15215;
    goto v_15229;
v_15225:
    v_15298 = stack[0];
    v_15298 = qcar(v_15298);
    v_15299 = qcar(v_15298);
    goto v_15226;
v_15227:
    v_15298 = elt(env, 2); // (cong ncong)
    goto v_15228;
v_15229:
    goto v_15225;
v_15226:
    goto v_15227;
v_15228:
    v_15298 = Lmemq(nil, v_15299, v_15298);
    if (v_15298 == nil) goto v_15215;
    v_15298 = stack[0];
    v_15298 = qcar(v_15298);
    v_15298 = qcdr(v_15298);
    fn = elt(env, 4); // kernels
    v_15298 = (*qfn1(fn))(fn, v_15298);
    env = stack[-4];
    goto v_15213;
v_15215:
    v_15298 = nil;
    goto v_15213;
    v_15298 = nil;
v_15213:
    goto v_15206;
v_15207:
    goto v_15203;
v_15204:
    goto v_15205;
v_15206:
    v_15298 = Lappend(nil, stack[-1], v_15298);
    env = stack[-4];
    v_15299 = v_15298;
    v_15298 = qvalue(elt(env, 3)); // !*rlbrkcxk
    if (v_15298 == nil) goto v_15245;
    v_15298 = v_15299;
    stack[-3] = v_15298;
v_15252:
    v_15298 = stack[-3];
    if (v_15298 == nil) goto v_15257;
    else goto v_15258;
v_15257:
    v_15298 = nil;
    goto v_15251;
v_15258:
    v_15298 = stack[-3];
    v_15298 = qcar(v_15298);
    fn = elt(env, 5); // lto_lpvarl
    v_15298 = (*qfn1(fn))(fn, v_15298);
    env = stack[-4];
    stack[-2] = v_15298;
    v_15298 = stack[-2];
    fn = elt(env, 6); // lastpair
    v_15298 = (*qfn1(fn))(fn, v_15298);
    env = stack[-4];
    stack[-1] = v_15298;
    v_15298 = stack[-3];
    v_15298 = qcdr(v_15298);
    stack[-3] = v_15298;
    v_15298 = stack[-1];
    if (!consp(v_15298)) goto v_15272;
    else goto v_15273;
v_15272:
    goto v_15252;
v_15273:
v_15253:
    v_15298 = stack[-3];
    if (v_15298 == nil) goto v_15277;
    else goto v_15278;
v_15277:
    v_15298 = stack[-2];
    goto v_15251;
v_15278:
    goto v_15286;
v_15282:
    stack[0] = stack[-1];
    goto v_15283;
v_15284:
    v_15298 = stack[-3];
    v_15298 = qcar(v_15298);
    fn = elt(env, 5); // lto_lpvarl
    v_15298 = (*qfn1(fn))(fn, v_15298);
    env = stack[-4];
    goto v_15285;
v_15286:
    goto v_15282;
v_15283:
    goto v_15284;
v_15285:
    v_15298 = Lrplacd(nil, stack[0], v_15298);
    env = stack[-4];
    v_15298 = stack[-1];
    fn = elt(env, 6); // lastpair
    v_15298 = (*qfn1(fn))(fn, v_15298);
    env = stack[-4];
    stack[-1] = v_15298;
    v_15298 = stack[-3];
    v_15298 = qcdr(v_15298);
    stack[-3] = v_15298;
    goto v_15253;
v_15251:
    v_15299 = v_15298;
    goto v_15243;
v_15245:
v_15243:
    v_15298 = v_15299;
    return onevalue(v_15298);
}



// Code for vunion

static LispObject CC_vunion(LispObject env,
                         LispObject v_15196, LispObject v_15197)
{
    env = qenv(env);
    LispObject v_15300, v_15301;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15196,v_15197);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_15197;
    stack[-2] = v_15196;
// end of prologue
    v_15300 = stack[-2];
    if (v_15300 == nil) goto v_15205;
    else goto v_15206;
v_15205:
    v_15300 = stack[-1];
    goto v_15204;
v_15206:
    goto v_15215;
v_15211:
    v_15300 = stack[-2];
    v_15300 = qcar(v_15300);
    v_15301 = qcar(v_15300);
    goto v_15212;
v_15213:
    v_15300 = stack[-1];
    goto v_15214;
v_15215:
    goto v_15211;
v_15212:
    goto v_15213;
v_15214:
    v_15300 = Lassoc(nil, v_15301, v_15300);
    stack[-3] = v_15300;
    if (v_15300 == nil) goto v_15209;
    else goto v_15210;
v_15209:
    goto v_15226;
v_15222:
    v_15300 = stack[-2];
    stack[0] = qcar(v_15300);
    goto v_15223;
v_15224:
    goto v_15234;
v_15230:
    v_15300 = stack[-2];
    v_15301 = qcdr(v_15300);
    goto v_15231;
v_15232:
    v_15300 = stack[-1];
    goto v_15233;
v_15234:
    goto v_15230;
v_15231:
    goto v_15232;
v_15233:
    v_15300 = CC_vunion(elt(env, 0), v_15301, v_15300);
    goto v_15225;
v_15226:
    goto v_15222;
v_15223:
    goto v_15224;
v_15225:
    {
        LispObject v_15306 = stack[0];
        return cons(v_15306, v_15300);
    }
v_15210:
    goto v_15245;
v_15241:
    v_15300 = stack[-2];
    v_15300 = qcar(v_15300);
    v_15301 = qcdr(v_15300);
    goto v_15242;
v_15243:
    v_15300 = stack[-3];
    v_15300 = qcdr(v_15300);
    goto v_15244;
v_15245:
    goto v_15241;
v_15242:
    goto v_15243;
v_15244:
    v_15300 = (LispObject)greaterp2(v_15301, v_15300);
    v_15300 = v_15300 ? lisp_true : nil;
    env = stack[-4];
    if (v_15300 == nil) goto v_15239;
    goto v_15256;
v_15252:
    v_15300 = stack[-2];
    stack[0] = qcar(v_15300);
    goto v_15253;
v_15254:
    goto v_15264;
v_15260:
    v_15300 = stack[-2];
    stack[-2] = qcdr(v_15300);
    goto v_15261;
v_15262:
    goto v_15272;
v_15268:
    v_15301 = stack[-3];
    goto v_15269;
v_15270:
    v_15300 = stack[-1];
    goto v_15271;
v_15272:
    goto v_15268;
v_15269:
    goto v_15270;
v_15271:
    v_15300 = Ldelete(nil, v_15301, v_15300);
    env = stack[-4];
    goto v_15263;
v_15264:
    goto v_15260;
v_15261:
    goto v_15262;
v_15263:
    v_15300 = CC_vunion(elt(env, 0), stack[-2], v_15300);
    goto v_15255;
v_15256:
    goto v_15252;
v_15253:
    goto v_15254;
v_15255:
    {
        LispObject v_15307 = stack[0];
        return cons(v_15307, v_15300);
    }
v_15239:
    goto v_15282;
v_15278:
    stack[0] = stack[-3];
    goto v_15279;
v_15280:
    goto v_15289;
v_15285:
    v_15300 = stack[-2];
    stack[-2] = qcdr(v_15300);
    goto v_15286;
v_15287:
    goto v_15297;
v_15293:
    v_15301 = stack[-3];
    goto v_15294;
v_15295:
    v_15300 = stack[-1];
    goto v_15296;
v_15297:
    goto v_15293;
v_15294:
    goto v_15295;
v_15296:
    v_15300 = Ldelete(nil, v_15301, v_15300);
    env = stack[-4];
    goto v_15288;
v_15289:
    goto v_15285;
v_15286:
    goto v_15287;
v_15288:
    v_15300 = CC_vunion(elt(env, 0), stack[-2], v_15300);
    goto v_15281;
v_15282:
    goto v_15278;
v_15279:
    goto v_15280;
v_15281:
    {
        LispObject v_15308 = stack[0];
        return cons(v_15308, v_15300);
    }
    v_15300 = nil;
v_15204:
    return onevalue(v_15300);
}



// Code for aex_mvar

static LispObject CC_aex_mvar(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15207;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15207 = v_15196;
// end of prologue
    goto v_15201;
    goto v_15199;
v_15201:
v_15199:
    fn = elt(env, 1); // aex_ex
    v_15207 = (*qfn1(fn))(fn, v_15207);
    env = stack[0];
    v_15207 = qcar(v_15207);
    {
        fn = elt(env, 2); // sfto_mvarx
        return (*qfn1(fn))(fn, v_15207);
    }
}



// Code for multi_args

static LispObject CC_multi_args(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15213;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15196;
// end of prologue
    v_15213 = stack[0];
    if (v_15213 == nil) goto v_15204;
    v_15213 = stack[0];
    v_15213 = qcar(v_15213);
    fn = elt(env, 1); // expression
    v_15213 = (*qfn1(fn))(fn, v_15213);
    env = stack[-1];
    v_15213 = stack[0];
    v_15213 = qcdr(v_15213);
    v_15213 = CC_multi_args(elt(env, 0), v_15213);
    goto v_15202;
v_15204:
v_15202:
    v_15213 = nil;
    return onevalue(v_15213);
}



// Code for n_nary

static LispObject CC_n_nary(LispObject env,
                         LispObject v_15196, LispObject v_15197)
{
    env = qenv(env);
    LispObject v_15268, v_15269;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15196,v_15197);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15197;
    stack[-1] = v_15196;
// end of prologue
    goto v_15214;
v_15210:
    v_15268 = stack[-1];
    v_15269 = qcar(v_15268);
    goto v_15211;
v_15212:
    v_15268 = elt(env, 1); // e
    goto v_15213;
v_15214:
    goto v_15210;
v_15211:
    goto v_15212;
v_15213:
    if (v_15269 == v_15268) goto v_15208;
    else goto v_15209;
v_15208:
    goto v_15222;
v_15218:
    v_15269 = stack[0];
    goto v_15219;
v_15220:
    v_15268 = elt(env, 2); // power
    goto v_15221;
v_15222:
    goto v_15218;
v_15219:
    goto v_15220;
v_15221:
    v_15268 = (v_15269 == v_15268 ? lisp_true : nil);
    goto v_15207;
v_15209:
    v_15268 = nil;
    goto v_15207;
    v_15268 = nil;
v_15207:
    if (v_15268 == nil) goto v_15205;
    goto v_15234;
v_15230:
    v_15268 = stack[-1];
    v_15269 = qcdr(v_15268);
    goto v_15231;
v_15232:
    v_15268 = elt(env, 3); // exp
    goto v_15233;
v_15234:
    goto v_15230;
v_15231:
    goto v_15232;
v_15233:
    fn = elt(env, 9); // unary
    v_15268 = (*qfn2(fn))(fn, v_15269, v_15268);
    goto v_15203;
v_15205:
    v_15268 = elt(env, 4); // "<apply>"
    fn = elt(env, 10); // printout
    v_15268 = (*qfn1(fn))(fn, v_15268);
    env = stack[-2];
    v_15268 = elt(env, 5); // "<"
    v_15268 = Lprinc(nil, v_15268);
    env = stack[-2];
    v_15268 = stack[0];
    v_15268 = Lprinc(nil, v_15268);
    env = stack[-2];
    v_15268 = elt(env, 6); // "/>"
    v_15268 = Lprinc(nil, v_15268);
    env = stack[-2];
    goto v_15253;
v_15249:
    v_15269 = qvalue(elt(env, 7)); // indent
    goto v_15250;
v_15251:
    v_15268 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_15252;
v_15253:
    goto v_15249;
v_15250:
    goto v_15251;
v_15252:
    v_15268 = plus2(v_15269, v_15268);
    env = stack[-2];
    qvalue(elt(env, 7)) = v_15268; // indent
    v_15268 = stack[-1];
    fn = elt(env, 11); // multi_elem
    v_15268 = (*qfn1(fn))(fn, v_15268);
    env = stack[-2];
    goto v_15263;
v_15259:
    v_15269 = qvalue(elt(env, 7)); // indent
    goto v_15260;
v_15261:
    v_15268 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_15262;
v_15263:
    goto v_15259;
v_15260:
    goto v_15261;
v_15262:
    v_15268 = difference2(v_15269, v_15268);
    env = stack[-2];
    qvalue(elt(env, 7)) = v_15268; // indent
    v_15268 = elt(env, 8); // "</apply>"
    fn = elt(env, 10); // printout
    v_15268 = (*qfn1(fn))(fn, v_15268);
    goto v_15203;
v_15203:
    v_15268 = nil;
    return onevalue(v_15268);
}



// Code for simpdf!*

static LispObject CC_simpdfH(LispObject env,
                         LispObject v_15196)
{
    env = qenv(env);
    LispObject v_15223, v_15224, v_15225;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15196);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_15223 = v_15196;
// end of prologue
    fn = elt(env, 2); // simpdf
    v_15223 = (*qfn1(fn))(fn, v_15223);
    env = stack[-1];
    stack[0] = v_15223;
    v_15223 = stack[0];
    fn = elt(env, 3); // rootextractsq
    v_15223 = (*qfn1(fn))(fn, v_15223);
    env = stack[-1];
    v_15225 = v_15223;
    goto v_15215;
v_15211:
    v_15224 = v_15225;
    goto v_15212;
v_15213:
    v_15223 = stack[0];
    goto v_15214;
v_15215:
    goto v_15211;
v_15212:
    goto v_15213;
v_15214:
    if (equal(v_15224, v_15223)) goto v_15210;
    v_15223 = v_15225;
    {
        fn = elt(env, 4); // resimp
        return (*qfn1(fn))(fn, v_15223);
    }
v_15210:
    v_15223 = stack[0];
    goto v_15201;
    v_15223 = nil;
v_15201:
    return onevalue(v_15223);
}



// Code for meq

static LispObject CC_meq(LispObject env,
                         LispObject v_15196, LispObject v_15197)
{
    env = qenv(env);
    LispObject v_15227, v_15228, v_15229;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15196,v_15197);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15197;
    stack[-1] = v_15196;
// end of prologue
    v_15227 = stack[-1];
    fn = elt(env, 2); // binding
    v_15227 = (*qfn1(fn))(fn, v_15227);
    env = stack[-2];
    v_15228 = v_15227;
    goto v_15206;
v_15202:
    v_15227 = v_15228;
    if (v_15227 == nil) goto v_15210;
    goto v_15218;
v_15214:
    v_15227 = v_15228;
    goto v_15215;
v_15216:
    v_15229 = elt(env, 1); // unbound
    goto v_15217;
v_15218:
    goto v_15214;
v_15215:
    goto v_15216;
v_15217:
    if (v_15227 == v_15229) goto v_15210;
    v_15227 = v_15228;
    v_15228 = v_15227;
    goto v_15208;
v_15210:
    v_15227 = stack[-1];
    v_15228 = v_15227;
    goto v_15208;
    v_15228 = nil;
v_15208:
    goto v_15203;
v_15204:
    v_15227 = stack[0];
    goto v_15205;
v_15206:
    goto v_15202;
v_15203:
    goto v_15204;
v_15205:
    v_15227 = (equal(v_15228, v_15227) ? lisp_true : nil);
    return onevalue(v_15227);
}



// Code for dipnumcontent

static LispObject CC_dipnumcontent(LispObject env,
                         LispObject v_15196, LispObject v_15197)
{
    env = qenv(env);
    LispObject v_15229, v_15230;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15197,v_15196);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15196,v_15197);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15197;
    stack[-1] = v_15196;
// end of prologue
v_15202:
    v_15229 = stack[0];
    fn = elt(env, 1); // bcone!?
    v_15229 = (*qfn1(fn))(fn, v_15229);
    env = stack[-3];
    if (v_15229 == nil) goto v_15207;
    else goto v_15205;
v_15207:
    v_15229 = stack[-1];
    if (v_15229 == nil) goto v_15205;
    goto v_15206;
v_15205:
    v_15229 = stack[0];
    goto v_15201;
v_15206:
    v_15229 = stack[-1];
    v_15229 = qcdr(v_15229);
    v_15229 = qcdr(v_15229);
    stack[-2] = v_15229;
    goto v_15223;
v_15219:
    v_15230 = stack[0];
    goto v_15220;
v_15221:
    v_15229 = stack[-1];
    v_15229 = qcdr(v_15229);
    v_15229 = qcar(v_15229);
    goto v_15222;
v_15223:
    goto v_15219;
v_15220:
    goto v_15221;
v_15222:
    fn = elt(env, 2); // vbcgcd
    v_15229 = (*qfn2(fn))(fn, v_15230, v_15229);
    env = stack[-3];
    stack[0] = v_15229;
    v_15229 = stack[-2];
    stack[-1] = v_15229;
    goto v_15202;
    v_15229 = nil;
v_15201:
    return onevalue(v_15229);
}



setup_type const u28_setup[] =
{
    {"super_der_simp",          CC_super_der_simp,TOO_MANY_1,  WRONG_NO_1},
    {"string-of-list",          CC_stringKofKlist,TOO_MANY_1,  WRONG_NO_1},
    {"outrefend",               CC_outrefend,   TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_negateat",           CC_ofsf_negateat,TOO_MANY_1,   WRONG_NO_1},
    {"simpcv",                  TOO_FEW_2,      CC_simpcv,     WRONG_NO_2},
    {"matpri",                  CC_matpri,      TOO_MANY_1,    WRONG_NO_1},
    {"talp_telp",               TOO_FEW_2,      CC_talp_telp,  WRONG_NO_2},
    {"matrixrowom",             CC_matrixrowom, TOO_MANY_1,    WRONG_NO_1},
    {"oprinla",                 CC_oprinla,     TOO_MANY_1,    WRONG_NO_1},
    {"can_be_proved",           TOO_FEW_2,      CC_can_be_proved,WRONG_NO_2},
    {"red=subst1",              TOO_FEW_2,      CC_redMsubst1, WRONG_NO_2},
    {"evaluate-mod-p",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_evaluateKmodKp},
    {"gf2cr:",                  CC_gf2crT,      TOO_MANY_1,    WRONG_NO_1},
    {"lalr_make_compressed_goto_column",CC_lalr_make_compressed_goto_column,TOO_MANY_1,WRONG_NO_1},
    {"add2locs",                CC_add2locs,    TOO_MANY_1,    WRONG_NO_1},
    {"opmtchrevop",             CC_opmtchrevop, TOO_MANY_1,    WRONG_NO_1},
    {"get_char_value",          TOO_FEW_2,      CC_get_char_value,WRONG_NO_2},
    {"homogp",                  CC_homogp,      TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_optsubstat",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_optsubstat},
    {"unaryir",                 TOO_FEW_2,      CC_unaryir,    WRONG_NO_2},
    {"atomlis",                 CC_atomlis,     TOO_MANY_1,    WRONG_NO_1},
    {"ft:zerop",                CC_ftTzerop,    TOO_MANY_1,    WRONG_NO_1},
    {"dip2vdp",                 CC_dip2vdp,     TOO_MANY_1,    WRONG_NO_1},
    {"equalreval",              CC_equalreval,  TOO_MANY_1,    WRONG_NO_1},
    {"edge_new_parent",         CC_edge_new_parent,TOO_MANY_1, WRONG_NO_1},
    {"pcdiv",                   TOO_FEW_2,      CC_pcdiv,      WRONG_NO_2},
    {"extract_dummy_ids",       CC_extract_dummy_ids,TOO_MANY_1,WRONG_NO_1},
    {"yylex",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_yylex},
    {"aex_lc",                  TOO_FEW_2,      CC_aex_lc,     WRONG_NO_2},
    {"outref",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_outref},
    {"createtriplewithancestor",TOO_FEW_2,      CC_createtriplewithancestor,WRONG_NO_2},
    {"ofsf_smmkatl",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smmkatl},
    {"bc_2sq",                  CC_bc_2sq,      TOO_MANY_1,    WRONG_NO_1},
    {"oldmtch",                 TOO_FEW_2,      CC_oldmtch,    WRONG_NO_2},
    {"dip-nc-ev-prod1",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dipKncKevKprod1},
    {"memqcar",                 TOO_FEW_2,      CC_memqcar,    WRONG_NO_2},
    {"bfplusn",                 TOO_FEW_2,      CC_bfplusn,    WRONG_NO_2},
    {"log_assignment_list",     TOO_FEW_2,      CC_log_assignment_list,WRONG_NO_2},
    {"insert",                  TOO_FEW_2,      CC_insert,     WRONG_NO_2},
    {"sc_rep",                  CC_sc_rep,      TOO_MANY_1,    WRONG_NO_1},
    {"gcd-in-vector",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gcdKinKvector},
    {"lalr_most_common_dest",   CC_lalr_most_common_dest,TOO_MANY_1,WRONG_NO_1},
    {"outrdefun",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_outrdefun},
    {"pasf_varlat",             CC_pasf_varlat, TOO_MANY_1,    WRONG_NO_1},
    {"vunion",                  TOO_FEW_2,      CC_vunion,     WRONG_NO_2},
    {"aex_mvar",                CC_aex_mvar,    TOO_MANY_1,    WRONG_NO_1},
    {"multi_args",              CC_multi_args,  TOO_MANY_1,    WRONG_NO_1},
    {"n_nary",                  TOO_FEW_2,      CC_n_nary,     WRONG_NO_2},
    {"simpdf*",                 CC_simpdfH,     TOO_MANY_1,    WRONG_NO_1},
    {"meq",                     TOO_FEW_2,      CC_meq,        WRONG_NO_2},
    {"dipnumcontent",           TOO_FEW_2,      CC_dipnumcontent,WRONG_NO_2},
    {NULL, (one_args *)"u28", (two_args *)"97006 134541 1979393", 0}
};

// end of generated code
