
// $destdir/u38.c        Machine generated C code

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



// Code for talp_specsub

static LispObject CC_talp_specsub(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21510, v_21511, v_21512;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[0] = v_21392;
    stack[-4] = v_21391;
// end of prologue
    goto v_21411;
v_21407:
    v_21511 = stack[0];
    goto v_21408;
v_21409:
    v_21510 = elt(env, 2); // true
    goto v_21410;
v_21411:
    goto v_21407;
v_21408:
    goto v_21409;
v_21410:
    if (v_21511 == v_21510) goto v_21405;
    else goto v_21406;
v_21405:
    v_21510 = lisp_true;
    goto v_21404;
v_21406:
    goto v_21421;
v_21417:
    v_21511 = stack[0];
    goto v_21418;
v_21419:
    v_21510 = elt(env, 3); // false
    goto v_21420;
v_21421:
    goto v_21417;
v_21418:
    goto v_21419;
v_21420:
    v_21510 = (v_21511 == v_21510 ? lisp_true : nil);
    goto v_21404;
    v_21510 = nil;
v_21404:
    if (v_21510 == nil) goto v_21402;
    v_21510 = stack[0];
    goto v_21397;
v_21402:
    v_21510 = stack[0];
    fn = elt(env, 4); // talp_atfp
    v_21510 = (*qfn1(fn))(fn, v_21510);
    env = stack[-6];
    if (v_21510 == nil) goto v_21429;
    goto v_21439;
v_21433:
    v_21510 = stack[-4];
    v_21512 = qcar(v_21510);
    goto v_21434;
v_21435:
    v_21510 = stack[-4];
    v_21511 = qcdr(v_21510);
    goto v_21436;
v_21437:
    v_21510 = stack[0];
    goto v_21438;
v_21439:
    goto v_21433;
v_21434:
    goto v_21435;
v_21436:
    goto v_21437;
v_21438:
    {
        fn = elt(env, 5); // talp_specsubat
        return (*qfnn(fn))(fn, 3, v_21512, v_21511, v_21510);
    }
v_21429:
    v_21510 = stack[0];
    fn = elt(env, 6); // talp_op
    v_21510 = (*qfn1(fn))(fn, v_21510);
    env = stack[-6];
    goto v_21452;
v_21448:
    stack[-5] = v_21510;
    goto v_21449;
v_21450:
    v_21510 = stack[0];
    fn = elt(env, 7); // talp_argl
    v_21510 = (*qfn1(fn))(fn, v_21510);
    env = stack[-6];
    stack[-3] = v_21510;
    v_21510 = stack[-3];
    if (v_21510 == nil) goto v_21464;
    else goto v_21465;
v_21464:
    v_21510 = nil;
    goto v_21458;
v_21465:
    v_21510 = stack[-3];
    v_21510 = qcar(v_21510);
    goto v_21477;
v_21473:
    v_21511 = stack[-4];
    goto v_21474;
v_21475:
    goto v_21476;
v_21477:
    goto v_21473;
v_21474:
    goto v_21475;
v_21476:
    v_21510 = CC_talp_specsub(elt(env, 0), v_21511, v_21510);
    env = stack[-6];
    v_21510 = ncons(v_21510);
    env = stack[-6];
    stack[-1] = v_21510;
    stack[-2] = v_21510;
v_21459:
    v_21510 = stack[-3];
    v_21510 = qcdr(v_21510);
    stack[-3] = v_21510;
    v_21510 = stack[-3];
    if (v_21510 == nil) goto v_21484;
    else goto v_21485;
v_21484:
    v_21510 = stack[-2];
    goto v_21458;
v_21485:
    goto v_21493;
v_21489:
    stack[0] = stack[-1];
    goto v_21490;
v_21491:
    v_21510 = stack[-3];
    v_21510 = qcar(v_21510);
    goto v_21504;
v_21500:
    v_21511 = stack[-4];
    goto v_21501;
v_21502:
    goto v_21503;
v_21504:
    goto v_21500;
v_21501:
    goto v_21502;
v_21503:
    v_21510 = CC_talp_specsub(elt(env, 0), v_21511, v_21510);
    env = stack[-6];
    v_21510 = ncons(v_21510);
    env = stack[-6];
    goto v_21492;
v_21493:
    goto v_21489;
v_21490:
    goto v_21491;
v_21492:
    v_21510 = Lrplacd(nil, stack[0], v_21510);
    env = stack[-6];
    v_21510 = stack[-1];
    v_21510 = qcdr(v_21510);
    stack[-1] = v_21510;
    goto v_21459;
v_21458:
    goto v_21451;
v_21452:
    goto v_21448;
v_21449:
    goto v_21450;
v_21451:
    {
        LispObject v_21519 = stack[-5];
        return cons(v_21519, v_21510);
    }
v_21397:
    return onevalue(v_21510);
}



// Code for ithlistelem

static LispObject CC_ithlistelem(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21426, v_21427;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21392;
    stack[-1] = v_21391;
// end of prologue
    v_21426 = stack[-1];
    if (v_21426 == nil) goto v_21400;
    goto v_21407;
v_21403:
    goto v_21413;
v_21409:
    v_21426 = stack[-1];
    v_21427 = qcar(v_21426);
    goto v_21410;
v_21411:
    v_21426 = stack[0];
    goto v_21412;
v_21413:
    goto v_21409;
v_21410:
    goto v_21411;
v_21412:
    fn = elt(env, 1); // nth
    stack[-2] = (*qfn2(fn))(fn, v_21427, v_21426);
    env = stack[-3];
    goto v_21404;
v_21405:
    goto v_21422;
v_21418:
    v_21426 = stack[-1];
    v_21427 = qcdr(v_21426);
    goto v_21419;
v_21420:
    v_21426 = stack[0];
    goto v_21421;
v_21422:
    goto v_21418;
v_21419:
    goto v_21420;
v_21421:
    v_21426 = CC_ithlistelem(elt(env, 0), v_21427, v_21426);
    goto v_21406;
v_21407:
    goto v_21403;
v_21404:
    goto v_21405;
v_21406:
    {
        LispObject v_21431 = stack[-2];
        return cons(v_21431, v_21426);
    }
v_21400:
    v_21426 = nil;
    return onevalue(v_21426);
}



// Code for sparpri

static LispObject CC_sparpri(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21463, v_21464, v_21465;
    LispObject fn;
    LispObject v_21393, v_21392, v_21391;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sparpri");
    va_start(aa, nargs);
    v_21391 = va_arg(aa, LispObject);
    v_21392 = va_arg(aa, LispObject);
    v_21393 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21393,v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21391,v_21392,v_21393);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_21393;
    v_21463 = v_21392;
    v_21464 = v_21391;
// end of prologue
    stack[-5] = v_21463;
    v_21463 = v_21464;
    stack[-3] = v_21463;
v_21405:
    v_21463 = stack[-3];
    if (v_21463 == nil) goto v_21409;
    else goto v_21410;
v_21409:
    goto v_21404;
v_21410:
    v_21463 = stack[-3];
    v_21463 = qcar(v_21463);
    stack[-2] = v_21463;
    goto v_21421;
v_21417:
    goto v_21427;
v_21423:
    stack[-1] = elt(env, 2); // quote
    goto v_21424;
v_21425:
    goto v_21436;
v_21430:
    stack[0] = elt(env, 3); // setq
    goto v_21431;
v_21432:
    goto v_21445;
v_21439:
    v_21465 = stack[-4];
    goto v_21440;
v_21441:
    v_21464 = stack[-5];
    goto v_21442;
v_21443:
    v_21463 = stack[-2];
    v_21463 = qcar(v_21463);
    goto v_21444;
v_21445:
    goto v_21439;
v_21440:
    goto v_21441;
v_21442:
    goto v_21443;
v_21444:
    v_21464 = list3(v_21465, v_21464, v_21463);
    env = stack[-6];
    goto v_21433;
v_21434:
    v_21463 = stack[-2];
    v_21463 = qcdr(v_21463);
    goto v_21435;
v_21436:
    goto v_21430;
v_21431:
    goto v_21432;
v_21433:
    goto v_21434;
v_21435:
    v_21463 = list3(stack[0], v_21464, v_21463);
    env = stack[-6];
    goto v_21426;
v_21427:
    goto v_21423;
v_21424:
    goto v_21425;
v_21426:
    v_21464 = list2(stack[-1], v_21463);
    env = stack[-6];
    goto v_21418;
v_21419:
    v_21463 = elt(env, 4); // first
    goto v_21420;
v_21421:
    goto v_21417;
v_21418:
    goto v_21419;
v_21420:
    fn = elt(env, 7); // writepri
    v_21463 = (*qfn2(fn))(fn, v_21464, v_21463);
    env = stack[-6];
    goto v_21458;
v_21454:
    v_21464 = elt(env, 5); // (quote !$)
    goto v_21455;
v_21456:
    v_21463 = elt(env, 6); // last
    goto v_21457;
v_21458:
    goto v_21454;
v_21455:
    goto v_21456;
v_21457:
    fn = elt(env, 7); // writepri
    v_21463 = (*qfn2(fn))(fn, v_21464, v_21463);
    env = stack[-6];
    v_21463 = stack[-3];
    v_21463 = qcdr(v_21463);
    stack[-3] = v_21463;
    goto v_21405;
v_21404:
    v_21463 = nil;
    return onevalue(v_21463);
}



// Code for evalb

static LispObject CC_evalb(LispObject env,
                         LispObject v_21391)
{
    env = qenv(env);
    LispObject v_21413, v_21414, v_21415;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21391);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21413 = v_21391;
// end of prologue
    goto v_21405;
v_21399:
    v_21415 = v_21413;
    goto v_21400;
v_21401:
    v_21414 = nil;
    goto v_21402;
v_21403:
    v_21413 = elt(env, 1); // algebraic
    goto v_21404;
v_21405:
    goto v_21399;
v_21400:
    goto v_21401;
v_21402:
    goto v_21403;
v_21404:
    fn = elt(env, 4); // formbool
    v_21413 = (*qfnn(fn))(fn, 3, v_21415, v_21414, v_21413);
    env = stack[0];
    fn = elt(env, 5); // eval
    v_21413 = (*qfn1(fn))(fn, v_21413);
    env = stack[0];
    if (v_21413 == nil) goto v_21396;
    v_21413 = elt(env, 2); // true
    goto v_21394;
v_21396:
    v_21413 = elt(env, 3); // false
    goto v_21394;
    v_21413 = nil;
v_21394:
    return onevalue(v_21413);
}



// Code for min0

static LispObject CC_min0(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21409, v_21410;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21409 = v_21392;
    v_21410 = v_21391;
// end of prologue
    goto v_21399;
v_21395:
    goto v_21405;
v_21401:
    goto v_21402;
v_21403:
    goto v_21404;
v_21405:
    goto v_21401;
v_21402:
    goto v_21403;
v_21404:
    fn = elt(env, 1); // min
    v_21410 = (*qfn2(fn))(fn, v_21410, v_21409);
    env = stack[0];
    goto v_21396;
v_21397:
    v_21409 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21398;
v_21399:
    goto v_21395;
v_21396:
    goto v_21397;
v_21398:
    {
        fn = elt(env, 2); // max
        return (*qfn2(fn))(fn, v_21410, v_21409);
    }
}



// Code for physoptimes

static LispObject CC_physoptimes(LispObject env,
                         LispObject v_21391)
{
    env = qenv(env);
    LispObject v_21649, v_21650;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21391);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[0] = v_21391;
// end of prologue
    stack[-2] = nil;
    goto v_21416;
v_21412:
    v_21650 = qvalue(elt(env, 2)); // tstack!*
    goto v_21413;
v_21414:
    v_21649 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21415;
v_21416:
    goto v_21412;
v_21413:
    goto v_21414;
v_21415:
    if (v_21650 == v_21649) goto v_21410;
    else goto v_21411;
v_21410:
    v_21649 = qvalue(elt(env, 3)); // mul!*
    goto v_21409;
v_21411:
    v_21649 = nil;
    goto v_21409;
    v_21649 = nil;
v_21409:
    if (v_21649 == nil) goto v_21407;
    v_21649 = qvalue(elt(env, 3)); // mul!*
    stack[-2] = v_21649;
    v_21649 = nil;
    qvalue(elt(env, 3)) = v_21649; // mul!*
    goto v_21405;
v_21407:
v_21405:
    v_21649 = qvalue(elt(env, 2)); // tstack!*
    v_21649 = add1(v_21649);
    env = stack[-7];
    qvalue(elt(env, 2)) = v_21649; // tstack!*
    v_21649 = stack[0];
    v_21649 = qcar(v_21649);
    fn = elt(env, 5); // physopsim!*
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    stack[-6] = v_21649;
    v_21649 = stack[0];
    v_21649 = qcdr(v_21649);
    stack[-1] = v_21649;
v_21434:
    v_21649 = stack[-1];
    if (v_21649 == nil) goto v_21439;
    else goto v_21440;
v_21439:
    goto v_21433;
v_21440:
    v_21649 = stack[-1];
    v_21649 = qcar(v_21649);
    fn = elt(env, 5); // physopsim!*
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    stack[-5] = v_21649;
    v_21649 = stack[-6];
    fn = elt(env, 6); // getphystype
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    stack[-4] = v_21649;
    v_21649 = stack[-5];
    fn = elt(env, 6); // getphystype
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    stack[-3] = v_21649;
    v_21649 = stack[-4];
    if (v_21649 == nil) goto v_21454;
    else goto v_21455;
v_21454:
    v_21649 = stack[-3];
    if (v_21649 == nil) goto v_21459;
    else goto v_21460;
v_21459:
    goto v_21468;
v_21464:
    v_21649 = stack[-6];
    fn = elt(env, 7); // physop2sq
    stack[0] = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    goto v_21465;
v_21466:
    v_21649 = stack[-5];
    fn = elt(env, 7); // physop2sq
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    goto v_21467;
v_21468:
    goto v_21464;
v_21465:
    goto v_21466;
v_21467:
    fn = elt(env, 8); // multsq
    v_21649 = (*qfn2(fn))(fn, stack[0], v_21649);
    env = stack[-7];
    fn = elt(env, 9); // mk!*sq
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    stack[-6] = v_21649;
    goto v_21458;
v_21460:
    v_21649 = stack[-6];
    v_21649 = (LispObject)zerop(v_21649);
    v_21649 = v_21649 ? lisp_true : nil;
    env = stack[-7];
    if (v_21649 == nil) goto v_21474;
    goto v_21483;
v_21479:
    v_21650 = nil;
    goto v_21480;
v_21481:
    v_21649 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21482;
v_21483:
    goto v_21479;
v_21480:
    goto v_21481;
v_21482:
    v_21649 = cons(v_21650, v_21649);
    env = stack[-7];
    fn = elt(env, 9); // mk!*sq
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    stack[-6] = v_21649;
    goto v_21458;
v_21474:
    v_21649 = stack[-6];
    v_21649 = Lonep(nil, v_21649);
    env = stack[-7];
    if (v_21649 == nil) goto v_21487;
    v_21649 = stack[-5];
    fn = elt(env, 7); // physop2sq
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    fn = elt(env, 9); // mk!*sq
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    stack[-6] = v_21649;
    goto v_21458;
v_21487:
    goto v_21501;
v_21497:
    v_21649 = stack[-6];
    fn = elt(env, 7); // physop2sq
    stack[0] = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    goto v_21498;
v_21499:
    v_21649 = stack[-5];
    fn = elt(env, 7); // physop2sq
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    goto v_21500;
v_21501:
    goto v_21497;
v_21498:
    goto v_21499;
v_21500:
    fn = elt(env, 8); // multsq
    v_21649 = (*qfn2(fn))(fn, stack[0], v_21649);
    env = stack[-7];
    fn = elt(env, 9); // mk!*sq
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    stack[-6] = v_21649;
    goto v_21458;
v_21458:
    goto v_21453;
v_21455:
    v_21649 = stack[-3];
    if (v_21649 == nil) goto v_21506;
    else goto v_21507;
v_21506:
    v_21649 = stack[-5];
    v_21649 = (LispObject)zerop(v_21649);
    v_21649 = v_21649 ? lisp_true : nil;
    env = stack[-7];
    if (v_21649 == nil) goto v_21512;
    goto v_21521;
v_21517:
    v_21650 = nil;
    goto v_21518;
v_21519:
    v_21649 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21520;
v_21521:
    goto v_21517;
v_21518:
    goto v_21519;
v_21520:
    v_21649 = cons(v_21650, v_21649);
    env = stack[-7];
    fn = elt(env, 9); // mk!*sq
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    goto v_21510;
v_21512:
    v_21649 = stack[-5];
    v_21649 = Lonep(nil, v_21649);
    env = stack[-7];
    if (v_21649 == nil) goto v_21525;
    v_21649 = stack[-6];
    fn = elt(env, 7); // physop2sq
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    fn = elt(env, 9); // mk!*sq
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    goto v_21510;
v_21525:
    goto v_21539;
v_21535:
    v_21649 = stack[-5];
    fn = elt(env, 7); // physop2sq
    stack[0] = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    goto v_21536;
v_21537:
    v_21649 = stack[-6];
    fn = elt(env, 7); // physop2sq
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    goto v_21538;
v_21539:
    goto v_21535;
v_21536:
    goto v_21537;
v_21538:
    fn = elt(env, 8); // multsq
    v_21649 = (*qfn2(fn))(fn, stack[0], v_21649);
    env = stack[-7];
    fn = elt(env, 9); // mk!*sq
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    goto v_21510;
    v_21649 = nil;
v_21510:
    stack[-6] = v_21649;
    goto v_21453;
v_21507:
    goto v_21552;
v_21548:
    v_21649 = stack[-6];
    fn = elt(env, 10); // physopaeval
    stack[0] = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    goto v_21549;
v_21550:
    v_21649 = stack[-5];
    fn = elt(env, 10); // physopaeval
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    goto v_21551;
v_21552:
    goto v_21548;
v_21549:
    goto v_21550;
v_21551:
    fn = elt(env, 11); // physopordchk
    v_21649 = (*qfn2(fn))(fn, stack[0], v_21649);
    env = stack[-7];
    if (v_21649 == nil) goto v_21545;
    goto v_21566;
v_21562:
    v_21650 = stack[-4];
    goto v_21563;
v_21564:
    v_21649 = stack[-3];
    goto v_21565;
v_21566:
    goto v_21562;
v_21563:
    goto v_21564;
v_21565:
    if (equal(v_21650, v_21649)) goto v_21560;
    else goto v_21561;
v_21560:
    goto v_21573;
v_21569:
    v_21650 = stack[-4];
    goto v_21570;
v_21571:
    v_21649 = elt(env, 4); // scalar
    goto v_21572;
v_21573:
    goto v_21569;
v_21570:
    goto v_21571;
v_21572:
    v_21649 = (v_21650 == v_21649 ? lisp_true : nil);
    goto v_21559;
v_21561:
    v_21649 = nil;
    goto v_21559;
    v_21649 = nil;
v_21559:
    if (v_21649 == nil) goto v_21545;
    goto v_21586;
v_21582:
    v_21649 = stack[-6];
    fn = elt(env, 7); // physop2sq
    stack[0] = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    goto v_21583;
v_21584:
    v_21649 = stack[-5];
    fn = elt(env, 7); // physop2sq
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    goto v_21585;
v_21586:
    goto v_21582;
v_21583:
    goto v_21584;
v_21585:
    fn = elt(env, 8); // multsq
    v_21649 = (*qfn2(fn))(fn, stack[0], v_21649);
    env = stack[-7];
    fn = elt(env, 9); // mk!*sq
    v_21649 = (*qfn1(fn))(fn, v_21649);
    env = stack[-7];
    stack[-6] = v_21649;
    goto v_21453;
v_21545:
    goto v_21598;
v_21594:
    v_21650 = stack[-6];
    goto v_21595;
v_21596:
    v_21649 = stack[-5];
    goto v_21597;
v_21598:
    goto v_21594;
v_21595:
    goto v_21596;
v_21597:
    fn = elt(env, 12); // multopop!*
    v_21649 = (*qfn2(fn))(fn, v_21650, v_21649);
    env = stack[-7];
    stack[-6] = v_21649;
    goto v_21453;
v_21453:
    v_21649 = stack[-1];
    v_21649 = qcdr(v_21649);
    stack[-1] = v_21649;
    goto v_21434;
v_21433:
v_21401:
    v_21649 = qvalue(elt(env, 3)); // mul!*
    if (v_21649 == nil) goto v_21609;
    else goto v_21610;
v_21609:
    v_21649 = lisp_true;
    goto v_21608;
v_21610:
    goto v_21620;
v_21616:
    v_21650 = qvalue(elt(env, 2)); // tstack!*
    goto v_21617;
v_21618:
    v_21649 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21619;
v_21620:
    goto v_21616;
v_21617:
    goto v_21618;
v_21619:
    v_21649 = (LispObject)greaterp2(v_21650, v_21649);
    v_21649 = v_21649 ? lisp_true : nil;
    env = stack[-7];
    goto v_21608;
    v_21649 = nil;
v_21608:
    if (v_21649 == nil) goto v_21606;
    goto v_21402;
v_21606:
    goto v_21628;
v_21624:
    v_21649 = qvalue(elt(env, 3)); // mul!*
    v_21650 = qcar(v_21649);
    goto v_21625;
v_21626:
    v_21649 = stack[-6];
    goto v_21627;
v_21628:
    goto v_21624;
v_21625:
    goto v_21626;
v_21627:
    v_21649 = Lapply1(nil, v_21650, v_21649);
    env = stack[-7];
    stack[-6] = v_21649;
    v_21649 = qvalue(elt(env, 3)); // mul!*
    v_21649 = qcdr(v_21649);
    qvalue(elt(env, 3)) = v_21649; // mul!*
    goto v_21401;
v_21402:
    v_21649 = qvalue(elt(env, 2)); // tstack!*
    v_21649 = sub1(v_21649);
    env = stack[-7];
    qvalue(elt(env, 2)) = v_21649; // tstack!*
    goto v_21644;
v_21640:
    v_21650 = qvalue(elt(env, 2)); // tstack!*
    goto v_21641;
v_21642:
    v_21649 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21643;
v_21644:
    goto v_21640;
v_21641:
    goto v_21642;
