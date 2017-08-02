
// $destdir/u39.c        Machine generated C code

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



// Code for listeval0

static LispObject CC_listeval0(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21797, v_21798, v_21799;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21714;
// end of prologue
    goto v_21729;
v_21725:
    v_21797 = qvalue(elt(env, 2)); // simpcount!*
    v_21798 = add1(v_21797);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_21798; // simpcount!*
    goto v_21726;
v_21727:
    v_21797 = qvalue(elt(env, 3)); // simplimit!*
    goto v_21728;
v_21729:
    goto v_21725;
v_21726:
    goto v_21727;
v_21728:
    v_21797 = (LispObject)greaterp2(v_21798, v_21797);
    v_21797 = v_21797 ? lisp_true : nil;
    env = stack[-1];
    if (v_21797 == nil) goto v_21723;
    v_21797 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 2)) = v_21797; // simpcount!*
    goto v_21741;
v_21735:
    v_21799 = elt(env, 4); // rlisp
    goto v_21736;
v_21737:
    v_21798 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_21738;
v_21739:
    v_21797 = elt(env, 5); // "Simplification recursion too deep"
    goto v_21740;
v_21741:
    goto v_21735;
v_21736:
    goto v_21737;
v_21738:
    goto v_21739;
v_21740:
    fn = elt(env, 7); // rerror
    v_21797 = (*qfnn(fn))(fn, 3, v_21799, v_21798, v_21797);
    env = stack[-1];
    goto v_21721;
v_21723:
v_21721:
    v_21797 = stack[0];
    if (symbolp(v_21797)) goto v_21747;
    else goto v_21748;
v_21747:
    v_21797 = stack[0];
    if (!symbolp(v_21797)) v_21797 = nil;
    else { v_21797 = qfastgets(v_21797);
           if (v_21797 != nil) { v_21797 = elt(v_21797, 17); // share
#ifdef RECORD_GET
             if (v_21797 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v_21797 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v_21797 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v_21797 == SPID_NOPROP) v_21797 = nil; else v_21797 = lisp_true; }}
#endif
    if (v_21797 == nil) goto v_21753;
    v_21797 = stack[0];
    fn = elt(env, 8); // eval
    v_21797 = (*qfn1(fn))(fn, v_21797);
    env = stack[-1];
    v_21797 = CC_listeval0(elt(env, 0), v_21797);
    env = stack[-1];
    stack[0] = v_21797;
    goto v_21751;
v_21753:
    v_21797 = stack[0];
    if (!symbolp(v_21797)) v_21797 = nil;
    else { v_21797 = qfastgets(v_21797);
           if (v_21797 != nil) { v_21797 = elt(v_21797, 4); // avalue
#ifdef RECORD_GET
             if (v_21797 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_21797 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_21797 == SPID_NOPROP) v_21797 = nil; }}
#endif
    v_21799 = v_21797;
    if (v_21797 == nil) goto v_21760;
    goto v_21769;
v_21765:
    v_21797 = v_21799;
    v_21797 = qcdr(v_21797);
    v_21798 = qcar(v_21797);
    goto v_21766;
v_21767:
    v_21797 = stack[0];
    goto v_21768;
v_21769:
    goto v_21765;
v_21766:
    goto v_21767;
v_21768:
    if (equal(v_21798, v_21797)) goto v_21760;
    v_21797 = v_21799;
    v_21797 = qcdr(v_21797);
    v_21797 = qcar(v_21797);
    v_21797 = CC_listeval0(elt(env, 0), v_21797);
    env = stack[-1];
    stack[0] = v_21797;
    goto v_21751;
v_21760:
v_21751:
    goto v_21746;
v_21748:
v_21746:
    goto v_21786;
v_21782:
    v_21797 = stack[0];
    v_21797 = qcar(v_21797);
    fn = elt(env, 9); // getrtype
    v_21798 = (*qfn1(fn))(fn, v_21797);
    env = stack[-1];
    goto v_21783;
v_21784:
    v_21797 = elt(env, 6); // array
    goto v_21785;
v_21786:
    goto v_21782;
v_21783:
    goto v_21784;
v_21785:
    if (v_21798 == v_21797) goto v_21780;
    else goto v_21781;
v_21780:
    v_21797 = stack[0];
    fn = elt(env, 10); // getelv
    v_21797 = (*qfn1(fn))(fn, v_21797);
    env = stack[-1];
    v_21797 = CC_listeval0(elt(env, 0), v_21797);
    env = stack[-1];
    stack[0] = v_21797;
    goto v_21779;
v_21781:
v_21779:
    v_21797 = qvalue(elt(env, 2)); // simpcount!*
    v_21797 = sub1(v_21797);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_21797; // simpcount!*
    v_21797 = stack[0];
    return onevalue(v_21797);
}



// Code for sqprint

static LispObject CC_sqprint(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21855, v_21856, v_21857;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_21714;
// end of prologue
// Binding !*prin!#
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-3, 1, 0);
    qvalue(elt(env, 1)) = nil; // !*prin!#
    v_21855 = lisp_true;
    qvalue(elt(env, 1)) = v_21855; // !*prin!#
    v_21855 = qvalue(elt(env, 3)); // orig!*
    stack[-2] = v_21855;
    v_21855 = qvalue(elt(env, 4)); // !*nat
    if (v_21855 == nil) goto v_21727;
    goto v_21736;
v_21732:
    v_21856 = qvalue(elt(env, 5)); // posn!*
    goto v_21733;
v_21734:
    v_21855 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_21735;
v_21736:
    goto v_21732;
v_21733:
    goto v_21734;
v_21735:
    v_21855 = (LispObject)lessp2(v_21856, v_21855);
    v_21855 = v_21855 ? lisp_true : nil;
    env = stack[-3];
    if (v_21855 == nil) goto v_21727;
    v_21855 = qvalue(elt(env, 5)); // posn!*
    qvalue(elt(env, 3)) = v_21855; // orig!*
    goto v_21725;
v_21727:
v_21725:
    v_21855 = qvalue(elt(env, 6)); // !*pri
    if (v_21855 == nil) goto v_21744;
    else goto v_21742;
v_21744:
    v_21855 = qvalue(elt(env, 7)); // wtl!*
    if (v_21855 == nil) goto v_21746;
    else goto v_21742;
v_21746:
    goto v_21743;
v_21742:
    v_21855 = stack[-1];
    fn = elt(env, 9); // sqhorner!*
    v_21855 = (*qfn1(fn))(fn, v_21855);
    env = stack[-3];
    fn = elt(env, 10); // prepsq!*
    v_21855 = (*qfn1(fn))(fn, v_21855);
    env = stack[-3];
    fn = elt(env, 11); // prepreform
    v_21855 = (*qfn1(fn))(fn, v_21855);
    env = stack[-3];
    fn = elt(env, 12); // maprin
    v_21855 = (*qfn1(fn))(fn, v_21855);
    env = stack[-3];
    goto v_21741;
v_21743:
    goto v_21759;
v_21755:
    v_21855 = stack[-1];
    v_21856 = qcdr(v_21855);
    goto v_21756;
v_21757:
    v_21855 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21758;
v_21759:
    goto v_21755;
v_21756:
    goto v_21757;
v_21758:
    if (v_21856 == v_21855) goto v_21754;
    v_21855 = stack[-1];
    v_21855 = qcar(v_21855);
    if (!consp(v_21855)) goto v_21769;
    else goto v_21770;
v_21769:
    v_21855 = lisp_true;
    goto v_21768;
v_21770:
    v_21855 = stack[-1];
    v_21855 = qcar(v_21855);
    v_21855 = qcar(v_21855);
    v_21855 = (consp(v_21855) ? nil : lisp_true);
    goto v_21768;
    v_21855 = nil;
v_21768:
    if (v_21855 == nil) goto v_21765;
    else goto v_21766;
v_21765:
    v_21855 = stack[-1];
    v_21855 = qcar(v_21855);
    v_21855 = qcdr(v_21855);
    goto v_21764;
v_21766:
    v_21855 = nil;
    goto v_21764;
    v_21855 = nil;
v_21764:
    goto v_21793;
v_21787:
    v_21856 = stack[-1];
    v_21857 = qcar(v_21856);
    goto v_21788;
v_21789:
    v_21856 = v_21855;
    goto v_21790;
v_21791:
    v_21855 = nil;
    goto v_21792;
v_21793:
    goto v_21787;
v_21788:
    goto v_21789;
v_21790:
    goto v_21791;
v_21792:
    fn = elt(env, 13); // xprinf
    v_21855 = (*qfnn(fn))(fn, 3, v_21857, v_21856, v_21855);
    env = stack[-3];
    v_21855 = elt(env, 8); // " / "
    fn = elt(env, 14); // prin2!*
    v_21855 = (*qfn1(fn))(fn, v_21855);
    env = stack[-3];
    v_21855 = stack[-1];
    v_21855 = qcdr(v_21855);
    if (!consp(v_21855)) goto v_21806;
    else goto v_21807;
v_21806:
    v_21855 = lisp_true;
    goto v_21805;
v_21807:
    v_21855 = stack[-1];
    v_21855 = qcdr(v_21855);
    v_21855 = qcar(v_21855);
    v_21855 = (consp(v_21855) ? nil : lisp_true);
    goto v_21805;
    v_21855 = nil;
v_21805:
    if (v_21855 == nil) goto v_21802;
    else goto v_21803;
v_21802:
    v_21855 = stack[-1];
    v_21855 = qcdr(v_21855);
    v_21855 = qcdr(v_21855);
    if (v_21855 == nil) goto v_21819;
    else goto v_21818;
v_21819:
    goto v_21828;
v_21824:
    v_21855 = stack[-1];
    v_21855 = qcdr(v_21855);
    v_21855 = qcar(v_21855);
    v_21856 = qcdr(v_21855);
    goto v_21825;
v_21826:
    v_21855 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21827;
v_21828:
    goto v_21824;
v_21825:
    goto v_21826;
v_21827:
    v_21855 = Lneq(nil, v_21856, v_21855);
    env = stack[-3];
v_21818:
    goto v_21801;
v_21803:
    v_21855 = nil;
    goto v_21801;
    v_21855 = nil;
v_21801:
    goto v_21844;
v_21838:
    v_21856 = stack[-1];
    v_21857 = qcdr(v_21856);
    goto v_21839;
v_21840:
    v_21856 = v_21855;
    goto v_21841;
v_21842:
    v_21855 = nil;
    goto v_21843;
v_21844:
    goto v_21838;
v_21839:
    goto v_21840;
v_21841:
    goto v_21842;
v_21843:
    fn = elt(env, 13); // xprinf
    v_21855 = (*qfnn(fn))(fn, 3, v_21857, v_21856, v_21855);
    env = stack[-3];
    goto v_21741;
v_21754:
    v_21855 = stack[-1];
    v_21855 = qcar(v_21855);
    fn = elt(env, 15); // xprinf2
    v_21855 = (*qfn1(fn))(fn, v_21855);
    env = stack[-3];
    goto v_21741;
v_21741:
    v_21855 = stack[-2];
    qvalue(elt(env, 3)) = v_21855; // orig!*
    ;}  // end of a binding scope
    return onevalue(v_21855);
}



// Code for rootextractf

static LispObject CC_rootextractf(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_22029, v_22030, v_22031;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_21714;
// end of prologue
    v_22029 = stack[-3];
    if (!consp(v_22029)) goto v_21722;
    else goto v_21723;
v_21722:
    v_22029 = lisp_true;
    goto v_21721;
v_21723:
    v_22029 = stack[-3];
    v_22029 = qcar(v_22029);
    v_22029 = (consp(v_22029) ? nil : lisp_true);
    goto v_21721;
    v_22029 = nil;
v_21721:
    if (v_22029 == nil) goto v_21719;
    v_22029 = stack[-3];
    goto v_21717;
v_21719:
    v_22029 = stack[-3];
    v_22029 = qcar(v_22029);
    v_22029 = qcar(v_22029);
    v_22029 = qcar(v_22029);
    stack[-4] = v_22029;
    v_22029 = stack[-3];
    v_22029 = qcar(v_22029);
    v_22029 = qcar(v_22029);
    v_22029 = qcdr(v_22029);
    stack[0] = v_22029;
    v_22029 = stack[-3];
    v_22029 = qcdr(v_22029);
    v_22029 = CC_rootextractf(elt(env, 0), v_22029);
    env = stack[-5];
    stack[-2] = v_22029;
    v_22029 = stack[-3];
    v_22029 = qcar(v_22029);
    v_22029 = qcdr(v_22029);
    v_22029 = CC_rootextractf(elt(env, 0), v_22029);
    env = stack[-5];
    stack[-1] = v_22029;
    v_22029 = stack[-1];
    if (v_22029 == nil) goto v_21759;
    else goto v_21760;
v_21759:
    v_22029 = stack[-2];
    goto v_21740;
v_21760:
    v_22029 = stack[-4];
    if (!consp(v_22029)) goto v_21763;
    else goto v_21764;
v_21763:
    goto v_21773;
v_21767:
    v_22029 = stack[-3];
    v_22029 = qcar(v_22029);
    v_22031 = qcar(v_22029);
    goto v_21768;
v_21769:
    v_22030 = stack[-1];
    goto v_21770;
v_21771:
    v_22029 = stack[-2];
    goto v_21772;
v_21773:
    goto v_21767;
v_21768:
    goto v_21769;
v_21770:
    goto v_21771;
v_21772:
    return acons(v_22031, v_22030, v_22029);
v_21764:
    goto v_21789;
v_21785:
    v_22029 = stack[-4];
    v_22030 = qcar(v_22029);
    goto v_21786;
v_21787:
    v_22029 = elt(env, 2); // sqrt
    goto v_21788;
v_21789:
    goto v_21785;
v_21786:
    goto v_21787;
v_21788:
    if (v_22030 == v_22029) goto v_21783;
    else goto v_21784;
v_21783:
    v_22029 = lisp_true;
    goto v_21782;
v_21784:
    goto v_21804;
v_21800:
    v_22029 = stack[-4];
    v_22030 = qcar(v_22029);
    goto v_21801;
v_21802:
    v_22029 = elt(env, 3); // expt
    goto v_21803;
v_21804:
    goto v_21800;
v_21801:
    goto v_21802;
v_21803:
    if (v_22030 == v_22029) goto v_21798;
    else goto v_21799;
v_21798:
    goto v_21817;
v_21813:
    v_22029 = stack[-4];
    v_22029 = qcdr(v_22029);
    v_22029 = qcdr(v_22029);
    v_22030 = qcar(v_22029);
    goto v_21814;
v_21815:
    v_22029 = elt(env, 4); // quotient
    goto v_21816;
v_21817:
    goto v_21813;
v_21814:
    goto v_21815;
v_21816:
    if (!consp(v_22030)) goto v_21811;
    v_22030 = qcar(v_22030);
    if (v_22030 == v_22029) goto v_21810;
    else goto v_21811;
v_21810:
    goto v_21831;
v_21827:
    v_22029 = stack[-4];
    v_22029 = qcdr(v_22029);
    v_22029 = qcdr(v_22029);
    v_22029 = qcar(v_22029);
    v_22029 = qcdr(v_22029);
    v_22030 = qcar(v_22029);
    goto v_21828;
v_21829:
    v_22029 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21830;
v_21831:
    goto v_21827;
v_21828:
    goto v_21829;
v_21830:
    if (v_22030 == v_22029) goto v_21825;
    else goto v_21826;
v_21825:
    v_22029 = stack[-4];
    v_22029 = qcdr(v_22029);
    v_22029 = qcdr(v_22029);
    v_22029 = qcar(v_22029);
    v_22029 = qcdr(v_22029);
    v_22029 = qcdr(v_22029);
    v_22029 = qcar(v_22029);
    v_22029 = (is_number(v_22029) ? lisp_true : nil);
    goto v_21824;
v_21826:
    v_22029 = nil;
    goto v_21824;
    v_22029 = nil;
v_21824:
    goto v_21809;
v_21811:
    v_22029 = nil;
    goto v_21809;
    v_22029 = nil;
v_21809:
    goto v_21797;
v_21799:
    v_22029 = nil;
    goto v_21797;
    v_22029 = nil;
v_21797:
    goto v_21782;
    v_22029 = nil;
v_21782:
    if (v_22029 == nil) goto v_21780;
    goto v_21861;
v_21857:
    v_22031 = stack[0];
    goto v_21858;
v_21859:
    goto v_21871;
v_21867:
    v_22029 = stack[-4];
    v_22030 = qcar(v_22029);
    goto v_21868;
v_21869:
    v_22029 = elt(env, 2); // sqrt
    goto v_21870;
v_21871:
    goto v_21867;
v_21868:
    goto v_21869;
v_21870:
    if (v_22030 == v_22029) goto v_21865;
    else goto v_21866;
v_21865:
    v_22029 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_21864;
v_21866:
    v_22029 = stack[-4];
    v_22029 = qcdr(v_22029);
    v_22029 = qcdr(v_22029);
    v_22029 = qcar(v_22029);
    v_22029 = qcdr(v_22029);
    v_22029 = qcdr(v_22029);
    v_22029 = qcar(v_22029);
    goto v_21864;
    v_22029 = nil;
v_21864:
    goto v_21860;
v_21861:
    goto v_21857;
v_21858:
    goto v_21859;
v_21860:
    v_22029 = Ldivide(nil, v_22031, v_22029);
    env = stack[-5];
    stack[0] = v_22029;
    goto v_21893;
v_21889:
    v_22029 = stack[0];
    v_22030 = qcar(v_22029);
    goto v_21890;
v_21891:
    v_22029 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21892;
v_21893:
    goto v_21889;
v_21890:
    goto v_21891;
v_21892:
    if (v_22030 == v_22029) goto v_21887;
    else goto v_21888;
v_21887:
    v_22029 = stack[-1];
    if (v_22029 == nil) goto v_21899;
    else goto v_21900;
v_21899:
    v_22029 = stack[-2];
    goto v_21898;
v_21900:
    goto v_21912;
v_21906:
    v_22029 = stack[-3];
    v_22029 = qcar(v_22029);
    v_22031 = qcar(v_22029);
    goto v_21907;
v_21908:
    v_22030 = stack[-1];
    goto v_21909;
v_21910:
    v_22029 = stack[-2];
    goto v_21911;
v_21912:
    goto v_21906;
v_21907:
    goto v_21908;
v_21909:
    goto v_21910;
v_21911:
    return acons(v_22031, v_22030, v_22029);
    v_22029 = nil;
v_21898:
    goto v_21740;
v_21888:
    v_22029 = stack[-4];
    v_22029 = qcdr(v_22029);
    v_22029 = qcar(v_22029);
    if (is_number(v_22029)) goto v_21918;
    else goto v_21919;
v_21918:
    goto v_21928;
v_21924:
    goto v_21934;
v_21930:
    v_22029 = stack[-4];
    v_22029 = qcdr(v_22029);
    v_22030 = qcar(v_22029);
    goto v_21931;
v_21932:
    v_22029 = stack[0];
    v_22029 = qcar(v_22029);
    goto v_21933;
v_21934:
    goto v_21930;
v_21931:
    goto v_21932;
v_21933:
    v_22030 = Lexpt(nil, v_22030, v_22029);
    env = stack[-5];
    goto v_21925;
v_21926:
    v_22029 = stack[-1];
    goto v_21927;
v_21928:
    goto v_21924;
v_21925:
    goto v_21926;
v_21927:
    fn = elt(env, 5); // multd
    v_22029 = (*qfn2(fn))(fn, v_22030, v_22029);
    env = stack[-5];
    stack[-1] = v_22029;
    v_22029 = stack[0];
    v_22029 = qcdr(v_22029);
    stack[0] = v_22029;
    goto v_21886;
v_21919:
    goto v_21951;
v_21947:
    v_22029 = stack[-4];
    v_22029 = qcdr(v_22029);
    v_22030 = qcar(v_22029);
    goto v_21948;
v_21949:
    v_22029 = stack[0];
    v_22029 = qcar(v_22029);
    goto v_21950;
v_21951:
    goto v_21947;
v_21948:
    goto v_21949;
v_21950:
    v_22029 = list2(v_22030, v_22029);
    env = stack[-5];
    fn = elt(env, 6); // simpexpt
    v_22029 = (*qfn1(fn))(fn, v_22029);
    env = stack[-5];
    v_22031 = v_22029;
    goto v_21965;
v_21961:
    v_22029 = v_22031;
    v_22030 = qcdr(v_22029);
    goto v_21962;
v_21963:
    v_22029 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21964;
v_21965:
    goto v_21961;
v_21962:
    goto v_21963;
v_21964:
    if (v_22030 == v_22029) goto v_21959;
    else goto v_21960;
v_21959:
    goto v_21974;
v_21970:
    v_22029 = v_22031;
    v_22030 = qcar(v_22029);
    goto v_21971;
v_21972:
    v_22029 = stack[-1];
    goto v_21973;
v_21974:
    goto v_21970;
v_21971:
    goto v_21972;
v_21973:
    fn = elt(env, 7); // multf
    v_22029 = (*qfn2(fn))(fn, v_22030, v_22029);
    env = stack[-5];
    stack[-1] = v_22029;
    v_22029 = stack[0];
    v_22029 = qcdr(v_22029);
    stack[0] = v_22029;
    goto v_21958;
v_21960:
    v_22029 = stack[-3];
    v_22029 = qcar(v_22029);
    v_22029 = qcar(v_22029);
    v_22029 = qcdr(v_22029);
    stack[0] = v_22029;
    goto v_21958;
v_21958:
    goto v_21886;
v_21886:
    goto v_21758;
v_21780:
v_21758:
    goto v_21994;
v_21990:
    v_22030 = stack[0];
    goto v_21991;
v_21992:
    v_22029 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21993;
v_21994:
    goto v_21990;
v_21991:
    goto v_21992;
v_21993:
    if (v_22030 == v_22029) goto v_21988;
    else goto v_21989;
v_21988:
    goto v_22002;
v_21998:
    v_22030 = stack[-1];
    goto v_21999;
v_22000:
    v_22029 = stack[-2];
    goto v_22001;
v_22002:
    goto v_21998;
v_21999:
    goto v_22000;
v_22001:
    {
        fn = elt(env, 8); // addf
        return (*qfn2(fn))(fn, v_22030, v_22029);
    }
v_21989:
    v_22029 = stack[-1];
    if (v_22029 == nil) goto v_22005;
    else goto v_22006;
v_22005:
    v_22029 = stack[-2];
    goto v_21987;
v_22006:
    goto v_22018;
v_22012:
    goto v_22024;
v_22020:
    v_22030 = stack[-4];
    goto v_22021;
v_22022:
    v_22029 = stack[0];
    goto v_22023;
v_22024:
    goto v_22020;
v_22021:
    goto v_22022;
v_22023:
    fn = elt(env, 9); // to
    v_22031 = (*qfn2(fn))(fn, v_22030, v_22029);
    goto v_22013;
v_22014:
    v_22030 = stack[-1];
    goto v_22015;
v_22016:
    v_22029 = stack[-2];
    goto v_22017;
v_22018:
    goto v_22012;
v_22013:
    goto v_22014;
v_22015:
    goto v_22016;
v_22017:
    return acons(v_22031, v_22030, v_22029);
    v_22029 = nil;
v_21987:
v_21740:
    goto v_21717;
    v_22029 = nil;
v_21717:
    return onevalue(v_22029);
}



