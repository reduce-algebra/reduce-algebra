
// $destdir/u54.c        Machine generated C code

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



// Code for multtaylorsq

static LispObject CC_multtaylorsq(LispObject env,
                         LispObject v_31882, LispObject v_31883)
{
    env = qenv(env);
    LispObject v_32035, v_32036;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31883,v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31882,v_31883);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_31883;
    stack[-6] = v_31882;
// end of prologue
    v_32035 = stack[-6];
    if (v_32035 == nil) goto v_31891;
    else goto v_31892;
v_31891:
    v_32035 = lisp_true;
    goto v_31890;
v_31892:
    v_32035 = stack[-5];
    v_32035 = qcar(v_32035);
    v_32035 = (v_32035 == nil ? lisp_true : nil);
    goto v_31890;
    v_32035 = nil;
v_31890:
    if (v_32035 == nil) goto v_31888;
    v_32035 = nil;
    goto v_31886;
v_31888:
    goto v_31912;
v_31904:
    stack[-7] = elt(env, 1); // taylor!*
    goto v_31905;
v_31906:
    v_32035 = stack[-6];
    v_32035 = qcdr(v_32035);
    v_32035 = qcar(v_32035);
    stack[-4] = v_32035;
    v_32035 = stack[-4];
    if (v_32035 == nil) goto v_31925;
    else goto v_31926;
v_31925:
    v_32035 = nil;
    stack[-1] = v_32035;
    goto v_31918;
v_31926:
    v_32035 = stack[-4];
    v_32035 = qcar(v_32035);
    v_32036 = v_32035;
    goto v_31938;
v_31934:
    v_32035 = v_32036;
    stack[0] = qcar(v_32035);
    goto v_31935;
v_31936:
    goto v_31948;
v_31944:
    v_32035 = v_32036;
    v_32036 = qcdr(v_32035);
    goto v_31945;
v_31946:
    v_32035 = stack[-5];
    goto v_31947;
v_31948:
    goto v_31944;
v_31945:
    goto v_31946;
v_31947:
    fn = elt(env, 3); // multsq
    v_32035 = (*qfn2(fn))(fn, v_32036, v_32035);
    env = stack[-8];
    fn = elt(env, 4); // subs2!*
    v_32035 = (*qfn1(fn))(fn, v_32035);
    env = stack[-8];
    fn = elt(env, 5); // resimp
    v_32035 = (*qfn1(fn))(fn, v_32035);
    env = stack[-8];
    goto v_31937;
v_31938:
    goto v_31934;
v_31935:
    goto v_31936;
v_31937:
    v_32035 = cons(stack[0], v_32035);
    env = stack[-8];
    v_32035 = ncons(v_32035);
    env = stack[-8];
    stack[-2] = v_32035;
    stack[-3] = v_32035;
v_31919:
    v_32035 = stack[-4];
    v_32035 = qcdr(v_32035);
    stack[-4] = v_32035;
    v_32035 = stack[-4];
    if (v_32035 == nil) goto v_31956;
    else goto v_31957;
v_31956:
    v_32035 = stack[-3];
    stack[-1] = v_32035;
    goto v_31918;
v_31957:
    goto v_31965;
v_31961:
    stack[-1] = stack[-2];
    goto v_31962;
v_31963:
    v_32035 = stack[-4];
    v_32035 = qcar(v_32035);
    v_32036 = v_32035;
    goto v_31976;
v_31972:
    v_32035 = v_32036;
    stack[0] = qcar(v_32035);
    goto v_31973;
v_31974:
    goto v_31986;
v_31982:
    v_32035 = v_32036;
    v_32036 = qcdr(v_32035);
    goto v_31983;
v_31984:
    v_32035 = stack[-5];
    goto v_31985;
v_31986:
    goto v_31982;
v_31983:
    goto v_31984;
v_31985:
    fn = elt(env, 3); // multsq
    v_32035 = (*qfn2(fn))(fn, v_32036, v_32035);
    env = stack[-8];
    fn = elt(env, 4); // subs2!*
    v_32035 = (*qfn1(fn))(fn, v_32035);
    env = stack[-8];
    fn = elt(env, 5); // resimp
    v_32035 = (*qfn1(fn))(fn, v_32035);
    env = stack[-8];
    goto v_31975;
v_31976:
    goto v_31972;
v_31973:
    goto v_31974;
v_31975:
    v_32035 = cons(stack[0], v_32035);
    env = stack[-8];
    v_32035 = ncons(v_32035);
    env = stack[-8];
    goto v_31964;
v_31965:
    goto v_31961;
v_31962:
    goto v_31963;
v_31964:
    v_32035 = Lrplacd(nil, stack[-1], v_32035);
    env = stack[-8];
    v_32035 = stack[-2];
    v_32035 = qcdr(v_32035);
    stack[-2] = v_32035;
    goto v_31919;
v_31918:
    goto v_31907;
v_31908:
    v_32035 = stack[-6];
    v_32035 = qcdr(v_32035);
    v_32035 = qcdr(v_32035);
    stack[0] = qcar(v_32035);
    goto v_31909;
v_31910:
    goto v_32001;
v_31997:
    v_32035 = qvalue(elt(env, 2)); // !*taylorkeeporiginal
    if (v_32035 == nil) goto v_32005;
    v_32035 = stack[-6];
    v_32035 = qcdr(v_32035);
    v_32035 = qcdr(v_32035);
    v_32035 = qcdr(v_32035);
    v_32035 = qcar(v_32035);
    if (v_32035 == nil) goto v_32005;
    goto v_32019;
v_32015:
    v_32036 = stack[-5];
    goto v_32016;
v_32017:
    v_32035 = stack[-6];
    v_32035 = qcdr(v_32035);
    v_32035 = qcdr(v_32035);
    v_32035 = qcdr(v_32035);
    v_32035 = qcar(v_32035);
    goto v_32018;
v_32019:
    goto v_32015;
v_32016:
    goto v_32017;
v_32018:
    fn = elt(env, 3); // multsq
    v_32035 = (*qfn2(fn))(fn, v_32036, v_32035);
    env = stack[-8];
    v_32036 = v_32035;
    goto v_32003;
v_32005:
    v_32035 = nil;
    v_32036 = v_32035;
    goto v_32003;
    v_32036 = nil;
v_32003:
    goto v_31998;
v_31999:
    v_32035 = stack[-6];
    v_32035 = qcdr(v_32035);
    v_32035 = qcdr(v_32035);
    v_32035 = qcdr(v_32035);
    v_32035 = qcdr(v_32035);
    v_32035 = qcar(v_32035);
    goto v_32000;
v_32001:
    goto v_31997;
v_31998:
    goto v_31999;
v_32000:
    v_32035 = list2(v_32036, v_32035);
    goto v_31911;
v_31912:
    goto v_31904;
v_31905:
    goto v_31906;
v_31907:
    goto v_31908;
v_31909:
    goto v_31910;
v_31911:
    {
        LispObject v_32045 = stack[-7];
        LispObject v_32046 = stack[-1];
        LispObject v_32047 = stack[0];
        return list3star(v_32045, v_32046, v_32047, v_32035);
    }
    v_32035 = nil;
v_31886:
    return onevalue(v_32035);
}



// Code for simpx1

static LispObject CC_simpx1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_32771, v_32772, v_32773;
    LispObject fn;
    LispObject v_31884, v_31883, v_31882;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "simpx1");
    va_start(aa, nargs);
    v_31882 = va_arg(aa, LispObject);
    v_31883 = va_arg(aa, LispObject);
    v_31884 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31884,v_31883,v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31882,v_31883,v_31884);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_31884;
    stack[-1] = v_31883;
    stack[-4] = v_31882;
// end of prologue
    stack[-6] = nil;
    goto v_31902;
v_31898:
    v_32772 = stack[-4];
    goto v_31899;
v_31900:
    v_32771 = elt(env, 1); // !*minus!*
    goto v_31901;
v_31902:
    goto v_31898;
v_31899:
    goto v_31900;
v_31901:
    if (!consp(v_32772)) goto v_31896;
    v_32772 = qcar(v_32772);
    if (v_32772 == v_32771) goto v_31895;
    else goto v_31896;
v_31895:
    goto v_31918;
v_31914:
    v_32772 = stack[-1];
    goto v_31915;
v_31916:
    v_32771 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31917;
v_31918:
    goto v_31914;
v_31915:
    goto v_31916;
v_31917:
    if (v_32772 == v_32771) goto v_31912;
    else goto v_31913;
v_31912:
    v_32771 = stack[-3];
    v_32771 = integerp(v_32771);
    if (v_32771 == nil) goto v_31923;
    else goto v_31924;
v_31923:
    v_32771 = nil;
    goto v_31922;
v_31924:
    goto v_31934;
v_31930:
    goto v_31940;
v_31936:
    v_32772 = stack[-3];
    goto v_31937;
v_31938:
    v_32771 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31939;
v_31940:
    goto v_31936;
v_31937:
    goto v_31938;
v_31939:
    v_32772 = Cremainder(v_32772, v_32771);
    env = stack[-7];
    goto v_31931;
v_31932:
    v_32771 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31933;
v_31934:
    goto v_31930;
v_31931:
    goto v_31932;
v_31933:
    v_32771 = (v_32772 == v_32771 ? lisp_true : nil);
    goto v_31922;
    v_32771 = nil;
v_31922:
    goto v_31911;
v_31913:
    v_32771 = nil;
    goto v_31911;
    v_32771 = nil;
v_31911:
    if (v_32771 == nil) goto v_31909;
    else goto v_31907;
v_31909:
    goto v_31957;
v_31953:
    v_32772 = stack[-3];
    goto v_31954;
v_31955:
    v_32771 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31956;
v_31957:
    goto v_31953;
v_31954:
    goto v_31955;
v_31956:
    if (v_32772 == v_32771) goto v_31951;
    else goto v_31952;
v_31951:
    goto v_31969;
v_31965:
    v_32772 = stack[-1];
    goto v_31966;
v_31967:
    v_32771 = elt(env, 2); // quotient
    goto v_31968;
v_31969:
    goto v_31965;
v_31966:
    goto v_31967;
v_31968:
    if (!consp(v_32772)) goto v_31963;
    v_32772 = qcar(v_32772);
    if (v_32772 == v_32771) goto v_31962;
    else goto v_31963;
v_31962:
    goto v_31980;
v_31976:
    v_32771 = stack[-1];
    v_32771 = qcdr(v_32771);
    v_32772 = qcar(v_32771);
    goto v_31977;
v_31978:
    v_32771 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31979;
v_31980:
    goto v_31976;
v_31977:
    goto v_31978;
v_31979:
    if (v_32772 == v_32771) goto v_31974;
    else goto v_31975;
v_31974:
    v_32771 = stack[-1];
    v_32771 = qcdr(v_32771);
    v_32771 = qcdr(v_32771);
    v_32771 = qcar(v_32771);
    v_32771 = integerp(v_32771);
    if (v_32771 == nil) goto v_31987;
    else goto v_31988;
v_31987:
    v_32771 = nil;
    goto v_31986;
v_31988:
    goto v_32001;
v_31997:
    goto v_32007;
v_32003:
    v_32771 = stack[-1];
    v_32771 = qcdr(v_32771);
    v_32771 = qcdr(v_32771);
    v_32772 = qcar(v_32771);
    goto v_32004;
v_32005:
    v_32771 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_32006;
v_32007:
    goto v_32003;
v_32004:
    goto v_32005;
v_32006:
    v_32772 = Cremainder(v_32772, v_32771);
    env = stack[-7];
    goto v_31998;
v_31999:
    v_32771 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32000;
v_32001:
    goto v_31997;
v_31998:
    goto v_31999;
v_32000:
    v_32771 = (v_32772 == v_32771 ? lisp_true : nil);
    goto v_31986;
    v_32771 = nil;
v_31986:
    goto v_31973;
v_31975:
    v_32771 = nil;
    goto v_31973;
    v_32771 = nil;
v_31973:
    goto v_31961;
v_31963:
    v_32771 = nil;
    goto v_31961;
    v_32771 = nil;
v_31961:
    goto v_31950;
v_31952:
    v_32771 = nil;
    goto v_31950;
    v_32771 = nil;
v_31950:
    if (v_32771 == nil) goto v_31948;
    else goto v_31907;
v_31948:
    goto v_31908;
v_31907:
    goto v_32029;
v_32025:
    goto v_32038;
v_32032:
    stack[-6] = elt(env, 3); // expt
    goto v_32033;
v_32034:
    stack[-5] = elt(env, 4); // i
    goto v_32035;
v_32036:
    goto v_32048;
v_32042:
    stack[-2] = elt(env, 2); // quotient
    goto v_32043;
v_32044:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32045;
v_32046:
    goto v_32056;
v_32052:
    v_32772 = stack[-3];
    goto v_32053;
v_32054:
    v_32771 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_32055;
v_32056:
    goto v_32052;
v_32053:
    goto v_32054;
v_32055:
    v_32771 = quot2(v_32772, v_32771);
    env = stack[-7];
    goto v_32047;
v_32048:
    goto v_32042;
v_32043:
    goto v_32044;
v_32045:
    goto v_32046;
v_32047:
    v_32771 = list3(stack[-2], stack[0], v_32771);
    env = stack[-7];
    goto v_32037;
v_32038:
    goto v_32032;
v_32033:
    goto v_32034;
v_32035:
    goto v_32036;
v_32037:
    v_32771 = list3(stack[-6], stack[-5], v_32771);
    env = stack[-7];
    fn = elt(env, 18); // simp
    stack[0] = (*qfn1(fn))(fn, v_32771);
    env = stack[-7];
    goto v_32026;
v_32027:
    goto v_32065;
v_32061:
    v_32771 = stack[-4];
    v_32771 = qcdr(v_32771);
    stack[-2] = qcar(v_32771);
    goto v_32062;
v_32063:
    goto v_32076;
v_32070:
    v_32773 = elt(env, 2); // quotient
    goto v_32071;
v_32072:
    v_32772 = stack[-1];
    goto v_32073;
v_32074:
    v_32771 = stack[-3];
    goto v_32075;
v_32076:
    goto v_32070;
v_32071:
    goto v_32072;
v_32073:
    goto v_32074;
v_32075:
    v_32771 = list3(v_32773, v_32772, v_32771);
    env = stack[-7];
    goto v_32064;
v_32065:
    goto v_32061;
v_32062:
    goto v_32063;
v_32064:
    v_32771 = list2(stack[-2], v_32771);
    env = stack[-7];
    fn = elt(env, 19); // simpexpt
    v_32771 = (*qfn1(fn))(fn, v_32771);
    env = stack[-7];
    goto v_32028;
v_32029:
    goto v_32025;
v_32026:
    goto v_32027;
v_32028:
    {
        LispObject v_32781 = stack[0];
        fn = elt(env, 20); // multsq
        return (*qfn2(fn))(fn, v_32781, v_32771);
    }
v_31908:
    goto v_32090;
v_32086:
    v_32772 = stack[-1];
    goto v_32087;
v_32088:
    v_32771 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32089;
v_32090:
    goto v_32086;
v_32087:
    goto v_32088;
v_32089:
    if (v_32772 == v_32771) goto v_32084;
    else goto v_32085;
v_32084:
    v_32771 = stack[-3];
    v_32771 = integerp(v_32771);
    goto v_32083;
v_32085:
    v_32771 = nil;
    goto v_32083;
    v_32771 = nil;
v_32083:
    if (v_32771 == nil) goto v_32081;
    goto v_32105;
v_32101:
    v_32771 = stack[-4];
    v_32771 = qcdr(v_32771);
    stack[0] = qcar(v_32771);
    goto v_32102;
v_32103:
    goto v_32116;
v_32110:
    v_32773 = elt(env, 2); // quotient
    goto v_32111;
v_32112:
    v_32772 = stack[-1];
    goto v_32113;
v_32114:
    v_32771 = stack[-3];
    goto v_32115;
v_32116:
    goto v_32110;
v_32111:
    goto v_32112;
v_32113:
    goto v_32114;
v_32115:
    v_32771 = list3(v_32773, v_32772, v_32771);
    env = stack[-7];
    goto v_32104;
v_32105:
    goto v_32101;
v_32102:
    goto v_32103;
v_32104:
    v_32771 = list2(stack[0], v_32771);
    env = stack[-7];
    fn = elt(env, 19); // simpexpt
    v_32771 = (*qfn1(fn))(fn, v_32771);
    env = stack[-7];
    {
        fn = elt(env, 21); // negsq
        return (*qfn1(fn))(fn, v_32771);
    }
v_32081:
    goto v_31894;
v_31896:
v_31894:
    v_32771 = stack[-1];
    if (is_number(v_32771)) goto v_32125;
    else goto v_32124;
v_32125:
    v_32771 = stack[-3];
    if (is_number(v_32771)) goto v_32127;
    else goto v_32124;
v_32127:
    goto v_32122;
v_32124:
    goto v_32136;
v_32132:
    v_32772 = qvalue(elt(env, 5)); // frlis!*
    goto v_32133;
v_32134:
    v_32771 = stack[-1];
    goto v_32135;
v_32136:
    goto v_32132;
v_32133:
    goto v_32134;
v_32135:
    fn = elt(env, 22); // smemqlp
    v_32771 = (*qfn2(fn))(fn, v_32772, v_32771);
    env = stack[-7];
    if (v_32771 == nil) goto v_32130;
    else goto v_32129;
v_32130:
    goto v_32145;
v_32141:
    v_32772 = qvalue(elt(env, 5)); // frlis!*
    goto v_32142;
v_32143:
    v_32771 = stack[-3];
    goto v_32144;
v_32145:
    goto v_32141;
v_32142:
    goto v_32143;
v_32144:
    fn = elt(env, 22); // smemqlp
    v_32771 = (*qfn2(fn))(fn, v_32772, v_32771);
    env = stack[-7];
    if (v_32771 == nil) goto v_32139;
    else goto v_32129;
v_32139:
    goto v_32122;
v_32129:
    goto v_32123;
v_32122:
    goto v_31891;
v_32123:
    goto v_32153;
v_32149:
    goto v_32161;
v_32155:
    stack[0] = elt(env, 3); // expt
    goto v_32156;
v_32157:
    stack[-2] = stack[-4];
    goto v_32158;
v_32159:
    goto v_32172;
v_32168:
    v_32772 = stack[-3];
    goto v_32169;
v_32170:
    v_32771 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32171;
v_32172:
    goto v_32168;
v_32169:
    goto v_32170;
v_32171:
    if (v_32772 == v_32771) goto v_32166;
    else goto v_32167;
v_32166:
    v_32771 = stack[-1];
    goto v_32165;
v_32167:
    goto v_32185;
v_32179:
    v_32773 = elt(env, 2); // quotient
    goto v_32180;
v_32181:
    v_32772 = stack[-1];
    goto v_32182;
v_32183:
    v_32771 = stack[-3];
    goto v_32184;
v_32185:
    goto v_32179;
v_32180:
    goto v_32181;
v_32182:
    goto v_32183;
v_32184:
    v_32771 = list3(v_32773, v_32772, v_32771);
    env = stack[-7];
    goto v_32165;
    v_32771 = nil;
v_32165:
    goto v_32160;
v_32161:
    goto v_32155;
v_32156:
    goto v_32157;
v_32158:
    goto v_32159;
v_32160:
    v_32772 = list3(stack[0], stack[-2], v_32771);
    env = stack[-7];
    goto v_32150;
v_32151:
    v_32771 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32152;
v_32153:
    goto v_32149;
v_32150:
    goto v_32151;
v_32152:
    {
        fn = elt(env, 23); // mksq
        return (*qfn2(fn))(fn, v_32772, v_32771);
    }
v_31891:
    v_32771 = stack[-1];
    if (is_number(v_32771)) goto v_32192;
    else goto v_32193;
v_32192:
    v_32771 = stack[-1];
    v_32771 = Lminusp(nil, v_32771);
    env = stack[-7];
    if (v_32771 == nil) goto v_32198;
    v_32771 = stack[-1];
    v_32771 = negate(v_32771);
    env = stack[-7];
    stack[-1] = v_32771;
    goto v_31892;
v_32198:
    v_32771 = stack[-1];
    v_32771 = integerp(v_32771);
    if (v_32771 == nil) goto v_32204;
    v_32771 = stack[-3];
    v_32771 = integerp(v_32771);
    if (v_32771 == nil) goto v_32210;
    v_32771 = stack[-6];
    if (v_32771 == nil) goto v_32216;
    v_32771 = stack[-1];
    v_32771 = negate(v_32771);
    env = stack[-7];
    stack[-1] = v_32771;
    goto v_32214;
v_32216:
v_32214:
    v_32771 = stack[-1];
    stack[-5] = v_32771;
    v_32771 = qvalue(elt(env, 6)); // !*mcd
    if (v_32771 == nil) goto v_32224;
    v_32771 = stack[-4];
    v_32771 = integerp(v_32771);
    if (v_32771 == nil) goto v_32228;
    else goto v_32227;
v_32228:
    v_32771 = qvalue(elt(env, 7)); // !*notseparate
    if (v_32771 == nil) goto v_32227;
    goto v_32224;
v_32227:
    goto v_32238;
v_32234:
    stack[-2] = stack[-5];
    goto v_32235;
v_32236:
    goto v_32245;
v_32241:
    stack[0] = stack[-3];
    goto v_32242;
v_32243:
    goto v_32252;
v_32248:
    v_32772 = stack[-1];
    goto v_32249;
v_32250:
    v_32771 = stack[-3];
    goto v_32251;
v_32252:
    goto v_32248;
v_32249:
    goto v_32250;
v_32251:
    v_32771 = quot2(v_32772, v_32771);
    env = stack[-7];
    stack[-1] = v_32771;
    goto v_32244;
v_32245:
    goto v_32241;
v_32242:
    goto v_32243;
