
// $destdir/u15.c        Machine generated C code

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



// Code for p_prin

static LispObject CC_p_prin(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8113, v_8114;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7976;
    v_8113 = v_7975;
// end of prologue
    v_8113 = Lexplode(nil, v_8113);
    env = stack[-2];
    stack[-1] = v_8113;
    goto v_7992;
v_7988:
    v_8114 = stack[-1];
    goto v_7989;
v_7990:
    v_8113 = elt(env, 1); // !_
    goto v_7991;
v_7992:
    goto v_7988;
v_7989:
    goto v_7990;
v_7991:
    if (!consp(v_8114)) goto v_7986;
    v_8114 = qcar(v_8114);
    if (v_8114 == v_8113) goto v_7985;
    else goto v_7986;
v_7985:
    goto v_8000;
v_7996:
    v_8114 = elt(env, 2); // !!
    goto v_7997;
v_7998:
    v_8113 = stack[-1];
    goto v_7999;
v_8000:
    goto v_7996;
v_7997:
    goto v_7998;
v_7999:
    v_8113 = cons(v_8114, v_8113);
    env = stack[-2];
    stack[-1] = v_8113;
    goto v_7984;
v_7986:
v_7984:
    v_8113 = qvalue(elt(env, 3)); // bldmsg_chars!*
    if (v_8113 == nil) goto v_8006;
    v_8113 = stack[0];
    if (v_8113 == nil) goto v_8011;
    goto v_8018;
v_8014:
    v_8114 = elt(env, 4); // ! 
    goto v_8015;
v_8016:
    v_8113 = qvalue(elt(env, 3)); // bldmsg_chars!*
    goto v_8017;
v_8018:
    goto v_8014;
v_8015:
    goto v_8016;
v_8017:
    v_8113 = cons(v_8114, v_8113);
    env = stack[-2];
    qvalue(elt(env, 3)) = v_8113; // bldmsg_chars!*
    goto v_8009;
v_8011:
v_8009:
    v_8113 = stack[-1];
    stack[0] = v_8113;
v_8024:
    v_8113 = stack[0];
    if (v_8113 == nil) goto v_8028;
    else goto v_8029;
v_8028:
    goto v_8023;
v_8029:
    v_8113 = stack[0];
    v_8113 = qcar(v_8113);
    goto v_8040;
v_8036:
    v_8114 = v_8113;
    goto v_8037;
v_8038:
    v_8113 = qvalue(elt(env, 3)); // bldmsg_chars!*
    goto v_8039;
v_8040:
    goto v_8036;
v_8037:
    goto v_8038;
v_8039:
    v_8113 = cons(v_8114, v_8113);
    env = stack[-2];
    qvalue(elt(env, 3)) = v_8113; // bldmsg_chars!*
    v_8113 = stack[0];
    v_8113 = qcdr(v_8113);
    stack[0] = v_8113;
    goto v_8024;
v_8023:
    goto v_8004;
v_8006:
    v_8113 = stack[0];
    if (v_8113 == nil) goto v_8050;
    goto v_8061;
v_8057:
    goto v_8067;
v_8063:
    stack[0] = Lposn(nil, 0);
    env = stack[-2];
    goto v_8064;
v_8065:
    v_8113 = stack[-1];
    v_8113 = Llength(nil, v_8113);
    env = stack[-2];
    v_8113 = add1(v_8113);
    env = stack[-2];
    goto v_8066;
v_8067:
    goto v_8063;
v_8064:
    goto v_8065;
v_8066:
    v_8114 = plus2(stack[0], v_8113);
    env = stack[-2];
    goto v_8058;
v_8059:
    v_8113 = qvalue(elt(env, 5)); // !*ll!*
    goto v_8060;
v_8061:
    goto v_8057;
v_8058:
    goto v_8059;
v_8060:
    v_8113 = (LispObject)greaterp2(v_8114, v_8113);
    v_8113 = v_8113 ? lisp_true : nil;
    env = stack[-2];
    if (v_8113 == nil) goto v_8055;
    v_8113 = Lterpri(nil, 0);
    env = stack[-2];
    goto v_8053;
v_8055:
v_8053:
    v_8113 = elt(env, 6); // " "
    v_8113 = Lprinc(nil, v_8113);
    env = stack[-2];
    goto v_8048;
v_8050:
    goto v_8083;
v_8079:
    goto v_8089;
v_8085:
    stack[0] = Lposn(nil, 0);
    env = stack[-2];
    goto v_8086;
v_8087:
    v_8113 = stack[-1];
    v_8113 = Llength(nil, v_8113);
    env = stack[-2];
    goto v_8088;
v_8089:
    goto v_8085;
v_8086:
    goto v_8087;
v_8088:
    v_8114 = plus2(stack[0], v_8113);
    env = stack[-2];
    goto v_8080;
v_8081:
    v_8113 = qvalue(elt(env, 5)); // !*ll!*
    goto v_8082;
v_8083:
    goto v_8079;
v_8080:
    goto v_8081;
v_8082:
    v_8113 = (LispObject)greaterp2(v_8114, v_8113);
    v_8113 = v_8113 ? lisp_true : nil;
    env = stack[-2];
    if (v_8113 == nil) goto v_8077;
    v_8113 = Lterpri(nil, 0);
    env = stack[-2];
    goto v_8048;
v_8077:
v_8048:
    v_8113 = stack[-1];
    stack[0] = v_8113;
v_8098:
    v_8113 = stack[0];
    if (v_8113 == nil) goto v_8102;
    else goto v_8103;
v_8102:
    goto v_8097;
v_8103:
    v_8113 = stack[0];
    v_8113 = qcar(v_8113);
    v_8113 = Lprinc(nil, v_8113);
    env = stack[-2];
    v_8113 = stack[0];
    v_8113 = qcdr(v_8113);
    stack[0] = v_8113;
    goto v_8098;
v_8097:
    goto v_8004;
v_8004:
    v_8113 = nil;
    return onevalue(v_8113);
}



// Code for sq2sscfpl

static LispObject CC_sq2sscfpl(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8035, v_8036;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7976;
    stack[-1] = v_7975;
// end of prologue
    v_8035 = stack[-1];
    if (v_8035 == nil) goto v_7980;
    else goto v_7981;
v_7980:
    v_8035 = nil;
    goto v_7979;
v_7981:
    v_8035 = stack[-1];
    if (!consp(v_8035)) goto v_7988;
    else goto v_7989;
v_7988:
    v_8035 = lisp_true;
    goto v_7987;
v_7989:
    v_8035 = stack[-1];
    v_8035 = qcar(v_8035);
    v_8035 = (consp(v_8035) ? nil : lisp_true);
    goto v_7987;
    v_8035 = nil;
v_7987:
    if (v_8035 == nil) goto v_7985;
    goto v_8003;
v_7999:
    v_8035 = stack[0];
    v_8035 = qcdr(v_8035);
    v_8035 = add1(v_8035);
    env = stack[-3];
    fn = elt(env, 1); // mkzl
    v_8036 = (*qfn1(fn))(fn, v_8035);
    env = stack[-3];
    goto v_8000;
v_8001:
    v_8035 = stack[-1];
    goto v_8002;
v_8003:
    goto v_7999;
v_8000:
    goto v_8001;
v_8002:
    v_8035 = cons(v_8036, v_8035);
    return ncons(v_8035);
v_7985:
    goto v_8016;
v_8012:
    goto v_8022;
v_8018:
    v_8035 = stack[-1];
    v_8036 = qcar(v_8035);
    goto v_8019;
v_8020:
    v_8035 = stack[0];
    goto v_8021;
v_8022:
    goto v_8018;
v_8019:
    goto v_8020;
v_8021:
    fn = elt(env, 2); // sq2sstm
    stack[-2] = (*qfn2(fn))(fn, v_8036, v_8035);
    env = stack[-3];
    goto v_8013;
v_8014:
    goto v_8031;
v_8027:
    v_8035 = stack[-1];
    v_8036 = qcdr(v_8035);
    goto v_8028;
v_8029:
    v_8035 = stack[0];
    goto v_8030;
v_8031:
    goto v_8027;
v_8028:
    goto v_8029;
v_8030:
    v_8035 = CC_sq2sscfpl(elt(env, 0), v_8036, v_8035);
    goto v_8015;
v_8016:
    goto v_8012;
v_8013:
    goto v_8014;
v_8015:
    {
        LispObject v_8040 = stack[-2];
        return Lappend(nil, v_8040, v_8035);
    }
    v_8035 = nil;
v_7979:
    return onevalue(v_8035);
}



// Code for ofsf_pow2q

static LispObject CC_ofsf_pow2q(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8003, v_8004, v_8005;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_8003 = v_7976;
    v_8004 = v_7975;
// end of prologue
    goto v_7985;
v_7979:
    goto v_7991;
v_7987:
    goto v_7997;
v_7993:
    goto v_7994;
v_7995:
    goto v_7996;
v_7997:
    goto v_7993;
v_7994:
    goto v_7995;
v_7996:
    fn = elt(env, 1); // to
    v_8004 = (*qfn2(fn))(fn, v_8004, v_8003);
    env = stack[0];
    goto v_7988;
v_7989:
    v_8003 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7990;
v_7991:
    goto v_7987;
v_7988:
    goto v_7989;
v_7990:
    v_8005 = cons(v_8004, v_8003);
    goto v_7980;
v_7981:
    v_8004 = nil;
    goto v_7982;
v_7983:
    v_8003 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7984;
v_7985:
    goto v_7979;
v_7980:
    goto v_7981;
v_7982:
    goto v_7983;
v_7984:
    return acons(v_8005, v_8004, v_8003);
}



// Code for downwght1

static LispObject CC_downwght1(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8202, v_8203;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_8202 = v_7976;
    stack[-4] = v_7975;
// end of prologue
    fn = elt(env, 3); // dm!-abs
    v_8202 = (*qfn1(fn))(fn, v_8202);
    env = stack[-6];
    fn = elt(env, 4); // !:onep
    v_8202 = (*qfn1(fn))(fn, v_8202);
    env = stack[-6];
    if (v_8202 == nil) goto v_7980;
    else goto v_7981;
v_7980:
    goto v_7991;
v_7985:
    goto v_7996;
v_7992:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_7993;
v_7994:
    goto v_8003;
v_7999:
    v_8203 = qvalue(elt(env, 2)); // maxvar
    goto v_8000;
v_8001:
    v_8202 = stack[-4];
    goto v_8002;
v_8003:
    goto v_7999;
v_8000:
    goto v_8001;
v_8002:
    v_8202 = plus2(v_8203, v_8202);
    env = stack[-6];
    goto v_7995;
v_7996:
    goto v_7992;
v_7993:
    goto v_7994;
v_7995:
    stack[-5] = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_8202-TAG_FIXNUM)/(16/CELL)));
    goto v_7986;
v_7987:
    stack[-3] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7988;
v_7989:
    goto v_8015;
v_8009:
    goto v_8021;
v_8017:
    goto v_8026;
v_8022:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_8023;
v_8024:
    goto v_8033;
v_8029:
    v_8203 = qvalue(elt(env, 2)); // maxvar
    goto v_8030;
v_8031:
    v_8202 = stack[-4];
    goto v_8032;
v_8033:
    goto v_8029;
v_8030:
    goto v_8031;
v_8032:
    v_8202 = plus2(v_8203, v_8202);
    env = stack[-6];
    goto v_8025;
v_8026:
    goto v_8022;
v_8023:
    goto v_8024;
v_8025:
    v_8203 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_8202-TAG_FIXNUM)/(16/CELL)));
    goto v_8018;
v_8019:
    v_8202 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8020;
v_8021:
    goto v_8017;
v_8018:
    goto v_8019;
v_8020:
    v_8202 = *(LispObject *)((char *)v_8203 + (CELL-TAG_VECTOR) + (((intptr_t)v_8202-TAG_FIXNUM)/(16/CELL)));
    v_8202 = qcar(v_8202);
    v_8202 = qcar(v_8202);
    stack[-2] = sub1(v_8202);
    env = stack[-6];
    goto v_8010;
v_8011:
    goto v_8046;
v_8042:
    goto v_8051;
v_8047:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_8048;
v_8049:
    goto v_8058;
v_8054:
    v_8203 = qvalue(elt(env, 2)); // maxvar
    goto v_8055;
v_8056:
    v_8202 = stack[-4];
    goto v_8057;
v_8058:
    goto v_8054;
v_8055:
    goto v_8056;
v_8057:
    v_8202 = plus2(v_8203, v_8202);
    env = stack[-6];
    goto v_8050;
v_8051:
    goto v_8047;
v_8048:
    goto v_8049;
v_8050:
    v_8203 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_8202-TAG_FIXNUM)/(16/CELL)));
    goto v_8043;
v_8044:
    v_8202 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8045;
v_8046:
    goto v_8042;
v_8043:
    goto v_8044;
v_8045:
    v_8202 = *(LispObject *)((char *)v_8203 + (CELL-TAG_VECTOR) + (((intptr_t)v_8202-TAG_FIXNUM)/(16/CELL)));
    v_8202 = qcar(v_8202);
    v_8202 = qcdr(v_8202);
    stack[-1] = sub1(v_8202);
    env = stack[-6];
    goto v_8012;
v_8013:
    goto v_8071;
v_8067:
    goto v_8076;
v_8072:
    goto v_8081;
v_8077:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_8078;
v_8079:
    goto v_8088;
v_8084:
    v_8203 = qvalue(elt(env, 2)); // maxvar
    goto v_8085;
v_8086:
    v_8202 = stack[-4];
    goto v_8087;
v_8088:
    goto v_8084;
v_8085:
    goto v_8086;
v_8087:
    v_8202 = plus2(v_8203, v_8202);
    env = stack[-6];
    goto v_8080;
v_8081:
    goto v_8077;
v_8078:
    goto v_8079;
v_8080:
    v_8203 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_8202-TAG_FIXNUM)/(16/CELL)));
    goto v_8073;
v_8074:
    v_8202 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8075;
v_8076:
    goto v_8072;
v_8073:
    goto v_8074;
v_8075:
    v_8202 = *(LispObject *)((char *)v_8203 + (CELL-TAG_VECTOR) + (((intptr_t)v_8202-TAG_FIXNUM)/(16/CELL)));
    v_8203 = qcdr(v_8202);
    goto v_8068;
v_8069:
    v_8202 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_8070;
v_8071:
    goto v_8067;
v_8068:
    goto v_8069;
v_8070:
    v_8202 = difference2(v_8203, v_8202);
    env = stack[-6];
    goto v_8014;
v_8015:
    goto v_8009;
v_8010:
    goto v_8011;
v_8012:
    goto v_8013;
v_8014:
    v_8202 = acons(stack[-2], stack[-1], v_8202);
    goto v_7990;
v_7991:
    goto v_7985;
v_7986:
    goto v_7987;
v_7988:
    goto v_7989;
v_7990:
    *(LispObject *)((char *)stack[-5] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-3]-TAG_FIXNUM)/(16/CELL))) = v_8202;
    goto v_7979;
v_7981:
    goto v_8104;
v_8098:
    goto v_8109;
v_8105:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_8106;
v_8107:
    goto v_8116;
v_8112:
    v_8203 = qvalue(elt(env, 2)); // maxvar
    goto v_8113;
v_8114:
    v_8202 = stack[-4];
    goto v_8115;
v_8116:
    goto v_8112;
v_8113:
    goto v_8114;
v_8115:
    v_8202 = plus2(v_8203, v_8202);
    env = stack[-6];
    goto v_8108;
v_8109:
    goto v_8105;
v_8106:
    goto v_8107;
v_8108:
    stack[-5] = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_8202-TAG_FIXNUM)/(16/CELL)));
    goto v_8099;
v_8100:
    stack[-3] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8101;
v_8102:
    goto v_8128;
v_8122:
    goto v_8134;
v_8130:
    goto v_8139;
v_8135:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_8136;
v_8137:
    goto v_8146;
v_8142:
    v_8203 = qvalue(elt(env, 2)); // maxvar
    goto v_8143;
v_8144:
    v_8202 = stack[-4];
    goto v_8145;
v_8146:
    goto v_8142;
v_8143:
    goto v_8144;
v_8145:
    v_8202 = plus2(v_8203, v_8202);
    env = stack[-6];
    goto v_8138;
v_8139:
    goto v_8135;
v_8136:
    goto v_8137;
v_8138:
    v_8203 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_8202-TAG_FIXNUM)/(16/CELL)));
    goto v_8131;
v_8132:
    v_8202 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8133;
v_8134:
    goto v_8130;
v_8131:
    goto v_8132;
v_8133:
    v_8202 = *(LispObject *)((char *)v_8203 + (CELL-TAG_VECTOR) + (((intptr_t)v_8202-TAG_FIXNUM)/(16/CELL)));
    v_8202 = qcar(v_8202);
    v_8202 = qcar(v_8202);
    stack[-2] = sub1(v_8202);
    env = stack[-6];
    goto v_8123;
v_8124:
    goto v_8158;
v_8154:
    goto v_8163;
v_8159:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_8160;
v_8161:
    goto v_8170;
v_8166:
    v_8203 = qvalue(elt(env, 2)); // maxvar
    goto v_8167;
v_8168:
    v_8202 = stack[-4];
    goto v_8169;
v_8170:
    goto v_8166;
v_8167:
    goto v_8168;
v_8169:
    v_8202 = plus2(v_8203, v_8202);
    env = stack[-6];
    goto v_8162;
v_8163:
    goto v_8159;
v_8160:
    goto v_8161;
v_8162:
    v_8203 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_8202-TAG_FIXNUM)/(16/CELL)));
    goto v_8155;
v_8156:
    v_8202 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8157;
v_8158:
    goto v_8154;
v_8155:
    goto v_8156;
v_8157:
    v_8202 = *(LispObject *)((char *)v_8203 + (CELL-TAG_VECTOR) + (((intptr_t)v_8202-TAG_FIXNUM)/(16/CELL)));
    v_8202 = qcar(v_8202);
    stack[-1] = qcdr(v_8202);
    goto v_8125;
v_8126:
    goto v_8183;
v_8179:
    goto v_8188;
v_8184:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_8185;
v_8186:
    goto v_8195;
v_8191:
    v_8203 = qvalue(elt(env, 2)); // maxvar
    goto v_8192;
v_8193:
    v_8202 = stack[-4];
    goto v_8194;
v_8195:
    goto v_8191;
v_8192:
    goto v_8193;
v_8194:
    v_8202 = plus2(v_8203, v_8202);
    env = stack[-6];
    goto v_8187;
v_8188:
    goto v_8184;
v_8185:
    goto v_8186;
v_8187:
    v_8203 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_8202-TAG_FIXNUM)/(16/CELL)));
    goto v_8180;
v_8181:
    v_8202 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8182;
v_8183:
    goto v_8179;
v_8180:
    goto v_8181;
v_8182:
    v_8202 = *(LispObject *)((char *)v_8203 + (CELL-TAG_VECTOR) + (((intptr_t)v_8202-TAG_FIXNUM)/(16/CELL)));
    v_8202 = qcdr(v_8202);
    v_8202 = sub1(v_8202);
    env = stack[-6];
    goto v_8127;
v_8128:
    goto v_8122;
v_8123:
    goto v_8124;
v_8125:
    goto v_8126;
v_8127:
    v_8202 = acons(stack[-2], stack[-1], v_8202);
    goto v_8103;
v_8104:
    goto v_8098;
v_8099:
    goto v_8100;
v_8101:
    goto v_8102;
v_8103:
    *(LispObject *)((char *)stack[-5] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-3]-TAG_FIXNUM)/(16/CELL))) = v_8202;
    goto v_7979;
    v_8202 = nil;
v_7979:
    return onevalue(v_8202);
}



// Code for newenv

static LispObject CC_newenv(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_7985, v_7986;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7985 = v_7975;
// end of prologue
    goto v_7982;
v_7978:
    v_7986 = v_7985;
    goto v_7979;
v_7980:
    v_7985 = elt(env, 1); // unbound
    goto v_7981;
v_7982:
    goto v_7978;
v_7979:
    goto v_7980;
v_7981:
    {
        fn = elt(env, 2); // bind
        return (*qfn2(fn))(fn, v_7986, v_7985);
    }
}



// Code for evenfree

static LispObject CC_evenfree(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_8019, v_8020;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7975);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7975;
// end of prologue
    v_8019 = stack[0];
    if (v_8019 == nil) goto v_7979;
    else goto v_7980;
v_7979:
    v_8019 = nil;
    goto v_7978;
v_7980:
    v_8019 = stack[0];
    if (is_number(v_8019)) goto v_7983;
    else goto v_7984;
v_7983:
    goto v_7992;
v_7988:
    v_8020 = stack[0];
    goto v_7989;
v_7990:
    v_8019 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_7991;
v_7992:
    goto v_7988;
v_7989:
    goto v_7990;
v_7991:
    fn = elt(env, 1); // qremd
    v_8019 = (*qfn2(fn))(fn, v_8020, v_8019);
    env = stack[-2];
    v_8019 = qcdr(v_8019);
    {
        fn = elt(env, 2); // absf
        return (*qfn1(fn))(fn, v_8019);
    }
v_7984:
    goto v_8003;
v_7999:
    goto v_8010;
v_8006:
    v_8019 = stack[0];
    v_8019 = qcar(v_8019);
    v_8020 = ncons(v_8019);
    env = stack[-2];
    goto v_8007;
v_8008:
    v_8019 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_8009;
v_8010:
    goto v_8006;
v_8007:
    goto v_8008;
v_8009:
    fn = elt(env, 1); // qremd
    v_8019 = (*qfn2(fn))(fn, v_8020, v_8019);
    env = stack[-2];
    v_8019 = qcdr(v_8019);
    fn = elt(env, 2); // absf
    stack[-1] = (*qfn1(fn))(fn, v_8019);
    env = stack[-2];
    goto v_8000;
v_8001:
    v_8019 = stack[0];
    v_8019 = qcdr(v_8019);
    v_8019 = CC_evenfree(elt(env, 0), v_8019);
    env = stack[-2];
    goto v_8002;
v_8003:
    goto v_7999;
v_8000:
    goto v_8001;
v_8002:
    {
        LispObject v_8023 = stack[-1];
        fn = elt(env, 3); // addf
        return (*qfn2(fn))(fn, v_8023, v_8019);
    }
    v_8019 = nil;
v_7978:
    return onevalue(v_8019);
}



// Code for fortranprecedence

static LispObject CC_fortranprecedence(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_7989, v_7990;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7975);
    }
// copy arguments values to proper place
    v_7989 = v_7975;
// end of prologue
    goto v_7985;
v_7981:
    v_7990 = v_7989;
    goto v_7982;
v_7983:
    v_7989 = elt(env, 1); // !*fortranprecedence!*
    goto v_7984;
v_7985:
    goto v_7981;
v_7982:
    goto v_7983;
v_7984:
    v_7989 = get(v_7990, v_7989);
    if (v_7989 == nil) goto v_7979;
    else goto v_7978;
v_7979:
    v_7989 = (LispObject)144+TAG_FIXNUM; // 9
v_7978:
    return onevalue(v_7989);
}



// Code for assert_typesyntaxp

