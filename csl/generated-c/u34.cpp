
// $destdir/u34.c        Machine generated C code

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



// Code for module

static LispObject CC_module(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18808, v_18809;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18808 = v_18793;
// end of prologue
    goto v_18802;
v_18798:
    v_18809 = qvalue(elt(env, 1)); // !*mode
    goto v_18799;
v_18800:
    v_18808 = qvalue(elt(env, 2)); // mode!-list!*
    goto v_18801;
v_18802:
    goto v_18798;
v_18799:
    goto v_18800;
v_18801:
    v_18808 = cons(v_18809, v_18808);
    env = stack[0];
    qvalue(elt(env, 2)) = v_18808; // mode!-list!*
    v_18808 = nil;
    v_18808 = ncons(v_18808);
    env = stack[0];
    qvalue(elt(env, 3)) = v_18808; // alglist!*
    v_18808 = elt(env, 4); // symbolic
    qvalue(elt(env, 1)) = v_18808; // !*mode
    v_18808 = nil;
    return onevalue(v_18808);
}



// Code for arglength

static LispObject CC_arglength(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18819, v_18820;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_18820 = v_18793;
// end of prologue
// Binding !*intstr
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = nil; // !*intstr
    v_18819 = v_18820;
    if (v_18819 == nil) goto v_18801;
    else goto v_18802;
v_18801:
    v_18819 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18798;
v_18802:
    v_18819 = lisp_true;
    qvalue(elt(env, 1)) = v_18819; // !*intstr
    v_18819 = v_18820;
    fn = elt(env, 2); // reval
    v_18819 = (*qfn1(fn))(fn, v_18819);
    env = stack[-1];
    v_18820 = v_18819;
    v_18819 = v_18820;
    if (!consp(v_18819)) goto v_18810;
    else goto v_18811;
v_18810:
    v_18819 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_18809;
v_18811:
    v_18819 = v_18820;
    v_18819 = qcdr(v_18819);
    v_18819 = Llength(nil, v_18819);
    goto v_18809;
    v_18819 = nil;
v_18809:
v_18798:
    ;}  // end of a binding scope
    return onevalue(v_18819);
}



// Code for simp!-prop!-condense

static LispObject CC_simpKpropKcondense(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18867, v_18868;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_18793;
// end of prologue
    stack[-2] = nil;
    goto v_18804;
v_18800:
    v_18868 = stack[-3];
    goto v_18801;
v_18802:
    v_18867 = elt(env, 1); // lambda_rfde09ec49c92
    goto v_18803;
v_18804:
    goto v_18800;
v_18801:
    goto v_18802;
v_18803:
    fn = elt(env, 2); // sort
    v_18867 = (*qfn2(fn))(fn, v_18868, v_18867);
    env = stack[-5];
    stack[-3] = v_18867;
v_18809:
    v_18867 = stack[-3];
    if (v_18867 == nil) goto v_18812;
    else goto v_18813;
v_18812:
    goto v_18808;
v_18813:
    v_18867 = stack[-3];
    v_18867 = qcar(v_18867);
    stack[-4] = v_18867;
    v_18867 = stack[-3];
    v_18867 = qcdr(v_18867);
    stack[-3] = v_18867;
    goto v_18825;
v_18821:
    v_18868 = stack[-4];
    goto v_18822;
v_18823:
    v_18867 = stack[-2];
    goto v_18824;
v_18825:
    goto v_18821;
v_18822:
    goto v_18823;
v_18824:
    v_18867 = cons(v_18868, v_18867);
    env = stack[-5];
    stack[-2] = v_18867;
    v_18867 = stack[-3];
    stack[-1] = v_18867;
v_18831:
    v_18867 = stack[-1];
    if (v_18867 == nil) goto v_18835;
    else goto v_18836;
v_18835:
    goto v_18830;
v_18836:
    v_18867 = stack[-1];
    v_18867 = qcar(v_18867);
    stack[0] = v_18867;
    goto v_18851;
v_18847:
    v_18868 = stack[-4];
    goto v_18848;
v_18849:
    v_18867 = stack[0];
    goto v_18850;
v_18851:
    goto v_18847;
v_18848:
    goto v_18849;
v_18850:
    fn = elt(env, 3); // subsetp
    v_18867 = (*qfn2(fn))(fn, v_18868, v_18867);
    env = stack[-5];
    if (v_18867 == nil) goto v_18845;
    goto v_18859;
v_18855:
    v_18868 = stack[0];
    goto v_18856;
v_18857:
    v_18867 = stack[-3];
    goto v_18858;
v_18859:
    goto v_18855;
v_18856:
    goto v_18857;
v_18858:
    v_18867 = Ldelete(nil, v_18868, v_18867);
    env = stack[-5];
    stack[-3] = v_18867;
    goto v_18843;
v_18845:
v_18843:
    v_18867 = stack[-1];
    v_18867 = qcdr(v_18867);
    stack[-1] = v_18867;
    goto v_18831;
v_18830:
    goto v_18809;
v_18808:
    v_18867 = stack[-2];
    {
        fn = elt(env, 4); // ordn
        return (*qfn1(fn))(fn, v_18867);
    }
    return onevalue(v_18867);
}



// Code for lambda_rfde09ec49c92

static LispObject CC_lambda_rfde09ec49c92(LispObject env,
                         LispObject v_18793, LispObject v_18794)
{
    env = qenv(env);
    LispObject v_18806;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18794,v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18793,v_18794);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18794;
    v_18806 = v_18793;
// end of prologue
    goto v_18801;
v_18797:
    stack[-1] = Llength(nil, v_18806);
    env = stack[-2];
    goto v_18798;
v_18799:
    v_18806 = stack[0];
    v_18806 = Llength(nil, v_18806);
    goto v_18800;
v_18801:
    goto v_18797;
v_18798:
    goto v_18799;
v_18800:
    {
        LispObject v_18809 = stack[-1];
        return Llessp(nil, v_18809, v_18806);
    }
}



// Code for skp_ordp

static LispObject CC_skp_ordp(LispObject env,
                         LispObject v_18793, LispObject v_18794)
{
    env = qenv(env);
    LispObject v_18809, v_18810, v_18811;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18809 = v_18794;
    v_18810 = v_18793;
// end of prologue
    goto v_18803;
v_18797:
    v_18811 = qcar(v_18810);
    goto v_18798;
v_18799:
    v_18810 = qcar(v_18809);
    goto v_18800;
v_18801:
    v_18809 = elt(env, 1); // atom_compare
    goto v_18802;
v_18803:
    goto v_18797;
v_18798:
    goto v_18799;
v_18800:
    goto v_18801;
v_18802:
    {
        fn = elt(env, 2); // cons_ordp
        return (*qfnn(fn))(fn, 3, v_18811, v_18810, v_18809);
    }
}



// Code for ra_l

static LispObject CC_ra_l(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18798;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18798 = v_18793;
// end of prologue
    fn = elt(env, 1); // ra_iv
    v_18798 = (*qfn1(fn))(fn, v_18798);
    env = stack[0];
    {
        fn = elt(env, 2); // riv_l
        return (*qfn1(fn))(fn, v_18798);
    }
}



// Code for lalr_extract_nonterminals

static LispObject CC_lalr_extract_nonterminals(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18943, v_18944, v_18945;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_18793;
// end of prologue
    v_18945 = nil;
v_18798:
    v_18943 = stack[-1];
    if (v_18943 == nil) goto v_18801;
    else goto v_18802;
v_18801:
    v_18943 = v_18945;
    {
        fn = elt(env, 7); // nreverse
        return (*qfn1(fn))(fn, v_18943);
    }
v_18802:
    v_18943 = stack[-1];
    if (!consp(v_18943)) goto v_18806;
    else goto v_18807;
v_18806:
    goto v_18814;
v_18810:
    stack[0] = v_18945;
    goto v_18811;
v_18812:
    goto v_18824;
v_18818:
    v_18945 = elt(env, 1); // "Malformed production"
    goto v_18819;
v_18820:
    v_18944 = stack[-1];
    goto v_18821;
v_18822:
    v_18943 = elt(env, 2); // "(RHS should be a list of tokens, not a non-nil atom)"
    goto v_18823;
v_18824:
    goto v_18818;
v_18819:
    goto v_18820;
v_18821:
    goto v_18822;
v_18823:
    v_18943 = list3(v_18945, v_18944, v_18943);
    env = stack[-3];
    fn = elt(env, 8); // rederr
    v_18943 = (*qfn1(fn))(fn, v_18943);
    env = stack[-3];
    goto v_18813;
v_18814:
    goto v_18810;
v_18811:
    goto v_18812;
v_18813:
    {
        LispObject v_18949 = stack[0];
        fn = elt(env, 7); // nreverse
        return (*qfn2(fn))(fn, v_18949, v_18943);
    }
v_18807:
    v_18943 = stack[-1];
    v_18943 = qcar(v_18943);
    v_18943 = Lstringp(nil, v_18943);
    env = stack[-3];
    if (v_18943 == nil) goto v_18829;
    v_18943 = stack[-1];
    v_18943 = qcdr(v_18943);
    stack[-1] = v_18943;
    goto v_18798;
v_18829:
    v_18943 = stack[-1];
    v_18943 = qcar(v_18943);
    if (symbolp(v_18943)) goto v_18835;
    else goto v_18836;
v_18835:
    goto v_18848;
v_18844:
    v_18943 = stack[-1];
    v_18944 = qcar(v_18943);
    goto v_18845;
v_18846:
    v_18943 = elt(env, 3); // lex_fixed_code
    goto v_18847;
v_18848:
    goto v_18844;
v_18845:
    goto v_18846;
v_18847:
    v_18943 = get(v_18944, v_18943);
    env = stack[-3];
    if (v_18943 == nil) goto v_18842;
    v_18943 = stack[-1];
    v_18943 = qcdr(v_18943);
    stack[-1] = v_18943;
    goto v_18798;
v_18842:
    goto v_18861;
v_18857:
    v_18943 = stack[-1];
    v_18943 = qcar(v_18943);
    goto v_18858;
v_18859:
    v_18944 = v_18945;
    goto v_18860;
v_18861:
    goto v_18857;
v_18858:
    goto v_18859;
v_18860:
    v_18943 = cons(v_18943, v_18944);
    env = stack[-3];
    v_18945 = v_18943;
    v_18943 = stack[-1];
    v_18943 = qcdr(v_18943);
    stack[-1] = v_18943;
    goto v_18798;
    goto v_18800;
v_18836:
    v_18943 = stack[-1];
    v_18943 = qcar(v_18943);
    if (!consp(v_18943)) goto v_18867;
    else goto v_18868;
v_18867:
    goto v_18876;
v_18872:
    stack[0] = v_18945;
    goto v_18873;
v_18874:
    goto v_18886;
v_18880:
    v_18945 = elt(env, 1); // "Malformed production"
    goto v_18881;
v_18882:
    v_18944 = stack[-1];
    goto v_18883;
v_18884:
    v_18943 = elt(env, 4); // "(atomic item in token list should be symbol or string)"
    goto v_18885;
v_18886:
    goto v_18880;
v_18881:
    goto v_18882;
v_18883:
    goto v_18884;
v_18885:
    v_18943 = list3(v_18945, v_18944, v_18943);
    env = stack[-3];
    fn = elt(env, 8); // rederr
    v_18943 = (*qfn1(fn))(fn, v_18943);
    env = stack[-3];
    goto v_18875;
v_18876:
    goto v_18872;
v_18873:
    goto v_18874;
v_18875:
    {
        LispObject v_18950 = stack[0];
        fn = elt(env, 7); // nreverse
        return (*qfn2(fn))(fn, v_18950, v_18943);
    }
v_18868:
    goto v_18896;
v_18892:
    v_18943 = stack[-1];
    v_18943 = qcar(v_18943);
    v_18944 = qcar(v_18943);
    goto v_18893;
v_18894:
    v_18943 = elt(env, 5); // (opt seq star plus list listplus or)
    goto v_18895;
v_18896:
    goto v_18892;
v_18893:
    goto v_18894;
v_18895:
    v_18943 = Lmemq(nil, v_18944, v_18943);
    if (v_18943 == nil) goto v_18891;
    goto v_18907;
v_18903:
    stack[-2] = v_18945;
    goto v_18904;
v_18905:
    goto v_18914;
v_18910:
    v_18943 = stack[-1];
    v_18943 = qcar(v_18943);
    v_18943 = qcdr(v_18943);
    stack[0] = CC_lalr_extract_nonterminals(elt(env, 0), v_18943);
    env = stack[-3];
    goto v_18911;
v_18912:
    v_18943 = stack[-1];
    v_18943 = qcdr(v_18943);
    v_18943 = CC_lalr_extract_nonterminals(elt(env, 0), v_18943);
    env = stack[-3];
    goto v_18913;
v_18914:
    goto v_18910;
v_18911:
    goto v_18912;
v_18913:
    v_18943 = Lappend(nil, stack[0], v_18943);
    env = stack[-3];
    goto v_18906;
v_18907:
    goto v_18903;
v_18904:
    goto v_18905;
v_18906:
    {
        LispObject v_18951 = stack[-2];
        fn = elt(env, 7); // nreverse
        return (*qfn2(fn))(fn, v_18951, v_18943);
    }
v_18891:
    goto v_18929;
v_18925:
    stack[0] = v_18945;
    goto v_18926;
v_18927:
    goto v_18939;
v_18933:
    v_18945 = elt(env, 1); // "Malformed production"
    goto v_18934;
v_18935:
    v_18944 = stack[-1];
    goto v_18936;
v_18937:
    v_18943 = elt(env, 6); // "(unrecognised item in rule)"
    goto v_18938;
v_18939:
    goto v_18933;
v_18934:
    goto v_18935;
v_18936:
    goto v_18937;
v_18938:
    v_18943 = list3(v_18945, v_18944, v_18943);
    env = stack[-3];
    fn = elt(env, 8); // rederr
    v_18943 = (*qfn1(fn))(fn, v_18943);
    env = stack[-3];
    goto v_18928;
v_18929:
    goto v_18925;
v_18926:
    goto v_18927;
v_18928:
    {
        LispObject v_18952 = stack[0];
        fn = elt(env, 7); // nreverse
        return (*qfn2(fn))(fn, v_18952, v_18943);
    }
v_18800:
    v_18943 = nil;
    return onevalue(v_18943);
}



// Code for aex_mklcnt

static LispObject CC_aex_mklcnt(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18862, v_18863;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18793;
// end of prologue
v_18792:
    v_18862 = stack[0];
    fn = elt(env, 1); // aex_simpleratp
    v_18862 = (*qfn1(fn))(fn, v_18862);
    env = stack[-2];
    if (v_18862 == nil) goto v_18802;
    else goto v_18800;
v_18802:
    v_18862 = stack[0];
    fn = elt(env, 2); // aex_ctx
    v_18862 = (*qfn1(fn))(fn, v_18862);
    env = stack[-2];
    fn = elt(env, 3); // ctx_idl
    v_18862 = (*qfn1(fn))(fn, v_18862);
    env = stack[-2];
    if (v_18862 == nil) goto v_18800;
    goto v_18801;
v_18800:
    v_18862 = stack[0];
    goto v_18797;
v_18801:
    v_18862 = stack[0];
    fn = elt(env, 4); // aex_fvarl
    v_18862 = (*qfn1(fn))(fn, v_18862);
    env = stack[-2];
    stack[-1] = v_18862;
    v_18862 = stack[-1];
    if (v_18862 == nil) goto v_18815;
    goto v_18820;
    goto v_18818;
v_18820:
v_18818:
    goto v_18832;
v_18828:
    v_18863 = stack[0];
    goto v_18829;
v_18830:
    v_18862 = stack[-1];
    v_18862 = qcar(v_18862);
    goto v_18831;
v_18832:
    goto v_18828;
v_18829:
    goto v_18830;
v_18831:
    fn = elt(env, 5); // aex_lc
    v_18862 = (*qfn2(fn))(fn, v_18863, v_18862);
    env = stack[-2];
    fn = elt(env, 6); // aex_nullp
    v_18862 = (*qfn1(fn))(fn, v_18862);
    env = stack[-2];
    if (v_18862 == nil) goto v_18825;
    goto v_18842;
v_18838:
    v_18863 = stack[0];
    goto v_18839;
v_18840:
    v_18862 = stack[-1];
    v_18862 = qcar(v_18862);
    goto v_18841;
v_18842:
    goto v_18838;
v_18839:
    goto v_18840;
v_18841:
    fn = elt(env, 7); // aex_red
    v_18862 = (*qfn2(fn))(fn, v_18863, v_18862);
    env = stack[-2];
    stack[0] = v_18862;
    goto v_18792;
v_18825:
    v_18862 = stack[0];
    goto v_18797;
v_18815:
    goto v_18856;
v_18852:
    v_18862 = stack[0];
    fn = elt(env, 8); // aex_sgn
    v_18863 = (*qfn1(fn))(fn, v_18862);
    env = stack[-2];
    goto v_18853;
v_18854:
    v_18862 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18855;
v_18856:
    goto v_18852;
v_18853:
    goto v_18854;
v_18855:
    v_18862 = Leqn(nil, v_18863, v_18862);
    env = stack[-2];
    if (v_18862 == nil) goto v_18850;
    {
        fn = elt(env, 9); // aex_0
        return (*qfnn(fn))(fn, 0);
    }
v_18850:
    v_18862 = stack[0];
v_18797:
    return onevalue(v_18862);
}



// Code for vp2

static LispObject CC_vp2(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18818, v_18819;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18793;
// end of prologue
    v_18819 = nil;
v_18798:
    v_18818 = stack[0];
    if (v_18818 == nil) goto v_18801;
    else goto v_18802;
v_18801:
    v_18818 = v_18819;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_18818);
    }
v_18802:
    goto v_18813;
v_18809:
    v_18818 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18810;
v_18811:
    goto v_18812;
v_18813:
    goto v_18809;
v_18810:
    goto v_18811;
v_18812:
    v_18818 = cons(v_18818, v_18819);
    env = stack[-1];
    v_18819 = v_18818;
    v_18818 = stack[0];
    v_18818 = qcdr(v_18818);
    stack[0] = v_18818;
    goto v_18798;
    v_18818 = nil;
    return onevalue(v_18818);
}



// Code for pasf_cein