v_32244:
    v_32771 = times2(stack[0], v_32771);
    env = stack[-7];
    goto v_32237;
v_32238:
    goto v_32234;
v_32235:
    goto v_32236;
v_32237:
    v_32771 = difference2(stack[-2], v_32771);
    env = stack[-7];
    stack[-5] = v_32771;
    goto v_32264;
v_32260:
    v_32772 = stack[-5];
    goto v_32261;
v_32262:
    v_32771 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32263;
v_32264:
    goto v_32260;
v_32261:
    goto v_32262;
v_32263:
    v_32771 = (LispObject)lessp2(v_32772, v_32771);
    v_32771 = v_32771 ? lisp_true : nil;
    env = stack[-7];
    if (v_32771 == nil) goto v_32258;
    v_32771 = stack[-1];
    v_32771 = sub1(v_32771);
    env = stack[-7];
    stack[-1] = v_32771;
    goto v_32274;
v_32270:
    v_32772 = stack[-5];
    goto v_32271;
v_32272:
    v_32771 = stack[-3];
    goto v_32273;
v_32274:
    goto v_32270;
v_32271:
    goto v_32272;
v_32273:
    v_32771 = plus2(v_32772, v_32771);
    env = stack[-7];
    stack[-5] = v_32771;
    goto v_32256;
v_32258:
v_32256:
    goto v_32222;
v_32224:
    v_32771 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_32771;
    goto v_32222;
v_32222:
    goto v_32286;
v_32282:
    v_32772 = stack[-4];
    goto v_32283;
v_32284:
    v_32771 = stack[-1];
    goto v_32285;
v_32286:
    goto v_32282;
v_32283:
    goto v_32284;
v_32285:
    v_32771 = list2(v_32772, v_32771);
    env = stack[-7];
    fn = elt(env, 19); // simpexpt
    v_32771 = (*qfn1(fn))(fn, v_32771);
    env = stack[-7];
    stack[0] = v_32771;
    goto v_32297;
v_32293:
    v_32772 = stack[-5];
    goto v_32294;
v_32295:
    v_32771 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32296;
v_32297:
    goto v_32293;
v_32294:
    goto v_32295;
v_32296:
    if (v_32772 == v_32771) goto v_32291;
    else goto v_32292;
v_32291:
    v_32771 = stack[0];
    goto v_31890;
v_32292:
    goto v_32311;
v_32307:
    v_32772 = stack[-3];
    goto v_32308;
v_32309:
    v_32771 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_32310;
v_32311:
    goto v_32307;
v_32308:
    goto v_32309;
v_32310:
    if (v_32772 == v_32771) goto v_32305;
    else goto v_32306;
v_32305:
    v_32771 = qvalue(elt(env, 8)); // !*keepsqrts
    goto v_32304;
v_32306:
    v_32771 = nil;
    goto v_32304;
    v_32771 = nil;
v_32304:
    if (v_32771 == nil) goto v_32302;
    goto v_32323;
v_32319:
    stack[-1] = stack[0];
    goto v_32320;
v_32321:
    goto v_32330;
v_32326:
    v_32771 = elt(env, 9); // sqrt
    if (!symbolp(v_32771)) stack[0] = nil;
    else { stack[0] = qfastgets(v_32771);
           if (stack[0] != nil) { stack[0] = elt(stack[0], 22); // simpfn
#ifdef RECORD_GET
             if (stack[0] != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                stack[0] = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (stack[0] == SPID_NOPROP) stack[0] = nil; }}
#endif
    goto v_32327;
v_32328:
    v_32771 = stack[-4];
    v_32771 = ncons(v_32771);
    env = stack[-7];
    goto v_32329;
v_32330:
    goto v_32326;
v_32327:
    goto v_32328;
v_32329:
    v_32771 = Lapply1(nil, stack[0], v_32771);
    env = stack[-7];
    goto v_32322;
v_32323:
    goto v_32319;
v_32320:
    goto v_32321;
v_32322:
    fn = elt(env, 20); // multsq
    v_32771 = (*qfn2(fn))(fn, stack[-1], v_32771);
    env = stack[-7];
    stack[0] = v_32771;
    goto v_32344;
v_32340:
    v_32772 = stack[-5];
    goto v_32341;
v_32342:
    v_32771 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32343;
v_32344:
    goto v_32340;
v_32341:
    goto v_32342;
v_32343:
    v_32771 = (LispObject)lessp2(v_32772, v_32771);
    v_32771 = v_32771 ? lisp_true : nil;
    env = stack[-7];
    if (v_32771 == nil) goto v_32338;
    v_32771 = stack[0];
    fn = elt(env, 24); // invsq
    v_32771 = (*qfn1(fn))(fn, v_32771);
    env = stack[-7];
    stack[0] = v_32771;
    v_32771 = stack[-5];
    v_32771 = negate(v_32771);
    env = stack[-7];
    stack[-5] = v_32771;
    goto v_32336;
v_32338:
v_32336:
    goto v_32356;
v_32352:
    v_32772 = stack[0];
    goto v_32353;
v_32354:
    v_32771 = stack[-5];
    goto v_32355;
v_32356:
    goto v_32352;
v_32353:
    goto v_32354;
v_32355:
    {
        fn = elt(env, 25); // exptsq
        return (*qfn2(fn))(fn, v_32772, v_32771);
    }
v_32302:
    goto v_32366;
v_32362:
    goto v_32363;
v_32364:
    goto v_32373;
v_32369:
    goto v_32379;
v_32375:
    v_32771 = stack[-4];
    fn = elt(env, 26); // simp!*
    v_32772 = (*qfn1(fn))(fn, v_32771);
    env = stack[-7];
    goto v_32376;
v_32377:
    v_32771 = stack[-3];
    goto v_32378;
v_32379:
    goto v_32375;
v_32376:
    goto v_32377;
v_32378:
    fn = elt(env, 27); // simprad
    v_32772 = (*qfn2(fn))(fn, v_32772, v_32771);
    env = stack[-7];
    goto v_32370;
v_32371:
    v_32771 = stack[-5];
    goto v_32372;
v_32373:
    goto v_32369;
v_32370:
    goto v_32371;
v_32372:
    fn = elt(env, 25); // exptsq
    v_32771 = (*qfn2(fn))(fn, v_32772, v_32771);
    env = stack[-7];
    goto v_32365;
v_32366:
    goto v_32362;
v_32363:
    goto v_32364;
v_32365:
    {
        LispObject v_32782 = stack[0];
        fn = elt(env, 20); // multsq
        return (*qfn2(fn))(fn, v_32782, v_32771);
    }
    goto v_32208;
v_32210:
    v_32771 = stack[-1];
    stack[-5] = v_32771;
    v_32771 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_32771;
    goto v_32208;
v_32208:
    goto v_32196;
v_32204:
    v_32771 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_32771;
    goto v_32196;
v_32196:
    goto v_32191;
v_32193:
    v_32771 = stack[-1];
    if (!consp(v_32771)) goto v_32391;
    else goto v_32392;
v_32391:
    v_32771 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_32771;
    goto v_32191;
v_32392:
    goto v_32401;
v_32397:
    v_32771 = stack[-1];
    v_32772 = qcar(v_32771);
    goto v_32398;
v_32399:
    v_32771 = elt(env, 10); // minus
    goto v_32400;
v_32401:
    goto v_32397;
v_32398:
    goto v_32399;
v_32400:
    if (v_32772 == v_32771) goto v_32395;
    else goto v_32396;
v_32395:
    v_32771 = stack[-1];
    v_32771 = qcdr(v_32771);
    v_32771 = qcar(v_32771);
    stack[-1] = v_32771;
    goto v_31892;
v_32396:
    goto v_32418;
v_32414:
    v_32771 = stack[-1];
    v_32772 = qcar(v_32771);
    goto v_32415;
v_32416:
    v_32771 = elt(env, 11); // plus
    goto v_32417;
v_32418:
    goto v_32414;
v_32415:
    goto v_32416;
v_32417:
    if (v_32772 == v_32771) goto v_32412;
    else goto v_32413;
v_32412:
    v_32771 = qvalue(elt(env, 12)); // !*expandexpt
    goto v_32411;
v_32413:
    v_32771 = nil;
    goto v_32411;
    v_32771 = nil;
v_32411:
    if (v_32771 == nil) goto v_32409;
    goto v_32431;
v_32427:
    v_32772 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32428;
v_32429:
    v_32771 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32430;
v_32431:
    goto v_32427;
v_32428:
    goto v_32429;
v_32430:
    v_32771 = cons(v_32772, v_32771);
    env = stack[-7];
    stack[-5] = v_32771;
    v_32771 = stack[-1];
    v_32771 = qcdr(v_32771);
    stack[-2] = v_32771;
v_32437:
    v_32771 = stack[-2];
    if (v_32771 == nil) goto v_32442;
    else goto v_32443;
v_32442:
    goto v_32436;
v_32443:
    v_32771 = stack[-2];
    v_32771 = qcar(v_32771);
    goto v_32454;
v_32450:
    goto v_32461;
v_32457:
    stack[-1] = stack[-4];
    goto v_32458;
v_32459:
    goto v_32470;
v_32464:
    stack[0] = elt(env, 2); // quotient
    goto v_32465;
v_32466:
    v_32772 = stack[-6];
    if (v_32772 == nil) goto v_32475;
    goto v_32482;
v_32478:
    v_32772 = elt(env, 10); // minus
    goto v_32479;
v_32480:
    goto v_32481;
v_32482:
    goto v_32478;
v_32479:
    goto v_32480;
v_32481:
    v_32771 = list2(v_32772, v_32771);
    env = stack[-7];
    v_32772 = v_32771;
    goto v_32473;
v_32475:
    v_32772 = v_32771;
    goto v_32473;
    v_32772 = nil;
v_32473:
    goto v_32467;
v_32468:
    v_32771 = stack[-3];
    goto v_32469;
v_32470:
    goto v_32464;
v_32465:
    goto v_32466;
v_32467:
    goto v_32468;
v_32469:
    v_32771 = list3(stack[0], v_32772, v_32771);
    env = stack[-7];
    goto v_32460;
v_32461:
    goto v_32457;
v_32458:
    goto v_32459;
v_32460:
    v_32771 = list2(stack[-1], v_32771);
    env = stack[-7];
    fn = elt(env, 19); // simpexpt
    v_32772 = (*qfn1(fn))(fn, v_32771);
    env = stack[-7];
    goto v_32451;
v_32452:
    v_32771 = stack[-5];
    goto v_32453;
v_32454:
    goto v_32450;
v_32451:
    goto v_32452;
v_32453:
    fn = elt(env, 20); // multsq
    v_32771 = (*qfn2(fn))(fn, v_32772, v_32771);
    env = stack[-7];
    stack[-5] = v_32771;
    v_32771 = stack[-2];
    v_32771 = qcdr(v_32771);
    stack[-2] = v_32771;
    goto v_32437;
v_32436:
    v_32771 = stack[-5];
    goto v_31890;
v_32409:
    goto v_32503;
v_32499:
    v_32771 = stack[-1];
    v_32772 = qcar(v_32771);
    goto v_32500;
v_32501:
    v_32771 = elt(env, 13); // times
    goto v_32502;
v_32503:
    goto v_32499;
v_32500:
    goto v_32501;
v_32502:
    if (v_32772 == v_32771) goto v_32497;
    else goto v_32498;
v_32497:
    v_32771 = stack[-1];
    v_32771 = qcdr(v_32771);
    v_32771 = qcar(v_32771);
    v_32771 = integerp(v_32771);
    goto v_32496;
v_32498:
    v_32771 = nil;
    goto v_32496;
    v_32771 = nil;
v_32496:
    if (v_32771 == nil) goto v_32494;
    v_32771 = stack[-3];
    if (is_number(v_32771)) goto v_32516;
    else goto v_32517;
v_32516:
    goto v_32524;
v_32520:
    v_32772 = stack[-3];
    goto v_32521;
v_32522:
    v_32771 = stack[-1];
    v_32771 = qcdr(v_32771);
    v_32771 = qcar(v_32771);
    goto v_32523;
v_32524:
    goto v_32520;
v_32521:
    goto v_32522;
v_32523:
    v_32771 = Lgcd(nil, v_32772, v_32771);
    env = stack[-7];
    stack[-5] = v_32771;
    goto v_32534;
v_32530:
    v_32772 = stack[-3];
    goto v_32531;
v_32532:
    v_32771 = stack[-5];
    goto v_32533;
v_32534:
    goto v_32530;
v_32531:
    goto v_32532;
v_32533:
    v_32771 = quot2(v_32772, v_32771);
    env = stack[-7];
    stack[-3] = v_32771;
    goto v_32542;
v_32538:
    v_32771 = stack[-1];
    v_32771 = qcdr(v_32771);
    v_32772 = qcar(v_32771);
    goto v_32539;
v_32540:
    v_32771 = stack[-5];
    goto v_32541;
v_32542:
    goto v_32538;
v_32539:
    goto v_32540;
v_32541:
    v_32771 = quot2(v_32772, v_32771);
    env = stack[-7];
    stack[-5] = v_32771;
    goto v_32515;
v_32517:
    v_32771 = stack[-1];
    v_32771 = qcdr(v_32771);
    v_32771 = qcar(v_32771);
    stack[-5] = v_32771;
    goto v_32515;
v_32515:
    v_32771 = stack[-1];
    v_32771 = qcdr(v_32771);
    v_32771 = qcdr(v_32771);
    v_32771 = qcdr(v_32771);
    if (v_32771 == nil) goto v_32555;
    goto v_32565;
v_32561:
    v_32772 = elt(env, 13); // times
    goto v_32562;
v_32563:
    v_32771 = stack[-1];
    v_32771 = qcdr(v_32771);
    v_32771 = qcdr(v_32771);
    goto v_32564;
v_32565:
    goto v_32561;
v_32562:
    goto v_32563;
v_32564:
    v_32771 = cons(v_32772, v_32771);
    env = stack[-7];
    goto v_32553;
v_32555:
    v_32771 = stack[-1];
    v_32771 = qcdr(v_32771);
    v_32771 = qcdr(v_32771);
    v_32771 = qcar(v_32771);
    goto v_32553;
    v_32771 = nil;
v_32553:
    stack[-1] = v_32771;
    goto v_32191;
v_32494:
    goto v_32586;
v_32582:
    v_32771 = stack[-1];
    v_32772 = qcar(v_32771);
    goto v_32583;
v_32584:
    v_32771 = elt(env, 2); // quotient
    goto v_32585;
v_32586:
    goto v_32582;
v_32583:
    goto v_32584;
v_32585:
    if (v_32772 == v_32771) goto v_32580;
    else goto v_32581;
v_32580:
    goto v_32598;
v_32594:
    v_32772 = stack[-3];
    goto v_32595;
v_32596:
    v_32771 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32597;
v_32598:
    goto v_32594;
v_32595:
    goto v_32596;
v_32597:
    if (v_32772 == v_32771) goto v_32592;
    else goto v_32593;
v_32592:
    v_32771 = qvalue(elt(env, 12)); // !*expandexpt
    goto v_32591;
v_32593:
    v_32771 = nil;
    goto v_32591;
    v_32771 = nil;
v_32591:
    goto v_32579;
v_32581:
    v_32771 = nil;
    goto v_32579;
    v_32771 = nil;
v_32579:
    if (v_32771 == nil) goto v_32577;
    v_32771 = stack[-1];
    v_32771 = qcdr(v_32771);
    v_32771 = qcdr(v_32771);
    v_32771 = qcar(v_32771);
    stack[-3] = v_32771;
    v_32771 = stack[-1];
    v_32771 = qcdr(v_32771);
    v_32771 = qcar(v_32771);
    stack[-1] = v_32771;
    goto v_31891;
v_32577:
    v_32771 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_32771;
    goto v_32191;
v_32191:
    v_32771 = stack[-4];
    if (symbolp(v_32771)) goto v_32622;
    else goto v_32621;
v_32622:
    goto v_32630;
v_32626:
    v_32772 = stack[-4];
    goto v_32627;
v_32628:
    v_32771 = elt(env, 14); // used!*
    goto v_32629;
v_32630:
    goto v_32626;
v_32627:
    goto v_32628;
v_32629:
    v_32771 = Lflagp(nil, v_32772, v_32771);
    env = stack[-7];
    if (v_32771 == nil) goto v_32624;
    else goto v_32621;
v_32624:
    goto v_32638;
v_32634:
    v_32771 = stack[-4];
    v_32772 = ncons(v_32771);
    env = stack[-7];
    goto v_32635;
v_32636:
    v_32771 = elt(env, 14); // used!*
    goto v_32637;
v_32638:
    goto v_32634;
v_32635:
    goto v_32636;
v_32637:
    v_32771 = Lflag(nil, v_32772, v_32771);
    env = stack[-7];
    goto v_32619;
v_32621:
v_32619:
    goto v_32654;
v_32650:
    v_32772 = stack[-4];
    goto v_32651;
v_32652:
    v_32771 = elt(env, 15); // (minus 1)
    goto v_32653;
v_32654:
    goto v_32650;
v_32651:
    goto v_32652;
v_32653:
    if (equal(v_32772, v_32771)) goto v_32648;
    else goto v_32649;
v_32648:
    goto v_32665;
v_32661:
    v_32772 = stack[-3];
    goto v_32662;
v_32663:
    v_32771 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32664;
v_32665:
    goto v_32661;
v_32662:
    goto v_32663;
v_32664:
    if (v_32772 == v_32771) goto v_32659;
    else goto v_32660;
v_32659:
    goto v_32676;
v_32670:
    v_32773 = elt(env, 16); // difference
    goto v_32671;
v_32672:
    v_32772 = stack[-1];
    goto v_32673;
v_32674:
    v_32771 = elt(env, 17); // (quotient 1 2)
    goto v_32675;
v_32676:
    goto v_32670;
v_32671:
    goto v_32672;
v_32673:
    goto v_32674;
v_32675:
    v_32771 = list3(v_32773, v_32772, v_32771);
    env = stack[-7];
    fn = elt(env, 18); // simp
    v_32771 = (*qfn1(fn))(fn, v_32771);
    env = stack[-7];
    v_32771 = qcar(v_32771);
    v_32771 = (v_32771 == nil ? lisp_true : nil);
    goto v_32658;
v_32660:
    v_32771 = nil;
    goto v_32658;
    v_32771 = nil;
v_32658:
    goto v_32647;
v_32649:
    v_32771 = nil;
    goto v_32647;
    v_32771 = nil;
v_32647:
    if (v_32771 == nil) goto v_32645;
    v_32771 = elt(env, 4); // i
    fn = elt(env, 18); // simp
    v_32771 = (*qfn1(fn))(fn, v_32771);
    env = stack[-7];
    stack[-4] = v_32771;
    v_32771 = stack[-6];
    if (v_32771 == nil) goto v_32693;
    v_32771 = stack[-4];
    {
        fn = elt(env, 21); // negsq
        return (*qfn1(fn))(fn, v_32771);
    }
v_32693:
    v_32771 = stack[-4];
    goto v_32691;
    v_32771 = nil;
v_32691:
    goto v_31890;
v_32645:
    goto v_32707;
v_32701:
    stack[0] = elt(env, 3); // expt
    goto v_32702;
v_32703:
    stack[-2] = stack[-4];
    goto v_32704;
v_32705:
    goto v_32718;
v_32714:
    v_32772 = stack[-3];
    goto v_32715;
v_32716:
    v_32771 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32717;
v_32718:
    goto v_32714;
v_32715:
    goto v_32716;
v_32717:
    if (v_32772 == v_32771) goto v_32712;
    else goto v_32713;
v_32712:
    v_32771 = stack[-1];
    goto v_32711;
v_32713:
    goto v_32731;
v_32725:
    v_32773 = elt(env, 2); // quotient
    goto v_32726;
v_32727:
    v_32772 = stack[-1];
    goto v_32728;
v_32729:
    v_32771 = stack[-3];
    goto v_32730;
v_32731:
    goto v_32725;
v_32726:
    goto v_32727;
v_32728:
    goto v_32729;
v_32730:
    v_32771 = list3(v_32773, v_32772, v_32771);
    env = stack[-7];
    goto v_32711;
    v_32771 = nil;
v_32711:
    goto v_32706;
v_32707:
    goto v_32701;
v_32702:
    goto v_32703;
v_32704:
    goto v_32705;
v_32706:
    v_32771 = list3(stack[0], stack[-2], v_32771);
    env = stack[-7];
    stack[-4] = v_32771;
    goto v_32740;
v_32736:
    stack[0] = stack[-4];
    goto v_32737;
v_32738:
    v_32771 = stack[-6];
    if (v_32771 == nil) goto v_32745;
    v_32771 = stack[-5];
    v_32771 = negate(v_32771);
    env = stack[-7];
    goto v_32743;
v_32745:
    v_32771 = stack[-5];
    goto v_32743;
    v_32771 = nil;
v_32743:
    goto v_32739;
v_32740:
    goto v_32736;
v_32737:
    goto v_32738;
v_32739:
    {
        LispObject v_32783 = stack[0];
        fn = elt(env, 23); // mksq
        return (*qfn2(fn))(fn, v_32783, v_32771);
    }
v_31892:
    v_32771 = qvalue(elt(env, 6)); // !*mcd
    if (v_32771 == nil) goto v_32755;
    goto v_32765;
v_32759:
    v_32773 = stack[-4];
    goto v_32760;
v_32761:
    v_32772 = stack[-1];
    goto v_32762;
v_32763:
    v_32771 = stack[-3];
    goto v_32764;
v_32765:
    goto v_32759;
v_32760:
    goto v_32761;
v_32762:
    goto v_32763;
v_32764:
    v_32771 = CC_simpx1(elt(env, 0), 3, v_32773, v_32772, v_32771);
    env = stack[-7];
    {
        fn = elt(env, 24); // invsq
        return (*qfn1(fn))(fn, v_32771);
    }
v_32755:
    v_32771 = stack[-6];
    v_32771 = (v_32771 == nil ? lisp_true : nil);
    stack[-6] = v_32771;
    goto v_31891;
v_31890:
    return onevalue(v_32771);
}