static LispObject CC_assert_typesyntaxp(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_7988, v_7989;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7989 = v_7975;
// end of prologue
    v_7988 = qvalue(elt(env, 1)); // !*assert
    if (v_7988 == nil) goto v_7980;
    v_7988 = v_7989;
    {
        fn = elt(env, 2); // assert_dyntypep
        return (*qfn1(fn))(fn, v_7988);
    }
v_7980:
    v_7988 = v_7989;
        return Lsymbolp(nil, v_7988);
    v_7988 = nil;
    return onevalue(v_7988);
}



// Code for mo_neworder

static LispObject CC_mo_neworder(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_7990;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7975);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7990 = v_7975;
// end of prologue
    v_7990 = qcar(v_7990);
    fn = elt(env, 1); // mo!=shorten
    v_7990 = (*qfn1(fn))(fn, v_7990);
    env = stack[-1];
    goto v_7986;
v_7982:
    stack[0] = v_7990;
    goto v_7983;
v_7984:
    fn = elt(env, 2); // mo!=deglist
    v_7990 = (*qfn1(fn))(fn, v_7990);
    goto v_7985;
v_7986:
    goto v_7982;
v_7983:
    goto v_7984;
v_7985:
    {
        LispObject v_7992 = stack[0];
        return cons(v_7992, v_7990);
    }
}



// Code for eqdummy

static LispObject CC_eqdummy(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_7998, v_7999, v_8000;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7998 = v_7976;
    v_7999 = v_7975;
// end of prologue
    v_8000 = v_7999;
    if (v_8000 == nil) goto v_7980;
    else goto v_7981;
v_7980:
    v_7998 = nil;
    goto v_7979;
v_7981:
    goto v_7990;
v_7986:
    if (!symbolp(v_7999)) v_7999 = nil;
    else { v_7999 = qfastgets(v_7999);
           if (v_7999 != nil) { v_7999 = elt(v_7999, 32); // dummy
#ifdef RECORD_GET
             if (v_7999 != SPID_NOPROP)
                record_get(elt(fastget_names, 32), 1);
             else record_get(elt(fastget_names, 32), 0),
                v_7999 = nil; }
           else record_get(elt(fastget_names, 32), 0); }
#else
             if (v_7999 == SPID_NOPROP) v_7999 = nil; }}
#endif
    v_7999 = qcar(v_7999);
    goto v_7987;
v_7988:
    if (!symbolp(v_7998)) v_7998 = nil;
    else { v_7998 = qfastgets(v_7998);
           if (v_7998 != nil) { v_7998 = elt(v_7998, 32); // dummy
#ifdef RECORD_GET
             if (v_7998 != SPID_NOPROP)
                record_get(elt(fastget_names, 32), 1);
             else record_get(elt(fastget_names, 32), 0),
                v_7998 = nil; }
           else record_get(elt(fastget_names, 32), 0); }
#else
             if (v_7998 == SPID_NOPROP) v_7998 = nil; }}
#endif
    v_7998 = qcar(v_7998);
    goto v_7989;
v_7990:
    goto v_7986;
v_7987:
    goto v_7988;
v_7989:
    v_7998 = (v_7999 == v_7998 ? lisp_true : nil);
    goto v_7979;
    v_7998 = nil;
v_7979:
    return onevalue(v_7998);
}



// Code for ra_budan!-0!-1

static LispObject CC_ra_budanK0K1(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_8056, v_8057;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7975);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_8057 = v_7975;
// end of prologue
    v_8056 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_8056;
    v_8056 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_8056;
    v_8056 = v_8057;
    fn = elt(env, 1); // ra_budan!-transform
    v_8056 = (*qfn1(fn))(fn, v_8056);
    env = stack[-4];
    stack[-3] = v_8056;
v_7991:
    v_8056 = stack[-3];
    if (v_8056 == nil) goto v_7994;
    else goto v_7995;
v_7994:
    goto v_7990;
v_7995:
    v_8056 = stack[-3];
    if (!consp(v_8056)) goto v_8004;
    else goto v_8005;
v_8004:
    v_8056 = lisp_true;
    goto v_8003;
v_8005:
    v_8056 = stack[-3];
    v_8056 = qcar(v_8056);
    v_8056 = (consp(v_8056) ? nil : lisp_true);
    goto v_8003;
    v_8056 = nil;
v_8003:
    if (v_8056 == nil) goto v_8001;
    v_8056 = stack[-3];
    v_8057 = v_8056;
    v_8056 = nil;
    stack[-3] = v_8056;
    goto v_7999;
v_8001:
    v_8056 = stack[-3];
    v_8056 = qcar(v_8056);
    v_8056 = qcdr(v_8056);
    v_8057 = v_8056;
    v_8056 = stack[-3];
    v_8056 = qcdr(v_8056);
    stack[-3] = v_8056;
    goto v_7999;
v_7999:
    v_8056 = v_8057;
    fn = elt(env, 2); // minusf
    v_8056 = (*qfn1(fn))(fn, v_8056);
    env = stack[-4];
    if (v_8056 == nil) goto v_8025;
    v_8056 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_8023;
v_8025:
    v_8056 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8023;
    v_8056 = nil;
v_8023:
    stack[-2] = v_8056;
    goto v_8041;
v_8037:
    goto v_8047;
v_8043:
    v_8057 = stack[-2];
    goto v_8044;
v_8045:
    v_8056 = stack[-1];
    goto v_8046;
v_8047:
    goto v_8043;
v_8044:
    goto v_8045;
v_8046:
    v_8057 = times2(v_8057, v_8056);
    env = stack[-4];
    goto v_8038;
v_8039:
    v_8056 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8040;
v_8041:
    goto v_8037;
v_8038:
    goto v_8039;
v_8040:
    v_8056 = (LispObject)lessp2(v_8057, v_8056);
    v_8056 = v_8056 ? lisp_true : nil;
    env = stack[-4];
    if (v_8056 == nil) goto v_8035;
    v_8056 = stack[0];
    v_8056 = add1(v_8056);
    env = stack[-4];
    stack[0] = v_8056;
    goto v_8033;
v_8035:
v_8033:
    v_8056 = stack[-2];
    stack[-1] = v_8056;
    goto v_7991;
v_7990:
    v_8056 = stack[0];
    return onevalue(v_8056);
}



// Code for lexer_word_continues

static LispObject CC_lexer_word_continues(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_8073, v_8074;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7975);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_7975;
// end of prologue
    v_8073 = stack[0];
    v_8073 = Lalpha_char_p(nil, v_8073);
    env = stack[-1];
    if (v_8073 == nil) goto v_7979;
    else goto v_7978;
v_7979:
    v_8073 = stack[0];
    v_8073 = Ldigitp(nil, v_8073);
    env = stack[-1];
    if (v_8073 == nil) goto v_7984;
    else goto v_7983;
v_7984:
    goto v_7999;
v_7995:
    v_8074 = stack[0];
    goto v_7996;
v_7997:
    v_8073 = elt(env, 1); // !_
    goto v_7998;
v_7999:
    goto v_7995;
v_7996:
    goto v_7997;
v_7998:
    if (v_8074 == v_8073) goto v_7993;
    else goto v_7994;
v_7993:
    goto v_8008;
v_8004:
    v_8074 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_8005;
v_8006:
    v_8073 = (LispObject)262144+TAG_FIXNUM; // 16384
    goto v_8007;
v_8008:
    goto v_8004;
v_8005:
    goto v_8006;
v_8007:
    fn = elt(env, 5); // land
    v_8073 = (*qfn2(fn))(fn, v_8074, v_8073);
    env = stack[-1];
    v_8073 = (LispObject)zerop(v_8073);
    v_8073 = v_8073 ? lisp_true : nil;
    env = stack[-1];
    v_8073 = (v_8073 == nil ? lisp_true : nil);
    goto v_7992;
v_7994:
    v_8073 = nil;
    goto v_7992;
    v_8073 = nil;
v_7992:
    if (v_8073 == nil) goto v_7990;
    v_8073 = lisp_true;
    goto v_7988;
v_7990:
    goto v_8030;
v_8026:
    v_8074 = stack[0];
    goto v_8027;
v_8028:
    v_8073 = elt(env, 3); // !.
    goto v_8029;
v_8030:
    goto v_8026;
v_8027:
    goto v_8028;
v_8029:
    if (v_8074 == v_8073) goto v_8024;
    else goto v_8025;
v_8024:
    goto v_8039;
v_8035:
    v_8074 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_8036;
v_8037:
    v_8073 = (LispObject)8388608+TAG_FIXNUM; // 524288
    goto v_8038;
v_8039:
    goto v_8035;
v_8036:
    goto v_8037;
v_8038:
    fn = elt(env, 5); // land
    v_8073 = (*qfn2(fn))(fn, v_8074, v_8073);
    env = stack[-1];
    v_8073 = (LispObject)zerop(v_8073);
    v_8073 = v_8073 ? lisp_true : nil;
    env = stack[-1];
    v_8073 = (v_8073 == nil ? lisp_true : nil);
    goto v_8023;
v_8025:
    v_8073 = nil;
    goto v_8023;
    v_8073 = nil;
v_8023:
    if (v_8073 == nil) goto v_8021;
    v_8073 = lisp_true;
    goto v_8019;
v_8021:
    goto v_8057;
v_8053:
    v_8074 = stack[0];
    goto v_8054;
v_8055:
    v_8073 = elt(env, 4); // !'
    goto v_8056;
v_8057:
    goto v_8053;
v_8054:
    goto v_8055;
v_8056:
    if (v_8074 == v_8073) goto v_8051;
    else goto v_8052;
v_8051:
    goto v_8066;
v_8062:
    v_8074 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_8063;
v_8064:
    v_8073 = (LispObject)1048576+TAG_FIXNUM; // 65536
    goto v_8065;
v_8066:
    goto v_8062;
v_8063:
    goto v_8064;
v_8065:
    fn = elt(env, 5); // land
    v_8073 = (*qfn2(fn))(fn, v_8074, v_8073);
    env = stack[-1];
    v_8073 = (LispObject)zerop(v_8073);
    v_8073 = v_8073 ? lisp_true : nil;
    v_8073 = (v_8073 == nil ? lisp_true : nil);
    goto v_8050;
v_8052:
    v_8073 = nil;
    goto v_8050;
    v_8073 = nil;
v_8050:
    goto v_8019;
    v_8073 = nil;
v_8019:
    goto v_7988;
    v_8073 = nil;
v_7988:
v_7983:
v_7978:
    return onevalue(v_8073);
}



// Code for aex_varl

static LispObject CC_aex_varl(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_7981;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7975);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7981 = v_7975;
// end of prologue
    fn = elt(env, 1); // aex_ex
    v_7981 = (*qfn1(fn))(fn, v_7981);
    env = stack[0];
    v_7981 = qcar(v_7981);
    {
        fn = elt(env, 2); // kernels
        return (*qfn1(fn))(fn, v_7981);
    }
}



// Code for ofsf_entry2at1

static LispObject CC_ofsf_entry2at1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8014, v_8015, v_8016;
    LispObject fn;
    LispObject v_7977, v_7976, v_7975;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_entry2at1");
    va_start(aa, nargs);
    v_7975 = va_arg(aa, LispObject);
    v_7976 = va_arg(aa, LispObject);
    v_7977 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7977,v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7975,v_7976,v_7977);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7977;
    stack[-1] = v_7976;
    v_8014 = v_7975;
// end of prologue
    goto v_7986;
v_7980:
    goto v_7992;
v_7988:
    v_8015 = stack[-1];
    v_8016 = qcar(v_8015);
    goto v_7989;
v_7990:
    goto v_7999;
v_7995:
    v_8015 = v_8014;
    goto v_7996;
v_7997:
    v_8014 = elt(env, 1); // and
    goto v_7998;
v_7999:
    goto v_7995;
v_7996:
    goto v_7997;
v_7998:
    v_8014 = (v_8015 == v_8014 ? lisp_true : nil);
    goto v_7991;
v_7992:
    goto v_7988;
v_7989:
    goto v_7990;
v_7991:
    fn = elt(env, 2); // ofsf_clnegrel
    stack[-2] = (*qfn2(fn))(fn, v_8016, v_8014);
    env = stack[-3];
    goto v_7981;
v_7982:
    goto v_8008;
v_8004:
    v_8015 = stack[0];
    goto v_8005;
v_8006:
    v_8014 = stack[-1];
    v_8014 = qcdr(v_8014);
    goto v_8007;
v_8008:
    goto v_8004;
v_8005:
    goto v_8006;
v_8007:
    fn = elt(env, 3); // addsq
    v_8014 = (*qfn2(fn))(fn, v_8015, v_8014);
    v_8015 = qcar(v_8014);
    goto v_7983;
v_7984:
    v_8014 = nil;
    goto v_7985;
v_7986:
    goto v_7980;
v_7981:
    goto v_7982;
v_7983:
    goto v_7984;
v_7985:
    {
        LispObject v_8020 = stack[-2];
        return list3(v_8020, v_8015, v_8014);
    }
}



// Code for intexprlisp

static LispObject CC_intexprlisp(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8011, v_8012;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7976;
    stack[-1] = v_7975;
// end of prologue
v_7974:
    v_8011 = stack[-1];
    if (v_8011 == nil) goto v_7980;
    else goto v_7981;
v_7980:
    v_8011 = lisp_true;
    goto v_7979;
v_7981:
    goto v_7995;
v_7991:
    v_8011 = stack[-1];
    v_8012 = qcar(v_8011);
    goto v_7992;
v_7993:
    v_8011 = stack[0];
    goto v_7994;
v_7995:
    goto v_7991;
v_7992:
    goto v_7993;
v_7994:
    fn = elt(env, 1); // intexprnp
    v_8011 = (*qfn2(fn))(fn, v_8012, v_8011);
    env = stack[-2];
    if (v_8011 == nil) goto v_7988;
    else goto v_7989;
v_7988:
    v_8011 = nil;
    goto v_7987;
v_7989:
    goto v_8007;
v_8003:
    v_8011 = stack[-1];
    v_8012 = qcdr(v_8011);
    goto v_8004;
v_8005:
    v_8011 = stack[0];
    goto v_8006;
v_8007:
    goto v_8003;
v_8004:
    goto v_8005;
v_8006:
    stack[-1] = v_8012;
    stack[0] = v_8011;
    goto v_7974;
    v_8011 = nil;
v_7987:
    goto v_7979;
    v_8011 = nil;
v_7979:
    return onevalue(v_8011);
}



// Code for ibalp_var!-satlist

static LispObject CC_ibalp_varKsatlist(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8215, v_8216;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_7976;
    v_8215 = v_7975;
// end of prologue
    stack[-5] = v_8215;
v_7981:
    v_8215 = stack[-5];
    if (v_8215 == nil) goto v_7985;
    else goto v_7986;
v_7985:
    v_8215 = nil;
    goto v_7980;
v_7986:
    v_8215 = stack[-5];
    v_8215 = qcar(v_8215);
    stack[-3] = v_8215;
    v_8215 = stack[-3];
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcar(v_8215);
    if (v_8215 == nil) goto v_7994;
    else goto v_7995;
v_7994:
    v_8215 = stack[-3];
    v_8215 = qcar(v_8215);
    stack[-2] = v_8215;
v_8005:
    v_8215 = stack[-2];
    if (v_8215 == nil) goto v_8010;
    else goto v_8011;
v_8010:
    goto v_8004;
v_8011:
    v_8215 = stack[-2];
    v_8215 = qcar(v_8215);
    stack[-1] = v_8215;
    goto v_8022;
v_8018:
    v_8215 = stack[-1];
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    stack[0] = qcdr(v_8215);
    goto v_8019;
v_8020:
    v_8215 = stack[-1];
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcar(v_8215);
    v_8215 = sub1(v_8215);
    env = stack[-6];
    goto v_8021;
v_8022:
    goto v_8018;
v_8019:
    goto v_8020;
v_8021:
    fn = elt(env, 1); // setcar
    v_8215 = (*qfn2(fn))(fn, stack[0], v_8215);
    env = stack[-6];
    goto v_8040;
v_8036:
    v_8215 = stack[-1];
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    stack[0] = qcdr(v_8215);
    goto v_8037;
v_8038:
    v_8215 = stack[-1];
    fn = elt(env, 2); // ibalp_calcmom
    v_8215 = (*qfn1(fn))(fn, v_8215);
    env = stack[-6];
    goto v_8039;
v_8040:
    goto v_8036;
v_8037:
    goto v_8038;
v_8039:
    fn = elt(env, 1); // setcar
    v_8215 = (*qfn2(fn))(fn, stack[0], v_8215);
    env = stack[-6];
    v_8215 = stack[-2];
    v_8215 = qcdr(v_8215);
    stack[-2] = v_8215;
    goto v_8005;
v_8004:
    v_8215 = stack[-3];
    v_8215 = qcdr(v_8215);
    v_8215 = qcar(v_8215);
    stack[-2] = v_8215;
v_8060:
    v_8215 = stack[-2];
    if (v_8215 == nil) goto v_8066;
    else goto v_8067;
v_8066:
    goto v_8059;
v_8067:
    v_8215 = stack[-2];
    v_8215 = qcar(v_8215);
    stack[-1] = v_8215;
    goto v_8078;
v_8074:
    v_8215 = stack[-1];
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    stack[0] = qcdr(v_8215);
    goto v_8075;
v_8076:
    v_8215 = stack[-1];
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcar(v_8215);
    v_8215 = sub1(v_8215);
    env = stack[-6];
    goto v_8077;
v_8078:
    goto v_8074;
v_8075:
    goto v_8076;
v_8077:
    fn = elt(env, 1); // setcar
    v_8215 = (*qfn2(fn))(fn, stack[0], v_8215);
    env = stack[-6];
    goto v_8098;
v_8094:
    v_8215 = stack[-1];
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    stack[0] = qcdr(v_8215);
    goto v_8095;
v_8096:
    v_8215 = stack[-1];
    fn = elt(env, 2); // ibalp_calcmom
    v_8215 = (*qfn1(fn))(fn, v_8215);
    env = stack[-6];
    goto v_8097;
v_8098:
    goto v_8094;
v_8095:
    goto v_8096;
v_8097:
    fn = elt(env, 1); // setcar
    v_8215 = (*qfn2(fn))(fn, stack[0], v_8215);
    env = stack[-6];
    v_8215 = stack[-2];
    v_8215 = qcdr(v_8215);
    stack[-2] = v_8215;
    goto v_8060;
v_8059:
    v_8215 = stack[-3];
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcar(v_8215);
    stack[-1] = v_8215;
v_8118:
    v_8215 = stack[-1];
    if (v_8215 == nil) goto v_8129;
    else goto v_8130;
v_8129:
    goto v_8117;
v_8130:
    v_8215 = stack[-1];
    v_8215 = qcar(v_8215);
    goto v_8141;
v_8137:
    v_8216 = v_8215;
    v_8216 = qcdr(v_8216);
    v_8216 = qcdr(v_8216);
    v_8216 = qcdr(v_8216);
    v_8216 = qcdr(v_8216);
    v_8216 = qcdr(v_8216);
    v_8216 = qcdr(v_8216);
    v_8216 = qcdr(v_8216);
    v_8216 = qcdr(v_8216);
    v_8216 = qcdr(v_8216);
    stack[0] = qcdr(v_8216);
    goto v_8138;
v_8139:
    goto v_8158;
v_8154:
    v_8216 = stack[-3];
    goto v_8155;
v_8156:
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcar(v_8215);
    goto v_8157;
v_8158:
    goto v_8154;
v_8155:
    goto v_8156;
v_8157:
    fn = elt(env, 3); // lto_delq
    v_8215 = (*qfn2(fn))(fn, v_8216, v_8215);
    env = stack[-6];
    goto v_8140;
v_8141:
    goto v_8137;
v_8138:
    goto v_8139;
v_8140:
    fn = elt(env, 1); // setcar
    v_8215 = (*qfn2(fn))(fn, stack[0], v_8215);
    env = stack[-6];
    v_8215 = stack[-1];
    v_8215 = qcdr(v_8215);
    stack[-1] = v_8215;
    goto v_8118;
v_8117:
    goto v_8179;
v_8175:
    v_8215 = stack[-3];
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8216 = qcdr(v_8215);
    goto v_8176;
v_8177:
    v_8215 = nil;
    goto v_8178;
v_8179:
    goto v_8175;
v_8176:
    goto v_8177;
v_8178:
    fn = elt(env, 1); // setcar
    v_8215 = (*qfn2(fn))(fn, v_8216, v_8215);
    env = stack[-6];
    goto v_7993;
v_7995:
v_7993:
    goto v_8194;
v_8190:
    v_8215 = stack[-3];
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    stack[0] = qcdr(v_8215);
    goto v_8191;
v_8192:
    goto v_8205;
v_8201:
    v_8216 = stack[-4];
    goto v_8202;
v_8203:
    v_8215 = stack[-3];
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcdr(v_8215);
    v_8215 = qcar(v_8215);
    goto v_8204;
v_8205:
    goto v_8201;
v_8202:
    goto v_8203;
v_8204:
    v_8215 = cons(v_8216, v_8215);
    env = stack[-6];
    goto v_8193;
v_8194:
    goto v_8190;
v_8191:
    goto v_8192;
v_8193:
    fn = elt(env, 1); // setcar
    v_8215 = (*qfn2(fn))(fn, stack[0], v_8215);
    env = stack[-6];
    v_8215 = stack[-5];
    v_8215 = qcdr(v_8215);
    stack[-5] = v_8215;
    goto v_7981;
v_7980:
    return onevalue(v_8215);
}



// Code for gb_buch!-ev_divides!?

static LispObject CC_gb_buchKev_dividesW(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_7986, v_7987;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7987 = v_7976;
    v_7986 = v_7975;
// end of prologue
    goto v_7983;
v_7979:
    goto v_7980;
v_7981:
    goto v_7982;
v_7983:
    goto v_7979;
v_7980:
    goto v_7981;
v_7982:
    {
        fn = elt(env, 1); // ev_mtest!?
        return (*qfn2(fn))(fn, v_7987, v_7986);
    }
}



// Code for matsm!*1

static LispObject CC_matsmH1(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_8114, v_8115;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7975);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    v_8114 = v_7975;
// end of prologue
    goto v_7984;
v_7980:
    stack[-8] = elt(env, 1); // mat
    goto v_7981;
v_7982:
    stack[-7] = v_8114;
    v_8114 = stack[-7];
    if (v_8114 == nil) goto v_7995;
    else goto v_7996;
v_7995:
    v_8114 = nil;
    goto v_7990;
v_7996:
    v_8114 = stack[-7];
    v_8114 = qcar(v_8114);
    stack[-3] = v_8114;
    v_8114 = stack[-3];
    if (v_8114 == nil) goto v_8012;
    else goto v_8013;
v_8012:
    v_8114 = nil;
    goto v_8007;
v_8013:
    v_8114 = stack[-3];
    v_8114 = qcar(v_8114);
    fn = elt(env, 3); // subs2!*
    v_8114 = (*qfn1(fn))(fn, v_8114);
    env = stack[-9];
    fn = elt(env, 4); // !*q2a
    v_8114 = (*qfn1(fn))(fn, v_8114);
    env = stack[-9];
    v_8114 = ncons(v_8114);
    env = stack[-9];
    stack[-1] = v_8114;
    stack[-2] = v_8114;
