
// $destdir/u07.c        Machine generated C code

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



// Code for gcddd

static LispObject CC_gcddd(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2550, v_2551, v_2552;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2433,v_2434);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2434;
    stack[-1] = v_2433;
// end of prologue
    goto v_2448;
v_2444:
    v_2551 = stack[-1];
    goto v_2445;
v_2446:
    v_2550 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2447;
v_2448:
    goto v_2444;
v_2445:
    goto v_2446;
v_2447:
    if (v_2551 == v_2550) goto v_2442;
    else goto v_2443;
v_2442:
    v_2550 = lisp_true;
    goto v_2441;
v_2443:
    goto v_2458;
v_2454:
    v_2551 = stack[0];
    goto v_2455;
v_2456:
    v_2550 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2457;
v_2458:
    goto v_2454;
v_2455:
    goto v_2456;
v_2457:
    v_2550 = (v_2551 == v_2550 ? lisp_true : nil);
    goto v_2441;
    v_2550 = nil;
v_2441:
    if (v_2550 == nil) goto v_2439;
    v_2550 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2437;
v_2439:
    v_2550 = stack[-1];
    if (!consp(v_2550)) goto v_2463;
    else goto v_2464;
v_2463:
    v_2550 = stack[0];
    if (!consp(v_2550)) goto v_2468;
    else goto v_2469;
v_2468:
    goto v_2476;
v_2472:
    v_2551 = stack[-1];
    goto v_2473;
v_2474:
    v_2550 = stack[0];
    goto v_2475;
v_2476:
    goto v_2472;
v_2473:
    goto v_2474;
v_2475:
        return Lgcd(nil, v_2551, v_2550);
v_2469:
    v_2550 = stack[0];
    fn = elt(env, 2); // fieldp
    v_2550 = (*qfn1(fn))(fn, v_2550);
    env = stack[-2];
    if (v_2550 == nil) goto v_2480;
    v_2550 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2467;
v_2480:
    goto v_2493;
v_2487:
    v_2552 = stack[-1];
    goto v_2488;
v_2489:
    v_2551 = stack[0];
    goto v_2490;
v_2491:
    v_2550 = elt(env, 1); // gcd
    goto v_2492;
v_2493:
    goto v_2487;
v_2488:
    goto v_2489;
v_2490:
    goto v_2491;
v_2492:
    {
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(fn, 3, v_2552, v_2551, v_2550);
    }
    v_2550 = nil;
v_2467:
    goto v_2437;
v_2464:
    v_2550 = stack[0];
    if (!consp(v_2550)) goto v_2497;
    else goto v_2498;
v_2497:
    v_2550 = stack[-1];
    v_2550 = qcar(v_2550);
    if (!symbolp(v_2550)) v_2550 = nil;
    else { v_2550 = qfastgets(v_2550);
           if (v_2550 != nil) { v_2550 = elt(v_2550, 3); // field
#ifdef RECORD_GET
             if (v_2550 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_2550 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_2550 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_2550 == SPID_NOPROP) v_2550 = nil; else v_2550 = lisp_true; }}
#endif
    if (v_2550 == nil) goto v_2503;
    v_2550 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2501;
v_2503:
    goto v_2517;
v_2511:
    v_2552 = stack[-1];
    goto v_2512;
v_2513:
    v_2551 = stack[0];
    goto v_2514;
v_2515:
    v_2550 = elt(env, 1); // gcd
    goto v_2516;
v_2517:
    goto v_2511;
v_2512:
    goto v_2513;
v_2514:
    goto v_2515;
v_2516:
    {
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(fn, 3, v_2552, v_2551, v_2550);
    }
    v_2550 = nil;
v_2501:
    goto v_2437;
v_2498:
    v_2550 = stack[-1];
    v_2550 = qcar(v_2550);
    if (!symbolp(v_2550)) v_2550 = nil;
    else { v_2550 = qfastgets(v_2550);
           if (v_2550 != nil) { v_2550 = elt(v_2550, 3); // field
#ifdef RECORD_GET
             if (v_2550 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_2550 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_2550 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_2550 == SPID_NOPROP) v_2550 = nil; else v_2550 = lisp_true; }}
#endif
    if (v_2550 == nil) goto v_2526;
    v_2550 = lisp_true;
    goto v_2524;
v_2526:
    v_2550 = stack[0];
    v_2550 = qcar(v_2550);
    if (!symbolp(v_2550)) v_2550 = nil;
    else { v_2550 = qfastgets(v_2550);
           if (v_2550 != nil) { v_2550 = elt(v_2550, 3); // field
#ifdef RECORD_GET
             if (v_2550 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_2550 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_2550 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_2550 == SPID_NOPROP) v_2550 = nil; else v_2550 = lisp_true; }}
#endif
    goto v_2524;
    v_2550 = nil;
v_2524:
    if (v_2550 == nil) goto v_2522;
    v_2550 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2437;
v_2522:
    goto v_2546;
v_2540:
    v_2552 = stack[-1];
    goto v_2541;
v_2542:
    v_2551 = stack[0];
    goto v_2543;
v_2544:
    v_2550 = elt(env, 1); // gcd
    goto v_2545;
v_2546:
    goto v_2540;
v_2541:
    goto v_2542;
v_2543:
    goto v_2544;
v_2545:
    {
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(fn, 3, v_2552, v_2551, v_2550);
    }
    v_2550 = nil;
v_2437:
    return onevalue(v_2550);
}



// Code for rat_sgn

static LispObject CC_rat_sgn(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2438;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_2438 = v_2433;
// end of prologue
    fn = elt(env, 1); // rat_numrn
    v_2438 = (*qfn1(fn))(fn, v_2438);
    env = stack[0];
    {
        fn = elt(env, 2); // sgn
        return (*qfn1(fn))(fn, v_2438);
    }
}



// Code for xcomment

static LispObject CC_xcomment(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2460, v_2461, v_2462;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2433,v_2434);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_2462 = v_2434;
    v_2461 = v_2433;
// end of prologue
    v_2460 = v_2462;
    if (v_2460 == nil) goto v_2439;
    goto v_2446;
v_2442:
    stack[0] = elt(env, 1); // comment
    goto v_2443;
v_2444:
    goto v_2453;
v_2449:
    v_2460 = v_2462;
    v_2460 = Lnreverse(nil, v_2460);
    env = stack[-1];
    goto v_2450;
v_2451:
    goto v_2452;
v_2453:
    goto v_2449;
v_2450:
    goto v_2451;
v_2452:
    fn = elt(env, 2); // aconc
    v_2460 = (*qfn2(fn))(fn, v_2460, v_2461);
    goto v_2445;
v_2446:
    goto v_2442;
v_2443:
    goto v_2444;
v_2445:
    {
        LispObject v_2464 = stack[0];
        return cons(v_2464, v_2460);
    }
v_2439:
    v_2460 = v_2461;
    goto v_2437;
    v_2460 = nil;
v_2437:
    return onevalue(v_2460);
}



// Code for mcharg1

static LispObject CC_mcharg1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2593, v_2594, v_2595;
    LispObject fn;
    LispObject v_2435, v_2434, v_2433;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mcharg1");
    va_start(aa, nargs);
    v_2433 = va_arg(aa, LispObject);
    v_2434 = va_arg(aa, LispObject);
    v_2435 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_2435,v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_2433,v_2434,v_2435);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_2435;
    stack[-2] = v_2434;
    stack[-3] = v_2433;
// end of prologue
    v_2593 = stack[-3];
    if (v_2593 == nil) goto v_2443;
    else goto v_2444;
v_2443:
    v_2593 = stack[-2];
    v_2593 = (v_2593 == nil ? lisp_true : nil);
    goto v_2442;
v_2444:
    v_2593 = nil;
    goto v_2442;
    v_2593 = nil;
v_2442:
    if (v_2593 == nil) goto v_2440;
    v_2593 = nil;
    return ncons(v_2593);
v_2440:
    v_2593 = stack[-3];
    v_2593 = Llength(nil, v_2593);
    env = stack[-5];
    stack[-4] = v_2593;
    v_2593 = stack[-2];
    v_2593 = Llength(nil, v_2593);
    env = stack[-5];
    stack[0] = v_2593;
    v_2593 = stack[-1];
    if (!symbolp(v_2593)) v_2593 = nil;
    else { v_2593 = qfastgets(v_2593);
           if (v_2593 != nil) { v_2593 = elt(v_2593, 35); // nary
#ifdef RECORD_GET
             if (v_2593 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v_2593 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v_2593 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v_2593 == SPID_NOPROP) v_2593 = nil; else v_2593 = lisp_true; }}
#endif
    if (v_2593 == nil) goto v_2473;
    goto v_2481;
v_2477:
    v_2594 = stack[-4];
    goto v_2478;
v_2479:
    v_2593 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_2480;
v_2481:
    goto v_2477;
v_2478:
    goto v_2479;
v_2480:
    v_2593 = (LispObject)greaterp2(v_2594, v_2593);
    v_2593 = v_2593 ? lisp_true : nil;
    env = stack[-5];
    goto v_2471;
v_2473:
    v_2593 = nil;
    goto v_2471;
    v_2593 = nil;
v_2471:
    if (v_2593 == nil) goto v_2469;
    goto v_2497;
v_2493:
    v_2594 = stack[-4];
    goto v_2494;
v_2495:
    v_2593 = qvalue(elt(env, 2)); // matchlength!*
    goto v_2496;
v_2497:
    goto v_2493;
v_2494:
    goto v_2495;
v_2496:
    v_2593 = (LispObject)lesseq2(v_2594, v_2593);
    v_2593 = v_2593 ? lisp_true : nil;
    env = stack[-5];
    if (v_2593 == nil) goto v_2490;
    v_2593 = stack[-1];
    if (!symbolp(v_2593)) v_2593 = nil;
    else { v_2593 = qfastgets(v_2593);
           if (v_2593 != nil) { v_2593 = elt(v_2593, 43); // symmetric
#ifdef RECORD_GET
             if (v_2593 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v_2593 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v_2593 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v_2593 == SPID_NOPROP) v_2593 = nil; else v_2593 = lisp_true; }}
#endif
    if (v_2593 == nil) goto v_2490;
    goto v_2510;
v_2504:
    v_2595 = stack[-3];
    goto v_2505;
v_2506:
    v_2594 = stack[-2];
    goto v_2507;
v_2508:
    v_2593 = stack[-1];
    goto v_2509;
v_2510:
    goto v_2504;
v_2505:
    goto v_2506;
v_2507:
    goto v_2508;
v_2509:
    {
        fn = elt(env, 3); // mchcomb
        return (*qfnn(fn))(fn, 3, v_2595, v_2594, v_2593);
    }
v_2490:
    goto v_2520;
v_2516:
    v_2594 = stack[0];
    goto v_2517;
v_2518:
    v_2593 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_2519;
v_2520:
    goto v_2516;
v_2517:
    goto v_2518;
v_2519:
    if (v_2594 == v_2593) goto v_2514;
    else goto v_2515;
v_2514:
    goto v_2528;
v_2524:
    v_2594 = stack[-1];
    goto v_2525;
v_2526:
    v_2593 = stack[-3];
    goto v_2527;
v_2528:
    goto v_2524;
v_2525:
    goto v_2526;
v_2527:
    fn = elt(env, 4); // mkbin
    v_2593 = (*qfn2(fn))(fn, v_2594, v_2593);
    env = stack[-5];
    v_2593 = qcdr(v_2593);
    stack[-3] = v_2593;
    v_2593 = (LispObject)32+TAG_FIXNUM; // 2
    stack[-4] = v_2593;
    goto v_2488;
v_2515:
    v_2593 = nil;
    goto v_2458;
v_2488:
    goto v_2467;
v_2469:
v_2467:
    goto v_2544;
v_2540:
    v_2594 = stack[-4];
    goto v_2541;
v_2542:
    v_2593 = stack[0];
    goto v_2543;
v_2544:
    goto v_2540;
v_2541:
    goto v_2542;
v_2543:
    if (equal(v_2594, v_2593)) goto v_2539;
    v_2593 = nil;
    goto v_2537;
v_2539:
    v_2593 = stack[-1];
    if (!symbolp(v_2593)) v_2593 = nil;
    else { v_2593 = qfastgets(v_2593);
           if (v_2593 != nil) { v_2593 = elt(v_2593, 43); // symmetric
#ifdef RECORD_GET
             if (v_2593 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v_2593 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v_2593 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v_2593 == SPID_NOPROP) v_2593 = nil; else v_2593 = lisp_true; }}
#endif
    if (v_2593 == nil) goto v_2549;
    goto v_2559;
v_2553:
    v_2595 = stack[-3];
    goto v_2554;
v_2555:
    v_2594 = stack[-2];
    goto v_2556;
v_2557:
    v_2593 = stack[-1];
    goto v_2558;
v_2559:
    goto v_2553;
v_2554:
    goto v_2555;
v_2556:
    goto v_2557;
v_2558:
    {
        fn = elt(env, 5); // mchsarg
        return (*qfnn(fn))(fn, 3, v_2595, v_2594, v_2593);
    }
v_2549:
    v_2593 = stack[-2];
    fn = elt(env, 6); // mtp
    v_2593 = (*qfn1(fn))(fn, v_2593);
    env = stack[-5];
    if (v_2593 == nil) goto v_2564;
    goto v_2573;
v_2569:
    v_2594 = stack[-2];
    goto v_2570;
v_2571:
    v_2593 = stack[-3];
    goto v_2572;
v_2573:
    goto v_2569;
v_2570:
    goto v_2571;
v_2572:
    fn = elt(env, 7); // pair
    v_2593 = (*qfn2(fn))(fn, v_2594, v_2593);
    return ncons(v_2593);
v_2564:
    goto v_2587;
v_2579:
    stack[0] = stack[-3];
    goto v_2580;
v_2581:
    goto v_2582;
v_2583:
    v_2593 = nil;
    v_2594 = ncons(v_2593);
    env = stack[-5];
    goto v_2584;
v_2585:
    v_2593 = stack[-1];
    goto v_2586;
v_2587:
    goto v_2579;
v_2580:
    goto v_2581;
v_2582:
    goto v_2583;
v_2584:
    goto v_2585;
v_2586:
    {
        LispObject v_2601 = stack[0];
        LispObject v_2602 = stack[-2];
        fn = elt(env, 8); // mcharg2
        return (*qfnn(fn))(fn, 4, v_2601, v_2602, v_2594, v_2593);
    }
    v_2593 = nil;
v_2537:
v_2458:
    goto v_2438;
    v_2593 = nil;
v_2438:
    return onevalue(v_2593);
}



// Code for talp_simplat1

static LispObject CC_talp_simplat1(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2479, v_2480, v_2481;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2433,v_2434);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_2479 = v_2434;
    stack[-1] = v_2433;
// end of prologue
    v_2479 = stack[-1];
    fn = elt(env, 4); // talp_simpat
    v_2479 = (*qfn1(fn))(fn, v_2479);
    env = stack[-3];
    stack[-1] = v_2479;
    goto v_2449;
v_2443:
    v_2479 = stack[-1];
    fn = elt(env, 5); // talp_op
    stack[-2] = (*qfn1(fn))(fn, v_2479);
    env = stack[-3];
    goto v_2444;
v_2445:
    v_2479 = stack[-1];
    fn = elt(env, 6); // talp_arg2l
    stack[0] = (*qfn1(fn))(fn, v_2479);
    env = stack[-3];
    goto v_2446;
v_2447:
    v_2479 = stack[-1];
    fn = elt(env, 7); // talp_arg2r
    v_2479 = (*qfn1(fn))(fn, v_2479);
    env = stack[-3];
    goto v_2448;
v_2449:
    goto v_2443;
v_2444:
    goto v_2445;
v_2446:
    goto v_2447;
v_2448:
    fn = elt(env, 8); // talp_simplat2
    v_2479 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_2479);
    env = stack[-3];
    v_2481 = v_2479;
    v_2479 = v_2481;
    if (v_2479 == nil) goto v_2459;
    goto v_2469;
v_2465:
    v_2480 = v_2481;
    goto v_2466;
v_2467:
    v_2479 = lisp_true;
    goto v_2468;
v_2469:
    goto v_2465;
v_2466:
    goto v_2467;
v_2468:
    if (v_2480 == v_2479) goto v_2463;
    else goto v_2464;
v_2463:
    v_2479 = elt(env, 2); // true
    goto v_2438;
v_2464:
    v_2479 = v_2481;
    goto v_2438;
    goto v_2457;
v_2459:
    v_2479 = elt(env, 3); // false
    goto v_2438;
v_2457:
    v_2479 = nil;
v_2438:
    return onevalue(v_2479);
}



// Code for mathml

static LispObject CC_mathml(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2441;
    LispObject fn;
    argcheck(nargs, 0, "mathml");
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
    fn = elt(env, 2); // lex
    v_2441 = (*qfnn(fn))(fn, 0);
    env = stack[0];
    {
        fn = elt(env, 3); // sub_math
        return (*qfnn(fn))(fn, 0);
    }
    return onevalue(v_2441);
}



// Code for exptchk

static LispObject CC_exptchk(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2497, v_2498, v_2499;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2433;
// end of prologue
    v_2497 = stack[0];
    if (!consp(v_2497)) goto v_2441;
    else goto v_2442;
v_2441:
    v_2497 = lisp_true;
    goto v_2440;
v_2442:
    v_2497 = stack[0];
    v_2497 = qcar(v_2497);
    v_2497 = (consp(v_2497) ? nil : lisp_true);
    goto v_2440;
    v_2497 = nil;
v_2440:
    if (v_2497 == nil) goto v_2438;
    goto v_2455;
v_2451:
    v_2498 = stack[0];
    goto v_2452;
v_2453:
    v_2497 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2454;
v_2455:
    goto v_2451;
v_2452:
    goto v_2453;
v_2454:
    return cons(v_2498, v_2497);
v_2438:
    v_2497 = stack[0];
    fn = elt(env, 1); // comm_kernels
    v_2497 = (*qfn1(fn))(fn, v_2497);
    env = stack[-2];
    stack[-1] = v_2497;
    goto v_2472;
v_2468:
    v_2497 = stack[-1];
    v_2498 = Llength(nil, v_2497);
    env = stack[-2];
    goto v_2469;
v_2470:
    v_2497 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_2471;
v_2472:
    goto v_2468;
v_2469:
    goto v_2470;
v_2471:
    v_2497 = (LispObject)lessp2(v_2498, v_2497);
    v_2497 = v_2497 ? lisp_true : nil;
    env = stack[-2];
    if (v_2497 == nil) goto v_2466;
    goto v_2481;
v_2477:
    v_2498 = stack[0];
    goto v_2478;
v_2479:
    v_2497 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2480;
v_2481:
    goto v_2477;
v_2478:
    goto v_2479;
v_2480:
    return cons(v_2498, v_2497);
v_2466:
    goto v_2493;
v_2487:
    v_2499 = stack[0];
    goto v_2488;
v_2489:
    v_2498 = nil;
    goto v_2490;
v_2491:
    v_2497 = stack[-1];
    goto v_2492;
v_2493:
    goto v_2487;
v_2488:
    goto v_2489;
v_2490:
    goto v_2491;
v_2492:
    {
        fn = elt(env, 2); // exptchk0
        return (*qfnn(fn))(fn, 3, v_2499, v_2498, v_2497);
    }
    v_2497 = nil;
    goto v_2436;
    v_2497 = nil;
v_2436:
    return onevalue(v_2497);
}



// Code for freeindexchk

static LispObject CC_freeindexchk(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2451, v_2452;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_2452 = v_2433;
// end of prologue
    v_2451 = v_2452;
    if (v_2451 == nil) goto v_2438;
    v_2451 = qvalue(elt(env, 1)); // indxl!*
    if (v_2451 == nil) goto v_2438;
    v_2451 = v_2452;
    fn = elt(env, 3); // indxchk
    v_2451 = (*qfn1(fn))(fn, v_2451);
    env = stack[0];
    if (v_2451 == nil) goto v_2438;
    v_2451 = elt(env, 2); // form!-with!-free!-indices
    goto v_2436;
v_2438:
    v_2451 = nil;
    goto v_2436;
    v_2451 = nil;
v_2436:
    return onevalue(v_2451);
}



// Code for areallindices

static LispObject CC_areallindices(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2457;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2433;
// end of prologue
v_2432:
    v_2457 = stack[0];
    v_2457 = qcar(v_2457);
    fn = elt(env, 1); // isanindex
    v_2457 = (*qfn1(fn))(fn, v_2457);
    env = stack[-1];
    if (v_2457 == nil) goto v_2437;
    else goto v_2438;
v_2437:
    v_2457 = nil;
    goto v_2436;
v_2438:
    v_2457 = stack[0];
    v_2457 = qcdr(v_2457);
    if (v_2457 == nil) goto v_2447;
    else goto v_2448;
v_2447:
    v_2457 = lisp_true;
    goto v_2446;
v_2448:
    v_2457 = stack[0];
    v_2457 = qcdr(v_2457);
    stack[0] = v_2457;
    goto v_2432;
    v_2457 = nil;
v_2446:
    goto v_2436;
    v_2457 = nil;
v_2436:
    return onevalue(v_2457);
}



// Code for getel

static LispObject CC_getel(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2488, v_2489, v_2490;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_2433;
// end of prologue
    goto v_2440;
v_2436:
    v_2488 = stack[-1];
    v_2489 = qcar(v_2488);
    goto v_2437;
v_2438:
    v_2488 = elt(env, 1); // dimension
    goto v_2439;
v_2440:
    goto v_2436;
v_2437:
    goto v_2438;
v_2439:
    v_2488 = get(v_2489, v_2488);
    env = stack[-3];
    stack[-2] = v_2488;
    goto v_2453;
v_2449:
    v_2488 = stack[-2];
    stack[0] = Llength(nil, v_2488);
    env = stack[-3];
    goto v_2450;
v_2451:
    v_2488 = stack[-1];
    v_2488 = qcdr(v_2488);
    v_2488 = Llength(nil, v_2488);
    env = stack[-3];
    goto v_2452;
v_2453:
    goto v_2449;
v_2450:
    goto v_2451;
v_2452:
    if (equal(stack[0], v_2488)) goto v_2448;
    goto v_2466;
v_2460:
    v_2490 = elt(env, 2); // rlisp
    goto v_2461;
v_2462:
    v_2489 = (LispObject)336+TAG_FIXNUM; // 21
    goto v_2463;
v_2464:
    v_2488 = elt(env, 3); // "Incorrect array reference"
    goto v_2465;
v_2466:
    goto v_2460;
v_2461:
    goto v_2462;
v_2463:
    goto v_2464;
v_2465:
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_2490, v_2489, v_2488);
    }