// Code for reduce!-eival!-powers

static LispObject CC_reduceKeivalKpowers(LispObject env,
                         LispObject v_21714, LispObject v_21715)
{
    env = qenv(env);
    LispObject v_21778, v_21779, v_21780, v_21781;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21715,v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21714,v_21715);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21780 = v_21715;
    v_21781 = v_21714;
// end of prologue
    v_21778 = v_21780;
    if (!consp(v_21778)) goto v_21727;
    else goto v_21728;
v_21727:
    v_21778 = lisp_true;
    goto v_21726;
v_21728:
    v_21778 = v_21780;
    v_21778 = qcar(v_21778);
    v_21778 = (consp(v_21778) ? nil : lisp_true);
    goto v_21726;
    v_21778 = nil;
v_21726:
    if (v_21778 == nil) goto v_21724;
    v_21778 = lisp_true;
    goto v_21722;
v_21724:
    goto v_21743;
v_21739:
    v_21778 = v_21780;
    v_21778 = qcar(v_21778);
    v_21778 = qcar(v_21778);
    v_21779 = qcar(v_21778);
    goto v_21740;
v_21741:
    v_21778 = v_21781;
    v_21778 = qcar(v_21778);
    v_21778 = qcar(v_21778);
    goto v_21742;
v_21743:
    goto v_21739;
v_21740:
    goto v_21741;
v_21742:
    v_21778 = (v_21779 == v_21778 ? lisp_true : nil);
    v_21778 = (v_21778 == nil ? lisp_true : nil);
    goto v_21722;
    v_21778 = nil;
v_21722:
    if (v_21778 == nil) goto v_21720;
    goto v_21758;
v_21754:
    v_21779 = v_21780;
    goto v_21755;
v_21756:
    v_21778 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21757;
v_21758:
    goto v_21754;
v_21755:
    goto v_21756;
v_21757:
    return cons(v_21779, v_21778);
v_21720:
    goto v_21768;
v_21764:
    stack[0] = v_21781;
    goto v_21765;
v_21766:
    goto v_21775;
v_21771:
    v_21779 = v_21780;
    goto v_21772;
v_21773:
    v_21778 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21774;
v_21775:
    goto v_21771;
v_21772:
    goto v_21773;
v_21774:
    v_21778 = cons(v_21779, v_21778);
    env = stack[-1];
    goto v_21767;
v_21768:
    goto v_21764;
v_21765:
    goto v_21766;
v_21767:
    {
        LispObject v_21783 = stack[0];
        fn = elt(env, 1); // reduce!-eival!-powers1
        return (*qfn2(fn))(fn, v_21783, v_21778);
    }
    v_21778 = nil;
    return onevalue(v_21778);
}



// Code for make!-image

static LispObject CC_makeKimage(LispObject env,
                         LispObject v_21714, LispObject v_21715)
{
    env = qenv(env);
    LispObject v_21799, v_21800, v_21801;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21715,v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21714,v_21715);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21715;
    stack[-1] = v_21714;
// end of prologue
    v_21799 = stack[-1];
    if (!consp(v_21799)) goto v_21723;
    else goto v_21724;
v_21723:
    v_21799 = lisp_true;
    goto v_21722;
v_21724:
    v_21799 = stack[-1];
    v_21799 = qcar(v_21799);
    v_21799 = (consp(v_21799) ? nil : lisp_true);
    goto v_21722;
    v_21799 = nil;
v_21722:
    if (v_21799 == nil) goto v_21720;
    v_21799 = stack[-1];
    goto v_21718;
v_21720:
    goto v_21739;
v_21735:
    v_21799 = stack[-1];
    v_21799 = qcar(v_21799);
    v_21799 = qcar(v_21799);
    v_21800 = qcar(v_21799);
    goto v_21736;
v_21737:
    v_21799 = qvalue(elt(env, 1)); // m!-image!-variable
    goto v_21738;
v_21739:
    goto v_21735;
v_21736:
    goto v_21737;
v_21738:
    if (equal(v_21800, v_21799)) goto v_21733;
    else goto v_21734;
v_21733:
    goto v_21751;
v_21747:
    v_21799 = stack[-1];
    v_21799 = qcar(v_21799);
    v_21800 = qcdr(v_21799);
    goto v_21748;
v_21749:
    v_21799 = stack[0];
    goto v_21750;
v_21751:
    goto v_21747;
v_21748:
    goto v_21749;
v_21750:
    fn = elt(env, 2); // evaluate!-in!-order
    v_21799 = (*qfn2(fn))(fn, v_21800, v_21799);
    env = stack[-3];
    fn = elt(env, 3); // !*n2f
    stack[-2] = (*qfn1(fn))(fn, v_21799);
    env = stack[-3];
    goto v_21761;
v_21757:
    v_21799 = stack[-1];
    v_21800 = qcdr(v_21799);
    goto v_21758;
v_21759:
    v_21799 = stack[0];
    goto v_21760;
v_21761:
    goto v_21757;
v_21758:
    goto v_21759;
v_21760:
    v_21799 = CC_makeKimage(elt(env, 0), v_21800, v_21799);
    v_21800 = stack[-2];
    v_21801 = v_21800;
    if (v_21801 == nil) goto v_21769;
    else goto v_21770;
v_21769:
    goto v_21768;
v_21770:
    goto v_21782;
v_21776:
    v_21801 = stack[-1];
    v_21801 = qcar(v_21801);
    v_21801 = qcar(v_21801);
    goto v_21777;
v_21778:
    goto v_21779;
v_21780:
    goto v_21781;
v_21782:
    goto v_21776;
v_21777:
    goto v_21778;
v_21779:
    goto v_21780;
v_21781:
    return acons(v_21801, v_21800, v_21799);
    v_21799 = nil;
v_21768:
    goto v_21718;
v_21734:
    goto v_21796;
v_21792:
    v_21800 = stack[-1];
    goto v_21793;
v_21794:
    v_21799 = stack[0];
    goto v_21795;
v_21796:
    goto v_21792;
v_21793:
    goto v_21794;
v_21795:
    fn = elt(env, 2); // evaluate!-in!-order
    v_21799 = (*qfn2(fn))(fn, v_21800, v_21799);
    env = stack[-3];
    {
        fn = elt(env, 3); // !*n2f
        return (*qfn1(fn))(fn, v_21799);
    }
    v_21799 = nil;
v_21718:
    return onevalue(v_21799);
}



// Code for ra_u

static LispObject CC_ra_u(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21719;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21719 = v_21714;
// end of prologue
    fn = elt(env, 1); // ra_iv
    v_21719 = (*qfn1(fn))(fn, v_21719);
    env = stack[0];
    {
        fn = elt(env, 2); // riv_u
        return (*qfn1(fn))(fn, v_21719);
    }
}



// Code for ofsf_decdeg2

static LispObject CC_ofsf_decdeg2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21933, v_21934, v_21935;
    LispObject fn;
    LispObject v_21716, v_21715, v_21714;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_decdeg2");
    va_start(aa, nargs);
    v_21714 = va_arg(aa, LispObject);
    v_21715 = va_arg(aa, LispObject);
    v_21716 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21716,v_21715,v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21714,v_21715,v_21716);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_21716;
    stack[-5] = v_21715;
    stack[-3] = v_21714;
// end of prologue
// Binding !*gcd
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-7, 1, -2);
    qvalue(elt(env, 1)) = nil; // !*gcd
    stack[-1] = nil;
    v_21933 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_21933;
    v_21933 = lisp_true;
    qvalue(elt(env, 1)) = v_21933; // !*gcd
    v_21933 = qvalue(elt(env, 3)); // !*rlbrkcxk
    if (v_21933 == nil) goto v_21732;
    goto v_21739;
v_21735:
    v_21934 = stack[-3];
    goto v_21736;
v_21737:
    v_21933 = stack[-5];
    goto v_21738;
v_21739:
    goto v_21735;
v_21736:
    goto v_21737;
v_21738:
    fn = elt(env, 5); // ofsf_cxkdgcd
    v_21933 = (*qfn2(fn))(fn, v_21934, v_21933);
    env = stack[-7];
    stack[0] = v_21933;
    goto v_21730;
v_21732:
v_21730:
    v_21933 = stack[-3];
    fn = elt(env, 6); // cl_atl1
    v_21933 = (*qfn1(fn))(fn, v_21933);
    env = stack[-7];
    stack[-3] = v_21933;
v_21746:
    v_21933 = stack[-3];
    if (v_21933 == nil) goto v_21749;
    goto v_21759;
v_21755:
    v_21934 = stack[0];
    goto v_21756;
v_21757:
    v_21933 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21758;
v_21759:
    goto v_21755;
v_21756:
    goto v_21757;
v_21758:
    v_21933 = Leqn(nil, v_21934, v_21933);
    env = stack[-7];
    if (v_21933 == nil) goto v_21753;
    else goto v_21749;
v_21753:
    goto v_21750;
v_21749:
    goto v_21745;
v_21750:
    v_21933 = stack[-3];
    v_21933 = qcar(v_21933);
    v_21934 = v_21933;
    v_21933 = stack[-3];
    v_21933 = qcdr(v_21933);
    stack[-3] = v_21933;
    v_21933 = v_21934;
    stack[-6] = v_21933;
    goto v_21779;
v_21773:
    v_21935 = stack[-6];
    goto v_21774;
v_21775:
    v_21934 = stack[-5];
    goto v_21776;
v_21777:
    v_21933 = stack[-4];
    goto v_21778;
v_21779:
    goto v_21773;
v_21774:
    goto v_21775;
v_21776:
    goto v_21777;
v_21778:
    fn = elt(env, 7); // ofsf_ignshift
    v_21933 = (*qfnn(fn))(fn, 3, v_21935, v_21934, v_21933);
    env = stack[-7];
    v_21935 = v_21933;
    goto v_21795;
v_21791:
    v_21934 = v_21935;
    goto v_21792;
v_21793:
    v_21933 = elt(env, 4); // odd
    goto v_21794;
v_21795:
    goto v_21791;
v_21792:
    goto v_21793;
v_21794:
    if (v_21934 == v_21933) goto v_21789;
    else goto v_21790;
v_21789:
    v_21933 = stack[-1];
    v_21933 = (v_21933 == nil ? lisp_true : nil);
    goto v_21788;
v_21790:
    v_21933 = nil;
    goto v_21788;
    v_21933 = nil;
v_21788:
    if (v_21933 == nil) goto v_21786;
    v_21933 = elt(env, 4); // odd
    stack[-1] = v_21933;
    goto v_21784;
v_21786:
    v_21933 = v_21935;
    if (v_21933 == nil) goto v_21804;
    else goto v_21805;
v_21804:
    goto v_21812;
v_21808:
    v_21933 = stack[-6];
    v_21933 = qcdr(v_21933);
    v_21934 = qcar(v_21933);
    goto v_21809;
v_21810:
    v_21933 = stack[-5];
    goto v_21811;
v_21812:
    goto v_21808;
v_21809:
    goto v_21810;
v_21811:
    fn = elt(env, 8); // sfto_reorder
    v_21933 = (*qfn2(fn))(fn, v_21934, v_21933);
    env = stack[-7];
    stack[-6] = v_21933;
v_21819:
    v_21933 = stack[-6];
    if (!consp(v_21933)) goto v_21830;
    else goto v_21831;
v_21830:
    v_21933 = lisp_true;
    goto v_21829;
v_21831:
    v_21933 = stack[-6];
    v_21933 = qcar(v_21933);
    v_21933 = (consp(v_21933) ? nil : lisp_true);
    goto v_21829;
    v_21933 = nil;
v_21829:
    if (v_21933 == nil) goto v_21826;
    else goto v_21827;
v_21826:
    goto v_21847;
v_21843:
    v_21933 = stack[-6];
    v_21933 = qcar(v_21933);
    v_21933 = qcar(v_21933);
    v_21934 = qcar(v_21933);
    goto v_21844;
v_21845:
    v_21933 = stack[-5];
    goto v_21846;
v_21847:
    goto v_21843;
v_21844:
    goto v_21845;
v_21846:
    if (v_21934 == v_21933) goto v_21841;
    else goto v_21842;
v_21841:
    goto v_21858;
v_21854:
    v_21934 = stack[0];
    goto v_21855;
v_21856:
    v_21933 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21857;
v_21858:
    goto v_21854;
v_21855:
    goto v_21856;
v_21857:
    v_21933 = Lneq(nil, v_21934, v_21933);
    env = stack[-7];
    goto v_21840;
v_21842:
    v_21933 = nil;
    goto v_21840;
    v_21933 = nil;
v_21840:
    goto v_21825;
v_21827:
    v_21933 = nil;
    goto v_21825;
    v_21933 = nil;
v_21825:
    if (v_21933 == nil) goto v_21822;
    else goto v_21823;
v_21822:
    goto v_21818;
v_21823:
    goto v_21873;
v_21869:
    v_21934 = stack[0];
    goto v_21870;
v_21871:
    v_21933 = stack[-6];
    v_21933 = qcar(v_21933);
    v_21933 = qcar(v_21933);
    v_21933 = qcdr(v_21933);
    goto v_21872;
v_21873:
    goto v_21869;
v_21870:
    goto v_21871;
v_21872:
    fn = elt(env, 9); // gcdf
    v_21933 = (*qfn2(fn))(fn, v_21934, v_21933);
    env = stack[-7];
    stack[0] = v_21933;
    v_21933 = stack[-6];
    v_21933 = qcdr(v_21933);
    stack[-6] = v_21933;
    goto v_21819;
v_21818:
    goto v_21784;
v_21805:
v_21784:
    goto v_21891;
v_21887:
    v_21934 = stack[0];
    goto v_21888;
v_21889:
    v_21933 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21890;
v_21891:
    goto v_21887;
v_21888:
    goto v_21889;
v_21890:
    v_21933 = (LispObject)greaterp2(v_21934, v_21933);
    v_21933 = v_21933 ? lisp_true : nil;
    env = stack[-7];
    if (v_21933 == nil) goto v_21884;
    goto v_21899;
v_21895:
    v_21934 = stack[-1];
    goto v_21896;
v_21897:
    v_21933 = elt(env, 4); // odd
    goto v_21898;
v_21899:
    goto v_21895;
v_21896:
    goto v_21897;
v_21898:
    if (v_21934 == v_21933) goto v_21894;
    else goto v_21884;
v_21894:
    v_21933 = lisp_true;
    stack[-1] = v_21933;
v_21905:
    goto v_21915;
v_21911:
    v_21934 = stack[0];
    goto v_21912;
v_21913:
    v_21933 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_21914;
v_21915:
    goto v_21911;
v_21912:
    goto v_21913;
v_21914:
    fn = elt(env, 10); // quotf
    v_21933 = (*qfn2(fn))(fn, v_21934, v_21933);
    env = stack[-7];
    v_21935 = v_21933;
    if (v_21933 == nil) goto v_21908;
    else goto v_21909;
v_21908:
    goto v_21904;
v_21909:
    v_21933 = v_21935;
    stack[0] = v_21933;
    goto v_21905;
v_21904:
    goto v_21882;
v_21884:
v_21882:
    goto v_21746;
v_21745:
    goto v_21928;
v_21924:
    v_21934 = stack[0];
    goto v_21925;
v_21926:
    v_21933 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21927;
v_21928:
    goto v_21924;
v_21925:
    goto v_21926;
v_21927:
    if (v_21934 == v_21933) goto v_21922;
    else goto v_21923;
v_21922:
    v_21933 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21725;
v_21923:
    v_21933 = stack[0];
v_21725:
    ;}  // end of a binding scope
    return onevalue(v_21933);
}



// Code for cl_atnum

static LispObject CC_cl_atnum(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21966, v_21967, v_21968;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21714;
// end of prologue
v_21713:
    v_21966 = stack[0];
    if (!consp(v_21966)) goto v_21723;
    else goto v_21724;
v_21723:
    v_21966 = stack[0];
    goto v_21722;
v_21724:
    v_21966 = stack[0];
    v_21966 = qcar(v_21966);
    goto v_21722;
    v_21966 = nil;
v_21722:
    v_21968 = v_21966;
    goto v_21751;
v_21747:
    v_21967 = v_21968;
    goto v_21748;
v_21749:
    v_21966 = elt(env, 2); // or
    goto v_21750;
v_21751:
    goto v_21747;
v_21748:
    goto v_21749;
v_21750:
    if (v_21967 == v_21966) goto v_21745;
    else goto v_21746;
v_21745:
    v_21966 = lisp_true;
    goto v_21744;
v_21746:
    goto v_21761;
v_21757:
    v_21967 = v_21968;
    goto v_21758;
v_21759:
    v_21966 = elt(env, 3); // and
    goto v_21760;
v_21761:
    goto v_21757;
v_21758:
    goto v_21759;
v_21760:
    v_21966 = (v_21967 == v_21966 ? lisp_true : nil);
    goto v_21744;
    v_21966 = nil;
v_21744:
    if (v_21966 == nil) goto v_21742;
    v_21966 = lisp_true;
    goto v_21740;
v_21742:
    goto v_21772;
v_21768:
    v_21967 = v_21968;
    goto v_21769;
v_21770:
    v_21966 = elt(env, 4); // not
    goto v_21771;
v_21772:
    goto v_21768;
v_21769:
    goto v_21770;
v_21771:
    v_21966 = (v_21967 == v_21966 ? lisp_true : nil);
    goto v_21740;
    v_21966 = nil;
v_21740:
    if (v_21966 == nil) goto v_21738;
    v_21966 = lisp_true;
    goto v_21736;
v_21738:
    goto v_21787;
v_21783:
    v_21967 = v_21968;
    goto v_21784;
v_21785:
    v_21966 = elt(env, 5); // impl
    goto v_21786;
v_21787:
    goto v_21783;
v_21784:
    goto v_21785;
v_21786:
    if (v_21967 == v_21966) goto v_21781;
    else goto v_21782;
v_21781:
    v_21966 = lisp_true;
    goto v_21780;
v_21782:
    goto v_21801;
v_21797:
    v_21967 = v_21968;
    goto v_21798;
v_21799:
    v_21966 = elt(env, 6); // repl
    goto v_21800;
v_21801:
    goto v_21797;
v_21798:
    goto v_21799;
v_21800:
    if (v_21967 == v_21966) goto v_21795;
    else goto v_21796;
v_21795:
    v_21966 = lisp_true;
    goto v_21794;
v_21796:
    goto v_21811;
v_21807:
    v_21967 = v_21968;
    goto v_21808;
v_21809:
    v_21966 = elt(env, 7); // equiv
    goto v_21810;
v_21811:
    goto v_21807;
v_21808:
    goto v_21809;
v_21810:
    v_21966 = (v_21967 == v_21966 ? lisp_true : nil);
    goto v_21794;
    v_21966 = nil;
v_21794:
    goto v_21780;
    v_21966 = nil;
v_21780:
    goto v_21736;
    v_21966 = nil;
v_21736:
    if (v_21966 == nil) goto v_21734;
    v_21966 = stack[0];
    v_21966 = qcdr(v_21966);
    stack[-1] = v_21966;
    v_21966 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_21966;
v_21819:
    v_21966 = stack[-1];
    if (v_21966 == nil) goto v_21825;
    else goto v_21826;
v_21825:
    v_21966 = stack[0];
    goto v_21818;
v_21826:
    goto v_21834;
v_21830:
    v_21966 = stack[-1];
    v_21966 = qcar(v_21966);
    v_21967 = CC_cl_atnum(elt(env, 0), v_21966);
    env = stack[-2];
    goto v_21831;
v_21832:
    v_21966 = stack[0];
    goto v_21833;
v_21834:
    goto v_21830;
v_21831:
    goto v_21832;
v_21833:
    v_21966 = plus2(v_21967, v_21966);
    env = stack[-2];
    stack[0] = v_21966;
    v_21966 = stack[-1];
    v_21966 = qcdr(v_21966);
    stack[-1] = v_21966;
    goto v_21819;
v_21818:
    goto v_21719;
v_21734:
    goto v_21855;
v_21851:
    v_21967 = v_21968;
    goto v_21852;
v_21853:
    v_21966 = elt(env, 8); // ex
    goto v_21854;
v_21855:
    goto v_21851;
v_21852:
    goto v_21853;
v_21854:
    if (v_21967 == v_21966) goto v_21849;
    else goto v_21850;
v_21849:
    v_21966 = lisp_true;
    goto v_21848;
v_21850:
    goto v_21865;
v_21861:
    v_21967 = v_21968;
    goto v_21862;
v_21863:
    v_21966 = elt(env, 9); // all
    goto v_21864;
v_21865:
    goto v_21861;
v_21862:
    goto v_21863;
v_21864:
    v_21966 = (v_21967 == v_21966 ? lisp_true : nil);
    goto v_21848;
    v_21966 = nil;
v_21848:
    if (v_21966 == nil) goto v_21846;
    v_21966 = stack[0];
    v_21966 = qcdr(v_21966);
    v_21966 = qcdr(v_21966);
    v_21966 = qcar(v_21966);
    stack[0] = v_21966;
    goto v_21713;
v_21846:
    goto v_21886;
v_21882:
    v_21967 = v_21968;
    goto v_21883;
v_21884:
    v_21966 = elt(env, 10); // bex
    goto v_21885;
v_21886:
    goto v_21882;
v_21883:
    goto v_21884;
v_21885:
    if (v_21967 == v_21966) goto v_21880;
    else goto v_21881;
v_21880:
    v_21966 = lisp_true;
    goto v_21879;
v_21881:
    goto v_21896;
v_21892:
    v_21967 = v_21968;
    goto v_21893;
v_21894:
    v_21966 = elt(env, 11); // ball
    goto v_21895;
v_21896:
    goto v_21892;
v_21893:
    goto v_21894;
v_21895:
    v_21966 = (v_21967 == v_21966 ? lisp_true : nil);
    goto v_21879;
    v_21966 = nil;
v_21879:
    if (v_21966 == nil) goto v_21877;
    goto v_21905;
v_21901:
    v_21966 = stack[0];
    v_21966 = qcdr(v_21966);
    v_21966 = qcdr(v_21966);
    v_21966 = qcar(v_21966);
    stack[-1] = CC_cl_atnum(elt(env, 0), v_21966);
    env = stack[-2];
    goto v_21902;
v_21903:
    v_21966 = stack[0];
    v_21966 = qcdr(v_21966);
    v_21966 = qcdr(v_21966);
    v_21966 = qcdr(v_21966);
    v_21966 = qcar(v_21966);
    v_21966 = CC_cl_atnum(elt(env, 0), v_21966);
    goto v_21904;
v_21905:
    goto v_21901;
v_21902:
    goto v_21903;
v_21904:
    {
        LispObject v_21971 = stack[-1];
        return plus2(v_21971, v_21966);
    }
v_21877:
    goto v_21929;
v_21925:
    v_21967 = v_21968;
    goto v_21926;
v_21927:
    v_21966 = elt(env, 12); // true
    goto v_21928;
v_21929:
    goto v_21925;
v_21926:
    goto v_21927;
v_21928:
    if (v_21967 == v_21966) goto v_21923;
    else goto v_21924;
v_21923:
    v_21966 = lisp_true;
    goto v_21922;
v_21924:
    goto v_21939;
v_21935:
    v_21967 = v_21968;
    goto v_21936;
v_21937:
    v_21966 = elt(env, 13); // false
    goto v_21938;
v_21939:
    goto v_21935;
v_21936:
    goto v_21937;
v_21938:
    v_21966 = (v_21967 == v_21966 ? lisp_true : nil);
    goto v_21922;
    v_21966 = nil;
v_21922:
    if (v_21966 == nil) goto v_21920;
    v_21966 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21719;
v_21920:
    goto v_21953;
v_21949:
    v_21967 = v_21968;
    goto v_21950;
v_21951:
    v_21966 = elt(env, 0); // cl_atnum
    goto v_21952;
v_21953:
    goto v_21949;
v_21950:
    goto v_21951;
v_21952:
    fn = elt(env, 14); // rl_external
    v_21966 = (*qfn2(fn))(fn, v_21967, v_21966);
    env = stack[-2];
    v_21967 = v_21966;
    if (v_21966 == nil) goto v_21947;
    goto v_21961;
v_21957:
    stack[-1] = v_21967;
    goto v_21958;
v_21959:
    v_21966 = stack[0];
    v_21966 = ncons(v_21966);
    env = stack[-2];
    goto v_21960;
v_21961:
    goto v_21957;
v_21958:
    goto v_21959;
v_21960:
    {
        LispObject v_21972 = stack[-1];
        fn = elt(env, 15); // apply
        return (*qfn2(fn))(fn, v_21972, v_21966);
    }
v_21947:
    v_21966 = (LispObject)16+TAG_FIXNUM; // 1
v_21719:
    return onevalue(v_21966);
}