static LispObject CC_pasf_cein(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_19035, v_19036;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_18793;
// end of prologue
    goto v_18815;
v_18811:
    v_19036 = stack[-3];
    goto v_18812;
v_18813:
    v_19035 = elt(env, 1); // true
    goto v_18814;
v_18815:
    goto v_18811;
v_18812:
    goto v_18813;
v_18814:
    if (v_19036 == v_19035) goto v_18809;
    else goto v_18810;
v_18809:
    v_19035 = lisp_true;
    goto v_18808;
v_18810:
    goto v_18825;
v_18821:
    v_19036 = stack[-3];
    goto v_18822;
v_18823:
    v_19035 = elt(env, 2); // false
    goto v_18824;
v_18825:
    goto v_18821;
v_18822:
    goto v_18823;
v_18824:
    v_19035 = (v_19036 == v_19035 ? lisp_true : nil);
    goto v_18808;
    v_19035 = nil;
v_18808:
    if (v_19035 == nil) goto v_18806;
    v_19035 = lisp_true;
    goto v_18804;
v_18806:
    goto v_18836;
v_18832:
    goto v_18849;
v_18845:
    v_19036 = stack[-3];
    goto v_18846;
v_18847:
    v_19035 = elt(env, 1); // true
    goto v_18848;
v_18849:
    goto v_18845;
v_18846:
    goto v_18847;
v_18848:
    if (v_19036 == v_19035) goto v_18843;
    else goto v_18844;
v_18843:
    v_19035 = lisp_true;
    goto v_18842;
v_18844:
    goto v_18859;
v_18855:
    v_19036 = stack[-3];
    goto v_18856;
v_18857:
    v_19035 = elt(env, 2); // false
    goto v_18858;
v_18859:
    goto v_18855;
v_18856:
    goto v_18857;
v_18858:
    v_19035 = (v_19036 == v_19035 ? lisp_true : nil);
    goto v_18842;
    v_19035 = nil;
v_18842:
    if (v_19035 == nil) goto v_18840;
    v_19035 = stack[-3];
    v_19036 = v_19035;
    goto v_18838;
v_18840:
    v_19035 = stack[-3];
    v_19035 = qcar(v_19035);
    v_19035 = Lconsp(nil, v_19035);
    env = stack[-5];
    if (v_19035 == nil) goto v_18865;
    v_19035 = stack[-3];
    v_19035 = qcar(v_19035);
    v_19035 = qcar(v_19035);
    v_19036 = v_19035;
    goto v_18838;
v_18865:
    v_19035 = stack[-3];
    v_19035 = qcar(v_19035);
    v_19036 = v_19035;
    goto v_18838;
    v_19036 = nil;
v_18838:
    goto v_18833;
v_18834:
    v_19035 = elt(env, 3); // (leq greaterp geq lessp)
    goto v_18835;
v_18836:
    goto v_18832;
v_18833:
    goto v_18834;
v_18835:
    v_19035 = Lmemq(nil, v_19036, v_19035);
    v_19035 = (v_19035 == nil ? lisp_true : nil);
    goto v_18804;
    v_19035 = nil;
v_18804:
    if (v_19035 == nil) goto v_18802;
    v_19035 = stack[-3];
    goto v_18798;
v_18802:
    v_19035 = stack[-3];
    v_19035 = qcdr(v_19035);
    v_19035 = qcar(v_19035);
    fn = elt(env, 6); // pasf_deci
    v_19035 = (*qfn1(fn))(fn, v_19035);
    env = stack[-5];
    stack[-2] = v_19035;
    v_19035 = stack[-2];
    v_19035 = qcar(v_19035);
    fn = elt(env, 7); // sfto_dcontentf
    v_19035 = (*qfn1(fn))(fn, v_19035);
    env = stack[-5];
    stack[-4] = v_19035;
    goto v_18894;
v_18888:
    v_19035 = stack[-3];
    stack[-1] = qcar(v_19035);
    goto v_18889;
v_18890:
    goto v_18902;
v_18898:
    goto v_18908;
v_18904:
    v_19035 = stack[-2];
    stack[0] = qcar(v_19035);
    goto v_18905;
v_18906:
    v_19035 = stack[-4];
    fn = elt(env, 8); // simp
    v_19035 = (*qfn1(fn))(fn, v_19035);
    env = stack[-5];
    v_19035 = qcar(v_19035);
    goto v_18907;
v_18908:
    goto v_18904;
v_18905:
    goto v_18906;
v_18907:
    fn = elt(env, 9); // quotfx
    stack[0] = (*qfn2(fn))(fn, stack[0], v_19035);
    env = stack[-5];
    goto v_18899;
v_18900:
    goto v_18922;
v_18918:
    goto v_18935;
v_18931:
    v_19036 = stack[-3];
    goto v_18932;
v_18933:
    v_19035 = elt(env, 1); // true
    goto v_18934;
v_18935:
    goto v_18931;
v_18932:
    goto v_18933;
v_18934:
    if (v_19036 == v_19035) goto v_18929;
    else goto v_18930;
v_18929:
    v_19035 = lisp_true;
    goto v_18928;
v_18930:
    goto v_18945;
v_18941:
    v_19036 = stack[-3];
    goto v_18942;
v_18943:
    v_19035 = elt(env, 2); // false
    goto v_18944;
v_18945:
    goto v_18941;
v_18942:
    goto v_18943;
v_18944:
    v_19035 = (v_19036 == v_19035 ? lisp_true : nil);
    goto v_18928;
    v_19035 = nil;
v_18928:
    if (v_19035 == nil) goto v_18926;
    v_19035 = stack[-3];
    v_19036 = v_19035;
    goto v_18924;
v_18926:
    v_19035 = stack[-3];
    v_19035 = qcar(v_19035);
    v_19035 = Lconsp(nil, v_19035);
    env = stack[-5];
    if (v_19035 == nil) goto v_18951;
    v_19035 = stack[-3];
    v_19035 = qcar(v_19035);
    v_19035 = qcar(v_19035);
    v_19036 = v_19035;
    goto v_18924;
v_18951:
    v_19035 = stack[-3];
    v_19035 = qcar(v_19035);
    v_19036 = v_19035;
    goto v_18924;
    v_19036 = nil;
v_18924:
    goto v_18919;
v_18920:
    v_19035 = elt(env, 4); // (leq greaterp)
    goto v_18921;
v_18922:
    goto v_18918;
v_18919:
    goto v_18920;
v_18921:
    v_19035 = Lmemq(nil, v_19036, v_19035);
    if (v_19035 == nil) goto v_18917;
    goto v_18970;
v_18966:
    v_19035 = stack[-2];
    v_19035 = qcdr(v_19035);
    v_19036 = negate(v_19035);
    env = stack[-5];
    goto v_18967;
v_18968:
    v_19035 = stack[-4];
    goto v_18969;
v_18970:
    goto v_18966;
v_18967:
    goto v_18968;
v_18969:
    fn = elt(env, 10); // pasf_floor
    v_19035 = (*qfn2(fn))(fn, v_19036, v_19035);
    env = stack[-5];
    fn = elt(env, 11); // negf
    v_19035 = (*qfn1(fn))(fn, v_19035);
    env = stack[-5];
    goto v_18915;
v_18917:
    goto v_18981;
v_18977:
    goto v_18994;
v_18990:
    v_19036 = stack[-3];
    goto v_18991;
v_18992:
    v_19035 = elt(env, 1); // true
    goto v_18993;
v_18994:
    goto v_18990;
v_18991:
    goto v_18992;
v_18993:
    if (v_19036 == v_19035) goto v_18988;
    else goto v_18989;
v_18988:
    v_19035 = lisp_true;
    goto v_18987;
v_18989:
    goto v_19004;
v_19000:
    v_19036 = stack[-3];
    goto v_19001;
v_19002:
    v_19035 = elt(env, 2); // false
    goto v_19003;
v_19004:
    goto v_19000;
v_19001:
    goto v_19002;
v_19003:
    v_19035 = (v_19036 == v_19035 ? lisp_true : nil);
    goto v_18987;
    v_19035 = nil;
v_18987:
    if (v_19035 == nil) goto v_18985;
    v_19035 = stack[-3];
    v_19036 = v_19035;
    goto v_18983;
v_18985:
    v_19035 = stack[-3];
    v_19035 = qcar(v_19035);
    v_19035 = Lconsp(nil, v_19035);
    env = stack[-5];
    if (v_19035 == nil) goto v_19010;
    v_19035 = stack[-3];
    v_19035 = qcar(v_19035);
    v_19035 = qcar(v_19035);
    v_19036 = v_19035;
    goto v_18983;
v_19010:
    v_19035 = stack[-3];
    v_19035 = qcar(v_19035);
    v_19036 = v_19035;
    goto v_18983;
    v_19036 = nil;
v_18983:
    goto v_18978;
v_18979:
    v_19035 = elt(env, 5); // (geq lessp)
    goto v_18980;
v_18981:
    goto v_18977;
v_18978:
    goto v_18979;
v_18980:
    v_19035 = Lmemq(nil, v_19036, v_19035);
    if (v_19035 == nil) goto v_18976;
    goto v_19029;
v_19025:
    v_19035 = stack[-2];
    v_19035 = qcdr(v_19035);
    v_19036 = negate(v_19035);
    env = stack[-5];
    goto v_19026;
v_19027:
    v_19035 = stack[-4];
    goto v_19028;
v_19029:
    goto v_19025;
v_19026:
    goto v_19027;
v_19028:
    fn = elt(env, 12); // pasf_ceil
    v_19035 = (*qfn2(fn))(fn, v_19036, v_19035);
    env = stack[-5];
    fn = elt(env, 11); // negf
    v_19035 = (*qfn1(fn))(fn, v_19035);
    env = stack[-5];
    goto v_18915;
v_18976:
    v_19035 = nil;
v_18915:
    goto v_18901;
v_18902:
    goto v_18898;
v_18899:
    goto v_18900;
v_18901:
    fn = elt(env, 13); // addf
    v_19036 = (*qfn2(fn))(fn, stack[0], v_19035);
    goto v_18891;
v_18892:
    v_19035 = nil;
    goto v_18893;
v_18894:
    goto v_18888;
v_18889:
    goto v_18890;
v_18891:
    goto v_18892;
v_18893:
    {
        LispObject v_19042 = stack[-1];
        return list3(v_19042, v_19036, v_19035);
    }
v_18798:
    return onevalue(v_19035);
}



// Code for ev_2a

static LispObject CC_ev_2a(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18803, v_18804;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18803 = v_18793;
// end of prologue
    goto v_18800;
v_18796:
    v_18804 = v_18803;
    goto v_18797;
v_18798:
    v_18803 = qvalue(elt(env, 1)); // dip_vars!*
    goto v_18799;
v_18800:
    goto v_18796;
v_18797:
    goto v_18798;
v_18799:
    {
        fn = elt(env, 2); // ev_2a1
        return (*qfn2(fn))(fn, v_18804, v_18803);
    }
}



// Code for bvarrd

static LispObject CC_bvarrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18889, v_18890;
    LispObject fn;
    argcheck(nargs, 0, "bvarrd");
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
    fn = elt(env, 9); // lex
    v_18889 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_18807;
v_18803:
    v_18890 = qvalue(elt(env, 1)); // char
    goto v_18804;
v_18805:
    v_18889 = elt(env, 2); // (d e g r e e)
    goto v_18806;
v_18807:
    goto v_18803;
v_18804:
    goto v_18805;
v_18806:
    if (equal(v_18890, v_18889)) goto v_18801;
    else goto v_18802;
v_18801:
    goto v_18815;
v_18811:
    v_18890 = elt(env, 3); // "<bvar>"
    goto v_18812;
v_18813:
    v_18889 = (LispObject)240+TAG_FIXNUM; // 15
    goto v_18814;
v_18815:
    goto v_18811;
v_18812:
    goto v_18813;
v_18814:
    fn = elt(env, 10); // errorml
    v_18889 = (*qfn2(fn))(fn, v_18890, v_18889);
    env = stack[-3];
    goto v_18800;
v_18802:
v_18800:
    fn = elt(env, 11); // mathml2
    v_18889 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[0] = v_18889;
    fn = elt(env, 9); // lex
    v_18889 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_18828;
v_18824:
    v_18890 = qvalue(elt(env, 1)); // char
    goto v_18825;
v_18826:
    v_18889 = elt(env, 2); // (d e g r e e)
    goto v_18827;
v_18828:
    goto v_18824;
v_18825:
    goto v_18826;
v_18827:
    if (equal(v_18890, v_18889)) goto v_18822;
    else goto v_18823;
v_18822:
    fn = elt(env, 12); // mathml
    v_18889 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-2] = v_18889;
    fn = elt(env, 9); // lex
    v_18889 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_18841;
v_18837:
    v_18890 = qvalue(elt(env, 1)); // char
    goto v_18838;
v_18839:
    v_18889 = elt(env, 4); // (!/ d e g r e e)
    goto v_18840;
v_18841:
    goto v_18837;
v_18838:
    goto v_18839;
v_18840:
    if (equal(v_18890, v_18889)) goto v_18836;
    goto v_18849;
v_18845:
    v_18890 = elt(env, 5); // "</degree>"
    goto v_18846;
v_18847:
    v_18889 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_18848;
v_18849:
    goto v_18845;
v_18846:
    goto v_18847;
v_18848:
    fn = elt(env, 13); // error
    v_18889 = (*qfn2(fn))(fn, v_18890, v_18889);
    env = stack[-3];
    goto v_18834;
v_18836:
v_18834:
    fn = elt(env, 9); // lex
    v_18889 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_18821;
v_18823:
    v_18889 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_18889;
    goto v_18821;
v_18821:
    goto v_18864;
v_18860:
    v_18890 = qvalue(elt(env, 1)); // char
    goto v_18861;
v_18862:
    v_18889 = elt(env, 6); // (!/ b v a r)
    goto v_18863;
v_18864:
    goto v_18860;
v_18861:
    goto v_18862;
v_18863:
    if (equal(v_18890, v_18889)) goto v_18858;
    else goto v_18859;
v_18858:
    goto v_18874;
v_18868:
    stack[-1] = elt(env, 7); // bvar
    goto v_18869;
v_18870:
    goto v_18871;
v_18872:
    v_18889 = stack[-2];
    v_18889 = ncons(v_18889);
    goto v_18873;
v_18874:
    goto v_18868;
v_18869:
    goto v_18870;
v_18871:
    goto v_18872;
v_18873:
    {
        LispObject v_18894 = stack[-1];
        LispObject v_18895 = stack[0];
        return list2star(v_18894, v_18895, v_18889);
    }
v_18859:
    goto v_18886;
v_18882:
    v_18890 = elt(env, 8); // "</bvar>"
    goto v_18883;
v_18884:
    v_18889 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_18885;
v_18886:
    goto v_18882;
v_18883:
    goto v_18884;
v_18885:
    fn = elt(env, 10); // errorml
    v_18889 = (*qfn2(fn))(fn, v_18890, v_18889);
    goto v_18857;
v_18857:
    v_18889 = nil;
    return onevalue(v_18889);
}



// Code for resume

static LispObject CC_resume(LispObject env,
                         LispObject v_18793, LispObject v_18794)
{
    env = qenv(env);
    LispObject v_18833, v_18834, v_18835, v_18836;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18794,v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18793,v_18794);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18833 = v_18794;
    v_18834 = v_18793;
// end of prologue
    v_18835 = v_18833;
    if (v_18835 == nil) goto v_18799;
    goto v_18810;
v_18802:
    v_18835 = v_18833;
    v_18835 = qcar(v_18835);
    v_18836 = qcar(v_18835);
    goto v_18803;
v_18804:
    v_18835 = v_18833;
    v_18835 = qcar(v_18835);
    v_18835 = qcdr(v_18835);
    v_18835 = qcar(v_18835);
    goto v_18805;
v_18806:
    goto v_18807;
v_18808:
    v_18833 = qcdr(v_18833);
    goto v_18809;
v_18810:
    goto v_18802;
v_18803:
    goto v_18804;
v_18805:
    goto v_18806;
v_18807:
    goto v_18808;
v_18809:
    {
        fn = elt(env, 2); // amatch
        return (*qfnn(fn))(fn, 4, v_18836, v_18835, v_18834, v_18833);
    }
v_18799:
    goto v_18827;
v_18823:
    v_18833 = v_18834;
    fn = elt(env, 3); // chk
    v_18834 = (*qfn1(fn))(fn, v_18833);
    env = stack[0];
    goto v_18824;
v_18825:
    v_18833 = lisp_true;
    goto v_18826;
v_18827:
    goto v_18823;
v_18824:
    goto v_18825;
v_18826:
    if (v_18834 == v_18833) goto v_18821;
    else goto v_18822;
v_18821:
    v_18833 = qvalue(elt(env, 1)); // substitution
    {
        fn = elt(env, 4); // bsubs
        return (*qfn1(fn))(fn, v_18833);
    }
v_18822:
    v_18833 = nil;
    return onevalue(v_18833);
}



// Code for evaluate

static LispObject CC_evaluate(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18850, v_18851, v_18852;
    LispObject fn;
    LispObject v_18795, v_18794, v_18793;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "evaluate");
    va_start(aa, nargs);
    v_18793 = va_arg(aa, LispObject);
    v_18794 = va_arg(aa, LispObject);
    v_18795 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18795,v_18794,v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18793,v_18794,v_18795);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    v_18851 = v_18795;
    v_18852 = v_18794;
    stack[-5] = v_18793;
// end of prologue
// Binding !*evaluateerror
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-7, 1, -4);
    qvalue(elt(env, 1)) = nil; // !*evaluateerror
    v_18850 = qvalue(elt(env, 2)); // !*protfg
    v_18850 = (v_18850 == nil ? lisp_true : nil);
    stack[-3] = v_18850;
    goto v_18810;
v_18806:
    v_18850 = v_18852;
    goto v_18807;
v_18808:
    goto v_18809;
v_18810:
    goto v_18806;
v_18807:
    goto v_18808;
v_18809:
    fn = elt(env, 6); // pair
    v_18850 = (*qfn2(fn))(fn, v_18850, v_18851);
    env = stack[-7];
    stack[-6] = v_18850;
    v_18851 = nil;
    v_18850 = lisp_true;
// Binding !*msg
// FLUIDBIND: reloadenv=7 litvec-offset=3 saveloc=2
{   bind_fluid_stack bind_fluid_var(-7, 3, -2);
    qvalue(elt(env, 3)) = v_18851; // !*msg
// Binding !*protfg
// FLUIDBIND: reloadenv=7 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-7, 2, -1);
    qvalue(elt(env, 2)) = v_18850; // !*protfg
    goto v_18824;
v_18818:
    goto v_18832;
v_18826:
    stack[0] = elt(env, 4); // evaluate0
    goto v_18827;
v_18828:
    v_18850 = stack[-5];
    stack[-5] = Lmkquote(nil, v_18850);
    env = stack[-7];
    goto v_18829;
v_18830:
    v_18850 = stack[-6];
    v_18850 = Lmkquote(nil, v_18850);
    env = stack[-7];
    goto v_18831;
v_18832:
    goto v_18826;
v_18827:
    goto v_18828;
v_18829:
    goto v_18830;
v_18831:
    v_18852 = list3(stack[0], stack[-5], v_18850);
    env = stack[-7];
    goto v_18819;
v_18820:
    v_18851 = stack[-3];
    goto v_18821;
v_18822:
    v_18850 = nil;
    goto v_18823;
v_18824:
    goto v_18818;
v_18819:
    goto v_18820;
v_18821:
    goto v_18822;
v_18823:
    fn = elt(env, 7); // errorset
    v_18850 = (*qfnn(fn))(fn, 3, v_18852, v_18851, v_18850);
    env = stack[-7];
    stack[0] = v_18850;
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    v_18850 = stack[0];
    fn = elt(env, 8); // errorp
    v_18850 = (*qfn1(fn))(fn, v_18850);
    env = stack[-7];
    if (v_18850 == nil) goto v_18843;
    v_18850 = elt(env, 5); // "error during function evaluation (e.g. singularity)"
    fn = elt(env, 9); // rederr
    v_18850 = (*qfn1(fn))(fn, v_18850);
    goto v_18841;
v_18843:
v_18841:
    v_18850 = stack[0];
    v_18850 = qcar(v_18850);
    ;}  // end of a binding scope
    return onevalue(v_18850);
}



// Code for toolongexpp

static LispObject CC_toolongexpp(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18804, v_18805;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18804 = v_18793;
// end of prologue
    goto v_18800;
v_18796:
    fn = elt(env, 2); // numprintlen
    v_18804 = (*qfn1(fn))(fn, v_18804);
    env = stack[0];
    goto v_18797;
v_18798:
    v_18805 = qvalue(elt(env, 1)); // maxexpprintlen!*
    goto v_18799;
v_18800:
    goto v_18796;
v_18797:
    goto v_18798;
v_18799:
        return Lgreaterp(nil, v_18804, v_18805);
}



// Code for reval3

static LispObject CC_reval3(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18800;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18800 = v_18793;
// end of prologue
    fn = elt(env, 1); // simp
    v_18800 = (*qfn1(fn))(fn, v_18800);
    env = stack[0];
    {
        fn = elt(env, 2); // mk!*sq
        return (*qfn1(fn))(fn, v_18800);
    }
}



// Code for incident

static LispObject CC_incident(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18847, v_18848, v_18849;
    LispObject fn;
    LispObject v_18795, v_18794, v_18793;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "incident");
    va_start(aa, nargs);
    v_18793 = va_arg(aa, LispObject);
    v_18794 = va_arg(aa, LispObject);
    v_18795 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18795,v_18794,v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18793,v_18794,v_18795);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_18795;
    stack[0] = v_18794;
    stack[-2] = v_18793;
// end of prologue
v_18792:
    v_18847 = stack[0];
    if (v_18847 == nil) goto v_18799;
    else goto v_18800;
v_18799:
    v_18847 = nil;
    goto v_18798;
v_18800:
    goto v_18812;
v_18806:
    v_18849 = stack[-2];
    goto v_18807;
v_18808:
    v_18847 = stack[0];
    v_18848 = qcar(v_18847);
    goto v_18809;
v_18810:
    v_18847 = stack[-1];
    goto v_18811;
v_18812:
    goto v_18806;
v_18807:
    goto v_18808;
v_18809:
    goto v_18810;
v_18811:
    fn = elt(env, 1); // incident1
    v_18847 = (*qfnn(fn))(fn, 3, v_18849, v_18848, v_18847);
    env = stack[-3];
    v_18848 = v_18847;
    v_18847 = v_18848;
    if (v_18847 == nil) goto v_18821;
    goto v_18828;
v_18824:
    goto v_18825;
v_18826:
    v_18847 = stack[0];
    v_18847 = qcdr(v_18847);
    goto v_18827;
v_18828:
    goto v_18824;
v_18825:
    goto v_18826;
v_18827:
    return cons(v_18848, v_18847);
v_18821:
    goto v_18841;
v_18835:
    goto v_18836;
v_18837:
    v_18847 = stack[0];
    stack[0] = qcdr(v_18847);
    goto v_18838;
v_18839:
    v_18847 = stack[-1];
    v_18847 = add1(v_18847);
    env = stack[-3];
    goto v_18840;
v_18841:
    goto v_18835;
v_18836:
    goto v_18837;
v_18838:
    goto v_18839;
v_18840:
    stack[-1] = v_18847;
    goto v_18792;
    v_18847 = nil;
    goto v_18798;
    v_18847 = nil;
v_18798:
    return onevalue(v_18847);
}



// Code for fs!:onep!:

static LispObject CC_fsTonepT(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18798;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18798 = v_18793;
// end of prologue
    v_18798 = qcdr(v_18798);
    {
        fn = elt(env, 1); // fs!:onep
        return (*qfn1(fn))(fn, v_18798);
    }
}



// Code for formbool

static LispObject CC_formbool(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_19084, v_19085, v_19086, v_19087, v_19088;
    LispObject fn;
    LispObject v_18795, v_18794, v_18793;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formbool");
    va_start(aa, nargs);
    v_18793 = va_arg(aa, LispObject);
    v_18794 = va_arg(aa, LispObject);
    v_18795 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18795,v_18794,v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18793,v_18794,v_18795);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_18795;
    stack[-3] = v_18794;
    stack[-4] = v_18793;
