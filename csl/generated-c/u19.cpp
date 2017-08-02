
// $destdir/u19.c        Machine generated C code

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



// Code for prepreform

static LispObject CC_prepreform(LispObject env,
                         LispObject v_10399)
{
    env = qenv(env);
    LispObject v_10416, v_10417;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10399);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10416 = v_10399;
// end of prologue
    goto v_10406;
v_10402:
    stack[0] = v_10416;
    goto v_10403;
v_10404:
    goto v_10413;
v_10409:
    v_10417 = qvalue(elt(env, 1)); // ordl!*
    goto v_10410;
v_10411:
    v_10416 = qvalue(elt(env, 2)); // factors!*
    goto v_10412;
v_10413:
    goto v_10409;
v_10410:
    goto v_10411;
v_10412:
    v_10416 = Lappend(nil, v_10417, v_10416);
    env = stack[-1];
    goto v_10405;
v_10406:
    goto v_10402;
v_10403:
    goto v_10404;
v_10405:
    {
        LispObject v_10419 = stack[0];
        fn = elt(env, 3); // prepreform1
        return (*qfn2(fn))(fn, v_10419, v_10416);
    }
}



// Code for wusort

static LispObject CC_wusort(LispObject env,
                         LispObject v_10399)
{
    env = qenv(env);
    LispObject v_10409, v_10410;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10409 = v_10399;
// end of prologue
    goto v_10406;
v_10402:
    v_10410 = v_10409;
    goto v_10403;
v_10404:
    v_10409 = elt(env, 1); // wulessp!*
    goto v_10405;
v_10406:
    goto v_10402;
v_10403:
    goto v_10404;
v_10405:
    {
        fn = elt(env, 2); // sort
        return (*qfn2(fn))(fn, v_10410, v_10409);
    }
}



// Code for talp_simplatat

static LispObject CC_talp_simplatat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10526, v_10527, v_10528;
    LispObject fn;
    LispObject v_10401, v_10400, v_10399;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_simplatat");
    va_start(aa, nargs);
    v_10399 = va_arg(aa, LispObject);
    v_10400 = va_arg(aa, LispObject);
    v_10401 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_10401,v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_10399,v_10400,v_10401);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_10401;
    stack[-1] = v_10400;
    stack[-2] = v_10399;
// end of prologue
    goto v_10411;
v_10407:
    v_10527 = stack[-1];
    goto v_10408;
v_10409:
    v_10526 = stack[0];
    goto v_10410;
v_10411:
    goto v_10407;
v_10408:
    goto v_10409;
v_10410:
    if (v_10527 == v_10526) goto v_10405;
    else goto v_10406;
v_10405:
    goto v_10418;
v_10414:
    v_10526 = stack[-2];
    goto v_10415;
v_10416:
    v_10527 = elt(env, 1); // equal
    goto v_10417;
v_10418:
    goto v_10414;
v_10415:
    goto v_10416;
v_10417:
    v_10526 = (v_10526 == v_10527 ? lisp_true : nil);
    goto v_10404;
v_10406:
    goto v_10428;
v_10424:
    stack[-3] = stack[-1];
    goto v_10425;
v_10426:
    fn = elt(env, 2); // talp_getl
    v_10526 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_10427;
v_10428:
    goto v_10424;
v_10425:
    goto v_10426;
v_10427:
    v_10526 = Latsoc(nil, stack[-3], v_10526);
    if (v_10526 == nil) goto v_10422;
    else goto v_10423;
v_10422:
    v_10526 = stack[0];
    if (!consp(v_10526)) goto v_10434;
    else goto v_10435;
v_10434:
    goto v_10444;
v_10438:
    v_10528 = stack[-2];
    goto v_10439;
v_10440:
    v_10527 = stack[-1];
    goto v_10441;
v_10442:
    v_10526 = stack[0];
    goto v_10443;
v_10444:
    goto v_10438;
v_10439:
    goto v_10440;
v_10441:
    goto v_10442;
v_10443:
    {
        fn = elt(env, 3); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_10528, v_10527, v_10526);
    }
v_10435:
    goto v_10455;
v_10451:
    v_10527 = stack[-1];
    goto v_10452;
v_10453:
    v_10526 = stack[0];
    goto v_10454;
v_10455:
    goto v_10451;
v_10452:
    goto v_10453;
v_10454:
    fn = elt(env, 4); // talp_telp
    v_10526 = (*qfn2(fn))(fn, v_10527, v_10526);
    env = stack[-4];
    if (v_10526 == nil) goto v_10449;
    goto v_10463;
v_10459:
    v_10526 = stack[-2];
    goto v_10460;
v_10461:
    v_10527 = elt(env, 1); // equal
    goto v_10462;
v_10463:
    goto v_10459;
v_10460:
    goto v_10461;
v_10462:
        return Lneq(nil, v_10526, v_10527);
v_10449:
    goto v_10475;
v_10469:
    v_10528 = stack[-2];
    goto v_10470;
v_10471:
    v_10527 = stack[-1];
    goto v_10472;
v_10473:
    v_10526 = stack[0];
    goto v_10474;
v_10475:
    goto v_10469;
v_10470:
    goto v_10471;
v_10472:
    goto v_10473;
v_10474:
    {
        fn = elt(env, 3); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_10528, v_10527, v_10526);
    }
    v_10526 = nil;
    goto v_10404;
v_10423:
    v_10526 = stack[0];
    if (!consp(v_10526)) goto v_10479;
    else goto v_10480;
v_10479:
    goto v_10490;
v_10486:
    stack[-3] = stack[0];
    goto v_10487;
v_10488:
    fn = elt(env, 2); // talp_getl
    v_10526 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_10489;
v_10490:
    goto v_10486;
v_10487:
    goto v_10488;
v_10489:
    v_10526 = Latsoc(nil, stack[-3], v_10526);
    if (v_10526 == nil) goto v_10484;
    else goto v_10485;
v_10484:
    goto v_10501;
v_10495:
    goto v_10496;
v_10497:
    goto v_10498;
v_10499:
    v_10526 = stack[0];
    fn = elt(env, 5); // talp_simplt
    v_10526 = (*qfn1(fn))(fn, v_10526);
    env = stack[-4];
    goto v_10500;
v_10501:
    goto v_10495;
v_10496:
    goto v_10497;
v_10498:
    goto v_10499;
v_10500:
    {
        LispObject v_10533 = stack[-2];
        LispObject v_10534 = stack[-1];
        fn = elt(env, 3); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_10533, v_10534, v_10526);
    }
v_10485:
    goto v_10513;
v_10509:
    v_10526 = stack[-2];
    goto v_10510;
v_10511:
    v_10527 = elt(env, 1); // equal
    goto v_10512;
v_10513:
    goto v_10509;
v_10510:
    goto v_10511;
v_10512:
        return Lneq(nil, v_10526, v_10527);
    v_10526 = nil;
    goto v_10404;
v_10480:
    goto v_10523;
v_10519:
    v_10526 = stack[-2];
    goto v_10520;
v_10521:
    v_10527 = elt(env, 1); // equal
    goto v_10522;
v_10523:
    goto v_10519;
v_10520:
    goto v_10521;
v_10522:
        return Lneq(nil, v_10526, v_10527);
    v_10526 = nil;
v_10404:
    return onevalue(v_10526);
}



// Code for rl_susipost

static LispObject CC_rl_susipost(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10417, v_10418;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10417 = v_10400;
    v_10418 = v_10399;
// end of prologue
    goto v_10407;
v_10403:
    stack[0] = qvalue(elt(env, 1)); // rl_susipost!*
    goto v_10404;
v_10405:
    goto v_10414;
v_10410:
    goto v_10411;
v_10412:
    goto v_10413;
v_10414:
    goto v_10410;
v_10411:
    goto v_10412;
v_10413:
    v_10417 = list2(v_10418, v_10417);
    env = stack[-1];
    goto v_10406;
v_10407:
    goto v_10403;
v_10404:
    goto v_10405;
v_10406:
    {
        LispObject v_10420 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_10420, v_10417);
    }
}



// Code for ev_sum

static LispObject CC_ev_sum(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10438, v_10439, v_10440;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10400;
    stack[-1] = v_10399;
// end of prologue
    v_10440 = nil;
v_10408:
    v_10438 = stack[-1];
    if (v_10438 == nil) goto v_10411;
    else goto v_10412;
v_10411:
    goto v_10407;
v_10412:
    goto v_10420;
v_10416:
    goto v_10425;
v_10421:
    v_10438 = stack[-1];
    v_10439 = qcar(v_10438);
    goto v_10422;
v_10423:
    v_10438 = stack[0];
    v_10438 = qcar(v_10438);
    goto v_10424;
v_10425:
    goto v_10421;
v_10422:
    goto v_10423;
v_10424:
    v_10438 = (LispObject)(intptr_t)((intptr_t)v_10439 + (intptr_t)v_10438 - TAG_FIXNUM);
    goto v_10417;
v_10418:
    v_10439 = v_10440;
    goto v_10419;
v_10420:
    goto v_10416;
v_10417:
    goto v_10418;
v_10419:
    v_10438 = cons(v_10438, v_10439);
    env = stack[-2];
    v_10440 = v_10438;
    v_10438 = stack[-1];
    v_10438 = qcdr(v_10438);
    stack[-1] = v_10438;
    v_10438 = stack[0];
    v_10438 = qcdr(v_10438);
    stack[0] = v_10438;
    goto v_10408;
v_10407:
    v_10438 = v_10440;
        return Lnreverse(nil, v_10438);
    return onevalue(v_10438);
}



// Code for sf_member

static LispObject CC_sf_member(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10456, v_10457;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10400;
    stack[-1] = v_10399;
// end of prologue
v_10398:
    v_10456 = stack[0];
    if (!consp(v_10456)) goto v_10408;
    else goto v_10409;
v_10408:
    v_10456 = lisp_true;
    goto v_10407;
v_10409:
    v_10456 = stack[0];
    v_10456 = qcar(v_10456);
    v_10456 = (consp(v_10456) ? nil : lisp_true);
    goto v_10407;
    v_10456 = nil;
v_10407:
    if (v_10456 == nil) goto v_10404;
    else goto v_10405;
v_10404:
    goto v_10425;
v_10421:
    v_10457 = stack[-1];
    goto v_10422;
v_10423:
    v_10456 = stack[0];
    v_10456 = qcar(v_10456);
    v_10456 = qcar(v_10456);
    v_10456 = qcar(v_10456);
    goto v_10424;
v_10425:
    goto v_10421;
v_10422:
    goto v_10423;
v_10424:
    fn = elt(env, 1); // mvar_member
    v_10456 = (*qfn2(fn))(fn, v_10457, v_10456);
    env = stack[-2];
    if (v_10456 == nil) goto v_10419;
    else goto v_10418;
v_10419:
    goto v_10439;
v_10435:
    v_10457 = stack[-1];
    goto v_10436;
v_10437:
    v_10456 = stack[0];
    v_10456 = qcar(v_10456);
    v_10456 = qcdr(v_10456);
    goto v_10438;
v_10439:
    goto v_10435;
v_10436:
    goto v_10437;
v_10438:
    v_10456 = CC_sf_member(elt(env, 0), v_10457, v_10456);
    env = stack[-2];
    if (v_10456 == nil) goto v_10433;
    else goto v_10432;
v_10433:
    goto v_10449;
v_10445:
    v_10457 = stack[-1];
    goto v_10446;
v_10447:
    v_10456 = stack[0];
    v_10456 = qcdr(v_10456);
    goto v_10448;
v_10449:
    goto v_10445;
v_10446:
    goto v_10447;
v_10448:
    stack[-1] = v_10457;
    stack[0] = v_10456;
    goto v_10398;
v_10432:
v_10418:
    goto v_10403;
v_10405:
    v_10456 = nil;
    goto v_10403;
    v_10456 = nil;
v_10403:
    return onevalue(v_10456);
}



// Code for nary

static LispObject CC_nary(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10467, v_10468;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10400;
    stack[-1] = v_10399;
// end of prologue
    goto v_10417;
v_10413:
    v_10467 = stack[-1];
    v_10468 = qcar(v_10467);
    goto v_10414;
v_10415:
    v_10467 = elt(env, 1); // e
    goto v_10416;
v_10417:
    goto v_10413;
v_10414:
    goto v_10415;
v_10416:
    if (v_10468 == v_10467) goto v_10411;
    else goto v_10412;
v_10411:
    goto v_10425;
v_10421:
    v_10468 = stack[0];
    goto v_10422;
v_10423:
    v_10467 = elt(env, 2); // power
    goto v_10424;
v_10425:
    goto v_10421;
v_10422:
    goto v_10423;
v_10424:
    v_10467 = (v_10468 == v_10467 ? lisp_true : nil);
    goto v_10410;
v_10412:
    v_10467 = nil;
    goto v_10410;
    v_10467 = nil;
v_10410:
    if (v_10467 == nil) goto v_10408;
    goto v_10437;
v_10433:
    v_10467 = stack[-1];
    v_10468 = qcdr(v_10467);
    goto v_10434;
v_10435:
    v_10467 = elt(env, 3); // exp
    goto v_10436;
v_10437:
    goto v_10433;
v_10434:
    goto v_10435;
v_10436:
    fn = elt(env, 8); // unary
    v_10467 = (*qfn2(fn))(fn, v_10468, v_10467);
    goto v_10406;
v_10408:
    v_10467 = elt(env, 4); // "<apply>"
    fn = elt(env, 9); // printout
    v_10467 = (*qfn1(fn))(fn, v_10467);
    env = stack[-2];
    v_10467 = elt(env, 5); // "<"
    v_10467 = Lprinc(nil, v_10467);
    env = stack[-2];
    v_10467 = stack[0];
    v_10467 = Lprinc(nil, v_10467);
    env = stack[-2];
    goto v_10454;
v_10450:
    v_10467 = stack[-1];
    v_10468 = qcar(v_10467);
    goto v_10451;
v_10452:
    v_10467 = elt(env, 6); // "/"
    goto v_10453;
v_10454:
    goto v_10450;
v_10451:
    goto v_10452;
v_10453:
    fn = elt(env, 10); // attributesml
    v_10467 = (*qfn2(fn))(fn, v_10468, v_10467);
    env = stack[-2];
    v_10467 = lisp_true;
    fn = elt(env, 11); // indent!*
    v_10467 = (*qfn1(fn))(fn, v_10467);
    env = stack[-2];
    v_10467 = stack[-1];
    v_10467 = qcdr(v_10467);
    fn = elt(env, 12); // multi_elem
    v_10467 = (*qfn1(fn))(fn, v_10467);
    env = stack[-2];
    v_10467 = nil;
    fn = elt(env, 11); // indent!*
    v_10467 = (*qfn1(fn))(fn, v_10467);
    env = stack[-2];
    v_10467 = elt(env, 7); // "</apply>"
    fn = elt(env, 9); // printout
    v_10467 = (*qfn1(fn))(fn, v_10467);
    goto v_10406;
v_10406:
    v_10467 = nil;
    return onevalue(v_10467);
}



// Code for inshisto

static LispObject CC_inshisto(LispObject env,
                         LispObject v_10399)
{
    env = qenv(env);
    LispObject v_10564, v_10565, v_10566;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10399);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_10399;
// end of prologue
    goto v_10410;
v_10406:
    goto v_10415;
v_10411:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_10412;
v_10413:
    goto v_10422;
v_10418:
    v_10565 = qvalue(elt(env, 2)); // maxvar
    goto v_10419;
v_10420:
    v_10564 = stack[-3];
    goto v_10421;
v_10422:
    goto v_10418;
v_10419:
    goto v_10420;
v_10421:
    v_10564 = plus2(v_10565, v_10564);
    env = stack[-5];
    goto v_10414;
v_10415:
    goto v_10411;
v_10412:
    goto v_10413;
v_10414:
    v_10565 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_10564-TAG_FIXNUM)/(16/CELL)));
    goto v_10407;
v_10408:
    v_10564 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10409;
v_10410:
    goto v_10406;
v_10407:
    goto v_10408;
v_10409:
    v_10564 = *(LispObject *)((char *)v_10565 + (CELL-TAG_VECTOR) + (((intptr_t)v_10564-TAG_FIXNUM)/(16/CELL)));
    if (v_10564 == nil) goto v_10404;
    goto v_10434;
v_10430:
    v_10565 = stack[-3];
    goto v_10431;
v_10432:
    v_10564 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10433;
v_10434:
    goto v_10430;
v_10431:
    goto v_10432;
v_10433:
    v_10564 = (LispObject)geq2(v_10565, v_10564);
    v_10564 = v_10564 ? lisp_true : nil;
    env = stack[-5];
    if (v_10564 == nil) goto v_10404;
    goto v_10450;
v_10446:
    stack[0] = qvalue(elt(env, 4)); // codhisto
    goto v_10447;
v_10448:
    goto v_10457;
v_10453:
    goto v_10462;
v_10458:
    goto v_10467;
v_10463:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_10464;
v_10465:
    goto v_10474;
v_10470:
    v_10565 = qvalue(elt(env, 2)); // maxvar
    goto v_10471;
v_10472:
    v_10564 = stack[-3];
    goto v_10473;
v_10474:
    goto v_10470;
v_10471:
    goto v_10472;
v_10473:
    v_10564 = plus2(v_10565, v_10564);
    env = stack[-5];
    goto v_10466;
v_10467:
    goto v_10463;
v_10464:
    goto v_10465;
v_10466:
    v_10565 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_10564-TAG_FIXNUM)/(16/CELL)));
    goto v_10459;
v_10460:
    v_10564 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10461;
v_10462:
    goto v_10458;
v_10459:
    goto v_10460;
v_10461:
    v_10564 = *(LispObject *)((char *)v_10565 + (CELL-TAG_VECTOR) + (((intptr_t)v_10564-TAG_FIXNUM)/(16/CELL)));
    v_10565 = qcdr(v_10564);
    goto v_10454;
v_10455:
    v_10564 = (LispObject)3200+TAG_FIXNUM; // 200
    goto v_10456;
v_10457:
    goto v_10453;
v_10454:
    goto v_10455;
v_10456:
    fn = elt(env, 6); // min
    v_10564 = (*qfn2(fn))(fn, v_10565, v_10564);
    env = stack[-5];
    stack[-2] = v_10564;
    goto v_10449;
v_10450:
    goto v_10446;
v_10447:
    goto v_10448;
v_10449:
    v_10564 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_10564-TAG_FIXNUM)/(16/CELL)));
    stack[-4] = v_10564;
    if (v_10564 == nil) goto v_10445;
    goto v_10488;
v_10484:
    goto v_10493;
v_10489:
    goto v_10498;
v_10494:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_10495;
v_10496:
    goto v_10505;
v_10501:
    v_10565 = qvalue(elt(env, 2)); // maxvar
    goto v_10502;
v_10503:
    v_10564 = stack[-4];
    goto v_10504;
v_10505:
    goto v_10501;
v_10502:
    goto v_10503;
v_10504:
    v_10564 = plus2(v_10565, v_10564);
    env = stack[-5];
    goto v_10497;
v_10498:
    goto v_10494;
v_10495:
    goto v_10496;
v_10497:
    v_10565 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_10564-TAG_FIXNUM)/(16/CELL)));
    goto v_10490;
v_10491:
    v_10564 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_10492;
v_10493:
    goto v_10489;
v_10490:
    goto v_10491;
v_10492:
    v_10565 = *(LispObject *)((char *)v_10565 + (CELL-TAG_VECTOR) + (((intptr_t)v_10564-TAG_FIXNUM)/(16/CELL)));
    goto v_10485;
v_10486:
    v_10564 = stack[-3];
    goto v_10487;
v_10488:
    goto v_10484;
v_10485:
    goto v_10486;
v_10487:
    v_10564 = Lrplaca(nil, v_10565, v_10564);
    env = stack[-5];
    goto v_10443;
v_10445:
    goto v_10519;
v_10515:
    v_10565 = stack[-2];
    goto v_10516;
v_10517:
    v_10564 = qvalue(elt(env, 5)); // headhisto
    goto v_10518;
v_10519:
    goto v_10515;
v_10516:
    goto v_10517;
v_10518:
    v_10564 = (LispObject)greaterp2(v_10565, v_10564);
    v_10564 = v_10564 ? lisp_true : nil;
    env = stack[-5];
    if (v_10564 == nil) goto v_10513;
    v_10564 = stack[-2];
    qvalue(elt(env, 5)) = v_10564; // headhisto
    goto v_10443;
v_10513:
v_10443:
    goto v_10529;
v_10523:
    goto v_10534;
v_10530:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_10531;
v_10532:
    goto v_10541;
v_10537:
    v_10565 = qvalue(elt(env, 2)); // maxvar
    goto v_10538;
v_10539:
    v_10564 = stack[-3];
    goto v_10540;
v_10541:
    goto v_10537;
v_10538:
    goto v_10539;
v_10540:
    v_10564 = plus2(v_10565, v_10564);
    env = stack[-5];
    goto v_10533;
v_10534:
    goto v_10530;
v_10531:
    goto v_10532;
v_10533:
    stack[-1] = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_10564-TAG_FIXNUM)/(16/CELL)));
    goto v_10524;
v_10525:
    stack[0] = (LispObject)112+TAG_FIXNUM; // 7
    goto v_10526;
v_10527:
    goto v_10551;
v_10547:
    v_10565 = nil;
    goto v_10548;
v_10549:
    v_10564 = stack[-4];
    goto v_10550;
v_10551:
    goto v_10547;
v_10548:
    goto v_10549;
v_10550:
    v_10564 = cons(v_10565, v_10564);
    env = stack[-5];
    goto v_10528;
v_10529:
    goto v_10523;
v_10524:
    goto v_10525;
v_10526:
    goto v_10527;
v_10528:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_10564;
    goto v_10560;
v_10554:
    v_10566 = qvalue(elt(env, 4)); // codhisto
    goto v_10555;
v_10556:
    v_10565 = stack[-2];
    goto v_10557;
v_10558:
    v_10564 = stack[-3];
    goto v_10559;
v_10560:
    goto v_10554;
v_10555:
    goto v_10556;
v_10557:
    goto v_10558;
v_10559:
    *(LispObject *)((char *)v_10566 + (CELL-TAG_VECTOR) + (((intptr_t)v_10565-TAG_FIXNUM)/(16/CELL))) = v_10564;
    v_10564 = nil;
    goto v_10402;
