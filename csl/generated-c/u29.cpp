
// $destdir/u29.c        Machine generated C code

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



// Code for cnrd

static LispObject CC_cnrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_16046, v_16047, v_16048;
    LispObject fn;
    argcheck(nargs, 0, "cnrd");
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
    stack_popper stack_popper_var(6);
// end of prologue
    goto v_15860;
v_15856:
    v_16047 = qvalue(elt(env, 1)); // atts
    goto v_15857;
v_15858:
    v_16046 = elt(env, 2); // type
    goto v_15859;
v_15860:
    goto v_15856;
v_15857:
    goto v_15858;
v_15859:
    fn = elt(env, 15); // find
    v_16046 = (*qfn2(fn))(fn, v_16047, v_16046);
    env = stack[-5];
    v_16046 = Lintern(nil, v_16046);
    env = stack[-5];
    stack[-1] = v_16046;
    goto v_15868;
v_15864:
    v_16047 = qvalue(elt(env, 1)); // atts
    goto v_15865;
v_15866:
    v_16046 = elt(env, 3); // base
    goto v_15867;
v_15868:
    goto v_15864;
v_15865:
    goto v_15866;
v_15867:
    fn = elt(env, 15); // find
    v_16046 = (*qfn2(fn))(fn, v_16047, v_16046);
    env = stack[-5];
    stack[0] = v_16046;
    fn = elt(env, 16); // lex
    v_16046 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    v_16046 = qvalue(elt(env, 4)); // char
    stack[-4] = v_16046;
    fn = elt(env, 16); // lex
    v_16046 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_15882;
v_15878:
    v_16047 = stack[-1];
    goto v_15879;
v_15880:
    v_16046 = elt(env, 5); // constant
    goto v_15881;
v_15882:
    goto v_15878;
v_15879:
    goto v_15880;
v_15881:
    if (v_16047 == v_16046) goto v_15876;
    else goto v_15877;
v_15876:
    v_16046 = stack[-4];
    {
        fn = elt(env, 17); // compress!*
        return (*qfn1(fn))(fn, v_16046);
    }
v_15877:
    v_16046 = stack[-1];
    if (v_16046 == nil) goto v_15889;
    else goto v_15890;
v_15889:
    v_16046 = stack[-4];
    {
        fn = elt(env, 17); // compress!*
        return (*qfn1(fn))(fn, v_16046);
    }
v_15890:
    goto v_15902;
v_15898:
    v_16047 = stack[-1];
    goto v_15899;
v_15900:
    v_16046 = elt(env, 6); // (real integer)
    goto v_15901;
v_15902:
    goto v_15898;
v_15899:
    goto v_15900;
v_15901:
    v_16046 = Lmember(nil, v_16047, v_16046);
    if (v_16046 == nil) goto v_15897;
    v_16046 = stack[0];
    if (v_16046 == nil) goto v_15908;
    else goto v_15909;
v_15908:
    v_16046 = stack[-4];
    {
        fn = elt(env, 17); // compress!*
        return (*qfn1(fn))(fn, v_16046);
    }
v_15909:
    goto v_15922;
v_15916:
    stack[-3] = elt(env, 7); // based_integer
    goto v_15917;
v_15918:
    stack[-2] = nil;
    goto v_15919;
v_15920:
    goto v_15932;
v_15926:
    stack[-1] = stack[0];
    goto v_15927;
v_15928:
    goto v_15941;
v_15935:
    stack[0] = elt(env, 8); // string
    goto v_15936;
v_15937:
    v_16046 = stack[-4];
    fn = elt(env, 17); // compress!*
    v_16047 = (*qfn1(fn))(fn, v_16046);
    env = stack[-5];
    goto v_15938;
v_15939:
    v_16046 = nil;
    goto v_15940;
v_15941:
    goto v_15935;
v_15936:
    goto v_15937;
v_15938:
    goto v_15939;
v_15940:
    v_16047 = list2star(stack[0], v_16047, v_16046);
    env = stack[-5];
    goto v_15929;
v_15930:
    v_16046 = nil;
    goto v_15931;
v_15932:
    goto v_15926;
v_15927:
    goto v_15928;
v_15929:
    goto v_15930;
v_15931:
    v_16046 = list2star(stack[-1], v_16047, v_16046);
    goto v_15921;
v_15922:
    goto v_15916;
v_15917:
    goto v_15918;
v_15919:
    goto v_15920;
v_15921:
    {
        LispObject v_16054 = stack[-3];
        LispObject v_16055 = stack[-2];
        return list2star(v_16054, v_16055, v_16046);
    }
    goto v_15895;
v_15897:
v_15895:
    goto v_15955;
v_15951:
    v_16046 = stack[-1];
    v_16047 = Lintern(nil, v_16046);
    env = stack[-5];
    goto v_15952;
v_15953:
    v_16046 = elt(env, 9); // (rational complex!-cartesian complex!-polar)
    goto v_15954;
v_15955:
    goto v_15951;
v_15952:
    goto v_15953;
v_15954:
    v_16046 = Lmember(nil, v_16047, v_16046);
    if (v_16046 == nil) goto v_15950;
    fn = elt(env, 18); // seprd
    v_16046 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[-2] = v_16046;
    goto v_15969;
v_15965:
    v_16047 = stack[-1];
    goto v_15966;
v_15967:
    v_16046 = elt(env, 10); // rational
    goto v_15968;
v_15969:
    goto v_15965;
v_15966:
    goto v_15967;
v_15968:
    if (v_16047 == v_16046) goto v_15963;
    else goto v_15964;
v_15963:
    fn = elt(env, 16); // lex
    v_16046 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_15978;
v_15974:
    v_16046 = stack[-4];
    fn = elt(env, 17); // compress!*
    v_16047 = (*qfn1(fn))(fn, v_16046);
    env = stack[-5];
    goto v_15975;
v_15976:
    v_16046 = stack[-2];
    goto v_15977;
v_15978:
    goto v_15974;
v_15975:
    goto v_15976;
v_15977:
    {
        fn = elt(env, 10); // rational
        return (*qfn2(fn))(fn, v_16047, v_16046);
    }
v_15964:
    goto v_15988;
v_15984:
    v_16047 = stack[-1];
    goto v_15985;
v_15986:
    v_16046 = elt(env, 11); // complex!-cartesian
    goto v_15987;
v_15988:
    goto v_15984;
v_15985:
    goto v_15986;
v_15987:
    if (v_16047 == v_16046) goto v_15982;
    else goto v_15983;
v_15982:
    fn = elt(env, 16); // lex
    v_16046 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_15999;
v_15993:
    stack[-1] = elt(env, 12); // complex_cartesian
    goto v_15994;
v_15995:
    stack[0] = nil;
    goto v_15996;
v_15997:
    goto v_16009;
v_16003:
    v_16046 = stack[-4];
    fn = elt(env, 17); // compress!*
    v_16048 = (*qfn1(fn))(fn, v_16046);
    env = stack[-5];
    goto v_16004;
v_16005:
    v_16047 = stack[-2];
    goto v_16006;
v_16007:
    v_16046 = nil;
    goto v_16008;
v_16009:
    goto v_16003;
v_16004:
    goto v_16005;
v_16006:
    goto v_16007;
v_16008:
    v_16046 = list2star(v_16048, v_16047, v_16046);
    goto v_15998;
v_15999:
    goto v_15993;
v_15994:
    goto v_15995;
v_15996:
    goto v_15997;
v_15998:
    {
        LispObject v_16056 = stack[-1];
        LispObject v_16057 = stack[0];
        return list2star(v_16056, v_16057, v_16046);
    }
v_15983:
    goto v_16020;
v_16016:
    v_16047 = stack[-1];
    goto v_16017;
v_16018:
    v_16046 = elt(env, 13); // complex!-polar
    goto v_16019;
v_16020:
    goto v_16016;
v_16017:
    goto v_16018;
v_16019:
    if (v_16047 == v_16046) goto v_16014;
    else goto v_16015;
v_16014:
    fn = elt(env, 16); // lex
    v_16046 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_16031;
v_16025:
    stack[-1] = elt(env, 14); // complex_polar
    goto v_16026;
v_16027:
    stack[0] = nil;
    goto v_16028;
v_16029:
    goto v_16041;
v_16035:
    v_16046 = stack[-4];
    fn = elt(env, 17); // compress!*
    v_16048 = (*qfn1(fn))(fn, v_16046);
    env = stack[-5];
    goto v_16036;
v_16037:
    v_16047 = stack[-2];
    goto v_16038;
v_16039:
    v_16046 = nil;
    goto v_16040;
v_16041:
    goto v_16035;
v_16036:
    goto v_16037;
v_16038:
    goto v_16039;
v_16040:
    v_16046 = list2star(v_16048, v_16047, v_16046);
    goto v_16030;
v_16031:
    goto v_16025;
v_16026:
    goto v_16027;
v_16028:
    goto v_16029;
v_16030:
    {
        LispObject v_16058 = stack[-1];
        LispObject v_16059 = stack[0];
        return list2star(v_16058, v_16059, v_16046);
    }
v_16015:
    goto v_15948;
v_15950:
v_15948:
    v_16046 = nil;
    return onevalue(v_16046);
}



// Code for ps!:expression

static LispObject CC_psTexpression(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15888, v_15889, v_15890;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15890 = v_15845;
// end of prologue
    v_15888 = v_15890;
    if (!consp(v_15888)) goto v_15853;
    else goto v_15854;
v_15853:
    v_15888 = lisp_true;
    goto v_15852;
v_15854:
    goto v_15867;
v_15863:
    v_15888 = v_15890;
    v_15889 = qcar(v_15888);
    goto v_15864;
v_15865:
    v_15888 = elt(env, 1); // !:ps!:
    goto v_15866;
v_15867:
    goto v_15863;
v_15864:
    goto v_15865;
v_15866:
    if (v_15889 == v_15888) goto v_15862;
    v_15888 = v_15890;
    v_15888 = qcar(v_15888);
    if (!symbolp(v_15888)) v_15888 = nil;
    else { v_15888 = qfastgets(v_15888);
           if (v_15888 != nil) { v_15888 = elt(v_15888, 8); // dname
#ifdef RECORD_GET
             if (v_15888 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_15888 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_15888 == SPID_NOPROP) v_15888 = nil; }}
#endif
    goto v_15860;
v_15862:
    v_15888 = nil;
    goto v_15860;
    v_15888 = nil;
v_15860:
    goto v_15852;
    v_15888 = nil;
v_15852:
    if (v_15888 == nil) goto v_15850;
    v_15888 = v_15890;
    goto v_15848;
v_15850:
    goto v_15885;
v_15881:
    v_15889 = v_15890;
    goto v_15882;
v_15883:
    v_15888 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_15884;
v_15885:
    goto v_15881;
v_15882:
    goto v_15883;
v_15884:
    {
        fn = elt(env, 2); // ps!:getv
        return (*qfn2(fn))(fn, v_15889, v_15888);
    }
    v_15888 = nil;
v_15848:
    return onevalue(v_15888);
}



// Code for vevstrictlydivides!?

static LispObject CC_vevstrictlydividesW(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_15870, v_15871, v_15872, v_15873;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15872 = v_15846;
    v_15873 = v_15845;
// end of prologue
    goto v_15856;
v_15852:
    v_15871 = v_15873;
    goto v_15853;
v_15854:
    v_15870 = v_15872;
    goto v_15855;
v_15856:
    goto v_15852;
v_15853:
    goto v_15854;
v_15855:
    if (equal(v_15871, v_15870)) goto v_15851;
    goto v_15864;
v_15860:
    v_15870 = v_15872;
    goto v_15861;
v_15862:
    v_15871 = v_15873;
    goto v_15863;
v_15864:
    goto v_15860;
v_15861:
    goto v_15862;
v_15863:
    {
        fn = elt(env, 1); // vevmtest!?
        return (*qfn2(fn))(fn, v_15870, v_15871);
    }
v_15851:
    v_15870 = nil;
    goto v_15849;
    v_15870 = nil;
v_15849:
    return onevalue(v_15870);
}



// Code for critical_element

static LispObject CC_critical_element(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15857, v_15858;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15857 = v_15845;
// end of prologue
    goto v_15852;
v_15848:
    v_15858 = v_15857;
    v_15858 = qcdr(v_15858);
    v_15858 = qcar(v_15858);
    goto v_15849;
v_15850:
    goto v_15851;
v_15852:
    goto v_15848;
v_15849:
    goto v_15850;
v_15851:
        return Lapply1(nil, v_15858, v_15857);
}



// Code for contract!-strand

static LispObject CC_contractKstrand(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_15857, v_15858;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15845,v_15846);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_15857 = v_15846;
    v_15858 = v_15845;
// end of prologue
    goto v_15853;
v_15849:
    stack[0] = v_15858;
    goto v_15850;
v_15851:
    fn = elt(env, 1); // zero!-roads
    v_15857 = (*qfn1(fn))(fn, v_15857);
    env = stack[-1];
    goto v_15852;
v_15853:
    goto v_15849;
v_15850:
    goto v_15851;
v_15852:
    {
        LispObject v_15860 = stack[0];
        fn = elt(env, 2); // contr!-strand
        return (*qfn2(fn))(fn, v_15860, v_15857);
    }
}



// Code for assert_declarestat1

static LispObject CC_assert_declarestat1(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_16190, v_16191, v_16192, v_16193;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(13);
// copy arguments values to proper place
    stack[-4] = v_15845;
// end of prologue
    stack[-10] = nil;
    v_16190 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_16190;
    v_16190 = stack[-4];
    v_16190 = qcar(v_16190);
    v_16190 = Lexplode(nil, v_16190);
    env = stack[-12];
    stack[0] = v_16190;
    goto v_15872;
v_15868:
    v_16190 = elt(env, 1); // assert!:
    v_16191 = Lexplode(nil, v_16190);
    env = stack[-12];
    goto v_15869;
v_15870:
    v_16190 = stack[0];
    goto v_15871;
v_15872:
    goto v_15868;
v_15869:
    goto v_15870;
v_15871:
    v_16190 = Lnconc(nil, v_16191, v_16190);
    env = stack[-12];
    v_16190 = Lcompress(nil, v_16190);
    env = stack[-12];
    v_16190 = Lintern(nil, v_16190);
    env = stack[-12];
    stack[-9] = v_16190;
    goto v_15883;
v_15879:
    v_16190 = elt(env, 2); // noassert!:
    v_16191 = Lexplode(nil, v_16190);
    env = stack[-12];
    goto v_15880;
v_15881:
    v_16190 = stack[0];
    goto v_15882;
v_15883:
    goto v_15879;
v_15880:
    goto v_15881;
v_15882:
    v_16190 = Lnconc(nil, v_16191, v_16190);
    env = stack[-12];
    v_16190 = Lcompress(nil, v_16190);
    env = stack[-12];
    v_16190 = Lintern(nil, v_16190);
    env = stack[-12];
    stack[-5] = v_16190;
    v_16190 = stack[-4];
    v_16190 = qcdr(v_16190);
    v_16190 = qcar(v_16190);
    stack[-6] = v_16190;
    v_16190 = stack[-6];
    if (v_16190 == nil) goto v_15898;
    else goto v_15899;
v_15898:
    v_16190 = nil;
    goto v_15891;
v_15899:
    goto v_15911;
v_15907:
    stack[0] = elt(env, 3); // a
    goto v_15908;
v_15909:
    v_16190 = stack[-7];
    v_16190 = add1(v_16190);
    env = stack[-12];
    stack[-7] = v_16190;
    goto v_15910;
v_15911:
    goto v_15907;
v_15908:
    goto v_15909;
v_15910:
    fn = elt(env, 18); // mkid
    v_16190 = (*qfn2(fn))(fn, stack[0], v_16190);
    env = stack[-12];
    v_16190 = ncons(v_16190);
    env = stack[-12];
    stack[-2] = v_16190;
    stack[-3] = v_16190;
v_15892:
    v_16190 = stack[-6];
    v_16190 = qcdr(v_16190);
    stack[-6] = v_16190;
    v_16190 = stack[-6];
    if (v_16190 == nil) goto v_15919;
    else goto v_15920;
v_15919:
    v_16190 = stack[-3];
    goto v_15891;
v_15920:
    goto v_15928;
v_15924:
    stack[-1] = stack[-2];
    goto v_15925;
v_15926:
    goto v_15939;
v_15935:
    stack[0] = elt(env, 3); // a
    goto v_15936;
v_15937:
    v_16190 = stack[-7];
    v_16190 = add1(v_16190);
    env = stack[-12];
    stack[-7] = v_16190;
    goto v_15938;
v_15939:
    goto v_15935;
v_15936:
    goto v_15937;
v_15938:
    fn = elt(env, 18); // mkid
    v_16190 = (*qfn2(fn))(fn, stack[0], v_16190);
    env = stack[-12];
    v_16190 = ncons(v_16190);
    env = stack[-12];
    goto v_15927;
v_15928:
    goto v_15924;
v_15925:
    goto v_15926;
v_15927:
    v_16190 = Lrplacd(nil, stack[-1], v_16190);
    env = stack[-12];
    v_16190 = stack[-2];
    v_16190 = qcdr(v_16190);
    stack[-2] = v_16190;
    goto v_15892;
v_15891:
    stack[-3] = v_16190;
    v_16190 = stack[-4];
    v_16190 = qcar(v_16190);
    v_16190 = Lmkquote(nil, v_16190);
    env = stack[-12];
    stack[-8] = v_16190;
    v_16190 = stack[-5];
    v_16190 = Lmkquote(nil, v_16190);
    env = stack[-12];
    stack[-7] = v_16190;
    goto v_15955;
v_15951:
    v_16191 = elt(env, 4); // list
    goto v_15952;
v_15953:
    v_16190 = stack[-3];
    goto v_15954;
v_15955:
    goto v_15951;
v_15952:
    goto v_15953;
v_15954:
    v_16190 = cons(v_16191, v_16190);
    env = stack[-12];
    stack[-6] = v_16190;
    goto v_15963;
v_15959:
    stack[-11] = elt(env, 4); // list
    goto v_15960;
v_15961:
    v_16190 = stack[-4];
    v_16190 = qcdr(v_16190);
    v_16190 = qcar(v_16190);
    stack[-5] = v_16190;
    v_16190 = stack[-5];
    if (v_16190 == nil) goto v_15976;
    else goto v_15977;
v_15976:
    v_16190 = nil;
    goto v_15969;
v_15977:
    v_16190 = stack[-5];
    v_16190 = qcar(v_16190);
    v_16190 = Lmkquote(nil, v_16190);
    env = stack[-12];
    v_16190 = ncons(v_16190);
    env = stack[-12];
    stack[-1] = v_16190;
    stack[-2] = v_16190;
v_15970:
    v_16190 = stack[-5];
    v_16190 = qcdr(v_16190);
    stack[-5] = v_16190;
    v_16190 = stack[-5];
    if (v_16190 == nil) goto v_15990;
    else goto v_15991;
v_15990:
    v_16190 = stack[-2];
    goto v_15969;
v_15991:
    goto v_15999;
v_15995:
    stack[0] = stack[-1];
    goto v_15996;
v_15997:
    v_16190 = stack[-5];
    v_16190 = qcar(v_16190);
    v_16190 = Lmkquote(nil, v_16190);
    env = stack[-12];
    v_16190 = ncons(v_16190);
    env = stack[-12];
    goto v_15998;
v_15999:
    goto v_15995;
v_15996:
    goto v_15997;
v_15998:
    v_16190 = Lrplacd(nil, stack[0], v_16190);
    env = stack[-12];
    v_16190 = stack[-1];
    v_16190 = qcdr(v_16190);
    stack[-1] = v_16190;
    goto v_15970;
v_15969:
    goto v_15962;
v_15963:
    goto v_15959;
v_15960:
    goto v_15961;
v_15962:
    v_16190 = cons(stack[-11], v_16190);
    env = stack[-12];
    stack[-11] = v_16190;
    v_16190 = stack[-4];
    v_16190 = qcdr(v_16190);
    v_16190 = qcdr(v_16190);
    v_16190 = qcar(v_16190);
    v_16190 = Lmkquote(nil, v_16190);
    env = stack[-12];
    goto v_16019;
v_16015:
    goto v_16029;
v_16021:
    stack[-5] = elt(env, 5); // de
    goto v_16022;
v_16023:
    stack[-4] = stack[-9];
    goto v_16024;
v_16025:
    goto v_16026;
v_16027:
    goto v_16042;
v_16034:
    stack[-2] = elt(env, 6); // assert_check1
    goto v_16035;
v_16036:
    stack[-1] = stack[-8];
    goto v_16037;
v_16038:
    stack[0] = stack[-7];
    goto v_16039;
v_16040:
    goto v_16053;
v_16047:
    v_16192 = stack[-6];
    goto v_16048;
v_16049:
    v_16191 = stack[-11];
    goto v_16050;
v_16051:
    goto v_16052;
v_16053:
    goto v_16047;
v_16048:
    goto v_16049;
v_16050:
    goto v_16051;
v_16052:
    v_16190 = list3(v_16192, v_16191, v_16190);
    env = stack[-12];
    goto v_16041;
v_16042:
    goto v_16034;
v_16035:
    goto v_16036;
v_16037:
    goto v_16038;
v_16039:
    goto v_16040;
v_16041:
    v_16190 = list3star(stack[-2], stack[-1], stack[0], v_16190);
    env = stack[-12];
    goto v_16028;
v_16029:
    goto v_16021;
v_16022:
    goto v_16023;
v_16024:
    goto v_16025;
v_16026:
    goto v_16027;
v_16028:
    v_16191 = list4(stack[-5], stack[-4], stack[-3], v_16190);
    env = stack[-12];
    goto v_16016;
v_16017:
    v_16190 = stack[-10];
    goto v_16018;
v_16019:
    goto v_16015;
v_16016:
    goto v_16017;
v_16018:
    v_16190 = cons(v_16191, v_16190);
    env = stack[-12];
    stack[-10] = v_16190;
    goto v_16063;
v_16059:
    goto v_16073;
v_16065:
    stack[-2] = elt(env, 7); // put
    goto v_16066;
v_16067:
    stack[-1] = stack[-8];
    goto v_16068;
v_16069:
    stack[0] = elt(env, 8); // (quote assert_assertfn)
    goto v_16070;
v_16071:
    v_16190 = stack[-9];
    v_16190 = Lmkquote(nil, v_16190);
    env = stack[-12];
    goto v_16072;
v_16073:
    goto v_16065;
v_16066:
    goto v_16067;
v_16068:
    goto v_16069;
v_16070:
    goto v_16071;
v_16072:
    v_16191 = list4(stack[-2], stack[-1], stack[0], v_16190);
    env = stack[-12];
    goto v_16060;
v_16061:
    v_16190 = stack[-10];
    goto v_16062;
v_16063:
    goto v_16059;
v_16060:
    goto v_16061;
v_16062:
    v_16190 = cons(v_16191, v_16190);
    env = stack[-12];
    stack[-10] = v_16190;
    goto v_16085;
v_16081:
    goto v_16095;
v_16087:
    v_16193 = elt(env, 7); // put
    goto v_16088;
v_16089:
    v_16192 = stack[-8];
    goto v_16090;
v_16091:
    v_16191 = elt(env, 9); // (quote assert_noassertfn)
    goto v_16092;
v_16093:
    v_16190 = stack[-7];
    goto v_16094;
v_16095:
    goto v_16087;
v_16088:
    goto v_16089;
v_16090:
    goto v_16091;
v_16092:
    goto v_16093;
v_16094:
    v_16191 = list4(v_16193, v_16192, v_16191, v_16190);
    env = stack[-12];
    goto v_16082;
v_16083:
    v_16190 = stack[-10];
    goto v_16084;
v_16085:
    goto v_16081;
v_16082:
    goto v_16083;
v_16084:
    v_16190 = cons(v_16191, v_16190);
    env = stack[-12];
    stack[-10] = v_16190;
    goto v_16106;
v_16102:
    goto v_16116;
v_16108:
    v_16193 = elt(env, 7); // put
    goto v_16109;
v_16110:
    v_16192 = stack[-8];
    goto v_16111;
v_16112:
    v_16191 = elt(env, 10); // (quote assert_installed)
    goto v_16113;
v_16114:
    v_16190 = nil;
    goto v_16115;
v_16116:
    goto v_16108;
v_16109:
    goto v_16110;
v_16111:
    goto v_16112;
v_16113:
    goto v_16114;
v_16115:
    v_16191 = list4(v_16193, v_16192, v_16191, v_16190);
    env = stack[-12];
    goto v_16103;
v_16104:
    v_16190 = stack[-10];
    goto v_16105;
v_16106:
    goto v_16102;
v_16103:
    goto v_16104;
v_16105:
    v_16190 = cons(v_16191, v_16190);
    env = stack[-12];
    stack[-10] = v_16190;
    goto v_16127;
v_16123:
    goto v_16133;
v_16129:
    stack[-3] = elt(env, 11); // cond
    goto v_16130;
v_16131:
    goto v_16140;
v_16136:
    goto v_16146;
v_16142:
    stack[0] = elt(env, 12); // not
    goto v_16143;
v_16144:
    goto v_16155;
v_16149:
    v_16192 = elt(env, 13); // member
    goto v_16150;
v_16151:
    v_16191 = stack[-8];
    goto v_16152;
v_16153:
    v_16190 = elt(env, 14); // assert_functionl!*
    goto v_16154;
v_16155:
    goto v_16149;
v_16150:
    goto v_16151;
v_16152:
    goto v_16153;
v_16154:
    v_16190 = list3(v_16192, v_16191, v_16190);
    env = stack[-12];
    goto v_16145;
v_16146:
    goto v_16142;
v_16143:
    goto v_16144;
v_16145:
    stack[-2] = list2(stack[0], v_16190);
    env = stack[-12];
    goto v_16137;
v_16138:
    goto v_16166;
v_16160:
    stack[-1] = elt(env, 15); // setq
    goto v_16161;
v_16162:
    stack[0] = elt(env, 14); // assert_functionl!*
    goto v_16163;
v_16164:
    goto v_16176;
v_16170:
    v_16192 = elt(env, 16); // cons
    goto v_16171;
v_16172:
    v_16191 = stack[-8];
    goto v_16173;
v_16174:
    v_16190 = elt(env, 14); // assert_functionl!*
    goto v_16175;
v_16176:
    goto v_16170;
v_16171:
    goto v_16172;
v_16173:
    goto v_16174;
v_16175:
    v_16190 = list3(v_16192, v_16191, v_16190);
    env = stack[-12];
    goto v_16165;
v_16166:
    goto v_16160;
v_16161:
    goto v_16162;
v_16163:
    goto v_16164;
v_16165:
    v_16190 = list3(stack[-1], stack[0], v_16190);
    env = stack[-12];
    goto v_16139;
v_16140:
    goto v_16136;
v_16137:
    goto v_16138;
v_16139:
    v_16190 = list2(stack[-2], v_16190);
    env = stack[-12];
    goto v_16132;
v_16133:
    goto v_16129;
v_16130:
    goto v_16131;
v_16132:
    v_16191 = list2(stack[-3], v_16190);
    env = stack[-12];
    goto v_16124;
v_16125:
    v_16190 = stack[-10];
    goto v_16126;
v_16127:
    goto v_16123;
v_16124:
    goto v_16125;
v_16126:
    v_16190 = cons(v_16191, v_16190);
    env = stack[-12];
    stack[-10] = v_16190;
    goto v_16186;
v_16182:
    v_16191 = elt(env, 17); // progn
    goto v_16183;
v_16184:
    v_16190 = stack[-10];
    v_16190 = Lnreverse(nil, v_16190);
    goto v_16185;
v_16186:
    goto v_16182;
v_16183:
    goto v_16184;
v_16185:
    return cons(v_16191, v_16190);
    return onevalue(v_16190);
}



