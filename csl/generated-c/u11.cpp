
// $destdir/u11.c        Machine generated C code

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



// Code for getphystype

static LispObject CC_getphystype(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5547, v_5548;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5442;
// end of prologue
    v_5547 = stack[0];
    fn = elt(env, 7); // physopp
    v_5547 = (*qfn1(fn))(fn, v_5547);
    env = stack[-2];
    if (v_5547 == nil) goto v_5450;
    v_5547 = stack[0];
    fn = elt(env, 8); // scalopp
    v_5547 = (*qfn1(fn))(fn, v_5547);
    env = stack[-2];
    if (v_5547 == nil) goto v_5456;
    v_5547 = elt(env, 1); // scalar
    goto v_5454;
v_5456:
    v_5547 = stack[0];
    fn = elt(env, 9); // vecopp
    v_5547 = (*qfn1(fn))(fn, v_5547);
    env = stack[-2];
    if (v_5547 == nil) goto v_5461;
    v_5547 = elt(env, 2); // vector
    goto v_5454;
v_5461:
    v_5547 = stack[0];
    fn = elt(env, 10); // tensopp
    v_5547 = (*qfn1(fn))(fn, v_5547);
    env = stack[-2];
    if (v_5547 == nil) goto v_5466;
    v_5547 = elt(env, 3); // tensor
    goto v_5454;
v_5466:
    v_5547 = stack[0];
    fn = elt(env, 11); // po!:statep
    v_5547 = (*qfn1(fn))(fn, v_5547);
    env = stack[-2];
    if (v_5547 == nil) goto v_5471;
    v_5547 = elt(env, 4); // state
    goto v_5454;
v_5471:
    v_5547 = nil;
    goto v_5454;
    v_5547 = nil;
v_5454:
    goto v_5448;
v_5450:
    v_5547 = stack[0];
    if (!consp(v_5547)) goto v_5478;
    else goto v_5479;
v_5478:
    v_5547 = nil;
    goto v_5448;
v_5479:
    v_5547 = stack[0];
    v_5547 = qcar(v_5547);
    if (!symbolp(v_5547)) v_5548 = nil;
    else { v_5548 = qfastgets(v_5547);
           if (v_5548 != nil) { v_5548 = elt(v_5548, 18); // phystype
#ifdef RECORD_GET
             if (v_5548 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v_5548 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v_5548 == SPID_NOPROP) v_5548 = nil; }}
#endif
    v_5547 = v_5548;
    if (v_5548 == nil) goto v_5483;
    goto v_5448;
v_5483:
    goto v_5495;
v_5491:
    v_5547 = stack[0];
    v_5548 = qcar(v_5547);
    goto v_5492;
v_5493:
    v_5547 = elt(env, 5); // phystypefn
    goto v_5494;
v_5495:
    goto v_5491;
v_5492:
    goto v_5493;
v_5494:
    v_5548 = get(v_5548, v_5547);
    env = stack[-2];
    v_5547 = v_5548;
    if (v_5548 == nil) goto v_5489;
    goto v_5504;
v_5500:
    v_5548 = v_5547;
    goto v_5501;
v_5502:
    v_5547 = stack[0];
    v_5547 = qcdr(v_5547);
    goto v_5503;
v_5504:
    goto v_5500;
v_5501:
    goto v_5502;
v_5503:
        return Lapply1(nil, v_5548, v_5547);
v_5489:
    v_5547 = stack[0];
    fn = elt(env, 12); // collectphystype
    v_5548 = (*qfn1(fn))(fn, v_5547);
    env = stack[-2];
    v_5547 = v_5548;
    if (v_5548 == nil) goto v_5508;
    else goto v_5509;
v_5508:
    v_5547 = nil;
    goto v_5448;
v_5509:
    v_5548 = v_5547;
    v_5548 = qcdr(v_5548);
    if (v_5548 == nil) goto v_5513;
    else goto v_5514;
v_5513:
    v_5547 = qcar(v_5547);
    goto v_5448;
v_5514:
    goto v_5525;
v_5521:
    v_5548 = elt(env, 4); // state
    goto v_5522;
v_5523:
    goto v_5524;
v_5525:
    goto v_5521;
v_5522:
    goto v_5523;
v_5524:
    v_5547 = Lmember(nil, v_5548, v_5547);
    if (v_5547 == nil) goto v_5520;
    v_5547 = elt(env, 4); // state
    goto v_5448;
v_5520:
    goto v_5537;
v_5533:
    stack[-1] = elt(env, 0); // getphystype
    goto v_5534;
v_5535:
    goto v_5544;
v_5540:
    v_5548 = elt(env, 6); // "PHYSOP type conflict in"
    goto v_5541;
v_5542:
    v_5547 = stack[0];
    goto v_5543;
v_5544:
    goto v_5540;
v_5541:
    goto v_5542;
v_5543:
    v_5547 = list2(v_5548, v_5547);
    env = stack[-2];
    goto v_5536;
v_5537:
    goto v_5533;
v_5534:
    goto v_5535;
v_5536:
    {
        LispObject v_5551 = stack[-1];
        fn = elt(env, 13); // rederr2
        return (*qfn2(fn))(fn, v_5551, v_5547);
    }
    v_5547 = nil;
v_5448:
    return onevalue(v_5547);
}



// Code for convertmode1

static LispObject CC_convertmode1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_5573, v_5574, v_5575, v_5576, v_5577, v_5578, v_5579;
    LispObject fn;
    LispObject v_5445, v_5444, v_5443, v_5442;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "convertmode1");
    va_start(aa, nargs);
    v_5442 = va_arg(aa, LispObject);
    v_5443 = va_arg(aa, LispObject);
    v_5444 = va_arg(aa, LispObject);
    v_5445 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_5445,v_5444,v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_5442,v_5443,v_5444,v_5445);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_5575 = v_5445;
    v_5576 = v_5444;
    v_5577 = v_5443;
    v_5578 = v_5442;
// end of prologue
    goto v_5458;
v_5454:
    v_5574 = v_5575;
    goto v_5455;
v_5456:
    v_5573 = elt(env, 1); // real
    goto v_5457;
v_5458:
    goto v_5454;
v_5455:
    goto v_5456;
v_5457:
    if (v_5574 == v_5573) goto v_5452;
    else goto v_5453;
v_5452:
    v_5573 = elt(env, 2); // algebraic
    v_5575 = v_5573;
    goto v_5451;
v_5453:
v_5451:
    goto v_5470;
v_5466:
    v_5574 = v_5576;
    goto v_5467;
v_5468:
    v_5573 = elt(env, 1); // real
    goto v_5469;
v_5470:
    goto v_5466;
v_5467:
    goto v_5468;
v_5469:
    if (v_5574 == v_5573) goto v_5464;
    else goto v_5465;
v_5464:
    v_5573 = elt(env, 2); // algebraic
    v_5576 = v_5573;
    goto v_5463;
v_5465:
v_5463:
    goto v_5482;
v_5478:
    v_5574 = v_5576;
    goto v_5479;
v_5480:
    v_5573 = v_5575;
    goto v_5481;
v_5482:
    goto v_5478;
v_5479:
    goto v_5480;
v_5481:
    if (v_5574 == v_5573) goto v_5476;
    else goto v_5477;
v_5476:
    v_5573 = v_5578;
    goto v_5449;
v_5477:
    v_5573 = v_5578;
    if (symbolp(v_5573)) goto v_5488;
    else goto v_5487;
v_5488:
    goto v_5496;
v_5492:
    v_5574 = v_5578;
    goto v_5493;
v_5494:
    v_5573 = v_5577;
    goto v_5495;
v_5496:
    goto v_5492;
v_5493:
    goto v_5494;
v_5495:
    v_5573 = Latsoc(nil, v_5574, v_5573);
    v_5579 = v_5573;
    if (v_5573 == nil) goto v_5487;
    goto v_5509;
v_5505:
    v_5573 = v_5579;
    v_5574 = qcdr(v_5573);
    goto v_5506;
v_5507:
    v_5573 = elt(env, 3); // (integer scalar real)
    goto v_5508;
v_5509:
    goto v_5505;
v_5506:
    goto v_5507;
v_5508:
    v_5573 = Lmemq(nil, v_5574, v_5573);
    if (v_5573 == nil) goto v_5503;
    else goto v_5504;
v_5503:
    goto v_5518;
v_5514:
    v_5573 = v_5579;
    v_5574 = qcdr(v_5573);
    goto v_5515;
v_5516:
    v_5573 = v_5575;
    goto v_5517;
v_5518:
    goto v_5514;
v_5515:
    goto v_5516;
v_5517:
    v_5573 = (v_5574 == v_5573 ? lisp_true : nil);
    v_5573 = (v_5573 == nil ? lisp_true : nil);
    goto v_5502;
v_5504:
    v_5573 = nil;
    goto v_5502;
    v_5573 = nil;
v_5502:
    if (v_5573 == nil) goto v_5487;
    goto v_5536;
v_5528:
    v_5573 = v_5578;
    goto v_5529;
v_5530:
    v_5574 = v_5577;
    goto v_5531;
v_5532:
    v_5575 = v_5576;
    goto v_5533;
v_5534:
    v_5576 = v_5579;
    v_5576 = qcdr(v_5576);
    goto v_5535;
v_5536:
    goto v_5528;
v_5529:
    goto v_5530;
v_5531:
    goto v_5532;
v_5533:
    goto v_5534;
v_5535:
    {
        fn = elt(env, 4); // convertmode
        return (*qfnn(fn))(fn, 4, v_5573, v_5574, v_5575, v_5576);
    }
v_5487:
    goto v_5549;
v_5545:
    v_5574 = v_5575;
    goto v_5546;
v_5547:
    v_5573 = v_5576;
    goto v_5548;
v_5549:
    goto v_5545;
v_5546:
    goto v_5547;
v_5548:
    v_5573 = get(v_5574, v_5573);
    env = stack[0];
    v_5579 = v_5573;
    if (v_5573 == nil) goto v_5542;
    else goto v_5543;
v_5542:
    goto v_5557;
v_5553:
    v_5573 = v_5575;
    goto v_5554;
v_5555:
    v_5574 = v_5576;
    goto v_5556;
v_5557:
    goto v_5553;
v_5554:
    goto v_5555;
v_5556:
    fn = elt(env, 5); // typerr
    v_5573 = (*qfn2(fn))(fn, v_5573, v_5574);
    goto v_5475;
v_5543:
    goto v_5569;
v_5563:
    v_5573 = v_5579;
    goto v_5564;
v_5565:
    v_5574 = v_5578;
    goto v_5566;
v_5567:
    v_5575 = v_5577;
    goto v_5568;
v_5569:
    goto v_5563;
v_5564:
    goto v_5565;
v_5566:
    goto v_5567;
v_5568:
        return Lapply2(nil, 3, v_5573, v_5574, v_5575);
v_5475:
    v_5573 = nil;
v_5449:
    return onevalue(v_5573);
}



// Code for mv!-domainlist!-!-

static LispObject CC_mvKdomainlistKK(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5479, v_5480;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5442,v_5443);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_5443;
    stack[-1] = v_5442;
// end of prologue
    stack[-2] = nil;
v_5448:
    v_5479 = stack[-1];
    if (v_5479 == nil) goto v_5451;
    else goto v_5452;
v_5451:
    v_5479 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_5479);
    }
v_5452:
    goto v_5463;
v_5459:
    goto v_5469;
v_5465:
    v_5479 = stack[-1];
    v_5480 = qcar(v_5479);
    goto v_5466;
v_5467:
    v_5479 = stack[0];
    v_5479 = qcar(v_5479);
    goto v_5468;
v_5469:
    goto v_5465;
v_5466:
    goto v_5467;
v_5468:
    v_5480 = difference2(v_5480, v_5479);
    env = stack[-3];
    goto v_5460;
v_5461:
    v_5479 = stack[-2];
    goto v_5462;
v_5463:
    goto v_5459;
v_5460:
    goto v_5461;
v_5462:
    v_5479 = cons(v_5480, v_5479);
    env = stack[-3];
    stack[-2] = v_5479;
    v_5479 = stack[-1];
    v_5479 = qcdr(v_5479);
    stack[-1] = v_5479;
    v_5479 = stack[0];
    v_5479 = qcdr(v_5479);
    stack[0] = v_5479;
    goto v_5448;
    v_5479 = nil;
    return onevalue(v_5479);
}



// Code for !*id2num

static LispObject CC_Hid2num(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5461, v_5462;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5461 = v_5442;
// end of prologue
    goto v_5455;
v_5451:
    goto v_5452;
v_5453:
    v_5462 = qvalue(elt(env, 1)); // pair_id_num!*
    goto v_5454;
v_5455:
    goto v_5451;
v_5452:
    goto v_5453;
v_5454:
    v_5461 = Lassoc(nil, v_5461, v_5462);
    v_5462 = v_5461;
    if (v_5461 == nil) goto v_5450;
    v_5461 = v_5462;
    v_5461 = qcdr(v_5461);
    goto v_5446;
v_5450:
    v_5461 = nil;
v_5446:
    return onevalue(v_5461);
}



// Code for list_assoc

static LispObject CC_list_assoc(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5470, v_5471, v_5472, v_5473;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5471 = v_5443;
    v_5472 = v_5442;
// end of prologue
v_5447:
    v_5470 = v_5471;
    if (v_5470 == nil) goto v_5450;
    else goto v_5451;
v_5450:
    v_5470 = v_5471;
    goto v_5446;
v_5451:
    goto v_5460;
v_5456:
    v_5470 = v_5471;
    v_5470 = qcar(v_5470);
    v_5473 = qcar(v_5470);
    goto v_5457;
v_5458:
    v_5470 = v_5472;
    goto v_5459;
v_5460:
    goto v_5456;
v_5457:
    goto v_5458;
v_5459:
    if (equal(v_5473, v_5470)) goto v_5454;
    else goto v_5455;
v_5454:
    v_5470 = v_5471;
    goto v_5446;
v_5455:
    v_5470 = v_5471;
    v_5470 = qcdr(v_5470);
    v_5471 = v_5470;
    goto v_5447;
    v_5470 = nil;
v_5446:
    return onevalue(v_5470);
}



// Code for exptf

static LispObject CC_exptf(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5515, v_5516, v_5517;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5442,v_5443);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5443;
    stack[-1] = v_5442;
// end of prologue
    goto v_5454;
v_5450:
    v_5516 = stack[0];
    goto v_5451;
v_5452:
    v_5515 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5453;
v_5454:
    goto v_5450;
v_5451:
    goto v_5452;
v_5453:
    v_5515 = (LispObject)lessp2(v_5516, v_5515);
    v_5515 = v_5515 ? lisp_true : nil;
    env = stack[-2];
    if (v_5515 == nil) goto v_5448;
    goto v_5465;
v_5459:
    v_5517 = elt(env, 1); // "exptf"
    goto v_5460;
v_5461:
    v_5516 = stack[-1];
    goto v_5462;
v_5463:
    v_5515 = stack[0];
    goto v_5464;
v_5465:
    goto v_5459;
v_5460:
    goto v_5461;
v_5462:
    goto v_5463;
v_5464:
    v_5515 = list3(v_5517, v_5516, v_5515);
    env = stack[-2];
    {
        fn = elt(env, 3); // errach
        return (*qfn1(fn))(fn, v_5515);
    }
v_5448:
    v_5515 = stack[-1];
    if (!consp(v_5515)) goto v_5473;
    else goto v_5474;
v_5473:
    v_5515 = lisp_true;
    goto v_5472;
v_5474:
    v_5515 = stack[-1];
    v_5515 = qcar(v_5515);
    v_5515 = (consp(v_5515) ? nil : lisp_true);
    goto v_5472;
    v_5515 = nil;
v_5472:
    if (v_5515 == nil) goto v_5470;
    goto v_5487;
v_5483:
    v_5516 = stack[-1];
    goto v_5484;
v_5485:
    v_5515 = stack[0];
    goto v_5486;
v_5487:
    goto v_5483;
v_5484:
    goto v_5485;
v_5486:
    {
        fn = elt(env, 4); // !:expt
        return (*qfn2(fn))(fn, v_5516, v_5515);
    }
v_5470:
    v_5515 = qvalue(elt(env, 2)); // !*exp
    if (v_5515 == nil) goto v_5492;
    else goto v_5490;
v_5492:
    v_5515 = stack[-1];
    fn = elt(env, 5); // kernlp
    v_5515 = (*qfn1(fn))(fn, v_5515);
    env = stack[-2];
    if (v_5515 == nil) goto v_5494;
    else goto v_5490;
v_5494:
    goto v_5491;
v_5490:
    goto v_5502;
v_5498:
    v_5516 = stack[-1];
    goto v_5499;
v_5500:
    v_5515 = stack[0];
    goto v_5501;
v_5502:
    goto v_5498;
v_5499:
    goto v_5500;
v_5501:
    {
        fn = elt(env, 6); // exptf1
        return (*qfn2(fn))(fn, v_5516, v_5515);
    }
v_5491:
    goto v_5512;
v_5508:
    v_5516 = stack[-1];
    goto v_5509;
v_5510:
    v_5515 = stack[0];
    goto v_5511;
v_5512:
    goto v_5508;
v_5509:
    goto v_5510;
v_5511:
    {
        fn = elt(env, 7); // mksfpf
        return (*qfn2(fn))(fn, v_5516, v_5515);
    }
    v_5515 = nil;
    return onevalue(v_5515);
}



// Code for lalr_generate_lr0_collection

static LispObject CC_lalr_generate_lr0_collection(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_5559, v_5560, v_5561;
    LispObject fn;
    argcheck(nargs, 0, "lalr_generate_lr0_collection");
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
    goto v_5458;
v_5454:
    fn = elt(env, 3); // lalr_lr0_initial_itemset
    v_5560 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    goto v_5455;
v_5456:
    v_5559 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5457;
v_5458:
    goto v_5454;
v_5455:
    goto v_5456;
v_5457:
    v_5559 = cons(v_5560, v_5559);
    env = stack[-7];
    v_5559 = ncons(v_5559);
    env = stack[-7];
    qvalue(elt(env, 1)) = v_5559; // itemset_collection
    v_5559 = qvalue(elt(env, 1)); // itemset_collection
    v_5559 = qcar(v_5559);
    v_5559 = ncons(v_5559);
    env = stack[-7];
    stack[-6] = v_5559;
    v_5559 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_5559;
v_5467:
    v_5559 = stack[-6];
    if (v_5559 == nil) goto v_5470;
    else goto v_5471;
v_5470:
    goto v_5466;
v_5471:
    v_5559 = stack[-6];
    v_5559 = qcar(v_5559);
    stack[-4] = v_5559;
    v_5559 = stack[-6];
    v_5559 = qcdr(v_5559);
    stack[-6] = v_5559;
    v_5559 = stack[-4];
    v_5559 = qcar(v_5559);
    stack[-3] = v_5559;
    v_5559 = qvalue(elt(env, 2)); // symbols
    stack[-2] = v_5559;
v_5483:
    v_5559 = stack[-2];
    if (v_5559 == nil) goto v_5487;
    else goto v_5488;
v_5487:
    goto v_5482;
v_5488:
    v_5559 = stack[-2];
    v_5559 = qcar(v_5559);
    stack[-1] = v_5559;
    goto v_5503;
v_5499:
    v_5560 = stack[-3];
    goto v_5500;
v_5501:
    v_5559 = stack[-1];
    goto v_5502;
v_5503:
    goto v_5499;
v_5500:
    goto v_5501;
v_5502:
    fn = elt(env, 4); // lalr_compute_lr0_goto
    v_5559 = (*qfn2(fn))(fn, v_5560, v_5559);
    env = stack[-7];
    v_5560 = v_5559;
    if (v_5559 == nil) goto v_5497;
    goto v_5514;
v_5510:
    v_5561 = v_5560;
    goto v_5511;
v_5512:
    v_5559 = qvalue(elt(env, 1)); // itemset_collection
    goto v_5513;
v_5514:
    goto v_5510;
v_5511:
    goto v_5512;
v_5513:
    v_5559 = Lassoc(nil, v_5561, v_5559);
    v_5561 = v_5559;
    if (v_5559 == nil) goto v_5509;
    v_5559 = v_5561;
    stack[0] = v_5559;
    goto v_5507;
v_5509:
    goto v_5526;
v_5522:
    stack[0] = v_5560;
    goto v_5523;
v_5524:
    v_5559 = stack[-5];
    v_5559 = add1(v_5559);
    env = stack[-7];
    stack[-5] = v_5559;
    goto v_5525;
v_5526:
    goto v_5522;
v_5523:
    goto v_5524;
v_5525:
    v_5559 = cons(stack[0], v_5559);
    env = stack[-7];
    stack[0] = v_5559;
    goto v_5535;
v_5531:
    v_5560 = stack[0];
    goto v_5532;
v_5533:
    v_5559 = qvalue(elt(env, 1)); // itemset_collection
    goto v_5534;
v_5535:
    goto v_5531;
v_5532:
    goto v_5533;
v_5534:
    v_5559 = cons(v_5560, v_5559);
    env = stack[-7];
    qvalue(elt(env, 1)) = v_5559; // itemset_collection
    goto v_5543;
v_5539:
    v_5560 = stack[0];
    goto v_5540;
v_5541:
    v_5559 = stack[-6];
    goto v_5542;
v_5543:
    goto v_5539;
v_5540:
    goto v_5541;
v_5542:
    v_5559 = cons(v_5560, v_5559);
    env = stack[-7];
    stack[-6] = v_5559;
    goto v_5507;
v_5507:
    goto v_5553;
v_5547:
    v_5561 = stack[-4];
    goto v_5548;
v_5549:
    v_5560 = stack[-1];
    goto v_5550;
v_5551:
    v_5559 = stack[0];
    goto v_5552;
v_5553:
    goto v_5547;
v_5548:
    goto v_5549;
v_5550:
    goto v_5551;
v_5552:
    fn = elt(env, 5); // lalr_add_goto
    v_5559 = (*qfnn(fn))(fn, 3, v_5561, v_5560, v_5559);
    env = stack[-7];
    goto v_5495;
v_5497:
v_5495:
    v_5559 = stack[-2];
    v_5559 = qcdr(v_5559);
    stack[-2] = v_5559;
    goto v_5483;
v_5482:
    goto v_5467;
v_5466:
    v_5559 = nil;
    return onevalue(v_5559);
}



// Code for quotfx

static LispObject CC_quotfx(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5477, v_5478, v_5479;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5478 = v_5443;
    v_5479 = v_5442;
// end of prologue
    v_5477 = qvalue(elt(env, 1)); // !*exp
    if (v_5477 == nil) goto v_5451;
    else goto v_5452;
v_5451:
    v_5477 = lisp_true;
    goto v_5450;
v_5452:
    v_5477 = qvalue(elt(env, 2)); // !*mcd
    v_5477 = (v_5477 == nil ? lisp_true : nil);
    goto v_5450;
    v_5477 = nil;
v_5450:
    if (v_5477 == nil) goto v_5448;
    goto v_5464;
v_5460:
    v_5477 = v_5479;
    goto v_5461;
v_5462:
    goto v_5463;
v_5464:
    goto v_5460;
v_5461:
    goto v_5462;
v_5463:
    {
        fn = elt(env, 3); // quotf
        return (*qfn2(fn))(fn, v_5477, v_5478);
    }
v_5448:
    goto v_5474;
v_5470:
    v_5477 = v_5479;
    goto v_5471;
v_5472:
    goto v_5473;
v_5474:
    goto v_5470;
v_5471:
    goto v_5472;
v_5473:
    {
        fn = elt(env, 4); // quotfx1
        return (*qfn2(fn))(fn, v_5477, v_5478);
    }
    v_5477 = nil;
    return onevalue(v_5477);
}



