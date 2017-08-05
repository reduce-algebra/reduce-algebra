
// $destdir/u55.c        Machine generated C code

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



// Code for addcoeffs

static LispObject CC_addcoeffs(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33172, v_33173, v_33174, v_33175;
    LispObject fn;
    LispObject v_33049, v_33048, v_33047, v_33046;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "addcoeffs");
    va_start(aa, nargs);
    v_33046 = va_arg(aa, LispObject);
    v_33047 = va_arg(aa, LispObject);
    v_33048 = va_arg(aa, LispObject);
    v_33049 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_33049,v_33048,v_33047,v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_33046,v_33047,v_33048,v_33049);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_33049;
    stack[-2] = v_33048;
    stack[-3] = v_33047;
    stack[-4] = v_33046;
// end of prologue
    goto v_33060;
v_33056:
    v_33173 = nil;
    goto v_33057;
v_33058:
    v_33172 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33059;
v_33060:
    goto v_33056;
v_33057:
    goto v_33058;
v_33059:
    v_33172 = cons(v_33173, v_33172);
    env = stack[-6];
    stack[0] = v_33172;
    goto v_33068;
v_33064:
    v_33172 = stack[-4];
    fn = elt(env, 1); // smallest!-increment
    stack[-5] = (*qfn1(fn))(fn, v_33172);
    env = stack[-6];
    goto v_33065;
v_33066:
    v_33172 = stack[-3];
    fn = elt(env, 1); // smallest!-increment
    v_33172 = (*qfn1(fn))(fn, v_33172);
    env = stack[-6];
    goto v_33067;
v_33068:
    goto v_33064;
v_33065:
    goto v_33066;
v_33067:
    fn = elt(env, 2); // common!-increment
    v_33172 = (*qfn2(fn))(fn, stack[-5], v_33172);
    env = stack[-6];
    goto v_33086;
v_33078:
    v_33175 = stack[-2];
    goto v_33079;
v_33080:
    v_33174 = stack[-1];
    goto v_33081;
v_33082:
    v_33173 = stack[-3];
    v_33173 = qcar(v_33173);
    v_33173 = qcar(v_33173);
    goto v_33083;
v_33084:
    goto v_33085;
v_33086:
    goto v_33078;
v_33079:
    goto v_33080;
v_33081:
    goto v_33082;
v_33083:
    goto v_33084;
v_33085:
    fn = elt(env, 3); // makecoeffpairs
    v_33172 = (*qfnn(fn))(fn, 4, v_33175, v_33174, v_33173, v_33172);
    env = stack[-6];
    stack[-5] = v_33172;
v_33076:
    v_33172 = stack[-5];
    if (v_33172 == nil) goto v_33095;
    else goto v_33096;
v_33095:
    goto v_33075;
v_33096:
    v_33172 = stack[-5];
    v_33172 = qcar(v_33172);
    stack[-2] = v_33172;
    goto v_33107;
v_33103:
    stack[-1] = stack[0];
    goto v_33104;
v_33105:
    goto v_33114;
v_33110:
    goto v_33119;
v_33115:
    v_33172 = stack[-2];
    v_33173 = qcar(v_33172);
    goto v_33116;
v_33117:
    v_33172 = stack[-4];
    goto v_33118;
v_33119:
    goto v_33115;
v_33116:
    goto v_33117;
v_33118:
    v_33172 = Lassoc(nil, v_33173, v_33172);
    v_33173 = v_33172;
    v_33172 = v_33173;
    if (v_33172 == nil) goto v_33127;
    else goto v_33128;
v_33127:
    goto v_33135;
v_33131:
    v_33173 = nil;
    goto v_33132;
v_33133:
    v_33172 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33134;
v_33135:
    goto v_33131;
v_33132:
    goto v_33133;
v_33134:
    v_33172 = cons(v_33173, v_33172);
    env = stack[-6];
    stack[0] = v_33172;
    goto v_33126;
v_33128:
    v_33172 = v_33173;
    v_33172 = qcdr(v_33172);
    stack[0] = v_33172;
    goto v_33126;
    stack[0] = nil;
v_33126:
    goto v_33111;
v_33112:
    goto v_33146;
v_33142:
    v_33172 = stack[-2];
    v_33173 = qcdr(v_33172);
    goto v_33143;
v_33144:
    v_33172 = stack[-3];
    goto v_33145;
v_33146:
    goto v_33142;
v_33143:
    goto v_33144;
v_33145:
    v_33172 = Lassoc(nil, v_33173, v_33172);
    v_33173 = v_33172;
    v_33172 = v_33173;
    if (v_33172 == nil) goto v_33154;
    else goto v_33155;
v_33154:
    goto v_33162;
v_33158:
    v_33173 = nil;
    goto v_33159;
v_33160:
    v_33172 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33161;
v_33162:
    goto v_33158;
v_33159:
    goto v_33160;
v_33161:
    v_33172 = cons(v_33173, v_33172);
    env = stack[-6];
    goto v_33153;
v_33155:
    v_33172 = v_33173;
    v_33172 = qcdr(v_33172);
    goto v_33153;
    v_33172 = nil;
v_33153:
    goto v_33113;
v_33114:
    goto v_33110;
v_33111:
    goto v_33112;
v_33113:
    fn = elt(env, 4); // multsq
    v_33172 = (*qfn2(fn))(fn, stack[0], v_33172);
    env = stack[-6];
    goto v_33106;
v_33107:
    goto v_33103;
v_33104:
    goto v_33105;
v_33106:
    fn = elt(env, 5); // addsq
    v_33172 = (*qfn2(fn))(fn, stack[-1], v_33172);
    env = stack[-6];
    stack[0] = v_33172;
    v_33172 = stack[-5];
    v_33172 = qcdr(v_33172);
    stack[-5] = v_33172;
    goto v_33076;
v_33075:
    v_33172 = stack[0];
    return onevalue(v_33172);
}



// Code for change!+sq!+to!+int

static LispObject CC_changeLsqLtoLint(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33072, v_33073, v_33074;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33072 = v_33046;
// end of prologue
    fn = elt(env, 2); // prepsq
    v_33072 = (*qfn1(fn))(fn, v_33072);
    env = stack[0];
    fn = elt(env, 3); // simp!*
    v_33072 = (*qfn1(fn))(fn, v_33072);
    env = stack[0];
    v_33074 = v_33072;
    goto v_33062;
v_33058:
    v_33072 = v_33074;
    v_33073 = qcdr(v_33072);
    goto v_33059;
v_33060:
    v_33072 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33061;
v_33062:
    goto v_33058;
v_33059:
    goto v_33060;
v_33061:
    if (v_33073 == v_33072) goto v_33056;
    else goto v_33057;
v_33056:
    v_33072 = v_33074;
    v_33072 = qcar(v_33072);
    goto v_33050;
v_33057:
    v_33072 = elt(env, 1); // "no integer in change!+sq!+to!+int"
    fn = elt(env, 4); // rederr
    v_33072 = (*qfn1(fn))(fn, v_33072);
    goto v_33055;
v_33055:
    v_33072 = nil;
v_33050:
    return onevalue(v_33072);
}



// Code for bc_pmon

static LispObject CC_bc_pmon(LispObject env,
                         LispObject v_33046, LispObject v_33047)
{
    env = qenv(env);
    LispObject v_33074, v_33075, v_33076;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33047,v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33046,v_33047);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33074 = v_33047;
    v_33075 = v_33046;
// end of prologue
    goto v_33056;
v_33050:
    goto v_33062;
v_33058:
    goto v_33068;
v_33064:
    goto v_33065;
v_33066:
    goto v_33067;
v_33068:
    goto v_33064;
v_33065:
    goto v_33066;
v_33067:
    fn = elt(env, 1); // to
    v_33075 = (*qfn2(fn))(fn, v_33075, v_33074);
    env = stack[0];
    goto v_33059;
v_33060:
    v_33074 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33061;
v_33062:
    goto v_33058;
v_33059:
    goto v_33060;
v_33061:
    v_33076 = cons(v_33075, v_33074);
    goto v_33051;
v_33052:
    v_33075 = nil;
    goto v_33053;
v_33054:
    v_33074 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33055;
v_33056:
    goto v_33050;
v_33051:
    goto v_33052;
v_33053:
    goto v_33054;
v_33055:
    return acons(v_33076, v_33075, v_33074);
}



// Code for operator

static LispObject CC_operator(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33066;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_33066 = v_33046;
// end of prologue
    stack[0] = v_33066;
v_33051:
    v_33066 = stack[0];
    if (v_33066 == nil) goto v_33055;
    else goto v_33056;
v_33055:
    v_33066 = nil;
    goto v_33050;
v_33056:
    v_33066 = stack[0];
    v_33066 = qcar(v_33066);
    fn = elt(env, 1); // mkop
    v_33066 = (*qfn1(fn))(fn, v_33066);
    env = stack[-1];
    v_33066 = stack[0];
    v_33066 = qcdr(v_33066);
    stack[0] = v_33066;
    goto v_33051;
v_33050:
    return onevalue(v_33066);
}



// Code for look_for_rational

static LispObject CC_look_for_rational(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33205, v_33206, v_33207;
    LispObject fn;
    LispObject v_33048, v_33047, v_33046;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "look_for_rational");
    va_start(aa, nargs);
    v_33046 = va_arg(aa, LispObject);
    v_33047 = va_arg(aa, LispObject);
    v_33048 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_33048,v_33047,v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_33046,v_33047,v_33048);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_33048;
    stack[-1] = v_33047;
    stack[-2] = v_33046;
// end of prologue
    goto v_33059;
v_33055:
    v_33206 = stack[-1];
    goto v_33056;
v_33057:
    v_33205 = elt(env, 1); // look_for_exponential
    goto v_33058;
v_33059:
    goto v_33055;
v_33056:
    goto v_33057;
v_33058:
    v_33205 = get(v_33206, v_33205);
    env = stack[-3];
    if (v_33205 == nil) goto v_33053;
    v_33205 = nil;
    goto v_33051;
v_33053:
    goto v_33073;
v_33069:
    v_33205 = stack[0];
    v_33206 = qcar(v_33205);
    goto v_33070;
v_33071:
    v_33205 = elt(env, 2); // sqrt
    goto v_33072;
v_33073:
    goto v_33069;
v_33070:
    goto v_33071;
v_33072:
    if (v_33206 == v_33205) goto v_33067;
    else goto v_33068;
v_33067:
    goto v_33081;
v_33077:
    v_33205 = stack[0];
    v_33205 = qcdr(v_33205);
    v_33206 = qcar(v_33205);
    goto v_33078;
v_33079:
    v_33205 = stack[-1];
    goto v_33080;
v_33081:
    goto v_33077;
v_33078:
    goto v_33079;
v_33080:
    v_33205 = (equal(v_33206, v_33205) ? lisp_true : nil);
    goto v_33066;
v_33068:
    v_33205 = nil;
    goto v_33066;
    v_33205 = nil;
v_33066:
    if (v_33205 == nil) goto v_33064;
    goto v_33097;
v_33091:
    v_33207 = stack[-2];
    goto v_33092;
v_33093:
    v_33206 = stack[-1];
    goto v_33094;
v_33095:
    v_33205 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_33096;
v_33097:
    goto v_33091;
v_33092:
    goto v_33093;
v_33094:
    goto v_33095;
v_33096:
    {
        fn = elt(env, 5); // look_for_rational1
        return (*qfnn(fn))(fn, 3, v_33207, v_33206, v_33205);
    }
v_33064:
    goto v_33111;
v_33107:
    v_33205 = stack[0];
    v_33206 = qcar(v_33205);
    goto v_33108;
v_33109:
    v_33205 = elt(env, 3); // expt
    goto v_33110;
v_33111:
    goto v_33107;
v_33108:
    goto v_33109;
v_33110:
    if (v_33206 == v_33205) goto v_33105;
    else goto v_33106;
v_33105:
    goto v_33123;
v_33119:
    v_33205 = stack[0];
    v_33205 = qcdr(v_33205);
    v_33206 = qcar(v_33205);
    goto v_33120;
v_33121:
    v_33205 = stack[-1];
    goto v_33122;
v_33123:
    goto v_33119;
v_33120:
    goto v_33121;
v_33122:
    if (equal(v_33206, v_33205)) goto v_33117;
    else goto v_33118;
v_33117:
    v_33205 = stack[0];
    v_33205 = qcdr(v_33205);
    v_33205 = qcdr(v_33205);
    v_33205 = qcar(v_33205);
    fn = elt(env, 6); // listp
    v_33205 = (*qfn1(fn))(fn, v_33205);
    env = stack[-3];
    if (v_33205 == nil) goto v_33130;
    else goto v_33131;
v_33130:
    v_33205 = nil;
    goto v_33129;
v_33131:
    goto v_33148;
v_33144:
    v_33205 = stack[0];
    v_33205 = qcdr(v_33205);
    v_33205 = qcdr(v_33205);
    v_33205 = qcar(v_33205);
    v_33206 = qcar(v_33205);
    goto v_33145;
v_33146:
    v_33205 = elt(env, 4); // quotient
    goto v_33147;
v_33148:
    goto v_33144;
v_33145:
    goto v_33146;
v_33147:
    if (v_33206 == v_33205) goto v_33142;
    else goto v_33143;
v_33142:
    v_33205 = stack[0];
    v_33205 = qcdr(v_33205);
    v_33205 = qcdr(v_33205);
    v_33205 = qcar(v_33205);
    v_33205 = qcdr(v_33205);
    v_33205 = qcar(v_33205);
    if (is_number(v_33205)) goto v_33158;
    v_33205 = nil;
    goto v_33156;
v_33158:
    v_33205 = stack[0];
    v_33205 = qcdr(v_33205);
    v_33205 = qcdr(v_33205);
    v_33205 = qcar(v_33205);
    v_33205 = qcdr(v_33205);
    v_33205 = qcdr(v_33205);
    v_33205 = qcar(v_33205);
    v_33205 = (is_number(v_33205) ? lisp_true : nil);
    goto v_33156;
    v_33205 = nil;
v_33156:
    goto v_33141;
v_33143:
    v_33205 = nil;
    goto v_33141;
    v_33205 = nil;
v_33141:
    goto v_33129;
    v_33205 = nil;
v_33129:
    goto v_33116;
v_33118:
    v_33205 = nil;
    goto v_33116;
    v_33205 = nil;
v_33116:
    goto v_33104;
v_33106:
    v_33205 = nil;
    goto v_33104;
    v_33205 = nil;
v_33104:
    if (v_33205 == nil) goto v_33102;
    goto v_33192;
v_33186:
    v_33207 = stack[-2];
    goto v_33187;
v_33188:
    v_33206 = stack[-1];
    goto v_33189;
v_33190:
    v_33205 = stack[0];
    v_33205 = qcdr(v_33205);
    v_33205 = qcdr(v_33205);
    v_33205 = qcar(v_33205);
    v_33205 = qcdr(v_33205);
    v_33205 = qcdr(v_33205);
    v_33205 = qcar(v_33205);
    goto v_33191;
v_33192:
    goto v_33186;
v_33187:
    goto v_33188;
v_33189:
    goto v_33190;
v_33191:
    {
        fn = elt(env, 5); // look_for_rational1
        return (*qfnn(fn))(fn, 3, v_33207, v_33206, v_33205);
    }
v_33102:
    v_33205 = nil;
    goto v_33051;
    v_33205 = nil;
v_33051:
    return onevalue(v_33205);
}



// Code for vevzero!?1

static LispObject CC_vevzeroW1(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33100, v_33101, v_33102;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33101 = v_33046;
// end of prologue
v_33045:
    v_33100 = v_33101;
    if (v_33100 == nil) goto v_33050;
    else goto v_33051;
v_33050:
    v_33100 = lisp_true;
    goto v_33049;
v_33051:
    goto v_33064;
v_33060:
    v_33100 = v_33101;
    v_33102 = qcar(v_33100);
    goto v_33061;
v_33062:
    v_33100 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33063;
v_33064:
    goto v_33060;
v_33061:
    goto v_33062;
v_33063:
    if (v_33102 == v_33100) goto v_33058;
    else goto v_33059;
v_33058:
    v_33100 = v_33101;
    v_33100 = qcdr(v_33100);
    if (v_33100 == nil) goto v_33070;
    else goto v_33071;
v_33070:
    v_33100 = lisp_true;
    goto v_33069;
v_33071:
    goto v_33085;
v_33081:
    v_33100 = v_33101;
    v_33100 = qcdr(v_33100);
    v_33102 = qcar(v_33100);
    goto v_33082;
v_33083:
    v_33100 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33084;
v_33085:
    goto v_33081;
v_33082:
    goto v_33083;
v_33084:
    if (v_33102 == v_33100) goto v_33079;
    else goto v_33080;
v_33079:
    v_33100 = v_33101;
    v_33100 = qcdr(v_33100);
    v_33100 = qcdr(v_33100);
    v_33101 = v_33100;
    goto v_33045;
v_33080:
    v_33100 = nil;
    goto v_33078;
    v_33100 = nil;
v_33078:
    goto v_33069;
    v_33100 = nil;
v_33069:
    goto v_33057;
v_33059:
    v_33100 = nil;
    goto v_33057;
    v_33100 = nil;
v_33057:
    goto v_33049;
    v_33100 = nil;
v_33049:
    return onevalue(v_33100);
}



// Code for xpndwedge

static LispObject CC_xpndwedge(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33094, v_33095;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33046;
// end of prologue
    stack[-1] = nil;
v_33052:
    v_33094 = stack[0];
    v_33094 = qcdr(v_33094);
    if (v_33094 == nil) goto v_33057;
    else goto v_33058;
v_33057:
    goto v_33053;
v_33058:
    goto v_33066;
v_33062:
    v_33094 = stack[0];
    v_33094 = qcar(v_33094);
    fn = elt(env, 1); // partitop
    v_33095 = (*qfn1(fn))(fn, v_33094);
    env = stack[-2];
    goto v_33063;
v_33064:
    v_33094 = stack[-1];
    goto v_33065;
v_33066:
    goto v_33062;
v_33063:
    goto v_33064;
v_33065:
    v_33094 = cons(v_33095, v_33094);
    env = stack[-2];
    stack[-1] = v_33094;
    v_33094 = stack[0];
    v_33094 = qcdr(v_33094);
    stack[0] = v_33094;
    goto v_33052;
v_33053:
    v_33094 = stack[0];
    v_33094 = qcar(v_33094);
    fn = elt(env, 1); // partitop
    v_33094 = (*qfn1(fn))(fn, v_33094);
    env = stack[-2];
    fn = elt(env, 2); // mkunarywedge
    v_33094 = (*qfn1(fn))(fn, v_33094);
    env = stack[-2];
    v_33095 = v_33094;
v_33054:
    v_33094 = stack[-1];
    if (v_33094 == nil) goto v_33079;
    else goto v_33080;
v_33079:
    v_33094 = v_33095;
    goto v_33051;
v_33080:
    goto v_33088;
v_33084:
    v_33094 = stack[-1];
    v_33094 = qcar(v_33094);
    goto v_33085;
v_33086:
    goto v_33087;
v_33088:
    goto v_33084;
v_33085:
    goto v_33086;
v_33087:
    fn = elt(env, 3); // wedgepf2
    v_33094 = (*qfn2(fn))(fn, v_33094, v_33095);
    env = stack[-2];
    v_33095 = v_33094;
    v_33094 = stack[-1];
    v_33094 = qcdr(v_33094);
    stack[-1] = v_33094;
    goto v_33054;
v_33051:
    return onevalue(v_33094);
}