// Code for sf2mv

static LispObject CC_sf2mv(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_15859, v_15860, v_15861;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15859 = v_15846;
    v_15860 = v_15845;
// end of prologue
    goto v_15855;
v_15849:
    v_15861 = v_15860;
    goto v_15850;
v_15851:
    v_15860 = nil;
    goto v_15852;
v_15853:
    goto v_15854;
v_15855:
    goto v_15849;
v_15850:
    goto v_15851;
v_15852:
    goto v_15853;
v_15854:
    {
        fn = elt(env, 1); // sf2mv1
        return (*qfnn(fn))(fn, 3, v_15861, v_15860, v_15859);
    }
}



// Code for fs!:prepfn!:

static LispObject CC_fsTprepfnT(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15848;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15848 = v_15845;
// end of prologue
    return onevalue(v_15848);
}



// Code for st_consolidate

static LispObject CC_st_consolidate(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15996, v_15997;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_15845;
// end of prologue
    stack[-1] = nil;
    v_15996 = stack[-3];
    if (v_15996 == nil) goto v_15854;
    else goto v_15855;
v_15854:
    v_15996 = nil;
    goto v_15851;
v_15855:
    v_15996 = stack[-3];
    v_15996 = qcdr(v_15996);
    v_15996 = qcar(v_15996);
    if (is_number(v_15996)) goto v_15860;
    else goto v_15861;
v_15860:
    v_15996 = stack[-3];
    goto v_15851;
v_15861:
    v_15996 = lisp_true;
    stack[-2] = v_15996;
    v_15996 = stack[-3];
    v_15996 = qcdr(v_15996);
    v_15996 = Lreverse(nil, v_15996);
    env = stack[-5];
    stack[0] = v_15996;
v_15870:
    v_15996 = stack[0];
    if (v_15996 == nil) goto v_15876;
    else goto v_15877;
v_15876:
    goto v_15869;
v_15877:
    v_15996 = stack[0];
    v_15996 = qcar(v_15996);
    v_15996 = CC_st_consolidate(elt(env, 0), v_15996);
    env = stack[-5];
    v_15997 = v_15996;
    if (v_15997 == nil) goto v_15888;
    v_15997 = v_15996;
    v_15997 = qcdr(v_15997);
    v_15997 = qcdr(v_15997);
    if (v_15997 == nil) goto v_15893;
    v_15997 = nil;
    stack[-2] = v_15997;
    goto v_15891;
v_15893:
    goto v_15905;
v_15901:
    v_15997 = elt(env, 1); // !*
    goto v_15902;
v_15903:
    v_15996 = qcdr(v_15996);
    v_15996 = qcar(v_15996);
    goto v_15904;
v_15905:
    goto v_15901;
v_15902:
    goto v_15903;
v_15904:
    v_15996 = list2(v_15997, v_15996);
    env = stack[-5];
    goto v_15891;
v_15891:
    goto v_15915;
v_15911:
    v_15997 = v_15996;
    goto v_15912;
v_15913:
    v_15996 = stack[-1];
    goto v_15914;
v_15915:
    goto v_15911;
v_15912:
    goto v_15913;
v_15914:
    v_15996 = cons(v_15997, v_15996);
    env = stack[-5];
    stack[-1] = v_15996;
    goto v_15886;
v_15888:
v_15886:
    v_15996 = stack[0];
    v_15996 = qcdr(v_15996);
    stack[0] = v_15996;
    goto v_15870;
v_15869:
    v_15996 = stack[-1];
    if (v_15996 == nil) goto v_15925;
    v_15996 = stack[-1];
    v_15996 = qcdr(v_15996);
    if (v_15996 == nil) goto v_15929;
    else goto v_15930;
v_15929:
    v_15996 = stack[-1];
    v_15996 = qcar(v_15996);
    goto v_15851;
v_15930:
    v_15996 = stack[-2];
    if (v_15996 == nil) goto v_15938;
    v_15996 = stack[-1];
    stack[-4] = v_15996;
    v_15996 = stack[-4];
    if (v_15996 == nil) goto v_15949;
    else goto v_15950;
v_15949:
    v_15996 = nil;
    goto v_15944;
v_15950:
    v_15996 = stack[-4];
    v_15996 = qcar(v_15996);
    v_15996 = qcdr(v_15996);
    v_15996 = qcar(v_15996);
    v_15996 = ncons(v_15996);
    env = stack[-5];
    stack[-1] = v_15996;
    stack[-2] = v_15996;
v_15945:
    v_15996 = stack[-4];
    v_15996 = qcdr(v_15996);
    stack[-4] = v_15996;
    v_15996 = stack[-4];
    if (v_15996 == nil) goto v_15964;
    else goto v_15965;
v_15964:
    v_15996 = stack[-2];
    goto v_15944;
v_15965:
    goto v_15973;
v_15969:
    stack[0] = stack[-1];
    goto v_15970;
v_15971:
    v_15996 = stack[-4];
    v_15996 = qcar(v_15996);
    v_15996 = qcdr(v_15996);
    v_15996 = qcar(v_15996);
    v_15996 = ncons(v_15996);
    env = stack[-5];
    goto v_15972;
v_15973:
    goto v_15969;
v_15970:
    goto v_15971;
v_15972:
    v_15996 = Lrplacd(nil, stack[0], v_15996);
    env = stack[-5];
    v_15996 = stack[-1];
    v_15996 = qcdr(v_15996);
    stack[-1] = v_15996;
    goto v_15945;
v_15944:
    stack[-1] = v_15996;
    goto v_15936;
v_15938:
v_15936:
    goto v_15989;
v_15985:
    v_15996 = stack[-3];
    v_15997 = qcar(v_15996);
    goto v_15986;
v_15987:
    v_15996 = stack[-1];
    goto v_15988;
v_15989:
    goto v_15985;
v_15986:
    goto v_15987;
v_15988:
    return cons(v_15997, v_15996);
v_15925:
    v_15996 = nil;
    goto v_15851;
    v_15996 = nil;
v_15851:
    return onevalue(v_15996);
}



// Code for ratminus

static LispObject CC_ratminus(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15858, v_15859;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_15845;
// end of prologue
    goto v_15852;
v_15848:
    v_15858 = stack[0];
    v_15858 = qcar(v_15858);
    v_15859 = negate(v_15858);
    goto v_15849;
v_15850:
    v_15858 = stack[0];
    v_15858 = qcdr(v_15858);
    goto v_15851;
v_15852:
    goto v_15848;
v_15849:
    goto v_15850;
v_15851:
    return cons(v_15859, v_15858);
}



// Code for all_sml_opchar

static LispObject CC_all_sml_opchar(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15890, v_15891;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15845;
// end of prologue
v_15844:
    v_15890 = stack[0];
    if (v_15890 == nil) goto v_15849;
    else goto v_15850;
v_15849:
    v_15890 = lisp_true;
    goto v_15848;
v_15850:
    goto v_15869;
v_15865:
    v_15891 = qvalue(elt(env, 1)); // lexer_style!*
    goto v_15866;
v_15867:
    v_15890 = (LispObject)2097152+TAG_FIXNUM; // 131072
    goto v_15868;
v_15869:
    goto v_15865;
v_15866:
    goto v_15867;
v_15868:
    fn = elt(env, 3); // land
    v_15890 = (*qfn2(fn))(fn, v_15891, v_15890);
    env = stack[-1];
    v_15890 = (LispObject)zerop(v_15890);
    v_15890 = v_15890 ? lisp_true : nil;
    env = stack[-1];
    if (v_15890 == nil) goto v_15861;
    else goto v_15862;
v_15861:
    goto v_15877;
v_15873:
    v_15890 = stack[0];
    v_15891 = qcar(v_15890);
    goto v_15874;
v_15875:
    v_15890 = elt(env, 2); // sml_opchar
    goto v_15876;
v_15877:
    goto v_15873;
v_15874:
    goto v_15875;
v_15876:
    v_15890 = Lflagp(nil, v_15891, v_15890);
    env = stack[-1];
    goto v_15860;
v_15862:
    v_15890 = nil;
    goto v_15860;
    v_15890 = nil;
v_15860:
    if (v_15890 == nil) goto v_15858;
    v_15890 = stack[0];
    v_15890 = qcdr(v_15890);
    stack[0] = v_15890;
    goto v_15844;
v_15858:
    v_15890 = nil;
    goto v_15856;
    v_15890 = nil;
v_15856:
    goto v_15848;
    v_15890 = nil;
v_15848:
    return onevalue(v_15890);
}



// Code for hasarg

static LispObject CC_hasarg(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_15904, v_15905, v_15906;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15845,v_15846);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15846;
    stack[-1] = v_15845;
// end of prologue
    goto v_15853;
v_15849:
    v_15905 = stack[-1];
    goto v_15850;
v_15851:
    v_15904 = qvalue(elt(env, 1)); // haveargs!*
    goto v_15852;
v_15853:
    goto v_15849;
v_15850:
    goto v_15851;
v_15852:
    v_15904 = cons(v_15905, v_15904);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_15904; // haveargs!*
    goto v_15865;
v_15861:
    v_15905 = stack[0];
    goto v_15862;
v_15863:
    v_15904 = qvalue(elt(env, 2)); // maxarg!*
    goto v_15864;
v_15865:
    goto v_15861;
v_15862:
    goto v_15863;
v_15864:
    v_15904 = (LispObject)greaterp2(v_15905, v_15904);
    v_15904 = v_15904 ? lisp_true : nil;
    env = stack[-2];
    if (v_15904 == nil) goto v_15859;
    v_15904 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 8); // qerline
    v_15904 = (*qfn1(fn))(fn, v_15904);
    env = stack[-2];
    v_15904 = elt(env, 3); // "**** "
    v_15904 = Lprinc(nil, v_15904);
    env = stack[-2];
    v_15904 = stack[-1];
    v_15904 = Lprin(nil, v_15904);
    env = stack[-2];
    v_15904 = elt(env, 4); // " has "
    v_15904 = Lprinc(nil, v_15904);
    env = stack[-2];
    v_15904 = stack[0];
    v_15904 = Lprinc(nil, v_15904);
    env = stack[-2];
    v_15904 = elt(env, 5); // " arguments"
    v_15904 = Lprinc(nil, v_15904);
    env = stack[-2];
    v_15904 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 9); // newline
    v_15904 = (*qfn1(fn))(fn, v_15904);
    env = stack[-2];
    goto v_15857;
v_15859:
v_15857:
    goto v_15890;
v_15886:
    v_15905 = stack[-1];
    goto v_15887;
v_15888:
    v_15904 = elt(env, 6); // bldmsg
    goto v_15889;
v_15890:
    goto v_15886;
v_15887:
    goto v_15888;
v_15889:
    if (v_15905 == v_15904) goto v_15885;
    goto v_15900;
v_15894:
    v_15905 = stack[-1];
    goto v_15895;
v_15896:
    v_15906 = elt(env, 7); // number!-of!-args
    goto v_15897;
v_15898:
    v_15904 = stack[0];
    goto v_15899;
v_15900:
    goto v_15894;
v_15895:
    goto v_15896;
v_15897:
    goto v_15898;
v_15899:
        return Lputprop(nil, 3, v_15905, v_15906, v_15904);
v_15885:
    v_15904 = nil;
    return onevalue(v_15904);
}



// Code for simpexpt11

static LispObject CC_simpexpt11(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15969, v_15970, v_15971;
    LispObject fn;
    LispObject v_15847, v_15846, v_15845;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "simpexpt11");
    va_start(aa, nargs);
    v_15845 = va_arg(aa, LispObject);
    v_15846 = va_arg(aa, LispObject);
    v_15847 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15847,v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15845,v_15846,v_15847);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_15847;
    stack[-2] = v_15846;
    stack[-3] = v_15845;
// end of prologue
    stack[-4] = nil;
    v_15969 = qvalue(elt(env, 1)); // !*precise_complex
    if (v_15969 == nil) goto v_15855;
    goto v_15864;
v_15858:
    v_15971 = stack[-3];
    goto v_15859;
v_15860:
    v_15970 = stack[-2];
    goto v_15861;
v_15862:
    v_15969 = stack[-1];
    goto v_15863;
v_15864:
    goto v_15858;
v_15859:
    goto v_15860;
v_15861:
    goto v_15862;
v_15863:
    {
        fn = elt(env, 2); // simpexpt2
        return (*qfnn(fn))(fn, 3, v_15971, v_15970, v_15969);
    }
v_15855:
    v_15969 = stack[-2];
    v_15969 = qcdr(v_15969);
    if (!consp(v_15969)) goto v_15876;
    else goto v_15877;
v_15876:
    v_15969 = lisp_true;
    goto v_15875;
v_15877:
    v_15969 = stack[-2];
    v_15969 = qcdr(v_15969);
    v_15969 = qcar(v_15969);
    v_15969 = (consp(v_15969) ? nil : lisp_true);
    goto v_15875;
    v_15969 = nil;
v_15875:
    if (v_15969 == nil) goto v_15873;
    v_15969 = lisp_true;
    goto v_15871;
v_15873:
    goto v_15899;
v_15895:
    v_15969 = stack[-2];
    v_15970 = qcar(v_15969);
    goto v_15896;
v_15897:
    v_15969 = stack[-2];
    v_15969 = qcdr(v_15969);
    goto v_15898;
v_15899:
    goto v_15895;
v_15896:
    goto v_15897;
v_15898:
    fn = elt(env, 3); // qremf
    v_15969 = (*qfn2(fn))(fn, v_15970, v_15969);
    env = stack[-5];
    stack[-4] = v_15969;
    v_15969 = qcar(v_15969);
    if (v_15969 == nil) goto v_15892;
    else goto v_15893;
v_15892:
    v_15969 = nil;
    goto v_15891;
v_15893:
    v_15969 = stack[-4];
    v_15969 = qcdr(v_15969);
    goto v_15891;
    v_15969 = nil;
v_15891:
    v_15969 = (v_15969 == nil ? lisp_true : nil);
    goto v_15871;
    v_15969 = nil;
v_15871:
    if (v_15969 == nil) goto v_15869;
    goto v_15918;
v_15912:
    v_15971 = stack[-3];
    goto v_15913;
v_15914:
    v_15970 = stack[-2];
    goto v_15915;
v_15916:
    v_15969 = stack[-1];
    goto v_15917;
v_15918:
    goto v_15912;
v_15913:
    goto v_15914;
v_15915:
    goto v_15916;
v_15917:
    {
        fn = elt(env, 2); // simpexpt2
        return (*qfnn(fn))(fn, 3, v_15971, v_15970, v_15969);
    }
v_15869:
    goto v_15929;
v_15925:
    goto v_15937;
v_15931:
    stack[0] = stack[-3];
    goto v_15932;
v_15933:
    goto v_15944;
v_15940:
    v_15969 = stack[-4];
    v_15970 = qcar(v_15969);
    goto v_15941;
v_15942:
    v_15969 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15943;
v_15944:
    goto v_15940;
v_15941:
    goto v_15942;
v_15943:
    v_15970 = cons(v_15970, v_15969);
    env = stack[-5];
    goto v_15934;
v_15935:
    v_15969 = stack[-1];
    goto v_15936;
v_15937:
    goto v_15931;
v_15932:
    goto v_15933;
v_15934:
    goto v_15935;
v_15936:
    fn = elt(env, 4); // simpexpt1
    stack[0] = (*qfnn(fn))(fn, 3, stack[0], v_15970, v_15969);
    env = stack[-5];
    goto v_15926;
v_15927:
    goto v_15956;
v_15950:
    goto v_15951;
v_15952:
    goto v_15963;
v_15959:
    v_15969 = stack[-4];
    v_15970 = qcdr(v_15969);
    goto v_15960;
v_15961:
    v_15969 = stack[-2];
    v_15969 = qcdr(v_15969);
    goto v_15962;
v_15963:
    goto v_15959;
v_15960:
    goto v_15961;
v_15962:
    v_15970 = cons(v_15970, v_15969);
    env = stack[-5];
    goto v_15953;
v_15954:
    v_15969 = stack[-1];
    goto v_15955;
v_15956:
    goto v_15950;
v_15951:
    goto v_15952;
v_15953:
    goto v_15954;
v_15955:
    fn = elt(env, 4); // simpexpt1
    v_15969 = (*qfnn(fn))(fn, 3, stack[-3], v_15970, v_15969);
    env = stack[-5];
    goto v_15928;
v_15929:
    goto v_15925;
v_15926:
    goto v_15927;
v_15928:
    {
        LispObject v_15977 = stack[0];
        fn = elt(env, 5); // multsq
        return (*qfn2(fn))(fn, v_15977, v_15969);
    }
    v_15969 = nil;
    return onevalue(v_15969);
}



// Code for rndifference!:

static LispObject CC_rndifferenceT(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_15896, v_15897;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15845,v_15846);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15846;
    stack[-1] = v_15845;
// end of prologue
    goto v_15853;
v_15849:
    goto v_15859;
v_15855:
    goto v_15865;
v_15861:
    v_15896 = stack[-1];
    v_15896 = qcdr(v_15896);
    v_15897 = qcar(v_15896);
    goto v_15862;
v_15863:
    v_15896 = stack[0];
    v_15896 = qcdr(v_15896);
    v_15896 = qcdr(v_15896);
    goto v_15864;
v_15865:
    goto v_15861;
v_15862:
    goto v_15863;
v_15864:
    stack[-2] = times2(v_15897, v_15896);
    env = stack[-3];
    goto v_15856;
v_15857:
    goto v_15877;
v_15873:
    v_15896 = stack[-1];
    v_15896 = qcdr(v_15896);
    v_15897 = qcdr(v_15896);
    goto v_15874;
v_15875:
    v_15896 = stack[0];
    v_15896 = qcdr(v_15896);
    v_15896 = qcar(v_15896);
    goto v_15876;
v_15877:
    goto v_15873;
v_15874:
    goto v_15875;
v_15876:
    v_15896 = times2(v_15897, v_15896);
    env = stack[-3];
    goto v_15858;
v_15859:
    goto v_15855;
v_15856:
    goto v_15857;
v_15858:
    stack[-2] = difference2(stack[-2], v_15896);
    env = stack[-3];
    goto v_15850;
v_15851:
    goto v_15889;
v_15885:
    v_15896 = stack[-1];
    v_15896 = qcdr(v_15896);
    v_15897 = qcdr(v_15896);
    goto v_15886;
v_15887:
    v_15896 = stack[0];
    v_15896 = qcdr(v_15896);
    v_15896 = qcdr(v_15896);
    goto v_15888;
v_15889:
    goto v_15885;
v_15886:
    goto v_15887;
v_15888:
    v_15896 = times2(v_15897, v_15896);
    env = stack[-3];
    goto v_15852;
v_15853:
    goto v_15849;
v_15850:
    goto v_15851;
v_15852:
    {
        LispObject v_15901 = stack[-2];
        fn = elt(env, 1); // mkrn
        return (*qfn2(fn))(fn, v_15901, v_15896);
    }
}



// Code for talp_copy

