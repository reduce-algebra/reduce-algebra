
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



// Code for !:expt

static LispObject CC_Texpt(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10880, v_10881, v_10882;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10664,v_10665);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_10665;
    stack[-4] = v_10664;
// end of prologue
    v_10880 = stack[-4];
    if (v_10880 == nil) goto v_10669;
    else goto v_10670;
v_10669:
    goto v_10680;
v_10676:
    v_10881 = stack[-3];
    goto v_10677;
v_10678:
    v_10880 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10679;
v_10680:
    goto v_10676;
v_10677:
    goto v_10678;
v_10679:
    if (v_10881 == v_10880) goto v_10674;
    else goto v_10675;
v_10674:
    goto v_10690;
v_10684:
    v_10882 = elt(env, 1); // poly
    goto v_10685;
v_10686:
    v_10881 = (LispObject)176+TAG_FIXNUM; // 11
    goto v_10687;
v_10688:
    v_10880 = elt(env, 2); // "0/0 formed"
    goto v_10689;
v_10690:
    goto v_10684;
v_10685:
    goto v_10686;
v_10687:
    goto v_10688;
v_10689:
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_10882, v_10881, v_10880);
    }
v_10675:
    v_10880 = nil;
    goto v_10673;
    v_10880 = nil;
v_10673:
    goto v_10668;
v_10670:
    goto v_10703;
v_10699:
    v_10881 = stack[-3];
    goto v_10700;
v_10701:
    v_10880 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10702;
v_10703:
    goto v_10699;
v_10700:
    goto v_10701;
v_10702:
    if (v_10881 == v_10880) goto v_10697;
    else goto v_10698;
v_10697:
    v_10880 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10668;
v_10698:
    goto v_10713;
v_10709:
    v_10881 = stack[-3];
    goto v_10710;
v_10711:
    v_10880 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10712;
v_10713:
    goto v_10709;
v_10710:
    goto v_10711;
v_10712:
    if (v_10881 == v_10880) goto v_10707;
    else goto v_10708;
v_10707:
    v_10880 = stack[-4];
    goto v_10668;
v_10708:
    goto v_10723;
v_10719:
    v_10881 = stack[-4];
    goto v_10720;
v_10721:
    v_10880 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10722;
v_10723:
    goto v_10719;
v_10720:
    goto v_10721;
v_10722:
    if (v_10881 == v_10880) goto v_10717;
    else goto v_10718;
v_10717:
    v_10880 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10668;
v_10718:
    goto v_10734;
v_10730:
    v_10881 = stack[-3];
    goto v_10731;
v_10732:
    v_10880 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10733;
v_10734:
    goto v_10730;
v_10731:
    goto v_10732;
v_10733:
    v_10880 = (LispObject)lessp2(v_10881, v_10880);
    v_10880 = v_10880 ? lisp_true : nil;
    env = stack[-6];
    if (v_10880 == nil) goto v_10728;
    goto v_10743;
v_10739:
    v_10880 = stack[-4];
    fn = elt(env, 5); // fieldp
    v_10880 = (*qfn1(fn))(fn, v_10880);
    env = stack[-6];
    if (v_10880 == nil) goto v_10746;
    else goto v_10747;
v_10746:
    v_10880 = stack[-4];
    fn = elt(env, 6); // mkratnum
    v_10880 = (*qfn1(fn))(fn, v_10880);
    env = stack[-6];
    stack[0] = v_10880;
    goto v_10745;
v_10747:
    v_10880 = stack[-4];
    stack[0] = v_10880;
    goto v_10745;
    stack[0] = nil;
v_10745:
    goto v_10740;
v_10741:
    v_10880 = stack[-3];
    v_10880 = negate(v_10880);
    env = stack[-6];
    goto v_10742;
v_10743:
    goto v_10739;
v_10740:
    goto v_10741;
v_10742:
    v_10880 = CC_Texpt(elt(env, 0), stack[0], v_10880);
    env = stack[-6];
    {
        fn = elt(env, 7); // !:recip
        return (*qfn1(fn))(fn, v_10880);
    }
v_10728:
    v_10880 = stack[-4];
    if (!consp(v_10880)) goto v_10757;
    else goto v_10758;
v_10757:
    goto v_10765;
v_10761:
    v_10881 = stack[-4];
    goto v_10762;
v_10763:
    v_10880 = stack[-3];
    goto v_10764;
v_10765:
    goto v_10761;
v_10762:
    goto v_10763;
v_10764:
        return Lexpt(nil, v_10881, v_10880);
v_10758:
    goto v_10785;
v_10781:
    v_10880 = stack[-4];
    v_10881 = qcar(v_10880);
    goto v_10782;
v_10783:
    v_10880 = elt(env, 3); // expt
    goto v_10784;
v_10785:
    goto v_10781;
v_10782:
    goto v_10783;
v_10784:
    v_10880 = get(v_10881, v_10880);
    env = stack[-6];
    stack[-2] = v_10880;
    if (v_10880 == nil) goto v_10779;
    goto v_10796;
v_10790:
    v_10882 = stack[-2];
    goto v_10791;
v_10792:
    v_10881 = stack[-4];
    goto v_10793;
v_10794:
    v_10880 = stack[-3];
    goto v_10795;
v_10796:
    goto v_10790;
v_10791:
    goto v_10792;
v_10793:
    goto v_10794;
v_10795:
        return Lapply2(nil, 3, v_10882, v_10881, v_10880);
v_10779:
    goto v_10805;
v_10801:
    v_10880 = stack[-4];
    v_10880 = qcar(v_10880);
    if (!symbolp(v_10880)) v_10881 = nil;
    else { v_10881 = qfastgets(v_10880);
           if (v_10881 != nil) { v_10881 = elt(v_10881, 34); // i2d
#ifdef RECORD_GET
             if (v_10881 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_10881 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_10881 == SPID_NOPROP) v_10881 = nil; }}
#endif
    goto v_10802;
v_10803:
    v_10880 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10804;
v_10805:
    goto v_10801;
v_10802:
    goto v_10803;
v_10804:
    v_10880 = Lapply1(nil, v_10881, v_10880);
    env = stack[-6];
    stack[-5] = v_10880;
    v_10880 = stack[-4];
    v_10880 = qcar(v_10880);
    if (!symbolp(v_10880)) v_10880 = nil;
    else { v_10880 = qfastgets(v_10880);
           if (v_10880 != nil) { v_10880 = elt(v_10880, 54); // times
#ifdef RECORD_GET
             if (v_10880 != SPID_NOPROP)
                record_get(elt(fastget_names, 54), 1);
             else record_get(elt(fastget_names, 54), 0),
                v_10880 = nil; }
           else record_get(elt(fastget_names, 54), 0); }
#else
             if (v_10880 == SPID_NOPROP) v_10880 = nil; }}
#endif
    stack[-2] = v_10880;
v_10775:
    v_10880 = stack[-3];
    goto v_10822;
v_10818:
    goto v_10828;
v_10824:
    stack[-1] = v_10880;
    goto v_10825;
v_10826:
    goto v_10835;
v_10831:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10832;
v_10833:
    goto v_10842;
v_10838:
    v_10881 = stack[-3];
    goto v_10839;
v_10840:
    v_10880 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10841;
v_10842:
    goto v_10838;
v_10839:
    goto v_10840;
v_10841:
    v_10880 = quot2(v_10881, v_10880);
    env = stack[-6];
    stack[-3] = v_10880;
    goto v_10834;
v_10835:
    goto v_10831;
v_10832:
    goto v_10833;
v_10834:
    v_10880 = times2(stack[0], v_10880);
    env = stack[-6];
    goto v_10827;
v_10828:
    goto v_10824;
v_10825:
    goto v_10826;
v_10827:
    v_10881 = difference2(stack[-1], v_10880);
    env = stack[-6];
    goto v_10819;
v_10820:
    v_10880 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10821;
v_10822:
    goto v_10818;
v_10819:
    goto v_10820;
v_10821:
    if (v_10881 == v_10880) goto v_10817;
    goto v_10853;
v_10847:
    v_10882 = stack[-2];
    goto v_10848;
v_10849:
    v_10881 = stack[-4];
    goto v_10850;
v_10851:
    v_10880 = stack[-5];
    goto v_10852;
v_10853:
    goto v_10847;
v_10848:
    goto v_10849;
v_10850:
    goto v_10851;
v_10852:
    v_10880 = Lapply2(nil, 3, v_10882, v_10881, v_10880);
    env = stack[-6];
    stack[-5] = v_10880;
    goto v_10815;
v_10817:
v_10815:
    goto v_10865;
v_10861:
    v_10881 = stack[-3];
    goto v_10862;
v_10863:
    v_10880 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10864;
v_10865:
    goto v_10861;
v_10862:
    goto v_10863;
v_10864:
    if (v_10881 == v_10880) goto v_10859;
    else goto v_10860;
v_10859:
    v_10880 = stack[-5];
    goto v_10774;
v_10860:
    goto v_10876;
v_10870:
    v_10882 = stack[-2];
    goto v_10871;
v_10872:
    v_10881 = stack[-4];
    goto v_10873;
v_10874:
    v_10880 = stack[-4];
    goto v_10875;
v_10876:
    goto v_10870;
v_10871:
    goto v_10872;
v_10873:
    goto v_10874;
v_10875:
    v_10880 = Lapply2(nil, 3, v_10882, v_10881, v_10880);
    env = stack[-6];
    stack[-4] = v_10880;
    goto v_10775;
v_10774:
    goto v_10668;
    v_10880 = nil;
v_10668:
    return onevalue(v_10880);
}



// Code for lex_start_line_comment

static LispObject CC_lex_start_line_comment(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10766, v_10767;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10664;
// end of prologue
    goto v_10678;
v_10674:
    v_10767 = stack[0];
    goto v_10675;
v_10676:
    v_10766 = elt(env, 1); // !%
    goto v_10677;
v_10678:
    goto v_10674;
v_10675:
    goto v_10676;
v_10677:
    if (v_10767 == v_10766) goto v_10672;
    else goto v_10673;
v_10672:
    goto v_10687;
v_10683:
    v_10767 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_10684;
v_10685:
    v_10766 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10686;
v_10687:
    goto v_10683;
v_10684:
    goto v_10685;
v_10686:
    fn = elt(env, 5); // land
    v_10766 = (*qfn2(fn))(fn, v_10767, v_10766);
    env = stack[-1];
    v_10766 = (LispObject)zerop(v_10766);
    v_10766 = v_10766 ? lisp_true : nil;
    env = stack[-1];
    v_10766 = (v_10766 == nil ? lisp_true : nil);
    goto v_10671;
v_10673:
    v_10766 = nil;
    goto v_10671;
    v_10766 = nil;
v_10671:
    if (v_10766 == nil) goto v_10669;
    v_10766 = lisp_true;
    goto v_10667;
v_10669:
    goto v_10709;
v_10705:
    v_10767 = stack[0];
    goto v_10706;
v_10707:
    v_10766 = elt(env, 3); // !#
    goto v_10708;
v_10709:
    goto v_10705;
v_10706:
    goto v_10707;
v_10708:
    if (v_10767 == v_10766) goto v_10703;
    else goto v_10704;
v_10703:
    goto v_10718;
v_10714:
    v_10767 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_10715;
v_10716:
    v_10766 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10717;
v_10718:
    goto v_10714;
v_10715:
    goto v_10716;
v_10717:
    fn = elt(env, 5); // land
    v_10766 = (*qfn2(fn))(fn, v_10767, v_10766);
    env = stack[-1];
    v_10766 = (LispObject)zerop(v_10766);
    v_10766 = v_10766 ? lisp_true : nil;
    env = stack[-1];
    v_10766 = (v_10766 == nil ? lisp_true : nil);
    goto v_10702;
v_10704:
    v_10766 = nil;
    goto v_10702;
    v_10766 = nil;
v_10702:
    if (v_10766 == nil) goto v_10700;
    v_10766 = lisp_true;
    goto v_10698;
v_10700:
    goto v_10736;
v_10732:
    v_10767 = stack[0];
    goto v_10733;
v_10734:
    v_10766 = elt(env, 4); // !/
    goto v_10735;
v_10736:
    goto v_10732;
v_10733:
    goto v_10734;
v_10735:
    if (v_10767 == v_10766) goto v_10730;
    else goto v_10731;
v_10730:
    goto v_10749;
v_10745:
    v_10767 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_10746;
v_10747:
    v_10766 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_10748;
v_10749:
    goto v_10745;
v_10746:
    goto v_10747;
v_10748:
    fn = elt(env, 5); // land
    v_10766 = (*qfn2(fn))(fn, v_10767, v_10766);
    env = stack[-1];
    v_10766 = (LispObject)zerop(v_10766);
    v_10766 = v_10766 ? lisp_true : nil;
    env = stack[-1];
    if (v_10766 == nil) goto v_10741;
    else goto v_10742;
v_10741:
    goto v_10756;
v_10752:
    fn = elt(env, 6); // yypeek
    v_10766 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_10753;
v_10754:
    v_10767 = elt(env, 4); // !/
    goto v_10755;
v_10756:
    goto v_10752;
v_10753:
    goto v_10754;
v_10755:
    v_10766 = (v_10766 == v_10767 ? lisp_true : nil);
    goto v_10740;
v_10742:
    v_10766 = nil;
    goto v_10740;
    v_10766 = nil;
v_10740:
    goto v_10729;
v_10731:
    v_10766 = nil;
    goto v_10729;
    v_10766 = nil;
v_10729:
    goto v_10698;
    v_10766 = nil;
v_10698:
    goto v_10667;
    v_10766 = nil;
v_10667:
    return onevalue(v_10766);
}



// Code for formcond

static LispObject CC_formcond(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10687, v_10688, v_10689;
    LispObject fn;
    LispObject v_10666, v_10665, v_10664;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formcond");
    va_start(aa, nargs);
    v_10664 = va_arg(aa, LispObject);
    v_10665 = va_arg(aa, LispObject);
    v_10666 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_10666,v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_10664,v_10665,v_10666);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_10687 = v_10666;
    v_10688 = v_10665;
    v_10689 = v_10664;
// end of prologue
    goto v_10673;
v_10669:
    stack[0] = elt(env, 1); // cond
    goto v_10670;
v_10671:
    goto v_10682;
v_10676:
    v_10689 = qcdr(v_10689);
    goto v_10677;
v_10678:
    goto v_10679;
v_10680:
    goto v_10681;
v_10682:
    goto v_10676;
v_10677:
    goto v_10678;
v_10679:
    goto v_10680;
v_10681:
    fn = elt(env, 2); // formcond1
    v_10687 = (*qfnn(fn))(fn, 3, v_10689, v_10688, v_10687);
    goto v_10672;
v_10673:
    goto v_10669;
v_10670:
    goto v_10671;
v_10672:
    {
        LispObject v_10691 = stack[0];
        return cons(v_10691, v_10687);
    }
}



// Code for ofsf_entry2at

static LispObject CC_ofsf_entry2at(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10698, v_10699, v_10700, v_10701;
    LispObject fn;
    LispObject v_10666, v_10665, v_10664;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_entry2at");
    va_start(aa, nargs);
    v_10664 = va_arg(aa, LispObject);
    v_10665 = va_arg(aa, LispObject);
    v_10666 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_10666,v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_10664,v_10665,v_10666);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_10699 = v_10666;
    v_10700 = v_10665;
    v_10701 = v_10664;
// end of prologue
    v_10698 = qvalue(elt(env, 1)); // !*rlidentify
    if (v_10698 == nil) goto v_10671;
    goto v_10681;
v_10675:
    v_10698 = v_10701;
    goto v_10676;
v_10677:
    goto v_10678;
v_10679:
    goto v_10680;
v_10681:
    goto v_10675;
v_10676:
    goto v_10677;
v_10678:
    goto v_10679;
v_10680:
    fn = elt(env, 2); // ofsf_entry2at1
    v_10698 = (*qfnn(fn))(fn, 3, v_10698, v_10700, v_10699);
    env = stack[0];
    {
        fn = elt(env, 3); // cl_identifyat
        return (*qfn1(fn))(fn, v_10698);
    }
v_10671:
    goto v_10694;
v_10688:
    v_10698 = v_10701;
    goto v_10689;
v_10690:
    goto v_10691;
v_10692:
    goto v_10693;
v_10694:
    goto v_10688;
v_10689:
    goto v_10690;
v_10691:
    goto v_10692;
v_10693:
    {
        fn = elt(env, 2); // ofsf_entry2at1
        return (*qfnn(fn))(fn, 3, v_10698, v_10700, v_10699);
    }
    v_10698 = nil;
    return onevalue(v_10698);
}



// Code for ofsf_smmkatl1

static LispObject CC_ofsf_smmkatl1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10704, v_10705, v_10706, v_10707, v_10708;
    LispObject fn;
    LispObject v_10667, v_10666, v_10665, v_10664;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ofsf_smmkatl1");
    va_start(aa, nargs);
    v_10664 = va_arg(aa, LispObject);
    v_10665 = va_arg(aa, LispObject);
    v_10666 = va_arg(aa, LispObject);
    v_10667 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10706 = v_10667;
    v_10707 = v_10666;
    v_10708 = v_10665;
    v_10704 = v_10664;
// end of prologue
    goto v_10677;
v_10673:
    v_10705 = v_10704;
    goto v_10674;
v_10675:
    v_10704 = elt(env, 1); // and
    goto v_10676;
v_10677:
    goto v_10673;
v_10674:
    goto v_10675;
v_10676:
    if (v_10705 == v_10704) goto v_10671;
    else goto v_10672;
v_10671:
    goto v_10687;
v_10681:
    v_10704 = v_10708;
    goto v_10682;
v_10683:
    v_10705 = v_10707;
    goto v_10684;
v_10685:
    goto v_10686;
v_10687:
    goto v_10681;
v_10682:
    goto v_10683;
v_10684:
    goto v_10685;
v_10686:
    {
        fn = elt(env, 2); // ofsf_smmkatl!-and
        return (*qfnn(fn))(fn, 3, v_10704, v_10705, v_10706);
    }
v_10672:
    goto v_10700;
v_10694:
    v_10704 = v_10708;
    goto v_10695;
v_10696:
    v_10705 = v_10707;
    goto v_10697;
v_10698:
    goto v_10699;
v_10700:
    goto v_10694;
v_10695:
    goto v_10696;
v_10697:
    goto v_10698;
v_10699:
    {
        fn = elt(env, 3); // ofsf_smmkatl!-or
        return (*qfnn(fn))(fn, 3, v_10704, v_10705, v_10706);
    }
    v_10704 = nil;
    return onevalue(v_10704);
}



// Code for rl_atl

static LispObject CC_rl_atl(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10675;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10675 = v_10664;
// end of prologue
    goto v_10671;
v_10667:
    stack[0] = qvalue(elt(env, 1)); // rl_atl!*
    goto v_10668;
v_10669:
    v_10675 = ncons(v_10675);
    env = stack[-1];
    goto v_10670;
v_10671:
    goto v_10667;
v_10668:
    goto v_10669;
v_10670:
    {
        LispObject v_10677 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_10677, v_10675);
    }
}



// Code for ibalp_readclause

static LispObject CC_ibalp_readclause(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10922, v_10923, v_10924, v_10925;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10664,v_10665);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_10665;
    v_10922 = v_10664;
// end of prologue
    stack[-3] = nil;
    stack[-2] = nil;
    v_10922 = qcdr(v_10922);
    stack[-4] = v_10922;
    goto v_10688;
v_10680:
    stack[-5] = nil;
    goto v_10681;
v_10682:
    stack[-1] = nil;
    goto v_10683;
v_10684:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10685;
v_10686:
    goto v_10701;
v_10693:
    v_10925 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10694;
v_10695:
    v_10924 = nil;
    goto v_10696;
v_10697:
    v_10923 = nil;
    goto v_10698;
v_10699:
    v_10922 = nil;
    goto v_10700;
v_10701:
    goto v_10693;
v_10694:
    goto v_10695;
v_10696:
    goto v_10697;
v_10698:
    goto v_10699;
v_10700:
    v_10922 = list4(v_10925, v_10924, v_10923, v_10922);
    env = stack[-9];
    goto v_10687;
v_10688:
    goto v_10680;
v_10681:
    goto v_10682;
v_10683:
    goto v_10684;
v_10685:
    goto v_10686;
v_10687:
    v_10922 = list3star(stack[-5], stack[-1], stack[0], v_10922);
    env = stack[-9];
    stack[-5] = v_10922;
    v_10922 = lisp_true;
    stack[-1] = v_10922;
v_10709:
    v_10922 = stack[-1];
    if (v_10922 == nil) goto v_10712;
    v_10922 = stack[-4];
    if (v_10922 == nil) goto v_10712;
    goto v_10713;
v_10712:
    goto v_10708;
v_10713:
    v_10922 = stack[-4];
    v_10922 = qcar(v_10922);
    stack[-8] = v_10922;
    goto v_10729;
v_10725:
    v_10923 = stack[-8];
    goto v_10726;
v_10727:
    v_10922 = elt(env, 1); // true
    goto v_10728;
v_10729:
    goto v_10725;
v_10726:
    goto v_10727;
v_10728:
    if (v_10923 == v_10922) goto v_10723;
    else goto v_10724;
v_10723:
    v_10922 = nil;
    stack[-1] = v_10922;
    goto v_10722;
v_10724:
    v_10922 = stack[-4];
    v_10922 = qcdr(v_10922);
    stack[-4] = v_10922;
    goto v_10745;
v_10741:
    v_10923 = stack[-8];
    goto v_10742;
v_10743:
    v_10922 = elt(env, 2); // false
    goto v_10744;
v_10745:
    goto v_10741;
v_10742:
    goto v_10743;
v_10744:
    if (v_10923 == v_10922) goto v_10740;
    goto v_10756;
v_10752:
    v_10922 = stack[-8];
    if (!consp(v_10922)) goto v_10759;
    else goto v_10760;
v_10759:
    v_10922 = stack[-8];
    v_10923 = v_10922;
    goto v_10758;
v_10760:
    v_10922 = stack[-8];
    v_10922 = qcar(v_10922);
    v_10923 = v_10922;
    goto v_10758;
    v_10923 = nil;
v_10758:
    goto v_10753;
v_10754:
    v_10922 = elt(env, 3); // not
    goto v_10755;
v_10756:
    goto v_10752;
v_10753:
    goto v_10754;
v_10755:
    if (v_10923 == v_10922) goto v_10750;
    else goto v_10751;
v_10750:
    v_10922 = stack[-8];
    v_10922 = qcdr(v_10922);
    v_10922 = qcar(v_10922);
    fn = elt(env, 4); // ibalp_arg2l
    v_10922 = (*qfn1(fn))(fn, v_10922);
    env = stack[-9];
    stack[-6] = v_10922;
    goto v_10776;
v_10772:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10773;
v_10774:
    v_10922 = stack[-8];
    v_10922 = qcdr(v_10922);
    v_10922 = qcar(v_10922);
    fn = elt(env, 5); // ibalp_arg2r
    v_10922 = (*qfn1(fn))(fn, v_10922);
    env = stack[-9];
    goto v_10775;