// Code for depend!-p

static LispObject CC_dependKp(LispObject env,
                         LispObject v_31882, LispObject v_31883)
{
    env = qenv(env);
    LispObject v_31944, v_31945, v_31946, v_31947;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31946 = v_31883;
    v_31947 = v_31882;
// end of prologue
    goto v_31893;
v_31889:
    v_31945 = v_31947;
    goto v_31890;
v_31891:
    v_31944 = v_31946;
    goto v_31892;
v_31893:
    goto v_31889;
v_31890:
    goto v_31891;
v_31892:
    if (v_31945 == v_31944) goto v_31887;
    else goto v_31888;
v_31887:
    v_31944 = lisp_true;
    goto v_31886;
v_31888:
    v_31944 = v_31947;
    if (!consp(v_31944)) goto v_31897;
    else goto v_31898;
v_31897:
    v_31944 = nil;
    goto v_31886;
v_31898:
    v_31944 = v_31947;
    v_31944 = qcar(v_31944);
    if (!consp(v_31944)) goto v_31902;
    goto v_31910;
v_31906:
    v_31944 = v_31947;
    goto v_31907;
v_31908:
    v_31945 = v_31946;
    goto v_31909;
v_31910:
    goto v_31906;
v_31907:
    goto v_31908;
v_31909:
    {
        fn = elt(env, 2); // depend!-f
        return (*qfn2(fn))(fn, v_31944, v_31945);
    }
v_31902:
    goto v_31919;
v_31915:
    v_31944 = v_31947;
    v_31945 = qcar(v_31944);
    goto v_31916;
v_31917:
    v_31944 = elt(env, 1); // !*sq
    goto v_31918;
v_31919:
    goto v_31915;
v_31916:
    goto v_31917;
v_31918:
    if (v_31945 == v_31944) goto v_31913;
    else goto v_31914;
v_31913:
    goto v_31928;
v_31924:
    v_31944 = v_31947;
    v_31944 = qcdr(v_31944);
    v_31944 = qcar(v_31944);
    goto v_31925;
v_31926:
    v_31945 = v_31946;
    goto v_31927;
v_31928:
    goto v_31924;
v_31925:
    goto v_31926;
v_31927:
    {
        fn = elt(env, 3); // depend!-sq
        return (*qfn2(fn))(fn, v_31944, v_31945);
    }
v_31914:
    goto v_31940;
v_31936:
    v_31944 = v_31947;
    v_31944 = qcdr(v_31944);
    goto v_31937;
v_31938:
    v_31945 = v_31946;
    goto v_31939;
v_31940:
    goto v_31936;
v_31937:
    goto v_31938;
v_31939:
    {
        fn = elt(env, 4); // depend!-l
        return (*qfn2(fn))(fn, v_31944, v_31945);
    }
    v_31944 = nil;
v_31886:
    return onevalue(v_31944);
}



// Code for pasf_exprng

static LispObject CC_pasf_exprng(LispObject env,
                         LispObject v_31882)
{
    env = qenv(env);
    LispObject v_32208, v_32209, v_32210, v_32211, v_32212, v_32213;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31882);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_32208 = v_31882;
// end of prologue
// Binding !*rlsism
// FLUIDBIND: reloadenv=6 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-6, 1, -4);
    qvalue(elt(env, 1)) = nil; // !*rlsism
    v_32209 = v_32208;
    if (!consp(v_32209)) goto v_31891;
    else goto v_31892;
v_31891:
    v_32209 = v_32208;
    goto v_31890;
v_31892:
    v_32209 = v_32208;
    v_32209 = qcar(v_32209);
    goto v_31890;
    v_32209 = nil;
v_31890:
    stack[-5] = v_32209;
    goto v_31907;
v_31903:
    v_32210 = stack[-5];
    goto v_31904;
v_31905:
    v_32209 = elt(env, 2); // and
    goto v_31906;
v_31907:
    goto v_31903;
v_31904:
    goto v_31905;
v_31906:
    if (v_32210 == v_32209) goto v_31901;
    else goto v_31902;
v_31901:
    goto v_31919;
v_31911:
    v_32210 = elt(env, 2); // and
    goto v_31912;
v_31913:
    v_32211 = qcdr(v_32208);
    goto v_31914;
v_31915:
    v_32209 = elt(env, 3); // true
    goto v_31916;
v_31917:
    v_32208 = elt(env, 4); // false
    goto v_31918;
v_31919:
    goto v_31911;
v_31912:
    goto v_31913;
v_31914:
    goto v_31915;
v_31916:
    goto v_31917;
v_31918:
    fn = elt(env, 12); // pasf_exprng!-gand
    v_32208 = (*qfnn(fn))(fn, 4, v_32210, v_32211, v_32209, v_32208);
    goto v_31888;
v_31902:
    goto v_31933;
v_31929:
    v_32210 = stack[-5];
    goto v_31930;
v_31931:
    v_32209 = elt(env, 5); // or
    goto v_31932;
v_31933:
    goto v_31929;
v_31930:
    goto v_31931;
v_31932:
    if (v_32210 == v_32209) goto v_31927;
    else goto v_31928;
v_31927:
    goto v_31945;
v_31937:
    v_32210 = elt(env, 5); // or
    goto v_31938;
v_31939:
    v_32211 = qcdr(v_32208);
    goto v_31940;
v_31941:
    v_32209 = elt(env, 4); // false
    goto v_31942;
v_31943:
    v_32208 = elt(env, 3); // true
    goto v_31944;
v_31945:
    goto v_31937;
v_31938:
    goto v_31939;
v_31940:
    goto v_31941;
v_31942:
    goto v_31943;
v_31944:
    fn = elt(env, 12); // pasf_exprng!-gand
    v_32208 = (*qfnn(fn))(fn, 4, v_32210, v_32211, v_32209, v_32208);
    goto v_31888;
v_31928:
    goto v_31959;
v_31955:
    v_32210 = stack[-5];
    goto v_31956;
v_31957:
    v_32209 = elt(env, 6); // ball
    goto v_31958;
v_31959:
    goto v_31955;
v_31956:
    goto v_31957;
v_31958:
    if (v_32210 == v_32209) goto v_31953;
    else goto v_31954;
v_31953:
    goto v_31975;
v_31963:
    v_32209 = v_32208;
    v_32209 = qcdr(v_32209);
    v_32213 = qcar(v_32209);
    goto v_31964;
v_31965:
    v_32209 = v_32208;
    v_32209 = qcdr(v_32209);
    v_32209 = qcdr(v_32209);
    v_32209 = qcdr(v_32209);
    v_32212 = qcar(v_32209);
    goto v_31966;
v_31967:
    v_32208 = qcdr(v_32208);
    v_32208 = qcdr(v_32208);
    v_32211 = qcar(v_32208);
    goto v_31968;
v_31969:
    v_32210 = elt(env, 2); // and
    goto v_31970;
v_31971:
    v_32209 = elt(env, 3); // true
    goto v_31972;
v_31973:
    v_32208 = elt(env, 4); // false
    goto v_31974;
v_31975:
    goto v_31963;
v_31964:
    goto v_31965;
v_31966:
    goto v_31967;
v_31968:
    goto v_31969;
v_31970:
    goto v_31971;
v_31972:
    goto v_31973;
v_31974:
    fn = elt(env, 13); // pasf_exprng!-gball
    v_32208 = (*qfnn(fn))(fn, 6, v_32213, v_32212, v_32211, v_32210, v_32209, v_32208);
    goto v_31888;
v_31954:
    goto v_31999;
v_31995:
    v_32210 = stack[-5];
    goto v_31996;
v_31997:
    v_32209 = elt(env, 7); // bex
    goto v_31998;
v_31999:
    goto v_31995;
v_31996:
    goto v_31997;
v_31998:
    if (v_32210 == v_32209) goto v_31993;
    else goto v_31994;
v_31993:
    goto v_32015;
v_32003:
    v_32209 = v_32208;
    v_32209 = qcdr(v_32209);
    v_32213 = qcar(v_32209);
    goto v_32004;
v_32005:
    v_32209 = v_32208;
    v_32209 = qcdr(v_32209);
    v_32209 = qcdr(v_32209);
    v_32209 = qcdr(v_32209);
    v_32212 = qcar(v_32209);
    goto v_32006;
v_32007:
    v_32208 = qcdr(v_32208);
    v_32208 = qcdr(v_32208);
    v_32211 = qcar(v_32208);
    goto v_32008;
v_32009:
    v_32210 = elt(env, 5); // or
    goto v_32010;
v_32011:
    v_32209 = elt(env, 4); // false
    goto v_32012;
v_32013:
    v_32208 = elt(env, 3); // true
    goto v_32014;
v_32015:
    goto v_32003;
v_32004:
    goto v_32005;
v_32006:
    goto v_32007;
v_32008:
    goto v_32009;
v_32010:
    goto v_32011;
v_32012:
    goto v_32013;
v_32014:
    fn = elt(env, 13); // pasf_exprng!-gball
    v_32208 = (*qfnn(fn))(fn, 6, v_32213, v_32212, v_32211, v_32210, v_32209, v_32208);
    goto v_31888;
v_31994:
    goto v_32051;
v_32047:
    v_32210 = stack[-5];
    goto v_32048;
v_32049:
    v_32209 = elt(env, 5); // or
    goto v_32050;
v_32051:
    goto v_32047;
v_32048:
    goto v_32049;
v_32050:
    if (v_32210 == v_32209) goto v_32045;
    else goto v_32046;
v_32045:
    v_32209 = lisp_true;
    goto v_32044;
v_32046:
    goto v_32061;
v_32057:
    v_32210 = stack[-5];
    goto v_32058;
v_32059:
    v_32209 = elt(env, 2); // and
    goto v_32060;
v_32061:
    goto v_32057;
v_32058:
    goto v_32059;
v_32060:
    v_32209 = (v_32210 == v_32209 ? lisp_true : nil);
    goto v_32044;
    v_32209 = nil;
v_32044:
    if (v_32209 == nil) goto v_32042;
    v_32209 = lisp_true;
    goto v_32040;
v_32042:
    goto v_32072;
v_32068:
    v_32210 = stack[-5];
    goto v_32069;
v_32070:
    v_32209 = elt(env, 8); // not
    goto v_32071;
v_32072:
    goto v_32068;
v_32069:
    goto v_32070;
v_32071:
    v_32209 = (v_32210 == v_32209 ? lisp_true : nil);
    goto v_32040;
    v_32209 = nil;
v_32040:
    if (v_32209 == nil) goto v_32038;
    v_32209 = lisp_true;
    goto v_32036;
v_32038:
    goto v_32087;
v_32083:
    v_32210 = stack[-5];
    goto v_32084;
v_32085:
    v_32209 = elt(env, 9); // impl
    goto v_32086;
v_32087:
    goto v_32083;
v_32084:
    goto v_32085;
v_32086:
    if (v_32210 == v_32209) goto v_32081;
    else goto v_32082;
v_32081:
    v_32209 = lisp_true;
    goto v_32080;
v_32082:
    goto v_32101;
v_32097:
    v_32210 = stack[-5];
    goto v_32098;
v_32099:
    v_32209 = elt(env, 10); // repl
    goto v_32100;
v_32101:
    goto v_32097;
v_32098:
    goto v_32099;
v_32100:
    if (v_32210 == v_32209) goto v_32095;
    else goto v_32096;
v_32095:
    v_32209 = lisp_true;
    goto v_32094;
v_32096:
    goto v_32111;
v_32107:
    v_32210 = stack[-5];
    goto v_32108;
v_32109:
    v_32209 = elt(env, 11); // equiv
    goto v_32110;
v_32111:
    goto v_32107;
v_32108:
    goto v_32109;
v_32110:
    v_32209 = (v_32210 == v_32209 ? lisp_true : nil);
    goto v_32094;
    v_32209 = nil;
v_32094:
    goto v_32080;
    v_32209 = nil;
v_32080:
    goto v_32036;
    v_32209 = nil;
v_32036:
    if (v_32209 == nil) goto v_32034;
    v_32208 = qcdr(v_32208);
    stack[-3] = v_32208;
    v_32208 = stack[-3];
    if (v_32208 == nil) goto v_32125;
    else goto v_32126;
v_32125:
    v_32208 = nil;
    goto v_32119;
v_32126:
    v_32208 = stack[-3];
    v_32208 = qcar(v_32208);
    v_32208 = CC_pasf_exprng(elt(env, 0), v_32208);
    env = stack[-6];
    v_32208 = ncons(v_32208);
    env = stack[-6];
    stack[-1] = v_32208;
    stack[-2] = v_32208;
v_32120:
    v_32208 = stack[-3];
    v_32208 = qcdr(v_32208);
    stack[-3] = v_32208;
    v_32208 = stack[-3];
    if (v_32208 == nil) goto v_32139;
    else goto v_32140;
v_32139:
    v_32208 = stack[-2];
    goto v_32119;
v_32140:
    goto v_32148;
v_32144:
    stack[0] = stack[-1];
    goto v_32145;
v_32146:
    v_32208 = stack[-3];
    v_32208 = qcar(v_32208);
    v_32208 = CC_pasf_exprng(elt(env, 0), v_32208);
    env = stack[-6];
    v_32208 = ncons(v_32208);
    env = stack[-6];
    goto v_32147;
v_32148:
    goto v_32144;
v_32145:
    goto v_32146;
v_32147:
    v_32208 = Lrplacd(nil, stack[0], v_32208);
    env = stack[-6];
    v_32208 = stack[-1];
    v_32208 = qcdr(v_32208);
    stack[-1] = v_32208;
    goto v_32120;
v_32119:
    v_32209 = v_32208;
    goto v_32165;
v_32159:
    v_32208 = v_32209;
    if (v_32208 == nil) goto v_32169;
    v_32208 = v_32209;
    v_32208 = qcdr(v_32208);
    if (v_32208 == nil) goto v_32169;
    goto v_32180;
v_32176:
    v_32208 = stack[-5];
    goto v_32177;
v_32178:
    goto v_32179;
v_32180:
    goto v_32176;
v_32177:
    goto v_32178;
v_32179:
    v_32208 = cons(v_32208, v_32209);
    env = stack[-6];
    v_32210 = v_32208;
    goto v_32167;
v_32169:
    v_32208 = v_32209;
    if (v_32208 == nil) goto v_32183;
    else goto v_32184;
v_32183:
    goto v_32194;
v_32190:
    v_32209 = stack[-5];
    goto v_32191;
v_32192:
    v_32208 = elt(env, 2); // and
    goto v_32193;
v_32194:
    goto v_32190;
v_32191:
    goto v_32192;
v_32193:
    if (v_32209 == v_32208) goto v_32188;
    else goto v_32189;
v_32188:
    v_32208 = elt(env, 3); // true
    goto v_32187;
v_32189:
    v_32208 = elt(env, 4); // false
    goto v_32187;
    v_32208 = nil;
v_32187:
    v_32210 = v_32208;
    goto v_32167;
v_32184:
    v_32208 = v_32209;
    v_32208 = qcar(v_32208);
    v_32210 = v_32208;
    goto v_32167;
    v_32210 = nil;
v_32167:
    goto v_32160;
v_32161:
    v_32209 = nil;
    goto v_32162;
v_32163:
    v_32208 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_32164;
v_32165:
    goto v_32159;
v_32160:
    goto v_32161;
v_32162:
    goto v_32163;
v_32164:
    fn = elt(env, 14); // cl_simpl
    v_32208 = (*qfnn(fn))(fn, 3, v_32210, v_32209, v_32208);
    goto v_31888;
v_32034:
v_31888:
    ;}  // end of a binding scope
    return onevalue(v_32208);
}



// Code for varsinsf

static LispObject CC_varsinsf(LispObject env,
                         LispObject v_31882, LispObject v_31883)
{
    env = qenv(env);
    LispObject v_31948, v_31949;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31883,v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31882,v_31883);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_31948 = v_31883;
    stack[-1] = v_31882;
// end of prologue
    v_31949 = stack[-1];
    if (!consp(v_31949)) goto v_31891;
    else goto v_31892;
v_31891:
    v_31949 = lisp_true;
    goto v_31890;
v_31892:
    v_31949 = stack[-1];
    v_31949 = qcar(v_31949);
    v_31949 = (consp(v_31949) ? nil : lisp_true);
    goto v_31890;
    v_31949 = nil;
v_31890:
    if (v_31949 == nil) goto v_31888;
    goto v_31886;
v_31888:
v_31907:
    v_31949 = stack[-1];
    if (!consp(v_31949)) goto v_31914;
    else goto v_31915;
v_31914:
    v_31949 = lisp_true;
    goto v_31913;
v_31915:
    v_31949 = stack[-1];
    v_31949 = qcar(v_31949);
    v_31949 = (consp(v_31949) ? nil : lisp_true);
    goto v_31913;
    v_31949 = nil;
v_31913:
    if (v_31949 == nil) goto v_31911;
    goto v_31906;
v_31911:
    goto v_31929;
v_31925:
    v_31949 = stack[-1];
    v_31949 = qcar(v_31949);
    stack[-2] = qcdr(v_31949);
    goto v_31926;
v_31927:
    goto v_31938;
v_31934:
    stack[0] = v_31948;
    goto v_31935;
v_31936:
    v_31948 = stack[-1];
    v_31948 = qcar(v_31948);
    v_31948 = qcar(v_31948);
    v_31948 = qcar(v_31948);
    v_31948 = ncons(v_31948);
    env = stack[-3];
    goto v_31937;
v_31938:
    goto v_31934;
v_31935:
    goto v_31936;
v_31937:
    fn = elt(env, 1); // union
    v_31948 = (*qfn2(fn))(fn, stack[0], v_31948);
    env = stack[-3];
    goto v_31928;
v_31929:
    goto v_31925;
v_31926:
    goto v_31927;
v_31928:
    v_31948 = CC_varsinsf(elt(env, 0), stack[-2], v_31948);
    env = stack[-3];
    v_31949 = stack[-1];
    v_31949 = qcdr(v_31949);
    stack[-1] = v_31949;
    goto v_31907;
v_31906:
    goto v_31886;
    v_31948 = nil;
v_31886:
    return onevalue(v_31948);
}



// Code for mkratnum

static LispObject CC_mkratnum(LispObject env,
                         LispObject v_31882)
{
    env = qenv(env);
    LispObject v_31934, v_31935, v_31936;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31882);
    }
// copy arguments values to proper place
    v_31936 = v_31882;
// end of prologue
    v_31934 = v_31936;
    if (!consp(v_31934)) goto v_31886;
    else goto v_31887;
v_31886:
    v_31934 = v_31936;
    {
        fn = elt(env, 4); // !*i2rn
        return (*qfn1(fn))(fn, v_31934);
    }
v_31887:
    goto v_31897;
v_31893:
    v_31934 = v_31936;
    v_31935 = qcar(v_31934);
    goto v_31894;
v_31895:
    v_31934 = elt(env, 1); // !:gi!:
    goto v_31896;
v_31897:
    goto v_31893;
v_31894:
    goto v_31895;
v_31896:
    if (v_31935 == v_31934) goto v_31891;
    else goto v_31892;
v_31891:
    goto v_31906;
v_31902:
    goto v_31912;
v_31908:
    v_31935 = elt(env, 1); // !:gi!:
    goto v_31909;
v_31910:
    v_31934 = elt(env, 2); // !:crn!:
    goto v_31911;
v_31912:
    goto v_31908;
v_31909:
    goto v_31910;
v_31911:
    v_31934 = get(v_31935, v_31934);
    goto v_31903;
v_31904:
    v_31935 = v_31936;
    goto v_31905;
v_31906:
    goto v_31902;
v_31903:
    goto v_31904;
v_31905:
        return Lapply1(nil, v_31934, v_31935);
v_31892:
    goto v_31923;
v_31919:
    goto v_31929;
v_31925:
    v_31934 = v_31936;
    v_31935 = qcar(v_31934);
    goto v_31926;
v_31927:
    v_31934 = elt(env, 3); // !:rn!:
    goto v_31928;
v_31929:
    goto v_31925;
v_31926:
    goto v_31927;
v_31928:
    v_31934 = get(v_31935, v_31934);
    goto v_31920;
v_31921:
    v_31935 = v_31936;
    goto v_31922;
v_31923:
    goto v_31919;
v_31920:
    goto v_31921;
v_31922:
        return Lapply1(nil, v_31934, v_31935);
    v_31934 = nil;
    return onevalue(v_31934);
}



// Code for xpartitsq

static LispObject CC_xpartitsq(LispObject env,
                         LispObject v_31882)
{
    env = qenv(env);
    LispObject v_32063, v_32064, v_32065;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31882);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_32065 = v_31882;
// end of prologue
    v_32063 = v_32065;
    v_32064 = qcar(v_32063);
    v_32063 = v_32065;
    v_32063 = qcdr(v_32063);
    stack[-2] = v_32064;
    stack[-1] = v_32063;
    v_32063 = stack[-2];
    if (v_32063 == nil) goto v_31892;
    else goto v_31893;
v_31892:
    v_32063 = nil;
    goto v_31891;
v_31893:
    v_32063 = stack[-2];
    if (!consp(v_32063)) goto v_31900;
    else goto v_31901;
v_31900:
    v_32063 = lisp_true;
    goto v_31899;
v_31901:
    v_32063 = stack[-2];
    v_32063 = qcar(v_32063);
    v_32063 = (consp(v_32063) ? nil : lisp_true);
    goto v_31899;
    v_32063 = nil;
v_31899:
    if (v_32063 == nil) goto v_31897;
    goto v_31915;
v_31911:
    v_32063 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31912;
v_31913:
    v_32064 = v_32065;
    goto v_31914;
