
// $destdir/u46.c        Machine generated C code

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



// Code for gcdlist

static LispObject CC_gcdlist(LispObject env,
                         LispObject v_25734)
{
    env = qenv(env);
    LispObject v_26384, v_26385, v_26386;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25734);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(15);
// copy arguments values to proper place
    stack[0] = v_25734;
// end of prologue
    v_26384 = stack[0];
    if (v_26384 == nil) goto v_25738;
    else goto v_25739;
v_25738:
    v_26384 = nil;
    goto v_25737;
v_25739:
    v_26384 = stack[0];
    v_26384 = qcdr(v_26384);
    if (v_26384 == nil) goto v_25742;
    else goto v_25743;
v_25742:
    v_26384 = stack[0];
    v_26384 = qcar(v_26384);
    {
        fn = elt(env, 4); // poly!-abs
        return (*qfn1(fn))(fn, v_26384);
    }
v_25743:
    v_26384 = stack[0];
    v_26384 = qcar(v_26384);
    if (!consp(v_26384)) goto v_25753;
    else goto v_25754;
v_25753:
    v_26384 = lisp_true;
    goto v_25752;
v_25754:
    v_26384 = stack[0];
    v_26384 = qcar(v_26384);
    v_26384 = qcar(v_26384);
    v_26384 = (consp(v_26384) ? nil : lisp_true);
    goto v_25752;
    v_26384 = nil;
v_25752:
    if (v_26384 == nil) goto v_25750;
    goto v_25769;
v_25765:
    v_26384 = stack[0];
    v_26385 = qcdr(v_26384);
    goto v_25766;
v_25767:
    v_26384 = stack[0];
    v_26384 = qcar(v_26384);
    goto v_25768;
v_25769:
    goto v_25765;
v_25766:
    goto v_25767;
v_25768:
    {
        fn = elt(env, 5); // gcdld
        return (*qfn2(fn))(fn, v_26385, v_26384);
    }
v_25750:
    stack[-1] = nil;
v_25784:
    v_26384 = stack[0];
    if (v_26384 == nil) goto v_25787;
    else goto v_25788;
v_25787:
    goto v_25783;
v_25788:
    v_26384 = stack[0];
    v_26384 = qcar(v_26384);
    if (v_26384 == nil) goto v_25793;
    else goto v_25794;
v_25793:
    v_26384 = stack[0];
    v_26384 = qcdr(v_26384);
    stack[0] = v_26384;
    goto v_25792;
v_25794:
    v_26384 = stack[0];
    v_26384 = qcar(v_26384);
    if (!consp(v_26384)) goto v_25803;
    else goto v_25804;
v_25803:
    v_26384 = lisp_true;
    goto v_25802;
v_25804:
    v_26384 = stack[0];
    v_26384 = qcar(v_26384);
    v_26384 = qcar(v_26384);
    v_26384 = (consp(v_26384) ? nil : lisp_true);
    goto v_25802;
    v_26384 = nil;
v_25802:
    if (v_26384 == nil) goto v_25800;
    goto v_25821;
v_25817:
    v_26384 = stack[0];
    stack[-2] = qcdr(v_26384);
    goto v_25818;
v_25819:
    goto v_25829;
v_25825:
    v_26384 = stack[-1];
    fn = elt(env, 6); // mapcarcar
    v_26385 = (*qfn1(fn))(fn, v_26384);
    env = stack[-14];
    goto v_25826;
v_25827:
    v_26384 = stack[0];
    v_26384 = qcar(v_26384);
    goto v_25828;
v_25829:
    goto v_25825;
v_25826:
    goto v_25827;
v_25828:
    fn = elt(env, 5); // gcdld
    v_26384 = (*qfn2(fn))(fn, v_26385, v_26384);
    env = stack[-14];
    goto v_25820;
v_25821:
    goto v_25817;
v_25818:
    goto v_25819;
v_25820:
    fn = elt(env, 5); // gcdld
    v_26384 = (*qfn2(fn))(fn, stack[-2], v_26384);
    env = stack[-14];
    v_26384 = ncons(v_26384);
    env = stack[-14];
    v_26384 = ncons(v_26384);
    env = stack[-14];
    stack[-1] = v_26384;
    v_26384 = nil;
    stack[0] = v_26384;
    goto v_25792;
v_25800:
    goto v_25844;
v_25838:
    v_26384 = stack[0];
    stack[-2] = qcar(v_26384);
    goto v_25839;
v_25840:
    v_26384 = stack[0];
    v_26384 = qcar(v_26384);
    fn = elt(env, 7); // powers1
    v_26385 = (*qfn1(fn))(fn, v_26384);
    env = stack[-14];
    goto v_25841;
v_25842:
    v_26384 = stack[-1];
    goto v_25843;
v_25844:
    goto v_25838;
v_25839:
    goto v_25840;
v_25841:
    goto v_25842;
v_25843:
    v_26384 = acons(stack[-2], v_26385, v_26384);
    env = stack[-14];
    stack[-1] = v_26384;
    v_26384 = stack[0];
    v_26384 = qcdr(v_26384);
    stack[0] = v_26384;
    goto v_25792;
v_25792:
    goto v_25784;
v_25783:
    v_26384 = stack[-1];
    if (v_26384 == nil) goto v_25855;
    else goto v_25856;
v_25855:
    v_26384 = nil;
    goto v_25780;
v_25856:
    v_26384 = stack[-1];
    v_26384 = qcdr(v_26384);
    if (v_26384 == nil) goto v_25859;
    else goto v_25860;
v_25859:
    v_26384 = stack[-1];
    v_26384 = qcar(v_26384);
    v_26384 = qcar(v_26384);
    {
        fn = elt(env, 4); // poly!-abs
        return (*qfn1(fn))(fn, v_26384);
    }
v_25860:
    v_26384 = nil;
    stack[-13] = v_26384;
    v_26384 = nil;
    stack[-12] = v_26384;
    v_26384 = stack[-1];
    stack[-11] = v_26384;
    v_26384 = stack[-11];
    if (v_26384 == nil) goto v_25878;
    else goto v_25879;
v_25878:
    v_26384 = nil;
    goto v_25873;
v_25879:
    v_26384 = stack[-11];
    v_26384 = qcar(v_26384);
    stack[-7] = v_26384;
    stack[-6] = nil;
    v_26384 = stack[-7];
    v_26384 = qcdr(v_26384);
    stack[-5] = v_26384;
    v_26384 = stack[-5];
    if (v_26384 == nil) goto v_25902;
    else goto v_25903;
v_25902:
    v_26384 = nil;
    goto v_25896;
v_25903:
    v_26384 = stack[-5];
    v_26384 = qcar(v_26384);
    stack[-1] = v_26384;
    goto v_25917;
v_25911:
    v_26384 = stack[-1];
    v_26386 = qcar(v_26384);
    goto v_25912;
v_25913:
    v_26384 = stack[-1];
    v_26384 = qcdr(v_26384);
    v_26385 = qcdr(v_26384);
    goto v_25914;
v_25915:
    v_26384 = stack[-6];
    goto v_25916;
v_25917:
    goto v_25911;
v_25912:
    goto v_25913;
v_25914:
    goto v_25915;
v_25916:
    v_26384 = acons(v_26386, v_26385, v_26384);
    env = stack[-14];
    stack[-6] = v_26384;
    goto v_25929;
v_25925:
    v_26384 = stack[-1];
    stack[0] = qcar(v_26384);
    goto v_25926;
v_25927:
    goto v_25937;
v_25933:
    v_26384 = stack[-1];
    v_26384 = qcdr(v_26384);
    v_26385 = qcar(v_26384);
    goto v_25934;
v_25935:
    v_26384 = stack[-1];
    v_26384 = qcdr(v_26384);
    v_26384 = qcdr(v_26384);
    goto v_25936;
v_25937:
    goto v_25933;
v_25934:
    goto v_25935;
v_25936:
    v_26384 = difference2(v_26385, v_26384);
    env = stack[-14];
    goto v_25928;
v_25929:
    goto v_25925;
v_25926:
    goto v_25927;
v_25928:
    v_26384 = cons(stack[0], v_26384);
    env = stack[-14];
    v_26384 = ncons(v_26384);
    env = stack[-14];
    stack[-3] = v_26384;
    stack[-4] = v_26384;
v_25897:
    v_26384 = stack[-5];
    v_26384 = qcdr(v_26384);
    stack[-5] = v_26384;
    v_26384 = stack[-5];
    if (v_26384 == nil) goto v_25948;
    else goto v_25949;
v_25948:
    v_26384 = stack[-4];
    goto v_25896;
v_25949:
    goto v_25957;
v_25953:
    stack[-2] = stack[-3];
    goto v_25954;
v_25955:
    v_26384 = stack[-5];
    v_26384 = qcar(v_26384);
    stack[-1] = v_26384;
    goto v_25970;
v_25964:
    v_26384 = stack[-1];
    v_26386 = qcar(v_26384);
    goto v_25965;
v_25966:
    v_26384 = stack[-1];
    v_26384 = qcdr(v_26384);
    v_26385 = qcdr(v_26384);
    goto v_25967;
v_25968:
    v_26384 = stack[-6];
    goto v_25969;
v_25970:
    goto v_25964;
v_25965:
    goto v_25966;
v_25967:
    goto v_25968;
v_25969:
    v_26384 = acons(v_26386, v_26385, v_26384);
    env = stack[-14];
    stack[-6] = v_26384;
    goto v_25982;
v_25978:
    v_26384 = stack[-1];
    stack[0] = qcar(v_26384);
    goto v_25979;
v_25980:
    goto v_25990;
v_25986:
    v_26384 = stack[-1];
    v_26384 = qcdr(v_26384);
    v_26385 = qcar(v_26384);
    goto v_25987;
v_25988:
    v_26384 = stack[-1];
    v_26384 = qcdr(v_26384);
    v_26384 = qcdr(v_26384);
    goto v_25989;
v_25990:
    goto v_25986;
v_25987:
    goto v_25988;
v_25989:
    v_26384 = difference2(v_26385, v_26384);
    env = stack[-14];
    goto v_25981;
v_25982:
    goto v_25978;
v_25979:
    goto v_25980;
v_25981:
    v_26384 = cons(stack[0], v_26384);
    env = stack[-14];
    v_26384 = ncons(v_26384);
    env = stack[-14];
    goto v_25956;
v_25957:
    goto v_25953;
v_25954:
    goto v_25955;
v_25956:
    v_26384 = Lrplacd(nil, stack[-2], v_26384);
    env = stack[-14];
    v_26384 = stack[-3];
    v_26384 = qcdr(v_26384);
    stack[-3] = v_26384;
    goto v_25897;
v_25896:
    stack[0] = v_26384;
    v_26384 = stack[-7];
    v_26384 = qcar(v_26384);
    fn = elt(env, 8); // numeric!-content
    v_26384 = (*qfn1(fn))(fn, v_26384);
    env = stack[-14];
    stack[-1] = v_26384;
    v_26384 = stack[-12];
    if (v_26384 == nil) goto v_26004;
    else goto v_26005;
v_26004:
    v_26384 = stack[-6];
    stack[-13] = v_26384;
    v_26384 = stack[-1];
    stack[-12] = v_26384;
    goto v_26003;
v_26005:
    goto v_26016;
v_26012:
    v_26385 = stack[-13];
    goto v_26013;
v_26014:
    v_26384 = stack[-6];
    goto v_26015;
v_26016:
    goto v_26012;
v_26013:
    goto v_26014;
v_26015:
    fn = elt(env, 9); // vintersection
    v_26384 = (*qfn2(fn))(fn, v_26385, v_26384);
    env = stack[-14];
    stack[-13] = v_26384;
    goto v_26024;
v_26020:
    v_26385 = stack[-12];
    goto v_26021;
v_26022:
    v_26384 = stack[-1];
    goto v_26023;
v_26024:
    goto v_26020;
v_26021:
    goto v_26022;
v_26023:
    fn = elt(env, 10); // gcddd
    v_26384 = (*qfn2(fn))(fn, v_26385, v_26384);
    env = stack[-14];
    stack[-12] = v_26384;
    goto v_26003;
v_26003:
    v_26384 = stack[-6];
    stack[-2] = v_26384;
v_26030:
    v_26384 = stack[-2];
    if (v_26384 == nil) goto v_26034;
    else goto v_26035;
v_26034:
    goto v_26029;
v_26035:
    v_26384 = stack[-2];
    v_26384 = qcar(v_26384);
    v_26386 = v_26384;
    goto v_26049;
v_26045:
    v_26384 = v_26386;
    v_26385 = qcdr(v_26384);
    goto v_26046;
v_26047:
    v_26384 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_26048;
v_26049:
    goto v_26045;
v_26046:
    goto v_26047;
v_26048:
    if (v_26385 == v_26384) goto v_26044;
    goto v_26058;
v_26054:
    goto v_26055;
v_26056:
    goto v_26066;
v_26062:
    goto v_26072;
v_26068:
    v_26384 = v_26386;
    v_26384 = qcar(v_26384);
    goto v_26069;
v_26070:
    v_26385 = v_26386;
    v_26385 = qcdr(v_26385);
    goto v_26071;
v_26072:
    goto v_26068;
v_26069:
    goto v_26070;
v_26071:
    fn = elt(env, 11); // mksp
    v_26385 = (*qfn2(fn))(fn, v_26384, v_26385);
    env = stack[-14];
    goto v_26063;
v_26064:
    v_26384 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26065;
v_26066:
    goto v_26062;
v_26063:
    goto v_26064;
v_26065:
    v_26384 = cons(v_26385, v_26384);
    env = stack[-14];
    v_26384 = ncons(v_26384);
    env = stack[-14];
    goto v_26057;
v_26058:
    goto v_26054;
v_26055:
    goto v_26056;
v_26057:
    fn = elt(env, 12); // multf
    v_26384 = (*qfn2(fn))(fn, stack[-1], v_26384);
    env = stack[-14];
    stack[-1] = v_26384;
    goto v_26042;
v_26044:
v_26042:
    v_26384 = stack[-2];
    v_26384 = qcdr(v_26384);
    stack[-2] = v_26384;
    goto v_26030;
v_26029:
    goto v_26085;
v_26081:
    goto v_26093;
v_26087:
    v_26384 = stack[-7];
    v_26386 = qcar(v_26384);
    goto v_26088;
v_26089:
    v_26385 = stack[-1];
    goto v_26090;
v_26091:
    v_26384 = elt(env, 3); // "Term content division failed"
    goto v_26092;
v_26093:
    goto v_26087;
v_26088:
    goto v_26089;
v_26090:
    goto v_26091;
v_26092:
    fn = elt(env, 13); // quotfail1
    v_26385 = (*qfnn(fn))(fn, 3, v_26386, v_26385, v_26384);
    env = stack[-14];
    goto v_26082;
v_26083:
    v_26384 = stack[0];
    goto v_26084;
v_26085:
    goto v_26081;
v_26082:
    goto v_26083;
v_26084:
    v_26384 = cons(v_26385, v_26384);
    env = stack[-14];
    v_26384 = ncons(v_26384);
    env = stack[-14];
    stack[-9] = v_26384;
    stack[-10] = v_26384;
v_25874:
    v_26384 = stack[-11];
    v_26384 = qcdr(v_26384);
    stack[-11] = v_26384;
    v_26384 = stack[-11];
    if (v_26384 == nil) goto v_26103;
    else goto v_26104;
v_26103:
    v_26384 = stack[-10];
    goto v_25873;
v_26104:
    goto v_26112;
v_26108:
    stack[-8] = stack[-9];
    goto v_26109;
v_26110:
    v_26384 = stack[-11];
    v_26384 = qcar(v_26384);
    stack[-7] = v_26384;
    stack[-6] = nil;
    v_26384 = stack[-7];
    v_26384 = qcdr(v_26384);
    stack[-5] = v_26384;
    v_26384 = stack[-5];
    if (v_26384 == nil) goto v_26134;
    else goto v_26135;
v_26134:
    v_26384 = nil;
    goto v_26128;
v_26135:
    v_26384 = stack[-5];
    v_26384 = qcar(v_26384);
    stack[-1] = v_26384;
    goto v_26149;
v_26143:
    v_26384 = stack[-1];
    v_26386 = qcar(v_26384);
    goto v_26144;
v_26145:
    v_26384 = stack[-1];
    v_26384 = qcdr(v_26384);
    v_26385 = qcdr(v_26384);
    goto v_26146;
v_26147:
    v_26384 = stack[-6];
    goto v_26148;
v_26149:
    goto v_26143;
v_26144:
    goto v_26145;
v_26146:
    goto v_26147;
v_26148:
    v_26384 = acons(v_26386, v_26385, v_26384);
    env = stack[-14];
    stack[-6] = v_26384;
    goto v_26161;
v_26157:
    v_26384 = stack[-1];
    stack[0] = qcar(v_26384);
    goto v_26158;
v_26159:
    goto v_26169;
v_26165:
    v_26384 = stack[-1];
    v_26384 = qcdr(v_26384);
    v_26385 = qcar(v_26384);
    goto v_26166;
v_26167:
    v_26384 = stack[-1];
    v_26384 = qcdr(v_26384);
    v_26384 = qcdr(v_26384);
    goto v_26168;
v_26169:
    goto v_26165;
v_26166:
    goto v_26167;
v_26168:
    v_26384 = difference2(v_26385, v_26384);
    env = stack[-14];
    goto v_26160;
v_26161:
    goto v_26157;
v_26158:
    goto v_26159;
v_26160:
    v_26384 = cons(stack[0], v_26384);
    env = stack[-14];
    v_26384 = ncons(v_26384);
    env = stack[-14];
    stack[-3] = v_26384;
    stack[-4] = v_26384;
v_26129:
    v_26384 = stack[-5];
    v_26384 = qcdr(v_26384);
    stack[-5] = v_26384;
    v_26384 = stack[-5];
    if (v_26384 == nil) goto v_26180;
    else goto v_26181;
v_26180:
    v_26384 = stack[-4];
    goto v_26128;
v_26181:
    goto v_26189;
v_26185:
    stack[-2] = stack[-3];
    goto v_26186;
v_26187:
    v_26384 = stack[-5];
    v_26384 = qcar(v_26384);
    stack[-1] = v_26384;
    goto v_26202;
v_26196:
    v_26384 = stack[-1];
    v_26386 = qcar(v_26384);
    goto v_26197;
v_26198:
    v_26384 = stack[-1];
    v_26384 = qcdr(v_26384);
    v_26385 = qcdr(v_26384);
    goto v_26199;
v_26200:
    v_26384 = stack[-6];
    goto v_26201;
v_26202:
    goto v_26196;
v_26197:
    goto v_26198;
v_26199:
    goto v_26200;
v_26201:
    v_26384 = acons(v_26386, v_26385, v_26384);
    env = stack[-14];
    stack[-6] = v_26384;
    goto v_26214;
v_26210:
    v_26384 = stack[-1];
    stack[0] = qcar(v_26384);
    goto v_26211;
v_26212:
    goto v_26222;
v_26218:
    v_26384 = stack[-1];
    v_26384 = qcdr(v_26384);
    v_26385 = qcar(v_26384);
    goto v_26219;
v_26220:
    v_26384 = stack[-1];
    v_26384 = qcdr(v_26384);
    v_26384 = qcdr(v_26384);
    goto v_26221;
v_26222:
    goto v_26218;
v_26219:
    goto v_26220;
v_26221:
    v_26384 = difference2(v_26385, v_26384);
    env = stack[-14];
    goto v_26213;
v_26214:
    goto v_26210;
v_26211:
    goto v_26212;
v_26213:
    v_26384 = cons(stack[0], v_26384);
    env = stack[-14];
    v_26384 = ncons(v_26384);
    env = stack[-14];
    goto v_26188;
v_26189:
    goto v_26185;
v_26186:
    goto v_26187;
v_26188:
    v_26384 = Lrplacd(nil, stack[-2], v_26384);
    env = stack[-14];
    v_26384 = stack[-3];
    v_26384 = qcdr(v_26384);
    stack[-3] = v_26384;
    goto v_26129;
v_26128:
    stack[0] = v_26384;
    v_26384 = stack[-7];
    v_26384 = qcar(v_26384);
    fn = elt(env, 8); // numeric!-content
    v_26384 = (*qfn1(fn))(fn, v_26384);
    env = stack[-14];
    stack[-1] = v_26384;
    v_26384 = stack[-12];
    if (v_26384 == nil) goto v_26236;
    else goto v_26237;