v_21643:
    if (v_21650 == v_21649) goto v_21638;
    else goto v_21639;
v_21638:
    v_21649 = stack[-2];
    qvalue(elt(env, 3)) = v_21649; // mul!*
    goto v_21637;
v_21639:
v_21637:
    v_21649 = stack[-6];
    return onevalue(v_21649);
}



// Code for deletez1

static LispObject CC_deletez1(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21439, v_21440, v_21441, v_21442;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21392;
    stack[-1] = v_21391;
// end of prologue
    v_21442 = nil;
v_21397:
    v_21439 = stack[-1];
    if (v_21439 == nil) goto v_21400;
    else goto v_21401;
v_21400:
    v_21439 = v_21442;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_21439);
    }
v_21401:
    goto v_21411;
v_21407:
    v_21441 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21408;
v_21409:
    goto v_21417;
v_21413:
    v_21439 = stack[-1];
    v_21439 = qcar(v_21439);
    v_21440 = qcar(v_21439);
    goto v_21414;
v_21415:
    v_21439 = stack[0];
    goto v_21416;
v_21417:
    goto v_21413;
v_21414:
    goto v_21415;
v_21416:
    v_21439 = Lassoc(nil, v_21440, v_21439);
    v_21439 = qcdr(v_21439);
    goto v_21410;
v_21411:
    goto v_21407;
v_21408:
    goto v_21409;
v_21410:
    if (v_21441 == v_21439) goto v_21405;
    else goto v_21406;
v_21405:
    v_21439 = stack[-1];
    v_21439 = qcdr(v_21439);
    stack[-1] = v_21439;
    goto v_21397;
v_21406:
    goto v_21433;
v_21429:
    v_21439 = stack[-1];
    v_21439 = qcar(v_21439);
    goto v_21430;
v_21431:
    v_21440 = v_21442;
    goto v_21432;
v_21433:
    goto v_21429;
v_21430:
    goto v_21431;
v_21432:
    v_21439 = cons(v_21439, v_21440);
    env = stack[-2];
    v_21442 = v_21439;
    v_21439 = stack[-1];
    v_21439 = qcdr(v_21439);
    stack[-1] = v_21439;
    goto v_21397;
    v_21439 = nil;
    return onevalue(v_21439);
}



// Code for assert_procstat!-argl

static LispObject CC_assert_procstatKargl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21564, v_21565, v_21566;
    LispObject fn;
    argcheck(nargs, 0, "assert_procstat-argl");
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
    stack[0] = nil;
v_21401:
    goto v_21410;
v_21406:
    v_21565 = qvalue(elt(env, 2)); // cursym!*
    goto v_21407;
v_21408:
    v_21564 = elt(env, 3); // !*rpar!*
    goto v_21409;
v_21410:
    goto v_21406;
v_21407:
    goto v_21408;
v_21409:
    if (v_21565 == v_21564) goto v_21404;
    else goto v_21405;
v_21404:
    goto v_21400;
v_21405:
    fn = elt(env, 13); // eolcheck
    v_21564 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    v_21564 = qvalue(elt(env, 2)); // cursym!*
    if (symbolp(v_21564)) goto v_21418;
    goto v_21426;
v_21422:
    v_21565 = elt(env, 4); // "Expecting identifier but found"
    goto v_21423;
v_21424:
    v_21564 = qvalue(elt(env, 2)); // cursym!*
    goto v_21425;
v_21426:
    goto v_21422;
v_21423:
    goto v_21424;
v_21425:
    v_21564 = list2(v_21565, v_21564);
    env = stack[-3];
    fn = elt(env, 14); // assert_rederr
    v_21564 = (*qfn1(fn))(fn, v_21564);
    env = stack[-3];
    goto v_21416;
v_21418:
v_21416:
    v_21564 = qvalue(elt(env, 2)); // cursym!*
    stack[-2] = v_21564;
    fn = elt(env, 15); // scan
    v_21564 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_21439;
v_21435:
    v_21565 = qvalue(elt(env, 2)); // cursym!*
    goto v_21436;
v_21437:
    v_21564 = elt(env, 5); // !*colon!*
    goto v_21438;
v_21439:
    goto v_21435;
v_21436:
    goto v_21437;
v_21438:
    if (v_21565 == v_21564) goto v_21433;
    else goto v_21434;
v_21433:
    fn = elt(env, 15); // scan
    v_21564 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    v_21564 = qvalue(elt(env, 2)); // cursym!*
    fn = elt(env, 16); // assert_typesyntaxp
    v_21564 = (*qfn1(fn))(fn, v_21564);
    env = stack[-3];
    if (v_21564 == nil) goto v_21445;
    else goto v_21446;
v_21445:
    goto v_21455;
v_21451:
    v_21565 = elt(env, 6); // "Expecting type but found"
    goto v_21452;
v_21453:
    v_21564 = qvalue(elt(env, 2)); // cursym!*
    goto v_21454;
v_21455:
    goto v_21451;
v_21452:
    goto v_21453;
v_21454:
    v_21564 = list2(v_21565, v_21564);
    env = stack[-3];
    fn = elt(env, 14); // assert_rederr
    v_21564 = (*qfn1(fn))(fn, v_21564);
    env = stack[-3];
    goto v_21444;
v_21446:
v_21444:
    v_21564 = qvalue(elt(env, 2)); // cursym!*
    stack[-1] = v_21564;
    fn = elt(env, 15); // scan
    v_21564 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    v_21564 = stack[-1];
    goto v_21432;
v_21434:
    v_21564 = nil;
v_21432:
    goto v_21468;
v_21462:
    v_21566 = stack[-2];
    goto v_21463;
v_21464:
    v_21565 = v_21564;
    goto v_21465;
v_21466:
    v_21564 = stack[0];
    goto v_21467;
v_21468:
    goto v_21462;
v_21463:
    goto v_21464;
v_21465:
    goto v_21466;
v_21467:
    v_21564 = acons(v_21566, v_21565, v_21564);
    env = stack[-3];
    stack[0] = v_21564;
    goto v_21480;
v_21476:
    v_21565 = qvalue(elt(env, 2)); // cursym!*
    goto v_21477;
v_21478:
    v_21564 = elt(env, 7); // (!*comma!* !*rpar!*)
    goto v_21479;
v_21480:
    goto v_21476;
v_21477:
    goto v_21478;
v_21479:
    v_21564 = Lmemq(nil, v_21565, v_21564);
    if (v_21564 == nil) goto v_21474;
    else goto v_21475;
v_21474:
    goto v_21490;
v_21486:
    v_21565 = elt(env, 8); // "Expecting ',' or ')' but found"
    goto v_21487;
v_21488:
    v_21564 = qvalue(elt(env, 2)); // cursym!*
    goto v_21489;
v_21490:
    goto v_21486;
v_21487:
    goto v_21488;
v_21489:
    v_21564 = list2(v_21565, v_21564);
    env = stack[-3];
    fn = elt(env, 14); // assert_rederr
    v_21564 = (*qfn1(fn))(fn, v_21564);
    env = stack[-3];
    goto v_21473;
v_21475:
v_21473:
    goto v_21501;
v_21497:
    v_21565 = qvalue(elt(env, 2)); // cursym!*
    goto v_21498;
v_21499:
    v_21564 = elt(env, 9); // !*comma!*
    goto v_21500;
v_21501:
    goto v_21497;
v_21498:
    goto v_21499;
v_21500:
    if (v_21565 == v_21564) goto v_21495;
    else goto v_21496;
v_21495:
    fn = elt(env, 15); // scan
    v_21564 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_21494;
v_21496:
v_21494:
    goto v_21401;
v_21400:
    goto v_21518;
v_21514:
    v_21565 = qvalue(elt(env, 10)); // nxtsym!*
    goto v_21515;
v_21516:
    v_21564 = elt(env, 5); // !*colon!*
    goto v_21517;
v_21518:
    goto v_21514;
v_21515:
    goto v_21516;
v_21517:
    if (v_21565 == v_21564) goto v_21512;
    else goto v_21513;
v_21512:
    v_21564 = lisp_true;
    goto v_21511;
v_21513:
    goto v_21528;
v_21524:
    v_21565 = qvalue(elt(env, 10)); // nxtsym!*
    goto v_21525;
v_21526:
    v_21564 = elt(env, 11); // !:
    goto v_21527;
v_21528:
    goto v_21524;
v_21525:
    goto v_21526;
v_21527:
    v_21564 = (v_21565 == v_21564 ? lisp_true : nil);
    goto v_21511;
    v_21564 = nil;
v_21511:
    if (v_21564 == nil) goto v_21509;
    fn = elt(env, 15); // scan
    v_21564 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    fn = elt(env, 15); // scan
    v_21564 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    v_21564 = qvalue(elt(env, 2)); // cursym!*
    fn = elt(env, 16); // assert_typesyntaxp
    v_21564 = (*qfn1(fn))(fn, v_21564);
    env = stack[-3];
    if (v_21564 == nil) goto v_21536;
    else goto v_21537;
v_21536:
    goto v_21546;
v_21542:
    v_21565 = elt(env, 6); // "Expecting type but found"
    goto v_21543;
v_21544:
    v_21564 = qvalue(elt(env, 2)); // cursym!*
    goto v_21545;
v_21546:
    goto v_21542;
v_21543:
    goto v_21544;
v_21545:
    v_21564 = list2(v_21565, v_21564);
    env = stack[-3];
    fn = elt(env, 14); // assert_rederr
    v_21564 = (*qfn1(fn))(fn, v_21564);
    env = stack[-3];
    goto v_21535;
v_21537:
v_21535:
    v_21564 = qvalue(elt(env, 2)); // cursym!*
    goto v_21507;
v_21509:
    v_21564 = nil;
v_21507:
    goto v_21557;
v_21551:
    v_21566 = elt(env, 12); // returnvalue
    goto v_21552;
v_21553:
    v_21565 = v_21564;
    goto v_21554;
v_21555:
    v_21564 = stack[0];
    goto v_21556;
v_21557:
    goto v_21551;
v_21552:
    goto v_21553;
v_21554:
    goto v_21555;
v_21556:
    v_21564 = acons(v_21566, v_21565, v_21564);
    stack[0] = v_21564;
    v_21564 = stack[0];
        return Lnreverse(nil, v_21564);
    return onevalue(v_21564);
}



// Code for remchkf1

static LispObject CC_remchkf1(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21441, v_21442, v_21443;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21392;
    stack[-1] = v_21391;
// end of prologue
    v_21441 = stack[-1];
    fn = elt(env, 4); // termsf
    v_21441 = (*qfn1(fn))(fn, v_21441);
    env = stack[-3];
    stack[-2] = v_21441;
    goto v_21408;
v_21402:
    v_21443 = stack[-1];
    goto v_21403;
v_21404:
    v_21442 = stack[0];
    goto v_21405;
v_21406:
    v_21441 = stack[-2];
    goto v_21407;
v_21408:
    goto v_21402;
v_21403:
    goto v_21404;
v_21405:
    goto v_21406;
v_21407:
    fn = elt(env, 5); // xremf
    v_21441 = (*qfnn(fn))(fn, 3, v_21443, v_21442, v_21441);
    env = stack[-3];
    stack[0] = v_21441;
    v_21441 = stack[0];
    if (v_21441 == nil) goto v_21418;
    else goto v_21419;
v_21418:
    v_21441 = lisp_true;
    goto v_21417;
v_21419:
    goto v_21429;
v_21425:
    v_21441 = stack[0];
    v_21441 = qcar(v_21441);
    stack[0] = v_21441;
    fn = elt(env, 4); // termsf
    v_21442 = (*qfn1(fn))(fn, v_21441);
    env = stack[-3];
    goto v_21426;
v_21427:
    v_21441 = stack[-2];
    goto v_21428;
v_21429:
    goto v_21425;
v_21426:
    goto v_21427;
v_21428:
    v_21441 = (LispObject)geq2(v_21442, v_21441);
    v_21441 = v_21441 ? lisp_true : nil;
    env = stack[-3];
    goto v_21417;
    v_21441 = nil;
v_21417:
    if (v_21441 == nil) goto v_21415;
    v_21441 = stack[-1];
    goto v_21396;
v_21415:
    v_21441 = qvalue(elt(env, 2)); // !*trcompact
    if (v_21441 == nil) goto v_21436;
    v_21441 = elt(env, 3); // "*** Remainder smaller"
    fn = elt(env, 6); // prin2t
    v_21441 = (*qfn1(fn))(fn, v_21441);
    goto v_21413;
v_21436:
v_21413:
    v_21441 = stack[0];
v_21396:
    return onevalue(v_21441);
}



// Code for gvar1

static LispObject CC_gvar1(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21516, v_21517, v_21518, v_21519;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21519 = v_21392;
    v_21518 = v_21391;
// end of prologue
v_21396:
    v_21516 = v_21518;
    if (v_21516 == nil) goto v_21403;
    else goto v_21404;
v_21403:
    v_21516 = lisp_true;
    goto v_21402;
v_21404:
    v_21516 = v_21518;
    v_21516 = (is_number(v_21516) ? lisp_true : nil);
    if (v_21516 == nil) goto v_21411;
    else goto v_21410;
v_21411:
    goto v_21422;
v_21418:
    v_21517 = v_21518;
    goto v_21419;
v_21420:
    v_21516 = elt(env, 1); // i
    goto v_21421;
v_21422:
    goto v_21418;
v_21419:
    goto v_21420;
v_21421:
    if (v_21517 == v_21516) goto v_21416;
    else goto v_21417;
v_21416:
    v_21516 = qvalue(elt(env, 2)); // !*complex
    goto v_21415;
v_21417:
    v_21516 = nil;
    goto v_21415;
    v_21516 = nil;
v_21415:
v_21410:
    goto v_21402;
    v_21516 = nil;
v_21402:
    if (v_21516 == nil) goto v_21400;
    v_21516 = v_21519;
    goto v_21395;
v_21400:
    v_21516 = v_21518;
    if (!consp(v_21516)) goto v_21430;
    else goto v_21431;
v_21430:
    goto v_21441;
v_21437:
    v_21517 = v_21518;
    goto v_21438;
v_21439:
    v_21516 = v_21519;
    goto v_21440;
v_21441:
    goto v_21437;
v_21438:
    goto v_21439;
v_21440:
    v_21516 = Lmember(nil, v_21517, v_21516);
    if (v_21516 == nil) goto v_21436;
    v_21516 = v_21519;
    goto v_21395;
v_21436:
    goto v_21453;
v_21449:
    v_21516 = v_21518;
    goto v_21450;
v_21451:
    v_21517 = v_21519;
    goto v_21452;
v_21453:
    goto v_21449;
v_21450:
    goto v_21451;
v_21452:
    return cons(v_21516, v_21517);
    goto v_21398;
v_21431:
    v_21516 = v_21518;
    v_21516 = qcar(v_21516);
    if (!symbolp(v_21516)) v_21516 = nil;
    else { v_21516 = qfastgets(v_21516);
           if (v_21516 != nil) { v_21516 = elt(v_21516, 8); // dname
#ifdef RECORD_GET
             if (v_21516 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_21516 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_21516 == SPID_NOPROP) v_21516 = nil; }}
#endif
    if (v_21516 == nil) goto v_21457;
    v_21516 = v_21519;
    goto v_21395;
v_21457:
    goto v_21468;
v_21464:
    v_21516 = v_21518;
    v_21517 = qcar(v_21516);
    goto v_21465;
v_21466:
    v_21516 = elt(env, 3); // (plus times expt difference minus)
    goto v_21467;
v_21468:
    goto v_21464;
v_21465:
    goto v_21466;
v_21467:
    v_21516 = Lmemq(nil, v_21517, v_21516);
    if (v_21516 == nil) goto v_21463;
    goto v_21478;
v_21474:
    v_21516 = v_21518;
    v_21516 = qcdr(v_21516);
    goto v_21475;
v_21476:
    v_21517 = v_21519;
    goto v_21477;
v_21478:
    goto v_21474;
v_21475:
    goto v_21476;
v_21477:
    {
        fn = elt(env, 5); // gvarlis1
        return (*qfn2(fn))(fn, v_21516, v_21517);
    }
v_21463:
    goto v_21488;
v_21484:
    v_21516 = v_21518;
    v_21517 = qcar(v_21516);
    goto v_21485;
v_21486:
    v_21516 = elt(env, 4); // quotient
    goto v_21487;
v_21488:
    goto v_21484;
v_21485:
    goto v_21486;
v_21487:
    if (v_21517 == v_21516) goto v_21482;
    else goto v_21483;
v_21482:
    v_21516 = v_21518;
    v_21516 = qcdr(v_21516);
    v_21516 = qcar(v_21516);
    v_21518 = v_21516;
    goto v_21396;
v_21483:
    goto v_21501;
v_21497:
    v_21517 = v_21518;
    goto v_21498;
v_21499:
    v_21516 = v_21519;
    goto v_21500;
v_21501:
    goto v_21497;
v_21498:
    goto v_21499;
v_21500:
    v_21516 = Lmember(nil, v_21517, v_21516);
    if (v_21516 == nil) goto v_21496;
    v_21516 = v_21519;
    goto v_21395;
v_21496:
    goto v_21513;
v_21509:
    v_21516 = v_21518;
    goto v_21510;
v_21511:
    v_21517 = v_21519;
    goto v_21512;
v_21513:
    goto v_21509;
v_21510:
    goto v_21511;
v_21512:
    return cons(v_21516, v_21517);
v_21398:
    v_21516 = nil;
v_21395:
    return onevalue(v_21516);
}



// Code for lalr_print_first_information

static LispObject CC_lalr_print_first_information(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21446, v_21447;
    LispObject fn;
    argcheck(nargs, 0, "lalr_print_first_information");
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
    v_21446 = elt(env, 1); // "=== FIRST sets for each nonterminal ==="
    v_21446 = Lprinc(nil, v_21446);
    env = stack[-2];
    v_21446 = Lterpri(nil, 0);
    env = stack[-2];
    v_21446 = qvalue(elt(env, 2)); // nonterminals
    stack[-1] = v_21446;
v_21398:
    v_21446 = stack[-1];
    if (v_21446 == nil) goto v_21402;
    else goto v_21403;
v_21402:
    goto v_21397;
v_21403:
    v_21446 = stack[-1];
    v_21446 = qcar(v_21446);
    stack[0] = v_21446;
    v_21446 = stack[0];
    fn = elt(env, 6); // lalr_prin_symbol
    v_21446 = (*qfn1(fn))(fn, v_21446);
    env = stack[-2];
    v_21446 = elt(env, 3); // ":"
    v_21446 = Lprinc(nil, v_21446);
    env = stack[-2];
    v_21446 = (LispObject)320+TAG_FIXNUM; // 20
    v_21446 = Lttab(nil, v_21446);
    env = stack[-2];
    goto v_21424;
v_21420:
    v_21447 = stack[0];
    goto v_21421;
v_21422:
    v_21446 = elt(env, 4); // lalr_first
    goto v_21423;
v_21424:
    goto v_21420;
v_21421:
    goto v_21422;
v_21423:
    v_21446 = get(v_21447, v_21446);
    env = stack[-2];
    stack[0] = v_21446;
v_21418:
    v_21446 = stack[0];
    if (v_21446 == nil) goto v_21429;
    else goto v_21430;
v_21429:
    goto v_21417;
v_21430:
    v_21446 = stack[0];
    v_21446 = qcar(v_21446);
    fn = elt(env, 6); // lalr_prin_symbol
    v_21446 = (*qfn1(fn))(fn, v_21446);
    env = stack[-2];
    v_21446 = elt(env, 5); // " "
    v_21446 = Lprinc(nil, v_21446);
    env = stack[-2];
    v_21446 = stack[0];
    v_21446 = qcdr(v_21446);
    stack[0] = v_21446;
    goto v_21418;
v_21417:
    v_21446 = Lterpri(nil, 0);
    env = stack[-2];
    v_21446 = stack[-1];
    v_21446 = qcdr(v_21446);
    stack[-1] = v_21446;
    goto v_21398;
v_21397:
        return Lterpri(nil, 0);
}



// Code for give!*position

static LispObject CC_giveHposition(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21458, v_21459;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_21392;
    stack[-3] = v_21391;
// end of prologue
    v_21458 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_21458;
    v_21458 = nil;
    stack[-1] = v_21458;
v_21403:
    v_21458 = stack[-1];
    if (v_21458 == nil) goto v_21410;
    else goto v_21411;
v_21410:
    goto v_21418;
v_21414:
    stack[0] = stack[-4];
    goto v_21415;
v_21416:
    v_21458 = stack[-2];
    v_21458 = Llength(nil, v_21458);
    env = stack[-5];
    goto v_21417;
v_21418:
    goto v_21414;
v_21415:
    goto v_21416;
v_21417:
    v_21458 = (LispObject)lesseq2(stack[0], v_21458);
    v_21458 = v_21458 ? lisp_true : nil;
    env = stack[-5];
    goto v_21409;
v_21411:
    v_21458 = nil;
    goto v_21409;
    v_21458 = nil;
v_21409:
    if (v_21458 == nil) goto v_21406;
    else goto v_21407;
v_21406:
    goto v_21402;
v_21407:
    goto v_21434;
v_21430:
    goto v_21440;
v_21436:
    v_21459 = stack[-2];
    goto v_21437;
v_21438:
    v_21458 = stack[-4];
    goto v_21439;
v_21440:
    goto v_21436;
v_21437:
    goto v_21438;
v_21439:
    fn = elt(env, 3); // nth
    v_21459 = (*qfn2(fn))(fn, v_21459, v_21458);
    env = stack[-5];
    goto v_21431;
v_21432:
    v_21458 = stack[-3];
    goto v_21433;
v_21434:
    goto v_21430;
v_21431:
    goto v_21432;
v_21433:
    if (equal(v_21459, v_21458)) goto v_21428;
    else goto v_21429;
v_21428:
    v_21458 = lisp_true;
    stack[-1] = v_21458;
    goto v_21427;
v_21429:
    v_21458 = stack[-4];
    v_21458 = add1(v_21458);
    env = stack[-5];
    stack[-4] = v_21458;
    goto v_21427;
v_21427:
    goto v_21403;
v_21402:
    v_21458 = stack[-1];
    if (v_21458 == nil) goto v_21452;
    else goto v_21453;
v_21452:
    v_21458 = elt(env, 2); // "error in give position"
    fn = elt(env, 4); // rederr
    v_21458 = (*qfn1(fn))(fn, v_21458);
    goto v_21451;
v_21453:
v_21451:
    v_21458 = stack[-4];
    return onevalue(v_21458);
}