// end of prologue
    goto v_18805;
v_18801:
    v_19085 = stack[-2];
    goto v_18802;
v_18803:
    v_19084 = elt(env, 1); // symbolic
    goto v_18804;
v_18805:
    goto v_18801;
v_18802:
    goto v_18803;
v_18804:
    if (v_19085 == v_19084) goto v_18799;
    else goto v_18800;
v_18799:
    goto v_18815;
v_18809:
    v_19086 = stack[-4];
    goto v_18810;
v_18811:
    v_19085 = stack[-3];
    goto v_18812;
v_18813:
    v_19084 = stack[-2];
    goto v_18814;
v_18815:
    goto v_18809;
v_18810:
    goto v_18811;
v_18812:
    goto v_18813;
v_18814:
    {
        fn = elt(env, 9); // formc
        return (*qfnn(fn))(fn, 3, v_19086, v_19085, v_19084);
    }
v_18800:
    v_19084 = stack[-4];
    if (!consp(v_19084)) goto v_18819;
    else goto v_18820;
v_18819:
    goto v_18830;
v_18826:
    v_19085 = stack[-4];
    goto v_18827;
v_18828:
    v_19084 = lisp_true;
    goto v_18829;
v_18830:
    goto v_18826;
v_18827:
    goto v_18828;
v_18829:
    if (v_19085 == v_19084) goto v_18824;
    else goto v_18825;
v_18824:
    v_19084 = stack[-4];
    goto v_18823;
v_18825:
    v_19084 = stack[-4];
    if (symbolp(v_19084)) goto v_18839;
    v_19084 = lisp_true;
    goto v_18837;
v_18839:
    goto v_18848;
v_18844:
    v_19085 = stack[-4];
    goto v_18845;
v_18846:
    v_19084 = stack[-3];
    goto v_18847;
v_18848:
    goto v_18844;
v_18845:
    goto v_18846;
v_18847:
    v_19084 = Latsoc(nil, v_19085, v_19084);
    goto v_18837;
    v_19084 = nil;
v_18837:
    if (v_19084 == nil) goto v_18835;
    goto v_18857;
v_18853:
    v_19085 = elt(env, 2); // boolvalue!*
    goto v_18854;
v_18855:
    v_19084 = stack[-4];
    goto v_18856;
v_18857:
    goto v_18853;
v_18854:
    goto v_18855;
v_18856:
    return list2(v_19085, v_19084);
v_18835:
    goto v_18867;
v_18863:
    stack[0] = elt(env, 2); // boolvalue!*
    goto v_18864;
v_18865:
    goto v_18876;
v_18870:
    v_19086 = stack[-4];
    goto v_18871;
v_18872:
    v_19085 = stack[-3];
    goto v_18873;
v_18874:
    v_19084 = stack[-2];
    goto v_18875;
v_18876:
    goto v_18870;
v_18871:
    goto v_18872;
v_18873:
    goto v_18874;
v_18875:
    fn = elt(env, 10); // formc!*
    v_19084 = (*qfnn(fn))(fn, 3, v_19086, v_19085, v_19084);
    goto v_18866;
v_18867:
    goto v_18863;
v_18864:
    goto v_18865;
v_18866:
    {
        LispObject v_19095 = stack[0];
        return list2(v_19095, v_19084);
    }
    v_19084 = nil;
v_18823:
    goto v_18798;
v_18820:
    goto v_18888;
v_18884:
    v_19084 = stack[-4];
    v_19085 = qcdr(v_19084);
    goto v_18885;
v_18886:
    v_19084 = stack[-3];
    goto v_18887;
v_18888:
    goto v_18884;
v_18885:
    goto v_18886;
v_18887:
    fn = elt(env, 11); // intexprlisp
    v_19084 = (*qfn2(fn))(fn, v_19085, v_19084);
    env = stack[-6];
    if (v_19084 == nil) goto v_18881;
    goto v_18898;
v_18894:
    v_19084 = stack[-4];
    v_19085 = qcar(v_19084);
    goto v_18895;
v_18896:
    v_19084 = elt(env, 3); // boolfn
    goto v_18897;
v_18898:
    goto v_18894;
v_18895:
    goto v_18896;
v_18897:
    v_19084 = get(v_19085, v_19084);
    env = stack[-6];
    if (v_19084 == nil) goto v_18881;
    v_19084 = stack[-4];
    goto v_18798;
v_18881:
    v_19084 = stack[-4];
    v_19084 = qcar(v_19084);
    if (symbolp(v_19084)) goto v_18905;
    else goto v_18904;
v_18905:
    goto v_18914;
v_18910:
    v_19084 = stack[-4];
    v_19085 = qcar(v_19084);
    goto v_18911;
v_18912:
    v_19084 = elt(env, 3); // boolfn
    goto v_18913;
v_18914:
    goto v_18910;
v_18911:
    goto v_18912;
v_18913:
    v_19084 = get(v_19085, v_19084);
    env = stack[-6];
    if (v_19084 == nil) goto v_18904;
    goto v_18923;
v_18919:
    goto v_18929;
v_18925:
    v_19084 = stack[-4];
    v_19085 = qcar(v_19084);
    goto v_18926;
v_18927:
    v_19084 = elt(env, 3); // boolfn
    goto v_18928;
v_18929:
    goto v_18925;
v_18926:
    goto v_18927;
v_18928:
    stack[0] = get(v_19085, v_19084);
    env = stack[-6];
    goto v_18920;
v_18921:
    goto v_18940;
v_18934:
    v_19084 = stack[-4];
    v_19086 = qcdr(v_19084);
    goto v_18935;
v_18936:
    v_19085 = stack[-3];
    goto v_18937;
v_18938:
    v_19084 = stack[-2];
    goto v_18939;
v_18940:
    goto v_18934;
v_18935:
    goto v_18936;
v_18937:
    goto v_18938;
v_18939:
    fn = elt(env, 12); // formclis
    v_19084 = (*qfnn(fn))(fn, 3, v_19086, v_19085, v_19084);
    goto v_18922;
v_18923:
    goto v_18919;
v_18920:
    goto v_18921;
v_18922:
    {
        LispObject v_19096 = stack[0];
        return cons(v_19096, v_19084);
    }
v_18904:
    v_19084 = stack[-4];
    v_19084 = qcar(v_19084);
    if (symbolp(v_19084)) goto v_18947;
    else goto v_18946;
v_18947:
    goto v_18956;
v_18952:
    v_19084 = stack[-4];
    v_19085 = qcar(v_19084);
    goto v_18953;
v_18954:
    v_19084 = elt(env, 4); // boolean
    goto v_18955;
v_18956:
    goto v_18952;
v_18953:
    goto v_18954;
v_18955:
    v_19084 = Lflagp(nil, v_19085, v_19084);
    env = stack[-6];
    if (v_19084 == nil) goto v_18946;
    goto v_18965;
v_18961:
    v_19084 = stack[-4];
    stack[0] = qcar(v_19084);
    goto v_18962;
v_18963:
    goto v_18977;
v_18969:
    v_19084 = stack[-4];
    v_19088 = qcdr(v_19084);
    goto v_18970;
v_18971:
    v_19087 = stack[-3];
    goto v_18972;
v_18973:
    v_19086 = stack[-2];
    goto v_18974;
v_18975:
    goto v_18987;
v_18983:
    v_19084 = stack[-4];
    v_19085 = qcar(v_19084);
    goto v_18984;
v_18985:
    v_19084 = elt(env, 5); // boolargs
    goto v_18986;
v_18987:
    goto v_18983;
v_18984:
    goto v_18985;
v_18986:
    v_19084 = Lflagp(nil, v_19085, v_19084);
    env = stack[-6];
    goto v_18976;
v_18977:
    goto v_18969;
v_18970:
    goto v_18971;
v_18972:
    goto v_18973;
v_18974:
    goto v_18975;
v_18976:
    fn = elt(env, 13); // formboollis
    v_19084 = (*qfnn(fn))(fn, 4, v_19088, v_19087, v_19086, v_19084);
    goto v_18964;
v_18965:
    goto v_18961;
v_18962:
    goto v_18963;
v_18964:
    {
        LispObject v_19097 = stack[0];
        return cons(v_19097, v_19084);
    }
v_18946:
    goto v_18997;
v_18993:
    v_19084 = stack[-4];
    v_19085 = qcar(v_19084);
    goto v_18994;
v_18995:
    v_19084 = elt(env, 2); // boolvalue!*
    goto v_18996;
v_18997:
    goto v_18993;
v_18994:
    goto v_18995;
v_18996:
    if (v_19085 == v_19084) goto v_18991;
    else goto v_18992;
v_18991:
    v_19084 = elt(env, 6); // "Too many formbools"
    {
        fn = elt(env, 14); // rederr
        return (*qfn1(fn))(fn, v_19084);
    }
v_18992:
    goto v_19009;
v_19005:
    v_19084 = stack[-4];
    v_19085 = qcar(v_19084);
    goto v_19006;
v_19007:
    v_19084 = elt(env, 7); // where
    goto v_19008;
v_19009:
    goto v_19005;
v_19006:
    goto v_19007;
v_19008:
    if (v_19085 == v_19084) goto v_19003;
    else goto v_19004;
v_19003:
    goto v_19018;
v_19014:
    stack[-5] = elt(env, 2); // boolvalue!*
    goto v_19015;
v_19016:
    goto v_19027;
v_19021:
    goto v_19035;
v_19029:
    stack[-1] = elt(env, 7); // where
    goto v_19030;
v_19031:
    goto v_19043;
v_19039:
    stack[0] = elt(env, 8); // bool!-eval
    goto v_19040;
v_19041:
    goto v_19052;
v_19046:
    v_19084 = stack[-4];
    v_19084 = qcdr(v_19084);
    v_19086 = qcar(v_19084);
    goto v_19047;
v_19048:
    v_19085 = stack[-3];
    goto v_19049;
v_19050:
    v_19084 = stack[-2];
    goto v_19051;
v_19052:
    goto v_19046;
v_19047:
    goto v_19048;
v_19049:
    goto v_19050;
v_19051:
    v_19084 = CC_formbool(elt(env, 0), 3, v_19086, v_19085, v_19084);
    env = stack[-6];
    goto v_19042;
v_19043:
    goto v_19039;
v_19040:
    goto v_19041;
v_19042:
    v_19084 = list2(stack[0], v_19084);
    env = stack[-6];
    v_19085 = Lmkquote(nil, v_19084);
    env = stack[-6];
    goto v_19032;
v_19033:
    v_19084 = stack[-4];
    v_19084 = qcdr(v_19084);
    v_19084 = qcdr(v_19084);
    v_19084 = qcar(v_19084);
    goto v_19034;
v_19035:
    goto v_19029;
v_19030:
    goto v_19031;
v_19032:
    goto v_19033;
v_19034:
    v_19086 = list3(stack[-1], v_19085, v_19084);
    env = stack[-6];
    goto v_19022;
v_19023:
    v_19085 = stack[-3];
    goto v_19024;
v_19025:
    v_19084 = stack[-2];
    goto v_19026;
v_19027:
    goto v_19021;
v_19022:
    goto v_19023;
v_19024:
    goto v_19025;
v_19026:
    fn = elt(env, 10); // formc!*
    v_19084 = (*qfnn(fn))(fn, 3, v_19086, v_19085, v_19084);
    goto v_19017;
v_19018:
    goto v_19014;
v_19015:
    goto v_19016;
v_19017:
    {
        LispObject v_19098 = stack[-5];
        return list2(v_19098, v_19084);
    }
v_19004:
    goto v_19071;
v_19067:
    stack[0] = elt(env, 2); // boolvalue!*
    goto v_19068;
v_19069:
    goto v_19080;
v_19074:
    v_19086 = stack[-4];
    goto v_19075;
v_19076:
    v_19085 = stack[-3];
    goto v_19077;
v_19078:
    v_19084 = stack[-2];
    goto v_19079;
v_19080:
    goto v_19074;
v_19075:
    goto v_19076;
v_19077:
    goto v_19078;
v_19079:
    fn = elt(env, 10); // formc!*
    v_19084 = (*qfnn(fn))(fn, 3, v_19086, v_19085, v_19084);
    goto v_19070;
v_19071:
    goto v_19067;
v_19068:
    goto v_19069;
v_19070:
    {
        LispObject v_19099 = stack[0];
        return list2(v_19099, v_19084);
    }
    v_19084 = nil;
v_18798:
    return onevalue(v_19084);
}



// Code for ofsf_lnegrel

static LispObject CC_ofsf_lnegrel(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18868, v_18869, v_18870;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18870 = v_18793;
// end of prologue
    goto v_18803;
v_18799:
    v_18869 = v_18870;
    goto v_18800;
v_18801:
    v_18868 = elt(env, 1); // equal
    goto v_18802;
v_18803:
    goto v_18799;
v_18800:
    goto v_18801;
v_18802:
    if (v_18869 == v_18868) goto v_18797;
    else goto v_18798;
v_18797:
    v_18868 = elt(env, 2); // neq
    goto v_18796;
v_18798:
    goto v_18813;
v_18809:
    v_18869 = v_18870;
    goto v_18810;
v_18811:
    v_18868 = elt(env, 2); // neq
    goto v_18812;
v_18813:
    goto v_18809;
v_18810:
    goto v_18811;
v_18812:
    if (v_18869 == v_18868) goto v_18807;
    else goto v_18808;
v_18807:
    v_18868 = elt(env, 1); // equal
    goto v_18796;
v_18808:
    goto v_18823;
v_18819:
    v_18869 = v_18870;
    goto v_18820;
v_18821:
    v_18868 = elt(env, 3); // leq
    goto v_18822;
v_18823:
    goto v_18819;
v_18820:
    goto v_18821;
v_18822:
    if (v_18869 == v_18868) goto v_18817;
    else goto v_18818;
v_18817:
    v_18868 = elt(env, 4); // greaterp
    goto v_18796;
v_18818:
    goto v_18833;
v_18829:
    v_18869 = v_18870;
    goto v_18830;
v_18831:
    v_18868 = elt(env, 5); // lessp
    goto v_18832;
v_18833:
    goto v_18829;
v_18830:
    goto v_18831;
v_18832:
    if (v_18869 == v_18868) goto v_18827;
    else goto v_18828;
v_18827:
    v_18868 = elt(env, 6); // geq
    goto v_18796;
v_18828:
    goto v_18843;
v_18839:
    v_18869 = v_18870;
    goto v_18840;
v_18841:
    v_18868 = elt(env, 6); // geq
    goto v_18842;
v_18843:
    goto v_18839;
v_18840:
    goto v_18841;
v_18842:
    if (v_18869 == v_18868) goto v_18837;
    else goto v_18838;
v_18837:
    v_18868 = elt(env, 5); // lessp
    goto v_18796;
v_18838:
    goto v_18853;
v_18849:
    v_18869 = v_18870;
    goto v_18850;
v_18851:
    v_18868 = elt(env, 4); // greaterp
    goto v_18852;
v_18853:
    goto v_18849;
v_18850:
    goto v_18851;
v_18852:
    if (v_18869 == v_18868) goto v_18847;
    else goto v_18848;
v_18847:
    v_18868 = elt(env, 3); // leq
    goto v_18796;
v_18848:
    goto v_18865;
v_18861:
    v_18868 = elt(env, 7); // "ofsf_lnegrel: unknown operator "
    goto v_18862;
v_18863:
    v_18869 = v_18870;
    goto v_18864;
v_18865:
    goto v_18861;
v_18862:
    goto v_18863;
v_18864:
    v_18868 = list2(v_18868, v_18869);
    env = stack[0];
    {
        fn = elt(env, 8); // rederr
        return (*qfn1(fn))(fn, v_18868);
    }
    v_18868 = nil;
v_18796:
    return onevalue(v_18868);
}



// Code for multdfconst

static LispObject CC_multdfconst(LispObject env,
                         LispObject v_18793, LispObject v_18794)
{
    env = qenv(env);
    LispObject v_18844, v_18845;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18794,v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18793,v_18794);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_18794;
    stack[-2] = v_18793;
// end of prologue
    stack[-3] = nil;
v_18799:
    v_18844 = stack[-1];
    if (v_18844 == nil) goto v_18806;
    else goto v_18807;
v_18806:
    v_18844 = lisp_true;
    goto v_18805;
v_18807:
    v_18844 = stack[-2];
    v_18844 = qcar(v_18844);
    v_18844 = (v_18844 == nil ? lisp_true : nil);
    goto v_18805;
    v_18844 = nil;
v_18805:
    if (v_18844 == nil) goto v_18803;
    v_18844 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_18844);
    }
v_18803:
    goto v_18826;
v_18820:
    v_18844 = stack[-1];
    v_18844 = qcar(v_18844);
    stack[0] = qcar(v_18844);
    goto v_18821;
v_18822:
    goto v_18836;
v_18832:
    v_18845 = stack[-2];
    goto v_18833;
v_18834:
    v_18844 = stack[-1];
    v_18844 = qcar(v_18844);
    v_18844 = qcdr(v_18844);
    goto v_18835;
v_18836:
    goto v_18832;
v_18833:
    goto v_18834;
v_18835:
    fn = elt(env, 2); // multsq
    v_18844 = (*qfn2(fn))(fn, v_18845, v_18844);
    env = stack[-4];
    fn = elt(env, 3); // subs2q
    v_18845 = (*qfn1(fn))(fn, v_18844);
    env = stack[-4];
    goto v_18823;
v_18824:
    v_18844 = stack[-3];
    goto v_18825;
v_18826:
    goto v_18820;
v_18821:
    goto v_18822;
v_18823:
    goto v_18824;
v_18825:
    v_18844 = acons(stack[0], v_18845, v_18844);
    env = stack[-4];
    stack[-3] = v_18844;
    v_18844 = stack[-1];
    v_18844 = qcdr(v_18844);
    stack[-1] = v_18844;
    goto v_18799;
    v_18844 = nil;
    return onevalue(v_18844);
}



// Code for sets

static LispObject CC_sets(LispObject env,
                         LispObject v_18793, LispObject v_18794)
{
    env = qenv(env);
    LispObject v_18822, v_18823;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18794,v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18793,v_18794);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18794;
    stack[-1] = v_18793;
// end of prologue
    v_18822 = elt(env, 1); // "<apply>"
    fn = elt(env, 5); // printout
    v_18822 = (*qfn1(fn))(fn, v_18822);
    env = stack[-2];
    v_18822 = elt(env, 2); // "<"
    v_18822 = Lprinc(nil, v_18822);
    env = stack[-2];
    v_18822 = stack[0];
    v_18822 = Lprinc(nil, v_18822);
    env = stack[-2];
    goto v_18809;
v_18805:
    v_18822 = stack[-1];
    v_18823 = qcar(v_18822);
    goto v_18806;
v_18807:
    v_18822 = elt(env, 3); // "/"
    goto v_18808;
v_18809:
    goto v_18805;
v_18806:
    goto v_18807;
v_18808:
    fn = elt(env, 6); // attributesml
    v_18822 = (*qfn2(fn))(fn, v_18823, v_18822);
    env = stack[-2];
    v_18822 = lisp_true;
    fn = elt(env, 7); // indent!*
    v_18822 = (*qfn1(fn))(fn, v_18822);
    env = stack[-2];
    v_18822 = stack[-1];
    v_18822 = qcdr(v_18822);
    fn = elt(env, 8); // multi_elem
    v_18822 = (*qfn1(fn))(fn, v_18822);
    env = stack[-2];
    v_18822 = nil;
    fn = elt(env, 7); // indent!*
    v_18822 = (*qfn1(fn))(fn, v_18822);
    env = stack[-2];
    v_18822 = elt(env, 4); // "</apply>"
    fn = elt(env, 5); // printout
    v_18822 = (*qfn1(fn))(fn, v_18822);
    v_18822 = nil;
    return onevalue(v_18822);
}



// Code for alg_plus

static LispObject CC_alg_plus(LispObject env,
                         LispObject v_18793, LispObject v_18794)
{
    env = qenv(env);
    LispObject v_18810, v_18811, v_18812;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18794,v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18793,v_18794);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18810 = v_18794;
    v_18811 = v_18793;
// end of prologue
    goto v_18806;
v_18800:
    v_18812 = elt(env, 1); // plus
    goto v_18801;
v_18802:
    goto v_18803;
v_18804:
    goto v_18805;
v_18806:
    goto v_18800;
v_18801:
    goto v_18802;
v_18803:
    goto v_18804;
v_18805:
    v_18810 = list3(v_18812, v_18811, v_18810);
    env = stack[0];
    {
        fn = elt(env, 2); // aeval
        return (*qfn1(fn))(fn, v_18810);
    }
    return onevalue(v_18810);
}



// Code for evaluate!-horner