// Code for janettreefind

static LispObject CC_janettreefind(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5576, v_5577;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_5442;
// end of prologue
    v_5576 = qvalue(elt(env, 1)); // fluidbibasisjanettreerootnode
    if (v_5576 == nil) goto v_5446;
    else goto v_5447;
v_5446:
    v_5576 = nil;
    goto v_5445;
v_5447:
    stack[-5] = nil;
    v_5576 = qvalue(elt(env, 1)); // fluidbibasisjanettreerootnode
    stack[-3] = v_5576;
    goto v_5465;
v_5461:
    v_5577 = stack[-4];
    goto v_5462;
v_5463:
    v_5576 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5464;
v_5465:
    goto v_5461;
v_5462:
    goto v_5463;
v_5464:
    v_5576 = *(LispObject *)((char *)v_5577 + (CELL-TAG_VECTOR) + (((intptr_t)v_5576-TAG_FIXNUM)/(16/CELL)));
    stack[-2] = v_5576;
    v_5576 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_5576;
v_5472:
    goto v_5481;
v_5477:
    v_5577 = stack[-2];
    goto v_5478;
v_5479:
    v_5576 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5480;
v_5481:
    goto v_5477;
v_5478:
    goto v_5479;
v_5480:
    if (((intptr_t)(v_5577)) > ((intptr_t)(v_5576))) goto v_5476;
    goto v_5471;
v_5476:
v_5487:
    goto v_5498;
v_5494:
    v_5576 = stack[-3];
    v_5576 = qcar(v_5576);
    stack[0] = qcar(v_5576);
    goto v_5495;
v_5496:
    goto v_5507;
v_5503:
    v_5577 = stack[-4];
    goto v_5504;
v_5505:
    v_5576 = stack[-1];
    goto v_5506;
v_5507:
    goto v_5503;
v_5504:
    goto v_5505;
v_5506:
    fn = elt(env, 2); // monomgetvariabledegree
    v_5576 = (*qfn2(fn))(fn, v_5577, v_5576);
    env = stack[-6];
    goto v_5497;
v_5498:
    goto v_5494;
v_5495:
    goto v_5496;
v_5497:
    v_5576 = (LispObject)lessp2(stack[0], v_5576);
    v_5576 = v_5576 ? lisp_true : nil;
    env = stack[-6];
    if (v_5576 == nil) goto v_5490;
    v_5576 = stack[-3];
    v_5576 = qcdr(v_5576);
    v_5576 = qcar(v_5576);
    if (v_5576 == nil) goto v_5490;
    goto v_5491;
v_5490:
    goto v_5486;
v_5491:
    v_5576 = stack[-3];
    v_5576 = qcdr(v_5576);
    v_5576 = qcar(v_5576);
    stack[-3] = v_5576;
    goto v_5487;
v_5486:
    goto v_5527;
v_5523:
    v_5576 = stack[-3];
    v_5576 = qcar(v_5576);
    stack[0] = qcar(v_5576);
    goto v_5524;
v_5525:
    goto v_5536;
v_5532:
    v_5577 = stack[-4];
    goto v_5533;
v_5534:
    v_5576 = stack[-1];
    goto v_5535;
v_5536:
    goto v_5532;
v_5533:
    goto v_5534;
v_5535:
    fn = elt(env, 2); // monomgetvariabledegree
    v_5576 = (*qfn2(fn))(fn, v_5577, v_5576);
    env = stack[-6];
    goto v_5526;
v_5527:
    goto v_5523;
v_5524:
    goto v_5525;
v_5526:
    if (equal(stack[0], v_5576)) goto v_5522;
    v_5576 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_5576;
    goto v_5520;
v_5522:
    v_5576 = stack[-3];
    v_5576 = qcdr(v_5576);
    v_5576 = qcdr(v_5576);
    if (v_5576 == nil) goto v_5542;
    goto v_5550;
v_5546:
    stack[0] = stack[-2];
    goto v_5547;
v_5548:
    goto v_5557;
v_5553:
    v_5577 = stack[-4];
    goto v_5554;
v_5555:
    v_5576 = stack[-1];
    goto v_5556;
v_5557:
    goto v_5553;
v_5554:
    goto v_5555;
v_5556:
    fn = elt(env, 2); // monomgetvariabledegree
    v_5576 = (*qfn2(fn))(fn, v_5577, v_5576);
    env = stack[-6];
    goto v_5549;
v_5550:
    goto v_5546;
v_5547:
    goto v_5548;
v_5549:
    v_5576 = (LispObject)(intptr_t)((intptr_t)stack[0] - (intptr_t)v_5576 + TAG_FIXNUM);
    stack[-2] = v_5576;
    v_5576 = stack[-1];
    v_5576 = (LispObject)((intptr_t)(v_5576) + 0x10);
    stack[-1] = v_5576;
    v_5576 = stack[-3];
    v_5576 = qcdr(v_5576);
    v_5576 = qcdr(v_5576);
    stack[-3] = v_5576;
    goto v_5520;
v_5542:
    v_5576 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_5576;
    v_5576 = stack[-3];
    v_5576 = qcar(v_5576);
    v_5576 = qcdr(v_5576);
    stack[-5] = v_5576;
    goto v_5520;
v_5520:
    goto v_5472;
v_5471:
    v_5576 = stack[-5];
    goto v_5445;
    v_5576 = nil;
v_5445:
    return onevalue(v_5576);
}



// Code for diffp1

static LispObject CC_diffp1(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5498, v_5499, v_5500;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5442,v_5443);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_5498 = v_5443;
    v_5500 = v_5442;
// end of prologue
    goto v_5453;
v_5449:
    v_5499 = v_5500;
    v_5499 = qcar(v_5499);
    goto v_5450;
v_5451:
    goto v_5452;
v_5453:
    goto v_5449;
v_5450:
    goto v_5451;
v_5452:
    if (v_5499 == v_5498) goto v_5448;
    v_5498 = nil;
    goto v_5446;
v_5448:
    goto v_5464;
v_5460:
    v_5498 = v_5500;
    v_5499 = qcdr(v_5498);
    goto v_5461;
v_5462:
    v_5498 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5463;
v_5464:
    goto v_5460;
v_5461:
    goto v_5462;
v_5463:
    if (v_5499 == v_5498) goto v_5458;
    else goto v_5459;
v_5458:
    v_5498 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5446;
v_5459:
    goto v_5476;
v_5472:
    v_5498 = v_5500;
    stack[-1] = qcdr(v_5498);
    goto v_5473;
v_5474:
    goto v_5485;
v_5481:
    goto v_5491;
v_5487:
    v_5498 = v_5500;
    stack[0] = qcar(v_5498);
    goto v_5488;
v_5489:
    v_5498 = v_5500;
    v_5498 = qcdr(v_5498);
    v_5498 = sub1(v_5498);
    env = stack[-2];
    goto v_5490;
v_5491:
    goto v_5487;
v_5488:
    goto v_5489;
v_5490:
    fn = elt(env, 1); // to
    v_5499 = (*qfn2(fn))(fn, stack[0], v_5498);
    env = stack[-2];
    goto v_5482;
v_5483:
    v_5498 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5484;
v_5485:
    goto v_5481;
v_5482:
    goto v_5483;
v_5484:
    v_5498 = cons(v_5499, v_5498);
    env = stack[-2];
    v_5498 = ncons(v_5498);
    env = stack[-2];
    goto v_5475;
v_5476:
    goto v_5472;
v_5473:
    goto v_5474;
v_5475:
    {
        LispObject v_5503 = stack[-1];
        fn = elt(env, 2); // multd
        return (*qfn2(fn))(fn, v_5503, v_5498);
    }
    v_5498 = nil;
v_5446:
    return onevalue(v_5498);
}



// Code for revv0

static LispObject CC_revv0(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5512, v_5513;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5442,v_5443);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_5443;
    stack[-1] = v_5442;
// end of prologue
v_5441:
    goto v_5453;
v_5449:
    v_5512 = stack[-1];
    v_5512 = qcdr(v_5512);
    v_5513 = qcar(v_5512);
    goto v_5450;
v_5451:
    v_5512 = stack[0];
    goto v_5452;
v_5453:
    goto v_5449;
v_5450:
    goto v_5451;
v_5452:
    if (v_5513 == v_5512) goto v_5447;
    else goto v_5448;
v_5447:
    v_5512 = stack[-1];
    goto v_5446;
v_5448:
    v_5512 = stack[-1];
    v_5512 = qcdr(v_5512);
    v_5512 = qcar(v_5512);
    stack[-2] = v_5512;
    goto v_5472;
v_5468:
    v_5512 = stack[-1];
    v_5513 = qcdr(v_5512);
    goto v_5469;
v_5470:
    v_5512 = stack[-1];
    v_5512 = qcdr(v_5512);
    v_5512 = qcdr(v_5512);
    v_5512 = qcar(v_5512);
    goto v_5471;
v_5472:
    goto v_5468;
v_5469:
    goto v_5470;
v_5471:
    v_5512 = Lrplaca(nil, v_5513, v_5512);
    env = stack[-3];
    goto v_5484;
v_5480:
    v_5512 = stack[-1];
    v_5512 = qcdr(v_5512);
    v_5513 = qcdr(v_5512);
    goto v_5481;
v_5482:
    v_5512 = stack[-1];
    v_5512 = qcdr(v_5512);
    v_5512 = qcdr(v_5512);
    v_5512 = qcdr(v_5512);
    v_5512 = qcar(v_5512);
    goto v_5483;
v_5484:
    goto v_5480;
v_5481:
    goto v_5482;
v_5483:
    v_5512 = Lrplaca(nil, v_5513, v_5512);
    env = stack[-3];
    goto v_5498;
v_5494:
    v_5512 = stack[-1];
    v_5512 = qcdr(v_5512);
    v_5512 = qcdr(v_5512);
    v_5513 = qcdr(v_5512);
    goto v_5495;
v_5496:
    v_5512 = stack[-2];
    goto v_5497;
v_5498:
    goto v_5494;
v_5495:
    goto v_5496;
v_5497:
    v_5512 = Lrplaca(nil, v_5513, v_5512);
    env = stack[-3];
    goto v_5509;
v_5505:
    v_5513 = stack[-1];
    goto v_5506;
v_5507:
    v_5512 = stack[0];
    goto v_5508;
v_5509:
    goto v_5505;
v_5506:
    goto v_5507;
v_5508:
    stack[-1] = v_5513;
    stack[0] = v_5512;
    goto v_5441;
    goto v_5446;
    v_5512 = nil;
v_5446:
    return onevalue(v_5512);
}



// Code for tayexp!-difference

static LispObject CC_tayexpKdifference(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5525, v_5526, v_5527;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5442,v_5443);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5443;
    v_5526 = v_5442;
// end of prologue
    v_5525 = v_5526;
    if (!consp(v_5525)) goto v_5451;
    else goto v_5452;
v_5451:
    v_5525 = stack[0];
    v_5525 = (consp(v_5525) ? nil : lisp_true);
    goto v_5450;
v_5452:
    v_5525 = nil;
    goto v_5450;
    v_5525 = nil;
v_5450:
    if (v_5525 == nil) goto v_5448;
    goto v_5464;
v_5460:
    goto v_5461;
v_5462:
    v_5525 = stack[0];
    goto v_5463;
v_5464:
    goto v_5460;
v_5461:
    goto v_5462;
v_5463:
    return difference2(v_5526, v_5525);
v_5448:
    v_5525 = v_5526;
    if (!consp(v_5525)) goto v_5471;
    else goto v_5472;
v_5471:
    goto v_5479;
v_5475:
    v_5525 = v_5526;
    fn = elt(env, 1); // !*i2rn
    v_5526 = (*qfn1(fn))(fn, v_5525);
    env = stack[-2];
    goto v_5476;
v_5477:
    v_5525 = stack[0];
    goto v_5478;
v_5479:
    goto v_5475;
v_5476:
    goto v_5477;
v_5478:
    fn = elt(env, 2); // rndifference!:
    v_5525 = (*qfn2(fn))(fn, v_5526, v_5525);
    goto v_5470;
v_5472:
    v_5525 = stack[0];
    if (!consp(v_5525)) goto v_5483;
    else goto v_5484;
v_5483:
    goto v_5491;
v_5487:
    stack[-1] = v_5526;
    goto v_5488;
v_5489:
    v_5525 = stack[0];
    fn = elt(env, 1); // !*i2rn
    v_5525 = (*qfn1(fn))(fn, v_5525);
    env = stack[-2];
    goto v_5490;
v_5491:
    goto v_5487;
v_5488:
    goto v_5489;
v_5490:
    fn = elt(env, 2); // rndifference!:
    v_5525 = (*qfn2(fn))(fn, stack[-1], v_5525);
    goto v_5470;
v_5484:
    goto v_5502;
v_5498:
    goto v_5499;
v_5500:
    v_5525 = stack[0];
    goto v_5501;
v_5502:
    goto v_5498;
v_5499:
    goto v_5500;
v_5501:
    fn = elt(env, 2); // rndifference!:
    v_5525 = (*qfn2(fn))(fn, v_5526, v_5525);
    goto v_5470;
    v_5525 = nil;
v_5470:
    v_5527 = v_5525;
    goto v_5514;
v_5510:
    v_5525 = v_5527;
    v_5525 = qcdr(v_5525);
    v_5526 = qcdr(v_5525);
    goto v_5511;
v_5512:
    v_5525 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5513;
v_5514:
    goto v_5510;
v_5511:
    goto v_5512;
v_5513:
    if (v_5526 == v_5525) goto v_5508;
    else goto v_5509;
v_5508:
    v_5525 = v_5527;
    v_5525 = qcdr(v_5525);
    v_5525 = qcar(v_5525);
    goto v_5507;
v_5509:
    v_5525 = v_5527;
    goto v_5507;
    v_5525 = nil;
v_5507:
    goto v_5446;
    v_5525 = nil;
v_5446:
    return onevalue(v_5525);
}



// Code for cl_smcpknowl

static LispObject CC_cl_smcpknowl(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5484;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_5484 = v_5442;
// end of prologue
    stack[-3] = v_5484;
    v_5484 = stack[-3];
    if (v_5484 == nil) goto v_5453;
    else goto v_5454;
v_5453:
    v_5484 = nil;
    goto v_5448;
v_5454:
    v_5484 = stack[-3];
    v_5484 = qcar(v_5484);
    v_5484 = ncons(v_5484);
    env = stack[-4];
    stack[-1] = v_5484;
    stack[-2] = v_5484;
v_5449:
    v_5484 = stack[-3];
    v_5484 = qcdr(v_5484);
    stack[-3] = v_5484;
    v_5484 = stack[-3];
    if (v_5484 == nil) goto v_5466;
    else goto v_5467;
v_5466:
    v_5484 = stack[-2];
    goto v_5448;
v_5467:
    goto v_5475;
v_5471:
    stack[0] = stack[-1];
    goto v_5472;
v_5473:
    v_5484 = stack[-3];
    v_5484 = qcar(v_5484);
    v_5484 = ncons(v_5484);
    env = stack[-4];
    goto v_5474;
v_5475:
    goto v_5471;
v_5472:
    goto v_5473;
v_5474:
    v_5484 = Lrplacd(nil, stack[0], v_5484);
    env = stack[-4];
    v_5484 = stack[-1];
    v_5484 = qcdr(v_5484);
    stack[-1] = v_5484;
    goto v_5449;
v_5448:
    return onevalue(v_5484);
}



// Code for ofsf_prepat

static LispObject CC_ofsf_prepat(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5463;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_5442;
// end of prologue
    goto v_5451;
v_5445:
    v_5463 = stack[-1];
    stack[-2] = qcar(v_5463);
    goto v_5446;
v_5447:
    v_5463 = stack[-1];
    v_5463 = qcdr(v_5463);
    v_5463 = qcar(v_5463);
    fn = elt(env, 1); // prepf
    stack[0] = (*qfn1(fn))(fn, v_5463);
    env = stack[-3];
    goto v_5448;
v_5449:
    v_5463 = stack[-1];
    v_5463 = qcdr(v_5463);
    v_5463 = qcdr(v_5463);
    v_5463 = qcar(v_5463);
    fn = elt(env, 1); // prepf
    v_5463 = (*qfn1(fn))(fn, v_5463);
    goto v_5450;
v_5451:
    goto v_5445;
v_5446:
    goto v_5447;
v_5448:
    goto v_5449;
v_5450:
    {
        LispObject v_5467 = stack[-2];
        LispObject v_5468 = stack[0];
        return list3(v_5467, v_5468, v_5463);
    }
}



// Code for ibalp_litp

static LispObject CC_ibalp_litp(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5476, v_5477;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_5442;
// end of prologue
    v_5476 = stack[0];
    fn = elt(env, 2); // ibalp_atomp
    v_5476 = (*qfn1(fn))(fn, v_5476);
    env = stack[-1];
    if (v_5476 == nil) goto v_5446;
    else goto v_5445;
v_5446:
    goto v_5457;
v_5453:
    v_5476 = stack[0];
    if (!consp(v_5476)) goto v_5460;
    else goto v_5461;
v_5460:
    v_5476 = stack[0];
    v_5477 = v_5476;
    goto v_5459;
v_5461:
    v_5476 = stack[0];
    v_5476 = qcar(v_5476);
    v_5477 = v_5476;
    goto v_5459;
    v_5477 = nil;
v_5459:
    goto v_5454;
v_5455:
    v_5476 = elt(env, 1); // not
    goto v_5456;
v_5457:
    goto v_5453;
v_5454:
    goto v_5455;
v_5456:
    if (v_5477 == v_5476) goto v_5451;
    else goto v_5452;
v_5451:
    v_5476 = stack[0];
    v_5476 = qcdr(v_5476);
    v_5476 = qcar(v_5476);
    {
        fn = elt(env, 2); // ibalp_atomp
        return (*qfn1(fn))(fn, v_5476);
    }
v_5452:
    v_5476 = nil;
    goto v_5450;
    v_5476 = nil;
v_5450:
v_5445:
    return onevalue(v_5476);
}



// Code for quotfail!-mod!-p

static LispObject CC_quotfailKmodKp(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5467, v_5468, v_5469;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5442,v_5443);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_5468 = v_5443;
    v_5469 = v_5442;
// end of prologue
    v_5467 = lisp_true;
    qvalue(elt(env, 1)) = v_5467; // exact!-quotient!-flag
    goto v_5454;
v_5450:
    v_5467 = v_5469;
    goto v_5451;
v_5452:
    goto v_5453;
v_5454:
    goto v_5450;
v_5451:
    goto v_5452;
v_5453:
    fn = elt(env, 3); // quotient!-mod!-p
    v_5467 = (*qfn2(fn))(fn, v_5467, v_5468);
    env = stack[0];
    v_5468 = v_5467;
    v_5467 = qvalue(elt(env, 1)); // exact!-quotient!-flag
    if (v_5467 == nil) goto v_5460;
    v_5467 = v_5468;
    goto v_5447;
v_5460:
    v_5467 = elt(env, 2); // "Quotient not exact (mod p)"
    fn = elt(env, 4); // errorf
    v_5467 = (*qfn1(fn))(fn, v_5467);
    goto v_5458;
v_5458:
    v_5467 = nil;
v_5447:
    return onevalue(v_5467);
}



// Code for smtp

static LispObject CC_smtp(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5643, v_5644, v_5645, v_5646;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5442,v_5443);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_5443;
    stack[0] = v_5442;
// end of prologue
    v_5643 = stack[0];
    if (!consp(v_5643)) goto v_5458;
    else goto v_5459;
v_5458:
    v_5643 = stack[0];
    if (!symbolp(v_5643)) v_5643 = nil;
    else { v_5643 = qfastgets(v_5643);
           if (v_5643 != nil) { v_5643 = elt(v_5643, 4); // avalue
#ifdef RECORD_GET
             if (v_5643 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_5643 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_5643 == SPID_NOPROP) v_5643 = nil; }}
#endif
    v_5643 = qcdr(v_5643);
    v_5643 = qcar(v_5643);
    stack[-7] = v_5643;
    v_5643 = stack[-7];
    v_5643 = qcdr(v_5643);
    v_5643 = qcdr(v_5643);
    v_5643 = qcar(v_5643);
    v_5644 = v_5643;
    goto v_5457;
v_5459:
    goto v_5476;
v_5472:
    v_5644 = stack[0];
    goto v_5473;
v_5474:
    v_5643 = elt(env, 1); // sparsemat
    goto v_5475;
v_5476:
    goto v_5472;
v_5473:
    goto v_5474;
v_5475:
    if (!consp(v_5644)) goto v_5470;
    v_5644 = qcar(v_5644);
    if (v_5644 == v_5643) goto v_5469;
    else goto v_5470;
v_5469:
    v_5643 = stack[0];
    stack[-7] = v_5643;
    v_5643 = stack[-7];
    v_5643 = qcdr(v_5643);
    v_5643 = qcdr(v_5643);
    v_5643 = qcar(v_5643);
    v_5644 = v_5643;
    goto v_5457;
v_5470:
    goto v_5491;
v_5487:
    v_5643 = stack[0];
    v_5643 = qcdr(v_5643);
    v_5644 = qcar(v_5643);
    goto v_5488;
v_5489:
    v_5643 = stack[-6];
    goto v_5490;
v_5491:
    goto v_5487;
v_5488:
    goto v_5489;
v_5490:
    v_5643 = CC_smtp(elt(env, 0), v_5644, v_5643);
    env = stack[-8];
    stack[-7] = v_5643;
    v_5643 = stack[-7];
    v_5643 = qcdr(v_5643);
    v_5643 = qcdr(v_5643);
    v_5643 = qcar(v_5643);
    v_5644 = v_5643;
    goto v_5457;
v_5457:
    v_5643 = v_5644;
    v_5643 = qcdr(v_5643);
    v_5643 = qcar(v_5643);
    stack[-4] = v_5643;
    v_5643 = v_5644;
    v_5643 = qcdr(v_5643);
    v_5643 = qcdr(v_5643);
    v_5643 = qcar(v_5643);
    goto v_5512;
v_5508:
    stack[-1] = v_5643;
    goto v_5509;
v_5510:
    goto v_5521;
v_5515:
    v_5645 = elt(env, 2); // spm
    goto v_5516;
v_5517:
    v_5644 = v_5643;
    goto v_5518;
v_5519:
    v_5643 = stack[-4];
    goto v_5520;
v_5521:
    goto v_5515;
v_5516:
    goto v_5517;
v_5518:
    goto v_5519;
v_5520:
    v_5643 = list3(v_5645, v_5644, v_5643);
    env = stack[-8];
    goto v_5511;
v_5512:
    goto v_5508;
v_5509:
    goto v_5510;
