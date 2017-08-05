
// $destdir/u52.c        Machine generated C code

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
#ifndef NDEBUG
#define NDEBUG 1
#endif
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
typedef intptr_t LispObject;
#define SIXTY_FOUR_BIT (sizeof(intptr_t) == 8)
static inline void CSL_IGNORE(LispObject x)
{ (void)x;
}
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
static inline bool is_cons(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_CONS);
}
static inline bool is_fixnum(LispObject p)
{ return ((((int)(p)) & XTAG_BITS) == TAG_FIXNUM);
}
static inline bool is_odds(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_HDR_IMMED); 
}
static inline bool is_sfloat(LispObject p)
{ return ((((int)(p)) & XTAG_BITS) == XTAG_SFLOAT);
}
static inline bool is_symbol(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_SYMBOL);
}
static inline bool is_numbers(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_NUMBERS);
}
static inline bool is_vector(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_VECTOR);
}
static inline bool is_bfloat(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT);
}
static inline bool consp(LispObject p)
{ return is_cons(p);
}
static inline bool symbolp(LispObject p)
{ return is_symbol(p);
}
static inline bool car_legal(LispObject p)
{ return is_cons(p);
}
typedef struct Cons_Cell
{ LispObject car;
 LispObject cdr;
} Cons_Cell;
static inline LispObject& qcar(LispObject p)
{ return ((Cons_Cell *)p)->car;
}
static inline LispObject& qcdr(LispObject p)
{ return ((Cons_Cell *)p)->cdr;
}
static inline LispObject& qcar(char * p)
{ return ((Cons_Cell *)p)->car;
}
static inline LispObject& qcdr(char * p)
{ return ((Cons_Cell *)p)->cdr;
}
static inline int32_t& car32(LispObject p)
{ return ((int32_t *)p)[0];
}
static inline int32_t& cdr32(LispObject p)
{ return ((int32_t *)p)[1];
}
static inline int32_t& car32(char * p)
{ return ((int32_t *)p)[0];
}
static inline int32_t& cdr32(char * p)
{ return ((int32_t *)p)[1];
}
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
static Header& vechdr(LispObject v)
{ return *(Header *)((char *)(v) - TAG_VECTOR);
}
static inline unsigned int type_of_header(Header h)
{ return ((unsigned int)h) & header_mask;
}
static inline size_t length_of_header(Header h)
{ return (((size_t)h) >> (Tw+7)) << 2;
}
static inline size_t length_of_bitheader(Header h)
{ return (((size_t)h) >> (Tw+2)) - 31;
}
static inline size_t length_of_byteheader(Header h)
{ return (((size_t)h) >> (Tw+5)) - 3;
}
static inline size_t length_of_hwordheader(Header h)
{ return (((size_t)h) >> (Tw+6)) - 1;
}
static inline Header bitvechdr_(size_t n)
{ return TYPE_BITVEC_1 + (((n+31)&31)<<(Tw+2));
}
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
static inline bool is_symbol_header(Header h)
{ return ((int)h & (0xf<<Tw)) == TYPE_SYMBOL;
}
static inline bool is_symbol_header_full_test(Header h)
{ return ((int)h & ((0xf<<Tw) + TAG_BITS)) == (TYPE_SYMBOL + TAG_HDR_IMMED);
}
static inline int header_fastget(Header h)
{ return (h >> SYM_FASTGET_SHIFT) & 0x3f;
}
static inline bool is_number_header_full_test(Header h)
{ return ((int)h & ((0x1d<<Tw) + TAG_BITS)) == ((0x1d<<Tw) + TAG_HDR_IMMED);
}
static inline bool is_vector_header_full_test(Header h)
{ return is_odds(h) && (((int)h & (0x3<<Tw)) != 0);
}
static inline bool is_array_header(Header h)
{ return type_of_header(h) == TYPE_ARRAY;
}
static inline bool vector_i8(Header h)
{ return ((0x7f070707u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
static inline bool vector_i16(Header h)
{ return ((0x00080008u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
static inline bool vector_i32(Header h)
{ return ((0x00000090u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
static inline bool vector_i64(Header h)
{ return ((0x00007820u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
static inline bool vector_i128(Header h)
{ return ((0x00000040u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
static inline bool vector_f32(Header h)
{ return ((0x00108000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
static inline bool vector_f64(Header h)
{ return ((0x00a00000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
static inline bool vector_f128(Header h)
{ return ((0x80400000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
#define TYPE_BIGNUM ( 0x1f <<Tw)
#define TYPE_RATNUM ( 0x1d <<Tw)
#define TYPE_COMPLEX_NUM ( 0x3d <<Tw)
#define TYPE_SINGLE_FLOAT ( 0x3f <<Tw)
#define TYPE_DOUBLE_FLOAT ( 0x5f <<Tw)
#define TYPE_LONG_FLOAT ( 0x7f <<Tw)
static inline Header& numhdr(LispObject v)
{ return *(Header *)((char *)(v) - TAG_NUMBERS);
}
static inline Header& flthdr(LispObject v)
{ return *(Header *)((char *)(v) - TAG_BOXFLOAT);
}
static inline bool is_ratio(LispObject n)
{ return type_of_header(numhdr(n)) == TYPE_RATNUM;
}
static inline bool is_complex(LispObject n)
{ return type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM;
}
static inline bool is_bignum_header(Header h)
{ return type_of_header(h) == TYPE_BIGNUM;
}
static inline bool is_bignum(LispObject n)
{ return is_bignum_header(numhdr(n));
}
static inline bool is_string_header(Header h)
{ return (type_of_header(h) & (0x1f<<Tw)) == TYPE_STRING_1;
}
static inline bool is_string(LispObject n)
{ return is_string_header(vechdr(n));
}
static inline bool is_vec8_header(Header h)
{ return (type_of_header(h) & (0x1f<<Tw)) == TYPE_VEC8_1;
}
static inline bool is_vec8(LispObject n)
{ return is_vec8_header(vechdr(n));
}
static inline bool is_bps_header(Header h)
{ return (type_of_header(h) & (0x1f<<Tw)) == TYPE_BPS_1;
}
static inline bool is_bps(LispObject n)
{ return is_bps_header(vechdr(n));
}
static inline bool is_vec16_header(Header h)
{ return (type_of_header(h) & (0x3f<<Tw)) == TYPE_VEC16_1;
}
static inline bool is_vec16(LispObject n)
{ return is_vec16_header(vechdr(n));
}
static inline bool is_bitvec_header(Header h)
{ return (type_of_header(h) & (0x03<<Tw)) == TYPE_BITVEC_1;
}
static inline bool is_bitvec(LispObject n)
{ return is_bitvec_header(vechdr(n));
}
static inline LispObject& elt(LispObject v, size_t n)
{ return *(LispObject *)((char *)v +
 (CELL-TAG_VECTOR) +
 (n*sizeof(LispObject)));
}
static inline char& celt(LispObject v, size_t n)
{ return *((char *)(v) + (CELL-TAG_VECTOR) + n);
}
static inline unsigned char& ucelt(LispObject v, size_t n)
{ return *((unsigned char *)v + (CELL-TAG_VECTOR) + n);
}
static inline signed char& scelt(LispObject v, size_t n)
{ return *((signed char *)v + (CELL-TAG_VECTOR) + n);
}
#define BPS_DATA_OFFSET (CELL-TAG_VECTOR)
static inline unsigned char* data_of_bps(LispObject v)
{ return (unsigned char *)v + BPS_DATA_OFFSET;
}
static inline LispObject& vselt(LispObject v, size_t n)
{ return *(LispObject *)(((intptr_t)v & ~((intptr_t)TAG_BITS)) +
 ((1 + n)*sizeof(LispObject)));
}
static inline int16_t& helt(LispObject v, size_t n)
{ return *(int16_t *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(int16_t));
}
static inline intptr_t& ielt(LispObject v, size_t n)
{ return *(intptr_t *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(intptr_t));
}
static inline int32_t& ielt32(LispObject v, size_t n)
{ return *(int32_t *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(int32_t));
}
static inline float& felt(LispObject v, size_t n)
{ return *(float *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(float));
}
static inline double& delt(LispObject v, size_t n)
{ return *(double *)((char *)v +
 (8-TAG_VECTOR) +
 n*sizeof(double));
}
static inline bool is_header(LispObject x)
{ return ((int)x & (0x3<<Tw)) != 0; 
}
static inline bool is_char(LispObject x)
{ return ((int)x & HDR_IMMED_MASK) == TAG_CHAR;
}
static inline bool is_spid(LispObject x)
{ return ((int)x & HDR_IMMED_MASK) == TAG_SPID;
}
static inline bool is_library(LispObject x)
{ return ((int)x & 0xfffff) == SPID_LIBRARY;
}
static inline unsigned int library_number(LispObject x)
{ return (x >> 20) & 0xfff;
}
static inline int font_of_char(LispObject n)
{ return ((int32_t)n >> (21+4+Tw)) & 0xf;
}
static inline int bits_of_char(LispObject n)
{ return 0;
}
static inline unsigned int code_of_char(LispObject n)
{ return ((uint32_t)(n) >> (4+Tw)) & 0x001fffff;
}
static inline LispObject pack_char(int font, unsigned int code)
{ return (LispObject)((((uint32_t)(font)) << (21+4+Tw)) |
 (((uint32_t)(code)) << (4+Tw)) | TAG_CHAR);
}
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
static inline Header& qheader(LispObject p)
{ return *(Header *)((char *)p + (0*CELL-TAG_SYMBOL));
}
static inline LispObject& qvalue(LispObject p)
{ return *(LispObject *)((char *)p + (1*CELL-TAG_SYMBOL));
}
static inline LispObject& qenv(LispObject p)
{ return *(LispObject *)((char *)p + (2*CELL-TAG_SYMBOL));
}
static inline LispObject& qplist(LispObject p)
{ return *(LispObject *)((char *)p + (3*CELL-TAG_SYMBOL));
}
static inline LispObject& qfastgets(LispObject p)
{ return *(LispObject *)((char *)p + (4*CELL-TAG_SYMBOL));
}
static inline LispObject& qpackage(LispObject p)
{ return *(LispObject *)((char *)p + (5*CELL-TAG_SYMBOL));
}
static inline LispObject& qpname(LispObject p)
{ return *(LispObject *)((char *)p + (6*CELL-TAG_SYMBOL));
}
static inline intptr_t& ifn0(LispObject p)
{ return *(intptr_t *)((char *)p + (7*CELL-TAG_SYMBOL));
}
static inline intptr_t& ifn1(LispObject p)
{ return *(intptr_t *)((char *)p + (8*CELL-TAG_SYMBOL));
}
static inline intptr_t& ifn2(LispObject p)
{ return *(intptr_t *)((char *)p + (9*CELL-TAG_SYMBOL));
}
static inline intptr_t& ifn3(LispObject p)
{ return *(intptr_t *)((char *)p + (10*CELL-TAG_SYMBOL));
}
static inline intptr_t& ifnn(LispObject p)
{ return *(intptr_t *)((char *)p + (11*CELL-TAG_SYMBOL));
}
static inline intptr_t& ifn4(LispObject p)
{ return *(intptr_t *)((char *)p + (11*CELL-TAG_SYMBOL));
}
static inline no_args*& qfn0(LispObject p)
{ return *(no_args **)((char *)p + (7*CELL-TAG_SYMBOL));
}
static inline one_args*& qfn1(LispObject p)
{ return *(one_args **)((char *)p + (8*CELL-TAG_SYMBOL));
}
static inline two_args*& qfn2(LispObject p)
{ return *(two_args **)((char *)p + (9*CELL-TAG_SYMBOL));
}
static inline three_args*& qfn3(LispObject p)
{ return *(three_args **)((char *)p + (10*CELL-TAG_SYMBOL));
}
static inline n_args*& qfnn(LispObject p)
{ return *(n_args **)((char *)p + (11*CELL-TAG_SYMBOL));
}
static inline four_args*& qfn4(LispObject p)
{ return *(four_args **)((char *)p + (11*CELL-TAG_SYMBOL));
}
static inline uint64_t& qcount(LispObject p)
{ return *(uint64_t *)((char *)p + (12*CELL-TAG_SYMBOL));
}
typedef union _Float_union
{ float f;
 uint32_t i;
 float32_t f32;
} Float_union;
static inline LispObject low32(LispObject a)
{ return (LispObject)(uint32_t)a;
}
typedef struct Big_Number
{
 Header h;
 uint32_t d[1]; 
} Big_Number;
static inline size_t bignum_length(LispObject b)
{ return length_of_header(numhdr(b));
}
static inline uint32_t* bignum_digits(LispObject b)
{ return (uint32_t *)((char *)b + (CELL-TAG_NUMBERS));
}
static inline int64_t bignum_digits64(LispObject b, size_t n)
{ return (int64_t)((int32_t *)((char *)b+(CELL-TAG_NUMBERS)))[n];
}
static inline Header make_bighdr(size_t n)
{ return TAG_HDR_IMMED+TYPE_BIGNUM+(n<<(Tw+7));
}
#define pack_hdrlength(n) (((intptr_t)(n))<<(Tw+7))
#define make_padder(n) (pack_hdrlength((n)/4) + TYPE_VEC8_1 + TAG_HDR_IMMED)
typedef struct Rational_Number
{ Header header;
 LispObject num;
 LispObject den;
} Rational_Number;
static inline LispObject& numerator(LispObject r)
{ return ((Rational_Number *)((char *)r-TAG_NUMBERS))->num;
}
static inline LispObject& denominator(LispObject r)
{ return ((Rational_Number *)((char *)r-TAG_NUMBERS))->den;
}
typedef struct Complex_Number
{ Header header;
 LispObject real;
 LispObject imag;
} Complex_Number;
static inline LispObject& real_part(LispObject r)
{ return ((Complex_Number *)((char *)r-TAG_NUMBERS))->real;
}
static inline LispObject& imag_part(LispObject r)
{ return ((Complex_Number *)((char *)r-TAG_NUMBERS))->imag;
}
typedef struct Single_Float
{ Header header;
 union float_or_int
 { float f;
 float32_t f32;
 int32_t i;
 } f;
} Single_Float;
static inline float& single_float_val(LispObject v)
{ return ((Single_Float *)((char *)v-TAG_BOXFLOAT))->f.f;
}
static inline float32_t& float32_t_val(LispObject v)
{ return ((Single_Float *)((char *)v-TAG_BOXFLOAT))->f.f32;
}
static inline int32_t& intfloat32_t_val(LispObject v)
{ return ((Single_Float *)((char *)v-TAG_BOXFLOAT))->f.i;
}
typedef union _Double_union
{ double f;
 uint32_t i[2];
 uint64_t i64;
 float64_t f64;
} Double_union;
#define SIZEOF_DOUBLE_FLOAT 16
static inline double *double_float_addr(LispObject v)
{ return (double *)((char *)v + (8-TAG_BOXFLOAT));
}
static inline int32_t& double_float_pad(LispObject v)
{ return *(int32_t *)((char *)v + (4-TAG_BOXFLOAT));
}
static inline double& double_float_val(LispObject v)
{ return *(double *)((char *)v + (8-TAG_BOXFLOAT));
}
static inline float64_t& float64_t_val(LispObject v)
{ return *(float64_t *)((char *)v + (8-TAG_BOXFLOAT));
}
static inline int64_t& intfloat64_t_val(LispObject v)
{ return *(int64_t *)((char *)v + (8-TAG_BOXFLOAT));
}
#define SIZEOF_LONG_FLOAT 24
static inline float128_t *long_float_addr(LispObject v)
{ return (float128_t *)((char *)v + (8-TAG_BOXFLOAT));
}
static inline int32_t& long_float_pad(LispObject v)
{ return *(int32_t *)((char *)v + (4-TAG_BOXFLOAT));
}
static inline float128_t& long_float_val(LispObject v)
{ return *(float128_t *)((char *)v + (8-TAG_BOXFLOAT));
}
static inline float128_t& float128_t_val(LispObject v)
{ return *(float128_t *)((char *)v + (8-TAG_BOXFLOAT));
}
static inline int64_t& intfloat128_t_val0(LispObject v)
{ return *(int64_t *)((char *)v + (8-TAG_BOXFLOAT));
}
static inline int64_t& intfloat128_t_val1(LispObject v)
{ return *(int64_t *)((char *)v + (16-TAG_BOXFLOAT));
}
static inline uintptr_t word_align_up(uintptr_t n)
{ return (LispObject)((n + 3) & (-(uintptr_t)4U));
}
static inline uintptr_t doubleword_align_up(uintptr_t n)
{ return (uintptr_t)((n + 7) & (-(uintptr_t)8U));
}
static inline LispObject doubleword_align_up(LispObject n)
{ return (LispObject)(((uintptr_t)n + 7) & (-(uintptr_t)8U));
}
static inline uintptr_t doubleword_align_down(uintptr_t n)
{ return (uintptr_t)((intptr_t)n & (-(uintptr_t)8U));
}
static inline uintptr_t object_align_up(uintptr_t n)
{ return (uintptr_t)((n + sizeof(LispObject) - 1) &
 (-(uintptr_t)sizeof(LispObject)));
}
static inline uintptr_t quadword_align_up(uintptr_t n)
{ return (uintptr_t)((n + 15) & (-(uintptr_t)16U));
}
static inline uintptr_t quadword_align_down(uintptr_t n)
{ return (uintptr_t)(n & (-(uintptr_t)16U));
}
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
static inline void push(LispObject a)
{ *++stack = a;
 assert(a != 0);
}
static inline void push2(LispObject a, LispObject b)
{ *++stack = a;
 assert(a != 0);
 *++stack = b;
 assert(b != 0);
}
static inline void push3(LispObject a, LispObject b, LispObject c)
{ *++stack = a;
 assert(a != 0);
 *++stack = b;
 assert(b != 0);
 *++stack = c;
 assert(c != 0);
}
static inline void push4(LispObject a, LispObject b, LispObject c,
 LispObject d)
{ *++stack = a;
 assert(a != 0);
 *++stack = b;
 assert(b != 0);
 *++stack = c;
 assert(c != 0);
 *++stack = d;
 assert(d != 0);
}
static inline void push5(LispObject a, LispObject b, LispObject c,
 LispObject d, LispObject e)
{ *++stack = a;
 assert(a != 0);
 *++stack = b;
 assert(b != 0);
 *++stack = c;
 assert(c != 0);
 *++stack = d;
 assert(d != 0);
 *++stack = e;
 assert(e != 0);
}
static inline void push6(LispObject a, LispObject b, LispObject c,
 LispObject d, LispObject e, LispObject f)
{ *++stack = a;
 assert(a != 0);
 *++stack = b;
 assert(b != 0);
 *++stack = c;
 assert(c != 0);
 *++stack = d;
 assert(d != 0);
 *++stack = e;
 assert(e != 0);
 *++stack = f;
 assert(f != 0);
}
static inline void pop(LispObject& a)
{ a = *stack--;
 assert(a != 0);
}
static inline void pop(volatile LispObject& a)
{ a = *stack--;
 assert(a != 0);
}
static inline void pop2(LispObject& a, LispObject& b)
{ a = *stack--;
 assert(a != 0);
 b = *stack--;
 assert(b != 0);
}
static inline void pop3(LispObject& a, LispObject& b, LispObject& c)
{ a = *stack--;
 assert(a != 0);
 b = *stack--;
 assert(b != 0);
 c = *stack--;
 assert(c != 0);
}
static inline void pop4(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d)
{ a = *stack--;
 assert(a != 0);
 b = *stack--;
 assert(b != 0);
 c = *stack--;
 assert(c != 0);
 d = *stack--;
 assert(d != 0);
}
static inline void pop5(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d, LispObject& e)
{ a = *stack--;
 assert(a != 0);
 b = *stack--;
 assert(b != 0);
 c = *stack--;
 assert(c != 0);
 d = *stack--;
 assert(d != 0);
 e = *stack--;
 assert(e != 0);
}
static inline void pop6(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d, LispObject& e, LispObject& f)
{ a = *stack--;
 assert(a != 0);
 b = *stack--;
 assert(b != 0);
 c = *stack--;
 assert(c != 0);
 d = *stack--;
 assert(d != 0);
 e = *stack--;
 assert(e != 0);
 f = *stack--;
 assert(f != 0);
}
static inline void popv(int n)
{ stack -= n;
}
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
#define LOG2_VECTOR_CHUNK_BYTES 20
#define VECTOR_CHUNK_BYTES ((size_t)(1<<LOG2_VECTOR_CHUNK_BYTES))
extern LispObject free_vectors[LOG2_VECTOR_CHUNK_BYTES+1];
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
extern LispObject get_basic_vector(int tag, int type, size_t length);
extern LispObject get_basic_vector_init(size_t n, LispObject v);
extern LispObject get_vector(int tag, int type, size_t length);
extern LispObject get_vector_init(size_t n, LispObject v);
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
 { LispObject r = get_basic_vector(TAG_BOXFLOAT,
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



// Code for qqe_simplqequal

static LispObject CC_qqe_simplqequal(LispObject env,
                         LispObject v_31058, LispObject v_31059)
{
    env = qenv(env);
    LispObject v_31452, v_31453, v_31454;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31058,v_31059);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    v_31452 = v_31059;
    stack[0] = v_31058;
// end of prologue
v_31057:
    v_31452 = stack[0];
    fn = elt(env, 5); // qqe_arg2r
    v_31452 = (*qfn1(fn))(fn, v_31452);
    env = stack[-9];
    stack[-7] = v_31452;
    v_31452 = stack[0];
    fn = elt(env, 6); // qqe_arg2l
    v_31452 = (*qfn1(fn))(fn, v_31452);
    env = stack[-9];
    stack[-8] = v_31452;
    goto v_31085;
v_31081:
    v_31453 = stack[-7];
    goto v_31082;
v_31083:
    v_31452 = stack[-8];
    goto v_31084;
v_31085:
    goto v_31081;
v_31082:
    goto v_31083;
v_31084:
    if (equal(v_31453, v_31452)) goto v_31079;
    else goto v_31080;
v_31079:
    v_31452 = elt(env, 1); // true
    goto v_31072;
v_31080:
    v_31452 = stack[-8];
    fn = elt(env, 7); // qqe_qprefix!-var
    v_31452 = (*qfn1(fn))(fn, v_31452);
    env = stack[-9];
    stack[-6] = v_31452;
    v_31452 = stack[-7];
    fn = elt(env, 7); // qqe_qprefix!-var
    v_31452 = (*qfn1(fn))(fn, v_31452);
    env = stack[-9];
    stack[-5] = v_31452;
    goto v_31105;
v_31101:
    v_31453 = stack[-6];
    goto v_31102;
v_31103:
    v_31452 = stack[-5];
    goto v_31104;
v_31105:
    goto v_31101;
v_31102:
    goto v_31103;
v_31104:
    if (v_31453 == v_31452) goto v_31099;
    else goto v_31100;
v_31099:
    v_31452 = lisp_true;
    goto v_31098;
v_31100:
    goto v_31119;
v_31115:
    v_31453 = stack[-6];
    goto v_31116;
v_31117:
    v_31452 = elt(env, 2); // qepsilon
    goto v_31118;
v_31119:
    goto v_31115;
v_31116:
    goto v_31117;
v_31118:
    if (v_31453 == v_31452) goto v_31113;
    else goto v_31114;
v_31113:
    v_31452 = lisp_true;
    goto v_31112;
v_31114:
    goto v_31129;
v_31125:
    v_31453 = stack[-5];
    goto v_31126;
v_31127:
    v_31452 = elt(env, 2); // qepsilon
    goto v_31128;
v_31129:
    goto v_31125;
v_31126:
    goto v_31127;
v_31128:
    v_31452 = (v_31453 == v_31452 ? lisp_true : nil);
    goto v_31112;
    v_31452 = nil;
v_31112:
    goto v_31098;
    v_31452 = nil;
v_31098:
    if (v_31452 == nil) goto v_31096;
    v_31452 = stack[-7];
    fn = elt(env, 8); // qqe_number!-of!-adds!-in!-qterm
    v_31452 = (*qfn1(fn))(fn, v_31452);
    env = stack[-9];
    stack[-3] = v_31452;
    v_31452 = stack[-8];
    fn = elt(env, 8); // qqe_number!-of!-adds!-in!-qterm
    v_31452 = (*qfn1(fn))(fn, v_31452);
    env = stack[-9];
    stack[-4] = v_31452;
    v_31452 = stack[-7];
    fn = elt(env, 9); // qqe_number!-of!-tails!-in!-qterm
    v_31452 = (*qfn1(fn))(fn, v_31452);
    env = stack[-9];
    stack[-1] = v_31452;
    v_31452 = stack[-8];
    fn = elt(env, 9); // qqe_number!-of!-tails!-in!-qterm
    v_31452 = (*qfn1(fn))(fn, v_31452);
    env = stack[-9];
    stack[-2] = v_31452;
    goto v_31153;
v_31149:
    v_31453 = stack[-6];
    goto v_31150;
v_31151:
    v_31452 = stack[-5];
    goto v_31152;
v_31153:
    goto v_31149;
v_31150:
    goto v_31151;
v_31152:
    if (v_31453 == v_31452) goto v_31147;
    else goto v_31148;
v_31147:
    goto v_31166;
v_31162:
    v_31453 = stack[-3];
    goto v_31163;
v_31164:
    v_31452 = stack[-1];
    goto v_31165;
v_31166:
    goto v_31162;
v_31163:
    goto v_31164;
v_31165:
    v_31452 = (LispObject)geq2(v_31453, v_31452);
    v_31452 = v_31452 ? lisp_true : nil;
    env = stack[-9];
    if (v_31452 == nil) goto v_31160;
    else goto v_31159;
v_31160:
    goto v_31175;
v_31171:
    v_31453 = stack[-4];
    goto v_31172;
v_31173:
    v_31452 = stack[-2];
    goto v_31174;
v_31175:
    goto v_31171;
v_31172:
    goto v_31173;
v_31174:
    v_31452 = (LispObject)geq2(v_31453, v_31452);
    v_31452 = v_31452 ? lisp_true : nil;
    env = stack[-9];
    if (v_31452 == nil) goto v_31169;
    else goto v_31159;
v_31169:
    v_31452 = nil;
    goto v_31157;
v_31159:
    goto v_31185;
v_31181:
    goto v_31191;
v_31187:
    v_31453 = stack[-3];
    goto v_31188;
v_31189:
    v_31452 = stack[-1];
    goto v_31190;
v_31191:
    goto v_31187;
v_31188:
    goto v_31189;
v_31190:
    stack[0] = difference2(v_31453, v_31452);
    env = stack[-9];
    goto v_31182;
v_31183:
    goto v_31199;
v_31195:
    v_31453 = stack[-4];
    goto v_31196;
v_31197:
    v_31452 = stack[-2];
    goto v_31198;
v_31199:
    goto v_31195;
v_31196:
    goto v_31197;
v_31198:
    v_31452 = difference2(v_31453, v_31452);
    env = stack[-9];
    goto v_31184;
v_31185:
    goto v_31181;
v_31182:
    goto v_31183;
v_31184:
    v_31452 = (equal(stack[0], v_31452) ? lisp_true : nil);
    v_31452 = (v_31452 == nil ? lisp_true : nil);
    goto v_31157;
    v_31452 = nil;
v_31157:
    goto v_31146;
v_31148:
    v_31452 = nil;
    goto v_31146;
    v_31452 = nil;
v_31146:
    if (v_31452 == nil) goto v_31144;
    v_31452 = elt(env, 3); // false
    goto v_31072;
v_31144:
    goto v_31219;
v_31215:
    v_31453 = stack[-7];
    goto v_31216;
v_31217:
    v_31452 = elt(env, 2); // qepsilon
    goto v_31218;
v_31219:
    goto v_31215;
v_31216:
    goto v_31217;
v_31218:
    if (v_31453 == v_31452) goto v_31213;
    else goto v_31214;
v_31213:
    goto v_31227;
v_31223:
    v_31453 = stack[-4];
    goto v_31224;
v_31225:
    v_31452 = stack[-2];
    goto v_31226;
v_31227:
    goto v_31223;
v_31224:
    goto v_31225;
v_31226:
    v_31452 = (LispObject)greaterp2(v_31453, v_31452);
    v_31452 = v_31452 ? lisp_true : nil;
    env = stack[-9];
    goto v_31212;
v_31214:
    v_31452 = nil;
    goto v_31212;
    v_31452 = nil;
v_31212:
    if (v_31452 == nil) goto v_31210;
    v_31452 = elt(env, 3); // false
    goto v_31072;
v_31210:
    goto v_31244;
v_31240:
    v_31453 = stack[-8];
    goto v_31241;
v_31242:
    v_31452 = elt(env, 2); // qepsilon
    goto v_31243;
v_31244:
    goto v_31240;
v_31241:
    goto v_31242;
v_31243:
    if (v_31453 == v_31452) goto v_31238;
    else goto v_31239;
v_31238:
    goto v_31252;
v_31248:
    v_31453 = stack[-3];
    goto v_31249;
v_31250:
    v_31452 = stack[-1];
    goto v_31251;
v_31252:
    goto v_31248;
v_31249:
    goto v_31250;
v_31251:
    v_31452 = (LispObject)greaterp2(v_31453, v_31452);
    v_31452 = v_31452 ? lisp_true : nil;
    env = stack[-9];
    goto v_31237;
v_31239:
    v_31452 = nil;
    goto v_31237;
    v_31452 = nil;
v_31237:
    if (v_31452 == nil) goto v_31235;
    v_31452 = elt(env, 3); // false
    goto v_31072;
v_31235:
    goto v_31269;
v_31265:
    v_31453 = stack[-7];
    goto v_31266;
v_31267:
    v_31452 = elt(env, 2); // qepsilon
    goto v_31268;
v_31269:
    goto v_31265;
v_31266:
    goto v_31267;
v_31268:
    if (v_31453 == v_31452) goto v_31263;
    else goto v_31264;
v_31263:
    goto v_31280;
v_31276:
    v_31453 = stack[-3];
    goto v_31277;
v_31278:
    v_31452 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31279;
v_31280:
    goto v_31276;
v_31277:
    goto v_31278;
v_31279:
    if (v_31453 == v_31452) goto v_31274;
    else goto v_31275;
v_31274:
    goto v_31287;
v_31283:
    v_31453 = stack[-4];
    goto v_31284;
v_31285:
    v_31452 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31286;
v_31287:
    goto v_31283;
v_31284:
    goto v_31285;
v_31286:
    v_31452 = (v_31453 == v_31452 ? lisp_true : nil);
    goto v_31273;
v_31275:
    v_31452 = nil;
    goto v_31273;
    v_31452 = nil;
v_31273:
    goto v_31262;
v_31264:
    v_31452 = nil;
    goto v_31262;
    v_31452 = nil;
v_31262:
    if (v_31452 == nil) goto v_31260;
    goto v_31305;
v_31301:
    v_31453 = stack[-6];
    goto v_31302;
v_31303:
    v_31452 = elt(env, 2); // qepsilon
    goto v_31304;
v_31305:
    goto v_31301;
v_31302:
    goto v_31303;
v_31304:
    if (v_31453 == v_31452) goto v_31299;
    else goto v_31300;
v_31299:
    v_31452 = elt(env, 1); // true
    goto v_31072;
v_31300:
    v_31452 = stack[-8];
    fn = elt(env, 10); // qqe_simplterm
    v_31452 = (*qfn1(fn))(fn, v_31452);
    env = stack[-9];
    goto v_31298;
v_31298:
    goto v_31320;
v_31314:
    v_31453 = elt(env, 4); // qequal
    goto v_31315;
v_31316:
    v_31454 = v_31452;
    goto v_31317;
v_31318:
    v_31452 = stack[-7];
    goto v_31319;
v_31320:
    goto v_31314;
v_31315:
    goto v_31316;
v_31317:
    goto v_31318;
v_31319:
    {
        fn = elt(env, 11); // qqe_mk2
        return (*qfnn(fn))(fn, 3, v_31453, v_31454, v_31452);
    }
v_31260:
    goto v_31335;
v_31331:
    v_31453 = stack[-8];
    goto v_31332;
v_31333:
    v_31452 = elt(env, 2); // qepsilon
    goto v_31334;
v_31335:
    goto v_31331;
v_31332:
    goto v_31333;
v_31334:
    if (v_31453 == v_31452) goto v_31329;
    else goto v_31330;
v_31329:
    goto v_31346;
v_31342:
    v_31453 = stack[-3];
    goto v_31343;
v_31344:
    v_31452 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31345;
v_31346:
    goto v_31342;
v_31343:
    goto v_31344;
v_31345:
    if (v_31453 == v_31452) goto v_31340;
    else goto v_31341;
v_31340:
    goto v_31353;
v_31349:
    v_31453 = stack[-4];
    goto v_31350;
v_31351:
    v_31452 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31352;
v_31353:
    goto v_31349;
v_31350:
    goto v_31351;
v_31352:
    v_31452 = (v_31453 == v_31452 ? lisp_true : nil);
    goto v_31339;
v_31341:
    v_31452 = nil;
    goto v_31339;
    v_31452 = nil;
v_31339:
    goto v_31328;
v_31330:
    v_31452 = nil;
    goto v_31328;
    v_31452 = nil;
v_31328:
    if (v_31452 == nil) goto v_31326;
    goto v_31371;
v_31367:
    v_31453 = stack[-5];
    goto v_31368;
v_31369:
    v_31452 = elt(env, 2); // qepsilon
    goto v_31370;
v_31371:
    goto v_31367;
v_31368:
    goto v_31369;
v_31370:
    if (v_31453 == v_31452) goto v_31365;
    else goto v_31366;
v_31365:
    v_31452 = elt(env, 1); // true
    goto v_31072;
v_31366:
    v_31452 = stack[-7];
    fn = elt(env, 10); // qqe_simplterm
    v_31452 = (*qfn1(fn))(fn, v_31452);
    env = stack[-9];
    stack[0] = v_31452;
    goto v_31364;
v_31364:
    goto v_31386;
v_31380:
    v_31454 = elt(env, 4); // qequal
    goto v_31381;
v_31382:
    v_31453 = stack[-8];
    goto v_31383;
v_31384:
    v_31452 = stack[0];
    goto v_31385;
v_31386:
    goto v_31380;
v_31381:
    goto v_31382;
v_31383:
    goto v_31384;
v_31385:
    {
        fn = elt(env, 11); // qqe_mk2
        return (*qfnn(fn))(fn, 3, v_31454, v_31453, v_31452);
    }
v_31326:
    goto v_31094;
v_31096:
v_31094:
    v_31452 = stack[-7];
    fn = elt(env, 10); // qqe_simplterm
    v_31452 = (*qfn1(fn))(fn, v_31452);
    env = stack[-9];
    stack[0] = v_31452;
    v_31452 = stack[-8];
    fn = elt(env, 10); // qqe_simplterm
    v_31452 = (*qfn1(fn))(fn, v_31452);
    env = stack[-9];
    goto v_31407;
v_31403:
    v_31454 = stack[-7];
    goto v_31404;
v_31405:
    v_31453 = stack[0];
    goto v_31406;
v_31407:
    goto v_31403;
v_31404:
    goto v_31405;
v_31406:
    if (equal(v_31454, v_31453)) goto v_31401;
    else goto v_31402;
v_31401:
    goto v_31414;
v_31410:
    v_31454 = stack[-8];
    goto v_31411;
v_31412:
    v_31453 = v_31452;
    goto v_31413;
v_31414:
    goto v_31410;
v_31411:
    goto v_31412;
v_31413:
    v_31453 = (equal(v_31454, v_31453) ? lisp_true : nil);
    goto v_31400;
v_31402:
    v_31453 = nil;
    goto v_31400;
    v_31453 = nil;
v_31400:
    if (v_31453 == nil) goto v_31398;
    goto v_31428;
v_31422:
    v_31454 = elt(env, 4); // qequal
    goto v_31423;
v_31424:
    v_31453 = v_31452;
    goto v_31425;
v_31426:
    v_31452 = stack[0];
    goto v_31427;
v_31428:
    goto v_31422;
v_31423:
    goto v_31424;
v_31425:
    goto v_31426;
v_31427:
    {
        fn = elt(env, 11); // qqe_mk2
        return (*qfnn(fn))(fn, 3, v_31454, v_31453, v_31452);
    }
v_31398:
    goto v_31439;
v_31435:
    goto v_31447;
v_31441:
    v_31454 = elt(env, 4); // qequal
    goto v_31442;
v_31443:
    v_31453 = v_31452;
    goto v_31444;
v_31445:
    v_31452 = stack[0];
    goto v_31446;
v_31447:
    goto v_31441;
v_31442:
    goto v_31443;
v_31444:
    goto v_31445;
v_31446:
    fn = elt(env, 11); // qqe_mk2
    v_31452 = (*qfnn(fn))(fn, 3, v_31454, v_31453, v_31452);
    env = stack[-9];
    goto v_31436;
v_31437:
    goto v_31438;
v_31439:
    goto v_31435;
v_31436:
    goto v_31437;
v_31438:
    stack[0] = v_31452;
    goto v_31057;
    v_31452 = nil;
v_31072:
    return onevalue(v_31452);
}



// Code for vdp_zero

static LispObject CC_vdp_zero(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31070, v_31071, v_31072;
    LispObject fn;
    argcheck(nargs, 0, "vdp_zero");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    goto v_31066;
v_31060:
    v_31072 = elt(env, 1); // invalid
    goto v_31061;
v_31062:
    v_31071 = elt(env, 1); // invalid
    goto v_31063;
v_31064:
    v_31070 = nil;
    goto v_31065;
v_31066:
    goto v_31060;
v_31061:
    goto v_31062;
v_31063:
    goto v_31064;
v_31065:
    {
        fn = elt(env, 2); // vdp_make
        return (*qfnn(fn))(fn, 3, v_31072, v_31071, v_31070);
    }
}



// Code for ps!:value

static LispObject CC_psTvalue(LispObject env,
                         LispObject v_31058)
{
    env = qenv(env);
    LispObject v_31109, v_31110, v_31111;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31111 = v_31058;
// end of prologue
    v_31109 = v_31111;
    if (!consp(v_31109)) goto v_31066;
    else goto v_31067;
v_31066:
    v_31109 = lisp_true;
    goto v_31065;
v_31067:
    goto v_31080;
v_31076:
    v_31109 = v_31111;
    v_31110 = qcar(v_31109);
    goto v_31077;
v_31078:
    v_31109 = elt(env, 1); // !:ps!:
    goto v_31079;
v_31080:
    goto v_31076;
v_31077:
    goto v_31078;
v_31079:
    if (v_31110 == v_31109) goto v_31075;
    v_31109 = v_31111;
    v_31109 = qcar(v_31109);
    if (!symbolp(v_31109)) v_31109 = nil;
    else { v_31109 = qfastgets(v_31109);
           if (v_31109 != nil) { v_31109 = elt(v_31109, 8); // dname
#ifdef RECORD_GET
             if (v_31109 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_31109 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_31109 == SPID_NOPROP) v_31109 = nil; }}
#endif
    goto v_31073;
v_31075:
    v_31109 = nil;
    goto v_31073;
    v_31109 = nil;
v_31073:
    goto v_31065;
    v_31109 = nil;
v_31065:
    if (v_31109 == nil) goto v_31063;
    v_31109 = v_31111;
    if (v_31109 == nil) goto v_31093;
    v_31109 = v_31111;
    goto v_31091;
v_31093:
    v_31109 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31091;
    v_31109 = nil;
v_31091:
    goto v_31061;
v_31063:
    goto v_31106;
v_31102:
    v_31110 = v_31111;
    goto v_31103;
v_31104:
    v_31109 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_31105;
v_31106:
    goto v_31102;
v_31103:
    goto v_31104;
v_31105:
    {
        fn = elt(env, 2); // ps!:getv
        return (*qfn2(fn))(fn, v_31110, v_31109);
    }
    v_31109 = nil;
v_31061:
    return onevalue(v_31109);
}



// Code for transferrow1

static LispObject CC_transferrow1(LispObject env,
                         LispObject v_31058)
{
    env = qenv(env);
    LispObject v_31112, v_31113;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31058);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31058;
// end of prologue
    goto v_31068;
v_31064:
    goto v_31073;
v_31069:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_31070;
v_31071:
    goto v_31080;
v_31076:
    v_31113 = qvalue(elt(env, 2)); // maxvar
    goto v_31077;
v_31078:
    v_31112 = stack[0];
    goto v_31079;
v_31080:
    goto v_31076;
v_31077:
    goto v_31078;
v_31079:
    v_31112 = plus2(v_31113, v_31112);
    env = stack[-2];
    goto v_31072;
v_31073:
    goto v_31069;
v_31070:
    goto v_31071;
v_31072:
    v_31113 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_31112-TAG_FIXNUM)/(16/CELL)));
    goto v_31065;
v_31066:
    v_31112 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_31067;
v_31068:
    goto v_31064;
v_31065:
    goto v_31066;
v_31067:
    v_31112 = *(LispObject *)((char *)v_31113 + (CELL-TAG_VECTOR) + (((intptr_t)v_31112-TAG_FIXNUM)/(16/CELL)));
    if (v_31112 == nil) goto v_31062;
    else goto v_31063;
v_31062:
    goto v_31090;
v_31086:
    goto v_31095;
v_31091:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_31092;
v_31093:
    goto v_31102;
v_31098:
    v_31113 = qvalue(elt(env, 2)); // maxvar
    goto v_31099;
v_31100:
    v_31112 = stack[0];
    goto v_31101;
v_31102:
    goto v_31098;
v_31099:
    goto v_31100;
v_31101:
    v_31112 = plus2(v_31113, v_31112);
    goto v_31094;
v_31095:
    goto v_31091;
v_31092:
    goto v_31093;
v_31094:
    v_31113 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_31112-TAG_FIXNUM)/(16/CELL)));
    goto v_31087;
v_31088:
    v_31112 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_31089;
v_31090:
    goto v_31086;
v_31087:
    goto v_31088;
v_31089:
    v_31112 = *(LispObject *)((char *)v_31113 + (CELL-TAG_VECTOR) + (((intptr_t)v_31112-TAG_FIXNUM)/(16/CELL)));
    v_31112 = (is_number(v_31112) ? lisp_true : nil);
    goto v_31061;
v_31063:
    v_31112 = nil;
    goto v_31061;
    v_31112 = nil;
v_31061:
    return onevalue(v_31112);
}



// Code for f2dip2

static LispObject CC_f2dip2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31145, v_31146, v_31147, v_31148;
    LispObject fn;
    LispObject v_31062, v_31061, v_31060, v_31059, v_31058;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "f2dip2");
    va_start(aa, nargs);
    v_31058 = va_arg(aa, LispObject);
    v_31059 = va_arg(aa, LispObject);
    v_31060 = va_arg(aa, LispObject);
    v_31061 = va_arg(aa, LispObject);
    v_31062 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_31062,v_31061,v_31060,v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_31058,v_31059,v_31060,v_31061,v_31062);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_31062;
    stack[-1] = v_31061;
    stack[-2] = v_31060;
    stack[-3] = v_31059;
    stack[-4] = v_31058;
// end of prologue
    goto v_31072;
v_31068:
    v_31146 = stack[-4];
    goto v_31069;
v_31070:
    v_31145 = qvalue(elt(env, 1)); // dipvars!*
    goto v_31071;
v_31072:
    goto v_31068;
v_31069:
    goto v_31070;
v_31071:
    v_31145 = Lmemq(nil, v_31146, v_31145);
    if (v_31145 == nil) goto v_31067;
    goto v_31085;
v_31077:
    v_31148 = stack[-1];
    goto v_31078;
v_31079:
    v_31147 = stack[-4];
    goto v_31080;
v_31081:
    v_31146 = stack[-3];
    goto v_31082;
v_31083:
    v_31145 = qvalue(elt(env, 1)); // dipvars!*
    goto v_31084;
v_31085:
    goto v_31077;
v_31078:
    goto v_31079;
v_31080:
    goto v_31081;
v_31082:
    goto v_31083;
v_31084:
    fn = elt(env, 2); // evinsert
    v_31145 = (*qfnn(fn))(fn, 4, v_31148, v_31147, v_31146, v_31145);
    env = stack[-5];
    goto v_31065;
v_31067:
    v_31145 = nil;
    goto v_31065;
    v_31145 = nil;
v_31065:
    v_31146 = v_31145;
    v_31145 = v_31146;
    if (v_31145 == nil) goto v_31097;
    v_31145 = v_31146;
    stack[-1] = v_31145;
    goto v_31095;
v_31097:
    goto v_31107;
v_31103:
    goto v_31104;
v_31105:
    goto v_31116;
v_31110:
    goto v_31122;
v_31118:
    goto v_31128;
v_31124:
    v_31146 = stack[-4];
    goto v_31125;
v_31126:
    v_31145 = stack[-3];
    goto v_31127;
v_31128:
    goto v_31124;
v_31125:
    goto v_31126;
v_31127:
    fn = elt(env, 3); // to
    v_31146 = (*qfn2(fn))(fn, v_31146, v_31145);
    env = stack[-5];
    goto v_31119;
v_31120:
    v_31145 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31121;
v_31122:
    goto v_31118;
v_31119:
    goto v_31120;
v_31121:
    v_31147 = cons(v_31146, v_31145);
    env = stack[-5];
    goto v_31111;
v_31112:
    v_31146 = nil;
    goto v_31113;
v_31114:
    v_31145 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31115;
v_31116:
    goto v_31110;
v_31111:
    goto v_31112;
v_31113:
    goto v_31114;
v_31115:
    v_31145 = acons(v_31147, v_31146, v_31145);
    env = stack[-5];
    goto v_31106;
v_31107:
    goto v_31103;
v_31104:
    goto v_31105;
v_31106:
    fn = elt(env, 4); // multsq
    v_31145 = (*qfn2(fn))(fn, stack[0], v_31145);
    env = stack[-5];
    stack[0] = v_31145;
    goto v_31095;
v_31095:
    goto v_31141;
v_31135:
    v_31147 = stack[-2];
    goto v_31136;
v_31137:
    v_31146 = stack[-1];
    goto v_31138;
v_31139:
    v_31145 = stack[0];
    goto v_31140;
v_31141:
    goto v_31135;
v_31136:
    goto v_31137;
v_31138:
    goto v_31139;
v_31140:
    {
        fn = elt(env, 5); // f2dip1
        return (*qfnn(fn))(fn, 3, v_31147, v_31146, v_31145);
    }
}



// Code for symmetrize!-inds

static LispObject CC_symmetrizeKinds(LispObject env,
                         LispObject v_31058, LispObject v_31059)
{
    env = qenv(env);
    LispObject v_31370, v_31371;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31058,v_31059);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-8] = v_31059;
    stack[-9] = v_31058;
// end of prologue
    v_31370 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-10] = v_31370;
    v_31370 = stack[-9];
    stack[-7] = v_31370;
    v_31370 = stack[-7];
    if (v_31370 == nil) goto v_31077;
    else goto v_31078;
v_31077:
    v_31370 = nil;
    goto v_31072;
v_31078:
    v_31370 = stack[-7];
    v_31370 = qcar(v_31370);
    v_31371 = v_31370;
    if (!consp(v_31371)) goto v_31087;
    else goto v_31088;
v_31087:
    goto v_31095;
v_31091:
    v_31371 = stack[-8];
    goto v_31092;
v_31093:
    goto v_31094;
v_31095:
    goto v_31091;
v_31092:
    goto v_31093;
v_31094:
    fn = elt(env, 1); // nth
    v_31370 = (*qfn2(fn))(fn, v_31371, v_31370);
    env = stack[-11];
    goto v_31086;
v_31088:
    stack[-3] = v_31370;
    v_31370 = stack[-3];
    if (v_31370 == nil) goto v_31109;
    else goto v_31110;
v_31109:
    v_31370 = nil;
    goto v_31104;
v_31110:
    v_31370 = stack[-3];
    v_31370 = qcar(v_31370);
    goto v_31122;
v_31118:
    v_31371 = stack[-8];
    goto v_31119;
v_31120:
    goto v_31121;
v_31122:
    goto v_31118;
v_31119:
    goto v_31120;
v_31121:
    fn = elt(env, 1); // nth
    v_31370 = (*qfn2(fn))(fn, v_31371, v_31370);
    env = stack[-11];
    v_31370 = ncons(v_31370);
    env = stack[-11];
    stack[-1] = v_31370;
    stack[-2] = v_31370;
v_31105:
    v_31370 = stack[-3];
    v_31370 = qcdr(v_31370);
    stack[-3] = v_31370;
    v_31370 = stack[-3];
    if (v_31370 == nil) goto v_31129;
    else goto v_31130;
v_31129:
    v_31370 = stack[-2];
    goto v_31104;
v_31130:
    goto v_31138;
v_31134:
    stack[0] = stack[-1];
    goto v_31135;
v_31136:
    v_31370 = stack[-3];
    v_31370 = qcar(v_31370);
    goto v_31149;
v_31145:
    v_31371 = stack[-8];
    goto v_31146;
v_31147:
    goto v_31148;
v_31149:
    goto v_31145;
v_31146:
    goto v_31147;
v_31148:
    fn = elt(env, 1); // nth
    v_31370 = (*qfn2(fn))(fn, v_31371, v_31370);
    env = stack[-11];
    v_31370 = ncons(v_31370);
    env = stack[-11];
    goto v_31137;
v_31138:
    goto v_31134;
v_31135:
    goto v_31136;
v_31137:
    v_31370 = Lrplacd(nil, stack[0], v_31370);
    env = stack[-11];
    v_31370 = stack[-1];
    v_31370 = qcdr(v_31370);
    stack[-1] = v_31370;
    goto v_31105;
v_31104:
    goto v_31086;
    v_31370 = nil;
v_31086:
    v_31370 = ncons(v_31370);
    env = stack[-11];
    stack[-5] = v_31370;
    stack[-6] = v_31370;
v_31073:
    v_31370 = stack[-7];
    v_31370 = qcdr(v_31370);
    stack[-7] = v_31370;
    v_31370 = stack[-7];
    if (v_31370 == nil) goto v_31158;
    else goto v_31159;
v_31158:
    v_31370 = stack[-6];
    goto v_31072;
v_31159:
    goto v_31167;
v_31163:
    stack[-4] = stack[-5];
    goto v_31164;
v_31165:
    v_31370 = stack[-7];
    v_31370 = qcar(v_31370);
    v_31371 = v_31370;
    if (!consp(v_31371)) goto v_31175;
    else goto v_31176;
v_31175:
    goto v_31183;
v_31179:
    v_31371 = stack[-8];
    goto v_31180;
v_31181:
    goto v_31182;
v_31183:
    goto v_31179;
v_31180:
    goto v_31181;
v_31182:
    fn = elt(env, 1); // nth
    v_31370 = (*qfn2(fn))(fn, v_31371, v_31370);
    env = stack[-11];
    goto v_31174;
v_31176:
    stack[-3] = v_31370;
    v_31370 = stack[-3];
    if (v_31370 == nil) goto v_31197;
    else goto v_31198;
v_31197:
    v_31370 = nil;
    goto v_31192;
v_31198:
    v_31370 = stack[-3];
    v_31370 = qcar(v_31370);
    goto v_31210;
v_31206:
    v_31371 = stack[-8];
    goto v_31207;
v_31208:
    goto v_31209;
v_31210:
    goto v_31206;
v_31207:
    goto v_31208;
v_31209:
    fn = elt(env, 1); // nth
    v_31370 = (*qfn2(fn))(fn, v_31371, v_31370);
    env = stack[-11];
    v_31370 = ncons(v_31370);
    env = stack[-11];
    stack[-1] = v_31370;
    stack[-2] = v_31370;
v_31193:
    v_31370 = stack[-3];
    v_31370 = qcdr(v_31370);
    stack[-3] = v_31370;
    v_31370 = stack[-3];
    if (v_31370 == nil) goto v_31217;
    else goto v_31218;
v_31217:
    v_31370 = stack[-2];
    goto v_31192;
v_31218:
    goto v_31226;
v_31222:
    stack[0] = stack[-1];
    goto v_31223;
v_31224:
    v_31370 = stack[-3];
    v_31370 = qcar(v_31370);
    goto v_31237;
v_31233:
    v_31371 = stack[-8];
    goto v_31234;
v_31235:
    goto v_31236;
v_31237:
    goto v_31233;
v_31234:
    goto v_31235;
v_31236:
    fn = elt(env, 1); // nth
    v_31370 = (*qfn2(fn))(fn, v_31371, v_31370);
    env = stack[-11];
    v_31370 = ncons(v_31370);
    env = stack[-11];
    goto v_31225;
v_31226:
    goto v_31222;
v_31223:
    goto v_31224;
v_31225:
    v_31370 = Lrplacd(nil, stack[0], v_31370);
    env = stack[-11];
    v_31370 = stack[-1];
    v_31370 = qcdr(v_31370);
    stack[-1] = v_31370;
    goto v_31193;
v_31192:
    goto v_31174;
    v_31370 = nil;
v_31174:
    v_31370 = ncons(v_31370);
    env = stack[-11];
    goto v_31166;
v_31167:
    goto v_31163;
v_31164:
    goto v_31165;
v_31166:
    v_31370 = Lrplacd(nil, stack[-4], v_31370);
    env = stack[-11];
    v_31370 = stack[-5];
    v_31370 = qcdr(v_31370);
    stack[-5] = v_31370;
    goto v_31073;
v_31072:
    stack[-5] = v_31370;
    v_31370 = stack[-5];
    v_31370 = qcar(v_31370);
    if (!consp(v_31370)) goto v_31246;
    else goto v_31247;
v_31246:
    v_31370 = stack[-5];
    fn = elt(env, 2); // indordn
    v_31370 = (*qfn1(fn))(fn, v_31370);
    env = stack[-11];
    goto v_31245;
v_31247:
    v_31370 = stack[-5];
    fn = elt(env, 3); // indordln
    v_31370 = (*qfn1(fn))(fn, v_31370);
    env = stack[-11];
    fn = elt(env, 4); // flatindl
    v_31370 = (*qfn1(fn))(fn, v_31370);
    env = stack[-11];
    goto v_31245;
    v_31370 = nil;
v_31245:
    stack[0] = v_31370;
    v_31370 = stack[-9];
    v_31370 = qcar(v_31370);
    if (!consp(v_31370)) goto v_31260;
    v_31370 = stack[-9];
    fn = elt(env, 4); // flatindl
    v_31370 = (*qfn1(fn))(fn, v_31370);
    env = stack[-11];
    stack[-9] = v_31370;
    goto v_31258;
v_31260:
v_31258:
    goto v_31270;
v_31266:
    v_31371 = stack[-9];
    goto v_31267;
v_31268:
    v_31370 = stack[0];
    goto v_31269;
v_31270:
    goto v_31266;
v_31267:
    goto v_31268;
v_31269:
    fn = elt(env, 5); // pair
    v_31370 = (*qfn2(fn))(fn, v_31371, v_31370);
    env = stack[-11];
    stack[-5] = v_31370;
    goto v_31278;
v_31274:
    stack[-6] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31275;
v_31276:
    v_31370 = stack[-8];
    stack[-7] = v_31370;
    v_31370 = stack[-7];
    if (v_31370 == nil) goto v_31289;
    else goto v_31290;
v_31289:
    v_31370 = nil;
    goto v_31284;
v_31290:
    v_31370 = stack[-7];
    v_31370 = qcar(v_31370);
    stack[-1] = v_31370;
    v_31370 = stack[-5];
    if (v_31370 == nil) goto v_31300;
    goto v_31308;
v_31304:
    v_31370 = stack[-5];
    v_31370 = qcar(v_31370);
    stack[0] = qcar(v_31370);
    goto v_31305;
v_31306:
    v_31370 = stack[-10];
    v_31370 = add1(v_31370);
    env = stack[-11];
    stack[-10] = v_31370;
    goto v_31307;
v_31308:
    goto v_31304;
v_31305:
    goto v_31306;
v_31307:
    if (equal(stack[0], v_31370)) goto v_31303;
    else goto v_31300;
v_31303:
    v_31370 = stack[-5];
    v_31370 = qcar(v_31370);
    v_31370 = qcdr(v_31370);
    v_31371 = v_31370;
    v_31370 = stack[-5];
    v_31370 = qcdr(v_31370);
    stack[-5] = v_31370;
    v_31370 = v_31371;
    goto v_31298;
v_31300:
    v_31370 = stack[-1];
    goto v_31298;
    v_31370 = nil;
v_31298:
    v_31370 = ncons(v_31370);
    env = stack[-11];
    stack[-3] = v_31370;
    stack[-4] = v_31370;
v_31285:
    v_31370 = stack[-7];
    v_31370 = qcdr(v_31370);
    stack[-7] = v_31370;
    v_31370 = stack[-7];
    if (v_31370 == nil) goto v_31327;
    else goto v_31328;
v_31327:
    v_31370 = stack[-4];
    goto v_31284;
v_31328:
    goto v_31336;
v_31332:
    stack[-2] = stack[-3];
    goto v_31333;
v_31334:
    v_31370 = stack[-7];
    v_31370 = qcar(v_31370);
    stack[-1] = v_31370;
    v_31370 = stack[-5];
    if (v_31370 == nil) goto v_31345;
    goto v_31353;
v_31349:
    v_31370 = stack[-5];
    v_31370 = qcar(v_31370);
    stack[0] = qcar(v_31370);
    goto v_31350;
v_31351:
    v_31370 = stack[-10];
    v_31370 = add1(v_31370);
    env = stack[-11];
    stack[-10] = v_31370;
    goto v_31352;
v_31353:
    goto v_31349;
v_31350:
    goto v_31351;
v_31352:
    if (equal(stack[0], v_31370)) goto v_31348;
    else goto v_31345;
v_31348:
    v_31370 = stack[-5];
    v_31370 = qcar(v_31370);
    v_31370 = qcdr(v_31370);
    v_31371 = v_31370;
    v_31370 = stack[-5];
    v_31370 = qcdr(v_31370);
    stack[-5] = v_31370;
    v_31370 = v_31371;
    goto v_31343;
v_31345:
    v_31370 = stack[-1];
    goto v_31343;
    v_31370 = nil;
v_31343:
    v_31370 = ncons(v_31370);
    env = stack[-11];
    goto v_31335;
v_31336:
    goto v_31332;
v_31333:
    goto v_31334;
v_31335:
    v_31370 = Lrplacd(nil, stack[-2], v_31370);
    env = stack[-11];
    v_31370 = stack[-3];
    v_31370 = qcdr(v_31370);
    stack[-3] = v_31370;
    goto v_31285;
v_31284:
    goto v_31277;
v_31278:
    goto v_31274;
v_31275:
    goto v_31276;
v_31277:
    {
        LispObject v_31383 = stack[-6];
        return cons(v_31383, v_31370);
    }
    return onevalue(v_31370);
}



// Code for coeff_sortl

static LispObject CC_coeff_sortl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31080, v_31081, v_31082;
    LispObject fn;
    LispObject v_31060, v_31059, v_31058;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "coeff_sortl");
    va_start(aa, nargs);
    v_31058 = va_arg(aa, LispObject);
    v_31059 = va_arg(aa, LispObject);
    v_31060 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31060,v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31058,v_31059,v_31060);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31060;
    stack[-1] = v_31059;
    v_31080 = v_31058;
// end of prologue
    goto v_31069;
v_31063:
    goto v_31075;
v_31071:
    v_31081 = v_31080;
    goto v_31072;
v_31073:
    v_31080 = stack[0];
    goto v_31074;
v_31075:
    goto v_31071;
v_31072:
    goto v_31073;
v_31074:
    fn = elt(env, 1); // coeff_ordn
    v_31082 = (*qfn2(fn))(fn, v_31081, v_31080);
    env = stack[-2];
    goto v_31064;
v_31065:
    v_31081 = stack[-1];
    goto v_31066;
v_31067:
    v_31080 = stack[0];
    goto v_31068;
v_31069:
    goto v_31063;
v_31064:
    goto v_31065;
v_31066:
    goto v_31067;
v_31068:
    {
        fn = elt(env, 2); // coeff_sortl1
        return (*qfnn(fn))(fn, 3, v_31082, v_31081, v_31080);
    }
}



// Code for subs2chkex

static LispObject CC_subs2chkex(LispObject env,
                         LispObject v_31058)
{
    env = qenv(env);
    LispObject v_31097, v_31098, v_31099;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31058);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_31058;
// end of prologue
v_31057:
    v_31097 = stack[0];
    if (v_31097 == nil) goto v_31062;
    else goto v_31063;
v_31062:
    v_31097 = nil;
    goto v_31061;
v_31063:
    v_31097 = stack[0];
    v_31097 = qcar(v_31097);
    v_31097 = qcdr(v_31097);
    fn = elt(env, 1); // subs2chk
    v_31097 = (*qfn1(fn))(fn, v_31097);
    env = stack[-1];
    v_31098 = v_31097;
    if (v_31098 == nil) goto v_31076;
    goto v_31085;
v_31079:
    v_31098 = stack[0];
    v_31098 = qcar(v_31098);
    v_31099 = qcar(v_31098);
    goto v_31080;
v_31081:
    v_31098 = v_31097;
    goto v_31082;
v_31083:
    v_31097 = stack[0];
    v_31097 = qcdr(v_31097);
    goto v_31084;
v_31085:
    goto v_31079;
v_31080:
    goto v_31081;
v_31082:
    goto v_31083;
v_31084:
    return acons(v_31099, v_31098, v_31097);
v_31076:
    v_31097 = stack[0];
    v_31097 = qcdr(v_31097);
    stack[0] = v_31097;
    goto v_31057;
    v_31097 = nil;
    goto v_31061;
    v_31097 = nil;
v_31061:
    return onevalue(v_31097);
}



// Code for simpsqrt3

static LispObject CC_simpsqrt3(LispObject env,
                         LispObject v_31058)
{
    env = qenv(env);
    LispObject v_31130, v_31131, v_31132;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31058);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31058;
// end of prologue
    goto v_31068;
v_31064:
    v_31131 = stack[0];
    goto v_31065;
v_31066:
    v_31130 = qvalue(elt(env, 1)); // listofallsqrts
    goto v_31067;
v_31068:
    goto v_31064;
v_31065:
    goto v_31066;
v_31067:
    v_31130 = Lassoc(nil, v_31131, v_31130);
    stack[-1] = v_31130;
    v_31130 = stack[-1];
    if (v_31130 == nil) goto v_31075;
    v_31130 = stack[-1];
    v_31130 = qcdr(v_31130);
    goto v_31062;
v_31075:
    goto v_31083;
v_31079:
    v_31131 = qvalue(elt(env, 2)); // listofnewsqrts
    goto v_31080;
v_31081:
    v_31130 = qvalue(elt(env, 3)); // knowntobeindep
    goto v_31082;
v_31083:
    goto v_31079;
v_31080:
    goto v_31081;
v_31082:
    v_31130 = Latsoc(nil, v_31131, v_31130);
    stack[-1] = v_31130;
    v_31130 = stack[-1];
    if (v_31130 == nil) goto v_31089;
    else goto v_31090;
v_31089:
    goto v_31063;
v_31090:
    goto v_31096;
v_31092:
    v_31131 = stack[0];
    goto v_31093;
v_31094:
    v_31130 = stack[-1];
    v_31130 = qcdr(v_31130);
    goto v_31095;
v_31096:
    goto v_31092;
v_31093:
    goto v_31094;
v_31095:
    v_31130 = Lassoc(nil, v_31131, v_31130);
    stack[-1] = v_31130;
    v_31130 = stack[-1];
    if (v_31130 == nil) goto v_31104;
    goto v_31111;
v_31107:
    v_31131 = stack[-1];
    goto v_31108;
v_31109:
    v_31130 = qvalue(elt(env, 1)); // listofallsqrts
    goto v_31110;
v_31111:
    goto v_31107;
v_31108:
    goto v_31109;
v_31110:
    v_31130 = cons(v_31131, v_31130);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_31130; // listofallsqrts
    v_31130 = stack[-1];
    v_31130 = qcdr(v_31130);
    goto v_31062;
v_31104:
v_31063:
    v_31130 = stack[0];
    fn = elt(env, 4); // actualsimpsqrt
    v_31130 = (*qfn1(fn))(fn, v_31130);
    env = stack[-2];
    stack[-1] = v_31130;
    goto v_31125;
v_31119:
    v_31132 = stack[0];
    goto v_31120;
v_31121:
    v_31131 = stack[-1];
    goto v_31122;
v_31123:
    v_31130 = qvalue(elt(env, 1)); // listofallsqrts
    goto v_31124;
v_31125:
    goto v_31119;
v_31120:
    goto v_31121;
v_31122:
    goto v_31123;
v_31124:
    v_31130 = acons(v_31132, v_31131, v_31130);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_31130; // listofallsqrts
    v_31130 = stack[-1];
v_31062:
    return onevalue(v_31130);
}



// Code for ofsf_smmkatl!-and

static LispObject CC_ofsf_smmkatlKand(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31211, v_31212, v_31213;
    LispObject fn;
    LispObject v_31060, v_31059, v_31058;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_smmkatl-and");
    va_start(aa, nargs);
    v_31058 = va_arg(aa, LispObject);
    v_31059 = va_arg(aa, LispObject);
    v_31060 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31060,v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31058,v_31059,v_31060);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_31060;
    v_31211 = v_31059;
    stack[-4] = v_31058;
// end of prologue
    v_31212 = qvalue(elt(env, 1)); // !*rlsipw
    if (v_31212 == nil) goto v_31071;
    else goto v_31072;
v_31071:
    v_31212 = qvalue(elt(env, 2)); // !*rlsipo
    goto v_31070;
v_31072:
    v_31212 = nil;
    goto v_31070;
    v_31212 = nil;
v_31070:
    if (v_31212 == nil) goto v_31068;
    goto v_31085;
v_31079:
    v_31213 = elt(env, 3); // and
    goto v_31080;
v_31081:
    v_31212 = v_31211;
    goto v_31082;
v_31083:
    v_31211 = stack[-3];
    goto v_31084;
v_31085:
    goto v_31079;
v_31080:
    goto v_31081;
v_31082:
    goto v_31083;
v_31084:
    {
        fn = elt(env, 4); // ofsf_irl2atl
        return (*qfnn(fn))(fn, 3, v_31213, v_31212, v_31211);
    }
v_31068:
    stack[-5] = v_31211;
v_31094:
    v_31211 = stack[-5];
    if (v_31211 == nil) goto v_31099;
    else goto v_31100;
v_31099:
    v_31211 = nil;
    goto v_31093;
v_31100:
    v_31211 = stack[-5];
    v_31211 = qcar(v_31211);
    goto v_31110;
v_31106:
    v_31212 = v_31211;
    v_31213 = qcar(v_31212);
    goto v_31107;
v_31108:
    v_31212 = stack[-4];
    goto v_31109;
v_31110:
    goto v_31106;
v_31107:
    goto v_31108;
v_31109:
    v_31212 = Latsoc(nil, v_31213, v_31212);
    v_31213 = v_31212;
    v_31212 = v_31213;
    if (v_31212 == nil) goto v_31117;
    else goto v_31118;
v_31117:
    goto v_31127;
v_31121:
    v_31212 = elt(env, 3); // and
    goto v_31122;
v_31123:
    v_31213 = v_31211;
    goto v_31124;
v_31125:
    v_31211 = stack[-3];
    goto v_31126;
v_31127:
    goto v_31121;
v_31122:
    goto v_31123;
v_31124:
    goto v_31125;
v_31126:
    fn = elt(env, 5); // ofsf_ir2atl
    v_31211 = (*qfnn(fn))(fn, 3, v_31212, v_31213, v_31211);
    env = stack[-6];
    goto v_31116;
v_31118:
    goto v_31140;
v_31134:
    goto v_31135;
v_31136:
    v_31212 = v_31211;
    goto v_31137;
v_31138:
    v_31211 = stack[-3];
    goto v_31139;
v_31140:
    goto v_31134;
v_31135:
    goto v_31136;
v_31137:
    goto v_31138;
v_31139:
    fn = elt(env, 6); // ofsf_smmkatl!-and1
    v_31211 = (*qfnn(fn))(fn, 3, v_31213, v_31212, v_31211);
    env = stack[-6];
    goto v_31116;
    v_31211 = nil;
v_31116:
    stack[-2] = v_31211;
    v_31211 = stack[-2];
    fn = elt(env, 7); // lastpair
    v_31211 = (*qfn1(fn))(fn, v_31211);
    env = stack[-6];
    stack[-1] = v_31211;
    v_31211 = stack[-5];
    v_31211 = qcdr(v_31211);
    stack[-5] = v_31211;
    v_31211 = stack[-1];
    if (!consp(v_31211)) goto v_31150;
    else goto v_31151;
v_31150:
    goto v_31094;
v_31151:
v_31095:
    v_31211 = stack[-5];
    if (v_31211 == nil) goto v_31155;
    else goto v_31156;
v_31155:
    v_31211 = stack[-2];
    goto v_31093;
v_31156:
    goto v_31164;
v_31160:
    stack[0] = stack[-1];
    goto v_31161;
v_31162:
    v_31211 = stack[-5];
    v_31211 = qcar(v_31211);
    goto v_31173;
v_31169:
    v_31212 = v_31211;
    v_31213 = qcar(v_31212);
    goto v_31170;
v_31171:
    v_31212 = stack[-4];
    goto v_31172;
v_31173:
    goto v_31169;
v_31170:
    goto v_31171;
v_31172:
    v_31212 = Latsoc(nil, v_31213, v_31212);
    v_31213 = v_31212;
    v_31212 = v_31213;
    if (v_31212 == nil) goto v_31180;
    else goto v_31181;
v_31180:
    goto v_31190;
v_31184:
    v_31213 = elt(env, 3); // and
    goto v_31185;
v_31186:
    v_31212 = v_31211;
    goto v_31187;
v_31188:
    v_31211 = stack[-3];
    goto v_31189;
v_31190:
    goto v_31184;
v_31185:
    goto v_31186;
v_31187:
    goto v_31188;
v_31189:
    fn = elt(env, 5); // ofsf_ir2atl
    v_31211 = (*qfnn(fn))(fn, 3, v_31213, v_31212, v_31211);
    env = stack[-6];
    goto v_31179;
v_31181:
    goto v_31203;
v_31197:
    goto v_31198;
v_31199:
    v_31212 = v_31211;
    goto v_31200;
v_31201:
    v_31211 = stack[-3];
    goto v_31202;
v_31203:
    goto v_31197;
v_31198:
    goto v_31199;
v_31200:
    goto v_31201;
v_31202:
    fn = elt(env, 6); // ofsf_smmkatl!-and1
    v_31211 = (*qfnn(fn))(fn, 3, v_31213, v_31212, v_31211);
    env = stack[-6];
    goto v_31179;
    v_31211 = nil;
v_31179:
    goto v_31163;
v_31164:
    goto v_31160;
v_31161:
    goto v_31162;
v_31163:
    v_31211 = Lrplacd(nil, stack[0], v_31211);
    env = stack[-6];
    v_31211 = stack[-1];
    fn = elt(env, 7); // lastpair
    v_31211 = (*qfn1(fn))(fn, v_31211);
    env = stack[-6];
    stack[-1] = v_31211;
    v_31211 = stack[-5];
    v_31211 = qcdr(v_31211);
    stack[-5] = v_31211;
    goto v_31095;
v_31093:
    return onevalue(v_31211);
}



// Code for update_components

static LispObject CC_update_components(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31112, v_31113, v_31114, v_31115;
    LispObject v_31060, v_31059, v_31058;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "update_components");
    va_start(aa, nargs);
    v_31058 = va_arg(aa, LispObject);
    v_31059 = va_arg(aa, LispObject);
    v_31060 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31060,v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31058,v_31059,v_31060);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_31114 = v_31060;
    stack[0] = v_31059;
    v_31112 = v_31058;
// end of prologue
    stack[-1] = v_31112;
v_31068:
    v_31112 = stack[-1];
    if (v_31112 == nil) goto v_31072;
    else goto v_31073;
v_31072:
    goto v_31067;
v_31073:
    v_31112 = stack[-1];
    v_31112 = qcar(v_31112);
    v_31113 = v_31112;
    goto v_31088;
v_31084:
    v_31115 = v_31113;
    goto v_31085;
v_31086:
    v_31112 = stack[0];
    goto v_31087;
v_31088:
    goto v_31084;
v_31085:
    goto v_31086;
v_31087:
    v_31112 = Lassoc(nil, v_31115, v_31112);
    v_31115 = v_31112;
    if (v_31112 == nil) goto v_31082;
    goto v_31097;
v_31093:
    goto v_31094;
v_31095:
    v_31112 = v_31114;
    goto v_31096;
v_31097:
    goto v_31093;
v_31094:
    goto v_31095;
v_31096:
    v_31112 = Lassoc(nil, v_31113, v_31112);
    if (v_31112 == nil) goto v_31092;
    else goto v_31082;
v_31092:
    goto v_31106;
v_31102:
    v_31112 = v_31115;
    goto v_31103;
v_31104:
    v_31113 = v_31114;
    goto v_31105;
v_31106:
    goto v_31102;
v_31103:
    goto v_31104;
v_31105:
    v_31112 = cons(v_31112, v_31113);
    env = stack[-2];
    v_31114 = v_31112;
    goto v_31080;
v_31082:
v_31080:
    v_31112 = stack[-1];
    v_31112 = qcdr(v_31112);
    stack[-1] = v_31112;
    goto v_31068;
v_31067:
    v_31112 = v_31114;
    return onevalue(v_31112);
}



// Code for talp_simplatfn

static LispObject CC_talp_simplatfn(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31284, v_31285, v_31286;
    LispObject fn;
    LispObject v_31060, v_31059, v_31058;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_simplatfn");
    va_start(aa, nargs);
    v_31058 = va_arg(aa, LispObject);
    v_31059 = va_arg(aa, LispObject);
    v_31060 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31060,v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31058,v_31059,v_31060);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_31060;
    stack[-2] = v_31059;
    stack[-3] = v_31058;
// end of prologue
    stack[-4] = nil;
    v_31284 = stack[-1];
    if (!consp(v_31284)) goto v_31068;
    else goto v_31069;
v_31068:
    goto v_31079;
v_31075:
    stack[0] = stack[-1];
    goto v_31076;
v_31077:
    fn = elt(env, 5); // talp_getl
    v_31284 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_31078;
v_31079:
    goto v_31075;
v_31076:
    goto v_31077;
v_31078:
    v_31284 = Latsoc(nil, stack[0], v_31284);
    if (v_31284 == nil) goto v_31073;
    else goto v_31074;
v_31073:
    goto v_31092;
v_31088:
    v_31285 = stack[-1];
    goto v_31089;
v_31090:
    v_31284 = stack[-2];
    goto v_31091;
v_31092:
    goto v_31088;
v_31089:
    goto v_31090;
v_31091:
    fn = elt(env, 6); // talp_telp
    v_31284 = (*qfn2(fn))(fn, v_31285, v_31284);
    env = stack[-5];
    if (v_31284 == nil) goto v_31086;
    goto v_31100;
v_31096:
    v_31284 = stack[-3];
    goto v_31097;
v_31098:
    v_31285 = elt(env, 1); // equal
    goto v_31099;
v_31100:
    goto v_31096;
v_31097:
    goto v_31098;
v_31099:
        return Lneq(nil, v_31284, v_31285);
v_31086:
    goto v_31112;
v_31106:
    stack[0] = stack[-3];
    goto v_31107;
v_31108:
    v_31284 = stack[-2];
    fn = elt(env, 7); // talp_simplt
    v_31285 = (*qfn1(fn))(fn, v_31284);
    env = stack[-5];
    goto v_31109;
v_31110:
    v_31284 = stack[-1];
    goto v_31111;
v_31112:
    goto v_31106;
v_31107:
    goto v_31108;
v_31109:
    goto v_31110;
v_31111:
    {
        LispObject v_31292 = stack[0];
        fn = elt(env, 8); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_31292, v_31285, v_31284);
    }
    goto v_31072;
v_31074:
    goto v_31124;
v_31120:
    v_31284 = stack[-3];
    goto v_31121;
v_31122:
    v_31285 = elt(env, 1); // equal
    goto v_31123;
v_31124:
    goto v_31120;
v_31121:
    goto v_31122;
v_31123:
        return Lneq(nil, v_31284, v_31285);
v_31072:
    goto v_31067;
v_31069:
    goto v_31133;
v_31129:
    v_31284 = stack[-2];
    fn = elt(env, 9); // talp_fop
    stack[0] = (*qfn1(fn))(fn, v_31284);
    env = stack[-5];
    goto v_31130;
v_31131:
    v_31284 = stack[-1];
    fn = elt(env, 9); // talp_fop
    v_31284 = (*qfn1(fn))(fn, v_31284);
    env = stack[-5];
    goto v_31132;
v_31133:
    goto v_31129;
v_31130:
    goto v_31131;
v_31132:
    v_31284 = (stack[0] == v_31284 ? lisp_true : nil);
    stack[0] = v_31284;
    v_31284 = stack[-2];
    fn = elt(env, 10); // talp_fargl
    v_31284 = (*qfn1(fn))(fn, v_31284);
    env = stack[-5];
    stack[-2] = v_31284;
    v_31284 = stack[-1];
    fn = elt(env, 10); // talp_fargl
    v_31284 = (*qfn1(fn))(fn, v_31284);
    env = stack[-5];
    stack[-1] = v_31284;
v_31145:
    v_31284 = stack[-2];
    if (v_31284 == nil) goto v_31148;
    v_31284 = stack[-1];
    if (v_31284 == nil) goto v_31148;
    v_31284 = stack[0];
    if (v_31284 == nil) goto v_31148;
    goto v_31149;
v_31148:
    goto v_31144;
v_31149:
    goto v_31165;
v_31159:
    v_31286 = elt(env, 1); // equal
    goto v_31160;
v_31161:
    v_31284 = stack[-2];
    v_31285 = qcar(v_31284);
    goto v_31162;
v_31163:
    v_31284 = stack[-1];
    v_31284 = qcar(v_31284);
    goto v_31164;
v_31165:
    goto v_31159;
v_31160:
    goto v_31161;
v_31162:
    goto v_31163;
v_31164:
    fn = elt(env, 11); // talp_simplat2
    v_31284 = (*qfnn(fn))(fn, 3, v_31286, v_31285, v_31284);
    env = stack[-5];
    stack[0] = v_31284;
    v_31284 = stack[0];
    if (v_31284 == nil) goto v_31174;
    goto v_31182;
v_31178:
    v_31285 = stack[0];
    goto v_31179;
v_31180:
    v_31284 = lisp_true;
    goto v_31181;
v_31182:
    goto v_31178;
v_31179:
    goto v_31180;
v_31181:
    if (equal(v_31285, v_31284)) goto v_31174;
    goto v_31193;
v_31189:
    v_31285 = stack[-3];
    goto v_31190;
v_31191:
    v_31284 = elt(env, 1); // equal
    goto v_31192;
v_31193:
    goto v_31189;
v_31190:
    goto v_31191;
v_31192:
    if (v_31285 == v_31284) goto v_31187;
    else goto v_31188;
v_31187:
    goto v_31201;
v_31197:
    v_31285 = stack[0];
    goto v_31198;
v_31199:
    v_31284 = stack[-4];
    goto v_31200;
v_31201:
    goto v_31197;
v_31198:
    goto v_31199;
v_31200:
    v_31284 = cons(v_31285, v_31284);
    env = stack[-5];
    stack[-4] = v_31284;
    goto v_31186;
v_31188:
    goto v_31213;
v_31207:
    v_31286 = elt(env, 2); // neq
    goto v_31208;
v_31209:
    v_31284 = stack[0];
    v_31285 = qcdr(v_31284);
    goto v_31210;
v_31211:
    v_31284 = stack[-4];
    goto v_31212;
v_31213:
    goto v_31207;
v_31208:
    goto v_31209;
v_31210:
    goto v_31211;
v_31212:
    v_31284 = acons(v_31286, v_31285, v_31284);
    env = stack[-5];
    stack[-4] = v_31284;
    goto v_31186;
v_31186:
    goto v_31172;
v_31174:
v_31172:
    v_31284 = stack[-2];
    v_31284 = qcdr(v_31284);
    stack[-2] = v_31284;
    v_31284 = stack[-1];
    v_31284 = qcdr(v_31284);
    stack[-1] = v_31284;
    goto v_31145;
v_31144:
    v_31284 = stack[0];
    if (v_31284 == nil) goto v_31226;
    v_31284 = stack[-4];
    if (v_31284 == nil) goto v_31226;
    v_31284 = stack[-4];
    v_31284 = qcdr(v_31284);
    if (v_31284 == nil) goto v_31234;
    goto v_31245;
v_31241:
    v_31285 = stack[-3];
    goto v_31242;
v_31243:
    v_31284 = elt(env, 1); // equal
    goto v_31244;
v_31245:
    goto v_31241;
v_31242:
    goto v_31243;
v_31244:
    if (v_31285 == v_31284) goto v_31239;
    else goto v_31240;
v_31239:
    goto v_31253;
v_31249:
    v_31285 = elt(env, 3); // and
    goto v_31250;
v_31251:
    v_31284 = stack[-4];
    goto v_31252;
v_31253:
    goto v_31249;
v_31250:
    goto v_31251;
v_31252:
    return cons(v_31285, v_31284);
v_31240:
    goto v_31263;
v_31259:
    v_31285 = elt(env, 4); // or
    goto v_31260;
v_31261:
    v_31284 = stack[-4];
    goto v_31262;
v_31263:
    goto v_31259;
v_31260:
    goto v_31261;
v_31262:
    return cons(v_31285, v_31284);
    goto v_31232;
v_31234:
    v_31284 = stack[-4];
    v_31284 = qcar(v_31284);
    goto v_31065;
v_31232:
    goto v_31224;
v_31226:
    goto v_31276;
v_31272:
    v_31284 = stack[-3];
    goto v_31273;
v_31274:
    v_31285 = elt(env, 1); // equal
    goto v_31275;
v_31276:
    goto v_31272;
v_31273:
    goto v_31274;
v_31275:
    if (v_31284 == v_31285) goto v_31270;
    else goto v_31271;
v_31270:
    v_31284 = stack[0];
    goto v_31065;
v_31271:
    v_31284 = stack[0];
    v_31284 = (v_31284 == nil ? lisp_true : nil);
    goto v_31065;
v_31224:
    goto v_31067;
v_31067:
    v_31284 = nil;
v_31065:
    return onevalue(v_31284);
}



// Code for division!-test

static LispObject CC_divisionKtest(LispObject env,
                         LispObject v_31058, LispObject v_31059)
{
    env = qenv(env);
    LispObject v_31086, v_31087;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31058,v_31059);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31059;
    stack[-1] = v_31058;
// end of prologue
v_31063:
    v_31086 = stack[0];
    if (v_31086 == nil) goto v_31066;
    else goto v_31067;
v_31066:
    v_31086 = lisp_true;
    goto v_31062;
v_31067:
    goto v_31077;
v_31073:
    v_31086 = stack[0];
    v_31087 = qcar(v_31086);
    goto v_31074;
v_31075:
    v_31086 = stack[-1];
    goto v_31076;
v_31077:
    goto v_31073;
v_31074:
    goto v_31075;
v_31076:
    fn = elt(env, 1); // quotf
    v_31086 = (*qfn2(fn))(fn, v_31087, v_31086);
    env = stack[-2];
    if (v_31086 == nil) goto v_31070;
    else goto v_31071;
v_31070:
    v_31086 = nil;
    goto v_31062;
v_31071:
    v_31086 = stack[0];
    v_31086 = qcdr(v_31086);
    stack[0] = v_31086;
    goto v_31063;
    v_31086 = nil;
v_31062:
    return onevalue(v_31086);
}



// Code for vsl_boundtype1

static LispObject CC_vsl_boundtype1(LispObject env,
                         LispObject v_31058, LispObject v_31059)
{
    env = qenv(env);
    LispObject v_31108, v_31109, v_31110, v_31111;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31058,v_31059);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31111 = v_31059;
    v_31110 = v_31058;
// end of prologue
v_31063:
    v_31108 = v_31110;
    if (!consp(v_31108)) goto v_31070;
    else goto v_31071;
v_31070:
    v_31108 = lisp_true;
    goto v_31069;
v_31071:
    v_31108 = v_31110;
    v_31108 = qcar(v_31108);
    v_31108 = (consp(v_31108) ? nil : lisp_true);
    goto v_31069;
    v_31108 = nil;
v_31069:
    if (v_31108 == nil) goto v_31067;
    v_31108 = nil;
    goto v_31062;
v_31067:
    goto v_31086;
v_31082:
    v_31108 = v_31110;
    v_31108 = qcar(v_31108);
    v_31108 = qcar(v_31108);
    v_31109 = qcar(v_31108);
    goto v_31083;
v_31084:
    v_31108 = v_31111;
    goto v_31085;
v_31086:
    goto v_31082;
v_31083:
    goto v_31084;
v_31085:
    if (v_31109 == v_31108) goto v_31080;
    else goto v_31081;
v_31080:
    v_31108 = v_31110;
    v_31108 = qcar(v_31108);
    v_31108 = qcdr(v_31108);
    fn = elt(env, 3); // minusf
    v_31108 = (*qfn1(fn))(fn, v_31108);
    env = stack[0];
    if (v_31108 == nil) goto v_31095;
    v_31108 = elt(env, 1); // ub
    goto v_31062;
v_31095:
    v_31108 = elt(env, 2); // lb
    goto v_31062;
    goto v_31065;
v_31081:
    v_31108 = v_31110;
    v_31108 = qcdr(v_31108);
    v_31110 = v_31108;
    goto v_31063;
v_31065:
    v_31108 = nil;
v_31062:
    return onevalue(v_31108);
}



