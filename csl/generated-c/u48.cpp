
// $destdir/u48.c        Machine generated C code

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



// Code for mksfpf

static LispObject CC_mksfpf(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28389, v_28390;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28257;
    v_28389 = v_28256;
// end of prologue
    fn = elt(env, 3); // mkprod
    v_28389 = (*qfn1(fn))(fn, v_28389);
    env = stack[-2];
    stack[-1] = v_28389;
    goto v_28270;
v_28266:
    v_28390 = stack[0];
    goto v_28267;
v_28268:
    v_28389 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28269;
v_28270:
    goto v_28266;
v_28267:
    goto v_28268;
v_28269:
    if (v_28390 == v_28389) goto v_28264;
    else goto v_28265;
v_28264:
    v_28389 = stack[-1];
    goto v_28263;
v_28265:
    v_28389 = stack[-1];
    if (!consp(v_28389)) goto v_28278;
    else goto v_28279;
v_28278:
    v_28389 = lisp_true;
    goto v_28277;
v_28279:
    v_28389 = stack[-1];
    v_28389 = qcar(v_28389);
    v_28389 = (consp(v_28389) ? nil : lisp_true);
    goto v_28277;
    v_28389 = nil;
v_28277:
    if (v_28389 == nil) goto v_28275;
    goto v_28292;
v_28288:
    v_28390 = stack[-1];
    goto v_28289;
v_28290:
    v_28389 = stack[0];
    goto v_28291;
v_28292:
    goto v_28288;
v_28289:
    goto v_28290;
v_28291:
    {
        fn = elt(env, 4); // !:expt
        return (*qfn2(fn))(fn, v_28390, v_28389);
    }
v_28275:
    goto v_28303;
v_28299:
    v_28390 = stack[0];
    goto v_28300;
v_28301:
    v_28389 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28302;
v_28303:
    goto v_28299;
v_28300:
    goto v_28301;
v_28302:
    v_28389 = (LispObject)geq2(v_28390, v_28389);
    v_28389 = v_28389 ? lisp_true : nil;
    env = stack[-2];
    if (v_28389 == nil) goto v_28296;
    v_28389 = stack[-1];
    v_28389 = qcar(v_28389);
    v_28389 = qcdr(v_28389);
    v_28389 = Lonep(nil, v_28389);
    env = stack[-2];
    if (v_28389 == nil) goto v_28296;
    v_28389 = stack[-1];
    v_28389 = qcdr(v_28389);
    if (v_28389 == nil) goto v_28312;
    else goto v_28296;
v_28312:
    goto v_28320;
v_28316:
    v_28389 = stack[-1];
    v_28389 = qcar(v_28389);
    v_28389 = qcar(v_28389);
    v_28390 = qcdr(v_28389);
    goto v_28317;
v_28318:
    v_28389 = stack[0];
    goto v_28319;
v_28320:
    goto v_28316;
v_28317:
    goto v_28318;
v_28319:
    v_28390 = times2(v_28390, v_28389);
    env = stack[-2];
    v_28389 = stack[-1];
    v_28389 = qcar(v_28389);
    v_28389 = qcar(v_28389);
    v_28389 = qcar(v_28389);
    stack[-1] = v_28390;
    stack[0] = v_28389;
    goto v_28336;
v_28332:
    v_28390 = stack[0];
    goto v_28333;
v_28334:
    v_28389 = qvalue(elt(env, 1)); // asymplis!*
    goto v_28335;
v_28336:
    goto v_28332;
v_28333:
    goto v_28334;
v_28335:
    v_28389 = Lassoc(nil, v_28390, v_28389);
    v_28390 = v_28389;
    v_28389 = qvalue(elt(env, 2)); // subfg!*
    if (v_28389 == nil) goto v_28344;
    v_28389 = v_28390;
    if (v_28389 == nil) goto v_28344;
    goto v_28356;
v_28352:
    v_28389 = v_28390;
    v_28390 = qcdr(v_28389);
    goto v_28353;
v_28354:
    v_28389 = stack[-1];
    goto v_28355;
v_28356:
    goto v_28352;
v_28353:
    goto v_28354;
v_28355:
    v_28389 = (LispObject)lesseq2(v_28390, v_28389);
    v_28389 = v_28389 ? lisp_true : nil;
    env = stack[-2];
    if (v_28389 == nil) goto v_28344;
    v_28389 = nil;
    goto v_28342;
v_28344:
    goto v_28369;
v_28365:
    goto v_28375;
v_28371:
    v_28390 = stack[0];
    goto v_28372;
v_28373:
    v_28389 = stack[-1];
    goto v_28374;
v_28375:
    goto v_28371;
v_28372:
    goto v_28373;
v_28374:
    fn = elt(env, 5); // mksp
    v_28390 = (*qfn2(fn))(fn, v_28390, v_28389);
    env = stack[-2];
    goto v_28366;
v_28367:
    v_28389 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28368;
v_28369:
    goto v_28365;
v_28366:
    goto v_28367;
v_28368:
    v_28389 = cons(v_28390, v_28389);
    return ncons(v_28389);
    v_28389 = nil;
v_28342:
    goto v_28263;
v_28296:
    goto v_28386;
v_28382:
    v_28390 = stack[-1];
    goto v_28383;
v_28384:
    v_28389 = stack[0];
    goto v_28385;
v_28386:
    goto v_28382;
v_28383:
    goto v_28384;
v_28385:
    {
        fn = elt(env, 6); // exptf2
        return (*qfn2(fn))(fn, v_28390, v_28389);
    }
    v_28389 = nil;
v_28263:
    return onevalue(v_28389);
}



// Code for gb_searchinlist

static LispObject CC_gb_searchinlist(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28286, v_28287;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28257;
    stack[-1] = v_28256;
// end of prologue
v_28261:
    v_28286 = stack[0];
    if (v_28286 == nil) goto v_28264;
    else goto v_28265;
v_28264:
    v_28286 = nil;
    goto v_28260;
v_28265:
    goto v_28275;
v_28271:
    v_28286 = stack[0];
    v_28286 = qcar(v_28286);
    fn = elt(env, 1); // vdp_evlmon
    v_28287 = (*qfn1(fn))(fn, v_28286);
    env = stack[-2];
    goto v_28272;
v_28273:
    v_28286 = stack[-1];
    goto v_28274;
v_28275:
    goto v_28271;
v_28272:
    goto v_28273;
v_28274:
    fn = elt(env, 2); // gb_buch!-ev_divides!?
    v_28286 = (*qfn2(fn))(fn, v_28287, v_28286);
    env = stack[-2];
    if (v_28286 == nil) goto v_28269;
    v_28286 = stack[0];
    v_28286 = qcar(v_28286);
    goto v_28260;
v_28269:
    v_28286 = stack[0];
    v_28286 = qcdr(v_28286);
    stack[0] = v_28286;
    goto v_28261;
    v_28286 = nil;
v_28260:
    return onevalue(v_28286);
}



// Code for copy_vect

static LispObject CC_copy_vect(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28288, v_28289, v_28290;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28257;
    stack[-1] = v_28256;
// end of prologue
    v_28288 = stack[-1];
    v_28288 = qcdr(v_28288);
    v_28288 = qcar(v_28288);
    fn = elt(env, 2); // fullcopy
    v_28288 = (*qfn1(fn))(fn, v_28288);
    env = stack[-2];
    v_28289 = stack[0];
    if (v_28289 == nil) goto v_28270;
    else goto v_28271;
v_28270:
    v_28289 = stack[-1];
    v_28289 = qcdr(v_28289);
    v_28289 = qcdr(v_28289);
    v_28289 = qcar(v_28289);
    stack[0] = v_28289;
    goto v_28269;
v_28271:
v_28269:
    goto v_28284;
v_28278:
    v_28290 = elt(env, 1); // sparsemat
    goto v_28279;
v_28280:
    v_28289 = v_28288;
    goto v_28281;
v_28282:
    v_28288 = stack[0];
    goto v_28283;
v_28284:
    goto v_28278;
v_28279:
    goto v_28280;
v_28281:
    goto v_28282;
v_28283:
    return list3(v_28290, v_28289, v_28288);
    return onevalue(v_28288);
}



// Code for nestzerop!:

static LispObject CC_nestzeropT(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28274, v_28275;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28256);
    }
// copy arguments values to proper place
    v_28275 = v_28256;
// end of prologue
    v_28274 = v_28275;
    v_28274 = integerp(v_28274);
    if (v_28274 == nil) goto v_28261;
    v_28274 = v_28275;
    fn = elt(env, 1); // simp
    v_28274 = (*qfn1(fn))(fn, v_28274);
    goto v_28259;
v_28261:
    v_28274 = v_28275;
    v_28274 = qcdr(v_28274);
    v_28274 = qcdr(v_28274);
    v_28274 = qcdr(v_28274);
    goto v_28259;
    v_28274 = nil;
v_28259:
    v_28274 = qcar(v_28274);
    v_28274 = (v_28274 == nil ? lisp_true : nil);
    return onevalue(v_28274);
}



// Code for dipretimes

static LispObject CC_dipretimes(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28300, v_28301, v_28302;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28301 = v_28256;
// end of prologue
v_28260:
    goto v_28269;
v_28265:
    v_28300 = v_28301;
    v_28302 = qcar(v_28300);
    goto v_28266;
v_28267:
    v_28300 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28268;
v_28269:
    goto v_28265;
v_28266:
    goto v_28267;
v_28268:
    if (v_28302 == v_28300) goto v_28263;
    else goto v_28264;
v_28263:
    v_28300 = v_28301;
    v_28300 = qcdr(v_28300);
    if (v_28300 == nil) goto v_28276;
    v_28300 = v_28301;
    v_28300 = qcdr(v_28300);
    v_28301 = v_28300;
    goto v_28260;
v_28276:
    v_28300 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28259;
    goto v_28262;
v_28264:
    v_28300 = v_28301;
    v_28300 = qcdr(v_28300);
    if (v_28300 == nil) goto v_28284;
    else goto v_28285;
v_28284:
    v_28300 = v_28301;
    v_28300 = qcar(v_28300);
    goto v_28259;
v_28285:
    goto v_28297;
v_28293:
    v_28300 = elt(env, 1); // times
    goto v_28294;
v_28295:
    goto v_28296;
v_28297:
    goto v_28293;
v_28294:
    goto v_28295;
v_28296:
    return cons(v_28300, v_28301);
v_28262:
    v_28300 = nil;
v_28259:
    return onevalue(v_28300);
}



// Code for natnump

static LispObject CC_natnump(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28275, v_28276;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28275 = v_28256;
// end of prologue
    v_28276 = v_28275;
    v_28276 = integerp(v_28276);
    if (v_28276 == nil) goto v_28260;
    else goto v_28261;
v_28260:
    v_28275 = nil;
    goto v_28259;
v_28261:
    goto v_28272;
v_28268:
    v_28276 = v_28275;
    goto v_28269;
v_28270:
    v_28275 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28271;
v_28272:
    goto v_28268;
v_28269:
    goto v_28270;
v_28271:
        return Lgeq(nil, v_28276, v_28275);
    v_28275 = nil;
v_28259:
    return onevalue(v_28275);
}



// Code for !*a2kwoweight

static LispObject CC_Ha2kwoweight(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28286, v_28287;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28256);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_28256;
// end of prologue
    v_28287 = lisp_true;
    v_28286 = nil;
// Binding !*uncached
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = v_28287; // !*uncached
// Binding wtl!*
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 2, -1);
    qvalue(elt(env, 2)) = v_28286; // wtl!*
    v_28286 = stack[-2];
    fn = elt(env, 4); // simp!*
    v_28286 = (*qfn1(fn))(fn, v_28286);
    env = stack[-4];
    stack[0] = v_28286;
    v_28286 = stack[0];
    fn = elt(env, 5); // kernp
    v_28286 = (*qfn1(fn))(fn, v_28286);
    env = stack[-4];
    if (v_28286 == nil) goto v_28268;
    v_28286 = stack[0];
    v_28286 = qcar(v_28286);
    v_28286 = qcar(v_28286);
    v_28286 = qcar(v_28286);
    v_28286 = qcar(v_28286);
    goto v_28266;
v_28268:
    goto v_28283;
v_28279:
    v_28287 = stack[-2];
    goto v_28280;
v_28281:
    v_28286 = elt(env, 3); // kernel
    goto v_28282;
v_28283:
    goto v_28279;
v_28280:
    goto v_28281;
v_28282:
    fn = elt(env, 6); // typerr
    v_28286 = (*qfn2(fn))(fn, v_28287, v_28286);
    goto v_28266;
    v_28286 = nil;
v_28266:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_28286);
}



// Code for aex_psremseq

static LispObject CC_aex_psremseq(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28356, v_28357, v_28358;
    LispObject fn;
    LispObject v_28258, v_28257, v_28256;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "aex_psremseq");
    va_start(aa, nargs);
    v_28256 = va_arg(aa, LispObject);
    v_28257 = va_arg(aa, LispObject);
    v_28258 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_28258,v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_28256,v_28257,v_28258);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_28258;
    stack[-1] = v_28257;
    stack[-2] = v_28256;
// end of prologue
    goto v_28267;
    goto v_28265;
v_28267:
v_28265:
    goto v_28274;
v_28270:
    v_28356 = stack[-2];
    fn = elt(env, 1); // aex_mklcnt
    v_28357 = (*qfn1(fn))(fn, v_28356);
    env = stack[-4];
    goto v_28271;
v_28272:
    v_28356 = stack[0];
    goto v_28273;
v_28274:
    goto v_28270;
v_28271:
    goto v_28272;
v_28273:
    fn = elt(env, 2); // aex_divposcnt
    v_28356 = (*qfn2(fn))(fn, v_28357, v_28356);
    env = stack[-4];
    stack[-2] = v_28356;
    goto v_28283;
v_28279:
    v_28356 = stack[-1];
    fn = elt(env, 1); // aex_mklcnt
    v_28357 = (*qfn1(fn))(fn, v_28356);
    env = stack[-4];
    goto v_28280;
v_28281:
    v_28356 = stack[0];
    goto v_28282;
v_28283:
    goto v_28279;
v_28280:
    goto v_28281;
v_28282:
    fn = elt(env, 2); // aex_divposcnt
    v_28356 = (*qfn2(fn))(fn, v_28357, v_28356);
    env = stack[-4];
    stack[-1] = v_28356;
    goto v_28292;
v_28288:
    v_28357 = stack[-1];
    goto v_28289;
v_28290:
    v_28356 = stack[-2];
    goto v_28291;
v_28292:
    goto v_28288;
v_28289:
    goto v_28290;
v_28291:
    v_28356 = list2(v_28357, v_28356);
    env = stack[-4];
    stack[-3] = v_28356;
v_28297:
    goto v_28307;
v_28303:
    goto v_28313;
v_28309:
    v_28357 = stack[-1];
    goto v_28310;
v_28311:
    v_28356 = stack[0];
    goto v_28312;
v_28313:
    goto v_28309;
v_28310:
    goto v_28311;
v_28312:
    fn = elt(env, 3); // aex_deg
    v_28357 = (*qfn2(fn))(fn, v_28357, v_28356);
    env = stack[-4];
    goto v_28304;
v_28305:
    v_28356 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28306;
v_28307:
    goto v_28303;
v_28304:
    goto v_28305;
v_28306:
    v_28356 = (LispObject)greaterp2(v_28357, v_28356);
    v_28356 = v_28356 ? lisp_true : nil;
    env = stack[-4];
    if (v_28356 == nil) goto v_28300;
    else goto v_28301;
v_28300:
    goto v_28296;
v_28301:
    goto v_28325;
v_28319:
    v_28358 = stack[-2];
    goto v_28320;
v_28321:
    v_28357 = stack[-1];
    goto v_28322;
v_28323:
    v_28356 = stack[0];
    goto v_28324;
v_28325:
    goto v_28319;
v_28320:
    goto v_28321;
v_28322:
    goto v_28323;
v_28324:
    fn = elt(env, 4); // aex_psrem
    v_28356 = (*qfnn(fn))(fn, 3, v_28358, v_28357, v_28356);
    env = stack[-4];
    v_28357 = v_28356;
    v_28356 = stack[-1];
    stack[-2] = v_28356;
    v_28356 = v_28357;
    fn = elt(env, 5); // aex_neg
    v_28356 = (*qfn1(fn))(fn, v_28356);
    env = stack[-4];
    stack[-1] = v_28356;
    v_28356 = stack[-1];
    fn = elt(env, 6); // aex_simplenullp
    v_28356 = (*qfn1(fn))(fn, v_28356);
    env = stack[-4];
    if (v_28356 == nil) goto v_28334;
    else goto v_28335;
v_28334:
    goto v_28343;
v_28339:
    v_28357 = stack[-1];
    goto v_28340;
v_28341:
    v_28356 = stack[0];
    goto v_28342;
v_28343:
    goto v_28339;
v_28340:
    goto v_28341;
v_28342:
    fn = elt(env, 2); // aex_divposcnt
    v_28356 = (*qfn2(fn))(fn, v_28357, v_28356);
    env = stack[-4];
    stack[-1] = v_28356;
    goto v_28351;
v_28347:
    v_28357 = stack[-1];
    goto v_28348;
v_28349:
    v_28356 = stack[-3];
    goto v_28350;
v_28351:
    goto v_28347;
v_28348:
    goto v_28349;
v_28350:
    v_28356 = cons(v_28357, v_28356);
    env = stack[-4];
    stack[-3] = v_28356;
    goto v_28333;
v_28335:
v_28333:
    goto v_28297;
v_28296:
    v_28356 = stack[-3];
        return Lnreverse(nil, v_28356);
    return onevalue(v_28356);
}



// Code for monomcomparelex

static LispObject CC_monomcomparelex(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28398, v_28399, v_28400;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_28257;
    v_28398 = v_28256;
// end of prologue
    goto v_28271;
v_28267:
    v_28400 = nil;
    goto v_28268;
v_28269:
    goto v_28277;
v_28273:
    v_28399 = v_28398;
    goto v_28274;
v_28275:
    v_28398 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28276;
v_28277:
    goto v_28273;
v_28274:
    goto v_28275;
v_28276:
    v_28398 = *(LispObject *)((char *)v_28399 + (CELL-TAG_VECTOR) + (((intptr_t)v_28398-TAG_FIXNUM)/(16/CELL)));
    goto v_28270;
v_28271:
    goto v_28267;
v_28268:
    goto v_28269;
v_28270:
    v_28398 = cons(v_28400, v_28398);
    env = stack[-3];
    v_28398 = Lreverse(nil, v_28398);
    env = stack[-3];
    v_28398 = qcdr(v_28398);
    stack[-2] = v_28398;
    goto v_28288;
v_28284:
    v_28400 = nil;
    goto v_28285;
v_28286:
    goto v_28294;
v_28290:
    v_28399 = stack[0];
    goto v_28291;
v_28292:
    v_28398 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28293;
v_28294:
    goto v_28290;
v_28291:
    goto v_28292;
v_28293:
    v_28398 = *(LispObject *)((char *)v_28399 + (CELL-TAG_VECTOR) + (((intptr_t)v_28398-TAG_FIXNUM)/(16/CELL)));
    goto v_28287;
v_28288:
    goto v_28284;
v_28285:
    goto v_28286;
v_28287:
    v_28398 = cons(v_28400, v_28398);
    env = stack[-3];
    v_28398 = Lreverse(nil, v_28398);
    env = stack[-3];
    v_28398 = qcdr(v_28398);
    stack[-1] = v_28398;
    v_28398 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_28398;
v_28302:
    v_28398 = stack[-2];
    v_28398 = qcar(v_28398);
    if (v_28398 == nil) goto v_28305;
    v_28398 = stack[-1];
    v_28398 = qcar(v_28398);
    if (v_28398 == nil) goto v_28305;
    goto v_28306;
v_28305:
    goto v_28301;
v_28306:
    goto v_28323;
v_28319:
    v_28398 = stack[-2];
    v_28399 = qcar(v_28398);
    goto v_28320;
v_28321:
    v_28398 = stack[-1];
    v_28398 = qcar(v_28398);
    goto v_28322;
v_28323:
    goto v_28319;
v_28320:
    goto v_28321;
v_28322:
    v_28398 = (LispObject)lessp2(v_28399, v_28398);
    v_28398 = v_28398 ? lisp_true : nil;
    env = stack[-3];
    if (v_28398 == nil) goto v_28317;
    v_28398 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_28398;
    v_28398 = nil;
    v_28398 = ncons(v_28398);
    env = stack[-3];
    stack[-2] = v_28398;
    goto v_28315;
v_28317:
    goto v_28339;
v_28335:
    v_28398 = stack[-2];
    v_28399 = qcar(v_28398);
    goto v_28336;
v_28337:
    v_28398 = stack[-1];
    v_28398 = qcar(v_28398);
    goto v_28338;
v_28339:
    goto v_28335;
v_28336:
    goto v_28337;
v_28338:
    v_28398 = (LispObject)greaterp2(v_28399, v_28398);
    v_28398 = v_28398 ? lisp_true : nil;
    env = stack[-3];
    if (v_28398 == nil) goto v_28333;
    v_28398 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[0] = v_28398;
    v_28398 = nil;
    v_28398 = ncons(v_28398);
    env = stack[-3];
    stack[-2] = v_28398;
    goto v_28315;
v_28333:
    v_28398 = stack[-2];
    v_28398 = qcdr(v_28398);
    stack[-2] = v_28398;
    v_28398 = stack[-1];
    v_28398 = qcdr(v_28398);
    stack[-1] = v_28398;
    goto v_28315;
v_28315:
    goto v_28302;
v_28301:
    goto v_28367;
v_28363:
    v_28399 = stack[0];
    goto v_28364;
v_28365:
    v_28398 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28366;
v_28367:
    goto v_28363;
v_28364:
    goto v_28365;
v_28366:
    if (v_28399 == v_28398) goto v_28361;
    else goto v_28362;
v_28361:
    v_28398 = stack[-2];
    v_28398 = qcar(v_28398);
    goto v_28360;
v_28362:
    v_28398 = nil;
    goto v_28360;
    v_28398 = nil;
v_28360:
    if (v_28398 == nil) goto v_28358;
    v_28398 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_28398;
    goto v_28356;
v_28358:
    goto v_28387;
v_28383:
    v_28399 = stack[0];
    goto v_28384;
v_28385:
    v_28398 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28386;
v_28387:
    goto v_28383;
v_28384:
    goto v_28385;
v_28386:
    if (v_28399 == v_28398) goto v_28381;
    else goto v_28382;
v_28381:
    v_28398 = stack[-1];
    v_28398 = qcar(v_28398);
    goto v_28380;
v_28382:
    v_28398 = nil;
    goto v_28380;
    v_28398 = nil;
v_28380:
    if (v_28398 == nil) goto v_28378;
    v_28398 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[0] = v_28398;
    goto v_28356;
v_28378:
v_28356:
    v_28398 = stack[0];
    return onevalue(v_28398);
}



// Code for my_freeof

static LispObject CC_my_freeof(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28285, v_28286, v_28287;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28257;
    stack[-1] = v_28256;
// end of prologue
    goto v_28268;
v_28264:
    v_28286 = stack[0];
    goto v_28265;
v_28266:
    v_28285 = stack[-1];
    goto v_28267;
v_28268:
    goto v_28264;
v_28265:
    goto v_28266;
v_28267:
    fn = elt(env, 2); // smember
    v_28285 = (*qfn2(fn))(fn, v_28286, v_28285);
    env = stack[-2];
    if (v_28285 == nil) goto v_28261;
    else goto v_28262;
v_28261:
    goto v_28278;
v_28272:
    v_28287 = qvalue(elt(env, 1)); // depl!*
    goto v_28273;
v_28274:
    v_28286 = stack[-1];
    goto v_28275;
v_28276:
    v_28285 = stack[0];
    goto v_28277;
v_28278:
    goto v_28272;
v_28273:
    goto v_28274;
v_28275:
    goto v_28276;
v_28277:
    {
        fn = elt(env, 3); // freeofdepl
        return (*qfnn(fn))(fn, 3, v_28287, v_28286, v_28285);
    }
v_28262:
    v_28285 = nil;
    goto v_28260;
    v_28285 = nil;
v_28260:
    return onevalue(v_28285);
}



// Code for rl_sacat

static LispObject CC_rl_sacat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28278, v_28279, v_28280;
    LispObject fn;
    LispObject v_28258, v_28257, v_28256;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "rl_sacat");
    va_start(aa, nargs);
    v_28256 = va_arg(aa, LispObject);
    v_28257 = va_arg(aa, LispObject);
    v_28258 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_28258,v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_28256,v_28257,v_28258);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_28278 = v_28258;
    v_28279 = v_28257;
    v_28280 = v_28256;
// end of prologue
    goto v_28265;
v_28261:
    stack[0] = qvalue(elt(env, 1)); // rl_sacat!*
    goto v_28262;
v_28263:
    goto v_28274;
v_28268:
    goto v_28269;
v_28270:
    goto v_28271;
v_28272:
    goto v_28273;
v_28274:
    goto v_28268;
v_28269:
    goto v_28270;
v_28271:
    goto v_28272;
v_28273:
    v_28278 = list3(v_28280, v_28279, v_28278);
    env = stack[-1];
    goto v_28264;
v_28265:
    goto v_28261;
v_28262:
    goto v_28263;
v_28264:
    {
        LispObject v_28282 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_28282, v_28278);
    }
}



// Code for acfsf_clnegrel