v_31915:
    goto v_31911;
v_31912:
    goto v_31913;
v_31914:
    v_32063 = cons(v_32063, v_32064);
    return ncons(v_32063);
v_31897:
    goto v_31925;
v_31921:
    v_32063 = stack[-2];
    v_32063 = qcar(v_32063);
    v_32063 = qcar(v_32063);
    v_32063 = qcar(v_32063);
    fn = elt(env, 1); // sfp
    v_32063 = (*qfn1(fn))(fn, v_32063);
    env = stack[-3];
    if (v_32063 == nil) goto v_31929;
    goto v_31940;
v_31936:
    goto v_31946;
v_31942:
    goto v_31953;
v_31949:
    v_32063 = stack[-2];
    v_32063 = qcar(v_32063);
    v_32063 = qcar(v_32063);
    v_32064 = qcar(v_32063);
    goto v_31950;
v_31951:
    v_32063 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31952;
v_31953:
    goto v_31949;
v_31950:
    goto v_31951;
v_31952:
    v_32063 = cons(v_32064, v_32063);
    env = stack[-3];
    v_32064 = CC_xpartitsq(elt(env, 0), v_32063);
    env = stack[-3];
    goto v_31943;
v_31944:
    v_32063 = stack[-2];
    v_32063 = qcar(v_32063);
    v_32063 = qcar(v_32063);
    v_32063 = qcdr(v_32063);
    goto v_31945;
v_31946:
    goto v_31942;
v_31943:
    goto v_31944;
v_31945:
    fn = elt(env, 2); // xexptpf
    stack[0] = (*qfn2(fn))(fn, v_32064, v_32063);
    env = stack[-3];
    goto v_31937;
v_31938:
    goto v_31970;
v_31966:
    v_32063 = stack[-2];
    v_32063 = qcar(v_32063);
    v_32064 = qcdr(v_32063);
    goto v_31967;
v_31968:
    v_32063 = stack[-1];
    goto v_31969;
v_31970:
    goto v_31966;
v_31967:
    goto v_31968;
v_31969:
    v_32063 = cons(v_32064, v_32063);
    env = stack[-3];
    fn = elt(env, 3); // cancel
    v_32063 = (*qfn1(fn))(fn, v_32063);
    env = stack[-3];
    v_32063 = CC_xpartitsq(elt(env, 0), v_32063);
    env = stack[-3];
    goto v_31939;
v_31940:
    goto v_31936;
v_31937:
    goto v_31938;
v_31939:
    fn = elt(env, 4); // wedgepf
    v_32063 = (*qfn2(fn))(fn, stack[0], v_32063);
    env = stack[-3];
    stack[0] = v_32063;
    goto v_31927;
v_31929:
    v_32063 = stack[-2];
    v_32063 = qcar(v_32063);
    v_32063 = qcar(v_32063);
    v_32063 = qcar(v_32063);
    fn = elt(env, 5); // xvarp
    v_32063 = (*qfn1(fn))(fn, v_32063);
    env = stack[-3];
    if (v_32063 == nil) goto v_31976;
    goto v_31987;
v_31983:
    goto v_31993;
v_31989:
    v_32063 = stack[-2];
    v_32063 = qcar(v_32063);
    v_32063 = qcar(v_32063);
    v_32063 = qcar(v_32063);
    fn = elt(env, 6); // xpartitk
    v_32064 = (*qfn1(fn))(fn, v_32063);
    env = stack[-3];
    goto v_31990;
v_31991:
    v_32063 = stack[-2];
    v_32063 = qcar(v_32063);
    v_32063 = qcar(v_32063);
    v_32063 = qcdr(v_32063);
    goto v_31992;
v_31993:
    goto v_31989;
v_31990:
    goto v_31991;
v_31992:
    fn = elt(env, 2); // xexptpf
    stack[0] = (*qfn2(fn))(fn, v_32064, v_32063);
    env = stack[-3];
    goto v_31984;
v_31985:
    goto v_32010;
v_32006:
    v_32063 = stack[-2];
    v_32063 = qcar(v_32063);
    v_32064 = qcdr(v_32063);
    goto v_32007;
v_32008:
    v_32063 = stack[-1];
    goto v_32009;
v_32010:
    goto v_32006;
v_32007:
    goto v_32008;
v_32009:
    v_32063 = cons(v_32064, v_32063);
    env = stack[-3];
    fn = elt(env, 3); // cancel
    v_32063 = (*qfn1(fn))(fn, v_32063);
    env = stack[-3];
    v_32063 = CC_xpartitsq(elt(env, 0), v_32063);
    env = stack[-3];
    goto v_31986;
v_31987:
    goto v_31983;
v_31984:
    goto v_31985;
v_31986:
    fn = elt(env, 4); // wedgepf
    v_32063 = (*qfn2(fn))(fn, stack[0], v_32063);
    env = stack[-3];
    stack[0] = v_32063;
    goto v_31927;
v_31976:
    goto v_32022;
v_32018:
    goto v_32030;
v_32026:
    v_32063 = stack[-2];
    v_32063 = qcar(v_32063);
    v_32064 = qcdr(v_32063);
    goto v_32027;
v_32028:
    v_32063 = stack[-1];
    goto v_32029;
v_32030:
    goto v_32026;
v_32027:
    goto v_32028;
v_32029:
    v_32063 = cons(v_32064, v_32063);
    env = stack[-3];
    fn = elt(env, 3); // cancel
    v_32063 = (*qfn1(fn))(fn, v_32063);
    env = stack[-3];
    stack[0] = CC_xpartitsq(elt(env, 0), v_32063);
    env = stack[-3];
    goto v_32019;
v_32020:
    goto v_32040;
v_32036:
    goto v_32047;
v_32043:
    v_32063 = stack[-2];
    v_32063 = qcar(v_32063);
    v_32064 = qcar(v_32063);
    goto v_32044;
v_32045:
    v_32063 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32046;
v_32047:
    goto v_32043;
v_32044:
    goto v_32045;
v_32046:
    v_32063 = cons(v_32064, v_32063);
    env = stack[-3];
    v_32064 = ncons(v_32063);
    env = stack[-3];
    goto v_32037;
v_32038:
    v_32063 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32039;
v_32040:
    goto v_32036;
v_32037:
    goto v_32038;
v_32039:
    v_32063 = cons(v_32064, v_32063);
    env = stack[-3];
    goto v_32021;
v_32022:
    goto v_32018;
v_32019:
    goto v_32020;
v_32021:
    fn = elt(env, 7); // multpfsq
    v_32063 = (*qfn2(fn))(fn, stack[0], v_32063);
    env = stack[-3];
    stack[0] = v_32063;
    goto v_31927;
    stack[0] = nil;
v_31927:
    goto v_31922;
v_31923:
    goto v_32059;
v_32055:
    v_32063 = stack[-2];
    v_32064 = qcdr(v_32063);
    goto v_32056;
v_32057:
    v_32063 = stack[-1];
    goto v_32058;
v_32059:
    goto v_32055;
v_32056:
    goto v_32057;
v_32058:
    v_32063 = cons(v_32064, v_32063);
    env = stack[-3];
    v_32063 = CC_xpartitsq(elt(env, 0), v_32063);
    env = stack[-3];
    goto v_31924;
v_31925:
    goto v_31921;
v_31922:
    goto v_31923;
v_31924:
    {
        LispObject v_32069 = stack[0];
        fn = elt(env, 8); // addpf
        return (*qfn2(fn))(fn, v_32069, v_32063);
    }
    v_32063 = nil;
v_31891:
    return onevalue(v_32063);
}



// Code for binc

static LispObject CC_binc(LispObject env,
                         LispObject v_31882, LispObject v_31883)
{
    env = qenv(env);
    LispObject v_31919, v_31920, v_31921;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31883,v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31882,v_31883);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31883;
    v_31921 = v_31882;
// end of prologue
    goto v_31893;
v_31889:
    v_31920 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31890;
v_31891:
    v_31919 = stack[0];
    goto v_31892;
v_31893:
    goto v_31889;
v_31890:
    goto v_31891;
v_31892:
    if (v_31920 == v_31919) goto v_31887;
    else goto v_31888;
v_31887:
    v_31919 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31886;
v_31888:
    goto v_31904;
v_31900:
    goto v_31913;
v_31907:
    goto v_31908;
v_31909:
    v_31920 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31910;
v_31911:
    v_31919 = stack[0];
    goto v_31912;
v_31913:
    goto v_31907;
v_31908:
    goto v_31909;
v_31910:
    goto v_31911;
v_31912:
    fn = elt(env, 1); // mk!-numr
    v_31919 = (*qfnn(fn))(fn, 3, v_31921, v_31920, v_31919);
    env = stack[-2];
    fn = elt(env, 2); // constimes
    stack[-1] = (*qfn1(fn))(fn, v_31919);
    env = stack[-2];
    goto v_31901;
v_31902:
    v_31919 = stack[0];
    fn = elt(env, 3); // factorial
    v_31919 = (*qfn1(fn))(fn, v_31919);
    env = stack[-2];
    goto v_31903;
v_31904:
    goto v_31900;
v_31901:
    goto v_31902;
v_31903:
    {
        LispObject v_31924 = stack[-1];
        fn = elt(env, 4); // listquotient
        return (*qfn2(fn))(fn, v_31924, v_31919);
    }
    v_31919 = nil;
v_31886:
    return onevalue(v_31919);
}



// Code for gi

static LispObject CC_gi(LispObject env,
                         LispObject v_31883, LispObject v_31884)
{
    env = qenv(env);
    LispObject v_31931, v_31932;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31884,v_31883);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31883,v_31884);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_31884;
    v_31931 = v_31883;
// end of prologue
// Binding gg!*
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = v_31931; // gg!*
    stack[-2] = nil;
    v_31931 = qvalue(elt(env, 1)); // gg!*
    stack[-1] = v_31931;
v_31896:
    v_31931 = stack[-1];
    if (v_31931 == nil) goto v_31900;
    else goto v_31901;
v_31900:
    goto v_31895;
v_31901:
    v_31931 = stack[-1];
    v_31931 = qcar(v_31931);
    stack[0] = v_31931;
    goto v_31915;
v_31911:
    v_31931 = stack[0];
    v_31931 = qcdr(v_31931);
    fn = elt(env, 2); // class
    v_31932 = (*qfn1(fn))(fn, v_31931);
    env = stack[-5];
    goto v_31912;
v_31913:
    v_31931 = stack[-3];
    goto v_31914;
v_31915:
    goto v_31911;
v_31912:
    goto v_31913;
v_31914:
    if (equal(v_31932, v_31931)) goto v_31909;
    else goto v_31910;
v_31909:
    goto v_31925;
v_31921:
    v_31932 = stack[0];
    goto v_31922;
v_31923:
    v_31931 = stack[-2];
    goto v_31924;
v_31925:
    goto v_31921;
v_31922:
    goto v_31923;
v_31924:
    v_31931 = cons(v_31932, v_31931);
    env = stack[-5];
    stack[-2] = v_31931;
    goto v_31908;
v_31910:
v_31908:
    v_31931 = stack[-1];
    v_31931 = qcdr(v_31931);
    stack[-1] = v_31931;
    goto v_31896;
v_31895:
    v_31931 = stack[-2];
    ;}  // end of a binding scope
    return onevalue(v_31931);
}



// Code for exports

static LispObject CC_exports(LispObject env,
                         LispObject v_31882)
{
    env = qenv(env);
    LispObject v_31894, v_31895;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31882);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31894 = v_31882;
// end of prologue
    goto v_31891;
v_31887:
    v_31895 = v_31894;
    goto v_31888;
v_31889:
    v_31894 = qvalue(elt(env, 1)); // exportslist!*
    goto v_31890;
v_31891:
    goto v_31887;
v_31888:
    goto v_31889;
v_31890:
    fn = elt(env, 2); // union
    v_31894 = (*qfn2(fn))(fn, v_31895, v_31894);
    env = stack[0];
    qvalue(elt(env, 1)) = v_31894; // exportslist!*
    v_31894 = nil;
    return onevalue(v_31894);
}



// Code for square!-free!-mod!-p

static LispObject CC_squareKfreeKmodKp(LispObject env,
                         LispObject v_31882)
{
    env = qenv(env);
    LispObject v_31923, v_31924;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31882);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31924 = v_31882;
// end of prologue
    v_31923 = v_31924;
    if (!consp(v_31923)) goto v_31890;
    else goto v_31891;
v_31890:
    v_31923 = lisp_true;
    goto v_31889;
v_31891:
    v_31923 = v_31924;
    v_31923 = qcar(v_31923);
    v_31923 = (consp(v_31923) ? nil : lisp_true);
    goto v_31889;
    v_31923 = nil;
v_31889:
    if (v_31923 == nil) goto v_31887;
    v_31923 = lisp_true;
    goto v_31885;
v_31887:
    goto v_31907;
v_31903:
    stack[0] = v_31924;
    goto v_31904;
v_31905:
    v_31923 = v_31924;
    fn = elt(env, 1); // derivative!-mod!-p
    v_31923 = (*qfn1(fn))(fn, v_31923);
    env = stack[-1];
    goto v_31906;
v_31907:
    goto v_31903;
v_31904:
    goto v_31905;
v_31906:
    fn = elt(env, 2); // gcd!-mod!-p
    v_31923 = (*qfn2(fn))(fn, stack[0], v_31923);
    v_31924 = v_31923;
    v_31923 = v_31924;
    if (!consp(v_31923)) goto v_31914;
    else goto v_31915;
v_31914:
    v_31923 = lisp_true;
    goto v_31913;
v_31915:
    v_31923 = v_31924;
    v_31923 = qcar(v_31923);
    v_31923 = (consp(v_31923) ? nil : lisp_true);
    goto v_31913;
    v_31923 = nil;
v_31913:
    goto v_31885;
    v_31923 = nil;
v_31885:
    return onevalue(v_31923);
}



// Code for rat_max

static LispObject CC_rat_max(LispObject env,
                         LispObject v_31882, LispObject v_31883)
{
    env = qenv(env);
    LispObject v_31901, v_31902;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31883,v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31882,v_31883);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_31883;
    stack[-1] = v_31882;
// end of prologue
    goto v_31894;
v_31890:
    v_31902 = stack[-1];
    goto v_31891;
v_31892:
    v_31901 = stack[0];
    goto v_31893;
v_31894:
    goto v_31890;
v_31891:
    goto v_31892;
v_31893:
    fn = elt(env, 1); // rat_leq
    v_31901 = (*qfn2(fn))(fn, v_31902, v_31901);
    if (v_31901 == nil) goto v_31888;
    v_31901 = stack[0];
    goto v_31886;
v_31888:
    v_31901 = stack[-1];
    goto v_31886;
    v_31901 = nil;
v_31886:
    return onevalue(v_31901);
}



// Code for rl_ex

static LispObject CC_rl_ex(LispObject env,
                         LispObject v_31882, LispObject v_31883)
{
    env = qenv(env);
    LispObject v_31900, v_31901;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31883,v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31882,v_31883);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31900 = v_31883;
    v_31901 = v_31882;
// end of prologue
    goto v_31890;
v_31886:
    stack[0] = qvalue(elt(env, 1)); // rl_ex!*
    goto v_31887;
v_31888:
    goto v_31897;
v_31893:
    goto v_31894;
v_31895:
    goto v_31896;
v_31897:
    goto v_31893;
v_31894:
    goto v_31895;
v_31896:
    v_31900 = list2(v_31901, v_31900);
    env = stack[-1];
    goto v_31889;
v_31890:
    goto v_31886;
v_31887:
    goto v_31888;
v_31889:
    {
        LispObject v_31903 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_31903, v_31900);
    }
}



// Code for !*invsq

static LispObject CC_Hinvsq(LispObject env,
                         LispObject v_31882)
{
    env = qenv(env);
    LispObject v_31896, v_31897;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31882);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31897 = v_31882;
// end of prologue
    v_31896 = qvalue(elt(env, 1)); // sqrtflag
    if (v_31896 == nil) goto v_31887;
    v_31896 = v_31897;
    fn = elt(env, 2); // invsq
    v_31896 = (*qfn1(fn))(fn, v_31896);
    env = stack[0];
    {
        fn = elt(env, 3); // sqrt2top
        return (*qfn1(fn))(fn, v_31896);
    }
v_31887:
    v_31896 = v_31897;
    {
        fn = elt(env, 2); // invsq
        return (*qfn1(fn))(fn, v_31896);
    }
    v_31896 = nil;
    return onevalue(v_31896);
}



// Code for ofsf_simpat

static LispObject CC_ofsf_simpat(LispObject env,
                         LispObject v_31882)
{
    env = qenv(env);
    LispObject v_32164, v_32165, v_32166;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31882);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_31882;
// end of prologue
    v_32164 = stack[-2];
    v_32164 = qcar(v_32164);
    stack[-3] = v_32164;
    v_32164 = stack[-2];
    v_32164 = qcdr(v_32164);
    v_32164 = qcar(v_32164);
    fn = elt(env, 9); // simp
    v_32164 = (*qfn1(fn))(fn, v_32164);
    env = stack[-4];
    stack[-1] = v_32164;
    v_32164 = qvalue(elt(env, 1)); // !*rlnzden
    if (v_32164 == nil) goto v_31901;
    else goto v_31900;
v_31901:
    v_32164 = qvalue(elt(env, 2)); // !*rlposden
    if (v_32164 == nil) goto v_31904;
    else goto v_31900;
v_31904:
    v_32164 = stack[-1];
    v_32164 = qcdr(v_32164);
    if (!consp(v_32164)) goto v_31909;
    else goto v_31910;
v_31909:
    v_32164 = lisp_true;
    goto v_31908;
v_31910:
    v_32164 = stack[-1];
    v_32164 = qcdr(v_32164);
    v_32164 = qcar(v_32164);
    v_32164 = (consp(v_32164) ? nil : lisp_true);
    goto v_31908;
    v_32164 = nil;
v_31908:
    if (v_32164 == nil) goto v_31906;
    else goto v_31900;
v_31906:
    goto v_31925;
v_31921:
    v_32165 = stack[-2];
    goto v_31922;
v_31923:
    v_32164 = elt(env, 3); // "atomic formula"
    goto v_31924;
v_31925:
    goto v_31921;
v_31922:
    goto v_31923;
v_31924:
    fn = elt(env, 10); // typerr
    v_32164 = (*qfn2(fn))(fn, v_32165, v_32164);
    env = stack[-4];
    goto v_31898;
v_31900:
v_31898:
    v_32164 = stack[-2];
    v_32164 = qcdr(v_32164);
    v_32164 = qcdr(v_32164);
    v_32164 = qcar(v_32164);
    fn = elt(env, 9); // simp
    v_32164 = (*qfn1(fn))(fn, v_32164);
    env = stack[-4];
    stack[0] = v_32164;
    v_32164 = qvalue(elt(env, 1)); // !*rlnzden
    if (v_32164 == nil) goto v_31937;
    else goto v_31936;
v_31937:
    v_32164 = qvalue(elt(env, 2)); // !*rlposden
    if (v_32164 == nil) goto v_31940;
    else goto v_31936;
v_31940:
    v_32164 = stack[0];
    v_32164 = qcdr(v_32164);
    if (!consp(v_32164)) goto v_31945;
    else goto v_31946;
v_31945:
    v_32164 = lisp_true;
    goto v_31944;
v_31946:
    v_32164 = stack[0];
    v_32164 = qcdr(v_32164);
    v_32164 = qcar(v_32164);
    v_32164 = (consp(v_32164) ? nil : lisp_true);
    goto v_31944;
    v_32164 = nil;
v_31944:
    if (v_32164 == nil) goto v_31942;
    else goto v_31936;
v_31942:
    goto v_31961;
v_31957:
    v_32165 = stack[-2];
    goto v_31958;
v_31959:
    v_32164 = elt(env, 3); // "atomic formula"
    goto v_31960;
v_31961:
    goto v_31957;
v_31958:
    goto v_31959;
v_31960:
    fn = elt(env, 10); // typerr
    v_32164 = (*qfn2(fn))(fn, v_32165, v_32164);
    env = stack[-4];
    goto v_31934;
v_31936:
v_31934:
    goto v_31969;
v_31965:
    goto v_31966;
v_31967:
    v_32164 = stack[0];
    fn = elt(env, 11); // negsq
    v_32164 = (*qfn1(fn))(fn, v_32164);
    env = stack[-4];
    goto v_31968;
v_31969:
    goto v_31965;
v_31966:
    goto v_31967;
v_31968:
    fn = elt(env, 12); // addsq
    v_32164 = (*qfn2(fn))(fn, stack[-1], v_32164);
    env = stack[-4];
    stack[-1] = v_32164;
    v_32164 = stack[-1];
    v_32164 = qcar(v_32164);
    v_32165 = v_32164;
    v_32164 = qvalue(elt(env, 2)); // !*rlposden
    if (v_32164 == nil) goto v_31978;
    v_32164 = stack[-1];
    v_32164 = qcdr(v_32164);
    if (!consp(v_32164)) goto v_31984;
    else goto v_31985;
v_31984:
    v_32164 = lisp_true;
    goto v_31983;
v_31985:
    v_32164 = stack[-1];
    v_32164 = qcdr(v_32164);
    v_32164 = qcar(v_32164);
    v_32164 = (consp(v_32164) ? nil : lisp_true);
    goto v_31983;
    v_32164 = nil;
v_31983:
    if (v_32164 == nil) goto v_31981;
    else goto v_31978;
v_31981:
    goto v_32002;
v_31996:
    v_32166 = stack[-3];
    goto v_31997;
v_31998:
    goto v_31999;
v_32000:
    v_32164 = nil;
    goto v_32001;
v_32002:
    goto v_31996;
v_31997:
    goto v_31998;
v_31999:
    goto v_32000;