v_10776:
    goto v_10772;
v_10773:
    goto v_10774;
v_10775:
    v_10922 = (LispObject)(intptr_t)((intptr_t)stack[0] - (intptr_t)v_10922 + TAG_FIXNUM);
    goto v_10749;
v_10751:
    v_10922 = stack[-8];
    fn = elt(env, 4); // ibalp_arg2l
    v_10922 = (*qfn1(fn))(fn, v_10922);
    env = stack[-9];
    stack[-6] = v_10922;
    v_10922 = stack[-8];
    fn = elt(env, 5); // ibalp_arg2r
    v_10922 = (*qfn1(fn))(fn, v_10922);
    env = stack[-9];
    goto v_10749;
v_10749:
    goto v_10798;
v_10794:
    v_10923 = v_10922;
    goto v_10795;
v_10796:
    v_10922 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10797;
v_10798:
    goto v_10794;
v_10795:
    goto v_10796;
v_10797:
    fn = elt(env, 6); // iequal
    v_10922 = (*qfn2(fn))(fn, v_10923, v_10922);
    env = stack[-9];
    if (v_10922 == nil) goto v_10792;
    goto v_10809;
v_10805:
    v_10923 = stack[-6];
    goto v_10806;
v_10807:
    v_10922 = stack[-3];
    goto v_10808;
v_10809:
    goto v_10805;
v_10806:
    goto v_10807;
v_10808:
    v_10922 = Lmemq(nil, v_10923, v_10922);
    if (v_10922 == nil) goto v_10803;
    else goto v_10804;
v_10803:
    goto v_10818;
v_10814:
    v_10922 = stack[-5];
    v_10922 = qcdr(v_10922);
    stack[0] = qcdr(v_10922);
    goto v_10815;
v_10816:
    v_10922 = stack[-5];
    v_10922 = qcdr(v_10922);
    v_10922 = qcdr(v_10922);
    v_10922 = qcar(v_10922);
    v_10922 = add1(v_10922);
    env = stack[-9];
    goto v_10817;
v_10818:
    goto v_10814;
v_10815:
    goto v_10816;
v_10817:
    fn = elt(env, 7); // setcar
    v_10922 = (*qfn2(fn))(fn, stack[0], v_10922);
    env = stack[-9];
    goto v_10832;
v_10828:
    v_10923 = stack[-6];
    goto v_10829;
v_10830:
    v_10922 = stack[-3];
    goto v_10831;
v_10832:
    goto v_10828;
v_10829:
    goto v_10830;
v_10831:
    v_10922 = cons(v_10923, v_10922);
    env = stack[-9];
    stack[-3] = v_10922;
    goto v_10844;
v_10836:
    v_10925 = stack[-5];
    goto v_10837;
v_10838:
    v_10924 = stack[-7];
    goto v_10839;
v_10840:
    v_10923 = stack[-6];
    goto v_10841;
v_10842:
    v_10922 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10843;
v_10844:
    goto v_10836;
v_10837:
    goto v_10838;
v_10839:
    goto v_10840;
v_10841:
    goto v_10842;
v_10843:
    fn = elt(env, 8); // ibalp_process!-var
    v_10922 = (*qfnn(fn))(fn, 4, v_10925, v_10924, v_10923, v_10922);
    env = stack[-9];
    stack[-7] = v_10922;
    goto v_10802;
v_10804:
v_10802:
    goto v_10790;
v_10792:
    goto v_10859;
v_10855:
    v_10923 = stack[-6];
    goto v_10856;
v_10857:
    v_10922 = stack[-2];
    goto v_10858;
v_10859:
    goto v_10855;
v_10856:
    goto v_10857;
v_10858:
    v_10922 = Lmemq(nil, v_10923, v_10922);
    if (v_10922 == nil) goto v_10853;
    else goto v_10854;
v_10853:
    goto v_10868;
v_10864:
    v_10922 = stack[-5];
    v_10922 = qcdr(v_10922);
    v_10922 = qcdr(v_10922);
    stack[0] = qcdr(v_10922);
    goto v_10865;
v_10866:
    v_10922 = stack[-5];
    v_10922 = qcdr(v_10922);
    v_10922 = qcdr(v_10922);
    v_10922 = qcdr(v_10922);
    v_10922 = qcar(v_10922);
    v_10922 = add1(v_10922);
    env = stack[-9];
    goto v_10867;
v_10868:
    goto v_10864;
v_10865:
    goto v_10866;
v_10867:
    fn = elt(env, 7); // setcar
    v_10922 = (*qfn2(fn))(fn, stack[0], v_10922);
    env = stack[-9];
    goto v_10884;
v_10880:
    v_10923 = stack[-6];
    goto v_10881;
v_10882:
    v_10922 = stack[-2];
    goto v_10883;
v_10884:
    goto v_10880;
v_10881:
    goto v_10882;
v_10883:
    v_10922 = cons(v_10923, v_10922);
    env = stack[-9];
    stack[-2] = v_10922;
    goto v_10896;
v_10888:
    v_10925 = stack[-5];
    goto v_10889;
v_10890:
    v_10924 = stack[-7];
    goto v_10891;
v_10892:
    v_10923 = stack[-6];
    goto v_10893;
v_10894:
    v_10922 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10895;
v_10896:
    goto v_10888;
v_10889:
    goto v_10890;
v_10891:
    goto v_10892;
v_10893:
    goto v_10894;
v_10895:
    fn = elt(env, 8); // ibalp_process!-var
    v_10922 = (*qfnn(fn))(fn, 4, v_10925, v_10924, v_10923, v_10922);
    env = stack[-9];
    stack[-7] = v_10922;
    goto v_10852;
v_10854:
v_10852:
    goto v_10790;
v_10790:
    goto v_10738;
v_10740:
v_10738:
    goto v_10722;
v_10722:
    goto v_10709;
v_10708:
    v_10922 = stack[-1];
    if (v_10922 == nil) goto v_10903;
    else goto v_10904;
v_10903:
    goto v_10911;
v_10907:
    v_10923 = elt(env, 1); // true
    goto v_10908;
v_10909:
    v_10922 = stack[-7];
    goto v_10910;
v_10911:
    goto v_10907;
v_10908:
    goto v_10909;
v_10910:
    return cons(v_10923, v_10922);
v_10904:
    goto v_10919;
v_10915:
    v_10923 = stack[-5];
    goto v_10916;
v_10917:
    v_10922 = stack[-7];
    goto v_10918;
v_10919:
    goto v_10915;
v_10916:
    goto v_10917;
v_10918:
    return cons(v_10923, v_10922);
    return onevalue(v_10922);
}



// Code for powers4

static LispObject CC_powers4(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10991, v_10992, v_10993;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10664,v_10665);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_10665;
    stack[-1] = v_10664;
// end of prologue
    stack[-3] = nil;
v_10670:
    v_10991 = stack[-1];
    if (v_10991 == nil) goto v_10673;
    else goto v_10674;
v_10673:
    goto v_10681;
v_10677:
    stack[-4] = stack[-3];
    goto v_10678;
v_10679:
    v_10991 = stack[0];
    stack[-3] = v_10991;
    v_10991 = stack[-3];
    if (v_10991 == nil) goto v_10692;
    else goto v_10693;
v_10692:
    v_10991 = nil;
    goto v_10687;
v_10693:
    v_10991 = stack[-3];
    v_10991 = qcar(v_10991);
    goto v_10707;
v_10701:
    v_10992 = v_10991;
    v_10993 = qcar(v_10992);
    goto v_10702;
v_10703:
    v_10991 = qcdr(v_10991);
    v_10992 = qcar(v_10991);
    goto v_10704;
v_10705:
    v_10991 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10706;
v_10707:
    goto v_10701;
v_10702:
    goto v_10703;
v_10704:
    goto v_10705;
v_10706:
    v_10991 = list2star(v_10993, v_10992, v_10991);
    env = stack[-5];
    v_10991 = ncons(v_10991);
    env = stack[-5];
    stack[-1] = v_10991;
    stack[-2] = v_10991;
v_10688:
    v_10991 = stack[-3];
    v_10991 = qcdr(v_10991);
    stack[-3] = v_10991;
    v_10991 = stack[-3];
    if (v_10991 == nil) goto v_10718;
    else goto v_10719;
v_10718:
    v_10991 = stack[-2];
    goto v_10687;
v_10719:
    goto v_10727;
v_10723:
    stack[0] = stack[-1];
    goto v_10724;
v_10725:
    v_10991 = stack[-3];
    v_10991 = qcar(v_10991);
    goto v_10740;
v_10734:
    v_10992 = v_10991;
    v_10993 = qcar(v_10992);
    goto v_10735;
v_10736:
    v_10991 = qcdr(v_10991);
    v_10992 = qcar(v_10991);
    goto v_10737;
v_10738:
    v_10991 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10739;
v_10740:
    goto v_10734;
v_10735:
    goto v_10736;
v_10737:
    goto v_10738;
v_10739:
    v_10991 = list2star(v_10993, v_10992, v_10991);
    env = stack[-5];
    v_10991 = ncons(v_10991);
    env = stack[-5];
    goto v_10726;
v_10727:
    goto v_10723;
v_10724:
    goto v_10725;
v_10726:
    v_10991 = Lrplacd(nil, stack[0], v_10991);
    env = stack[-5];
    v_10991 = stack[-1];
    v_10991 = qcdr(v_10991);
    stack[-1] = v_10991;
    goto v_10688;
v_10687:
    goto v_10680;
v_10681:
    goto v_10677;
v_10678:
    goto v_10679;
v_10680:
    {
        LispObject v_10999 = stack[-4];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_10999, v_10991);
    }
v_10674:
    v_10991 = stack[0];
    if (v_10991 == nil) goto v_10749;
    else goto v_10750;
v_10749:
    goto v_10757;
v_10753:
    stack[-4] = stack[-3];
    goto v_10754;
v_10755:
    v_10991 = stack[-1];
    stack[-3] = v_10991;
    v_10991 = stack[-3];
    if (v_10991 == nil) goto v_10768;
    else goto v_10769;
v_10768:
    v_10991 = nil;
    goto v_10763;
v_10769:
    v_10991 = stack[-3];
    v_10991 = qcar(v_10991);
    goto v_10783;
v_10777:
    v_10992 = v_10991;
    v_10993 = qcar(v_10992);
    goto v_10778;
v_10779:
    v_10992 = qcdr(v_10991);
    goto v_10780;
v_10781:
    v_10991 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10782;
v_10783:
    goto v_10777;
v_10778:
    goto v_10779;
v_10780:
    goto v_10781;
v_10782:
    v_10991 = list2star(v_10993, v_10992, v_10991);
    env = stack[-5];
    v_10991 = ncons(v_10991);
    env = stack[-5];
    stack[-1] = v_10991;
    stack[-2] = v_10991;
v_10764:
    v_10991 = stack[-3];
    v_10991 = qcdr(v_10991);
    stack[-3] = v_10991;
    v_10991 = stack[-3];
    if (v_10991 == nil) goto v_10793;
    else goto v_10794;
v_10793:
    v_10991 = stack[-2];
    goto v_10763;
v_10794:
    goto v_10802;
v_10798:
    stack[0] = stack[-1];
    goto v_10799;
v_10800:
    v_10991 = stack[-3];
    v_10991 = qcar(v_10991);
    goto v_10815;
v_10809:
    v_10992 = v_10991;
    v_10993 = qcar(v_10992);
    goto v_10810;
v_10811:
    v_10992 = qcdr(v_10991);
    goto v_10812;
v_10813:
    v_10991 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10814;
v_10815:
    goto v_10809;
v_10810:
    goto v_10811;
v_10812:
    goto v_10813;
v_10814:
    v_10991 = list2star(v_10993, v_10992, v_10991);
    env = stack[-5];
    v_10991 = ncons(v_10991);
    env = stack[-5];
    goto v_10801;
v_10802:
    goto v_10798;
v_10799:
    goto v_10800;
v_10801:
    v_10991 = Lrplacd(nil, stack[0], v_10991);
    env = stack[-5];
    v_10991 = stack[-1];
    v_10991 = qcdr(v_10991);
    stack[-1] = v_10991;
    goto v_10764;
v_10763:
    goto v_10756;
v_10757:
    goto v_10753;
v_10754:
    goto v_10755;
v_10756:
    {
        LispObject v_11000 = stack[-4];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_11000, v_10991);
    }
v_10750:
    goto v_10829;
v_10825:
    v_10991 = stack[-1];
    v_10991 = qcar(v_10991);
    v_10992 = qcar(v_10991);
    goto v_10826;
v_10827:
    v_10991 = stack[0];
    v_10991 = qcar(v_10991);
    v_10991 = qcar(v_10991);
    goto v_10828;
v_10829:
    goto v_10825;
v_10826:
    goto v_10827;
v_10828:
    if (equal(v_10992, v_10991)) goto v_10823;
    else goto v_10824;
v_10823:
    goto v_10845;
v_10841:
    v_10991 = stack[-1];
    v_10991 = qcar(v_10991);
    v_10992 = qcdr(v_10991);
    goto v_10842;
v_10843:
    v_10991 = stack[0];
    v_10991 = qcar(v_10991);
    v_10991 = qcdr(v_10991);
    v_10991 = qcar(v_10991);
    goto v_10844;
v_10845:
    goto v_10841;
v_10842:
    goto v_10843;
v_10844:
    v_10991 = (LispObject)greaterp2(v_10992, v_10991);
    v_10991 = v_10991 ? lisp_true : nil;
    env = stack[-5];
    if (v_10991 == nil) goto v_10839;
    goto v_10858;
v_10854:
    v_10991 = stack[0];
    v_10991 = qcar(v_10991);
    v_10992 = qcdr(v_10991);
    goto v_10855;
v_10856:
    v_10991 = stack[-1];
    v_10991 = qcar(v_10991);
    v_10991 = qcdr(v_10991);
    goto v_10857;
v_10858:
    goto v_10854;
v_10855:
    goto v_10856;
v_10857:
    v_10991 = Lrplaca(nil, v_10992, v_10991);
    env = stack[-5];
    goto v_10837;
v_10839:
v_10837:
    goto v_10874;
v_10870:
    v_10991 = stack[-1];
    v_10991 = qcar(v_10991);
    v_10992 = qcdr(v_10991);
    goto v_10871;
v_10872:
    v_10991 = stack[0];
    v_10991 = qcar(v_10991);
    v_10991 = qcdr(v_10991);
    v_10991 = qcdr(v_10991);
    goto v_10873;
v_10874:
    goto v_10870;
v_10871:
    goto v_10872;
v_10873:
    v_10991 = (LispObject)lessp2(v_10992, v_10991);
    v_10991 = v_10991 ? lisp_true : nil;
    env = stack[-5];
    if (v_10991 == nil) goto v_10868;
    goto v_10887;
v_10883:
    v_10991 = stack[0];
    v_10991 = qcar(v_10991);
    v_10992 = qcdr(v_10991);
    goto v_10884;
v_10885:
    v_10991 = stack[-1];
    v_10991 = qcar(v_10991);
    v_10991 = qcdr(v_10991);
    goto v_10886;
v_10887:
    goto v_10883;
v_10884:
    goto v_10885;
v_10886:
    v_10991 = Lrplacd(nil, v_10992, v_10991);
    env = stack[-5];
    goto v_10866;
v_10868:
v_10866:
    goto v_10899;
v_10895:
    goto v_10896;
v_10897:
    goto v_10906;
v_10902:
    stack[-2] = stack[0];
    goto v_10903;
v_10904:
    goto v_10913;
v_10909:
    v_10991 = stack[-1];
    v_10992 = qcdr(v_10991);
    goto v_10910;
v_10911:
    v_10991 = stack[0];
    v_10991 = qcdr(v_10991);
    goto v_10912;
v_10913:
    goto v_10909;
v_10910:
    goto v_10911;
v_10912:
    v_10991 = CC_powers4(elt(env, 0), v_10992, v_10991);
    env = stack[-5];
    goto v_10905;
v_10906:
    goto v_10902;
v_10903:
    goto v_10904;
v_10905:
    v_10991 = Lrplacd(nil, stack[-2], v_10991);
    env = stack[-5];
    goto v_10898;
v_10899:
    goto v_10895;
v_10896:
    goto v_10897;
v_10898:
    {
        LispObject v_11001 = stack[-3];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_11001, v_10991);
    }
v_10824:
    goto v_10925;
v_10921:
    v_10991 = stack[-1];
    v_10991 = qcar(v_10991);
    v_10992 = qcar(v_10991);
    goto v_10922;
v_10923:
    v_10991 = stack[0];
    v_10991 = qcar(v_10991);
    v_10991 = qcar(v_10991);
    goto v_10924;
v_10925:
    goto v_10921;
v_10922:
    goto v_10923;
v_10924:
    fn = elt(env, 2); // ordop
    v_10991 = (*qfn2(fn))(fn, v_10992, v_10991);
    env = stack[-5];
    if (v_10991 == nil) goto v_10919;
    goto v_10937;
v_10933:
    v_10991 = stack[0];
    v_10991 = qcar(v_10991);
    v_10992 = qcdr(v_10991);
    goto v_10934;
v_10935:
    v_10991 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10936;
v_10937:
    goto v_10933;
v_10934:
    goto v_10935;
v_10936:
    v_10991 = Lrplacd(nil, v_10992, v_10991);
    env = stack[-5];
    goto v_10947;
v_10943:
    goto v_10944;
v_10945:
    goto v_10954;
v_10950:
    stack[-2] = stack[0];
    goto v_10951;
v_10952:
    goto v_10961;
v_10957:
    v_10992 = stack[-1];
    goto v_10958;
v_10959:
    v_10991 = stack[0];
    v_10991 = qcdr(v_10991);
    goto v_10960;
v_10961:
    goto v_10957;
v_10958:
    goto v_10959;
v_10960:
    v_10991 = CC_powers4(elt(env, 0), v_10992, v_10991);
    env = stack[-5];
    goto v_10953;
v_10954:
    goto v_10950;
v_10951:
    goto v_10952;
v_10953:
    v_10991 = Lrplacd(nil, stack[-2], v_10991);
    env = stack[-5];
    goto v_10946;
v_10947:
    goto v_10943;
v_10944:
    goto v_10945;
v_10946:
    {
        LispObject v_11002 = stack[-3];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_11002, v_10991);
    }
v_10919:
    goto v_10974;
v_10968:
    v_10991 = stack[-1];
    v_10991 = qcar(v_10991);
    stack[-2] = qcar(v_10991);
    goto v_10969;
v_10970:
    goto v_10983;
v_10979:
    v_10991 = stack[-1];
    v_10991 = qcar(v_10991);
    v_10992 = qcdr(v_10991);
    goto v_10980;
v_10981:
    v_10991 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10982;
v_10983:
    goto v_10979;
v_10980:
    goto v_10981;
v_10982:
    v_10992 = cons(v_10992, v_10991);
    env = stack[-5];
    goto v_10971;
v_10972:
    v_10991 = stack[-3];
    goto v_10973;
v_10974:
    goto v_10968;
v_10969:
    goto v_10970;
v_10971:
    goto v_10972;
v_10973:
    v_10991 = acons(stack[-2], v_10992, v_10991);
    env = stack[-5];
    stack[-3] = v_10991;
    v_10991 = stack[-1];
    v_10991 = qcdr(v_10991);
    stack[-1] = v_10991;
    goto v_10670;
    v_10991 = nil;
    return onevalue(v_10991);
}



// Code for om2mml

static LispObject CC_om2mml(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10681;
    LispObject fn;
    argcheck(nargs, 0, "om2mml");
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
    fn = elt(env, 2); // om2ir
    v_10681 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_10681;
    v_10681 = lisp_true;
    fn = elt(env, 3); // terpri!*
    v_10681 = (*qfn1(fn))(fn, v_10681);
    env = stack[-1];
    v_10681 = elt(env, 1); // "Intermediate representation:"
    v_10681 = Lprinc(nil, v_10681);
    env = stack[-1];
    v_10681 = lisp_true;
    fn = elt(env, 3); // terpri!*
    v_10681 = (*qfn1(fn))(fn, v_10681);
    env = stack[-1];
    v_10681 = stack[0];
    v_10681 = Lprinc(nil, v_10681);
    env = stack[-1];
    v_10681 = lisp_true;
    fn = elt(env, 3); // terpri!*
    v_10681 = (*qfn1(fn))(fn, v_10681);
    env = stack[-1];
    v_10681 = stack[0];
    fn = elt(env, 4); // ir2mml
    v_10681 = (*qfn1(fn))(fn, v_10681);
    v_10681 = nil;
    return onevalue(v_10681);
}



// Code for !*wedgepf2pf

static LispObject CC_Hwedgepf2pf(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10697, v_10698, v_10699;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10664;
// end of prologue
    stack[-1] = nil;
v_10669:
    v_10697 = stack[0];
    if (v_10697 == nil) goto v_10672;
    else goto v_10673;
v_10672:
    v_10697 = stack[-1];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_10697);
    }
v_10673:
    goto v_10686;
v_10680:
    v_10697 = stack[0];
    v_10697 = qcar(v_10697);
    v_10697 = qcar(v_10697);
    fn = elt(env, 2); // mkuwedge
    v_10699 = (*qfn1(fn))(fn, v_10697);
    env = stack[-2];
    goto v_10681;
v_10682:
    v_10697 = stack[0];
    v_10697 = qcar(v_10697);
    v_10698 = qcdr(v_10697);
    goto v_10683;
v_10684:
    v_10697 = stack[-1];
    goto v_10685;
v_10686:
    goto v_10680;
v_10681:
    goto v_10682;
v_10683:
    goto v_10684;
v_10685:
    v_10697 = acons(v_10699, v_10698, v_10697);
    env = stack[-2];
    stack[-1] = v_10697;
    v_10697 = stack[0];
    v_10697 = qcdr(v_10697);
    stack[0] = v_10697;
    goto v_10669;
    v_10697 = nil;
    return onevalue(v_10697);
}



// Code for delete!-dups

static LispObject CC_deleteKdups(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10708, v_10709, v_10710;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10664;
// end of prologue
    v_10710 = nil;
v_10669:
    v_10708 = stack[0];
    if (v_10708 == nil) goto v_10673;
    goto v_10683;
v_10679:
    v_10708 = stack[0];
    v_10709 = qcar(v_10708);
    goto v_10680;
v_10681:
    v_10708 = stack[0];
    v_10708 = qcdr(v_10708);
    goto v_10682;
v_10683:
    goto v_10679;
v_10680:
    goto v_10681;
v_10682:
    v_10708 = Lmember(nil, v_10709, v_10708);
    if (v_10708 == nil) goto v_10678;
    v_10708 = stack[0];
    v_10708 = qcdr(v_10708);
    stack[0] = v_10708;
    goto v_10669;
v_10678:
    goto v_10698;
v_10694:
    v_10708 = stack[0];
    v_10708 = qcar(v_10708);
    goto v_10695;
v_10696:
    v_10709 = v_10710;
    goto v_10697;
v_10698:
    goto v_10694;
v_10695:
    goto v_10696;
v_10697:
    v_10708 = cons(v_10708, v_10709);
    env = stack[-1];
    v_10710 = v_10708;
    v_10708 = stack[0];
    v_10708 = qcdr(v_10708);
    stack[0] = v_10708;
    goto v_10669;
    goto v_10671;
v_10673:
    v_10708 = v_10710;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_10708);
    }