// Code for acmemb

static LispObject CC_acmemb(LispObject env,
                         LispObject v_33046, LispObject v_33047)
{
    env = qenv(env);
    LispObject v_33075, v_33076;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33047,v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33046,v_33047);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33047;
    stack[-1] = v_33046;
// end of prologue
v_33051:
    v_33075 = stack[0];
    if (v_33075 == nil) goto v_33054;
    else goto v_33055;
v_33054:
    v_33075 = nil;
    goto v_33050;
v_33055:
    goto v_33065;
v_33061:
    v_33076 = stack[-1];
    goto v_33062;
v_33063:
    v_33075 = stack[0];
    v_33075 = qcar(v_33075);
    goto v_33064;
v_33065:
    goto v_33061;
v_33062:
    goto v_33063;
v_33064:
    fn = elt(env, 1); // aceq
    v_33075 = (*qfn2(fn))(fn, v_33076, v_33075);
    env = stack[-2];
    if (v_33075 == nil) goto v_33059;
    v_33075 = stack[0];
    v_33075 = qcar(v_33075);
    goto v_33050;
v_33059:
    v_33075 = stack[0];
    v_33075 = qcdr(v_33075);
    stack[0] = v_33075;
    goto v_33051;
    v_33075 = nil;
v_33050:
    return onevalue(v_33075);
}



// Code for noncom1

static LispObject CC_noncom1(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33058, v_33059;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33059 = v_33046;
// end of prologue
    v_33058 = lisp_true;
    qvalue(elt(env, 1)) = v_33058; // !*ncmp
    goto v_33054;
v_33050:
    v_33058 = v_33059;
    v_33058 = ncons(v_33058);
    env = stack[0];
    goto v_33051;
v_33052:
    v_33059 = elt(env, 2); // noncom
    goto v_33053;
v_33054:
    goto v_33050;
v_33051:
    goto v_33052;
v_33053:
        return Lflag(nil, v_33058, v_33059);
}



// Code for rationalizef

static LispObject CC_rationalizef(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33271, v_33272;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_33046;
// end of prologue
    v_33271 = stack[-2];
    fn = elt(env, 8); // kernels
    v_33271 = (*qfn1(fn))(fn, v_33271);
    env = stack[-4];
    stack[0] = v_33271;
    stack[-3] = v_33271;
v_33053:
    v_33271 = stack[-3];
    if (v_33271 == nil) goto v_33058;
    else goto v_33059;
v_33058:
    v_33271 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33052;
v_33059:
    v_33271 = stack[-3];
    v_33271 = qcar(v_33271);
    stack[-1] = v_33271;
    goto v_33077;
v_33073:
    v_33272 = stack[-1];
    goto v_33074;
v_33075:
    v_33271 = elt(env, 1); // expt
    goto v_33076;
v_33077:
    goto v_33073;
v_33074:
    goto v_33075;
v_33076:
    if (!consp(v_33272)) goto v_33071;
    v_33272 = qcar(v_33272);
    if (v_33272 == v_33271) goto v_33070;
    else goto v_33071;
v_33070:
    goto v_33089;
v_33085:
    v_33271 = stack[-1];
    v_33271 = qcdr(v_33271);
    v_33271 = qcdr(v_33271);
    v_33272 = qcar(v_33271);
    goto v_33086;
v_33087:
    v_33271 = elt(env, 2); // quotient
    goto v_33088;
v_33089:
    goto v_33085;
v_33086:
    goto v_33087;
v_33088:
    if (!consp(v_33272)) goto v_33083;
    v_33272 = qcar(v_33272);
    if (v_33272 == v_33271) goto v_33082;
    else goto v_33083;
v_33082:
    goto v_33100;
v_33096:
    v_33272 = stack[0];
    goto v_33097;
v_33098:
    v_33271 = stack[-1];
    v_33271 = qcdr(v_33271);
    goto v_33099;
v_33100:
    goto v_33096;
v_33097:
    goto v_33098;
v_33099:
    fn = elt(env, 9); // lowertowerp
    v_33271 = (*qfn2(fn))(fn, v_33272, v_33271);
    env = stack[-4];
    goto v_33081;
v_33083:
    v_33271 = nil;
    goto v_33081;
    v_33271 = nil;
v_33081:
    goto v_33069;
v_33071:
    v_33271 = nil;
    goto v_33069;
    v_33271 = nil;
v_33069:
    if (v_33271 == nil) goto v_33067;
    goto v_33065;
v_33067:
    goto v_33121;
v_33117:
    v_33272 = stack[-1];
    goto v_33118;
v_33119:
    v_33271 = elt(env, 3); // i
    goto v_33120;
v_33121:
    goto v_33117;
v_33118:
    goto v_33119;
v_33120:
    if (v_33272 == v_33271) goto v_33115;
    else goto v_33116;
v_33115:
    v_33271 = lisp_true;
    goto v_33114;
v_33116:
    goto v_33140;
v_33136:
    v_33272 = stack[-1];
    goto v_33137;
v_33138:
    v_33271 = elt(env, 1); // expt
    goto v_33139;
v_33140:
    goto v_33136;
v_33137:
    goto v_33138;
v_33139:
    if (!consp(v_33272)) goto v_33134;
    v_33272 = qcar(v_33272);
    if (v_33272 == v_33271) goto v_33133;
    else goto v_33134;
v_33133:
    goto v_33147;
v_33143:
    v_33271 = stack[-1];
    v_33271 = qcdr(v_33271);
    v_33271 = qcdr(v_33271);
    v_33272 = qcar(v_33271);
    goto v_33144;
v_33145:
    v_33271 = elt(env, 4); // (quotient 1 2)
    goto v_33146;
v_33147:
    goto v_33143;
v_33144:
    goto v_33145;
v_33146:
    v_33271 = (equal(v_33272, v_33271) ? lisp_true : nil);
    goto v_33132;
v_33134:
    v_33271 = nil;
    goto v_33132;
    v_33271 = nil;
v_33132:
    if (v_33271 == nil) goto v_33130;
    v_33271 = lisp_true;
    goto v_33128;
v_33130:
    goto v_33165;
v_33161:
    v_33272 = stack[-1];
    goto v_33162;
v_33163:
    v_33271 = elt(env, 5); // sqrt
    goto v_33164;
v_33165:
    goto v_33161;
v_33162:
    goto v_33163;
v_33164:
    v_33271 = Leqcar(nil, v_33272, v_33271);
    env = stack[-4];
    goto v_33128;
    v_33271 = nil;
v_33128:
    goto v_33114;
    v_33271 = nil;
v_33114:
    if (v_33271 == nil) goto v_33112;
    goto v_33173;
v_33169:
    goto v_33179;
v_33175:
    v_33272 = stack[-2];
    goto v_33176;
v_33177:
    v_33271 = stack[-1];
    goto v_33178;
v_33179:
    goto v_33175;
v_33176:
    goto v_33177;
v_33178:
    fn = elt(env, 10); // mkmain
    v_33272 = (*qfn2(fn))(fn, v_33272, v_33271);
    env = stack[-4];
    goto v_33170;
v_33171:
    v_33271 = stack[-1];
    goto v_33172;
v_33173:
    goto v_33169;
v_33170:
    goto v_33171;
v_33172:
    {
        fn = elt(env, 11); // conjquadratic
        return (*qfn2(fn))(fn, v_33272, v_33271);
    }
v_33112:
    goto v_33194;
v_33190:
    v_33272 = stack[-1];
    goto v_33191;
v_33192:
    v_33271 = elt(env, 1); // expt
    goto v_33193;
v_33194:
    goto v_33190;
v_33191:
    goto v_33192;
v_33193:
    if (!consp(v_33272)) goto v_33188;
    v_33272 = qcar(v_33272);
    if (v_33272 == v_33271) goto v_33187;
    else goto v_33188;
v_33187:
    goto v_33201;
v_33197:
    v_33271 = stack[-1];
    v_33271 = qcdr(v_33271);
    v_33271 = qcdr(v_33271);
    v_33272 = qcar(v_33271);
    goto v_33198;
v_33199:
    v_33271 = elt(env, 6); // (quotient 1 3)
    goto v_33200;
v_33201:
    goto v_33197;
v_33198:
    goto v_33199;
v_33200:
    v_33271 = (equal(v_33272, v_33271) ? lisp_true : nil);
    goto v_33186;
v_33188:
    v_33271 = nil;
    goto v_33186;
    v_33271 = nil;
v_33186:
    if (v_33271 == nil) goto v_33184;
    goto v_33216;
v_33212:
    goto v_33222;
v_33218:
    v_33272 = stack[-2];
    goto v_33219;
v_33220:
    v_33271 = stack[-1];
    goto v_33221;
v_33222:
    goto v_33218;
v_33219:
    goto v_33220;
v_33221:
    fn = elt(env, 10); // mkmain
    v_33272 = (*qfn2(fn))(fn, v_33272, v_33271);
    env = stack[-4];
    goto v_33213;
v_33214:
    v_33271 = stack[-1];
    goto v_33215;
v_33216:
    goto v_33212;
v_33213:
    goto v_33214;
v_33215:
    {
        fn = elt(env, 12); // conjcubic
        return (*qfn2(fn))(fn, v_33272, v_33271);
    }
v_33184:
    goto v_33237;
v_33233:
    v_33272 = stack[-1];
    goto v_33234;
v_33235:
    v_33271 = elt(env, 1); // expt
    goto v_33236;
v_33237:
    goto v_33233;
v_33234:
    goto v_33235;
v_33236:
    if (!consp(v_33272)) goto v_33231;
    v_33272 = qcar(v_33272);
    if (v_33272 == v_33271) goto v_33230;
    else goto v_33231;
v_33230:
    goto v_33244;
v_33240:
    v_33271 = stack[-1];
    v_33271 = qcdr(v_33271);
    v_33271 = qcdr(v_33271);
    v_33272 = qcar(v_33271);
    goto v_33241;
v_33242:
    v_33271 = elt(env, 7); // (quotient 1 4)
    goto v_33243;
v_33244:
    goto v_33240;
v_33241:
    goto v_33242;
v_33243:
    v_33271 = (equal(v_33272, v_33271) ? lisp_true : nil);
    goto v_33229;
v_33231:
    v_33271 = nil;
    goto v_33229;
    v_33271 = nil;
v_33229:
    if (v_33271 == nil) goto v_33227;
    goto v_33259;
v_33255:
    goto v_33265;
v_33261:
    v_33272 = stack[-2];
    goto v_33262;
v_33263:
    v_33271 = stack[-1];
    goto v_33264;
v_33265:
    goto v_33261;
v_33262:
    goto v_33263;
v_33264:
    fn = elt(env, 10); // mkmain
    v_33272 = (*qfn2(fn))(fn, v_33272, v_33271);
    env = stack[-4];
    goto v_33256;
v_33257:
    v_33271 = stack[-1];
    goto v_33258;
v_33259:
    goto v_33255;
v_33256:
    goto v_33257;
v_33258:
    {
        fn = elt(env, 13); // conjquartic
        return (*qfn2(fn))(fn, v_33272, v_33271);
    }
v_33227:
v_33065:
    v_33271 = stack[-3];
    v_33271 = qcdr(v_33271);
    stack[-3] = v_33271;
    goto v_33053;
v_33052:
    return onevalue(v_33271);
}



// Code for lowestdeg

static LispObject CC_lowestdeg(LispObject env,
                         LispObject v_33046, LispObject v_33047)
{
    env = qenv(env);
    LispObject v_33141, v_33142;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33047,v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33046,v_33047);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_33047;
    v_33141 = v_33046;
// end of prologue
    fn = elt(env, 3); // simp!*
    v_33141 = (*qfn1(fn))(fn, v_33141);
    env = stack[-4];
    stack[-1] = v_33141;
    v_33141 = stack[-1];
    if (!consp(v_33141)) goto v_33063;
    else goto v_33064;
v_33063:
    v_33141 = lisp_true;
    goto v_33062;
v_33064:
    v_33141 = stack[-1];
    v_33141 = qcar(v_33141);
    v_33141 = (consp(v_33141) ? nil : lisp_true);
    goto v_33062;
    v_33141 = nil;
v_33062:
    if (v_33141 == nil) goto v_33060;
    v_33141 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33054;
v_33060:
    v_33141 = stack[-1];
    fn = elt(env, 4); // !*q2f
    v_33141 = (*qfn1(fn))(fn, v_33141);
    env = stack[-4];
    stack[-1] = v_33141;
    v_33141 = stack[-1];
    fn = elt(env, 5); // erase_pol_cst
    v_33141 = (*qfn1(fn))(fn, v_33141);
    env = stack[-4];
    stack[0] = v_33141;
    goto v_33085;
v_33081:
    v_33142 = stack[0];
    goto v_33082;
v_33083:
    v_33141 = stack[-1];
    goto v_33084;
v_33085:
    goto v_33081;
v_33082:
    goto v_33083;
v_33084:
    if (equal(v_33142, v_33141)) goto v_33080;
    v_33141 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33054;
v_33080:
    v_33141 = stack[-2];
    fn = elt(env, 6); // !*a2k
    v_33141 = (*qfn1(fn))(fn, v_33141);
    env = stack[-4];
    stack[0] = v_33141;
    v_33141 = stack[-2];
    v_33141 = ncons(v_33141);
    env = stack[-4];
    fn = elt(env, 7); // setkorder
    v_33141 = (*qfn1(fn))(fn, v_33141);
    env = stack[-4];
    stack[-3] = v_33141;
    v_33141 = stack[-1];
    fn = elt(env, 8); // reorder
    v_33141 = (*qfn1(fn))(fn, v_33141);
    env = stack[-4];
    stack[-2] = v_33141;
    v_33141 = stack[-3];
    fn = elt(env, 7); // setkorder
    v_33141 = (*qfn1(fn))(fn, v_33141);
    env = stack[-4];
    v_33141 = stack[-2];
    v_33141 = Lreverse(nil, v_33141);
    env = stack[-4];
    stack[-2] = v_33141;
    v_33141 = stack[-2];
    v_33141 = qcar(v_33141);
    v_33141 = qcar(v_33141);
    v_33141 = qcar(v_33141);
    stack[-1] = v_33141;
    v_33141 = stack[-1];
    if (!consp(v_33141)) goto v_33107;
    goto v_33117;
v_33113:
    v_33141 = stack[-1];
    v_33142 = qcar(v_33141);
    goto v_33114;
v_33115:
    v_33141 = elt(env, 1); // expt
    goto v_33116;
v_33117:
    goto v_33113;
v_33114:
    goto v_33115;
v_33116:
    if (v_33142 == v_33141) goto v_33111;
    else goto v_33112;
v_33111:
    v_33141 = elt(env, 2); // "exponents must be integers"
    fn = elt(env, 9); // rederr
    v_33141 = (*qfn1(fn))(fn, v_33141);
    goto v_33110;
v_33112:
v_33110:
    goto v_33105;
v_33107:
v_33105:
    goto v_33131;
v_33127:
    v_33142 = stack[-1];
    goto v_33128;
v_33129:
    v_33141 = stack[0];
    goto v_33130;
v_33131:
    goto v_33127;
v_33128:
    goto v_33129;
v_33130:
    if (equal(v_33142, v_33141)) goto v_33126;
    v_33141 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33054;
v_33126:
    v_33141 = stack[-2];
    v_33141 = qcar(v_33141);
    v_33141 = qcar(v_33141);
    v_33141 = qcdr(v_33141);
    goto v_33054;
    v_33141 = nil;
v_33054:
    return onevalue(v_33141);
}



// Code for add!-to!-sorted!-tree

static LispObject CC_addKtoKsortedKtree(LispObject env,
                         LispObject v_33046, LispObject v_33047)
{
    env = qenv(env);
    LispObject v_33155, v_33156, v_33157;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33047,v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33046,v_33047);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_33047;
    stack[-1] = v_33046;
// end of prologue
    stack[-2] = nil;
v_33052:
    v_33155 = stack[0];
    if (v_33155 == nil) goto v_33055;
    else goto v_33056;
v_33055:
    goto v_33063;
v_33059:
    stack[0] = stack[-2];
    goto v_33060;
v_33061:
    goto v_33072;
v_33066:
    v_33157 = nil;
    goto v_33067;
v_33068:
    v_33156 = stack[-1];
    goto v_33069;
v_33070:
    v_33155 = nil;
    goto v_33071;
v_33072:
    goto v_33066;
v_33067:
    goto v_33068;
v_33069:
    goto v_33070;
v_33071:
    v_33155 = list2star(v_33157, v_33156, v_33155);
    env = stack[-3];
    goto v_33062;
v_33063:
    goto v_33059;
v_33060:
    goto v_33061;
v_33062:
    {
        LispObject v_33161 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_33161, v_33155);
    }
v_33056:
    goto v_33082;
v_33078:
    v_33156 = stack[-1];
    goto v_33079;
v_33080:
    v_33155 = stack[0];
    v_33155 = qcdr(v_33155);
    v_33155 = qcar(v_33155);
    goto v_33081;
v_33082:
    goto v_33078;
v_33079:
    goto v_33080;
v_33081:
    if (equal(v_33156, v_33155)) goto v_33076;
    else goto v_33077;
v_33076:
    goto v_33092;
v_33088:
    v_33156 = stack[-2];
    goto v_33089;
v_33090:
    v_33155 = stack[0];
    goto v_33091;
v_33092:
    goto v_33088;
v_33089:
    goto v_33090;
v_33091:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_33156, v_33155);
    }
v_33077:
    goto v_33102;
v_33098:
    v_33156 = stack[-1];
    goto v_33099;
v_33100:
    v_33155 = stack[0];
    v_33155 = qcdr(v_33155);
    v_33155 = qcar(v_33155);
    goto v_33101;
v_33102:
    goto v_33098;
v_33099:
    goto v_33100;
v_33101:
    v_33155 = Lorderp(nil, v_33156, v_33155);
    env = stack[-3];
    if (v_33155 == nil) goto v_33096;
    goto v_33112;
v_33108:
    goto v_33109;
v_33110:
    goto v_33119;
v_33115:
    goto v_33125;
v_33121:
    v_33156 = stack[-1];
    goto v_33122;
v_33123:
    v_33155 = stack[0];
    v_33155 = qcar(v_33155);
    goto v_33124;
v_33125:
    goto v_33121;
v_33122:
    goto v_33123;
v_33124:
    v_33156 = CC_addKtoKsortedKtree(elt(env, 0), v_33156, v_33155);
    env = stack[-3];
    goto v_33116;
v_33117:
    v_33155 = stack[0];
    v_33155 = qcdr(v_33155);
    goto v_33118;
v_33119:
    goto v_33115;
v_33116:
    goto v_33117;
v_33118:
    v_33155 = cons(v_33156, v_33155);
    env = stack[-3];
    goto v_33111;
v_33112:
    goto v_33108;
v_33109:
    goto v_33110;
v_33111:
    {
        LispObject v_33162 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_33162, v_33155);
    }
v_33096:
    goto v_33138;
v_33134:
    v_33155 = stack[0];
    v_33156 = qcar(v_33155);
    goto v_33135;
v_33136:
    v_33155 = stack[-2];
    goto v_33137;
v_33138:
    goto v_33134;
v_33135:
    goto v_33136;
v_33137:
    v_33155 = cons(v_33156, v_33155);
    env = stack[-3];
    stack[-2] = v_33155;
    goto v_33147;
v_33143:
    v_33155 = stack[0];
    v_33155 = qcdr(v_33155);
    v_33156 = qcar(v_33155);
    goto v_33144;
