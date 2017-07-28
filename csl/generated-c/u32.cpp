
// $destdir/u32.c        Machine generated C code

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



// Code for ofsf_simplat1

static LispObject CC_ofsf_simplat1(LispObject env,
                         LispObject v_18077, LispObject v_18078)
{
    env = qenv(env);
    LispObject v_18282, v_18283, v_18284;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18077,v_18078);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_18078;
    v_18284 = v_18077;
// end of prologue
    v_18282 = v_18284;
    v_18282 = qcar(v_18282);
    stack[-3] = v_18282;
    goto v_18094;
v_18090:
    v_18283 = stack[-3];
    goto v_18091;
v_18092:
    v_18282 = elt(env, 1); // (equal neq leq geq lessp greaterp)
    goto v_18093;
v_18094:
    goto v_18090;
v_18091:
    goto v_18092;
v_18093:
    v_18282 = Lmemq(nil, v_18283, v_18282);
    if (v_18282 == nil) goto v_18088;
    else goto v_18089;
v_18088:
    v_18282 = nil;
    goto v_18083;
v_18089:
    v_18282 = v_18284;
    v_18282 = qcdr(v_18282);
    v_18282 = qcar(v_18282);
    stack[-1] = v_18282;
    v_18282 = stack[-1];
    if (!consp(v_18282)) goto v_18108;
    else goto v_18109;
v_18108:
    v_18282 = lisp_true;
    goto v_18107;
v_18109:
    v_18282 = stack[-1];
    v_18282 = qcar(v_18282);
    v_18282 = (consp(v_18282) ? nil : lisp_true);
    goto v_18107;
    v_18282 = nil;
v_18107:
    if (v_18282 == nil) goto v_18105;
    goto v_18126;
v_18122:
    v_18283 = stack[-3];
    goto v_18123;
v_18124:
    v_18282 = stack[-1];
    goto v_18125;
v_18126:
    goto v_18122;
v_18123:
    goto v_18124;
v_18125:
    fn = elt(env, 11); // ofsf_evalatp
    v_18282 = (*qfn2(fn))(fn, v_18283, v_18282);
    env = stack[-4];
    if (v_18282 == nil) goto v_18120;
    v_18282 = elt(env, 2); // true
    goto v_18118;
v_18120:
    v_18282 = elt(env, 3); // false
    goto v_18118;
    v_18282 = nil;
v_18118:
    goto v_18083;
v_18105:
    goto v_18138;
v_18134:
    stack[0] = stack[-1];
    goto v_18135;
v_18136:
    v_18282 = stack[-1];
    fn = elt(env, 12); // sfto_dcontentf
    v_18282 = (*qfn1(fn))(fn, v_18282);
    env = stack[-4];
    goto v_18137;
v_18138:
    goto v_18134;
v_18135:
    goto v_18136;
v_18137:
    fn = elt(env, 13); // quotf
    v_18282 = (*qfn2(fn))(fn, stack[0], v_18282);
    env = stack[-4];
    stack[-1] = v_18282;
    v_18282 = stack[-1];
    fn = elt(env, 14); // minusf
    v_18282 = (*qfn1(fn))(fn, v_18282);
    env = stack[-4];
    if (v_18282 == nil) goto v_18145;
    v_18282 = stack[-1];
    fn = elt(env, 15); // negf
    v_18282 = (*qfn1(fn))(fn, v_18282);
    env = stack[-4];
    stack[-1] = v_18282;
    v_18282 = stack[-3];
    fn = elt(env, 16); // ofsf_anegrel
    v_18282 = (*qfn1(fn))(fn, v_18282);
    env = stack[-4];
    stack[-3] = v_18282;
    goto v_18143;
v_18145:
v_18143:
    v_18282 = qvalue(elt(env, 4)); // !*rlsiatadv
    if (v_18282 == nil) goto v_18154;
    else goto v_18155;
v_18154:
    goto v_18164;
v_18158:
    v_18284 = stack[-3];
    goto v_18159;
v_18160:
    v_18283 = stack[-1];
    goto v_18161;
v_18162:
    v_18282 = nil;
    goto v_18163;
v_18164:
    goto v_18158;
v_18159:
    goto v_18160;
v_18161:
    goto v_18162;
v_18163:
    return list3(v_18284, v_18283, v_18282);
v_18155:
    goto v_18176;
v_18172:
    v_18283 = stack[-3];
    goto v_18173;
v_18174:
    v_18282 = elt(env, 5); // equal
    goto v_18175;
v_18176:
    goto v_18172;
v_18173:
    goto v_18174;
v_18175:
    if (v_18283 == v_18282) goto v_18170;
    else goto v_18171;
v_18170:
    goto v_18184;
v_18180:
    v_18283 = stack[-1];
    goto v_18181;
v_18182:
    v_18282 = stack[-2];
    goto v_18183;
v_18184:
    goto v_18180;
v_18181:
    goto v_18182;
v_18183:
    {
        fn = elt(env, 17); // ofsf_simplequal
        return (*qfn2(fn))(fn, v_18283, v_18282);
    }
v_18171:
    goto v_18195;
v_18191:
    v_18283 = stack[-3];
    goto v_18192;
v_18193:
    v_18282 = elt(env, 6); // neq
    goto v_18194;
v_18195:
    goto v_18191;
v_18192:
    goto v_18193;
v_18194:
    if (v_18283 == v_18282) goto v_18189;
    else goto v_18190;
v_18189:
    goto v_18203;
v_18199:
    v_18283 = stack[-1];
    goto v_18200;
v_18201:
    v_18282 = stack[-2];
    goto v_18202;
v_18203:
    goto v_18199;
v_18200:
    goto v_18201;
v_18202:
    {
        fn = elt(env, 18); // ofsf_simplneq
        return (*qfn2(fn))(fn, v_18283, v_18282);
    }
v_18190:
    goto v_18214;
v_18210:
    v_18283 = stack[-3];
    goto v_18211;
v_18212:
    v_18282 = elt(env, 7); // leq
    goto v_18213;
v_18214:
    goto v_18210;
v_18211:
    goto v_18212;
v_18213:
    if (v_18283 == v_18282) goto v_18208;
    else goto v_18209;
v_18208:
    goto v_18222;
v_18218:
    v_18283 = stack[-1];
    goto v_18219;
v_18220:
    v_18282 = stack[-2];
    goto v_18221;
v_18222:
    goto v_18218;
v_18219:
    goto v_18220;
v_18221:
    {
        fn = elt(env, 19); // ofsf_simplleq
        return (*qfn2(fn))(fn, v_18283, v_18282);
    }
v_18209:
    goto v_18233;
v_18229:
    v_18283 = stack[-3];
    goto v_18230;
v_18231:
    v_18282 = elt(env, 8); // geq
    goto v_18232;
v_18233:
    goto v_18229;
v_18230:
    goto v_18231;
v_18232:
    if (v_18283 == v_18282) goto v_18227;
    else goto v_18228;
v_18227:
    goto v_18241;
v_18237:
    v_18283 = stack[-1];
    goto v_18238;
v_18239:
    v_18282 = stack[-2];
    goto v_18240;
v_18241:
    goto v_18237;
v_18238:
    goto v_18239;
v_18240:
    {
        fn = elt(env, 20); // ofsf_simplgeq
        return (*qfn2(fn))(fn, v_18283, v_18282);
    }
v_18228:
    goto v_18252;
v_18248:
    v_18283 = stack[-3];
    goto v_18249;
v_18250:
    v_18282 = elt(env, 9); // lessp
    goto v_18251;
v_18252:
    goto v_18248;
v_18249:
    goto v_18250;
v_18251:
    if (v_18283 == v_18282) goto v_18246;
    else goto v_18247;
v_18246:
    goto v_18260;
v_18256:
    v_18283 = stack[-1];
    goto v_18257;
v_18258:
    v_18282 = stack[-2];
    goto v_18259;
v_18260:
    goto v_18256;
v_18257:
    goto v_18258;
v_18259:
    {
        fn = elt(env, 21); // ofsf_simpllessp
        return (*qfn2(fn))(fn, v_18283, v_18282);
    }
v_18247:
    goto v_18271;
v_18267:
    v_18283 = stack[-3];
    goto v_18268;
v_18269:
    v_18282 = elt(env, 10); // greaterp
    goto v_18270;
v_18271:
    goto v_18267;
v_18268:
    goto v_18269;
v_18270:
    if (v_18283 == v_18282) goto v_18265;
    else goto v_18266;
v_18265:
    goto v_18279;
v_18275:
    v_18283 = stack[-1];
    goto v_18276;
v_18277:
    v_18282 = stack[-2];
    goto v_18278;
v_18279:
    goto v_18275;
v_18276:
    goto v_18277;
v_18278:
    {
        fn = elt(env, 22); // ofsf_simplgreaterp
        return (*qfn2(fn))(fn, v_18283, v_18282);
    }
v_18266:
    v_18282 = nil;
v_18083:
    return onevalue(v_18282);
}



// Code for containerml

static LispObject CC_containerml(LispObject env,
                         LispObject v_18077, LispObject v_18078)
{
    env = qenv(env);
    LispObject v_18120, v_18121;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18077,v_18078);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18078;
    stack[-1] = v_18077;
// end of prologue
    goto v_18090;
v_18086:
    v_18121 = stack[0];
    goto v_18087;
v_18088:
    v_18120 = elt(env, 1); // integer_interval
    goto v_18089;
v_18090:
    goto v_18086;
v_18087:
    goto v_18088;
v_18089:
    if (v_18121 == v_18120) goto v_18084;
    else goto v_18085;
v_18084:
    v_18120 = elt(env, 2); // interval
    stack[0] = v_18120;
    goto v_18083;
v_18085:
v_18083:
    v_18120 = elt(env, 3); // "<"
    fn = elt(env, 7); // printout
    v_18120 = (*qfn1(fn))(fn, v_18120);
    env = stack[-2];
    v_18120 = stack[0];
    v_18120 = Lprinc(nil, v_18120);
    env = stack[-2];
    goto v_18103;
v_18099:
    v_18120 = stack[-1];
    v_18121 = qcar(v_18120);
    goto v_18100;
v_18101:
    v_18120 = elt(env, 4); // ""
    goto v_18102;
v_18103:
    goto v_18099;
v_18100:
    goto v_18101;
v_18102:
    fn = elt(env, 8); // attributesml
    v_18120 = (*qfn2(fn))(fn, v_18121, v_18120);
    env = stack[-2];
    v_18120 = lisp_true;
    fn = elt(env, 9); // indent!*
    v_18120 = (*qfn1(fn))(fn, v_18120);
    env = stack[-2];
    v_18120 = stack[-1];
    v_18120 = qcdr(v_18120);
    fn = elt(env, 10); // multi_elem
    v_18120 = (*qfn1(fn))(fn, v_18120);
    env = stack[-2];
    v_18120 = nil;
    fn = elt(env, 9); // indent!*
    v_18120 = (*qfn1(fn))(fn, v_18120);
    env = stack[-2];
    v_18120 = elt(env, 5); // "</"
    fn = elt(env, 7); // printout
    v_18120 = (*qfn1(fn))(fn, v_18120);
    env = stack[-2];
    v_18120 = stack[0];
    v_18120 = Lprinc(nil, v_18120);
    env = stack[-2];
    v_18120 = elt(env, 6); // ">"
    v_18120 = Lprinc(nil, v_18120);
    v_18120 = nil;
    return onevalue(v_18120);
}



// Code for add_minus

static LispObject CC_add_minus(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18261, v_18262;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18077);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_18077;
// end of prologue
    v_18261 = stack[-1];
    if (!consp(v_18261)) goto v_18083;
    else goto v_18084;
v_18083:
    v_18261 = stack[-1];
    goto v_18080;
v_18084:
    goto v_18097;
v_18093:
    v_18261 = stack[-1];
    v_18262 = qcar(v_18261);
    goto v_18094;
v_18095:
    v_18261 = elt(env, 1); // !:rd!:
    goto v_18096;
v_18097:
    goto v_18093;
v_18094:
    goto v_18095;
v_18096:
    if (v_18262 == v_18261) goto v_18091;
    else goto v_18092;
v_18091:
    goto v_18106;
v_18102:
    v_18261 = stack[-1];
    v_18262 = qcdr(v_18261);
    goto v_18103;
v_18104:
    v_18261 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18105;
v_18106:
    goto v_18102;
v_18103:
    goto v_18104;
v_18105:
    v_18261 = (LispObject)geq2(v_18262, v_18261);
    v_18261 = v_18261 ? lisp_true : nil;
    env = stack[-3];
    goto v_18090;
v_18092:
    v_18261 = nil;
    goto v_18090;
    v_18261 = nil;
v_18090:
    if (v_18261 == nil) goto v_18088;
    v_18261 = stack[-1];
    goto v_18080;
v_18088:
    goto v_18124;
v_18120:
    v_18261 = stack[-1];
    v_18262 = qcar(v_18261);
    goto v_18121;
v_18122:
    v_18261 = elt(env, 1); // !:rd!:
    goto v_18123;
v_18124:
    goto v_18120;
v_18121:
    goto v_18122;
v_18123:
    if (v_18262 == v_18261) goto v_18118;
    else goto v_18119;
v_18118:
    goto v_18133;
v_18129:
    v_18261 = stack[-1];
    v_18262 = qcdr(v_18261);
    goto v_18130;
v_18131:
    v_18261 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18132;
v_18133:
    goto v_18129;
v_18130:
    goto v_18131;
v_18132:
    v_18261 = (LispObject)lessp2(v_18262, v_18261);
    v_18261 = v_18261 ? lisp_true : nil;
    env = stack[-3];
    goto v_18117;
v_18119:
    v_18261 = nil;
    goto v_18117;
    v_18261 = nil;
v_18117:
    if (v_18261 == nil) goto v_18115;
    goto v_18145;
v_18141:
    stack[-2] = elt(env, 2); // minus
    goto v_18142;
v_18143:
    goto v_18152;
v_18148:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_18149;
v_18150:
    v_18261 = stack[-1];
    v_18261 = qcdr(v_18261);
    v_18261 = Labsval(nil, v_18261);
    env = stack[-3];
    goto v_18151;
v_18152:
    goto v_18148;
v_18149:
    goto v_18150;
v_18151:
    v_18261 = cons(stack[0], v_18261);
    goto v_18144;
v_18145:
    goto v_18141;
v_18142:
    goto v_18143;
v_18144:
    {
        LispObject v_18266 = stack[-2];
        return list2(v_18266, v_18261);
    }
v_18115:
    goto v_18167;
v_18163:
    v_18261 = stack[-1];
    v_18262 = qcar(v_18261);
    goto v_18164;
v_18165:
    v_18261 = elt(env, 2); // minus
    goto v_18166;
v_18167:
    goto v_18163;
v_18164:
    goto v_18165;
v_18166:
    if (v_18262 == v_18261) goto v_18161;
    else goto v_18162;
v_18161:
    v_18261 = stack[-1];
    v_18261 = qcdr(v_18261);
    v_18261 = qcar(v_18261);
    v_18261 = (is_number(v_18261) ? lisp_true : nil);
    goto v_18160;
v_18162:
    v_18261 = nil;
    goto v_18160;
    v_18261 = nil;
v_18160:
    if (v_18261 == nil) goto v_18158;
    v_18261 = stack[-1];
    goto v_18080;
v_18158:
    goto v_18189;
v_18185:
    v_18261 = stack[-1];
    v_18262 = qcar(v_18261);
    goto v_18186;
v_18187:
    v_18261 = elt(env, 2); // minus
    goto v_18188;
v_18189:
    goto v_18185;
v_18186:
    goto v_18187;
v_18188:
    if (v_18262 == v_18261) goto v_18183;
    else goto v_18184;
v_18183:
    goto v_18198;
v_18194:
    v_18261 = stack[-1];
    v_18261 = qcdr(v_18261);
    v_18261 = qcar(v_18261);
    v_18262 = qcdr(v_18261);
    goto v_18195;
v_18196:
    v_18261 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18197;
v_18198:
    goto v_18194;
v_18195:
    goto v_18196;
v_18197:
    v_18261 = (LispObject)lessp2(v_18262, v_18261);
    v_18261 = v_18261 ? lisp_true : nil;
    env = stack[-3];
    goto v_18182;
v_18184:
    v_18261 = nil;
    goto v_18182;
    v_18261 = nil;
v_18182:
    if (v_18261 == nil) goto v_18180;
    goto v_18212;
v_18208:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_18209;
v_18210:
    v_18261 = stack[-1];
    v_18261 = qcdr(v_18261);
    v_18261 = qcar(v_18261);
    v_18261 = qcdr(v_18261);
    v_18261 = Labsval(nil, v_18261);
    goto v_18211;
v_18212:
    goto v_18208;
v_18209:
    goto v_18210;
v_18211:
    {
        LispObject v_18267 = stack[0];
        return cons(v_18267, v_18261);
    }
v_18180:
    goto v_18225;
v_18221:
    v_18261 = stack[-1];
    v_18262 = qcar(v_18261);
    goto v_18222;
v_18223:
    v_18261 = elt(env, 2); // minus
    goto v_18224;
v_18225:
    goto v_18221;
v_18222:
    goto v_18223;
v_18224:
    if (v_18262 == v_18261) goto v_18219;
    else goto v_18220;
v_18219:
    v_18261 = stack[-1];
    goto v_18080;
v_18220:
    goto v_18237;
v_18233:
    v_18261 = stack[-1];
    v_18262 = qcdr(v_18261);
    goto v_18234;
v_18235:
    v_18261 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18236;
v_18237:
    goto v_18233;
v_18234:
    goto v_18235;
v_18236:
    v_18261 = (LispObject)lessp2(v_18262, v_18261);
    v_18261 = v_18261 ? lisp_true : nil;
    env = stack[-3];
    if (v_18261 == nil) goto v_18231;
    goto v_18246;
v_18242:
    stack[-2] = elt(env, 2); // minus
    goto v_18243;
v_18244:
    goto v_18253;
v_18249:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_18250;
v_18251:
    v_18261 = stack[-1];
    v_18261 = qcdr(v_18261);
    v_18261 = Labsval(nil, v_18261);
    env = stack[-3];
    goto v_18252;
v_18253:
    goto v_18249;
v_18250:
    goto v_18251;
v_18252:
    v_18261 = cons(stack[0], v_18261);
    goto v_18245;
v_18246:
    goto v_18242;
v_18243:
    goto v_18244;
v_18245:
    {
        LispObject v_18268 = stack[-2];
        return list2(v_18268, v_18261);
    }
v_18231:
    v_18261 = stack[-1];
    goto v_18080;
    v_18261 = nil;
v_18080:
    return onevalue(v_18261);
}



// Code for insoccs

static LispObject CC_insoccs(LispObject env,
                         LispObject v_18077, LispObject v_18078)
{
    env = qenv(env);
    LispObject v_18149, v_18150;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18077,v_18078);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18078;
    stack[-1] = v_18077;
// end of prologue
    v_18149 = stack[-1];
    if (symbolp(v_18149)) goto v_18084;
    v_18149 = stack[-1];
    fn = elt(env, 1); // subscriptedvarp
    v_18149 = (*qfn1(fn))(fn, v_18149);
    env = stack[-2];
    if (v_18149 == nil) goto v_18089;
    else goto v_18084;
v_18089:
    v_18149 = stack[-1];
    v_18149 = Lconsp(nil, v_18149);
    env = stack[-2];
    if (v_18149 == nil) goto v_18092;
    v_18149 = stack[-1];
    v_18149 = qcar(v_18149);
    fn = elt(env, 1); // subscriptedvarp
    v_18149 = (*qfn1(fn))(fn, v_18149);
    env = stack[-2];
    if (v_18149 == nil) goto v_18092;
    goto v_18084;
v_18092:
    goto v_18085;
v_18084:
    goto v_18105;
v_18101:
    v_18150 = stack[0];
    goto v_18102;
v_18103:
    v_18149 = stack[-1];
    goto v_18104;
v_18105:
    goto v_18101;
v_18102:
    goto v_18103;
v_18104:
    fn = elt(env, 2); // insertocc
    v_18149 = (*qfn2(fn))(fn, v_18150, v_18149);
    env = stack[-2];
    stack[0] = v_18149;
    goto v_18083;
v_18085:
v_18083:
    v_18149 = stack[-1];
    if (symbolp(v_18149)) goto v_18115;
    v_18149 = stack[-1];
    fn = elt(env, 3); // constp
    v_18149 = (*qfn1(fn))(fn, v_18149);
    env = stack[-2];
    v_18149 = (v_18149 == nil ? lisp_true : nil);
    goto v_18113;
v_18115:
    v_18149 = nil;
    goto v_18113;
    v_18149 = nil;
v_18113:
    if (v_18149 == nil) goto v_18111;
    v_18149 = stack[-1];
    v_18149 = qcdr(v_18149);
    stack[-1] = v_18149;
v_18126:
    v_18149 = stack[-1];
    if (v_18149 == nil) goto v_18131;
    else goto v_18132;
v_18131:
    goto v_18125;
v_18132:
    v_18149 = stack[-1];
    v_18149 = qcar(v_18149);
    goto v_18143;
v_18139:
    v_18150 = v_18149;
    goto v_18140;
v_18141:
    v_18149 = stack[0];
    goto v_18142;
v_18143:
    goto v_18139;
v_18140:
    goto v_18141;
v_18142:
    v_18149 = CC_insoccs(elt(env, 0), v_18150, v_18149);
    env = stack[-2];
    stack[0] = v_18149;
    v_18149 = stack[-1];
    v_18149 = qcdr(v_18149);
    stack[-1] = v_18149;
    goto v_18126;
v_18125:
    goto v_18109;
v_18111:
v_18109:
    v_18149 = stack[0];
    return onevalue(v_18149);
}



// Code for overall_factor

static LispObject CC_overall_factor(LispObject env,
                         LispObject v_18077, LispObject v_18078)
{
    env = qenv(env);
    LispObject v_18113, v_18114;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18077,v_18078);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_18078;
    stack[-1] = v_18077;
// end of prologue
v_18076:
    v_18113 = stack[0];
    if (v_18113 == nil) goto v_18082;
    else goto v_18083;
v_18082:
    v_18113 = lisp_true;
    goto v_18081;
v_18083:
    goto v_18096;
v_18092:
    stack[-2] = stack[-1];
    goto v_18093;
v_18094:
    v_18113 = stack[0];
    fn = elt(env, 1); // xval
    v_18113 = (*qfn1(fn))(fn, v_18113);
    env = stack[-3];
    goto v_18095;
v_18096:
    goto v_18092;
v_18093:
    goto v_18094;
v_18095:
    v_18113 = Lmemq(nil, stack[-2], v_18113);
    if (v_18113 == nil) goto v_18090;
    else goto v_18091;