v_8008:
    v_8114 = stack[-3];
    v_8114 = qcdr(v_8114);
    stack[-3] = v_8114;
    v_8114 = stack[-3];
    if (v_8114 == nil) goto v_8027;
    else goto v_8028;
v_8027:
    v_8114 = stack[-2];
    goto v_8007;
v_8028:
    goto v_8036;
v_8032:
    stack[0] = stack[-1];
    goto v_8033;
v_8034:
    v_8114 = stack[-3];
    v_8114 = qcar(v_8114);
    fn = elt(env, 3); // subs2!*
    v_8114 = (*qfn1(fn))(fn, v_8114);
    env = stack[-9];
    fn = elt(env, 4); // !*q2a
    v_8114 = (*qfn1(fn))(fn, v_8114);
    env = stack[-9];
    v_8114 = ncons(v_8114);
    env = stack[-9];
    goto v_8035;
v_8036:
    goto v_8032;
v_8033:
    goto v_8034;
v_8035:
    v_8114 = Lrplacd(nil, stack[0], v_8114);
    env = stack[-9];
    v_8114 = stack[-1];
    v_8114 = qcdr(v_8114);
    stack[-1] = v_8114;
    goto v_8008;
v_8007:
    v_8114 = ncons(v_8114);
    env = stack[-9];
    stack[-5] = v_8114;
    stack[-6] = v_8114;
v_7991:
    v_8114 = stack[-7];
    v_8114 = qcdr(v_8114);
    stack[-7] = v_8114;
    v_8114 = stack[-7];
    if (v_8114 == nil) goto v_8051;
    else goto v_8052;
v_8051:
    v_8114 = stack[-6];
    goto v_7990;
v_8052:
    goto v_8060;
v_8056:
    stack[-4] = stack[-5];
    goto v_8057;
v_8058:
    v_8114 = stack[-7];
    v_8114 = qcar(v_8114);
    stack[-3] = v_8114;
    v_8114 = stack[-3];
    if (v_8114 == nil) goto v_8075;
    else goto v_8076;
v_8075:
    v_8114 = nil;
    goto v_8070;
v_8076:
    v_8114 = stack[-3];
    v_8114 = qcar(v_8114);
    fn = elt(env, 3); // subs2!*
    v_8114 = (*qfn1(fn))(fn, v_8114);
    env = stack[-9];
    fn = elt(env, 4); // !*q2a
    v_8114 = (*qfn1(fn))(fn, v_8114);
    env = stack[-9];
    v_8114 = ncons(v_8114);
    env = stack[-9];
    stack[-1] = v_8114;
    stack[-2] = v_8114;
v_8071:
    v_8114 = stack[-3];
    v_8114 = qcdr(v_8114);
    stack[-3] = v_8114;
    v_8114 = stack[-3];
    if (v_8114 == nil) goto v_8090;
    else goto v_8091;
v_8090:
    v_8114 = stack[-2];
    goto v_8070;
v_8091:
    goto v_8099;
v_8095:
    stack[0] = stack[-1];
    goto v_8096;
v_8097:
    v_8114 = stack[-3];
    v_8114 = qcar(v_8114);
    fn = elt(env, 3); // subs2!*
    v_8114 = (*qfn1(fn))(fn, v_8114);
    env = stack[-9];
    fn = elt(env, 4); // !*q2a
    v_8114 = (*qfn1(fn))(fn, v_8114);
    env = stack[-9];
    v_8114 = ncons(v_8114);
    env = stack[-9];
    goto v_8098;
v_8099:
    goto v_8095;
v_8096:
    goto v_8097;
v_8098:
    v_8114 = Lrplacd(nil, stack[0], v_8114);
    env = stack[-9];
    v_8114 = stack[-1];
    v_8114 = qcdr(v_8114);
    stack[-1] = v_8114;
    goto v_8071;
v_8070:
    v_8114 = ncons(v_8114);
    env = stack[-9];
    goto v_8059;
v_8060:
    goto v_8056;
v_8057:
    goto v_8058;
v_8059:
    v_8114 = Lrplacd(nil, stack[-4], v_8114);
    env = stack[-9];
    v_8114 = stack[-5];
    v_8114 = qcdr(v_8114);
    stack[-5] = v_8114;
    goto v_7991;
v_7990:
    goto v_7983;
v_7984:
    goto v_7980;
v_7981:
    goto v_7982;
v_7983:
    v_8114 = cons(stack[-8], v_8114);
    env = stack[-9];
    v_8115 = nil;
    qvalue(elt(env, 2)) = v_8115; // !*sub2
    return onevalue(v_8114);
}



// Code for maxtype

static LispObject CC_maxtype(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_7995, v_7996;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7975);
    }
// copy arguments values to proper place
    v_7996 = v_7975;
// end of prologue
    v_7995 = v_7996;
    if (!consp(v_7995)) goto v_7979;
    else goto v_7980;
v_7979:
    v_7995 = v_7996;
    goto v_7978;
v_7980:
    v_7995 = v_7996;
    v_7995 = qcdr(v_7995);
    v_7995 = Lconsp(nil, v_7995);
    if (v_7995 == nil) goto v_7984;
    v_7995 = v_7996;
    v_7995 = qcdr(v_7995);
    v_7995 = qcar(v_7995);
    goto v_7978;
v_7984:
    v_7995 = v_7996;
    v_7995 = qcar(v_7995);
    goto v_7978;
    v_7995 = nil;
v_7978:
    return onevalue(v_7995);
}



// Code for bind

static LispObject CC_bind(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_7997, v_7998;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7998 = v_7976;
    v_7997 = v_7975;
// end of prologue
    goto v_7985;
v_7979:
    stack[-1] = v_7997;
    goto v_7980;
v_7981:
    stack[0] = elt(env, 1); // binding
    goto v_7982;
v_7983:
    goto v_7993;
v_7989:
    goto v_7990;
v_7991:
    if (!symbolp(v_7997)) v_7997 = nil;
    else { v_7997 = qfastgets(v_7997);
           if (v_7997 != nil) { v_7997 = elt(v_7997, 13); // binding
#ifdef RECORD_GET
             if (v_7997 != SPID_NOPROP)
                record_get(elt(fastget_names, 13), 1);
             else record_get(elt(fastget_names, 13), 0),
                v_7997 = nil; }
           else record_get(elt(fastget_names, 13), 0); }
#else
             if (v_7997 == SPID_NOPROP) v_7997 = nil; }}
#endif
    goto v_7992;
v_7993:
    goto v_7989;
v_7990:
    goto v_7991;
v_7992:
    v_7997 = cons(v_7998, v_7997);
    goto v_7984;
v_7985:
    goto v_7979;
v_7980:
    goto v_7981;
v_7982:
    goto v_7983;
v_7984:
    {
        LispObject v_8001 = stack[-1];
        LispObject v_8002 = stack[0];
        return Lputprop(nil, 3, v_8001, v_8002, v_7997);
    }
}



// Code for triviallcm

static LispObject CC_triviallcm(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7994, v_7995;
    LispObject fn;
    LispObject v_7977, v_7976, v_7975;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "triviallcm");
    va_start(aa, nargs);
    v_7975 = va_arg(aa, LispObject);
    v_7976 = va_arg(aa, LispObject);
    v_7977 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7977,v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7975,v_7976,v_7977);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_7977;
    v_7995 = v_7976;
    v_7994 = v_7975;
// end of prologue
    goto v_7983;
v_7979:
    goto v_7989;
v_7985:
    goto v_7986;
v_7987:
    goto v_7988;
v_7989:
    goto v_7985;
v_7986:
    goto v_7987;
v_7988:
    fn = elt(env, 1); // xdiv
    v_7995 = (*qfn2(fn))(fn, v_7995, v_7994);
    goto v_7980;
v_7981:
    v_7994 = stack[0];
    goto v_7982;
v_7983:
    goto v_7979;
v_7980:
    goto v_7981;
v_7982:
    v_7994 = (equal(v_7995, v_7994) ? lisp_true : nil);
    return onevalue(v_7994);
}



// Code for aminusp!:1

static LispObject CC_aminuspT1(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_8095, v_8096, v_8097, v_8098;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7975);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_7975;
// end of prologue
    v_8095 = stack[-1];
    fn = elt(env, 4); // aeval!*
    v_8095 = (*qfn1(fn))(fn, v_8095);
    env = stack[-3];
    stack[-1] = v_8095;
    v_8095 = stack[-1];
    stack[-2] = v_8095;
    v_8095 = stack[-2];
    v_8095 = integerp(v_8095);
    if (v_8095 == nil) goto v_7986;
    v_8095 = stack[-2];
        return Lminusp(nil, v_8095);
v_7986:
    goto v_7998;
v_7994:
    v_8096 = stack[-2];
    goto v_7995;
v_7996:
    v_8095 = elt(env, 1); // !*sq
    goto v_7997;
v_7998:
    goto v_7994;
v_7995:
    goto v_7996;
v_7997:
    if (!consp(v_8096)) goto v_7991;
    v_8096 = qcar(v_8096);
    if (v_8096 == v_8095) goto v_7992;
v_7991:
    goto v_8012;
v_8002:
    stack[0] = nil;
    goto v_8003;
v_8004:
    v_8095 = stack[-1];
    fn = elt(env, 5); // reval
    v_8098 = (*qfn1(fn))(fn, v_8095);
    env = stack[-3];
    goto v_8005;
v_8006:
    v_8097 = elt(env, 2); // "invalid in FOR statement"
    goto v_8007;
v_8008:
    v_8096 = nil;
    goto v_8009;
v_8010:
    v_8095 = lisp_true;
    goto v_8011;
v_8012:
    goto v_8002;
v_8003:
    goto v_8004;
v_8005:
    goto v_8006;
v_8007:
    goto v_8008;
v_8009:
    goto v_8010;
v_8011:
    fn = elt(env, 6); // msgpri
    v_8095 = (*qfnn(fn))(fn, 5, stack[0], v_8098, v_8097, v_8096, v_8095);
    env = stack[-3];
    goto v_7984;
v_7992:
v_7984:
    v_8095 = stack[-2];
    v_8095 = qcdr(v_8095);
    v_8095 = qcar(v_8095);
    stack[-2] = v_8095;
    v_8095 = stack[-2];
    v_8095 = qcar(v_8095);
    v_8095 = integerp(v_8095);
    if (v_8095 == nil) goto v_8025;
    v_8095 = stack[-2];
    v_8095 = qcdr(v_8095);
    v_8095 = integerp(v_8095);
    if (v_8095 == nil) goto v_8025;
    v_8095 = stack[-2];
    v_8095 = qcar(v_8095);
        return Lminusp(nil, v_8095);
v_8025:
    goto v_8047;
v_8043:
    v_8095 = stack[-2];
    v_8096 = qcdr(v_8095);
    goto v_8044;
v_8045:
    v_8095 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8046;
v_8047:
    goto v_8043;
v_8044:
    goto v_8045;
v_8046:
    if (v_8096 == v_8095) goto v_8042;
    v_8095 = lisp_true;
    goto v_8040;
v_8042:
    v_8095 = stack[-2];
    v_8095 = qcar(v_8095);
    stack[-2] = v_8095;
    if (!consp(v_8095)) goto v_8056;
    else goto v_8057;
v_8056:
    v_8095 = lisp_true;
    goto v_8055;
v_8057:
    v_8095 = stack[-2];
    v_8095 = qcar(v_8095);
    v_8095 = (consp(v_8095) ? nil : lisp_true);
    goto v_8055;
    v_8095 = nil;
v_8055:
    v_8095 = (v_8095 == nil ? lisp_true : nil);
    goto v_8040;
    v_8095 = nil;
v_8040:
    if (v_8095 == nil) goto v_8038;
    goto v_8078;
v_8068:
    stack[0] = nil;
    goto v_8069;
v_8070:
    v_8095 = stack[-1];
    fn = elt(env, 5); // reval
    v_8098 = (*qfn1(fn))(fn, v_8095);
    env = stack[-3];
    goto v_8071;
v_8072:
    v_8097 = elt(env, 2); // "invalid in FOR statement"
    goto v_8073;
v_8074:
    v_8096 = nil;
    goto v_8075;
v_8076:
    v_8095 = lisp_true;
    goto v_8077;
v_8078:
    goto v_8068;
v_8069:
    goto v_8070;
v_8071:
    goto v_8072;
v_8073:
    goto v_8074;
v_8075:
    goto v_8076;
v_8077:
    fn = elt(env, 6); // msgpri
    v_8095 = (*qfnn(fn))(fn, 5, stack[0], v_8098, v_8097, v_8096, v_8095);
    goto v_8023;
v_8038:
    goto v_8092;
v_8088:
    v_8096 = elt(env, 3); // !:minusp
    goto v_8089;
v_8090:
    v_8095 = stack[-2];
    goto v_8091;
v_8092:
    goto v_8088;
v_8089:
    goto v_8090;
v_8091:
        return Lapply1(nil, v_8096, v_8095);
v_8023:
    v_8095 = nil;
    return onevalue(v_8095);
}



// Code for groeb!=better

static LispObject CC_groebMbetter(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8040, v_8041;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7976;
    stack[-1] = v_7975;
// end of prologue
    goto v_7987;
v_7983:
    v_8040 = stack[-1];
    v_8040 = qcdr(v_8040);
    v_8041 = qcar(v_8040);
    goto v_7984;
v_7985:
    v_8040 = stack[0];
    v_8040 = qcdr(v_8040);
    v_8040 = qcar(v_8040);
    goto v_7986;
v_7987:
    goto v_7983;
v_7984:
    goto v_7985;
v_7986:
    v_8040 = (LispObject)lessp2(v_8041, v_8040);
    v_8040 = v_8040 ? lisp_true : nil;
    env = stack[-2];
    if (v_8040 == nil) goto v_7981;
    v_8040 = lisp_true;
    goto v_7979;
v_7981:
    goto v_8001;
v_7997:
    v_8040 = stack[-1];
    v_8040 = qcdr(v_8040);
    v_8041 = qcar(v_8040);
    goto v_7998;
v_7999:
    v_8040 = stack[0];
    v_8040 = qcdr(v_8040);
    v_8040 = qcar(v_8040);
    goto v_8000;
v_8001:
    goto v_7997;
v_7998:
    goto v_7999;
v_8000:
    if (equal(v_8041, v_8040)) goto v_7995;
    else goto v_7996;
v_7995:
    goto v_8013;
v_8009:
    goto v_8019;
v_8015:
    goto v_8025;
v_8021:
    v_8041 = stack[-1];
    goto v_8022;
v_8023:
    v_8040 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_8024;
v_8025:
    goto v_8021;
v_8022:
    goto v_8023;
v_8024:
    fn = elt(env, 1); // nth
    stack[-1] = (*qfn2(fn))(fn, v_8041, v_8040);
    env = stack[-2];
    goto v_8016;
v_8017:
    goto v_8033;
v_8029:
    v_8041 = stack[0];
    goto v_8030;
v_8031:
    v_8040 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_8032;
v_8033:
    goto v_8029;
v_8030:
    goto v_8031;
v_8032:
    fn = elt(env, 1); // nth
    v_8040 = (*qfn2(fn))(fn, v_8041, v_8040);
    env = stack[-2];
    goto v_8018;
v_8019:
    goto v_8015;
v_8016:
    goto v_8017;
v_8018:
    fn = elt(env, 2); // mo_compare
    v_8041 = (*qfn2(fn))(fn, stack[-1], v_8040);
    goto v_8010;
v_8011:
    v_8040 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8012;
v_8013:
    goto v_8009;
v_8010:
    goto v_8011;
v_8012:
        return Lleq(nil, v_8041, v_8040);
v_7996:
    v_8040 = nil;
    goto v_7979;
    v_8040 = nil;
v_7979:
    return onevalue(v_8040);
}



// Code for dcombine

static LispObject CC_dcombine(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8471, v_8472, v_8473;
    LispObject fn;
    LispObject v_7977, v_7976, v_7975;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dcombine");
    va_start(aa, nargs);
    v_7975 = va_arg(aa, LispObject);
    v_7976 = va_arg(aa, LispObject);
    v_7977 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7977,v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7975,v_7976,v_7977);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_7977;
    stack[-4] = v_7976;
    stack[-5] = v_7975;
// end of prologue
    v_8471 = stack[-5];
    if (!consp(v_8471)) goto v_7981;
    else goto v_7982;
v_7981:
    goto v_7991;
v_7985:
    goto v_7997;
v_7993:
    v_8471 = stack[-4];
    v_8472 = qcar(v_8471);
    goto v_7994;
v_7995:
    v_8471 = stack[-3];
    goto v_7996;
v_7997:
    goto v_7993;
v_7994:
    goto v_7995;
v_7996:
    stack[0] = get(v_8472, v_8471);
    env = stack[-7];
    goto v_7986;
v_7987:
    goto v_8006;
v_8002:
    v_8471 = stack[-4];
    v_8471 = qcar(v_8471);
    if (!symbolp(v_8471)) v_8472 = nil;
    else { v_8472 = qfastgets(v_8471);
           if (v_8472 != nil) { v_8472 = elt(v_8472, 34); // i2d
#ifdef RECORD_GET
             if (v_8472 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_8472 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_8472 == SPID_NOPROP) v_8472 = nil; }}
#endif
    goto v_8003;
v_8004:
    v_8471 = stack[-5];
    goto v_8005;
v_8006:
    goto v_8002;
v_8003:
    goto v_8004;
v_8005:
    v_8472 = Lapply1(nil, v_8472, v_8471);
    env = stack[-7];
    goto v_7988;
v_7989:
    v_8471 = stack[-4];
    goto v_7990;
v_7991:
    goto v_7985;
v_7986:
    goto v_7987;
v_7988:
    goto v_7989;
v_7990:
    v_8471 = Lapply2(nil, 3, stack[0], v_8472, v_8471);
    env = stack[-7];
    goto v_7980;
v_7982:
    v_8471 = stack[-4];
    if (!consp(v_8471)) goto v_8012;
    else goto v_8013;
v_8012:
    goto v_8022;
v_8016:
    goto v_8028;
v_8024:
    v_8471 = stack[-5];
    v_8472 = qcar(v_8471);
    goto v_8025;
v_8026:
    v_8471 = stack[-3];
    goto v_8027;
v_8028:
    goto v_8024;
v_8025:
    goto v_8026;
v_8027:
    stack[-1] = get(v_8472, v_8471);
    env = stack[-7];
    goto v_8017;
v_8018:
    stack[0] = stack[-5];
    goto v_8019;
v_8020:
    goto v_8038;
v_8034:
    v_8471 = stack[-5];
    v_8471 = qcar(v_8471);
    if (!symbolp(v_8471)) v_8472 = nil;
    else { v_8472 = qfastgets(v_8471);
           if (v_8472 != nil) { v_8472 = elt(v_8472, 34); // i2d
#ifdef RECORD_GET
             if (v_8472 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_8472 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_8472 == SPID_NOPROP) v_8472 = nil; }}
#endif
    goto v_8035;
v_8036:
    v_8471 = stack[-4];
    goto v_8037;
v_8038:
    goto v_8034;
v_8035:
    goto v_8036;
v_8037:
    v_8471 = Lapply1(nil, v_8472, v_8471);
    env = stack[-7];
    goto v_8021;
v_8022:
    goto v_8016;
v_8017:
    goto v_8018;
v_8019:
    goto v_8020;
v_8021:
    v_8471 = Lapply2(nil, 3, stack[-1], stack[0], v_8471);
    env = stack[-7];
    goto v_7980;
v_8013:
    goto v_8049;
v_8045:
    v_8471 = stack[-5];
    v_8472 = qcar(v_8471);
    goto v_8046;
v_8047:
    v_8471 = stack[-4];
    v_8471 = qcar(v_8471);
    goto v_8048;
v_8049:
    goto v_8045;
v_8046:
    goto v_8047;
v_8048:
    if (v_8472 == v_8471) goto v_8043;
    else goto v_8044;
v_8043:
    goto v_8061;
v_8055:
    goto v_8067;
v_8063:
    v_8471 = stack[-5];
    v_8472 = qcar(v_8471);
    goto v_8064;
v_8065:
    v_8471 = stack[-3];
    goto v_8066;
v_8067:
    goto v_8063;
v_8064:
    goto v_8065;
v_8066:
    v_8473 = get(v_8472, v_8471);
    env = stack[-7];
    goto v_8056;
v_8057:
    v_8472 = stack[-5];
    goto v_8058;
v_8059:
    v_8471 = stack[-4];
    goto v_8060;
v_8061:
    goto v_8055;
v_8056:
    goto v_8057;
v_8058:
    goto v_8059;
v_8060:
    v_8471 = Lapply2(nil, 3, v_8473, v_8472, v_8471);
    env = stack[-7];
    goto v_7980;
v_8044:
    v_8471 = stack[-5];
    v_8472 = qcar(v_8471);
    v_8471 = stack[-4];
    v_8471 = qcar(v_8471);
    stack[-6] = v_8472;
    stack[-2] = v_8471;
    goto v_8086;
v_8082:
    v_8472 = stack[-6];
    goto v_8083;
v_8084:
    v_8471 = stack[-2];
    goto v_8085;
v_8086:
    goto v_8082;
v_8083:
    goto v_8084;
v_8085:
    v_8473 = get(v_8472, v_8471);
    env = stack[-7];
    v_8472 = elt(env, 1); // (!:crn!: !:gi!:)
    v_8471 = elt(env, 2); // (!:rd!: !:cr!:)
    stack[-1] = v_8473;
    stack[0] = v_8472;
    v_8473 = v_8471;
    v_8471 = stack[-1];
    if (v_8471 == nil) goto v_8101;
    v_8471 = stack[-1];
    if (!consp(v_8471)) goto v_8105;
    else goto v_8101;
v_8105:
    goto v_8102;
v_8101:
    v_8471 = lisp_true;
    goto v_8100;
v_8102:
    goto v_8121;
v_8117:
    v_8472 = stack[-6];
    goto v_8118;
v_8119:
    v_8471 = elt(env, 3); // cmpxfn
    goto v_8120;
v_8121:
    goto v_8117;
v_8118:
    goto v_8119;
v_8120:
    v_8471 = get(v_8472, v_8471);
    env = stack[-7];
    if (v_8471 == nil) goto v_8114;
    goto v_8130;
v_8126:
    v_8472 = stack[-2];
    goto v_8127;
v_8128:
    v_8471 = elt(env, 3); // cmpxfn
    goto v_8129;
v_8130:
    goto v_8126;
v_8127:
    goto v_8128;
v_8129:
    v_8471 = get(v_8472, v_8471);
    env = stack[-7];
    if (v_8471 == nil) goto v_8124;
    else goto v_8114;
v_8124:
    goto v_8113;
v_8114:
    goto v_8139;
v_8135:
    v_8472 = stack[-6];
    goto v_8136;
v_8137:
    v_8471 = v_8473;
    goto v_8138;
v_8139:
    goto v_8135;
v_8136:
    goto v_8137;
v_8138:
    v_8471 = Lmemq(nil, v_8472, v_8471);
    if (v_8471 == nil) goto v_8133;
    goto v_8148;
v_8144:
    v_8471 = stack[-2];
    goto v_8145;
v_8146:
    v_8472 = v_8473;
    goto v_8147;
v_8148:
    goto v_8144;
v_8145:
    goto v_8146;