// Code for ioto_smaprinbuf

static LispObject CC_ioto_smaprinbuf(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21734, v_21735;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21714;
// end of prologue
    goto v_21721;
v_21717:
    v_21735 = elt(env, 1); // !!
    goto v_21718;
v_21719:
    v_21734 = qvalue(elt(env, 2)); // rlsmaprinbuf!*
    goto v_21720;
v_21721:
    goto v_21717;
v_21718:
    goto v_21719;
v_21720:
    v_21734 = cons(v_21735, v_21734);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_21734; // rlsmaprinbuf!*
    goto v_21730;
v_21726:
    v_21735 = stack[0];
    goto v_21727;
v_21728:
    v_21734 = qvalue(elt(env, 2)); // rlsmaprinbuf!*
    goto v_21729;
v_21730:
    goto v_21726;
v_21727:
    goto v_21728;
v_21729:
    v_21734 = cons(v_21735, v_21734);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_21734; // rlsmaprinbuf!*
    v_21734 = stack[0];
    return onevalue(v_21734);
}



// Code for bvarom

static LispObject CC_bvarom(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21747, v_21748;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21714;
// end of prologue
    v_21747 = stack[0];
    v_21747 = qcar(v_21747);
    v_21747 = Lconsp(nil, v_21747);
    env = stack[-1];
    if (v_21747 == nil) goto v_21722;
    goto v_21734;
v_21730:
    v_21747 = stack[0];
    v_21747 = qcar(v_21747);
    v_21748 = qcar(v_21747);
    goto v_21731;
v_21732:
    v_21747 = elt(env, 1); // bvar
    goto v_21733;
v_21734:
    goto v_21730;
v_21731:
    goto v_21732;
v_21733:
    if (v_21748 == v_21747) goto v_21728;
    else goto v_21729;
v_21728:
    v_21747 = stack[0];
    v_21747 = qcar(v_21747);
    v_21747 = qcdr(v_21747);
    v_21747 = qcar(v_21747);
    fn = elt(env, 2); // objectom
    v_21747 = (*qfn1(fn))(fn, v_21747);
    env = stack[-1];
    v_21747 = stack[0];
    v_21747 = qcdr(v_21747);
    v_21747 = CC_bvarom(elt(env, 0), v_21747);
    goto v_21727;
v_21729:
v_21727:
    goto v_21720;
v_21722:
v_21720:
    v_21747 = nil;
    return onevalue(v_21747);
}



// Code for rewrite

static LispObject CC_rewrite(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_22112, v_22113, v_22114;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-4] = v_21714;
// end of prologue
    v_22112 = elt(env, 1); // list
    v_22112 = ncons(v_22112);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_22112 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    stack[-9] = v_22112;
    goto v_21735;
v_21729:
    v_22114 = elt(env, 2); // part
    goto v_21730;
v_21731:
    v_22113 = stack[-4];
    goto v_21732;
v_21733:
    v_22112 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21734;
v_21735:
    goto v_21729;
v_21730:
    goto v_21731;
v_21732:
    goto v_21733;
v_21734:
    v_22112 = list3(v_22114, v_22113, v_22112);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_22112 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    stack[-8] = v_22112;
    goto v_21746;
v_21740:
    goto v_21753;
v_21749:
    v_22113 = elt(env, 3); // length
    goto v_21750;
v_21751:
    v_22112 = stack[-8];
    goto v_21752;
v_21753:
    goto v_21749;
v_21750:
    goto v_21751;
v_21752:
    v_22112 = list2(v_22113, v_22112);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_22114 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    goto v_21741;
v_21742:
    v_22113 = nil;
    goto v_21743;
v_21744:
    v_22112 = elt(env, 4); // only
    goto v_21745;
v_21746:
    goto v_21740;
v_21741:
    goto v_21742;
v_21743:
    goto v_21744;
v_21745:
    fn = elt(env, 24); // assgnpri
    v_22112 = (*qfnn(fn))(fn, 3, v_22114, v_22113, v_22112);
    env = stack[-10];
    v_22112 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_22112;
v_21761:
    goto v_21775;
v_21769:
    stack[0] = elt(env, 5); // difference
    goto v_21770;
v_21771:
    goto v_21783;
v_21779:
    v_22113 = elt(env, 6); // arglength
    goto v_21780;
v_21781:
    v_22112 = stack[-4];
    goto v_21782;
v_21783:
    goto v_21779;
v_21780:
    goto v_21781;
v_21782:
    v_22112 = list2(v_22113, v_22112);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_22113 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    goto v_21772;
v_21773:
    v_22112 = stack[-5];
    goto v_21774;
v_21775:
    goto v_21769;
v_21770:
    goto v_21771;
v_21772:
    goto v_21773;
v_21774:
    v_22112 = list3(stack[0], v_22113, v_22112);
    env = stack[-10];
    fn = elt(env, 26); // aminusp!:
    v_22112 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    if (v_22112 == nil) goto v_21766;
    goto v_21760;
v_21766:
    goto v_21796;
v_21790:
    stack[-3] = elt(env, 7); // plus
    goto v_21791;
v_21792:
    goto v_21803;
v_21799:
    stack[-1] = elt(env, 3); // length
    goto v_21800;
v_21801:
    goto v_21810;
v_21806:
    stack[0] = elt(env, 8); // den
    goto v_21807;
v_21808:
    goto v_21819;
v_21813:
    v_22114 = elt(env, 2); // part
    goto v_21814;
v_21815:
    v_22113 = stack[-4];
    goto v_21816;
v_21817:
    v_22112 = stack[-5];
    goto v_21818;
v_21819:
    goto v_21813;
v_21814:
    goto v_21815;
v_21816:
    goto v_21817;
v_21818:
    v_22112 = list3(v_22114, v_22113, v_22112);
    env = stack[-10];
    goto v_21809;
v_21810:
    goto v_21806;
v_21807:
    goto v_21808;
v_21809:
    v_22112 = list2(stack[0], v_22112);
    env = stack[-10];
    goto v_21802;
v_21803:
    goto v_21799;
v_21800:
    goto v_21801;
v_21802:
    stack[-2] = list2(stack[-1], v_22112);
    env = stack[-10];
    goto v_21793;
v_21794:
    goto v_21828;
v_21824:
    stack[-1] = elt(env, 3); // length
    goto v_21825;
v_21826:
    goto v_21835;
v_21831:
    stack[0] = elt(env, 9); // num
    goto v_21832;
v_21833:
    goto v_21844;
v_21838:
    v_22114 = elt(env, 2); // part
    goto v_21839;
v_21840:
    v_22113 = stack[-4];
    goto v_21841;
v_21842:
    v_22112 = stack[-5];
    goto v_21843;
v_21844:
    goto v_21838;
v_21839:
    goto v_21840;
v_21841:
    goto v_21842;
v_21843:
    v_22112 = list3(v_22114, v_22113, v_22112);
    env = stack[-10];
    goto v_21834;
v_21835:
    goto v_21831;
v_21832:
    goto v_21833;
v_21834:
    v_22112 = list2(stack[0], v_22112);
    env = stack[-10];
    goto v_21827;
v_21828:
    goto v_21824;
v_21825:
    goto v_21826;
v_21827:
    v_22112 = list2(stack[-1], v_22112);
    env = stack[-10];
    goto v_21795;
v_21796:
    goto v_21790;
v_21791:
    goto v_21792;
v_21793:
    goto v_21794;
v_21795:
    v_22112 = list3(stack[-3], stack[-2], v_22112);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_22112 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    stack[0] = v_22112;
    goto v_21855;
v_21849:
    v_22112 = stack[0];
    fn = elt(env, 25); // aeval!*
    v_22114 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    goto v_21850;
v_21851:
    v_22113 = nil;
    goto v_21852;
v_21853:
    v_22112 = elt(env, 4); // only
    goto v_21854;
v_21855:
    goto v_21849;
v_21850:
    goto v_21851;
v_21852:
    goto v_21853;
v_21854:
    fn = elt(env, 24); // assgnpri
    v_22112 = (*qfnn(fn))(fn, 3, v_22114, v_22113, v_22112);
    env = stack[-10];
    goto v_21869;
v_21865:
    v_22112 = stack[0];
    fn = elt(env, 25); // aeval!*
    stack[-3] = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    goto v_21866;
v_21867:
    goto v_21880;
v_21874:
    stack[-2] = elt(env, 7); // plus
    goto v_21875;
v_21876:
    goto v_21887;
v_21883:
    stack[0] = elt(env, 3); // length
    goto v_21884;
v_21885:
    goto v_21894;
v_21890:
    v_22113 = elt(env, 8); // den
    goto v_21891;
v_21892:
    v_22112 = stack[-8];
    goto v_21893;
v_21894:
    goto v_21890;
v_21891:
    goto v_21892;
v_21893:
    v_22112 = list2(v_22113, v_22112);
    env = stack[-10];
    goto v_21886;
v_21887:
    goto v_21883;
v_21884:
    goto v_21885;
v_21886:
    stack[-1] = list2(stack[0], v_22112);
    env = stack[-10];
    goto v_21877;
v_21878:
    goto v_21902;
v_21898:
    stack[0] = elt(env, 3); // length
    goto v_21899;
v_21900:
    goto v_21909;
v_21905:
    v_22113 = elt(env, 9); // num
    goto v_21906;
v_21907:
    v_22112 = stack[-8];
    goto v_21908;
v_21909:
    goto v_21905;
v_21906:
    goto v_21907;
v_21908:
    v_22112 = list2(v_22113, v_22112);
    env = stack[-10];
    goto v_21901;
v_21902:
    goto v_21898;
v_21899:
    goto v_21900;
v_21901:
    v_22112 = list2(stack[0], v_22112);
    env = stack[-10];
    goto v_21879;
v_21880:
    goto v_21874;
v_21875:
    goto v_21876;
v_21877:
    goto v_21878;
v_21879:
    v_22112 = list3(stack[-2], stack[-1], v_22112);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_22112 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    goto v_21868;
v_21869:
    goto v_21865;
v_21866:
    goto v_21867;
v_21868:
    fn = elt(env, 27); // evallessp
    v_22112 = (*qfn2(fn))(fn, stack[-3], v_22112);
    env = stack[-10];
    if (v_22112 == nil) goto v_21863;
    goto v_21920;
v_21914:
    v_22114 = elt(env, 2); // part
    goto v_21915;
v_21916:
    v_22113 = stack[-4];
    goto v_21917;
v_21918:
    v_22112 = stack[-5];
    goto v_21919;
v_21920:
    goto v_21914;
v_21915:
    goto v_21916;
v_21917:
    goto v_21918;
v_21919:
    v_22112 = list3(v_22114, v_22113, v_22112);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_22112 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    stack[-8] = v_22112;
    goto v_21861;
v_21863:
v_21861:
    v_22112 = nil;
    fn = elt(env, 25); // aeval!*
    v_22112 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    v_22112 = stack[-5];
    goto v_21936;
v_21930:
    v_22114 = elt(env, 7); // plus
    goto v_21931;
v_21932:
    v_22113 = v_22112;
    goto v_21933;
v_21934:
    v_22112 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21935;
v_21936:
    goto v_21930;
v_21931:
    goto v_21932;
v_21933:
    goto v_21934;
v_21935:
    v_22112 = list3(v_22114, v_22113, v_22112);
    env = stack[-10];
    fn = elt(env, 25); // aeval!*
    v_22112 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    stack[-5] = v_22112;
    goto v_21761;
v_21760:
    goto v_21947;
v_21941:
    v_22112 = elt(env, 10); // "g is "
    fn = elt(env, 23); // aeval
    v_22114 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    goto v_21942;
v_21943:
    v_22113 = nil;
    goto v_21944;
v_21945:
    v_22112 = elt(env, 11); // first
    goto v_21946;
v_21947:
    goto v_21941;
v_21942:
    goto v_21943;
v_21944:
    goto v_21945;
v_21946:
    fn = elt(env, 24); // assgnpri
    v_22112 = (*qfnn(fn))(fn, 3, v_22114, v_22113, v_22112);
    env = stack[-10];
    goto v_21959;
v_21953:
    v_22112 = stack[-8];
    fn = elt(env, 23); // aeval
    v_22114 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    goto v_21954;
v_21955:
    v_22113 = nil;
    goto v_21956;
v_21957:
    v_22112 = elt(env, 12); // last
    goto v_21958;
v_21959:
    goto v_21953;
v_21954:
    goto v_21955;
v_21956:
    goto v_21957;
v_21958:
    fn = elt(env, 24); // assgnpri
    v_22112 = (*qfnn(fn))(fn, 3, v_22114, v_22113, v_22112);
    env = stack[-10];
    v_22112 = stack[-4];
    fn = elt(env, 23); // aeval
    v_22112 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    fn = elt(env, 28); // getrlist
    v_22112 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    stack[-6] = v_22112;
v_21967:
    v_22112 = stack[-6];
    if (v_22112 == nil) goto v_21973;
    else goto v_21974;
v_21973:
    goto v_21966;
v_21974:
    v_22112 = stack[-6];
    v_22112 = qcar(v_22112);
    stack[0] = v_22112;
    goto v_21990;
v_21982:
    stack[-3] = elt(env, 13); // limit
    goto v_21983;
v_21984:
    goto v_21999;
v_21993:
    stack[-2] = elt(env, 14); // quotient
    goto v_21994;
v_21995:
    goto v_22006;
v_22002:
    v_22113 = elt(env, 15); // log
    goto v_22003;
v_22004:
    v_22112 = stack[0];
    goto v_22005;
v_22006:
    goto v_22002;
v_22003:
    goto v_22004;
v_22005:
    stack[-1] = list2(v_22113, v_22112);
    env = stack[-10];
    goto v_21996;
v_21997:
    goto v_22014;
v_22010:
    v_22113 = elt(env, 15); // log
    goto v_22011;
v_22012:
    v_22112 = stack[-8];
    goto v_22013;
v_22014:
    goto v_22010;
v_22011:
    goto v_22012;
v_22013:
    v_22112 = list2(v_22113, v_22112);
    env = stack[-10];
    goto v_21998;
v_21999:
    goto v_21993;
v_21994:
    goto v_21995;
v_21996:
    goto v_21997;
v_21998:
    v_22114 = list3(stack[-2], stack[-1], v_22112);
    env = stack[-10];
    goto v_21985;
v_21986:
    v_22113 = elt(env, 16); // x
    goto v_21987;
v_21988:
    v_22112 = elt(env, 17); // infinity
    goto v_21989;
v_21990:
    goto v_21982;
v_21983:
    goto v_21984;
v_21985:
    goto v_21986;
v_21987:
    goto v_21988;
v_21989:
    v_22112 = list4(stack[-3], v_22114, v_22113, v_22112);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_22112 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    stack[-7] = v_22112;
    goto v_22027;
v_22021:
    stack[-5] = elt(env, 18); // expt
    goto v_22022;
v_22023:
    stack[-4] = elt(env, 19); // e
    goto v_22024;
v_22025:
    goto v_22037;
v_22031:
    stack[-3] = elt(env, 5); // difference
    goto v_22032;
v_22033:
    goto v_22044;
v_22040:
    v_22113 = elt(env, 15); // log
    goto v_22041;
v_22042:
    v_22112 = stack[0];
    goto v_22043;
v_22044:
    goto v_22040;
v_22041:
    goto v_22042;
v_22043:
    stack[-2] = list2(v_22113, v_22112);
    env = stack[-10];
    goto v_22034;
v_22035:
    goto v_22054;
v_22048:
    stack[-1] = elt(env, 20); // times
    goto v_22049;
v_22050:
    stack[0] = stack[-7];
    goto v_22051;
v_22052:
    goto v_22062;
v_22058:
    v_22113 = elt(env, 15); // log
    goto v_22059;
v_22060:
    v_22112 = stack[-8];
    goto v_22061;
v_22062:
    goto v_22058;
v_22059:
    goto v_22060;
v_22061:
    v_22112 = list2(v_22113, v_22112);
    env = stack[-10];
    goto v_22053;
v_22054:
    goto v_22048;
v_22049:
    goto v_22050;
v_22051:
    goto v_22052;
v_22053:
    v_22112 = list3(stack[-1], stack[0], v_22112);
    env = stack[-10];
    goto v_22036;
v_22037:
    goto v_22031;
v_22032:
    goto v_22033;
v_22034:
    goto v_22035;
v_22036:
    v_22112 = list3(stack[-3], stack[-2], v_22112);
    env = stack[-10];
    goto v_22026;
v_22027:
    goto v_22021;
v_22022:
    goto v_22023;
v_22024:
    goto v_22025;
v_22026:
    v_22112 = list3(stack[-5], stack[-4], v_22112);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_22112 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    goto v_22073;
v_22067:
    stack[-1] = elt(env, 20); // times
    goto v_22068;
v_22069:
    stack[0] = v_22112;
    goto v_22070;
v_22071:
    goto v_22083;
v_22077:
    v_22114 = elt(env, 18); // expt
    goto v_22078;
v_22079:
    v_22113 = elt(env, 21); // w
    goto v_22080;
v_22081:
    v_22112 = stack[-7];
    goto v_22082;
v_22083:
    goto v_22077;
v_22078:
    goto v_22079;
v_22080:
    goto v_22081;
v_22082:
    v_22112 = list3(v_22114, v_22113, v_22112);
    env = stack[-10];
    goto v_22072;
v_22073:
    goto v_22067;
v_22068:
    goto v_22069;
v_22070:
    goto v_22071;
v_22072:
    v_22112 = list3(stack[-1], stack[0], v_22112);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_22112 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    stack[0] = v_22112;
    goto v_22095;
v_22089:
    stack[-1] = elt(env, 22); // append
    goto v_22090;
v_22091:
    goto v_22102;
v_22098:
    v_22113 = elt(env, 1); // list
    goto v_22099;
v_22100:
    v_22112 = stack[0];
    goto v_22101;
v_22102:
    goto v_22098;
v_22099:
    goto v_22100;
v_22101:
    v_22113 = list2(v_22113, v_22112);
    env = stack[-10];
    goto v_22092;
v_22093:
    v_22112 = stack[-9];
    goto v_22094;
v_22095:
    goto v_22089;
v_22090:
    goto v_22091;
v_22092:
    goto v_22093;
v_22094:
    v_22112 = list3(stack[-1], v_22113, v_22112);
    env = stack[-10];
    fn = elt(env, 23); // aeval
    v_22112 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    stack[-9] = v_22112;
    v_22112 = nil;
    fn = elt(env, 23); // aeval
    v_22112 = (*qfn1(fn))(fn, v_22112);
    env = stack[-10];
    v_22112 = stack[-6];
    v_22112 = qcdr(v_22112);
    stack[-6] = v_22112;
    goto v_21967;
v_21966:
    v_22112 = stack[-9];
    {
        fn = elt(env, 23); // aeval
        return (*qfn1(fn))(fn, v_22112);
    }
    return onevalue(v_22112);
}



// Code for s!-nextarg