v_18090:
    v_18113 = nil;
    goto v_18089;
v_18091:
    goto v_18109;
v_18105:
    v_18114 = stack[-1];
    goto v_18106;
v_18107:
    v_18113 = stack[0];
    v_18113 = qcdr(v_18113);
    goto v_18108;
v_18109:
    goto v_18105;
v_18106:
    goto v_18107;
v_18108:
    stack[-1] = v_18114;
    stack[0] = v_18113;
    goto v_18076;
    v_18113 = nil;
v_18089:
    goto v_18081;
    v_18113 = nil;
v_18081:
    return onevalue(v_18113);
}



// Code for testchar1

static LispObject CC_testchar1(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18125, v_18126;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18077);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18077;
// end of prologue
    v_18125 = stack[0];
    v_18125 = integerp(v_18125);
    if (v_18125 == nil) goto v_18082;
    v_18125 = stack[0];
    goto v_18080;
v_18082:
    v_18125 = stack[0];
    v_18125 = Lexplodec(nil, v_18125);
    env = stack[-1];
    v_18125 = qcdr(v_18125);
    if (v_18125 == nil) goto v_18086;
    else goto v_18087;
v_18086:
    v_18125 = stack[0];
    goto v_18080;
v_18087:
    goto v_18098;
v_18094:
    v_18126 = stack[0];
    goto v_18095;
v_18096:
    v_18125 = qvalue(elt(env, 1)); // nochar!*
    goto v_18097;
v_18098:
    goto v_18094;
v_18095:
    goto v_18096;
v_18097:
    v_18125 = Lmember(nil, v_18126, v_18125);
    if (v_18125 == nil) goto v_18093;
    v_18125 = stack[0];
    goto v_18080;
v_18093:
    goto v_18109;
v_18105:
    v_18126 = stack[0];
    goto v_18106;
v_18107:
    v_18125 = qvalue(elt(env, 2)); // nochar1!*
    goto v_18108;
v_18109:
    goto v_18105;
v_18106:
    goto v_18107;
v_18108:
    v_18125 = Lmember(nil, v_18126, v_18125);
    if (v_18125 == nil) goto v_18104;
    v_18125 = stack[0];
    goto v_18080;
v_18104:
    goto v_18121;
v_18117:
    v_18126 = stack[0];
    goto v_18118;
v_18119:
    v_18125 = qvalue(elt(env, 2)); // nochar1!*
    goto v_18120;
v_18121:
    goto v_18117;
v_18118:
    goto v_18119;
v_18120:
    v_18125 = cons(v_18126, v_18125);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_18125; // nochar1!*
    v_18125 = stack[0];
    goto v_18080;
    v_18125 = nil;
v_18080:
    return onevalue(v_18125);
}



// Code for expand_rule

static LispObject CC_expand_rule(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18228, v_18229;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18077);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    v_18229 = v_18077;
// end of prologue
    goto v_18084;
v_18080:
    v_18228 = v_18229;
    stack[-9] = qcar(v_18228);
    goto v_18081;
v_18082:
    v_18228 = v_18229;
    v_18228 = qcdr(v_18228);
    stack[-8] = v_18228;
    v_18228 = stack[-8];
    if (v_18228 == nil) goto v_18097;
    else goto v_18098;
v_18097:
    v_18228 = nil;
    goto v_18091;
v_18098:
    v_18228 = stack[-8];
    v_18228 = qcar(v_18228);
    stack[-4] = v_18228;
    goto v_18110;
v_18106:
    v_18228 = stack[-4];
    v_18228 = qcar(v_18228);
    stack[-3] = v_18228;
    v_18228 = stack[-3];
    if (v_18228 == nil) goto v_18121;
    else goto v_18122;
v_18121:
    v_18228 = nil;
    v_18229 = v_18228;
    goto v_18115;
v_18122:
    v_18228 = stack[-3];
    v_18228 = qcar(v_18228);
    fn = elt(env, 1); // expand_terminal
    v_18228 = (*qfn1(fn))(fn, v_18228);
    env = stack[-10];
    v_18228 = ncons(v_18228);
    env = stack[-10];
    stack[-1] = v_18228;
    stack[-2] = v_18228;
v_18116:
    v_18228 = stack[-3];
    v_18228 = qcdr(v_18228);
    stack[-3] = v_18228;
    v_18228 = stack[-3];
    if (v_18228 == nil) goto v_18135;
    else goto v_18136;
v_18135:
    v_18228 = stack[-2];
    v_18229 = v_18228;
    goto v_18115;
v_18136:
    goto v_18144;
v_18140:
    stack[0] = stack[-1];
    goto v_18141;
v_18142:
    v_18228 = stack[-3];
    v_18228 = qcar(v_18228);
    fn = elt(env, 1); // expand_terminal
    v_18228 = (*qfn1(fn))(fn, v_18228);
    env = stack[-10];
    v_18228 = ncons(v_18228);
    env = stack[-10];
    goto v_18143;
v_18144:
    goto v_18140;
v_18141:
    goto v_18142;
v_18143:
    v_18228 = Lrplacd(nil, stack[0], v_18228);
    env = stack[-10];
    v_18228 = stack[-1];
    v_18228 = qcdr(v_18228);
    stack[-1] = v_18228;
    goto v_18116;
v_18115:
    goto v_18107;
v_18108:
    v_18228 = stack[-4];
    v_18228 = qcdr(v_18228);
    goto v_18109;
v_18110:
    goto v_18106;
v_18107:
    goto v_18108;
v_18109:
    v_18228 = cons(v_18229, v_18228);
    env = stack[-10];
    v_18228 = ncons(v_18228);
    env = stack[-10];
    stack[-6] = v_18228;
    stack[-7] = v_18228;
v_18092:
    v_18228 = stack[-8];
    v_18228 = qcdr(v_18228);
    stack[-8] = v_18228;
    v_18228 = stack[-8];
    if (v_18228 == nil) goto v_18160;
    else goto v_18161;
v_18160:
    v_18228 = stack[-7];
    goto v_18091;
v_18161:
    goto v_18169;
v_18165:
    stack[-5] = stack[-6];
    goto v_18166;
v_18167:
    v_18228 = stack[-8];
    v_18228 = qcar(v_18228);
    stack[-4] = v_18228;
    goto v_18180;
v_18176:
    v_18228 = stack[-4];
    v_18228 = qcar(v_18228);
    stack[-3] = v_18228;
    v_18228 = stack[-3];
    if (v_18228 == nil) goto v_18191;
    else goto v_18192;
v_18191:
    v_18228 = nil;
    v_18229 = v_18228;
    goto v_18185;
v_18192:
    v_18228 = stack[-3];
    v_18228 = qcar(v_18228);
    fn = elt(env, 1); // expand_terminal
    v_18228 = (*qfn1(fn))(fn, v_18228);
    env = stack[-10];
    v_18228 = ncons(v_18228);
    env = stack[-10];
    stack[-1] = v_18228;
    stack[-2] = v_18228;
v_18186:
    v_18228 = stack[-3];
    v_18228 = qcdr(v_18228);
    stack[-3] = v_18228;
    v_18228 = stack[-3];
    if (v_18228 == nil) goto v_18205;
    else goto v_18206;
v_18205:
    v_18228 = stack[-2];
    v_18229 = v_18228;
    goto v_18185;
v_18206:
    goto v_18214;
v_18210:
    stack[0] = stack[-1];
    goto v_18211;
v_18212:
    v_18228 = stack[-3];
    v_18228 = qcar(v_18228);
    fn = elt(env, 1); // expand_terminal
    v_18228 = (*qfn1(fn))(fn, v_18228);
    env = stack[-10];
    v_18228 = ncons(v_18228);
    env = stack[-10];
    goto v_18213;
v_18214:
    goto v_18210;
v_18211:
    goto v_18212;
v_18213:
    v_18228 = Lrplacd(nil, stack[0], v_18228);
    env = stack[-10];
    v_18228 = stack[-1];
    v_18228 = qcdr(v_18228);
    stack[-1] = v_18228;
    goto v_18186;
v_18185:
    goto v_18177;
v_18178:
    v_18228 = stack[-4];
    v_18228 = qcdr(v_18228);
    goto v_18179;
v_18180:
    goto v_18176;
v_18177:
    goto v_18178;
v_18179:
    v_18228 = cons(v_18229, v_18228);
    env = stack[-10];
    v_18228 = ncons(v_18228);
    env = stack[-10];
    goto v_18168;
v_18169:
    goto v_18165;
v_18166:
    goto v_18167;
v_18168:
    v_18228 = Lrplacd(nil, stack[-5], v_18228);
    env = stack[-10];
    v_18228 = stack[-6];
    v_18228 = qcdr(v_18228);
    stack[-6] = v_18228;
    goto v_18092;
v_18091:
    goto v_18083;
v_18084:
    goto v_18080;
v_18081:
    goto v_18082;
v_18083:
    {
        LispObject v_18240 = stack[-9];
        return cons(v_18240, v_18228);
    }
}



// Code for formboollis

static LispObject CC_formboollis(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18143, v_18144, v_18145;
    LispObject fn;
    LispObject v_18080, v_18079, v_18078, v_18077;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "formboollis");
    va_start(aa, nargs);
    v_18077 = va_arg(aa, LispObject);
    v_18078 = va_arg(aa, LispObject);
    v_18079 = va_arg(aa, LispObject);
    v_18080 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_18080,v_18079,v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_18077,v_18078,v_18079,v_18080);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_18080;
    stack[-1] = v_18079;
    stack[-2] = v_18078;
    stack[-3] = v_18077;
// end of prologue
    stack[-4] = nil;
v_18087:
    v_18143 = stack[-3];
    if (v_18143 == nil) goto v_18090;
    else goto v_18091;
v_18090:
    goto v_18086;
v_18091:
    v_18143 = stack[0];
    if (v_18143 == nil) goto v_18097;
    goto v_18104;
v_18100:
    goto v_18112;
v_18106:
    v_18143 = stack[-3];
    v_18145 = qcar(v_18143);
    goto v_18107;
v_18108:
    v_18144 = stack[-2];
    goto v_18109;
v_18110:
    v_18143 = stack[-1];
    goto v_18111;
v_18112:
    goto v_18106;
v_18107:
    goto v_18108;
v_18109:
    goto v_18110;
v_18111:
    fn = elt(env, 1); // formbool
    v_18144 = (*qfnn(fn))(fn, 3, v_18145, v_18144, v_18143);
    env = stack[-5];
    goto v_18101;
v_18102:
    v_18143 = stack[-4];
    goto v_18103;
v_18104:
    goto v_18100;
v_18101:
    goto v_18102;
v_18103:
    v_18143 = cons(v_18144, v_18143);
    env = stack[-5];
    stack[-4] = v_18143;
    goto v_18095;
v_18097:
    goto v_18125;
v_18121:
    goto v_18133;
v_18127:
    v_18143 = stack[-3];
    v_18145 = qcar(v_18143);
    goto v_18128;
v_18129:
    v_18144 = stack[-2];
    goto v_18130;
v_18131:
    v_18143 = stack[-1];
    goto v_18132;
v_18133:
    goto v_18127;
v_18128:
    goto v_18129;
v_18130:
    goto v_18131;
v_18132:
    fn = elt(env, 2); // formc!*
    v_18144 = (*qfnn(fn))(fn, 3, v_18145, v_18144, v_18143);
    env = stack[-5];
    goto v_18122;
v_18123:
    v_18143 = stack[-4];
    goto v_18124;
v_18125:
    goto v_18121;
v_18122:
    goto v_18123;
v_18124:
    v_18143 = cons(v_18144, v_18143);
    env = stack[-5];
    stack[-4] = v_18143;
    goto v_18095;
v_18095:
    v_18143 = stack[-3];
    v_18143 = qcdr(v_18143);
    stack[-3] = v_18143;
    goto v_18087;
v_18086:
    v_18143 = stack[-4];
    {
        fn = elt(env, 3); // reversip!*
        return (*qfn1(fn))(fn, v_18143);
    }
    return onevalue(v_18143);
}



// Code for pasf_dt

static LispObject CC_pasf_dt(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18448, v_18449, v_18450, v_18451;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18077);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18077;
// end of prologue
    goto v_18095;
v_18091:
    v_18449 = stack[0];
    goto v_18092;
v_18093:
    v_18448 = elt(env, 1); // true
    goto v_18094;
v_18095:
    goto v_18091;
v_18092:
    goto v_18093;
v_18094:
    if (v_18449 == v_18448) goto v_18089;
    else goto v_18090;
v_18089:
    v_18448 = lisp_true;
    goto v_18088;
v_18090:
    goto v_18105;
v_18101:
    v_18449 = stack[0];
    goto v_18102;
v_18103:
    v_18448 = elt(env, 2); // false
    goto v_18104;
v_18105:
    goto v_18101;
v_18102:
    goto v_18103;
v_18104:
    v_18448 = (v_18449 == v_18448 ? lisp_true : nil);
    goto v_18088;
    v_18448 = nil;
v_18088:
    if (v_18448 == nil) goto v_18086;
    v_18448 = stack[0];
    goto v_18082;
v_18086:
    v_18448 = stack[0];
    v_18448 = qcdr(v_18448);
    v_18448 = qcar(v_18448);
    fn = elt(env, 16); // pasf_pdp
    v_18448 = (*qfn1(fn))(fn, v_18448);
    env = stack[-1];
    v_18451 = v_18448;
    goto v_18126;
v_18122:
    v_18449 = stack[0];
    goto v_18123;
v_18124:
    v_18448 = elt(env, 1); // true
    goto v_18125;
v_18126:
    goto v_18122;
v_18123:
    goto v_18124;
v_18125:
    if (v_18449 == v_18448) goto v_18120;
    else goto v_18121;
v_18120:
    v_18448 = lisp_true;
    goto v_18119;
v_18121:
    goto v_18136;
v_18132:
    v_18449 = stack[0];
    goto v_18133;
v_18134:
    v_18448 = elt(env, 2); // false
    goto v_18135;
v_18136:
    goto v_18132;
v_18133:
    goto v_18134;
v_18135:
    v_18448 = (v_18449 == v_18448 ? lisp_true : nil);
    goto v_18119;
    v_18448 = nil;
v_18119:
    if (v_18448 == nil) goto v_18117;
    v_18448 = stack[0];
    goto v_18115;
v_18117:
    v_18448 = stack[0];
    v_18448 = qcar(v_18448);
    v_18448 = Lconsp(nil, v_18448);
    env = stack[-1];
    if (v_18448 == nil) goto v_18142;
    v_18448 = stack[0];
    v_18448 = qcar(v_18448);
    v_18448 = qcar(v_18448);
    goto v_18115;
v_18142:
    v_18448 = stack[0];
    v_18448 = qcar(v_18448);
    goto v_18115;
    v_18448 = nil;
v_18115:
    v_18450 = v_18448;
    goto v_18165;
v_18161:
    v_18449 = v_18451;
    goto v_18162;
v_18163:
    v_18448 = elt(env, 3); // pdef
    goto v_18164;
v_18165:
    goto v_18161;
v_18162:
    goto v_18163;
v_18164:
    if (v_18449 == v_18448) goto v_18159;
    else goto v_18160;
v_18159:
    goto v_18172;
v_18168:
    v_18449 = v_18450;
    goto v_18169;
v_18170:
    v_18448 = elt(env, 4); // (equal lessp leq)
    goto v_18171;
v_18172:
    goto v_18168;
v_18169:
    goto v_18170;
v_18171:
    v_18448 = Lmemq(nil, v_18449, v_18448);
    goto v_18158;
v_18160:
    v_18448 = nil;
    goto v_18158;
    v_18448 = nil;
v_18158:
    if (v_18448 == nil) goto v_18156;
    v_18448 = elt(env, 2); // false
    goto v_18082;
v_18156:
    goto v_18192;
v_18188:
    v_18449 = v_18451;
    goto v_18189;
v_18190:
    v_18448 = elt(env, 5); // ndef
    goto v_18191;
v_18192:
    goto v_18188;
v_18189:
    goto v_18190;
v_18191:
    if (v_18449 == v_18448) goto v_18186;
    else goto v_18187;
v_18186:
    goto v_18199;
v_18195:
    v_18449 = v_18450;
    goto v_18196;
v_18197:
    v_18448 = elt(env, 6); // (equal greaterp geq)
    goto v_18198;
v_18199:
    goto v_18195;
v_18196:
    goto v_18197;
v_18198:
    v_18448 = Lmemq(nil, v_18449, v_18448);
    goto v_18185;
v_18187:
    v_18448 = nil;
    goto v_18185;
    v_18448 = nil;
v_18185:
    if (v_18448 == nil) goto v_18183;
    v_18448 = elt(env, 2); // false
    goto v_18082;
v_18183:
    goto v_18219;
v_18215:
    v_18449 = v_18451;
    goto v_18216;
v_18217:
    v_18448 = elt(env, 3); // pdef
    goto v_18218;
v_18219:
    goto v_18215;
v_18216:
    goto v_18217;
v_18218:
    if (v_18449 == v_18448) goto v_18213;
    else goto v_18214;
v_18213:
    goto v_18226;
v_18222:
    v_18449 = v_18450;
    goto v_18223;
v_18224:
    v_18448 = elt(env, 7); // (neq greaterp geq)
    goto v_18225;
v_18226:
    goto v_18222;
v_18223:
    goto v_18224;
v_18225:
    v_18448 = Lmemq(nil, v_18449, v_18448);
    goto v_18212;
v_18214:
    v_18448 = nil;
    goto v_18212;
    v_18448 = nil;
v_18212:
    if (v_18448 == nil) goto v_18210;
    v_18448 = elt(env, 1); // true
    goto v_18082;
v_18210:
    goto v_18246;
v_18242:
    v_18449 = v_18451;
    goto v_18243;
v_18244:
    v_18448 = elt(env, 5); // ndef
    goto v_18245;
v_18246:
    goto v_18242;
v_18243:
    goto v_18244;
v_18245:
    if (v_18449 == v_18448) goto v_18240;
    else goto v_18241;
v_18240:
    goto v_18253;
v_18249:
    v_18449 = v_18450;
    goto v_18250;
v_18251:
    v_18448 = elt(env, 8); // (neq lessp leq)
    goto v_18252;
v_18253:
    goto v_18249;
v_18250:
    goto v_18251;
v_18252:
    v_18448 = Lmemq(nil, v_18449, v_18448);
    goto v_18239;
v_18241:
    v_18448 = nil;
    goto v_18239;
    v_18448 = nil;
v_18239:
    if (v_18448 == nil) goto v_18237;
    v_18448 = elt(env, 1); // true
    goto v_18082;
v_18237:
    goto v_18273;
v_18269:
    v_18449 = v_18451;
    goto v_18270;
v_18271:
    v_18448 = elt(env, 9); // psdef
    goto v_18272;
v_18273:
    goto v_18269;
v_18270:
    goto v_18271;
v_18272:
    if (v_18449 == v_18448) goto v_18267;
    else goto v_18268;
v_18267:
    goto v_18280;
v_18276:
    v_18449 = v_18450;
    goto v_18277;
v_18278:
    v_18448 = elt(env, 10); // lessp
    goto v_18279;
v_18280:
    goto v_18276;
v_18277:
    goto v_18278;
v_18279:
    v_18448 = (v_18449 == v_18448 ? lisp_true : nil);
    goto v_18266;
v_18268:
    v_18448 = nil;
    goto v_18266;
    v_18448 = nil;
v_18266:
    if (v_18448 == nil) goto v_18264;
    v_18448 = elt(env, 2); // false
    goto v_18082;
v_18264:
    goto v_18300;
v_18296:
    v_18449 = v_18451;
    goto v_18297;
v_18298:
    v_18448 = elt(env, 11); // nsdef
    goto v_18299;
v_18300:
    goto v_18296;
v_18297:
    goto v_18298;
v_18299:
    if (v_18449 == v_18448) goto v_18294;
    else goto v_18295;
v_18294:
    goto v_18307;
v_18303:
    v_18449 = v_18450;
    goto v_18304;
v_18305:
    v_18448 = elt(env, 12); // greaterp
    goto v_18306;
v_18307:
    goto v_18303;
v_18304:
    goto v_18305;
v_18306:
    v_18448 = (v_18449 == v_18448 ? lisp_true : nil);
    goto v_18293;
v_18295:
    v_18448 = nil;
    goto v_18293;
    v_18448 = nil;
v_18293:
    if (v_18448 == nil) goto v_18291;
    v_18448 = elt(env, 2); // false
    goto v_18082;
v_18291:
    goto v_18327;
v_18323:
    v_18449 = v_18451;
    goto v_18324;
v_18325:
    v_18448 = elt(env, 9); // psdef
    goto v_18326;
v_18327:
    goto v_18323;
v_18324:
    goto v_18325;
v_18326:
    if (v_18449 == v_18448) goto v_18321;
    else goto v_18322;
v_18321:
    goto v_18334;
v_18330:
    v_18449 = v_18450;
    goto v_18331;
v_18332:
    v_18448 = elt(env, 13); // geq
    goto v_18333;
v_18334:
    goto v_18330;
v_18331:
    goto v_18332;
v_18333:
    v_18448 = (v_18449 == v_18448 ? lisp_true : nil);
    goto v_18320;
v_18322:
    v_18448 = nil;
    goto v_18320;
    v_18448 = nil;
v_18320:
    if (v_18448 == nil) goto v_18318;
    v_18448 = elt(env, 1); // true
    goto v_18082;
v_18318:
    goto v_18354;
v_18350:
    v_18449 = v_18451;
    goto v_18351;
v_18352:
    v_18448 = elt(env, 11); // nsdef
    goto v_18353;
v_18354:
    goto v_18350;
v_18351:
    goto v_18352;
v_18353:
    if (v_18449 == v_18448) goto v_18348;
    else goto v_18349;
v_18348:
    goto v_18361;
v_18357:
    v_18449 = v_18450;
    goto v_18358;
v_18359:
    v_18448 = elt(env, 14); // leq
    goto v_18360;
v_18361:
    goto v_18357;
v_18358:
    goto v_18359;
v_18360:
    v_18448 = (v_18449 == v_18448 ? lisp_true : nil);
    goto v_18347;
v_18349:
    v_18448 = nil;
    goto v_18347;
    v_18448 = nil;
v_18347:
    if (v_18448 == nil) goto v_18345;
    v_18448 = elt(env, 1); // true
    goto v_18082;
v_18345:
    goto v_18381;
v_18377:
    v_18449 = v_18451;
    goto v_18378;
v_18379:
    v_18448 = elt(env, 9); // psdef
    goto v_18380;
v_18381:
    goto v_18377;
v_18378:
    goto v_18379;
v_18380:
    if (v_18449 == v_18448) goto v_18375;
    else goto v_18376;