v_10404:
    v_10564 = nil;
v_10402:
    return onevalue(v_10564);
}



// Code for deleteall

static LispObject CC_deleteall(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10438, v_10439, v_10440, v_10441;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10400;
    stack[-1] = v_10399;
// end of prologue
    v_10440 = nil;
v_10406:
    v_10438 = stack[0];
    if (v_10438 == nil) goto v_10410;
    else goto v_10411;
v_10410:
    v_10438 = v_10440;
    goto v_10405;
v_10411:
    v_10438 = stack[0];
    v_10438 = qcar(v_10438);
    v_10441 = v_10438;
    v_10438 = stack[0];
    v_10438 = qcdr(v_10438);
    stack[0] = v_10438;
    goto v_10426;
v_10422:
    v_10439 = v_10441;
    goto v_10423;
v_10424:
    v_10438 = stack[-1];
    goto v_10425;
v_10426:
    goto v_10422;
v_10423:
    goto v_10424;
v_10425:
    if (equal(v_10439, v_10438)) goto v_10421;
    goto v_10434;
v_10430:
    stack[-2] = v_10440;
    goto v_10431;
v_10432:
    v_10438 = v_10441;
    v_10438 = ncons(v_10438);
    env = stack[-3];
    goto v_10433;
v_10434:
    goto v_10430;
v_10431:
    goto v_10432;
v_10433:
    v_10438 = Lnconc(nil, stack[-2], v_10438);
    env = stack[-3];
    v_10440 = v_10438;
    goto v_10419;
v_10421:
v_10419:
    goto v_10406;
v_10405:
    return onevalue(v_10438);
}



// Code for copyd

static LispObject CC_copyd(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10496, v_10497, v_10498;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_10400;
    stack[-2] = v_10399;
// end of prologue
    v_10496 = stack[-1];
    fn = elt(env, 6); // getd
    v_10496 = (*qfn1(fn))(fn, v_10496);
    env = stack[-4];
    v_10497 = v_10496;
    if (v_10497 == nil) goto v_10410;
    else goto v_10411;
v_10410:
    goto v_10421;
v_10417:
    v_10497 = qvalue(elt(env, 2)); // !*savedef
    goto v_10418;
v_10419:
    v_10496 = elt(env, 2); // !*savedef
    goto v_10420;
v_10421:
    goto v_10417;
v_10418:
    goto v_10419;
v_10420:
    if (v_10497 == v_10496) goto v_10416;
    goto v_10431;
v_10425:
    stack[-3] = elt(env, 3); // rlisp
    goto v_10426;
v_10427:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10428;
v_10429:
    goto v_10439;
v_10435:
    v_10497 = stack[-1];
    goto v_10436;
v_10437:
    v_10496 = elt(env, 4); // "has no definition in copyd"
    goto v_10438;
v_10439:
    goto v_10435;
v_10436:
    goto v_10437;
v_10438:
    v_10496 = list2(v_10497, v_10496);
    env = stack[-4];
    goto v_10430;
v_10431:
    goto v_10425;
v_10426:
    goto v_10427;
v_10428:
    goto v_10429;
v_10430:
    fn = elt(env, 7); // rerror
    v_10496 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_10496);
    env = stack[-4];
    goto v_10414;
v_10416:
v_10414:
    goto v_10409;
v_10411:
    goto v_10451;
v_10445:
    v_10498 = stack[-2];
    goto v_10446;
v_10447:
    v_10497 = v_10496;
    v_10497 = qcar(v_10497);
    goto v_10448;
v_10449:
    v_10496 = qcdr(v_10496);
    goto v_10450;
v_10451:
    goto v_10445;
v_10446:
    goto v_10447;
v_10448:
    goto v_10449;
v_10450:
    fn = elt(env, 8); // putd
    v_10496 = (*qfnn(fn))(fn, 3, v_10498, v_10497, v_10496);
    env = stack[-4];
    v_10496 = stack[-1];
    if (!symbolp(v_10496)) v_10496 = nil;
    else { v_10496 = qfastgets(v_10496);
           if (v_10496 != nil) { v_10496 = elt(v_10496, 1); // lose
#ifdef RECORD_GET
             if (v_10496 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v_10496 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v_10496 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v_10496 == SPID_NOPROP) v_10496 = nil; else v_10496 = lisp_true; }}
#endif
    if (v_10496 == nil) goto v_10460;
    goto v_10468;
v_10464:
    v_10496 = stack[-2];
    v_10497 = ncons(v_10496);
    env = stack[-4];
    goto v_10465;
v_10466:
    v_10496 = elt(env, 5); // lose
    goto v_10467;
v_10468:
    goto v_10464;
v_10465:
    goto v_10466;
v_10467:
    v_10496 = Lflag(nil, v_10497, v_10496);
    env = stack[-4];
    goto v_10458;
v_10460:
v_10458:
    goto v_10409;
v_10409:
    goto v_10481;
v_10477:
    v_10497 = stack[-1];
    goto v_10478;
v_10479:
    v_10496 = elt(env, 2); // !*savedef
    goto v_10480;
v_10481:
    goto v_10477;
v_10478:
    goto v_10479;
v_10480:
    v_10497 = get(v_10497, v_10496);
    env = stack[-4];
    v_10496 = v_10497;
    if (v_10497 == nil) goto v_10475;
    goto v_10491;
v_10485:
    v_10498 = stack[-2];
    goto v_10486;
v_10487:
    v_10497 = elt(env, 2); // !*savedef
    goto v_10488;
v_10489:
    goto v_10490;
v_10491:
    goto v_10485;
v_10486:
    goto v_10487;
v_10488:
    goto v_10489;
v_10490:
    v_10496 = Lputprop(nil, 3, v_10498, v_10497, v_10496);
    goto v_10473;
v_10475:
v_10473:
    v_10496 = stack[-2];
    return onevalue(v_10496);
}



// Code for mo_from_a

static LispObject CC_mo_from_a(LispObject env,
                         LispObject v_10399)
{
    env = qenv(env);
    LispObject v_10508, v_10509;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10399);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_10399;
// end of prologue
    goto v_10409;
v_10405:
    stack[0] = stack[-3];
    goto v_10406;
v_10407:
    v_10508 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 4); // ring_all_names
    v_10508 = (*qfn1(fn))(fn, v_10508);
    env = stack[-5];
    goto v_10408;
v_10409:
    goto v_10405;
v_10406:
    goto v_10407;
v_10408:
    v_10508 = Lmember(nil, stack[0], v_10508);
    if (v_10508 == nil) goto v_10403;
    else goto v_10404;
v_10403:
    goto v_10419;
v_10415:
    v_10509 = stack[-3];
    goto v_10416;
v_10417:
    v_10508 = elt(env, 2); // "dpoly variable"
    goto v_10418;
v_10419:
    goto v_10415;
v_10416:
    goto v_10417;
v_10418:
    {
        fn = elt(env, 5); // typerr
        return (*qfn2(fn))(fn, v_10509, v_10508);
    }
v_10404:
    v_10508 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 4); // ring_all_names
    v_10508 = (*qfn1(fn))(fn, v_10508);
    env = stack[-5];
    stack[-4] = v_10508;
    v_10508 = stack[-4];
    if (v_10508 == nil) goto v_10440;
    else goto v_10441;
v_10440:
    v_10508 = nil;
    goto v_10434;
v_10441:
    v_10508 = stack[-4];
    v_10508 = qcar(v_10508);
    goto v_10456;
v_10452:
    v_10509 = v_10508;
    goto v_10453;
v_10454:
    v_10508 = stack[-3];
    goto v_10455;
v_10456:
    goto v_10452;
v_10453:
    goto v_10454;
v_10455:
    if (equal(v_10509, v_10508)) goto v_10450;
    else goto v_10451;
v_10450:
    v_10508 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10449;
v_10451:
    v_10508 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10449;
    v_10508 = nil;
v_10449:
    v_10508 = ncons(v_10508);
    env = stack[-5];
    stack[-1] = v_10508;
    stack[-2] = v_10508;
v_10435:
    v_10508 = stack[-4];
    v_10508 = qcdr(v_10508);
    stack[-4] = v_10508;
    v_10508 = stack[-4];
    if (v_10508 == nil) goto v_10467;
    else goto v_10468;
v_10467:
    v_10508 = stack[-2];
    goto v_10434;
v_10468:
    goto v_10476;
v_10472:
    stack[0] = stack[-1];
    goto v_10473;
v_10474:
    v_10508 = stack[-4];
    v_10508 = qcar(v_10508);
    goto v_10490;
v_10486:
    v_10509 = v_10508;
    goto v_10487;
v_10488:
    v_10508 = stack[-3];
    goto v_10489;
v_10490:
    goto v_10486;
v_10487:
    goto v_10488;
v_10489:
    if (equal(v_10509, v_10508)) goto v_10484;
    else goto v_10485;
v_10484:
    v_10508 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10483;
v_10485:
    v_10508 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10483;
    v_10508 = nil;
v_10483:
    v_10508 = ncons(v_10508);
    env = stack[-5];
    goto v_10475;
v_10476:
    goto v_10472;
v_10473:
    goto v_10474;
v_10475:
    v_10508 = Lrplacd(nil, stack[0], v_10508);
    env = stack[-5];
    v_10508 = stack[-1];
    v_10508 = qcdr(v_10508);
    stack[-1] = v_10508;
    goto v_10435;
v_10434:
    fn = elt(env, 6); // mo!=shorten
    v_10508 = (*qfn1(fn))(fn, v_10508);
    env = stack[-5];
    goto v_10504;
v_10500:
    stack[0] = v_10508;
    goto v_10501;
v_10502:
    fn = elt(env, 7); // mo!=deglist
    v_10508 = (*qfn1(fn))(fn, v_10508);
    goto v_10503;
v_10504:
    goto v_10500;
v_10501:
    goto v_10502;
v_10503:
    {
        LispObject v_10515 = stack[0];
        return cons(v_10515, v_10508);
    }
    goto v_10402;
    v_10508 = nil;
v_10402:
    return onevalue(v_10508);
}



// Code for general!-reduce!-degree!-mod!-p

static LispObject CC_generalKreduceKdegreeKmodKp(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10498, v_10499, v_10500;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10400;
    stack[-1] = v_10399;
// end of prologue
    goto v_10412;
v_10408:
    v_10498 = stack[-1];
    v_10498 = qcar(v_10498);
    v_10498 = qcdr(v_10498);
    fn = elt(env, 2); // general!-modular!-minus
    v_10499 = (*qfn1(fn))(fn, v_10498);
    env = stack[-3];
    goto v_10409;
v_10410:
    v_10498 = stack[0];
    v_10498 = qcar(v_10498);
    v_10498 = qcdr(v_10498);
    goto v_10411;
v_10412:
    goto v_10408;
v_10409:
    goto v_10410;
v_10411:
    fn = elt(env, 3); // general!-modular!-quotient
    v_10498 = (*qfn2(fn))(fn, v_10499, v_10498);
    env = stack[-3];
    stack[-2] = v_10498;
    goto v_10424;
v_10420:
    v_10498 = stack[-1];
    v_10498 = qcar(v_10498);
    v_10498 = qcar(v_10498);
    v_10499 = qcdr(v_10498);
    goto v_10421;
v_10422:
    v_10498 = stack[0];
    v_10498 = qcar(v_10498);
    v_10498 = qcar(v_10498);
    v_10498 = qcdr(v_10498);
    goto v_10423;
v_10424:
    goto v_10420;
v_10421:
    goto v_10422;
v_10423:
    v_10498 = (LispObject)(intptr_t)((intptr_t)v_10499 - (intptr_t)v_10498 + TAG_FIXNUM);
    v_10500 = v_10498;
    goto v_10442;
v_10438:
    v_10499 = v_10500;
    goto v_10439;
v_10440:
    v_10498 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10441;
v_10442:
    goto v_10438;
v_10439:
    goto v_10440;
v_10441:
    if (v_10499 == v_10498) goto v_10436;
    else goto v_10437;
v_10436:
    goto v_10450;
v_10446:
    v_10498 = stack[-1];
    stack[-1] = qcdr(v_10498);
    goto v_10447;
v_10448:
    goto v_10458;
v_10454:
    v_10498 = stack[0];
    v_10499 = qcdr(v_10498);
    goto v_10455;
v_10456:
    v_10498 = stack[-2];
    goto v_10457;
v_10458:
    goto v_10454;
v_10455:
    goto v_10456;
v_10457:
    fn = elt(env, 4); // general!-multiply!-by!-constant!-mod!-p
    v_10498 = (*qfn2(fn))(fn, v_10499, v_10498);
    env = stack[-3];
    goto v_10449;
v_10450:
    goto v_10446;
v_10447:
    goto v_10448;
v_10449:
    {
        LispObject v_10504 = stack[-1];
        fn = elt(env, 5); // general!-plus!-mod!-p
        return (*qfn2(fn))(fn, v_10504, v_10498);
    }
v_10437:
    goto v_10469;
v_10465:
    v_10498 = stack[-1];
    stack[-1] = qcdr(v_10498);
    goto v_10466;
v_10467:
    goto v_10477;
v_10473:
    goto v_10483;
v_10479:
    goto v_10489;
v_10485:
    v_10498 = stack[0];
    v_10498 = qcar(v_10498);
    v_10498 = qcar(v_10498);
    v_10498 = qcar(v_10498);
    goto v_10486;
v_10487:
    v_10499 = v_10500;
    goto v_10488;
v_10489:
    goto v_10485;
v_10486:
    goto v_10487;
v_10488:
    fn = elt(env, 6); // mksp
    v_10499 = (*qfn2(fn))(fn, v_10498, v_10499);
    env = stack[-3];
    goto v_10480;
v_10481:
    v_10498 = stack[-2];
    goto v_10482;
v_10483:
    goto v_10479;
v_10480:
    goto v_10481;
v_10482:
    v_10499 = cons(v_10499, v_10498);
    env = stack[-3];
    goto v_10474;
v_10475:
    v_10498 = stack[0];
    v_10498 = qcdr(v_10498);
    goto v_10476;
v_10477:
    goto v_10473;
v_10474:
    goto v_10475;
v_10476:
    fn = elt(env, 7); // general!-times!-term!-mod!-p
    v_10498 = (*qfn2(fn))(fn, v_10499, v_10498);
    env = stack[-3];
    goto v_10468;
v_10469:
    goto v_10465;
v_10466:
    goto v_10467;
v_10468:
    {
        LispObject v_10505 = stack[-1];
        fn = elt(env, 5); // general!-plus!-mod!-p
        return (*qfn2(fn))(fn, v_10505, v_10498);
    }
    v_10498 = nil;
    return onevalue(v_10498);
}



// Code for simplify!-filename

static LispObject CC_simplifyKfilename(LispObject env,
                         LispObject v_10399)
{
    env = qenv(env);
    LispObject v_10450, v_10451;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10399);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_10399;
// end of prologue
    v_10450 = stack[-1];
    v_10450 = Lexplodec(nil, v_10450);
    env = stack[-3];
    stack[-2] = v_10450;
    v_10450 = elt(env, 2); // "/packages/"
    v_10450 = Lexplodec(nil, v_10450);
    env = stack[-3];
    stack[0] = v_10450;
v_10412:
    v_10450 = stack[-2];
    if (v_10450 == nil) goto v_10415;
    goto v_10425;
v_10421:
    v_10451 = stack[-2];
    goto v_10422;
v_10423:
    v_10450 = stack[0];
    goto v_10424;
v_10425:
    goto v_10421;
v_10422:
    goto v_10423;
v_10424:
    fn = elt(env, 3); // starts!-with
    v_10450 = (*qfn2(fn))(fn, v_10451, v_10450);
    env = stack[-3];
    if (v_10450 == nil) goto v_10419;
    else goto v_10415;
v_10419:
    goto v_10416;
v_10415:
    goto v_10411;
v_10416:
    v_10450 = stack[-2];
    v_10450 = qcdr(v_10450);
    stack[-2] = v_10450;
    goto v_10412;
v_10411:
    v_10450 = stack[-2];
    if (v_10450 == nil) goto v_10433;
    else goto v_10434;
v_10433:
    v_10450 = stack[-1];
    goto v_10404;
v_10434:
    v_10450 = stack[-2];
    v_10450 = qcdr(v_10450);
    v_10450 = qcdr(v_10450);
    v_10450 = qcdr(v_10450);
    v_10450 = qcdr(v_10450);
    v_10450 = qcdr(v_10450);
    v_10450 = qcdr(v_10450);
    v_10450 = qcdr(v_10450);
    v_10450 = qcdr(v_10450);
    v_10450 = qcdr(v_10450);
    v_10450 = qcdr(v_10450);
    stack[-2] = v_10450;
    v_10450 = stack[-2];
    {
        fn = elt(env, 4); // list2string
        return (*qfn1(fn))(fn, v_10450);
    }
v_10404:
    return onevalue(v_10450);
}



// Code for polynomheadreduceby

static LispObject CC_polynomheadreduceby(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10467, v_10468;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_10400;
    stack[-2] = v_10399;
// end of prologue
    stack[-3] = nil;
v_10409:
    v_10467 = stack[-2];
    v_10467 = qcar(v_10467);
    if (v_10467 == nil) goto v_10412;
    v_10467 = stack[-3];
    if (v_10467 == nil) goto v_10417;
    else goto v_10412;
v_10417:
    goto v_10413;
v_10412:
    goto v_10408;
v_10413:
    goto v_10429;
v_10425:
    v_10467 = stack[-2];
    v_10468 = qcar(v_10467);
    goto v_10426;
v_10427:
    v_10467 = stack[-1];
    v_10467 = qcar(v_10467);
    goto v_10428;
v_10429:
    goto v_10425;
v_10426:
    goto v_10427;
v_10428:
    fn = elt(env, 3); // monomisdivisibleby
    v_10467 = (*qfn2(fn))(fn, v_10468, v_10467);
    env = stack[-4];
    if (v_10467 == nil) goto v_10423;
    goto v_10439;
v_10435:
    v_10467 = stack[-2];
    v_10468 = qcar(v_10467);
    goto v_10436;
v_10437:
    v_10467 = stack[-1];
    v_10467 = qcar(v_10467);
    goto v_10438;
v_10439:
    goto v_10435;
v_10436:
    goto v_10437;
v_10438:
    fn = elt(env, 4); // monomdivide
    v_10467 = (*qfn2(fn))(fn, v_10468, v_10467);
    env = stack[-4];
    goto v_10449;
v_10445:
    stack[0] = stack[-2];
    goto v_10446;
v_10447:
    goto v_10456;
v_10452:
    v_10468 = stack[-1];
    goto v_10453;
v_10454:
    goto v_10455;
v_10456:
    goto v_10452;
v_10453:
    goto v_10454;
v_10455:
    fn = elt(env, 5); // polynommultiplybymonom
    v_10467 = (*qfn2(fn))(fn, v_10468, v_10467);
    env = stack[-4];
    goto v_10448;
v_10449:
    goto v_10445;
v_10446:
    goto v_10447;
v_10448:
    fn = elt(env, 6); // polynomadd
    v_10467 = (*qfn2(fn))(fn, stack[0], v_10467);
    env = stack[-4];
    goto v_10421;
v_10423:
    v_10467 = lisp_true;
    stack[-3] = v_10467;
    goto v_10421;
v_10421:
    goto v_10409;
v_10408:
    v_10467 = qvalue(elt(env, 2)); // fluidbibasisreductionsmade
    v_10467 = (LispObject)((intptr_t)(v_10467) + 0x10);
    qvalue(elt(env, 2)) = v_10467; // fluidbibasisreductionsmade
    v_10467 = nil;
    return onevalue(v_10467);
}



// Code for rl_subat

static LispObject CC_rl_subat(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10417, v_10418;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10417 = v_10400;
    v_10418 = v_10399;
// end of prologue
    goto v_10407;
v_10403:
    stack[0] = qvalue(elt(env, 1)); // rl_subat!*
    goto v_10404;
v_10405:
    goto v_10414;
v_10410:
    goto v_10411;
v_10412:
    goto v_10413;
v_10414:
    goto v_10410;
v_10411:
    goto v_10412;
v_10413:
    v_10417 = list2(v_10418, v_10417);
    env = stack[-1];
    goto v_10406;
v_10407:
    goto v_10403;
v_10404:
    goto v_10405;
v_10406:
    {
        LispObject v_10420 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_10420, v_10417);
    }
}



// Code for ibalp_initwl

static LispObject CC_ibalp_initwl(LispObject env,
                         LispObject v_10399)
{
    env = qenv(env);
    LispObject v_10640, v_10641;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10399);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_10640 = v_10399;
// end of prologue
    stack[-4] = nil;
    stack[-2] = v_10640;
v_10410:
    v_10640 = stack[-2];
    if (v_10640 == nil) goto v_10414;
    else goto v_10415;
v_10414:
    goto v_10409;
v_10415:
    v_10640 = stack[-2];
    v_10640 = qcar(v_10640);
    stack[-1] = v_10640;
    v_10640 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_10640;
    v_10640 = stack[-1];
    v_10640 = qcar(v_10640);
    stack[-3] = v_10640;
v_10426:
    goto v_10440;
v_10436:
    v_10641 = stack[-5];
    goto v_10437;
v_10438:
    v_10640 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10439;
v_10440:
    goto v_10436;
v_10437:
    goto v_10438;
v_10439:
    v_10640 = Leqn(nil, v_10641, v_10640);
    env = stack[-6];
    if (v_10640 == nil) goto v_10433;
    else goto v_10434;
v_10433:
    v_10640 = stack[-3];
    goto v_10432;
v_10434:
    v_10640 = nil;
    goto v_10432;
    v_10640 = nil;
v_10432:
    if (v_10640 == nil) goto v_10429;
    else goto v_10430;
v_10429:
    goto v_10425;
v_10430:
    goto v_10453;
v_10449:
    v_10640 = stack[-1];
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    stack[0] = qcdr(v_10640);
    goto v_10450;
v_10451:
    goto v_10466;
v_10462:
    v_10640 = stack[-3];
    v_10641 = qcar(v_10640);
    goto v_10463;
v_10464:
    v_10640 = stack[-1];
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcar(v_10640);
    goto v_10465;