static LispObject CC_evaluateKhorner(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18840, v_18841, v_18842;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_18793;
// end of prologue
    goto v_18799;
v_18795:
    v_18841 = stack[-1];
    goto v_18796;
v_18797:
    v_18840 = qvalue(elt(env, 1)); // horner!-cache!*
    goto v_18798;
v_18799:
    goto v_18795;
v_18796:
    goto v_18797;
v_18798:
    v_18840 = Lassoc(nil, v_18841, v_18840);
    stack[-2] = v_18840;
    v_18840 = stack[-2];
    if (v_18840 == nil) goto v_18807;
    v_18840 = stack[-2];
    v_18840 = qcdr(v_18840);
    goto v_18805;
v_18807:
    v_18840 = stack[-1];
    fn = elt(env, 2); // simp!*
    v_18840 = (*qfn1(fn))(fn, v_18840);
    env = stack[-3];
    stack[-2] = v_18840;
    goto v_18821;
v_18817:
    v_18840 = stack[-2];
    v_18840 = qcar(v_18840);
    fn = elt(env, 3); // hornerf
    stack[0] = (*qfn1(fn))(fn, v_18840);
    env = stack[-3];
    goto v_18818;
v_18819:
    v_18840 = stack[-2];
    v_18840 = qcdr(v_18840);
    fn = elt(env, 3); // hornerf
    v_18840 = (*qfn1(fn))(fn, v_18840);
    env = stack[-3];
    goto v_18820;
v_18821:
    goto v_18817;
v_18818:
    goto v_18819;
v_18820:
    v_18840 = cons(stack[0], v_18840);
    env = stack[-3];
    fn = elt(env, 4); // prepsq
    v_18840 = (*qfn1(fn))(fn, v_18840);
    env = stack[-3];
    stack[-2] = v_18840;
    goto v_18835;
v_18829:
    v_18842 = stack[-1];
    goto v_18830;
v_18831:
    v_18841 = stack[-2];
    goto v_18832;
v_18833:
    v_18840 = qvalue(elt(env, 1)); // horner!-cache!*
    goto v_18834;
v_18835:
    goto v_18829;
v_18830:
    goto v_18831;
v_18832:
    goto v_18833;
v_18834:
    v_18840 = acons(v_18842, v_18841, v_18840);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_18840; // horner!-cache!*
    v_18840 = stack[-2];
    goto v_18805;
    v_18840 = nil;
v_18805:
    return onevalue(v_18840);
}



// Code for lispreadp

static LispObject CC_lispreadp(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18803, v_18804;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18803 = v_18793;
// end of prologue
    goto v_18800;
v_18796:
    goto v_18797;
v_18798:
    v_18804 = elt(env, 1); // read
    goto v_18799;
v_18800:
    goto v_18796;
v_18797:
    goto v_18798;
v_18799:
        return Leqcar(nil, v_18803, v_18804);
}



// Code for indexsymmetrize

static LispObject CC_indexsymmetrize(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18866, v_18867, v_18868;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_18793;
// end of prologue
    goto v_18807;
v_18803:
    v_18866 = stack[-2];
    v_18867 = qcar(v_18866);
    goto v_18804;
v_18805:
    v_18866 = elt(env, 1); // indxsymmetrize
    goto v_18806;
v_18807:
    goto v_18803;
v_18804:
    goto v_18805;
v_18806:
    v_18866 = get(v_18867, v_18866);
    env = stack[-4];
    stack[-3] = v_18866;
    v_18866 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_18866;
    goto v_18817;
v_18813:
    v_18867 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18814;
v_18815:
    v_18866 = stack[-2];
    v_18866 = qcdr(v_18866);
    goto v_18816;
v_18817:
    goto v_18813;
v_18814:
    goto v_18815;
v_18816:
    v_18866 = cons(v_18867, v_18866);
    env = stack[-4];
    stack[-1] = v_18866;
v_18800:
    v_18866 = stack[-3];
    if (v_18866 == nil) goto v_18823;
    else goto v_18824;
v_18823:
    goto v_18833;
v_18827:
    v_18868 = stack[0];
    goto v_18828;
v_18829:
    v_18866 = stack[-2];
    v_18867 = qcar(v_18866);
    goto v_18830;
v_18831:
    v_18866 = stack[-1];
    v_18866 = qcdr(v_18866);
    goto v_18832;
v_18833:
    goto v_18827;
v_18828:
    goto v_18829;
v_18830:
    goto v_18831;
v_18832:
    return list2star(v_18868, v_18867, v_18866);
v_18824:
    goto v_18844;
v_18840:
    v_18866 = stack[-3];
    v_18867 = qcar(v_18866);
    goto v_18841;
v_18842:
    v_18866 = stack[-1];
    v_18866 = qcdr(v_18866);
    goto v_18843;
v_18844:
    goto v_18840;
v_18841:
    goto v_18842;
v_18843:
    v_18866 = Lapply1(nil, v_18867, v_18866);
    env = stack[-4];
    stack[-1] = v_18866;
    v_18866 = stack[-1];
    if (v_18866 == nil) goto v_18851;
    else goto v_18852;
v_18851:
    v_18866 = nil;
    goto v_18799;
v_18852:
    goto v_18860;
v_18856:
    v_18866 = stack[-1];
    v_18867 = qcar(v_18866);
    goto v_18857;
v_18858:
    v_18866 = stack[0];
    goto v_18859;
v_18860:
    goto v_18856;
v_18857:
    goto v_18858;
v_18859:
    v_18866 = times2(v_18867, v_18866);
    env = stack[-4];
    stack[0] = v_18866;
    v_18866 = stack[-3];
    v_18866 = qcdr(v_18866);
    stack[-3] = v_18866;
    goto v_18800;
v_18799:
    return onevalue(v_18866);
}



// Code for s_actual_world1

static LispObject CC_s_actual_world1(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18799;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18799 = v_18793;
// end of prologue
    v_18799 = qcar(v_18799);
    v_18799 = qcar(v_18799);
    v_18799 = qcar(v_18799);
    return onevalue(v_18799);
}



// Code for lex_skip_line_comment

static LispObject CC_lex_skip_line_comment(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18826, v_18827;
    LispObject fn;
    argcheck(nargs, 0, "lex_skip_line_comment");
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
v_18796:
    goto v_18809;
v_18805:
    v_18827 = qvalue(elt(env, 1)); // lex_char
    goto v_18806;
v_18807:
    v_18826 = qvalue(elt(env, 2)); // !$eol!$
    goto v_18808;
v_18809:
    goto v_18805;
v_18806:
    goto v_18807;
v_18808:
    if (equal(v_18827, v_18826)) goto v_18803;
    else goto v_18804;
v_18803:
    v_18826 = lisp_true;
    goto v_18802;
v_18804:
    goto v_18819;
v_18815:
    v_18827 = qvalue(elt(env, 1)); // lex_char
    goto v_18816;
v_18817:
    v_18826 = qvalue(elt(env, 3)); // !$eof!$
    goto v_18818;
v_18819:
    goto v_18815;
v_18816:
    goto v_18817;
v_18818:
    v_18826 = (equal(v_18827, v_18826) ? lisp_true : nil);
    goto v_18802;
    v_18826 = nil;
v_18802:
    if (v_18826 == nil) goto v_18800;
    goto v_18795;
v_18800:
    fn = elt(env, 4); // yyreadch
    v_18826 = (*qfnn(fn))(fn, 0);
    env = stack[0];
    goto v_18796;
v_18795:
    v_18826 = lisp_true;
    return onevalue(v_18826);
}



// Code for profile_a_package