v_18375:
    goto v_18388;
v_18384:
    v_18449 = v_18450;
    goto v_18385;
v_18386:
    v_18448 = elt(env, 15); // neq
    goto v_18387;
v_18388:
    goto v_18384;
v_18385:
    goto v_18386;
v_18387:
    v_18448 = (v_18449 == v_18448 ? lisp_true : nil);
    goto v_18374;
v_18376:
    v_18448 = nil;
    goto v_18374;
    v_18448 = nil;
v_18374:
    if (v_18448 == nil) goto v_18372;
    goto v_18402;
v_18396:
    v_18450 = elt(env, 12); // greaterp
    goto v_18397;
v_18398:
    v_18448 = stack[0];
    v_18448 = qcdr(v_18448);
    v_18449 = qcar(v_18448);
    goto v_18399;
v_18400:
    v_18448 = nil;
    goto v_18401;
v_18402:
    goto v_18396;
v_18397:
    goto v_18398;
v_18399:
    goto v_18400;
v_18401:
    return list3(v_18450, v_18449, v_18448);
v_18372:
    goto v_18420;
v_18416:
    v_18449 = v_18451;
    goto v_18417;
v_18418:
    v_18448 = elt(env, 11); // nsdef
    goto v_18419;
v_18420:
    goto v_18416;
v_18417:
    goto v_18418;
v_18419:
    if (v_18449 == v_18448) goto v_18414;
    else goto v_18415;
v_18414:
    goto v_18427;
v_18423:
    v_18449 = v_18450;
    goto v_18424;
v_18425:
    v_18448 = elt(env, 15); // neq
    goto v_18426;
v_18427:
    goto v_18423;
v_18424:
    goto v_18425;
v_18426:
    v_18448 = (v_18449 == v_18448 ? lisp_true : nil);
    goto v_18413;
v_18415:
    v_18448 = nil;
    goto v_18413;
    v_18448 = nil;
v_18413:
    if (v_18448 == nil) goto v_18411;
    goto v_18441;
v_18435:
    v_18450 = elt(env, 10); // lessp
    goto v_18436;
v_18437:
    v_18448 = stack[0];
    v_18448 = qcdr(v_18448);
    v_18449 = qcar(v_18448);
    goto v_18438;
v_18439:
    v_18448 = nil;
    goto v_18440;
v_18441:
    goto v_18435;
v_18436:
    goto v_18437;
v_18438:
    goto v_18439;
v_18440:
    return list3(v_18450, v_18449, v_18448);
v_18411:
    v_18448 = stack[0];
v_18082:
    return onevalue(v_18448);
}



// Code for ev_revgradlexcomp

static LispObject CC_ev_revgradlexcomp(LispObject env,
                         LispObject v_18077, LispObject v_18078)
{
    env = qenv(env);
    LispObject v_18151, v_18152;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18077,v_18078);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_18078;
    stack[-2] = v_18077;
// end of prologue
v_18076:
    v_18151 = stack[-2];
    if (v_18151 == nil) goto v_18086;
    else goto v_18087;
v_18086:
    v_18151 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18083;
v_18087:
    goto v_18099;
v_18095:
    v_18151 = stack[-2];
    v_18152 = qcar(v_18151);
    goto v_18096;
v_18097:
    v_18151 = stack[-1];
    v_18151 = qcar(v_18151);
    goto v_18098;
v_18099:
    goto v_18095;
v_18096:
    goto v_18097;
v_18098:
    fn = elt(env, 1); // iequal
    v_18151 = (*qfn2(fn))(fn, v_18152, v_18151);
    env = stack[-4];
    if (v_18151 == nil) goto v_18093;
    goto v_18109;
v_18105:
    v_18151 = stack[-2];
    v_18152 = qcdr(v_18151);
    goto v_18106;
v_18107:
    v_18151 = stack[-1];
    v_18151 = qcdr(v_18151);
    goto v_18108;
v_18109:
    goto v_18105;
v_18106:
    goto v_18107;
v_18108:
    stack[-2] = v_18152;
    stack[-1] = v_18151;
    goto v_18076;
v_18093:
    v_18151 = stack[-2];
    fn = elt(env, 2); // ev_tdeg
    v_18151 = (*qfn1(fn))(fn, v_18151);
    env = stack[-4];
    stack[-3] = v_18151;
    v_18151 = stack[-1];
    fn = elt(env, 2); // ev_tdeg
    v_18151 = (*qfn1(fn))(fn, v_18151);
    env = stack[-4];
    stack[0] = v_18151;
    goto v_18127;
v_18123:
    v_18152 = stack[-3];
    goto v_18124;
v_18125:
    v_18151 = stack[0];
    goto v_18126;
v_18127:
    goto v_18123;
v_18124:
    goto v_18125;
v_18126:
    fn = elt(env, 1); // iequal
    v_18151 = (*qfn2(fn))(fn, v_18152, v_18151);
    env = stack[-4];
    if (v_18151 == nil) goto v_18121;
    goto v_18135;
v_18131:
    v_18152 = stack[-2];
    goto v_18132;
v_18133:
    v_18151 = stack[-1];
    goto v_18134;
v_18135:
    goto v_18131;
v_18132:
    goto v_18133;
v_18134:
    {
        fn = elt(env, 3); // ev_invlexcomp
        return (*qfn2(fn))(fn, v_18152, v_18151);
    }
v_18121:
    goto v_18146;
v_18142:
    v_18152 = stack[-3];
    goto v_18143;
v_18144:
    v_18151 = stack[0];
    goto v_18145;
v_18146:
    goto v_18142;
v_18143:
    goto v_18144;
v_18145:
    if (((intptr_t)(v_18152)) > ((intptr_t)(v_18151))) goto v_18140;
    else goto v_18141;
v_18140:
    v_18151 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18083;
v_18141:
    v_18151 = (LispObject)-16+TAG_FIXNUM; // -1
v_18083:
    return onevalue(v_18151);
}



// Code for minusml

static LispObject CC_minusml(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18092;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18077);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18077;
// end of prologue
    v_18092 = elt(env, 1); // "<apply><minus/>"
    fn = elt(env, 3); // printout
    v_18092 = (*qfn1(fn))(fn, v_18092);
    env = stack[-1];
    v_18092 = lisp_true;
    fn = elt(env, 4); // indent!*
    v_18092 = (*qfn1(fn))(fn, v_18092);
    env = stack[-1];
    v_18092 = stack[0];
    v_18092 = qcdr(v_18092);
    fn = elt(env, 5); // multiminus
    v_18092 = (*qfn1(fn))(fn, v_18092);
    env = stack[-1];
    v_18092 = nil;
    fn = elt(env, 4); // indent!*
    v_18092 = (*qfn1(fn))(fn, v_18092);
    env = stack[-1];
    v_18092 = elt(env, 2); // "</apply>"
    fn = elt(env, 3); // printout
    v_18092 = (*qfn1(fn))(fn, v_18092);
    v_18092 = nil;
    return onevalue(v_18092);
}



// Code for f2dip11

static LispObject CC_f2dip11(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18130, v_18131;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18077);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18077;
// end of prologue
v_18076:
    v_18130 = qvalue(elt(env, 1)); // !*notestparameters
    if (v_18130 == nil) goto v_18081;
    else goto v_18080;
v_18081:
    goto v_18091;
v_18087:
    v_18131 = stack[0];
    goto v_18088;
v_18089:
    v_18130 = qvalue(elt(env, 2)); // vdpvars!*
    goto v_18090;
v_18091:
    goto v_18087;
v_18088:
    goto v_18089;
v_18090:
    v_18130 = Lmember(nil, v_18131, v_18130);
    if (v_18130 == nil) goto v_18086;
    goto v_18101;
v_18097:
    v_18131 = stack[0];
    goto v_18098;
v_18099:
    v_18130 = elt(env, 3); // "occurs in a parameter and is member of the groebner variables."
    goto v_18100;
v_18101:
    goto v_18097;
v_18098:
    goto v_18099;
v_18100:
    v_18130 = list2(v_18131, v_18130);
    env = stack[-1];
    fn = elt(env, 6); // rederr
    v_18130 = (*qfn1(fn))(fn, v_18130);
    env = stack[-1];
    goto v_18084;
v_18086:
v_18084:
    v_18130 = stack[0];
    if (!consp(v_18130)) goto v_18106;
    else goto v_18107;
v_18106:
    goto v_18117;
v_18113:
    v_18131 = stack[0];
    goto v_18114;
v_18115:
    v_18130 = elt(env, 4); // list
    goto v_18116;
v_18117:
    goto v_18113;
v_18114:
    goto v_18115;
v_18116:
    if (v_18131 == v_18130) goto v_18111;
    else goto v_18112;
v_18111:
    v_18130 = elt(env, 5); // "groebner: LIST not allowed."
    {
        fn = elt(env, 6); // rederr
        return (*qfn1(fn))(fn, v_18130);
    }
v_18112:
    v_18130 = nil;
    goto v_18105;
v_18107:
    v_18130 = stack[0];
    v_18130 = qcar(v_18130);
    v_18130 = CC_f2dip11(elt(env, 0), v_18130);
    env = stack[-1];
    v_18130 = stack[0];
    v_18130 = qcdr(v_18130);
    stack[0] = v_18130;
    goto v_18076;
    v_18130 = nil;
v_18105:
v_18080:
    return onevalue(v_18130);
}



// Code for xriterion_1

static LispObject CC_xriterion_1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18258, v_18259, v_18260;
    LispObject fn;
    LispObject v_18079, v_18078, v_18077;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xriterion_1");
    va_start(aa, nargs);
    v_18077 = va_arg(aa, LispObject);
    v_18078 = va_arg(aa, LispObject);
    v_18079 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18079,v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18077,v_18078,v_18079);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_18079;
    stack[-1] = v_18078;
    stack[-2] = v_18077;
// end of prologue
v_18076:
    v_18258 = stack[-1];
    if (v_18258 == nil) goto v_18083;
    else goto v_18084;
v_18083:
    v_18258 = nil;
    goto v_18082;
v_18084:
    goto v_18093;
v_18089:
    v_18258 = stack[-2];
    v_18258 = qcdr(v_18258);
    v_18259 = qcar(v_18258);
    goto v_18090;
v_18091:
    v_18258 = elt(env, 1); // spoly_pair
    goto v_18092;
v_18093:
    goto v_18089;
v_18090:
    goto v_18091;
v_18092:
    if (v_18259 == v_18258) goto v_18088;
    v_18258 = nil;
    goto v_18082;
v_18088:
    v_18258 = stack[-1];
    v_18258 = qcar(v_18258);
    stack[-3] = v_18258;
    goto v_18115;
v_18111:
    v_18259 = stack[-3];
    goto v_18112;
v_18113:
    v_18258 = stack[-2];
    v_18258 = qcdr(v_18258);
    v_18258 = qcdr(v_18258);
    v_18258 = qcar(v_18258);
    goto v_18114;
v_18115:
    goto v_18111;
v_18112:
    goto v_18113;
v_18114:
    if (equal(v_18259, v_18258)) goto v_18110;
    goto v_18129;
v_18125:
    v_18259 = stack[-3];
    goto v_18126;
v_18127:
    v_18258 = stack[-2];
    v_18258 = qcdr(v_18258);
    v_18258 = qcdr(v_18258);
    v_18258 = qcdr(v_18258);
    v_18258 = qcar(v_18258);
    goto v_18128;
v_18129:
    goto v_18125;
v_18126:
    goto v_18127;
v_18128:
    if (equal(v_18259, v_18258)) goto v_18124;
    goto v_18145;
v_18141:
    v_18258 = stack[-3];
    fn = elt(env, 5); // xval
    v_18259 = (*qfn1(fn))(fn, v_18258);
    env = stack[-4];
    goto v_18142;
v_18143:
    v_18258 = stack[-2];
    v_18258 = qcar(v_18258);
    goto v_18144;
v_18145:
    goto v_18141;
v_18142:
    goto v_18143;
v_18144:
    fn = elt(env, 6); // xdiv
    v_18258 = (*qfn2(fn))(fn, v_18259, v_18258);
    env = stack[-4];
    if (v_18258 == nil) goto v_18138;
    else goto v_18139;
v_18138:
    v_18258 = nil;
    goto v_18137;
v_18139:
    goto v_18162;
v_18158:
    v_18259 = stack[-3];
    goto v_18159;
v_18160:
    v_18258 = stack[-2];
    v_18258 = qcdr(v_18258);
    v_18258 = qcdr(v_18258);
    v_18258 = qcar(v_18258);
    goto v_18161;
v_18162:
    goto v_18158;
v_18159:
    goto v_18160;
v_18161:
    fn = elt(env, 7); // make_spoly_pair
    v_18258 = (*qfn2(fn))(fn, v_18259, v_18258);
    env = stack[-4];
    v_18259 = v_18258;
    v_18258 = v_18259;
    if (v_18258 == nil) goto v_18171;
    else goto v_18172;
v_18171:
    v_18258 = lisp_true;
    goto v_18170;
v_18172:
    goto v_18182;
v_18178:
    goto v_18179;
v_18180:
    v_18258 = stack[0];
    goto v_18181;
v_18182:
    goto v_18178;
v_18179:
    goto v_18180;
v_18181:
    fn = elt(env, 8); // find_item
    v_18258 = (*qfn2(fn))(fn, v_18259, v_18258);
    env = stack[-4];
    v_18258 = (v_18258 == nil ? lisp_true : nil);
    goto v_18170;
    v_18258 = nil;
v_18170:
    if (v_18258 == nil) goto v_18155;
    else goto v_18156;
v_18155:
    v_18258 = nil;
    goto v_18154;
v_18156:
    goto v_18198;
v_18194:
    v_18259 = stack[-3];
    goto v_18195;
v_18196:
    v_18258 = stack[-2];
    v_18258 = qcdr(v_18258);
    v_18258 = qcdr(v_18258);
    v_18258 = qcdr(v_18258);
    v_18258 = qcar(v_18258);
    goto v_18197;
v_18198:
    goto v_18194;
v_18195:
    goto v_18196;
v_18197:
    fn = elt(env, 7); // make_spoly_pair
    v_18258 = (*qfn2(fn))(fn, v_18259, v_18258);
    env = stack[-4];
    v_18259 = v_18258;
    v_18258 = v_18259;
    if (v_18258 == nil) goto v_18208;
    else goto v_18209;
v_18208:
    v_18258 = lisp_true;
    goto v_18207;
v_18209:
    goto v_18219;
v_18215:
    goto v_18216;
v_18217:
    v_18258 = stack[0];
    goto v_18218;
v_18219:
    goto v_18215;
v_18216:
    goto v_18217;
v_18218:
    fn = elt(env, 8); // find_item
    v_18258 = (*qfn2(fn))(fn, v_18259, v_18258);
    env = stack[-4];
    v_18258 = (v_18258 == nil ? lisp_true : nil);
    goto v_18207;
    v_18258 = nil;
v_18207:
    if (v_18258 == nil) goto v_18191;
    else goto v_18192;
v_18191:
    v_18258 = nil;
    goto v_18190;
v_18192:
    v_18258 = qvalue(elt(env, 2)); // !*trxideal
    if (v_18258 == nil) goto v_18229;
    goto v_18236;
v_18232:
    v_18259 = elt(env, 3); // "criterion 1 hit"
    goto v_18233;
v_18234:
    v_18258 = elt(env, 4); // last
    goto v_18235;
v_18236:
    goto v_18232;
v_18233:
    goto v_18234;
v_18235:
    fn = elt(env, 9); // writepri
    v_18258 = (*qfn2(fn))(fn, v_18259, v_18258);
    env = stack[-4];
    goto v_18227;
v_18229:
v_18227:
    v_18258 = lisp_true;
    goto v_18190;
    v_18258 = nil;
v_18190:
    goto v_18154;
    v_18258 = nil;
v_18154:
    goto v_18137;
    v_18258 = nil;
v_18137:
    goto v_18122;
v_18124:
    v_18258 = nil;
    goto v_18122;
    v_18258 = nil;
v_18122:
    goto v_18108;
v_18110:
    v_18258 = nil;
    goto v_18108;
    v_18258 = nil;
v_18108:
    if (v_18258 == nil) goto v_18106;
    else goto v_18105;
v_18106:
    goto v_18253;
v_18247:
    v_18260 = stack[-2];
    goto v_18248;
v_18249:
    v_18258 = stack[-1];
    v_18259 = qcdr(v_18258);
    goto v_18250;
v_18251:
    v_18258 = stack[0];
    goto v_18252;
v_18253:
    goto v_18247;
v_18248:
    goto v_18249;
v_18250:
    goto v_18251;
v_18252:
    stack[-2] = v_18260;
    stack[-1] = v_18259;
    stack[0] = v_18258;
    goto v_18076;
v_18105:
    goto v_18082;
    v_18258 = nil;
v_18082:
    return onevalue(v_18258);
}



// Code for eqexpr

static LispObject CC_eqexpr(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18118, v_18119, v_18120;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18077);
    }
// copy arguments values to proper place
    v_18120 = v_18077;
// end of prologue
    v_18118 = v_18120;
    if (!consp(v_18118)) goto v_18082;
    goto v_18093;
v_18089:
    v_18118 = v_18120;
    v_18119 = qcar(v_18118);
    goto v_18090;
v_18091:
    v_18118 = elt(env, 1); // equalopr
    goto v_18092;
v_18093:
    goto v_18089;
v_18090:
    goto v_18091;
v_18092:
    v_18118 = Lflagp(nil, v_18119, v_18118);
    if (v_18118 == nil) goto v_18087;
    v_18118 = v_18120;
    v_18118 = qcdr(v_18118);
    v_18118 = qcdr(v_18118);
    if (v_18118 == nil) goto v_18099;
    else goto v_18100;
v_18099:
    v_18118 = nil;
    goto v_18098;
v_18100:
    v_18118 = v_18120;
    v_18118 = qcdr(v_18118);
    v_18118 = qcdr(v_18118);
    v_18118 = qcdr(v_18118);
    v_18118 = (v_18118 == nil ? lisp_true : nil);
    goto v_18098;
    v_18118 = nil;
v_18098:
    goto v_18085;
v_18087:
    v_18118 = nil;
    goto v_18085;
    v_18118 = nil;
v_18085:
    goto v_18080;
v_18082:
    v_18118 = nil;
    goto v_18080;
    v_18118 = nil;
v_18080:
    return onevalue(v_18118);
}



// Code for comb

static LispObject CC_comb(LispObject env,
                         LispObject v_18077, LispObject v_18078)
{
    env = qenv(env);
    LispObject v_18187, v_18188, v_18189;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18077,v_18078);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_18078;
    stack[-4] = v_18077;
// end of prologue
    stack[-5] = nil;
    goto v_18094;
v_18090:
    v_18188 = stack[-3];
    goto v_18091;
v_18092:
    v_18187 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18093;
v_18094:
    goto v_18090;
v_18091:
    goto v_18092;
v_18093:
    if (v_18188 == v_18187) goto v_18088;
    else goto v_18089;
v_18088:
    v_18187 = nil;
    return ncons(v_18187);
v_18089:
    goto v_18106;
v_18102:
    goto v_18112;
v_18108:
    v_18187 = stack[-4];
    v_18188 = Llength(nil, v_18187);
    env = stack[-6];
    goto v_18109;
v_18110:
    v_18187 = stack[-3];
    goto v_18111;
v_18112:
    goto v_18108;
v_18109:
    goto v_18110;
v_18111:
    v_18188 = difference2(v_18188, v_18187);
    env = stack[-6];
    stack[-2] = v_18188;
    goto v_18103;
v_18104:
    v_18187 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18105;
v_18106:
    goto v_18102;
v_18103:
    goto v_18104;
v_18105:
    v_18187 = (LispObject)lessp2(v_18188, v_18187);
    v_18187 = v_18187 ? lisp_true : nil;
    env = stack[-6];
    if (v_18187 == nil) goto v_18100;
    v_18187 = nil;
    goto v_18084;
v_18100:
    v_18187 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_18187;
v_18121:
    goto v_18133;
v_18129:
    v_18188 = stack[-2];
    goto v_18130;
v_18131:
    v_18187 = stack[-1];
    goto v_18132;
v_18133:
    goto v_18129;
v_18130:
    goto v_18131;
v_18132:
    v_18187 = difference2(v_18188, v_18187);
    env = stack[-6];
    v_18187 = Lminusp(nil, v_18187);
    env = stack[-6];
    if (v_18187 == nil) goto v_18126;
    goto v_18120;
v_18126:
    goto v_18142;
v_18138:
    v_18187 = stack[-4];
    stack[0] = qcdr(v_18187);
    goto v_18139;
v_18140:
    v_18187 = stack[-3];
    v_18187 = sub1(v_18187);
    env = stack[-6];
    goto v_18141;
v_18142:
    goto v_18138;
v_18139:
    goto v_18140;
v_18141:
    v_18187 = CC_comb(elt(env, 0), stack[0], v_18187);
    env = stack[-6];
    stack[0] = v_18187;
v_18150:
    v_18187 = stack[0];
    if (v_18187 == nil) goto v_18154;
    else goto v_18155;
v_18154:
    goto v_18149;
v_18155:
    v_18187 = stack[0];
    v_18187 = qcar(v_18187);
    goto v_18168;
v_18162:
    v_18188 = stack[-4];
    v_18189 = qcar(v_18188);
    goto v_18163;
v_18164:
    v_18188 = v_18187;
    goto v_18165;
v_18166:
    v_18187 = stack[-5];
    goto v_18167;
v_18168:
    goto v_18162;
v_18163:
    goto v_18164;
v_18165:
    goto v_18166;
v_18167:
    v_18187 = acons(v_18189, v_18188, v_18187);
    env = stack[-6];
    stack[-5] = v_18187;
    v_18187 = stack[0];
    v_18187 = qcdr(v_18187);
    stack[0] = v_18187;
    goto v_18150;
v_18149:
    v_18187 = stack[-4];
    v_18187 = qcdr(v_18187);
    stack[-4] = v_18187;
    v_18187 = stack[-1];
    v_18187 = add1(v_18187);
    env = stack[-6];
    stack[-1] = v_18187;
    goto v_18121;
v_18120:
    goto v_18184;
v_18180:
    v_18188 = stack[-4];
    goto v_18181;
v_18182:
    v_18187 = stack[-5];
    goto v_18183;
v_18184:
    goto v_18180;
v_18181:
    goto v_18182;
v_18183:
    return cons(v_18188, v_18187);
v_18084:
    return onevalue(v_18187);
}



// Code for max!-degree

static LispObject CC_maxKdegree(LispObject env,
                         LispObject v_18077, LispObject v_18078)
{
    env = qenv(env);
    LispObject v_18143, v_18144, v_18145, v_18146;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18077,v_18078);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_18144 = v_18078;
    v_18145 = v_18077;