v_10466:
    goto v_10462;
v_10463:
    goto v_10464;
v_10465:
    v_10640 = cons(v_10641, v_10640);
    env = stack[-6];
    goto v_10452;
v_10453:
    goto v_10449;
v_10450:
    goto v_10451;
v_10452:
    fn = elt(env, 2); // setcar
    v_10640 = (*qfn2(fn))(fn, stack[0], v_10640);
    env = stack[-6];
    goto v_10482;
v_10478:
    v_10640 = stack[-3];
    v_10640 = qcar(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    stack[0] = qcdr(v_10640);
    goto v_10479;
v_10480:
    goto v_10500;
v_10496:
    v_10641 = stack[-1];
    goto v_10497;
v_10498:
    v_10640 = stack[-3];
    v_10640 = qcar(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcar(v_10640);
    goto v_10499;
v_10500:
    goto v_10496;
v_10497:
    goto v_10498;
v_10499:
    v_10640 = cons(v_10641, v_10640);
    env = stack[-6];
    goto v_10481;
v_10482:
    goto v_10478;
v_10479:
    goto v_10480;
v_10481:
    fn = elt(env, 2); // setcar
    v_10640 = (*qfn2(fn))(fn, stack[0], v_10640);
    env = stack[-6];
    v_10640 = stack[-5];
    v_10640 = add1(v_10640);
    env = stack[-6];
    stack[-5] = v_10640;
    v_10640 = stack[-3];
    v_10640 = qcdr(v_10640);
    stack[-3] = v_10640;
    goto v_10426;
v_10425:
    v_10640 = stack[-1];
    v_10640 = qcdr(v_10640);
    v_10640 = qcar(v_10640);
    stack[-3] = v_10640;
v_10524:
    goto v_10538;
v_10534:
    v_10641 = stack[-5];
    goto v_10535;
v_10536:
    v_10640 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10537;
v_10538:
    goto v_10534;
v_10535:
    goto v_10536;
v_10537:
    v_10640 = Leqn(nil, v_10641, v_10640);
    env = stack[-6];
    if (v_10640 == nil) goto v_10531;
    else goto v_10532;
v_10531:
    v_10640 = stack[-3];
    goto v_10530;
v_10532:
    v_10640 = nil;
    goto v_10530;
    v_10640 = nil;
v_10530:
    if (v_10640 == nil) goto v_10527;
    else goto v_10528;
v_10527:
    goto v_10523;
v_10528:
    goto v_10551;
v_10547:
    v_10640 = stack[-1];
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    stack[0] = qcdr(v_10640);
    goto v_10548;
v_10549:
    goto v_10564;
v_10560:
    v_10640 = stack[-3];
    v_10641 = qcar(v_10640);
    goto v_10561;
v_10562:
    v_10640 = stack[-1];
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcar(v_10640);
    goto v_10563;
v_10564:
    goto v_10560;
v_10561:
    goto v_10562;
v_10563:
    v_10640 = cons(v_10641, v_10640);
    env = stack[-6];
    goto v_10550;
v_10551:
    goto v_10547;
v_10548:
    goto v_10549;
v_10550:
    fn = elt(env, 2); // setcar
    v_10640 = (*qfn2(fn))(fn, stack[0], v_10640);
    env = stack[-6];
    goto v_10580;
v_10576:
    v_10640 = stack[-3];
    v_10640 = qcar(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    stack[0] = qcdr(v_10640);
    goto v_10577;
v_10578:
    goto v_10598;
v_10594:
    v_10641 = stack[-1];
    goto v_10595;
v_10596:
    v_10640 = stack[-3];
    v_10640 = qcar(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcdr(v_10640);
    v_10640 = qcar(v_10640);
    goto v_10597;
v_10598:
    goto v_10594;
v_10595:
    goto v_10596;
v_10597:
    v_10640 = cons(v_10641, v_10640);
    env = stack[-6];
    goto v_10579;
v_10580:
    goto v_10576;
v_10577:
    goto v_10578;
v_10579:
    fn = elt(env, 2); // setcar
    v_10640 = (*qfn2(fn))(fn, stack[0], v_10640);
    env = stack[-6];
    v_10640 = stack[-5];
    v_10640 = add1(v_10640);
    env = stack[-6];
    stack[-5] = v_10640;
    v_10640 = stack[-3];
    v_10640 = qcdr(v_10640);
    stack[-3] = v_10640;
    goto v_10524;
v_10523:
    goto v_10626;
v_10622:
    v_10641 = stack[-5];
    goto v_10623;
v_10624:
    v_10640 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10625;
v_10626:
    goto v_10622;
v_10623:
    goto v_10624;
v_10625:
    v_10640 = (LispObject)lessp2(v_10641, v_10640);
    v_10640 = v_10640 ? lisp_true : nil;
    env = stack[-6];
    if (v_10640 == nil) goto v_10620;
    goto v_10634;
v_10630:
    v_10641 = stack[-1];
    goto v_10631;
v_10632:
    v_10640 = stack[-4];
    goto v_10633;
v_10634:
    goto v_10630;
v_10631:
    goto v_10632;
v_10633:
    v_10640 = cons(v_10641, v_10640);
    env = stack[-6];
    stack[-4] = v_10640;
    goto v_10618;
v_10620:
v_10618:
    v_10640 = stack[-2];
    v_10640 = qcdr(v_10640);
    stack[-2] = v_10640;
    goto v_10410;
v_10409:
    v_10640 = stack[-4];
    return onevalue(v_10640);
}



// Code for variableom

static LispObject CC_variableom(LispObject env,
                         LispObject v_10399)
{
    env = qenv(env);
    LispObject v_10455, v_10456;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10399);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10399;
// end of prologue
    goto v_10409;
v_10405:
    v_10455 = stack[0];
    v_10456 = Lintern(nil, v_10455);
    env = stack[-2];
    goto v_10406;
v_10407:
    v_10455 = qvalue(elt(env, 2)); // constantsom!*
    goto v_10408;
v_10409:
    goto v_10405;
v_10406:
    goto v_10407;
v_10408:
    v_10455 = Lassoc(nil, v_10456, v_10455);
    stack[-1] = v_10455;
    v_10455 = stack[-1];
    if (v_10455 == nil) goto v_10417;
    v_10455 = elt(env, 3); // "<OMS "
    fn = elt(env, 9); // printout
    v_10455 = (*qfn1(fn))(fn, v_10455);
    env = stack[-2];
    v_10455 = elt(env, 4); // "cd="""
    v_10455 = Lprinc(nil, v_10455);
    env = stack[-2];
    v_10455 = stack[-1];
    v_10455 = qcdr(v_10455);
    v_10455 = qcar(v_10455);
    v_10455 = Lprinc(nil, v_10455);
    env = stack[-2];
    v_10455 = elt(env, 5); // """ "
    v_10455 = Lprinc(nil, v_10455);
    env = stack[-2];
    v_10455 = elt(env, 6); // "name="""
    v_10455 = Lprinc(nil, v_10455);
    env = stack[-2];
    v_10455 = stack[-1];
    v_10455 = qcdr(v_10455);
    v_10455 = qcdr(v_10455);
    v_10455 = qcar(v_10455);
    v_10455 = Lprinc(nil, v_10455);
    env = stack[-2];
    v_10455 = elt(env, 7); // """/>"
    v_10455 = Lprinc(nil, v_10455);
    goto v_10415;
v_10417:
    v_10455 = stack[0];
    if (v_10455 == nil) goto v_10444;
    v_10455 = elt(env, 8); // "<OMV "
    fn = elt(env, 9); // printout
    v_10455 = (*qfn1(fn))(fn, v_10455);
    env = stack[-2];
    v_10455 = elt(env, 6); // "name="""
    v_10455 = Lprinc(nil, v_10455);
    env = stack[-2];
    v_10455 = stack[0];
    v_10455 = Lprinc(nil, v_10455);
    env = stack[-2];
    v_10455 = elt(env, 7); // """/>"
    v_10455 = Lprinc(nil, v_10455);
    goto v_10442;
v_10444:
v_10442:
    goto v_10415;
v_10415:
    v_10455 = nil;
    return onevalue(v_10455);
}



// Code for vdpputprop

static LispObject CC_vdpputprop(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10523, v_10524, v_10525, v_10526;
    LispObject fn;
    LispObject v_10401, v_10400, v_10399;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "vdpputprop");
    va_start(aa, nargs);
    v_10399 = va_arg(aa, LispObject);
    v_10400 = va_arg(aa, LispObject);
    v_10401 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_10401,v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_10399,v_10400,v_10401);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_10401;
    stack[-3] = v_10400;
    stack[-4] = v_10399;
// end of prologue
    stack[-5] = nil;
    v_10523 = stack[-4];
    v_10523 = Lconsp(nil, v_10523);
    env = stack[-6];
    if (v_10523 == nil) goto v_10414;
    else goto v_10415;
v_10414:
    v_10523 = lisp_true;
    goto v_10413;
v_10415:
    v_10523 = stack[-4];
    v_10523 = qcdr(v_10523);
    stack[-5] = v_10523;
    v_10523 = Lconsp(nil, v_10523);
    env = stack[-6];
    if (v_10523 == nil) goto v_10423;
    else goto v_10424;
v_10423:
    v_10523 = lisp_true;
    goto v_10422;
v_10424:
    v_10523 = stack[-5];
    v_10523 = qcdr(v_10523);
    stack[-5] = v_10523;
    v_10523 = Lconsp(nil, v_10523);
    env = stack[-6];
    if (v_10523 == nil) goto v_10433;
    else goto v_10434;
v_10433:
    v_10523 = lisp_true;
    goto v_10432;
v_10434:
    v_10523 = stack[-5];
    v_10523 = qcdr(v_10523);
    stack[-5] = v_10523;
    v_10523 = Lconsp(nil, v_10523);
    env = stack[-6];
    if (v_10523 == nil) goto v_10443;
    else goto v_10444;
v_10443:
    v_10523 = lisp_true;
    goto v_10442;
v_10444:
    v_10523 = stack[-5];
    v_10523 = qcdr(v_10523);
    stack[-5] = v_10523;
    v_10523 = Lconsp(nil, v_10523);
    env = stack[-6];
    v_10523 = (v_10523 == nil ? lisp_true : nil);
    goto v_10442;
    v_10523 = nil;
v_10442:
    goto v_10432;
    v_10523 = nil;
v_10432:
    goto v_10422;
    v_10523 = nil;
v_10422:
    goto v_10413;
    v_10523 = nil;
v_10413:
    if (v_10523 == nil) goto v_10411;
    goto v_10462;
v_10456:
    stack[-1] = elt(env, 2); // dipoly
    goto v_10457;
v_10458:
    stack[0] = (LispObject)96+TAG_FIXNUM; // 6
    goto v_10459;
v_10460:
    goto v_10474;
v_10466:
    v_10526 = elt(env, 3); // "vdpputprop given a non-vdp as 1st parameter"
    goto v_10467;
v_10468:
    v_10525 = stack[-4];
    goto v_10469;
v_10470:
    v_10524 = stack[-3];
    goto v_10471;
v_10472:
    v_10523 = stack[-2];
    goto v_10473;
v_10474:
    goto v_10466;
v_10467:
    goto v_10468;
v_10469:
    goto v_10470;
v_10471:
    goto v_10472;
v_10473:
    v_10523 = list4(v_10526, v_10525, v_10524, v_10523);
    env = stack[-6];
    goto v_10461;
v_10462:
    goto v_10456;
v_10457:
    goto v_10458;
v_10459:
    goto v_10460;
v_10461:
    fn = elt(env, 4); // rerror
    v_10523 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_10523);
    env = stack[-6];
    goto v_10409;
v_10411:
v_10409:
    goto v_10483;
v_10479:
    v_10524 = stack[-3];
    goto v_10480;
v_10481:
    v_10523 = stack[-5];
    v_10523 = qcar(v_10523);
    goto v_10482;
v_10483:
    goto v_10479;
v_10480:
    goto v_10481;
v_10482:
    v_10523 = Lassoc(nil, v_10524, v_10523);
    v_10524 = v_10523;
    v_10523 = v_10524;
    if (v_10523 == nil) goto v_10491;
    goto v_10498;
v_10494:
    goto v_10495;
v_10496:
    v_10523 = stack[-2];
    goto v_10497;
v_10498:
    goto v_10494;
v_10495:
    goto v_10496;
v_10497:
    v_10523 = Lrplacd(nil, v_10524, v_10523);
    goto v_10489;
v_10491:
    goto v_10508;
v_10504:
    stack[0] = stack[-5];
    goto v_10505;
v_10506:
    goto v_10517;
v_10511:
    v_10525 = stack[-3];
    goto v_10512;
v_10513:
    v_10524 = stack[-2];
    goto v_10514;
v_10515:
    v_10523 = stack[-5];
    v_10523 = qcar(v_10523);
    goto v_10516;
v_10517:
    goto v_10511;
v_10512:
    goto v_10513;
v_10514:
    goto v_10515;
v_10516:
    v_10523 = acons(v_10525, v_10524, v_10523);
    env = stack[-6];
    goto v_10507;
v_10508:
    goto v_10504;
v_10505:
    goto v_10506;
v_10507:
    v_10523 = Lrplaca(nil, stack[0], v_10523);
    goto v_10489;
v_10489:
    v_10523 = stack[-4];
    return onevalue(v_10523);
}



// Code for command

static LispObject CC_command(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10716, v_10717, v_10718, v_10719;
    LispObject fn;
    argcheck(nargs, 0, "command");
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
// Binding errmsg!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = nil; // errmsg!*
// Binding loopdelimslist!*
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-3, 2, -1);
    qvalue(elt(env, 2)) = nil; // loopdelimslist!*
    v_10716 = qvalue(elt(env, 4)); // !*demo
    if (v_10716 == nil) goto v_10414;
    v_10716 = qvalue(elt(env, 5)); // ifl!*
    if (v_10716 == nil) goto v_10414;
    fn = elt(env, 28); // commdemo
    v_10716 = (*qfnn(fn))(fn, 0);
    goto v_10406;
v_10414:
    v_10716 = qvalue(elt(env, 6)); // !*slin
    if (v_10716 == nil) goto v_10424;
    else goto v_10425;
v_10424:
    v_10716 = lisp_true;
    goto v_10423;
v_10425:
    v_10716 = qvalue(elt(env, 7)); // !*reduce4
    goto v_10423;
    v_10716 = nil;
v_10423:
    if (v_10716 == nil) goto v_10421;
    goto v_10407;
v_10421:
    fn = elt(env, 29); // setcloc!*
    v_10716 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    v_10716 = qvalue(elt(env, 8)); // lreadfn!*
    if (v_10716 == nil) goto v_10435;
    goto v_10442;
v_10438:
    v_10717 = qvalue(elt(env, 8)); // lreadfn!*
    goto v_10439;
v_10440:
    v_10716 = nil;
    goto v_10441;
v_10442:
    goto v_10438;
v_10439:
    goto v_10440;
v_10441:
    fn = elt(env, 30); // lispapply
    v_10716 = (*qfn2(fn))(fn, v_10717, v_10716);
    env = stack[-3];
    goto v_10433;
v_10435:
    v_10716 = Lread(nil, 0);
    env = stack[-3];
    goto v_10433;
    v_10716 = nil;
v_10433:
    stack[0] = v_10716;
    goto v_10408;
v_10407:
    fn = elt(env, 31); // readch1
    v_10716 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    qvalue(elt(env, 9)) = v_10716; // crchar!*
    goto v_10457;
v_10453:
    v_10717 = qvalue(elt(env, 9)); // crchar!*
    goto v_10454;
v_10455:
    v_10716 = qvalue(elt(env, 10)); // !$eol!$
    goto v_10456;
v_10457:
    goto v_10453;
v_10454:
    goto v_10455;
v_10456:
    if (equal(v_10717, v_10716)) goto v_10451;
    else goto v_10452;
v_10451:
    goto v_10407;
v_10452:
    fn = elt(env, 32); // command1
    v_10716 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[0] = v_10716;
v_10408:
    v_10716 = qvalue(elt(env, 7)); // !*reduce4
    if (v_10716 == nil) goto v_10464;
    goto v_10409;
v_10464:
    v_10716 = qvalue(elt(env, 11)); // !*struct
    if (v_10716 == nil) goto v_10467;
    v_10716 = stack[0];
    fn = elt(env, 33); // structchk
    v_10716 = (*qfn1(fn))(fn, v_10716);
    env = stack[-3];
    stack[0] = v_10716;
    goto v_10462;
v_10467:
v_10462:
    v_10716 = qvalue(elt(env, 12)); // !*pret
    if (v_10716 == nil) goto v_10474;
    v_10716 = stack[0];
    if (!consp(v_10716)) goto v_10480;
    else goto v_10481;
v_10480:
    v_10716 = lisp_true;
    goto v_10479;
v_10481:
    goto v_10490;
v_10486:
    v_10716 = stack[0];
    v_10717 = qcar(v_10716);
    goto v_10487;
v_10488:
    v_10716 = elt(env, 13); // (in out shut)
    goto v_10489;
v_10490:
    goto v_10486;
v_10487:
    goto v_10488;
v_10489:
    v_10716 = Lmemq(nil, v_10717, v_10716);
    v_10716 = (v_10716 == nil ? lisp_true : nil);
    goto v_10479;
    v_10716 = nil;
v_10479:
    if (v_10716 == nil) goto v_10474;
    v_10716 = stack[0];
    if (v_10716 == nil) goto v_10502;
    else goto v_10503;
v_10502:
    goto v_10509;
v_10505:
    v_10717 = qvalue(elt(env, 14)); // cursym!*
    goto v_10506;
v_10507:
    v_10716 = elt(env, 15); // end
    goto v_10508;
v_10509:
    goto v_10505;
v_10506:
    goto v_10507;
v_10508:
    v_10716 = (v_10717 == v_10716 ? lisp_true : nil);
    goto v_10501;
v_10503:
    v_10716 = nil;
    goto v_10501;
    v_10716 = nil;
v_10501:
    if (v_10716 == nil) goto v_10499;
    v_10716 = elt(env, 15); // end
    fn = elt(env, 34); // rprint
    v_10716 = (*qfn1(fn))(fn, v_10716);
    env = stack[-3];
    goto v_10497;
v_10499:
    v_10716 = stack[0];
    fn = elt(env, 34); // rprint
    v_10716 = (*qfn1(fn))(fn, v_10716);
    env = stack[-3];
    v_10716 = Lterpri(nil, 0);
    env = stack[-3];
    goto v_10497;
v_10497:
    goto v_10472;
v_10474:
v_10472:
    v_10716 = qvalue(elt(env, 6)); // !*slin
    if (v_10716 == nil) goto v_10526;
    goto v_10533;
v_10529:
    v_10717 = elt(env, 16); // symbolic
    goto v_10530;
v_10531:
    v_10716 = stack[0];
    goto v_10532;
v_10533:
    goto v_10529;
v_10530:
    goto v_10531;
v_10532:
    v_10716 = list2(v_10717, v_10716);
    goto v_10406;
v_10526:
    v_10716 = stack[0];
    fn = elt(env, 35); // form
    v_10716 = (*qfn1(fn))(fn, v_10716);
    env = stack[-3];
    v_10717 = v_10716;
    v_10716 = qvalue(elt(env, 17)); // key!*
    if (!symbolp(v_10716)) v_10716 = nil;
    else { v_10716 = qfastgets(v_10716);
           if (v_10716 != nil) { v_10716 = elt(v_10716, 48); // modefn
#ifdef RECORD_GET
             if (v_10716 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v_10716 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v_10716 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v_10716 == SPID_NOPROP) v_10716 = nil; else v_10716 = lisp_true; }}
#endif
    if (v_10716 == nil) goto v_10541;
    v_10716 = qvalue(elt(env, 17)); // key!*
    goto v_10539;
v_10541:
    v_10716 = v_10717;
    if (!consp(v_10716)) goto v_10550;
    goto v_10560;
v_10556:
    v_10716 = v_10717;
    v_10718 = qcar(v_10716);
    goto v_10557;
v_10558:
    v_10716 = elt(env, 18); // quote
    goto v_10559;
v_10560:
    goto v_10556;
v_10557:
    goto v_10558;
v_10559:
    if (v_10718 == v_10716) goto v_10555;
    v_10716 = v_10717;
    v_10716 = qcar(v_10716);
    if (symbolp(v_10716)) goto v_10568;
    else goto v_10566;
v_10568:
    goto v_10581;
v_10577:
    v_10716 = v_10717;
    v_10718 = qcar(v_10716);
    goto v_10578;
v_10579:
    v_10716 = elt(env, 19); // nochange
    goto v_10580;
v_10581:
    goto v_10577;
v_10578:
    goto v_10579;
v_10580:
    v_10716 = Lflagp(nil, v_10718, v_10716);
    env = stack[-3];
    if (v_10716 == nil) goto v_10575;
    v_10716 = lisp_true;
    goto v_10573;
v_10575:
    goto v_10597;
v_10593:
    v_10716 = v_10717;
    v_10718 = qcar(v_10716);
    goto v_10594;
v_10595:
    v_10716 = elt(env, 20); // intfn
    goto v_10596;
v_10597:
    goto v_10593;
v_10594:
    goto v_10595;
v_10596:
    v_10716 = Lflagp(nil, v_10718, v_10716);
    env = stack[-3];
    if (v_10716 == nil) goto v_10591;
    v_10716 = lisp_true;
    goto v_10589;
v_10591:
    goto v_10608;
v_10604:
    v_10716 = v_10717;
    v_10718 = qcar(v_10716);
    goto v_10605;
v_10606:
    v_10716 = elt(env, 21); // list
    goto v_10607;
v_10608:
    goto v_10604;
v_10605:
    goto v_10606;
v_10607:
    v_10716 = (v_10718 == v_10716 ? lisp_true : nil);
    goto v_10589;
    v_10716 = nil;
v_10589:
    goto v_10573;
    v_10716 = nil;
v_10573:
    if (v_10716 == nil) goto v_10566;
    goto v_10567;
v_10566:
    v_10716 = lisp_true;
    goto v_10565;
v_10567:
    goto v_10624;
v_10620:
    v_10716 = v_10717;
    v_10718 = qcar(v_10716);
    goto v_10621;