v_32001:
    v_32164 = list3(v_32166, v_32165, v_32164);
    env = stack[-4];
    stack[0] = v_32164;
    v_32164 = qvalue(elt(env, 4)); // !*rladdcond
    if (v_32164 == nil) goto v_32009;
    goto v_32019;
v_32015:
    v_32165 = stack[-3];
    goto v_32016;
v_32017:
    v_32164 = elt(env, 5); // (lessp leq greaterp geq)
    goto v_32018;
v_32019:
    goto v_32015;
v_32016:
    goto v_32017;
v_32018:
    v_32164 = Lmemq(nil, v_32165, v_32164);
    if (v_32164 == nil) goto v_32014;
    goto v_32030;
v_32024:
    stack[-2] = elt(env, 6); // and
    goto v_32025;
v_32026:
    goto v_32039;
v_32033:
    v_32166 = elt(env, 7); // greaterp
    goto v_32034;
v_32035:
    v_32164 = stack[-1];
    v_32165 = qcdr(v_32164);
    goto v_32036;
v_32037:
    v_32164 = nil;
    goto v_32038;
v_32039:
    goto v_32033;
v_32034:
    goto v_32035;
v_32036:
    goto v_32037;
v_32038:
    stack[-1] = list3(v_32166, v_32165, v_32164);
    env = stack[-4];
    goto v_32027;
v_32028:
    v_32164 = stack[0];
    v_32164 = ncons(v_32164);
    env = stack[-4];
    goto v_32029;
v_32030:
    goto v_32024;
v_32025:
    goto v_32026;
v_32027:
    goto v_32028;
v_32029:
    v_32164 = list2star(stack[-2], stack[-1], v_32164);
    goto v_32012;
v_32014:
    goto v_32055;
v_32049:
    stack[-2] = elt(env, 6); // and
    goto v_32050;
v_32051:
    goto v_32064;
v_32058:
    v_32166 = elt(env, 8); // neq
    goto v_32059;
v_32060:
    v_32164 = stack[-1];
    v_32165 = qcdr(v_32164);
    goto v_32061;
v_32062:
    v_32164 = nil;
    goto v_32063;
v_32064:
    goto v_32058;
v_32059:
    goto v_32060;
v_32061:
    goto v_32062;
v_32063:
    stack[-1] = list3(v_32166, v_32165, v_32164);
    env = stack[-4];
    goto v_32052;
v_32053:
    v_32164 = stack[0];
    v_32164 = ncons(v_32164);
    env = stack[-4];
    goto v_32054;
v_32055:
    goto v_32049;
v_32050:
    goto v_32051;
v_32052:
    goto v_32053;
v_32054:
    v_32164 = list2star(stack[-2], stack[-1], v_32164);
    goto v_32012;
    v_32164 = nil;
v_32012:
    stack[0] = v_32164;
    goto v_32007;
v_32009:
v_32007:
    v_32164 = stack[0];
    goto v_31890;
v_31978:
    v_32164 = qvalue(elt(env, 1)); // !*rlnzden
    if (v_32164 == nil) goto v_32075;
    v_32164 = stack[-1];
    v_32164 = qcdr(v_32164);
    if (!consp(v_32164)) goto v_32081;
    else goto v_32082;
v_32081:
    v_32164 = lisp_true;
    goto v_32080;
v_32082:
    v_32164 = stack[-1];
    v_32164 = qcdr(v_32164);
    v_32164 = qcar(v_32164);
    v_32164 = (consp(v_32164) ? nil : lisp_true);
    goto v_32080;
    v_32164 = nil;
v_32080:
    if (v_32164 == nil) goto v_32078;
    else goto v_32075;
v_32078:
    goto v_32100;
v_32096:
    v_32166 = stack[-3];
    goto v_32097;
v_32098:
    v_32164 = elt(env, 5); // (lessp leq greaterp geq)
    goto v_32099;
v_32100:
    goto v_32096;
v_32097:
    goto v_32098;
v_32099:
    v_32164 = Lmemq(nil, v_32166, v_32164);
    if (v_32164 == nil) goto v_32095;
    goto v_32109;
v_32105:
    goto v_32106;
v_32107:
    v_32164 = stack[-1];
    v_32164 = qcdr(v_32164);
    goto v_32108;
v_32109:
    goto v_32105;
v_32106:
    goto v_32107;
v_32108:
    fn = elt(env, 13); // multf
    v_32164 = (*qfn2(fn))(fn, v_32165, v_32164);
    env = stack[-4];
    v_32165 = v_32164;
    goto v_32093;
v_32095:
v_32093:
    goto v_32120;
v_32114:
    v_32166 = stack[-3];
    goto v_32115;
v_32116:
    goto v_32117;
v_32118:
    v_32164 = nil;
    goto v_32119;
v_32120:
    goto v_32114;
v_32115:
    goto v_32116;
v_32117:
    goto v_32118;
v_32119:
    v_32164 = list3(v_32166, v_32165, v_32164);
    env = stack[-4];
    stack[0] = v_32164;
    v_32164 = qvalue(elt(env, 4)); // !*rladdcond
    if (v_32164 == nil) goto v_32127;
    goto v_32136;
v_32130:
    stack[-2] = elt(env, 6); // and
    goto v_32131;
v_32132:
    goto v_32145;
v_32139:
    v_32166 = elt(env, 8); // neq
    goto v_32140;
v_32141:
    v_32164 = stack[-1];
    v_32165 = qcdr(v_32164);
    goto v_32142;
v_32143:
    v_32164 = nil;
    goto v_32144;
v_32145:
    goto v_32139;
v_32140:
    goto v_32141;
v_32142:
    goto v_32143;
v_32144:
    stack[-1] = list3(v_32166, v_32165, v_32164);
    env = stack[-4];
    goto v_32133;
v_32134:
    v_32164 = stack[0];
    v_32164 = ncons(v_32164);
    env = stack[-4];
    goto v_32135;
v_32136:
    goto v_32130;
v_32131:
    goto v_32132;
v_32133:
    goto v_32134;
v_32135:
    v_32164 = list2star(stack[-2], stack[-1], v_32164);
    stack[0] = v_32164;
    goto v_32125;
v_32127:
v_32125:
    v_32164 = stack[0];
    goto v_31890;
v_32075:
    goto v_32160;
v_32154:
    v_32166 = stack[-3];
    goto v_32155;
v_32156:
    goto v_32157;
v_32158:
    v_32164 = nil;
    goto v_32159;
v_32160:
    goto v_32154;
v_32155:
    goto v_32156;
v_32157:
    goto v_32158;
v_32159:
    return list3(v_32166, v_32165, v_32164);
v_31890:
    return onevalue(v_32164);
}



// Code for dip_monp

static LispObject CC_dip_monp(LispObject env,
                         LispObject v_31882)
{
    env = qenv(env);
    LispObject v_31896, v_31897;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31896 = v_31882;
// end of prologue
    v_31897 = v_31896;
    if (v_31897 == nil) goto v_31886;
    else goto v_31887;
v_31886:
    v_31896 = nil;
    goto v_31885;
v_31887:
    v_31896 = qcdr(v_31896);
    v_31896 = qcdr(v_31896);
    v_31896 = (v_31896 == nil ? lisp_true : nil);
    goto v_31885;
    v_31896 = nil;
v_31885:
    return onevalue(v_31896);
}



// Code for sfto_dprpartf1

static LispObject CC_sfto_dprpartf1(LispObject env,
                         LispObject v_31882, LispObject v_31883)
{
    env = qenv(env);
    LispObject v_31905, v_31906;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31883,v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31882,v_31883);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_31905 = v_31883;
    v_31906 = v_31882;
// end of prologue
    goto v_31890;
v_31886:
    goto v_31887;
v_31888:
    goto v_31889;
v_31890:
    goto v_31886;
v_31887:
    goto v_31888;
v_31889:
    fn = elt(env, 1); // quotf
    v_31905 = (*qfn2(fn))(fn, v_31906, v_31905);
    env = stack[-1];
    stack[0] = v_31905;
    v_31905 = stack[0];
    fn = elt(env, 2); // minusf
    v_31905 = (*qfn1(fn))(fn, v_31905);
    env = stack[-1];
    if (v_31905 == nil) goto v_31897;
    v_31905 = stack[0];
    {
        fn = elt(env, 3); // negf
        return (*qfn1(fn))(fn, v_31905);
    }
v_31897:
    v_31905 = stack[0];
    goto v_31895;
    v_31905 = nil;
v_31895:
    return onevalue(v_31905);
}



// Code for subscriptedvarp2

static LispObject CC_subscriptedvarp2(LispObject env,
                         LispObject v_31882)
{
    env = qenv(env);
    LispObject v_31900, v_31901;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31882);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_31900 = v_31882;
// end of prologue
    goto v_31889;
v_31885:
    goto v_31896;
v_31892:
    v_31901 = nil;
    goto v_31893;
v_31894:
    goto v_31895;
v_31896:
    goto v_31892;
v_31893:
    goto v_31894;
v_31895:
    fn = elt(env, 1); // symtabget
    v_31900 = (*qfn2(fn))(fn, v_31901, v_31900);
    env = stack[0];
    v_31901 = Llength(nil, v_31900);
    goto v_31886;
v_31887:
    v_31900 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31888;
v_31889:
    goto v_31885;
v_31886:
    goto v_31887;
v_31888:
        return Lgreaterp(nil, v_31901, v_31900);
}



// Code for !*kp2q

static LispObject CC_Hkp2q(LispObject env,
                         LispObject v_31882, LispObject v_31883)
{
    env = qenv(env);
    LispObject v_31935, v_31936;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31883,v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31882,v_31883);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31883;
    stack[-1] = v_31882;
// end of prologue
    goto v_31894;
v_31890:
    v_31936 = stack[0];
    goto v_31891;
v_31892:
    v_31935 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31893;
v_31894:
    goto v_31890;
v_31891:
    goto v_31892;
v_31893:
    v_31935 = (LispObject)greaterp2(v_31936, v_31935);
    v_31935 = v_31935 ? lisp_true : nil;
    env = stack[-2];
    if (v_31935 == nil) goto v_31888;
    goto v_31902;
v_31898:
    v_31936 = stack[-1];
    goto v_31899;
v_31900:
    v_31935 = stack[0];
    goto v_31901;
v_31902:
    goto v_31898;
v_31899:
    goto v_31900;
v_31901:
    {
        fn = elt(env, 2); // mksq
        return (*qfn2(fn))(fn, v_31936, v_31935);
    }
v_31888:
    v_31935 = stack[0];
    v_31935 = (LispObject)zerop(v_31935);
    v_31935 = v_31935 ? lisp_true : nil;
    env = stack[-2];
    if (v_31935 == nil) goto v_31906;
    goto v_31914;
v_31910:
    v_31936 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31911;
v_31912:
    v_31935 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31913;
v_31914:
    goto v_31910;
v_31911:
    goto v_31912;
v_31913:
    return cons(v_31936, v_31935);
v_31906:
    goto v_31924;
v_31920:
    goto v_31921;
v_31922:
    v_31935 = stack[0];
    v_31935 = negate(v_31935);
    env = stack[-2];
    goto v_31923;
v_31924:
    goto v_31920;
v_31921:
    goto v_31922;
v_31923:
    fn = elt(env, 2); // mksq
    v_31935 = (*qfn2(fn))(fn, stack[-1], v_31935);
    env = stack[-2];
    stack[-1] = v_31935;
    v_31935 = qcar(v_31935);
    if (v_31935 == nil) goto v_31917;
    else goto v_31918;
v_31917:
    v_31935 = elt(env, 1); // "Zero divisor"
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_31935);
    }
v_31918:
    v_31935 = stack[-1];
    {
        fn = elt(env, 4); // revpr
        return (*qfn1(fn))(fn, v_31935);
    }
    v_31935 = nil;
    return onevalue(v_31935);
}



// Code for calc_world

static LispObject CC_calc_world(LispObject env,
                         LispObject v_31882, LispObject v_31883)
{
    env = qenv(env);
    LispObject v_31946, v_31947;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31883,v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31882,v_31883);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_31883;
    stack[-2] = v_31882;
// end of prologue
    goto v_31894;
v_31890:
    stack[0] = stack[-1];
    goto v_31891;
v_31892:
    v_31946 = stack[-2];
    fn = elt(env, 1); // s_world_names
    v_31946 = (*qfn1(fn))(fn, v_31946);
    env = stack[-4];
    goto v_31893;
v_31894:
    goto v_31890;
v_31891:
    goto v_31892;
v_31893:
    fn = elt(env, 2); // actual_alst
    v_31946 = (*qfn2(fn))(fn, stack[0], v_31946);
    env = stack[-4];
    stack[-1] = v_31946;
    v_31946 = stack[-2];
    v_31946 = qcdr(v_31946);
    v_31946 = qcar(v_31946);
    stack[0] = v_31946;
    goto v_31905;
v_31901:
    v_31947 = stack[-1];
    goto v_31902;
v_31903:
    v_31946 = stack[0];
    v_31946 = qcdr(v_31946);
    goto v_31904;
v_31905:
    goto v_31901;
v_31902:
    goto v_31903;
v_31904:
    v_31946 = Lassoc(nil, v_31947, v_31946);
    stack[-3] = v_31946;
    v_31946 = stack[-3];
    if (v_31946 == nil) goto v_31913;
    v_31946 = stack[-3];
    v_31946 = qcdr(v_31946);
    goto v_31888;
v_31913:
    goto v_31923;
v_31919:
    v_31946 = stack[-2];
    v_31946 = qcdr(v_31946);
    v_31946 = qcdr(v_31946);
    v_31947 = qcar(v_31946);
    goto v_31920;
v_31921:
    v_31946 = stack[-1];
    goto v_31922;
v_31923:
    goto v_31919;
v_31920:
    goto v_31921;
v_31922:
    fn = elt(env, 3); // calc_atlas
    v_31946 = (*qfn2(fn))(fn, v_31947, v_31946);
    env = stack[-4];
    fn = elt(env, 4); // reval
    v_31946 = (*qfn1(fn))(fn, v_31946);
    env = stack[-4];
    stack[-3] = v_31946;
    goto v_31934;
v_31930:
    goto v_31931;
v_31932:
    goto v_31942;
v_31938:
    v_31947 = stack[-1];
    goto v_31939;
v_31940:
    v_31946 = stack[-3];
    goto v_31941;
v_31942:
    goto v_31938;
v_31939:
    goto v_31940;
v_31941:
    v_31946 = cons(v_31947, v_31946);
    env = stack[-4];
    v_31946 = ncons(v_31946);
    env = stack[-4];
    goto v_31933;
v_31934:
    goto v_31930;
v_31931:
    goto v_31932;
v_31933:
    v_31946 = Lnconc(nil, stack[0], v_31946);
    v_31946 = stack[-3];
v_31888:
    return onevalue(v_31946);
}



// Code for liendimcom

static LispObject CC_liendimcom(LispObject env,
                         LispObject v_31882)
{
    env = qenv(env);
    LispObject v_33031, v_33032, v_33033, v_33034;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31882);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_31882;
// end of prologue
    v_33031 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-9] = v_33031;
    goto v_31894;
v_31890:
    stack[0] = elt(env, 1); // lie_dim
    goto v_31891;
v_31892:
    v_33031 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 14); // aeval
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_31893;
v_31894:
    goto v_31890;
v_31891:
    goto v_31892;
v_31893:
    fn = elt(env, 15); // setk
    v_33031 = (*qfn2(fn))(fn, stack[0], v_33031);
    env = stack[-10];
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_33031;
v_31901:
    goto v_31915;
v_31909:
    stack[0] = elt(env, 2); // difference
    goto v_31910;
v_31911:
    goto v_31925;
v_31919:
    v_33033 = elt(env, 2); // difference
    goto v_31920;
v_31921:
    v_33032 = stack[-8];
    goto v_31922;
v_31923:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31924;
v_31925:
    goto v_31919;
v_31920:
    goto v_31921;
v_31922:
    goto v_31923;
v_31924:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_31912;
v_31913:
    v_33031 = stack[-3];
    goto v_31914;
v_31915:
    goto v_31909;
v_31910:
    goto v_31911;
v_31912:
    goto v_31913;
v_31914:
    v_33031 = list3(stack[0], v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_31906;
    goto v_31900;
v_31906:
    v_33031 = stack[-3];
    stack[-2] = v_33031;
v_31934:
    goto v_31948;
v_31942:
    stack[0] = elt(env, 2); // difference
    goto v_31943;
v_31944:
    v_33031 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_31945;
v_31946:
    v_33031 = stack[-2];
    goto v_31947;
v_31948:
    goto v_31942;
v_31943:
    goto v_31944;
v_31945:
    goto v_31946;
v_31947:
    v_33031 = list3(stack[0], v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_31939;
    goto v_31933;
v_31939:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_33031;
v_31957:
    goto v_31971;
v_31965:
    stack[0] = elt(env, 2); // difference
    goto v_31966;
v_31967:
    v_33031 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_31968;
v_31969:
    v_33031 = stack[-1];
    goto v_31970;
v_31971:
    goto v_31965;
v_31966:
    goto v_31967;
v_31968:
    goto v_31969;
v_31970:
    v_33031 = list3(stack[0], v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_31962;
    goto v_31956;
v_31962:
    goto v_31986;
v_31982:
    goto v_31997;
v_31989:
    v_33034 = elt(env, 3); // lie_cc
    goto v_31990;
v_31991:
    v_33033 = stack[-3];
    goto v_31992;
v_31993:
    v_33032 = stack[-2];
    goto v_31994;
v_31995:
    v_33031 = stack[-1];
    goto v_31996;
v_31997:
    goto v_31989;
v_31990:
    goto v_31991;
v_31992:
    goto v_31993;
v_31994:
    goto v_31995;
v_31996:
    v_33031 = list4(v_33034, v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_31983;
v_31984:
    v_33031 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31985;
v_31986:
    goto v_31982;
v_31983:
    goto v_31984;
v_31985:
    fn = elt(env, 18); // evalneq
    v_33031 = (*qfn2(fn))(fn, v_33032, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_31980;
    goto v_32008;
v_32004:
    stack[0] = elt(env, 1); // lie_dim
    goto v_32005;
v_32006:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32007;
v_32008:
    goto v_32004;
v_32005:
    goto v_32006;
v_32007:
    fn = elt(env, 15); // setk
    v_33031 = (*qfn2(fn))(fn, stack[0], v_33031);
    env = stack[-10];
    goto v_32017;
v_32013:
    stack[0] = elt(env, 4); // lie_p
    goto v_32014;
v_32015:
    v_33031 = stack[-3];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32016;
v_32017:
    goto v_32013;
v_32014:
    goto v_32015;
v_32016:
    fn = elt(env, 15); // setk
    v_33031 = (*qfn2(fn))(fn, stack[0], v_33031);
    env = stack[-10];
    goto v_32026;
v_32022:
    stack[0] = elt(env, 5); // lie_q
    goto v_32023;
v_32024:
    v_33031 = stack[-2];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32025;
v_32026:
    goto v_32022;
v_32023:
    goto v_32024;
v_32025:
    fn = elt(env, 15); // setk
    v_33031 = (*qfn2(fn))(fn, stack[0], v_33031);
    env = stack[-10];
    v_33031 = stack[-1];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-9] = v_33031;
    v_33031 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-3] = v_33031;
    goto v_32042;
v_32036:
    v_33033 = elt(env, 6); // plus
    goto v_32037;
v_32038:
    v_33032 = stack[-8];
    goto v_32039;
v_32040:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32041;
v_32042:
    goto v_32036;
v_32037:
    goto v_32038;
v_32039:
    goto v_32040;
v_32041:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-1] = v_33031;
    stack[-2] = v_33031;
    goto v_31978;
v_31980:
v_31978:
    v_33031 = stack[-1];
    goto v_32056;
v_32050:
    v_33033 = elt(env, 6); // plus
    goto v_32051;
v_32052:
    v_33032 = v_33031;
    goto v_32053;
v_32054:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32055;
v_32056:
    goto v_32050;
v_32051:
    goto v_32052;
v_32053:
    goto v_32054;
v_32055:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-1] = v_33031;
    goto v_31957;
v_31956:
    v_33031 = stack[-2];
    goto v_32070;
v_32064:
    v_33033 = elt(env, 6); // plus
    goto v_32065;
v_32066:
    v_33032 = v_33031;
    goto v_32067;
v_32068:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32069;
v_32070:
    goto v_32064;
v_32065:
    goto v_32066;
v_32067:
    goto v_32068;
v_32069:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-2] = v_33031;
    goto v_31934;
v_31933:
    v_33031 = stack[-3];
    goto v_32084;
v_32078:
    v_33033 = elt(env, 6); // plus
    goto v_32079;
v_32080:
    v_33032 = v_33031;
    goto v_32081;
v_32082:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32083;
v_32084:
    goto v_32078;
v_32079:
    goto v_32080;
v_32081:
    goto v_32082;
v_32083:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-3] = v_33031;
    goto v_31901;
v_31900:
    goto v_32097;
v_32093:
    v_33031 = elt(env, 1); // lie_dim
    fn = elt(env, 14); // aeval
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32094;
v_32095:
    v_33031 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32096;
v_32097:
    goto v_32093;
v_32094:
    goto v_32095;