v_5511:
    fn = elt(env, 6); // mkempspmat
    v_5643 = (*qfn2(fn))(fn, stack[-1], v_5643);
    env = stack[-8];
    stack[-5] = v_5643;
    goto v_5534;
v_5530:
    v_5644 = stack[-7];
    goto v_5531;
v_5532:
    v_5643 = elt(env, 1); // sparsemat
    goto v_5533;
v_5534:
    goto v_5530;
v_5531:
    goto v_5532;
v_5533:
    if (!consp(v_5644)) goto v_5527;
    v_5644 = qcar(v_5644);
    if (v_5644 == v_5643) goto v_5528;
v_5527:
    goto v_5544;
v_5538:
    stack[-2] = elt(env, 3); // matrix
    goto v_5539;
v_5540:
    stack[-1] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_5541;
v_5542:
    goto v_5554;
v_5548:
    v_5645 = elt(env, 4); // "Matrix"
    goto v_5549;
v_5550:
    v_5644 = stack[0];
    goto v_5551;
v_5552:
    v_5643 = elt(env, 5); // "not set"
    goto v_5553;
v_5554:
    goto v_5548;
v_5549:
    goto v_5550;
v_5551:
    goto v_5552;
v_5553:
    v_5643 = list3(v_5645, v_5644, v_5643);
    env = stack[-8];
    goto v_5543;
v_5544:
    goto v_5538;
v_5539:
    goto v_5540;
v_5541:
    goto v_5542;
v_5543:
    fn = elt(env, 7); // rerror
    v_5643 = (*qfnn(fn))(fn, 3, stack[-2], stack[-1], v_5643);
    goto v_5526;
v_5528:
    v_5643 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_5643;
v_5563:
    goto v_5575;
v_5571:
    v_5644 = stack[-4];
    goto v_5572;
v_5573:
    v_5643 = stack[-1];
    goto v_5574;
v_5575:
    goto v_5571;
v_5572:
    goto v_5573;
v_5574:
    v_5643 = difference2(v_5644, v_5643);
    env = stack[-8];
    v_5643 = Lminusp(nil, v_5643);
    env = stack[-8];
    if (v_5643 == nil) goto v_5568;
    goto v_5562;
v_5568:
    goto v_5584;
v_5580:
    v_5644 = stack[-7];
    goto v_5581;
v_5582:
    v_5643 = stack[-1];
    goto v_5583;
v_5584:
    goto v_5580;
v_5581:
    goto v_5582;
v_5583:
    fn = elt(env, 8); // findrow
    v_5643 = (*qfn2(fn))(fn, v_5644, v_5643);
    env = stack[-8];
    v_5644 = v_5643;
    v_5643 = v_5644;
    if (v_5643 == nil) goto v_5590;
    v_5643 = stack[-1];
    stack[-3] = v_5643;
    v_5643 = v_5644;
    v_5643 = qcdr(v_5643);
    stack[0] = v_5643;
v_5596:
    v_5643 = stack[0];
    if (v_5643 == nil) goto v_5601;
    else goto v_5602;
v_5601:
    goto v_5595;
v_5602:
    v_5643 = stack[0];
    v_5643 = qcar(v_5643);
    v_5644 = v_5643;
    v_5643 = v_5644;
    v_5643 = qcar(v_5643);
    v_5644 = qcdr(v_5644);
    stack[-2] = v_5644;
    goto v_5621;
v_5613:
    goto v_5629;
v_5623:
    v_5645 = stack[-5];
    goto v_5624;
v_5625:
    v_5644 = v_5643;
    goto v_5626;
v_5627:
    v_5643 = stack[-3];
    goto v_5628;
v_5629:
    goto v_5623;
v_5624:
    goto v_5625;
v_5626:
    goto v_5627;
v_5628:
    v_5646 = list3(v_5645, v_5644, v_5643);
    env = stack[-8];
    goto v_5614;
v_5615:
    v_5645 = stack[-2];
    goto v_5616;
v_5617:
    v_5644 = stack[-5];
    goto v_5618;
v_5619:
    v_5643 = stack[-6];
    goto v_5620;
v_5621:
    goto v_5613;
v_5614:
    goto v_5615;
v_5616:
    goto v_5617;
v_5618:
    goto v_5619;
v_5620:
    fn = elt(env, 9); // letmtr3
    v_5643 = (*qfnn(fn))(fn, 4, v_5646, v_5645, v_5644, v_5643);
    env = stack[-8];
    v_5643 = stack[0];
    v_5643 = qcdr(v_5643);
    stack[0] = v_5643;
    goto v_5596;
v_5595:
    goto v_5588;
v_5590:
v_5588:
    v_5643 = stack[-1];
    v_5643 = add1(v_5643);
    env = stack[-8];
    stack[-1] = v_5643;
    goto v_5563;
v_5562:
    goto v_5526;
v_5526:
    v_5643 = stack[-5];
    return onevalue(v_5643);
}



// Code for on

static LispObject CC_on(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5462;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_5462 = v_5442;
// end of prologue
    stack[0] = v_5462;
v_5447:
    v_5462 = stack[0];
    if (v_5462 == nil) goto v_5451;
    else goto v_5452;
v_5451:
    v_5462 = nil;
    goto v_5446;
v_5452:
    v_5462 = stack[0];
    v_5462 = qcar(v_5462);
    fn = elt(env, 1); // on1
    v_5462 = (*qfn1(fn))(fn, v_5462);
    env = stack[-1];
    v_5462 = stack[0];
    v_5462 = qcdr(v_5462);
    stack[0] = v_5462;
    goto v_5447;
v_5446:
    return onevalue(v_5462);
}



// Code for mkuwedge

static LispObject CC_mkuwedge(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5464, v_5465;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_5464 = v_5442;
// end of prologue
    v_5465 = v_5464;
    v_5465 = qcdr(v_5465);
    if (v_5465 == nil) goto v_5447;
    goto v_5456;
v_5452:
    v_5465 = elt(env, 1); // wedge
    goto v_5453;
v_5454:
    goto v_5455;
v_5456:
    goto v_5452;
v_5453:
    goto v_5454;
v_5455:
    v_5464 = cons(v_5465, v_5464);
    env = stack[0];
    fn = elt(env, 2); // fkern
    v_5464 = (*qfn1(fn))(fn, v_5464);
    v_5464 = qcar(v_5464);
    goto v_5445;
v_5447:
    v_5464 = qcar(v_5464);
    goto v_5445;
    v_5464 = nil;
v_5445:
    return onevalue(v_5464);
}



// Code for form1

static LispObject CC_form1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6010, v_6011, v_6012, v_6013;
    LispObject fn;
    LispObject v_5444, v_5443, v_5442;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "form1");
    va_start(aa, nargs);
    v_5442 = va_arg(aa, LispObject);
    v_5443 = va_arg(aa, LispObject);
    v_5444 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_5444,v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_5442,v_5443,v_5444);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_5444;
    stack[-2] = v_5443;
    stack[-3] = v_5442;
// end of prologue
v_5441:
    v_6010 = stack[-3];
    if (!consp(v_6010)) goto v_5452;
    else goto v_5453;
v_5452:
    v_6010 = stack[-3];
    if (symbolp(v_6010)) goto v_5458;
    v_6010 = stack[-3];
    goto v_5456;
v_5458:
    goto v_5467;
v_5463:
    v_6011 = stack[-3];
    goto v_5464;
v_5465:
    v_6010 = elt(env, 1); // ed
    goto v_5466;
v_5467:
    goto v_5463;
v_5464:
    goto v_5465;
v_5466:
    if (v_6011 == v_6010) goto v_5461;
    else goto v_5462;
v_5461:
    v_6010 = stack[-3];
    return ncons(v_6010);
v_5462:
    v_6010 = stack[-3];
    if (!symbolp(v_6010)) v_6010 = nil;
    else { v_6010 = qfastgets(v_6010);
           if (v_6010 != nil) { v_6010 = elt(v_6010, 48); // modefn
#ifdef RECORD_GET
             if (v_6010 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v_6010 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v_6010 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v_6010 == SPID_NOPROP) v_6010 = nil; else v_6010 = lisp_true; }}
#endif
    if (v_6010 == nil) goto v_5473;
    v_6010 = stack[-3];
    {
        fn = elt(env, 23); // set!-global!-mode
        return (*qfn1(fn))(fn, v_6010);
    }
v_5473:
    goto v_5485;
v_5481:
    v_6011 = stack[-1];
    goto v_5482;
v_5483:
    v_6010 = elt(env, 2); // idfn
    goto v_5484;
v_5485:
    goto v_5481;
v_5482:
    goto v_5483;
v_5484:
    v_6010 = get(v_6011, v_6010);
    stack[-4] = v_6010;
    if (v_6010 == nil) goto v_5479;
    goto v_5495;
v_5489:
    v_6012 = stack[-4];
    goto v_5490;
v_5491:
    v_6011 = stack[-3];
    goto v_5492;
v_5493:
    v_6010 = stack[-2];
    goto v_5494;
v_5495:
    goto v_5489;
v_5490:
    goto v_5491;
v_5492:
    goto v_5493;
v_5494:
        return Lapply2(nil, 3, v_6012, v_6011, v_6010);
v_5479:
    v_6010 = stack[-3];
    goto v_5456;
    v_6010 = nil;
v_5456:
    goto v_5449;
v_5453:
    v_6010 = stack[-3];
    v_6010 = qcar(v_6010);
    if (!consp(v_6010)) goto v_5503;
    goto v_5513;
v_5507:
    v_6012 = stack[-3];
    goto v_5508;
v_5509:
    v_6011 = stack[-2];
    goto v_5510;
v_5511:
    v_6010 = stack[-1];
    goto v_5512;
v_5513:
    goto v_5507;
v_5508:
    goto v_5509;
v_5510:
    goto v_5511;
v_5512:
    {
        fn = elt(env, 24); // form2
        return (*qfnn(fn))(fn, 3, v_6012, v_6011, v_6010);
    }
v_5503:
    v_6010 = stack[-3];
    v_6010 = qcar(v_6010);
    if (symbolp(v_6010)) goto v_5518;
    goto v_5526;
v_5522:
    v_6010 = stack[-3];
    v_6011 = qcar(v_6010);
    goto v_5523;
v_5524:
    v_6010 = elt(env, 3); // "operator"
    goto v_5525;
v_5526:
    goto v_5522;
v_5523:
    goto v_5524;
v_5525:
    fn = elt(env, 25); // typerr
    v_6010 = (*qfn2(fn))(fn, v_6011, v_6010);
    env = stack[-5];
    goto v_5451;
v_5518:
    goto v_5536;
v_5532:
    v_6010 = stack[-3];
    v_6011 = qcar(v_6010);
    goto v_5533;
v_5534:
    v_6010 = elt(env, 4); // comment
    goto v_5535;
v_5536:
    goto v_5532;
v_5533:
    goto v_5534;
v_5535:
    if (v_6011 == v_6010) goto v_5530;
    else goto v_5531;
v_5530:
    goto v_5547;
v_5541:
    v_6010 = stack[-3];
    fn = elt(env, 26); // lastpair
    v_6010 = (*qfn1(fn))(fn, v_6010);
    env = stack[-5];
    v_6012 = qcar(v_6010);
    goto v_5542;
v_5543:
    v_6011 = stack[-2];
    goto v_5544;
v_5545:
    v_6010 = stack[-1];
    goto v_5546;
v_5547:
    goto v_5541;
v_5542:
    goto v_5543;
v_5544:
    goto v_5545;
v_5546:
    stack[-3] = v_6012;
    stack[-2] = v_6011;
    stack[-1] = v_6010;
    goto v_5441;
v_5531:
    goto v_5560;
v_5556:
    v_6010 = stack[-3];
    v_6011 = qcar(v_6010);
    goto v_5557;
v_5558:
    v_6010 = elt(env, 5); // noform
    goto v_5559;
v_5560:
    goto v_5556;
v_5557:
    goto v_5558;
v_5559:
    v_6010 = Lflagp(nil, v_6011, v_6010);
    env = stack[-5];
    if (v_6010 == nil) goto v_5554;
    v_6010 = stack[-3];
    goto v_5449;
v_5554:
    v_6010 = stack[-3];
    v_6010 = qcar(v_6010);
    fn = elt(env, 27); // arrayp
    v_6010 = (*qfn1(fn))(fn, v_6010);
    env = stack[-5];
    if (v_6010 == nil) goto v_5566;
    goto v_5576;
v_5572:
    v_6011 = stack[-1];
    goto v_5573;
v_5574:
    v_6010 = elt(env, 6); // symbolic
    goto v_5575;
v_5576:
    goto v_5572;
v_5573:
    goto v_5574;
v_5575:
    if (v_6011 == v_6010) goto v_5571;
    else goto v_5566;
v_5571:
    goto v_5584;
v_5580:
    stack[0] = elt(env, 7); // getel
    goto v_5581;
v_5582:
    goto v_5593;
v_5587:
    v_6012 = stack[-3];
    goto v_5588;
v_5589:
    v_6011 = stack[-2];
    goto v_5590;
v_5591:
    v_6010 = stack[-1];
    goto v_5592;
v_5593:
    goto v_5587;
v_5588:
    goto v_5589;
v_5590:
    goto v_5591;
v_5592:
    fn = elt(env, 28); // intargfn
    v_6010 = (*qfnn(fn))(fn, 3, v_6012, v_6011, v_6010);
    goto v_5583;
v_5584:
    goto v_5580;
v_5581:
    goto v_5582;
v_5583:
    {
        LispObject v_6019 = stack[0];
        return list2(v_6019, v_6010);
    }
v_5566:
    v_6010 = stack[-3];
    v_6010 = qcdr(v_6010);
    v_6010 = Lconsp(nil, v_6010);
    env = stack[-5];
    if (v_6010 == nil) goto v_5598;
    goto v_5612;
v_5608:
    v_6010 = stack[-3];
    v_6010 = qcar(v_6010);
    if (!symbolp(v_6010)) v_6011 = nil;
    else { v_6011 = qfastgets(v_6010);
           if (v_6011 != nil) { v_6011 = elt(v_6011, 2); // rtype
#ifdef RECORD_GET
             if (v_6011 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_6011 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_6011 == SPID_NOPROP) v_6011 = nil; }}
#endif
    goto v_5609;
v_5610:
    v_6010 = elt(env, 8); // vector
    goto v_5611;
v_5612:
    goto v_5608;
v_5609:
    goto v_5610;
v_5611:
    if (v_6011 == v_6010) goto v_5606;
    else goto v_5607;
v_5606:
    v_6010 = lisp_true;
    goto v_5605;
v_5607:
    v_6010 = stack[-3];
    v_6010 = qcdr(v_6010);
    v_6010 = qcar(v_6010);
    v_6010 = Lsimple_vectorp(nil, v_6010);
    env = stack[-5];
    if (v_6010 == nil) goto v_5622;
    else goto v_5621;
v_5622:
    goto v_5632;
v_5628:
    v_6010 = stack[-3];
    v_6010 = qcdr(v_6010);
    v_6011 = qcar(v_6010);
    goto v_5629;
v_5630:
    v_6010 = elt(env, 9); // vecfn
    goto v_5631;
v_5632:
    goto v_5628;
v_5629:
    goto v_5630;
v_5631:
    v_6010 = Lflagpcar(nil, v_6011, v_6010);
    env = stack[-5];
v_5621:
    goto v_5605;
    v_6010 = nil;
v_5605:
    if (v_6010 == nil) goto v_5598;
    goto v_5644;
v_5638:
    v_6012 = stack[-3];
    goto v_5639;
v_5640:
    v_6011 = stack[-2];
    goto v_5641;
v_5642:
    v_6010 = stack[-1];
    goto v_5643;
v_5644:
    goto v_5638;
v_5639:
    goto v_5640;
v_5641:
    goto v_5642;
v_5643:
    {
        fn = elt(env, 29); // getvect
        return (*qfnn(fn))(fn, 3, v_6012, v_6011, v_6010);
    }
v_5598:
    v_6010 = stack[-3];
    v_6010 = qcar(v_6010);
    if (!symbolp(v_6010)) v_6010 = nil;
    else { v_6010 = qfastgets(v_6010);
           if (v_6010 != nil) { v_6010 = elt(v_6010, 48); // modefn
#ifdef RECORD_GET
             if (v_6010 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v_6010 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v_6010 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v_6010 == SPID_NOPROP) v_6010 = nil; else v_6010 = lisp_true; }}
#endif
    if (v_6010 == nil) goto v_5649;
    goto v_5662;
v_5654:
    v_6010 = stack[-3];
    v_6010 = qcdr(v_6010);
    v_6013 = qcar(v_6010);
    goto v_5655;
v_5656:
    v_6012 = stack[-2];
    goto v_5657;
v_5658:
    v_6011 = stack[-1];
    goto v_5659;
v_5660:
    v_6010 = stack[-3];
    v_6010 = qcar(v_6010);
    goto v_5661;
v_5662:
    goto v_5654;
v_5655:
    goto v_5656;
v_5657:
    goto v_5658;
v_5659:
    goto v_5660;
v_5661:
    {
        fn = elt(env, 30); // convertmode
        return (*qfnn(fn))(fn, 4, v_6013, v_6012, v_6011, v_6010);
    }
v_5649:
    goto v_5677;
v_5673:
    v_6010 = stack[-3];
    v_6011 = qcar(v_6010);
    goto v_5674;
v_5675:
    v_6010 = elt(env, 10); // formfn
    goto v_5676;
v_5677:
    goto v_5673;
v_5674:
    goto v_5675;
v_5676:
    v_6010 = get(v_6011, v_6010);
    env = stack[-5];
    stack[-4] = v_6010;
    if (v_6010 == nil) goto v_5671;
    goto v_5686;
v_5682:
    goto v_5696;
v_5688:
    v_6013 = stack[-4];
    goto v_5689;
v_5690:
    v_6012 = stack[-3];
    goto v_5691;
v_5692:
    v_6011 = stack[-2];
    goto v_5693;
v_5694:
    v_6010 = stack[-1];
    goto v_5695;
v_5696:
    goto v_5688;
v_5689:
    goto v_5690;
v_5691:
    goto v_5692;
v_5693:
    goto v_5694;
v_5695:
    v_6011 = Lapply3(nil, 4, v_6013, v_6012, v_6011, v_6010);
    env = stack[-5];
    goto v_5683;
v_5684:
    v_6010 = stack[-1];
    goto v_5685;
v_5686:
    goto v_5682;
v_5683:
    goto v_5684;
v_5685:
    {
        fn = elt(env, 31); // macrochk
        return (*qfn2(fn))(fn, v_6011, v_6010);
    }
v_5671:
    goto v_5708;
v_5704:
    v_6010 = stack[-3];
    v_6010 = qcar(v_6010);
    if (!symbolp(v_6010)) v_6011 = nil;
    else { v_6011 = qfastgets(v_6010);
           if (v_6011 != nil) { v_6011 = elt(v_6011, 36); // stat
#ifdef RECORD_GET
             if (v_6011 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v_6011 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v_6011 == SPID_NOPROP) v_6011 = nil; }}
#endif
    goto v_5705;
v_5706:
    v_6010 = elt(env, 11); // rlis
    goto v_5707;
v_5708:
    goto v_5704;
v_5705:
    goto v_5706;
v_5707:
    if (v_6011 == v_6010) goto v_5702;
    else goto v_5703;
v_5702:
    goto v_5718;
v_5714:
    goto v_5726;
v_5720:
    v_6012 = stack[-3];
    goto v_5721;
v_5722:
    v_6011 = stack[-2];
    goto v_5723;
v_5724:
    v_6010 = stack[-1];
    goto v_5725;
v_5726:
    goto v_5720;
v_5721:
    goto v_5722;
v_5723:
    goto v_5724;
v_5725:
    fn = elt(env, 32); // formrlis
    v_6011 = (*qfnn(fn))(fn, 3, v_6012, v_6011, v_6010);
    env = stack[-5];
    goto v_5715;
v_5716:
    v_6010 = stack[-1];
    goto v_5717;
v_5718:
    goto v_5714;
v_5715:
    goto v_5716;
v_5717:
    {
        fn = elt(env, 31); // macrochk
        return (*qfn2(fn))(fn, v_6011, v_6010);
    }
v_5703:
    goto v_5737;
v_5733:
    v_6010 = stack[-3];
    v_6011 = qcar(v_6010);
    goto v_5734;
v_5735:
    v_6010 = elt(env, 12); // !*comma!*
    goto v_5736;
v_5737:
    goto v_5733;
v_5734:
    goto v_5735;
v_5736:
    if (v_6011 == v_6010) goto v_5731;
    else goto v_5732;
v_5731:
    v_6010 = stack[-3];
    v_6010 = qcdr(v_6010);
    v_6010 = qcar(v_6010);
    if (!consp(v_6010)) goto v_5748;
    v_6010 = stack[-3];
    v_6010 = qcdr(v_6010);
    v_6010 = qcdr(v_6010);
    v_6010 = qcar(v_6010);
    if (!consp(v_6010)) goto v_5754;
    else goto v_5755;
v_5754:
    goto v_5765;
v_5761:
    v_6010 = stack[-3];
    v_6010 = qcdr(v_6010);
    v_6010 = qcar(v_6010);
    v_6011 = qcar(v_6010);
    goto v_5762;
v_5763:
    v_6010 = elt(env, 13); // type
    goto v_5764;
v_5765:
    goto v_5761;
v_5762:
    goto v_5763;
v_5764:
    v_6010 = Lflagp(nil, v_6011, v_6010);
    env = stack[-5];
    goto v_5753;
v_5755:
    v_6010 = nil;
    goto v_5753;
    v_6010 = nil;
v_5753:
    goto v_5746;
v_5748:
    v_6010 = nil;
    goto v_5746;
    v_6010 = nil;
v_5746:
    if (v_6010 == nil) goto v_5744;
    v_6010 = stack[-3];
    v_6010 = qcdr(v_6010);
    v_6010 = qcar(v_6010);
    v_6010 = qcar(v_6010);
    fn = elt(env, 33); // blocktyperr
    v_6010 = (*qfn1(fn))(fn, v_6010);
    env = stack[-5];
    goto v_5742;
v_5744:
    goto v_5791;
v_5785:
    stack[-4] = elt(env, 14); // rlisp
    goto v_5786;
v_5787:
    stack[0] = (LispObject)160+TAG_FIXNUM; // 10
    goto v_5788;
v_5789:
    goto v_5799;
v_5795:
    v_6011 = elt(env, 15); // "Syntax error: , invalid after"
    goto v_5796;
v_5797:
    v_6010 = stack[-3];
    v_6010 = qcdr(v_6010);
    v_6010 = qcar(v_6010);
    goto v_5798;
v_5799:
    goto v_5795;
v_5796:
    goto v_5797;
v_5798:
    v_6010 = list2(v_6011, v_6010);
    env = stack[-5];
    goto v_5790;
v_5791:
    goto v_5785;
v_5786:
    goto v_5787;
v_5788:
    goto v_5789;
v_5790:
    fn = elt(env, 34); // rerror
    v_6010 = (*qfnn(fn))(fn, 3, stack[-4], stack[0], v_6010);
    env = stack[-5];
    goto v_5742;
v_5742:
    goto v_5451;