// Code for cl_pnf2

static LispObject CC_cl_pnf2(LispObject env,
                         LispObject v_21391)
{
    env = qenv(env);
    LispObject v_21707, v_21708, v_21709;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21391);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21391;
// end of prologue
    v_21707 = stack[0];
    if (!consp(v_21707)) goto v_21400;
    else goto v_21401;
v_21400:
    v_21707 = stack[0];
    goto v_21399;
v_21401:
    v_21707 = stack[0];
    v_21707 = qcar(v_21707);
    goto v_21399;
    v_21707 = nil;
v_21399:
    stack[-1] = v_21707;
    goto v_21420;
v_21416:
    v_21708 = stack[-1];
    goto v_21417;
v_21418:
    v_21707 = elt(env, 2); // ex
    goto v_21419;
v_21420:
    goto v_21416;
v_21417:
    goto v_21418;
v_21419:
    if (v_21708 == v_21707) goto v_21414;
    else goto v_21415;
v_21414:
    v_21707 = lisp_true;
    goto v_21413;
v_21415:
    goto v_21430;
v_21426:
    v_21708 = stack[-1];
    goto v_21427;
v_21428:
    v_21707 = elt(env, 3); // all
    goto v_21429;
v_21430:
    goto v_21426;
v_21427:
    goto v_21428;
v_21429:
    v_21707 = (v_21708 == v_21707 ? lisp_true : nil);
    goto v_21413;
    v_21707 = nil;
v_21413:
    if (v_21707 == nil) goto v_21411;
    v_21707 = stack[0];
    {
        fn = elt(env, 16); // cl_pnf2!-quantifier
        return (*qfn1(fn))(fn, v_21707);
    }
v_21411:
    goto v_21448;
v_21444:
    v_21708 = stack[-1];
    goto v_21445;
v_21446:
    v_21707 = elt(env, 4); // or
    goto v_21447;
v_21448:
    goto v_21444;
v_21445:
    goto v_21446;
v_21447:
    if (v_21708 == v_21707) goto v_21442;
    else goto v_21443;
v_21442:
    v_21707 = lisp_true;
    goto v_21441;
v_21443:
    goto v_21458;
v_21454:
    v_21708 = stack[-1];
    goto v_21455;
v_21456:
    v_21707 = elt(env, 5); // and
    goto v_21457;
v_21458:
    goto v_21454;
v_21455:
    goto v_21456;
v_21457:
    v_21707 = (v_21708 == v_21707 ? lisp_true : nil);
    goto v_21441;
    v_21707 = nil;
v_21441:
    if (v_21707 == nil) goto v_21439;
    v_21707 = stack[0];
    {
        fn = elt(env, 17); // cl_pnf2!-junctor
        return (*qfn1(fn))(fn, v_21707);
    }
v_21439:
    goto v_21476;
v_21472:
    v_21708 = stack[-1];
    goto v_21473;
v_21474:
    v_21707 = elt(env, 6); // true
    goto v_21475;
v_21476:
    goto v_21472;
v_21473:
    goto v_21474;
v_21475:
    if (v_21708 == v_21707) goto v_21470;
    else goto v_21471;
v_21470:
    v_21707 = lisp_true;
    goto v_21469;
v_21471:
    goto v_21486;
v_21482:
    v_21708 = stack[-1];
    goto v_21483;
v_21484:
    v_21707 = elt(env, 7); // false
    goto v_21485;
v_21486:
    goto v_21482;
v_21483:
    goto v_21484;
v_21485:
    v_21707 = (v_21708 == v_21707 ? lisp_true : nil);
    goto v_21469;
    v_21707 = nil;
v_21469:
    if (v_21707 == nil) goto v_21467;
    v_21707 = stack[0];
    return ncons(v_21707);
v_21467:
    goto v_21501;
v_21497:
    v_21708 = stack[-1];
    goto v_21498;
v_21499:
    v_21707 = elt(env, 0); // cl_pnf2
    goto v_21500;
v_21501:
    goto v_21497;
v_21498:
    goto v_21499;
v_21500:
    fn = elt(env, 18); // rl_external
    v_21707 = (*qfn2(fn))(fn, v_21708, v_21707);
    env = stack[-2];
    v_21708 = v_21707;
    if (v_21707 == nil) goto v_21495;
    goto v_21509;
v_21505:
    stack[-1] = v_21708;
    goto v_21506;
v_21507:
    v_21707 = stack[0];
    v_21707 = ncons(v_21707);
    env = stack[-2];
    goto v_21508;
v_21509:
    goto v_21505;
v_21506:
    goto v_21507;
v_21508:
    {
        LispObject v_21712 = stack[-1];
        fn = elt(env, 19); // apply
        return (*qfn2(fn))(fn, v_21712, v_21707);
    }
v_21495:
    goto v_21529;
v_21525:
    v_21708 = stack[-1];
    goto v_21526;
v_21527:
    v_21707 = elt(env, 6); // true
    goto v_21528;
v_21529:
    goto v_21525;
v_21526:
    goto v_21527;
v_21528:
    if (v_21708 == v_21707) goto v_21523;
    else goto v_21524;
v_21523:
    v_21707 = lisp_true;
    goto v_21522;
v_21524:
    goto v_21539;
v_21535:
    v_21708 = stack[-1];
    goto v_21536;
v_21537:
    v_21707 = elt(env, 7); // false
    goto v_21538;
v_21539:
    goto v_21535;
v_21536:
    goto v_21537;
v_21538:
    v_21707 = (v_21708 == v_21707 ? lisp_true : nil);
    goto v_21522;
    v_21707 = nil;
v_21522:
    if (v_21707 == nil) goto v_21520;
    v_21707 = lisp_true;
    goto v_21518;
v_21520:
    goto v_21566;
v_21562:
    v_21708 = stack[-1];
    goto v_21563;
v_21564:
    v_21707 = elt(env, 4); // or
    goto v_21565;
v_21566:
    goto v_21562;
v_21563:
    goto v_21564;
v_21565:
    if (v_21708 == v_21707) goto v_21560;
    else goto v_21561;
v_21560:
    v_21707 = lisp_true;
    goto v_21559;
v_21561:
    goto v_21576;
v_21572:
    v_21708 = stack[-1];
    goto v_21573;
v_21574:
    v_21707 = elt(env, 5); // and
    goto v_21575;
v_21576:
    goto v_21572;
v_21573:
    goto v_21574;
v_21575:
    v_21707 = (v_21708 == v_21707 ? lisp_true : nil);
    goto v_21559;
    v_21707 = nil;
v_21559:
    if (v_21707 == nil) goto v_21557;
    v_21707 = lisp_true;
    goto v_21555;
v_21557:
    goto v_21587;
v_21583:
    v_21708 = stack[-1];
    goto v_21584;
v_21585:
    v_21707 = elt(env, 8); // not
    goto v_21586;
v_21587:
    goto v_21583;
v_21584:
    goto v_21585;
v_21586:
    v_21707 = (v_21708 == v_21707 ? lisp_true : nil);
    goto v_21555;
    v_21707 = nil;
v_21555:
    if (v_21707 == nil) goto v_21553;
    v_21707 = lisp_true;
    goto v_21551;
v_21553:
    goto v_21602;
v_21598:
    v_21708 = stack[-1];
    goto v_21599;
v_21600:
    v_21707 = elt(env, 9); // impl
    goto v_21601;
v_21602:
    goto v_21598;
v_21599:
    goto v_21600;
v_21601:
    if (v_21708 == v_21707) goto v_21596;
    else goto v_21597;
v_21596:
    v_21707 = lisp_true;
    goto v_21595;
v_21597:
    goto v_21616;
v_21612:
    v_21708 = stack[-1];
    goto v_21613;
v_21614:
    v_21707 = elt(env, 10); // repl
    goto v_21615;
v_21616:
    goto v_21612;
v_21613:
    goto v_21614;
v_21615:
    if (v_21708 == v_21707) goto v_21610;
    else goto v_21611;
v_21610:
    v_21707 = lisp_true;
    goto v_21609;
v_21611:
    goto v_21626;
v_21622:
    v_21708 = stack[-1];
    goto v_21623;
v_21624:
    v_21707 = elt(env, 11); // equiv
    goto v_21625;
v_21626:
    goto v_21622;
v_21623:
    goto v_21624;
v_21625:
    v_21707 = (v_21708 == v_21707 ? lisp_true : nil);
    goto v_21609;
    v_21707 = nil;
v_21609:
    goto v_21595;
    v_21707 = nil;
v_21595:
    goto v_21551;
    v_21707 = nil;
v_21551:
    if (v_21707 == nil) goto v_21549;
    v_21707 = lisp_true;
    goto v_21547;
v_21549:
    goto v_21645;
v_21641:
    v_21708 = stack[-1];
    goto v_21642;
v_21643:
    v_21707 = elt(env, 2); // ex
    goto v_21644;
v_21645:
    goto v_21641;
v_21642:
    goto v_21643;
v_21644:
    if (v_21708 == v_21707) goto v_21639;
    else goto v_21640;
v_21639:
    v_21707 = lisp_true;
    goto v_21638;
v_21640:
    goto v_21655;
v_21651:
    v_21708 = stack[-1];
    goto v_21652;
v_21653:
    v_21707 = elt(env, 3); // all
    goto v_21654;
v_21655:
    goto v_21651;
v_21652:
    goto v_21653;
v_21654:
    v_21707 = (v_21708 == v_21707 ? lisp_true : nil);
    goto v_21638;
    v_21707 = nil;
v_21638:
    if (v_21707 == nil) goto v_21636;
    v_21707 = lisp_true;
    goto v_21634;
v_21636:
    goto v_21674;
v_21670:
    v_21708 = stack[-1];
    goto v_21671;
v_21672:
    v_21707 = elt(env, 12); // bex
    goto v_21673;
v_21674:
    goto v_21670;
v_21671:
    goto v_21672;
v_21673:
    if (v_21708 == v_21707) goto v_21668;
    else goto v_21669;
v_21668:
    v_21707 = lisp_true;
    goto v_21667;
v_21669:
    goto v_21684;
v_21680:
    v_21708 = stack[-1];
    goto v_21681;
v_21682:
    v_21707 = elt(env, 13); // ball
    goto v_21683;
v_21684:
    goto v_21680;
v_21681:
    goto v_21682;
v_21683:
    v_21707 = (v_21708 == v_21707 ? lisp_true : nil);
    goto v_21667;
    v_21707 = nil;
v_21667:
    if (v_21707 == nil) goto v_21665;
    v_21707 = lisp_true;
    goto v_21663;
v_21665:
    v_21707 = stack[-1];
    if (!symbolp(v_21707)) v_21707 = nil;
    else { v_21707 = qfastgets(v_21707);
           if (v_21707 != nil) { v_21707 = elt(v_21707, 21); // rl_external
#ifdef RECORD_GET
             if (v_21707 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_21707 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_21707 == SPID_NOPROP) v_21707 = nil; }}
#endif
    goto v_21663;
    v_21707 = nil;
v_21663:
    goto v_21634;
    v_21707 = nil;
v_21634:
    goto v_21547;
    v_21707 = nil;
v_21547:
    goto v_21518;
    v_21707 = nil;
v_21518:
    if (v_21707 == nil) goto v_21516;
    goto v_21701;
v_21695:
    v_21709 = elt(env, 14); // "cl_pnf2():"
    goto v_21696;
v_21697:
    v_21708 = stack[-1];
    goto v_21698;
v_21699:
    v_21707 = elt(env, 15); // "invalid as operator"
    goto v_21700;
v_21701:
    goto v_21695;
v_21696:
    goto v_21697;
v_21698:
    goto v_21699;
v_21700:
    v_21707 = list3(v_21709, v_21708, v_21707);
    env = stack[-2];
    fn = elt(env, 20); // rederr
    v_21707 = (*qfn1(fn))(fn, v_21707);
    goto v_21514;
v_21516:
v_21514:
    v_21707 = stack[0];
    return ncons(v_21707);
    return onevalue(v_21707);
}



// Code for getargsrd

static LispObject CC_getargsrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21417, v_21418;
    LispObject fn;
    argcheck(nargs, 0, "getargsrd");
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
    goto v_21404;
v_21400:
    v_21418 = qvalue(elt(env, 2)); // char
    goto v_21401;
v_21402:
    v_21417 = elt(env, 3); // (b v a r)
    goto v_21403;
v_21404:
    goto v_21400;
v_21401:
    goto v_21402;
v_21403:
    if (equal(v_21418, v_21417)) goto v_21398;
    else goto v_21399;
v_21398:
    fn = elt(env, 4); // bvarrd
    v_21417 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_21417;
    fn = elt(env, 5); // lex
    v_21417 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_21414;
v_21410:
    goto v_21411;
v_21412:
    v_21417 = CC_getargsrd(elt(env, 0), 0);
    goto v_21413;
v_21414:
    goto v_21410;
v_21411:
    goto v_21412;
v_21413:
    {
        LispObject v_21420 = stack[0];
        return cons(v_21420, v_21417);
    }
v_21399:
    v_21417 = nil;
    return onevalue(v_21417);
}



// Code for close_forall

static LispObject CC_close_forall(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21408, v_21409;
    LispObject fn;
    argcheck(nargs, 0, "close_forall");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
// end of prologue
    goto v_21403;
v_21399:
    v_21409 = qvalue(elt(env, 1)); // flagg
    goto v_21400;
v_21401:
    v_21408 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21402;
v_21403:
    goto v_21399;
v_21400:
    goto v_21401;
v_21402:
    if (v_21409 == v_21408) goto v_21397;
    else goto v_21398;
v_21397:
    v_21408 = elt(env, 2); // "</apply>"
    fn = elt(env, 3); // printout
    v_21408 = (*qfn1(fn))(fn, v_21408);
    goto v_21396;
v_21398:
v_21396:
    v_21408 = nil;
    return onevalue(v_21408);
}



// Code for degreef

static LispObject CC_degreef(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21453, v_21454;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21392;
    stack[-1] = v_21391;
// end of prologue
    v_21453 = stack[-1];
    if (!consp(v_21453)) goto v_21400;
    else goto v_21401;
v_21400:
    v_21453 = lisp_true;
    goto v_21399;
v_21401:
    v_21453 = stack[-1];
    v_21453 = qcar(v_21453);
    v_21453 = (consp(v_21453) ? nil : lisp_true);
    goto v_21399;
    v_21453 = nil;
v_21399:
    if (v_21453 == nil) goto v_21397;
    v_21453 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21395;
v_21397:
    goto v_21416;
v_21412:
    v_21453 = stack[-1];
    v_21453 = qcar(v_21453);
    v_21453 = qcar(v_21453);
    v_21454 = qcar(v_21453);
    goto v_21413;
v_21414:
    v_21453 = stack[0];
    goto v_21415;
v_21416:
    goto v_21412;
v_21413:
    goto v_21414;
v_21415:
    if (v_21454 == v_21453) goto v_21410;
    else goto v_21411;
v_21410:
    v_21453 = stack[-1];
    v_21453 = qcar(v_21453);
    v_21453 = qcar(v_21453);
    v_21453 = qcdr(v_21453);
    goto v_21395;
v_21411:
    goto v_21433;
v_21429:
    goto v_21439;
v_21435:
    v_21453 = stack[-1];
    v_21453 = qcar(v_21453);
    v_21454 = qcdr(v_21453);
    goto v_21436;
v_21437:
    v_21453 = stack[0];
    goto v_21438;
v_21439:
    goto v_21435;
v_21436:
    goto v_21437;
v_21438:
    stack[-2] = CC_degreef(elt(env, 0), v_21454, v_21453);
    env = stack[-3];
    goto v_21430;
v_21431:
    goto v_21449;
v_21445:
    v_21453 = stack[-1];
    v_21454 = qcdr(v_21453);
    goto v_21446;
v_21447:
    v_21453 = stack[0];
    goto v_21448;
v_21449:
    goto v_21445;
v_21446:
    goto v_21447;
v_21448:
    v_21453 = CC_degreef(elt(env, 0), v_21454, v_21453);
    env = stack[-3];
    goto v_21432;
v_21433:
    goto v_21429;
v_21430:
    goto v_21431;
v_21432:
    {
        LispObject v_21458 = stack[-2];
        fn = elt(env, 1); // max
        return (*qfn2(fn))(fn, v_21458, v_21453);
    }
    v_21453 = nil;
v_21395:
    return onevalue(v_21453);
}



// Code for matrixp

static LispObject CC_matrixp(LispObject env,
                         LispObject v_21391)
{
    env = qenv(env);
    LispObject v_21436, v_21437, v_21438;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21391);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21437 = v_21391;
// end of prologue
    v_21436 = v_21437;
    v_21436 = Lconsp(nil, v_21436);
    env = stack[0];
    if (v_21436 == nil) goto v_21398;
    else goto v_21399;
v_21398:
    v_21436 = v_21437;
    fn = elt(env, 3); // reval
    v_21436 = (*qfn1(fn))(fn, v_21436);
    env = stack[0];
    v_21437 = v_21436;
    goto v_21397;
v_21399:
v_21397:
    goto v_21417;
v_21413:
    v_21438 = v_21437;
    goto v_21414;
v_21415:
    v_21436 = elt(env, 1); // mat
    goto v_21416;
v_21417:
    goto v_21413;
v_21414:
    goto v_21415;
v_21416:
    if (!consp(v_21438)) goto v_21410;
    v_21438 = qcar(v_21438);
    if (v_21438 == v_21436) goto v_21411;
v_21410:
    goto v_21425;
v_21421:
    goto v_21422;
v_21423:
    v_21436 = elt(env, 2); // sparsemat
    goto v_21424;
v_21425:
    goto v_21421;
v_21422:
    goto v_21423;
v_21424:
    v_21436 = Leqcar(nil, v_21437, v_21436);
    v_21436 = (v_21436 == nil ? lisp_true : nil);
    goto v_21409;
v_21411:
    v_21436 = nil;
    goto v_21409;
    v_21436 = nil;
v_21409:
    if (v_21436 == nil) goto v_21407;
    v_21436 = nil;
    goto v_21394;
v_21407:
    v_21436 = lisp_true;
    goto v_21394;
    v_21436 = nil;
v_21394:
    return onevalue(v_21436);
}



// Code for sc_mkmatrix

static LispObject CC_sc_mkmatrix(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21474, v_21475, v_21476;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_21392;
    stack[-6] = v_21391;
// end of prologue
    v_21474 = stack[-6];
    v_21474 = sub1(v_21474);
    env = stack[-8];
    v_21474 = Lmkvect(nil, v_21474);
    env = stack[-8];
    stack[-7] = v_21474;
    v_21474 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_21474;
v_21405:
    goto v_21417;
v_21413:
    v_21474 = stack[-6];
    v_21475 = sub1(v_21474);
    env = stack[-8];
    goto v_21414;
v_21415:
    v_21474 = stack[-3];
    goto v_21416;
v_21417:
    goto v_21413;
v_21414:
    goto v_21415;
v_21416:
    v_21474 = difference2(v_21475, v_21474);
    env = stack[-8];
    v_21474 = Lminusp(nil, v_21474);
    env = stack[-8];
    if (v_21474 == nil) goto v_21410;
    goto v_21404;
v_21410:
    v_21474 = stack[-5];
    v_21474 = sub1(v_21474);
    env = stack[-8];
    v_21474 = Lmkvect(nil, v_21474);
    env = stack[-8];
    stack[-4] = v_21474;
    v_21474 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_21474;
v_21428:
    goto v_21440;
v_21436:
    v_21474 = stack[-5];
    v_21475 = sub1(v_21474);
    env = stack[-8];
    goto v_21437;
v_21438:
    v_21474 = stack[-2];
    goto v_21439;
v_21440:
    goto v_21436;
v_21437:
    goto v_21438;
v_21439:
    v_21474 = difference2(v_21475, v_21474);
    env = stack[-8];
    v_21474 = Lminusp(nil, v_21474);
    env = stack[-8];
    if (v_21474 == nil) goto v_21433;
    goto v_21427;
v_21433:
    goto v_21452;
v_21446:
    stack[-1] = stack[-4];
    goto v_21447;
v_21448:
    stack[0] = stack[-2];
    goto v_21449;
v_21450:
    v_21474 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 2); // sc_simp
    v_21474 = (*qfn1(fn))(fn, v_21474);
    env = stack[-8];
    goto v_21451;
v_21452:
    goto v_21446;
v_21447:
    goto v_21448;
v_21449:
    goto v_21450;
v_21451:
    fn = elt(env, 3); // sc_iputv
    v_21474 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_21474);
    env = stack[-8];
    v_21474 = stack[-2];
    v_21474 = add1(v_21474);
    env = stack[-8];
    stack[-2] = v_21474;
    goto v_21428;
v_21427:
    goto v_21466;
v_21460:
    v_21476 = stack[-7];
    goto v_21461;
v_21462:
    v_21475 = stack[-3];
    goto v_21463;
v_21464:
    v_21474 = stack[-4];
    goto v_21465;
v_21466:
    goto v_21460;
v_21461:
    goto v_21462;
v_21463:
    goto v_21464;
v_21465:
    fn = elt(env, 3); // sc_iputv
    v_21474 = (*qfnn(fn))(fn, 3, v_21476, v_21475, v_21474);
    env = stack[-8];
    v_21474 = stack[-3];
    v_21474 = add1(v_21474);
    env = stack[-8];
    stack[-3] = v_21474;
    goto v_21405;
v_21404:
    v_21474 = stack[-7];
    return onevalue(v_21474);
}



// Code for string2bytelist

static LispObject CC_string2bytelist(LispObject env,
                         LispObject v_21391)
{
    env = qenv(env);
    LispObject v_21447, v_21448;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21391);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_21447 = v_21391;
// end of prologue
    stack[-1] = nil;
    fn = elt(env, 2); // string2list
    v_21447 = (*qfn1(fn))(fn, v_21447);
    env = stack[-2];
    stack[0] = v_21447;
v_21402:
    v_21447 = stack[0];
    if (v_21447 == nil) goto v_21405;
    else goto v_21406;