// Code for spmatsm!*

static LispObject CC_spmatsmH(LispObject env,
                         LispObject v_31058, LispObject v_31059)
{
    env = qenv(env);
    LispObject v_31084, v_31085, v_31086;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31058,v_31059);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31084 = v_31059;
    v_31085 = v_31058;
// end of prologue
    v_31084 = v_31085;
    fn = elt(env, 2); // spmatsm
    v_31084 = (*qfn1(fn))(fn, v_31084);
    env = stack[0];
    v_31086 = v_31084;
    goto v_31075;
v_31071:
    v_31085 = v_31086;
    goto v_31072;
v_31073:
    v_31084 = elt(env, 1); // sparsemat
    goto v_31074;
v_31075:
    goto v_31071;
v_31072:
    goto v_31073;
v_31074:
    if (!consp(v_31085)) goto v_31069;
    v_31085 = qcar(v_31085);
    if (v_31085 == v_31084) goto v_31068;
    else goto v_31069;
v_31068:
    v_31084 = v_31086;
    goto v_31063;
v_31069:
    v_31084 = v_31086;
    {
        fn = elt(env, 3); // matsm!*1
        return (*qfn1(fn))(fn, v_31084);
    }
    v_31084 = nil;
v_31063:
    return onevalue(v_31084);
}