// end of prologue
v_18083:
    v_18143 = v_18145;
    if (!consp(v_18143)) goto v_18090;
    else goto v_18091;
v_18090:
    v_18143 = lisp_true;
    goto v_18089;
v_18091:
    v_18143 = v_18145;
    v_18143 = qcar(v_18143);
    v_18143 = (consp(v_18143) ? nil : lisp_true);
    goto v_18089;
    v_18143 = nil;
v_18089:
    if (v_18143 == nil) goto v_18087;
    v_18143 = v_18144;
    goto v_18082;
v_18087:
    goto v_18106;
v_18102:
    v_18146 = v_18144;
    goto v_18103;
v_18104:
    v_18143 = v_18145;
    v_18143 = qcar(v_18143);
    v_18143 = qcar(v_18143);
    v_18143 = qcdr(v_18143);
    goto v_18105;
v_18106:
    goto v_18102;
v_18103:
    goto v_18104;
v_18105:
    if (((intptr_t)(v_18146)) > ((intptr_t)(v_18143))) goto v_18100;
    else goto v_18101;
v_18100:
    v_18143 = v_18145;
    v_18143 = qcdr(v_18143);
    stack[0] = v_18143;
    goto v_18119;
v_18115:
    v_18143 = v_18145;
    v_18143 = qcar(v_18143);
    v_18143 = qcdr(v_18143);
    goto v_18116;
v_18117:
    goto v_18118;
v_18119:
    goto v_18115;
v_18116:
    goto v_18117;
v_18118:
    v_18143 = CC_maxKdegree(elt(env, 0), v_18143, v_18144);
    env = stack[-1];
    v_18144 = v_18143;
    v_18143 = stack[0];
    v_18145 = v_18143;
    goto v_18083;
v_18101:
    v_18143 = v_18145;
    v_18143 = qcdr(v_18143);
    stack[0] = v_18143;
    goto v_18134;
v_18130:
    v_18143 = v_18145;
    v_18143 = qcar(v_18143);
    v_18143 = qcdr(v_18143);
    goto v_18131;
v_18132:
    v_18144 = v_18145;
    v_18144 = qcar(v_18144);
    v_18144 = qcar(v_18144);
    v_18144 = qcdr(v_18144);
    goto v_18133;
v_18134:
    goto v_18130;
v_18131:
    goto v_18132;
v_18133:
    v_18143 = CC_maxKdegree(elt(env, 0), v_18143, v_18144);
    env = stack[-1];
    v_18144 = v_18143;
    v_18143 = stack[0];
    v_18145 = v_18143;
    goto v_18083;
    v_18143 = nil;
v_18082:
    return onevalue(v_18143);
}



// Code for chkrn!*

static LispObject CC_chkrnH(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18089, v_18090;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18090 = v_18077;
// end of prologue
    v_18089 = qvalue(elt(env, 1)); // !*!*roundbf
    if (v_18089 == nil) goto v_18082;
    v_18089 = v_18090;
    goto v_18080;
v_18082:
    v_18089 = v_18090;
    {
        fn = elt(env, 2); // bf2flck
        return (*qfn1(fn))(fn, v_18089);
    }
    v_18089 = nil;
v_18080:
    return onevalue(v_18089);
}



// Code for length_multiindex

static LispObject CC_length_multiindex(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18105, v_18106;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18077);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_18105 = v_18077;
// end of prologue
    stack[0] = v_18105;
    v_18105 = (LispObject)0+TAG_FIXNUM; // 0
    v_18106 = v_18105;
v_18083:
    v_18105 = stack[0];
    if (v_18105 == nil) goto v_18088;
    else goto v_18089;
v_18088:
    v_18105 = v_18106;
    goto v_18082;
v_18089:
    goto v_18097;
v_18093:
    v_18105 = stack[0];
    v_18105 = qcar(v_18105);
    goto v_18094;
v_18095:
    goto v_18096;
v_18097:
    goto v_18093;
v_18094:
    goto v_18095;
v_18096:
    v_18105 = plus2(v_18105, v_18106);
    env = stack[-1];
    v_18106 = v_18105;
    v_18105 = stack[0];
    v_18105 = qcdr(v_18105);
    stack[0] = v_18105;
    goto v_18083;
v_18082:
    return onevalue(v_18105);
}



// Code for ofsf_facequal!*

static LispObject CC_ofsf_facequalH(LispObject env,
                         LispObject v_18077, LispObject v_18078)
{
    env = qenv(env);
    LispObject v_18115, v_18116, v_18117;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18116 = v_18078;
    v_18117 = v_18077;
// end of prologue
    v_18115 = qvalue(elt(env, 1)); // !*rlsifac
    if (v_18115 == nil) goto v_18083;
    v_18115 = qvalue(elt(env, 2)); // !*rlsiexpla
    if (v_18115 == nil) goto v_18087;
    else goto v_18086;
v_18087:
    v_18115 = qvalue(elt(env, 3)); // !*rlsiexpl
    if (v_18115 == nil) goto v_18089;
    goto v_18097;
v_18093:
    goto v_18094;
v_18095:
    v_18115 = elt(env, 4); // or
    goto v_18096;
v_18097:
    goto v_18093;
v_18094:
    goto v_18095;
v_18096:
    if (v_18116 == v_18115) goto v_18092;
    else goto v_18089;
v_18092:
    goto v_18086;
v_18089:
    goto v_18083;
v_18086:
    v_18115 = v_18117;
    {
        fn = elt(env, 6); // ofsf_facequal
        return (*qfn1(fn))(fn, v_18115);
    }
v_18083:
    goto v_18111;
v_18105:
    v_18116 = elt(env, 5); // equal
    goto v_18106;
v_18107:
    goto v_18108;
v_18109:
    v_18115 = nil;
    goto v_18110;
v_18111:
    goto v_18105;
v_18106:
    goto v_18107;
v_18108:
    goto v_18109;
v_18110:
    return list3(v_18116, v_18117, v_18115);
    v_18115 = nil;
    return onevalue(v_18115);
}



// Code for talp_noffcts

static LispObject CC_talp_noffcts(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18114, v_18115;
    LispObject fn;
    argcheck(nargs, 0, "talp_noffcts");
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
    v_18114 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_18114;
    fn = elt(env, 1); // talp_getl
    v_18114 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[0] = v_18114;
v_18085:
    v_18114 = stack[0];
    if (v_18114 == nil) goto v_18089;
    else goto v_18090;
v_18089:
    goto v_18084;
v_18090:
    v_18114 = stack[0];
    v_18114 = qcar(v_18114);
    goto v_18105;
v_18101:
    v_18115 = qcdr(v_18114);
    goto v_18102;
v_18103:
    v_18114 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18104;
v_18105:
    goto v_18101;
v_18102:
    goto v_18103;
v_18104:
    v_18114 = (LispObject)greaterp2(v_18115, v_18114);
    v_18114 = v_18114 ? lisp_true : nil;
    env = stack[-2];
    if (v_18114 == nil) goto v_18099;
    v_18114 = stack[-1];
    v_18114 = add1(v_18114);
    env = stack[-2];
    stack[-1] = v_18114;
    goto v_18097;
v_18099:
v_18097:
    v_18114 = stack[0];
    v_18114 = qcdr(v_18114);
    stack[0] = v_18114;
    goto v_18085;
v_18084:
    v_18114 = stack[-1];
    return onevalue(v_18114);
}



// Code for pasf_susibinad

static LispObject CC_pasf_susibinad(LispObject env,
                         LispObject v_18077, LispObject v_18078)
{
    env = qenv(env);
    LispObject v_18359, v_18360, v_18361, v_18362, v_18363, v_18364, v_18365;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18077,v_18078);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_18078;
    stack[-4] = v_18077;
// end of prologue
    goto v_18093;
v_18089:
    v_18359 = stack[-4];
    v_18360 = qcdr(v_18359);
    goto v_18090;
v_18091:
    v_18359 = stack[-3];
    v_18359 = qcdr(v_18359);
    goto v_18092;
v_18093:
    goto v_18089;
v_18090:
    goto v_18091;
v_18092:
    fn = elt(env, 5); // cl_susiminlevel
    v_18359 = (*qfn2(fn))(fn, v_18360, v_18359);
    env = stack[-6];
    stack[-1] = v_18359;
    v_18359 = stack[-4];
    v_18359 = qcar(v_18359);
    stack[-4] = v_18359;
    v_18359 = stack[-3];
    v_18359 = qcar(v_18359);
    stack[-3] = v_18359;
    goto v_18112;
v_18108:
    v_18360 = stack[-3];
    goto v_18109;
v_18110:
    v_18359 = elt(env, 1); // false
    goto v_18111;
v_18112:
    goto v_18108;
v_18109:
    goto v_18110;
v_18111:
    if (v_18360 == v_18359) goto v_18106;
    else goto v_18107;
v_18106:
    v_18359 = elt(env, 1); // false
    goto v_18087;
v_18107:
    goto v_18124;
v_18120:
    v_18360 = stack[-3];
    goto v_18121;
v_18122:
    v_18359 = elt(env, 2); // true
    goto v_18123;
v_18124:
    goto v_18120;
v_18121:
    goto v_18122;
v_18123:
    if (v_18360 == v_18359) goto v_18118;
    else goto v_18119;
v_18118:
    v_18359 = elt(env, 3); // (delete . t)
    return ncons(v_18359);
v_18119:
    goto v_18137;
v_18133:
    v_18359 = stack[-4];
    v_18359 = qcdr(v_18359);
    v_18360 = qcar(v_18359);
    goto v_18134;
v_18135:
    v_18359 = stack[-3];
    v_18359 = qcdr(v_18359);
    v_18359 = qcar(v_18359);
    goto v_18136;
v_18137:
    goto v_18133;
v_18134:
    goto v_18135;
v_18136:
    if (equal(v_18360, v_18359)) goto v_18131;
    else goto v_18132;
v_18131:
    goto v_18153;
v_18145:
    v_18359 = stack[-4];
    v_18359 = qcdr(v_18359);
    v_18362 = qcar(v_18359);
    goto v_18146;
v_18147:
    v_18359 = stack[-4];
    v_18361 = qcar(v_18359);
    goto v_18148;
v_18149:
    v_18359 = stack[-3];
    v_18360 = qcar(v_18359);
    goto v_18150;
v_18151:
    v_18359 = stack[-1];
    goto v_18152;
v_18153:
    goto v_18145;
v_18146:
    goto v_18147;
v_18148:
    goto v_18149;
v_18150:
    goto v_18151;
v_18152:
    {
        fn = elt(env, 6); // pasf_susibineq
        return (*qfnn(fn))(fn, 4, v_18362, v_18361, v_18360, v_18359);
    }
v_18132:
    v_18359 = stack[-4];
    v_18359 = qcdr(v_18359);
    v_18359 = qcar(v_18359);
    fn = elt(env, 7); // pasf_dec
    v_18359 = (*qfn1(fn))(fn, v_18359);
    env = stack[-6];
    stack[-5] = v_18359;
    v_18359 = stack[-3];
    v_18359 = qcdr(v_18359);
    v_18359 = qcar(v_18359);
    fn = elt(env, 7); // pasf_dec
    v_18359 = (*qfn1(fn))(fn, v_18359);
    env = stack[-6];
    stack[-2] = v_18359;
    goto v_18178;
v_18174:
    v_18359 = stack[-5];
    v_18360 = qcar(v_18359);
    goto v_18175;
v_18176:
    v_18359 = stack[-2];
    v_18359 = qcar(v_18359);
    goto v_18177;
v_18178:
    goto v_18174;
v_18175:
    goto v_18176;
v_18177:
    if (equal(v_18360, v_18359)) goto v_18172;
    else goto v_18173;
v_18172:
    goto v_18198;
v_18184:
    v_18359 = stack[-4];
    v_18365 = qcar(v_18359);
    goto v_18185;
v_18186:
    v_18359 = stack[-5];
    v_18364 = qcar(v_18359);
    goto v_18187;
v_18188:
    v_18359 = stack[-5];
    v_18359 = qcdr(v_18359);
    if (v_18359 == nil) goto v_18206;
    v_18359 = stack[-5];
    v_18359 = qcdr(v_18359);
    v_18363 = v_18359;
    goto v_18204;
v_18206:
    v_18359 = (LispObject)0+TAG_FIXNUM; // 0
    v_18363 = v_18359;
    goto v_18204;
    v_18363 = nil;
v_18204:
    goto v_18189;
v_18190:
    v_18359 = stack[-3];
    v_18362 = qcar(v_18359);
    goto v_18191;
v_18192:
    v_18359 = stack[-2];
    v_18361 = qcar(v_18359);
    goto v_18193;
v_18194:
    v_18359 = stack[-2];
    v_18359 = qcdr(v_18359);
    if (v_18359 == nil) goto v_18221;
    v_18359 = stack[-2];
    v_18359 = qcdr(v_18359);
    v_18360 = v_18359;
    goto v_18219;
v_18221:
    v_18359 = (LispObject)0+TAG_FIXNUM; // 0
    v_18360 = v_18359;
    goto v_18219;
    v_18360 = nil;
v_18219:
    goto v_18195;
v_18196:
    v_18359 = stack[-1];
    goto v_18197;
v_18198:
    goto v_18184;
v_18185:
    goto v_18186;
v_18187:
    goto v_18188;
v_18189:
    goto v_18190;
v_18191:
    goto v_18192;
v_18193:
    goto v_18194;
v_18195:
    goto v_18196;
v_18197:
    {
        fn = elt(env, 8); // pasf_susibinord
        return (*qfnn(fn))(fn, 7, v_18365, v_18364, v_18363, v_18362, v_18361, v_18360, v_18359);
    }
v_18173:
    v_18359 = stack[-5];
    v_18359 = qcar(v_18359);
    fn = elt(env, 9); // kernels
    v_18359 = (*qfn1(fn))(fn, v_18359);
    env = stack[-6];
    stack[0] = v_18359;
    v_18359 = stack[-2];
    v_18359 = qcar(v_18359);
    fn = elt(env, 9); // kernels
    v_18359 = (*qfn1(fn))(fn, v_18359);
    env = stack[-6];
    v_18361 = v_18359;
    goto v_18248;
v_18244:
    v_18359 = stack[-4];
    v_18360 = qcar(v_18359);
    goto v_18245;
v_18246:
    v_18359 = elt(env, 4); // equal
    goto v_18247;
v_18248:
    goto v_18244;
v_18245:
    goto v_18246;
v_18247:
    if (v_18360 == v_18359) goto v_18242;
    else goto v_18243;
v_18242:
    v_18359 = stack[0];
    v_18359 = qcdr(v_18359);
    if (v_18359 == nil) goto v_18254;
    else goto v_18255;
v_18254:
    goto v_18262;
v_18258:
    v_18359 = stack[0];
    v_18360 = qcar(v_18359);
    goto v_18259;
v_18260:
    v_18359 = v_18361;
    goto v_18261;
v_18262:
    goto v_18258;
v_18259:
    goto v_18260;
v_18261:
    v_18359 = Lmemq(nil, v_18360, v_18359);
    goto v_18253;
v_18255:
    v_18359 = nil;
    goto v_18253;
    v_18359 = nil;
v_18253:
    goto v_18241;
v_18243:
    v_18359 = nil;
    goto v_18241;
    v_18359 = nil;
v_18241:
    if (v_18359 == nil) goto v_18239;
    goto v_18280;
v_18274:
    goto v_18288;
v_18282:
    stack[-2] = stack[-3];
    goto v_18283;
v_18284:
    v_18359 = stack[0];
    stack[0] = qcar(v_18359);
    goto v_18285;
v_18286:
    v_18359 = stack[-5];
    v_18359 = qcdr(v_18359);
    fn = elt(env, 10); // negf
    v_18359 = (*qfn1(fn))(fn, v_18359);
    env = stack[-6];
    goto v_18287;
v_18288:
    goto v_18282;
v_18283:
    goto v_18284;
v_18285:
    goto v_18286;
v_18287:
    fn = elt(env, 11); // pasf_subfof1
    v_18361 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_18359);
    env = stack[-6];
    goto v_18275;
v_18276:
    v_18360 = stack[-1];
    goto v_18277;
v_18278:
    v_18359 = lisp_true;
    goto v_18279;
v_18280:
    goto v_18274;
v_18275:
    goto v_18276;
v_18277:
    goto v_18278;
v_18279:
    {
        fn = elt(env, 12); // pasf_susibinad1
        return (*qfnn(fn))(fn, 3, v_18361, v_18360, v_18359);
    }
v_18239:
    goto v_18309;
v_18305:
    v_18359 = stack[-3];
    v_18360 = qcar(v_18359);
    goto v_18306;
v_18307:
    v_18359 = elt(env, 4); // equal
    goto v_18308;
v_18309:
    goto v_18305;
v_18306:
    goto v_18307;
v_18308:
    if (v_18360 == v_18359) goto v_18303;
    else goto v_18304;
v_18303:
    v_18359 = v_18361;
    v_18359 = qcdr(v_18359);
    if (v_18359 == nil) goto v_18315;
    else goto v_18316;
v_18315:
    goto v_18323;
v_18319:
    v_18359 = v_18361;
    v_18360 = qcar(v_18359);
    goto v_18320;
v_18321:
    v_18359 = stack[0];
    goto v_18322;
v_18323:
    goto v_18319;
v_18320:
    goto v_18321;
v_18322:
    v_18359 = Lmemq(nil, v_18360, v_18359);
    goto v_18314;
v_18316:
    v_18359 = nil;
    goto v_18314;
    v_18359 = nil;
v_18314:
    goto v_18302;
v_18304:
    v_18359 = nil;
    goto v_18302;
    v_18359 = nil;
v_18302:
    if (v_18359 == nil) goto v_18300;
    goto v_18341;
v_18335:
    goto v_18349;
v_18343:
    stack[-3] = stack[-4];
    goto v_18344;
v_18345:
    v_18359 = v_18361;
    stack[0] = qcar(v_18359);
    goto v_18346;
v_18347:
    v_18359 = stack[-2];
    v_18359 = qcdr(v_18359);
    fn = elt(env, 10); // negf
    v_18359 = (*qfn1(fn))(fn, v_18359);
    env = stack[-6];
    goto v_18348;
v_18349:
    goto v_18343;
v_18344:
    goto v_18345;
v_18346:
    goto v_18347;
v_18348:
    fn = elt(env, 11); // pasf_subfof1
    v_18361 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_18359);
    env = stack[-6];
    goto v_18336;
v_18337:
    v_18360 = stack[-1];
    goto v_18338;
v_18339:
    v_18359 = nil;
    goto v_18340;
v_18341:
    goto v_18335;
v_18336:
    goto v_18337;
v_18338:
    goto v_18339;
v_18340:
    {
        fn = elt(env, 12); // pasf_susibinad1
        return (*qfnn(fn))(fn, 3, v_18361, v_18360, v_18359);
    }
v_18300:
    v_18359 = nil;
v_18087:
    return onevalue(v_18359);
}



// Code for ev_sum

static LispObject CC_ev_sum(LispObject env,
                         LispObject v_18077, LispObject v_18078)
{
    env = qenv(env);
    LispObject v_18115, v_18116, v_18117;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18077,v_18078);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18078;
    stack[-1] = v_18077;
// end of prologue
    v_18117 = nil;
v_18085:
    v_18115 = stack[-1];
    if (v_18115 == nil) goto v_18088;
    else goto v_18089;
v_18088:
    goto v_18084;
v_18089:
    goto v_18097;
v_18093:
    goto v_18102;
v_18098:
    v_18115 = stack[-1];
    v_18116 = qcar(v_18115);
    goto v_18099;
v_18100:
    v_18115 = stack[0];
    v_18115 = qcar(v_18115);
    goto v_18101;
v_18102:
    goto v_18098;
v_18099:
    goto v_18100;
v_18101:
    v_18115 = (LispObject)(intptr_t)((intptr_t)v_18116 + (intptr_t)v_18115 - TAG_FIXNUM);
    goto v_18094;
v_18095:
    v_18116 = v_18117;
    goto v_18096;
v_18097:
    goto v_18093;
v_18094:
    goto v_18095;
v_18096:
    v_18115 = cons(v_18115, v_18116);
    env = stack[-2];
    v_18117 = v_18115;
    v_18115 = stack[-1];
    v_18115 = qcdr(v_18115);
    stack[-1] = v_18115;
    v_18115 = stack[0];
    v_18115 = qcdr(v_18115);
    stack[0] = v_18115;
    goto v_18085;
v_18084:
    v_18115 = v_18117;
        return Lnreverse(nil, v_18115);
    return onevalue(v_18115);
}



// Code for multiminus

static LispObject CC_multiminus(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18100, v_18101;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18077);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18077;
// end of prologue
    v_18100 = stack[0];
    v_18100 = qcar(v_18100);
    fn = elt(env, 1); // expression
    v_18100 = (*qfn1(fn))(fn, v_18100);
    env = stack[-1];
    goto v_18092;
v_18088:
    v_18100 = stack[0];
    v_18101 = Llength(nil, v_18100);
    env = stack[-1];
    goto v_18089;
v_18090:
    v_18100 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_18091;
v_18092:
    goto v_18088;
v_18089:
    goto v_18090;
v_18091:
    if (v_18101 == v_18100) goto v_18086;
    else goto v_18087;
v_18086:
    v_18100 = stack[0];
    v_18100 = qcdr(v_18100);
    v_18100 = qcar(v_18100);
    fn = elt(env, 1); // expression
    v_18100 = (*qfn1(fn))(fn, v_18100);
    goto v_18085;
v_18087:
v_18085:
    v_18100 = nil;
    return onevalue(v_18100);
}



// Code for dm!-min

static LispObject CC_dmKmin(LispObject env,
                         LispObject v_18077, LispObject v_18078)
{
    env = qenv(env);
    LispObject v_18096, v_18097;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18077,v_18078);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18078;
    stack[-1] = v_18077;
// end of prologue
    goto v_18089;
v_18085:
    v_18097 = stack[-1];
    goto v_18086;
v_18087:
    v_18096 = stack[0];
    goto v_18088;
v_18089:
    goto v_18085;
v_18086:
    goto v_18087;
v_18088:
    fn = elt(env, 1); // dm!-gt
    v_18096 = (*qfn2(fn))(fn, v_18097, v_18096);
    if (v_18096 == nil) goto v_18083;
    v_18096 = stack[0];
    goto v_18081;
v_18083:
    v_18096 = stack[-1];
    goto v_18081;
    v_18096 = nil;
v_18081:
    return onevalue(v_18096);
}



// Code for !:dmtimeslst