v_5732:
v_5451:
    goto v_5816;
v_5812:
    v_6011 = stack[-1];
    goto v_5813;
v_5814:
    v_6010 = elt(env, 6); // symbolic
    goto v_5815;
v_5816:
    goto v_5812;
v_5813:
    goto v_5814;
v_5815:
    if (v_6011 == v_6010) goto v_5810;
    else goto v_5811;
v_5810:
    v_6010 = lisp_true;
    goto v_5809;
v_5811:
    v_6010 = stack[-3];
    v_6010 = qcar(v_6010);
    if (!symbolp(v_6010)) v_6010 = nil;
    else { v_6010 = qfastgets(v_6010);
           if (v_6010 != nil) { v_6010 = elt(v_6010, 59); // opfn
#ifdef RECORD_GET
             if (v_6010 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v_6010 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v_6010 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v_6010 == SPID_NOPROP) v_6010 = nil; else v_6010 = lisp_true; }}
#endif
    goto v_5809;
    v_6010 = nil;
v_5809:
    if (v_6010 == nil) goto v_5807;
    v_6010 = stack[-3];
    fn = elt(env, 35); // argnochk
    v_6010 = (*qfn1(fn))(fn, v_6010);
    env = stack[-5];
    goto v_5805;
v_5807:
v_5805:
    goto v_5834;
v_5828:
    v_6010 = stack[-3];
    v_6012 = qcdr(v_6010);
    goto v_5829;
v_5830:
    v_6011 = stack[-2];
    goto v_5831;
v_5832:
    v_6010 = stack[-1];
    goto v_5833;
v_5834:
    goto v_5828;
v_5829:
    goto v_5830;
v_5831:
    goto v_5832;
v_5833:
    fn = elt(env, 36); // formlis
    v_6010 = (*qfnn(fn))(fn, 3, v_6012, v_6011, v_6010);
    env = stack[-5];
    stack[-4] = v_6010;
    goto v_5847;
v_5843:
    v_6011 = stack[-4];
    goto v_5844;
v_5845:
    v_6010 = stack[-3];
    v_6010 = qcdr(v_6010);
    goto v_5846;
v_5847:
    goto v_5843;
v_5844:
    goto v_5845;
v_5846:
    if (equal(v_6011, v_6010)) goto v_5841;
    else goto v_5842;
v_5841:
    v_6010 = stack[-3];
    goto v_5840;
v_5842:
    goto v_5859;
v_5855:
    v_6010 = stack[-3];
    v_6011 = qcar(v_6010);
    goto v_5856;
v_5857:
    v_6010 = stack[-4];
    goto v_5858;
v_5859:
    goto v_5855;
v_5856:
    goto v_5857;
v_5858:
    v_6010 = cons(v_6011, v_6010);
    env = stack[-5];
    goto v_5840;
    v_6010 = nil;
v_5840:
    stack[0] = v_6010;
    goto v_5875;
v_5871:
    v_6011 = stack[-1];
    goto v_5872;
v_5873:
    v_6010 = elt(env, 6); // symbolic
    goto v_5874;
v_5875:
    goto v_5871;
v_5872:
    goto v_5873;
v_5874:
    if (v_6011 == v_6010) goto v_5869;
    else goto v_5870;
v_5869:
    v_6010 = lisp_true;
    goto v_5868;
v_5870:
    v_6010 = stack[-3];
    v_6010 = qcar(v_6010);
    if (!symbolp(v_6010)) v_6010 = nil;
    else { v_6010 = qfastgets(v_6010);
           if (v_6010 != nil) { v_6010 = elt(v_6010, 36); // stat
#ifdef RECORD_GET
             if (v_6010 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v_6010 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v_6010 == SPID_NOPROP) v_6010 = nil; }}
#endif
    if (v_6010 == nil) goto v_5883;
    else goto v_5882;
v_5883:
    v_6010 = stack[-3];
    v_6010 = qcdr(v_6010);
    if (v_6010 == nil) goto v_5892;
    else goto v_5893;
v_5892:
    v_6010 = nil;
    goto v_5891;
v_5893:
    goto v_5908;
v_5904:
    v_6010 = stack[-3];
    v_6010 = qcdr(v_6010);
    v_6011 = qcar(v_6010);
    goto v_5905;
v_5906:
    v_6010 = elt(env, 16); // quote
    goto v_5907;
v_5908:
    goto v_5904;
v_5905:
    goto v_5906;
v_5907:
    if (!consp(v_6011)) goto v_5902;
    v_6011 = qcar(v_6011);
    if (v_6011 == v_6010) goto v_5901;
    else goto v_5902;
v_5901:
    v_6010 = qvalue(elt(env, 17)); // !*micro!-version
    if (v_6010 == nil) goto v_5915;
    else goto v_5916;
v_5915:
    v_6010 = nil;
    goto v_5914;
v_5916:
    v_6010 = qvalue(elt(env, 18)); // !*defn
    v_6010 = (v_6010 == nil ? lisp_true : nil);
    goto v_5914;
    v_6010 = nil;
v_5914:
    v_6010 = (v_6010 == nil ? lisp_true : nil);
    goto v_5900;
v_5902:
    v_6010 = nil;
    goto v_5900;
    v_6010 = nil;
v_5900:
    goto v_5891;
    v_6010 = nil;
v_5891:
    if (v_6010 == nil) goto v_5889;
    else goto v_5888;
v_5889:
    goto v_5936;
v_5932:
    v_6011 = stack[0];
    goto v_5933;
v_5934:
    v_6010 = stack[-2];
    goto v_5935;
v_5936:
    goto v_5932;
v_5933:
    goto v_5934;
v_5935:
    fn = elt(env, 37); // intexprnp
    v_6010 = (*qfn2(fn))(fn, v_6011, v_6010);
    env = stack[-5];
    if (v_6010 == nil) goto v_5929;
    else goto v_5930;
v_5929:
    v_6010 = nil;
    goto v_5928;
v_5930:
    v_6010 = qvalue(elt(env, 19)); // !*composites
    if (v_6010 == nil) goto v_5944;
    else goto v_5945;
v_5944:
    goto v_5951;
v_5947:
    v_6011 = qvalue(elt(env, 20)); // current!-modulus
    goto v_5948;
v_5949:
    v_6010 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5950;
v_5951:
    goto v_5947;
v_5948:
    goto v_5949;
v_5950:
    v_6010 = (v_6011 == v_6010 ? lisp_true : nil);
    goto v_5943;
v_5945:
    v_6010 = nil;
    goto v_5943;
    v_6010 = nil;
v_5943:
    goto v_5928;
    v_6010 = nil;
v_5928:
v_5888:
v_5882:
    goto v_5868;
    v_6010 = nil;
v_5868:
    if (v_6010 == nil) goto v_5866;
    goto v_5963;
v_5959:
    v_6011 = stack[0];
    goto v_5960;
v_5961:
    v_6010 = stack[-1];
    goto v_5962;
v_5963:
    goto v_5959;
v_5960:
    goto v_5961;
v_5962:
    {
        fn = elt(env, 31); // macrochk
        return (*qfn2(fn))(fn, v_6011, v_6010);
    }
v_5866:
    goto v_5972;
v_5968:
    v_6011 = stack[-1];
    goto v_5969;
v_5970:
    v_6010 = elt(env, 21); // algebraic
    goto v_5971;
v_5972:
    goto v_5968;
v_5969:
    goto v_5970;
v_5971:
    if (v_6011 == v_6010) goto v_5967;
    goto v_5984;
v_5976:
    v_6013 = stack[0];
    goto v_5977;
v_5978:
    v_6012 = stack[-2];
    goto v_5979;
v_5980:
    v_6011 = stack[-1];
    goto v_5981;
v_5982:
    v_6010 = elt(env, 21); // algebraic
    goto v_5983;
v_5984:
    goto v_5976;
v_5977:
    goto v_5978;
v_5979:
    goto v_5980;
v_5981:
    goto v_5982;
v_5983:
    {
        fn = elt(env, 30); // convertmode
        return (*qfnn(fn))(fn, 4, v_6013, v_6012, v_6011, v_6010);
    }
v_5967:
    goto v_5998;
v_5992:
    stack[0] = elt(env, 22); // list
    goto v_5993;
v_5994:
    goto v_6005;
v_6001:
    v_6010 = stack[-3];
    v_6011 = qcar(v_6010);
    goto v_6002;
v_6003:
    v_6010 = stack[-2];
    goto v_6004;
v_6005:
    goto v_6001;
v_6002:
    goto v_6003;
v_6004:
    fn = elt(env, 38); // algid
    v_6011 = (*qfn2(fn))(fn, v_6011, v_6010);
    goto v_5995;
v_5996:
    v_6010 = stack[-4];
    goto v_5997;
v_5998:
    goto v_5992;
v_5993:
    goto v_5994;
v_5995:
    goto v_5996;
v_5997:
    {
        LispObject v_6020 = stack[0];
        return list2star(v_6020, v_6011, v_6010);
    }
    v_6010 = nil;
v_5449:
    return onevalue(v_6010);
}



// Code for formop

static LispObject CC_formop(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5506, v_5507;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_5442;
// end of prologue
    stack[-2] = nil;
v_5448:
    v_5506 = stack[-1];
    if (!consp(v_5506)) goto v_5457;
    else goto v_5458;
v_5457:
    v_5506 = lisp_true;
    goto v_5456;
v_5458:
    v_5506 = stack[-1];
    v_5506 = qcar(v_5506);
    v_5506 = (consp(v_5506) ? nil : lisp_true);
    goto v_5456;
    v_5506 = nil;
v_5456:
    if (v_5506 == nil) goto v_5454;
    goto v_5449;
v_5454:
    goto v_5471;
v_5467:
    goto v_5477;
v_5473:
    v_5506 = stack[-1];
    v_5506 = qcar(v_5506);
    stack[0] = qcar(v_5506);
    goto v_5474;
v_5475:
    v_5506 = stack[-1];
    v_5506 = qcar(v_5506);
    v_5506 = qcdr(v_5506);
    v_5506 = CC_formop(elt(env, 0), v_5506);
    env = stack[-3];
    goto v_5476;
v_5477:
    goto v_5473;
v_5474:
    goto v_5475;
v_5476:
    fn = elt(env, 1); // multop
    v_5507 = (*qfn2(fn))(fn, stack[0], v_5506);
    env = stack[-3];
    goto v_5468;
v_5469:
    v_5506 = stack[-2];
    goto v_5470;
v_5471:
    goto v_5467;
v_5468:
    goto v_5469;
v_5470:
    v_5506 = cons(v_5507, v_5506);
    env = stack[-3];
    stack[-2] = v_5506;
    v_5506 = stack[-1];
    v_5506 = qcdr(v_5506);
    stack[-1] = v_5506;
    goto v_5448;
v_5449:
    v_5506 = stack[-1];
    v_5507 = v_5506;
v_5450:
    v_5506 = stack[-2];
    if (v_5506 == nil) goto v_5491;
    else goto v_5492;
v_5491:
    v_5506 = v_5507;
    goto v_5447;
v_5492:
    goto v_5500;
v_5496:
    v_5506 = stack[-2];
    v_5506 = qcar(v_5506);
    goto v_5497;
v_5498:
    goto v_5499;
v_5500:
    goto v_5496;
v_5497:
    goto v_5498;
v_5499:
    fn = elt(env, 2); // raddf
    v_5506 = (*qfn2(fn))(fn, v_5506, v_5507);
    env = stack[-3];
    v_5507 = v_5506;
    v_5506 = stack[-2];
    v_5506 = qcdr(v_5506);
    stack[-2] = v_5506;
    goto v_5450;
v_5447:
    return onevalue(v_5506);
}



// Code for leftzeros

static LispObject CC_leftzeros(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5500, v_5501;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5442;
// end of prologue
    stack[-1] = nil;
v_5448:
    v_5500 = stack[0];
    if (v_5500 == nil) goto v_5457;
    else goto v_5458;
v_5457:
    v_5500 = lisp_true;
    goto v_5456;
v_5458:
    goto v_5468;
v_5464:
    v_5500 = stack[0];
    v_5501 = qcar(v_5500);
    goto v_5465;
v_5466:
    v_5500 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5467;
v_5468:
    goto v_5464;
v_5465:
    goto v_5466;
v_5467:
    v_5500 = Lneq(nil, v_5501, v_5500);
    env = stack[-2];
    goto v_5456;
    v_5500 = nil;
v_5456:
    if (v_5500 == nil) goto v_5454;
    goto v_5449;
v_5454:
    goto v_5477;
v_5473:
    v_5501 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5474;
v_5475:
    v_5500 = stack[-1];
    goto v_5476;
v_5477:
    goto v_5473;
v_5474:
    goto v_5475;
v_5476:
    v_5500 = cons(v_5501, v_5500);
    env = stack[-2];
    stack[-1] = v_5500;
    v_5500 = stack[0];
    v_5500 = qcdr(v_5500);
    stack[0] = v_5500;
    goto v_5448;
v_5449:
    v_5500 = (LispObject)0+TAG_FIXNUM; // 0
    v_5501 = v_5500;
v_5450:
    v_5500 = stack[-1];
    if (v_5500 == nil) goto v_5485;
    else goto v_5486;
v_5485:
    v_5500 = v_5501;
    goto v_5447;
v_5486:
    goto v_5493;
v_5489:
    v_5500 = stack[-1];
    v_5500 = qcar(v_5500);
    goto v_5490;
v_5491:
    goto v_5492;
v_5493:
    goto v_5489;
v_5490:
    goto v_5491;
v_5492:
    v_5500 = (LispObject)(intptr_t)((intptr_t)v_5500 + (intptr_t)v_5501 - TAG_FIXNUM);
    v_5501 = v_5500;
    v_5500 = stack[-1];
    v_5500 = qcdr(v_5500);
    stack[-1] = v_5500;
    goto v_5450;
v_5447:
    return onevalue(v_5500);
}



// Code for reduce!-mod!-p

static LispObject CC_reduceKmodKp(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5498, v_5499, v_5500;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5442;
// end of prologue
    v_5498 = stack[0];
    if (v_5498 == nil) goto v_5446;
    else goto v_5447;
v_5446:
    v_5498 = nil;
    goto v_5445;
v_5447:
    v_5498 = stack[0];
    if (!consp(v_5498)) goto v_5454;
    else goto v_5455;
v_5454:
    v_5498 = lisp_true;
    goto v_5453;
v_5455:
    v_5498 = stack[0];
    v_5498 = qcar(v_5498);
    v_5498 = (consp(v_5498) ? nil : lisp_true);
    goto v_5453;
    v_5498 = nil;
v_5453:
    if (v_5498 == nil) goto v_5451;
    v_5498 = stack[0];
    v_5498 = Lmodular_number(nil, v_5498);
    env = stack[-2];
    {
        fn = elt(env, 1); // !*n2f
        return (*qfn1(fn))(fn, v_5498);
    }
v_5451:
    v_5498 = stack[0];
    v_5498 = qcar(v_5498);
    v_5498 = qcdr(v_5498);
    stack[-1] = CC_reduceKmodKp(elt(env, 0), v_5498);
    env = stack[-2];
    v_5498 = stack[0];
    v_5498 = qcdr(v_5498);
    v_5498 = CC_reduceKmodKp(elt(env, 0), v_5498);
    v_5499 = stack[-1];
    v_5500 = v_5499;
    if (v_5500 == nil) goto v_5479;
    else goto v_5480;
v_5479:
    goto v_5478;
v_5480:
    goto v_5492;
v_5486:
    v_5500 = stack[0];
    v_5500 = qcar(v_5500);
    v_5500 = qcar(v_5500);
    goto v_5487;
v_5488:
    goto v_5489;
v_5490:
    goto v_5491;
v_5492:
    goto v_5486;
v_5487:
    goto v_5488;
v_5489:
    goto v_5490;
v_5491:
    return acons(v_5500, v_5499, v_5498);
    v_5498 = nil;
v_5478:
    goto v_5445;
    v_5498 = nil;
v_5445:
    return onevalue(v_5498);
}



// Code for mconv

static LispObject CC_mconv(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5448;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_5442;
// end of prologue
    v_5448 = qvalue(elt(env, 1)); // dmode!*
    fn = elt(env, 2); // dmconv0
    v_5448 = (*qfn1(fn))(fn, v_5448);
    env = stack[-1];
    v_5448 = stack[0];
    {
        fn = elt(env, 3); // mconv1
        return (*qfn1(fn))(fn, v_5448);
    }
}



// Code for lalr_lr0_itemset_to_lalr_kernel

static LispObject CC_lalr_lr0_itemset_to_lalr_kernel(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5502, v_5503;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_5502 = v_5442;
// end of prologue
    stack[-2] = nil;
    stack[-1] = v_5502;
v_5450:
    v_5502 = stack[-1];
    if (v_5502 == nil) goto v_5454;
    else goto v_5455;
v_5454:
    goto v_5449;
v_5455:
    v_5502 = stack[-1];
    v_5502 = qcar(v_5502);
    stack[0] = v_5502;
    goto v_5473;
v_5469:
    v_5502 = stack[0];
    v_5503 = qcar(v_5502);
    goto v_5470;
v_5471:
    v_5502 = elt(env, 1); // !S!'
    goto v_5472;
v_5473:
    goto v_5469;
v_5470:
    goto v_5471;
v_5472:
    if (v_5503 == v_5502) goto v_5467;
    else goto v_5468;
v_5467:
    v_5502 = lisp_true;
    goto v_5466;
v_5468:
    goto v_5485;
v_5481:
    v_5502 = stack[0];
    v_5502 = qcdr(v_5502);
    v_5503 = qcar(v_5502);
    goto v_5482;
v_5483:
    v_5502 = elt(env, 2); // !.
    goto v_5484;
v_5485:
    goto v_5481;
v_5482:
    goto v_5483;
v_5484:
    v_5502 = Lneq(nil, v_5503, v_5502);
    env = stack[-3];
    goto v_5466;
    v_5502 = nil;
v_5466:
    if (v_5502 == nil) goto v_5464;
    goto v_5495;
v_5491:
    v_5502 = stack[0];
    v_5503 = ncons(v_5502);
    env = stack[-3];
    goto v_5492;
v_5493:
    v_5502 = stack[-2];
    goto v_5494;
v_5495:
    goto v_5491;
v_5492:
    goto v_5493;
v_5494:
    v_5502 = cons(v_5503, v_5502);
    env = stack[-3];
    stack[-2] = v_5502;
    goto v_5462;
v_5464:
v_5462:
    v_5502 = stack[-1];
    v_5502 = qcdr(v_5502);
    stack[-1] = v_5502;
    goto v_5450;
v_5449:
    v_5502 = stack[-2];
    return onevalue(v_5502);
}



// Code for aex_simplenullp

static LispObject CC_aex_simplenullp(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5448;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
// copy arguments values to proper place
    v_5448 = v_5442;
// end of prologue
    fn = elt(env, 1); // aex_ex
    v_5448 = (*qfn1(fn))(fn, v_5448);
    v_5448 = qcar(v_5448);
    v_5448 = (v_5448 == nil ? lisp_true : nil);
    return onevalue(v_5448);
}



// Code for ofsf_ordatp

static LispObject CC_ofsf_ordatp(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5485, v_5486, v_5487, v_5488, v_5489, v_5490;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5442,v_5443);
    }
// copy arguments values to proper place
    v_5489 = v_5443;
    v_5490 = v_5442;
// end of prologue
    v_5485 = v_5490;
    v_5485 = qcdr(v_5485);
    v_5485 = qcar(v_5485);
    v_5488 = v_5485;
    v_5485 = v_5489;
    v_5485 = qcdr(v_5485);
    v_5485 = qcar(v_5485);
    v_5487 = v_5485;
    goto v_5463;
v_5459:
    v_5486 = v_5488;
    goto v_5460;
v_5461:
    v_5485 = v_5487;
    goto v_5462;
v_5463:
    goto v_5459;
v_5460:
    goto v_5461;
v_5462:
    if (equal(v_5486, v_5485)) goto v_5458;
    goto v_5471;
v_5467:
    v_5485 = v_5488;
    goto v_5468;
v_5469:
    v_5486 = v_5487;
    goto v_5470;
v_5471:
    goto v_5467;
v_5468:
    goto v_5469;
v_5470:
    fn = elt(env, 1); // ordp
    v_5485 = (*qfn2(fn))(fn, v_5485, v_5486);
    v_5485 = (v_5485 == nil ? lisp_true : nil);
    goto v_5448;
v_5458:
    goto v_5480;
v_5476:
    v_5485 = v_5490;
    v_5485 = qcar(v_5485);
    goto v_5477;
v_5478:
    v_5486 = v_5489;
    v_5486 = qcar(v_5486);
    goto v_5479;
v_5480:
    goto v_5476;
v_5477:
    goto v_5478;
v_5479:
    {
        fn = elt(env, 2); // ofsf_ordrelp
        return (*qfn2(fn))(fn, v_5485, v_5486);
    }
v_5448:
    return onevalue(v_5485);
}



// Code for monommultiplybyvariable

static LispObject CC_monommultiplybyvariable(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5539, v_5540;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5442,v_5443);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_5443;
    stack[-2] = v_5442;
// end of prologue
    goto v_5452;
v_5448:
    v_5540 = stack[-2];
    goto v_5449;
v_5450:
    v_5539 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5451;
v_5452:
    goto v_5448;
v_5449:
    goto v_5450;
v_5451:
    v_5539 = *(LispObject *)((char *)v_5540 + (CELL-TAG_VECTOR) + (((intptr_t)v_5539-TAG_FIXNUM)/(16/CELL)));
    stack[-3] = v_5539;
v_5458:
    v_5539 = stack[-3];
    v_5539 = qcar(v_5539);
    if (v_5539 == nil) goto v_5461;
    goto v_5472;
v_5468:
    v_5539 = stack[-3];
    v_5540 = qcar(v_5539);
    goto v_5469;
v_5470:
    v_5539 = stack[-1];
    goto v_5471;
v_5472:
    goto v_5468;
v_5469:
    goto v_5470;
v_5471:
    v_5539 = (LispObject)greaterp2(v_5540, v_5539);
    v_5539 = v_5539 ? lisp_true : nil;
    env = stack[-4];
    if (v_5539 == nil) goto v_5461;
    goto v_5462;
v_5461:
    goto v_5457;
v_5462:
    v_5539 = stack[-3];
    v_5539 = qcdr(v_5539);
    stack[-3] = v_5539;
    goto v_5458;
v_5457:
    v_5539 = stack[-3];
    v_5539 = qcar(v_5539);
    if (v_5539 == nil) goto v_5482;
    goto v_5492;
v_5488:
    v_5539 = stack[-3];
    v_5540 = qcar(v_5539);
    goto v_5489;
v_5490:
    v_5539 = stack[-1];
    goto v_5491;
v_5492:
    goto v_5488;
v_5489:
    goto v_5490;
v_5491:
    if (equal(v_5540, v_5539)) goto v_5487;
    else goto v_5482;
v_5487:
    goto v_5483;
v_5482:
    goto v_5501;
v_5497:
    goto v_5507;
v_5503:
    stack[0] = stack[-3];
    goto v_5504;
v_5505:
    goto v_5514;