static LispObject CC_talp_copy(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15917, v_15918;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_15918 = v_15845;
// end of prologue
    v_15917 = v_15918;
    if (!consp(v_15917)) goto v_15852;
    else goto v_15853;
v_15852:
    v_15917 = v_15918;
    goto v_15851;
v_15853:
    v_15917 = v_15918;
    stack[-3] = v_15917;
    v_15917 = stack[-3];
    if (v_15917 == nil) goto v_15867;
    else goto v_15868;
v_15867:
    v_15917 = nil;
    goto v_15862;
v_15868:
    v_15917 = stack[-3];
    v_15917 = qcar(v_15917);
    v_15918 = v_15917;
    v_15917 = v_15918;
    if (!consp(v_15917)) goto v_15877;
    else goto v_15878;
v_15877:
    v_15917 = v_15918;
    goto v_15876;
v_15878:
    v_15917 = v_15918;
    v_15917 = CC_talp_copy(elt(env, 0), v_15917);
    env = stack[-4];
    goto v_15876;
    v_15917 = nil;
v_15876:
    v_15917 = ncons(v_15917);
    env = stack[-4];
    stack[-1] = v_15917;
    stack[-2] = v_15917;
v_15863:
    v_15917 = stack[-3];
    v_15917 = qcdr(v_15917);
    stack[-3] = v_15917;
    v_15917 = stack[-3];
    if (v_15917 == nil) goto v_15889;
    else goto v_15890;
v_15889:
    v_15917 = stack[-2];
    goto v_15862;
v_15890:
    goto v_15898;
v_15894:
    stack[0] = stack[-1];
    goto v_15895;
v_15896:
    v_15917 = stack[-3];
    v_15917 = qcar(v_15917);
    v_15918 = v_15917;
    v_15917 = v_15918;
    if (!consp(v_15917)) goto v_15906;
    else goto v_15907;
v_15906:
    v_15917 = v_15918;
    goto v_15905;
v_15907:
    v_15917 = v_15918;
    v_15917 = CC_talp_copy(elt(env, 0), v_15917);
    env = stack[-4];
    goto v_15905;
    v_15917 = nil;
v_15905:
    v_15917 = ncons(v_15917);
    env = stack[-4];
    goto v_15897;
v_15898:
    goto v_15894;
v_15895:
    goto v_15896;
v_15897:
    v_15917 = Lrplacd(nil, stack[0], v_15917);
    env = stack[-4];
    v_15917 = stack[-1];
    v_15917 = qcdr(v_15917);
    stack[-1] = v_15917;
    goto v_15863;
v_15862:
    goto v_15851;
v_15851:
    return onevalue(v_15917);
}



// Code for opfneval

static LispObject CC_opfneval(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15934, v_15935, v_15936;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_15934 = v_15845;
// end of prologue
    goto v_15853;
v_15849:
    v_15935 = v_15934;
    stack[-4] = qcar(v_15935);
    goto v_15850;
v_15851:
    goto v_15871;
v_15867:
    v_15935 = v_15934;
    v_15936 = qcar(v_15935);
    goto v_15868;
v_15869:
    v_15935 = elt(env, 1); // noval
    goto v_15870;
v_15871:
    goto v_15867;
v_15868:
    goto v_15869;
v_15870:
    v_15935 = Lflagp(nil, v_15936, v_15935);
    env = stack[-5];
    if (v_15935 == nil) goto v_15865;
    v_15934 = qcdr(v_15934);
    goto v_15863;
v_15865:
    goto v_15886;
v_15880:
    v_15935 = v_15934;
    v_15935 = qcdr(v_15935);
    goto v_15881;
v_15882:
    goto v_15894;
v_15890:
    v_15936 = qcar(v_15934);
    goto v_15891;
v_15892:
    v_15934 = elt(env, 2); // nosimp
    goto v_15893;
v_15894:
    goto v_15890;
v_15891:
    goto v_15892;
v_15893:
    v_15936 = get(v_15936, v_15934);
    env = stack[-5];
    goto v_15883;
v_15884:
    v_15934 = lisp_true;
    goto v_15885;
v_15886:
    goto v_15880;
v_15881:
    goto v_15882;
v_15883:
    goto v_15884;
v_15885:
    fn = elt(env, 3); // fnreval
    v_15934 = (*qfnn(fn))(fn, 3, v_15935, v_15936, v_15934);
    env = stack[-5];
    goto v_15863;
    v_15934 = nil;
v_15863:
    stack[-3] = v_15934;
    v_15934 = stack[-3];
    if (v_15934 == nil) goto v_15901;
    else goto v_15902;
v_15901:
    v_15934 = nil;
    goto v_15860;
v_15902:
    v_15934 = stack[-3];
    v_15934 = qcar(v_15934);
    v_15934 = Lmkquote(nil, v_15934);
    env = stack[-5];
    v_15934 = ncons(v_15934);
    env = stack[-5];
    stack[-1] = v_15934;
    stack[-2] = v_15934;
v_15861:
    v_15934 = stack[-3];
    v_15934 = qcdr(v_15934);
    stack[-3] = v_15934;
    v_15934 = stack[-3];
    if (v_15934 == nil) goto v_15915;
    else goto v_15916;
v_15915:
    v_15934 = stack[-2];
    goto v_15860;
v_15916:
    goto v_15924;
v_15920:
    stack[0] = stack[-1];
    goto v_15921;
v_15922:
    v_15934 = stack[-3];
    v_15934 = qcar(v_15934);
    v_15934 = Lmkquote(nil, v_15934);
    env = stack[-5];
    v_15934 = ncons(v_15934);
    env = stack[-5];
    goto v_15923;
v_15924:
    goto v_15920;
v_15921:
    goto v_15922;
v_15923:
    v_15934 = Lrplacd(nil, stack[0], v_15934);
    env = stack[-5];
    v_15934 = stack[-1];
    v_15934 = qcdr(v_15934);
    stack[-1] = v_15934;
    goto v_15861;
v_15860:
    goto v_15852;
v_15853:
    goto v_15849;
v_15850:
    goto v_15851;
v_15852:
    v_15934 = cons(stack[-4], v_15934);
    env = stack[-5];
    {
        fn = elt(env, 4); // lispeval
        return (*qfn1(fn))(fn, v_15934);
    }
}



// Code for doublep

static LispObject CC_doublep(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15865, v_15866, v_15867;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15866 = v_15845;
// end of prologue
    goto v_15856;
v_15852:
    v_15865 = v_15866;
    goto v_15853;
v_15854:
    v_15867 = elt(env, 1); // !:rd!:
    goto v_15855;
v_15856:
    goto v_15852;
v_15853:
    goto v_15854;
v_15855:
    if (!consp(v_15865)) goto v_15850;
    v_15865 = qcar(v_15865);
    if (v_15865 == v_15867) goto v_15849;
    else goto v_15850;
v_15849:
    v_15865 = v_15866;
    v_15865 = qcdr(v_15865);
        return Lconsp(nil, v_15865);
v_15850:
    v_15865 = nil;
    goto v_15848;
    v_15865 = nil;
v_15848:
    return onevalue(v_15865);
}



// Code for groebsavelterm

static LispObject CC_groebsavelterm(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15873, v_15874;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15874 = v_15845;
// end of prologue
    v_15873 = qvalue(elt(env, 1)); // !*groelterms
    if (v_15873 == nil) goto v_15850;
    v_15873 = v_15874;
    if (v_15873 == nil) goto v_15856;
    else goto v_15857;
v_15856:
    v_15873 = lisp_true;
    goto v_15855;
v_15857:
    v_15873 = v_15874;
    v_15873 = qcdr(v_15873);
    v_15873 = qcdr(v_15873);
    v_15873 = qcdr(v_15873);
    v_15873 = qcar(v_15873);
    v_15873 = (v_15873 == nil ? lisp_true : nil);
    goto v_15855;
    v_15873 = nil;
v_15855:
    if (v_15873 == nil) goto v_15853;
    else goto v_15850;
v_15853:
    v_15873 = v_15874;
    v_15873 = qcdr(v_15873);
    v_15873 = qcdr(v_15873);
    v_15873 = qcar(v_15873);
    {
        fn = elt(env, 2); // groebsaveltermbc
        return (*qfn1(fn))(fn, v_15873);
    }
v_15850:
    v_15873 = nil;
    return onevalue(v_15873);
}



// Code for physop!-multfnc

static LispObject CC_physopKmultfnc(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_16214, v_16215, v_16216;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15845,v_15846);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_15846;
    stack[-2] = v_15845;
// end of prologue
    goto v_15857;
v_15853:
    v_16214 = stack[-2];
    v_16214 = qcar(v_16214);
    stack[0] = qcdr(v_16214);
    goto v_15854;
v_15855:
    v_16214 = stack[-1];
    v_16214 = qcar(v_16214);
    v_16214 = ncons(v_16214);
    env = stack[-4];
    goto v_15856;
v_15857:
    goto v_15853;
v_15854:
    goto v_15855;
v_15856:
    fn = elt(env, 3); // physop!-multf
    v_16214 = (*qfn2(fn))(fn, stack[0], v_16214);
    env = stack[-4];
    stack[-3] = v_16214;
    v_16214 = stack[-3];
    if (v_16214 == nil) goto v_15866;
    else goto v_15867;
v_15866:
    goto v_15865;
v_15867:
    v_16214 = stack[-3];
    if (!consp(v_16214)) goto v_15878;
    else goto v_15879;
v_15878:
    v_16214 = lisp_true;
    goto v_15877;
v_15879:
    v_16214 = stack[-3];
    v_16214 = qcar(v_16214);
    v_16214 = (consp(v_16214) ? nil : lisp_true);
    goto v_15877;
    v_16214 = nil;
v_15877:
    if (v_16214 == nil) goto v_15874;
    else goto v_15875;
v_15874:
    goto v_15895;
v_15891:
    v_16214 = stack[-3];
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    v_16215 = qcar(v_16214);
    goto v_15892;
v_15893:
    v_16214 = stack[-2];
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    goto v_15894;
v_15895:
    goto v_15891;
v_15892:
    goto v_15893;
v_15894:
    if (v_16215 == v_16214) goto v_15889;
    else goto v_15890;
v_15889:
    v_16214 = stack[-3];
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    fn = elt(env, 4); // physopp
    v_16214 = (*qfn1(fn))(fn, v_16214);
    env = stack[-4];
    if (v_16214 == nil) goto v_15906;
    else goto v_15907;
v_15906:
    v_16214 = lisp_true;
    goto v_15905;
v_15907:
    v_16214 = qvalue(elt(env, 1)); // !*contract2
    goto v_15905;
    v_16214 = nil;
v_15905:
    goto v_15888;
v_15890:
    v_16214 = nil;
    goto v_15888;
    v_16214 = nil;
v_15888:
    goto v_15873;
v_15875:
    v_16214 = nil;
    goto v_15873;
    v_16214 = nil;
v_15873:
    if (v_16214 == nil) goto v_15871;
    goto v_15928;
v_15924:
    goto v_15938;
v_15934:
    v_16214 = stack[-2];
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    stack[0] = qcar(v_16214);
    goto v_15935;
v_15936:
    goto v_15948;
v_15944:
    v_16214 = stack[-2];
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    v_16215 = qcdr(v_16214);
    goto v_15945;
v_15946:
    v_16214 = stack[-3];
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    v_16214 = qcdr(v_16214);
    goto v_15947;
v_15948:
    goto v_15944;
v_15945:
    goto v_15946;
v_15947:
    v_16214 = plus2(v_16215, v_16214);
    env = stack[-4];
    goto v_15937;
v_15938:
    goto v_15934;
v_15935:
    goto v_15936;
v_15937:
    fn = elt(env, 5); // mkspm
    v_16214 = (*qfn2(fn))(fn, stack[0], v_16214);
    env = stack[-4];
    v_16216 = v_16214;
    if (v_16214 == nil) goto v_15931;
    else goto v_15932;
v_15931:
    v_16214 = nil;
    stack[0] = v_16214;
    goto v_15930;
v_15932:
    goto v_15964;
v_15960:
    v_16215 = v_16216;
    goto v_15961;
v_15962:
    v_16214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15963;
v_15964:
    goto v_15960;
v_15961:
    goto v_15962;
v_15963:
    if (v_16215 == v_16214) goto v_15958;
    else goto v_15959;
v_15958:
    v_16214 = stack[-3];
    v_16214 = qcar(v_16214);
    v_16214 = qcdr(v_16214);
    stack[0] = v_16214;
    goto v_15930;
v_15959:
    goto v_15978;
v_15974:
    v_16215 = v_16216;
    goto v_15975;
v_15976:
    v_16214 = stack[-3];
    v_16214 = qcar(v_16214);
    v_16214 = qcdr(v_16214);
    goto v_15977;
v_15978:
    goto v_15974;
v_15975:
    goto v_15976;
v_15977:
    v_16214 = cons(v_16215, v_16214);
    env = stack[-4];
    v_16214 = ncons(v_16214);
    env = stack[-4];
    stack[0] = v_16214;
    goto v_15930;
    stack[0] = nil;
v_15930:
    goto v_15925;
v_15926:
    goto v_15988;
v_15984:
    goto v_15995;
v_15991:
    v_16214 = stack[-2];
    v_16214 = qcar(v_16214);
    v_16215 = qcar(v_16214);
    goto v_15992;
v_15993:
    v_16214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15994;
v_15995:
    goto v_15991;
v_15992:
    goto v_15993;
v_15994:
    v_16214 = cons(v_16215, v_16214);
    env = stack[-4];
    v_16215 = ncons(v_16214);
    env = stack[-4];
    goto v_15985;
v_15986:
    v_16214 = stack[-3];
    v_16214 = qcdr(v_16214);
    goto v_15987;
v_15988:
    goto v_15984;
v_15985:
    goto v_15986;
v_15987:
    fn = elt(env, 3); // physop!-multf
    v_16214 = (*qfn2(fn))(fn, v_16215, v_16214);
    env = stack[-4];
    goto v_15927;
v_15928:
    goto v_15924;
v_15925:
    goto v_15926;
v_15927:
    fn = elt(env, 6); // addf
    v_16214 = (*qfn2(fn))(fn, stack[0], v_16214);
    env = stack[-4];
    stack[-3] = v_16214;
    goto v_15865;
v_15871:
    v_16214 = stack[-2];
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    if (!consp(v_16214)) goto v_16006;
    else goto v_16007;
v_16006:
    v_16214 = stack[-2];
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    if (!symbolp(v_16214)) v_16214 = nil;
    else { v_16214 = qfastgets(v_16214);
           if (v_16214 != nil) { v_16214 = elt(v_16214, 0); // noncom
#ifdef RECORD_GET
             if (v_16214 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_16214 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_16214 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_16214 == SPID_NOPROP) v_16214 = nil; else v_16214 = lisp_true; }}
#endif
    goto v_16005;
v_16007:
    v_16214 = stack[-2];
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    if (!symbolp(v_16214)) v_16214 = nil;
    else { v_16214 = qfastgets(v_16214);
           if (v_16214 != nil) { v_16214 = elt(v_16214, 0); // noncom
#ifdef RECORD_GET
             if (v_16214 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_16214 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_16214 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_16214 == SPID_NOPROP) v_16214 = nil; else v_16214 = lisp_true; }}
#endif
    goto v_16005;
    v_16214 = nil;
v_16005:
    if (v_16214 == nil) goto v_16003;
    goto v_16038;
v_16034:
    v_16214 = stack[-2];
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    v_16215 = qcar(v_16214);
    goto v_16035;
v_16036:
    v_16214 = stack[-3];
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    goto v_16037;
v_16038:
    goto v_16034;
v_16035:
    goto v_16036;
v_16037:
    fn = elt(env, 7); // noncommuting
    v_16214 = (*qfn2(fn))(fn, v_16215, v_16214);
    env = stack[-4];
    if (v_16214 == nil) goto v_16031;
    else goto v_16032;
v_16031:
    goto v_16052;
v_16048:
    v_16214 = stack[-2];
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    v_16215 = qcar(v_16214);
    goto v_16049;
v_16050:
    v_16214 = stack[-3];
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    goto v_16051;
v_16052:
    goto v_16048;
v_16049:
    goto v_16050;
v_16051:
    fn = elt(env, 8); // physop!-ordop
    v_16214 = (*qfn2(fn))(fn, v_16215, v_16214);
    env = stack[-4];
    v_16214 = (v_16214 == nil ? lisp_true : nil);
    goto v_16030;
v_16032:
    v_16214 = nil;
    goto v_16030;
    v_16214 = nil;
v_16030:
    if (v_16214 == nil) goto v_16028;
    goto v_16074;
v_16070:
    goto v_16081;
v_16077:
    v_16214 = stack[-2];
    v_16214 = qcar(v_16214);
    v_16215 = qcar(v_16214);
    goto v_16078;
v_16079:
    v_16214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16080;
v_16081:
    goto v_16077;
v_16078:
    goto v_16079;
v_16080:
    v_16214 = cons(v_16215, v_16214);
    env = stack[-4];
    v_16215 = ncons(v_16214);
    env = stack[-4];
    goto v_16071;
v_16072:
    v_16214 = stack[-3];
    v_16214 = qcar(v_16214);
    v_16214 = qcdr(v_16214);
    goto v_16073;
v_16074:
    goto v_16070;
v_16071:
    goto v_16072;
v_16073:
    fn = elt(env, 3); // physop!-multf
    v_16214 = (*qfn2(fn))(fn, v_16215, v_16214);
    env = stack[-4];
    v_16216 = v_16214;
    if (v_16214 == nil) goto v_16067;
    else goto v_16068;
v_16067:
    goto v_16094;
v_16090:
    goto v_16101;
v_16097:
    v_16214 = stack[-2];
    v_16214 = qcar(v_16214);
    v_16215 = qcar(v_16214);
    goto v_16098;
v_16099:
    v_16214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16100;
v_16101:
    goto v_16097;
v_16098:
    goto v_16099;
v_16100:
    v_16214 = cons(v_16215, v_16214);
    env = stack[-4];
    v_16215 = ncons(v_16214);
    env = stack[-4];
    goto v_16091;
v_16092:
    v_16214 = stack[-3];
    v_16214 = qcdr(v_16214);
    goto v_16093;
v_16094:
    goto v_16090;
v_16091:
    goto v_16092;
v_16093:
    fn = elt(env, 3); // physop!-multf
    v_16214 = (*qfn2(fn))(fn, v_16215, v_16214);
    env = stack[-4];
    stack[-3] = v_16214;
    goto v_16066;
v_16068:
    goto v_16115;
v_16111:
    goto v_16122;
v_16118:
    v_16214 = stack[-3];
    v_16214 = qcar(v_16214);
    v_16214 = qcar(v_16214);
    goto v_16119;
v_16120:
    v_16215 = v_16216;
    goto v_16121;
v_16122:
    goto v_16118;
v_16119:
    goto v_16120;
v_16121:
    v_16214 = cons(v_16214, v_16215);
    env = stack[-4];
    stack[0] = ncons(v_16214);
    env = stack[-4];
    goto v_16112;
v_16113:
    goto v_16132;
v_16128:
    goto v_16139;
v_16135:
    v_16214 = stack[-2];
    v_16214 = qcar(v_16214);
    v_16215 = qcar(v_16214);
    goto v_16136;
v_16137:
    v_16214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16138;
v_16139:
    goto v_16135;
v_16136:
    goto v_16137;
v_16138:
    v_16214 = cons(v_16215, v_16214);
    env = stack[-4];
    v_16215 = ncons(v_16214);
    env = stack[-4];
    goto v_16129;
v_16130:
    v_16214 = stack[-3];
    v_16214 = qcdr(v_16214);
    goto v_16131;
v_16132:
    goto v_16128;
v_16129:
    goto v_16130;
v_16131:
    fn = elt(env, 3); // physop!-multf
    v_16214 = (*qfn2(fn))(fn, v_16215, v_16214);
    env = stack[-4];
    goto v_16114;
v_16115:
    goto v_16111;
v_16112:
    goto v_16113;
v_16114:
    fn = elt(env, 6); // addf
    v_16214 = (*qfn2(fn))(fn, stack[0], v_16214);
    env = stack[-4];
    stack[-3] = v_16214;
    goto v_16066;
v_16066:
    goto v_16026;
v_16028:
    goto v_16154;
v_16150:
    v_16214 = stack[-2];
    v_16214 = qcar(v_16214);
    v_16215 = qcar(v_16214);
    goto v_16151;
v_16152:
    v_16214 = stack[-3];
    goto v_16153;
v_16154:
    goto v_16150;
v_16151:
    goto v_16152;
v_16153:
    v_16214 = cons(v_16215, v_16214);
    env = stack[-4];
    v_16214 = ncons(v_16214);
    env = stack[-4];
    stack[-3] = v_16214;
    goto v_16026;
v_16026:
    goto v_15865;
v_16003:
    v_16214 = lisp_true;
// Binding !*!*processed
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 2, 0);
    qvalue(elt(env, 2)) = v_16214; // !*!*processed
    goto v_16168;
v_16164:
    goto v_16175;
v_16171:
    v_16214 = stack[-2];
    v_16214 = qcar(v_16214);
    v_16215 = qcar(v_16214);
    goto v_16172;
v_16173:
    v_16214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16174;
v_16175:
    goto v_16171;
v_16172:
    goto v_16173;
v_16174:
    v_16214 = cons(v_16215, v_16214);
    env = stack[-4];
    v_16215 = ncons(v_16214);
    env = stack[-4];
    goto v_16165;
v_16166:
    v_16214 = stack[-3];
    goto v_16167;
v_16168:
    goto v_16164;
v_16165:
    goto v_16166;
v_16167:
    fn = elt(env, 3); // physop!-multf
    v_16214 = (*qfn2(fn))(fn, v_16215, v_16214);
    env = stack[-4];
    stack[-3] = v_16214;
    ;}  // end of a binding scope
    goto v_15865;
v_15865:
    goto v_16186;
v_16182:
    goto v_16183;
v_16184:
    goto v_16193;
v_16189:
    goto v_16199;
v_16195:
    v_16214 = stack[-2];
    v_16215 = qcdr(v_16214);
    goto v_16196;
v_16197:
    v_16214 = stack[-1];
    goto v_16198;
v_16199:
    goto v_16195;
v_16196:
    goto v_16197;
v_16198:
    fn = elt(env, 3); // physop!-multf
    stack[0] = (*qfn2(fn))(fn, v_16215, v_16214);
    env = stack[-4];
    goto v_16190;
v_16191:
    goto v_16208;
v_16204:
    v_16214 = stack[-2];
    v_16214 = qcar(v_16214);
    v_16215 = ncons(v_16214);
    env = stack[-4];
    goto v_16205;
v_16206:
    v_16214 = stack[-1];
    v_16214 = qcdr(v_16214);
    goto v_16207;
v_16208:
    goto v_16204;
v_16205:
    goto v_16206;
v_16207:
    fn = elt(env, 3); // physop!-multf
    v_16214 = (*qfn2(fn))(fn, v_16215, v_16214);
    env = stack[-4];
    goto v_16192;
v_16193:
    goto v_16189;
v_16190:
    goto v_16191;
v_16192:
    fn = elt(env, 6); // addf
    v_16214 = (*qfn2(fn))(fn, stack[0], v_16214);
    env = stack[-4];
    goto v_16185;
v_16186:
    goto v_16182;
v_16183:
    goto v_16184;
v_16185:
    {
        LispObject v_16221 = stack[-3];
        fn = elt(env, 6); // addf
        return (*qfn2(fn))(fn, v_16221, v_16214);
    }
    return onevalue(v_16214);
}



// Code for red_tailred