v_2448:
    goto v_2479;
v_2473:
    v_2488 = stack[-1];
    v_2488 = qcar(v_2488);
    if (!symbolp(v_2488)) v_2488 = nil;
    else { v_2488 = qfastgets(v_2488);
           if (v_2488 != nil) { v_2488 = elt(v_2488, 4); // avalue
#ifdef RECORD_GET
             if (v_2488 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_2488 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_2488 == SPID_NOPROP) v_2488 = nil; }}
#endif
    v_2488 = qcdr(v_2488);
    v_2490 = qcar(v_2488);
    goto v_2474;
v_2475:
    v_2488 = stack[-1];
    v_2489 = qcdr(v_2488);
    goto v_2476;
v_2477:
    v_2488 = stack[-2];
    goto v_2478;
v_2479:
    goto v_2473;
v_2474:
    goto v_2475;
v_2476:
    goto v_2477;
v_2478:
    {
        fn = elt(env, 5); // getel1
        return (*qfnn(fn))(fn, 3, v_2490, v_2489, v_2488);
    }
    v_2488 = nil;
    return onevalue(v_2488);
}



// Code for mo!=lexcomp

static LispObject CC_moMlexcomp(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2487, v_2488, v_2489, v_2490;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2488 = v_2434;
    v_2489 = v_2433;
// end of prologue
v_2438:
    v_2487 = v_2489;
    if (v_2487 == nil) goto v_2441;
    else goto v_2442;
v_2441:
    v_2487 = v_2488;
    if (v_2487 == nil) goto v_2446;
    else goto v_2447;
v_2446:
    v_2487 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2437;
v_2447:
    v_2487 = elt(env, 1); // (0)
    v_2489 = v_2487;
    goto v_2438;
    goto v_2440;
v_2442:
    v_2487 = v_2488;
    if (v_2487 == nil) goto v_2453;
    else goto v_2454;
v_2453:
    v_2487 = elt(env, 1); // (0)
    v_2488 = v_2487;
    goto v_2438;
v_2454:
    goto v_2463;
v_2459:
    v_2487 = v_2489;
    v_2490 = qcar(v_2487);
    goto v_2460;
v_2461:
    v_2487 = v_2488;
    v_2487 = qcar(v_2487);
    goto v_2462;
v_2463:
    goto v_2459;
v_2460:
    goto v_2461;
v_2462:
    if (equal(v_2490, v_2487)) goto v_2457;
    else goto v_2458;
v_2457:
    v_2487 = v_2489;
    v_2487 = qcdr(v_2487);
    v_2489 = v_2487;
    v_2487 = v_2488;
    v_2487 = qcdr(v_2487);
    v_2488 = v_2487;
    goto v_2438;
v_2458:
    goto v_2478;
v_2474:
    v_2487 = v_2489;
    v_2487 = qcar(v_2487);
    goto v_2475;
v_2476:
    v_2488 = qcar(v_2488);
    goto v_2477;
v_2478:
    goto v_2474;
v_2475:
    goto v_2476;
v_2477:
    if (((intptr_t)(v_2487)) > ((intptr_t)(v_2488))) goto v_2472;
    else goto v_2473;
v_2472:
    v_2487 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2437;
v_2473:
    v_2487 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_2437;
v_2440:
    v_2487 = nil;
v_2437:
    return onevalue(v_2487);
}



// Code for vecp

static LispObject CC_vecp(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2545, v_2546, v_2547, v_2548;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_2547 = v_2433;
// end of prologue
    v_2545 = v_2547;
    if (v_2545 == nil) goto v_2445;
    else goto v_2446;
v_2445:
    v_2545 = lisp_true;
    goto v_2444;
v_2446:
    v_2545 = v_2547;
    v_2545 = (is_number(v_2545) ? lisp_true : nil);
    goto v_2444;
    v_2545 = nil;
v_2444:
    if (v_2545 == nil) goto v_2442;
    v_2545 = nil;
    goto v_2440;
v_2442:
    v_2545 = v_2547;
    if (!consp(v_2545)) goto v_2454;
    else goto v_2455;
v_2454:
    goto v_2465;
v_2461:
    v_2545 = v_2547;
    if (!symbolp(v_2545)) v_2545 = nil;
    else { v_2545 = qfastgets(v_2545);
           if (v_2545 != nil) { v_2545 = elt(v_2545, 2); // rtype
#ifdef RECORD_GET
             if (v_2545 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_2545 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_2545 == SPID_NOPROP) v_2545 = nil; }}
#endif
    goto v_2462;
v_2463:
    v_2546 = elt(env, 2); // !3vector
    goto v_2464;
v_2465:
    goto v_2461;
v_2462:
    goto v_2463;
v_2464:
    if (v_2545 == v_2546) goto v_2459;
    else goto v_2460;
v_2459:
    v_2545 = lisp_true;
    goto v_2458;
v_2460:
    v_2545 = v_2547;
        return Lthreevectorp(nil, v_2545);
    v_2545 = nil;
v_2458:
    goto v_2440;
v_2455:
    v_2545 = v_2547;
    v_2545 = Lthreevectorp(nil, v_2545);
    env = stack[0];
    if (v_2545 == nil) goto v_2475;
    v_2545 = lisp_true;
    goto v_2440;
v_2475:
    v_2545 = v_2547;
    v_2545 = qcar(v_2545);
    v_2548 = v_2545;
    if (!consp(v_2545)) goto v_2483;
    else goto v_2484;
v_2483:
    goto v_2491;
v_2487:
    v_2545 = v_2548;
    if (!symbolp(v_2545)) v_2546 = nil;
    else { v_2546 = qfastgets(v_2545);
           if (v_2546 != nil) { v_2546 = elt(v_2546, 2); // rtype
#ifdef RECORD_GET
             if (v_2546 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_2546 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_2546 == SPID_NOPROP) v_2546 = nil; }}
#endif
    goto v_2488;
v_2489:
    v_2545 = elt(env, 2); // !3vector
    goto v_2490;
v_2491:
    goto v_2487;
v_2488:
    goto v_2489;
v_2490:
    v_2545 = (v_2546 == v_2545 ? lisp_true : nil);
    goto v_2482;
v_2484:
    v_2545 = nil;
    goto v_2482;
    v_2545 = nil;
v_2482:
    if (v_2545 == nil) goto v_2480;
    v_2545 = v_2547;
    v_2545 = qcdr(v_2545);
    v_2545 = qcar(v_2545);
    {
        fn = elt(env, 6); // isvectorindex
        return (*qfn1(fn))(fn, v_2545);
    }
v_2480:
    goto v_2510;
v_2506:
    v_2546 = v_2548;
    goto v_2507;
v_2508:
    v_2545 = elt(env, 3); // vectorfn
    goto v_2509;
v_2510:
    goto v_2506;
v_2507:
    goto v_2508;
v_2509:
    v_2545 = Lflagp(nil, v_2546, v_2545);
    env = stack[0];
    if (v_2545 == nil) goto v_2504;
    v_2545 = lisp_true;
    goto v_2440;
v_2504:
    goto v_2525;
v_2521:
    v_2546 = v_2548;
    goto v_2522;
v_2523:
    v_2545 = elt(env, 4); // varithop
    goto v_2524;
v_2525:
    goto v_2521;
v_2522:
    goto v_2523;
v_2524:
    v_2545 = Lflagp(nil, v_2546, v_2545);
    env = stack[0];
    if (v_2545 == nil) goto v_2519;
    v_2545 = lisp_true;
    goto v_2517;
v_2519:
    goto v_2536;
v_2532:
    v_2546 = v_2548;
    goto v_2533;
v_2534:
    v_2545 = elt(env, 5); // vectormapping
    goto v_2535;
v_2536:
    goto v_2532;
v_2533:
    goto v_2534;
v_2535:
    v_2545 = Lflagp(nil, v_2546, v_2545);
    env = stack[0];
    goto v_2517;
    v_2545 = nil;
v_2517:
    if (v_2545 == nil) goto v_2515;
    v_2545 = v_2547;
    v_2545 = qcdr(v_2545);
    {
        fn = elt(env, 7); // hasonevector
        return (*qfn1(fn))(fn, v_2545);
    }
v_2515:
    v_2545 = nil;
    goto v_2440;
    v_2545 = nil;
v_2440:
    return onevalue(v_2545);
}



// Code for gperm

static LispObject CC_gperm(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2508, v_2509;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_2433;
// end of prologue
    stack[-1] = nil;
v_2441:
    goto v_2451;
v_2447:
    v_2509 = stack[0];
    goto v_2448;
v_2449:
    v_2508 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2450;
v_2451:
    goto v_2447;
v_2448:
    goto v_2449;
v_2450:
    v_2508 = (LispObject)greaterp2(v_2509, v_2508);
    v_2508 = v_2508 ? lisp_true : nil;
    env = stack[-4];
    if (v_2508 == nil) goto v_2444;
    else goto v_2445;
v_2444:
    goto v_2440;
v_2445:
    goto v_2460;
v_2456:
    v_2509 = stack[0];
    goto v_2457;
v_2458:
    v_2508 = stack[-1];
    goto v_2459;
v_2460:
    goto v_2456;
v_2457:
    goto v_2458;
v_2459:
    v_2508 = cons(v_2509, v_2508);
    env = stack[-4];
    stack[-1] = v_2508;
    v_2508 = stack[0];
    v_2508 = sub1(v_2508);
    env = stack[-4];
    stack[0] = v_2508;
    goto v_2441;
v_2440:
    v_2508 = stack[-1];
    fn = elt(env, 2); // gperm0
    v_2508 = (*qfn1(fn))(fn, v_2508);
    env = stack[-4];
    stack[-3] = v_2508;
    v_2508 = stack[-3];
    if (v_2508 == nil) goto v_2475;
    else goto v_2476;
v_2475:
    v_2508 = nil;
    goto v_2469;
v_2476:
    v_2508 = stack[-3];
    v_2508 = qcar(v_2508);
    fn = elt(env, 3); // pkp
    v_2508 = (*qfn1(fn))(fn, v_2508);
    env = stack[-4];
    v_2508 = ncons(v_2508);
    env = stack[-4];
    stack[-1] = v_2508;
    stack[-2] = v_2508;
v_2470:
    v_2508 = stack[-3];
    v_2508 = qcdr(v_2508);
    stack[-3] = v_2508;
    v_2508 = stack[-3];
    if (v_2508 == nil) goto v_2489;
    else goto v_2490;
v_2489:
    v_2508 = stack[-2];
    goto v_2469;
v_2490:
    goto v_2498;
v_2494:
    stack[0] = stack[-1];
    goto v_2495;
v_2496:
    v_2508 = stack[-3];
    v_2508 = qcar(v_2508);
    fn = elt(env, 3); // pkp
    v_2508 = (*qfn1(fn))(fn, v_2508);
    env = stack[-4];
    v_2508 = ncons(v_2508);
    env = stack[-4];
    goto v_2497;
v_2498:
    goto v_2494;
v_2495:
    goto v_2496;
v_2497:
    v_2508 = Lrplacd(nil, stack[0], v_2508);
    env = stack[-4];
    v_2508 = stack[-1];
    v_2508 = qcdr(v_2508);
    stack[-1] = v_2508;
    goto v_2470;
v_2469:
    return onevalue(v_2508);
}



// Code for times!-mod!-p

static LispObject CC_timesKmodKp(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2651, v_2652, v_2653;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2433,v_2434);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_2434;
    stack[-1] = v_2433;
// end of prologue
    v_2651 = stack[-1];
    if (v_2651 == nil) goto v_2442;
    else goto v_2443;
v_2442:
    v_2651 = lisp_true;
    goto v_2441;
v_2443:
    v_2651 = stack[0];
    v_2651 = (v_2651 == nil ? lisp_true : nil);
    goto v_2441;
    v_2651 = nil;
v_2441:
    if (v_2651 == nil) goto v_2439;
    v_2651 = nil;
    goto v_2437;
v_2439:
    v_2651 = stack[-1];
    if (!consp(v_2651)) goto v_2455;
    else goto v_2456;
v_2455:
    v_2651 = lisp_true;
    goto v_2454;
v_2456:
    v_2651 = stack[-1];
    v_2651 = qcar(v_2651);
    v_2651 = (consp(v_2651) ? nil : lisp_true);
    goto v_2454;
    v_2651 = nil;
v_2454:
    if (v_2651 == nil) goto v_2452;
    goto v_2469;
v_2465:
    v_2652 = stack[0];
    goto v_2466;
v_2467:
    v_2651 = stack[-1];
    goto v_2468;
v_2469:
    goto v_2465;
v_2466:
    goto v_2467;
v_2468:
    {
        fn = elt(env, 1); // multiply!-by!-constant!-mod!-p
        return (*qfn2(fn))(fn, v_2652, v_2651);
    }
v_2452:
    v_2651 = stack[0];
    if (!consp(v_2651)) goto v_2476;
    else goto v_2477;
v_2476:
    v_2651 = lisp_true;
    goto v_2475;
v_2477:
    v_2651 = stack[0];
    v_2651 = qcar(v_2651);
    v_2651 = (consp(v_2651) ? nil : lisp_true);
    goto v_2475;
    v_2651 = nil;
v_2475:
    if (v_2651 == nil) goto v_2473;
    goto v_2490;
v_2486:
    v_2652 = stack[-1];
    goto v_2487;
v_2488:
    v_2651 = stack[0];
    goto v_2489;
v_2490:
    goto v_2486;
v_2487:
    goto v_2488;
v_2489:
    {
        fn = elt(env, 1); // multiply!-by!-constant!-mod!-p
        return (*qfn2(fn))(fn, v_2652, v_2651);
    }
v_2473:
    goto v_2499;
v_2495:
    v_2651 = stack[-1];
    v_2651 = qcar(v_2651);
    v_2651 = qcar(v_2651);
    v_2652 = qcar(v_2651);
    goto v_2496;
v_2497:
    v_2651 = stack[0];
    v_2651 = qcar(v_2651);
    v_2651 = qcar(v_2651);
    v_2651 = qcar(v_2651);
    goto v_2498;
v_2499:
    goto v_2495;
v_2496:
    goto v_2497;
v_2498:
    if (equal(v_2652, v_2651)) goto v_2493;
    else goto v_2494;
v_2493:
    goto v_2513;
v_2509:
    goto v_2519;
v_2515:
    goto v_2525;
v_2521:
    v_2651 = stack[-1];
    v_2652 = qcar(v_2651);
    goto v_2522;
v_2523:
    v_2651 = stack[0];
    goto v_2524;
v_2525:
    goto v_2521;
v_2522:
    goto v_2523;
v_2524:
    fn = elt(env, 2); // times!-term!-mod!-p
    stack[-2] = (*qfn2(fn))(fn, v_2652, v_2651);
    env = stack[-3];
    goto v_2516;
v_2517:
    goto v_2534;
v_2530:
    v_2651 = stack[0];
    v_2652 = qcar(v_2651);
    goto v_2531;
v_2532:
    v_2651 = stack[-1];
    v_2651 = qcdr(v_2651);
    goto v_2533;
v_2534:
    goto v_2530;
v_2531:
    goto v_2532;
v_2533:
    fn = elt(env, 2); // times!-term!-mod!-p
    v_2651 = (*qfn2(fn))(fn, v_2652, v_2651);
    env = stack[-3];
    goto v_2518;
v_2519:
    goto v_2515;
v_2516:
    goto v_2517;
v_2518:
    fn = elt(env, 3); // plus!-mod!-p
    stack[-2] = (*qfn2(fn))(fn, stack[-2], v_2651);
    env = stack[-3];
    goto v_2510;
v_2511:
    goto v_2544;
v_2540:
    v_2651 = stack[-1];
    v_2652 = qcdr(v_2651);
    goto v_2541;
v_2542:
    v_2651 = stack[0];
    v_2651 = qcdr(v_2651);
    goto v_2543;
v_2544:
    goto v_2540;
v_2541:
    goto v_2542;
v_2543:
    v_2651 = CC_timesKmodKp(elt(env, 0), v_2652, v_2651);
    env = stack[-3];
    goto v_2512;
v_2513:
    goto v_2509;
v_2510:
    goto v_2511;
v_2512:
    {
        LispObject v_2657 = stack[-2];
        fn = elt(env, 3); // plus!-mod!-p
        return (*qfn2(fn))(fn, v_2657, v_2651);
    }
v_2494:
    goto v_2556;
v_2552:
    v_2651 = stack[-1];
    v_2651 = qcar(v_2651);
    v_2651 = qcar(v_2651);
    v_2652 = qcar(v_2651);
    goto v_2553;
v_2554:
    v_2651 = stack[0];
    v_2651 = qcar(v_2651);
    v_2651 = qcar(v_2651);
    v_2651 = qcar(v_2651);
    goto v_2555;
v_2556:
    goto v_2552;
v_2553:
    goto v_2554;
v_2555:
    fn = elt(env, 4); // ordop
    v_2651 = (*qfn2(fn))(fn, v_2652, v_2651);
    env = stack[-3];
    if (v_2651 == nil) goto v_2550;
    goto v_2570;
v_2566:
    v_2651 = stack[-1];
    v_2651 = qcar(v_2651);
    v_2652 = qcdr(v_2651);
    goto v_2567;
v_2568:
    v_2651 = stack[0];
    goto v_2569;
v_2570:
    goto v_2566;
v_2567:
    goto v_2568;
v_2569:
    stack[-2] = CC_timesKmodKp(elt(env, 0), v_2652, v_2651);
    env = stack[-3];
    goto v_2580;
v_2576:
    v_2651 = stack[-1];
    v_2652 = qcdr(v_2651);
    goto v_2577;
v_2578:
    v_2651 = stack[0];
    goto v_2579;
v_2580:
    goto v_2576;
v_2577:
    goto v_2578;
v_2579:
    v_2651 = CC_timesKmodKp(elt(env, 0), v_2652, v_2651);
    v_2652 = stack[-2];
    v_2653 = v_2652;
    if (v_2653 == nil) goto v_2588;
    else goto v_2589;
v_2588:
    goto v_2587;
v_2589:
    goto v_2601;
v_2595:
    v_2653 = stack[-1];
    v_2653 = qcar(v_2653);
    v_2653 = qcar(v_2653);
    goto v_2596;
v_2597:
    goto v_2598;
v_2599:
    goto v_2600;
v_2601:
    goto v_2595;
v_2596:
    goto v_2597;
v_2598:
    goto v_2599;
v_2600:
    return acons(v_2653, v_2652, v_2651);
    v_2651 = nil;
v_2587:
    goto v_2437;
v_2550:
    goto v_2614;
v_2610:
    v_2652 = stack[-1];
    goto v_2611;
v_2612:
    v_2651 = stack[0];
    v_2651 = qcar(v_2651);
    v_2651 = qcdr(v_2651);
    goto v_2613;
v_2614:
    goto v_2610;
v_2611:
    goto v_2612;
v_2613:
    stack[-2] = CC_timesKmodKp(elt(env, 0), v_2652, v_2651);
    env = stack[-3];
    goto v_2624;
v_2620:
    v_2652 = stack[-1];
    goto v_2621;
v_2622:
    v_2651 = stack[0];
    v_2651 = qcdr(v_2651);
    goto v_2623;
v_2624:
    goto v_2620;
v_2621:
    goto v_2622;
v_2623:
    v_2651 = CC_timesKmodKp(elt(env, 0), v_2652, v_2651);
    v_2652 = stack[-2];
    v_2653 = v_2652;
    if (v_2653 == nil) goto v_2632;
    else goto v_2633;
v_2632:
    goto v_2631;
v_2633:
    goto v_2645;
v_2639:
    v_2653 = stack[0];
    v_2653 = qcar(v_2653);
    v_2653 = qcar(v_2653);
    goto v_2640;
v_2641:
    goto v_2642;
v_2643:
    goto v_2644;
v_2645:
    goto v_2639;
v_2640:
    goto v_2641;
v_2642:
    goto v_2643;
v_2644:
    return acons(v_2653, v_2652, v_2651);
    v_2651 = nil;
v_2631:
    goto v_2437;
    v_2651 = nil;
v_2437:
    return onevalue(v_2651);
}



// Code for prin2t

static LispObject CC_prin2t(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2439;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2433;
// end of prologue
    v_2439 = stack[0];
    v_2439 = Lprinc(nil, v_2439);
    env = stack[-1];
    v_2439 = Lterpri(nil, 0);
    v_2439 = stack[0];
    return onevalue(v_2439);
}



// Code for wulessp

static LispObject CC_wulessp(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2541;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2433,v_2434);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_2434;
    stack[-1] = v_2433;
// end of prologue
    goto v_2444;
v_2440:
    v_2541 = stack[-1];
    fn = elt(env, 1); // wuconstantp
    v_2541 = (*qfn1(fn))(fn, v_2541);
    env = stack[-3];
    if (v_2541 == nil) goto v_2448;
    v_2541 = nil;
    stack[-2] = v_2541;
    goto v_2446;
v_2448:
    v_2541 = stack[-1];
    v_2541 = qcar(v_2541);
    v_2541 = qcar(v_2541);
    v_2541 = qcar(v_2541);
    stack[-2] = v_2541;
    goto v_2446;
    stack[-2] = nil;
v_2446:
    goto v_2441;
v_2442:
    v_2541 = stack[0];
    fn = elt(env, 1); // wuconstantp
    v_2541 = (*qfn1(fn))(fn, v_2541);
    env = stack[-3];
    if (v_2541 == nil) goto v_2461;
    v_2541 = nil;
    goto v_2459;
v_2461:
    v_2541 = stack[0];
    v_2541 = qcar(v_2541);
    v_2541 = qcar(v_2541);
    v_2541 = qcar(v_2541);
    goto v_2459;
    v_2541 = nil;
v_2459:
    goto v_2443;
v_2444:
    goto v_2440;
v_2441:
    goto v_2442;
v_2443:
    fn = elt(env, 2); // symbollessp
    v_2541 = (*qfn2(fn))(fn, stack[-2], v_2541);
    env = stack[-3];
    if (v_2541 == nil) goto v_2438;
    else goto v_2437;
v_2438:
    goto v_2479;
v_2475:
    v_2541 = stack[-1];
    fn = elt(env, 1); // wuconstantp
    v_2541 = (*qfn1(fn))(fn, v_2541);
    env = stack[-3];
    if (v_2541 == nil) goto v_2483;
    v_2541 = nil;
    stack[-2] = v_2541;
    goto v_2481;
v_2483:
    v_2541 = stack[-1];
    v_2541 = qcar(v_2541);
    v_2541 = qcar(v_2541);
    v_2541 = qcar(v_2541);
    stack[-2] = v_2541;
    goto v_2481;
    stack[-2] = nil;