v_10622:
    v_10716 = elt(env, 22); // (setq setel setf)
    goto v_10623;
v_10624:
    goto v_10620;
v_10621:
    goto v_10622;
v_10623:
    v_10716 = Lmemq(nil, v_10718, v_10716);
    if (v_10716 == nil) goto v_10618;
    else goto v_10619;
v_10618:
    v_10716 = nil;
    goto v_10617;
v_10619:
    goto v_10637;
v_10633:
    v_10716 = v_10717;
    v_10716 = qcdr(v_10716);
    v_10716 = qcdr(v_10716);
    v_10718 = qcar(v_10716);
    goto v_10634;
v_10635:
    v_10716 = elt(env, 18); // quote
    goto v_10636;
v_10637:
    goto v_10633;
v_10634:
    goto v_10635;
v_10636:
    v_10716 = Leqcar(nil, v_10718, v_10716);
    env = stack[-3];
    goto v_10617;
    v_10716 = nil;
v_10617:
    goto v_10565;
    v_10716 = nil;
v_10565:
    goto v_10553;
v_10555:
    v_10716 = nil;
    goto v_10553;
    v_10716 = nil;
v_10553:
    goto v_10548;
v_10550:
    v_10716 = nil;
    goto v_10548;
    v_10716 = nil;
v_10548:
    if (v_10716 == nil) goto v_10546;
    v_10716 = elt(env, 16); // symbolic
    goto v_10539;
v_10546:
    v_10716 = qvalue(elt(env, 23)); // !*mode
    goto v_10539;
v_10539:
    goto v_10658;
v_10654:
    stack[0] = v_10716;
    goto v_10655;
v_10656:
    goto v_10669;
v_10661:
    v_10719 = v_10717;
    goto v_10662;
v_10663:
    v_10718 = nil;
    goto v_10664;
v_10665:
    v_10717 = elt(env, 16); // symbolic
    goto v_10666;
v_10667:
    goto v_10668;
v_10669:
    goto v_10661;
v_10662:
    goto v_10663;
v_10664:
    goto v_10665;
v_10666:
    goto v_10667;
v_10668:
    fn = elt(env, 36); // convertmode1
    v_10716 = (*qfnn(fn))(fn, 4, v_10719, v_10718, v_10717, v_10716);
    env = stack[-3];
    goto v_10657;
v_10658:
    goto v_10654;
v_10655:
    goto v_10656;
v_10657:
    v_10716 = list2(stack[0], v_10716);
    goto v_10406;
v_10409:
    v_10716 = qvalue(elt(env, 24)); // !*debug
    if (v_10716 == nil) goto v_10677;
    v_10716 = elt(env, 25); // "Parse: "
    v_10716 = Lprinc(nil, v_10716);
    env = stack[-3];
    v_10716 = stack[0];
    fn = elt(env, 37); // prettyprint
    v_10716 = (*qfn1(fn))(fn, v_10716);
    env = stack[-3];
    goto v_10675;
v_10677:
v_10675:
    goto v_10691;
v_10687:
    v_10717 = qvalue(elt(env, 17)); // key!*
    goto v_10688;
v_10689:
    v_10716 = elt(env, 26); // !*semicol!*
    goto v_10690;
v_10691:
    goto v_10687;
v_10688:
    goto v_10689;
v_10690:
    if (v_10717 == v_10716) goto v_10685;
    else goto v_10686;
v_10685:
    goto v_10407;
v_10686:
    v_10716 = qvalue(elt(env, 7)); // !*reduce4
    if (v_10716 == nil) goto v_10696;
    else goto v_10697;
v_10696:
    v_10716 = stack[0];
    fn = elt(env, 35); // form
    v_10716 = (*qfn1(fn))(fn, v_10716);
    env = stack[-3];
    stack[0] = v_10716;
    goto v_10695;
v_10697:
    v_10716 = stack[0];
    fn = elt(env, 38); // n_form
    v_10716 = (*qfn1(fn))(fn, v_10716);
    env = stack[-3];
    stack[0] = v_10716;
    goto v_10695;
v_10695:
    v_10716 = qvalue(elt(env, 24)); // !*debug
    if (v_10716 == nil) goto v_10708;
    v_10716 = Lterpri(nil, 0);
    env = stack[-3];
    v_10716 = elt(env, 27); // "Form: "
    v_10716 = Lprinc(nil, v_10716);
    env = stack[-3];
    v_10716 = stack[0];
    fn = elt(env, 37); // prettyprint
    v_10716 = (*qfn1(fn))(fn, v_10716);
    goto v_10706;
v_10708:
v_10706:
    v_10716 = stack[0];
v_10406:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_10716);
}



// Code for mkarray1

static LispObject CC_mkarray1(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10475, v_10476;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_10400;
    stack[-5] = v_10399;
// end of prologue
    v_10475 = stack[-5];
    if (v_10475 == nil) goto v_10404;
    else goto v_10405;
v_10404:
    goto v_10415;
v_10411:
    v_10475 = stack[-4];
    goto v_10412;
v_10413:
    v_10476 = elt(env, 1); // symbolic
    goto v_10414;
v_10415:
    goto v_10411;
v_10412:
    goto v_10413;
v_10414:
    if (v_10475 == v_10476) goto v_10409;
    else goto v_10410;
v_10409:
    v_10475 = nil;
    goto v_10408;
v_10410:
    v_10475 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10408;
    v_10475 = nil;
v_10408:
    goto v_10403;
v_10405:
    v_10475 = stack[-5];
    v_10475 = qcar(v_10475);
    v_10475 = sub1(v_10475);
    env = stack[-7];
    stack[-6] = v_10475;
    v_10475 = stack[-6];
    v_10475 = Lmkvect(nil, v_10475);
    env = stack[-7];
    stack[-3] = v_10475;
    v_10475 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_10475;
v_10438:
    goto v_10450;
v_10446:
    v_10476 = stack[-6];
    goto v_10447;
v_10448:
    v_10475 = stack[-2];
    goto v_10449;
v_10450:
    goto v_10446;
v_10447:
    goto v_10448;
v_10449:
    v_10475 = difference2(v_10476, v_10475);
    env = stack[-7];
    v_10475 = Lminusp(nil, v_10475);
    env = stack[-7];
    if (v_10475 == nil) goto v_10443;
    goto v_10437;
v_10443:
    goto v_10460;
v_10454:
    stack[-1] = stack[-3];
    goto v_10455;
v_10456:
    stack[0] = stack[-2];
    goto v_10457;
v_10458:
    goto v_10468;
v_10464:
    v_10475 = stack[-5];
    v_10476 = qcdr(v_10475);
    goto v_10465;
v_10466:
    v_10475 = stack[-4];
    goto v_10467;
v_10468:
    goto v_10464;
v_10465:
    goto v_10466;
v_10467:
    v_10475 = CC_mkarray1(elt(env, 0), v_10476, v_10475);
    env = stack[-7];
    goto v_10459;
v_10460:
    goto v_10454;
v_10455:
    goto v_10456;
v_10457:
    goto v_10458;
v_10459:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_10475;
    v_10475 = stack[-2];
    v_10475 = add1(v_10475);
    env = stack[-7];
    stack[-2] = v_10475;
    goto v_10438;
v_10437:
    v_10475 = stack[-3];
    goto v_10403;
    v_10475 = nil;
v_10403:
    return onevalue(v_10475);
}



// Code for class

static LispObject CC_class(LispObject env,
                         LispObject v_10399)
{
    env = qenv(env);
    LispObject v_10435, v_10436;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10399);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10399;
// end of prologue
    goto v_10409;
v_10405:
    v_10435 = stack[0];
    fn = elt(env, 3); // ord
    v_10436 = (*qfn1(fn))(fn, v_10435);
    env = stack[-1];
    goto v_10406;
v_10407:
    v_10435 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10408;
v_10409:
    goto v_10405;
v_10406:
    goto v_10407;
v_10408:
    if (v_10436 == v_10435) goto v_10403;
    else goto v_10404;
v_10403:
    v_10435 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10402;
v_10404:
    goto v_10426;
v_10422:
    v_10436 = qvalue(elt(env, 1)); // ordering
    goto v_10423;
v_10424:
    v_10435 = elt(env, 2); // lex
    goto v_10425;
v_10426:
    goto v_10422;
v_10423:
    goto v_10424;
v_10425:
    if (v_10436 == v_10435) goto v_10420;
    else goto v_10421;
v_10420:
    v_10435 = stack[0];
    goto v_10419;
v_10421:
    v_10435 = stack[0];
    v_10435 = qcdr(v_10435);
    goto v_10419;
    v_10435 = nil;
v_10419:
    v_10435 = Lreverse(nil, v_10435);
    env = stack[-1];
    fn = elt(env, 4); // leftzeros
    v_10435 = (*qfn1(fn))(fn, v_10435);
    v_10435 = (LispObject)((intptr_t)(v_10435) + 0x10);
    goto v_10402;
    v_10435 = nil;
v_10402:
    return onevalue(v_10435);
}



// Code for moduntag

static LispObject CC_moduntag(LispObject env,
                         LispObject v_10399)
{
    env = qenv(env);
    LispObject v_10451, v_10452;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10399);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10399;
// end of prologue
    stack[-1] = nil;
v_10404:
    goto v_10414;
v_10410:
    v_10452 = stack[0];
    goto v_10411;
v_10412:
    v_10451 = elt(env, 1); // !:mod!:
    goto v_10413;
v_10414:
    goto v_10410;
v_10411:
    goto v_10412;
v_10413:
    if (!consp(v_10452)) goto v_10408;
    v_10452 = qcar(v_10452);
    if (v_10452 == v_10451) goto v_10407;
    else goto v_10408;
v_10407:
    goto v_10422;
v_10418:
    v_10452 = stack[-1];
    goto v_10419;
v_10420:
    v_10451 = stack[0];
    v_10451 = qcdr(v_10451);
    goto v_10421;
v_10422:
    goto v_10418;
v_10419:
    goto v_10420;
v_10421:
    {
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_10452, v_10451);
    }
v_10408:
    v_10451 = stack[0];
    if (!consp(v_10451)) goto v_10426;
    else goto v_10427;
v_10426:
    goto v_10434;
v_10430:
    v_10452 = stack[-1];
    goto v_10431;
v_10432:
    v_10451 = stack[0];
    goto v_10433;
v_10434:
    goto v_10430;
v_10431:
    goto v_10432;
v_10433:
    {
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_10452, v_10451);
    }
v_10427:
    goto v_10444;
v_10440:
    v_10451 = stack[0];
    v_10451 = qcar(v_10451);
    v_10452 = CC_moduntag(elt(env, 0), v_10451);
    env = stack[-2];
    goto v_10441;
v_10442:
    v_10451 = stack[-1];
    goto v_10443;
v_10444:
    goto v_10440;
v_10441:
    goto v_10442;
v_10443:
    v_10451 = cons(v_10452, v_10451);
    env = stack[-2];
    stack[-1] = v_10451;
    v_10451 = stack[0];
    v_10451 = qcdr(v_10451);
    stack[0] = v_10451;
    goto v_10404;
    v_10451 = nil;
    return onevalue(v_10451);
}



// Code for mksq

static LispObject CC_mksq(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10729, v_10730;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_10400;
    stack[-4] = v_10399;
// end of prologue
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v_10729 = qvalue(elt(env, 2)); // subfg!*
    if (v_10729 == nil) goto v_10414;
    else goto v_10415;
v_10414:
    goto v_10408;
v_10415:
    goto v_10424;
v_10420:
    v_10730 = stack[-4];
    goto v_10421;
v_10422:
    v_10729 = qvalue(elt(env, 3)); // wtl!*
    goto v_10423;
v_10424:
    goto v_10420;
v_10421:
    goto v_10422;
v_10423:
    v_10729 = Lassoc(nil, v_10730, v_10729);
    stack[-2] = v_10729;
    if (v_10729 == nil) goto v_10418;
    goto v_10434;
v_10430:
    stack[0] = elt(env, 4); // k!*
    goto v_10431;
v_10432:
    goto v_10441;
v_10437:
    v_10730 = stack[-3];
    goto v_10438;
v_10439:
    v_10729 = stack[-2];
    v_10729 = qcdr(v_10729);
    goto v_10440;
v_10441:
    goto v_10437;
v_10438:
    goto v_10439;
v_10440:
    v_10729 = times2(v_10730, v_10729);
    env = stack[-6];
    goto v_10433;
v_10434:
    goto v_10430;
v_10431:
    goto v_10432;
v_10433:
    v_10729 = CC_mksq(elt(env, 0), stack[0], v_10729);
    env = stack[-6];
    stack[-2] = v_10729;
    v_10729 = qcar(v_10729);
    if (v_10729 == nil) goto v_10428;
    else goto v_10418;
v_10428:
    v_10729 = stack[-2];
    goto v_10406;
v_10418:
    v_10729 = stack[-4];
    if (!consp(v_10729)) goto v_10448;
    goto v_10409;
v_10448:
    v_10729 = qvalue(elt(env, 5)); // !*nosubs
    if (v_10729 == nil) goto v_10454;
    else goto v_10455;
v_10454:
    v_10729 = stack[-4];
    if (!symbolp(v_10729)) v_10729 = nil;
    else { v_10729 = qfastgets(v_10729);
           if (v_10729 != nil) { v_10729 = elt(v_10729, 4); // avalue
#ifdef RECORD_GET
             if (v_10729 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_10729 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_10729 == SPID_NOPROP) v_10729 = nil; }}
#endif
    stack[-1] = v_10729;
    goto v_10453;
v_10455:
    v_10729 = nil;
    goto v_10453;
    v_10729 = nil;
v_10453:
    if (v_10729 == nil) goto v_10451;
    goto v_10410;
v_10451:
    v_10729 = stack[-4];
    if (symbolp(v_10729)) goto v_10464;
    else goto v_10465;
v_10464:
    goto v_10472;
v_10468:
    v_10729 = stack[-4];
    v_10730 = ncons(v_10729);
    env = stack[-6];
    goto v_10469;
v_10470:
    v_10729 = elt(env, 6); // used!*
    goto v_10471;
v_10472:
    goto v_10468;
v_10469:
    goto v_10470;
v_10471:
    v_10729 = Lflag(nil, v_10730, v_10729);
    env = stack[-6];
    goto v_10463;
v_10465:
v_10463:
v_10407:
    v_10729 = qvalue(elt(env, 5)); // !*nosubs
    if (v_10729 == nil) goto v_10480;
    else goto v_10478;
v_10480:
    goto v_10487;
v_10483:
    v_10730 = stack[-3];
    goto v_10484;
v_10485:
    v_10729 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10486;
v_10487:
    goto v_10483;
v_10484:
    goto v_10485;
v_10486:
    if (v_10730 == v_10729) goto v_10478;
    goto v_10479;
v_10478:
    goto v_10408;
v_10479:
    goto v_10497;
v_10493:
    v_10730 = stack[-4];
    goto v_10494;
v_10495:
    v_10729 = qvalue(elt(env, 7)); // asymplis!*
    goto v_10496;
v_10497:
    goto v_10493;
v_10494:
    goto v_10495;
v_10496:
    v_10729 = Lassoc(nil, v_10730, v_10729);
    stack[-1] = v_10729;
    if (v_10729 == nil) goto v_10491;
    goto v_10507;
v_10503:
    v_10729 = stack[-1];
    v_10730 = qcdr(v_10729);
    goto v_10504;
v_10505:
    v_10729 = stack[-3];
    goto v_10506;
v_10507:
    goto v_10503;
v_10504:
    goto v_10505;
v_10506:
    v_10729 = (LispObject)lesseq2(v_10730, v_10729);
    v_10729 = v_10729 ? lisp_true : nil;
    env = stack[-6];
    if (v_10729 == nil) goto v_10491;
    goto v_10516;
v_10512:
    v_10730 = nil;
    goto v_10513;
v_10514:
    v_10729 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10515;
v_10516:
    goto v_10512;
v_10513:
    goto v_10514;
v_10515:
    return cons(v_10730, v_10729);
v_10491:
    goto v_10527;
v_10523:
    v_10730 = stack[-4];
    goto v_10524;
v_10525:
    v_10729 = qvalue(elt(env, 8)); // powlis!*
    goto v_10526;
v_10527:
    goto v_10523;
v_10524:
    goto v_10525;
v_10526:
    v_10729 = Lassoc(nil, v_10730, v_10729);
    stack[-1] = v_10729;
    if (v_10729 == nil) goto v_10522;
    else goto v_10521;
v_10522:
    v_10729 = stack[-4];
    if (!consp(v_10729)) goto v_10535;
    goto v_10545;
v_10541:
    v_10729 = stack[-4];
    v_10730 = qcar(v_10729);
    goto v_10542;
v_10543:
    v_10729 = elt(env, 9); // (expt sqrt)
    goto v_10544;
v_10545:
    goto v_10541;
v_10542:
    goto v_10543;
v_10544:
    v_10729 = Lmemq(nil, v_10730, v_10729);
    if (v_10729 == nil) goto v_10539;
    else goto v_10540;
v_10539:
    v_10729 = nil;
    goto v_10538;
v_10540:
    goto v_10557;
v_10553:
    v_10729 = stack[-4];
    v_10729 = qcdr(v_10729);
    v_10730 = qcar(v_10729);
    goto v_10554;
v_10555:
    v_10729 = qvalue(elt(env, 8)); // powlis!*
    goto v_10556;
v_10557:
    goto v_10553;
v_10554:
    goto v_10555;
v_10556:
    v_10729 = Lassoc(nil, v_10730, v_10729);
    stack[-1] = v_10729;
    goto v_10538;
    v_10729 = nil;
v_10538:
    goto v_10533;
v_10535:
    v_10729 = nil;
    goto v_10533;
    v_10729 = nil;
v_10533:
    if (v_10729 == nil) goto v_10531;
    else goto v_10521;
v_10531:
    goto v_10520;
v_10521:
    goto v_10572;
v_10568:
    goto v_10578;
v_10574:
    v_10730 = stack[-3];
    goto v_10575;
v_10576:
    v_10729 = stack[-1];
    v_10729 = qcdr(v_10729);
    v_10729 = qcar(v_10729);
    goto v_10577;
v_10578:
    goto v_10574;
v_10575:
    goto v_10576;
v_10577:
    v_10730 = times2(v_10730, v_10729);
    env = stack[-6];
    goto v_10569;
v_10570:
    v_10729 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10571;
v_10572:
    goto v_10568;
v_10569:
    goto v_10570;
v_10571:
    v_10729 = (LispObject)lessp2(v_10730, v_10729);
    v_10729 = v_10729 ? lisp_true : nil;
    env = stack[-6];
    if (v_10729 == nil) goto v_10566;
    else goto v_10520;
v_10566:
    v_10729 = lisp_true;
    qvalue(elt(env, 10)) = v_10729; // !*sub2
    goto v_10477;
v_10520:
v_10477:
v_10408:
    v_10729 = stack[-5];
    if (v_10729 == nil) goto v_10587;
    else goto v_10588;
v_10587:
    v_10729 = stack[-4];
    fn = elt(env, 13); // fkern
    v_10729 = (*qfn1(fn))(fn, v_10729);
    env = stack[-6];
    stack[-5] = v_10729;
    goto v_10586;
v_10588:
v_10586:
    goto v_10597;
v_10593:
    goto v_10604;
v_10600:
    goto v_10610;
v_10606:
    v_10730 = stack[-5];
    goto v_10607;
v_10608:
    v_10729 = stack[-3];
    goto v_10609;
v_10610:
    goto v_10606;
v_10607:
    goto v_10608;
v_10609:
    fn = elt(env, 14); // getpower
    v_10730 = (*qfn2(fn))(fn, v_10730, v_10729);
    env = stack[-6];
    goto v_10601;
v_10602:
    v_10729 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10603;
v_10604:
    goto v_10600;
v_10601:
    goto v_10602;
v_10603:
    v_10729 = cons(v_10730, v_10729);
    env = stack[-6];
    v_10730 = ncons(v_10729);
    env = stack[-6];
    goto v_10594;
v_10595:
    v_10729 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10596;
v_10597:
    goto v_10593;
v_10594:
    goto v_10595;
v_10596:
    v_10729 = cons(v_10730, v_10729);
    env = stack[-6];
    stack[-5] = v_10729;
    v_10729 = stack[-2];
    if (v_10729 == nil) goto v_10618;
    goto v_10625;
v_10621:
    v_10730 = stack[-2];
    goto v_10622;
v_10623:
    v_10729 = stack[-5];
    goto v_10624;
v_10625:
    goto v_10621;
v_10622:
    goto v_10623;
v_10624:
    {
        fn = elt(env, 15); // multsq
        return (*qfn2(fn))(fn, v_10730, v_10729);
    }
v_10618:
    v_10729 = stack[-5];
    goto v_10616;
    v_10729 = nil;
v_10616:
    goto v_10406;
v_10409:
    v_10729 = qvalue(elt(env, 5)); // !*nosubs
    if (v_10729 == nil) goto v_10637;
    else goto v_10638;
v_10637:
    v_10729 = stack[-4];
    v_10729 = qcar(v_10729);
    if (!consp(v_10729)) goto v_10642;
    else goto v_10643;
v_10642:
    goto v_10658;
v_10654:
    v_10729 = stack[-4];
    v_10730 = qcar(v_10729);
    goto v_10655;
v_10656:
    v_10729 = elt(env, 11); // mksqsubfn
    goto v_10657;
v_10658:
    goto v_10654;
v_10655:
    goto v_10656;
v_10657:
    v_10729 = get(v_10730, v_10729);
    env = stack[-6];
    stack[-1] = v_10729;
    if (v_10729 == nil) goto v_10651;
    else goto v_10652;
v_10651:
    v_10729 = nil;
    goto v_10650;
v_10652:
    goto v_10670;
v_10666:
    v_10730 = stack[-1];
    goto v_10667;
v_10668:
    v_10729 = stack[-4];
    goto v_10669;
v_10670:
    goto v_10666;
v_10667:
    goto v_10668;
v_10669:
    v_10729 = Lapply1(nil, v_10730, v_10729);
    env = stack[-6];
    stack[-1] = v_10729;
    goto v_10650;
    v_10729 = nil;
v_10650:
    if (v_10729 == nil) goto v_10648;
    else goto v_10647;
v_10648:
    goto v_10677;
v_10673:
    v_10730 = stack[-4];
    goto v_10674;
v_10675:
    v_10729 = stack[-4];
    v_10729 = qcar(v_10729);
    if (!symbolp(v_10729)) v_10729 = nil;
    else { v_10729 = qfastgets(v_10729);
           if (v_10729 != nil) { v_10729 = elt(v_10729, 50); // kvalue
#ifdef RECORD_GET
             if (v_10729 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v_10729 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v_10729 == SPID_NOPROP) v_10729 = nil; }}
#endif
    goto v_10676;
v_10677:
    goto v_10673;
v_10674:
    goto v_10675;
v_10676:
    v_10729 = Lassoc(nil, v_10730, v_10729);
    stack[-1] = v_10729;
v_10647:
    goto v_10641;
v_10643:
    v_10729 = nil;
    goto v_10641;
    v_10729 = nil;
v_10641:
    goto v_10636;
v_10638:
    v_10729 = nil;
    goto v_10636;
    v_10729 = nil;
v_10636:
    if (v_10729 == nil) goto v_10634;
    goto v_10410;
v_10634:
    goto v_10695;
v_10691:
    stack[0] = elt(env, 6); // used!*
    goto v_10692;
v_10693:
    v_10729 = stack[-4];
    fn = elt(env, 13); // fkern
    v_10729 = (*qfn1(fn))(fn, v_10729);
    env = stack[-6];
    stack[-5] = v_10729;
    v_10729 = qcdr(v_10729);
    v_10729 = qcdr(v_10729);
    goto v_10694;
v_10695:
    goto v_10691;
v_10692:
    goto v_10693;
v_10694:
    v_10729 = Lmemq(nil, stack[0], v_10729);
    if (v_10729 == nil) goto v_10689;
    else goto v_10690;
v_10689:
    goto v_10707;
v_10703:
    v_10730 = stack[-5];
    goto v_10704;
v_10705:
    v_10729 = elt(env, 6); // used!*
    goto v_10706;
v_10707:
    goto v_10703;
v_10704:
    goto v_10705;
v_10706:
    fn = elt(env, 16); // aconc
    v_10729 = (*qfn2(fn))(fn, v_10730, v_10729);
    env = stack[-6];
    goto v_10632;
v_10690:
v_10632:
    goto v_10407;
v_10410:
    v_10729 = stack[-1];
    v_10729 = qcdr(v_10729);
    stack[-1] = v_10729;
    v_10729 = qvalue(elt(env, 12)); // !*resubs
    if (v_10729 == nil) goto v_10714;
    else goto v_10715;
v_10714:
    v_10729 = lisp_true;
    qvalue(elt(env, 5)) = v_10729; // !*nosubs
    goto v_10713;
v_10715:
v_10713:
    v_10729 = stack[-1];
    fn = elt(env, 17); // simpcar
    v_10729 = (*qfn1(fn))(fn, v_10729);
    env = stack[-6];
    stack[-5] = v_10729;
    v_10729 = nil;
    qvalue(elt(env, 5)) = v_10729; // !*nosubs
    goto v_10726;
v_10722:
    v_10730 = stack[-5];
    goto v_10723;
v_10724:
    v_10729 = stack[-3];
    goto v_10725;
v_10726:
    goto v_10722;
v_10723:
    goto v_10724;
v_10725:
    {
        fn = elt(env, 18); // exptsq
        return (*qfn2(fn))(fn, v_10730, v_10729);
    }
v_10406:
    return onevalue(v_10729);
}