// Code for tchscheme

static LispObject CC_tchscheme(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31183, v_31184;
    LispObject fn;
    argcheck(nargs, 0, "tchscheme");
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
    stack[-3] = nil;
    stack[-2] = nil;
    v_31183 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_31183;
v_31066:
    goto v_31078;
v_31074:
    v_31184 = qvalue(elt(env, 1)); // rowmax
    goto v_31075;
v_31076:
    v_31183 = stack[-1];
    goto v_31077;
v_31078:
    goto v_31074;
v_31075:
    goto v_31076;
v_31077:
    v_31183 = difference2(v_31184, v_31183);
    env = stack[-4];
    v_31183 = Lminusp(nil, v_31183);
    env = stack[-4];
    if (v_31183 == nil) goto v_31071;
    goto v_31065;
v_31071:
    goto v_31094;
v_31090:
    goto v_31099;
v_31095:
    goto v_31104;
v_31100:
    stack[0] = qvalue(elt(env, 2)); // codmat
    goto v_31101;
v_31102:
    goto v_31111;
v_31107:
    v_31184 = qvalue(elt(env, 3)); // maxvar
    goto v_31108;
v_31109:
    v_31183 = stack[-1];
    goto v_31110;
v_31111:
    goto v_31107;
v_31108:
    goto v_31109;
v_31110:
    v_31183 = plus2(v_31184, v_31183);
    env = stack[-4];
    goto v_31103;
v_31104:
    goto v_31100;
v_31101:
    goto v_31102;
v_31103:
    v_31184 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_31183-TAG_FIXNUM)/(16/CELL)));
    goto v_31096;