v_33145:
    v_33155 = stack[-2];
    goto v_33146;
v_33147:
    goto v_33143;
v_33144:
    goto v_33145;
v_33146:
    v_33155 = cons(v_33156, v_33155);
    env = stack[-3];
    stack[-2] = v_33155;
    v_33155 = stack[0];
    v_33155 = qcdr(v_33155);
    v_33155 = qcdr(v_33155);
    stack[0] = v_33155;
    goto v_33052;
    v_33155 = nil;
    return onevalue(v_33155);
}



// Code for ofsf_exploitknowl

static LispObject CC_ofsf_exploitknowl(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33413, v_33414, v_33415, v_33416;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(13);
// copy arguments values to proper place
    v_33413 = v_33046;
// end of prologue
    stack[-11] = nil;
    stack[-10] = nil;
    stack[-9] = nil;
    stack[-8] = nil;
    stack[-7] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-1] = v_33413;
v_33065:
    v_33413 = stack[-1];
    if (v_33413 == nil) goto v_33069;
    else goto v_33070;
v_33069:
    goto v_33064;
v_33070:
    v_33413 = stack[-1];
    v_33413 = qcar(v_33413);
    stack[0] = v_33413;
    v_33413 = stack[0];
    v_33413 = qcar(v_33413);
    fn = elt(env, 8); // sfto_varp
    v_33413 = (*qfn1(fn))(fn, v_33413);
    env = stack[-12];
    stack[-4] = v_33413;
    if (v_33413 == nil) goto v_33079;
    v_33413 = stack[0];
    v_33413 = qcdr(v_33413);
    stack[0] = v_33413;
v_33086:
    v_33413 = stack[0];
    if (v_33413 == nil) goto v_33091;
    else goto v_33092;
v_33091:
    goto v_33085;
v_33092:
    v_33413 = stack[0];
    v_33413 = qcar(v_33413);
    v_33413 = qcdr(v_33413);
    v_33414 = v_33413;
    v_33413 = v_33414;
    v_33413 = qcar(v_33413);
    stack[-3] = v_33413;
    v_33413 = v_33414;
    v_33413 = qcdr(v_33413);
    v_33414 = v_33413;
    v_33413 = v_33414;
    fn = elt(env, 9); // negsq
    v_33413 = (*qfn1(fn))(fn, v_33413);
    env = stack[-12];
    v_33414 = v_33413;
    v_33413 = v_33414;
    v_33413 = qcar(v_33413);
    if (v_33413 == nil) goto v_33112;
    else goto v_33111;
v_33112:
    v_33413 = (LispObject)0+TAG_FIXNUM; // 0
v_33111:
    stack[-2] = v_33413;
    goto v_33124;
v_33120:
    v_33415 = stack[-3];
    goto v_33121;
v_33122:
    v_33413 = elt(env, 1); // equal
    goto v_33123;
v_33124:
    goto v_33120;
v_33121:
    goto v_33122;
v_33123:
    if (v_33415 == v_33413) goto v_33118;
    else goto v_33119;
v_33118:
    v_33413 = qvalue(elt(env, 2)); // !*rlsippsubst
    if (v_33413 == nil) goto v_33130;
    goto v_33139;
v_33133:
    v_33415 = stack[-4];
    goto v_33134;
v_33135:
    goto v_33136;
v_33137:
    v_33413 = stack[-11];
    goto v_33138;
v_33139:
    goto v_33133;
v_33134:
    goto v_33135;
v_33136:
    goto v_33137;
v_33138:
    v_33413 = acons(v_33415, v_33414, v_33413);
    env = stack[-12];
    stack[-11] = v_33413;
    goto v_33128;
v_33130:
    goto v_33154;
v_33150:
    v_33414 = stack[-2];
    goto v_33151;
v_33152:
    v_33413 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33153;
v_33154:
    goto v_33150;
v_33151:
    goto v_33152;
v_33153:
    v_33413 = (LispObject)greaterp2(v_33414, v_33413);
    v_33413 = v_33413 ? lisp_true : nil;
    env = stack[-12];
    if (v_33413 == nil) goto v_33148;
    goto v_33162;
v_33158:
    v_33414 = stack[-4];
    goto v_33159;
v_33160:
    v_33413 = stack[-9];
    goto v_33161;
v_33162:
    goto v_33158;
v_33159:
    goto v_33160;
v_33161:
    fn = elt(env, 10); // lto_insertq
    v_33413 = (*qfn2(fn))(fn, v_33414, v_33413);
    env = stack[-12];
    stack[-9] = v_33413;
    goto v_33146;
v_33148:
    goto v_33172;
v_33168:
    v_33414 = stack[-2];
    goto v_33169;
v_33170:
    v_33413 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33171;
v_33172:
    goto v_33168;
v_33169:
    goto v_33170;
v_33171:
    v_33413 = (LispObject)lessp2(v_33414, v_33413);
    v_33413 = v_33413 ? lisp_true : nil;
    env = stack[-12];
    if (v_33413 == nil) goto v_33166;
    goto v_33180;
v_33176:
    v_33414 = stack[-4];
    goto v_33177;
v_33178:
    v_33413 = stack[-8];
    goto v_33179;
v_33180:
    goto v_33176;
v_33177:
    goto v_33178;
v_33179:
    fn = elt(env, 10); // lto_insertq
    v_33413 = (*qfn2(fn))(fn, v_33414, v_33413);
    env = stack[-12];
    stack[-8] = v_33413;
    goto v_33146;
v_33166:
    goto v_33190;
v_33186:
    v_33414 = stack[-2];
    goto v_33187;
v_33188:
    v_33413 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33189;
v_33190:
    goto v_33186;
v_33187:
    goto v_33188;
v_33189:
    v_33413 = Leqn(nil, v_33414, v_33413);
    env = stack[-12];
    if (v_33413 == nil) goto v_33184;
    goto v_33198;
v_33194:
    v_33414 = stack[-4];
    goto v_33195;
v_33196:
    v_33413 = stack[-10];
    goto v_33197;
v_33198:
    goto v_33194;
v_33195:
    goto v_33196;
v_33197:
    fn = elt(env, 10); // lto_insertq
    v_33413 = (*qfn2(fn))(fn, v_33414, v_33413);
    env = stack[-12];
    stack[-10] = v_33413;
    goto v_33146;
v_33184:
v_33146:
    goto v_33128;
v_33128:
    goto v_33117;
v_33119:
    goto v_33207;
v_33203:
    v_33414 = stack[-3];
    goto v_33204;
v_33205:
    v_33413 = elt(env, 3); // greaterp
    goto v_33206;
v_33207:
    goto v_33203;
v_33204:
    goto v_33205;
v_33206:
    if (v_33414 == v_33413) goto v_33201;
    else goto v_33202;
v_33201:
    goto v_33219;
v_33215:
    v_33414 = stack[-2];
    goto v_33216;
v_33217:
    v_33413 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33218;
v_33219:
    goto v_33215;
v_33216:
    goto v_33217;
v_33218:
    v_33413 = (LispObject)geq2(v_33414, v_33413);
    v_33413 = v_33413 ? lisp_true : nil;
    env = stack[-12];
    if (v_33413 == nil) goto v_33213;
    goto v_33227;
v_33223:
    v_33414 = stack[-4];
    goto v_33224;
v_33225:
    v_33413 = stack[-9];
    goto v_33226;
v_33227:
    goto v_33223;
v_33224:
    goto v_33225;
v_33226:
    fn = elt(env, 10); // lto_insertq
    v_33413 = (*qfn2(fn))(fn, v_33414, v_33413);
    env = stack[-12];
    stack[-9] = v_33413;
    goto v_33211;
v_33213:
v_33211:
    goto v_33117;
v_33202:
    goto v_33236;
v_33232:
    v_33414 = stack[-3];
    goto v_33233;
v_33234:
    v_33413 = elt(env, 4); // geq
    goto v_33235;
v_33236:
    goto v_33232;
v_33233:
    goto v_33234;
v_33235:
    if (v_33414 == v_33413) goto v_33230;
    else goto v_33231;
v_33230:
    goto v_33248;
v_33244:
    v_33414 = stack[-2];
    goto v_33245;
v_33246:
    v_33413 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33247;
v_33248:
    goto v_33244;
v_33245:
    goto v_33246;
v_33247:
    v_33413 = (LispObject)greaterp2(v_33414, v_33413);
    v_33413 = v_33413 ? lisp_true : nil;
    env = stack[-12];
    if (v_33413 == nil) goto v_33242;
    goto v_33256;
v_33252:
    v_33414 = stack[-4];
    goto v_33253;
v_33254:
    v_33413 = stack[-9];
    goto v_33255;
v_33256:
    goto v_33252;
v_33253:
    goto v_33254;
v_33255:
    fn = elt(env, 10); // lto_insertq
    v_33413 = (*qfn2(fn))(fn, v_33414, v_33413);
    env = stack[-12];
    stack[-9] = v_33413;
    goto v_33240;
v_33242:
    goto v_33266;
v_33262:
    v_33414 = stack[-2];
    goto v_33263;
v_33264:
    v_33413 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33265;
v_33266:
    goto v_33262;
v_33263:
    goto v_33264;
v_33265:
    v_33413 = Leqn(nil, v_33414, v_33413);
    env = stack[-12];
    if (v_33413 == nil) goto v_33260;
    goto v_33274;
v_33270:
    v_33414 = stack[-4];
    goto v_33271;
v_33272:
    v_33413 = stack[-7];
    goto v_33273;
v_33274:
    goto v_33270;
v_33271:
    goto v_33272;
v_33273:
    fn = elt(env, 10); // lto_insertq
    v_33413 = (*qfn2(fn))(fn, v_33414, v_33413);
    env = stack[-12];
    stack[-7] = v_33413;
    goto v_33240;
v_33260:
v_33240:
    goto v_33117;
v_33231:
    goto v_33283;
v_33279:
    v_33414 = stack[-3];
    goto v_33280;
v_33281:
    v_33413 = elt(env, 5); // lessp
    goto v_33282;
v_33283:
    goto v_33279;
v_33280:
    goto v_33281;
v_33282:
    if (v_33414 == v_33413) goto v_33277;
    else goto v_33278;
v_33277:
    goto v_33295;
v_33291:
    v_33414 = stack[-2];
    goto v_33292;
v_33293:
    v_33413 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33294;
v_33295:
    goto v_33291;
v_33292:
    goto v_33293;
v_33294:
    v_33413 = (LispObject)lesseq2(v_33414, v_33413);
    v_33413 = v_33413 ? lisp_true : nil;
    env = stack[-12];
    if (v_33413 == nil) goto v_33289;
    goto v_33303;
v_33299:
    v_33414 = stack[-4];
    goto v_33300;
v_33301:
    v_33413 = stack[-8];
    goto v_33302;
v_33303:
    goto v_33299;
v_33300:
    goto v_33301;
v_33302:
    fn = elt(env, 10); // lto_insertq
    v_33413 = (*qfn2(fn))(fn, v_33414, v_33413);
    env = stack[-12];
    stack[-8] = v_33413;
    goto v_33287;
v_33289:
v_33287:
    goto v_33117;
v_33278:
    goto v_33312;
v_33308:
    v_33414 = stack[-3];
    goto v_33309;
v_33310:
    v_33413 = elt(env, 6); // leq
    goto v_33311;
v_33312:
    goto v_33308;
v_33309:
    goto v_33310;
v_33311:
    if (v_33414 == v_33413) goto v_33306;
    else goto v_33307;
v_33306:
    goto v_33324;
v_33320:
    v_33414 = stack[-2];
    goto v_33321;
v_33322:
    v_33413 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33323;
v_33324:
    goto v_33320;
v_33321:
    goto v_33322;
v_33323:
    v_33413 = (LispObject)lessp2(v_33414, v_33413);
    v_33413 = v_33413 ? lisp_true : nil;
    env = stack[-12];
    if (v_33413 == nil) goto v_33318;
    goto v_33332;
v_33328:
    v_33414 = stack[-4];
    goto v_33329;
v_33330:
    v_33413 = stack[-8];
    goto v_33331;
v_33332:
    goto v_33328;
v_33329:
    goto v_33330;
v_33331:
    fn = elt(env, 10); // lto_insertq
    v_33413 = (*qfn2(fn))(fn, v_33414, v_33413);
    env = stack[-12];
    stack[-8] = v_33413;
    goto v_33316;
v_33318:
    goto v_33342;
v_33338:
    v_33414 = stack[-2];
    goto v_33339;
v_33340:
    v_33413 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33341;
v_33342:
    goto v_33338;
v_33339:
    goto v_33340;
v_33341:
    v_33413 = Leqn(nil, v_33414, v_33413);
    env = stack[-12];
    if (v_33413 == nil) goto v_33336;
    goto v_33350;
v_33346:
    v_33414 = stack[-4];
    goto v_33347;
v_33348:
    v_33413 = stack[-6];
    goto v_33349;
v_33350:
    goto v_33346;
v_33347:
    goto v_33348;
v_33349:
    fn = elt(env, 10); // lto_insertq
    v_33413 = (*qfn2(fn))(fn, v_33414, v_33413);
    env = stack[-12];
    stack[-6] = v_33413;
    goto v_33316;
v_33336:
v_33316:
    goto v_33117;
v_33307:
    goto v_33359;
v_33355:
    v_33414 = stack[-3];
    goto v_33356;
v_33357:
    v_33413 = elt(env, 7); // neq
    goto v_33358;
v_33359:
    goto v_33355;
v_33356:
    goto v_33357;
v_33358:
    if (v_33414 == v_33413) goto v_33353;
    else goto v_33354;
v_33353:
    goto v_33371;
v_33367:
    v_33414 = stack[-2];
    goto v_33368;
v_33369:
    v_33413 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33370;
v_33371:
    goto v_33367;
v_33368:
    goto v_33369;
v_33370:
    v_33413 = Leqn(nil, v_33414, v_33413);
    env = stack[-12];
    if (v_33413 == nil) goto v_33365;
    goto v_33379;
v_33375:
    v_33414 = stack[-4];
    goto v_33376;
v_33377:
    v_33413 = stack[-5];
    goto v_33378;
v_33379:
    goto v_33375;
v_33376:
    goto v_33377;
v_33378:
    fn = elt(env, 10); // lto_insertq
    v_33413 = (*qfn2(fn))(fn, v_33414, v_33413);
    env = stack[-12];
    stack[-5] = v_33413;
    goto v_33363;
v_33365:
v_33363:
    goto v_33117;
v_33354:
v_33117:
    v_33413 = stack[0];
    v_33413 = qcdr(v_33413);
    stack[0] = v_33413;
    goto v_33086;
v_33085:
    goto v_33077;
v_33079:
v_33077:
    v_33413 = stack[-1];
    v_33413 = qcdr(v_33413);
    stack[-1] = v_33413;
    goto v_33065;
v_33064:
    goto v_33395;
v_33387:
    stack[0] = stack[-11];
    goto v_33388;
v_33389:
    stack[-1] = stack[-10];
    goto v_33390;
v_33391:
    stack[-2] = stack[-9];
    goto v_33392;
v_33393:
    goto v_33408;
v_33400:
    v_33416 = stack[-8];
    goto v_33401;
v_33402:
    v_33415 = stack[-7];
    goto v_33403;
v_33404:
    v_33414 = stack[-6];
    goto v_33405;
v_33406:
    v_33413 = stack[-5];
    goto v_33407;
v_33408:
    goto v_33400;
v_33401:
    goto v_33402;
v_33403:
    goto v_33404;
v_33405:
    goto v_33406;
v_33407:
    v_33413 = list4(v_33416, v_33415, v_33414, v_33413);
    goto v_33394;
v_33395:
    goto v_33387;
v_33388:
    goto v_33389;
v_33390:
    goto v_33391;
v_33392:
    goto v_33393;
v_33394:
    {
        LispObject v_33429 = stack[0];
        LispObject v_33430 = stack[-1];
        LispObject v_33431 = stack[-2];
        return list3star(v_33429, v_33430, v_33431, v_33413);
    }
    return onevalue(v_33413);
}



// Code for uterm

static LispObject CC_uterm(LispObject env,
                         LispObject v_33047, LispObject v_33048)
{
    env = qenv(env);
    LispObject v_33136, v_33137;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33048,v_33047);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33047,v_33048);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_33136 = v_33048;
    stack[-1] = v_33047;
// end of prologue
// Binding rhs!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = v_33136; // rhs!*
    v_33136 = qvalue(elt(env, 1)); // rhs!*
    if (v_33136 == nil) goto v_33056;
    else goto v_33057;
v_33056:
    v_33136 = nil;
    goto v_33055;
v_33057:
    goto v_33071;
v_33067:
    v_33137 = stack[-1];
    goto v_33068;
v_33069:
    v_33136 = qvalue(elt(env, 1)); // rhs!*
    v_33136 = qcar(v_33136);
    v_33136 = qcar(v_33136);
    goto v_33070;
v_33071:
    goto v_33067;
v_33068:
    goto v_33069;
v_33070:
    fn = elt(env, 2); // addinds
    v_33136 = (*qfn2(fn))(fn, v_33137, v_33136);
    env = stack[-3];
    stack[0] = v_33136;
    goto v_33081;
v_33077:
    v_33136 = qvalue(elt(env, 1)); // rhs!*
    v_33136 = qcar(v_33136);
    v_33136 = qcdr(v_33136);
    v_33137 = qcar(v_33136);
    goto v_33078;
v_33079:
    v_33136 = stack[-1];
    goto v_33080;
v_33081:
    goto v_33077;
v_33078:
    goto v_33079;
v_33080:
    fn = elt(env, 3); // evaluatecoeffts
    v_33136 = (*qfn2(fn))(fn, v_33137, v_33136);
    env = stack[-3];
    v_33137 = v_33136;
    if (v_33137 == nil) goto v_33089;
    else goto v_33090;
v_33089:
    goto v_33097;
v_33093:
    v_33137 = stack[-1];
    goto v_33094;
v_33095:
    v_33136 = qvalue(elt(env, 1)); // rhs!*
    v_33136 = qcdr(v_33136);
    goto v_33096;
v_33097:
    goto v_33093;
v_33094:
    goto v_33095;
v_33096:
    v_33136 = CC_uterm(elt(env, 0), v_33137, v_33136);
    goto v_33065;
v_33090:
    goto v_33106;
v_33102:
    v_33137 = v_33136;
    goto v_33103;
v_33104:
    v_33136 = qvalue(elt(env, 1)); // rhs!*
    v_33136 = qcar(v_33136);
    v_33136 = qcdr(v_33136);
    v_33136 = qcdr(v_33136);
    goto v_33105;
v_33106:
    goto v_33102;
v_33103:
    goto v_33104;
v_33105:
    v_33136 = cons(v_33137, v_33136);
    env = stack[-3];
    goto v_33117;
v_33113:
    goto v_33124;
v_33120:
    v_33137 = stack[0];
    goto v_33121;
v_33122:
    goto v_33123;
v_33124:
    goto v_33120;
v_33121:
    goto v_33122;
v_33123:
    v_33136 = cons(v_33137, v_33136);
    env = stack[-3];
    stack[0] = ncons(v_33136);
    env = stack[-3];
    goto v_33114;
v_33115:
    goto v_33132;
v_33128:
    v_33137 = stack[-1];
    goto v_33129;
v_33130:
    v_33136 = qvalue(elt(env, 1)); // rhs!*
    v_33136 = qcdr(v_33136);
    goto v_33131;
v_33132:
    goto v_33128;