static LispObject CC_sKnextarg(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21931, v_21932, v_21933;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21714;
// end of prologue
    v_21931 = qvalue(elt(env, 2)); // !*udebug
    if (v_21931 == nil) goto v_21724;
    v_21931 = nil;
    fn = elt(env, 13); // uprint
    v_21931 = (*qfn1(fn))(fn, v_21931);
    env = stack[-2];
    goto v_21722;
v_21724:
v_21722:
    v_21931 = qvalue(elt(env, 3)); // comb
    if (v_21931 == nil) goto v_21730;
    else goto v_21731;
v_21730:
    v_21931 = qvalue(elt(env, 4)); // i
    v_21931 = add1(v_21931);
    env = stack[-2];
    qvalue(elt(env, 4)) = v_21931; // i
    v_21931 = stack[0];
    fn = elt(env, 14); // initcomb
    v_21931 = (*qfn1(fn))(fn, v_21931);
    env = stack[-2];
    qvalue(elt(env, 3)) = v_21931; // comb
    goto v_21729;
v_21731:
v_21729:
    goto v_21746;
v_21742:
    v_21932 = stack[0];
    goto v_21743;
v_21744:
    v_21931 = qvalue(elt(env, 3)); // comb
    goto v_21745;
v_21746:
    goto v_21742;
v_21743:
    goto v_21744;
v_21745:
    fn = elt(env, 15); // getcomb
    v_21931 = (*qfn2(fn))(fn, v_21932, v_21931);
    env = stack[-2];
    stack[-1] = v_21931;
    if (v_21931 == nil) goto v_21740;
    goto v_21761;
v_21757:
    v_21932 = qvalue(elt(env, 4)); // i
    goto v_21758;
v_21759:
    v_21931 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21760;
v_21761:
    goto v_21757;
v_21758:
    goto v_21759;
v_21760:
    if (v_21932 == v_21931) goto v_21755;
    else goto v_21756;
v_21755:
    goto v_21769;
v_21765:
    v_21932 = qvalue(elt(env, 4)); // i
    goto v_21766;
v_21767:
    v_21931 = qvalue(elt(env, 5)); // upb
    goto v_21768;
v_21769:
    goto v_21765;
v_21766:
    goto v_21767;
v_21768:
    v_21931 = (LispObject)lesseq2(v_21932, v_21931);
    v_21931 = v_21931 ? lisp_true : nil;
    env = stack[-2];
    goto v_21754;
v_21756:
    v_21931 = nil;
    goto v_21754;
    v_21931 = nil;
v_21754:
    if (v_21931 == nil) goto v_21752;
    goto v_21780;
v_21776:
    v_21931 = stack[-1];
    v_21931 = qcar(v_21931);
    v_21932 = qcar(v_21931);
    goto v_21777;
v_21778:
    v_21931 = stack[-1];
    v_21931 = qcdr(v_21931);
    goto v_21779;
v_21780:
    goto v_21776;
v_21777:
    goto v_21778;
v_21779:
    return cons(v_21932, v_21931);
v_21752:
    goto v_21796;
v_21792:
    v_21932 = qvalue(elt(env, 4)); // i
    goto v_21793;
v_21794:
    v_21931 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21795;
v_21796:
    goto v_21792;
v_21793:
    goto v_21794;
v_21795:
    if (v_21932 == v_21931) goto v_21790;
    else goto v_21791;
v_21790:
    goto v_21804;
v_21800:
    v_21932 = qvalue(elt(env, 4)); // i
    goto v_21801;
v_21802:
    v_21931 = qvalue(elt(env, 5)); // upb
    goto v_21803;
v_21804:
    goto v_21800;
v_21801:
    goto v_21802;
v_21803:
    v_21931 = (LispObject)lesseq2(v_21932, v_21931);
    v_21931 = v_21931 ? lisp_true : nil;
    env = stack[-2];
    goto v_21789;
v_21791:
    v_21931 = nil;
    goto v_21789;
    v_21931 = nil;
v_21789:
    if (v_21931 == nil) goto v_21787;
    goto v_21815;
v_21811:
    v_21932 = elt(env, 6); // (null!-fn)
    goto v_21812;
v_21813:
    v_21931 = stack[0];
    goto v_21814;
v_21815:
    goto v_21811;
v_21812:
    goto v_21813;
v_21814:
    return cons(v_21932, v_21931);
v_21787:
    v_21931 = qvalue(elt(env, 7)); // acontract
    if (v_21931 == nil) goto v_21819;
    goto v_21828;
v_21824:
    v_21932 = qvalue(elt(env, 4)); // i
    goto v_21825;
v_21826:
    v_21931 = qvalue(elt(env, 5)); // upb
    goto v_21827;
v_21828:
    goto v_21824;
v_21825:
    goto v_21826;
v_21827:
    v_21931 = (LispObject)lesseq2(v_21932, v_21931);
    v_21931 = v_21931 ? lisp_true : nil;
    env = stack[-2];
    if (v_21931 == nil) goto v_21819;
    goto v_21839;
v_21833:
    v_21933 = qvalue(elt(env, 8)); // op
    goto v_21834;
v_21835:
    v_21931 = stack[-1];
    v_21932 = qcar(v_21931);
    goto v_21836;
v_21837:
    v_21931 = stack[-1];
    v_21931 = qcdr(v_21931);
    goto v_21838;
v_21839:
    goto v_21833;
v_21834:
    goto v_21835;
v_21836:
    goto v_21837;
v_21838:
    v_21931 = acons(v_21933, v_21932, v_21931);
    env = stack[-2];
    {
        fn = elt(env, 16); // mval
        return (*qfn1(fn))(fn, v_21931);
    }
v_21819:
    v_21931 = qvalue(elt(env, 9)); // mcontract
    if (v_21931 == nil) goto v_21846;
    goto v_21855;
v_21851:
    v_21932 = qvalue(elt(env, 4)); // i
    goto v_21852;
v_21853:
    v_21931 = qvalue(elt(env, 5)); // upb
    goto v_21854;
v_21855:
    goto v_21851;
v_21852:
    goto v_21853;
v_21854:
    v_21931 = (LispObject)lesseq2(v_21932, v_21931);
    v_21931 = v_21931 ? lisp_true : nil;
    env = stack[-2];
    if (v_21931 == nil) goto v_21846;
    goto v_21865;
v_21859:
    v_21933 = elt(env, 10); // null!-fn
    goto v_21860;
v_21861:
    v_21931 = stack[-1];
    v_21932 = qcar(v_21931);
    goto v_21862;
v_21863:
    v_21931 = stack[-1];
    v_21931 = qcdr(v_21931);
    goto v_21864;
v_21865:
    goto v_21859;
v_21860:
    goto v_21861;
v_21862:
    goto v_21863;
v_21864:
    return acons(v_21933, v_21932, v_21931);
v_21846:
    v_21931 = qvalue(elt(env, 11)); // expand
    if (v_21931 == nil) goto v_21872;
    v_21931 = nil;
    qvalue(elt(env, 11)) = v_21931; // expand
    goto v_21880;
v_21876:
    v_21932 = qvalue(elt(env, 12)); // identity
    goto v_21877;
v_21878:
    v_21931 = stack[0];
    goto v_21879;
v_21880:
    goto v_21876;
v_21877:
    goto v_21878;
v_21879:
    return cons(v_21932, v_21931);
v_21872:
    v_21931 = nil;
    goto v_21750;
    v_21931 = nil;
v_21750:
    goto v_21738;
v_21740:
    goto v_21896;
v_21892:
    v_21932 = qvalue(elt(env, 4)); // i
    goto v_21893;
v_21894:
    v_21931 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21895;
v_21896:
    goto v_21892;
v_21893:
    goto v_21894;
v_21895:
    if (v_21932 == v_21931) goto v_21890;
    else goto v_21891;
v_21890:
    goto v_21904;
v_21900:
    v_21932 = qvalue(elt(env, 4)); // i
    goto v_21901;
v_21902:
    v_21931 = qvalue(elt(env, 5)); // upb
    goto v_21903;
v_21904:
    goto v_21900;
v_21901:
    goto v_21902;
v_21903:
    v_21931 = (LispObject)lesseq2(v_21932, v_21931);
    v_21931 = v_21931 ? lisp_true : nil;
    env = stack[-2];
    goto v_21889;
v_21891:
    v_21931 = nil;
    goto v_21889;
    v_21931 = nil;
v_21889:
    if (v_21931 == nil) goto v_21887;
    goto v_21915;
v_21911:
    v_21932 = elt(env, 6); // (null!-fn)
    goto v_21912;
v_21913:
    v_21931 = stack[0];
    goto v_21914;
v_21915:
    goto v_21911;
v_21912:
    goto v_21913;
v_21914:
    return cons(v_21932, v_21931);
v_21887:
    v_21931 = qvalue(elt(env, 11)); // expand
    if (v_21931 == nil) goto v_21919;
    v_21931 = nil;
    qvalue(elt(env, 11)) = v_21931; // expand
    goto v_21927;
v_21923:
    v_21932 = qvalue(elt(env, 12)); // identity
    goto v_21924;
v_21925:
    v_21931 = stack[0];
    goto v_21926;
v_21927:
    goto v_21923;
v_21924:
    goto v_21925;
v_21926:
    return cons(v_21932, v_21931);
v_21919:
    v_21931 = nil;
v_21738:
    return onevalue(v_21931);
}



// Code for wedgef

static LispObject CC_wedgef(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21948, v_21949, v_21950;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_21714;
// end of prologue
    v_21948 = stack[-1];
    fn = elt(env, 6); // dim!<deg
    v_21948 = (*qfn1(fn))(fn, v_21948);
    env = stack[-3];
    if (v_21948 == nil) goto v_21719;
    v_21948 = nil;
    goto v_21717;
v_21719:
    goto v_21730;
v_21726:
    v_21948 = stack[-1];
    v_21949 = qcar(v_21948);
    goto v_21727;
v_21728:
    v_21948 = elt(env, 1); // hodge
    goto v_21729;
v_21730:
    goto v_21726;
v_21727:
    goto v_21728;
v_21729:
    if (!consp(v_21949)) goto v_21724;
    v_21949 = qcar(v_21949);
    if (v_21949 == v_21948) goto v_21723;
    else goto v_21724;
v_21723:
    v_21948 = stack[-1];
    v_21948 = qcar(v_21948);
    v_21948 = qcdr(v_21948);
    v_21948 = qcar(v_21948);
    fn = elt(env, 7); // deg!*form
    v_21948 = (*qfn1(fn))(fn, v_21948);
    env = stack[-3];
    stack[-2] = v_21948;
    goto v_21748;
v_21744:
    stack[0] = stack[-2];
    goto v_21745;
v_21746:
    v_21948 = stack[-1];
    v_21948 = qcdr(v_21948);
    fn = elt(env, 8); // deg!*farg
    v_21948 = (*qfn1(fn))(fn, v_21948);
    env = stack[-3];
    goto v_21747;
v_21748:
    goto v_21744;
v_21745:
    goto v_21746;
v_21747:
    if (equal(stack[0], v_21948)) goto v_21742;
    else goto v_21743;
v_21742:
    goto v_21758;
v_21754:
    goto v_21764;
v_21760:
    goto v_21773;
v_21767:
    v_21948 = stack[-1];
    v_21948 = qcar(v_21948);
    v_21948 = qcdr(v_21948);
    v_21950 = qcar(v_21948);
    goto v_21768;
v_21769:
    v_21949 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21770;
v_21771:
    v_21948 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21772;
v_21773:
    goto v_21767;
v_21768:
    goto v_21769;
v_21770:
    goto v_21771;
v_21772:
    v_21948 = list2star(v_21950, v_21949, v_21948);
    env = stack[-3];
    stack[0] = ncons(v_21948);
    env = stack[-3];
    goto v_21761;
v_21762:
    v_21948 = stack[-1];
    v_21948 = qcdr(v_21948);
    v_21948 = qcdr(v_21948);
    if (v_21948 == nil) goto v_21785;
    v_21948 = stack[-1];
    v_21948 = qcdr(v_21948);
    fn = elt(env, 9); // mkuniquewedge1
    v_21948 = (*qfn1(fn))(fn, v_21948);
    env = stack[-3];
    goto v_21783;
v_21785:
    goto v_21802;
v_21796:
    v_21948 = stack[-1];
    v_21948 = qcdr(v_21948);
    v_21950 = qcar(v_21948);
    goto v_21797;
v_21798:
    v_21949 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21799;
v_21800:
    v_21948 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21801;
v_21802:
    goto v_21796;
v_21797:
    goto v_21798;
v_21799:
    goto v_21800;
v_21801:
    v_21948 = list2star(v_21950, v_21949, v_21948);
    env = stack[-3];
    v_21948 = ncons(v_21948);
    env = stack[-3];
    goto v_21783;
    v_21948 = nil;
v_21783:
    fn = elt(env, 10); // hodgepf
    v_21948 = (*qfn1(fn))(fn, v_21948);
    env = stack[-3];
    fn = elt(env, 11); // mkunarywedge
    v_21948 = (*qfn1(fn))(fn, v_21948);
    env = stack[-3];
    goto v_21763;
v_21764:
    goto v_21760;
v_21761:
    goto v_21762;
v_21763:
    fn = elt(env, 12); // wedgepf2
    stack[-1] = (*qfn2(fn))(fn, stack[0], v_21948);
    env = stack[-3];
    goto v_21755;
v_21756:
    goto v_21814;
v_21810:
    stack[0] = stack[-2];
    goto v_21811;
v_21812:
    goto v_21821;
v_21817:
    goto v_21818;
v_21819:
    v_21948 = qvalue(elt(env, 2)); // dimex!*
    fn = elt(env, 13); // negf
    v_21948 = (*qfn1(fn))(fn, v_21948);
    env = stack[-3];
    goto v_21820;
v_21821:
    goto v_21817;
v_21818:
    goto v_21819;
v_21820:
    fn = elt(env, 14); // addf
    v_21948 = (*qfn2(fn))(fn, stack[-2], v_21948);
    env = stack[-3];
    goto v_21813;
v_21814:
    goto v_21810;
v_21811:
    goto v_21812;
v_21813:
    fn = elt(env, 15); // multf
    v_21948 = (*qfn2(fn))(fn, stack[0], v_21948);
    env = stack[-3];
    fn = elt(env, 16); // mksgnsq
    v_21948 = (*qfn1(fn))(fn, v_21948);
    env = stack[-3];
    goto v_21757;
v_21758:
    goto v_21754;
v_21755:
    goto v_21756;
v_21757:
    {
        LispObject v_21954 = stack[-1];
        fn = elt(env, 17); // multpfsq
        return (*qfn2(fn))(fn, v_21954, v_21948);
    }
v_21743:
    v_21948 = stack[-1];
    {
        fn = elt(env, 18); // mkwedge
        return (*qfn1(fn))(fn, v_21948);
    }
    v_21948 = nil;
    goto v_21717;
v_21724:
    goto v_21840;
v_21836:
    v_21948 = stack[-1];
    v_21949 = qcar(v_21948);
    goto v_21837;
v_21838:
    v_21948 = elt(env, 3); // d
    goto v_21839;
v_21840:
    goto v_21836;
v_21837:
    goto v_21838;
v_21839:
    if (!consp(v_21949)) goto v_21834;
    v_21949 = qcar(v_21949);
    if (v_21949 == v_21948) goto v_21833;
    else goto v_21834;
v_21833:
    goto v_21853;
v_21849:
    v_21949 = elt(env, 3); // d
    goto v_21850;
v_21851:
    v_21948 = elt(env, 4); // noxpnd
    goto v_21852;
v_21853:
    goto v_21849;
v_21850:
    goto v_21851;
v_21852:
    v_21948 = Lflagp(nil, v_21949, v_21948);
    env = stack[-3];
    if (v_21948 == nil) goto v_21847;
    v_21948 = lisp_true;
    goto v_21845;
v_21847:
    goto v_21864;
v_21860:
    v_21949 = qvalue(elt(env, 5)); // lftshft!*
    goto v_21861;
v_21862:
    v_21948 = stack[-1];
    v_21948 = qcar(v_21948);
    v_21948 = qcdr(v_21948);
    v_21948 = qcar(v_21948);
    goto v_21863;
v_21864:
    goto v_21860;
v_21861:
    goto v_21862;
v_21863:
    fn = elt(env, 19); // smemqlp
    v_21948 = (*qfn2(fn))(fn, v_21949, v_21948);
    env = stack[-3];
    goto v_21845;
    v_21948 = nil;
v_21845:
    goto v_21832;
v_21834:
    v_21948 = nil;
    goto v_21832;
    v_21948 = nil;
v_21832:
    if (v_21948 == nil) goto v_21830;
    goto v_21878;
v_21874:
    goto v_21886;
v_21882:
    v_21948 = stack[-1];
    v_21948 = qcar(v_21948);
    v_21948 = qcdr(v_21948);
    v_21949 = qcar(v_21948);
    goto v_21883;
v_21884:
    v_21948 = stack[-1];
    v_21948 = qcdr(v_21948);
    goto v_21885;
v_21886:
    goto v_21882;
v_21883:
    goto v_21884;
v_21885:
    v_21948 = cons(v_21949, v_21948);
    env = stack[-3];
    fn = elt(env, 20); // dwedge
    v_21948 = (*qfn1(fn))(fn, v_21948);
    env = stack[-3];
    fn = elt(env, 11); // mkunarywedge
    stack[-2] = (*qfn1(fn))(fn, v_21948);
    env = stack[-3];
    goto v_21875;
v_21876:
    goto v_21898;
v_21894:
    goto v_21904;
v_21900:
    goto v_21913;
v_21907:
    v_21948 = stack[-1];
    v_21948 = qcar(v_21948);
    v_21948 = qcdr(v_21948);
    v_21950 = qcar(v_21948);
    goto v_21908;
v_21909:
    v_21949 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21910;
v_21911:
    v_21948 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21912;
v_21913:
    goto v_21907;
v_21908:
    goto v_21909;
v_21910:
    goto v_21911;
v_21912:
    v_21948 = list2star(v_21950, v_21949, v_21948);
    env = stack[-3];
    stack[0] = ncons(v_21948);
    env = stack[-3];
    goto v_21901;
v_21902:
    v_21948 = stack[-1];
    v_21948 = qcdr(v_21948);
    v_21948 = qcdr(v_21948);
    if (v_21948 == nil) goto v_21924;
    v_21948 = stack[-1];
    v_21948 = qcdr(v_21948);
    fn = elt(env, 20); // dwedge
    v_21948 = (*qfn1(fn))(fn, v_21948);
    env = stack[-3];
    goto v_21922;
v_21924:
    v_21948 = stack[-1];
    v_21948 = qcdr(v_21948);
    v_21948 = qcar(v_21948);
    fn = elt(env, 21); // exdfk
    v_21948 = (*qfn1(fn))(fn, v_21948);
    env = stack[-3];
    goto v_21922;
    v_21948 = nil;
v_21922:
    fn = elt(env, 11); // mkunarywedge
    v_21948 = (*qfn1(fn))(fn, v_21948);
    env = stack[-3];
    goto v_21903;
v_21904:
    goto v_21900;
v_21901:
    goto v_21902;
v_21903:
    fn = elt(env, 12); // wedgepf2
    stack[0] = (*qfn2(fn))(fn, stack[0], v_21948);
    env = stack[-3];
    goto v_21895;
v_21896:
    v_21948 = stack[-1];
    v_21948 = qcar(v_21948);
    v_21948 = qcdr(v_21948);
    v_21948 = qcar(v_21948);
    fn = elt(env, 7); // deg!*form
    v_21948 = (*qfn1(fn))(fn, v_21948);
    env = stack[-3];
    fn = elt(env, 16); // mksgnsq
    v_21948 = (*qfn1(fn))(fn, v_21948);
    env = stack[-3];
    fn = elt(env, 22); // negsq
    v_21948 = (*qfn1(fn))(fn, v_21948);
    env = stack[-3];
    goto v_21897;
v_21898:
    goto v_21894;
v_21895:
    goto v_21896;
v_21897:
    fn = elt(env, 17); // multpfsq
    v_21948 = (*qfn2(fn))(fn, stack[0], v_21948);
    env = stack[-3];
    goto v_21877;
v_21878:
    goto v_21874;
v_21875:
    goto v_21876;
v_21877:
    {
        LispObject v_21955 = stack[-2];
        fn = elt(env, 23); // addpf
        return (*qfn2(fn))(fn, v_21955, v_21948);
    }
v_21830:
    v_21948 = stack[-1];
    {
        fn = elt(env, 18); // mkwedge
        return (*qfn1(fn))(fn, v_21948);
    }
    v_21948 = nil;
v_21717:
    return onevalue(v_21948);
}



// Code for apply_e

static LispObject CC_apply_e(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21734, v_21735;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21734 = v_21714;
// end of prologue
    goto v_21725;
v_21721:
    v_21735 = v_21734;
    goto v_21722;
v_21723:
    v_21734 = nil;
    goto v_21724;
v_21725:
    goto v_21721;
v_21722:
    goto v_21723;
v_21724:
    fn = elt(env, 2); // apply
    v_21735 = (*qfn2(fn))(fn, v_21735, v_21734);
    env = stack[0];
    v_21734 = v_21735;
    v_21735 = integerp(v_21735);
    if (v_21735 == nil) goto v_21719;
    goto v_21717;
v_21719:
    v_21734 = elt(env, 1); // "randpoly expons function must return an integer"
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_21734);
    }
    v_21734 = nil;
v_21717:
    return onevalue(v_21734);
}



// Code for diff_vertex

static LispObject CC_diff_vertex(LispObject env,
                         LispObject v_21714, LispObject v_21715)
{
    env = qenv(env);
    LispObject v_21767, v_21768, v_21769;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21715,v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21714,v_21715);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21715;
    stack[-1] = v_21714;
// end of prologue
    v_21769 = nil;
v_21720:
    v_21767 = stack[-1];
    if (v_21767 == nil) goto v_21723;
    else goto v_21724;
v_21723:
    v_21767 = v_21769;
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_21767);
    }
v_21724:
    goto v_21735;
v_21731:
    v_21767 = stack[-1];
    v_21767 = qcar(v_21767);
    v_21768 = qcar(v_21767);
    goto v_21732;
v_21733:
    v_21767 = stack[0];
    goto v_21734;
v_21735:
    goto v_21731;
v_21732:
    goto v_21733;
v_21734:
    v_21767 = Lassoc(nil, v_21768, v_21767);
    if (v_21767 == nil) goto v_21729;
    goto v_21746;
v_21742:
    v_21767 = stack[-1];
    v_21767 = qcar(v_21767);
    v_21768 = qcar(v_21767);
    goto v_21743;
v_21744:
    v_21767 = qvalue(elt(env, 1)); // !_0edge
    v_21767 = qcar(v_21767);
    goto v_21745;
v_21746:
    goto v_21742;
v_21743:
    goto v_21744;
v_21745:
    if (v_21768 == v_21767) goto v_21729;
    v_21767 = stack[-1];
    v_21767 = qcdr(v_21767);
    stack[-1] = v_21767;
    goto v_21720;
v_21729:
    goto v_21761;
v_21757:
    v_21767 = stack[-1];
    v_21767 = qcar(v_21767);
    goto v_21758;
v_21759:
    v_21768 = v_21769;
    goto v_21760;
v_21761:
    goto v_21757;
v_21758:
    goto v_21759;
v_21760:
    v_21767 = cons(v_21767, v_21768);
    env = stack[-2];
    v_21769 = v_21767;
    v_21767 = stack[-1];
    v_21767 = qcdr(v_21767);
    stack[-1] = v_21767;
    goto v_21720;
    v_21767 = nil;
    return onevalue(v_21767);
}



// Code for no!-side!-effectp