v_31097:
    v_31183 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_31098;
v_31099:
    goto v_31095;
v_31096:
    goto v_31097;
v_31098:
    v_31184 = *(LispObject *)((char *)v_31184 + (CELL-TAG_VECTOR) + (((intptr_t)v_31183-TAG_FIXNUM)/(16/CELL)));
    goto v_31091;
v_31092:
    v_31183 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_31093;
v_31094:
    goto v_31090;
v_31091:
    goto v_31092;
v_31093:
    if (v_31184 == v_31183) goto v_31089;
    goto v_31126;
v_31122:
    goto v_31131;
v_31127:
    stack[0] = qvalue(elt(env, 2)); // codmat
    goto v_31128;
v_31129:
    goto v_31138;
v_31134:
    v_31184 = qvalue(elt(env, 3)); // maxvar
    goto v_31135;
v_31136:
    v_31183 = stack[-1];
    goto v_31137;
v_31138:
    goto v_31134;
v_31135:
    goto v_31136;
v_31137:
    v_31183 = plus2(v_31184, v_31183);
    env = stack[-4];
    goto v_31130;
v_31131:
    goto v_31127;
v_31128:
    goto v_31129;
v_31130:
    v_31184 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_31183-TAG_FIXNUM)/(16/CELL)));
    goto v_31123;
v_31124:
    v_31183 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_31125;
v_31126:
    goto v_31122;
v_31123:
    goto v_31124;
v_31125:
    v_31183 = *(LispObject *)((char *)v_31184 + (CELL-TAG_VECTOR) + (((intptr_t)v_31183-TAG_FIXNUM)/(16/CELL)));
    stack[-3] = v_31183;
    if (v_31183 == nil) goto v_31120;
    else goto v_31121;
v_31120:
    v_31183 = nil;
    goto v_31119;
v_31121:
    v_31183 = stack[-3];
    v_31183 = qcdr(v_31183);
    if (v_31183 == nil) goto v_31149;
    else goto v_31150;
v_31149:
    goto v_31158;
v_31154:
    v_31184 = stack[-1];
    goto v_31155;
v_31156:
    v_31183 = stack[-3];
    v_31183 = qcar(v_31183);
    v_31183 = qcdr(v_31183);
    v_31183 = qcar(v_31183);
    goto v_31157;
v_31158:
    goto v_31154;
v_31155:
    goto v_31156;
v_31157:
    fn = elt(env, 4); // transferrow
    v_31183 = (*qfn2(fn))(fn, v_31184, v_31183);
    env = stack[-4];
    goto v_31148;
v_31150:
    v_31183 = nil;
    goto v_31148;
    v_31183 = nil;
v_31148:
    goto v_31119;
    v_31183 = nil;
v_31119:
    goto v_31087;
v_31089:
    v_31183 = nil;
    goto v_31087;
    v_31183 = nil;
v_31087:
    if (v_31183 == nil) goto v_31085;
    goto v_31175;
v_31171:
    v_31184 = stack[-1];
    goto v_31172;
v_31173:
    v_31183 = stack[-3];
    v_31183 = qcar(v_31183);
    goto v_31174;
v_31175:
    goto v_31171;
v_31172:
    goto v_31173;
v_31174:
    fn = elt(env, 5); // chscheme
    v_31183 = (*qfn2(fn))(fn, v_31184, v_31183);
    env = stack[-4];
    v_31183 = lisp_true;
    stack[-2] = v_31183;
    goto v_31083;
v_31085:
v_31083:
    v_31183 = stack[-1];
    v_31183 = add1(v_31183);
    env = stack[-4];
    stack[-1] = v_31183;
    goto v_31066;
v_31065:
    v_31183 = stack[-2];
    return onevalue(v_31183);
}



// Code for solvealgtrig01

static LispObject CC_solvealgtrig01(LispObject env,
                         LispObject v_31058, LispObject v_31059)
{
    env = qenv(env);
    LispObject v_31118, v_31119;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31058,v_31059);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31059;
    stack[-1] = v_31058;
// end of prologue
v_31064:
    v_31118 = stack[-1];
    if (!consp(v_31118)) goto v_31067;
    else goto v_31068;
v_31067:
    v_31118 = stack[0];
    goto v_31063;
v_31068:
    goto v_31077;
v_31073:
    v_31118 = stack[-1];
    v_31119 = qcar(v_31118);
    goto v_31074;
v_31075:
    v_31118 = elt(env, 1); // (sin cos tan cot sinh cosh tanh coth)
    goto v_31076;
v_31077:
    goto v_31073;
v_31074:
    goto v_31075;
v_31076:
    v_31118 = Lmemq(nil, v_31119, v_31118);
    if (v_31118 == nil) goto v_31072;
    v_31118 = stack[-1];
    v_31118 = qcdr(v_31118);
    v_31118 = qcar(v_31118);
    fn = elt(env, 2); // constant_exprp
    v_31118 = (*qfn1(fn))(fn, v_31118);
    env = stack[-3];
    if (v_31118 == nil) goto v_31085;
    v_31118 = stack[0];
    goto v_31063;
v_31085:
    goto v_31098;
v_31094:
    v_31118 = stack[-1];
    v_31118 = qcdr(v_31118);
    v_31118 = qcar(v_31118);
    v_31119 = ncons(v_31118);
    env = stack[-3];
    goto v_31095;
v_31096:
    v_31118 = stack[0];
    goto v_31097;
v_31098:
    goto v_31094;
v_31095:
    goto v_31096;
v_31097:
    {
        fn = elt(env, 3); // union
        return (*qfn2(fn))(fn, v_31119, v_31118);
    }
    goto v_31066;
v_31072:
    v_31118 = stack[-1];
    v_31118 = qcdr(v_31118);
    stack[-2] = v_31118;
    goto v_31113;
v_31109:
    v_31118 = stack[-1];
    v_31119 = qcar(v_31118);
    goto v_31110;
v_31111:
    v_31118 = stack[0];
    goto v_31112;
v_31113:
    goto v_31109;
v_31110:
    goto v_31111;
v_31112:
    v_31118 = CC_solvealgtrig01(elt(env, 0), v_31119, v_31118);
    env = stack[-3];
    stack[0] = v_31118;
    v_31118 = stack[-2];
    stack[-1] = v_31118;
    goto v_31064;
v_31066:
    v_31118 = nil;
v_31063:
    return onevalue(v_31118);
}



// Code for normmat

static LispObject CC_normmat(LispObject env,
                         LispObject v_31058)
{
    env = qenv(env);
    LispObject v_31204, v_31205;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31058);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    v_31205 = v_31058;
// end of prologue
    stack[-6] = nil;
    v_31204 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_31204;
    v_31204 = v_31205;
    stack[-5] = v_31204;
v_31069:
    v_31204 = stack[-5];
    if (v_31204 == nil) goto v_31073;
    else goto v_31074;
v_31073:
    goto v_31068;
v_31074:
    v_31204 = stack[-5];
    v_31204 = qcar(v_31204);
    stack[-1] = v_31204;
    v_31204 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-7] = v_31204;
    v_31204 = stack[-1];
    stack[0] = v_31204;
v_31084:
    v_31204 = stack[0];
    if (v_31204 == nil) goto v_31088;
    else goto v_31089;
v_31088:
    goto v_31083;
v_31089:
    v_31204 = stack[0];
    v_31204 = qcar(v_31204);
    goto v_31100;
v_31096:
    v_31205 = stack[-7];
    goto v_31097;
v_31098:
    v_31204 = qcdr(v_31204);
    goto v_31099;
v_31100:
    goto v_31096;
v_31097:
    goto v_31098;
v_31099:
    fn = elt(env, 1); // lcm
    v_31204 = (*qfn2(fn))(fn, v_31205, v_31204);
    env = stack[-9];
    stack[-7] = v_31204;
    v_31204 = stack[0];
    v_31204 = qcdr(v_31204);
    stack[0] = v_31204;
    goto v_31084;
v_31083:
    goto v_31111;
v_31107:
    v_31204 = stack[-1];
    stack[-4] = v_31204;
    v_31204 = stack[-4];
    if (v_31204 == nil) goto v_31121;
    else goto v_31122;
v_31121:
    v_31204 = nil;
    v_31205 = v_31204;
    goto v_31116;
v_31122:
    v_31204 = stack[-4];
    v_31204 = qcar(v_31204);
    goto v_31134;
v_31130:
    v_31205 = v_31204;
    stack[0] = qcar(v_31205);
    goto v_31131;
v_31132:
    goto v_31142;
v_31138:
    v_31205 = stack[-7];
    goto v_31139;
v_31140:
    v_31204 = qcdr(v_31204);
    goto v_31141;
v_31142:
    goto v_31138;
v_31139:
    goto v_31140;