static LispObject CC_Tdmtimeslst(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18104, v_18105;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18077);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_18105 = v_18077;
// end of prologue
    v_18104 = v_18105;
    if (v_18104 == nil) goto v_18081;
    else goto v_18082;
v_18081:
    v_18104 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18080;
v_18082:
    v_18104 = v_18105;
    v_18104 = qcdr(v_18104);
    if (v_18104 == nil) goto v_18085;
    else goto v_18086;
v_18085:
    v_18104 = v_18105;
    v_18104 = qcar(v_18104);
    goto v_18080;
v_18086:
    goto v_18098;
v_18094:
    v_18104 = v_18105;
    stack[0] = qcar(v_18104);
    goto v_18095;
v_18096:
    v_18104 = v_18105;
    v_18104 = qcdr(v_18104);
    v_18104 = CC_Tdmtimeslst(elt(env, 0), v_18104);
    env = stack[-1];
    goto v_18097;
v_18098:
    goto v_18094;
v_18095:
    goto v_18096;
v_18097:
    {
        LispObject v_18107 = stack[0];
        fn = elt(env, 1); // !:times
        return (*qfn2(fn))(fn, v_18107, v_18104);
    }
    v_18104 = nil;
v_18080:
    return onevalue(v_18104);
}



// Code for sign!-of

static LispObject CC_signKof(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18093, v_18094;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18077);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18093 = v_18077;
// end of prologue
    v_18093 = ncons(v_18093);
    env = stack[0];
    fn = elt(env, 1); // simp!-sign
    v_18093 = (*qfn1(fn))(fn, v_18093);
    v_18093 = qcar(v_18093);
    v_18094 = v_18093;
    v_18093 = v_18094;
    if (is_number(v_18093)) goto v_18087;
    v_18093 = nil;
    goto v_18085;
v_18087:
    v_18093 = v_18094;
    goto v_18085;
    v_18093 = nil;
v_18085:
    return onevalue(v_18093);
}



// Code for log_assignment

static LispObject CC_log_assignment(LispObject env,
                         LispObject v_18077, LispObject v_18078)
{
    env = qenv(env);
    LispObject v_18194, v_18195, v_18196;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18077,v_18078);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18078;
    v_18195 = v_18077;
// end of prologue
v_18082:
    v_18194 = stack[0];
    if (!consp(v_18194)) goto v_18089;
    else goto v_18090;
v_18089:
    v_18194 = lisp_true;
    goto v_18088;
v_18090:
    goto v_18104;
v_18100:
    v_18196 = stack[0];
    goto v_18101;
v_18102:
    v_18194 = elt(env, 1); // quote
    goto v_18103;
v_18104:
    goto v_18100;
v_18101:
    goto v_18102;
v_18103:
    if (!consp(v_18196)) goto v_18098;
    v_18196 = qcar(v_18196);
    if (v_18196 == v_18194) goto v_18097;
    else goto v_18098;
v_18097:
    v_18194 = lisp_true;
    goto v_18096;
v_18098:
    goto v_18115;
v_18111:
    v_18196 = stack[0];
    goto v_18112;
v_18113:
    v_18194 = elt(env, 2); // function
    goto v_18114;
v_18115:
    goto v_18111;
v_18112:
    goto v_18113;
v_18114:
    v_18194 = Leqcar(nil, v_18196, v_18194);
    env = stack[-1];
    goto v_18096;
    v_18194 = nil;
v_18096:
    goto v_18088;
    v_18194 = nil;
v_18088:
    if (v_18194 == nil) goto v_18086;
    v_18194 = nil;
    goto v_18081;
v_18086:
    goto v_18126;
v_18122:
    v_18196 = stack[0];
    goto v_18123;
v_18124:
    v_18194 = elt(env, 3); // setq
    goto v_18125;
v_18126:
    goto v_18122;
v_18123:
    goto v_18124;
v_18125:
    if (!consp(v_18196)) goto v_18120;
    v_18196 = qcar(v_18196);
    if (v_18196 == v_18194) goto v_18119;
    else goto v_18120;
v_18119:
    goto v_18137;
v_18133:
    v_18194 = stack[0];
    v_18194 = qcdr(v_18194);
    v_18196 = qcar(v_18194);
    goto v_18134;
v_18135:
    v_18194 = v_18195;
    goto v_18136;
v_18137:
    goto v_18133;
v_18134:
    goto v_18135;
v_18136:
    v_18194 = Lmember(nil, v_18196, v_18194);
    if (v_18194 == nil) goto v_18132;
    v_18194 = Lposn(nil, 0);
    env = stack[-1];
    v_18194 = (LispObject)zerop(v_18194);
    v_18194 = v_18194 ? lisp_true : nil;
    env = stack[-1];
    if (v_18194 == nil) goto v_18145;
    else goto v_18146;
v_18145:
    v_18194 = Lterpri(nil, 0);
    env = stack[-1];
    goto v_18144;
v_18146:
v_18144:
    v_18194 = elt(env, 4); // "+++ Assignment to parameter of inline: "
    v_18194 = Lprinc(nil, v_18194);
    env = stack[-1];
    v_18194 = stack[0];
    v_18194 = Lprint(nil, v_18194);
    env = stack[-1];
    v_18194 = elt(env, 5); // "+++ Macro was: "
    v_18194 = Lprinc(nil, v_18194);
    env = stack[-1];
    v_18194 = qvalue(elt(env, 6)); // inlineinfo
    v_18194 = Lprint(nil, v_18194);
    v_18194 = lisp_true;
    goto v_18081;
v_18132:
    v_18194 = stack[0];
    v_18194 = qcdr(v_18194);
    v_18194 = qcdr(v_18194);
    v_18194 = qcar(v_18194);
    stack[0] = v_18194;
    goto v_18082;
    goto v_18084;
v_18120:
    goto v_18172;
v_18168:
    v_18196 = stack[0];
    goto v_18169;
v_18170:
    v_18194 = elt(env, 7); // cond
    goto v_18171;
v_18172:
    goto v_18168;
v_18169:
    goto v_18170;
v_18171:
    if (!consp(v_18196)) goto v_18166;
    v_18196 = qcar(v_18196);
    if (v_18196 == v_18194) goto v_18165;
    else goto v_18166;
v_18165:
    goto v_18180;
v_18176:
    goto v_18177;
v_18178:
    v_18194 = stack[0];
    v_18194 = qcdr(v_18194);
    goto v_18179;
v_18180:
    goto v_18176;
v_18177:
    goto v_18178;
v_18179:
    {
        fn = elt(env, 8); // log_assignment_list_list
        return (*qfn2(fn))(fn, v_18195, v_18194);
    }
v_18166:
    goto v_18191;
v_18187:
    goto v_18188;
v_18189:
    v_18194 = stack[0];
    goto v_18190;
v_18191:
    goto v_18187;
v_18188:
    goto v_18189;
v_18190:
    {
        fn = elt(env, 9); // log_assignment_list
        return (*qfn2(fn))(fn, v_18195, v_18194);
    }
v_18084:
    v_18194 = nil;
v_18081:
    return onevalue(v_18194);
}



// Code for arglength

static LispObject CC_arglength(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18103, v_18104;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18077);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_18104 = v_18077;
// end of prologue
// Binding !*intstr
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = nil; // !*intstr
    v_18103 = v_18104;
    if (v_18103 == nil) goto v_18085;
    else goto v_18086;
v_18085:
    v_18103 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18082;
v_18086:
    v_18103 = lisp_true;
    qvalue(elt(env, 1)) = v_18103; // !*intstr
    v_18103 = v_18104;
    fn = elt(env, 2); // reval
    v_18103 = (*qfn1(fn))(fn, v_18103);
    env = stack[-1];
    v_18104 = v_18103;
    v_18103 = v_18104;
    if (!consp(v_18103)) goto v_18094;
    else goto v_18095;
v_18094:
    v_18103 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_18093;
v_18095:
    v_18103 = v_18104;
    v_18103 = qcdr(v_18103);
    v_18103 = Llength(nil, v_18103);
    goto v_18093;
    v_18103 = nil;
v_18093:
v_18082:
    ;}  // end of a binding scope
    return onevalue(v_18103);
}



// Code for !*di2q

static LispObject CC_Hdi2q(LispObject env,
                         LispObject v_18078, LispObject v_18079)
{
    env = qenv(env);
    LispObject v_18156, v_18157, v_18158;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18079,v_18078);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18078,v_18079);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_18156 = v_18079;
    v_18157 = v_18078;
// end of prologue
// Binding varlist!*
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = v_18156; // varlist!*
    goto v_18090;
v_18086:
    v_18156 = v_18157;
    stack[-3] = v_18156;
    v_18156 = stack[-3];
    if (v_18156 == nil) goto v_18100;
    else goto v_18101;
v_18100:
    v_18156 = nil;
    v_18157 = v_18156;
    goto v_18095;
v_18101:
    v_18156 = stack[-3];
    v_18156 = qcar(v_18156);
    goto v_18115;
v_18109:
    v_18157 = v_18156;
    v_18158 = qcar(v_18157);
    goto v_18110;
v_18111:
    v_18157 = qcdr(v_18156);
    goto v_18112;
v_18113:
    v_18156 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18114;
v_18115:
    goto v_18109;
v_18110:
    goto v_18111;
v_18112:
    goto v_18113;
v_18114:
    v_18156 = list2star(v_18158, v_18157, v_18156);
    env = stack[-5];
    v_18156 = ncons(v_18156);
    env = stack[-5];
    stack[-1] = v_18156;
    stack[-2] = v_18156;
v_18096:
    v_18156 = stack[-3];
    v_18156 = qcdr(v_18156);
    stack[-3] = v_18156;
    v_18156 = stack[-3];
    if (v_18156 == nil) goto v_18125;
    else goto v_18126;
v_18125:
    v_18156 = stack[-2];
    v_18157 = v_18156;
    goto v_18095;
v_18126:
    goto v_18134;
v_18130:
    stack[0] = stack[-1];
    goto v_18131;
v_18132:
    v_18156 = stack[-3];
    v_18156 = qcar(v_18156);
    goto v_18147;
v_18141:
    v_18157 = v_18156;
    v_18158 = qcar(v_18157);
    goto v_18142;
v_18143:
    v_18157 = qcdr(v_18156);
    goto v_18144;
v_18145:
    v_18156 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18146;
v_18147:
    goto v_18141;
v_18142:
    goto v_18143;
v_18144:
    goto v_18145;
v_18146:
    v_18156 = list2star(v_18158, v_18157, v_18156);
    env = stack[-5];
    v_18156 = ncons(v_18156);
    env = stack[-5];
    goto v_18133;
v_18134:
    goto v_18130;
v_18131:
    goto v_18132;
v_18133:
    v_18156 = Lrplacd(nil, stack[0], v_18156);
    env = stack[-5];
    v_18156 = stack[-1];
    v_18156 = qcdr(v_18156);
    stack[-1] = v_18156;
    goto v_18096;
v_18095:
    goto v_18087;
v_18088:
    v_18156 = qvalue(elt(env, 1)); // varlist!*
    goto v_18089;
v_18090:
    goto v_18086;
v_18087:
    goto v_18088;
v_18089:
    fn = elt(env, 2); // !*di2q0
    v_18156 = (*qfn2(fn))(fn, v_18157, v_18156);
    ;}  // end of a binding scope
    return onevalue(v_18156);
}



// Code for ra_l

static LispObject CC_ra_l(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18082;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18077);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18082 = v_18077;
// end of prologue
    fn = elt(env, 1); // ra_iv
    v_18082 = (*qfn1(fn))(fn, v_18082);
    env = stack[0];
    {
        fn = elt(env, 2); // riv_l
        return (*qfn1(fn))(fn, v_18082);
    }
}



// Code for lalr_extract_nonterminals

static LispObject CC_lalr_extract_nonterminals(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18227, v_18228, v_18229;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18077);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_18077;
// end of prologue
    v_18229 = nil;
v_18082:
    v_18227 = stack[-1];
    if (v_18227 == nil) goto v_18085;
    else goto v_18086;
v_18085:
    v_18227 = v_18229;
    {
        fn = elt(env, 7); // nreverse
        return (*qfn1(fn))(fn, v_18227);
    }
v_18086:
    v_18227 = stack[-1];
    if (!consp(v_18227)) goto v_18090;
    else goto v_18091;
v_18090:
    goto v_18098;
v_18094:
    stack[0] = v_18229;
    goto v_18095;
v_18096:
    goto v_18108;
v_18102:
    v_18229 = elt(env, 1); // "Malformed production"
    goto v_18103;
v_18104:
    v_18228 = stack[-1];
    goto v_18105;
v_18106:
    v_18227 = elt(env, 2); // "(RHS should be a list of tokens, not a non-nil atom)"
    goto v_18107;
v_18108:
    goto v_18102;
v_18103:
    goto v_18104;
v_18105:
    goto v_18106;
v_18107:
    v_18227 = list3(v_18229, v_18228, v_18227);
    env = stack[-3];
    fn = elt(env, 8); // rederr
    v_18227 = (*qfn1(fn))(fn, v_18227);
    env = stack[-3];
    goto v_18097;
v_18098:
    goto v_18094;
v_18095:
    goto v_18096;
v_18097:
    {
        LispObject v_18233 = stack[0];
        fn = elt(env, 7); // nreverse
        return (*qfn2(fn))(fn, v_18233, v_18227);
    }
v_18091:
    v_18227 = stack[-1];
    v_18227 = qcar(v_18227);
    v_18227 = Lstringp(nil, v_18227);
    env = stack[-3];
    if (v_18227 == nil) goto v_18113;
    v_18227 = stack[-1];
    v_18227 = qcdr(v_18227);
    stack[-1] = v_18227;
    goto v_18082;
v_18113:
    v_18227 = stack[-1];
    v_18227 = qcar(v_18227);
    if (symbolp(v_18227)) goto v_18119;
    else goto v_18120;
v_18119:
    goto v_18132;
v_18128:
    v_18227 = stack[-1];
    v_18228 = qcar(v_18227);
    goto v_18129;
v_18130:
    v_18227 = elt(env, 3); // lex_fixed_code
    goto v_18131;
v_18132:
    goto v_18128;
v_18129:
    goto v_18130;
v_18131:
    v_18227 = get(v_18228, v_18227);
    env = stack[-3];
    if (v_18227 == nil) goto v_18126;
    v_18227 = stack[-1];
    v_18227 = qcdr(v_18227);
    stack[-1] = v_18227;
    goto v_18082;
v_18126:
    goto v_18145;
v_18141:
    v_18227 = stack[-1];
    v_18227 = qcar(v_18227);
    goto v_18142;
v_18143:
    v_18228 = v_18229;
    goto v_18144;
v_18145:
    goto v_18141;
v_18142:
    goto v_18143;
v_18144:
    v_18227 = cons(v_18227, v_18228);
    env = stack[-3];
    v_18229 = v_18227;
    v_18227 = stack[-1];
    v_18227 = qcdr(v_18227);
    stack[-1] = v_18227;
    goto v_18082;
    goto v_18084;
v_18120:
    v_18227 = stack[-1];
    v_18227 = qcar(v_18227);
    if (!consp(v_18227)) goto v_18151;
    else goto v_18152;
v_18151:
    goto v_18160;
v_18156:
    stack[0] = v_18229;
    goto v_18157;
v_18158:
    goto v_18170;
v_18164:
    v_18229 = elt(env, 1); // "Malformed production"
    goto v_18165;
v_18166:
    v_18228 = stack[-1];
    goto v_18167;
v_18168:
    v_18227 = elt(env, 4); // "(atomic item in token list should be symbol or string)"
    goto v_18169;
v_18170:
    goto v_18164;
v_18165:
    goto v_18166;
v_18167:
    goto v_18168;
v_18169:
    v_18227 = list3(v_18229, v_18228, v_18227);
    env = stack[-3];
    fn = elt(env, 8); // rederr
    v_18227 = (*qfn1(fn))(fn, v_18227);
    env = stack[-3];
    goto v_18159;
v_18160:
    goto v_18156;
v_18157:
    goto v_18158;
v_18159:
    {
        LispObject v_18234 = stack[0];
        fn = elt(env, 7); // nreverse
        return (*qfn2(fn))(fn, v_18234, v_18227);
    }
v_18152:
    goto v_18180;
v_18176:
    v_18227 = stack[-1];
    v_18227 = qcar(v_18227);
    v_18228 = qcar(v_18227);
    goto v_18177;
v_18178:
    v_18227 = elt(env, 5); // (opt seq star plus list listplus or)
    goto v_18179;
v_18180:
    goto v_18176;
v_18177:
    goto v_18178;
v_18179:
    v_18227 = Lmemq(nil, v_18228, v_18227);
    if (v_18227 == nil) goto v_18175;
    goto v_18191;
v_18187:
    stack[-2] = v_18229;
    goto v_18188;
v_18189:
    goto v_18198;
v_18194:
    v_18227 = stack[-1];
    v_18227 = qcar(v_18227);
    v_18227 = qcdr(v_18227);
    stack[0] = CC_lalr_extract_nonterminals(elt(env, 0), v_18227);
    env = stack[-3];
    goto v_18195;
v_18196:
    v_18227 = stack[-1];
    v_18227 = qcdr(v_18227);
    v_18227 = CC_lalr_extract_nonterminals(elt(env, 0), v_18227);
    env = stack[-3];
    goto v_18197;
v_18198:
    goto v_18194;
v_18195:
    goto v_18196;
v_18197:
    v_18227 = Lappend(nil, stack[0], v_18227);
    env = stack[-3];
    goto v_18190;
v_18191:
    goto v_18187;
v_18188:
    goto v_18189;
v_18190:
    {
        LispObject v_18235 = stack[-2];
        fn = elt(env, 7); // nreverse
        return (*qfn2(fn))(fn, v_18235, v_18227);
    }
v_18175:
    goto v_18213;
v_18209:
    stack[0] = v_18229;
    goto v_18210;
v_18211:
    goto v_18223;
v_18217:
    v_18229 = elt(env, 1); // "Malformed production"
    goto v_18218;
v_18219:
    v_18228 = stack[-1];
    goto v_18220;
v_18221:
    v_18227 = elt(env, 6); // "(unrecognised item in rule)"
    goto v_18222;
v_18223:
    goto v_18217;
v_18218:
    goto v_18219;
v_18220:
    goto v_18221;
v_18222:
    v_18227 = list3(v_18229, v_18228, v_18227);
    env = stack[-3];
    fn = elt(env, 8); // rederr
    v_18227 = (*qfn1(fn))(fn, v_18227);
    env = stack[-3];
    goto v_18212;
v_18213:
    goto v_18209;
v_18210:
    goto v_18211;
v_18212:
    {
        LispObject v_18236 = stack[0];
        fn = elt(env, 7); // nreverse
        return (*qfn2(fn))(fn, v_18236, v_18227);
    }
v_18084:
    v_18227 = nil;
    return onevalue(v_18227);
}



// Code for talp_atnum

static LispObject CC_talp_atnum(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18263, v_18264, v_18265, v_18266;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18077);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_18265 = v_18077;
// end of prologue
v_18076:
    v_18263 = v_18265;
    if (!consp(v_18263)) goto v_18084;
    else goto v_18085;
v_18084:
    v_18263 = v_18265;
    goto v_18083;
v_18085:
    v_18263 = v_18265;
    v_18263 = qcar(v_18263);
    goto v_18083;
    v_18263 = nil;
v_18083:
    v_18266 = v_18263;
    goto v_18112;
v_18108:
    v_18264 = v_18266;
    goto v_18109;
v_18110:
    v_18263 = elt(env, 1); // or
    goto v_18111;
v_18112:
    goto v_18108;
v_18109:
    goto v_18110;
v_18111:
    if (v_18264 == v_18263) goto v_18106;
    else goto v_18107;
v_18106:
    v_18263 = lisp_true;
    goto v_18105;
v_18107:
    goto v_18122;
v_18118:
    v_18264 = v_18266;
    goto v_18119;
v_18120:
    v_18263 = elt(env, 2); // and
    goto v_18121;
v_18122:
    goto v_18118;
v_18119:
    goto v_18120;
v_18121:
    v_18263 = (v_18264 == v_18263 ? lisp_true : nil);
    goto v_18105;
    v_18263 = nil;
v_18105:
    if (v_18263 == nil) goto v_18103;
    v_18263 = lisp_true;
    goto v_18101;
v_18103:
    goto v_18133;
v_18129:
    v_18264 = v_18266;
    goto v_18130;
v_18131:
    v_18263 = elt(env, 3); // not
    goto v_18132;
v_18133:
    goto v_18129;
v_18130:
    goto v_18131;
v_18132:
    v_18263 = (v_18264 == v_18263 ? lisp_true : nil);
    goto v_18101;
    v_18263 = nil;
v_18101:
    if (v_18263 == nil) goto v_18099;
    v_18263 = lisp_true;
    goto v_18097;
v_18099:
    goto v_18148;
v_18144:
    v_18264 = v_18266;
    goto v_18145;
v_18146:
    v_18263 = elt(env, 4); // impl
    goto v_18147;
v_18148:
    goto v_18144;
v_18145:
    goto v_18146;
v_18147:
    if (v_18264 == v_18263) goto v_18142;
    else goto v_18143;
v_18142:
    v_18263 = lisp_true;
    goto v_18141;
v_18143:
    goto v_18162;
v_18158:
    v_18264 = v_18266;
    goto v_18159;
v_18160:
    v_18263 = elt(env, 5); // repl
    goto v_18161;
v_18162:
    goto v_18158;
v_18159:
    goto v_18160;
v_18161:
    if (v_18264 == v_18263) goto v_18156;
    else goto v_18157;
v_18156:
    v_18263 = lisp_true;
    goto v_18155;
v_18157:
    goto v_18172;
v_18168:
    v_18264 = v_18266;
    goto v_18169;
v_18170:
    v_18263 = elt(env, 6); // equiv
    goto v_18171;
v_18172:
    goto v_18168;
v_18169:
    goto v_18170;
v_18171:
    v_18263 = (v_18264 == v_18263 ? lisp_true : nil);
    goto v_18155;
    v_18263 = nil;
v_18155:
    goto v_18141;
    v_18263 = nil;
v_18141:
    goto v_18097;
    v_18263 = nil;
v_18097:
    if (v_18263 == nil) goto v_18095;
    v_18263 = v_18265;
    v_18263 = qcdr(v_18263);
    stack[-1] = v_18263;
    v_18263 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_18263;
v_18180:
    v_18263 = stack[-1];
    if (v_18263 == nil) goto v_18186;
    else goto v_18187;
v_18186:
    v_18263 = stack[0];
    goto v_18179;
v_18187:
    goto v_18195;
v_18191:
    v_18263 = stack[-1];
    v_18263 = qcar(v_18263);
    v_18264 = CC_talp_atnum(elt(env, 0), v_18263);
    env = stack[-2];
    goto v_18192;