static LispObject CC_noKsideKeffectp(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21770, v_21771;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21714;
// end of prologue
    v_21770 = stack[0];
    if (!consp(v_21770)) goto v_21718;
    else goto v_21719;
v_21718:
    v_21770 = stack[0];
    v_21770 = (is_number(v_21770) ? lisp_true : nil);
    if (v_21770 == nil) goto v_21723;
    else goto v_21722;
v_21723:
    v_21770 = stack[0];
    if (symbolp(v_21770)) goto v_21729;
    v_21770 = nil;
    goto v_21727;
v_21729:
    v_21770 = stack[0];
    v_21770 = Lsymbol_specialp(nil, v_21770);
    env = stack[-1];
    if (v_21770 == nil) goto v_21736;
    else goto v_21735;
v_21736:
    v_21770 = stack[0];
    v_21770 = Lsymbol_globalp(nil, v_21770);
v_21735:
    v_21770 = (v_21770 == nil ? lisp_true : nil);
    goto v_21727;
    v_21770 = nil;
v_21727:
v_21722:
    goto v_21717;
v_21719:
    goto v_21748;
v_21744:
    v_21770 = stack[0];
    v_21771 = qcar(v_21770);
    goto v_21745;
v_21746:
    v_21770 = elt(env, 1); // quote
    goto v_21747;
v_21748:
    goto v_21744;
v_21745:
    goto v_21746;
v_21747:
    if (v_21771 == v_21770) goto v_21742;
    else goto v_21743;
v_21742:
    v_21770 = lisp_true;
    goto v_21717;
v_21743:
    goto v_21760;
v_21756:
    v_21770 = stack[0];
    v_21771 = qcar(v_21770);
    goto v_21757;
v_21758:
    v_21770 = elt(env, 2); // nosideeffects
    goto v_21759;
v_21760:
    goto v_21756;
v_21757:
    goto v_21758;
v_21759:
    v_21770 = Lflagp(nil, v_21771, v_21770);
    env = stack[-1];
    if (v_21770 == nil) goto v_21754;
    v_21770 = stack[0];
    v_21770 = qcdr(v_21770);
    {
        fn = elt(env, 3); // no!-side!-effect!-listp
        return (*qfn1(fn))(fn, v_21770);
    }
v_21754:
    v_21770 = nil;
    goto v_21717;
    v_21770 = nil;
v_21717:
    return onevalue(v_21770);
}



// Code for innprodpex

static LispObject CC_innprodpex(LispObject env,
                         LispObject v_21714, LispObject v_21715)
{
    env = qenv(env);
    LispObject v_21786, v_21787;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21715,v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21714,v_21715);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_21715;
    stack[-2] = v_21714;
// end of prologue
v_21713:
    v_21786 = stack[-1];
    if (v_21786 == nil) goto v_21719;
    else goto v_21720;
v_21719:
    v_21786 = nil;
    goto v_21718;
v_21720:
    goto v_21730;
v_21726:
    v_21787 = stack[-2];
    goto v_21727;
v_21728:
    v_21786 = stack[-1];
    v_21786 = qcar(v_21786);
    v_21786 = qcar(v_21786);
    goto v_21729;
v_21730:
    goto v_21726;
v_21727:
    goto v_21728;
v_21729:
    fn = elt(env, 1); // innprodp2
    v_21786 = (*qfn2(fn))(fn, v_21787, v_21786);
    env = stack[-4];
    v_21787 = v_21786;
    v_21786 = v_21787;
    if (v_21786 == nil) goto v_21739;
    goto v_21748;
v_21742:
    v_21786 = v_21787;
    stack[-3] = qcdr(v_21786);
    goto v_21743;
v_21744:
    v_21786 = v_21787;
    v_21786 = qcar(v_21786);
    if (v_21786 == nil) goto v_21754;
    v_21786 = stack[-1];
    v_21786 = qcar(v_21786);
    v_21786 = qcdr(v_21786);
    fn = elt(env, 2); // negf
    v_21786 = (*qfn1(fn))(fn, v_21786);
    env = stack[-4];
    stack[0] = v_21786;
    goto v_21752;
v_21754:
    v_21786 = stack[-1];
    v_21786 = qcar(v_21786);
    v_21786 = qcdr(v_21786);
    stack[0] = v_21786;
    goto v_21752;
    stack[0] = nil;
v_21752:
    goto v_21745;
v_21746:
    goto v_21771;
v_21767:
    v_21787 = stack[-2];
    goto v_21768;
v_21769:
    v_21786 = stack[-1];
    v_21786 = qcdr(v_21786);
    goto v_21770;
v_21771:
    goto v_21767;
v_21768:
    goto v_21769;
v_21770:
    v_21786 = CC_innprodpex(elt(env, 0), v_21787, v_21786);
    goto v_21747;
v_21748:
    goto v_21742;
v_21743:
    goto v_21744;
v_21745:
    goto v_21746;
v_21747:
    {
        LispObject v_21792 = stack[-3];
        LispObject v_21793 = stack[0];
        return acons(v_21792, v_21793, v_21786);
    }
v_21739:
    goto v_21782;
v_21778:
    v_21787 = stack[-2];
    goto v_21779;
v_21780:
    v_21786 = stack[-1];
    v_21786 = qcdr(v_21786);
    goto v_21781;
v_21782:
    goto v_21778;
v_21779:
    goto v_21780;
v_21781:
    stack[-2] = v_21787;
    stack[-1] = v_21786;
    goto v_21713;
    v_21786 = nil;
    goto v_21718;
    v_21786 = nil;
v_21718:
    return onevalue(v_21786);
}



// Code for getavalue

static LispObject CC_getavalue(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21730, v_21731;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21730 = v_21714;
// end of prologue
    if (!symbolp(v_21730)) v_21730 = nil;
    else { v_21730 = qfastgets(v_21730);
           if (v_21730 != nil) { v_21730 = elt(v_21730, 4); // avalue
#ifdef RECORD_GET
             if (v_21730 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_21730 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_21730 == SPID_NOPROP) v_21730 = nil; }}
#endif
    v_21731 = v_21730;
    v_21730 = v_21731;
    if (v_21730 == nil) goto v_21722;
    v_21730 = v_21731;
    v_21730 = qcdr(v_21730);
    v_21730 = qcar(v_21730);
    goto v_21720;
v_21722:
    v_21730 = nil;
    goto v_21720;
    v_21730 = nil;
v_21720:
    return onevalue(v_21730);
}



// Code for ratlessp

static LispObject CC_ratlessp(LispObject env,
                         LispObject v_21714, LispObject v_21715)
{
    env = qenv(env);
    LispObject v_21733, v_21734;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21715,v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21714,v_21715);
    }
// copy arguments values to proper place
    v_21733 = v_21715;
    v_21734 = v_21714;
// end of prologue
    goto v_21722;
v_21718:
    goto v_21728;
v_21724:
    goto v_21725;
v_21726:
    goto v_21727;
v_21728:
    goto v_21724;
v_21725:
    goto v_21726;
v_21727:
    fn = elt(env, 1); // ratdif
    v_21733 = (*qfn2(fn))(fn, v_21734, v_21733);
    v_21734 = qcar(v_21733);
    goto v_21719;
v_21720:
    v_21733 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21721;
v_21722:
    goto v_21718;
v_21719:
    goto v_21720;
v_21721:
        return Llessp(nil, v_21734, v_21733);
}



// Code for get!-term!-n

static LispObject CC_getKtermKn(LispObject env,
                         LispObject v_21714, LispObject v_21715)
{
    env = qenv(env);
    LispObject v_21763, v_21764, v_21765, v_21766;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21715,v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21714,v_21715);
    }
// copy arguments values to proper place
    v_21765 = v_21715;
    v_21766 = v_21714;
// end of prologue
v_21719:
    v_21763 = v_21765;
    if (v_21763 == nil) goto v_21726;
    else goto v_21727;
v_21726:
    v_21763 = lisp_true;
    goto v_21725;
v_21727:
    goto v_21736;
v_21732:
    v_21764 = v_21766;
    goto v_21733;
v_21734:
    v_21763 = v_21765;
    v_21763 = qcar(v_21763);
    v_21763 = qcar(v_21763);
    goto v_21735;
v_21736:
    goto v_21732;
v_21733:
    goto v_21734;
v_21735:
    v_21763 = ((intptr_t)v_21764 > (intptr_t)v_21763) ? lisp_true : nil;
    goto v_21725;
    v_21763 = nil;
v_21725:
    if (v_21763 == nil) goto v_21723;
    v_21763 = elt(env, 1); // no
    goto v_21718;
v_21723:
    goto v_21749;
v_21745:
    v_21763 = v_21765;
    v_21763 = qcar(v_21763);
    v_21764 = qcar(v_21763);
    goto v_21746;
v_21747:
    v_21763 = v_21766;
    goto v_21748;
v_21749:
    goto v_21745;
v_21746:
    goto v_21747;
v_21748:
    if (equal(v_21764, v_21763)) goto v_21743;
    else goto v_21744;
v_21743:
    v_21763 = v_21765;
    v_21763 = qcar(v_21763);
    v_21763 = qcdr(v_21763);
    v_21763 = ncons(v_21763);
    return ncons(v_21763);
v_21744:
    v_21763 = v_21765;
    v_21763 = qcdr(v_21763);
    v_21765 = v_21763;
    goto v_21719;
    v_21763 = nil;
v_21718:
    return onevalue(v_21763);
}



// Code for settcollectnonmultiprolongations

static LispObject CC_settcollectnonmultiprolongations(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21853, v_21854, v_21855;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_21714;
// end of prologue
    v_21853 = qvalue(elt(env, 1)); // fluidbibasissett
    v_21853 = qcar(v_21853);
    if (v_21853 == nil) goto v_21719;
    v_21853 = qvalue(elt(env, 1)); // fluidbibasissett
    v_21853 = qcar(v_21853);
    stack[-4] = v_21853;
    goto v_21737;
v_21733:
    v_21854 = stack[-4];
    goto v_21734;
v_21735:
    v_21853 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21736;
v_21737:
    goto v_21733;
v_21734:
    goto v_21735;
v_21736:
    v_21853 = *(LispObject *)((char *)v_21854 + (CELL-TAG_VECTOR) + (((intptr_t)v_21853-TAG_FIXNUM)/(16/CELL)));
    v_21853 = qcar(v_21853);
    fn = elt(env, 4); // monomgetfirstmultivar
    v_21853 = (*qfn1(fn))(fn, v_21853);
    env = stack[-5];
    v_21853 = (LispObject)((intptr_t)(v_21853) - 0x10);
    stack[-1] = v_21853;
    v_21853 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_21853;
v_21746:
    goto v_21758;
v_21754:
    v_21854 = stack[-1];
    goto v_21755;
v_21756:
    v_21853 = stack[0];
    goto v_21757;
v_21758:
    goto v_21754;
v_21755:
    goto v_21756;
v_21757:
    v_21853 = difference2(v_21854, v_21853);
    env = stack[-5];
    v_21853 = Lminusp(nil, v_21853);
    env = stack[-5];
    if (v_21853 == nil) goto v_21751;
    goto v_21745;
v_21751:
    goto v_21771;
v_21767:
    v_21854 = stack[-4];
    goto v_21768;
v_21769:
    v_21853 = stack[0];
    goto v_21770;
v_21771:
    goto v_21767;
v_21768:
    goto v_21769;
v_21770:
    fn = elt(env, 5); // tripleisprolongedby
    v_21853 = (*qfn2(fn))(fn, v_21854, v_21853);
    env = stack[-5];
    if (v_21853 == nil) goto v_21764;
    else goto v_21765;
v_21764:
    goto v_21779;
v_21775:
    goto v_21784;
v_21780:
    v_21854 = stack[-4];
    goto v_21781;
v_21782:
    v_21853 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21783;
v_21784:
    goto v_21780;
v_21781:
    goto v_21782;
v_21783:
    v_21855 = *(LispObject *)((char *)v_21854 + (CELL-TAG_VECTOR) + (((intptr_t)v_21853-TAG_FIXNUM)/(16/CELL)));
    goto v_21776;
v_21777:
    goto v_21792;
v_21788:
    v_21854 = qvalue(elt(env, 3)); // fluidbibasissinglevariablemonomialss
    goto v_21789;
v_21790:
    v_21853 = stack[0];
    goto v_21791;
v_21792:
    goto v_21788;
v_21789:
    goto v_21790;
v_21791:
    v_21853 = *(LispObject *)((char *)v_21854 + (CELL-TAG_VECTOR) + (((intptr_t)v_21853-TAG_FIXNUM)/(16/CELL)));
    goto v_21778;
v_21779:
    goto v_21775;
v_21776:
    goto v_21777;
v_21778:
    fn = elt(env, 6); // polynommultiplybymonom
    v_21853 = (*qfn2(fn))(fn, v_21855, v_21853);
    env = stack[-5];
    stack[-2] = v_21853;
    goto v_21801;
v_21797:
    v_21854 = stack[-4];
    goto v_21798;
v_21799:
    v_21853 = stack[0];
    goto v_21800;
v_21801:
    goto v_21797;
v_21798:
    goto v_21799;
v_21800:
    fn = elt(env, 7); // triplesetprolongedby
    v_21853 = (*qfn2(fn))(fn, v_21854, v_21853);
    env = stack[-5];
    v_21853 = stack[-2];
    v_21853 = qcar(v_21853);
    if (v_21853 == nil) goto v_21807;
    goto v_21815;
v_21811:
    v_21855 = stack[-2];
    goto v_21812;
v_21813:
    goto v_21821;
v_21817:
    v_21854 = stack[-4];
    goto v_21818;
v_21819:
    v_21853 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_21820;
v_21821:
    goto v_21817;
v_21818:
    goto v_21819;
v_21820:
    v_21853 = *(LispObject *)((char *)v_21854 + (CELL-TAG_VECTOR) + (((intptr_t)v_21853-TAG_FIXNUM)/(16/CELL)));
    goto v_21814;
v_21815:
    goto v_21811;
v_21812:
    goto v_21813;
v_21814:
    fn = elt(env, 8); // createtriplewithancestor
    v_21853 = (*qfn2(fn))(fn, v_21855, v_21853);
    env = stack[-5];
    stack[-2] = v_21853;
    goto v_21830;
v_21826:
    v_21855 = stack[-2];
    goto v_21827;
v_21828:
    goto v_21836;
v_21832:
    v_21854 = stack[-4];
    goto v_21833;
v_21834:
    v_21853 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_21835;
v_21836:
    goto v_21832;
v_21833:
    goto v_21834;
v_21835:
    v_21853 = *(LispObject *)((char *)v_21854 + (CELL-TAG_VECTOR) + (((intptr_t)v_21853-TAG_FIXNUM)/(16/CELL)));
    goto v_21829;
v_21830:
    goto v_21826;
v_21827:
    goto v_21828;
v_21829:
    fn = elt(env, 9); // triplesetprolongset
    v_21853 = (*qfn2(fn))(fn, v_21855, v_21853);
    env = stack[-5];
    goto v_21845;
v_21841:
    v_21854 = stack[-3];
    goto v_21842;
v_21843:
    v_21853 = stack[-2];
    goto v_21844;
v_21845:
    goto v_21841;
v_21842:
    goto v_21843;
v_21844:
    fn = elt(env, 10); // sortedtriplelistinsert
    v_21853 = (*qfn2(fn))(fn, v_21854, v_21853);
    env = stack[-5];
    goto v_21805;
v_21807:
v_21805:
    goto v_21763;
v_21765:
v_21763:
    v_21853 = stack[0];
    v_21853 = add1(v_21853);
    env = stack[-5];
    stack[0] = v_21853;
    goto v_21746;
v_21745:
    v_21853 = nil;
    goto v_21717;
v_21719:
    v_21853 = nil;
v_21717:
    return onevalue(v_21853);
}



// Code for ofsf_qesubqat

static LispObject CC_ofsf_qesubqat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21912, v_21913, v_21914;
    LispObject fn;
    LispObject v_21716, v_21715, v_21714;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_qesubqat");
    va_start(aa, nargs);
    v_21714 = va_arg(aa, LispObject);
    v_21715 = va_arg(aa, LispObject);
    v_21716 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21716,v_21715,v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21714,v_21715,v_21716);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_21716;
    stack[-1] = v_21715;
    stack[-2] = v_21714;
// end of prologue
    goto v_21732;
v_21728:
    stack[-3] = stack[-1];
    goto v_21729;
v_21730:
    v_21912 = stack[-2];
    fn = elt(env, 7); // ofsf_varlat
    v_21912 = (*qfn1(fn))(fn, v_21912);
    env = stack[-4];
    goto v_21731;
v_21732:
    goto v_21728;
v_21729:
    goto v_21730;
v_21731:
    v_21912 = Lmemq(nil, stack[-3], v_21912);
    if (v_21912 == nil) goto v_21726;
    else goto v_21727;
v_21726:
    v_21912 = stack[-2];
    goto v_21722;
v_21727:
    v_21912 = qvalue(elt(env, 2)); // !*rlqesubf
    if (v_21912 == nil) goto v_21741;
    goto v_21748;
v_21744:
    v_21912 = stack[-2];
    v_21912 = qcdr(v_21912);
    stack[-3] = qcar(v_21912);
    goto v_21745;
v_21746:
    goto v_21758;
v_21754:
    goto v_21755;
v_21756:
    v_21912 = stack[0];
    fn = elt(env, 8); // prepsq
    v_21912 = (*qfn1(fn))(fn, v_21912);
    env = stack[-4];
    goto v_21757;
v_21758:
    goto v_21754;
v_21755:
    goto v_21756;
v_21757:
    v_21912 = cons(stack[-1], v_21912);
    env = stack[-4];
    v_21912 = ncons(v_21912);
    env = stack[-4];
    goto v_21747;
v_21748:
    goto v_21744;
v_21745:
    goto v_21746;
v_21747:
    fn = elt(env, 9); // subf
    v_21912 = (*qfn2(fn))(fn, stack[-3], v_21912);
    env = stack[-4];
    goto v_21739;
v_21741:
    goto v_21771;
v_21765:
    v_21912 = stack[-2];
    v_21912 = qcdr(v_21912);
    v_21914 = qcar(v_21912);
    goto v_21766;
v_21767:
    v_21913 = stack[-1];
    goto v_21768;
v_21769:
    v_21912 = stack[0];
    goto v_21770;
v_21771:
    goto v_21765;
v_21766:
    goto v_21767;
v_21768:
    goto v_21769;
v_21770:
    fn = elt(env, 10); // ofsf_subf
    v_21912 = (*qfnn(fn))(fn, 3, v_21914, v_21913, v_21912);
    env = stack[-4];
    goto v_21739;
    v_21912 = nil;
v_21739:
    stack[-1] = v_21912;
    v_21912 = stack[-2];
    v_21912 = qcar(v_21912);
    stack[0] = v_21912;
    v_21912 = qvalue(elt(env, 3)); // !*rlqelocal
    if (v_21912 == nil) goto v_21782;
    goto v_21789;
v_21785:
    v_21913 = stack[0];
    goto v_21786;
v_21787:
    v_21912 = stack[-1];
    goto v_21788;
v_21789:
    goto v_21785;
v_21786:
    goto v_21787;
v_21788:
    {
        fn = elt(env, 11); // ofsf_qesubqat!-local
        return (*qfn2(fn))(fn, v_21913, v_21912);
    }
v_21782:
    goto v_21804;
v_21800:
    v_21913 = stack[0];
    goto v_21801;
v_21802:
    v_21912 = elt(env, 4); // equal
    goto v_21803;
v_21804:
    goto v_21800;
v_21801:
    goto v_21802;
v_21803:
    if (v_21913 == v_21912) goto v_21798;
    else goto v_21799;
v_21798:
    v_21912 = lisp_true;
    goto v_21797;
v_21799:
    goto v_21818;
v_21814:
    v_21913 = stack[0];
    goto v_21815;
v_21816:
    v_21912 = elt(env, 5); // neq
    goto v_21817;
v_21818:
    goto v_21814;
v_21815:
    goto v_21816;
v_21817:
    if (v_21913 == v_21912) goto v_21812;
    else goto v_21813;
v_21812:
    v_21912 = lisp_true;
    goto v_21811;
v_21813:
    goto v_21829;
v_21825:
    goto v_21837;
v_21831:
    v_21914 = elt(env, 6); // geq
    goto v_21832;
v_21833:
    v_21912 = stack[-1];
    v_21913 = qcdr(v_21912);
    goto v_21834;
v_21835:
    v_21912 = nil;
    goto v_21836;
v_21837:
    goto v_21831;
v_21832:
    goto v_21833;
v_21834:
    goto v_21835;
v_21836:
    v_21913 = list3(v_21914, v_21913, v_21912);
    env = stack[-4];
    goto v_21826;
v_21827:
    v_21912 = nil;
    goto v_21828;
v_21829:
    goto v_21825;
v_21826:
    goto v_21827;
v_21828:
    fn = elt(env, 12); // ofsf_surep
    v_21912 = (*qfn2(fn))(fn, v_21913, v_21912);
    env = stack[-4];
    goto v_21811;
    v_21912 = nil;
v_21811:
    goto v_21797;
    v_21912 = nil;
v_21797:
    if (v_21912 == nil) goto v_21795;
    goto v_21850;
v_21844:
    v_21914 = stack[0];
    goto v_21845;
v_21846:
    v_21912 = stack[-1];
    v_21913 = qcar(v_21912);
    goto v_21847;
v_21848:
    v_21912 = nil;
    goto v_21849;
v_21850:
    goto v_21844;
v_21845:
    goto v_21846;
v_21847:
    goto v_21848;
v_21849:
    return list3(v_21914, v_21913, v_21912);
v_21795:
    v_21912 = stack[-1];
    v_21912 = qcdr(v_21912);
    fn = elt(env, 13); // sfto_pdecf
    v_21912 = (*qfn1(fn))(fn, v_21912);
    env = stack[-4];
    v_21912 = qcar(v_21912);
    stack[-2] = v_21912;
    goto v_21868;
v_21864:
    goto v_21876;
v_21870:
    v_21914 = elt(env, 6); // geq
    goto v_21871;
v_21872:
    v_21913 = stack[-2];
    goto v_21873;
v_21874:
    v_21912 = nil;
    goto v_21875;
v_21876:
    goto v_21870;
v_21871:
    goto v_21872;
v_21873:
    goto v_21874;
v_21875:
    v_21913 = list3(v_21914, v_21913, v_21912);
    env = stack[-4];
    goto v_21865;
v_21866:
    v_21912 = nil;
    goto v_21867;
v_21868:
    goto v_21864;
v_21865:
    goto v_21866;
v_21867:
    fn = elt(env, 12); // ofsf_surep
    v_21912 = (*qfn2(fn))(fn, v_21913, v_21912);
    env = stack[-4];
    if (v_21912 == nil) goto v_21862;
    goto v_21888;
v_21882:
    v_21914 = stack[0];
    goto v_21883;
v_21884:
    v_21912 = stack[-1];
    v_21913 = qcar(v_21912);
    goto v_21885;
v_21886:
    v_21912 = nil;
    goto v_21887;
v_21888:
    goto v_21882;
v_21883:
    goto v_21884;
v_21885:
    goto v_21886;
v_21887:
    return list3(v_21914, v_21913, v_21912);
v_21862:
    goto v_21900;
v_21894:
    goto v_21895;
v_21896:
    goto v_21907;
v_21903:
    v_21912 = stack[-1];
    v_21913 = qcar(v_21912);
    goto v_21904;
v_21905:
    v_21912 = stack[-2];
    goto v_21906;
v_21907:
    goto v_21903;
v_21904:
    goto v_21905;
v_21906:
    fn = elt(env, 14); // multf
    v_21913 = (*qfn2(fn))(fn, v_21913, v_21912);
    goto v_21897;
v_21898:
    v_21912 = nil;
    goto v_21899;
v_21900:
    goto v_21894;
v_21895:
    goto v_21896;
v_21897:
    goto v_21898;
v_21899:
    {
        LispObject v_21919 = stack[0];
        return list3(v_21919, v_21913, v_21912);
    }