v_33129:
    goto v_33130;
v_33131:
    v_33136 = CC_uterm(elt(env, 0), v_33137, v_33136);
    env = stack[-3];
    goto v_33116;
v_33117:
    goto v_33113;
v_33114:
    goto v_33115;
v_33116:
    fn = elt(env, 4); // plusdf
    v_33136 = (*qfn2(fn))(fn, stack[0], v_33136);
v_33065:
    goto v_33055;
    v_33136 = nil;
v_33055:
    ;}  // end of a binding scope
    return onevalue(v_33136);
}



// Code for get!*nr!*real!*irred!*reps

static LispObject CC_getHnrHrealHirredHreps(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33058, v_33059;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33058 = v_33046;
// end of prologue
    goto v_33055;
v_33051:
    goto v_33052;
v_33053:
    v_33059 = elt(env, 1); // realrepnumber
    goto v_33054;
v_33055:
    goto v_33051;
v_33052:
    goto v_33053;
v_33054:
    return get(v_33058, v_33059);
    return onevalue(v_33058);
}



// Code for qqe_simpat

static LispObject CC_qqe_simpat(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33049;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33049 = v_33046;
// end of prologue
    return onevalue(v_33049);
}



// Code for pasf_ceeq

static LispObject CC_pasf_ceeq(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33159, v_33160;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33046;
// end of prologue
    goto v_33067;
v_33063:
    v_33160 = stack[0];
    goto v_33064;
v_33065:
    v_33159 = elt(env, 1); // true
    goto v_33066;
v_33067:
    goto v_33063;
v_33064:
    goto v_33065;
v_33066:
    if (v_33160 == v_33159) goto v_33061;
    else goto v_33062;
v_33061:
    v_33159 = lisp_true;
    goto v_33060;
v_33062:
    goto v_33077;
v_33073:
    v_33160 = stack[0];
    goto v_33074;
v_33075:
    v_33159 = elt(env, 2); // false
    goto v_33076;
v_33077:
    goto v_33073;
v_33074:
    goto v_33075;
v_33076:
    v_33159 = (v_33160 == v_33159 ? lisp_true : nil);
    goto v_33060;
    v_33159 = nil;
v_33060:
    if (v_33159 == nil) goto v_33058;
    v_33159 = lisp_true;
    goto v_33056;
v_33058:
    goto v_33088;
v_33084:
    goto v_33101;
v_33097:
    v_33160 = stack[0];
    goto v_33098;
v_33099:
    v_33159 = elt(env, 1); // true
    goto v_33100;
v_33101:
    goto v_33097;
v_33098:
    goto v_33099;
v_33100:
    if (v_33160 == v_33159) goto v_33095;
    else goto v_33096;
v_33095:
    v_33159 = lisp_true;
    goto v_33094;
v_33096:
    goto v_33111;
v_33107:
    v_33160 = stack[0];
    goto v_33108;
v_33109:
    v_33159 = elt(env, 2); // false
    goto v_33110;
v_33111:
    goto v_33107;
v_33108:
    goto v_33109;
v_33110:
    v_33159 = (v_33160 == v_33159 ? lisp_true : nil);
    goto v_33094;
    v_33159 = nil;
v_33094:
    if (v_33159 == nil) goto v_33092;
    v_33159 = stack[0];
    v_33160 = v_33159;
    goto v_33090;
v_33092:
    v_33159 = stack[0];
    v_33159 = qcar(v_33159);
    v_33159 = Lconsp(nil, v_33159);
    env = stack[-2];
    if (v_33159 == nil) goto v_33117;
    v_33159 = stack[0];
    v_33159 = qcar(v_33159);
    v_33159 = qcar(v_33159);
    v_33160 = v_33159;
    goto v_33090;
v_33117:
    v_33159 = stack[0];
    v_33159 = qcar(v_33159);
    v_33160 = v_33159;
    goto v_33090;
    v_33160 = nil;
v_33090:
    goto v_33085;
v_33086:
    v_33159 = elt(env, 3); // (equal neq)
    goto v_33087;
v_33088:
    goto v_33084;
v_33085:
    goto v_33086;
v_33087:
    v_33159 = Lmemq(nil, v_33160, v_33159);
    v_33159 = (v_33159 == nil ? lisp_true : nil);
    goto v_33056;
    v_33159 = nil;
v_33056:
    if (v_33159 == nil) goto v_33054;
    v_33159 = stack[0];
    goto v_33050;
v_33054:
    v_33159 = stack[0];
    v_33159 = qcdr(v_33159);
    v_33159 = qcar(v_33159);
    fn = elt(env, 4); // sfto_dcontentf
    v_33159 = (*qfn1(fn))(fn, v_33159);
    env = stack[-2];
    v_33160 = v_33159;
    goto v_33143;
v_33137:
    v_33159 = stack[0];
    stack[-1] = qcar(v_33159);
    goto v_33138;
v_33139:
    goto v_33151;
v_33147:
    v_33159 = stack[0];
    v_33159 = qcdr(v_33159);
    stack[0] = qcar(v_33159);
    goto v_33148;
v_33149:
    v_33159 = v_33160;
    fn = elt(env, 5); // simp
    v_33159 = (*qfn1(fn))(fn, v_33159);
    env = stack[-2];
    v_33159 = qcar(v_33159);
    goto v_33150;
v_33151:
    goto v_33147;
v_33148:
    goto v_33149;
v_33150:
    fn = elt(env, 6); // quotfx
    v_33160 = (*qfn2(fn))(fn, stack[0], v_33159);
    goto v_33140;
v_33141:
    v_33159 = nil;
    goto v_33142;
v_33143:
    goto v_33137;
v_33138:
    goto v_33139;
v_33140:
    goto v_33141;
v_33142:
    {
        LispObject v_33163 = stack[-1];
        return list3(v_33163, v_33160, v_33159);
    }
v_33050:
    return onevalue(v_33159);
}



// Code for matrix_input_test

static LispObject CC_matrix_input_test(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33077, v_33078, v_33079;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33078 = v_33046;
// end of prologue
    goto v_33059;
v_33055:
    v_33079 = v_33078;
    goto v_33056;
v_33057:
    v_33077 = elt(env, 1); // mat
    goto v_33058;
v_33059:
    goto v_33055;
v_33056:
    goto v_33057;
v_33058:
    if (!consp(v_33079)) goto v_33052;
    v_33079 = qcar(v_33079);
    if (v_33079 == v_33077) goto v_33053;
v_33052:
    goto v_33070;
v_33064:
    v_33079 = elt(env, 2); // "ERROR: `"
    goto v_33065;
v_33066:
    goto v_33067;
v_33068:
    v_33077 = elt(env, 3); // "' is non matrix input."
    goto v_33069;
v_33070:
    goto v_33064;
v_33065:
    goto v_33066;
v_33067:
    goto v_33068;
v_33069:
    v_33077 = list3(v_33079, v_33078, v_33077);
    env = stack[0];
    fn = elt(env, 4); // rederr
    v_33077 = (*qfn1(fn))(fn, v_33077);
    goto v_33051;
v_33053:
    v_33077 = v_33078;
    goto v_33049;
v_33051:
    v_33077 = nil;
v_33049:
    return onevalue(v_33077);
}



// Code for dip!-nc!-ev!-prod

static LispObject CC_dipKncKevKprod(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33079, v_33080, v_33081, v_33082;
    LispObject fn;
    LispObject v_33049, v_33048, v_33047, v_33046;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "dip-nc-ev-prod");
    va_start(aa, nargs);
    v_33046 = va_arg(aa, LispObject);
    v_33047 = va_arg(aa, LispObject);
    v_33048 = va_arg(aa, LispObject);
    v_33049 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_33049,v_33048,v_33047,v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_33046,v_33047,v_33048,v_33049);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_33079 = v_33049;
    v_33080 = v_33048;
    v_33081 = v_33047;
    v_33082 = v_33046;
// end of prologue
    goto v_33058;
v_33052:
    stack[-2] = v_33081;
    goto v_33053;
v_33054:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33055;
v_33056:
    goto v_33068;
v_33062:
    stack[0] = v_33079;
    goto v_33063;
v_33064:
    goto v_33075;
v_33071:
    v_33079 = v_33082;
    goto v_33072;
v_33073:
    goto v_33074;
v_33075:
    goto v_33071;
v_33072:
    goto v_33073;
v_33074:
    fn = elt(env, 1); // bcprod
    v_33080 = (*qfn2(fn))(fn, v_33079, v_33080);
    env = stack[-3];
    goto v_33065;
v_33066:
    v_33079 = nil;
    goto v_33067;
v_33068:
    goto v_33062;
v_33063:
    goto v_33064;
v_33065:
    goto v_33066;
v_33067:
    v_33079 = list2star(stack[0], v_33080, v_33079);
    env = stack[-3];
    goto v_33057;
v_33058:
    goto v_33052;
v_33053:
    goto v_33054;
v_33055:
    goto v_33056;
v_33057:
    {
        LispObject v_33086 = stack[-2];
        LispObject v_33087 = stack[-1];
        fn = elt(env, 2); // dip!-nc!-ev!-prod1
        return (*qfnn(fn))(fn, 3, v_33086, v_33087, v_33079);
    }
}



// Code for row_dim

static LispObject CC_row_dim(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33070;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_33046;
// end of prologue
    v_33070 = qvalue(elt(env, 1)); // !*fast_la
    if (v_33070 == nil) goto v_33056;
    else goto v_33057;
v_33056:
    v_33070 = stack[0];
    fn = elt(env, 3); // matrixp
    v_33070 = (*qfn1(fn))(fn, v_33070);
    env = stack[-1];
    v_33070 = (v_33070 == nil ? lisp_true : nil);
    goto v_33055;
v_33057:
    v_33070 = nil;
    goto v_33055;
    v_33070 = nil;
v_33055:
    if (v_33070 == nil) goto v_33053;
    v_33070 = elt(env, 2); // "Error in row_dim: input should be a matrix."
    fn = elt(env, 4); // rederr
    v_33070 = (*qfn1(fn))(fn, v_33070);
    env = stack[-1];
    goto v_33051;
v_33053:
v_33051:
    v_33070 = stack[0];
    fn = elt(env, 5); // size_of_matrix
    v_33070 = (*qfn1(fn))(fn, v_33070);
    v_33070 = qcar(v_33070);
    return onevalue(v_33070);
}



// Code for unshift

static LispObject CC_unshift(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33110, v_33111, v_33112, v_33113;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33113 = v_33046;
// end of prologue
    v_33110 = qvalue(elt(env, 1)); // !*xo
    v_33112 = v_33110;
    v_33110 = v_33112;
    v_33110 = qcar(v_33110);
    if (!consp(v_33110)) goto v_33057;
    goto v_33068;
v_33064:
    v_33110 = v_33112;
    v_33110 = qcar(v_33110);
    v_33110 = qcdr(v_33110);
    v_33111 = qcar(v_33110);
    goto v_33065;
v_33066:
    v_33110 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33067;
v_33068:
    goto v_33064;
v_33065:
    goto v_33066;
v_33067:
    if (v_33111 == v_33110) goto v_33062;
    else goto v_33063;
v_33062:
    goto v_33078;
v_33074:
    v_33110 = v_33112;
    v_33110 = qcdr(v_33110);
    v_33110 = qcdr(v_33110);
    v_33111 = qcar(v_33110);
    goto v_33075;
v_33076:
    v_33110 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33077;
v_33078:
    goto v_33074;
v_33075:
    goto v_33076;
v_33077:
    v_33110 = (v_33111 == v_33110 ? lisp_true : nil);
    goto v_33061;
v_33063:
    v_33110 = nil;
    goto v_33061;
    v_33110 = nil;
v_33061:
    goto v_33055;
v_33057:
    goto v_33094;
v_33090:
    v_33111 = v_33112;
    goto v_33091;
v_33092:
    v_33110 = elt(env, 2); // (0.0 . 0.0)
    goto v_33093;
v_33094:
    goto v_33090;
v_33091:
    goto v_33092;
v_33093:
    v_33110 = (equal(v_33111, v_33110) ? lisp_true : nil);
    goto v_33055;
    v_33110 = nil;
v_33055:
    if (v_33110 == nil) goto v_33051;
    v_33110 = v_33113;
    goto v_33049;
v_33051:
    goto v_33107;
v_33103:
    v_33111 = v_33113;
    goto v_33104;
v_33105:
    v_33110 = qvalue(elt(env, 1)); // !*xo
    goto v_33106;
v_33107:
    goto v_33103;
v_33104:
    goto v_33105;
v_33106:
    fn = elt(env, 3); // gfplus
    v_33110 = (*qfn2(fn))(fn, v_33111, v_33110);
    env = stack[0];
    {
        fn = elt(env, 4); // gfadjust
        return (*qfn1(fn))(fn, v_33110);
    }
    v_33110 = nil;
v_33049:
    return onevalue(v_33110);
}



// Code for r2speclist

static LispObject CC_r2speclist(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33108, v_33109, v_33110;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_33109 = v_33046;
// end of prologue
    goto v_33057;
v_33053:
    v_33110 = v_33109;
    goto v_33054;
v_33055:
    v_33108 = elt(env, 1); // plus
    goto v_33056;
v_33057:
    goto v_33053;
v_33054:
    goto v_33055;
v_33056:
    if (!consp(v_33110)) goto v_33051;
    v_33110 = qcar(v_33110);
    if (v_33110 == v_33108) goto v_33050;
    else goto v_33051;
v_33050:
    v_33108 = v_33109;
    v_33108 = qcdr(v_33108);
    goto v_33049;
v_33051:
    v_33108 = v_33109;
    v_33108 = ncons(v_33108);
    env = stack[-4];
    goto v_33049;
    v_33108 = nil;
v_33049:
    v_33109 = v_33108;
    v_33108 = v_33109;
    stack[-3] = v_33108;
    v_33108 = stack[-3];
    if (v_33108 == nil) goto v_33075;
    else goto v_33076;
v_33075:
    v_33108 = nil;
    goto v_33070;
v_33076:
    v_33108 = stack[-3];
    v_33108 = qcar(v_33108);
    fn = elt(env, 2); // r2speclist1
    v_33108 = (*qfn1(fn))(fn, v_33108);
    env = stack[-4];
    v_33108 = ncons(v_33108);
    env = stack[-4];
    stack[-1] = v_33108;
    stack[-2] = v_33108;
v_33071:
    v_33108 = stack[-3];
    v_33108 = qcdr(v_33108);
    stack[-3] = v_33108;
    v_33108 = stack[-3];
    if (v_33108 == nil) goto v_33089;
    else goto v_33090;
v_33089:
    v_33108 = stack[-2];
    goto v_33070;
v_33090:
    goto v_33098;
v_33094:
    stack[0] = stack[-1];
    goto v_33095;
v_33096:
    v_33108 = stack[-3];
    v_33108 = qcar(v_33108);
    fn = elt(env, 2); // r2speclist1
    v_33108 = (*qfn1(fn))(fn, v_33108);
    env = stack[-4];
    v_33108 = ncons(v_33108);
    env = stack[-4];
    goto v_33097;
v_33098:
    goto v_33094;
v_33095:
    goto v_33096;
v_33097:
    v_33108 = Lrplacd(nil, stack[0], v_33108);
    env = stack[-4];
    v_33108 = stack[-1];
    v_33108 = qcdr(v_33108);
    stack[-1] = v_33108;
    goto v_33071;
v_33070:
    return onevalue(v_33108);
}



// Code for all_defined

static LispObject CC_all_defined(LispObject env,
                         LispObject v_33046, LispObject v_33047)
{
    env = qenv(env);
    LispObject v_33065, v_33066;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33047,v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33046,v_33047);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33047;
    v_33065 = v_33046;
// end of prologue
    goto v_33054;
v_33050:
    stack[-1] = v_33065;
    goto v_33051;
v_33052:
    goto v_33061;
v_33057:
    fn = elt(env, 1); // map__edges
    v_33066 = (*qfn1(fn))(fn, v_33065);
    env = stack[-2];
    goto v_33058;
v_33059:
    v_33065 = stack[0];
    goto v_33060;
v_33061:
    goto v_33057;
v_33058:
    goto v_33059;
v_33060:
    fn = elt(env, 2); // defined_append
    v_33065 = (*qfn2(fn))(fn, v_33066, v_33065);
    env = stack[-2];
    goto v_33053;
v_33054:
    goto v_33050;
v_33051:
    goto v_33052;
v_33053:
    {
        LispObject v_33069 = stack[-1];
        fn = elt(env, 3); // all_defined_map_
        return (*qfn2(fn))(fn, v_33069, v_33065);
    }
}



// Code for simprd

static LispObject CC_simprd(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33060, v_33061;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_33061 = v_33046;
// end of prologue
    v_33060 = v_33061;
    if (!consp(v_33060)) goto v_33050;
    else goto v_33051;
v_33050:
    v_33060 = nil;
    goto v_33049;
v_33051:
    v_33060 = elt(env, 1); // !:rd!:
// Binding dmode!*
// FLUIDBIND: reloadenv=1 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 2, 0);
    qvalue(elt(env, 2)) = v_33060; // dmode!*
    v_33060 = v_33061;
    fn = elt(env, 3); // simplist
    v_33060 = (*qfn1(fn))(fn, v_33060);
    ;}  // end of a binding scope
    goto v_33049;
    v_33060 = nil;
v_33049:
    return onevalue(v_33060);
}



// Code for gak

static LispObject CC_gak(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33144, v_33145, v_33146, v_33147, v_33148;
    LispObject fn;
    LispObject v_33048, v_33047, v_33046;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "gak");
    va_start(aa, nargs);
    v_33046 = va_arg(aa, LispObject);
    v_33047 = va_arg(aa, LispObject);
    v_33048 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_33048,v_33047,v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_33046,v_33047,v_33048);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_33145 = v_33048;
    v_33146 = v_33047;
    v_33147 = v_33046;
// end of prologue
v_33045:
    v_33144 = v_33147;
    if (!consp(v_33144)) goto v_33056;
    else goto v_33057;
v_33056:
    v_33144 = lisp_true;
    goto v_33055;
v_33057:
    v_33144 = v_33147;
    v_33144 = qcar(v_33144);
    v_33144 = (consp(v_33144) ? nil : lisp_true);
    goto v_33055;
    v_33144 = nil;
v_33055:
    if (v_33144 == nil) goto v_33053;
    v_33144 = v_33145;
    goto v_33051;
v_33053:
    v_33144 = v_33147;
    v_33144 = qcar(v_33144);
    v_33144 = qcar(v_33144);
    v_33144 = qcar(v_33144);
    v_33148 = v_33144;
    goto v_33080;
v_33074:
    v_33144 = v_33147;
    stack[-3] = qcdr(v_33144);
    goto v_33075;
v_33076:
    stack[-2] = v_33146;
    goto v_33077;
v_33078:
    goto v_33091;
v_33085:
    v_33144 = v_33147;
    v_33144 = qcar(v_33144);
    stack[-1] = qcdr(v_33144);
    goto v_33086;
v_33087:
    stack[0] = v_33146;
    goto v_33088;
v_33089:
    v_33144 = v_33148;
    if (!consp(v_33144)) goto v_33103;
    goto v_33113;
v_33109:
    v_33144 = v_33148;
    v_33144 = qcar(v_33144);
    goto v_33110;
v_33111:
    goto v_33112;
v_33113:
    goto v_33109;
v_33110:
    goto v_33111;
v_33112:
    v_33144 = Lmember(nil, v_33144, v_33146);
    if (v_33144 == nil) goto v_33107;
    else goto v_33108;