v_18193:
    v_18263 = stack[0];
    goto v_18194;
v_18195:
    goto v_18191;
v_18192:
    goto v_18193;
v_18194:
    v_18263 = plus2(v_18264, v_18263);
    env = stack[-2];
    stack[0] = v_18263;
    v_18263 = stack[-1];
    v_18263 = qcdr(v_18263);
    stack[-1] = v_18263;
    goto v_18180;
v_18179:
    goto v_18081;
v_18095:
    goto v_18216;
v_18212:
    v_18264 = v_18266;
    goto v_18213;
v_18214:
    v_18263 = elt(env, 7); // ex
    goto v_18215;
v_18216:
    goto v_18212;
v_18213:
    goto v_18214;
v_18215:
    if (v_18264 == v_18263) goto v_18210;
    else goto v_18211;
v_18210:
    v_18263 = lisp_true;
    goto v_18209;
v_18211:
    goto v_18226;
v_18222:
    v_18264 = v_18266;
    goto v_18223;
v_18224:
    v_18263 = elt(env, 8); // all
    goto v_18225;
v_18226:
    goto v_18222;
v_18223:
    goto v_18224;
v_18225:
    v_18263 = (v_18264 == v_18263 ? lisp_true : nil);
    goto v_18209;
    v_18263 = nil;
v_18209:
    if (v_18263 == nil) goto v_18207;
    v_18263 = v_18265;
    v_18263 = qcdr(v_18263);
    v_18263 = qcdr(v_18263);
    v_18263 = qcar(v_18263);
    v_18265 = v_18263;
    goto v_18076;
v_18207:
    goto v_18247;
v_18243:
    v_18264 = v_18266;
    goto v_18244;
v_18245:
    v_18263 = elt(env, 9); // true
    goto v_18246;
v_18247:
    goto v_18243;
v_18244:
    goto v_18245;
v_18246:
    if (v_18264 == v_18263) goto v_18241;
    else goto v_18242;
v_18241:
    v_18263 = lisp_true;
    goto v_18240;
v_18242:
    goto v_18257;
v_18253:
    v_18263 = v_18266;
    goto v_18254;
v_18255:
    v_18264 = elt(env, 10); // false
    goto v_18256;
v_18257:
    goto v_18253;
v_18254:
    goto v_18255;
v_18256:
    v_18263 = (v_18263 == v_18264 ? lisp_true : nil);
    goto v_18240;
    v_18263 = nil;
v_18240:
    if (v_18263 == nil) goto v_18238;
    v_18263 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18081;
v_18238:
    v_18263 = (LispObject)16+TAG_FIXNUM; // 1
v_18081:
    return onevalue(v_18263);
}



// Code for pasf_sisub

static LispObject CC_pasf_sisub(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18528, v_18529, v_18530, v_18531, v_18532, v_18533;
    LispObject fn;
    LispObject v_18079, v_18078, v_18077;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pasf_sisub");
    va_start(aa, nargs);
    v_18077 = va_arg(aa, LispObject);
    v_18078 = va_arg(aa, LispObject);
    v_18079 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18079,v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18077,v_18078,v_18079);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_18079;
    stack[-5] = v_18078;
    stack[-1] = v_18077;
// end of prologue
    v_18528 = stack[-1];
    if (!consp(v_18528)) goto v_18086;
    else goto v_18087;
v_18086:
    v_18528 = stack[-1];
    goto v_18085;
v_18087:
    v_18528 = stack[-1];
    v_18528 = qcar(v_18528);
    goto v_18085;
    v_18528 = nil;
v_18085:
    stack[-6] = v_18528;
    goto v_18106;
v_18102:
    v_18529 = stack[-6];
    goto v_18103;
v_18104:
    v_18528 = elt(env, 1); // ex
    goto v_18105;
v_18106:
    goto v_18102;
v_18103:
    goto v_18104;
v_18105:
    if (v_18529 == v_18528) goto v_18100;
    else goto v_18101;
v_18100:
    v_18528 = lisp_true;
    goto v_18099;
v_18101:
    goto v_18116;
v_18112:
    v_18529 = stack[-6];
    goto v_18113;
v_18114:
    v_18528 = elt(env, 2); // all
    goto v_18115;
v_18116:
    goto v_18112;
v_18113:
    goto v_18114;
v_18115:
    v_18528 = (v_18529 == v_18528 ? lisp_true : nil);
    goto v_18099;
    v_18528 = nil;
v_18099:
    if (v_18528 == nil) goto v_18097;
    goto v_18127;
v_18121:
    stack[-2] = stack[-6];
    goto v_18122;
v_18123:
    v_18528 = stack[-1];
    v_18528 = qcdr(v_18528);
    stack[0] = qcar(v_18528);
    goto v_18124;
v_18125:
    goto v_18139;
v_18133:
    v_18528 = stack[-1];
    v_18528 = qcdr(v_18528);
    v_18528 = qcdr(v_18528);
    v_18530 = qcar(v_18528);
    goto v_18134;
v_18135:
    v_18529 = stack[-5];
    goto v_18136;
v_18137:
    v_18528 = stack[-4];
    goto v_18138;
v_18139:
    goto v_18133;
v_18134:
    goto v_18135;
v_18136:
    goto v_18137;
v_18138:
    v_18528 = CC_pasf_sisub(elt(env, 0), 3, v_18530, v_18529, v_18528);
    goto v_18126;
v_18127:
    goto v_18121;
v_18122:
    goto v_18123;
v_18124:
    goto v_18125;
v_18126:
    {
        LispObject v_18541 = stack[-2];
        LispObject v_18542 = stack[0];
        return list3(v_18541, v_18542, v_18528);
    }
v_18097:
    goto v_18158;
v_18154:
    v_18529 = stack[-6];
    goto v_18155;
v_18156:
    v_18528 = elt(env, 3); // bex
    goto v_18157;
v_18158:
    goto v_18154;
v_18155:
    goto v_18156;
v_18157:
    if (v_18529 == v_18528) goto v_18152;
    else goto v_18153;
v_18152:
    v_18528 = lisp_true;
    goto v_18151;
v_18153:
    goto v_18168;
v_18164:
    v_18529 = stack[-6];
    goto v_18165;
v_18166:
    v_18528 = elt(env, 4); // ball
    goto v_18167;
v_18168:
    goto v_18164;
v_18165:
    goto v_18166;
v_18167:
    v_18528 = (v_18529 == v_18528 ? lisp_true : nil);
    goto v_18151;
    v_18528 = nil;
v_18151:
    if (v_18528 == nil) goto v_18149;
    goto v_18181;
v_18173:
    stack[-3] = stack[-6];
    goto v_18174;
v_18175:
    v_18528 = stack[-1];
    v_18528 = qcdr(v_18528);
    stack[-2] = qcar(v_18528);
    goto v_18176;
v_18177:
    goto v_18193;
v_18187:
    v_18528 = stack[-1];
    v_18528 = qcdr(v_18528);
    v_18528 = qcdr(v_18528);
    v_18530 = qcar(v_18528);
    goto v_18188;
v_18189:
    v_18529 = stack[-5];
    goto v_18190;
v_18191:
    v_18528 = stack[-4];
    goto v_18192;
v_18193:
    goto v_18187;
v_18188:
    goto v_18189;
v_18190:
    goto v_18191;
v_18192:
    stack[0] = CC_pasf_sisub(elt(env, 0), 3, v_18530, v_18529, v_18528);
    env = stack[-7];
    goto v_18178;
v_18179:
    goto v_18207;
v_18201:
    v_18528 = stack[-1];
    v_18528 = qcdr(v_18528);
    v_18528 = qcdr(v_18528);
    v_18528 = qcdr(v_18528);
    v_18530 = qcar(v_18528);
    goto v_18202;
v_18203:
    v_18529 = stack[-5];
    goto v_18204;
v_18205:
    v_18528 = stack[-4];
    goto v_18206;
v_18207:
    goto v_18201;
v_18202:
    goto v_18203;
v_18204:
    goto v_18205;
v_18206:
    v_18528 = CC_pasf_sisub(elt(env, 0), 3, v_18530, v_18529, v_18528);
    goto v_18180;
v_18181:
    goto v_18173;
v_18174:
    goto v_18175;
v_18176:
    goto v_18177;
v_18178:
    goto v_18179;
v_18180:
    {
        LispObject v_18543 = stack[-3];
        LispObject v_18544 = stack[-2];
        LispObject v_18545 = stack[0];
        return list4(v_18543, v_18544, v_18545, v_18528);
    }
v_18149:
    goto v_18223;
v_18219:
    v_18529 = stack[-6];
    goto v_18220;
v_18221:
    v_18528 = elt(env, 5); // and
    goto v_18222;
v_18223:
    goto v_18219;
v_18220:
    goto v_18221;
v_18222:
    if (v_18529 == v_18528) goto v_18217;
    else goto v_18218;
v_18217:
    goto v_18239;
v_18227:
    v_18533 = elt(env, 5); // and
    goto v_18228;
v_18229:
    v_18528 = stack[-1];
    v_18532 = qcdr(v_18528);
    goto v_18230;
v_18231:
    v_18531 = stack[-5];
    goto v_18232;
v_18233:
    v_18530 = stack[-4];
    goto v_18234;
v_18235:
    v_18529 = elt(env, 6); // true
    goto v_18236;
v_18237:
    v_18528 = elt(env, 7); // false
    goto v_18238;
v_18239:
    goto v_18227;
v_18228:
    goto v_18229;
v_18230:
    goto v_18231;
v_18232:
    goto v_18233;
v_18234:
    goto v_18235;
v_18236:
    goto v_18237;
v_18238:
    {
        fn = elt(env, 13); // pasf_sisub!-gand
        return (*qfnn(fn))(fn, 6, v_18533, v_18532, v_18531, v_18530, v_18529, v_18528);
    }
v_18218:
    goto v_18255;
v_18251:
    v_18529 = stack[-6];
    goto v_18252;
v_18253:
    v_18528 = elt(env, 8); // or
    goto v_18254;
v_18255:
    goto v_18251;
v_18252:
    goto v_18253;
v_18254:
    if (v_18529 == v_18528) goto v_18249;
    else goto v_18250;
v_18249:
    goto v_18271;
v_18259:
    v_18533 = elt(env, 8); // or
    goto v_18260;
v_18261:
    v_18528 = stack[-1];
    v_18532 = qcdr(v_18528);
    goto v_18262;
v_18263:
    v_18531 = stack[-5];
    goto v_18264;
v_18265:
    v_18530 = stack[-4];
    goto v_18266;
v_18267:
    v_18529 = elt(env, 7); // false
    goto v_18268;
v_18269:
    v_18528 = elt(env, 6); // true
    goto v_18270;
v_18271:
    goto v_18259;
v_18260:
    goto v_18261;
v_18262:
    goto v_18263;
v_18264:
    goto v_18265;
v_18266:
    goto v_18267;
v_18268:
    goto v_18269;
v_18270:
    {
        fn = elt(env, 13); // pasf_sisub!-gand
        return (*qfnn(fn))(fn, 6, v_18533, v_18532, v_18531, v_18530, v_18529, v_18528);
    }
v_18250:
    goto v_18299;
v_18295:
    v_18529 = stack[-6];
    goto v_18296;
v_18297:
    v_18528 = elt(env, 8); // or
    goto v_18298;
v_18299:
    goto v_18295;
v_18296:
    goto v_18297;
v_18298:
    if (v_18529 == v_18528) goto v_18293;
    else goto v_18294;
v_18293:
    v_18528 = lisp_true;
    goto v_18292;
v_18294:
    goto v_18309;
v_18305:
    v_18529 = stack[-6];
    goto v_18306;
v_18307:
    v_18528 = elt(env, 5); // and
    goto v_18308;
v_18309:
    goto v_18305;
v_18306:
    goto v_18307;
v_18308:
    v_18528 = (v_18529 == v_18528 ? lisp_true : nil);
    goto v_18292;
    v_18528 = nil;
v_18292:
    if (v_18528 == nil) goto v_18290;
    v_18528 = lisp_true;
    goto v_18288;
v_18290:
    goto v_18320;
v_18316:
    v_18529 = stack[-6];
    goto v_18317;
v_18318:
    v_18528 = elt(env, 9); // not
    goto v_18319;
v_18320:
    goto v_18316;
v_18317:
    goto v_18318;
v_18319:
    v_18528 = (v_18529 == v_18528 ? lisp_true : nil);
    goto v_18288;
    v_18528 = nil;
v_18288:
    if (v_18528 == nil) goto v_18286;
    v_18528 = lisp_true;
    goto v_18284;
v_18286:
    goto v_18335;
v_18331:
    v_18529 = stack[-6];
    goto v_18332;
v_18333:
    v_18528 = elt(env, 10); // impl
    goto v_18334;
v_18335:
    goto v_18331;
v_18332:
    goto v_18333;
v_18334:
    if (v_18529 == v_18528) goto v_18329;
    else goto v_18330;
v_18329:
    v_18528 = lisp_true;
    goto v_18328;
v_18330:
    goto v_18349;
v_18345:
    v_18529 = stack[-6];
    goto v_18346;
v_18347:
    v_18528 = elt(env, 11); // repl
    goto v_18348;
v_18349:
    goto v_18345;
v_18346:
    goto v_18347;
v_18348:
    if (v_18529 == v_18528) goto v_18343;
    else goto v_18344;
v_18343:
    v_18528 = lisp_true;
    goto v_18342;
v_18344:
    goto v_18359;
v_18355:
    v_18529 = stack[-6];
    goto v_18356;
v_18357:
    v_18528 = elt(env, 12); // equiv
    goto v_18358;
v_18359:
    goto v_18355;
v_18356:
    goto v_18357;
v_18358:
    v_18528 = (v_18529 == v_18528 ? lisp_true : nil);
    goto v_18342;
    v_18528 = nil;
v_18342:
    goto v_18328;
    v_18528 = nil;
v_18328:
    goto v_18284;
    v_18528 = nil;
v_18284:
    if (v_18528 == nil) goto v_18282;
    v_18528 = stack[-1];
    v_18528 = qcdr(v_18528);
    stack[-3] = v_18528;
    v_18528 = stack[-3];
    if (v_18528 == nil) goto v_18373;
    else goto v_18374;
v_18373:
    v_18528 = nil;
    goto v_18367;
v_18374:
    v_18528 = stack[-3];
    v_18528 = qcar(v_18528);
    goto v_18388;
v_18382:
    v_18530 = v_18528;
    goto v_18383;
v_18384:
    v_18529 = stack[-5];
    goto v_18385;
v_18386:
    v_18528 = stack[-4];
    goto v_18387;
v_18388:
    goto v_18382;
v_18383:
    goto v_18384;
v_18385:
    goto v_18386;
v_18387:
    v_18528 = CC_pasf_sisub(elt(env, 0), 3, v_18530, v_18529, v_18528);
    env = stack[-7];
    v_18528 = ncons(v_18528);
    env = stack[-7];
    stack[-1] = v_18528;
    stack[-2] = v_18528;
v_18368:
    v_18528 = stack[-3];
    v_18528 = qcdr(v_18528);
    stack[-3] = v_18528;
    v_18528 = stack[-3];
    if (v_18528 == nil) goto v_18396;
    else goto v_18397;
v_18396:
    v_18528 = stack[-2];
    goto v_18367;
v_18397:
    goto v_18405;
v_18401:
    stack[0] = stack[-1];
    goto v_18402;
v_18403:
    v_18528 = stack[-3];
    v_18528 = qcar(v_18528);
    goto v_18418;
v_18412:
    v_18530 = v_18528;
    goto v_18413;
v_18414:
    v_18529 = stack[-5];
    goto v_18415;
v_18416:
    v_18528 = stack[-4];
    goto v_18417;
v_18418:
    goto v_18412;
v_18413:
    goto v_18414;
v_18415:
    goto v_18416;
v_18417:
    v_18528 = CC_pasf_sisub(elt(env, 0), 3, v_18530, v_18529, v_18528);
    env = stack[-7];
    v_18528 = ncons(v_18528);
    env = stack[-7];
    goto v_18404;
v_18405:
    goto v_18401;
v_18402:
    goto v_18403;
v_18404:
    v_18528 = Lrplacd(nil, stack[0], v_18528);
    env = stack[-7];
    v_18528 = stack[-1];
    v_18528 = qcdr(v_18528);
    stack[-1] = v_18528;
    goto v_18368;
v_18367:
    v_18529 = v_18528;
    v_18528 = v_18529;
    if (v_18528 == nil) goto v_18428;
    v_18528 = v_18529;
    v_18528 = qcdr(v_18528);
    if (v_18528 == nil) goto v_18428;
    goto v_18439;
v_18435:
    v_18528 = stack[-6];
    goto v_18436;
v_18437:
    goto v_18438;
v_18439:
    goto v_18435;
v_18436:
    goto v_18437;
v_18438:
    return cons(v_18528, v_18529);
v_18428:
    v_18528 = v_18529;
    if (v_18528 == nil) goto v_18442;
    else goto v_18443;
v_18442:
    goto v_18453;
v_18449:
    v_18529 = stack[-6];
    goto v_18450;
v_18451:
    v_18528 = elt(env, 5); // and
    goto v_18452;
v_18453:
    goto v_18449;
v_18450:
    goto v_18451;
v_18452:
    if (v_18529 == v_18528) goto v_18447;
    else goto v_18448;
v_18447:
    v_18528 = elt(env, 6); // true
    goto v_18446;
v_18448:
    v_18528 = elt(env, 7); // false
    goto v_18446;
    v_18528 = nil;
v_18446:
    goto v_18426;
v_18443:
    v_18528 = v_18529;
    v_18528 = qcar(v_18528);
    goto v_18426;
    v_18528 = nil;
v_18426:
    goto v_18083;
v_18282:
    goto v_18476;
v_18472:
    v_18529 = stack[-6];
    goto v_18473;
v_18474:
    v_18528 = elt(env, 6); // true
    goto v_18475;
v_18476:
    goto v_18472;
v_18473:
    goto v_18474;
v_18475:
    if (v_18529 == v_18528) goto v_18470;
    else goto v_18471;
v_18470:
    v_18528 = lisp_true;
    goto v_18469;
v_18471:
    goto v_18486;
v_18482:
    v_18529 = stack[-6];
    goto v_18483;
v_18484:
    v_18528 = elt(env, 7); // false
    goto v_18485;
v_18486:
    goto v_18482;
v_18483:
    goto v_18484;
v_18485:
    v_18528 = (v_18529 == v_18528 ? lisp_true : nil);
    goto v_18469;
    v_18528 = nil;
v_18469:
    if (v_18528 == nil) goto v_18467;
    v_18528 = stack[-1];
    goto v_18083;
v_18467:
    goto v_18496;
v_18492:
    goto v_18504;
v_18498:
    v_18528 = stack[-1];
    stack[0] = qcar(v_18528);
    goto v_18499;
v_18500:
    goto v_18512;
v_18508:
    v_18528 = stack[-1];
    v_18528 = qcdr(v_18528);
    stack[-1] = qcar(v_18528);
    goto v_18509;
v_18510:
    goto v_18522;
v_18518:
    v_18529 = stack[-5];
    goto v_18519;
v_18520:
    v_18528 = stack[-4];
    goto v_18521;
v_18522:
    goto v_18518;
v_18519:
    goto v_18520;
v_18521:
    v_18528 = cons(v_18529, v_18528);
    env = stack[-7];
    v_18528 = ncons(v_18528);
    env = stack[-7];
    goto v_18511;
v_18512:
    goto v_18508;
v_18509:
    goto v_18510;
v_18511:
    fn = elt(env, 14); // subf
    v_18528 = (*qfn2(fn))(fn, stack[-1], v_18528);
    env = stack[-7];
    v_18529 = qcar(v_18528);
    goto v_18501;
v_18502:
    v_18528 = nil;
    goto v_18503;
v_18504:
    goto v_18498;
v_18499:
    goto v_18500;
v_18501:
    goto v_18502;
v_18503:
    v_18529 = list3(stack[0], v_18529, v_18528);
    env = stack[-7];
    goto v_18493;
v_18494:
    v_18528 = stack[-6];
    goto v_18495;
v_18496:
    goto v_18492;
v_18493:
    goto v_18494;
v_18495:
    {
        fn = elt(env, 15); // pasf_simplat1
        return (*qfn2(fn))(fn, v_18529, v_18528);
    }
v_18083:
    return onevalue(v_18528);
}



// Code for innprodp2

static LispObject CC_innprodp2(LispObject env,
                         LispObject v_18077, LispObject v_18078)
{
    env = qenv(env);
    LispObject v_18122, v_18123, v_18124, v_18125;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18077,v_18078);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_18124 = v_18078;
    stack[0] = v_18077;
// end of prologue
    goto v_18087;
v_18083:
    v_18122 = nil;
    goto v_18084;
v_18085:
    v_18123 = v_18124;
    goto v_18086;
v_18087:
    goto v_18083;
v_18084:
    goto v_18085;
v_18086:
    v_18122 = cons(v_18122, v_18123);
    env = stack[-1];
    v_18124 = v_18122;
v_18092:
    v_18122 = stack[0];
    if (v_18122 == nil) goto v_18095;
    v_18122 = v_18124;
    if (v_18122 == nil) goto v_18095;
    goto v_18096;
v_18095:
    goto v_18091;
v_18096:
    goto v_18111;
v_18103:
    v_18125 = nil;
    goto v_18104;
v_18105:
    v_18122 = stack[0];
    v_18123 = qcar(v_18122);
    goto v_18106;
v_18107:
    v_18122 = v_18124;
    v_18122 = qcdr(v_18122);
    goto v_18108;
v_18109:
    v_18124 = qcar(v_18124);
    goto v_18110;
v_18111:
    goto v_18103;
v_18104:
    goto v_18105;
v_18106:
    goto v_18107;
v_18108:
    goto v_18109;
v_18110:
    fn = elt(env, 1); // innprodkp
    v_18122 = (*qfnn(fn))(fn, 4, v_18125, v_18123, v_18122, v_18124);
    env = stack[-1];
    v_18124 = v_18122;
    v_18122 = stack[0];
    v_18122 = qcdr(v_18122);
    stack[0] = v_18122;
    goto v_18092;
v_18091:
    v_18122 = v_18124;
    return onevalue(v_18122);
}



// Code for omatpir

static LispObject CC_omatpir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18103, v_18104, v_18105;
    LispObject fn;
    argcheck(nargs, 0, "omatpir");
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
    fn = elt(env, 2); // lex
    v_18103 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    fn = elt(env, 3); // omsir
    v_18103 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_18103 = qcar(v_18103);
    stack[-1] = v_18103;
    fn = elt(env, 2); // lex
    v_18103 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    fn = elt(env, 4); // omobj
    v_18103 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_18103 = qcar(v_18103);
    stack[0] = v_18103;
    fn = elt(env, 2); // lex
    v_18103 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_18103 = elt(env, 1); // (!/ o m a t p)
    fn = elt(env, 5); // checktag
    v_18103 = (*qfn1(fn))(fn, v_18103);
    env = stack[-2];
    goto v_18099;