v_31141:
    fn = elt(env, 2); // quotf
    v_31204 = (*qfn2(fn))(fn, v_31205, v_31204);
    env = stack[-9];
    goto v_31133;
v_31134:
    goto v_31130;
v_31131:
    goto v_31132;
v_31133:
    fn = elt(env, 3); // multf
    v_31204 = (*qfn2(fn))(fn, stack[0], v_31204);
    env = stack[-9];
    v_31204 = ncons(v_31204);
    env = stack[-9];
    stack[-2] = v_31204;
    stack[-3] = v_31204;
v_31117:
    v_31204 = stack[-4];
    v_31204 = qcdr(v_31204);
    stack[-4] = v_31204;
    v_31204 = stack[-4];
    if (v_31204 == nil) goto v_31150;
    else goto v_31151;
v_31150:
    v_31204 = stack[-3];
    v_31205 = v_31204;
    goto v_31116;
v_31151:
    goto v_31159;
v_31155:
    stack[-1] = stack[-2];
    goto v_31156;
v_31157:
    v_31204 = stack[-4];
    v_31204 = qcar(v_31204);
    goto v_31170;
v_31166:
    v_31205 = v_31204;
    stack[0] = qcar(v_31205);
    goto v_31167;
v_31168:
    goto v_31178;
v_31174:
    v_31205 = stack[-7];
    goto v_31175;
v_31176:
    v_31204 = qcdr(v_31204);
    goto v_31177;
v_31178:
    goto v_31174;
v_31175:
    goto v_31176;
v_31177:
    fn = elt(env, 2); // quotf
    v_31204 = (*qfn2(fn))(fn, v_31205, v_31204);
    env = stack[-9];
    goto v_31169;
v_31170:
    goto v_31166;
v_31167:
    goto v_31168;
v_31169:
    fn = elt(env, 3); // multf
    v_31204 = (*qfn2(fn))(fn, stack[0], v_31204);
    env = stack[-9];
    v_31204 = ncons(v_31204);
    env = stack[-9];
    goto v_31158;
v_31159:
    goto v_31155;
v_31156:
    goto v_31157;
v_31158:
    v_31204 = Lrplacd(nil, stack[-1], v_31204);
    env = stack[-9];
    v_31204 = stack[-2];
    v_31204 = qcdr(v_31204);
    stack[-2] = v_31204;
    goto v_31117;
v_31116:
    goto v_31108;
v_31109:
    v_31204 = stack[-6];
    goto v_31110;
v_31111:
    goto v_31107;
v_31108:
    goto v_31109;
v_31110:
    v_31204 = cons(v_31205, v_31204);
    env = stack[-9];
    stack[-6] = v_31204;
    goto v_31190;
v_31186:
    v_31205 = stack[-7];
    goto v_31187;
v_31188:
    v_31204 = stack[-8];
    goto v_31189;
v_31190:
    goto v_31186;
v_31187:
    goto v_31188;
v_31189:
    fn = elt(env, 3); // multf
    v_31204 = (*qfn2(fn))(fn, v_31205, v_31204);
    env = stack[-9];
    stack[-8] = v_31204;
    v_31204 = stack[-5];
    v_31204 = qcdr(v_31204);
    stack[-5] = v_31204;
    goto v_31069;
v_31068:
    goto v_31200;
v_31196:
    v_31204 = stack[-6];
    v_31205 = Lreverse(nil, v_31204);
    goto v_31197;
v_31198:
    v_31204 = stack[-8];
    goto v_31199;
v_31200:
    goto v_31196;
v_31197:
    goto v_31198;
v_31199:
    return cons(v_31205, v_31204);
    return onevalue(v_31204);
}



// Code for extract_numid

static LispObject CC_extract_numid(LispObject env,
                         LispObject v_31058)
{
    env = qenv(env);
    LispObject v_31092, v_31093;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31058);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31058;
// end of prologue
v_31057:
    v_31092 = stack[0];
    if (v_31092 == nil) goto v_31062;
    else goto v_31063;
v_31062:
    v_31092 = nil;
    goto v_31061;
v_31063:
    v_31092 = stack[0];
    v_31092 = qcar(v_31092);
    fn = elt(env, 1); // !*id2num
    v_31092 = (*qfn1(fn))(fn, v_31092);
    env = stack[-2];
    v_31093 = v_31092;
    v_31092 = v_31093;
    if (v_31092 == nil) goto v_31075;
    goto v_31082;
v_31078:
    stack[-1] = v_31093;
    goto v_31079;
v_31080:
    v_31092 = stack[0];
    v_31092 = qcdr(v_31092);
    v_31092 = CC_extract_numid(elt(env, 0), v_31092);
    goto v_31081;
v_31082:
    goto v_31078;
v_31079:
    goto v_31080;
v_31081:
    {
        LispObject v_31096 = stack[-1];
        return cons(v_31096, v_31092);
    }
v_31075:
    v_31092 = stack[0];
    v_31092 = qcdr(v_31092);
    stack[0] = v_31092;
    goto v_31057;
    v_31092 = nil;
    goto v_31061;
    v_31092 = nil;
v_31061:
    return onevalue(v_31092);
}



// Code for dv_skelsplit

static LispObject CC_dv_skelsplit(LispObject env,
                         LispObject v_31058)
{
    env = qenv(env);
    LispObject v_31513, v_31514, v_31515;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31058);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(13);
// copy arguments values to proper place
    stack[-10] = v_31058;
// end of prologue
    v_31513 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_31513;
    v_31513 = stack[-10];
    fn = elt(env, 10); // listp
    v_31513 = (*qfn1(fn))(fn, v_31513);
    env = stack[-12];
    if (v_31513 == nil) goto v_31078;
    v_31513 = stack[-10];
    v_31513 = qcdr(v_31513);
    v_31513 = qcar(v_31513);
    fn = elt(env, 10); // listp
    v_31513 = (*qfn1(fn))(fn, v_31513);
    env = stack[-12];
    if (v_31513 == nil) goto v_31084;
    goto v_31095;
v_31091:
    v_31513 = stack[-10];
    v_31513 = qcdr(v_31513);
    v_31513 = qcar(v_31513);
    v_31514 = qcar(v_31513);
    goto v_31092;
v_31093:
    v_31513 = elt(env, 1); // list
    goto v_31094;
v_31095:
    goto v_31091;
v_31092:
    goto v_31093;
v_31094:
    if (v_31514 == v_31513) goto v_31090;
    else goto v_31084;
v_31090:
    v_31513 = stack[-10];
    v_31513 = qcdr(v_31513);
    v_31513 = qcar(v_31513);
    goto v_31082;
v_31084:
    v_31513 = nil;
v_31082:
    goto v_31076;
v_31078:
    v_31513 = nil;
v_31076:
    stack[-11] = v_31513;
    v_31513 = stack[-10];
    fn = elt(env, 11); // dummyp
    v_31513 = (*qfn1(fn))(fn, v_31513);
    env = stack[-12];
    stack[-6] = v_31513;
    if (v_31513 == nil) goto v_31107;
    goto v_31117;
v_31111:
    stack[-3] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31112;
v_31113:
    stack[-2] = stack[-6];
    goto v_31114;
v_31115:
    goto v_31127;
v_31121:
    stack[-1] = elt(env, 2); // !~dv
    goto v_31122;
v_31123:
    stack[0] = elt(env, 3); // !*
    goto v_31124;
v_31125:
    v_31513 = stack[-6];
    v_31513 = ncons(v_31513);
    env = stack[-12];
    goto v_31126;
v_31127:
    goto v_31121;
v_31122:
    goto v_31123;
v_31124:
    goto v_31125;
v_31126:
    v_31513 = list2star(stack[-1], stack[0], v_31513);
    goto v_31116;
v_31117:
    goto v_31111;
v_31112:
    goto v_31113;
v_31114:
    goto v_31115;
v_31116:
    {
        LispObject v_31528 = stack[-3];
        LispObject v_31529 = stack[-2];
        return list3(v_31528, v_31529, v_31513);
    }
v_31107:
    v_31513 = stack[-10];
    fn = elt(env, 10); // listp
    v_31513 = (*qfn1(fn))(fn, v_31513);
    env = stack[-12];
    if (v_31513 == nil) goto v_31136;
    else goto v_31137;
v_31136:
    v_31513 = lisp_true;
    goto v_31135;
v_31137:
    v_31513 = stack[-11];
    if (v_31513 == nil) goto v_31145;
    else goto v_31146;
v_31145:
    v_31513 = nil;
    goto v_31144;
v_31146:
    v_31513 = stack[-10];
    v_31513 = qcdr(v_31513);
    v_31513 = qcdr(v_31513);
    v_31513 = (v_31513 == nil ? lisp_true : nil);
    goto v_31144;
    v_31513 = nil;
v_31144:
    goto v_31135;
    v_31513 = nil;
v_31135:
    if (v_31513 == nil) goto v_31133;
    goto v_31162;
v_31156:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31157;
v_31158:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31159;
v_31160:
    v_31513 = stack[-10];
    v_31513 = ncons(v_31513);
    goto v_31161;
v_31162:
    goto v_31156;
v_31157:
    goto v_31158;
v_31159:
    goto v_31160;
v_31161:
    {
        LispObject v_31530 = stack[-1];
        LispObject v_31531 = stack[0];
        return list3(v_31530, v_31531, v_31513);
    }
v_31133:
    goto v_31172;
v_31168:
    v_31513 = stack[-10];
    v_31514 = qcar(v_31513);
    goto v_31169;
v_31170:
    v_31513 = elt(env, 4); // symtree
    goto v_31171;
v_31172:
    goto v_31168;
v_31169:
    goto v_31170;
v_31171:
    v_31513 = get(v_31514, v_31513);
    env = stack[-12];
    stack[-9] = v_31513;
    v_31513 = stack[-9];
    if (v_31513 == nil) goto v_31178;
    else goto v_31179;
v_31178:
    v_31513 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_31513;
    goto v_31198;
v_31194:
    v_31513 = stack[-11];
    if (v_31513 == nil) goto v_31203;
    v_31513 = stack[-10];
    v_31513 = qcdr(v_31513);
    v_31513 = qcdr(v_31513);
    goto v_31201;
v_31203:
    v_31513 = stack[-10];
    v_31513 = qcdr(v_31513);
    goto v_31201;
    v_31513 = nil;
v_31201:
    v_31514 = Llength(nil, v_31513);
    env = stack[-12];
    goto v_31195;
v_31196:
    v_31513 = stack[-3];
    goto v_31197;
v_31198:
    goto v_31194;
v_31195:
    goto v_31196;
v_31197:
    v_31513 = difference2(v_31514, v_31513);
    env = stack[-12];
    v_31513 = Lminusp(nil, v_31513);
    env = stack[-12];
    if (v_31513 == nil) goto v_31191;
    v_31513 = nil;
    goto v_31185;
v_31191:
    v_31513 = stack[-3];
    v_31513 = ncons(v_31513);
    env = stack[-12];
    stack[-1] = v_31513;
    stack[-2] = v_31513;
v_31186:
    v_31513 = stack[-3];
    v_31513 = add1(v_31513);
    env = stack[-12];
    stack[-3] = v_31513;
    goto v_31228;
v_31224:
    v_31513 = stack[-11];
    if (v_31513 == nil) goto v_31233;
    v_31513 = stack[-10];
    v_31513 = qcdr(v_31513);
    v_31513 = qcdr(v_31513);
    goto v_31231;
v_31233:
    v_31513 = stack[-10];
    v_31513 = qcdr(v_31513);
    goto v_31231;
    v_31513 = nil;
v_31231:
    v_31514 = Llength(nil, v_31513);
    env = stack[-12];
    goto v_31225;
v_31226:
    v_31513 = stack[-3];
    goto v_31227;
v_31228:
    goto v_31224;
v_31225:
    goto v_31226;
v_31227:
    v_31513 = difference2(v_31514, v_31513);
    env = stack[-12];
    v_31513 = Lminusp(nil, v_31513);
    env = stack[-12];
    if (v_31513 == nil) goto v_31221;
    v_31513 = stack[-2];
    goto v_31185;
v_31221:
    goto v_31249;
v_31245:
    stack[0] = stack[-1];
    goto v_31246;
v_31247:
    v_31513 = stack[-3];
    v_31513 = ncons(v_31513);
    env = stack[-12];
    goto v_31248;
v_31249:
    goto v_31245;
v_31246:
    goto v_31247;
v_31248:
    v_31513 = Lrplacd(nil, stack[0], v_31513);
    env = stack[-12];
    v_31513 = stack[-1];
    v_31513 = qcdr(v_31513);
    stack[-1] = v_31513;
    goto v_31186;
v_31185:
    stack[-9] = v_31513;
    v_31513 = stack[-10];
    v_31513 = qcar(v_31513);
    if (!symbolp(v_31513)) v_31513 = nil;
    else { v_31513 = qfastgets(v_31513);
           if (v_31513 != nil) { v_31513 = elt(v_31513, 43); // symmetric
#ifdef RECORD_GET
             if (v_31513 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v_31513 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v_31513 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v_31513 == SPID_NOPROP) v_31513 = nil; else v_31513 = lisp_true; }}
#endif
    if (v_31513 == nil) goto v_31258;
    goto v_31267;
v_31263:
    v_31514 = elt(env, 5); // !+
    goto v_31264;
v_31265:
    v_31513 = stack[-9];
    goto v_31266;
v_31267:
    goto v_31263;
v_31264:
    goto v_31265;
v_31266:
    v_31513 = cons(v_31514, v_31513);
    env = stack[-12];
    stack[-9] = v_31513;
    goto v_31256;
v_31258:
    goto v_31277;
v_31273:
    v_31513 = stack[-10];
    v_31514 = qcar(v_31513);
    goto v_31274;
v_31275:
    v_31513 = elt(env, 6); // antisymmetric
    goto v_31276;
v_31277:
    goto v_31273;
v_31274:
    goto v_31275;
v_31276:
    v_31513 = Lflagp(nil, v_31514, v_31513);
    env = stack[-12];
    if (v_31513 == nil) goto v_31271;
    goto v_31286;
v_31282:
    v_31514 = elt(env, 7); // !-
    goto v_31283;
v_31284:
    v_31513 = stack[-9];
    goto v_31285;
v_31286:
    goto v_31282;
v_31283:
    goto v_31284;
v_31285:
    v_31513 = cons(v_31514, v_31513);
    env = stack[-12];
    stack[-9] = v_31513;
    goto v_31256;
v_31271:
    goto v_31296;
v_31292:
    v_31514 = elt(env, 3); // !*
    goto v_31293;
v_31294:
    v_31513 = stack[-9];
    goto v_31295;
v_31296:
    goto v_31292;
v_31293:
    goto v_31294;
v_31295:
    v_31513 = cons(v_31514, v_31513);
    env = stack[-12];
    stack[-9] = v_31513;
    goto v_31256;
v_31256:
    goto v_31177;
v_31179:
v_31177:
    v_31513 = stack[-11];
    if (v_31513 == nil) goto v_31305;
    v_31513 = stack[-10];
    v_31513 = qcdr(v_31513);
    v_31513 = qcdr(v_31513);
    goto v_31303;
v_31305:
    v_31513 = stack[-10];
    v_31513 = qcdr(v_31513);
    goto v_31303;
    v_31513 = nil;
v_31303:
    v_31513 = Llength(nil, v_31513);
    env = stack[-12];
    v_31513 = sub1(v_31513);
    env = stack[-12];
    v_31513 = Lmkvect(nil, v_31513);
    env = stack[-12];
    stack[-8] = v_31513;
    v_31513 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_31513;
    v_31513 = stack[-11];
    if (v_31513 == nil) goto v_31322;
    v_31513 = stack[-10];
    v_31513 = qcdr(v_31513);
    v_31513 = qcdr(v_31513);
    goto v_31320;
v_31322:
    v_31513 = stack[-10];
    v_31513 = qcdr(v_31513);
    goto v_31320;
    v_31513 = nil;
v_31320:
    stack[-4] = v_31513;
v_31318:
    v_31513 = stack[-4];
    if (v_31513 == nil) goto v_31333;
    else goto v_31334;
v_31333:
    goto v_31317;
v_31334:
    v_31513 = stack[-4];
    v_31513 = qcar(v_31513);
    stack[-1] = v_31513;
    v_31513 = stack[-7];
    v_31513 = add1(v_31513);
    env = stack[-12];
    stack[-7] = v_31513;
    v_31513 = stack[-1];
    fn = elt(env, 11); // dummyp
    v_31513 = (*qfn1(fn))(fn, v_31513);
    env = stack[-12];
    stack[-6] = v_31513;
    if (v_31513 == nil) goto v_31345;
    goto v_31353;
v_31349:
    v_31514 = stack[-5];
    goto v_31350;
v_31351:
    v_31513 = stack[-6];
    goto v_31352;
v_31353:
    goto v_31349;
v_31350:
    goto v_31351;
v_31352:
    fn = elt(env, 12); // max
    v_31513 = (*qfn2(fn))(fn, v_31514, v_31513);
    env = stack[-12];
    stack[-5] = v_31513;
    v_31513 = stack[-1];
    if (symbolp(v_31513)) goto v_31358;
    else goto v_31359;
v_31358:
    goto v_31367;
v_31361:
    stack[-3] = stack[-8];
    goto v_31362;
v_31363:
    v_31513 = stack[-7];
    stack[-2] = sub1(v_31513);
    env = stack[-12];
    goto v_31364;
v_31365:
    goto v_31378;
v_31372:
    stack[-1] = elt(env, 2); // !~dv
    goto v_31373;
v_31374:
    stack[0] = elt(env, 3); // !*
    goto v_31375;
v_31376:
    v_31513 = stack[-6];
    v_31513 = ncons(v_31513);
    env = stack[-12];
    goto v_31377;
v_31378:
    goto v_31372;
v_31373:
    goto v_31374;
v_31375:
    goto v_31376;
v_31377:
    v_31513 = list2star(stack[-1], stack[0], v_31513);
    env = stack[-12];
    goto v_31366;
v_31367:
    goto v_31361;
v_31362:
    goto v_31363;
v_31364:
    goto v_31365;
v_31366:
    *(LispObject *)((char *)stack[-3] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-2]-TAG_FIXNUM)/(16/CELL))) = v_31513;
    goto v_31357;
v_31359:
    goto v_31391;
v_31385:
    stack[-3] = stack[-8];
    goto v_31386;
v_31387:
    v_31513 = stack[-7];
    stack[-2] = sub1(v_31513);
    env = stack[-12];
    goto v_31388;
v_31389:
    goto v_31402;
v_31396:
    stack[-1] = elt(env, 8); // !~dva
    goto v_31397;
v_31398:
    stack[0] = elt(env, 3); // !*
    goto v_31399;
v_31400:
    v_31513 = stack[-6];
    v_31513 = ncons(v_31513);
    env = stack[-12];
    goto v_31401;
v_31402:
    goto v_31396;
v_31397:
    goto v_31398;
v_31399:
    goto v_31400;
v_31401:
    v_31513 = list2star(stack[-1], stack[0], v_31513);
    env = stack[-12];
    goto v_31390;
v_31391:
    goto v_31385;
v_31386:
    goto v_31387;
v_31388:
    goto v_31389;
v_31390:
    *(LispObject *)((char *)stack[-3] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-2]-TAG_FIXNUM)/(16/CELL))) = v_31513;
    goto v_31357;
v_31357:
    goto v_31343;
v_31345:
    goto v_31415;
v_31409:
    stack[-2] = stack[-8];
    goto v_31410;
v_31411:
    v_31513 = stack[-7];
    stack[0] = sub1(v_31513);
    env = stack[-12];
    goto v_31412;
v_31413:
    v_31513 = stack[-1];
    v_31513 = ncons(v_31513);
    env = stack[-12];
    goto v_31414;
v_31415:
    goto v_31409;
v_31410:
    goto v_31411;
v_31412:
    goto v_31413;
v_31414:
    *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_31513;
    goto v_31343;
v_31343:
    v_31513 = stack[-4];
    v_31513 = qcdr(v_31513);
    stack[-4] = v_31513;
    goto v_31318;
v_31317:
    goto v_31431;
v_31425:
    v_31515 = stack[-9];
    goto v_31426;
v_31427:
    v_31514 = stack[-8];
    goto v_31428;
v_31429:
    v_31513 = elt(env, 9); // idcons_ordp
    goto v_31430;
v_31431:
    goto v_31425;
v_31426:
    goto v_31427;
v_31428:
    goto v_31429;
v_31430:
    fn = elt(env, 13); // st_sorttree
    v_31513 = (*qfnn(fn))(fn, 3, v_31515, v_31514, v_31513);
    env = stack[-12];
    stack[-9] = v_31513;
    v_31513 = stack[-9];
    if (v_31513 == nil) goto v_31438;
    goto v_31446;
v_31442:
    v_31513 = stack[-9];
    v_31514 = qcar(v_31513);
    goto v_31443;
v_31444:
    v_31513 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31445;
v_31446:
    goto v_31442;
v_31443:
    goto v_31444;
v_31445:
    if (v_31514 == v_31513) goto v_31441;
    else goto v_31438;
v_31441:
    v_31513 = nil;
    goto v_31069;
v_31438:
    v_31513 = stack[-9];
    v_31513 = qcar(v_31513);
    stack[0] = v_31513;
    goto v_31458;
v_31454:
    v_31513 = stack[-9];
    v_31514 = qcdr(v_31513);
    goto v_31455;
v_31456:
    v_31513 = stack[-8];
    goto v_31457;
v_31458:
    goto v_31454;
v_31455:
    goto v_31456;
v_31457:
    fn = elt(env, 14); // dv_skelsplit1
    v_31513 = (*qfn2(fn))(fn, v_31514, v_31513);
    env = stack[-12];
    stack[-1] = v_31513;
    v_31513 = stack[-1];
    v_31513 = qcdr(v_31513);
    fn = elt(env, 15); // st_consolidate
    v_31513 = (*qfn1(fn))(fn, v_31513);
    env = stack[-12];
    stack[-9] = v_31513;
    v_31513 = stack[-11];
    if (v_31513 == nil) goto v_31468;
    goto v_31477;
v_31471:
    v_31513 = stack[-10];
    v_31515 = qcar(v_31513);
    goto v_31472;
v_31473:
    v_31514 = stack[-11];
    goto v_31474;
v_31475:
    v_31513 = stack[-1];
    v_31513 = qcar(v_31513);
    goto v_31476;
v_31477:
    goto v_31471;
v_31472:
    goto v_31473;
v_31474:
    goto v_31475;
v_31476:
    v_31513 = list2star(v_31515, v_31514, v_31513);
    env = stack[-12];
    goto v_31466;
v_31468:
    goto v_31490;
v_31486:
    v_31513 = stack[-10];
    v_31514 = qcar(v_31513);
    goto v_31487;
v_31488:
    v_31513 = stack[-1];
    v_31513 = qcar(v_31513);
    goto v_31489;
v_31490:
    goto v_31486;
v_31487:
    goto v_31488;
v_31489:
    v_31513 = cons(v_31514, v_31513);
    env = stack[-12];
    goto v_31466;
    v_31513 = nil;
v_31466:
    stack[-1] = v_31513;
    goto v_31502;
v_31496:
    goto v_31497;
v_31498:
    stack[-2] = stack[-5];
    goto v_31499;
v_31500:
    goto v_31510;
v_31506:
    v_31514 = stack[-1];
    goto v_31507;
v_31508:
    v_31513 = stack[-9];
    goto v_31509;
v_31510:
    goto v_31506;
v_31507:
    goto v_31508;
v_31509:
    v_31513 = cons(v_31514, v_31513);
    goto v_31501;
v_31502:
    goto v_31496;
v_31497:
    goto v_31498;
v_31499:
    goto v_31500;
v_31501:
    {
        LispObject v_31532 = stack[0];
        LispObject v_31533 = stack[-2];
        return list3(v_31532, v_31533, v_31513);
    }
v_31069:
    return onevalue(v_31513);
}



// Code for small!-random!-number