v_5510:
    v_5539 = stack[-3];
    v_5540 = qcar(v_5539);
    goto v_5511;
v_5512:
    v_5539 = stack[-3];
    v_5539 = qcdr(v_5539);
    goto v_5513;
v_5514:
    goto v_5510;
v_5511:
    goto v_5512;
v_5513:
    v_5539 = cons(v_5540, v_5539);
    env = stack[-4];
    goto v_5506;
v_5507:
    goto v_5503;
v_5504:
    goto v_5505;
v_5506:
    v_5540 = Lrplacd(nil, stack[0], v_5539);
    env = stack[-4];
    goto v_5498;
v_5499:
    v_5539 = stack[-1];
    goto v_5500;
v_5501:
    goto v_5497;
v_5498:
    goto v_5499;
v_5500:
    v_5539 = Lrplaca(nil, v_5540, v_5539);
    env = stack[-4];
    goto v_5526;
v_5520:
    stack[-1] = stack[-2];
    goto v_5521;
v_5522:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5523;
v_5524:
    goto v_5534;
v_5530:
    v_5540 = stack[-2];
    goto v_5531;
v_5532:
    v_5539 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5533;
v_5534:
    goto v_5530;
v_5531:
    goto v_5532;
v_5533:
    v_5539 = *(LispObject *)((char *)v_5540 + (CELL-TAG_VECTOR) + (((intptr_t)v_5539-TAG_FIXNUM)/(16/CELL)));
    v_5539 = add1(v_5539);
    goto v_5525;
v_5526:
    goto v_5520;
v_5521:
    goto v_5522;
v_5523:
    goto v_5524;
v_5525:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_5539;
    goto v_5481;
v_5483:
v_5481:
    v_5539 = nil;
    return onevalue(v_5539);
}



// Code for cl_varl1

static LispObject CC_cl_varl1(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5458, v_5459, v_5460, v_5461;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5458 = v_5442;
// end of prologue
    goto v_5453;
v_5445:
    v_5461 = v_5458;
    goto v_5446;
v_5447:
    v_5460 = nil;
    goto v_5448;
v_5449:
    v_5459 = nil;
    goto v_5450;
v_5451:
    v_5458 = nil;
    goto v_5452;
v_5453:
    goto v_5445;
v_5446:
    goto v_5447;
v_5448:
    goto v_5449;
v_5450:
    goto v_5451;
v_5452:
    {
        fn = elt(env, 1); // cl_varl2
        return (*qfnn(fn))(fn, 4, v_5461, v_5460, v_5459, v_5458);
    }
}



// Code for preptayexp

static LispObject CC_preptayexp(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5454, v_5455;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5455 = v_5442;
// end of prologue
    v_5454 = v_5455;
    if (!consp(v_5454)) goto v_5446;
    else goto v_5447;
v_5446:
    v_5454 = v_5455;
    goto v_5445;
v_5447:
    v_5454 = v_5455;
    {
        fn = elt(env, 1); // rnprep!:
        return (*qfn1(fn))(fn, v_5454);
    }
    v_5454 = nil;
v_5445:
    return onevalue(v_5454);
}



// Code for ibalp_atomp

static LispObject CC_ibalp_atomp(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5508, v_5509;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_5442;
// end of prologue
    goto v_5456;
v_5452:
    v_5509 = stack[0];
    goto v_5453;
v_5454:
    v_5508 = elt(env, 1); // true
    goto v_5455;
v_5456:
    goto v_5452;
v_5453:
    goto v_5454;
v_5455:
    if (v_5509 == v_5508) goto v_5450;
    else goto v_5451;
v_5450:
    v_5508 = lisp_true;
    goto v_5449;
v_5451:
    goto v_5466;
v_5462:
    v_5509 = stack[0];
    goto v_5463;
v_5464:
    v_5508 = elt(env, 2); // false
    goto v_5465;
v_5466:
    goto v_5462;
v_5463:
    goto v_5464;
v_5465:
    v_5508 = (v_5509 == v_5508 ? lisp_true : nil);
    goto v_5449;
    v_5508 = nil;
v_5449:
    if (v_5508 == nil) goto v_5447;
    v_5508 = lisp_true;
    goto v_5445;
v_5447:
    goto v_5481;
v_5477:
    v_5508 = stack[0];
    if (!consp(v_5508)) goto v_5484;
    else goto v_5485;
v_5484:
    v_5508 = stack[0];
    v_5509 = v_5508;
    goto v_5483;
v_5485:
    v_5508 = stack[0];
    v_5508 = qcar(v_5508);
    v_5509 = v_5508;
    goto v_5483;
    v_5509 = nil;
v_5483:
    goto v_5478;
v_5479:
    v_5508 = elt(env, 3); // equal
    goto v_5480;
v_5481:
    goto v_5477;
v_5478:
    goto v_5479;
v_5480:
    if (v_5509 == v_5508) goto v_5475;
    else goto v_5476;
v_5475:
    v_5508 = stack[0];
    fn = elt(env, 4); // ibalp_arg2l
    v_5508 = (*qfn1(fn))(fn, v_5508);
    env = stack[-1];
    if (symbolp(v_5508)) goto v_5496;
    v_5508 = nil;
    goto v_5494;
v_5496:
    v_5508 = stack[0];
    fn = elt(env, 5); // ibalp_arg2r
    v_5508 = (*qfn1(fn))(fn, v_5508);
    v_5508 = (is_number(v_5508) ? lisp_true : nil);
    goto v_5494;
    v_5508 = nil;
v_5494:
    goto v_5474;
v_5476:
    v_5508 = nil;
    goto v_5474;
    v_5508 = nil;
v_5474:
    goto v_5445;
    v_5508 = nil;
v_5445:
    return onevalue(v_5508);
}



// Code for off

static LispObject CC_off(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5462;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_5462 = v_5442;
// end of prologue
    stack[0] = v_5462;
v_5447:
    v_5462 = stack[0];
    if (v_5462 == nil) goto v_5451;
    else goto v_5452;
v_5451:
    v_5462 = nil;
    goto v_5446;
v_5452:
    v_5462 = stack[0];
    v_5462 = qcar(v_5462);
    fn = elt(env, 1); // off1
    v_5462 = (*qfn1(fn))(fn, v_5462);
    env = stack[-1];
    v_5462 = stack[0];
    v_5462 = qcdr(v_5462);
    stack[0] = v_5462;
    goto v_5447;
v_5446:
    return onevalue(v_5462);
}



// Code for id2bytelist

static LispObject CC_id2bytelist(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5447;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_5447 = v_5442;
// end of prologue
    fn = elt(env, 1); // id2string
    v_5447 = (*qfn1(fn))(fn, v_5447);
    env = stack[0];
    {
        fn = elt(env, 2); // string2bytelist
        return (*qfn1(fn))(fn, v_5447);
    }
}



// Code for !:difference

static LispObject CC_Tdifference(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5499, v_5500, v_5501, v_5502;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5501 = v_5443;
    v_5502 = v_5442;
// end of prologue
    v_5499 = v_5502;
    if (v_5499 == nil) goto v_5447;
    else goto v_5448;
v_5447:
    v_5499 = v_5501;
    {
        fn = elt(env, 2); // !:minus
        return (*qfn1(fn))(fn, v_5499);
    }
v_5448:
    v_5499 = v_5501;
    if (v_5499 == nil) goto v_5452;
    else goto v_5453;
v_5452:
    v_5499 = v_5502;
    goto v_5446;
v_5453:
    goto v_5462;
v_5458:
    v_5500 = v_5502;
    goto v_5459;
v_5460:
    v_5499 = v_5501;
    goto v_5461;
v_5462:
    goto v_5458;
v_5459:
    goto v_5460;
v_5461:
    if (equal(v_5500, v_5499)) goto v_5456;
    else goto v_5457;
v_5456:
    v_5499 = nil;
    goto v_5446;
v_5457:
    v_5499 = v_5502;
    if (!consp(v_5499)) goto v_5470;
    else goto v_5471;
v_5470:
    v_5499 = v_5501;
    v_5499 = (consp(v_5499) ? nil : lisp_true);
    goto v_5469;
v_5471:
    v_5499 = nil;
    goto v_5469;
    v_5499 = nil;
v_5469:
    if (v_5499 == nil) goto v_5467;
    goto v_5483;
v_5479:
    v_5499 = v_5502;
    goto v_5480;
v_5481:
    v_5500 = v_5501;
    goto v_5482;
v_5483:
    goto v_5479;
v_5480:
    goto v_5481;
v_5482:
    return difference2(v_5499, v_5500);
v_5467:
    goto v_5495;
v_5489:
    v_5500 = v_5502;
    goto v_5490;
v_5491:
    goto v_5492;
v_5493:
    v_5499 = elt(env, 1); // difference
    goto v_5494;
v_5495:
    goto v_5489;
v_5490:
    goto v_5491;
v_5492:
    goto v_5493;
v_5494:
    {
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(fn, 3, v_5500, v_5501, v_5499);
    }
    v_5499 = nil;
v_5446:
    return onevalue(v_5499);
}



// Code for scan

static LispObject CC_scan(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6336, v_6337, v_6338;
    LispObject fn;
    argcheck(nargs, 0, "scan");
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
    goto v_5471;
v_5467:
    v_6337 = qvalue(elt(env, 1)); // cursym!*
    goto v_5468;
v_5469:
    v_6336 = elt(env, 2); // !*semicol!*
    goto v_5470;
v_5471:
    goto v_5467;
v_5468:
    goto v_5469;
v_5470:
    if (v_6337 == v_6336) goto v_5466;
    goto v_5449;
v_5466:
v_5448:
    v_6336 = nil;
    qvalue(elt(env, 3)) = v_6336; // escaped!*
    fn = elt(env, 44); // token
    v_6336 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    qvalue(elt(env, 4)) = v_6336; // nxtsym!*
v_5449:
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    if (!consp(v_6336)) goto v_5483;
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    fn = elt(env, 45); // toknump
    v_6336 = (*qfn1(fn))(fn, v_6336);
    env = stack[-3];
    v_6336 = (v_6336 == nil ? lisp_true : nil);
    goto v_5481;
v_5483:
    v_6336 = nil;
    goto v_5481;
    v_6336 = nil;
v_5481:
    if (v_6336 == nil) goto v_5479;
    goto v_5460;
v_5479:
    goto v_5501;
v_5497:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5498;
v_5499:
    v_6336 = elt(env, 5); // else
    goto v_5500;
v_5501:
    goto v_5497;
v_5498:
    goto v_5499;
v_5500:
    if (v_6337 == v_6336) goto v_5495;
    else goto v_5496;
v_5495:
    v_6336 = lisp_true;
    goto v_5494;
v_5496:
    goto v_5511;
v_5507:
    v_6337 = qvalue(elt(env, 1)); // cursym!*
    goto v_5508;
v_5509:
    v_6336 = elt(env, 2); // !*semicol!*
    goto v_5510;
v_5511:
    goto v_5507;
v_5508:
    goto v_5509;
v_5510:
    v_6336 = (v_6337 == v_6336 ? lisp_true : nil);
    goto v_5494;
    v_6336 = nil;
v_5494:
    if (v_6336 == nil) goto v_5492;
    v_6336 = nil;
    qvalue(elt(env, 6)) = v_6336; // outl!*
    goto v_5477;
v_5492:
v_5477:
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    fn = elt(env, 46); // prin2x
    v_6336 = (*qfn1(fn))(fn, v_6336);
    env = stack[-3];
v_5450:
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    if (symbolp(v_6336)) goto v_5521;
    goto v_5461;
v_5521:
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    if (!symbolp(v_6336)) v_6336 = nil;
    else { v_6336 = qfastgets(v_6336);
           if (v_6336 != nil) { v_6336 = elt(v_6336, 28); // newnam
#ifdef RECORD_GET
             if (v_6336 != SPID_NOPROP)
                record_get(elt(fastget_names, 28), 1);
             else record_get(elt(fastget_names, 28), 0),
                v_6336 = nil; }
           else record_get(elt(fastget_names, 28), 0); }
#else
             if (v_6336 == SPID_NOPROP) v_6336 = nil; }}
#endif
    stack[-1] = v_6336;
    if (v_6336 == nil) goto v_5524;
    goto v_5533;
v_5529:
    v_6337 = stack[-1];
    goto v_5530;
v_5531:
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5532;
v_5533:
    goto v_5529;
v_5530:
    goto v_5531;
v_5532:
    if (equal(v_6337, v_6336)) goto v_5524;
    goto v_5459;
v_5524:
    goto v_5546;
v_5542:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5543;
v_5544:
    v_6336 = elt(env, 7); // comment
    goto v_5545;
v_5546:
    goto v_5542;
v_5543:
    goto v_5544;
v_5545:
    if (v_6337 == v_6336) goto v_5540;
    else goto v_5541;
v_5540:
    v_6336 = lisp_true;
    goto v_5539;
v_5541:
    goto v_5560;
v_5556:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5557;
v_5558:
    v_6336 = elt(env, 8); // !C!O!M!M!E!N!T
    goto v_5559;
v_5560:
    goto v_5556;
v_5557:
    goto v_5558;
v_5559:
    if (v_6337 == v_6336) goto v_5554;
    else goto v_5555;
v_5554:
    v_6336 = lisp_true;
    goto v_5553;
v_5555:
    goto v_5570;
v_5566:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5567;
v_5568:
    v_6336 = elt(env, 9); // !Comment
    goto v_5569;
v_5570:
    goto v_5566;
v_5567:
    goto v_5568;
v_5569:
    v_6336 = (v_6337 == v_6336 ? lisp_true : nil);
    goto v_5553;
    v_6336 = nil;
v_5553:
    goto v_5539;
    v_6336 = nil;
v_5539:
    if (v_6336 == nil) goto v_5537;
    v_6336 = elt(env, 7); // comment
    fn = elt(env, 47); // read!-comment1
    v_6336 = (*qfn1(fn))(fn, v_6336);
    env = stack[-3];
    stack[-1] = v_6336;
    v_6336 = qvalue(elt(env, 10)); // !*comment
    if (v_6336 == nil) goto v_5579;
    v_6336 = stack[-1];
    goto v_5447;
v_5579:
    goto v_5448;
    goto v_5519;
v_5537:
    goto v_5594;
v_5590:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5591;
v_5592:
    v_6336 = elt(env, 11); // !%
    goto v_5593;
v_5594:
    goto v_5590;
v_5591:
    goto v_5592;
v_5593:
    if (v_6337 == v_6336) goto v_5588;
    else goto v_5589;
v_5588:
    goto v_5601;
v_5597:
    v_6337 = qvalue(elt(env, 12)); // ttype!*
    goto v_5598;
v_5599:
    v_6336 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_5600;
v_5601:
    goto v_5597;
v_5598:
    goto v_5599;
v_5600:
    v_6336 = (v_6337 == v_6336 ? lisp_true : nil);
    goto v_5587;
v_5589:
    v_6336 = nil;
    goto v_5587;
    v_6336 = nil;
v_5587:
    if (v_6336 == nil) goto v_5585;
    v_6336 = elt(env, 13); // percent_comment
    fn = elt(env, 47); // read!-comment1
    v_6336 = (*qfn1(fn))(fn, v_6336);
    env = stack[-3];
    stack[-1] = v_6336;
    v_6336 = qvalue(elt(env, 10)); // !*comment
    if (v_6336 == nil) goto v_5613;
    v_6336 = stack[-1];
    goto v_5447;
v_5613:
    goto v_5448;
    goto v_5519;
v_5585:
    goto v_5624;
v_5620:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5621;
v_5622:
    v_6336 = elt(env, 14); // !#if
    goto v_5623;
v_5624:
    goto v_5620;
v_5621:
    goto v_5622;
v_5623:
    if (v_6337 == v_6336) goto v_5618;
    else goto v_5619;
v_5618:
    goto v_5456;
v_5619:
    goto v_5637;
v_5633:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5634;
v_5635:
    v_6336 = elt(env, 15); // !#else
    goto v_5636;
v_5637:
    goto v_5633;
v_5634:
    goto v_5635;
v_5636:
    if (v_6337 == v_6336) goto v_5631;
    else goto v_5632;
v_5631:
    v_6336 = lisp_true;
    goto v_5630;
v_5632:
    goto v_5647;
v_5643:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5644;
v_5645:
    v_6336 = elt(env, 16); // !#elif
    goto v_5646;
v_5647:
    goto v_5643;
v_5644:
    goto v_5645;
v_5646:
    v_6336 = (v_6337 == v_6336 ? lisp_true : nil);
    goto v_5630;
    v_6336 = nil;
v_5630:
    if (v_6336 == nil) goto v_5628;
    v_6336 = nil;
    stack[-2] = v_6336;
    stack[-1] = v_6336;
    qvalue(elt(env, 4)) = v_6336; // nxtsym!*
    goto v_5457;
v_5628:
    goto v_5658;
v_5654:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5655;
v_5656:
    v_6336 = elt(env, 17); // !#endif
    goto v_5657;
v_5658:
    goto v_5654;
v_5655:
    goto v_5656;
v_5657:
    if (v_6337 == v_6336) goto v_5652;
    else goto v_5653;
v_5652:
    goto v_5448;
v_5653:
    goto v_5667;
v_5663:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5664;
v_5665:
    v_6336 = elt(env, 18); // !#eval
    goto v_5666;
v_5667:
    goto v_5663;
v_5664:
    goto v_5665;
v_5666:
    if (v_6337 == v_6336) goto v_5661;
    else goto v_5662;
v_5661:
    goto v_5677;
v_5671:
    fn = elt(env, 48); // rread
    v_6338 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_5672;
v_5673:
    v_6337 = qvalue(elt(env, 19)); // !*backtrace
    goto v_5674;
v_5675:
    v_6336 = nil;
    goto v_5676;
v_5677:
    goto v_5671;
v_5672:
    goto v_5673;
v_5674:
    goto v_5675;
v_5676:
    fn = elt(env, 49); // errorset
    v_6336 = (*qfnn(fn))(fn, 3, v_6338, v_6337, v_6336);
    env = stack[-3];
    v_6336 = nil;
    qvalue(elt(env, 3)) = v_6336; // escaped!*
    qvalue(elt(env, 20)) = v_6336; // curescaped!*
    goto v_5448;
v_5662:
    goto v_5688;
v_5684:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5685;
v_5686:
    v_6336 = elt(env, 21); // !#define
    goto v_5687;
v_5688:
    goto v_5684;
v_5685:
    goto v_5686;
v_5687:
    if (v_6337 == v_6336) goto v_5682;
    else goto v_5683;
v_5682:
    goto v_5698;
v_5692:
    v_6338 = elt(env, 22); // (rread)
    goto v_5693;
v_5694:
    v_6337 = qvalue(elt(env, 19)); // !*backtrace
    goto v_5695;
v_5696:
    v_6336 = nil;
    goto v_5697;
v_5698:
    goto v_5692;
v_5693:
    goto v_5694;
v_5695:
    goto v_5696;
v_5697:
    fn = elt(env, 49); // errorset
    v_6336 = (*qfnn(fn))(fn, 3, v_6338, v_6337, v_6336);
    env = stack[-3];
    stack[-1] = v_6336;
    v_6336 = nil;
    qvalue(elt(env, 3)) = v_6336; // escaped!*
    qvalue(elt(env, 20)) = v_6336; // curescaped!*
    v_6336 = stack[-1];
    fn = elt(env, 50); // errorp
    v_6336 = (*qfn1(fn))(fn, v_6336);
    env = stack[-3];
    if (v_6336 == nil) goto v_5706;
    goto v_5448;
v_5706:
    goto v_5716;
v_5710:
    v_6338 = elt(env, 22); // (rread)
    goto v_5711;
v_5712:
    v_6337 = qvalue(elt(env, 19)); // !*backtrace
    goto v_5713;
v_5714:
    v_6336 = nil;
    goto v_5715;
v_5716:
    goto v_5710;
v_5711:
    goto v_5712;
v_5713:
    goto v_5714;
v_5715:
    fn = elt(env, 49); // errorset
    v_6336 = (*qfnn(fn))(fn, 3, v_6338, v_6337, v_6336);
    env = stack[-3];
    stack[0] = v_6336;
    v_6336 = nil;
    qvalue(elt(env, 3)) = v_6336; // escaped!*
    qvalue(elt(env, 20)) = v_6336; // curescaped!*
    v_6336 = stack[0];
    fn = elt(env, 50); // errorp
    v_6336 = (*qfn1(fn))(fn, v_6336);
    env = stack[-3];
    if (v_6336 == nil) goto v_5724;
    goto v_5448;
v_5724:
    goto v_5734;
v_5728:
    v_6336 = stack[-1];
    v_6338 = qcar(v_6336);
    goto v_5729;
v_5730:
    v_6337 = elt(env, 23); // newnam
    goto v_5731;
v_5732:
    v_6336 = stack[0];
    v_6336 = qcar(v_6336);
    goto v_5733;
v_5734:
    goto v_5728;
v_5729:
    goto v_5730;
v_5731:
    goto v_5732;
v_5733:
    v_6336 = Lputprop(nil, 3, v_6338, v_6337, v_6336);
    env = stack[-3];
    v_6336 = elt(env, 24); // "*** "
    v_6336 = Lprinc(nil, v_6336);
    env = stack[-3];
    v_6336 = stack[-1];
    v_6336 = qcar(v_6336);
    v_6336 = Lprin(nil, v_6336);
    env = stack[-3];
    v_6336 = elt(env, 25); // " => "
    v_6336 = Lprinc(nil, v_6336);
    env = stack[-3];
    v_6336 = stack[0];
    v_6336 = qcar(v_6336);
    v_6336 = Lprint(nil, v_6336);
    env = stack[-3];
    goto v_5448;
v_5683:
    goto v_5756;
v_5752:
    v_6337 = qvalue(elt(env, 12)); // ttype!*
    goto v_5753;
v_5754:
    v_6336 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_5755;
v_5756:
    goto v_5752;
v_5753:
    goto v_5754;
v_5755:
    if (v_6337 == v_6336) goto v_5751;
    goto v_5461;
v_5751:
    goto v_5765;
v_5761:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5762;
v_5763:
    v_6336 = qvalue(elt(env, 26)); // !$eof!$
    goto v_5764;
v_5765:
    goto v_5761;
v_5762:
    goto v_5763;
v_5764:
    if (v_6337 == v_6336) goto v_5759;
    else goto v_5760;
v_5759:
    {
        fn = elt(env, 51); // filenderr
        return (*qfnn(fn))(fn, 0);
    }
v_5760:
    goto v_5775;
v_5771:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5772;
v_5773:
    v_6336 = elt(env, 27); // !'
    goto v_5774;
v_5775:
    goto v_5771;
v_5772:
    goto v_5773;
v_5774:
    if (v_6337 == v_6336) goto v_5769;
    else goto v_5770;
v_5769:
    v_6336 = elt(env, 28); // "Invalid QUOTE"
    fn = elt(env, 52); // rederr
    v_6336 = (*qfn1(fn))(fn, v_6336);
    env = stack[-3];
    goto v_5519;
v_5770:
    v_6336 = qvalue(elt(env, 29)); // !*eoldelimp
    if (v_6336 == nil) goto v_5781;
    goto v_5789;