v_10671:
    v_10708 = nil;
    return onevalue(v_10708);
}



// Code for scal!*list

static LispObject CC_scalHlist(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10698, v_10699;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10664,v_10665);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10665;
    stack[-1] = v_10664;
// end of prologue
    stack[-2] = nil;
v_10670:
    v_10698 = stack[0];
    if (v_10698 == nil) goto v_10673;
    else goto v_10674;
v_10673:
    v_10698 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_10698);
    }
v_10674:
    goto v_10685;
v_10681:
    goto v_10691;
v_10687:
    v_10699 = stack[-1];
    goto v_10688;
v_10689:
    v_10698 = stack[0];
    v_10698 = qcar(v_10698);
    goto v_10690;
v_10691:
    goto v_10687;
v_10688:
    goto v_10689;
v_10690:
    fn = elt(env, 2); // !:times
    v_10699 = (*qfn2(fn))(fn, v_10699, v_10698);
    env = stack[-3];
    goto v_10682;
v_10683:
    v_10698 = stack[-2];
    goto v_10684;
v_10685:
    goto v_10681;
v_10682:
    goto v_10683;
v_10684:
    v_10698 = cons(v_10699, v_10698);
    env = stack[-3];
    stack[-2] = v_10698;
    v_10698 = stack[0];
    v_10698 = qcdr(v_10698);
    stack[0] = v_10698;
    goto v_10670;
    v_10698 = nil;
    return onevalue(v_10698);
}



// Code for physop!-ordop

static LispObject CC_physopKordop(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10852, v_10853;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10664,v_10665);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_10665;
    stack[-1] = v_10664;
// end of prologue
v_10663:
    v_10852 = stack[-1];
    fn = elt(env, 3); // !*physopp
    v_10852 = (*qfn1(fn))(fn, v_10852);
    env = stack[-4];
    if (v_10852 == nil) goto v_10676;
    v_10852 = stack[0];
    fn = elt(env, 3); // !*physopp
    v_10852 = (*qfn1(fn))(fn, v_10852);
    env = stack[-4];
    if (v_10852 == nil) goto v_10676;
    goto v_10677;
v_10676:
    v_10852 = stack[-1];
    fn = elt(env, 3); // !*physopp
    v_10852 = (*qfn1(fn))(fn, v_10852);
    env = stack[-4];
    if (v_10852 == nil) goto v_10687;
    v_10852 = nil;
    goto v_10685;
v_10687:
    v_10852 = stack[0];
    fn = elt(env, 3); // !*physopp
    v_10852 = (*qfn1(fn))(fn, v_10852);
    env = stack[-4];
    if (v_10852 == nil) goto v_10692;
    v_10852 = lisp_true;
    goto v_10685;
v_10692:
    goto v_10703;
v_10699:
    v_10853 = stack[-1];
    goto v_10700;
v_10701:
    v_10852 = stack[0];
    goto v_10702;
v_10703:
    goto v_10699;
v_10700:
    goto v_10701;
v_10702:
    {
        fn = elt(env, 4); // ordop2
        return (*qfn2(fn))(fn, v_10853, v_10852);
    }
    v_10852 = nil;
v_10685:
    goto v_10673;
v_10677:
    v_10852 = stack[-1];
    if (symbolp(v_10852)) goto v_10708;
    else goto v_10709;
v_10708:
    goto v_10716;
v_10712:
    v_10853 = stack[-1];
    goto v_10713;
v_10714:
    v_10852 = elt(env, 1); // physopname
    goto v_10715;
v_10716:
    goto v_10712;
v_10713:
    goto v_10714;
v_10715:
    v_10852 = get(v_10853, v_10852);
    env = stack[-4];
    stack[-3] = v_10852;
    goto v_10707;
v_10709:
    goto v_10726;
v_10722:
    v_10852 = stack[-1];
    v_10853 = qcar(v_10852);
    goto v_10723;
v_10724:
    v_10852 = elt(env, 1); // physopname
    goto v_10725;
v_10726:
    goto v_10722;
v_10723:
    goto v_10724;
v_10725:
    v_10852 = get(v_10853, v_10852);
    env = stack[-4];
    stack[-3] = v_10852;
    goto v_10735;
v_10731:
    v_10853 = stack[-3];
    goto v_10732;
v_10733:
    v_10852 = stack[-1];
    v_10852 = qcdr(v_10852);
    goto v_10734;
v_10735:
    goto v_10731;
v_10732:
    goto v_10733;
v_10734:
    v_10852 = cons(v_10853, v_10852);
    env = stack[-4];
    stack[-3] = v_10852;
    v_10852 = stack[-1];
    v_10852 = qcar(v_10852);
    stack[-1] = v_10852;
    goto v_10707;
v_10707:
    goto v_10750;
v_10746:
    v_10853 = stack[-1];
    goto v_10747;
v_10748:
    v_10852 = qvalue(elt(env, 2)); // specoplist!*
    goto v_10749;
v_10750:
    goto v_10746;
v_10747:
    goto v_10748;
v_10749:
    v_10852 = Lmember(nil, v_10853, v_10852);
    if (v_10852 == nil) goto v_10745;
    v_10852 = lisp_true;
    goto v_10673;
v_10745:
    v_10852 = stack[0];
    if (symbolp(v_10852)) goto v_10757;
    else goto v_10758;
v_10757:
    goto v_10765;
v_10761:
    v_10853 = stack[0];
    goto v_10762;
v_10763:
    v_10852 = elt(env, 1); // physopname
    goto v_10764;
v_10765:
    goto v_10761;
v_10762:
    goto v_10763;
v_10764:
    v_10852 = get(v_10853, v_10852);
    env = stack[-4];
    stack[-2] = v_10852;
    goto v_10756;
v_10758:
    goto v_10775;
v_10771:
    v_10852 = stack[0];
    v_10853 = qcar(v_10852);
    goto v_10772;
v_10773:
    v_10852 = elt(env, 1); // physopname
    goto v_10774;
v_10775:
    goto v_10771;
v_10772:
    goto v_10773;
v_10774:
    v_10852 = get(v_10853, v_10852);
    env = stack[-4];
    stack[-2] = v_10852;
    goto v_10784;
v_10780:
    v_10853 = stack[-2];
    goto v_10781;
v_10782:
    v_10852 = stack[0];
    v_10852 = qcdr(v_10852);
    goto v_10783;
v_10784:
    goto v_10780;
v_10781:
    goto v_10782;
v_10783:
    v_10852 = cons(v_10853, v_10852);
    env = stack[-4];
    stack[-2] = v_10852;
    v_10852 = stack[0];
    v_10852 = qcar(v_10852);
    stack[0] = v_10852;
    goto v_10756;
v_10756:
    goto v_10799;
v_10795:
    v_10853 = stack[0];
    goto v_10796;
v_10797:
    v_10852 = qvalue(elt(env, 2)); // specoplist!*
    goto v_10798;
v_10799:
    goto v_10795;
v_10796:
    goto v_10797;
v_10798:
    v_10852 = Lmember(nil, v_10853, v_10852);
    if (v_10852 == nil) goto v_10794;
    v_10852 = lisp_true;
    goto v_10673;
v_10794:
    v_10852 = stack[-3];
    fn = elt(env, 5); // opnum!*
    v_10852 = (*qfn1(fn))(fn, v_10852);
    env = stack[-4];
    stack[-1] = v_10852;
    v_10852 = stack[-2];
    fn = elt(env, 5); // opnum!*
    v_10852 = (*qfn1(fn))(fn, v_10852);
    env = stack[-4];
    stack[0] = v_10852;
    goto v_10817;
v_10813:
    v_10853 = stack[-1];
    goto v_10814;
v_10815:
    v_10852 = stack[0];
    goto v_10816;
v_10817:
    goto v_10813;
v_10814:
    goto v_10815;
v_10816:
    v_10852 = (LispObject)lessp2(v_10853, v_10852);
    v_10852 = v_10852 ? lisp_true : nil;
    env = stack[-4];
    if (v_10852 == nil) goto v_10811;
    v_10852 = lisp_true;
    goto v_10809;
v_10811:
    goto v_10828;
v_10824:
    v_10853 = stack[-1];
    goto v_10825;
v_10826:
    v_10852 = stack[0];
    goto v_10827;
v_10828:
    goto v_10824;
v_10825:
    goto v_10826;
v_10827:
    v_10852 = (LispObject)greaterp2(v_10853, v_10852);
    v_10852 = v_10852 ? lisp_true : nil;
    env = stack[-4];
    if (v_10852 == nil) goto v_10822;
    v_10852 = nil;
    goto v_10809;
v_10822:
    v_10852 = stack[-3];
    if (symbolp(v_10852)) goto v_10832;
    else goto v_10833;
v_10832:
    v_10852 = lisp_true;
    goto v_10809;
v_10833:
    v_10852 = stack[-2];
    if (symbolp(v_10852)) goto v_10836;
    else goto v_10837;
v_10836:
    v_10852 = nil;
    goto v_10809;
v_10837:
    goto v_10847;
v_10843:
    v_10852 = stack[-3];
    v_10853 = qcdr(v_10852);
    goto v_10844;
v_10845:
    v_10852 = stack[-2];
    v_10852 = qcdr(v_10852);
    goto v_10846;
v_10847:
    goto v_10843;
v_10844:
    goto v_10845;
v_10846:
    stack[-1] = v_10853;
    stack[0] = v_10852;
    goto v_10663;
    v_10852 = nil;
v_10809:
v_10673:
    return onevalue(v_10852);
}



// Code for zero!-roads

static LispObject CC_zeroKroads(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10698, v_10699;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10664;
// end of prologue
v_10663:
    v_10698 = stack[0];
    if (v_10698 == nil) goto v_10668;
    else goto v_10669;
v_10668:
    v_10698 = nil;
    goto v_10667;
v_10669:
    v_10698 = stack[0];
    v_10698 = qcar(v_10698);
    fn = elt(env, 1); // z!-roads
    v_10698 = (*qfn1(fn))(fn, v_10698);
    env = stack[-2];
    v_10699 = v_10698;
    v_10698 = v_10699;
    if (v_10698 == nil) goto v_10681;
    goto v_10688;
v_10684:
    stack[-1] = v_10699;
    goto v_10685;
v_10686:
    v_10698 = stack[0];
    v_10698 = qcdr(v_10698);
    v_10698 = CC_zeroKroads(elt(env, 0), v_10698);
    goto v_10687;
v_10688:
    goto v_10684;
v_10685:
    goto v_10686;
v_10687:
    {
        LispObject v_10702 = stack[-1];
        return cons(v_10702, v_10698);
    }
v_10681:
    v_10698 = stack[0];
    v_10698 = qcdr(v_10698);
    stack[0] = v_10698;
    goto v_10663;
    v_10698 = nil;
    goto v_10667;
    v_10698 = nil;
v_10667:
    return onevalue(v_10698);
}



// Code for revalx

static LispObject CC_revalx(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10688, v_10689;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_10689 = v_10664;
// end of prologue
    v_10688 = v_10689;
    if (!consp(v_10688)) goto v_10674;
    v_10688 = v_10689;
    v_10688 = qcar(v_10688);
    v_10688 = (consp(v_10688) ? nil : lisp_true);
    v_10688 = (v_10688 == nil ? lisp_true : nil);
    goto v_10672;
v_10674:
    v_10688 = nil;
    goto v_10672;
    v_10688 = nil;
v_10672:
    if (v_10688 == nil) goto v_10670;
    v_10688 = v_10689;
    fn = elt(env, 1); // prepf
    v_10688 = (*qfn1(fn))(fn, v_10688);
    env = stack[0];
    goto v_10668;
v_10670:
    v_10688 = v_10689;
    goto v_10668;
    v_10688 = nil;
v_10668:
    {
        fn = elt(env, 2); // reval
        return (*qfn1(fn))(fn, v_10688);
    }
}



// Code for di_restore

static LispObject CC_di_restore(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10674, v_10675;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10674 = v_10664;
// end of prologue
    goto v_10671;
v_10667:
    v_10675 = v_10674;
    goto v_10668;
v_10669:
    v_10674 = nil;
    goto v_10670;
v_10671:
    goto v_10667;
v_10668:
    goto v_10669;
v_10670:
    {
        fn = elt(env, 1); // di_restore1
        return (*qfn2(fn))(fn, v_10675, v_10674);
    }
}



// Code for general!-reduce!-mod!-p

static LispObject CC_generalKreduceKmodKp(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10720, v_10721, v_10722;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10664;
// end of prologue
    v_10720 = stack[0];
    if (v_10720 == nil) goto v_10668;
    else goto v_10669;
v_10668:
    v_10720 = nil;
    goto v_10667;
v_10669:
    v_10720 = stack[0];
    if (!consp(v_10720)) goto v_10676;
    else goto v_10677;
v_10676:
    v_10720 = lisp_true;
    goto v_10675;
v_10677:
    v_10720 = stack[0];
    v_10720 = qcar(v_10720);
    v_10720 = (consp(v_10720) ? nil : lisp_true);
    goto v_10675;
    v_10720 = nil;
v_10675:
    if (v_10720 == nil) goto v_10673;
    v_10720 = stack[0];
    fn = elt(env, 1); // general!-modular!-number
    v_10720 = (*qfn1(fn))(fn, v_10720);
    env = stack[-2];
    {
        fn = elt(env, 2); // !*n2f
        return (*qfn1(fn))(fn, v_10720);
    }
v_10673:
    v_10720 = stack[0];
    v_10720 = qcar(v_10720);
    v_10720 = qcdr(v_10720);
    stack[-1] = CC_generalKreduceKmodKp(elt(env, 0), v_10720);
    env = stack[-2];
    v_10720 = stack[0];
    v_10720 = qcdr(v_10720);
    v_10720 = CC_generalKreduceKmodKp(elt(env, 0), v_10720);
    v_10721 = stack[-1];
    v_10722 = v_10721;
    if (v_10722 == nil) goto v_10701;
    else goto v_10702;
v_10701:
    goto v_10700;
v_10702:
    goto v_10714;
v_10708:
    v_10722 = stack[0];
    v_10722 = qcar(v_10722);
    v_10722 = qcar(v_10722);
    goto v_10709;
v_10710:
    goto v_10711;
v_10712:
    goto v_10713;
v_10714:
    goto v_10708;
v_10709:
    goto v_10710;
v_10711:
    goto v_10712;
v_10713:
    return acons(v_10722, v_10721, v_10720);
    v_10720 = nil;
v_10700:
    goto v_10667;
    v_10720 = nil;
v_10667:
    return onevalue(v_10720);
}



// Code for lex_save_context

static LispObject CC_lex_save_context(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10737, v_10738;
    argcheck(nargs, 0, "lex_save_context");
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
    v_10737 = qvalue(elt(env, 1)); // lex_codename
    stack[-4] = v_10737;
    v_10737 = stack[-4];
    if (v_10737 == nil) goto v_10674;
    else goto v_10675;
v_10674:
    v_10737 = nil;
    goto v_10669;
v_10675:
    v_10737 = stack[-4];
    v_10737 = qcar(v_10737);
    stack[0] = v_10737;
    goto v_10687;
v_10683:
    goto v_10693;
v_10689:
    v_10737 = stack[0];
    v_10737 = qcdr(v_10737);
    v_10738 = Lintern(nil, v_10737);
    env = stack[-5];
    goto v_10690;
v_10691:
    v_10737 = elt(env, 2); // lex_dipthong
    goto v_10692;
v_10693:
    goto v_10689;
v_10690:
    goto v_10691;
v_10692:
    v_10738 = get(v_10738, v_10737);
    env = stack[-5];
    goto v_10684;
v_10685:
    v_10737 = stack[0];
    goto v_10686;
v_10687:
    goto v_10683;
v_10684:
    goto v_10685;
v_10686:
    v_10737 = cons(v_10738, v_10737);
    env = stack[-5];
    v_10737 = ncons(v_10737);
    env = stack[-5];
    stack[-2] = v_10737;
    stack[-3] = v_10737;
v_10670:
    v_10737 = stack[-4];
    v_10737 = qcdr(v_10737);
    stack[-4] = v_10737;
    v_10737 = stack[-4];
    if (v_10737 == nil) goto v_10703;
    else goto v_10704;
v_10703:
    v_10737 = stack[-3];
    goto v_10669;
v_10704:
    goto v_10712;
v_10708:
    stack[-1] = stack[-2];
    goto v_10709;
v_10710:
    v_10737 = stack[-4];
    v_10737 = qcar(v_10737);
    stack[0] = v_10737;
    goto v_10723;
v_10719:
    goto v_10729;
v_10725:
    v_10737 = stack[0];
    v_10737 = qcdr(v_10737);
    v_10738 = Lintern(nil, v_10737);
    env = stack[-5];
    goto v_10726;
v_10727:
    v_10737 = elt(env, 2); // lex_dipthong
    goto v_10728;
v_10729:
    goto v_10725;
v_10726:
    goto v_10727;
v_10728:
    v_10738 = get(v_10738, v_10737);
    env = stack[-5];
    goto v_10720;
v_10721:
    v_10737 = stack[0];
    goto v_10722;
v_10723:
    goto v_10719;
v_10720:
    goto v_10721;
v_10722:
    v_10737 = cons(v_10738, v_10737);
    env = stack[-5];
    v_10737 = ncons(v_10737);
    env = stack[-5];
    goto v_10711;
v_10712:
    goto v_10708;
v_10709:
    goto v_10710;
v_10711:
    v_10737 = Lrplacd(nil, stack[-1], v_10737);
    env = stack[-5];
    v_10737 = stack[-2];
    v_10737 = qcdr(v_10737);
    stack[-2] = v_10737;
    goto v_10670;
v_10669:
    return onevalue(v_10737);
}



// Code for monomdivide

static LispObject CC_monomdivide(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10785, v_10786, v_10787;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10664,v_10665);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_10665;
    stack[-4] = v_10664;
// end of prologue
    stack[-2] = nil;
    v_10785 = (LispObject)16+TAG_FIXNUM; // 1
    v_10785 = Lmkvect(nil, v_10785);
    env = stack[-6];
    stack[-5] = v_10785;
    goto v_10681;
v_10675:
    stack[-1] = stack[-5];
    goto v_10676;
v_10677:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10678;
v_10679:
    goto v_10689;
v_10685:
    goto v_10694;
v_10690:
    v_10786 = stack[-4];
    goto v_10691;
v_10692:
    v_10785 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10693;
v_10694:
    goto v_10690;
v_10691:
    goto v_10692;
v_10693:
    v_10787 = *(LispObject *)((char *)v_10786 + (CELL-TAG_VECTOR) + (((intptr_t)v_10785-TAG_FIXNUM)/(16/CELL)));
    goto v_10686;
v_10687:
    goto v_10702;
v_10698:
    v_10786 = stack[-3];
    goto v_10699;
v_10700:
    v_10785 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10701;
v_10702:
    goto v_10698;
v_10699:
    goto v_10700;
v_10701:
    v_10785 = *(LispObject *)((char *)v_10786 + (CELL-TAG_VECTOR) + (((intptr_t)v_10785-TAG_FIXNUM)/(16/CELL)));
    goto v_10688;
v_10689:
    goto v_10685;
v_10686:
    goto v_10687;
v_10688:
    v_10785 = difference2(v_10787, v_10785);
    env = stack[-6];
    goto v_10680;
v_10681:
    goto v_10675;
v_10676:
    goto v_10677;
v_10678:
    goto v_10679;
v_10680:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_10785;
    goto v_10710;
v_10706:
    v_10786 = stack[-4];
    goto v_10707;
v_10708:
    v_10785 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10709;
v_10710:
    goto v_10706;
v_10707:
    goto v_10708;