static LispObject CC_smallKrandomKnumber(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31146, v_31147;
    LispObject fn;
    argcheck(nargs, 0, "small-random-number");
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
    goto v_31067;
v_31063:
    fn = elt(env, 4); // next!-random!-number
    v_31147 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_31064;
v_31065:
    v_31146 = (LispObject)16000+TAG_FIXNUM; // 1000
    goto v_31066;
v_31067:
    goto v_31063;
v_31064:
    goto v_31065;
v_31066:
    v_31146 = Cremainder(v_31147, v_31146);
    env = stack[-3];
    stack[-2] = v_31146;
    goto v_31075;
v_31071:
    goto v_31081;
v_31077:
    fn = elt(env, 4); // next!-random!-number
    v_31147 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_31078;
v_31079:
    v_31146 = (LispObject)16000+TAG_FIXNUM; // 1000
    goto v_31080;
v_31081:
    goto v_31077;
v_31078:
    goto v_31079;
v_31080:
    stack[0] = Cremainder(v_31147, v_31146);
    env = stack[-3];
    goto v_31072;
v_31073:
    goto v_31089;
v_31085:
    v_31147 = (LispObject)16000+TAG_FIXNUM; // 1000
    goto v_31086;
v_31087:
    v_31146 = stack[-2];
    goto v_31088;
v_31089:
    goto v_31085;
v_31086:
    goto v_31087;
v_31088:
    v_31146 = times2(v_31147, v_31146);
    env = stack[-3];
    goto v_31074;
v_31075:
    goto v_31071;
v_31072:
    goto v_31073;
v_31074:
    v_31146 = plus2(stack[0], v_31146);
    env = stack[-3];
    stack[-2] = v_31146;
    goto v_31101;
v_31097:
    v_31147 = stack[-2];
    goto v_31098;
v_31099:
    v_31146 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31100;
v_31101:
    goto v_31097;
v_31098:
    goto v_31099;
v_31100:
    v_31146 = (LispObject)lessp2(v_31147, v_31146);
    v_31146 = v_31146 ? lisp_true : nil;
    env = stack[-3];
    if (v_31146 == nil) goto v_31095;
    goto v_31109;
v_31105:
    v_31147 = stack[-2];
    goto v_31106;
v_31107:
    v_31146 = (LispObject)16000000+TAG_FIXNUM; // 1000000
    goto v_31108;
v_31109:
    goto v_31105;
v_31106:
    goto v_31107;
v_31108:
    v_31146 = plus2(v_31147, v_31146);
    env = stack[-3];
    stack[-2] = v_31146;
    goto v_31093;
v_31095:
v_31093:
    goto v_31117;
v_31113:
    stack[-1] = elt(env, 1); // 1.0
    goto v_31114;
v_31115:
    goto v_31124;
v_31120:
    stack[0] = elt(env, 2); // 1.5
    goto v_31121;
v_31122:
    goto v_31131;
v_31127:
    v_31146 = stack[-2];
    v_31147 = Lfloat(nil, v_31146);
    env = stack[-3];
    goto v_31128;
v_31129:
    v_31146 = elt(env, 3); // 1.0e+06
    goto v_31130;
v_31131:
    goto v_31127;
v_31128:
    goto v_31129;
v_31130:
    v_31146 = quot2(v_31147, v_31146);
    env = stack[-3];
    goto v_31123;
v_31124:
    goto v_31120;
v_31121:
    goto v_31122;
v_31123:
    v_31146 = times2(stack[0], v_31146);
    env = stack[-3];
    goto v_31116;
v_31117:
    goto v_31113;
v_31114:
    goto v_31115;
v_31116:
    v_31146 = plus2(stack[-1], v_31146);
    env = stack[-3];
    stack[-2] = v_31146;
    goto v_31140;
v_31136:
    v_31147 = stack[-2];
    goto v_31137;
v_31138:
    v_31146 = stack[-2];
    goto v_31139;
v_31140:
    goto v_31136;
v_31137:
    goto v_31138;
v_31139:
    v_31146 = times2(v_31147, v_31146);
    env = stack[-3];
    stack[-2] = v_31146;
    v_31146 = stack[-2];
    fn = elt(env, 5); // exp
    v_31146 = (*qfn1(fn))(fn, v_31146);
        return Ltruncate(nil, v_31146);
    return onevalue(v_31146);
}



// Code for ofsf_smmkatl!-or

static LispObject CC_ofsf_smmkatlKor(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31187, v_31188, v_31189;
    LispObject fn;
    LispObject v_31060, v_31059, v_31058;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_smmkatl-or");
    va_start(aa, nargs);
    v_31058 = va_arg(aa, LispObject);
    v_31059 = va_arg(aa, LispObject);
    v_31060 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31060,v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31058,v_31059,v_31060);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_31060;
    v_31187 = v_31059;
    stack[-4] = v_31058;
// end of prologue
    stack[-5] = v_31187;
v_31070:
    v_31187 = stack[-5];
    if (v_31187 == nil) goto v_31075;
    else goto v_31076;
v_31075:
    v_31187 = nil;
    goto v_31069;
v_31076:
    v_31187 = stack[-5];
    v_31187 = qcar(v_31187);
    goto v_31086;
v_31082:
    v_31188 = v_31187;
    v_31189 = qcar(v_31188);
    goto v_31083;
v_31084:
    v_31188 = stack[-4];
    goto v_31085;
v_31086:
    goto v_31082;
v_31083:
    goto v_31084;
v_31085:
    v_31188 = Latsoc(nil, v_31189, v_31188);
    v_31189 = v_31188;
    v_31188 = v_31189;
    if (v_31188 == nil) goto v_31093;
    else goto v_31094;
v_31093:
    goto v_31103;
v_31097:
    v_31188 = elt(env, 1); // or
    goto v_31098;
v_31099:
    v_31189 = v_31187;
    goto v_31100;
v_31101:
    v_31187 = stack[-3];
    goto v_31102;
v_31103:
    goto v_31097;
v_31098:
    goto v_31099;
v_31100:
    goto v_31101;
v_31102:
    fn = elt(env, 2); // ofsf_ir2atl
    v_31187 = (*qfnn(fn))(fn, 3, v_31188, v_31189, v_31187);
    env = stack[-6];
    goto v_31092;
v_31094:
    goto v_31116;
v_31110:
    goto v_31111;
v_31112:
    v_31188 = v_31187;
    goto v_31113;
v_31114:
    v_31187 = stack[-3];
    goto v_31115;
v_31116:
    goto v_31110;
v_31111:
    goto v_31112;
v_31113:
    goto v_31114;
v_31115:
    fn = elt(env, 3); // ofsf_smmkatl!-or1
    v_31187 = (*qfnn(fn))(fn, 3, v_31189, v_31188, v_31187);
    env = stack[-6];
    goto v_31092;
    v_31187 = nil;
v_31092:
    stack[-2] = v_31187;
    v_31187 = stack[-2];
    fn = elt(env, 4); // lastpair
    v_31187 = (*qfn1(fn))(fn, v_31187);
    env = stack[-6];
    stack[-1] = v_31187;
    v_31187 = stack[-5];
    v_31187 = qcdr(v_31187);
    stack[-5] = v_31187;
    v_31187 = stack[-1];
    if (!consp(v_31187)) goto v_31126;
    else goto v_31127;
v_31126:
    goto v_31070;
v_31127:
v_31071:
    v_31187 = stack[-5];
    if (v_31187 == nil) goto v_31131;
    else goto v_31132;
v_31131:
    v_31187 = stack[-2];
    goto v_31069;
v_31132:
    goto v_31140;
v_31136:
    stack[0] = stack[-1];
    goto v_31137;
v_31138:
    v_31187 = stack[-5];
    v_31187 = qcar(v_31187);
    goto v_31149;
v_31145:
    v_31188 = v_31187;
    v_31189 = qcar(v_31188);
    goto v_31146;
v_31147:
    v_31188 = stack[-4];
    goto v_31148;
v_31149:
    goto v_31145;
v_31146:
    goto v_31147;
v_31148:
    v_31188 = Latsoc(nil, v_31189, v_31188);
    v_31189 = v_31188;
    v_31188 = v_31189;
    if (v_31188 == nil) goto v_31156;
    else goto v_31157;
v_31156:
    goto v_31166;
v_31160:
    v_31189 = elt(env, 1); // or
    goto v_31161;
v_31162:
    v_31188 = v_31187;
    goto v_31163;
v_31164:
    v_31187 = stack[-3];
    goto v_31165;
v_31166:
    goto v_31160;
v_31161:
    goto v_31162;
v_31163:
    goto v_31164;
v_31165:
    fn = elt(env, 2); // ofsf_ir2atl
    v_31187 = (*qfnn(fn))(fn, 3, v_31189, v_31188, v_31187);
    env = stack[-6];
    goto v_31155;
v_31157:
    goto v_31179;
v_31173:
    goto v_31174;
v_31175:
    v_31188 = v_31187;
    goto v_31176;
v_31177:
    v_31187 = stack[-3];
    goto v_31178;
v_31179:
    goto v_31173;
v_31174:
    goto v_31175;
v_31176:
    goto v_31177;
v_31178:
    fn = elt(env, 3); // ofsf_smmkatl!-or1
    v_31187 = (*qfnn(fn))(fn, 3, v_31189, v_31188, v_31187);
    env = stack[-6];
    goto v_31155;
    v_31187 = nil;
v_31155:
    goto v_31139;
v_31140:
    goto v_31136;
v_31137:
    goto v_31138;
v_31139:
    v_31187 = Lrplacd(nil, stack[0], v_31187);
    env = stack[-6];
    v_31187 = stack[-1];
    fn = elt(env, 4); // lastpair
    v_31187 = (*qfn1(fn))(fn, v_31187);
    env = stack[-6];
    stack[-1] = v_31187;
    v_31187 = stack[-5];
    v_31187 = qcdr(v_31187);
    stack[-5] = v_31187;
    goto v_31071;
v_31069:
    return onevalue(v_31187);
}



// Code for giprim

static LispObject CC_giprim(LispObject env,
                         LispObject v_31058)
{
    env = qenv(env);
    LispObject v_31085, v_31086, v_31087;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31087 = v_31058;
// end of prologue
    goto v_31068;
v_31064:
    v_31086 = v_31087;
    goto v_31065;
v_31066:
    v_31085 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31067;
v_31068:
    goto v_31064;
v_31065:
    goto v_31066;
v_31067:
    if (v_31086 == v_31085) goto v_31062;
    else goto v_31063;
v_31062:
    v_31085 = elt(env, 1); // i
    goto v_31061;
v_31063:
    goto v_31081;
v_31075:
    v_31085 = elt(env, 2); // times
    goto v_31076;
v_31077:
    v_31086 = v_31087;
    goto v_31078;
v_31079:
    v_31087 = elt(env, 1); // i
    goto v_31080;
v_31081:
    goto v_31075;
v_31076:
    goto v_31077;
v_31078:
    goto v_31079;
v_31080:
    return list3(v_31085, v_31086, v_31087);
    v_31085 = nil;
v_31061:
    return onevalue(v_31085);
}



// Code for mk_resimp_rep

static LispObject CC_mk_resimp_rep(LispObject env,
                         LispObject v_31058)
{
    env = qenv(env);
    LispObject v_31147, v_31148;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31058);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_31058;
// end of prologue
    v_31147 = stack[-5];
    fn = elt(env, 1); // get_group_in
    v_31147 = (*qfn1(fn))(fn, v_31147);
    env = stack[-7];
    stack[-6] = v_31147;
    v_31147 = stack[-6];
    fn = elt(env, 2); // get!*elements
    v_31147 = (*qfn1(fn))(fn, v_31147);
    env = stack[-7];
    stack[-4] = v_31147;
    v_31147 = stack[-4];
    if (v_31147 == nil) goto v_31077;
    else goto v_31078;
v_31077:
    v_31147 = nil;
    goto v_31071;
v_31078:
    v_31147 = stack[-4];
    v_31147 = qcar(v_31147);
    goto v_31090;
v_31086:
    stack[0] = v_31147;
    goto v_31087;
v_31088:
    goto v_31098;
v_31094:
    v_31148 = v_31147;
    goto v_31095;
v_31096:
    v_31147 = stack[-5];
    goto v_31097;
v_31098:
    goto v_31094;
v_31095:
    goto v_31096;
v_31097:
    fn = elt(env, 3); // get_rep_matrix_in
    v_31147 = (*qfn2(fn))(fn, v_31148, v_31147);
    env = stack[-7];
    fn = elt(env, 4); // mk!+resimp!+mat
    v_31147 = (*qfn1(fn))(fn, v_31147);
    env = stack[-7];
    goto v_31089;
v_31090:
    goto v_31086;
v_31087:
    goto v_31088;
v_31089:
    v_31147 = list2(stack[0], v_31147);
    env = stack[-7];
    v_31147 = ncons(v_31147);
    env = stack[-7];
    stack[-2] = v_31147;
    stack[-3] = v_31147;
v_31072:
    v_31147 = stack[-4];
    v_31147 = qcdr(v_31147);
    stack[-4] = v_31147;
    v_31147 = stack[-4];
    if (v_31147 == nil) goto v_31105;
    else goto v_31106;
v_31105:
    v_31147 = stack[-3];
    goto v_31071;
v_31106:
    goto v_31114;
v_31110:
    stack[-1] = stack[-2];
    goto v_31111;
v_31112:
    v_31147 = stack[-4];
    v_31147 = qcar(v_31147);
    goto v_31125;
v_31121:
    stack[0] = v_31147;
    goto v_31122;
v_31123:
    goto v_31133;
v_31129:
    v_31148 = v_31147;
    goto v_31130;
v_31131:
    v_31147 = stack[-5];
    goto v_31132;
v_31133:
    goto v_31129;
v_31130:
    goto v_31131;
v_31132:
    fn = elt(env, 3); // get_rep_matrix_in
    v_31147 = (*qfn2(fn))(fn, v_31148, v_31147);
    env = stack[-7];
    fn = elt(env, 4); // mk!+resimp!+mat
    v_31147 = (*qfn1(fn))(fn, v_31147);
    env = stack[-7];
    goto v_31124;
v_31125:
    goto v_31121;
v_31122:
    goto v_31123;
v_31124:
    v_31147 = list2(stack[0], v_31147);
    env = stack[-7];
    v_31147 = ncons(v_31147);
    env = stack[-7];
    goto v_31113;
v_31114:
    goto v_31110;
v_31111:
    goto v_31112;
v_31113:
    v_31147 = Lrplacd(nil, stack[-1], v_31147);
    env = stack[-7];
    v_31147 = stack[-2];
    v_31147 = qcdr(v_31147);
    stack[-2] = v_31147;
    goto v_31072;
v_31071:
    stack[0] = v_31147;
    goto v_31143;
v_31139:
    v_31147 = stack[-6];
    v_31148 = ncons(v_31147);
    goto v_31140;
v_31141:
    v_31147 = stack[0];
    goto v_31142;
v_31143:
    goto v_31139;
v_31140:
    goto v_31141;
v_31142:
        return Lappend(nil, v_31148, v_31147);
    return onevalue(v_31147);
}



// Code for talp_try1

static LispObject CC_talp_try1(LispObject env,
                         LispObject v_31058)
{
    env = qenv(env);
    LispObject v_31285, v_31286, v_31287;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31058);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_31286 = v_31058;
// end of prologue
    v_31285 = v_31286;
    if (!consp(v_31285)) goto v_31066;
    else goto v_31067;
v_31066:
    v_31285 = v_31286;
    goto v_31063;
v_31067:
    v_31285 = v_31286;
    fn = elt(env, 5); // talp_rnf
    v_31285 = (*qfn1(fn))(fn, v_31285);
    env = stack[-5];
    stack[0] = v_31285;
    goto v_31088;
v_31084:
    v_31286 = stack[0];
    goto v_31085;
v_31086:
    v_31285 = elt(env, 1); // true
    goto v_31087;
v_31088:
    goto v_31084;
v_31085:
    goto v_31086;
v_31087:
    if (v_31286 == v_31285) goto v_31082;
    else goto v_31083;
v_31082:
    v_31285 = lisp_true;
    goto v_31081;
v_31083:
    goto v_31098;
v_31094:
    v_31286 = stack[0];
    goto v_31095;
v_31096:
    v_31285 = elt(env, 2); // false
    goto v_31097;
v_31098:
    goto v_31094;
v_31095:
    goto v_31096;
v_31097:
    v_31285 = (v_31286 == v_31285 ? lisp_true : nil);
    goto v_31081;
    v_31285 = nil;
v_31081:
    if (v_31285 == nil) goto v_31079;
    v_31285 = lisp_true;
    goto v_31077;
v_31079:
    v_31285 = stack[0];
    fn = elt(env, 6); // talp_atfp
    v_31285 = (*qfn1(fn))(fn, v_31285);
    env = stack[-5];
    goto v_31077;
    v_31285 = nil;
v_31077:
    if (v_31285 == nil) goto v_31075;
    v_31285 = stack[0];
    goto v_31063;
v_31075:
    v_31285 = stack[0];
    fn = elt(env, 7); // talp_op
    v_31285 = (*qfn1(fn))(fn, v_31285);
    env = stack[-5];
    v_31287 = v_31285;
    goto v_31118;
v_31114:
    v_31286 = v_31287;
    goto v_31115;
v_31116:
    v_31285 = elt(env, 3); // or
    goto v_31117;
v_31118:
    goto v_31114;
v_31115:
    goto v_31116;
v_31117:
    if (v_31286 == v_31285) goto v_31112;
    else goto v_31113;
v_31112:
    goto v_31128;
v_31122:
    goto v_31136;
v_31132:
    stack[-4] = elt(env, 4); // and
    goto v_31133;
v_31134:
    v_31285 = stack[0];
    fn = elt(env, 8); // talp_argl
    v_31285 = (*qfn1(fn))(fn, v_31285);
    env = stack[-5];
    stack[-3] = v_31285;
    v_31285 = stack[-3];
    if (v_31285 == nil) goto v_31148;
    else goto v_31149;
v_31148:
    v_31285 = nil;
    goto v_31142;
v_31149:
    v_31285 = stack[-3];
    v_31285 = qcar(v_31285);
    fn = elt(env, 9); // cl_nnfnot
    v_31285 = (*qfn1(fn))(fn, v_31285);
    env = stack[-5];
    v_31285 = CC_talp_try1(elt(env, 0), v_31285);
    env = stack[-5];
    v_31285 = ncons(v_31285);
    env = stack[-5];
    stack[-1] = v_31285;
    stack[-2] = v_31285;
v_31143:
    v_31285 = stack[-3];
    v_31285 = qcdr(v_31285);
    stack[-3] = v_31285;
    v_31285 = stack[-3];
    if (v_31285 == nil) goto v_31163;
    else goto v_31164;
v_31163:
    v_31285 = stack[-2];
    goto v_31142;
v_31164:
    goto v_31172;
v_31168:
    stack[0] = stack[-1];
    goto v_31169;
v_31170:
    v_31285 = stack[-3];
    v_31285 = qcar(v_31285);
    fn = elt(env, 9); // cl_nnfnot
    v_31285 = (*qfn1(fn))(fn, v_31285);
    env = stack[-5];
    v_31285 = CC_talp_try1(elt(env, 0), v_31285);
    env = stack[-5];
    v_31285 = ncons(v_31285);
    env = stack[-5];
    goto v_31171;
v_31172:
    goto v_31168;
v_31169:
    goto v_31170;
v_31171:
    v_31285 = Lrplacd(nil, stack[0], v_31285);
    env = stack[-5];
    v_31285 = stack[-1];
    v_31285 = qcdr(v_31285);
    stack[-1] = v_31285;
    goto v_31143;
v_31142:
    goto v_31135;
v_31136:
    goto v_31132;
v_31133:
    goto v_31134;
v_31135:
    v_31285 = cons(stack[-4], v_31285);
    env = stack[-5];
    fn = elt(env, 10); // talp_try2
    v_31285 = (*qfn1(fn))(fn, v_31285);
    env = stack[-5];
    fn = elt(env, 9); // cl_nnfnot
    v_31287 = (*qfn1(fn))(fn, v_31285);
    env = stack[-5];
    goto v_31123;
v_31124:
    v_31286 = nil;
    goto v_31125;
v_31126:
    v_31285 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_31127;
v_31128:
    goto v_31122;
v_31123:
    goto v_31124;
v_31125:
    goto v_31126;
v_31127:
    {
        fn = elt(env, 11); // cl_simpl
        return (*qfnn(fn))(fn, 3, v_31287, v_31286, v_31285);
    }
v_31113:
    goto v_31191;
v_31187:
    v_31286 = v_31287;
    goto v_31188;
v_31189:
    v_31285 = elt(env, 4); // and
    goto v_31190;
v_31191:
    goto v_31187;
v_31188:
    goto v_31189;
v_31190:
    if (v_31286 == v_31285) goto v_31185;
    else goto v_31186;
v_31185:
    goto v_31201;
v_31195:
    goto v_31208;
v_31204:
    stack[-4] = v_31287;
    goto v_31205;
v_31206:
    v_31285 = stack[0];
    fn = elt(env, 8); // talp_argl
    v_31285 = (*qfn1(fn))(fn, v_31285);
    env = stack[-5];
    stack[-3] = v_31285;
    v_31285 = stack[-3];
    if (v_31285 == nil) goto v_31220;
    else goto v_31221;
v_31220:
    v_31285 = nil;
    goto v_31214;
v_31221:
    v_31285 = stack[-3];
    v_31285 = qcar(v_31285);
    v_31285 = CC_talp_try1(elt(env, 0), v_31285);
    env = stack[-5];
    v_31285 = ncons(v_31285);
    env = stack[-5];
    stack[-1] = v_31285;
    stack[-2] = v_31285;
v_31215:
    v_31285 = stack[-3];
    v_31285 = qcdr(v_31285);
    stack[-3] = v_31285;
    v_31285 = stack[-3];
    if (v_31285 == nil) goto v_31234;
    else goto v_31235;
v_31234:
    v_31285 = stack[-2];
    goto v_31214;
v_31235:
    goto v_31243;
v_31239:
    stack[0] = stack[-1];
    goto v_31240;
v_31241:
    v_31285 = stack[-3];
    v_31285 = qcar(v_31285);
    v_31285 = CC_talp_try1(elt(env, 0), v_31285);
    env = stack[-5];
    v_31285 = ncons(v_31285);
    env = stack[-5];
    goto v_31242;
v_31243:
    goto v_31239;
v_31240:
    goto v_31241;
v_31242:
    v_31285 = Lrplacd(nil, stack[0], v_31285);
    env = stack[-5];
    v_31285 = stack[-1];
    v_31285 = qcdr(v_31285);
    stack[-1] = v_31285;
    goto v_31215;
v_31214:
    goto v_31207;
v_31208:
    goto v_31204;
v_31205:
    goto v_31206;
v_31207:
    v_31285 = cons(stack[-4], v_31285);
    env = stack[-5];
    fn = elt(env, 10); // talp_try2
    v_31287 = (*qfn1(fn))(fn, v_31285);
    env = stack[-5];
    goto v_31196;
v_31197:
    v_31286 = nil;
    goto v_31198;
v_31199:
    v_31285 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_31200;
v_31201:
    goto v_31195;
v_31196:
    goto v_31197;
v_31198:
    goto v_31199;
v_31200:
    {
        fn = elt(env, 11); // cl_simpl
        return (*qfnn(fn))(fn, 3, v_31287, v_31286, v_31285);
    }
v_31186:
    goto v_31264;
v_31258:
    goto v_31272;
v_31266:
    stack[-2] = v_31287;
    goto v_31267;
v_31268:
    v_31285 = stack[0];
    v_31285 = qcdr(v_31285);
    stack[-1] = qcar(v_31285);
    goto v_31269;
v_31270:
    v_31285 = stack[0];
    v_31285 = qcdr(v_31285);
    v_31285 = qcdr(v_31285);
    v_31285 = qcar(v_31285);
    v_31285 = CC_talp_try1(elt(env, 0), v_31285);
    env = stack[-5];
    v_31285 = ncons(v_31285);
    env = stack[-5];
    goto v_31271;
v_31272:
    goto v_31266;
v_31267:
    goto v_31268;
v_31269:
    goto v_31270;
v_31271:
    v_31287 = list2star(stack[-2], stack[-1], v_31285);
    env = stack[-5];
    goto v_31259;
v_31260:
    v_31286 = nil;
    goto v_31261;
v_31262:
    v_31285 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_31263;
v_31264:
    goto v_31258;
v_31259:
    goto v_31260;
v_31261:
    goto v_31262;
v_31263:
    {
        fn = elt(env, 11); // cl_simpl
        return (*qfnn(fn))(fn, 3, v_31287, v_31286, v_31285);
    }
    v_31285 = nil;
v_31063:
    return onevalue(v_31285);
}



// Code for qqe_prefix!-length