v_21722:
    return onevalue(v_21912);
}



// Code for simpexpt1

static LispObject CC_simpexpt1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_22265, v_22266, v_22267;
    LispObject fn;
    LispObject v_21716, v_21715, v_21714;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "simpexpt1");
    va_start(aa, nargs);
    v_21714 = va_arg(aa, LispObject);
    v_21715 = va_arg(aa, LispObject);
    v_21716 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21716,v_21715,v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21714,v_21715,v_21716);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_21716;
    stack[-5] = v_21715;
    stack[-6] = v_21714;
// end of prologue
// Binding !*allfac
// FLUIDBIND: reloadenv=8 litvec-offset=1 saveloc=7
{   bind_fluid_stack bind_fluid_var(-8, 1, -7);
    qvalue(elt(env, 1)) = nil; // !*allfac
// Binding !*div
// FLUIDBIND: reloadenv=8 litvec-offset=2 saveloc=3
{   bind_fluid_stack bind_fluid_var(-8, 2, -3);
    qvalue(elt(env, 2)) = nil; // !*div
    v_22265 = stack[-6];
    v_22265 = Lonep(nil, v_22265);
    env = stack[-8];
    if (v_22265 == nil) goto v_21729;
    goto v_21737;
v_21733:
    v_22266 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21734;
v_21735:
    v_22265 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21736;
v_21737:
    goto v_21733;
v_21734:
    goto v_21735;
v_21736:
    v_22265 = cons(v_22266, v_22265);
    goto v_21724;
v_21729:
    v_22265 = lisp_true;
    qvalue(elt(env, 1)) = v_22265; // !*allfac
    v_22265 = stack[-5];
    v_22265 = qcar(v_22265);
    stack[-2] = v_22265;
    goto v_21755;
v_21751:
    v_22266 = stack[-2];
    goto v_21752;
v_21753:
    v_22265 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21754;
v_21755:
    goto v_21751;
v_21752:
    goto v_21753;
v_21754:
    if (v_22266 == v_22265) goto v_21749;
    else goto v_21750;
v_21749:
    goto v_21762;
v_21758:
    v_22265 = stack[-5];
    v_22266 = qcdr(v_22265);
    goto v_21759;
v_21760:
    v_22265 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21761;
v_21762:
    goto v_21758;
v_21759:
    goto v_21760;
v_21761:
    v_22265 = (v_22266 == v_22265 ? lisp_true : nil);
    goto v_21748;
v_21750:
    v_22265 = nil;
    goto v_21748;
    v_22265 = nil;
v_21748:
    if (v_22265 == nil) goto v_21746;
    v_22265 = stack[-6];
    fn = elt(env, 11); // simp
    v_22265 = (*qfn1(fn))(fn, v_22265);
    goto v_21724;
v_21746:
    goto v_21784;
v_21780:
    v_22266 = stack[-6];
    goto v_21781;
v_21782:
    v_22265 = elt(env, 4); // e
    goto v_21783;
v_21784:
    goto v_21780;
v_21781:
    goto v_21782;
v_21783:
    if (v_22266 == v_22265) goto v_21778;
    else goto v_21779;
v_21778:
    v_22265 = stack[-5];
    v_22265 = qcdr(v_22265);
    if (!consp(v_22265)) goto v_21793;
    else goto v_21794;
v_21793:
    v_22265 = lisp_true;
    goto v_21792;
v_21794:
    v_22265 = stack[-5];
    v_22265 = qcdr(v_22265);
    v_22265 = qcar(v_22265);
    v_22265 = (consp(v_22265) ? nil : lisp_true);
    goto v_21792;
    v_22265 = nil;
v_21792:
    if (v_22265 == nil) goto v_21790;
    v_22265 = stack[-2];
    if (!consp(v_22265)) goto v_21810;
    else goto v_21811;
v_21810:
    v_22265 = lisp_true;
    goto v_21809;
v_21811:
    v_22265 = stack[-2];
    v_22265 = qcar(v_22265);
    v_22265 = (consp(v_22265) ? nil : lisp_true);
    goto v_21809;
    v_22265 = nil;
v_21809:
    if (v_22265 == nil) goto v_21806;
    else goto v_21807;
v_21806:
    goto v_21827;
v_21823:
    v_22265 = stack[-2];
    v_22265 = qcar(v_22265);
    v_22265 = qcar(v_22265);
    v_22266 = qcdr(v_22265);
    goto v_21824;
v_21825:
    v_22265 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21826;
v_21827:
    goto v_21823;
v_21824:
    goto v_21825;
v_21826:
    if (v_22266 == v_22265) goto v_21821;
    else goto v_21822;
v_21821:
    v_22265 = stack[-2];
    v_22265 = qcdr(v_22265);
    if (v_22265 == nil) goto v_21835;
    else goto v_21836;
v_21835:
    goto v_21844;
v_21840:
    v_22265 = stack[-2];
    v_22265 = qcar(v_22265);
    v_22265 = qcar(v_22265);
    v_22266 = qcar(v_22265);
    goto v_21841;
v_21842:
    v_22265 = elt(env, 5); // log
    goto v_21843;
v_21844:
    goto v_21840;
v_21841:
    goto v_21842;
v_21843:
    v_22265 = Leqcar(nil, v_22266, v_22265);
    env = stack[-8];
    goto v_21834;
v_21836:
    v_22265 = nil;
    goto v_21834;
    v_22265 = nil;
v_21834:
    goto v_21820;
v_21822:
    v_22265 = nil;
    goto v_21820;
    v_22265 = nil;
v_21820:
    goto v_21805;
v_21807:
    v_22265 = nil;
    goto v_21805;
    v_22265 = nil;
v_21805:
    goto v_21788;
v_21790:
    v_22265 = nil;
    goto v_21788;
    v_22265 = nil;
v_21788:
    goto v_21777;
v_21779:
    v_22265 = nil;
    goto v_21777;
    v_22265 = nil;
v_21777:
    if (v_22265 == nil) goto v_21775;
    goto v_21872;
v_21866:
    v_22265 = stack[-2];
    v_22265 = qcar(v_22265);
    v_22265 = qcar(v_22265);
    v_22265 = qcar(v_22265);
    v_22265 = qcdr(v_22265);
    v_22265 = qcar(v_22265);
    fn = elt(env, 12); // simp!*
    v_22265 = (*qfn1(fn))(fn, v_22265);
    env = stack[-8];
    fn = elt(env, 13); // prepsq!*
    stack[0] = (*qfn1(fn))(fn, v_22265);
    env = stack[-8];
    goto v_21867;
v_21868:
    goto v_21886;
v_21882:
    v_22265 = stack[-2];
    v_22265 = qcar(v_22265);
    v_22266 = qcdr(v_22265);
    goto v_21883;
v_21884:
    v_22265 = stack[-5];
    v_22265 = qcdr(v_22265);
    goto v_21885;
v_21886:
    goto v_21882;
v_21883:
    goto v_21884;
v_21885:
    v_22266 = cons(v_22266, v_22265);
    env = stack[-8];
    goto v_21869;
v_21870:
    v_22265 = nil;
    goto v_21871;
v_21872:
    goto v_21866;
v_21867:
    goto v_21868;
v_21869:
    goto v_21870;
v_21871:
    v_22265 = CC_simpexpt1(elt(env, 0), 3, stack[0], v_22266, v_22265);
    goto v_21724;
v_21775:
    v_22265 = stack[-2];
    if (!consp(v_22265)) goto v_21903;
    else goto v_21904;
v_21903:
    v_22265 = lisp_true;
    goto v_21902;
v_21904:
    v_22265 = stack[-2];
    v_22265 = qcar(v_22265);
    v_22265 = (consp(v_22265) ? nil : lisp_true);
    goto v_21902;
    v_22265 = nil;
v_21902:
    if (v_22265 == nil) goto v_21899;
    else goto v_21900;
v_21899:
    v_22265 = lisp_true;
    goto v_21898;
v_21900:
    v_22265 = stack[-5];
    v_22265 = qcdr(v_22265);
    if (!consp(v_22265)) goto v_21917;
    else goto v_21918;
v_21917:
    v_22265 = lisp_true;
    goto v_21916;
v_21918:
    v_22265 = stack[-5];
    v_22265 = qcdr(v_22265);
    v_22265 = qcar(v_22265);
    v_22265 = (consp(v_22265) ? nil : lisp_true);
    goto v_21916;
    v_22265 = nil;
v_21916:
    v_22265 = (v_22265 == nil ? lisp_true : nil);
    goto v_21898;
    v_22265 = nil;
v_21898:
    if (v_22265 == nil) goto v_21896;
    goto v_21936;
v_21930:
    v_22267 = stack[-6];
    goto v_21931;
v_21932:
    v_22266 = stack[-5];
    goto v_21933;
v_21934:
    v_22265 = stack[-4];
    goto v_21935;
v_21936:
    goto v_21930;
v_21931:
    goto v_21932;
v_21933:
    goto v_21934;
v_21935:
    fn = elt(env, 14); // simpexpt11
    v_22265 = (*qfnn(fn))(fn, 3, v_22267, v_22266, v_22265);
    goto v_21724;
v_21896:
    v_22265 = stack[-6];
    fn = elt(env, 11); // simp
    v_22265 = (*qfn1(fn))(fn, v_22265);
    env = stack[-8];
    stack[-1] = v_22265;
    v_22265 = stack[-2];
    if (v_22265 == nil) goto v_21944;
    else goto v_21945;
v_21944:
    v_22265 = stack[-1];
    v_22265 = qcar(v_22265);
    if (v_22265 == nil) goto v_21949;
    else goto v_21950;
v_21949:
    goto v_21960;
v_21954:
    v_22267 = elt(env, 6); // alg
    goto v_21955;
v_21956:
    v_22266 = (LispObject)224+TAG_FIXNUM; // 14
    goto v_21957;
v_21958:
    v_22265 = elt(env, 7); // "0**0 formed"
    goto v_21959;
v_21960:
    goto v_21954;
v_21955:
    goto v_21956;
v_21957:
    goto v_21958;
v_21959:
    fn = elt(env, 15); // rerror
    v_22265 = (*qfnn(fn))(fn, 3, v_22267, v_22266, v_22265);
    goto v_21948;
v_21950:
    goto v_21971;
v_21967:
    v_22266 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21968;
v_21969:
    v_22265 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21970;
v_21971:
    goto v_21967;
v_21968:
    goto v_21969;
v_21970:
    v_22265 = cons(v_22266, v_22265);
    goto v_21948;
    v_22265 = nil;
v_21948:
    goto v_21724;
v_21945:
    v_22265 = stack[-1];
    v_22265 = qcar(v_22265);
    if (v_22265 == nil) goto v_21976;
    else goto v_21977;
v_21976:
    v_22265 = stack[-2];
    if (!consp(v_22265)) goto v_21990;
    else goto v_21991;
v_21990:
    v_22265 = lisp_true;
    goto v_21989;
v_21991:
    v_22265 = stack[-2];
    v_22265 = qcar(v_22265);
    v_22265 = (consp(v_22265) ? nil : lisp_true);
    goto v_21989;
    v_22265 = nil;
v_21989:
    if (v_22265 == nil) goto v_21987;
    v_22265 = stack[-2];
    fn = elt(env, 16); // minusf
    v_22265 = (*qfn1(fn))(fn, v_22265);
    env = stack[-8];
    goto v_21985;
v_21987:
    v_22265 = nil;
    goto v_21985;
    v_22265 = nil;
v_21985:
    if (v_22265 == nil) goto v_21983;
    goto v_22011;
v_22005:
    v_22267 = elt(env, 6); // alg
    goto v_22006;
v_22007:
    v_22266 = (LispObject)240+TAG_FIXNUM; // 15
    goto v_22008;
v_22009:
    v_22265 = elt(env, 8); // "Zero divisor"
    goto v_22010;
v_22011:
    goto v_22005;
v_22006:
    goto v_22007;
v_22008:
    goto v_22009;
v_22010:
    fn = elt(env, 15); // rerror
    v_22265 = (*qfnn(fn))(fn, 3, v_22267, v_22266, v_22265);
    goto v_21981;
v_21983:
    goto v_22022;
v_22018:
    v_22266 = nil;
    goto v_22019;
v_22020:
    v_22265 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22021;
v_22022:
    goto v_22018;
v_22019:
    goto v_22020;
v_22021:
    v_22265 = cons(v_22266, v_22265);
    goto v_21981;
    v_22265 = nil;
v_21981:
    goto v_21975;
v_21977:
    v_22265 = stack[-2];
    if (!consp(v_22265)) goto v_22029;
    else goto v_22030;
v_22029:
    goto v_22040;
v_22036:
    v_22265 = stack[-5];
    v_22266 = qcdr(v_22265);
    goto v_22037;
v_22038:
    v_22265 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22039;
v_22040:
    goto v_22036;
v_22037:
    goto v_22038;
v_22039:
    if (v_22266 == v_22265) goto v_22034;
    else goto v_22035;
v_22034:
    v_22265 = stack[-1];
    v_22265 = qcar(v_22265);
    if (!consp(v_22265)) goto v_22050;
    else goto v_22051;
v_22050:
    v_22265 = lisp_true;
    goto v_22049;
v_22051:
    v_22265 = stack[-1];
    v_22265 = qcar(v_22265);
    v_22265 = qcar(v_22265);
    v_22265 = (consp(v_22265) ? nil : lisp_true);
    goto v_22049;
    v_22265 = nil;
v_22049:
    if (v_22265 == nil) goto v_22047;
    goto v_22065;
v_22061:
    v_22265 = stack[-1];
    v_22266 = qcdr(v_22265);
    goto v_22062;
v_22063:
    v_22265 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22064;
v_22065:
    goto v_22061;
v_22062:
    goto v_22063;
v_22064:
    v_22265 = (v_22266 == v_22265 ? lisp_true : nil);
    goto v_22045;
v_22047:
    v_22265 = nil;
    goto v_22045;
    v_22265 = nil;
v_22045:
    goto v_22033;
v_22035:
    v_22265 = nil;
    goto v_22033;
    v_22265 = nil;
v_22033:
    goto v_22028;
v_22030:
    v_22265 = nil;
    goto v_22028;
    v_22265 = nil;
v_22028:
    if (v_22265 == nil) goto v_22026;
    v_22265 = stack[-1];
    v_22265 = qcar(v_22265);
    if (!consp(v_22265)) goto v_22085;
    else goto v_22086;
v_22085:
    goto v_22094;
v_22090:
    v_22266 = stack[-2];
    goto v_22091;
v_22092:
    v_22265 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22093;
v_22094:
    goto v_22090;
v_22091:
    goto v_22092;
v_22093:
    v_22265 = (LispObject)greaterp2(v_22266, v_22265);
    v_22265 = v_22265 ? lisp_true : nil;
    env = stack[-8];
    goto v_22084;
v_22086:
    v_22265 = nil;
    goto v_22084;
    v_22265 = nil;
v_22084:
    if (v_22265 == nil) goto v_22082;
    goto v_22106;
v_22102:
    v_22265 = stack[-1];
    v_22266 = qcar(v_22265);
    goto v_22103;
v_22104:
    v_22265 = stack[-2];
    goto v_22105;
v_22106:
    goto v_22102;
v_22103:
    goto v_22104;
v_22105:
    v_22265 = Lexpt(nil, v_22266, v_22265);
    env = stack[-8];
    fn = elt(env, 17); // !*d2q
    v_22265 = (*qfn1(fn))(fn, v_22265);
    goto v_22080;
v_22082:
    goto v_22117;
v_22113:
    goto v_22123;
v_22119:
    v_22265 = stack[-1];
    v_22266 = qcar(v_22265);
    goto v_22120;
v_22121:
    v_22265 = stack[-2];
    goto v_22122;
v_22123:
    goto v_22119;
v_22120:
    goto v_22121;
v_22122:
    fn = elt(env, 18); // !:expt
    v_22266 = (*qfn2(fn))(fn, v_22266, v_22265);
    env = stack[-8];
    goto v_22114;
v_22115:
    v_22265 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22116;
v_22117:
    goto v_22113;
v_22114:
    goto v_22115;
v_22116:
    v_22265 = cons(v_22266, v_22265);
    env = stack[-8];
    stack[-1] = v_22265;
    v_22265 = qvalue(elt(env, 9)); // !*mcd
    if (v_22265 == nil) goto v_22131;
    v_22265 = stack[-1];
    fn = elt(env, 19); // resimp
    v_22265 = (*qfn1(fn))(fn, v_22265);
    goto v_22129;
v_22131:
    v_22265 = stack[-1];
    goto v_22129;
    v_22265 = nil;
v_22129:
    goto v_22080;
    v_22265 = nil;
v_22080:
    goto v_21975;
v_22026:
    goto v_22145;
v_22141:
    stack[0] = elt(env, 10); // expt
    goto v_22142;
v_22143:
    goto v_22152;
v_22148:
    v_22266 = stack[-1];
    goto v_22149;
v_22150:
    v_22265 = stack[-5];
    goto v_22151;
v_22152:
    goto v_22148;
v_22149:
    goto v_22150;
v_22151:
    v_22265 = list2(v_22266, v_22265);
    env = stack[-8];
    goto v_22144;
v_22145:
    goto v_22141;
v_22142:
    goto v_22143;
v_22144:
    fn = elt(env, 20); // domainvalchk
    v_22265 = (*qfn2(fn))(fn, stack[0], v_22265);
    env = stack[-8];
    v_22266 = v_22265;
    if (v_22265 == nil) goto v_22139;
    v_22265 = v_22266;
    goto v_21975;
v_22139:
    v_22265 = stack[-2];
    if (!consp(v_22265)) goto v_22160;
    else goto v_22161;
v_22160:
    goto v_22167;
v_22163:
    v_22265 = stack[-5];
    v_22266 = qcdr(v_22265);
    goto v_22164;
v_22165:
    v_22265 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22166;
v_22167:
    goto v_22163;
v_22164:
    goto v_22165;
v_22166:
    v_22265 = (v_22266 == v_22265 ? lisp_true : nil);
    goto v_22159;
v_22161:
    v_22265 = nil;
    goto v_22159;
    v_22265 = nil;
v_22159:
    if (v_22265 == nil) goto v_22157;
    goto v_22184;
v_22180:
    v_22266 = stack[-2];
    goto v_22181;
v_22182:
    v_22265 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_22183;
v_22184:
    goto v_22180;
v_22181:
    goto v_22182;
v_22183:
    v_22265 = (LispObject)lessp2(v_22266, v_22265);
    v_22265 = v_22265 ? lisp_true : nil;
    env = stack[-8];
    if (v_22265 == nil) goto v_22177;
    else goto v_22178;
v_22177:
    goto v_22192;
v_22188:
    v_22266 = stack[-1];
    goto v_22189;
v_22190:
    v_22265 = stack[-2];
    goto v_22191;
v_22192:
    goto v_22188;
v_22189:
    goto v_22190;
v_22191:
    fn = elt(env, 21); // exptsq
    v_22265 = (*qfn2(fn))(fn, v_22266, v_22265);
    goto v_22176;
v_22178:
    v_22265 = qvalue(elt(env, 9)); // !*mcd
    if (v_22265 == nil) goto v_22196;
    goto v_22204;
v_22200:
    stack[0] = stack[-1];
    goto v_22201;
v_22202:
    v_22265 = stack[-2];
    v_22265 = negate(v_22265);
    env = stack[-8];
    goto v_22203;
v_22204:
    goto v_22200;
v_22201:
    goto v_22202;
v_22203:
    fn = elt(env, 21); // exptsq
    v_22265 = (*qfn2(fn))(fn, stack[0], v_22265);
    env = stack[-8];
    fn = elt(env, 22); // invsq
    v_22265 = (*qfn1(fn))(fn, v_22265);
    goto v_22176;
v_22196:
    goto v_22215;
v_22211:
    goto v_22221;
v_22217:
    goto v_22227;
v_22223:
    v_22265 = stack[-1];
    v_22266 = qcar(v_22265);
    goto v_22224;
v_22225:
    v_22265 = stack[-2];
    goto v_22226;
v_22227:
    goto v_22223;
v_22224:
    goto v_22225;
v_22226:
    fn = elt(env, 23); // expf
    stack[0] = (*qfn2(fn))(fn, v_22266, v_22265);
    env = stack[-8];
    goto v_22218;
v_22219:
    goto v_22236;
v_22232:
    v_22265 = stack[-1];
    stack[-1] = qcdr(v_22265);
    goto v_22233;
v_22234:
    v_22265 = stack[-2];
    v_22265 = negate(v_22265);
    env = stack[-8];
    goto v_22235;
v_22236:
    goto v_22232;
v_22233:
    goto v_22234;
v_22235:
    fn = elt(env, 24); // mksfpf
    v_22265 = (*qfn2(fn))(fn, stack[-1], v_22265);
    env = stack[-8];
    goto v_22220;
v_22221:
    goto v_22217;
v_22218:
    goto v_22219;
v_22220:
    fn = elt(env, 25); // multf
    v_22266 = (*qfn2(fn))(fn, stack[0], v_22265);
    env = stack[-8];
    goto v_22212;
v_22213:
    v_22265 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_22214;
v_22215:
    goto v_22211;
v_22212:
    goto v_22213;
v_22214:
    v_22265 = cons(v_22266, v_22265);
    goto v_22176;
    v_22265 = nil;
v_22176:
    goto v_21975;
v_22157:
    goto v_22251;
v_22245:
    v_22265 = stack[-4];
    if (v_22265 == nil) goto v_22255;
    v_22265 = stack[-6];
    v_22267 = v_22265;
    goto v_22253;
v_22255:
    v_22265 = stack[-1];
    fn = elt(env, 26); // subs2!*
    v_22265 = (*qfn1(fn))(fn, v_22265);
    env = stack[-8];
    fn = elt(env, 13); // prepsq!*
    v_22265 = (*qfn1(fn))(fn, v_22265);
    env = stack[-8];
    v_22267 = v_22265;
    goto v_22253;
    v_22267 = nil;
v_22253:
    goto v_22246;
v_22247:
    v_22266 = stack[-5];
    goto v_22248;
v_22249:
    v_22265 = lisp_true;
    goto v_22250;
v_22251:
    goto v_22245;
v_22246:
    goto v_22247;
v_22248:
    goto v_22249;
v_22250:
    fn = elt(env, 14); // simpexpt11
    v_22265 = (*qfnn(fn))(fn, 3, v_22267, v_22266, v_22265);
    goto v_21975;
    v_22265 = nil;
v_21975:
v_21724:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_22265);
}



// Code for evalnumberp