static LispObject CC_profile_a_package(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_19533, v_19534, v_19535, v_19536, v_19537;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_18793;
// end of prologue
// Binding !*errcont
// FLUIDBIND: reloadenv=9 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-9, 1, -2);
    qvalue(elt(env, 1)) = nil; // !*errcont
    v_19533 = elt(env, 2); // cpulimit
    v_19533 = Lboundp(nil, v_19533);
    env = stack[-9];
    if (v_19533 == nil) goto v_18811;
    else goto v_18812;
v_18811:
    v_19533 = lisp_true;
    goto v_18810;
v_18812:
    v_19533 = qvalue(elt(env, 2)); // cpulimit
    v_19533 = Lexplodec(nil, v_19533);
    env = stack[-9];
    v_19533 = Lcompress(nil, v_19533);
    env = stack[-9];
    qvalue(elt(env, 2)) = v_19533; // cpulimit
    v_19533 = integerp(v_19533);
    if (v_19533 == nil) goto v_18820;
    else goto v_18821;
v_18820:
    v_19533 = lisp_true;
    goto v_18819;
v_18821:
    goto v_18834;
v_18830:
    v_19534 = qvalue(elt(env, 2)); // cpulimit
    goto v_18831;
v_18832:
    v_19533 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18833;
v_18834:
    goto v_18830;
v_18831:
    goto v_18832;
v_18833:
    v_19533 = (LispObject)lessp2(v_19534, v_19533);
    v_19533 = v_19533 ? lisp_true : nil;
    env = stack[-9];
    goto v_18819;
    v_19533 = nil;
v_18819:
    goto v_18810;
    v_19533 = nil;
v_18810:
    if (v_19533 == nil) goto v_18808;
    goto v_18845;
v_18841:
    v_19534 = elt(env, 3); // jlisp
    goto v_18842;
v_18843:
    v_19533 = qvalue(elt(env, 4)); // lispsystem!*
    goto v_18844;
v_18845:
    goto v_18841;
v_18842:
    goto v_18843;
v_18844:
    v_19533 = Lmemq(nil, v_19534, v_19533);
    if (v_19533 == nil) goto v_18840;
    v_19533 = (LispObject)80000+TAG_FIXNUM; // 5000
    goto v_18838;
v_18840:
    v_19533 = (LispObject)2880+TAG_FIXNUM; // 180
    goto v_18838;
    v_19533 = nil;
v_18838:
    qvalue(elt(env, 2)) = v_19533; // cpulimit
    goto v_18806;
v_18808:
v_18806:
    v_19533 = elt(env, 5); // conslimit
    v_19533 = Lboundp(nil, v_19533);
    env = stack[-9];
    if (v_19533 == nil) goto v_18859;
    else goto v_18860;
v_18859:
    v_19533 = lisp_true;
    goto v_18858;
v_18860:
    v_19533 = qvalue(elt(env, 5)); // conslimit
    v_19533 = Lexplodec(nil, v_19533);
    env = stack[-9];
    v_19533 = Lcompress(nil, v_19533);
    env = stack[-9];
    qvalue(elt(env, 5)) = v_19533; // conslimit
    v_19533 = integerp(v_19533);
    if (v_19533 == nil) goto v_18868;
    else goto v_18869;
v_18868:
    v_19533 = lisp_true;
    goto v_18867;
v_18869:
    goto v_18882;
v_18878:
    v_19534 = qvalue(elt(env, 5)); // conslimit
    goto v_18879;
v_18880:
    v_19533 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18881;
v_18882:
    goto v_18878;
v_18879:
    goto v_18880;
v_18881:
    v_19533 = (LispObject)lessp2(v_19534, v_19533);
    v_19533 = v_19533 ? lisp_true : nil;
    env = stack[-9];
    goto v_18867;
    v_19533 = nil;
v_18867:
    goto v_18858;
    v_19533 = nil;
v_18858:
    if (v_19533 == nil) goto v_18856;
    v_19533 = (LispObject)32000+TAG_FIXNUM; // 2000
    qvalue(elt(env, 5)) = v_19533; // conslimit
    goto v_18854;
v_18856:
v_18854:
    v_19533 = elt(env, 6); // "PROFILING: "
    v_19533 = Lprinc(nil, v_19533);
    env = stack[-9];
    v_19533 = stack[-7];
    v_19533 = qcar(v_19533);
    v_19533 = Lprint(nil, v_19533);
    env = stack[-9];
    v_19533 = nil;
    qvalue(elt(env, 7)) = v_19533; // !*backtrace
    v_19533 = lisp_true;
    qvalue(elt(env, 1)) = v_19533; // !*errcont
    v_19533 = nil;
    qvalue(elt(env, 8)) = v_19533; // !*int
    v_19533 = stack[-7];
    v_19533 = qcar(v_19533);
    stack[-8] = v_19533;
    v_19533 = nil;
    v_19533 = Lverbos(nil, v_19533);
    env = stack[-9];
    fn = elt(env, 53); // get_configuration_data
    v_19533 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    goto v_18907;
v_18903:
    v_19534 = stack[-8];
    goto v_18904;
v_18905:
    v_19533 = qvalue(elt(env, 9)); // reduce_regression_tests
    goto v_18906;
v_18907:
    goto v_18903;
v_18904:
    goto v_18905;
v_18906:
    v_19533 = Lmemq(nil, v_19534, v_19533);
    if (v_19533 == nil) goto v_18901;
    else goto v_18902;
v_18901:
    v_19533 = stack[-8];
    fn = elt(env, 54); // load!-package
    v_19533 = (*qfn1(fn))(fn, v_19533);
    env = stack[-9];
    goto v_18922;
v_18918:
    v_19534 = stack[-8];
    goto v_18919;
v_18920:
    v_19533 = elt(env, 10); // folder
    goto v_18921;
v_18922:
    goto v_18918;
v_18919:
    goto v_18920;
v_18921:
    v_19533 = get(v_19534, v_19533);
    env = stack[-9];
    if (v_19533 == nil) goto v_18916;
    goto v_18930;
v_18926:
    v_19534 = stack[-8];
    goto v_18927;
v_18928:
    v_19533 = elt(env, 10); // folder
    goto v_18929;
v_18930:
    goto v_18926;
v_18927:
    goto v_18928;
v_18929:
    v_19533 = get(v_19534, v_19533);
    env = stack[-9];
    stack[-8] = v_19533;
    goto v_18914;
v_18916:
v_18914:
    goto v_18938;
v_18934:
    v_19534 = elt(env, 11); // "$reduce/packages/"
    goto v_18935;
v_18936:
    v_19533 = stack[-8];
    goto v_18937;
v_18938:
    goto v_18934;
v_18935:
    goto v_18936;
v_18937:
    fn = elt(env, 55); // concat
    v_19533 = (*qfn2(fn))(fn, v_19534, v_19533);
    env = stack[-9];
    qvalue(elt(env, 12)) = v_19533; // testdirectory
    goto v_18946;
v_18942:
    stack[-1] = elt(env, 11); // "$reduce/packages/"
    goto v_18943;
v_18944:
    goto v_18953;
v_18949:
    stack[-3] = stack[-8];
    goto v_18950;
v_18951:
    goto v_18960;
v_18956:
    stack[0] = elt(env, 13); // "/"
    goto v_18957;
v_18958:
    goto v_18967;
v_18963:
    v_19533 = stack[-7];
    v_19534 = qcar(v_19533);
    goto v_18964;
v_18965:
    v_19533 = elt(env, 14); // ".tst"
    goto v_18966;
v_18967:
    goto v_18963;
v_18964:
    goto v_18965;
v_18966:
    fn = elt(env, 55); // concat
    v_19533 = (*qfn2(fn))(fn, v_19534, v_19533);
    env = stack[-9];
    goto v_18959;
v_18960:
    goto v_18956;
v_18957:
    goto v_18958;
v_18959:
    fn = elt(env, 55); // concat
    v_19533 = (*qfn2(fn))(fn, stack[0], v_19533);
    env = stack[-9];
    goto v_18952;
v_18953:
    goto v_18949;
v_18950:
    goto v_18951;
v_18952:
    fn = elt(env, 55); // concat
    v_19533 = (*qfn2(fn))(fn, stack[-3], v_19533);
    env = stack[-9];
    goto v_18945;
v_18946:
    goto v_18942;
v_18943:
    goto v_18944;
v_18945:
    fn = elt(env, 55); // concat
    v_19533 = (*qfn2(fn))(fn, stack[-1], v_19533);
    env = stack[-9];
    stack[-8] = v_19533;
    v_19533 = (LispObject)1280+TAG_FIXNUM; // 80
    v_19533 = Llinelength(nil, v_19533);
    env = stack[-9];
    stack[-6] = v_19533;
    v_19533 = nil;
    v_19533 = ncons(v_19533);
    env = stack[-9];
    qvalue(elt(env, 15)) = v_19533; // alglist!*
    v_19533 = elt(env, 16); // algebraic
    qvalue(elt(env, 17)) = v_19533; // !*mode
    goto v_18983;
v_18979:
    v_19533 = elt(env, 18); // "[Profile] "
    stack[0] = Lexplodec(nil, v_19533);
    env = stack[-9];
    goto v_18980;
v_18981:
    v_19533 = stack[-7];
    v_19533 = qcar(v_19533);
    v_19533 = Lexplodec(nil, v_19533);
    env = stack[-9];
    goto v_18982;
v_18983:
    goto v_18979;
v_18980:
    goto v_18981;
v_18982:
    v_19533 = Lappend(nil, stack[0], v_19533);
    env = stack[-9];
    fn = elt(env, 56); // list!-to!-string
    v_19533 = (*qfn1(fn))(fn, v_19533);
    env = stack[-9];
    fn = elt(env, 57); // window!-heading
    v_19533 = (*qfn1(fn))(fn, v_19533);
    env = stack[-9];
    v_19533 = elt(env, 19); // quit
    fn = elt(env, 58); // getd
    v_19533 = (*qfn1(fn))(fn, v_19533);
    env = stack[-9];
    stack[-3] = v_19533;
    v_19533 = elt(env, 19); // quit
    v_19533 = Lremd(nil, v_19533);
    env = stack[-9];
    goto v_19000;
v_18994:
    v_19535 = elt(env, 19); // quit
    goto v_18995;
v_18996:
    v_19534 = elt(env, 20); // expr
    goto v_18997;
v_18998:
    v_19533 = elt(env, 21); // posn
    goto v_18999;
v_19000:
    goto v_18994;
v_18995:
    goto v_18996;
v_18997:
    goto v_18998;
v_18999:
    fn = elt(env, 59); // putd
    v_19533 = (*qfnn(fn))(fn, 3, v_19535, v_19534, v_19533);
    env = stack[-9];
    v_19533 = (LispObject)64+TAG_FIXNUM; // 4
    v_19533 = Lmapstore(nil, v_19533);
    env = stack[-9];
    v_19533 = lisp_true;
    qvalue(elt(env, 1)) = v_19533; // !*errcont
    v_19533 = nil;
    v_19533 = Lwrs(nil, v_19533);
    env = stack[-9];
    stack[-5] = v_19533;
    v_19533 = nil;
    v_19533 = Lrds(nil, v_19533);
    env = stack[-9];
    stack[-4] = v_19533;
    v_19533 = stack[-5];
    v_19533 = Lwrs(nil, v_19533);
    env = stack[-9];
    v_19533 = stack[-4];
    v_19533 = Lrds(nil, v_19533);
    env = stack[-9];
    goto v_19026;
v_19016:
    goto v_19036;
v_19028:
    stack[-1] = elt(env, 22); // errorset
    goto v_19029;
v_19030:
    goto v_19046;
v_19040:
    stack[0] = elt(env, 23); // in_list1
    goto v_19041;
v_19042:
    v_19533 = stack[-8];
    v_19534 = Lmkquote(nil, v_19533);
    env = stack[-9];
    goto v_19043;
v_19044:
    v_19533 = lisp_true;
    goto v_19045;
v_19046:
    goto v_19040;
v_19041:
    goto v_19042;
v_19043:
    goto v_19044;
v_19045:
    v_19533 = list3(stack[0], v_19534, v_19533);
    env = stack[-9];
    v_19535 = Lmkquote(nil, v_19533);
    env = stack[-9];
    goto v_19031;
v_19032:
    v_19534 = nil;
    goto v_19033;
v_19034:
    v_19533 = nil;
    goto v_19035;
v_19036:
    goto v_19028;
v_19029:
    goto v_19030;
v_19031:
    goto v_19032;
v_19033:
    goto v_19034;
v_19035:
    v_19537 = list4(stack[-1], v_19535, v_19534, v_19533);
    env = stack[-9];
    goto v_19017;
v_19018:
    v_19536 = qvalue(elt(env, 2)); // cpulimit
    goto v_19019;
v_19020:
    v_19535 = qvalue(elt(env, 5)); // conslimit
    goto v_19021;
v_19022:
    v_19534 = (LispObject)160000+TAG_FIXNUM; // 10000
    goto v_19023;
v_19024:
    v_19533 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_19025;
v_19026:
    goto v_19016;
v_19017:
    goto v_19018;
v_19019:
    goto v_19020;
v_19021:
    goto v_19022;
v_19023:
    goto v_19024;
v_19025:
    fn = elt(env, 60); // resource!-limit
    v_19533 = (*qfnn(fn))(fn, 5, v_19537, v_19536, v_19535, v_19534, v_19533);
    env = stack[-9];
    stack[0] = v_19533;
    v_19533 = stack[-5];
    v_19533 = Lwrs(nil, v_19533);
    env = stack[-9];
    v_19533 = stack[-4];
    v_19533 = Lrds(nil, v_19533);
    env = stack[-9];
    v_19533 = nil;
    qvalue(elt(env, 24)) = v_19533; // erfg!*
    v_19533 = Lterpri(nil, 0);
    env = stack[-9];
    goto v_19070;
v_19064:
    v_19535 = elt(env, 19); // quit
    goto v_19065;
v_19066:
    v_19533 = stack[-3];
    v_19534 = qcar(v_19533);
    goto v_19067;
v_19068:
    v_19533 = stack[-3];
    v_19533 = qcdr(v_19533);
    goto v_19069;
v_19070:
    goto v_19064;
v_19065:
    goto v_19066;
v_19067:
    goto v_19068;
v_19069:
    fn = elt(env, 59); // putd
    v_19533 = (*qfnn(fn))(fn, 3, v_19535, v_19534, v_19533);
    env = stack[-9];
    goto v_19081;
v_19077:
    v_19533 = (LispObject)32+TAG_FIXNUM; // 2
    v_19534 = Lmapstore(nil, v_19533);
    env = stack[-9];
    goto v_19078;
v_19079:
    v_19533 = elt(env, 25); // profile_compare_fn
    goto v_19080;
v_19081:
    goto v_19077;
v_19078:
    goto v_19079;
v_19080:
    fn = elt(env, 61); // sort
    v_19533 = (*qfn2(fn))(fn, v_19534, v_19533);
    env = stack[-9];
    stack[-5] = v_19533;
    goto v_19094;
v_19090:
    v_19534 = elt(env, 26); // "buildlogs/flaguse.log"
    goto v_19091;
v_19092:
    v_19533 = elt(env, 27); // append
    goto v_19093;
v_19094:
    goto v_19090;
v_19091:
    goto v_19092;
v_19093:
    fn = elt(env, 62); // open
    v_19533 = (*qfn2(fn))(fn, v_19534, v_19533);
    env = stack[-9];
    v_19533 = Lwrs(nil, v_19533);
    env = stack[-9];
    stack[-1] = v_19533;
    v_19533 = lisp_true;
    fn = elt(env, 63); // bytecounts
    v_19533 = (*qfn1(fn))(fn, v_19533);
    env = stack[-9];
    v_19533 = stack[-1];
    v_19533 = Lwrs(nil, v_19533);
    env = stack[-9];
    v_19533 = Lclose(nil, v_19533);
    env = stack[-9];
    fn = elt(env, 64); // load!-source
    v_19533 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    v_19533 = nil;
    stack[-4] = v_19533;
v_19106:
    v_19533 = stack[-5];
    if (v_19533 == nil) goto v_19109;
    else goto v_19110;
v_19109:
    goto v_19105;
v_19110:
    goto v_19118;
v_19114:
    v_19533 = stack[-5];
    v_19533 = qcar(v_19533);
    v_19534 = qcar(v_19533);
    goto v_19115;
v_19116:
    v_19533 = elt(env, 28); // !*savedef
    goto v_19117;
v_19118:
    goto v_19114;
v_19115:
    goto v_19116;
v_19117:
    v_19533 = get(v_19534, v_19533);
    env = stack[-9];
    v_19535 = v_19533;
    goto v_19132;
v_19128:
    v_19534 = v_19535;
    goto v_19129;
v_19130:
    v_19533 = elt(env, 29); // lambda
    goto v_19131;
v_19132:
    goto v_19128;
v_19129:
    goto v_19130;
v_19131:
    if (!consp(v_19534)) goto v_19126;
    v_19534 = qcar(v_19534);
    if (v_19534 == v_19533) goto v_19125;
    else goto v_19126;
v_19125:
    goto v_19142;
v_19136:
    v_19533 = stack[-5];
    v_19533 = qcar(v_19533);
    stack[-1] = qcar(v_19533);
    goto v_19137;
v_19138:
    goto v_19153;
v_19147:
    goto v_19160;
v_19156:
    v_19533 = stack[-5];
    v_19533 = qcar(v_19533);
    v_19533 = qcar(v_19533);
    goto v_19157;
v_19158:
    v_19534 = v_19535;
    v_19534 = qcdr(v_19534);
    goto v_19159;
v_19160:
    goto v_19156;
v_19157:
    goto v_19158;
v_19159:
    v_19533 = cons(v_19533, v_19534);
    env = stack[-9];
    fn = elt(env, 65); // md60
    v_19535 = (*qfn1(fn))(fn, v_19533);
    env = stack[-9];
    goto v_19148;
v_19149:
    v_19533 = stack[-5];
    v_19533 = qcar(v_19533);
    v_19533 = qcdr(v_19533);
    v_19534 = qcar(v_19533);
    goto v_19150;
v_19151:
    v_19533 = stack[-5];
    v_19533 = qcar(v_19533);
    v_19533 = qcdr(v_19533);
    v_19533 = qcdr(v_19533);
    v_19533 = qcar(v_19533);
    goto v_19152;
v_19153:
    goto v_19147;
v_19148:
    goto v_19149;
v_19150:
    goto v_19151;
v_19152:
    v_19534 = list2star(v_19535, v_19534, v_19533);
    env = stack[-9];
    goto v_19139;
v_19140:
    v_19533 = stack[-4];
    goto v_19141;
v_19142:
    goto v_19136;
v_19137:
    goto v_19138;
v_19139:
    goto v_19140;
v_19141:
    v_19533 = acons(stack[-1], v_19534, v_19533);
    env = stack[-9];
    stack[-4] = v_19533;
    goto v_19124;
v_19126:
v_19124:
    v_19533 = stack[-5];
    v_19533 = qcdr(v_19533);
    stack[-5] = v_19533;
    goto v_19106;
v_19105:
    v_19533 = stack[-4];
    stack[-5] = v_19533;
    v_19533 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_19533;
v_19182:
    goto v_19194;
v_19190:
    v_19534 = (LispObject)5584+TAG_FIXNUM; // 349
    goto v_19191;
v_19192:
    v_19533 = stack[-1];
    goto v_19193;
v_19194:
    goto v_19190;
v_19191:
    goto v_19192;
v_19193:
    v_19533 = difference2(v_19534, v_19533);
    env = stack[-9];
    v_19533 = Lminusp(nil, v_19533);
    env = stack[-9];
    if (v_19533 == nil) goto v_19187;
    goto v_19181;
v_19187:
    v_19533 = stack[-4];
    if (v_19533 == nil) goto v_19201;
    v_19533 = stack[-4];
    v_19533 = qcdr(v_19533);
    stack[-4] = v_19533;
    goto v_19199;
v_19201:
v_19199:
    v_19533 = stack[-1];
    v_19533 = add1(v_19533);
    env = stack[-9];
    stack[-1] = v_19533;
    goto v_19182;
v_19181:
    v_19533 = stack[-4];
    if (v_19533 == nil) goto v_19210;
    goto v_19217;
v_19213:
    v_19534 = stack[-4];
    goto v_19214;
v_19215:
    v_19533 = nil;
    goto v_19216;
v_19217:
    goto v_19213;
v_19214:
    goto v_19215;
v_19216:
    v_19533 = Lrplacd(nil, v_19534, v_19533);
    env = stack[-9];
    goto v_19208;
v_19210:
v_19208:
    goto v_19225;
v_19221:
    v_19534 = elt(env, 30); // "profile.dat"
    goto v_19222;
v_19223:
    v_19533 = elt(env, 27); // append
    goto v_19224;
v_19225:
    goto v_19221;
v_19222:
    goto v_19223;
v_19224:
    fn = elt(env, 62); // open
    v_19533 = (*qfn2(fn))(fn, v_19534, v_19533);
    env = stack[-9];
    stack[-4] = v_19533;
    v_19533 = stack[-4];
    v_19533 = Lwrs(nil, v_19533);
    env = stack[-9];
    stack[-4] = v_19533;
    v_19533 = (LispObject)1280+TAG_FIXNUM; // 80
    v_19533 = Llinelength(nil, v_19533);
    env = stack[-9];
    v_19533 = stack[0];
    if (!consp(v_19533)) goto v_19234;
    else goto v_19235;
v_19234:
    v_19533 = elt(env, 31); // "% +++++ Error: Resource limit exceeded"
    v_19533 = Lprintc(nil, v_19533);
    env = stack[-9];
    goto v_19233;
v_19235:
v_19233:
    v_19533 = elt(env, 32); // "% @@@@@ Resources used: "
    v_19533 = Lprinc(nil, v_19533);
    env = stack[-9];
    v_19533 = qvalue(elt(env, 33)); // !*resources!*
    v_19533 = Lprint(nil, v_19533);
    env = stack[-9];
    v_19533 = elt(env, 34); // "("
    v_19533 = Lprinc(nil, v_19533);
    env = stack[-9];
    v_19533 = stack[-7];
    v_19533 = qcar(v_19533);
    v_19533 = Lprin(nil, v_19533);
    env = stack[-9];
    v_19533 = Lterpri(nil, 0);
    env = stack[-9];
    v_19533 = stack[-5];
    stack[-1] = v_19533;
v_19252:
    v_19533 = stack[-1];
    if (v_19533 == nil) goto v_19256;
    else goto v_19257;
v_19256:
    goto v_19251;
v_19257:
    v_19533 = stack[-1];
    v_19533 = qcar(v_19533);
    stack[0] = v_19533;
    v_19533 = elt(env, 35); // "  ("
    v_19533 = Lprinc(nil, v_19533);
    env = stack[-9];
    v_19533 = stack[0];
    v_19533 = qcar(v_19533);
    v_19533 = Lprin(nil, v_19533);
    env = stack[-9];
    v_19533 = elt(env, 36); // " "
    v_19533 = Lprinc(nil, v_19533);
    env = stack[-9];
    goto v_19279;
v_19275:
    v_19534 = Lposn(nil, 0);
    env = stack[-9];
    goto v_19276;
v_19277:
    v_19533 = (LispObject)480+TAG_FIXNUM; // 30
    goto v_19278;
v_19279:
    goto v_19275;
v_19276:
    goto v_19277;
v_19278:
    v_19533 = (LispObject)greaterp2(v_19534, v_19533);
    v_19533 = v_19533 ? lisp_true : nil;
    env = stack[-9];
    if (v_19533 == nil) goto v_19273;
    v_19533 = Lterpri(nil, 0);
    env = stack[-9];
    v_19533 = (LispObject)480+TAG_FIXNUM; // 30
    v_19533 = Lttab(nil, v_19533);
    env = stack[-9];
    goto v_19271;
v_19273:
v_19271:
    v_19533 = stack[0];
    v_19533 = qcdr(v_19533);
    v_19533 = qcar(v_19533);
    v_19533 = Lprin(nil, v_19533);
    env = stack[-9];
    v_19533 = elt(env, 36); // " "
    v_19533 = Lprinc(nil, v_19533);
    env = stack[-9];
    v_19533 = stack[0];
    v_19533 = qcdr(v_19533);
    v_19533 = qcdr(v_19533);
    v_19533 = qcar(v_19533);
    v_19533 = Lprin(nil, v_19533);
    env = stack[-9];
    v_19533 = elt(env, 36); // " "
    v_19533 = Lprinc(nil, v_19533);
    env = stack[-9];
    v_19533 = stack[0];
    v_19533 = qcdr(v_19533);
    v_19533 = qcdr(v_19533);
    v_19533 = qcdr(v_19533);
    v_19533 = Lprinc(nil, v_19533);
    env = stack[-9];
    v_19533 = elt(env, 37); // ")"
    v_19533 = Lprintc(nil, v_19533);
    env = stack[-9];
    v_19533 = stack[-1];
    v_19533 = qcdr(v_19533);
    stack[-1] = v_19533;
    goto v_19252;
v_19251:
    v_19533 = elt(env, 38); // "  )"
    v_19533 = Lprintc(nil, v_19533);
    env = stack[-9];
    v_19533 = Lterpri(nil, 0);
    env = stack[-9];
    v_19533 = stack[-4];
    v_19533 = Lwrs(nil, v_19533);
    env = stack[-9];
    v_19533 = Lclose(nil, v_19533);
    env = stack[-9];
    v_19533 = stack[-6];
    v_19533 = Llinelength(nil, v_19533);
    env = stack[-9];
    goto v_18900;
v_18902:
v_18900:
    v_19533 = stack[-7];
    v_19533 = qcdr(v_19533);
    stack[-7] = v_19533;
    v_19533 = stack[-7];
    if (v_19533 == nil) goto v_19319;
    else goto v_19320;
v_19319:
    goto v_19327;
v_19323:
    v_19534 = elt(env, 26); // "buildlogs/flaguse.log"
    goto v_19324;
v_19325:
    v_19533 = elt(env, 39); // input
    goto v_19326;
v_19327:
    goto v_19323;
v_19324:
    goto v_19325;
v_19326:
    fn = elt(env, 62); // open
    v_19533 = (*qfn2(fn))(fn, v_19534, v_19533);
    env = stack[-9];
    stack[-4] = v_19533;
    v_19533 = stack[-4];
    v_19533 = Lrds(nil, v_19533);
    env = stack[-9];
    stack[-4] = v_19533;
    v_19533 = nil;
    stack[-5] = v_19533;
v_19335:
    goto v_19344;
v_19340:
    v_19534 = Lread(nil, 0);
    env = stack[-9];
    v_19535 = v_19534;
    goto v_19341;
v_19342:
    v_19533 = qvalue(elt(env, 40)); // !$eof!$
    goto v_19343;
v_19344:
    goto v_19340;
v_19341:
    goto v_19342;
v_19343:
    if (equal(v_19534, v_19533)) goto v_19338;
    else goto v_19339;
v_19338:
    goto v_19334;
v_19339:
    goto v_19353;
v_19349:
    goto v_19359;
v_19355:
    v_19534 = v_19535;
    goto v_19356;
v_19357:
    v_19533 = elt(env, 41); // orderp
    goto v_19358;
v_19359:
    goto v_19355;
v_19356:
    goto v_19357;
v_19358:
    fn = elt(env, 61); // sort
    v_19534 = (*qfn2(fn))(fn, v_19534, v_19533);
    env = stack[-9];
    goto v_19350;
v_19351:
    v_19533 = stack[-5];
    goto v_19352;
v_19353:
    goto v_19349;
v_19350:
    goto v_19351;
v_19352:
    v_19533 = cons(v_19534, v_19533);
    env = stack[-9];
    stack[-5] = v_19533;
    goto v_19335;
v_19334:
    v_19533 = stack[-4];
    v_19533 = Lrds(nil, v_19533);
    env = stack[-9];
    v_19533 = Lclose(nil, v_19533);
    env = stack[-9];
    v_19533 = elt(env, 42); // ((symbol!-make!-fastget (quote lose) 1) (symbol!-make!-fastget (quote noncom) 0))
    stack[0] = v_19533;
    goto v_19372;
v_19368:
    v_19534 = elt(env, 43); // (lose noncom)
    goto v_19369;
v_19370:
    v_19533 = elt(env, 44); // processed
    goto v_19371;
v_19372:
    goto v_19368;
v_19369:
    goto v_19370;
v_19371:
    v_19533 = Lflag(nil, v_19534, v_19533);
    env = stack[-9];
    v_19533 = (LispObject)32+TAG_FIXNUM; // 2
    stack[-6] = v_19533;
v_19378:
    v_19533 = stack[-5];
    if (v_19533 == nil) goto v_19381;
    else goto v_19382;
v_19381:
    goto v_19377;
v_19382:
    v_19533 = nil;
    stack[-4] = v_19533;
    v_19533 = stack[-5];
    stack[-5] = v_19533;
v_19389:
    v_19533 = stack[-5];
    if (v_19533 == nil) goto v_19393;
    else goto v_19394;
v_19393:
    goto v_19388;
v_19394:
    v_19533 = stack[-5];
    v_19533 = qcar(v_19533);
    stack[-3] = v_19533;
    v_19533 = stack[-3];
    if (v_19533 == nil) goto v_19403;
    goto v_19416;
v_19412:
    v_19533 = stack[-3];
    v_19533 = qcar(v_19533);
    v_19533 = qcdr(v_19533);
    v_19534 = qcar(v_19533);
    goto v_19413;
v_19414:
    v_19533 = elt(env, 44); // processed
    goto v_19415;
v_19416:
    goto v_19412;
v_19413:
    goto v_19414;
v_19415:
    v_19533 = Lflagp(nil, v_19534, v_19533);
    env = stack[-9];
    if (v_19533 == nil) goto v_19409;
    else goto v_19410;
v_19409:
    goto v_19427;
v_19423:
    v_19534 = stack[-6];
    goto v_19424;
v_19425:
    v_19533 = (LispObject)1008+TAG_FIXNUM; // 63
    goto v_19426;
v_19427:
    goto v_19423;
v_19424:
    goto v_19425;
v_19426:
    v_19533 = (LispObject)lessp2(v_19534, v_19533);
    v_19533 = v_19533 ? lisp_true : nil;
    env = stack[-9];
    goto v_19408;
v_19410:
    v_19533 = nil;
    goto v_19408;
    v_19533 = nil;
v_19408:
    if (v_19533 == nil) goto v_19403;
    goto v_19438;
v_19434:
    goto v_19446;
v_19440:
    stack[-1] = elt(env, 45); // symbol!-make!-fastget
    goto v_19441;
v_19442:
    v_19533 = stack[-3];
    v_19533 = qcar(v_19533);
    v_19533 = qcdr(v_19533);
    v_19533 = qcar(v_19533);
    v_19534 = Lmkquote(nil, v_19533);
    env = stack[-9];
    goto v_19443;
v_19444:
    v_19533 = stack[-6];
    goto v_19445;
v_19446:
    goto v_19440;
v_19441:
    goto v_19442;
v_19443:
    goto v_19444;
v_19445:
    v_19534 = list3(stack[-1], v_19534, v_19533);
    env = stack[-9];
    goto v_19435;
v_19436:
    v_19533 = stack[0];
    goto v_19437;
v_19438:
    goto v_19434;
v_19435:
    goto v_19436;
v_19437:
    v_19533 = cons(v_19534, v_19533);
    env = stack[-9];
    stack[0] = v_19533;
    goto v_19460;
v_19456:
    v_19533 = stack[-3];
    v_19533 = qcar(v_19533);
    v_19533 = qcdr(v_19533);
    v_19533 = qcar(v_19533);
    v_19534 = ncons(v_19533);
    env = stack[-9];
    goto v_19457;
v_19458:
    v_19533 = elt(env, 44); // processed
    goto v_19459;
v_19460:
    goto v_19456;
v_19457:
    goto v_19458;
v_19459:
    v_19533 = Lflag(nil, v_19534, v_19533);
    env = stack[-9];
    v_19533 = stack[-6];
    v_19533 = add1(v_19533);
    env = stack[-9];
    stack[-6] = v_19533;
    goto v_19401;
v_19403:
v_19401:
    v_19533 = stack[-3];
    v_19533 = qcdr(v_19533);
    if (v_19533 == nil) goto v_19472;
    goto v_19480;
v_19476:
    v_19533 = stack[-3];
    v_19534 = qcdr(v_19533);
    goto v_19477;
v_19478:
    v_19533 = stack[-4];
    goto v_19479;
v_19480:
    goto v_19476;
v_19477:
    goto v_19478;
v_19479:
    v_19533 = cons(v_19534, v_19533);
    env = stack[-9];
    stack[-4] = v_19533;
    goto v_19470;
v_19472:
v_19470:
    v_19533 = stack[-5];
    v_19533 = qcdr(v_19533);
    stack[-5] = v_19533;
    goto v_19389;
v_19388:
    v_19533 = stack[-4];
    v_19533 = Lreverse(nil, v_19533);
    env = stack[-9];
    stack[-5] = v_19533;
    goto v_19378;
v_19377:
    goto v_19493;
v_19489:
    v_19534 = elt(env, 46); // "buildlogs/fastgets.lsp"
    goto v_19490;
v_19491:
    v_19533 = elt(env, 47); // output
    goto v_19492;
v_19493:
    goto v_19489;
v_19490:
    goto v_19491;
v_19492:
    fn = elt(env, 62); // open
    v_19533 = (*qfn2(fn))(fn, v_19534, v_19533);
    env = stack[-9];
    stack[-5] = v_19533;
    v_19533 = stack[-5];
    v_19533 = Lwrs(nil, v_19533);
    env = stack[-9];
    stack[-5] = v_19533;
    v_19533 = elt(env, 48); // "% fastgets.lsp generated by profiling"
    v_19533 = Lprintc(nil, v_19533);
    env = stack[-9];
    v_19533 = Lterpri(nil, 0);
    env = stack[-9];
    goto v_19507;
v_19503:
    stack[-1] = elt(env, 49); // progn
    goto v_19504;
v_19505:
    v_19533 = stack[0];
    v_19533 = Lreverse(nil, v_19533);
    env = stack[-9];
    goto v_19506;
v_19507:
    goto v_19503;
v_19504:
    goto v_19505;
v_19506:
    v_19533 = cons(stack[-1], v_19533);
    env = stack[-9];
    fn = elt(env, 66); // prettyprint
    v_19533 = (*qfn1(fn))(fn, v_19533);
    env = stack[-9];
    v_19533 = Lterpri(nil, 0);
    env = stack[-9];
    v_19533 = elt(env, 50); // "% end of fastgets.lsp"
    v_19533 = Lprintc(nil, v_19533);
    env = stack[-9];
    v_19533 = stack[-5];
    v_19533 = Lwrs(nil, v_19533);
    env = stack[-9];
    v_19533 = Lclose(nil, v_19533);
    env = stack[-9];
    v_19533 = elt(env, 51); // "Profiling complete"
    v_19533 = Lprintc(nil, v_19533);
    env = stack[-9];
    v_19533 = elt(env, 51); // "Profiling complete"
    fn = elt(env, 57); // window!-heading
    v_19533 = (*qfn1(fn))(fn, v_19533);
    env = stack[-9];
    v_19533 = lisp_true;
    fn = elt(env, 67); // restart!-csl
    v_19533 = (*qfn1(fn))(fn, v_19533);
    goto v_19318;
v_19320:
    goto v_19530;
v_19526:
    v_19534 = elt(env, 52); // (remake profile_a_package)
    goto v_19527;
v_19528:
    v_19533 = stack[-7];
    goto v_19529;
v_19530:
    goto v_19526;
v_19527:
    goto v_19528;
v_19529:
    fn = elt(env, 67); // restart!-csl
    v_19533 = (*qfn2(fn))(fn, v_19534, v_19533);
    goto v_19318;
v_19318:
    v_19533 = nil;
    ;}  // end of a binding scope
    return onevalue(v_19533);
}