// Code for !:expt

static LispObject CC_Texpt(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10616, v_10617, v_10618;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_10400;
    stack[-4] = v_10399;
// end of prologue
    v_10616 = stack[-4];
    if (v_10616 == nil) goto v_10404;
    else goto v_10405;
v_10404:
    goto v_10415;
v_10411:
    v_10617 = stack[-3];
    goto v_10412;
v_10413:
    v_10616 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10414;
v_10415:
    goto v_10411;
v_10412:
    goto v_10413;
v_10414:
    if (v_10617 == v_10616) goto v_10409;
    else goto v_10410;
v_10409:
    goto v_10425;
v_10419:
    v_10618 = elt(env, 1); // poly
    goto v_10420;
v_10421:
    v_10617 = (LispObject)176+TAG_FIXNUM; // 11
    goto v_10422;
v_10423:
    v_10616 = elt(env, 2); // "0/0 formed"
    goto v_10424;
v_10425:
    goto v_10419;
v_10420:
    goto v_10421;
v_10422:
    goto v_10423;
v_10424:
    {
        fn = elt(env, 5); // rerror
        return (*qfnn(fn))(fn, 3, v_10618, v_10617, v_10616);
    }
v_10410:
    v_10616 = nil;
    goto v_10408;
    v_10616 = nil;
v_10408:
    goto v_10403;
v_10405:
    goto v_10438;
v_10434:
    v_10617 = stack[-3];
    goto v_10435;
v_10436:
    v_10616 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10437;
v_10438:
    goto v_10434;
v_10435:
    goto v_10436;
v_10437:
    if (v_10617 == v_10616) goto v_10432;
    else goto v_10433;
v_10432:
    v_10616 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10403;
v_10433:
    goto v_10448;
v_10444:
    v_10617 = stack[-3];
    goto v_10445;
v_10446:
    v_10616 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10447;
v_10448:
    goto v_10444;
v_10445:
    goto v_10446;
v_10447:
    if (v_10617 == v_10616) goto v_10442;
    else goto v_10443;
v_10442:
    v_10616 = stack[-4];
    goto v_10403;
v_10443:
    goto v_10458;
v_10454:
    v_10617 = stack[-4];
    goto v_10455;
v_10456:
    v_10616 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10457;
v_10458:
    goto v_10454;
v_10455:
    goto v_10456;
v_10457:
    if (v_10617 == v_10616) goto v_10452;
    else goto v_10453;
v_10452:
    v_10616 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10403;
v_10453:
    goto v_10469;
v_10465:
    v_10617 = stack[-3];
    goto v_10466;
v_10467:
    v_10616 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10468;
v_10469:
    goto v_10465;
v_10466:
    goto v_10467;
v_10468:
    v_10616 = (LispObject)lessp2(v_10617, v_10616);
    v_10616 = v_10616 ? lisp_true : nil;
    env = stack[-6];
    if (v_10616 == nil) goto v_10463;
    goto v_10478;
v_10474:
    v_10616 = stack[-4];
    fn = elt(env, 6); // fieldp
    v_10616 = (*qfn1(fn))(fn, v_10616);
    env = stack[-6];
    if (v_10616 == nil) goto v_10481;
    else goto v_10482;
v_10481:
    v_10616 = stack[-4];
    fn = elt(env, 7); // mkratnum
    v_10616 = (*qfn1(fn))(fn, v_10616);
    env = stack[-6];
    stack[0] = v_10616;
    goto v_10480;
v_10482:
    v_10616 = stack[-4];
    stack[0] = v_10616;
    goto v_10480;
    stack[0] = nil;
v_10480:
    goto v_10475;
v_10476:
    v_10616 = stack[-3];
    v_10616 = negate(v_10616);
    env = stack[-6];
    goto v_10477;
v_10478:
    goto v_10474;
v_10475:
    goto v_10476;
v_10477:
    v_10616 = CC_Texpt(elt(env, 0), stack[0], v_10616);
    env = stack[-6];
    {
        fn = elt(env, 8); // !:recip
        return (*qfn1(fn))(fn, v_10616);
    }
v_10463:
    v_10616 = stack[-4];
    if (!consp(v_10616)) goto v_10492;
    else goto v_10493;
v_10492:
    goto v_10500;
v_10496:
    v_10617 = stack[-4];
    goto v_10497;
v_10498:
    v_10616 = stack[-3];
    goto v_10499;
v_10500:
    goto v_10496;
v_10497:
    goto v_10498;
v_10499:
        return Lexpt(nil, v_10617, v_10616);
v_10493:
    goto v_10521;
v_10517:
    v_10616 = stack[-4];
    v_10617 = qcar(v_10616);
    goto v_10518;
v_10519:
    v_10616 = elt(env, 4); // expt
    goto v_10520;
v_10521:
    goto v_10517;
v_10518:
    goto v_10519;
v_10520:
    v_10616 = get(v_10617, v_10616);
    env = stack[-6];
    stack[-2] = v_10616;
    if (v_10616 == nil) goto v_10515;
    goto v_10532;
v_10526:
    v_10618 = stack[-2];
    goto v_10527;
v_10528:
    v_10617 = stack[-4];
    goto v_10529;
v_10530:
    v_10616 = stack[-3];
    goto v_10531;
v_10532:
    goto v_10526;
v_10527:
    goto v_10528;
v_10529:
    goto v_10530;
v_10531:
        return Lapply2(nil, 3, v_10618, v_10617, v_10616);
v_10515:
    goto v_10541;
v_10537:
    v_10616 = stack[-4];
    v_10616 = qcar(v_10616);
    if (!symbolp(v_10616)) v_10617 = nil;
    else { v_10617 = qfastgets(v_10616);
           if (v_10617 != nil) { v_10617 = elt(v_10617, 34); // i2d
#ifdef RECORD_GET
             if (v_10617 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_10617 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_10617 == SPID_NOPROP) v_10617 = nil; }}
#endif
    goto v_10538;
v_10539:
    v_10616 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10540;
v_10541:
    goto v_10537;
v_10538:
    goto v_10539;
v_10540:
    v_10616 = Lapply1(nil, v_10617, v_10616);
    env = stack[-6];
    stack[-5] = v_10616;
    v_10616 = stack[-4];
    v_10616 = qcar(v_10616);
    if (!symbolp(v_10616)) v_10616 = nil;
    else { v_10616 = qfastgets(v_10616);
           if (v_10616 != nil) { v_10616 = elt(v_10616, 54); // times
#ifdef RECORD_GET
             if (v_10616 != SPID_NOPROP)
                record_get(elt(fastget_names, 54), 1);
             else record_get(elt(fastget_names, 54), 0),
                v_10616 = nil; }
           else record_get(elt(fastget_names, 54), 0); }
#else
             if (v_10616 == SPID_NOPROP) v_10616 = nil; }}
#endif
    stack[-2] = v_10616;
v_10510:
    v_10616 = stack[-3];
    goto v_10558;
v_10554:
    goto v_10564;
v_10560:
    stack[-1] = v_10616;
    goto v_10561;
v_10562:
    goto v_10571;
v_10567:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10568;
v_10569:
    goto v_10578;
v_10574:
    v_10617 = stack[-3];
    goto v_10575;
v_10576:
    v_10616 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10577;
v_10578:
    goto v_10574;
v_10575:
    goto v_10576;
v_10577:
    v_10616 = quot2(v_10617, v_10616);
    env = stack[-6];
    stack[-3] = v_10616;
    goto v_10570;
v_10571:
    goto v_10567;
v_10568:
    goto v_10569;
v_10570:
    v_10616 = times2(stack[0], v_10616);
    env = stack[-6];
    goto v_10563;
v_10564:
    goto v_10560;
v_10561:
    goto v_10562;
v_10563:
    v_10617 = difference2(stack[-1], v_10616);
    env = stack[-6];
    goto v_10555;
v_10556:
    v_10616 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10557;
v_10558:
    goto v_10554;
v_10555:
    goto v_10556;
v_10557:
    if (v_10617 == v_10616) goto v_10553;
    goto v_10589;
v_10583:
    v_10618 = stack[-2];
    goto v_10584;
v_10585:
    v_10617 = stack[-4];
    goto v_10586;
v_10587:
    v_10616 = stack[-5];
    goto v_10588;
v_10589:
    goto v_10583;
v_10584:
    goto v_10585;
v_10586:
    goto v_10587;
v_10588:
    v_10616 = Lapply2(nil, 3, v_10618, v_10617, v_10616);
    env = stack[-6];
    stack[-5] = v_10616;
    goto v_10551;
v_10553:
v_10551:
    goto v_10601;
v_10597:
    v_10617 = stack[-3];
    goto v_10598;
v_10599:
    v_10616 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10600;
v_10601:
    goto v_10597;
v_10598:
    goto v_10599;
v_10600:
    if (v_10617 == v_10616) goto v_10595;
    else goto v_10596;
v_10595:
    v_10616 = stack[-5];
    goto v_10509;
v_10596:
    goto v_10612;
v_10606:
    v_10618 = stack[-2];
    goto v_10607;
v_10608:
    v_10617 = stack[-4];
    goto v_10609;
v_10610:
    v_10616 = stack[-4];
    goto v_10611;
v_10612:
    goto v_10606;
v_10607:
    goto v_10608;
v_10609:
    goto v_10610;
v_10611:
    v_10616 = Lapply2(nil, 3, v_10618, v_10617, v_10616);
    env = stack[-6];
    stack[-4] = v_10616;
    goto v_10510;
v_10509:
    goto v_10403;
    v_10616 = nil;
v_10403:
    return onevalue(v_10616);
}



// Code for lexer_word_starter

static LispObject CC_lexer_word_starter(LispObject env,
                         LispObject v_10399)
{
    env = qenv(env);
    LispObject v_10492, v_10493;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10399);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10399;
// end of prologue
    v_10492 = stack[0];
    v_10492 = Lalpha_char_p(nil, v_10492);
    env = stack[-1];
    if (v_10492 == nil) goto v_10403;
    else goto v_10402;
v_10403:
    goto v_10418;
v_10414:
    v_10493 = stack[0];
    goto v_10415;
v_10416:
    v_10492 = elt(env, 1); // !_
    goto v_10417;
v_10418:
    goto v_10414;
v_10415:
    goto v_10416;
v_10417:
    if (v_10493 == v_10492) goto v_10412;
    else goto v_10413;
v_10412:
    goto v_10427;
v_10423:
    v_10493 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_10424;
v_10425:
    v_10492 = (LispObject)32768+TAG_FIXNUM; // 2048
    goto v_10426;
v_10427:
    goto v_10423;
v_10424:
    goto v_10425;
v_10426:
    fn = elt(env, 5); // land
    v_10492 = (*qfn2(fn))(fn, v_10493, v_10492);
    env = stack[-1];
    v_10492 = (LispObject)zerop(v_10492);
    v_10492 = v_10492 ? lisp_true : nil;
    env = stack[-1];
    v_10492 = (v_10492 == nil ? lisp_true : nil);
    goto v_10411;
v_10413:
    v_10492 = nil;
    goto v_10411;
    v_10492 = nil;
v_10411:
    if (v_10492 == nil) goto v_10409;
    v_10492 = lisp_true;
    goto v_10407;
v_10409:
    goto v_10449;
v_10445:
    v_10493 = stack[0];
    goto v_10446;
v_10447:
    v_10492 = elt(env, 3); // !'
    goto v_10448;
v_10449:
    goto v_10445;
v_10446:
    goto v_10447;
v_10448:
    if (v_10493 == v_10492) goto v_10443;
    else goto v_10444;
v_10443:
    goto v_10458;
v_10454:
    v_10493 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_10455;
v_10456:
    v_10492 = (LispObject)131072+TAG_FIXNUM; // 8192
    goto v_10457;
v_10458:
    goto v_10454;
v_10455:
    goto v_10456;
v_10457:
    fn = elt(env, 5); // land
    v_10492 = (*qfn2(fn))(fn, v_10493, v_10492);
    env = stack[-1];
    v_10492 = (LispObject)zerop(v_10492);
    v_10492 = v_10492 ? lisp_true : nil;
    env = stack[-1];
    v_10492 = (v_10492 == nil ? lisp_true : nil);
    goto v_10442;
v_10444:
    v_10492 = nil;
    goto v_10442;
    v_10492 = nil;
v_10442:
    if (v_10492 == nil) goto v_10440;
    v_10492 = lisp_true;
    goto v_10438;
v_10440:
    goto v_10476;
v_10472:
    v_10493 = stack[0];
    goto v_10473;
v_10474:
    v_10492 = elt(env, 4); // !\ (backslash)
    goto v_10475;
v_10476:
    goto v_10472;
v_10473:
    goto v_10474;
v_10475:
    if (v_10493 == v_10492) goto v_10470;
    else goto v_10471;
v_10470:
    goto v_10485;
v_10481:
    v_10493 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_10482;
v_10483:
    v_10492 = (LispObject)65536+TAG_FIXNUM; // 4096
    goto v_10484;
v_10485:
    goto v_10481;
v_10482:
    goto v_10483;
v_10484:
    fn = elt(env, 5); // land
    v_10492 = (*qfn2(fn))(fn, v_10493, v_10492);
    env = stack[-1];
    v_10492 = (LispObject)zerop(v_10492);
    v_10492 = v_10492 ? lisp_true : nil;
    v_10492 = (v_10492 == nil ? lisp_true : nil);
    goto v_10469;
v_10471:
    v_10492 = nil;
    goto v_10469;
    v_10492 = nil;
v_10469:
    goto v_10438;
    v_10492 = nil;
v_10438:
    goto v_10407;
    v_10492 = nil;
v_10407:
v_10402:
    return onevalue(v_10492);
}



// Code for coeffs

static LispObject CC_coeffs(LispObject env,
                         LispObject v_10399)
{
    env = qenv(env);
    LispObject v_10548, v_10549;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10399);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_10399;
// end of prologue
    stack[-2] = nil;
    v_10548 = stack[-4];
    v_10548 = qcar(v_10548);
    v_10548 = qcar(v_10548);
    v_10548 = qcar(v_10548);
    stack[-1] = v_10548;
    v_10548 = stack[-4];
    v_10548 = qcar(v_10548);
    v_10548 = qcar(v_10548);
    v_10548 = qcdr(v_10548);
    stack[-5] = v_10548;
v_10420:
    v_10548 = stack[-4];
    if (!consp(v_10548)) goto v_10431;
    else goto v_10432;
v_10431:
    v_10548 = lisp_true;
    goto v_10430;
v_10432:
    v_10548 = stack[-4];
    v_10548 = qcar(v_10548);
    v_10548 = (consp(v_10548) ? nil : lisp_true);
    goto v_10430;
    v_10548 = nil;
v_10430:
    if (v_10548 == nil) goto v_10427;
    else goto v_10428;
v_10427:
    goto v_10444;
v_10440:
    v_10548 = stack[-4];
    v_10548 = qcar(v_10548);
    v_10548 = qcar(v_10548);
    v_10549 = qcar(v_10548);
    goto v_10441;
v_10442:
    v_10548 = stack[-1];
    goto v_10443;
v_10444:
    goto v_10440;
v_10441:
    goto v_10442;
v_10443:
    v_10548 = (v_10549 == v_10548 ? lisp_true : nil);
    goto v_10426;
v_10428:
    v_10548 = nil;
    goto v_10426;
    v_10548 = nil;
v_10426:
    if (v_10548 == nil) goto v_10423;
    else goto v_10424;
v_10423:
    goto v_10419;
v_10424:
    v_10548 = stack[-4];
    v_10548 = qcar(v_10548);
    v_10548 = qcar(v_10548);
    v_10548 = qcdr(v_10548);
    stack[-3] = v_10548;
    v_10548 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_10548;
v_10462:
    goto v_10474;
v_10470:
    goto v_10481;
v_10477:
    v_10549 = stack[-5];
    goto v_10478;
v_10479:
    v_10548 = stack[-3];
    goto v_10480;
v_10481:
    goto v_10477;
v_10478:
    goto v_10479;
v_10480:
    v_10548 = difference2(v_10549, v_10548);
    env = stack[-6];
    v_10549 = sub1(v_10548);
    env = stack[-6];
    goto v_10471;
v_10472:
    v_10548 = stack[0];
    goto v_10473;
v_10474:
    goto v_10470;
v_10471:
    goto v_10472;
v_10473:
    v_10548 = difference2(v_10549, v_10548);
    env = stack[-6];
    v_10548 = Lminusp(nil, v_10548);
    env = stack[-6];
    if (v_10548 == nil) goto v_10467;
    goto v_10461;
v_10467:
    goto v_10491;
v_10487:
    v_10549 = nil;
    goto v_10488;
v_10489:
    v_10548 = stack[-2];
    goto v_10490;
v_10491:
    goto v_10487;
v_10488:
    goto v_10489;
v_10490:
    v_10548 = cons(v_10549, v_10548);
    env = stack[-6];
    stack[-2] = v_10548;
    v_10548 = stack[0];
    v_10548 = add1(v_10548);
    env = stack[-6];
    stack[0] = v_10548;
    goto v_10462;
v_10461:
    goto v_10501;
v_10497:
    v_10548 = stack[-4];
    v_10548 = qcar(v_10548);
    v_10549 = qcdr(v_10548);
    goto v_10498;
v_10499:
    v_10548 = stack[-2];
    goto v_10500;
v_10501:
    goto v_10497;
v_10498:
    goto v_10499;
v_10500:
    v_10548 = cons(v_10549, v_10548);
    env = stack[-6];
    stack[-2] = v_10548;
    v_10548 = stack[-4];
    v_10548 = qcdr(v_10548);
    stack[-4] = v_10548;
    v_10548 = stack[-3];
    stack[-5] = v_10548;
    goto v_10420;
v_10419:
    v_10548 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_10548;
v_10512:
    goto v_10524;
v_10520:
    v_10548 = stack[-5];
    v_10549 = sub1(v_10548);
    env = stack[-6];
    goto v_10521;
v_10522:
    v_10548 = stack[0];
    goto v_10523;
v_10524:
    goto v_10520;
v_10521:
    goto v_10522;
v_10523:
    v_10548 = difference2(v_10549, v_10548);
    env = stack[-6];
    v_10548 = Lminusp(nil, v_10548);
    env = stack[-6];
    if (v_10548 == nil) goto v_10517;
    goto v_10511;
v_10517:
    goto v_10534;
v_10530:
    v_10549 = nil;
    goto v_10531;
v_10532:
    v_10548 = stack[-2];
    goto v_10533;
v_10534:
    goto v_10530;
v_10531:
    goto v_10532;
v_10533:
    v_10548 = cons(v_10549, v_10548);
    env = stack[-6];
    stack[-2] = v_10548;
    v_10548 = stack[0];
    v_10548 = add1(v_10548);
    env = stack[-6];
    stack[0] = v_10548;
    goto v_10512;
v_10511:
    goto v_10545;
v_10541:
    v_10549 = stack[-4];
    goto v_10542;