v_2481:
    goto v_2476;
v_2477:
    v_2541 = stack[0];
    fn = elt(env, 1); // wuconstantp
    v_2541 = (*qfn1(fn))(fn, v_2541);
    env = stack[-3];
    if (v_2541 == nil) goto v_2496;
    v_2541 = nil;
    goto v_2494;
v_2496:
    v_2541 = stack[0];
    v_2541 = qcar(v_2541);
    v_2541 = qcar(v_2541);
    v_2541 = qcar(v_2541);
    goto v_2494;
    v_2541 = nil;
v_2494:
    goto v_2478;
v_2479:
    goto v_2475;
v_2476:
    goto v_2477;
v_2478:
    if (equal(stack[-2], v_2541)) goto v_2473;
    else goto v_2474;
v_2473:
    goto v_2511;
v_2507:
    v_2541 = stack[-1];
    fn = elt(env, 1); // wuconstantp
    v_2541 = (*qfn1(fn))(fn, v_2541);
    env = stack[-3];
    if (v_2541 == nil) goto v_2515;
    v_2541 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_2541;
    goto v_2513;
v_2515:
    v_2541 = stack[-1];
    v_2541 = qcar(v_2541);
    v_2541 = qcar(v_2541);
    v_2541 = qcdr(v_2541);
    stack[-1] = v_2541;
    goto v_2513;
    stack[-1] = nil;
v_2513:
    goto v_2508;
v_2509:
    v_2541 = stack[0];
    fn = elt(env, 1); // wuconstantp
    v_2541 = (*qfn1(fn))(fn, v_2541);
    if (v_2541 == nil) goto v_2528;
    v_2541 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2526;
v_2528:
    v_2541 = stack[0];
    v_2541 = qcar(v_2541);
    v_2541 = qcar(v_2541);
    v_2541 = qcdr(v_2541);
    goto v_2526;
    v_2541 = nil;
v_2526:
    goto v_2510;
v_2511:
    goto v_2507;
v_2508:
    goto v_2509;
v_2510:
    {
        LispObject v_2545 = stack[-1];
        return Llessp(nil, v_2545, v_2541);
    }
v_2474:
    v_2541 = nil;
    goto v_2472;
    v_2541 = nil;
v_2472:
v_2437:
    return onevalue(v_2541);
}



// Code for talp_varlt1

static LispObject CC_talp_varlt1(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2500, v_2501;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2433,v_2434);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_2434;
    stack[-1] = v_2433;
// end of prologue
    v_2500 = stack[-1];
    if (!consp(v_2500)) goto v_2441;
    else goto v_2442;
v_2441:
    goto v_2452;
v_2448:
    stack[-2] = stack[-1];
    goto v_2449;
v_2450:
    fn = elt(env, 1); // talp_getl
    v_2500 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_2451;
v_2452:
    goto v_2448;
v_2449:
    goto v_2450;
v_2451:
    v_2500 = Latsoc(nil, stack[-2], v_2500);
    if (v_2500 == nil) goto v_2446;
    else goto v_2447;
v_2446:
    goto v_2461;
v_2457:
    v_2501 = stack[-1];
    goto v_2458;
v_2459:
    v_2500 = stack[0];
    goto v_2460;
v_2461:
    goto v_2457;
v_2458:
    goto v_2459;
v_2460:
    {
        fn = elt(env, 2); // lto_insert
        return (*qfn2(fn))(fn, v_2501, v_2500);
    }
v_2447:
    v_2500 = nil;
    goto v_2437;
    goto v_2440;
v_2442:
v_2440:
    v_2500 = stack[-1];
    fn = elt(env, 3); // talp_argl
    v_2500 = (*qfn1(fn))(fn, v_2500);
    env = stack[-3];
    stack[-1] = v_2500;
v_2470:
    v_2500 = stack[-1];
    if (v_2500 == nil) goto v_2475;
    else goto v_2476;
v_2475:
    goto v_2469;
v_2476:
    v_2500 = stack[-1];
    v_2500 = qcar(v_2500);
    goto v_2487;
v_2483:
    goto v_2493;
v_2489:
    v_2501 = v_2500;
    goto v_2490;
v_2491:
    v_2500 = stack[0];
    goto v_2492;
v_2493:
    goto v_2489;
v_2490:
    goto v_2491;
v_2492:
    v_2501 = CC_talp_varlt1(elt(env, 0), v_2501, v_2500);
    env = stack[-3];
    goto v_2484;
v_2485:
    v_2500 = stack[0];
    goto v_2486;
v_2487:
    goto v_2483;
v_2484:
    goto v_2485;
v_2486:
    fn = elt(env, 4); // union
    v_2500 = (*qfn2(fn))(fn, v_2501, v_2500);
    env = stack[-3];
    stack[0] = v_2500;
    v_2500 = stack[-1];
    v_2500 = qcdr(v_2500);
    stack[-1] = v_2500;
    goto v_2470;
v_2469:
    v_2500 = stack[0];
v_2437:
    return onevalue(v_2500);
}



// Code for mri_type

static LispObject CC_mri_type(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2451, v_2452;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2451 = v_2433;
// end of prologue
    v_2452 = v_2451;
    v_2452 = qcdr(v_2452);
    v_2452 = qcdr(v_2452);
    v_2452 = qcdr(v_2452);
    if (v_2452 == nil) goto v_2437;
    else goto v_2438;
v_2437:
    v_2451 = nil;
    goto v_2436;
v_2438:
    v_2451 = qcdr(v_2451);
    v_2451 = qcdr(v_2451);
    v_2451 = qcdr(v_2451);
    v_2451 = qcar(v_2451);
    goto v_2436;
    v_2451 = nil;
v_2436:
    return onevalue(v_2451);
}



// Code for qqe_prepat

static LispObject CC_qqe_prepat(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2436;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2436 = v_2433;
// end of prologue
    return onevalue(v_2436);
}



// Code for ev_invlexcomp

static LispObject CC_ev_invlexcomp(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2523, v_2524;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2433,v_2434);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_2434;
    stack[-1] = v_2433;
// end of prologue
v_2432:
    v_2523 = stack[-1];
    if (v_2523 == nil) goto v_2442;
    else goto v_2443;
v_2442:
    v_2523 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2438;
v_2443:
    goto v_2455;
v_2451:
    v_2523 = stack[-1];
    v_2524 = qcar(v_2523);
    goto v_2452;
v_2453:
    v_2523 = stack[0];
    v_2523 = qcar(v_2523);
    goto v_2454;
v_2455:
    goto v_2451;
v_2452:
    goto v_2453;
v_2454:
    fn = elt(env, 2); // iequal
    v_2523 = (*qfn2(fn))(fn, v_2524, v_2523);
    env = stack[-3];
    if (v_2523 == nil) goto v_2449;
    goto v_2465;
v_2461:
    v_2523 = stack[-1];
    v_2524 = qcdr(v_2523);
    goto v_2462;
v_2463:
    v_2523 = stack[0];
    v_2523 = qcdr(v_2523);
    goto v_2464;
v_2465:
    goto v_2461;
v_2462:
    goto v_2463;
v_2464:
    stack[-1] = v_2524;
    stack[0] = v_2523;
    goto v_2432;
v_2449:
    goto v_2475;
v_2471:
    v_2523 = stack[-1];
    v_2524 = qcdr(v_2523);
    goto v_2472;
v_2473:
    v_2523 = stack[0];
    v_2523 = qcdr(v_2523);
    goto v_2474;
v_2475:
    goto v_2471;
v_2472:
    goto v_2473;
v_2474:
    v_2523 = CC_ev_invlexcomp(elt(env, 0), v_2524, v_2523);
    env = stack[-3];
    stack[-2] = v_2523;
    goto v_2489;
v_2485:
    v_2524 = stack[-2];
    goto v_2486;
v_2487:
    v_2523 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2488;
v_2489:
    goto v_2485;
v_2486:
    goto v_2487;
v_2488:
    fn = elt(env, 2); // iequal
    v_2523 = (*qfn2(fn))(fn, v_2524, v_2523);
    env = stack[-3];
    if (v_2523 == nil) goto v_2482;
    else goto v_2483;
v_2482:
    v_2523 = stack[-2];
    goto v_2438;
v_2483:
    goto v_2502;
v_2498:
    v_2523 = stack[0];
    v_2524 = qcar(v_2523);
    goto v_2499;
v_2500:
    v_2523 = stack[-1];
    v_2523 = qcar(v_2523);
    goto v_2501;
v_2502:
    goto v_2498;
v_2499:
    goto v_2500;
v_2501:
    fn = elt(env, 2); // iequal
    v_2523 = (*qfn2(fn))(fn, v_2524, v_2523);
    if (v_2523 == nil) goto v_2496;
    v_2523 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2438;
v_2496:
    goto v_2516;
v_2512:
    v_2523 = stack[0];
    v_2524 = qcar(v_2523);
    goto v_2513;
v_2514:
    v_2523 = stack[-1];
    v_2523 = qcar(v_2523);
    goto v_2515;
v_2516:
    goto v_2512;
v_2513:
    goto v_2514;
v_2515:
    if (((intptr_t)(v_2524)) > ((intptr_t)(v_2523))) goto v_2510;
    else goto v_2511;
v_2510:
    v_2523 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2438;
v_2511:
    v_2523 = (LispObject)-16+TAG_FIXNUM; // -1
v_2438:
    return onevalue(v_2523);
}



// Code for diplength

static LispObject CC_diplength(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2476, v_2477;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2433;
// end of prologue
    stack[-1] = nil;
v_2439:
    v_2476 = stack[0];
    if (v_2476 == nil) goto v_2444;
    else goto v_2445;
v_2444:
    goto v_2440;
v_2445:
    goto v_2452;
v_2448:
    v_2477 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2449;
v_2450:
    v_2476 = stack[-1];
    goto v_2451;
v_2452:
    goto v_2448;
v_2449:
    goto v_2450;
v_2451:
    v_2476 = cons(v_2477, v_2476);
    env = stack[-2];
    stack[-1] = v_2476;
    v_2476 = stack[0];
    v_2476 = qcdr(v_2476);
    v_2476 = qcdr(v_2476);
    stack[0] = v_2476;
    goto v_2439;
v_2440:
    v_2476 = (LispObject)0+TAG_FIXNUM; // 0
    v_2477 = v_2476;
v_2441:
    v_2476 = stack[-1];
    if (v_2476 == nil) goto v_2461;
    else goto v_2462;
v_2461:
    v_2476 = v_2477;
    goto v_2438;
v_2462:
    goto v_2470;
v_2466:
    v_2476 = stack[-1];
    v_2476 = qcar(v_2476);
    goto v_2467;
v_2468:
    goto v_2469;
v_2470:
    goto v_2466;
v_2467:
    goto v_2468;
v_2469:
    v_2476 = plus2(v_2476, v_2477);
    env = stack[-2];
    v_2477 = v_2476;
    v_2476 = stack[-1];
    v_2476 = qcdr(v_2476);
    stack[-1] = v_2476;
    goto v_2441;
v_2438:
    return onevalue(v_2476);
}



// Code for boundindp

static LispObject CC_boundindp(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2465, v_2466, v_2467, v_2468;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2466 = v_2434;
    v_2467 = v_2433;
// end of prologue
v_2438:
    v_2465 = v_2467;
    if (v_2465 == nil) goto v_2441;
    else goto v_2442;
v_2441:
    v_2465 = lisp_true;
    goto v_2437;
v_2442:
    goto v_2455;
v_2451:
    v_2465 = v_2467;
    v_2468 = qcar(v_2465);
    goto v_2452;
v_2453:
    v_2465 = v_2466;
    goto v_2454;
v_2455:
    goto v_2451;
v_2452:
    goto v_2453;
v_2454:
    v_2465 = Lmember(nil, v_2468, v_2465);
    if (v_2465 == nil) goto v_2450;
    v_2465 = v_2467;
    v_2465 = qcdr(v_2465);
    v_2467 = v_2465;
    goto v_2438;
v_2450:
    v_2465 = nil;
    goto v_2437;
    goto v_2440;
v_2440:
    v_2465 = nil;
v_2437:
    return onevalue(v_2465);
}



// Code for round!:mt

static LispObject CC_roundTmt(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2556, v_2557;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2433,v_2434);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_2434;
    stack[-2] = v_2433;
// end of prologue
    goto v_2453;
v_2449:
    v_2557 = stack[-2];
    goto v_2450;
v_2451:
    v_2556 = elt(env, 1); // !:rd!:
    goto v_2452;
v_2453:
    goto v_2449;
v_2450:
    goto v_2451;
v_2452:
    if (!consp(v_2557)) goto v_2447;
    v_2557 = qcar(v_2557);
    if (v_2557 == v_2556) goto v_2446;
    else goto v_2447;
v_2446:
    v_2556 = stack[-2];
    v_2556 = qcdr(v_2556);
    v_2556 = (consp(v_2556) ? nil : lisp_true);
    v_2556 = (v_2556 == nil ? lisp_true : nil);
    goto v_2445;
v_2447:
    v_2556 = nil;
    goto v_2445;
    v_2556 = nil;
v_2445:
    if (v_2556 == nil) goto v_2443;
    v_2556 = stack[-1];
    v_2556 = integerp(v_2556);
    if (v_2556 == nil) goto v_2465;
    else goto v_2466;
v_2465:
    v_2556 = nil;
    goto v_2464;
v_2466:
    goto v_2477;
v_2473:
    v_2557 = stack[-1];
    goto v_2474;
v_2475:
    v_2556 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2476;
v_2477:
    goto v_2473;
v_2474:
    goto v_2475;
v_2476:
    v_2556 = (LispObject)greaterp2(v_2557, v_2556);
    v_2556 = v_2556 ? lisp_true : nil;
    env = stack[-4];
    goto v_2464;
    v_2556 = nil;
v_2464:
    goto v_2441;
v_2443:
    v_2556 = nil;
    goto v_2441;
    v_2556 = nil;
v_2441:
    if (v_2556 == nil) goto v_2439;
    goto v_2492;
v_2488:
    goto v_2499;
v_2495:
    v_2556 = stack[-2];
    v_2556 = qcdr(v_2556);
    v_2556 = qcar(v_2556);
    v_2556 = Labsval(nil, v_2556);
    env = stack[-4];
    fn = elt(env, 2); // msd
    v_2557 = (*qfn1(fn))(fn, v_2556);
    env = stack[-4];
    goto v_2496;
v_2497:
    v_2556 = stack[-1];
    goto v_2498;
v_2499:
    goto v_2495;
v_2496:
    goto v_2497;
v_2498:
    v_2556 = difference2(v_2557, v_2556);
    env = stack[-4];
    v_2557 = sub1(v_2556);
    env = stack[-4];
    stack[-1] = v_2557;
    goto v_2489;
v_2490:
    v_2556 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2491;
v_2492:
    goto v_2488;
v_2489:
    goto v_2490;
v_2491:
    v_2556 = (LispObject)lessp2(v_2557, v_2556);
    v_2556 = v_2556 ? lisp_true : nil;
    env = stack[-4];
    if (v_2556 == nil) goto v_2486;
    v_2556 = stack[-2];
    goto v_2484;
v_2486:
    goto v_2514;
v_2510:
    v_2557 = stack[-1];
    goto v_2511;
v_2512:
    v_2556 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2513;
v_2514:
    goto v_2510;
v_2511:
    goto v_2512;
v_2513:
    if (v_2557 == v_2556) goto v_2508;
    else goto v_2509;
v_2508:
    v_2556 = stack[-2];
    {
        fn = elt(env, 3); // round!:last
        return (*qfn1(fn))(fn, v_2556);
    }
v_2509:
    goto v_2529;
v_2523:
    stack[-3] = elt(env, 1); // !:rd!:
    goto v_2524;
v_2525:
    goto v_2536;
v_2532:
    v_2556 = stack[-2];
    v_2556 = qcdr(v_2556);
    stack[0] = qcar(v_2556);
    goto v_2533;
v_2534:
    v_2556 = stack[-1];
    v_2556 = negate(v_2556);
    env = stack[-4];
    goto v_2535;
v_2536:
    goto v_2532;
v_2533:
    goto v_2534;
v_2535:
    fn = elt(env, 4); // ashift
    stack[0] = (*qfn2(fn))(fn, stack[0], v_2556);
    env = stack[-4];
    goto v_2526;
v_2527:
    goto v_2547;
v_2543:
    v_2556 = stack[-2];
    v_2556 = qcdr(v_2556);
    v_2557 = qcdr(v_2556);
    goto v_2544;
v_2545:
    v_2556 = stack[-1];
    goto v_2546;
v_2547:
    goto v_2543;
v_2544:
    goto v_2545;
v_2546:
    v_2556 = plus2(v_2557, v_2556);
    env = stack[-4];
    goto v_2528;
v_2529:
    goto v_2523;
v_2524:
    goto v_2525;
v_2526:
    goto v_2527;
v_2528:
    v_2556 = list2star(stack[-3], stack[0], v_2556);
    env = stack[-4];
    {
        fn = elt(env, 3); // round!:last
        return (*qfn1(fn))(fn, v_2556);
    }
    v_2556 = nil;
v_2484:
    goto v_2437;
v_2439:
    v_2556 = elt(env, 0); // round!:mt
    {
        fn = elt(env, 5); // bflerrmsg
        return (*qfn1(fn))(fn, v_2556);
    }
    v_2556 = nil;
v_2437:
    return onevalue(v_2556);
}



// Code for physopp!*

static LispObject CC_physoppH(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2505, v_2506;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2433;
// end of prologue
    v_2505 = stack[0];
    fn = elt(env, 4); // physopp
    v_2505 = (*qfn1(fn))(fn, v_2505);
    env = stack[-1];
    if (v_2505 == nil) goto v_2437;
    else goto v_2436;
v_2437:
    v_2505 = stack[0];
    if (!consp(v_2505)) goto v_2443;
    goto v_2454;
v_2450:
    v_2505 = stack[0];
    v_2506 = qcar(v_2505);
    goto v_2451;
v_2452:
    v_2505 = elt(env, 1); // physopfn
    goto v_2453;
v_2454:
    goto v_2450;
v_2451:
    goto v_2452;
v_2453:
    v_2505 = Lflagp(nil, v_2506, v_2505);
    env = stack[-1];
    if (v_2505 == nil) goto v_2448;
    v_2505 = lisp_true;
    goto v_2446;
v_2448:
    goto v_2473;
v_2469:
    v_2505 = stack[0];
    v_2506 = qcar(v_2505);
    goto v_2470;
v_2471:
    v_2505 = elt(env, 2); // physoparith
    goto v_2472;
v_2473:
    goto v_2469;
v_2470:
    goto v_2471;
v_2472:
    v_2505 = Lflagp(nil, v_2506, v_2505);
    env = stack[-1];
    if (v_2505 == nil) goto v_2467;
    v_2505 = stack[0];
    v_2505 = qcdr(v_2505);
    fn = elt(env, 5); // hasonephysop
    v_2505 = (*qfn1(fn))(fn, v_2505);
    env = stack[-1];
    goto v_2465;
v_2467:
    v_2505 = nil;
    goto v_2465;
    v_2505 = nil;
v_2465:
    if (v_2505 == nil) goto v_2463;
    else goto v_2462;
v_2463:
    goto v_2492;
v_2488:
    v_2505 = stack[0];
    v_2506 = qcar(v_2505);
    goto v_2489;
v_2490:
    v_2505 = elt(env, 3); // physopmapping
    goto v_2491;
v_2492:
    goto v_2488;
v_2489:
    goto v_2490;
v_2491:
    v_2505 = Lflagp(nil, v_2506, v_2505);
    env = stack[-1];
    if (v_2505 == nil) goto v_2486;
    v_2505 = stack[0];
    v_2505 = qcdr(v_2505);
    {
        fn = elt(env, 5); // hasonephysop
        return (*qfn1(fn))(fn, v_2505);
    }
v_2486:
    v_2505 = nil;
    goto v_2484;
    v_2505 = nil;
v_2484:
v_2462:
    goto v_2446;
    v_2505 = nil;
v_2446:
    goto v_2441;
v_2443:
    v_2505 = nil;
    goto v_2441;
    v_2505 = nil;
v_2441:
v_2436:
    return onevalue(v_2505);
}



// Code for getrmacro

static LispObject CC_getrmacro(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2499, v_2500, v_2501;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2433;
// end of prologue
    v_2499 = stack[0];
    if (symbolp(v_2499)) goto v_2442;
    v_2499 = nil;
    goto v_2440;
v_2442:
    v_2499 = stack[0];
    fn = elt(env, 5); // getd
    v_2499 = (*qfn1(fn))(fn, v_2499);
    env = stack[-1];
    v_2501 = v_2499;
    if (v_2499 == nil) goto v_2446;
    goto v_2455;
v_2451:
    v_2499 = v_2501;
    v_2500 = qcar(v_2499);
    goto v_2452;
v_2453:
    v_2499 = elt(env, 2); // macro
    goto v_2454;
v_2455:
    goto v_2451;
v_2452:
    goto v_2453;
v_2454:
    if (v_2500 == v_2499) goto v_2450;
    else goto v_2446;
v_2450:
    v_2499 = v_2501;
    goto v_2440;
v_2446:
    goto v_2467;
v_2463:
    v_2500 = stack[0];
    goto v_2464;
v_2465:
    v_2499 = elt(env, 3); // inline
    goto v_2466;
v_2467:
    goto v_2463;
v_2464:
    goto v_2465;
v_2466:
    v_2499 = get(v_2500, v_2499);
    env = stack[-1];
    v_2501 = v_2499;
    if (v_2499 == nil) goto v_2461;
    goto v_2475;
v_2471:
    v_2499 = elt(env, 3); // inline
    goto v_2472;
v_2473:
    v_2500 = v_2501;
    goto v_2474;
v_2475:
    goto v_2471;
v_2472:
    goto v_2473;
v_2474:
    return cons(v_2499, v_2500);
v_2461:
    goto v_2485;
v_2481:
    v_2500 = stack[0];
    goto v_2482;
v_2483:
    v_2499 = elt(env, 4); // smacro
    goto v_2484;
v_2485:
    goto v_2481;
v_2482:
    goto v_2483;
v_2484:
    v_2499 = get(v_2500, v_2499);
    env = stack[-1];
    v_2501 = v_2499;
    if (v_2499 == nil) goto v_2479;
    goto v_2493;
v_2489:
    v_2499 = elt(env, 4); // smacro
    goto v_2490;
v_2491:
    v_2500 = v_2501;
    goto v_2492;
v_2493:
    goto v_2489;
v_2490:
    goto v_2491;
v_2492:
    return cons(v_2499, v_2500);
v_2479:
    v_2499 = nil;
    goto v_2440;
    v_2499 = nil;
v_2440:
    return onevalue(v_2499);
}