v_21405:
    goto v_21401;
v_21406:
    v_21447 = stack[0];
    v_21447 = qcar(v_21447);
    v_21447 = Lminusp(nil, v_21447);
    env = stack[-2];
    if (v_21447 == nil) goto v_21412;
    goto v_21421;
v_21417:
    goto v_21427;
v_21423:
    v_21448 = (LispObject)4096+TAG_FIXNUM; // 256
    goto v_21424;
v_21425:
    v_21447 = stack[0];
    v_21447 = qcar(v_21447);
    goto v_21426;
v_21427:
    goto v_21423;
v_21424:
    goto v_21425;
v_21426:
    v_21448 = plus2(v_21448, v_21447);
    env = stack[-2];
    goto v_21418;
v_21419:
    v_21447 = stack[-1];
    goto v_21420;
v_21421:
    goto v_21417;
v_21418:
    goto v_21419;
v_21420:
    v_21447 = cons(v_21448, v_21447);
    env = stack[-2];
    stack[-1] = v_21447;
    goto v_21410;
v_21412:
    goto v_21439;
v_21435:
    v_21447 = stack[0];
    v_21448 = qcar(v_21447);
    goto v_21436;
v_21437:
    v_21447 = stack[-1];
    goto v_21438;
v_21439:
    goto v_21435;
v_21436:
    goto v_21437;
v_21438:
    v_21447 = cons(v_21448, v_21447);
    env = stack[-2];
    stack[-1] = v_21447;
    goto v_21410;
v_21410:
    v_21447 = stack[0];
    v_21447 = qcdr(v_21447);
    stack[0] = v_21447;
    goto v_21402;
v_21401:
    v_21447 = stack[-1];
        return Lnreverse(nil, v_21447);
    return onevalue(v_21447);
}



// Code for gftimes

static LispObject CC_gftimes(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21418, v_21419, v_21420;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21419 = v_21392;
    v_21420 = v_21391;
// end of prologue
    v_21418 = v_21420;
    v_21418 = qcar(v_21418);
    if (!consp(v_21418)) goto v_21396;
    else goto v_21397;
v_21396:
    goto v_21405;
v_21401:
    v_21418 = v_21420;
    goto v_21402;
v_21403:
    goto v_21404;
v_21405:
    goto v_21401;
v_21402:
    goto v_21403;
v_21404:
    {
        fn = elt(env, 1); // gfftimes
        return (*qfn2(fn))(fn, v_21418, v_21419);
    }
v_21397:
    goto v_21415;
v_21411:
    v_21418 = v_21420;
    goto v_21412;
v_21413:
    goto v_21414;
v_21415:
    goto v_21411;
v_21412:
    goto v_21413;
v_21414:
    {
        fn = elt(env, 2); // gbftimes
        return (*qfn2(fn))(fn, v_21418, v_21419);
    }
    v_21418 = nil;
    return onevalue(v_21418);
}



// Code for sublap

static LispObject CC_sublap(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21482, v_21483;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21392;
    stack[-1] = v_21391;
// end of prologue
    v_21482 = stack[-1];
    if (v_21482 == nil) goto v_21404;
    else goto v_21405;
v_21404:
    v_21482 = lisp_true;
    goto v_21403;
v_21405:
    v_21482 = stack[0];
    v_21482 = (v_21482 == nil ? lisp_true : nil);
    goto v_21403;
    v_21482 = nil;
v_21403:
    if (v_21482 == nil) goto v_21401;
    v_21482 = stack[0];
    goto v_21399;
v_21401:
    v_21482 = stack[0];
    if (!consp(v_21482)) goto v_21413;
    else goto v_21414;
v_21413:
    v_21482 = stack[0];
    if (is_number(v_21482)) goto v_21418;
    else goto v_21419;
v_21418:
    v_21482 = stack[0];
    goto v_21417;
v_21419:
    goto v_21428;
v_21424:
    v_21483 = stack[0];
    goto v_21425;
v_21426:
    v_21482 = stack[-1];
    goto v_21427;
v_21428:
    goto v_21424;
v_21425:
    goto v_21426;
v_21427:
    v_21482 = Latsoc(nil, v_21483, v_21482);
    v_21483 = v_21482;
    if (v_21482 == nil) goto v_21423;
    v_21482 = v_21483;
    v_21482 = qcdr(v_21482);
    goto v_21417;
v_21423:
    v_21482 = stack[0];
    goto v_21417;
    v_21482 = nil;
v_21417:
    goto v_21399;
v_21414:
    goto v_21444;
v_21440:
    v_21482 = stack[0];
    v_21483 = qcar(v_21482);
    goto v_21441;
v_21442:
    v_21482 = elt(env, 2); // app
    goto v_21443;
v_21444:
    goto v_21440;
v_21441:
    goto v_21442;
v_21443:
    v_21482 = Lflagp(nil, v_21483, v_21482);
    env = stack[-3];
    if (v_21482 == nil) goto v_21438;
    goto v_21453;
v_21449:
    v_21483 = stack[-1];
    goto v_21450;
v_21451:
    v_21482 = stack[0];
    goto v_21452;
v_21453:
    goto v_21449;
v_21450:
    goto v_21451;
v_21452:
    {
        fn = elt(env, 3); // sublap1
        return (*qfn2(fn))(fn, v_21483, v_21482);
    }
v_21438:
    goto v_21463;
v_21459:
    goto v_21469;
v_21465:
    v_21483 = stack[-1];
    goto v_21466;
v_21467:
    v_21482 = stack[0];
    v_21482 = qcar(v_21482);
    goto v_21468;
v_21469:
    goto v_21465;
v_21466:
    goto v_21467;
v_21468:
    stack[-2] = CC_sublap(elt(env, 0), v_21483, v_21482);
    env = stack[-3];
    goto v_21460;
v_21461:
    goto v_21478;
v_21474:
    v_21483 = stack[-1];
    goto v_21475;
v_21476:
    v_21482 = stack[0];
    v_21482 = qcdr(v_21482);
    goto v_21477;
v_21478:
    goto v_21474;
v_21475:
    goto v_21476;
v_21477:
    v_21482 = CC_sublap(elt(env, 0), v_21483, v_21482);
    goto v_21462;
v_21463:
    goto v_21459;
v_21460:
    goto v_21461;
v_21462:
    {
        LispObject v_21487 = stack[-2];
        return cons(v_21487, v_21482);
    }
    v_21482 = nil;
v_21399:
    return onevalue(v_21482);
}



// Code for !*!*a2i

static LispObject CC_HHa2i(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21417, v_21418;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21417 = v_21392;
    stack[0] = v_21391;
// end of prologue
    goto v_21403;
v_21399:
    v_21418 = stack[0];
    goto v_21400;
v_21401:
    goto v_21402;
v_21403:
    goto v_21399;
v_21400:
    goto v_21401;
v_21402:
    fn = elt(env, 2); // intexprnp
    v_21417 = (*qfn2(fn))(fn, v_21418, v_21417);
    env = stack[-1];
    if (v_21417 == nil) goto v_21397;
    v_21417 = stack[0];
    goto v_21395;
v_21397:
    goto v_21414;
v_21410:
    v_21418 = elt(env, 1); // ieval
    goto v_21411;
v_21412:
    v_21417 = stack[0];
    goto v_21413;
v_21414:
    goto v_21410;
v_21411:
    goto v_21412;
v_21413:
    return list2(v_21418, v_21417);
    v_21417 = nil;
v_21395:
    return onevalue(v_21417);
}



// Code for drnconv

static LispObject CC_drnconv(LispObject env,
                         LispObject v_21391)
{
    env = qenv(env);
    LispObject v_21450, v_21451, v_21452;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21391);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21451 = v_21391;
// end of prologue
    v_21450 = v_21451;
    if (v_21450 == nil) goto v_21399;
    else goto v_21400;
v_21399:
    v_21450 = lisp_true;
    goto v_21398;
v_21400:
    v_21450 = v_21451;
    v_21450 = (is_number(v_21450) ? lisp_true : nil);
    if (v_21450 == nil) goto v_21407;
    else goto v_21406;
v_21407:
    goto v_21415;
v_21411:
    v_21452 = v_21451;
    goto v_21412;
v_21413:
    v_21450 = qvalue(elt(env, 1)); // dmd!*
    goto v_21414;
v_21415:
    goto v_21411;
v_21412:
    goto v_21413;
v_21414:
    v_21450 = Leqcar(nil, v_21452, v_21450);
    env = stack[0];
v_21406:
    goto v_21398;
    v_21450 = nil;
v_21398:
    if (v_21450 == nil) goto v_21396;
    v_21450 = v_21451;
    goto v_21394;
v_21396:
    goto v_21426;
v_21422:
    v_21450 = v_21451;
    v_21452 = qcar(v_21450);
    goto v_21423;
v_21424:
    v_21450 = qvalue(elt(env, 1)); // dmd!*
    goto v_21425;
v_21426:
    goto v_21422;
v_21423:
    goto v_21424;
v_21425:
    v_21450 = get(v_21452, v_21450);
    v_21452 = v_21450;
    v_21450 = v_21452;
    if (v_21450 == nil) goto v_21434;
    v_21450 = v_21452;
    if (!consp(v_21450)) goto v_21437;
    else goto v_21434;
v_21437:
    goto v_21444;
v_21440:
    v_21450 = v_21452;
    goto v_21441;
v_21442:
    goto v_21443;
v_21444:
    goto v_21440;
v_21441:
    goto v_21442;
v_21443:
        return Lapply1(nil, v_21450, v_21451);
v_21434:
    v_21450 = v_21451;
    goto v_21432;
    v_21450 = nil;
v_21432:
    goto v_21394;
    v_21450 = nil;
v_21394:
    return onevalue(v_21450);
}



// Code for rl_fvarl

static LispObject CC_rl_fvarl(LispObject env,
                         LispObject v_21391)
{
    env = qenv(env);
    LispObject v_21402;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21391);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21402 = v_21391;
// end of prologue
    goto v_21398;
v_21394:
    stack[0] = qvalue(elt(env, 1)); // rl_fvarl!*
    goto v_21395;
v_21396:
    v_21402 = ncons(v_21402);
    env = stack[-1];
    goto v_21397;
v_21398:
    goto v_21394;
v_21395:
    goto v_21396;
v_21397:
    {
        LispObject v_21404 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_21404, v_21402);
    }
}



// Code for taydegree!<

static LispObject CC_taydegreeR(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21451, v_21452;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_21392;
    stack[-2] = v_21391;
// end of prologue
v_21398:
    v_21451 = stack[-2];
    v_21451 = qcar(v_21451);
    stack[-3] = v_21451;
    v_21451 = stack[-1];
    v_21451 = qcar(v_21451);
    stack[0] = v_21451;
v_21399:
    goto v_21414;
v_21410:
    v_21451 = stack[-3];
    v_21452 = qcar(v_21451);
    goto v_21411;
v_21412:
    v_21451 = stack[0];
    v_21451 = qcar(v_21451);
    goto v_21413;
v_21414:
    goto v_21410;
v_21411:
    goto v_21412;
v_21413:
    fn = elt(env, 2); // tayexp!-greaterp
    v_21451 = (*qfn2(fn))(fn, v_21452, v_21451);
    env = stack[-4];
    if (v_21451 == nil) goto v_21408;
    v_21451 = nil;
    goto v_21397;
v_21408:
    goto v_21427;
v_21423:
    v_21451 = stack[-3];
    v_21452 = qcar(v_21451);
    goto v_21424;
v_21425:
    v_21451 = stack[0];
    v_21451 = qcar(v_21451);
    goto v_21426;
v_21427:
    goto v_21423;
v_21424:
    goto v_21425;
v_21426:
    fn = elt(env, 3); // tayexp!-lessp
    v_21451 = (*qfn2(fn))(fn, v_21452, v_21451);
    env = stack[-4];
    if (v_21451 == nil) goto v_21421;
    v_21451 = lisp_true;
    goto v_21397;
v_21421:
    v_21451 = stack[-3];
    v_21451 = qcdr(v_21451);
    stack[-3] = v_21451;
    v_21451 = stack[0];
    v_21451 = qcdr(v_21451);
    stack[0] = v_21451;
    v_21451 = stack[-3];
    if (v_21451 == nil) goto v_21440;
    goto v_21399;
v_21440:
    v_21451 = stack[-2];
    v_21451 = qcdr(v_21451);
    stack[-2] = v_21451;
    v_21451 = stack[-1];
    v_21451 = qcdr(v_21451);
    stack[-1] = v_21451;
    v_21451 = stack[-2];
    if (v_21451 == nil) goto v_21449;
    goto v_21398;
v_21449:
    v_21451 = nil;
v_21397:
    return onevalue(v_21451);
}



// Code for internal!-factorf

static LispObject CC_internalKfactorf(LispObject env,
                         LispObject v_21391)
{
    env = qenv(env);
    LispObject v_21678, v_21679;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21391);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_21391;
// end of prologue
    v_21678 = qvalue(elt(env, 1)); // current!-modulus
// Binding current!-modulus
// FLUIDBIND: reloadenv=10 litvec-offset=1 saveloc=9
{   bind_fluid_stack bind_fluid_var(-10, 1, -9);
    qvalue(elt(env, 1)) = v_21678; // current!-modulus
// Binding m!-image!-variable
// FLUIDBIND: reloadenv=10 litvec-offset=2 saveloc=7
{   bind_fluid_stack bind_fluid_var(-10, 2, -7);
    qvalue(elt(env, 2)) = nil; // m!-image!-variable
    stack[-6] = nil;
    v_21678 = stack[-8];
    if (!consp(v_21678)) goto v_21411;
    else goto v_21412;
v_21411:
    v_21678 = lisp_true;
    goto v_21410;
v_21412:
    v_21678 = stack[-8];
    v_21678 = qcar(v_21678);
    v_21678 = (consp(v_21678) ? nil : lisp_true);
    goto v_21410;
    v_21678 = nil;
v_21410:
    if (v_21678 == nil) goto v_21408;
    v_21678 = stack[-8];
    v_21678 = ncons(v_21678);
    goto v_21403;
v_21408:
    goto v_21427;
v_21423:
    v_21679 = stack[-8];
    goto v_21424;
v_21425:
    v_21678 = nil;
    goto v_21426;
v_21427:
    goto v_21423;
v_21424:
    goto v_21425;
v_21426:
    fn = elt(env, 5); // kernord
    v_21678 = (*qfn2(fn))(fn, v_21679, v_21678);
    env = stack[-10];
    v_21679 = v_21678;
    v_21678 = qvalue(elt(env, 4)); // !*kernreverse
    if (v_21678 == nil) goto v_21433;
    v_21678 = v_21679;
    v_21678 = Lreverse(nil, v_21678);
    env = stack[-10];
    v_21679 = v_21678;
    goto v_21431;
v_21433:
v_21431:
    v_21678 = v_21679;
    fn = elt(env, 6); // setkorder
    v_21678 = (*qfn1(fn))(fn, v_21678);
    env = stack[-10];
    stack[-3] = v_21678;
    v_21678 = stack[-8];
    fn = elt(env, 7); // reorder
    v_21678 = (*qfn1(fn))(fn, v_21678);
    env = stack[-10];
    stack[-8] = v_21678;
    v_21678 = stack[-8];
    fn = elt(env, 8); // minusf
    v_21678 = (*qfn1(fn))(fn, v_21678);
    env = stack[-10];
    if (v_21678 == nil) goto v_21444;
    v_21678 = stack[-6];
    v_21678 = (v_21678 == nil ? lisp_true : nil);
    stack[-6] = v_21678;
    v_21678 = stack[-8];
    fn = elt(env, 9); // negf
    v_21678 = (*qfn1(fn))(fn, v_21678);
    env = stack[-10];
    stack[-8] = v_21678;
    goto v_21442;
v_21444:
v_21442:
    v_21678 = stack[-8];
    fn = elt(env, 10); // comfac
    v_21678 = (*qfn1(fn))(fn, v_21678);
    env = stack[-10];
    stack[-2] = v_21678;
    goto v_21458;
v_21454:
    stack[0] = stack[-8];
    goto v_21455;
v_21456:
    v_21678 = stack[-2];
    fn = elt(env, 11); // comfac!-to!-poly
    v_21678 = (*qfn1(fn))(fn, v_21678);
    env = stack[-10];
    goto v_21457;
v_21458:
    goto v_21454;
v_21455:
    goto v_21456;
v_21457:
    fn = elt(env, 12); // quotf1
    v_21678 = (*qfn2(fn))(fn, stack[0], v_21678);
    env = stack[-10];
    stack[-8] = v_21678;
    v_21678 = stack[-8];
    if (!consp(v_21678)) goto v_21468;
    else goto v_21469;
v_21468:
    v_21678 = lisp_true;
    goto v_21467;
v_21469:
    v_21678 = stack[-8];
    v_21678 = qcar(v_21678);
    v_21678 = (consp(v_21678) ? nil : lisp_true);
    goto v_21467;
    v_21678 = nil;
v_21467:
    if (v_21678 == nil) goto v_21465;
    v_21678 = stack[-8];
    stack[-5] = v_21678;
    v_21678 = nil;
    stack[-8] = v_21678;
    goto v_21463;
v_21465:
    v_21678 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_21678;
    v_21678 = stack[-8];
    v_21678 = qcar(v_21678);
    v_21678 = qcar(v_21678);
    v_21678 = qcar(v_21678);
    qvalue(elt(env, 2)) = v_21678; // m!-image!-variable
    goto v_21491;
v_21487:
    v_21678 = stack[-8];
    fn = elt(env, 13); // factorize!-primitive!-polynomial
    v_21679 = (*qfn1(fn))(fn, v_21678);
    env = stack[-10];
    goto v_21488;
v_21489:
    v_21678 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21490;
v_21491:
    goto v_21487;
v_21488:
    goto v_21489;
v_21490:
    fn = elt(env, 14); // distribute!.multiplicity
    v_21678 = (*qfn2(fn))(fn, v_21679, v_21678);
    env = stack[-10];
    stack[-8] = v_21678;
    goto v_21463;
v_21463:
    v_21678 = stack[-2];
    v_21678 = qcar(v_21678);
    stack[-1] = v_21678;
    v_21678 = stack[-2];
    v_21678 = qcdr(v_21678);
    fn = elt(env, 15); // fctrf1
    v_21678 = (*qfn1(fn))(fn, v_21678);
    env = stack[-10];
    stack[-2] = v_21678;
    v_21678 = stack[-1];
    if (v_21678 == nil) goto v_21503;
    goto v_21512;
v_21506:
    v_21678 = stack[-2];
    stack[0] = qcar(v_21678);
    goto v_21507;
v_21508:
    goto v_21520;
v_21516:
    goto v_21527;
v_21523:
    goto v_21533;
v_21529:
    v_21678 = stack[-1];
    v_21679 = qcar(v_21678);
    goto v_21530;
v_21531:
    v_21678 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21532;
v_21533:
    goto v_21529;
v_21530:
    goto v_21531;
v_21532:
    fn = elt(env, 16); // to
    v_21679 = (*qfn2(fn))(fn, v_21679, v_21678);
    env = stack[-10];
    goto v_21524;
v_21525:
    v_21678 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21526;
v_21527:
    goto v_21523;
v_21524:
    goto v_21525;
v_21526:
    v_21678 = cons(v_21679, v_21678);
    env = stack[-10];
    v_21679 = ncons(v_21678);
    env = stack[-10];
    goto v_21517;
v_21518:
    v_21678 = stack[-1];
    v_21678 = qcdr(v_21678);
    goto v_21519;
v_21520:
    goto v_21516;
v_21517:
    goto v_21518;
v_21519:
    v_21679 = cons(v_21679, v_21678);
    env = stack[-10];
    goto v_21509;
v_21510:
    v_21678 = stack[-2];
    v_21678 = qcdr(v_21678);
    goto v_21511;
v_21512:
    goto v_21506;
v_21507:
    goto v_21508;
v_21509:
    goto v_21510;
v_21511:
    v_21678 = list2star(stack[0], v_21679, v_21678);
    env = stack[-10];
    stack[-2] = v_21678;
    goto v_21501;
v_21503:
v_21501:
    v_21678 = stack[-6];
    if (v_21678 == nil) goto v_21545;
    v_21678 = stack[-5];
    fn = elt(env, 9); // negf
    v_21678 = (*qfn1(fn))(fn, v_21678);
    env = stack[-10];
    stack[-5] = v_21678;
    goto v_21543;
v_21545:
v_21543:
    goto v_21554;
v_21550:
    stack[0] = stack[-2];
    goto v_21551;
v_21552:
    goto v_21561;
v_21557:
    v_21679 = stack[-5];
    goto v_21558;
v_21559:
    v_21678 = stack[-8];
    goto v_21560;
v_21561:
    goto v_21557;
v_21558:
    goto v_21559;
v_21560:
    v_21678 = cons(v_21679, v_21678);
    env = stack[-10];
    goto v_21553;
v_21554:
    goto v_21550;
v_21551:
    goto v_21552;
v_21553:
    fn = elt(env, 17); // fac!-merge
    v_21678 = (*qfn2(fn))(fn, stack[0], v_21678);
    env = stack[-10];
    stack[-8] = v_21678;
    v_21678 = stack[-3];
    fn = elt(env, 6); // setkorder
    v_21678 = (*qfn1(fn))(fn, v_21678);
    env = stack[-10];
    v_21678 = stack[-8];
    v_21678 = qcdr(v_21678);
    stack[-4] = v_21678;
    v_21678 = stack[-4];
    if (v_21678 == nil) goto v_21576;
    else goto v_21577;
v_21576:
    v_21678 = nil;
    goto v_21570;
v_21577:
    v_21678 = stack[-4];
    v_21678 = qcar(v_21678);
    stack[0] = v_21678;
    goto v_21589;
v_21585:
    v_21678 = stack[0];
    v_21678 = qcar(v_21678);
    fn = elt(env, 7); // reorder
    v_21678 = (*qfn1(fn))(fn, v_21678);
    env = stack[-10];
    stack[-5] = v_21678;
    fn = elt(env, 8); // minusf
    v_21678 = (*qfn1(fn))(fn, v_21678);
    env = stack[-10];
    if (v_21678 == nil) goto v_21593;
    v_21678 = stack[-6];
    v_21678 = (v_21678 == nil ? lisp_true : nil);
    stack[-6] = v_21678;
    v_21678 = stack[-5];
    fn = elt(env, 9); // negf
    v_21678 = (*qfn1(fn))(fn, v_21678);
    env = stack[-10];
    v_21679 = v_21678;
    goto v_21591;
v_21593:
    v_21678 = stack[-5];
    v_21679 = v_21678;
    goto v_21591;
    v_21679 = nil;
v_21591:
    goto v_21586;
v_21587:
    v_21678 = stack[0];
    v_21678 = qcdr(v_21678);
    goto v_21588;
v_21589:
    goto v_21585;
v_21586:
    goto v_21587;
v_21588:
    v_21678 = cons(v_21679, v_21678);
    env = stack[-10];
    v_21678 = ncons(v_21678);
    env = stack[-10];
    stack[-2] = v_21678;
    stack[-3] = v_21678;
v_21571:
    v_21678 = stack[-4];
    v_21678 = qcdr(v_21678);
    stack[-4] = v_21678;
    v_21678 = stack[-4];
    if (v_21678 == nil) goto v_21611;
    else goto v_21612;
v_21611:
    v_21678 = stack[-3];
    goto v_21570;
v_21612:
    goto v_21620;
v_21616:
    stack[-1] = stack[-2];
    goto v_21617;
v_21618:
    v_21678 = stack[-4];
    v_21678 = qcar(v_21678);
    stack[0] = v_21678;
    goto v_21631;
v_21627:
    v_21678 = stack[0];
    v_21678 = qcar(v_21678);
    fn = elt(env, 7); // reorder
    v_21678 = (*qfn1(fn))(fn, v_21678);
    env = stack[-10];
    stack[-5] = v_21678;
    fn = elt(env, 8); // minusf
    v_21678 = (*qfn1(fn))(fn, v_21678);
    env = stack[-10];
    if (v_21678 == nil) goto v_21635;
    v_21678 = stack[-6];
    v_21678 = (v_21678 == nil ? lisp_true : nil);
    stack[-6] = v_21678;
    v_21678 = stack[-5];
    fn = elt(env, 9); // negf
    v_21678 = (*qfn1(fn))(fn, v_21678);
    env = stack[-10];
    v_21679 = v_21678;
    goto v_21633;
v_21635:
    v_21678 = stack[-5];
    v_21679 = v_21678;
    goto v_21633;
    v_21679 = nil;
v_21633:
    goto v_21628;
v_21629:
    v_21678 = stack[0];
    v_21678 = qcdr(v_21678);
    goto v_21630;
v_21631:
    goto v_21627;
v_21628:
    goto v_21629;
v_21630:
    v_21678 = cons(v_21679, v_21678);
    env = stack[-10];
    v_21678 = ncons(v_21678);
    env = stack[-10];
    goto v_21619;
v_21620:
    goto v_21616;
v_21617:
    goto v_21618;
v_21619:
    v_21678 = Lrplacd(nil, stack[-1], v_21678);
    env = stack[-10];
    v_21678 = stack[-2];
    v_21678 = qcdr(v_21678);
    stack[-2] = v_21678;
    goto v_21571;
v_21570:
    stack[-2] = v_21678;
    goto v_21656;
v_21652:
    goto v_21665;
v_21661:
    stack[0] = stack[-6];
    goto v_21662;
v_21663:
    v_21678 = stack[-8];
    v_21678 = qcar(v_21678);
    fn = elt(env, 8); // minusf
    v_21678 = (*qfn1(fn))(fn, v_21678);
    env = stack[-10];
    goto v_21664;
v_21665:
    goto v_21661;
v_21662:
    goto v_21663;
v_21664:
    if (equal(stack[0], v_21678)) goto v_21660;
    v_21678 = stack[-8];
    v_21678 = qcar(v_21678);
    fn = elt(env, 9); // negf
    v_21678 = (*qfn1(fn))(fn, v_21678);
    env = stack[-10];
    v_21679 = v_21678;
    goto v_21658;
v_21660:
    v_21678 = stack[-8];
    v_21678 = qcar(v_21678);
    v_21679 = v_21678;
    goto v_21658;
    v_21679 = nil;
v_21658:
    goto v_21653;
v_21654:
    v_21678 = stack[-2];
    goto v_21655;
v_21656:
    goto v_21652;
v_21653:
    goto v_21654;
v_21655:
    v_21678 = cons(v_21679, v_21678);
v_21403:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_21678);
}