v_10543:
    v_10548 = stack[-2];
    goto v_10544;
v_10545:
    goto v_10541;
v_10542:
    goto v_10543;
v_10544:
    v_10548 = cons(v_10549, v_10548);
        return Lnreverse(nil, v_10548);
    return onevalue(v_10548);
}



// Code for gcref_mkedges!-tgf

static LispObject CC_gcref_mkedgesKtgf(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10424;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_10424 = v_10400;
    stack[-1] = v_10399;
// end of prologue
    stack[-2] = v_10424;
v_10405:
    v_10424 = stack[-2];
    if (v_10424 == nil) goto v_10409;
    else goto v_10410;
v_10409:
    v_10424 = nil;
    goto v_10404;
v_10410:
    v_10424 = stack[-2];
    v_10424 = qcar(v_10424);
    stack[0] = v_10424;
    v_10424 = stack[-1];
    v_10424 = Lprinc(nil, v_10424);
    env = stack[-3];
    v_10424 = elt(env, 1); // " "
    v_10424 = Lprinc(nil, v_10424);
    env = stack[-3];
    v_10424 = stack[0];
    fn = elt(env, 2); // prin2t
    v_10424 = (*qfn1(fn))(fn, v_10424);
    env = stack[-3];
    v_10424 = stack[-2];
    v_10424 = qcdr(v_10424);
    stack[-2] = v_10424;
    goto v_10405;
v_10404:
    return onevalue(v_10424);
}



// Code for replus

static LispObject CC_replus(LispObject env,
                         LispObject v_10399)
{
    env = qenv(env);
    LispObject v_10428, v_10429;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10399);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_10429 = v_10399;
// end of prologue
    v_10428 = v_10429;
    if (v_10428 == nil) goto v_10403;
    else goto v_10404;
v_10403:
    v_10428 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10402;
v_10404:
    v_10428 = v_10429;
    if (!consp(v_10428)) goto v_10407;
    else goto v_10408;
v_10407:
    v_10428 = v_10429;
    goto v_10402;
v_10408:
    v_10428 = v_10429;
    v_10428 = qcdr(v_10428);
    if (v_10428 == nil) goto v_10411;
    else goto v_10412;
v_10411:
    v_10428 = v_10429;
    v_10428 = qcar(v_10428);
    goto v_10402;
v_10412:
    goto v_10424;
v_10420:
    stack[0] = elt(env, 1); // plus
    goto v_10421;
v_10422:
    v_10428 = v_10429;
    fn = elt(env, 2); // unplus
    v_10428 = (*qfn1(fn))(fn, v_10428);
    goto v_10423;
v_10424:
    goto v_10420;
v_10421:
    goto v_10422;
v_10423:
    {
        LispObject v_10431 = stack[0];
        return cons(v_10431, v_10428);
    }
    v_10428 = nil;
v_10402:
    return onevalue(v_10428);
}



// Code for prepsq!*

static LispObject CC_prepsqH(LispObject env,
                         LispObject v_10399)
{
    env = qenv(env);
    LispObject v_10707, v_10708, v_10709;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10399);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_10399;
// end of prologue
// Binding !*combinelogs
// FLUIDBIND: reloadenv=11 litvec-offset=1 saveloc=8
{   bind_fluid_stack bind_fluid_var(-11, 1, -8);
    qvalue(elt(env, 1)) = nil; // !*combinelogs
    v_10707 = stack[-9];
    v_10707 = qcar(v_10707);
    if (v_10707 == nil) goto v_10409;
    else goto v_10410;
v_10409:
    v_10707 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10405;
v_10410:
    v_10707 = qvalue(elt(env, 3)); // ordl!*
    fn = elt(env, 14); // setkorder
    v_10707 = (*qfn1(fn))(fn, v_10707);
    env = stack[-11];
    stack[-10] = v_10707;
    goto v_10422;
v_10418:
    goto v_10428;
v_10424:
    v_10707 = qvalue(elt(env, 4)); // factors!*
    stack[-7] = v_10707;
v_10434:
    v_10707 = stack[-7];
    if (v_10707 == nil) goto v_10439;
    else goto v_10440;
v_10439:
    v_10707 = nil;
    v_10708 = v_10707;
    goto v_10433;
v_10440:
    v_10707 = stack[-7];
    v_10707 = qcar(v_10707);
    v_10708 = v_10707;
    v_10707 = v_10708;
    if (symbolp(v_10707)) goto v_10449;
    v_10707 = nil;
    goto v_10447;
v_10449:
    goto v_10459;
v_10455:
    v_10709 = v_10708;
    goto v_10456;
v_10457:
    v_10707 = elt(env, 5); // prepsq!*fn
    goto v_10458;
v_10459:
    goto v_10455;
v_10456:
    goto v_10457;
v_10458:
    v_10707 = get(v_10709, v_10707);
    env = stack[-11];
    v_10709 = v_10707;
    if (v_10707 == nil) goto v_10453;
    goto v_10469;
v_10463:
    goto v_10464;
v_10465:
    v_10707 = stack[-9];
    goto v_10466;
v_10467:
    goto v_10468;
v_10469:
    goto v_10463;
v_10464:
    goto v_10465;
v_10466:
    goto v_10467;
v_10468:
    v_10707 = Lapply2(nil, 3, v_10709, v_10707, v_10708);
    env = stack[-11];
    goto v_10447;
v_10453:
    v_10707 = v_10708;
    if (!symbolp(v_10707)) v_10707 = nil;
    else { v_10707 = qfastgets(v_10707);
           if (v_10707 != nil) { v_10707 = elt(v_10707, 24); // klist
#ifdef RECORD_GET
             if (v_10707 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v_10707 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v_10707 == SPID_NOPROP) v_10707 = nil; }}
#endif
    stack[-3] = v_10707;
    v_10707 = stack[-3];
    if (v_10707 == nil) goto v_10485;
    else goto v_10486;
v_10485:
    v_10707 = nil;
    goto v_10479;
v_10486:
    v_10707 = stack[-3];
    v_10707 = qcar(v_10707);
    v_10707 = qcar(v_10707);
    v_10707 = ncons(v_10707);
    env = stack[-11];
    stack[-1] = v_10707;
    stack[-2] = v_10707;
v_10480:
    v_10707 = stack[-3];
    v_10707 = qcdr(v_10707);
    stack[-3] = v_10707;
    v_10707 = stack[-3];
    if (v_10707 == nil) goto v_10499;
    else goto v_10500;
v_10499:
    v_10707 = stack[-2];
    goto v_10479;
v_10500:
    goto v_10508;
v_10504:
    stack[0] = stack[-1];
    goto v_10505;
v_10506:
    v_10707 = stack[-3];
    v_10707 = qcar(v_10707);
    v_10707 = qcar(v_10707);
    v_10707 = ncons(v_10707);
    env = stack[-11];
    goto v_10507;
v_10508:
    goto v_10504;
v_10505:
    goto v_10506;
v_10507:
    v_10707 = Lrplacd(nil, stack[0], v_10707);
    env = stack[-11];
    v_10707 = stack[-1];
    v_10707 = qcdr(v_10707);
    stack[-1] = v_10707;
    goto v_10480;
v_10479:
    goto v_10447;
    v_10707 = nil;
v_10447:
    stack[-6] = v_10707;
    v_10707 = stack[-6];
    fn = elt(env, 15); // lastpair
    v_10707 = (*qfn1(fn))(fn, v_10707);
    env = stack[-11];
    stack[-5] = v_10707;
    v_10707 = stack[-7];
    v_10707 = qcdr(v_10707);
    stack[-7] = v_10707;
    v_10707 = stack[-5];
    if (!consp(v_10707)) goto v_10524;
    else goto v_10525;
v_10524:
    goto v_10434;
v_10525:
v_10435:
    v_10707 = stack[-7];
    if (v_10707 == nil) goto v_10529;
    else goto v_10530;
v_10529:
    v_10707 = stack[-6];
    v_10708 = v_10707;
    goto v_10433;
v_10530:
    goto v_10538;
v_10534:
    stack[-4] = stack[-5];
    goto v_10535;
v_10536:
    v_10707 = stack[-7];
    v_10707 = qcar(v_10707);
    v_10708 = v_10707;
    if (symbolp(v_10708)) goto v_10546;
    v_10707 = nil;
    goto v_10544;
v_10546:
    goto v_10556;
v_10552:
    v_10709 = v_10707;
    goto v_10553;
v_10554:
    v_10708 = elt(env, 5); // prepsq!*fn
    goto v_10555;
v_10556:
    goto v_10552;
v_10553:
    goto v_10554;
v_10555:
    v_10708 = get(v_10709, v_10708);
    env = stack[-11];
    v_10709 = v_10708;
    if (v_10708 == nil) goto v_10550;
    goto v_10566;
v_10560:
    goto v_10561;
v_10562:
    v_10708 = stack[-9];
    goto v_10563;
v_10564:
    goto v_10565;
v_10566:
    goto v_10560;
v_10561:
    goto v_10562;
v_10563:
    goto v_10564;
v_10565:
    v_10707 = Lapply2(nil, 3, v_10709, v_10708, v_10707);
    env = stack[-11];
    goto v_10544;
v_10550:
    if (!symbolp(v_10707)) v_10707 = nil;
    else { v_10707 = qfastgets(v_10707);
           if (v_10707 != nil) { v_10707 = elt(v_10707, 24); // klist
#ifdef RECORD_GET
             if (v_10707 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v_10707 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v_10707 == SPID_NOPROP) v_10707 = nil; }}
#endif
    stack[-3] = v_10707;
    v_10707 = stack[-3];
    if (v_10707 == nil) goto v_10582;
    else goto v_10583;
v_10582:
    v_10707 = nil;
    goto v_10576;
v_10583:
    v_10707 = stack[-3];
    v_10707 = qcar(v_10707);
    v_10707 = qcar(v_10707);
    v_10707 = ncons(v_10707);
    env = stack[-11];
    stack[-1] = v_10707;
    stack[-2] = v_10707;
v_10577:
    v_10707 = stack[-3];
    v_10707 = qcdr(v_10707);
    stack[-3] = v_10707;
    v_10707 = stack[-3];
    if (v_10707 == nil) goto v_10596;
    else goto v_10597;
v_10596:
    v_10707 = stack[-2];
    goto v_10576;
v_10597:
    goto v_10605;
v_10601:
    stack[0] = stack[-1];
    goto v_10602;
v_10603:
    v_10707 = stack[-3];
    v_10707 = qcar(v_10707);
    v_10707 = qcar(v_10707);
    v_10707 = ncons(v_10707);
    env = stack[-11];
    goto v_10604;
v_10605:
    goto v_10601;
v_10602:
    goto v_10603;
v_10604:
    v_10707 = Lrplacd(nil, stack[0], v_10707);
    env = stack[-11];
    v_10707 = stack[-1];
    v_10707 = qcdr(v_10707);
    stack[-1] = v_10707;
    goto v_10577;
v_10576:
    goto v_10544;
    v_10707 = nil;
v_10544:
    goto v_10537;
v_10538:
    goto v_10534;
v_10535:
    goto v_10536;
v_10537:
    v_10707 = Lrplacd(nil, stack[-4], v_10707);
    env = stack[-11];
    v_10707 = stack[-5];
    fn = elt(env, 15); // lastpair
    v_10707 = (*qfn1(fn))(fn, v_10707);
    env = stack[-11];
    stack[-5] = v_10707;
    v_10707 = stack[-7];
    v_10707 = qcdr(v_10707);
    stack[-7] = v_10707;
    goto v_10435;
v_10433:
    goto v_10425;
v_10426:
    v_10707 = elt(env, 6); // ordop
    goto v_10427;
v_10428:
    goto v_10424;
v_10425:
    goto v_10426;
v_10427:
    fn = elt(env, 16); // sort
    stack[0] = (*qfn2(fn))(fn, v_10708, v_10707);
    env = stack[-11];
    goto v_10419;
v_10420:
    goto v_10625;
v_10621:
    goto v_10631;
v_10627:
    v_10708 = qvalue(elt(env, 4)); // factors!*
    goto v_10628;
v_10629:
    v_10707 = elt(env, 6); // ordop
    goto v_10630;
v_10631:
    goto v_10627;
v_10628:
    goto v_10629;
v_10630:
    fn = elt(env, 16); // sort
    v_10708 = (*qfn2(fn))(fn, v_10708, v_10707);
    env = stack[-11];
    goto v_10622;
v_10623:
    v_10707 = qvalue(elt(env, 3)); // ordl!*
    goto v_10624;
v_10625:
    goto v_10621;
v_10622:
    goto v_10623;
v_10624:
    v_10707 = Lappend(nil, v_10708, v_10707);
    env = stack[-11];
    goto v_10421;
v_10422:
    goto v_10418;
v_10419:
    goto v_10420;
v_10421:
    v_10707 = Lappend(nil, stack[0], v_10707);
    env = stack[-11];
    fn = elt(env, 14); // setkorder
    v_10707 = (*qfn1(fn))(fn, v_10707);
    env = stack[-11];
    goto v_10647;
v_10643:
    v_10708 = qvalue(elt(env, 7)); // kord!*
    goto v_10644;
v_10645:
    v_10707 = stack[-10];
    goto v_10646;
v_10647:
    goto v_10643;
v_10644:
    goto v_10645;
v_10646:
    if (equal(v_10708, v_10707)) goto v_10642;
    v_10707 = lisp_true;
    goto v_10640;
v_10642:
    v_10707 = qvalue(elt(env, 8)); // wtl!*
    goto v_10640;
    v_10707 = nil;
v_10640:
    if (v_10707 == nil) goto v_10638;
    goto v_10659;
v_10655:
    v_10707 = stack[-9];
    v_10707 = qcar(v_10707);
    fn = elt(env, 17); // formop
    stack[0] = (*qfn1(fn))(fn, v_10707);
    env = stack[-11];
    goto v_10656;
v_10657:
    v_10707 = stack[-9];
    v_10707 = qcdr(v_10707);
    fn = elt(env, 17); // formop
    v_10707 = (*qfn1(fn))(fn, v_10707);
    env = stack[-11];
    goto v_10658;
v_10659:
    goto v_10655;
v_10656:
    goto v_10657;
v_10658:
    v_10707 = cons(stack[0], v_10707);
    env = stack[-11];
    stack[-9] = v_10707;
    goto v_10636;
v_10638:
v_10636:
    v_10707 = qvalue(elt(env, 9)); // !*rat
    if (v_10707 == nil) goto v_10670;
    else goto v_10668;
v_10670:
    v_10707 = qvalue(elt(env, 10)); // !*div
    if (v_10707 == nil) goto v_10673;
    else goto v_10668;
v_10673:
    v_10707 = qvalue(elt(env, 11)); // upl!*
    if (v_10707 == nil) goto v_10676;
    else goto v_10668;
v_10676:
    v_10707 = qvalue(elt(env, 12)); // dnl!*
    if (v_10707 == nil) goto v_10678;
    else goto v_10668;
v_10678:
    goto v_10669;
v_10668:
    goto v_10688;
v_10682:
    v_10707 = stack[-9];
    v_10709 = qcar(v_10707);
    goto v_10683;
v_10684:
    v_10707 = stack[-9];
    v_10708 = qcdr(v_10707);
    goto v_10685;
v_10686:
    v_10707 = nil;
    goto v_10687;
v_10688:
    goto v_10682;
v_10683:
    goto v_10684;
v_10685:
    goto v_10686;
v_10687:
    fn = elt(env, 18); // prepsq!*1
    v_10707 = (*qfnn(fn))(fn, 3, v_10709, v_10708, v_10707);
    env = stack[-11];
    fn = elt(env, 19); // replus
    v_10707 = (*qfn1(fn))(fn, v_10707);
    env = stack[-11];
    goto v_10667;
v_10669:
    goto v_10701;
v_10697:
    v_10708 = stack[-9];
    goto v_10698;
v_10699:
    v_10707 = elt(env, 13); // prepsq!*2
    goto v_10700;
v_10701:
    goto v_10697;
v_10698:
    goto v_10699;
v_10700:
    fn = elt(env, 20); // sqform
    v_10707 = (*qfn2(fn))(fn, v_10708, v_10707);
    env = stack[-11];
    goto v_10667;
    v_10707 = nil;
v_10667:
    stack[-9] = v_10707;
    v_10707 = stack[-10];
    fn = elt(env, 14); // setkorder
    v_10707 = (*qfn1(fn))(fn, v_10707);
    v_10707 = stack[-9];
v_10405:
    ;}  // end of a binding scope
    return onevalue(v_10707);
}



// Code for qqe_simplterm

static LispObject CC_qqe_simplterm(LispObject env,
                         LispObject v_10399)
{
    env = qenv(env);
    LispObject v_10454, v_10455, v_10456;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10399);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10399;
// end of prologue
    v_10454 = stack[0];
    if (!consp(v_10454)) goto v_10407;
    else goto v_10408;
v_10407:
    v_10454 = stack[0];
    goto v_10403;
v_10408:
    v_10454 = stack[0];
    fn = elt(env, 5); // qqe_op
    v_10454 = (*qfn1(fn))(fn, v_10454);
    env = stack[-1];
    v_10456 = v_10454;
    goto v_10421;
v_10417:
    v_10455 = v_10456;
    goto v_10418;
v_10419:
    v_10454 = elt(env, 2); // (ltail rtail)
    goto v_10420;
v_10421:
    goto v_10417;
v_10418:
    goto v_10419;
v_10420:
    v_10454 = Lmemq(nil, v_10455, v_10454);
    if (v_10454 == nil) goto v_10416;
    v_10454 = stack[0];
    {
        fn = elt(env, 6); // qqe_simplterm!-tail
        return (*qfn1(fn))(fn, v_10454);
    }
v_10416:
    goto v_10433;
v_10429:
    v_10455 = v_10456;
    goto v_10430;
v_10431:
    v_10454 = elt(env, 3); // (lhead rhead)
    goto v_10432;
v_10433:
    goto v_10429;
v_10430:
    goto v_10431;
v_10432:
    v_10454 = Lmemq(nil, v_10455, v_10454);
    if (v_10454 == nil) goto v_10428;
    v_10454 = stack[0];
    {
        fn = elt(env, 7); // qqe_simplterm!-head
        return (*qfn1(fn))(fn, v_10454);
    }
v_10428:
    goto v_10445;
v_10441:
    v_10455 = v_10456;
    goto v_10442;
v_10443:
    v_10454 = elt(env, 4); // (ladd radd)
    goto v_10444;
v_10445:
    goto v_10441;
v_10442:
    goto v_10443;
v_10444:
    v_10454 = Lmemq(nil, v_10455, v_10454);
    if (v_10454 == nil) goto v_10440;
    v_10454 = stack[0];
    {
        fn = elt(env, 8); // qqe_simplterm!-add
        return (*qfn1(fn))(fn, v_10454);
    }
v_10440:
    v_10454 = stack[0];
    goto v_10403;
    v_10454 = nil;
v_10403:
    return onevalue(v_10454);
}



// Code for make!-univariate!-image!-mod!-p