v_32096:
    fn = elt(env, 18); // evalneq
    v_33031 = (*qfn2(fn))(fn, v_33032, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32091;
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_33031;
v_32104:
    goto v_32118;
v_32112:
    stack[0] = elt(env, 2); // difference
    goto v_32113;
v_32114:
    goto v_32128;
v_32122:
    v_33033 = elt(env, 2); // difference
    goto v_32123;
v_32124:
    v_33032 = stack[-8];
    goto v_32125;
v_32126:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32127;
v_32128:
    goto v_32122;
v_32123:
    goto v_32124;
v_32125:
    goto v_32126;
v_32127:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32115;
v_32116:
    v_33031 = stack[-5];
    goto v_32117;
v_32118:
    goto v_32112;
v_32113:
    goto v_32114;
v_32115:
    goto v_32116;
v_32117:
    v_33031 = list3(stack[0], v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32109;
    goto v_32103;
v_32109:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_33031;
v_32137:
    goto v_32151;
v_32145:
    stack[0] = elt(env, 2); // difference
    goto v_32146;
v_32147:
    v_33031 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32148;
v_32149:
    v_33031 = stack[-4];
    goto v_32150;
v_32151:
    goto v_32145;
v_32146:
    goto v_32147;
v_32148:
    goto v_32149;
v_32150:
    v_33031 = list3(stack[0], v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32142;
    goto v_32136;
v_32142:
    goto v_32165;
v_32159:
    stack[-1] = elt(env, 7); // quotient
    goto v_32160;
v_32161:
    goto v_32176;
v_32168:
    v_33034 = elt(env, 3); // lie_cc
    goto v_32169;
v_32170:
    v_33033 = stack[-5];
    goto v_32171;
v_32172:
    v_33032 = stack[-4];
    goto v_32173;
v_32174:
    v_33031 = stack[-9];
    goto v_32175;
v_32176:
    goto v_32168;
v_32169:
    goto v_32170;
v_32171:
    goto v_32172;
v_32173:
    goto v_32174;
v_32175:
    stack[0] = list4(v_33034, v_33033, v_33032, v_33031);
    env = stack[-10];
    goto v_32162;
v_32163:
    goto v_32190;
v_32182:
    v_33034 = elt(env, 3); // lie_cc
    goto v_32183;
v_32184:
    v_33033 = elt(env, 4); // lie_p
    goto v_32185;
v_32186:
    v_33032 = elt(env, 5); // lie_q
    goto v_32187;
v_32188:
    v_33031 = stack[-9];
    goto v_32189;
v_32190:
    goto v_32182;
v_32183:
    goto v_32184;
v_32185:
    goto v_32186;
v_32187:
    goto v_32188;
v_32189:
    v_33031 = list4(v_33034, v_33033, v_33032, v_33031);
    env = stack[-10];
    goto v_32164;
v_32165:
    goto v_32159;
v_32160:
    goto v_32161;
v_32162:
    goto v_32163;
v_32164:
    v_33031 = list3(stack[-1], stack[0], v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-6] = v_33031;
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_33031;
v_32198:
    goto v_32212;
v_32206:
    stack[0] = elt(env, 2); // difference
    goto v_32207;
v_32208:
    v_33031 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32209;
v_32210:
    v_33031 = stack[-3];
    goto v_32211;
v_32212:
    goto v_32206;
v_32207:
    goto v_32208;
v_32209:
    goto v_32210;
v_32211:
    v_33031 = list3(stack[0], v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32203;
    goto v_32197;
v_32203:
    goto v_32227;
v_32223:
    goto v_32238;
v_32230:
    v_33034 = elt(env, 3); // lie_cc
    goto v_32231;
v_32232:
    v_33033 = stack[-5];
    goto v_32233;
v_32234:
    v_33032 = stack[-4];
    goto v_32235;
v_32236:
    v_33031 = stack[-3];
    goto v_32237;
v_32238:
    goto v_32230;
v_32231:
    goto v_32232;
v_32233:
    goto v_32234;
v_32235:
    goto v_32236;
v_32237:
    v_33031 = list4(v_33034, v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    stack[-2] = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32224;
v_32225:
    goto v_32251;
v_32245:
    stack[-1] = elt(env, 8); // times
    goto v_32246;
v_32247:
    stack[0] = stack[-6];
    goto v_32248;
v_32249:
    goto v_32263;
v_32255:
    v_33034 = elt(env, 3); // lie_cc
    goto v_32256;
v_32257:
    v_33033 = elt(env, 4); // lie_p
    goto v_32258;
v_32259:
    v_33032 = elt(env, 5); // lie_q
    goto v_32260;
v_32261:
    v_33031 = stack[-3];
    goto v_32262;
v_32263:
    goto v_32255;
v_32256:
    goto v_32257;
v_32258:
    goto v_32259;
v_32260:
    goto v_32261;
v_32262:
    v_33031 = list4(v_33034, v_33033, v_33032, v_33031);
    env = stack[-10];
    goto v_32250;
v_32251:
    goto v_32245;
v_32246:
    goto v_32247;
v_32248:
    goto v_32249;
v_32250:
    v_33031 = list3(stack[-1], stack[0], v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32226;
v_32227:
    goto v_32223;
v_32224:
    goto v_32225;
v_32226:
    fn = elt(env, 18); // evalneq
    v_33031 = (*qfn2(fn))(fn, stack[-2], v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32221;
    goto v_32273;
v_32269:
    stack[0] = elt(env, 1); // lie_dim
    goto v_32270;
v_32271:
    v_33031 = (LispObject)32+TAG_FIXNUM; // 2
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32272;
v_32273:
    goto v_32269;
v_32270:
    goto v_32271;
v_32272:
    fn = elt(env, 15); // setk
    v_33031 = (*qfn2(fn))(fn, stack[0], v_33031);
    env = stack[-10];
    v_33031 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-5] = v_33031;
    goto v_32287;
v_32281:
    v_33033 = elt(env, 6); // plus
    goto v_32282;
v_32283:
    v_33032 = stack[-8];
    goto v_32284;
v_32285:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32286;
v_32287:
    goto v_32281;
v_32282:
    goto v_32283;
v_32284:
    goto v_32285;
v_32286:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-4] = v_33031;
    goto v_32299;
v_32293:
    v_33033 = elt(env, 6); // plus
    goto v_32294;
v_32295:
    v_33032 = stack[-8];
    goto v_32296;
v_32297:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32298;
v_32299:
    goto v_32293;
v_32294:
    goto v_32295;
v_32296:
    goto v_32297;
v_32298:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-3] = v_33031;
    goto v_32219;
v_32221:
v_32219:
    v_33031 = stack[-3];
    goto v_32313;
v_32307:
    v_33033 = elt(env, 6); // plus
    goto v_32308;
v_32309:
    v_33032 = v_33031;
    goto v_32310;
v_32311:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32312;
v_32313:
    goto v_32307;
v_32308:
    goto v_32309;
v_32310:
    goto v_32311;
v_32312:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-3] = v_33031;
    goto v_32198;
v_32197:
    v_33031 = stack[-4];
    goto v_32327;
v_32321:
    v_33033 = elt(env, 6); // plus
    goto v_32322;
v_32323:
    v_33032 = v_33031;
    goto v_32324;
v_32325:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32326;
v_32327:
    goto v_32321;
v_32322:
    goto v_32323;
v_32324:
    goto v_32325;
v_32326:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-4] = v_33031;
    goto v_32137;
v_32136:
    v_33031 = stack[-5];
    goto v_32341;
v_32335:
    v_33033 = elt(env, 6); // plus
    goto v_32336;
v_32337:
    v_33032 = v_33031;
    goto v_32338;
v_32339:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32340;
v_32341:
    goto v_32335;
v_32336:
    goto v_32337;
v_32338:
    goto v_32339;
v_32340:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-5] = v_33031;
    goto v_32104;
v_32103:
    goto v_32354;
v_32350:
    v_33031 = elt(env, 1); // lie_dim
    fn = elt(env, 14); // aeval
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32351;
v_32352:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32353;
v_32354:
    goto v_32350;
v_32351:
    goto v_32352;
v_32353:
    fn = elt(env, 19); // evalequal
    v_33031 = (*qfn2(fn))(fn, v_33032, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32348;
    goto v_32363;
v_32359:
    stack[0] = elt(env, 9); // lie_help
    goto v_32360;
v_32361:
    v_33031 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 14); // aeval
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32362;
v_32363:
    goto v_32359;
v_32360:
    goto v_32361;
v_32362:
    fn = elt(env, 15); // setk
    v_33031 = (*qfn2(fn))(fn, stack[0], v_33031);
    env = stack[-10];
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_33031;
v_32370:
    goto v_32384;
v_32378:
    stack[0] = elt(env, 2); // difference
    goto v_32379;
v_32380:
    v_33031 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32381;
v_32382:
    v_33031 = stack[-6];
    goto v_32383;
v_32384:
    goto v_32378;
v_32379:
    goto v_32380;
v_32381:
    goto v_32382;
v_32383:
    v_33031 = list3(stack[0], v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32375;
    goto v_32369;
v_32375:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_33031;
v_32393:
    goto v_32407;
v_32401:
    stack[0] = elt(env, 2); // difference
    goto v_32402;
v_32403:
    v_33031 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32404;
v_32405:
    v_33031 = stack[-5];
    goto v_32406;
v_32407:
    goto v_32401;
v_32402:
    goto v_32403;
v_32404:
    goto v_32405;
v_32406:
    v_33031 = list3(stack[0], v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32398;
    goto v_32392;
v_32398:
    goto v_32422;
v_32418:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_33031;
    v_33031 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_33031;
v_32427:
    goto v_32442;
v_32436:
    stack[0] = elt(env, 2); // difference
    goto v_32437;
v_32438:
    v_33031 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32439;
v_32440:
    v_33031 = stack[-4];
    goto v_32441;
v_32442:
    goto v_32436;
v_32437:
    goto v_32438;
v_32439:
    goto v_32440;
v_32441:
    v_33031 = list3(stack[0], v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32433;
    v_33031 = stack[-3];
    v_33032 = v_33031;
    goto v_32426;
v_32433:
    goto v_32456;
v_32450:
    stack[-2] = elt(env, 6); // plus
    goto v_32451;
v_32452:
    goto v_32466;
v_32460:
    stack[-1] = elt(env, 8); // times
    goto v_32461;
v_32462:
    goto v_32477;
v_32469:
    v_33034 = elt(env, 3); // lie_cc
    goto v_32470;
v_32471:
    v_33033 = elt(env, 4); // lie_p
    goto v_32472;
v_32473:
    v_33032 = elt(env, 5); // lie_q
    goto v_32474;
v_32475:
    v_33031 = stack[-4];
    goto v_32476;
v_32477:
    goto v_32469;
v_32470:
    goto v_32471;
v_32472:
    goto v_32473;
v_32474:
    goto v_32475;
v_32476:
    stack[0] = list4(v_33034, v_33033, v_33032, v_33031);
    env = stack[-10];
    goto v_32463;
v_32464:
    goto v_32491;
v_32483:
    v_33034 = elt(env, 3); // lie_cc
    goto v_32484;
v_32485:
    v_33033 = stack[-4];
    goto v_32486;
v_32487:
    v_33032 = stack[-6];
    goto v_32488;
v_32489:
    v_33031 = stack[-5];
    goto v_32490;
v_32491:
    goto v_32483;
v_32484:
    goto v_32485;
v_32486:
    goto v_32487;
v_32488:
    goto v_32489;
v_32490:
    v_33031 = list4(v_33034, v_33033, v_33032, v_33031);
    env = stack[-10];
    goto v_32465;
v_32466:
    goto v_32460;
v_32461:
    goto v_32462;
v_32463:
    goto v_32464;
v_32465:
    v_33031 = list3(stack[-1], stack[0], v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32453;
v_32454:
    v_33031 = stack[-3];
    goto v_32455;
v_32456:
    goto v_32450;
v_32451:
    goto v_32452;
v_32453:
    goto v_32454;
v_32455:
    v_33031 = list3(stack[-2], v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-3] = v_33031;
    v_33031 = stack[-4];
    goto v_32507;
v_32501:
    v_33033 = elt(env, 6); // plus
    goto v_32502;
v_32503:
    v_33032 = v_33031;
    goto v_32504;
v_32505:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32506;
v_32507:
    goto v_32501;
v_32502:
    goto v_32503;
v_32504:
    goto v_32505;
v_32506:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-4] = v_33031;
    goto v_32427;
v_32426:
    goto v_32419;
v_32420:
    v_33031 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32421;
v_32422:
    goto v_32418;
v_32419:
    goto v_32420;
v_32421:
    fn = elt(env, 18); // evalneq
    v_33031 = (*qfn2(fn))(fn, v_33032, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32416;
    goto v_32517;
v_32513:
    stack[0] = elt(env, 9); // lie_help
    goto v_32514;
v_32515:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32516;
v_32517:
    goto v_32513;
v_32514:
    goto v_32515;
v_32516:
    fn = elt(env, 15); // setk
    v_33031 = (*qfn2(fn))(fn, stack[0], v_33031);
    env = stack[-10];
    goto v_32526;
v_32522:
    stack[0] = elt(env, 10); // lie_s
    goto v_32523;
v_32524:
    v_33031 = stack[-6];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32525;
v_32526:
    goto v_32522;
v_32523:
    goto v_32524;
v_32525:
    fn = elt(env, 15); // setk
    v_33031 = (*qfn2(fn))(fn, stack[0], v_33031);
    env = stack[-10];
    v_33031 = stack[-5];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-9] = v_33031;
    goto v_32540;
v_32534:
    v_33033 = elt(env, 6); // plus
    goto v_32535;
v_32536:
    v_33032 = stack[-8];
    goto v_32537;
v_32538:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32539;
v_32540:
    goto v_32534;
v_32535:
    goto v_32536;
v_32537:
    goto v_32538;
v_32539:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-5] = v_33031;
    stack[-6] = v_33031;
    goto v_32414;
v_32416:
v_32414:
    v_33031 = stack[-5];
    goto v_32554;
v_32548:
    v_33033 = elt(env, 6); // plus
    goto v_32549;
v_32550:
    v_33032 = v_33031;
    goto v_32551;
v_32552:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32553;
v_32554:
    goto v_32548;
v_32549:
    goto v_32550;
v_32551:
    goto v_32552;
v_32553:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-5] = v_33031;
    goto v_32393;
v_32392:
    v_33031 = stack[-6];
    goto v_32568;
v_32562:
    v_33033 = elt(env, 6); // plus
    goto v_32563;
v_32564:
    v_33032 = v_33031;
    goto v_32565;
v_32566:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32567;
v_32568:
    goto v_32562;
v_32563:
    goto v_32564;
v_32565:
    goto v_32566;
v_32567:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-6] = v_33031;
    goto v_32370;
v_32369:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_33031;
v_32575:
    goto v_32589;
v_32583:
    stack[0] = elt(env, 2); // difference
    goto v_32584;
v_32585:
    v_33031 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32586;
v_32587:
    v_33031 = stack[-1];
    goto v_32588;
v_32589:
    goto v_32583;
v_32584:
    goto v_32585;
v_32586:
    goto v_32587;
v_32588:
    v_33031 = list3(stack[0], v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32580;
    goto v_32574;
v_32580:
    goto v_32600;
v_32596:
    goto v_32608;
v_32602:
    v_33033 = elt(env, 11); // lientrans
    goto v_32603;
v_32604:
    v_33032 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32605;
v_32606:
    v_33031 = stack[-1];
    goto v_32607;
v_32608:
    goto v_32602;
v_32603:
    goto v_32604;
v_32605:
    goto v_32606;
v_32607:
    stack[0] = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    goto v_32597;
v_32598:
    goto v_32622;
v_32614:
    v_33034 = elt(env, 3); // lie_cc
    goto v_32615;
v_32616:
    v_33033 = elt(env, 4); // lie_p
    goto v_32617;
v_32618:
    v_33032 = elt(env, 5); // lie_q
    goto v_32619;
v_32620:
    v_33031 = stack[-1];
    goto v_32621;
v_32622:
    goto v_32614;
v_32615:
    goto v_32616;
v_32617:
    goto v_32618;
v_32619:
    goto v_32620;
v_32621:
    v_33031 = list4(v_33034, v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32599;
v_32600:
    goto v_32596;
v_32597:
    goto v_32598;
v_32599:
    fn = elt(env, 15); // setk
    v_33031 = (*qfn2(fn))(fn, stack[0], v_33031);
    env = stack[-10];
    v_33031 = stack[-1];
    goto v_32637;
v_32631:
    v_33033 = elt(env, 6); // plus
    goto v_32632;
v_32633:
    v_33032 = v_33031;
    goto v_32634;
v_32635:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32636;
v_32637:
    goto v_32631;
v_32632:
    goto v_32633;
v_32634:
    goto v_32635;
v_32636:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-1] = v_33031;
    goto v_32575;
v_32574:
    goto v_32650;
v_32646:
    v_33031 = elt(env, 9); // lie_help
    fn = elt(env, 14); // aeval
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32647;
v_32648:
    v_33031 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32649;
v_32650:
    goto v_32646;
v_32647:
    goto v_32648;
v_32649:
    fn = elt(env, 19); // evalequal
    v_33031 = (*qfn2(fn))(fn, v_33032, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32644;
    goto v_32659;
v_32655:
    goto v_32667;
v_32661:
    v_33033 = elt(env, 11); // lientrans
    goto v_32662;
v_32663:
    v_33032 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_32664;
v_32665:
    v_33031 = elt(env, 4); // lie_p
    goto v_32666;
v_32667:
    goto v_32661;
v_32662:
    goto v_32663;
v_32664:
    goto v_32665;
v_32666:
    stack[-1] = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    goto v_32656;
v_32657:
    goto v_32676;
v_32672:
    goto v_32684;
v_32678:
    v_33033 = elt(env, 11); // lientrans
    goto v_32679;
v_32680:
    v_33032 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_32681;
v_32682:
    v_33031 = elt(env, 5); // lie_q
    goto v_32683;
v_32684:
    goto v_32678;
v_32679:
    goto v_32680;
v_32681:
    goto v_32682;
v_32683:
    stack[0] = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    goto v_32673;
v_32674:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 14); // aeval
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32675;
v_32676:
    goto v_32672;
v_32673:
    goto v_32674;
v_32675:
    fn = elt(env, 15); // setk
    v_33031 = (*qfn2(fn))(fn, stack[0], v_33031);
    env = stack[-10];
    goto v_32658;
v_32659:
    goto v_32655;
v_32656:
    goto v_32657;
v_32658:
    fn = elt(env, 15); // setk
    v_33031 = (*qfn2(fn))(fn, stack[-1], v_33031);
    env = stack[-10];
    goto v_32695;
v_32691:
    stack[0] = elt(env, 12); // lie_kk!*
    goto v_32692;
v_32693:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 14); // aeval
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32694;
v_32695:
    goto v_32691;
v_32692:
    goto v_32693;
v_32694:
    fn = elt(env, 15); // setk
    v_33031 = (*qfn2(fn))(fn, stack[0], v_33031);
    env = stack[-10];
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_33031;
v_32702:
    goto v_32716;
v_32710:
    stack[0] = elt(env, 2); // difference
    goto v_32711;
v_32712:
    v_33031 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32713;
v_32714:
    v_33031 = stack[-1];
    goto v_32715;
v_32716:
    goto v_32710;
v_32711:
    goto v_32712;
v_32713:
    goto v_32714;
v_32715:
    v_33031 = list3(stack[0], v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32707;
    goto v_32701;
v_32707:
    goto v_32732;
v_32728:
    goto v_32743;
v_32735:
    v_33034 = elt(env, 3); // lie_cc
    goto v_32736;
v_32737:
    v_33033 = elt(env, 4); // lie_p
    goto v_32738;
v_32739:
    v_33032 = elt(env, 5); // lie_q
    goto v_32740;
v_32741:
    v_33031 = stack[-1];
    goto v_32742;
v_32743:
    goto v_32735;
v_32736:
    goto v_32737;
v_32738:
    goto v_32739;
v_32740:
    goto v_32741;
v_32742:
    v_33031 = list4(v_33034, v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32729;
v_32730:
    v_33031 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32731;
v_32732:
    goto v_32728;
v_32729:
    goto v_32730;
v_32731:
    fn = elt(env, 18); // evalneq
    v_33031 = (*qfn2(fn))(fn, v_33032, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32725;
    goto v_32756;
v_32752:
    stack[0] = stack[-1];
    goto v_32753;
v_32754:
    v_33031 = elt(env, 4); // lie_p
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32755;
v_32756:
    goto v_32752;
v_32753:
    goto v_32754;
v_32755:
    fn = elt(env, 18); // evalneq
    v_33031 = (*qfn2(fn))(fn, stack[0], v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32725;
    goto v_32766;
v_32762:
    stack[0] = stack[-1];
    goto v_32763;
v_32764:
    v_33031 = elt(env, 5); // lie_q
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32765;
v_32766:
    goto v_32762;
v_32763:
    goto v_32764;
v_32765:
    fn = elt(env, 18); // evalneq
    v_33031 = (*qfn2(fn))(fn, stack[0], v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32725;
    goto v_32775;
v_32771:
    stack[0] = elt(env, 13); // lie_tt
    goto v_32772;
v_32773:
    v_33031 = stack[-1];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32774;
v_32775:
    goto v_32771;
v_32772:
    goto v_32773;
v_32774:
    fn = elt(env, 15); // setk
    v_33031 = (*qfn2(fn))(fn, stack[0], v_33031);
    env = stack[-10];
    goto v_32787;
v_32781:
    v_33033 = elt(env, 6); // plus
    goto v_32782;
v_32783:
    v_33032 = stack[-8];
    goto v_32784;
v_32785:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32786;
v_32787:
    goto v_32781;
v_32782:
    goto v_32783;
v_32784:
    goto v_32785;
v_32786:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-1] = v_33031;
    goto v_32723;
v_32725:
v_32723:
    v_33031 = stack[-1];
    goto v_32801;
v_32795:
    v_33033 = elt(env, 6); // plus
    goto v_32796;
v_32797:
    v_33032 = v_33031;
    goto v_32798;
v_32799:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32800;
v_32801:
    goto v_32795;
v_32796:
    goto v_32797;
v_32798:
    goto v_32799;
v_32800:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-1] = v_33031;
    goto v_32702;
v_32701:
    goto v_32642;
v_32644:
    goto v_32812;
v_32808:
    goto v_32820;
v_32814:
    v_33033 = elt(env, 11); // lientrans
    goto v_32815;
v_32816:
    v_33032 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_32817;
v_32818:
    v_33031 = elt(env, 10); // lie_s
    goto v_32819;
v_32820:
    goto v_32814;
v_32815:
    goto v_32816;
v_32817:
    goto v_32818;
v_32819:
    stack[-7] = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    goto v_32809;
v_32810:
    goto v_32832;
v_32826:
    stack[-6] = elt(env, 7); // quotient
    goto v_32827;
v_32828:
    goto v_32843;
v_32835:
    v_33034 = elt(env, 3); // lie_cc
    goto v_32836;
v_32837:
    v_33033 = elt(env, 4); // lie_p
    goto v_32838;
v_32839:
    v_33032 = elt(env, 5); // lie_q
    goto v_32840;
v_32841:
    v_33031 = stack[-9];
    goto v_32842;
v_32843:
    goto v_32835;
v_32836:
    goto v_32837;
v_32838:
    goto v_32839;
v_32840:
    goto v_32841;
v_32842:
    stack[-5] = list4(v_33034, v_33033, v_33032, v_33031);
    env = stack[-10];
    goto v_32829;
v_32830:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_33031;
    v_33031 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_33031;
v_32852:
    goto v_32867;
v_32861:
    stack[0] = elt(env, 2); // difference
    goto v_32862;
v_32863:
    v_33031 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32864;
v_32865:
    v_33031 = stack[-4];
    goto v_32866;
v_32867:
    goto v_32861;
v_32862:
    goto v_32863;
v_32864:
    goto v_32865;
v_32866:
    v_33031 = list3(stack[0], v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32858;
    v_33031 = stack[-3];
    goto v_32851;
v_32858:
    goto v_32881;
v_32875:
    stack[-2] = elt(env, 6); // plus
    goto v_32876;
v_32877:
    goto v_32891;
v_32885:
    stack[-1] = elt(env, 8); // times
    goto v_32886;
v_32887:
    goto v_32902;
v_32894:
    v_33034 = elt(env, 3); // lie_cc
    goto v_32895;
v_32896:
    v_33033 = elt(env, 4); // lie_p
    goto v_32897;
v_32898:
    v_33032 = elt(env, 5); // lie_q
    goto v_32899;
v_32900:
    v_33031 = stack[-4];
    goto v_32901;
v_32902:
    goto v_32894;
v_32895:
    goto v_32896;
v_32897:
    goto v_32898;
v_32899:
    goto v_32900;
v_32901:
    stack[0] = list4(v_33034, v_33033, v_33032, v_33031);
    env = stack[-10];
    goto v_32888;
v_32889:
    goto v_32916;
v_32908:
    v_33034 = elt(env, 3); // lie_cc
    goto v_32909;
v_32910:
    v_33033 = stack[-4];
    goto v_32911;
v_32912:
    v_33032 = elt(env, 10); // lie_s
    goto v_32913;
v_32914:
    v_33031 = stack[-9];
    goto v_32915;
v_32916:
    goto v_32908;
v_32909:
    goto v_32910;
v_32911:
    goto v_32912;
v_32913:
    goto v_32914;
v_32915:
    v_33031 = list4(v_33034, v_33033, v_33032, v_33031);
    env = stack[-10];
    goto v_32890;
v_32891:
    goto v_32885;
v_32886:
    goto v_32887;
v_32888:
    goto v_32889;
v_32890:
    v_33031 = list3(stack[-1], stack[0], v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32878;
v_32879:
    v_33031 = stack[-3];
    goto v_32880;
v_32881:
    goto v_32875;
v_32876:
    goto v_32877;
v_32878:
    goto v_32879;
v_32880:
    v_33031 = list3(stack[-2], v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-3] = v_33031;
    v_33031 = stack[-4];
    goto v_32932;
v_32926:
    v_33033 = elt(env, 6); // plus
    goto v_32927;
v_32928:
    v_33032 = v_33031;
    goto v_32929;
v_32930:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_32931;
v_32932:
    goto v_32926;
v_32927:
    goto v_32928;
v_32929:
    goto v_32930;
v_32931:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-4] = v_33031;
    goto v_32852;
v_32851:
    goto v_32831;
v_32832:
    goto v_32826;
v_32827:
    goto v_32828;
v_32829:
    goto v_32830;
v_32831:
    v_33031 = list3(stack[-6], stack[-5], v_33031);
    env = stack[-10];
    fn = elt(env, 14); // aeval
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32811;
v_32812:
    goto v_32808;
v_32809:
    goto v_32810;
v_32811:
    fn = elt(env, 15); // setk
    v_33031 = (*qfn2(fn))(fn, stack[-7], v_33031);
    env = stack[-10];
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_33031;
v_32939:
    goto v_32953;
v_32947:
    stack[0] = elt(env, 2); // difference
    goto v_32948;
v_32949:
    v_33031 = stack[-8];
    fn = elt(env, 16); // aeval!*
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32950;
v_32951:
    v_33031 = stack[-1];
    goto v_32952;
v_32953:
    goto v_32947;
v_32948:
    goto v_32949;
v_32950:
    goto v_32951;
v_32952:
    v_33031 = list3(stack[0], v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 17); // aminusp!:
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32944;
    goto v_32938;
v_32944:
    goto v_32969;
v_32965:
    goto v_32980;
v_32972:
    v_33034 = elt(env, 3); // lie_cc
    goto v_32973;
v_32974:
    v_33033 = elt(env, 4); // lie_p
    goto v_32975;
v_32976:
    v_33032 = elt(env, 5); // lie_q
    goto v_32977;
v_32978:
    v_33031 = stack[-1];
    goto v_32979;
v_32980:
    goto v_32972;
v_32973:
    goto v_32974;
v_32975:
    goto v_32976;
v_32977:
    goto v_32978;
v_32979:
    v_33031 = list4(v_33034, v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33032 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32966;
v_32967:
    v_33031 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_32968;
v_32969:
    goto v_32965;
v_32966:
    goto v_32967;
v_32968:
    fn = elt(env, 18); // evalneq
    v_33031 = (*qfn2(fn))(fn, v_33032, v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32962;
    goto v_32992;
v_32988:
    stack[0] = stack[-1];
    goto v_32989;
v_32990:
    v_33031 = elt(env, 10); // lie_s
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_32991;
v_32992:
    goto v_32988;
v_32989:
    goto v_32990;
v_32991:
    fn = elt(env, 18); // evalneq
    v_33031 = (*qfn2(fn))(fn, stack[0], v_33031);
    env = stack[-10];
    if (v_33031 == nil) goto v_32962;
    goto v_33001;
v_32997:
    stack[0] = elt(env, 13); // lie_tt
    goto v_32998;
v_32999:
    v_33031 = stack[-1];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    goto v_33000;
v_33001:
    goto v_32997;
v_32998:
    goto v_32999;
v_33000:
    fn = elt(env, 15); // setk
    v_33031 = (*qfn2(fn))(fn, stack[0], v_33031);
    env = stack[-10];
    goto v_33013;
v_33007:
    v_33033 = elt(env, 6); // plus
    goto v_33008;
v_33009:
    v_33032 = stack[-8];
    goto v_33010;
v_33011:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33012;
v_33013:
    goto v_33007;
v_33008:
    goto v_33009;
v_33010:
    goto v_33011;
v_33012:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-1] = v_33031;
    goto v_32960;
v_32962:
v_32960:
    v_33031 = stack[-1];
    goto v_33027;
v_33021:
    v_33033 = elt(env, 6); // plus
    goto v_33022;
v_33023:
    v_33032 = v_33031;
    goto v_33024;
v_33025:
    v_33031 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33026;
v_33027:
    goto v_33021;
v_33022:
    goto v_33023;
v_33024:
    goto v_33025;
v_33026:
    v_33031 = list3(v_33033, v_33032, v_33031);
    env = stack[-10];
    fn = elt(env, 16); // aeval!*
    v_33031 = (*qfn1(fn))(fn, v_33031);
    env = stack[-10];
    stack[-1] = v_33031;
    goto v_32939;
v_32938:
    goto v_32642;
v_32642:
    goto v_32346;
v_32348:
v_32346:
    goto v_32089;
v_32091:
v_32089:
    v_33031 = nil;
    return onevalue(v_33031);
}



// Code for dpmat_gbtag

static LispObject CC_dpmat_gbtag(LispObject env,
                         LispObject v_31882)
{
    env = qenv(env);
    LispObject v_31892, v_31893;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31892 = v_31882;
// end of prologue
    goto v_31889;
v_31885:
    v_31893 = v_31892;
    goto v_31886;
v_31887:
    v_31892 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_31888;
v_31889:
    goto v_31885;
v_31886:
    goto v_31887;
v_31888:
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(fn, v_31893, v_31892);
    }
}



// Code for st_extract_symcells1

static LispObject CC_st_extract_symcells1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_32051, v_32052, v_32053;
    LispObject fn;
    LispObject v_31884, v_31883, v_31882;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "st_extract_symcells1");
    va_start(aa, nargs);
    v_31882 = va_arg(aa, LispObject);
    v_31883 = va_arg(aa, LispObject);
    v_31884 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_31884,v_31883,v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_31882,v_31883,v_31884);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_31884;
    stack[-5] = v_31883;
    stack[0] = v_31882;
// end of prologue
    v_32051 = stack[0];
    v_32051 = qcdr(v_32051);
    v_32051 = qcar(v_32051);
    fn = elt(env, 2); // listp
    v_32051 = (*qfn1(fn))(fn, v_32051);
    env = stack[-7];
    if (v_32051 == nil) goto v_31892;
    else goto v_31893;
v_31892:
    goto v_31905;
v_31899:
    stack[-1] = stack[-4];
    goto v_31900;
v_31901:
    goto v_31912;
v_31908:
    v_32052 = stack[0];
    goto v_31909;
v_31910:
    v_32051 = stack[-5];
    goto v_31911;
v_31912:
    goto v_31908;
v_31909:
    goto v_31910;
v_31911:
    stack[0] = cons(v_32052, v_32051);
    env = stack[-7];
    goto v_31902;
v_31903:
    v_32051 = stack[-4];
    v_32051 = add1(v_32051);
    goto v_31904;
v_31905:
    goto v_31899;
v_31900:
    goto v_31901;
v_31902:
    goto v_31903;
v_31904:
    {
        LispObject v_32061 = stack[-1];
        LispObject v_32062 = stack[0];
        return list3(v_32061, v_32062, v_32051);
    }
v_31893:
    goto v_31924;
v_31920:
    v_32051 = stack[0];
    stack[-6] = qcar(v_32051);
    goto v_31921;
v_31922:
    v_32051 = stack[0];
    v_32051 = qcdr(v_32051);
    stack[-3] = v_32051;
    v_32051 = stack[-3];
    if (v_32051 == nil) goto v_31937;
    else goto v_31938;
v_31937:
    v_32051 = nil;
    goto v_31931;
v_31938:
    v_32051 = stack[-3];
    v_32051 = qcar(v_32051);
    goto v_31952;
v_31946:
    v_32053 = v_32051;
    goto v_31947;
v_31948:
    v_32052 = stack[-5];
    goto v_31949;
v_31950:
    v_32051 = stack[-4];
    goto v_31951;
v_31952:
    goto v_31946;
v_31947:
    goto v_31948;
v_31949:
    goto v_31950;
v_31951:
    v_32051 = CC_st_extract_symcells1(elt(env, 0), 3, v_32053, v_32052, v_32051);
    env = stack[-7];
    v_32052 = v_32051;
    v_32052 = qcdr(v_32052);
    v_32052 = qcar(v_32052);
    stack[-5] = v_32052;
    v_32052 = v_32051;
    v_32052 = qcdr(v_32052);
    v_32052 = qcdr(v_32052);
    v_32052 = qcar(v_32052);
    stack[-4] = v_32052;
    v_32052 = v_32051;
    v_32052 = qcar(v_32052);
    if (is_number(v_32052)) goto v_31965;
    else goto v_31966;
v_31965:
    goto v_31974;
v_31970:
    v_32052 = elt(env, 1); // !*
    goto v_31971;
v_31972:
    v_32051 = qcar(v_32051);
    goto v_31973;
v_31974:
    goto v_31970;
v_31971:
    goto v_31972;
v_31973:
    v_32051 = list2(v_32052, v_32051);
    env = stack[-7];
    goto v_31964;
v_31966:
    v_32051 = qcar(v_32051);
    goto v_31964;
    v_32051 = nil;
v_31964:
    v_32051 = ncons(v_32051);
    env = stack[-7];
    stack[-1] = v_32051;
    stack[-2] = v_32051;
v_31932:
    v_32051 = stack[-3];
    v_32051 = qcdr(v_32051);
    stack[-3] = v_32051;
    v_32051 = stack[-3];
    if (v_32051 == nil) goto v_31986;
    else goto v_31987;
v_31986:
    v_32051 = stack[-2];
    goto v_31931;
v_31987:
    goto v_31995;
v_31991:
    stack[0] = stack[-1];
    goto v_31992;
v_31993:
    v_32051 = stack[-3];
    v_32051 = qcar(v_32051);
    goto v_32008;
v_32002:
    v_32053 = v_32051;
    goto v_32003;
v_32004:
    v_32052 = stack[-5];
    goto v_32005;
v_32006:
    v_32051 = stack[-4];
    goto v_32007;
v_32008:
    goto v_32002;
v_32003:
    goto v_32004;
v_32005:
    goto v_32006;
v_32007:
    v_32051 = CC_st_extract_symcells1(elt(env, 0), 3, v_32053, v_32052, v_32051);
    env = stack[-7];
    v_32052 = v_32051;
    v_32052 = qcdr(v_32052);
    v_32052 = qcar(v_32052);
    stack[-5] = v_32052;
    v_32052 = v_32051;
    v_32052 = qcdr(v_32052);
    v_32052 = qcdr(v_32052);
    v_32052 = qcar(v_32052);
    stack[-4] = v_32052;
    v_32052 = v_32051;
    v_32052 = qcar(v_32052);
    if (is_number(v_32052)) goto v_32021;
    else goto v_32022;
v_32021:
    goto v_32030;
v_32026:
    v_32052 = elt(env, 1); // !*
    goto v_32027;
v_32028:
    v_32051 = qcar(v_32051);
    goto v_32029;
v_32030:
    goto v_32026;
v_32027:
    goto v_32028;
v_32029:
    v_32051 = list2(v_32052, v_32051);
    env = stack[-7];
    goto v_32020;
v_32022:
    v_32051 = qcar(v_32051);
    goto v_32020;
    v_32051 = nil;
v_32020:
    v_32051 = ncons(v_32051);
    env = stack[-7];
    goto v_31994;
v_31995:
    goto v_31991;
v_31992:
    goto v_31993;
v_31994:
    v_32051 = Lrplacd(nil, stack[0], v_32051);
    env = stack[-7];
    v_32051 = stack[-1];
    v_32051 = qcdr(v_32051);
    stack[-1] = v_32051;
    goto v_31932;
v_31931:
    goto v_31923;
v_31924:
    goto v_31920;
v_31921:
    goto v_31922;
v_31923:
    v_32051 = cons(stack[-6], v_32051);
    goto v_32047;
v_32041:
    v_32053 = v_32051;
    goto v_32042;
v_32043:
    v_32052 = stack[-5];
    goto v_32044;
v_32045:
    v_32051 = stack[-4];
    goto v_32046;
v_32047:
    goto v_32041;
v_32042:
    goto v_32043;
v_32044:
    goto v_32045;
v_32046:
    return list3(v_32053, v_32052, v_32051);
    v_32051 = nil;
    return onevalue(v_32051);
}



// Code for sfto_deggcd1

static LispObject CC_sfto_deggcd1(LispObject env,
                         LispObject v_31882, LispObject v_31883)
{
    env = qenv(env);
    LispObject v_31974, v_31975, v_31976;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31883,v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31882,v_31883);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_31883;
    stack[-2] = v_31882;
// end of prologue
    v_31974 = (LispObject)0+TAG_FIXNUM; // 0
    v_31976 = v_31974;
    v_31974 = lisp_true;
    stack[-3] = v_31974;
v_31893:
    v_31974 = stack[-3];
    if (v_31974 == nil) goto v_31896;
    goto v_31905;
v_31901:
    v_31975 = v_31976;
    goto v_31902;
v_31903:
    v_31974 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31904;
v_31905:
    goto v_31901;
v_31902:
    goto v_31903;
v_31904:
    if (v_31975 == v_31974) goto v_31896;
    goto v_31897;
v_31896:
    goto v_31892;
v_31897:
    v_31974 = stack[-2];
    if (!consp(v_31974)) goto v_31915;
    else goto v_31916;
v_31915:
    v_31974 = lisp_true;
    goto v_31914;
v_31916:
    v_31974 = stack[-2];
    v_31974 = qcar(v_31974);
    v_31974 = (consp(v_31974) ? nil : lisp_true);
    goto v_31914;
    v_31974 = nil;
v_31914:
    if (v_31974 == nil) goto v_31912;
    v_31974 = nil;
    stack[-3] = v_31974;
    goto v_31910;
v_31912:
    goto v_31935;
v_31931:
    v_31974 = stack[-2];
    v_31974 = qcar(v_31974);
    v_31974 = qcar(v_31974);
    v_31975 = qcar(v_31974);
    goto v_31932;
v_31933:
    v_31974 = stack[-1];
    goto v_31934;
v_31935:
    goto v_31931;
v_31932:
    goto v_31933;
v_31934:
    if (v_31975 == v_31974) goto v_31929;
    else goto v_31930;
v_31929:
    goto v_31946;
v_31942:
    v_31975 = v_31976;
    goto v_31943;
v_31944:
    v_31974 = stack[-2];
    v_31974 = qcar(v_31974);
    v_31974 = qcar(v_31974);
    v_31974 = qcdr(v_31974);
    goto v_31945;
v_31946:
    goto v_31942;
v_31943:
    goto v_31944;
v_31945:
    v_31974 = Lgcd(nil, v_31975, v_31974);
    env = stack[-4];
    v_31976 = v_31974;
    goto v_31928;
v_31930:
    goto v_31959;
v_31955:
    stack[0] = v_31976;
    goto v_31956;
v_31957:
    goto v_31966;
v_31962:
    v_31974 = stack[-2];
    v_31974 = qcar(v_31974);
    v_31975 = qcdr(v_31974);
    goto v_31963;
v_31964:
    v_31974 = stack[-1];
    goto v_31965;
v_31966:
    goto v_31962;
v_31963:
    goto v_31964;
v_31965:
    v_31974 = CC_sfto_deggcd1(elt(env, 0), v_31975, v_31974);
    env = stack[-4];
    goto v_31958;
v_31959:
    goto v_31955;
v_31956:
    goto v_31957;
v_31958:
    v_31974 = Lgcd(nil, stack[0], v_31974);
    env = stack[-4];
    v_31976 = v_31974;
    goto v_31928;
v_31928:
    v_31974 = stack[-2];
    v_31974 = qcdr(v_31974);
    stack[-2] = v_31974;
    goto v_31910;
v_31910:
    goto v_31893;
v_31892:
    v_31974 = v_31976;
    return onevalue(v_31974);
}