v_26236:
    v_26384 = stack[-6];
    stack[-13] = v_26384;
    v_26384 = stack[-1];
    stack[-12] = v_26384;
    goto v_26235;
v_26237:
    goto v_26248;
v_26244:
    v_26385 = stack[-13];
    goto v_26245;
v_26246:
    v_26384 = stack[-6];
    goto v_26247;
v_26248:
    goto v_26244;
v_26245:
    goto v_26246;
v_26247:
    fn = elt(env, 9); // vintersection
    v_26384 = (*qfn2(fn))(fn, v_26385, v_26384);
    env = stack[-14];
    stack[-13] = v_26384;
    goto v_26256;
v_26252:
    v_26385 = stack[-12];
    goto v_26253;
v_26254:
    v_26384 = stack[-1];
    goto v_26255;
v_26256:
    goto v_26252;
v_26253:
    goto v_26254;
v_26255:
    fn = elt(env, 10); // gcddd
    v_26384 = (*qfn2(fn))(fn, v_26385, v_26384);
    env = stack[-14];
    stack[-12] = v_26384;
    goto v_26235;
v_26235:
    v_26384 = stack[-6];
    stack[-2] = v_26384;
v_26262:
    v_26384 = stack[-2];
    if (v_26384 == nil) goto v_26266;
    else goto v_26267;
v_26266:
    goto v_26261;
v_26267:
    v_26384 = stack[-2];
    v_26384 = qcar(v_26384);
    v_26386 = v_26384;
    goto v_26281;
v_26277:
    v_26384 = v_26386;
    v_26385 = qcdr(v_26384);
    goto v_26278;
v_26279:
    v_26384 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_26280;
v_26281:
    goto v_26277;
v_26278:
    goto v_26279;
v_26280:
    if (v_26385 == v_26384) goto v_26276;
    goto v_26290;
v_26286:
    goto v_26287;
v_26288:
    goto v_26298;
v_26294:
    goto v_26304;
v_26300:
    v_26384 = v_26386;
    v_26384 = qcar(v_26384);
    goto v_26301;
v_26302:
    v_26385 = v_26386;
    v_26385 = qcdr(v_26385);
    goto v_26303;
v_26304:
    goto v_26300;
v_26301:
    goto v_26302;
v_26303:
    fn = elt(env, 11); // mksp
    v_26385 = (*qfn2(fn))(fn, v_26384, v_26385);
    env = stack[-14];
    goto v_26295;
v_26296:
    v_26384 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26297;
v_26298:
    goto v_26294;
v_26295:
    goto v_26296;
v_26297:
    v_26384 = cons(v_26385, v_26384);
    env = stack[-14];
    v_26384 = ncons(v_26384);
    env = stack[-14];
    goto v_26289;
v_26290:
    goto v_26286;
v_26287:
    goto v_26288;
v_26289:
    fn = elt(env, 12); // multf
    v_26384 = (*qfn2(fn))(fn, stack[-1], v_26384);
    env = stack[-14];
    stack[-1] = v_26384;
    goto v_26274;
v_26276:
v_26274:
    v_26384 = stack[-2];
    v_26384 = qcdr(v_26384);
    stack[-2] = v_26384;
    goto v_26262;
v_26261:
    goto v_26317;
v_26313:
    goto v_26325;
v_26319:
    v_26384 = stack[-7];
    v_26386 = qcar(v_26384);
    goto v_26320;
v_26321:
    v_26385 = stack[-1];
    goto v_26322;
v_26323:
    v_26384 = elt(env, 3); // "Term content division failed"
    goto v_26324;
v_26325:
    goto v_26319;
v_26320:
    goto v_26321;
v_26322:
    goto v_26323;
v_26324:
    fn = elt(env, 13); // quotfail1
    v_26385 = (*qfnn(fn))(fn, 3, v_26386, v_26385, v_26384);
    env = stack[-14];
    goto v_26314;
v_26315:
    v_26384 = stack[0];
    goto v_26316;
v_26317:
    goto v_26313;
v_26314:
    goto v_26315;
v_26316:
    v_26384 = cons(v_26385, v_26384);
    env = stack[-14];
    v_26384 = ncons(v_26384);
    env = stack[-14];
    goto v_26111;
v_26112:
    goto v_26108;
v_26109:
    goto v_26110;
v_26111:
    v_26384 = Lrplacd(nil, stack[-8], v_26384);
    env = stack[-14];
    v_26384 = stack[-9];
    v_26384 = qcdr(v_26384);
    stack[-9] = v_26384;
    goto v_25874;
v_25873:
    stack[0] = v_26384;
    v_26384 = stack[-13];
    stack[-1] = v_26384;
v_26336:
    v_26384 = stack[-1];
    if (v_26384 == nil) goto v_26340;
    else goto v_26341;
v_26340:
    goto v_26335;
v_26341:
    v_26384 = stack[-1];
    v_26384 = qcar(v_26384);
    goto v_26352;
v_26348:
    stack[-2] = stack[-12];
    goto v_26349;
v_26350:
    goto v_26360;
v_26356:
    goto v_26366;
v_26362:
    v_26385 = v_26384;
    v_26385 = qcar(v_26385);
    goto v_26363;
v_26364:
    v_26384 = qcdr(v_26384);
    goto v_26365;
v_26366:
    goto v_26362;
v_26363:
    goto v_26364;
v_26365:
    fn = elt(env, 11); // mksp
    v_26385 = (*qfn2(fn))(fn, v_26385, v_26384);
    env = stack[-14];
    goto v_26357;
v_26358:
    v_26384 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26359;
v_26360:
    goto v_26356;
v_26357:
    goto v_26358;
v_26359:
    v_26384 = cons(v_26385, v_26384);
    env = stack[-14];
    v_26384 = ncons(v_26384);
    env = stack[-14];
    goto v_26351;
v_26352:
    goto v_26348;
v_26349:
    goto v_26350;
v_26351:
    fn = elt(env, 12); // multf
    v_26384 = (*qfn2(fn))(fn, stack[-2], v_26384);
    env = stack[-14];
    stack[-12] = v_26384;
    v_26384 = stack[-1];
    v_26384 = qcdr(v_26384);
    stack[-1] = v_26384;
    goto v_26336;
v_26335:
    goto v_26380;
v_26376:
    stack[-1] = stack[-12];
    goto v_26377;
v_26378:
    v_26384 = stack[0];
    fn = elt(env, 14); // gcdlist1
    v_26384 = (*qfn1(fn))(fn, v_26384);
    env = stack[-14];
    goto v_26379;
v_26380:
    goto v_26376;
v_26377:
    goto v_26378;
v_26379:
    fn = elt(env, 12); // multf
    v_26384 = (*qfn2(fn))(fn, stack[-1], v_26384);
    env = stack[-14];
    {
        fn = elt(env, 4); // poly!-abs
        return (*qfn1(fn))(fn, v_26384);
    }
v_25780:
    goto v_25737;
    v_26384 = nil;
v_25737:
    return onevalue(v_26384);
}



// Code for gigcdsq

static LispObject CC_gigcdsq(LispObject env,
                         LispObject v_25734, LispObject v_25735)
{
    env = qenv(env);
    LispObject v_25808, v_25809;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25735,v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25734,v_25735);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_25735;
    stack[-1] = v_25734;
// end of prologue
    v_25808 = stack[-1];
    if (v_25808 == nil) goto v_25740;
    goto v_25747;
v_25743:
    v_25809 = stack[0];
    goto v_25744;
v_25745:
    v_25808 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25746;
v_25747:
    goto v_25743;
v_25744:
    goto v_25745;
v_25746:
    fn = elt(env, 1); // giintgcd
    v_25808 = (*qfn2(fn))(fn, v_25809, v_25808);
    env = stack[-3];
    stack[-2] = v_25808;
    goto v_25763;
v_25759:
    v_25809 = stack[-2];
    goto v_25760;
v_25761:
    v_25808 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25762;
v_25763:
    goto v_25759;
v_25760:
    goto v_25761;
v_25762:
    if (v_25809 == v_25808) goto v_25758;
    goto v_25771;
v_25767:
    goto v_25777;
v_25773:
    v_25809 = stack[-1];
    goto v_25774;
v_25775:
    v_25808 = stack[-2];
    goto v_25776;
v_25777:
    goto v_25773;
v_25774:
    goto v_25775;
v_25776:
    fn = elt(env, 1); // giintgcd
    v_25809 = (*qfn2(fn))(fn, v_25809, v_25808);
    env = stack[-3];
    stack[-2] = v_25809;
    goto v_25768;
v_25769:
    v_25808 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25770;
v_25771:
    goto v_25767;
v_25768:
    goto v_25769;
v_25770:
    v_25808 = Lneq(nil, v_25809, v_25808);
    env = stack[-3];
    goto v_25756;
v_25758:
    v_25808 = nil;
    goto v_25756;
    v_25808 = nil;
v_25756:
    if (v_25808 == nil) goto v_25754;
    goto v_25789;
v_25785:
    v_25809 = stack[-1];
    goto v_25786;
v_25787:
    v_25808 = stack[-2];
    goto v_25788;
v_25789:
    goto v_25785;
v_25786:
    goto v_25787;
v_25788:
    fn = elt(env, 2); // quotf
    v_25808 = (*qfn2(fn))(fn, v_25809, v_25808);
    env = stack[-3];
    stack[-1] = v_25808;
    goto v_25797;
v_25793:
    v_25809 = stack[0];
    goto v_25794;
v_25795:
    v_25808 = stack[-2];
    goto v_25796;
v_25797:
    goto v_25793;
v_25794:
    goto v_25795;
v_25796:
    fn = elt(env, 2); // quotf
    v_25808 = (*qfn2(fn))(fn, v_25809, v_25808);
    stack[0] = v_25808;
    goto v_25752;
v_25754:
v_25752:
    goto v_25738;
v_25740:
v_25738:
    goto v_25805;
v_25801:
    v_25809 = stack[-1];
    goto v_25802;
v_25803:
    v_25808 = stack[0];
    goto v_25804;
v_25805:
    goto v_25801;
v_25802:
    goto v_25803;
v_25804:
    return cons(v_25809, v_25808);
}



// Code for conditionml

static LispObject CC_conditionml(LispObject env,
                         LispObject v_25734)
{
    env = qenv(env);
    LispObject v_25750;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25734);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_25734;
// end of prologue
    v_25750 = elt(env, 1); // "<condition>"
    fn = elt(env, 3); // printout
    v_25750 = (*qfn1(fn))(fn, v_25750);
    env = stack[-1];
    v_25750 = lisp_true;
    fn = elt(env, 4); // indent!*
    v_25750 = (*qfn1(fn))(fn, v_25750);
    env = stack[-1];
    v_25750 = stack[0];
    v_25750 = qcar(v_25750);
    fn = elt(env, 5); // expression
    v_25750 = (*qfn1(fn))(fn, v_25750);
    env = stack[-1];
    v_25750 = nil;
    fn = elt(env, 4); // indent!*
    v_25750 = (*qfn1(fn))(fn, v_25750);
    env = stack[-1];
    v_25750 = elt(env, 2); // "</condition>"
    fn = elt(env, 3); // printout
    v_25750 = (*qfn1(fn))(fn, v_25750);
    v_25750 = nil;
    return onevalue(v_25750);
}



// Code for ieval

static LispObject CC_ieval(LispObject env,
                         LispObject v_25734)
{
    env = qenv(env);
    LispObject v_25739;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25734);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_25739 = v_25734;
// end of prologue
    fn = elt(env, 1); // reval
    v_25739 = (*qfn1(fn))(fn, v_25739);
    env = stack[0];
    {
        fn = elt(env, 2); // !*s2i
        return (*qfn1(fn))(fn, v_25739);
    }
}



// Code for znumrnil

static LispObject CC_znumrnil(LispObject env,
                         LispObject v_25734)
{
    env = qenv(env);
    LispObject v_25753, v_25754;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25734);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_25734;
// end of prologue
    v_25753 = stack[0];
    fn = elt(env, 1); // znumr
    v_25753 = (*qfn1(fn))(fn, v_25753);
    if (v_25753 == nil) goto v_25739;
    goto v_25747;
v_25743:
    v_25754 = nil;
    goto v_25744;
v_25745:
    v_25753 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25746;
v_25747:
    goto v_25743;
v_25744:
    goto v_25745;
v_25746:
    return cons(v_25754, v_25753);
v_25739:
    v_25753 = stack[0];
    goto v_25737;
    v_25753 = nil;
v_25737:
    return onevalue(v_25753);
}



// Code for diford

static LispObject CC_diford(LispObject env,
                         LispObject v_25734)
{
    env = qenv(env);
    LispObject v_25740;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_25740 = v_25734;
// end of prologue
    v_25740 = qcdr(v_25740);
    v_25740 = qcdr(v_25740);
    {
        fn = elt(env, 1); // lengthn
        return (*qfn1(fn))(fn, v_25740);
    }
}



// Code for letmtr

static LispObject CC_letmtr(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25832, v_25833, v_25834;
    LispObject fn;
    LispObject v_25736, v_25735, v_25734;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "letmtr");
    va_start(aa, nargs);
    v_25734 = va_arg(aa, LispObject);
    v_25735 = va_arg(aa, LispObject);
    v_25736 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_25736,v_25735,v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_25734,v_25735,v_25736);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_25736;
    stack[-3] = v_25735;
    stack[-4] = v_25734;
// end of prologue
    stack[-5] = nil;
    goto v_25751;
v_25747:
    v_25833 = stack[-2];
    goto v_25748;
v_25749:
    v_25832 = elt(env, 2); // mat
    goto v_25750;
v_25751:
    goto v_25747;
v_25748:
    goto v_25749;
v_25750:
    if (!consp(v_25833)) goto v_25744;
    v_25833 = qcar(v_25833);
    if (v_25833 == v_25832) goto v_25745;
v_25744:
    goto v_25761;
v_25755:
    stack[-1] = elt(env, 3); // matrix
    goto v_25756;
v_25757:
    stack[0] = (LispObject)160+TAG_FIXNUM; // 10
    goto v_25758;
v_25759:
    goto v_25771;
v_25765:
    v_25834 = elt(env, 4); // "Matrix"
    goto v_25766;
v_25767:
    v_25832 = stack[-4];
    v_25833 = qcar(v_25832);
    goto v_25768;
v_25769:
    v_25832 = elt(env, 5); // "not set"
    goto v_25770;
v_25771:
    goto v_25765;
v_25766:
    goto v_25767;
v_25768:
    goto v_25769;
v_25770:
    v_25832 = list3(v_25834, v_25833, v_25832);
    env = stack[-6];
    goto v_25760;
v_25761:
    goto v_25755;
v_25756:
    goto v_25757;
v_25758:
    goto v_25759;
v_25760:
    fn = elt(env, 7); // rerror
    v_25832 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_25832);
    env = stack[-6];
    goto v_25743;
v_25745:
    v_25832 = stack[-4];
    v_25832 = qcdr(v_25832);
    fn = elt(env, 8); // revlis
    v_25832 = (*qfn1(fn))(fn, v_25832);
    env = stack[-6];
    stack[-5] = v_25832;
    fn = elt(env, 9); // numlis
    v_25832 = (*qfn1(fn))(fn, v_25832);
    env = stack[-6];
    if (v_25832 == nil) goto v_25780;
    else goto v_25781;
v_25780:
    v_25832 = lisp_true;
    goto v_25779;
v_25781:
    goto v_25794;
v_25790:
    v_25832 = stack[-5];
    v_25833 = Llength(nil, v_25832);
    env = stack[-6];
    goto v_25791;
v_25792:
    v_25832 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_25793;
v_25794:
    goto v_25790;
v_25791:
    goto v_25792;
v_25793:
    v_25832 = Lneq(nil, v_25833, v_25832);
    env = stack[-6];
    goto v_25779;
    v_25832 = nil;
v_25779:
    if (v_25832 == nil) goto v_25777;
    goto v_25803;
v_25799:
    v_25833 = stack[-4];
    goto v_25800;
v_25801:
    v_25832 = elt(env, 6); // hold
    goto v_25802;
v_25803:
    goto v_25799;
v_25800:
    goto v_25801;
v_25802:
    {
        fn = elt(env, 10); // errpri2
        return (*qfn2(fn))(fn, v_25833, v_25832);
    }
v_25777:
v_25743:
    goto v_25811;
v_25807:
    goto v_25817;
v_25813:
    goto v_25823;
v_25819:
    v_25832 = stack[-2];
    v_25833 = qcdr(v_25832);
    goto v_25820;
v_25821:
    v_25832 = stack[-5];
    v_25832 = qcar(v_25832);
    goto v_25822;
v_25823:
    goto v_25819;
v_25820:
    goto v_25821;
v_25822:
    fn = elt(env, 11); // nth
    v_25833 = (*qfn2(fn))(fn, v_25833, v_25832);
    env = stack[-6];
    goto v_25814;
v_25815:
    v_25832 = stack[-5];
    v_25832 = qcdr(v_25832);
    v_25832 = qcar(v_25832);
    goto v_25816;
v_25817:
    goto v_25813;
v_25814:
    goto v_25815;
v_25816:
    fn = elt(env, 12); // pnth
    v_25833 = (*qfn2(fn))(fn, v_25833, v_25832);
    env = stack[-6];
    goto v_25808;
v_25809:
    v_25832 = stack[-3];
    goto v_25810;
v_25811:
    goto v_25807;
v_25808:
    goto v_25809;
v_25810:
    v_25832 = Lrplaca(nil, v_25833, v_25832);
    v_25832 = nil;
    return onevalue(v_25832);
}



// Code for evalmember

static LispObject CC_evalmember(LispObject env,
                         LispObject v_25734, LispObject v_25735)
{
    env = qenv(env);
    LispObject v_25746, v_25747;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25735,v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25734,v_25735);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_25746 = v_25735;
    v_25747 = v_25734;
// end of prologue
    goto v_25741;
v_25737:
    stack[0] = v_25747;
    goto v_25738;
v_25739:
    fn = elt(env, 1); // getrlist
    v_25746 = (*qfn1(fn))(fn, v_25746);
    goto v_25740;
v_25741:
    goto v_25737;
v_25738:
    goto v_25739;
v_25740:
    v_25746 = Lmember(nil, stack[0], v_25746);
    return onevalue(v_25746);
}



// Code for gpargp

static LispObject CC_gpargp(LispObject env,
                         LispObject v_25734)
{
    env = qenv(env);
    LispObject v_25748;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25734);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_25734;
// end of prologue
    v_25748 = stack[0];
    v_25748 = Lstringp(nil, v_25748);
    env = stack[-1];
    if (v_25748 == nil) goto v_25738;
    else goto v_25737;
v_25738:
    v_25748 = stack[0];
    fn = elt(env, 1); // gpexpp
    v_25748 = (*qfn1(fn))(fn, v_25748);
    env = stack[-1];
    if (v_25748 == nil) goto v_25743;
    else goto v_25742;
v_25743:
    v_25748 = stack[0];
    {
        fn = elt(env, 2); // gplogexpp
        return (*qfn1(fn))(fn, v_25748);
    }
v_25742:
v_25737:
    return onevalue(v_25748);
}



// Code for extract_vars

static LispObject CC_extract_vars(LispObject env,
                         LispObject v_25734)
{
    env = qenv(env);
    LispObject v_25774, v_25775;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25734);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_25734;
// end of prologue
    stack[-1] = nil;
v_25739:
    v_25774 = stack[0];
    if (v_25774 == nil) goto v_25742;
    else goto v_25743;
v_25742:
    v_25774 = stack[-1];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_25774);
    }
v_25743:
    goto v_25754;
v_25750:
    v_25774 = stack[0];
    v_25774 = qcar(v_25774);
    fn = elt(env, 3); // raiseind!:
    v_25775 = (*qfn1(fn))(fn, v_25774);
    env = stack[-2];
    goto v_25751;
v_25752:
    v_25774 = elt(env, 1); // variable
    goto v_25753;
v_25754:
    goto v_25750;
v_25751:
    goto v_25752;
v_25753:
    v_25774 = Lflagp(nil, v_25775, v_25774);
    env = stack[-2];
    if (v_25774 == nil) goto v_25748;
    goto v_25764;
v_25760:
    v_25774 = stack[0];
    v_25775 = qcar(v_25774);
    goto v_25761;
v_25762:
    v_25774 = stack[-1];
    goto v_25763;
v_25764:
    goto v_25760;