static LispObject CC_acfsf_clnegrel(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28269, v_28270;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28269 = v_28257;
    v_28270 = v_28256;
// end of prologue
    if (v_28269 == nil) goto v_28262;
    v_28269 = v_28270;
    goto v_28260;
v_28262:
    v_28269 = v_28270;
    {
        fn = elt(env, 1); // acfsf_lnegrel
        return (*qfn1(fn))(fn, v_28269);
    }
    v_28269 = nil;
v_28260:
    return onevalue(v_28269);
}



// Code for parfool

static LispObject CC_parfool(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28299, v_28300, v_28301;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28256);
    }
// copy arguments values to proper place
    v_28301 = v_28256;
// end of prologue
    v_28299 = v_28301;
    v_28299 = qcar(v_28299);
    if (v_28299 == nil) goto v_28260;
    else goto v_28261;
v_28260:
    v_28299 = lisp_true;
    goto v_28259;
v_28261:
    v_28299 = v_28301;
    v_28299 = qcar(v_28299);
    if (is_number(v_28299)) goto v_28267;
    else goto v_28266;
v_28267:
    goto v_28279;
v_28275:
    v_28299 = v_28301;
    v_28300 = qcdr(v_28299);
    goto v_28276;
v_28277:
    v_28299 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28278;
v_28279:
    goto v_28275;
v_28276:
    goto v_28277;
v_28278:
    if (v_28300 == v_28299) goto v_28273;
    else goto v_28274;
v_28273:
    goto v_28288;
v_28284:
    v_28299 = v_28301;
    v_28300 = qcar(v_28299);
    goto v_28285;
v_28286:
    v_28299 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28287;
v_28288:
    goto v_28284;
v_28285:
    goto v_28286;
v_28287:
    v_28299 = (LispObject)lessp2(v_28300, v_28299);
    v_28299 = v_28299 ? lisp_true : nil;
    goto v_28272;
v_28274:
    v_28299 = nil;
    goto v_28272;
    v_28299 = nil;
v_28272:
    if (v_28299 == nil) goto v_28266;
    v_28299 = lisp_true;
    goto v_28259;
v_28266:
    v_28299 = nil;
    goto v_28259;
    v_28299 = nil;
v_28259:
    return onevalue(v_28299);
}



// Code for groebcplistmerge

static LispObject CC_groebcplistmerge(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28327, v_28328;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_28257;
    stack[-2] = v_28256;
// end of prologue
    v_28327 = stack[-2];
    if (v_28327 == nil) goto v_28266;
    else goto v_28267;
v_28266:
    v_28327 = stack[-1];
    goto v_28263;
v_28267:
    v_28327 = stack[-1];
    if (v_28327 == nil) goto v_28272;
    else goto v_28273;
v_28272:
    v_28327 = stack[-2];
    goto v_28263;
v_28273:
    v_28327 = stack[-2];
    v_28327 = qcar(v_28327);
    stack[-3] = v_28327;
    v_28327 = stack[-1];
    v_28327 = qcar(v_28327);
    stack[0] = v_28327;
    goto v_28285;
v_28281:
    v_28328 = stack[-3];
    goto v_28282;
v_28283:
    v_28327 = stack[0];
    goto v_28284;
v_28285:
    goto v_28281;
v_28282:
    goto v_28283;
v_28284:
    fn = elt(env, 1); // groebcpcompless!?
    v_28327 = (*qfn2(fn))(fn, v_28328, v_28327);
    env = stack[-4];
    if (v_28327 == nil) goto v_28291;
    goto v_28298;
v_28294:
    stack[0] = stack[-3];
    goto v_28295;
v_28296:
    goto v_28305;
v_28301:
    v_28327 = stack[-2];
    v_28328 = qcdr(v_28327);
    goto v_28302;
v_28303:
    v_28327 = stack[-1];
    goto v_28304;
v_28305:
    goto v_28301;
v_28302:
    goto v_28303;
v_28304:
    v_28327 = CC_groebcplistmerge(elt(env, 0), v_28328, v_28327);
    goto v_28297;
v_28298:
    goto v_28294;
v_28295:
    goto v_28296;
v_28297:
    {
        LispObject v_28333 = stack[0];
        return cons(v_28333, v_28327);
    }
v_28291:
    goto v_28316;
v_28312:
    goto v_28313;
v_28314:
    goto v_28323;
v_28319:
    v_28328 = stack[-2];
    goto v_28320;
v_28321:
    v_28327 = stack[-1];
    v_28327 = qcdr(v_28327);
    goto v_28322;
v_28323:
    goto v_28319;
v_28320:
    goto v_28321;
v_28322:
    v_28327 = CC_groebcplistmerge(elt(env, 0), v_28328, v_28327);
    goto v_28315;
v_28316:
    goto v_28312;
v_28313:
    goto v_28314;
v_28315:
    {
        LispObject v_28334 = stack[0];
        return cons(v_28334, v_28327);
    }
    v_28327 = nil;
v_28263:
    return onevalue(v_28327);
}



// Code for mkdmoderr

static LispObject CC_mkdmoderr(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28282;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_28257;
    v_28282 = v_28256;
// end of prologue
    goto v_28266;
v_28260:
    stack[-4] = elt(env, 1); // lambda
    goto v_28261;
v_28262:
    stack[-2] = elt(env, 2); // (!*x!*)
    goto v_28263;
v_28264:
    goto v_28276;
v_28270:
    stack[-1] = elt(env, 3); // dmoderr
    goto v_28271;
v_28272:
    stack[0] = Lmkquote(nil, v_28282);
    env = stack[-5];
    goto v_28273;
v_28274:
    v_28282 = stack[-3];
    v_28282 = Lmkquote(nil, v_28282);
    env = stack[-5];
    goto v_28275;
v_28276:
    goto v_28270;
v_28271:
    goto v_28272;
v_28273:
    goto v_28274;
v_28275:
    v_28282 = list3(stack[-1], stack[0], v_28282);
    goto v_28265;
v_28266:
    goto v_28260;
v_28261:
    goto v_28262;
v_28263:
    goto v_28264;
v_28265:
    {
        LispObject v_28288 = stack[-4];
        LispObject v_28289 = stack[-2];
        return list3(v_28288, v_28289, v_28282);
    }
}



// Code for indordln

static LispObject CC_indordln(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28298, v_28299;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28256);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_28299 = v_28256;
// end of prologue
    v_28298 = v_28299;
    if (v_28298 == nil) goto v_28260;
    else goto v_28261;
v_28260:
    v_28298 = nil;
    goto v_28259;
v_28261:
    v_28298 = v_28299;
    v_28298 = qcdr(v_28298);
    if (v_28298 == nil) goto v_28264;
    else goto v_28265;
v_28264:
    v_28298 = v_28299;
    goto v_28259;
v_28265:
    v_28298 = v_28299;
    v_28298 = qcdr(v_28298);
    v_28298 = qcdr(v_28298);
    if (v_28298 == nil) goto v_28269;
    else goto v_28270;
v_28269:
    goto v_28279;
v_28275:
    v_28298 = v_28299;
    v_28298 = qcar(v_28298);
    goto v_28276;
v_28277:
    v_28299 = qcdr(v_28299);
    v_28299 = qcar(v_28299);
    goto v_28278;
v_28279:
    goto v_28275;
v_28276:
    goto v_28277;
v_28278:
    {
        fn = elt(env, 1); // indordl2
        return (*qfn2(fn))(fn, v_28298, v_28299);
    }
v_28270:
    goto v_28292;
v_28288:
    v_28298 = v_28299;
    stack[0] = qcar(v_28298);
    goto v_28289;
v_28290:
    v_28298 = v_28299;
    v_28298 = qcdr(v_28298);
    v_28298 = CC_indordln(elt(env, 0), v_28298);
    env = stack[-1];
    goto v_28291;
v_28292:
    goto v_28288;
v_28289:
    goto v_28290;
v_28291:
    {
        LispObject v_28301 = stack[0];
        fn = elt(env, 2); // indordlad
        return (*qfn2(fn))(fn, v_28301, v_28298);
    }
    v_28298 = nil;
v_28259:
    return onevalue(v_28298);
}



// Code for listquotient

static LispObject CC_listquotient(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28476, v_28477, v_28478;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_28257;
    stack[0] = v_28256;
// end of prologue
    goto v_28268;
v_28264:
    v_28476 = stack[0];
    v_28477 = qcar(v_28476);
    goto v_28265;
v_28266:
    v_28476 = stack[-4];
    goto v_28267;
v_28268:
    goto v_28264;
v_28265:
    goto v_28266;
v_28267:
    fn = elt(env, 3); // reval1
    v_28476 = (*qfn2(fn))(fn, v_28477, v_28476);
    env = stack[-7];
    stack[-3] = v_28476;
    goto v_28277;
v_28273:
    v_28476 = stack[0];
    v_28476 = qcdr(v_28476);
    v_28477 = qcar(v_28476);
    goto v_28274;
v_28275:
    v_28476 = stack[-4];
    goto v_28276;
v_28277:
    goto v_28273;
v_28274:
    goto v_28275;
v_28276:
    fn = elt(env, 3); // reval1
    v_28476 = (*qfn2(fn))(fn, v_28477, v_28476);
    env = stack[-7];
    stack[-6] = v_28476;
    goto v_28287;
v_28283:
    stack[-5] = elt(env, 1); // list
    goto v_28284;
v_28285:
    goto v_28298;
v_28294:
    v_28477 = stack[-3];
    goto v_28295;
v_28296:
    v_28476 = elt(env, 1); // list
    goto v_28297;
v_28298:
    goto v_28294;
v_28295:
    goto v_28296;
v_28297:
    if (!consp(v_28477)) goto v_28291;
    v_28477 = qcar(v_28477);
    if (v_28477 == v_28476) goto v_28292;
v_28291:
    v_28476 = stack[-6];
    v_28476 = qcdr(v_28476);
    stack[-6] = v_28476;
    v_28476 = stack[-6];
    if (v_28476 == nil) goto v_28311;
    else goto v_28312;
v_28311:
    v_28476 = nil;
    goto v_28305;
v_28312:
    v_28476 = stack[-6];
    v_28476 = qcar(v_28476);
    goto v_28324;
v_28320:
    goto v_28332;
v_28326:
    v_28478 = elt(env, 2); // quotient
    goto v_28327;
v_28328:
    v_28477 = stack[-3];
    goto v_28329;
v_28330:
    goto v_28331;
v_28332:
    goto v_28326;
v_28327:
    goto v_28328;
v_28329:
    goto v_28330;
v_28331:
    v_28477 = list3(v_28478, v_28477, v_28476);
    env = stack[-7];
    goto v_28321;
v_28322:
    v_28476 = stack[-4];
    goto v_28323;
v_28324:
    goto v_28320;
v_28321:
    goto v_28322;
v_28323:
    fn = elt(env, 3); // reval1
    v_28476 = (*qfn2(fn))(fn, v_28477, v_28476);
    env = stack[-7];
    v_28476 = ncons(v_28476);
    env = stack[-7];
    stack[-1] = v_28476;
    stack[-2] = v_28476;
v_28306:
    v_28476 = stack[-6];
    v_28476 = qcdr(v_28476);
    stack[-6] = v_28476;
    v_28476 = stack[-6];
    if (v_28476 == nil) goto v_28341;
    else goto v_28342;
v_28341:
    v_28476 = stack[-2];
    goto v_28305;
v_28342:
    goto v_28350;
v_28346:
    stack[0] = stack[-1];
    goto v_28347;
v_28348:
    v_28476 = stack[-6];
    v_28476 = qcar(v_28476);
    goto v_28361;
v_28357:
    goto v_28369;
v_28363:
    v_28478 = elt(env, 2); // quotient
    goto v_28364;
v_28365:
    v_28477 = stack[-3];
    goto v_28366;
v_28367:
    goto v_28368;
v_28369:
    goto v_28363;
v_28364:
    goto v_28365;
v_28366:
    goto v_28367;
v_28368:
    v_28477 = list3(v_28478, v_28477, v_28476);
    env = stack[-7];
    goto v_28358;
v_28359:
    v_28476 = stack[-4];
    goto v_28360;
v_28361:
    goto v_28357;
v_28358:
    goto v_28359;
v_28360:
    fn = elt(env, 3); // reval1
    v_28476 = (*qfn2(fn))(fn, v_28477, v_28476);
    env = stack[-7];
    v_28476 = ncons(v_28476);
    env = stack[-7];
    goto v_28349;
v_28350:
    goto v_28346;
v_28347:
    goto v_28348;
v_28349:
    v_28476 = Lrplacd(nil, stack[0], v_28476);
    env = stack[-7];
    v_28476 = stack[-1];
    v_28476 = qcdr(v_28476);
    stack[-1] = v_28476;
    goto v_28306;
v_28305:
    goto v_28290;
v_28292:
    goto v_28383;
v_28379:
    v_28477 = stack[-6];
    goto v_28380;
v_28381:
    v_28476 = elt(env, 1); // list
    goto v_28382;
v_28383:
    goto v_28379;
v_28380:
    goto v_28381;
v_28382:
    if (!consp(v_28477)) goto v_28377;
    v_28477 = qcar(v_28477);
    if (v_28477 == v_28476) goto v_28376;
    else goto v_28377;
v_28376:
    goto v_28393;
v_28387:
    v_28476 = stack[-3];
    v_28478 = qcdr(v_28476);
    goto v_28388;
v_28389:
    v_28476 = stack[-6];
    v_28477 = qcdr(v_28476);
    goto v_28390;
v_28391:
    v_28476 = stack[-4];
    goto v_28392;
v_28393:
    goto v_28387;
v_28388:
    goto v_28389;
v_28390:
    goto v_28391;
v_28392:
    fn = elt(env, 4); // listquotient2
    v_28476 = (*qfnn(fn))(fn, 3, v_28478, v_28477, v_28476);
    goto v_28290;
v_28377:
    v_28476 = stack[-3];
    v_28476 = qcdr(v_28476);
    stack[-3] = v_28476;
    v_28476 = stack[-3];
    if (v_28476 == nil) goto v_28411;
    else goto v_28412;
v_28411:
    v_28476 = nil;
    goto v_28405;
v_28412:
    v_28476 = stack[-3];
    v_28476 = qcar(v_28476);
    goto v_28424;
v_28420:
    goto v_28432;
v_28426:
    v_28478 = elt(env, 2); // quotient
    goto v_28427;
v_28428:
    v_28477 = v_28476;
    goto v_28429;
v_28430:
    v_28476 = stack[-6];
    goto v_28431;
v_28432:
    goto v_28426;
v_28427:
    goto v_28428;
v_28429:
    goto v_28430;
v_28431:
    v_28477 = list3(v_28478, v_28477, v_28476);
    env = stack[-7];
    goto v_28421;
v_28422:
    v_28476 = stack[-4];
    goto v_28423;
v_28424:
    goto v_28420;
v_28421:
    goto v_28422;
v_28423:
    fn = elt(env, 3); // reval1
    v_28476 = (*qfn2(fn))(fn, v_28477, v_28476);
    env = stack[-7];
    v_28476 = ncons(v_28476);
    env = stack[-7];
    stack[-1] = v_28476;
    stack[-2] = v_28476;
v_28406:
    v_28476 = stack[-3];
    v_28476 = qcdr(v_28476);
    stack[-3] = v_28476;
    v_28476 = stack[-3];
    if (v_28476 == nil) goto v_28441;
    else goto v_28442;
v_28441:
    v_28476 = stack[-2];
    goto v_28405;
v_28442:
    goto v_28450;
v_28446:
    stack[0] = stack[-1];
    goto v_28447;
v_28448:
    v_28476 = stack[-3];
    v_28476 = qcar(v_28476);
    goto v_28461;
v_28457:
    goto v_28469;
v_28463:
    v_28478 = elt(env, 2); // quotient
    goto v_28464;
v_28465:
    v_28477 = v_28476;
    goto v_28466;
v_28467:
    v_28476 = stack[-6];
    goto v_28468;
v_28469:
    goto v_28463;
v_28464:
    goto v_28465;
v_28466:
    goto v_28467;
v_28468:
    v_28477 = list3(v_28478, v_28477, v_28476);
    env = stack[-7];
    goto v_28458;
v_28459:
    v_28476 = stack[-4];
    goto v_28460;
v_28461:
    goto v_28457;
v_28458:
    goto v_28459;
v_28460:
    fn = elt(env, 3); // reval1
    v_28476 = (*qfn2(fn))(fn, v_28477, v_28476);
    env = stack[-7];
    v_28476 = ncons(v_28476);
    env = stack[-7];
    goto v_28449;
v_28450:
    goto v_28446;
v_28447:
    goto v_28448;
v_28449:
    v_28476 = Lrplacd(nil, stack[0], v_28476);
    env = stack[-7];
    v_28476 = stack[-1];
    v_28476 = qcdr(v_28476);
    stack[-1] = v_28476;
    goto v_28406;
v_28405:
    goto v_28290;
    v_28476 = nil;
v_28290:
    goto v_28286;
v_28287:
    goto v_28283;
v_28284:
    goto v_28285;
v_28286:
    {
        LispObject v_28486 = stack[-5];
        return cons(v_28486, v_28476);
    }
    return onevalue(v_28476);
}



// Code for fs!:prin!:

static LispObject CC_fsTprinT(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28265;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28256);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_28256;
// end of prologue
    v_28265 = elt(env, 1); // "["
    fn = elt(env, 3); // prin2!*
    v_28265 = (*qfn1(fn))(fn, v_28265);
    env = stack[-1];
    v_28265 = stack[0];
    v_28265 = qcdr(v_28265);
    fn = elt(env, 4); // fs!:prin
    v_28265 = (*qfn1(fn))(fn, v_28265);
    env = stack[-1];
    v_28265 = elt(env, 2); // "]"
    {
        fn = elt(env, 3); // prin2!*
        return (*qfn1(fn))(fn, v_28265);
    }
}



// Code for groeb!=testb

static LispObject CC_groebMtestb(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28367, v_28368;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_28257;
    stack[-1] = v_28256;
// end of prologue
    goto v_28267;
v_28263:
    v_28367 = stack[-1];
    fn = elt(env, 1); // mo_comp
    v_28368 = (*qfn1(fn))(fn, v_28367);
    env = stack[-3];
    goto v_28264;
v_28265:
    v_28367 = stack[0];
    v_28367 = qcar(v_28367);
    goto v_28266;
v_28267:
    goto v_28263;
v_28264:
    goto v_28265;
v_28266:
    if (equal(v_28368, v_28367)) goto v_28261;
    else goto v_28262;
v_28261:
    goto v_28281;
v_28277:
    stack[-2] = stack[-1];
    goto v_28278;
v_28279:
    goto v_28288;
v_28284:
    v_28368 = stack[0];
    goto v_28285;
v_28286:
    v_28367 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_28287;
v_28288:
    goto v_28284;
v_28285:
    goto v_28286;
v_28287:
    fn = elt(env, 2); // nth
    v_28367 = (*qfn2(fn))(fn, v_28368, v_28367);
    env = stack[-3];
    goto v_28280;
v_28281:
    goto v_28277;
v_28278:
    goto v_28279;
v_28280:
    fn = elt(env, 3); // mo_divides!?
    v_28367 = (*qfn2(fn))(fn, stack[-2], v_28367);
    env = stack[-3];
    if (v_28367 == nil) goto v_28274;
    else goto v_28275;
v_28274:
    v_28367 = nil;
    goto v_28273;
v_28275:
    goto v_28303;
v_28299:
    goto v_28309;
v_28305:
    goto v_28317;
v_28313:
    v_28368 = stack[0];
    goto v_28314;
v_28315:
    v_28367 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_28316;
v_28317:
    goto v_28313;
v_28314:
    goto v_28315;
v_28316:
    fn = elt(env, 2); // nth
    v_28367 = (*qfn2(fn))(fn, v_28368, v_28367);
    env = stack[-3];
    fn = elt(env, 4); // bas_dpoly
    v_28367 = (*qfn1(fn))(fn, v_28367);
    env = stack[-3];
    fn = elt(env, 5); // dp_lmon
    v_28368 = (*qfn1(fn))(fn, v_28367);
    env = stack[-3];
    goto v_28306;
v_28307:
    v_28367 = stack[-1];
    goto v_28308;
v_28309:
    goto v_28305;
v_28306:
    goto v_28307;
v_28308:
    fn = elt(env, 6); // mo_lcm
    stack[-2] = (*qfn2(fn))(fn, v_28368, v_28367);
    env = stack[-3];
    goto v_28300;
v_28301:
    goto v_28326;
v_28322:
    v_28368 = stack[0];
    goto v_28323;
v_28324:
    v_28367 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_28325;
v_28326:
    goto v_28322;
v_28323:
    goto v_28324;
v_28325:
    fn = elt(env, 2); // nth
    v_28367 = (*qfn2(fn))(fn, v_28368, v_28367);
    env = stack[-3];
    goto v_28302;
v_28303:
    goto v_28299;
v_28300:
    goto v_28301;
v_28302:
    fn = elt(env, 7); // mo_equal!?
    v_28367 = (*qfn2(fn))(fn, stack[-2], v_28367);
    env = stack[-3];
    if (v_28367 == nil) goto v_28296;
    else goto v_28297;
v_28296:
    goto v_28334;
v_28330:
    goto v_28340;
v_28336:
    goto v_28348;
v_28344:
    v_28368 = stack[0];
    goto v_28345;
v_28346:
    v_28367 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_28347;
v_28348:
    goto v_28344;
v_28345:
    goto v_28346;
v_28347:
    fn = elt(env, 2); // nth
    v_28367 = (*qfn2(fn))(fn, v_28368, v_28367);
    env = stack[-3];
    fn = elt(env, 4); // bas_dpoly
    v_28367 = (*qfn1(fn))(fn, v_28367);
    env = stack[-3];
    fn = elt(env, 5); // dp_lmon
    v_28368 = (*qfn1(fn))(fn, v_28367);
    env = stack[-3];
    goto v_28337;
v_28338:
    v_28367 = stack[-1];
    goto v_28339;
v_28340:
    goto v_28336;
v_28337:
    goto v_28338;
v_28339:
    fn = elt(env, 6); // mo_lcm
    stack[-1] = (*qfn2(fn))(fn, v_28368, v_28367);
    env = stack[-3];
    goto v_28331;
v_28332:
    goto v_28357;
v_28353:
    v_28368 = stack[0];
    goto v_28354;
v_28355:
    v_28367 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_28356;
v_28357:
    goto v_28353;
v_28354:
    goto v_28355;
v_28356:
    fn = elt(env, 2); // nth
    v_28367 = (*qfn2(fn))(fn, v_28368, v_28367);
    env = stack[-3];
    goto v_28333;
v_28334:
    goto v_28330;
v_28331:
    goto v_28332;
v_28333:
    fn = elt(env, 7); // mo_equal!?
    v_28367 = (*qfn2(fn))(fn, stack[-1], v_28367);
    v_28367 = (v_28367 == nil ? lisp_true : nil);
    goto v_28295;
v_28297:
    v_28367 = nil;
    goto v_28295;
    v_28367 = nil;
v_28295:
    goto v_28273;
    v_28367 = nil;
v_28273:
    goto v_28260;
v_28262:
    v_28367 = nil;
    goto v_28260;
    v_28367 = nil;
v_28260:
    return onevalue(v_28367);
}



// Code for verify_tens_ids

static LispObject CC_verify_tens_ids(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28310, v_28311;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28256);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_28256;
// end of prologue
    v_28310 = stack[-1];
    v_28310 = qcar(v_28310);
    v_28311 = v_28310;
    v_28310 = stack[-1];
    v_28310 = qcdr(v_28310);
    v_28310 = qcar(v_28310);
    stack[0] = v_28310;
    v_28310 = v_28311;
    fn = elt(env, 3); // extract_dummy_ids
    v_28310 = (*qfn1(fn))(fn, v_28310);
    env = stack[-3];
    fn = elt(env, 4); // repeats
    v_28310 = (*qfn1(fn))(fn, v_28310);
    env = stack[-3];
    if (v_28310 == nil) goto v_28271;
    else goto v_28269;
v_28271:
    v_28310 = stack[0];
    fn = elt(env, 3); // extract_dummy_ids
    v_28310 = (*qfn1(fn))(fn, v_28310);
    env = stack[-3];
    fn = elt(env, 4); // repeats
    v_28310 = (*qfn1(fn))(fn, v_28310);
    env = stack[-3];
    if (v_28310 == nil) goto v_28275;
    else goto v_28269;
v_28275:
    goto v_28270;
v_28269:
    goto v_28286;
v_28280:
    stack[-2] = elt(env, 1); // cantens
    goto v_28281;
v_28282:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_28283;
v_28284:
    goto v_28294;
v_28290:
    goto v_28300;
v_28296:
    v_28310 = stack[-1];
    v_28311 = qcar(v_28310);
    goto v_28297;
v_28298:
    v_28310 = stack[-1];
    v_28310 = qcdr(v_28310);
    v_28310 = qcar(v_28310);
    goto v_28299;
v_28300:
    goto v_28296;
v_28297:
    goto v_28298;
v_28299:
    v_28311 = list2(v_28311, v_28310);
    env = stack[-3];
    goto v_28291;
v_28292:
    v_28310 = elt(env, 2); // "are inconsistent lists of indices"
    goto v_28293;
v_28294:
    goto v_28290;
v_28291:
    goto v_28292;
v_28293:
    v_28310 = list2(v_28311, v_28310);
    env = stack[-3];
    goto v_28285;
v_28286:
    goto v_28280;
v_28281:
    goto v_28282;
v_28283:
    goto v_28284;
v_28285:
    fn = elt(env, 5); // rerror
    v_28310 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_28310);
    goto v_28268;
v_28270:
    v_28310 = lisp_true;
    goto v_28261;
v_28268:
    v_28310 = nil;
v_28261:
    return onevalue(v_28310);
}



// Code for no_of_tm_sf_limited