v_8147:
    v_8471 = Lmemq(nil, v_8471, v_8472);
    if (v_8471 == nil) goto v_8143;
    else goto v_8133;
v_8143:
    goto v_8113;
v_8133:
    v_8471 = nil;
    goto v_8111;
v_8113:
    goto v_8160;
v_8156:
    v_8472 = stack[-2];
    goto v_8157;
v_8158:
    v_8471 = elt(env, 4); // !:ps!:
    goto v_8159;
v_8160:
    goto v_8156;
v_8157:
    goto v_8158;
v_8159:
    v_8471 = Lneq(nil, v_8472, v_8471);
    env = stack[-7];
    goto v_8111;
    v_8471 = nil;
v_8111:
    goto v_8100;
    v_8471 = nil;
v_8100:
    if (v_8471 == nil) goto v_8097;
    goto v_8169;
v_8165:
    v_8472 = stack[-2];
    goto v_8166;
v_8167:
    v_8471 = elt(env, 5); // noconvert
    goto v_8168;
v_8169:
    goto v_8165;
v_8166:
    goto v_8167;
v_8168:
    v_8471 = Lflagp(nil, v_8472, v_8471);
    env = stack[-7];
    if (v_8471 == nil) goto v_8163;
    else goto v_8097;
v_8163:
    goto v_8182;
v_8178:
    v_8472 = stack[-6];
    goto v_8179;
v_8180:
    v_8471 = stack[0];
    goto v_8181;
v_8182:
    goto v_8178;
v_8179:
    goto v_8180;
v_8181:
    v_8471 = Lmemq(nil, v_8472, v_8471);
    if (v_8471 == nil) goto v_8176;
    goto v_8191;
v_8187:
    v_8472 = stack[-2];
    goto v_8188;
v_8189:
    v_8471 = elt(env, 6); // !:rd!:
    goto v_8190;
v_8191:
    goto v_8187;
v_8188:
    goto v_8189;
v_8190:
    if (v_8472 == v_8471) goto v_8186;
    else goto v_8176;
v_8186:
    goto v_8174;
v_8176:
    goto v_8203;
v_8199:
    v_8472 = stack[-6];
    goto v_8200;
v_8201:
    v_8471 = elt(env, 6); // !:rd!:
    goto v_8202;
v_8203:
    goto v_8199;
v_8200:
    goto v_8201;
v_8202:
    if (v_8472 == v_8471) goto v_8197;
    else goto v_8198;
v_8197:
    goto v_8210;
v_8206:
    v_8472 = stack[-2];
    goto v_8207;
v_8208:
    v_8471 = stack[0];
    goto v_8209;
v_8210:
    goto v_8206;
v_8207:
    goto v_8208;
v_8209:
    v_8471 = Lmemq(nil, v_8472, v_8471);
    goto v_8196;
v_8198:
    v_8471 = nil;
    goto v_8196;
    v_8471 = nil;
v_8196:
    if (v_8471 == nil) goto v_8194;
    else goto v_8174;
v_8194:
    goto v_8175;
v_8174:
    goto v_8222;
v_8218:
    goto v_8228;
v_8224:
    v_8472 = stack[-6];
    goto v_8225;
v_8226:
    v_8471 = elt(env, 7); // !:cr!:
    goto v_8227;
v_8228:
    goto v_8224;
v_8225:
    goto v_8226;
v_8227:
    v_8472 = get(v_8472, v_8471);
    env = stack[-7];
    goto v_8219;
v_8220:
    v_8471 = stack[-5];
    goto v_8221;
v_8222:
    goto v_8218;
v_8219:
    goto v_8220;
v_8221:
    v_8471 = Lapply1(nil, v_8472, v_8471);
    env = stack[-7];
    stack[-5] = v_8471;
    v_8471 = elt(env, 7); // !:cr!:
    stack[-6] = v_8471;
    goto v_8173;
v_8175:
    goto v_8247;
v_8243:
    v_8472 = stack[-6];
    goto v_8244;
v_8245:
    v_8471 = elt(env, 8); // !:rn!:
    goto v_8246;
v_8247:
    goto v_8243;
v_8244:
    goto v_8245;
v_8246:
    if (v_8472 == v_8471) goto v_8241;
    else goto v_8242;
v_8241:
    goto v_8254;
v_8250:
    v_8472 = stack[-2];
    goto v_8251;
v_8252:
    v_8471 = elt(env, 9); // !:gi!:
    goto v_8253;
v_8254:
    goto v_8250;
v_8251:
    goto v_8252;
v_8253:
    v_8471 = (v_8472 == v_8471 ? lisp_true : nil);
    goto v_8240;
v_8242:
    v_8471 = nil;
    goto v_8240;
    v_8471 = nil;
v_8240:
    if (v_8471 == nil) goto v_8238;
    v_8471 = lisp_true;
    goto v_8236;
v_8238:
    goto v_8272;
v_8268:
    v_8472 = stack[-6];
    goto v_8269;
v_8270:
    v_8471 = elt(env, 9); // !:gi!:
    goto v_8271;
v_8272:
    goto v_8268;
v_8269:
    goto v_8270;
v_8271:
    if (v_8472 == v_8471) goto v_8266;
    else goto v_8267;
v_8266:
    goto v_8279;
v_8275:
    v_8472 = stack[-2];
    goto v_8276;
v_8277:
    v_8471 = elt(env, 8); // !:rn!:
    goto v_8278;
v_8279:
    goto v_8275;
v_8276:
    goto v_8277;
v_8278:
    v_8471 = (v_8472 == v_8471 ? lisp_true : nil);
    goto v_8265;
v_8267:
    v_8471 = nil;
    goto v_8265;
    v_8471 = nil;
v_8265:
    goto v_8236;
    v_8471 = nil;
v_8236:
    if (v_8471 == nil) goto v_8234;
    goto v_8291;
v_8287:
    goto v_8297;
v_8293:
    v_8472 = stack[-6];
    goto v_8294;
v_8295:
    v_8471 = elt(env, 10); // !:crn!:
    goto v_8296;
v_8297:
    goto v_8293;
v_8294:
    goto v_8295;
v_8296:
    v_8472 = get(v_8472, v_8471);
    env = stack[-7];
    goto v_8288;
v_8289:
    v_8471 = stack[-5];
    goto v_8290;
v_8291:
    goto v_8287;
v_8288:
    goto v_8289;
v_8290:
    v_8471 = Lapply1(nil, v_8472, v_8471);
    env = stack[-7];
    stack[-5] = v_8471;
    v_8471 = elt(env, 10); // !:crn!:
    stack[-6] = v_8471;
    goto v_8173;
v_8234:
v_8173:
    goto v_8307;
v_8303:
    goto v_8313;
v_8309:
    v_8472 = stack[-2];
    goto v_8310;
v_8311:
    v_8471 = stack[-6];
    goto v_8312;
v_8313:
    goto v_8309;
v_8310:
    goto v_8311;
v_8312:
    v_8472 = get(v_8472, v_8471);
    env = stack[-7];
    goto v_8304;
v_8305:
    v_8471 = stack[-4];
    goto v_8306;
v_8307:
    goto v_8303;
v_8304:
    goto v_8305;
v_8306:
    v_8471 = Lapply1(nil, v_8472, v_8471);
    env = stack[-7];
    stack[-4] = v_8471;
    goto v_8322;
v_8318:
    v_8472 = stack[-6];
    goto v_8319;
v_8320:
    v_8471 = stack[-3];
    goto v_8321;
v_8322:
    goto v_8318;
v_8319:
    goto v_8320;
v_8321:
    v_8471 = get(v_8472, v_8471);
    env = stack[-7];
    stack[-1] = v_8471;
    goto v_8095;
v_8097:
    goto v_8332;
v_8328:
    v_8472 = stack[-1];
    goto v_8329;
v_8330:
    v_8471 = stack[-5];
    goto v_8331;
v_8332:
    goto v_8328;
v_8329:
    goto v_8330;
v_8331:
    v_8471 = Lapply1(nil, v_8472, v_8471);
    env = stack[-7];
    stack[-5] = v_8471;
    goto v_8340;
v_8336:
    v_8472 = stack[-2];
    goto v_8337;
v_8338:
    v_8471 = stack[-3];
    goto v_8339;
v_8340:
    goto v_8336;
v_8337:
    goto v_8338;
v_8339:
    v_8471 = get(v_8472, v_8471);
    env = stack[-7];
    stack[-1] = v_8471;
    goto v_8095;
v_8095:
    goto v_8350;
v_8344:
    v_8473 = stack[-1];
    goto v_8345;
v_8346:
    v_8472 = stack[-5];
    goto v_8347;
v_8348:
    v_8471 = stack[-4];
    goto v_8349;
v_8350:
    goto v_8344;
v_8345:
    goto v_8346;
v_8347:
    goto v_8348;
v_8349:
    v_8471 = Lapply2(nil, 3, v_8473, v_8472, v_8471);
    env = stack[-7];
    goto v_7980;
    v_8471 = nil;
v_7980:
    stack[-5] = v_8471;
    v_8471 = qvalue(elt(env, 11)); // !*rounded
    if (v_8471 == nil) goto v_8357;
    v_8471 = qvalue(elt(env, 12)); // !*roundall
    if (v_8471 == nil) goto v_8357;
    v_8471 = stack[-5];
    if (!consp(v_8471)) goto v_8357;
    goto v_8378;
v_8374:
    v_8471 = stack[-5];
    v_8472 = qcar(v_8471);
    stack[-4] = v_8472;
    goto v_8375;
v_8376:
    v_8471 = elt(env, 8); // !:rn!:
    goto v_8377;
v_8378:
    goto v_8374;
v_8375:
    goto v_8376;
v_8377:
    if (v_8472 == v_8471) goto v_8372;
    else goto v_8373;
v_8372:
    goto v_8387;
v_8383:
    v_8471 = stack[-5];
    v_8471 = qcdr(v_8471);
    v_8472 = qcdr(v_8471);
    goto v_8384;
v_8385:
    v_8471 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8386;
v_8387:
    goto v_8383;
v_8384:
    goto v_8385;
v_8386:
    v_8471 = Lneq(nil, v_8472, v_8471);
    env = stack[-7];
    goto v_8371;
v_8373:
    v_8471 = nil;
    goto v_8371;
    v_8471 = nil;
v_8371:
    if (v_8471 == nil) goto v_8369;
    v_8471 = stack[-5];
    fn = elt(env, 14); // !*rn2rd
    v_8471 = (*qfn1(fn))(fn, v_8471);
    env = stack[-7];
    goto v_8367;
v_8369:
    goto v_8407;
v_8403:
    v_8472 = stack[-4];
    goto v_8404;
v_8405:
    v_8471 = elt(env, 10); // !:crn!:
    goto v_8406;
v_8407:
    goto v_8403;
v_8404:
    goto v_8405;
v_8406:
    if (v_8472 == v_8471) goto v_8401;
    else goto v_8402;
v_8401:
    goto v_8418;
v_8414:
    v_8471 = stack[-5];
    v_8471 = qcdr(v_8471);
    v_8471 = qcar(v_8471);
    v_8472 = qcdr(v_8471);
    goto v_8415;
v_8416:
    v_8471 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8417;
v_8418:
    goto v_8414;
v_8415:
    goto v_8416;
v_8417:
    if (v_8472 == v_8471) goto v_8413;
    v_8471 = lisp_true;
    goto v_8411;
v_8413:
    goto v_8432;
v_8428:
    v_8471 = stack[-5];
    v_8471 = qcdr(v_8471);
    v_8471 = qcdr(v_8471);
    v_8472 = qcdr(v_8471);
    goto v_8429;
v_8430:
    v_8471 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8431;
v_8432:
    goto v_8428;
v_8429:
    goto v_8430;
v_8431:
    v_8471 = Lneq(nil, v_8472, v_8471);
    env = stack[-7];
    goto v_8411;
    v_8471 = nil;
v_8411:
    goto v_8400;
v_8402:
    v_8471 = nil;
    goto v_8400;
    v_8471 = nil;
v_8400:
    if (v_8471 == nil) goto v_8398;
    v_8471 = stack[-5];
    fn = elt(env, 15); // !*crn2cr
    v_8471 = (*qfn1(fn))(fn, v_8471);
    env = stack[-7];
    goto v_8367;
v_8398:
    v_8471 = stack[-5];
    goto v_8367;
    v_8471 = nil;
v_8367:
    {
        fn = elt(env, 16); // int!-equiv!-chk
        return (*qfn1(fn))(fn, v_8471);
    }
v_8357:
    goto v_8452;
v_8448:
    v_8472 = stack[-3];
    goto v_8449;
v_8450:
    v_8471 = elt(env, 13); // divide
    goto v_8451;
v_8452:
    goto v_8448;
v_8449:
    goto v_8450;
v_8451:
    if (v_8472 == v_8471) goto v_8446;
    else goto v_8447;
v_8446:
    goto v_8460;
v_8456:
    v_8471 = stack[-5];
    v_8471 = qcar(v_8471);
    fn = elt(env, 16); // int!-equiv!-chk
    stack[0] = (*qfn1(fn))(fn, v_8471);
    env = stack[-7];
    goto v_8457;
v_8458:
    v_8471 = stack[-5];
    v_8471 = qcdr(v_8471);
    fn = elt(env, 16); // int!-equiv!-chk
    v_8471 = (*qfn1(fn))(fn, v_8471);
    goto v_8459;
v_8460:
    goto v_8456;
v_8457:
    goto v_8458;
v_8459:
    {
        LispObject v_8481 = stack[0];
        return cons(v_8481, v_8471);
    }
v_8447:
    v_8471 = stack[-5];
    {
        fn = elt(env, 16); // int!-equiv!-chk
        return (*qfn1(fn))(fn, v_8471);
    }
    v_8471 = nil;
    return onevalue(v_8471);
}



// Code for general!-times!-mod!-p

static LispObject CC_generalKtimesKmodKp(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8193, v_8194, v_8195;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7976;
    stack[-1] = v_7975;
// end of prologue
    v_8193 = stack[-1];
    if (v_8193 == nil) goto v_7984;
    else goto v_7985;
v_7984:
    v_8193 = lisp_true;
    goto v_7983;
v_7985:
    v_8193 = stack[0];
    v_8193 = (v_8193 == nil ? lisp_true : nil);
    goto v_7983;
    v_8193 = nil;
v_7983:
    if (v_8193 == nil) goto v_7981;
    v_8193 = nil;
    goto v_7979;
v_7981:
    v_8193 = stack[-1];
    if (!consp(v_8193)) goto v_7997;
    else goto v_7998;
v_7997:
    v_8193 = lisp_true;
    goto v_7996;
v_7998:
    v_8193 = stack[-1];
    v_8193 = qcar(v_8193);
    v_8193 = (consp(v_8193) ? nil : lisp_true);
    goto v_7996;
    v_8193 = nil;
v_7996:
    if (v_8193 == nil) goto v_7994;
    goto v_8011;
v_8007:
    v_8194 = stack[0];
    goto v_8008;
v_8009:
    v_8193 = stack[-1];
    goto v_8010;
v_8011:
    goto v_8007;
v_8008:
    goto v_8009;
v_8010:
    {
        fn = elt(env, 1); // gen!-mult!-by!-const!-mod!-p
        return (*qfn2(fn))(fn, v_8194, v_8193);
    }
v_7994:
    v_8193 = stack[0];
    if (!consp(v_8193)) goto v_8018;
    else goto v_8019;
v_8018:
    v_8193 = lisp_true;
    goto v_8017;
v_8019:
    v_8193 = stack[0];
    v_8193 = qcar(v_8193);
    v_8193 = (consp(v_8193) ? nil : lisp_true);
    goto v_8017;
    v_8193 = nil;
v_8017:
    if (v_8193 == nil) goto v_8015;
    goto v_8032;
v_8028:
    v_8194 = stack[-1];
    goto v_8029;
v_8030:
    v_8193 = stack[0];
    goto v_8031;
v_8032:
    goto v_8028;
v_8029:
    goto v_8030;
v_8031:
    {
        fn = elt(env, 1); // gen!-mult!-by!-const!-mod!-p
        return (*qfn2(fn))(fn, v_8194, v_8193);
    }
v_8015:
    goto v_8041;
v_8037:
    v_8193 = stack[-1];
    v_8193 = qcar(v_8193);
    v_8193 = qcar(v_8193);
    v_8194 = qcar(v_8193);
    goto v_8038;
v_8039:
    v_8193 = stack[0];
    v_8193 = qcar(v_8193);
    v_8193 = qcar(v_8193);
    v_8193 = qcar(v_8193);
    goto v_8040;
v_8041:
    goto v_8037;
v_8038:
    goto v_8039;
v_8040:
    if (equal(v_8194, v_8193)) goto v_8035;
    else goto v_8036;
v_8035:
    goto v_8055;
v_8051:
    goto v_8061;
v_8057:
    goto v_8067;
v_8063:
    v_8193 = stack[-1];
    v_8194 = qcar(v_8193);
    goto v_8064;
v_8065:
    v_8193 = stack[0];
    goto v_8066;
v_8067:
    goto v_8063;
v_8064:
    goto v_8065;
v_8066:
    fn = elt(env, 2); // general!-times!-term!-mod!-p
    stack[-2] = (*qfn2(fn))(fn, v_8194, v_8193);
    env = stack[-3];
    goto v_8058;
v_8059:
    goto v_8076;
v_8072:
    v_8193 = stack[0];
    v_8194 = qcar(v_8193);
    goto v_8073;
v_8074:
    v_8193 = stack[-1];
    v_8193 = qcdr(v_8193);
    goto v_8075;
v_8076:
    goto v_8072;
v_8073:
    goto v_8074;
v_8075:
    fn = elt(env, 2); // general!-times!-term!-mod!-p
    v_8193 = (*qfn2(fn))(fn, v_8194, v_8193);
    env = stack[-3];
    goto v_8060;
v_8061:
    goto v_8057;
v_8058:
    goto v_8059;
v_8060:
    fn = elt(env, 3); // general!-plus!-mod!-p
    stack[-2] = (*qfn2(fn))(fn, stack[-2], v_8193);
    env = stack[-3];
    goto v_8052;
v_8053:
    goto v_8086;
v_8082:
    v_8193 = stack[-1];
    v_8194 = qcdr(v_8193);
    goto v_8083;
v_8084:
    v_8193 = stack[0];
    v_8193 = qcdr(v_8193);
    goto v_8085;
v_8086:
    goto v_8082;
v_8083:
    goto v_8084;
v_8085:
    v_8193 = CC_generalKtimesKmodKp(elt(env, 0), v_8194, v_8193);
    env = stack[-3];
    goto v_8054;
v_8055:
    goto v_8051;
v_8052:
    goto v_8053;
v_8054:
    {
        LispObject v_8199 = stack[-2];
        fn = elt(env, 3); // general!-plus!-mod!-p
        return (*qfn2(fn))(fn, v_8199, v_8193);
    }
v_8036:
    goto v_8098;
v_8094:
    v_8193 = stack[-1];
    v_8193 = qcar(v_8193);
    v_8193 = qcar(v_8193);
    v_8194 = qcar(v_8193);
    goto v_8095;
v_8096:
    v_8193 = stack[0];
    v_8193 = qcar(v_8193);
    v_8193 = qcar(v_8193);
    v_8193 = qcar(v_8193);
    goto v_8097;
v_8098:
    goto v_8094;
v_8095:
    goto v_8096;
v_8097:
    fn = elt(env, 4); // ordop
    v_8193 = (*qfn2(fn))(fn, v_8194, v_8193);
    env = stack[-3];
    if (v_8193 == nil) goto v_8092;
    goto v_8112;
v_8108:
    v_8193 = stack[-1];
    v_8193 = qcar(v_8193);
    v_8194 = qcdr(v_8193);
    goto v_8109;
v_8110:
    v_8193 = stack[0];
    goto v_8111;
v_8112:
    goto v_8108;
v_8109:
    goto v_8110;
v_8111:
    stack[-2] = CC_generalKtimesKmodKp(elt(env, 0), v_8194, v_8193);
    env = stack[-3];
    goto v_8122;
v_8118:
    v_8193 = stack[-1];
    v_8194 = qcdr(v_8193);
    goto v_8119;
v_8120:
    v_8193 = stack[0];
    goto v_8121;
v_8122:
    goto v_8118;
v_8119:
    goto v_8120;
v_8121:
    v_8193 = CC_generalKtimesKmodKp(elt(env, 0), v_8194, v_8193);
    v_8194 = stack[-2];
    v_8195 = v_8194;
    if (v_8195 == nil) goto v_8130;
    else goto v_8131;
v_8130:
    goto v_8129;
v_8131:
    goto v_8143;
v_8137:
    v_8195 = stack[-1];
    v_8195 = qcar(v_8195);
    v_8195 = qcar(v_8195);
    goto v_8138;
v_8139:
    goto v_8140;
v_8141:
    goto v_8142;
v_8143:
    goto v_8137;
v_8138:
    goto v_8139;
v_8140:
    goto v_8141;
v_8142:
    return acons(v_8195, v_8194, v_8193);
    v_8193 = nil;
v_8129:
    goto v_7979;
v_8092:
    goto v_8156;
v_8152:
    v_8194 = stack[-1];
    goto v_8153;
v_8154:
    v_8193 = stack[0];
    v_8193 = qcar(v_8193);
    v_8193 = qcdr(v_8193);
    goto v_8155;
v_8156:
    goto v_8152;
v_8153:
    goto v_8154;
v_8155:
    stack[-2] = CC_generalKtimesKmodKp(elt(env, 0), v_8194, v_8193);
    env = stack[-3];
    goto v_8166;
v_8162:
    v_8194 = stack[-1];
    goto v_8163;
v_8164:
    v_8193 = stack[0];
    v_8193 = qcdr(v_8193);
    goto v_8165;
v_8166:
    goto v_8162;
v_8163:
    goto v_8164;
v_8165:
    v_8193 = CC_generalKtimesKmodKp(elt(env, 0), v_8194, v_8193);
    v_8194 = stack[-2];
    v_8195 = v_8194;
    if (v_8195 == nil) goto v_8174;
    else goto v_8175;
v_8174:
    goto v_8173;
v_8175:
    goto v_8187;
v_8181:
    v_8195 = stack[0];
    v_8195 = qcar(v_8195);
    v_8195 = qcar(v_8195);
    goto v_8182;
v_8183:
    goto v_8184;
v_8185:
    goto v_8186;
v_8187:
    goto v_8181;
v_8182:
    goto v_8183;
v_8184:
    goto v_8185;
v_8186:
    return acons(v_8195, v_8194, v_8193);
    v_8193 = nil;
v_8173:
    goto v_7979;
    v_8193 = nil;
v_7979:
    return onevalue(v_8193);
}



// Code for setk