// Code for red!-weight

static LispObject CC_redKweight(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2452, v_2453;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2433,v_2434);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_2434;
    stack[-1] = v_2433;
// end of prologue
    goto v_2441;
v_2437:
    v_2452 = stack[-1];
    fn = elt(env, 1); // nonzero!-length
    stack[-2] = (*qfn1(fn))(fn, v_2452);
    env = stack[-3];
    goto v_2438;
v_2439:
    goto v_2449;
v_2445:
    v_2453 = stack[-1];
    goto v_2446;
v_2447:
    v_2452 = stack[0];
    goto v_2448;
v_2449:
    goto v_2445;
v_2446:
    goto v_2447;
v_2448:
    fn = elt(env, 2); // red!-weight1
    v_2452 = (*qfn2(fn))(fn, v_2453, v_2452);
    goto v_2440;
v_2441:
    goto v_2437;
v_2438:
    goto v_2439;
v_2440:
    {
        LispObject v_2457 = stack[-2];
        return cons(v_2457, v_2452);
    }
}



// Code for red_divtestbe

static LispObject CC_red_divtestbe(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2477, v_2478;
    LispObject fn;
    LispObject v_2435, v_2434, v_2433;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "red_divtestbe");
    va_start(aa, nargs);
    v_2433 = va_arg(aa, LispObject);
    v_2434 = va_arg(aa, LispObject);
    v_2435 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_2435,v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_2433,v_2434,v_2435);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_2435;
    stack[-1] = v_2434;
    stack[-2] = v_2433;
// end of prologue
v_2439:
    v_2477 = stack[-2];
    if (v_2477 == nil) goto v_2442;
    else goto v_2443;
v_2442:
    v_2477 = nil;
    goto v_2438;
v_2443:
    goto v_2454;
v_2450:
    v_2477 = stack[-2];
    v_2477 = qcar(v_2477);
    fn = elt(env, 1); // bas_dpecart
    v_2478 = (*qfn1(fn))(fn, v_2477);
    env = stack[-3];
    goto v_2451;
v_2452:
    v_2477 = stack[0];
    goto v_2453;
v_2454:
    goto v_2450;
v_2451:
    goto v_2452;
v_2453:
    v_2477 = (LispObject)lesseq2(v_2478, v_2477);
    v_2477 = v_2477 ? lisp_true : nil;
    env = stack[-3];
    if (v_2477 == nil) goto v_2447;
    goto v_2465;
v_2461:
    v_2477 = stack[-2];
    v_2477 = qcar(v_2477);
    fn = elt(env, 2); // bas_dpoly
    v_2477 = (*qfn1(fn))(fn, v_2477);
    env = stack[-3];
    fn = elt(env, 3); // dp_lmon
    v_2478 = (*qfn1(fn))(fn, v_2477);
    env = stack[-3];
    goto v_2462;
v_2463:
    v_2477 = stack[-1];
    goto v_2464;
v_2465:
    goto v_2461;
v_2462:
    goto v_2463;
v_2464:
    fn = elt(env, 4); // mo_vdivides!?
    v_2477 = (*qfn2(fn))(fn, v_2478, v_2477);
    env = stack[-3];
    if (v_2477 == nil) goto v_2447;
    v_2477 = stack[-2];
    v_2477 = qcar(v_2477);
    goto v_2438;
v_2447:
    v_2477 = stack[-2];
    v_2477 = qcdr(v_2477);
    stack[-2] = v_2477;
    goto v_2439;
    v_2477 = nil;
v_2438:
    return onevalue(v_2477);
}



// Code for pappl_pv

static LispObject CC_pappl_pv(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2509, v_2510;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2433,v_2434);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_2509 = v_2434;
    stack[-4] = v_2433;
// end of prologue
    stack[-5] = v_2509;
    v_2509 = stack[-5];
    if (v_2509 == nil) goto v_2446;
    else goto v_2447;
v_2446:
    v_2509 = nil;
    goto v_2441;
v_2447:
    v_2509 = stack[-5];
    v_2509 = qcar(v_2509);
    goto v_2459;
v_2455:
    v_2510 = v_2509;
    stack[0] = qcar(v_2510);
    goto v_2456;
v_2457:
    goto v_2467;
v_2463:
    v_2510 = stack[-4];
    goto v_2464;
v_2465:
    v_2509 = qcdr(v_2509);
    goto v_2466;
v_2467:
    goto v_2463;
v_2464:
    goto v_2465;
v_2466:
    fn = elt(env, 1); // pappl0
    v_2509 = (*qfn2(fn))(fn, v_2510, v_2509);
    env = stack[-6];
    goto v_2458;
v_2459:
    goto v_2455;
v_2456:
    goto v_2457;
v_2458:
    v_2509 = cons(stack[0], v_2509);
    env = stack[-6];
    v_2509 = ncons(v_2509);
    env = stack[-6];
    stack[-2] = v_2509;
    stack[-3] = v_2509;
v_2442:
    v_2509 = stack[-5];
    v_2509 = qcdr(v_2509);
    stack[-5] = v_2509;
    v_2509 = stack[-5];
    if (v_2509 == nil) goto v_2475;
    else goto v_2476;
v_2475:
    v_2509 = stack[-3];
    goto v_2441;
v_2476:
    goto v_2484;
v_2480:
    stack[-1] = stack[-2];
    goto v_2481;
v_2482:
    v_2509 = stack[-5];
    v_2509 = qcar(v_2509);
    goto v_2495;
v_2491:
    v_2510 = v_2509;
    stack[0] = qcar(v_2510);
    goto v_2492;
v_2493:
    goto v_2503;
v_2499:
    v_2510 = stack[-4];
    goto v_2500;
v_2501:
    v_2509 = qcdr(v_2509);
    goto v_2502;
v_2503:
    goto v_2499;
v_2500:
    goto v_2501;
v_2502:
    fn = elt(env, 1); // pappl0
    v_2509 = (*qfn2(fn))(fn, v_2510, v_2509);
    env = stack[-6];
    goto v_2494;
v_2495:
    goto v_2491;
v_2492:
    goto v_2493;
v_2494:
    v_2509 = cons(stack[0], v_2509);
    env = stack[-6];
    v_2509 = ncons(v_2509);
    env = stack[-6];
    goto v_2483;
v_2484:
    goto v_2480;
v_2481:
    goto v_2482;
v_2483:
    v_2509 = Lrplacd(nil, stack[-1], v_2509);
    env = stack[-6];
    v_2509 = stack[-2];
    v_2509 = qcdr(v_2509);
    stack[-2] = v_2509;
    goto v_2442;
v_2441:
    {
        fn = elt(env, 2); // pv_sort
        return (*qfn1(fn))(fn, v_2509);
    }
}



// Code for general!-modular!-quotient

static LispObject CC_generalKmodularKquotient(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2445, v_2446;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2433,v_2434);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_2445 = v_2434;
    v_2446 = v_2433;
// end of prologue
    goto v_2441;
v_2437:
    stack[0] = v_2446;
    goto v_2438;
v_2439:
    fn = elt(env, 1); // general!-modular!-reciprocal
    v_2445 = (*qfn1(fn))(fn, v_2445);
    env = stack[-1];
    goto v_2440;
v_2441:
    goto v_2437;
v_2438:
    goto v_2439;
v_2440:
    {
        LispObject v_2448 = stack[0];
        fn = elt(env, 2); // general!-modular!-times
        return (*qfn2(fn))(fn, v_2448, v_2445);
    }
}



// Code for minus!-mod!-p

static LispObject CC_minusKmodKp(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2488, v_2489;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_2433;
// end of prologue
    stack[-2] = nil;
v_2438:
    v_2488 = stack[-1];
    if (v_2488 == nil) goto v_2441;
    else goto v_2442;
v_2441:
    v_2488 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_2488);
    }
v_2442:
    v_2488 = stack[-1];
    if (!consp(v_2488)) goto v_2450;
    else goto v_2451;
v_2450:
    v_2488 = lisp_true;
    goto v_2449;
v_2451:
    v_2488 = stack[-1];
    v_2488 = qcar(v_2488);
    v_2488 = (consp(v_2488) ? nil : lisp_true);
    goto v_2449;
    v_2488 = nil;
v_2449:
    if (v_2488 == nil) goto v_2447;
    goto v_2464;
v_2460:
    v_2489 = stack[-2];
    goto v_2461;
v_2462:
    v_2488 = stack[-1];
    {   intptr_t w = int_of_fixnum(v_2488);
        if (w != 0) w = current_modulus - w;
        v_2488 = fixnum_of_int(w);
    }
    goto v_2463;
v_2464:
    goto v_2460;
v_2461:
    goto v_2462;
v_2463:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_2489, v_2488);
    }
v_2447:
    goto v_2477;
v_2471:
    v_2488 = stack[-1];
    v_2488 = qcar(v_2488);
    stack[0] = qcar(v_2488);
    goto v_2472;
v_2473:
    v_2488 = stack[-1];
    v_2488 = qcar(v_2488);
    v_2488 = qcdr(v_2488);
    v_2489 = CC_minusKmodKp(elt(env, 0), v_2488);
    env = stack[-3];
    goto v_2474;
v_2475:
    v_2488 = stack[-2];
    goto v_2476;
v_2477:
    goto v_2471;
v_2472:
    goto v_2473;
v_2474:
    goto v_2475;
v_2476:
    v_2488 = acons(stack[0], v_2489, v_2488);
    env = stack[-3];
    stack[-2] = v_2488;
    v_2488 = stack[-1];
    v_2488 = qcdr(v_2488);
    stack[-1] = v_2488;
    goto v_2438;
    v_2488 = nil;
    return onevalue(v_2488);
}



// Code for raddf

static LispObject CC_raddf(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2599, v_2600;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2433,v_2434);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_2434;
    stack[-2] = v_2433;
// end of prologue
    stack[-3] = nil;
v_2439:
    v_2599 = stack[-2];
    if (v_2599 == nil) goto v_2442;
    else goto v_2443;
v_2442:
    goto v_2450;
v_2446:
    v_2600 = stack[-3];
    goto v_2447;
v_2448:
    v_2599 = stack[-1];
    goto v_2449;
v_2450:
    goto v_2446;
v_2447:
    goto v_2448;
v_2449:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_2600, v_2599);
    }
v_2443:
    v_2599 = stack[-1];
    if (v_2599 == nil) goto v_2453;
    else goto v_2454;
v_2453:
    goto v_2461;
v_2457:
    v_2600 = stack[-3];
    goto v_2458;
v_2459:
    v_2599 = stack[-2];
    goto v_2460;
v_2461:
    goto v_2457;
v_2458:
    goto v_2459;
v_2460:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_2600, v_2599);
    }
v_2454:
    v_2599 = stack[-2];
    if (!consp(v_2599)) goto v_2468;
    else goto v_2469;
v_2468:
    v_2599 = lisp_true;
    goto v_2467;
v_2469:
    v_2599 = stack[-2];
    v_2599 = qcar(v_2599);
    v_2599 = (consp(v_2599) ? nil : lisp_true);
    goto v_2467;
    v_2599 = nil;
v_2467:
    if (v_2599 == nil) goto v_2465;
    goto v_2482;
v_2478:
    stack[0] = stack[-3];
    goto v_2479;
v_2480:
    goto v_2489;
v_2485:
    v_2600 = stack[-2];
    goto v_2486;
v_2487:
    v_2599 = stack[-1];
    goto v_2488;
v_2489:
    goto v_2485;
v_2486:
    goto v_2487;
v_2488:
    fn = elt(env, 2); // addd
    v_2599 = (*qfn2(fn))(fn, v_2600, v_2599);
    env = stack[-4];
    goto v_2481;
v_2482:
    goto v_2478;
v_2479:
    goto v_2480;
v_2481:
    {
        LispObject v_2605 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_2605, v_2599);
    }
v_2465:
    v_2599 = stack[-1];
    if (!consp(v_2599)) goto v_2496;
    else goto v_2497;
v_2496:
    v_2599 = lisp_true;
    goto v_2495;
v_2497:
    v_2599 = stack[-1];
    v_2599 = qcar(v_2599);
    v_2599 = (consp(v_2599) ? nil : lisp_true);
    goto v_2495;
    v_2599 = nil;
v_2495:
    if (v_2599 == nil) goto v_2493;
    goto v_2510;
v_2506:
    stack[0] = stack[-3];
    goto v_2507;
v_2508:
    goto v_2517;
v_2513:
    v_2600 = stack[-1];
    goto v_2514;
v_2515:
    v_2599 = stack[-2];
    goto v_2516;
v_2517:
    goto v_2513;
v_2514:
    goto v_2515;
v_2516:
    fn = elt(env, 2); // addd
    v_2599 = (*qfn2(fn))(fn, v_2600, v_2599);
    env = stack[-4];
    goto v_2509;
v_2510:
    goto v_2506;
v_2507:
    goto v_2508;
v_2509:
    {
        LispObject v_2606 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_2606, v_2599);
    }
v_2493:
    goto v_2526;
v_2522:
    v_2599 = stack[-2];
    v_2599 = qcar(v_2599);
    v_2600 = qcar(v_2599);
    goto v_2523;
v_2524:
    v_2599 = stack[-1];
    v_2599 = qcar(v_2599);
    v_2599 = qcar(v_2599);
    goto v_2525;
v_2526:
    goto v_2522;
v_2523:
    goto v_2524;
v_2525:
    if (equal(v_2600, v_2599)) goto v_2520;
    else goto v_2521;
v_2520:
    goto v_2540;
v_2534:
    v_2599 = stack[-2];
    v_2599 = qcar(v_2599);
    stack[0] = qcar(v_2599);
    goto v_2535;
v_2536:
    goto v_2549;
v_2545:
    v_2599 = stack[-2];
    v_2599 = qcar(v_2599);
    v_2600 = qcdr(v_2599);
    goto v_2546;
v_2547:
    v_2599 = stack[-1];
    v_2599 = qcar(v_2599);
    v_2599 = qcdr(v_2599);
    goto v_2548;
v_2549:
    goto v_2545;
v_2546:
    goto v_2547;
v_2548:
    v_2600 = CC_raddf(elt(env, 0), v_2600, v_2599);
    env = stack[-4];
    goto v_2537;
v_2538:
    v_2599 = stack[-3];
    goto v_2539;
v_2540:
    goto v_2534;
v_2535:
    goto v_2536;
v_2537:
    goto v_2538;
v_2539:
    v_2599 = acons(stack[0], v_2600, v_2599);
    env = stack[-4];
    stack[-3] = v_2599;
    v_2599 = stack[-2];
    v_2599 = qcdr(v_2599);
    stack[-2] = v_2599;
    v_2599 = stack[-1];
    v_2599 = qcdr(v_2599);
    stack[-1] = v_2599;
    goto v_2439;
v_2521:
    goto v_2568;
v_2564:
    v_2599 = stack[-2];
    v_2599 = qcar(v_2599);
    v_2600 = qcar(v_2599);
    goto v_2565;
v_2566:
    v_2599 = stack[-1];
    v_2599 = qcar(v_2599);
    v_2599 = qcar(v_2599);
    goto v_2567;
v_2568:
    goto v_2564;
v_2565:
    goto v_2566;
v_2567:
    fn = elt(env, 3); // ordpp
    v_2599 = (*qfn2(fn))(fn, v_2600, v_2599);
    env = stack[-4];
    if (v_2599 == nil) goto v_2562;
    goto v_2580;
v_2576:
    v_2599 = stack[-2];
    v_2600 = qcar(v_2599);
    goto v_2577;
v_2578:
    v_2599 = stack[-3];
    goto v_2579;
v_2580:
    goto v_2576;
v_2577:
    goto v_2578;
v_2579:
    v_2599 = cons(v_2600, v_2599);
    env = stack[-4];
    stack[-3] = v_2599;
    v_2599 = stack[-2];
    v_2599 = qcdr(v_2599);
    stack[-2] = v_2599;
    goto v_2439;
v_2562:
    goto v_2593;
v_2589:
    v_2599 = stack[-1];
    v_2600 = qcar(v_2599);
    goto v_2590;
v_2591:
    v_2599 = stack[-3];
    goto v_2592;
v_2593:
    goto v_2589;
v_2590:
    goto v_2591;
v_2592:
    v_2599 = cons(v_2600, v_2599);
    env = stack[-4];
    stack[-3] = v_2599;
    v_2599 = stack[-1];
    v_2599 = qcdr(v_2599);
    stack[-1] = v_2599;
    goto v_2439;
    v_2599 = nil;
    return onevalue(v_2599);
}



// Code for gcdf1

static LispObject CC_gcdf1(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2644, v_2645;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2433,v_2434);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_2434;
    stack[-2] = v_2433;
// end of prologue
    v_2644 = stack[-2];
    if (v_2644 == nil) goto v_2442;
    else goto v_2443;
v_2442:
    v_2644 = stack[-1];
    goto v_2438;
v_2443:
    v_2644 = stack[-1];
    if (v_2644 == nil) goto v_2446;
    else goto v_2447;
v_2446:
    v_2644 = stack[-2];
    goto v_2438;
v_2447:
    goto v_2460;
v_2456:
    v_2645 = stack[-2];
    goto v_2457;
v_2458:
    v_2644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2459;
v_2460:
    goto v_2456;
v_2457:
    goto v_2458;
v_2459:
    if (v_2645 == v_2644) goto v_2454;
    else goto v_2455;
v_2454:
    v_2644 = lisp_true;
    goto v_2453;
v_2455:
    goto v_2470;
v_2466:
    v_2645 = stack[-1];
    goto v_2467;
v_2468:
    v_2644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2469;
v_2470:
    goto v_2466;
v_2467:
    goto v_2468;
v_2469:
    v_2644 = (v_2645 == v_2644 ? lisp_true : nil);
    goto v_2453;
    v_2644 = nil;
v_2453:
    if (v_2644 == nil) goto v_2451;
    v_2644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2438;
v_2451:
    v_2644 = stack[-2];
    if (!consp(v_2644)) goto v_2479;
    else goto v_2480;
v_2479:
    v_2644 = lisp_true;
    goto v_2478;
v_2480:
    v_2644 = stack[-2];
    v_2644 = qcar(v_2644);
    v_2644 = (consp(v_2644) ? nil : lisp_true);
    goto v_2478;
    v_2644 = nil;
v_2478:
    if (v_2644 == nil) goto v_2476;
    goto v_2493;
v_2489:
    v_2645 = stack[-2];
    goto v_2490;
v_2491:
    v_2644 = stack[-1];
    goto v_2492;
v_2493:
    goto v_2489;
v_2490:
    goto v_2491;
v_2492:
    {
        fn = elt(env, 7); // gcdfd
        return (*qfn2(fn))(fn, v_2645, v_2644);
    }
v_2476:
    v_2644 = stack[-1];
    if (!consp(v_2644)) goto v_2500;
    else goto v_2501;
v_2500:
    v_2644 = lisp_true;
    goto v_2499;
v_2501:
    v_2644 = stack[-1];
    v_2644 = qcar(v_2644);
    v_2644 = (consp(v_2644) ? nil : lisp_true);
    goto v_2499;
    v_2644 = nil;
v_2499:
    if (v_2644 == nil) goto v_2497;
    goto v_2514;
v_2510:
    v_2645 = stack[-1];
    goto v_2511;
v_2512:
    v_2644 = stack[-2];
    goto v_2513;
v_2514:
    goto v_2510;
v_2511:
    goto v_2512;
v_2513:
    {
        fn = elt(env, 7); // gcdfd
        return (*qfn2(fn))(fn, v_2645, v_2644);
    }
v_2497:
    v_2644 = qvalue(elt(env, 2)); // !*anygcd
    if (v_2644 == nil) goto v_2521;
    else goto v_2522;
v_2521:
    v_2644 = lisp_true;
    goto v_2520;
v_2522:
    v_2644 = stack[-2];
    fn = elt(env, 8); // num!-exponents
    v_2644 = (*qfn1(fn))(fn, v_2644);
    env = stack[-4];
    if (v_2644 == nil) goto v_2529;
    else goto v_2530;
v_2529:
    v_2644 = lisp_true;
    goto v_2528;
v_2530:
    v_2644 = stack[-1];
    fn = elt(env, 8); // num!-exponents
    v_2644 = (*qfn1(fn))(fn, v_2644);
    env = stack[-4];
    v_2644 = (v_2644 == nil ? lisp_true : nil);
    goto v_2528;
    v_2644 = nil;
v_2528:
    goto v_2520;
    v_2644 = nil;
v_2520:
    if (v_2644 == nil) goto v_2518;
    v_2644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2438;
v_2518:
    goto v_2547;
v_2543:
    v_2645 = stack[-2];
    goto v_2544;
v_2545:
    v_2644 = stack[-1];
    goto v_2546;
v_2547:
    goto v_2543;
v_2544:
    goto v_2545;
v_2546:
    fn = elt(env, 9); // quotf1
    v_2644 = (*qfn2(fn))(fn, v_2645, v_2644);
    env = stack[-4];
    if (v_2644 == nil) goto v_2541;
    v_2644 = stack[-1];
    goto v_2438;
v_2541:
    goto v_2558;
v_2554:
    v_2645 = stack[-1];
    goto v_2555;
v_2556:
    v_2644 = stack[-2];
    goto v_2557;
v_2558:
    goto v_2554;
v_2555:
    goto v_2556;
v_2557:
    fn = elt(env, 9); // quotf1
    v_2644 = (*qfn2(fn))(fn, v_2645, v_2644);
    env = stack[-4];
    if (v_2644 == nil) goto v_2552;
    v_2644 = stack[-2];
    goto v_2438;
v_2552:
    goto v_2567;
v_2563:
    v_2645 = stack[-2];
    goto v_2564;
v_2565:
    v_2644 = stack[-1];
    goto v_2566;
v_2567:
    goto v_2563;
v_2564:
    goto v_2565;
v_2566:
    fn = elt(env, 10); // gcdf2
    v_2644 = (*qfn2(fn))(fn, v_2645, v_2644);
    env = stack[-4];
    stack[-3] = v_2644;
    v_2644 = qvalue(elt(env, 3)); // !*gcd
    if (v_2644 == nil) goto v_2573;
    goto v_2585;
v_2581:
    v_2645 = qvalue(elt(env, 4)); // dmode!*
    goto v_2582;
v_2583:
    v_2644 = elt(env, 5); // (!:rd!: !:cr!:)
    goto v_2584;
v_2585:
    goto v_2581;
v_2582:
    goto v_2583;