v_5785:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5786;
v_5787:
    v_6336 = qvalue(elt(env, 30)); // !$eol!$
    goto v_5788;
v_5789:
    goto v_5785;
v_5786:
    goto v_5787;
v_5788:
    if (v_6337 == v_6336) goto v_5784;
    else goto v_5781;
v_5784:
    goto v_5458;
v_5781:
    goto v_5802;
v_5798:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5799;
v_5800:
    v_6336 = elt(env, 31); // !#
    goto v_5801;
v_5802:
    goto v_5798;
v_5799:
    goto v_5800;
v_5801:
    if (v_6337 == v_6336) goto v_5796;
    else goto v_5797;
v_5796:
    v_6336 = qvalue(elt(env, 32)); // crchar!*
    v_6336 = Lwhitespace_char_p(nil, v_6336);
    env = stack[-3];
    v_6336 = (v_6336 == nil ? lisp_true : nil);
    goto v_5795;
v_5797:
    v_6336 = nil;
    goto v_5795;
    v_6336 = nil;
v_5795:
    if (v_6336 == nil) goto v_5793;
    goto v_5454;
v_5793:
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    if (!symbolp(v_6336)) v_6336 = nil;
    else { v_6336 = qfastgets(v_6336);
           if (v_6336 != nil) { v_6336 = elt(v_6336, 11); // switch!*
#ifdef RECORD_GET
             if (v_6336 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v_6336 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v_6336 == SPID_NOPROP) v_6336 = nil; }}
#endif
    stack[-1] = v_6336;
    if (v_6336 == nil) goto v_5811;
    else goto v_5812;
v_5811:
    goto v_5461;
v_5812:
    goto v_5822;
v_5818:
    v_6336 = stack[-1];
    v_6337 = qcdr(v_6336);
    goto v_5819;
v_5820:
    v_6336 = elt(env, 2); // !*semicol!*
    goto v_5821;
v_5822:
    goto v_5818;
v_5819:
    goto v_5820;
v_5821:
    if (!consp(v_6337)) goto v_5816;
    v_6337 = qcar(v_6337);
    if (v_6337 == v_6336) goto v_5815;
    else goto v_5816;
v_5815:
    goto v_5458;
v_5816:
v_5519:
    v_6336 = qvalue(elt(env, 32)); // crchar!*
    v_6336 = Lwhitespace_char_p(nil, v_6336);
    env = stack[-3];
    stack[-2] = v_6336;
v_5451:
    fn = elt(env, 44); // token
    v_6336 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    qvalue(elt(env, 4)) = v_6336; // nxtsym!*
    goto v_5837;
v_5833:
    v_6337 = qvalue(elt(env, 12)); // ttype!*
    goto v_5834;
v_5835:
    v_6336 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_5836;
v_5837:
    goto v_5833;
v_5834:
    goto v_5835;
v_5836:
    if (v_6337 == v_6336) goto v_5832;
    goto v_5452;
v_5832:
    goto v_5846;
v_5842:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5843;
v_5844:
    v_6336 = qvalue(elt(env, 26)); // !$eof!$
    goto v_5845;
v_5846:
    goto v_5842;
v_5843:
    goto v_5844;
v_5845:
    if (v_6337 == v_6336) goto v_5840;
    else goto v_5841;
v_5840:
    {
        fn = elt(env, 51); // filenderr
        return (*qfnn(fn))(fn, 0);
    }
v_5841:
    v_6336 = stack[-1];
    v_6336 = qcar(v_6336);
    if (v_6336 == nil) goto v_5851;
    goto v_5453;
v_5851:
v_5452:
    v_6336 = stack[-1];
    v_6336 = qcdr(v_6336);
    v_6336 = qcar(v_6336);
    qvalue(elt(env, 1)) = v_6336; // cursym!*
    v_6336 = nil;
    qvalue(elt(env, 20)) = v_6336; // curescaped!*
    goto v_5867;
v_5863:
    v_6337 = qvalue(elt(env, 1)); // cursym!*
    goto v_5864;
v_5865:
    v_6336 = elt(env, 33); // !*rpar!*
    goto v_5866;
v_5867:
    goto v_5863;
v_5864:
    goto v_5865;
v_5866:
    if (v_6337 == v_6336) goto v_5861;
    else goto v_5862;
v_5861:
    goto v_5462;
v_5862:
    v_6336 = qvalue(elt(env, 1)); // cursym!*
    {
        fn = elt(env, 53); // addcomment
        return (*qfn1(fn))(fn, v_6336);
    }
v_5453:
    v_6336 = stack[-2];
    if (v_6336 == nil) goto v_5878;
    else goto v_5876;
v_5878:
    goto v_5885;
v_5881:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5882;
v_5883:
    v_6336 = stack[-1];
    v_6336 = qcar(v_6336);
    goto v_5884;
v_5885:
    goto v_5881;
v_5882:
    goto v_5883;
v_5884:
    v_6336 = Latsoc(nil, v_6337, v_6336);
    stack[0] = v_6336;
    if (v_6336 == nil) goto v_5876;
    goto v_5877;
v_5876:
    goto v_5452;
v_5877:
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    fn = elt(env, 46); // prin2x
    v_6336 = (*qfn1(fn))(fn, v_6336);
    env = stack[-3];
    v_6336 = stack[0];
    v_6336 = qcdr(v_6336);
    stack[-1] = v_6336;
    v_6336 = stack[-1];
    v_6336 = qcar(v_6336);
    if (v_6336 == nil) goto v_5900;
    else goto v_5901;
v_5900:
    goto v_5908;
v_5904:
    v_6336 = stack[-1];
    v_6336 = qcdr(v_6336);
    v_6337 = qcar(v_6336);
    goto v_5905;
v_5906:
    v_6336 = elt(env, 34); // !*comment!*
    goto v_5907;
v_5908:
    goto v_5904;
v_5905:
    goto v_5906;
v_5907:
    v_6336 = (v_6337 == v_6336 ? lisp_true : nil);
    goto v_5899;
v_5901:
    v_6336 = nil;
    goto v_5899;
    v_6336 = nil;
v_5899:
    if (v_6336 == nil) goto v_5897;
    fn = elt(env, 54); // read!-comment
    v_6336 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    qvalue(elt(env, 35)) = v_6336; // comment!*
    goto v_5448;
v_5897:
    goto v_5451;
v_5454:
    v_6336 = nil;
    stack[-2] = v_6336;
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    if (!symbolp(v_6336)) v_6336 = nil;
    else { v_6336 = qfastgets(v_6336);
           if (v_6336 != nil) { v_6336 = elt(v_6336, 11); // switch!*
#ifdef RECORD_GET
             if (v_6336 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v_6336 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v_6336 == SPID_NOPROP) v_6336 = nil; }}
#endif
    stack[-1] = v_6336;
    fn = elt(env, 44); // token
    v_6336 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    qvalue(elt(env, 4)) = v_6336; // nxtsym!*
    goto v_5934;
v_5930:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5931;
v_5932:
    v_6336 = elt(env, 36); // if
    goto v_5933;
v_5934:
    goto v_5930;
v_5931:
    goto v_5932;
v_5933:
    if (v_6337 == v_6336) goto v_5928;
    else goto v_5929;
v_5928:
    v_6336 = lisp_true;
    goto v_5927;
v_5929:
    goto v_5948;
v_5944:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5945;
v_5946:
    v_6336 = elt(env, 5); // else
    goto v_5947;
v_5948:
    goto v_5944;
v_5945:
    goto v_5946;
v_5947:
    if (v_6337 == v_6336) goto v_5942;
    else goto v_5943;
v_5942:
    v_6336 = lisp_true;
    goto v_5941;
v_5943:
    goto v_5962;
v_5958:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5959;
v_5960:
    v_6336 = elt(env, 37); // elif
    goto v_5961;
v_5962:
    goto v_5958;
v_5959:
    goto v_5960;
v_5961:
    if (v_6337 == v_6336) goto v_5956;
    else goto v_5957;
v_5956:
    v_6336 = lisp_true;
    goto v_5955;
v_5957:
    goto v_5976;
v_5972:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5973;
v_5974:
    v_6336 = elt(env, 38); // endif
    goto v_5975;
v_5976:
    goto v_5972;
v_5973:
    goto v_5974;
v_5975:
    if (v_6337 == v_6336) goto v_5970;
    else goto v_5971;
v_5970:
    v_6336 = lisp_true;
    goto v_5969;
v_5971:
    goto v_5990;
v_5986:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5987;
v_5988:
    v_6336 = elt(env, 39); // eval
    goto v_5989;
v_5990:
    goto v_5986;
v_5987:
    goto v_5988;
v_5989:
    if (v_6337 == v_6336) goto v_5984;
    else goto v_5985;
v_5984:
    v_6336 = lisp_true;
    goto v_5983;
v_5985:
    goto v_6000;
v_5996:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_5997;
v_5998:
    v_6336 = elt(env, 40); // define
    goto v_5999;
v_6000:
    goto v_5996;
v_5997:
    goto v_5998;
v_5999:
    v_6336 = (v_6337 == v_6336 ? lisp_true : nil);
    goto v_5983;
    v_6336 = nil;
v_5983:
    goto v_5969;
    v_6336 = nil;
v_5969:
    goto v_5955;
    v_6336 = nil;
v_5955:
    goto v_5941;
    v_6336 = nil;
v_5941:
    goto v_5927;
    v_6336 = nil;
v_5927:
    if (v_6336 == nil) goto v_5925;
    goto v_5455;
v_5925:
    goto v_6012;
v_6008:
    v_6337 = qvalue(elt(env, 12)); // ttype!*
    goto v_6009;
v_6010:
    v_6336 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_6011;
v_6012:
    goto v_6008;
v_6009:
    goto v_6010;
v_6011:
    if (v_6337 == v_6336) goto v_6007;
    goto v_5452;
v_6007:
    goto v_6021;
v_6017:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_6018;
v_6019:
    v_6336 = qvalue(elt(env, 26)); // !$eof!$
    goto v_6020;
v_6021:
    goto v_6017;
v_6018:
    goto v_6019;
v_6020:
    if (v_6337 == v_6336) goto v_6015;
    else goto v_6016;
v_6015:
    {
        fn = elt(env, 51); // filenderr
        return (*qfnn(fn))(fn, 0);
    }
v_6016:
    v_6336 = stack[-1];
    v_6336 = qcar(v_6336);
    if (v_6336 == nil) goto v_6026;
    goto v_5453;
v_6026:
    goto v_5452;
v_5455:
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    fn = elt(env, 46); // prin2x
    v_6336 = (*qfn1(fn))(fn, v_6336);
    env = stack[-3];
    goto v_6038;
v_6034:
    stack[0] = elt(env, 31); // !#
    goto v_6035;
v_6036:
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    v_6336 = Lexplodec(nil, v_6336);
    env = stack[-3];
    goto v_6037;
v_6038:
    goto v_6034;
v_6035:
    goto v_6036;
v_6037:
    v_6336 = cons(stack[0], v_6336);
    env = stack[-3];
    fn = elt(env, 55); // list2string
    v_6336 = (*qfn1(fn))(fn, v_6336);
    env = stack[-3];
    v_6336 = Lintern(nil, v_6336);
    env = stack[-3];
    qvalue(elt(env, 4)) = v_6336; // nxtsym!*
    goto v_5450;
v_5456:
    goto v_6049;
v_6043:
    fn = elt(env, 48); // rread
    v_6338 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_6044;
v_6045:
    v_6337 = qvalue(elt(env, 19)); // !*backtrace
    goto v_6046;
v_6047:
    v_6336 = nil;
    goto v_6048;
v_6049:
    goto v_6043;
v_6044:
    goto v_6045;
v_6046:
    goto v_6047;
v_6048:
    fn = elt(env, 49); // errorset
    v_6336 = (*qfnn(fn))(fn, 3, v_6338, v_6337, v_6336);
    env = stack[-3];
    stack[-1] = v_6336;
    v_6336 = nil;
    qvalue(elt(env, 3)) = v_6336; // escaped!*
    qvalue(elt(env, 20)) = v_6336; // curescaped!*
    v_6336 = stack[-1];
    fn = elt(env, 50); // errorp
    v_6336 = (*qfn1(fn))(fn, v_6336);
    env = stack[-3];
    if (v_6336 == nil) goto v_6060;
    else goto v_6061;
v_6060:
    v_6336 = stack[-1];
    v_6336 = qcar(v_6336);
    goto v_6059;
v_6061:
    v_6336 = nil;
    goto v_6059;
    v_6336 = nil;
v_6059:
    if (v_6336 == nil) goto v_6057;
    goto v_5448;
v_6057:
    v_6336 = nil;
    stack[-1] = v_6336;
    v_6336 = lisp_true;
    stack[-2] = v_6336;
v_5457:
    goto v_6083;
v_6079:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_6080;
v_6081:
    v_6336 = elt(env, 31); // !#
    goto v_6082;
v_6083:
    goto v_6079;
v_6080:
    goto v_6081;
v_6082:
    if (v_6337 == v_6336) goto v_6077;
    else goto v_6078;
v_6077:
    goto v_6094;
v_6090:
    v_6337 = qvalue(elt(env, 12)); // ttype!*
    goto v_6091;
v_6092:
    v_6336 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_6093;
v_6094:
    goto v_6090;
v_6091:
    goto v_6092;
v_6093:
    if (v_6337 == v_6336) goto v_6088;
    else goto v_6089;
v_6088:
    v_6336 = qvalue(elt(env, 32)); // crchar!*
    v_6336 = Lwhitespace_char_p(nil, v_6336);
    env = stack[-3];
    v_6336 = (v_6336 == nil ? lisp_true : nil);
    goto v_6087;
v_6089:
    v_6336 = nil;
    goto v_6087;
    v_6336 = nil;
v_6087:
    goto v_6076;
v_6078:
    v_6336 = nil;
    goto v_6076;
    v_6336 = nil;
v_6076:
    if (v_6336 == nil) goto v_6074;
    fn = elt(env, 44); // token
    v_6336 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    qvalue(elt(env, 4)) = v_6336; // nxtsym!*
    goto v_6115;
v_6111:
    v_6337 = qvalue(elt(env, 12)); // ttype!*
    goto v_6112;
v_6113:
    v_6336 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6114;
v_6115:
    goto v_6111;
v_6112:
    goto v_6113;
v_6114:
    if (v_6337 == v_6336) goto v_6109;
    else goto v_6110;
v_6109:
    goto v_6125;
v_6121:
    stack[0] = elt(env, 31); // !#
    goto v_6122;
v_6123:
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    v_6336 = Lexplodec(nil, v_6336);
    env = stack[-3];
    goto v_6124;
v_6125:
    goto v_6121;
v_6122:
    goto v_6123;
v_6124:
    v_6336 = cons(stack[0], v_6336);
    env = stack[-3];
    fn = elt(env, 55); // list2string
    v_6336 = (*qfn1(fn))(fn, v_6336);
    env = stack[-3];
    v_6336 = Lintern(nil, v_6336);
    env = stack[-3];
    qvalue(elt(env, 4)) = v_6336; // nxtsym!*
    goto v_6108;
v_6110:
v_6108:
    goto v_6072;
v_6074:
v_6072:
    goto v_6137;
v_6133:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_6134;
v_6135:
    v_6336 = elt(env, 17); // !#endif
    goto v_6136;
v_6137:
    goto v_6133;
v_6134:
    goto v_6135;
v_6136:
    if (v_6337 == v_6336) goto v_6131;
    else goto v_6132;
v_6131:
    v_6336 = stack[-1];
    if (v_6336 == nil) goto v_6142;
    else goto v_6143;
v_6142:
    goto v_5448;
v_6143:
    v_6336 = stack[-1];
    v_6336 = qcdr(v_6336);
    stack[-1] = v_6336;
    goto v_6141;
v_6141:
    goto v_6130;
v_6132:
    goto v_6155;
v_6151:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_6152;
v_6153:
    v_6336 = elt(env, 14); // !#if
    goto v_6154;
v_6155:
    goto v_6151;
v_6152:
    goto v_6153;
v_6154:
    if (v_6337 == v_6336) goto v_6149;
    else goto v_6150;
v_6149:
    goto v_6163;
v_6159:
    v_6337 = nil;
    goto v_6160;
v_6161:
    v_6336 = stack[-1];
    goto v_6162;
v_6163:
    goto v_6159;
v_6160:
    goto v_6161;
v_6162:
    v_6336 = cons(v_6337, v_6336);
    env = stack[-3];
    stack[-1] = v_6336;
    goto v_6130;
v_6150:
    goto v_6176;
v_6172:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_6173;
v_6174:
    v_6336 = elt(env, 15); // !#else
    goto v_6175;
v_6176:
    goto v_6172;
v_6173:
    goto v_6174;
v_6175:
    if (v_6337 == v_6336) goto v_6170;
    else goto v_6171;
v_6170:
    v_6336 = stack[-1];
    if (v_6336 == nil) goto v_6181;
    else goto v_6182;
v_6181:
    v_6336 = stack[-2];
    goto v_6180;
v_6182:
    v_6336 = nil;
    goto v_6180;
    v_6336 = nil;
v_6180:
    goto v_6169;
v_6171:
    v_6336 = nil;
    goto v_6169;
    v_6336 = nil;
v_6169:
    if (v_6336 == nil) goto v_6167;
    goto v_5448;
v_6167:
    goto v_6201;
v_6197:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_6198;
v_6199:
    v_6336 = elt(env, 16); // !#elif
    goto v_6200;
v_6201:
    goto v_6197;
v_6198:
    goto v_6199;
v_6200:
    if (v_6337 == v_6336) goto v_6195;
    else goto v_6196;
v_6195:
    v_6336 = stack[-1];
    if (v_6336 == nil) goto v_6206;
    else goto v_6207;
v_6206:
    v_6336 = stack[-2];
    goto v_6205;
v_6207:
    v_6336 = nil;
    goto v_6205;
    v_6336 = nil;
v_6205:
    goto v_6194;
v_6196:
    v_6336 = nil;
    goto v_6194;
    v_6336 = nil;
v_6194:
    if (v_6336 == nil) goto v_6192;
    goto v_5456;
v_6192:
v_6130:
    fn = elt(env, 44); // token
    v_6336 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    qvalue(elt(env, 4)) = v_6336; // nxtsym!*
    goto v_6229;
v_6225:
    v_6337 = qvalue(elt(env, 12)); // ttype!*
    goto v_6226;
v_6227:
    v_6336 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_6228;
v_6229:
    goto v_6225;
v_6226:
    goto v_6227;
v_6228:
    if (v_6337 == v_6336) goto v_6223;
    else goto v_6224;
v_6223:
    goto v_6236;
v_6232:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_6233;
v_6234:
    v_6336 = qvalue(elt(env, 26)); // !$eof!$
    goto v_6235;
v_6236:
    goto v_6232;
v_6233:
    goto v_6234;
v_6235:
    v_6336 = (v_6337 == v_6336 ? lisp_true : nil);
    goto v_6222;
v_6224:
    v_6336 = nil;
    goto v_6222;
    v_6336 = nil;
v_6222:
    if (v_6336 == nil) goto v_6220;
    {
        fn = elt(env, 51); // filenderr
        return (*qfnn(fn))(fn, 0);
    }
v_6220:
    goto v_5457;
v_5458:
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    qvalue(elt(env, 41)) = v_6336; // semic!*
    v_6336 = nil;
    qvalue(elt(env, 20)) = v_6336; // curescaped!*
    v_6336 = elt(env, 2); // !*semicol!*
    {
        fn = elt(env, 53); // addcomment
        return (*qfn1(fn))(fn, v_6336);
    }
v_5459:
    v_6336 = stack[-1];
    qvalue(elt(env, 4)) = v_6336; // nxtsym!*
    v_6336 = stack[-1];
    v_6336 = Lstringp(nil, v_6336);
    env = stack[-3];
    if (v_6336 == nil) goto v_6254;
    goto v_5461;
v_6254:
    v_6336 = stack[-1];
    if (!consp(v_6336)) goto v_6257;
    else goto v_6258;
v_6257:
    goto v_5450;
v_6258:
    goto v_5461;
v_5460:
    goto v_6270;
v_6266:
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    v_6337 = qcar(v_6336);
    goto v_6267;
v_6268:
    v_6336 = elt(env, 42); // string
    goto v_6269;
v_6270:
    goto v_6266;
v_6267:
    goto v_6268;
v_6269:
    if (v_6337 == v_6336) goto v_6265;
    goto v_5461;
v_6265:
    v_6336 = elt(env, 43); // " "
    fn = elt(env, 46); // prin2x
    v_6336 = (*qfn1(fn))(fn, v_6336);
    env = stack[-3];
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    v_6336 = qcdr(v_6336);
    v_6336 = qcar(v_6336);
    v_6336 = Lmkquote(nil, v_6336);
    env = stack[-3];
    qvalue(elt(env, 4)) = v_6336; // nxtsym!*
    v_6336 = qcdr(v_6336);
    v_6336 = qcar(v_6336);
    fn = elt(env, 46); // prin2x
    v_6336 = (*qfn1(fn))(fn, v_6336);
    env = stack[-3];
v_5461:
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    qvalue(elt(env, 1)) = v_6336; // cursym!*
    v_6336 = qvalue(elt(env, 3)); // escaped!*
    qvalue(elt(env, 20)) = v_6336; // curescaped!*
    v_6336 = nil;
    qvalue(elt(env, 3)) = v_6336; // escaped!*
    fn = elt(env, 44); // token
    v_6336 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    qvalue(elt(env, 4)) = v_6336; // nxtsym!*
    goto v_6299;
v_6295:
    v_6337 = qvalue(elt(env, 4)); // nxtsym!*
    goto v_6296;
v_6297:
    v_6336 = qvalue(elt(env, 26)); // !$eof!$
    goto v_6298;
v_6299:
    goto v_6295;
v_6296:
    goto v_6297;
v_6298:
    if (v_6337 == v_6336) goto v_6293;
    else goto v_6294;
v_6293:
    goto v_6306;
v_6302:
    v_6337 = qvalue(elt(env, 12)); // ttype!*
    goto v_6303;
v_6304:
    v_6336 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_6305;
v_6306:
    goto v_6302;
v_6303:
    goto v_6304;
v_6305:
    v_6336 = (v_6337 == v_6336 ? lisp_true : nil);
    goto v_6292;
v_6294:
    v_6336 = nil;
    goto v_6292;
    v_6336 = nil;
v_6292:
    if (v_6336 == nil) goto v_6290;
    {
        fn = elt(env, 51); // filenderr
        return (*qfnn(fn))(fn, 0);
    }
v_6290:
v_5462:
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    if (is_number(v_6336)) goto v_6316;
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    if (!consp(v_6336)) goto v_6323;
    else goto v_6324;
v_6323:
    v_6336 = qvalue(elt(env, 4)); // nxtsym!*
    if (!symbolp(v_6336)) v_6336 = nil;
    else { v_6336 = qfastgets(v_6336);
           if (v_6336 != nil) { v_6336 = elt(v_6336, 11); // switch!*
#ifdef RECORD_GET
             if (v_6336 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v_6336 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v_6336 == SPID_NOPROP) v_6336 = nil; }}
#endif
    v_6336 = (v_6336 == nil ? lisp_true : nil);
    goto v_6322;