v_33107:
    v_33144 = nil;
    goto v_33106;
v_33108:
    goto v_33125;
v_33121:
    v_33146 = v_33148;
    goto v_33122;
v_33123:
    v_33144 = v_33145;
    goto v_33124;
v_33125:
    goto v_33121;
v_33122:
    goto v_33123;
v_33124:
    v_33144 = Lmember(nil, v_33146, v_33144);
    v_33144 = (v_33144 == nil ? lisp_true : nil);
    goto v_33106;
    v_33144 = nil;
v_33106:
    goto v_33101;
v_33103:
    v_33144 = nil;
    goto v_33101;
    v_33144 = nil;
v_33101:
    if (v_33144 == nil) goto v_33099;
    goto v_33138;
v_33134:
    v_33144 = v_33145;
    goto v_33135;
v_33136:
    v_33145 = v_33148;
    goto v_33137;
v_33138:
    goto v_33134;
v_33135:
    goto v_33136;
v_33137:
    fn = elt(env, 1); // aconc
    v_33144 = (*qfn2(fn))(fn, v_33144, v_33145);
    env = stack[-4];
    goto v_33097;
v_33099:
    v_33144 = v_33145;
    goto v_33097;
    v_33144 = nil;
v_33097:
    goto v_33090;
v_33091:
    goto v_33085;
v_33086:
    goto v_33087;
v_33088:
    goto v_33089;
v_33090:
    v_33144 = CC_gak(elt(env, 0), 3, stack[-1], stack[0], v_33144);
    env = stack[-4];
    goto v_33079;
v_33080:
    goto v_33074;
v_33075:
    goto v_33076;
v_33077:
    goto v_33078;
v_33079:
    v_33147 = stack[-3];
    v_33146 = stack[-2];
    v_33145 = v_33144;
    goto v_33045;
    v_33144 = nil;
v_33051:
    return onevalue(v_33144);
}



// Code for constant_expr_listp

static LispObject CC_constant_expr_listp(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33116, v_33117;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_33046;
// end of prologue
v_33051:
    v_33116 = stack[0];
    if (!consp(v_33116)) goto v_33054;
    else goto v_33055;
v_33054:
    v_33116 = stack[0];
    v_33116 = (v_33116 == nil ? lisp_true : nil);
    v_33117 = v_33116;
    if (v_33116 == nil) goto v_33060;
    v_33116 = v_33117;
    goto v_33050;
v_33060:
    v_33116 = stack[0];
    v_33116 = (is_number(v_33116) ? lisp_true : nil);
    v_33117 = v_33116;
    if (v_33116 == nil) goto v_33065;
    v_33116 = v_33117;
    goto v_33050;
v_33065:
    goto v_33076;
v_33072:
    v_33117 = stack[0];
    goto v_33073;
v_33074:
    v_33116 = elt(env, 1); // constant
    goto v_33075;
v_33076:
    goto v_33072;
v_33073:
    goto v_33074;
v_33075:
    v_33116 = Lflagp(nil, v_33117, v_33116);
    env = stack[-1];
    v_33117 = v_33116;
    if (v_33116 == nil) goto v_33070;
    v_33116 = v_33117;
    goto v_33050;
v_33070:
    goto v_33090;
v_33086:
    v_33117 = stack[0];
    goto v_33087;
v_33088:
    v_33116 = elt(env, 2); // i
    goto v_33089;
v_33090:
    goto v_33086;
v_33087:
    goto v_33088;
v_33089:
    if (v_33117 == v_33116) goto v_33084;
    else goto v_33085;
v_33084:
    v_33116 = elt(env, 2); // i
    if (!symbolp(v_33116)) v_33116 = nil;
    else { v_33116 = qfastgets(v_33116);
           if (v_33116 != nil) { v_33116 = elt(v_33116, 56); // idvalfn
#ifdef RECORD_GET
             if (v_33116 != SPID_NOPROP)
                record_get(elt(fastget_names, 56), 1);
             else record_get(elt(fastget_names, 56), 0),
                v_33116 = nil; }
           else record_get(elt(fastget_names, 56), 0); }
#else
             if (v_33116 == SPID_NOPROP) v_33116 = nil; }}
#endif
    goto v_33083;
v_33085:
    v_33116 = nil;
    goto v_33083;
    v_33116 = nil;
v_33083:
    v_33117 = v_33116;
    if (v_33116 == nil) goto v_33081;
    v_33116 = v_33117;
    goto v_33050;
v_33081:
    v_33116 = nil;
    goto v_33050;
    goto v_33053;
v_33055:
    v_33116 = stack[0];
    v_33116 = qcar(v_33116);
    fn = elt(env, 3); // constant_exprp
    v_33116 = (*qfn1(fn))(fn, v_33116);
    env = stack[-1];
    if (v_33116 == nil) goto v_33107;
    v_33116 = stack[0];
    v_33116 = qcdr(v_33116);
    stack[0] = v_33116;
    goto v_33051;
v_33107:
    v_33116 = nil;
    goto v_33050;
    goto v_33053;
v_33053:
    v_33116 = nil;
v_33050:
    return onevalue(v_33116);
}



// Code for talp_nextt

static LispObject CC_talp_nextt(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33332, v_33333, v_33334, v_33335, v_33336, v_33337, v_33338, v_33339;
    LispObject fn;
    LispObject v_33048, v_33047, v_33046;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_nextt");
    va_start(aa, nargs);
    v_33046 = va_arg(aa, LispObject);
    v_33047 = va_arg(aa, LispObject);
    v_33048 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_33048,v_33047,v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_33046,v_33047,v_33048);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-6] = v_33048;
    stack[-7] = v_33047;
    stack[-8] = v_33046;
// end of prologue
    stack[-9] = nil;
    fn = elt(env, 1); // talp_getl
    v_33332 = (*qfnn(fn))(fn, 0);
    env = stack[-10];
    stack[-3] = v_33332;
v_33063:
    v_33332 = stack[-3];
    if (v_33332 == nil) goto v_33068;
    else goto v_33069;
v_33068:
    v_33332 = nil;
    goto v_33062;
v_33069:
    v_33332 = stack[-3];
    v_33332 = qcar(v_33332);
    v_33334 = v_33332;
    goto v_33083;
v_33079:
    v_33332 = v_33334;
    v_33333 = qcdr(v_33332);
    goto v_33080;
v_33081:
    v_33332 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33082;
v_33083:
    goto v_33079;
v_33080:
    goto v_33081;
v_33082:
    if (v_33333 == v_33332) goto v_33077;
    else goto v_33078;
v_33077:
    goto v_33092;
v_33088:
    v_33332 = v_33334;
    v_33333 = qcar(v_33332);
    goto v_33089;
v_33090:
    v_33332 = stack[-9];
    goto v_33091;
v_33092:
    goto v_33088;
v_33089:
    goto v_33090;
v_33091:
    v_33332 = cons(v_33333, v_33332);
    env = stack[-10];
    stack[-9] = v_33332;
    v_33332 = nil;
    goto v_33076;
v_33078:
    goto v_33104;
v_33100:
    v_33332 = stack[-6];
    goto v_33101;
v_33102:
    v_33333 = v_33334;
    goto v_33103;
v_33104:
    goto v_33100;
v_33101:
    goto v_33102;
v_33103:
    fn = elt(env, 2); // talp_mk!-invs
    v_33332 = (*qfn2(fn))(fn, v_33332, v_33333);
    env = stack[-10];
    goto v_33076;
    v_33332 = nil;
v_33076:
    stack[-2] = v_33332;
    v_33332 = stack[-2];
    fn = elt(env, 3); // lastpair
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-10];
    stack[-1] = v_33332;
    v_33332 = stack[-3];
    v_33332 = qcdr(v_33332);
    stack[-3] = v_33332;
    v_33332 = stack[-1];
    if (!consp(v_33332)) goto v_33113;
    else goto v_33114;
v_33113:
    goto v_33063;
v_33114:
v_33064:
    v_33332 = stack[-3];
    if (v_33332 == nil) goto v_33118;
    else goto v_33119;
v_33118:
    v_33332 = stack[-2];
    goto v_33062;
v_33119:
    goto v_33127;
v_33123:
    stack[0] = stack[-1];
    goto v_33124;
v_33125:
    v_33332 = stack[-3];
    v_33332 = qcar(v_33332);
    v_33334 = v_33332;
    goto v_33140;
v_33136:
    v_33332 = v_33334;
    v_33333 = qcdr(v_33332);
    goto v_33137;
v_33138:
    v_33332 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33139;
v_33140:
    goto v_33136;
v_33137:
    goto v_33138;
v_33139:
    if (v_33333 == v_33332) goto v_33134;
    else goto v_33135;
v_33134:
    goto v_33149;
v_33145:
    v_33332 = v_33334;
    v_33333 = qcar(v_33332);
    goto v_33146;
v_33147:
    v_33332 = stack[-9];
    goto v_33148;
v_33149:
    goto v_33145;
v_33146:
    goto v_33147;
v_33148:
    v_33332 = cons(v_33333, v_33332);
    env = stack[-10];
    stack[-9] = v_33332;
    v_33332 = nil;
    goto v_33133;
v_33135:
    goto v_33161;
v_33157:
    v_33332 = stack[-6];
    goto v_33158;
v_33159:
    v_33333 = v_33334;
    goto v_33160;
v_33161:
    goto v_33157;
v_33158:
    goto v_33159;
v_33160:
    fn = elt(env, 2); // talp_mk!-invs
    v_33332 = (*qfn2(fn))(fn, v_33332, v_33333);
    env = stack[-10];
    goto v_33133;
    v_33332 = nil;
v_33133:
    goto v_33126;
v_33127:
    goto v_33123;
v_33124:
    goto v_33125;
v_33126:
    v_33332 = Lrplacd(nil, stack[0], v_33332);
    env = stack[-10];
    v_33332 = stack[-1];
    fn = elt(env, 3); // lastpair
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-10];
    stack[-1] = v_33332;
    v_33332 = stack[-3];
    v_33332 = qcdr(v_33332);
    stack[-3] = v_33332;
    goto v_33064;
v_33062:
    fn = elt(env, 4); // talp_list2vec
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-10];
    stack[-5] = v_33332;
    v_33332 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_33332;
v_33174:
    goto v_33187;
v_33183:
    v_33332 = stack[-5];
    v_33333 = Lupbv(nil, v_33332);
    env = stack[-10];
    goto v_33184;
v_33185:
    v_33332 = stack[-4];
    goto v_33186;
v_33187:
    goto v_33183;
v_33184:
    goto v_33185;
v_33186:
    v_33332 = difference2(v_33333, v_33332);
    env = stack[-10];
    v_33332 = Lminusp(nil, v_33332);
    env = stack[-10];
    if (v_33332 == nil) goto v_33180;
    v_33332 = nil;
    goto v_33173;
v_33180:
    goto v_33196;
v_33192:
    v_33333 = stack[-5];
    goto v_33193;
v_33194:
    v_33332 = stack[-4];
    goto v_33195;
v_33196:
    goto v_33192;
v_33193:
    goto v_33194;
v_33195:
    v_33332 = *(LispObject *)((char *)v_33333 + (CELL-TAG_VECTOR) + (((intptr_t)v_33332-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_33332;
    v_33332 = stack[0];
    fn = elt(env, 5); // talp_invp
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-10];
    if (v_33332 == nil) goto v_33204;
    v_33332 = stack[0];
    v_33332 = ncons(v_33332);
    env = stack[-10];
    goto v_33202;
v_33204:
    v_33332 = nil;
v_33202:
    stack[-3] = v_33332;
    v_33332 = stack[-3];
    fn = elt(env, 3); // lastpair
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-10];
    stack[-2] = v_33332;
    v_33332 = stack[-4];
    v_33332 = add1(v_33332);
    env = stack[-10];
    stack[-4] = v_33332;
    v_33332 = stack[-2];
    if (!consp(v_33332)) goto v_33215;
    else goto v_33216;
v_33215:
    goto v_33174;
v_33216:
v_33175:
    goto v_33228;
v_33224:
    v_33332 = stack[-5];
    v_33333 = Lupbv(nil, v_33332);
    env = stack[-10];
    goto v_33225;
v_33226:
    v_33332 = stack[-4];
    goto v_33227;
v_33228:
    goto v_33224;
v_33225:
    goto v_33226;
v_33227:
    v_33332 = difference2(v_33333, v_33332);
    env = stack[-10];
    v_33332 = Lminusp(nil, v_33332);
    env = stack[-10];
    if (v_33332 == nil) goto v_33221;
    v_33332 = stack[-3];
    goto v_33173;
v_33221:
    goto v_33238;
v_33234:
    stack[-1] = stack[-2];
    goto v_33235;
v_33236:
    goto v_33244;
v_33240:
    v_33333 = stack[-5];
    goto v_33241;
v_33242:
    v_33332 = stack[-4];
    goto v_33243;
v_33244:
    goto v_33240;
v_33241:
    goto v_33242;
v_33243:
    v_33332 = *(LispObject *)((char *)v_33333 + (CELL-TAG_VECTOR) + (((intptr_t)v_33332-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_33332;
    v_33332 = stack[0];
    fn = elt(env, 5); // talp_invp
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-10];
    if (v_33332 == nil) goto v_33252;
    v_33332 = stack[0];
    v_33332 = ncons(v_33332);
    env = stack[-10];
    goto v_33250;
v_33252:
    v_33332 = nil;
v_33250:
    goto v_33237;
v_33238:
    goto v_33234;
v_33235:
    goto v_33236;
v_33237:
    v_33332 = Lrplacd(nil, stack[-1], v_33332);
    env = stack[-10];
    v_33332 = stack[-2];
    fn = elt(env, 3); // lastpair
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-10];
    stack[-2] = v_33332;
    v_33332 = stack[-4];
    v_33332 = add1(v_33332);
    env = stack[-10];
    stack[-4] = v_33332;
    goto v_33175;
v_33173:
    fn = elt(env, 4); // talp_list2vec
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-10];
    stack[0] = v_33332;
    goto v_33267;
v_33263:
    v_33332 = stack[-9];
    v_33333 = Lnreverse(nil, v_33332);
    env = stack[-10];
    goto v_33264;
v_33265:
    v_33332 = stack[-6];
    goto v_33266;
v_33267:
    goto v_33263;
v_33264:
    goto v_33265;
v_33266:
    v_33332 = Lnconc(nil, v_33333, v_33332);
    env = stack[-10];
    fn = elt(env, 4); // talp_list2vec
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-10];
    stack[-1] = v_33332;
    v_33332 = stack[-6];
    fn = elt(env, 4); // talp_list2vec
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-10];
    v_33333 = stack[-8];
    if (v_33333 == nil) goto v_33276;
    goto v_33295;
v_33279:
    v_33339 = stack[-8];
    goto v_33280;
v_33281:
    v_33338 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33282;
v_33283:
    v_33337 = stack[-7];
    goto v_33284;
v_33285:
    v_33336 = stack[-1];
    goto v_33286;
v_33287:
    v_33335 = v_33332;
    goto v_33288;
v_33289:
    v_33334 = stack[-5];
    goto v_33290;
v_33291:
    v_33333 = stack[0];
    goto v_33292;
v_33293:
    v_33332 = nil;
    goto v_33294;
v_33295:
    goto v_33279;
v_33280:
    goto v_33281;
v_33282:
    goto v_33283;
v_33284:
    goto v_33285;
v_33286:
    goto v_33287;
v_33288:
    goto v_33289;
v_33290:
    goto v_33291;
v_33292:
    goto v_33293;
v_33294:
    fn = elt(env, 6); // talp_nextt1
    v_33332 = (*qfnn(fn))(fn, 8, v_33339, v_33338, v_33337, v_33336, v_33335, v_33334, v_33333, v_33332);
    v_33333 = v_33332;
    v_33332 = v_33333;
    v_33332 = qcar(v_33332);
    if (v_33332 == nil) goto v_33308;
    v_33332 = v_33333;
    v_33332 = qcdr(v_33332);
    goto v_33306;
v_33308:
    v_33332 = nil;
v_33306:
    goto v_33274;
v_33276:
    goto v_33320;
v_33316:
    v_33332 = stack[-1];
    v_33333 = Lupbv(nil, v_33332);
    env = stack[-10];
    goto v_33317;
v_33318:
    v_33332 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_33319;
v_33320:
    goto v_33316;
v_33317:
    goto v_33318;
v_33319:
    v_33332 = (LispObject)greaterp2(v_33333, v_33332);
    v_33332 = v_33332 ? lisp_true : nil;
    if (v_33332 == nil) goto v_33314;
    goto v_33328;
v_33324:
    v_33333 = stack[-1];
    goto v_33325;
v_33326:
    v_33332 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33327;
v_33328:
    goto v_33324;
v_33325:
    goto v_33326;
v_33327:
    v_33332 = *(LispObject *)((char *)v_33333 + (CELL-TAG_VECTOR) + (((intptr_t)v_33332-TAG_FIXNUM)/(16/CELL)));
    goto v_33274;
v_33314:
    v_33332 = nil;
v_33274:
    return onevalue(v_33332);
}



// Code for ofsf_factsf

static LispObject CC_ofsf_factsf(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33102, v_33103;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33046;
// end of prologue
    stack[-1] = nil;
v_33052:
    goto v_33064;
v_33060:
    v_33103 = stack[0];
    goto v_33061;
v_33062:
    v_33102 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33063;
v_33064:
    goto v_33060;
v_33061:
    goto v_33062;
v_33063:
    v_33102 = (LispObject)lesseq2(v_33103, v_33102);
    v_33102 = v_33102 ? lisp_true : nil;
    env = stack[-2];
    if (v_33102 == nil) goto v_33058;
    goto v_33053;
v_33058:
    goto v_33072;
v_33068:
    v_33103 = stack[0];
    goto v_33069;
v_33070:
    v_33102 = stack[-1];
    goto v_33071;
v_33072:
    goto v_33068;
v_33069:
    goto v_33070;
v_33071:
    v_33102 = cons(v_33103, v_33102);
    env = stack[-2];
    stack[-1] = v_33102;
    goto v_33080;
v_33076:
    goto v_33077;
v_33078:
    v_33102 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 1); // negf
    v_33102 = (*qfn1(fn))(fn, v_33102);
    env = stack[-2];
    goto v_33079;
v_33080:
    goto v_33076;
v_33077:
    goto v_33078;
v_33079:
    fn = elt(env, 2); // addf
    v_33102 = (*qfn2(fn))(fn, stack[0], v_33102);
    env = stack[-2];
    stack[0] = v_33102;
    goto v_33052;
v_33053:
    v_33102 = (LispObject)16+TAG_FIXNUM; // 1
    v_33103 = v_33102;
v_33054:
    v_33102 = stack[-1];
    if (v_33102 == nil) goto v_33087;
    else goto v_33088;
v_33087:
    v_33102 = v_33103;
    goto v_33051;
v_33088:
    goto v_33096;
v_33092:
    v_33102 = stack[-1];
    v_33102 = qcar(v_33102);
    goto v_33093;
v_33094:
    goto v_33095;
v_33096:
    goto v_33092;
v_33093:
    goto v_33094;
v_33095:
    fn = elt(env, 3); // multf
    v_33102 = (*qfn2(fn))(fn, v_33102, v_33103);
    env = stack[-2];
    v_33103 = v_33102;
    v_33102 = stack[-1];
    v_33102 = qcdr(v_33102);
    stack[-1] = v_33102;
    goto v_33054;