static LispObject CC_setk(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8071, v_8072, v_8073;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7976;
    v_8072 = v_7975;
// end of prologue
    v_8071 = v_8072;
    if (!consp(v_8071)) goto v_7981;
    goto v_7988;
v_7984:
    v_8071 = v_8072;
    v_8073 = qcar(v_8071);
    goto v_7985;
v_7986:
    v_8071 = elt(env, 1); // evalargfn
    goto v_7987;
v_7988:
    goto v_7984;
v_7985:
    goto v_7986;
v_7987:
    v_8071 = get(v_8073, v_8071);
    env = stack[-2];
    v_8073 = v_8071;
    v_8071 = v_8073;
    if (v_8071 == nil) goto v_7996;
    goto v_8003;
v_7999:
    goto v_8009;
v_8005:
    v_8071 = v_8072;
    stack[-1] = qcar(v_8071);
    goto v_8006;
v_8007:
    goto v_8017;
v_8013:
    v_8071 = v_8073;
    goto v_8014;
v_8015:
    v_8072 = qcdr(v_8072);
    goto v_8016;
v_8017:
    goto v_8013;
v_8014:
    goto v_8015;
v_8016:
    v_8071 = Lapply1(nil, v_8071, v_8072);
    env = stack[-2];
    goto v_8008;
v_8009:
    goto v_8005;
v_8006:
    goto v_8007;
v_8008:
    v_8072 = cons(stack[-1], v_8071);
    env = stack[-2];
    goto v_8000;
v_8001:
    v_8071 = stack[0];
    goto v_8002;
v_8003:
    goto v_7999;
v_8000:
    goto v_8001;
v_8002:
    {
        fn = elt(env, 3); // setk0
        return (*qfn2(fn))(fn, v_8072, v_8071);
    }
v_7996:
    goto v_8028;
v_8024:
    v_8071 = v_8072;
    v_8071 = qcar(v_8071);
    if (!symbolp(v_8071)) v_8073 = nil;
    else { v_8073 = qfastgets(v_8071);
           if (v_8073 != nil) { v_8073 = elt(v_8073, 2); // rtype
#ifdef RECORD_GET
             if (v_8073 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_8073 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_8073 == SPID_NOPROP) v_8073 = nil; }}
#endif
    goto v_8025;
v_8026:
    v_8071 = elt(env, 2); // matrix
    goto v_8027;
v_8028:
    goto v_8024;
v_8025:
    goto v_8026;
v_8027:
    if (v_8073 == v_8071) goto v_8022;
    else goto v_8023;
v_8022:
    goto v_8038;
v_8034:
    goto v_8035;
v_8036:
    v_8071 = stack[0];
    goto v_8037;
v_8038:
    goto v_8034;
v_8035:
    goto v_8036;
v_8037:
    {
        fn = elt(env, 3); // setk0
        return (*qfn2(fn))(fn, v_8072, v_8071);
    }
v_8023:
    goto v_8048;
v_8044:
    goto v_8054;
v_8050:
    v_8071 = v_8072;
    stack[-1] = qcar(v_8071);
    goto v_8051;
v_8052:
    v_8071 = v_8072;
    v_8071 = qcdr(v_8071);
    fn = elt(env, 4); // revlis
    v_8071 = (*qfn1(fn))(fn, v_8071);
    env = stack[-2];
    goto v_8053;
v_8054:
    goto v_8050;
v_8051:
    goto v_8052;
v_8053:
    v_8072 = cons(stack[-1], v_8071);
    env = stack[-2];
    goto v_8045;
v_8046:
    v_8071 = stack[0];
    goto v_8047;
v_8048:
    goto v_8044;
v_8045:
    goto v_8046;
v_8047:
    {
        fn = elt(env, 3); // setk0
        return (*qfn2(fn))(fn, v_8072, v_8071);
    }
    v_8071 = nil;
    goto v_7979;
v_7981:
    goto v_8068;
v_8064:
    goto v_8065;
v_8066:
    v_8071 = stack[0];
    goto v_8067;
v_8068:
    goto v_8064;
v_8065:
    goto v_8066;
v_8067:
    {
        fn = elt(env, 3); // setk0
        return (*qfn2(fn))(fn, v_8072, v_8071);
    }
    v_8071 = nil;
v_7979:
    return onevalue(v_8071);
}



// Code for lalr_resolve_conflicts

static LispObject CC_lalr_resolve_conflicts(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8254, v_8255, v_8256;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-7] = v_7976;
    stack[-8] = v_7975;
// end of prologue
    stack[-9] = nil;
    stack[-2] = nil;
    goto v_7995;
v_7991:
    v_8255 = stack[-8];
    goto v_7992;
v_7993:
    v_8254 = elt(env, 1); // orderactions
    goto v_7994;
v_7995:
    goto v_7991;
v_7992:
    goto v_7993;
v_7994:
    fn = elt(env, 5); // sort
    v_8254 = (*qfn2(fn))(fn, v_8255, v_8254);
    env = stack[-10];
    stack[-8] = v_8254;
v_8000:
    v_8254 = stack[-8];
    if (v_8254 == nil) goto v_8003;
    else goto v_8004;
v_8003:
    goto v_7999;
v_8004:
    v_8254 = stack[-8];
    v_8254 = qcar(v_8254);
    v_8254 = ncons(v_8254);
    env = stack[-10];
    v_8256 = v_8254;
    v_8254 = stack[-8];
    v_8254 = qcdr(v_8254);
    stack[-8] = v_8254;
v_8014:
    v_8254 = stack[-8];
    if (v_8254 == nil) goto v_8017;
    goto v_8026;
v_8022:
    v_8254 = stack[-8];
    v_8254 = qcar(v_8254);
    v_8255 = qcar(v_8254);
    goto v_8023;
v_8024:
    v_8254 = v_8256;
    v_8254 = qcar(v_8254);
    v_8254 = qcar(v_8254);
    goto v_8025;
v_8026:
    goto v_8022;
v_8023:
    goto v_8024;
v_8025:
    if (equal(v_8255, v_8254)) goto v_8021;
    else goto v_8017;
v_8021:
    goto v_8018;
v_8017:
    goto v_8013;
v_8018:
    goto v_8039;
v_8035:
    v_8254 = stack[-8];
    v_8254 = qcar(v_8254);
    goto v_8036;
v_8037:
    v_8255 = v_8256;
    goto v_8038;
v_8039:
    goto v_8035;
v_8036:
    goto v_8037;
v_8038:
    v_8254 = cons(v_8254, v_8255);
    env = stack[-10];
    v_8256 = v_8254;
    v_8254 = stack[-8];
    v_8254 = qcdr(v_8254);
    stack[-8] = v_8254;
    goto v_8014;
v_8013:
    v_8254 = nil;
    stack[-4] = v_8254;
    stack[-5] = v_8254;
    stack[-6] = v_8254;
    v_8254 = v_8256;
    v_8254 = qcdr(v_8254);
    if (v_8254 == nil) goto v_8048;
    else goto v_8049;
v_8048:
    v_8254 = v_8256;
    v_8254 = qcar(v_8254);
    stack[-4] = v_8254;
    goto v_8047;
v_8049:
    v_8254 = v_8256;
    stack[0] = v_8254;
v_8059:
    v_8254 = stack[0];
    if (v_8254 == nil) goto v_8063;
    else goto v_8064;
v_8063:
    goto v_8058;
v_8064:
    v_8254 = stack[0];
    v_8254 = qcar(v_8254);
    v_8255 = v_8254;
    goto v_8078;
v_8074:
    v_8254 = v_8255;
    v_8254 = qcdr(v_8254);
    v_8254 = qcar(v_8254);
    v_8256 = qcar(v_8254);
    goto v_8075;
v_8076:
    v_8254 = elt(env, 2); // shift
    goto v_8077;
v_8078:
    goto v_8074;
v_8075:
    goto v_8076;
v_8077:
    if (v_8256 == v_8254) goto v_8072;
    else goto v_8073;
v_8072:
    v_8254 = v_8255;
    stack[-6] = v_8254;
    goto v_8071;
v_8073:
    v_8254 = stack[-5];
    if (v_8254 == nil) goto v_8085;
    else goto v_8086;
v_8085:
    v_8254 = v_8255;
    stack[-5] = v_8254;
    goto v_8071;
v_8086:
    goto v_8098;
v_8092:
    v_8256 = stack[-5];
    goto v_8093;
v_8094:
    goto v_8095;
v_8096:
    v_8254 = stack[-7];
    goto v_8097;
v_8098:
    goto v_8092;
v_8093:
    goto v_8094;
v_8095:
    goto v_8096;
v_8097:
    fn = elt(env, 6); // lalr_warn_reduce_reduce_conflict
    v_8254 = (*qfnn(fn))(fn, 3, v_8256, v_8255, v_8254);
    env = stack[-10];
    goto v_8071;
v_8071:
    v_8254 = stack[-6];
    if (v_8254 == nil) goto v_8105;
    v_8254 = stack[-5];
    if (v_8254 == nil) goto v_8105;
    v_8254 = stack[-6];
    v_8254 = qcar(v_8254);
    stack[-3] = v_8254;
    v_8254 = stack[-5];
    v_8254 = qcdr(v_8254);
    v_8254 = qcar(v_8254);
    v_8254 = qcdr(v_8254);
    v_8254 = qcar(v_8254);
    v_8256 = v_8254;
v_8115:
    v_8254 = v_8256;
    if (v_8254 == nil) goto v_8123;
    else goto v_8124;
v_8123:
    goto v_8114;
v_8124:
    v_8254 = v_8256;
    v_8254 = qcar(v_8254);
    v_8255 = v_8254;
    v_8254 = v_8255;
    if (is_number(v_8254)) goto v_8132;
    else goto v_8133;
v_8132:
    v_8254 = v_8255;
    stack[-2] = v_8254;
    goto v_8131;
v_8133:
v_8131:
    v_8254 = v_8256;
    v_8254 = qcdr(v_8254);
    v_8256 = v_8254;
    goto v_8115;
v_8114:
    v_8254 = stack[-3];
    if (v_8254 == nil) goto v_8141;
    v_8254 = stack[-2];
    if (v_8254 == nil) goto v_8141;
    v_8254 = stack[-3];
    fn = elt(env, 7); // lalr_precedence
    v_8254 = (*qfn1(fn))(fn, v_8254);
    env = stack[-10];
    stack[-1] = v_8254;
    v_8254 = stack[-2];
    fn = elt(env, 7); // lalr_precedence
    v_8254 = (*qfn1(fn))(fn, v_8254);
    env = stack[-10];
    v_8256 = v_8254;
    v_8254 = stack[-1];
    if (v_8254 == nil) goto v_8153;
    v_8254 = v_8256;
    if (v_8254 == nil) goto v_8153;
    goto v_8166;
v_8162:
    v_8255 = stack[-1];
    goto v_8163;
v_8164:
    v_8254 = v_8256;
    goto v_8165;
v_8166:
    goto v_8162;
v_8163:
    goto v_8164;
v_8165:
    if (equal(v_8255, v_8254)) goto v_8160;
    else goto v_8161;
v_8160:
    v_8254 = stack[-3];
    fn = elt(env, 8); // lalr_associativity
    v_8254 = (*qfn1(fn))(fn, v_8254);
    env = stack[-10];
    v_8256 = v_8254;
    goto v_8179;
v_8175:
    v_8255 = v_8256;
    goto v_8176;
v_8177:
    v_8254 = elt(env, 3); // !:left
    goto v_8178;
v_8179:
    goto v_8175;
v_8176:
    goto v_8177;
v_8178:
    if (v_8255 == v_8254) goto v_8173;
    else goto v_8174;
v_8173:
    v_8254 = nil;
    stack[-6] = v_8254;
    goto v_8172;
v_8174:
    goto v_8189;
v_8185:
    v_8255 = v_8256;
    goto v_8186;
v_8187:
    v_8254 = elt(env, 4); // !:right
    goto v_8188;
v_8189:
    goto v_8185;
v_8186:
    goto v_8187;
v_8188:
    if (v_8255 == v_8254) goto v_8183;
    else goto v_8184;
v_8183:
    v_8254 = nil;
    stack[-5] = v_8254;
    goto v_8172;
v_8184:
    v_8254 = nil;
    stack[-5] = v_8254;
    stack[-6] = v_8254;
    goto v_8172;
v_8172:
    goto v_8159;
v_8161:
    goto v_8203;
v_8199:
    v_8254 = stack[-1];
    goto v_8200;
v_8201:
    v_8255 = v_8256;
    goto v_8202;
v_8203:
    goto v_8199;
v_8200:
    goto v_8201;
v_8202:
    v_8254 = (LispObject)lessp2(v_8254, v_8255);
    v_8254 = v_8254 ? lisp_true : nil;
    env = stack[-10];
    if (v_8254 == nil) goto v_8197;
    v_8254 = nil;
    stack[-5] = v_8254;
    goto v_8159;
v_8197:
    v_8254 = nil;
    stack[-6] = v_8254;
    goto v_8159;
v_8159:
    goto v_8151;
v_8153:
v_8151:
    goto v_8139;
v_8141:
v_8139:
    goto v_8103;
v_8105:
v_8103:
    v_8254 = stack[0];
    v_8254 = qcdr(v_8254);
    stack[0] = v_8254;
    goto v_8059;
v_8058:
    goto v_8047;
v_8047:
    v_8254 = stack[-6];
    if (v_8254 == nil) goto v_8215;
    v_8254 = stack[-5];
    if (v_8254 == nil) goto v_8215;
    goto v_8227;
v_8221:
    v_8256 = stack[-6];
    goto v_8222;
v_8223:
    v_8255 = stack[-5];
    goto v_8224;
v_8225:
    v_8254 = stack[-7];
    goto v_8226;
v_8227:
    goto v_8221;
v_8222:
    goto v_8223;
v_8224:
    goto v_8225;
v_8226:
    fn = elt(env, 9); // lalr_warn_shift_reduce_conflict
    v_8254 = (*qfnn(fn))(fn, 3, v_8256, v_8255, v_8254);
    env = stack[-10];
    goto v_8213;
v_8215:
v_8213:
    v_8254 = stack[-4];
    if (v_8254 == nil) goto v_8233;
    else goto v_8232;
v_8233:
    v_8254 = stack[-6];
    if (v_8254 == nil) goto v_8237;
    else goto v_8236;
v_8237:
    v_8254 = stack[-5];
v_8236:
v_8232:
    stack[-4] = v_8254;
    v_8254 = stack[-4];
    if (v_8254 == nil) goto v_8243;
    goto v_8250;
v_8246:
    v_8255 = stack[-4];
    goto v_8247;
v_8248:
    v_8254 = stack[-9];
    goto v_8249;
v_8250:
    goto v_8246;
v_8247:
    goto v_8248;
v_8249:
    v_8254 = cons(v_8255, v_8254);
    env = stack[-10];
    stack[-9] = v_8254;
    goto v_8241;
v_8243:
v_8241:
    goto v_8000;
v_7999:
    v_8254 = stack[-9];
    return onevalue(v_8254);
}



// Code for idsort

static LispObject CC_idsort(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_7985, v_7986;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7985 = v_7975;
// end of prologue
    goto v_7982;
v_7978:
    v_7986 = v_7985;
    goto v_7979;
v_7980:
    v_7985 = elt(env, 1); // idcompare
    goto v_7981;
v_7982:
    goto v_7978;
v_7979:
    goto v_7980;
v_7981:
    {
        fn = elt(env, 2); // sort
        return (*qfn2(fn))(fn, v_7986, v_7985);
    }
}



// Code for mri_realvarp

static LispObject CC_mri_realvarp(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_8000, v_8001;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7975);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_8001 = v_7975;
// end of prologue
    v_8000 = v_8001;
    if (symbolp(v_8000)) goto v_7980;
    v_8000 = nil;
    goto v_7978;
v_7980:
    goto v_7989;
v_7985:
    goto v_7995;
v_7991:
    goto v_7992;
v_7993:
    v_8000 = elt(env, 1); // mri_type
    goto v_7994;
v_7995:
    goto v_7991;
v_7992:
    goto v_7993;
v_7994:
    v_8000 = get(v_8001, v_8000);
    env = stack[0];
    goto v_7986;
v_7987:
    v_8001 = elt(env, 2); // real
    goto v_7988;
v_7989:
    goto v_7985;
v_7986:
    goto v_7987;
v_7988:
    v_8000 = (v_8000 == v_8001 ? lisp_true : nil);
    goto v_7978;
    v_8000 = nil;
v_7978:
    return onevalue(v_8000);
}



// Code for qqe_ofsf_chsimpterm

static LispObject CC_qqe_ofsf_chsimpterm(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_8068, v_8069;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7975);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_8069 = v_7975;
// end of prologue
    v_8068 = v_8069;
    if (!consp(v_8068)) goto v_7982;
    else goto v_7983;
v_7982:
    v_8068 = v_8069;
    goto v_7979;
v_7983:
    v_8068 = v_8069;
    v_8068 = qcdr(v_8068);
    stack[-1] = v_8068;
v_7992:
    v_8068 = stack[-1];
    if (v_8068 == nil) goto v_7995;
    else goto v_7996;
v_7995:
    goto v_7991;
v_7996:
    v_8068 = stack[-1];
    v_8068 = qcar(v_8068);
    v_8068 = Lconsp(nil, v_8068);
    env = stack[-2];
    if (v_8068 == nil) goto v_8002;
    goto v_8016;
v_8012:
    v_8068 = stack[-1];
    v_8068 = qcar(v_8068);
    fn = elt(env, 3); // qqe_op
    v_8069 = (*qfn1(fn))(fn, v_8068);
    env = stack[-2];
    goto v_8013;
v_8014:
    v_8068 = elt(env, 1); // expt
    goto v_8015;
v_8016:
    goto v_8012;
v_8013:
    goto v_8014;
v_8015:
    if (v_8069 == v_8068) goto v_8010;
    else goto v_8011;
v_8010:
    v_8068 = stack[-1];
    v_8068 = qcar(v_8068);
    fn = elt(env, 4); // qqe_arg2l
    v_8068 = (*qfn1(fn))(fn, v_8068);
    env = stack[-2];
    v_8068 = Lconsp(nil, v_8068);
    env = stack[-2];
    if (v_8068 == nil) goto v_8023;
    else goto v_8024;
v_8023:
    v_8068 = nil;
    goto v_8022;
v_8024:
    goto v_8036;
v_8032:
    v_8068 = stack[-1];
    v_8068 = qcar(v_8068);
    fn = elt(env, 4); // qqe_arg2l
    v_8068 = (*qfn1(fn))(fn, v_8068);
    env = stack[-2];
    fn = elt(env, 3); // qqe_op
    v_8069 = (*qfn1(fn))(fn, v_8068);
    env = stack[-2];
    goto v_8033;
v_8034:
    v_8068 = elt(env, 2); // (ltail rtail)
    goto v_8035;
v_8036:
    goto v_8032;
v_8033:
    goto v_8034;
v_8035:
    v_8068 = Lmemq(nil, v_8069, v_8068);
    goto v_8022;
    v_8068 = nil;
v_8022:
    goto v_8009;
v_8011:
    v_8068 = nil;
    goto v_8009;
    v_8068 = nil;
v_8009:
    if (v_8068 == nil) goto v_8002;
    goto v_8051;
v_8047:
    stack[0] = stack[-1];
    goto v_8048;
v_8049:
    v_8068 = stack[-1];
    v_8068 = qcar(v_8068);
    fn = elt(env, 5); // qqe_chsimpterm
    v_8068 = (*qfn1(fn))(fn, v_8068);
    env = stack[-2];
    goto v_8050;
v_8051:
    goto v_8047;
v_8048:
    goto v_8049;
v_8050:
    fn = elt(env, 6); // setcar
    v_8068 = (*qfn2(fn))(fn, stack[0], v_8068);
    env = stack[-2];
    goto v_8000;
v_8002:
    v_8068 = stack[-1];
    v_8068 = qcar(v_8068);
    v_8068 = Lconsp(nil, v_8068);
    env = stack[-2];
    if (v_8068 == nil) goto v_8057;
    v_8068 = stack[-1];
    v_8068 = qcar(v_8068);
    v_8068 = CC_qqe_ofsf_chsimpterm(elt(env, 0), v_8068);
    env = stack[-2];
    goto v_8000;
v_8057:
v_8000:
    v_8068 = stack[-1];
    v_8068 = qcdr(v_8068);
    stack[-1] = v_8068;
    goto v_7992;
v_7991:
    goto v_7981;
v_7981:
    v_8068 = nil;
v_7979:
    return onevalue(v_8068);
}



// Code for kernord!-split

static LispObject CC_kernordKsplit(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8090, v_8091, v_8092;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_7976;
    stack[-3] = v_7975;
// end of prologue
    stack[-4] = nil;
    stack[-1] = nil;
    v_8090 = stack[-3];
    fn = elt(env, 1); // powers
    v_8090 = (*qfn1(fn))(fn, v_8090);
    env = stack[-5];
    stack[-3] = v_8090;
    v_8090 = stack[-2];
    fn = elt(env, 1); // powers
    v_8090 = (*qfn1(fn))(fn, v_8090);
    env = stack[-5];
    stack[-2] = v_8090;
    v_8090 = stack[-3];
    stack[0] = v_8090;
v_7989:
    v_8090 = stack[0];
    if (v_8090 == nil) goto v_7993;
    else goto v_7994;
v_7993:
    goto v_7988;
v_7994:
    v_8090 = stack[0];
    v_8090 = qcar(v_8090);
    v_8092 = v_8090;
    goto v_8008;
v_8004:
    v_8090 = v_8092;
    v_8091 = qcar(v_8090);
    goto v_8005;
v_8006:
    v_8090 = stack[-2];
    goto v_8007;
v_8008:
    goto v_8004;
v_8005:
    goto v_8006;
v_8007:
    v_8090 = Lassoc(nil, v_8091, v_8090);
    if (v_8090 == nil) goto v_8003;
    goto v_8018;
v_8014:
    v_8091 = v_8092;
    goto v_8015;
v_8016:
    v_8090 = stack[-1];
    goto v_8017;
v_8018:
    goto v_8014;
v_8015:
    goto v_8016;
v_8017:
    v_8090 = cons(v_8091, v_8090);
    env = stack[-5];
    stack[-1] = v_8090;
    goto v_8001;
v_8003:
    goto v_8028;
v_8024:
    v_8091 = v_8092;
    goto v_8025;
v_8026:
    v_8090 = stack[-4];
    goto v_8027;
v_8028:
    goto v_8024;
v_8025:
    goto v_8026;
v_8027:
    v_8090 = cons(v_8091, v_8090);
    env = stack[-5];
    stack[-4] = v_8090;
    goto v_8001;
v_8001:
    v_8090 = stack[0];
    v_8090 = qcdr(v_8090);
    stack[0] = v_8090;
    goto v_7989;
v_7988:
    v_8090 = stack[-2];
    stack[0] = v_8090;
v_8036:
    v_8090 = stack[0];
    if (v_8090 == nil) goto v_8040;
    else goto v_8041;
v_8040:
    goto v_8035;
v_8041:
    v_8090 = stack[0];
    v_8090 = qcar(v_8090);
    v_8092 = v_8090;
    goto v_8055;
v_8051:
    v_8090 = v_8092;
    v_8091 = qcar(v_8090);
    goto v_8052;
v_8053:
    v_8090 = stack[-3];
    goto v_8054;
v_8055:
    goto v_8051;
v_8052:
    goto v_8053;
v_8054:
    v_8090 = Lassoc(nil, v_8091, v_8090);
    if (v_8090 == nil) goto v_8050;
    goto v_8065;
v_8061:
    v_8091 = v_8092;
    goto v_8062;
v_8063:
    v_8090 = stack[-1];
    goto v_8064;
v_8065:
    goto v_8061;
v_8062:
    goto v_8063;
v_8064:
    v_8090 = cons(v_8091, v_8090);
    env = stack[-5];
    stack[-1] = v_8090;
    goto v_8048;
v_8050:
    goto v_8075;
v_8071:
    v_8091 = v_8092;
    goto v_8072;
v_8073:
    v_8090 = stack[-4];
    goto v_8074;
v_8075:
    goto v_8071;
v_8072:
    goto v_8073;
v_8074:
    v_8090 = cons(v_8091, v_8090);
    env = stack[-5];
    stack[-4] = v_8090;
    goto v_8048;
v_8048:
    v_8090 = stack[0];
    v_8090 = qcdr(v_8090);
    stack[0] = v_8090;
    goto v_8036;
v_8035:
    goto v_8085;
v_8081:
    v_8090 = stack[-4];
    v_8091 = Lnreverse(nil, v_8090);
    env = stack[-5];
    goto v_8082;
v_8083:
    v_8090 = stack[-1];
    v_8090 = Lnreverse(nil, v_8090);
    goto v_8084;
v_8085:
    goto v_8081;
v_8082:
    goto v_8083;
v_8084:
    return cons(v_8091, v_8090);
    return onevalue(v_8090);
}