// Code for symbolsom

static LispObject CC_symbolsom(LispObject env,
                         LispObject v_21391)
{
    env = qenv(env);
    LispObject v_21536, v_21537, v_21538;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21391);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_21391;
// end of prologue
    stack[-1] = nil;
    goto v_21405;
v_21401:
    v_21536 = stack[-4];
    v_21537 = qcar(v_21536);
    goto v_21402;
v_21403:
    v_21536 = qvalue(elt(env, 2)); // valid_om!*
    goto v_21404;
v_21405:
    goto v_21401;
v_21402:
    goto v_21403;
v_21404:
    v_21536 = Lassoc(nil, v_21537, v_21536);
    stack[-5] = v_21536;
    v_21536 = stack[-5];
    if (v_21536 == nil) goto v_21413;
    v_21536 = stack[-5];
    v_21536 = qcdr(v_21536);
    v_21536 = qcar(v_21536);
    stack[-5] = v_21536;
    goto v_21411;
v_21413:
v_21411:
    v_21536 = stack[-4];
    v_21536 = qcar(v_21536);
    stack[0] = v_21536;
    v_21536 = stack[-4];
    v_21536 = qcdr(v_21536);
    v_21536 = qcdr(v_21536);
    v_21536 = qcar(v_21536);
    stack[-3] = v_21536;
    v_21536 = stack[-4];
    v_21536 = Lreverse(nil, v_21536);
    env = stack[-6];
    v_21536 = qcar(v_21536);
    stack[-2] = v_21536;
    goto v_21435;
v_21431:
    v_21537 = stack[0];
    goto v_21432;
v_21433:
    v_21536 = elt(env, 3); // diff
    goto v_21434;
v_21435:
    goto v_21431;
v_21432:
    goto v_21433;
v_21434:
    if (v_21537 == v_21536) goto v_21430;
    v_21536 = stack[-4];
    v_21536 = qcdr(v_21536);
    v_21536 = qcdr(v_21536);
    v_21536 = qcdr(v_21536);
    v_21536 = qcar(v_21536);
    stack[-1] = v_21536;
    goto v_21428;
v_21430:
v_21428:
    v_21536 = stack[-1];
    if (v_21536 == nil) goto v_21446;
    goto v_21456;
v_21452:
    v_21536 = stack[-1];
    v_21537 = qcar(v_21536);
    goto v_21453;
v_21454:
    v_21536 = elt(env, 4); // condition
    goto v_21455;
v_21456:
    goto v_21452;
v_21453:
    goto v_21454;
v_21455:
    if (v_21537 == v_21536) goto v_21450;
    else goto v_21451;
v_21450:
    goto v_21465;
v_21461:
    v_21537 = elt(env, 5); // "<condition> tag not supported in MathML"
    goto v_21462;
v_21463:
    v_21536 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21464;
v_21465:
    goto v_21461;
v_21462:
    goto v_21463;
v_21464:
    fn = elt(env, 14); // errorml
    v_21536 = (*qfn2(fn))(fn, v_21537, v_21536);
    env = stack[-6];
    goto v_21449;
v_21451:
v_21449:
    goto v_21444;
v_21446:
v_21444:
    v_21536 = elt(env, 6); // "<OMA>"
    fn = elt(env, 15); // printout
    v_21536 = (*qfn1(fn))(fn, v_21536);
    env = stack[-6];
    v_21536 = lisp_true;
    fn = elt(env, 16); // indent!*
    v_21536 = (*qfn1(fn))(fn, v_21536);
    env = stack[-6];
    v_21536 = stack[-1];
    if (v_21536 == nil) goto v_21479;
    goto v_21485;
v_21481:
    v_21537 = stack[0];
    goto v_21482;
v_21483:
    v_21536 = elt(env, 7); // int
    goto v_21484;
v_21485:
    goto v_21481;
v_21482:
    goto v_21483;
v_21484:
    v_21536 = (v_21537 == v_21536 ? lisp_true : nil);
    goto v_21477;
v_21479:
    v_21536 = nil;
    goto v_21477;
    v_21536 = nil;
v_21477:
    if (v_21536 == nil) goto v_21475;
    v_21536 = elt(env, 8); // defint
    stack[0] = v_21536;
    goto v_21473;
v_21475:
v_21473:
    v_21536 = elt(env, 9); // "<OMS cd="""
    fn = elt(env, 15); // printout
    v_21536 = (*qfn1(fn))(fn, v_21536);
    env = stack[-6];
    v_21536 = stack[-5];
    v_21536 = Lprinc(nil, v_21536);
    env = stack[-6];
    v_21536 = elt(env, 10); // """ name="""
    v_21536 = Lprinc(nil, v_21536);
    env = stack[-6];
    v_21536 = stack[0];
    v_21536 = Lprinc(nil, v_21536);
    env = stack[-6];
    v_21536 = elt(env, 11); // """/>"
    v_21536 = Lprinc(nil, v_21536);
    env = stack[-6];
    v_21536 = stack[-1];
    if (v_21536 == nil) goto v_21506;
    v_21536 = stack[-1];
    fn = elt(env, 17); // objectom
    v_21536 = (*qfn1(fn))(fn, v_21536);
    env = stack[-6];
    goto v_21504;
v_21506:
v_21504:
    goto v_21518;
v_21512:
    stack[-1] = elt(env, 12); // lambda
    goto v_21513;
v_21514:
    stack[0] = nil;
    goto v_21515;
v_21516:
    goto v_21528;
v_21522:
    v_21538 = stack[-3];
    goto v_21523;
v_21524:
    v_21537 = stack[-2];
    goto v_21525;
v_21526:
    v_21536 = nil;
    goto v_21527;
v_21528:
    goto v_21522;
v_21523:
    goto v_21524;
v_21525:
    goto v_21526;
v_21527:
    v_21536 = list2star(v_21538, v_21537, v_21536);
    env = stack[-6];
    goto v_21517;
v_21518:
    goto v_21512;
v_21513:
    goto v_21514;
v_21515:
    goto v_21516;
v_21517:
    v_21536 = list2star(stack[-1], stack[0], v_21536);
    env = stack[-6];
    fn = elt(env, 18); // lambdaom
    v_21536 = (*qfn1(fn))(fn, v_21536);
    env = stack[-6];
    v_21536 = nil;
    fn = elt(env, 16); // indent!*
    v_21536 = (*qfn1(fn))(fn, v_21536);
    env = stack[-6];
    v_21536 = elt(env, 13); // "</OMA>"
    fn = elt(env, 15); // printout
    v_21536 = (*qfn1(fn))(fn, v_21536);
    v_21536 = nil;
    return onevalue(v_21536);
}



// Code for contposp

static LispObject CC_contposp(LispObject env,
                         LispObject v_21391)
{
    env = qenv(env);
    LispObject v_21413, v_21414;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21413 = v_21391;
// end of prologue
v_21390:
    v_21414 = v_21413;
    if (v_21414 == nil) goto v_21395;
    else goto v_21396;
v_21395:
    v_21413 = lisp_true;
    goto v_21394;
v_21396:
    v_21414 = v_21413;
    v_21414 = qcar(v_21414);
    if (!consp(v_21414)) goto v_21403;
    else goto v_21404;
v_21403:
    v_21413 = qcdr(v_21413);
    goto v_21390;
v_21404:
    v_21413 = nil;
    goto v_21402;
    v_21413 = nil;
v_21402:
    goto v_21394;
    v_21413 = nil;
v_21394:
    return onevalue(v_21413);
}



// Code for exdff0

static LispObject CC_exdff0(LispObject env,
                         LispObject v_21391)
{
    env = qenv(env);
    LispObject v_21496, v_21497;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21391);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_21391;
// end of prologue
    stack[-3] = nil;
v_21397:
    v_21496 = stack[-2];
    if (!consp(v_21496)) goto v_21406;
    else goto v_21407;
v_21406:
    v_21496 = lisp_true;
    goto v_21405;
v_21407:
    v_21496 = stack[-2];
    v_21496 = qcar(v_21496);
    v_21496 = (consp(v_21496) ? nil : lisp_true);
    goto v_21405;
    v_21496 = nil;
v_21405:
    if (v_21496 == nil) goto v_21403;
    goto v_21398;
v_21403:
    goto v_21420;
v_21416:
    goto v_21426;
v_21422:
    goto v_21432;
v_21428:
    goto v_21438;
v_21434:
    goto v_21445;
v_21441:
    v_21496 = stack[-2];
    v_21496 = qcar(v_21496);
    v_21497 = qcar(v_21496);
    goto v_21442;
v_21443:
    v_21496 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21444;
v_21445:
    goto v_21441;
v_21442:
    goto v_21443;
v_21444:
    v_21496 = cons(v_21497, v_21496);
    env = stack[-4];
    v_21497 = ncons(v_21496);
    env = stack[-4];
    goto v_21435;
v_21436:
    v_21496 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21437;
v_21438:
    goto v_21434;
v_21435:
    goto v_21436;
v_21437:
    stack[0] = cons(v_21497, v_21496);
    env = stack[-4];
    goto v_21429;
v_21430:
    v_21496 = stack[-2];
    v_21496 = qcar(v_21496);
    v_21496 = qcdr(v_21496);
    v_21496 = CC_exdff0(elt(env, 0), v_21496);
    env = stack[-4];
    goto v_21431;
v_21432:
    goto v_21428;
v_21429:
    goto v_21430;
v_21431:
    fn = elt(env, 1); // multsqpf
    stack[-1] = (*qfn2(fn))(fn, stack[0], v_21496);
    env = stack[-4];
    goto v_21423;
v_21424:
    goto v_21460;
v_21456:
    v_21496 = stack[-2];
    v_21496 = qcar(v_21496);
    v_21496 = qcar(v_21496);
    fn = elt(env, 2); // exdfp0
    stack[0] = (*qfn1(fn))(fn, v_21496);
    env = stack[-4];
    goto v_21457;
v_21458:
    goto v_21470;
v_21466:
    v_21496 = stack[-2];
    v_21496 = qcar(v_21496);
    v_21497 = qcdr(v_21496);
    goto v_21467;
v_21468:
    v_21496 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21469;
v_21470:
    goto v_21466;
v_21467:
    goto v_21468;
v_21469:
    v_21496 = cons(v_21497, v_21496);
    env = stack[-4];
    goto v_21459;
v_21460:
    goto v_21456;
v_21457:
    goto v_21458;
v_21459:
    fn = elt(env, 3); // multpfsq
    v_21496 = (*qfn2(fn))(fn, stack[0], v_21496);
    env = stack[-4];
    goto v_21425;
v_21426:
    goto v_21422;
v_21423:
    goto v_21424;
v_21425:
    fn = elt(env, 4); // addpf
    v_21497 = (*qfn2(fn))(fn, stack[-1], v_21496);
    env = stack[-4];
    goto v_21417;
v_21418:
    v_21496 = stack[-3];
    goto v_21419;
v_21420:
    goto v_21416;
v_21417:
    goto v_21418;
v_21419:
    v_21496 = cons(v_21497, v_21496);
    env = stack[-4];
    stack[-3] = v_21496;
    v_21496 = stack[-2];
    v_21496 = qcdr(v_21496);
    stack[-2] = v_21496;
    goto v_21397;
v_21398:
    v_21496 = nil;
    v_21497 = v_21496;
v_21399:
    v_21496 = stack[-3];
    if (v_21496 == nil) goto v_21481;
    else goto v_21482;
v_21481:
    v_21496 = v_21497;
    goto v_21396;
v_21482:
    goto v_21490;
v_21486:
    v_21496 = stack[-3];
    v_21496 = qcar(v_21496);
    goto v_21487;
v_21488:
    goto v_21489;
v_21490:
    goto v_21486;
v_21487:
    goto v_21488;
v_21489:
    fn = elt(env, 4); // addpf
    v_21496 = (*qfn2(fn))(fn, v_21496, v_21497);
    env = stack[-4];
    v_21497 = v_21496;
    v_21496 = stack[-3];
    v_21496 = qcdr(v_21496);
    stack[-3] = v_21496;
    goto v_21399;
v_21396:
    return onevalue(v_21496);
}



// Code for !:!:quotient

static LispObject CC_TTquotient(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21412, v_21413;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21413 = v_21392;
    v_21412 = v_21391;
// end of prologue
    goto v_21399;
v_21395:
    stack[0] = v_21412;
    goto v_21396;
v_21397:
    v_21412 = v_21413;
    v_21412 = integerp(v_21412);
    if (v_21412 == nil) goto v_21404;
    v_21412 = v_21413;
    fn = elt(env, 1); // i2rd!*
    v_21412 = (*qfn1(fn))(fn, v_21412);
    env = stack[-1];
    goto v_21402;
v_21404:
    v_21412 = v_21413;
    goto v_21402;
    v_21412 = nil;
v_21402:
    goto v_21398;
v_21399:
    goto v_21395;
v_21396:
    goto v_21397;
v_21398:
    {
        LispObject v_21415 = stack[0];
        fn = elt(env, 2); // !:quotient
        return (*qfn2(fn))(fn, v_21415, v_21412);
    }
}



// Code for getphystypeall

static LispObject CC_getphystypeall(LispObject env,
                         LispObject v_21391)
{
    env = qenv(env);
    LispObject v_21434, v_21435;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21391);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21391;
// end of prologue
    goto v_21407;
v_21403:
    v_21435 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21404;
v_21405:
    v_21434 = stack[0];
    goto v_21406;
v_21407:
    goto v_21403;
v_21404:
    goto v_21405;
v_21406:
    fn = elt(env, 3); // deleteall
    v_21434 = (*qfn2(fn))(fn, v_21435, v_21434);
    env = stack[-2];
    fn = elt(env, 4); // collectphystype
    v_21434 = (*qfn1(fn))(fn, v_21434);
    env = stack[-2];
    v_21435 = v_21434;
    if (v_21434 == nil) goto v_21399;
    else goto v_21400;
v_21399:
    v_21434 = nil;
    goto v_21395;
v_21400:
    v_21434 = v_21435;
    v_21434 = qcdr(v_21434);
    if (v_21434 == nil) goto v_21412;
    goto v_21420;
v_21416:
    stack[-1] = elt(env, 0); // getphystypeall
    goto v_21417;
v_21418:
    goto v_21427;
v_21423:
    v_21435 = elt(env, 2); // "PHYSOP type mismatch in"
    goto v_21424;
v_21425:
    v_21434 = stack[0];
    goto v_21426;
v_21427:
    goto v_21423;
v_21424:
    goto v_21425;
v_21426:
    v_21434 = list2(v_21435, v_21434);
    env = stack[-2];
    goto v_21419;
v_21420:
    goto v_21416;
v_21417:
    goto v_21418;
v_21419:
    fn = elt(env, 5); // rederr2
    v_21434 = (*qfn2(fn))(fn, stack[-1], v_21434);
    goto v_21398;
v_21412:
    v_21434 = v_21435;
    v_21434 = qcar(v_21434);
    goto v_21395;
v_21398:
    v_21434 = nil;
v_21395:
    return onevalue(v_21434);
}



// Code for evalgreaterp

static LispObject CC_evalgreaterp(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21468, v_21469, v_21470;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21469 = v_21392;
    v_21468 = v_21391;
// end of prologue
    goto v_21402;
v_21396:
    v_21470 = elt(env, 1); // difference
    goto v_21397;
v_21398:
    goto v_21399;
v_21400:
    goto v_21401;
v_21402:
    goto v_21396;
v_21397:
    goto v_21398;
v_21399:
    goto v_21400;
v_21401:
    v_21468 = list3(v_21470, v_21469, v_21468);
    env = stack[-1];
    fn = elt(env, 3); // simp!*
    v_21468 = (*qfn1(fn))(fn, v_21468);
    env = stack[-1];
    stack[0] = v_21468;
    v_21468 = stack[0];
    v_21468 = qcdr(v_21468);
    if (!consp(v_21468)) goto v_21414;
    v_21468 = lisp_true;
    goto v_21412;
v_21414:
    v_21468 = stack[0];
    v_21468 = qcar(v_21468);
    if (!consp(v_21468)) goto v_21422;
    else goto v_21423;
v_21422:
    v_21468 = lisp_true;
    goto v_21421;
v_21423:
    v_21468 = stack[0];
    v_21468 = qcar(v_21468);
    v_21468 = qcar(v_21468);
    v_21468 = (consp(v_21468) ? nil : lisp_true);
    goto v_21421;
    v_21468 = nil;
v_21421:
    v_21468 = (v_21468 == nil ? lisp_true : nil);
    goto v_21412;
    v_21468 = nil;
v_21412:
    if (v_21468 == nil) goto v_21410;
    goto v_21439;
v_21435:
    v_21468 = stack[0];
    v_21468 = qcar(v_21468);
    fn = elt(env, 4); // minusf
    v_21468 = (*qfn1(fn))(fn, v_21468);
    env = stack[-1];
    if (v_21468 == nil) goto v_21444;
    v_21468 = stack[0];
    fn = elt(env, 5); // negsq
    v_21468 = (*qfn1(fn))(fn, v_21468);
    env = stack[-1];
    goto v_21442;
v_21444:
    v_21468 = stack[0];
    goto v_21442;
    v_21468 = nil;
v_21442:
    fn = elt(env, 6); // mk!*sq
    v_21469 = (*qfn1(fn))(fn, v_21468);
    env = stack[-1];
    goto v_21436;
v_21437:
    v_21468 = elt(env, 2); // "number"
    goto v_21438;
v_21439:
    goto v_21435;
v_21436:
    goto v_21437;
v_21438:
    {
        fn = elt(env, 7); // typerr
        return (*qfn2(fn))(fn, v_21469, v_21468);
    }
v_21410:
    v_21468 = stack[0];
    v_21468 = qcar(v_21468);
    if (v_21468 == nil) goto v_21458;
    else goto v_21459;
v_21458:
    v_21468 = nil;
    goto v_21457;
v_21459:
    v_21468 = stack[0];
    v_21468 = qcar(v_21468);
    {
        fn = elt(env, 8); // !:minusp
        return (*qfn1(fn))(fn, v_21468);
    }
    v_21468 = nil;
v_21457:
    goto v_21408;
    v_21468 = nil;
v_21408:
    return onevalue(v_21468);
}