v_33051:
    return onevalue(v_33102);
}



// Code for dip_comp1

static LispObject CC_dip_comp1(LispObject env,
                         LispObject v_33046, LispObject v_33047)
{
    env = qenv(env);
    LispObject v_33059;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33047,v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33046,v_33047);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33047;
    v_33059 = v_33046;
// end of prologue
    goto v_33054;
v_33050:
    fn = elt(env, 1); // dip_evlmon
    stack[-1] = (*qfn1(fn))(fn, v_33059);
    env = stack[-2];
    goto v_33051;
v_33052:
    v_33059 = stack[0];
    fn = elt(env, 1); // dip_evlmon
    v_33059 = (*qfn1(fn))(fn, v_33059);
    env = stack[-2];
    goto v_33053;
v_33054:
    goto v_33050;
v_33051:
    goto v_33052;
v_33053:
    {
        LispObject v_33062 = stack[-1];
        fn = elt(env, 2); // ev_comp
        return (*qfn2(fn))(fn, v_33062, v_33059);
    }
}



// Code for tidysqrt

static LispObject CC_tidysqrt(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33080, v_33081;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33046;
// end of prologue
    v_33080 = stack[0];
    v_33080 = qcar(v_33080);
    fn = elt(env, 1); // tidysqrtf
    v_33080 = (*qfn1(fn))(fn, v_33080);
    env = stack[-2];
    stack[-1] = v_33080;
    v_33080 = stack[-1];
    if (v_33080 == nil) goto v_33057;
    else goto v_33058;
v_33057:
    goto v_33065;
v_33061:
    v_33081 = nil;
    goto v_33062;
v_33063:
    v_33080 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33064;
v_33065:
    goto v_33061;
v_33062:
    goto v_33063;
v_33064:
    return cons(v_33081, v_33080);
v_33058:
    v_33080 = stack[0];
    v_33080 = qcdr(v_33080);
    fn = elt(env, 1); // tidysqrtf
    v_33080 = (*qfn1(fn))(fn, v_33080);
    env = stack[-2];
    goto v_33076;
v_33072:
    stack[0] = stack[-1];
    goto v_33073;
v_33074:
    fn = elt(env, 2); // invsq
    v_33080 = (*qfn1(fn))(fn, v_33080);
    env = stack[-2];
    goto v_33075;
v_33076:
    goto v_33072;
v_33073:
    goto v_33074;
v_33075:
    {
        LispObject v_33084 = stack[0];
        fn = elt(env, 3); // multsq
        return (*qfn2(fn))(fn, v_33084, v_33080);
    }
    return onevalue(v_33080);
}



// Code for expttermp

static LispObject CC_expttermp(LispObject env,
                         LispObject v_33046, LispObject v_33047)
{
    env = qenv(env);
    LispObject v_33081, v_33082, v_33083, v_33084;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33083 = v_33047;
    v_33084 = v_33046;
// end of prologue
    goto v_33058;
v_33054:
    v_33082 = v_33084;
    goto v_33055;
v_33056:
    v_33081 = elt(env, 1); // expt
    goto v_33057;
v_33058:
    goto v_33054;
v_33055:
    goto v_33056;
v_33057:
    if (!consp(v_33082)) goto v_33052;
    v_33082 = qcar(v_33082);
    if (v_33082 == v_33081) goto v_33051;
    else goto v_33052;
v_33051:
    goto v_33066;
v_33062:
    v_33081 = v_33084;
    v_33081 = qcdr(v_33081);
    v_33081 = qcar(v_33081);
    goto v_33063;
v_33064:
    v_33082 = v_33083;
    goto v_33065;
v_33066:
    goto v_33062;
v_33063:
    goto v_33064;
v_33065:
    {
        fn = elt(env, 2); // expttermp1
        return (*qfn2(fn))(fn, v_33081, v_33082);
    }
v_33052:
    goto v_33078;
v_33074:
    v_33081 = v_33084;
    goto v_33075;
v_33076:
    v_33082 = v_33083;
    goto v_33077;
v_33078:
    goto v_33074;
v_33075:
    goto v_33076;
v_33077:
    {
        fn = elt(env, 2); // expttermp1
        return (*qfn2(fn))(fn, v_33081, v_33082);
    }
    v_33081 = nil;
    return onevalue(v_33081);
}



// Code for xriterion_2

static LispObject CC_xriterion_2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33190, v_33191, v_33192;
    LispObject fn;
    LispObject v_33048, v_33047, v_33046;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xriterion_2");
    va_start(aa, nargs);
    v_33046 = va_arg(aa, LispObject);
    v_33047 = va_arg(aa, LispObject);
    v_33048 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_33048,v_33047,v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_33046,v_33047,v_33048);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_33048;
    stack[-1] = v_33047;
    stack[-2] = v_33046;
// end of prologue
v_33045:
    v_33190 = stack[-1];
    if (v_33190 == nil) goto v_33052;
    else goto v_33053;
v_33052:
    v_33190 = nil;
    goto v_33051;
v_33053:
    goto v_33062;
v_33058:
    v_33190 = stack[-2];
    v_33190 = qcdr(v_33190);
    v_33191 = qcar(v_33190);
    goto v_33059;
v_33060:
    v_33190 = elt(env, 1); // wedge_pair
    goto v_33061;
v_33062:
    goto v_33058;
v_33059:
    goto v_33060;
v_33061:
    if (v_33191 == v_33190) goto v_33057;
    v_33190 = nil;
    goto v_33051;
v_33057:
    v_33190 = stack[-1];
    v_33190 = qcar(v_33190);
    stack[-3] = v_33190;
    goto v_33084;
v_33080:
    goto v_33093;
v_33087:
    v_33192 = stack[-3];
    goto v_33088;
v_33089:
    v_33191 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33090;
v_33091:
    v_33190 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33092;
v_33093:
    goto v_33087;
v_33088:
    goto v_33089;
v_33090:
    goto v_33091;
v_33092:
    v_33190 = list2star(v_33192, v_33191, v_33190);
    env = stack[-4];
    v_33191 = ncons(v_33190);
    env = stack[-4];
    goto v_33081;
v_33082:
    v_33190 = stack[-2];
    v_33190 = qcdr(v_33190);
    v_33190 = qcdr(v_33190);
    v_33190 = qcar(v_33190);
    goto v_33083;
v_33084:
    goto v_33080;
v_33081:
    goto v_33082;
v_33083:
    if (equal(v_33191, v_33190)) goto v_33079;
    goto v_33110;
v_33106:
    goto v_33116;
v_33112:
    v_33191 = stack[-3];
    goto v_33113;
v_33114:
    v_33190 = stack[-3];
    goto v_33115;
v_33116:
    goto v_33112;
v_33113:
    goto v_33114;
v_33115:
    v_33191 = list2(v_33191, v_33190);
    env = stack[-4];
    goto v_33107;
v_33108:
    v_33190 = stack[-2];
    v_33190 = qcar(v_33190);
    goto v_33109;
v_33110:
    goto v_33106;
v_33107:
    goto v_33108;
v_33109:
    fn = elt(env, 5); // xdiv
    v_33190 = (*qfn2(fn))(fn, v_33191, v_33190);
    env = stack[-4];
    if (v_33190 == nil) goto v_33103;
    else goto v_33104;
v_33103:
    v_33190 = nil;
    goto v_33102;
v_33104:
    goto v_33133;
v_33129:
    v_33191 = stack[-3];
    goto v_33130;
v_33131:
    v_33190 = stack[-2];
    v_33190 = qcdr(v_33190);
    v_33190 = qcdr(v_33190);
    v_33190 = qcdr(v_33190);
    v_33190 = qcar(v_33190);
    goto v_33132;
v_33133:
    goto v_33129;
v_33130:
    goto v_33131;
v_33132:
    fn = elt(env, 6); // make_wedge_pair
    v_33190 = (*qfn2(fn))(fn, v_33191, v_33190);
    env = stack[-4];
    v_33191 = v_33190;
    v_33190 = v_33191;
    if (v_33190 == nil) goto v_33143;
    else goto v_33144;
v_33143:
    v_33190 = lisp_true;
    goto v_33142;
v_33144:
    goto v_33154;
v_33150:
    goto v_33151;
v_33152:
    v_33190 = stack[0];
    goto v_33153;
v_33154:
    goto v_33150;
v_33151:
    goto v_33152;
v_33153:
    fn = elt(env, 7); // find_item
    v_33190 = (*qfn2(fn))(fn, v_33191, v_33190);
    env = stack[-4];
    v_33190 = (v_33190 == nil ? lisp_true : nil);
    goto v_33142;
    v_33190 = nil;
v_33142:
    if (v_33190 == nil) goto v_33126;
    else goto v_33127;
v_33126:
    v_33190 = nil;
    goto v_33125;
v_33127:
    v_33190 = qvalue(elt(env, 2)); // !*trxideal
    if (v_33190 == nil) goto v_33164;
    goto v_33171;
v_33167:
    v_33191 = elt(env, 3); // "criterion 2 hit"
    goto v_33168;
v_33169:
    v_33190 = elt(env, 4); // last
    goto v_33170;
v_33171:
    goto v_33167;
v_33168:
    goto v_33169;
v_33170:
    fn = elt(env, 8); // writepri
    v_33190 = (*qfn2(fn))(fn, v_33191, v_33190);
    env = stack[-4];
    goto v_33162;
v_33164:
v_33162:
    v_33190 = lisp_true;
    goto v_33125;
    v_33190 = nil;
v_33125:
    goto v_33102;
    v_33190 = nil;
v_33102:
    goto v_33077;
v_33079:
    v_33190 = nil;
    goto v_33077;
    v_33190 = nil;
v_33077:
    if (v_33190 == nil) goto v_33075;
    else goto v_33074;
v_33075:
    goto v_33185;
v_33179:
    v_33192 = stack[-2];
    goto v_33180;
v_33181:
    v_33190 = stack[-1];
    v_33191 = qcdr(v_33190);
    goto v_33182;
v_33183:
    v_33190 = stack[0];
    goto v_33184;
v_33185:
    goto v_33179;
v_33180:
    goto v_33181;
v_33182:
    goto v_33183;
v_33184:
    stack[-2] = v_33192;
    stack[-1] = v_33191;
    stack[0] = v_33190;
    goto v_33045;
v_33074:
    goto v_33051;
    v_33190 = nil;
v_33051:
    return onevalue(v_33190);
}



// Code for evalsubset

static LispObject CC_evalsubset(LispObject env,
                         LispObject v_33046, LispObject v_33047)
{
    env = qenv(env);
    LispObject v_33071, v_33072, v_33073;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33047,v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33046,v_33047);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33071 = v_33047;
    v_33072 = v_33046;
// end of prologue
    goto v_33056;
v_33050:
    v_33073 = elt(env, 1); // subset
    goto v_33051;
v_33052:
    goto v_33053;
v_33054:
    goto v_33055;
v_33056:
    goto v_33050;
v_33051:
    goto v_33052;
v_33053:
    goto v_33054;
v_33055:
    fn = elt(env, 2); // evalsetbool
    v_33071 = (*qfnn(fn))(fn, 3, v_33073, v_33072, v_33071);
    env = stack[0];
    v_33072 = v_33071;
    v_33071 = v_33072;
    if (!consp(v_33071)) goto v_33063;
    else goto v_33064;
v_33063:
    v_33071 = v_33072;
    goto v_33062;
v_33064:
    v_33071 = v_33072;
    {
        fn = elt(env, 3); // evalsymsubset
        return (*qfn1(fn))(fn, v_33071);
    }
    v_33071 = nil;
v_33062:
    return onevalue(v_33071);
}



// Code for preproc

static LispObject CC_preproc(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33063, v_33064;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
// copy arguments values to proper place
    v_33063 = v_33046;
// end of prologue
    fn = elt(env, 1); // preproc1
    v_33063 = (*qfn1(fn))(fn, v_33063);
    v_33064 = v_33063;
    v_33063 = v_33064;
    if (v_33063 == nil) goto v_33056;
    v_33063 = v_33064;
    v_33063 = qcar(v_33063);
    goto v_33050;
v_33056:
    v_33063 = v_33064;
    goto v_33050;
    v_33063 = nil;
v_33050:
    return onevalue(v_33063);
}



// Code for dvertex!-to!-projector

static LispObject CC_dvertexKtoKprojector(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33137, v_33138, v_33139;
    LispObject fn;
    LispObject v_33048, v_33047, v_33046;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dvertex-to-projector");
    va_start(aa, nargs);
    v_33046 = va_arg(aa, LispObject);
    v_33047 = va_arg(aa, LispObject);
    v_33048 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_33048,v_33047,v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_33046,v_33047,v_33048);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_33048;
    stack[-1] = v_33047;
    stack[-2] = v_33046;
// end of prologue
    goto v_33063;
v_33057:
    v_33137 = stack[-2];
    v_33137 = qcdr(v_33137);
    v_33139 = qcar(v_33137);
    goto v_33058;
v_33059:
    v_33138 = stack[-1];
    goto v_33060;
v_33061:
    v_33137 = stack[0];
    goto v_33062;
v_33063:
    goto v_33057;
v_33058:
    goto v_33059;
v_33060:
    goto v_33061;
v_33062:
    fn = elt(env, 1); // mktails
    v_33137 = (*qfnn(fn))(fn, 3, v_33139, v_33138, v_33137);
    env = stack[-4];
    stack[-3] = v_33137;
    v_33137 = stack[-3];
    v_33137 = qcar(v_33137);
    fn = elt(env, 2); // repeatsp
    v_33137 = (*qfn1(fn))(fn, v_33137);
    env = stack[-4];
    if (v_33137 == nil) goto v_33072;
    v_33137 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33055;
v_33072:
    goto v_33084;
v_33078:
    v_33137 = stack[-2];
    v_33137 = qcdr(v_33137);
    v_33137 = qcdr(v_33137);
    v_33139 = qcar(v_33137);
    goto v_33079;
v_33080:
    v_33138 = stack[-1];
    goto v_33081;
v_33082:
    v_33137 = stack[-3];
    v_33137 = qcdr(v_33137);
    goto v_33083;
v_33084:
    goto v_33078;
v_33079:
    goto v_33080;
v_33081:
    goto v_33082;
v_33083:
    fn = elt(env, 1); // mktails
    v_33137 = (*qfnn(fn))(fn, 3, v_33139, v_33138, v_33137);
    env = stack[-4];
    stack[-1] = v_33137;
    v_33137 = stack[-1];
    v_33137 = qcar(v_33137);
    fn = elt(env, 2); // repeatsp
    v_33137 = (*qfn1(fn))(fn, v_33137);
    env = stack[-4];
    if (v_33137 == nil) goto v_33095;
    v_33137 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33055;
v_33095:
    v_33137 = stack[-1];
    v_33137 = qcdr(v_33137);
    stack[0] = v_33137;
    goto v_33107;
v_33103:
    v_33137 = stack[-3];
    stack[-2] = qcar(v_33137);
    goto v_33104;
v_33105:
    v_33137 = stack[-1];
    v_33137 = qcar(v_33137);
    v_33137 = Lreverse(nil, v_33137);
    env = stack[-4];
    goto v_33106;
v_33107:
    goto v_33103;
v_33104:
    goto v_33105;
v_33106:
    fn = elt(env, 3); // prop!-simp
    v_33137 = (*qfn2(fn))(fn, stack[-2], v_33137);
    env = stack[-4];
    stack[-2] = v_33137;
    v_33137 = stack[-2];
    fn = elt(env, 4); // mk!-contract!-coeff
    v_33137 = (*qfn1(fn))(fn, v_33137);
    env = stack[-4];
    goto v_33120;
v_33116:
    stack[-1] = v_33137;
    goto v_33117;
v_33118:
    goto v_33129;
v_33123:
    v_33137 = stack[-2];
    v_33137 = qcdr(v_33137);
    v_33139 = qcar(v_33137);
    goto v_33124;
v_33125:
    v_33137 = stack[-2];
    v_33137 = qcdr(v_33137);
    v_33138 = qcdr(v_33137);
    goto v_33126;
v_33127:
    v_33137 = stack[0];
    goto v_33128;
v_33129:
    goto v_33123;
v_33124:
    goto v_33125;
v_33126:
    goto v_33127;
v_33128:
    fn = elt(env, 5); // dpropagator
    v_33137 = (*qfnn(fn))(fn, 3, v_33139, v_33138, v_33137);
    goto v_33119;
v_33120:
    goto v_33116;
v_33117:
    goto v_33118;
v_33119:
    {
        LispObject v_33144 = stack[-1];
        return cons(v_33144, v_33137);
    }
v_33055:
    return onevalue(v_33137);
}



// Code for red_extract

static LispObject CC_red_extract(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33086, v_33087;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_33046;
// end of prologue
    goto v_33053;
v_33049:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33050;
v_33051:
    v_33086 = stack[-2];
    fn = elt(env, 1); // bas_rep
    v_33086 = (*qfn1(fn))(fn, v_33086);
    env = stack[-4];
    goto v_33052;
v_33053:
    goto v_33049;
v_33050:
    goto v_33051;
v_33052:
    fn = elt(env, 2); // dp_comp
    v_33086 = (*qfn2(fn))(fn, stack[0], v_33086);
    env = stack[-4];
    stack[-3] = v_33086;
    goto v_33063;
v_33059:
    goto v_33071;
v_33065:
    v_33086 = stack[-2];
    fn = elt(env, 3); // bas_nr
    stack[-1] = (*qfn1(fn))(fn, v_33086);
    env = stack[-4];
    goto v_33066;
v_33067:
    v_33086 = stack[-2];
    fn = elt(env, 4); // bas_dpoly
    stack[0] = (*qfn1(fn))(fn, v_33086);
    env = stack[-4];
    goto v_33068;
v_33069:
    goto v_33081;
v_33077:
    v_33086 = stack[-2];
    fn = elt(env, 1); // bas_rep
    v_33087 = (*qfn1(fn))(fn, v_33086);
    env = stack[-4];
    goto v_33078;
v_33079:
    v_33086 = stack[-3];
    goto v_33080;
v_33081:
    goto v_33077;
v_33078:
    goto v_33079;
v_33080:
    fn = elt(env, 5); // dp_diff
    v_33086 = (*qfn2(fn))(fn, v_33087, v_33086);
    env = stack[-4];
    goto v_33070;
v_33071:
    goto v_33065;
v_33066:
    goto v_33067;
v_33068:
    goto v_33069;
v_33070:
    fn = elt(env, 6); // bas_make1
    v_33087 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_33086);
    goto v_33060;
v_33061:
    v_33086 = stack[-3];
    goto v_33062;
v_33063:
    goto v_33059;
v_33060:
    goto v_33061;
v_33062:
    return cons(v_33087, v_33086);
}



// Code for !*hfac