// Code for sortedpolynomlistinsert

static LispObject CC_sortedpolynomlistinsert(LispObject env,
                         LispObject v_18793, LispObject v_18794)
{
    env = qenv(env);
    LispObject v_18854, v_18855;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18794,v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18793,v_18794);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_18794;
    v_18854 = v_18793;
// end of prologue
    stack[-2] = v_18854;
v_18802:
    v_18854 = stack[-2];
    v_18854 = qcar(v_18854);
    if (v_18854 == nil) goto v_18805;
    goto v_18815;
v_18811:
    goto v_18821;
v_18817:
    v_18854 = stack[-2];
    v_18855 = qcar(v_18854);
    goto v_18818;
v_18819:
    v_18854 = stack[-1];
    goto v_18820;
v_18821:
    goto v_18817;
v_18818:
    goto v_18819;
v_18820:
    fn = elt(env, 1); // polynomcompare
    v_18855 = (*qfn2(fn))(fn, v_18855, v_18854);
    env = stack[-3];
    goto v_18812;
v_18813:
    v_18854 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_18814;
v_18815:
    goto v_18811;
v_18812:
    goto v_18813;
v_18814:
    if (v_18855 == v_18854) goto v_18805;
    goto v_18806;
v_18805:
    goto v_18801;
v_18806:
    v_18854 = stack[-2];
    v_18854 = qcdr(v_18854);
    stack[-2] = v_18854;
    goto v_18802;
v_18801:
    goto v_18835;
v_18831:
    goto v_18841;
v_18837:
    stack[0] = stack[-2];
    goto v_18838;
v_18839:
    goto v_18848;
v_18844:
    v_18854 = stack[-2];
    v_18855 = qcar(v_18854);
    goto v_18845;
v_18846:
    v_18854 = stack[-2];
    v_18854 = qcdr(v_18854);
    goto v_18847;
v_18848:
    goto v_18844;
v_18845:
    goto v_18846;
v_18847:
    v_18854 = cons(v_18855, v_18854);
    env = stack[-3];
    goto v_18840;
v_18841:
    goto v_18837;
v_18838:
    goto v_18839;
v_18840:
    v_18855 = Lrplacd(nil, stack[0], v_18854);
    env = stack[-3];
    goto v_18832;
v_18833:
    v_18854 = stack[-1];
    goto v_18834;
v_18835:
    goto v_18831;
v_18832:
    goto v_18833;
v_18834:
    v_18854 = Lrplaca(nil, v_18855, v_18854);
    v_18854 = nil;
    return onevalue(v_18854);
}



// Code for !*tayexp2q

static LispObject CC_Htayexp2q(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18821, v_18822;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
// copy arguments values to proper place
    v_18822 = v_18793;
// end of prologue
    v_18821 = v_18822;
    if (!consp(v_18821)) goto v_18797;
    else goto v_18798;
v_18797:
    goto v_18805;
v_18801:
    v_18821 = v_18822;
    v_18821 = (LispObject)zerop(v_18821);
    v_18821 = v_18821 ? lisp_true : nil;
    if (v_18821 == nil) goto v_18809;
    v_18821 = nil;
    v_18822 = v_18821;
    goto v_18807;
v_18809:
    v_18821 = v_18822;
    v_18822 = v_18821;
    goto v_18807;
    v_18822 = nil;
v_18807:
    goto v_18802;
v_18803:
    v_18821 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18804;
v_18805:
    goto v_18801;
v_18802:
    goto v_18803;
v_18804:
    return cons(v_18822, v_18821);
v_18798:
    v_18821 = v_18822;
    v_18821 = qcdr(v_18821);
    goto v_18796;
    v_18821 = nil;
v_18796:
    return onevalue(v_18821);
}



// Code for pasf_smwmkatl

static LispObject CC_pasf_smwmkatl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18833, v_18834, v_18835, v_18836, v_18837;
    LispObject fn;
    LispObject v_18796, v_18795, v_18794, v_18793;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "pasf_smwmkatl");
    va_start(aa, nargs);
    v_18793 = va_arg(aa, LispObject);
    v_18794 = va_arg(aa, LispObject);
    v_18795 = va_arg(aa, LispObject);
    v_18796 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18834 = v_18796;
    v_18835 = v_18795;
    v_18836 = v_18794;
    v_18837 = v_18793;
// end of prologue
    v_18833 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_18833 == nil) goto v_18801;
    goto v_18812;
v_18804:
    v_18833 = v_18837;
    goto v_18805;
v_18806:
    goto v_18807;
v_18808:
    goto v_18809;
v_18810:
    goto v_18811;
v_18812:
    goto v_18804;
v_18805:
    goto v_18806;
v_18807:
    goto v_18808;
v_18809:
    goto v_18810;
v_18811:
    {
        fn = elt(env, 2); // cl_susimkatl
        return (*qfnn(fn))(fn, 4, v_18833, v_18836, v_18835, v_18834);
    }
v_18801:
    goto v_18828;
v_18820:
    v_18833 = v_18837;
    goto v_18821;
v_18822:
    goto v_18823;
v_18824:
    goto v_18825;
v_18826:
    goto v_18827;
v_18828:
    goto v_18820;
v_18821:
    goto v_18822;
v_18823:
    goto v_18824;
v_18825:
    goto v_18826;
v_18827:
    {
        fn = elt(env, 3); // cl_smmkatl
        return (*qfnn(fn))(fn, 4, v_18833, v_18836, v_18835, v_18834);
    }
    v_18833 = nil;
    return onevalue(v_18833);
}



// Code for vdelete

static LispObject CC_vdelete(LispObject env,
                         LispObject v_18793, LispObject v_18794)
{
    env = qenv(env);
    LispObject v_18841, v_18842, v_18843;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18794,v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18793,v_18794);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18794;
    stack[-1] = v_18793;
// end of prologue
    v_18843 = nil;
v_18799:
    v_18841 = stack[0];
    if (v_18841 == nil) goto v_18802;
    else goto v_18803;
v_18802:
    v_18841 = v_18843;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_18841);
    }
v_18803:
    goto v_18813;
v_18809:
    v_18841 = stack[-1];
    v_18842 = qcar(v_18841);
    goto v_18810;
v_18811:
    v_18841 = stack[0];
    v_18841 = qcar(v_18841);
    v_18841 = qcar(v_18841);
    goto v_18812;
v_18813:
    goto v_18809;
v_18810:
    goto v_18811;
v_18812:
    if (equal(v_18842, v_18841)) goto v_18807;
    else goto v_18808;
v_18807:
    goto v_18824;
v_18820:
    v_18842 = v_18843;
    goto v_18821;
v_18822:
    v_18841 = stack[0];
    v_18841 = qcdr(v_18841);
    goto v_18823;
v_18824:
    goto v_18820;
v_18821:
    goto v_18822;
v_18823:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_18842, v_18841);
    }
v_18808:
    goto v_18835;
v_18831:
    v_18841 = stack[0];
    v_18841 = qcar(v_18841);
    goto v_18832;
v_18833:
    v_18842 = v_18843;
    goto v_18834;
v_18835:
    goto v_18831;
v_18832:
    goto v_18833;
v_18834:
    v_18841 = cons(v_18841, v_18842);
    env = stack[-2];
    v_18843 = v_18841;
    v_18841 = stack[0];
    v_18841 = qcdr(v_18841);
    stack[0] = v_18841;
    goto v_18799;
    v_18841 = nil;
    return onevalue(v_18841);
}



// Code for matrixom

static LispObject CC_matrixom(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18813;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18793;
// end of prologue
    v_18813 = elt(env, 1); // "<OMA>"
    fn = elt(env, 4); // printout
    v_18813 = (*qfn1(fn))(fn, v_18813);
    env = stack[-1];
    v_18813 = lisp_true;
    fn = elt(env, 5); // indent!*
    v_18813 = (*qfn1(fn))(fn, v_18813);
    env = stack[-1];
    v_18813 = elt(env, 2); // "<OMS cd=""linalg1"" name=""matrix""/>"
    fn = elt(env, 4); // printout
    v_18813 = (*qfn1(fn))(fn, v_18813);
    env = stack[-1];
    v_18813 = stack[0];
    v_18813 = qcdr(v_18813);
    v_18813 = qcdr(v_18813);
    v_18813 = qcdr(v_18813);
    v_18813 = qcar(v_18813);
    fn = elt(env, 6); // matrixrowom
    v_18813 = (*qfn1(fn))(fn, v_18813);
    env = stack[-1];
    v_18813 = nil;
    fn = elt(env, 5); // indent!*
    v_18813 = (*qfn1(fn))(fn, v_18813);
    env = stack[-1];
    v_18813 = elt(env, 3); // "</OMA>"
    fn = elt(env, 4); // printout
    v_18813 = (*qfn1(fn))(fn, v_18813);
    v_18813 = nil;
    return onevalue(v_18813);
}



// Code for difference!:

static LispObject CC_differenceT(LispObject env,
                         LispObject v_18793, LispObject v_18794)
{
    env = qenv(env);
    LispObject v_18931, v_18932, v_18933, v_18934;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18794,v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18793,v_18794);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_18933 = v_18794;
    v_18934 = v_18793;
// end of prologue
    goto v_18811;
v_18807:
    v_18931 = v_18934;
    v_18931 = qcdr(v_18931);
    v_18932 = qcar(v_18931);
    stack[-1] = v_18932;
    goto v_18808;
v_18809:
    v_18931 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18810;
v_18811:
    goto v_18807;
v_18808:
    goto v_18809;
v_18810:
    if (v_18932 == v_18931) goto v_18805;
    else goto v_18806;
v_18805:
    v_18931 = v_18933;
    {
        fn = elt(env, 2); // minus!:
        return (*qfn1(fn))(fn, v_18931);
    }
v_18806:
    goto v_18824;
v_18820:
    v_18931 = v_18933;
    v_18931 = qcdr(v_18931);
    v_18932 = qcar(v_18931);
    stack[0] = v_18932;
    goto v_18821;
v_18822:
    v_18931 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18823;
v_18824:
    goto v_18820;
v_18821:
    goto v_18822;
v_18823:
    if (v_18932 == v_18931) goto v_18818;
    else goto v_18819;
v_18818:
    v_18931 = v_18934;
    goto v_18804;
v_18819:
    goto v_18836;
v_18832:
    goto v_18842;
v_18838:
    v_18931 = v_18934;
    v_18931 = qcdr(v_18931);
    v_18931 = qcdr(v_18931);
    stack[-4] = v_18931;
    goto v_18839;
v_18840:
    v_18932 = v_18933;
    v_18932 = qcdr(v_18932);
    v_18932 = qcdr(v_18932);
    stack[-2] = v_18932;
    goto v_18841;
v_18842:
    goto v_18838;
v_18839:
    goto v_18840;
v_18841:
    v_18932 = difference2(v_18931, v_18932);
    env = stack[-5];
    stack[-3] = v_18932;
    goto v_18833;
v_18834:
    v_18931 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18835;
v_18836:
    goto v_18832;
v_18833:
    goto v_18834;
v_18835:
    if (v_18932 == v_18931) goto v_18830;
    else goto v_18831;
v_18830:
    goto v_18857;
v_18851:
    stack[-2] = elt(env, 1); // !:rd!:
    goto v_18852;
v_18853:
    goto v_18864;
v_18860:
    v_18932 = stack[-1];
    goto v_18861;
v_18862:
    v_18931 = stack[0];
    goto v_18863;
v_18864:
    goto v_18860;
v_18861:
    goto v_18862;
v_18863:
    v_18932 = difference2(v_18932, v_18931);
    goto v_18854;
v_18855:
    v_18931 = stack[-4];
    goto v_18856;
v_18857:
    goto v_18851;
v_18852:
    goto v_18853;
v_18854:
    goto v_18855;
v_18856:
    {
        LispObject v_18940 = stack[-2];
        return list2star(v_18940, v_18932, v_18931);
    }
v_18831:
    goto v_18875;
v_18871:
    v_18932 = stack[-3];
    goto v_18872;
v_18873:
    v_18931 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18874;
v_18875:
    goto v_18871;
v_18872:
    goto v_18873;
v_18874:
    v_18931 = (LispObject)greaterp2(v_18932, v_18931);
    v_18931 = v_18931 ? lisp_true : nil;
    env = stack[-5];
    if (v_18931 == nil) goto v_18869;
    goto v_18885;
v_18879:
    stack[-4] = elt(env, 1); // !:rd!:
    goto v_18880;
v_18881:
    goto v_18892;
v_18888:
    goto v_18898;
v_18894:
    v_18932 = stack[-1];
    goto v_18895;
v_18896:
    v_18931 = stack[-3];
    goto v_18897;
v_18898:
    goto v_18894;
v_18895:
    goto v_18896;
v_18897:
    fn = elt(env, 3); // ashift
    v_18932 = (*qfn2(fn))(fn, v_18932, v_18931);
    env = stack[-5];
    goto v_18889;
v_18890:
    v_18931 = stack[0];
    goto v_18891;
v_18892:
    goto v_18888;
v_18889:
    goto v_18890;
v_18891:
    v_18932 = difference2(v_18932, v_18931);
    goto v_18882;
v_18883:
    v_18931 = stack[-2];
    goto v_18884;
v_18885:
    goto v_18879;
v_18880:
    goto v_18881;
v_18882:
    goto v_18883;
v_18884:
    {
        LispObject v_18941 = stack[-4];
        return list2star(v_18941, v_18932, v_18931);
    }
v_18869:
    goto v_18912;
v_18906:
    stack[-2] = elt(env, 1); // !:rd!:
    goto v_18907;
v_18908:
    goto v_18919;
v_18915:
    goto v_18916;
v_18917:
    goto v_18926;
v_18922:
    goto v_18923;
v_18924:
    v_18931 = stack[-3];
    v_18931 = negate(v_18931);
    env = stack[-5];
    goto v_18925;
v_18926:
    goto v_18922;
v_18923:
    goto v_18924;
v_18925:
    fn = elt(env, 3); // ashift
    v_18931 = (*qfn2(fn))(fn, stack[0], v_18931);
    env = stack[-5];
    goto v_18918;
v_18919:
    goto v_18915;
v_18916:
    goto v_18917;
v_18918:
    v_18932 = difference2(stack[-1], v_18931);
    goto v_18909;
v_18910:
    v_18931 = stack[-4];
    goto v_18911;
v_18912:
    goto v_18906;
v_18907:
    goto v_18908;
v_18909:
    goto v_18910;
v_18911:
    {
        LispObject v_18942 = stack[-2];
        return list2star(v_18942, v_18932, v_18931);
    }
    v_18931 = nil;
v_18804:
    return onevalue(v_18931);
}



// Code for find_buble

static LispObject CC_find_buble(LispObject env,
                         LispObject v_18793, LispObject v_18794)
{
    env = qenv(env);
    LispObject v_18825, v_18826;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18794,v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18793,v_18794);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18794;
    stack[-1] = v_18793;
// end of prologue
v_18792:
    v_18825 = stack[0];
    if (v_18825 == nil) goto v_18798;
    else goto v_18799;
v_18798:
    v_18825 = nil;
    goto v_18797;
v_18799:
    goto v_18812;
v_18808:
    v_18826 = stack[-1];
    goto v_18809;
v_18810:
    v_18825 = stack[0];
    v_18825 = qcar(v_18825);
    goto v_18811;
v_18812:
    goto v_18808;
v_18809:
    goto v_18810;
v_18811:
    fn = elt(env, 1); // is_buble
    v_18825 = (*qfn2(fn))(fn, v_18826, v_18825);
    env = stack[-2];
    if (v_18825 == nil) goto v_18806;
    else goto v_18805;
v_18806:
    goto v_18821;
v_18817:
    v_18826 = stack[-1];
    goto v_18818;
v_18819:
    v_18825 = stack[0];
    v_18825 = qcdr(v_18825);
    goto v_18820;
v_18821:
    goto v_18817;
v_18818:
    goto v_18819;
v_18820:
    stack[-1] = v_18826;
    stack[0] = v_18825;
    goto v_18792;
v_18805:
    goto v_18797;
    v_18825 = nil;
v_18797:
    return onevalue(v_18825);
}



// Code for log_assignment

static LispObject CC_log_assignment(LispObject env,
                         LispObject v_18793, LispObject v_18794)
{
    env = qenv(env);
    LispObject v_18910, v_18911, v_18912;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18794,v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18793,v_18794);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18794;
    v_18911 = v_18793;
// end of prologue
v_18798:
    v_18910 = stack[0];
    if (!consp(v_18910)) goto v_18805;
    else goto v_18806;
v_18805:
    v_18910 = lisp_true;
    goto v_18804;
v_18806:
    goto v_18820;
v_18816:
    v_18912 = stack[0];
    goto v_18817;
v_18818:
    v_18910 = elt(env, 1); // quote
    goto v_18819;
v_18820:
    goto v_18816;
v_18817:
    goto v_18818;
v_18819:
    if (!consp(v_18912)) goto v_18814;
    v_18912 = qcar(v_18912);
    if (v_18912 == v_18910) goto v_18813;
    else goto v_18814;
v_18813:
    v_18910 = lisp_true;
    goto v_18812;
v_18814:
    goto v_18831;
v_18827:
    v_18912 = stack[0];
    goto v_18828;
v_18829:
    v_18910 = elt(env, 2); // function
    goto v_18830;
v_18831:
    goto v_18827;
v_18828:
    goto v_18829;
v_18830:
    v_18910 = Leqcar(nil, v_18912, v_18910);
    env = stack[-1];
    goto v_18812;
    v_18910 = nil;
v_18812:
    goto v_18804;
    v_18910 = nil;
v_18804:
    if (v_18910 == nil) goto v_18802;
    v_18910 = nil;
    goto v_18797;
v_18802:
    goto v_18842;
v_18838:
    v_18912 = stack[0];
    goto v_18839;
v_18840:
    v_18910 = elt(env, 3); // setq
    goto v_18841;
v_18842:
    goto v_18838;
v_18839:
    goto v_18840;
v_18841:
    if (!consp(v_18912)) goto v_18836;
    v_18912 = qcar(v_18912);
    if (v_18912 == v_18910) goto v_18835;
    else goto v_18836;
v_18835:
    goto v_18853;
v_18849:
    v_18910 = stack[0];
    v_18910 = qcdr(v_18910);
    v_18912 = qcar(v_18910);
    goto v_18850;
v_18851:
    v_18910 = v_18911;
    goto v_18852;
v_18853:
    goto v_18849;
v_18850:
    goto v_18851;
v_18852:
    v_18910 = Lmember(nil, v_18912, v_18910);
    if (v_18910 == nil) goto v_18848;
    v_18910 = Lposn(nil, 0);
    env = stack[-1];
    v_18910 = (LispObject)zerop(v_18910);
    v_18910 = v_18910 ? lisp_true : nil;
    env = stack[-1];
    if (v_18910 == nil) goto v_18861;
    else goto v_18862;
v_18861:
    v_18910 = Lterpri(nil, 0);
    env = stack[-1];
    goto v_18860;
v_18862:
v_18860:
    v_18910 = elt(env, 4); // "+++ Assignment to parameter of inline: "
    v_18910 = Lprinc(nil, v_18910);
    env = stack[-1];
    v_18910 = stack[0];
    v_18910 = Lprint(nil, v_18910);
    env = stack[-1];
    v_18910 = elt(env, 5); // "+++ Macro was: "
    v_18910 = Lprinc(nil, v_18910);
    env = stack[-1];
    v_18910 = qvalue(elt(env, 6)); // inlineinfo
    v_18910 = Lprint(nil, v_18910);
    v_18910 = lisp_true;
    goto v_18797;
v_18848:
    v_18910 = stack[0];
    v_18910 = qcdr(v_18910);
    v_18910 = qcdr(v_18910);
    v_18910 = qcar(v_18910);
    stack[0] = v_18910;
    goto v_18798;
    goto v_18800;
v_18836:
    goto v_18888;
v_18884:
    v_18912 = stack[0];
    goto v_18885;
v_18886:
    v_18910 = elt(env, 7); // cond
    goto v_18887;
v_18888:
    goto v_18884;
v_18885:
    goto v_18886;
v_18887:
    if (!consp(v_18912)) goto v_18882;
    v_18912 = qcar(v_18912);
    if (v_18912 == v_18910) goto v_18881;
    else goto v_18882;
v_18881:
    goto v_18896;
v_18892:
    goto v_18893;
v_18894:
    v_18910 = stack[0];
    v_18910 = qcdr(v_18910);
    goto v_18895;
v_18896:
    goto v_18892;
v_18893:
    goto v_18894;
v_18895:
    {
        fn = elt(env, 8); // log_assignment_list_list
        return (*qfn2(fn))(fn, v_18911, v_18910);
    }
v_18882:
    goto v_18907;
v_18903:
    goto v_18904;