v_25761:
    goto v_25762;
v_25763:
    v_25774 = cons(v_25775, v_25774);
    env = stack[-2];
    stack[-1] = v_25774;
    v_25774 = stack[0];
    v_25774 = qcdr(v_25774);
    stack[0] = v_25774;
    goto v_25739;
v_25748:
    v_25774 = stack[0];
    v_25774 = qcdr(v_25774);
    stack[0] = v_25774;
    goto v_25739;
    v_25774 = nil;
    return onevalue(v_25774);
}



// Code for rat_leq

static LispObject CC_rat_leq(LispObject env,
                         LispObject v_25734, LispObject v_25735)
{
    env = qenv(env);
    LispObject v_25754, v_25755;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25735,v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25734,v_25735);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_25754 = v_25735;
    v_25755 = v_25734;
// end of prologue
    goto v_25742;
v_25738:
    goto v_25749;
v_25745:
    stack[0] = v_25755;
    goto v_25746;
v_25747:
    fn = elt(env, 1); // negsq
    v_25754 = (*qfn1(fn))(fn, v_25754);
    env = stack[-1];
    goto v_25748;
v_25749:
    goto v_25745;
v_25746:
    goto v_25747;
v_25748:
    fn = elt(env, 2); // addsq
    v_25754 = (*qfn2(fn))(fn, stack[0], v_25754);
    env = stack[-1];
    fn = elt(env, 3); // rat_sgn
    v_25755 = (*qfn1(fn))(fn, v_25754);
    goto v_25739;
v_25740:
    v_25754 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25741;
v_25742:
    goto v_25738;
v_25739:
    goto v_25740;
v_25741:
        return Llessp(nil, v_25755, v_25754);
}



// Code for ofsf_simplequal

static LispObject CC_ofsf_simplequal(LispObject env,
                         LispObject v_25734, LispObject v_25735)
{
    env = qenv(env);
    LispObject v_25827, v_25828, v_25829;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25735,v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25734,v_25735);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_25735;
    stack[-2] = v_25734;
// end of prologue
    v_25827 = stack[-2];
    fn = elt(env, 9); // ofsf_posdefp
    v_25827 = (*qfn1(fn))(fn, v_25827);
    env = stack[-4];
    stack[-3] = v_25827;
    goto v_25753;
v_25749:
    v_25828 = stack[-3];
    goto v_25750;
v_25751:
    v_25827 = elt(env, 2); // stsq
    goto v_25752;
v_25753:
    goto v_25749;
v_25750:
    goto v_25751;
v_25752:
    if (v_25828 == v_25827) goto v_25747;
    else goto v_25748;
v_25747:
    v_25827 = elt(env, 3); // false
    goto v_25741;
v_25748:
    v_25827 = stack[-2];
    fn = elt(env, 10); // sfto_sqfpartf
    v_25827 = (*qfn1(fn))(fn, v_25827);
    env = stack[-4];
    stack[0] = v_25827;
    v_25827 = stack[0];
    fn = elt(env, 9); // ofsf_posdefp
    v_25827 = (*qfn1(fn))(fn, v_25827);
    env = stack[-4];
    v_25829 = v_25827;
    goto v_25769;
v_25765:
    v_25828 = v_25829;
    goto v_25766;
v_25767:
    v_25827 = elt(env, 2); // stsq
    goto v_25768;
v_25769:
    goto v_25765;
v_25766:
    goto v_25767;
v_25768:
    if (v_25828 == v_25827) goto v_25763;
    else goto v_25764;
v_25763:
    v_25827 = elt(env, 3); // false
    goto v_25741;
v_25764:
    v_25827 = qvalue(elt(env, 4)); // !*rlsitsqspl
    if (v_25827 == nil) goto v_25776;
    v_25827 = qvalue(elt(env, 5)); // !*rlsiexpla
    if (v_25827 == nil) goto v_25780;
    else goto v_25779;
v_25780:
    v_25827 = qvalue(elt(env, 6)); // !*rlsiexpl
    if (v_25827 == nil) goto v_25782;
    goto v_25790;
v_25786:
    v_25828 = stack[-1];
    goto v_25787;
v_25788:
    v_25827 = elt(env, 7); // and
    goto v_25789;
v_25790:
    goto v_25786;
v_25787:
    goto v_25788;
v_25789:
    if (v_25828 == v_25827) goto v_25785;
    else goto v_25782;
v_25785:
    goto v_25779;
v_25782:
    goto v_25776;
v_25779:
    goto v_25801;
v_25797:
    v_25828 = v_25829;
    goto v_25798;
v_25799:
    v_25827 = elt(env, 8); // tsq
    goto v_25800;
v_25801:
    goto v_25797;
v_25798:
    goto v_25799;
v_25800:
    if (v_25828 == v_25827) goto v_25795;
    else goto v_25796;
v_25795:
    v_25827 = stack[0];
    {
        fn = elt(env, 11); // ofsf_tsqsplequal
        return (*qfn1(fn))(fn, v_25827);
    }
v_25796:
    goto v_25814;
v_25810:
    v_25828 = stack[-3];
    goto v_25811;
v_25812:
    v_25827 = elt(env, 8); // tsq
    goto v_25813;
v_25814:
    goto v_25810;
v_25811:
    goto v_25812;
v_25813:
    if (v_25828 == v_25827) goto v_25808;
    else goto v_25809;
v_25808:
    v_25827 = stack[-2];
    {
        fn = elt(env, 11); // ofsf_tsqsplequal
        return (*qfn1(fn))(fn, v_25827);
    }
v_25809:
    goto v_25774;
v_25776:
v_25774:
    goto v_25824;
v_25820:
    v_25828 = stack[0];
    goto v_25821;
v_25822:
    v_25827 = stack[-1];
    goto v_25823;
v_25824:
    goto v_25820;
v_25821:
    goto v_25822;
v_25823:
    {
        fn = elt(env, 12); // ofsf_facequal!*
        return (*qfn2(fn))(fn, v_25828, v_25827);
    }
v_25741:
    return onevalue(v_25827);
}



// Code for simpexpt2

static LispObject CC_simpexpt2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_26379, v_26380, v_26381;
    LispObject fn;
    LispObject v_25736, v_25735, v_25734;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "simpexpt2");
    va_start(aa, nargs);
    v_25734 = va_arg(aa, LispObject);
    v_25735 = va_arg(aa, LispObject);
    v_25736 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_25736,v_25735,v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_25734,v_25735,v_25736);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_25736;
    stack[-2] = v_25735;
    stack[-3] = v_25734;
// end of prologue
v_25733:
    stack[0] = nil;
    goto v_25752;
v_25748:
    v_26380 = stack[-3];
    goto v_25749;
v_25750:
    v_26379 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25751;
v_25752:
    goto v_25748;
v_25749:
    goto v_25750;
v_25751:
    if (v_26380 == v_26379) goto v_25746;
    else goto v_25747;
v_25746:
    goto v_25760;
v_25756:
    v_26380 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25757;
v_25758:
    v_26379 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25759;
v_25760:
    goto v_25756;
v_25757:
    goto v_25758;
v_25759:
    return cons(v_26380, v_26379);
v_25747:
    v_26379 = stack[-2];
    v_26379 = qcar(v_26379);
    stack[-4] = v_26379;
    v_26379 = stack[-3];
    v_26379 = Lconsp(nil, v_26379);
    env = stack[-5];
    if (v_26379 == nil) goto v_25768;
    goto v_25783;
v_25779:
    v_26379 = stack[-3];
    v_26380 = qcar(v_26379);
    goto v_25780;
v_25781:
    v_26379 = elt(env, 2); // expt
    goto v_25782;
v_25783:
    goto v_25779;
v_25780:
    goto v_25781;
v_25782:
    if (v_26380 == v_26379) goto v_25777;
    else goto v_25778;
v_25777:
    v_26379 = qvalue(elt(env, 3)); // !*precise_complex
    v_26379 = (v_26379 == nil ? lisp_true : nil);
    goto v_25776;
v_25778:
    v_26379 = nil;
    goto v_25776;
    v_26379 = nil;
v_25776:
    if (v_26379 == nil) goto v_25774;
    goto v_25797;
v_25793:
    v_26379 = stack[-3];
    v_26379 = qcdr(v_26379);
    v_26379 = qcdr(v_26379);
    v_26379 = qcar(v_26379);
    fn = elt(env, 15); // simp
    v_26380 = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    stack[-4] = v_26380;
    goto v_25794;
v_25795:
    v_26379 = stack[-2];
    goto v_25796;
v_25797:
    goto v_25793;
v_25794:
    goto v_25795;
v_25796:
    fn = elt(env, 16); // multsq
    v_26379 = (*qfn2(fn))(fn, v_26380, v_26379);
    env = stack[-5];
    stack[-2] = v_26379;
    v_26379 = qvalue(elt(env, 4)); // !*precise
    if (v_26379 == nil) goto v_25807;
    v_26379 = stack[-4];
    v_26379 = qcar(v_26379);
    if (is_number(v_26379)) goto v_25811;
    else goto v_25807;
v_25811:
    v_26379 = stack[-4];
    v_26379 = qcar(v_26379);
    v_26379 = Levenp(nil, v_26379);
    env = stack[-5];
    if (v_26379 == nil) goto v_25807;
    goto v_25823;
v_25819:
    v_26380 = elt(env, 5); // abs
    goto v_25820;
v_25821:
    v_26379 = stack[-3];
    v_26379 = qcdr(v_26379);
    v_26379 = qcar(v_26379);
    goto v_25822;
v_25823:
    goto v_25819;
v_25820:
    goto v_25821;
v_25822:
    v_26379 = list2(v_26380, v_26379);
    env = stack[-5];
    stack[-3] = v_26379;
    goto v_25805;
v_25807:
    v_26379 = stack[-3];
    v_26379 = qcdr(v_26379);
    v_26379 = qcar(v_26379);
    stack[-3] = v_26379;
    goto v_25805;
v_25805:
    goto v_25840;
v_25834:
    v_26381 = stack[-3];
    goto v_25835;
v_25836:
    v_26380 = stack[-2];
    goto v_25837;
v_25838:
    v_26379 = stack[-1];
    goto v_25839;
v_25840:
    goto v_25834;
v_25835:
    goto v_25836;
v_25837:
    goto v_25838;
v_25839:
    {
        fn = elt(env, 17); // simpexpt1
        return (*qfnn(fn))(fn, 3, v_26381, v_26380, v_26379);
    }
v_25774:
    goto v_25854;
v_25850:
    v_26379 = stack[-3];
    v_26380 = qcar(v_26379);
    goto v_25851;
v_25852:
    v_26379 = elt(env, 6); // sqrt
    goto v_25853;
v_25854:
    goto v_25850;
v_25851:
    goto v_25852;
v_25853:
    if (v_26380 == v_26379) goto v_25848;
    else goto v_25849;
v_25848:
    v_26379 = qvalue(elt(env, 7)); // !*keepsqrts
    v_26379 = (v_26379 == nil ? lisp_true : nil);
    goto v_25847;
v_25849:
    v_26379 = nil;
    goto v_25847;
    v_26379 = nil;
v_25847:
    if (v_26379 == nil) goto v_25845;
    goto v_25870;
v_25864:
    v_26379 = stack[-3];
    v_26379 = qcdr(v_26379);
    stack[0] = qcar(v_26379);
    goto v_25865;
v_25866:
    goto v_25879;
v_25875:
    goto v_25885;
v_25881:
    v_26380 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25882;
v_25883:
    v_26379 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_25884;
v_25885:
    goto v_25881;
v_25882:
    goto v_25883;
v_25884:
    v_26380 = cons(v_26380, v_26379);
    env = stack[-5];
    goto v_25876;
v_25877:
    v_26379 = stack[-2];
    goto v_25878;
v_25879:
    goto v_25875;
v_25876:
    goto v_25877;
v_25878:
    fn = elt(env, 16); // multsq
    v_26380 = (*qfn2(fn))(fn, v_26380, v_26379);
    env = stack[-5];
    goto v_25867;
v_25868:
    v_26379 = stack[-1];
    goto v_25869;
v_25870:
    goto v_25864;
v_25865:
    goto v_25866;
v_25867:
    goto v_25868;
v_25869:
    stack[-3] = stack[0];
    stack[-2] = v_26380;
    stack[-1] = v_26379;
    goto v_25733;
v_25845:
    goto v_25900;
v_25896:
    v_26379 = stack[-3];
    v_26380 = qcar(v_26379);
    goto v_25897;
v_25898:
    v_26379 = elt(env, 8); // times
    goto v_25899;
v_25900:
    goto v_25896;
v_25897:
    goto v_25898;
v_25899:
    if (v_26380 == v_26379) goto v_25894;
    else goto v_25895;
v_25894:
    v_26379 = qvalue(elt(env, 4)); // !*precise
    if (v_26379 == nil) goto v_25906;
    else goto v_25907;
v_25906:
    v_26379 = qvalue(elt(env, 9)); // !*modular
    v_26379 = (v_26379 == nil ? lisp_true : nil);
    goto v_25905;
v_25907:
    v_26379 = nil;
    goto v_25905;
    v_26379 = nil;
v_25905:
    goto v_25893;
v_25895:
    v_26379 = nil;
    goto v_25893;
    v_26379 = nil;
v_25893:
    if (v_26379 == nil) goto v_25891;
    goto v_25922;
v_25918:
    v_26380 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25919;
v_25920:
    v_26379 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25921;
v_25922:
    goto v_25918;
v_25919:
    goto v_25920;
v_25921:
    v_26379 = cons(v_26380, v_26379);
    env = stack[-5];
    stack[-4] = v_26379;
    v_26379 = stack[-3];
    v_26379 = qcdr(v_26379);
    stack[0] = v_26379;
v_25928:
    v_26379 = stack[0];
    if (v_26379 == nil) goto v_25933;
    else goto v_25934;
v_25933:
    goto v_25927;
v_25934:
    v_26379 = stack[0];
    v_26379 = qcar(v_26379);
    goto v_25945;
v_25941:
    goto v_25953;
v_25947:
    v_26381 = v_26379;
    goto v_25948;
v_25949:
    v_26380 = stack[-2];
    goto v_25950;
v_25951:
    v_26379 = stack[-1];
    goto v_25952;
v_25953:
    goto v_25947;
v_25948:
    goto v_25949;
v_25950:
    goto v_25951;
v_25952:
    fn = elt(env, 17); // simpexpt1
    v_26380 = (*qfnn(fn))(fn, 3, v_26381, v_26380, v_26379);
    env = stack[-5];
    goto v_25942;
v_25943:
    v_26379 = stack[-4];
    goto v_25944;
v_25945:
    goto v_25941;
v_25942:
    goto v_25943;
v_25944:
    fn = elt(env, 16); // multsq
    v_26379 = (*qfn2(fn))(fn, v_26380, v_26379);
    env = stack[-5];
    stack[-4] = v_26379;
    v_26379 = stack[0];
    v_26379 = qcdr(v_26379);
    stack[0] = v_26379;
    goto v_25928;
v_25927:
    v_26379 = stack[-4];
    goto v_25742;
v_25891:
    goto v_25971;
v_25967:
    v_26379 = stack[-3];
    v_26380 = qcar(v_26379);
    goto v_25968;
v_25969:
    v_26379 = elt(env, 8); // times
    goto v_25970;
v_25971:
    goto v_25967;
v_25968:
    goto v_25969;
v_25970:
    if (v_26380 == v_26379) goto v_25965;
    else goto v_25966;
v_25965:
    v_26379 = stack[-3];
    v_26379 = qcdr(v_26379);
    fn = elt(env, 18); // split!-sign
    v_26379 = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    stack[0] = v_26379;
    if (v_26379 == nil) goto v_25977;
    else goto v_25978;
v_25977:
    v_26379 = nil;
    goto v_25976;
v_25978:
    v_26379 = stack[0];
    v_26379 = qcar(v_26379);
    goto v_25976;
    v_26379 = nil;
v_25976:
    goto v_25964;
v_25966:
    v_26379 = nil;
    goto v_25964;
    v_26379 = nil;
v_25964:
    if (v_26379 == nil) goto v_25962;
    goto v_25997;
v_25991:
    goto v_26004;
v_26000:
    v_26379 = stack[0];
    v_26379 = qcdr(v_26379);
    v_26380 = qcar(v_26379);
    goto v_26001;
v_26002:
    v_26379 = stack[0];
    v_26379 = qcdr(v_26379);
    v_26379 = qcdr(v_26379);
    goto v_26003;
v_26004:
    goto v_26000;
v_26001:
    goto v_26002;
v_26003:
    v_26379 = Lappend(nil, v_26380, v_26379);
    env = stack[-5];
    fn = elt(env, 19); // retimes
    v_26381 = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    goto v_25992;
v_25993:
    v_26380 = stack[-2];
    goto v_25994;
v_25995:
    v_26379 = stack[-1];
    goto v_25996;
v_25997:
    goto v_25991;
v_25992:
    goto v_25993;
v_25994:
    goto v_25995;
v_25996:
    fn = elt(env, 17); // simpexpt1
    v_26379 = (*qfnn(fn))(fn, 3, v_26381, v_26380, v_26379);
    env = stack[-5];
    stack[-4] = v_26379;
    v_26379 = stack[0];
    v_26379 = qcar(v_26379);
    stack[0] = v_26379;
v_26016:
    v_26379 = stack[0];
    if (v_26379 == nil) goto v_26021;
    else goto v_26022;
v_26021:
    goto v_26015;
v_26022:
    v_26379 = stack[0];
    v_26379 = qcar(v_26379);
    goto v_26033;
v_26029:
    goto v_26041;
v_26035:
    v_26381 = v_26379;
    goto v_26036;
v_26037:
    v_26380 = stack[-2];
    goto v_26038;
v_26039:
    v_26379 = stack[-1];
    goto v_26040;
v_26041:
    goto v_26035;
v_26036:
    goto v_26037;
v_26038:
    goto v_26039;
v_26040:
    fn = elt(env, 17); // simpexpt1
    v_26380 = (*qfnn(fn))(fn, 3, v_26381, v_26380, v_26379);
    env = stack[-5];
    goto v_26030;
v_26031:
    v_26379 = stack[-4];
    goto v_26032;
v_26033:
    goto v_26029;
v_26030:
    goto v_26031;
v_26032:
    fn = elt(env, 16); // multsq
    v_26379 = (*qfn2(fn))(fn, v_26380, v_26379);
    env = stack[-5];
    stack[-4] = v_26379;
    v_26379 = stack[0];
    v_26379 = qcdr(v_26379);
    stack[0] = v_26379;
    goto v_26016;
v_26015:
    v_26379 = stack[-4];
    goto v_25742;
v_25962:
    goto v_26059;
v_26055:
    v_26379 = stack[-3];
    v_26380 = qcar(v_26379);
    goto v_26056;
v_26057:
    v_26379 = elt(env, 10); // quotient
    goto v_26058;
v_26059:
    goto v_26055;
v_26056:
    goto v_26057;
v_26058:
    if (v_26380 == v_26379) goto v_26053;
    else goto v_26054;
v_26053:
    v_26379 = qvalue(elt(env, 4)); // !*precise
    if (v_26379 == nil) goto v_26065;
    else goto v_26066;
v_26065:
    v_26379 = lisp_true;
    goto v_26064;
v_26066:
    v_26379 = stack[-3];
    v_26379 = qcdr(v_26379);
    v_26379 = qcdr(v_26379);
    v_26379 = qcar(v_26379);
    fn = elt(env, 20); // posnump
    v_26379 = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    if (v_26379 == nil) goto v_26073;
    else goto v_26074;
v_26073:
    v_26379 = nil;
    goto v_26072;
v_26074:
    v_26379 = stack[-2];
    fn = elt(env, 21); // prepsq
    v_26379 = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    fn = elt(env, 20); // posnump
    v_26379 = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    goto v_26072;
    v_26379 = nil;
v_26072:
    goto v_26064;
    v_26379 = nil;
v_26064:
    goto v_26052;
v_26054:
    v_26379 = nil;
    goto v_26052;
    v_26379 = nil;
v_26052:
    if (v_26379 == nil) goto v_26050;
    v_26379 = stack[-1];
    if (v_26379 == nil) goto v_26095;
    else goto v_26096;
v_26095:
    v_26379 = qvalue(elt(env, 11)); // !*mcd
    goto v_26094;
v_26096:
    v_26379 = nil;
    goto v_26094;
    v_26379 = nil;