static LispObject CC_evalnumberp(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21774, v_21775, v_21776;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21774 = v_21714;
// end of prologue
    fn = elt(env, 3); // aeval
    v_21774 = (*qfn1(fn))(fn, v_21774);
    env = stack[0];
    v_21776 = v_21774;
    v_21774 = v_21776;
    if (!consp(v_21774)) goto v_21721;
    else goto v_21722;
v_21721:
    v_21774 = v_21776;
    v_21774 = (is_number(v_21774) ? lisp_true : nil);
    goto v_21720;
v_21722:
    goto v_21736;
v_21732:
    v_21774 = v_21776;
    v_21775 = qcar(v_21774);
    goto v_21733;
v_21734:
    v_21774 = elt(env, 1); // !*sq
    goto v_21735;
v_21736:
    goto v_21732;
v_21733:
    goto v_21734;
v_21735:
    if (v_21775 == v_21774) goto v_21731;
    v_21774 = lisp_true;
    goto v_21729;
v_21731:
    v_21774 = v_21776;
    v_21774 = qcdr(v_21774);
    v_21774 = qcar(v_21774);
    v_21774 = qcdr(v_21774);
    v_21774 = (consp(v_21774) ? nil : lisp_true);
    v_21774 = (v_21774 == nil ? lisp_true : nil);
    goto v_21729;
    v_21774 = nil;
v_21729:
    if (v_21774 == nil) goto v_21727;
    v_21774 = nil;
    goto v_21720;
v_21727:
    v_21774 = v_21776;
    v_21774 = qcdr(v_21774);
    v_21774 = qcar(v_21774);
    v_21774 = qcar(v_21774);
    v_21775 = v_21774;
    v_21774 = v_21775;
    if (!consp(v_21774)) goto v_21759;
    else goto v_21760;
v_21759:
    v_21774 = lisp_true;
    goto v_21758;
v_21760:
    goto v_21770;
v_21766:
    v_21774 = v_21775;
    v_21774 = qcar(v_21774);
    goto v_21767;
v_21768:
    v_21775 = elt(env, 2); // numbertag
    goto v_21769;
v_21770:
    goto v_21766;
v_21767:
    goto v_21768;
v_21769:
        return Lflagp(nil, v_21774, v_21775);
    v_21774 = nil;
v_21758:
    goto v_21720;
    v_21774 = nil;
v_21720:
    return onevalue(v_21774);
}



// Code for mri_opn

static LispObject CC_mri_opn(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21729, v_21730;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
// copy arguments values to proper place
    v_21729 = v_21714;
// end of prologue
    fn = elt(env, 1); // mri_op
    v_21729 = (*qfn1(fn))(fn, v_21729);
    v_21730 = v_21729;
    v_21729 = v_21730;
    if (!consp(v_21729)) goto v_21721;
    else goto v_21722;
v_21721:
    v_21729 = v_21730;
    goto v_21720;
v_21722:
    v_21729 = v_21730;
    v_21729 = qcar(v_21729);
    goto v_21720;
    v_21729 = nil;
v_21720:
    return onevalue(v_21729);
}



// Code for dip_f2dip2

static LispObject CC_dip_f2dip2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21783, v_21784, v_21785, v_21786, v_21787, v_21788;
    LispObject fn;
    LispObject v_21718, v_21717, v_21716, v_21715, v_21714;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "dip_f2dip2");
    va_start(aa, nargs);
    v_21714 = va_arg(aa, LispObject);
    v_21715 = va_arg(aa, LispObject);
    v_21716 = va_arg(aa, LispObject);
    v_21717 = va_arg(aa, LispObject);
    v_21718 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_21718,v_21717,v_21716,v_21715,v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_21714,v_21715,v_21716,v_21717,v_21718);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_21718;
    v_21785 = v_21717;
    v_21786 = v_21716;
    v_21787 = v_21715;
    v_21788 = v_21714;
// end of prologue
    goto v_21728;
v_21724:
    v_21784 = v_21788;
    goto v_21725;
v_21726:
    v_21783 = qvalue(elt(env, 1)); // dip_vars!*
    goto v_21727;
v_21728:
    goto v_21724;
v_21725:
    goto v_21726;
v_21727:
    v_21783 = Lmemq(nil, v_21784, v_21783);
    if (v_21783 == nil) goto v_21723;
    goto v_21739;
v_21733:
    stack[0] = v_21786;
    goto v_21734;
v_21735:
    goto v_21750;
v_21742:
    v_21784 = v_21785;
    goto v_21743;
v_21744:
    v_21785 = v_21788;
    goto v_21745;
v_21746:
    v_21786 = v_21787;
    goto v_21747;
v_21748:
    v_21783 = qvalue(elt(env, 1)); // dip_vars!*
    goto v_21749;
v_21750:
    goto v_21742;
v_21743:
    goto v_21744;
v_21745:
    goto v_21746;
v_21747:
    goto v_21748;
v_21749:
    fn = elt(env, 2); // ev_insert
    v_21784 = (*qfnn(fn))(fn, 4, v_21784, v_21785, v_21786, v_21783);
    env = stack[-3];
    goto v_21736;
v_21737:
    v_21783 = stack[-1];
    goto v_21738;
v_21739:
    goto v_21733;
v_21734:
    goto v_21735;
v_21736:
    goto v_21737;
v_21738:
    {
        LispObject v_21792 = stack[0];
        fn = elt(env, 3); // dip_f2dip1
        return (*qfnn(fn))(fn, 3, v_21792, v_21784, v_21783);
    }
v_21723:
    goto v_21765;
v_21759:
    stack[-2] = v_21786;
    goto v_21760;
v_21761:
    stack[0] = v_21785;
    goto v_21762;
v_21763:
    goto v_21773;
v_21769:
    goto v_21770;
v_21771:
    goto v_21780;
v_21776:
    v_21783 = v_21788;
    goto v_21777;
v_21778:
    v_21784 = v_21787;
    goto v_21779;
v_21780:
    goto v_21776;
v_21777:
    goto v_21778;
v_21779:
    fn = elt(env, 4); // bc_pmon
    v_21783 = (*qfn2(fn))(fn, v_21783, v_21784);
    env = stack[-3];
    goto v_21772;
v_21773:
    goto v_21769;
v_21770:
    goto v_21771;
v_21772:
    fn = elt(env, 5); // bc_prod
    v_21783 = (*qfn2(fn))(fn, stack[-1], v_21783);
    env = stack[-3];
    goto v_21764;
v_21765:
    goto v_21759;
v_21760:
    goto v_21761;
v_21762:
    goto v_21763;
v_21764:
    {
        LispObject v_21793 = stack[-2];
        LispObject v_21794 = stack[0];
        fn = elt(env, 3); // dip_f2dip1
        return (*qfnn(fn))(fn, 3, v_21793, v_21794, v_21783);
    }
    v_21783 = nil;
    return onevalue(v_21783);
}



// Code for rl_surep

static LispObject CC_rl_surep(LispObject env,
                         LispObject v_21714, LispObject v_21715)
{
    env = qenv(env);
    LispObject v_21732, v_21733;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21715,v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21714,v_21715);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21732 = v_21715;
    v_21733 = v_21714;
// end of prologue
    goto v_21722;
v_21718:
    stack[0] = qvalue(elt(env, 1)); // rl_surep!*
    goto v_21719;
v_21720:
    goto v_21729;
v_21725:
    goto v_21726;
v_21727:
    goto v_21728;
v_21729:
    goto v_21725;
v_21726:
    goto v_21727;
v_21728:
    v_21732 = list2(v_21733, v_21732);
    env = stack[-1];
    goto v_21721;
v_21722:
    goto v_21718;
v_21719:
    goto v_21720;
v_21721:
    {
        LispObject v_21735 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_21735, v_21732);
    }
}



// Code for containerom

static LispObject CC_containerom(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21843, v_21844;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_21714;
// end of prologue
    v_21843 = stack[-2];
    v_21843 = qcdr(v_21843);
    v_21843 = qcar(v_21843);
    stack[-1] = v_21843;
    v_21843 = stack[-2];
    v_21843 = qcar(v_21843);
    stack[0] = v_21843;
    v_21843 = elt(env, 2); // "<OMA>"
    fn = elt(env, 14); // printout
    v_21843 = (*qfn1(fn))(fn, v_21843);
    env = stack[-4];
    v_21843 = lisp_true;
    fn = elt(env, 15); // indent!*
    v_21843 = (*qfn1(fn))(fn, v_21843);
    env = stack[-4];
    goto v_21739;
v_21735:
    v_21844 = stack[0];
    goto v_21736;
v_21737:
    v_21843 = elt(env, 3); // vectorml
    goto v_21738;
v_21739:
    goto v_21735;
v_21736:
    goto v_21737;
v_21738:
    if (v_21844 == v_21843) goto v_21733;
    else goto v_21734;
v_21733:
    v_21843 = elt(env, 4); // vector
    stack[0] = v_21843;
    goto v_21732;
v_21734:
v_21732:
    goto v_21747;
v_21743:
    v_21844 = stack[0];
    goto v_21744;
v_21745:
    v_21843 = qvalue(elt(env, 5)); // valid_om!*
    goto v_21746;
v_21747:
    goto v_21743;
v_21744:
    goto v_21745;
v_21746:
    v_21843 = Lassoc(nil, v_21844, v_21843);
    v_21843 = qcdr(v_21843);
    v_21843 = qcar(v_21843);
    stack[-3] = v_21843;
    goto v_21765;
v_21761:
    v_21843 = stack[-2];
    v_21844 = qcar(v_21843);
    goto v_21762;
v_21763:
    v_21843 = elt(env, 6); // set
    goto v_21764;
v_21765:
    goto v_21761;
v_21762:
    goto v_21763;
v_21764:
    if (v_21844 == v_21843) goto v_21759;
    else goto v_21760;
v_21759:
    v_21843 = stack[-1];
    v_21843 = Lconsp(nil, v_21843);
    env = stack[-4];
    goto v_21758;
v_21760:
    v_21843 = nil;
    goto v_21758;
    v_21843 = nil;
v_21758:
    if (v_21843 == nil) goto v_21756;
    goto v_21782;
v_21778:
    v_21843 = stack[-1];
    v_21843 = qcar(v_21843);
    v_21843 = qcdr(v_21843);
    v_21843 = qcar(v_21843);
    v_21844 = Lintern(nil, v_21843);
    env = stack[-4];
    goto v_21779;
v_21780:
    v_21843 = elt(env, 7); // multiset
    goto v_21781;
v_21782:
    goto v_21778;
v_21779:
    goto v_21780;
v_21781:
    if (v_21844 == v_21843) goto v_21776;
    else goto v_21777;
v_21776:
    v_21843 = elt(env, 8); // multiset1
    stack[-3] = v_21843;
    goto v_21775;
v_21777:
v_21775:
    goto v_21754;
v_21756:
v_21754:
    goto v_21799;
v_21795:
    v_21843 = stack[-2];
    v_21844 = qcar(v_21843);
    goto v_21796;
v_21797:
    v_21843 = elt(env, 3); // vectorml
    goto v_21798;
v_21799:
    goto v_21795;
v_21796:
    goto v_21797;
v_21798:
    if (v_21844 == v_21843) goto v_21793;
    else goto v_21794;
v_21793:
    v_21843 = elt(env, 9); // "vector"
    stack[0] = v_21843;
    goto v_21792;
v_21794:
v_21792:
    goto v_21812;
v_21808:
    v_21843 = stack[-2];
    v_21844 = qcar(v_21843);
    goto v_21809;
v_21810:
    v_21843 = elt(env, 3); // vectorml
    goto v_21811;
v_21812:
    goto v_21808;
v_21809:
    goto v_21810;
v_21811:
    if (v_21844 == v_21843) goto v_21806;
    else goto v_21807;
v_21806:
    goto v_21821;
v_21817:
    v_21844 = elt(env, 4); // vector
    goto v_21818;
v_21819:
    v_21843 = stack[-2];
    v_21843 = qcdr(v_21843);
    goto v_21820;
v_21821:
    goto v_21817;
v_21818:
    goto v_21819;
v_21820:
    v_21843 = cons(v_21844, v_21843);
    env = stack[-4];
    stack[-2] = v_21843;
    goto v_21805;
v_21807:
v_21805:
    v_21843 = elt(env, 10); // "<OMS cd="""
    fn = elt(env, 14); // printout
    v_21843 = (*qfn1(fn))(fn, v_21843);
    env = stack[-4];
    v_21843 = stack[-3];
    v_21843 = Lprinc(nil, v_21843);
    env = stack[-4];
    v_21843 = elt(env, 11); // """ name="""
    v_21843 = Lprinc(nil, v_21843);
    env = stack[-4];
    v_21843 = stack[0];
    v_21843 = Lprinc(nil, v_21843);
    env = stack[-4];
    v_21843 = elt(env, 12); // """/>"
    v_21843 = Lprinc(nil, v_21843);
    env = stack[-4];
    v_21843 = stack[-2];
    v_21843 = qcdr(v_21843);
    v_21843 = qcdr(v_21843);
    fn = elt(env, 16); // multiom
    v_21843 = (*qfn1(fn))(fn, v_21843);
    env = stack[-4];
    v_21843 = nil;
    fn = elt(env, 15); // indent!*
    v_21843 = (*qfn1(fn))(fn, v_21843);
    env = stack[-4];
    v_21843 = elt(env, 13); // "</OMA>"
    fn = elt(env, 14); // printout
    v_21843 = (*qfn1(fn))(fn, v_21843);
    v_21843 = nil;
    return onevalue(v_21843);
}



// Code for bflessp

static LispObject CC_bflessp(LispObject env,
                         LispObject v_21714, LispObject v_21715)
{
    env = qenv(env);
    LispObject v_21740, v_21741, v_21742;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21741 = v_21715;
    v_21742 = v_21714;
// end of prologue
    v_21740 = v_21742;
    if (!consp(v_21740)) goto v_21719;
    else goto v_21720;
v_21719:
    goto v_21727;
v_21723:
    v_21740 = v_21742;
    goto v_21724;
v_21725:
    goto v_21726;
v_21727:
    goto v_21723;
v_21724:
    goto v_21725;
v_21726:
        return Llessp(nil, v_21740, v_21741);
v_21720:
    goto v_21737;
v_21733:
    v_21740 = v_21741;
    goto v_21734;
v_21735:
    v_21741 = v_21742;
    goto v_21736;
v_21737:
    goto v_21733;
v_21734:
    goto v_21735;
v_21736:
    {
        fn = elt(env, 1); // grpbf
        return (*qfn2(fn))(fn, v_21740, v_21741);
    }
    v_21740 = nil;
    return onevalue(v_21740);
}



// Code for z!-roads

static LispObject CC_zKroads(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21791, v_21792, v_21793;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21792 = v_21714;
// end of prologue
    goto v_21724;
v_21720:
    v_21793 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21721;
v_21722:
    v_21791 = v_21792;
    v_21791 = qcar(v_21791);
    v_21791 = qcar(v_21791);
    v_21791 = qcdr(v_21791);
    goto v_21723;
v_21724:
    goto v_21720;
v_21721:
    goto v_21722;
v_21723:
    if (v_21793 == v_21791) goto v_21718;
    else goto v_21719;
v_21718:
    v_21791 = v_21792;
    v_21791 = qcar(v_21791);
    v_21791 = qcar(v_21791);
    goto v_21717;
v_21719:
    goto v_21739;
v_21735:
    v_21793 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21736;
v_21737:
    v_21791 = v_21792;
    v_21791 = qcar(v_21791);
    v_21791 = qcdr(v_21791);
    v_21791 = qcar(v_21791);
    v_21791 = qcdr(v_21791);
    goto v_21738;
v_21739:
    goto v_21735;
v_21736:
    goto v_21737;
v_21738:
    if (v_21793 == v_21791) goto v_21733;
    else goto v_21734;
v_21733:
    v_21791 = v_21792;
    v_21791 = qcar(v_21791);
    v_21791 = qcdr(v_21791);
    v_21791 = qcar(v_21791);
    goto v_21717;
v_21734:
    goto v_21756;
v_21752:
    v_21793 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21753;
v_21754:
    v_21791 = v_21792;
    v_21791 = qcar(v_21791);
    v_21791 = qcdr(v_21791);
    v_21791 = qcdr(v_21791);
    v_21791 = qcar(v_21791);
    v_21791 = qcdr(v_21791);
    goto v_21755;
v_21756:
    goto v_21752;
v_21753:
    goto v_21754;
v_21755:
    if (v_21793 == v_21791) goto v_21750;
    else goto v_21751;
v_21750:
    v_21791 = v_21792;
    v_21791 = qcar(v_21791);
    v_21791 = qcdr(v_21791);
    v_21791 = qcdr(v_21791);
    v_21791 = qcar(v_21791);
    goto v_21717;
v_21751:
    v_21791 = nil;
    goto v_21717;
    v_21791 = nil;
v_21717:
    v_21793 = v_21791;
    v_21791 = v_21793;
    if (v_21791 == nil) goto v_21775;
    else goto v_21776;
v_21775:
    v_21791 = nil;
    goto v_21774;
v_21776:
    goto v_21786;
v_21782:
    v_21791 = v_21793;
    v_21791 = qcar(v_21791);
    goto v_21783;
v_21784:
    v_21792 = qcdr(v_21792);
    goto v_21785;
v_21786:
    goto v_21782;
v_21783:
    goto v_21784;
v_21785:
    return cons(v_21791, v_21792);
    v_21791 = nil;
v_21774:
    return onevalue(v_21791);
}



// Code for assert_kernelp

static LispObject CC_assert_kernelp(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21761, v_21762;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21761 = v_21714;
// end of prologue
    v_21762 = v_21761;
    if (symbolp(v_21762)) goto v_21722;
    else goto v_21723;
v_21722:
    v_21761 = lisp_true;
    goto v_21718;
v_21723:
    v_21762 = v_21761;
    v_21762 = Lconsp(nil, v_21762);
    env = stack[0];
    if (v_21762 == nil) goto v_21728;
    else goto v_21729;
v_21728:
    v_21761 = nil;
    goto v_21718;
v_21729:
    v_21762 = v_21761;
    v_21762 = qcar(v_21762);
    if (!symbolp(v_21762)) v_21762 = nil;
    else { v_21762 = qfastgets(v_21762);
           if (v_21762 != nil) { v_21762 = elt(v_21762, 38); // fkernfn
#ifdef RECORD_GET
             if (v_21762 != SPID_NOPROP)
                record_get(elt(fastget_names, 38), 1);
             else record_get(elt(fastget_names, 38), 0),
                v_21762 = nil; }
           else record_get(elt(fastget_names, 38), 0); }
#else
             if (v_21762 == SPID_NOPROP) v_21762 = nil; }}
#endif
    if (v_21762 == nil) goto v_21736;
    v_21761 = lisp_true;
    goto v_21718;
v_21736:
    v_21762 = v_21761;
    v_21762 = qcar(v_21762);
    if (!consp(v_21762)) goto v_21743;
    else goto v_21744;
v_21743:
    v_21762 = v_21761;
    v_21762 = qcar(v_21762);
    if (!symbolp(v_21762)) v_21762 = nil;
    else { v_21762 = qfastgets(v_21762);
           if (v_21762 != nil) { v_21762 = elt(v_21762, 24); // klist
#ifdef RECORD_GET
             if (v_21762 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v_21762 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v_21762 == SPID_NOPROP) v_21762 = nil; }}
#endif
    goto v_21742;
v_21744:
    v_21762 = qvalue(elt(env, 2)); // exlist!*
    goto v_21742;
    v_21762 = nil;
v_21742:
    goto v_21757;
v_21753:
    goto v_21754;
v_21755:
    goto v_21756;
v_21757:
    goto v_21753;
v_21754:
    goto v_21755;
v_21756:
    v_21761 = Latsoc(nil, v_21761, v_21762);
v_21718:
    return onevalue(v_21761);
}



// Code for msolve!-psys1

static LispObject CC_msolveKpsys1(LispObject env,
                         LispObject v_21714, LispObject v_21715)
{
    env = qenv(env);
    LispObject v_21839, v_21840;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21715,v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21714,v_21715);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_21715;
    stack[0] = v_21714;
// end of prologue
    v_21839 = nil;
    v_21839 = ncons(v_21839);
    env = stack[-7];
    v_21840 = v_21839;
    v_21839 = stack[0];
    stack[-4] = v_21839;
v_21729:
    v_21839 = stack[-4];
    if (v_21839 == nil) goto v_21733;
    else goto v_21734;
v_21733:
    goto v_21728;
v_21734:
    v_21839 = stack[-4];
    v_21839 = qcar(v_21839);
    stack[-3] = v_21839;
    v_21839 = nil;
    stack[-6] = v_21839;
    v_21839 = v_21840;
    stack[-2] = v_21839;
v_21744:
    v_21839 = stack[-2];
    if (v_21839 == nil) goto v_21748;
    else goto v_21749;
v_21748:
    goto v_21743;
v_21749:
    v_21839 = stack[-2];
    v_21839 = qcar(v_21839);
    stack[-1] = v_21839;
    goto v_21762;
v_21758:
    v_21840 = stack[-3];
    goto v_21759;
v_21760:
    v_21839 = stack[-1];
    goto v_21761;
v_21762:
    goto v_21758;
v_21759:
    goto v_21760;
v_21761:
    fn = elt(env, 2); // subf
    v_21839 = (*qfn2(fn))(fn, v_21840, v_21839);
    env = stack[-7];
    v_21839 = qcar(v_21839);
    fn = elt(env, 3); // moduntag
    v_21839 = (*qfn1(fn))(fn, v_21839);
    env = stack[-7];
    fn = elt(env, 4); // general!-reduce!-mod!-p
    v_21839 = (*qfn1(fn))(fn, v_21839);
    env = stack[-7];
    v_21840 = v_21839;
    v_21839 = v_21840;
    if (v_21839 == nil) goto v_21768;
    else goto v_21769;
v_21768:
    goto v_21776;
v_21772:
    v_21840 = stack[-1];
    goto v_21773;
v_21774:
    v_21839 = stack[-6];
    goto v_21775;
v_21776:
    goto v_21772;
v_21773:
    goto v_21774;
v_21775:
    v_21839 = cons(v_21840, v_21839);
    env = stack[-7];
    stack[-6] = v_21839;
    goto v_21767;
v_21769:
    v_21839 = v_21840;
    if (!consp(v_21839)) goto v_21783;
    else goto v_21784;
v_21783:
    v_21839 = lisp_true;
    goto v_21782;
v_21784:
    v_21839 = v_21840;
    v_21839 = qcar(v_21839);
    v_21839 = (consp(v_21839) ? nil : lisp_true);
    goto v_21782;
    v_21839 = nil;
v_21782:
    if (v_21839 == nil) goto v_21780;
    goto v_21767;
v_21780:
    goto v_21804;
v_21800:
    goto v_21801;
v_21802:
    v_21839 = stack[-5];
    goto v_21803;
v_21804:
    goto v_21800;
v_21801:
    goto v_21802;
v_21803:
    fn = elt(env, 5); // msolve!-poly
    v_21839 = (*qfn2(fn))(fn, v_21840, v_21839);
    env = stack[-7];
    stack[0] = v_21839;
v_21798:
    v_21839 = stack[0];
    if (v_21839 == nil) goto v_21809;
    else goto v_21810;
v_21809:
    goto v_21797;