v_18093:
    v_18105 = stack[-1];
    goto v_18094;
v_18095:
    v_18104 = stack[0];
    goto v_18096;
v_18097:
    v_18103 = nil;
    goto v_18098;
v_18099:
    goto v_18093;
v_18094:
    goto v_18095;
v_18096:
    goto v_18097;
v_18098:
    v_18103 = list2star(v_18105, v_18104, v_18103);
    return ncons(v_18103);
    return onevalue(v_18103);
}



// Code for mkempspmat

static LispObject CC_mkempspmat(LispObject env,
                         LispObject v_18077, LispObject v_18078)
{
    env = qenv(env);
    LispObject v_18096, v_18097;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18077,v_18078);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18078;
    v_18096 = v_18077;
// end of prologue
    goto v_18090;
v_18084:
    stack[-1] = elt(env, 1); // sparsemat
    goto v_18085;
v_18086:
    v_18097 = Lmkvect(nil, v_18096);
    goto v_18087;
v_18088:
    v_18096 = stack[0];
    goto v_18089;
v_18090:
    goto v_18084;
v_18085:
    goto v_18086;
v_18087:
    goto v_18088;
v_18089:
    {
        LispObject v_18100 = stack[-1];
        return list3(v_18100, v_18097, v_18096);
    }
    return onevalue(v_18096);
}



// Code for suchp

static LispObject CC_suchp(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18096, v_18097;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18097 = v_18077;
// end of prologue
    v_18096 = v_18097;
    if (!consp(v_18096)) goto v_18082;
    goto v_18088;
v_18084:
    v_18096 = v_18097;
    v_18096 = qcar(v_18096);
    goto v_18085;
v_18086:
    v_18097 = elt(env, 1); // such!-that
    goto v_18087;
v_18088:
    goto v_18084;
v_18085:
    goto v_18086;
v_18087:
    v_18096 = (v_18096 == v_18097 ? lisp_true : nil);
    goto v_18080;
v_18082:
    v_18096 = nil;
    goto v_18080;
    v_18096 = nil;
v_18080:
    return onevalue(v_18096);
}



// Code for dipequal

static LispObject CC_dipequal(LispObject env,
                         LispObject v_18077, LispObject v_18078)
{
    env = qenv(env);
    LispObject v_18137, v_18138;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18077,v_18078);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18078;
    stack[-1] = v_18077;
// end of prologue
v_18082:
    v_18137 = stack[-1];
    if (v_18137 == nil) goto v_18085;
    else goto v_18086;
v_18085:
    v_18137 = stack[0];
    v_18137 = (v_18137 == nil ? lisp_true : nil);
    goto v_18081;
v_18086:
    v_18137 = stack[0];
    if (v_18137 == nil) goto v_18090;
    else goto v_18091;
v_18090:
    v_18137 = nil;
    goto v_18081;
v_18091:
    goto v_18104;
v_18100:
    v_18137 = stack[-1];
    v_18137 = qcdr(v_18137);
    v_18138 = qcar(v_18137);
    goto v_18101;
v_18102:
    v_18137 = stack[0];
    v_18137 = qcdr(v_18137);
    v_18137 = qcar(v_18137);
    goto v_18103;
v_18104:
    goto v_18100;
v_18101:
    goto v_18102;
v_18103:
    if (equal(v_18138, v_18137)) goto v_18098;
    else goto v_18099;
v_18098:
    goto v_18120;
v_18116:
    v_18137 = stack[-1];
    v_18138 = qcar(v_18137);
    goto v_18117;
v_18118:
    v_18137 = stack[0];
    v_18137 = qcar(v_18137);
    goto v_18119;
v_18120:
    goto v_18116;
v_18117:
    goto v_18118;
v_18119:
    fn = elt(env, 1); // evequal
    v_18137 = (*qfn2(fn))(fn, v_18138, v_18137);
    env = stack[-2];
    if (v_18137 == nil) goto v_18114;
    v_18137 = stack[-1];
    v_18137 = qcdr(v_18137);
    v_18137 = qcdr(v_18137);
    stack[-1] = v_18137;
    v_18137 = stack[0];
    v_18137 = qcdr(v_18137);
    v_18137 = qcdr(v_18137);
    stack[0] = v_18137;
    goto v_18082;
v_18114:
    v_18137 = nil;
    goto v_18081;
    goto v_18097;
v_18099:
    v_18137 = nil;
    goto v_18081;
v_18097:
    goto v_18084;
v_18084:
    v_18137 = nil;
v_18081:
    return onevalue(v_18137);
}



// Code for !*xadd

static LispObject CC_Hxadd(LispObject env,
                         LispObject v_18077, LispObject v_18078)
{
    env = qenv(env);
    LispObject v_18130, v_18131, v_18132, v_18133;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18077,v_18078);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18133 = v_18078;
    stack[0] = v_18077;
// end of prologue
    v_18130 = v_18133;
    v_18132 = v_18130;
v_18086:
    v_18130 = v_18132;
    if (v_18130 == nil) goto v_18089;
    goto v_18098;
v_18094:
    v_18130 = stack[0];
    v_18131 = qcar(v_18130);
    goto v_18095;
v_18096:
    v_18130 = v_18132;
    v_18130 = qcar(v_18130);
    v_18130 = qcar(v_18130);
    goto v_18097;
v_18098:
    goto v_18094;
v_18095:
    goto v_18096;
v_18097:
    if (equal(v_18131, v_18130)) goto v_18089;
    goto v_18090;
v_18089:
    goto v_18085;
v_18090:
    v_18130 = v_18132;
    v_18130 = qcdr(v_18130);
    v_18132 = v_18130;
    goto v_18086;
v_18085:
    v_18130 = v_18132;
    if (v_18130 == nil) goto v_18110;
    goto v_18117;
v_18113:
    v_18130 = v_18132;
    v_18130 = qcar(v_18130);
    goto v_18114;
v_18115:
    v_18131 = v_18133;
    goto v_18116;
v_18117:
    goto v_18113;
v_18114:
    goto v_18115;
v_18116:
    v_18130 = Ldelete(nil, v_18130, v_18131);
    v_18133 = v_18130;
    goto v_18108;
v_18110:
v_18108:
    goto v_18126;
v_18122:
    v_18130 = stack[0];
    goto v_18123;
v_18124:
    v_18131 = v_18133;
    goto v_18125;
v_18126:
    goto v_18122;
v_18123:
    goto v_18124;
v_18125:
    return cons(v_18130, v_18131);
    return onevalue(v_18130);
}



// Code for simp!-prop1

static LispObject CC_simpKprop1(LispObject env,
                         LispObject v_18077, LispObject v_18078)
{
    env = qenv(env);
    LispObject v_18575, v_18576, v_18577;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18077,v_18078);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_18078;
    stack[-4] = v_18077;
// end of prologue
v_18076:
    v_18575 = stack[-4];
    if (!consp(v_18575)) goto v_18087;
    else goto v_18088;
v_18087:
    goto v_18083;
v_18088:
    goto v_18103;
v_18099:
    v_18575 = stack[-4];
    v_18576 = qcar(v_18575);
    goto v_18100;
v_18101:
    v_18575 = qvalue(elt(env, 1)); // !'and
    goto v_18102;
v_18103:
    goto v_18099;
v_18100:
    goto v_18101;
v_18102:
    if (equal(v_18576, v_18575)) goto v_18097;
    else goto v_18098;
v_18097:
    v_18575 = stack[-3];
    goto v_18096;
v_18098:
    v_18575 = nil;
    goto v_18096;
    v_18575 = nil;
v_18096:
    if (v_18575 == nil) goto v_18094;
    else goto v_18092;
v_18094:
    goto v_18120;
v_18116:
    v_18575 = stack[-4];
    v_18576 = qcar(v_18575);
    goto v_18117;
v_18118:
    v_18575 = qvalue(elt(env, 2)); // !'or
    goto v_18119;
v_18120:
    goto v_18116;
v_18117:
    goto v_18118;
v_18119:
    if (equal(v_18576, v_18575)) goto v_18114;
    else goto v_18115;
v_18114:
    v_18575 = stack[-3];
    v_18575 = (v_18575 == nil ? lisp_true : nil);
    goto v_18113;
v_18115:
    v_18575 = nil;
    goto v_18113;
    v_18575 = nil;
v_18113:
    if (v_18575 == nil) goto v_18111;
    else goto v_18092;
v_18111:
    goto v_18093;
v_18092:
    v_18575 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_18575;
    v_18575 = stack[-4];
    v_18575 = qcdr(v_18575);
    stack[-1] = v_18575;
v_18133:
    v_18575 = stack[-1];
    if (v_18575 == nil) goto v_18138;
    else goto v_18139;
v_18138:
    goto v_18132;
v_18139:
    v_18575 = stack[-1];
    v_18575 = qcar(v_18575);
    goto v_18150;
v_18146:
    goto v_18147;
v_18148:
    goto v_18157;
v_18153:
    v_18576 = v_18575;
    goto v_18154;
v_18155:
    v_18575 = stack[-3];
    goto v_18156;
v_18157:
    goto v_18153;
v_18154:
    goto v_18155;
v_18156:
    v_18575 = CC_simpKprop1(elt(env, 0), v_18576, v_18575);
    env = stack[-6];
    goto v_18149;
v_18150:
    goto v_18146;
v_18147:
    goto v_18148;
v_18149:
    fn = elt(env, 16); // multf
    v_18575 = (*qfn2(fn))(fn, stack[0], v_18575);
    env = stack[-6];
    stack[0] = v_18575;
    v_18575 = stack[-1];
    v_18575 = qcdr(v_18575);
    stack[-1] = v_18575;
    goto v_18133;
v_18132:
    goto v_18091;
v_18093:
    goto v_18173;
v_18169:
    v_18575 = stack[-4];
    v_18576 = qcar(v_18575);
    goto v_18170;
v_18171:
    v_18575 = qvalue(elt(env, 2)); // !'or
    goto v_18172;
v_18173:
    goto v_18169;
v_18170:
    goto v_18171;
v_18172:
    if (equal(v_18576, v_18575)) goto v_18167;
    else goto v_18168;
v_18167:
    v_18575 = stack[-3];
    goto v_18166;
v_18168:
    v_18575 = nil;
    goto v_18166;
    v_18575 = nil;
v_18166:
    if (v_18575 == nil) goto v_18164;
    else goto v_18162;
v_18164:
    goto v_18190;
v_18186:
    v_18575 = stack[-4];
    v_18576 = qcar(v_18575);
    goto v_18187;
v_18188:
    v_18575 = qvalue(elt(env, 1)); // !'and
    goto v_18189;
v_18190:
    goto v_18186;
v_18187:
    goto v_18188;
v_18189:
    if (equal(v_18576, v_18575)) goto v_18184;
    else goto v_18185;
v_18184:
    v_18575 = stack[-3];
    v_18575 = (v_18575 == nil ? lisp_true : nil);
    goto v_18183;
v_18185:
    v_18575 = nil;
    goto v_18183;
    v_18575 = nil;
v_18183:
    if (v_18575 == nil) goto v_18181;
    else goto v_18162;
v_18181:
    goto v_18163;
v_18162:
    v_18575 = nil;
    stack[0] = v_18575;
    v_18575 = stack[-4];
    v_18575 = qcdr(v_18575);
    stack[-1] = v_18575;
v_18203:
    v_18575 = stack[-1];
    if (v_18575 == nil) goto v_18208;
    else goto v_18209;
v_18208:
    goto v_18202;
v_18209:
    v_18575 = stack[-1];
    v_18575 = qcar(v_18575);
    goto v_18220;
v_18216:
    goto v_18217;
v_18218:
    goto v_18227;
v_18223:
    v_18576 = v_18575;
    goto v_18224;
v_18225:
    v_18575 = stack[-3];
    goto v_18226;
v_18227:
    goto v_18223;
v_18224:
    goto v_18225;
v_18226:
    v_18575 = CC_simpKprop1(elt(env, 0), v_18576, v_18575);
    env = stack[-6];
    goto v_18219;
v_18220:
    goto v_18216;
v_18217:
    goto v_18218;
v_18219:
    fn = elt(env, 17); // addf
    v_18575 = (*qfn2(fn))(fn, stack[0], v_18575);
    env = stack[-6];
    stack[0] = v_18575;
    v_18575 = stack[-1];
    v_18575 = qcdr(v_18575);
    stack[-1] = v_18575;
    goto v_18203;
v_18202:
    goto v_18091;
v_18163:
    goto v_18238;
v_18234:
    v_18575 = stack[-4];
    v_18576 = qcar(v_18575);
    goto v_18235;
v_18236:
    v_18575 = elt(env, 3); // not
    goto v_18237;
v_18238:
    goto v_18234;
v_18235:
    goto v_18236;
v_18237:
    if (v_18576 == v_18575) goto v_18232;
    else goto v_18233;
v_18232:
    goto v_18247;
v_18243:
    v_18575 = stack[-4];
    v_18575 = qcdr(v_18575);
    v_18576 = qcar(v_18575);
    goto v_18244;
v_18245:
    v_18575 = stack[-3];
    v_18575 = (v_18575 == nil ? lisp_true : nil);
    goto v_18246;
v_18247:
    goto v_18243;
v_18244:
    goto v_18245;
v_18246:
    v_18575 = CC_simpKprop1(elt(env, 0), v_18576, v_18575);
    stack[0] = v_18575;
    goto v_18091;
v_18233:
    goto v_18259;
v_18255:
    v_18575 = stack[-4];
    v_18576 = qcar(v_18575);
    goto v_18256;
v_18257:
    v_18575 = elt(env, 4); // implies
    goto v_18258;
v_18259:
    goto v_18255;
v_18256:
    goto v_18257;
v_18258:
    if (v_18576 == v_18575) goto v_18253;
    else goto v_18254;
v_18253:
    v_18575 = stack[-3];
    if (v_18575 == nil) goto v_18266;
    goto v_18273;
v_18269:
    goto v_18281;
v_18275:
    stack[0] = elt(env, 5); // or
    goto v_18276;
v_18277:
    goto v_18288;
v_18284:
    v_18576 = elt(env, 3); // not
    goto v_18285;
v_18286:
    v_18575 = stack[-4];
    v_18575 = qcdr(v_18575);
    v_18575 = qcar(v_18575);
    goto v_18287;
v_18288:
    goto v_18284;
v_18285:
    goto v_18286;
v_18287:
    v_18576 = list2(v_18576, v_18575);
    env = stack[-6];
    goto v_18278;
v_18279:
    v_18575 = stack[-4];
    v_18575 = qcdr(v_18575);
    v_18575 = qcdr(v_18575);
    v_18575 = qcar(v_18575);
    goto v_18280;
v_18281:
    goto v_18275;
v_18276:
    goto v_18277;
v_18278:
    goto v_18279;
v_18280:
    v_18576 = list3(stack[0], v_18576, v_18575);
    env = stack[-6];
    goto v_18270;
v_18271:
    v_18575 = lisp_true;
    goto v_18272;
v_18273:
    goto v_18269;
v_18270:
    goto v_18271;
v_18272:
    v_18575 = CC_simpKprop1(elt(env, 0), v_18576, v_18575);
    stack[0] = v_18575;
    goto v_18264;
v_18266:
    goto v_18305;
v_18301:
    goto v_18313;
v_18307:
    stack[0] = elt(env, 5); // or
    goto v_18308;
v_18309:
    goto v_18320;
v_18316:
    v_18576 = elt(env, 3); // not
    goto v_18317;
v_18318:
    v_18575 = stack[-4];
    v_18575 = qcdr(v_18575);
    v_18575 = qcdr(v_18575);
    v_18575 = qcar(v_18575);
    goto v_18319;
v_18320:
    goto v_18316;
v_18317:
    goto v_18318;
v_18319:
    v_18576 = list2(v_18576, v_18575);
    env = stack[-6];
    goto v_18310;
v_18311:
    v_18575 = stack[-4];
    v_18575 = qcdr(v_18575);
    v_18575 = qcar(v_18575);
    goto v_18312;
v_18313:
    goto v_18307;
v_18308:
    goto v_18309;
v_18310:
    goto v_18311;
v_18312:
    v_18576 = list3(stack[0], v_18576, v_18575);
    env = stack[-6];
    goto v_18302;
v_18303:
    v_18575 = lisp_true;
    goto v_18304;
v_18305:
    goto v_18301;
v_18302:
    goto v_18303;
v_18304:
    v_18575 = CC_simpKprop1(elt(env, 0), v_18576, v_18575);
    stack[0] = v_18575;
    goto v_18264;
v_18264:
    goto v_18091;
v_18254:
    goto v_18336;
v_18332:
    v_18575 = stack[-4];
    v_18576 = qcar(v_18575);
    goto v_18333;
v_18334:
    v_18575 = elt(env, 6); // equiv
    goto v_18335;
v_18336:
    goto v_18332;
v_18333:
    goto v_18334;
v_18335:
    if (v_18576 == v_18575) goto v_18330;
    else goto v_18331;
v_18330:
    goto v_18345;
v_18341:
    goto v_18353;
v_18347:
    stack[-5] = elt(env, 5); // or
    goto v_18348;
v_18349:
    goto v_18362;
v_18356:
    v_18577 = elt(env, 7); // and
    goto v_18357;
v_18358:
    v_18575 = stack[-4];
    v_18575 = qcdr(v_18575);
    v_18576 = qcar(v_18575);
    goto v_18359;
v_18360:
    v_18575 = stack[-4];
    v_18575 = qcdr(v_18575);
    v_18575 = qcdr(v_18575);
    v_18575 = qcar(v_18575);
    goto v_18361;
v_18362:
    goto v_18356;
v_18357:
    goto v_18358;
v_18359:
    goto v_18360;
v_18361:
    stack[-2] = list3(v_18577, v_18576, v_18575);
    env = stack[-6];
    goto v_18350;
v_18351:
    goto v_18378;
v_18372:
    stack[-1] = elt(env, 7); // and
    goto v_18373;
v_18374:
    goto v_18385;
v_18381:
    v_18576 = elt(env, 3); // not
    goto v_18382;
v_18383:
    v_18575 = stack[-4];
    v_18575 = qcdr(v_18575);
    v_18575 = qcar(v_18575);
    goto v_18384;
v_18385:
    goto v_18381;
v_18382:
    goto v_18383;
v_18384:
    stack[0] = list2(v_18576, v_18575);
    env = stack[-6];
    goto v_18375;
v_18376:
    goto v_18395;
v_18391:
    v_18576 = elt(env, 3); // not
    goto v_18392;
v_18393:
    v_18575 = stack[-4];
    v_18575 = qcdr(v_18575);
    v_18575 = qcdr(v_18575);
    v_18575 = qcar(v_18575);
    goto v_18394;
v_18395:
    goto v_18391;
v_18392:
    goto v_18393;
v_18394:
    v_18575 = list2(v_18576, v_18575);
    env = stack[-6];
    goto v_18377;
v_18378:
    goto v_18372;
v_18373:
    goto v_18374;
v_18375:
    goto v_18376;
v_18377:
    v_18575 = list3(stack[-1], stack[0], v_18575);
    env = stack[-6];
    goto v_18352;
v_18353:
    goto v_18347;
v_18348:
    goto v_18349;
v_18350:
    goto v_18351;
v_18352:
    v_18576 = list3(stack[-5], stack[-2], v_18575);
    env = stack[-6];
    goto v_18342;
v_18343:
    v_18575 = stack[-3];
    goto v_18344;
v_18345:
    goto v_18341;
v_18342:
    goto v_18343;
v_18344:
    v_18575 = CC_simpKprop1(elt(env, 0), v_18576, v_18575);
    stack[0] = v_18575;
    goto v_18091;
v_18331:
    goto v_18084;
v_18091:
    v_18575 = stack[0];
    goto v_18082;
v_18083:
    goto v_18417;
v_18413:
    v_18576 = stack[-4];
    goto v_18414;
v_18415:
    v_18575 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18416;
v_18417:
    goto v_18413;
v_18414:
    goto v_18415;
v_18416:
    if (v_18576 == v_18575) goto v_18411;
    else goto v_18412;
v_18411:
    v_18575 = lisp_true;
    goto v_18410;
v_18412:
    goto v_18431;
v_18427:
    v_18576 = stack[-4];
    goto v_18428;
v_18429:
    v_18575 = lisp_true;
    goto v_18430;
v_18431:
    goto v_18427;
v_18428:
    goto v_18429;
v_18430:
    if (equal(v_18576, v_18575)) goto v_18425;
    else goto v_18426;
v_18425:
    v_18575 = lisp_true;
    goto v_18424;
v_18426:
    goto v_18441;
v_18437:
    v_18576 = stack[-4];
    goto v_18438;
v_18439:
    v_18575 = elt(env, 8); // true
    goto v_18440;
v_18441:
    goto v_18437;
v_18438:
    goto v_18439;
v_18440:
    v_18575 = (v_18576 == v_18575 ? lisp_true : nil);
    goto v_18424;
    v_18575 = nil;
v_18424:
    goto v_18410;
    v_18575 = nil;
v_18410:
    if (v_18575 == nil) goto v_18408;
    v_18575 = stack[-3];
    stack[-4] = v_18575;
    goto v_18406;
v_18408:
    goto v_18456;
v_18452:
    v_18576 = stack[-4];
    goto v_18453;
v_18454:
    v_18575 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18455;
v_18456:
    goto v_18452;
v_18453:
    goto v_18454;
v_18455:
    if (v_18576 == v_18575) goto v_18450;
    else goto v_18451;
v_18450:
    v_18575 = lisp_true;
    goto v_18449;
v_18451:
    v_18575 = stack[-4];
    if (v_18575 == nil) goto v_18464;
    else goto v_18465;
v_18464:
    v_18575 = lisp_true;
    goto v_18463;
v_18465:
    goto v_18474;
v_18470:
    v_18576 = stack[-4];
    goto v_18471;
v_18472:
    v_18575 = elt(env, 9); // false
    goto v_18473;
v_18474:
    goto v_18470;
v_18471:
    goto v_18472;
v_18473:
    v_18575 = (v_18576 == v_18575 ? lisp_true : nil);
    goto v_18463;
    v_18575 = nil;
v_18463:
    goto v_18449;
    v_18575 = nil;
v_18449:
    if (v_18575 == nil) goto v_18447;
    v_18575 = stack[-3];
    v_18575 = (v_18575 == nil ? lisp_true : nil);
    stack[-4] = v_18575;
    goto v_18406;