// Code for addinds

static LispObject CC_addinds(LispObject env,
                         LispObject v_31882, LispObject v_31883)
{
    env = qenv(env);
    LispObject v_31948, v_31949;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31883,v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31882,v_31883);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31883;
    stack[-1] = v_31882;
// end of prologue
    stack[-2] = nil;
v_31888:
    v_31948 = stack[-1];
    if (v_31948 == nil) goto v_31891;
    else goto v_31892;
v_31891:
    v_31948 = stack[0];
    if (v_31948 == nil) goto v_31896;
    else goto v_31897;
v_31896:
    v_31948 = stack[-2];
    {
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(fn, v_31948);
    }
v_31897:
    goto v_31908;
v_31904:
    stack[0] = stack[-2];
    goto v_31905;
v_31906:
    v_31948 = elt(env, 1); // "Powrhs too long"
    fn = elt(env, 4); // interr
    v_31948 = (*qfn1(fn))(fn, v_31948);
    env = stack[-3];
    goto v_31907;
v_31908:
    goto v_31904;
v_31905:
    goto v_31906;
v_31907:
    {
        LispObject v_31953 = stack[0];
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(fn, v_31953, v_31948);
    }
    goto v_31890;
v_31892:
    v_31948 = stack[0];
    if (v_31948 == nil) goto v_31912;
    else goto v_31913;
v_31912:
    goto v_31920;
v_31916:
    stack[0] = stack[-2];
    goto v_31917;
v_31918:
    v_31948 = elt(env, 2); // "Powu too long"
    fn = elt(env, 4); // interr
    v_31948 = (*qfn1(fn))(fn, v_31948);
    env = stack[-3];
    goto v_31919;
v_31920:
    goto v_31916;
v_31917:
    goto v_31918;
v_31919:
    {
        LispObject v_31954 = stack[0];
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(fn, v_31954, v_31948);
    }
v_31913:
    goto v_31931;
v_31927:
    goto v_31937;
v_31933:
    v_31948 = stack[-1];
    v_31949 = qcar(v_31948);
    goto v_31934;
v_31935:
    v_31948 = stack[0];
    v_31948 = qcar(v_31948);
    v_31948 = qcar(v_31948);
    goto v_31936;
v_31937:
    goto v_31933;
v_31934:
    goto v_31935;
v_31936:
    v_31949 = plus2(v_31949, v_31948);
    env = stack[-3];
    goto v_31928;
v_31929:
    v_31948 = stack[-2];
    goto v_31930;
v_31931:
    goto v_31927;
v_31928:
    goto v_31929;
v_31930:
    v_31948 = cons(v_31949, v_31948);
    env = stack[-3];
    stack[-2] = v_31948;
    v_31948 = stack[-1];
    v_31948 = qcdr(v_31948);
    stack[-1] = v_31948;
    v_31948 = stack[0];
    v_31948 = qcdr(v_31948);
    stack[0] = v_31948;
    goto v_31888;