static LispObject CC_makeKunivariateKimageKmodKp(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10642, v_10643, v_10644;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_10400;
    stack[-2] = v_10399;
// end of prologue
    v_10642 = stack[-2];
    if (!consp(v_10642)) goto v_10413;
    else goto v_10414;
v_10413:
    v_10642 = lisp_true;
    goto v_10412;
v_10414:
    v_10642 = stack[-2];
    v_10642 = qcar(v_10642);
    v_10642 = (consp(v_10642) ? nil : lisp_true);
    goto v_10412;
    v_10642 = nil;
v_10412:
    if (v_10642 == nil) goto v_10410;
    v_10642 = stack[-2];
    if (v_10642 == nil) goto v_10424;
    else goto v_10425;
v_10424:
    v_10642 = nil;
    goto v_10405;
v_10425:
    v_10642 = stack[-2];
    v_10642 = Lmodular_number(nil, v_10642);
    env = stack[-4];
    {
        fn = elt(env, 2); // !*n2f
        return (*qfn1(fn))(fn, v_10642);
    }
    goto v_10408;
v_10410:
v_10408:
    goto v_10441;
v_10437:
    v_10642 = stack[-2];
    v_10642 = qcar(v_10642);
    v_10642 = qcar(v_10642);
    v_10643 = qcar(v_10642);
    goto v_10438;
v_10439:
    v_10642 = stack[-1];
    goto v_10440;
v_10441:
    goto v_10437;
v_10438:
    goto v_10439;
v_10440:
    if (equal(v_10643, v_10642)) goto v_10435;
    else goto v_10436;
v_10435:
    v_10642 = nil;
    stack[0] = v_10642;
v_10450:
    v_10642 = stack[-2];
    if (!consp(v_10642)) goto v_10461;
    else goto v_10462;
v_10461:
    v_10642 = lisp_true;
    goto v_10460;
v_10462:
    v_10642 = stack[-2];
    v_10642 = qcar(v_10642);
    v_10642 = (consp(v_10642) ? nil : lisp_true);
    goto v_10460;
    v_10642 = nil;
v_10460:
    if (v_10642 == nil) goto v_10457;
    else goto v_10458;
v_10457:
    goto v_10474;
v_10470:
    v_10642 = stack[-2];
    v_10642 = qcar(v_10642);
    v_10642 = qcar(v_10642);
    v_10643 = qcar(v_10642);
    goto v_10471;
v_10472:
    v_10642 = stack[-1];
    goto v_10473;
v_10474:
    goto v_10470;
v_10471:
    goto v_10472;
v_10473:
    v_10642 = (equal(v_10643, v_10642) ? lisp_true : nil);
    goto v_10456;
v_10458:
    v_10642 = nil;
    goto v_10456;
    v_10642 = nil;
v_10456:
    if (v_10642 == nil) goto v_10453;
    else goto v_10454;
v_10453:
    goto v_10449;
v_10454:
    goto v_10490;
v_10486:
    v_10642 = stack[-2];
    v_10642 = qcar(v_10642);
    v_10643 = qcdr(v_10642);
    goto v_10487;
v_10488:
    v_10642 = stack[-1];
    goto v_10489;
v_10490:
    goto v_10486;
v_10487:
    goto v_10488;
v_10489:
    v_10642 = CC_makeKunivariateKimageKmodKp(elt(env, 0), v_10643, v_10642);
    env = stack[-4];
    stack[-3] = v_10642;
    v_10642 = stack[-3];
    if (v_10642 == nil) goto v_10498;
    goto v_10507;
v_10501:
    v_10642 = stack[-2];
    v_10642 = qcar(v_10642);
    v_10644 = qcar(v_10642);
    goto v_10502;
v_10503:
    v_10643 = stack[-3];
    goto v_10504;
v_10505:
    v_10642 = stack[0];
    goto v_10506;
v_10507:
    goto v_10501;
v_10502:
    goto v_10503;
v_10504:
    goto v_10505;
v_10506:
    v_10642 = acons(v_10644, v_10643, v_10642);
    env = stack[-4];
    stack[0] = v_10642;
    goto v_10496;
v_10498:
v_10496:
    v_10642 = stack[-2];
    v_10642 = qcdr(v_10642);
    stack[-2] = v_10642;
    goto v_10450;
v_10449:
    goto v_10520;
v_10516:
    v_10643 = stack[-2];
    goto v_10517;
v_10518:
    v_10642 = stack[-1];
    goto v_10519;
v_10520:
    goto v_10516;
v_10517:
    goto v_10518;
v_10519:
    v_10642 = CC_makeKunivariateKimageKmodKp(elt(env, 0), v_10643, v_10642);
    env = stack[-4];
    stack[-2] = v_10642;
v_10526:
    v_10642 = stack[0];
    if (v_10642 == nil) goto v_10529;
    else goto v_10530;
v_10529:
    goto v_10525;
v_10530:
    v_10642 = stack[0];
    v_10642 = qcdr(v_10642);
    stack[-3] = v_10642;
    goto v_10540;
v_10536:
    v_10643 = stack[0];
    goto v_10537;
v_10538:
    v_10642 = stack[-2];
    goto v_10539;
v_10540:
    goto v_10536;
v_10537:
    goto v_10538;
v_10539:
    v_10642 = Lrplacd(nil, v_10643, v_10642);
    env = stack[-4];
    v_10642 = stack[0];
    stack[-2] = v_10642;
    v_10642 = stack[-3];
    stack[0] = v_10642;
    goto v_10526;
v_10525:
    v_10642 = stack[-2];
    goto v_10405;
v_10436:
    v_10642 = nil;
    stack[0] = v_10642;
v_10551:
    v_10642 = stack[-2];
    if (!consp(v_10642)) goto v_10562;
    else goto v_10563;
v_10562:
    v_10642 = lisp_true;
    goto v_10561;
v_10563:
    v_10642 = stack[-2];
    v_10642 = qcar(v_10642);
    v_10642 = (consp(v_10642) ? nil : lisp_true);
    goto v_10561;
    v_10642 = nil;
v_10561:
    if (v_10642 == nil) goto v_10558;
    else goto v_10559;
v_10558:
    goto v_10575;
v_10571:
    v_10642 = stack[-2];
    v_10642 = qcar(v_10642);
    v_10642 = qcar(v_10642);
    v_10643 = qcar(v_10642);
    goto v_10572;
v_10573:
    v_10642 = stack[-1];
    goto v_10574;
v_10575:
    goto v_10571;
v_10572:
    goto v_10573;
v_10574:
    v_10642 = (equal(v_10643, v_10642) ? lisp_true : nil);
    v_10642 = (v_10642 == nil ? lisp_true : nil);
    goto v_10557;
v_10559:
    v_10642 = nil;
    goto v_10557;
    v_10642 = nil;
v_10557:
    if (v_10642 == nil) goto v_10554;
    else goto v_10555;
v_10554:
    goto v_10550;
v_10555:
    goto v_10592;
v_10588:
    stack[-3] = stack[0];
    goto v_10589;
v_10590:
    goto v_10599;
v_10595:
    goto v_10605;
v_10601:
    v_10642 = stack[-2];
    v_10642 = qcar(v_10642);
    v_10642 = qcar(v_10642);
    v_10643 = qcar(v_10642);
    goto v_10602;
v_10603:
    v_10642 = stack[-2];
    v_10642 = qcar(v_10642);
    v_10642 = qcar(v_10642);
    v_10642 = qcdr(v_10642);
    goto v_10604;
v_10605:
    goto v_10601;
v_10602:
    goto v_10603;
v_10604:
    fn = elt(env, 3); // image!-of!-power
    stack[0] = (*qfn2(fn))(fn, v_10643, v_10642);
    env = stack[-4];
    goto v_10596;
v_10597:
    goto v_10619;
v_10615:
    v_10642 = stack[-2];
    v_10642 = qcar(v_10642);
    v_10643 = qcdr(v_10642);
    goto v_10616;
v_10617:
    v_10642 = stack[-1];
    goto v_10618;
v_10619:
    goto v_10615;
v_10616:
    goto v_10617;
v_10618:
    v_10642 = CC_makeKunivariateKimageKmodKp(elt(env, 0), v_10643, v_10642);
    env = stack[-4];
    goto v_10598;
v_10599:
    goto v_10595;
v_10596:
    goto v_10597;
v_10598:
    fn = elt(env, 4); // times!-mod!-p
    v_10642 = (*qfn2(fn))(fn, stack[0], v_10642);
    env = stack[-4];
    goto v_10591;
v_10592:
    goto v_10588;
v_10589:
    goto v_10590;
v_10591:
    fn = elt(env, 5); // plus!-mod!-p
    v_10642 = (*qfn2(fn))(fn, stack[-3], v_10642);
    env = stack[-4];
    stack[0] = v_10642;
    v_10642 = stack[-2];
    v_10642 = qcdr(v_10642);
    stack[-2] = v_10642;
    goto v_10551;
v_10550:
    goto v_10631;
v_10627:
    v_10643 = stack[-2];
    goto v_10628;
v_10629:
    v_10642 = stack[-1];
    goto v_10630;
v_10631:
    goto v_10627;
v_10628:
    goto v_10629;
v_10630:
    v_10642 = CC_makeKunivariateKimageKmodKp(elt(env, 0), v_10643, v_10642);
    env = stack[-4];
    stack[-2] = v_10642;
    goto v_10639;
v_10635:
    v_10643 = stack[0];
    goto v_10636;
v_10637:
    v_10642 = stack[-2];
    goto v_10638;
v_10639:
    goto v_10635;
v_10636:
    goto v_10637;
v_10638:
    {
        fn = elt(env, 5); // plus!-mod!-p
        return (*qfn2(fn))(fn, v_10643, v_10642);
    }
    v_10642 = nil;
v_10405:
    return onevalue(v_10642);
}



// Code for exptpri

static LispObject CC_exptpri(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10817, v_10818, v_10819;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    v_10817 = v_10400;
    stack[-5] = v_10399;
// end of prologue
    v_10818 = qvalue(elt(env, 1)); // !*utf8
    if (v_10818 == nil) goto v_10405;
    goto v_10412;
v_10408:
    v_10818 = stack[-5];
    goto v_10409;
v_10410:
    goto v_10411;
v_10412:
    goto v_10408;
v_10409:
    goto v_10410;
v_10411:
    {
        fn = elt(env, 20); // utf8_exptpri
        return (*qfn2(fn))(fn, v_10818, v_10817);
    }
v_10405:
// Binding !*list
// FLUIDBIND: reloadenv=7 litvec-offset=2 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 2, -6);
    qvalue(elt(env, 2)) = nil; // !*list
    stack[0] = nil;
    v_10818 = qvalue(elt(env, 4)); // !*nat
    if (v_10818 == nil) goto v_10432;
    else goto v_10433;
v_10432:
    v_10818 = lisp_true;
    goto v_10431;
v_10433:
    v_10818 = qvalue(elt(env, 5)); // !*fort
    goto v_10431;
    v_10818 = nil;
v_10431:
    if (v_10818 == nil) goto v_10429;
    v_10817 = elt(env, 6); // failed
    goto v_10424;
v_10429:
    goto v_10445;
v_10441:
    v_10818 = elt(env, 7); // expt
    if (!symbolp(v_10818)) v_10818 = nil;
    else { v_10818 = qfastgets(v_10818);
           if (v_10818 != nil) { v_10818 = elt(v_10818, 23); // infix
#ifdef RECORD_GET
             if (v_10818 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_10818 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_10818 == SPID_NOPROP) v_10818 = nil; }}
#endif
    stack[-2] = v_10818;
    goto v_10442;
v_10443:
    goto v_10444;
v_10445:
    goto v_10441;
v_10442:
    goto v_10443;
v_10444:
    v_10817 = (LispObject)greaterp2(v_10818, v_10817);
    v_10817 = v_10817 ? lisp_true : nil;
    env = stack[-7];
    v_10817 = (v_10817 == nil ? lisp_true : nil);
    stack[-4] = v_10817;
    v_10817 = stack[-5];
    v_10817 = qcdr(v_10817);
    v_10817 = qcar(v_10817);
    stack[-1] = v_10817;
    v_10817 = stack[-5];
    v_10817 = qcdr(v_10817);
    v_10817 = qcdr(v_10817);
    v_10817 = qcar(v_10817);
    stack[-3] = v_10817;
    v_10817 = qvalue(elt(env, 8)); // !*eraise
    if (v_10817 == nil) goto v_10460;
    v_10817 = stack[-1];
    if (!consp(v_10817)) goto v_10467;
    v_10817 = stack[-1];
    v_10817 = qcar(v_10817);
    if (!symbolp(v_10817)) v_10817 = nil;
    else { v_10817 = qfastgets(v_10817);
           if (v_10817 != nil) { v_10817 = elt(v_10817, 57); // prifn
#ifdef RECORD_GET
             if (v_10817 != SPID_NOPROP)
                record_get(elt(fastget_names, 57), 1);
             else record_get(elt(fastget_names, 57), 0),
                v_10817 = nil; }
           else record_get(elt(fastget_names, 57), 0); }
#else
             if (v_10817 == SPID_NOPROP) v_10817 = nil; }}
#endif
    stack[0] = v_10817;
    if (v_10817 == nil) goto v_10471;
    else goto v_10472;
v_10471:
    v_10817 = nil;
    goto v_10470;
v_10472:
    goto v_10483;
v_10479:
    goto v_10489;
v_10485:
    v_10818 = stack[0];
    goto v_10486;
v_10487:
    v_10817 = elt(env, 7); // expt
    goto v_10488;
v_10489:
    goto v_10485;
v_10486:
    goto v_10487;
v_10488:
    v_10818 = get(v_10818, v_10817);
    env = stack[-7];
    goto v_10480;
v_10481:
    v_10817 = elt(env, 9); // inbrackets
    goto v_10482;
v_10483:
    goto v_10479;
v_10480:
    goto v_10481;
v_10482:
    v_10817 = (v_10818 == v_10817 ? lisp_true : nil);
    goto v_10470;
    v_10817 = nil;
v_10470:
    goto v_10465;
v_10467:
    v_10817 = nil;
    goto v_10465;
    v_10817 = nil;
v_10465:
    if (v_10817 == nil) goto v_10460;
    goto v_10504;
v_10498:
    v_10819 = stack[-1];
    goto v_10499;
v_10500:
    v_10818 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10501;
v_10502:
    v_10817 = elt(env, 9); // inbrackets
    goto v_10503;
v_10504:
    goto v_10498;
v_10499:
    goto v_10500;
v_10501:
    goto v_10502;
v_10503:
    fn = elt(env, 21); // layout!-formula
    v_10817 = (*qfnn(fn))(fn, 3, v_10819, v_10818, v_10817);
    env = stack[-7];
    stack[-1] = v_10817;
    goto v_10458;
v_10460:
    goto v_10518;
v_10514:
    v_10818 = stack[0];
    goto v_10515;
v_10516:
    v_10817 = elt(env, 10); // indexprin
    goto v_10517;
v_10518:
    goto v_10514;
v_10515:
    goto v_10516;
v_10517:
    if (v_10818 == v_10817) goto v_10512;
    else goto v_10513;
v_10512:
    goto v_10525;
v_10521:
    goto v_10531;
v_10527:
    v_10818 = stack[-1];
    goto v_10528;
v_10529:
    v_10817 = stack[-3];
    goto v_10530;
v_10531:
    goto v_10527;
v_10528:
    goto v_10529;
v_10530:
    fn = elt(env, 22); // indexpower
    v_10818 = (*qfn2(fn))(fn, v_10818, v_10817);
    env = stack[-7];
    goto v_10522;
v_10523:
    v_10817 = elt(env, 6); // failed
    goto v_10524;
v_10525:
    goto v_10521;
v_10522:
    goto v_10523;
v_10524:
    v_10817 = (v_10818 == v_10817 ? lisp_true : nil);
    v_10817 = (v_10817 == nil ? lisp_true : nil);
    goto v_10511;
v_10513:
    v_10817 = nil;
    goto v_10511;
    v_10817 = nil;
v_10511:
    if (v_10817 == nil) goto v_10509;
    v_10817 = nil;
    goto v_10424;
v_10509:
    goto v_10550;
v_10544:
    v_10819 = stack[-1];
    goto v_10545;
v_10546:
    v_10818 = stack[-2];
    goto v_10547;
v_10548:
    v_10817 = nil;
    goto v_10549;
v_10550:
    goto v_10544;
v_10545:
    goto v_10546;
v_10547:
    goto v_10548;
v_10549:
    fn = elt(env, 21); // layout!-formula
    v_10817 = (*qfnn(fn))(fn, 3, v_10819, v_10818, v_10817);
    env = stack[-7];
    stack[-1] = v_10817;
    goto v_10458;
v_10458:
    v_10817 = stack[-1];
    if (v_10817 == nil) goto v_10556;
    else goto v_10557;
v_10556:
    v_10817 = elt(env, 6); // failed
    goto v_10424;
v_10557:
// Binding !*ratpri
// FLUIDBIND: reloadenv=7 litvec-offset=11 saveloc=5
{   bind_fluid_stack bind_fluid_var(-7, 11, -5);
    qvalue(elt(env, 11)) = nil; // !*ratpri
    goto v_10577;
v_10573:
    v_10818 = stack[-3];
    goto v_10574;
v_10575:
    v_10817 = elt(env, 13); // quotient
    goto v_10576;
v_10577:
    goto v_10573;
v_10574:
    goto v_10575;
v_10576:
    if (!consp(v_10818)) goto v_10571;
    v_10818 = qcar(v_10818);
    if (v_10818 == v_10817) goto v_10570;
    else goto v_10571;
v_10570:
    goto v_10585;
v_10581:
    v_10817 = stack[-3];
    v_10817 = qcdr(v_10817);
    v_10818 = qcar(v_10817);
    goto v_10582;
v_10583:
    v_10817 = elt(env, 14); // minus
    goto v_10584;
v_10585:
    goto v_10581;
v_10582:
    goto v_10583;
v_10584:
    v_10817 = Leqcar(nil, v_10818, v_10817);
    env = stack[-7];
    goto v_10569;
v_10571:
    v_10817 = nil;
    goto v_10569;
    v_10817 = nil;
v_10569:
    if (v_10817 == nil) goto v_10567;
    goto v_10598;
v_10594:
    stack[0] = elt(env, 14); // minus
    goto v_10595;
v_10596:
    goto v_10607;
v_10601:
    v_10817 = stack[-3];
    v_10819 = qcar(v_10817);
    goto v_10602;
v_10603:
    v_10817 = stack[-3];
    v_10817 = qcdr(v_10817);
    v_10817 = qcar(v_10817);
    v_10817 = qcdr(v_10817);
    v_10818 = qcar(v_10817);
    goto v_10604;
v_10605:
    v_10817 = stack[-3];
    v_10817 = qcdr(v_10817);
    v_10817 = qcdr(v_10817);
    v_10817 = qcar(v_10817);
    goto v_10606;
v_10607:
    goto v_10601;
v_10602:
    goto v_10603;
v_10604:
    goto v_10605;
v_10606:
    v_10817 = list3(v_10819, v_10818, v_10817);
    env = stack[-7];
    goto v_10597;
v_10598:
    goto v_10594;
v_10595:
    goto v_10596;
v_10597:
    v_10817 = list2(stack[0], v_10817);
    env = stack[-7];
    stack[-3] = v_10817;
    goto v_10565;
v_10567:
    v_10817 = stack[-3];
    fn = elt(env, 23); // negnumberchk
    v_10817 = (*qfn1(fn))(fn, v_10817);
    env = stack[-7];
    stack[-3] = v_10817;
    goto v_10565;
v_10565:
    goto v_10630;
v_10624:
    v_10819 = stack[-3];
    goto v_10625;
v_10626:
    v_10817 = qvalue(elt(env, 8)); // !*eraise
    if (v_10817 == nil) goto v_10635;
    v_10817 = (LispObject)0+TAG_FIXNUM; // 0
    v_10818 = v_10817;
    goto v_10633;
v_10635:
    v_10817 = stack[-2];
    v_10818 = v_10817;
    goto v_10633;
    v_10818 = nil;
v_10633:
    goto v_10627;
v_10628:
    v_10817 = nil;
    goto v_10629;
v_10630:
    goto v_10624;
v_10625:
    goto v_10626;
v_10627:
    goto v_10628;
v_10629:
    fn = elt(env, 21); // layout!-formula
    v_10817 = (*qfnn(fn))(fn, 3, v_10819, v_10818, v_10817);
    env = stack[-7];
    stack[-3] = v_10817;
    ;}  // end of a binding scope
    v_10817 = stack[-3];
    if (v_10817 == nil) goto v_10644;
    else goto v_10645;
v_10644:
    v_10817 = elt(env, 6); // failed
    goto v_10424;
v_10645:
    goto v_10653;
v_10649:
    v_10817 = stack[-1];
    v_10817 = qcar(v_10817);
    v_10818 = qcdr(v_10817);
    goto v_10650;
v_10651:
    v_10817 = stack[-3];
    v_10817 = qcar(v_10817);
    v_10817 = qcdr(v_10817);
    goto v_10652;
v_10653:
    goto v_10649;
v_10650:
    goto v_10651;
v_10652:
    v_10817 = plus2(v_10818, v_10817);
    env = stack[-7];
    stack[-5] = v_10817;
    v_10817 = stack[-4];
    if (v_10817 == nil) goto v_10663;
    goto v_10670;
v_10666:
    v_10818 = stack[-5];
    goto v_10667;
v_10668:
    v_10817 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10669;
v_10670:
    goto v_10666;
v_10667:
    goto v_10668;
v_10669:
    v_10817 = plus2(v_10818, v_10817);
    env = stack[-7];
    stack[-5] = v_10817;
    goto v_10661;
v_10663:
v_10661:
    goto v_10682;
v_10678:
    stack[0] = stack[-5];
    goto v_10679;
v_10680:
    goto v_10689;
v_10685:
    goto v_10695;
v_10691:
    v_10817 = nil;
    v_10818 = Llinelength(nil, v_10817);
    env = stack[-7];
    goto v_10692;
v_10693:
    v_10817 = qvalue(elt(env, 15)); // spare!*
    goto v_10694;
v_10695:
    goto v_10691;
v_10692:
    goto v_10693;
v_10694:
    v_10818 = difference2(v_10818, v_10817);
    env = stack[-7];
    goto v_10686;
v_10687:
    v_10817 = qvalue(elt(env, 16)); // orig!*
    goto v_10688;
v_10689:
    goto v_10685;
v_10686:
    goto v_10687;
v_10688:
    v_10817 = difference2(v_10818, v_10817);
    env = stack[-7];
    goto v_10681;
v_10682:
    goto v_10678;
v_10679:
    goto v_10680;
v_10681:
    v_10817 = (LispObject)greaterp2(stack[0], v_10817);
    v_10817 = v_10817 ? lisp_true : nil;
    env = stack[-7];
    if (v_10817 == nil) goto v_10676;
    v_10817 = elt(env, 6); // failed
    goto v_10424;
v_10676:
    goto v_10710;
v_10706:
    stack[0] = stack[-5];
    goto v_10707;
v_10708:
    goto v_10717;
v_10713:
    goto v_10723;
v_10719:
    v_10817 = nil;
    v_10818 = Llinelength(nil, v_10817);
    env = stack[-7];
    goto v_10720;
v_10721:
    v_10817 = qvalue(elt(env, 15)); // spare!*
    goto v_10722;
v_10723:
    goto v_10719;
v_10720:
    goto v_10721;
v_10722:
    v_10818 = difference2(v_10818, v_10817);
    env = stack[-7];
    goto v_10714;
v_10715:
    v_10817 = qvalue(elt(env, 17)); // posn!*
    goto v_10716;
v_10717:
    goto v_10713;
v_10714:
    goto v_10715;
v_10716:
    v_10817 = difference2(v_10818, v_10817);
    env = stack[-7];
    goto v_10709;
v_10710:
    goto v_10706;
v_10707:
    goto v_10708;
v_10709:
    v_10817 = (LispObject)greaterp2(stack[0], v_10817);
    v_10817 = v_10817 ? lisp_true : nil;
    env = stack[-7];
    if (v_10817 == nil) goto v_10704;
    v_10817 = lisp_true;
    fn = elt(env, 24); // terpri!*
    v_10817 = (*qfn1(fn))(fn, v_10817);
    env = stack[-7];
    goto v_10702;
v_10704:
v_10702:
    v_10817 = stack[-4];
    if (v_10817 == nil) goto v_10733;
    v_10817 = elt(env, 18); // "("
    fn = elt(env, 25); // prin2!*
    v_10817 = (*qfn1(fn))(fn, v_10817);
    env = stack[-7];
    goto v_10731;
v_10733:
v_10731:
    v_10817 = stack[-1];
    fn = elt(env, 26); // putpline
    v_10817 = (*qfn1(fn))(fn, v_10817);
    env = stack[-7];
    v_10817 = qvalue(elt(env, 8)); // !*eraise
    if (v_10817 == nil) goto v_10742;
    goto v_10749;
v_10745:
    v_10818 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10746;
v_10747:
    v_10817 = stack[-3];
    v_10817 = qcdr(v_10817);
    v_10817 = qcar(v_10817);
    goto v_10748;
v_10749:
    goto v_10745;
v_10746:
    goto v_10747;
v_10748:
    v_10817 = difference2(v_10818, v_10817);
    env = stack[-7];
    stack[-5] = v_10817;
    goto v_10740;