static LispObject CC_red_tailred(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_15877, v_15878, v_15879;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15877 = v_15846;
    v_15879 = v_15845;
// end of prologue
    v_15878 = qvalue(elt(env, 1)); // !*noetherian
    if (v_15878 == nil) goto v_15851;
    goto v_15860;
v_15854:
    goto v_15855;
v_15856:
    v_15878 = v_15877;
    goto v_15857;
v_15858:
    v_15877 = elt(env, 2); // red_topred
    goto v_15859;
v_15860:
    goto v_15854;
v_15855:
    goto v_15856;
v_15857:
    goto v_15858;
v_15859:
    {
        fn = elt(env, 4); // red_tailreddriver
        return (*qfnn(fn))(fn, 3, v_15879, v_15878, v_15877);
    }
v_15851:
    goto v_15873;
v_15867:
    goto v_15868;
v_15869:
    v_15878 = v_15877;
    goto v_15870;
v_15871:
    v_15877 = elt(env, 3); // red_topredbe
    goto v_15872;
v_15873:
    goto v_15867;
v_15868:
    goto v_15869;
v_15870:
    goto v_15871;
v_15872:
    {
        fn = elt(env, 4); // red_tailreddriver
        return (*qfnn(fn))(fn, 3, v_15879, v_15878, v_15877);
    }
    v_15877 = nil;
    return onevalue(v_15877);
}



// Code for ifstat

static LispObject CC_ifstat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15935, v_15936;
    LispObject fn;
    argcheck(nargs, 0, "ifstat");
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
    stack[-1] = nil;
v_15850:
    v_15935 = lisp_true;
    fn = elt(env, 6); // xread
    v_15935 = (*qfn1(fn))(fn, v_15935);
    env = stack[-2];
    stack[0] = v_15935;
    goto v_15861;
v_15857:
    v_15936 = qvalue(elt(env, 1)); // cursym!*
    goto v_15858;
v_15859:
    v_15935 = elt(env, 2); // then
    goto v_15860;
v_15861:
    goto v_15857;
v_15858:
    goto v_15859;
v_15860:
    if (v_15936 == v_15935) goto v_15856;
    goto v_15869;
v_15865:
    v_15936 = elt(env, 3); // if
    goto v_15866;
v_15867:
    v_15935 = lisp_true;
    goto v_15868;
v_15869:
    goto v_15865;
v_15866:
    goto v_15867;
v_15868:
    fn = elt(env, 7); // symerr
    v_15935 = (*qfn2(fn))(fn, v_15936, v_15935);
    env = stack[-2];
    goto v_15854;
v_15856:
v_15854:
    goto v_15877;
v_15873:
    goto v_15874;
v_15875:
    goto v_15884;
v_15880:
    goto v_15881;
v_15882:
    v_15935 = lisp_true;
    fn = elt(env, 6); // xread
    v_15935 = (*qfn1(fn))(fn, v_15935);
    env = stack[-2];
    goto v_15883;
v_15884:
    goto v_15880;
v_15881:
    goto v_15882;
v_15883:
    v_15935 = list2(stack[0], v_15935);
    env = stack[-2];
    goto v_15876;
v_15877:
    goto v_15873;
v_15874:
    goto v_15875;
v_15876:
    fn = elt(env, 8); // aconc!*
    v_15935 = (*qfn2(fn))(fn, stack[-1], v_15935);
    env = stack[-2];
    stack[-1] = v_15935;
    goto v_15896;
v_15892:
    v_15936 = qvalue(elt(env, 1)); // cursym!*
    goto v_15893;
v_15894:
    v_15935 = elt(env, 4); // else
    goto v_15895;
v_15896:
    goto v_15892;
v_15893:
    goto v_15894;
v_15895:
    if (v_15936 == v_15935) goto v_15891;
    goto v_15889;
v_15891:
    goto v_15906;
v_15902:
    fn = elt(env, 9); // scan
    v_15936 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_15903;
v_15904:
    v_15935 = elt(env, 3); // if
    goto v_15905;
v_15906:
    goto v_15902;
v_15903:
    goto v_15904;
v_15905:
    if (v_15936 == v_15935) goto v_15900;
    else goto v_15901;
v_15900:
    goto v_15850;
v_15901:
    goto v_15916;
v_15912:
    goto v_15913;
v_15914:
    goto v_15923;
v_15919:
    stack[0] = lisp_true;
    goto v_15920;
v_15921:
    v_15935 = lisp_true;
    fn = elt(env, 10); // xread1
    v_15935 = (*qfn1(fn))(fn, v_15935);
    env = stack[-2];
    goto v_15922;
v_15923:
    goto v_15919;
v_15920:
    goto v_15921;
v_15922:
    v_15935 = list2(stack[0], v_15935);
    env = stack[-2];
    goto v_15915;
v_15916:
    goto v_15912;
v_15913:
    goto v_15914;
v_15915:
    fn = elt(env, 8); // aconc!*
    v_15935 = (*qfn2(fn))(fn, stack[-1], v_15935);
    env = stack[-2];
    stack[-1] = v_15935;
    goto v_15889;
v_15889:
    goto v_15932;
v_15928:
    v_15936 = elt(env, 5); // cond
    goto v_15929;
v_15930:
    v_15935 = stack[-1];
    goto v_15931;
v_15932:
    goto v_15928;
v_15929:
    goto v_15930;
v_15931:
    return cons(v_15936, v_15935);
    return onevalue(v_15935);
}



// Code for tayexp!-minus

static LispObject CC_tayexpKminus(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15858, v_15859;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15859 = v_15845;
// end of prologue
    v_15858 = v_15859;
    if (!consp(v_15858)) goto v_15849;
    else goto v_15850;
v_15849:
    v_15858 = v_15859;
    return negate(v_15858);
v_15850:
    v_15858 = v_15859;
    {
        fn = elt(env, 1); // rnminus!:
        return (*qfn1(fn))(fn, v_15858);
    }
    v_15858 = nil;
    return onevalue(v_15858);
}



// Code for mk!+trace

static LispObject CC_mkLtrace(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15912, v_15913, v_15914;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_15845;
// end of prologue
    v_15912 = stack[-1];
    fn = elt(env, 3); // squared!+matrix!+p
    v_15912 = (*qfn1(fn))(fn, v_15912);
    env = stack[-3];
    if (v_15912 == nil) goto v_15853;
    else goto v_15854;
v_15853:
    v_15912 = elt(env, 1); // "no square matrix in add"
    fn = elt(env, 4); // rederr
    v_15912 = (*qfn1(fn))(fn, v_15912);
    env = stack[-3];
    goto v_15852;
v_15854:
v_15852:
    goto v_15864;
v_15860:
    v_15913 = nil;
    goto v_15861;
v_15862:
    v_15912 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15863;
v_15864:
    goto v_15860;
v_15861:
    goto v_15862;
v_15863:
    v_15912 = cons(v_15913, v_15912);
    env = stack[-3];
    stack[0] = v_15912;
    v_15912 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_15912;
v_15870:
    goto v_15882;
v_15878:
    v_15912 = stack[-1];
    fn = elt(env, 5); // get!+row!+nr
    v_15913 = (*qfn1(fn))(fn, v_15912);
    env = stack[-3];
    goto v_15879;
v_15880:
    v_15912 = stack[-2];
    goto v_15881;
v_15882:
    goto v_15878;
v_15879:
    goto v_15880;
v_15881:
    v_15912 = difference2(v_15913, v_15912);
    env = stack[-3];
    v_15912 = Lminusp(nil, v_15912);
    env = stack[-3];
    if (v_15912 == nil) goto v_15875;
    goto v_15869;
v_15875:
    goto v_15892;
v_15888:
    goto v_15889;
v_15890:
    goto v_15901;
v_15895:
    v_15914 = stack[-1];
    goto v_15896;
v_15897:
    v_15913 = stack[-2];
    goto v_15898;
v_15899:
    v_15912 = stack[-2];
    goto v_15900;
v_15901:
    goto v_15895;
v_15896:
    goto v_15897;
v_15898:
    goto v_15899;
v_15900:
    fn = elt(env, 6); // get!+mat!+entry
    v_15912 = (*qfnn(fn))(fn, 3, v_15914, v_15913, v_15912);
    env = stack[-3];
    goto v_15891;
v_15892:
    goto v_15888;
v_15889:
    goto v_15890;
v_15891:
    fn = elt(env, 7); // addsq
    v_15912 = (*qfn2(fn))(fn, stack[0], v_15912);
    env = stack[-3];
    stack[0] = v_15912;
    v_15912 = stack[-2];
    v_15912 = add1(v_15912);
    env = stack[-3];
    stack[-2] = v_15912;
    goto v_15870;
v_15869:
    v_15912 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-3, 2, -1);
    qvalue(elt(env, 2)) = v_15912; // !*sub2
    v_15912 = stack[0];
    fn = elt(env, 8); // subs2
    v_15912 = (*qfn1(fn))(fn, v_15912);
    stack[0] = v_15912;
    ;}  // end of a binding scope
    v_15912 = stack[0];
    return onevalue(v_15912);
}



// Code for talp_specsubat

static LispObject CC_talp_specsubat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15884;
    LispObject fn;
    LispObject v_15847, v_15846, v_15845;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_specsubat");
    va_start(aa, nargs);
    v_15845 = va_arg(aa, LispObject);
    v_15846 = va_arg(aa, LispObject);
    v_15847 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15847,v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15845,v_15846,v_15847);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_15847;
    stack[-3] = v_15846;
    stack[-4] = v_15845;
// end of prologue
    goto v_15857;
v_15851:
    v_15884 = stack[-2];
    fn = elt(env, 1); // talp_op
    stack[-5] = (*qfn1(fn))(fn, v_15884);
    env = stack[-6];
    goto v_15852;
v_15853:
    goto v_15867;
v_15861:
    stack[-1] = stack[-4];
    goto v_15862;
v_15863:
    stack[0] = stack[-3];
    goto v_15864;
v_15865:
    v_15884 = stack[-2];
    fn = elt(env, 2); // talp_arg2l
    v_15884 = (*qfn1(fn))(fn, v_15884);
    env = stack[-6];
    goto v_15866;
v_15867:
    goto v_15861;
v_15862:
    goto v_15863;
v_15864:
    goto v_15865;
v_15866:
    fn = elt(env, 3); // talp_specsubt
    stack[0] = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_15884);
    env = stack[-6];
    goto v_15854;
v_15855:
    goto v_15879;
v_15873:
    stack[-1] = stack[-4];
    goto v_15874;
v_15875:
    goto v_15876;
v_15877:
    v_15884 = stack[-2];
    fn = elt(env, 4); // talp_arg2r
    v_15884 = (*qfn1(fn))(fn, v_15884);
    env = stack[-6];
    goto v_15878;
v_15879:
    goto v_15873;
v_15874:
    goto v_15875;
v_15876:
    goto v_15877;
v_15878:
    fn = elt(env, 3); // talp_specsubt
    v_15884 = (*qfnn(fn))(fn, 3, stack[-1], stack[-3], v_15884);
    env = stack[-6];
    goto v_15856;
v_15857:
    goto v_15851;
v_15852:
    goto v_15853;
v_15854:
    goto v_15855;
v_15856:
    fn = elt(env, 5); // talp_mk2
    v_15884 = (*qfnn(fn))(fn, 3, stack[-5], stack[0], v_15884);
    env = stack[-6];
    {
        fn = elt(env, 6); // talp_simpat
        return (*qfn1(fn))(fn, v_15884);
    }
}



// Code for qqe_arg!-check!-q

static LispObject CC_qqe_argKcheckKq(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15897;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15845;
// end of prologue
    v_15897 = stack[0];
    fn = elt(env, 1); // qqe_id!-nyt!-branchq
    v_15897 = (*qfn1(fn))(fn, v_15897);
    env = stack[-1];
    if (v_15897 == nil) goto v_15851;
    else goto v_15852;
v_15851:
    v_15897 = nil;
    goto v_15848;
v_15852:
    v_15897 = stack[0];
    if (!consp(v_15897)) goto v_15860;
    else goto v_15861;
v_15860:
    v_15897 = stack[0];
    v_15897 = (is_number(v_15897) ? lisp_true : nil);
    v_15897 = (v_15897 == nil ? lisp_true : nil);
    goto v_15859;
v_15861:
    v_15897 = nil;
    goto v_15859;
    v_15897 = nil;
v_15859:
    if (v_15897 == nil) goto v_15857;
    v_15897 = stack[0];
    fn = elt(env, 2); // qqe_btidp
    v_15897 = (*qfn1(fn))(fn, v_15897);
    env = stack[-1];
    if (v_15897 == nil) goto v_15872;
    v_15897 = nil;
    goto v_15848;
v_15872:
    v_15897 = stack[0];
    fn = elt(env, 3); // qqe_nytidp
    v_15897 = (*qfn1(fn))(fn, v_15897);
    env = stack[-1];
    if (v_15897 == nil) goto v_15877;
    v_15897 = stack[0];
    fn = elt(env, 4); // qqe_qtid
    v_15897 = (*qfn1(fn))(fn, v_15897);
    env = stack[-1];
    v_15897 = stack[0];
    fn = elt(env, 5); // qqe_add2rollbackids
    v_15897 = (*qfn1(fn))(fn, v_15897);
    v_15897 = lisp_true;
    goto v_15848;
v_15877:
    v_15897 = lisp_true;
    goto v_15848;
    goto v_15850;
v_15857:
    v_15897 = stack[0];
    if (is_number(v_15897)) goto v_15891;
    v_15897 = stack[0];
    fn = elt(env, 6); // qqe_arg!-check
    v_15897 = (*qfn1(fn))(fn, v_15897);
    v_15897 = lisp_true;
    goto v_15848;
v_15891:
v_15850:
    v_15897 = nil;
v_15848:
    return onevalue(v_15897);
}



// Code for pasf_sisub!-gand

static LispObject CC_pasf_sisubKgand(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15965, v_15966, v_15967;
    LispObject fn;
    LispObject v_15850, v_15849, v_15848, v_15847, v_15846, v_15845;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "pasf_sisub-gand");
    va_start(aa, nargs);
    v_15845 = va_arg(aa, LispObject);
    v_15846 = va_arg(aa, LispObject);
    v_15847 = va_arg(aa, LispObject);
    v_15848 = va_arg(aa, LispObject);
    v_15849 = va_arg(aa, LispObject);
    v_15850 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_15850,v_15849,v_15848,v_15847,v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_15845,v_15846,v_15847,v_15848,v_15849,v_15850);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-1] = v_15850;
    stack[-2] = v_15849;
    stack[-3] = v_15848;
    stack[-4] = v_15847;
    stack[-5] = v_15846;
    stack[-6] = v_15845;
// end of prologue
    stack[0] = nil;
    v_15965 = lisp_true;
    stack[-7] = v_15965;
v_15861:
    v_15965 = stack[-7];
    if (v_15965 == nil) goto v_15864;
    v_15965 = stack[-5];
    if (v_15965 == nil) goto v_15864;
    goto v_15865;
v_15864:
    goto v_15860;
v_15865:
    v_15965 = stack[-5];
    v_15965 = qcar(v_15965);
    v_15966 = v_15965;
    v_15965 = stack[-5];
    v_15965 = qcdr(v_15965);
    stack[-5] = v_15965;
    v_15965 = v_15966;
    goto v_15887;
v_15881:
    v_15967 = v_15965;
    goto v_15882;
v_15883:
    v_15966 = stack[-4];
    goto v_15884;
v_15885:
    v_15965 = stack[-3];
    goto v_15886;
v_15887:
    goto v_15881;
v_15882:
    goto v_15883;
v_15884:
    goto v_15885;
v_15886:
    fn = elt(env, 4); // pasf_sisub
    v_15965 = (*qfnn(fn))(fn, 3, v_15967, v_15966, v_15965);
    env = stack[-8];
    v_15967 = v_15965;
    goto v_15899;
v_15895:
    v_15966 = v_15967;
    goto v_15896;
v_15897:
    v_15965 = stack[-1];
    goto v_15898;
v_15899:
    goto v_15895;
v_15896:
    goto v_15897;
v_15898:
    if (v_15966 == v_15965) goto v_15893;
    else goto v_15894;
v_15893:
    v_15965 = nil;
    stack[-7] = v_15965;
    goto v_15892;
v_15894:
    goto v_15909;
v_15905:
    v_15966 = v_15967;
    goto v_15906;
v_15907:
    v_15965 = stack[-2];
    goto v_15908;
v_15909:
    goto v_15905;
v_15906:
    goto v_15907;
v_15908:
    if (equal(v_15966, v_15965)) goto v_15904;
    goto v_15917;
v_15913:
    v_15966 = v_15967;
    goto v_15914;
v_15915:
    v_15965 = stack[0];
    goto v_15916;
v_15917:
    goto v_15913;
v_15914:
    goto v_15915;
v_15916:
    v_15965 = cons(v_15966, v_15965);
    env = stack[-8];
    stack[0] = v_15965;
    goto v_15892;
v_15904:
v_15892:
    goto v_15861;
v_15860:
    v_15965 = stack[-7];
    if (v_15965 == nil) goto v_15922;
    else goto v_15923;
v_15922:
    v_15965 = stack[-1];
    goto v_15857;
v_15923:
    v_15965 = stack[0];
    if (v_15965 == nil) goto v_15929;
    v_15965 = stack[0];
    v_15965 = qcdr(v_15965);
    if (v_15965 == nil) goto v_15929;
    goto v_15940;
v_15936:
    v_15966 = stack[-6];
    goto v_15937;
v_15938:
    v_15965 = stack[0];
    goto v_15939;
v_15940:
    goto v_15936;
v_15937:
    goto v_15938;
v_15939:
    return cons(v_15966, v_15965);
v_15929:
    v_15965 = stack[0];
    if (v_15965 == nil) goto v_15943;
    else goto v_15944;
v_15943:
    goto v_15954;
v_15950:
    v_15966 = stack[-6];
    goto v_15951;
v_15952:
    v_15965 = elt(env, 1); // and
    goto v_15953;
v_15954:
    goto v_15950;
v_15951:
    goto v_15952;
v_15953:
    if (v_15966 == v_15965) goto v_15948;
    else goto v_15949;
v_15948:
    v_15965 = elt(env, 2); // true
    goto v_15947;
v_15949:
    v_15965 = elt(env, 3); // false
    goto v_15947;
    v_15965 = nil;
v_15947:
    goto v_15927;
v_15944:
    v_15965 = stack[0];
    v_15965 = qcar(v_15965);
    goto v_15927;
    v_15965 = nil;
v_15927:
v_15857:
    return onevalue(v_15965);
}



// Code for vdp_sugar

static LispObject CC_vdp_sugar(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15871, v_15872;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15845;
// end of prologue
    v_15871 = stack[0];
    fn = elt(env, 3); // vdp_zero!?
    v_15871 = (*qfn1(fn))(fn, v_15871);
    env = stack[-1];
    if (v_15871 == nil) goto v_15851;
    else goto v_15849;
v_15851:
    v_15871 = qvalue(elt(env, 1)); // !*cgbsugar
    if (v_15871 == nil) goto v_15849;
    goto v_15850;
v_15849:
    v_15871 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15848;
v_15850:
    goto v_15867;
v_15863:
    v_15872 = stack[0];
    goto v_15864;
v_15865:
    v_15871 = elt(env, 2); // sugar
    goto v_15866;
v_15867:
    goto v_15863;
v_15864:
    goto v_15865;
v_15866:
    fn = elt(env, 4); // vdp_getprop
    v_15871 = (*qfn2(fn))(fn, v_15872, v_15871);
    if (v_15871 == nil) goto v_15861;
    else goto v_15860;
v_15861:
    v_15871 = (LispObject)0+TAG_FIXNUM; // 0
v_15860:
    goto v_15848;
    v_15871 = nil;
v_15848:
    return onevalue(v_15871);
}



// Code for dm!-mkfloat

static LispObject CC_dmKmkfloat(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15865, v_15866;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15865 = v_15845;
// end of prologue
    v_15866 = v_15865;
    v_15866 = Lintegerp(nil, v_15866);
    env = stack[0];
    if (v_15866 == nil) goto v_15850;
    goto v_15858;
v_15854:
    v_15866 = elt(env, 1); // !:rd!:
    if (!symbolp(v_15866)) v_15866 = nil;
    else { v_15866 = qfastgets(v_15866);
           if (v_15866 != nil) { v_15866 = elt(v_15866, 34); // i2d
#ifdef RECORD_GET
             if (v_15866 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_15866 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_15866 == SPID_NOPROP) v_15866 = nil; }}
#endif
    goto v_15855;
v_15856:
    goto v_15857;
v_15858:
    goto v_15854;
v_15855:
    goto v_15856;
v_15857:
        return Lapply1(nil, v_15866, v_15865);
v_15850:
    goto v_15848;
    v_15865 = nil;
v_15848:
    return onevalue(v_15865);
}



// Code for sc_geq

static LispObject CC_sc_geq(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_15858, v_15859;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15845,v_15846);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15858 = v_15846;
    v_15859 = v_15845;
// end of prologue
    goto v_15854;
v_15850:
    goto v_15851;
v_15852:
    goto v_15853;
v_15854:
    goto v_15850;
v_15851:
    goto v_15852;
v_15853:
    fn = elt(env, 1); // sc_subtrsq
    v_15858 = (*qfn2(fn))(fn, v_15859, v_15858);
    env = stack[0];
    fn = elt(env, 2); // sc_minussq
    v_15858 = (*qfn1(fn))(fn, v_15858);
    v_15858 = (v_15858 == nil ? lisp_true : nil);
    return onevalue(v_15858);
}



// Code for bcfd

static LispObject CC_bcfd(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15890, v_15891, v_15892;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15892 = v_15845;
// end of prologue
    v_15890 = qvalue(elt(env, 1)); // !*grmod!*
    if (v_15890 == nil) goto v_15849;
    else goto v_15850;
v_15849:
    goto v_15857;
v_15853:
    v_15891 = v_15892;
    goto v_15854;
v_15855:
    v_15890 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15856;
v_15857:
    goto v_15853;
v_15854:
    goto v_15855;
v_15856:
    {
        fn = elt(env, 4); // mkbc
        return (*qfn2(fn))(fn, v_15891, v_15890);
    }
v_15850:
    v_15890 = v_15892;
    v_15890 = integerp(v_15890);
    if (v_15890 == nil) goto v_15861;
    v_15890 = v_15892;
    {
        fn = elt(env, 5); // bcfi
        return (*qfn1(fn))(fn, v_15890);
    }
v_15861:
    goto v_15872;
v_15868:
    v_15890 = v_15892;
    v_15891 = qcar(v_15890);
    goto v_15869;
v_15870:
    v_15890 = elt(env, 2); // !:mod!:
    goto v_15871;
v_15872:
    goto v_15868;
v_15869:
    goto v_15870;
v_15871:
    if (v_15891 == v_15890) goto v_15867;
    goto v_15882;
v_15878:
    v_15890 = elt(env, 3); // "Invalid modular coefficient"
    goto v_15879;
v_15880:
    v_15891 = v_15892;
    goto v_15881;
v_15882:
    goto v_15878;
v_15879:
    goto v_15880;
v_15881:
    v_15890 = list2(v_15890, v_15891);
    env = stack[0];
    {
        fn = elt(env, 6); // rederr
        return (*qfn1(fn))(fn, v_15890);
    }
v_15867:
    v_15890 = v_15892;
    v_15890 = qcdr(v_15890);
    {
        fn = elt(env, 5); // bcfi
        return (*qfn1(fn))(fn, v_15890);
    }
    v_15890 = nil;
    return onevalue(v_15890);
}



// Code for rd!:times

static LispObject CC_rdTtimes(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_16025, v_16026, v_16027;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15845,v_15846);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15846;
    stack[-1] = v_15845;
// end of prologue
    v_16025 = nil;
    stack[-2] = v_16025;
    v_16025 = qvalue(elt(env, 1)); // !*!*roundbf
    if (v_16025 == nil) goto v_15856;
    else goto v_15857;