v_26094:
    if (v_26379 == nil) goto v_26092;
    goto v_26109;
v_26103:
    v_26379 = stack[-3];
    fn = elt(env, 22); // simp!*
    v_26379 = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    fn = elt(env, 21); // prepsq
    v_26381 = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    goto v_26104;
v_26105:
    v_26380 = stack[-2];
    goto v_26106;
v_26107:
    v_26379 = lisp_true;
    goto v_26108;
v_26109:
    goto v_26103;
v_26104:
    goto v_26105;
v_26106:
    goto v_26107;
v_26108:
    {
        fn = elt(env, 17); // simpexpt1
        return (*qfnn(fn))(fn, 3, v_26381, v_26380, v_26379);
    }
v_26092:
    v_26379 = stack[-2];
    fn = elt(env, 21); // prepsq
    v_26379 = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    stack[-2] = v_26379;
    goto v_26122;
v_26118:
    goto v_26129;
v_26125:
    v_26379 = stack[-3];
    v_26379 = qcdr(v_26379);
    v_26380 = qcar(v_26379);
    goto v_26126;
v_26127:
    v_26379 = stack[-2];
    goto v_26128;
v_26129:
    goto v_26125;
v_26126:
    goto v_26127;
v_26128:
    v_26379 = list2(v_26380, v_26379);
    env = stack[-5];
    fn = elt(env, 23); // simpexpt
    stack[0] = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    goto v_26119;
v_26120:
    goto v_26140;
v_26136:
    v_26379 = stack[-3];
    v_26379 = qcdr(v_26379);
    v_26379 = qcdr(v_26379);
    v_26380 = qcar(v_26379);
    goto v_26137;
v_26138:
    v_26379 = stack[-2];
    goto v_26139;
v_26140:
    goto v_26136;
v_26137:
    goto v_26138;
v_26139:
    v_26379 = list2(v_26380, v_26379);
    env = stack[-5];
    fn = elt(env, 23); // simpexpt
    v_26379 = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    goto v_26121;
v_26122:
    goto v_26118;
v_26119:
    goto v_26120;
v_26121:
    {
        LispObject v_26387 = stack[0];
        fn = elt(env, 24); // quotsq
        return (*qfn2(fn))(fn, v_26387, v_26379);
    }
v_26050:
    goto v_26156;
v_26152:
    v_26379 = stack[-3];
    v_26380 = qcar(v_26379);
    goto v_26153;
v_26154:
    v_26379 = elt(env, 12); // minus
    goto v_26155;
v_26156:
    goto v_26152;
v_26153:
    goto v_26154;
v_26155:
    if (v_26380 == v_26379) goto v_26150;
    else goto v_26151;
v_26150:
    v_26379 = qvalue(elt(env, 4)); // !*precise
    if (v_26379 == nil) goto v_26162;
    else goto v_26163;
v_26162:
    goto v_26169;
v_26165:
    v_26379 = stack[-3];
    v_26379 = qcdr(v_26379);
    v_26380 = qcar(v_26379);
    goto v_26166;
v_26167:
    v_26379 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26168;
v_26169:
    goto v_26165;
v_26166:
    goto v_26167;
v_26168:
    v_26379 = (v_26380 == v_26379 ? lisp_true : nil);
    v_26379 = (v_26379 == nil ? lisp_true : nil);
    goto v_26161;
v_26163:
    v_26379 = nil;
    goto v_26161;
    v_26379 = nil;
v_26161:
    goto v_26149;
v_26151:
    v_26379 = nil;
    goto v_26149;
    v_26379 = nil;
v_26149:
    if (v_26379 == nil) goto v_26147;
    v_26379 = stack[-2];
    fn = elt(env, 21); // prepsq
    v_26379 = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    stack[-1] = v_26379;
    goto v_26190;
v_26186:
    goto v_26197;
v_26193:
    v_26380 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_26194;
v_26195:
    v_26379 = stack[-1];
    goto v_26196;
v_26197:
    goto v_26193;
v_26194:
    goto v_26195;
v_26196:
    v_26379 = list2(v_26380, v_26379);
    env = stack[-5];
    fn = elt(env, 23); // simpexpt
    stack[0] = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    goto v_26187;
v_26188:
    goto v_26206;
v_26202:
    v_26379 = stack[-3];
    v_26379 = qcdr(v_26379);
    v_26380 = qcar(v_26379);
    goto v_26203;
v_26204:
    v_26379 = stack[-1];
    goto v_26205;
v_26206:
    goto v_26202;
v_26203:
    goto v_26204;
v_26205:
    v_26379 = list2(v_26380, v_26379);
    env = stack[-5];
    fn = elt(env, 23); // simpexpt
    v_26379 = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    goto v_26189;
v_26190:
    goto v_26186;
v_26187:
    goto v_26188;
v_26189:
    {
        LispObject v_26388 = stack[0];
        fn = elt(env, 16); // multsq
        return (*qfn2(fn))(fn, v_26388, v_26379);
    }
v_26147:
    goto v_25766;
v_25768:
v_25766:
    v_26379 = stack[-1];
    if (v_26379 == nil) goto v_26213;
    else goto v_26214;
v_26213:
    v_26379 = qvalue(elt(env, 13)); // dmode!*
    if (v_26379 == nil) goto v_26218;
    v_26379 = stack[-3];
    if (symbolp(v_26379)) goto v_26223;
    else goto v_26218;
v_26223:
    goto v_26231;
v_26227:
    v_26380 = stack[-3];
    goto v_26228;
v_26229:
    v_26379 = qvalue(elt(env, 13)); // dmode!*
    goto v_26230;
v_26231:
    goto v_26227;
v_26228:
    goto v_26229;
v_26230:
    v_26379 = get(v_26380, v_26379);
    env = stack[-5];
    if (v_26379 == nil) goto v_26218;
    goto v_26219;
v_26218:
    v_26379 = stack[-3];
    fn = elt(env, 22); // simp!*
    v_26379 = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    fn = elt(env, 21); // prepsq
    v_26379 = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    stack[-3] = v_26379;
    goto v_26217;
v_26219:
v_26217:
    goto v_26244;
v_26238:
    v_26381 = stack[-3];
    goto v_26239;
v_26240:
    v_26380 = stack[-2];
    goto v_26241;
v_26242:
    v_26379 = lisp_true;
    goto v_26243;
v_26244:
    goto v_26238;
v_26239:
    goto v_26240;
v_26241:
    goto v_26242;
v_26243:
    {
        fn = elt(env, 17); // simpexpt1
        return (*qfnn(fn))(fn, 3, v_26381, v_26380, v_26379);
    }
v_26214:
    v_26379 = stack[-3];
    if (is_number(v_26379)) goto v_26250;
    else goto v_26249;
v_26250:
    v_26379 = stack[-3];
    v_26379 = (LispObject)zerop(v_26379);
    v_26379 = v_26379 ? lisp_true : nil;
    env = stack[-5];
    if (v_26379 == nil) goto v_26249;
    goto v_26260;
v_26256:
    v_26380 = nil;
    goto v_26257;
v_26258:
    v_26379 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26259;
v_26260:
    goto v_26256;
v_26257:
    goto v_26258;
v_26259:
    return cons(v_26380, v_26379);
v_26249:
    v_26379 = stack[-4];
    if (is_number(v_26379)) goto v_26264;
    v_26379 = stack[-4];
    fn = elt(env, 25); // prepf
    v_26379 = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    stack[-4] = v_26379;
    goto v_26212;
v_26264:
v_26212:
    v_26379 = stack[-2];
    v_26379 = qcdr(v_26379);
    fn = elt(env, 25); // prepf
    v_26379 = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    stack[-2] = v_26379;
    goto v_26280;
v_26276:
    v_26380 = stack[-4];
    goto v_26277;
v_26278:
    v_26379 = qvalue(elt(env, 14)); // frlis!*
    goto v_26279;
v_26280:
    goto v_26276;
v_26277:
    goto v_26278;
v_26279:
    v_26379 = Lmemq(nil, v_26380, v_26379);
    if (v_26379 == nil) goto v_26274;
    goto v_26289;
v_26285:
    v_26380 = stack[-2];
    goto v_26286;
v_26287:
    v_26379 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26288;
v_26289:
    goto v_26285;
v_26286:
    goto v_26287;
v_26288:
    if (v_26380 == v_26379) goto v_26284;
    else goto v_26274;
v_26284:
    goto v_26297;
v_26293:
    goto v_26306;
v_26300:
    v_26381 = stack[-3];
    goto v_26301;
v_26302:
    v_26380 = stack[-4];
    goto v_26303;
v_26304:
    v_26379 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26305;
v_26306:
    goto v_26300;
v_26301:
    goto v_26302;
v_26303:
    goto v_26304;
v_26305:
    v_26379 = acons(v_26381, v_26380, v_26379);
    env = stack[-5];
    v_26380 = ncons(v_26379);
    goto v_26294;
v_26295:
    v_26379 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26296;
v_26297:
    goto v_26293;
v_26294:
    goto v_26295;
v_26296:
    return cons(v_26380, v_26379);
v_26274:
    v_26379 = qvalue(elt(env, 11)); // !*mcd
    if (v_26379 == nil) goto v_26315;
    else goto v_26313;
v_26315:
    v_26379 = stack[-4];
    if (is_number(v_26379)) goto v_26321;
    v_26379 = lisp_true;
    goto v_26319;
v_26321:
    goto v_26334;
v_26330:
    v_26380 = stack[-2];
    goto v_26331;
v_26332:
    v_26379 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26333;
v_26334:
    goto v_26330;
v_26331:
    goto v_26332;
v_26333:
    if (v_26380 == v_26379) goto v_26329;
    v_26379 = lisp_true;
    goto v_26327;
v_26329:
    v_26379 = stack[-3];
    if (!consp(v_26379)) goto v_26342;
    else goto v_26343;
v_26342:
    v_26379 = lisp_true;
    goto v_26341;
v_26343:
    goto v_26353;
v_26349:
    v_26379 = stack[-3];
    fn = elt(env, 22); // simp!*
    v_26379 = (*qfn1(fn))(fn, v_26379);
    env = stack[-5];
    v_26380 = qcdr(v_26379);
    goto v_26350;
v_26351:
    v_26379 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26352;
v_26353:
    goto v_26349;
v_26350:
    goto v_26351;
v_26352:
    v_26379 = Lneq(nil, v_26380, v_26379);
    env = stack[-5];
    goto v_26341;
    v_26379 = nil;
v_26341:
    goto v_26327;
    v_26379 = nil;
v_26327:
    goto v_26319;
    v_26379 = nil;
v_26319:
    if (v_26379 == nil) goto v_26317;
    else goto v_26313;
v_26317:
    goto v_26314;
v_26313:
    goto v_26365;
v_26359:
    v_26381 = stack[-3];
    goto v_26360;
v_26361:
    v_26380 = stack[-4];
    goto v_26362;
v_26363:
    v_26379 = stack[-2];
    goto v_26364;
v_26365:
    goto v_26359;
v_26360:
    goto v_26361;
v_26362:
    goto v_26363;
v_26364:
    {
        fn = elt(env, 26); // simpx1
        return (*qfnn(fn))(fn, 3, v_26381, v_26380, v_26379);
    }
v_26314:
    goto v_26376;
v_26372:
    v_26380 = stack[-3];
    goto v_26373;
v_26374:
    v_26379 = stack[-4];
    goto v_26375;
v_26376:
    goto v_26372;
v_26373:
    goto v_26374;
v_26375:
    {
        fn = elt(env, 27); // mksq
        return (*qfn2(fn))(fn, v_26380, v_26379);
    }
    v_26379 = nil;
v_25742:
    return onevalue(v_26379);
}



// Code for mk!+resimp!+mat

static LispObject CC_mkLresimpLmat(LispObject env,
                         LispObject v_25734)
{
    env = qenv(env);
    LispObject v_25865;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25734);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    v_25865 = v_25734;
// end of prologue
    stack[-7] = v_25865;
    v_25865 = stack[-7];
    if (v_25865 == nil) goto v_25751;
    else goto v_25752;
v_25751:
    v_25865 = nil;
    goto v_25746;
v_25752:
    v_25865 = stack[-7];
    v_25865 = qcar(v_25865);
    stack[-3] = v_25865;
    v_25865 = stack[-3];
    if (v_25865 == nil) goto v_25768;
    else goto v_25769;
v_25768:
    v_25865 = nil;
    goto v_25763;
v_25769:
    v_25865 = stack[-3];
    v_25865 = qcar(v_25865);
    fn = elt(env, 2); // resimp
    v_25865 = (*qfn1(fn))(fn, v_25865);
    env = stack[-8];
    v_25865 = ncons(v_25865);
    env = stack[-8];
    stack[-1] = v_25865;
    stack[-2] = v_25865;
v_25764:
    v_25865 = stack[-3];
    v_25865 = qcdr(v_25865);
    stack[-3] = v_25865;
    v_25865 = stack[-3];
    if (v_25865 == nil) goto v_25782;
    else goto v_25783;
v_25782:
    v_25865 = stack[-2];
    goto v_25763;
v_25783:
    goto v_25791;
v_25787:
    stack[0] = stack[-1];
    goto v_25788;
v_25789:
    v_25865 = stack[-3];
    v_25865 = qcar(v_25865);
    fn = elt(env, 2); // resimp
    v_25865 = (*qfn1(fn))(fn, v_25865);
    env = stack[-8];
    v_25865 = ncons(v_25865);
    env = stack[-8];
    goto v_25790;
v_25791:
    goto v_25787;
v_25788:
    goto v_25789;
v_25790:
    v_25865 = Lrplacd(nil, stack[0], v_25865);
    env = stack[-8];
    v_25865 = stack[-1];
    v_25865 = qcdr(v_25865);
    stack[-1] = v_25865;
    goto v_25764;
v_25763:
    v_25865 = ncons(v_25865);
    env = stack[-8];
    stack[-5] = v_25865;
    stack[-6] = v_25865;
v_25747:
    v_25865 = stack[-7];
    v_25865 = qcdr(v_25865);
    stack[-7] = v_25865;
    v_25865 = stack[-7];
    if (v_25865 == nil) goto v_25805;
    else goto v_25806;
v_25805:
    v_25865 = stack[-6];
    goto v_25746;
v_25806:
    goto v_25814;
v_25810:
    stack[-4] = stack[-5];
    goto v_25811;
v_25812:
    v_25865 = stack[-7];
    v_25865 = qcar(v_25865);
    stack[-3] = v_25865;
    v_25865 = stack[-3];
    if (v_25865 == nil) goto v_25829;
    else goto v_25830;
v_25829:
    v_25865 = nil;
    goto v_25824;
v_25830:
    v_25865 = stack[-3];
    v_25865 = qcar(v_25865);
    fn = elt(env, 2); // resimp
    v_25865 = (*qfn1(fn))(fn, v_25865);
    env = stack[-8];
    v_25865 = ncons(v_25865);
    env = stack[-8];
    stack[-1] = v_25865;
    stack[-2] = v_25865;
v_25825:
    v_25865 = stack[-3];
    v_25865 = qcdr(v_25865);
    stack[-3] = v_25865;
    v_25865 = stack[-3];
    if (v_25865 == nil) goto v_25843;
    else goto v_25844;
v_25843:
    v_25865 = stack[-2];
    goto v_25824;
v_25844:
    goto v_25852;
v_25848:
    stack[0] = stack[-1];
    goto v_25849;
v_25850:
    v_25865 = stack[-3];
    v_25865 = qcar(v_25865);
    fn = elt(env, 2); // resimp
    v_25865 = (*qfn1(fn))(fn, v_25865);
    env = stack[-8];
    v_25865 = ncons(v_25865);
    env = stack[-8];
    goto v_25851;
v_25852:
    goto v_25848;
v_25849:
    goto v_25850;
v_25851:
    v_25865 = Lrplacd(nil, stack[0], v_25865);
    env = stack[-8];
    v_25865 = stack[-1];
    v_25865 = qcdr(v_25865);
    stack[-1] = v_25865;
    goto v_25825;
v_25824:
    v_25865 = ncons(v_25865);
    env = stack[-8];
    goto v_25813;
v_25814:
    goto v_25810;
v_25811:
    goto v_25812;
v_25813:
    v_25865 = Lrplacd(nil, stack[-4], v_25865);
    env = stack[-8];
    v_25865 = stack[-5];
    v_25865 = qcdr(v_25865);
    stack[-5] = v_25865;
    goto v_25747;
v_25746:
    return onevalue(v_25865);
}



// Code for pasf_ceil

static LispObject CC_pasf_ceil(LispObject env,
                         LispObject v_25734, LispObject v_25735)
{
    env = qenv(env);
    LispObject v_25856, v_25857, v_25858;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25735,v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25734,v_25735);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_25735;
    stack[-1] = v_25734;
// end of prologue
    v_25856 = stack[-1];
    if (!consp(v_25856)) goto v_25747;
    else goto v_25748;
v_25747:
    v_25856 = lisp_true;
    goto v_25746;
v_25748:
    v_25856 = stack[-1];
    v_25856 = qcar(v_25856);
    v_25856 = (consp(v_25856) ? nil : lisp_true);
    goto v_25746;
    v_25856 = nil;
v_25746:
    if (v_25856 == nil) goto v_25744;
    v_25856 = stack[0];
    if (!consp(v_25856)) goto v_25758;
    else goto v_25759;
v_25758:
    v_25856 = lisp_true;
    goto v_25757;
v_25759:
    v_25856 = stack[0];
    v_25856 = qcar(v_25856);
    v_25856 = (consp(v_25856) ? nil : lisp_true);
    goto v_25757;
    v_25856 = nil;
v_25757:
    goto v_25742;
v_25744:
    v_25856 = nil;
    goto v_25742;
    v_25856 = nil;
v_25742:
    if (v_25856 == nil) goto v_25740;
    v_25856 = stack[-1];
    if (v_25856 == nil) goto v_25772;
    else goto v_25773;
v_25772:
    v_25856 = nil;
    goto v_25771;
v_25773:
    goto v_25787;
v_25783:
    goto v_25793;
v_25789:
    v_25857 = stack[-1];
    goto v_25790;
v_25791:
    v_25856 = stack[0];
    goto v_25792;
v_25793:
    goto v_25789;
v_25790:
    goto v_25791;
v_25792:
    v_25857 = Cremainder(v_25857, v_25856);
    env = stack[-2];
    goto v_25784;
v_25785:
    v_25856 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25786;
v_25787:
    goto v_25783;
v_25784:
    goto v_25785;
v_25786:
    if (v_25857 == v_25856) goto v_25781;
    else goto v_25782;
v_25781:
    goto v_25802;
v_25798:
    v_25857 = stack[-1];
    goto v_25799;
v_25800:
    v_25856 = stack[0];
    goto v_25801;
v_25802:
    goto v_25798;
v_25799:
    goto v_25800;
v_25801:
    v_25856 = quot2(v_25857, v_25856);
    env = stack[-2];
    goto v_25780;
v_25782:
    goto v_25812;
v_25808:
    goto v_25818;
v_25814:
    v_25857 = stack[-1];
    goto v_25815;
v_25816:
    v_25856 = stack[0];
    goto v_25817;
v_25818:
    goto v_25814;
v_25815:
    goto v_25816;
v_25817:
    v_25857 = times2(v_25857, v_25856);
    env = stack[-2];
    goto v_25809;
v_25810:
    v_25856 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25811;
v_25812:
    goto v_25808;
v_25809:
    goto v_25810;
v_25811:
    v_25856 = (LispObject)greaterp2(v_25857, v_25856);
    v_25856 = v_25856 ? lisp_true : nil;
    env = stack[-2];
    if (v_25856 == nil) goto v_25806;
    goto v_25828;
v_25824:
    v_25857 = stack[-1];
    goto v_25825;
v_25826:
    v_25856 = stack[0];
    goto v_25827;
v_25828:
    goto v_25824;
v_25825:
    goto v_25826;
v_25827:
    v_25856 = quot2(v_25857, v_25856);
    env = stack[-2];
    v_25856 = add1(v_25856);
    env = stack[-2];
    goto v_25780;
v_25806:
    goto v_25838;
v_25834:
    v_25857 = stack[-1];
    goto v_25835;
v_25836:
    v_25856 = stack[0];
    goto v_25837;
v_25838:
    goto v_25834;
v_25835:
    goto v_25836;