static LispObject CC_qqe_prefixKlength(LispObject env,
                         LispObject v_31058)
{
    env = qenv(env);
    LispObject v_31107, v_31108, v_31109;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31058);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31108 = v_31058;
// end of prologue
    v_31107 = (LispObject)0+TAG_FIXNUM; // 0
    v_31109 = v_31107;
    v_31107 = v_31108;
    if (v_31107 == nil) goto v_31067;
    else goto v_31068;
v_31067:
    v_31107 = nil;
    stack[0] = v_31107;
    goto v_31066;
v_31068:
    v_31107 = v_31108;
    stack[0] = v_31107;
    goto v_31066;
v_31066:
v_31077:
    v_31107 = stack[0];
    if (v_31107 == nil) goto v_31080;
    v_31107 = stack[0];
    if (!consp(v_31107)) goto v_31080;
    goto v_31081;
v_31080:
    goto v_31076;
v_31081:
    goto v_31095;
v_31091:
    v_31107 = stack[0];
    v_31108 = qcar(v_31107);
    goto v_31092;
v_31093:
    v_31107 = elt(env, 1); // (rtail ltail rhead lhead)
    goto v_31094;
v_31095:
    goto v_31091;
v_31092:
    goto v_31093;
v_31094:
    v_31107 = Lmemq(nil, v_31108, v_31107);
    if (v_31107 == nil) goto v_31090;
    v_31107 = v_31109;
    v_31107 = add1(v_31107);
    env = stack[-1];
    v_31109 = v_31107;
    goto v_31088;
v_31090:
v_31088:
    v_31107 = stack[0];
    v_31107 = qcdr(v_31107);
    v_31107 = qcar(v_31107);
    stack[0] = v_31107;
    goto v_31077;
v_31076:
    v_31107 = v_31109;
    return onevalue(v_31107);
}



// Code for acfsf_varlat

static LispObject CC_acfsf_varlat(LispObject env,
                         LispObject v_31058)
{
    env = qenv(env);
    LispObject v_31063;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31058);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31063 = v_31058;
// end of prologue
    fn = elt(env, 1); // acfsf_arg2l
    v_31063 = (*qfn1(fn))(fn, v_31063);
    env = stack[0];
    {
        fn = elt(env, 2); // kernels
        return (*qfn1(fn))(fn, v_31063);
    }
}



// Code for expvec2a1

static LispObject CC_expvec2a1(LispObject env,
                         LispObject v_31058, LispObject v_31059)
{
    env = qenv(env);
    LispObject v_31135, v_31136, v_31137;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31058,v_31059);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31059;
    stack[-1] = v_31058;
// end of prologue
    stack[-2] = nil;
v_31064:
    v_31135 = stack[-1];
    if (v_31135 == nil) goto v_31067;
    else goto v_31068;
v_31067:
    v_31135 = stack[-2];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_31135);
    }
v_31068:
    goto v_31078;
v_31074:
    v_31135 = stack[-1];
    v_31136 = qcar(v_31135);
    goto v_31075;
v_31076:
    v_31135 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31077;
v_31078:
    goto v_31074;
v_31075:
    goto v_31076;
v_31077:
    if (v_31136 == v_31135) goto v_31072;
    else goto v_31073;
v_31072:
    v_31135 = stack[-1];
    v_31135 = qcdr(v_31135);
    stack[-1] = v_31135;
    v_31135 = stack[0];
    v_31135 = qcdr(v_31135);
    stack[0] = v_31135;
    goto v_31064;
v_31073:
    goto v_31092;
v_31088:
    v_31135 = stack[-1];
    v_31136 = qcar(v_31135);
    goto v_31089;
v_31090:
    v_31135 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31091;
v_31092:
    goto v_31088;
v_31089:
    goto v_31090;
v_31091:
    if (v_31136 == v_31135) goto v_31086;
    else goto v_31087;
v_31086:
    goto v_31101;
v_31097:
    v_31135 = stack[0];
    v_31136 = qcar(v_31135);
    goto v_31098;
v_31099:
    v_31135 = stack[-2];
    goto v_31100;
v_31101:
    goto v_31097;
v_31098:
    goto v_31099;
v_31100:
    v_31135 = cons(v_31136, v_31135);
    env = stack[-3];
    stack[-2] = v_31135;
    v_31135 = stack[-1];
    v_31135 = qcdr(v_31135);
    stack[-1] = v_31135;
    v_31135 = stack[0];
    v_31135 = qcdr(v_31135);
    stack[0] = v_31135;
    goto v_31064;
v_31087:
    goto v_31116;
v_31112:
    goto v_31124;
v_31118:
    v_31137 = elt(env, 1); // expt
    goto v_31119;
v_31120:
    v_31135 = stack[0];
    v_31136 = qcar(v_31135);
    goto v_31121;
v_31122:
    v_31135 = stack[-1];
    v_31135 = qcar(v_31135);
    goto v_31123;
v_31124:
    goto v_31118;
v_31119:
    goto v_31120;
v_31121:
    goto v_31122;
v_31123:
    v_31136 = list3(v_31137, v_31136, v_31135);
    env = stack[-3];
    goto v_31113;
v_31114:
    v_31135 = stack[-2];
    goto v_31115;
v_31116:
    goto v_31112;
v_31113:
    goto v_31114;
v_31115:
    v_31135 = cons(v_31136, v_31135);
    env = stack[-3];
    stack[-2] = v_31135;
    v_31135 = stack[-1];
    v_31135 = qcdr(v_31135);
    stack[-1] = v_31135;
    v_31135 = stack[0];
    v_31135 = qcdr(v_31135);
    stack[0] = v_31135;
    goto v_31064;
    v_31135 = nil;
    return onevalue(v_31135);
}



// Code for sqprla

static LispObject CC_sqprla(LispObject env,
                         LispObject v_31058, LispObject v_31059)
{
    env = qenv(env);
    LispObject v_31071, v_31072;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31058,v_31059);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_31059;
    v_31071 = v_31058;
// end of prologue
    goto v_31066;
v_31062:
    v_31071 = qcar(v_31071);
    fn = elt(env, 1); // prepsq!*
    v_31072 = (*qfn1(fn))(fn, v_31071);
    env = stack[-1];
    goto v_31063;
v_31064:
    v_31071 = stack[0];
    goto v_31065;
v_31066:
    goto v_31062;
v_31063:
    goto v_31064;
v_31065:
    {
        fn = elt(env, 2); // maprintla
        return (*qfn2(fn))(fn, v_31072, v_31071);
    }
}



// Code for rdzchk

static LispObject CC_rdzchk(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31257, v_31258;
    LispObject fn;
    LispObject v_31060, v_31059, v_31058;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "rdzchk");
    va_start(aa, nargs);
    v_31058 = va_arg(aa, LispObject);
    v_31059 = va_arg(aa, LispObject);
    v_31060 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31060,v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31058,v_31059,v_31060);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31060;
    stack[-1] = v_31059;
    stack[-2] = v_31058;
// end of prologue
    v_31257 = stack[-2];
    if (!consp(v_31257)) goto v_31064;
    else goto v_31065;
v_31064:
    goto v_31079;
v_31075:
    v_31258 = stack[-2];
    goto v_31076;
v_31077:
    v_31257 = elt(env, 1); // 0.0
    goto v_31078;
v_31079:
    goto v_31075;
v_31076:
    goto v_31077;
v_31078:
    if (equal(v_31258, v_31257)) goto v_31073;
    else goto v_31074;
v_31073:
    v_31257 = lisp_true;
    goto v_31072;
v_31074:
    goto v_31097;
v_31093:
    v_31258 = stack[-1];
    goto v_31094;
v_31095:
    v_31257 = elt(env, 1); // 0.0
    goto v_31096;
v_31097:
    goto v_31093;
v_31094:
    goto v_31095;
v_31096:
    v_31257 = (LispObject)greaterp2(v_31258, v_31257);
    v_31257 = v_31257 ? lisp_true : nil;
    env = stack[-3];
    if (v_31257 == nil) goto v_31090;
    else goto v_31091;
v_31090:
    v_31257 = nil;
    goto v_31089;
v_31091:
    goto v_31108;
v_31104:
    v_31258 = stack[0];
    goto v_31105;
v_31106:
    v_31257 = elt(env, 1); // 0.0
    goto v_31107;
v_31108:
    goto v_31104;
v_31105:
    goto v_31106;
v_31107:
    v_31257 = (LispObject)greaterp2(v_31258, v_31257);
    v_31257 = v_31257 ? lisp_true : nil;
    env = stack[-3];
    goto v_31089;
    v_31257 = nil;
v_31089:
    if (v_31257 == nil) goto v_31087;
    else goto v_31086;
v_31087:
    goto v_31120;
v_31116:
    v_31258 = stack[-1];
    goto v_31117;
v_31118:
    v_31257 = elt(env, 1); // 0.0
    goto v_31119;
v_31120:
    goto v_31116;
v_31117:
    goto v_31118;
v_31119:
    v_31257 = (LispObject)lessp2(v_31258, v_31257);
    v_31257 = v_31257 ? lisp_true : nil;
    env = stack[-3];
    if (v_31257 == nil) goto v_31113;
    else goto v_31114;
v_31113:
    v_31257 = nil;
    goto v_31112;
v_31114:
    goto v_31131;
v_31127:
    v_31258 = stack[0];
    goto v_31128;
v_31129:
    v_31257 = elt(env, 1); // 0.0
    goto v_31130;
v_31131:
    goto v_31127;
v_31128:
    goto v_31129;
v_31130:
    v_31257 = (LispObject)lessp2(v_31258, v_31257);
    v_31257 = v_31257 ? lisp_true : nil;
    env = stack[-3];
    goto v_31112;
    v_31257 = nil;
v_31112:
v_31086:
    goto v_31072;
    v_31257 = nil;
v_31072:
    if (v_31257 == nil) goto v_31070;
    v_31257 = stack[-2];
    goto v_31068;
v_31070:
    goto v_31142;
v_31138:
    v_31257 = stack[-2];
    stack[0] = Labsval(nil, v_31257);
    env = stack[-3];
    goto v_31139;
v_31140:
    goto v_31150;
v_31146:
    v_31257 = stack[-1];
    v_31258 = Labsval(nil, v_31257);
    env = stack[-3];
    goto v_31147;
v_31148:
    v_31257 = qvalue(elt(env, 2)); // !!fleps1
    goto v_31149;
v_31150:
    goto v_31146;
v_31147:
    goto v_31148;
v_31149:
    v_31257 = times2(v_31258, v_31257);
    env = stack[-3];
    goto v_31141;
v_31142:
    goto v_31138;
v_31139:
    goto v_31140;
v_31141:
    v_31257 = (LispObject)lessp2(stack[0], v_31257);
    v_31257 = v_31257 ? lisp_true : nil;
    env = stack[-3];
    if (v_31257 == nil) goto v_31136;
    v_31257 = elt(env, 1); // 0.0
    goto v_31068;
v_31136:
    v_31257 = stack[-2];
    goto v_31068;
    v_31257 = nil;
v_31068:
    goto v_31063;
v_31065:
    goto v_31168;
v_31164:
    v_31257 = stack[-2];
    v_31257 = qcdr(v_31257);
    v_31258 = qcar(v_31257);
    goto v_31165;
v_31166:
    v_31257 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31167;
v_31168:
    goto v_31164;
v_31165:
    goto v_31166;
v_31167:
    if (v_31258 == v_31257) goto v_31162;
    else goto v_31163;
v_31162:
    v_31257 = lisp_true;
    goto v_31161;
v_31163:
    goto v_31188;
v_31184:
    v_31257 = stack[-1];
    v_31257 = qcdr(v_31257);
    v_31258 = qcar(v_31257);
    goto v_31185;
v_31186:
    v_31257 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31187;
v_31188:
    goto v_31184;
v_31185:
    goto v_31186;
v_31187:
    v_31257 = (LispObject)greaterp2(v_31258, v_31257);
    v_31257 = v_31257 ? lisp_true : nil;
    env = stack[-3];
    if (v_31257 == nil) goto v_31181;
    else goto v_31182;
v_31181:
    v_31257 = nil;
    goto v_31180;
v_31182:
    goto v_31201;
v_31197:
    v_31257 = stack[0];
    v_31257 = qcdr(v_31257);
    v_31258 = qcar(v_31257);
    goto v_31198;
v_31199:
    v_31257 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31200;
v_31201:
    goto v_31197;
v_31198:
    goto v_31199;
v_31200:
    v_31257 = (LispObject)greaterp2(v_31258, v_31257);
    v_31257 = v_31257 ? lisp_true : nil;
    env = stack[-3];
    goto v_31180;
    v_31257 = nil;
v_31180:
    if (v_31257 == nil) goto v_31178;
    else goto v_31177;
v_31178:
    goto v_31215;
v_31211:
    v_31257 = stack[-1];
    v_31257 = qcdr(v_31257);
    v_31258 = qcar(v_31257);
    goto v_31212;
v_31213:
    v_31257 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31214;
v_31215:
    goto v_31211;
v_31212:
    goto v_31213;
v_31214:
    v_31257 = (LispObject)lessp2(v_31258, v_31257);
    v_31257 = v_31257 ? lisp_true : nil;
    env = stack[-3];
    if (v_31257 == nil) goto v_31208;
    else goto v_31209;
v_31208:
    v_31257 = nil;
    goto v_31207;
v_31209:
    goto v_31228;
v_31224:
    v_31257 = stack[0];
    v_31257 = qcdr(v_31257);
    v_31258 = qcar(v_31257);
    goto v_31225;
v_31226:
    v_31257 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31227;
v_31228:
    goto v_31224;
v_31225:
    goto v_31226;
v_31227:
    v_31257 = (LispObject)lessp2(v_31258, v_31257);
    v_31257 = v_31257 ? lisp_true : nil;
    env = stack[-3];
    goto v_31207;
    v_31257 = nil;
v_31207:
v_31177:
    goto v_31161;
    v_31257 = nil;
v_31161:
    if (v_31257 == nil) goto v_31159;
    v_31257 = stack[-2];
    goto v_31063;
v_31159:
    goto v_31241;
v_31237:
    v_31257 = stack[-2];
    fn = elt(env, 5); // abs!:
    stack[0] = (*qfn1(fn))(fn, v_31257);
    env = stack[-3];
    goto v_31238;
v_31239:
    goto v_31249;
v_31245:
    v_31257 = stack[-1];
    fn = elt(env, 5); // abs!:
    v_31258 = (*qfn1(fn))(fn, v_31257);
    env = stack[-3];
    goto v_31246;
v_31247:
    v_31257 = qvalue(elt(env, 3)); // rd!-tolerance!*
    goto v_31248;
v_31249:
    goto v_31245;
v_31246:
    goto v_31247;
v_31248:
    fn = elt(env, 6); // times!:
    v_31257 = (*qfn2(fn))(fn, v_31258, v_31257);
    env = stack[-3];
    goto v_31240;
v_31241:
    goto v_31237;
v_31238:
    goto v_31239;
v_31240:
    fn = elt(env, 7); // lessp!:
    v_31257 = (*qfn2(fn))(fn, stack[0], v_31257);
    env = stack[-3];
    if (v_31257 == nil) goto v_31235;
    v_31257 = qvalue(elt(env, 4)); // bfz!*
    goto v_31063;
v_31235:
    v_31257 = stack[-2];
    goto v_31063;
    v_31257 = nil;
v_31063:
    return onevalue(v_31257);
}



// Code for requote1

static LispObject CC_requote1(LispObject env,
                         LispObject v_31058)
{
    env = qenv(env);
    LispObject v_31158, v_31159;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31058);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_31058;
// end of prologue
    stack[-2] = nil;
    stack[0] = nil;
v_31064:
    v_31158 = stack[-1];
    if (v_31158 == nil) goto v_31067;
    else goto v_31068;
v_31067:
    v_31158 = stack[-2];
        return Lnreverse(nil, v_31158);
v_31068:
    v_31158 = stack[-1];
    v_31158 = qcar(v_31158);
    if (is_number(v_31158)) goto v_31072;
    goto v_31082;
v_31078:
    v_31158 = stack[-1];
    v_31159 = qcar(v_31158);
    goto v_31079;
v_31080:
    v_31158 = elt(env, 1); // (nil t)
    goto v_31081;
v_31082:
    goto v_31078;
v_31079:
    goto v_31080;
v_31081:
    v_31158 = Lmemq(nil, v_31159, v_31158);
    if (v_31158 == nil) goto v_31077;
    else goto v_31072;
v_31077:
    goto v_31073;
v_31072:
    goto v_31092;
v_31088:
    v_31158 = stack[-1];
    v_31159 = qcar(v_31158);
    goto v_31089;
v_31090:
    v_31158 = stack[-2];
    goto v_31091;
v_31092:
    goto v_31088;
v_31089:
    goto v_31090;
v_31091:
    v_31158 = cons(v_31159, v_31158);
    env = stack[-3];
    stack[-2] = v_31158;
    goto v_31066;
v_31073:
    v_31158 = stack[-1];
    v_31158 = qcar(v_31158);
    if (!consp(v_31158)) goto v_31096;
    else goto v_31097;
v_31096:
    v_31158 = nil;
    goto v_31063;
v_31097:
    goto v_31107;
v_31103:
    v_31158 = stack[-1];
    v_31158 = qcar(v_31158);
    v_31159 = qcar(v_31158);
    goto v_31104;
v_31105:
    v_31158 = elt(env, 2); // quote
    goto v_31106;
v_31107:
    goto v_31103;
v_31104:
    goto v_31105;
v_31106:
    if (v_31159 == v_31158) goto v_31101;
    else goto v_31102;
v_31101:
    goto v_31117;
v_31113:
    v_31158 = stack[-1];
    v_31158 = qcar(v_31158);
    v_31158 = qcdr(v_31158);
    v_31159 = qcar(v_31158);
    goto v_31114;
v_31115:
    v_31158 = stack[-2];
    goto v_31116;
v_31117:
    goto v_31113;
v_31114:
    goto v_31115;
v_31116:
    v_31158 = cons(v_31159, v_31158);
    env = stack[-3];
    stack[-2] = v_31158;
    goto v_31066;
v_31102:
    goto v_31133;
v_31129:
    v_31158 = stack[-1];
    v_31158 = qcar(v_31158);
    v_31159 = qcar(v_31158);
    goto v_31130;
v_31131:
    v_31158 = elt(env, 3); // list
    goto v_31132;
v_31133:
    goto v_31129;
v_31130:
    goto v_31131;
v_31132:
    if (v_31159 == v_31158) goto v_31127;
    else goto v_31128;
v_31127:
    v_31158 = stack[-1];
    v_31158 = qcar(v_31158);
    v_31158 = qcdr(v_31158);
    v_31158 = CC_requote1(elt(env, 0), v_31158);
    env = stack[-3];
    stack[0] = v_31158;
    goto v_31126;
v_31128:
    v_31158 = nil;
    goto v_31126;
    v_31158 = nil;
v_31126:
    if (v_31158 == nil) goto v_31124;
    goto v_31150;
v_31146:
    v_31159 = stack[0];
    goto v_31147;
v_31148:
    v_31158 = stack[-2];
    goto v_31149;
v_31150:
    goto v_31146;
v_31147:
    goto v_31148;
v_31149:
    v_31158 = cons(v_31159, v_31158);
    env = stack[-3];
    stack[-2] = v_31158;
    goto v_31066;
v_31124:
    v_31158 = nil;
    goto v_31063;
v_31066:
    v_31158 = stack[-1];
    v_31158 = qcdr(v_31158);
    stack[-1] = v_31158;
    goto v_31064;
v_31063:
    return onevalue(v_31158);
}



// Code for denlist

static LispObject CC_denlist(LispObject env,
                         LispObject v_31058, LispObject v_31059)
{
    env = qenv(env);
    LispObject v_31121, v_31122;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31058,v_31059);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31059;
    stack[-1] = v_31058;
// end of prologue
    stack[-2] = nil;
v_31064:
    v_31121 = stack[-1];
    if (v_31121 == nil) goto v_31067;
    else goto v_31068;
v_31067:
    v_31121 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_31121);
    }
v_31068:
    goto v_31078;
v_31074:
    v_31121 = stack[-1];
    v_31121 = qcar(v_31121);
    v_31122 = Llength(nil, v_31121);
    env = stack[-3];
    goto v_31075;
v_31076:
    v_31121 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31077;
v_31078:
    goto v_31074;
v_31075:
    goto v_31076;
v_31077:
    if (v_31122 == v_31121) goto v_31072;
    else goto v_31073;
v_31072:
    goto v_31088;
v_31084:
    goto v_31094;
v_31090:
    v_31121 = stack[-1];
    v_31122 = qcar(v_31121);
    goto v_31091;
v_31092:
    v_31121 = stack[0];
    goto v_31093;
v_31094:
    goto v_31090;
v_31091:
    goto v_31092;
v_31093:
    fn = elt(env, 2); // ev!-denom2
    v_31122 = (*qfn2(fn))(fn, v_31122, v_31121);
    env = stack[-3];
    goto v_31085;
v_31086:
    v_31121 = stack[-2];
    goto v_31087;
v_31088:
    goto v_31084;
v_31085:
    goto v_31086;
v_31087:
    v_31121 = cons(v_31122, v_31121);
    env = stack[-3];
    stack[-2] = v_31121;
    v_31121 = stack[-1];
    v_31121 = qcdr(v_31121);
    stack[-1] = v_31121;
    goto v_31064;
v_31073:
    goto v_31108;
v_31104:
    goto v_31114;
v_31110:
    v_31121 = stack[-1];
    v_31122 = qcar(v_31121);
    goto v_31111;
v_31112:
    v_31121 = stack[0];
    goto v_31113;
v_31114:
    goto v_31110;
v_31111:
    goto v_31112;
v_31113:
    fn = elt(env, 3); // ev!-denom3
    v_31122 = (*qfn2(fn))(fn, v_31122, v_31121);
    env = stack[-3];
    goto v_31105;
v_31106:
    v_31121 = stack[-2];
    goto v_31107;
v_31108:
    goto v_31104;
v_31105:
    goto v_31106;
v_31107:
    v_31121 = cons(v_31122, v_31121);
    env = stack[-3];
    stack[-2] = v_31121;
    v_31121 = stack[-1];
    v_31121 = qcdr(v_31121);
    stack[-1] = v_31121;
    goto v_31064;
    v_31121 = nil;
    return onevalue(v_31121);
}



// Code for actual_arguments

static LispObject CC_actual_arguments(LispObject env,
                         LispObject v_31058)
{
    env = qenv(env);
    LispObject v_31081, v_31082, v_31083;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31058);
    }
// copy arguments values to proper place
    v_31082 = v_31058;
// end of prologue
    goto v_31065;
v_31061:
    v_31083 = elt(env, 1); // list
    goto v_31062;
v_31063:
    v_31081 = v_31082;
    v_31081 = qcdr(v_31081);
    if (v_31081 == nil) goto v_31069;
    else goto v_31068;
v_31069:
    goto v_31077;
v_31073:
    v_31081 = v_31082;
    v_31082 = qcar(v_31081);
    goto v_31074;
v_31075:
    v_31081 = elt(env, 2); // generic_function
    goto v_31076;
v_31077:
    goto v_31073;
v_31074:
    goto v_31075;
v_31076:
    v_31081 = get(v_31082, v_31081);
v_31068:
    goto v_31064;
v_31065:
    goto v_31061;
v_31062:
    goto v_31063;
v_31064:
    return cons(v_31083, v_31081);
}



// Code for eval_uni_poly

static LispObject CC_eval_uni_poly(LispObject env,
                         LispObject v_31058, LispObject v_31059)
{
    env = qenv(env);
    LispObject v_31160, v_31161, v_31162;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31058,v_31059);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_31059;
    stack[-2] = v_31058;
// end of prologue
    v_31160 = stack[-2];
    if (!consp(v_31160)) goto v_31063;
    else goto v_31064;
v_31063:
    v_31160 = stack[-2];
    goto v_31062;
v_31064:
    v_31160 = stack[-2];
    v_31160 = qcar(v_31160);
    v_31160 = qcdr(v_31160);
    v_31162 = v_31160;
    v_31160 = stack[-2];
    v_31160 = qcar(v_31160);
    v_31160 = qcar(v_31160);
    v_31160 = qcdr(v_31160);
    v_31161 = v_31160;
    v_31160 = stack[-2];
    v_31160 = qcdr(v_31160);
    stack[-2] = v_31160;
v_31084:
    v_31160 = stack[-2];
    if (!consp(v_31160)) goto v_31087;
    else goto v_31088;