// Code for gsugar

static LispObject CC_gsugar(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_8037, v_8038;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7975);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7975;
// end of prologue
    v_8037 = qvalue(elt(env, 1)); // !*gsugar
    if (v_8037 == nil) goto v_7980;
    v_8037 = stack[0];
    if (v_8037 == nil) goto v_7988;
    else goto v_7989;
v_7988:
    v_8037 = lisp_true;
    goto v_7987;
v_7989:
    v_8037 = stack[0];
    v_8037 = qcdr(v_8037);
    v_8037 = qcdr(v_8037);
    v_8037 = qcdr(v_8037);
    v_8037 = qcar(v_8037);
    v_8037 = (v_8037 == nil ? lisp_true : nil);
    goto v_7987;
    v_8037 = nil;
v_7987:
    if (v_8037 == nil) goto v_7985;
    v_8037 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7983;
v_7985:
    goto v_8008;
v_8004:
    v_8038 = stack[0];
    goto v_8005;
v_8006:
    v_8037 = elt(env, 2); // sugar
    goto v_8007;
v_8008:
    goto v_8004;
v_8005:
    goto v_8006;
v_8007:
    fn = elt(env, 4); // vdpgetprop
    v_8037 = (*qfn2(fn))(fn, v_8038, v_8037);
    env = stack[-2];
    goto v_7983;
    v_8037 = nil;
v_7983:
    stack[-1] = v_8037;
    v_8037 = stack[-1];
    if (v_8037 == nil) goto v_8014;
    else goto v_8013;
v_8014:
    goto v_8022;
v_8018:
    v_8038 = elt(env, 3); // "*** missing sugar"
    goto v_8019;
v_8020:
    v_8037 = stack[0];
    goto v_8021;
v_8022:
    goto v_8018;
v_8019:
    goto v_8020;
v_8021:
    v_8037 = list2(v_8038, v_8037);
    env = stack[-2];
    v_8037 = Lprint(nil, v_8037);
    env = stack[-2];
    fn = elt(env, 5); // backtrace
    v_8037 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_8037 = stack[0];
    fn = elt(env, 6); // vdptdeg
    v_8037 = (*qfn1(fn))(fn, v_8037);
    env = stack[-2];
    stack[-1] = v_8037;
    goto v_8033;
v_8029:
    v_8038 = stack[0];
    goto v_8030;
v_8031:
    v_8037 = stack[-1];
    goto v_8032;
v_8033:
    goto v_8029;
v_8030:
    goto v_8031;
v_8032:
    fn = elt(env, 7); // gsetsugar
    v_8037 = (*qfn2(fn))(fn, v_8038, v_8037);
    v_8037 = stack[-1];
v_8013:
    goto v_7978;
v_7980:
    v_8037 = nil;
v_7978:
    return onevalue(v_8037);
}



// Code for remcomma

static LispObject CC_remcomma(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_7995, v_7996, v_7997;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7996 = v_7975;
// end of prologue
    goto v_7986;
v_7982:
    v_7995 = v_7996;
    goto v_7983;
v_7984:
    v_7997 = elt(env, 1); // !*comma!*
    goto v_7985;
v_7986:
    goto v_7982;
v_7983:
    goto v_7984;
v_7985:
    if (!consp(v_7995)) goto v_7980;
    v_7995 = qcar(v_7995);
    if (v_7995 == v_7997) goto v_7979;
    else goto v_7980;
v_7979:
    v_7995 = v_7996;
    v_7995 = qcdr(v_7995);
    goto v_7978;
v_7980:
    v_7995 = v_7996;
    return ncons(v_7995);
    v_7995 = nil;
v_7978:
    return onevalue(v_7995);
}



// Code for mv!-domainlist!-!*

static LispObject CC_mvKdomainlistKH(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8009, v_8010;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7976;
    stack[-1] = v_7975;
// end of prologue
    stack[-2] = nil;
v_7981:
    v_8009 = stack[0];
    if (v_8009 == nil) goto v_7984;
    else goto v_7985;
v_7984:
    v_8009 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_8009);
    }
v_7985:
    goto v_7996;
v_7992:
    goto v_8002;
v_7998:
    v_8010 = stack[-1];
    goto v_7999;
v_8000:
    v_8009 = stack[0];
    v_8009 = qcar(v_8009);
    goto v_8001;
v_8002:
    goto v_7998;
v_7999:
    goto v_8000;
v_8001:
    v_8010 = times2(v_8010, v_8009);
    env = stack[-3];
    goto v_7993;
v_7994:
    v_8009 = stack[-2];
    goto v_7995;
v_7996:
    goto v_7992;
v_7993:
    goto v_7994;
v_7995:
    v_8009 = cons(v_8010, v_8009);
    env = stack[-3];
    stack[-2] = v_8009;
    v_8009 = stack[0];
    v_8009 = qcdr(v_8009);
    stack[0] = v_8009;
    goto v_7981;
    v_8009 = nil;
    return onevalue(v_8009);
}



// Code for pv_times2

static LispObject CC_pv_times2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8011, v_8012;
    LispObject fn;
    LispObject v_7977, v_7976, v_7975;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pv_times2");
    va_start(aa, nargs);
    v_7975 = va_arg(aa, LispObject);
    v_7976 = va_arg(aa, LispObject);
    v_7977 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7977,v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7975,v_7976,v_7977);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7977;
    v_8011 = v_7976;
    stack[-1] = v_7975;
// end of prologue
v_7982:
    v_8012 = v_8011;
    if (v_8012 == nil) goto v_7985;
    else goto v_7986;
v_7985:
    v_8011 = stack[0];
    goto v_7981;
v_7986:
    v_8012 = v_8011;
    v_8012 = qcdr(v_8012);
    stack[-2] = v_8012;
    goto v_7998;
v_7994:
    goto v_8005;
v_8001:
    v_8012 = stack[-1];
    goto v_8002;
v_8003:
    v_8011 = qcar(v_8011);
    goto v_8004;
v_8005:
    goto v_8001;
v_8002:
    goto v_8003;
v_8004:
    fn = elt(env, 1); // pv_times3
    v_8011 = (*qfn2(fn))(fn, v_8012, v_8011);
    env = stack[-3];
    v_8012 = ncons(v_8011);
    env = stack[-3];
    goto v_7995;
v_7996:
    v_8011 = stack[0];
    goto v_7997;
v_7998:
    goto v_7994;
v_7995:
    goto v_7996;
v_7997:
    fn = elt(env, 2); // pv_add
    v_8011 = (*qfn2(fn))(fn, v_8012, v_8011);
    env = stack[-3];
    stack[0] = v_8011;
    v_8011 = stack[-2];
    goto v_7982;
    v_8011 = nil;
v_7981:
    return onevalue(v_8011);
}



// Code for tr_write

static LispObject CC_tr_write(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_8001, v_8002;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7975);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_8002 = v_7975;
// end of prologue
    v_8001 = qvalue(elt(env, 1)); // !*trsolve
    if (v_8001 == nil) goto v_7980;
    v_8001 = v_8002;
    stack[0] = v_8001;
v_7985:
    v_8001 = stack[0];
    if (v_8001 == nil) goto v_7989;
    else goto v_7990;
v_7989:
    goto v_7984;
v_7990:
    v_8001 = stack[0];
    v_8001 = qcar(v_8001);
    v_8001 = Lprinc(nil, v_8001);
    env = stack[-1];
    v_8001 = stack[0];
    v_8001 = qcdr(v_8001);
    stack[0] = v_8001;
    goto v_7985;
v_7984:
        return Lterpri(nil, 0);
v_7980:
    v_8001 = nil;
    return onevalue(v_8001);
}



// Code for conv!:mt

static LispObject CC_convTmt(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8130, v_8131;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_7976;
    stack[-2] = v_7975;
// end of prologue
    goto v_7995;
v_7991:
    v_8131 = stack[-2];
    goto v_7992;
v_7993:
    v_8130 = elt(env, 1); // !:rd!:
    goto v_7994;
v_7995:
    goto v_7991;
v_7992:
    goto v_7993;
v_7994:
    if (!consp(v_8131)) goto v_7989;
    v_8131 = qcar(v_8131);
    if (v_8131 == v_8130) goto v_7988;
    else goto v_7989;
v_7988:
    v_8130 = stack[-2];
    v_8130 = qcdr(v_8130);
    v_8130 = (consp(v_8130) ? nil : lisp_true);
    v_8130 = (v_8130 == nil ? lisp_true : nil);
    goto v_7987;
v_7989:
    v_8130 = nil;
    goto v_7987;
    v_8130 = nil;
v_7987:
    if (v_8130 == nil) goto v_7985;
    v_8130 = stack[0];
    v_8130 = integerp(v_8130);
    if (v_8130 == nil) goto v_8007;
    else goto v_8008;
v_8007:
    v_8130 = nil;
    goto v_8006;
v_8008:
    goto v_8019;
v_8015:
    v_8131 = stack[0];
    goto v_8016;
v_8017:
    v_8130 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8018;
v_8019:
    goto v_8015;
v_8016:
    goto v_8017;
v_8018:
    v_8130 = (LispObject)greaterp2(v_8131, v_8130);
    v_8130 = v_8130 ? lisp_true : nil;
    env = stack[-4];
    goto v_8006;
    v_8130 = nil;
v_8006:
    goto v_7983;
v_7985:
    v_8130 = nil;
    goto v_7983;
    v_8130 = nil;
v_7983:
    if (v_8130 == nil) goto v_7981;
    goto v_8033;
v_8029:
    goto v_8039;
v_8035:
    v_8130 = stack[-2];
    v_8130 = qcdr(v_8130);
    v_8130 = qcar(v_8130);
    v_8130 = Labsval(nil, v_8130);
    env = stack[-4];
    fn = elt(env, 2); // msd
    v_8131 = (*qfn1(fn))(fn, v_8130);
    env = stack[-4];
    goto v_8036;
v_8037:
    v_8130 = stack[0];
    goto v_8038;
v_8039:
    goto v_8035;
v_8036:
    goto v_8037;
v_8038:
    v_8131 = difference2(v_8131, v_8130);
    env = stack[-4];
    stack[0] = v_8131;
    goto v_8030;
v_8031:
    v_8130 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8032;
v_8033:
    goto v_8029;
v_8030:
    goto v_8031;
v_8032:
    if (v_8131 == v_8130) goto v_8027;
    else goto v_8028;
v_8027:
    v_8130 = stack[-2];
    goto v_8026;
v_8028:
    goto v_8055;
v_8051:
    v_8131 = stack[0];
    goto v_8052;
v_8053:
    v_8130 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8054;
v_8055:
    goto v_8051;
v_8052:
    goto v_8053;
v_8054:
    v_8130 = (LispObject)lessp2(v_8131, v_8130);
    v_8130 = v_8130 ? lisp_true : nil;
    env = stack[-4];
    if (v_8130 == nil) goto v_8049;
    v_8130 = stack[0];
    v_8130 = negate(v_8130);
    env = stack[-4];
    stack[-3] = v_8130;
    goto v_8068;
v_8062:
    stack[-1] = elt(env, 1); // !:rd!:
    goto v_8063;
v_8064:
    goto v_8075;
v_8071:
    v_8130 = stack[-2];
    v_8130 = qcdr(v_8130);
    v_8131 = qcar(v_8130);
    goto v_8072;
v_8073:
    v_8130 = stack[-3];
    goto v_8074;
v_8075:
    goto v_8071;
v_8072:
    goto v_8073;
v_8074:
    fn = elt(env, 3); // ashift
    stack[0] = (*qfn2(fn))(fn, v_8131, v_8130);
    env = stack[-4];
    goto v_8065;
v_8066:
    goto v_8085;
v_8081:
    v_8130 = stack[-2];
    v_8130 = qcdr(v_8130);
    v_8131 = qcdr(v_8130);
    goto v_8082;
v_8083:
    v_8130 = stack[-3];
    goto v_8084;
v_8085:
    goto v_8081;
v_8082:
    goto v_8083;
v_8084:
    v_8130 = difference2(v_8131, v_8130);
    goto v_8067;
v_8068:
    goto v_8062;
v_8063:
    goto v_8064;
v_8065:
    goto v_8066;
v_8067:
    {
        LispObject v_8136 = stack[-1];
        LispObject v_8137 = stack[0];
        return list2star(v_8136, v_8137, v_8130);
    }
v_8049:
    v_8130 = stack[0];
    v_8130 = sub1(v_8130);
    env = stack[-4];
    stack[-3] = v_8130;
    goto v_8103;
v_8097:
    stack[-1] = elt(env, 1); // !:rd!:
    goto v_8098;
v_8099:
    goto v_8110;
v_8106:
    v_8130 = stack[-2];
    v_8130 = qcdr(v_8130);
    stack[0] = qcar(v_8130);
    goto v_8107;
v_8108:
    v_8130 = stack[-3];
    v_8130 = negate(v_8130);
    env = stack[-4];
    goto v_8109;
v_8110:
    goto v_8106;
v_8107:
    goto v_8108;
v_8109:
    fn = elt(env, 3); // ashift
    stack[0] = (*qfn2(fn))(fn, stack[0], v_8130);
    env = stack[-4];
    goto v_8100;
v_8101:
    goto v_8121;
v_8117:
    v_8130 = stack[-2];
    v_8130 = qcdr(v_8130);
    v_8131 = qcdr(v_8130);
    goto v_8118;
v_8119:
    v_8130 = stack[-3];
    goto v_8120;
v_8121:
    goto v_8117;
v_8118:
    goto v_8119;
v_8120:
    v_8130 = plus2(v_8131, v_8130);
    env = stack[-4];
    goto v_8102;
v_8103:
    goto v_8097;
v_8098:
    goto v_8099;
v_8100:
    goto v_8101;
v_8102:
    v_8130 = list2star(stack[-1], stack[0], v_8130);
    env = stack[-4];
    {
        fn = elt(env, 4); // round!:last
        return (*qfn1(fn))(fn, v_8130);
    }
    v_8130 = nil;
v_8026:
    goto v_7979;
v_7981:
    v_8130 = elt(env, 0); // conv!:mt
    {
        fn = elt(env, 5); // bflerrmsg
        return (*qfn1(fn))(fn, v_8130);
    }
    v_8130 = nil;
v_7979:
    return onevalue(v_8130);
}



// Code for multd!*

static LispObject CC_multdH(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8027, v_8028;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7976;
    stack[-1] = v_7975;
// end of prologue
    goto v_7987;
v_7983:
    v_8028 = stack[0];
    goto v_7984;
v_7985:
    v_8027 = elt(env, 1); // kernel
    goto v_7986;
v_7987:
    goto v_7983;
v_7984:
    goto v_7985;
v_7986:
    fn = elt(env, 2); // xtype
    v_8027 = (*qfn2(fn))(fn, v_8028, v_8027);
    env = stack[-2];
    if (v_8027 == nil) goto v_7981;
    goto v_7995;
v_7991:
    v_8027 = stack[-1];
    fn = elt(env, 3); // value
    stack[-1] = (*qfn1(fn))(fn, v_8027);
    env = stack[-2];
    goto v_7992;
v_7993:
    goto v_8004;
v_8000:
    goto v_8010;
v_8006:
    v_8027 = stack[0];
    fn = elt(env, 3); // value
    v_8028 = (*qfn1(fn))(fn, v_8027);
    env = stack[-2];
    goto v_8007;
v_8008:
    v_8027 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8009;
v_8010:
    goto v_8006;
v_8007:
    goto v_8008;
v_8009:
    fn = elt(env, 4); // to
    v_8028 = (*qfn2(fn))(fn, v_8028, v_8027);
    env = stack[-2];
    goto v_8001;
v_8002:
    v_8027 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8003;
v_8004:
    goto v_8000;
v_8001:
    goto v_8002;
v_8003:
    v_8027 = cons(v_8028, v_8027);
    env = stack[-2];
    v_8027 = ncons(v_8027);
    env = stack[-2];
    goto v_7994;
v_7995:
    goto v_7991;
v_7992:
    goto v_7993;
v_7994:
    {
        LispObject v_8031 = stack[-1];
        fn = elt(env, 5); // multd
        return (*qfn2(fn))(fn, v_8031, v_8027);
    }
v_7981:
    goto v_8022;
v_8018:
    v_8027 = stack[-1];
    fn = elt(env, 3); // value
    stack[-1] = (*qfn1(fn))(fn, v_8027);
    env = stack[-2];
    goto v_8019;
v_8020:
    v_8027 = stack[0];
    fn = elt(env, 3); // value
    v_8027 = (*qfn1(fn))(fn, v_8027);
    env = stack[-2];
    goto v_8021;
v_8022:
    goto v_8018;
v_8019:
    goto v_8020;
v_8021:
    {
        LispObject v_8032 = stack[-1];
        fn = elt(env, 5); // multd
        return (*qfn2(fn))(fn, v_8032, v_8027);
    }
    v_8027 = nil;
    return onevalue(v_8027);
}



// Code for reduce!-degree!-mod!-p

static LispObject CC_reduceKdegreeKmodKp(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8073, v_8074, v_8075;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7976;
    stack[-1] = v_7975;
// end of prologue
    goto v_7987;
v_7983:
    v_8073 = stack[-1];
    v_8073 = qcar(v_8073);
    v_8073 = qcdr(v_8073);
    {   intptr_t w = int_of_fixnum(v_8073);
        if (w != 0) w = current_modulus - w;
        v_8074 = fixnum_of_int(w);
    }
    goto v_7984;
v_7985:
    v_8073 = stack[0];
    v_8073 = qcar(v_8073);
    v_8073 = qcdr(v_8073);
    goto v_7986;
v_7987:
    goto v_7983;
v_7984:
    goto v_7985;
v_7986:
    v_8073 = Lmodular_quotient(nil, v_8074, v_8073);
    env = stack[-3];
    stack[-2] = v_8073;
    goto v_7999;
v_7995:
    v_8073 = stack[-1];
    v_8073 = qcar(v_8073);
    v_8073 = qcar(v_8073);
    v_8074 = qcdr(v_8073);
    goto v_7996;
v_7997:
    v_8073 = stack[0];
    v_8073 = qcar(v_8073);
    v_8073 = qcar(v_8073);
    v_8073 = qcdr(v_8073);
    goto v_7998;
v_7999:
    goto v_7995;
v_7996:
    goto v_7997;
v_7998:
    v_8073 = (LispObject)(intptr_t)((intptr_t)v_8074 - (intptr_t)v_8073 + TAG_FIXNUM);
    v_8075 = v_8073;
    goto v_8017;
v_8013:
    v_8074 = v_8075;
    goto v_8014;
v_8015:
    v_8073 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8016;
v_8017:
    goto v_8013;
v_8014:
    goto v_8015;
v_8016:
    if (v_8074 == v_8073) goto v_8011;
    else goto v_8012;
v_8011:
    goto v_8025;
v_8021:
    v_8073 = stack[-1];
    stack[-1] = qcdr(v_8073);
    goto v_8022;
v_8023:
    goto v_8033;
v_8029:
    v_8073 = stack[0];
    v_8074 = qcdr(v_8073);
    goto v_8030;
v_8031:
    v_8073 = stack[-2];
    goto v_8032;
v_8033:
    goto v_8029;
v_8030:
    goto v_8031;
v_8032:
    fn = elt(env, 1); // multiply!-by!-constant!-mod!-p
    v_8073 = (*qfn2(fn))(fn, v_8074, v_8073);
    env = stack[-3];
    goto v_8024;
v_8025:
    goto v_8021;
v_8022:
    goto v_8023;
v_8024:
    {
        LispObject v_8079 = stack[-1];
        fn = elt(env, 2); // plus!-mod!-p
        return (*qfn2(fn))(fn, v_8079, v_8073);
    }
v_8012:
    goto v_8044;
v_8040:
    v_8073 = stack[-1];
    stack[-1] = qcdr(v_8073);
    goto v_8041;
v_8042:
    goto v_8052;
v_8048:
    goto v_8058;
v_8054:
    goto v_8064;
v_8060:
    v_8073 = stack[0];
    v_8073 = qcar(v_8073);
    v_8073 = qcar(v_8073);
    v_8073 = qcar(v_8073);
    goto v_8061;
v_8062:
    v_8074 = v_8075;
    goto v_8063;
v_8064:
    goto v_8060;
v_8061:
    goto v_8062;
v_8063:
    fn = elt(env, 3); // mksp
    v_8074 = (*qfn2(fn))(fn, v_8073, v_8074);
    env = stack[-3];
    goto v_8055;
v_8056:
    v_8073 = stack[-2];
    goto v_8057;
v_8058:
    goto v_8054;
v_8055:
    goto v_8056;
v_8057:
    v_8074 = cons(v_8074, v_8073);
    env = stack[-3];
    goto v_8049;
v_8050:
    v_8073 = stack[0];
    v_8073 = qcdr(v_8073);
    goto v_8051;
v_8052:
    goto v_8048;
v_8049:
    goto v_8050;
v_8051:
    fn = elt(env, 4); // times!-term!-mod!-p
    v_8073 = (*qfn2(fn))(fn, v_8074, v_8073);
    env = stack[-3];
    goto v_8043;
v_8044:
    goto v_8040;
v_8041:
    goto v_8042;
v_8043:
    {
        LispObject v_8080 = stack[-1];
        fn = elt(env, 2); // plus!-mod!-p
        return (*qfn2(fn))(fn, v_8080, v_8073);
    }
    v_8073 = nil;
    return onevalue(v_8073);
}



// Code for lalr_make_compressed_action_row1

static LispObject CC_lalr_make_compressed_action_row1(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_8125, v_8126, v_8127, v_8128, v_8129;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7975);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_7975;
// end of prologue
    stack[-2] = nil;
    v_8125 = stack[0];
    fn = elt(env, 4); // lalr_most_common_reduction
    v_8125 = (*qfn1(fn))(fn, v_8125);
    env = stack[-4];
    stack[-3] = v_8125;
    v_8125 = stack[0];
    stack[-1] = v_8125;
v_7988:
    v_8125 = stack[-1];
    if (v_8125 == nil) goto v_7992;
    else goto v_7993;