v_15856:
    v_16025 = stack[-1];
    v_16025 = qcdr(v_16025);
    if (!consp(v_16025)) goto v_15861;
    else goto v_15862;
v_15861:
    v_16025 = stack[0];
    v_16025 = qcdr(v_16025);
    if (!consp(v_16025)) goto v_15867;
    else goto v_15868;
v_15867:
    goto v_15876;
v_15872:
    v_16025 = stack[-1];
    v_16026 = qcdr(v_16025);
    goto v_15873;
v_15874:
    v_16025 = stack[0];
    v_16025 = qcdr(v_16025);
    goto v_15875;
v_15876:
    goto v_15872;
v_15873:
    goto v_15874;
v_15875:
    fn = elt(env, 4); // safe!-fp!-times
    v_16025 = (*qfn2(fn))(fn, v_16026, v_16025);
    env = stack[-3];
    stack[-2] = v_16025;
    goto v_15866;
v_15868:
    v_16025 = nil;
    goto v_15866;
    v_16025 = nil;
v_15866:
    goto v_15860;
v_15862:
    v_16025 = nil;
    goto v_15860;
    v_16025 = nil;
v_15860:
    goto v_15855;
v_15857:
    v_16025 = nil;
    goto v_15855;
    v_16025 = nil;
v_15855:
    if (v_16025 == nil) goto v_15853;
    goto v_15895;
v_15891:
    v_16026 = elt(env, 2); // !:rd!:
    goto v_15892;
v_15893:
    v_16025 = stack[-2];
    goto v_15894;
v_15895:
    goto v_15891;
v_15892:
    goto v_15893;
v_15894:
    return cons(v_16026, v_16025);
v_15853:
    goto v_15909;
v_15905:
    v_16026 = stack[-1];
    goto v_15906;
v_15907:
    v_16025 = stack[0];
    goto v_15908;
v_15909:
    goto v_15905;
v_15906:
    goto v_15907;
v_15908:
    fn = elt(env, 5); // convprc2
    v_16025 = (*qfn2(fn))(fn, v_16026, v_16025);
    env = stack[-3];
    stack[-1] = v_16025;
    v_16025 = qvalue(elt(env, 3)); // yy!!
    stack[0] = v_16025;
    v_16025 = stack[-1];
    if (!consp(v_16025)) goto v_15917;
    goto v_15924;
v_15920:
    v_16026 = stack[-1];
    goto v_15921;
v_15922:
    v_16025 = stack[0];
    goto v_15923;
v_15924:
    goto v_15920;
v_15921:
    goto v_15922;
v_15923:
    fn = elt(env, 6); // csl_timbf
    v_16025 = (*qfn2(fn))(fn, v_16026, v_16025);
    env = stack[-3];
    goto v_15915;
v_15917:
    goto v_15934;
v_15930:
    v_16026 = stack[-1];
    goto v_15931;
v_15932:
    v_16025 = stack[0];
    goto v_15933;
v_15934:
    goto v_15930;
v_15931:
    goto v_15932;
v_15933:
    v_16025 = times2(v_16026, v_16025);
    env = stack[-3];
    stack[-2] = v_16025;
    v_16025 = stack[-2];
    fn = elt(env, 7); // fp!-infinite
    v_16025 = (*qfn1(fn))(fn, v_16025);
    env = stack[-3];
    if (v_16025 == nil) goto v_15940;
    fn = elt(env, 8); // rndbfon
    v_16025 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_15949;
v_15945:
    v_16025 = stack[-1];
    v_16025 = Lfloatp(nil, v_16025);
    env = stack[-3];
    if (v_16025 == nil) goto v_15953;
    v_16025 = stack[-1];
    fn = elt(env, 9); // fl2bf
    v_16025 = (*qfn1(fn))(fn, v_16025);
    env = stack[-3];
    stack[-1] = v_16025;
    goto v_15951;
v_15953:
    v_16025 = stack[-1];
    if (!consp(v_16025)) goto v_15964;
    v_16025 = stack[-1];
    goto v_15962;
v_15964:
    v_16025 = stack[-1];
    v_16025 = integerp(v_16025);
    if (v_16025 == nil) goto v_15968;
    goto v_15978;
v_15972:
    v_16027 = elt(env, 2); // !:rd!:
    goto v_15973;
v_15974:
    v_16026 = stack[-1];
    goto v_15975;
v_15976:
    v_16025 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15977;
v_15978:
    goto v_15972;
v_15973:
    goto v_15974;
v_15975:
    goto v_15976;
v_15977:
    v_16025 = list2star(v_16027, v_16026, v_16025);
    env = stack[-3];
    goto v_15962;
v_15968:
    v_16025 = stack[-1];
    fn = elt(env, 10); // read!:num
    v_16025 = (*qfn1(fn))(fn, v_16025);
    env = stack[-3];
    goto v_15962;
    v_16025 = nil;
v_15962:
    fn = elt(env, 11); // normbf
    v_16025 = (*qfn1(fn))(fn, v_16025);
    env = stack[-3];
    stack[-1] = v_16025;
    goto v_15951;
    stack[-1] = nil;
v_15951:
    goto v_15946;
v_15947:
    v_16025 = stack[0];
    v_16025 = Lfloatp(nil, v_16025);
    env = stack[-3];
    if (v_16025 == nil) goto v_15989;
    v_16025 = stack[0];
    fn = elt(env, 9); // fl2bf
    v_16025 = (*qfn1(fn))(fn, v_16025);
    env = stack[-3];
    goto v_15987;
v_15989:
    v_16025 = stack[0];
    if (!consp(v_16025)) goto v_16000;
    v_16025 = stack[0];
    goto v_15998;
v_16000:
    v_16025 = stack[0];
    v_16025 = integerp(v_16025);
    if (v_16025 == nil) goto v_16004;
    goto v_16014;
v_16008:
    v_16027 = elt(env, 2); // !:rd!:
    goto v_16009;
v_16010:
    v_16026 = stack[0];
    goto v_16011;
v_16012:
    v_16025 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16013;
v_16014:
    goto v_16008;
v_16009:
    goto v_16010;
v_16011:
    goto v_16012;
v_16013:
    v_16025 = list2star(v_16027, v_16026, v_16025);
    env = stack[-3];
    goto v_15998;
v_16004:
    v_16025 = stack[0];
    fn = elt(env, 10); // read!:num
    v_16025 = (*qfn1(fn))(fn, v_16025);
    env = stack[-3];
    goto v_15998;
    v_16025 = nil;
v_15998:
    fn = elt(env, 11); // normbf
    v_16025 = (*qfn1(fn))(fn, v_16025);
    env = stack[-3];
    goto v_15987;
    v_16025 = nil;
v_15987:
    goto v_15948;
v_15949:
    goto v_15945;
v_15946:
    goto v_15947;
v_15948:
    fn = elt(env, 6); // csl_timbf
    v_16025 = (*qfn2(fn))(fn, stack[-1], v_16025);
    env = stack[-3];
    goto v_15938;
v_15940:
    v_16025 = stack[-2];
    goto v_15938;
    v_16025 = nil;
v_15938:
    goto v_15915;
    v_16025 = nil;
v_15915:
    {
        fn = elt(env, 12); // mkround
        return (*qfn1(fn))(fn, v_16025);
    }
    goto v_15851;
    v_16025 = nil;
v_15851:
    return onevalue(v_16025);
}



// Code for permp

static LispObject CC_permp(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_15897, v_15898, v_15899, v_15900;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15845,v_15846);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_15898 = v_15846;
    v_15899 = v_15845;
// end of prologue
v_15850:
    v_15897 = v_15899;
    if (v_15897 == nil) goto v_15853;
    else goto v_15854;
v_15853:
    v_15897 = lisp_true;
    goto v_15849;
v_15854:
    goto v_15863;
v_15859:
    v_15897 = v_15899;
    v_15900 = qcar(v_15897);
    goto v_15860;
v_15861:
    v_15897 = v_15898;
    v_15897 = qcar(v_15897);
    goto v_15862;
v_15863:
    goto v_15859;
v_15860:
    goto v_15861;
v_15862:
    if (equal(v_15900, v_15897)) goto v_15857;
    else goto v_15858;
v_15857:
    v_15897 = v_15899;
    v_15897 = qcdr(v_15897);
    v_15899 = v_15897;
    v_15897 = v_15898;
    v_15897 = qcdr(v_15897);
    v_15898 = v_15897;
    goto v_15850;
v_15858:
    goto v_15879;
v_15875:
    v_15897 = v_15899;
    stack[0] = qcdr(v_15897);
    goto v_15876;
v_15877:
    goto v_15889;
v_15883:
    v_15897 = v_15898;
    v_15897 = qcar(v_15897);
    goto v_15884;
v_15885:
    v_15899 = qcar(v_15899);
    goto v_15886;
v_15887:
    v_15898 = qcdr(v_15898);
    goto v_15888;
v_15889:
    goto v_15883;
v_15884:
    goto v_15885;
v_15886:
    goto v_15887;
v_15888:
    v_15897 = Lsubst(nil, 3, v_15897, v_15899, v_15898);
    env = stack[-1];
    goto v_15878;
v_15879:
    goto v_15875;
v_15876:
    goto v_15877;
v_15878:
    v_15897 = CC_permp(elt(env, 0), stack[0], v_15897);
    v_15897 = (v_15897 == nil ? lisp_true : nil);
    goto v_15849;
    v_15897 = nil;
v_15849:
    return onevalue(v_15897);
}



// Code for groeb!=rf1

static LispObject CC_groebMrf1(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_15863, v_15864;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15845,v_15846);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_15846;
    v_15863 = v_15845;
// end of prologue
    goto v_15853;
v_15849:
    goto v_15859;
v_15855:
    v_15864 = stack[0];
    goto v_15856;
v_15857:
    goto v_15858;
v_15859:
    goto v_15855;
v_15856:
    goto v_15857;
v_15858:
    fn = elt(env, 1); // red_totalred
    v_15864 = (*qfn2(fn))(fn, v_15864, v_15863);
    goto v_15850;
v_15851:
    v_15863 = stack[0];
    goto v_15852;
v_15853:
    goto v_15849;
v_15850:
    goto v_15851;
v_15852:
    return list2(v_15864, v_15863);
}



// Code for expansion_name

static LispObject CC_expansion_name(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15858;
    argcheck(nargs, 0, "expansion_name");
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
    goto v_15852;
v_15848:
    v_15858 = elt(env, 1); // lalr_internal_
    stack[0] = Lexplode(nil, v_15858);
    env = stack[-1];
    goto v_15849;
v_15850:
    v_15858 = qvalue(elt(env, 2)); // expansion_count
    v_15858 = add1(v_15858);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_15858; // expansion_count
    v_15858 = Lexplode(nil, v_15858);
    env = stack[-1];
    goto v_15851;
v_15852:
    goto v_15848;
v_15849:
    goto v_15850;
v_15851:
    v_15858 = Lappend(nil, stack[0], v_15858);
        return Lcompress(nil, v_15858);
}



// Code for ofsf_posvarp

static LispObject CC_ofsf_posvarp(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_16101, v_16102, v_16103, v_16104;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15845,v_15846);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15846;
    stack[-1] = v_15845;
// end of prologue
    v_16103 = nil;
    v_16101 = stack[-1];
    if (!consp(v_16101)) goto v_15856;
    else goto v_15857;
v_15856:
    v_16101 = stack[-1];
    goto v_15855;
v_15857:
    v_16101 = stack[-1];
    v_16101 = qcar(v_16101);
    goto v_15855;
    v_16101 = nil;
v_15855:
    goto v_15872;
v_15868:
    v_16102 = v_16101;
    goto v_15869;
v_15870:
    v_16101 = elt(env, 1); // and
    goto v_15871;
v_15872:
    goto v_15868;
v_15869:
    goto v_15870;
v_15871:
    if (v_16102 == v_16101) goto v_15866;
    else goto v_15867;
v_15866:
    v_16101 = stack[-1];
    v_16101 = qcdr(v_16101);
    stack[-2] = v_16101;
v_15879:
    v_16101 = v_16103;
    if (v_16101 == nil) goto v_15886;
    else goto v_15887;
v_15886:
    v_16101 = stack[-2];
    goto v_15885;
v_15887:
    v_16101 = nil;
    goto v_15885;
    v_16101 = nil;
v_15885:
    if (v_16101 == nil) goto v_15882;
    else goto v_15883;
v_15882:
    goto v_15878;
v_15883:
    v_16101 = stack[-2];
    v_16101 = qcar(v_16101);
    v_16102 = v_16101;
    v_16101 = stack[-2];
    v_16101 = qcdr(v_16101);
    stack[-2] = v_16101;
    v_16101 = v_16102;
    v_16104 = v_16101;
    goto v_15919;
v_15915:
    v_16102 = stack[-1];
    goto v_15916;
v_15917:
    v_16101 = elt(env, 2); // true
    goto v_15918;
v_15919:
    goto v_15915;
v_15916:
    goto v_15917;
v_15918:
    if (v_16102 == v_16101) goto v_15913;
    else goto v_15914;
v_15913:
    v_16101 = lisp_true;
    goto v_15912;
v_15914:
    goto v_15929;
v_15925:
    v_16102 = stack[-1];
    goto v_15926;
v_15927:
    v_16101 = elt(env, 3); // false
    goto v_15928;
v_15929:
    goto v_15925;
v_15926:
    goto v_15927;
v_15928:
    v_16101 = (v_16102 == v_16101 ? lisp_true : nil);
    goto v_15912;
    v_16101 = nil;
v_15912:
    if (v_16101 == nil) goto v_15910;
    v_16101 = lisp_true;
    goto v_15908;
v_15910:
    goto v_15956;
v_15952:
    v_16102 = stack[-1];
    goto v_15953;
v_15954:
    v_16101 = elt(env, 4); // or
    goto v_15955;
v_15956:
    goto v_15952;
v_15953:
    goto v_15954;
v_15955:
    if (v_16102 == v_16101) goto v_15950;
    else goto v_15951;
v_15950:
    v_16101 = lisp_true;
    goto v_15949;
v_15951:
    goto v_15966;
v_15962:
    v_16102 = stack[-1];
    goto v_15963;
v_15964:
    v_16101 = elt(env, 1); // and
    goto v_15965;
v_15966:
    goto v_15962;
v_15963:
    goto v_15964;
v_15965:
    v_16101 = (v_16102 == v_16101 ? lisp_true : nil);
    goto v_15949;
    v_16101 = nil;
v_15949:
    if (v_16101 == nil) goto v_15947;
    v_16101 = lisp_true;
    goto v_15945;
v_15947:
    goto v_15977;
v_15973:
    v_16102 = stack[-1];
    goto v_15974;
v_15975:
    v_16101 = elt(env, 5); // not
    goto v_15976;
v_15977:
    goto v_15973;
v_15974:
    goto v_15975;
v_15976:
    v_16101 = (v_16102 == v_16101 ? lisp_true : nil);
    goto v_15945;
    v_16101 = nil;
v_15945:
    if (v_16101 == nil) goto v_15943;
    v_16101 = lisp_true;
    goto v_15941;
v_15943:
    goto v_15992;
v_15988:
    v_16102 = stack[-1];
    goto v_15989;
v_15990:
    v_16101 = elt(env, 6); // impl
    goto v_15991;
v_15992:
    goto v_15988;
v_15989:
    goto v_15990;
v_15991:
    if (v_16102 == v_16101) goto v_15986;
    else goto v_15987;
v_15986:
    v_16101 = lisp_true;
    goto v_15985;
v_15987:
    goto v_16006;
v_16002:
    v_16102 = stack[-1];
    goto v_16003;
v_16004:
    v_16101 = elt(env, 7); // repl
    goto v_16005;
v_16006:
    goto v_16002;
v_16003:
    goto v_16004;
v_16005:
    if (v_16102 == v_16101) goto v_16000;
    else goto v_16001;
v_16000:
    v_16101 = lisp_true;
    goto v_15999;
v_16001:
    goto v_16016;
v_16012:
    v_16102 = stack[-1];
    goto v_16013;
v_16014:
    v_16101 = elt(env, 8); // equiv
    goto v_16015;
v_16016:
    goto v_16012;
v_16013:
    goto v_16014;
v_16015:
    v_16101 = (v_16102 == v_16101 ? lisp_true : nil);
    goto v_15999;
    v_16101 = nil;
v_15999:
    goto v_15985;
    v_16101 = nil;
v_15985:
    goto v_15941;
    v_16101 = nil;
v_15941:
    if (v_16101 == nil) goto v_15939;
    v_16101 = lisp_true;
    goto v_15937;
v_15939:
    goto v_16035;
v_16031:
    v_16102 = stack[-1];
    goto v_16032;
v_16033:
    v_16101 = elt(env, 9); // ex
    goto v_16034;
v_16035:
    goto v_16031;
v_16032:
    goto v_16033;
v_16034:
    if (v_16102 == v_16101) goto v_16029;
    else goto v_16030;
v_16029:
    v_16101 = lisp_true;
    goto v_16028;
v_16030:
    goto v_16045;
v_16041:
    v_16102 = stack[-1];
    goto v_16042;
v_16043:
    v_16101 = elt(env, 10); // all
    goto v_16044;
v_16045:
    goto v_16041;
v_16042:
    goto v_16043;
v_16044:
    v_16101 = (v_16102 == v_16101 ? lisp_true : nil);
    goto v_16028;
    v_16101 = nil;
v_16028:
    if (v_16101 == nil) goto v_16026;
    v_16101 = lisp_true;
    goto v_16024;
v_16026:
    goto v_16064;
v_16060:
    v_16102 = stack[-1];
    goto v_16061;
v_16062:
    v_16101 = elt(env, 11); // bex
    goto v_16063;
v_16064:
    goto v_16060;
v_16061:
    goto v_16062;
v_16063:
    if (v_16102 == v_16101) goto v_16058;
    else goto v_16059;
v_16058:
    v_16101 = lisp_true;
    goto v_16057;
v_16059:
    goto v_16074;
v_16070:
    v_16102 = stack[-1];
    goto v_16071;
v_16072:
    v_16101 = elt(env, 12); // ball
    goto v_16073;
v_16074:
    goto v_16070;
v_16071:
    goto v_16072;
v_16073:
    v_16101 = (v_16102 == v_16101 ? lisp_true : nil);
    goto v_16057;
    v_16101 = nil;
v_16057:
    if (v_16101 == nil) goto v_16055;
    v_16101 = lisp_true;
    goto v_16053;
v_16055:
    v_16101 = stack[-1];
    if (!symbolp(v_16101)) v_16101 = nil;
    else { v_16101 = qfastgets(v_16101);
           if (v_16101 != nil) { v_16101 = elt(v_16101, 21); // rl_external
#ifdef RECORD_GET
             if (v_16101 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_16101 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_16101 == SPID_NOPROP) v_16101 = nil; }}
#endif
    goto v_16053;
    v_16101 = nil;
v_16053:
    goto v_16024;
    v_16101 = nil;
v_16024:
    goto v_15937;
    v_16101 = nil;
v_15937:
    goto v_15908;
    v_16101 = nil;
v_15908:
    if (v_16101 == nil) goto v_15905;
    else goto v_15906;
v_15905:
    goto v_16088;
v_16084:
    v_16102 = v_16104;
    goto v_16085;
v_16086:
    v_16101 = stack[0];
    goto v_16087;
v_16088:
    goto v_16084;
v_16085:
    goto v_16086;
v_16087:
    fn = elt(env, 13); // ofsf_posvarpat
    v_16101 = (*qfn2(fn))(fn, v_16102, v_16101);
    env = stack[-3];
    v_16103 = v_16101;
    goto v_15904;
v_15906:
v_15904:
    goto v_15879;
v_15878:
    v_16101 = v_16103;
    goto v_15853;
v_15867:
    goto v_16098;
v_16094:
    v_16102 = stack[-1];
    goto v_16095;
v_16096:
    v_16101 = stack[0];
    goto v_16097;
v_16098:
    goto v_16094;
v_16095:
    goto v_16096;
v_16097:
    {
        fn = elt(env, 13); // ofsf_posvarpat
        return (*qfn2(fn))(fn, v_16102, v_16101);
    }
v_15853:
    return onevalue(v_16101);
}



// Code for cquotegex

static LispObject CC_cquotegex(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15853;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15853 = v_15845;
// end of prologue
    v_15853 = qvalue(elt(env, 1)); // !*guardian
    if (v_15853 == nil) goto v_15850;
    v_15853 = elt(env, 2); // gex
    goto v_15848;
v_15850:
    v_15853 = nil;
v_15848:
    return onevalue(v_15853);
}



// Code for negind

static LispObject CC_negind(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_15887, v_15888;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15845,v_15846);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15846;
    stack[-1] = v_15845;
// end of prologue
v_15844:
    v_15887 = stack[-1];
    if (v_15887 == nil) goto v_15850;
    else goto v_15851;
v_15850:
    v_15887 = nil;
    goto v_15849;
v_15851:
    goto v_15864;
v_15860:
    goto v_15870;
v_15866:
    v_15887 = stack[-1];
    v_15888 = qcar(v_15887);
    goto v_15867;
v_15868:
    v_15887 = stack[0];
    v_15887 = qcar(v_15887);
    v_15887 = qcar(v_15887);
    goto v_15869;
v_15870:
    goto v_15866;
v_15867:
    goto v_15868;
v_15869:
    v_15888 = plus2(v_15888, v_15887);
    env = stack[-2];
    goto v_15861;
v_15862:
    v_15887 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15863;
v_15864:
    goto v_15860;
v_15861:
    goto v_15862;
v_15863:
    v_15887 = (LispObject)lessp2(v_15888, v_15887);
    v_15887 = v_15887 ? lisp_true : nil;
    env = stack[-2];
    if (v_15887 == nil) goto v_15858;
    else goto v_15857;
v_15858:
    goto v_15882;
v_15878:
    v_15887 = stack[-1];
    v_15888 = qcdr(v_15887);
    goto v_15879;
v_15880:
    v_15887 = stack[0];
    v_15887 = qcdr(v_15887);
    goto v_15881;
v_15882:
    goto v_15878;
v_15879:
    goto v_15880;
v_15881:
    stack[-1] = v_15888;
    stack[0] = v_15887;
    goto v_15844;
v_15857:
    goto v_15849;
    v_15887 = nil;
v_15849:
    return onevalue(v_15887);
}



// Code for cl_rename!-vars

static LispObject CC_cl_renameKvars(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15857;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_15857 = v_15845;
// end of prologue
    goto v_15852;
v_15848:
    stack[0] = v_15857;
    goto v_15849;
v_15850:
    fn = elt(env, 1); // cl_replace!-varl
    v_15857 = (*qfn1(fn))(fn, v_15857);
    env = stack[-1];
    goto v_15851;
v_15852:
    goto v_15848;
v_15849:
    goto v_15850;
v_15851:
    fn = elt(env, 2); // cl_rename!-vars1
    v_15857 = (*qfn2(fn))(fn, stack[0], v_15857);
    v_15857 = qcar(v_15857);
    return onevalue(v_15857);
}



// Code for dip_f2dip1

static LispObject CC_dip_f2dip1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15929, v_15930, v_15931, v_15932, v_15933;
    LispObject fn;
    LispObject v_15847, v_15846, v_15845;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dip_f2dip1");
    va_start(aa, nargs);
    v_15845 = va_arg(aa, LispObject);
    v_15846 = va_arg(aa, LispObject);
    v_15847 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_15847,v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_15845,v_15846,v_15847);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_15847;
    stack[-1] = v_15846;
    stack[-2] = v_15845;