v_31087:
    goto v_31083;
v_31088:
    goto v_31096;
v_31092:
    goto v_31102;
v_31098:
    stack[-3] = v_31162;
    goto v_31099;
v_31100:
    goto v_31109;
v_31105:
    stack[0] = stack[-1];
    goto v_31106;
v_31107:
    goto v_31116;
v_31112:
    goto v_31113;
v_31114:
    v_31160 = stack[-2];
    v_31160 = qcar(v_31160);
    v_31160 = qcar(v_31160);
    v_31160 = qcdr(v_31160);
    goto v_31115;
v_31116:
    goto v_31112;
v_31113:
    goto v_31114;
v_31115:
    v_31160 = difference2(v_31161, v_31160);
    env = stack[-4];
    goto v_31108;
v_31109:
    goto v_31105;
v_31106:
    goto v_31107;
v_31108:
    v_31160 = Lexpt(nil, stack[0], v_31160);
    env = stack[-4];
    goto v_31101;
v_31102:
    goto v_31098;
v_31099:
    goto v_31100;
v_31101:
    v_31161 = times2(stack[-3], v_31160);
    env = stack[-4];
    goto v_31093;
v_31094:
    v_31160 = stack[-2];
    v_31160 = qcar(v_31160);
    v_31160 = qcdr(v_31160);
    goto v_31095;
v_31096:
    goto v_31092;
v_31093:
    goto v_31094;
v_31095:
    v_31160 = plus2(v_31161, v_31160);
    env = stack[-4];
    v_31162 = v_31160;
    v_31160 = stack[-2];
    v_31160 = qcar(v_31160);
    v_31160 = qcar(v_31160);
    v_31160 = qcdr(v_31160);
    v_31161 = v_31160;
    v_31160 = stack[-2];
    v_31160 = qcdr(v_31160);
    stack[-2] = v_31160;
    goto v_31084;
v_31083:
    goto v_31136;
v_31132:
    stack[0] = v_31162;
    goto v_31133;
v_31134:
    goto v_31143;
v_31139:
    v_31160 = stack[-1];
    goto v_31140;
v_31141:
    goto v_31142;
v_31143:
    goto v_31139;
v_31140:
    goto v_31141;
v_31142:
    v_31160 = Lexpt(nil, v_31160, v_31161);
    env = stack[-4];
    goto v_31135;
v_31136:
    goto v_31132;
v_31133:
    goto v_31134;
v_31135:
    v_31160 = times2(stack[0], v_31160);
    env = stack[-4];
    v_31162 = v_31160;
    v_31160 = stack[-2];
    if (v_31160 == nil) goto v_31149;
    goto v_31156;
v_31152:
    v_31161 = v_31162;
    goto v_31153;
v_31154:
    v_31160 = stack[-2];
    goto v_31155;
v_31156:
    goto v_31152;
v_31153:
    goto v_31154;
v_31155:
    v_31160 = plus2(v_31161, v_31160);
    v_31162 = v_31160;
    goto v_31147;
v_31149:
v_31147:
    v_31160 = v_31162;
    goto v_31062;
    v_31160 = nil;
v_31062:
    return onevalue(v_31160);
}



// Code for coeff_totder

static LispObject CC_coeff_totder(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31156, v_31157, v_31158, v_31159;
    LispObject fn;
    LispObject v_31060, v_31059, v_31058;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "coeff_totder");
    va_start(aa, nargs);
    v_31058 = va_arg(aa, LispObject);
    v_31059 = va_arg(aa, LispObject);
    v_31060 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31060,v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31058,v_31059,v_31060);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31060;
    v_31156 = v_31059;
    stack[-1] = v_31058;
// end of prologue
    goto v_31072;
v_31068:
    v_31157 = stack[-1];
    goto v_31069;
v_31070:
    goto v_31071;
v_31072:
    goto v_31068;
v_31069:
    goto v_31070;
v_31071:
    fn = elt(env, 5); // idtomind
    v_31156 = (*qfn2(fn))(fn, v_31157, v_31156);
    env = stack[-2];
    v_31157 = v_31156;
    v_31157 = qcar(v_31157);
    v_31159 = v_31157;
    goto v_31081;
v_31077:
    v_31156 = qcdr(v_31156);
    v_31157 = qcar(v_31156);
    goto v_31078;
v_31079:
    v_31156 = qvalue(elt(env, 1)); // all_mind_table!*
    goto v_31080;
v_31081:
    goto v_31077;
v_31078:
    goto v_31079;
v_31080:
    v_31156 = Lassoc(nil, v_31157, v_31156);
    v_31156 = qcdr(v_31156);
    v_31156 = qcar(v_31156);
    v_31158 = v_31156;
    v_31156 = v_31158;
    if (v_31156 == nil) goto v_31092;
    goto v_31102;
v_31098:
    v_31157 = stack[-1];
    goto v_31099;
v_31100:
    v_31156 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31101;
v_31102:
    goto v_31098;
v_31099:
    goto v_31100;
v_31101:
    if (v_31157 == v_31156) goto v_31096;
    else goto v_31097;
v_31096:
    goto v_31110;
v_31106:
    goto v_31116;
v_31112:
    stack[-1] = v_31159;
    goto v_31113;
v_31114:
    goto v_31123;
v_31119:
    v_31157 = v_31158;
    goto v_31120;
v_31121:
    v_31156 = stack[0];
    goto v_31122;
v_31123:
    goto v_31119;
v_31120:
    goto v_31121;
v_31122:
    fn = elt(env, 6); // nth
    v_31156 = (*qfn2(fn))(fn, v_31157, v_31156);
    env = stack[-2];
    goto v_31115;
v_31116:
    goto v_31112;
v_31113:
    goto v_31114;
v_31115:
    v_31157 = list2(stack[-1], v_31156);
    env = stack[-2];
    goto v_31107;
v_31108:
    v_31156 = qvalue(elt(env, 2)); // i2m_jetspace!*
    goto v_31109;
v_31110:
    goto v_31106;
v_31107:
    goto v_31108;
v_31109:
    fn = elt(env, 7); // cde_lassoc2
    v_31156 = (*qfn2(fn))(fn, v_31157, v_31156);
    v_31156 = qcar(v_31156);
    goto v_31066;
v_31097:
    goto v_31135;
v_31131:
    goto v_31141;
v_31137:
    stack[-1] = v_31159;
    goto v_31138;
v_31139:
    goto v_31148;
v_31144:
    v_31157 = v_31158;
    goto v_31145;
v_31146:
    v_31156 = stack[0];
    goto v_31147;
v_31148:
    goto v_31144;
v_31145:
    goto v_31146;
v_31147:
    fn = elt(env, 6); // nth
    v_31156 = (*qfn2(fn))(fn, v_31157, v_31156);
    env = stack[-2];
    goto v_31140;
v_31141:
    goto v_31137;
v_31138:
    goto v_31139;
v_31140:
    v_31157 = list2(stack[-1], v_31156);
    env = stack[-2];
    goto v_31132;
v_31133:
    v_31156 = qvalue(elt(env, 3)); // i2m_jetspace_odd!*
    goto v_31134;
v_31135:
    goto v_31131;
v_31132:
    goto v_31133;
v_31134:
    fn = elt(env, 7); // cde_lassoc2
    v_31156 = (*qfn2(fn))(fn, v_31157, v_31156);
    v_31156 = qcar(v_31156);
    goto v_31066;
    goto v_31090;
v_31092:
    v_31156 = elt(env, 4); // letop
    goto v_31066;
v_31090:
    v_31156 = nil;
v_31066:
    return onevalue(v_31156);
}



// Code for rl_identifyonoff

static LispObject CC_rl_identifyonoff(LispObject env,
                         LispObject v_31058)
{
    env = qenv(env);
    LispObject v_31069;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31058);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31069 = v_31058;
// end of prologue
    goto v_31065;
v_31061:
    stack[0] = qvalue(elt(env, 1)); // rl_identifyonoff!*
    goto v_31062;
v_31063:
    v_31069 = ncons(v_31069);
    env = stack[-1];
    goto v_31064;
v_31065:
    goto v_31061;
v_31062:
    goto v_31063;
v_31064:
    {
        LispObject v_31071 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_31071, v_31069);
    }
}



// Code for rule!*

static LispObject CC_ruleH(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31277, v_31278, v_31279, v_31280, v_31281;
    LispObject fn;
    LispObject v_31062, v_31061, v_31060, v_31059, v_31058;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "rule*");
    va_start(aa, nargs);
    v_31058 = va_arg(aa, LispObject);
    v_31059 = va_arg(aa, LispObject);
    v_31060 = va_arg(aa, LispObject);
    v_31061 = va_arg(aa, LispObject);
    v_31062 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_31062,v_31061,v_31060,v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_31058,v_31059,v_31060,v_31061,v_31062);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[0] = v_31062;
    stack[-1] = v_31061;
    stack[-2] = v_31060;
    stack[-3] = v_31059;
    stack[-4] = v_31058;
// end of prologue
    stack[-5] = nil;
    v_31277 = stack[-2];
    qvalue(elt(env, 1)) = v_31277; // frasc!*
    goto v_31076;
v_31072:
    v_31278 = stack[-1];
    goto v_31073;
v_31074:
    v_31277 = lisp_true;
    goto v_31075;
v_31076:
    goto v_31072;
v_31073:
    goto v_31074;
v_31075:
    if (v_31278 == v_31277) goto v_31070;
    else goto v_31071;
v_31070:
    v_31277 = lisp_true;
    goto v_31069;
v_31071:
    goto v_31087;
v_31083:
    v_31278 = stack[-2];
    goto v_31084;
v_31085:
    v_31277 = stack[-1];
    goto v_31086;
v_31087:
    goto v_31083;
v_31084:
    goto v_31085;
v_31086:
    v_31277 = Lsubla(nil, v_31278, v_31277);
    env = stack[-6];
    goto v_31069;
    v_31277 = nil;
v_31069:
    qvalue(elt(env, 2)) = v_31277; // mcond!*
    v_31277 = stack[0];
    if (v_31277 == nil) goto v_31093;
    goto v_31101;
v_31097:
    v_31278 = stack[0];
    goto v_31098;
v_31099:
    v_31277 = elt(env, 3); // old
    goto v_31100;
v_31101:
    goto v_31097;
v_31098:
    goto v_31099;
v_31100:
    if (v_31278 == v_31277) goto v_31093;
    goto v_31113;
v_31105:
    v_31280 = stack[-4];
    goto v_31106;
v_31107:
    v_31279 = stack[-3];
    goto v_31108;
v_31109:
    v_31278 = stack[-2];
    goto v_31110;
v_31111:
    v_31277 = stack[-1];
    goto v_31112;
v_31113:
    goto v_31105;
v_31106:
    goto v_31107;
v_31108:
    goto v_31109;
v_31110:
    goto v_31111;
v_31112:
    v_31277 = list4(v_31280, v_31279, v_31278, v_31277);
    env = stack[-6];
    qvalue(elt(env, 4)) = v_31277; // newrule!*
    v_31277 = stack[-4];
    if (symbolp(v_31277)) goto v_31120;
    else goto v_31121;
v_31120:
    v_31277 = stack[-4];
    if (!symbolp(v_31277)) v_31277 = nil;
    else { v_31277 = qfastgets(v_31277);
           if (v_31277 != nil) { v_31277 = elt(v_31277, 2); // rtype
#ifdef RECORD_GET
             if (v_31277 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_31277 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_31277 == SPID_NOPROP) v_31277 = nil; }}
#endif
    stack[-5] = v_31277;
    if (v_31277 == nil) goto v_31126;
    goto v_31136;
v_31130:
    stack[-1] = stack[-4];
    goto v_31131;
v_31132:
    goto v_31143;
v_31139:
    v_31278 = elt(env, 5); // rtype
    goto v_31140;
v_31141:
    v_31277 = stack[-5];
    goto v_31142;
v_31143:
    goto v_31139;
v_31140:
    goto v_31141;
v_31142:
    v_31278 = cons(v_31278, v_31277);
    env = stack[-6];
    goto v_31133;
v_31134:
    v_31277 = qvalue(elt(env, 6)); // props!*
    goto v_31135;
v_31136:
    goto v_31130;
v_31131:
    goto v_31132;
v_31133:
    goto v_31134;
v_31135:
    v_31277 = acons(stack[-1], v_31278, v_31277);
    env = stack[-6];
    qvalue(elt(env, 6)) = v_31277; // props!*
    goto v_31152;
v_31148:
    v_31278 = stack[-4];
    goto v_31149;
v_31150:
    v_31277 = elt(env, 5); // rtype
    goto v_31151;
v_31152:
    goto v_31148;
v_31149:
    goto v_31150;
v_31151:
    v_31277 = Lremprop(nil, v_31278, v_31277);
    env = stack[-6];
    goto v_31124;
v_31126:
v_31124:
    v_31277 = stack[-4];
    if (!symbolp(v_31277)) v_31277 = nil;
    else { v_31277 = qfastgets(v_31277);
           if (v_31277 != nil) { v_31277 = elt(v_31277, 4); // avalue
#ifdef RECORD_GET
             if (v_31277 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_31277 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_31277 == SPID_NOPROP) v_31277 = nil; }}
#endif
    stack[-5] = v_31277;
    if (v_31277 == nil) goto v_31158;
    goto v_31166;
v_31162:
    v_31278 = stack[-5];
    goto v_31163;
v_31164:
    v_31277 = nil;
    goto v_31165;
v_31166:
    goto v_31162;
v_31163:
    goto v_31164;
v_31165:
    fn = elt(env, 10); // updoldrules
    v_31277 = (*qfn2(fn))(fn, v_31278, v_31277);
    env = stack[-6];
    goto v_31174;
v_31170:
    v_31278 = stack[-4];
    goto v_31171;
v_31172:
    v_31277 = elt(env, 7); // avalue
    goto v_31173;
v_31174:
    goto v_31170;
v_31171:
    goto v_31172;
v_31173:
    v_31277 = Lremprop(nil, v_31278, v_31277);
    env = stack[-6];
    goto v_31156;
v_31158:
v_31156:
    goto v_31119;
v_31121:
v_31119:
    goto v_31189;
v_31185:
    v_31278 = stack[-3];
    goto v_31186;
v_31187:
    v_31277 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31188;
v_31189:
    goto v_31185;
v_31186:
    goto v_31187;
v_31188:
    if (v_31278 == v_31277) goto v_31183;
    else goto v_31184;
v_31183:
    goto v_31201;
v_31197:
    v_31278 = stack[-4];
    goto v_31198;
v_31199:
    v_31277 = elt(env, 8); // expt
    goto v_31200;
v_31201:
    goto v_31197;
v_31198:
    goto v_31199;
v_31200:
    if (!consp(v_31278)) goto v_31195;
    v_31278 = qcar(v_31278);
    if (v_31278 == v_31277) goto v_31194;
    else goto v_31195;
v_31194:
    v_31277 = stack[-4];
    v_31277 = qcdr(v_31277);
    v_31277 = qcar(v_31277);
    if (symbolp(v_31277)) goto v_31207;
    v_31277 = nil;
    goto v_31205;
v_31207:
    v_31277 = stack[-4];
    v_31277 = qcdr(v_31277);
    v_31277 = qcdr(v_31277);
    v_31277 = qcar(v_31277);
    if (is_number(v_31277)) goto v_31217;
    v_31277 = nil;
    goto v_31215;
v_31217:
    goto v_31229;
v_31225:
    v_31277 = stack[-4];
    v_31277 = qcdr(v_31277);
    v_31278 = qcar(v_31277);
    goto v_31226;
v_31227:
    v_31277 = qvalue(elt(env, 9)); // asymplis!*
    goto v_31228;
v_31229:
    goto v_31225;
v_31226:
    goto v_31227;
v_31228:
    v_31277 = Lassoc(nil, v_31278, v_31277);
    stack[-5] = v_31277;
    goto v_31215;
    v_31277 = nil;
v_31215:
    goto v_31205;
    v_31277 = nil;
v_31205:
    goto v_31193;
v_31195:
    v_31277 = nil;
    goto v_31193;
    v_31277 = nil;
v_31193:
    goto v_31182;
v_31184:
    v_31277 = nil;
    goto v_31182;
    v_31277 = nil;
v_31182:
    if (v_31277 == nil) goto v_31180;
    goto v_31246;
v_31242:
    v_31278 = stack[-5];
    goto v_31243;
v_31244:
    v_31277 = nil;
    goto v_31245;
v_31246:
    goto v_31242;
v_31243:
    goto v_31244;
v_31245:
    fn = elt(env, 10); // updoldrules
    v_31277 = (*qfn2(fn))(fn, v_31278, v_31277);
    env = stack[-6];
    goto v_31178;
v_31180:
v_31178:
    goto v_31091;
v_31093:
v_31091:
    goto v_31258;
v_31250:
    v_31281 = stack[-4];
    goto v_31251;
v_31252:
    v_31280 = stack[-3];
    goto v_31253;
v_31254:
    v_31279 = stack[-2];
    goto v_31255;
v_31256:
    goto v_31270;
v_31266:
    v_31278 = stack[0];
    goto v_31267;
v_31268:
    v_31277 = elt(env, 3); // old
    goto v_31269;
v_31270:
    goto v_31266;
v_31267:
    goto v_31268;
v_31269:
    if (v_31278 == v_31277) goto v_31264;
    else goto v_31265;
v_31264:
    v_31277 = lisp_true;
    goto v_31263;
v_31265:
    v_31277 = stack[0];
    goto v_31263;
    v_31277 = nil;
v_31263:
    goto v_31257;
v_31258:
    goto v_31250;
v_31251:
    goto v_31252;
v_31253:
    goto v_31254;
v_31255:
    goto v_31256;
v_31257:
    {
        fn = elt(env, 11); // rule
        return (*qfnn(fn))(fn, 4, v_31281, v_31280, v_31279, v_31277);
    }
    return onevalue(v_31277);
}



// Code for rl_simplb

static LispObject CC_rl_simplb(LispObject env,
                         LispObject v_31058, LispObject v_31059)
{
    env = qenv(env);
    LispObject v_31076, v_31077;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31058,v_31059);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31076 = v_31059;
    v_31077 = v_31058;
// end of prologue
    goto v_31066;
v_31062:
    stack[0] = qvalue(elt(env, 1)); // rl_simplb!*
    goto v_31063;
v_31064:
    goto v_31073;
v_31069:
    goto v_31070;
v_31071:
    goto v_31072;
v_31073:
    goto v_31069;
v_31070:
    goto v_31071;
v_31072:
    v_31076 = list2(v_31077, v_31076);
    env = stack[-1];
    goto v_31065;
v_31066:
    goto v_31062;
v_31063:
    goto v_31064;
v_31065:
    {
        LispObject v_31079 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_31079, v_31076);
    }
}



// Code for make!-image!-mod!-p

static LispObject CC_makeKimageKmodKp(LispObject env,
                         LispObject v_31058, LispObject v_31059)
{
    env = qenv(env);
    LispObject v_31100, v_31101;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31059,v_31058);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31058,v_31059);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31059;
    stack[-1] = v_31058;
// end of prologue
    goto v_31069;
v_31065:
    v_31101 = stack[-1];
    goto v_31066;
v_31067:
    v_31100 = stack[0];
    goto v_31068;
v_31069:
    goto v_31065;
v_31066:
    goto v_31067;
v_31068:
    fn = elt(env, 2); // degree!-in!-variable
    v_31100 = (*qfn2(fn))(fn, v_31101, v_31100);
    env = stack[-3];
    stack[-2] = v_31100;
    goto v_31077;
v_31073:
    v_31101 = stack[-1];
    goto v_31074;
v_31075:
    v_31100 = stack[0];
    goto v_31076;
v_31077:
    goto v_31073;
v_31074:
    goto v_31075;
v_31076:
    fn = elt(env, 3); // make!-univariate!-image!-mod!-p
    v_31100 = (*qfn2(fn))(fn, v_31101, v_31100);
    env = stack[-3];
    stack[-1] = v_31100;
    goto v_31088;
v_31084:
    goto v_31094;
v_31090:
    v_31101 = stack[-1];
    goto v_31091;
v_31092:
    v_31100 = stack[0];
    goto v_31093;
v_31094:
    goto v_31090;
v_31091:
    goto v_31092;
v_31093:
    fn = elt(env, 2); // degree!-in!-variable
    v_31101 = (*qfn2(fn))(fn, v_31101, v_31100);
    env = stack[-3];
    goto v_31085;
v_31086:
    v_31100 = stack[-2];
    goto v_31087;
v_31088:
    goto v_31084;
v_31085:
    goto v_31086;
v_31087:
    if (equal(v_31101, v_31100)) goto v_31083;
    v_31100 = lisp_true;
    qvalue(elt(env, 1)) = v_31100; // unlucky!-case
    goto v_31081;
v_31083:
v_31081:
    v_31100 = stack[-1];
    return onevalue(v_31100);
}



setup_type const u52_setup[] =
{
    {"qqe_simplqequal",         TOO_FEW_2,      CC_qqe_simplqequal,WRONG_NO_2},
    {"vdp_zero",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vdp_zero},
    {"ps:value",                CC_psTvalue,    TOO_MANY_1,    WRONG_NO_1},
    {"transferrow1",            CC_transferrow1,TOO_MANY_1,    WRONG_NO_1},
    {"f2dip2",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_f2dip2},
    {"symmetrize-inds",         TOO_FEW_2,      CC_symmetrizeKinds,WRONG_NO_2},
    {"coeff_sortl",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_coeff_sortl},
    {"subs2chkex",              CC_subs2chkex,  TOO_MANY_1,    WRONG_NO_1},
    {"simpsqrt3",               CC_simpsqrt3,   TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_smmkatl-and",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smmkatlKand},
    {"update_components",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_update_components},
    {"talp_simplatfn",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_simplatfn},
    {"division-test",           TOO_FEW_2,      CC_divisionKtest,WRONG_NO_2},
    {"vsl_boundtype1",          TOO_FEW_2,      CC_vsl_boundtype1,WRONG_NO_2},
    {"spmatsm*",                TOO_FEW_2,      CC_spmatsmH,   WRONG_NO_2},
    {"tchscheme",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_tchscheme},
    {"solvealgtrig01",          TOO_FEW_2,      CC_solvealgtrig01,WRONG_NO_2},
    {"normmat",                 CC_normmat,     TOO_MANY_1,    WRONG_NO_1},
    {"extract_numid",           CC_extract_numid,TOO_MANY_1,   WRONG_NO_1},
    {"dv_skelsplit",            CC_dv_skelsplit,TOO_MANY_1,    WRONG_NO_1},
    {"small-random-number",     WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_smallKrandomKnumber},
    {"ofsf_smmkatl-or",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smmkatlKor},
    {"giprim",                  CC_giprim,      TOO_MANY_1,    WRONG_NO_1},
    {"mk_resimp_rep",           CC_mk_resimp_rep,TOO_MANY_1,   WRONG_NO_1},
    {"talp_try1",               CC_talp_try1,   TOO_MANY_1,    WRONG_NO_1},
    {"qqe_prefix-length",       CC_qqe_prefixKlength,TOO_MANY_1,WRONG_NO_1},
    {"acfsf_varlat",            CC_acfsf_varlat,TOO_MANY_1,    WRONG_NO_1},
    {"expvec2a1",               TOO_FEW_2,      CC_expvec2a1,  WRONG_NO_2},
    {"sqprla",                  TOO_FEW_2,      CC_sqprla,     WRONG_NO_2},
    {"rdzchk",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rdzchk},
    {"requote1",                CC_requote1,    TOO_MANY_1,    WRONG_NO_1},
    {"denlist",                 TOO_FEW_2,      CC_denlist,    WRONG_NO_2},
    {"actual_arguments",        CC_actual_arguments,TOO_MANY_1,WRONG_NO_1},
    {"eval_uni_poly",           TOO_FEW_2,      CC_eval_uni_poly,WRONG_NO_2},
    {"coeff_totder",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_coeff_totder},
    {"rl_identifyonoff",        CC_rl_identifyonoff,TOO_MANY_1,WRONG_NO_1},
    {"rule*",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ruleH},
    {"rl_simplb",               TOO_FEW_2,      CC_rl_simplb,  WRONG_NO_2},
    {"make-image-mod-p",        TOO_FEW_2,      CC_makeKimageKmodKp,WRONG_NO_2},
    {NULL, (one_args *)"u52", (two_args *)"53476 7878988 9809719", 0}
};

// end of generated code