v_2584:
    v_2644 = Lmemq(nil, v_2645, v_2644);
    if (v_2644 == nil) goto v_2579;
    else goto v_2580;
v_2579:
    goto v_2598;
v_2594:
    v_2645 = stack[-2];
    goto v_2595;
v_2596:
    v_2644 = stack[-3];
    goto v_2597;
v_2598:
    goto v_2594;
v_2595:
    goto v_2596;
v_2597:
    fn = elt(env, 9); // quotf1
    v_2644 = (*qfn2(fn))(fn, v_2645, v_2644);
    env = stack[-4];
    if (v_2644 == nil) goto v_2591;
    else goto v_2592;
v_2591:
    v_2644 = lisp_true;
    goto v_2590;
v_2592:
    goto v_2609;
v_2605:
    v_2645 = stack[-1];
    goto v_2606;
v_2607:
    v_2644 = stack[-3];
    goto v_2608;
v_2609:
    goto v_2605;
v_2606:
    goto v_2607;
v_2608:
    fn = elt(env, 9); // quotf1
    v_2644 = (*qfn2(fn))(fn, v_2645, v_2644);
    env = stack[-4];
    v_2644 = (v_2644 == nil ? lisp_true : nil);
    goto v_2590;
    v_2644 = nil;
v_2590:
    goto v_2578;
v_2580:
    v_2644 = nil;
    goto v_2578;
    v_2644 = nil;
v_2578:
    if (v_2644 == nil) goto v_2573;
    v_2644 = stack[-2];
    fn = elt(env, 11); // noncomfp
    v_2644 = (*qfn1(fn))(fn, v_2644);
    env = stack[-4];
    if (v_2644 == nil) goto v_2620;
    else goto v_2618;
v_2620:
    v_2644 = stack[-1];
    fn = elt(env, 11); // noncomfp
    v_2644 = (*qfn1(fn))(fn, v_2644);
    env = stack[-4];
    if (v_2644 == nil) goto v_2623;
    else goto v_2618;
v_2623:
    goto v_2619;
v_2618:
    v_2644 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2438;
v_2619:
    goto v_2637;
v_2631:
    stack[0] = elt(env, 6); // "gcdf failed"
    goto v_2632;
v_2633:
    v_2644 = stack[-2];
    fn = elt(env, 12); // prepf
    stack[-2] = (*qfn1(fn))(fn, v_2644);
    env = stack[-4];
    goto v_2634;
v_2635:
    v_2644 = stack[-1];
    fn = elt(env, 12); // prepf
    v_2644 = (*qfn1(fn))(fn, v_2644);
    env = stack[-4];
    goto v_2636;
v_2637:
    goto v_2631;
v_2632:
    goto v_2633;
v_2634:
    goto v_2635;
v_2636:
    v_2644 = list3(stack[0], stack[-2], v_2644);
    env = stack[-4];
    fn = elt(env, 13); // errach
    v_2644 = (*qfn1(fn))(fn, v_2644);
    goto v_2617;
v_2617:
    goto v_2571;
v_2573:
v_2571:
    v_2644 = stack[-3];
v_2438:
    return onevalue(v_2644);
}



// Code for talp_smupdknowl

static LispObject CC_talp_smupdknowl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2497, v_2498, v_2499, v_2500;
    LispObject fn;
    LispObject v_2436, v_2435, v_2434, v_2433;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "talp_smupdknowl");
    va_start(aa, nargs);
    v_2433 = va_arg(aa, LispObject);
    v_2434 = va_arg(aa, LispObject);
    v_2435 = va_arg(aa, LispObject);
    v_2436 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_2436,v_2435,v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_2433,v_2434,v_2435,v_2436);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_2436;
    v_2497 = v_2435;
    stack[-1] = v_2434;
    stack[-2] = v_2433;
// end of prologue
    stack[-3] = nil;
v_2444:
    v_2498 = stack[-1];
    if (v_2498 == nil) goto v_2447;
    else goto v_2448;
v_2447:
    goto v_2443;
v_2448:
    v_2498 = stack[-1];
    v_2498 = qcar(v_2498);
    stack[-3] = v_2498;
    v_2498 = stack[-1];
    v_2498 = qcdr(v_2498);
    stack[-1] = v_2498;
    goto v_2464;
v_2456:
    v_2500 = stack[-2];
    goto v_2457;
v_2458:
    v_2499 = stack[-3];
    goto v_2459;
v_2460:
    v_2498 = v_2497;
    goto v_2461;
v_2462:
    v_2497 = stack[0];
    goto v_2463;
v_2464:
    goto v_2456;
v_2457:
    goto v_2458;
v_2459:
    goto v_2460;
v_2461:
    goto v_2462;
v_2463:
    fn = elt(env, 4); // talp_smupdknowl1
    v_2497 = (*qfnn(fn))(fn, 4, v_2500, v_2499, v_2498, v_2497);
    env = stack[-4];
    goto v_2477;
v_2473:
    v_2499 = v_2497;
    goto v_2474;
v_2475:
    v_2498 = elt(env, 2); // false
    goto v_2476;
v_2477:
    goto v_2473;
v_2474:
    goto v_2475;
v_2476:
    if (v_2499 == v_2498) goto v_2471;
    else goto v_2472;
v_2471:
    v_2498 = nil;
    stack[-1] = v_2498;
    v_2498 = elt(env, 3); // break
    stack[-3] = v_2498;
    goto v_2470;
v_2472:
v_2470:
    goto v_2444;
v_2443:
    goto v_2490;
v_2486:
    v_2499 = stack[-3];
    goto v_2487;
v_2488:
    v_2498 = elt(env, 3); // break
    goto v_2489;
v_2490:
    goto v_2486;
v_2487:
    goto v_2488;
v_2489:
    if (v_2499 == v_2498) goto v_2484;
    else goto v_2485;
v_2484:
    v_2497 = elt(env, 2); // false
    goto v_2440;
v_2485:
    goto v_2440;
    v_2497 = nil;
v_2440:
    return onevalue(v_2497);
}



// Code for mri_simplfloor

static LispObject CC_mri_simplfloor(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2446;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2433;
// end of prologue
    v_2446 = stack[0];
    fn = elt(env, 1); // mri_floorkernelp
    v_2446 = (*qfn1(fn))(fn, v_2446);
    env = stack[-1];
    if (v_2446 == nil) goto v_2437;
    else goto v_2438;
v_2437:
    v_2446 = stack[0];
    goto v_2436;
v_2438:
    v_2446 = stack[0];
    {
        fn = elt(env, 2); // mri_simplfloor1
        return (*qfn1(fn))(fn, v_2446);
    }
    v_2446 = nil;
v_2436:
    return onevalue(v_2446);
}



// Code for rl_simpat

static LispObject CC_rl_simpat(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2444;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_2444 = v_2433;
// end of prologue
    goto v_2440;
v_2436:
    stack[0] = qvalue(elt(env, 1)); // rl_simpat!*
    goto v_2437;
v_2438:
    v_2444 = ncons(v_2444);
    env = stack[-1];
    goto v_2439;
v_2440:
    goto v_2436;
v_2437:
    goto v_2438;
v_2439:
    {
        LispObject v_2446 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_2446, v_2444);
    }
}



// Code for kernord

static LispObject CC_kernord(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2456, v_2457;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2433,v_2434);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_2456 = v_2434;
    stack[0] = v_2433;
// end of prologue
    goto v_2441;
v_2437:
    v_2457 = stack[0];
    goto v_2438;
v_2439:
    goto v_2440;
v_2441:
    goto v_2437;
v_2438:
    goto v_2439;
v_2440:
    fn = elt(env, 1); // kernord!-split
    v_2456 = (*qfn2(fn))(fn, v_2457, v_2456);
    env = stack[-2];
    stack[0] = v_2456;
    goto v_2449;
v_2445:
    v_2456 = stack[0];
    v_2456 = qcar(v_2456);
    fn = elt(env, 2); // kernord!-sort
    stack[-1] = (*qfn1(fn))(fn, v_2456);
    env = stack[-2];
    goto v_2446;
v_2447:
    v_2456 = stack[0];
    v_2456 = qcdr(v_2456);
    fn = elt(env, 2); // kernord!-sort
    v_2456 = (*qfn1(fn))(fn, v_2456);
    goto v_2448;
v_2449:
    goto v_2445;
v_2446:
    goto v_2447;
v_2448:
    {
        LispObject v_2460 = stack[-1];
        return Lappend(nil, v_2460, v_2456);
    }
}



// Code for quotfd

static LispObject CC_quotfd(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2491, v_2492, v_2493, v_2494;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2493 = v_2434;
    v_2494 = v_2433;
// end of prologue
    goto v_2444;
v_2440:
    v_2492 = v_2494;
    goto v_2441;
v_2442:
    v_2491 = v_2493;
    goto v_2443;
v_2444:
    goto v_2440;
v_2441:
    goto v_2442;
v_2443:
    if (equal(v_2492, v_2491)) goto v_2438;
    else goto v_2439;
v_2438:
    v_2491 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2437;
v_2439:
    v_2491 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_2491)) v_2491 = nil;
    else { v_2491 = qfastgets(v_2491);
           if (v_2491 != nil) { v_2491 = elt(v_2491, 3); // field
#ifdef RECORD_GET
             if (v_2491 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_2491 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_2491 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_2491 == SPID_NOPROP) v_2491 = nil; else v_2491 = lisp_true; }}
#endif
    if (v_2491 == nil) goto v_2449;
    goto v_2457;
v_2453:
    v_2491 = v_2494;
    goto v_2454;
v_2455:
    v_2492 = v_2493;
    goto v_2456;
v_2457:
    goto v_2453;
v_2454:
    goto v_2455;
v_2456:
    {
        fn = elt(env, 2); // divd
        return (*qfn2(fn))(fn, v_2491, v_2492);
    }
v_2449:
    v_2491 = v_2494;
    if (!consp(v_2491)) goto v_2464;
    else goto v_2465;
v_2464:
    v_2491 = lisp_true;
    goto v_2463;
v_2465:
    v_2491 = v_2494;
    v_2491 = qcar(v_2491);
    v_2491 = (consp(v_2491) ? nil : lisp_true);
    goto v_2463;
    v_2491 = nil;
v_2463:
    if (v_2491 == nil) goto v_2461;
    goto v_2478;
v_2474:
    v_2491 = v_2494;
    goto v_2475;
v_2476:
    v_2492 = v_2493;
    goto v_2477;
v_2478:
    goto v_2474;
v_2475:
    goto v_2476;
v_2477:
    {
        fn = elt(env, 3); // quotdd
        return (*qfn2(fn))(fn, v_2491, v_2492);
    }
v_2461:
    goto v_2488;
v_2484:
    v_2491 = v_2494;
    goto v_2485;
v_2486:
    v_2492 = v_2493;
    goto v_2487;
v_2488:
    goto v_2484;
v_2485:
    goto v_2486;
v_2487:
    {
        fn = elt(env, 4); // quotk
        return (*qfn2(fn))(fn, v_2491, v_2492);
    }
    v_2491 = nil;
v_2437:
    return onevalue(v_2491);
}



// Code for omobj

static LispObject CC_omobj(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2462, v_2463;
    LispObject fn;
    argcheck(nargs, 0, "omobj");
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
    goto v_2447;
v_2443:
    v_2462 = qvalue(elt(env, 2)); // char
    fn = elt(env, 4); // compress!*
    v_2463 = (*qfn1(fn))(fn, v_2462);
    env = stack[0];
    goto v_2444;
v_2445:
    v_2462 = qvalue(elt(env, 3)); // omfuncs!*
    goto v_2446;
v_2447:
    goto v_2443;
v_2444:
    goto v_2445;
v_2446:
    v_2462 = Lassoc(nil, v_2463, v_2462);
    v_2463 = v_2462;
    if (v_2462 == nil) goto v_2442;
    goto v_2457;
v_2453:
    v_2462 = v_2463;
    v_2462 = qcdr(v_2462);
    v_2463 = qcar(v_2462);
    goto v_2454;
v_2455:
    v_2462 = nil;
    goto v_2456;
v_2457:
    goto v_2453;
v_2454:
    goto v_2455;
v_2456:
    {
        fn = elt(env, 5); // apply
        return (*qfn2(fn))(fn, v_2463, v_2462);
    }
v_2442:
    v_2462 = nil;
    return onevalue(v_2462);
}



// Code for prepd

static LispObject CC_prepd(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2514, v_2515;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2433;
// end of prologue
    v_2514 = stack[0];
    if (!consp(v_2514)) goto v_2437;
    else goto v_2438;
v_2437:
    goto v_2449;
v_2445:
    v_2515 = stack[0];
    goto v_2446;
v_2447:
    v_2514 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2448;
v_2449:
    goto v_2445;
v_2446:
    goto v_2447;
v_2448:
    v_2514 = (LispObject)lessp2(v_2515, v_2514);
    v_2514 = v_2514 ? lisp_true : nil;
    env = stack[-2];
    if (v_2514 == nil) goto v_2443;
    goto v_2457;
v_2453:
    stack[-1] = elt(env, 1); // minus
    goto v_2454;
v_2455:
    v_2514 = stack[0];
    v_2514 = negate(v_2514);
    goto v_2456;
v_2457:
    goto v_2453;
v_2454:
    goto v_2455;
v_2456:
    {
        LispObject v_2518 = stack[-1];
        return list2(v_2518, v_2514);
    }
v_2443:
    v_2514 = stack[0];
    goto v_2441;
    v_2514 = nil;
v_2441:
    goto v_2436;
v_2438:
    goto v_2471;
v_2467:
    v_2514 = stack[0];
    v_2514 = qcar(v_2514);
    if (!symbolp(v_2514)) v_2515 = nil;
    else { v_2515 = qfastgets(v_2514);
           if (v_2515 != nil) { v_2515 = elt(v_2515, 30); // minusp
#ifdef RECORD_GET
             if (v_2515 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v_2515 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v_2515 == SPID_NOPROP) v_2515 = nil; }}
#endif
    goto v_2468;
v_2469:
    v_2514 = stack[0];
    goto v_2470;
v_2471:
    goto v_2467;
v_2468:
    goto v_2469;
v_2470:
    v_2514 = Lapply1(nil, v_2515, v_2514);
    env = stack[-2];
    if (v_2514 == nil) goto v_2465;
    v_2514 = stack[0];
    fn = elt(env, 3); // !:minus
    v_2514 = (*qfn1(fn))(fn, v_2514);
    env = stack[-2];
    fn = elt(env, 4); // prepd1
    v_2514 = (*qfn1(fn))(fn, v_2514);
    env = stack[-2];
    v_2515 = v_2514;
    v_2514 = v_2515;
    if (v_2514 == nil) goto v_2482;
    else goto v_2483;
v_2482:
    v_2514 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2481;
v_2483:
    goto v_2493;
v_2489:
    v_2514 = elt(env, 1); // minus
    goto v_2490;
v_2491:
    goto v_2492;
v_2493:
    goto v_2489;
v_2490:
    goto v_2491;
v_2492:
    return list2(v_2514, v_2515);
    v_2514 = nil;
v_2481:
    goto v_2436;
v_2465:
    goto v_2503;
v_2499:
    goto v_2509;
v_2505:
    v_2514 = stack[0];
    v_2515 = qcar(v_2514);
    goto v_2506;
v_2507:
    v_2514 = elt(env, 2); // prepfn
    goto v_2508;
v_2509:
    goto v_2505;
v_2506:
    goto v_2507;
v_2508:
    v_2515 = get(v_2515, v_2514);
    goto v_2500;
v_2501:
    v_2514 = stack[0];
    goto v_2502;
v_2503:
    goto v_2499;
v_2500:
    goto v_2501;
v_2502:
        return Lapply1(nil, v_2515, v_2514);
    v_2514 = nil;
v_2436:
    return onevalue(v_2514);
}



// Code for subscriptedvarp

static LispObject CC_subscriptedvarp(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2462, v_2463;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2433;
// end of prologue
    goto v_2443;
v_2439:
    goto v_2450;
v_2446:
    v_2463 = nil;
    goto v_2447;
v_2448:
    v_2462 = stack[0];
    goto v_2449;
v_2450:
    goto v_2446;
v_2447:
    goto v_2448;
v_2449:
    fn = elt(env, 2); // symtabget
    v_2462 = (*qfn2(fn))(fn, v_2463, v_2462);
    env = stack[-1];
    v_2463 = Llength(nil, v_2462);
    env = stack[-1];
    goto v_2440;
v_2441:
    v_2462 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_2442;
v_2443:
    goto v_2439;
v_2440:
    goto v_2441;
v_2442:
    v_2462 = (LispObject)greaterp2(v_2463, v_2462);
    v_2462 = v_2462 ? lisp_true : nil;
    env = stack[-1];
    if (v_2462 == nil) goto v_2437;
    else goto v_2436;
v_2437:
    goto v_2459;
v_2455:
    v_2462 = stack[0];
    goto v_2456;
v_2457:
    v_2463 = elt(env, 1); // subscripted
    goto v_2458;
v_2459:
    goto v_2455;
v_2456:
    goto v_2457;
v_2458:
        return Lflagp(nil, v_2462, v_2463);
v_2436:
    return onevalue(v_2462);
}



// Code for quotematrix

static LispObject CC_quotematrix(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2436;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2436 = v_2433;
// end of prologue
    v_2436 = elt(env, 1); // matrix
    return onevalue(v_2436);
}



// Code for deg!*farg

static LispObject CC_degHfarg(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2476, v_2477;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_2477 = v_2433;
// end of prologue
    v_2476 = v_2477;
    v_2476 = qcdr(v_2476);
    if (v_2476 == nil) goto v_2437;
    else goto v_2438;
v_2437:
    v_2476 = v_2477;
    v_2476 = qcar(v_2476);
    {
        fn = elt(env, 2); // deg!*form
        return (*qfn1(fn))(fn, v_2476);
    }
v_2438:
    stack[-1] = nil;
    v_2476 = v_2477;
    stack[0] = v_2476;
v_2453:
    v_2476 = stack[0];
    if (v_2476 == nil) goto v_2457;
    else goto v_2458;
v_2457:
    goto v_2452;
v_2458:
    v_2476 = stack[0];
    v_2476 = qcar(v_2476);
    goto v_2469;
v_2465:
    fn = elt(env, 2); // deg!*form
    v_2477 = (*qfn1(fn))(fn, v_2476);
    env = stack[-2];
    goto v_2466;
v_2467:
    v_2476 = stack[-1];
    goto v_2468;
v_2469:
    goto v_2465;
v_2466:
    goto v_2467;
v_2468:
    fn = elt(env, 3); // addf
    v_2476 = (*qfn2(fn))(fn, v_2477, v_2476);
    env = stack[-2];
    stack[-1] = v_2476;
    v_2476 = stack[0];
    v_2476 = qcdr(v_2476);
    stack[0] = v_2476;
    goto v_2453;
v_2452:
    v_2476 = stack[-1];
    goto v_2436;
    v_2476 = nil;
v_2436:
    return onevalue(v_2476);
}



// Code for algid

static LispObject CC_algid(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2457, v_2458, v_2459;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2457 = v_2434;
    v_2458 = v_2433;
// end of prologue
    goto v_2445;
v_2441:
    v_2459 = v_2458;
    goto v_2442;
v_2443:
    goto v_2444;
v_2445:
    goto v_2441;
v_2442:
    goto v_2443;
v_2444:
    v_2457 = Latsoc(nil, v_2459, v_2457);
    if (v_2457 == nil) goto v_2440;
    else goto v_2438;
v_2440:
    v_2457 = v_2458;
    if (!symbolp(v_2457)) v_2457 = nil;
    else { v_2457 = qfastgets(v_2457);
           if (v_2457 != nil) { v_2457 = elt(v_2457, 17); // share
#ifdef RECORD_GET
             if (v_2457 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v_2457 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v_2457 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v_2457 == SPID_NOPROP) v_2457 = nil; else v_2457 = lisp_true; }}
#endif
    if (v_2457 == nil) goto v_2449;
    else goto v_2438;
v_2449:
    goto v_2439;
v_2438:
    v_2457 = v_2458;
    goto v_2437;
v_2439:
    v_2457 = v_2458;
        return Lmkquote(nil, v_2457);
    v_2457 = nil;
v_2437:
    return onevalue(v_2457);
}



// Code for !:plus

static LispObject CC_Tplus(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2495, v_2496, v_2497;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2433,v_2434);
    }
// copy arguments values to proper place
    v_2496 = v_2434;
    v_2497 = v_2433;
// end of prologue
    v_2495 = v_2497;
    if (v_2495 == nil) goto v_2438;
    else goto v_2439;
v_2438:
    v_2495 = v_2496;
    goto v_2437;
v_2439:
    v_2495 = v_2496;
    if (v_2495 == nil) goto v_2442;
    else goto v_2443;
v_2442:
    v_2495 = v_2497;
    goto v_2437;
v_2443:
    v_2495 = v_2497;
    if (!consp(v_2495)) goto v_2450;
    else goto v_2451;
v_2450:
    v_2495 = v_2496;
    v_2495 = (consp(v_2495) ? nil : lisp_true);
    goto v_2449;
v_2451:
    v_2495 = nil;
    goto v_2449;
    v_2495 = nil;
v_2449:
    if (v_2495 == nil) goto v_2447;
    goto v_2463;
v_2459:
    v_2495 = v_2497;
    goto v_2460;
v_2461:
    goto v_2462;
v_2463:
    goto v_2459;
v_2460:
    goto v_2461;
v_2462:
    v_2495 = plus2(v_2495, v_2496);
    v_2497 = v_2495;
    goto v_2475;
v_2471:
    v_2496 = v_2497;
    goto v_2472;
v_2473:
    v_2495 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2474;
v_2475:
    goto v_2471;
v_2472:
    goto v_2473;
v_2474:
    if (v_2496 == v_2495) goto v_2469;
    else goto v_2470;
v_2469:
    v_2495 = nil;
    goto v_2468;
v_2470:
    v_2495 = v_2497;
    goto v_2468;
    v_2495 = nil;
v_2468:
    goto v_2437;
v_2447:
    goto v_2491;
v_2485:
    goto v_2486;
v_2487:
    goto v_2488;
v_2489:
    v_2495 = elt(env, 1); // plus
    goto v_2490;
v_2491:
    goto v_2485;
v_2486:
    goto v_2487;
v_2488:
    goto v_2489;
v_2490:
    {
        fn = elt(env, 2); // dcombine
        return (*qfnn(fn))(fn, 3, v_2497, v_2496, v_2495);
    }
    v_2495 = nil;
v_2437:
    return onevalue(v_2495);
}



// Code for gizerop!:

static LispObject CC_gizeropT(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2461, v_2462, v_2463;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2462 = v_2433;
// end of prologue
    goto v_2443;
v_2439:
    v_2461 = v_2462;
    v_2461 = qcdr(v_2461);
    v_2463 = qcar(v_2461);
    goto v_2440;
v_2441:
    v_2461 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2442;
v_2443:
    goto v_2439;
v_2440:
    goto v_2441;
v_2442:
    if (v_2463 == v_2461) goto v_2437;
    else goto v_2438;
v_2437:
    goto v_2452;
v_2448:
    v_2461 = v_2462;
    v_2461 = qcdr(v_2461);
    v_2462 = qcdr(v_2461);
    goto v_2449;
v_2450:
    v_2461 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2451;
v_2452:
    goto v_2448;
v_2449:
    goto v_2450;
v_2451:
    v_2461 = (v_2462 == v_2461 ? lisp_true : nil);
    goto v_2436;
v_2438:
    v_2461 = nil;
    goto v_2436;
    v_2461 = nil;
v_2436:
    return onevalue(v_2461);
}



// Code for groeb!=testa

static LispObject CC_groebMtesta(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2458, v_2459;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2433,v_2434);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2434;
    v_2458 = v_2433;
// end of prologue
    goto v_2441;
v_2437:
    goto v_2447;
v_2443:
    v_2459 = v_2458;
    goto v_2444;
v_2445:
    v_2458 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_2446;
v_2447:
    goto v_2443;
v_2444:
    goto v_2445;
v_2446:
    fn = elt(env, 1); // nth
    stack[-1] = (*qfn2(fn))(fn, v_2459, v_2458);
    env = stack[-2];
    goto v_2438;
v_2439:
    goto v_2455;
v_2451:
    v_2459 = stack[0];
    goto v_2452;
v_2453:
    v_2458 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_2454;
v_2455:
    goto v_2451;
v_2452:
    goto v_2453;
v_2454:
    fn = elt(env, 1); // nth
    v_2458 = (*qfn2(fn))(fn, v_2459, v_2458);
    env = stack[-2];
    goto v_2440;
v_2441:
    goto v_2437;
v_2438:
    goto v_2439;
v_2440:
    {
        LispObject v_2462 = stack[-1];
        fn = elt(env, 2); // mo_divides!?
        return (*qfn2(fn))(fn, v_2462, v_2458);
    }
}



// Code for resimp1

static LispObject CC_resimp1(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2464, v_2465;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2433;
// end of prologue
    goto v_2443;
v_2439:
    goto v_2449;
v_2445:
    v_2464 = stack[0];
    v_2465 = qcar(v_2464);
    goto v_2446;
v_2447:
    v_2464 = nil;
    goto v_2448;
v_2449:
    goto v_2445;
v_2446:
    goto v_2447;
v_2448:
    fn = elt(env, 2); // subf1
    stack[-1] = (*qfn2(fn))(fn, v_2465, v_2464);
    env = stack[-2];
    goto v_2440;
v_2441:
    goto v_2458;
v_2454:
    v_2464 = stack[0];
    v_2465 = qcdr(v_2464);
    goto v_2455;
v_2456:
    v_2464 = nil;
    goto v_2457;
v_2458:
    goto v_2454;
v_2455:
    goto v_2456;
v_2457:
    fn = elt(env, 2); // subf1
    v_2464 = (*qfn2(fn))(fn, v_2465, v_2464);
    env = stack[-2];
    goto v_2442;
v_2443:
    goto v_2439;
v_2440:
    goto v_2441;
v_2442:
    fn = elt(env, 3); // quotsq
    v_2464 = (*qfn2(fn))(fn, stack[-1], v_2464);
    env = stack[-2];
    stack[0] = v_2464;
    v_2464 = lisp_true;
    qvalue(elt(env, 1)) = v_2464; // !*sub2
    v_2464 = stack[0];
    return onevalue(v_2464);
}



// Code for gperm2

static LispObject CC_gperm2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2474, v_2475, v_2476, v_2477;
    LispObject fn;
    LispObject v_2435, v_2434, v_2433;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "gperm2");
    va_start(aa, nargs);
    v_2433 = va_arg(aa, LispObject);
    v_2434 = va_arg(aa, LispObject);
    v_2435 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_2435,v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_2433,v_2434,v_2435);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_2435;
    stack[-1] = v_2434;
    v_2474 = v_2433;
// end of prologue
v_2440:
    v_2475 = v_2474;
    if (v_2475 == nil) goto v_2443;
    else goto v_2444;
v_2443:
    v_2474 = stack[0];
    goto v_2439;
v_2444:
    v_2475 = v_2474;
    v_2475 = qcdr(v_2475);
    stack[-2] = v_2475;
    goto v_2460;
v_2452:
    goto v_2466;
v_2462:
    v_2475 = qcar(v_2474);
    goto v_2463;
v_2464:
    v_2474 = nil;
    goto v_2465;
v_2466:
    goto v_2462;
v_2463:
    goto v_2464;
v_2465:
    fn = elt(env, 1); // rev
    v_2477 = (*qfn2(fn))(fn, v_2475, v_2474);
    env = stack[-3];
    goto v_2453;
v_2454:
    v_2476 = stack[-1];
    goto v_2455;
v_2456:
    v_2475 = nil;
    goto v_2457;
v_2458:
    v_2474 = stack[0];
    goto v_2459;
v_2460:
    goto v_2452;
v_2453:
    goto v_2454;
v_2455:
    goto v_2456;
v_2457:
    goto v_2458;
v_2459:
    fn = elt(env, 2); // gperm1
    v_2474 = (*qfnn(fn))(fn, 4, v_2477, v_2476, v_2475, v_2474);
    env = stack[-3];
    stack[0] = v_2474;
    v_2474 = stack[-2];
    goto v_2440;
    v_2474 = nil;
v_2439:
    return onevalue(v_2474);
}



// Code for copy

static LispObject CC_copy(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2466, v_2467;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2433;
// end of prologue
    stack[-1] = nil;
v_2438:
    v_2466 = stack[0];
    if (!consp(v_2466)) goto v_2441;
    else goto v_2442;
v_2441:
    goto v_2449;
v_2445:
    v_2467 = stack[-1];
    goto v_2446;
v_2447:
    v_2466 = stack[0];
    goto v_2448;
v_2449:
    goto v_2445;
v_2446:
    goto v_2447;
v_2448:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_2467, v_2466);
    }
v_2442:
    goto v_2459;
v_2455:
    v_2466 = stack[0];
    v_2466 = qcar(v_2466);
    v_2467 = CC_copy(elt(env, 0), v_2466);
    env = stack[-2];
    goto v_2456;
v_2457:
    v_2466 = stack[-1];
    goto v_2458;
v_2459:
    goto v_2455;
v_2456:
    goto v_2457;
v_2458:
    v_2466 = cons(v_2467, v_2466);
    env = stack[-2];
    stack[-1] = v_2466;
    v_2466 = stack[0];
    v_2466 = qcdr(v_2466);
    stack[0] = v_2466;
    goto v_2438;
    v_2466 = nil;
    return onevalue(v_2466);
}



// Code for exptmod!:

static LispObject CC_exptmodT(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2446, v_2447;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2433,v_2434);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_2446 = v_2434;
    v_2447 = v_2433;
// end of prologue
    goto v_2442;
v_2438:
    v_2447 = qcdr(v_2447);
    goto v_2439;
v_2440:
    goto v_2441;
v_2442:
    goto v_2438;
v_2439:
    goto v_2440;
v_2441:
    fn = elt(env, 1); // general!-modular!-expt
    v_2446 = (*qfn2(fn))(fn, v_2447, v_2446);
    env = stack[0];
    {
        fn = elt(env, 2); // !*modular2f
        return (*qfn1(fn))(fn, v_2446);
    }
}



// Code for sgn

static LispObject CC_sgn(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2462, v_2463;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2433;
// end of prologue
    goto v_2444;
v_2440:
    v_2463 = stack[0];
    goto v_2441;
v_2442:
    v_2462 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2443;
v_2444:
    goto v_2440;
v_2441:
    goto v_2442;
v_2443:
    v_2462 = (LispObject)greaterp2(v_2463, v_2462);
    v_2462 = v_2462 ? lisp_true : nil;
    env = stack[-1];
    if (v_2462 == nil) goto v_2438;
    v_2462 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2436;
v_2438:
    goto v_2455;
v_2451:
    v_2463 = stack[0];
    goto v_2452;
v_2453:
    v_2462 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2454;
v_2455:
    goto v_2451;
v_2452:
    goto v_2453;
v_2454:
    v_2462 = (LispObject)lessp2(v_2463, v_2462);
    v_2462 = v_2462 ? lisp_true : nil;
    if (v_2462 == nil) goto v_2449;
    v_2462 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_2436;
v_2449:
    v_2462 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_2436;
    v_2462 = nil;
v_2436:
    return onevalue(v_2462);
}



// Code for anform1

static LispObject CC_anform1(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2558, v_2559;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_2433;
// end of prologue
    v_2558 = stack[-1];
    v_2558 = qcar(v_2558);
    stack[-2] = v_2558;
    v_2558 = stack[-1];
    v_2558 = qcdr(v_2558);
    stack[-1] = v_2558;
    v_2558 = stack[-2];
    if (!consp(v_2558)) goto v_2447;
    v_2558 = stack[-2];
    v_2558 = CC_anform1(elt(env, 0), v_2558);
    env = stack[-3];
    v_2558 = stack[-1];
    {
        fn = elt(env, 8); // anforml
        return (*qfn1(fn))(fn, v_2558);
    }
v_2447:
    v_2558 = stack[-2];
    if (symbolp(v_2558)) goto v_2456;
    v_2558 = nil;
    goto v_2438;
v_2456:
    goto v_2466;
v_2462:
    v_2559 = stack[-2];
    goto v_2463;
v_2464:
    v_2558 = elt(env, 2); // dclglb
    goto v_2465;
v_2466:
    goto v_2462;
v_2463:
    goto v_2464;
v_2465:
    v_2558 = Lflagp(nil, v_2559, v_2558);
    env = stack[-3];
    if (v_2558 == nil) goto v_2460;
    goto v_2478;
v_2474:
    v_2559 = stack[-2];
    goto v_2475;
v_2476:
    v_2558 = elt(env, 3); // glb2rf
    goto v_2477;
v_2478:
    goto v_2474;
v_2475:
    goto v_2476;
v_2477:
    v_2558 = Lflagp(nil, v_2559, v_2558);
    env = stack[-3];
    if (v_2558 == nil) goto v_2471;
    else goto v_2472;
v_2471:
    goto v_2486;
v_2482:
    v_2558 = stack[-2];
    v_2559 = ncons(v_2558);
    env = stack[-3];
    goto v_2483;
v_2484:
    v_2558 = elt(env, 3); // glb2rf
    goto v_2485;
v_2486:
    goto v_2482;
v_2483:
    goto v_2484;
v_2485:
    v_2558 = Lflag(nil, v_2559, v_2558);
    env = stack[-3];
    goto v_2495;
v_2491:
    v_2559 = stack[-2];
    goto v_2492;
v_2493:
    v_2558 = qvalue(elt(env, 4)); // globs!*
    goto v_2494;
v_2495:
    goto v_2491;
v_2492:
    goto v_2493;
v_2494:
    v_2558 = cons(v_2559, v_2558);
    env = stack[-3];
    qvalue(elt(env, 4)) = v_2558; // globs!*
    goto v_2470;
v_2472:
v_2470:
    v_2558 = stack[-1];
    {
        fn = elt(env, 8); // anforml
        return (*qfn1(fn))(fn, v_2558);
    }
v_2460:
    goto v_2506;
v_2502:
    v_2559 = stack[-2];
    goto v_2503;
v_2504:
    v_2558 = qvalue(elt(env, 5)); // locls!*
    goto v_2505;
v_2506:
    goto v_2502;
v_2503:
    goto v_2504;
v_2505:
    v_2558 = Lassoc(nil, v_2559, v_2558);
    if (v_2558 == nil) goto v_2501;
    v_2558 = stack[-1];
    {
        fn = elt(env, 8); // anforml
        return (*qfn1(fn))(fn, v_2558);
    }
v_2501:
    v_2558 = stack[-2];
    fn = elt(env, 9); // add2calls
    v_2558 = (*qfn1(fn))(fn, v_2558);
    env = stack[-3];
    goto v_2519;
v_2515:
    stack[0] = stack[-2];
    goto v_2516;
v_2517:
    v_2558 = stack[-1];
    v_2558 = Llength(nil, v_2558);
    env = stack[-3];
    goto v_2518;
v_2519:
    goto v_2515;
v_2516:
    goto v_2517;
v_2518:
    fn = elt(env, 10); // checkargcount
    v_2558 = (*qfn2(fn))(fn, stack[0], v_2558);
    env = stack[-3];
    goto v_2532;
v_2528:
    v_2559 = stack[-2];
    goto v_2529;
v_2530:
    v_2558 = elt(env, 6); // noanl
    goto v_2531;
v_2532:
    goto v_2528;
v_2529:
    goto v_2530;
v_2531:
    v_2558 = Lflagp(nil, v_2559, v_2558);
    env = stack[-3];
    if (v_2558 == nil) goto v_2526;
    goto v_2524;
v_2526:
    goto v_2543;
v_2539:
    v_2559 = stack[-2];
    goto v_2540;
v_2541:
    v_2558 = elt(env, 7); // anlfn
    goto v_2542;
v_2543:
    goto v_2539;
v_2540:
    goto v_2541;
v_2542:
    v_2558 = get(v_2559, v_2558);
    env = stack[-3];
    v_2559 = v_2558;
    if (v_2558 == nil) goto v_2537;
    goto v_2551;
v_2547:
    goto v_2548;
v_2549:
    v_2558 = stack[-1];
    goto v_2550;
v_2551:
    goto v_2547;
v_2548:
    goto v_2549;
v_2550:
    v_2558 = Lapply1(nil, v_2559, v_2558);
    goto v_2524;
v_2537:
    v_2558 = stack[-1];
    fn = elt(env, 8); // anforml
    v_2558 = (*qfn1(fn))(fn, v_2558);
    goto v_2524;
v_2524:
    v_2558 = nil;
v_2438:
    return onevalue(v_2558);
}



// Code for sfto_gcdf

static LispObject CC_sfto_gcdf(LispObject env,
                         LispObject v_2433, LispObject v_2434)
{
    env = qenv(env);
    LispObject v_2489, v_2490;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_2433,v_2434);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_2434;
    stack[-1] = v_2433;
// end of prologue
    v_2489 = qvalue(elt(env, 1)); // !*rldavgcd
    if (v_2489 == nil) goto v_2438;
    else goto v_2439;
v_2438:
    goto v_2446;
v_2442:
    v_2490 = stack[-1];
    goto v_2443;
v_2444:
    v_2489 = stack[0];
    goto v_2445;
v_2446:
    goto v_2442;
v_2443:
    goto v_2444;
v_2445:
    {
        fn = elt(env, 3); // gcdf
        return (*qfn2(fn))(fn, v_2490, v_2489);
    }
v_2439:
    goto v_2457;
v_2453:
    v_2490 = stack[-1];
    goto v_2454;
v_2455:
    v_2489 = nil;
    goto v_2456;
v_2457:
    goto v_2453;
v_2454:
    goto v_2455;
v_2456:
    fn = elt(env, 4); // sfto_davp
    v_2489 = (*qfn2(fn))(fn, v_2490, v_2489);
    env = stack[-3];
    if (v_2489 == nil) goto v_2451;
    else goto v_2449;
v_2451:
    goto v_2466;
v_2462:
    v_2490 = stack[0];
    goto v_2463;
v_2464:
    v_2489 = nil;
    goto v_2465;
v_2466:
    goto v_2462;
v_2463:
    goto v_2464;
v_2465:
    fn = elt(env, 4); // sfto_davp
    v_2489 = (*qfn2(fn))(fn, v_2490, v_2489);
    env = stack[-3];
    if (v_2489 == nil) goto v_2460;
    else goto v_2449;
v_2460:
    goto v_2450;
v_2449:
    v_2489 = nil;
// Binding !*ezgcd
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 2, -2);
    qvalue(elt(env, 2)) = v_2489; // !*ezgcd
    goto v_2476;
v_2472:
    v_2490 = stack[-1];
    goto v_2473;
v_2474:
    v_2489 = stack[0];
    goto v_2475;
v_2476:
    goto v_2472;
v_2473:
    goto v_2474;
v_2475:
    fn = elt(env, 3); // gcdf
    v_2489 = (*qfn2(fn))(fn, v_2490, v_2489);
    ;}  // end of a binding scope
    goto v_2437;
v_2450:
    goto v_2486;
v_2482:
    v_2490 = stack[-1];
    goto v_2483;
v_2484:
    v_2489 = stack[0];
    goto v_2485;
v_2486:
    goto v_2482;
v_2483:
    goto v_2484;
v_2485:
    {
        fn = elt(env, 5); // ezgcdf
        return (*qfn2(fn))(fn, v_2490, v_2489);
    }
    v_2489 = nil;
v_2437:
    return onevalue(v_2489);
}



// Code for cl_atfp

static LispObject CC_cl_atfp(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_2623, v_2624, v_2625;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_2624 = v_2433;
// end of prologue
    v_2623 = v_2624;
    if (!consp(v_2623)) goto v_2437;
    else goto v_2438;
v_2437:
    v_2623 = v_2624;
    goto v_2436;
v_2438:
    v_2623 = v_2624;
    v_2623 = qcar(v_2623);
    goto v_2436;
    v_2623 = nil;
v_2436:
    v_2625 = v_2623;
    goto v_2458;
v_2454:
    v_2624 = v_2625;
    goto v_2455;
v_2456:
    v_2623 = elt(env, 1); // true
    goto v_2457;
v_2458:
    goto v_2454;
v_2455:
    goto v_2456;
v_2457:
    if (v_2624 == v_2623) goto v_2452;
    else goto v_2453;
v_2452:
    v_2623 = lisp_true;
    goto v_2451;
v_2453:
    goto v_2468;
v_2464:
    v_2624 = v_2625;
    goto v_2465;
v_2466:
    v_2623 = elt(env, 2); // false
    goto v_2467;
v_2468:
    goto v_2464;
v_2465:
    goto v_2466;
v_2467:
    v_2623 = (v_2624 == v_2623 ? lisp_true : nil);
    goto v_2451;
    v_2623 = nil;
v_2451:
    if (v_2623 == nil) goto v_2449;
    v_2623 = lisp_true;
    goto v_2447;
v_2449:
    goto v_2495;
v_2491:
    v_2624 = v_2625;
    goto v_2492;
v_2493:
    v_2623 = elt(env, 3); // or
    goto v_2494;
v_2495:
    goto v_2491;
v_2492:
    goto v_2493;
v_2494:
    if (v_2624 == v_2623) goto v_2489;
    else goto v_2490;
v_2489:
    v_2623 = lisp_true;
    goto v_2488;
v_2490:
    goto v_2505;
v_2501:
    v_2624 = v_2625;
    goto v_2502;
v_2503:
    v_2623 = elt(env, 4); // and
    goto v_2504;
v_2505:
    goto v_2501;
v_2502:
    goto v_2503;
v_2504:
    v_2623 = (v_2624 == v_2623 ? lisp_true : nil);
    goto v_2488;
    v_2623 = nil;
v_2488:
    if (v_2623 == nil) goto v_2486;
    v_2623 = lisp_true;
    goto v_2484;
v_2486:
    goto v_2516;
v_2512:
    v_2624 = v_2625;
    goto v_2513;
v_2514:
    v_2623 = elt(env, 5); // not
    goto v_2515;
v_2516:
    goto v_2512;
v_2513:
    goto v_2514;
v_2515:
    v_2623 = (v_2624 == v_2623 ? lisp_true : nil);
    goto v_2484;
    v_2623 = nil;
v_2484:
    if (v_2623 == nil) goto v_2482;
    v_2623 = lisp_true;
    goto v_2480;
v_2482:
    goto v_2531;
v_2527:
    v_2624 = v_2625;
    goto v_2528;
v_2529:
    v_2623 = elt(env, 6); // impl
    goto v_2530;
v_2531:
    goto v_2527;
v_2528:
    goto v_2529;
v_2530:
    if (v_2624 == v_2623) goto v_2525;
    else goto v_2526;
v_2525:
    v_2623 = lisp_true;
    goto v_2524;
v_2526:
    goto v_2545;
v_2541:
    v_2624 = v_2625;
    goto v_2542;
v_2543:
    v_2623 = elt(env, 7); // repl
    goto v_2544;
v_2545:
    goto v_2541;
v_2542:
    goto v_2543;
v_2544:
    if (v_2624 == v_2623) goto v_2539;
    else goto v_2540;
v_2539:
    v_2623 = lisp_true;
    goto v_2538;
v_2540:
    goto v_2555;
v_2551:
    v_2624 = v_2625;
    goto v_2552;
v_2553:
    v_2623 = elt(env, 8); // equiv
    goto v_2554;
v_2555:
    goto v_2551;
v_2552:
    goto v_2553;
v_2554:
    v_2623 = (v_2624 == v_2623 ? lisp_true : nil);
    goto v_2538;
    v_2623 = nil;
v_2538:
    goto v_2524;
    v_2623 = nil;
v_2524:
    goto v_2480;
    v_2623 = nil;
v_2480:
    if (v_2623 == nil) goto v_2478;
    v_2623 = lisp_true;
    goto v_2476;
v_2478:
    goto v_2574;
v_2570:
    v_2624 = v_2625;
    goto v_2571;
v_2572:
    v_2623 = elt(env, 9); // ex
    goto v_2573;
v_2574:
    goto v_2570;
v_2571:
    goto v_2572;
v_2573:
    if (v_2624 == v_2623) goto v_2568;
    else goto v_2569;
v_2568:
    v_2623 = lisp_true;
    goto v_2567;
v_2569:
    goto v_2584;
v_2580:
    v_2624 = v_2625;
    goto v_2581;
v_2582:
    v_2623 = elt(env, 10); // all
    goto v_2583;
v_2584:
    goto v_2580;
v_2581:
    goto v_2582;
v_2583:
    v_2623 = (v_2624 == v_2623 ? lisp_true : nil);
    goto v_2567;
    v_2623 = nil;
v_2567:
    if (v_2623 == nil) goto v_2565;
    v_2623 = lisp_true;
    goto v_2563;
v_2565:
    goto v_2603;
v_2599:
    v_2624 = v_2625;
    goto v_2600;
v_2601:
    v_2623 = elt(env, 11); // bex
    goto v_2602;
v_2603:
    goto v_2599;
v_2600:
    goto v_2601;
v_2602:
    if (v_2624 == v_2623) goto v_2597;
    else goto v_2598;
v_2597:
    v_2623 = lisp_true;
    goto v_2596;
v_2598:
    goto v_2613;
v_2609:
    v_2623 = v_2625;
    goto v_2610;
v_2611:
    v_2624 = elt(env, 12); // ball
    goto v_2612;
v_2613:
    goto v_2609;
v_2610:
    goto v_2611;
v_2612:
    v_2623 = (v_2623 == v_2624 ? lisp_true : nil);
    goto v_2596;
    v_2623 = nil;
v_2596:
    if (v_2623 == nil) goto v_2594;
    v_2623 = lisp_true;
    goto v_2592;
v_2594:
    v_2623 = v_2625;
    if (!symbolp(v_2623)) v_2623 = nil;
    else { v_2623 = qfastgets(v_2623);
           if (v_2623 != nil) { v_2623 = elt(v_2623, 21); // rl_external
#ifdef RECORD_GET
             if (v_2623 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_2623 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_2623 == SPID_NOPROP) v_2623 = nil; }}
#endif
    goto v_2592;
    v_2623 = nil;
v_2592:
    goto v_2563;
    v_2623 = nil;
v_2563:
    goto v_2476;
    v_2623 = nil;
v_2476:
    goto v_2447;
    v_2623 = nil;
v_2447:
    v_2623 = (v_2623 == nil ? lisp_true : nil);
    return onevalue(v_2623);
}