static LispObject CC_Hhfac(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33102, v_33103, v_33104;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_33046;
// end of prologue
    v_33102 = stack[0];
    v_33102 = integerp(v_33102);
    if (v_33102 == nil) goto v_33054;
    else goto v_33055;
v_33054:
    v_33102 = lisp_true;
    goto v_33053;
v_33055:
    goto v_33069;
v_33065:
    v_33103 = stack[0];
    goto v_33066;
v_33067:
    v_33102 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33068;
v_33069:
    goto v_33065;
v_33066:
    goto v_33067;
v_33068:
    v_33102 = (LispObject)lessp2(v_33103, v_33102);
    v_33102 = v_33102 ? lisp_true : nil;
    env = stack[-1];
    if (v_33102 == nil) goto v_33063;
    else goto v_33062;
v_33063:
    goto v_33077;
v_33073:
    v_33103 = stack[0];
    goto v_33074;
v_33075:
    v_33102 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_33076;
v_33077:
    goto v_33073;
v_33074:
    goto v_33075;
v_33076:
    v_33102 = (LispObject)greaterp2(v_33103, v_33102);
    v_33102 = v_33102 ? lisp_true : nil;
    env = stack[-1];
v_33062:
    goto v_33053;
    v_33102 = nil;
v_33053:
    if (v_33102 == nil) goto v_33051;
    goto v_33087;
v_33081:
    v_33104 = elt(env, 1); // avector
    goto v_33082;
v_33083:
    v_33103 = (LispObject)208+TAG_FIXNUM; // 13
    goto v_33084;
v_33085:
    v_33102 = elt(env, 2); // "Invalid index"
    goto v_33086;
v_33087:
    goto v_33081;
v_33082:
    goto v_33083;
v_33084:
    goto v_33085;
v_33086:
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_33104, v_33103, v_33102);
    }
v_33051:
    goto v_33097;
v_33093:
    v_33102 = elt(env, 3); // hfactors
    fn = elt(env, 5); // getavalue
    v_33103 = (*qfn1(fn))(fn, v_33102);
    goto v_33094;
v_33095:
    v_33102 = stack[0];
    goto v_33096;
v_33097:
    goto v_33093;
v_33094:
    goto v_33095;
v_33096:
    v_33102 = *(LispObject *)((char *)v_33103 + (CELL-TAG_VECTOR) + (((intptr_t)v_33102-TAG_FIXNUM)/(16/CELL)));
    goto v_33049;
    v_33102 = nil;
v_33049:
    return onevalue(v_33102);
}



// Code for radd

static LispObject CC_radd(LispObject env,
                         LispObject v_33046, LispObject v_33047)
{
    env = qenv(env);
    LispObject v_33176, v_33177;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33047,v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33046,v_33047);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_33047;
    stack[-1] = v_33046;
// end of prologue
    stack[-2] = nil;
    v_33176 = stack[-1];
    if (!consp(v_33176)) goto v_33057;
    goto v_33064;
v_33060:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33061;
v_33062:
    v_33176 = stack[-1];
    fn = elt(env, 3); // prepf
    v_33176 = (*qfn1(fn))(fn, v_33176);
    goto v_33063;
v_33064:
    goto v_33060;
v_33061:
    goto v_33062;
v_33063:
    {
        LispObject v_33181 = stack[0];
        return list2(v_33181, v_33176);
    }
v_33057:
    goto v_33078;
v_33074:
    v_33177 = stack[-1];
    goto v_33075;
v_33076:
    v_33176 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33077;
v_33078:
    goto v_33074;
v_33075:
    goto v_33076;
v_33077:
    v_33176 = (LispObject)lessp2(v_33177, v_33176);
    v_33176 = v_33176 ? lisp_true : nil;
    env = stack[-3];
    if (v_33176 == nil) goto v_33071;
    v_33176 = stack[0];
    v_33176 = Levenp(nil, v_33176);
    env = stack[-3];
    if (v_33176 == nil) goto v_33071;
    v_33176 = lisp_true;
    stack[-2] = v_33176;
    v_33176 = stack[-1];
    v_33176 = negate(v_33176);
    env = stack[-3];
    stack[-1] = v_33176;
    goto v_33069;
v_33071:
v_33069:
    goto v_33092;
v_33088:
    v_33177 = stack[-1];
    goto v_33089;
v_33090:
    v_33176 = stack[0];
    goto v_33091;
v_33092:
    goto v_33088;
v_33089:
    goto v_33090;
v_33091:
    fn = elt(env, 4); // nrootnn
    v_33176 = (*qfn2(fn))(fn, v_33177, v_33176);
    env = stack[-3];
    stack[-1] = v_33176;
    v_33176 = stack[-2];
    if (v_33176 == nil) goto v_33098;
    v_33176 = qvalue(elt(env, 1)); // !*reduced
    if (v_33176 == nil) goto v_33103;
    goto v_33111;
v_33107:
    v_33177 = stack[0];
    goto v_33108;
v_33109:
    v_33176 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_33110;
v_33111:
    goto v_33107;
v_33108:
    goto v_33109;
v_33110:
    if (v_33177 == v_33176) goto v_33106;
    else goto v_33103;
v_33106:
    goto v_33119;
v_33115:
    v_33176 = stack[-1];
    stack[0] = qcar(v_33176);
    goto v_33116;
v_33117:
    goto v_33128;
v_33124:
    goto v_33134;
v_33130:
    v_33177 = elt(env, 2); // i
    goto v_33131;
v_33132:
    v_33176 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33133;
v_33134:
    goto v_33130;
v_33131:
    goto v_33132;
v_33133:
    fn = elt(env, 5); // to
    v_33177 = (*qfn2(fn))(fn, v_33177, v_33176);
    env = stack[-3];
    goto v_33125;
v_33126:
    v_33176 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33127;
v_33128:
    goto v_33124;
v_33125:
    goto v_33126;
v_33127:
    v_33176 = cons(v_33177, v_33176);
    env = stack[-3];
    v_33176 = ncons(v_33176);
    env = stack[-3];
    goto v_33118;
v_33119:
    goto v_33115;
v_33116:
    goto v_33117;
v_33118:
    fn = elt(env, 6); // multd
    v_33176 = (*qfn2(fn))(fn, stack[0], v_33176);
    stack[0] = v_33176;
    v_33176 = stack[-1];
    v_33176 = qcdr(v_33176);
    stack[-1] = v_33176;
    goto v_33101;
v_33103:
    v_33176 = stack[-1];
    v_33176 = qcar(v_33176);
    stack[0] = v_33176;
    v_33176 = stack[-1];
    v_33176 = qcdr(v_33176);
    v_33176 = negate(v_33176);
    stack[-1] = v_33176;
    goto v_33101;
v_33101:
    goto v_33096;
v_33098:
    v_33176 = stack[-1];
    v_33176 = qcar(v_33176);
    stack[0] = v_33176;
    v_33176 = stack[-1];
    v_33176 = qcdr(v_33176);
    stack[-1] = v_33176;
    goto v_33096;
v_33096:
    goto v_33161;
v_33157:
    v_33177 = stack[-1];
    goto v_33158;
v_33159:
    v_33176 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33160;
v_33161:
    goto v_33157;
v_33158:
    goto v_33159;
v_33160:
    if (v_33177 == v_33176) goto v_33155;
    else goto v_33156;
v_33155:
    v_33176 = stack[0];
    return ncons(v_33176);
v_33156:
    goto v_33173;
v_33169:
    v_33177 = stack[0];
    goto v_33170;
v_33171:
    v_33176 = stack[-1];
    goto v_33172;
v_33173:
    goto v_33169;
v_33170:
    goto v_33171;
v_33172:
    return list2(v_33177, v_33176);
    v_33176 = nil;
    return onevalue(v_33176);
}



// Code for find_active_components

static LispObject CC_find_active_components(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33118, v_33119, v_33120;
    LispObject fn;
    LispObject v_33048, v_33047, v_33046;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "find_active_components");
    va_start(aa, nargs);
    v_33046 = va_arg(aa, LispObject);
    v_33047 = va_arg(aa, LispObject);
    v_33048 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_33048,v_33047,v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_33046,v_33047,v_33048);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_33048;
    stack[-1] = v_33047;
    stack[-2] = v_33046;
// end of prologue
    goto v_33059;
v_33053:
    goto v_33065;
v_33061:
    v_33120 = stack[-2];
    goto v_33062;
v_33063:
    goto v_33071;
v_33067:
    v_33119 = stack[-2];
    goto v_33068;
v_33069:
    v_33118 = qvalue(elt(env, 1)); // depl!*
    goto v_33070;
v_33071:
    goto v_33067;
v_33068:
    goto v_33069;
v_33070:
    v_33118 = Lassoc(nil, v_33119, v_33118);
    v_33119 = v_33118;
    v_33118 = v_33119;
    if (v_33118 == nil) goto v_33079;
    v_33118 = v_33119;
    v_33118 = qcdr(v_33118);
    goto v_33077;
v_33079:
    v_33118 = nil;
v_33077:
    goto v_33064;
v_33065:
    goto v_33061;
v_33062:
    goto v_33063;
v_33064:
    v_33120 = cons(v_33120, v_33118);
    env = stack[-3];
    goto v_33054;
v_33055:
    v_33119 = stack[-1];
    goto v_33056;
v_33057:
    v_33118 = stack[0];
    goto v_33058;
v_33059:
    goto v_33053;
v_33054:
    goto v_33055;
v_33056:
    goto v_33057;
v_33058:
    fn = elt(env, 2); // update_components
    v_33118 = (*qfnn(fn))(fn, 3, v_33120, v_33119, v_33118);
    env = stack[-3];
    stack[0] = v_33118;
    v_33118 = stack[-2];
    if (!consp(v_33118)) goto v_33088;
    v_33118 = stack[-2];
    stack[-2] = v_33118;
v_33093:
    v_33118 = stack[-2];
    if (v_33118 == nil) goto v_33097;
    else goto v_33098;
v_33097:
    goto v_33092;
v_33098:
    v_33118 = stack[-2];
    v_33118 = qcar(v_33118);
    goto v_33111;
v_33105:
    v_33120 = v_33118;
    goto v_33106;
v_33107:
    v_33119 = stack[-1];
    goto v_33108;
v_33109:
    v_33118 = stack[0];
    goto v_33110;
v_33111:
    goto v_33105;
v_33106:
    goto v_33107;
v_33108:
    goto v_33109;
v_33110:
    v_33118 = CC_find_active_components(elt(env, 0), 3, v_33120, v_33119, v_33118);
    env = stack[-3];
    stack[0] = v_33118;
    v_33118 = stack[-2];
    v_33118 = qcdr(v_33118);
    stack[-2] = v_33118;
    goto v_33093;
v_33092:
    goto v_33086;
v_33088:
v_33086:
    v_33118 = stack[0];
    return onevalue(v_33118);
}



// Code for giminusp!:

static LispObject CC_giminuspT(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33071, v_33072, v_33073;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33072 = v_33046;
// end of prologue
    goto v_33056;
v_33052:
    v_33071 = v_33072;
    v_33071 = qcdr(v_33071);
    v_33073 = qcar(v_33071);
    goto v_33053;
v_33054:
    v_33071 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33055;
v_33056:
    goto v_33052;
v_33053:
    goto v_33054;
v_33055:
    if (v_33073 == v_33071) goto v_33050;
    else goto v_33051;
v_33050:
    v_33071 = v_33072;
    v_33071 = qcdr(v_33071);
    v_33071 = qcdr(v_33071);
        return Lminusp(nil, v_33071);
v_33051:
    v_33071 = v_33072;
    v_33071 = qcdr(v_33071);
    v_33071 = qcar(v_33071);
        return Lminusp(nil, v_33071);
    v_33071 = nil;
    return onevalue(v_33071);
}



// Code for opfchk!!

static LispObject CC_opfchkB(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33332, v_33333;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_33046;
// end of prologue
    stack[-3] = nil;
    stack[-2] = nil;
    v_33332 = stack[-6];
    v_33332 = qcar(v_33332);
    stack[-7] = v_33332;
    stack[-5] = v_33332;
    v_33332 = stack[-6];
    v_33332 = qcdr(v_33332);
    stack[-6] = v_33332;
    goto v_33073;
v_33069:
    v_33333 = stack[-7];
    goto v_33070;
v_33071:
    v_33332 = elt(env, 1); // integer
    goto v_33072;
v_33073:
    goto v_33069;
v_33070:
    goto v_33071;
v_33072:
    v_33332 = Lflagp(nil, v_33333, v_33332);
    env = stack[-8];
    if (v_33332 == nil) goto v_33067;
    v_33332 = lisp_true;
    stack[-3] = v_33332;
    goto v_33082;
v_33078:
    v_33333 = stack[-7];
    goto v_33079;
v_33080:
    v_33332 = elt(env, 2); // !:rn!:
    goto v_33081;
v_33082:
    goto v_33078;
v_33079:
    goto v_33080;
v_33081:
    v_33332 = get(v_33333, v_33332);
    env = stack[-8];
    goto v_33065;
v_33067:
    v_33332 = qvalue(elt(env, 3)); // !*numval
    if (v_33332 == nil) goto v_33086;
    goto v_33094;
v_33090:
    v_33333 = qvalue(elt(env, 4)); // dmode!*
    goto v_33091;
v_33092:
    v_33332 = elt(env, 5); // (!:rd!: !:cr!:)
    goto v_33093;
v_33094:
    goto v_33090;
v_33091:
    goto v_33092;
v_33093:
    v_33332 = Lmemq(nil, v_33333, v_33332);
    if (v_33332 == nil) goto v_33086;
    goto v_33103;
v_33099:
    v_33333 = stack[-7];
    goto v_33100;
v_33101:
    v_33332 = elt(env, 6); // !:rd!:
    goto v_33102;
v_33103:
    goto v_33099;
v_33100:
    goto v_33101;
v_33102:
    v_33332 = get(v_33333, v_33332);
    env = stack[-8];
    goto v_33065;
v_33086:
    v_33332 = nil;
v_33065:
    stack[-7] = v_33332;
    v_33332 = stack[-7];
    if (v_33332 == nil) goto v_33108;
    else goto v_33109;
v_33108:
    v_33332 = nil;
    goto v_33055;
v_33109:
    v_33332 = stack[-3];
    if (v_33332 == nil) goto v_33115;
    v_33332 = elt(env, 7); // simprn
    goto v_33113;
v_33115:
    goto v_33125;
v_33121:
    v_33333 = stack[-7];
    goto v_33122;
v_33123:
    v_33332 = elt(env, 8); // simparg
    goto v_33124;
v_33125:
    goto v_33121;
v_33122:
    goto v_33123;
v_33124:
    v_33332 = get(v_33333, v_33332);
    env = stack[-8];
    stack[-4] = v_33332;
    if (v_33332 == nil) goto v_33119;
    v_33332 = stack[-4];
    goto v_33113;
v_33119:
    v_33332 = elt(env, 9); // simprd
    goto v_33113;
    v_33332 = nil;
v_33113:
    stack[-4] = v_33332;
    v_33332 = stack[-3];
    if (v_33332 == nil) goto v_33136;
    else goto v_33134;
v_33136:
    v_33332 = qvalue(elt(env, 10)); // !*complex
    if (v_33332 == nil) goto v_33134;
    goto v_33135;
v_33134:
    goto v_33058;
v_33135:
    goto v_33149;
v_33145:
    v_33332 = stack[-6];
    v_33333 = qcar(v_33332);
    goto v_33146;
v_33147:
    v_33332 = elt(env, 11); // list
    goto v_33148;
v_33149:
    goto v_33145;
v_33146:
    goto v_33147;
v_33148:
    if (!consp(v_33333)) goto v_33143;
    v_33333 = qcar(v_33333);
    if (v_33333 == v_33332) goto v_33142;
    else goto v_33143;
v_33142:
    v_33332 = stack[-6];
    v_33332 = qcar(v_33332);
    v_33332 = qcdr(v_33332);
    fn = elt(env, 17); // revlis
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-8];
    fn = elt(env, 18); // simpcr
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-8];
    v_33333 = v_33332;
    if (v_33332 == nil) goto v_33156;
    goto v_33169;
v_33165:
    goto v_33166;
v_33167:
    v_33332 = nil;
    goto v_33168;
v_33169:
    goto v_33165;
v_33166:
    goto v_33167;
v_33168:
    if (!consp(v_33333)) goto v_33156;
    v_33333 = qcar(v_33333);
    if (v_33333 == v_33332) goto v_33163;
    else goto v_33156;
v_33163:
    goto v_33057;
v_33156:
    goto v_33058;
    goto v_33141;
v_33143:
v_33141:
    v_33332 = stack[-6];
    fn = elt(env, 17); // revlis
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-8];
    fn = elt(env, 18); // simpcr
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-8];
    stack[-6] = v_33332;
    if (v_33332 == nil) goto v_33176;
    else goto v_33177;
v_33176:
    v_33332 = nil;
    goto v_33055;
v_33177:
    goto v_33193;
v_33189:
    v_33333 = stack[-6];
    goto v_33190;
v_33191:
    v_33332 = nil;
    goto v_33192;
v_33193:
    goto v_33189;
v_33190:
    goto v_33191;
v_33192:
    if (!consp(v_33333)) goto v_33187;
    v_33333 = qcar(v_33333);
    if (v_33333 == v_33332) goto v_33186;
    else goto v_33187;
v_33186:
    v_33332 = lisp_true;
    goto v_33185;
v_33187:
    goto v_33207;
v_33203:
    v_33333 = stack[-5];
    goto v_33204;
v_33205:
    v_33332 = elt(env, 12); // expt
    goto v_33206;
v_33207:
    goto v_33203;
v_33204:
    goto v_33205;
v_33206:
    if (v_33333 == v_33332) goto v_33201;
    else goto v_33202;
v_33201:
    v_33332 = stack[-6];
    v_33332 = qcar(v_33332);
    v_33332 = qcar(v_33332);
    fn = elt(env, 19); // rd!:minusp
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-8];
    goto v_33200;
v_33202:
    v_33332 = nil;
    goto v_33200;
    v_33332 = nil;
v_33200:
    goto v_33185;
    v_33332 = nil;
v_33185:
    if (v_33332 == nil) goto v_33183;
    v_33332 = stack[-6];
    v_33332 = qcdr(v_33332);
    stack[-6] = v_33332;
    goto v_33175;
v_33183:
    v_33332 = stack[-6];
    v_33332 = qcdr(v_33332);
    stack[-2] = v_33332;
    v_33332 = stack[-6];
    v_33332 = qcar(v_33332);
    stack[-6] = v_33332;
    goto v_33058;
v_33175:
v_33056:
    goto v_33234;
v_33230:
    v_33333 = stack[-5];
    goto v_33231;
v_33232:
    v_33332 = elt(env, 13); // !:cr!:
    goto v_33233;
v_33234:
    goto v_33230;
v_33231:
    goto v_33232;
v_33233:
    v_33332 = get(v_33333, v_33332);
    env = stack[-8];
    stack[-7] = v_33332;
    if (v_33332 == nil) goto v_33228;
    goto v_33059;
v_33228:
v_33057:
    goto v_33244;
v_33238:
    stack[-1] = elt(env, 14); // alg
    goto v_33239;
v_33240:
    stack[0] = (LispObject)288+TAG_FIXNUM; // 18
    goto v_33241;
v_33242:
    goto v_33252;
v_33248:
    v_33333 = stack[-5];
    goto v_33249;
v_33250:
    v_33332 = elt(env, 15); // "is not defined as complex function"
    goto v_33251;
v_33252:
    goto v_33248;
v_33249:
    goto v_33250;
v_33251:
    v_33332 = list2(v_33333, v_33332);
    env = stack[-8];
    goto v_33243;
v_33244:
    goto v_33238;
v_33239:
    goto v_33240;
v_33241:
    goto v_33242;
v_33243:
    fn = elt(env, 20); // rerror
    v_33332 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_33332);
    env = stack[-8];
v_33058:
    goto v_33264;
v_33260:
    stack[0] = stack[-4];
    goto v_33261;
v_33262:
    v_33332 = stack[-6];
    fn = elt(env, 17); // revlis
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-8];
    goto v_33263;
v_33264:
    goto v_33260;
v_33261:
    goto v_33262;