static LispObject CC_no_of_tm_sf_limited(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28327, v_28328;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_28257;
    stack[-1] = v_28256;
// end of prologue
    v_28327 = stack[-1];
    if (v_28327 == nil) goto v_28261;
    else goto v_28262;
v_28261:
    v_28327 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28260;
v_28262:
    v_28327 = stack[-1];
    v_28327 = Lconsp(nil, v_28327);
    env = stack[-3];
    if (v_28327 == nil) goto v_28269;
    else goto v_28270;
v_28269:
    v_28327 = lisp_true;
    goto v_28268;
v_28270:
    v_28327 = stack[-1];
    v_28327 = qcar(v_28327);
    v_28327 = Lconsp(nil, v_28327);
    env = stack[-3];
    v_28327 = (v_28327 == nil ? lisp_true : nil);
    goto v_28268;
    v_28327 = nil;
v_28268:
    if (v_28327 == nil) goto v_28266;
    v_28327 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28260;
v_28266:
    goto v_28291;
v_28287:
    v_28327 = stack[-1];
    v_28327 = qcar(v_28327);
    v_28328 = qcdr(v_28327);
    goto v_28288;
v_28289:
    v_28327 = stack[0];
    goto v_28290;
v_28291:
    goto v_28287;
v_28288:
    goto v_28289;
v_28290:
    v_28327 = CC_no_of_tm_sf_limited(elt(env, 0), v_28328, v_28327);
    env = stack[-3];
    stack[-2] = v_28327;
    goto v_28305;
v_28301:
    v_28328 = stack[-2];
    goto v_28302;
v_28303:
    v_28327 = stack[0];
    goto v_28304;
v_28305:
    goto v_28301;
v_28302:
    goto v_28303;
v_28304:
    v_28327 = (LispObject)greaterp2(v_28328, v_28327);
    v_28327 = v_28327 ? lisp_true : nil;
    env = stack[-3];
    if (v_28327 == nil) goto v_28299;
    v_28327 = stack[-2];
    goto v_28297;
v_28299:
    goto v_28316;
v_28312:
    goto v_28313;
v_28314:
    goto v_28323;
v_28319:
    v_28327 = stack[-1];
    v_28328 = qcdr(v_28327);
    goto v_28320;
v_28321:
    v_28327 = stack[0];
    goto v_28322;
v_28323:
    goto v_28319;
v_28320:
    goto v_28321;
v_28322:
    v_28327 = CC_no_of_tm_sf_limited(elt(env, 0), v_28328, v_28327);
    goto v_28315;
v_28316:
    goto v_28312;
v_28313:
    goto v_28314;
v_28315:
    {
        LispObject v_28332 = stack[-2];
        return plus2(v_28332, v_28327);
    }
    v_28327 = nil;
v_28297:
    goto v_28260;
    v_28327 = nil;
v_28260:
    return onevalue(v_28327);
}



// Code for count!-linear!-factors!-mod!-p

static LispObject CC_countKlinearKfactorsKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28580, v_28581, v_28582, v_28583, v_28584;
    LispObject fn;
    LispObject v_28258, v_28257, v_28256;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "count-linear-factors-mod-p");
    va_start(aa, nargs);
    v_28256 = va_arg(aa, LispObject);
    v_28257 = va_arg(aa, LispObject);
    v_28258 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_28258,v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_28256,v_28257,v_28258);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_28258;
    stack[-2] = v_28257;
    stack[-3] = v_28256;
// end of prologue
// Binding linear!-factors
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-5, 1, 0);
    qvalue(elt(env, 1)) = nil; // linear!-factors
    v_28580 = (LispObject)0+TAG_FIXNUM; // 0
    v_28584 = v_28580;
v_28268:
    goto v_28278;
v_28274:
    v_28581 = qvalue(elt(env, 2)); // dpoly
    goto v_28275;
v_28276:
    v_28580 = v_28584;
    goto v_28277;
v_28278:
    goto v_28274;
v_28275:
    goto v_28276;
v_28277:
    v_28580 = (LispObject)(intptr_t)((intptr_t)v_28581 - (intptr_t)v_28580 + TAG_FIXNUM);
    v_28580 = ((intptr_t)(v_28580) < 0 ? lisp_true : nil);
    if (v_28580 == nil) goto v_28273;
    goto v_28267;
v_28273:
    goto v_28290;
v_28284:
    v_28583 = stack[-2];
    goto v_28285;
v_28286:
    v_28582 = v_28584;
    goto v_28287;
v_28288:
    goto v_28297;
v_28293:
    v_28581 = qvalue(elt(env, 3)); // poly!-vector
    goto v_28294;
v_28295:
    v_28580 = v_28584;
    goto v_28296;
v_28297:
    goto v_28293;
v_28294:
    goto v_28295;
v_28296:
    v_28580 = *(LispObject *)((char *)v_28581 + (CELL-TAG_VECTOR) + (((intptr_t)v_28580-TAG_FIXNUM)/(16/CELL)));
    goto v_28289;
v_28290:
    goto v_28284;
v_28285:
    goto v_28286;
v_28287:
    goto v_28288;
v_28289:
    *(LispObject *)((char *)v_28583 + (CELL-TAG_VECTOR) + (((intptr_t)v_28582-TAG_FIXNUM)/(16/CELL))) = v_28580;
    v_28580 = v_28584;
    v_28580 = (LispObject)((intptr_t)(v_28580) + 0x10);
    v_28584 = v_28580;
    goto v_28268;
v_28267:
    goto v_28310;
v_28304:
    v_28582 = qvalue(elt(env, 4)); // current!-modulus
    goto v_28305;
v_28306:
    v_28581 = stack[-3];
    goto v_28307;
v_28308:
    v_28580 = stack[-1];
    goto v_28309;
v_28310:
    goto v_28304;
v_28305:
    goto v_28306;
v_28307:
    goto v_28308;
v_28309:
    fn = elt(env, 5); // make!-x!-to!-p
    v_28580 = (*qfnn(fn))(fn, 3, v_28582, v_28581, v_28580);
    env = stack[-5];
    stack[-4] = v_28580;
    v_28580 = (LispObject)0+TAG_FIXNUM; // 0
    v_28584 = v_28580;
v_28317:
    goto v_28327;
v_28323:
    v_28581 = stack[-4];
    goto v_28324;
v_28325:
    v_28580 = v_28584;
    goto v_28326;
v_28327:
    goto v_28323;
v_28324:
    goto v_28325;
v_28326:
    v_28580 = (LispObject)(intptr_t)((intptr_t)v_28581 - (intptr_t)v_28580 + TAG_FIXNUM);
    v_28580 = ((intptr_t)(v_28580) < 0 ? lisp_true : nil);
    if (v_28580 == nil) goto v_28322;
    goto v_28316;
v_28322:
    goto v_28339;
v_28333:
    v_28583 = stack[-3];
    goto v_28334;
v_28335:
    v_28582 = v_28584;
    goto v_28336;
v_28337:
    goto v_28346;
v_28342:
    v_28581 = stack[-1];
    goto v_28343;
v_28344:
    v_28580 = v_28584;
    goto v_28345;
v_28346:
    goto v_28342;
v_28343:
    goto v_28344;
v_28345:
    v_28580 = *(LispObject *)((char *)v_28581 + (CELL-TAG_VECTOR) + (((intptr_t)v_28580-TAG_FIXNUM)/(16/CELL)));
    goto v_28338;
v_28339:
    goto v_28333;
v_28334:
    goto v_28335;
v_28336:
    goto v_28337;
v_28338:
    *(LispObject *)((char *)v_28583 + (CELL-TAG_VECTOR) + (((intptr_t)v_28582-TAG_FIXNUM)/(16/CELL))) = v_28580;
    v_28580 = v_28584;
    v_28580 = (LispObject)((intptr_t)(v_28580) + 0x10);
    v_28584 = v_28580;
    goto v_28317;
v_28316:
    goto v_28360;
v_28356:
    v_28581 = stack[-4];
    goto v_28357;
v_28358:
    v_28580 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28359;
v_28360:
    goto v_28356;
v_28357:
    goto v_28358;
v_28359:
    if (((intptr_t)(v_28581)) < ((intptr_t)(v_28580))) goto v_28354;
    else goto v_28355;
v_28354:
    goto v_28371;
v_28367:
    v_28581 = stack[-4];
    goto v_28368;
v_28369:
    v_28580 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28370;
v_28371:
    goto v_28367;
v_28368:
    goto v_28369;
v_28370:
    if (((intptr_t)(v_28581)) < ((intptr_t)(v_28580))) goto v_28365;
    else goto v_28366;
v_28365:
    goto v_28380;
v_28374:
    v_28582 = stack[-3];
    goto v_28375;
v_28376:
    v_28581 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28377;
v_28378:
    v_28580 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28379;
v_28380:
    goto v_28374;
v_28375:
    goto v_28376;
v_28377:
    goto v_28378;
v_28379:
    *(LispObject *)((char *)v_28582 + (CELL-TAG_VECTOR) + (((intptr_t)v_28581-TAG_FIXNUM)/(16/CELL))) = v_28580;
    goto v_28364;
v_28366:
v_28364:
    goto v_28390;
v_28384:
    v_28582 = stack[-3];
    goto v_28385;
v_28386:
    v_28581 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28387;
v_28388:
    v_28580 = (LispObject)16+TAG_FIXNUM; // 1
    {   intptr_t w = int_of_fixnum(v_28580);
        if (w != 0) w = current_modulus - w;
        v_28580 = fixnum_of_int(w);
    }
    goto v_28389;
v_28390:
    goto v_28384;
v_28385:
    goto v_28386;
v_28387:
    goto v_28388;
v_28389:
    *(LispObject *)((char *)v_28582 + (CELL-TAG_VECTOR) + (((intptr_t)v_28581-TAG_FIXNUM)/(16/CELL))) = v_28580;
    v_28580 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_28580;
    goto v_28353;
v_28355:
    goto v_28404;
v_28398:
    v_28583 = stack[-3];
    goto v_28399;
v_28400:
    v_28582 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28401;
v_28402:
    goto v_28411;
v_28407:
    goto v_28416;
v_28412:
    v_28581 = stack[-3];
    goto v_28413;
v_28414:
    v_28580 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28415;
v_28416:
    goto v_28412;
v_28413:
    goto v_28414;
v_28415:
    v_28581 = *(LispObject *)((char *)v_28581 + (CELL-TAG_VECTOR) + (((intptr_t)v_28580-TAG_FIXNUM)/(16/CELL)));
    goto v_28408;
v_28409:
    v_28580 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28410;
v_28411:
    goto v_28407;
v_28408:
    goto v_28409;
v_28410:
    {   intptr_t w = int_of_fixnum(v_28581) - int_of_fixnum(v_28580);
        if (w < 0) w += current_modulus;
        v_28580 = fixnum_of_int(w);
    }
    goto v_28403;
v_28404:
    goto v_28398;
v_28399:
    goto v_28400;
v_28401:
    goto v_28402;
v_28403:
    *(LispObject *)((char *)v_28583 + (CELL-TAG_VECTOR) + (((intptr_t)v_28582-TAG_FIXNUM)/(16/CELL))) = v_28580;
    goto v_28434;
v_28430:
    v_28581 = stack[-4];
    goto v_28431;
v_28432:
    v_28580 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28433;
v_28434:
    goto v_28430;
v_28431:
    goto v_28432;
v_28433:
    if (v_28581 == v_28580) goto v_28428;
    else goto v_28429;
v_28428:
    goto v_28441;
v_28437:
    goto v_28446;
v_28442:
    v_28581 = stack[-3];
    goto v_28443;
v_28444:
    v_28580 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28445;
v_28446:
    goto v_28442;
v_28443:
    goto v_28444;
v_28445:
    v_28581 = *(LispObject *)((char *)v_28581 + (CELL-TAG_VECTOR) + (((intptr_t)v_28580-TAG_FIXNUM)/(16/CELL)));
    goto v_28438;
v_28439:
    v_28580 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28440;
v_28441:
    goto v_28437;
v_28438:
    goto v_28439;
v_28440:
    v_28580 = (v_28581 == v_28580 ? lisp_true : nil);
    goto v_28427;
v_28429:
    v_28580 = nil;
    goto v_28427;
    v_28580 = nil;
v_28427:
    if (v_28580 == nil) goto v_28425;
    goto v_28463;
v_28459:
    goto v_28468;
v_28464:
    v_28581 = stack[-3];
    goto v_28465;
v_28466:
    v_28580 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28467;
v_28468:
    goto v_28464;
v_28465:
    goto v_28466;
v_28467:
    v_28581 = *(LispObject *)((char *)v_28581 + (CELL-TAG_VECTOR) + (((intptr_t)v_28580-TAG_FIXNUM)/(16/CELL)));
    goto v_28460;
v_28461:
    v_28580 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28462;
v_28463:
    goto v_28459;
v_28460:
    goto v_28461;
v_28462:
    if (v_28581 == v_28580) goto v_28457;
    else goto v_28458;
v_28457:
    v_28580 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[-4] = v_28580;
    goto v_28456;
v_28458:
    v_28580 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_28580;
    goto v_28456;
v_28456:
    goto v_28423;
v_28425:
v_28423:
    goto v_28353;
v_28353:
    goto v_28485;
v_28481:
    v_28581 = stack[-4];
    goto v_28482;
v_28483:
    v_28580 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28484;
v_28485:
    goto v_28481;
v_28482:
    goto v_28483;
v_28484:
    if (((intptr_t)(v_28581)) < ((intptr_t)(v_28580))) goto v_28479;
    else goto v_28480;
v_28479:
    goto v_28495;
v_28489:
    v_28582 = stack[-2];
    goto v_28490;
v_28491:
    v_28581 = qvalue(elt(env, 2)); // dpoly
    goto v_28492;
v_28493:
    v_28580 = stack[-3];
    goto v_28494;
v_28495:
    goto v_28489;
v_28490:
    goto v_28491;
v_28492:
    goto v_28493;
v_28494:
    fn = elt(env, 6); // copy!-vector
    v_28580 = (*qfnn(fn))(fn, 3, v_28582, v_28581, v_28580);
    env = stack[-5];
    stack[-1] = v_28580;
    goto v_28478;
v_28480:
    goto v_28510;
v_28502:
    v_28583 = stack[-3];
    goto v_28503;
v_28504:
    v_28582 = stack[-4];
    goto v_28505;
v_28506:
    v_28581 = stack[-2];
    goto v_28507;
v_28508:
    v_28580 = qvalue(elt(env, 2)); // dpoly
    goto v_28509;
v_28510:
    goto v_28502;
v_28503:
    goto v_28504;
v_28505:
    goto v_28506;
v_28507:
    goto v_28508;
v_28509:
    fn = elt(env, 7); // gcd!-in!-vector
    v_28580 = (*qfnn(fn))(fn, 4, v_28583, v_28582, v_28581, v_28580);
    env = stack[-5];
    stack[-1] = v_28580;
    goto v_28478;
v_28478:
    v_28580 = stack[-1];
    v_28580 = Lmkvect(nil, v_28580);
    env = stack[-5];
    qvalue(elt(env, 1)) = v_28580; // linear!-factors
    v_28580 = (LispObject)0+TAG_FIXNUM; // 0
    v_28584 = v_28580;
v_28520:
    goto v_28530;
v_28526:
    v_28581 = stack[-1];
    goto v_28527;
v_28528:
    v_28580 = v_28584;
    goto v_28529;
v_28530:
    goto v_28526;
v_28527:
    goto v_28528;
v_28529:
    v_28580 = (LispObject)(intptr_t)((intptr_t)v_28581 - (intptr_t)v_28580 + TAG_FIXNUM);
    v_28580 = ((intptr_t)(v_28580) < 0 ? lisp_true : nil);
    if (v_28580 == nil) goto v_28525;
    goto v_28519;
v_28525:
    goto v_28542;
v_28536:
    v_28583 = qvalue(elt(env, 1)); // linear!-factors
    goto v_28537;
v_28538:
    v_28582 = v_28584;
    goto v_28539;
v_28540:
    goto v_28549;
v_28545:
    v_28581 = stack[-3];
    goto v_28546;
v_28547:
    v_28580 = v_28584;
    goto v_28548;
v_28549:
    goto v_28545;
v_28546:
    goto v_28547;
v_28548:
    v_28580 = *(LispObject *)((char *)v_28581 + (CELL-TAG_VECTOR) + (((intptr_t)v_28580-TAG_FIXNUM)/(16/CELL)));
    goto v_28541;
v_28542:
    goto v_28536;
v_28537:
    goto v_28538;
v_28539:
    goto v_28540;
v_28541:
    *(LispObject *)((char *)v_28583 + (CELL-TAG_VECTOR) + (((intptr_t)v_28582-TAG_FIXNUM)/(16/CELL))) = v_28580;
    v_28580 = v_28584;
    v_28580 = (LispObject)((intptr_t)(v_28580) + 0x10);
    v_28584 = v_28580;
    goto v_28520;
v_28519:
    goto v_28564;
v_28556:
    v_28583 = qvalue(elt(env, 3)); // poly!-vector
    goto v_28557;
v_28558:
    v_28582 = qvalue(elt(env, 2)); // dpoly
    goto v_28559;
v_28560:
    v_28581 = qvalue(elt(env, 1)); // linear!-factors
    goto v_28561;
v_28562:
    v_28580 = stack[-1];
    goto v_28563;
v_28564:
    goto v_28556;
v_28557:
    goto v_28558;
v_28559:
    goto v_28560;
v_28561:
    goto v_28562;
v_28563:
    fn = elt(env, 8); // quotfail!-in!-vector
    v_28580 = (*qfnn(fn))(fn, 4, v_28583, v_28582, v_28581, v_28580);
    env = stack[-5];
    qvalue(elt(env, 2)) = v_28580; // dpoly
    goto v_28576;
v_28570:
    v_28582 = stack[-1];
    goto v_28571;
v_28572:
    v_28581 = qvalue(elt(env, 1)); // linear!-factors
    goto v_28573;
v_28574:
    v_28580 = stack[-4];
    goto v_28575;
v_28576:
    goto v_28570;
v_28571:
    goto v_28572;
v_28573:
    goto v_28574;
v_28575:
    v_28580 = list3(v_28582, v_28581, v_28580);
    ;}  // end of a binding scope
    return onevalue(v_28580);
}



// Code for aex_xtothen

static LispObject CC_aex_xtothen(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28281, v_28282;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_28281 = v_28257;
    v_28282 = v_28256;
// end of prologue
    goto v_28264;
v_28260:
    goto v_28270;
v_28266:
    goto v_28276;
v_28272:
    goto v_28273;
v_28274:
    goto v_28275;
v_28276:
    goto v_28272;
v_28273:
    goto v_28274;
v_28275:
    fn = elt(env, 1); // sfto_kexp
    v_28282 = (*qfn2(fn))(fn, v_28282, v_28281);
    env = stack[-1];
    goto v_28267;
v_28268:
    v_28281 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28269;
v_28270:
    goto v_28266;
v_28267:
    goto v_28268;
v_28269:
    stack[0] = cons(v_28282, v_28281);
    env = stack[-1];
    goto v_28261;
v_28262:
    fn = elt(env, 2); // ctx_new
    v_28281 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_28263;
v_28264:
    goto v_28260;
v_28261:
    goto v_28262;
v_28263:
    {
        LispObject v_28284 = stack[0];
        fn = elt(env, 3); // aex_mk
        return (*qfn2(fn))(fn, v_28284, v_28281);
    }
}



// Code for ofsf_facequal

static LispObject CC_ofsf_facequal(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28362, v_28363, v_28364;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28256);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_28362 = v_28256;
// end of prologue
    fn = elt(env, 6); // sfto_fctrf
    v_28362 = (*qfn1(fn))(fn, v_28362);
    env = stack[-4];
    v_28362 = qcdr(v_28362);
    stack[-3] = v_28362;
    v_28362 = stack[-3];
    if (v_28362 == nil) goto v_28269;
    else goto v_28270;
v_28269:
    v_28362 = nil;
    goto v_28262;
v_28270:
    v_28362 = stack[-3];
    v_28362 = qcar(v_28362);
    goto v_28284;
v_28278:
    v_28364 = elt(env, 1); // equal
    goto v_28279;
v_28280:
    v_28363 = qcar(v_28362);
    goto v_28281;
v_28282:
    v_28362 = nil;
    goto v_28283;
v_28284:
    goto v_28278;
v_28279:
    goto v_28280;
v_28281:
    goto v_28282;
v_28283:
    v_28362 = list3(v_28364, v_28363, v_28362);
    env = stack[-4];
    v_28362 = ncons(v_28362);
    env = stack[-4];
    stack[-1] = v_28362;
    stack[-2] = v_28362;
v_28263:
    v_28362 = stack[-3];
    v_28362 = qcdr(v_28362);
    stack[-3] = v_28362;
    v_28362 = stack[-3];
    if (v_28362 == nil) goto v_28293;
    else goto v_28294;
v_28293:
    v_28362 = stack[-2];
    goto v_28262;
v_28294:
    goto v_28302;
v_28298:
    stack[0] = stack[-1];
    goto v_28299;
v_28300:
    v_28362 = stack[-3];
    v_28362 = qcar(v_28362);
    goto v_28315;
v_28309:
    v_28364 = elt(env, 1); // equal
    goto v_28310;
v_28311:
    v_28363 = qcar(v_28362);
    goto v_28312;
v_28313:
    v_28362 = nil;
    goto v_28314;
v_28315:
    goto v_28309;
v_28310:
    goto v_28311;
v_28312:
    goto v_28313;
v_28314:
    v_28362 = list3(v_28364, v_28363, v_28362);
    env = stack[-4];
    v_28362 = ncons(v_28362);
    env = stack[-4];
    goto v_28301;
v_28302:
    goto v_28298;
v_28299:
    goto v_28300;
v_28301:
    v_28362 = Lrplacd(nil, stack[0], v_28362);
    env = stack[-4];
    v_28362 = stack[-1];
    v_28362 = qcdr(v_28362);
    stack[-1] = v_28362;
    goto v_28263;
v_28262:
    v_28363 = v_28362;
    v_28362 = v_28363;
    if (v_28362 == nil) goto v_28326;
    v_28362 = v_28363;
    v_28362 = qcdr(v_28362);
    if (v_28362 == nil) goto v_28326;
    goto v_28337;
v_28333:
    v_28362 = elt(env, 2); // or
    goto v_28334;
v_28335:
    goto v_28336;
v_28337:
    goto v_28333;
v_28334:
    goto v_28335;
v_28336:
    return cons(v_28362, v_28363);
v_28326:
    v_28362 = v_28363;
    if (v_28362 == nil) goto v_28340;
    else goto v_28341;
v_28340:
    goto v_28351;
v_28347:
    v_28363 = elt(env, 2); // or
    goto v_28348;
v_28349:
    v_28362 = elt(env, 3); // and
    goto v_28350;
v_28351:
    goto v_28347;
v_28348:
    goto v_28349;
v_28350:
    if (v_28363 == v_28362) goto v_28345;
    else goto v_28346;
v_28345:
    v_28362 = elt(env, 4); // true
    goto v_28344;
v_28346:
    v_28362 = elt(env, 5); // false
    goto v_28344;
    v_28362 = nil;
v_28344:
    goto v_28324;
v_28341:
    v_28362 = v_28363;
    v_28362 = qcar(v_28362);
    goto v_28324;
    v_28362 = nil;
v_28324:
    return onevalue(v_28362);
}



// Code for ofsf_smeqtable

static LispObject CC_ofsf_smeqtable(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28297, v_28298, v_28299, v_28300, v_28301, v_28302;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28300 = v_28257;
    v_28301 = v_28256;
// end of prologue
    v_28297 = elt(env, 1); // ((equal (equal . equal) (neq . false) (geq . equal) (leq . equal) (greaterp . false) (lessp . false)) (neq (neq . neq) (geq
// . greaterp) (leq . lessp) (greaterp . greaterp) (lessp . lessp)) (geq (geq . geq) (leq . equal) (greaterp . greaterp) (lessp
// . false)) (leq (leq . leq) (greaterp . false) (lessp . lessp)) (greaterp (greaterp . greaterp) (lessp . false)) (lessp (lessp
// . lessp)))
    v_28302 = v_28297;
    goto v_28270;
v_28266:
    v_28299 = v_28300;
    goto v_28267;
v_28268:
    goto v_28276;
v_28272:
    v_28298 = v_28301;
    goto v_28273;
v_28274:
    v_28297 = v_28302;
    goto v_28275;
v_28276:
    goto v_28272;
v_28273:
    goto v_28274;
v_28275:
    v_28297 = Latsoc(nil, v_28298, v_28297);
    goto v_28269;
v_28270:
    goto v_28266;
v_28267:
    goto v_28268;
v_28269:
    v_28297 = Latsoc(nil, v_28299, v_28297);
    if (v_28297 == nil) goto v_28265;
    else goto v_28264;
v_28265:
    goto v_28285;
v_28281:
    v_28297 = v_28301;
    goto v_28282;
v_28283:
    goto v_28291;
v_28287:
    v_28298 = v_28300;
    goto v_28288;
v_28289:
    v_28299 = v_28302;
    goto v_28290;
v_28291:
    goto v_28287;
v_28288:
    goto v_28289;
v_28290:
    v_28298 = Latsoc(nil, v_28298, v_28299);
    goto v_28284;
v_28285:
    goto v_28281;
v_28282:
    goto v_28283;
v_28284:
    v_28297 = Latsoc(nil, v_28297, v_28298);
v_28264:
    v_28297 = qcdr(v_28297);
    return onevalue(v_28297);
}



// Code for dfdeg