v_18905:
    v_18910 = stack[0];
    goto v_18906;
v_18907:
    goto v_18903;
v_18904:
    goto v_18905;
v_18906:
    {
        fn = elt(env, 9); // log_assignment_list
        return (*qfn2(fn))(fn, v_18911, v_18910);
    }
v_18800:
    v_18910 = nil;
v_18797:
    return onevalue(v_18910);
}



// Code for remchkf

static LispObject CC_remchkf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18861, v_18862, v_18863;
    LispObject fn;
    LispObject v_18795, v_18794, v_18793;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "remchkf");
    va_start(aa, nargs);
    v_18793 = va_arg(aa, LispObject);
    v_18794 = va_arg(aa, LispObject);
    v_18795 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18795,v_18794,v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18793,v_18794,v_18795);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_18795;
    stack[-1] = v_18794;
    stack[-2] = v_18793;
// end of prologue
    goto v_18802;
v_18798:
    v_18862 = stack[-2];
    goto v_18799;
v_18800:
    v_18861 = stack[-1];
    goto v_18801;
v_18802:
    goto v_18798;
v_18799:
    goto v_18800;
v_18801:
    fn = elt(env, 1); // remchkf1
    v_18861 = (*qfn2(fn))(fn, v_18862, v_18861);
    env = stack[-4];
    stack[-3] = v_18861;
    v_18861 = stack[-3];
    if (!consp(v_18861)) goto v_18816;
    else goto v_18817;
v_18816:
    v_18861 = lisp_true;
    goto v_18815;
v_18817:
    v_18861 = stack[-3];
    v_18861 = qcar(v_18861);
    v_18861 = (consp(v_18861) ? nil : lisp_true);
    goto v_18815;
    v_18861 = nil;
v_18815:
    if (v_18861 == nil) goto v_18813;
    v_18861 = lisp_true;
    goto v_18811;
v_18813:
    goto v_18833;
v_18829:
    v_18861 = stack[-2];
    fn = elt(env, 2); // kernels
    v_18862 = (*qfn1(fn))(fn, v_18861);
    env = stack[-4];
    goto v_18830;
v_18831:
    v_18861 = stack[0];
    goto v_18832;
v_18833:
    goto v_18829;
v_18830:
    goto v_18831;
v_18832:
    fn = elt(env, 3); // intersection
    v_18861 = (*qfn2(fn))(fn, v_18862, v_18861);
    env = stack[-4];
    v_18861 = (v_18861 == nil ? lisp_true : nil);
    goto v_18811;
    v_18861 = nil;
v_18811:
    if (v_18861 == nil) goto v_18809;
    v_18861 = stack[-3];
    goto v_18807;
v_18809:
    goto v_18846;
v_18842:
    v_18861 = stack[-3];
    stack[-2] = qcar(v_18861);
    goto v_18843;
v_18844:
    goto v_18856;
v_18850:
    v_18861 = stack[-3];
    v_18863 = qcdr(v_18861);
    goto v_18851;
v_18852:
    v_18862 = stack[-1];
    goto v_18853;
v_18854:
    v_18861 = stack[0];
    goto v_18855;
v_18856:
    goto v_18850;
v_18851:
    goto v_18852;
v_18853:
    goto v_18854;
v_18855:
    v_18861 = CC_remchkf(elt(env, 0), 3, v_18863, v_18862, v_18861);
    goto v_18845;
v_18846:
    goto v_18842;
v_18843:
    goto v_18844;
v_18845:
    {
        LispObject v_18868 = stack[-2];
        return cons(v_18868, v_18861);
    }
    v_18861 = nil;
v_18807:
    return onevalue(v_18861);
}



// Code for ad_splitname

static LispObject CC_ad_splitname(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18857, v_18858;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_18858 = v_18793;
// end of prologue
    v_18857 = v_18858;
    if (symbolp(v_18857)) goto v_18797;
    else goto v_18798;
v_18797:
    stack[0] = nil;
    v_18857 = v_18858;
    v_18857 = Lexplode(nil, v_18857);
    env = stack[-2];
    v_18857 = Lreverse(nil, v_18857);
    env = stack[-2];
    stack[-1] = v_18857;
v_18809:
    v_18857 = stack[-1];
    if (v_18857 == nil) goto v_18812;
    v_18857 = stack[-1];
    v_18857 = qcar(v_18857);
    fn = elt(env, 1); // charnump!:
    v_18857 = (*qfn1(fn))(fn, v_18857);
    env = stack[-2];
    if (v_18857 == nil) goto v_18812;
    goto v_18813;
v_18812:
    goto v_18808;
v_18813:
    goto v_18826;
v_18822:
    v_18857 = stack[-1];
    v_18858 = qcar(v_18857);
    goto v_18823;
v_18824:
    v_18857 = stack[0];
    goto v_18825;
v_18826:
    goto v_18822;
v_18823:
    goto v_18824;
v_18825:
    v_18857 = cons(v_18858, v_18857);
    env = stack[-2];
    stack[0] = v_18857;
    v_18857 = stack[-1];
    v_18857 = qcdr(v_18857);
    stack[-1] = v_18857;
    goto v_18809;
v_18808:
    v_18857 = stack[-1];
    if (v_18857 == nil) goto v_18836;
    v_18857 = stack[-1];
    v_18857 = Lreverse(nil, v_18857);
    env = stack[-2];
    v_18857 = Lcompress(nil, v_18857);
    env = stack[-2];
    v_18857 = Lintern(nil, v_18857);
    env = stack[-2];
    stack[-1] = v_18857;
    goto v_18834;
v_18836:
v_18834:
    v_18857 = stack[0];
    if (v_18857 == nil) goto v_18845;
    v_18857 = stack[0];
    v_18857 = Lcompress(nil, v_18857);
    stack[0] = v_18857;
    goto v_18843;
v_18845:
v_18843:
    goto v_18854;
v_18850:
    v_18858 = stack[-1];
    goto v_18851;
v_18852:
    v_18857 = stack[0];
    goto v_18853;
v_18854:
    goto v_18850;
v_18851:
    goto v_18852;
v_18853:
    return cons(v_18858, v_18857);
    goto v_18796;
v_18798:
    v_18857 = nil;
v_18796:
    return onevalue(v_18857);
}



// Code for ratdif

static LispObject CC_ratdif(LispObject env,
                         LispObject v_18793, LispObject v_18794)
{
    env = qenv(env);
    LispObject v_18808, v_18809;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18794,v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18793,v_18794);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_18808 = v_18794;
    v_18809 = v_18793;
// end of prologue
    goto v_18803;
v_18797:
    stack[0] = v_18809;
    goto v_18798;
v_18799:
    fn = elt(env, 1); // ratminus
    v_18809 = (*qfn1(fn))(fn, v_18808);
    env = stack[-1];
    goto v_18800;
v_18801:
    v_18808 = nil;
    goto v_18802;
v_18803:
    goto v_18797;
v_18798:
    goto v_18799;
v_18800:
    goto v_18801;
v_18802:
    {
        LispObject v_18811 = stack[0];
        fn = elt(env, 2); // ratplusm
        return (*qfnn(fn))(fn, 3, v_18811, v_18809, v_18808);
    }
}



// Code for cde_replace_nth

static LispObject CC_cde_replace_nth(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18852, v_18853;
    LispObject fn;
    LispObject v_18795, v_18794, v_18793;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cde_replace_nth");
    va_start(aa, nargs);
    v_18793 = va_arg(aa, LispObject);
    v_18794 = va_arg(aa, LispObject);
    v_18795 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18795,v_18794,v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18793,v_18794,v_18795);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_18795;
    stack[-1] = v_18794;
    stack[-2] = v_18793;
// end of prologue
    stack[-3] = nil;
v_18800:
    v_18852 = stack[-2];
    if (v_18852 == nil) goto v_18804;
    goto v_18814;
v_18810:
    v_18853 = stack[-1];
    goto v_18811;
v_18812:
    v_18852 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18813;
v_18814:
    goto v_18810;
v_18811:
    goto v_18812;
v_18813:
    if (v_18853 == v_18852) goto v_18808;
    else goto v_18809;
v_18808:
    goto v_18822;
v_18818:
    stack[-1] = stack[-3];
    goto v_18819;
v_18820:
    goto v_18829;
v_18825:
    v_18853 = stack[0];
    goto v_18826;
v_18827:
    v_18852 = stack[-2];
    v_18852 = qcdr(v_18852);
    goto v_18828;
v_18829:
    goto v_18825;
v_18826:
    goto v_18827;
v_18828:
    v_18852 = cons(v_18853, v_18852);
    env = stack[-4];
    goto v_18821;
v_18822:
    goto v_18818;
v_18819:
    goto v_18820;
v_18821:
    {
        LispObject v_18858 = stack[-1];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_18858, v_18852);
    }
v_18809:
    goto v_18840;
v_18836:
    v_18852 = stack[-2];
    v_18853 = qcar(v_18852);
    goto v_18837;
v_18838:
    v_18852 = stack[-3];
    goto v_18839;
v_18840:
    goto v_18836;
v_18837:
    goto v_18838;
v_18839:
    v_18852 = cons(v_18853, v_18852);
    env = stack[-4];
    stack[-3] = v_18852;
    v_18852 = stack[-2];
    v_18852 = qcdr(v_18852);
    stack[-2] = v_18852;
    v_18852 = stack[-1];
    v_18852 = sub1(v_18852);
    env = stack[-4];
    stack[-1] = v_18852;
    goto v_18800;
    goto v_18802;
v_18804:
    v_18852 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_18852);
    }
v_18802:
    v_18852 = nil;
    return onevalue(v_18852);
}



// Code for gcd!-with!-number

static LispObject CC_gcdKwithKnumber(LispObject env,
                         LispObject v_18793, LispObject v_18794)
{
    env = qenv(env);
    LispObject v_18876, v_18877, v_18878;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18794,v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18793,v_18794);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18794;
    v_18877 = v_18793;
// end of prologue
v_18798:
    goto v_18811;
v_18807:
    v_18878 = v_18877;
    goto v_18808;
v_18809:
    v_18876 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18810;
v_18811:
    goto v_18807;
v_18808:
    goto v_18809;
v_18810:
    if (v_18878 == v_18876) goto v_18805;
    else goto v_18806;
v_18805:
    v_18876 = lisp_true;
    goto v_18804;
v_18806:
    v_18876 = v_18877;
    if (!consp(v_18876)) goto v_18820;
    v_18876 = lisp_true;
    goto v_18818;
v_18820:
    v_18876 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_18876)) v_18876 = nil;
    else { v_18876 = qfastgets(v_18876);
           if (v_18876 != nil) { v_18876 = elt(v_18876, 3); // field
#ifdef RECORD_GET
             if (v_18876 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_18876 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_18876 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_18876 == SPID_NOPROP) v_18876 = nil; else v_18876 = lisp_true; }}
#endif
    goto v_18818;
    v_18876 = nil;
v_18818:
    goto v_18804;
    v_18876 = nil;
v_18804:
    if (v_18876 == nil) goto v_18802;
    v_18876 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18797;
v_18802:
    v_18876 = stack[0];
    if (!consp(v_18876)) goto v_18832;
    else goto v_18833;
v_18832:
    v_18876 = lisp_true;
    goto v_18831;
v_18833:
    v_18876 = stack[0];
    v_18876 = qcar(v_18876);
    v_18876 = (consp(v_18876) ? nil : lisp_true);
    goto v_18831;
    v_18876 = nil;
v_18831:
    if (v_18876 == nil) goto v_18829;
    v_18876 = stack[0];
    if (v_18876 == nil) goto v_18843;
    else goto v_18844;
v_18843:
    v_18876 = v_18877;
        return Labsval(nil, v_18876);
v_18844:
    v_18876 = stack[0];
    if (!consp(v_18876)) goto v_18849;
    v_18876 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18797;
v_18849:
    goto v_18859;
v_18855:
    goto v_18856;
v_18857:
    v_18876 = stack[0];
    goto v_18858;
v_18859:
    goto v_18855;
v_18856:
    goto v_18857;
v_18858:
    {
        fn = elt(env, 2); // gcddd
        return (*qfn2(fn))(fn, v_18877, v_18876);
    }
    goto v_18800;
v_18829:
    goto v_18869;
v_18865:
    goto v_18866;
v_18867:
    v_18876 = stack[0];
    v_18876 = qcar(v_18876);
    v_18876 = qcdr(v_18876);
    goto v_18868;
v_18869:
    goto v_18865;
v_18866:
    goto v_18867;
v_18868:
    v_18876 = CC_gcdKwithKnumber(elt(env, 0), v_18877, v_18876);
    env = stack[-1];
    v_18877 = v_18876;
    v_18876 = stack[0];
    v_18876 = qcdr(v_18876);
    stack[0] = v_18876;
    goto v_18798;
v_18800:
    v_18876 = nil;
v_18797:
    return onevalue(v_18876);
}



// Code for lex_process_directive

static LispObject CC_lex_process_directive(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18901, v_18902, v_18903;
    LispObject fn;
    argcheck(nargs, 0, "lex_process_directive");
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
    goto v_18805;
v_18801:
    v_18902 = qvalue(elt(env, 1)); // yylval
    goto v_18802;
v_18803:
    v_18901 = elt(env, 2); // !#endif
    goto v_18804;
v_18805:
    goto v_18801;
v_18802:
    goto v_18803;
v_18804:
    if (v_18902 == v_18901) goto v_18799;
    else goto v_18800;
v_18799:
    v_18901 = qvalue(elt(env, 3)); // if_depth
    v_18901 = (LispObject)zerop(v_18901);
    v_18901 = v_18901 ? lisp_true : nil;
    env = stack[-1];
    if (v_18901 == nil) goto v_18811;
    v_18901 = elt(env, 4); // "+++ #endif not follopwing #if"
    v_18901 = Lprintc(nil, v_18901);
    env = stack[-1];
    goto v_18809;
v_18811:
v_18809:
    v_18901 = qvalue(elt(env, 3)); // if_depth
    v_18901 = sub1(v_18901);
    env = stack[-1];
    qvalue(elt(env, 3)) = v_18901; // if_depth
    v_18901 = lisp_true;
    goto v_18796;
v_18800:
    goto v_18825;
v_18821:
    v_18902 = qvalue(elt(env, 1)); // yylval
    goto v_18822;
v_18823:
    v_18901 = qvalue(elt(env, 5)); // !$eof!$
    goto v_18824;
v_18825:
    goto v_18821;
v_18822:
    goto v_18823;
v_18824:
    if (equal(v_18902, v_18901)) goto v_18819;
    else goto v_18820;
v_18819:
    v_18901 = qvalue(elt(env, 3)); // if_depth
    v_18901 = (LispObject)zerop(v_18901);
    v_18901 = v_18901 ? lisp_true : nil;
    env = stack[-1];
    if (v_18901 == nil) goto v_18830;
    else goto v_18831;
v_18830:
    v_18901 = elt(env, 6); // "+++ #endif missing at end of file"
    v_18901 = Lprintc(nil, v_18901);
    goto v_18829;
v_18831:
v_18829:
    v_18901 = lisp_true;
    goto v_18796;
v_18820:
    goto v_18843;
v_18839:
    v_18902 = qvalue(elt(env, 1)); // yylval
    goto v_18840;
v_18841:
    v_18901 = elt(env, 7); // !#if
    goto v_18842;
v_18843:
    goto v_18839;
v_18840:
    goto v_18841;
v_18842:
    if (v_18902 == v_18901) goto v_18837;
    else goto v_18838;
v_18837:
    v_18901 = qvalue(elt(env, 3)); // if_depth
    v_18901 = add1(v_18901);
    env = stack[-1];
    qvalue(elt(env, 3)) = v_18901; // if_depth
    fn = elt(env, 10); // read_s_expression
    v_18901 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_18856;
v_18850:
    v_18903 = qvalue(elt(env, 1)); // yylval
    goto v_18851;
v_18852:
    v_18902 = nil;
    goto v_18853;
v_18854:
    v_18901 = nil;
    goto v_18855;
v_18856:
    goto v_18850;
v_18851:
    goto v_18852;
v_18853:
    goto v_18854;
v_18855:
    fn = elt(env, 11); // errorset
    v_18901 = (*qfnn(fn))(fn, 3, v_18903, v_18902, v_18901);
    env = stack[-1];
    stack[0] = v_18901;
    v_18901 = stack[0];
    fn = elt(env, 12); // errorp
    v_18901 = (*qfn1(fn))(fn, v_18901);
    env = stack[-1];
    if (v_18901 == nil) goto v_18864;
    else goto v_18862;
v_18864:
    v_18901 = stack[0];
    v_18901 = qcar(v_18901);
    if (v_18901 == nil) goto v_18862;
    goto v_18863;
v_18862:
    v_18901 = lisp_true;
    {
        fn = elt(env, 13); // lex_skip_to_else_or_endif
        return (*qfn1(fn))(fn, v_18901);
    }
v_18863:
    v_18901 = lisp_true;
    goto v_18796;
    goto v_18798;
v_18838:
    goto v_18881;
v_18877:
    v_18902 = qvalue(elt(env, 1)); // yylval
    goto v_18878;
v_18879:
    v_18901 = elt(env, 8); // !#else
    goto v_18880;
v_18881:
    goto v_18877;
v_18878:
    goto v_18879;
v_18880:
    if (v_18902 == v_18901) goto v_18875;
    else goto v_18876;
v_18875:
    v_18901 = nil;
    {
        fn = elt(env, 13); // lex_skip_to_else_or_endif
        return (*qfn1(fn))(fn, v_18901);
    }
v_18876:
    goto v_18892;
v_18888:
    v_18902 = qvalue(elt(env, 1)); // yylval
    goto v_18889;
v_18890:
    v_18901 = elt(env, 9); // !#elif
    goto v_18891;
v_18892:
    goto v_18888;
v_18889:
    goto v_18890;
v_18891:
    if (v_18902 == v_18901) goto v_18886;
    else goto v_18887;
v_18886:
    fn = elt(env, 10); // read_s_expression
    v_18901 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_18901 = nil;
    {
        fn = elt(env, 13); // lex_skip_to_else_or_endif
        return (*qfn1(fn))(fn, v_18901);
    }
v_18887:
    v_18901 = nil;
    goto v_18796;
v_18798:
    v_18901 = nil;
v_18796:
    return onevalue(v_18901);
}



// Code for polynomwrite

static LispObject CC_polynomwrite(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18846, v_18847;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18793;
// end of prologue
    stack[-1] = nil;
v_18798:
    v_18846 = stack[0];
    v_18846 = qcar(v_18846);
    if (v_18846 == nil) goto v_18801;
    else goto v_18802;
v_18801:
    v_18846 = stack[-1];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_18846);
    }
v_18802:
    goto v_18813;
v_18809:
    goto v_18818;
v_18814:
    v_18846 = stack[0];
    v_18847 = qcar(v_18846);
    goto v_18815;
v_18816:
    v_18846 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18817;
v_18818:
    goto v_18814;
v_18815:
    goto v_18816;
v_18817:
    v_18847 = *(LispObject *)((char *)v_18847 + (CELL-TAG_VECTOR) + (((intptr_t)v_18846-TAG_FIXNUM)/(16/CELL)));
    goto v_18810;
v_18811:
    v_18846 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18812;
v_18813:
    goto v_18809;
v_18810:
    goto v_18811;
v_18812:
    if (v_18847 == v_18846) goto v_18807;
    else goto v_18808;
v_18807:
    goto v_18829;
v_18825:
    v_18847 = stack[-1];
    goto v_18826;
v_18827:
    v_18846 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18828;
v_18829:
    goto v_18825;
v_18826:
    goto v_18827;
v_18828:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_18847, v_18846);
    }
v_18808:
    goto v_18839;
v_18835:
    v_18846 = stack[0];
    v_18846 = qcar(v_18846);
    fn = elt(env, 2); // monomwrite
    v_18847 = (*qfn1(fn))(fn, v_18846);
    env = stack[-2];
    goto v_18836;
v_18837:
    v_18846 = stack[-1];
    goto v_18838;
v_18839:
    goto v_18835;
v_18836:
    goto v_18837;
v_18838:
    v_18846 = cons(v_18847, v_18846);
    env = stack[-2];
    stack[-1] = v_18846;
    v_18846 = stack[0];
    v_18846 = qcdr(v_18846);
    stack[0] = v_18846;
    goto v_18798;
    v_18846 = nil;
    return onevalue(v_18846);
}



// Code for talp_sumd