// Code for powers2

static LispObject CC_powers2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_2500, v_2501, v_2502;
    LispObject fn;
    LispObject v_2435, v_2434, v_2433;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "powers2");
    va_start(aa, nargs);
    v_2433 = va_arg(aa, LispObject);
    v_2434 = va_arg(aa, LispObject);
    v_2435 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_2435,v_2434,v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_2433,v_2434,v_2435);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_2435;
    stack[-1] = v_2434;
    stack[-2] = v_2433;
// end of prologue
v_2440:
    v_2500 = stack[-2];
    if (!consp(v_2500)) goto v_2447;
    else goto v_2448;
v_2447:
    v_2500 = lisp_true;
    goto v_2446;
v_2448:
    v_2500 = stack[-2];
    v_2500 = qcar(v_2500);
    v_2500 = (consp(v_2500) ? nil : lisp_true);
    goto v_2446;
    v_2500 = nil;
v_2446:
    if (v_2500 == nil) goto v_2444;
    v_2500 = stack[-2];
    if (v_2500 == nil) goto v_2458;
    else goto v_2459;
v_2458:
    v_2500 = stack[-1];
    goto v_2439;
v_2459:
    goto v_2469;
v_2465:
    v_2501 = stack[0];
    goto v_2466;
v_2467:
    v_2500 = stack[-1];
    goto v_2468;
v_2469:
    goto v_2465;
v_2466:
    goto v_2467;
v_2468:
    {
        fn = elt(env, 1); // powers4
        return (*qfn2(fn))(fn, v_2501, v_2500);
    }
    goto v_2442;
v_2444:
    v_2500 = stack[-2];
    v_2500 = qcar(v_2500);
    v_2500 = qcdr(v_2500);
    stack[-3] = v_2500;
    goto v_2484;
v_2478:
    v_2500 = stack[-2];
    v_2502 = qcdr(v_2500);
    goto v_2479;
v_2480:
    v_2501 = stack[-1];
    goto v_2481;
v_2482:
    v_2500 = stack[0];
    goto v_2483;
v_2484:
    goto v_2478;
v_2479:
    goto v_2480;
v_2481:
    goto v_2482;
v_2483:
    v_2500 = CC_powers2(elt(env, 0), 3, v_2502, v_2501, v_2500);
    env = stack[-4];
    stack[-1] = v_2500;
    goto v_2494;
v_2490:
    v_2500 = stack[-2];
    v_2500 = qcar(v_2500);
    v_2501 = qcar(v_2500);
    goto v_2491;
v_2492:
    v_2500 = stack[0];
    goto v_2493;
v_2494:
    goto v_2490;
v_2491:
    goto v_2492;
v_2493:
    v_2500 = cons(v_2501, v_2500);
    env = stack[-4];
    stack[0] = v_2500;
    v_2500 = stack[-3];
    stack[-2] = v_2500;
    goto v_2440;
v_2442:
    v_2500 = nil;
v_2439:
    return onevalue(v_2500);
}



// Code for find

static LispObject CC_find(LispObject env,
                         LispObject v_2433)
{
    env = qenv(env);
    LispObject v_3637, v_3638, v_3639;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_2433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2433);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_2433;
// end of prologue
v_2432:
    v_3637 = elt(env, 1); // mcd
    v_3637 = ncons(v_3637);
    env = stack[-3];
    fn = elt(env, 14); // off
    v_3637 = (*qfn1(fn))(fn, v_3637);
    env = stack[-3];
    v_3637 = elt(env, 2); // factor
    v_3637 = ncons(v_3637);
    env = stack[-3];
    fn = elt(env, 14); // off
    v_3637 = (*qfn1(fn))(fn, v_3637);
    env = stack[-3];
    v_3637 = elt(env, 3); // exp
    v_3637 = ncons(v_3637);
    env = stack[-3];
    fn = elt(env, 14); // off
    v_3637 = (*qfn1(fn))(fn, v_3637);
    env = stack[-3];
    v_3637 = stack[-1];
    if (!consp(v_3637)) goto v_2449;
    else goto v_2450;
v_2449:
    goto v_2461;
v_2457:
    v_3638 = stack[-1];
    goto v_2458;
v_2459:
    v_3637 = elt(env, 4); // ww
    goto v_2460;
v_2461:
    goto v_2457;
v_2458:
    goto v_2459;
v_2460:
    fn = elt(env, 15); // freeof
    v_3637 = (*qfn2(fn))(fn, v_3638, v_3637);
    env = stack[-3];
    if (v_3637 == nil) goto v_2455;
    v_3637 = stack[-1];
    if (is_number(v_3637)) goto v_2466;
    else goto v_2467;
v_2466:
    goto v_2474;
v_2470:
    v_3638 = elt(env, 5); // number
    goto v_2471;
v_2472:
    v_3637 = stack[-1];
    goto v_2473;
v_2474:
    goto v_2470;
v_2471:
    goto v_2472;
v_2473:
    return list2(v_3638, v_3637);
v_2467:
    goto v_2487;
v_2483:
    v_3638 = stack[-1];
    goto v_2484;
v_2485:
    v_3637 = elt(env, 6); // e
    goto v_2486;
v_2487:
    goto v_2483;
v_2484:
    goto v_2485;
v_2486:
    if (v_3638 == v_3637) goto v_2481;
    else goto v_2482;
v_2481:
    goto v_2495;
v_2491:
    v_3637 = elt(env, 5); // number
    goto v_2492;
v_2493:
    v_3638 = elt(env, 6); // e
    goto v_2494;
v_2495:
    goto v_2491;
v_2492:
    goto v_2493;
v_2494:
    return list2(v_3637, v_3638);
v_2482:
    goto v_2505;
v_2501:
    v_3638 = elt(env, 7); // x_exp
    goto v_2502;
v_2503:
    v_3637 = stack[-1];
    goto v_2504;
v_2505:
    goto v_2501;
v_2502:
    goto v_2503;
v_2504:
    return list2(v_3638, v_3637);
    goto v_2465;
v_2465:
    goto v_2453;
v_2455:
    goto v_2518;
v_2512:
    v_3638 = elt(env, 8); // expt
    goto v_2513;
v_2514:
    v_3639 = elt(env, 4); // ww
    goto v_2515;
v_2516:
    v_3637 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2517;
v_2518:
    goto v_2512;
v_2513:
    goto v_2514;
v_2515:
    goto v_2516;
v_2517:
    return list3(v_3638, v_3639, v_3637);
v_2453:
    goto v_2448;
v_2450:
    goto v_2532;
v_2528:
    v_3637 = stack[-1];
    v_3638 = qcar(v_3637);
    goto v_2529;
v_2530:
    v_3637 = elt(env, 8); // expt
    goto v_2531;
v_2532:
    goto v_2528;
v_2529:
    goto v_2530;
v_2531:
    if (v_3638 == v_3637) goto v_2526;
    else goto v_2527;
v_2526:
    goto v_2543;
v_2537:
    v_3639 = elt(env, 8); // expt
    goto v_2538;
v_2539:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_2540;
v_2541:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    goto v_2542;
v_2543:
    goto v_2537;
v_2538:
    goto v_2539;
v_2540:
    goto v_2541;
v_2542:
    return list3(v_3639, v_3638, v_3637);
v_2527:
    goto v_2562;
v_2558:
    v_3637 = stack[-1];
    v_3638 = qcar(v_3637);
    goto v_2559;
v_2560:
    v_3637 = elt(env, 9); // plus
    goto v_2561;
v_2562:
    goto v_2558;
v_2559:
    goto v_2560;
v_2561:
    if (v_3638 == v_3637) goto v_2556;
    else goto v_2557;
v_2556:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    if (!consp(v_3637)) goto v_2572;
    else goto v_2573;
v_2572:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = (consp(v_3637) ? nil : lisp_true);
    goto v_2571;
v_2573:
    v_3637 = nil;
    goto v_2571;
    v_3637 = nil;
v_2571:
    if (v_3637 == nil) goto v_2569;
    goto v_2594;
v_2590:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = Llength(nil, v_3637);
    env = stack[-3];
    goto v_2591;
v_2592:
    v_3637 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_2593;
v_2594:
    goto v_2590;
v_2591:
    goto v_2592;
v_2593:
    v_3637 = (LispObject)greaterp2(v_3638, v_3637);
    v_3637 = v_3637 ? lisp_true : nil;
    env = stack[-3];
    if (v_3637 == nil) goto v_2588;
    goto v_2611;
v_2607:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_2608;
v_2609:
    v_3637 = elt(env, 4); // ww
    goto v_2610;
v_2611:
    goto v_2607;
v_2608:
    goto v_2609;
v_2610:
    if (v_3638 == v_3637) goto v_2605;
    else goto v_2606;
v_2605:
    goto v_2621;
v_2617:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_2618;
v_2619:
    v_3637 = elt(env, 4); // ww
    goto v_2620;
v_2621:
    goto v_2617;
v_2618:
    goto v_2619;
v_2620:
    fn = elt(env, 15); // freeof
    v_3637 = (*qfn2(fn))(fn, v_3638, v_3637);
    env = stack[-3];
    goto v_2604;
v_2606:
    v_3637 = nil;
    goto v_2604;
    v_3637 = nil;
v_2604:
    if (v_3637 == nil) goto v_2602;
    goto v_2635;
v_2631:
    goto v_2643;
v_2637:
    v_3639 = elt(env, 8); // expt
    goto v_2638;
v_2639:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_2640;
v_2641:
    v_3637 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2642;
v_2643:
    goto v_2637;
v_2638:
    goto v_2639;
v_2640:
    goto v_2641;
v_2642:
    stack[0] = list3(v_3639, v_3638, v_3637);
    env = stack[-3];
    goto v_2632;
v_2633:
    goto v_2655;
v_2651:
    v_3637 = elt(env, 9); // plus
    v_3638 = ncons(v_3637);
    env = stack[-3];
    goto v_2652;
v_2653:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    goto v_2654;
v_2655:
    goto v_2651;
v_2652:
    goto v_2653;
v_2654:
    v_3637 = Lappend(nil, v_3638, v_3637);
    env = stack[-3];
    v_3637 = CC_find(elt(env, 0), v_3637);
    goto v_2634;
v_2635:
    goto v_2631;
v_2632:
    goto v_2633;
v_2634:
    {
        LispObject v_3643 = stack[0];
        return Lappend(nil, v_3643, v_3637);
    }
v_2602:
    goto v_2668;
v_2664:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    stack[0] = CC_find(elt(env, 0), v_3637);
    env = stack[-3];
    goto v_2665;
v_2666:
    goto v_2678;
v_2674:
    v_3637 = elt(env, 9); // plus
    v_3638 = ncons(v_3637);
    env = stack[-3];
    goto v_2675;
v_2676:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    goto v_2677;
v_2678:
    goto v_2674;
v_2675:
    goto v_2676;
v_2677:
    v_3637 = Lappend(nil, v_3638, v_3637);
    goto v_2667;
v_2668:
    goto v_2664;
v_2665:
    goto v_2666;
v_2667:
    {
        LispObject v_3644 = stack[0];
        return Lappend(nil, v_3644, v_3637);
    }
    goto v_2586;
v_2588:
    goto v_2698;
v_2694:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_2695;
v_2696:
    v_3637 = elt(env, 4); // ww
    goto v_2697;
v_2698:
    goto v_2694;
v_2695:
    goto v_2696;
v_2697:
    if (v_3638 == v_3637) goto v_2692;
    else goto v_2693;
v_2692:
    goto v_2709;
v_2705:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_2706;
v_2707:
    v_3637 = elt(env, 4); // ww
    goto v_2708;
v_2709:
    goto v_2705;
v_2706:
    goto v_2707;
v_2708:
    fn = elt(env, 15); // freeof
    v_3637 = (*qfn2(fn))(fn, v_3638, v_3637);
    env = stack[-3];
    goto v_2691;
v_2693:
    v_3637 = nil;
    goto v_2691;
    v_3637 = nil;
v_2691:
    if (v_3637 == nil) goto v_2689;
    goto v_2726;
v_2718:
    stack[-2] = elt(env, 7); // x_exp
    goto v_2719;
v_2720:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    stack[-1] = qcar(v_3637);
    goto v_2721;
v_2722:
    stack[0] = elt(env, 8); // expt
    goto v_2723;
v_2724:
    goto v_2737;
v_2733:
    v_3638 = elt(env, 4); // ww
    goto v_2734;
v_2735:
    v_3637 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2736;
v_2737:
    goto v_2733;
v_2734:
    goto v_2735;
v_2736:
    v_3637 = list2(v_3638, v_3637);
    goto v_2725;
v_2726:
    goto v_2718;
v_2719:
    goto v_2720;
v_2721:
    goto v_2722;
v_2723:
    goto v_2724;
v_2725:
    {
        LispObject v_3645 = stack[-2];
        LispObject v_3646 = stack[-1];
        LispObject v_3647 = stack[0];
        return list3star(v_3645, v_3646, v_3647, v_3637);
    }
v_2689:
    goto v_2754;
v_2750:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_2751;
v_2752:
    v_3637 = elt(env, 4); // ww
    goto v_2753;
v_2754:
    goto v_2750;
v_2751:
    goto v_2752;
v_2753:
    if (v_3638 == v_3637) goto v_2748;
    else goto v_2749;
v_2748:
    goto v_2764;
v_2760:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_2761;
v_2762:
    v_3637 = elt(env, 4); // ww
    goto v_2763;
v_2764:
    goto v_2760;
v_2761:
    goto v_2762;
v_2763:
    fn = elt(env, 15); // freeof
    v_3637 = (*qfn2(fn))(fn, v_3638, v_3637);
    env = stack[-3];
    goto v_2747;
v_2749:
    v_3637 = nil;
    goto v_2747;
    v_3637 = nil;
v_2747:
    if (v_3637 == nil) goto v_2745;
    goto v_2778;
v_2774:
    goto v_2786;
v_2780:
    v_3639 = elt(env, 8); // expt
    goto v_2781;
v_2782:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_2783;
v_2784:
    v_3637 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2785;
v_2786:
    goto v_2780;
v_2781:
    goto v_2782;
v_2783:
    goto v_2784;
v_2785:
    stack[0] = list3(v_3639, v_3638, v_3637);
    env = stack[-3];
    goto v_2775;
v_2776:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = CC_find(elt(env, 0), v_3637);
    goto v_2777;
v_2778:
    goto v_2774;
v_2775:
    goto v_2776;
v_2777:
    {
        LispObject v_3648 = stack[0];
        return Lappend(nil, v_3648, v_3637);
    }
v_2745:
    goto v_2804;
v_2800:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    stack[0] = CC_find(elt(env, 0), v_3637);
    env = stack[-3];
    goto v_2801;
v_2802:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = CC_find(elt(env, 0), v_3637);
    goto v_2803;
v_2804:
    goto v_2800;
v_2801:
    goto v_2802;
v_2803:
    {
        LispObject v_3649 = stack[0];
        return Lappend(nil, v_3649, v_3637);
    }
    goto v_2687;
v_2687:
    goto v_2586;
v_2586:
    goto v_2567;
v_2569:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    if (!consp(v_3637)) goto v_2822;
    else goto v_2823;
v_2822:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = Lconsp(nil, v_3637);
    env = stack[-3];
    goto v_2821;
v_2823:
    v_3637 = nil;
    goto v_2821;
    v_3637 = nil;
v_2821:
    if (v_3637 == nil) goto v_2819;
    goto v_2844;
v_2840:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = Llength(nil, v_3637);
    env = stack[-3];
    goto v_2841;
v_2842:
    v_3637 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_2843;
v_2844:
    goto v_2840;
v_2841:
    goto v_2842;
v_2843:
    v_3637 = (LispObject)greaterp2(v_3638, v_3637);
    v_3637 = v_3637 ? lisp_true : nil;
    env = stack[-3];
    if (v_3637 == nil) goto v_2838;
    goto v_2857;
v_2853:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_2854;
v_2855:
    v_3637 = elt(env, 4); // ww
    goto v_2856;
v_2857:
    goto v_2853;
v_2854:
    goto v_2855;
v_2856:
    if (v_3638 == v_3637) goto v_2851;
    else goto v_2852;
v_2851:
    goto v_2867;
v_2863:
    goto v_2875;
v_2869:
    v_3639 = elt(env, 8); // expt
    goto v_2870;
v_2871:
    v_3638 = elt(env, 4); // ww
    goto v_2872;
v_2873:
    v_3637 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_2874;
v_2875:
    goto v_2869;
v_2870:
    goto v_2871;
v_2872:
    goto v_2873;
v_2874:
    stack[0] = list3(v_3639, v_3638, v_3637);
    env = stack[-3];
    goto v_2864;
v_2865:
    goto v_2885;
v_2881:
    v_3637 = elt(env, 9); // plus
    v_3638 = ncons(v_3637);
    env = stack[-3];
    goto v_2882;
v_2883:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    goto v_2884;
v_2885:
    goto v_2881;
v_2882:
    goto v_2883;
v_2884:
    v_3637 = Lappend(nil, v_3638, v_3637);
    env = stack[-3];
    v_3637 = CC_find(elt(env, 0), v_3637);
    goto v_2866;
v_2867:
    goto v_2863;
v_2864:
    goto v_2865;
v_2866:
    {
        LispObject v_3650 = stack[0];
        return Lappend(nil, v_3650, v_3637);
    }
v_2852:
    goto v_2898;
v_2894:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    stack[0] = CC_find(elt(env, 0), v_3637);
    env = stack[-3];
    goto v_2895;
v_2896:
    goto v_2909;
v_2905:
    v_3637 = elt(env, 9); // plus
    v_3638 = ncons(v_3637);
    env = stack[-3];
    goto v_2906;
v_2907:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    goto v_2908;
v_2909:
    goto v_2905;
v_2906:
    goto v_2907;
v_2908:
    v_3637 = Lappend(nil, v_3638, v_3637);
    env = stack[-3];
    v_3637 = CC_find(elt(env, 0), v_3637);
    goto v_2897;
v_2898:
    goto v_2894;
v_2895:
    goto v_2896;
v_2897:
    {
        LispObject v_3651 = stack[0];
        return Lappend(nil, v_3651, v_3637);
    }
    goto v_2836;
v_2838:
    goto v_2922;
v_2918:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    stack[0] = CC_find(elt(env, 0), v_3637);
    env = stack[-3];
    goto v_2919;
v_2920:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = CC_find(elt(env, 0), v_3637);
    goto v_2921;
v_2922:
    goto v_2918;
v_2919:
    goto v_2920;
v_2921:
    {
        LispObject v_3652 = stack[0];
        return Lappend(nil, v_3652, v_3637);
    }
v_2836:
    goto v_2817;
v_2819:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = Lconsp(nil, v_3637);
    env = stack[-3];
    if (v_3637 == nil) goto v_2937;
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = Lconsp(nil, v_3637);
    env = stack[-3];
    if (v_3637 == nil) goto v_2937;
    goto v_2958;
v_2954:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = Llength(nil, v_3637);
    env = stack[-3];
    goto v_2955;
v_2956:
    v_3637 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_2957;
v_2958:
    goto v_2954;
v_2955:
    goto v_2956;
v_2957:
    v_3637 = (LispObject)greaterp2(v_3638, v_3637);
    v_3637 = v_3637 ? lisp_true : nil;
    env = stack[-3];
    if (v_3637 == nil) goto v_2952;
    goto v_2968;
v_2964:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    stack[0] = CC_find(elt(env, 0), v_3637);
    env = stack[-3];
    goto v_2965;
v_2966:
    goto v_2979;
v_2975:
    v_3637 = elt(env, 9); // plus
    v_3638 = ncons(v_3637);
    env = stack[-3];
    goto v_2976;
v_2977:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    goto v_2978;
v_2979:
    goto v_2975;
v_2976:
    goto v_2977;
v_2978:
    v_3637 = Lappend(nil, v_3638, v_3637);
    env = stack[-3];
    v_3637 = CC_find(elt(env, 0), v_3637);
    goto v_2967;
v_2968:
    goto v_2964;
v_2965:
    goto v_2966;
v_2967:
    {
        LispObject v_3653 = stack[0];
        return Lappend(nil, v_3653, v_3637);
    }
v_2952:
    goto v_2992;
v_2988:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    stack[0] = CC_find(elt(env, 0), v_3637);
    env = stack[-3];
    goto v_2989;
v_2990:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = CC_find(elt(env, 0), v_3637);
    goto v_2991;
v_2992:
    goto v_2988;
v_2989:
    goto v_2990;
v_2991:
    {
        LispObject v_3654 = stack[0];
        return Lappend(nil, v_3654, v_3637);
    }
    goto v_2935;
v_2937:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = Lconsp(nil, v_3637);
    env = stack[-3];
    if (v_3637 == nil) goto v_3007;
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    if (!consp(v_3637)) goto v_3013;
    else goto v_3007;
v_3013:
    goto v_3027;
v_3023:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = Llength(nil, v_3637);
    env = stack[-3];
    goto v_3024;
v_3025:
    v_3637 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_3026;
v_3027:
    goto v_3023;
v_3024:
    goto v_3025;
v_3026:
    v_3637 = (LispObject)greaterp2(v_3638, v_3637);
    v_3637 = v_3637 ? lisp_true : nil;
    env = stack[-3];
    if (v_3637 == nil) goto v_3021;
    goto v_3040;