v_6324:
    v_6336 = nil;
    goto v_6322;
    v_6336 = nil;
v_6322:
    if (v_6336 == nil) goto v_6320;
    else goto v_6316;
v_6320:
    goto v_6317;
v_6316:
    v_6336 = elt(env, 43); // " "
    fn = elt(env, 46); // prin2x
    v_6336 = (*qfn1(fn))(fn, v_6336);
    env = stack[-3];
    goto v_6315;
v_6317:
v_6315:
    v_6336 = qvalue(elt(env, 1)); // cursym!*
    {
        fn = elt(env, 53); // addcomment
        return (*qfn1(fn))(fn, v_6336);
    }
v_5447:
    return onevalue(v_6336);
}



// Code for listtest

static LispObject CC_listtest(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_5484, v_5485, v_5486;
    LispObject v_5444, v_5443, v_5442;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "listtest");
    va_start(aa, nargs);
    v_5442 = va_arg(aa, LispObject);
    v_5443 = va_arg(aa, LispObject);
    v_5444 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_5444,v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_5442,v_5443,v_5444);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_5444;
    stack[-1] = v_5443;
    stack[-2] = v_5442;
// end of prologue
v_5448:
    v_5484 = stack[-2];
    if (v_5484 == nil) goto v_5451;
    else goto v_5452;
v_5451:
    v_5484 = nil;
    goto v_5447;
v_5452:
    goto v_5464;
v_5458:
    v_5486 = stack[0];
    goto v_5459;
v_5460:
    v_5484 = stack[-2];
    v_5485 = qcar(v_5484);
    goto v_5461;
v_5462:
    v_5484 = stack[-1];
    goto v_5463;
v_5464:
    goto v_5458;
v_5459:
    goto v_5460;
v_5461:
    goto v_5462;
v_5463:
    v_5484 = Lapply2(nil, 3, v_5486, v_5485, v_5484);
    env = stack[-3];
    if (v_5484 == nil) goto v_5456;
    v_5484 = stack[-2];
    v_5484 = qcar(v_5484);
    if (v_5484 == nil) goto v_5471;
    else goto v_5472;
v_5471:
    v_5484 = lisp_true;
    goto v_5447;
v_5472:
    v_5484 = stack[-2];
    v_5484 = qcar(v_5484);
    goto v_5447;
    goto v_5450;
v_5456:
    v_5484 = stack[-2];
    v_5484 = qcdr(v_5484);
    stack[-2] = v_5484;
    goto v_5448;
v_5450:
    v_5484 = nil;
v_5447:
    return onevalue(v_5484);
}



// Code for pv_neg

static LispObject CC_pv_neg(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5477, v_5478, v_5479;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5442;
// end of prologue
    stack[-1] = nil;
v_5449:
    v_5477 = stack[0];
    if (v_5477 == nil) goto v_5452;
    else goto v_5453;
v_5452:
    goto v_5448;
v_5453:
    goto v_5463;
v_5457:
    v_5477 = stack[0];
    v_5477 = qcar(v_5477);
    v_5477 = qcar(v_5477);
    v_5479 = negate(v_5477);
    env = stack[-2];
    goto v_5458;
v_5459:
    v_5477 = stack[0];
    v_5477 = qcar(v_5477);
    v_5478 = qcdr(v_5477);
    goto v_5460;
v_5461:
    v_5477 = stack[-1];
    goto v_5462;
v_5463:
    goto v_5457;
v_5458:
    goto v_5459;
v_5460:
    goto v_5461;
v_5462:
    v_5477 = acons(v_5479, v_5478, v_5477);
    env = stack[-2];
    stack[-1] = v_5477;
    v_5477 = stack[0];
    v_5477 = qcdr(v_5477);
    stack[0] = v_5477;
    goto v_5449;
v_5448:
    v_5477 = stack[-1];
        return Lnreverse(nil, v_5477);
    return onevalue(v_5477);
}



// Code for arintequiv!:

static LispObject CC_arintequivT(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5488, v_5489, v_5490;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5489 = v_5442;
// end of prologue
    v_5488 = v_5489;
    v_5488 = qcdr(v_5488);
    if (is_number(v_5488)) goto v_5446;
    else goto v_5447;
v_5446:
    v_5488 = v_5489;
    v_5488 = qcdr(v_5488);
    goto v_5445;
v_5447:
    goto v_5462;
v_5458:
    v_5488 = v_5489;
    v_5488 = qcdr(v_5488);
    v_5488 = qcar(v_5488);
    goto v_5459;
v_5460:
    v_5490 = elt(env, 1); // !:rn!:
    goto v_5461;
v_5462:
    goto v_5458;
v_5459:
    goto v_5460;
v_5461:
    if (v_5488 == v_5490) goto v_5456;
    else goto v_5457;
v_5456:
    goto v_5471;
v_5467:
    v_5488 = v_5489;
    v_5488 = qcdr(v_5488);
    v_5488 = qcdr(v_5488);
    v_5490 = qcdr(v_5488);
    goto v_5468;
v_5469:
    v_5488 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5470;
v_5471:
    goto v_5467;
v_5468:
    goto v_5469;
v_5470:
    v_5488 = (v_5490 == v_5488 ? lisp_true : nil);
    goto v_5455;
v_5457:
    v_5488 = nil;
    goto v_5455;
    v_5488 = nil;
v_5455:
    if (v_5488 == nil) goto v_5453;
    v_5488 = v_5489;
    v_5488 = qcdr(v_5488);
    v_5488 = qcdr(v_5488);
    v_5488 = qcar(v_5488);
    goto v_5445;
v_5453:
    v_5488 = nil;
    goto v_5445;
    v_5488 = nil;
v_5445:
    return onevalue(v_5488);
}



// Code for lalr_prin_nonterminal

static LispObject CC_lalr_prin_nonterminal(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5470, v_5471;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_5470 = v_5442;
// end of prologue
    goto v_5454;
v_5450:
    v_5471 = v_5470;
    goto v_5451;
v_5452:
    v_5470 = qvalue(elt(env, 1)); // nonterminal_codes
    goto v_5453;
v_5454:
    goto v_5450;
v_5451:
    goto v_5452;
v_5453:
    fn = elt(env, 2); // cdrassoc
    v_5470 = (*qfn2(fn))(fn, v_5471, v_5470);
    env = stack[-1];
    fn = elt(env, 3); // explode2uc
    v_5470 = (*qfn1(fn))(fn, v_5470);
    env = stack[-1];
    stack[0] = v_5470;
v_5447:
    v_5470 = stack[0];
    if (v_5470 == nil) goto v_5459;
    else goto v_5460;
v_5459:
    v_5470 = nil;
    goto v_5446;
v_5460:
    v_5470 = stack[0];
    v_5470 = qcar(v_5470);
    v_5470 = Lprinc(nil, v_5470);
    env = stack[-1];
    v_5470 = stack[0];
    v_5470 = qcdr(v_5470);
    stack[0] = v_5470;
    goto v_5447;
v_5446:
    return onevalue(v_5470);
}



// Code for remflagss

static LispObject CC_remflagss(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5469, v_5470, v_5471, v_5472;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5442,v_5443);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_5469 = v_5443;
    v_5471 = v_5442;
// end of prologue
    v_5472 = v_5469;
v_5448:
    v_5469 = v_5472;
    if (v_5469 == nil) goto v_5452;
    else goto v_5453;
v_5452:
    v_5469 = nil;
    goto v_5447;
v_5453:
    v_5469 = v_5472;
    v_5469 = qcar(v_5469);
    goto v_5464;
v_5460:
    v_5470 = v_5471;
    goto v_5461;
v_5462:
    goto v_5463;
v_5464:
    goto v_5460;
v_5461:
    goto v_5462;
v_5463:
    v_5469 = Lremflag(nil, v_5470, v_5469);
    env = stack[0];
    v_5469 = v_5472;
    v_5469 = qcdr(v_5469);
    v_5472 = v_5469;
    goto v_5448;
v_5447:
    return onevalue(v_5469);
}



// Code for ordpa

static LispObject CC_ordpa(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5453, v_5454;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5453 = v_5443;
    v_5454 = v_5442;
// end of prologue
    goto v_5450;
v_5446:
    goto v_5447;
v_5448:
    goto v_5449;
v_5450:
    goto v_5446;
v_5447:
    goto v_5448;
v_5449:
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_5454, v_5453);
    }
}



// Code for qqe_number!-of!-tails!-in!-qterm

static LispObject CC_qqe_numberKofKtailsKinKqterm(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5472, v_5473;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_5442;
// end of prologue
v_5446:
    v_5472 = stack[0];
    if (!consp(v_5472)) goto v_5449;
    else goto v_5450;
v_5449:
    v_5472 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5445;
v_5450:
    goto v_5459;
v_5455:
    v_5472 = stack[0];
    fn = elt(env, 2); // qqe_op
    v_5473 = (*qfn1(fn))(fn, v_5472);
    env = stack[-1];
    goto v_5456;
v_5457:
    v_5472 = elt(env, 1); // (ladd radd)
    goto v_5458;
v_5459:
    goto v_5455;
v_5456:
    goto v_5457;
v_5458:
    v_5472 = Lmemq(nil, v_5473, v_5472);
    if (v_5472 == nil) goto v_5454;
    v_5472 = stack[0];
    fn = elt(env, 3); // qqe_arg2r
    v_5472 = (*qfn1(fn))(fn, v_5472);
    env = stack[-1];
    stack[0] = v_5472;
    goto v_5446;
v_5454:
    v_5472 = stack[0];
    fn = elt(env, 4); // qqe_arg2l
    v_5472 = (*qfn1(fn))(fn, v_5472);
    env = stack[-1];
    v_5472 = CC_qqe_numberKofKtailsKinKqterm(elt(env, 0), v_5472);
    return add1(v_5472);
    v_5472 = nil;
v_5445:
    return onevalue(v_5472);
}



// Code for lastnondomain

static LispObject CC_lastnondomain(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5491, v_5492;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_5491 = v_5442;
// end of prologue
v_5446:
    v_5492 = v_5491;
    if (!consp(v_5492)) goto v_5453;
    else goto v_5454;
v_5453:
    v_5492 = lisp_true;
    goto v_5452;
v_5454:
    v_5492 = v_5491;
    v_5492 = qcar(v_5492);
    v_5492 = (consp(v_5492) ? nil : lisp_true);
    goto v_5452;
    v_5492 = nil;
v_5452:
    if (v_5492 == nil) goto v_5450;
    goto v_5468;
v_5464:
    v_5492 = elt(env, 1); // "non-domain"
    goto v_5465;
v_5466:
    goto v_5467;
v_5468:
    goto v_5464;
v_5465:
    goto v_5466;
v_5467:
    v_5491 = list2(v_5492, v_5491);
    env = stack[0];
    {
        fn = elt(env, 2); // errach
        return (*qfn1(fn))(fn, v_5491);
    }
v_5450:
    v_5492 = v_5491;
    v_5492 = qcdr(v_5492);
    if (!consp(v_5492)) goto v_5475;
    else goto v_5476;
v_5475:
    v_5492 = lisp_true;
    goto v_5474;
v_5476:
    v_5492 = v_5491;
    v_5492 = qcdr(v_5492);
    v_5492 = qcar(v_5492);
    v_5492 = (consp(v_5492) ? nil : lisp_true);
    goto v_5474;
    v_5492 = nil;
v_5474:
    if (v_5492 == nil) goto v_5472;
    goto v_5445;
v_5472:
    v_5491 = qcdr(v_5491);
    goto v_5446;
    v_5491 = nil;
v_5445:
    return onevalue(v_5491);
}



// Code for ibalp_vmember

static LispObject CC_ibalp_vmember(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5474, v_5475;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5442,v_5443);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5443;
    stack[-1] = v_5442;
// end of prologue
v_5441:
    v_5474 = stack[0];
    if (v_5474 == nil) goto v_5447;
    else goto v_5448;
v_5447:
    v_5474 = nil;
    goto v_5446;
v_5448:
    goto v_5461;
v_5457:
    v_5475 = stack[-1];
    goto v_5458;
v_5459:
    v_5474 = stack[0];
    v_5474 = qcar(v_5474);
    goto v_5460;
v_5461:
    goto v_5457;
v_5458:
    goto v_5459;
v_5460:
    fn = elt(env, 1); // ibalp_vequal
    v_5474 = (*qfn2(fn))(fn, v_5475, v_5474);
    env = stack[-2];
    if (v_5474 == nil) goto v_5455;
    else goto v_5454;
v_5455:
    goto v_5470;
v_5466:
    v_5475 = stack[-1];
    goto v_5467;
v_5468:
    v_5474 = stack[0];
    v_5474 = qcdr(v_5474);
    goto v_5469;
v_5470:
    goto v_5466;
v_5467:
    goto v_5468;
v_5469:
    stack[-1] = v_5475;
    stack[0] = v_5474;
    goto v_5441;
v_5454:
    goto v_5446;
    v_5474 = nil;
v_5446:
    return onevalue(v_5474);
}



// Code for basicom

static LispObject CC_basicom(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5472;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_5442;
// end of prologue
    v_5472 = stack[0];
    if (is_number(v_5472)) goto v_5448;
    else goto v_5449;
v_5448:
    v_5472 = stack[0];
    v_5472 = integerp(v_5472);
    if (v_5472 == nil) goto v_5454;
    v_5472 = stack[0];
    fn = elt(env, 1); // integerom
    v_5472 = (*qfn1(fn))(fn, v_5472);
    env = stack[-1];
    goto v_5452;
v_5454:
v_5452:
    v_5472 = stack[0];
    v_5472 = Lfloatp(nil, v_5472);
    env = stack[-1];
    if (v_5472 == nil) goto v_5462;
    v_5472 = stack[0];
    fn = elt(env, 2); // floatom
    v_5472 = (*qfn1(fn))(fn, v_5472);
    goto v_5460;
v_5462:
v_5460:
    goto v_5447;
v_5449:
    v_5472 = stack[0];
    if (symbolp(v_5472)) goto v_5467;
    else goto v_5468;
v_5467:
    v_5472 = stack[0];
    fn = elt(env, 3); // variableom
    v_5472 = (*qfn1(fn))(fn, v_5472);
    goto v_5447;
v_5468:
v_5447:
    v_5472 = nil;
    return onevalue(v_5472);
}



// Code for dfn_prop

static LispObject CC_dfn_prop(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5490, v_5491, v_5492;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_5490 = v_5442;
// end of prologue
    v_5490 = qcdr(v_5490);
    v_5490 = Llength(nil, v_5490);
    env = stack[0];
    v_5492 = v_5490;
    goto v_5456;
v_5452:
    v_5491 = v_5492;
    goto v_5453;
v_5454:
    v_5490 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5455;
v_5456:
    goto v_5452;
v_5453:
    goto v_5454;
v_5455:
    if (v_5491 == v_5490) goto v_5450;
    else goto v_5451;
v_5450:
    v_5490 = elt(env, 1); // dfn
    goto v_5449;
v_5451:
    goto v_5466;
v_5462:
    v_5491 = v_5492;
    goto v_5463;
v_5464:
    v_5490 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_5465;
v_5466:
    goto v_5462;
v_5463:
    goto v_5464;
v_5465:
    if (v_5491 == v_5490) goto v_5460;
    else goto v_5461;
v_5460:
    v_5490 = elt(env, 2); // dfn2
    goto v_5449;
v_5461:
    goto v_5476;
v_5472:
    v_5491 = v_5492;
    goto v_5473;
v_5474:
    v_5490 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_5475;
v_5476:
    goto v_5472;
v_5473:
    goto v_5474;
v_5475:
    if (v_5491 == v_5490) goto v_5470;
    else goto v_5471;
v_5470:
    v_5490 = elt(env, 3); // dfn3
    goto v_5449;
v_5471:
    goto v_5487;
v_5483:
    v_5490 = elt(env, 1); // dfn
    goto v_5484;
v_5485:
    v_5491 = v_5492;
    goto v_5486;
v_5487:
    goto v_5483;
v_5484:
    goto v_5485;
v_5486:
    {
        fn = elt(env, 4); // mkid
        return (*qfn2(fn))(fn, v_5490, v_5491);
    }
    v_5490 = nil;
v_5449:
    return onevalue(v_5490);
}



// Code for initwght

static LispObject CC_initwght(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5574, v_5575;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_5442;
// end of prologue
    v_5574 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_5574;
    stack[0] = v_5574;
    goto v_5457;
v_5453:
    goto v_5462;
v_5458:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_5459;
v_5460:
    goto v_5469;
v_5465:
    v_5575 = qvalue(elt(env, 2)); // maxvar
    goto v_5466;
v_5467:
    v_5574 = stack[-3];
    goto v_5468;
v_5469:
    goto v_5465;
v_5466:
    goto v_5467;
v_5468:
    v_5574 = plus2(v_5575, v_5574);
    env = stack[-6];
    goto v_5461;
v_5462:
    goto v_5458;
v_5459:
    goto v_5460;
v_5461:
    v_5575 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_5574-TAG_FIXNUM)/(16/CELL)));
    goto v_5454;
v_5455:
    v_5574 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_5456;
v_5457:
    goto v_5453;
v_5454:
    goto v_5455;
v_5456:
    v_5574 = *(LispObject *)((char *)v_5575 + (CELL-TAG_VECTOR) + (((intptr_t)v_5574-TAG_FIXNUM)/(16/CELL)));
    stack[-4] = v_5574;
v_5452:
    v_5574 = stack[-4];
    if (v_5574 == nil) goto v_5477;
    else goto v_5478;
v_5477:
    goto v_5451;
v_5478:
    v_5574 = stack[-4];
    v_5574 = qcar(v_5574);
    stack[-2] = v_5574;
    goto v_5492;
v_5488:
    goto v_5497;
v_5493:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_5494;
v_5495:
    goto v_5504;
v_5500:
    v_5575 = qvalue(elt(env, 2)); // maxvar
    goto v_5501;
v_5502:
    v_5574 = stack[-2];
    v_5574 = qcar(v_5574);
    goto v_5503;
v_5504:
    goto v_5500;
v_5501:
    goto v_5502;
v_5503:
    v_5574 = plus2(v_5575, v_5574);
    env = stack[-6];
    goto v_5496;
v_5497:
    goto v_5493;
v_5494:
    goto v_5495;
v_5496:
    v_5575 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_5574-TAG_FIXNUM)/(16/CELL)));
    goto v_5489;
v_5490:
    v_5574 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5491;
v_5492:
    goto v_5488;
v_5489:
    goto v_5490;
v_5491:
    v_5574 = *(LispObject *)((char *)v_5575 + (CELL-TAG_VECTOR) + (((intptr_t)v_5574-TAG_FIXNUM)/(16/CELL)));
    if (v_5574 == nil) goto v_5487;
    v_5574 = stack[-2];
    v_5574 = qcdr(v_5574);
    v_5574 = qcar(v_5574);
    fn = elt(env, 3); // dm!-abs
    v_5574 = (*qfn1(fn))(fn, v_5574);
    env = stack[-6];
    fn = elt(env, 4); // !:onep
    v_5574 = (*qfn1(fn))(fn, v_5574);
    env = stack[-6];
    if (v_5574 == nil) goto v_5513;
    else goto v_5514;
v_5513:
    v_5574 = stack[-5];
    v_5574 = add1(v_5574);
    env = stack[-6];
    stack[-5] = v_5574;
    goto v_5512;
v_5514:
v_5512:
    v_5574 = stack[0];
    v_5574 = add1(v_5574);
    env = stack[-6];
    stack[0] = v_5574;
    goto v_5485;
v_5487:
v_5485:
    v_5574 = stack[-4];
    v_5574 = qcdr(v_5574);
    stack[-4] = v_5574;
    goto v_5452;
v_5451:
    goto v_5532;
v_5526:
    goto v_5537;
v_5533:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_5534;
v_5535:
    goto v_5544;
v_5540:
    v_5575 = qvalue(elt(env, 2)); // maxvar
    goto v_5541;
v_5542:
    v_5574 = stack[-3];
    goto v_5543;
v_5544:
    goto v_5540;
v_5541:
    goto v_5542;
v_5543:
    v_5574 = plus2(v_5575, v_5574);
    env = stack[-6];
    goto v_5536;
v_5537:
    goto v_5533;
v_5534:
    goto v_5535;
v_5536:
    stack[-4] = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_5574-TAG_FIXNUM)/(16/CELL)));
    goto v_5527;
v_5528:
    stack[-3] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5529;
v_5530:
    goto v_5556;
v_5550:
    stack[-2] = stack[0];
    goto v_5551;
v_5552:
    stack[-1] = stack[-5];
    goto v_5553;
v_5554:
    goto v_5564;
v_5560:
    goto v_5561;
v_5562:
    goto v_5571;
v_5567:
    v_5575 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_5568;
v_5569:
    v_5574 = stack[-5];
    goto v_5570;
v_5571:
    goto v_5567;
v_5568:
    goto v_5569;
v_5570:
    v_5574 = times2(v_5575, v_5574);
    env = stack[-6];
    goto v_5563;
v_5564:
    goto v_5560;
v_5561:
    goto v_5562;
v_5563:
    v_5574 = plus2(stack[0], v_5574);
    env = stack[-6];
    goto v_5555;
v_5556:
    goto v_5550;
v_5551:
    goto v_5552;
v_5553:
    goto v_5554;
v_5555:
    v_5574 = acons(stack[-2], stack[-1], v_5574);
    goto v_5531;
v_5532:
    goto v_5526;
v_5527:
    goto v_5528;
v_5529:
    goto v_5530;
v_5531:
    *(LispObject *)((char *)stack[-4] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-3]-TAG_FIXNUM)/(16/CELL))) = v_5574;
    v_5574 = nil;
    return onevalue(v_5574);
}



// Code for vdplength

static LispObject CC_vdplength(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5450;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5450 = v_5442;
// end of prologue
    v_5450 = qcdr(v_5450);
    v_5450 = qcdr(v_5450);
    v_5450 = qcdr(v_5450);
    v_5450 = qcar(v_5450);
    {
        fn = elt(env, 1); // diplength
        return (*qfn1(fn))(fn, v_5450);
    }
}



// Code for plus!:

static LispObject CC_plusT(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5579, v_5580, v_5581, v_5582;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5442,v_5443);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_5581 = v_5443;
    v_5582 = v_5442;
// end of prologue
    goto v_5460;
v_5456:
    v_5579 = v_5582;
    v_5579 = qcdr(v_5579);
    v_5580 = qcar(v_5579);
    stack[-1] = v_5580;
    goto v_5457;
v_5458:
    v_5579 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5459;
v_5460:
    goto v_5456;
v_5457:
    goto v_5458;
v_5459:
    if (v_5580 == v_5579) goto v_5454;
    else goto v_5455;
v_5454:
    v_5579 = v_5581;
    goto v_5453;
v_5455:
    goto v_5472;
v_5468:
    v_5579 = v_5581;
    v_5579 = qcdr(v_5579);
    v_5580 = qcar(v_5579);
    stack[0] = v_5580;
    goto v_5469;
v_5470:
    v_5579 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5471;
v_5472:
    goto v_5468;
v_5469:
    goto v_5470;