static LispObject CC_dfdeg(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28294, v_28295;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28294 = v_28257;
    v_28295 = v_28256;
// end of prologue
    goto v_28267;
v_28263:
    goto v_28264;
v_28265:
    goto v_28266;
v_28267:
    goto v_28263;
v_28264:
    goto v_28265;
v_28266:
    v_28294 = Lmember(nil, v_28294, v_28295);
    v_28295 = v_28294;
    if (v_28294 == nil) goto v_28261;
    else goto v_28262;
v_28261:
    v_28294 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28260;
v_28262:
    v_28294 = v_28295;
    v_28294 = qcdr(v_28294);
    if (v_28294 == nil) goto v_28276;
    else goto v_28277;
v_28276:
    v_28294 = lisp_true;
    goto v_28275;
v_28277:
    v_28294 = v_28295;
    v_28294 = qcdr(v_28294);
    v_28294 = qcar(v_28294);
    v_28294 = integerp(v_28294);
    v_28294 = (v_28294 == nil ? lisp_true : nil);
    goto v_28275;
    v_28294 = nil;
v_28275:
    if (v_28294 == nil) goto v_28273;
    v_28294 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28260;
v_28273:
    v_28294 = v_28295;
    v_28294 = qcdr(v_28294);
    v_28294 = qcar(v_28294);
    goto v_28260;
    v_28294 = nil;
v_28260:
    return onevalue(v_28294);
}



// Code for girationalize!:

static LispObject CC_girationalizeT(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28355, v_28356, v_28357;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28256);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_28256;
// end of prologue
    stack[-5] = nil;
// Binding !*gcd
// FLUIDBIND: reloadenv=6 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-6, 1, -3);
    qvalue(elt(env, 1)) = nil; // !*gcd
    v_28355 = lisp_true;
    qvalue(elt(env, 1)) = v_28355; // !*gcd
    goto v_28272;
v_28268:
    stack[-1] = stack[-5];
    goto v_28269;
v_28270:
    v_28355 = stack[-4];
    v_28355 = qcdr(v_28355);
    stack[-5] = v_28355;
    fn = elt(env, 3); // conjgd
    v_28355 = (*qfn1(fn))(fn, v_28355);
    env = stack[-6];
    stack[0] = v_28355;
    goto v_28271;
v_28272:
    goto v_28268;
v_28269:
    goto v_28270;
v_28271:
    if (equal(stack[-1], v_28355)) goto v_28266;
    else goto v_28267;
v_28266:
    v_28355 = stack[-4];
    goto v_28262;
v_28267:
    goto v_28283;
v_28279:
    stack[-2] = stack[0];
    goto v_28280;
v_28281:
    goto v_28290;
v_28286:
    goto v_28296;
v_28292:
    goto v_28302;
v_28298:
    v_28356 = stack[-5];
    goto v_28299;
v_28300:
    v_28355 = stack[0];
    goto v_28301;
v_28302:
    goto v_28298;
v_28299:
    goto v_28300;
v_28301:
    fn = elt(env, 4); // addf
    stack[-1] = (*qfn2(fn))(fn, v_28356, v_28355);
    env = stack[-6];
    goto v_28293;
v_28294:
    goto v_28310;
v_28306:
    goto v_28316;
v_28312:
    goto v_28313;
v_28314:
    v_28355 = stack[-5];
    fn = elt(env, 5); // negf
    v_28355 = (*qfn1(fn))(fn, v_28355);
    env = stack[-6];
    goto v_28315;
v_28316:
    goto v_28312;
v_28313:
    goto v_28314;
v_28315:
    fn = elt(env, 4); // addf
    stack[0] = (*qfn2(fn))(fn, stack[0], v_28355);
    env = stack[-6];
    goto v_28307;
v_28308:
    goto v_28327;
v_28321:
    v_28357 = elt(env, 2); // !:gi!:
    goto v_28322;
v_28323:
    v_28356 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28324;
v_28325:
    v_28355 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28326;
v_28327:
    goto v_28321;
v_28322:
    goto v_28323;
v_28324:
    goto v_28325;
v_28326:
    v_28355 = list2star(v_28357, v_28356, v_28355);
    env = stack[-6];
    goto v_28309;
v_28310:
    goto v_28306;
v_28307:
    goto v_28308;
v_28309:
    fn = elt(env, 6); // multf
    v_28355 = (*qfn2(fn))(fn, stack[0], v_28355);
    env = stack[-6];
    goto v_28295;
v_28296:
    goto v_28292;
v_28293:
    goto v_28294;
v_28295:
    fn = elt(env, 7); // gcdf
    v_28356 = (*qfn2(fn))(fn, stack[-1], v_28355);
    env = stack[-6];
    goto v_28287;
v_28288:
    v_28355 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_28289;
v_28290:
    goto v_28286;
v_28287:
    goto v_28288;
v_28289:
    fn = elt(env, 8); // quotf
    v_28355 = (*qfn2(fn))(fn, v_28356, v_28355);
    env = stack[-6];
    goto v_28282;
v_28283:
    goto v_28279;
v_28280:
    goto v_28281;
v_28282:
    fn = elt(env, 9); // quotf!-fail
    v_28355 = (*qfn2(fn))(fn, stack[-2], v_28355);
    env = stack[-6];
    stack[0] = v_28355;
    goto v_28337;
v_28333:
    goto v_28343;
v_28339:
    v_28355 = stack[-4];
    v_28356 = qcar(v_28355);
    goto v_28340;
v_28341:
    v_28355 = stack[0];
    goto v_28342;
v_28343:
    goto v_28339;
v_28340:
    goto v_28341;
v_28342:
    fn = elt(env, 6); // multf
    stack[-1] = (*qfn2(fn))(fn, v_28356, v_28355);
    env = stack[-6];
    goto v_28334;
v_28335:
    goto v_28352;
v_28348:
    v_28356 = stack[-5];
    goto v_28349;
v_28350:
    v_28355 = stack[0];
    goto v_28351;
v_28352:
    goto v_28348;
v_28349:
    goto v_28350;
v_28351:
    fn = elt(env, 6); // multf
    v_28355 = (*qfn2(fn))(fn, v_28356, v_28355);
    env = stack[-6];
    goto v_28336;
v_28337:
    goto v_28333;
v_28334:
    goto v_28335;
v_28336:
    fn = elt(env, 10); // gigcdsq
    v_28355 = (*qfn2(fn))(fn, stack[-1], v_28355);
v_28262:
    ;}  // end of a binding scope
    return onevalue(v_28355);
}



// Code for makecoeffpairs

static LispObject CC_makecoeffpairs(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28277, v_28278, v_28279, v_28280;
    LispObject fn;
    LispObject v_28259, v_28258, v_28257, v_28256;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "makecoeffpairs");
    va_start(aa, nargs);
    v_28256 = va_arg(aa, LispObject);
    v_28257 = va_arg(aa, LispObject);
    v_28258 = va_arg(aa, LispObject);
    v_28259 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_28259,v_28258,v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_28256,v_28257,v_28258,v_28259);
    }
// copy arguments values to proper place
    v_28277 = v_28259;
    v_28278 = v_28258;
    v_28279 = v_28257;
    v_28280 = v_28256;
// end of prologue
    goto v_28271;
v_28263:
    goto v_28264;
v_28265:
    goto v_28266;
v_28267:
    goto v_28268;
v_28269:
    goto v_28270;
v_28271:
    goto v_28263;
v_28264:
    goto v_28265;
v_28266:
    goto v_28267;
v_28268:
    goto v_28269;
v_28270:
    fn = elt(env, 1); // makecoeffpairs1
    v_28277 = (*qfnn(fn))(fn, 4, v_28280, v_28279, v_28278, v_28277);
    v_28277 = qcdr(v_28277);
        return Lnreverse(nil, v_28277);
}



// Code for cl_sordp