// end of prologue
    v_15929 = stack[-2];
    if (v_15929 == nil) goto v_15851;
    else goto v_15852;
v_15851:
    v_15929 = nil;
    goto v_15850;
v_15852:
    v_15929 = stack[-2];
    if (!consp(v_15929)) goto v_15859;
    else goto v_15860;
v_15859:
    v_15929 = lisp_true;
    goto v_15858;
v_15860:
    v_15929 = stack[-2];
    v_15929 = qcar(v_15929);
    v_15929 = (consp(v_15929) ? nil : lisp_true);
    goto v_15858;
    v_15929 = nil;
v_15858:
    if (v_15929 == nil) goto v_15856;
    goto v_15873;
v_15869:
    goto v_15879;
v_15875:
    goto v_15876;
v_15877:
    v_15929 = stack[-2];
    fn = elt(env, 1); // bc_fd
    v_15929 = (*qfn1(fn))(fn, v_15929);
    env = stack[-4];
    goto v_15878;
v_15879:
    goto v_15875;
v_15876:
    goto v_15877;
v_15878:
    fn = elt(env, 2); // bc_prod
    v_15930 = (*qfn2(fn))(fn, stack[0], v_15929);
    env = stack[-4];
    goto v_15870;
v_15871:
    v_15929 = stack[-1];
    goto v_15872;
v_15873:
    goto v_15869;
v_15870:
    goto v_15871;
v_15872:
    {
        fn = elt(env, 3); // dip_fmon
        return (*qfn2(fn))(fn, v_15930, v_15929);
    }
v_15856:
    goto v_15891;
v_15887:
    goto v_15903;
v_15893:
    v_15929 = stack[-2];
    v_15929 = qcar(v_15929);
    v_15929 = qcar(v_15929);
    v_15933 = qcar(v_15929);
    goto v_15894;
v_15895:
    v_15929 = stack[-2];
    v_15929 = qcar(v_15929);
    v_15929 = qcar(v_15929);
    v_15932 = qcdr(v_15929);
    goto v_15896;
v_15897:
    v_15929 = stack[-2];
    v_15929 = qcar(v_15929);
    v_15931 = qcdr(v_15929);
    goto v_15898;
v_15899:
    v_15930 = stack[-1];
    goto v_15900;
v_15901:
    v_15929 = stack[0];
    goto v_15902;
v_15903:
    goto v_15893;
v_15894:
    goto v_15895;
v_15896:
    goto v_15897;
v_15898:
    goto v_15899;
v_15900:
    goto v_15901;
v_15902:
    fn = elt(env, 4); // dip_f2dip2
    stack[-3] = (*qfnn(fn))(fn, 5, v_15933, v_15932, v_15931, v_15930, v_15929);
    env = stack[-4];
    goto v_15888;
v_15889:
    goto v_15924;
v_15918:
    v_15929 = stack[-2];
    v_15931 = qcdr(v_15929);
    goto v_15919;
v_15920:
    v_15930 = stack[-1];
    goto v_15921;
v_15922:
    v_15929 = stack[0];
    goto v_15923;
v_15924:
    goto v_15918;
v_15919:
    goto v_15920;
v_15921:
    goto v_15922;
v_15923:
    v_15929 = CC_dip_f2dip1(elt(env, 0), 3, v_15931, v_15930, v_15929);
    env = stack[-4];
    goto v_15890;
v_15891:
    goto v_15887;
v_15888:
    goto v_15889;
v_15890:
    {
        LispObject v_15938 = stack[-3];
        fn = elt(env, 5); // dip_sum
        return (*qfn2(fn))(fn, v_15938, v_15929);
    }
    v_15929 = nil;
v_15850:
    return onevalue(v_15929);
}



// Code for getdec

static LispObject CC_getdec(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15866, v_15867;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15845;
// end of prologue
    goto v_15855;
v_15851:
    v_15867 = nil;
    goto v_15852;
v_15853:
    v_15866 = stack[0];
    goto v_15854;
v_15855:
    goto v_15851;
v_15852:
    goto v_15853;
v_15854:
    fn = elt(env, 1); // symtabget
    v_15866 = (*qfn2(fn))(fn, v_15867, v_15866);
    env = stack[-1];
    v_15867 = v_15866;
    v_15866 = v_15867;
    if (v_15866 == nil) goto v_15860;
    else goto v_15861;
v_15860:
    v_15866 = stack[0];
    fn = elt(env, 2); // implicitdec
    v_15866 = (*qfn1(fn))(fn, v_15866);
    v_15867 = v_15866;
    goto v_15859;
v_15861:
v_15859:
    v_15866 = v_15867;
    return onevalue(v_15866);
}



// Code for evrevgradlexcomp

static LispObject CC_evrevgradlexcomp(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_15918, v_15919;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15845,v_15846);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_15846;
    stack[-2] = v_15845;
// end of prologue
v_15850:
    v_15918 = stack[-2];
    if (v_15918 == nil) goto v_15853;
    else goto v_15854;
v_15853:
    v_15918 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15849;
v_15854:
    v_15918 = stack[-1];
    if (v_15918 == nil) goto v_15857;
    else goto v_15858;
v_15857:
    v_15918 = elt(env, 1); // (0)
    stack[-1] = v_15918;
    goto v_15850;
v_15858:
    goto v_15868;
v_15864:
    v_15918 = stack[-2];
    v_15919 = qcar(v_15918);
    goto v_15865;
v_15866:
    v_15918 = stack[-1];
    v_15918 = qcar(v_15918);
    goto v_15867;
v_15868:
    goto v_15864;
v_15865:
    goto v_15866;
v_15867:
    fn = elt(env, 2); // iequal
    v_15918 = (*qfn2(fn))(fn, v_15919, v_15918);
    env = stack[-4];
    if (v_15918 == nil) goto v_15862;
    v_15918 = stack[-2];
    v_15918 = qcdr(v_15918);
    stack[-2] = v_15918;
    v_15918 = stack[-1];
    v_15918 = qcdr(v_15918);
    stack[-1] = v_15918;
    goto v_15850;
v_15862:
    v_15918 = stack[-2];
    fn = elt(env, 3); // evtdeg
    stack[0] = (*qfn1(fn))(fn, v_15918);
    env = stack[-4];
    v_15918 = stack[-1];
    fn = elt(env, 3); // evtdeg
    v_15918 = (*qfn1(fn))(fn, v_15918);
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v_15918;
    goto v_15894;
v_15890:
    v_15919 = stack[-3];
    goto v_15891;
v_15892:
    v_15918 = stack[0];
    goto v_15893;
v_15894:
    goto v_15890;
v_15891:
    goto v_15892;
v_15893:
    fn = elt(env, 2); // iequal
    v_15918 = (*qfn2(fn))(fn, v_15919, v_15918);
    env = stack[-4];
    if (v_15918 == nil) goto v_15888;
    goto v_15902;
v_15898:
    v_15919 = stack[-2];
    goto v_15899;
v_15900:
    v_15918 = stack[-1];
    goto v_15901;
v_15902:
    goto v_15898;
v_15899:
    goto v_15900;
v_15901:
    {
        fn = elt(env, 4); // evinvlexcomp
        return (*qfn2(fn))(fn, v_15919, v_15918);
    }
v_15888:
    goto v_15911;
v_15907:
    v_15919 = stack[-3];
    goto v_15908;
v_15909:
    v_15918 = stack[0];
    goto v_15910;
v_15911:
    goto v_15907;
v_15908:
    goto v_15909;
v_15910:
    if (((intptr_t)(v_15919)) > ((intptr_t)(v_15918))) goto v_15905;
    else goto v_15906;
v_15905:
    v_15918 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15886;
v_15906:
    v_15918 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_15886;
    v_15918 = nil;
v_15886:
    goto v_15849;
    v_15918 = nil;
v_15849:
    return onevalue(v_15918);
}



// Code for unresidp

static LispObject CC_unresidp(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15856, v_15857;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15856 = v_15845;
// end of prologue
    goto v_15851;
v_15847:
    goto v_15848;
v_15849:
    v_15857 = qvalue(elt(env, 1)); // !*reservedops!*
    goto v_15850;
v_15851:
    goto v_15847;
v_15848:
    goto v_15849;
v_15850:
    v_15856 = Lmemq(nil, v_15856, v_15857);
    v_15856 = (v_15856 == nil ? lisp_true : nil);
    return onevalue(v_15856);
}



// Code for boolvalue!*

static LispObject CC_boolvalueH(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15864, v_15865;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15864 = v_15845;
// end of prologue
    v_15865 = v_15864;
    if (v_15865 == nil) goto v_15849;
    else goto v_15850;
v_15849:
    v_15864 = nil;
    goto v_15848;
v_15850:
    goto v_15859;
v_15855:
    v_15865 = v_15864;
    goto v_15856;
v_15857:
    v_15864 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15858;
v_15859:
    goto v_15855;
v_15856:
    goto v_15857;
v_15858:
    v_15864 = (v_15865 == v_15864 ? lisp_true : nil);
    v_15864 = (v_15864 == nil ? lisp_true : nil);
    goto v_15848;
    v_15864 = nil;
v_15848:
    return onevalue(v_15864);
}



// Code for no!-side!-effect!-listp

static LispObject CC_noKsideKeffectKlistp(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15868;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15845;
// end of prologue
v_15844:
    v_15868 = stack[0];
    if (v_15868 == nil) goto v_15849;
    else goto v_15850;
v_15849:
    v_15868 = lisp_true;
    goto v_15848;
v_15850:
    v_15868 = stack[0];
    v_15868 = qcar(v_15868);
    fn = elt(env, 1); // no!-side!-effectp
    v_15868 = (*qfn1(fn))(fn, v_15868);
    env = stack[-1];
    if (v_15868 == nil) goto v_15857;
    else goto v_15858;
v_15857:
    v_15868 = nil;
    goto v_15856;
v_15858:
    v_15868 = stack[0];
    v_15868 = qcdr(v_15868);
    stack[0] = v_15868;
    goto v_15844;
    v_15868 = nil;
v_15856:
    goto v_15848;
    v_15868 = nil;
v_15848:
    return onevalue(v_15868);
}



// Code for quotpri

static LispObject CC_quotpri(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15902, v_15903, v_15904;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_15903 = v_15845;
// end of prologue
    stack[0] = nil;
    v_15902 = qvalue(elt(env, 1)); // !*ratpri
    if (v_15902 == nil) goto v_15856;
    else goto v_15857;
v_15856:
    v_15902 = lisp_true;
    goto v_15855;
v_15857:
    v_15902 = qvalue(elt(env, 2)); // !*nat
    if (v_15902 == nil) goto v_15864;
    else goto v_15865;
v_15864:
    v_15902 = lisp_true;
    goto v_15863;
v_15865:
    v_15902 = qvalue(elt(env, 3)); // !*fort
    if (v_15902 == nil) goto v_15872;
    else goto v_15871;
v_15872:
    v_15902 = qvalue(elt(env, 4)); // !*list
    if (v_15902 == nil) goto v_15876;
    else goto v_15875;
v_15876:
    v_15902 = qvalue(elt(env, 5)); // !*mcd
    v_15902 = (v_15902 == nil ? lisp_true : nil);
v_15875:
v_15871:
    goto v_15863;
    v_15902 = nil;
v_15863:
    goto v_15855;
    v_15902 = nil;
v_15855:
    if (v_15902 == nil) goto v_15853;
    v_15902 = elt(env, 6); // failed
    goto v_15849;
v_15853:
    goto v_15888;
v_15884:
    v_15904 = qvalue(elt(env, 7)); // dmode!*
    goto v_15885;
v_15886:
    v_15902 = elt(env, 8); // ratmode
    goto v_15887;
v_15888:
    goto v_15884;
v_15885:
    goto v_15886;
v_15887:
    v_15902 = Lflagp(nil, v_15904, v_15902);
    env = stack[-1];
    if (v_15902 == nil) goto v_15882;
    v_15902 = qvalue(elt(env, 7)); // dmode!*
    stack[0] = v_15902;
    v_15902 = nil;
    qvalue(elt(env, 7)) = v_15902; // dmode!*
    goto v_15851;
v_15882:
v_15851:
    v_15902 = v_15903;
    fn = elt(env, 9); // ratfunpri1
    v_15902 = (*qfn1(fn))(fn, v_15902);
    env = stack[-1];
    v_15903 = v_15902;
    v_15902 = stack[0];
    if (v_15902 == nil) goto v_15898;
    v_15902 = stack[0];
    qvalue(elt(env, 7)) = v_15902; // dmode!*
    goto v_15896;
v_15898:
v_15896:
    v_15902 = v_15903;
v_15849:
    return onevalue(v_15902);
}



// Code for mo_2a

static LispObject CC_mo_2a(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15857;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_15857 = v_15845;
// end of prologue
    goto v_15852;
v_15848:
    stack[0] = qcar(v_15857);
    goto v_15849;
v_15850:
    v_15857 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 2); // ring_all_names
    v_15857 = (*qfn1(fn))(fn, v_15857);
    env = stack[-1];
    goto v_15851;
v_15852:
    goto v_15848;
v_15849:
    goto v_15850;
v_15851:
    {
        LispObject v_15859 = stack[0];
        fn = elt(env, 3); // mo!=expvec2a1
        return (*qfn2(fn))(fn, v_15859, v_15857);
    }
}



// Code for cde_odd_derivatives

static LispObject CC_cde_odd_derivatives(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15950, v_15951, v_15952;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_15845;
// end of prologue
    goto v_15857;
v_15853:
    v_15951 = qvalue(elt(env, 1)); // n_all_parametric_ext
    goto v_15854;
v_15855:
    v_15950 = qvalue(elt(env, 2)); // n_all_principal_ext
    goto v_15856;
v_15857:
    goto v_15853;
v_15854:
    goto v_15855;
v_15856:
    v_15950 = plus2(v_15951, v_15950);
    env = stack[-8];
    stack[-5] = v_15950;
    v_15950 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_15950;
v_15863:
    goto v_15875;
v_15871:
    v_15951 = stack[-5];
    goto v_15872;
v_15873:
    v_15950 = stack[-4];
    goto v_15874;
v_15875:
    goto v_15871;
v_15872:
    goto v_15873;
v_15874:
    v_15950 = difference2(v_15951, v_15950);
    env = stack[-8];
    v_15950 = Lminusp(nil, v_15950);
    env = stack[-8];
    if (v_15950 == nil) goto v_15868;
    v_15950 = nil;
    goto v_15862;
v_15868:
    goto v_15884;
v_15880:
    v_15951 = elt(env, 3); // svf_ext
    goto v_15881;
v_15882:
    v_15950 = stack[-4];
    goto v_15883;
v_15884:
    goto v_15880;
v_15881:
    goto v_15882;
v_15883:
    fn = elt(env, 4); // mkid
    v_15950 = (*qfn2(fn))(fn, v_15951, v_15950);
    env = stack[-8];
    stack[-7] = v_15950;
    goto v_15894;
v_15888:
    v_15952 = stack[-7];
    goto v_15889;
v_15890:
    v_15951 = nil;
    goto v_15891;
v_15892:
    v_15950 = stack[-6];
    goto v_15893;
v_15894:
    goto v_15888;
v_15889:
    goto v_15890;
v_15891:
    goto v_15892;
v_15893:
    fn = elt(env, 5); // super_vectorfield
    v_15950 = (*qfnn(fn))(fn, 3, v_15952, v_15951, v_15950);
    env = stack[-8];
    v_15950 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_15950;
v_15901:
    goto v_15913;
v_15909:
    v_15951 = stack[-5];
    goto v_15910;
v_15911:
    v_15950 = stack[-3];
    goto v_15912;
v_15913:
    goto v_15909;
v_15910:
    goto v_15911;
v_15912:
    v_15950 = difference2(v_15951, v_15950);
    env = stack[-8];
    v_15950 = Lminusp(nil, v_15950);
    env = stack[-8];
    if (v_15950 == nil) goto v_15906;
    goto v_15900;
v_15906:
    goto v_15926;
v_15918:
    stack[-2] = stack[-7];
    goto v_15919;
v_15920:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15921;
v_15922:
    stack[0] = stack[-3];
    goto v_15923;
v_15924:
    goto v_15939;
v_15935:
    v_15951 = stack[-4];
    goto v_15936;
v_15937:
    v_15950 = stack[-3];
    goto v_15938;
v_15939:
    goto v_15935;
v_15936:
    goto v_15937;
v_15938:
    v_15950 = Leqn(nil, v_15951, v_15950);
    env = stack[-8];
    if (v_15950 == nil) goto v_15933;
    v_15950 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15931;
v_15933:
    v_15950 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15931;
    v_15950 = nil;
v_15931:
    goto v_15925;
v_15926:
    goto v_15918;
v_15919:
    goto v_15920;
v_15921:
    goto v_15922;
v_15923:
    goto v_15924;
v_15925:
    fn = elt(env, 6); // set_svf
    v_15950 = (*qfnn(fn))(fn, 4, stack[-2], stack[-1], stack[0], v_15950);
    env = stack[-8];
    v_15950 = stack[-3];
    v_15950 = add1(v_15950);
    env = stack[-8];
    stack[-3] = v_15950;
    goto v_15901;
v_15900:
    v_15950 = stack[-4];
    v_15950 = add1(v_15950);
    env = stack[-8];
    stack[-4] = v_15950;
    goto v_15863;
v_15862:
    return onevalue(v_15950);
}



// Code for arg1of2

static LispObject CC_arg1of2(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_15849, v_15850;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15849 = v_15846;
    v_15850 = v_15845;
// end of prologue
    v_15849 = v_15850;
    return onevalue(v_15849);
}



// Code for mkfil!*

static LispObject CC_mkfilH(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15887, v_15888;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_15845;
// end of prologue
    v_15888 = nil;
    v_15887 = stack[0];
    v_15887 = Lstringp(nil, v_15887);
    env = stack[-1];
    if (v_15887 == nil) goto v_15853;
    v_15887 = stack[0];
    goto v_15851;
v_15853:
    v_15887 = stack[0];
    if (symbolp(v_15887)) goto v_15858;
    goto v_15865;
v_15861:
    v_15888 = stack[0];
    goto v_15862;
v_15863:
    v_15887 = elt(env, 1); // "file name"
    goto v_15864;
v_15865:
    goto v_15861;
v_15862:
    goto v_15863;
v_15864:
    {
        fn = elt(env, 2); // typerr
        return (*qfn2(fn))(fn, v_15888, v_15887);
    }
v_15858:
    v_15887 = stack[0];
    if (!symbolp(v_15887)) v_15887 = nil;
    else { v_15887 = qfastgets(v_15887);
           if (v_15887 != nil) { v_15887 = elt(v_15887, 17); // share
#ifdef RECORD_GET
             if (v_15887 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v_15887 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v_15887 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v_15887 == SPID_NOPROP) v_15887 = nil; else v_15887 = lisp_true; }}
#endif
    if (v_15887 == nil) goto v_15873;
    v_15887 = stack[0];
    fn = elt(env, 3); // eval
    v_15887 = (*qfn1(fn))(fn, v_15887);
    env = stack[-1];
    v_15888 = v_15887;
    v_15887 = Lstringp(nil, v_15887);
    env = stack[-1];
    goto v_15871;
v_15873:
    v_15887 = nil;
    goto v_15871;
    v_15887 = nil;
v_15871:
    if (v_15887 == nil) goto v_15869;
    v_15887 = v_15888;
    goto v_15851;
v_15869:
    v_15887 = stack[0];
    {
        fn = elt(env, 4); // string!-downcase
        return (*qfn1(fn))(fn, v_15887);
    }
    v_15887 = nil;
v_15851:
    return onevalue(v_15887);
}



// Code for pushback

static LispObject CC_pushback(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_15889, v_15890;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15845,v_15846);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15846;
    v_15889 = v_15845;
// end of prologue
v_15854:
    v_15890 = v_15889;
    v_15890 = qcar(v_15890);
    if (v_15890 == nil) goto v_15857;
    else goto v_15858;
v_15857:
    goto v_15853;
v_15858:
    v_15889 = qcdr(v_15889);
    goto v_15854;
v_15853:
    goto v_15870;
v_15866:
    goto v_15876;
v_15872:
    stack[-1] = v_15889;
    goto v_15873;
v_15874:
    goto v_15883;
v_15879:
    v_15890 = v_15889;
    v_15890 = qcar(v_15890);
    goto v_15880;
v_15881:
    v_15889 = qcdr(v_15889);
    goto v_15882;
v_15883:
    goto v_15879;
v_15880:
    goto v_15881;
v_15882:
    v_15889 = cons(v_15890, v_15889);
    env = stack[-2];
    goto v_15875;
v_15876:
    goto v_15872;
v_15873:
    goto v_15874;
v_15875:
    v_15890 = Lrplacd(nil, stack[-1], v_15889);
    env = stack[-2];
    goto v_15867;
v_15868:
    v_15889 = stack[0];
    goto v_15869;
v_15870:
    goto v_15866;
v_15867:
    goto v_15868;
v_15869:
    v_15889 = Lrplaca(nil, v_15890, v_15889);
    v_15889 = nil;
    return onevalue(v_15889);
}



// Code for talp_getinvfsym

static LispObject CC_talp_getinvfsym(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_15897, v_15898;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15845,v_15846);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_15846;
    stack[-1] = v_15845;
// end of prologue
    fn = elt(env, 1); // talp_getextl
    v_15897 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-2] = v_15897;
v_15854:
    goto v_15863;
v_15859:
    v_15897 = stack[-2];
    v_15897 = qcar(v_15897);
    v_15898 = qcar(v_15897);
    goto v_15860;
v_15861:
    v_15897 = stack[-1];
    goto v_15862;
v_15863:
    goto v_15859;
v_15860:
    goto v_15861;
v_15862:
    if (equal(v_15898, v_15897)) goto v_15857;
    else goto v_15858;
v_15857:
    goto v_15853;
v_15858:
    v_15897 = stack[-2];
    v_15897 = qcdr(v_15897);
    stack[-2] = v_15897;
    goto v_15854;
v_15853:
    v_15897 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_15897;
v_15874:
    goto v_15886;
v_15882:
    v_15898 = stack[0];
    goto v_15883;
v_15884:
    v_15897 = stack[-1];
    goto v_15885;
v_15886:
    goto v_15882;
v_15883:
    goto v_15884;
v_15885:
    v_15897 = difference2(v_15898, v_15897);
    env = stack[-3];
    v_15897 = Lminusp(nil, v_15897);
    env = stack[-3];
    if (v_15897 == nil) goto v_15879;
    goto v_15873;
v_15879:
    v_15897 = stack[-2];
    v_15897 = qcdr(v_15897);
    stack[-2] = v_15897;
    v_15897 = stack[-1];
    v_15897 = add1(v_15897);
    env = stack[-3];
    stack[-1] = v_15897;
    goto v_15874;
v_15873:
    v_15897 = stack[-2];
    v_15897 = qcar(v_15897);
    v_15897 = qcar(v_15897);
    return onevalue(v_15897);
}



// Code for qqe_arg!-check!-lb!-rb