v_5471:
    if (v_5580 == v_5579) goto v_5466;
    else goto v_5467;
v_5466:
    v_5579 = v_5582;
    goto v_5453;
v_5467:
    goto v_5484;
v_5480:
    goto v_5490;
v_5486:
    v_5579 = v_5582;
    v_5579 = qcdr(v_5579);
    v_5579 = qcdr(v_5579);
    stack[-4] = v_5579;
    goto v_5487;
v_5488:
    v_5580 = v_5581;
    v_5580 = qcdr(v_5580);
    v_5580 = qcdr(v_5580);
    stack[-2] = v_5580;
    goto v_5489;
v_5490:
    goto v_5486;
v_5487:
    goto v_5488;
v_5489:
    v_5580 = difference2(v_5579, v_5580);
    env = stack[-5];
    stack[-3] = v_5580;
    goto v_5481;
v_5482:
    v_5579 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5483;
v_5484:
    goto v_5480;
v_5481:
    goto v_5482;
v_5483:
    if (v_5580 == v_5579) goto v_5478;
    else goto v_5479;
v_5478:
    goto v_5505;
v_5499:
    stack[-2] = elt(env, 1); // !:rd!:
    goto v_5500;
v_5501:
    goto v_5512;
v_5508:
    v_5580 = stack[-1];
    goto v_5509;
v_5510:
    v_5579 = stack[0];
    goto v_5511;
v_5512:
    goto v_5508;
v_5509:
    goto v_5510;
v_5511:
    v_5580 = plus2(v_5580, v_5579);
    goto v_5502;
v_5503:
    v_5579 = stack[-4];
    goto v_5504;
v_5505:
    goto v_5499;
v_5500:
    goto v_5501;
v_5502:
    goto v_5503;
v_5504:
    {
        LispObject v_5588 = stack[-2];
        return list2star(v_5588, v_5580, v_5579);
    }
v_5479:
    goto v_5523;
v_5519:
    v_5580 = stack[-3];
    goto v_5520;
v_5521:
    v_5579 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5522;
v_5523:
    goto v_5519;
v_5520:
    goto v_5521;
v_5522:
    v_5579 = (LispObject)greaterp2(v_5580, v_5579);
    v_5579 = v_5579 ? lisp_true : nil;
    env = stack[-5];
    if (v_5579 == nil) goto v_5517;
    goto v_5533;
v_5527:
    stack[-4] = elt(env, 1); // !:rd!:
    goto v_5528;
v_5529:
    goto v_5540;
v_5536:
    goto v_5546;
v_5542:
    v_5580 = stack[-1];
    goto v_5543;
v_5544:
    v_5579 = stack[-3];
    goto v_5545;
v_5546:
    goto v_5542;
v_5543:
    goto v_5544;
v_5545:
    fn = elt(env, 2); // ashift
    v_5580 = (*qfn2(fn))(fn, v_5580, v_5579);
    env = stack[-5];
    goto v_5537;
v_5538:
    v_5579 = stack[0];
    goto v_5539;
v_5540:
    goto v_5536;
v_5537:
    goto v_5538;
v_5539:
    v_5580 = plus2(v_5580, v_5579);
    goto v_5530;
v_5531:
    v_5579 = stack[-2];
    goto v_5532;
v_5533:
    goto v_5527;
v_5528:
    goto v_5529;
v_5530:
    goto v_5531;
v_5532:
    {
        LispObject v_5589 = stack[-4];
        return list2star(v_5589, v_5580, v_5579);
    }
v_5517:
    goto v_5560;
v_5554:
    stack[-2] = elt(env, 1); // !:rd!:
    goto v_5555;
v_5556:
    goto v_5567;
v_5563:
    goto v_5564;
v_5565:
    goto v_5574;
v_5570:
    goto v_5571;
v_5572:
    v_5579 = stack[-3];
    v_5579 = negate(v_5579);
    env = stack[-5];
    goto v_5573;
v_5574:
    goto v_5570;
v_5571:
    goto v_5572;
v_5573:
    fn = elt(env, 2); // ashift
    v_5579 = (*qfn2(fn))(fn, stack[0], v_5579);
    env = stack[-5];
    goto v_5566;
v_5567:
    goto v_5563;
v_5564:
    goto v_5565;
v_5566:
    v_5580 = plus2(stack[-1], v_5579);
    goto v_5557;
v_5558:
    v_5579 = stack[-4];
    goto v_5559;
v_5560:
    goto v_5554;
v_5555:
    goto v_5556;
v_5557:
    goto v_5558;
v_5559:
    {
        LispObject v_5590 = stack[-2];
        return list2star(v_5590, v_5580, v_5579);
    }
    v_5579 = nil;
v_5453:
    return onevalue(v_5579);
}



// Code for contr1!-strand

static LispObject CC_contr1Kstrand(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5459, v_5460, v_5461, v_5462;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5459 = v_5443;
    v_5460 = v_5442;
// end of prologue
    goto v_5454;
v_5446:
    v_5462 = v_5460;
    goto v_5447;
v_5448:
    v_5461 = v_5459;
    goto v_5449;
v_5450:
    v_5460 = nil;
    goto v_5451;
v_5452:
    v_5459 = nil;
    goto v_5453;
v_5454:
    goto v_5446;
v_5447:
    goto v_5448;
v_5449:
    goto v_5450;
v_5451:
    goto v_5452;
v_5453:
    {
        fn = elt(env, 1); // contr2!-strand
        return (*qfnn(fn))(fn, 4, v_5462, v_5461, v_5460, v_5459);
    }
}



// Code for red!-weight!-less!-p

static LispObject CC_redKweightKlessKp(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5480, v_5481, v_5482, v_5483;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5481 = v_5443;
    v_5482 = v_5442;
// end of prologue
    goto v_5453;
v_5449:
    v_5480 = v_5482;
    v_5483 = qcar(v_5480);
    goto v_5450;
v_5451:
    v_5480 = v_5481;
    v_5480 = qcar(v_5480);
    goto v_5452;
v_5453:
    goto v_5449;
v_5450:
    goto v_5451;
v_5452:
    if (equal(v_5483, v_5480)) goto v_5447;
    else goto v_5448;
v_5447:
    goto v_5463;
v_5459:
    v_5480 = v_5482;
    v_5480 = qcdr(v_5480);
    goto v_5460;
v_5461:
    v_5481 = qcdr(v_5481);
    goto v_5462;
v_5463:
    goto v_5459;
v_5460:
    goto v_5461;
v_5462:
        return Llessp(nil, v_5480, v_5481);
v_5448:
    goto v_5475;
v_5471:
    v_5480 = v_5482;
    v_5480 = qcar(v_5480);
    goto v_5472;
v_5473:
    v_5481 = qcar(v_5481);
    goto v_5474;
v_5475:
    goto v_5471;
v_5472:
    goto v_5473;
v_5474:
        return Llessp(nil, v_5480, v_5481);
    v_5480 = nil;
    return onevalue(v_5480);
}



// Code for set!-general!-modulus

static LispObject CC_setKgeneralKmodulus(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5483, v_5484;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5442;
// end of prologue
    v_5483 = stack[0];
    if (is_number(v_5483)) goto v_5451;
    v_5483 = lisp_true;
    goto v_5449;
v_5451:
    goto v_5460;
v_5456:
    v_5484 = stack[0];
    goto v_5457;
v_5458:
    v_5483 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5459;
v_5460:
    goto v_5456;
v_5457:
    goto v_5458;
v_5459:
    v_5483 = (v_5484 == v_5483 ? lisp_true : nil);
    goto v_5449;
    v_5483 = nil;
v_5449:
    if (v_5483 == nil) goto v_5447;
    v_5483 = qvalue(elt(env, 1)); // current!-modulus
    goto v_5445;
v_5447:
    v_5483 = qvalue(elt(env, 1)); // current!-modulus
    stack[-1] = v_5483;
    v_5483 = stack[0];
    qvalue(elt(env, 1)) = v_5483; // current!-modulus
    goto v_5477;
v_5473:
    v_5484 = stack[0];
    goto v_5474;
v_5475:
    v_5483 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_5476;
v_5477:
    goto v_5473;
v_5474:
    goto v_5475;
v_5476:
    v_5483 = quot2(v_5484, v_5483);
    env = stack[-2];
    qvalue(elt(env, 2)) = v_5483; // modulus!/2
    v_5483 = stack[0];
    v_5483 = Lset_small_modulus(nil, v_5483);
    v_5483 = stack[-1];
    goto v_5445;
    v_5483 = nil;
v_5445:
    return onevalue(v_5483);
}



// Code for ra_budancount

static LispObject CC_ra_budancount(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_5458, v_5459, v_5460;
    LispObject fn;
    LispObject v_5444, v_5443, v_5442;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ra_budancount");
    va_start(aa, nargs);
    v_5442 = va_arg(aa, LispObject);
    v_5443 = va_arg(aa, LispObject);
    v_5444 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_5444,v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_5442,v_5443,v_5444);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_5458 = v_5444;
    v_5459 = v_5443;
    v_5460 = v_5442;
// end of prologue
    goto v_5454;
v_5448:
    goto v_5449;
v_5450:
    goto v_5451;
v_5452:
    goto v_5453;
v_5454:
    goto v_5448;
v_5449:
    goto v_5450;
v_5451:
    goto v_5452;
v_5453:
    fn = elt(env, 1); // ra_transform
    v_5458 = (*qfnn(fn))(fn, 3, v_5460, v_5459, v_5458);
    env = stack[0];
    {
        fn = elt(env, 2); // ra_budan!-0!-1
        return (*qfn1(fn))(fn, v_5458);
    }
}



// Code for lalr_prin_action

static LispObject CC_lalr_prin_action(LispObject env,
                         LispObject v_5442)
{
    env = qenv(env);
    LispObject v_5481, v_5482;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5442);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_5442;
// end of prologue
    v_5481 = stack[0];
    if (v_5481 == nil) goto v_5446;
    else goto v_5447;
v_5446:
    v_5481 = elt(env, 1); // " "
        return Lprinc(nil, v_5481);
v_5447:
    goto v_5458;
v_5454:
    v_5482 = stack[0];
    goto v_5455;
v_5456:
    v_5481 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5457;
v_5458:
    goto v_5454;
v_5455:
    goto v_5456;
v_5457:
    v_5481 = (LispObject)greaterp2(v_5482, v_5481);
    v_5481 = v_5481 ? lisp_true : nil;
    env = stack[-1];
    if (v_5481 == nil) goto v_5452;
    v_5481 = elt(env, 2); // "shift to state "
    v_5481 = Lprinc(nil, v_5481);
    v_5481 = stack[0];
        return Lprin(nil, v_5481);
v_5452:
    goto v_5471;
v_5467:
    v_5482 = stack[0];
    goto v_5468;
v_5469:
    v_5481 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5470;
v_5471:
    goto v_5467;
v_5468:
    goto v_5469;
v_5470:
    if (v_5482 == v_5481) goto v_5465;
    else goto v_5466;
v_5465:
    v_5481 = elt(env, 3); // "accept"
        return Lprinc(nil, v_5481);
v_5466:
    v_5481 = stack[0];
    v_5481 = negate(v_5481);
    env = stack[-1];
    {
        fn = elt(env, 4); // lalr_prin_reduction
        return (*qfn1(fn))(fn, v_5481);
    }
    v_5481 = nil;
    return onevalue(v_5481);
}



// Code for formclis

static LispObject CC_formclis(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_5481, v_5482, v_5483;
    LispObject fn;
    LispObject v_5444, v_5443, v_5442;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formclis");
    va_start(aa, nargs);
    v_5442 = va_arg(aa, LispObject);
    v_5443 = va_arg(aa, LispObject);
    v_5444 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_5444,v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_5442,v_5443,v_5444);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_5444;
    stack[-1] = v_5443;
    stack[-2] = v_5442;
// end of prologue
    stack[-3] = nil;
v_5451:
    v_5481 = stack[-2];
    if (v_5481 == nil) goto v_5454;
    else goto v_5455;
v_5454:
    goto v_5450;
v_5455:
    goto v_5463;
v_5459:
    goto v_5471;
v_5465:
    v_5481 = stack[-2];
    v_5483 = qcar(v_5481);
    goto v_5466;
v_5467:
    v_5482 = stack[-1];
    goto v_5468;
v_5469:
    v_5481 = stack[0];
    goto v_5470;
v_5471:
    goto v_5465;
v_5466:
    goto v_5467;
v_5468:
    goto v_5469;
v_5470:
    fn = elt(env, 1); // formc
    v_5482 = (*qfnn(fn))(fn, 3, v_5483, v_5482, v_5481);
    env = stack[-4];
    goto v_5460;
v_5461:
    v_5481 = stack[-3];
    goto v_5462;
v_5463:
    goto v_5459;
v_5460:
    goto v_5461;
v_5462:
    v_5481 = cons(v_5482, v_5481);
    env = stack[-4];
    stack[-3] = v_5481;
    v_5481 = stack[-2];
    v_5481 = qcdr(v_5481);
    stack[-2] = v_5481;
    goto v_5451;
v_5450:
    v_5481 = stack[-3];
    {
        fn = elt(env, 2); // reversip!*
        return (*qfn1(fn))(fn, v_5481);
    }
    return onevalue(v_5481);
}



// Code for ofsf_posvarpat

static LispObject CC_ofsf_posvarpat(LispObject env,
                         LispObject v_5442, LispObject v_5443)
{
    env = qenv(env);
    LispObject v_5486, v_5487, v_5488;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5442,v_5443);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_5443;
    v_5488 = v_5442;
// end of prologue
    v_5486 = v_5488;
    if (!consp(v_5486)) goto v_5450;
    else goto v_5451;
v_5450:
    v_5486 = v_5488;
    goto v_5449;
v_5451:
    v_5486 = v_5488;
    v_5486 = qcar(v_5486);
    goto v_5449;
    v_5486 = nil;
v_5449:
    stack[-1] = v_5486;
    goto v_5466;
v_5462:
    v_5487 = stack[-1];
    goto v_5463;
v_5464:
    v_5486 = elt(env, 1); // (greaterp geq)
    goto v_5465;
v_5466:
    goto v_5462;
v_5463:
    goto v_5464;
v_5465:
    v_5486 = Lmemq(nil, v_5487, v_5486);
    if (v_5486 == nil) goto v_5460;
    else goto v_5461;
v_5460:
    v_5486 = nil;
    goto v_5447;
v_5461:
    goto v_5479;
v_5475:
    v_5486 = v_5488;
    v_5486 = qcdr(v_5486);
    v_5486 = qcar(v_5486);
    fn = elt(env, 2); // sfto_varp
    v_5487 = (*qfn1(fn))(fn, v_5486);
    goto v_5476;
v_5477:
    v_5486 = stack[0];
    goto v_5478;
v_5479:
    goto v_5475;
v_5476:
    goto v_5477;
v_5478:
    if (v_5487 == v_5486) goto v_5473;
    else goto v_5474;
v_5473:
    v_5486 = stack[-1];
    goto v_5447;
v_5474:
    v_5486 = nil;
v_5447:
    return onevalue(v_5486);
}



// Code for processcarpartitie1

static LispObject CC_processcarpartitie1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_5493, v_5494, v_5495;
    LispObject fn;
    LispObject v_5446, v_5445, v_5444, v_5443, v_5442;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "processcarpartitie1");
    va_start(aa, nargs);
    v_5442 = va_arg(aa, LispObject);
    v_5443 = va_arg(aa, LispObject);
    v_5444 = va_arg(aa, LispObject);
    v_5445 = va_arg(aa, LispObject);
    v_5446 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_5446,v_5445,v_5444,v_5443,v_5442);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_5442,v_5443,v_5444,v_5445,v_5446);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-3] = v_5446;
    stack[-4] = v_5445;
    stack[-5] = v_5444;
    v_5493 = v_5443;
    stack[-6] = v_5442;
// end of prologue
v_5451:
    v_5494 = v_5493;
    if (v_5494 == nil) goto v_5454;
    else goto v_5455;
v_5454:
    v_5493 = stack[-3];
    goto v_5450;
v_5455:
    v_5494 = v_5493;
    v_5494 = qcdr(v_5494);
    stack[-7] = v_5494;
    goto v_5473;
v_5463:
    stack[-2] = stack[-5];
    goto v_5464;
v_5465:
    stack[-1] = stack[-6];
    goto v_5466;
v_5467:
    stack[0] = v_5493;
    goto v_5468;
v_5469:
    goto v_5484;
v_5478:
    v_5494 = stack[-4];
    v_5495 = qcar(v_5494);
    goto v_5479;
v_5480:
    v_5494 = qcar(v_5493);
    goto v_5481;
v_5482:
    v_5493 = stack[-4];
    v_5493 = qcdr(v_5493);
    goto v_5483;
v_5484:
    goto v_5478;
v_5479:
    goto v_5480;
v_5481:
    goto v_5482;
v_5483:
    v_5494 = list2star(v_5495, v_5494, v_5493);
    env = stack[-8];
    goto v_5470;
v_5471:
    v_5493 = stack[-3];
    goto v_5472;
v_5473:
    goto v_5463;
v_5464:
    goto v_5465;
v_5466:
    goto v_5467;
v_5468:
    goto v_5469;
v_5470:
    goto v_5471;
v_5472:
    fn = elt(env, 1); // processpartitie1
    v_5493 = (*qfnn(fn))(fn, 5, stack[-2], stack[-1], stack[0], v_5494, v_5493);
    env = stack[-8];
    stack[-3] = v_5493;
    v_5493 = stack[-7];
    goto v_5451;
    v_5493 = nil;
v_5450:
    return onevalue(v_5493);
}



setup_type const u11_setup[] =
{
    {"getphystype",             CC_getphystype, TOO_MANY_1,    WRONG_NO_1},
    {"convertmode1",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_convertmode1},
    {"mv-domainlist--",         TOO_FEW_2,      CC_mvKdomainlistKK,WRONG_NO_2},
    {"*id2num",                 CC_Hid2num,     TOO_MANY_1,    WRONG_NO_1},
    {"list_assoc",              TOO_FEW_2,      CC_list_assoc, WRONG_NO_2},
    {"exptf",                   TOO_FEW_2,      CC_exptf,      WRONG_NO_2},
    {"lalr_generate_lr0_collection",WRONG_NO_NA,WRONG_NO_NB,   (n_args *)CC_lalr_generate_lr0_collection},
    {"quotfx",                  TOO_FEW_2,      CC_quotfx,     WRONG_NO_2},
    {"janettreefind",           CC_janettreefind,TOO_MANY_1,   WRONG_NO_1},
    {"diffp1",                  TOO_FEW_2,      CC_diffp1,     WRONG_NO_2},
    {"revv0",                   TOO_FEW_2,      CC_revv0,      WRONG_NO_2},
    {"tayexp-difference",       TOO_FEW_2,      CC_tayexpKdifference,WRONG_NO_2},
    {"cl_smcpknowl",            CC_cl_smcpknowl,TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_prepat",             CC_ofsf_prepat, TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_litp",              CC_ibalp_litp,  TOO_MANY_1,    WRONG_NO_1},
    {"quotfail-mod-p",          TOO_FEW_2,      CC_quotfailKmodKp,WRONG_NO_2},
    {"smtp",                    TOO_FEW_2,      CC_smtp,       WRONG_NO_2},
    {"on",                      CC_on,          TOO_MANY_1,    WRONG_NO_1},
    {"mkuwedge",                CC_mkuwedge,    TOO_MANY_1,    WRONG_NO_1},
    {"form1",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_form1},
    {"formop",                  CC_formop,      TOO_MANY_1,    WRONG_NO_1},
    {"leftzeros",               CC_leftzeros,   TOO_MANY_1,    WRONG_NO_1},
    {"reduce-mod-p",            CC_reduceKmodKp,TOO_MANY_1,    WRONG_NO_1},
    {"mconv",                   CC_mconv,       TOO_MANY_1,    WRONG_NO_1},
    {"lalr_lr0_itemset_to_lalr_kernel",CC_lalr_lr0_itemset_to_lalr_kernel,TOO_MANY_1,WRONG_NO_1},
    {"aex_simplenullp",         CC_aex_simplenullp,TOO_MANY_1, WRONG_NO_1},
    {"ofsf_ordatp",             TOO_FEW_2,      CC_ofsf_ordatp,WRONG_NO_2},
    {"monommultiplybyvariable", TOO_FEW_2,      CC_monommultiplybyvariable,WRONG_NO_2},
    {"cl_varl1",                CC_cl_varl1,    TOO_MANY_1,    WRONG_NO_1},
    {"preptayexp",              CC_preptayexp,  TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_atomp",             CC_ibalp_atomp, TOO_MANY_1,    WRONG_NO_1},
    {"off",                     CC_off,         TOO_MANY_1,    WRONG_NO_1},
    {"id2bytelist",             CC_id2bytelist, TOO_MANY_1,    WRONG_NO_1},
    {":difference",             TOO_FEW_2,      CC_Tdifference,WRONG_NO_2},
    {"scan",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_scan},
    {"listtest",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_listtest},
    {"pv_neg",                  CC_pv_neg,      TOO_MANY_1,    WRONG_NO_1},
    {"arintequiv:",             CC_arintequivT, TOO_MANY_1,    WRONG_NO_1},
    {"lalr_prin_nonterminal",   CC_lalr_prin_nonterminal,TOO_MANY_1,WRONG_NO_1},
    {"remflagss",               TOO_FEW_2,      CC_remflagss,  WRONG_NO_2},
    {"ordpa",                   TOO_FEW_2,      CC_ordpa,      WRONG_NO_2},
    {"qqe_number-of-tails-in-qterm",CC_qqe_numberKofKtailsKinKqterm,TOO_MANY_1,WRONG_NO_1},
    {"lastnondomain",           CC_lastnondomain,TOO_MANY_1,   WRONG_NO_1},
    {"ibalp_vmember",           TOO_FEW_2,      CC_ibalp_vmember,WRONG_NO_2},
    {"basicom",                 CC_basicom,     TOO_MANY_1,    WRONG_NO_1},
    {"dfn_prop",                CC_dfn_prop,    TOO_MANY_1,    WRONG_NO_1},
    {"initwght",                CC_initwght,    TOO_MANY_1,    WRONG_NO_1},
    {"vdplength",               CC_vdplength,   TOO_MANY_1,    WRONG_NO_1},
    {"plus:",                   TOO_FEW_2,      CC_plusT,      WRONG_NO_2},
    {"contr1-strand",           TOO_FEW_2,      CC_contr1Kstrand,WRONG_NO_2},
    {"red-weight-less-p",       TOO_FEW_2,      CC_redKweightKlessKp,WRONG_NO_2},
    {"set-general-modulus",     CC_setKgeneralKmodulus,TOO_MANY_1,WRONG_NO_1},
    {"ra_budancount",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ra_budancount},
    {"lalr_prin_action",        CC_lalr_prin_action,TOO_MANY_1,WRONG_NO_1},
    {"formclis",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formclis},
    {"ofsf_posvarpat",          TOO_FEW_2,      CC_ofsf_posvarpat,WRONG_NO_2},
    {"processcarpartitie1",     WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_processcarpartitie1},
    {NULL, (one_args *)"u11", (two_args *)"65266 1412015 6587347", 0}
};

// end of generated code