v_7992:
    goto v_7987;
v_7993:
    v_8125 = stack[-1];
    v_8125 = qcar(v_8125);
    v_8127 = v_8125;
    goto v_8007;
v_8003:
    v_8125 = v_8127;
    v_8125 = qcdr(v_8125);
    v_8126 = qcar(v_8125);
    goto v_8004;
v_8005:
    v_8125 = stack[-3];
    goto v_8006;
v_8007:
    goto v_8003;
v_8004:
    goto v_8005;
v_8006:
    if (equal(v_8126, v_8125)) goto v_8002;
    v_8125 = v_8127;
    v_8125 = qcar(v_8125);
    v_8129 = v_8125;
    v_8125 = v_8127;
    v_8125 = qcdr(v_8125);
    v_8125 = qcar(v_8125);
    v_8125 = qcar(v_8125);
    v_8128 = v_8125;
    goto v_8026;
v_8022:
    v_8126 = v_8128;
    goto v_8023;
v_8024:
    v_8125 = elt(env, 1); // shift
    goto v_8025;
v_8026:
    goto v_8022;
v_8023:
    goto v_8024;
v_8025:
    if (v_8126 == v_8125) goto v_8020;
    else goto v_8021;
v_8020:
    goto v_8036;
v_8030:
    v_8126 = v_8129;
    goto v_8031;
v_8032:
    v_8125 = v_8127;
    v_8125 = qcdr(v_8125);
    v_8125 = qcar(v_8125);
    v_8125 = qcdr(v_8125);
    v_8127 = qcar(v_8125);
    goto v_8033;
v_8034:
    v_8125 = stack[-2];
    goto v_8035;
v_8036:
    goto v_8030;
v_8031:
    goto v_8032;
v_8033:
    goto v_8034;
v_8035:
    v_8125 = acons(v_8126, v_8127, v_8125);
    env = stack[-4];
    stack[-2] = v_8125;
    goto v_8019;
v_8021:
    goto v_8050;
v_8046:
    v_8126 = v_8128;
    goto v_8047;
v_8048:
    v_8125 = elt(env, 2); // accept
    goto v_8049;
v_8050:
    goto v_8046;
v_8047:
    goto v_8048;
v_8049:
    if (v_8126 == v_8125) goto v_8044;
    else goto v_8045;
v_8044:
    goto v_8060;
v_8054:
    v_8127 = v_8129;
    goto v_8055;
v_8056:
    v_8126 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8057;
v_8058:
    v_8125 = stack[-2];
    goto v_8059;
v_8060:
    goto v_8054;
v_8055:
    goto v_8056;
v_8057:
    goto v_8058;
v_8059:
    v_8125 = acons(v_8127, v_8126, v_8125);
    env = stack[-4];
    stack[-2] = v_8125;
    goto v_8019;
v_8045:
    goto v_8070;
v_8066:
    v_8126 = v_8128;
    goto v_8067;
v_8068:
    v_8125 = elt(env, 3); // reduce
    goto v_8069;
v_8070:
    goto v_8066;
v_8067:
    goto v_8068;
v_8069:
    if (v_8126 == v_8125) goto v_8064;
    else goto v_8065;
v_8064:
    goto v_8080;
v_8074:
    stack[0] = v_8129;
    goto v_8075;
v_8076:
    v_8125 = v_8127;
    v_8125 = qcdr(v_8125);
    v_8125 = qcar(v_8125);
    v_8125 = qcdr(v_8125);
    v_8125 = qcdr(v_8125);
    v_8125 = qcar(v_8125);
    v_8126 = negate(v_8125);
    env = stack[-4];
    goto v_8077;
v_8078:
    v_8125 = stack[-2];
    goto v_8079;
v_8080:
    goto v_8074;
v_8075:
    goto v_8076;
v_8077:
    goto v_8078;
v_8079:
    v_8125 = acons(stack[0], v_8126, v_8125);
    env = stack[-4];
    stack[-2] = v_8125;
    goto v_8019;
v_8065:
v_8019:
    goto v_8000;
v_8002:
v_8000:
    v_8125 = stack[-1];
    v_8125 = qcdr(v_8125);
    stack[-1] = v_8125;
    goto v_7988;
v_7987:
    v_8125 = stack[-3];
    if (v_8125 == nil) goto v_8095;
    goto v_8105;
v_8101:
    v_8125 = stack[-3];
    v_8126 = qcar(v_8125);
    goto v_8102;
v_8103:
    v_8125 = elt(env, 2); // accept
    goto v_8104;
v_8105:
    goto v_8101;
v_8102:
    goto v_8103;
v_8104:
    if (v_8126 == v_8125) goto v_8099;
    else goto v_8100;
v_8099:
    v_8125 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8098;
v_8100:
    v_8125 = stack[-3];
    v_8125 = qcdr(v_8125);
    v_8125 = qcdr(v_8125);
    v_8125 = qcar(v_8125);
    v_8125 = negate(v_8125);
    goto v_8098;
    v_8125 = nil;
v_8098:
    stack[-3] = v_8125;
    goto v_8093;
v_8095:
v_8093:
    goto v_8122;
v_8118:
    v_8126 = stack[-2];
    goto v_8119;
v_8120:
    v_8125 = stack[-3];
    goto v_8121;
v_8122:
    goto v_8118;
v_8119:
    goto v_8120;
v_8121:
    return cons(v_8126, v_8125);
    return onevalue(v_8125);
}



// Code for updtemplate

static LispObject CC_updtemplate(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8099, v_8100, v_8101;
    LispObject fn;
    LispObject v_7977, v_7976, v_7975;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "updtemplate");
    va_start(aa, nargs);
    v_7975 = va_arg(aa, LispObject);
    v_7976 = va_arg(aa, LispObject);
    v_7977 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7977,v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7975,v_7976,v_7977);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_7977;
    v_8099 = v_7976;
    stack[-6] = v_7975;
// end of prologue
    stack[-4] = v_8099;
    v_8099 = stack[-4];
    if (v_8099 == nil) goto v_7992;
    else goto v_7993;
v_7992:
    v_8099 = nil;
    goto v_7987;
v_7993:
    v_8099 = stack[-4];
    v_8099 = qcar(v_8099);
    stack[0] = v_8099;
    goto v_8008;
v_8004:
    goto v_8014;
v_8010:
    v_8100 = stack[-6];
    goto v_8011;
v_8012:
    v_8099 = stack[0];
    goto v_8013;
v_8014:
    goto v_8010;
v_8011:
    goto v_8012;
v_8013:
    v_8100 = Lsubla(nil, v_8100, v_8099);
    env = stack[-8];
    stack[-7] = v_8100;
    goto v_8005;
v_8006:
    v_8099 = stack[0];
    goto v_8007;
v_8008:
    goto v_8004;
v_8005:
    goto v_8006;
v_8007:
    if (equal(v_8100, v_8099)) goto v_8002;
    else goto v_8003;
v_8002:
    v_8099 = stack[0];
    goto v_8001;
v_8003:
    goto v_8025;
v_8021:
    goto v_8031;
v_8027:
    v_8100 = stack[-7];
    goto v_8028;
v_8029:
    v_8099 = stack[-5];
    goto v_8030;
v_8031:
    goto v_8027;
v_8028:
    goto v_8029;
v_8030:
    fn = elt(env, 1); // reval!-without
    v_8100 = (*qfn2(fn))(fn, v_8100, v_8099);
    env = stack[-8];
    v_8101 = v_8100;
    goto v_8022;
v_8023:
    v_8099 = stack[-7];
    goto v_8024;
v_8025:
    goto v_8021;
v_8022:
    goto v_8023;
v_8024:
    if (equal(v_8100, v_8099)) goto v_8020;
    v_8099 = v_8101;
    goto v_8001;
v_8020:
    v_8099 = stack[-7];
    goto v_8001;
    v_8099 = nil;
v_8001:
    v_8099 = ncons(v_8099);
    env = stack[-8];
    stack[-2] = v_8099;
    stack[-3] = v_8099;
v_7988:
    v_8099 = stack[-4];
    v_8099 = qcdr(v_8099);
    stack[-4] = v_8099;
    v_8099 = stack[-4];
    if (v_8099 == nil) goto v_8043;
    else goto v_8044;
v_8043:
    v_8099 = stack[-3];
    goto v_7987;
v_8044:
    goto v_8052;
v_8048:
    stack[-1] = stack[-2];
    goto v_8049;
v_8050:
    v_8099 = stack[-4];
    v_8099 = qcar(v_8099);
    stack[0] = v_8099;
    goto v_8066;
v_8062:
    goto v_8072;
v_8068:
    v_8100 = stack[-6];
    goto v_8069;
v_8070:
    v_8099 = stack[0];
    goto v_8071;
v_8072:
    goto v_8068;
v_8069:
    goto v_8070;
v_8071:
    v_8100 = Lsubla(nil, v_8100, v_8099);
    env = stack[-8];
    stack[-7] = v_8100;
    goto v_8063;
v_8064:
    v_8099 = stack[0];
    goto v_8065;
v_8066:
    goto v_8062;
v_8063:
    goto v_8064;
v_8065:
    if (equal(v_8100, v_8099)) goto v_8060;
    else goto v_8061;
v_8060:
    v_8099 = stack[0];
    goto v_8059;
v_8061:
    goto v_8083;
v_8079:
    goto v_8089;
v_8085:
    v_8100 = stack[-7];
    goto v_8086;
v_8087:
    v_8099 = stack[-5];
    goto v_8088;
v_8089:
    goto v_8085;
v_8086:
    goto v_8087;
v_8088:
    fn = elt(env, 1); // reval!-without
    v_8100 = (*qfn2(fn))(fn, v_8100, v_8099);
    env = stack[-8];
    v_8101 = v_8100;
    goto v_8080;
v_8081:
    v_8099 = stack[-7];
    goto v_8082;
v_8083:
    goto v_8079;
v_8080:
    goto v_8081;
v_8082:
    if (equal(v_8100, v_8099)) goto v_8078;
    v_8099 = v_8101;
    goto v_8059;
v_8078:
    v_8099 = stack[-7];
    goto v_8059;
    v_8099 = nil;
v_8059:
    v_8099 = ncons(v_8099);
    env = stack[-8];
    goto v_8051;
v_8052:
    goto v_8048;
v_8049:
    goto v_8050;
v_8051:
    v_8099 = Lrplacd(nil, stack[-1], v_8099);
    env = stack[-8];
    v_8099 = stack[-2];
    v_8099 = qcdr(v_8099);
    stack[-2] = v_8099;
    goto v_7988;
v_7987:
    return onevalue(v_8099);
}



// Code for talp_subalchk

static LispObject CC_talp_subalchk(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_7978;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7978 = v_7975;
// end of prologue
    v_7978 = nil;
    return onevalue(v_7978);
}



// Code for qqe_arg!-check!-b

static LispObject CC_qqe_argKcheckKb(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_8030;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7975);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_7975;
// end of prologue
    v_8030 = stack[0];
    fn = elt(env, 1); // qqe_id!-nyt!-branchb
    v_8030 = (*qfn1(fn))(fn, v_8030);
    env = stack[-1];
    if (v_8030 == nil) goto v_7981;
    else goto v_7982;
v_7981:
    v_8030 = nil;
    goto v_7978;
v_7982:
    v_8030 = stack[0];
    if (!consp(v_8030)) goto v_7990;
    else goto v_7991;
v_7990:
    v_8030 = stack[0];
    v_8030 = (is_number(v_8030) ? lisp_true : nil);
    v_8030 = (v_8030 == nil ? lisp_true : nil);
    goto v_7989;
v_7991:
    v_8030 = nil;
    goto v_7989;
    v_8030 = nil;
v_7989:
    if (v_8030 == nil) goto v_7987;
    v_8030 = stack[0];
    fn = elt(env, 2); // qqe_qtidp
    v_8030 = (*qfn1(fn))(fn, v_8030);
    env = stack[-1];
    if (v_8030 == nil) goto v_8002;
    v_8030 = nil;
    goto v_7978;
v_8002:
    v_8030 = stack[0];
    fn = elt(env, 3); // qqe_nytidp
    v_8030 = (*qfn1(fn))(fn, v_8030);
    env = stack[-1];
    if (v_8030 == nil) goto v_8007;
    v_8030 = stack[0];
    fn = elt(env, 4); // qqe_btid
    v_8030 = (*qfn1(fn))(fn, v_8030);
    env = stack[-1];
    v_8030 = stack[0];
    fn = elt(env, 5); // qqe_add2rollbackids
    v_8030 = (*qfn1(fn))(fn, v_8030);
    v_8030 = lisp_true;
    goto v_7978;
v_8007:
    v_8030 = lisp_true;
    goto v_7978;
    goto v_7980;
v_7987:
    v_8030 = stack[0];
    if (!consp(v_8030)) goto v_8021;
    v_8030 = stack[0];
    fn = elt(env, 6); // qqe_arg!-check
    v_8030 = (*qfn1(fn))(fn, v_8030);
    v_8030 = lisp_true;
    goto v_7978;
v_8021:
    v_8030 = lisp_true;
    goto v_7978;
v_7980:
    v_8030 = nil;
v_7978:
    return onevalue(v_8030);
}



// Code for mapins

static LispObject CC_mapins(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8015, v_8016, v_8017;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7976;
    stack[-1] = v_7975;
// end of prologue
    stack[-2] = nil;
v_7981:
    v_8015 = stack[0];
    if (v_8015 == nil) goto v_7984;
    else goto v_7985;
v_7984:
    v_8015 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_8015);
    }
v_7985:
    goto v_7998;
v_7992:
    goto v_8004;
v_8000:
    v_8016 = stack[-1];
    goto v_8001;
v_8002:
    v_8015 = stack[0];
    v_8015 = qcar(v_8015);
    v_8015 = qcar(v_8015);
    goto v_8003;
v_8004:
    goto v_8000;
v_8001:
    goto v_8002;
v_8003:
    v_8017 = cons(v_8016, v_8015);
    env = stack[-3];
    goto v_7993;
v_7994:
    v_8015 = stack[0];
    v_8015 = qcar(v_8015);
    v_8016 = qcdr(v_8015);
    goto v_7995;
v_7996:
    v_8015 = stack[-2];
    goto v_7997;
v_7998:
    goto v_7992;
v_7993:
    goto v_7994;
v_7995:
    goto v_7996;
v_7997:
    v_8015 = acons(v_8017, v_8016, v_8015);
    env = stack[-3];
    stack[-2] = v_8015;
    v_8015 = stack[0];
    v_8015 = qcdr(v_8015);
    stack[0] = v_8015;
    goto v_7981;
    v_8015 = nil;
    return onevalue(v_8015);
}



// Code for cird

static LispObject CC_cird(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8031, v_8032, v_8033;
    LispObject fn;
    argcheck(nargs, 0, "cird");
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
    goto v_7991;
v_7987:
    v_8032 = qvalue(elt(env, 1)); // atts
    goto v_7988;
v_7989:
    v_8031 = elt(env, 2); // (type)
    goto v_7990;
v_7991:
    goto v_7987;
v_7988:
    goto v_7989;
v_7990:
    fn = elt(env, 5); // retattributes
    v_8031 = (*qfn2(fn))(fn, v_8032, v_8031);
    env = stack[-2];
    stack[0] = v_8031;
    fn = elt(env, 6); // lex
    v_8031 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_8031 = qvalue(elt(env, 3)); // char
    stack[-1] = v_8031;
    fn = elt(env, 6); // lex
    v_8031 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_8031 = stack[-1];
    v_8031 = Lcompress(nil, v_8031);
    env = stack[-2];
    v_8032 = v_8031;
    v_8031 = v_8032;
    if (is_number(v_8031)) goto v_8001;
    else goto v_8002;
v_8001:
    goto v_8009;
v_8005:
    goto v_8006;
v_8007:
    v_8031 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_8008;
v_8009:
    goto v_8005;
v_8006:
    goto v_8007;
v_8008:
    fn = elt(env, 7); // errorml
    v_8031 = (*qfn2(fn))(fn, v_8032, v_8031);
    env = stack[-2];
    goto v_8000;
v_8002:
v_8000:
    v_8031 = stack[-1];
    fn = elt(env, 8); // compress!*
    v_8031 = (*qfn1(fn))(fn, v_8031);
    env = stack[-2];
    v_8032 = v_8031;
    v_8031 = stack[0];
    if (v_8031 == nil) goto v_8016;
    else goto v_8017;
v_8016:
    v_8031 = v_8032;
    goto v_7982;
v_8017:
    goto v_8027;
v_8021:
    v_8033 = elt(env, 4); // ci
    goto v_8022;
v_8023:
    v_8031 = stack[0];
    goto v_8024;
v_8025:
    goto v_8026;
v_8027:
    goto v_8021;
v_8022:
    goto v_8023;
v_8024:
    goto v_8025;
v_8026:
    return list3(v_8033, v_8031, v_8032);
v_7982:
    return onevalue(v_8031);
}



// Code for getcomb

static LispObject CC_getcomb(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8016, v_8017;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_8016 = v_7976;
    stack[0] = v_7975;
// end of prologue
    goto v_7986;
v_7982:
    v_8017 = v_8016;
    goto v_7983;
v_7984:
    v_8016 = qvalue(elt(env, 1)); // i
    goto v_7985;
v_7986:
    goto v_7982;
v_7983:
    goto v_7984;
v_7985:
    fn = elt(env, 3); // nextcomb
    v_8016 = (*qfn2(fn))(fn, v_8017, v_8016);
    env = stack[-2];
    qvalue(elt(env, 2)) = v_8016; // comb
    v_8016 = qvalue(elt(env, 2)); // comb
    v_8016 = qcar(v_8016);
    v_8017 = qvalue(elt(env, 2)); // comb
    v_8017 = qcdr(v_8017);
    qvalue(elt(env, 2)) = v_8017; // comb
    v_8017 = v_8016;
    if (v_8017 == nil) goto v_7996;
    goto v_8003;
v_7999:
    stack[-1] = v_8016;
    goto v_8000;
v_8001:
    goto v_8010;
v_8006:
    v_8017 = stack[0];
    goto v_8007;
v_8008:
    goto v_8009;
v_8010:
    goto v_8006;
v_8007:
    goto v_8008;
v_8009:
    fn = elt(env, 4); // setdiff
    v_8016 = (*qfn2(fn))(fn, v_8017, v_8016);
    goto v_8002;
v_8003:
    goto v_7999;
v_8000:
    goto v_8001;
v_8002:
    {
        LispObject v_8020 = stack[-1];
        return cons(v_8020, v_8016);
    }
v_7996:
    v_8016 = nil;
    goto v_7994;
    v_8016 = nil;
v_7994:
    return onevalue(v_8016);
}



// Code for setdmode1

static LispObject CC_setdmode1(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8154, v_8155, v_8156, v_8157;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    v_8155 = v_7976;
    stack[-5] = v_7975;
// end of prologue
    goto v_7988;
v_7984:
    v_8156 = stack[-5];
    goto v_7985;
v_7986:
    v_8154 = elt(env, 1); // tag
    goto v_7987;
v_7988:
    goto v_7984;
v_7985:
    goto v_7986;
v_7987:
    v_8154 = get(v_8156, v_8154);
    env = stack[-7];
    stack[-6] = v_8154;
    v_8154 = qvalue(elt(env, 2)); // dmode!*
    stack[-4] = v_8154;
    v_8154 = v_8155;
    if (v_8154 == nil) goto v_7994;
    else goto v_7995;
v_7994:
    v_8154 = stack[-4];
    if (v_8154 == nil) goto v_7999;
    else goto v_8000;
v_7999:
    v_8154 = nil;
    goto v_7998;
v_8000:
    goto v_8009;
v_8005:
    v_8155 = stack[-5];
    goto v_8006;
v_8007:
    v_8154 = stack[-4];
    if (!symbolp(v_8154)) v_8154 = nil;
    else { v_8154 = qfastgets(v_8154);
           if (v_8154 != nil) { v_8154 = elt(v_8154, 8); // dname
#ifdef RECORD_GET
             if (v_8154 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_8154 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_8154 == SPID_NOPROP) v_8154 = nil; }}
#endif
    stack[-4] = v_8154;
    goto v_8008;
v_8009:
    goto v_8005;
v_8006:
    goto v_8007;
v_8008:
    if (v_8155 == v_8154) goto v_8003;
    else goto v_8004;
v_8003:
    fn = elt(env, 11); // rmsubs
    v_8154 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    v_8154 = nil;
    qvalue(elt(env, 2)) = v_8154; // dmode!*
    qvalue(elt(env, 3)) = v_8154; // gdmode!*
    v_8154 = stack[-4];
    goto v_7998;
v_8004:
    goto v_8023;
v_8019:
    v_8155 = stack[-5];
    goto v_8020;
v_8021:
    v_8154 = stack[-4];
    goto v_8022;
v_8023:
    goto v_8019;
v_8020:
    goto v_8021;
v_8022:
    {
        fn = elt(env, 12); // offmoderr
        return (*qfn2(fn))(fn, v_8155, v_8154);
    }
    v_8154 = nil;
v_7998:
    goto v_7982;
v_7995:
    goto v_8036;
v_8032:
    v_8155 = stack[-5];
    goto v_8033;
v_8034:
    v_8154 = elt(env, 4); // (rounded complex!-rounded)
    goto v_8035;
v_8036:
    goto v_8032;
v_8033:
    goto v_8034;
v_8035:
    v_8154 = Lmemq(nil, v_8155, v_8154);
    if (v_8154 == nil) goto v_8031;
    fn = elt(env, 13); // !!mfefix
    v_8154 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    goto v_8029;
v_8031:
v_8029:
    goto v_8049;
v_8045:
    v_8155 = stack[-6];
    goto v_8046;
v_8047:
    v_8154 = stack[-4];
    goto v_8048;
v_8049:
    goto v_8045;
v_8046:
    goto v_8047;
v_8048:
    if (v_8155 == v_8154) goto v_8043;
    else goto v_8044;
v_8043:
    v_8154 = stack[-6];
    goto v_7982;
v_8044:
    goto v_7993;
v_7993:
    goto v_8062;
v_8058:
    v_8155 = stack[-6];
    goto v_8059;
v_8060:
    v_8154 = elt(env, 5); // realtype
    goto v_8061;
v_8062:
    goto v_8058;
v_8059:
    goto v_8060;
v_8061:
    v_8154 = get(v_8155, v_8154);
    env = stack[-7];
    stack[-3] = v_8154;
    if (v_8154 == nil) goto v_8055;
    else goto v_8056;
v_8055:
    v_8154 = stack[-6];
    stack[-3] = v_8154;
    goto v_8054;
v_8056:
v_8054:
    v_8154 = qvalue(elt(env, 6)); // domainlist!*
    stack[-2] = v_8154;
v_8069:
    v_8154 = stack[-2];
    if (v_8154 == nil) goto v_8073;
    else goto v_8074;
v_8073:
    goto v_8068;
v_8074:
    v_8154 = stack[-2];
    v_8154 = qcar(v_8154);
    stack[-1] = v_8154;
    goto v_8092;
v_8088:
    v_8155 = stack[-1];
    goto v_8089;
v_8090:
    v_8154 = elt(env, 7); // !:gi!:
    goto v_8091;
v_8092:
    goto v_8088;
v_8089:
    goto v_8090;
v_8091:
    if (v_8155 == v_8154) goto v_8087;
    goto v_8099;
v_8095:
    v_8155 = stack[-1];
    goto v_8096;
v_8097:
    v_8154 = stack[-3];
    goto v_8098;
v_8099:
    goto v_8095;
v_8096:
    goto v_8097;
v_8098:
    v_8154 = (v_8155 == v_8154 ? lisp_true : nil);
    v_8154 = (v_8154 == nil ? lisp_true : nil);
    goto v_8085;
v_8087:
    v_8154 = nil;
    goto v_8085;
    v_8154 = nil;
v_8085:
    if (v_8154 == nil) goto v_8083;
    goto v_8112;
v_8108:
    goto v_8120;
v_8116:
    v_8154 = elt(env, 8); // !*
    stack[0] = Lexplode(nil, v_8154);
    env = stack[-7];
    goto v_8117;
v_8118:
    v_8154 = stack[-1];
    if (!symbolp(v_8154)) v_8154 = nil;
    else { v_8154 = qfastgets(v_8154);
           if (v_8154 != nil) { v_8154 = elt(v_8154, 8); // dname
#ifdef RECORD_GET
             if (v_8154 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_8154 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_8154 == SPID_NOPROP) v_8154 = nil; }}
#endif
    v_8154 = Lexplode(nil, v_8154);
    env = stack[-7];
    goto v_8119;
v_8120:
    goto v_8116;
v_8117:
    goto v_8118;
v_8119:
    v_8154 = Lappend(nil, stack[0], v_8154);
    env = stack[-7];
    v_8154 = Lcompress(nil, v_8154);
    env = stack[-7];
    v_8155 = Lintern(nil, v_8154);
    env = stack[-7];
    goto v_8109;
v_8110:
    v_8154 = nil;
    goto v_8111;
v_8112:
    goto v_8108;
v_8109:
    goto v_8110;
v_8111:
    v_8154 = Lset(nil, v_8155, v_8154);
    env = stack[-7];
    goto v_8081;
v_8083:
v_8081:
    v_8154 = stack[-2];
    v_8154 = qcdr(v_8154);
    stack[-2] = v_8154;
    goto v_8069;
v_8068:
    fn = elt(env, 11); // rmsubs
    v_8154 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    v_8154 = stack[-4];
    if (!symbolp(v_8154)) v_8154 = nil;
    else { v_8154 = qfastgets(v_8154);
           if (v_8154 != nil) { v_8154 = elt(v_8154, 8); // dname
#ifdef RECORD_GET
             if (v_8154 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_8154 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_8154 == SPID_NOPROP) v_8154 = nil; }}
#endif
    stack[-4] = v_8154;
    v_8154 = stack[-4];
    if (v_8154 == nil) goto v_8135;
    goto v_8147;
v_8139:
    v_8157 = elt(env, 9); // "Domain mode"
    goto v_8140;
v_8141:
    v_8156 = stack[-4];
    goto v_8142;
v_8143:
    v_8155 = elt(env, 10); // "changed to"
    goto v_8144;
v_8145:
    v_8154 = stack[-5];
    goto v_8146;
v_8147:
    goto v_8139;
v_8140:
    goto v_8141;
v_8142:
    goto v_8143;
v_8144:
    goto v_8145;
v_8146:
    v_8154 = list4(v_8157, v_8156, v_8155, v_8154);
    env = stack[-7];
    fn = elt(env, 14); // lprim
    v_8154 = (*qfn1(fn))(fn, v_8154);
    env = stack[-7];
    goto v_8133;
v_8135:
v_8133:
    v_8154 = stack[-6];
    qvalue(elt(env, 2)) = v_8154; // dmode!*
    qvalue(elt(env, 3)) = v_8154; // gdmode!*
    v_8154 = stack[-4];
v_7982:
    return onevalue(v_8154);
}