// Code for bas_make

static LispObject CC_bas_make(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21417, v_21418;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_21392;
    v_21417 = v_21391;
// end of prologue
    goto v_21403;
v_21395:
    stack[-3] = v_21417;
    goto v_21396;
v_21397:
    stack[-1] = stack[-2];
    goto v_21398;
v_21399:
    v_21417 = stack[-2];
    stack[0] = Llength(nil, v_21417);
    env = stack[-4];
    goto v_21400;
v_21401:
    goto v_21413;
v_21409:
    v_21417 = stack[-2];
    fn = elt(env, 1); // dp_ecart
    v_21418 = (*qfn1(fn))(fn, v_21417);
    env = stack[-4];
    goto v_21410;
v_21411:
    v_21417 = nil;
    goto v_21412;
v_21413:
    goto v_21409;
v_21410:
    goto v_21411;
v_21412:
    v_21417 = list2(v_21418, v_21417);
    goto v_21402;
v_21403:
    goto v_21395;
v_21396:
    goto v_21397;
v_21398:
    goto v_21399;
v_21400:
    goto v_21401;
v_21402:
    {
        LispObject v_21423 = stack[-3];
        LispObject v_21424 = stack[-1];
        LispObject v_21425 = stack[0];
        return list3star(v_21423, v_21424, v_21425, v_21417);
    }
}



// Code for split!-further

static LispObject CC_splitKfurther(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21605, v_21606, v_21607, v_21608;
    LispObject fn;
    LispObject v_21393, v_21392, v_21391;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "split-further");
    va_start(aa, nargs);
    v_21391 = va_arg(aa, LispObject);
    v_21392 = va_arg(aa, LispObject);
    v_21393 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21393,v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21391,v_21392,v_21393);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_21393;
    stack[-2] = v_21392;
    stack[-3] = v_21391;
// end of prologue
    v_21605 = stack[-3];
    if (v_21605 == nil) goto v_21397;
    else goto v_21398;
v_21397:
    v_21605 = nil;
    return ncons(v_21605);
v_21398:
    goto v_21419;
v_21413:
    v_21605 = stack[-3];
    v_21607 = qcdr(v_21605);
    goto v_21414;
v_21415:
    v_21606 = stack[-2];
    goto v_21416;
v_21417:
    v_21605 = stack[-1];
    goto v_21418;
v_21419:
    goto v_21413;
v_21414:
    goto v_21415;
v_21416:
    goto v_21417;
v_21418:
    v_21605 = CC_splitKfurther(elt(env, 0), 3, v_21607, v_21606, v_21605);
    env = stack[-5];
    stack[-4] = v_21605;
    v_21605 = stack[-4];
    v_21605 = qcdr(v_21605);
    stack[0] = v_21605;
    v_21605 = stack[-4];
    v_21605 = qcar(v_21605);
    stack[-4] = v_21605;
    goto v_21436;
v_21432:
    v_21606 = qvalue(elt(env, 2)); // number!-needed
    goto v_21433;
v_21434:
    v_21605 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21435;
v_21436:
    goto v_21432;
v_21433:
    goto v_21434;
v_21435:
    if (v_21606 == v_21605) goto v_21430;
    else goto v_21431;
v_21430:
    goto v_21410;
v_21431:
    goto v_21446;
v_21440:
    v_21607 = stack[-2];
    goto v_21441;
v_21442:
    v_21606 = stack[-1];
    goto v_21443;
v_21444:
    v_21605 = qvalue(elt(env, 3)); // work!-vector1
    goto v_21445;
v_21446:
    goto v_21440;
v_21441:
    goto v_21442;
v_21443:
    goto v_21444;
v_21445:
    fn = elt(env, 7); // copy!-vector
    v_21605 = (*qfnn(fn))(fn, 3, v_21607, v_21606, v_21605);
    env = stack[-5];
    qvalue(elt(env, 4)) = v_21605; // dwork1
    goto v_21457;
v_21451:
    v_21605 = stack[-3];
    v_21605 = qcar(v_21605);
    v_21607 = qcar(v_21605);
    goto v_21452;
v_21453:
    v_21605 = stack[-3];
    v_21605 = qcar(v_21605);
    v_21606 = qcdr(v_21605);
    goto v_21454;
v_21455:
    v_21605 = qvalue(elt(env, 5)); // work!-vector2
    goto v_21456;
v_21457:
    goto v_21451;
v_21452:
    goto v_21453;
v_21454:
    goto v_21455;
v_21456:
    fn = elt(env, 7); // copy!-vector
    v_21605 = (*qfnn(fn))(fn, 3, v_21607, v_21606, v_21605);
    env = stack[-5];
    qvalue(elt(env, 6)) = v_21605; // dwork2
    goto v_21474;
v_21466:
    v_21608 = qvalue(elt(env, 3)); // work!-vector1
    goto v_21467;
v_21468:
    v_21607 = qvalue(elt(env, 4)); // dwork1
    goto v_21469;
v_21470:
    v_21606 = qvalue(elt(env, 5)); // work!-vector2
    goto v_21471;
v_21472:
    v_21605 = qvalue(elt(env, 6)); // dwork2
    goto v_21473;
v_21474:
    goto v_21466;
v_21467:
    goto v_21468;
v_21469:
    goto v_21470;
v_21471:
    goto v_21472;
v_21473:
    fn = elt(env, 8); // gcd!-in!-vector
    v_21605 = (*qfnn(fn))(fn, 4, v_21608, v_21607, v_21606, v_21605);
    env = stack[-5];
    qvalue(elt(env, 4)) = v_21605; // dwork1
    goto v_21491;
v_21487:
    v_21606 = qvalue(elt(env, 4)); // dwork1
    goto v_21488;
v_21489:
    v_21605 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21490;
v_21491:
    goto v_21487;
v_21488:
    goto v_21489;
v_21490:
    if (v_21606 == v_21605) goto v_21485;
    else goto v_21486;
v_21485:
    v_21605 = lisp_true;
    goto v_21484;
v_21486:
    goto v_21501;
v_21497:
    v_21606 = qvalue(elt(env, 4)); // dwork1
    goto v_21498;
v_21499:
    v_21605 = stack[-3];
    v_21605 = qcar(v_21605);
    v_21605 = qcdr(v_21605);
    goto v_21500;
v_21501:
    goto v_21497;
v_21498:
    goto v_21499;
v_21500:
    v_21605 = (equal(v_21606, v_21605) ? lisp_true : nil);
    goto v_21484;
    v_21605 = nil;
v_21484:
    if (v_21605 == nil) goto v_21482;
    goto v_21410;
v_21482:
    goto v_21514;
v_21508:
    v_21605 = stack[-3];
    v_21605 = qcar(v_21605);
    v_21607 = qcar(v_21605);
    goto v_21509;
v_21510:
    v_21605 = stack[-3];
    v_21605 = qcar(v_21605);
    v_21606 = qcdr(v_21605);
    goto v_21511;
v_21512:
    v_21605 = qvalue(elt(env, 5)); // work!-vector2
    goto v_21513;
v_21514:
    goto v_21508;
v_21509:
    goto v_21510;
v_21511:
    goto v_21512;
v_21513:
    fn = elt(env, 7); // copy!-vector
    v_21605 = (*qfnn(fn))(fn, 3, v_21607, v_21606, v_21605);
    env = stack[-5];
    qvalue(elt(env, 6)) = v_21605; // dwork2
    goto v_21531;
v_21523:
    v_21608 = qvalue(elt(env, 5)); // work!-vector2
    goto v_21524;
v_21525:
    v_21607 = qvalue(elt(env, 6)); // dwork2
    goto v_21526;
v_21527:
    v_21606 = qvalue(elt(env, 3)); // work!-vector1
    goto v_21528;
v_21529:
    v_21605 = qvalue(elt(env, 4)); // dwork1
    goto v_21530;
v_21531:
    goto v_21523;
v_21524:
    goto v_21525;
v_21526:
    goto v_21527;
v_21528:
    goto v_21529;
v_21530:
    fn = elt(env, 9); // quotfail!-in!-vector
    v_21605 = (*qfnn(fn))(fn, 4, v_21608, v_21607, v_21606, v_21605);
    env = stack[-5];
    qvalue(elt(env, 6)) = v_21605; // dwork2
    v_21605 = qvalue(elt(env, 4)); // dwork1
    v_21605 = Lmkvect(nil, v_21605);
    env = stack[-5];
    stack[-1] = v_21605;
    goto v_21545;
v_21539:
    v_21607 = qvalue(elt(env, 3)); // work!-vector1
    goto v_21540;
v_21541:
    v_21606 = qvalue(elt(env, 4)); // dwork1
    goto v_21542;
v_21543:
    v_21605 = stack[-1];
    goto v_21544;
v_21545:
    goto v_21539;
v_21540:
    goto v_21541;
v_21542:
    goto v_21543;
v_21544:
    fn = elt(env, 7); // copy!-vector
    v_21605 = (*qfnn(fn))(fn, 3, v_21607, v_21606, v_21605);
    env = stack[-5];
    goto v_21556;
v_21550:
    v_21607 = stack[-1];
    goto v_21551;
v_21552:
    v_21606 = qvalue(elt(env, 4)); // dwork1
    goto v_21553;
v_21554:
    v_21605 = stack[-4];
    goto v_21555;
v_21556:
    goto v_21550;
v_21551:
    goto v_21552;
v_21553:
    goto v_21554;
v_21555:
    v_21605 = acons(v_21607, v_21606, v_21605);
    env = stack[-5];
    stack[-4] = v_21605;
    goto v_21567;
v_21561:
    stack[-2] = qvalue(elt(env, 5)); // work!-vector2
    goto v_21562;
v_21563:
    stack[-1] = qvalue(elt(env, 6)); // dwork2
    goto v_21564;
v_21565:
    v_21605 = qvalue(elt(env, 6)); // dwork2
    v_21605 = Lmkvect(nil, v_21605);
    env = stack[-5];
    stack[-3] = v_21605;
    goto v_21566;
v_21567:
    goto v_21561;
v_21562:
    goto v_21563;
v_21564:
    goto v_21565;
v_21566:
    fn = elt(env, 7); // copy!-vector
    v_21605 = (*qfnn(fn))(fn, 3, stack[-2], stack[-1], v_21605);
    env = stack[-5];
    goto v_21579;
v_21573:
    v_21607 = stack[-3];
    goto v_21574;
v_21575:
    v_21606 = qvalue(elt(env, 6)); // dwork2
    goto v_21576;
v_21577:
    v_21605 = stack[0];
    goto v_21578;
v_21579:
    goto v_21573;
v_21574:
    goto v_21575;
v_21576:
    goto v_21577;
v_21578:
    v_21605 = acons(v_21607, v_21606, v_21605);
    env = stack[-5];
    stack[0] = v_21605;
    v_21605 = qvalue(elt(env, 2)); // number!-needed
    v_21605 = (LispObject)((intptr_t)(v_21605) - 0x10);
    qvalue(elt(env, 2)) = v_21605; // number!-needed
    goto v_21590;
v_21586:
    v_21606 = stack[-4];
    goto v_21587;
v_21588:
    v_21605 = stack[0];
    goto v_21589;
v_21590:
    goto v_21586;
v_21587:
    goto v_21588;
v_21589:
    return cons(v_21606, v_21605);
v_21410:
    goto v_21600;
v_21594:
    v_21607 = stack[-4];
    goto v_21595;
v_21596:
    v_21605 = stack[-3];
    v_21606 = qcar(v_21605);
    goto v_21597;
v_21598:
    v_21605 = stack[0];
    goto v_21599;
v_21600:
    goto v_21594;
v_21595:
    goto v_21596;
v_21597:
    goto v_21598;
v_21599:
    return list2star(v_21607, v_21606, v_21605);
    goto v_21396;
    v_21605 = nil;
v_21396:
    return onevalue(v_21605);
}



// Code for ext_mult

static LispObject CC_ext_mult(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21467, v_21468, v_21469;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21467 = v_21392;
    v_21468 = v_21391;
// end of prologue
    goto v_21399;
v_21395:
    v_21468 = qcdr(v_21468);
    goto v_21396;
v_21397:
    v_21467 = qcdr(v_21467);
    goto v_21398;
v_21399:
    goto v_21395;
v_21396:
    goto v_21397;
v_21398:
    fn = elt(env, 2); // merge_lists
    v_21467 = (*qfn2(fn))(fn, v_21468, v_21467);
    env = stack[-1];
    stack[0] = v_21467;
    v_21467 = stack[0];
    if (v_21467 == nil) goto v_21407;
    else goto v_21408;
v_21407:
    goto v_21415;
v_21411:
    v_21468 = nil;
    goto v_21412;
v_21413:
    v_21467 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21414;
v_21415:
    goto v_21411;
v_21412:
    goto v_21413;
v_21414:
    return cons(v_21468, v_21467);
v_21408:
    v_21467 = stack[0];
    v_21467 = qcdr(v_21467);
    if (v_21467 == nil) goto v_21418;
    else goto v_21419;
v_21418:
    goto v_21427;
v_21423:
    v_21468 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21424;
v_21425:
    v_21467 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21426;
v_21427:
    goto v_21423;
v_21424:
    goto v_21425;
v_21426:
    return cons(v_21468, v_21467);
v_21419:
    goto v_21439;
v_21433:
    goto v_21445;
v_21441:
    goto v_21451;
v_21447:
    goto v_21458;
v_21454:
    v_21468 = elt(env, 1); // ext
    goto v_21455;
v_21456:
    v_21467 = stack[0];
    v_21467 = qcdr(v_21467);
    goto v_21457;
v_21458:
    goto v_21454;
v_21455:
    goto v_21456;
v_21457:
    v_21467 = cons(v_21468, v_21467);
    env = stack[-1];
    fn = elt(env, 3); // !*a2k
    v_21468 = (*qfn1(fn))(fn, v_21467);
    env = stack[-1];
    goto v_21448;
v_21449:
    v_21467 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21450;
v_21451:
    goto v_21447;
v_21448:
    goto v_21449;
v_21450:
    fn = elt(env, 4); // to
    v_21468 = (*qfn2(fn))(fn, v_21468, v_21467);
    env = stack[-1];
    goto v_21442;
v_21443:
    v_21467 = stack[0];
    v_21467 = qcar(v_21467);
    goto v_21444;
v_21445:
    goto v_21441;
v_21442:
    goto v_21443;
v_21444:
    v_21469 = cons(v_21468, v_21467);
    goto v_21434;
v_21435:
    v_21468 = nil;
    goto v_21436;
v_21437:
    v_21467 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21438;
v_21439:
    goto v_21433;
v_21434:
    goto v_21435;
v_21436:
    goto v_21437;
v_21438:
    return acons(v_21469, v_21468, v_21467);
    v_21467 = nil;
    return onevalue(v_21467);
}



// Code for multivariatep

static LispObject CC_multivariatep(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21443, v_21444;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21392;
    stack[-1] = v_21391;
// end of prologue
v_21396:
    v_21443 = stack[-1];
    if (!consp(v_21443)) goto v_21403;
    else goto v_21404;
v_21403:
    v_21443 = lisp_true;
    goto v_21402;
v_21404:
    v_21443 = stack[-1];
    v_21443 = qcar(v_21443);
    v_21443 = (consp(v_21443) ? nil : lisp_true);
    goto v_21402;
    v_21443 = nil;
v_21402:
    if (v_21443 == nil) goto v_21400;
    v_21443 = nil;
    goto v_21395;
v_21400:
    goto v_21419;
v_21415:
    v_21443 = stack[-1];
    v_21443 = qcar(v_21443);
    v_21443 = qcar(v_21443);
    v_21444 = qcar(v_21443);
    goto v_21416;
v_21417:
    v_21443 = stack[0];
    goto v_21418;
v_21419:
    goto v_21415;
v_21416:
    goto v_21417;
v_21418:
    if (v_21444 == v_21443) goto v_21414;
    v_21443 = lisp_true;
    goto v_21395;
v_21414:
    goto v_21433;
v_21429:
    v_21443 = stack[-1];
    v_21443 = qcar(v_21443);
    v_21444 = qcdr(v_21443);
    goto v_21430;
v_21431:
    v_21443 = stack[0];
    goto v_21432;
v_21433:
    goto v_21429;
v_21430:
    goto v_21431;
v_21432:
    v_21443 = CC_multivariatep(elt(env, 0), v_21444, v_21443);
    env = stack[-2];
    if (v_21443 == nil) goto v_21427;
    v_21443 = lisp_true;
    goto v_21395;
v_21427:
    v_21443 = stack[-1];
    v_21443 = qcdr(v_21443);
    stack[-1] = v_21443;
    goto v_21396;
    v_21443 = nil;
v_21395:
    return onevalue(v_21443);
}



// Code for lex_init

static LispObject CC_lex_init(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21418, v_21419;
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
    v_21418 = (LispObject)1024+TAG_FIXNUM; // 64
    v_21418 = Lmkvect(nil, v_21418);
    env = stack[0];
    qvalue(elt(env, 1)) = v_21418; // last64
    v_21418 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 2)) = v_21418; // last64p
    v_21418 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 3)) = v_21418; // which_line
    v_21418 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 4)) = v_21418; // if_depth
    v_21418 = qvalue(elt(env, 5)); // !*tracelex
    if (v_21418 == nil) goto v_21400;
    goto v_21410;
v_21406:
    v_21419 = Lposn(nil, 0);
    env = stack[0];
    goto v_21407;
v_21408:
    v_21418 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21409;
v_21410:
    goto v_21406;
v_21407:
    goto v_21408;
v_21409:
    if (v_21419 == v_21418) goto v_21405;
    v_21418 = Lterpri(nil, 0);
    env = stack[0];
    goto v_21403;
v_21405:
v_21403:
    v_21418 = elt(env, 6); // "yylex initialized"
    v_21418 = Lprintc(nil, v_21418);
    env = stack[0];
    goto v_21398;
v_21400:
v_21398:
    v_21418 = nil;
    qvalue(elt(env, 7)) = v_21418; // lex_peeked
    {
        fn = elt(env, 8); // yyreadch
        return (*qfnn(fn))(fn, 0);
    }
}



// Code for rl_qefsolset

static LispObject CC_rl_qefsolset(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21425, v_21426, v_21427, v_21428, v_21429;
    LispObject fn;
    LispObject v_21395, v_21394, v_21393, v_21392, v_21391;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "rl_qefsolset");
    va_start(aa, nargs);
    v_21391 = va_arg(aa, LispObject);
    v_21392 = va_arg(aa, LispObject);
    v_21393 = va_arg(aa, LispObject);
    v_21394 = va_arg(aa, LispObject);
    v_21395 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_21395,v_21394,v_21393,v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_21391,v_21392,v_21393,v_21394,v_21395);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_21425 = v_21395;
    v_21426 = v_21394;
    v_21427 = v_21393;
    v_21428 = v_21392;
    v_21429 = v_21391;
// end of prologue
    goto v_21402;
v_21398:
    stack[-3] = qvalue(elt(env, 1)); // rl_qefsolset!*
    goto v_21399;
v_21400:
    goto v_21413;
v_21405:
    stack[-2] = v_21429;
    goto v_21406;
v_21407:
    stack[-1] = v_21428;
    goto v_21408;
v_21409:
    stack[0] = v_21427;
    goto v_21410;
v_21411:
    goto v_21422;
v_21418:
    goto v_21419;
v_21420:
    goto v_21421;
v_21422:
    goto v_21418;
v_21419:
    goto v_21420;
v_21421:
    v_21425 = list2(v_21426, v_21425);
    env = stack[-4];
    goto v_21412;
v_21413:
    goto v_21405;
v_21406:
    goto v_21407;
v_21408:
    goto v_21409;
v_21410:
    goto v_21411;
v_21412:
    v_21425 = list3star(stack[-2], stack[-1], stack[0], v_21425);
    env = stack[-4];
    goto v_21401;
v_21402:
    goto v_21398;
v_21399:
    goto v_21400;
v_21401:
    {
        LispObject v_21434 = stack[-3];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_21434, v_21425);
    }
}



// Code for even_action_sf

static LispObject CC_even_action_sf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21452, v_21453, v_21454, v_21455;
    LispObject fn;
    LispObject v_21394, v_21393, v_21392, v_21391;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "even_action_sf");
    va_start(aa, nargs);
    v_21391 = va_arg(aa, LispObject);
    v_21392 = va_arg(aa, LispObject);
    v_21393 = va_arg(aa, LispObject);
    v_21394 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_21394,v_21393,v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_21391,v_21392,v_21393,v_21394);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_21394;
    stack[-1] = v_21393;
    stack[-2] = v_21392;
    stack[-3] = v_21391;
// end of prologue
    goto v_21405;
v_21401:
    v_21453 = nil;
    goto v_21402;
v_21403:
    v_21452 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_21404;
v_21405:
    goto v_21401;
v_21402:
    goto v_21403;
v_21404:
    v_21452 = cons(v_21453, v_21452);
    env = stack[-5];
    v_21453 = v_21452;
v_21410:
    v_21452 = stack[-2];
    if (!consp(v_21452)) goto v_21417;
    else goto v_21418;
v_21417:
    v_21452 = lisp_true;
    goto v_21416;
v_21418:
    v_21452 = stack[-2];
    v_21452 = qcar(v_21452);
    v_21452 = (consp(v_21452) ? nil : lisp_true);
    goto v_21416;
    v_21452 = nil;
v_21416:
    if (v_21452 == nil) goto v_21414;
    goto v_21409;
v_21414:
    goto v_21432;
v_21428:
    stack[-4] = v_21453;
    goto v_21429;
v_21430:
    goto v_21443;
v_21435:
    v_21455 = stack[-3];
    goto v_21436;
v_21437:
    v_21452 = stack[-2];
    v_21454 = qcar(v_21452);
    goto v_21438;
v_21439:
    v_21453 = stack[-1];
    goto v_21440;
v_21441:
    v_21452 = stack[0];
    goto v_21442;
v_21443:
    goto v_21435;