v_33263:
    v_33332 = Lapply1(nil, stack[0], v_33332);
    env = stack[-8];
    stack[-6] = v_33332;
    if (v_33332 == nil) goto v_33257;
    else goto v_33258;
v_33257:
    v_33332 = nil;
    goto v_33055;
v_33258:
v_33059:
    goto v_33277;
v_33271:
    stack[0] = elt(env, 16); // apply
    goto v_33272;
v_33273:
    v_33332 = stack[-7];
    stack[-1] = Lmkquote(nil, v_33332);
    env = stack[-8];
    goto v_33274;
v_33275:
    v_33332 = stack[-6];
    v_33332 = Lmkquote(nil, v_33332);
    env = stack[-8];
    goto v_33276;
v_33277:
    goto v_33271;
v_33272:
    goto v_33273;
v_33274:
    goto v_33275;
v_33276:
    v_33332 = list3(stack[0], stack[-1], v_33332);
    env = stack[-8];
    fn = elt(env, 21); // errorset2
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-8];
    stack[-6] = v_33332;
    v_33332 = stack[-6];
    fn = elt(env, 22); // errorp
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-8];
    if (v_33332 == nil) goto v_33287;
    else goto v_33285;
v_33287:
    goto v_33300;
v_33296:
    v_33332 = stack[-6];
    v_33333 = qcar(v_33332);
    stack[-6] = v_33333;
    goto v_33297;
v_33298:
    v_33332 = elt(env, 6); // !:rd!:
    goto v_33299;
v_33300:
    goto v_33296;
v_33297:
    goto v_33298;
v_33299:
    if (!consp(v_33333)) goto v_33294;
    v_33333 = qcar(v_33333);
    if (v_33333 == v_33332) goto v_33293;
    else goto v_33294;
v_33293:
    v_33332 = stack[-6];
    v_33332 = qcdr(v_33332);
    fn = elt(env, 23); // complexp
    v_33332 = (*qfn1(fn))(fn, v_33332);
    env = stack[-8];
    goto v_33292;
v_33294:
    v_33332 = nil;
    goto v_33292;
    v_33332 = nil;
v_33292:
    if (v_33332 == nil) goto v_33290;
    else goto v_33285;
v_33290:
    goto v_33286;
v_33285:
    v_33332 = stack[-2];
    if (v_33332 == nil) goto v_33313;
    v_33332 = stack[-2];
    stack[-6] = v_33332;
    v_33332 = nil;
    stack[-2] = v_33332;
    goto v_33056;
v_33313:
    v_33332 = nil;
    goto v_33055;
    goto v_33284;
v_33286:
    v_33332 = stack[-3];
    if (v_33332 == nil) goto v_33325;
    v_33332 = stack[-6];
    {
        fn = elt(env, 24); // intconv
        return (*qfn1(fn))(fn, v_33332);
    }
v_33325:
    v_33332 = stack[-6];
    goto v_33323;
    v_33332 = nil;
v_33323:
    goto v_33055;
v_33284:
    v_33332 = nil;
v_33055:
    return onevalue(v_33332);
}



// Code for cr!:minusp

static LispObject CC_crTminusp(LispObject env,
                         LispObject v_33046)
{
    env = qenv(env);
    LispObject v_33099, v_33100, v_33101;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33046);
    }
// copy arguments values to proper place
    v_33099 = v_33046;
// end of prologue
    v_33100 = v_33099;
    v_33100 = qcdr(v_33100);
    v_33100 = qcar(v_33100);
    v_33099 = qcdr(v_33099);
    v_33099 = qcdr(v_33099);
    v_33101 = v_33100;
    v_33100 = v_33099;
    v_33099 = v_33101;
    if (!consp(v_33099)) goto v_33058;
    else goto v_33059;
v_33058:
    v_33099 = v_33100;
    v_33099 = (LispObject)zerop(v_33099);
    v_33099 = v_33099 ? lisp_true : nil;
    if (v_33099 == nil) goto v_33063;
    else goto v_33064;
v_33063:
    v_33099 = nil;
    goto v_33062;
v_33064:
    goto v_33075;
v_33071:
    v_33100 = v_33101;
    goto v_33072;
v_33073:
    v_33099 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33074;
v_33075:
    goto v_33071;
v_33072:
    goto v_33073;
v_33074:
        return Llessp(nil, v_33100, v_33099);
    v_33099 = nil;
v_33062:
    goto v_33057;
v_33059:
    v_33099 = v_33100;
    v_33099 = qcar(v_33099);
    v_33099 = (LispObject)zerop(v_33099);
    v_33099 = v_33099 ? lisp_true : nil;
    if (v_33099 == nil) goto v_33082;
    else goto v_33083;
v_33082:
    v_33099 = nil;
    goto v_33081;
v_33083:
    goto v_33095;
v_33091:
    v_33099 = v_33101;
    v_33100 = qcar(v_33099);
    goto v_33092;
v_33093:
    v_33099 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33094;
v_33095:
    goto v_33091;
v_33092:
    goto v_33093;
v_33094:
        return Llessp(nil, v_33100, v_33099);
    v_33099 = nil;
v_33081:
    goto v_33057;
    v_33099 = nil;
v_33057:
    return onevalue(v_33099);
}



// Code for subsubf

static LispObject CC_subsubf(LispObject env,
                         LispObject v_33046, LispObject v_33047)
{
    env = qenv(env);
    LispObject v_33289, v_33290;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33047,v_33046);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33046,v_33047);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_33047;
    stack[-6] = v_33046;
// end of prologue
    stack[-4] = nil;
    v_33289 = stack[-5];
    v_33289 = qcdr(v_33289);
    v_33289 = qcdr(v_33289);
    stack[0] = v_33289;
v_33056:
    v_33289 = stack[0];
    if (v_33289 == nil) goto v_33062;
    else goto v_33063;
v_33062:
    goto v_33055;
v_33063:
    v_33289 = stack[0];
    v_33289 = qcar(v_33289);
    goto v_33077;
v_33073:
    v_33290 = v_33289;
    goto v_33074;
v_33075:
    v_33289 = stack[-6];
    goto v_33076;
v_33077:
    goto v_33073;
v_33074:
    goto v_33075;
v_33076:
    v_33289 = Lassoc(nil, v_33290, v_33289);
    stack[-1] = v_33289;
    if (v_33289 == nil) goto v_33072;
    goto v_33086;
v_33082:
    v_33290 = stack[-1];
    goto v_33083;
v_33084:
    v_33289 = stack[-4];
    goto v_33085;
v_33086:
    goto v_33082;
v_33083:
    goto v_33084;
v_33085:
    v_33289 = cons(v_33290, v_33289);
    env = stack[-8];
    stack[-4] = v_33289;
    goto v_33094;
v_33090:
    v_33290 = stack[-1];
    goto v_33091;
v_33092:
    v_33289 = stack[-6];
    goto v_33093;
v_33094:
    goto v_33090;
v_33091:
    goto v_33092;
v_33093:
    v_33289 = Ldelete(nil, v_33290, v_33289);
    env = stack[-8];
    stack[-6] = v_33289;
    goto v_33070;
v_33072:
v_33070:
    v_33289 = stack[0];
    v_33289 = qcdr(v_33289);
    stack[0] = v_33289;
    goto v_33056;
v_33055:
    goto v_33104;
v_33100:
    goto v_33110;
v_33106:
    v_33290 = stack[-6];
    goto v_33107;
v_33108:
    v_33289 = stack[-5];
    v_33289 = qcar(v_33289);
    goto v_33109;
v_33110:
    goto v_33106;
v_33107:
    goto v_33108;
v_33109:
    stack[-3] = Lsublis(nil, v_33290, v_33289);
    env = stack[-8];
    goto v_33101;
v_33102:
    v_33289 = stack[-5];
    v_33289 = qcdr(v_33289);
    stack[-5] = v_33289;
    v_33289 = stack[-5];
    if (v_33289 == nil) goto v_33124;
    else goto v_33125;
v_33124:
    v_33289 = nil;
    goto v_33118;
v_33125:
    v_33289 = stack[-5];
    v_33289 = qcar(v_33289);
    goto v_33137;
v_33133:
    v_33290 = stack[-6];
    goto v_33134;
v_33135:
    goto v_33136;
v_33137:
    goto v_33133;
v_33134:
    goto v_33135;
v_33136:
    fn = elt(env, 3); // subsublis
    v_33289 = (*qfn2(fn))(fn, v_33290, v_33289);
    env = stack[-8];
    v_33289 = ncons(v_33289);
    env = stack[-8];
    stack[-1] = v_33289;
    stack[-2] = v_33289;
v_33119:
    v_33289 = stack[-5];
    v_33289 = qcdr(v_33289);
    stack[-5] = v_33289;
    v_33289 = stack[-5];
    if (v_33289 == nil) goto v_33144;
    else goto v_33145;
v_33144:
    v_33289 = stack[-2];
    goto v_33118;
v_33145:
    goto v_33153;
v_33149:
    stack[0] = stack[-1];
    goto v_33150;
v_33151:
    v_33289 = stack[-5];
    v_33289 = qcar(v_33289);
    goto v_33164;
v_33160:
    v_33290 = stack[-6];
    goto v_33161;
v_33162:
    goto v_33163;
v_33164:
    goto v_33160;
v_33161:
    goto v_33162;
v_33163:
    fn = elt(env, 3); // subsublis
    v_33289 = (*qfn2(fn))(fn, v_33290, v_33289);
    env = stack[-8];
    v_33289 = ncons(v_33289);
    env = stack[-8];
    goto v_33152;
v_33153:
    goto v_33149;
v_33150:
    goto v_33151;
v_33152:
    v_33289 = Lrplacd(nil, stack[0], v_33289);
    env = stack[-8];
    v_33289 = stack[-1];
    v_33289 = qcdr(v_33289);
    stack[-1] = v_33289;
    goto v_33119;
v_33118:
    goto v_33103;
v_33104:
    goto v_33100;
v_33101:
    goto v_33102;
v_33103:
    v_33289 = cons(stack[-3], v_33289);
    env = stack[-8];
    stack[-5] = v_33289;
    v_33289 = stack[-4];
    if (v_33289 == nil) goto v_33171;
    else goto v_33172;
v_33171:
    v_33289 = stack[-5];
    goto v_33052;
v_33172:
    goto v_33180;
v_33176:
    v_33289 = stack[-4];
    fn = elt(env, 4); // reversip!*
    v_33289 = (*qfn1(fn))(fn, v_33289);
    env = stack[-8];
    stack[-7] = v_33289;
    v_33289 = stack[-7];
    if (v_33289 == nil) goto v_33191;
    else goto v_33192;
v_33191:
    v_33289 = nil;
    v_33290 = v_33289;
    goto v_33185;
v_33192:
    v_33289 = stack[-7];
    v_33289 = qcar(v_33289);
    v_33290 = v_33289;
    goto v_33206;
v_33200:
    stack[-1] = elt(env, 1); // equal
    goto v_33201;
v_33202:
    v_33289 = v_33290;
    stack[0] = qcar(v_33289);
    goto v_33203;
v_33204:
    v_33289 = v_33290;
    v_33289 = qcdr(v_33289);
    fn = elt(env, 5); // aeval
    v_33289 = (*qfn1(fn))(fn, v_33289);
    env = stack[-8];
    goto v_33205;
v_33206:
    goto v_33200;
v_33201:
    goto v_33202;
v_33203:
    goto v_33204;
v_33205:
    v_33289 = list3(stack[-1], stack[0], v_33289);
    env = stack[-8];
    v_33289 = ncons(v_33289);
    env = stack[-8];
    stack[-3] = v_33289;
    stack[-4] = v_33289;
v_33186:
    v_33289 = stack[-7];
    v_33289 = qcdr(v_33289);
    stack[-7] = v_33289;
    v_33289 = stack[-7];
    if (v_33289 == nil) goto v_33217;
    else goto v_33218;
v_33217:
    v_33289 = stack[-4];
    v_33290 = v_33289;
    goto v_33185;
v_33218:
    goto v_33226;
v_33222:
    stack[-2] = stack[-3];
    goto v_33223;
v_33224:
    v_33289 = stack[-7];
    v_33289 = qcar(v_33289);
    v_33290 = v_33289;
    goto v_33239;
v_33233:
    stack[-1] = elt(env, 1); // equal
    goto v_33234;
v_33235:
    v_33289 = v_33290;
    stack[0] = qcar(v_33289);
    goto v_33236;
v_33237:
    v_33289 = v_33290;
    v_33289 = qcdr(v_33289);
    fn = elt(env, 5); // aeval
    v_33289 = (*qfn1(fn))(fn, v_33289);
    env = stack[-8];
    goto v_33238;
v_33239:
    goto v_33233;
v_33234:
    goto v_33235;
v_33236:
    goto v_33237;
v_33238:
    v_33289 = list3(stack[-1], stack[0], v_33289);
    env = stack[-8];
    v_33289 = ncons(v_33289);
    env = stack[-8];
    goto v_33225;
v_33226:
    goto v_33222;
v_33223:
    goto v_33224;
v_33225:
    v_33289 = Lrplacd(nil, stack[-2], v_33289);
    env = stack[-8];
    v_33289 = stack[-3];
    v_33289 = qcdr(v_33289);
    stack[-3] = v_33289;
    goto v_33186;
v_33185:
    goto v_33177;
v_33178:
    v_33289 = stack[-5];
    goto v_33179;
v_33180:
    goto v_33176;
v_33177:
    goto v_33178;
v_33179:
    fn = elt(env, 6); // aconc!*
    v_33289 = (*qfn2(fn))(fn, v_33290, v_33289);
    env = stack[-8];
    stack[-5] = v_33289;
    v_33289 = stack[-6];
    if (v_33289 == nil) goto v_33252;
    v_33289 = stack[-5];
    {
        fn = elt(env, 7); // subeval
        return (*qfn1(fn))(fn, v_33289);
    }
v_33252:
    goto v_33264;
v_33260:
    goto v_33271;
v_33267:
    goto v_33277;
v_33273:
    goto v_33283;
v_33279:
    v_33290 = elt(env, 2); // sub
    goto v_33280;
v_33281:
    v_33289 = stack[-5];
    goto v_33282;
v_33283:
    goto v_33279;
v_33280:
    goto v_33281;
v_33282:
    v_33290 = cons(v_33290, v_33289);
    env = stack[-8];
    goto v_33274;
v_33275:
    v_33289 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33276;
v_33277:
    goto v_33273;
v_33274:
    goto v_33275;
v_33276:
    fn = elt(env, 8); // mksp
    v_33290 = (*qfn2(fn))(fn, v_33290, v_33289);
    env = stack[-8];
    goto v_33268;
v_33269:
    v_33289 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33270;
v_33271:
    goto v_33267;
v_33268:
    goto v_33269;
v_33270:
    v_33289 = cons(v_33290, v_33289);
    env = stack[-8];
    v_33290 = ncons(v_33289);
    env = stack[-8];
    goto v_33261;
v_33262:
    v_33289 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33263;
v_33264:
    goto v_33260;
v_33261:
    goto v_33262;
v_33263:
    v_33289 = cons(v_33290, v_33289);
    env = stack[-8];
    {
        fn = elt(env, 9); // mk!*sq
        return (*qfn1(fn))(fn, v_33289);
    }
    v_33289 = nil;
v_33052:
    return onevalue(v_33289);
}



setup_type const u55_setup[] =
{
    {"addcoeffs",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_addcoeffs},
    {"change+sq+to+int",        CC_changeLsqLtoLint,TOO_MANY_1,WRONG_NO_1},
    {"bc_pmon",                 TOO_FEW_2,      CC_bc_pmon,    WRONG_NO_2},
    {"operator",                CC_operator,    TOO_MANY_1,    WRONG_NO_1},
    {"look_for_rational",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_look_for_rational},
    {"vevzero?1",               CC_vevzeroW1,   TOO_MANY_1,    WRONG_NO_1},
    {"xpndwedge",               CC_xpndwedge,   TOO_MANY_1,    WRONG_NO_1},
    {"acmemb",                  TOO_FEW_2,      CC_acmemb,     WRONG_NO_2},
    {"noncom1",                 CC_noncom1,     TOO_MANY_1,    WRONG_NO_1},
    {"rationalizef",            CC_rationalizef,TOO_MANY_1,    WRONG_NO_1},
    {"lowestdeg",               TOO_FEW_2,      CC_lowestdeg,  WRONG_NO_2},
    {"add-to-sorted-tree",      TOO_FEW_2,      CC_addKtoKsortedKtree,WRONG_NO_2},
    {"ofsf_exploitknowl",       CC_ofsf_exploitknowl,TOO_MANY_1,WRONG_NO_1},
    {"uterm",                   TOO_FEW_2,      CC_uterm,      WRONG_NO_2},
    {"get*nr*real*irred*reps",  CC_getHnrHrealHirredHreps,TOO_MANY_1,WRONG_NO_1},
    {"qqe_simpat",              CC_qqe_simpat,  TOO_MANY_1,    WRONG_NO_1},
    {"pasf_ceeq",               CC_pasf_ceeq,   TOO_MANY_1,    WRONG_NO_1},
    {"matrix_input_test",       CC_matrix_input_test,TOO_MANY_1,WRONG_NO_1},
    {"dip-nc-ev-prod",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dipKncKevKprod},
    {"row_dim",                 CC_row_dim,     TOO_MANY_1,    WRONG_NO_1},
    {"unshift",                 CC_unshift,     TOO_MANY_1,    WRONG_NO_1},
    {"r2speclist",              CC_r2speclist,  TOO_MANY_1,    WRONG_NO_1},
    {"all_defined",             TOO_FEW_2,      CC_all_defined,WRONG_NO_2},
    {"simprd",                  CC_simprd,      TOO_MANY_1,    WRONG_NO_1},
    {"gak",                     WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gak},
    {"constant_expr_listp",     CC_constant_expr_listp,TOO_MANY_1,WRONG_NO_1},
    {"talp_nextt",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_nextt},
    {"ofsf_factsf",             CC_ofsf_factsf, TOO_MANY_1,    WRONG_NO_1},
    {"dip_comp1",               TOO_FEW_2,      CC_dip_comp1,  WRONG_NO_2},
    {"tidysqrt",                CC_tidysqrt,    TOO_MANY_1,    WRONG_NO_1},
    {"expttermp",               TOO_FEW_2,      CC_expttermp,  WRONG_NO_2},
    {"xriterion_2",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xriterion_2},
    {"evalsubset",              TOO_FEW_2,      CC_evalsubset, WRONG_NO_2},
    {"preproc",                 CC_preproc,     TOO_MANY_1,    WRONG_NO_1},
    {"dvertex-to-projector",    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dvertexKtoKprojector},
    {"red_extract",             CC_red_extract, TOO_MANY_1,    WRONG_NO_1},
    {"*hfac",                   CC_Hhfac,       TOO_MANY_1,    WRONG_NO_1},
    {"radd",                    TOO_FEW_2,      CC_radd,       WRONG_NO_2},
    {"find_active_components",  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_find_active_components},
    {"giminusp:",               CC_giminuspT,   TOO_MANY_1,    WRONG_NO_1},
    {"opfchk!",                 CC_opfchkB,     TOO_MANY_1,    WRONG_NO_1},
    {"cr:minusp",               CC_crTminusp,   TOO_MANY_1,    WRONG_NO_1},
    {"subsubf",                 TOO_FEW_2,      CC_subsubf,    WRONG_NO_2},
    {NULL, (one_args *)"u55", (two_args *)"119506 5627884 5662800", 0}
};

// end of generated code