static LispObject CC_qqe_argKcheckKlbKrb(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15890, v_15891;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15845;
// end of prologue
    v_15890 = stack[0];
    v_15890 = qcdr(v_15890);
    v_15890 = qcar(v_15890);
    v_15891 = v_15890;
    v_15890 = stack[0];
    v_15890 = qcdr(v_15890);
    v_15890 = qcdr(v_15890);
    v_15890 = qcar(v_15890);
    stack[-1] = v_15890;
    v_15890 = v_15891;
    fn = elt(env, 2); // qqe_arg!-check!-b
    v_15890 = (*qfn1(fn))(fn, v_15890);
    env = stack[-2];
    if (v_15890 == nil) goto v_15860;
    else goto v_15861;
v_15860:
    fn = elt(env, 3); // qqe_arg!-check!-marked!-ids!-rollback
    v_15890 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_15870;
v_15866:
    v_15891 = stack[0];
    goto v_15867;
v_15868:
    v_15890 = elt(env, 1); // "type conflict: arguments don't fit
//             binary op with basic type args"
    goto v_15869;
v_15870:
    goto v_15866;
v_15867:
    goto v_15868;
v_15869:
    fn = elt(env, 4); // typerr
    v_15890 = (*qfn2(fn))(fn, v_15891, v_15890);
    env = stack[-2];
    goto v_15859;
v_15861:
v_15859:
    v_15890 = stack[-1];
    fn = elt(env, 2); // qqe_arg!-check!-b
    v_15890 = (*qfn1(fn))(fn, v_15890);
    env = stack[-2];
    if (v_15890 == nil) goto v_15876;
    else goto v_15877;
v_15876:
    fn = elt(env, 3); // qqe_arg!-check!-marked!-ids!-rollback
    v_15890 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_15886;
v_15882:
    v_15891 = stack[0];
    goto v_15883;
v_15884:
    v_15890 = elt(env, 1); // "type conflict: arguments don't fit
//             binary op with basic type args"
    goto v_15885;
v_15886:
    goto v_15882;
v_15883:
    goto v_15884;
v_15885:
    fn = elt(env, 4); // typerr
    v_15890 = (*qfn2(fn))(fn, v_15891, v_15890);
    goto v_15875;
v_15877:
v_15875:
    v_15890 = nil;
    return onevalue(v_15890);
}



// Code for pasf_pdp

static LispObject CC_pasf_pdp(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_16066, v_16067, v_16068;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15845;
// end of prologue
    v_16066 = stack[0];
    if (!consp(v_16066)) goto v_15857;
    else goto v_15858;
v_15857:
    v_16066 = lisp_true;
    goto v_15856;
v_15858:
    v_16066 = stack[0];
    v_16066 = qcar(v_16066);
    v_16066 = (consp(v_16066) ? nil : lisp_true);
    goto v_15856;
    v_16066 = nil;
v_15856:
    if (v_16066 == nil) goto v_15854;
    v_16066 = stack[0];
    if (v_16066 == nil) goto v_15868;
    else goto v_15869;
v_15868:
    v_16066 = elt(env, 1); // indef
    goto v_15867;
v_15869:
    goto v_15879;
v_15875:
    v_16067 = stack[0];
    goto v_15876;
v_15877:
    v_16066 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15878;
v_15879:
    goto v_15875;
v_15876:
    goto v_15877;
v_15878:
    v_16066 = (LispObject)lessp2(v_16067, v_16066);
    v_16066 = v_16066 ? lisp_true : nil;
    env = stack[-2];
    if (v_16066 == nil) goto v_15873;
    v_16066 = elt(env, 2); // ndef
    goto v_15867;
v_15873:
    goto v_15890;
v_15886:
    v_16067 = stack[0];
    goto v_15887;
v_15888:
    v_16066 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15889;
v_15890:
    goto v_15886;
v_15887:
    goto v_15888;
v_15889:
    v_16066 = (LispObject)greaterp2(v_16067, v_16066);
    v_16066 = v_16066 ? lisp_true : nil;
    env = stack[-2];
    if (v_16066 == nil) goto v_15884;
    v_16066 = elt(env, 3); // pdef
    goto v_15867;
v_15884:
    v_16066 = elt(env, 1); // indef
    goto v_15867;
    v_16066 = nil;
v_15867:
    goto v_15850;
v_15854:
    v_16066 = stack[0];
    v_16066 = qcar(v_16066);
    v_16066 = qcar(v_16066);
    v_16066 = qcdr(v_16066);
    v_16066 = Levenp(nil, v_16066);
    env = stack[-2];
    if (v_16066 == nil) goto v_15900;
    v_16066 = stack[0];
    v_16066 = qcar(v_16066);
    v_16066 = qcdr(v_16066);
    v_16066 = CC_pasf_pdp(elt(env, 0), v_16066);
    env = stack[-2];
    stack[-1] = v_16066;
    v_16066 = stack[0];
    v_16066 = qcdr(v_16066);
    v_16066 = CC_pasf_pdp(elt(env, 0), v_16066);
    env = stack[-2];
    v_16068 = v_16066;
    v_16066 = v_16068;
    if (v_16066 == nil) goto v_15919;
    else goto v_15920;
v_15919:
    goto v_15930;
v_15926:
    v_16067 = stack[-1];
    goto v_15927;
v_15928:
    v_16066 = elt(env, 4); // psdef
    goto v_15929;
v_15930:
    goto v_15926;
v_15927:
    goto v_15928;
v_15929:
    if (v_16067 == v_16066) goto v_15924;
    else goto v_15925;
v_15924:
    v_16066 = lisp_true;
    goto v_15923;
v_15925:
    goto v_15940;
v_15936:
    v_16067 = stack[-1];
    goto v_15937;
v_15938:
    v_16066 = elt(env, 3); // pdef
    goto v_15939;
v_15940:
    goto v_15936;
v_15937:
    goto v_15938;
v_15939:
    v_16066 = (v_16067 == v_16066 ? lisp_true : nil);
    goto v_15923;
    v_16066 = nil;
v_15923:
    goto v_15918;
v_15920:
    v_16066 = nil;
    goto v_15918;
    v_16066 = nil;
v_15918:
    if (v_16066 == nil) goto v_15916;
    v_16066 = elt(env, 4); // psdef
    goto v_15850;
v_15916:
    v_16066 = v_16068;
    if (v_16066 == nil) goto v_15954;
    else goto v_15955;
v_15954:
    goto v_15965;
v_15961:
    v_16067 = stack[-1];
    goto v_15962;
v_15963:
    v_16066 = elt(env, 5); // nsdef
    goto v_15964;
v_15965:
    goto v_15961;
v_15962:
    goto v_15963;
v_15964:
    if (v_16067 == v_16066) goto v_15959;
    else goto v_15960;
v_15959:
    v_16066 = lisp_true;
    goto v_15958;
v_15960:
    goto v_15975;
v_15971:
    v_16067 = stack[-1];
    goto v_15972;
v_15973:
    v_16066 = elt(env, 2); // ndef
    goto v_15974;
v_15975:
    goto v_15971;
v_15972:
    goto v_15973;
v_15974:
    v_16066 = (v_16067 == v_16066 ? lisp_true : nil);
    goto v_15958;
    v_16066 = nil;
v_15958:
    goto v_15953;
v_15955:
    v_16066 = nil;
    goto v_15953;
    v_16066 = nil;
v_15953:
    if (v_16066 == nil) goto v_15951;
    v_16066 = elt(env, 5); // nsdef
    goto v_15850;
v_15951:
    goto v_15995;
v_15991:
    v_16067 = v_16068;
    goto v_15992;
v_15993:
    v_16066 = elt(env, 3); // pdef
    goto v_15994;
v_15995:
    goto v_15991;
v_15992:
    goto v_15993;
v_15994:
    if (v_16067 == v_16066) goto v_15989;
    else goto v_15990;
v_15989:
    goto v_16006;
v_16002:
    v_16067 = stack[-1];
    goto v_16003;
v_16004:
    v_16066 = elt(env, 4); // psdef
    goto v_16005;
v_16006:
    goto v_16002;
v_16003:
    goto v_16004;
v_16005:
    if (v_16067 == v_16066) goto v_16000;
    else goto v_16001;
v_16000:
    v_16066 = lisp_true;
    goto v_15999;
v_16001:
    goto v_16016;
v_16012:
    v_16067 = stack[-1];
    goto v_16013;
v_16014:
    v_16066 = elt(env, 3); // pdef
    goto v_16015;
v_16016:
    goto v_16012;
v_16013:
    goto v_16014;
v_16015:
    v_16066 = (v_16067 == v_16066 ? lisp_true : nil);
    goto v_15999;
    v_16066 = nil;
v_15999:
    goto v_15988;
v_15990:
    v_16066 = nil;
    goto v_15988;
    v_16066 = nil;
v_15988:
    if (v_16066 == nil) goto v_15986;
    v_16066 = elt(env, 3); // pdef
    goto v_15850;
v_15986:
    goto v_16036;
v_16032:
    v_16067 = v_16068;
    goto v_16033;
v_16034:
    v_16066 = elt(env, 2); // ndef
    goto v_16035;
v_16036:
    goto v_16032;
v_16033:
    goto v_16034;
v_16035:
    if (v_16067 == v_16066) goto v_16030;
    else goto v_16031;
v_16030:
    goto v_16047;
v_16043:
    v_16067 = stack[-1];
    goto v_16044;
v_16045:
    v_16066 = elt(env, 5); // nsdef
    goto v_16046;
v_16047:
    goto v_16043;
v_16044:
    goto v_16045;
v_16046:
    if (v_16067 == v_16066) goto v_16041;
    else goto v_16042;
v_16041:
    v_16066 = lisp_true;
    goto v_16040;
v_16042:
    goto v_16057;
v_16053:
    v_16067 = stack[-1];
    goto v_16054;
v_16055:
    v_16066 = elt(env, 2); // ndef
    goto v_16056;
v_16057:
    goto v_16053;
v_16054:
    goto v_16055;
v_16056:
    v_16066 = (v_16067 == v_16066 ? lisp_true : nil);
    goto v_16040;
    v_16066 = nil;
v_16040:
    goto v_16029;
v_16031:
    v_16066 = nil;
    goto v_16029;
    v_16066 = nil;
v_16029:
    if (v_16066 == nil) goto v_16027;
    v_16066 = elt(env, 2); // ndef
    goto v_15850;
v_16027:
    goto v_15898;
v_15900:
v_15898:
    v_16066 = elt(env, 1); // indef
v_15850:
    return onevalue(v_16066);
}



// Code for get!-height

static LispObject CC_getKheight(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15873;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_15845;
// end of prologue
    v_15873 = stack[0];
    if (v_15873 == nil) goto v_15849;
    else goto v_15850;
v_15849:
    v_15873 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15848;
v_15850:
    v_15873 = stack[0];
    if (is_number(v_15873)) goto v_15853;
    else goto v_15854;
v_15853:
    v_15873 = stack[0];
        return Labsval(nil, v_15873);
v_15854:
    goto v_15865;
v_15861:
    v_15873 = stack[0];
    v_15873 = qcar(v_15873);
    v_15873 = qcdr(v_15873);
    stack[-1] = CC_getKheight(elt(env, 0), v_15873);
    env = stack[-2];
    goto v_15862;
v_15863:
    v_15873 = stack[0];
    v_15873 = qcdr(v_15873);
    v_15873 = CC_getKheight(elt(env, 0), v_15873);
    env = stack[-2];
    goto v_15864;
v_15865:
    goto v_15861;
v_15862:
    goto v_15863;
v_15864:
    {
        LispObject v_15876 = stack[-1];
        fn = elt(env, 1); // max
        return (*qfn2(fn))(fn, v_15876, v_15873);
    }
    v_15873 = nil;
v_15848:
    return onevalue(v_15873);
}



// Code for omfir

static LispObject CC_omfir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_15878, v_15879;
    LispObject fn;
    argcheck(nargs, 0, "omfir");
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
    goto v_15854;
v_15850:
    v_15879 = qvalue(elt(env, 1)); // atts
    goto v_15851;
v_15852:
    v_15878 = elt(env, 2); // dec
    goto v_15853;
v_15854:
    goto v_15850;
v_15851:
    goto v_15852;
v_15853:
    fn = elt(env, 5); // find
    v_15878 = (*qfn2(fn))(fn, v_15879, v_15878);
    env = stack[-1];
    stack[0] = v_15878;
    goto v_15866;
v_15862:
    v_15879 = qvalue(elt(env, 1)); // atts
    goto v_15863;
v_15864:
    v_15878 = elt(env, 3); // name
    goto v_15865;
v_15866:
    goto v_15862;
v_15863:
    goto v_15864;
v_15865:
    fn = elt(env, 5); // find
    v_15878 = (*qfn2(fn))(fn, v_15879, v_15878);
    env = stack[-1];
    if (v_15878 == nil) goto v_15860;
    goto v_15874;
v_15870:
    v_15879 = elt(env, 4); // "wrong att"
    goto v_15871;
v_15872:
    v_15878 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_15873;
v_15874:
    goto v_15870;
v_15871:
    goto v_15872;
v_15873:
    fn = elt(env, 6); // errorml
    v_15878 = (*qfn2(fn))(fn, v_15879, v_15878);
    goto v_15858;
v_15860:
v_15858:
    v_15878 = stack[0];
    return onevalue(v_15878);
}



// Code for initarg

static LispObject CC_initarg(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_16066, v_16067;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_15845;
// end of prologue
    v_16066 = qvalue(elt(env, 1)); // op
    if (!symbolp(v_16066)) v_16066 = nil;
    else { v_16066 = qfastgets(v_16066);
           if (v_16066 != nil) { v_16066 = elt(v_16066, 43); // symmetric
#ifdef RECORD_GET
             if (v_16066 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v_16066 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v_16066 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v_16066 == SPID_NOPROP) v_16066 = nil; else v_16066 = lisp_true; }}
#endif
    qvalue(elt(env, 2)) = v_16066; // symm
    goto v_15865;
v_15861:
    v_16066 = qvalue(elt(env, 3)); // p
    stack[0] = Llength(nil, v_16066);
    env = stack[-6];
    goto v_15862;
v_15863:
    v_16066 = qvalue(elt(env, 4)); // r
    v_16066 = Llength(nil, v_16066);
    env = stack[-6];
    goto v_15864;
v_15865:
    goto v_15861;
v_15862:
    goto v_15863;
v_15864:
    v_16066 = difference2(stack[0], v_16066);
    env = stack[-6];
    v_16066 = add1(v_16066);
    env = stack[-6];
    stack[-1] = v_16066;
    v_16066 = qvalue(elt(env, 1)); // op
    fn = elt(env, 14); // ident
    v_16066 = (*qfn1(fn))(fn, v_16066);
    env = stack[-6];
    qvalue(elt(env, 5)) = v_16066; // identity
    v_16066 = qvalue(elt(env, 4)); // r
    v_16066 = qcar(v_16066);
    fn = elt(env, 15); // mgenp
    v_16066 = (*qfn1(fn))(fn, v_16066);
    env = stack[-6];
    stack[-3] = v_16066;
    v_16066 = qvalue(elt(env, 4)); // r
    v_16066 = qcdr(v_16066);
    fn = elt(env, 16); // list!-mgen
    v_16066 = (*qfn1(fn))(fn, v_16066);
    env = stack[-6];
    stack[0] = v_16066;
    goto v_15887;
v_15883:
    v_16067 = qvalue(elt(env, 1)); // op
    goto v_15884;
v_15885:
    v_16066 = elt(env, 6); // assoc
    goto v_15886;
v_15887:
    goto v_15883;
v_15884:
    goto v_15885;
v_15886:
    v_16066 = Lflagp(nil, v_16067, v_16066);
    env = stack[-6];
    if (v_16066 == nil) goto v_15881;
    v_16066 = qvalue(elt(env, 2)); // symm
    if (v_16066 == nil) goto v_15892;
    else goto v_15893;
v_15892:
    v_16066 = nil;
    goto v_15891;
v_15893:
    goto v_15907;
v_15903:
    v_16067 = stack[0];
    goto v_15904;
v_15905:
    v_16066 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15906;
v_15907:
    goto v_15903;
v_15904:
    goto v_15905;
v_15906:
    v_16066 = (LispObject)greaterp2(v_16067, v_16066);
    v_16066 = v_16066 ? lisp_true : nil;
    env = stack[-6];
    if (v_16066 == nil) goto v_15900;
    else goto v_15901;
v_15900:
    v_16066 = nil;
    goto v_15899;
v_15901:
    v_16066 = qvalue(elt(env, 7)); // !*sym!-assoc
    v_16066 = (v_16066 == nil ? lisp_true : nil);
    goto v_15899;
    v_16066 = nil;
v_15899:
    goto v_15891;
    v_16066 = nil;
v_15891:
    v_16066 = (v_16066 == nil ? lisp_true : nil);
    goto v_15879;
v_15881:
    v_16066 = nil;
    goto v_15879;
    v_16066 = nil;
v_15879:
    stack[-5] = v_16066;
    goto v_15928;
v_15924:
    v_16066 = qvalue(elt(env, 4)); // r
    v_16067 = Llength(nil, v_16066);
    env = stack[-6];
    goto v_15925;
v_15926:
    v_16066 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15927;
v_15928:
    goto v_15924;
v_15925:
    goto v_15926;
v_15927:
    v_16066 = (LispObject)greaterp2(v_16067, v_16066);
    v_16066 = v_16066 ? lisp_true : nil;
    env = stack[-6];
    if (v_16066 == nil) goto v_15921;
    else goto v_15922;
v_15921:
    v_16066 = nil;
    goto v_15920;
v_15922:
    v_16066 = stack[-5];
    if (v_16066 == nil) goto v_15937;
    else goto v_15936;
v_15937:
    v_16066 = stack[0];
v_15936:
    goto v_15920;
    v_16066 = nil;
v_15920:
    stack[-2] = v_16066;
    goto v_15948;
v_15944:
    v_16067 = stack[-1];
    goto v_15945;
v_15946:
    v_16066 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_15947;
v_15948:
    goto v_15944;
v_15945:
    goto v_15946;
v_15947:
    v_16066 = (LispObject)greaterp2(v_16067, v_16066);
    v_16066 = v_16066 ? lisp_true : nil;
    env = stack[-6];
    if (v_16066 == nil) goto v_15942;
    else goto v_15941;
v_15942:
    v_16066 = qvalue(elt(env, 5)); // identity
    if (v_16066 == nil) goto v_15953;
    else goto v_15954;
v_15953:
    v_16066 = nil;
    goto v_15952;
v_15954:
    goto v_15964;
v_15960:
    v_16066 = qvalue(elt(env, 3)); // p
    v_16067 = Llength(nil, v_16066);
    env = stack[-6];
    goto v_15961;
v_15962:
    v_16066 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15963;
v_15964:
    goto v_15960;
v_15961:
    goto v_15962;
v_15963:
    v_16066 = (LispObject)greaterp2(v_16067, v_16066);
    v_16066 = v_16066 ? lisp_true : nil;
    env = stack[-6];
    goto v_15952;
    v_16066 = nil;
v_15952:
v_15941:
    v_16067 = v_16066;
    v_16066 = stack[-3];
    if (v_16066 == nil) goto v_15970;
    else goto v_15971;
v_15970:
    v_16066 = nil;
    goto v_15969;
v_15971:
    v_16066 = v_16067;
    goto v_15969;
    v_16066 = nil;
v_15969:
    qvalue(elt(env, 8)) = v_16066; // mcontract
    v_16066 = stack[-5];
    if (v_16066 == nil) goto v_15979;
    else goto v_15980;
v_15979:
    v_16066 = nil;
    goto v_15978;
v_15980:
    v_16066 = v_16067;
    if (v_16066 == nil) goto v_15987;
    else goto v_15988;
v_15987:
    v_16066 = nil;
    goto v_15986;
v_15988:
    v_16066 = stack[-3];
    v_16066 = (v_16066 == nil ? lisp_true : nil);
    goto v_15986;
    v_16066 = nil;
v_15986:
    goto v_15978;
    v_16066 = nil;
v_15978:
    qvalue(elt(env, 9)) = v_16066; // acontract
    v_16066 = qvalue(elt(env, 5)); // identity
    if (v_16066 == nil) goto v_15997;
    else goto v_15998;
v_15997:
    v_16066 = nil;
    goto v_15996;
v_15998:
    goto v_16011;
v_16007:
    v_16067 = stack[-1];
    goto v_16008;
v_16009:
    v_16066 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16010;
v_16011:
    goto v_16007;
v_16008:
    goto v_16009;
v_16010:
    v_16066 = (LispObject)lessp2(v_16067, v_16066);
    v_16066 = v_16066 ? lisp_true : nil;
    env = stack[-6];
    if (v_16066 == nil) goto v_16005;
    else goto v_16004;
v_16005:
    v_16066 = stack[-2];
v_16004:
    goto v_15996;
    v_16066 = nil;
v_15996:
    qvalue(elt(env, 10)) = v_16066; // expand
    v_16066 = stack[-2];
    if (v_16066 == nil) goto v_16019;
    else goto v_16017;
v_16019:
    goto v_16027;
v_16023:
    v_16067 = stack[-1];
    goto v_16024;
v_16025:
    v_16066 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16026;
v_16027:
    goto v_16023;
v_16024:
    goto v_16025;
v_16026:
    v_16066 = (LispObject)lessp2(v_16067, v_16066);
    v_16066 = v_16066 ? lisp_true : nil;
    env = stack[-6];
    if (v_16066 == nil) goto v_16021;
    else goto v_16017;
v_16021:
    goto v_16018;
v_16017:
    v_16066 = stack[-3];
    if (v_16066 == nil) goto v_16033;
    v_16066 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16031;
v_16033:
    v_16066 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_16031;
    v_16066 = nil;
v_16031:
    goto v_16016;
v_16018:
    v_16066 = stack[-1];
    goto v_16016;
    v_16066 = nil;
v_16016:
    qvalue(elt(env, 11)) = v_16066; // i
    v_16066 = qvalue(elt(env, 5)); // identity
    if (v_16066 == nil) goto v_16045;
    v_16066 = qvalue(elt(env, 3)); // p
    v_16066 = Llength(nil, v_16066);
    env = stack[-6];
    goto v_16043;
v_16045:
    goto v_16056;
v_16052:
    v_16067 = stack[-1];
    goto v_16053;
v_16054:
    v_16066 = stack[0];
    goto v_16055;
v_16056:
    goto v_16052;
v_16053:
    goto v_16054;
v_16055:
    v_16066 = plus2(v_16067, v_16066);
    env = stack[-6];
    goto v_16043;
    v_16066 = nil;
v_16043:
    qvalue(elt(env, 12)) = v_16066; // upb
    v_16066 = qvalue(elt(env, 2)); // symm
    if (v_16066 == nil) goto v_16062;
    v_16066 = stack[-4];
    fn = elt(env, 17); // initcomb
    v_16066 = (*qfn1(fn))(fn, v_16066);
    env = stack[-6];
    qvalue(elt(env, 13)) = v_16066; // comb
    goto v_16060;
v_16062:
v_16060:
    v_16066 = nil;
    return onevalue(v_16066);
}



// Code for plubf

static LispObject CC_plubf(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_16097, v_16098, v_16099;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15845,v_15846);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-6] = v_15846;
    stack[-7] = v_15845;
// end of prologue
    goto v_15865;
v_15861:
    v_16097 = stack[-7];
    v_16097 = qcdr(v_16097);
    v_16098 = qcar(v_16097);
    stack[-8] = v_16098;
    goto v_15862;
v_15863:
    v_16097 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15864;
v_15865:
    goto v_15861;
v_15862:
    goto v_15863;
v_15864:
    if (v_16098 == v_16097) goto v_15859;
    else goto v_15860;
v_15859:
    v_16097 = stack[-6];
    goto v_15856;
v_15860:
    goto v_15879;
v_15875:
    v_16097 = stack[-6];
    v_16097 = qcdr(v_16097);
    v_16098 = qcar(v_16097);
    stack[-5] = v_16098;
    goto v_15876;
v_15877:
    v_16097 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15878;
v_15879:
    goto v_15875;
v_15876:
    goto v_15877;