static LispObject CC_cl_sordp(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_29645, v_29646, v_29647, v_29648;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28257;
    stack[-1] = v_28256;
// end of prologue
v_28255:
    v_29645 = stack[-1];
    if (!consp(v_29645)) goto v_28265;
    else goto v_28266;
v_28265:
    v_29645 = stack[-1];
    goto v_28264;
v_28266:
    v_29645 = stack[-1];
    v_29645 = qcar(v_29645);
    goto v_28264;
    v_29645 = nil;
v_28264:
    v_29648 = v_29645;
    v_29645 = stack[0];
    if (!consp(v_29645)) goto v_28275;
    else goto v_28276;
v_28275:
    v_29645 = stack[0];
    goto v_28274;
v_28276:
    v_29645 = stack[0];
    v_29645 = qcar(v_29645);
    goto v_28274;
    v_29645 = nil;
v_28274:
    v_29647 = v_29645;
    goto v_28303;
v_28299:
    v_29646 = v_29648;
    goto v_28300;
v_28301:
    v_29645 = elt(env, 1); // true
    goto v_28302;
v_28303:
    goto v_28299;
v_28300:
    goto v_28301;
v_28302:
    if (v_29646 == v_29645) goto v_28297;
    else goto v_28298;
v_28297:
    v_29645 = lisp_true;
    goto v_28296;
v_28298:
    goto v_28313;
v_28309:
    v_29646 = v_29648;
    goto v_28310;
v_28311:
    v_29645 = elt(env, 2); // false
    goto v_28312;
v_28313:
    goto v_28309;
v_28310:
    goto v_28311;
v_28312:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28296;
    v_29645 = nil;
v_28296:
    if (v_29645 == nil) goto v_28294;
    v_29645 = lisp_true;
    goto v_28292;
v_28294:
    goto v_28340;
v_28336:
    v_29646 = v_29648;
    goto v_28337;
v_28338:
    v_29645 = elt(env, 3); // or
    goto v_28339;
v_28340:
    goto v_28336;
v_28337:
    goto v_28338;
v_28339:
    if (v_29646 == v_29645) goto v_28334;
    else goto v_28335;
v_28334:
    v_29645 = lisp_true;
    goto v_28333;
v_28335:
    goto v_28350;
v_28346:
    v_29646 = v_29648;
    goto v_28347;
v_28348:
    v_29645 = elt(env, 4); // and
    goto v_28349;
v_28350:
    goto v_28346;
v_28347:
    goto v_28348;
v_28349:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28333;
    v_29645 = nil;
v_28333:
    if (v_29645 == nil) goto v_28331;
    v_29645 = lisp_true;
    goto v_28329;
v_28331:
    goto v_28361;
v_28357:
    v_29646 = v_29648;
    goto v_28358;
v_28359:
    v_29645 = elt(env, 5); // not
    goto v_28360;
v_28361:
    goto v_28357;
v_28358:
    goto v_28359;
v_28360:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28329;
    v_29645 = nil;
v_28329:
    if (v_29645 == nil) goto v_28327;
    v_29645 = lisp_true;
    goto v_28325;
v_28327:
    goto v_28376;
v_28372:
    v_29646 = v_29648;
    goto v_28373;
v_28374:
    v_29645 = elt(env, 6); // impl
    goto v_28375;
v_28376:
    goto v_28372;
v_28373:
    goto v_28374;
v_28375:
    if (v_29646 == v_29645) goto v_28370;
    else goto v_28371;
v_28370:
    v_29645 = lisp_true;
    goto v_28369;
v_28371:
    goto v_28390;
v_28386:
    v_29646 = v_29648;
    goto v_28387;
v_28388:
    v_29645 = elt(env, 7); // repl
    goto v_28389;
v_28390:
    goto v_28386;
v_28387:
    goto v_28388;
v_28389:
    if (v_29646 == v_29645) goto v_28384;
    else goto v_28385;
v_28384:
    v_29645 = lisp_true;
    goto v_28383;
v_28385:
    goto v_28400;
v_28396:
    v_29646 = v_29648;
    goto v_28397;
v_28398:
    v_29645 = elt(env, 8); // equiv
    goto v_28399;
v_28400:
    goto v_28396;
v_28397:
    goto v_28398;
v_28399:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28383;
    v_29645 = nil;
v_28383:
    goto v_28369;
    v_29645 = nil;
v_28369:
    goto v_28325;
    v_29645 = nil;
v_28325:
    if (v_29645 == nil) goto v_28323;
    v_29645 = lisp_true;
    goto v_28321;
v_28323:
    goto v_28419;
v_28415:
    v_29646 = v_29648;
    goto v_28416;
v_28417:
    v_29645 = elt(env, 9); // ex
    goto v_28418;
v_28419:
    goto v_28415;
v_28416:
    goto v_28417;
v_28418:
    if (v_29646 == v_29645) goto v_28413;
    else goto v_28414;
v_28413:
    v_29645 = lisp_true;
    goto v_28412;
v_28414:
    goto v_28429;
v_28425:
    v_29646 = v_29648;
    goto v_28426;
v_28427:
    v_29645 = elt(env, 10); // all
    goto v_28428;
v_28429:
    goto v_28425;
v_28426:
    goto v_28427;
v_28428:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28412;
    v_29645 = nil;
v_28412:
    if (v_29645 == nil) goto v_28410;
    v_29645 = lisp_true;
    goto v_28408;
v_28410:
    goto v_28448;
v_28444:
    v_29646 = v_29648;
    goto v_28445;
v_28446:
    v_29645 = elt(env, 11); // bex
    goto v_28447;
v_28448:
    goto v_28444;
v_28445:
    goto v_28446;
v_28447:
    if (v_29646 == v_29645) goto v_28442;
    else goto v_28443;
v_28442:
    v_29645 = lisp_true;
    goto v_28441;
v_28443:
    goto v_28458;
v_28454:
    v_29646 = v_29648;
    goto v_28455;
v_28456:
    v_29645 = elt(env, 12); // ball
    goto v_28457;
v_28458:
    goto v_28454;
v_28455:
    goto v_28456;
v_28457:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28441;
    v_29645 = nil;
v_28441:
    if (v_29645 == nil) goto v_28439;
    v_29645 = lisp_true;
    goto v_28437;
v_28439:
    v_29645 = v_29648;
    if (!symbolp(v_29645)) v_29645 = nil;
    else { v_29645 = qfastgets(v_29645);
           if (v_29645 != nil) { v_29645 = elt(v_29645, 21); // rl_external
#ifdef RECORD_GET
             if (v_29645 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_29645 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_29645 == SPID_NOPROP) v_29645 = nil; }}
#endif
    goto v_28437;
    v_29645 = nil;
v_28437:
    goto v_28408;
    v_29645 = nil;
v_28408:
    goto v_28321;
    v_29645 = nil;
v_28321:
    goto v_28292;
    v_29645 = nil;
v_28292:
    if (v_29645 == nil) goto v_28289;
    else goto v_28290;
v_28289:
    goto v_28479;
v_28475:
    v_29646 = v_29647;
    goto v_28476;
v_28477:
    v_29645 = elt(env, 1); // true
    goto v_28478;
v_28479:
    goto v_28475;
v_28476:
    goto v_28477;
v_28478:
    if (v_29646 == v_29645) goto v_28473;
    else goto v_28474;
v_28473:
    v_29645 = lisp_true;
    goto v_28472;
v_28474:
    goto v_28489;
v_28485:
    v_29646 = v_29647;
    goto v_28486;
v_28487:
    v_29645 = elt(env, 2); // false
    goto v_28488;
v_28489:
    goto v_28485;
v_28486:
    goto v_28487;
v_28488:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28472;
    v_29645 = nil;
v_28472:
    if (v_29645 == nil) goto v_28470;
    v_29645 = lisp_true;
    goto v_28468;
v_28470:
    goto v_28516;
v_28512:
    v_29646 = v_29647;
    goto v_28513;
v_28514:
    v_29645 = elt(env, 3); // or
    goto v_28515;
v_28516:
    goto v_28512;
v_28513:
    goto v_28514;
v_28515:
    if (v_29646 == v_29645) goto v_28510;
    else goto v_28511;
v_28510:
    v_29645 = lisp_true;
    goto v_28509;
v_28511:
    goto v_28526;
v_28522:
    v_29646 = v_29647;
    goto v_28523;
v_28524:
    v_29645 = elt(env, 4); // and
    goto v_28525;
v_28526:
    goto v_28522;
v_28523:
    goto v_28524;
v_28525:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28509;
    v_29645 = nil;
v_28509:
    if (v_29645 == nil) goto v_28507;
    v_29645 = lisp_true;
    goto v_28505;
v_28507:
    goto v_28537;
v_28533:
    v_29646 = v_29647;
    goto v_28534;
v_28535:
    v_29645 = elt(env, 5); // not
    goto v_28536;
v_28537:
    goto v_28533;
v_28534:
    goto v_28535;
v_28536:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28505;
    v_29645 = nil;
v_28505:
    if (v_29645 == nil) goto v_28503;
    v_29645 = lisp_true;
    goto v_28501;
v_28503:
    goto v_28552;
v_28548:
    v_29646 = v_29647;
    goto v_28549;
v_28550:
    v_29645 = elt(env, 6); // impl
    goto v_28551;
v_28552:
    goto v_28548;
v_28549:
    goto v_28550;
v_28551:
    if (v_29646 == v_29645) goto v_28546;
    else goto v_28547;
v_28546:
    v_29645 = lisp_true;
    goto v_28545;
v_28547:
    goto v_28566;
v_28562:
    v_29646 = v_29647;
    goto v_28563;
v_28564:
    v_29645 = elt(env, 7); // repl
    goto v_28565;
v_28566:
    goto v_28562;
v_28563:
    goto v_28564;
v_28565:
    if (v_29646 == v_29645) goto v_28560;
    else goto v_28561;
v_28560:
    v_29645 = lisp_true;
    goto v_28559;
v_28561:
    goto v_28576;
v_28572:
    v_29646 = v_29647;
    goto v_28573;
v_28574:
    v_29645 = elt(env, 8); // equiv
    goto v_28575;
v_28576:
    goto v_28572;
v_28573:
    goto v_28574;
v_28575:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28559;
    v_29645 = nil;
v_28559:
    goto v_28545;
    v_29645 = nil;
v_28545:
    goto v_28501;
    v_29645 = nil;
v_28501:
    if (v_29645 == nil) goto v_28499;
    v_29645 = lisp_true;
    goto v_28497;
v_28499:
    goto v_28595;
v_28591:
    v_29646 = v_29647;
    goto v_28592;
v_28593:
    v_29645 = elt(env, 9); // ex
    goto v_28594;
v_28595:
    goto v_28591;
v_28592:
    goto v_28593;
v_28594:
    if (v_29646 == v_29645) goto v_28589;
    else goto v_28590;
v_28589:
    v_29645 = lisp_true;
    goto v_28588;
v_28590:
    goto v_28605;
v_28601:
    v_29646 = v_29647;
    goto v_28602;
v_28603:
    v_29645 = elt(env, 10); // all
    goto v_28604;
v_28605:
    goto v_28601;
v_28602:
    goto v_28603;
v_28604:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28588;
    v_29645 = nil;
v_28588:
    if (v_29645 == nil) goto v_28586;
    v_29645 = lisp_true;
    goto v_28584;
v_28586:
    goto v_28624;
v_28620:
    v_29646 = v_29647;
    goto v_28621;
v_28622:
    v_29645 = elt(env, 11); // bex
    goto v_28623;
v_28624:
    goto v_28620;
v_28621:
    goto v_28622;
v_28623:
    if (v_29646 == v_29645) goto v_28618;
    else goto v_28619;
v_28618:
    v_29645 = lisp_true;
    goto v_28617;
v_28619:
    goto v_28634;
v_28630:
    v_29646 = v_29647;
    goto v_28631;
v_28632:
    v_29645 = elt(env, 12); // ball
    goto v_28633;
v_28634:
    goto v_28630;
v_28631:
    goto v_28632;
v_28633:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28617;
    v_29645 = nil;
v_28617:
    if (v_29645 == nil) goto v_28615;
    v_29645 = lisp_true;
    goto v_28613;
v_28615:
    v_29645 = v_29647;
    if (!symbolp(v_29645)) v_29645 = nil;
    else { v_29645 = qfastgets(v_29645);
           if (v_29645 != nil) { v_29645 = elt(v_29645, 21); // rl_external
#ifdef RECORD_GET
             if (v_29645 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_29645 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_29645 == SPID_NOPROP) v_29645 = nil; }}
#endif
    goto v_28613;
    v_29645 = nil;
v_28613:
    goto v_28584;
    v_29645 = nil;
v_28584:
    goto v_28497;
    v_29645 = nil;
v_28497:
    goto v_28468;
    v_29645 = nil;
v_28468:
    v_29645 = (v_29645 == nil ? lisp_true : nil);
    goto v_28288;
v_28290:
    v_29645 = nil;
    goto v_28288;
    v_29645 = nil;
v_28288:
    if (v_29645 == nil) goto v_28286;
    goto v_28652;
v_28648:
    v_29646 = stack[-1];
    goto v_28649;
v_28650:
    v_29645 = stack[0];
    goto v_28651;
v_28652:
    goto v_28648;
v_28649:
    goto v_28650;
v_28651:
    {
        fn = elt(env, 13); // rl_ordatp
        return (*qfn2(fn))(fn, v_29646, v_29645);
    }
v_28286:
    goto v_28675;
v_28671:
    v_29646 = v_29648;
    goto v_28672;
v_28673:
    v_29645 = elt(env, 1); // true
    goto v_28674;
v_28675:
    goto v_28671;
v_28672:
    goto v_28673;
v_28674:
    if (v_29646 == v_29645) goto v_28669;
    else goto v_28670;
v_28669:
    v_29645 = lisp_true;
    goto v_28668;
v_28670:
    goto v_28685;
v_28681:
    v_29646 = v_29648;
    goto v_28682;
v_28683:
    v_29645 = elt(env, 2); // false
    goto v_28684;
v_28685:
    goto v_28681;
v_28682:
    goto v_28683;
v_28684:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28668;
    v_29645 = nil;
v_28668:
    if (v_29645 == nil) goto v_28666;
    v_29645 = lisp_true;
    goto v_28664;
v_28666:
    goto v_28712;
v_28708:
    v_29646 = v_29648;
    goto v_28709;
v_28710:
    v_29645 = elt(env, 3); // or
    goto v_28711;
v_28712:
    goto v_28708;
v_28709:
    goto v_28710;
v_28711:
    if (v_29646 == v_29645) goto v_28706;
    else goto v_28707;
v_28706:
    v_29645 = lisp_true;
    goto v_28705;
v_28707:
    goto v_28722;
v_28718:
    v_29646 = v_29648;
    goto v_28719;
v_28720:
    v_29645 = elt(env, 4); // and
    goto v_28721;
v_28722:
    goto v_28718;
v_28719:
    goto v_28720;
v_28721:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28705;
    v_29645 = nil;
v_28705:
    if (v_29645 == nil) goto v_28703;
    v_29645 = lisp_true;
    goto v_28701;
v_28703:
    goto v_28733;
v_28729:
    v_29646 = v_29648;
    goto v_28730;
v_28731:
    v_29645 = elt(env, 5); // not
    goto v_28732;
v_28733:
    goto v_28729;
v_28730:
    goto v_28731;
v_28732:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28701;
    v_29645 = nil;
v_28701:
    if (v_29645 == nil) goto v_28699;
    v_29645 = lisp_true;
    goto v_28697;
v_28699:
    goto v_28748;
v_28744:
    v_29646 = v_29648;
    goto v_28745;
v_28746:
    v_29645 = elt(env, 6); // impl
    goto v_28747;
v_28748:
    goto v_28744;
v_28745:
    goto v_28746;
v_28747:
    if (v_29646 == v_29645) goto v_28742;
    else goto v_28743;
v_28742:
    v_29645 = lisp_true;
    goto v_28741;
v_28743:
    goto v_28762;
v_28758:
    v_29646 = v_29648;
    goto v_28759;
v_28760:
    v_29645 = elt(env, 7); // repl
    goto v_28761;
v_28762:
    goto v_28758;
v_28759:
    goto v_28760;
v_28761:
    if (v_29646 == v_29645) goto v_28756;
    else goto v_28757;
v_28756:
    v_29645 = lisp_true;
    goto v_28755;
v_28757:
    goto v_28772;
v_28768:
    v_29646 = v_29648;
    goto v_28769;
v_28770:
    v_29645 = elt(env, 8); // equiv
    goto v_28771;
v_28772:
    goto v_28768;
v_28769:
    goto v_28770;
v_28771:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28755;
    v_29645 = nil;
v_28755:
    goto v_28741;
    v_29645 = nil;
v_28741:
    goto v_28697;
    v_29645 = nil;
v_28697:
    if (v_29645 == nil) goto v_28695;
    v_29645 = lisp_true;
    goto v_28693;
v_28695:
    goto v_28791;
v_28787:
    v_29646 = v_29648;
    goto v_28788;
v_28789:
    v_29645 = elt(env, 9); // ex
    goto v_28790;
v_28791:
    goto v_28787;
v_28788:
    goto v_28789;
v_28790:
    if (v_29646 == v_29645) goto v_28785;
    else goto v_28786;
v_28785:
    v_29645 = lisp_true;
    goto v_28784;
v_28786:
    goto v_28801;
v_28797:
    v_29646 = v_29648;
    goto v_28798;
v_28799:
    v_29645 = elt(env, 10); // all
    goto v_28800;
v_28801:
    goto v_28797;
v_28798:
    goto v_28799;
v_28800:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28784;
    v_29645 = nil;
v_28784:
    if (v_29645 == nil) goto v_28782;
    v_29645 = lisp_true;
    goto v_28780;
v_28782:
    goto v_28820;
v_28816:
    v_29646 = v_29648;
    goto v_28817;
v_28818:
    v_29645 = elt(env, 11); // bex
    goto v_28819;
v_28820:
    goto v_28816;
v_28817:
    goto v_28818;
v_28819:
    if (v_29646 == v_29645) goto v_28814;
    else goto v_28815;
v_28814:
    v_29645 = lisp_true;
    goto v_28813;
v_28815:
    goto v_28830;
v_28826:
    v_29646 = v_29648;
    goto v_28827;
v_28828:
    v_29645 = elt(env, 12); // ball
    goto v_28829;
v_28830:
    goto v_28826;
v_28827:
    goto v_28828;
v_28829:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28813;
    v_29645 = nil;
v_28813:
    if (v_29645 == nil) goto v_28811;
    v_29645 = lisp_true;
    goto v_28809;
v_28811:
    v_29645 = v_29648;
    if (!symbolp(v_29645)) v_29645 = nil;
    else { v_29645 = qfastgets(v_29645);
           if (v_29645 != nil) { v_29645 = elt(v_29645, 21); // rl_external
#ifdef RECORD_GET
             if (v_29645 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_29645 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_29645 == SPID_NOPROP) v_29645 = nil; }}
#endif
    goto v_28809;
    v_29645 = nil;
v_28809:
    goto v_28780;
    v_29645 = nil;
v_28780:
    goto v_28693;
    v_29645 = nil;
v_28693:
    goto v_28664;
    v_29645 = nil;
v_28664:
    if (v_29645 == nil) goto v_28661;
    else goto v_28662;
v_28661:
    goto v_28851;
v_28847:
    v_29646 = v_29647;
    goto v_28848;
v_28849:
    v_29645 = elt(env, 1); // true
    goto v_28850;
v_28851:
    goto v_28847;
v_28848:
    goto v_28849;
v_28850:
    if (v_29646 == v_29645) goto v_28845;
    else goto v_28846;
v_28845:
    v_29645 = lisp_true;
    goto v_28844;
v_28846:
    goto v_28861;
v_28857:
    v_29646 = v_29647;
    goto v_28858;
v_28859:
    v_29645 = elt(env, 2); // false
    goto v_28860;
v_28861:
    goto v_28857;
v_28858:
    goto v_28859;
v_28860:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28844;
    v_29645 = nil;
v_28844:
    if (v_29645 == nil) goto v_28842;
    v_29645 = lisp_true;
    goto v_28840;
v_28842:
    goto v_28888;
v_28884:
    v_29646 = v_29647;
    goto v_28885;
v_28886:
    v_29645 = elt(env, 3); // or
    goto v_28887;
v_28888:
    goto v_28884;
v_28885:
    goto v_28886;
v_28887:
    if (v_29646 == v_29645) goto v_28882;
    else goto v_28883;
v_28882:
    v_29645 = lisp_true;
    goto v_28881;
v_28883:
    goto v_28898;
v_28894:
    v_29646 = v_29647;
    goto v_28895;
v_28896:
    v_29645 = elt(env, 4); // and
    goto v_28897;
v_28898:
    goto v_28894;
v_28895:
    goto v_28896;
v_28897:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28881;
    v_29645 = nil;
v_28881:
    if (v_29645 == nil) goto v_28879;
    v_29645 = lisp_true;
    goto v_28877;
v_28879:
    goto v_28909;
v_28905:
    v_29646 = v_29647;
    goto v_28906;
v_28907:
    v_29645 = elt(env, 5); // not
    goto v_28908;
v_28909:
    goto v_28905;
v_28906:
    goto v_28907;
v_28908:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28877;
    v_29645 = nil;
v_28877:
    if (v_29645 == nil) goto v_28875;
    v_29645 = lisp_true;
    goto v_28873;
v_28875:
    goto v_28924;
v_28920:
    v_29646 = v_29647;
    goto v_28921;
v_28922:
    v_29645 = elt(env, 6); // impl
    goto v_28923;
v_28924:
    goto v_28920;
v_28921:
    goto v_28922;
v_28923:
    if (v_29646 == v_29645) goto v_28918;
    else goto v_28919;
v_28918:
    v_29645 = lisp_true;
    goto v_28917;
v_28919:
    goto v_28938;
v_28934:
    v_29646 = v_29647;
    goto v_28935;
v_28936:
    v_29645 = elt(env, 7); // repl
    goto v_28937;
v_28938:
    goto v_28934;
v_28935:
    goto v_28936;
v_28937:
    if (v_29646 == v_29645) goto v_28932;
    else goto v_28933;
v_28932:
    v_29645 = lisp_true;
    goto v_28931;
v_28933:
    goto v_28948;
v_28944:
    v_29646 = v_29647;
    goto v_28945;
v_28946:
    v_29645 = elt(env, 8); // equiv
    goto v_28947;
v_28948:
    goto v_28944;
v_28945:
    goto v_28946;
v_28947:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28931;
    v_29645 = nil;
v_28931:
    goto v_28917;
    v_29645 = nil;
v_28917:
    goto v_28873;
    v_29645 = nil;
v_28873:
    if (v_29645 == nil) goto v_28871;
    v_29645 = lisp_true;
    goto v_28869;
v_28871:
    goto v_28967;
v_28963:
    v_29646 = v_29647;
    goto v_28964;
v_28965:
    v_29645 = elt(env, 9); // ex
    goto v_28966;
v_28967:
    goto v_28963;
v_28964:
    goto v_28965;
v_28966:
    if (v_29646 == v_29645) goto v_28961;
    else goto v_28962;
v_28961:
    v_29645 = lisp_true;
    goto v_28960;
v_28962:
    goto v_28977;
v_28973:
    v_29646 = v_29647;
    goto v_28974;
v_28975:
    v_29645 = elt(env, 10); // all
    goto v_28976;
v_28977:
    goto v_28973;
v_28974:
    goto v_28975;
v_28976:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28960;
    v_29645 = nil;
v_28960:
    if (v_29645 == nil) goto v_28958;
    v_29645 = lisp_true;
    goto v_28956;
v_28958:
    goto v_28996;
v_28992:
    v_29646 = v_29647;
    goto v_28993;
v_28994:
    v_29645 = elt(env, 11); // bex
    goto v_28995;
v_28996:
    goto v_28992;
v_28993:
    goto v_28994;
v_28995:
    if (v_29646 == v_29645) goto v_28990;
    else goto v_28991;
v_28990:
    v_29645 = lisp_true;
    goto v_28989;
v_28991:
    goto v_29006;
v_29002:
    v_29646 = v_29647;
    goto v_29003;
v_29004:
    v_29645 = elt(env, 12); // ball
    goto v_29005;
v_29006:
    goto v_29002;
v_29003:
    goto v_29004;
v_29005:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_28989;
    v_29645 = nil;
v_28989:
    if (v_29645 == nil) goto v_28987;
    v_29645 = lisp_true;
    goto v_28985;
v_28987:
    v_29645 = v_29647;
    if (!symbolp(v_29645)) v_29645 = nil;
    else { v_29645 = qfastgets(v_29645);
           if (v_29645 != nil) { v_29645 = elt(v_29645, 21); // rl_external
#ifdef RECORD_GET
             if (v_29645 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_29645 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_29645 == SPID_NOPROP) v_29645 = nil; }}
#endif
    goto v_28985;
    v_29645 = nil;
v_28985:
    goto v_28956;
    v_29645 = nil;
v_28956:
    goto v_28869;
    v_29645 = nil;
v_28869:
    goto v_28840;
    v_29645 = nil;
v_28840:
    goto v_28660;
v_28662:
    v_29645 = nil;
    goto v_28660;
    v_29645 = nil;
v_28660:
    if (v_29645 == nil) goto v_28658;
    v_29645 = lisp_true;
    goto v_28262;
v_28658:
    goto v_29036;
v_29032:
    v_29646 = v_29648;
    goto v_29033;
v_29034:
    v_29645 = elt(env, 1); // true
    goto v_29035;
v_29036:
    goto v_29032;
v_29033:
    goto v_29034;
v_29035:
    if (v_29646 == v_29645) goto v_29030;
    else goto v_29031;
v_29030:
    v_29645 = lisp_true;
    goto v_29029;
v_29031:
    goto v_29046;
v_29042:
    v_29646 = v_29648;
    goto v_29043;
v_29044:
    v_29645 = elt(env, 2); // false
    goto v_29045;
v_29046:
    goto v_29042;
v_29043:
    goto v_29044;
v_29045:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_29029;
    v_29645 = nil;
v_29029:
    if (v_29645 == nil) goto v_29027;
    v_29645 = lisp_true;
    goto v_29025;
v_29027:
    goto v_29073;
v_29069:
    v_29646 = v_29648;
    goto v_29070;
v_29071:
    v_29645 = elt(env, 3); // or
    goto v_29072;
v_29073:
    goto v_29069;
v_29070:
    goto v_29071;
v_29072:
    if (v_29646 == v_29645) goto v_29067;
    else goto v_29068;
v_29067:
    v_29645 = lisp_true;
    goto v_29066;
v_29068:
    goto v_29083;
v_29079:
    v_29646 = v_29648;
    goto v_29080;
v_29081:
    v_29645 = elt(env, 4); // and
    goto v_29082;
v_29083:
    goto v_29079;
v_29080:
    goto v_29081;
v_29082:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_29066;
    v_29645 = nil;
v_29066:
    if (v_29645 == nil) goto v_29064;
    v_29645 = lisp_true;
    goto v_29062;
v_29064:
    goto v_29094;
v_29090:
    v_29646 = v_29648;
    goto v_29091;
v_29092:
    v_29645 = elt(env, 5); // not
    goto v_29093;
v_29094:
    goto v_29090;
v_29091:
    goto v_29092;
v_29093:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_29062;
    v_29645 = nil;
v_29062:
    if (v_29645 == nil) goto v_29060;
    v_29645 = lisp_true;
    goto v_29058;
v_29060:
    goto v_29109;
v_29105:
    v_29646 = v_29648;
    goto v_29106;
v_29107:
    v_29645 = elt(env, 6); // impl
    goto v_29108;
v_29109:
    goto v_29105;
v_29106:
    goto v_29107;
v_29108:
    if (v_29646 == v_29645) goto v_29103;
    else goto v_29104;
v_29103:
    v_29645 = lisp_true;
    goto v_29102;
v_29104:
    goto v_29123;
v_29119:
    v_29646 = v_29648;
    goto v_29120;
v_29121:
    v_29645 = elt(env, 7); // repl
    goto v_29122;
v_29123:
    goto v_29119;
v_29120:
    goto v_29121;
v_29122:
    if (v_29646 == v_29645) goto v_29117;
    else goto v_29118;
v_29117:
    v_29645 = lisp_true;
    goto v_29116;
v_29118:
    goto v_29133;
v_29129:
    v_29646 = v_29648;
    goto v_29130;
v_29131:
    v_29645 = elt(env, 8); // equiv
    goto v_29132;
v_29133:
    goto v_29129;
v_29130:
    goto v_29131;
v_29132:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_29116;
    v_29645 = nil;
v_29116:
    goto v_29102;
    v_29645 = nil;
v_29102:
    goto v_29058;
    v_29645 = nil;
v_29058:
    if (v_29645 == nil) goto v_29056;
    v_29645 = lisp_true;
    goto v_29054;
v_29056:
    goto v_29152;
v_29148:
    v_29646 = v_29648;
    goto v_29149;
v_29150:
    v_29645 = elt(env, 9); // ex
    goto v_29151;
v_29152:
    goto v_29148;
v_29149:
    goto v_29150;
v_29151:
    if (v_29646 == v_29645) goto v_29146;
    else goto v_29147;
v_29146:
    v_29645 = lisp_true;
    goto v_29145;
v_29147:
    goto v_29162;
v_29158:
    v_29646 = v_29648;
    goto v_29159;
v_29160:
    v_29645 = elt(env, 10); // all
    goto v_29161;
v_29162:
    goto v_29158;
v_29159:
    goto v_29160;
v_29161:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_29145;
    v_29645 = nil;
v_29145:
    if (v_29645 == nil) goto v_29143;
    v_29645 = lisp_true;
    goto v_29141;
v_29143:
    goto v_29181;
v_29177:
    v_29646 = v_29648;
    goto v_29178;
v_29179:
    v_29645 = elt(env, 11); // bex
    goto v_29180;
v_29181:
    goto v_29177;
v_29178:
    goto v_29179;
v_29180:
    if (v_29646 == v_29645) goto v_29175;
    else goto v_29176;
v_29175:
    v_29645 = lisp_true;
    goto v_29174;
v_29176:
    goto v_29191;
v_29187:
    v_29646 = v_29648;
    goto v_29188;
v_29189:
    v_29645 = elt(env, 12); // ball
    goto v_29190;
v_29191:
    goto v_29187;
v_29188:
    goto v_29189;
v_29190:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_29174;
    v_29645 = nil;
v_29174:
    if (v_29645 == nil) goto v_29172;
    v_29645 = lisp_true;
    goto v_29170;
v_29172:
    v_29645 = v_29648;
    if (!symbolp(v_29645)) v_29645 = nil;
    else { v_29645 = qfastgets(v_29645);
           if (v_29645 != nil) { v_29645 = elt(v_29645, 21); // rl_external
#ifdef RECORD_GET
             if (v_29645 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_29645 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_29645 == SPID_NOPROP) v_29645 = nil; }}
#endif
    goto v_29170;
    v_29645 = nil;
v_29170:
    goto v_29141;
    v_29645 = nil;
v_29141:
    goto v_29054;
    v_29645 = nil;
v_29054:
    goto v_29025;
    v_29645 = nil;
v_29025:
    if (v_29645 == nil) goto v_29022;
    goto v_29213;
v_29209:
    v_29646 = v_29647;
    goto v_29210;
v_29211:
    v_29645 = elt(env, 1); // true
    goto v_29212;
v_29213:
    goto v_29209;
v_29210:
    goto v_29211;
v_29212:
    if (v_29646 == v_29645) goto v_29207;
    else goto v_29208;
v_29207:
    v_29645 = lisp_true;
    goto v_29206;
v_29208:
    goto v_29223;
v_29219:
    v_29646 = v_29647;
    goto v_29220;
v_29221:
    v_29645 = elt(env, 2); // false
    goto v_29222;
v_29223:
    goto v_29219;
v_29220:
    goto v_29221;
v_29222:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_29206;
    v_29645 = nil;
v_29206:
    if (v_29645 == nil) goto v_29204;
    v_29645 = lisp_true;
    goto v_29202;
v_29204:
    goto v_29250;
v_29246:
    v_29646 = v_29647;
    goto v_29247;
v_29248:
    v_29645 = elt(env, 3); // or
    goto v_29249;
v_29250:
    goto v_29246;
v_29247:
    goto v_29248;
v_29249:
    if (v_29646 == v_29645) goto v_29244;
    else goto v_29245;
v_29244:
    v_29645 = lisp_true;
    goto v_29243;
v_29245:
    goto v_29260;
v_29256:
    v_29646 = v_29647;
    goto v_29257;
v_29258:
    v_29645 = elt(env, 4); // and
    goto v_29259;
v_29260:
    goto v_29256;
v_29257:
    goto v_29258;
v_29259:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_29243;
    v_29645 = nil;
v_29243:
    if (v_29645 == nil) goto v_29241;
    v_29645 = lisp_true;
    goto v_29239;
v_29241:
    goto v_29271;
v_29267:
    v_29646 = v_29647;
    goto v_29268;
v_29269:
    v_29645 = elt(env, 5); // not
    goto v_29270;
v_29271:
    goto v_29267;
v_29268:
    goto v_29269;
v_29270:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_29239;
    v_29645 = nil;
v_29239:
    if (v_29645 == nil) goto v_29237;
    v_29645 = lisp_true;
    goto v_29235;
v_29237:
    goto v_29286;
v_29282:
    v_29646 = v_29647;
    goto v_29283;
v_29284:
    v_29645 = elt(env, 6); // impl
    goto v_29285;
v_29286:
    goto v_29282;
v_29283:
    goto v_29284;
v_29285:
    if (v_29646 == v_29645) goto v_29280;
    else goto v_29281;
v_29280:
    v_29645 = lisp_true;
    goto v_29279;
v_29281:
    goto v_29300;
v_29296:
    v_29646 = v_29647;
    goto v_29297;
v_29298:
    v_29645 = elt(env, 7); // repl
    goto v_29299;
v_29300:
    goto v_29296;
v_29297:
    goto v_29298;
v_29299:
    if (v_29646 == v_29645) goto v_29294;
    else goto v_29295;
v_29294:
    v_29645 = lisp_true;
    goto v_29293;
v_29295:
    goto v_29310;
v_29306:
    v_29646 = v_29647;
    goto v_29307;
v_29308:
    v_29645 = elt(env, 8); // equiv
    goto v_29309;
v_29310:
    goto v_29306;
v_29307:
    goto v_29308;
v_29309:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_29293;
    v_29645 = nil;
v_29293:
    goto v_29279;
    v_29645 = nil;
v_29279:
    goto v_29235;
    v_29645 = nil;
v_29235:
    if (v_29645 == nil) goto v_29233;
    v_29645 = lisp_true;
    goto v_29231;
v_29233:
    goto v_29329;
v_29325:
    v_29646 = v_29647;
    goto v_29326;
v_29327:
    v_29645 = elt(env, 9); // ex
    goto v_29328;
v_29329:
    goto v_29325;
v_29326:
    goto v_29327;
v_29328:
    if (v_29646 == v_29645) goto v_29323;
    else goto v_29324;
v_29323:
    v_29645 = lisp_true;
    goto v_29322;
v_29324:
    goto v_29339;
v_29335:
    v_29646 = v_29647;
    goto v_29336;
v_29337:
    v_29645 = elt(env, 10); // all
    goto v_29338;
v_29339:
    goto v_29335;
v_29336:
    goto v_29337;
v_29338:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_29322;
    v_29645 = nil;
v_29322:
    if (v_29645 == nil) goto v_29320;
    v_29645 = lisp_true;
    goto v_29318;
v_29320:
    goto v_29358;
v_29354:
    v_29646 = v_29647;
    goto v_29355;
v_29356:
    v_29645 = elt(env, 11); // bex
    goto v_29357;
v_29358:
    goto v_29354;
v_29355:
    goto v_29356;
v_29357:
    if (v_29646 == v_29645) goto v_29352;
    else goto v_29353;
v_29352:
    v_29645 = lisp_true;
    goto v_29351;
v_29353:
    goto v_29368;
v_29364:
    v_29646 = v_29647;
    goto v_29365;
v_29366:
    v_29645 = elt(env, 12); // ball
    goto v_29367;
v_29368:
    goto v_29364;
v_29365:
    goto v_29366;
v_29367:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_29351;
    v_29645 = nil;
v_29351:
    if (v_29645 == nil) goto v_29349;
    v_29645 = lisp_true;
    goto v_29347;
v_29349:
    v_29645 = v_29647;
    if (!symbolp(v_29645)) v_29645 = nil;
    else { v_29645 = qfastgets(v_29645);
           if (v_29645 != nil) { v_29645 = elt(v_29645, 21); // rl_external
#ifdef RECORD_GET
             if (v_29645 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_29645 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_29645 == SPID_NOPROP) v_29645 = nil; }}
#endif
    goto v_29347;
    v_29645 = nil;
v_29347:
    goto v_29318;
    v_29645 = nil;
v_29318:
    goto v_29231;
    v_29645 = nil;
v_29231:
    goto v_29202;
    v_29645 = nil;
v_29202:
    if (v_29645 == nil) goto v_29200;
    else goto v_29022;
v_29200:
    v_29645 = nil;
    goto v_28262;
v_29022:
    goto v_29386;
v_29382:
    v_29646 = v_29648;
    goto v_29383;
v_29384:
    v_29645 = v_29647;
    goto v_29385;
v_29386:
    goto v_29382;
v_29383:
    goto v_29384;
v_29385:
    if (equal(v_29646, v_29645)) goto v_29381;
    goto v_29394;
v_29390:
    v_29645 = v_29648;
    goto v_29391;
v_29392:
    v_29646 = v_29647;
    goto v_29393;
v_29394:
    goto v_29390;
v_29391:
    goto v_29392;
v_29393:
    {
        fn = elt(env, 14); // cl_ordopp
        return (*qfn2(fn))(fn, v_29645, v_29646);
    }
v_29381:
    goto v_29409;
v_29405:
    v_29646 = v_29648;
    goto v_29406;
v_29407:
    v_29645 = elt(env, 1); // true
    goto v_29408;
v_29409:
    goto v_29405;
v_29406:
    goto v_29407;
v_29408:
    if (v_29646 == v_29645) goto v_29403;
    else goto v_29404;
v_29403:
    v_29645 = lisp_true;
    goto v_29402;
v_29404:
    goto v_29419;
v_29415:
    v_29646 = v_29648;
    goto v_29416;
v_29417:
    v_29645 = elt(env, 2); // false
    goto v_29418;
v_29419:
    goto v_29415;
v_29416:
    goto v_29417;
v_29418:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_29402;
    v_29645 = nil;
v_29402:
    if (v_29645 == nil) goto v_29400;
    v_29645 = lisp_true;
    goto v_28262;
v_29400:
    goto v_29436;
v_29432:
    v_29646 = v_29648;
    goto v_29433;
v_29434:
    v_29645 = elt(env, 9); // ex
    goto v_29435;
v_29436:
    goto v_29432;
v_29433:
    goto v_29434;
v_29435:
    if (v_29646 == v_29645) goto v_29430;
    else goto v_29431;
v_29430:
    v_29645 = lisp_true;
    goto v_29429;
v_29431:
    goto v_29446;
v_29442:
    v_29646 = v_29648;
    goto v_29443;
v_29444:
    v_29645 = elt(env, 10); // all
    goto v_29445;
v_29446:
    goto v_29442;
v_29443:
    goto v_29444;
v_29445:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_29429;
    v_29645 = nil;
v_29429:
    if (v_29645 == nil) goto v_29427;
    goto v_29458;
v_29454:
    v_29645 = stack[-1];
    v_29645 = qcdr(v_29645);
    v_29646 = qcar(v_29645);
    goto v_29455;
v_29456:
    v_29645 = stack[0];
    v_29645 = qcdr(v_29645);
    v_29645 = qcar(v_29645);
    goto v_29457;
v_29458:
    goto v_29454;
v_29455:
    goto v_29456;
v_29457:
    if (equal(v_29646, v_29645)) goto v_29453;
    goto v_29474;
v_29470:
    v_29645 = stack[-1];
    v_29645 = qcdr(v_29645);
    v_29646 = qcar(v_29645);
    goto v_29471;
v_29472:
    v_29645 = stack[0];
    v_29645 = qcdr(v_29645);
    v_29645 = qcar(v_29645);
    goto v_29473;
v_29474:
    goto v_29470;
v_29471:
    goto v_29472;
v_29473:
    fn = elt(env, 15); // ordp
    v_29645 = (*qfn2(fn))(fn, v_29646, v_29645);
    env = stack[-2];
    if (v_29645 == nil) goto v_29467;
    else goto v_29468;
v_29467:
    v_29645 = nil;
    goto v_29466;
v_29468:
    goto v_29489;
v_29485:
    v_29645 = stack[-1];
    v_29645 = qcdr(v_29645);
    v_29646 = qcar(v_29645);
    goto v_29486;
v_29487:
    v_29645 = stack[0];
    v_29645 = qcdr(v_29645);
    v_29645 = qcar(v_29645);
    goto v_29488;
v_29489:
    goto v_29485;
v_29486:
    goto v_29487;
v_29488:
    v_29645 = Lneq(nil, v_29646, v_29645);
    goto v_29466;
    v_29645 = nil;
v_29466:
    v_29645 = (v_29645 == nil ? lisp_true : nil);
    goto v_28262;
v_29453:
    goto v_29504;
v_29500:
    v_29645 = stack[-1];
    v_29645 = qcdr(v_29645);
    v_29645 = qcdr(v_29645);
    v_29646 = qcar(v_29645);
    goto v_29501;
v_29502:
    v_29645 = stack[0];
    v_29645 = qcdr(v_29645);
    v_29645 = qcdr(v_29645);
    v_29645 = qcar(v_29645);
    goto v_29503;
v_29504:
    goto v_29500;
v_29501:
    goto v_29502;
v_29503:
    stack[-1] = v_29646;
    stack[0] = v_29645;
    goto v_28255;
    goto v_29425;
v_29427:
v_29425:
    goto v_29525;
v_29521:
    v_29646 = v_29648;
    goto v_29522;
v_29523:
    v_29645 = elt(env, 11); // bex
    goto v_29524;
v_29525:
    goto v_29521;
v_29522:
    goto v_29523;
v_29524:
    if (v_29646 == v_29645) goto v_29519;
    else goto v_29520;
v_29519:
    v_29645 = lisp_true;
    goto v_29518;
v_29520:
    goto v_29535;
v_29531:
    v_29646 = v_29648;
    goto v_29532;
v_29533:
    v_29645 = elt(env, 12); // ball
    goto v_29534;
v_29535:
    goto v_29531;
v_29532:
    goto v_29533;
v_29534:
    v_29645 = (v_29646 == v_29645 ? lisp_true : nil);
    goto v_29518;
    v_29645 = nil;
v_29518:
    if (v_29645 == nil) goto v_29516;
    goto v_29547;
v_29543:
    v_29645 = stack[-1];
    v_29645 = qcdr(v_29645);
    v_29646 = qcar(v_29645);
    goto v_29544;
v_29545:
    v_29645 = stack[0];
    v_29645 = qcdr(v_29645);
    v_29645 = qcar(v_29645);
    goto v_29546;
v_29547:
    goto v_29543;
v_29544:
    goto v_29545;
v_29546:
    if (equal(v_29646, v_29645)) goto v_29542;
    goto v_29563;
v_29559:
    v_29645 = stack[-1];
    v_29645 = qcdr(v_29645);
    v_29646 = qcar(v_29645);
    goto v_29560;
v_29561:
    v_29645 = stack[0];
    v_29645 = qcdr(v_29645);
    v_29645 = qcar(v_29645);
    goto v_29562;
v_29563:
    goto v_29559;
v_29560:
    goto v_29561;
v_29562:
    fn = elt(env, 15); // ordp
    v_29645 = (*qfn2(fn))(fn, v_29646, v_29645);
    env = stack[-2];
    if (v_29645 == nil) goto v_29556;
    else goto v_29557;
v_29556:
    v_29645 = nil;
    goto v_29555;
v_29557:
    goto v_29578;
v_29574:
    v_29645 = stack[-1];
    v_29645 = qcdr(v_29645);
    v_29646 = qcar(v_29645);
    goto v_29575;
v_29576:
    v_29645 = stack[0];
    v_29645 = qcdr(v_29645);
    v_29645 = qcar(v_29645);
    goto v_29577;
v_29578:
    goto v_29574;
v_29575:
    goto v_29576;
v_29577:
    v_29645 = Lneq(nil, v_29646, v_29645);
    goto v_29555;
    v_29645 = nil;
v_29555:
    v_29645 = (v_29645 == nil ? lisp_true : nil);
    goto v_28262;
v_29542:
    goto v_29592;
v_29588:
    v_29645 = stack[-1];
    v_29645 = qcdr(v_29645);
    v_29645 = qcdr(v_29645);
    v_29645 = qcdr(v_29645);
    v_29646 = qcar(v_29645);
    goto v_29589;
v_29590:
    v_29645 = stack[0];
    v_29645 = qcdr(v_29645);
    v_29645 = qcdr(v_29645);
    v_29645 = qcdr(v_29645);
    v_29645 = qcar(v_29645);
    goto v_29591;
v_29592:
    goto v_29588;
v_29589:
    goto v_29590;
v_29591:
    if (equal(v_29646, v_29645)) goto v_29587;
    goto v_29608;
v_29604:
    v_29645 = stack[-1];
    v_29645 = qcdr(v_29645);
    v_29645 = qcdr(v_29645);
    v_29645 = qcdr(v_29645);
    v_29646 = qcar(v_29645);
    goto v_29605;
v_29606:
    v_29645 = stack[0];
    v_29645 = qcdr(v_29645);
    v_29645 = qcdr(v_29645);
    v_29645 = qcdr(v_29645);
    v_29645 = qcar(v_29645);
    goto v_29607;
v_29608:
    goto v_29604;
v_29605:
    goto v_29606;
v_29607:
    stack[-1] = v_29646;
    stack[0] = v_29645;
    goto v_28255;
v_29587:
    goto v_29626;
v_29622:
    v_29645 = stack[-1];
    v_29645 = qcdr(v_29645);
    v_29645 = qcdr(v_29645);
    v_29646 = qcar(v_29645);
    goto v_29623;
v_29624:
    v_29645 = stack[0];
    v_29645 = qcdr(v_29645);
    v_29645 = qcdr(v_29645);
    v_29645 = qcar(v_29645);
    goto v_29625;
v_29626:
    goto v_29622;
v_29623:
    goto v_29624;
v_29625:
    stack[-1] = v_29646;
    stack[0] = v_29645;
    goto v_28255;
    goto v_29514;
v_29516:
v_29514:
    goto v_29640;
v_29636:
    v_29645 = stack[-1];
    v_29646 = qcdr(v_29645);
    goto v_29637;
v_29638:
    v_29645 = stack[0];
    v_29645 = qcdr(v_29645);
    goto v_29639;
v_29640:
    goto v_29636;
v_29637:
    goto v_29638;
v_29639:
    {
        fn = elt(env, 16); // cl_sordpl
        return (*qfn2(fn))(fn, v_29646, v_29645);
    }
v_28262:
    return onevalue(v_29645);
}