v_31890:
    v_31948 = nil;
    return onevalue(v_31948);
}



// Code for qqe_length!-graph!-bterm

static LispObject CC_qqe_lengthKgraphKbterm(LispObject env,
                         LispObject v_31882, LispObject v_31883)
{
    env = qenv(env);
    LispObject v_31951, v_31952;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31883,v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31882,v_31883);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31883;
    stack[-1] = v_31882;
// end of prologue
    v_31951 = stack[-1];
    if (v_31951 == nil) goto v_31893;
    else goto v_31894;
v_31893:
    v_31951 = lisp_true;
    goto v_31892;
v_31894:
    v_31951 = stack[-1];
    v_31951 = (consp(v_31951) ? nil : lisp_true);
    goto v_31892;
    v_31951 = nil;
v_31892:
    if (v_31951 == nil) goto v_31890;
    v_31951 = stack[0];
    goto v_31886;
v_31890:
    goto v_31910;
v_31906:
    v_31951 = stack[-1];
    fn = elt(env, 2); // qqe_op
    v_31952 = (*qfn1(fn))(fn, v_31951);
    env = stack[-2];
    goto v_31907;
v_31908:
    v_31951 = elt(env, 1); // (lhead rhead)
    goto v_31909;
v_31910:
    goto v_31906;
v_31907:
    goto v_31908;
v_31909:
    v_31951 = Lmemq(nil, v_31952, v_31951);
    if (v_31951 == nil) goto v_31905;
    goto v_31920;
v_31916:
    v_31952 = stack[-1];
    goto v_31917;
v_31918:
    v_31951 = stack[0];
    goto v_31919;
v_31920:
    goto v_31916;
v_31917:
    goto v_31918;
v_31919:
    fn = elt(env, 3); // qqe_length!-graph!-bterm!-update!-headmin
    v_31951 = (*qfn2(fn))(fn, v_31952, v_31951);
    stack[0] = v_31951;
    goto v_31903;
v_31905:
    v_31951 = stack[-1];
    v_31951 = qcdr(v_31951);
    stack[-1] = v_31951;
v_31928:
    v_31951 = stack[-1];
    if (v_31951 == nil) goto v_31933;
    else goto v_31934;
v_31933:
    goto v_31927;
v_31934:
    v_31951 = stack[-1];
    v_31951 = qcar(v_31951);
    goto v_31945;
v_31941:
    v_31952 = v_31951;
    goto v_31942;
v_31943:
    v_31951 = stack[0];
    goto v_31944;
v_31945:
    goto v_31941;
v_31942:
    goto v_31943;
v_31944:
    v_31951 = CC_qqe_lengthKgraphKbterm(elt(env, 0), v_31952, v_31951);
    env = stack[-2];
    stack[0] = v_31951;
    v_31951 = stack[-1];
    v_31951 = qcdr(v_31951);
    stack[-1] = v_31951;
    goto v_31928;
v_31927:
    goto v_31903;
v_31903:
    v_31951 = stack[0];
v_31886:
    return onevalue(v_31951);
}



// Code for crprimp

static LispObject CC_crprimp(LispObject env,
                         LispObject v_31882)
{
    env = qenv(env);
    LispObject v_31926, v_31927, v_31928;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31928 = v_31882;
// end of prologue
    goto v_31892;
v_31888:
    v_31927 = v_31928;
    goto v_31889;
v_31890:
    v_31926 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31891;
v_31892:
    goto v_31888;
v_31889:
    goto v_31890;
v_31891:
    if (v_31927 == v_31926) goto v_31886;
    else goto v_31887;
v_31886:
    v_31926 = elt(env, 1); // i
    goto v_31885;
v_31887:
    goto v_31902;
v_31898:
    v_31927 = v_31928;
    goto v_31899;
v_31900:
    v_31926 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_31901;
v_31902:
    goto v_31898;
v_31899:
    goto v_31900;
v_31901:
    if (v_31927 == v_31926) goto v_31896;
    else goto v_31897;
v_31896:
    goto v_31910;
v_31906:
    v_31926 = elt(env, 2); // minus
    goto v_31907;
v_31908:
    v_31927 = elt(env, 1); // i
    goto v_31909;
v_31910:
    goto v_31906;
v_31907:
    goto v_31908;
v_31909:
    return list2(v_31926, v_31927);
v_31897:
    goto v_31922;
v_31916:
    v_31926 = elt(env, 3); // times
    goto v_31917;
v_31918:
    v_31927 = v_31928;
    goto v_31919;
v_31920:
    v_31928 = elt(env, 1); // i
    goto v_31921;
v_31922:
    goto v_31916;
v_31917:
    goto v_31918;
v_31919:
    goto v_31920;
v_31921:
    return list3(v_31926, v_31927, v_31928);
    v_31926 = nil;
v_31885:
    return onevalue(v_31926);
}



// Code for remove_critical_pairs

static LispObject CC_remove_critical_pairs(LispObject env,
                         LispObject v_31882, LispObject v_31883)
{
    env = qenv(env);
    LispObject v_31899, v_31900;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31883,v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31882,v_31883);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_31883;
    v_31899 = v_31882;
// end of prologue
    v_31900 = v_31899;
    if (v_31900 == nil) goto v_31888;
    goto v_31895;
v_31891:
    v_31900 = stack[0];
    goto v_31892;
v_31893:
    goto v_31894;
v_31895:
    goto v_31891;
v_31892:
    goto v_31893;
v_31894:
    fn = elt(env, 1); // remove_items
    v_31899 = (*qfn2(fn))(fn, v_31900, v_31899);
    goto v_31886;
v_31888:
v_31886:
    v_31899 = stack[0];
    return onevalue(v_31899);
}



// Code for physopplus

static LispObject CC_physopplus(LispObject env,
                         LispObject v_31882)
{
    env = qenv(env);
    LispObject v_31953, v_31954;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31882);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_31882;
// end of prologue
    v_31953 = stack[0];
    v_31953 = qcar(v_31953);
    fn = elt(env, 2); // physopsim!*
    v_31953 = (*qfn1(fn))(fn, v_31953);
    env = stack[-4];
    stack[-3] = v_31953;
    v_31953 = stack[0];
    v_31953 = qcdr(v_31953);
    stack[0] = v_31953;
v_31896:
    v_31953 = stack[0];
    if (v_31953 == nil) goto v_31901;
    else goto v_31902;
v_31901:
    goto v_31895;
v_31902:
    v_31953 = stack[0];
    v_31953 = qcar(v_31953);
    fn = elt(env, 2); // physopsim!*
    v_31953 = (*qfn1(fn))(fn, v_31953);
    env = stack[-4];
    stack[-2] = v_31953;
    v_31953 = stack[-3];
    fn = elt(env, 3); // getphystype
    v_31953 = (*qfn1(fn))(fn, v_31953);
    env = stack[-4];
    stack[-1] = v_31953;
    v_31953 = stack[-2];
    fn = elt(env, 3); // getphystype
    v_31953 = (*qfn1(fn))(fn, v_31953);
    env = stack[-4];
    v_31954 = v_31953;
    if (v_31954 == nil) goto v_31917;
    v_31954 = stack[-1];
    if (v_31954 == nil) goto v_31917;
    goto v_31928;
v_31924:
    v_31954 = stack[-1];
    goto v_31925;
v_31926:
    goto v_31927;
v_31928:
    goto v_31924;
v_31925:
    goto v_31926;
v_31927:
    if (v_31954 == v_31953) goto v_31917;
    goto v_31936;
v_31932:
    v_31954 = elt(env, 0); // physopplus
    goto v_31933;
v_31934:
    v_31953 = elt(env, 1); // "type mismatch in plus "
    goto v_31935;
v_31936:
    goto v_31932;
v_31933:
    goto v_31934;
v_31935:
    fn = elt(env, 4); // rederr2
    v_31953 = (*qfn2(fn))(fn, v_31954, v_31953);
    env = stack[-4];
    goto v_31915;
v_31917:
v_31915:
    goto v_31945;
v_31941:
    v_31953 = stack[-3];
    fn = elt(env, 5); // physop2sq
    stack[-1] = (*qfn1(fn))(fn, v_31953);
    env = stack[-4];
    goto v_31942;
v_31943:
    v_31953 = stack[-2];
    fn = elt(env, 5); // physop2sq
    v_31953 = (*qfn1(fn))(fn, v_31953);
    env = stack[-4];
    goto v_31944;
v_31945:
    goto v_31941;
v_31942:
    goto v_31943;
v_31944:
    fn = elt(env, 6); // addsq
    v_31953 = (*qfn2(fn))(fn, stack[-1], v_31953);
    env = stack[-4];
    fn = elt(env, 7); // mk!*sq
    v_31953 = (*qfn1(fn))(fn, v_31953);
    env = stack[-4];
    stack[-3] = v_31953;
    v_31953 = stack[0];
    v_31953 = qcdr(v_31953);
    stack[0] = v_31953;
    goto v_31896;
v_31895:
    v_31953 = stack[-3];
    return onevalue(v_31953);
}



// Code for bassoc

static LispObject CC_bassoc(LispObject env,
                         LispObject v_31882, LispObject v_31883)
{
    env = qenv(env);
    LispObject v_31911, v_31912;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_31883,v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_31882,v_31883);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_31883;
    stack[-1] = v_31882;
// end of prologue
v_31887:
    v_31911 = stack[0];
    if (v_31911 == nil) goto v_31890;
    else goto v_31891;
v_31890:
    v_31911 = nil;
    goto v_31886;
v_31891:
    goto v_31901;
v_31897:
    v_31912 = stack[-1];
    goto v_31898;
v_31899:
    v_31911 = stack[0];
    v_31911 = qcar(v_31911);
    v_31911 = qcar(v_31911);
    goto v_31900;
v_31901:
    goto v_31897;
v_31898:
    goto v_31899;
v_31900:
    fn = elt(env, 1); // th_match
    v_31911 = (*qfn2(fn))(fn, v_31912, v_31911);
    env = stack[-2];
    if (v_31911 == nil) goto v_31895;
    v_31911 = stack[0];
    goto v_31886;
v_31895:
    v_31911 = stack[0];
    v_31911 = qcdr(v_31911);
    stack[0] = v_31911;
    goto v_31887;
    v_31911 = nil;
v_31886:
    return onevalue(v_31911);
}



// Code for !*sq2fourier

static LispObject CC_Hsq2fourier(LispObject env,
                         LispObject v_31882)
{
    env = qenv(env);
    LispObject v_31953, v_31954, v_31955;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31882);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_31882;
// end of prologue
    v_31953 = stack[0];
    v_31953 = qcar(v_31953);
    if (v_31953 == nil) goto v_31886;
    else goto v_31887;
v_31886:
    v_31953 = nil;
    goto v_31885;
v_31887:
    v_31953 = (LispObject)48+TAG_FIXNUM; // 3
    v_31953 = Lmkvect(nil, v_31953);
    env = stack[-3];
    stack[-2] = v_31953;
    goto v_31904;
v_31898:
    v_31955 = stack[-2];
    goto v_31899;
v_31900:
    v_31954 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_31901;
v_31902:
    v_31953 = stack[0];
    goto v_31903;
v_31904:
    goto v_31898;
v_31899:
    goto v_31900;
v_31901:
    goto v_31902;
v_31903:
    *(LispObject *)((char *)v_31955 + (CELL-TAG_VECTOR) + (((intptr_t)v_31954-TAG_FIXNUM)/(16/CELL))) = v_31953;
    goto v_31914;
v_31908:
    v_31955 = stack[-2];
    goto v_31909;
v_31910:
    v_31954 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31911;
v_31912:
    v_31953 = elt(env, 1); // cos
    goto v_31913;
v_31914:
    goto v_31908;
v_31909:
    goto v_31910;
v_31911:
    goto v_31912;
v_31913:
    *(LispObject *)((char *)v_31955 + (CELL-TAG_VECTOR) + (((intptr_t)v_31954-TAG_FIXNUM)/(16/CELL))) = v_31953;
    goto v_31924;
v_31918:
    stack[-1] = stack[-2];
    goto v_31919;
v_31920:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_31921;
v_31922:
    fn = elt(env, 4); // fs!:make!-nullangle
    v_31953 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_31923;
v_31924:
    goto v_31918;
v_31919:
    goto v_31920;
v_31921:
    goto v_31922;
v_31923:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_31953;
    goto v_31934;
v_31928:
    v_31955 = stack[-2];
    goto v_31929;
v_31930:
    v_31954 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_31931;
v_31932:
    v_31953 = nil;
    goto v_31933;
v_31934:
    goto v_31928;
v_31929:
    goto v_31930;
v_31931:
    goto v_31932;
v_31933:
    *(LispObject *)((char *)v_31955 + (CELL-TAG_VECTOR) + (((intptr_t)v_31954-TAG_FIXNUM)/(16/CELL))) = v_31953;
    goto v_31943;
v_31939:
    goto v_31949;
v_31945:
    v_31954 = elt(env, 2); // fourier
    goto v_31946;
v_31947:
    v_31953 = elt(env, 3); // tag
    goto v_31948;
v_31949:
    goto v_31945;
v_31946:
    goto v_31947;
v_31948:
    v_31954 = get(v_31954, v_31953);
    goto v_31940;
v_31941:
    v_31953 = stack[-2];
    goto v_31942;
v_31943:
    goto v_31939;
v_31940:
    goto v_31941;
v_31942:
    return cons(v_31954, v_31953);
    goto v_31885;
    v_31953 = nil;
v_31885:
    return onevalue(v_31953);
}



// Code for all_index_lst

static LispObject CC_all_index_lst(LispObject env,
                         LispObject v_31882)
{
    env = qenv(env);
    LispObject v_31950, v_31951;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31882);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_31882;
// end of prologue
    stack[-2] = nil;
v_31888:
    v_31950 = stack[-1];
    if (v_31950 == nil) goto v_31893;
    else goto v_31894;
v_31893:
    goto v_31889;
v_31894:
    goto v_31901;
v_31897:
    v_31950 = stack[-1];
    v_31950 = qcar(v_31950);
    v_31950 = qcdr(v_31950);
    stack[0] = v_31950;
    v_31950 = stack[0];
    v_31950 = qcar(v_31950);
    fn = elt(env, 2); // listp
    v_31950 = (*qfn1(fn))(fn, v_31950);
    env = stack[-3];
    if (v_31950 == nil) goto v_31909;
    goto v_31919;
v_31915:
    v_31950 = stack[0];
    v_31950 = qcar(v_31950);
    v_31951 = qcar(v_31950);
    goto v_31916;
v_31917:
    v_31950 = elt(env, 1); // list
    goto v_31918;
v_31919:
    goto v_31915;
v_31916:
    goto v_31917;
v_31918:
    if (v_31951 == v_31950) goto v_31914;
    else goto v_31909;
v_31914:
    v_31950 = stack[0];
    v_31950 = qcdr(v_31950);
    v_31951 = v_31950;
    goto v_31907;
v_31909:
    v_31950 = stack[0];
    v_31951 = v_31950;
    goto v_31907;
    v_31951 = nil;
v_31907:
    goto v_31898;
v_31899:
    v_31950 = stack[-2];
    goto v_31900;
v_31901:
    goto v_31897;
v_31898:
    goto v_31899;
v_31900:
    v_31950 = cons(v_31951, v_31950);
    env = stack[-3];
    stack[-2] = v_31950;
    v_31950 = stack[-1];
    v_31950 = qcdr(v_31950);
    stack[-1] = v_31950;
    goto v_31888;
v_31889:
    v_31950 = nil;
    v_31951 = v_31950;
v_31890:
    v_31950 = stack[-2];
    if (v_31950 == nil) goto v_31935;
    else goto v_31936;
v_31935:
    v_31950 = v_31951;
    goto v_31887;
v_31936:
    goto v_31944;
v_31940:
    v_31950 = stack[-2];
    v_31950 = qcar(v_31950);
    goto v_31941;
v_31942:
    goto v_31943;
v_31944:
    goto v_31940;
v_31941:
    goto v_31942;
v_31943:
    v_31950 = Lappend(nil, v_31950, v_31951);
    env = stack[-3];
    v_31951 = v_31950;
    v_31950 = stack[-2];
    v_31950 = qcdr(v_31950);
    stack[-2] = v_31950;
    goto v_31890;
v_31887:
    return onevalue(v_31950);
}



// Code for sc_create

static LispObject CC_sc_create(LispObject env,
                         LispObject v_31882)
{
    env = qenv(env);
    LispObject v_31929, v_31930;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_31882);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_31882);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_31882;
// end of prologue
    stack[-2] = nil;
    v_31929 = stack[-1];
    stack[0] = v_31929;
v_31892:
    v_31929 = stack[0];
    v_31929 = sub1(v_31929);
    env = stack[-3];
    v_31929 = Lminusp(nil, v_31929);
    env = stack[-3];
    if (v_31929 == nil) goto v_31897;
    goto v_31891;
v_31897:
    goto v_31907;
v_31903:
    v_31930 = stack[0];
    goto v_31904;
v_31905:
    v_31929 = stack[-2];
    goto v_31906;
v_31907:
    goto v_31903;
v_31904:
    goto v_31905;
v_31906:
    v_31929 = cons(v_31930, v_31929);
    env = stack[-3];
    stack[-2] = v_31929;
    v_31929 = stack[0];
    v_31929 = sub1(v_31929);
    env = stack[-3];
    stack[0] = v_31929;
    goto v_31892;
v_31891:
    goto v_31917;
v_31913:
    goto v_31923;
v_31919:
    v_31930 = stack[-2];
    goto v_31920;
v_31921:
    v_31929 = elt(env, 1); // symbolic
    goto v_31922;
v_31923:
    goto v_31919;
v_31920:
    goto v_31921;
v_31922:
    fn = elt(env, 2); // list2vect!*
    stack[0] = (*qfn2(fn))(fn, v_31930, v_31929);
    env = stack[-3];
    goto v_31914;
v_31915:
    v_31929 = stack[-1];
    v_31929 = sub1(v_31929);
    env = stack[-3];
    v_31929 = Lmkvect(nil, v_31929);
    goto v_31916;
v_31917:
    goto v_31913;
v_31914:
    goto v_31915;
v_31916:
    {
        LispObject v_31934 = stack[0];
        return cons(v_31934, v_31929);
    }
    return onevalue(v_31929);
}



setup_type const u54_setup[] =
{
    {"multtaylorsq",            TOO_FEW_2,      CC_multtaylorsq,WRONG_NO_2},
    {"simpx1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_simpx1},
    {"depend-p",                TOO_FEW_2,      CC_dependKp,   WRONG_NO_2},
    {"pasf_exprng",             CC_pasf_exprng, TOO_MANY_1,    WRONG_NO_1},
    {"varsinsf",                TOO_FEW_2,      CC_varsinsf,   WRONG_NO_2},
    {"mkratnum",                CC_mkratnum,    TOO_MANY_1,    WRONG_NO_1},
    {"xpartitsq",               CC_xpartitsq,   TOO_MANY_1,    WRONG_NO_1},
    {"binc",                    TOO_FEW_2,      CC_binc,       WRONG_NO_2},
    {"gi",                      TOO_FEW_2,      CC_gi,         WRONG_NO_2},
    {"exports",                 CC_exports,     TOO_MANY_1,    WRONG_NO_1},
    {"square-free-mod-p",       CC_squareKfreeKmodKp,TOO_MANY_1,WRONG_NO_1},
    {"rat_max",                 TOO_FEW_2,      CC_rat_max,    WRONG_NO_2},
    {"rl_ex",                   TOO_FEW_2,      CC_rl_ex,      WRONG_NO_2},
    {"*invsq",                  CC_Hinvsq,      TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_simpat",             CC_ofsf_simpat, TOO_MANY_1,    WRONG_NO_1},
    {"dip_monp",                CC_dip_monp,    TOO_MANY_1,    WRONG_NO_1},
    {"sfto_dprpartf1",          TOO_FEW_2,      CC_sfto_dprpartf1,WRONG_NO_2},
    {"subscriptedvarp2",        CC_subscriptedvarp2,TOO_MANY_1,WRONG_NO_1},
    {"*kp2q",                   TOO_FEW_2,      CC_Hkp2q,      WRONG_NO_2},
    {"calc_world",              TOO_FEW_2,      CC_calc_world, WRONG_NO_2},
    {"liendimcom",              CC_liendimcom,  TOO_MANY_1,    WRONG_NO_1},
    {"dpmat_gbtag",             CC_dpmat_gbtag, TOO_MANY_1,    WRONG_NO_1},
    {"st_extract_symcells1",    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_st_extract_symcells1},
    {"sfto_deggcd1",            TOO_FEW_2,      CC_sfto_deggcd1,WRONG_NO_2},
    {"addinds",                 TOO_FEW_2,      CC_addinds,    WRONG_NO_2},
    {"qqe_length-graph-bterm",  TOO_FEW_2,      CC_qqe_lengthKgraphKbterm,WRONG_NO_2},
    {"crprimp",                 CC_crprimp,     TOO_MANY_1,    WRONG_NO_1},
    {"remove_critical_pairs",   TOO_FEW_2,      CC_remove_critical_pairs,WRONG_NO_2},
    {"physopplus",              CC_physopplus,  TOO_MANY_1,    WRONG_NO_1},
    {"bassoc",                  TOO_FEW_2,      CC_bassoc,     WRONG_NO_2},
    {"*sq2fourier",             CC_Hsq2fourier, TOO_MANY_1,    WRONG_NO_1},
    {"all_index_lst",           CC_all_index_lst,TOO_MANY_1,   WRONG_NO_1},
    {"sc_create",               CC_sc_create,   TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u54", (two_args *)"115554 2765653 2485031", 0}
};

// end of generated code