v_3036:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_3037;
v_3038:
    v_3637 = elt(env, 4); // ww
    goto v_3039;
v_3040:
    goto v_3036;
v_3037:
    goto v_3038;
v_3039:
    if (v_3638 == v_3637) goto v_3034;
    else goto v_3035;
v_3034:
    goto v_3053;
v_3047:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    stack[-2] = CC_find(elt(env, 0), v_3637);
    env = stack[-3];
    goto v_3048;
v_3049:
    goto v_3065;
v_3059:
    v_3639 = elt(env, 8); // expt
    goto v_3060;
v_3061:
    v_3638 = elt(env, 4); // ww
    goto v_3062;
v_3063:
    v_3637 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3064;
v_3065:
    goto v_3059;
v_3060:
    goto v_3061;
v_3062:
    goto v_3063;
v_3064:
    stack[0] = list3(v_3639, v_3638, v_3637);
    env = stack[-3];
    goto v_3050;
v_3051:
    goto v_3075;
v_3071:
    v_3637 = elt(env, 9); // plus
    v_3638 = ncons(v_3637);
    env = stack[-3];
    goto v_3072;
v_3073:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    goto v_3074;
v_3075:
    goto v_3071;
v_3072:
    goto v_3073;
v_3074:
    v_3637 = Lappend(nil, v_3638, v_3637);
    env = stack[-3];
    v_3637 = CC_find(elt(env, 0), v_3637);
    goto v_3052;
v_3053:
    goto v_3047;
v_3048:
    goto v_3049;
v_3050:
    goto v_3051;
v_3052:
    {
        LispObject v_3655 = stack[-2];
        LispObject v_3656 = stack[0];
        return list2star(v_3655, v_3656, v_3637);
    }
v_3035:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    if (is_number(v_3637)) goto v_3085;
    else goto v_3086;
v_3085:
    goto v_3098;
v_3092:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    stack[-2] = CC_find(elt(env, 0), v_3637);
    env = stack[-3];
    goto v_3093;
v_3094:
    goto v_3108;
v_3104:
    v_3638 = elt(env, 5); // number
    goto v_3105;
v_3106:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    goto v_3107;
v_3108:
    goto v_3104;
v_3105:
    goto v_3106;
v_3107:
    stack[0] = list2(v_3638, v_3637);
    env = stack[-3];
    goto v_3095;
v_3096:
    goto v_3120;
v_3116:
    v_3637 = elt(env, 9); // plus
    v_3638 = ncons(v_3637);
    env = stack[-3];
    goto v_3117;
v_3118:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    goto v_3119;
v_3120:
    goto v_3116;
v_3117:
    goto v_3118;
v_3119:
    v_3637 = Lappend(nil, v_3638, v_3637);
    env = stack[-3];
    v_3637 = CC_find(elt(env, 0), v_3637);
    goto v_3097;
v_3098:
    goto v_3092;
v_3093:
    goto v_3094;
v_3095:
    goto v_3096;
v_3097:
    {
        LispObject v_3657 = stack[-2];
        LispObject v_3658 = stack[0];
        return list2star(v_3657, v_3658, v_3637);
    }
v_3086:
    goto v_3084;
v_3084:
    goto v_3033;
v_3033:
    goto v_3019;
v_3021:
    goto v_3135;
v_3131:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    stack[0] = CC_find(elt(env, 0), v_3637);
    env = stack[-3];
    goto v_3132;
v_3133:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = CC_find(elt(env, 0), v_3637);
    goto v_3134;
v_3135:
    goto v_3131;
v_3132:
    goto v_3133;
v_3134:
    {
        LispObject v_3659 = stack[0];
        return Lappend(nil, v_3659, v_3637);
    }
v_3019:
    goto v_3005;
v_3007:
    goto v_3152;
v_3148:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    stack[0] = CC_find(elt(env, 0), v_3637);
    env = stack[-3];
    goto v_3149;
v_3150:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = ncons(v_3637);
    goto v_3151;
v_3152:
    goto v_3148;
v_3149:
    goto v_3150;
v_3151:
    {
        LispObject v_3660 = stack[0];
        return Lappend(nil, v_3660, v_3637);
    }
v_3005:
    goto v_2935;
v_2935:
    goto v_2817;
v_2817:
    goto v_2567;
v_2567:
    goto v_2555;
v_2557:
    goto v_3172;
v_3168:
    v_3637 = stack[-1];
    v_3638 = qcar(v_3637);
    goto v_3169;
v_3170:
    v_3637 = elt(env, 10); // lminus
    goto v_3171;
v_3172:
    goto v_3168;
v_3169:
    goto v_3170;
v_3171:
    if (v_3638 == v_3637) goto v_3166;
    else goto v_3167;
v_3166:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    if (is_number(v_3637)) goto v_3178;
    else goto v_3179;
v_3178:
    goto v_3188;
v_3184:
    v_3638 = elt(env, 5); // number
    goto v_3185;
v_3186:
    v_3637 = stack[-1];
    goto v_3187;
v_3188:
    goto v_3184;
v_3185:
    goto v_3186;
v_3187:
    return list2(v_3638, v_3637);
v_3179:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    stack[-1] = v_3637;
    goto v_2432;
    goto v_3165;
v_3167:
    goto v_3207;
v_3203:
    v_3637 = stack[-1];
    v_3638 = qcar(v_3637);
    goto v_3204;
v_3205:
    v_3637 = elt(env, 11); // quotient
    goto v_3206;
v_3207:
    goto v_3203;
v_3204:
    goto v_3205;
v_3206:
    if (v_3638 == v_3637) goto v_3201;
    else goto v_3202;
v_3201:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    if (is_number(v_3637)) goto v_3215;
    else goto v_3214;
v_3215:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    if (is_number(v_3637)) goto v_3219;
    else goto v_3214;
v_3219:
    goto v_3231;
v_3225:
    v_3639 = elt(env, 5); // number
    goto v_3226;
v_3227:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_3228;
v_3229:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    goto v_3230;
v_3231:
    goto v_3225;
v_3226:
    goto v_3227;
v_3228:
    goto v_3229;
v_3230:
    return list3(v_3639, v_3638, v_3637);
v_3214:
    goto v_3247;
v_3243:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    stack[0] = CC_find(elt(env, 0), v_3637);
    env = stack[-3];
    goto v_3244;
v_3245:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = CC_find(elt(env, 0), v_3637);
    goto v_3246;
v_3247:
    goto v_3243;
v_3244:
    goto v_3245;
v_3246:
    {
        LispObject v_3661 = stack[0];
        return Lappend(nil, v_3661, v_3637);
    }
    goto v_3200;
v_3202:
    goto v_3267;
v_3263:
    v_3637 = stack[-1];
    v_3638 = qcar(v_3637);
    goto v_3264;
v_3265:
    v_3637 = elt(env, 12); // minus
    goto v_3266;
v_3267:
    goto v_3263;
v_3264:
    goto v_3265;
v_3266:
    if (v_3638 == v_3637) goto v_3261;
    else goto v_3262;
v_3261:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    if (!consp(v_3637)) goto v_3273;
    else goto v_3274;
v_3273:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    stack[-1] = v_3637;
    goto v_2432;
v_3274:
    goto v_3295;
v_3291:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_3292;
v_3293:
    v_3637 = elt(env, 8); // expt
    goto v_3294;
v_3295:
    goto v_3291;
v_3292:
    goto v_3293;
v_3294:
    if (v_3638 == v_3637) goto v_3289;
    else goto v_3290;
v_3289:
    goto v_3304;
v_3300:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_3301;
v_3302:
    v_3637 = elt(env, 4); // ww
    goto v_3303;
v_3304:
    goto v_3300;
v_3301:
    goto v_3302;
v_3303:
    v_3637 = (v_3638 == v_3637 ? lisp_true : nil);
    goto v_3288;
v_3290:
    v_3637 = nil;
    goto v_3288;
    v_3637 = nil;
v_3288:
    if (v_3637 == nil) goto v_3286;
    goto v_3319;
v_3315:
    goto v_3325;
v_3321:
    v_3637 = elt(env, 12); // minus
    stack[0] = ncons(v_3637);
    env = stack[-3];
    goto v_3322;
v_3323:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = CC_find(elt(env, 0), v_3637);
    env = stack[-3];
    goto v_3324;
v_3325:
    goto v_3321;
v_3322:
    goto v_3323;
v_3324:
    stack[0] = Lappend(nil, stack[0], v_3637);
    env = stack[-3];
    goto v_3316;
v_3317:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = CC_find(elt(env, 0), v_3637);
    goto v_3318;
v_3319:
    goto v_3315;
v_3316:
    goto v_3317;
v_3318:
    {
        LispObject v_3662 = stack[0];
        return Lappend(nil, v_3662, v_3637);
    }
v_3286:
    goto v_3344;
v_3340:
    v_3637 = elt(env, 12); // minus
    stack[0] = ncons(v_3637);
    env = stack[-3];
    goto v_3341;
v_3342:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = CC_find(elt(env, 0), v_3637);
    goto v_3343;
v_3344:
    goto v_3340;
v_3341:
    goto v_3342;
v_3343:
    {
        LispObject v_3663 = stack[0];
        return Lappend(nil, v_3663, v_3637);
    }
    goto v_3272;
v_3272:
    goto v_3260;
v_3262:
    goto v_3361;
v_3357:
    v_3637 = stack[-1];
    v_3638 = qcar(v_3637);
    goto v_3358;
v_3359:
    v_3637 = elt(env, 13); // times
    goto v_3360;
v_3361:
    goto v_3357;
v_3358:
    goto v_3359;
v_3360:
    if (v_3638 == v_3637) goto v_3355;
    else goto v_3356;
v_3355:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    if (!consp(v_3637)) goto v_3371;
    else goto v_3372;
v_3371:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = (consp(v_3637) ? nil : lisp_true);
    goto v_3370;
v_3372:
    v_3637 = nil;
    goto v_3370;
    v_3637 = nil;
v_3370:
    if (v_3637 == nil) goto v_3368;
    goto v_3393;
v_3389:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_3390;
v_3391:
    v_3637 = elt(env, 4); // ww
    goto v_3392;
v_3393:
    goto v_3389;
v_3390:
    goto v_3391;
v_3392:
    fn = elt(env, 15); // freeof
    v_3637 = (*qfn2(fn))(fn, v_3638, v_3637);
    env = stack[-3];
    if (v_3637 == nil) goto v_3386;
    else goto v_3387;
v_3386:
    goto v_3405;
v_3399:
    v_3639 = elt(env, 8); // expt
    goto v_3400;
v_3401:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_3402;
v_3403:
    v_3637 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3404;
v_3405:
    goto v_3399;
v_3400:
    goto v_3401;
v_3402:
    goto v_3403;
v_3404:
    return list3(v_3639, v_3638, v_3637);
v_3387:
    goto v_3422;
v_3418:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_3419;
v_3420:
    v_3637 = elt(env, 4); // ww
    goto v_3421;
v_3422:
    goto v_3418;
v_3419:
    goto v_3420;
v_3421:
    fn = elt(env, 15); // freeof
    v_3637 = (*qfn2(fn))(fn, v_3638, v_3637);
    if (v_3637 == nil) goto v_3415;
    else goto v_3416;
v_3415:
    goto v_3433;
v_3429:
    v_3638 = nil;
    goto v_3430;
v_3431:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    goto v_3432;
v_3433:
    goto v_3429;
v_3430:
    goto v_3431;
v_3432:
    return list2(v_3638, v_3637);
v_3416:
    goto v_3414;
v_3414:
    goto v_3385;
v_3385:
    goto v_3366;
v_3368:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    if (!consp(v_3637)) goto v_3450;
    else goto v_3451;
v_3450:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = Lconsp(nil, v_3637);
    env = stack[-3];
    goto v_3449;
v_3451:
    v_3637 = nil;
    goto v_3449;
    v_3637 = nil;
v_3449:
    if (v_3637 == nil) goto v_3447;
    goto v_3472;
v_3468:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_3469;
v_3470:
    v_3637 = elt(env, 4); // ww
    goto v_3471;
v_3472:
    goto v_3468;
v_3469:
    goto v_3470;
v_3471:
    fn = elt(env, 15); // freeof
    v_3637 = (*qfn2(fn))(fn, v_3638, v_3637);
    env = stack[-3];
    if (v_3637 == nil) goto v_3465;
    else goto v_3466;
v_3465:
    goto v_3484;
v_3478:
    v_3639 = elt(env, 8); // expt
    goto v_3479;
v_3480:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_3481;
v_3482:
    v_3637 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3483;
v_3484:
    goto v_3478;
v_3479:
    goto v_3480;
v_3481:
    goto v_3482;
v_3483:
    return list3(v_3639, v_3638, v_3637);
v_3466:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    stack[-1] = v_3637;
    goto v_2432;
    goto v_3445;
v_3447:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = Lconsp(nil, v_3637);
    env = stack[-3];
    if (v_3637 == nil) goto v_3502;
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = Lconsp(nil, v_3637);
    env = stack[-3];
    if (v_3637 == nil) goto v_3502;
    goto v_3523;
v_3519:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = Llength(nil, v_3637);
    env = stack[-3];
    goto v_3520;
v_3521:
    v_3637 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_3522;
v_3523:
    goto v_3519;
v_3520:
    goto v_3521;
v_3522:
    v_3637 = (LispObject)greaterp2(v_3638, v_3637);
    v_3637 = v_3637 ? lisp_true : nil;
    env = stack[-3];
    if (v_3637 == nil) goto v_3517;
    goto v_3533;
v_3529:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    stack[0] = CC_find(elt(env, 0), v_3637);
    env = stack[-3];
    goto v_3530;
v_3531:
    goto v_3544;
v_3540:
    v_3637 = elt(env, 13); // times
    v_3638 = ncons(v_3637);
    env = stack[-3];
    goto v_3541;
v_3542:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    goto v_3543;
v_3544:
    goto v_3540;
v_3541:
    goto v_3542;
v_3543:
    v_3637 = Lappend(nil, v_3638, v_3637);
    env = stack[-3];
    v_3637 = CC_find(elt(env, 0), v_3637);
    goto v_3532;
v_3533:
    goto v_3529;
v_3530:
    goto v_3531;
v_3532:
    {
        LispObject v_3664 = stack[0];
        return Lappend(nil, v_3664, v_3637);
    }
v_3517:
    goto v_3557;
v_3553:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    stack[0] = CC_find(elt(env, 0), v_3637);
    env = stack[-3];
    goto v_3554;
v_3555:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = CC_find(elt(env, 0), v_3637);
    goto v_3556;
v_3557:
    goto v_3553;
v_3554:
    goto v_3555;
v_3556:
    {
        LispObject v_3665 = stack[0];
        return Lappend(nil, v_3665, v_3637);
    }
    goto v_3500;
v_3502:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = Lconsp(nil, v_3637);
    env = stack[-3];
    if (v_3637 == nil) goto v_3572;
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    if (!consp(v_3637)) goto v_3578;
    else goto v_3572;
v_3578:
    goto v_3593;
v_3589:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_3590;
v_3591:
    v_3637 = elt(env, 4); // ww
    goto v_3592;
v_3593:
    goto v_3589;
v_3590:
    goto v_3591;
v_3592:
    fn = elt(env, 15); // freeof
    v_3637 = (*qfn2(fn))(fn, v_3638, v_3637);
    env = stack[-3];
    if (v_3637 == nil) goto v_3586;
    goto v_3603;
v_3599:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3638 = qcar(v_3637);
    goto v_3600;
v_3601:
    v_3637 = elt(env, 4); // ww
    goto v_3602;
v_3603:
    goto v_3599;
v_3600:
    goto v_3601;
v_3602:
    if (v_3638 == v_3637) goto v_3598;
    else goto v_3586;
v_3598:
    goto v_3616;
v_3610:
    v_3638 = elt(env, 8); // expt
    goto v_3611;
v_3612:
    v_3639 = elt(env, 4); // ww
    goto v_3613;
v_3614:
    v_3637 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_3615;
v_3616:
    goto v_3610;
v_3611:
    goto v_3612;
v_3613:
    goto v_3614;
v_3615:
    return list3(v_3638, v_3639, v_3637);
v_3586:
    goto v_3627;
v_3623:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    stack[0] = CC_find(elt(env, 0), v_3637);
    env = stack[-3];
    goto v_3624;
v_3625:
    v_3637 = stack[-1];
    v_3637 = qcdr(v_3637);
    v_3637 = qcdr(v_3637);
    v_3637 = qcar(v_3637);
    v_3637 = CC_find(elt(env, 0), v_3637);
    goto v_3626;
v_3627:
    goto v_3623;
v_3624:
    goto v_3625;
v_3626:
    {
        LispObject v_3666 = stack[0];
        return Lappend(nil, v_3666, v_3637);
    }
    goto v_3570;
v_3572:
v_3570:
    goto v_3500;
v_3500:
    goto v_3445;
v_3445:
    goto v_3366;
v_3366:
    goto v_3354;
v_3356:
v_3354:
    goto v_3260;
v_3260:
    goto v_3200;
v_3200:
    goto v_3165;
v_3165:
    goto v_2555;
v_2555:
    goto v_2525;
v_2525:
    goto v_2448;
v_2448:
    v_3637 = nil;
    return onevalue(v_3637);
}



setup_type const u07_setup[] =
{
    {"gcddd",                   TOO_FEW_2,      CC_gcddd,      WRONG_NO_2},
    {"rat_sgn",                 CC_rat_sgn,     TOO_MANY_1,    WRONG_NO_1},
    {"xcomment",                TOO_FEW_2,      CC_xcomment,   WRONG_NO_2},
    {"mcharg1",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mcharg1},
    {"talp_simplat1",           TOO_FEW_2,      CC_talp_simplat1,WRONG_NO_2},
    {"mathml",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mathml},
    {"exptchk",                 CC_exptchk,     TOO_MANY_1,    WRONG_NO_1},
    {"freeindexchk",            CC_freeindexchk,TOO_MANY_1,    WRONG_NO_1},
    {"areallindices",           CC_areallindices,TOO_MANY_1,   WRONG_NO_1},
    {"getel",                   CC_getel,       TOO_MANY_1,    WRONG_NO_1},
    {"mo=lexcomp",              TOO_FEW_2,      CC_moMlexcomp, WRONG_NO_2},
    {"vecp",                    CC_vecp,        TOO_MANY_1,    WRONG_NO_1},
    {"gperm",                   CC_gperm,       TOO_MANY_1,    WRONG_NO_1},
    {"times-mod-p",             TOO_FEW_2,      CC_timesKmodKp,WRONG_NO_2},
    {"prin2t",                  CC_prin2t,      TOO_MANY_1,    WRONG_NO_1},
    {"wulessp",                 TOO_FEW_2,      CC_wulessp,    WRONG_NO_2},
    {"talp_varlt1",             TOO_FEW_2,      CC_talp_varlt1,WRONG_NO_2},
    {"mri_type",                CC_mri_type,    TOO_MANY_1,    WRONG_NO_1},
    {"qqe_prepat",              CC_qqe_prepat,  TOO_MANY_1,    WRONG_NO_1},
    {"ev_invlexcomp",           TOO_FEW_2,      CC_ev_invlexcomp,WRONG_NO_2},
    {"diplength",               CC_diplength,   TOO_MANY_1,    WRONG_NO_1},
    {"boundindp",               TOO_FEW_2,      CC_boundindp,  WRONG_NO_2},
    {"round:mt",                TOO_FEW_2,      CC_roundTmt,   WRONG_NO_2},
    {"physopp*",                CC_physoppH,    TOO_MANY_1,    WRONG_NO_1},
    {"getrmacro",               CC_getrmacro,   TOO_MANY_1,    WRONG_NO_1},
    {"red-weight",              TOO_FEW_2,      CC_redKweight, WRONG_NO_2},
    {"red_divtestbe",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_red_divtestbe},
    {"pappl_pv",                TOO_FEW_2,      CC_pappl_pv,   WRONG_NO_2},
    {"general-modular-quotient",TOO_FEW_2,      CC_generalKmodularKquotient,WRONG_NO_2},
    {"minus-mod-p",             CC_minusKmodKp, TOO_MANY_1,    WRONG_NO_1},
    {"raddf",                   TOO_FEW_2,      CC_raddf,      WRONG_NO_2},
    {"gcdf1",                   TOO_FEW_2,      CC_gcdf1,      WRONG_NO_2},
    {"talp_smupdknowl",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_smupdknowl},
    {"mri_simplfloor",          CC_mri_simplfloor,TOO_MANY_1,  WRONG_NO_1},
    {"rl_simpat",               CC_rl_simpat,   TOO_MANY_1,    WRONG_NO_1},
    {"kernord",                 TOO_FEW_2,      CC_kernord,    WRONG_NO_2},
    {"quotfd",                  TOO_FEW_2,      CC_quotfd,     WRONG_NO_2},
    {"omobj",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_omobj},
    {"prepd",                   CC_prepd,       TOO_MANY_1,    WRONG_NO_1},
    {"subscriptedvarp",         CC_subscriptedvarp,TOO_MANY_1, WRONG_NO_1},
    {"quotematrix",             CC_quotematrix, TOO_MANY_1,    WRONG_NO_1},
    {"deg*farg",                CC_degHfarg,    TOO_MANY_1,    WRONG_NO_1},
    {"algid",                   TOO_FEW_2,      CC_algid,      WRONG_NO_2},
    {":plus",                   TOO_FEW_2,      CC_Tplus,      WRONG_NO_2},
    {"gizerop:",                CC_gizeropT,    TOO_MANY_1,    WRONG_NO_1},
    {"groeb=testa",             TOO_FEW_2,      CC_groebMtesta,WRONG_NO_2},
    {"resimp1",                 CC_resimp1,     TOO_MANY_1,    WRONG_NO_1},
    {"gperm2",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gperm2},
    {"copy",                    CC_copy,        TOO_MANY_1,    WRONG_NO_1},
    {"exptmod:",                TOO_FEW_2,      CC_exptmodT,   WRONG_NO_2},
    {"sgn",                     CC_sgn,         TOO_MANY_1,    WRONG_NO_1},
    {"anform1",                 CC_anform1,     TOO_MANY_1,    WRONG_NO_1},
    {"sfto_gcdf",               TOO_FEW_2,      CC_sfto_gcdf,  WRONG_NO_2},
    {"cl_atfp",                 CC_cl_atfp,     TOO_MANY_1,    WRONG_NO_1},
    {"powers2",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_powers2},
    {"find",                    CC_find,        TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u07", (two_args *)"72122 7027575 2661600", 0}
};

// end of generated code