// Code for bc_dcont

static LispObject CC_bc_dcont(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28261;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28261 = v_28256;
// end of prologue
    v_28261 = qcar(v_28261);
    {
        fn = elt(env, 1); // sfto_dcontentf
        return (*qfn1(fn))(fn, v_28261);
    }
}



// Code for dvfsf_susipost

static LispObject CC_dvfsf_susipost(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28260, v_28261;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28260 = v_28257;
    v_28261 = v_28256;
// end of prologue
    v_28260 = v_28261;
    return onevalue(v_28260);
}



// Code for matsm!*

static LispObject CC_matsmH(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28262, v_28263;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_28262 = v_28257;
    v_28263 = v_28256;
// end of prologue
    v_28262 = v_28263;
    fn = elt(env, 1); // matsm
    v_28262 = (*qfn1(fn))(fn, v_28262);
    env = stack[0];
    {
        fn = elt(env, 2); // matsm!*1
        return (*qfn1(fn))(fn, v_28262);
    }
}



// Code for vdplsort

static LispObject CC_vdplsort(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28266, v_28267;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28266 = v_28256;
// end of prologue
    goto v_28263;
v_28259:
    v_28267 = v_28266;
    goto v_28260;
v_28261:
    v_28266 = elt(env, 1); // vdpvevlcomp
    goto v_28262;
v_28263:
    goto v_28259;
v_28260:
    goto v_28261;
v_28262:
    {
        fn = elt(env, 2); // sort
        return (*qfn2(fn))(fn, v_28267, v_28266);
    }
}



// Code for gfquotient

static LispObject CC_gfquotient(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28283, v_28284, v_28285;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28284 = v_28257;
    v_28285 = v_28256;
// end of prologue
    v_28283 = v_28285;
    v_28283 = qcar(v_28283);
    if (!consp(v_28283)) goto v_28261;
    else goto v_28262;
v_28261:
    goto v_28270;
v_28266:
    v_28283 = v_28285;
    goto v_28267;
v_28268:
    goto v_28269;
v_28270:
    goto v_28266;
v_28267:
    goto v_28268;
v_28269:
    {
        fn = elt(env, 1); // gffquot
        return (*qfn2(fn))(fn, v_28283, v_28284);
    }
v_28262:
    goto v_28280;
v_28276:
    v_28283 = v_28285;
    goto v_28277;
v_28278:
    goto v_28279;
v_28280:
    goto v_28276;
v_28277:
    goto v_28278;
v_28279:
    {
        fn = elt(env, 2); // gbfquot
        return (*qfn2(fn))(fn, v_28283, v_28284);
    }
    v_28283 = nil;
    return onevalue(v_28283);
}



// Code for physopsubs

static LispObject CC_physopsubs(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28377, v_28378, v_28379;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28256);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_28256;
// end of prologue
// Binding alglist!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = nil; // alglist!*
    v_28377 = nil;
    v_28377 = ncons(v_28377);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_28377; // alglist!*
    v_28377 = stack[-1];
    fn = elt(env, 10); // physop2sq
    v_28377 = (*qfn1(fn))(fn, v_28377);
    env = stack[-3];
    stack[-1] = v_28377;
    v_28377 = qvalue(elt(env, 2)); // physoplist!*
    stack[0] = v_28377;
v_28270:
    v_28377 = stack[0];
    if (v_28377 == nil) goto v_28274;
    else goto v_28275;
v_28274:
    goto v_28269;
v_28275:
    v_28377 = stack[0];
    v_28377 = qcar(v_28377);
    v_28379 = v_28377;
    goto v_28286;
v_28282:
    v_28378 = v_28379;
    goto v_28283;
v_28284:
    v_28377 = elt(env, 3); // rtype
    goto v_28285;
v_28286:
    goto v_28282;
v_28283:
    goto v_28284;
v_28285:
    v_28377 = Lremprop(nil, v_28378, v_28377);
    env = stack[-3];
    goto v_28296;
v_28290:
    goto v_28291;
v_28292:
    v_28378 = elt(env, 4); // simpfn
    goto v_28293;
v_28294:
    v_28377 = elt(env, 5); // simpiden
    goto v_28295;
v_28296:
    goto v_28290;
v_28291:
    goto v_28292;
v_28293:
    goto v_28294;
v_28295:
    v_28377 = Lputprop(nil, 3, v_28379, v_28378, v_28377);
    env = stack[-3];
    v_28377 = stack[0];
    v_28377 = qcdr(v_28377);
    stack[0] = v_28377;
    goto v_28270;
v_28269:
    goto v_28307;
v_28303:
    v_28378 = elt(env, 6); // (dot)
    goto v_28304;
v_28305:
    v_28377 = elt(env, 7); // physopfn
    goto v_28306;
v_28307:
    goto v_28303;
v_28304:
    goto v_28305;
v_28306:
    v_28377 = Lremflag(nil, v_28378, v_28377);
    env = stack[-3];
    goto v_28317;
v_28311:
    v_28379 = elt(env, 8); // dot
    goto v_28312;
v_28313:
    v_28378 = elt(env, 4); // simpfn
    goto v_28314;
v_28315:
    v_28377 = elt(env, 5); // simpiden
    goto v_28316;
v_28317:
    goto v_28311;
v_28312:
    goto v_28313;
v_28314:
    goto v_28315;
v_28316:
    v_28377 = Lputprop(nil, 3, v_28379, v_28378, v_28377);
    env = stack[-3];
    v_28377 = stack[-1];
    fn = elt(env, 11); // subs2
    v_28377 = (*qfn1(fn))(fn, v_28377);
    env = stack[-3];
    stack[-1] = v_28377;
    v_28377 = stack[-1];
    fn = elt(env, 12); // !*q2a
    v_28377 = (*qfn1(fn))(fn, v_28377);
    env = stack[-3];
    stack[-1] = v_28377;
    v_28377 = qvalue(elt(env, 2)); // physoplist!*
    stack[0] = v_28377;
v_28328:
    v_28377 = stack[0];
    if (v_28377 == nil) goto v_28332;
    else goto v_28333;
v_28332:
    goto v_28327;
v_28333:
    v_28377 = stack[0];
    v_28377 = qcar(v_28377);
    v_28379 = v_28377;
    goto v_28344;
v_28340:
    v_28378 = v_28379;
    goto v_28341;
v_28342:
    v_28377 = elt(env, 4); // simpfn
    goto v_28343;
v_28344:
    goto v_28340;
v_28341:
    goto v_28342;
v_28343:
    v_28377 = Lremprop(nil, v_28378, v_28377);
    env = stack[-3];
    goto v_28354;
v_28348:
    goto v_28349;
v_28350:
    v_28378 = elt(env, 3); // rtype
    goto v_28351;
v_28352:
    v_28377 = elt(env, 9); // physop
    goto v_28353;
v_28354:
    goto v_28348;
v_28349:
    goto v_28350;
v_28351:
    goto v_28352;
v_28353:
    v_28377 = Lputprop(nil, 3, v_28379, v_28378, v_28377);
    env = stack[-3];
    v_28377 = stack[0];
    v_28377 = qcdr(v_28377);
    stack[0] = v_28377;
    goto v_28328;
v_28327:
    goto v_28365;
v_28361:
    v_28378 = elt(env, 8); // dot
    goto v_28362;
v_28363:
    v_28377 = elt(env, 4); // simpfn
    goto v_28364;
v_28365:
    goto v_28361;
v_28362:
    goto v_28363;
v_28364:
    v_28377 = Lremprop(nil, v_28378, v_28377);
    env = stack[-3];
    goto v_28373;
v_28369:
    v_28378 = elt(env, 6); // (dot)
    goto v_28370;
v_28371:
    v_28377 = elt(env, 7); // physopfn
    goto v_28372;
v_28373:
    goto v_28369;
v_28370:
    goto v_28371;
v_28372:
    v_28377 = Lflag(nil, v_28378, v_28377);
    v_28377 = stack[-1];
    ;}  // end of a binding scope
    return onevalue(v_28377);
}



// Code for free

static LispObject CC_free(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28274;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28256);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_28256;
// end of prologue
    v_28274 = stack[0];
    v_28274 = qcdr(v_28274);
    v_28274 = qcar(v_28274);
    fn = elt(env, 1); // freeind
    v_28274 = (*qfn1(fn))(fn, v_28274);
    env = stack[-1];
    if (v_28274 == nil) goto v_28260;
    else goto v_28261;
v_28260:
    v_28274 = nil;
    goto v_28259;
v_28261:
    v_28274 = stack[0];
    v_28274 = qcdr(v_28274);
    v_28274 = qcdr(v_28274);
    v_28274 = qcar(v_28274);
    {
        fn = elt(env, 1); // freeind
        return (*qfn1(fn))(fn, v_28274);
    }
    v_28274 = nil;
v_28259:
    return onevalue(v_28274);
}



// Code for expand!-imrepartpow

static LispObject CC_expandKimrepartpow(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28363, v_28364;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28256);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_28256;
// end of prologue
// Binding !*exp
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = nil; // !*exp
    v_28363 = lisp_true;
    qvalue(elt(env, 1)) = v_28363; // !*exp
    v_28363 = stack[-2];
    v_28363 = qcar(v_28363);
    if (symbolp(v_28363)) goto v_28266;
    goto v_28274;
v_28270:
    v_28363 = stack[-2];
    v_28363 = qcar(v_28363);
    v_28364 = qcar(v_28363);
    goto v_28271;
v_28272:
    v_28363 = elt(env, 2); // cmpxsplitfn
    goto v_28273;
v_28274:
    goto v_28270;
v_28271:
    goto v_28272;
v_28273:
    v_28363 = get(v_28364, v_28363);
    env = stack[-4];
    goto v_28264;
v_28266:
    v_28363 = nil;
    goto v_28264;
    v_28363 = nil;
v_28264:
    v_28364 = v_28363;
    goto v_28287;
v_28283:
    v_28363 = v_28364;
    if (v_28363 == nil) goto v_28290;
    else goto v_28291;
v_28290:
    goto v_28301;
v_28297:
    v_28363 = stack[-2];
    v_28364 = qcar(v_28363);
    goto v_28298;
v_28299:
    v_28363 = elt(env, 3); // i
    goto v_28300;
v_28301:
    goto v_28297;
v_28298:
    goto v_28299;
v_28300:
    if (v_28364 == v_28363) goto v_28295;
    else goto v_28296;
v_28295:
    goto v_28310;
v_28306:
    goto v_28317;
v_28313:
    goto v_28323;
v_28319:
    v_28364 = elt(env, 3); // i
    goto v_28320;
v_28321:
    v_28363 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28322;
v_28323:
    goto v_28319;
v_28320:
    goto v_28321;
v_28322:
    fn = elt(env, 4); // to
    v_28364 = (*qfn2(fn))(fn, v_28364, v_28363);
    env = stack[-4];
    goto v_28314;
v_28315:
    v_28363 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28316;
v_28317:
    goto v_28313;
v_28314:
    goto v_28315;
v_28316:
    v_28363 = cons(v_28364, v_28363);
    env = stack[-4];
    v_28364 = ncons(v_28363);
    env = stack[-4];
    goto v_28307;
v_28308:
    v_28363 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28309;
v_28310:
    goto v_28306;
v_28307:
    goto v_28308;
v_28309:
    v_28363 = cons(v_28364, v_28363);
    env = stack[-4];
    goto v_28294;
v_28296:
    goto v_28335;
v_28331:
    v_28363 = stack[-2];
    v_28363 = qcar(v_28363);
    fn = elt(env, 5); // mkrepart
    stack[-1] = (*qfn1(fn))(fn, v_28363);
    env = stack[-4];
    goto v_28332;
v_28333:
    goto v_28344;
v_28340:
    v_28363 = elt(env, 3); // i
    fn = elt(env, 6); // simp
    stack[0] = (*qfn1(fn))(fn, v_28363);
    env = stack[-4];
    goto v_28341;
v_28342:
    v_28363 = stack[-2];
    v_28363 = qcar(v_28363);
    fn = elt(env, 7); // mkimpart
    v_28363 = (*qfn1(fn))(fn, v_28363);
    env = stack[-4];
    goto v_28343;
v_28344:
    goto v_28340;
v_28341:
    goto v_28342;
v_28343:
    fn = elt(env, 8); // multsq
    v_28363 = (*qfn2(fn))(fn, stack[0], v_28363);
    env = stack[-4];
    goto v_28334;
v_28335:
    goto v_28331;
v_28332:
    goto v_28333;
v_28334:
    fn = elt(env, 9); // addsq
    v_28363 = (*qfn2(fn))(fn, stack[-1], v_28363);
    env = stack[-4];
    goto v_28294;
    v_28363 = nil;
v_28294:
    v_28364 = v_28363;
    goto v_28289;
v_28291:
    goto v_28357;
v_28353:
    goto v_28354;
v_28355:
    v_28363 = stack[-2];
    v_28363 = qcar(v_28363);
    goto v_28356;
v_28357:
    goto v_28353;
v_28354:
    goto v_28355;
v_28356:
    v_28363 = Lapply1(nil, v_28364, v_28363);
    env = stack[-4];
    v_28364 = v_28363;
    goto v_28289;
    v_28364 = nil;
v_28289:
    goto v_28284;
v_28285:
    v_28363 = stack[-2];
    v_28363 = qcdr(v_28363);
    goto v_28286;
v_28287:
    goto v_28283;
v_28284:
    goto v_28285;
v_28286:
    fn = elt(env, 10); // exptsq
    v_28363 = (*qfn2(fn))(fn, v_28364, v_28363);
    ;}  // end of a binding scope
    return onevalue(v_28363);
}



// Code for njets

static LispObject CC_njets(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28275, v_28276;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_28275 = v_28257;
    v_28276 = v_28256;
// end of prologue
    goto v_28264;
v_28260:
    stack[-1] = v_28275;
    goto v_28261;
v_28262:
    goto v_28271;
v_28267:
    stack[0] = v_28275;
    goto v_28268;
v_28269:
    v_28275 = v_28276;
    v_28275 = sub1(v_28275);
    env = stack[-2];
    goto v_28270;
v_28271:
    goto v_28267;
v_28268:
    goto v_28269;
v_28270:
    v_28275 = plus2(stack[0], v_28275);
    env = stack[-2];
    goto v_28263;
v_28264:
    goto v_28260;
v_28261:
    goto v_28262;
v_28263:
    {
        LispObject v_28279 = stack[-1];
        fn = elt(env, 1); // combin
        return (*qfn2(fn))(fn, v_28279, v_28275);
    }
}



// Code for bfminus

static LispObject CC_bfminus(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28269, v_28270;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28270 = v_28256;
// end of prologue
    v_28269 = v_28270;
    if (!consp(v_28269)) goto v_28260;
    else goto v_28261;
v_28260:
    v_28269 = v_28270;
    return negate(v_28269);
v_28261:
    v_28269 = v_28270;
    {
        fn = elt(env, 1); // minus!:
        return (*qfn1(fn))(fn, v_28269);
    }
    v_28269 = nil;
    return onevalue(v_28269);
}



// Code for domainp_list

static LispObject CC_domainp_list(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28289, v_28290;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28289 = v_28256;
// end of prologue
v_28255:
    v_28290 = v_28289;
    if (v_28290 == nil) goto v_28260;
    else goto v_28261;
v_28260:
    v_28289 = lisp_true;
    goto v_28259;
v_28261:
    v_28290 = v_28289;
    v_28290 = qcar(v_28290);
    if (!consp(v_28290)) goto v_28272;
    else goto v_28273;
v_28272:
    v_28290 = lisp_true;
    goto v_28271;
v_28273:
    v_28290 = v_28289;
    v_28290 = qcar(v_28290);
    v_28290 = qcar(v_28290);
    v_28290 = (consp(v_28290) ? nil : lisp_true);
    goto v_28271;
    v_28290 = nil;
v_28271:
    if (v_28290 == nil) goto v_28269;
    v_28289 = qcdr(v_28289);
    goto v_28255;
v_28269:
    v_28289 = nil;
    goto v_28267;
    v_28289 = nil;
v_28267:
    goto v_28259;
    v_28289 = nil;
v_28259:
    return onevalue(v_28289);
}



// Code for janettreeinsert

static LispObject CC_janettreeinsert(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28540, v_28541, v_28542;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28256);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_28256;
// end of prologue
    goto v_28271;
v_28267:
    v_28541 = stack[-7];
    goto v_28268;
v_28269:
    v_28540 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28270;
v_28271:
    goto v_28267;
v_28268:
    goto v_28269;
v_28270:
    v_28540 = *(LispObject *)((char *)v_28541 + (CELL-TAG_VECTOR) + (((intptr_t)v_28540-TAG_FIXNUM)/(16/CELL)));
    v_28540 = qcar(v_28540);
    stack[-3] = v_28540;
    goto v_28280;
v_28276:
    v_28541 = stack[-3];
    goto v_28277;
v_28278:
    v_28540 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28279;
v_28280:
    goto v_28276;
v_28277:
    goto v_28278;
v_28279:
    v_28540 = *(LispObject *)((char *)v_28541 + (CELL-TAG_VECTOR) + (((intptr_t)v_28540-TAG_FIXNUM)/(16/CELL)));
    stack[-6] = v_28540;
    v_28540 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_28540;
    v_28540 = qvalue(elt(env, 1)); // fluidbibasisjanettreerootnode
    if (v_28540 == nil) goto v_28287;
    else goto v_28288;
v_28287:
    goto v_28297;
v_28291:
    v_28542 = stack[-6];
    goto v_28292;
v_28293:
    v_28541 = stack[-8];
    goto v_28294;
v_28295:
    v_28540 = stack[-7];
    goto v_28296;
v_28297:
    goto v_28291;
v_28292:
    goto v_28293;
v_28294:
    goto v_28295;
v_28296:
    fn = elt(env, 2); // janettreenodebuild
    v_28540 = (*qfnn(fn))(fn, 3, v_28542, v_28541, v_28540);
    env = stack[-9];
    qvalue(elt(env, 1)) = v_28540; // fluidbibasisjanettreerootnode
    goto v_28286;
v_28288:
    v_28540 = qvalue(elt(env, 1)); // fluidbibasisjanettreerootnode
    stack[-5] = v_28540;
v_28307:
    goto v_28317;
v_28313:
    v_28541 = stack[-6];
    goto v_28314;
v_28315:
    v_28540 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28316;
v_28317:
    goto v_28313;
v_28314:
    goto v_28315;
v_28316:
    v_28540 = (LispObject)greaterp2(v_28541, v_28540);
    v_28540 = v_28540 ? lisp_true : nil;
    env = stack[-9];
    if (v_28540 == nil) goto v_28310;
    else goto v_28311;
v_28310:
    goto v_28306;
v_28311:
v_28323:
    v_28540 = stack[-5];
    if (v_28540 == nil) goto v_28326;
    goto v_28337;
v_28333:
    v_28540 = stack[-5];
    v_28540 = qcar(v_28540);
    stack[0] = qcar(v_28540);
    goto v_28334;
v_28335:
    goto v_28346;
v_28342:
    v_28541 = stack[-3];
    goto v_28343;
v_28344:
    v_28540 = stack[-8];
    goto v_28345;
v_28346:
    goto v_28342;
v_28343:
    goto v_28344;
v_28345:
    fn = elt(env, 3); // monomgetvariabledegree
    v_28540 = (*qfn2(fn))(fn, v_28541, v_28540);
    env = stack[-9];
    goto v_28336;
v_28337:
    goto v_28333;
v_28334:
    goto v_28335;
v_28336:
    v_28540 = (LispObject)lessp2(stack[0], v_28540);
    v_28540 = v_28540 ? lisp_true : nil;
    env = stack[-9];
    if (v_28540 == nil) goto v_28326;
    v_28540 = stack[-5];
    v_28540 = qcdr(v_28540);
    v_28540 = qcar(v_28540);
    if (v_28540 == nil) goto v_28326;
    goto v_28327;
v_28326:
    goto v_28322;
v_28327:
    v_28540 = stack[-5];
    v_28540 = qcdr(v_28540);
    v_28540 = qcar(v_28540);
    stack[-5] = v_28540;
    goto v_28323;
v_28322:
    v_28540 = stack[-5];
    if (v_28540 == nil) goto v_28361;
    goto v_28370;
v_28366:
    v_28540 = stack[-5];
    v_28540 = qcar(v_28540);
    stack[0] = qcar(v_28540);
    goto v_28367;
v_28368:
    goto v_28379;
v_28375:
    v_28541 = stack[-3];
    goto v_28376;
v_28377:
    v_28540 = stack[-8];
    goto v_28378;
v_28379:
    goto v_28375;
v_28376:
    goto v_28377;
v_28378:
    fn = elt(env, 3); // monomgetvariabledegree
    v_28540 = (*qfn2(fn))(fn, v_28541, v_28540);
    env = stack[-9];
    goto v_28369;
v_28370:
    goto v_28366;
v_28367:
    goto v_28368;
v_28369:
    v_28540 = (LispObject)greaterp2(stack[0], v_28540);
    v_28540 = v_28540 ? lisp_true : nil;
    env = stack[-9];
    if (v_28540 == nil) goto v_28361;
    goto v_28389;
v_28383:
    v_28542 = stack[-6];
    goto v_28384;
v_28385:
    v_28541 = stack[-8];
    goto v_28386;
v_28387:
    v_28540 = stack[-7];
    goto v_28388;
v_28389:
    goto v_28383;
v_28384:
    goto v_28385;
v_28386:
    goto v_28387;
v_28388:
    fn = elt(env, 2); // janettreenodebuild
    v_28540 = (*qfnn(fn))(fn, 3, v_28542, v_28541, v_28540);
    env = stack[-9];
    stack[-4] = v_28540;
    v_28540 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_28540;
    goto v_28399;
v_28395:
    v_28540 = stack[-5];
    stack[-2] = qcdr(v_28540);
    goto v_28396;
v_28397:
    goto v_28409;
v_28403:
    v_28540 = stack[-5];
    v_28540 = qcar(v_28540);
    stack[-1] = qcar(v_28540);
    goto v_28404;