static LispObject CC_talp_sumd(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18842, v_18843;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_18843 = v_18793;
// end of prologue
    v_18842 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_18842;
    v_18842 = v_18843;
    if (!consp(v_18842)) goto v_18802;
    else goto v_18803;
v_18802:
    v_18842 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18798;
v_18803:
    v_18842 = v_18843;
    fn = elt(env, 1); // rl_atl
    v_18842 = (*qfn1(fn))(fn, v_18842);
    env = stack[-3];
    stack[-2] = v_18842;
v_18810:
    v_18842 = stack[-2];
    if (v_18842 == nil) goto v_18813;
    else goto v_18814;
v_18813:
    goto v_18809;
v_18814:
    goto v_18822;
v_18818:
    stack[-1] = stack[0];
    goto v_18819;
v_18820:
    goto v_18829;
v_18825:
    v_18842 = stack[-2];
    v_18842 = qcar(v_18842);
    fn = elt(env, 2); // talp_arg2l
    v_18842 = (*qfn1(fn))(fn, v_18842);
    env = stack[-3];
    fn = elt(env, 3); // talp_td
    stack[0] = (*qfn1(fn))(fn, v_18842);
    env = stack[-3];
    goto v_18826;
v_18827:
    v_18842 = stack[-2];
    v_18842 = qcar(v_18842);
    fn = elt(env, 4); // talp_arg2r
    v_18842 = (*qfn1(fn))(fn, v_18842);
    env = stack[-3];
    fn = elt(env, 3); // talp_td
    v_18842 = (*qfn1(fn))(fn, v_18842);
    env = stack[-3];
    goto v_18828;
v_18829:
    goto v_18825;
v_18826:
    goto v_18827;
v_18828:
    v_18842 = plus2(stack[0], v_18842);
    env = stack[-3];
    goto v_18821;
v_18822:
    goto v_18818;
v_18819:
    goto v_18820;
v_18821:
    v_18842 = plus2(stack[-1], v_18842);
    env = stack[-3];
    stack[0] = v_18842;
    v_18842 = stack[-2];
    v_18842 = qcdr(v_18842);
    stack[-2] = v_18842;
    goto v_18810;
v_18809:
    v_18842 = stack[0];
v_18798:
    return onevalue(v_18842);
}



// Code for mri_congp

static LispObject CC_mri_congp(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18804, v_18805;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18804 = v_18793;
// end of prologue
    goto v_18799;
v_18795:
    fn = elt(env, 2); // mri_opn
    v_18804 = (*qfn1(fn))(fn, v_18804);
    env = stack[0];
    goto v_18796;
v_18797:
    v_18805 = elt(env, 1); // (cong ncong)
    goto v_18798;
v_18799:
    goto v_18795;
v_18796:
    goto v_18797;
v_18798:
    v_18804 = Lmemq(nil, v_18804, v_18805);
    return onevalue(v_18804);
}



// Code for qqe_ofsf_varlat

static LispObject CC_qqe_ofsf_varlat(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18822, v_18823;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_18822 = v_18793;
// end of prologue
    fn = elt(env, 1); // qqe_ofsf_prepat
    v_18822 = (*qfn1(fn))(fn, v_18822);
    env = stack[-2];
    stack[-1] = v_18822;
    goto v_18803;
v_18799:
    goto v_18809;
v_18805:
    v_18822 = stack[-1];
    fn = elt(env, 2); // qqe_arg2l
    v_18823 = (*qfn1(fn))(fn, v_18822);
    env = stack[-2];
    goto v_18806;
v_18807:
    v_18822 = nil;
    goto v_18808;
v_18809:
    goto v_18805;
v_18806:
    goto v_18807;
v_18808:
    fn = elt(env, 3); // qqe_ofsf_varlterm
    stack[0] = (*qfn2(fn))(fn, v_18823, v_18822);
    env = stack[-2];
    goto v_18800;
v_18801:
    goto v_18818;
v_18814:
    v_18822 = stack[-1];
    fn = elt(env, 4); // qqe_arg2r
    v_18823 = (*qfn1(fn))(fn, v_18822);
    env = stack[-2];
    goto v_18815;
v_18816:
    v_18822 = nil;
    goto v_18817;
v_18818:
    goto v_18814;
v_18815:
    goto v_18816;
v_18817:
    fn = elt(env, 3); // qqe_ofsf_varlterm
    v_18822 = (*qfn2(fn))(fn, v_18823, v_18822);
    env = stack[-2];
    goto v_18802;
v_18803:
    goto v_18799;
v_18800:
    goto v_18801;
v_18802:
    {
        LispObject v_18826 = stack[0];
        fn = elt(env, 5); // union
        return (*qfn2(fn))(fn, v_18826, v_18822);
    }
}



// Code for pasf_zcong

static LispObject CC_pasf_zcong(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_19014, v_19015, v_19016;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_19015 = v_18793;
// end of prologue
    v_19014 = v_19015;
    v_19014 = Lconsp(nil, v_19014);
    env = stack[0];
    if (v_19014 == nil) goto v_18798;
    v_19014 = v_19015;
    v_19014 = qcar(v_19014);
    v_19014 = Lconsp(nil, v_19014);
    env = stack[0];
    if (v_19014 == nil) goto v_18798;
    goto v_18812;
v_18808:
    v_19014 = v_19015;
    v_19014 = qcar(v_19014);
    v_19016 = qcar(v_19014);
    goto v_18809;
v_18810:
    v_19014 = elt(env, 1); // (cong ncong)
    goto v_18811;
v_18812:
    goto v_18808;
v_18809:
    goto v_18810;
v_18811:
    v_19014 = Lmemq(nil, v_19016, v_19014);
    if (v_19014 == nil) goto v_18798;
    v_19014 = v_19015;
    v_19014 = qcar(v_19014);
    v_19014 = qcdr(v_19014);
    if (v_19014 == nil) goto v_18820;
    else goto v_18821;
v_18820:
    goto v_18832;
v_18826:
    goto v_18841;
v_18837:
    goto v_18854;
v_18850:
    v_19016 = v_19015;
    goto v_18851;
v_18852:
    v_19014 = elt(env, 2); // true
    goto v_18853;
v_18854:
    goto v_18850;
v_18851:
    goto v_18852;
v_18853:
    if (v_19016 == v_19014) goto v_18848;
    else goto v_18849;
v_18848:
    v_19014 = lisp_true;
    goto v_18847;
v_18849:
    goto v_18864;
v_18860:
    v_19016 = v_19015;
    goto v_18861;
v_18862:
    v_19014 = elt(env, 3); // false
    goto v_18863;
v_18864:
    goto v_18860;
v_18861:
    goto v_18862;
v_18863:
    v_19014 = (v_19016 == v_19014 ? lisp_true : nil);
    goto v_18847;
    v_19014 = nil;
v_18847:
    if (v_19014 == nil) goto v_18845;
    v_19014 = v_19015;
    v_19016 = v_19014;
    goto v_18843;
v_18845:
    v_19014 = v_19015;
    v_19014 = qcar(v_19014);
    v_19014 = Lconsp(nil, v_19014);
    env = stack[0];
    if (v_19014 == nil) goto v_18870;
    v_19014 = v_19015;
    v_19014 = qcar(v_19014);
    v_19014 = qcar(v_19014);
    v_19016 = v_19014;
    goto v_18843;
v_18870:
    v_19014 = v_19015;
    v_19014 = qcar(v_19014);
    v_19016 = v_19014;
    goto v_18843;
    v_19016 = nil;
v_18843:
    goto v_18838;
v_18839:
    v_19014 = elt(env, 4); // cong
    goto v_18840;
v_18841:
    goto v_18837;
v_18838:
    goto v_18839;
v_18840:
    if (v_19016 == v_19014) goto v_18835;
    else goto v_18836;
v_18835:
    v_19014 = elt(env, 5); // equal
    v_19016 = v_19014;
    goto v_18834;
v_18836:
    v_19014 = elt(env, 6); // neq
    v_19016 = v_19014;
    goto v_18834;
    v_19016 = nil;
v_18834:
    goto v_18827;
v_18828:
    v_19014 = v_19015;
    v_19014 = qcdr(v_19014);
    v_19015 = qcar(v_19014);
    goto v_18829;
v_18830:
    v_19014 = nil;
    goto v_18831;
v_18832:
    goto v_18826;
v_18827:
    goto v_18828;
v_18829:
    goto v_18830;
v_18831:
    return list3(v_19016, v_19015, v_19014);
v_18821:
    v_19014 = v_19015;
    v_19014 = qcdr(v_19014);
    v_19014 = qcar(v_19014);
    if (v_19014 == nil) goto v_18894;
    else goto v_18895;
v_18894:
    goto v_18903;
v_18899:
    goto v_18916;
v_18912:
    v_19016 = v_19015;
    goto v_18913;
v_18914:
    v_19014 = elt(env, 2); // true
    goto v_18915;
v_18916:
    goto v_18912;
v_18913:
    goto v_18914;
v_18915:
    if (v_19016 == v_19014) goto v_18910;
    else goto v_18911;
v_18910:
    v_19014 = lisp_true;
    goto v_18909;
v_18911:
    goto v_18926;
v_18922:
    v_19016 = v_19015;
    goto v_18923;
v_18924:
    v_19014 = elt(env, 3); // false
    goto v_18925;
v_18926:
    goto v_18922;
v_18923:
    goto v_18924;
v_18925:
    v_19014 = (v_19016 == v_19014 ? lisp_true : nil);
    goto v_18909;
    v_19014 = nil;
v_18909:
    if (v_19014 == nil) goto v_18907;
    v_19014 = v_19015;
    v_19016 = v_19014;
    goto v_18905;
v_18907:
    v_19014 = v_19015;
    v_19014 = qcar(v_19014);
    v_19014 = Lconsp(nil, v_19014);
    env = stack[0];
    if (v_19014 == nil) goto v_18932;
    v_19014 = v_19015;
    v_19014 = qcar(v_19014);
    v_19014 = qcar(v_19014);
    v_19016 = v_19014;
    goto v_18905;
v_18932:
    v_19014 = v_19015;
    v_19014 = qcar(v_19014);
    v_19016 = v_19014;
    goto v_18905;
    v_19016 = nil;
v_18905:
    goto v_18900;
v_18901:
    v_19014 = elt(env, 4); // cong
    goto v_18902;
v_18903:
    goto v_18899;
v_18900:
    goto v_18901;
v_18902:
    v_19014 = (v_19016 == v_19014 ? lisp_true : nil);
    goto v_18893;
v_18895:
    v_19014 = nil;
    goto v_18893;
    v_19014 = nil;
v_18893:
    if (v_19014 == nil) goto v_18891;
    v_19014 = elt(env, 2); // true
    goto v_18819;
v_18891:
    v_19014 = v_19015;
    v_19014 = qcdr(v_19014);
    v_19014 = qcar(v_19014);
    if (v_19014 == nil) goto v_18953;
    else goto v_18954;
v_18953:
    goto v_18962;
v_18958:
    goto v_18975;
v_18971:
    v_19016 = v_19015;
    goto v_18972;
v_18973:
    v_19014 = elt(env, 2); // true
    goto v_18974;
v_18975:
    goto v_18971;
v_18972:
    goto v_18973;
v_18974:
    if (v_19016 == v_19014) goto v_18969;
    else goto v_18970;
v_18969:
    v_19014 = lisp_true;
    goto v_18968;
v_18970:
    goto v_18985;
v_18981:
    v_19016 = v_19015;
    goto v_18982;
v_18983:
    v_19014 = elt(env, 3); // false
    goto v_18984;
v_18985:
    goto v_18981;
v_18982:
    goto v_18983;
v_18984:
    v_19014 = (v_19016 == v_19014 ? lisp_true : nil);
    goto v_18968;
    v_19014 = nil;
v_18968:
    if (v_19014 == nil) goto v_18966;
    v_19014 = v_19015;
    v_19016 = v_19014;
    goto v_18964;
v_18966:
    v_19014 = v_19015;
    v_19014 = qcar(v_19014);
    v_19014 = Lconsp(nil, v_19014);
    env = stack[0];
    if (v_19014 == nil) goto v_18991;
    v_19014 = v_19015;
    v_19014 = qcar(v_19014);
    v_19014 = qcar(v_19014);
    v_19016 = v_19014;
    goto v_18964;
v_18991:
    v_19014 = v_19015;
    v_19014 = qcar(v_19014);
    v_19016 = v_19014;
    goto v_18964;
    v_19016 = nil;
v_18964:
    goto v_18959;
v_18960:
    v_19014 = elt(env, 7); // ncong
    goto v_18961;
v_18962:
    goto v_18958;
v_18959:
    goto v_18960;
v_18961:
    v_19014 = (v_19016 == v_19014 ? lisp_true : nil);
    goto v_18952;
v_18954:
    v_19014 = nil;
    goto v_18952;
    v_19014 = nil;
v_18952:
    if (v_19014 == nil) goto v_18950;
    v_19014 = elt(env, 3); // false
    goto v_18819;
v_18950:
    v_19014 = v_19015;
    goto v_18819;
    v_19014 = nil;
v_18819:
    goto v_18796;
v_18798:
    v_19014 = v_19015;
    goto v_18796;
    v_19014 = nil;
v_18796:
    return onevalue(v_19014);
}



// Code for mapcarcar

static LispObject CC_mapcarcar(LispObject env,
                         LispObject v_18793)
{
    env = qenv(env);
    LispObject v_18837;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18793);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18793);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_18837 = v_18793;
// end of prologue
    stack[-3] = v_18837;
    v_18837 = stack[-3];
    if (v_18837 == nil) goto v_18804;
    else goto v_18805;
v_18804:
    v_18837 = nil;
    goto v_18799;
v_18805:
    v_18837 = stack[-3];
    v_18837 = qcar(v_18837);
    v_18837 = qcar(v_18837);
    v_18837 = ncons(v_18837);
    env = stack[-4];
    stack[-1] = v_18837;
    stack[-2] = v_18837;
v_18800:
    v_18837 = stack[-3];
    v_18837 = qcdr(v_18837);
    stack[-3] = v_18837;
    v_18837 = stack[-3];
    if (v_18837 == nil) goto v_18818;
    else goto v_18819;
v_18818:
    v_18837 = stack[-2];
    goto v_18799;
v_18819:
    goto v_18827;
v_18823:
    stack[0] = stack[-1];
    goto v_18824;
v_18825:
    v_18837 = stack[-3];
    v_18837 = qcar(v_18837);
    v_18837 = qcar(v_18837);
    v_18837 = ncons(v_18837);
    env = stack[-4];
    goto v_18826;
v_18827:
    goto v_18823;
v_18824:
    goto v_18825;
v_18826:
    v_18837 = Lrplacd(nil, stack[0], v_18837);
    env = stack[-4];
    v_18837 = stack[-1];
    v_18837 = qcdr(v_18837);
    stack[-1] = v_18837;
    goto v_18800;
v_18799:
    return onevalue(v_18837);
}



// Code for applyfnrd

static LispObject CC_applyfnrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18815, v_18816, v_18817;
    LispObject fn;
    argcheck(nargs, 0, "applyfnrd");
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
    fn = elt(env, 1); // fnrd
    v_18815 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_18815;
    fn = elt(env, 2); // stats_getargs
    v_18815 = (*qfnn(fn))(fn, 0);
    goto v_18811;
v_18805:
    v_18817 = stack[0];
    goto v_18806;
v_18807:
    v_18816 = nil;
    goto v_18808;
v_18809:
    goto v_18810;
v_18811:
    goto v_18805;
v_18806:
    goto v_18807;
v_18808:
    goto v_18809;
v_18810:
    return list2star(v_18817, v_18816, v_18815);
    return onevalue(v_18815);
}



// Code for lessppair

static LispObject CC_lessppair(LispObject env,
                         LispObject v_18793, LispObject v_18794)
{
    env = qenv(env);
    LispObject v_18831, v_18832, v_18833, v_18834;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18832 = v_18794;
    v_18833 = v_18793;
// end of prologue
    goto v_18804;
v_18800:
    v_18831 = v_18833;
    v_18834 = qcar(v_18831);
    goto v_18801;
v_18802:
    v_18831 = v_18832;
    v_18831 = qcar(v_18831);
    goto v_18803;
v_18804:
    goto v_18800;
v_18801:
    goto v_18802;
v_18803:
    if (equal(v_18834, v_18831)) goto v_18798;
    else goto v_18799;
v_18798:
    goto v_18814;
v_18810:
    v_18831 = v_18833;
    v_18831 = qcdr(v_18831);
    goto v_18811;
v_18812:
    v_18832 = qcdr(v_18832);
    goto v_18813;
v_18814:
    goto v_18810;
v_18811:
    goto v_18812;
v_18813:
        return Llessp(nil, v_18831, v_18832);
v_18799:
    goto v_18826;
v_18822:
    v_18831 = v_18833;
    v_18831 = qcar(v_18831);
    goto v_18823;
v_18824:
    v_18832 = qcar(v_18832);
    goto v_18825;
v_18826:
    goto v_18822;
v_18823:
    goto v_18824;
v_18825:
        return Llessp(nil, v_18831, v_18832);
    v_18831 = nil;
    return onevalue(v_18831);
}



setup_type const u34_setup[] =
{
    {"module",                  CC_module,      TOO_MANY_1,    WRONG_NO_1},
    {"arglength",               CC_arglength,   TOO_MANY_1,    WRONG_NO_1},
    {"simp-prop-condense",      CC_simpKpropKcondense,TOO_MANY_1,WRONG_NO_1},
    {"lambda_rfde09ec49c92",    TOO_FEW_2,      CC_lambda_rfde09ec49c92,WRONG_NO_2},
    {"skp_ordp",                TOO_FEW_2,      CC_skp_ordp,   WRONG_NO_2},
    {"ra_l",                    CC_ra_l,        TOO_MANY_1,    WRONG_NO_1},
    {"lalr_extract_nonterminals",CC_lalr_extract_nonterminals,TOO_MANY_1,WRONG_NO_1},
    {"aex_mklcnt",              CC_aex_mklcnt,  TOO_MANY_1,    WRONG_NO_1},
    {"vp2",                     CC_vp2,         TOO_MANY_1,    WRONG_NO_1},
    {"pasf_cein",               CC_pasf_cein,   TOO_MANY_1,    WRONG_NO_1},
    {"ev_2a",                   CC_ev_2a,       TOO_MANY_1,    WRONG_NO_1},
    {"bvarrd",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_bvarrd},
    {"resume",                  TOO_FEW_2,      CC_resume,     WRONG_NO_2},
    {"evaluate",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_evaluate},
    {"toolongexpp",             CC_toolongexpp, TOO_MANY_1,    WRONG_NO_1},
    {"reval3",                  CC_reval3,      TOO_MANY_1,    WRONG_NO_1},
    {"incident",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_incident},
    {"fs:onep:",                CC_fsTonepT,    TOO_MANY_1,    WRONG_NO_1},
    {"formbool",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formbool},
    {"ofsf_lnegrel",            CC_ofsf_lnegrel,TOO_MANY_1,    WRONG_NO_1},
    {"multdfconst",             TOO_FEW_2,      CC_multdfconst,WRONG_NO_2},
    {"sets",                    TOO_FEW_2,      CC_sets,       WRONG_NO_2},
    {"alg_plus",                TOO_FEW_2,      CC_alg_plus,   WRONG_NO_2},
    {"evaluate-horner",         CC_evaluateKhorner,TOO_MANY_1, WRONG_NO_1},
    {"lispreadp",               CC_lispreadp,   TOO_MANY_1,    WRONG_NO_1},
    {"indexsymmetrize",         CC_indexsymmetrize,TOO_MANY_1, WRONG_NO_1},
    {"s_actual_world1",         CC_s_actual_world1,TOO_MANY_1, WRONG_NO_1},
    {"lex_skip_line_comment",   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex_skip_line_comment},
    {"profile_a_package",       CC_profile_a_package,TOO_MANY_1,WRONG_NO_1},
    {"sortedpolynomlistinsert", TOO_FEW_2,      CC_sortedpolynomlistinsert,WRONG_NO_2},
    {"*tayexp2q",               CC_Htayexp2q,   TOO_MANY_1,    WRONG_NO_1},
    {"pasf_smwmkatl",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pasf_smwmkatl},
    {"vdelete",                 TOO_FEW_2,      CC_vdelete,    WRONG_NO_2},
    {"matrixom",                CC_matrixom,    TOO_MANY_1,    WRONG_NO_1},
    {"difference:",             TOO_FEW_2,      CC_differenceT,WRONG_NO_2},
    {"find_buble",              TOO_FEW_2,      CC_find_buble, WRONG_NO_2},
    {"log_assignment",          TOO_FEW_2,      CC_log_assignment,WRONG_NO_2},
    {"remchkf",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_remchkf},
    {"ad_splitname",            CC_ad_splitname,TOO_MANY_1,    WRONG_NO_1},
    {"ratdif",                  TOO_FEW_2,      CC_ratdif,     WRONG_NO_2},
    {"cde_replace_nth",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cde_replace_nth},
    {"gcd-with-number",         TOO_FEW_2,      CC_gcdKwithKnumber,WRONG_NO_2},
    {"lex_process_directive",   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_lex_process_directive},
    {"polynomwrite",            CC_polynomwrite,TOO_MANY_1,    WRONG_NO_1},
    {"talp_sumd",               CC_talp_sumd,   TOO_MANY_1,    WRONG_NO_1},
    {"mri_congp",               CC_mri_congp,   TOO_MANY_1,    WRONG_NO_1},
    {"qqe_ofsf_varlat",         CC_qqe_ofsf_varlat,TOO_MANY_1, WRONG_NO_1},
    {"pasf_zcong",              CC_pasf_zcong,  TOO_MANY_1,    WRONG_NO_1},
    {"mapcarcar",               CC_mapcarcar,   TOO_MANY_1,    WRONG_NO_1},
    {"applyfnrd",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_applyfnrd},
    {"lessppair",               TOO_FEW_2,      CC_lessppair,  WRONG_NO_2},
    {NULL, (one_args *)"u34", (two_args *)"112810 2860623 9282089", 0}
};

// end of generated code