v_10709:
    v_10785 = *(LispObject *)((char *)v_10786 + (CELL-TAG_VECTOR) + (((intptr_t)v_10785-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_10785;
    goto v_10718;
v_10714:
    v_10786 = stack[-3];
    goto v_10715;
v_10716:
    v_10785 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10717;
v_10718:
    goto v_10714;
v_10715:
    goto v_10716;
v_10717:
    v_10785 = *(LispObject *)((char *)v_10786 + (CELL-TAG_VECTOR) + (((intptr_t)v_10785-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_10785;
v_10724:
    v_10785 = stack[0];
    v_10785 = qcar(v_10785);
    if (v_10785 == nil) goto v_10727;
    else goto v_10728;
v_10727:
    goto v_10723;
v_10728:
    goto v_10740;
v_10736:
    v_10785 = stack[0];
    v_10786 = qcar(v_10785);
    goto v_10737;
v_10738:
    v_10785 = stack[-1];
    v_10785 = qcar(v_10785);
    goto v_10739;
v_10740:
    goto v_10736;
v_10737:
    goto v_10738;
v_10739:
    if (equal(v_10786, v_10785)) goto v_10734;
    else goto v_10735;
v_10734:
    v_10785 = stack[0];
    v_10785 = qcdr(v_10785);
    stack[0] = v_10785;
    v_10785 = stack[-1];
    v_10785 = qcdr(v_10785);
    stack[-1] = v_10785;
    goto v_10733;
v_10735:
    goto v_10757;
v_10753:
    v_10785 = stack[0];
    v_10786 = qcar(v_10785);
    goto v_10754;
v_10755:
    v_10785 = stack[-2];
    goto v_10756;
v_10757:
    goto v_10753;
v_10754:
    goto v_10755;
v_10756:
    v_10785 = cons(v_10786, v_10785);
    env = stack[-6];
    stack[-2] = v_10785;
    v_10785 = stack[0];
    v_10785 = qcdr(v_10785);
    stack[0] = v_10785;
    goto v_10733;
v_10733:
    goto v_10724;
v_10723:
    goto v_10770;
v_10766:
    v_10786 = nil;
    goto v_10767;
v_10768:
    v_10785 = stack[-2];
    goto v_10769;
v_10770:
    goto v_10766;
v_10767:
    goto v_10768;
v_10769:
    v_10785 = cons(v_10786, v_10785);
    env = stack[-6];
    stack[-2] = v_10785;
    goto v_10779;
v_10773:
    stack[-1] = stack[-5];
    goto v_10774;
v_10775:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10776;
v_10777:
    v_10785 = stack[-2];
    v_10785 = Lreverse(nil, v_10785);
    goto v_10778;
v_10779:
    goto v_10773;
v_10774:
    goto v_10775;
v_10776:
    goto v_10777;
v_10778:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_10785;
    v_10785 = stack[-5];
    return onevalue(v_10785);
}



// Code for sfto_ucontentf1

static LispObject CC_sfto_ucontentf1(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10737, v_10738;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10664,v_10665);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10665;
    stack[-1] = v_10664;
// end of prologue
    stack[-2] = nil;
v_10671:
    v_10737 = stack[-1];
    if (!consp(v_10737)) goto v_10684;
    else goto v_10685;
v_10684:
    v_10737 = lisp_true;
    goto v_10683;
v_10685:
    v_10737 = stack[-1];
    v_10737 = qcar(v_10737);
    v_10737 = (consp(v_10737) ? nil : lisp_true);
    goto v_10683;
    v_10737 = nil;
v_10683:
    if (v_10737 == nil) goto v_10681;
    v_10737 = lisp_true;
    goto v_10679;
v_10681:
    goto v_10701;
v_10697:
    v_10737 = stack[-1];
    v_10737 = qcar(v_10737);
    v_10737 = qcar(v_10737);
    v_10738 = qcar(v_10737);
    goto v_10698;
v_10699:
    v_10737 = stack[0];
    goto v_10700;
v_10701:
    goto v_10697;
v_10698:
    goto v_10699;
v_10700:
    v_10737 = Lneq(nil, v_10738, v_10737);
    env = stack[-3];
    goto v_10679;
    v_10737 = nil;
v_10679:
    if (v_10737 == nil) goto v_10677;
    goto v_10672;
v_10677:
    goto v_10712;
v_10708:
    v_10737 = stack[-1];
    v_10737 = qcar(v_10737);
    v_10738 = qcdr(v_10737);
    goto v_10709;
v_10710:
    v_10737 = stack[-2];
    goto v_10711;
v_10712:
    goto v_10708;
v_10709:
    goto v_10710;
v_10711:
    v_10737 = cons(v_10738, v_10737);
    env = stack[-3];
    stack[-2] = v_10737;
    v_10737 = stack[-1];
    v_10737 = qcdr(v_10737);
    stack[-1] = v_10737;
    goto v_10671;
v_10672:
    v_10737 = stack[-1];
    v_10738 = v_10737;
v_10673:
    v_10737 = stack[-2];
    if (v_10737 == nil) goto v_10722;
    else goto v_10723;
v_10722:
    v_10737 = v_10738;
    goto v_10670;
v_10723:
    goto v_10731;
v_10727:
    v_10737 = stack[-2];
    v_10737 = qcar(v_10737);
    goto v_10728;
v_10729:
    goto v_10730;
v_10731:
    goto v_10727;
v_10728:
    goto v_10729;
v_10730:
    fn = elt(env, 1); // sfto_gcdf!*
    v_10737 = (*qfn2(fn))(fn, v_10737, v_10738);
    env = stack[-3];
    v_10738 = v_10737;
    v_10737 = stack[-2];
    v_10737 = qcdr(v_10737);
    stack[-2] = v_10737;
    goto v_10673;
v_10670:
    return onevalue(v_10737);
}



// Code for simpg3

static LispObject CC_simpg3(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10674, v_10675;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10674 = v_10664;
// end of prologue
    goto v_10671;
v_10667:
    v_10675 = v_10674;
    goto v_10668;
v_10669:
    v_10674 = elt(env, 1); // g3
    goto v_10670;
v_10671:
    goto v_10667;
v_10668:
    goto v_10669;
v_10670:
    {
        fn = elt(env, 2); // simpcv
        return (*qfn2(fn))(fn, v_10675, v_10674);
    }
}



// Code for findnthroot

static LispObject CC_findnthroot(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10667;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10667 = v_10664;
// end of prologue
    v_10667 = nil;
    return onevalue(v_10667);
}



// Code for prepsq!*

static LispObject CC_prepsqH(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10971, v_10972, v_10973;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_10664;
// end of prologue
// Binding !*combinelogs
// FLUIDBIND: reloadenv=11 litvec-offset=1 saveloc=8
{   bind_fluid_stack bind_fluid_var(-11, 1, -8);
    qvalue(elt(env, 1)) = nil; // !*combinelogs
    v_10971 = stack[-9];
    v_10971 = qcar(v_10971);
    if (v_10971 == nil) goto v_10673;
    else goto v_10674;
v_10673:
    v_10971 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10670;
v_10674:
    v_10971 = qvalue(elt(env, 2)); // ordl!*
    fn = elt(env, 13); // setkorder
    v_10971 = (*qfn1(fn))(fn, v_10971);
    env = stack[-11];
    stack[-10] = v_10971;
    goto v_10686;
v_10682:
    goto v_10692;
v_10688:
    v_10971 = qvalue(elt(env, 3)); // factors!*
    stack[-7] = v_10971;
v_10698:
    v_10971 = stack[-7];
    if (v_10971 == nil) goto v_10703;
    else goto v_10704;
v_10703:
    v_10971 = nil;
    v_10972 = v_10971;
    goto v_10697;
v_10704:
    v_10971 = stack[-7];
    v_10971 = qcar(v_10971);
    v_10972 = v_10971;
    v_10971 = v_10972;
    if (symbolp(v_10971)) goto v_10713;
    v_10971 = nil;
    goto v_10711;
v_10713:
    goto v_10723;
v_10719:
    v_10973 = v_10972;
    goto v_10720;
v_10721:
    v_10971 = elt(env, 4); // prepsq!*fn
    goto v_10722;
v_10723:
    goto v_10719;
v_10720:
    goto v_10721;
v_10722:
    v_10971 = get(v_10973, v_10971);
    env = stack[-11];
    v_10973 = v_10971;
    if (v_10971 == nil) goto v_10717;
    goto v_10733;
v_10727:
    goto v_10728;
v_10729:
    v_10971 = stack[-9];
    goto v_10730;
v_10731:
    goto v_10732;
v_10733:
    goto v_10727;
v_10728:
    goto v_10729;
v_10730:
    goto v_10731;
v_10732:
    v_10971 = Lapply2(nil, 3, v_10973, v_10971, v_10972);
    env = stack[-11];
    goto v_10711;
v_10717:
    v_10971 = v_10972;
    if (!symbolp(v_10971)) v_10971 = nil;
    else { v_10971 = qfastgets(v_10971);
           if (v_10971 != nil) { v_10971 = elt(v_10971, 24); // klist
#ifdef RECORD_GET
             if (v_10971 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v_10971 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v_10971 == SPID_NOPROP) v_10971 = nil; }}
#endif
    stack[-3] = v_10971;
    v_10971 = stack[-3];
    if (v_10971 == nil) goto v_10749;
    else goto v_10750;
v_10749:
    v_10971 = nil;
    goto v_10743;
v_10750:
    v_10971 = stack[-3];
    v_10971 = qcar(v_10971);
    v_10971 = qcar(v_10971);
    v_10971 = ncons(v_10971);
    env = stack[-11];
    stack[-1] = v_10971;
    stack[-2] = v_10971;
v_10744:
    v_10971 = stack[-3];
    v_10971 = qcdr(v_10971);
    stack[-3] = v_10971;
    v_10971 = stack[-3];
    if (v_10971 == nil) goto v_10763;
    else goto v_10764;
v_10763:
    v_10971 = stack[-2];
    goto v_10743;
v_10764:
    goto v_10772;
v_10768:
    stack[0] = stack[-1];
    goto v_10769;
v_10770:
    v_10971 = stack[-3];
    v_10971 = qcar(v_10971);
    v_10971 = qcar(v_10971);
    v_10971 = ncons(v_10971);
    env = stack[-11];
    goto v_10771;
v_10772:
    goto v_10768;
v_10769:
    goto v_10770;
v_10771:
    v_10971 = Lrplacd(nil, stack[0], v_10971);
    env = stack[-11];
    v_10971 = stack[-1];
    v_10971 = qcdr(v_10971);
    stack[-1] = v_10971;
    goto v_10744;
v_10743:
    goto v_10711;
    v_10971 = nil;
v_10711:
    stack[-6] = v_10971;
    v_10971 = stack[-6];
    fn = elt(env, 14); // lastpair
    v_10971 = (*qfn1(fn))(fn, v_10971);
    env = stack[-11];
    stack[-5] = v_10971;
    v_10971 = stack[-7];
    v_10971 = qcdr(v_10971);
    stack[-7] = v_10971;
    v_10971 = stack[-5];
    if (!consp(v_10971)) goto v_10788;
    else goto v_10789;
v_10788:
    goto v_10698;
v_10789:
v_10699:
    v_10971 = stack[-7];
    if (v_10971 == nil) goto v_10793;
    else goto v_10794;
v_10793:
    v_10971 = stack[-6];
    v_10972 = v_10971;
    goto v_10697;
v_10794:
    goto v_10802;
v_10798:
    stack[-4] = stack[-5];
    goto v_10799;
v_10800:
    v_10971 = stack[-7];
    v_10971 = qcar(v_10971);
    v_10972 = v_10971;
    if (symbolp(v_10972)) goto v_10810;
    v_10971 = nil;
    goto v_10808;
v_10810:
    goto v_10820;
v_10816:
    v_10973 = v_10971;
    goto v_10817;
v_10818:
    v_10972 = elt(env, 4); // prepsq!*fn
    goto v_10819;
v_10820:
    goto v_10816;
v_10817:
    goto v_10818;
v_10819:
    v_10972 = get(v_10973, v_10972);
    env = stack[-11];
    v_10973 = v_10972;
    if (v_10972 == nil) goto v_10814;
    goto v_10830;
v_10824:
    goto v_10825;
v_10826:
    v_10972 = stack[-9];
    goto v_10827;
v_10828:
    goto v_10829;
v_10830:
    goto v_10824;
v_10825:
    goto v_10826;
v_10827:
    goto v_10828;
v_10829:
    v_10971 = Lapply2(nil, 3, v_10973, v_10972, v_10971);
    env = stack[-11];
    goto v_10808;
v_10814:
    if (!symbolp(v_10971)) v_10971 = nil;
    else { v_10971 = qfastgets(v_10971);
           if (v_10971 != nil) { v_10971 = elt(v_10971, 24); // klist
#ifdef RECORD_GET
             if (v_10971 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v_10971 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v_10971 == SPID_NOPROP) v_10971 = nil; }}
#endif
    stack[-3] = v_10971;
    v_10971 = stack[-3];
    if (v_10971 == nil) goto v_10846;
    else goto v_10847;
v_10846:
    v_10971 = nil;
    goto v_10840;
v_10847:
    v_10971 = stack[-3];
    v_10971 = qcar(v_10971);
    v_10971 = qcar(v_10971);
    v_10971 = ncons(v_10971);
    env = stack[-11];
    stack[-1] = v_10971;
    stack[-2] = v_10971;
v_10841:
    v_10971 = stack[-3];
    v_10971 = qcdr(v_10971);
    stack[-3] = v_10971;
    v_10971 = stack[-3];
    if (v_10971 == nil) goto v_10860;
    else goto v_10861;
v_10860:
    v_10971 = stack[-2];
    goto v_10840;
v_10861:
    goto v_10869;
v_10865:
    stack[0] = stack[-1];
    goto v_10866;
v_10867:
    v_10971 = stack[-3];
    v_10971 = qcar(v_10971);
    v_10971 = qcar(v_10971);
    v_10971 = ncons(v_10971);
    env = stack[-11];
    goto v_10868;
v_10869:
    goto v_10865;
v_10866:
    goto v_10867;
v_10868:
    v_10971 = Lrplacd(nil, stack[0], v_10971);
    env = stack[-11];
    v_10971 = stack[-1];
    v_10971 = qcdr(v_10971);
    stack[-1] = v_10971;
    goto v_10841;
v_10840:
    goto v_10808;
    v_10971 = nil;
v_10808:
    goto v_10801;
v_10802:
    goto v_10798;
v_10799:
    goto v_10800;
v_10801:
    v_10971 = Lrplacd(nil, stack[-4], v_10971);
    env = stack[-11];
    v_10971 = stack[-5];
    fn = elt(env, 14); // lastpair
    v_10971 = (*qfn1(fn))(fn, v_10971);
    env = stack[-11];
    stack[-5] = v_10971;
    v_10971 = stack[-7];
    v_10971 = qcdr(v_10971);
    stack[-7] = v_10971;
    goto v_10699;
v_10697:
    goto v_10689;
v_10690:
    v_10971 = elt(env, 5); // ordop
    goto v_10691;
v_10692:
    goto v_10688;
v_10689:
    goto v_10690;
v_10691:
    fn = elt(env, 15); // sort
    stack[0] = (*qfn2(fn))(fn, v_10972, v_10971);
    env = stack[-11];
    goto v_10683;
v_10684:
    goto v_10889;
v_10885:
    goto v_10895;
v_10891:
    v_10972 = qvalue(elt(env, 3)); // factors!*
    goto v_10892;
v_10893:
    v_10971 = elt(env, 5); // ordop
    goto v_10894;
v_10895:
    goto v_10891;
v_10892:
    goto v_10893;
v_10894:
    fn = elt(env, 15); // sort
    v_10972 = (*qfn2(fn))(fn, v_10972, v_10971);
    env = stack[-11];
    goto v_10886;
v_10887:
    v_10971 = qvalue(elt(env, 2)); // ordl!*
    goto v_10888;
v_10889:
    goto v_10885;
v_10886:
    goto v_10887;
v_10888:
    v_10971 = Lappend(nil, v_10972, v_10971);
    env = stack[-11];
    goto v_10685;
v_10686:
    goto v_10682;
v_10683:
    goto v_10684;
v_10685:
    v_10971 = Lappend(nil, stack[0], v_10971);
    env = stack[-11];
    fn = elt(env, 13); // setkorder
    v_10971 = (*qfn1(fn))(fn, v_10971);
    env = stack[-11];
    goto v_10911;
v_10907:
    v_10972 = qvalue(elt(env, 6)); // kord!*
    goto v_10908;
v_10909:
    v_10971 = stack[-10];
    goto v_10910;
v_10911:
    goto v_10907;
v_10908:
    goto v_10909;
v_10910:
    if (equal(v_10972, v_10971)) goto v_10906;
    v_10971 = lisp_true;
    goto v_10904;
v_10906:
    v_10971 = qvalue(elt(env, 7)); // wtl!*
    goto v_10904;
    v_10971 = nil;
v_10904:
    if (v_10971 == nil) goto v_10902;
    goto v_10923;
v_10919:
    v_10971 = stack[-9];
    v_10971 = qcar(v_10971);
    fn = elt(env, 16); // formop
    stack[0] = (*qfn1(fn))(fn, v_10971);
    env = stack[-11];
    goto v_10920;
v_10921:
    v_10971 = stack[-9];
    v_10971 = qcdr(v_10971);
    fn = elt(env, 16); // formop
    v_10971 = (*qfn1(fn))(fn, v_10971);
    env = stack[-11];
    goto v_10922;
v_10923:
    goto v_10919;
v_10920:
    goto v_10921;
v_10922:
    v_10971 = cons(stack[0], v_10971);
    env = stack[-11];
    stack[-9] = v_10971;
    goto v_10900;
v_10902:
v_10900:
    v_10971 = qvalue(elt(env, 8)); // !*rat
    if (v_10971 == nil) goto v_10934;
    else goto v_10932;
v_10934:
    v_10971 = qvalue(elt(env, 9)); // !*div
    if (v_10971 == nil) goto v_10937;
    else goto v_10932;
v_10937:
    v_10971 = qvalue(elt(env, 10)); // upl!*
    if (v_10971 == nil) goto v_10940;
    else goto v_10932;
v_10940:
    v_10971 = qvalue(elt(env, 11)); // dnl!*
    if (v_10971 == nil) goto v_10942;
    else goto v_10932;
v_10942:
    goto v_10933;
v_10932:
    goto v_10952;
v_10946:
    v_10971 = stack[-9];
    v_10973 = qcar(v_10971);
    goto v_10947;
v_10948:
    v_10971 = stack[-9];
    v_10972 = qcdr(v_10971);
    goto v_10949;
v_10950:
    v_10971 = nil;
    goto v_10951;
v_10952:
    goto v_10946;
v_10947:
    goto v_10948;
v_10949:
    goto v_10950;
v_10951:
    fn = elt(env, 17); // prepsq!*1
    v_10971 = (*qfnn(fn))(fn, 3, v_10973, v_10972, v_10971);
    env = stack[-11];
    fn = elt(env, 18); // replus
    v_10971 = (*qfn1(fn))(fn, v_10971);
    env = stack[-11];
    goto v_10931;
v_10933:
    goto v_10965;
v_10961:
    v_10972 = stack[-9];
    goto v_10962;
v_10963:
    v_10971 = elt(env, 12); // prepsq!*2
    goto v_10964;
v_10965:
    goto v_10961;
v_10962:
    goto v_10963;
v_10964:
    fn = elt(env, 19); // sqform
    v_10971 = (*qfn2(fn))(fn, v_10972, v_10971);
    env = stack[-11];
    goto v_10931;
    v_10971 = nil;
v_10931:
    stack[-9] = v_10971;
    v_10971 = stack[-10];
    fn = elt(env, 13); // setkorder
    v_10971 = (*qfn1(fn))(fn, v_10971);
    v_10971 = stack[-9];
v_10670:
    ;}  // end of a binding scope
    return onevalue(v_10971);
}



// Code for ibalp_recalcv

static LispObject CC_ibalp_recalcv(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10752, v_10753;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_10752 = v_10664;
// end of prologue
    stack[-2] = v_10752;
v_10669:
    v_10752 = stack[-2];
    if (v_10752 == nil) goto v_10673;
    else goto v_10674;
v_10673:
    v_10752 = nil;
    goto v_10668;
v_10674:
    v_10752 = stack[-2];
    v_10752 = qcar(v_10752);
    stack[-1] = v_10752;
    goto v_10685;
v_10681:
    v_10752 = stack[-1];
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    stack[0] = qcdr(v_10752);
    goto v_10682;
v_10683:
    goto v_10701;
v_10697:
    v_10752 = stack[-1];
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10753 = qcar(v_10752);
    goto v_10698;
v_10699:
    v_10752 = elt(env, 1); // 0.05
    goto v_10700;
v_10701:
    goto v_10697;
v_10698:
    goto v_10699;
v_10700:
    v_10752 = difference2(v_10753, v_10752);
    env = stack[-3];
    goto v_10684;
v_10685:
    goto v_10681;
v_10682:
    goto v_10683;
v_10684:
    fn = elt(env, 2); // setcar
    v_10752 = (*qfn2(fn))(fn, stack[0], v_10752);
    env = stack[-3];
    goto v_10719;
v_10715:
    v_10752 = stack[-1];
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    stack[0] = qcdr(v_10752);
    goto v_10716;
v_10717:
    goto v_10736;
v_10732:
    v_10752 = stack[-1];
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10752 = qcdr(v_10752);
    v_10753 = qcar(v_10752);
    goto v_10733;
v_10734:
    v_10752 = elt(env, 1); // 0.05
    goto v_10735;
v_10736:
    goto v_10732;
v_10733:
    goto v_10734;
v_10735:
    v_10752 = difference2(v_10753, v_10752);
    env = stack[-3];
    goto v_10718;
v_10719:
    goto v_10715;
v_10716:
    goto v_10717;
v_10718:
    fn = elt(env, 2); // setcar
    v_10752 = (*qfn2(fn))(fn, stack[0], v_10752);
    env = stack[-3];
    v_10752 = stack[-2];
    v_10752 = qcdr(v_10752);
    stack[-2] = v_10752;
    goto v_10669;
v_10668:
    return onevalue(v_10752);
}



// Code for mvar_member

static LispObject CC_mvar_member(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10698, v_10699, v_10700, v_10701;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10700 = v_10665;
    v_10701 = v_10664;
// end of prologue
    goto v_10675;
v_10671:
    v_10699 = v_10701;
    goto v_10672;
v_10673:
    v_10698 = v_10700;
    goto v_10674;
v_10675:
    goto v_10671;
v_10672:
    goto v_10673;
v_10674:
    if (equal(v_10699, v_10698)) goto v_10669;
    else goto v_10670;
v_10669:
    v_10698 = lisp_true;
    goto v_10668;
v_10670:
    v_10698 = v_10700;
    if (!consp(v_10698)) goto v_10684;
    goto v_10691;
v_10687:
    v_10698 = v_10701;
    goto v_10688;
v_10689:
    v_10699 = v_10700;
    v_10699 = qcdr(v_10699);
    goto v_10690;
v_10691:
    goto v_10687;
v_10688:
    goto v_10689;
v_10690:
    {
        fn = elt(env, 1); // arglist_member
        return (*qfn2(fn))(fn, v_10698, v_10699);
    }
v_10684:
    v_10698 = nil;
    goto v_10682;
    v_10698 = nil;
v_10682:
    goto v_10668;
    v_10698 = nil;
v_10668:
    return onevalue(v_10698);
}



// Code for variablesir

static LispObject CC_variablesir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10707, v_10708;
    LispObject fn;
    argcheck(nargs, 0, "variablesir");
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
    goto v_10677;
v_10673:
    v_10708 = qvalue(elt(env, 1)); // char
    goto v_10674;
v_10675:
    v_10707 = elt(env, 2); // (!/ o m b v a r)
    goto v_10676;
v_10677:
    goto v_10673;
v_10674:
    goto v_10675;
v_10676:
    if (equal(v_10708, v_10707)) goto v_10672;
    fn = elt(env, 3); // omvir
    v_10707 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_10707;
    fn = elt(env, 4); // lex
    v_10707 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_10707 = CC_variablesir(elt(env, 0), 0);
    v_10708 = stack[0];
    if (v_10708 == nil) goto v_10685;
    else goto v_10686;
v_10685:
    goto v_10693;
v_10689:
    v_10708 = stack[0];
    goto v_10690;
v_10691:
    goto v_10692;
v_10693:
    goto v_10689;
v_10690:
    goto v_10691;
v_10692:
        return Lappend(nil, v_10708, v_10707);
v_10686:
    goto v_10703;
v_10699:
    v_10708 = stack[0];
    goto v_10700;
v_10701:
    goto v_10702;
v_10703:
    goto v_10699;
v_10700:
    goto v_10701;
v_10702:
    return cons(v_10708, v_10707);
    goto v_10670;
v_10672:
v_10670:
    v_10707 = nil;
    return onevalue(v_10707);
}



// Code for evmtest!?

static LispObject CC_evmtestW(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10702, v_10703, v_10704, v_10705;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10703 = v_10665;
    v_10704 = v_10664;
// end of prologue
v_10669:
    v_10702 = v_10704;
    if (v_10702 == nil) goto v_10673;
    v_10702 = v_10703;
    if (v_10702 == nil) goto v_10673;
    goto v_10686;
v_10682:
    v_10702 = v_10704;
    v_10705 = qcar(v_10702);
    goto v_10683;
v_10684:
    v_10702 = v_10703;
    v_10702 = qcar(v_10702);
    goto v_10685;
v_10686:
    goto v_10682;
v_10683:
    goto v_10684;
v_10685:
    if (((intptr_t)(v_10705)) < ((intptr_t)(v_10702))) goto v_10681;
    v_10702 = v_10704;
    v_10702 = qcdr(v_10702);
    v_10704 = v_10702;
    v_10702 = v_10703;
    v_10702 = qcdr(v_10702);
    v_10703 = v_10702;
    goto v_10669;
v_10681:
    v_10702 = nil;
    goto v_10668;
    goto v_10671;
v_10673:
    v_10702 = v_10703;
    {
        fn = elt(env, 1); // evzero!?
        return (*qfn1(fn))(fn, v_10702);
    }
v_10671:
    v_10702 = nil;
v_10668:
    return onevalue(v_10702);
}



// Code for xord_deglex

static LispObject CC_xord_deglex(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10728, v_10729, v_10730, v_10731;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10664,v_10665);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10665;
    stack[-1] = v_10664;
// end of prologue
    goto v_10675;
v_10671:
    v_10728 = stack[-1];
    v_10729 = qcar(v_10728);
    goto v_10672;
v_10673:
    v_10728 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10674;
v_10675:
    goto v_10671;
v_10672:
    goto v_10673;
v_10674:
    if (v_10729 == v_10728) goto v_10669;
    else goto v_10670;
v_10669:
    v_10728 = nil;
    goto v_10668;
v_10670:
    goto v_10686;
v_10682:
    v_10728 = stack[0];
    v_10729 = qcar(v_10728);
    goto v_10683;
v_10684:
    v_10728 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10685;
v_10686:
    goto v_10682;
v_10683:
    goto v_10684;
v_10685:
    if (v_10729 == v_10728) goto v_10680;
    else goto v_10681;
v_10680:
    v_10728 = lisp_true;
    goto v_10668;
v_10681:
    v_10728 = stack[-1];
    fn = elt(env, 1); // xdegreemon
    stack[-2] = (*qfn1(fn))(fn, v_10728);
    env = stack[-3];
    v_10728 = stack[0];
    fn = elt(env, 1); // xdegreemon
    v_10728 = (*qfn1(fn))(fn, v_10728);
    env = stack[-3];
    v_10731 = stack[-2];
    v_10730 = v_10728;
    goto v_10707;
v_10703:
    v_10729 = v_10731;
    goto v_10704;
v_10705:
    v_10728 = v_10730;
    goto v_10706;
v_10707:
    goto v_10703;
v_10704:
    goto v_10705;
v_10706:
    if (equal(v_10729, v_10728)) goto v_10701;
    else goto v_10702;
v_10701:
    goto v_10715;
v_10711:
    v_10729 = stack[-1];
    goto v_10712;
v_10713:
    v_10728 = stack[0];
    goto v_10714;
v_10715:
    goto v_10711;
v_10712:
    goto v_10713;
v_10714:
    {
        fn = elt(env, 2); // xord_lex
        return (*qfn2(fn))(fn, v_10729, v_10728);
    }
v_10702:
    goto v_10725;
v_10721:
    v_10728 = v_10731;
    goto v_10722;
v_10723:
    v_10729 = v_10730;
    goto v_10724;
v_10725:
    goto v_10721;
v_10722:
    goto v_10723;
v_10724:
        return Lgreaterp(nil, v_10728, v_10729);
    v_10728 = nil;
    goto v_10668;
    v_10728 = nil;
v_10668:
    return onevalue(v_10728);
}



// Code for invp

static LispObject CC_invp(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10730, v_10731, v_10732;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
// copy arguments values to proper place
    v_10732 = v_10664;
// end of prologue
    goto v_10674;
v_10670:
    v_10731 = v_10732;
    goto v_10671;
v_10672:
    v_10730 = elt(env, 1); // unit
    goto v_10673;
v_10674:
    goto v_10670;
v_10671:
    goto v_10672;
v_10673:
    if (v_10731 == v_10730) goto v_10668;
    else goto v_10669;
v_10668:
    v_10730 = v_10732;
    goto v_10667;
v_10669:
    v_10730 = v_10732;
    if (!consp(v_10730)) goto v_10678;
    else goto v_10679;
v_10678:
    goto v_10686;
v_10682:
    v_10730 = v_10732;
    goto v_10683;
v_10684:
    v_10731 = elt(env, 2); // inverse
    goto v_10685;
v_10686:
    goto v_10682;
v_10683:
    goto v_10684;
v_10685:
    return get(v_10730, v_10731);
v_10679:
    goto v_10695;
v_10691:
    v_10730 = v_10732;
    v_10731 = qcar(v_10730);
    goto v_10692;
v_10693:
    v_10730 = elt(env, 3); // (comm anticomm)
    goto v_10694;
v_10695:
    goto v_10691;
v_10692:
    goto v_10693;
v_10694:
    v_10730 = Lmember(nil, v_10731, v_10730);
    if (v_10730 == nil) goto v_10690;
    goto v_10707;
v_10701:
    v_10731 = elt(env, 4); // quotient
    goto v_10702;
v_10703:
    v_10730 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10704;
v_10705:
    goto v_10706;
v_10707:
    goto v_10701;
v_10702:
    goto v_10703;
v_10704:
    goto v_10705;
v_10706:
    return list3(v_10731, v_10730, v_10732);
v_10690:
    goto v_10718;
v_10714:
    goto v_10724;
v_10720:
    v_10730 = v_10732;
    v_10731 = qcar(v_10730);
    goto v_10721;
v_10722:
    v_10730 = elt(env, 2); // inverse
    goto v_10723;
v_10724:
    goto v_10720;
v_10721:
    goto v_10722;
v_10723:
    v_10730 = get(v_10731, v_10730);
    goto v_10715;
v_10716:
    v_10731 = v_10732;
    v_10731 = qcdr(v_10731);
    goto v_10717;
v_10718:
    goto v_10714;
v_10715:
    goto v_10716;
v_10717:
    return cons(v_10730, v_10731);
    v_10730 = nil;
v_10667:
    return onevalue(v_10730);
}



// Code for contr

static LispObject CC_contr(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10698, v_10699;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10664,v_10665);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10665;
    stack[-1] = v_10664;
// end of prologue
    stack[-2] = nil;
v_10670:
    v_10698 = stack[0];
    if (v_10698 == nil) goto v_10673;
    else goto v_10674;
v_10673:
    v_10698 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_10698);
    }