v_28405:
    v_28540 = stack[-5];
    v_28540 = qcar(v_28540);
    stack[0] = qcdr(v_28540);
    goto v_28406;
v_28407:
    goto v_28421;
v_28417:
    v_28540 = stack[-5];
    v_28540 = qcdr(v_28540);
    v_28541 = qcar(v_28540);
    goto v_28418;
v_28419:
    v_28540 = stack[-5];
    v_28540 = qcdr(v_28540);
    v_28540 = qcdr(v_28540);
    goto v_28420;
v_28421:
    goto v_28417;
v_28418:
    goto v_28419;
v_28420:
    v_28540 = cons(v_28541, v_28540);
    env = stack[-9];
    goto v_28408;
v_28409:
    goto v_28403;
v_28404:
    goto v_28405;
v_28406:
    goto v_28407;
v_28408:
    v_28540 = acons(stack[-1], stack[0], v_28540);
    env = stack[-9];
    goto v_28398;
v_28399:
    goto v_28395;
v_28396:
    goto v_28397;
v_28398:
    fn = elt(env, 4); // setcar
    v_28540 = (*qfn2(fn))(fn, stack[-2], v_28540);
    env = stack[-9];
    goto v_28433;
v_28429:
    v_28540 = stack[-5];
    v_28541 = qcdr(v_28540);
    goto v_28430;
v_28431:
    v_28540 = stack[-4];
    v_28540 = qcdr(v_28540);
    v_28540 = qcdr(v_28540);
    goto v_28432;
v_28433:
    goto v_28429;
v_28430:
    goto v_28431;
v_28432:
    fn = elt(env, 5); // setcdr
    v_28540 = (*qfn2(fn))(fn, v_28541, v_28540);
    env = stack[-9];
    goto v_28444;
v_28440:
    v_28540 = stack[-5];
    v_28541 = qcar(v_28540);
    goto v_28441;
v_28442:
    v_28540 = stack[-4];
    v_28540 = qcar(v_28540);
    v_28540 = qcar(v_28540);
    goto v_28443;
v_28444:
    goto v_28440;
v_28441:
    goto v_28442;
v_28443:
    fn = elt(env, 4); // setcar
    v_28540 = (*qfn2(fn))(fn, v_28541, v_28540);
    env = stack[-9];
    goto v_28455;
v_28451:
    v_28540 = stack[-5];
    v_28541 = qcar(v_28540);
    goto v_28452;
v_28453:
    v_28540 = stack[-4];
    v_28540 = qcar(v_28540);
    v_28540 = qcdr(v_28540);
    goto v_28454;
v_28455:
    goto v_28451;
v_28452:
    goto v_28453;
v_28454:
    fn = elt(env, 5); // setcdr
    v_28540 = (*qfn2(fn))(fn, v_28541, v_28540);
    env = stack[-9];
    goto v_28359;
v_28361:
    v_28540 = stack[-5];
    if (v_28540 == nil) goto v_28463;
    goto v_28475;
v_28471:
    v_28540 = stack[-5];
    v_28540 = qcar(v_28540);
    stack[0] = qcar(v_28540);
    goto v_28472;
v_28473:
    goto v_28484;
v_28480:
    v_28541 = stack[-3];
    goto v_28481;
v_28482:
    v_28540 = stack[-8];
    goto v_28483;
v_28484:
    goto v_28480;
v_28481:
    goto v_28482;
v_28483:
    fn = elt(env, 3); // monomgetvariabledegree
    v_28540 = (*qfn2(fn))(fn, v_28541, v_28540);
    env = stack[-9];
    goto v_28474;
v_28475:
    goto v_28471;
v_28472:
    goto v_28473;
v_28474:
    if (equal(stack[0], v_28540)) goto v_28469;
    else goto v_28470;
v_28469:
    v_28540 = stack[-5];
    v_28540 = qcdr(v_28540);
    v_28540 = qcdr(v_28540);
    goto v_28468;
v_28470:
    v_28540 = nil;
    goto v_28468;
    v_28540 = nil;
v_28468:
    if (v_28540 == nil) goto v_28463;
    goto v_28498;
v_28494:
    stack[0] = stack[-6];
    goto v_28495;
v_28496:
    goto v_28505;
v_28501:
    v_28541 = stack[-3];
    goto v_28502;
v_28503:
    v_28540 = stack[-8];
    goto v_28504;
v_28505:
    goto v_28501;
v_28502:
    goto v_28503;
v_28504:
    fn = elt(env, 3); // monomgetvariabledegree
    v_28540 = (*qfn2(fn))(fn, v_28541, v_28540);
    env = stack[-9];
    goto v_28497;
v_28498:
    goto v_28494;
v_28495:
    goto v_28496;
v_28497:
    v_28540 = difference2(stack[0], v_28540);
    env = stack[-9];
    stack[-6] = v_28540;
    v_28540 = stack[-8];
    v_28540 = add1(v_28540);
    env = stack[-9];
    stack[-8] = v_28540;
    v_28540 = stack[-5];
    v_28540 = qcdr(v_28540);
    v_28540 = qcdr(v_28540);
    stack[-5] = v_28540;
    goto v_28359;
v_28463:
    v_28540 = stack[-5];
    if (v_28540 == nil) goto v_28515;
    goto v_28522;
v_28518:
    v_28540 = stack[-5];
    stack[0] = qcdr(v_28540);
    goto v_28519;
v_28520:
    goto v_28532;
v_28526:
    v_28542 = stack[-6];
    goto v_28527;
v_28528:
    v_28541 = stack[-8];
    goto v_28529;
v_28530:
    v_28540 = stack[-7];
    goto v_28531;
v_28532:
    goto v_28526;
v_28527:
    goto v_28528;
v_28529:
    goto v_28530;
v_28531:
    fn = elt(env, 2); // janettreenodebuild
    v_28540 = (*qfnn(fn))(fn, 3, v_28542, v_28541, v_28540);
    env = stack[-9];
    goto v_28521;
v_28522:
    goto v_28518;
v_28519:
    goto v_28520;
v_28521:
    fn = elt(env, 4); // setcar
    v_28540 = (*qfn2(fn))(fn, stack[0], v_28540);
    env = stack[-9];
    v_28540 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_28540;
    goto v_28359;
v_28515:
v_28359:
    goto v_28307;
v_28306:
    goto v_28286;
v_28286:
    v_28540 = nil;
    return onevalue(v_28540);
}



// Code for dvfsf_ppolyp

static LispObject CC_dvfsf_ppolyp(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28297, v_28298;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28256);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_28298 = v_28256;
// end of prologue
    v_28297 = v_28298;
    if (!consp(v_28297)) goto v_28267;
    else goto v_28268;
v_28267:
    v_28297 = lisp_true;
    goto v_28266;
v_28268:
    v_28297 = v_28298;
    v_28297 = qcar(v_28297);
    v_28297 = (consp(v_28297) ? nil : lisp_true);
    goto v_28266;
    v_28297 = nil;
v_28266:
    if (v_28297 == nil) goto v_28264;
    v_28297 = lisp_true;
    goto v_28260;
v_28264:
    v_28297 = v_28298;
    fn = elt(env, 2); // kernels
    v_28297 = (*qfn1(fn))(fn, v_28297);
    env = stack[0];
    v_28298 = v_28297;
    v_28297 = v_28298;
    v_28297 = qcdr(v_28297);
    if (v_28297 == nil) goto v_28281;
    else goto v_28282;
v_28281:
    goto v_28289;
v_28285:
    v_28297 = v_28298;
    v_28297 = qcar(v_28297);
    goto v_28286;
v_28287:
    v_28298 = elt(env, 1); // p
    goto v_28288;
v_28289:
    goto v_28285;
v_28286:
    goto v_28287;
v_28288:
    v_28297 = (v_28297 == v_28298 ? lisp_true : nil);
    goto v_28280;
v_28282:
    v_28297 = nil;
    goto v_28280;
    v_28297 = nil;
v_28280:
v_28260:
    return onevalue(v_28297);
}



// Code for spinnerprod

static LispObject CC_spinnerprod(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28392, v_28393, v_28394, v_28395;
    LispObject v_28261, v_28260, v_28259, v_28258, v_28257, v_28256;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "spinnerprod");
    va_start(aa, nargs);
    v_28256 = va_arg(aa, LispObject);
    v_28257 = va_arg(aa, LispObject);
    v_28258 = va_arg(aa, LispObject);
    v_28259 = va_arg(aa, LispObject);
    v_28260 = va_arg(aa, LispObject);
    v_28261 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_28261,v_28260,v_28259,v_28258,v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_28256,v_28257,v_28258,v_28259,v_28260,v_28261);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_28261;
    v_28392 = v_28260;
    v_28393 = v_28259;
    stack[-5] = v_28258;
    v_28394 = v_28257;
    v_28395 = v_28256;
// end of prologue
    stack[-6] = v_28393;
    v_28393 = stack[-6];
    stack[-3] = v_28393;
    v_28392 = qcdr(v_28392);
    stack[-1] = v_28392;
v_28275:
    v_28392 = stack[-1];
    if (v_28392 == nil) goto v_28280;
    else goto v_28281;
v_28280:
    goto v_28274;
v_28281:
    v_28392 = stack[-1];
    v_28392 = qcar(v_28392);
    v_28393 = v_28392;
    v_28392 = v_28393;
    v_28392 = qcar(v_28392);
    stack[-7] = v_28392;
    v_28392 = stack[-7];
    if (v_28392 == nil) goto v_28291;
    else goto v_28292;
v_28291:
    v_28392 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_28392;
    goto v_28290;
v_28292:
v_28290:
    v_28392 = v_28393;
    v_28392 = qcdr(v_28392);
    stack[-2] = v_28392;
    v_28392 = stack[-2];
    if (v_28392 == nil) goto v_28303;
    else goto v_28304;
v_28303:
    v_28392 = lisp_true;
    goto v_28302;
v_28304:
    goto v_28313;
v_28309:
    stack[0] = stack[-2];
    goto v_28310;
v_28311:
    v_28392 = nil;
    v_28392 = ncons(v_28392);
    env = stack[-8];
    goto v_28312;
v_28313:
    goto v_28309;
v_28310:
    goto v_28311;
v_28312:
    v_28392 = (equal(stack[0], v_28392) ? lisp_true : nil);
    goto v_28302;
    v_28392 = nil;
v_28302:
    if (v_28392 == nil) goto v_28300;
    v_28392 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_28392;
    goto v_28298;
v_28300:
v_28298:
    goto v_28328;
v_28324:
    v_28393 = stack[-7];
    goto v_28325;
v_28326:
    v_28392 = stack[-5];
    goto v_28327;
v_28328:
    goto v_28324;
v_28325:
    goto v_28326;
v_28327:
    v_28392 = (LispObject)lesseq2(v_28393, v_28392);
    v_28392 = v_28392 ? lisp_true : nil;
    env = stack[-8];
    if (v_28392 == nil) goto v_28322;
    goto v_28335;
v_28331:
    v_28393 = stack[-7];
    goto v_28332;
v_28333:
    v_28392 = stack[-4];
    goto v_28334;
v_28335:
    goto v_28331;
v_28332:
    goto v_28333;
v_28334:
    v_28392 = Latsoc(nil, v_28393, v_28392);
    stack[-7] = v_28392;
    v_28392 = stack[-7];
    if (v_28392 == nil) goto v_28345;
    else goto v_28346;
v_28345:
    v_28392 = lisp_true;
    goto v_28344;
v_28346:
    goto v_28355;
v_28351:
    stack[0] = stack[-7];
    goto v_28352;
v_28353:
    v_28392 = nil;
    v_28392 = ncons(v_28392);
    env = stack[-8];
    goto v_28354;
v_28355:
    goto v_28351;
v_28352:
    goto v_28353;
v_28354:
    v_28392 = (equal(stack[0], v_28392) ? lisp_true : nil);
    goto v_28344;
    v_28392 = nil;
v_28344:
    if (v_28392 == nil) goto v_28342;
    goto v_28340;
v_28342:
    goto v_28370;
v_28364:
    stack[0] = elt(env, 1); // plus
    goto v_28365;
v_28366:
    stack[-3] = stack[-6];
    goto v_28367;
v_28368:
    goto v_28380;
v_28374:
    v_28394 = elt(env, 2); // times
    goto v_28375;
v_28376:
    v_28393 = stack[-2];
    goto v_28377;
v_28378:
    v_28392 = stack[-7];
    v_28392 = qcdr(v_28392);
    goto v_28379;
v_28380:
    goto v_28374;
v_28375:
    goto v_28376;
v_28377:
    goto v_28378;
v_28379:
    v_28392 = list3(v_28394, v_28393, v_28392);
    env = stack[-8];
    goto v_28369;
v_28370:
    goto v_28364;
v_28365:
    goto v_28366;
v_28367:
    goto v_28368;
v_28369:
    v_28392 = list3(stack[0], stack[-3], v_28392);
    env = stack[-8];
    stack[-6] = v_28392;
    v_28392 = stack[-6];
    stack[-3] = v_28392;
    goto v_28340;
v_28340:
    goto v_28320;
v_28322:
v_28320:
    v_28392 = stack[-1];
    v_28392 = qcdr(v_28392);
    stack[-1] = v_28392;
    goto v_28275;
v_28274:
    v_28392 = stack[-3];
    return onevalue(v_28392);
}



// Code for safe!-fp!-quot

static LispObject CC_safeKfpKquot(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28347, v_28348, v_28349;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_28349 = v_28257;
    stack[0] = v_28256;
// end of prologue
    goto v_28270;
v_28266:
    v_28348 = v_28349;
    goto v_28267;
v_28268:
    v_28347 = elt(env, 1); // 0.0
    goto v_28269;
v_28270:
    goto v_28266;
v_28267:
    goto v_28268;
v_28269:
    if (equal(v_28348, v_28347)) goto v_28264;
    else goto v_28265;
v_28264:
    v_28347 = nil;
    goto v_28261;
v_28265:
    v_28347 = qvalue(elt(env, 2)); // !*nonegzerotimes
    if (v_28347 == nil) goto v_28275;
    goto v_28283;
v_28279:
    v_28348 = stack[0];
    goto v_28280;
v_28281:
    v_28347 = elt(env, 1); // 0.0
    goto v_28282;
v_28283:
    goto v_28279;
v_28280:
    goto v_28281;
v_28282:
    if (equal(v_28348, v_28347)) goto v_28278;
    else goto v_28275;
v_28278:
    v_28347 = elt(env, 1); // 0.0
    goto v_28261;
v_28275:
    goto v_28292;
v_28288:
    v_28347 = stack[0];
    goto v_28289;
v_28290:
    v_28348 = v_28349;
    goto v_28291;
v_28292:
    goto v_28288;
v_28289:
    goto v_28290;
v_28291:
    v_28347 = quot2(v_28347, v_28348);
    env = stack[-2];
    stack[-1] = v_28347;
    goto v_28305;
v_28301:
    v_28348 = stack[-1];
    goto v_28302;
v_28303:
    v_28347 = qvalue(elt(env, 3)); // !!minnorm
    goto v_28304;
v_28305:
    goto v_28301;
v_28302:
    goto v_28303;
v_28304:
    v_28347 = (LispObject)lessp2(v_28348, v_28347);
    v_28347 = v_28347 ? lisp_true : nil;
    env = stack[-2];
    if (v_28347 == nil) goto v_28298;
    goto v_28315;
v_28311:
    v_28348 = stack[-1];
    goto v_28312;
v_28313:
    v_28347 = qvalue(elt(env, 4)); // !!minnegnorm
    goto v_28314;
v_28315:
    goto v_28311;
v_28312:
    goto v_28313;
v_28314:
    v_28347 = (LispObject)greaterp2(v_28348, v_28347);
    v_28347 = v_28347 ? lisp_true : nil;
    env = stack[-2];
    if (v_28347 == nil) goto v_28298;
    goto v_28323;
v_28319:
    v_28348 = stack[0];
    goto v_28320;
v_28321:
    v_28347 = elt(env, 1); // 0.0
    goto v_28322;
v_28323:
    goto v_28319;
v_28320:
    goto v_28321;
v_28322:
    if (equal(v_28348, v_28347)) goto v_28298;
    v_28347 = nil;
    goto v_28261;
v_28298:
    goto v_28333;
v_28329:
    goto v_28339;
v_28335:
    v_28348 = stack[-1];
    goto v_28336;
v_28337:
    v_28347 = stack[-1];
    goto v_28338;
v_28339:
    goto v_28335;
v_28336:
    goto v_28337;
v_28338:
    v_28347 = difference2(v_28348, v_28347);
    env = stack[-2];
    goto v_28330;
v_28331:
    v_28348 = elt(env, 1); // 0.0
    goto v_28332;
v_28333:
    goto v_28329;
v_28330:
    goto v_28331;
v_28332:
    if (equal(v_28347, v_28348)) goto v_28327;
    else goto v_28328;
v_28327:
    v_28347 = stack[-1];
    goto v_28261;
v_28328:
    v_28347 = nil;
    goto v_28261;
    v_28347 = nil;
v_28261:
    return onevalue(v_28347);
}



// Code for f2dip

static LispObject CC_f2dip(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28270;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28256);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_28270 = v_28256;
// end of prologue
    goto v_28265;
v_28259:
    stack[-1] = v_28270;
    goto v_28260;
v_28261:
    fn = elt(env, 1); // evzero
    stack[0] = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_28262;
v_28263:
    v_28270 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 2); // bcfd
    v_28270 = (*qfn1(fn))(fn, v_28270);
    env = stack[-2];
    goto v_28264;
v_28265:
    goto v_28259;
v_28260:
    goto v_28261;
v_28262:
    goto v_28263;
v_28264:
    {
        LispObject v_28273 = stack[-1];
        LispObject v_28274 = stack[0];
        fn = elt(env, 3); // f2dip1
        return (*qfnn(fn))(fn, 3, v_28273, v_28274, v_28270);
    }
}



// Code for reset_opnums

static LispObject CC_reset_opnums(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28324, v_28325, v_28326;
    LispObject fn;
    argcheck(nargs, 0, "reset_opnums");
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
    v_28324 = qvalue(elt(env, 1)); // oporder!*
    stack[-4] = v_28324;
    v_28324 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_28324;
v_28264:
    v_28324 = stack[-4];
    if (v_28324 == nil) goto v_28269;
    else goto v_28270;
v_28269:
    v_28324 = nil;
    goto v_28263;
v_28270:
    v_28324 = stack[-4];
    v_28324 = qcar(v_28324);
    v_28325 = v_28324;
    v_28324 = stack[-4];
    v_28324 = qcdr(v_28324);
    stack[-4] = v_28324;
    v_28324 = v_28325;
    if (symbolp(v_28324)) goto v_28279;
    else goto v_28280;
v_28279:
    v_28324 = v_28325;
    stack[-2] = v_28324;
    v_28324 = nil;
    goto v_28278;
v_28280:
    v_28324 = v_28325;
    v_28324 = qcar(v_28324);
    stack[-2] = v_28324;
    v_28324 = v_28325;
    v_28324 = qcdr(v_28324);
    goto v_28278;
v_28278:
    goto v_28297;
v_28291:
    stack[-1] = stack[-2];
    goto v_28292;
v_28293:
    stack[0] = elt(env, 2); // opnum
    goto v_28294;
v_28295:
    goto v_28305;
v_28301:
    goto v_28311;
v_28307:
    v_28325 = v_28324;
    goto v_28308;
v_28309:
    v_28324 = stack[-3];
    goto v_28310;
v_28311:
    goto v_28307;
v_28308:
    goto v_28309;
v_28310:
    v_28326 = cons(v_28325, v_28324);
    env = stack[-5];
    goto v_28302;
v_28303:
    goto v_28319;
v_28315:
    v_28325 = stack[-2];
    goto v_28316;
v_28317:
    v_28324 = elt(env, 2); // opnum
    goto v_28318;
v_28319:
    goto v_28315;
v_28316:
    goto v_28317;
v_28318:
    v_28324 = get(v_28325, v_28324);
    env = stack[-5];
    goto v_28304;
v_28305:
    goto v_28301;
v_28302:
    goto v_28303;
v_28304:
    fn = elt(env, 3); // !*xadd
    v_28324 = (*qfn2(fn))(fn, v_28326, v_28324);
    env = stack[-5];
    goto v_28296;
v_28297:
    goto v_28291;
v_28292:
    goto v_28293;
v_28294:
    goto v_28295;
v_28296:
    v_28324 = Lputprop(nil, 3, stack[-1], stack[0], v_28324);
    env = stack[-5];
    v_28324 = stack[-3];
    v_28324 = add1(v_28324);
    env = stack[-5];
    stack[-3] = v_28324;
    goto v_28264;
v_28263:
    return onevalue(v_28324);
}



// Code for delete_edge

static LispObject CC_delete_edge(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28304, v_28305, v_28306;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28257;
    stack[-1] = v_28256;
// end of prologue
    v_28306 = nil;
v_28262:
    v_28304 = stack[0];
    if (v_28304 == nil) goto v_28265;
    else goto v_28266;
v_28265:
    v_28304 = v_28306;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_28304);
    }
v_28266:
    goto v_28276;
v_28272:
    v_28304 = stack[-1];
    v_28305 = qcar(v_28304);
    goto v_28273;
v_28274:
    v_28304 = stack[0];
    v_28304 = qcar(v_28304);
    v_28304 = qcar(v_28304);
    goto v_28275;
v_28276:
    goto v_28272;
v_28273:
    goto v_28274;
v_28275:
    if (v_28305 == v_28304) goto v_28270;
    else goto v_28271;
v_28270:
    goto v_28287;
v_28283:
    v_28305 = v_28306;
    goto v_28284;
v_28285:
    v_28304 = stack[0];
    v_28304 = qcdr(v_28304);
    goto v_28286;
v_28287:
    goto v_28283;
v_28284:
    goto v_28285;
v_28286:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_28305, v_28304);
    }
v_28271:
    goto v_28298;
v_28294:
    v_28304 = stack[0];
    v_28304 = qcar(v_28304);
    goto v_28295;
v_28296:
    v_28305 = v_28306;
    goto v_28297;
v_28298:
    goto v_28294;
v_28295:
    goto v_28296;
v_28297:
    v_28304 = cons(v_28304, v_28305);
    env = stack[-2];
    v_28306 = v_28304;
    v_28304 = stack[0];
    v_28304 = qcdr(v_28304);
    stack[0] = v_28304;
    goto v_28262;
    v_28304 = nil;
    return onevalue(v_28304);
}



// Code for reduce!-ratios

static LispObject CC_reduceKratios(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28324, v_28325;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_28257;
    stack[-2] = v_28256;
// end of prologue
v_28255:
    goto v_28271;
v_28267:
    v_28325 = stack[-2];
    goto v_28268;
v_28269:
    v_28324 = stack[-1];
    goto v_28270;
v_28271:
    goto v_28267;
v_28268:
    goto v_28269;
v_28270:
    fn = elt(env, 1); // red!-ratios1
    v_28324 = (*qfn2(fn))(fn, v_28325, v_28324);
    env = stack[-4];
    stack[-3] = v_28324;
    if (v_28324 == nil) goto v_28264;
    else goto v_28265;
v_28264:
    v_28324 = stack[-2];
    goto v_28261;
v_28265:
    goto v_28280;
v_28276:
    goto v_28286;
v_28282:
    v_28324 = stack[-3];
    v_28325 = qcar(v_28324);
    goto v_28283;
v_28284:
    v_28324 = stack[-2];
    goto v_28285;
v_28286:
    goto v_28282;
v_28283:
    goto v_28284;
v_28285:
    fn = elt(env, 2); // mv!-domainlist!-!*
    stack[0] = (*qfn2(fn))(fn, v_28325, v_28324);
    env = stack[-4];
    goto v_28277;
v_28278:
    goto v_28295;
v_28291:
    v_28324 = stack[-3];
    v_28325 = qcdr(v_28324);
    goto v_28292;
v_28293:
    v_28324 = stack[-1];
    goto v_28294;
v_28295:
    goto v_28291;
v_28292:
    goto v_28293;
v_28294:
    fn = elt(env, 2); // mv!-domainlist!-!*
    v_28324 = (*qfn2(fn))(fn, v_28325, v_28324);
    env = stack[-4];
    goto v_28279;
v_28280:
    goto v_28276;
v_28277:
    goto v_28278;
v_28279:
    fn = elt(env, 3); // mv!-domainlist!-!-
    v_28324 = (*qfn2(fn))(fn, stack[0], v_28324);
    env = stack[-4];
    stack[-3] = v_28324;
    goto v_28308;
v_28304:
    v_28324 = stack[-2];
    fn = elt(env, 4); // reddom_zeros
    stack[0] = (*qfn1(fn))(fn, v_28324);
    env = stack[-4];
    goto v_28305;
v_28306:
    v_28324 = stack[-3];
    fn = elt(env, 4); // reddom_zeros
    v_28324 = (*qfn1(fn))(fn, v_28324);
    env = stack[-4];
    goto v_28307;
v_28308:
    goto v_28304;
v_28305:
    goto v_28306;
v_28307:
    v_28324 = (LispObject)geq2(stack[0], v_28324);
    v_28324 = v_28324 ? lisp_true : nil;
    env = stack[-4];
    if (v_28324 == nil) goto v_28302;
    v_28324 = stack[-2];
    goto v_28300;
v_28302:
    goto v_28321;
v_28317:
    v_28325 = stack[-3];
    goto v_28318;
v_28319:
    v_28324 = stack[-1];
    goto v_28320;
v_28321:
    goto v_28317;
v_28318:
    goto v_28319;
v_28320:
    stack[-2] = v_28325;
    stack[-1] = v_28324;
    goto v_28255;
    v_28324 = nil;
v_28300:
v_28261:
    return onevalue(v_28324);
}