v_21436:
    goto v_21437;
v_21438:
    goto v_21439;
v_21440:
    goto v_21441;
v_21442:
    fn = elt(env, 2); // even_action_term
    v_21452 = (*qfnn(fn))(fn, 4, v_21455, v_21454, v_21453, v_21452);
    env = stack[-5];
    goto v_21431;
v_21432:
    goto v_21428;
v_21429:
    goto v_21430;
v_21431:
    fn = elt(env, 3); // addsq
    v_21452 = (*qfn2(fn))(fn, stack[-4], v_21452);
    env = stack[-5];
    v_21453 = v_21452;
    v_21452 = stack[-2];
    v_21452 = qcdr(v_21452);
    stack[-2] = v_21452;
    goto v_21410;
v_21409:
    v_21452 = v_21453;
    return onevalue(v_21452);
}



// Code for talp_maxd

static LispObject CC_talp_maxd(LispObject env,
                         LispObject v_21391)
{
    env = qenv(env);
    LispObject v_21449, v_21450;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21391);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_21450 = v_21391;
// end of prologue
    v_21449 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_21449;
    v_21449 = v_21450;
    if (!consp(v_21449)) goto v_21403;
    else goto v_21404;
v_21403:
    v_21449 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21397;
v_21404:
    v_21449 = v_21450;
    fn = elt(env, 2); // rl_atl
    v_21449 = (*qfn1(fn))(fn, v_21449);
    env = stack[-3];
    stack[-2] = v_21449;
v_21411:
    v_21449 = stack[-2];
    if (v_21449 == nil) goto v_21414;
    else goto v_21415;
v_21414:
    goto v_21410;
v_21415:
    goto v_21423;
v_21419:
    v_21449 = stack[-2];
    v_21449 = qcar(v_21449);
    fn = elt(env, 3); // talp_arg2l
    v_21449 = (*qfn1(fn))(fn, v_21449);
    env = stack[-3];
    fn = elt(env, 4); // talp_td
    stack[0] = (*qfn1(fn))(fn, v_21449);
    env = stack[-3];
    goto v_21420;
v_21421:
    v_21449 = stack[-2];
    v_21449 = qcar(v_21449);
    fn = elt(env, 5); // talp_arg2r
    v_21449 = (*qfn1(fn))(fn, v_21449);
    env = stack[-3];
    fn = elt(env, 4); // talp_td
    v_21449 = (*qfn1(fn))(fn, v_21449);
    env = stack[-3];
    goto v_21422;
v_21423:
    goto v_21419;
v_21420:
    goto v_21421;
v_21422:
    v_21449 = Lmax2(nil, stack[0], v_21449);
    env = stack[-3];
    stack[0] = v_21449;
    goto v_21441;
v_21437:
    v_21450 = stack[0];
    goto v_21438;
v_21439:
    v_21449 = stack[-1];
    goto v_21440;
v_21441:
    goto v_21437;
v_21438:
    goto v_21439;
v_21440:
    v_21449 = (LispObject)greaterp2(v_21450, v_21449);
    v_21449 = v_21449 ? lisp_true : nil;
    env = stack[-3];
    if (v_21449 == nil) goto v_21435;
    v_21449 = stack[0];
    stack[-1] = v_21449;
    goto v_21433;
v_21435:
v_21433:
    v_21449 = stack[-2];
    v_21449 = qcdr(v_21449);
    stack[-2] = v_21449;
    goto v_21411;
v_21410:
    v_21449 = stack[-1];
v_21397:
    return onevalue(v_21449);
}



// Code for rl_bnfsimpl

static LispObject CC_rl_bnfsimpl(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21409, v_21410;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21409 = v_21392;
    v_21410 = v_21391;
// end of prologue
    goto v_21399;
v_21395:
    stack[0] = qvalue(elt(env, 1)); // rl_bnfsimpl!*
    goto v_21396;
v_21397:
    goto v_21406;
v_21402:
    goto v_21403;
v_21404:
    goto v_21405;
v_21406:
    goto v_21402;
v_21403:
    goto v_21404;
v_21405:
    v_21409 = list2(v_21410, v_21409);
    env = stack[-1];
    goto v_21398;
v_21399:
    goto v_21395;
v_21396:
    goto v_21397;
v_21398:
    {
        LispObject v_21412 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_21412, v_21409);
    }
}



// Code for sfto_b!:extadd

static LispObject CC_sfto_bTextadd(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21525, v_21526, v_21527;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_21392;
    stack[-2] = v_21391;
// end of prologue
    stack[0] = nil;
v_21397:
    v_21525 = stack[-2];
    if (v_21525 == nil) goto v_21400;
    else goto v_21401;
v_21400:
    goto v_21408;
v_21404:
    v_21526 = stack[0];
    goto v_21405;
v_21406:
    v_21525 = stack[-1];
    goto v_21407;
v_21408:
    goto v_21404;
v_21405:
    goto v_21406;
v_21407:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_21526, v_21525);
    }
v_21401:
    v_21525 = stack[-1];
    if (v_21525 == nil) goto v_21411;
    else goto v_21412;
v_21411:
    goto v_21419;
v_21415:
    v_21526 = stack[0];
    goto v_21416;
v_21417:
    v_21525 = stack[-2];
    goto v_21418;
v_21419:
    goto v_21415;
v_21416:
    goto v_21417;
v_21418:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_21526, v_21525);
    }
v_21412:
    goto v_21428;
v_21424:
    v_21525 = stack[-2];
    v_21525 = qcar(v_21525);
    v_21526 = qcar(v_21525);
    goto v_21425;
v_21426:
    v_21525 = stack[-1];
    v_21525 = qcar(v_21525);
    v_21525 = qcar(v_21525);
    goto v_21427;
v_21428:
    goto v_21424;
v_21425:
    goto v_21426;
v_21427:
    if (equal(v_21526, v_21525)) goto v_21422;
    else goto v_21423;
v_21422:
    goto v_21440;
v_21436:
    stack[-3] = stack[0];
    goto v_21437;
v_21438:
    goto v_21447;
v_21443:
    v_21525 = stack[-2];
    v_21525 = qcar(v_21525);
    v_21526 = qcdr(v_21525);
    goto v_21444;
v_21445:
    v_21525 = stack[-1];
    v_21525 = qcar(v_21525);
    v_21525 = qcdr(v_21525);
    goto v_21446;
v_21447:
    goto v_21443;
v_21444:
    goto v_21445;
v_21446:
    fn = elt(env, 2); // addf
    stack[0] = (*qfn2(fn))(fn, v_21526, v_21525);
    env = stack[-4];
    goto v_21459;
v_21455:
    v_21525 = stack[-2];
    v_21526 = qcdr(v_21525);
    goto v_21456;
v_21457:
    v_21525 = stack[-1];
    v_21525 = qcdr(v_21525);
    goto v_21458;
v_21459:
    goto v_21455;
v_21456:
    goto v_21457;
v_21458:
    v_21525 = CC_sfto_bTextadd(elt(env, 0), v_21526, v_21525);
    env = stack[-4];
    v_21526 = stack[0];
    v_21527 = v_21526;
    if (v_21527 == nil) goto v_21468;
    else goto v_21469;
v_21468:
    goto v_21467;
v_21469:
    goto v_21481;
v_21475:
    v_21527 = stack[-2];
    v_21527 = qcar(v_21527);
    v_21527 = qcar(v_21527);
    goto v_21476;
v_21477:
    goto v_21478;
v_21479:
    goto v_21480;
v_21481:
    goto v_21475;
v_21476:
    goto v_21477;
v_21478:
    goto v_21479;
v_21480:
    v_21525 = acons(v_21527, v_21526, v_21525);
    env = stack[-4];
    goto v_21467;
    v_21525 = nil;
v_21467:
    goto v_21439;
v_21440:
    goto v_21436;
v_21437:
    goto v_21438;
v_21439:
    {
        LispObject v_21532 = stack[-3];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_21532, v_21525);
    }
v_21423:
    goto v_21494;
v_21490:
    v_21525 = stack[-2];
    v_21525 = qcar(v_21525);
    v_21526 = qcar(v_21525);
    goto v_21491;
v_21492:
    v_21525 = stack[-1];
    v_21525 = qcar(v_21525);
    v_21525 = qcar(v_21525);
    goto v_21493;
v_21494:
    goto v_21490;
v_21491:
    goto v_21492;
v_21493:
    fn = elt(env, 3); // sfto_b!:ordexp
    v_21525 = (*qfn2(fn))(fn, v_21526, v_21525);
    env = stack[-4];
    if (v_21525 == nil) goto v_21488;
    goto v_21506;
v_21502:
    v_21525 = stack[-2];
    v_21526 = qcar(v_21525);
    goto v_21503;
v_21504:
    v_21525 = stack[0];
    goto v_21505;
v_21506:
    goto v_21502;
v_21503:
    goto v_21504;
v_21505:
    v_21525 = cons(v_21526, v_21525);
    env = stack[-4];
    stack[0] = v_21525;
    v_21525 = stack[-2];
    v_21525 = qcdr(v_21525);
    stack[-2] = v_21525;
    goto v_21397;
v_21488:
    goto v_21519;
v_21515:
    v_21525 = stack[-1];
    v_21526 = qcar(v_21525);
    goto v_21516;
v_21517:
    v_21525 = stack[0];
    goto v_21518;
v_21519:
    goto v_21515;
v_21516:
    goto v_21517;
v_21518:
    v_21525 = cons(v_21526, v_21525);
    env = stack[-4];
    stack[0] = v_21525;
    v_21525 = stack[-1];
    v_21525 = qcdr(v_21525);
    stack[-1] = v_21525;
    goto v_21397;
    v_21525 = nil;
    return onevalue(v_21525);
}



// Code for ciml

static LispObject CC_ciml(LispObject env,
                         LispObject v_21391)
{
    env = qenv(env);
    LispObject v_21413, v_21414;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21391);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_21391;
// end of prologue
    v_21413 = elt(env, 1); // "<ci"
    fn = elt(env, 4); // printout
    v_21413 = (*qfn1(fn))(fn, v_21413);
    env = stack[-1];
    goto v_21403;
v_21399:
    v_21413 = stack[0];
    v_21414 = qcar(v_21413);
    goto v_21400;
v_21401:
    v_21413 = elt(env, 2); // ""
    goto v_21402;
v_21403:
    goto v_21399;
v_21400:
    goto v_21401;
v_21402:
    fn = elt(env, 5); // attributesml
    v_21413 = (*qfn2(fn))(fn, v_21414, v_21413);
    env = stack[-1];
    v_21413 = stack[0];
    v_21413 = qcdr(v_21413);
    v_21413 = qcar(v_21413);
    v_21413 = Lprinc(nil, v_21413);
    env = stack[-1];
    v_21413 = elt(env, 3); // "</ci>"
    v_21413 = Lprinc(nil, v_21413);
    v_21413 = nil;
    return onevalue(v_21413);
}



// Code for groebinvokecritm

static LispObject CC_groebinvokecritm(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21435, v_21436;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_21392;
    stack[-2] = v_21391;
// end of prologue
    v_21435 = stack[-1];
    stack[-3] = v_21435;
v_21397:
    v_21435 = stack[-3];
    if (v_21435 == nil) goto v_21401;
    else goto v_21402;
v_21401:
    goto v_21396;
v_21402:
    v_21435 = stack[-3];
    v_21435 = qcar(v_21435);
    stack[0] = v_21435;
    goto v_21417;
v_21413:
    v_21435 = stack[-2];
    v_21436 = qcar(v_21435);
    goto v_21414;
v_21415:
    v_21435 = stack[0];
    v_21435 = qcar(v_21435);
    goto v_21416;
v_21417:
    goto v_21413;
v_21414:
    goto v_21415;
v_21416:
    fn = elt(env, 2); // buchvevdivides!?
    v_21435 = (*qfn2(fn))(fn, v_21436, v_21435);
    env = stack[-4];
    if (v_21435 == nil) goto v_21411;
    v_21435 = qvalue(elt(env, 1)); // mcount!*
    v_21435 = add1(v_21435);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_21435; // mcount!*
    goto v_21429;
v_21425:
    v_21436 = stack[0];
    goto v_21426;
v_21427:
    v_21435 = stack[-1];
    goto v_21428;
v_21429:
    goto v_21425;
v_21426:
    goto v_21427;
v_21428:
    fn = elt(env, 3); // groedeletip
    v_21435 = (*qfn2(fn))(fn, v_21436, v_21435);
    env = stack[-4];
    stack[-1] = v_21435;
    goto v_21409;
v_21411:
v_21409:
    v_21435 = stack[-3];
    v_21435 = qcdr(v_21435);
    stack[-3] = v_21435;
    goto v_21397;
v_21396:
    v_21435 = stack[-1];
    return onevalue(v_21435);
}



// Code for collectphysops_reversed

static LispObject CC_collectphysops_reversed(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21460, v_21461;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21392;
    stack[-1] = v_21391;
// end of prologue
    v_21460 = stack[-1];
    if (!consp(v_21460)) goto v_21399;
    else goto v_21400;
v_21399:
    v_21460 = stack[-1];
    fn = elt(env, 1); // physopp
    v_21460 = (*qfn1(fn))(fn, v_21460);
    if (v_21460 == nil) goto v_21405;
    goto v_21413;
v_21409:
    v_21461 = stack[-1];
    goto v_21410;
v_21411:
    v_21460 = stack[0];
    goto v_21412;
v_21413:
    goto v_21409;
v_21410:
    goto v_21411;
v_21412:
    return cons(v_21461, v_21460);
v_21405:
    v_21460 = stack[0];
    goto v_21395;
    goto v_21398;
v_21400:
    v_21460 = stack[-1];
    fn = elt(env, 1); // physopp
    v_21460 = (*qfn1(fn))(fn, v_21460);
    env = stack[-3];
    if (v_21460 == nil) goto v_21420;
    goto v_21428;
v_21424:
    goto v_21434;
v_21430:
    stack[-2] = stack[-1];
    goto v_21431;
v_21432:
    v_21460 = stack[-1];
    fn = elt(env, 2); // collectindices
    v_21460 = (*qfn1(fn))(fn, v_21460);
    env = stack[-3];
    goto v_21433;
v_21434:
    goto v_21430;
v_21431:
    goto v_21432;
v_21433:
    fn = elt(env, 3); // removeindices
    v_21461 = (*qfn2(fn))(fn, stack[-2], v_21460);
    goto v_21425;
v_21426:
    v_21460 = stack[0];
    goto v_21427;
v_21428:
    goto v_21424;
v_21425:
    goto v_21426;
v_21427:
    return cons(v_21461, v_21460);
v_21420:
v_21398:
v_21441:
    v_21460 = stack[-1];
    if (!consp(v_21460)) goto v_21444;
    else goto v_21445;
v_21444:
    goto v_21440;
v_21445:
    goto v_21453;
v_21449:
    v_21460 = stack[-1];
    v_21461 = qcar(v_21460);
    goto v_21450;
v_21451:
    v_21460 = stack[0];
    goto v_21452;
v_21453:
    goto v_21449;
v_21450:
    goto v_21451;
v_21452:
    v_21460 = CC_collectphysops_reversed(elt(env, 0), v_21461, v_21460);
    env = stack[-3];
    stack[0] = v_21460;
    v_21460 = stack[-1];
    v_21460 = qcdr(v_21460);
    stack[-1] = v_21460;
    goto v_21441;
v_21440:
    v_21460 = stack[0];
v_21395:
    return onevalue(v_21460);
}



// Code for subcare

static LispObject CC_subcare(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21473, v_21474, v_21475;
    LispObject fn;
    LispObject v_21393, v_21392, v_21391;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "subcare");
    va_start(aa, nargs);
    v_21391 = va_arg(aa, LispObject);
    v_21392 = va_arg(aa, LispObject);
    v_21393 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21393,v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21391,v_21392,v_21393);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_21393;
    stack[-1] = v_21392;
    stack[-2] = v_21391;
// end of prologue
    stack[-3] = nil;
v_21398:
    v_21473 = stack[0];
    if (v_21473 == nil) goto v_21401;
    else goto v_21402;
v_21401:
    v_21473 = stack[-3];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_21473);
    }
v_21402:
    goto v_21412;
v_21408:
    v_21474 = stack[-2];
    goto v_21409;
v_21410:
    v_21473 = stack[0];
    goto v_21411;
v_21412:
    goto v_21408;
v_21409:
    goto v_21410;
v_21411:
    if (equal(v_21474, v_21473)) goto v_21406;
    else goto v_21407;
v_21406:
    goto v_21420;
v_21416:
    v_21474 = stack[-3];
    goto v_21417;
v_21418:
    v_21473 = stack[-1];
    goto v_21419;
v_21420:
    goto v_21416;
v_21417:
    goto v_21418;
v_21419:
    {
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_21474, v_21473);
    }
v_21407:
    v_21473 = stack[0];
    if (!consp(v_21473)) goto v_21427;
    else goto v_21428;
v_21427:
    v_21473 = lisp_true;
    goto v_21426;
v_21428:
    goto v_21438;
v_21434:
    v_21473 = stack[0];
    v_21474 = qcar(v_21473);
    goto v_21435;
v_21436:
    v_21473 = elt(env, 1); // subfunc
    goto v_21437;
v_21438:
    goto v_21434;
v_21435:
    goto v_21436;
v_21437:
    v_21473 = get(v_21474, v_21473);
    env = stack[-4];
    goto v_21426;
    v_21473 = nil;
v_21426:
    if (v_21473 == nil) goto v_21424;
    goto v_21447;
v_21443:
    v_21474 = stack[-3];
    goto v_21444;
v_21445:
    v_21473 = stack[0];
    goto v_21446;
v_21447:
    goto v_21443;
v_21444:
    goto v_21445;
v_21446:
    {
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_21474, v_21473);
    }
v_21424:
    goto v_21457;
v_21453:
    goto v_21465;
v_21459:
    v_21475 = stack[-2];
    goto v_21460;
v_21461:
    v_21474 = stack[-1];
    goto v_21462;
v_21463:
    v_21473 = stack[0];
    v_21473 = qcar(v_21473);
    goto v_21464;
v_21465:
    goto v_21459;
v_21460:
    goto v_21461;
v_21462:
    goto v_21463;
v_21464:
    v_21474 = CC_subcare(elt(env, 0), 3, v_21475, v_21474, v_21473);
    env = stack[-4];
    goto v_21454;
v_21455:
    v_21473 = stack[-3];
    goto v_21456;
v_21457:
    goto v_21453;
v_21454:
    goto v_21455;
v_21456:
    v_21473 = cons(v_21474, v_21473);
    env = stack[-4];
    stack[-3] = v_21473;
    v_21473 = stack[0];
    v_21473 = qcdr(v_21473);
    stack[0] = v_21473;
    goto v_21398;
    v_21473 = nil;
    return onevalue(v_21473);
}



// Code for fs!:make!-nullangle

static LispObject CC_fsTmakeKnullangle(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21430, v_21431, v_21432;
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
    v_21430 = (LispObject)112+TAG_FIXNUM; // 7
    v_21430 = Lmkvect(nil, v_21430);
    env = stack[-2];
    stack[-1] = v_21430;
    v_21430 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_21430;
v_21401:
    goto v_21413;
v_21409:
    v_21431 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_21410;
v_21411:
    v_21430 = stack[0];
    goto v_21412;
v_21413:
    goto v_21409;
v_21410:
    goto v_21411;
v_21412:
    v_21430 = difference2(v_21431, v_21430);
    env = stack[-2];
    v_21430 = Lminusp(nil, v_21430);
    env = stack[-2];
    if (v_21430 == nil) goto v_21406;
    goto v_21400;
v_21406:
    goto v_21423;
v_21417:
    v_21432 = stack[-1];
    goto v_21418;
v_21419:
    v_21431 = stack[0];
    goto v_21420;
v_21421:
    v_21430 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21422;
v_21423:
    goto v_21417;
v_21418:
    goto v_21419;
v_21420:
    goto v_21421;
v_21422:
    *(LispObject *)((char *)v_21432 + (CELL-TAG_VECTOR) + (((intptr_t)v_21431-TAG_FIXNUM)/(16/CELL))) = v_21430;
    v_21430 = stack[0];
    v_21430 = add1(v_21430);
    env = stack[-2];
    stack[0] = v_21430;
    goto v_21401;
v_21400:
    v_21430 = stack[-1];
    return onevalue(v_21430);
}



// Code for dp_from_ei

static LispObject CC_dp_from_ei(LispObject env,
                         LispObject v_21391)
{
    env = qenv(env);
    LispObject v_21404;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21391);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_21391;
// end of prologue
    goto v_21399;
v_21395:
    v_21404 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 1); // cali_bc_fi
    stack[-1] = (*qfn1(fn))(fn, v_21404);
    env = stack[-2];
    goto v_21396;
v_21397:
    v_21404 = stack[0];
    fn = elt(env, 2); // mo_from_ei
    v_21404 = (*qfn1(fn))(fn, v_21404);
    env = stack[-2];
    goto v_21398;
v_21399:
    goto v_21395;
v_21396:
    goto v_21397;
v_21398:
    fn = elt(env, 3); // dp_term
    v_21404 = (*qfn2(fn))(fn, stack[-1], v_21404);
    return ncons(v_21404);
}



// Code for giplus!:

static LispObject CC_giplusT(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21424, v_21425;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21392;
    stack[-1] = v_21391;
// end of prologue
    goto v_21399;
v_21395:
    goto v_21405;
v_21401:
    v_21424 = stack[-1];
    v_21424 = qcdr(v_21424);
    v_21425 = qcar(v_21424);
    goto v_21402;
v_21403:
    v_21424 = stack[0];
    v_21424 = qcdr(v_21424);
    v_21424 = qcar(v_21424);
    goto v_21404;
v_21405:
    goto v_21401;
v_21402:
    goto v_21403;
v_21404:
    stack[-2] = plus2(v_21425, v_21424);
    env = stack[-3];
    goto v_21396;
v_21397:
    goto v_21417;
v_21413:
    v_21424 = stack[-1];
    v_21424 = qcdr(v_21424);
    v_21425 = qcdr(v_21424);
    goto v_21414;
v_21415:
    v_21424 = stack[0];
    v_21424 = qcdr(v_21424);
    v_21424 = qcdr(v_21424);
    goto v_21416;
v_21417:
    goto v_21413;
v_21414:
    goto v_21415;
v_21416:
    v_21424 = plus2(v_21425, v_21424);
    env = stack[-3];
    goto v_21398;
v_21399:
    goto v_21395;
v_21396:
    goto v_21397;
v_21398:
    {
        LispObject v_21429 = stack[-2];
        fn = elt(env, 1); // mkgi
        return (*qfn2(fn))(fn, v_21429, v_21424);
    }
}