v_10674:
    goto v_10685;
v_10681:
    goto v_10691;
v_10687:
    v_10699 = stack[-1];
    goto v_10688;
v_10689:
    v_10698 = stack[0];
    v_10698 = qcar(v_10698);
    goto v_10690;
v_10691:
    goto v_10687;
v_10688:
    goto v_10689;
v_10690:
    fn = elt(env, 2); // split!-road
    v_10699 = (*qfn2(fn))(fn, v_10699, v_10698);
    env = stack[-3];
    goto v_10682;
v_10683:
    v_10698 = stack[-2];
    goto v_10684;
v_10685:
    goto v_10681;
v_10682:
    goto v_10683;
v_10684:
    v_10698 = cons(v_10699, v_10698);
    env = stack[-3];
    stack[-2] = v_10698;
    v_10698 = stack[0];
    v_10698 = qcdr(v_10698);
    stack[0] = v_10698;
    goto v_10670;
    v_10698 = nil;
    return onevalue(v_10698);
}



// Code for repasc

static LispObject CC_repasc(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10748, v_10749, v_10750;
    LispObject fn;
    LispObject v_10666, v_10665, v_10664;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "repasc");
    va_start(aa, nargs);
    v_10664 = va_arg(aa, LispObject);
    v_10665 = va_arg(aa, LispObject);
    v_10666 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_10666,v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_10664,v_10665,v_10666);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_10666;
    stack[-1] = v_10665;
    stack[-2] = v_10664;
// end of prologue
    v_10750 = nil;
v_10671:
    v_10748 = stack[0];
    if (v_10748 == nil) goto v_10674;
    else goto v_10675;
v_10674:
    goto v_10682;
v_10678:
    stack[-3] = v_10750;
    goto v_10679;
v_10680:
    goto v_10691;
v_10685:
    stack[-1] = elt(env, 1); // alg
    goto v_10686;
v_10687:
    stack[0] = (LispObject)112+TAG_FIXNUM; // 7
    goto v_10688;
v_10689:
    goto v_10701;
v_10695:
    v_10750 = elt(env, 2); // "key"
    goto v_10696;
v_10697:
    v_10749 = stack[-2];
    goto v_10698;
v_10699:
    v_10748 = elt(env, 3); // "not found"
    goto v_10700;
v_10701:
    goto v_10695;
v_10696:
    goto v_10697;
v_10698:
    goto v_10699;
v_10700:
    v_10748 = list3(v_10750, v_10749, v_10748);
    env = stack[-4];
    goto v_10690;
v_10691:
    goto v_10685;
v_10686:
    goto v_10687;
v_10688:
    goto v_10689;
v_10690:
    fn = elt(env, 4); // rerror
    v_10748 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_10748);
    env = stack[-4];
    goto v_10681;
v_10682:
    goto v_10678;
v_10679:
    goto v_10680;
v_10681:
    {
        LispObject v_10755 = stack[-3];
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(fn, v_10755, v_10748);
    }
v_10675:
    goto v_10711;
v_10707:
    v_10749 = stack[-2];
    goto v_10708;
v_10709:
    v_10748 = stack[0];
    v_10748 = qcar(v_10748);
    v_10748 = qcar(v_10748);
    goto v_10710;
v_10711:
    goto v_10707;
v_10708:
    goto v_10709;
v_10710:
    if (equal(v_10749, v_10748)) goto v_10705;
    else goto v_10706;
v_10705:
    goto v_10721;
v_10717:
    stack[-3] = v_10750;
    goto v_10718;
v_10719:
    goto v_10730;
v_10724:
    v_10750 = stack[-2];
    goto v_10725;
v_10726:
    v_10749 = stack[-1];
    goto v_10727;
v_10728:
    v_10748 = stack[0];
    v_10748 = qcdr(v_10748);
    goto v_10729;
v_10730:
    goto v_10724;
v_10725:
    goto v_10726;
v_10727:
    goto v_10728;
v_10729:
    v_10748 = acons(v_10750, v_10749, v_10748);
    env = stack[-4];
    goto v_10720;
v_10721:
    goto v_10717;
v_10718:
    goto v_10719;
v_10720:
    {
        LispObject v_10756 = stack[-3];
        fn = elt(env, 5); // nreverse
        return (*qfn2(fn))(fn, v_10756, v_10748);
    }
v_10706:
    goto v_10742;
v_10738:
    v_10748 = stack[0];
    v_10748 = qcar(v_10748);
    goto v_10739;
v_10740:
    v_10749 = v_10750;
    goto v_10741;
v_10742:
    goto v_10738;
v_10739:
    goto v_10740;
v_10741:
    v_10748 = cons(v_10748, v_10749);
    env = stack[-4];
    v_10750 = v_10748;
    v_10748 = stack[0];
    v_10748 = qcdr(v_10748);
    stack[0] = v_10748;
    goto v_10671;
    v_10748 = nil;
    return onevalue(v_10748);
}



// Code for addgt

static LispObject CC_addgt(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10696, v_10697;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10664;
// end of prologue
    goto v_10674;
v_10670:
    v_10697 = qvalue(elt(env, 1)); // ordering
    goto v_10671;
v_10672:
    v_10696 = elt(env, 2); // lex
    goto v_10673;
v_10674:
    goto v_10670;
v_10671:
    goto v_10672;
v_10673:
    if (v_10697 == v_10696) goto v_10668;
    else goto v_10669;
v_10668:
    v_10696 = stack[0];
    goto v_10667;
v_10669:
    goto v_10685;
v_10681:
    goto v_10692;
v_10688:
    v_10697 = elt(env, 3); // plus
    goto v_10689;
v_10690:
    v_10696 = stack[0];
    goto v_10691;
v_10692:
    goto v_10688;
v_10689:
    goto v_10690;
v_10691:
    v_10696 = cons(v_10697, v_10696);
    env = stack[-1];
    fn = elt(env, 4); // eval
    v_10697 = (*qfn1(fn))(fn, v_10696);
    goto v_10682;
v_10683:
    v_10696 = stack[0];
    goto v_10684;
v_10685:
    goto v_10681;
v_10682:
    goto v_10683;
v_10684:
    return cons(v_10697, v_10696);
    v_10696 = nil;
v_10667:
    return onevalue(v_10696);
}



// Code for il_simp

static LispObject CC_il_simp(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10674, v_10675;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10674 = v_10664;
// end of prologue
    goto v_10671;
v_10667:
    v_10675 = v_10674;
    goto v_10668;
v_10669:
    v_10674 = nil;
    goto v_10670;
v_10671:
    goto v_10667;
v_10668:
    goto v_10669;
v_10670:
    {
        fn = elt(env, 1); // il_simp1
        return (*qfn2(fn))(fn, v_10675, v_10674);
    }
}



// Code for ordexn

static LispObject CC_ordexn(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10756, v_10757;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10664,v_10665);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_10665;
    stack[-2] = v_10664;
// end of prologue
    stack[0] = nil;
    stack[-3] = nil;
v_10671:
    v_10756 = stack[-1];
    if (v_10756 == nil) goto v_10674;
    else goto v_10675;
v_10674:
    goto v_10682;
v_10678:
    goto v_10679;
v_10680:
    goto v_10690;
v_10686:
    v_10757 = stack[-2];
    goto v_10687;
v_10688:
    v_10756 = stack[-3];
    goto v_10689;
v_10690:
    goto v_10686;
v_10687:
    goto v_10688;
v_10689:
    v_10756 = cons(v_10757, v_10756);
    env = stack[-4];
    v_10756 = Lreverse(nil, v_10756);
    goto v_10681;
v_10682:
    goto v_10678;
v_10679:
    goto v_10680;
v_10681:
    {
        LispObject v_10762 = stack[0];
        return cons(v_10762, v_10756);
    }
v_10675:
    goto v_10699;
v_10695:
    v_10757 = stack[-2];
    goto v_10696;
v_10697:
    v_10756 = stack[-1];
    v_10756 = qcar(v_10756);
    goto v_10698;
v_10699:
    goto v_10695;
v_10696:
    goto v_10697;
v_10698:
    if (v_10757 == v_10756) goto v_10693;
    else goto v_10694;
v_10693:
    v_10756 = nil;
    goto v_10670;
v_10694:
    v_10756 = stack[-2];
    if (v_10756 == nil) goto v_10705;
    goto v_10714;
v_10710:
    v_10757 = stack[-2];
    goto v_10711;
v_10712:
    v_10756 = stack[-1];
    v_10756 = qcar(v_10756);
    goto v_10713;
v_10714:
    goto v_10710;
v_10711:
    goto v_10712;
v_10713:
    fn = elt(env, 1); // ordop
    v_10756 = (*qfn2(fn))(fn, v_10757, v_10756);
    env = stack[-4];
    if (v_10756 == nil) goto v_10705;
    goto v_10723;
v_10719:
    goto v_10720;
v_10721:
    goto v_10730;
v_10726:
    goto v_10737;
v_10733:
    v_10757 = stack[-2];
    goto v_10734;
v_10735:
    v_10756 = stack[-3];
    goto v_10736;
v_10737:
    goto v_10733;
v_10734:
    goto v_10735;
v_10736:
    v_10756 = cons(v_10757, v_10756);
    env = stack[-4];
    v_10757 = Lreverse(nil, v_10756);
    env = stack[-4];
    goto v_10727;
v_10728:
    v_10756 = stack[-1];
    goto v_10729;
v_10730:
    goto v_10726;
v_10727:
    goto v_10728;
v_10729:
    v_10756 = Lappend(nil, v_10757, v_10756);
    goto v_10722;
v_10723:
    goto v_10719;
v_10720:
    goto v_10721;
v_10722:
    {
        LispObject v_10763 = stack[0];
        return cons(v_10763, v_10756);
    }
v_10705:
    goto v_10748;
v_10744:
    v_10756 = stack[-1];
    v_10757 = qcar(v_10756);
    goto v_10745;
v_10746:
    v_10756 = stack[-3];
    goto v_10747;
v_10748:
    goto v_10744;
v_10745:
    goto v_10746;
v_10747:
    v_10756 = cons(v_10757, v_10756);
    env = stack[-4];
    stack[-3] = v_10756;
    v_10756 = stack[-1];
    v_10756 = qcdr(v_10756);
    stack[-1] = v_10756;
    v_10756 = stack[0];
    v_10756 = (v_10756 == nil ? lisp_true : nil);
    stack[0] = v_10756;
    goto v_10673;
v_10673:
    goto v_10671;
v_10670:
    return onevalue(v_10756);
}



// Code for expt!-mod!-p

static LispObject CC_exptKmodKp(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10741, v_10742, v_10743;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10664,v_10665);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_10743 = v_10665;
    stack[0] = v_10664;
// end of prologue
    goto v_10675;
v_10671:
    v_10742 = v_10743;
    goto v_10672;
v_10673:
    v_10741 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10674;
v_10675:
    goto v_10671;
v_10672:
    goto v_10673;
v_10674:
    if (v_10742 == v_10741) goto v_10669;
    else goto v_10670;
v_10669:
    v_10741 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10668;
v_10670:
    goto v_10685;
v_10681:
    v_10742 = v_10743;
    goto v_10682;
v_10683:
    v_10741 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10684;
v_10685:
    goto v_10681;
v_10682:
    goto v_10683;
v_10684:
    if (v_10742 == v_10741) goto v_10679;
    else goto v_10680;
v_10679:
    v_10741 = stack[0];
    goto v_10668;
v_10680:
    goto v_10700;
v_10696:
    v_10742 = v_10743;
    goto v_10697;
v_10698:
    v_10741 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10699;
v_10700:
    goto v_10696;
v_10697:
    goto v_10698;
v_10699:
    v_10741 = Ldivide(nil, v_10742, v_10741);
    env = stack[-2];
    stack[-1] = v_10741;
    goto v_10708;
v_10704:
    v_10742 = stack[0];
    goto v_10705;
v_10706:
    v_10741 = stack[-1];
    v_10741 = qcar(v_10741);
    goto v_10707;
v_10708:
    goto v_10704;
v_10705:
    goto v_10706;
v_10707:
    v_10741 = CC_exptKmodKp(elt(env, 0), v_10742, v_10741);
    env = stack[-2];
    v_10743 = v_10741;
    goto v_10717;
v_10713:
    v_10741 = v_10743;
    goto v_10714;
v_10715:
    v_10742 = v_10743;
    goto v_10716;
v_10717:
    goto v_10713;
v_10714:
    goto v_10715;
v_10716:
    fn = elt(env, 1); // times!-mod!-p
    v_10741 = (*qfn2(fn))(fn, v_10741, v_10742);
    env = stack[-2];
    v_10743 = v_10741;
    goto v_10728;
v_10724:
    v_10741 = stack[-1];
    v_10742 = qcdr(v_10741);
    goto v_10725;
v_10726:
    v_10741 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10727;
v_10728:
    goto v_10724;
v_10725:
    goto v_10726;
v_10727:
    if (v_10742 == v_10741) goto v_10723;
    goto v_10737;
v_10733:
    v_10742 = v_10743;
    goto v_10734;
v_10735:
    v_10741 = stack[0];
    goto v_10736;
v_10737:
    goto v_10733;
v_10734:
    goto v_10735;
v_10736:
    fn = elt(env, 1); // times!-mod!-p
    v_10741 = (*qfn2(fn))(fn, v_10742, v_10741);
    v_10743 = v_10741;
    goto v_10721;
v_10723:
v_10721:
    v_10741 = v_10743;
    goto v_10668;
    v_10741 = nil;
v_10668:
    return onevalue(v_10741);
}



// Code for prin_with_margin

static LispObject CC_prin_with_margin(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10688, v_10689;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_10688 = v_10664;
// end of prologue
    goto v_10675;
v_10667:
    stack[-1] = v_10688;
    goto v_10668;
v_10669:
    stack[0] = Lposn(nil, 0);
    env = stack[-2];
    goto v_10670;
v_10671:
    goto v_10683;
v_10679:
    v_10688 = nil;
    v_10689 = Llinelength(nil, v_10688);
    env = stack[-2];
    goto v_10680;
v_10681:
    v_10688 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10682;
v_10683:
    goto v_10679;
v_10680:
    goto v_10681;
v_10682:
    v_10689 = difference2(v_10689, v_10688);
    env = stack[-2];
    goto v_10672;
v_10673:
    v_10688 = elt(env, 1); // explode
    goto v_10674;
v_10675:
    goto v_10667;
v_10668:
    goto v_10669;
v_10670:
    goto v_10671;
v_10672:
    goto v_10673;
v_10674:
    {
        LispObject v_10692 = stack[-1];
        LispObject v_10693 = stack[0];
        fn = elt(env, 2); // print_with_margin_sub
        return (*qfnn(fn))(fn, 4, v_10692, v_10693, v_10689, v_10688);
    }
}



// Code for gcref_mkgraph

static LispObject CC_gcref_mkgraph(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10677, v_10678;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10678 = v_10664;
// end of prologue
    v_10677 = qvalue(elt(env, 1)); // !*gcrefudg
    if (v_10677 == nil) goto v_10669;
    v_10677 = v_10678;
    {
        fn = elt(env, 2); // gcref_mkgraph!-udg
        return (*qfn1(fn))(fn, v_10677);
    }
v_10669:
    v_10677 = v_10678;
    {
        fn = elt(env, 3); // gcref_mkgraph!-tgf
        return (*qfn1(fn))(fn, v_10677);
    }
    v_10677 = nil;
    return onevalue(v_10677);
}



// Code for talp_rnf1