v_10742:
    v_10817 = elt(env, 7); // expt
    fn = elt(env, 27); // oprin
    v_10817 = (*qfn1(fn))(fn, v_10817);
    env = stack[-7];
    v_10817 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_10817;
    goto v_10740;
v_10740:
    goto v_10767;
v_10761:
    goto v_10775;
v_10769:
    v_10819 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10770;
v_10771:
    v_10818 = stack[-5];
    goto v_10772;
v_10773:
    v_10817 = stack[-3];
    v_10817 = qcar(v_10817);
    v_10817 = qcar(v_10817);
    goto v_10774;
v_10775:
    goto v_10769;
v_10770:
    goto v_10771;
v_10772:
    goto v_10773;
v_10774:
    fn = elt(env, 28); // update!-pline
    stack[-2] = (*qfnn(fn))(fn, 3, v_10819, v_10818, v_10817);
    env = stack[-7];
    goto v_10762;
v_10763:
    v_10817 = stack[-3];
    v_10817 = qcar(v_10817);
    stack[-1] = qcdr(v_10817);
    goto v_10764;
v_10765:
    goto v_10789;
v_10785:
    goto v_10795;
v_10791:
    v_10817 = stack[-3];
    v_10817 = qcdr(v_10817);
    v_10818 = qcar(v_10817);
    goto v_10792;
v_10793:
    v_10817 = stack[-5];
    goto v_10794;
v_10795:
    goto v_10791;
v_10792:
    goto v_10793;
v_10794:
    stack[0] = plus2(v_10818, v_10817);
    env = stack[-7];
    goto v_10786;
v_10787:
    goto v_10805;
v_10801:
    v_10817 = stack[-3];
    v_10817 = qcdr(v_10817);
    v_10818 = qcdr(v_10817);
    goto v_10802;
v_10803:
    v_10817 = stack[-5];
    goto v_10804;
v_10805:
    goto v_10801;
v_10802:
    goto v_10803;
v_10804:
    v_10817 = plus2(v_10818, v_10817);
    env = stack[-7];
    goto v_10788;
v_10789:
    goto v_10785;
v_10786:
    goto v_10787;
v_10788:
    v_10817 = cons(stack[0], v_10817);
    env = stack[-7];
    goto v_10766;
v_10767:
    goto v_10761;
v_10762:
    goto v_10763;
v_10764:
    goto v_10765;
v_10766:
    v_10817 = acons(stack[-2], stack[-1], v_10817);
    env = stack[-7];
    fn = elt(env, 26); // putpline
    v_10817 = (*qfn1(fn))(fn, v_10817);
    env = stack[-7];
    v_10817 = stack[-4];
    if (v_10817 == nil) goto v_10813;
    v_10817 = elt(env, 19); // ")"
    fn = elt(env, 25); // prin2!*
    v_10817 = (*qfn1(fn))(fn, v_10817);
    goto v_10811;
v_10813:
v_10811:
    v_10817 = nil;
v_10424:
    ;}  // end of a binding scope
    goto v_10403;
    v_10817 = nil;
v_10403:
    return onevalue(v_10817);
}



// Code for mml2om

static LispObject CC_mml2om(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10415;
    LispObject fn;
    argcheck(nargs, 0, "mml2om");
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
    fn = elt(env, 3); // mml2ir
    v_10415 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_10415;
    v_10415 = lisp_true;
    fn = elt(env, 4); // terpri!*
    v_10415 = (*qfn1(fn))(fn, v_10415);
    env = stack[-1];
    v_10415 = elt(env, 2); // "Intermediate representation: "
    v_10415 = Lprinc(nil, v_10415);
    env = stack[-1];
    v_10415 = lisp_true;
    fn = elt(env, 4); // terpri!*
    v_10415 = (*qfn1(fn))(fn, v_10415);
    env = stack[-1];
    v_10415 = stack[0];
    v_10415 = Lprint(nil, v_10415);
    env = stack[-1];
    v_10415 = stack[0];
    fn = elt(env, 5); // ir2om
    v_10415 = (*qfn1(fn))(fn, v_10415);
    v_10415 = nil;
    return onevalue(v_10415);
}



// Code for evmtest!?

static LispObject CC_evmtestW(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10437, v_10438, v_10439, v_10440;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10438 = v_10400;
    v_10439 = v_10399;
// end of prologue
v_10404:
    v_10437 = v_10439;
    if (v_10437 == nil) goto v_10408;
    v_10437 = v_10438;
    if (v_10437 == nil) goto v_10408;
    goto v_10421;
v_10417:
    v_10437 = v_10439;
    v_10440 = qcar(v_10437);
    goto v_10418;
v_10419:
    v_10437 = v_10438;
    v_10437 = qcar(v_10437);
    goto v_10420;
v_10421:
    goto v_10417;
v_10418:
    goto v_10419;
v_10420:
    if (((intptr_t)(v_10440)) < ((intptr_t)(v_10437))) goto v_10416;
    v_10437 = v_10439;
    v_10437 = qcdr(v_10437);
    v_10439 = v_10437;
    v_10437 = v_10438;
    v_10437 = qcdr(v_10437);
    v_10438 = v_10437;
    goto v_10404;
v_10416:
    v_10437 = nil;
    goto v_10403;
    goto v_10406;
v_10408:
    v_10437 = v_10438;
    {
        fn = elt(env, 1); // evzero!?
        return (*qfn1(fn))(fn, v_10437);
    }
v_10406:
    v_10437 = nil;
v_10403:
    return onevalue(v_10437);
}



// Code for scal!*list

static LispObject CC_scalHlist(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10433, v_10434;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10400;
    stack[-1] = v_10399;
// end of prologue
    stack[-2] = nil;
v_10405:
    v_10433 = stack[0];
    if (v_10433 == nil) goto v_10408;
    else goto v_10409;
v_10408:
    v_10433 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_10433);
    }
v_10409:
    goto v_10420;
v_10416:
    goto v_10426;
v_10422:
    v_10434 = stack[-1];
    goto v_10423;
v_10424:
    v_10433 = stack[0];
    v_10433 = qcar(v_10433);
    goto v_10425;
v_10426:
    goto v_10422;
v_10423:
    goto v_10424;
v_10425:
    fn = elt(env, 2); // !:times
    v_10434 = (*qfn2(fn))(fn, v_10434, v_10433);
    env = stack[-3];
    goto v_10417;
v_10418:
    v_10433 = stack[-2];
    goto v_10419;
v_10420:
    goto v_10416;
v_10417:
    goto v_10418;
v_10419:
    v_10433 = cons(v_10434, v_10433);
    env = stack[-3];
    stack[-2] = v_10433;
    v_10433 = stack[0];
    v_10433 = qcdr(v_10433);
    stack[0] = v_10433;
    goto v_10405;
    v_10433 = nil;
    return onevalue(v_10433);
}



// Code for add2resultbuf

static LispObject CC_add2resultbuf(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10541, v_10542, v_10543;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10400;
    stack[-1] = v_10399;
// end of prologue
    v_10541 = qvalue(elt(env, 1)); // !*libreduce_active
    if (v_10541 == nil) goto v_10408;
    fn = elt(env, 13); // lr_result
    v_10541 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_10419;
v_10415:
    v_10542 = qvalue(elt(env, 2)); // semic!*
    goto v_10416;
v_10417:
    v_10541 = elt(env, 3); // !$
    goto v_10418;
v_10419:
    goto v_10415;
v_10416:
    goto v_10417;
v_10418:
    if (v_10542 == v_10541) goto v_10414;
    goto v_10427;
v_10423:
    v_10542 = stack[-1];
    goto v_10424;
v_10425:
    v_10541 = stack[0];
    goto v_10426;
v_10427:
    goto v_10423;
v_10424:
    goto v_10425;
v_10426:
    fn = elt(env, 14); // lr_printer
    v_10541 = (*qfn2(fn))(fn, v_10542, v_10541);
    env = stack[-2];
    goto v_10412;
v_10414:
v_10412:
    fn = elt(env, 15); // lr_statcounter
    v_10541 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_10541 = qvalue(elt(env, 4)); // statcounter
    v_10541 = Lprinc(nil, v_10541);
    env = stack[-2];
    fn = elt(env, 16); // lr_mode
    v_10541 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_10443;
v_10439:
    v_10542 = qvalue(elt(env, 5)); // !*mode
    goto v_10440;
v_10441:
    v_10541 = elt(env, 6); // symbolic
    goto v_10442;
v_10443:
    goto v_10439;
v_10440:
    goto v_10441;
v_10442:
    if (v_10542 == v_10541) goto v_10437;
    else goto v_10438;
v_10437:
    v_10541 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10436;
v_10438:
    v_10541 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10436;
    v_10541 = nil;
v_10436:
    v_10541 = Lprinc(nil, v_10541);
    env = stack[-2];
    fn = elt(env, 17); // lr_posttext
    v_10541 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_10541 = Lterpri(nil, 0);
    env = stack[-2];
    goto v_10406;
v_10408:
v_10406:
    goto v_10464;
v_10460:
    v_10542 = stack[0];
    goto v_10461;
v_10462:
    v_10541 = elt(env, 6); // symbolic
    goto v_10463;
v_10464:
    goto v_10460;
v_10461:
    goto v_10462;
v_10463:
    if (v_10542 == v_10541) goto v_10458;
    else goto v_10459;
v_10458:
    v_10541 = lisp_true;
    goto v_10457;
v_10459:
    v_10541 = stack[-1];
    if (v_10541 == nil) goto v_10476;
    else goto v_10477;
v_10476:
    v_10541 = qvalue(elt(env, 7)); // !*reduce4
    if (v_10541 == nil) goto v_10481;
    else goto v_10482;
v_10481:
    v_10541 = lisp_true;
    goto v_10480;
v_10482:
    goto v_10491;
v_10487:
    v_10542 = stack[0];
    goto v_10488;
v_10489:
    v_10541 = elt(env, 8); // empty_list
    goto v_10490;
v_10491:
    goto v_10487;
v_10488:
    goto v_10489;
v_10490:
    v_10541 = (v_10542 == v_10541 ? lisp_true : nil);
    v_10541 = (v_10541 == nil ? lisp_true : nil);
    goto v_10480;
    v_10541 = nil;
v_10480:
    goto v_10475;
v_10477:
    v_10541 = nil;
    goto v_10475;
    v_10541 = nil;
v_10475:
    if (v_10541 == nil) goto v_10473;
    v_10541 = lisp_true;
    goto v_10471;
v_10473:
    v_10541 = qvalue(elt(env, 9)); // !*nosave!*
    goto v_10471;
    v_10541 = nil;
v_10471:
    goto v_10457;
    v_10541 = nil;
v_10457:
    if (v_10541 == nil) goto v_10455;
    v_10541 = nil;
    goto v_10403;
v_10455:
    v_10541 = qvalue(elt(env, 7)); // !*reduce4
    if (v_10541 == nil) goto v_10507;
    goto v_10516;
v_10510:
    v_10543 = elt(env, 10); // ws
    goto v_10511;
v_10512:
    v_10542 = stack[-1];
    goto v_10513;
v_10514:
    v_10541 = stack[0];
    goto v_10515;
v_10516:
    goto v_10510;
v_10511:
    goto v_10512;
v_10513:
    goto v_10514;
v_10515:
    fn = elt(env, 18); // putobject
    v_10541 = (*qfnn(fn))(fn, 3, v_10543, v_10542, v_10541);
    env = stack[-2];
    goto v_10505;
v_10507:
    v_10541 = nil;
    v_10541 = ncons(v_10541);
    env = stack[-2];
    qvalue(elt(env, 11)) = v_10541; // alglist!*
    v_10541 = stack[-1];
    qvalue(elt(env, 10)) = v_10541; // ws
    goto v_10505;
v_10505:
    fn = elt(env, 19); // terminalp
    v_10541 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_10541 == nil) goto v_10528;
    goto v_10537;
v_10531:
    v_10543 = qvalue(elt(env, 4)); // statcounter
    goto v_10532;
v_10533:
    v_10542 = stack[-1];
    goto v_10534;
v_10535:
    v_10541 = qvalue(elt(env, 12)); // resultbuflis!*
    goto v_10536;
v_10537:
    goto v_10531;
v_10532:
    goto v_10533;
v_10534:
    goto v_10535;
v_10536:
    v_10541 = acons(v_10543, v_10542, v_10541);
    env = stack[-2];
    qvalue(elt(env, 12)) = v_10541; // resultbuflis!*
    goto v_10526;
v_10528:
v_10526:
    v_10541 = nil;
v_10403:
    return onevalue(v_10541);
}



// Code for ord2

static LispObject CC_ord2(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10432, v_10433;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10400;
    stack[-1] = v_10399;
// end of prologue
    goto v_10411;
v_10407:
    v_10433 = stack[-1];
    goto v_10408;
v_10409:
    v_10432 = stack[0];
    goto v_10410;
v_10411:
    goto v_10407;
v_10408:
    goto v_10409;
v_10410:
    fn = elt(env, 1); // ordp
    v_10432 = (*qfn2(fn))(fn, v_10433, v_10432);
    if (v_10432 == nil) goto v_10405;
    goto v_10419;
v_10415:
    v_10433 = stack[-1];
    goto v_10416;
v_10417:
    v_10432 = stack[0];
    goto v_10418;
v_10419:
    goto v_10415;
v_10416:
    goto v_10417;
v_10418:
    return list2(v_10433, v_10432);
v_10405:
    goto v_10429;
v_10425:
    v_10433 = stack[0];
    goto v_10426;
v_10427:
    v_10432 = stack[-1];
    goto v_10428;
v_10429:
    goto v_10425;
v_10426:
    goto v_10427;
v_10428:
    return list2(v_10433, v_10432);
    v_10432 = nil;
    return onevalue(v_10432);
}



// Code for general!-expt!-mod!-p

static LispObject CC_generalKexptKmodKp(LispObject env,
                         LispObject v_10399, LispObject v_10400)
{
    env = qenv(env);
    LispObject v_10477, v_10478, v_10479;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10400,v_10399);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10399,v_10400);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_10479 = v_10400;
    stack[0] = v_10399;
// end of prologue
    goto v_10410;
v_10406:
    v_10478 = v_10479;
    goto v_10407;
v_10408:
    v_10477 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10409;
v_10410:
    goto v_10406;
v_10407:
    goto v_10408;
v_10409:
    if (v_10478 == v_10477) goto v_10404;
    else goto v_10405;
v_10404:
    v_10477 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10403;
v_10405:
    goto v_10420;
v_10416:
    v_10478 = v_10479;
    goto v_10417;
v_10418:
    v_10477 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10419;
v_10420:
    goto v_10416;
v_10417:
    goto v_10418;
v_10419:
    if (v_10478 == v_10477) goto v_10414;
    else goto v_10415;
v_10414:
    v_10477 = stack[0];
    goto v_10403;
v_10415:
    goto v_10436;
v_10432:
    v_10478 = v_10479;
    goto v_10433;
v_10434:
    v_10477 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10435;
v_10436:
    goto v_10432;
v_10433:
    goto v_10434;
v_10435:
    v_10477 = Ldivide(nil, v_10478, v_10477);
    env = stack[-2];
    stack[-1] = v_10477;
    goto v_10444;
v_10440:
    v_10478 = stack[0];
    goto v_10441;
v_10442:
    v_10477 = stack[-1];
    v_10477 = qcar(v_10477);
    goto v_10443;
v_10444:
    goto v_10440;
v_10441:
    goto v_10442;
v_10443:
    v_10477 = CC_generalKexptKmodKp(elt(env, 0), v_10478, v_10477);
    env = stack[-2];
    v_10479 = v_10477;
    goto v_10453;
v_10449:
    v_10477 = v_10479;
    goto v_10450;
v_10451:
    v_10478 = v_10479;
    goto v_10452;
v_10453:
    goto v_10449;
v_10450:
    goto v_10451;
v_10452:
    fn = elt(env, 2); // general!-times!-mod!-p
    v_10477 = (*qfn2(fn))(fn, v_10477, v_10478);
    env = stack[-2];
    v_10479 = v_10477;
    goto v_10464;
v_10460:
    v_10477 = stack[-1];
    v_10478 = qcdr(v_10477);
    goto v_10461;
v_10462:
    v_10477 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10463;
v_10464:
    goto v_10460;
v_10461:
    goto v_10462;
v_10463:
    if (v_10478 == v_10477) goto v_10459;
    goto v_10473;
v_10469:
    v_10478 = v_10479;
    goto v_10470;
v_10471:
    v_10477 = stack[0];
    goto v_10472;
v_10473:
    goto v_10469;
v_10470:
    goto v_10471;
v_10472:
    fn = elt(env, 2); // general!-times!-mod!-p
    v_10477 = (*qfn2(fn))(fn, v_10478, v_10477);
    v_10479 = v_10477;
    goto v_10457;
v_10459:
v_10457:
    v_10477 = v_10479;
    goto v_10403;
    v_10477 = nil;
v_10403:
    return onevalue(v_10477);
}



// Code for read_typed_name

static LispObject CC_read_typed_name(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10434, v_10435;
    LispObject fn;
    argcheck(nargs, 0, "read_typed_name");
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
    v_10434 = qvalue(elt(env, 2)); // cursym!*
    stack[0] = v_10434;
    fn = elt(env, 5); // scan
    v_10434 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_10414;
v_10410:
    v_10435 = qvalue(elt(env, 2)); // cursym!*
    goto v_10411;
v_10412:
    v_10434 = elt(env, 3); // !*colon!*
    goto v_10413;
v_10414:
    goto v_10410;
v_10411:
    goto v_10412;
v_10413:
    if (v_10435 == v_10434) goto v_10409;
    goto v_10422;
v_10418:
    v_10434 = stack[0];
    goto v_10419;
v_10420:
    v_10435 = elt(env, 4); // general
    goto v_10421;
v_10422:
    goto v_10418;
v_10419:
    goto v_10420;
v_10421:
    return cons(v_10434, v_10435);
v_10409:
    fn = elt(env, 5); // scan
    v_10434 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_10431;
v_10427:
    goto v_10428;
v_10429:
    fn = elt(env, 6); // read_type
    v_10434 = (*qfnn(fn))(fn, 0);
    goto v_10430;
v_10431:
    goto v_10427;
v_10428:
    goto v_10429;
v_10430:
    {
        LispObject v_10437 = stack[0];
        return cons(v_10437, v_10434);
    }
    return onevalue(v_10434);
}



setup_type const u19_setup[] =
{
    {"prepreform",              CC_prepreform,  TOO_MANY_1,    WRONG_NO_1},
    {"wusort",                  CC_wusort,      TOO_MANY_1,    WRONG_NO_1},
    {"talp_simplatat",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_simplatat},
    {"rl_susipost",             TOO_FEW_2,      CC_rl_susipost,WRONG_NO_2},
    {"ev_sum",                  TOO_FEW_2,      CC_ev_sum,     WRONG_NO_2},
    {"sf_member",               TOO_FEW_2,      CC_sf_member,  WRONG_NO_2},
    {"nary",                    TOO_FEW_2,      CC_nary,       WRONG_NO_2},
    {"inshisto",                CC_inshisto,    TOO_MANY_1,    WRONG_NO_1},
    {"deleteall",               TOO_FEW_2,      CC_deleteall,  WRONG_NO_2},
    {"copyd",                   TOO_FEW_2,      CC_copyd,      WRONG_NO_2},
    {"mo_from_a",               CC_mo_from_a,   TOO_MANY_1,    WRONG_NO_1},
    {"general-reduce-degree-mod-p",TOO_FEW_2,   CC_generalKreduceKdegreeKmodKp,WRONG_NO_2},
    {"simplify-filename",       CC_simplifyKfilename,TOO_MANY_1,WRONG_NO_1},
    {"polynomheadreduceby",     TOO_FEW_2,      CC_polynomheadreduceby,WRONG_NO_2},
    {"rl_subat",                TOO_FEW_2,      CC_rl_subat,   WRONG_NO_2},
    {"ibalp_initwl",            CC_ibalp_initwl,TOO_MANY_1,    WRONG_NO_1},
    {"variableom",              CC_variableom,  TOO_MANY_1,    WRONG_NO_1},
    {"vdpputprop",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vdpputprop},
    {"command",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_command},
    {"mkarray1",                TOO_FEW_2,      CC_mkarray1,   WRONG_NO_2},
    {"class",                   CC_class,       TOO_MANY_1,    WRONG_NO_1},
    {"moduntag",                CC_moduntag,    TOO_MANY_1,    WRONG_NO_1},
    {"mksq",                    TOO_FEW_2,      CC_mksq,       WRONG_NO_2},
    {":expt",                   TOO_FEW_2,      CC_Texpt,      WRONG_NO_2},
    {"lexer_word_starter",      CC_lexer_word_starter,TOO_MANY_1,WRONG_NO_1},
    {"coeffs",                  CC_coeffs,      TOO_MANY_1,    WRONG_NO_1},
    {"gcref_mkedges-tgf",       TOO_FEW_2,      CC_gcref_mkedgesKtgf,WRONG_NO_2},
    {"replus",                  CC_replus,      TOO_MANY_1,    WRONG_NO_1},
    {"prepsq*",                 CC_prepsqH,     TOO_MANY_1,    WRONG_NO_1},
    {"qqe_simplterm",           CC_qqe_simplterm,TOO_MANY_1,   WRONG_NO_1},
    {"make-univariate-image-mod-p",TOO_FEW_2,   CC_makeKunivariateKimageKmodKp,WRONG_NO_2},
    {"exptpri",                 TOO_FEW_2,      CC_exptpri,    WRONG_NO_2},
    {"mml2om",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mml2om},
    {"evmtest?",                TOO_FEW_2,      CC_evmtestW,   WRONG_NO_2},
    {"scal*list",               TOO_FEW_2,      CC_scalHlist,  WRONG_NO_2},
    {"add2resultbuf",           TOO_FEW_2,      CC_add2resultbuf,WRONG_NO_2},
    {"ord2",                    TOO_FEW_2,      CC_ord2,       WRONG_NO_2},
    {"general-expt-mod-p",      TOO_FEW_2,      CC_generalKexptKmodKp,WRONG_NO_2},
    {"read_typed_name",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_read_typed_name},
    {NULL, (one_args *)"u19", (two_args *)"181756 6587427 2673376", 0}
};

// end of generated code