v_15878:
    if (v_16098 == v_16097) goto v_15873;
    else goto v_15874;
v_15873:
    v_16097 = stack[-7];
    goto v_15856;
v_15874:
    goto v_15893;
v_15889:
    goto v_15899;
v_15895:
    v_16097 = stack[-7];
    v_16097 = qcdr(v_16097);
    v_16098 = qcdr(v_16097);
    stack[-4] = v_16098;
    goto v_15896;
v_15897:
    v_16097 = stack[-6];
    v_16097 = qcdr(v_16097);
    v_16097 = qcdr(v_16097);
    stack[-3] = v_16097;
    goto v_15898;
v_15899:
    goto v_15895;
v_15896:
    goto v_15897;
v_15898:
    v_16098 = difference2(v_16098, v_16097);
    env = stack[-9];
    stack[-2] = v_16098;
    goto v_15890;
v_15891:
    v_16097 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15892;
v_15893:
    goto v_15889;
v_15890:
    goto v_15891;
v_15892:
    if (v_16098 == v_16097) goto v_15887;
    else goto v_15888;
v_15887:
    goto v_15914;
v_15908:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_15909;
v_15910:
    goto v_15921;
v_15917:
    v_16098 = stack[-8];
    goto v_15918;
v_15919:
    v_16097 = stack[-5];
    goto v_15920;
v_15921:
    goto v_15917;
v_15918:
    goto v_15919;
v_15920:
    v_16098 = plus2(v_16098, v_16097);
    env = stack[-9];
    goto v_15911;
v_15912:
    v_16097 = stack[-4];
    goto v_15913;
v_15914:
    goto v_15908;
v_15909:
    goto v_15910;
v_15911:
    goto v_15912;
v_15913:
    v_16097 = list2star(stack[0], v_16098, v_16097);
    env = stack[-9];
    goto v_15856;
v_15888:
    goto v_15930;
v_15926:
    stack[-1] = stack[-2];
    goto v_15927;
v_15928:
    goto v_15937;
v_15933:
    v_16097 = stack[-8];
    v_16097 = Labsval(nil, v_16097);
    env = stack[-9];
    fn = elt(env, 3); // msd
    stack[0] = (*qfn1(fn))(fn, v_16097);
    env = stack[-9];
    goto v_15934;
v_15935:
    v_16097 = stack[-5];
    v_16097 = Labsval(nil, v_16097);
    env = stack[-9];
    fn = elt(env, 3); // msd
    v_16097 = (*qfn1(fn))(fn, v_16097);
    env = stack[-9];
    goto v_15936;
v_15937:
    goto v_15933;
v_15934:
    goto v_15935;
v_15936:
    v_16097 = difference2(stack[0], v_16097);
    env = stack[-9];
    goto v_15929;
v_15930:
    goto v_15926;
v_15927:
    goto v_15928;
v_15929:
    v_16097 = plus2(stack[-1], v_16097);
    env = stack[-9];
    stack[-1] = v_16097;
    v_16097 = qvalue(elt(env, 2)); // !:bprec!:
    v_16097 = add1(v_16097);
    env = stack[-9];
    stack[0] = v_16097;
    goto v_15955;
v_15951:
    v_16098 = stack[-1];
    goto v_15952;
v_15953:
    v_16097 = stack[0];
    goto v_15954;
v_15955:
    goto v_15951;
v_15952:
    goto v_15953;
v_15954:
    v_16097 = (LispObject)greaterp2(v_16098, v_16097);
    v_16097 = v_16097 ? lisp_true : nil;
    env = stack[-9];
    if (v_16097 == nil) goto v_15949;
    v_16097 = stack[-7];
    goto v_15856;
v_15949:
    goto v_15968;
v_15964:
    goto v_15965;
v_15966:
    v_16097 = stack[0];
    v_16097 = negate(v_16097);
    env = stack[-9];
    goto v_15967;
v_15968:
    goto v_15964;
v_15965:
    goto v_15966;
v_15967:
    v_16097 = (LispObject)lessp2(stack[-1], v_16097);
    v_16097 = v_16097 ? lisp_true : nil;
    env = stack[-9];
    if (v_16097 == nil) goto v_15962;
    v_16097 = stack[-6];
    goto v_15856;
v_15962:
    goto v_15982;
v_15978:
    v_16098 = stack[-2];
    goto v_15979;
v_15980:
    v_16097 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15981;
v_15982:
    goto v_15978;
v_15979:
    goto v_15980;
v_15981:
    v_16097 = (LispObject)greaterp2(v_16098, v_16097);
    v_16097 = v_16097 ? lisp_true : nil;
    env = stack[-9];
    if (v_16097 == nil) goto v_15976;
    goto v_15992;
v_15986:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_15987;
v_15988:
    goto v_15999;
v_15995:
    goto v_16005;
v_16001:
    v_16098 = stack[-8];
    goto v_16002;
v_16003:
    v_16097 = stack[-2];
    goto v_16004;
v_16005:
    goto v_16001;
v_16002:
    goto v_16003;
v_16004:
    fn = elt(env, 4); // ashift
    v_16098 = (*qfn2(fn))(fn, v_16098, v_16097);
    env = stack[-9];
    goto v_15996;
v_15997:
    v_16097 = stack[-5];
    goto v_15998;
v_15999:
    goto v_15995;
v_15996:
    goto v_15997;
v_15998:
    v_16098 = plus2(v_16098, v_16097);
    env = stack[-9];
    goto v_15989;
v_15990:
    v_16097 = stack[-3];
    goto v_15991;
v_15992:
    goto v_15986;
v_15987:
    goto v_15988;
v_15989:
    goto v_15990;
v_15991:
    v_16097 = list2star(stack[0], v_16098, v_16097);
    env = stack[-9];
    goto v_15856;
v_15976:
    goto v_16019;
v_16013:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_16014;
v_16015:
    goto v_16026;
v_16022:
    stack[-1] = stack[-8];
    goto v_16023;
v_16024:
    goto v_16033;
v_16029:
    stack[-3] = stack[-5];
    goto v_16030;
v_16031:
    v_16097 = stack[-2];
    v_16097 = negate(v_16097);
    env = stack[-9];
    goto v_16032;
v_16033:
    goto v_16029;
v_16030:
    goto v_16031;
v_16032:
    fn = elt(env, 4); // ashift
    v_16097 = (*qfn2(fn))(fn, stack[-3], v_16097);
    env = stack[-9];
    goto v_16025;
v_16026:
    goto v_16022;
v_16023:
    goto v_16024;
v_16025:
    v_16098 = plus2(stack[-1], v_16097);
    env = stack[-9];
    goto v_16016;
v_16017:
    v_16097 = stack[-4];
    goto v_16018;
v_16019:
    goto v_16013;
v_16014:
    goto v_16015;
v_16016:
    goto v_16017;
v_16018:
    v_16097 = list2star(stack[0], v_16098, v_16097);
    env = stack[-9];
    goto v_15856;
    v_16097 = nil;
v_15856:
    stack[-2] = v_16097;
    v_16097 = stack[-2];
    v_16097 = qcdr(v_16097);
    v_16097 = qcar(v_16097);
    v_16099 = v_16097;
    goto v_16053;
v_16049:
    v_16098 = v_16099;
    goto v_16050;
v_16051:
    v_16097 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16052;
v_16053:
    goto v_16049;
v_16050:
    goto v_16051;
v_16052:
    if (v_16098 == v_16097) goto v_16047;
    else goto v_16048;
v_16047:
    goto v_16063;
v_16057:
    v_16099 = elt(env, 1); // !:rd!:
    goto v_16058;
v_16059:
    v_16098 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16060;
v_16061:
    v_16097 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_16062;
v_16063:
    goto v_16057;
v_16058:
    goto v_16059;
v_16060:
    goto v_16061;
v_16062:
    return list2star(v_16099, v_16098, v_16097);
v_16048:
    goto v_16072;
v_16068:
    v_16098 = v_16099;
    goto v_16069;
v_16070:
    v_16097 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_16071;
v_16072:
    goto v_16068;
v_16069:
    goto v_16070;
v_16071:
    fn = elt(env, 5); // inorm
    v_16097 = (*qfn2(fn))(fn, v_16098, v_16097);
    env = stack[-9];
    v_16099 = v_16097;
    goto v_16082;
v_16076:
    stack[-1] = elt(env, 1); // !:rd!:
    goto v_16077;
v_16078:
    v_16097 = v_16099;
    stack[0] = qcar(v_16097);
    goto v_16079;
v_16080:
    goto v_16091;
v_16087:
    v_16097 = v_16099;
    v_16098 = qcdr(v_16097);
    goto v_16088;
v_16089:
    v_16097 = stack[-2];
    v_16097 = qcdr(v_16097);
    v_16097 = qcdr(v_16097);
    goto v_16090;
v_16091:
    goto v_16087;
v_16088:
    goto v_16089;
v_16090:
    v_16097 = plus2(v_16098, v_16097);
    goto v_16081;
v_16082:
    goto v_16076;
v_16077:
    goto v_16078;
v_16079:
    goto v_16080;
v_16081:
    {
        LispObject v_16109 = stack[-1];
        LispObject v_16110 = stack[0];
        return list2star(v_16109, v_16110, v_16097);
    }
    return onevalue(v_16097);
}



// Code for edge_new_parents

static LispObject CC_edge_new_parents(LispObject env,
                         LispObject v_15845)
{
    env = qenv(env);
    LispObject v_15878, v_15879, v_15880;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_15845);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_15880 = v_15845;
// end of prologue
    goto v_15855;
v_15851:
    v_15878 = v_15880;
    v_15879 = qcar(v_15878);
    goto v_15852;
v_15853:
    v_15878 = qvalue(elt(env, 1)); // old_edge_list
    goto v_15854;
v_15855:
    goto v_15851;
v_15852:
    goto v_15853;
v_15854:
    v_15878 = Lassoc(nil, v_15879, v_15878);
    if (v_15878 == nil) goto v_15850;
    v_15878 = nil;
    goto v_15848;
v_15850:
    v_15878 = v_15880;
    v_15878 = qcdr(v_15878);
    v_15878 = qcar(v_15878);
    goto v_15873;
v_15869:
    v_15879 = v_15878;
    v_15879 = qcar(v_15879);
    goto v_15870;
v_15871:
    v_15878 = qcdr(v_15878);
    goto v_15872;
v_15873:
    goto v_15869;
v_15870:
    goto v_15871;
v_15872:
    v_15878 = list2(v_15879, v_15878);
    env = stack[0];
    {
        fn = elt(env, 2); // edge_new_parent
        return (*qfn1(fn))(fn, v_15878);
    }
    v_15878 = nil;
v_15848:
    return onevalue(v_15878);
}



// Code for idtomind

static LispObject CC_idtomind(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_15879, v_15880, v_15881;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15881 = v_15846;
    v_15879 = v_15845;
// end of prologue
    goto v_15856;
v_15852:
    v_15880 = v_15879;
    goto v_15853;
v_15854:
    v_15879 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_15855;
v_15856:
    goto v_15852;
v_15853:
    goto v_15854;
v_15855:
    if (v_15880 == v_15879) goto v_15850;
    else goto v_15851;
v_15850:
    goto v_15863;
v_15859:
    v_15879 = v_15881;
    goto v_15860;
v_15861:
    v_15880 = qvalue(elt(env, 1)); // i2m_jetspace!*
    goto v_15862;
v_15863:
    goto v_15859;
v_15860:
    goto v_15861;
v_15862:
    v_15879 = Lassoc(nil, v_15879, v_15880);
    v_15879 = qcdr(v_15879);
    goto v_15849;
v_15851:
    goto v_15874;
v_15870:
    v_15879 = v_15881;
    goto v_15871;
v_15872:
    v_15880 = qvalue(elt(env, 2)); // i2m_jetspace_odd!*
    goto v_15873;
v_15874:
    goto v_15870;
v_15871:
    goto v_15872;
v_15873:
    v_15879 = Lassoc(nil, v_15879, v_15880);
    v_15879 = qcdr(v_15879);
    goto v_15849;
    v_15879 = nil;
v_15849:
    return onevalue(v_15879);
}



// Code for open

static LispObject CC_open(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_15925, v_15926, v_15927, v_15928;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_15846,v_15845);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_15845,v_15846);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_15927 = v_15846;
    v_15928 = v_15845;
// end of prologue
    goto v_15856;
v_15852:
    v_15926 = v_15927;
    goto v_15853;
v_15854:
    v_15925 = elt(env, 1); // input
    goto v_15855;
v_15856:
    goto v_15852;
v_15853:
    goto v_15854;
v_15855:
    if (v_15926 == v_15925) goto v_15850;
    else goto v_15851;
v_15850:
    goto v_15864;
v_15860:
    v_15926 = v_15928;
    goto v_15861;
v_15862:
    v_15925 = (LispObject)1040+TAG_FIXNUM; // 65
    goto v_15863;
v_15864:
    goto v_15860;
v_15861:
    goto v_15862;
v_15863:
    {
        fn = elt(env, 5); // internal!-open
        return (*qfn2(fn))(fn, v_15926, v_15925);
    }
v_15851:
    goto v_15873;
v_15869:
    v_15926 = v_15927;
    goto v_15870;
v_15871:
    v_15925 = elt(env, 2); // output
    goto v_15872;
v_15873:
    goto v_15869;
v_15870:
    goto v_15871;
v_15872:
    if (v_15926 == v_15925) goto v_15867;
    else goto v_15868;
v_15867:
    goto v_15881;
v_15877:
    stack[0] = v_15928;
    goto v_15878;
v_15879:
    goto v_15888;
v_15884:
    v_15926 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_15885;
v_15886:
    v_15925 = (LispObject)832+TAG_FIXNUM; // 52
    goto v_15887;
v_15888:
    goto v_15884;
v_15885:
    goto v_15886;
v_15887:
    v_15925 = plus2(v_15926, v_15925);
    env = stack[-1];
    goto v_15880;
v_15881:
    goto v_15877;
v_15878:
    goto v_15879;
v_15880:
    {
        LispObject v_15930 = stack[0];
        fn = elt(env, 5); // internal!-open
        return (*qfn2(fn))(fn, v_15930, v_15925);
    }
v_15868:
    goto v_15897;
v_15893:
    v_15926 = v_15927;
    goto v_15894;
v_15895:
    v_15925 = elt(env, 3); // append
    goto v_15896;
v_15897:
    goto v_15893;
v_15894:
    goto v_15895;
v_15896:
    if (v_15926 == v_15925) goto v_15891;
    else goto v_15892;
v_15891:
    goto v_15905;
v_15901:
    stack[0] = v_15928;
    goto v_15902;
v_15903:
    goto v_15912;
v_15908:
    v_15926 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_15909;
v_15910:
    v_15925 = (LispObject)640+TAG_FIXNUM; // 40
    goto v_15911;
v_15912:
    goto v_15908;
v_15909:
    goto v_15910;
v_15911:
    v_15925 = plus2(v_15926, v_15925);
    env = stack[-1];
    goto v_15904;
v_15905:
    goto v_15901;
v_15902:
    goto v_15903;
v_15904:
    {
        LispObject v_15931 = stack[0];
        fn = elt(env, 5); // internal!-open
        return (*qfn2(fn))(fn, v_15931, v_15925);
    }
v_15892:
    goto v_15922;
v_15918:
    v_15925 = elt(env, 4); // "bad direction ~A in open"
    goto v_15919;
v_15920:
    v_15926 = v_15927;
    goto v_15921;
v_15922:
    goto v_15918;
v_15919:
    goto v_15920;
v_15921:
    {
        fn = elt(env, 6); // error
        return (*qfn2(fn))(fn, v_15925, v_15926);
    }
    v_15925 = nil;
    return onevalue(v_15925);
}



// Code for cl_sordpl

static LispObject CC_cl_sordpl(LispObject env,
                         LispObject v_15845, LispObject v_15846)
{
    env = qenv(env);
    LispObject v_15888, v_15889, v_15890, v_15891;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15889 = v_15846;
    v_15890 = v_15845;
// end of prologue
v_15850:
    v_15888 = v_15889;
    if (v_15888 == nil) goto v_15853;
    else goto v_15854;
v_15853:
    v_15888 = nil;
    goto v_15849;
v_15854:
    v_15888 = v_15890;
    if (v_15888 == nil) goto v_15857;
    else goto v_15858;
v_15857:
    v_15888 = lisp_true;
    goto v_15849;
v_15858:
    goto v_15867;
v_15863:
    v_15888 = v_15890;
    v_15891 = qcar(v_15888);
    goto v_15864;
v_15865:
    v_15888 = v_15889;
    v_15888 = qcar(v_15888);
    goto v_15866;
v_15867:
    goto v_15863;
v_15864:
    goto v_15865;
v_15866:
    if (equal(v_15891, v_15888)) goto v_15862;
    goto v_15877;
v_15873:
    v_15888 = v_15890;
    v_15888 = qcar(v_15888);
    goto v_15874;
v_15875:
    v_15889 = qcar(v_15889);
    goto v_15876;
v_15877:
    goto v_15873;
v_15874:
    goto v_15875;
v_15876:
    {
        fn = elt(env, 1); // cl_sordp
        return (*qfn2(fn))(fn, v_15888, v_15889);
    }
v_15862:
    v_15888 = v_15890;
    v_15888 = qcdr(v_15888);
    v_15890 = v_15888;
    v_15888 = v_15889;
    v_15888 = qcdr(v_15888);
    v_15889 = v_15888;
    goto v_15850;
    v_15888 = nil;
v_15849:
    return onevalue(v_15888);
}



setup_type const u29_setup[] =
{
    {"cnrd",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cnrd},
    {"ps:expression",           CC_psTexpression,TOO_MANY_1,   WRONG_NO_1},
    {"vevstrictlydivides?",     TOO_FEW_2,      CC_vevstrictlydividesW,WRONG_NO_2},
    {"critical_element",        CC_critical_element,TOO_MANY_1,WRONG_NO_1},
    {"contract-strand",         TOO_FEW_2,      CC_contractKstrand,WRONG_NO_2},
    {"assert_declarestat1",     CC_assert_declarestat1,TOO_MANY_1,WRONG_NO_1},
    {"sf2mv",                   TOO_FEW_2,      CC_sf2mv,      WRONG_NO_2},
    {"fs:prepfn:",              CC_fsTprepfnT,  TOO_MANY_1,    WRONG_NO_1},
    {"st_consolidate",          CC_st_consolidate,TOO_MANY_1,  WRONG_NO_1},
    {"ratminus",                CC_ratminus,    TOO_MANY_1,    WRONG_NO_1},
    {"all_sml_opchar",          CC_all_sml_opchar,TOO_MANY_1,  WRONG_NO_1},
    {"hasarg",                  TOO_FEW_2,      CC_hasarg,     WRONG_NO_2},
    {"simpexpt11",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_simpexpt11},
    {"rndifference:",           TOO_FEW_2,      CC_rndifferenceT,WRONG_NO_2},
    {"talp_copy",               CC_talp_copy,   TOO_MANY_1,    WRONG_NO_1},
    {"opfneval",                CC_opfneval,    TOO_MANY_1,    WRONG_NO_1},
    {"doublep",                 CC_doublep,     TOO_MANY_1,    WRONG_NO_1},
    {"groebsavelterm",          CC_groebsavelterm,TOO_MANY_1,  WRONG_NO_1},
    {"physop-multfnc",          TOO_FEW_2,      CC_physopKmultfnc,WRONG_NO_2},
    {"red_tailred",             TOO_FEW_2,      CC_red_tailred,WRONG_NO_2},
    {"ifstat",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ifstat},
    {"tayexp-minus",            CC_tayexpKminus,TOO_MANY_1,    WRONG_NO_1},
    {"mk+trace",                CC_mkLtrace,    TOO_MANY_1,    WRONG_NO_1},
    {"talp_specsubat",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_specsubat},
    {"qqe_arg-check-q",         CC_qqe_argKcheckKq,TOO_MANY_1, WRONG_NO_1},
    {"pasf_sisub-gand",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pasf_sisubKgand},
    {"vdp_sugar",               CC_vdp_sugar,   TOO_MANY_1,    WRONG_NO_1},
    {"dm-mkfloat",              CC_dmKmkfloat,  TOO_MANY_1,    WRONG_NO_1},
    {"sc_geq",                  TOO_FEW_2,      CC_sc_geq,     WRONG_NO_2},
    {"bcfd",                    CC_bcfd,        TOO_MANY_1,    WRONG_NO_1},
    {"rd:times",                TOO_FEW_2,      CC_rdTtimes,   WRONG_NO_2},
    {"permp",                   TOO_FEW_2,      CC_permp,      WRONG_NO_2},
    {"groeb=rf1",               TOO_FEW_2,      CC_groebMrf1,  WRONG_NO_2},
    {"expansion_name",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_expansion_name},
    {"ofsf_posvarp",            TOO_FEW_2,      CC_ofsf_posvarp,WRONG_NO_2},
    {"cquotegex",               CC_cquotegex,   TOO_MANY_1,    WRONG_NO_1},
    {"negind",                  TOO_FEW_2,      CC_negind,     WRONG_NO_2},
    {"cl_rename-vars",          CC_cl_renameKvars,TOO_MANY_1,  WRONG_NO_1},
    {"dip_f2dip1",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dip_f2dip1},
    {"getdec",                  CC_getdec,      TOO_MANY_1,    WRONG_NO_1},
    {"evrevgradlexcomp",        TOO_FEW_2,      CC_evrevgradlexcomp,WRONG_NO_2},
    {"unresidp",                CC_unresidp,    TOO_MANY_1,    WRONG_NO_1},
    {"boolvalue*",              CC_boolvalueH,  TOO_MANY_1,    WRONG_NO_1},
    {"no-side-effect-listp",    CC_noKsideKeffectKlistp,TOO_MANY_1,WRONG_NO_1},
    {"quotpri",                 CC_quotpri,     TOO_MANY_1,    WRONG_NO_1},
    {"mo_2a",                   CC_mo_2a,       TOO_MANY_1,    WRONG_NO_1},
    {"cde_odd_derivatives",     CC_cde_odd_derivatives,TOO_MANY_1,WRONG_NO_1},
    {"arg1of2",                 TOO_FEW_2,      CC_arg1of2,    WRONG_NO_2},
    {"mkfil*",                  CC_mkfilH,      TOO_MANY_1,    WRONG_NO_1},
    {"pushback",                TOO_FEW_2,      CC_pushback,   WRONG_NO_2},
    {"talp_getinvfsym",         TOO_FEW_2,      CC_talp_getinvfsym,WRONG_NO_2},
    {"qqe_arg-check-lb-rb",     CC_qqe_argKcheckKlbKrb,TOO_MANY_1,WRONG_NO_1},
    {"pasf_pdp",                CC_pasf_pdp,    TOO_MANY_1,    WRONG_NO_1},
    {"get-height",              CC_getKheight,  TOO_MANY_1,    WRONG_NO_1},
    {"omfir",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_omfir},
    {"initarg",                 CC_initarg,     TOO_MANY_1,    WRONG_NO_1},
    {"plubf",                   TOO_FEW_2,      CC_plubf,      WRONG_NO_2},
    {"edge_new_parents",        CC_edge_new_parents,TOO_MANY_1,WRONG_NO_1},
    {"idtomind",                TOO_FEW_2,      CC_idtomind,   WRONG_NO_2},
    {"open",                    TOO_FEW_2,      CC_open,       WRONG_NO_2},
    {"cl_sordpl",               TOO_FEW_2,      CC_cl_sordpl,  WRONG_NO_2},
    {NULL, (one_args *)"u29", (two_args *)"81796 3250302 8853103", 0}
};

// end of generated code