static LispObject CC_talp_rnf1(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10801, v_10802, v_10803;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_10802 = v_10664;
// end of prologue
    v_10801 = v_10802;
    if (!consp(v_10801)) goto v_10671;
    else goto v_10672;
v_10671:
    v_10801 = v_10802;
    goto v_10668;
v_10672:
    goto v_10682;
v_10676:
    v_10803 = v_10802;
    goto v_10677;
v_10678:
    v_10802 = nil;
    goto v_10679;
v_10680:
    v_10801 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_10681;
v_10682:
    goto v_10676;
v_10677:
    goto v_10678;
v_10679:
    goto v_10680;
v_10681:
    fn = elt(env, 3); // cl_simpl
    v_10801 = (*qfnn(fn))(fn, 3, v_10803, v_10802, v_10801);
    env = stack[-5];
    stack[0] = v_10801;
    goto v_10698;
v_10694:
    v_10802 = stack[0];
    goto v_10695;
v_10696:
    v_10801 = elt(env, 1); // true
    goto v_10697;
v_10698:
    goto v_10694;
v_10695:
    goto v_10696;
v_10697:
    if (v_10802 == v_10801) goto v_10692;
    else goto v_10693;
v_10692:
    v_10801 = lisp_true;
    goto v_10691;
v_10693:
    goto v_10708;
v_10704:
    v_10802 = stack[0];
    goto v_10705;
v_10706:
    v_10801 = elt(env, 2); // false
    goto v_10707;
v_10708:
    goto v_10704;
v_10705:
    goto v_10706;
v_10707:
    v_10801 = (v_10802 == v_10801 ? lisp_true : nil);
    goto v_10691;
    v_10801 = nil;
v_10691:
    if (v_10801 == nil) goto v_10689;
    v_10801 = stack[0];
    goto v_10668;
v_10689:
    v_10801 = stack[0];
    fn = elt(env, 4); // talp_atfp
    v_10801 = (*qfn1(fn))(fn, v_10801);
    env = stack[-5];
    if (v_10801 == nil) goto v_10716;
    v_10801 = stack[0];
    fn = elt(env, 5); // talp_acfrp
    v_10801 = (*qfn1(fn))(fn, v_10801);
    env = stack[-5];
    if (v_10801 == nil) goto v_10722;
    goto v_10732;
v_10726:
    v_10801 = stack[0];
    fn = elt(env, 6); // talp_raf
    v_10803 = (*qfn1(fn))(fn, v_10801);
    env = stack[-5];
    goto v_10727;
v_10728:
    v_10802 = nil;
    goto v_10729;
v_10730:
    v_10801 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_10731;
v_10732:
    goto v_10726;
v_10727:
    goto v_10728;
v_10729:
    goto v_10730;
v_10731:
    {
        fn = elt(env, 3); // cl_simpl
        return (*qfnn(fn))(fn, 3, v_10803, v_10802, v_10801);
    }
v_10722:
    v_10801 = stack[0];
    goto v_10720;
    v_10801 = nil;
v_10720:
    goto v_10668;
v_10716:
    goto v_10747;
v_10741:
    goto v_10753;
v_10749:
    v_10801 = stack[0];
    fn = elt(env, 7); // talp_op
    stack[-4] = (*qfn1(fn))(fn, v_10801);
    env = stack[-5];
    goto v_10750;
v_10751:
    v_10801 = stack[0];
    fn = elt(env, 8); // talp_argl
    v_10801 = (*qfn1(fn))(fn, v_10801);
    env = stack[-5];
    stack[-3] = v_10801;
    v_10801 = stack[-3];
    if (v_10801 == nil) goto v_10766;
    else goto v_10767;
v_10766:
    v_10801 = nil;
    goto v_10760;
v_10767:
    v_10801 = stack[-3];
    v_10801 = qcar(v_10801);
    v_10801 = CC_talp_rnf1(elt(env, 0), v_10801);
    env = stack[-5];
    v_10801 = ncons(v_10801);
    env = stack[-5];
    stack[-1] = v_10801;
    stack[-2] = v_10801;
v_10761:
    v_10801 = stack[-3];
    v_10801 = qcdr(v_10801);
    stack[-3] = v_10801;
    v_10801 = stack[-3];
    if (v_10801 == nil) goto v_10780;
    else goto v_10781;
v_10780:
    v_10801 = stack[-2];
    goto v_10760;
v_10781:
    goto v_10789;
v_10785:
    stack[0] = stack[-1];
    goto v_10786;
v_10787:
    v_10801 = stack[-3];
    v_10801 = qcar(v_10801);
    v_10801 = CC_talp_rnf1(elt(env, 0), v_10801);
    env = stack[-5];
    v_10801 = ncons(v_10801);
    env = stack[-5];
    goto v_10788;
v_10789:
    goto v_10785;
v_10786:
    goto v_10787;
v_10788:
    v_10801 = Lrplacd(nil, stack[0], v_10801);
    env = stack[-5];
    v_10801 = stack[-1];
    v_10801 = qcdr(v_10801);
    stack[-1] = v_10801;
    goto v_10761;
v_10760:
    goto v_10752;
v_10753:
    goto v_10749;
v_10750:
    goto v_10751;
v_10752:
    v_10803 = cons(stack[-4], v_10801);
    env = stack[-5];
    goto v_10742;
v_10743:
    v_10802 = nil;
    goto v_10744;
v_10745:
    v_10801 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_10746;
v_10747:
    goto v_10741;
v_10742:
    goto v_10743;
v_10744:
    goto v_10745;
v_10746:
    {
        fn = elt(env, 3); // cl_simpl
        return (*qfnn(fn))(fn, 3, v_10803, v_10802, v_10801);
    }
v_10668:
    return onevalue(v_10801);
}



// Code for ibalp_renewwl

static LispObject CC_ibalp_renewwl(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10988, v_10989;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_10988 = v_10664;
// end of prologue
    stack[-2] = v_10988;
v_10672:
    v_10988 = stack[-2];
    if (v_10988 == nil) goto v_10676;
    else goto v_10677;
v_10676:
    goto v_10671;
v_10677:
    v_10988 = stack[-2];
    v_10988 = qcar(v_10988);
    stack[-1] = v_10988;
    v_10988 = stack[-1];
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcar(v_10988);
    if (v_10988 == nil) goto v_10685;
    else goto v_10686;
v_10685:
    goto v_10703;
v_10699:
    v_10988 = stack[-1];
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcar(v_10988);
    v_10989 = Llength(nil, v_10988);
    env = stack[-4];
    goto v_10700;
v_10701:
    v_10988 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10702;
v_10703:
    goto v_10699;
v_10700:
    goto v_10701;
v_10702:
    v_10988 = Leqn(nil, v_10989, v_10988);
    env = stack[-4];
    if (v_10988 == nil) goto v_10696;
    goto v_10720;
v_10716:
    goto v_10726;
v_10722:
    v_10988 = stack[-1];
    v_10988 = qcar(v_10988);
    stack[0] = Llength(nil, v_10988);
    env = stack[-4];
    goto v_10723;
v_10724:
    v_10988 = stack[-1];
    v_10988 = qcdr(v_10988);
    v_10988 = qcar(v_10988);
    v_10988 = Llength(nil, v_10988);
    env = stack[-4];
    goto v_10725;
v_10726:
    goto v_10722;
v_10723:
    goto v_10724;
v_10725:
    v_10989 = plus2(stack[0], v_10988);
    env = stack[-4];
    goto v_10717;
v_10718:
    v_10988 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10719;
v_10720:
    goto v_10716;
v_10717:
    goto v_10718;
v_10719:
    v_10988 = (LispObject)greaterp2(v_10989, v_10988);
    v_10988 = v_10988 ? lisp_true : nil;
    env = stack[-4];
    if (v_10988 == nil) goto v_10696;
    v_10988 = stack[-1];
    fn = elt(env, 1); // ibalp_getnewwl
    v_10988 = (*qfn1(fn))(fn, v_10988);
    env = stack[-4];
    stack[-3] = v_10988;
    v_10988 = stack[-3];
    if (v_10988 == nil) goto v_10740;
    goto v_10747;
v_10743:
    v_10988 = stack[-1];
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    stack[0] = qcdr(v_10988);
    goto v_10744;
v_10745:
    goto v_10760;
v_10756:
    v_10989 = stack[-3];
    goto v_10757;
v_10758:
    v_10988 = stack[-1];
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcar(v_10988);
    goto v_10759;
v_10760:
    goto v_10756;
v_10757:
    goto v_10758;
v_10759:
    v_10988 = cons(v_10989, v_10988);
    env = stack[-4];
    goto v_10746;
v_10747:
    goto v_10743;
v_10744:
    goto v_10745;
v_10746:
    fn = elt(env, 2); // setcar
    v_10988 = (*qfn2(fn))(fn, stack[0], v_10988);
    env = stack[-4];
    goto v_10775;
v_10771:
    v_10988 = stack[-3];
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    stack[0] = qcdr(v_10988);
    goto v_10772;
v_10773:
    goto v_10792;
v_10788:
    v_10989 = stack[-1];
    goto v_10789;
v_10790:
    v_10988 = stack[-3];
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcar(v_10988);
    goto v_10791;
v_10792:
    goto v_10788;
v_10789:
    goto v_10790;
v_10791:
    v_10988 = cons(v_10989, v_10988);
    env = stack[-4];
    goto v_10774;
v_10775:
    goto v_10771;
v_10772:
    goto v_10773;
v_10774:
    fn = elt(env, 2); // setcar
    v_10988 = (*qfn2(fn))(fn, stack[0], v_10988);
    env = stack[-4];
    goto v_10738;
v_10740:
v_10738:
    goto v_10694;
v_10696:
    v_10988 = stack[-1];
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcar(v_10988);
    if (v_10988 == nil) goto v_10811;
    else goto v_10812;
v_10811:
    goto v_10826;
v_10822:
    goto v_10832;
v_10828:
    v_10988 = stack[-1];
    v_10988 = qcar(v_10988);
    stack[0] = Llength(nil, v_10988);
    env = stack[-4];
    goto v_10829;
v_10830:
    v_10988 = stack[-1];
    v_10988 = qcdr(v_10988);
    v_10988 = qcar(v_10988);
    v_10988 = Llength(nil, v_10988);
    env = stack[-4];
    goto v_10831;
v_10832:
    goto v_10828;
v_10829:
    goto v_10830;
v_10831:
    v_10989 = plus2(stack[0], v_10988);
    env = stack[-4];
    goto v_10823;
v_10824:
    v_10988 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10825;
v_10826:
    goto v_10822;
v_10823:
    goto v_10824;
v_10825:
    v_10988 = (LispObject)greaterp2(v_10989, v_10988);
    v_10988 = v_10988 ? lisp_true : nil;
    env = stack[-4];
    goto v_10810;
v_10812:
    v_10988 = nil;
    goto v_10810;
    v_10988 = nil;
v_10810:
    if (v_10988 == nil) goto v_10808;
    v_10988 = stack[-1];
    fn = elt(env, 1); // ibalp_getnewwl
    v_10988 = (*qfn1(fn))(fn, v_10988);
    env = stack[-4];
    stack[-3] = v_10988;
    v_10988 = stack[-3];
    if (v_10988 == nil) goto v_10849;
    goto v_10856;
v_10852:
    v_10988 = stack[-1];
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    stack[0] = qcdr(v_10988);
    goto v_10853;
v_10854:
    goto v_10869;
v_10865:
    v_10989 = stack[-3];
    goto v_10866;
v_10867:
    v_10988 = stack[-1];
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcar(v_10988);
    goto v_10868;
v_10869:
    goto v_10865;
v_10866:
    goto v_10867;
v_10868:
    v_10988 = cons(v_10989, v_10988);
    env = stack[-4];
    goto v_10855;
v_10856:
    goto v_10852;
v_10853:
    goto v_10854;
v_10855:
    fn = elt(env, 2); // setcar
    v_10988 = (*qfn2(fn))(fn, stack[0], v_10988);
    env = stack[-4];
    goto v_10884;
v_10880:
    v_10988 = stack[-3];
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    stack[0] = qcdr(v_10988);
    goto v_10881;
v_10882:
    goto v_10901;
v_10897:
    v_10989 = stack[-1];
    goto v_10898;
v_10899:
    v_10988 = stack[-3];
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcar(v_10988);
    goto v_10900;
v_10901:
    goto v_10897;
v_10898:
    goto v_10899;
v_10900:
    v_10988 = cons(v_10989, v_10988);
    env = stack[-4];
    goto v_10883;
v_10884:
    goto v_10880;
v_10881:
    goto v_10882;
v_10883:
    fn = elt(env, 2); // setcar
    v_10988 = (*qfn2(fn))(fn, stack[0], v_10988);
    env = stack[-4];
    goto v_10847;
v_10849:
v_10847:
    v_10988 = stack[-1];
    fn = elt(env, 1); // ibalp_getnewwl
    v_10988 = (*qfn1(fn))(fn, v_10988);
    env = stack[-4];
    stack[-3] = v_10988;
    v_10988 = stack[-3];
    if (v_10988 == nil) goto v_10920;
    goto v_10927;
v_10923:
    v_10988 = stack[-1];
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    stack[0] = qcdr(v_10988);
    goto v_10924;
v_10925:
    goto v_10940;
v_10936:
    v_10989 = stack[-3];
    goto v_10937;
v_10938:
    v_10988 = stack[-1];
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcar(v_10988);
    goto v_10939;
v_10940:
    goto v_10936;
v_10937:
    goto v_10938;
v_10939:
    v_10988 = cons(v_10989, v_10988);
    env = stack[-4];
    goto v_10926;
v_10927:
    goto v_10923;
v_10924:
    goto v_10925;
v_10926:
    fn = elt(env, 2); // setcar
    v_10988 = (*qfn2(fn))(fn, stack[0], v_10988);
    env = stack[-4];
    goto v_10955;
v_10951:
    v_10988 = stack[-3];
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    stack[0] = qcdr(v_10988);
    goto v_10952;
v_10953:
    goto v_10972;
v_10968:
    v_10989 = stack[-1];
    goto v_10969;
v_10970:
    v_10988 = stack[-3];
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcdr(v_10988);
    v_10988 = qcar(v_10988);
    goto v_10971;
v_10972:
    goto v_10968;
v_10969:
    goto v_10970;
v_10971:
    v_10988 = cons(v_10989, v_10988);
    env = stack[-4];
    goto v_10954;
v_10955:
    goto v_10951;
v_10952:
    goto v_10953;
v_10954:
    fn = elt(env, 2); // setcar
    v_10988 = (*qfn2(fn))(fn, stack[0], v_10988);
    env = stack[-4];
    goto v_10918;
v_10920:
v_10918:
    goto v_10694;
v_10808:
v_10694:
    goto v_10684;
v_10686:
v_10684:
    v_10988 = stack[-2];
    v_10988 = qcdr(v_10988);
    stack[-2] = v_10988;
    goto v_10672;
v_10671:
    v_10988 = nil;
    return onevalue(v_10988);
}



// Code for binomial!-coefft!-mod!-p

static LispObject CC_binomialKcoefftKmodKp(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10783, v_10784, v_10785, v_10786, v_10787;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10664,v_10665);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_10665;
    stack[-2] = v_10664;
// end of prologue
    goto v_10676;
v_10672:
    v_10784 = stack[-2];
    goto v_10673;
v_10674:
    v_10783 = stack[-1];
    goto v_10675;
v_10676:
    goto v_10672;
v_10673:
    goto v_10674;
v_10675:
    v_10783 = (LispObject)lessp2(v_10784, v_10783);
    v_10783 = v_10783 ? lisp_true : nil;
    env = stack[-4];
    if (v_10783 == nil) goto v_10670;
    v_10783 = nil;
    goto v_10668;
v_10670:
    goto v_10686;
v_10682:
    v_10784 = stack[-2];
    goto v_10683;
v_10684:
    v_10783 = stack[-1];
    goto v_10685;
v_10686:
    goto v_10682;
v_10683:
    goto v_10684;
v_10685:
    if (equal(v_10784, v_10783)) goto v_10680;
    else goto v_10681;
v_10680:
    v_10783 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10668;
v_10681:
    goto v_10696;
v_10692:
    v_10784 = stack[-1];
    goto v_10693;
v_10694:
    v_10783 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10695;
v_10696:
    goto v_10692;
v_10693:
    goto v_10694;
v_10695:
    if (v_10784 == v_10783) goto v_10690;
    else goto v_10691;
v_10690:
    v_10783 = stack[-2];
    v_10783 = Lmodular_number(nil, v_10783);
    env = stack[-4];
    {
        fn = elt(env, 1); // !*n2f
        return (*qfn1(fn))(fn, v_10783);
    }
v_10691:
    v_10783 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_10783;
    goto v_10715;
v_10711:
    stack[0] = stack[-1];
    goto v_10712;
v_10713:
    goto v_10722;
v_10718:
    v_10784 = stack[-2];
    goto v_10719;
v_10720:
    v_10783 = stack[-1];
    goto v_10721;
v_10722:
    goto v_10718;
v_10719:
    goto v_10720;
v_10721:
    v_10783 = difference2(v_10784, v_10783);
    env = stack[-4];
    goto v_10714;
v_10715:
    goto v_10711;
v_10712:
    goto v_10713;
v_10714:
    fn = elt(env, 2); // min
    v_10783 = (*qfn2(fn))(fn, stack[0], v_10783);
    env = stack[-4];
    stack[0] = v_10783;
    v_10783 = stack[-2];
    v_10783 = Lmodular_number(nil, v_10783);
    env = stack[-4];
    stack[-2] = v_10783;
    v_10783 = stack[-1];
    v_10783 = Lmodular_number(nil, v_10783);
    env = stack[-4];
    v_10783 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_10783;
v_10732:
    goto v_10744;
v_10740:
    v_10784 = stack[0];
    goto v_10741;
v_10742:
    v_10783 = stack[-1];
    goto v_10743;
v_10744:
    goto v_10740;
v_10741:
    goto v_10742;
v_10743:
    v_10783 = difference2(v_10784, v_10783);
    env = stack[-4];
    v_10783 = Lminusp(nil, v_10783);
    env = stack[-4];
    if (v_10783 == nil) goto v_10737;
    goto v_10731;
v_10737:
    v_10783 = stack[-1];
    v_10783 = Lmodular_number(nil, v_10783);
    env = stack[-4];
    v_10787 = v_10783;
    goto v_10755;
v_10751:
    goto v_10761;
v_10757:
    v_10786 = stack[-3];
    goto v_10758;
v_10759:
    goto v_10767;
v_10763:
    v_10785 = stack[-2];
    goto v_10764;
v_10765:
    goto v_10773;
v_10769:
    v_10784 = v_10787;
    goto v_10770;
v_10771:
    v_10783 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10772;
v_10773:
    goto v_10769;
v_10770:
    goto v_10771;
v_10772:
    {   intptr_t w = int_of_fixnum(v_10784) - int_of_fixnum(v_10783);
        if (w < 0) w += current_modulus;
        v_10783 = fixnum_of_int(w);
    }
    goto v_10766;
v_10767:
    goto v_10763;
v_10764:
    goto v_10765;
v_10766:
    {   intptr_t w = int_of_fixnum(v_10785) - int_of_fixnum(v_10783);
        if (w < 0) w += current_modulus;
        v_10783 = fixnum_of_int(w);
    }
    goto v_10760;
v_10761:
    goto v_10757;
v_10758:
    goto v_10759;
v_10760:
    v_10783 = Lmodular_times(nil, v_10786, v_10783);
    env = stack[-4];
    goto v_10752;
v_10753:
    v_10784 = v_10787;
    goto v_10754;
v_10755:
    goto v_10751;
v_10752:
    goto v_10753;
v_10754:
    v_10783 = Lmodular_quotient(nil, v_10783, v_10784);
    env = stack[-4];
    stack[-3] = v_10783;
    v_10783 = stack[-1];
    v_10783 = add1(v_10783);
    env = stack[-4];
    stack[-1] = v_10783;
    goto v_10732;
v_10731:
    v_10783 = stack[-3];
    {
        fn = elt(env, 1); // !*n2f
        return (*qfn1(fn))(fn, v_10783);
    }
    goto v_10668;
    v_10783 = nil;
v_10668:
    return onevalue(v_10783);
}



// Code for ir2om

static LispObject CC_ir2om(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10680;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10664;
// end of prologue
    v_10680 = (LispObject)32+TAG_FIXNUM; // 2
    qvalue(elt(env, 1)) = v_10680; // ind
    v_10680 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 2)) = v_10680; // indent
    v_10680 = elt(env, 3); // "<OMOBJ>"
    fn = elt(env, 5); // printout
    v_10680 = (*qfn1(fn))(fn, v_10680);
    env = stack[-1];
    v_10680 = lisp_true;
    fn = elt(env, 6); // indent!*
    v_10680 = (*qfn1(fn))(fn, v_10680);
    env = stack[-1];
    v_10680 = stack[0];
    fn = elt(env, 7); // objectom
    v_10680 = (*qfn1(fn))(fn, v_10680);
    env = stack[-1];
    v_10680 = nil;
    fn = elt(env, 6); // indent!*
    v_10680 = (*qfn1(fn))(fn, v_10680);
    env = stack[-1];
    v_10680 = elt(env, 4); // "</OMOBJ>"
    fn = elt(env, 5); // printout
    v_10680 = (*qfn1(fn))(fn, v_10680);
    v_10680 = nil;
    return onevalue(v_10680);
}



// Code for groebcplistsortin

static LispObject CC_groebcplistsortin(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10685, v_10686;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10664,v_10665);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_10665;
    v_10686 = v_10664;
// end of prologue
    v_10685 = stack[0];
    if (v_10685 == nil) goto v_10669;
    else goto v_10670;
v_10669:
    v_10685 = v_10686;
    return ncons(v_10685);
v_10670:
    goto v_10681;
v_10677:
    goto v_10678;
v_10679:
    v_10685 = stack[0];
    goto v_10680;
v_10681:
    goto v_10677;
v_10678:
    goto v_10679;
v_10680:
    fn = elt(env, 1); // groebcplistsortin1
    v_10685 = (*qfn2(fn))(fn, v_10686, v_10685);
    v_10685 = stack[0];
    goto v_10668;
    v_10685 = nil;
v_10668:
    return onevalue(v_10685);
}



// Code for mo_times_ei

static LispObject CC_mo_times_ei(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10706, v_10707, v_10708;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10664,v_10665);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10708 = v_10665;
    v_10707 = v_10664;
// end of prologue
    v_10706 = v_10708;
    v_10706 = qcar(v_10706);
    if (v_10706 == nil) goto v_10669;
    else goto v_10670;
v_10669:
    v_10706 = v_10707;
    v_10706 = ncons(v_10706);
    env = stack[-1];
    goto v_10668;
v_10670:
    goto v_10682;
v_10678:
    goto v_10687;
v_10683:
    goto v_10684;
v_10685:
    v_10706 = v_10708;
    v_10706 = qcar(v_10706);
    v_10706 = qcar(v_10706);
    goto v_10686;
v_10687:
    goto v_10683;
v_10684:
    goto v_10685;
v_10686:
    v_10706 = (LispObject)(intptr_t)((intptr_t)v_10707 + (intptr_t)v_10706 - TAG_FIXNUM);
    goto v_10679;
v_10680:
    v_10707 = v_10708;
    v_10707 = qcar(v_10707);
    v_10707 = qcdr(v_10707);
    goto v_10681;
v_10682:
    goto v_10678;
v_10679:
    goto v_10680;
v_10681:
    v_10706 = cons(v_10706, v_10707);
    env = stack[-1];
    goto v_10668;
    v_10706 = nil;
v_10668:
    goto v_10702;
v_10698:
    stack[0] = v_10706;
    goto v_10699;
v_10700:
    fn = elt(env, 1); // mo!=deglist
    v_10706 = (*qfn1(fn))(fn, v_10706);
    goto v_10701;
v_10702:
    goto v_10698;
v_10699:
    goto v_10700;
v_10701:
    {
        LispObject v_10710 = stack[0];
        return cons(v_10710, v_10706);
    }
}



// Code for th_match

static LispObject CC_th_match(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10698, v_10699;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10664,v_10665);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10665;
    stack[-1] = v_10664;
// end of prologue
    goto v_10676;
v_10672:
    v_10699 = stack[-1];
    goto v_10673;
v_10674:
    v_10698 = stack[0];
    goto v_10675;
v_10676:
    goto v_10672;
v_10673:
    goto v_10674;
v_10675:
    fn = elt(env, 1); // th_match0
    v_10698 = (*qfn2(fn))(fn, v_10699, v_10698);
    env = stack[-2];
    if (v_10698 == nil) goto v_10669;
    else goto v_10670;
v_10669:
    v_10698 = nil;
    goto v_10668;
v_10670:
    goto v_10686;