v_18447:
v_18406:
    goto v_18488;
v_18484:
    v_18576 = stack[-4];
    goto v_18485;
v_18486:
    v_18575 = lisp_true;
    goto v_18487;
v_18488:
    goto v_18484;
v_18485:
    goto v_18486;
v_18487:
    if (equal(v_18576, v_18575)) goto v_18482;
    else goto v_18483;
v_18482:
    goto v_18496;
v_18492:
    v_18576 = elt(env, 10); // (or !*true (not !*true))
    goto v_18493;
v_18494:
    v_18575 = lisp_true;
    goto v_18495;
v_18496:
    goto v_18492;
v_18493:
    goto v_18494;
v_18495:
    stack[-4] = v_18576;
    stack[-3] = v_18575;
    goto v_18076;
v_18483:
    v_18575 = stack[-4];
    if (v_18575 == nil) goto v_18501;
    else goto v_18502;
v_18501:
    goto v_18509;
v_18505:
    v_18576 = elt(env, 11); // (and !*true (not !*true))
    goto v_18506;
v_18507:
    v_18575 = lisp_true;
    goto v_18508;
v_18509:
    goto v_18505;
v_18506:
    goto v_18507;
v_18508:
    stack[-4] = v_18576;
    stack[-3] = v_18575;
    goto v_18076;
v_18502:
v_18084:
    v_18575 = stack[-4];
    fn = elt(env, 18); // reval
    v_18575 = (*qfn1(fn))(fn, v_18575);
    env = stack[-6];
    stack[-4] = v_18575;
    goto v_18523;
v_18519:
    v_18576 = stack[-4];
    goto v_18520;
v_18521:
    v_18575 = elt(env, 12); // boolean
    goto v_18522;
v_18523:
    goto v_18519;
v_18520:
    goto v_18521;
v_18522:
    if (!consp(v_18576)) goto v_18517;
    v_18576 = qcar(v_18576);
    if (v_18576 == v_18575) goto v_18516;
    else goto v_18517;
v_18516:
    goto v_18531;
v_18527:
    v_18575 = stack[-4];
    v_18575 = qcdr(v_18575);
    v_18576 = qcar(v_18575);
    goto v_18528;
v_18529:
    v_18575 = stack[-3];
    goto v_18530;
v_18531:
    goto v_18527;
v_18528:
    goto v_18529;
v_18530:
    stack[-4] = v_18576;
    stack[-3] = v_18575;
    goto v_18076;
v_18517:
    goto v_18542;
v_18538:
    v_18575 = stack[-3];
    if (v_18575 == nil) goto v_18546;
    v_18575 = elt(env, 13); // prop!*
    v_18576 = v_18575;
    goto v_18544;
v_18546:
    v_18575 = elt(env, 14); // not_prop!*
    v_18576 = v_18575;
    goto v_18544;
    v_18576 = nil;
v_18544:
    goto v_18539;
v_18540:
    v_18575 = stack[-4];
    goto v_18541;
v_18542:
    goto v_18538;
v_18539:
    goto v_18540;
v_18541:
    v_18575 = list2(v_18576, v_18575);
    env = stack[-6];
    fn = elt(env, 19); // simp
    v_18575 = (*qfn1(fn))(fn, v_18575);
    env = stack[-6];
    v_18575 = qcar(v_18575);
    stack[0] = v_18575;
    goto v_18562;
v_18558:
    v_18576 = stack[-4];
    goto v_18559;
v_18560:
    v_18575 = qvalue(elt(env, 15)); // propvars!*
    goto v_18561;
v_18562:
    goto v_18558;
v_18559:
    goto v_18560;
v_18561:
    v_18575 = Lmember(nil, v_18576, v_18575);
    if (v_18575 == nil) goto v_18556;
    else goto v_18557;
v_18556:
    goto v_18571;
v_18567:
    v_18576 = stack[-4];
    goto v_18568;
v_18569:
    v_18575 = qvalue(elt(env, 15)); // propvars!*
    goto v_18570;
v_18571:
    goto v_18567;
v_18568:
    goto v_18569;
v_18570:
    v_18575 = cons(v_18576, v_18575);
    env = stack[-6];
    qvalue(elt(env, 15)) = v_18575; // propvars!*
    goto v_18555;
v_18557:
v_18555:
    v_18575 = stack[0];
v_18082:
    return onevalue(v_18575);
}



// Code for split_cov_cont_ids

static LispObject CC_split_cov_cont_ids(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18139, v_18140, v_18141;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18077);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_18077;
// end of prologue
    stack[-2] = nil;
    stack[0] = nil;
v_18085:
    v_18139 = stack[-1];
    if (v_18139 == nil) goto v_18088;
    else goto v_18089;
v_18088:
    goto v_18084;
v_18089:
    v_18139 = stack[-1];
    v_18139 = qcar(v_18139);
    v_18141 = v_18139;
    goto v_18104;
v_18100:
    v_18140 = v_18141;
    goto v_18101;
v_18102:
    v_18139 = elt(env, 1); // minus
    goto v_18103;
v_18104:
    goto v_18100;
v_18101:
    goto v_18102;
v_18103:
    if (!consp(v_18140)) goto v_18098;
    v_18140 = qcar(v_18140);
    if (v_18140 == v_18139) goto v_18097;
    else goto v_18098;
v_18097:
    goto v_18112;
v_18108:
    v_18139 = v_18141;
    v_18139 = qcdr(v_18139);
    v_18140 = qcar(v_18139);
    goto v_18109;
v_18110:
    v_18139 = stack[-2];
    goto v_18111;
v_18112:
    goto v_18108;
v_18109:
    goto v_18110;
v_18111:
    v_18139 = cons(v_18140, v_18139);
    env = stack[-3];
    stack[-2] = v_18139;
    goto v_18096;
v_18098:
    goto v_18124;
v_18120:
    v_18140 = v_18141;
    goto v_18121;
v_18122:
    v_18139 = stack[0];
    goto v_18123;
v_18124:
    goto v_18120;
v_18121:
    goto v_18122;
v_18123:
    v_18139 = cons(v_18140, v_18139);
    env = stack[-3];
    stack[0] = v_18139;
    goto v_18096;
v_18096:
    v_18139 = stack[-1];
    v_18139 = qcdr(v_18139);
    stack[-1] = v_18139;
    goto v_18085;
v_18084:
    goto v_18134;
v_18130:
    v_18139 = stack[-2];
    v_18140 = Lnreverse(nil, v_18139);
    env = stack[-3];
    goto v_18131;
v_18132:
    v_18139 = stack[0];
    v_18139 = Lnreverse(nil, v_18139);
    goto v_18133;
v_18134:
    goto v_18130;
v_18131:
    goto v_18132;
v_18133:
    return list2(v_18140, v_18139);
    return onevalue(v_18139);
}



// Code for st_ad_numsorttree

static LispObject CC_st_ad_numsorttree(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18095, v_18096;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18077);
    }
// copy arguments values to proper place
    v_18095 = v_18077;
// end of prologue
    fn = elt(env, 1); // st_ad_numsorttree1
    v_18095 = (*qfn1(fn))(fn, v_18095);
    goto v_18089;
v_18085:
    v_18096 = v_18095;
    v_18096 = qcar(v_18096);
    goto v_18086;
v_18087:
    v_18095 = qcdr(v_18095);
    v_18095 = qcar(v_18095);
    goto v_18088;
v_18089:
    goto v_18085;
v_18086:
    goto v_18087;
v_18088:
    return cons(v_18096, v_18095);
    return onevalue(v_18095);
}



// Code for general!-horner!-rule!-mod!-p

static LispObject CC_generalKhornerKruleKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18233, v_18234, v_18235, v_18236, v_18237;
    LispObject fn;
    LispObject v_18081, v_18080, v_18079, v_18078, v_18077;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "general-horner-rule-mod-p");
    va_start(aa, nargs);
    v_18077 = va_arg(aa, LispObject);
    v_18078 = va_arg(aa, LispObject);
    v_18079 = va_arg(aa, LispObject);
    v_18080 = va_arg(aa, LispObject);
    v_18081 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_18081,v_18080,v_18079,v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_18077,v_18078,v_18079,v_18080,v_18081);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_18081;
    stack[-3] = v_18080;
    stack[-4] = v_18079;
    v_18235 = v_18078;
    v_18236 = v_18077;
// end of prologue
v_18076:
    v_18233 = stack[-4];
    if (!consp(v_18233)) goto v_18093;
    else goto v_18094;
v_18093:
    v_18233 = lisp_true;
    goto v_18092;
v_18094:
    v_18233 = stack[-4];
    v_18233 = qcar(v_18233);
    v_18233 = (consp(v_18233) ? nil : lisp_true);
    goto v_18092;
    v_18233 = nil;
v_18092:
    if (v_18233 == nil) goto v_18090;
    v_18233 = lisp_true;
    goto v_18088;
v_18090:
    goto v_18109;
v_18105:
    v_18233 = stack[-4];
    v_18233 = qcar(v_18233);
    v_18233 = qcar(v_18233);
    v_18234 = qcar(v_18233);
    goto v_18106;
v_18107:
    v_18233 = stack[-2];
    goto v_18108;
v_18109:
    goto v_18105;
v_18106:
    goto v_18107;
v_18108:
    v_18233 = (equal(v_18234, v_18233) ? lisp_true : nil);
    v_18233 = (v_18233 == nil ? lisp_true : nil);
    goto v_18088;
    v_18233 = nil;
v_18088:
    if (v_18233 == nil) goto v_18086;
    v_18233 = stack[-3];
    if (v_18233 == nil) goto v_18123;
    else goto v_18124;
v_18123:
    v_18233 = lisp_true;
    goto v_18122;
v_18124:
    v_18233 = stack[-3];
    v_18233 = (LispObject)zerop(v_18233);
    v_18233 = v_18233 ? lisp_true : nil;
    env = stack[-6];
    goto v_18122;
    v_18233 = nil;
v_18122:
    if (v_18233 == nil) goto v_18120;
    v_18233 = stack[-4];
    goto v_18118;
v_18120:
    goto v_18139;
v_18135:
    stack[0] = v_18236;
    goto v_18136;
v_18137:
    goto v_18146;
v_18142:
    v_18233 = stack[-3];
    goto v_18143;
v_18144:
    v_18234 = v_18235;
    goto v_18145;
v_18146:
    goto v_18142;
v_18143:
    goto v_18144;
v_18145:
    fn = elt(env, 1); // general!-expt!-mod!-p
    v_18233 = (*qfn2(fn))(fn, v_18233, v_18234);
    env = stack[-6];
    goto v_18138;
v_18139:
    goto v_18135;
v_18136:
    goto v_18137;
v_18138:
    fn = elt(env, 2); // general!-times!-mod!-p
    v_18233 = (*qfn2(fn))(fn, stack[0], v_18233);
    env = stack[-6];
    v_18236 = v_18233;
    goto v_18154;
v_18150:
    v_18233 = stack[-4];
    goto v_18151;
v_18152:
    v_18234 = v_18236;
    goto v_18153;
v_18154:
    goto v_18150;
v_18151:
    goto v_18152;
v_18153:
    {
        fn = elt(env, 3); // general!-plus!-mod!-p
        return (*qfn2(fn))(fn, v_18233, v_18234);
    }
    v_18233 = nil;
v_18118:
    goto v_18084;
v_18086:
    v_18233 = stack[-4];
    v_18233 = qcar(v_18233);
    v_18233 = qcar(v_18233);
    v_18233 = qcdr(v_18233);
    stack[-5] = v_18233;
    goto v_18177;
v_18167:
    v_18233 = stack[-3];
    if (v_18233 == nil) goto v_18184;
    else goto v_18185;
v_18184:
    v_18233 = lisp_true;
    goto v_18183;
v_18185:
    v_18233 = stack[-3];
    v_18233 = (LispObject)zerop(v_18233);
    v_18233 = v_18233 ? lisp_true : nil;
    env = stack[-6];
    goto v_18183;
    v_18233 = nil;
v_18183:
    if (v_18233 == nil) goto v_18181;
    v_18233 = stack[-4];
    v_18233 = qcar(v_18233);
    v_18233 = qcdr(v_18233);
    v_18236 = v_18233;
    goto v_18179;
v_18181:
    goto v_18202;
v_18198:
    v_18233 = stack[-4];
    v_18233 = qcar(v_18233);
    stack[-1] = qcdr(v_18233);
    goto v_18199;
v_18200:
    goto v_18211;
v_18207:
    stack[0] = v_18236;
    goto v_18208;
v_18209:
    goto v_18218;
v_18214:
    v_18234 = stack[-3];
    goto v_18215;
v_18216:
    goto v_18224;
v_18220:
    goto v_18221;
v_18222:
    v_18233 = stack[-5];
    goto v_18223;
v_18224:
    goto v_18220;
v_18221:
    goto v_18222;
v_18223:
    v_18233 = (LispObject)(intptr_t)((intptr_t)v_18235 - (intptr_t)v_18233 + TAG_FIXNUM);
    goto v_18217;
v_18218:
    goto v_18214;
v_18215:
    goto v_18216;
v_18217:
    fn = elt(env, 1); // general!-expt!-mod!-p
    v_18233 = (*qfn2(fn))(fn, v_18234, v_18233);
    env = stack[-6];
    goto v_18210;
v_18211:
    goto v_18207;
v_18208:
    goto v_18209;
v_18210:
    fn = elt(env, 2); // general!-times!-mod!-p
    v_18233 = (*qfn2(fn))(fn, stack[0], v_18233);
    env = stack[-6];
    goto v_18201;
v_18202:
    goto v_18198;
v_18199:
    goto v_18200;
v_18201:
    fn = elt(env, 3); // general!-plus!-mod!-p
    v_18233 = (*qfn2(fn))(fn, stack[-1], v_18233);
    env = stack[-6];
    v_18236 = v_18233;
    goto v_18179;
    v_18236 = nil;
v_18179:
    goto v_18168;
v_18169:
    v_18235 = stack[-5];
    goto v_18170;
v_18171:
    v_18233 = stack[-4];
    v_18237 = qcdr(v_18233);
    goto v_18172;
v_18173:
    v_18234 = stack[-3];
    goto v_18174;
v_18175:
    v_18233 = stack[-2];
    goto v_18176;
v_18177:
    goto v_18167;
v_18168:
    goto v_18169;
v_18170:
    goto v_18171;
v_18172:
    goto v_18173;
v_18174:
    goto v_18175;
v_18176:
    stack[-4] = v_18237;
    stack[-3] = v_18234;
    stack[-2] = v_18233;
    goto v_18076;
    goto v_18084;
    v_18233 = nil;
v_18084:
    return onevalue(v_18233);
}



// Code for gitimes!:

static LispObject CC_gitimesT(LispObject env,
                         LispObject v_18077, LispObject v_18078)
{
    env = qenv(env);
    LispObject v_18146, v_18147, v_18148, v_18149;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18078,v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18077,v_18078);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_18146 = v_18078;
    v_18147 = v_18077;
// end of prologue
    v_18148 = v_18147;
    v_18148 = qcdr(v_18148);
    v_18149 = qcar(v_18148);
    v_18147 = qcdr(v_18147);
    v_18148 = qcdr(v_18147);
    v_18147 = v_18146;
    v_18147 = qcdr(v_18147);
    v_18147 = qcar(v_18147);
    v_18146 = qcdr(v_18146);
    v_18146 = qcdr(v_18146);
    stack[-4] = v_18149;
    stack[-3] = v_18148;
    stack[-2] = v_18147;
    stack[-1] = v_18146;
    goto v_18101;
v_18097:
    goto v_18107;
v_18103:
    goto v_18113;
v_18109:
    v_18147 = stack[-4];
    goto v_18110;
v_18111:
    v_18146 = stack[-2];
    goto v_18112;
v_18113:
    goto v_18109;
v_18110:
    goto v_18111;
v_18112:
    stack[0] = times2(v_18147, v_18146);
    env = stack[-5];
    goto v_18104;
v_18105:
    goto v_18121;
v_18117:
    v_18147 = stack[-3];
    goto v_18118;
v_18119:
    v_18146 = stack[-1];
    goto v_18120;
v_18121:
    goto v_18117;
v_18118:
    goto v_18119;
v_18120:
    v_18146 = times2(v_18147, v_18146);
    env = stack[-5];
    goto v_18106;
v_18107:
    goto v_18103;
v_18104:
    goto v_18105;
v_18106:
    stack[0] = difference2(stack[0], v_18146);
    env = stack[-5];
    goto v_18098;
v_18099:
    goto v_18129;
v_18125:
    goto v_18135;
v_18131:
    v_18147 = stack[-4];
    goto v_18132;
v_18133:
    v_18146 = stack[-1];
    goto v_18134;
v_18135:
    goto v_18131;
v_18132:
    goto v_18133;
v_18134:
    stack[-1] = times2(v_18147, v_18146);
    env = stack[-5];
    goto v_18126;
v_18127:
    goto v_18143;
v_18139:
    v_18147 = stack[-2];
    goto v_18140;
v_18141:
    v_18146 = stack[-3];
    goto v_18142;
v_18143:
    goto v_18139;
v_18140:
    goto v_18141;
v_18142:
    v_18146 = times2(v_18147, v_18146);
    env = stack[-5];
    goto v_18128;
v_18129:
    goto v_18125;
v_18126:
    goto v_18127;
v_18128:
    v_18146 = plus2(stack[-1], v_18146);
    env = stack[-5];
    goto v_18100;
v_18101:
    goto v_18097;
v_18098:
    goto v_18099;
v_18100:
    {
        LispObject v_18155 = stack[0];
        fn = elt(env, 1); // mkgi
        return (*qfn2(fn))(fn, v_18155, v_18146);
    }
}



// Code for !*a2f

static LispObject CC_Ha2f(LispObject env,
                         LispObject v_18077)
{
    env = qenv(env);
    LispObject v_18082;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18077);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18077);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18082 = v_18077;
// end of prologue
    fn = elt(env, 1); // simp!*
    v_18082 = (*qfn1(fn))(fn, v_18082);
    env = stack[0];
    {
        fn = elt(env, 2); // !*q2f
        return (*qfn1(fn))(fn, v_18082);
    }
}



setup_type const u32_setup[] =
{
    {"ofsf_simplat1",           TOO_FEW_2,      CC_ofsf_simplat1,WRONG_NO_2},
    {"containerml",             TOO_FEW_2,      CC_containerml,WRONG_NO_2},
    {"add_minus",               CC_add_minus,   TOO_MANY_1,    WRONG_NO_1},
    {"insoccs",                 TOO_FEW_2,      CC_insoccs,    WRONG_NO_2},
    {"overall_factor",          TOO_FEW_2,      CC_overall_factor,WRONG_NO_2},
    {"testchar1",               CC_testchar1,   TOO_MANY_1,    WRONG_NO_1},
    {"expand_rule",             CC_expand_rule, TOO_MANY_1,    WRONG_NO_1},
    {"formboollis",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formboollis},
    {"pasf_dt",                 CC_pasf_dt,     TOO_MANY_1,    WRONG_NO_1},
    {"ev_revgradlexcomp",       TOO_FEW_2,      CC_ev_revgradlexcomp,WRONG_NO_2},
    {"minusml",                 CC_minusml,     TOO_MANY_1,    WRONG_NO_1},
    {"f2dip11",                 CC_f2dip11,     TOO_MANY_1,    WRONG_NO_1},
    {"xriterion_1",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xriterion_1},
    {"eqexpr",                  CC_eqexpr,      TOO_MANY_1,    WRONG_NO_1},
    {"comb",                    TOO_FEW_2,      CC_comb,       WRONG_NO_2},
    {"max-degree",              TOO_FEW_2,      CC_maxKdegree, WRONG_NO_2},
    {"chkrn*",                  CC_chkrnH,      TOO_MANY_1,    WRONG_NO_1},
    {"length_multiindex",       CC_length_multiindex,TOO_MANY_1,WRONG_NO_1},
    {"ofsf_facequal*",          TOO_FEW_2,      CC_ofsf_facequalH,WRONG_NO_2},
    {"talp_noffcts",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_noffcts},
    {"pasf_susibinad",          TOO_FEW_2,      CC_pasf_susibinad,WRONG_NO_2},
    {"ev_sum",                  TOO_FEW_2,      CC_ev_sum,     WRONG_NO_2},
    {"multiminus",              CC_multiminus,  TOO_MANY_1,    WRONG_NO_1},
    {"dm-min",                  TOO_FEW_2,      CC_dmKmin,     WRONG_NO_2},
    {":dmtimeslst",             CC_Tdmtimeslst, TOO_MANY_1,    WRONG_NO_1},
    {"sign-of",                 CC_signKof,     TOO_MANY_1,    WRONG_NO_1},
    {"log_assignment",          TOO_FEW_2,      CC_log_assignment,WRONG_NO_2},
    {"arglength",               CC_arglength,   TOO_MANY_1,    WRONG_NO_1},
    {"*di2q",                   TOO_FEW_2,      CC_Hdi2q,      WRONG_NO_2},
    {"ra_l",                    CC_ra_l,        TOO_MANY_1,    WRONG_NO_1},
    {"lalr_extract_nonterminals",CC_lalr_extract_nonterminals,TOO_MANY_1,WRONG_NO_1},
    {"talp_atnum",              CC_talp_atnum,  TOO_MANY_1,    WRONG_NO_1},
    {"pasf_sisub",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pasf_sisub},
    {"innprodp2",               TOO_FEW_2,      CC_innprodp2,  WRONG_NO_2},
    {"omatpir",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_omatpir},
    {"mkempspmat",              TOO_FEW_2,      CC_mkempspmat, WRONG_NO_2},
    {"suchp",                   CC_suchp,       TOO_MANY_1,    WRONG_NO_1},
    {"dipequal",                TOO_FEW_2,      CC_dipequal,   WRONG_NO_2},
    {"*xadd",                   TOO_FEW_2,      CC_Hxadd,      WRONG_NO_2},
    {"simp-prop1",              TOO_FEW_2,      CC_simpKprop1, WRONG_NO_2},
    {"split_cov_cont_ids",      CC_split_cov_cont_ids,TOO_MANY_1,WRONG_NO_1},
    {"st_ad_numsorttree",       CC_st_ad_numsorttree,TOO_MANY_1,WRONG_NO_1},
    {"general-horner-rule-mod-p",WRONG_NO_NA,   WRONG_NO_NB,   (n_args *)CC_generalKhornerKruleKmodKp},
    {"gitimes:",                TOO_FEW_2,      CC_gitimesT,   WRONG_NO_2},
    {"*a2f",                    CC_Ha2f,        TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u32", (two_args *)"21190 3922534 8060720", 0}
};

// end of generated code