v_25837:
    v_25856 = quot2(v_25857, v_25856);
    env = stack[-2];
    goto v_25780;
    v_25856 = nil;
v_25780:
    fn = elt(env, 2); // simp
    v_25856 = (*qfn1(fn))(fn, v_25856);
    v_25856 = qcar(v_25856);
    goto v_25771;
    v_25856 = nil;
v_25771:
    goto v_25738;
v_25740:
    goto v_25852;
v_25846:
    v_25858 = elt(env, 1); // "pasf_ceil: not a domain valued sf in input"
    goto v_25847;
v_25848:
    v_25857 = stack[-1];
    goto v_25849;
v_25850:
    v_25856 = stack[0];
    goto v_25851;
v_25852:
    goto v_25846;
v_25847:
    goto v_25848;
v_25849:
    goto v_25850;
v_25851:
    v_25856 = list3(v_25858, v_25857, v_25856);
    env = stack[-2];
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_25856);
    }
    v_25856 = nil;
v_25738:
    return onevalue(v_25856);
}



// Code for numir

static LispObject CC_numir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25948, v_25949, v_25950;
    LispObject fn;
    argcheck(nargs, 0, "numir");
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
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// end of prologue
    goto v_25748;
v_25744:
    v_25949 = qvalue(elt(env, 2)); // atts
    goto v_25745;
v_25746:
    v_25948 = elt(env, 3); // name
    goto v_25747;
v_25748:
    goto v_25744;
v_25745:
    goto v_25746;
v_25747:
    fn = elt(env, 12); // find
    v_25948 = (*qfn2(fn))(fn, v_25949, v_25948);
    env = stack[-7];
    v_25948 = Lintern(nil, v_25948);
    env = stack[-7];
    stack[-1] = v_25948;
    fn = elt(env, 13); // lex
    v_25948 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    fn = elt(env, 14); // omobj
    v_25948 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    stack[0] = v_25948;
    fn = elt(env, 13); // lex
    v_25948 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    fn = elt(env, 14); // omobj
    v_25948 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    goto v_25763;
v_25759:
    v_25950 = stack[-1];
    goto v_25760;
v_25761:
    v_25949 = elt(env, 4); // complex_cartesian
    goto v_25762;
v_25763:
    goto v_25759;
v_25760:
    goto v_25761;
v_25762:
    if (v_25950 == v_25949) goto v_25757;
    else goto v_25758;
v_25757:
    v_25949 = stack[0];
    if (symbolp(v_25949)) goto v_25768;
    v_25949 = v_25948;
    if (symbolp(v_25949)) goto v_25768;
    goto v_25769;
v_25768:
    goto v_25781;
v_25775:
    stack[-4] = elt(env, 5); // plus
    goto v_25776;
v_25777:
    stack[-3] = nil;
    goto v_25778;
v_25779:
    goto v_25791;
v_25785:
    stack[-2] = stack[0];
    goto v_25786;
v_25787:
    goto v_25800;
v_25794:
    stack[-1] = elt(env, 6); // times
    goto v_25795;
v_25796:
    stack[0] = nil;
    goto v_25797;
v_25798:
    goto v_25810;
v_25804:
    v_25950 = v_25948;
    goto v_25805;
v_25806:
    v_25949 = elt(env, 7); // !&imaginaryi!;
    goto v_25807;
v_25808:
    v_25948 = nil;
    goto v_25809;
v_25810:
    goto v_25804;
v_25805:
    goto v_25806;
v_25807:
    goto v_25808;
v_25809:
    v_25948 = list2star(v_25950, v_25949, v_25948);
    env = stack[-7];
    goto v_25799;
v_25800:
    goto v_25794;
v_25795:
    goto v_25796;
v_25797:
    goto v_25798;
v_25799:
    v_25949 = list2star(stack[-1], stack[0], v_25948);
    env = stack[-7];
    goto v_25788;
v_25789:
    v_25948 = nil;
    goto v_25790;
v_25791:
    goto v_25785;
v_25786:
    goto v_25787;
v_25788:
    goto v_25789;
v_25790:
    v_25948 = list2star(stack[-2], v_25949, v_25948);
    goto v_25780;
v_25781:
    goto v_25775;
v_25776:
    goto v_25777;
v_25778:
    goto v_25779;
v_25780:
    {
        LispObject v_25958 = stack[-4];
        LispObject v_25959 = stack[-3];
        return list2star(v_25958, v_25959, v_25948);
    }
v_25769:
    goto v_25756;
v_25758:
v_25756:
    goto v_25823;
v_25819:
    v_25950 = stack[-1];
    goto v_25820;
v_25821:
    v_25949 = elt(env, 8); // complex_polar
    goto v_25822;
v_25823:
    goto v_25819;
v_25820:
    goto v_25821;
v_25822:
    if (v_25950 == v_25949) goto v_25817;
    else goto v_25818;
v_25817:
    v_25949 = stack[0];
    if (symbolp(v_25949)) goto v_25828;
    v_25949 = v_25948;
    if (symbolp(v_25949)) goto v_25828;
    goto v_25829;
v_25828:
    goto v_25841;
v_25835:
    stack[-6] = elt(env, 6); // times
    goto v_25836;
v_25837:
    stack[-5] = nil;
    goto v_25838;
v_25839:
    goto v_25851;
v_25845:
    stack[-4] = stack[0];
    goto v_25846;
v_25847:
    goto v_25860;
v_25854:
    stack[-3] = elt(env, 9); // exp
    goto v_25855;
v_25856:
    stack[-2] = nil;
    goto v_25857;
v_25858:
    goto v_25871;
v_25865:
    stack[-1] = elt(env, 6); // times
    goto v_25866;
v_25867:
    stack[0] = nil;
    goto v_25868;
v_25869:
    goto v_25881;
v_25875:
    v_25950 = v_25948;
    goto v_25876;
v_25877:
    v_25949 = elt(env, 7); // !&imaginaryi!;
    goto v_25878;
v_25879:
    v_25948 = nil;
    goto v_25880;
v_25881:
    goto v_25875;
v_25876:
    goto v_25877;
v_25878:
    goto v_25879;
v_25880:
    v_25948 = list2star(v_25950, v_25949, v_25948);
    env = stack[-7];
    goto v_25870;
v_25871:
    goto v_25865;
v_25866:
    goto v_25867;
v_25868:
    goto v_25869;
v_25870:
    v_25948 = list2star(stack[-1], stack[0], v_25948);
    env = stack[-7];
    v_25948 = ncons(v_25948);
    env = stack[-7];
    goto v_25859;
v_25860:
    goto v_25854;
v_25855:
    goto v_25856;
v_25857:
    goto v_25858;
v_25859:
    v_25949 = list2star(stack[-3], stack[-2], v_25948);
    env = stack[-7];
    goto v_25848;
v_25849:
    v_25948 = nil;
    goto v_25850;
v_25851:
    goto v_25845;
v_25846:
    goto v_25847;
v_25848:
    goto v_25849;
v_25850:
    v_25948 = list2star(stack[-4], v_25949, v_25948);
    goto v_25840;
v_25841:
    goto v_25835;
v_25836:
    goto v_25837;
v_25838:
    goto v_25839;
v_25840:
    {
        LispObject v_25960 = stack[-6];
        LispObject v_25961 = stack[-5];
        return list2star(v_25960, v_25961, v_25948);
    }
v_25829:
    goto v_25816;
v_25818:
v_25816:
    goto v_25894;
v_25890:
    v_25950 = stack[-1];
    goto v_25891;
v_25892:
    v_25949 = elt(env, 10); // rational
    goto v_25893;
v_25894:
    goto v_25890;
v_25891:
    goto v_25892;
v_25893:
    if (v_25950 == v_25949) goto v_25888;
    else goto v_25889;
v_25888:
    v_25949 = stack[0];
    if (symbolp(v_25949)) goto v_25899;
    v_25949 = v_25948;
    if (symbolp(v_25949)) goto v_25899;
    goto v_25900;
v_25899:
    goto v_25912;
v_25906:
    stack[-2] = elt(env, 11); // divide
    goto v_25907;
v_25908:
    stack[-1] = nil;
    goto v_25909;
v_25910:
    goto v_25922;
v_25916:
    v_25950 = stack[0];
    goto v_25917;
v_25918:
    v_25949 = v_25948;
    goto v_25919;
v_25920:
    v_25948 = nil;
    goto v_25921;
v_25922:
    goto v_25916;
v_25917:
    goto v_25918;
v_25919:
    goto v_25920;
v_25921:
    v_25948 = list2star(v_25950, v_25949, v_25948);
    goto v_25911;
v_25912:
    goto v_25906;
v_25907:
    goto v_25908;
v_25909:
    goto v_25910;
v_25911:
    {
        LispObject v_25962 = stack[-2];
        LispObject v_25963 = stack[-1];
        return list2star(v_25962, v_25963, v_25948);
    }
v_25900:
    goto v_25887;
v_25889:
v_25887:
    goto v_25934;
v_25928:
    stack[-2] = stack[-1];
    goto v_25929;
v_25930:
    stack[-1] = nil;
    goto v_25931;
v_25932:
    goto v_25944;
v_25938:
    v_25950 = stack[0];
    goto v_25939;
v_25940:
    v_25949 = v_25948;
    goto v_25941;
v_25942:
    v_25948 = nil;
    goto v_25943;
v_25944:
    goto v_25938;
v_25939:
    goto v_25940;
v_25941:
    goto v_25942;
v_25943:
    v_25948 = list2star(v_25950, v_25949, v_25948);
    goto v_25933;
v_25934:
    goto v_25928;
v_25929:
    goto v_25930;
v_25931:
    goto v_25932;
v_25933:
    {
        LispObject v_25964 = stack[-2];
        LispObject v_25965 = stack[-1];
        return list2star(v_25964, v_25965, v_25948);
    }
    return onevalue(v_25948);
}



// Code for diffp

static LispObject CC_diffp(LispObject env,
                         LispObject v_25734, LispObject v_25735)
{
    env = qenv(env);
    LispObject v_27294, v_27295, v_27296, v_27297, v_27298;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25735,v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25734,v_25735);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-7] = v_25735;
    stack[-8] = v_25734;
// end of prologue
    stack[0] = nil;
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    stack[-9] = v_27294;
    v_27294 = stack[-8];
    v_27294 = qcar(v_27294);
    stack[-8] = v_27294;
    goto v_25767;
v_25763:
    v_27295 = stack[-9];
    goto v_25764;
v_25765:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25766;
v_25767:
    goto v_25763;
v_25764:
    goto v_25765;
v_25766:
    v_27294 = (LispObject)greaterp2(v_27295, v_27294);
    v_27294 = v_27294 ? lisp_true : nil;
    env = stack[-10];
    if (v_27294 == nil) goto v_25760;
    v_27294 = stack[-8];
    fn = elt(env, 24); // noncomp
    v_27294 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    if (v_27294 == nil) goto v_25760;
    goto v_25778;
v_25774:
    goto v_25784;
v_25780:
    goto v_25791;
v_25787:
    v_27295 = stack[-8];
    goto v_25788;
v_25789:
    v_27294 = stack[-7];
    goto v_25790;
v_25791:
    goto v_25787;
v_25788:
    goto v_25789;
v_25790:
    v_27294 = list2(v_27295, v_27294);
    env = stack[-10];
    fn = elt(env, 25); // simpdf
    stack[-1] = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    goto v_25781;
v_25782:
    goto v_25800;
v_25796:
    stack[0] = stack[-8];
    goto v_25797;
v_25798:
    v_27294 = stack[-9];
    v_27294 = sub1(v_27294);
    env = stack[-10];
    goto v_25799;
v_25800:
    goto v_25796;
v_25797:
    goto v_25798;
v_25799:
    v_27294 = list2(stack[0], v_27294);
    env = stack[-10];
    fn = elt(env, 26); // simpexpt
    v_27294 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    goto v_25783;
v_25784:
    goto v_25780;
v_25781:
    goto v_25782;
v_25783:
    fn = elt(env, 27); // multsq
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_27294);
    env = stack[-10];
    goto v_25775;
v_25776:
    goto v_25809;
v_25805:
    goto v_25815;
v_25811:
    goto v_25822;
v_25818:
    goto v_25828;
v_25824:
    v_27295 = stack[-8];
    goto v_25825;
v_25826:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25827;
v_25828:
    goto v_25824;
v_25825:
    goto v_25826;
v_25827:
    fn = elt(env, 28); // to
    v_27295 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    goto v_25819;
v_25820:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25821;
v_25822:
    goto v_25818;
v_25819:
    goto v_25820;
v_25821:
    v_27294 = cons(v_27295, v_27294);
    env = stack[-10];
    v_27295 = ncons(v_27294);
    env = stack[-10];
    goto v_25812;
v_25813:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25814;
v_25815:
    goto v_25811;
v_25812:
    goto v_25813;
v_25814:
    stack[0] = cons(v_27295, v_27294);
    env = stack[-10];
    goto v_25806;
v_25807:
    goto v_25838;
v_25834:
    goto v_25844;
v_25840:
    stack[-2] = stack[-8];
    goto v_25841;
v_25842:
    v_27294 = stack[-9];
    v_27294 = sub1(v_27294);
    env = stack[-10];
    goto v_25843;
v_25844:
    goto v_25840;
v_25841:
    goto v_25842;
v_25843:
    v_27295 = cons(stack[-2], v_27294);
    env = stack[-10];
    goto v_25835;
v_25836:
    v_27294 = stack[-7];
    goto v_25837;
v_25838:
    goto v_25834;
v_25835:
    goto v_25836;
v_25837:
    v_27294 = CC_diffp(elt(env, 0), v_27295, v_27294);
    env = stack[-10];
    goto v_25808;
v_25809:
    goto v_25805;
v_25806:
    goto v_25807;
v_25808:
    fn = elt(env, 27); // multsq
    v_27294 = (*qfn2(fn))(fn, stack[0], v_27294);
    env = stack[-10];
    goto v_25777;
v_25778:
    goto v_25774;
v_25775:
    goto v_25776;
v_25777:
    {
        LispObject v_27309 = stack[-1];
        fn = elt(env, 29); // addsq
        return (*qfn2(fn))(fn, v_27309, v_27294);
    }
v_25760:
    goto v_25859;
v_25855:
    v_27295 = stack[-8];
    goto v_25856;
v_25857:
    v_27294 = stack[-7];
    goto v_25858;
v_25859:
    goto v_25855;
v_25856:
    goto v_25857;
v_25858:
    if (v_27295 == v_27294) goto v_25853;
    else goto v_25854;
v_25853:
    goto v_25867;
v_25863:
    v_27295 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25864;
v_25865:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25866;
v_25867:
    goto v_25863;
v_25864:
    goto v_25865;