// Code for fs!:subang

static LispObject CC_fsTsubang(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28441, v_28442, v_28443, v_28444;
    LispObject fn;
    LispObject v_28258, v_28257, v_28256;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "fs:subang");
    va_start(aa, nargs);
    v_28256 = va_arg(aa, LispObject);
    v_28257 = va_arg(aa, LispObject);
    v_28258 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_28258,v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_28256,v_28257,v_28258);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-5] = v_28258;
    stack[-6] = v_28257;
    stack[-7] = v_28256;
// end of prologue
    v_28441 = stack[-7];
    if (v_28441 == nil) goto v_28262;
    else goto v_28263;
v_28262:
    v_28441 = nil;
    goto v_28261;
v_28263:
    v_28441 = (LispObject)112+TAG_FIXNUM; // 7
    v_28441 = Lmkvect(nil, v_28441);
    env = stack[-9];
    stack[-8] = v_28441;
    goto v_28278;
v_28274:
    goto v_28283;
v_28279:
    v_28442 = stack[-7];
    goto v_28280;
v_28281:
    v_28441 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_28282;
v_28283:
    goto v_28279;
v_28280:
    goto v_28281;
v_28282:
    v_28442 = *(LispObject *)((char *)v_28442 + (CELL-TAG_VECTOR) + (((intptr_t)v_28441-TAG_FIXNUM)/(16/CELL)));
    goto v_28275;
v_28276:
    v_28441 = stack[-6];
    goto v_28277;
v_28278:
    goto v_28274;
v_28275:
    goto v_28276;
v_28277:
    v_28441 = *(LispObject *)((char *)v_28442 + (CELL-TAG_VECTOR) + (((intptr_t)v_28441-TAG_FIXNUM)/(16/CELL)));
    stack[-4] = v_28441;
    v_28441 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_28441;
v_28292:
    goto v_28304;
v_28300:
    v_28442 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_28301;
v_28302:
    v_28441 = stack[-3];
    goto v_28303;
v_28304:
    goto v_28300;
v_28301:
    goto v_28302;
v_28303:
    v_28441 = difference2(v_28442, v_28441);
    env = stack[-9];
    v_28441 = Lminusp(nil, v_28441);
    env = stack[-9];
    if (v_28441 == nil) goto v_28297;
    goto v_28291;
v_28297:
    goto v_28316;
v_28312:
    v_28442 = stack[-3];
    goto v_28313;
v_28314:
    v_28441 = stack[-6];
    goto v_28315;
v_28316:
    goto v_28312;
v_28313:
    goto v_28314;
v_28315:
    if (equal(v_28442, v_28441)) goto v_28310;
    else goto v_28311;
v_28310:
    goto v_28325;
v_28319:
    stack[-1] = stack[-8];
    goto v_28320;
v_28321:
    stack[0] = stack[-3];
    goto v_28322;
v_28323:
    goto v_28333;
v_28329:
    v_28443 = stack[-4];
    goto v_28330;
v_28331:
    goto v_28339;
v_28335:
    v_28442 = stack[-5];
    goto v_28336;
v_28337:
    v_28441 = stack[-3];
    goto v_28338;
v_28339:
    goto v_28335;
v_28336:
    goto v_28337;
v_28338:
    v_28441 = *(LispObject *)((char *)v_28442 + (CELL-TAG_VECTOR) + (((intptr_t)v_28441-TAG_FIXNUM)/(16/CELL)));
    goto v_28332;
v_28333:
    goto v_28329;
v_28330:
    goto v_28331;
v_28332:
    v_28441 = times2(v_28443, v_28441);
    env = stack[-9];
    goto v_28324;
v_28325:
    goto v_28319;
v_28320:
    goto v_28321;
v_28322:
    goto v_28323;
v_28324:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_28441;
    goto v_28309;
v_28311:
    goto v_28351;
v_28345:
    stack[-2] = stack[-8];
    goto v_28346;
v_28347:
    stack[-1] = stack[-3];
    goto v_28348;
v_28349:
    goto v_28359;
v_28355:
    goto v_28364;
v_28360:
    goto v_28369;
v_28365:
    v_28442 = stack[-7];
    goto v_28366;
v_28367:
    v_28441 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_28368;
v_28369:
    goto v_28365;
v_28366:
    goto v_28367;
v_28368:
    v_28442 = *(LispObject *)((char *)v_28442 + (CELL-TAG_VECTOR) + (((intptr_t)v_28441-TAG_FIXNUM)/(16/CELL)));
    goto v_28361;
v_28362:
    v_28441 = stack[-3];
    goto v_28363;
v_28364:
    goto v_28360;
v_28361:
    goto v_28362;
v_28363:
    stack[0] = *(LispObject *)((char *)v_28442 + (CELL-TAG_VECTOR) + (((intptr_t)v_28441-TAG_FIXNUM)/(16/CELL)));
    goto v_28356;
v_28357:
    goto v_28380;
v_28376:
    v_28443 = stack[-4];
    goto v_28377;
v_28378:
    goto v_28386;
v_28382:
    v_28442 = stack[-5];
    goto v_28383;
v_28384:
    v_28441 = stack[-3];
    goto v_28385;
v_28386:
    goto v_28382;
v_28383:
    goto v_28384;
v_28385:
    v_28441 = *(LispObject *)((char *)v_28442 + (CELL-TAG_VECTOR) + (((intptr_t)v_28441-TAG_FIXNUM)/(16/CELL)));
    goto v_28379;
v_28380:
    goto v_28376;
v_28377:
    goto v_28378;
v_28379:
    v_28441 = times2(v_28443, v_28441);
    env = stack[-9];
    goto v_28358;
v_28359:
    goto v_28355;
v_28356:
    goto v_28357;
v_28358:
    v_28441 = plus2(stack[0], v_28441);
    env = stack[-9];
    goto v_28350;
v_28351:
    goto v_28345;
v_28346:
    goto v_28347;
v_28348:
    goto v_28349;
v_28350:
    *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-1]-TAG_FIXNUM)/(16/CELL))) = v_28441;
    goto v_28309;
v_28309:
    v_28441 = stack[-3];
    v_28441 = add1(v_28441);
    env = stack[-9];
    stack[-3] = v_28441;
    goto v_28292;
v_28291:
    goto v_28397;
v_28393:
    goto v_28405;
v_28399:
    goto v_28410;
v_28406:
    v_28442 = stack[-7];
    goto v_28407;
v_28408:
    v_28441 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_28409;
v_28410:
    goto v_28406;
v_28407:
    goto v_28408;
v_28409:
    v_28443 = *(LispObject *)((char *)v_28442 + (CELL-TAG_VECTOR) + (((intptr_t)v_28441-TAG_FIXNUM)/(16/CELL)));
    goto v_28400;
v_28401:
    v_28442 = stack[-6];
    goto v_28402;
v_28403:
    v_28441 = stack[-5];
    goto v_28404;
v_28405:
    goto v_28399;
v_28400:
    goto v_28401;
v_28402:
    goto v_28403;
v_28404:
    stack[0] = CC_fsTsubang(elt(env, 0), 3, v_28443, v_28442, v_28441);
    env = stack[-9];
    goto v_28394;
v_28395:
    goto v_28423;
v_28417:
    goto v_28428;
v_28424:
    v_28442 = stack[-7];
    goto v_28425;
v_28426:
    v_28441 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28427;
v_28428:
    goto v_28424;
v_28425:
    goto v_28426;
v_28427:
    v_28444 = *(LispObject *)((char *)v_28442 + (CELL-TAG_VECTOR) + (((intptr_t)v_28441-TAG_FIXNUM)/(16/CELL)));
    goto v_28418;
v_28419:
    v_28443 = stack[-8];
    goto v_28420;
v_28421:
    goto v_28437;
v_28433:
    v_28442 = stack[-7];
    goto v_28434;
v_28435:
    v_28441 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_28436;
v_28437:
    goto v_28433;
v_28434:
    goto v_28435;
v_28436:
    v_28441 = *(LispObject *)((char *)v_28442 + (CELL-TAG_VECTOR) + (((intptr_t)v_28441-TAG_FIXNUM)/(16/CELL)));
    goto v_28422;
v_28423:
    goto v_28417;
v_28418:
    goto v_28419;
v_28420:
    goto v_28421;
v_28422:
    fn = elt(env, 1); // make!-term
    v_28441 = (*qfnn(fn))(fn, 3, v_28444, v_28443, v_28441);
    env = stack[-9];
    goto v_28396;
v_28397:
    goto v_28393;
v_28394:
    goto v_28395;
v_28396:
    {
        LispObject v_28454 = stack[0];
        fn = elt(env, 2); // fs!:plus
        return (*qfn2(fn))(fn, v_28454, v_28441);
    }
    goto v_28261;
    v_28441 = nil;
v_28261:
    return onevalue(v_28441);
}



// Code for addnew

static LispObject CC_addnew(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_28304, v_28305, v_28306, v_28307, v_28308;
    LispObject fn;
    LispObject v_28258, v_28257, v_28256;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "addnew");
    va_start(aa, nargs);
    v_28256 = va_arg(aa, LispObject);
    v_28257 = va_arg(aa, LispObject);
    v_28258 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_28258,v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_28256,v_28257,v_28258);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28258;
    v_28307 = v_28257;
    v_28308 = v_28256;
// end of prologue
    goto v_28266;
v_28260:
    v_28306 = qvalue(elt(env, 1)); // gv!*
    goto v_28261;
v_28262:
    v_28305 = v_28307;
    goto v_28263;
v_28264:
    v_28304 = v_28308;
    goto v_28265;
v_28266:
    goto v_28260;
v_28261:
    goto v_28262;
v_28263:
    goto v_28264;
v_28265:
    *(LispObject *)((char *)v_28306 + (CELL-TAG_VECTOR) + (((intptr_t)v_28305-TAG_FIXNUM)/(16/CELL))) = v_28304;
    goto v_28276;
v_28270:
    v_28306 = qvalue(elt(env, 2)); // bv!*
    goto v_28271;
v_28272:
    v_28305 = v_28307;
    goto v_28273;
v_28274:
    v_28304 = lisp_true;
    goto v_28275;
v_28276:
    goto v_28270;
v_28271:
    goto v_28272;
v_28273:
    goto v_28274;
v_28275:
    *(LispObject *)((char *)v_28306 + (CELL-TAG_VECTOR) + (((intptr_t)v_28305-TAG_FIXNUM)/(16/CELL))) = v_28304;
    v_28304 = v_28308;
    if (v_28304 == nil) goto v_28282;
    else goto v_28283;
v_28282:
    v_28304 = stack[0];
    goto v_28281;
v_28283:
    goto v_28293;
v_28289:
    goto v_28299;
v_28295:
    stack[-1] = v_28307;
    goto v_28296;
v_28297:
    v_28304 = v_28308;
    fn = elt(env, 3); // ljet
    v_28304 = (*qfn1(fn))(fn, v_28304);
    env = stack[-2];
    goto v_28298;
v_28299:
    goto v_28295;
v_28296:
    goto v_28297;
v_28298:
    v_28305 = cons(stack[-1], v_28304);
    env = stack[-2];
    goto v_28290;
v_28291:
    v_28304 = stack[0];
    goto v_28292;
v_28293:
    goto v_28289;
v_28290:
    goto v_28291;
v_28292:
    fn = elt(env, 4); // insert
    v_28304 = (*qfn2(fn))(fn, v_28305, v_28304);
    goto v_28281;
    v_28304 = nil;
v_28281:
    return onevalue(v_28304);
}



// Code for flattens1

static LispObject CC_flattens1(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28288;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28256);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28256;
// end of prologue
v_28260:
    v_28288 = stack[0];
    if (!consp(v_28288)) goto v_28263;
    else goto v_28264;
v_28263:
    v_28288 = stack[0];
    return ncons(v_28288);
v_28264:
    v_28288 = stack[0];
    v_28288 = qcdr(v_28288);
    if (v_28288 == nil) goto v_28269;
    goto v_28277;
v_28273:
    v_28288 = stack[0];
    v_28288 = qcar(v_28288);
    stack[-1] = CC_flattens1(elt(env, 0), v_28288);
    env = stack[-2];
    goto v_28274;
v_28275:
    v_28288 = stack[0];
    v_28288 = qcdr(v_28288);
    v_28288 = CC_flattens1(elt(env, 0), v_28288);
    goto v_28276;
v_28277:
    goto v_28273;
v_28274:
    goto v_28275;
v_28276:
    {
        LispObject v_28291 = stack[-1];
        return Lappend(nil, v_28291, v_28288);
    }
v_28269:
    v_28288 = stack[0];
    v_28288 = qcar(v_28288);
    stack[0] = v_28288;
    goto v_28260;
    v_28288 = nil;
    return onevalue(v_28288);
}



// Code for pst_mkpst

static LispObject CC_pst_mkpst(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28268;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_28256);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_28268 = v_28256;
// end of prologue
    goto v_28264;
v_28260:
    stack[0] = nil;
    goto v_28261;
v_28262:
    fn = elt(env, 1); // pst_mkpst1
    v_28268 = (*qfn1(fn))(fn, v_28268);
    env = stack[-1];
    goto v_28263;
v_28264:
    goto v_28260;
v_28261:
    goto v_28262;
v_28263:
    v_28268 = cons(stack[0], v_28268);
    env = stack[-1];
    {
        fn = elt(env, 2); // pst_equitable
        return (*qfn1(fn))(fn, v_28268);
    }
}



// Code for taylorp

static LispObject CC_taylorp(LispObject env,
                         LispObject v_28256)
{
    env = qenv(env);
    LispObject v_28266, v_28267;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_28266 = v_28256;
// end of prologue
    goto v_28263;
v_28259:
    goto v_28260;
v_28261:
    v_28267 = elt(env, 1); // taylor
    goto v_28262;
v_28263:
    goto v_28259;
v_28260:
    goto v_28261;
v_28262:
        return Leqcar(nil, v_28266, v_28267);
}



// Code for nonlnr

static LispObject CC_nonlnr(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28370, v_28371;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_28257;
    stack[-1] = v_28256;
// end of prologue
v_28255:
    v_28370 = stack[-1];
    if (!consp(v_28370)) goto v_28265;
    else goto v_28266;
v_28265:
    v_28370 = lisp_true;
    goto v_28264;
v_28266:
    v_28370 = stack[-1];
    v_28370 = qcar(v_28370);
    v_28370 = (consp(v_28370) ? nil : lisp_true);
    goto v_28264;
    v_28370 = nil;
v_28264:
    if (v_28370 == nil) goto v_28262;
    v_28370 = nil;
    goto v_28260;
v_28262:
    goto v_28281;
v_28277:
    v_28370 = stack[-1];
    v_28370 = qcar(v_28370);
    v_28370 = qcar(v_28370);
    v_28371 = qcar(v_28370);
    goto v_28278;
v_28279:
    v_28370 = stack[0];
    goto v_28280;
v_28281:
    goto v_28277;
v_28278:
    goto v_28279;
v_28280:
    v_28370 = Lmember(nil, v_28371, v_28370);
    if (v_28370 == nil) goto v_28276;
    goto v_28296;
v_28292:
    v_28370 = stack[-1];
    v_28370 = qcar(v_28370);
    v_28370 = qcar(v_28370);
    v_28371 = qcdr(v_28370);
    goto v_28293;
v_28294:
    v_28370 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_28295;
v_28296:
    goto v_28292;
v_28293:
    goto v_28294;
v_28295:
    v_28370 = (LispObject)greaterp2(v_28371, v_28370);
    v_28370 = v_28370 ? lisp_true : nil;
    env = stack[-2];
    if (v_28370 == nil) goto v_28290;
    else goto v_28289;
v_28290:
    goto v_28311;
v_28307:
    v_28370 = stack[-1];
    v_28370 = qcar(v_28370);
    v_28371 = qcdr(v_28370);
    goto v_28308;
v_28309:
    v_28370 = stack[0];
    goto v_28310;
v_28311:
    goto v_28307;
v_28308:
    goto v_28309;
v_28310:
    fn = elt(env, 1); // freeofl
    v_28370 = (*qfn2(fn))(fn, v_28371, v_28370);
    env = stack[-2];
    if (v_28370 == nil) goto v_28304;
    else goto v_28305;
v_28304:
    v_28370 = lisp_true;
    goto v_28303;
v_28305:
    goto v_28324;
v_28320:
    v_28370 = stack[-1];
    v_28371 = qcdr(v_28370);
    goto v_28321;
v_28322:
    v_28370 = stack[0];
    goto v_28323;
v_28324:
    goto v_28320;
v_28321:
    goto v_28322;
v_28323:
    stack[-1] = v_28371;
    stack[0] = v_28370;
    goto v_28255;
    v_28370 = nil;
v_28303:
v_28289:
    goto v_28260;
v_28276:
    goto v_28339;
v_28335:
    v_28370 = stack[-1];
    v_28370 = qcar(v_28370);
    v_28370 = qcar(v_28370);
    v_28371 = qcar(v_28370);
    goto v_28336;
v_28337:
    v_28370 = stack[0];
    goto v_28338;
v_28339:
    goto v_28335;
v_28336:
    goto v_28337;
v_28338:
    fn = elt(env, 1); // freeofl
    v_28370 = (*qfn2(fn))(fn, v_28371, v_28370);
    env = stack[-2];
    if (v_28370 == nil) goto v_28332;
    else goto v_28333;
v_28332:
    v_28370 = lisp_true;
    goto v_28331;
v_28333:
    goto v_28356;
v_28352:
    v_28370 = stack[-1];
    v_28370 = qcar(v_28370);
    v_28371 = qcdr(v_28370);
    goto v_28353;
v_28354:
    v_28370 = stack[0];
    goto v_28355;
v_28356:
    goto v_28352;
v_28353:
    goto v_28354;
v_28355:
    v_28370 = CC_nonlnr(elt(env, 0), v_28371, v_28370);
    env = stack[-2];
    if (v_28370 == nil) goto v_28350;
    else goto v_28349;
v_28350:
    goto v_28366;
v_28362:
    v_28370 = stack[-1];
    v_28371 = qcdr(v_28370);
    goto v_28363;
v_28364:
    v_28370 = stack[0];
    goto v_28365;
v_28366:
    goto v_28362;
v_28363:
    goto v_28364;
v_28365:
    stack[-1] = v_28371;
    stack[0] = v_28370;
    goto v_28255;
v_28349:
    goto v_28331;
    v_28370 = nil;
v_28331:
    goto v_28260;
    v_28370 = nil;
v_28260:
    return onevalue(v_28370);
}



// Code for talp_mkinvop

static LispObject CC_talp_mkinvop(LispObject env,
                         LispObject v_28256, LispObject v_28257)
{
    env = qenv(env);
    LispObject v_28281;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_28257,v_28256);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_28256,v_28257);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_28257;
    stack[-1] = v_28256;
// end of prologue
    goto v_28266;
v_28262:
    goto v_28274;
v_28270:
    v_28281 = elt(env, 1); // inv_
    stack[-2] = Lexplode(nil, v_28281);
    env = stack[-3];
    goto v_28271;
v_28272:
    v_28281 = stack[-1];
    v_28281 = ncons(v_28281);
    env = stack[-3];
    goto v_28273;
v_28274:
    goto v_28270;
v_28271:
    goto v_28272;
v_28273:
    v_28281 = Lnconc(nil, stack[-2], v_28281);
    env = stack[-3];
    v_28281 = Lcompress(nil, v_28281);
    env = stack[-3];
    stack[-1] = Lexplode(nil, v_28281);
    env = stack[-3];
    goto v_28263;
v_28264:
    v_28281 = stack[0];
    v_28281 = Lexplode(nil, v_28281);
    env = stack[-3];
    goto v_28265;
v_28266:
    goto v_28262;
v_28263:
    goto v_28264;
v_28265:
    v_28281 = Lnconc(nil, stack[-1], v_28281);
    env = stack[-3];
    v_28281 = Lcompress(nil, v_28281);
        return Lintern(nil, v_28281);
}



setup_type const u48_setup[] =
{
    {"mksfpf",                  TOO_FEW_2,      CC_mksfpf,     WRONG_NO_2},
    {"gb_searchinlist",         TOO_FEW_2,      CC_gb_searchinlist,WRONG_NO_2},
    {"copy_vect",               TOO_FEW_2,      CC_copy_vect,  WRONG_NO_2},
    {"nestzerop:",              CC_nestzeropT,  TOO_MANY_1,    WRONG_NO_1},
    {"dipretimes",              CC_dipretimes,  TOO_MANY_1,    WRONG_NO_1},
    {"natnump",                 CC_natnump,     TOO_MANY_1,    WRONG_NO_1},
    {"*a2kwoweight",            CC_Ha2kwoweight,TOO_MANY_1,    WRONG_NO_1},
    {"aex_psremseq",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_aex_psremseq},
    {"monomcomparelex",         TOO_FEW_2,      CC_monomcomparelex,WRONG_NO_2},
    {"my_freeof",               TOO_FEW_2,      CC_my_freeof,  WRONG_NO_2},
    {"rl_sacat",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rl_sacat},
    {"acfsf_clnegrel",          TOO_FEW_2,      CC_acfsf_clnegrel,WRONG_NO_2},
    {"parfool",                 CC_parfool,     TOO_MANY_1,    WRONG_NO_1},
    {"groebcplistmerge",        TOO_FEW_2,      CC_groebcplistmerge,WRONG_NO_2},
    {"mkdmoderr",               TOO_FEW_2,      CC_mkdmoderr,  WRONG_NO_2},
    {"indordln",                CC_indordln,    TOO_MANY_1,    WRONG_NO_1},
    {"listquotient",            TOO_FEW_2,      CC_listquotient,WRONG_NO_2},
    {"fs:prin:",                CC_fsTprinT,    TOO_MANY_1,    WRONG_NO_1},
    {"groeb=testb",             TOO_FEW_2,      CC_groebMtestb,WRONG_NO_2},
    {"verify_tens_ids",         CC_verify_tens_ids,TOO_MANY_1, WRONG_NO_1},
    {"no_of_tm_sf_limited",     TOO_FEW_2,      CC_no_of_tm_sf_limited,WRONG_NO_2},
    {"count-linear-factors-mod-p",WRONG_NO_NA,  WRONG_NO_NB,   (n_args *)CC_countKlinearKfactorsKmodKp},
    {"aex_xtothen",             TOO_FEW_2,      CC_aex_xtothen,WRONG_NO_2},
    {"ofsf_facequal",           CC_ofsf_facequal,TOO_MANY_1,   WRONG_NO_1},
    {"ofsf_smeqtable",          TOO_FEW_2,      CC_ofsf_smeqtable,WRONG_NO_2},
    {"dfdeg",                   TOO_FEW_2,      CC_dfdeg,      WRONG_NO_2},
    {"girationalize:",          CC_girationalizeT,TOO_MANY_1,  WRONG_NO_1},
    {"makecoeffpairs",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_makecoeffpairs},
    {"cl_sordp",                TOO_FEW_2,      CC_cl_sordp,   WRONG_NO_2},
    {"bc_dcont",                CC_bc_dcont,    TOO_MANY_1,    WRONG_NO_1},
    {"dvfsf_susipost",          TOO_FEW_2,      CC_dvfsf_susipost,WRONG_NO_2},
    {"matsm*",                  TOO_FEW_2,      CC_matsmH,     WRONG_NO_2},
    {"vdplsort",                CC_vdplsort,    TOO_MANY_1,    WRONG_NO_1},
    {"gfquotient",              TOO_FEW_2,      CC_gfquotient, WRONG_NO_2},
    {"physopsubs",              CC_physopsubs,  TOO_MANY_1,    WRONG_NO_1},
    {"free",                    CC_free,        TOO_MANY_1,    WRONG_NO_1},
    {"expand-imrepartpow",      CC_expandKimrepartpow,TOO_MANY_1,WRONG_NO_1},
    {"njets",                   TOO_FEW_2,      CC_njets,      WRONG_NO_2},
    {"bfminus",                 CC_bfminus,     TOO_MANY_1,    WRONG_NO_1},
    {"domainp_list",            CC_domainp_list,TOO_MANY_1,    WRONG_NO_1},
    {"janettreeinsert",         CC_janettreeinsert,TOO_MANY_1, WRONG_NO_1},
    {"dvfsf_ppolyp",            CC_dvfsf_ppolyp,TOO_MANY_1,    WRONG_NO_1},
    {"spinnerprod",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_spinnerprod},
    {"safe-fp-quot",            TOO_FEW_2,      CC_safeKfpKquot,WRONG_NO_2},
    {"f2dip",                   CC_f2dip,       TOO_MANY_1,    WRONG_NO_1},
    {"reset_opnums",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_reset_opnums},
    {"delete_edge",             TOO_FEW_2,      CC_delete_edge,WRONG_NO_2},
    {"reduce-ratios",           TOO_FEW_2,      CC_reduceKratios,WRONG_NO_2},
    {"fs:subang",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_fsTsubang},
    {"addnew",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_addnew},
    {"flattens1",               CC_flattens1,   TOO_MANY_1,    WRONG_NO_1},
    {"pst_mkpst",               CC_pst_mkpst,   TOO_MANY_1,    WRONG_NO_1},
    {"taylorp",                 CC_taylorp,     TOO_MANY_1,    WRONG_NO_1},
    {"nonlnr",                  TOO_FEW_2,      CC_nonlnr,     WRONG_NO_2},
    {"talp_mkinvop",            TOO_FEW_2,      CC_talp_mkinvop,WRONG_NO_2},
    {NULL, (one_args *)"u48", (two_args *)"34662 9252114 2649643", 0}
};

// end of generated code