v_10682:
    v_10698 = stack[-1];
    v_10698 = qcdr(v_10698);
    v_10698 = qcar(v_10698);
    fn = elt(env, 2); // dl_get
    v_10698 = (*qfn1(fn))(fn, v_10698);
    env = stack[-2];
    stack[-1] = Llength(nil, v_10698);
    env = stack[-2];
    goto v_10683;
v_10684:
    v_10698 = stack[0];
    v_10698 = qcdr(v_10698);
    v_10698 = qcar(v_10698);
    fn = elt(env, 2); // dl_get
    v_10698 = (*qfn1(fn))(fn, v_10698);
    env = stack[-2];
    v_10698 = Llength(nil, v_10698);
    goto v_10685;
v_10686:
    goto v_10682;
v_10683:
    goto v_10684;
v_10685:
    v_10698 = (equal(stack[-1], v_10698) ? lisp_true : nil);
    goto v_10668;
    v_10698 = nil;
v_10668:
    return onevalue(v_10698);
}



// Code for arplus!:

static LispObject CC_arplusT(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10689, v_10690, v_10691;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10664,v_10665);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_10690 = v_10665;
    v_10691 = v_10664;
// end of prologue
// Binding dmode!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = nil; // dmode!*
// Binding !*exp
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-3, 2, -1);
    qvalue(elt(env, 2)) = nil; // !*exp
    v_10689 = lisp_true;
    qvalue(elt(env, 2)) = v_10689; // !*exp
    goto v_10677;
v_10673:
    stack[0] = elt(env, 3); // !:ar!:
    goto v_10674;
v_10675:
    goto v_10684;
v_10680:
    v_10689 = v_10691;
    v_10689 = qcdr(v_10689);
    goto v_10681;
v_10682:
    v_10690 = qcdr(v_10690);
    goto v_10683;
v_10684:
    goto v_10680;
v_10681:
    goto v_10682;
v_10683:
    fn = elt(env, 4); // addf
    v_10689 = (*qfn2(fn))(fn, v_10689, v_10690);
    env = stack[-3];
    goto v_10676;
v_10677:
    goto v_10673;
v_10674:
    goto v_10675;
v_10676:
    v_10689 = cons(stack[0], v_10689);
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_10689);
}



// Code for subf1

static LispObject CC_subf1(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_11412, v_11413, v_11414;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10664,v_10665);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(15);
// copy arguments values to proper place
    stack[-11] = v_10665;
    stack[-12] = v_10664;
// end of prologue
    v_11412 = stack[-12];
    if (v_11412 == nil) goto v_10669;
    else goto v_10670;
v_10669:
    goto v_10677;
v_10673:
    v_11413 = nil;
    goto v_10674;
v_10675:
    v_11412 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10676;
v_10677:
    goto v_10673;
v_10674:
    goto v_10675;
v_10676:
    return cons(v_11413, v_11412);
v_10670:
    v_11412 = stack[-12];
    if (!consp(v_11412)) goto v_10684;
    else goto v_10685;
v_10684:
    v_11412 = lisp_true;
    goto v_10683;
v_10685:
    v_11412 = stack[-12];
    v_11412 = qcar(v_11412);
    v_11412 = (consp(v_11412) ? nil : lisp_true);
    goto v_10683;
    v_11412 = nil;
v_10683:
    if (v_11412 == nil) goto v_10681;
    v_11412 = stack[-12];
    if (!consp(v_11412)) goto v_10695;
    else goto v_10696;
v_10695:
    v_11412 = qvalue(elt(env, 1)); // dmode!*
    if (v_11412 == nil) goto v_10700;
    else goto v_10701;
v_10700:
    goto v_10708;
v_10704:
    v_11413 = stack[-12];
    goto v_10705;
v_10706:
    v_11412 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10707;
v_10708:
    goto v_10704;
v_10705:
    goto v_10706;
v_10707:
    return cons(v_11413, v_11412);
v_10701:
    v_11412 = stack[-12];
    {
        fn = elt(env, 11); // simpatom
        return (*qfn1(fn))(fn, v_11412);
    }
    v_11412 = nil;
    goto v_10694;
v_10696:
    goto v_10725;
v_10721:
    v_11413 = qvalue(elt(env, 1)); // dmode!*
    goto v_10722;
v_10723:
    v_11412 = stack[-12];
    v_11412 = qcar(v_11412);
    goto v_10724;
v_10725:
    goto v_10721;
v_10722:
    goto v_10723;
v_10724:
    if (v_11413 == v_11412) goto v_10719;
    else goto v_10720;
v_10719:
    goto v_10734;
v_10730:
    v_11413 = qvalue(elt(env, 1)); // dmode!*
    goto v_10731;
v_10732:
    v_11412 = elt(env, 2); // resimplify
    goto v_10733;
v_10734:
    goto v_10730;
v_10731:
    goto v_10732;
v_10733:
    v_11412 = Lflagp(nil, v_11413, v_11412);
    env = stack[-14];
    v_11412 = (v_11412 == nil ? lisp_true : nil);
    goto v_10718;
v_10720:
    v_11412 = nil;
    goto v_10718;
    v_11412 = nil;
v_10718:
    if (v_11412 == nil) goto v_10716;
    v_11412 = stack[-12];
    {
        fn = elt(env, 12); // !*d2q
        return (*qfn1(fn))(fn, v_11412);
    }
v_10716:
    v_11412 = stack[-12];
    fn = elt(env, 13); // prepf
    v_11412 = (*qfn1(fn))(fn, v_11412);
    env = stack[-14];
    {
        fn = elt(env, 14); // simp
        return (*qfn1(fn))(fn, v_11412);
    }
    v_11412 = nil;
v_10694:
    goto v_10668;
v_10681:
// Binding varstack!*
// FLUIDBIND: reloadenv=14 litvec-offset=3 saveloc=9
{   bind_fluid_stack bind_fluid_var(-14, 3, -9);
    qvalue(elt(env, 3)) = nil; // varstack!*
    stack[-5] = nil;
    stack[-4] = nil;
    v_11412 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-13] = v_11412;
    goto v_10780;
v_10776:
    v_11413 = nil;
    goto v_10777;
v_10778:
    v_11412 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10779;
v_10780:
    goto v_10776;
v_10777:
    goto v_10778;
v_10779:
    v_11412 = cons(v_11413, v_11412);
    env = stack[-14];
    stack[-3] = v_11412;
v_10765:
    v_11412 = stack[-12];
    v_11412 = qcar(v_11412);
    v_11412 = qcar(v_11412);
    v_11412 = qcar(v_11412);
    stack[-2] = v_11412;
    v_11412 = nil;
    stack[0] = v_11412;
    goto v_10797;
v_10793:
    v_11413 = stack[-2];
    goto v_10794;
v_10795:
    v_11412 = stack[-11];
    goto v_10796;
v_10797:
    goto v_10793;
v_10794:
    goto v_10795;
v_10796:
    v_11412 = Lassoc(nil, v_11413, v_11412);
    if (v_11412 == nil) goto v_10791;
    goto v_10806;
v_10802:
    v_11413 = stack[-2];
    goto v_10803;
v_10804:
    v_11412 = qvalue(elt(env, 4)); // wtl!*
    goto v_10805;
v_10806:
    goto v_10802;
v_10803:
    goto v_10804;
v_10805:
    v_11412 = Lassoc(nil, v_11413, v_11412);
    stack[0] = v_11412;
    if (v_11412 == nil) goto v_10791;
    v_11412 = stack[0];
    v_11412 = qcdr(v_11412);
    stack[0] = v_11412;
    goto v_10789;
v_10791:
v_10789:
    goto v_10820;
v_10816:
    v_11413 = stack[-2];
    goto v_10817;
v_10818:
    v_11412 = qvalue(elt(env, 5)); // asymplis!*
    goto v_10819;
v_10820:
    goto v_10816;
v_10817:
    goto v_10818;
v_10819:
    v_11412 = Lassoc(nil, v_11413, v_11412);
    stack[-10] = v_11412;
    if (v_11412 == nil) goto v_10815;
    v_11412 = stack[-10];
    v_11412 = qcdr(v_11412);
    stack[-10] = v_11412;
    goto v_10813;
v_10815:
v_10813:
v_10766:
    v_11412 = stack[-12];
    if (v_11412 == nil) goto v_10832;
    else goto v_10833;
v_10832:
    v_11412 = lisp_true;
    goto v_10831;
v_10833:
    goto v_10842;
v_10838:
    goto v_10848;
v_10844:
    v_11413 = stack[-12];
    goto v_10845;
v_10846:
    v_11412 = stack[-2];
    goto v_10847;
v_10848:
    goto v_10844;
v_10845:
    goto v_10846;
v_10847:
    fn = elt(env, 15); // degr
    v_11413 = (*qfn2(fn))(fn, v_11413, v_11412);
    env = stack[-14];
    stack[-13] = v_11413;
    goto v_10839;
v_10840:
    v_11412 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10841;
v_10842:
    goto v_10838;
v_10839:
    goto v_10840;
v_10841:
    v_11412 = (v_11413 == v_11412 ? lisp_true : nil);
    goto v_10831;
    v_11412 = nil;
v_10831:
    if (v_11412 == nil) goto v_10829;
    goto v_10767;
v_10829:
    v_11412 = stack[-10];
    if (v_11412 == nil) goto v_10857;
    else goto v_10858;
v_10857:
    v_11412 = lisp_true;
    goto v_10856;
v_10858:
    goto v_10868;
v_10864:
    v_11413 = stack[-13];
    goto v_10865;
v_10866:
    v_11412 = stack[-10];
    goto v_10867;
v_10868:
    goto v_10864;
v_10865:
    goto v_10866;
v_10867:
    v_11412 = (LispObject)lessp2(v_11413, v_11412);
    v_11412 = v_11412 ? lisp_true : nil;
    env = stack[-14];
    goto v_10856;
    v_11412 = nil;
v_10856:
    if (v_11412 == nil) goto v_10854;
    goto v_10876;
v_10872:
    goto v_10882;
v_10878:
    v_11412 = stack[-12];
    v_11413 = qcar(v_11412);
    goto v_10879;
v_10880:
    v_11412 = stack[0];
    goto v_10881;
v_10882:
    goto v_10878;
v_10879:
    goto v_10880;
v_10881:
    fn = elt(env, 16); // wtchk
    v_11413 = (*qfn2(fn))(fn, v_11413, v_11412);
    env = stack[-14];
    goto v_10873;
v_10874:
    v_11412 = stack[-5];
    goto v_10875;
v_10876:
    goto v_10872;
v_10873:
    goto v_10874;
v_10875:
    v_11412 = cons(v_11413, v_11412);
    env = stack[-14];
    stack[-5] = v_11412;
    goto v_10827;
v_10854:
v_10827:
    v_11412 = stack[-12];
    v_11412 = qcdr(v_11412);
    stack[-12] = v_11412;
    goto v_10766;
v_10767:
    v_11412 = nil;
    v_11414 = v_11412;
v_10892:
    v_11412 = stack[-11];
    if (v_11412 == nil) goto v_10895;
    else goto v_10896;
v_10895:
    goto v_10891;
v_10896:
    goto v_10907;
v_10903:
    v_11412 = stack[-11];
    v_11412 = qcar(v_11412);
    v_11413 = qcar(v_11412);
    goto v_10904;
v_10905:
    v_11412 = stack[-11];
    v_11412 = qcar(v_11412);
    v_11412 = qcdr(v_11412);
    goto v_10906;
v_10907:
    goto v_10903;
v_10904:
    goto v_10905;
v_10906:
    if (equal(v_11413, v_11412)) goto v_10902;
    goto v_10919;
v_10915:
    v_11412 = stack[-11];
    v_11412 = qcar(v_11412);
    goto v_10916;
v_10917:
    v_11413 = v_11414;
    goto v_10918;
v_10919:
    goto v_10915;
v_10916:
    goto v_10917;
v_10918:
    v_11412 = cons(v_11412, v_11413);
    env = stack[-14];
    v_11414 = v_11412;
    goto v_10900;
v_10902:
v_10900:
    v_11412 = stack[-11];
    v_11412 = qcdr(v_11412);
    stack[-11] = v_11412;
    goto v_10892;
v_10891:
    v_11412 = v_11414;
    v_11412 = Lnreverse(nil, v_11412);
    env = stack[-14];
    stack[-11] = v_11412;
    v_11412 = stack[-2];
    if (!consp(v_11412)) goto v_10934;
    v_11412 = stack[-2];
    v_11412 = qcar(v_11412);
    v_11412 = (consp(v_11412) ? nil : lisp_true);
    v_11412 = (v_11412 == nil ? lisp_true : nil);
    goto v_10932;
v_10934:
    v_11412 = nil;
    goto v_10932;
    v_11412 = nil;
v_10932:
    if (v_11412 == nil) goto v_10930;
    v_11412 = stack[-2];
    fn = elt(env, 13); // prepf
    v_11412 = (*qfn1(fn))(fn, v_11412);
    env = stack[-14];
    stack[-2] = v_11412;
    goto v_10928;
v_10930:
v_10928:
    v_11412 = stack[-11];
    if (v_11412 == nil) goto v_10947;
    else goto v_10948;
v_10947:
    goto v_10958;
v_10954:
    v_11413 = stack[-2];
    goto v_10955;
v_10956:
    v_11412 = elt(env, 6); // k!*
    goto v_10957;
v_10958:
    goto v_10954;
v_10955:
    goto v_10956;
v_10957:
    if (v_11413 == v_11412) goto v_10952;
    else goto v_10953;
v_10952:
    v_11412 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10951;
v_10953:
    v_11412 = stack[-2];
    goto v_10951;
    v_11412 = nil;
v_10951:
    stack[-1] = v_11412;
    goto v_10946;
v_10948:
    goto v_10975;
v_10971:
    goto v_10981;
v_10977:
    v_11413 = stack[-11];
    goto v_10978;
v_10979:
    v_11412 = stack[-2];
    goto v_10980;
v_10981:
    goto v_10977;
v_10978:
    goto v_10979;
v_10980:
    fn = elt(env, 17); // subsublis
    v_11413 = (*qfn2(fn))(fn, v_11413, v_11412);
    env = stack[-14];
    stack[-1] = v_11413;
    goto v_10972;
v_10973:
    v_11412 = stack[-2];
    goto v_10974;
v_10975:
    goto v_10971;
v_10972:
    goto v_10973;
v_10974:
    if (equal(v_11413, v_11412)) goto v_10969;
    else goto v_10970;
v_10969:
    goto v_10989;
v_10985:
    v_11413 = stack[-2];
    goto v_10986;
v_10987:
    v_11412 = qvalue(elt(env, 5)); // asymplis!*
    goto v_10988;
v_10989:
    goto v_10985;
v_10986:
    goto v_10987;
v_10988:
    v_11412 = Lassoc(nil, v_11413, v_11412);
    v_11412 = (v_11412 == nil ? lisp_true : nil);
    goto v_10968;
v_10970:
    v_11412 = nil;
    goto v_10968;
    v_11412 = nil;
v_10968:
    if (v_11412 == nil) goto v_10966;
    goto v_10770;
v_10966:
v_10946:
v_10768:
    goto v_11002;
v_10998:
    v_11413 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10999;
v_11000:
    v_11412 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11001;
v_11002:
    goto v_10998;
v_10999:
    goto v_11000;
v_11001:
    v_11412 = cons(v_11413, v_11412);
    env = stack[-14];
    stack[-8] = v_11412;
    v_11412 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-13] = v_11412;
    v_11412 = stack[-5];
    if (v_11412 == nil) goto v_11009;
    v_11412 = stack[-5];
    v_11412 = qcar(v_11412);
    v_11412 = qcar(v_11412);
    v_11412 = qcdr(v_11412);
    v_11412 = Lminusp(nil, v_11412);
    env = stack[-14];
    if (v_11412 == nil) goto v_11009;
    goto v_10771;
v_11009:
    goto v_11026;
v_11022:
    v_11412 = stack[-1];
    fn = elt(env, 18); // getrtype
    v_11413 = (*qfn1(fn))(fn, v_11412);
    env = stack[-14];
    stack[-7] = v_11413;
    goto v_11023;
v_11024:
    v_11412 = elt(env, 7); // yetunknowntype
    goto v_11025;
v_11026:
    goto v_11022;
v_11023:
    goto v_11024;
v_11025:
    if (v_11413 == v_11412) goto v_11020;
    else goto v_11021;
v_11020:
    goto v_11036;
v_11032:
    v_11413 = stack[-1];
    goto v_11033;
v_11034:
    v_11412 = nil;
    goto v_11035;
v_11036:
    goto v_11032;
v_11033:
    goto v_11034;
v_11035:
    fn = elt(env, 19); // eval!-yetunknowntypeexpr
    v_11412 = (*qfn2(fn))(fn, v_11413, v_11412);
    env = stack[-14];
    stack[-1] = v_11412;
    fn = elt(env, 18); // getrtype
    v_11412 = (*qfn1(fn))(fn, v_11412);
    env = stack[-14];
    stack[-7] = v_11412;
    goto v_11019;
v_11021:
v_11019:
    v_11412 = stack[-7];
    if (v_11412 == nil) goto v_11042;
    goto v_11050;
v_11046:
    v_11413 = stack[-7];
    goto v_11047;
v_11048:
    v_11412 = elt(env, 8); // list
    goto v_11049;
v_11050:
    goto v_11046;
v_11047:
    goto v_11048;
v_11049:
    if (v_11413 == v_11412) goto v_11042;
    goto v_11058;
v_11054:
    goto v_11064;
v_11060:
    v_11413 = stack[-7];
    goto v_11061;
v_11062:
    v_11412 = stack[-1];
    goto v_11063;
v_11064:
    goto v_11060;
v_11061:
    goto v_11062;
v_11063:
    v_11413 = list2(v_11413, v_11412);
    env = stack[-14];
    goto v_11055;
v_11056:
    v_11412 = elt(env, 9); // "substituted expression"
    goto v_11057;
v_11058:
    goto v_11054;
v_11055:
    goto v_11056;
v_11057:
    fn = elt(env, 20); // typerr
    v_11412 = (*qfn2(fn))(fn, v_11413, v_11412);
    env = stack[-14];
    goto v_11040;
v_11042:
v_11040:
    v_11412 = nil;
    fn = elt(env, 21); // setkorder
    v_11412 = (*qfn1(fn))(fn, v_11412);
    env = stack[-14];
    stack[0] = v_11412;
    v_11412 = stack[-1];
    fn = elt(env, 14); // simp
    v_11412 = (*qfn1(fn))(fn, v_11412);
    env = stack[-14];
    stack[-7] = v_11412;
    v_11412 = stack[0];
    fn = elt(env, 21); // setkorder
    v_11412 = (*qfn1(fn))(fn, v_11412);
    env = stack[-14];
    v_11412 = stack[-7];
    fn = elt(env, 22); // reordsq
    v_11412 = (*qfn1(fn))(fn, v_11412);
    env = stack[-14];
    stack[-7] = v_11412;
    v_11412 = stack[-11];
    if (v_11412 == nil) goto v_11082;
    else goto v_11083;
v_11082:
    v_11412 = stack[-7];
    fn = elt(env, 23); // kernp
    v_11412 = (*qfn1(fn))(fn, v_11412);
    env = stack[-14];
    if (v_11412 == nil) goto v_11087;
    else goto v_11088;
v_11087:
    v_11412 = nil;
    goto v_11086;
v_11088:
    goto v_11098;
v_11094:
    v_11412 = stack[-7];
    v_11412 = qcar(v_11412);
    v_11412 = qcar(v_11412);
    v_11412 = qcar(v_11412);
    v_11413 = qcar(v_11412);
    goto v_11095;
v_11096:
    v_11412 = stack[-2];
    goto v_11097;
v_11098:
    goto v_11094;
v_11095:
    goto v_11096;
v_11097:
    v_11412 = (v_11413 == v_11412 ? lisp_true : nil);
    goto v_11086;
    v_11412 = nil;
v_11086:
    goto v_11081;
v_11083:
    v_11412 = nil;
    goto v_11081;
    v_11412 = nil;
v_11081:
    if (v_11412 == nil) goto v_11079;
    goto v_10770;
v_11079:
    v_11412 = stack[-7];
    v_11412 = qcar(v_11412);
    if (v_11412 == nil) goto v_11109;
    else goto v_11110;
v_11109:
    goto v_10769;
v_11110:
    v_11412 = stack[-7];
    stack[-6] = v_11412;
    v_11412 = stack[-5];
    stack[-2] = v_11412;
v_11117:
    v_11412 = stack[-2];
    if (v_11412 == nil) goto v_11121;
    else goto v_11122;
v_11121:
    goto v_11116;
v_11122:
    v_11412 = stack[-2];
    v_11412 = qcar(v_11412);
    stack[-1] = v_11412;
    v_11412 = stack[-1];
    v_11412 = qcar(v_11412);
    v_11412 = qcdr(v_11412);
    stack[-10] = v_11412;
    goto v_11139;
v_11135:
    v_11413 = stack[-10];
    goto v_11136;
v_11137:
    v_11412 = qvalue(elt(env, 10)); // frlis!*
    goto v_11138;
v_11139:
    goto v_11135;
v_11136:
    goto v_11137;
v_11138:
    v_11412 = Lmemq(nil, v_11413, v_11412);
    if (v_11412 == nil) goto v_11134;
    goto v_11149;
v_11145:
    v_11412 = stack[-6];
    fn = elt(env, 24); // prepsq
    v_11413 = (*qfn1(fn))(fn, v_11412);
    env = stack[-14];
    goto v_11146;
v_11147:
    v_11412 = stack[-10];
    goto v_11148;
v_11149:
    goto v_11145;
v_11146:
    goto v_11147;
v_11148:
    v_11412 = list2(v_11413, v_11412);
    env = stack[-14];
    fn = elt(env, 25); // simpexpt
    v_11412 = (*qfn1(fn))(fn, v_11412);
    env = stack[-14];
    stack[-7] = v_11412;
    v_11412 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-10] = v_11412;
    goto v_11132;
v_11134:
v_11132:
    goto v_11159;
v_11155:
    goto v_11166;
v_11162:
    stack[0] = stack[-7];
    goto v_11163;
v_11164:
    goto v_11173;
v_11169:
    v_11413 = stack[-10];
    goto v_11170;
v_11171:
    v_11412 = stack[-13];
    goto v_11172;
v_11173:
    goto v_11169;
v_11170:
    goto v_11171;
v_11172:
    v_11412 = difference2(v_11413, v_11412);
    env = stack[-14];
    goto v_11165;
v_11166:
    goto v_11162;
v_11163:
    goto v_11164;
v_11165:
    fn = elt(env, 26); // exptsq
    v_11412 = (*qfn2(fn))(fn, stack[0], v_11412);
    env = stack[-14];
    fn = elt(env, 27); // subs2
    v_11413 = (*qfn1(fn))(fn, v_11412);
    env = stack[-14];
    goto v_11156;
v_11157:
    v_11412 = stack[-8];
    goto v_11158;
v_11159:
    goto v_11155;
v_11156:
    goto v_11157;
v_11158:
    fn = elt(env, 28); // multsq
    v_11412 = (*qfn2(fn))(fn, v_11413, v_11412);
    env = stack[-14];
    stack[-8] = v_11412;
    v_11412 = stack[-10];
    stack[-13] = v_11412;
    goto v_11183;