// Code for wedgepf

static LispObject CC_wedgepf(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_7988, v_7989;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7988 = v_7976;
    v_7989 = v_7975;
// end of prologue
    goto v_7984;
v_7980:
    stack[0] = v_7989;
    goto v_7981;
v_7982:
    fn = elt(env, 1); // !*pf2wedgepf
    v_7988 = (*qfn1(fn))(fn, v_7988);
    env = stack[-1];
    goto v_7983;
v_7984:
    goto v_7980;
v_7981:
    goto v_7982;
v_7983:
    fn = elt(env, 2); // wedgepf2
    v_7988 = (*qfn2(fn))(fn, stack[0], v_7988);
    env = stack[-1];
    {
        fn = elt(env, 3); // !*wedgepf2pf
        return (*qfn1(fn))(fn, v_7988);
    }
}



// Code for noncommuting

static LispObject CC_noncommuting(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8052, v_8053, v_8054, v_8055;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
// copy arguments values to proper place
    v_8053 = v_7976;
    v_8054 = v_7975;
// end of prologue
    v_8055 = nil;
    v_8052 = v_8054;
    if (!consp(v_8052)) goto v_7984;
    else goto v_7985;
v_7984:
    v_8052 = v_8054;
    goto v_7983;
v_7985:
    v_8052 = v_8054;
    v_8052 = qcar(v_8052);
    goto v_7983;
    v_8052 = nil;
v_7983:
    v_8054 = v_8052;
    v_8052 = v_8053;
    if (!consp(v_8052)) goto v_7994;
    else goto v_7995;
v_7994:
    v_8052 = v_8053;
    goto v_7993;
v_7995:
    v_8052 = v_8053;
    v_8052 = qcar(v_8052);
    goto v_7993;
    v_8052 = nil;
v_7993:
    v_8053 = v_8052;
    v_8052 = v_8054;
    if (!consp(v_8052)) goto v_8009;
    else goto v_8010;
v_8009:
    v_8052 = v_8054;
    if (!symbolp(v_8052)) v_8052 = nil;
    else { v_8052 = qfastgets(v_8052);
           if (v_8052 != nil) { v_8052 = elt(v_8052, 0); // noncom
#ifdef RECORD_GET
             if (v_8052 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_8052 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_8052 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_8052 == SPID_NOPROP) v_8052 = nil; else v_8052 = lisp_true; }}
#endif
    goto v_8008;
v_8010:
    v_8052 = v_8054;
    v_8052 = qcar(v_8052);
    if (!symbolp(v_8052)) v_8052 = nil;
    else { v_8052 = qfastgets(v_8052);
           if (v_8052 != nil) { v_8052 = elt(v_8052, 0); // noncom
#ifdef RECORD_GET
             if (v_8052 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_8052 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_8052 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_8052 == SPID_NOPROP) v_8052 = nil; else v_8052 = lisp_true; }}
#endif
    goto v_8008;
    v_8052 = nil;
v_8008:
    if (v_8052 == nil) goto v_8004;
    v_8052 = v_8053;
    if (!consp(v_8052)) goto v_8022;
    else goto v_8023;
v_8022:
    v_8052 = v_8053;
    if (!symbolp(v_8052)) v_8052 = nil;
    else { v_8052 = qfastgets(v_8052);
           if (v_8052 != nil) { v_8052 = elt(v_8052, 0); // noncom
#ifdef RECORD_GET
             if (v_8052 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_8052 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_8052 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_8052 == SPID_NOPROP) v_8052 = nil; else v_8052 = lisp_true; }}
#endif
    goto v_8021;
v_8023:
    v_8052 = v_8053;
    v_8052 = qcar(v_8052);
    if (!symbolp(v_8052)) v_8052 = nil;
    else { v_8052 = qfastgets(v_8052);
           if (v_8052 != nil) { v_8052 = elt(v_8052, 0); // noncom
#ifdef RECORD_GET
             if (v_8052 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_8052 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_8052 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_8052 == SPID_NOPROP) v_8052 = nil; else v_8052 = lisp_true; }}
#endif
    goto v_8021;
    v_8052 = nil;
v_8021:
    if (v_8052 == nil) goto v_8004;
    goto v_8005;
v_8004:
    goto v_8003;
v_8005:
    goto v_8040;
v_8036:
    goto v_8037;
v_8038:
    v_8052 = elt(env, 1); // noncommutes
    goto v_8039;
v_8040:
    goto v_8036;
v_8037:
    goto v_8038;
v_8039:
    v_8052 = get(v_8054, v_8052);
    goto v_8047;
v_8043:
    goto v_8044;
v_8045:
    goto v_8046;
v_8047:
    goto v_8043;
v_8044:
    goto v_8045;
v_8046:
    v_8052 = Lmember(nil, v_8053, v_8052);
    v_8055 = v_8052;
    goto v_8003;
v_8003:
    v_8052 = v_8055;
    return onevalue(v_8052);
}



// Code for all_edge

static LispObject CC_all_edge(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8015, v_8016, v_8017;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7976;
    stack[-1] = v_7975;
// end of prologue
    v_8017 = nil;
v_7981:
    v_8015 = stack[0];
    if (v_8015 == nil) goto v_7984;
    else goto v_7985;
v_7984:
    v_8015 = v_8017;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_8015);
    }
v_7985:
    goto v_7995;
v_7991:
    v_8016 = stack[-1];
    goto v_7992;
v_7993:
    v_8015 = stack[0];
    v_8015 = qcar(v_8015);
    v_8015 = qcar(v_8015);
    goto v_7994;
v_7995:
    goto v_7991;
v_7992:
    goto v_7993;
v_7994:
    if (v_8016 == v_8015) goto v_7989;
    else goto v_7990;
v_7989:
    goto v_8005;
v_8001:
    v_8015 = stack[0];
    v_8015 = qcar(v_8015);
    goto v_8002;
v_8003:
    v_8016 = v_8017;
    goto v_8004;
v_8005:
    goto v_8001;
v_8002:
    goto v_8003;
v_8004:
    v_8015 = cons(v_8015, v_8016);
    env = stack[-2];
    v_8017 = v_8015;
    v_8015 = stack[0];
    v_8015 = qcdr(v_8015);
    stack[0] = v_8015;
    goto v_7981;
v_7990:
    v_8015 = stack[0];
    v_8015 = qcdr(v_8015);
    stack[0] = v_8015;
    goto v_7981;
    v_8015 = nil;
    return onevalue(v_8015);
}



// Code for mkid

static LispObject CC_mkid(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8042, v_8043;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7976;
    v_8042 = v_7975;
// end of prologue
    v_8043 = v_8042;
    if (symbolp(v_8043)) goto v_7981;
    goto v_7988;
v_7984:
    v_8043 = v_8042;
    goto v_7985;
v_7986:
    v_8042 = elt(env, 1); // "MKID root"
    goto v_7987;
v_7988:
    goto v_7984;
v_7985:
    goto v_7986;
v_7987:
    {
        fn = elt(env, 3); // typerr
        return (*qfn2(fn))(fn, v_8043, v_8042);
    }
v_7981:
    v_8043 = stack[0];
    if (!consp(v_8043)) goto v_7995;
    else goto v_7996;
v_7995:
    v_8043 = stack[0];
    v_8043 = Lsymbolp(nil, v_8043);
    env = stack[-2];
    if (v_8043 == nil) goto v_8000;
    else goto v_7999;
v_8000:
    v_8043 = stack[0];
    v_8043 = integerp(v_8043);
    if (v_8043 == nil) goto v_8005;
    else goto v_8006;
v_8005:
    v_8043 = nil;
    goto v_8004;
v_8006:
    v_8043 = stack[0];
    v_8043 = Lminusp(nil, v_8043);
    env = stack[-2];
    v_8043 = (v_8043 == nil ? lisp_true : nil);
    goto v_8004;
    v_8043 = nil;
v_8004:
v_7999:
    goto v_7994;
v_7996:
    v_8043 = nil;
    goto v_7994;
    v_8043 = nil;
v_7994:
    if (v_8043 == nil) goto v_7992;
    goto v_8025;
v_8021:
    fn = elt(env, 4); // get!-print!-name
    v_8042 = (*qfn1(fn))(fn, v_8042);
    env = stack[-2];
    stack[-1] = Lexplode(nil, v_8042);
    env = stack[-2];
    goto v_8022;
v_8023:
    v_8042 = stack[0];
    fn = elt(env, 4); // get!-print!-name
    v_8042 = (*qfn1(fn))(fn, v_8042);
    env = stack[-2];
    v_8042 = Lexplode(nil, v_8042);
    env = stack[-2];
    goto v_8024;
v_8025:
    goto v_8021;
v_8022:
    goto v_8023;
v_8024:
    v_8042 = Lnconc(nil, stack[-1], v_8042);
    env = stack[-2];
    v_8042 = Lcompress(nil, v_8042);
        return Lintern(nil, v_8042);
v_7992:
    goto v_8039;
v_8035:
    v_8043 = stack[0];
    goto v_8036;
v_8037:
    v_8042 = elt(env, 2); // "MKID index"
    goto v_8038;
v_8039:
    goto v_8035;
v_8036:
    goto v_8037;
v_8038:
    {
        fn = elt(env, 3); // typerr
        return (*qfn2(fn))(fn, v_8043, v_8042);
    }
    v_8042 = nil;
    return onevalue(v_8042);
}



// Code for mv!-pow!-chk

static LispObject CC_mvKpowKchk(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8005, v_8006;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7976,v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7975,v_7976);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_8005 = v_7976;
    stack[0] = v_7975;
// end of prologue
    v_8006 = v_8005;
    if (v_8006 == nil) goto v_7981;
    goto v_7991;
v_7987:
    v_8006 = stack[0];
    v_8006 = qcar(v_8006);
    v_8006 = qcar(v_8006);
    goto v_7988;
v_7989:
    v_8005 = qcar(v_8005);
    v_8005 = qcar(v_8005);
    goto v_7990;
v_7991:
    goto v_7987;
v_7988:
    goto v_7989;
v_7990:
    fn = elt(env, 1); // mv!-pow!-!-
    v_8005 = (*qfn2(fn))(fn, v_8006, v_8005);
    env = stack[-1];
    stack[0] = v_8005;
    if (v_8005 == nil) goto v_7981;
    v_8005 = stack[0];
    fn = elt(env, 2); // mv!-pow!-minusp
    v_8005 = (*qfn1(fn))(fn, v_8005);
    if (v_8005 == nil) goto v_7998;
    else goto v_7981;
v_7998:
    v_8005 = stack[0];
    goto v_7979;
v_7981:
    v_8005 = nil;
    goto v_7979;
    v_8005 = nil;
v_7979:
    return onevalue(v_8005);
}



// Code for !:divide

static LispObject CC_Tdivide(LispObject env,
                         LispObject v_7975, LispObject v_7976)
{
    env = qenv(env);
    LispObject v_8032, v_8033, v_8034;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8033 = v_7976;
    v_8034 = v_7975;
// end of prologue
    v_8032 = v_8034;
    if (v_8032 == nil) goto v_7980;
    else goto v_7981;
v_7980:
    v_8032 = nil;
    return ncons(v_8032);
v_7981:
    v_8032 = v_8033;
    if (v_8032 == nil) goto v_7985;
    else goto v_7986;
v_7985:
    goto v_7995;
v_7989:
    v_8034 = elt(env, 1); // poly
    goto v_7990;
v_7991:
    v_8033 = (LispObject)3232+TAG_FIXNUM; // 202
    goto v_7992;
v_7993:
    v_8032 = elt(env, 2); // "zero divisor"
    goto v_7994;
v_7995:
    goto v_7989;
v_7990:
    goto v_7991;
v_7992:
    goto v_7993;
v_7994:
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_8034, v_8033, v_8032);
    }
v_7986:
    v_8032 = v_8034;
    if (!consp(v_8032)) goto v_8003;
    else goto v_8004;
v_8003:
    v_8032 = v_8033;
    v_8032 = (consp(v_8032) ? nil : lisp_true);
    goto v_8002;
v_8004:
    v_8032 = nil;
    goto v_8002;
    v_8032 = nil;
v_8002:
    if (v_8032 == nil) goto v_8000;
    goto v_8016;
v_8012:
    v_8032 = v_8034;
    goto v_8013;
v_8014:
    goto v_8015;
v_8016:
    goto v_8012;
v_8013:
    goto v_8014;
v_8015:
    {
        fn = elt(env, 5); // dividef
        return (*qfn2(fn))(fn, v_8032, v_8033);
    }
v_8000:
    goto v_8028;
v_8022:
    goto v_8023;
v_8024:
    goto v_8025;
v_8026:
    v_8032 = elt(env, 3); // divide
    goto v_8027;
v_8028:
    goto v_8022;
v_8023:
    goto v_8024;
v_8025:
    goto v_8026;
v_8027:
    {
        fn = elt(env, 6); // dcombine
        return (*qfnn(fn))(fn, 3, v_8034, v_8033, v_8032);
    }
    v_8032 = nil;
    return onevalue(v_8032);
}



// Code for gperm0

static LispObject CC_gperm0(LispObject env,
                         LispObject v_7975)
{
    env = qenv(env);
    LispObject v_7997, v_7998;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7975);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7975);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7998 = v_7975;
// end of prologue
    v_7997 = v_7998;
    if (v_7997 == nil) goto v_7979;
    else goto v_7980;
v_7979:
    v_7997 = nil;
    goto v_7978;
v_7980:
    goto v_7990;
v_7986:
    v_7997 = v_7998;
    stack[0] = qcdr(v_7997);
    goto v_7987;
v_7988:
    v_7997 = v_7998;
    v_7997 = qcar(v_7997);
    v_7997 = ncons(v_7997);
    env = stack[-1];
    v_7997 = ncons(v_7997);
    env = stack[-1];
    goto v_7989;
v_7990:
    goto v_7986;
v_7987:
    goto v_7988;
v_7989:
    {
        LispObject v_8000 = stack[0];
        fn = elt(env, 1); // gperm3
        return (*qfn2(fn))(fn, v_8000, v_7997);
    }
    v_7997 = nil;
v_7978:
    return onevalue(v_7997);
}



setup_type const u15_setup[] =
{
    {"p_prin",                  TOO_FEW_2,      CC_p_prin,     WRONG_NO_2},
    {"sq2sscfpl",               TOO_FEW_2,      CC_sq2sscfpl,  WRONG_NO_2},
    {"ofsf_pow2q",              TOO_FEW_2,      CC_ofsf_pow2q, WRONG_NO_2},
    {"downwght1",               TOO_FEW_2,      CC_downwght1,  WRONG_NO_2},
    {"newenv",                  CC_newenv,      TOO_MANY_1,    WRONG_NO_1},
    {"evenfree",                CC_evenfree,    TOO_MANY_1,    WRONG_NO_1},
    {"fortranprecedence",       CC_fortranprecedence,TOO_MANY_1,WRONG_NO_1},
    {"assert_typesyntaxp",      CC_assert_typesyntaxp,TOO_MANY_1,WRONG_NO_1},
    {"mo_neworder",             CC_mo_neworder, TOO_MANY_1,    WRONG_NO_1},
    {"eqdummy",                 TOO_FEW_2,      CC_eqdummy,    WRONG_NO_2},
    {"ra_budan-0-1",            CC_ra_budanK0K1,TOO_MANY_1,    WRONG_NO_1},
    {"lexer_word_continues",    CC_lexer_word_continues,TOO_MANY_1,WRONG_NO_1},
    {"aex_varl",                CC_aex_varl,    TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_entry2at1",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_entry2at1},
    {"intexprlisp",             TOO_FEW_2,      CC_intexprlisp,WRONG_NO_2},
    {"ibalp_var-satlist",       TOO_FEW_2,      CC_ibalp_varKsatlist,WRONG_NO_2},
    {"gb_buch-ev_divides?",     TOO_FEW_2,      CC_gb_buchKev_dividesW,WRONG_NO_2},
    {"matsm*1",                 CC_matsmH1,     TOO_MANY_1,    WRONG_NO_1},
    {"maxtype",                 CC_maxtype,     TOO_MANY_1,    WRONG_NO_1},
    {"bind",                    TOO_FEW_2,      CC_bind,       WRONG_NO_2},
    {"triviallcm",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_triviallcm},
    {"aminusp:1",               CC_aminuspT1,   TOO_MANY_1,    WRONG_NO_1},
    {"groeb=better",            TOO_FEW_2,      CC_groebMbetter,WRONG_NO_2},
    {"dcombine",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dcombine},
    {"general-times-mod-p",     TOO_FEW_2,      CC_generalKtimesKmodKp,WRONG_NO_2},
    {"setk",                    TOO_FEW_2,      CC_setk,       WRONG_NO_2},
    {"lalr_resolve_conflicts",  TOO_FEW_2,      CC_lalr_resolve_conflicts,WRONG_NO_2},
    {"idsort",                  CC_idsort,      TOO_MANY_1,    WRONG_NO_1},
    {"mri_realvarp",            CC_mri_realvarp,TOO_MANY_1,    WRONG_NO_1},
    {"qqe_ofsf_chsimpterm",     CC_qqe_ofsf_chsimpterm,TOO_MANY_1,WRONG_NO_1},
    {"kernord-split",           TOO_FEW_2,      CC_kernordKsplit,WRONG_NO_2},
    {"gsugar",                  CC_gsugar,      TOO_MANY_1,    WRONG_NO_1},
    {"remcomma",                CC_remcomma,    TOO_MANY_1,    WRONG_NO_1},
    {"mv-domainlist-*",         TOO_FEW_2,      CC_mvKdomainlistKH,WRONG_NO_2},
    {"pv_times2",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pv_times2},
    {"tr_write",                CC_tr_write,    TOO_MANY_1,    WRONG_NO_1},
    {"conv:mt",                 TOO_FEW_2,      CC_convTmt,    WRONG_NO_2},
    {"multd*",                  TOO_FEW_2,      CC_multdH,     WRONG_NO_2},
    {"reduce-degree-mod-p",     TOO_FEW_2,      CC_reduceKdegreeKmodKp,WRONG_NO_2},
    {"lalr_make_compressed_action_row1",CC_lalr_make_compressed_action_row1,TOO_MANY_1,WRONG_NO_1},
    {"updtemplate",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_updtemplate},
    {"talp_subalchk",           CC_talp_subalchk,TOO_MANY_1,   WRONG_NO_1},
    {"qqe_arg-check-b",         CC_qqe_argKcheckKb,TOO_MANY_1, WRONG_NO_1},
    {"mapins",                  TOO_FEW_2,      CC_mapins,     WRONG_NO_2},
    {"cird",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cird},
    {"getcomb",                 TOO_FEW_2,      CC_getcomb,    WRONG_NO_2},
    {"setdmode1",               TOO_FEW_2,      CC_setdmode1,  WRONG_NO_2},
    {"wedgepf",                 TOO_FEW_2,      CC_wedgepf,    WRONG_NO_2},
    {"noncommuting",            TOO_FEW_2,      CC_noncommuting,WRONG_NO_2},
    {"all_edge",                TOO_FEW_2,      CC_all_edge,   WRONG_NO_2},
    {"mkid",                    TOO_FEW_2,      CC_mkid,       WRONG_NO_2},
    {"mv-pow-chk",              TOO_FEW_2,      CC_mvKpowKchk, WRONG_NO_2},
    {":divide",                 TOO_FEW_2,      CC_Tdivide,    WRONG_NO_2},
    {"gperm0",                  CC_gperm0,      TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u15", (two_args *)"101917 1374978 9782665", 0}
};

// end of generated code