// Code for ofsf_sippsubst1

static LispObject CC_ofsf_sippsubst1(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21424, v_21425, v_21426;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21425 = v_21392;
    v_21426 = v_21391;
// end of prologue
    goto v_21401;
v_21395:
    v_21424 = v_21426;
    if (!consp(v_21424)) goto v_21404;
    else goto v_21405;
v_21404:
    v_21424 = v_21426;
    stack[0] = v_21424;
    goto v_21403;
v_21405:
    v_21424 = v_21426;
    v_21424 = qcar(v_21424);
    stack[0] = v_21424;
    goto v_21403;
    stack[0] = nil;
v_21403:
    goto v_21396;
v_21397:
    goto v_21417;
v_21413:
    v_21424 = v_21426;
    v_21424 = qcdr(v_21424);
    v_21424 = qcar(v_21424);
    goto v_21414;
v_21415:
    goto v_21416;
v_21417:
    goto v_21413;
v_21414:
    goto v_21415;
v_21416:
    fn = elt(env, 1); // ofsf_siatsubf
    v_21424 = (*qfn2(fn))(fn, v_21424, v_21425);
    v_21425 = qcar(v_21424);
    goto v_21398;
v_21399:
    v_21424 = nil;
    goto v_21400;
v_21401:
    goto v_21395;
v_21396:
    goto v_21397;
v_21398:
    goto v_21399;
v_21400:
    {
        LispObject v_21428 = stack[0];
        return list3(v_21428, v_21425, v_21424);
    }
}



// Code for rl_convertarg

static LispObject CC_rl_convertarg(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21411, v_21412;
    LispObject fn;
    LispObject v_21393, v_21392, v_21391;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "rl_convertarg");
    va_start(aa, nargs);
    v_21391 = va_arg(aa, LispObject);
    v_21392 = va_arg(aa, LispObject);
    v_21393 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21393,v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21391,v_21392,v_21393);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_21411 = v_21393;
    v_21412 = v_21392;
    stack[0] = v_21391;
// end of prologue
    goto v_21400;
v_21396:
    goto v_21406;
v_21402:
    goto v_21403;
v_21404:
    goto v_21405;
v_21406:
    goto v_21402;
v_21403:
    goto v_21404;
v_21405:
    fn = elt(env, 1); // rl_conversionfunction
    stack[-1] = (*qfn2(fn))(fn, v_21412, v_21411);
    env = stack[-2];
    goto v_21397;
v_21398:
    v_21411 = stack[0];
    v_21411 = ncons(v_21411);
    env = stack[-2];
    goto v_21399;
v_21400:
    goto v_21396;
v_21397:
    goto v_21398;
v_21399:
    {
        LispObject v_21415 = stack[-1];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_21415, v_21411);
    }
}



// Code for repr_n

static LispObject CC_repr_n(LispObject env,
                         LispObject v_21391)
{
    env = qenv(env);
    LispObject v_21427, v_21428, v_21429;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_21391);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_21428 = v_21391;
// end of prologue
    v_21427 = v_21428;
    v_21427 = qcdr(v_21427);
    v_21427 = qcdr(v_21427);
    v_21427 = qcar(v_21427);
    if (v_21427 == nil) goto v_21395;
    else goto v_21396;
v_21395:
    v_21427 = elt(env, 1); // "repr_n : invalid REPR structure"
    v_21427 = ncons(v_21427);
    env = stack[0];
    {
        fn = elt(env, 2); // rederr
        return (*qfn1(fn))(fn, v_21427);
    }
v_21396:
    goto v_21410;
v_21406:
    v_21427 = v_21428;
    v_21427 = qcdr(v_21427);
    v_21427 = qcdr(v_21427);
    v_21427 = qcdr(v_21427);
    v_21427 = qcdr(v_21427);
    v_21429 = qcar(v_21427);
    goto v_21407;
v_21408:
    v_21427 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21409;
v_21410:
    goto v_21406;
v_21407:
    goto v_21408;
v_21409:
    if (v_21429 == v_21427) goto v_21404;
    else goto v_21405;
v_21404:
    v_21427 = nil;
    goto v_21394;
v_21405:
    v_21427 = v_21428;
    v_21427 = qcdr(v_21427);
    v_21427 = qcdr(v_21427);
    v_21427 = qcar(v_21427);
    v_21427 = qcar(v_21427);
    v_21427 = qcar(v_21427);
    goto v_21394;
    v_21427 = nil;
v_21394:
    return onevalue(v_21427);
}



// Code for setrd

static LispObject CC_setrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21417, v_21418;
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
    goto v_21402;
v_21398:
    v_21418 = qvalue(elt(env, 2)); // atts
    goto v_21399;
v_21400:
    v_21417 = elt(env, 3); // (type)
    goto v_21401;
v_21402:
    goto v_21398;
v_21399:
    goto v_21400;
v_21401:
    fn = elt(env, 5); // retattributes
    v_21417 = (*qfn2(fn))(fn, v_21418, v_21417);
    env = stack[-2];
    goto v_21412;
v_21406:
    stack[-1] = elt(env, 4); // set
    goto v_21407;
v_21408:
    stack[0] = v_21417;
    goto v_21409;
v_21410:
    fn = elt(env, 6); // stats_getargs
    v_21417 = (*qfnn(fn))(fn, 0);
    goto v_21411;
v_21412:
    goto v_21406;
v_21407:
    goto v_21408;
v_21409:
    goto v_21410;
v_21411:
    {
        LispObject v_21421 = stack[-1];
        LispObject v_21422 = stack[0];
        return list2star(v_21421, v_21422, v_21417);
    }
    return onevalue(v_21417);
}



// Code for valuecoefft

static LispObject CC_valuecoefft(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21438, v_21439, v_21440, v_21441, v_21442;
    LispObject fn;
    LispObject v_21393, v_21392, v_21391;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "valuecoefft");
    va_start(aa, nargs);
    v_21391 = va_arg(aa, LispObject);
    v_21392 = va_arg(aa, LispObject);
    v_21393 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_21440 = v_21393;
    v_21441 = v_21392;
    v_21442 = v_21391;
// end of prologue
v_21397:
    v_21438 = v_21440;
    if (v_21438 == nil) goto v_21400;
    else goto v_21401;
v_21400:
    v_21438 = elt(env, 1); // "Valuecoefft - no value"
    {
        fn = elt(env, 2); // interr
        return (*qfn1(fn))(fn, v_21438);
    }
v_21401:
    goto v_21411;
v_21407:
    v_21439 = v_21442;
    goto v_21408;
v_21409:
    v_21438 = v_21440;
    v_21438 = qcar(v_21438);
    goto v_21410;
v_21411:
    goto v_21407;
v_21408:
    goto v_21409;
v_21410:
    if (v_21439 == v_21438) goto v_21405;
    else goto v_21406;
v_21405:
    goto v_21423;
v_21419:
    v_21438 = v_21441;
    v_21439 = qcar(v_21438);
    goto v_21420;
v_21421:
    v_21438 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_21422;
v_21423:
    goto v_21419;
v_21420:
    goto v_21421;
v_21422:
    if (v_21439 == v_21438) goto v_21417;
    else goto v_21418;
v_21417:
    v_21438 = nil;
    goto v_21396;
v_21418:
    v_21438 = v_21441;
    v_21438 = qcar(v_21438);
    goto v_21396;
    goto v_21399;
v_21406:
    v_21438 = v_21441;
    v_21438 = qcdr(v_21438);
    v_21441 = v_21438;
    v_21438 = v_21440;
    v_21438 = qcdr(v_21438);
    v_21440 = v_21438;
    goto v_21397;
v_21399:
    v_21438 = nil;
v_21396:
    return onevalue(v_21438);
}



// Code for gbfplus

static LispObject CC_gbfplus(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21420, v_21421;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21392;
    stack[-1] = v_21391;
// end of prologue
    goto v_21399;
v_21395:
    goto v_21405;
v_21401:
    v_21420 = stack[-1];
    v_21421 = qcar(v_21420);
    goto v_21402;
v_21403:
    v_21420 = stack[0];
    v_21420 = qcar(v_21420);
    goto v_21404;
v_21405:
    goto v_21401;
v_21402:
    goto v_21403;
v_21404:
    fn = elt(env, 1); // plubf
    stack[-2] = (*qfn2(fn))(fn, v_21421, v_21420);
    env = stack[-3];
    goto v_21396;
v_21397:
    goto v_21415;
v_21411:
    v_21420 = stack[-1];
    v_21421 = qcdr(v_21420);
    goto v_21412;
v_21413:
    v_21420 = stack[0];
    v_21420 = qcdr(v_21420);
    goto v_21414;
v_21415:
    goto v_21411;
v_21412:
    goto v_21413;
v_21414:
    fn = elt(env, 1); // plubf
    v_21420 = (*qfn2(fn))(fn, v_21421, v_21420);
    goto v_21398;
v_21399:
    goto v_21395;
v_21396:
    goto v_21397;
v_21398:
    {
        LispObject v_21425 = stack[-2];
        return cons(v_21425, v_21420);
    }
}



// Code for r2findindex1

static LispObject CC_r2findindex1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21422, v_21423, v_21424;
    LispObject fn;
    LispObject v_21393, v_21392, v_21391;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "r2findindex1");
    va_start(aa, nargs);
    v_21391 = va_arg(aa, LispObject);
    v_21392 = va_arg(aa, LispObject);
    v_21393 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21393,v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21391,v_21392,v_21393);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_21423 = v_21393;
    stack[0] = v_21392;
    stack[-1] = v_21391;
// end of prologue
v_21397:
    v_21422 = stack[0];
    if (v_21422 == nil) goto v_21400;
    else goto v_21401;
v_21400:
    v_21422 = elt(env, 1); // "index not found"
    {
        fn = elt(env, 2); // rederr
        return (*qfn1(fn))(fn, v_21422);
    }
v_21401:
    goto v_21411;
v_21407:
    v_21424 = stack[-1];
    goto v_21408;
v_21409:
    v_21422 = stack[0];
    v_21422 = qcar(v_21422);
    goto v_21410;
v_21411:
    goto v_21407;
v_21408:
    goto v_21409;
v_21410:
    if (equal(v_21424, v_21422)) goto v_21405;
    else goto v_21406;
v_21405:
    v_21422 = v_21423;
    goto v_21396;
v_21406:
    v_21422 = stack[0];
    v_21422 = qcdr(v_21422);
    stack[0] = v_21422;
    v_21422 = v_21423;
    v_21422 = add1(v_21422);
    env = stack[-2];
    v_21423 = v_21422;
    goto v_21397;
    v_21422 = nil;
v_21396:
    return onevalue(v_21422);
}



// Code for intrdsortin

static LispObject CC_intrdsortin(LispObject env,
                         LispObject v_21391, LispObject v_21392)
{
    env = qenv(env);
    LispObject v_21458, v_21459;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_21391,v_21392);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_21392;
    stack[-1] = v_21391;
// end of prologue
    stack[-2] = nil;
v_21397:
    v_21458 = stack[0];
    if (v_21458 == nil) goto v_21400;
    else goto v_21401;
v_21400:
    goto v_21408;
v_21404:
    stack[0] = stack[-2];
    goto v_21405;
v_21406:
    v_21458 = stack[-1];
    v_21458 = ncons(v_21458);
    env = stack[-3];
    goto v_21407;
v_21408:
    goto v_21404;
v_21405:
    goto v_21406;
v_21407:
    {
        LispObject v_21463 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_21463, v_21458);
    }
v_21401:
    v_21458 = stack[-1];
    v_21459 = qcar(v_21458);
    v_21458 = stack[0];
    v_21458 = qcar(v_21458);
    v_21458 = qcar(v_21458);
    goto v_21427;
v_21423:
    goto v_21424;
v_21425:
    goto v_21426;
v_21427:
    goto v_21423;
v_21424:
    goto v_21425;
v_21426:
    fn = elt(env, 2); // !:difference
    v_21458 = (*qfn2(fn))(fn, v_21459, v_21458);
    env = stack[-3];
    fn = elt(env, 3); // !:minusp
    v_21458 = (*qfn1(fn))(fn, v_21458);
    env = stack[-3];
    if (v_21458 == nil) goto v_21413;
    goto v_21435;
v_21431:
    v_21458 = stack[0];
    v_21459 = qcar(v_21458);
    goto v_21432;
v_21433:
    v_21458 = stack[-2];
    goto v_21434;
v_21435:
    goto v_21431;
v_21432:
    goto v_21433;
v_21434:
    v_21458 = cons(v_21459, v_21458);
    env = stack[-3];
    stack[-2] = v_21458;
    v_21458 = stack[0];
    v_21458 = qcdr(v_21458);
    stack[0] = v_21458;
    goto v_21397;
v_21413:
    goto v_21448;
v_21444:
    goto v_21445;
v_21446:
    goto v_21455;
v_21451:
    v_21459 = stack[-1];
    goto v_21452;
v_21453:
    v_21458 = stack[0];
    goto v_21454;
v_21455:
    goto v_21451;
v_21452:
    goto v_21453;
v_21454:
    v_21458 = cons(v_21459, v_21458);
    env = stack[-3];
    goto v_21447;
v_21448:
    goto v_21444;
v_21445:
    goto v_21446;
v_21447:
    {
        LispObject v_21464 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_21464, v_21458);
    }
    v_21458 = nil;
    return onevalue(v_21458);
}



// Code for contr2

static LispObject CC_contr2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_21457, v_21458;
    LispObject fn;
    LispObject v_21393, v_21392, v_21391;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "contr2");
    va_start(aa, nargs);
    v_21391 = va_arg(aa, LispObject);
    v_21392 = va_arg(aa, LispObject);
    v_21393 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_21393,v_21392,v_21391);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_21391,v_21392,v_21393);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_21393;
    stack[-1] = v_21392;
    stack[-2] = v_21391;
// end of prologue
    stack[-3] = nil;
v_21398:
    v_21457 = stack[-1];
    if (v_21457 == nil) goto v_21401;
    else goto v_21402;
v_21401:
    goto v_21409;
v_21405:
    stack[-1] = stack[-3];
    goto v_21406;
v_21407:
    goto v_21416;
v_21412:
    v_21458 = stack[-2];
    goto v_21413;
v_21414:
    v_21457 = stack[0];
    goto v_21415;
v_21416:
    goto v_21412;
v_21413:
    goto v_21414;
v_21415:
    fn = elt(env, 1); // contr
    v_21457 = (*qfn2(fn))(fn, v_21458, v_21457);
    env = stack[-4];
    goto v_21408;
v_21409:
    goto v_21405;
v_21406:
    goto v_21407;
v_21408:
    {
        LispObject v_21463 = stack[-1];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_21463, v_21457);
    }
v_21402:
    v_21457 = stack[0];
    if (v_21457 == nil) goto v_21419;
    else goto v_21420;
v_21419:
    goto v_21427;
v_21423:
    stack[0] = stack[-3];
    goto v_21424;
v_21425:
    goto v_21434;
v_21430:
    v_21458 = stack[-2];
    goto v_21431;
v_21432:
    v_21457 = stack[-1];
    goto v_21433;
v_21434:
    goto v_21430;
v_21431:
    goto v_21432;
v_21433:
    fn = elt(env, 1); // contr
    v_21457 = (*qfn2(fn))(fn, v_21458, v_21457);
    env = stack[-4];
    goto v_21426;
v_21427:
    goto v_21423;
v_21424:
    goto v_21425;
v_21426:
    {
        LispObject v_21464 = stack[0];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_21464, v_21457);
    }
v_21420:
    goto v_21444;
v_21440:
    goto v_21450;
v_21446:
    v_21458 = stack[-2];
    goto v_21447;
v_21448:
    v_21457 = stack[-1];
    v_21457 = qcar(v_21457);
    goto v_21449;
v_21450:
    goto v_21446;
v_21447:
    goto v_21448;
v_21449:
    fn = elt(env, 3); // split!-road
    v_21458 = (*qfn2(fn))(fn, v_21458, v_21457);
    env = stack[-4];
    goto v_21441;
v_21442:
    v_21457 = stack[-3];
    goto v_21443;
v_21444:
    goto v_21440;
v_21441:
    goto v_21442;
v_21443:
    v_21457 = cons(v_21458, v_21457);
    env = stack[-4];
    stack[-3] = v_21457;
    v_21457 = stack[-1];
    v_21457 = qcdr(v_21457);
    stack[-1] = v_21457;
    goto v_21398;
    v_21457 = nil;
    return onevalue(v_21457);
}



setup_type const u38_setup[] =
{
    {"talp_specsub",            TOO_FEW_2,      CC_talp_specsub,WRONG_NO_2},
    {"ithlistelem",             TOO_FEW_2,      CC_ithlistelem,WRONG_NO_2},
    {"sparpri",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_sparpri},
    {"evalb",                   CC_evalb,       TOO_MANY_1,    WRONG_NO_1},
    {"min0",                    TOO_FEW_2,      CC_min0,       WRONG_NO_2},
    {"physoptimes",             CC_physoptimes, TOO_MANY_1,    WRONG_NO_1},
    {"deletez1",                TOO_FEW_2,      CC_deletez1,   WRONG_NO_2},
    {"assert_procstat-argl",    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_assert_procstatKargl},
    {"remchkf1",                TOO_FEW_2,      CC_remchkf1,   WRONG_NO_2},
    {"gvar1",                   TOO_FEW_2,      CC_gvar1,      WRONG_NO_2},
    {"lalr_print_first_information",WRONG_NO_NA,WRONG_NO_NB,   (n_args *)CC_lalr_print_first_information},
    {"give*position",           TOO_FEW_2,      CC_giveHposition,WRONG_NO_2},
    {"cl_pnf2",                 CC_cl_pnf2,     TOO_MANY_1,    WRONG_NO_1},
    {"getargsrd",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_getargsrd},
    {"close_forall",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_close_forall},
    {"degreef",                 TOO_FEW_2,      CC_degreef,    WRONG_NO_2},
    {"matrixp",                 CC_matrixp,     TOO_MANY_1,    WRONG_NO_1},
    {"sc_mkmatrix",             TOO_FEW_2,      CC_sc_mkmatrix,WRONG_NO_2},
    {"string2bytelist",         CC_string2bytelist,TOO_MANY_1, WRONG_NO_1},
    {"gftimes",                 TOO_FEW_2,      CC_gftimes,    WRONG_NO_2},
    {"sublap",                  TOO_FEW_2,      CC_sublap,     WRONG_NO_2},
    {"**a2i",                   TOO_FEW_2,      CC_HHa2i,      WRONG_NO_2},
    {"drnconv",                 CC_drnconv,     TOO_MANY_1,    WRONG_NO_1},
    {"rl_fvarl",                CC_rl_fvarl,    TOO_MANY_1,    WRONG_NO_1},
    {"taydegree<",              TOO_FEW_2,      CC_taydegreeR, WRONG_NO_2},
    {"internal-factorf",        CC_internalKfactorf,TOO_MANY_1,WRONG_NO_1},
    {"symbolsom",               CC_symbolsom,   TOO_MANY_1,    WRONG_NO_1},
    {"contposp",                CC_contposp,    TOO_MANY_1,    WRONG_NO_1},
    {"exdff0",                  CC_exdff0,      TOO_MANY_1,    WRONG_NO_1},
    {"::quotient",              TOO_FEW_2,      CC_TTquotient, WRONG_NO_2},
    {"getphystypeall",          CC_getphystypeall,TOO_MANY_1,  WRONG_NO_1},
    {"evalgreaterp",            TOO_FEW_2,      CC_evalgreaterp,WRONG_NO_2},
    {"bas_make",                TOO_FEW_2,      CC_bas_make,   WRONG_NO_2},
    {"split-further",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_splitKfurther},
    {"ext_mult",                TOO_FEW_2,      CC_ext_mult,   WRONG_NO_2},
    {"multivariatep",           TOO_FEW_2,      CC_multivariatep,WRONG_NO_2},
    {"lex_init",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex_init},
    {"rl_qefsolset",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rl_qefsolset},
    {"even_action_sf",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_even_action_sf},
    {"talp_maxd",               CC_talp_maxd,   TOO_MANY_1,    WRONG_NO_1},
    {"rl_bnfsimpl",             TOO_FEW_2,      CC_rl_bnfsimpl,WRONG_NO_2},
    {"sfto_b:extadd",           TOO_FEW_2,      CC_sfto_bTextadd,WRONG_NO_2},
    {"ciml",                    CC_ciml,        TOO_MANY_1,    WRONG_NO_1},
    {"groebinvokecritm",        TOO_FEW_2,      CC_groebinvokecritm,WRONG_NO_2},
    {"collectphysops_reversed", TOO_FEW_2,      CC_collectphysops_reversed,WRONG_NO_2},
    {"subcare",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_subcare},
    {"fs:make-nullangle",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_fsTmakeKnullangle},
    {"dp_from_ei",              CC_dp_from_ei,  TOO_MANY_1,    WRONG_NO_1},
    {"giplus:",                 TOO_FEW_2,      CC_giplusT,    WRONG_NO_2},
    {"ofsf_sippsubst1",         TOO_FEW_2,      CC_ofsf_sippsubst1,WRONG_NO_2},
    {"rl_convertarg",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rl_convertarg},
    {"repr_n",                  CC_repr_n,      TOO_MANY_1,    WRONG_NO_1},
    {"setrd",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setrd},
    {"valuecoefft",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_valuecoefft},
    {"gbfplus",                 TOO_FEW_2,      CC_gbfplus,    WRONG_NO_2},
    {"r2findindex1",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_r2findindex1},
    {"intrdsortin",             TOO_FEW_2,      CC_intrdsortin,WRONG_NO_2},
    {"contr2",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_contr2},
    {NULL, (one_args *)"u38", (two_args *)"5909 8674530 6840317", 0}
};

// end of generated code