v_21810:
    v_21839 = stack[0];
    v_21839 = qcar(v_21839);
    goto v_21821;
v_21817:
    goto v_21827;
v_21823:
    v_21840 = stack[-1];
    goto v_21824;
v_21825:
    goto v_21826;
v_21827:
    goto v_21823;
v_21824:
    goto v_21825;
v_21826:
    v_21840 = Lappend(nil, v_21840, v_21839);
    env = stack[-7];
    goto v_21818;
v_21819:
    v_21839 = stack[-6];
    goto v_21820;
v_21821:
    goto v_21817;
v_21818:
    goto v_21819;
v_21820:
    v_21839 = cons(v_21840, v_21839);
    env = stack[-7];
    stack[-6] = v_21839;
    v_21839 = stack[0];
    v_21839 = qcdr(v_21839);
    stack[0] = v_21839;
    goto v_21798;
v_21797:
    goto v_21767;
v_21767:
    v_21839 = stack[-2];
    v_21839 = qcdr(v_21839);
    stack[-2] = v_21839;
    goto v_21744;
v_21743:
    v_21839 = stack[-6];
    v_21840 = v_21839;
    v_21839 = stack[-4];
    v_21839 = qcdr(v_21839);
    stack[-4] = v_21839;
    goto v_21729;
v_21728:
    v_21839 = v_21840;
    return onevalue(v_21839);
}



// Code for assoc2

static LispObject CC_assoc2(LispObject env,
                         LispObject v_21714, LispObject v_21715)
{
    env = qenv(env);
    LispObject v_21743, v_21744, v_21745, v_21746;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21744 = v_21715;
    v_21745 = v_21714;
// end of prologue
v_21719:
    v_21743 = v_21744;
    if (v_21743 == nil) goto v_21722;
    else goto v_21723;
v_21722:
    v_21743 = nil;
    goto v_21718;
v_21723:
    goto v_21732;
v_21728:
    v_21746 = v_21745;
    goto v_21729;
v_21730:
    v_21743 = v_21744;
    v_21743 = qcar(v_21743);
    v_21743 = qcdr(v_21743);
    goto v_21731;
v_21732:
    goto v_21728;
v_21729:
    goto v_21730;
v_21731:
    if (equal(v_21746, v_21743)) goto v_21726;
    else goto v_21727;
v_21726:
    v_21743 = v_21744;
    v_21743 = qcar(v_21743);
    goto v_21718;
v_21727:
    v_21743 = v_21744;
    v_21743 = qcdr(v_21743);
    v_21744 = v_21743;
    goto v_21719;
    v_21743 = nil;
v_21718:
    return onevalue(v_21743);
}



// Code for lastcar

static LispObject CC_lastcar(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21735, v_21736;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21735 = v_21714;
// end of prologue
v_21718:
    v_21736 = v_21735;
    if (v_21736 == nil) goto v_21721;
    else goto v_21722;
v_21721:
    v_21735 = nil;
    goto v_21717;
v_21722:
    v_21736 = v_21735;
    v_21736 = qcdr(v_21736);
    if (v_21736 == nil) goto v_21725;
    else goto v_21726;
v_21725:
    v_21735 = qcar(v_21735);
    goto v_21717;
v_21726:
    v_21735 = qcdr(v_21735);
    goto v_21718;
    v_21735 = nil;
v_21717:
    return onevalue(v_21735);
}



// Code for testord

static LispObject CC_testord(LispObject env,
                         LispObject v_21714, LispObject v_21715)
{
    env = qenv(env);
    LispObject v_21745, v_21746;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21715,v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21714,v_21715);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21715;
    stack[-1] = v_21714;
// end of prologue
v_21719:
    v_21745 = stack[-1];
    if (v_21745 == nil) goto v_21722;
    else goto v_21723;
v_21722:
    v_21745 = lisp_true;
    goto v_21718;
v_21723:
    goto v_21733;
v_21729:
    v_21745 = stack[-1];
    v_21746 = qcar(v_21745);
    goto v_21730;
v_21731:
    v_21745 = stack[0];
    v_21745 = qcar(v_21745);
    goto v_21732;
v_21733:
    goto v_21729;
v_21730:
    goto v_21731;
v_21732:
    v_21745 = (LispObject)lesseq2(v_21746, v_21745);
    v_21745 = v_21745 ? lisp_true : nil;
    env = stack[-2];
    if (v_21745 == nil) goto v_21727;
    v_21745 = stack[-1];
    v_21745 = qcdr(v_21745);
    stack[-1] = v_21745;
    v_21745 = stack[0];
    v_21745 = qcdr(v_21745);
    stack[0] = v_21745;
    goto v_21719;
v_21727:
    v_21745 = nil;
    goto v_21718;
    v_21745 = nil;
v_21718:
    return onevalue(v_21745);
}



// Code for mk!+outer!+list

static LispObject CC_mkLouterLlist(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21728, v_21729;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_21714;
// end of prologue
    goto v_21724;
v_21720:
    v_21728 = elt(env, 1); // list
    v_21729 = ncons(v_21728);
    goto v_21721;
v_21722:
    v_21728 = stack[0];
    goto v_21723;
v_21724:
    goto v_21720;
v_21721:
    goto v_21722;
v_21723:
        return Lappend(nil, v_21729, v_21728);
    return onevalue(v_21728);
}



// Code for dvfsf_smupdknowl

static LispObject CC_dvfsf_smupdknowl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21754, v_21755, v_21756, v_21757, v_21758;
    LispObject fn;
    LispObject v_21717, v_21716, v_21715, v_21714;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "dvfsf_smupdknowl");
    va_start(aa, nargs);
    v_21714 = va_arg(aa, LispObject);
    v_21715 = va_arg(aa, LispObject);
    v_21716 = va_arg(aa, LispObject);
    v_21717 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21755 = v_21717;
    v_21756 = v_21716;
    v_21757 = v_21715;
    v_21758 = v_21714;
// end of prologue
    v_21754 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_21754 == nil) goto v_21722;
    goto v_21733;
v_21725:
    v_21754 = v_21758;
    goto v_21726;
v_21727:
    goto v_21728;
v_21729:
    goto v_21730;
v_21731:
    goto v_21732;
v_21733:
    goto v_21725;
v_21726:
    goto v_21727;
v_21728:
    goto v_21729;
v_21730:
    goto v_21731;
v_21732:
    {
        fn = elt(env, 2); // cl_susiupdknowl
        return (*qfnn(fn))(fn, 4, v_21754, v_21757, v_21756, v_21755);
    }
v_21722:
    goto v_21749;
v_21741:
    v_21754 = v_21758;
    goto v_21742;
v_21743:
    goto v_21744;
v_21745:
    goto v_21746;
v_21747:
    goto v_21748;
v_21749:
    goto v_21741;
v_21742:
    goto v_21743;
v_21744:
    goto v_21745;
v_21746:
    goto v_21747;
v_21748:
    {
        fn = elt(env, 3); // cl_smupdknowl
        return (*qfnn(fn))(fn, 4, v_21754, v_21757, v_21756, v_21755);
    }
    v_21754 = nil;
    return onevalue(v_21754);
}



// Code for setfuncsnaryrd

static LispObject CC_setfuncsnaryrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21768, v_21769;
    LispObject fn;
    argcheck(nargs, 0, "setfuncsnaryrd");
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
    fn = elt(env, 4); // mathml
    v_21768 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_21768;
    v_21768 = stack[0];
    v_21768 = Lconsp(nil, v_21768);
    env = stack[-1];
    if (v_21768 == nil) goto v_21723;
    v_21768 = stack[0];
    v_21768 = qcdr(v_21768);
    v_21768 = qcar(v_21768);
    if (v_21768 == nil) goto v_21729;
    goto v_21741;
v_21737:
    v_21768 = stack[0];
    v_21768 = qcdr(v_21768);
    v_21768 = qcar(v_21768);
    v_21768 = qcar(v_21768);
    v_21768 = qcdr(v_21768);
    v_21768 = qcar(v_21768);
    v_21769 = Lintern(nil, v_21768);
    env = stack[-1];
    goto v_21738;
v_21739:
    v_21768 = elt(env, 2); // multiset
    goto v_21740;
v_21741:
    goto v_21737;
v_21738:
    goto v_21739;
v_21740:
    if (v_21769 == v_21768) goto v_21735;
    else goto v_21736;
v_21735:
    v_21768 = elt(env, 2); // multiset
    qvalue(elt(env, 3)) = v_21768; // mmlatts
    goto v_21734;
v_21736:
v_21734:
    goto v_21727;
v_21729:
v_21727:
    goto v_21721;
v_21723:
v_21721:
    v_21768 = stack[0];
    if (v_21768 == nil) goto v_21754;
    else goto v_21755;
v_21754:
    v_21768 = nil;
    goto v_21753;
v_21755:
    goto v_21765;
v_21761:
    goto v_21762;
v_21763:
    v_21768 = CC_setfuncsnaryrd(elt(env, 0), 0);
    goto v_21764;
v_21765:
    goto v_21761;
v_21762:
    goto v_21763;
v_21764:
    {
        LispObject v_21771 = stack[0];
        return cons(v_21771, v_21768);
    }
    v_21768 = nil;
v_21753:
    return onevalue(v_21768);
}



// Code for multerm

static LispObject CC_multerm(LispObject env,
                         LispObject v_21714, LispObject v_21715)
{
    env = qenv(env);
    LispObject v_21748, v_21749;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21715,v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21714,v_21715);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21715;
    stack[-1] = v_21714;
// end of prologue
    goto v_21726;
v_21722:
    v_21748 = stack[-1];
    v_21749 = qcdr(v_21748);
    goto v_21723;
v_21724:
    v_21748 = stack[0];
    v_21748 = qcdr(v_21748);
    goto v_21725;
v_21726:
    goto v_21722;
v_21723:
    goto v_21724;
v_21725:
    fn = elt(env, 2); // !*multsq
    v_21748 = (*qfn2(fn))(fn, v_21749, v_21748);
    env = stack[-3];
    goto v_21736;
v_21732:
    stack[-2] = v_21748;
    goto v_21733;
v_21734:
    goto v_21743;
v_21739:
    v_21748 = stack[-1];
    v_21749 = qcar(v_21748);
    goto v_21740;
v_21741:
    v_21748 = stack[0];
    v_21748 = qcar(v_21748);
    goto v_21742;
v_21743:
    goto v_21739;
v_21740:
    goto v_21741;
v_21742:
    fn = elt(env, 3); // mulpower
    v_21748 = (*qfn2(fn))(fn, v_21749, v_21748);
    env = stack[-3];
    goto v_21735;
v_21736:
    goto v_21732;
v_21733:
    goto v_21734;
v_21735:
    {
        LispObject v_21753 = stack[-2];
        fn = elt(env, 4); // multdfconst
        return (*qfn2(fn))(fn, v_21753, v_21748);
    }
    return onevalue(v_21748);
}



// Code for diplmon2sq

static LispObject CC_diplmon2sq(LispObject env,
                         LispObject v_21714, LispObject v_21715)
{
    env = qenv(env);
    LispObject v_21739, v_21740;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21715,v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21714,v_21715);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21739 = v_21715;
    v_21740 = v_21714;
// end of prologue
    goto v_21722;
v_21718:
    stack[0] = v_21740;
    goto v_21719;
v_21720:
    goto v_21729;
v_21725:
    goto v_21735;
v_21731:
    v_21740 = v_21739;
    goto v_21732;
v_21733:
    v_21739 = qvalue(elt(env, 1)); // dipvars!*
    goto v_21734;
v_21735:
    goto v_21731;
v_21732:
    goto v_21733;
v_21734:
    fn = elt(env, 2); // dipev2f
    v_21740 = (*qfn2(fn))(fn, v_21740, v_21739);
    env = stack[-1];
    goto v_21726;
v_21727:
    v_21739 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21728;
v_21729:
    goto v_21725;
v_21726:
    goto v_21727;
v_21728:
    v_21739 = cons(v_21740, v_21739);
    env = stack[-1];
    goto v_21721;
v_21722:
    goto v_21718;
v_21719:
    goto v_21720;
v_21721:
    {
        LispObject v_21742 = stack[0];
        fn = elt(env, 3); // multsq
        return (*qfn2(fn))(fn, v_21742, v_21739);
    }
}



// Code for vdpcleanup

static LispObject CC_vdpcleanup(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21717;
    argcheck(nargs, 0, "vdpcleanup");
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
    v_21717 = nil;
    v_21717 = ncons(v_21717);
    env = stack[0];
    qvalue(elt(env, 1)) = v_21717; // dipevlist!*
    return onevalue(v_21717);
}



// Code for divide!-by!-power!-of!-ten

static LispObject CC_divideKbyKpowerKofKten(LispObject env,
                         LispObject v_21714, LispObject v_21715)
{
    env = qenv(env);
    LispObject v_21794, v_21795, v_21796;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21715,v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21714,v_21715);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21715;
    stack[-1] = v_21714;
// end of prologue
    goto v_21726;
v_21722:
    v_21795 = stack[0];
    goto v_21723;
v_21724:
    v_21794 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21725;
v_21726:
    goto v_21722;
v_21723:
    goto v_21724;
v_21725:
    v_21794 = (LispObject)lessp2(v_21795, v_21794);
    v_21794 = v_21794 ? lisp_true : nil;
    env = stack[-3];
    if (v_21794 == nil) goto v_21720;
    v_21794 = elt(env, 0); // divide!-by!-power!-of!-ten
    {
        fn = elt(env, 3); // bflerrmsg
        return (*qfn1(fn))(fn, v_21794);
    }
v_21720:
    v_21794 = qvalue(elt(env, 1)); // bften!*
    stack[-2] = v_21794;
v_21737:
    goto v_21747;
v_21743:
    v_21795 = stack[0];
    goto v_21744;
v_21745:
    v_21794 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21746;
v_21747:
    goto v_21743;
v_21744:
    goto v_21745;
v_21746:
    v_21794 = (LispObject)greaterp2(v_21795, v_21794);
    v_21794 = v_21794 ? lisp_true : nil;
    env = stack[-3];
    if (v_21794 == nil) goto v_21740;
    else goto v_21741;
v_21740:
    goto v_21736;
v_21741:
    v_21794 = stack[0];
    v_21794 = Levenp(nil, v_21794);
    env = stack[-3];
    if (v_21794 == nil) goto v_21753;
    else goto v_21754;
v_21753:
    goto v_21765;
v_21759:
    v_21796 = stack[-1];
    goto v_21760;
v_21761:
    v_21795 = stack[-2];
    goto v_21762;
v_21763:
    v_21794 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_21764;
v_21765:
    goto v_21759;
v_21760:
    goto v_21761;
v_21762:
    goto v_21763;
v_21764:
    fn = elt(env, 4); // divide!:
    v_21794 = (*qfnn(fn))(fn, 3, v_21796, v_21795, v_21794);
    env = stack[-3];
    fn = elt(env, 5); // normbf
    v_21794 = (*qfn1(fn))(fn, v_21794);
    env = stack[-3];
    stack[-1] = v_21794;
    goto v_21752;
v_21754:
v_21752:
    goto v_21774;
v_21770:
    v_21795 = stack[0];
    goto v_21771;
v_21772:
    v_21794 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_21773;
v_21774:
    goto v_21770;
v_21771:
    goto v_21772;
v_21773:
    fn = elt(env, 6); // lshift
    v_21794 = (*qfn2(fn))(fn, v_21795, v_21794);
    env = stack[-3];
    stack[0] = v_21794;
    goto v_21783;
v_21779:
    goto v_21789;
v_21785:
    v_21795 = stack[-2];
    goto v_21786;
v_21787:
    v_21794 = stack[-2];
    goto v_21788;
v_21789:
    goto v_21785;
v_21786:
    goto v_21787;
v_21788:
    fn = elt(env, 7); // times!:
    v_21795 = (*qfn2(fn))(fn, v_21795, v_21794);
    env = stack[-3];
    goto v_21780;
v_21781:
    v_21794 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_21782;
v_21783:
    goto v_21779;
v_21780:
    goto v_21781;
v_21782:
    fn = elt(env, 8); // cut!:mt
    v_21794 = (*qfn2(fn))(fn, v_21795, v_21794);
    env = stack[-3];
    fn = elt(env, 5); // normbf
    v_21794 = (*qfn1(fn))(fn, v_21794);
    env = stack[-3];
    stack[-2] = v_21794;
    goto v_21737;
v_21736:
    v_21794 = stack[-1];
    goto v_21718;
    v_21794 = nil;
v_21718:
    return onevalue(v_21794);
}



// Code for lf!=zero

static LispObject CC_lfMzero(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21719;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21719 = v_21714;
// end of prologue
    v_21719 = qcdr(v_21719);
    v_21719 = (v_21719 == nil ? lisp_true : nil);
    return onevalue(v_21719);
}



// Code for lalr_expand_grammar

static LispObject CC_lalr_expand_grammar(LispObject env,
                         LispObject v_21714)
{
    env = qenv(env);
    LispObject v_21750, v_21751;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21714);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21714);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_21750 = v_21714;
// end of prologue
// Binding pending_rules!*
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 1, -1);
    qvalue(elt(env, 1)) = nil; // pending_rules!*
    fn = elt(env, 3); // lalr_check_grammar
    v_21750 = (*qfn1(fn))(fn, v_21750);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_21750; // pending_rules!*
    v_21750 = nil;
    stack[0] = v_21750;
v_21728:
    v_21750 = qvalue(elt(env, 1)); // pending_rules!*
    if (v_21750 == nil) goto v_21731;
    else goto v_21732;
v_21731:
    goto v_21727;
v_21732:
    v_21750 = qvalue(elt(env, 1)); // pending_rules!*
    v_21750 = qcar(v_21750);
    v_21751 = v_21750;
    v_21750 = qvalue(elt(env, 1)); // pending_rules!*
    v_21750 = qcdr(v_21750);
    qvalue(elt(env, 1)) = v_21750; // pending_rules!*
    goto v_21744;
v_21740:
    v_21750 = v_21751;
    fn = elt(env, 4); // expand_rule
    v_21751 = (*qfn1(fn))(fn, v_21750);
    env = stack[-2];
    goto v_21741;
v_21742:
    v_21750 = stack[0];
    goto v_21743;
v_21744:
    goto v_21740;
v_21741:
    goto v_21742;
v_21743:
    v_21750 = cons(v_21751, v_21750);
    env = stack[-2];
    stack[0] = v_21750;
    goto v_21728;
v_21727:
    v_21750 = stack[0];
    v_21750 = Lreverse(nil, v_21750);
    ;}  // end of a binding scope
    return onevalue(v_21750);
}



setup_type const u39_setup[] =
{
    {"listeval0",               CC_listeval0,   TOO_MANY_1,    WRONG_NO_1},
    {"sqprint",                 CC_sqprint,     TOO_MANY_1,    WRONG_NO_1},
    {"rootextractf",            CC_rootextractf,TOO_MANY_1,    WRONG_NO_1},
    {"reduce-eival-powers",     TOO_FEW_2,      CC_reduceKeivalKpowers,WRONG_NO_2},
    {"make-image",              TOO_FEW_2,      CC_makeKimage, WRONG_NO_2},
    {"ra_u",                    CC_ra_u,        TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_decdeg2",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_decdeg2},
    {"cl_atnum",                CC_cl_atnum,    TOO_MANY_1,    WRONG_NO_1},
    {"ioto_smaprinbuf",         CC_ioto_smaprinbuf,TOO_MANY_1, WRONG_NO_1},
    {"bvarom",                  CC_bvarom,      TOO_MANY_1,    WRONG_NO_1},
    {"rewrite",                 CC_rewrite,     TOO_MANY_1,    WRONG_NO_1},
    {"s-nextarg",               CC_sKnextarg,   TOO_MANY_1,    WRONG_NO_1},
    {"wedgef",                  CC_wedgef,      TOO_MANY_1,    WRONG_NO_1},
    {"apply_e",                 CC_apply_e,     TOO_MANY_1,    WRONG_NO_1},
    {"diff_vertex",             TOO_FEW_2,      CC_diff_vertex,WRONG_NO_2},
    {"no-side-effectp",         CC_noKsideKeffectp,TOO_MANY_1, WRONG_NO_1},
    {"innprodpex",              TOO_FEW_2,      CC_innprodpex, WRONG_NO_2},
    {"getavalue",               CC_getavalue,   TOO_MANY_1,    WRONG_NO_1},
    {"ratlessp",                TOO_FEW_2,      CC_ratlessp,   WRONG_NO_2},
    {"get-term-n",              TOO_FEW_2,      CC_getKtermKn, WRONG_NO_2},
    {"settcollectnonmultiprolongations",CC_settcollectnonmultiprolongations,TOO_MANY_1,WRONG_NO_1},
    {"ofsf_qesubqat",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_qesubqat},
    {"simpexpt1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_simpexpt1},
    {"evalnumberp",             CC_evalnumberp, TOO_MANY_1,    WRONG_NO_1},
    {"mri_opn",                 CC_mri_opn,     TOO_MANY_1,    WRONG_NO_1},
    {"dip_f2dip2",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dip_f2dip2},
    {"rl_surep",                TOO_FEW_2,      CC_rl_surep,   WRONG_NO_2},
    {"containerom",             CC_containerom, TOO_MANY_1,    WRONG_NO_1},
    {"bflessp",                 TOO_FEW_2,      CC_bflessp,    WRONG_NO_2},
    {"z-roads",                 CC_zKroads,     TOO_MANY_1,    WRONG_NO_1},
    {"assert_kernelp",          CC_assert_kernelp,TOO_MANY_1,  WRONG_NO_1},
    {"msolve-psys1",            TOO_FEW_2,      CC_msolveKpsys1,WRONG_NO_2},
    {"assoc2",                  TOO_FEW_2,      CC_assoc2,     WRONG_NO_2},
    {"lastcar",                 CC_lastcar,     TOO_MANY_1,    WRONG_NO_1},
    {"testord",                 TOO_FEW_2,      CC_testord,    WRONG_NO_2},
    {"mk+outer+list",           CC_mkLouterLlist,TOO_MANY_1,   WRONG_NO_1},
    {"dvfsf_smupdknowl",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dvfsf_smupdknowl},
    {"setfuncsnaryrd",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setfuncsnaryrd},
    {"multerm",                 TOO_FEW_2,      CC_multerm,    WRONG_NO_2},
    {"diplmon2sq",              TOO_FEW_2,      CC_diplmon2sq, WRONG_NO_2},
    {"vdpcleanup",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vdpcleanup},
    {"divide-by-power-of-ten",  TOO_FEW_2,      CC_divideKbyKpowerKofKten,WRONG_NO_2},
    {"lf=zero",                 CC_lfMzero,     TOO_MANY_1,    WRONG_NO_1},
    {"lalr_expand_grammar",     CC_lalr_expand_grammar,TOO_MANY_1,WRONG_NO_1},
    {NULL, (one_args *)"u39", (two_args *)"8505 9782644 1974927", 0}
};

// end of generated code