v_11179:
    goto v_11189;
v_11185:
    stack[0] = stack[-8];
    goto v_11186;
v_11187:
    goto v_11196;
v_11192:
    v_11412 = stack[-1];
    v_11413 = qcdr(v_11412);
    goto v_11193;
v_11194:
    v_11412 = stack[-11];
    goto v_11195;
v_11196:
    goto v_11192;
v_11193:
    goto v_11194;
v_11195:
    v_11412 = CC_subf1(elt(env, 0), v_11413, v_11412);
    env = stack[-14];
    goto v_11188;
v_11189:
    goto v_11185;
v_11186:
    goto v_11187;
v_11188:
    fn = elt(env, 28); // multsq
    v_11413 = (*qfn2(fn))(fn, stack[0], v_11412);
    env = stack[-14];
    goto v_11180;
v_11181:
    v_11412 = stack[-3];
    goto v_11182;
v_11183:
    goto v_11179;
v_11180:
    goto v_11181;
v_11182:
    fn = elt(env, 29); // addsq
    v_11412 = (*qfn2(fn))(fn, v_11413, v_11412);
    env = stack[-14];
    stack[-3] = v_11412;
    v_11412 = stack[-2];
    v_11412 = qcdr(v_11412);
    stack[-2] = v_11412;
    goto v_11117;
v_11116:
v_10769:
v_11205:
    v_11412 = stack[-5];
    if (v_11412 == nil) goto v_11208;
    else goto v_11209;
v_11208:
    goto v_11204;
v_11209:
    goto v_11217;
v_11213:
    v_11412 = stack[-5];
    v_11412 = qcar(v_11412);
    v_11413 = qcdr(v_11412);
    goto v_11214;
v_11215:
    v_11412 = stack[-11];
    goto v_11216;
v_11217:
    goto v_11213;
v_11214:
    goto v_11215;
v_11216:
    v_11412 = CC_subf1(elt(env, 0), v_11413, v_11412);
    env = stack[-14];
    v_11412 = stack[-5];
    v_11412 = qcdr(v_11412);
    stack[-5] = v_11412;
    goto v_11205;
v_11204:
    v_11412 = stack[-12];
    if (v_11412 == nil) goto v_11226;
    else goto v_11227;
v_11226:
    v_11412 = stack[-3];
    goto v_10764;
v_11227:
    v_11412 = stack[-12];
    if (!consp(v_11412)) goto v_11234;
    else goto v_11235;
v_11234:
    v_11412 = lisp_true;
    goto v_11233;
v_11235:
    v_11412 = stack[-12];
    v_11412 = qcar(v_11412);
    v_11412 = (consp(v_11412) ? nil : lisp_true);
    goto v_11233;
    v_11412 = nil;
v_11233:
    if (v_11412 == nil) goto v_11231;
    goto v_11248;
v_11244:
    goto v_11254;
v_11250:
    v_11413 = stack[-12];
    goto v_11251;
v_11252:
    v_11412 = stack[-11];
    goto v_11253;
v_11254:
    goto v_11250;
v_11251:
    goto v_11252;
v_11253:
    v_11413 = CC_subf1(elt(env, 0), v_11413, v_11412);
    env = stack[-14];
    goto v_11245;
v_11246:
    v_11412 = stack[-3];
    goto v_11247;
v_11248:
    goto v_11244;
v_11245:
    goto v_11246;
v_11247:
    fn = elt(env, 29); // addsq
    v_11412 = (*qfn2(fn))(fn, v_11413, v_11412);
    goto v_10764;
v_11231:
    goto v_10765;
v_10770:
    v_11412 = stack[-2];
    fn = elt(env, 30); // sub2chk
    v_11412 = (*qfn1(fn))(fn, v_11412);
    env = stack[-14];
    v_11412 = stack[-5];
    stack[-2] = v_11412;
v_11263:
    v_11412 = stack[-2];
    if (v_11412 == nil) goto v_11267;
    else goto v_11268;
v_11267:
    goto v_11262;
v_11268:
    v_11412 = stack[-2];
    v_11412 = qcar(v_11412);
    stack[-1] = v_11412;
    goto v_11279;
v_11275:
    goto v_11285;
v_11281:
    goto v_11291;
v_11287:
    goto v_11298;
v_11294:
    v_11412 = stack[-1];
    v_11413 = qcar(v_11412);
    goto v_11295;
v_11296:
    v_11412 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11297;
v_11298:
    goto v_11294;
v_11295:
    goto v_11296;
v_11297:
    v_11412 = cons(v_11413, v_11412);
    env = stack[-14];
    v_11413 = ncons(v_11412);
    env = stack[-14];
    goto v_11288;
v_11289:
    v_11412 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11290;
v_11291:
    goto v_11287;
v_11288:
    goto v_11289;
v_11290:
    stack[0] = cons(v_11413, v_11412);
    env = stack[-14];
    goto v_11282;
v_11283:
    goto v_11308;
v_11304:
    v_11412 = stack[-1];
    v_11413 = qcdr(v_11412);
    goto v_11305;
v_11306:
    v_11412 = stack[-11];
    goto v_11307;
v_11308:
    goto v_11304;
v_11305:
    goto v_11306;
v_11307:
    v_11412 = CC_subf1(elt(env, 0), v_11413, v_11412);
    env = stack[-14];
    goto v_11284;
v_11285:
    goto v_11281;
v_11282:
    goto v_11283;
v_11284:
    fn = elt(env, 28); // multsq
    v_11413 = (*qfn2(fn))(fn, stack[0], v_11412);
    env = stack[-14];
    goto v_11276;
v_11277:
    v_11412 = stack[-3];
    goto v_11278;
v_11279:
    goto v_11275;
v_11276:
    goto v_11277;
v_11278:
    fn = elt(env, 29); // addsq
    v_11412 = (*qfn2(fn))(fn, v_11413, v_11412);
    env = stack[-14];
    stack[-3] = v_11412;
    v_11412 = stack[-2];
    v_11412 = qcdr(v_11412);
    stack[-2] = v_11412;
    goto v_11263;
v_11262:
    goto v_10769;
v_10771:
    v_11412 = stack[-1];
    v_11412 = ncons(v_11412);
    env = stack[-14];
    fn = elt(env, 31); // simprecip
    v_11412 = (*qfn1(fn))(fn, v_11412);
    env = stack[-14];
    stack[-7] = v_11412;
v_10772:
    goto v_11323;
v_11319:
    v_11412 = stack[-5];
    v_11413 = qcar(v_11412);
    goto v_11320;
v_11321:
    v_11412 = stack[-4];
    goto v_11322;
v_11323:
    goto v_11319;
v_11320:
    goto v_11321;
v_11322:
    v_11412 = cons(v_11413, v_11412);
    env = stack[-14];
    stack[-4] = v_11412;
    v_11412 = stack[-5];
    v_11412 = qcdr(v_11412);
    stack[-5] = v_11412;
    v_11412 = stack[-5];
    if (v_11412 == nil) goto v_11332;
    goto v_11341;
v_11337:
    v_11412 = stack[-5];
    v_11412 = qcar(v_11412);
    v_11412 = qcar(v_11412);
    v_11413 = qcdr(v_11412);
    goto v_11338;
v_11339:
    v_11412 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11340;
v_11341:
    goto v_11337;
v_11338:
    goto v_11339;
v_11340:
    v_11412 = (LispObject)lessp2(v_11413, v_11412);
    v_11412 = v_11412 ? lisp_true : nil;
    env = stack[-14];
    if (v_11412 == nil) goto v_11332;
    goto v_10772;
v_11332:
v_10773:
    v_11412 = stack[-4];
    v_11412 = qcar(v_11412);
    v_11412 = qcar(v_11412);
    v_11412 = qcdr(v_11412);
    v_11412 = negate(v_11412);
    env = stack[-14];
    stack[-10] = v_11412;
    goto v_11357;
v_11353:
    goto v_11364;
v_11360:
    stack[0] = stack[-7];
    goto v_11361;
v_11362:
    goto v_11371;
v_11367:
    v_11413 = stack[-10];
    goto v_11368;
v_11369:
    v_11412 = stack[-13];
    goto v_11370;
v_11371:
    goto v_11367;
v_11368:
    goto v_11369;
v_11370:
    v_11412 = difference2(v_11413, v_11412);
    env = stack[-14];
    goto v_11363;
v_11364:
    goto v_11360;
v_11361:
    goto v_11362;
v_11363:
    fn = elt(env, 26); // exptsq
    v_11412 = (*qfn2(fn))(fn, stack[0], v_11412);
    env = stack[-14];
    fn = elt(env, 27); // subs2
    v_11413 = (*qfn1(fn))(fn, v_11412);
    env = stack[-14];
    goto v_11354;
v_11355:
    v_11412 = stack[-8];
    goto v_11356;
v_11357:
    goto v_11353;
v_11354:
    goto v_11355;
v_11356:
    fn = elt(env, 28); // multsq
    v_11412 = (*qfn2(fn))(fn, v_11413, v_11412);
    env = stack[-14];
    stack[-8] = v_11412;
    v_11412 = stack[-10];
    stack[-13] = v_11412;
    goto v_11381;
v_11377:
    goto v_11387;
v_11383:
    stack[0] = stack[-8];
    goto v_11384;
v_11385:
    goto v_11394;
v_11390:
    v_11412 = stack[-4];
    v_11412 = qcar(v_11412);
    v_11413 = qcdr(v_11412);
    goto v_11391;
v_11392:
    v_11412 = stack[-11];
    goto v_11393;
v_11394:
    goto v_11390;
v_11391:
    goto v_11392;
v_11393:
    v_11412 = CC_subf1(elt(env, 0), v_11413, v_11412);
    env = stack[-14];
    goto v_11386;
v_11387:
    goto v_11383;
v_11384:
    goto v_11385;
v_11386:
    fn = elt(env, 28); // multsq
    v_11413 = (*qfn2(fn))(fn, stack[0], v_11412);
    env = stack[-14];
    goto v_11378;
v_11379:
    v_11412 = stack[-3];
    goto v_11380;
v_11381:
    goto v_11377;
v_11378:
    goto v_11379;
v_11380:
    fn = elt(env, 29); // addsq
    v_11412 = (*qfn2(fn))(fn, v_11413, v_11412);
    env = stack[-14];
    stack[-3] = v_11412;
    v_11412 = stack[-4];
    v_11412 = qcdr(v_11412);
    stack[-4] = v_11412;
    v_11412 = stack[-4];
    if (v_11412 == nil) goto v_11405;
    goto v_10773;
v_11405:
    v_11412 = stack[-5];
    if (v_11412 == nil) goto v_11408;
    goto v_10768;
v_11408:
    goto v_10769;
    v_11412 = nil;
v_10764:
    ;}  // end of a binding scope
    goto v_10668;
    v_11412 = nil;
v_10668:
    return onevalue(v_11412);
}



// Code for decprec2internal

static LispObject CC_decprec2internal(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10682, v_10683;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_10682 = v_10664;
// end of prologue
    goto v_10671;
v_10667:
    goto v_10678;
v_10674:
    v_10683 = v_10682;
    goto v_10675;
v_10676:
    v_10682 = qvalue(elt(env, 1)); // !!log2of10
    goto v_10677;
v_10678:
    goto v_10674;
v_10675:
    goto v_10676;
v_10677:
    v_10682 = times2(v_10683, v_10682);
    env = stack[0];
    fn = elt(env, 2); // ceiling
    v_10683 = (*qfn1(fn))(fn, v_10682);
    goto v_10668;
v_10669:
    v_10682 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_10670;
v_10671:
    goto v_10667;
v_10668:
    goto v_10669;
v_10670:
    return plus2(v_10683, v_10682);
}



// Code for triplesetprolongset

static LispObject CC_triplesetprolongset(LispObject env,
                         LispObject v_10664, LispObject v_10665)
{
    env = qenv(env);
    LispObject v_10702, v_10703;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10665,v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10664,v_10665);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10665;
    stack[-1] = v_10664;
// end of prologue
    v_10703 = nil;
v_10672:
    v_10702 = stack[0];
    if (v_10702 == nil) goto v_10675;
    else goto v_10676;
v_10675:
    goto v_10671;
v_10676:
    goto v_10684;
v_10680:
    v_10702 = stack[0];
    v_10702 = qcar(v_10702);
    goto v_10681;
v_10682:
    goto v_10683;
v_10684:
    goto v_10680;
v_10681:
    goto v_10682;
v_10683:
    v_10702 = cons(v_10702, v_10703);
    env = stack[-2];
    v_10703 = v_10702;
    v_10702 = stack[0];
    v_10702 = qcdr(v_10702);
    stack[0] = v_10702;
    goto v_10672;
v_10671:
    goto v_10697;
v_10691:
    goto v_10692;
v_10693:
    stack[0] = (LispObject)48+TAG_FIXNUM; // 3
    goto v_10694;
v_10695:
    v_10702 = v_10703;
    v_10702 = Lreverse(nil, v_10702);
    goto v_10696;
v_10697:
    goto v_10691;
v_10692:
    goto v_10693;
v_10694:
    goto v_10695;
v_10696:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_10702;
    v_10702 = nil;
    return onevalue(v_10702);
}



// Code for rl_csimpl

static LispObject CC_rl_csimpl(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10689, v_10690, v_10691;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10664;
// end of prologue
    v_10689 = qvalue(elt(env, 1)); // !*rlsimpl
    if (v_10689 == nil) goto v_10669;
    v_10689 = elt(env, 2); // rl_simpl
    fn = elt(env, 3); // getd
    v_10689 = (*qfn1(fn))(fn, v_10689);
    env = stack[-1];
    if (v_10689 == nil) goto v_10669;
    goto v_10682;
v_10676:
    v_10691 = stack[0];
    goto v_10677;
v_10678:
    v_10690 = nil;
    goto v_10679;
v_10680:
    v_10689 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_10681;
v_10682:
    goto v_10676;
v_10677:
    goto v_10678;
v_10679:
    goto v_10680;
v_10681:
    {
        fn = elt(env, 2); // rl_simpl
        return (*qfnn(fn))(fn, 3, v_10691, v_10690, v_10689);
    }
v_10669:
    v_10689 = stack[0];
    goto v_10667;
    v_10689 = nil;
v_10667:
    return onevalue(v_10689);
}



// Code for talp_invn

static LispObject CC_talp_invn(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10677;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_10677 = v_10664;
// end of prologue
    fn = elt(env, 1); // talp_op
    v_10677 = (*qfn1(fn))(fn, v_10677);
    env = stack[0];
    v_10677 = Lexplodec(nil, v_10677);
    env = stack[0];
    v_10677 = qcdr(v_10677);
    v_10677 = qcdr(v_10677);
    v_10677 = qcdr(v_10677);
    v_10677 = qcdr(v_10677);
    v_10677 = qcdr(v_10677);
    v_10677 = qcar(v_10677);
    v_10677 = ncons(v_10677);
        return Lcompress(nil, v_10677);
}



// Code for lx2xx

static LispObject CC_lx2xx(LispObject env,
                         LispObject v_10664)
{
    env = qenv(env);
    LispObject v_10741, v_10742;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10664);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10664);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_10664;
// end of prologue
    v_10741 = stack[-2];
    if (!consp(v_10741)) goto v_10680;
    else goto v_10681;
v_10680:
    v_10741 = lisp_true;
    goto v_10679;
v_10681:
    v_10741 = stack[-2];
    v_10741 = qcar(v_10741);
    v_10741 = (consp(v_10741) ? nil : lisp_true);
    goto v_10679;
    v_10741 = nil;
v_10679:
    if (v_10741 == nil) goto v_10677;
    v_10741 = lisp_true;
    goto v_10675;
v_10677:
    v_10741 = stack[-2];
    v_10741 = qcar(v_10741);
    if (!consp(v_10741)) goto v_10694;
    else goto v_10695;
v_10694:
    v_10741 = lisp_true;
    goto v_10693;
v_10695:
    v_10741 = stack[-2];
    v_10741 = qcar(v_10741);
    v_10741 = qcar(v_10741);
    v_10741 = (consp(v_10741) ? nil : lisp_true);
    goto v_10693;
    v_10741 = nil;
v_10693:
    goto v_10675;
    v_10741 = nil;
v_10675:
    if (v_10741 == nil) goto v_10673;
    v_10741 = stack[-2];
    goto v_10669;
v_10673:
    v_10741 = stack[-2];
    v_10741 = qcdr(v_10741);
    v_10741 = qcar(v_10741);
    stack[-3] = v_10741;
    v_10741 = stack[-3];
    fn = elt(env, 1); // lastnondomain
    v_10741 = (*qfn1(fn))(fn, v_10741);
    env = stack[-4];
    v_10741 = qcdr(v_10741);
    stack[-1] = v_10741;
    goto v_10719;
v_10713:
    v_10741 = stack[-2];
    stack[0] = qcar(v_10741);
    goto v_10714;
v_10715:
    goto v_10727;
v_10723:
    goto v_10734;
v_10730:
    v_10742 = stack[-1];
    goto v_10731;
v_10732:
    v_10741 = stack[-3];
    goto v_10733;
v_10734:
    goto v_10730;
v_10731:
    goto v_10732;
v_10733:
    fn = elt(env, 2); // delet
    v_10741 = (*qfn2(fn))(fn, v_10742, v_10741);
    env = stack[-4];
    fn = elt(env, 3); // xxsort
    v_10742 = (*qfn1(fn))(fn, v_10741);
    env = stack[-4];
    goto v_10724;
v_10725:
    v_10741 = stack[-1];
    goto v_10726;
v_10727:
    goto v_10723;
v_10724:
    goto v_10725;
v_10726:
    v_10742 = Lappend(nil, v_10742, v_10741);
    goto v_10716;
v_10717:
    v_10741 = stack[-2];
    v_10741 = qcdr(v_10741);
    v_10741 = qcdr(v_10741);
    goto v_10718;
v_10719:
    goto v_10713;
v_10714:
    goto v_10715;
v_10716:
    goto v_10717;
v_10718:
    {
        LispObject v_10747 = stack[0];
        return list2star(v_10747, v_10742, v_10741);
    }
v_10669:
    return onevalue(v_10741);
}



setup_type const u19_setup[] =
{
    {":expt",                   TOO_FEW_2,      CC_Texpt,      WRONG_NO_2},
    {"lex_start_line_comment",  CC_lex_start_line_comment,TOO_MANY_1,WRONG_NO_1},
    {"formcond",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formcond},
    {"ofsf_entry2at",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_entry2at},
    {"ofsf_smmkatl1",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smmkatl1},
    {"rl_atl",                  CC_rl_atl,      TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_readclause",        TOO_FEW_2,      CC_ibalp_readclause,WRONG_NO_2},
    {"powers4",                 TOO_FEW_2,      CC_powers4,    WRONG_NO_2},
    {"om2mml",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_om2mml},
    {"*wedgepf2pf",             CC_Hwedgepf2pf, TOO_MANY_1,    WRONG_NO_1},
    {"delete-dups",             CC_deleteKdups, TOO_MANY_1,    WRONG_NO_1},
    {"scal*list",               TOO_FEW_2,      CC_scalHlist,  WRONG_NO_2},
    {"physop-ordop",            TOO_FEW_2,      CC_physopKordop,WRONG_NO_2},
    {"zero-roads",              CC_zeroKroads,  TOO_MANY_1,    WRONG_NO_1},
    {"revalx",                  CC_revalx,      TOO_MANY_1,    WRONG_NO_1},
    {"di_restore",              CC_di_restore,  TOO_MANY_1,    WRONG_NO_1},
    {"general-reduce-mod-p",    CC_generalKreduceKmodKp,TOO_MANY_1,WRONG_NO_1},
    {"lex_save_context",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex_save_context},
    {"monomdivide",             TOO_FEW_2,      CC_monomdivide,WRONG_NO_2},
    {"sfto_ucontentf1",         TOO_FEW_2,      CC_sfto_ucontentf1,WRONG_NO_2},
    {"simpg3",                  CC_simpg3,      TOO_MANY_1,    WRONG_NO_1},
    {"findnthroot",             CC_findnthroot, TOO_MANY_1,    WRONG_NO_1},
    {"prepsq*",                 CC_prepsqH,     TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_recalcv",           CC_ibalp_recalcv,TOO_MANY_1,   WRONG_NO_1},
    {"mvar_member",             TOO_FEW_2,      CC_mvar_member,WRONG_NO_2},
    {"variablesir",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_variablesir},
    {"evmtest?",                TOO_FEW_2,      CC_evmtestW,   WRONG_NO_2},
    {"xord_deglex",             TOO_FEW_2,      CC_xord_deglex,WRONG_NO_2},
    {"invp",                    CC_invp,        TOO_MANY_1,    WRONG_NO_1},
    {"contr",                   TOO_FEW_2,      CC_contr,      WRONG_NO_2},
    {"repasc",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_repasc},
    {"addgt",                   CC_addgt,       TOO_MANY_1,    WRONG_NO_1},
    {"il_simp",                 CC_il_simp,     TOO_MANY_1,    WRONG_NO_1},
    {"ordexn",                  TOO_FEW_2,      CC_ordexn,     WRONG_NO_2},
    {"expt-mod-p",              TOO_FEW_2,      CC_exptKmodKp, WRONG_NO_2},
    {"prin_with_margin",        CC_prin_with_margin,TOO_MANY_1,WRONG_NO_1},
    {"gcref_mkgraph",           CC_gcref_mkgraph,TOO_MANY_1,   WRONG_NO_1},
    {"talp_rnf1",               CC_talp_rnf1,   TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_renewwl",           CC_ibalp_renewwl,TOO_MANY_1,   WRONG_NO_1},
    {"binomial-coefft-mod-p",   TOO_FEW_2,      CC_binomialKcoefftKmodKp,WRONG_NO_2},
    {"ir2om",                   CC_ir2om,       TOO_MANY_1,    WRONG_NO_1},
    {"groebcplistsortin",       TOO_FEW_2,      CC_groebcplistsortin,WRONG_NO_2},
    {"mo_times_ei",             TOO_FEW_2,      CC_mo_times_ei,WRONG_NO_2},
    {"th_match",                TOO_FEW_2,      CC_th_match,   WRONG_NO_2},
    {"arplus:",                 TOO_FEW_2,      CC_arplusT,    WRONG_NO_2},
    {"subf1",                   TOO_FEW_2,      CC_subf1,      WRONG_NO_2},
    {"decprec2internal",        CC_decprec2internal,TOO_MANY_1,WRONG_NO_1},
    {"triplesetprolongset",     TOO_FEW_2,      CC_triplesetprolongset,WRONG_NO_2},
    {"rl_csimpl",               CC_rl_csimpl,   TOO_MANY_1,    WRONG_NO_1},
    {"talp_invn",               CC_talp_invn,   TOO_MANY_1,    WRONG_NO_1},
    {"lx2xx",                   CC_lx2xx,       TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u19", (two_args *)"179199 4132816 7178925", 0}
};

// end of generated code