v_25866:
    v_27294 = cons(v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_25852;
v_25854:
    v_27294 = nil;
    goto v_25852;
    v_27294 = nil;
v_25852:
    if (v_27294 == nil) goto v_25850;
    goto v_25747;
v_25850:
    v_27294 = stack[-8];
    if (!consp(v_27294)) goto v_25873;
    else goto v_25874;
v_25873:
    goto v_25748;
v_25874:
    v_27294 = stack[-8];
    v_27294 = qcar(v_27294);
    if (!consp(v_27294)) goto v_25882;
    goto v_25890;
v_25886:
    v_27295 = stack[-8];
    goto v_25887;
v_25888:
    v_27294 = stack[-7];
    goto v_25889;
v_25890:
    goto v_25886;
v_25887:
    goto v_25888;
v_25889:
    fn = elt(env, 30); // difff
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_25880;
v_25882:
    v_27294 = nil;
    goto v_25880;
    v_27294 = nil;
v_25880:
    if (v_27294 == nil) goto v_25878;
    else goto v_25876;
v_25878:
    goto v_25905;
v_25901:
    v_27294 = stack[-8];
    v_27295 = qcar(v_27294);
    goto v_25902;
v_25903:
    v_27294 = elt(env, 2); // !*sq
    goto v_25904;
v_25905:
    goto v_25901;
v_25902:
    goto v_25903;
v_25904:
    if (v_27295 == v_27294) goto v_25899;
    else goto v_25900;
v_25899:
    goto v_25914;
v_25910:
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    v_27295 = qcar(v_27294);
    goto v_25911;
v_25912:
    v_27294 = stack[-7];
    goto v_25913;
v_25914:
    goto v_25910;
v_25911:
    goto v_25912;
v_25913:
    fn = elt(env, 31); // diffsq
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_25898;
v_25900:
    v_27294 = nil;
    goto v_25898;
    v_27294 = nil;
v_25898:
    if (v_27294 == nil) goto v_25896;
    else goto v_25876;
v_25896:
    goto v_25877;
v_25876:
    goto v_25746;
v_25877:
    goto v_25929;
v_25925:
    v_27294 = stack[-8];
    v_27295 = qcar(v_27294);
    goto v_25926;
v_25927:
    v_27294 = elt(env, 3); // dfform
    goto v_25928;
v_25929:
    goto v_25925;
v_25926:
    goto v_25927;
v_25928:
    v_27294 = get(v_27295, v_27294);
    env = stack[-10];
    stack[-6] = v_27294;
    if (v_27294 == nil) goto v_25923;
    goto v_25942;
v_25934:
    v_27297 = stack[-6];
    goto v_25935;
v_25936:
    v_27296 = stack[-8];
    goto v_25937;
v_25938:
    v_27295 = stack[-7];
    goto v_25939;
v_25940:
    v_27294 = stack[-9];
    goto v_25941;
v_25942:
    goto v_25934;
v_25935:
    goto v_25936;
v_25937:
    goto v_25938;
v_25939:
    goto v_25940;
v_25941:
        return Lapply3(nil, 4, v_27297, v_27296, v_27295, v_27294);
v_25923:
    goto v_25954;
v_25950:
    v_27294 = stack[-8];
    stack[-1] = qcar(v_27294);
    goto v_25951;
v_25952:
    v_27294 = stack[-8];
    fn = elt(env, 32); // dfn_prop
    v_27294 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    goto v_25953;
v_25954:
    goto v_25950;
v_25951:
    goto v_25952;
v_25953:
    v_27294 = get(stack[-1], v_27294);
    env = stack[-10];
    stack[-6] = v_27294;
    if (v_27294 == nil) goto v_25948;
    goto v_25758;
v_25948:
    goto v_25970;
v_25966:
    v_27294 = stack[-8];
    v_27295 = qcar(v_27294);
    goto v_25967;
v_25968:
    v_27294 = elt(env, 4); // plus
    goto v_25969;
v_25970:
    goto v_25966;
v_25967:
    goto v_25968;
v_25969:
    if (v_27295 == v_27294) goto v_25964;
    else goto v_25965;
v_25964:
    goto v_25979;
v_25975:
    v_27294 = stack[-8];
    fn = elt(env, 33); // simp
    v_27295 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    goto v_25976;
v_25977:
    v_27294 = stack[-7];
    goto v_25978;
v_25979:
    goto v_25975;
v_25976:
    goto v_25977;
v_25978:
    fn = elt(env, 31); // diffsq
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_25963;
v_25965:
    v_27294 = nil;
    goto v_25963;
    v_27294 = nil;
v_25963:
    if (v_27294 == nil) goto v_25961;
    goto v_25746;
v_25961:
    goto v_25749;
v_25758:
    v_27294 = stack[-6];
    stack[-5] = v_27294;
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    stack[-4] = v_27294;
v_25745:
    goto v_25996;
v_25992:
    goto v_26002;
v_25998:
    v_27294 = stack[-4];
    v_27294 = qcar(v_27294);
    fn = elt(env, 33); // simp
    v_27295 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    goto v_25999;
v_26000:
    v_27294 = stack[-7];
    goto v_26001;
v_26002:
    goto v_25998;
v_25999:
    goto v_26000;
v_26001:
    fn = elt(env, 31); // diffsq
    v_27295 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    goto v_25993;
v_25994:
    v_27294 = stack[0];
    goto v_25995;
v_25996:
    goto v_25992;
v_25993:
    goto v_25994;
v_25995:
    v_27294 = cons(v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    v_27294 = stack[0];
    v_27294 = qcar(v_27294);
    v_27294 = qcar(v_27294);
    if (v_27294 == nil) goto v_26011;
    v_27294 = stack[-5];
    v_27294 = qcar(v_27294);
    if (v_27294 == nil) goto v_26016;
    else goto v_26011;
v_26016:
    goto v_25749;
v_26011:
    v_27294 = stack[-5];
    v_27294 = qcdr(v_27294);
    stack[-5] = v_27294;
    v_27294 = stack[-4];
    v_27294 = qcdr(v_27294);
    stack[-4] = v_27294;
    v_27294 = stack[-4];
    if (v_27294 == nil) goto v_26026;
    v_27294 = stack[-5];
    if (v_27294 == nil) goto v_26026;
    goto v_25745;
v_26026:
    v_27294 = stack[-4];
    if (v_27294 == nil) goto v_26033;
    else goto v_26031;
v_26033:
    v_27294 = stack[-5];
    if (v_27294 == nil) goto v_26035;
    else goto v_26031;
v_26035:
    goto v_26032;
v_26031:
    goto v_25749;
v_26032:
    v_27294 = stack[0];
    v_27294 = Lreverse(nil, v_27294);
    env = stack[-10];
    stack[-5] = v_27294;
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    stack[-4] = v_27294;
    goto v_26046;
v_26042:
    v_27295 = nil;
    goto v_26043;
v_26044:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26045;
v_26046:
    goto v_26042;
v_26043:
    goto v_26044;
v_26045:
    v_27294 = cons(v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
v_26051:
    v_27294 = stack[-5];
    v_27294 = qcar(v_27294);
    v_27294 = qcar(v_27294);
    if (v_27294 == nil) goto v_26055;
    goto v_26064;
v_26060:
    goto v_26070;
v_26066:
    v_27294 = stack[-5];
    stack[-1] = qcar(v_27294);
    goto v_26067;
v_26068:
    goto v_26079;
v_26075:
    goto v_26085;
v_26081:
    v_27294 = stack[-6];
    v_27294 = qcar(v_27294);
    v_27295 = qcar(v_27294);
    goto v_26082;
v_26083:
    v_27294 = stack[-4];
    goto v_26084;
v_26085:
    goto v_26081;
v_26082:
    goto v_26083;
v_26084:
    fn = elt(env, 34); // pair
    v_27295 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    goto v_26076;
v_26077:
    v_27294 = stack[-6];
    v_27294 = qcar(v_27294);
    v_27294 = qcdr(v_27294);
    goto v_26078;
v_26079:
    goto v_26075;
v_26076:
    goto v_26077;
v_26078:
    v_27294 = Lsubla(nil, v_27295, v_27294);
    env = stack[-10];
    fn = elt(env, 33); // simp
    v_27294 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    goto v_26069;
v_26070:
    goto v_26066;
v_26067:
    goto v_26068;
v_26069:
    fn = elt(env, 27); // multsq
    v_27295 = (*qfn2(fn))(fn, stack[-1], v_27294);
    env = stack[-10];
    goto v_26061;
v_26062:
    v_27294 = stack[0];
    goto v_26063;
v_26064:
    goto v_26060;
v_26061:
    goto v_26062;
v_26063:
    fn = elt(env, 29); // addsq
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_26053;
v_26055:
v_26053:
    v_27294 = stack[-6];
    v_27294 = qcdr(v_27294);
    stack[-6] = v_27294;
    v_27294 = stack[-5];
    v_27294 = qcdr(v_27294);
    stack[-5] = v_27294;
    v_27294 = stack[-5];
    if (v_27294 == nil) goto v_26101;
    goto v_26051;
v_26101:
v_25746:
v_25747:
    goto v_26111;
v_26107:
    v_27295 = stack[-8];
    goto v_26108;
v_26109:
    v_27294 = qvalue(elt(env, 5)); // wtl!*
    goto v_26110;
v_26111:
    goto v_26107;
v_26108:
    goto v_26109;
v_26110:
    v_27294 = Latsoc(nil, v_27295, v_27294);
    stack[-6] = v_27294;
    if (v_27294 == nil) goto v_26106;
    goto v_26120;
v_26116:
    goto v_26126;
v_26122:
    goto v_26133;
v_26129:
    goto v_26139;
v_26135:
    stack[-1] = elt(env, 6); // k!*
    goto v_26136;
v_26137:
    v_27294 = stack[-6];
    v_27294 = qcdr(v_27294);
    v_27294 = negate(v_27294);
    env = stack[-10];
    goto v_26138;
v_26139:
    goto v_26135;
v_26136:
    goto v_26137;
v_26138:
    fn = elt(env, 28); // to
    v_27295 = (*qfn2(fn))(fn, stack[-1], v_27294);
    env = stack[-10];
    goto v_26130;
v_26131:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26132;
v_26133:
    goto v_26129;
v_26130:
    goto v_26131;
v_26132:
    v_27294 = cons(v_27295, v_27294);
    env = stack[-10];
    v_27295 = ncons(v_27294);
    env = stack[-10];
    goto v_26123;
v_26124:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26125;
v_26126:
    goto v_26122;
v_26123:
    goto v_26124;
v_26125:
    v_27295 = cons(v_27295, v_27294);
    env = stack[-10];
    goto v_26117;
v_26118:
    v_27294 = stack[0];
    goto v_26119;
v_26120:
    goto v_26116;
v_26117:
    goto v_26118;
v_26119:
    fn = elt(env, 27); // multsq
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_26104;
v_26106:
v_26104:
    v_27294 = stack[-9];
    v_27294 = sub1(v_27294);
    env = stack[-10];
    stack[-3] = v_27294;
    goto v_26158;
v_26154:
    v_27295 = stack[-9];
    goto v_26155;
v_26156:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26157;
v_26158:
    goto v_26154;
v_26155:
    goto v_26156;
v_26157:
    if (v_27295 == v_27294) goto v_26152;
    else goto v_26153;
v_26152:
    v_27294 = stack[0];
    goto v_26151;
v_26153:
    v_27294 = qvalue(elt(env, 7)); // dmode!*
    if (!symbolp(v_27294)) v_27294 = nil;
    else { v_27294 = qfastgets(v_27294);
           if (v_27294 != nil) { v_27294 = elt(v_27294, 5); // convert
#ifdef RECORD_GET
             if (v_27294 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v_27294 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v_27294 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v_27294 == SPID_NOPROP) v_27294 = nil; else v_27294 = lisp_true; }}
#endif
    if (v_27294 == nil) goto v_26167;
    goto v_26176;
v_26172:
    v_27294 = qvalue(elt(env, 7)); // dmode!*
    if (!symbolp(v_27294)) v_27295 = nil;
    else { v_27295 = qfastgets(v_27294);
           if (v_27295 != nil) { v_27295 = elt(v_27295, 34); // i2d
#ifdef RECORD_GET
             if (v_27295 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_27295 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_27295 == SPID_NOPROP) v_27295 = nil; }}
#endif
    goto v_26173;
v_26174:
    v_27294 = stack[-9];
    goto v_26175;
v_26176:
    goto v_26172;
v_26173:
    goto v_26174;
v_26175:
    v_27294 = Lapply1(nil, v_27295, v_27294);
    env = stack[-10];
    fn = elt(env, 35); // int!-equiv!-chk
    v_27294 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    stack[-9] = v_27294;
    v_27294 = (v_27294 == nil ? lisp_true : nil);
    goto v_26165;
v_26167:
    v_27294 = nil;
    goto v_26165;
    v_27294 = nil;
v_26165:
    if (v_27294 == nil) goto v_26163;
    goto v_26189;
v_26185:
    v_27295 = nil;
    goto v_26186;
v_26187:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26188;
v_26189:
    goto v_26185;
v_26186:
    goto v_26187;
v_26188:
    v_27294 = cons(v_27295, v_27294);
    env = stack[-10];
    goto v_26151;
v_26163:
    goto v_26199;
v_26195:
    goto v_26205;
v_26201:
    goto v_26212;
v_26208:
    goto v_26218;
v_26214:
    v_27295 = stack[-8];
    goto v_26215;
v_26216:
    v_27294 = stack[-3];
    goto v_26217;
v_26218:
    goto v_26214;
v_26215:
    goto v_26216;
v_26217:
    fn = elt(env, 28); // to
    v_27295 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    goto v_26209;
v_26210:
    v_27294 = stack[-9];
    goto v_26211;
v_26212:
    goto v_26208;
v_26209:
    goto v_26210;
v_26211:
    v_27294 = cons(v_27295, v_27294);
    env = stack[-10];
    v_27295 = ncons(v_27294);
    env = stack[-10];
    goto v_26202;
v_26203:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26204;
v_26205:
    goto v_26201;
v_26202:
    goto v_26203;
v_26204:
    v_27295 = cons(v_27295, v_27294);
    env = stack[-10];
    goto v_26196;
v_26197:
    v_27294 = stack[0];
    goto v_26198;
v_26199:
    goto v_26195;
v_26196:
    goto v_26197;
v_26198:
    fn = elt(env, 27); // multsq
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    goto v_26151;
    v_27294 = nil;
v_26151:
    {
        fn = elt(env, 36); // rationalizesq
        return (*qfn1(fn))(fn, v_27294);
    }
v_25748:
    goto v_26237;
v_26233:
    v_27295 = stack[-8];
    goto v_26234;
v_26235:
    v_27294 = stack[-7];
    goto v_26236;
v_26237:
    goto v_26233;
v_26234:
    goto v_26235;
v_26236:
    fn = elt(env, 37); // depends
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    if (v_27294 == nil) goto v_26230;
    else goto v_26231;
v_26230:
    goto v_26252;
v_26248:
    v_27295 = stack[-8];
    goto v_26249;
v_26250:
    v_27294 = qvalue(elt(env, 8)); // powlis!*
    goto v_26251;
v_26252:
    goto v_26248;
v_26249:
    goto v_26250;
v_26251:
    v_27294 = Latsoc(nil, v_27295, v_27294);
    stack[-6] = v_27294;
    if (v_27294 == nil) goto v_26246;
    else goto v_26247;
v_26246:
    v_27294 = lisp_true;
    goto v_26245;
v_26247:
    goto v_26264;
v_26260:
    v_27294 = stack[-6];
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    v_27295 = qcar(v_27294);
    goto v_26261;
v_26262:
    v_27294 = stack[-7];
    goto v_26263;
v_26264:
    goto v_26260;
v_26261:
    goto v_26262;
v_26263:
    fn = elt(env, 37); // depends
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    v_27294 = (v_27294 == nil ? lisp_true : nil);
    goto v_26245;
    v_27294 = nil;
v_26245:
    if (v_27294 == nil) goto v_26243;
    v_27294 = qvalue(elt(env, 9)); // !*depend
    v_27294 = (v_27294 == nil ? lisp_true : nil);
    goto v_26241;
v_26243:
    v_27294 = nil;
    goto v_26241;
    v_27294 = nil;
v_26241:
    goto v_26229;
v_26231:
    v_27294 = nil;
    goto v_26229;
    v_27294 = nil;
v_26229:
    if (v_27294 == nil) goto v_26227;
    goto v_26285;
v_26281:
    v_27295 = nil;
    goto v_26282;
v_26283:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26284;
v_26285:
    goto v_26281;
v_26282:
    goto v_26283;
v_26284:
    return cons(v_27295, v_27294);
v_26227:
    v_27294 = qvalue(elt(env, 10)); // !*expanddf
    if (v_27294 == nil) goto v_26291;
    goto v_26307;
v_26303:
    v_27295 = stack[-8];
    goto v_26304;
v_26305:
    v_27294 = qvalue(elt(env, 8)); // powlis!*
    goto v_26306;
v_26307:
    goto v_26303;
v_26304:
    goto v_26305;
v_26306:
    v_27294 = Latsoc(nil, v_27295, v_27294);
    stack[-6] = v_27294;
    if (v_27294 == nil) goto v_26301;
    else goto v_26302;
v_26301:
    v_27294 = lisp_true;
    goto v_26300;
v_26302:
    goto v_26319;
v_26315:
    v_27294 = stack[-6];
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    v_27295 = qcar(v_27294);
    goto v_26316;
v_26317:
    v_27294 = stack[-7];
    goto v_26318;
v_26319:
    goto v_26315;
v_26316:
    goto v_26317;
v_26318:
    fn = elt(env, 37); // depends
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    v_27294 = (v_27294 == nil ? lisp_true : nil);
    goto v_26300;
    v_27294 = nil;
v_26300:
    if (v_27294 == nil) goto v_26298;
    goto v_26335;
v_26331:
    v_27295 = stack[-8];
    goto v_26332;
v_26333:
    v_27294 = qvalue(elt(env, 11)); // depl!*
    goto v_26334;
v_26335:
    goto v_26331;
v_26332:
    goto v_26333;
v_26334:
    v_27294 = Latsoc(nil, v_27295, v_27294);
    stack[-6] = v_27294;
    if (v_27294 == nil) goto v_26329;
    else goto v_26330;
v_26329:
    v_27294 = nil;
    goto v_26328;
v_26330:
    goto v_26346;
v_26342:
    v_27295 = stack[-7];
    goto v_26343;
v_26344:
    v_27294 = stack[-6];
    v_27294 = qcdr(v_27294);
    stack[-6] = v_27294;
    goto v_26345;
v_26346:
    goto v_26342;
v_26343:
    goto v_26344;
v_26345:
    v_27294 = Lmemq(nil, v_27295, v_27294);
    v_27294 = (v_27294 == nil ? lisp_true : nil);
    goto v_26328;
    v_27294 = nil;
v_26328:
    goto v_26296;
v_26298:
    v_27294 = nil;
    goto v_26296;
    v_27294 = nil;
v_26296:
    if (v_27294 == nil) goto v_26291;
    goto v_26362;
v_26356:
    v_27296 = stack[-8];
    goto v_26357;
v_26358:
    v_27295 = stack[-7];
    goto v_26359;
v_26360:
    v_27294 = stack[-6];
    goto v_26361;
v_26362:
    goto v_26356;
v_26357:
    goto v_26358;
v_26359:
    goto v_26360;
v_26361:
    fn = elt(env, 38); // df!-chain!-rule
    v_27294 = (*qfnn(fn))(fn, 3, v_27296, v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_25747;
v_26291:
    goto v_26373;
v_26367:
    v_27296 = elt(env, 12); // df
    goto v_26368;
v_26369:
    v_27295 = stack[-8];
    goto v_26370;
v_26371:
    v_27294 = stack[-7];
    goto v_26372;
v_26373:
    goto v_26367;
v_26368:
    goto v_26369;
v_26370:
    goto v_26371;
v_26372:
    v_27294 = list3(v_27296, v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    v_27294 = stack[0];
    fn = elt(env, 39); // opmtch
    v_27294 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    stack[-6] = v_27294;
    if (v_27294 == nil) goto v_26380;
    v_27294 = stack[-6];
    fn = elt(env, 33); // simp
    v_27294 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    goto v_26378;
v_26380:
    goto v_26392;
v_26388:
    v_27295 = stack[0];
    goto v_26389;
v_26390:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26391;
v_26392:
    goto v_26388;
v_26389:
    goto v_26390;
v_26391:
    fn = elt(env, 40); // mksq
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    goto v_26378;
    v_27294 = nil;
v_26378:
    stack[0] = v_27294;
    goto v_25747;
v_25749:
    goto v_26403;
v_26399:
    v_27294 = stack[-8];
    v_27295 = qcar(v_27294);
    goto v_26400;
v_26401:
    v_27294 = elt(env, 12); // df
    goto v_26402;
v_26403:
    goto v_26399;
v_26400:
    goto v_26401;
v_26402:
    if (v_27295 == v_27294) goto v_26397;
    else goto v_26398;
v_26397:
    goto v_26415;
v_26411:
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    v_27295 = qcar(v_27294);
    goto v_26412;
v_26413:
    v_27294 = stack[-7];
    goto v_26414;
v_26415:
    goto v_26411;
v_26412:
    goto v_26413;
v_26414:
    if (v_27295 == v_27294) goto v_26409;
    else goto v_26410;
v_26409:
    v_27294 = qvalue(elt(env, 13)); // !*commutedf
    if (v_27294 == nil) goto v_26423;
    v_27294 = qvalue(elt(env, 9)); // !*depend
    if (v_27294 == nil) goto v_26426;
    else goto v_26423;
v_26426:
    goto v_26433;
v_26429:
    v_27295 = nil;
    goto v_26430;
v_26431:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26432;
v_26433:
    goto v_26429;
v_26430:
    goto v_26431;
v_26432:
    return cons(v_27295, v_27294);
v_26423:
    v_27294 = qvalue(elt(env, 14)); // !*simpnoncomdf
    if (v_27294 == nil) goto v_26437;
    goto v_26446;
v_26442:
    v_27295 = stack[-7];
    goto v_26443;
v_26444:
    v_27294 = qvalue(elt(env, 11)); // depl!*
    goto v_26445;
v_26446:
    goto v_26442;
v_26443:
    goto v_26444;
v_26445:
    v_27294 = Latsoc(nil, v_27295, v_27294);
    stack[0] = v_27294;
    if (v_27294 == nil) goto v_26437;
    v_27294 = stack[0];
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    if (v_27294 == nil) goto v_26450;
    else goto v_26437;
v_26450:
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    v_27294 = qcar(v_27294);
    stack[-6] = v_27294;
    goto v_26463;
v_26459:
    goto v_26472;
v_26466:
    v_27296 = elt(env, 12); // df
    goto v_26467;
v_26468:
    v_27295 = stack[-8];
    goto v_26469;
v_26470:
    v_27294 = stack[-6];
    goto v_26471;
v_26472:
    goto v_26466;
v_26467:
    goto v_26468;
v_26469:
    goto v_26470;
v_26471:
    v_27294 = list3(v_27296, v_27295, v_27294);
    env = stack[-10];
    fn = elt(env, 33); // simp
    stack[0] = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    goto v_26460;
v_26461:
    goto v_26484;
v_26478:
    v_27296 = elt(env, 12); // df
    goto v_26479;
v_26480:
    v_27295 = stack[-7];
    goto v_26481;
v_26482:
    v_27294 = stack[-6];
    goto v_26483;
v_26484:
    goto v_26478;
v_26479:
    goto v_26480;
v_26481:
    goto v_26482;
v_26483:
    v_27294 = list3(v_27296, v_27295, v_27294);
    env = stack[-10];
    fn = elt(env, 33); // simp
    v_27294 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    goto v_26462;
v_26463:
    goto v_26459;
v_26460:
    goto v_26461;
v_26462:
    fn = elt(env, 41); // quotsq
    v_27294 = (*qfn2(fn))(fn, stack[0], v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_25747;
v_26437:
    goto v_26408;
v_26410:
    goto v_26495;
v_26491:
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    v_27295 = qcar(v_27294);
    goto v_26492;
v_26493:
    v_27294 = elt(env, 15); // int
    goto v_26494;
v_26495:
    goto v_26491;
v_26492:
    goto v_26493;
v_26494:
    if (!consp(v_27295)) goto v_26489;
    v_27295 = qcar(v_27295);
    if (v_27295 == v_27294) goto v_26488;
    else goto v_26489;
v_26488:
    goto v_26508;
v_26504:
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    v_27294 = qcar(v_27294);
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    v_27295 = qcar(v_27294);
    goto v_26505;
v_26506:
    v_27294 = stack[-7];
    goto v_26507;
v_26508:
    goto v_26504;
v_26505:
    goto v_26506;
v_26507:
    if (v_27295 == v_27294) goto v_26502;
    else goto v_26503;
v_26502:
    goto v_26523;
v_26517:
    v_27296 = elt(env, 12); // df
    goto v_26518;
v_26519:
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    v_27294 = qcar(v_27294);
    v_27294 = qcdr(v_27294);
    v_27295 = qcar(v_27294);
    goto v_26520;
v_26521:
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    goto v_26522;
v_26523:
    goto v_26517;
v_26518:
    goto v_26519;
v_26520:
    goto v_26521;
v_26522:
    v_27294 = list2star(v_27296, v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_25750;
v_26503:
    v_27294 = qvalue(elt(env, 16)); // !*allowdfint
    if (v_27294 == nil) goto v_26534;
    goto v_26544;
v_26540:
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    v_27294 = qcar(v_27294);
    v_27294 = qcdr(v_27294);
    v_27294 = qcar(v_27294);
    fn = elt(env, 42); // simp!*
    v_27295 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    goto v_26541;
v_26542:
    v_27294 = stack[-7];
    goto v_26543;
v_26544:
    goto v_26540;
v_26541:
    goto v_26542;
v_26543:
    fn = elt(env, 31); // diffsq
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    fn = elt(env, 43); // not_df_p
    v_27294 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    if (v_27294 == nil) goto v_26534;
    goto v_26559;
v_26553:
    stack[-2] = elt(env, 12); // df
    goto v_26554;
v_26555:
    goto v_26569;
v_26563:
    stack[-1] = elt(env, 15); // int
    goto v_26564;
v_26565:
    v_27294 = stack[0];
    fn = elt(env, 44); // mk!*sq
    v_27295 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    goto v_26566;
v_26567:
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    v_27294 = qcar(v_27294);
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    v_27294 = qcar(v_27294);
    goto v_26568;
v_26569:
    goto v_26563;
v_26564:
    goto v_26565;
v_26566:
    goto v_26567;
v_26568:
    v_27294 = list3(stack[-1], v_27295, v_27294);
    env = stack[-10];
    fn = elt(env, 45); // reval
    v_27295 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    goto v_26556;
v_26557:
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    goto v_26558;
v_26559:
    goto v_26553;
v_26554:
    goto v_26555;
v_26556:
    goto v_26557;
v_26558:
    v_27294 = list2star(stack[-2], v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_25750;
v_26534:
    goto v_26408;
v_26489:
v_26408:
    v_27294 = qvalue(elt(env, 10)); // !*expanddf
    if (v_27294 == nil) goto v_26585;
    goto v_26595;
v_26591:
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    v_27295 = qcar(v_27294);
    goto v_26592;
v_26593:
    v_27294 = stack[-7];
    goto v_26594;
v_26595:
    goto v_26591;
v_26592:
    goto v_26593;
v_26594:
    fn = elt(env, 37); // depends
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    if (v_27294 == nil) goto v_26585;
    goto v_26609;
v_26605:
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    v_27295 = qcar(v_27294);
    goto v_26606;
v_26607:
    v_27294 = qvalue(elt(env, 8)); // powlis!*
    goto v_26608;
v_26609:
    goto v_26605;
v_26606:
    goto v_26607;
v_26608:
    v_27294 = Latsoc(nil, v_27295, v_27294);
    stack[-6] = v_27294;
    if (v_27294 == nil) goto v_26603;
    else goto v_26604;
v_26603:
    v_27294 = lisp_true;
    goto v_26602;
v_26604:
    goto v_26623;
v_26619:
    v_27294 = stack[-6];
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    v_27295 = qcar(v_27294);
    goto v_26620;
v_26621:
    v_27294 = stack[-7];
    goto v_26622;
v_26623:
    goto v_26619;
v_26620:
    goto v_26621;
v_26622:
    fn = elt(env, 37); // depends
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    v_27294 = (v_27294 == nil ? lisp_true : nil);
    goto v_26602;
    v_27294 = nil;
v_26602:
    if (v_27294 == nil) goto v_26585;
    goto v_26640;
v_26636:
    v_27295 = stack[-7];
    goto v_26637;
v_26638:
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    v_27294 = qcar(v_27294);
    goto v_26639;
v_26640:
    goto v_26636;
v_26637:
    goto v_26638;
v_26639:
    fn = elt(env, 46); // smember
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    if (v_27294 == nil) goto v_26633;
    else goto v_26634;
v_26633:
    goto v_26649;
v_26645:
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    v_27295 = qcar(v_27294);
    goto v_26646;
v_26647:
    v_27294 = qvalue(elt(env, 11)); // depl!*
    goto v_26648;
v_26649:
    goto v_26645;
v_26646:
    goto v_26647;
v_26648:
    v_27294 = Lassoc(nil, v_27295, v_27294);
    stack[-6] = v_27294;
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    v_27294 = qcar(v_27294);
    if (!consp(v_27294)) goto v_26658;
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    v_27294 = qcar(v_27294);
    v_27294 = qcdr(v_27294);
    if (v_27294 == nil) goto v_26664;
    else goto v_26665;
v_26664:
    v_27294 = nil;
    goto v_26663;
v_26665:
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    v_27294 = qcar(v_27294);
    v_27294 = qcdr(v_27294);
    fn = elt(env, 47); // get!-all!-kernels
    v_27294 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    goto v_26663;
    v_27294 = nil;
v_26663:
    goto v_26656;
v_26658:
    v_27294 = nil;
    goto v_26656;
    v_27294 = nil;
v_26656:
    stack[-5] = v_27294;
    v_27294 = stack[-6];
    if (v_27294 == nil) goto v_26684;
    v_27294 = stack[-5];
    if (v_27294 == nil) goto v_26684;
    goto v_26696;
v_26692:
    goto v_26702;
v_26698:
    v_27295 = stack[-7];
    goto v_26699;
v_26700:
    v_27294 = stack[-5];
    goto v_26701;
v_26702:
    goto v_26698;
v_26699:
    goto v_26700;
v_26701:
    v_27295 = Ldelete(nil, v_27295, v_27294);
    env = stack[-10];
    goto v_26693;
v_26694:
    v_27294 = stack[-7];
    goto v_26695;
v_26696:
    goto v_26692;
v_26693:
    goto v_26694;
v_26695:
    fn = elt(env, 48); // ldepends
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    if (v_27294 == nil) goto v_26684;
    goto v_26682;
v_26684:
    v_27294 = stack[-6];
    if (v_27294 == nil) goto v_26708;
    goto v_26716;
v_26712:
    v_27295 = stack[-7];
    goto v_26713;
v_26714:
    v_27294 = stack[-6];
    v_27294 = qcdr(v_27294);
    stack[-6] = v_27294;
    goto v_26715;
v_26716:
    goto v_26712;
v_26713:
    goto v_26714;
v_26715:
    v_27294 = Lmemq(nil, v_27295, v_27294);
    if (v_27294 == nil) goto v_26711;
    else goto v_26708;
v_26711:
    goto v_26728;
v_26722:
    v_27296 = stack[-8];
    goto v_26723;
v_26724:
    v_27295 = stack[-7];
    goto v_26725;
v_26726:
    v_27294 = stack[-6];
    goto v_26727;
v_26728:
    goto v_26722;
v_26723:
    goto v_26724;
v_26725:
    goto v_26726;
v_26727:
    fn = elt(env, 38); // df!-chain!-rule
    v_27294 = (*qfnn(fn))(fn, 3, v_27296, v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_25747;
v_26708:
    v_27294 = stack[-5];
    if (v_27294 == nil) goto v_26733;
    goto v_26742;
v_26738:
    v_27295 = stack[-7];
    goto v_26739;
v_26740:
    v_27294 = stack[-5];
    goto v_26741;
v_26742:
    goto v_26738;
v_26739:
    goto v_26740;
v_26741:
    fn = elt(env, 46); // smember
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    if (v_27294 == nil) goto v_26736;
    else goto v_26733;
v_26736:
    goto v_26752;
v_26746:
    v_27296 = stack[-8];
    goto v_26747;
v_26748:
    v_27295 = stack[-7];
    goto v_26749;
v_26750:
    v_27294 = stack[-5];
    goto v_26751;
v_26752:
    goto v_26746;
v_26747:
    goto v_26748;
v_26749:
    goto v_26750;
v_26751:
    fn = elt(env, 38); // df!-chain!-rule
    v_27294 = (*qfnn(fn))(fn, 3, v_27296, v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_25747;
v_26733:
v_26682:
    goto v_26632;
v_26634:
v_26632:
    goto v_26583;
v_26585:
v_26583:
    goto v_26765;
v_26761:
    goto v_26771;
v_26767:
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    stack[0] = qcar(v_27294);
    goto v_26768;
v_26769:
    goto v_26780;
v_26776:
    v_27295 = stack[-8];
    goto v_26777;
v_26778:
    v_27294 = stack[-7];
    goto v_26779;
v_26780:
    goto v_26776;
v_26777:
    goto v_26778;
v_26779:
    fn = elt(env, 49); // merge!-ind!-vars
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    goto v_26770;
v_26771:
    goto v_26767;
v_26768:
    goto v_26769;
v_26770:
    v_27295 = cons(stack[0], v_27294);
    env = stack[-10];
    stack[0] = v_27295;
    goto v_26762;
v_26763:
    v_27294 = elt(env, 12); // df
    if (!symbolp(v_27294)) v_27294 = nil;
    else { v_27294 = qfastgets(v_27294);
           if (v_27294 != nil) { v_27294 = elt(v_27294, 50); // kvalue
#ifdef RECORD_GET
             if (v_27294 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v_27294 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v_27294 == SPID_NOPROP) v_27294 = nil; }}
#endif
    goto v_26764;
v_26765:
    goto v_26761;
v_26762:
    goto v_26763;
v_26764:
    fn = elt(env, 50); // find_sub_df
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    stack[-6] = v_27294;
    if (v_27294 == nil) goto v_26759;
    v_27294 = stack[-6];
    v_27294 = qcar(v_27294);
    fn = elt(env, 33); // simp
    v_27294 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    v_27294 = stack[-6];
    v_27294 = qcdr(v_27294);
    stack[-3] = v_27294;
v_26791:
    v_27294 = stack[-3];
    if (v_27294 == nil) goto v_26796;
    else goto v_26797;
v_26796:
    goto v_26790;
v_26797:
    v_27294 = stack[-3];
    v_27294 = qcar(v_27294);
    stack[-2] = v_27294;
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_27294;
v_26806:
    goto v_26818;
v_26814:
    v_27294 = stack[-2];
    v_27295 = qcdr(v_27294);
    goto v_26815;
v_26816:
    v_27294 = stack[-1];
    goto v_26817;
v_26818:
    goto v_26814;
v_26815:
    goto v_26816;
v_26817:
    v_27294 = difference2(v_27295, v_27294);
    env = stack[-10];
    v_27294 = Lminusp(nil, v_27294);
    env = stack[-10];
    if (v_27294 == nil) goto v_26811;
    goto v_26805;
v_26811:
    goto v_26828;
v_26824:
    v_27295 = stack[0];
    goto v_26825;
v_26826:
    v_27294 = stack[-2];
    v_27294 = qcar(v_27294);
    goto v_26827;
v_26828:
    goto v_26824;
v_26825:
    goto v_26826;
v_26827:
    fn = elt(env, 31); // diffsq
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    v_27294 = stack[-1];
    v_27294 = add1(v_27294);
    env = stack[-10];
    stack[-1] = v_27294;
    goto v_26806;
v_26805:
    v_27294 = stack[-3];
    v_27294 = qcdr(v_27294);
    stack[-3] = v_27294;
    goto v_26791;
v_26790:
    goto v_25747;
v_26759:
    goto v_26843;
v_26839:
    v_27295 = elt(env, 12); // df
    goto v_26840;
v_26841:
    v_27294 = stack[0];
    goto v_26842;
v_26843:
    goto v_26839;
v_26840:
    goto v_26841;
v_26842:
    v_27294 = cons(v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_26757;
v_26757:
    goto v_26396;
v_26398:
    v_27294 = qvalue(elt(env, 17)); // !*df_partial
    if (v_27294 == nil) goto v_26847;
    v_27294 = qvalue(elt(env, 10)); // !*expanddf
    if (v_27294 == nil) goto v_26847;
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    v_27294 = qcar(v_27294);
    if (!consp(v_27294)) goto v_26847;
    goto v_26864;
v_26860:
    v_27294 = stack[-8];
    v_27294 = qcar(v_27294);
    v_27295 = Lexplode(nil, v_27294);
    env = stack[-10];
    goto v_26861;
v_26862:
    v_27294 = elt(env, 18); // (!! !! !_)
    goto v_26863;
v_26864:
    goto v_26860;
v_26861:
    goto v_26862;
v_26863:
    v_27294 = Lnconc(nil, v_27295, v_27294);
    env = stack[-10];
    v_27294 = Lcompress(nil, v_27294);
    env = stack[-10];
    v_27294 = Lintern(nil, v_27294);
    env = stack[-10];
    stack[-6] = v_27294;
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    stack[-5] = v_27294;
    goto v_26876;
v_26872:
    v_27295 = nil;
    goto v_26873;
v_26874:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26875;
v_26876:
    goto v_26872;
v_26873:
    goto v_26874;
v_26875:
    v_27294 = cons(v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    v_27294 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_27294;
    v_27294 = stack[-5];
    stack[-2] = v_27294;
v_26883:
    v_27294 = stack[-2];
    if (v_27294 == nil) goto v_26887;
    else goto v_26888;
v_26887:
    goto v_26882;
v_26888:
    v_27294 = stack[-2];
    v_27294 = qcar(v_27294);
    stack[-1] = v_27294;
    v_27294 = stack[-3];
    v_27294 = add1(v_27294);
    env = stack[-10];
    stack[-3] = v_27294;
    goto v_26912;
v_26906:
    v_27296 = elt(env, 12); // df
    goto v_26907;
v_26908:
    v_27295 = stack[-1];
    goto v_26909;
v_26910:
    v_27294 = stack[-7];
    goto v_26911;
v_26912:
    goto v_26906;
v_26907:
    goto v_26908;
v_26909:
    goto v_26910;
v_26911:
    v_27294 = list3(v_27296, v_27295, v_27294);
    env = stack[-10];
    fn = elt(env, 33); // simp
    v_27294 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    stack[-1] = v_27294;
    v_27294 = qcar(v_27294);
    if (v_27294 == nil) goto v_26903;
    goto v_26922;
v_26918:
    v_27295 = stack[-6];
    goto v_26919;
v_26920:
    v_27294 = stack[-3];
    goto v_26921;
v_26922:
    goto v_26918;
v_26919:
    goto v_26920;
v_26921:
    fn = elt(env, 51); // mkid
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    stack[-4] = v_27294;
    goto v_26932;
v_26926:
    v_27296 = stack[-4];
    goto v_26927;
v_26928:
    v_27295 = elt(env, 20); // simpfn
    goto v_26929;
v_26930:
    v_27294 = elt(env, 21); // simpiden
    goto v_26931;
v_26932:
    goto v_26926;
v_26927:
    goto v_26928;
v_26929:
    goto v_26930;
v_26931:
    v_27294 = Lputprop(nil, 3, v_27296, v_27295, v_27294);
    env = stack[-10];
    goto v_26941;
v_26937:
    goto v_26938;
v_26939:
    goto v_26948;
v_26944:
    goto v_26955;
v_26951:
    v_27295 = stack[-4];
    goto v_26952;
v_26953:
    v_27294 = stack[-5];
    goto v_26954;
v_26955:
    goto v_26951;
v_26952:
    goto v_26953;
v_26954:
    v_27294 = cons(v_27295, v_27294);
    env = stack[-10];
    fn = elt(env, 33); // simp
    v_27295 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    goto v_26945;
v_26946:
    v_27294 = stack[-1];
    goto v_26947;
v_26948:
    goto v_26944;
v_26945:
    goto v_26946;
v_26947:
    fn = elt(env, 27); // multsq
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    goto v_26940;
v_26941:
    goto v_26937;
v_26938:
    goto v_26939;
v_26940:
    fn = elt(env, 29); // addsq
    v_27294 = (*qfn2(fn))(fn, stack[0], v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_26901;
v_26903:
v_26901:
    v_27294 = stack[-2];
    v_27294 = qcdr(v_27294);
    stack[-2] = v_27294;
    goto v_26883;
v_26882:
    goto v_25747;
v_26847:
    goto v_26970;
v_26964:
    v_27296 = elt(env, 12); // df
    goto v_26965;
v_26966:
    v_27295 = stack[-8];
    goto v_26967;
v_26968:
    v_27294 = stack[-7];
    goto v_26969;
v_26970:
    goto v_26964;
v_26965:
    goto v_26966;
v_26967:
    goto v_26968;
v_26969:
    v_27294 = list3(v_27296, v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_26396;
v_26396:
v_25750:
    v_27294 = stack[0];
    fn = elt(env, 39); // opmtch
    v_27294 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    stack[-6] = v_27294;
    if (v_27294 == nil) goto v_26977;
    v_27294 = stack[-6];
    fn = elt(env, 33); // simp
    v_27294 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_26975;
v_26977:
    goto v_26993;
v_26989:
    v_27295 = stack[-8];
    goto v_26990;
v_26991:
    v_27294 = stack[-7];
    goto v_26992;
v_26993:
    goto v_26989;
v_26990:
    goto v_26991;
v_26992:
    fn = elt(env, 37); // depends
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    if (v_27294 == nil) goto v_26986;
    else goto v_26987;
v_26986:
    goto v_27008;
v_27004:
    v_27294 = stack[0];
    v_27294 = qcdr(v_27294);
    v_27295 = qcar(v_27294);
    stack[-8] = v_27295;
    goto v_27005;
v_27006:
    v_27294 = qvalue(elt(env, 8)); // powlis!*
    goto v_27007;
v_27008:
    goto v_27004;
v_27005:
    goto v_27006;
v_27007:
    v_27294 = Latsoc(nil, v_27295, v_27294);
    stack[-6] = v_27294;
    if (v_27294 == nil) goto v_27002;
    else goto v_27003;
v_27002:
    v_27294 = lisp_true;
    goto v_27001;
v_27003:
    goto v_27022;
v_27018:
    v_27294 = stack[-6];
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    v_27295 = qcar(v_27294);
    goto v_27019;
v_27020:
    v_27294 = stack[0];
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    goto v_27021;
v_27022:
    goto v_27018;
v_27019:
    goto v_27020;
v_27021:
    fn = elt(env, 52); // dependsl
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    v_27294 = (v_27294 == nil ? lisp_true : nil);
    goto v_27001;
    v_27294 = nil;
v_27001:
    if (v_27294 == nil) goto v_26999;
    v_27294 = qvalue(elt(env, 9)); // !*depend
    v_27294 = (v_27294 == nil ? lisp_true : nil);
    goto v_26997;
v_26999:
    v_27294 = nil;
    goto v_26997;
    v_27294 = nil;
v_26997:
    goto v_26985;
v_26987:
    v_27294 = nil;
    goto v_26985;
    v_27294 = nil;
v_26985:
    if (v_27294 == nil) goto v_26983;
    goto v_27045;
v_27041:
    v_27295 = nil;
    goto v_27042;
v_27043:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27044;
v_27045:
    goto v_27041;
v_27042:
    goto v_27043;
v_27044:
    return cons(v_27295, v_27294);
v_26983:
    v_27294 = qvalue(elt(env, 10)); // !*expanddf
    if (v_27294 == nil) goto v_27049;
    v_27294 = stack[-8];
    if (!consp(v_27294)) goto v_27056;
    v_27294 = stack[0];
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    if (v_27294 == nil) goto v_27060;
    else goto v_27061;
v_27060:
    goto v_27074;
v_27070:
    v_27294 = stack[-8];
    v_27295 = qcar(v_27294);
    goto v_27071;
v_27072:
    v_27294 = elt(env, 22); // (df int)
    goto v_27073;
v_27074:
    goto v_27070;
v_27071:
    goto v_27072;
v_27073:
    v_27294 = Lmemq(nil, v_27295, v_27294);
    if (v_27294 == nil) goto v_27068;
    else goto v_27069;
v_27068:
    goto v_27088;
v_27084:
    v_27295 = stack[-7];
    goto v_27085;
v_27086:
    v_27294 = stack[-8];
    goto v_27087;
v_27088:
    goto v_27084;
v_27085:
    goto v_27086;
v_27087:
    fn = elt(env, 46); // smember
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    if (v_27294 == nil) goto v_27081;
    else goto v_27082;
v_27081:
    goto v_27099;
v_27095:
    v_27295 = stack[-8];
    goto v_27096;
v_27097:
    v_27294 = qvalue(elt(env, 8)); // powlis!*
    goto v_27098;
v_27099:
    goto v_27095;
v_27096:
    goto v_27097;
v_27098:
    v_27294 = Latsoc(nil, v_27295, v_27294);
    stack[-6] = v_27294;
    if (v_27294 == nil) goto v_27093;
    else goto v_27094;
v_27093:
    v_27294 = lisp_true;
    goto v_27092;
v_27094:
    goto v_27111;
v_27107:
    v_27294 = stack[-6];
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    v_27294 = qcdr(v_27294);
    v_27295 = qcar(v_27294);
    goto v_27108;
v_27109:
    v_27294 = stack[-7];
    goto v_27110;
v_27111:
    goto v_27107;
v_27108:
    goto v_27109;
v_27110:
    fn = elt(env, 37); // depends
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    v_27294 = (v_27294 == nil ? lisp_true : nil);
    goto v_27092;
    v_27294 = nil;
v_27092:
    goto v_27080;
v_27082:
    v_27294 = nil;
    goto v_27080;
    v_27294 = nil;
v_27080:
    goto v_27067;
v_27069:
    v_27294 = nil;
    goto v_27067;
    v_27294 = nil;
v_27067:
    goto v_27059;
v_27061:
    v_27294 = nil;
    goto v_27059;
    v_27294 = nil;
v_27059:
    goto v_27054;
v_27056:
    v_27294 = nil;
    goto v_27054;
    v_27294 = nil;
v_27054:
    if (v_27294 == nil) goto v_27049;
    goto v_27135;
v_27131:
    v_27295 = stack[-8];
    goto v_27132;
v_27133:
    v_27294 = qvalue(elt(env, 11)); // depl!*
    goto v_27134;
v_27135:
    goto v_27131;
v_27132:
    goto v_27133;
v_27134:
    v_27294 = Lassoc(nil, v_27295, v_27294);
    stack[-6] = v_27294;
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    if (v_27294 == nil) goto v_27141;
    else goto v_27142;
v_27141:
    v_27294 = nil;
    goto v_27140;
v_27142:
    v_27294 = stack[-8];
    v_27294 = qcdr(v_27294);
    fn = elt(env, 47); // get!-all!-kernels
    v_27294 = (*qfn1(fn))(fn, v_27294);
    env = stack[-10];
    goto v_27140;
    v_27294 = nil;
v_27140:
    stack[-5] = v_27294;
    v_27294 = stack[-6];
    if (v_27294 == nil) goto v_27154;
    v_27294 = stack[-5];
    if (v_27294 == nil) goto v_27154;
    goto v_27166;
v_27162:
    goto v_27172;
v_27168:
    v_27295 = stack[-7];
    goto v_27169;
v_27170:
    v_27294 = stack[-5];
    goto v_27171;
v_27172:
    goto v_27168;
v_27169:
    goto v_27170;
v_27171:
    v_27295 = Ldelete(nil, v_27295, v_27294);
    env = stack[-10];
    goto v_27163;
v_27164:
    v_27294 = stack[-7];
    goto v_27165;
v_27166:
    goto v_27162;
v_27163:
    goto v_27164;
v_27165:
    fn = elt(env, 48); // ldepends
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    if (v_27294 == nil) goto v_27154;
    goto v_27187;
v_27177:
    v_27298 = elt(env, 23); // "Possible inconsistent dependencies in"
    goto v_27178;
v_27179:
    v_27297 = stack[-8];
    goto v_27180;
v_27181:
    v_27296 = nil;
    goto v_27182;
v_27183:
    v_27295 = nil;
    goto v_27184;
v_27185:
    v_27294 = nil;
    goto v_27186;
v_27187:
    goto v_27177;
v_27178:
    goto v_27179;
v_27180:
    goto v_27181;
v_27182:
    goto v_27183;
v_27184:
    goto v_27185;
v_27186:
    fn = elt(env, 53); // msgpri
    v_27294 = (*qfnn(fn))(fn, 5, v_27298, v_27297, v_27296, v_27295, v_27294);
    env = stack[-10];
    goto v_27198;
v_27194:
    v_27295 = stack[0];
    goto v_27195;
v_27196:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27197;
v_27198:
    goto v_27194;
v_27195:
    goto v_27196;
v_27197:
    fn = elt(env, 40); // mksq
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_27152;
v_27154:
    v_27294 = stack[-6];
    if (v_27294 == nil) goto v_27202;
    goto v_27212;
v_27208:
    v_27295 = stack[-7];
    goto v_27209;
v_27210:
    v_27294 = stack[-6];
    v_27294 = qcdr(v_27294);
    stack[-6] = v_27294;
    goto v_27211;
v_27212:
    goto v_27208;
v_27209:
    goto v_27210;
v_27211:
    v_27294 = Lmemq(nil, v_27295, v_27294);
    if (v_27294 == nil) goto v_27207;
    goto v_27222;
v_27218:
    v_27295 = stack[0];
    goto v_27219;
v_27220:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27221;
v_27222:
    goto v_27218;
v_27219:
    goto v_27220;
v_27221:
    fn = elt(env, 40); // mksq
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_27205;
v_27207:
    goto v_27234;
v_27228:
    v_27296 = stack[-8];
    goto v_27229;
v_27230:
    v_27295 = stack[-7];
    goto v_27231;
v_27232:
    v_27294 = stack[-6];
    goto v_27233;
v_27234:
    goto v_27228;
v_27229:
    goto v_27230;
v_27231:
    goto v_27232;
v_27233:
    fn = elt(env, 38); // df!-chain!-rule
    v_27294 = (*qfnn(fn))(fn, 3, v_27296, v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_27205;
v_27205:
    goto v_27152;
v_27202:
    v_27294 = stack[-5];
    if (v_27294 == nil) goto v_27239;
    goto v_27250;
v_27246:
    v_27295 = stack[-7];
    goto v_27247;
v_27248:
    v_27294 = stack[-5];
    goto v_27249;
v_27250:
    goto v_27246;
v_27247:
    goto v_27248;
v_27249:
    fn = elt(env, 46); // smember
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    if (v_27294 == nil) goto v_27244;
    goto v_27258;
v_27254:
    v_27295 = stack[0];
    goto v_27255;
v_27256:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27257;
v_27258:
    goto v_27254;
v_27255:
    goto v_27256;
v_27257:
    fn = elt(env, 40); // mksq
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    goto v_27242;
v_27244:
    goto v_27270;
v_27264:
    v_27296 = stack[-8];
    goto v_27265;
v_27266:
    v_27295 = stack[-7];
    goto v_27267;
v_27268:
    v_27294 = stack[-5];
    goto v_27269;
v_27270:
    goto v_27264;
v_27265:
    goto v_27266;
v_27267:
    goto v_27268;
v_27269:
    fn = elt(env, 38); // df!-chain!-rule
    v_27294 = (*qfnn(fn))(fn, 3, v_27296, v_27295, v_27294);
    env = stack[-10];
    goto v_27242;
    v_27294 = nil;
v_27242:
    stack[0] = v_27294;
    goto v_27152;
v_27239:
    goto v_27281;
v_27277:
    v_27295 = stack[0];
    goto v_27278;
v_27279:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27280;
v_27281:
    goto v_27277;
v_27278:
    goto v_27279;
v_27280:
    fn = elt(env, 40); // mksq
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_27152;
v_27152:
    goto v_26975;
v_27049:
    goto v_27291;
v_27287:
    v_27295 = stack[0];
    goto v_27288;
v_27289:
    v_27294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27290;
v_27291:
    goto v_27287;
v_27288:
    goto v_27289;
v_27290:
    fn = elt(env, 40); // mksq
    v_27294 = (*qfn2(fn))(fn, v_27295, v_27294);
    env = stack[-10];
    stack[0] = v_27294;
    goto v_26975;
v_26975:
    goto v_25747;
    return onevalue(v_27294);
}



// Code for remdiff

static LispObject CC_remdiff(LispObject env,
                         LispObject v_25734)
{
    env = qenv(env);
    LispObject v_25838, v_25839;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25734);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_25734;
// end of prologue
    v_25838 = stack[-1];
    if (symbolp(v_25838)) goto v_25738;
    v_25838 = stack[-1];
    fn = elt(env, 4); // constp
    v_25838 = (*qfn1(fn))(fn, v_25838);
    env = stack[-5];
    if (v_25838 == nil) goto v_25742;
    else goto v_25738;
v_25742:
    goto v_25739;
v_25738:
    v_25838 = stack[-1];
    goto v_25737;
v_25739:
    goto v_25756;
v_25752:
    v_25838 = stack[-1];
    v_25839 = qcar(v_25838);
    goto v_25753;
v_25754:
    v_25838 = elt(env, 1); // difference
    goto v_25755;
v_25756:
    goto v_25752;
v_25753:
    goto v_25754;
v_25755:
    if (v_25839 == v_25838) goto v_25750;
    else goto v_25751;
v_25750:
    goto v_25767;
v_25761:
    stack[-3] = elt(env, 2); // plus
    goto v_25762;
v_25763:
    v_25838 = stack[-1];
    v_25838 = qcdr(v_25838);
    v_25838 = qcar(v_25838);
    stack[-2] = CC_remdiff(elt(env, 0), v_25838);
    env = stack[-5];
    goto v_25764;
v_25765:
    goto v_25778;
v_25774:
    stack[0] = elt(env, 3); // minus
    goto v_25775;
v_25776:
    v_25838 = stack[-1];
    v_25838 = qcdr(v_25838);
    v_25838 = qcdr(v_25838);
    v_25838 = qcar(v_25838);
    v_25838 = CC_remdiff(elt(env, 0), v_25838);
    env = stack[-5];
    goto v_25777;
v_25778:
    goto v_25774;
v_25775:
    goto v_25776;
v_25777:
    v_25838 = list2(stack[0], v_25838);
    env = stack[-5];
    goto v_25766;
v_25767:
    goto v_25761;
v_25762:
    goto v_25763;
v_25764:
    goto v_25765;
v_25766:
    v_25838 = list3(stack[-3], stack[-2], v_25838);
    goto v_25749;
v_25751:
    goto v_25792;
v_25788:
    v_25838 = stack[-1];
    stack[-4] = qcar(v_25838);
    goto v_25789;
v_25790:
    v_25838 = stack[-1];
    v_25838 = qcdr(v_25838);
    stack[-3] = v_25838;
    v_25838 = stack[-3];
    if (v_25838 == nil) goto v_25805;
    else goto v_25806;
v_25805:
    v_25838 = nil;
    goto v_25799;
v_25806:
    v_25838 = stack[-3];
    v_25838 = qcar(v_25838);
    v_25838 = CC_remdiff(elt(env, 0), v_25838);
    env = stack[-5];
    v_25838 = ncons(v_25838);
    env = stack[-5];
    stack[-1] = v_25838;
    stack[-2] = v_25838;
v_25800:
    v_25838 = stack[-3];
    v_25838 = qcdr(v_25838);
    stack[-3] = v_25838;
    v_25838 = stack[-3];
    if (v_25838 == nil) goto v_25819;
    else goto v_25820;
v_25819:
    v_25838 = stack[-2];
    goto v_25799;
v_25820:
    goto v_25828;
v_25824:
    stack[0] = stack[-1];
    goto v_25825;
v_25826:
    v_25838 = stack[-3];
    v_25838 = qcar(v_25838);
    v_25838 = CC_remdiff(elt(env, 0), v_25838);
    env = stack[-5];
    v_25838 = ncons(v_25838);
    env = stack[-5];
    goto v_25827;
v_25828:
    goto v_25824;
v_25825:
    goto v_25826;
v_25827:
    v_25838 = Lrplacd(nil, stack[0], v_25838);
    env = stack[-5];
    v_25838 = stack[-1];
    v_25838 = qcdr(v_25838);
    stack[-1] = v_25838;
    goto v_25800;
v_25799:
    goto v_25791;
v_25792:
    goto v_25788;
v_25789:
    goto v_25790;
v_25791:
    {
        LispObject v_25845 = stack[-4];
        return cons(v_25845, v_25838);
    }
    v_25838 = nil;
v_25749:
    goto v_25737;
    v_25838 = nil;
v_25737:
    return onevalue(v_25838);
}



// Code for nspaces

static LispObject CC_nspaces(LispObject env,
                         LispObject v_25734)
{
    env = qenv(env);
    LispObject v_25775, v_25776, v_25777;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25734);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_25734;
// end of prologue
    stack[-2] = nil;
    v_25775 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_25775;
v_25743:
    goto v_25755;
v_25751:
    v_25776 = stack[-1];
    goto v_25752;
v_25753:
    v_25775 = stack[0];
    goto v_25754;
v_25755:
    goto v_25751;
v_25752:
    goto v_25753;
v_25754:
    v_25775 = difference2(v_25776, v_25775);
    env = stack[-3];
    v_25775 = Lminusp(nil, v_25775);
    env = stack[-3];
    if (v_25775 == nil) goto v_25748;
    goto v_25742;
v_25748:
    goto v_25766;
v_25760:
    v_25777 = elt(env, 2); // !!
    goto v_25761;
v_25762:
    v_25776 = elt(env, 3); // ! 
    goto v_25763;
v_25764:
    v_25775 = stack[-2];
    goto v_25765;
v_25766:
    goto v_25760;
v_25761:
    goto v_25762;
v_25763:
    goto v_25764;
v_25765:
    v_25775 = list2star(v_25777, v_25776, v_25775);
    env = stack[-3];
    stack[-2] = v_25775;
    v_25775 = stack[0];
    v_25775 = add1(v_25775);
    env = stack[-3];
    stack[0] = v_25775;
    goto v_25743;
v_25742:
    v_25775 = stack[-2];
    v_25775 = Lcompress(nil, v_25775);
        return Lintern(nil, v_25775);
    return onevalue(v_25775);
}



// Code for mk_simpl_map_

static LispObject CC_mk_simpl_map_(LispObject env,
                         LispObject v_25734)
{
    env = qenv(env);
    LispObject v_25744, v_25745;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_25744 = v_25734;
// end of prologue
    goto v_25741;
v_25737:
    v_25745 = v_25744;
    goto v_25738;
v_25739:
    v_25744 = nil;
    goto v_25740;
v_25741:
    goto v_25737;
v_25738:
    goto v_25739;
v_25740:
    {
        fn = elt(env, 1); // mk_simpl_map_1
        return (*qfn2(fn))(fn, v_25745, v_25744);
    }
}



// Code for mk_dummy_ids

static LispObject CC_mk_dummy_ids(LispObject env,
                         LispObject v_25734)
{
    env = qenv(env);
    LispObject v_25776, v_25777;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25734);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_25776 = v_25734;
// end of prologue
    goto v_25746;
v_25742:
    v_25777 = v_25776;
    v_25777 = qcar(v_25777);
    goto v_25743;
v_25744:
    v_25776 = qcdr(v_25776);
    v_25776 = qcar(v_25776);
    goto v_25745;
v_25746:
    goto v_25742;
v_25743:
    goto v_25744;
v_25745:
    fn = elt(env, 5); // intersection
    v_25776 = (*qfn2(fn))(fn, v_25777, v_25776);
    env = stack[-1];
    fn = elt(env, 6); // clean_numid
    v_25776 = (*qfn1(fn))(fn, v_25776);
    env = stack[-1];
    stack[0] = v_25776;
    goto v_25757;
v_25753:
    v_25777 = stack[0];
    goto v_25754;
v_25755:
    v_25776 = elt(env, 2); // dummy
    goto v_25756;
v_25757:
    goto v_25753;
v_25754:
    goto v_25755;
v_25756:
    v_25776 = Lflag(nil, v_25777, v_25776);
    env = stack[-1];
    goto v_25765;
v_25761:
    v_25777 = stack[0];
    goto v_25762;
v_25763:
    v_25776 = elt(env, 3); // reserved
    goto v_25764;
v_25765:
    goto v_25761;
v_25762:
    goto v_25763;
v_25764:
    v_25776 = Lflag(nil, v_25777, v_25776);
    env = stack[-1];
    goto v_25773;
v_25769:
    v_25777 = stack[0];
    goto v_25770;
v_25771:
    v_25776 = qvalue(elt(env, 4)); // dummy_id!*
    goto v_25772;
v_25773:
    goto v_25769;
v_25770:
    goto v_25771;
v_25772:
    fn = elt(env, 7); // union
    v_25776 = (*qfn2(fn))(fn, v_25777, v_25776);
    env = stack[-1];
    qvalue(elt(env, 4)) = v_25776; // dummy_id!*
    v_25776 = nil;
    return onevalue(v_25776);
}



// Code for createtriple

static LispObject CC_createtriple(LispObject env,
                         LispObject v_25734)
{
    env = qenv(env);
    LispObject v_25786, v_25787, v_25788;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25734);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25734);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_25734;
// end of prologue
    v_25786 = (LispObject)48+TAG_FIXNUM; // 3
    v_25786 = Lmkvect(nil, v_25786);
    env = stack[-3];
    stack[-2] = v_25786;
    goto v_25748;
v_25742:
    v_25788 = stack[-2];
    goto v_25743;
v_25744:
    v_25787 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25745;
v_25746:
    v_25786 = qvalue(elt(env, 2)); // fluidbibasistripleid
    goto v_25747;
v_25748:
    goto v_25742;
v_25743:
    goto v_25744;
v_25745:
    goto v_25746;
v_25747:
    *(LispObject *)((char *)v_25788 + (CELL-TAG_VECTOR) + (((intptr_t)v_25787-TAG_FIXNUM)/(16/CELL))) = v_25786;
    goto v_25758;
v_25752:
    v_25788 = stack[-2];
    goto v_25753;
v_25754:
    v_25787 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25755;
v_25756:
    v_25786 = stack[0];
    goto v_25757;
v_25758:
    goto v_25752;
v_25753:
    goto v_25754;
v_25755:
    goto v_25756;
v_25757:
    *(LispObject *)((char *)v_25788 + (CELL-TAG_VECTOR) + (((intptr_t)v_25787-TAG_FIXNUM)/(16/CELL))) = v_25786;
    goto v_25768;
v_25762:
    v_25788 = stack[-2];
    goto v_25763;
v_25764:
    v_25787 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_25765;
v_25766:
    v_25786 = qvalue(elt(env, 2)); // fluidbibasistripleid
    goto v_25767;
v_25768:
    goto v_25762;
v_25763:
    goto v_25764;
v_25765:
    goto v_25766;
v_25767:
    *(LispObject *)((char *)v_25788 + (CELL-TAG_VECTOR) + (((intptr_t)v_25787-TAG_FIXNUM)/(16/CELL))) = v_25786;
    goto v_25778;
v_25772:
    stack[-1] = stack[-2];
    goto v_25773;
v_25774:
    stack[0] = (LispObject)48+TAG_FIXNUM; // 3
    goto v_25775;
v_25776:
    v_25786 = nil;
    v_25786 = ncons(v_25786);
    env = stack[-3];
    goto v_25777;
v_25778:
    goto v_25772;
v_25773:
    goto v_25774;
v_25775:
    goto v_25776;
v_25777:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_25786;
    v_25786 = qvalue(elt(env, 2)); // fluidbibasistripleid
    v_25786 = (LispObject)((intptr_t)(v_25786) + 0x10);
    qvalue(elt(env, 2)) = v_25786; // fluidbibasistripleid
    v_25786 = stack[-2];
    return onevalue(v_25786);
}



setup_type const u46_setup[] =
{
    {"gcdlist",                 CC_gcdlist,     TOO_MANY_1,    WRONG_NO_1},
    {"gigcdsq",                 TOO_FEW_2,      CC_gigcdsq,    WRONG_NO_2},
    {"conditionml",             CC_conditionml, TOO_MANY_1,    WRONG_NO_1},
    {"ieval",                   CC_ieval,       TOO_MANY_1,    WRONG_NO_1},
    {"znumrnil",                CC_znumrnil,    TOO_MANY_1,    WRONG_NO_1},
    {"diford",                  CC_diford,      TOO_MANY_1,    WRONG_NO_1},
    {"letmtr",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_letmtr},
    {"evalmember",              TOO_FEW_2,      CC_evalmember, WRONG_NO_2},
    {"gpargp",                  CC_gpargp,      TOO_MANY_1,    WRONG_NO_1},
    {"extract_vars",            CC_extract_vars,TOO_MANY_1,    WRONG_NO_1},
    {"rat_leq",                 TOO_FEW_2,      CC_rat_leq,    WRONG_NO_2},
    {"ofsf_simplequal",         TOO_FEW_2,      CC_ofsf_simplequal,WRONG_NO_2},
    {"simpexpt2",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_simpexpt2},
    {"mk+resimp+mat",           CC_mkLresimpLmat,TOO_MANY_1,   WRONG_NO_1},
    {"pasf_ceil",               TOO_FEW_2,      CC_pasf_ceil,  WRONG_NO_2},
    {"numir",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_numir},
    {"diffp",                   TOO_FEW_2,      CC_diffp,      WRONG_NO_2},
    {"remdiff",                 CC_remdiff,     TOO_MANY_1,    WRONG_NO_1},
    {"nspaces",                 CC_nspaces,     TOO_MANY_1,    WRONG_NO_1},
    {"mk_simpl_map_",           CC_mk_simpl_map_,TOO_MANY_1,   WRONG_NO_1},
    {"mk_dummy_ids",            CC_mk_dummy_ids,TOO_MANY_1,    WRONG_NO_1},
    {"createtriple",            CC_createtriple,TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u46", (two_args *)"131112 1059015 6465240", 0}
};

// end of generated code
