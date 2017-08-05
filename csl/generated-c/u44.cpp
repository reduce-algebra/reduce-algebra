
// $destdir/u44.c        Machine generated C code

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



// Code for lieninstruc

static LispObject CC_lieninstruc(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_25153, v_25154, v_25155, v_25156;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_24950;
// end of prologue
    v_25153 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_25153;
v_24957:
    goto v_24971;
v_24965:
    stack[0] = elt(env, 1); // difference
    goto v_24966;
v_24967:
    goto v_24981;
v_24975:
    v_25155 = elt(env, 1); // difference
    goto v_24976;
v_24977:
    v_25154 = stack[-4];
    goto v_24978;
v_24979:
    v_25153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24980;
v_24981:
    goto v_24975;
v_24976:
    goto v_24977;
v_24978:
    goto v_24979;
v_24980:
    v_25153 = list3(v_25155, v_25154, v_25153);
    env = stack[-6];
    fn = elt(env, 6); // aeval!*
    v_25154 = (*qfn1(fn))(fn, v_25153);
    env = stack[-6];
    goto v_24968;
v_24969:
    v_25153 = stack[-5];
    goto v_24970;
v_24971:
    goto v_24965;
v_24966:
    goto v_24967;
v_24968:
    goto v_24969;
v_24970:
    v_25153 = list3(stack[0], v_25154, v_25153);
    env = stack[-6];
    fn = elt(env, 7); // aminusp!:
    v_25153 = (*qfn1(fn))(fn, v_25153);
    env = stack[-6];
    if (v_25153 == nil) goto v_24962;
    goto v_24956;
v_24962:
    v_25153 = stack[-5];
    v_25153 = add1(v_25153);
    env = stack[-6];
    stack[-3] = v_25153;
v_24990:
    goto v_25005;
v_24999:
    stack[0] = elt(env, 1); // difference
    goto v_25000;
v_25001:
    v_25153 = stack[-4];
    fn = elt(env, 6); // aeval!*
    v_25154 = (*qfn1(fn))(fn, v_25153);
    env = stack[-6];
    goto v_25002;
v_25003:
    v_25153 = stack[-3];
    goto v_25004;
v_25005:
    goto v_24999;
v_25000:
    goto v_25001;
v_25002:
    goto v_25003;
v_25004:
    v_25153 = list3(stack[0], v_25154, v_25153);
    env = stack[-6];
    fn = elt(env, 7); // aminusp!:
    v_25153 = (*qfn1(fn))(fn, v_25153);
    env = stack[-6];
    if (v_25153 == nil) goto v_24996;
    goto v_24989;
v_24996:
    v_25153 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_25153;
v_25014:
    goto v_25028;
v_25022:
    stack[0] = elt(env, 1); // difference
    goto v_25023;
v_25024:
    v_25153 = stack[-4];
    fn = elt(env, 6); // aeval!*
    v_25154 = (*qfn1(fn))(fn, v_25153);
    env = stack[-6];
    goto v_25025;
v_25026:
    v_25153 = stack[-2];
    goto v_25027;
v_25028:
    goto v_25022;
v_25023:
    goto v_25024;
v_25025:
    goto v_25026;
v_25027:
    v_25153 = list3(stack[0], v_25154, v_25153);
    env = stack[-6];
    fn = elt(env, 7); // aminusp!:
    v_25153 = (*qfn1(fn))(fn, v_25153);
    env = stack[-6];
    if (v_25153 == nil) goto v_25019;
    goto v_25013;
v_25019:
    goto v_25039;
v_25035:
    goto v_25049;
v_25041:
    v_25156 = elt(env, 2); // lie_cc
    goto v_25042;
v_25043:
    v_25155 = stack[-5];
    goto v_25044;
v_25045:
    v_25154 = stack[-3];
    goto v_25046;
v_25047:
    v_25153 = stack[-2];
    goto v_25048;
v_25049:
    goto v_25041;
v_25042:
    goto v_25043;
v_25044:
    goto v_25045;
v_25046:
    goto v_25047;
v_25048:
    stack[0] = list4(v_25156, v_25155, v_25154, v_25153);
    env = stack[-6];
    goto v_25036;
v_25037:
    goto v_25064;
v_25056:
    v_25156 = elt(env, 3); // lienstrucin
    goto v_25057;
v_25058:
    v_25155 = stack[-5];
    goto v_25059;
v_25060:
    v_25154 = stack[-3];
    goto v_25061;
v_25062:
    v_25153 = stack[-2];
    goto v_25063;
v_25064:
    goto v_25056;
v_25057:
    goto v_25058;
v_25059:
    goto v_25060;
v_25061:
    goto v_25062;
v_25063:
    v_25153 = list4(v_25156, v_25155, v_25154, v_25153);
    env = stack[-6];
    fn = elt(env, 6); // aeval!*
    v_25153 = (*qfn1(fn))(fn, v_25153);
    env = stack[-6];
    goto v_25038;
v_25039:
    goto v_25035;
v_25036:
    goto v_25037;
v_25038:
    fn = elt(env, 8); // setk
    v_25153 = (*qfn2(fn))(fn, stack[0], v_25153);
    env = stack[-6];
    goto v_25074;
v_25070:
    goto v_25084;
v_25076:
    v_25156 = elt(env, 2); // lie_cc
    goto v_25077;
v_25078:
    v_25155 = stack[-3];
    goto v_25079;
v_25080:
    v_25154 = stack[-5];
    goto v_25081;
v_25082:
    v_25153 = stack[-2];
    goto v_25083;
v_25084:
    goto v_25076;
v_25077:
    goto v_25078;
v_25079:
    goto v_25080;
v_25081:
    goto v_25082;
v_25083:
    stack[-1] = list4(v_25156, v_25155, v_25154, v_25153);
    env = stack[-6];
    goto v_25071;
v_25072:
    goto v_25095;
v_25091:
    stack[0] = elt(env, 4); // minus
    goto v_25092;
v_25093:
    goto v_25106;
v_25098:
    v_25156 = elt(env, 3); // lienstrucin
    goto v_25099;
v_25100:
    v_25155 = stack[-5];
    goto v_25101;
v_25102:
    v_25154 = stack[-3];
    goto v_25103;
v_25104:
    v_25153 = stack[-2];
    goto v_25105;
v_25106:
    goto v_25098;
v_25099:
    goto v_25100;
v_25101:
    goto v_25102;
v_25103:
    goto v_25104;
v_25105:
    v_25153 = list4(v_25156, v_25155, v_25154, v_25153);
    env = stack[-6];
    goto v_25094;
v_25095:
    goto v_25091;
v_25092:
    goto v_25093;
v_25094:
    v_25153 = list2(stack[0], v_25153);
    env = stack[-6];
    fn = elt(env, 6); // aeval!*
    v_25153 = (*qfn1(fn))(fn, v_25153);
    env = stack[-6];
    goto v_25073;
v_25074:
    goto v_25070;
v_25071:
    goto v_25072;
v_25073:
    fn = elt(env, 8); // setk
    v_25153 = (*qfn2(fn))(fn, stack[-1], v_25153);
    env = stack[-6];
    v_25153 = stack[-2];
    goto v_25121;
v_25115:
    v_25155 = elt(env, 5); // plus
    goto v_25116;
v_25117:
    v_25154 = v_25153;
    goto v_25118;
v_25119:
    v_25153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25120;
v_25121:
    goto v_25115;
v_25116:
    goto v_25117;
v_25118:
    goto v_25119;
v_25120:
    v_25153 = list3(v_25155, v_25154, v_25153);
    env = stack[-6];
    fn = elt(env, 6); // aeval!*
    v_25153 = (*qfn1(fn))(fn, v_25153);
    env = stack[-6];
    stack[-2] = v_25153;
    goto v_25014;
v_25013:
    v_25153 = stack[-3];
    goto v_25135;
v_25129:
    v_25155 = elt(env, 5); // plus
    goto v_25130;
v_25131:
    v_25154 = v_25153;
    goto v_25132;
v_25133:
    v_25153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25134;
v_25135:
    goto v_25129;
v_25130:
    goto v_25131;
v_25132:
    goto v_25133;
v_25134:
    v_25153 = list3(v_25155, v_25154, v_25153);
    env = stack[-6];
    fn = elt(env, 6); // aeval!*
    v_25153 = (*qfn1(fn))(fn, v_25153);
    env = stack[-6];
    stack[-3] = v_25153;
    goto v_24990;
v_24989:
    v_25153 = stack[-5];
    goto v_25149;
v_25143:
    v_25155 = elt(env, 5); // plus
    goto v_25144;
v_25145:
    v_25154 = v_25153;
    goto v_25146;
v_25147:
    v_25153 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25148;
v_25149:
    goto v_25143;
v_25144:
    goto v_25145;
v_25146:
    goto v_25147;
v_25148:
    v_25153 = list3(v_25155, v_25154, v_25153);
    env = stack[-6];
    fn = elt(env, 6); // aeval!*
    v_25153 = (*qfn1(fn))(fn, v_25153);
    env = stack[-6];
    stack[-5] = v_25153;
    goto v_24957;
v_24956:
    v_25153 = nil;
    return onevalue(v_25153);
}



// Code for appr

static LispObject CC_appr(LispObject env,
                         LispObject v_24950, LispObject v_24951)
{
    env = qenv(env);
    LispObject v_24977, v_24978, v_24979;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24951,v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24950,v_24951);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_24977 = v_24951;
    v_24978 = v_24950;
// end of prologue
v_24956:
    v_24979 = v_24978;
    if (v_24979 == nil) goto v_24959;
    else goto v_24960;
v_24959:
    goto v_24955;
v_24960:
    v_24979 = v_24978;
    v_24979 = qcdr(v_24979);
    stack[0] = v_24979;
    goto v_24972;
v_24968:
    v_24978 = qcar(v_24978);
    goto v_24969;
v_24970:
    goto v_24971;
v_24972:
    goto v_24968;
v_24969:
    goto v_24970;
v_24971:
    v_24977 = cons(v_24978, v_24977);
    env = stack[-1];
    v_24978 = stack[0];
    goto v_24956;
    v_24977 = nil;
v_24955:
    return onevalue(v_24977);
}



// Code for fctargs

static LispObject CC_fctargs(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24966, v_24967;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24966 = v_24950;
// end of prologue
    goto v_24960;
v_24956:
    goto v_24957;
v_24958:
    v_24967 = qvalue(elt(env, 1)); // depl!*
    goto v_24959;
v_24960:
    goto v_24956;
v_24957:
    goto v_24958;
v_24959:
    v_24967 = Lassoc(nil, v_24966, v_24967);
    v_24966 = v_24967;
    if (v_24967 == nil) goto v_24955;
    v_24966 = qcdr(v_24966);
    goto v_24953;
v_24955:
    v_24966 = nil;
v_24953:
    return onevalue(v_24966);
}



// Code for cgp_greenp

static LispObject CC_cgp_greenp(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24955;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
// copy arguments values to proper place
    v_24955 = v_24950;
// end of prologue
    fn = elt(env, 1); // cgp_rp
    v_24955 = (*qfn1(fn))(fn, v_24955);
    v_24955 = (v_24955 == nil ? lisp_true : nil);
    return onevalue(v_24955);
}



// Code for integralir

static LispObject CC_integralir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25031, v_25032;
    LispObject fn;
    argcheck(nargs, 0, "integralir");
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
    goto v_24963;
v_24959:
    v_25032 = qvalue(elt(env, 1)); // atts
    goto v_24960;
v_24961:
    v_25031 = elt(env, 2); // name
    goto v_24962;
v_24963:
    goto v_24959;
v_24960:
    goto v_24961;
v_24962:
    fn = elt(env, 6); // find
    v_25031 = (*qfn2(fn))(fn, v_25032, v_25031);
    env = stack[-3];
    v_25031 = Lintern(nil, v_25031);
    env = stack[-3];
    stack[-1] = v_25031;
    v_25031 = elt(env, 3); // (bvar x 1)
    v_25031 = ncons(v_25031);
    env = stack[-3];
    stack[0] = v_25031;
    goto v_24977;
v_24973:
    v_25032 = stack[-1];
    goto v_24974;
v_24975:
    v_25031 = elt(env, 4); // defint
    goto v_24976;
v_24977:
    goto v_24973;
v_24974:
    goto v_24975;
v_24976:
    if (v_25032 == v_25031) goto v_24971;
    else goto v_24972;
v_24971:
    fn = elt(env, 7); // lex
    v_25031 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    fn = elt(env, 8); // omobj
    v_25031 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    goto v_24970;
v_24972:
v_24970:
    fn = elt(env, 7); // lex
    v_25031 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    fn = elt(env, 8); // omobj
    v_25031 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[-2] = v_25031;
    v_25031 = stack[-2];
    v_25031 = Lconsp(nil, v_25031);
    env = stack[-3];
    if (v_25031 == nil) goto v_24988;
    goto v_24999;
v_24995:
    v_25031 = stack[-2];
    v_25032 = qcar(v_25031);
    goto v_24996;
v_24997:
    v_25031 = elt(env, 5); // lambda
    goto v_24998;
v_24999:
    goto v_24995;
v_24996:
    goto v_24997;
v_24998:
    if (v_25032 == v_25031) goto v_24993;
    else goto v_24994;
v_24993:
    v_25031 = stack[-2];
    fn = elt(env, 9); // lambdavar
    v_25031 = (*qfn1(fn))(fn, v_25031);
    env = stack[-3];
    stack[0] = v_25031;
    v_25031 = stack[-2];
    fn = elt(env, 10); // lambdafun
    v_25031 = (*qfn1(fn))(fn, v_25031);
    env = stack[-3];
    stack[-2] = v_25031;
    goto v_24992;
v_24994:
v_24992:
    goto v_24986;
v_24988:
v_24986:
    goto v_25013;
v_25009:
    goto v_25019;
v_25015:
    v_25032 = stack[-1];
    goto v_25016;
v_25017:
    v_25031 = nil;
    goto v_25018;
v_25019:
    goto v_25015;
v_25016:
    goto v_25017;
v_25018:
    stack[-1] = list2(v_25032, v_25031);
    env = stack[-3];
    goto v_25010;
v_25011:
    goto v_25027;
v_25023:
    goto v_25024;
v_25025:
    v_25031 = stack[-2];
    v_25031 = ncons(v_25031);
    env = stack[-3];
    goto v_25026;
v_25027:
    goto v_25023;
v_25024:
    goto v_25025;
v_25026:
    v_25031 = Lappend(nil, stack[0], v_25031);
    goto v_25012;
v_25013:
    goto v_25009;
v_25010:
    goto v_25011;
v_25012:
    {
        LispObject v_25036 = stack[-1];
        return Lappend(nil, v_25036, v_25031);
    }
    return onevalue(v_25031);
}



// Code for simpu

static LispObject CC_simpu(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24989, v_24990;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_24990 = v_24950;
// end of prologue
    goto v_24957;
v_24953:
    goto v_24964;
v_24960:
    goto v_24970;
v_24966:
    goto v_24978;
v_24972:
    stack[-1] = elt(env, 1); // u
    goto v_24973;
v_24974:
    v_24989 = v_24990;
    stack[0] = qcar(v_24989);
    goto v_24975;
v_24976:
    v_24989 = v_24990;
    v_24989 = qcdr(v_24989);
    fn = elt(env, 2); // ordn
    v_24989 = (*qfn1(fn))(fn, v_24989);
    env = stack[-2];
    v_24989 = Lreverse(nil, v_24989);
    env = stack[-2];
    goto v_24977;
v_24978:
    goto v_24972;
v_24973:
    goto v_24974;
v_24975:
    goto v_24976;
v_24977:
    v_24990 = list2star(stack[-1], stack[0], v_24989);
    env = stack[-2];
    goto v_24967;
v_24968:
    v_24989 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24969;
v_24970:
    goto v_24966;
v_24967:
    goto v_24968;
v_24969:
    fn = elt(env, 3); // mksp
    v_24990 = (*qfn2(fn))(fn, v_24990, v_24989);
    env = stack[-2];
    goto v_24961;
v_24962:
    v_24989 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24963;
v_24964:
    goto v_24960;
v_24961:
    goto v_24962;
v_24963:
    v_24989 = cons(v_24990, v_24989);
    env = stack[-2];
    v_24990 = ncons(v_24989);
    goto v_24954;
v_24955:
    v_24989 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24956;
v_24957:
    goto v_24953;
v_24954:
    goto v_24955;
v_24956:
    return cons(v_24990, v_24989);
}



// Code for dip2a

static LispObject CC_dip2a(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24963, v_24964;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_24964 = v_24950;
// end of prologue
    v_24963 = v_24964;
    if (v_24963 == nil) goto v_24954;
    else goto v_24955;
v_24954:
    v_24963 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24953;
v_24955:
    v_24963 = v_24964;
    fn = elt(env, 1); // dip2a1
    v_24963 = (*qfn1(fn))(fn, v_24963);
    env = stack[0];
    {
        fn = elt(env, 2); // dipreplus
        return (*qfn1(fn))(fn, v_24963);
    }
    v_24963 = nil;
v_24953:
    return onevalue(v_24963);
}



// Code for mkexdf

static LispObject CC_mkexdf(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24975, v_24976;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_24975 = v_24950;
// end of prologue
    goto v_24966;
v_24962:
    v_24976 = elt(env, 1); // d
    goto v_24963;
v_24964:
    goto v_24965;
v_24966:
    goto v_24962;
v_24963:
    goto v_24964;
v_24965:
    v_24975 = list2(v_24976, v_24975);
    env = stack[-1];
    stack[0] = v_24975;
    fn = elt(env, 2); // opmtch
    v_24975 = (*qfn1(fn))(fn, v_24975);
    env = stack[-1];
    v_24976 = v_24975;
    if (v_24975 == nil) goto v_24959;
    v_24975 = v_24976;
    {
        fn = elt(env, 3); // partitop
        return (*qfn1(fn))(fn, v_24975);
    }
v_24959:
    v_24975 = stack[0];
    {
        fn = elt(env, 4); // mkupf
        return (*qfn1(fn))(fn, v_24975);
    }
    v_24975 = nil;
    return onevalue(v_24975);
}



// Code for markedvarp

static LispObject CC_markedvarp(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24960, v_24961;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24960 = v_24950;
// end of prologue
    goto v_24957;
v_24953:
    goto v_24954;
v_24955:
    v_24961 = elt(env, 1); // !*marked!*
    goto v_24956;
v_24957:
    goto v_24953;
v_24954:
    goto v_24955;
v_24956:
        return Lflagp(nil, v_24960, v_24961);
}



// Code for ev!-edgeloop

static LispObject CC_evKedgeloop(LispObject env,
                         LispObject v_24950, LispObject v_24951)
{
    env = qenv(env);
    LispObject v_24970, v_24971, v_24972;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24970 = v_24951;
    v_24971 = v_24950;
// end of prologue
    goto v_24958;
v_24954:
    v_24972 = qvalue(elt(env, 1)); // ndim!*
    goto v_24955;
v_24956:
    goto v_24964;
v_24960:
    v_24971 = qcar(v_24971);
    goto v_24961;
v_24962:
    goto v_24963;
v_24964:
    goto v_24960;
v_24961:
    goto v_24962;
v_24963:
    v_24970 = Lassoc(nil, v_24971, v_24970);
    v_24970 = qcdr(v_24970);
    goto v_24957;
v_24958:
    goto v_24954;
v_24955:
    goto v_24956;
v_24957:
    {
        fn = elt(env, 2); // binc
        return (*qfn2(fn))(fn, v_24972, v_24970);
    }
}



// Code for prepsq!*0

static LispObject CC_prepsqH0(LispObject env,
                         LispObject v_24950, LispObject v_24951)
{
    env = qenv(env);
    LispObject v_25023, v_25024, v_25025;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24951,v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24950,v_24951);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_24951;
    stack[-2] = v_24950;
// end of prologue
    v_25023 = stack[-2];
    v_25023 = qcar(v_25023);
    if (v_25023 == nil) goto v_24958;
    else goto v_24959;
v_24958:
    v_25023 = nil;
    goto v_24957;
v_24959:
    goto v_24969;
v_24965:
    goto v_24975;
v_24971:
    v_25023 = stack[-2];
    v_25024 = qcar(v_25023);
    goto v_24972;
v_24973:
    v_25023 = stack[-2];
    v_25023 = qcdr(v_25023);
    goto v_24974;
v_24975:
    goto v_24971;
v_24972:
    goto v_24973;
v_24974:
    fn = elt(env, 1); // gcdf
    v_25024 = (*qfn2(fn))(fn, v_25024, v_25023);
    env = stack[-4];
    stack[-3] = v_25024;
    goto v_24966;
v_24967:
    v_25023 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24968;
v_24969:
    goto v_24965;
v_24966:
    goto v_24967;
v_24968:
    if (v_25024 == v_25023) goto v_24964;
    goto v_24988;
v_24982:
    goto v_24994;
v_24990:
    v_25023 = stack[-2];
    v_25024 = qcar(v_25023);
    goto v_24991;
v_24992:
    v_25023 = stack[-3];
    goto v_24993;
v_24994:
    goto v_24990;
v_24991:
    goto v_24992;
v_24993:
    fn = elt(env, 2); // quotf!-fail
    stack[0] = (*qfn2(fn))(fn, v_25024, v_25023);
    env = stack[-4];
    goto v_24983;
v_24984:
    goto v_25003;
v_24999:
    v_25023 = stack[-2];
    v_25024 = qcdr(v_25023);
    goto v_25000;
v_25001:
    v_25023 = stack[-3];
    goto v_25002;
v_25003:
    goto v_24999;
v_25000:
    goto v_25001;
v_25002:
    fn = elt(env, 2); // quotf!-fail
    v_25024 = (*qfn2(fn))(fn, v_25024, v_25023);
    env = stack[-4];
    goto v_24985;
v_24986:
    v_25023 = stack[-1];
    goto v_24987;
v_24988:
    goto v_24982;
v_24983:
    goto v_24984;
v_24985:
    goto v_24986;
v_24987:
    {
        LispObject v_25030 = stack[0];
        fn = elt(env, 3); // prepsq!*1
        return (*qfnn(fn))(fn, 3, v_25030, v_25024, v_25023);
    }
v_24964:
    goto v_25017;
v_25011:
    v_25023 = stack[-2];
    v_25025 = qcar(v_25023);
    goto v_25012;
v_25013:
    v_25023 = stack[-2];
    v_25024 = qcdr(v_25023);
    goto v_25014;
v_25015:
    v_25023 = stack[-1];
    goto v_25016;
v_25017:
    goto v_25011;
v_25012:
    goto v_25013;
v_25014:
    goto v_25015;
v_25016:
    {
        fn = elt(env, 3); // prepsq!*1
        return (*qfnn(fn))(fn, 3, v_25025, v_25024, v_25023);
    }
    v_25023 = nil;
v_24957:
    return onevalue(v_25023);
}



// Code for super_vectorfield

static LispObject CC_super_vectorfield(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25193, v_25194, v_25195, v_25196, v_25197;
    LispObject fn;
    LispObject v_24952, v_24951, v_24950;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "super_vectorfield");
    va_start(aa, nargs);
    v_24950 = va_arg(aa, LispObject);
    v_24951 = va_arg(aa, LispObject);
    v_24952 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24952,v_24951,v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24950,v_24951,v_24952);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_24952;
    stack[-2] = v_24951;
    stack[-3] = v_24950;
// end of prologue
    v_25193 = stack[-3];
    if (symbolp(v_25193)) goto v_24960;
    goto v_24973;
v_24963:
    v_25197 = elt(env, 1); // "SUPER_VECTORFIELD:"
    goto v_24964;
v_24965:
    v_25196 = stack[-3];
    goto v_24966;
v_24967:
    v_25195 = elt(env, 2); // "is not an identifier"
    goto v_24968;
v_24969:
    v_25194 = nil;
    goto v_24970;
v_24971:
    v_25193 = lisp_true;
    goto v_24972;
v_24973:
    goto v_24963;
v_24964:
    goto v_24965;
v_24966:
    goto v_24967;
v_24968:
    goto v_24969;
v_24970:
    goto v_24971;
v_24972:
    fn = elt(env, 14); // msgpri
    v_25193 = (*qfnn(fn))(fn, 5, v_25197, v_25196, v_25195, v_25194, v_25193);
    env = stack[-5];
    goto v_24958;
v_24960:
v_24958:
    goto v_24986;
v_24980:
    v_25195 = stack[-3];
    goto v_24981;
v_24982:
    v_25194 = elt(env, 3); // simpfn
    goto v_24983;
v_24984:
    v_25193 = elt(env, 4); // super_der_simp
    goto v_24985;
v_24986:
    goto v_24980;
v_24981:
    goto v_24982;
v_24983:
    goto v_24984;
v_24985:
    v_25193 = Lputprop(nil, 3, v_25195, v_25194, v_25193);
    env = stack[-5];
    goto v_24995;
v_24991:
    v_25193 = stack[-3];
    v_25194 = ncons(v_25193);
    env = stack[-5];
    goto v_24992;
v_24993:
    v_25193 = elt(env, 5); // full
    goto v_24994;
v_24995:
    goto v_24991;
v_24992:
    goto v_24993;
v_24994:
    v_25193 = Lflag(nil, v_25194, v_25193);
    env = stack[-5];
    v_25193 = stack[-2];
    if (v_25193 == nil) goto v_25001;
    else goto v_25002;
v_25001:
    v_25193 = stack[-2];
    goto v_25000;
v_25002:
    v_25193 = stack[-2];
    if (!consp(v_25193)) goto v_25005;
    else goto v_25006;
v_25005:
    v_25193 = stack[-2];
    v_25193 = ncons(v_25193);
    env = stack[-5];
    goto v_25000;
v_25006:
    goto v_25016;
v_25012:
    v_25193 = stack[-2];
    v_25194 = qcar(v_25193);
    goto v_25013;
v_25014:
    v_25193 = elt(env, 6); // list
    goto v_25015;
v_25016:
    goto v_25012;
v_25013:
    goto v_25014;
v_25015:
    if (v_25194 == v_25193) goto v_25010;
    else goto v_25011;
v_25010:
    v_25193 = stack[-2];
    v_25193 = qcdr(v_25193);
    goto v_25000;
v_25011:
    v_25193 = stack[-2];
    goto v_25000;
    v_25193 = nil;
v_25000:
    stack[-2] = v_25193;
    v_25193 = stack[0];
    if (v_25193 == nil) goto v_25027;
    else goto v_25028;
v_25027:
    v_25193 = stack[0];
    goto v_25026;
v_25028:
    v_25193 = stack[0];
    if (!consp(v_25193)) goto v_25031;
    else goto v_25032;
v_25031:
    v_25193 = stack[0];
    v_25193 = ncons(v_25193);
    env = stack[-5];
    goto v_25026;
v_25032:
    goto v_25042;
v_25038:
    v_25193 = stack[0];
    v_25194 = qcar(v_25193);
    goto v_25039;
v_25040:
    v_25193 = elt(env, 6); // list
    goto v_25041;
v_25042:
    goto v_25038;
v_25039:
    goto v_25040;
v_25041:
    if (v_25194 == v_25193) goto v_25036;
    else goto v_25037;
v_25036:
    v_25193 = stack[0];
    v_25193 = qcdr(v_25193);
    goto v_25026;
v_25037:
    v_25193 = stack[0];
    goto v_25026;
    v_25193 = nil;
v_25026:
    stack[0] = v_25193;
    v_25193 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_25193;
    v_25193 = stack[0];
    stack[-1] = v_25193;
v_25055:
    v_25193 = stack[-1];
    if (v_25193 == nil) goto v_25059;
    else goto v_25060;
v_25059:
    goto v_25054;
v_25060:
    v_25193 = stack[-1];
    v_25193 = qcar(v_25193);
    stack[0] = v_25193;
    goto v_25078;
v_25074:
    v_25193 = stack[0];
    v_25194 = Llength(nil, v_25193);
    env = stack[-5];
    goto v_25075;
v_25076:
    v_25193 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_25077;
v_25078:
    goto v_25074;
v_25075:
    goto v_25076;
v_25077:
    if (v_25194 == v_25193) goto v_25073;
    v_25193 = lisp_true;
    goto v_25071;
v_25073:
    goto v_25093;
v_25089:
    v_25193 = stack[0];
    v_25194 = qcar(v_25193);
    goto v_25090;
v_25091:
    v_25193 = elt(env, 7); // ext
    goto v_25092;
v_25093:
    goto v_25089;
v_25090:
    goto v_25091;
v_25092:
    if (v_25194 == v_25193) goto v_25088;
    v_25193 = lisp_true;
    goto v_25086;
v_25088:
    v_25193 = stack[0];
    v_25193 = qcdr(v_25193);
    v_25193 = qcar(v_25193);
    v_25193 = integerp(v_25193);
    v_25193 = (v_25193 == nil ? lisp_true : nil);
    goto v_25086;
    v_25193 = nil;
v_25086:
    goto v_25071;
    v_25193 = nil;
v_25071:
    if (v_25193 == nil) goto v_25069;
    goto v_25116;
v_25106:
    v_25197 = elt(env, 1); // "SUPER_VECTORFIELD:"
    goto v_25107;
v_25108:
    v_25196 = stack[0];
    goto v_25109;
v_25110:
    v_25195 = elt(env, 8); // "not a valid odd variable"
    goto v_25111;
v_25112:
    v_25194 = nil;
    goto v_25113;
v_25114:
    v_25193 = lisp_true;
    goto v_25115;
v_25116:
    goto v_25106;
v_25107:
    goto v_25108;
v_25109:
    goto v_25110;
v_25111:
    goto v_25112;
v_25113:
    goto v_25114;
v_25115:
    fn = elt(env, 14); // msgpri
    v_25193 = (*qfnn(fn))(fn, 5, v_25197, v_25196, v_25195, v_25194, v_25193);
    env = stack[-5];
    goto v_25067;
v_25069:
    goto v_25129;
v_25125:
    v_25194 = stack[-4];
    goto v_25126;
v_25127:
    v_25193 = stack[0];
    v_25193 = qcdr(v_25193);
    v_25193 = qcar(v_25193);
    goto v_25128;
v_25129:
    goto v_25125;
v_25126:
    goto v_25127;
v_25128:
    fn = elt(env, 15); // max
    v_25193 = (*qfn2(fn))(fn, v_25194, v_25193);
    env = stack[-5];
    stack[-4] = v_25193;
    goto v_25067;
v_25067:
    v_25193 = stack[-1];
    v_25193 = qcdr(v_25193);
    stack[-1] = v_25193;
    goto v_25055;
v_25054:
    goto v_25143;
v_25137:
    v_25195 = stack[-3];
    goto v_25138;
v_25139:
    v_25194 = elt(env, 9); // variables
    goto v_25140;
v_25141:
    v_25193 = stack[-2];
    goto v_25142;
v_25143:
    goto v_25137;
v_25138:
    goto v_25139;
v_25140:
    goto v_25141;
v_25142:
    v_25193 = Lputprop(nil, 3, v_25195, v_25194, v_25193);
    env = stack[-5];
    goto v_25154;
v_25148:
    stack[-1] = stack[-3];
    goto v_25149;
v_25150:
    stack[0] = elt(env, 10); // even_dimension
    goto v_25151;
v_25152:
    v_25193 = stack[-2];
    v_25193 = Llength(nil, v_25193);
    env = stack[-5];
    goto v_25153;
v_25154:
    goto v_25148;
v_25149:
    goto v_25150;
v_25151:
    goto v_25152;
v_25153:
    v_25193 = Lputprop(nil, 3, stack[-1], stack[0], v_25193);
    env = stack[-5];
    goto v_25166;
v_25160:
    v_25195 = stack[-3];
    goto v_25161;
v_25162:
    v_25194 = elt(env, 11); // odd_dimension
    goto v_25163;
v_25164:
    v_25193 = stack[-4];
    goto v_25165;
v_25166:
    goto v_25160;
v_25161:
    goto v_25162;
v_25163:
    goto v_25164;
v_25165:
    v_25193 = Lputprop(nil, 3, v_25195, v_25194, v_25193);
    env = stack[-5];
    goto v_25177;
v_25171:
    v_25195 = stack[-3];
    goto v_25172;
v_25173:
    v_25194 = elt(env, 12); // setkfn
    goto v_25174;
v_25175:
    v_25193 = elt(env, 13); // setk_super_vectorfield
    goto v_25176;
v_25177:
    goto v_25171;
v_25172:
    goto v_25173;
v_25174:
    goto v_25175;
v_25176:
    v_25193 = Lputprop(nil, 3, v_25195, v_25194, v_25193);
    env = stack[-5];
    goto v_25188;
v_25182:
    stack[0] = elt(env, 6); // list
    goto v_25183;
v_25184:
    v_25193 = stack[-2];
    v_25194 = Llength(nil, v_25193);
    goto v_25185;
v_25186:
    v_25193 = stack[-4];
    goto v_25187;
v_25188:
    goto v_25182;
v_25183:
    goto v_25184;
v_25185:
    goto v_25186;
v_25187:
    {
        LispObject v_25203 = stack[0];
        return list3(v_25203, v_25194, v_25193);
    }
    return onevalue(v_25193);
}



// Code for co_hfn

static LispObject CC_co_hfn(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24964;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24950;
// end of prologue
    goto v_24957;
v_24953:
    v_24964 = stack[0];
    v_24964 = qcdr(v_24964);
    fn = elt(env, 1); // cl_fvarl1
    stack[-1] = (*qfn1(fn))(fn, v_24964);
    env = stack[-2];
    goto v_24954;
v_24955:
    v_24964 = stack[0];
    v_24964 = qcdr(v_24964);
    fn = elt(env, 2); // rl_atnum
    v_24964 = (*qfn1(fn))(fn, v_24964);
    goto v_24956;
v_24957:
    goto v_24953;
v_24954:
    goto v_24955;
v_24956:
    {
        LispObject v_24967 = stack[-1];
        return list2(v_24967, v_24964);
    }
}



// Code for rtypepart

static LispObject CC_rtypepart(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24962;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_24962 = v_24950;
// end of prologue
    fn = elt(env, 2); // getrtypecar
    v_24962 = (*qfn1(fn))(fn, v_24962);
    env = stack[0];
    if (v_24962 == nil) goto v_24955;
    v_24962 = elt(env, 1); // yetunknowntype
    goto v_24953;
v_24955:
    v_24962 = nil;
    goto v_24953;
    v_24962 = nil;
v_24953:
    return onevalue(v_24962);
}



// Code for expf

static LispObject CC_expf(LispObject env,
                         LispObject v_24950, LispObject v_24951)
{
    env = qenv(env);
    LispObject v_25167, v_25168, v_25169;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24951,v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24950,v_24951);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_24951;
    stack[-1] = v_24950;
// end of prologue
    v_25167 = stack[-1];
    if (v_25167 == nil) goto v_24955;
    else goto v_24956;
v_24955:
    v_25167 = nil;
    goto v_24954;
v_24956:
    goto v_24965;
v_24961:
    v_25168 = stack[-1];
    goto v_24962;
v_24963:
    v_25167 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24964;
v_24965:
    goto v_24961;
v_24962:
    goto v_24963;
v_24964:
    if (v_25168 == v_25167) goto v_24959;
    else goto v_24960;
v_24959:
    v_25167 = stack[-1];
    goto v_24954;
v_24960:
    v_25167 = stack[-1];
    if (!consp(v_25167)) goto v_24969;
    else goto v_24970;
v_24969:
    goto v_24977;
v_24973:
    stack[-2] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24974;
v_24975:
    goto v_24984;
v_24980:
    goto v_24981;
v_24982:
    v_25167 = stack[0];
    v_25167 = negate(v_25167);
    env = stack[-3];
    goto v_24983;
v_24984:
    goto v_24980;
v_24981:
    goto v_24982;
v_24983:
    v_25167 = Lexpt(nil, stack[-1], v_25167);
    env = stack[-3];
    goto v_24976;
v_24977:
    goto v_24973;
v_24974:
    goto v_24975;
v_24976:
    {
        LispObject v_25173 = stack[-2];
        fn = elt(env, 3); // mkrn
        return (*qfn2(fn))(fn, v_25173, v_25167);
    }
v_24970:
    v_25167 = stack[-1];
    if (!consp(v_25167)) goto v_24992;
    else goto v_24993;
v_24992:
    v_25167 = lisp_true;
    goto v_24991;
v_24993:
    v_25167 = stack[-1];
    v_25167 = qcar(v_25167);
    v_25167 = (consp(v_25167) ? nil : lisp_true);
    goto v_24991;
    v_25167 = nil;
v_24991:
    if (v_25167 == nil) goto v_24989;
    goto v_25006;
v_25002:
    v_25168 = stack[-1];
    goto v_25003;
v_25004:
    v_25167 = stack[0];
    goto v_25005;
v_25006:
    goto v_25002;
v_25003:
    goto v_25004;
v_25005:
    {
        fn = elt(env, 4); // !:expt
        return (*qfn2(fn))(fn, v_25168, v_25167);
    }
v_24989:
    v_25167 = stack[-1];
    v_25167 = qcdr(v_25167);
    if (v_25167 == nil) goto v_25010;
    goto v_25018;
v_25014:
    v_25168 = stack[-1];
    goto v_25015;
v_25016:
    v_25167 = stack[0];
    goto v_25017;
v_25018:
    goto v_25014;
v_25015:
    goto v_25016;
v_25017:
    {
        fn = elt(env, 5); // mksp!*
        return (*qfn2(fn))(fn, v_25168, v_25167);
    }
v_25010:
    goto v_25027;
v_25023:
    v_25167 = stack[-1];
    v_25167 = qcar(v_25167);
    v_25167 = qcar(v_25167);
    v_25168 = qcdr(v_25167);
    goto v_25024;
v_25025:
    v_25167 = qvalue(elt(env, 1)); // frlis!*
    goto v_25026;
v_25027:
    goto v_25023;
v_25024:
    goto v_25025;
v_25026:
    v_25167 = Lmemq(nil, v_25168, v_25167);
    if (v_25167 == nil) goto v_25022;
    goto v_25040;
v_25036:
    goto v_25046;
v_25042:
    goto v_25055;
v_25049:
    v_25169 = elt(env, 2); // expt
    goto v_25050;
v_25051:
    v_25167 = stack[-1];
    v_25167 = qcar(v_25167);
    v_25167 = qcar(v_25167);
    v_25168 = qcar(v_25167);
    goto v_25052;
v_25053:
    v_25167 = stack[-1];
    v_25167 = qcar(v_25167);
    v_25167 = qcar(v_25167);
    v_25167 = qcdr(v_25167);
    goto v_25054;
v_25055:
    goto v_25049;
v_25050:
    goto v_25051;
v_25052:
    goto v_25053;
v_25054:
    v_25167 = list3(v_25169, v_25168, v_25167);
    env = stack[-3];
    fn = elt(env, 6); // fkern
    v_25167 = (*qfn1(fn))(fn, v_25167);
    env = stack[-3];
    v_25168 = qcar(v_25167);
    goto v_25043;
v_25044:
    v_25167 = stack[0];
    goto v_25045;
v_25046:
    goto v_25042;
v_25043:
    goto v_25044;
v_25045:
    fn = elt(env, 7); // to
    stack[-2] = (*qfn2(fn))(fn, v_25168, v_25167);
    env = stack[-3];
    goto v_25037;
v_25038:
    goto v_25072;
v_25068:
    v_25167 = stack[-1];
    v_25167 = qcar(v_25167);
    v_25168 = qcdr(v_25167);
    goto v_25069;
v_25070:
    v_25167 = stack[0];
    goto v_25071;
v_25072:
    goto v_25068;
v_25069:
    goto v_25070;
v_25071:
    v_25167 = CC_expf(elt(env, 0), v_25168, v_25167);
    env = stack[-3];
    goto v_25039;
v_25040:
    goto v_25036;
v_25037:
    goto v_25038;
v_25039:
    v_25167 = cons(stack[-2], v_25167);
    return ncons(v_25167);
v_25022:
    goto v_25084;
v_25080:
    v_25167 = stack[-1];
    v_25167 = qcar(v_25167);
    v_25167 = qcar(v_25167);
    v_25168 = qcdr(v_25167);
    goto v_25081;
v_25082:
    v_25167 = stack[0];
    goto v_25083;
v_25084:
    goto v_25080;
v_25081:
    goto v_25082;
v_25083:
    v_25167 = times2(v_25168, v_25167);
    env = stack[-3];
    stack[-2] = v_25167;
    goto v_25101;
v_25097:
    v_25168 = stack[-2];
    goto v_25098;
v_25099:
    v_25167 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25100;
v_25101:
    goto v_25097;
v_25098:
    goto v_25099;
v_25100:
    v_25167 = (LispObject)greaterp2(v_25168, v_25167);
    v_25167 = v_25167 ? lisp_true : nil;
    env = stack[-3];
    if (v_25167 == nil) goto v_25094;
    v_25167 = stack[-1];
    v_25167 = qcar(v_25167);
    v_25167 = qcar(v_25167);
    v_25167 = qcar(v_25167);
    fn = elt(env, 8); // sfp
    v_25167 = (*qfn1(fn))(fn, v_25167);
    env = stack[-3];
    if (v_25167 == nil) goto v_25094;
    goto v_25115;
v_25111:
    goto v_25121;
v_25117:
    v_25167 = stack[-1];
    v_25167 = qcar(v_25167);
    v_25167 = qcar(v_25167);
    v_25168 = qcar(v_25167);
    goto v_25118;
v_25119:
    v_25167 = stack[-2];
    goto v_25120;
v_25121:
    goto v_25117;
v_25118:
    goto v_25119;
v_25120:
    fn = elt(env, 9); // exptf
    stack[-2] = (*qfn2(fn))(fn, v_25168, v_25167);
    env = stack[-3];
    goto v_25112;
v_25113:
    goto v_25132;
v_25128:
    v_25167 = stack[-1];
    v_25167 = qcar(v_25167);
    v_25168 = qcdr(v_25167);
    goto v_25129;
v_25130:
    v_25167 = stack[0];
    goto v_25131;
v_25132:
    goto v_25128;
v_25129:
    goto v_25130;
v_25131:
    v_25167 = CC_expf(elt(env, 0), v_25168, v_25167);
    env = stack[-3];
    goto v_25114;
v_25115:
    goto v_25111;
v_25112:
    goto v_25113;
v_25114:
    {
        LispObject v_25174 = stack[-2];
        fn = elt(env, 10); // multf
        return (*qfn2(fn))(fn, v_25174, v_25167);
    }
v_25094:
    goto v_25145;
v_25141:
    goto v_25151;
v_25147:
    v_25167 = stack[-1];
    v_25167 = qcar(v_25167);
    v_25167 = qcar(v_25167);
    v_25168 = qcar(v_25167);
    goto v_25148;
v_25149:
    v_25167 = stack[-2];
    goto v_25150;
v_25151:
    goto v_25147;
v_25148:
    goto v_25149;
v_25150:
    fn = elt(env, 7); // to
    stack[-2] = (*qfn2(fn))(fn, v_25168, v_25167);
    env = stack[-3];
    goto v_25142;
v_25143:
    goto v_25162;
v_25158:
    v_25167 = stack[-1];
    v_25167 = qcar(v_25167);
    v_25168 = qcdr(v_25167);
    goto v_25159;
v_25160:
    v_25167 = stack[0];
    goto v_25161;
v_25162:
    goto v_25158;
v_25159:
    goto v_25160;
v_25161:
    v_25167 = CC_expf(elt(env, 0), v_25168, v_25167);
    env = stack[-3];
    goto v_25144;
v_25145:
    goto v_25141;
v_25142:
    goto v_25143;
v_25144:
    v_25167 = cons(stack[-2], v_25167);
    return ncons(v_25167);
    v_25167 = nil;
    goto v_24954;
    v_25167 = nil;
v_24954:
    return onevalue(v_25167);
}



// Code for change!+int!+to!+sq

static LispObject CC_changeLintLtoLsq(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24962, v_24963;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24962 = v_24950;
// end of prologue
    goto v_24959;
v_24955:
    v_24963 = v_24962;
    goto v_24956;
v_24957:
    v_24962 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24958;
v_24959:
    goto v_24955;
v_24956:
    goto v_24957;
v_24958:
    return cons(v_24963, v_24962);
    return onevalue(v_24962);
}



// Code for freeof!-dfl

static LispObject CC_freeofKdfl(LispObject env,
                         LispObject v_24950, LispObject v_24951)
{
    env = qenv(env);
    LispObject v_24986, v_24987;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24951,v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24950,v_24951);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24951;
    stack[-1] = v_24950;
// end of prologue
v_24949:
    v_24986 = stack[-1];
    if (!consp(v_24986)) goto v_24955;
    else goto v_24956;
v_24955:
    v_24986 = lisp_true;
    goto v_24954;
v_24956:
    goto v_24970;
v_24966:
    v_24986 = stack[-1];
    v_24987 = qcar(v_24986);
    goto v_24967;
v_24968:
    v_24986 = stack[0];
    goto v_24969;
v_24970:
    goto v_24966;
v_24967:
    goto v_24968;
v_24969:
    fn = elt(env, 1); // freeof!-df
    v_24986 = (*qfn2(fn))(fn, v_24987, v_24986);
    env = stack[-2];
    if (v_24986 == nil) goto v_24963;
    else goto v_24964;
v_24963:
    v_24986 = nil;
    goto v_24962;
v_24964:
    goto v_24982;
v_24978:
    v_24986 = stack[-1];
    v_24987 = qcdr(v_24986);
    goto v_24979;
v_24980:
    v_24986 = stack[0];
    goto v_24981;
v_24982:
    goto v_24978;
v_24979:
    goto v_24980;
v_24981:
    stack[-1] = v_24987;
    stack[0] = v_24986;
    goto v_24949;
    v_24986 = nil;
v_24962:
    goto v_24954;
    v_24986 = nil;
v_24954:
    return onevalue(v_24986);
}



// Code for pasf_premf

static LispObject CC_pasf_premf(LispObject env,
                         LispObject v_24950, LispObject v_24951)
{
    env = qenv(env);
    LispObject v_24968, v_24969;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24951,v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24950,v_24951);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24951;
    v_24968 = v_24950;
// end of prologue
    goto v_24958;
v_24954:
    goto v_24964;
v_24960:
    v_24969 = v_24968;
    goto v_24961;
v_24962:
    v_24968 = stack[0];
    goto v_24963;
v_24964:
    goto v_24960;
v_24961:
    goto v_24962;
v_24963:
    fn = elt(env, 1); // remf
    v_24969 = (*qfn2(fn))(fn, v_24969, v_24968);
    env = stack[-1];
    goto v_24955;
v_24956:
    v_24968 = stack[0];
    goto v_24957;
v_24958:
    goto v_24954;
v_24955:
    goto v_24956;
v_24957:
    {
        fn = elt(env, 2); // pasf_premf1
        return (*qfn2(fn))(fn, v_24969, v_24968);
    }
}



// Code for pasf_coeflst

static LispObject CC_pasf_coeflst(LispObject env,
                         LispObject v_24950, LispObject v_24951)
{
    env = qenv(env);
    LispObject v_25033, v_25034, v_25035;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24951,v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24950,v_24951);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_24951;
    stack[-2] = v_24950;
// end of prologue
    stack[0] = nil;
    v_25033 = stack[-1];
    v_25033 = ncons(v_25033);
    env = stack[-4];
    fn = elt(env, 1); // setkorder
    v_25033 = (*qfn1(fn))(fn, v_25033);
    env = stack[-4];
    stack[-3] = v_25033;
    v_25033 = stack[-2];
    fn = elt(env, 2); // reorder
    v_25033 = (*qfn1(fn))(fn, v_25033);
    env = stack[-4];
    stack[-2] = v_25033;
v_24965:
    v_25033 = stack[-2];
    if (!consp(v_25033)) goto v_24976;
    else goto v_24977;
v_24976:
    v_25033 = lisp_true;
    goto v_24975;
v_24977:
    v_25033 = stack[-2];
    v_25033 = qcar(v_25033);
    v_25033 = (consp(v_25033) ? nil : lisp_true);
    goto v_24975;
    v_25033 = nil;
v_24975:
    if (v_25033 == nil) goto v_24972;
    else goto v_24973;
v_24972:
    goto v_24989;
v_24985:
    v_25033 = stack[-2];
    v_25033 = qcar(v_25033);
    v_25033 = qcar(v_25033);
    v_25034 = qcar(v_25033);
    goto v_24986;
v_24987:
    v_25033 = stack[-1];
    goto v_24988;
v_24989:
    goto v_24985;
v_24986:
    goto v_24987;
v_24988:
    v_25033 = (v_25034 == v_25033 ? lisp_true : nil);
    goto v_24971;
v_24973:
    v_25033 = nil;
    goto v_24971;
    v_25033 = nil;
v_24971:
    if (v_25033 == nil) goto v_24968;
    else goto v_24969;
v_24968:
    goto v_24964;
v_24969:
    goto v_25007;
v_25001:
    v_25033 = stack[-2];
    v_25033 = qcar(v_25033);
    v_25035 = qcdr(v_25033);
    goto v_25002;
v_25003:
    v_25033 = stack[-2];
    v_25033 = qcar(v_25033);
    v_25033 = qcar(v_25033);
    v_25034 = qcdr(v_25033);
    goto v_25004;
v_25005:
    v_25033 = stack[0];
    goto v_25006;
v_25007:
    goto v_25001;
v_25002:
    goto v_25003;
v_25004:
    goto v_25005;
v_25006:
    v_25033 = acons(v_25035, v_25034, v_25033);
    env = stack[-4];
    stack[0] = v_25033;
    v_25033 = stack[-2];
    v_25033 = qcdr(v_25033);
    stack[-2] = v_25033;
    goto v_24965;
v_24964:
    v_25033 = stack[-3];
    fn = elt(env, 1); // setkorder
    v_25033 = (*qfn1(fn))(fn, v_25033);
    env = stack[-4];
    goto v_25028;
v_25022:
    v_25033 = stack[-2];
    fn = elt(env, 3); // negf
    v_25035 = (*qfn1(fn))(fn, v_25033);
    env = stack[-4];
    goto v_25023;
v_25024:
    v_25034 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25025;
v_25026:
    v_25033 = stack[0];
    goto v_25027;
v_25028:
    goto v_25022;
v_25023:
    goto v_25024;
v_25025:
    goto v_25026;
v_25027:
    v_25033 = acons(v_25035, v_25034, v_25033);
        return Lnreverse(nil, v_25033);
    return onevalue(v_25033);
}



// Code for conditionml

static LispObject CC_conditionml(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24965;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24950;
// end of prologue
    v_24965 = elt(env, 1); // "<condition>"
    fn = elt(env, 3); // printout
    v_24965 = (*qfn1(fn))(fn, v_24965);
    env = stack[-1];
    v_24965 = lisp_true;
    fn = elt(env, 4); // indent!*
    v_24965 = (*qfn1(fn))(fn, v_24965);
    env = stack[-1];
    v_24965 = stack[0];
    v_24965 = qcar(v_24965);
    fn = elt(env, 5); // expression
    v_24965 = (*qfn1(fn))(fn, v_24965);
    env = stack[-1];
    v_24965 = nil;
    fn = elt(env, 4); // indent!*
    v_24965 = (*qfn1(fn))(fn, v_24965);
    env = stack[-1];
    v_24965 = elt(env, 2); // "</condition>"
    fn = elt(env, 3); // printout
    v_24965 = (*qfn1(fn))(fn, v_24965);
    v_24965 = nil;
    return onevalue(v_24965);
}



// Code for mkexpt

static LispObject CC_mkexpt(LispObject env,
                         LispObject v_24950, LispObject v_24951)
{
    env = qenv(env);
    LispObject v_24978, v_24979, v_24980, v_24981;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24980 = v_24951;
    v_24981 = v_24950;
// end of prologue
    goto v_24961;
v_24957:
    v_24979 = v_24980;
    goto v_24958;
v_24959:
    v_24978 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24960;
v_24961:
    goto v_24957;
v_24958:
    goto v_24959;
v_24960:
    if (v_24979 == v_24978) goto v_24955;
    else goto v_24956;
v_24955:
    v_24978 = v_24981;
    goto v_24954;
v_24956:
    goto v_24974;
v_24968:
    v_24978 = elt(env, 1); // expt
    goto v_24969;
v_24970:
    v_24979 = v_24981;
    goto v_24971;
v_24972:
    goto v_24973;
v_24974:
    goto v_24968;
v_24969:
    goto v_24970;
v_24971:
    goto v_24972;
v_24973:
    return list3(v_24978, v_24979, v_24980);
    v_24978 = nil;
v_24954:
    return onevalue(v_24978);
}



// Code for rnfix!*

static LispObject CC_rnfixH(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24964, v_24965;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24964 = v_24950;
// end of prologue
    goto v_24957;
v_24953:
    v_24965 = v_24964;
    v_24965 = qcdr(v_24965);
    v_24965 = qcar(v_24965);
    goto v_24954;
v_24955:
    v_24964 = qcdr(v_24964);
    v_24964 = qcdr(v_24964);
    goto v_24956;
v_24957:
    goto v_24953;
v_24954:
    goto v_24955;
v_24956:
    return quot2(v_24965, v_24964);
}



// Code for evalmember

static LispObject CC_evalmember(LispObject env,
                         LispObject v_24950, LispObject v_24951)
{
    env = qenv(env);
    LispObject v_24962, v_24963;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24951,v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24950,v_24951);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_24962 = v_24951;
    v_24963 = v_24950;
// end of prologue
    goto v_24957;
v_24953:
    stack[0] = v_24963;
    goto v_24954;
v_24955:
    fn = elt(env, 1); // getrlist
    v_24962 = (*qfn1(fn))(fn, v_24962);
    goto v_24956;
v_24957:
    goto v_24953;
v_24954:
    goto v_24955;
v_24956:
    v_24962 = Lmember(nil, stack[0], v_24962);
    return onevalue(v_24962);
}



// Code for gpargp

static LispObject CC_gpargp(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24964;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24950;
// end of prologue
    v_24964 = stack[0];
    v_24964 = Lstringp(nil, v_24964);
    env = stack[-1];
    if (v_24964 == nil) goto v_24954;
    else goto v_24953;
v_24954:
    v_24964 = stack[0];
    fn = elt(env, 1); // gpexpp
    v_24964 = (*qfn1(fn))(fn, v_24964);
    env = stack[-1];
    if (v_24964 == nil) goto v_24959;
    else goto v_24958;
v_24959:
    v_24964 = stack[0];
    {
        fn = elt(env, 2); // gplogexpp
        return (*qfn1(fn))(fn, v_24964);
    }
v_24958:
v_24953:
    return onevalue(v_24964);
}



// Code for indexvp

static LispObject CC_indexvp(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24963, v_24964;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24963 = v_24950;
// end of prologue
    v_24964 = v_24963;
    if (!consp(v_24964)) goto v_24955;
    v_24963 = qcar(v_24963);
    if (!symbolp(v_24963)) v_24963 = nil;
    else { v_24963 = qfastgets(v_24963);
           if (v_24963 != nil) { v_24963 = elt(v_24963, 16); // indexvar
#ifdef RECORD_GET
             if (v_24963 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v_24963 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v_24963 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v_24963 == SPID_NOPROP) v_24963 = nil; else v_24963 = lisp_true; }}
#endif
    goto v_24953;
v_24955:
    v_24963 = nil;
    goto v_24953;
    v_24963 = nil;
v_24953:
    return onevalue(v_24963);
}



// Code for extract_vars

static LispObject CC_extract_vars(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24990, v_24991;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24950;
// end of prologue
    stack[-1] = nil;
v_24955:
    v_24990 = stack[0];
    if (v_24990 == nil) goto v_24958;
    else goto v_24959;
v_24958:
    v_24990 = stack[-1];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_24990);
    }
v_24959:
    goto v_24970;
v_24966:
    v_24990 = stack[0];
    v_24990 = qcar(v_24990);
    fn = elt(env, 3); // raiseind!:
    v_24991 = (*qfn1(fn))(fn, v_24990);
    env = stack[-2];
    goto v_24967;
v_24968:
    v_24990 = elt(env, 1); // variable
    goto v_24969;
v_24970:
    goto v_24966;
v_24967:
    goto v_24968;
v_24969:
    v_24990 = Lflagp(nil, v_24991, v_24990);
    env = stack[-2];
    if (v_24990 == nil) goto v_24964;
    goto v_24980;
v_24976:
    v_24990 = stack[0];
    v_24991 = qcar(v_24990);
    goto v_24977;
v_24978:
    v_24990 = stack[-1];
    goto v_24979;
v_24980:
    goto v_24976;
v_24977:
    goto v_24978;
v_24979:
    v_24990 = cons(v_24991, v_24990);
    env = stack[-2];
    stack[-1] = v_24990;
    v_24990 = stack[0];
    v_24990 = qcdr(v_24990);
    stack[0] = v_24990;
    goto v_24955;
v_24964:
    v_24990 = stack[0];
    v_24990 = qcdr(v_24990);
    stack[0] = v_24990;
    goto v_24955;
    v_24990 = nil;
    return onevalue(v_24990);
}



// Code for cl_gand!-col

static LispObject CC_cl_gandKcol(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25150, v_25151, v_25152;
    LispObject fn;
    LispObject v_24953, v_24952, v_24951, v_24950;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_gand-col");
    va_start(aa, nargs);
    v_24950 = va_arg(aa, LispObject);
    v_24951 = va_arg(aa, LispObject);
    v_24952 = va_arg(aa, LispObject);
    v_24953 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_24953,v_24952,v_24951,v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_24950,v_24951,v_24952,v_24953);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-4] = v_24953;
    stack[-5] = v_24952;
    stack[-6] = v_24951;
    stack[-7] = v_24950;
// end of prologue
    stack[-8] = nil;
    goto v_24966;
v_24962:
    v_25152 = elt(env, 1); // true
    goto v_24963;
v_24964:
    goto v_24972;
v_24968:
    v_25151 = stack[-5];
    goto v_24969;
v_24970:
    v_25150 = elt(env, 2); // and
    goto v_24971;
v_24972:
    goto v_24968;
v_24969:
    goto v_24970;
v_24971:
    v_25150 = (v_25151 == v_25150 ? lisp_true : nil);
    goto v_24965;
v_24966:
    goto v_24962;
v_24963:
    goto v_24964;
v_24965:
    fn = elt(env, 4); // cl_cflip
    v_25150 = (*qfn2(fn))(fn, v_25152, v_25150);
    env = stack[-9];
    stack[-3] = v_25150;
    v_25150 = stack[-3];
    fn = elt(env, 5); // cl_flip
    v_25150 = (*qfn1(fn))(fn, v_25150);
    env = stack[-9];
    stack[-2] = v_25150;
v_24980:
    v_25150 = stack[-7];
    if (v_25150 == nil) goto v_24983;
    else goto v_24984;
v_24983:
    goto v_24979;
v_24984:
    goto v_24996;
v_24988:
    v_25150 = stack[-7];
    stack[-1] = qcar(v_25150);
    goto v_24989;
v_24990:
    stack[0] = stack[-4];
    goto v_24991;
v_24992:
    v_25150 = stack[-6];
    v_25151 = sub1(v_25150);
    env = stack[-9];
    goto v_24993;
v_24994:
    v_25150 = stack[-5];
    goto v_24995;
v_24996:
    goto v_24988;
v_24989:
    goto v_24990;
v_24991:
    goto v_24992;
v_24993:
    goto v_24994;
v_24995:
    fn = elt(env, 6); // cl_simpl1
    v_25150 = (*qfnn(fn))(fn, 4, stack[-1], stack[0], v_25151, v_25150);
    env = stack[-9];
    v_25152 = v_25150;
    v_25150 = stack[-7];
    v_25150 = qcdr(v_25150);
    stack[-7] = v_25150;
    goto v_25013;
v_25009:
    v_25151 = v_25152;
    goto v_25010;
v_25011:
    v_25150 = stack[-2];
    goto v_25012;
v_25013:
    goto v_25009;
v_25010:
    goto v_25011;
v_25012:
    if (v_25151 == v_25150) goto v_25007;
    else goto v_25008;
v_25007:
    v_25150 = stack[-2];
    v_25150 = ncons(v_25150);
    env = stack[-9];
    stack[-8] = v_25150;
    v_25150 = nil;
    stack[-7] = v_25150;
    goto v_25006;
v_25008:
    goto v_25025;
v_25021:
    v_25151 = v_25152;
    goto v_25022;
v_25023:
    v_25150 = stack[-3];
    goto v_25024;
v_25025:
    goto v_25021;
v_25022:
    goto v_25023;
v_25024:
    if (equal(v_25151, v_25150)) goto v_25020;
    goto v_25036;
v_25032:
    v_25150 = v_25152;
    if (!consp(v_25150)) goto v_25039;
    else goto v_25040;
v_25039:
    v_25150 = v_25152;
    v_25151 = v_25150;
    goto v_25038;
v_25040:
    v_25150 = v_25152;
    v_25150 = qcar(v_25150);
    v_25151 = v_25150;
    goto v_25038;
    v_25151 = nil;
v_25038:
    goto v_25033;
v_25034:
    v_25150 = stack[-5];
    goto v_25035;
v_25036:
    goto v_25032;
v_25033:
    goto v_25034;
v_25035:
    if (v_25151 == v_25150) goto v_25030;
    else goto v_25031;
v_25030:
    v_25150 = qvalue(elt(env, 3)); // !*rlsichk
    if (v_25150 == nil) goto v_25051;
    v_25150 = v_25152;
    v_25150 = qcdr(v_25150);
    stack[0] = v_25150;
v_25056:
    v_25150 = stack[0];
    if (v_25150 == nil) goto v_25061;
    else goto v_25062;
v_25061:
    goto v_25055;
v_25062:
    v_25150 = stack[0];
    v_25150 = qcar(v_25150);
    v_25152 = v_25150;
    goto v_25076;
v_25072:
    v_25151 = v_25152;
    goto v_25073;
v_25074:
    v_25150 = stack[-8];
    goto v_25075;
v_25076:
    goto v_25072;
v_25073:
    goto v_25074;
v_25075:
    v_25150 = Lmember(nil, v_25151, v_25150);
    if (v_25150 == nil) goto v_25070;
    else goto v_25071;
v_25070:
    goto v_25085;
v_25081:
    v_25151 = v_25152;
    goto v_25082;
v_25083:
    v_25150 = stack[-8];
    goto v_25084;
v_25085:
    goto v_25081;
v_25082:
    goto v_25083;
v_25084:
    v_25150 = cons(v_25151, v_25150);
    env = stack[-9];
    stack[-8] = v_25150;
    goto v_25069;
v_25071:
v_25069:
    v_25150 = stack[0];
    v_25150 = qcdr(v_25150);
    stack[0] = v_25150;
    goto v_25056;
v_25055:
    goto v_25049;
v_25051:
    v_25150 = v_25152;
    v_25150 = qcdr(v_25150);
    stack[0] = v_25150;
v_25095:
    v_25150 = stack[0];
    if (v_25150 == nil) goto v_25100;
    else goto v_25101;
v_25100:
    goto v_25094;
v_25101:
    v_25150 = stack[0];
    v_25150 = qcar(v_25150);
    goto v_25112;
v_25108:
    v_25151 = v_25150;
    goto v_25109;
v_25110:
    v_25150 = stack[-8];
    goto v_25111;
v_25112:
    goto v_25108;
v_25109:
    goto v_25110;
v_25111:
    v_25150 = cons(v_25151, v_25150);
    env = stack[-9];
    stack[-8] = v_25150;
    v_25150 = stack[0];
    v_25150 = qcdr(v_25150);
    stack[0] = v_25150;
    goto v_25095;
v_25094:
    goto v_25049;
v_25049:
    goto v_25029;
v_25031:
    v_25150 = qvalue(elt(env, 3)); // !*rlsichk
    if (v_25150 == nil) goto v_25117;
    goto v_25126;
v_25122:
    v_25151 = v_25152;
    goto v_25123;
v_25124:
    v_25150 = stack[-8];
    goto v_25125;
v_25126:
    goto v_25122;
v_25123:
    goto v_25124;
v_25125:
    v_25150 = Lmember(nil, v_25151, v_25150);
    if (v_25150 == nil) goto v_25117;
    goto v_25118;
v_25117:
    goto v_25135;
v_25131:
    v_25151 = v_25152;
    goto v_25132;
v_25133:
    v_25150 = stack[-8];
    goto v_25134;
v_25135:
    goto v_25131;
v_25132:
    goto v_25133;
v_25134:
    v_25150 = cons(v_25151, v_25150);
    env = stack[-9];
    stack[-8] = v_25150;
    goto v_25029;
v_25118:
v_25029:
    goto v_25006;
v_25020:
v_25006:
    goto v_24980;
v_24979:
    v_25150 = stack[-8];
    if (v_25150 == nil) goto v_25142;
    v_25150 = stack[-8];
        return Lnreverse(nil, v_25150);
v_25142:
    v_25150 = stack[-3];
    return ncons(v_25150);
    v_25150 = nil;
    return onevalue(v_25150);
}



// Code for numir

static LispObject CC_numir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25163, v_25164, v_25165;
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
    goto v_24963;
v_24959:
    v_25164 = qvalue(elt(env, 1)); // atts
    goto v_24960;
v_24961:
    v_25163 = elt(env, 2); // name
    goto v_24962;
v_24963:
    goto v_24959;
v_24960:
    goto v_24961;
v_24962:
    fn = elt(env, 11); // find
    v_25163 = (*qfn2(fn))(fn, v_25164, v_25163);
    env = stack[-7];
    v_25163 = Lintern(nil, v_25163);
    env = stack[-7];
    stack[-1] = v_25163;
    fn = elt(env, 12); // lex
    v_25163 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    fn = elt(env, 13); // omobj
    v_25163 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    stack[0] = v_25163;
    fn = elt(env, 12); // lex
    v_25163 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    fn = elt(env, 13); // omobj
    v_25163 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    goto v_24978;
v_24974:
    v_25165 = stack[-1];
    goto v_24975;
v_24976:
    v_25164 = elt(env, 3); // complex_cartesian
    goto v_24977;
v_24978:
    goto v_24974;
v_24975:
    goto v_24976;
v_24977:
    if (v_25165 == v_25164) goto v_24972;
    else goto v_24973;
v_24972:
    v_25164 = stack[0];
    if (symbolp(v_25164)) goto v_24983;
    v_25164 = v_25163;
    if (symbolp(v_25164)) goto v_24983;
    goto v_24984;
v_24983:
    goto v_24996;
v_24990:
    stack[-4] = elt(env, 4); // plus
    goto v_24991;
v_24992:
    stack[-3] = nil;
    goto v_24993;
v_24994:
    goto v_25006;
v_25000:
    stack[-2] = stack[0];
    goto v_25001;
v_25002:
    goto v_25015;
v_25009:
    stack[-1] = elt(env, 5); // times
    goto v_25010;
v_25011:
    stack[0] = nil;
    goto v_25012;
v_25013:
    goto v_25025;
v_25019:
    v_25165 = v_25163;
    goto v_25020;
v_25021:
    v_25164 = elt(env, 6); // !&imaginaryi!;
    goto v_25022;
v_25023:
    v_25163 = nil;
    goto v_25024;
v_25025:
    goto v_25019;
v_25020:
    goto v_25021;
v_25022:
    goto v_25023;
v_25024:
    v_25163 = list2star(v_25165, v_25164, v_25163);
    env = stack[-7];
    goto v_25014;
v_25015:
    goto v_25009;
v_25010:
    goto v_25011;
v_25012:
    goto v_25013;
v_25014:
    v_25164 = list2star(stack[-1], stack[0], v_25163);
    env = stack[-7];
    goto v_25003;
v_25004:
    v_25163 = nil;
    goto v_25005;
v_25006:
    goto v_25000;
v_25001:
    goto v_25002;
v_25003:
    goto v_25004;
v_25005:
    v_25163 = list2star(stack[-2], v_25164, v_25163);
    goto v_24995;
v_24996:
    goto v_24990;
v_24991:
    goto v_24992;
v_24993:
    goto v_24994;
v_24995:
    {
        LispObject v_25173 = stack[-4];
        LispObject v_25174 = stack[-3];
        return list2star(v_25173, v_25174, v_25163);
    }
v_24984:
    goto v_24971;
v_24973:
v_24971:
    goto v_25038;
v_25034:
    v_25165 = stack[-1];
    goto v_25035;
v_25036:
    v_25164 = elt(env, 7); // complex_polar
    goto v_25037;
v_25038:
    goto v_25034;
v_25035:
    goto v_25036;
v_25037:
    if (v_25165 == v_25164) goto v_25032;
    else goto v_25033;
v_25032:
    v_25164 = stack[0];
    if (symbolp(v_25164)) goto v_25043;
    v_25164 = v_25163;
    if (symbolp(v_25164)) goto v_25043;
    goto v_25044;
v_25043:
    goto v_25056;
v_25050:
    stack[-6] = elt(env, 5); // times
    goto v_25051;
v_25052:
    stack[-5] = nil;
    goto v_25053;
v_25054:
    goto v_25066;
v_25060:
    stack[-4] = stack[0];
    goto v_25061;
v_25062:
    goto v_25075;
v_25069:
    stack[-3] = elt(env, 8); // exp
    goto v_25070;
v_25071:
    stack[-2] = nil;
    goto v_25072;
v_25073:
    goto v_25086;
v_25080:
    stack[-1] = elt(env, 5); // times
    goto v_25081;
v_25082:
    stack[0] = nil;
    goto v_25083;
v_25084:
    goto v_25096;
v_25090:
    v_25165 = v_25163;
    goto v_25091;
v_25092:
    v_25164 = elt(env, 6); // !&imaginaryi!;
    goto v_25093;
v_25094:
    v_25163 = nil;
    goto v_25095;
v_25096:
    goto v_25090;
v_25091:
    goto v_25092;
v_25093:
    goto v_25094;
v_25095:
    v_25163 = list2star(v_25165, v_25164, v_25163);
    env = stack[-7];
    goto v_25085;
v_25086:
    goto v_25080;
v_25081:
    goto v_25082;
v_25083:
    goto v_25084;
v_25085:
    v_25163 = list2star(stack[-1], stack[0], v_25163);
    env = stack[-7];
    v_25163 = ncons(v_25163);
    env = stack[-7];
    goto v_25074;
v_25075:
    goto v_25069;
v_25070:
    goto v_25071;
v_25072:
    goto v_25073;
v_25074:
    v_25164 = list2star(stack[-3], stack[-2], v_25163);
    env = stack[-7];
    goto v_25063;
v_25064:
    v_25163 = nil;
    goto v_25065;
v_25066:
    goto v_25060;
v_25061:
    goto v_25062;
v_25063:
    goto v_25064;
v_25065:
    v_25163 = list2star(stack[-4], v_25164, v_25163);
    goto v_25055;
v_25056:
    goto v_25050;
v_25051:
    goto v_25052;
v_25053:
    goto v_25054;
v_25055:
    {
        LispObject v_25175 = stack[-6];
        LispObject v_25176 = stack[-5];
        return list2star(v_25175, v_25176, v_25163);
    }
v_25044:
    goto v_25031;
v_25033:
v_25031:
    goto v_25109;
v_25105:
    v_25165 = stack[-1];
    goto v_25106;
v_25107:
    v_25164 = elt(env, 9); // rational
    goto v_25108;
v_25109:
    goto v_25105;
v_25106:
    goto v_25107;
v_25108:
    if (v_25165 == v_25164) goto v_25103;
    else goto v_25104;
v_25103:
    v_25164 = stack[0];
    if (symbolp(v_25164)) goto v_25114;
    v_25164 = v_25163;
    if (symbolp(v_25164)) goto v_25114;
    goto v_25115;
v_25114:
    goto v_25127;
v_25121:
    stack[-2] = elt(env, 10); // divide
    goto v_25122;
v_25123:
    stack[-1] = nil;
    goto v_25124;
v_25125:
    goto v_25137;
v_25131:
    v_25165 = stack[0];
    goto v_25132;
v_25133:
    v_25164 = v_25163;
    goto v_25134;
v_25135:
    v_25163 = nil;
    goto v_25136;
v_25137:
    goto v_25131;
v_25132:
    goto v_25133;
v_25134:
    goto v_25135;
v_25136:
    v_25163 = list2star(v_25165, v_25164, v_25163);
    goto v_25126;
v_25127:
    goto v_25121;
v_25122:
    goto v_25123;
v_25124:
    goto v_25125;
v_25126:
    {
        LispObject v_25177 = stack[-2];
        LispObject v_25178 = stack[-1];
        return list2star(v_25177, v_25178, v_25163);
    }
v_25115:
    goto v_25102;
v_25104:
v_25102:
    goto v_25149;
v_25143:
    stack[-2] = stack[-1];
    goto v_25144;
v_25145:
    stack[-1] = nil;
    goto v_25146;
v_25147:
    goto v_25159;
v_25153:
    v_25165 = stack[0];
    goto v_25154;
v_25155:
    v_25164 = v_25163;
    goto v_25156;
v_25157:
    v_25163 = nil;
    goto v_25158;
v_25159:
    goto v_25153;
v_25154:
    goto v_25155;
v_25156:
    goto v_25157;
v_25158:
    v_25163 = list2star(v_25165, v_25164, v_25163);
    goto v_25148;
v_25149:
    goto v_25143;
v_25144:
    goto v_25145;
v_25146:
    goto v_25147;
v_25148:
    {
        LispObject v_25179 = stack[-2];
        LispObject v_25180 = stack[-1];
        return list2star(v_25179, v_25180, v_25163);
    }
    return onevalue(v_25163);
}



// Code for ps!:arg!-values

static LispObject CC_psTargKvalues(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_25101, v_25102, v_25103;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_25102 = v_24950;
// end of prologue
    goto v_24957;
v_24953:
    v_25101 = v_25102;
    stack[-4] = qcar(v_25101);
    goto v_24954;
v_24955:
    v_25101 = v_25102;
    v_25101 = qcdr(v_25101);
    stack[-3] = v_25101;
    v_25101 = stack[-3];
    if (v_25101 == nil) goto v_24970;
    else goto v_24971;
v_24970:
    v_25101 = nil;
    goto v_24964;
v_24971:
    v_25101 = stack[-3];
    v_25101 = qcar(v_25101);
    v_25103 = v_25101;
    v_25101 = v_25103;
    if (!consp(v_25101)) goto v_24984;
    else goto v_24985;
v_24984:
    v_25101 = lisp_true;
    goto v_24983;
v_24985:
    goto v_24998;
v_24994:
    v_25101 = v_25103;
    v_25102 = qcar(v_25101);
    goto v_24995;
v_24996:
    v_25101 = elt(env, 1); // !:ps!:
    goto v_24997;
v_24998:
    goto v_24994;
v_24995:
    goto v_24996;
v_24997:
    if (v_25102 == v_25101) goto v_24993;
    v_25101 = v_25103;
    v_25101 = qcar(v_25101);
    if (!symbolp(v_25101)) v_25101 = nil;
    else { v_25101 = qfastgets(v_25101);
           if (v_25101 != nil) { v_25101 = elt(v_25101, 8); // dname
#ifdef RECORD_GET
             if (v_25101 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_25101 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_25101 == SPID_NOPROP) v_25101 = nil; }}
#endif
    goto v_24991;
v_24993:
    v_25101 = nil;
    goto v_24991;
    v_25101 = nil;
v_24991:
    goto v_24983;
    v_25101 = nil;
v_24983:
    if (v_25101 == nil) goto v_24981;
    v_25101 = v_25103;
    goto v_24979;
v_24981:
    v_25101 = v_25103;
    v_25101 = Lconsp(nil, v_25101);
    env = stack[-5];
    if (v_25101 == nil) goto v_25010;
    goto v_25019;
v_25015:
    v_25101 = v_25103;
    v_25102 = qcar(v_25101);
    goto v_25016;
v_25017:
    v_25101 = elt(env, 1); // !:ps!:
    goto v_25018;
v_25019:
    goto v_25015;
v_25016:
    goto v_25017;
v_25018:
    if (v_25102 == v_25101) goto v_25014;
    else goto v_25010;
v_25014:
    v_25101 = v_25103;
    fn = elt(env, 2); // ps!:value
    v_25101 = (*qfn1(fn))(fn, v_25101);
    env = stack[-5];
    goto v_24979;
v_25010:
    v_25101 = v_25103;
    v_25101 = CC_psTargKvalues(elt(env, 0), v_25101);
    env = stack[-5];
    goto v_24979;
    v_25101 = nil;
v_24979:
    v_25101 = ncons(v_25101);
    env = stack[-5];
    stack[-1] = v_25101;
    stack[-2] = v_25101;
v_24965:
    v_25101 = stack[-3];
    v_25101 = qcdr(v_25101);
    stack[-3] = v_25101;
    v_25101 = stack[-3];
    if (v_25101 == nil) goto v_25033;
    else goto v_25034;
v_25033:
    v_25101 = stack[-2];
    goto v_24964;
v_25034:
    goto v_25042;
v_25038:
    stack[0] = stack[-1];
    goto v_25039;
v_25040:
    v_25101 = stack[-3];
    v_25101 = qcar(v_25101);
    v_25103 = v_25101;
    v_25101 = v_25103;
    if (!consp(v_25101)) goto v_25054;
    else goto v_25055;
v_25054:
    v_25101 = lisp_true;
    goto v_25053;
v_25055:
    goto v_25068;
v_25064:
    v_25101 = v_25103;
    v_25102 = qcar(v_25101);
    goto v_25065;
v_25066:
    v_25101 = elt(env, 1); // !:ps!:
    goto v_25067;
v_25068:
    goto v_25064;
v_25065:
    goto v_25066;
v_25067:
    if (v_25102 == v_25101) goto v_25063;
    v_25101 = v_25103;
    v_25101 = qcar(v_25101);
    if (!symbolp(v_25101)) v_25101 = nil;
    else { v_25101 = qfastgets(v_25101);
           if (v_25101 != nil) { v_25101 = elt(v_25101, 8); // dname
#ifdef RECORD_GET
             if (v_25101 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_25101 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_25101 == SPID_NOPROP) v_25101 = nil; }}
#endif
    goto v_25061;
v_25063:
    v_25101 = nil;
    goto v_25061;
    v_25101 = nil;
v_25061:
    goto v_25053;
    v_25101 = nil;
v_25053:
    if (v_25101 == nil) goto v_25051;
    v_25101 = v_25103;
    goto v_25049;
v_25051:
    v_25101 = v_25103;
    v_25101 = Lconsp(nil, v_25101);
    env = stack[-5];
    if (v_25101 == nil) goto v_25080;
    goto v_25089;
v_25085:
    v_25101 = v_25103;
    v_25102 = qcar(v_25101);
    goto v_25086;
v_25087:
    v_25101 = elt(env, 1); // !:ps!:
    goto v_25088;
v_25089:
    goto v_25085;
v_25086:
    goto v_25087;
v_25088:
    if (v_25102 == v_25101) goto v_25084;
    else goto v_25080;
v_25084:
    v_25101 = v_25103;
    fn = elt(env, 2); // ps!:value
    v_25101 = (*qfn1(fn))(fn, v_25101);
    env = stack[-5];
    goto v_25049;
v_25080:
    v_25101 = v_25103;
    v_25101 = CC_psTargKvalues(elt(env, 0), v_25101);
    env = stack[-5];
    goto v_25049;
    v_25101 = nil;
v_25049:
    v_25101 = ncons(v_25101);
    env = stack[-5];
    goto v_25041;
v_25042:
    goto v_25038;
v_25039:
    goto v_25040;
v_25041:
    v_25101 = Lrplacd(nil, stack[0], v_25101);
    env = stack[-5];
    v_25101 = stack[-1];
    v_25101 = qcdr(v_25101);
    stack[-1] = v_25101;
    goto v_24965;
v_24964:
    goto v_24956;
v_24957:
    goto v_24953;
v_24954:
    goto v_24955;
v_24956:
    {
        LispObject v_25109 = stack[-4];
        return cons(v_25109, v_25101);
    }
}



// Code for remdiff

static LispObject CC_remdiff(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_25054, v_25055;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_24950;
// end of prologue
    v_25054 = stack[-1];
    if (symbolp(v_25054)) goto v_24954;
    v_25054 = stack[-1];
    fn = elt(env, 4); // constp
    v_25054 = (*qfn1(fn))(fn, v_25054);
    env = stack[-5];
    if (v_25054 == nil) goto v_24958;
    else goto v_24954;
v_24958:
    goto v_24955;
v_24954:
    v_25054 = stack[-1];
    goto v_24953;
v_24955:
    goto v_24972;
v_24968:
    v_25054 = stack[-1];
    v_25055 = qcar(v_25054);
    goto v_24969;
v_24970:
    v_25054 = elt(env, 1); // difference
    goto v_24971;
v_24972:
    goto v_24968;
v_24969:
    goto v_24970;
v_24971:
    if (v_25055 == v_25054) goto v_24966;
    else goto v_24967;
v_24966:
    goto v_24983;
v_24977:
    stack[-3] = elt(env, 2); // plus
    goto v_24978;
v_24979:
    v_25054 = stack[-1];
    v_25054 = qcdr(v_25054);
    v_25054 = qcar(v_25054);
    stack[-2] = CC_remdiff(elt(env, 0), v_25054);
    env = stack[-5];
    goto v_24980;
v_24981:
    goto v_24994;
v_24990:
    stack[0] = elt(env, 3); // minus
    goto v_24991;
v_24992:
    v_25054 = stack[-1];
    v_25054 = qcdr(v_25054);
    v_25054 = qcdr(v_25054);
    v_25054 = qcar(v_25054);
    v_25054 = CC_remdiff(elt(env, 0), v_25054);
    env = stack[-5];
    goto v_24993;
v_24994:
    goto v_24990;
v_24991:
    goto v_24992;
v_24993:
    v_25054 = list2(stack[0], v_25054);
    env = stack[-5];
    goto v_24982;
v_24983:
    goto v_24977;
v_24978:
    goto v_24979;
v_24980:
    goto v_24981;
v_24982:
    v_25054 = list3(stack[-3], stack[-2], v_25054);
    goto v_24965;
v_24967:
    goto v_25008;
v_25004:
    v_25054 = stack[-1];
    stack[-4] = qcar(v_25054);
    goto v_25005;
v_25006:
    v_25054 = stack[-1];
    v_25054 = qcdr(v_25054);
    stack[-3] = v_25054;
    v_25054 = stack[-3];
    if (v_25054 == nil) goto v_25021;
    else goto v_25022;
v_25021:
    v_25054 = nil;
    goto v_25015;
v_25022:
    v_25054 = stack[-3];
    v_25054 = qcar(v_25054);
    v_25054 = CC_remdiff(elt(env, 0), v_25054);
    env = stack[-5];
    v_25054 = ncons(v_25054);
    env = stack[-5];
    stack[-1] = v_25054;
    stack[-2] = v_25054;
v_25016:
    v_25054 = stack[-3];
    v_25054 = qcdr(v_25054);
    stack[-3] = v_25054;
    v_25054 = stack[-3];
    if (v_25054 == nil) goto v_25035;
    else goto v_25036;
v_25035:
    v_25054 = stack[-2];
    goto v_25015;
v_25036:
    goto v_25044;
v_25040:
    stack[0] = stack[-1];
    goto v_25041;
v_25042:
    v_25054 = stack[-3];
    v_25054 = qcar(v_25054);
    v_25054 = CC_remdiff(elt(env, 0), v_25054);
    env = stack[-5];
    v_25054 = ncons(v_25054);
    env = stack[-5];
    goto v_25043;
v_25044:
    goto v_25040;
v_25041:
    goto v_25042;
v_25043:
    v_25054 = Lrplacd(nil, stack[0], v_25054);
    env = stack[-5];
    v_25054 = stack[-1];
    v_25054 = qcdr(v_25054);
    stack[-1] = v_25054;
    goto v_25016;
v_25015:
    goto v_25007;
v_25008:
    goto v_25004;
v_25005:
    goto v_25006;
v_25007:
    {
        LispObject v_25061 = stack[-4];
        return cons(v_25061, v_25054);
    }
    v_25054 = nil;
v_24965:
    goto v_24953;
    v_25054 = nil;
v_24953:
    return onevalue(v_25054);
}



// Code for e!*

static LispObject CC_eH(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24953;
    LispObject fn;
    argcheck(nargs, 0, "e*");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_24953 = qvalue(elt(env, 1)); // !:bprec!:
    {
        fn = elt(env, 2); // !:e
        return (*qfn1(fn))(fn, v_24953);
    }
}



// Code for nspaces

static LispObject CC_nspaces(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24990, v_24991, v_24992;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_24950;
// end of prologue
    stack[-2] = nil;
    v_24990 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_24990;
v_24958:
    goto v_24970;
v_24966:
    v_24991 = stack[-1];
    goto v_24967;
v_24968:
    v_24990 = stack[0];
    goto v_24969;
v_24970:
    goto v_24966;
v_24967:
    goto v_24968;
v_24969:
    v_24990 = difference2(v_24991, v_24990);
    env = stack[-3];
    v_24990 = Lminusp(nil, v_24990);
    env = stack[-3];
    if (v_24990 == nil) goto v_24963;
    goto v_24957;
v_24963:
    goto v_24981;
v_24975:
    v_24992 = elt(env, 1); // !!
    goto v_24976;
v_24977:
    v_24991 = elt(env, 2); // ! 
    goto v_24978;
v_24979:
    v_24990 = stack[-2];
    goto v_24980;
v_24981:
    goto v_24975;
v_24976:
    goto v_24977;
v_24978:
    goto v_24979;
v_24980:
    v_24990 = list2star(v_24992, v_24991, v_24990);
    env = stack[-3];
    stack[-2] = v_24990;
    v_24990 = stack[0];
    v_24990 = add1(v_24990);
    env = stack[-3];
    stack[0] = v_24990;
    goto v_24958;
v_24957:
    v_24990 = stack[-2];
    v_24990 = Lcompress(nil, v_24990);
        return Lintern(nil, v_24990);
    return onevalue(v_24990);
}



// Code for mk_simpl_map_

static LispObject CC_mk_simpl_map_(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24960, v_24961;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24960 = v_24950;
// end of prologue
    goto v_24957;
v_24953:
    v_24961 = v_24960;
    goto v_24954;
v_24955:
    v_24960 = nil;
    goto v_24956;
v_24957:
    goto v_24953;
v_24954:
    goto v_24955;
v_24956:
    {
        fn = elt(env, 1); // mk_simpl_map_1
        return (*qfn2(fn))(fn, v_24961, v_24960);
    }
}



// Code for mk_dummy_ids

static LispObject CC_mk_dummy_ids(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24991, v_24992;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_24991 = v_24950;
// end of prologue
    goto v_24961;
v_24957:
    v_24992 = v_24991;
    v_24992 = qcar(v_24992);
    goto v_24958;
v_24959:
    v_24991 = qcdr(v_24991);
    v_24991 = qcar(v_24991);
    goto v_24960;
v_24961:
    goto v_24957;
v_24958:
    goto v_24959;
v_24960:
    fn = elt(env, 4); // intersection
    v_24991 = (*qfn2(fn))(fn, v_24992, v_24991);
    env = stack[-1];
    fn = elt(env, 5); // clean_numid
    v_24991 = (*qfn1(fn))(fn, v_24991);
    env = stack[-1];
    stack[0] = v_24991;
    goto v_24972;
v_24968:
    v_24992 = stack[0];
    goto v_24969;
v_24970:
    v_24991 = elt(env, 1); // dummy
    goto v_24971;
v_24972:
    goto v_24968;
v_24969:
    goto v_24970;
v_24971:
    v_24991 = Lflag(nil, v_24992, v_24991);
    env = stack[-1];
    goto v_24980;
v_24976:
    v_24992 = stack[0];
    goto v_24977;
v_24978:
    v_24991 = elt(env, 2); // reserved
    goto v_24979;
v_24980:
    goto v_24976;
v_24977:
    goto v_24978;
v_24979:
    v_24991 = Lflag(nil, v_24992, v_24991);
    env = stack[-1];
    goto v_24988;
v_24984:
    v_24992 = stack[0];
    goto v_24985;
v_24986:
    v_24991 = qvalue(elt(env, 3)); // dummy_id!*
    goto v_24987;
v_24988:
    goto v_24984;
v_24985:
    goto v_24986;
v_24987:
    fn = elt(env, 6); // union
    v_24991 = (*qfn2(fn))(fn, v_24992, v_24991);
    env = stack[-1];
    qvalue(elt(env, 3)) = v_24991; // dummy_id!*
    v_24991 = nil;
    return onevalue(v_24991);
}



// Code for aex_unbind

static LispObject CC_aex_unbind(LispObject env,
                         LispObject v_24950, LispObject v_24951)
{
    env = qenv(env);
    LispObject v_24970, v_24971;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24951,v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24950,v_24951);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_24951;
    stack[-1] = v_24950;
// end of prologue
    goto v_24958;
v_24954:
    v_24970 = stack[-1];
    fn = elt(env, 1); // aex_ex
    stack[-2] = (*qfn1(fn))(fn, v_24970);
    env = stack[-3];
    goto v_24955;
v_24956:
    goto v_24966;
v_24962:
    v_24970 = stack[-1];
    fn = elt(env, 2); // aex_ctx
    v_24971 = (*qfn1(fn))(fn, v_24970);
    env = stack[-3];
    goto v_24963;
v_24964:
    v_24970 = stack[0];
    goto v_24965;
v_24966:
    goto v_24962;
v_24963:
    goto v_24964;
v_24965:
    fn = elt(env, 3); // ctx_remove
    v_24970 = (*qfn2(fn))(fn, v_24971, v_24970);
    env = stack[-3];
    goto v_24957;
v_24958:
    goto v_24954;
v_24955:
    goto v_24956;
v_24957:
    {
        LispObject v_24975 = stack[-2];
        fn = elt(env, 4); // aex_mk
        return (*qfn2(fn))(fn, v_24975, v_24970);
    }
}



// Code for createtriple

static LispObject CC_createtriple(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_25001, v_25002, v_25003;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_24950;
// end of prologue
    v_25001 = (LispObject)48+TAG_FIXNUM; // 3
    v_25001 = Lmkvect(nil, v_25001);
    env = stack[-3];
    stack[-2] = v_25001;
    goto v_24963;
v_24957:
    v_25003 = stack[-2];
    goto v_24958;
v_24959:
    v_25002 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24960;
v_24961:
    v_25001 = qvalue(elt(env, 1)); // fluidbibasistripleid
    goto v_24962;
v_24963:
    goto v_24957;
v_24958:
    goto v_24959;
v_24960:
    goto v_24961;
v_24962:
    *(LispObject *)((char *)v_25003 + (CELL-TAG_VECTOR) + (((intptr_t)v_25002-TAG_FIXNUM)/(16/CELL))) = v_25001;
    goto v_24973;
v_24967:
    v_25003 = stack[-2];
    goto v_24968;
v_24969:
    v_25002 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24970;
v_24971:
    v_25001 = stack[0];
    goto v_24972;
v_24973:
    goto v_24967;
v_24968:
    goto v_24969;
v_24970:
    goto v_24971;
v_24972:
    *(LispObject *)((char *)v_25003 + (CELL-TAG_VECTOR) + (((intptr_t)v_25002-TAG_FIXNUM)/(16/CELL))) = v_25001;
    goto v_24983;
v_24977:
    v_25003 = stack[-2];
    goto v_24978;
v_24979:
    v_25002 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_24980;
v_24981:
    v_25001 = qvalue(elt(env, 1)); // fluidbibasistripleid
    goto v_24982;
v_24983:
    goto v_24977;
v_24978:
    goto v_24979;
v_24980:
    goto v_24981;
v_24982:
    *(LispObject *)((char *)v_25003 + (CELL-TAG_VECTOR) + (((intptr_t)v_25002-TAG_FIXNUM)/(16/CELL))) = v_25001;
    goto v_24993;
v_24987:
    stack[-1] = stack[-2];
    goto v_24988;
v_24989:
    stack[0] = (LispObject)48+TAG_FIXNUM; // 3
    goto v_24990;
v_24991:
    v_25001 = nil;
    v_25001 = ncons(v_25001);
    env = stack[-3];
    goto v_24992;
v_24993:
    goto v_24987;
v_24988:
    goto v_24989;
v_24990:
    goto v_24991;
v_24992:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_25001;
    v_25001 = qvalue(elt(env, 1)); // fluidbibasistripleid
    v_25001 = (LispObject)((intptr_t)(v_25001) + 0x10);
    qvalue(elt(env, 1)) = v_25001; // fluidbibasistripleid
    v_25001 = stack[-2];
    return onevalue(v_25001);
}



// Code for totalcompareconstants

static LispObject CC_totalcompareconstants(LispObject env,
                         LispObject v_24950, LispObject v_24951)
{
    env = qenv(env);
    LispObject v_25121, v_25122, v_25123;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24951,v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24950,v_24951);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_24951;
    stack[-2] = v_24950;
// end of prologue
    goto v_24961;
v_24957:
    v_25122 = stack[-2];
    goto v_24958;
v_24959:
    v_25121 = stack[-1];
    goto v_24960;
v_24961:
    goto v_24957;
v_24958:
    goto v_24959;
v_24960:
    if (equal(v_25122, v_25121)) goto v_24955;
    else goto v_24956;
v_24955:
    v_25121 = elt(env, 1); // equal
    goto v_24954;
v_24956:
    v_25121 = stack[-2];
    if (!consp(v_25121)) goto v_24969;
    else goto v_24970;
v_24969:
    v_25121 = lisp_true;
    goto v_24968;
v_24970:
    v_25121 = stack[-2];
    v_25121 = qcar(v_25121);
    v_25121 = (consp(v_25121) ? nil : lisp_true);
    goto v_24968;
    v_25121 = nil;
v_24968:
    if (v_25121 == nil) goto v_24966;
    v_25121 = stack[-1];
    if (!consp(v_25121)) goto v_24984;
    else goto v_24985;
v_24984:
    v_25121 = lisp_true;
    goto v_24983;
v_24985:
    v_25121 = stack[-1];
    v_25121 = qcar(v_25121);
    v_25121 = (consp(v_25121) ? nil : lisp_true);
    goto v_24983;
    v_25121 = nil;
v_24983:
    if (v_25121 == nil) goto v_24981;
    goto v_25002;
v_24998:
    v_25121 = stack[-2];
    if (v_25121 == nil) goto v_25005;
    else goto v_25006;
v_25005:
    v_25121 = (LispObject)0+TAG_FIXNUM; // 0
    v_25122 = v_25121;
    goto v_25004;
v_25006:
    v_25121 = stack[-2];
    v_25122 = v_25121;
    goto v_25004;
    v_25122 = nil;
v_25004:
    goto v_24999;
v_25000:
    v_25121 = stack[-1];
    if (v_25121 == nil) goto v_25014;
    else goto v_25015;
v_25014:
    v_25121 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25013;
v_25015:
    v_25121 = stack[-1];
    goto v_25013;
    v_25121 = nil;
v_25013:
    goto v_25001;
v_25002:
    goto v_24998;
v_24999:
    goto v_25000;
v_25001:
    v_25121 = (LispObject)lessp2(v_25122, v_25121);
    v_25121 = v_25121 ? lisp_true : nil;
    env = stack[-4];
    if (v_25121 == nil) goto v_24996;
    v_25121 = elt(env, 2); // less
    goto v_24994;
v_24996:
    v_25121 = elt(env, 3); // greater
    goto v_24994;
    v_25121 = nil;
v_24994:
    goto v_24979;
v_24981:
    v_25121 = elt(env, 2); // less
    goto v_24979;
    v_25121 = nil;
v_24979:
    goto v_24954;
v_24966:
    v_25121 = stack[-1];
    if (!consp(v_25121)) goto v_25032;
    else goto v_25033;
v_25032:
    v_25121 = lisp_true;
    goto v_25031;
v_25033:
    v_25121 = stack[-1];
    v_25121 = qcar(v_25121);
    v_25121 = (consp(v_25121) ? nil : lisp_true);
    goto v_25031;
    v_25121 = nil;
v_25031:
    if (v_25121 == nil) goto v_25029;
    v_25121 = elt(env, 3); // greater
    goto v_24954;
v_25029:
// Binding wukord!*
// FLUIDBIND: reloadenv=4 litvec-offset=4 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 4, -3);
    qvalue(elt(env, 4)) = nil; // wukord!*
// Binding wuvarlist!*
// FLUIDBIND: reloadenv=4 litvec-offset=5 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 5, 0);
    qvalue(elt(env, 5)) = nil; // wuvarlist!*
    goto v_25058;
v_25054:
    v_25121 = stack[-2];
    v_25121 = qcar(v_25121);
    v_25121 = qcar(v_25121);
    v_25122 = qcar(v_25121);
    goto v_25055;
v_25056:
    v_25121 = stack[-1];
    v_25121 = qcar(v_25121);
    v_25121 = qcar(v_25121);
    v_25121 = qcar(v_25121);
    goto v_25057;
v_25058:
    goto v_25054;
v_25055:
    goto v_25056;
v_25057:
    fn = elt(env, 6); // symbollessp
    v_25121 = (*qfn2(fn))(fn, v_25122, v_25121);
    env = stack[-4];
    if (v_25121 == nil) goto v_25052;
    v_25121 = elt(env, 2); // less
    goto v_25048;
v_25052:
    goto v_25075;
v_25071:
    v_25121 = stack[-1];
    v_25121 = qcar(v_25121);
    v_25121 = qcar(v_25121);
    v_25122 = qcar(v_25121);
    goto v_25072;
v_25073:
    v_25121 = stack[-2];
    v_25121 = qcar(v_25121);
    v_25121 = qcar(v_25121);
    v_25121 = qcar(v_25121);
    goto v_25074;
v_25075:
    goto v_25071;
v_25072:
    goto v_25073;
v_25074:
    fn = elt(env, 6); // symbollessp
    v_25121 = (*qfn2(fn))(fn, v_25122, v_25121);
    env = stack[-4];
    if (v_25121 == nil) goto v_25069;
    v_25121 = elt(env, 3); // greater
    goto v_25048;
v_25069:
    goto v_25092;
v_25088:
    v_25121 = stack[-2];
    v_25121 = qcar(v_25121);
    v_25122 = qcdr(v_25121);
    goto v_25089;
v_25090:
    v_25121 = stack[-1];
    v_25121 = qcar(v_25121);
    v_25121 = qcdr(v_25121);
    goto v_25091;
v_25092:
    goto v_25088;
v_25089:
    goto v_25090;
v_25091:
    v_25121 = CC_totalcompareconstants(elt(env, 0), v_25122, v_25121);
    env = stack[-4];
    v_25123 = v_25121;
    goto v_25050;
v_25050:
    goto v_25107;
v_25103:
    v_25122 = v_25123;
    goto v_25104;
v_25105:
    v_25121 = elt(env, 1); // equal
    goto v_25106;
v_25107:
    goto v_25103;
v_25104:
    goto v_25105;
v_25106:
    if (v_25122 == v_25121) goto v_25102;
    v_25121 = v_25123;
    goto v_25048;
v_25102:
    goto v_25116;
v_25112:
    v_25121 = stack[-2];
    v_25122 = qcdr(v_25121);
    goto v_25113;
v_25114:
    v_25121 = stack[-1];
    v_25121 = qcdr(v_25121);
    goto v_25115;
v_25116:
    goto v_25112;
v_25113:
    goto v_25114;
v_25115:
    v_25121 = CC_totalcompareconstants(elt(env, 0), v_25122, v_25121);
v_25048:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_24954;
    v_25121 = nil;
v_24954:
    return onevalue(v_25121);
}



// Code for mk!+resimp!+mat

static LispObject CC_mkLresimpLmat(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_25080;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    v_25080 = v_24950;
// end of prologue
    stack[-7] = v_25080;
    v_25080 = stack[-7];
    if (v_25080 == nil) goto v_24966;
    else goto v_24967;
v_24966:
    v_25080 = nil;
    goto v_24961;
v_24967:
    v_25080 = stack[-7];
    v_25080 = qcar(v_25080);
    stack[-3] = v_25080;
    v_25080 = stack[-3];
    if (v_25080 == nil) goto v_24983;
    else goto v_24984;
v_24983:
    v_25080 = nil;
    goto v_24978;
v_24984:
    v_25080 = stack[-3];
    v_25080 = qcar(v_25080);
    fn = elt(env, 1); // resimp
    v_25080 = (*qfn1(fn))(fn, v_25080);
    env = stack[-8];
    v_25080 = ncons(v_25080);
    env = stack[-8];
    stack[-1] = v_25080;
    stack[-2] = v_25080;
v_24979:
    v_25080 = stack[-3];
    v_25080 = qcdr(v_25080);
    stack[-3] = v_25080;
    v_25080 = stack[-3];
    if (v_25080 == nil) goto v_24997;
    else goto v_24998;
v_24997:
    v_25080 = stack[-2];
    goto v_24978;
v_24998:
    goto v_25006;
v_25002:
    stack[0] = stack[-1];
    goto v_25003;
v_25004:
    v_25080 = stack[-3];
    v_25080 = qcar(v_25080);
    fn = elt(env, 1); // resimp
    v_25080 = (*qfn1(fn))(fn, v_25080);
    env = stack[-8];
    v_25080 = ncons(v_25080);
    env = stack[-8];
    goto v_25005;
v_25006:
    goto v_25002;
v_25003:
    goto v_25004;
v_25005:
    v_25080 = Lrplacd(nil, stack[0], v_25080);
    env = stack[-8];
    v_25080 = stack[-1];
    v_25080 = qcdr(v_25080);
    stack[-1] = v_25080;
    goto v_24979;
v_24978:
    v_25080 = ncons(v_25080);
    env = stack[-8];
    stack[-5] = v_25080;
    stack[-6] = v_25080;
v_24962:
    v_25080 = stack[-7];
    v_25080 = qcdr(v_25080);
    stack[-7] = v_25080;
    v_25080 = stack[-7];
    if (v_25080 == nil) goto v_25020;
    else goto v_25021;
v_25020:
    v_25080 = stack[-6];
    goto v_24961;
v_25021:
    goto v_25029;
v_25025:
    stack[-4] = stack[-5];
    goto v_25026;
v_25027:
    v_25080 = stack[-7];
    v_25080 = qcar(v_25080);
    stack[-3] = v_25080;
    v_25080 = stack[-3];
    if (v_25080 == nil) goto v_25044;
    else goto v_25045;
v_25044:
    v_25080 = nil;
    goto v_25039;
v_25045:
    v_25080 = stack[-3];
    v_25080 = qcar(v_25080);
    fn = elt(env, 1); // resimp
    v_25080 = (*qfn1(fn))(fn, v_25080);
    env = stack[-8];
    v_25080 = ncons(v_25080);
    env = stack[-8];
    stack[-1] = v_25080;
    stack[-2] = v_25080;
v_25040:
    v_25080 = stack[-3];
    v_25080 = qcdr(v_25080);
    stack[-3] = v_25080;
    v_25080 = stack[-3];
    if (v_25080 == nil) goto v_25058;
    else goto v_25059;
v_25058:
    v_25080 = stack[-2];
    goto v_25039;
v_25059:
    goto v_25067;
v_25063:
    stack[0] = stack[-1];
    goto v_25064;
v_25065:
    v_25080 = stack[-3];
    v_25080 = qcar(v_25080);
    fn = elt(env, 1); // resimp
    v_25080 = (*qfn1(fn))(fn, v_25080);
    env = stack[-8];
    v_25080 = ncons(v_25080);
    env = stack[-8];
    goto v_25066;
v_25067:
    goto v_25063;
v_25064:
    goto v_25065;
v_25066:
    v_25080 = Lrplacd(nil, stack[0], v_25080);
    env = stack[-8];
    v_25080 = stack[-1];
    v_25080 = qcdr(v_25080);
    stack[-1] = v_25080;
    goto v_25040;
v_25039:
    v_25080 = ncons(v_25080);
    env = stack[-8];
    goto v_25028;
v_25029:
    goto v_25025;
v_25026:
    goto v_25027;
v_25028:
    v_25080 = Lrplacd(nil, stack[-4], v_25080);
    env = stack[-8];
    v_25080 = stack[-5];
    v_25080 = qcdr(v_25080);
    stack[-5] = v_25080;
    goto v_24962;
v_24961:
    return onevalue(v_25080);
}



// Code for talp_invtscsimpl

static LispObject CC_talp_invtscsimpl(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_25091, v_25092, v_25093;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_24950;
// end of prologue
    v_25091 = stack[0];
    fn = elt(env, 4); // talp_rnf
    v_25091 = (*qfn1(fn))(fn, v_25091);
    env = stack[-5];
    stack[0] = v_25091;
    v_25091 = stack[0];
    if (!consp(v_25091)) goto v_24959;
    else goto v_24960;
v_24959:
    v_25091 = stack[0];
    goto v_24954;
v_24960:
    v_25091 = stack[0];
    fn = elt(env, 5); // talp_atfp
    v_25091 = (*qfn1(fn))(fn, v_25091);
    env = stack[-5];
    if (v_25091 == nil) goto v_24966;
    v_25091 = stack[0];
    fn = elt(env, 6); // talp_invtscc
    v_25091 = (*qfn1(fn))(fn, v_25091);
    env = stack[-5];
    if (v_25091 == nil) goto v_24972;
    v_25091 = stack[0];
    fn = elt(env, 7); // talp_simpat
    v_25091 = (*qfn1(fn))(fn, v_25091);
    env = stack[-5];
    fn = elt(env, 8); // talp_invtscsimplat
    v_25091 = (*qfn1(fn))(fn, v_25091);
    env = stack[-5];
    {
        fn = elt(env, 4); // talp_rnf
        return (*qfn1(fn))(fn, v_25091);
    }
v_24972:
    v_25091 = stack[0];
    {
        fn = elt(env, 7); // talp_simpat
        return (*qfn1(fn))(fn, v_25091);
    }
    goto v_24964;
v_24966:
v_24964:
    v_25091 = stack[0];
    fn = elt(env, 9); // talp_op
    v_25091 = (*qfn1(fn))(fn, v_25091);
    env = stack[-5];
    v_25093 = v_25091;
    goto v_24997;
v_24993:
    v_25092 = v_25093;
    goto v_24994;
v_24995:
    v_25091 = elt(env, 1); // or
    goto v_24996;
v_24997:
    goto v_24993;
v_24994:
    goto v_24995;
v_24996:
    if (v_25092 == v_25091) goto v_24991;
    else goto v_24992;
v_24991:
    v_25091 = lisp_true;
    goto v_24990;
v_24992:
    goto v_25007;
v_25003:
    v_25092 = v_25093;
    goto v_25004;
v_25005:
    v_25091 = elt(env, 2); // and
    goto v_25006;
v_25007:
    goto v_25003;
v_25004:
    goto v_25005;
v_25006:
    v_25091 = (v_25092 == v_25091 ? lisp_true : nil);
    goto v_24990;
    v_25091 = nil;
v_24990:
    if (v_25091 == nil) goto v_24988;
    goto v_25017;
v_25013:
    stack[-4] = v_25093;
    goto v_25014;
v_25015:
    v_25091 = stack[0];
    fn = elt(env, 10); // talp_argl
    v_25091 = (*qfn1(fn))(fn, v_25091);
    env = stack[-5];
    stack[-3] = v_25091;
    v_25091 = stack[-3];
    if (v_25091 == nil) goto v_25029;
    else goto v_25030;
v_25029:
    v_25091 = nil;
    goto v_25023;
v_25030:
    v_25091 = stack[-3];
    v_25091 = qcar(v_25091);
    v_25091 = CC_talp_invtscsimpl(elt(env, 0), v_25091);
    env = stack[-5];
    v_25091 = ncons(v_25091);
    env = stack[-5];
    stack[-1] = v_25091;
    stack[-2] = v_25091;
v_25024:
    v_25091 = stack[-3];
    v_25091 = qcdr(v_25091);
    stack[-3] = v_25091;
    v_25091 = stack[-3];
    if (v_25091 == nil) goto v_25043;
    else goto v_25044;
v_25043:
    v_25091 = stack[-2];
    goto v_25023;
v_25044:
    goto v_25052;
v_25048:
    stack[0] = stack[-1];
    goto v_25049;
v_25050:
    v_25091 = stack[-3];
    v_25091 = qcar(v_25091);
    v_25091 = CC_talp_invtscsimpl(elt(env, 0), v_25091);
    env = stack[-5];
    v_25091 = ncons(v_25091);
    env = stack[-5];
    goto v_25051;
v_25052:
    goto v_25048;
v_25049:
    goto v_25050;
v_25051:
    v_25091 = Lrplacd(nil, stack[0], v_25091);
    env = stack[-5];
    v_25091 = stack[-1];
    v_25091 = qcdr(v_25091);
    stack[-1] = v_25091;
    goto v_25024;
v_25023:
    goto v_25016;
v_25017:
    goto v_25013;
v_25014:
    goto v_25015;
v_25016:
    v_25091 = cons(stack[-4], v_25091);
    env = stack[-5];
    {
        fn = elt(env, 4); // talp_rnf
        return (*qfn1(fn))(fn, v_25091);
    }
v_24988:
    goto v_25068;
v_25064:
    v_25092 = v_25093;
    goto v_25065;
v_25066:
    v_25091 = elt(env, 3); // (ex all)
    goto v_25067;
v_25068:
    goto v_25064;
v_25065:
    goto v_25066;
v_25067:
    v_25091 = Lmemq(nil, v_25092, v_25091);
    if (v_25091 == nil) goto v_25063;
    goto v_25080;
v_25074:
    stack[-2] = v_25093;
    goto v_25075;
v_25076:
    v_25091 = stack[0];
    v_25091 = qcdr(v_25091);
    stack[-1] = qcar(v_25091);
    goto v_25077;
v_25078:
    v_25091 = stack[0];
    v_25091 = qcdr(v_25091);
    v_25091 = qcdr(v_25091);
    v_25091 = qcar(v_25091);
    v_25091 = CC_talp_invtscsimpl(elt(env, 0), v_25091);
    env = stack[-5];
    v_25091 = ncons(v_25091);
    env = stack[-5];
    goto v_25079;
v_25080:
    goto v_25074;
v_25075:
    goto v_25076;
v_25077:
    goto v_25078;
v_25079:
    v_25091 = list2star(stack[-2], stack[-1], v_25091);
    env = stack[-5];
    {
        fn = elt(env, 4); // talp_rnf
        return (*qfn1(fn))(fn, v_25091);
    }
v_25063:
    v_25091 = nil;
v_24954:
    return onevalue(v_25091);
}



// Code for matrixml

static LispObject CC_matrixml(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24997, v_24998;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_24950;
// end of prologue
    v_24997 = elt(env, 1); // "<matrix"
    fn = elt(env, 5); // printout
    v_24997 = (*qfn1(fn))(fn, v_24997);
    env = stack[-1];
    goto v_24961;
v_24957:
    v_24997 = stack[0];
    v_24998 = qcar(v_24997);
    goto v_24958;
v_24959:
    v_24997 = elt(env, 2); // ""
    goto v_24960;
v_24961:
    goto v_24957;
v_24958:
    goto v_24959;
v_24960:
    fn = elt(env, 6); // attributesml
    v_24997 = (*qfn2(fn))(fn, v_24998, v_24997);
    env = stack[-1];
    v_24997 = lisp_true;
    fn = elt(env, 7); // indent!*
    v_24997 = (*qfn1(fn))(fn, v_24997);
    env = stack[-1];
    goto v_24975;
v_24971:
    v_24997 = stack[0];
    v_24997 = qcdr(v_24997);
    v_24998 = qcar(v_24997);
    goto v_24972;
v_24973:
    v_24997 = elt(env, 3); // matrixrow
    goto v_24974;
v_24975:
    goto v_24971;
v_24972:
    goto v_24973;
v_24974:
    if (v_24998 == v_24997) goto v_24969;
    else goto v_24970;
v_24969:
    v_24997 = stack[0];
    v_24997 = qcdr(v_24997);
    v_24997 = qcdr(v_24997);
    v_24997 = qcar(v_24997);
    fn = elt(env, 8); // matrix_rows
    v_24997 = (*qfn1(fn))(fn, v_24997);
    env = stack[-1];
    goto v_24968;
v_24970:
    v_24997 = stack[0];
    v_24997 = qcdr(v_24997);
    v_24997 = qcdr(v_24997);
    v_24997 = qcar(v_24997);
    fn = elt(env, 9); // cols2rows
    v_24997 = (*qfn1(fn))(fn, v_24997);
    env = stack[-1];
    fn = elt(env, 8); // matrix_rows
    v_24997 = (*qfn1(fn))(fn, v_24997);
    env = stack[-1];
    goto v_24968;
v_24968:
    v_24997 = nil;
    fn = elt(env, 7); // indent!*
    v_24997 = (*qfn1(fn))(fn, v_24997);
    env = stack[-1];
    v_24997 = elt(env, 4); // "</matrix>"
    fn = elt(env, 5); // printout
    v_24997 = (*qfn1(fn))(fn, v_24997);
    v_24997 = nil;
    return onevalue(v_24997);
}



// Code for ieval

static LispObject CC_ieval(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24955;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_24955 = v_24950;
// end of prologue
    fn = elt(env, 1); // reval
    v_24955 = (*qfn1(fn))(fn, v_24955);
    env = stack[0];
    {
        fn = elt(env, 2); // !*s2i
        return (*qfn1(fn))(fn, v_24955);
    }
}



// Code for diford

static LispObject CC_diford(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24956;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24956 = v_24950;
// end of prologue
    v_24956 = qcdr(v_24956);
    v_24956 = qcdr(v_24956);
    {
        fn = elt(env, 1); // lengthn
        return (*qfn1(fn))(fn, v_24956);
    }
}



// Code for specrd!:times

static LispObject CC_specrdTtimes(LispObject env,
                         LispObject v_24950, LispObject v_24951)
{
    env = qenv(env);
    LispObject v_25039, v_25040;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24951,v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24950,v_24951);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_24951;
    stack[-1] = v_24950;
// end of prologue
    stack[-2] = nil;
    v_25039 = stack[-1];
    fn = elt(env, 2); // add_minus
    v_25039 = (*qfn1(fn))(fn, v_25039);
    env = stack[-3];
    stack[-1] = v_25039;
    v_25039 = stack[0];
    fn = elt(env, 2); // add_minus
    v_25039 = (*qfn1(fn))(fn, v_25039);
    env = stack[-3];
    stack[0] = v_25039;
    goto v_24969;
v_24965:
    v_25040 = stack[-1];
    goto v_24966;
v_24967:
    v_25039 = elt(env, 1); // minus
    goto v_24968;
v_24969:
    goto v_24965;
v_24966:
    goto v_24967;
v_24968:
    if (!consp(v_25040)) goto v_24963;
    v_25040 = qcar(v_25040);
    if (v_25040 == v_25039) goto v_24962;
    else goto v_24963;
v_24962:
    v_25039 = stack[-1];
    v_25039 = qcdr(v_25039);
    v_25039 = qcar(v_25039);
    stack[-1] = v_25039;
    v_25039 = lisp_true;
    stack[-2] = v_25039;
    goto v_24961;
v_24963:
v_24961:
    goto v_24985;
v_24981:
    v_25040 = stack[0];
    goto v_24982;
v_24983:
    v_25039 = elt(env, 1); // minus
    goto v_24984;
v_24985:
    goto v_24981;
v_24982:
    goto v_24983;
v_24984:
    if (!consp(v_25040)) goto v_24979;
    v_25040 = qcar(v_25040);
    if (v_25040 == v_25039) goto v_24978;
    else goto v_24979;
v_24978:
    v_25039 = stack[0];
    v_25039 = qcdr(v_25039);
    v_25039 = qcar(v_25039);
    stack[0] = v_25039;
    v_25039 = stack[-2];
    v_25039 = (v_25039 == nil ? lisp_true : nil);
    stack[-2] = v_25039;
    goto v_24977;
v_24979:
v_24977:
    v_25039 = stack[-1];
    if (!consp(v_25039)) goto v_24995;
    else goto v_24996;
v_24995:
    v_25039 = stack[-1];
    v_25039 = Lfloat(nil, v_25039);
    env = stack[-3];
    fn = elt(env, 3); // mkround
    v_25039 = (*qfn1(fn))(fn, v_25039);
    env = stack[-3];
    stack[-1] = v_25039;
    goto v_24994;
v_24996:
v_24994:
    v_25039 = stack[0];
    if (!consp(v_25039)) goto v_25003;
    else goto v_25004;
v_25003:
    v_25039 = stack[0];
    v_25039 = Lfloat(nil, v_25039);
    env = stack[-3];
    fn = elt(env, 3); // mkround
    v_25039 = (*qfn1(fn))(fn, v_25039);
    env = stack[-3];
    stack[0] = v_25039;
    goto v_25002;
v_25004:
v_25002:
    v_25039 = stack[-2];
    if (v_25039 == nil) goto v_25012;
    goto v_25019;
v_25015:
    stack[-2] = elt(env, 1); // minus
    goto v_25016;
v_25017:
    goto v_25026;
v_25022:
    v_25040 = stack[-1];
    goto v_25023;
v_25024:
    v_25039 = stack[0];
    goto v_25025;
v_25026:
    goto v_25022;
v_25023:
    goto v_25024;
v_25025:
    fn = elt(env, 4); // rd!:times
    v_25039 = (*qfn2(fn))(fn, v_25040, v_25039);
    goto v_25018;
v_25019:
    goto v_25015;
v_25016:
    goto v_25017;
v_25018:
    {
        LispObject v_25044 = stack[-2];
        return list2(v_25044, v_25039);
    }
v_25012:
    goto v_25036;
v_25032:
    v_25040 = stack[-1];
    goto v_25033;
v_25034:
    v_25039 = stack[0];
    goto v_25035;
v_25036:
    goto v_25032;
v_25033:
    goto v_25034;
v_25035:
    {
        fn = elt(env, 4); // rd!:times
        return (*qfn2(fn))(fn, v_25040, v_25039);
    }
    v_25039 = nil;
    return onevalue(v_25039);
}



// Code for letmtr

static LispObject CC_letmtr(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25047, v_25048, v_25049;
    LispObject fn;
    LispObject v_24952, v_24951, v_24950;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "letmtr");
    va_start(aa, nargs);
    v_24950 = va_arg(aa, LispObject);
    v_24951 = va_arg(aa, LispObject);
    v_24952 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24952,v_24951,v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24950,v_24951,v_24952);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_24952;
    stack[-3] = v_24951;
    stack[-4] = v_24950;
// end of prologue
    stack[-5] = nil;
    goto v_24966;
v_24962:
    v_25048 = stack[-2];
    goto v_24963;
v_24964:
    v_25047 = elt(env, 1); // mat
    goto v_24965;
v_24966:
    goto v_24962;
v_24963:
    goto v_24964;
v_24965:
    if (!consp(v_25048)) goto v_24959;
    v_25048 = qcar(v_25048);
    if (v_25048 == v_25047) goto v_24960;
v_24959:
    goto v_24976;
v_24970:
    stack[-1] = elt(env, 2); // matrix
    goto v_24971;
v_24972:
    stack[0] = (LispObject)160+TAG_FIXNUM; // 10
    goto v_24973;
v_24974:
    goto v_24986;
v_24980:
    v_25049 = elt(env, 3); // "Matrix"
    goto v_24981;
v_24982:
    v_25047 = stack[-4];
    v_25048 = qcar(v_25047);
    goto v_24983;
v_24984:
    v_25047 = elt(env, 4); // "not set"
    goto v_24985;
v_24986:
    goto v_24980;
v_24981:
    goto v_24982;
v_24983:
    goto v_24984;
v_24985:
    v_25047 = list3(v_25049, v_25048, v_25047);
    env = stack[-6];
    goto v_24975;
v_24976:
    goto v_24970;
v_24971:
    goto v_24972;
v_24973:
    goto v_24974;
v_24975:
    fn = elt(env, 6); // rerror
    v_25047 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_25047);
    env = stack[-6];
    goto v_24958;
v_24960:
    v_25047 = stack[-4];
    v_25047 = qcdr(v_25047);
    fn = elt(env, 7); // revlis
    v_25047 = (*qfn1(fn))(fn, v_25047);
    env = stack[-6];
    stack[-5] = v_25047;
    fn = elt(env, 8); // numlis
    v_25047 = (*qfn1(fn))(fn, v_25047);
    env = stack[-6];
    if (v_25047 == nil) goto v_24995;
    else goto v_24996;
v_24995:
    v_25047 = lisp_true;
    goto v_24994;
v_24996:
    goto v_25009;
v_25005:
    v_25047 = stack[-5];
    v_25048 = Llength(nil, v_25047);
    env = stack[-6];
    goto v_25006;
v_25007:
    v_25047 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_25008;
v_25009:
    goto v_25005;
v_25006:
    goto v_25007;
v_25008:
    v_25047 = Lneq(nil, v_25048, v_25047);
    env = stack[-6];
    goto v_24994;
    v_25047 = nil;
v_24994:
    if (v_25047 == nil) goto v_24992;
    goto v_25018;
v_25014:
    v_25048 = stack[-4];
    goto v_25015;
v_25016:
    v_25047 = elt(env, 5); // hold
    goto v_25017;
v_25018:
    goto v_25014;
v_25015:
    goto v_25016;
v_25017:
    {
        fn = elt(env, 9); // errpri2
        return (*qfn2(fn))(fn, v_25048, v_25047);
    }
v_24992:
v_24958:
    goto v_25026;
v_25022:
    goto v_25032;
v_25028:
    goto v_25038;
v_25034:
    v_25047 = stack[-2];
    v_25048 = qcdr(v_25047);
    goto v_25035;
v_25036:
    v_25047 = stack[-5];
    v_25047 = qcar(v_25047);
    goto v_25037;
v_25038:
    goto v_25034;
v_25035:
    goto v_25036;
v_25037:
    fn = elt(env, 10); // nth
    v_25048 = (*qfn2(fn))(fn, v_25048, v_25047);
    env = stack[-6];
    goto v_25029;
v_25030:
    v_25047 = stack[-5];
    v_25047 = qcdr(v_25047);
    v_25047 = qcar(v_25047);
    goto v_25031;
v_25032:
    goto v_25028;
v_25029:
    goto v_25030;
v_25031:
    fn = elt(env, 11); // pnth
    v_25048 = (*qfn2(fn))(fn, v_25048, v_25047);
    env = stack[-6];
    goto v_25023;
v_25024:
    v_25047 = stack[-3];
    goto v_25025;
v_25026:
    goto v_25022;
v_25023:
    goto v_25024;
v_25025:
    v_25047 = Lrplaca(nil, v_25048, v_25047);
    v_25047 = nil;
    return onevalue(v_25047);
}



// Code for remove_least_item

static LispObject CC_remove_least_item(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24976, v_24977;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24976 = v_24950;
// end of prologue
v_24954:
    v_24977 = v_24976;
    v_24977 = qcdr(v_24977);
    if (v_24977 == nil) goto v_24957;
    else goto v_24958;
v_24957:
    v_24976 = elt(env, 1); // "How did we get here?"
    {
        fn = elt(env, 2); // rederr
        return (*qfn1(fn))(fn, v_24976);
    }
v_24958:
    v_24977 = v_24976;
    v_24977 = qcdr(v_24977);
    v_24977 = qcar(v_24977);
    v_24977 = qcdr(v_24977);
    if (v_24977 == nil) goto v_24963;
    else goto v_24964;
v_24963:
    {
        fn = elt(env, 3); // remove_root_item
        return (*qfn1(fn))(fn, v_24976);
    }
v_24964:
    v_24976 = qcdr(v_24976);
    v_24976 = qcar(v_24976);
    goto v_24954;
    v_24976 = nil;
    return onevalue(v_24976);
}



// Code for r2oaddspecies

static LispObject CC_r2oaddspecies(LispObject env,
                         LispObject v_24950, LispObject v_24951)
{
    env = qenv(env);
    LispObject v_24988, v_24989;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24951,v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24950,v_24951);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_24951;
    stack[-1] = v_24950;
// end of prologue
    goto v_24961;
v_24957:
    v_24989 = stack[-1];
    goto v_24958;
v_24959:
    v_24988 = stack[0];
    goto v_24960;
v_24961:
    goto v_24957;
v_24958:
    goto v_24959;
v_24960:
    v_24988 = Lassoc(nil, v_24989, v_24988);
    if (v_24988 == nil) goto v_24956;
    v_24988 = stack[0];
    goto v_24954;
v_24956:
    v_24988 = elt(env, 1); // "new species: "
    v_24988 = Lprinc(nil, v_24988);
    env = stack[-2];
    v_24988 = stack[-1];
    fn = elt(env, 2); // prin2t
    v_24988 = (*qfn1(fn))(fn, v_24988);
    env = stack[-2];
    goto v_24977;
v_24973:
    goto v_24974;
v_24975:
    goto v_24985;
v_24981:
    v_24989 = stack[-1];
    goto v_24982;
v_24983:
    v_24988 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24984;
v_24985:
    goto v_24981;
v_24982:
    goto v_24983;
v_24984:
    v_24988 = cons(v_24989, v_24988);
    env = stack[-2];
    v_24988 = ncons(v_24988);
    goto v_24976;
v_24977:
    goto v_24973;
v_24974:
    goto v_24975;
v_24976:
    {
        LispObject v_24992 = stack[0];
        return Lappend(nil, v_24992, v_24988);
    }
    v_24988 = nil;
v_24954:
    return onevalue(v_24988);
}



// Code for ev!-poles

static LispObject CC_evKpoles(LispObject env,
                         LispObject v_24950, LispObject v_24951)
{
    env = qenv(env);
    LispObject v_24985, v_24986, v_24987, v_24988;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24986 = v_24951;
    v_24987 = v_24950;
// end of prologue
v_24955:
    v_24985 = v_24987;
    if (v_24985 == nil) goto v_24958;
    else goto v_24959;
v_24958:
    v_24985 = nil;
    goto v_24954;
v_24959:
    goto v_24968;
v_24964:
    goto v_24973;
v_24969:
    v_24985 = v_24987;
    v_24988 = qcar(v_24985);
    goto v_24970;
v_24971:
    v_24985 = v_24986;
    goto v_24972;
v_24973:
    goto v_24969;
v_24970:
    goto v_24971;
v_24972:
    v_24985 = Lassoc(nil, v_24988, v_24985);
    v_24988 = qcdr(v_24985);
    goto v_24965;
v_24966:
    v_24985 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24967;
v_24968:
    goto v_24964;
v_24965:
    goto v_24966;
v_24967:
    if (v_24988 == v_24985) goto v_24962;
    else goto v_24963;
v_24962:
    v_24985 = v_24987;
    v_24985 = qcdr(v_24985);
    v_24987 = v_24985;
    goto v_24955;
v_24963:
    v_24985 = v_24987;
    goto v_24954;
    v_24985 = nil;
v_24954:
    return onevalue(v_24985);
}



// Code for mv!-compact2

static LispObject CC_mvKcompact2(LispObject env,
                         LispObject v_24950, LispObject v_24951)
{
    env = qenv(env);
    LispObject v_25012, v_25013, v_25014;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24951,v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24950,v_24951);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_24951;
    stack[-1] = v_24950;
// end of prologue
    goto v_24963;
v_24959:
    v_25013 = stack[-1];
    goto v_24960;
v_24961:
    v_25012 = stack[0];
    goto v_24962;
v_24963:
    goto v_24959;
v_24960:
    goto v_24961;
v_24962:
    fn = elt(env, 1); // equiv!-coeffs
    v_25012 = (*qfn2(fn))(fn, v_25013, v_25012);
    env = stack[-3];
    stack[-2] = v_25012;
    v_25012 = stack[0];
    fn = elt(env, 2); // mv!-domainlist
    v_25012 = (*qfn1(fn))(fn, v_25012);
    env = stack[-3];
    goto v_24973;
v_24969:
    v_25013 = stack[-2];
    goto v_24970;
v_24971:
    goto v_24972;
v_24973:
    goto v_24969;
v_24970:
    goto v_24971;
v_24972:
    fn = elt(env, 3); // reduce
    v_25012 = (*qfn2(fn))(fn, v_25013, v_25012);
    env = stack[-3];
    v_25014 = v_25012;
    goto v_24984;
v_24980:
    v_25013 = v_25014;
    goto v_24981;
v_24982:
    v_25012 = stack[-2];
    goto v_24983;
v_24984:
    goto v_24980;
v_24981:
    goto v_24982;
v_24983:
    if (equal(v_25013, v_25012)) goto v_24978;
    else goto v_24979;
v_24978:
    v_25012 = nil;
    goto v_24977;
v_24979:
    goto v_24995;
v_24991:
    goto v_25001;
v_24997:
    goto v_24998;
v_24999:
    goto v_25008;
v_25004:
    v_25013 = v_25014;
    goto v_25005;
v_25006:
    v_25012 = stack[-2];
    goto v_25007;
v_25008:
    goto v_25004;
v_25005:
    goto v_25006;
v_25007:
    fn = elt(env, 4); // mv!-domainlist!-!-
    v_25012 = (*qfn2(fn))(fn, v_25013, v_25012);
    env = stack[-3];
    goto v_25000;
v_25001:
    goto v_24997;
v_24998:
    goto v_24999;
v_25000:
    fn = elt(env, 5); // mv!-coeff!-replace
    v_25013 = (*qfn2(fn))(fn, stack[0], v_25012);
    env = stack[-3];
    goto v_24992;
v_24993:
    v_25012 = stack[-1];
    goto v_24994;
v_24995:
    goto v_24991;
v_24992:
    goto v_24993;
v_24994:
    {
        fn = elt(env, 6); // mv!-!+
        return (*qfn2(fn))(fn, v_25013, v_25012);
    }
    v_25012 = nil;
v_24977:
    return onevalue(v_25012);
}



// Code for prepcadr

static LispObject CC_prepcadr(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_24956;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24956 = v_24950;
// end of prologue
    v_24956 = qcdr(v_24956);
    v_24956 = qcar(v_24956);
    {
        fn = elt(env, 1); // prepsq
        return (*qfn1(fn))(fn, v_24956);
    }
}



// Code for listminimize

static LispObject CC_listminimize(LispObject env,
                         LispObject v_24950, LispObject v_24951)
{
    env = qenv(env);
    LispObject v_24973, v_24974, v_24975;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24951,v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24950,v_24951);
    }
// copy arguments values to proper place
    v_24973 = v_24951;
    v_24974 = v_24950;
// end of prologue
    v_24975 = v_24974;
    if (v_24975 == nil) goto v_24955;
    else goto v_24956;
v_24955:
    v_24973 = nil;
    goto v_24954;
v_24956:
    goto v_24969;
v_24963:
    v_24975 = nil;
    goto v_24964;
v_24965:
    goto v_24966;
v_24967:
    goto v_24968;
v_24969:
    goto v_24963;
v_24964:
    goto v_24965;
v_24966:
    goto v_24967;
v_24968:
    fn = elt(env, 1); // cali!=min
    v_24973 = (*qfnn(fn))(fn, 3, v_24975, v_24974, v_24973);
        return Lreverse(nil, v_24973);
    v_24973 = nil;
v_24954:
    return onevalue(v_24973);
}



// Code for general!-multiply!-by!-constant!-mod!-p

static LispObject CC_generalKmultiplyKbyKconstantKmodKp(LispObject env,
                         LispObject v_24950, LispObject v_24951)
{
    env = qenv(env);
    LispObject v_25035, v_25036, v_25037;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_24951,v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_24950,v_24951);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_24951;
    stack[-1] = v_24950;
// end of prologue
    v_25035 = stack[-1];
    if (v_25035 == nil) goto v_24955;
    else goto v_24956;
v_24955:
    v_25035 = nil;
    goto v_24954;
v_24956:
    goto v_24965;
v_24961:
    v_25036 = stack[0];
    goto v_24962;
v_24963:
    v_25035 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_24964;
v_24965:
    goto v_24961;
v_24962:
    goto v_24963;
v_24964:
    if (v_25036 == v_25035) goto v_24959;
    else goto v_24960;
v_24959:
    v_25035 = stack[-1];
    goto v_24954;
v_24960:
    v_25035 = stack[-1];
    if (!consp(v_25035)) goto v_24973;
    else goto v_24974;
v_24973:
    v_25035 = lisp_true;
    goto v_24972;
v_24974:
    v_25035 = stack[-1];
    v_25035 = qcar(v_25035);
    v_25035 = (consp(v_25035) ? nil : lisp_true);
    goto v_24972;
    v_25035 = nil;
v_24972:
    if (v_25035 == nil) goto v_24970;
    goto v_24988;
v_24984:
    v_25036 = stack[-1];
    goto v_24985;
v_24986:
    v_25035 = stack[0];
    goto v_24987;
v_24988:
    goto v_24984;
v_24985:
    goto v_24986;
v_24987:
    fn = elt(env, 1); // general!-modular!-times
    v_25035 = (*qfn2(fn))(fn, v_25036, v_25035);
    env = stack[-3];
    {
        fn = elt(env, 2); // !*n2f
        return (*qfn1(fn))(fn, v_25035);
    }
v_24970:
    goto v_24998;
v_24994:
    v_25035 = stack[-1];
    v_25035 = qcar(v_25035);
    v_25036 = qcdr(v_25035);
    goto v_24995;
v_24996:
    v_25035 = stack[0];
    goto v_24997;
v_24998:
    goto v_24994;
v_24995:
    goto v_24996;
v_24997:
    stack[-2] = CC_generalKmultiplyKbyKconstantKmodKp(elt(env, 0), v_25036, v_25035);
    env = stack[-3];
    goto v_25008;
v_25004:
    v_25035 = stack[-1];
    v_25036 = qcdr(v_25035);
    goto v_25005;
v_25006:
    v_25035 = stack[0];
    goto v_25007;
v_25008:
    goto v_25004;
v_25005:
    goto v_25006;
v_25007:
    v_25035 = CC_generalKmultiplyKbyKconstantKmodKp(elt(env, 0), v_25036, v_25035);
    v_25036 = stack[-2];
    v_25037 = v_25036;
    if (v_25037 == nil) goto v_25016;
    else goto v_25017;
v_25016:
    goto v_25015;
v_25017:
    goto v_25029;
v_25023:
    v_25037 = stack[-1];
    v_25037 = qcar(v_25037);
    v_25037 = qcar(v_25037);
    goto v_25024;
v_25025:
    goto v_25026;
v_25027:
    goto v_25028;
v_25029:
    goto v_25023;
v_25024:
    goto v_25025;
v_25026:
    goto v_25027;
v_25028:
    return acons(v_25037, v_25036, v_25035);
    v_25035 = nil;
v_25015:
    goto v_24954;
    v_25035 = nil;
v_24954:
    return onevalue(v_25035);
}



// Code for mchsarg

static LispObject CC_mchsarg(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25113, v_25114;
    LispObject fn;
    LispObject v_24952, v_24951, v_24950;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mchsarg");
    va_start(aa, nargs);
    v_24950 = va_arg(aa, LispObject);
    v_24951 = va_arg(aa, LispObject);
    v_24952 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_24952,v_24951,v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_24950,v_24951,v_24952);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_24952;
    stack[-6] = v_24951;
    stack[-1] = v_24950;
// end of prologue
    v_25113 = stack[-6];
    fn = elt(env, 2); // mtp
    v_25113 = (*qfn1(fn))(fn, v_25113);
    env = stack[-8];
    if (v_25113 == nil) goto v_24958;
    goto v_24971;
v_24967:
    v_25114 = stack[-5];
    goto v_24968;
v_24969:
    v_25113 = elt(env, 1); // times
    goto v_24970;
v_24971:
    goto v_24967;
v_24968:
    goto v_24969;
v_24970:
    if (v_25114 == v_25113) goto v_24966;
    v_25113 = lisp_true;
    goto v_24964;
v_24966:
    v_25113 = stack[-1];
    fn = elt(env, 3); // noncomfree
    v_25113 = (*qfn1(fn))(fn, v_25113);
    env = stack[-8];
    goto v_24964;
    v_25113 = nil;
v_24964:
    if (v_25113 == nil) goto v_24958;
    v_25113 = stack[-6];
    fn = elt(env, 4); // noncomperm
    v_25113 = (*qfn1(fn))(fn, v_25113);
    env = stack[-8];
    stack[-4] = v_25113;
    v_25113 = stack[-4];
    if (v_25113 == nil) goto v_24989;
    else goto v_24990;
v_24989:
    v_25113 = nil;
    goto v_24983;
v_24990:
    v_25113 = stack[-4];
    v_25113 = qcar(v_25113);
    goto v_25002;
v_24998:
    v_25114 = v_25113;
    goto v_24999;
v_25000:
    v_25113 = stack[-1];
    goto v_25001;
v_25002:
    goto v_24998;
v_24999:
    goto v_25000;
v_25001:
    fn = elt(env, 5); // pair
    v_25113 = (*qfn2(fn))(fn, v_25114, v_25113);
    env = stack[-8];
    v_25113 = ncons(v_25113);
    env = stack[-8];
    stack[-2] = v_25113;
    stack[-3] = v_25113;
v_24984:
    v_25113 = stack[-4];
    v_25113 = qcdr(v_25113);
    stack[-4] = v_25113;
    v_25113 = stack[-4];
    if (v_25113 == nil) goto v_25009;
    else goto v_25010;
v_25009:
    v_25113 = stack[-3];
    goto v_24983;
v_25010:
    goto v_25018;
v_25014:
    stack[0] = stack[-2];
    goto v_25015;
v_25016:
    v_25113 = stack[-4];
    v_25113 = qcar(v_25113);
    goto v_25029;
v_25025:
    v_25114 = v_25113;
    goto v_25026;
v_25027:
    v_25113 = stack[-1];
    goto v_25028;
v_25029:
    goto v_25025;
v_25026:
    goto v_25027;
v_25028:
    fn = elt(env, 5); // pair
    v_25113 = (*qfn2(fn))(fn, v_25114, v_25113);
    env = stack[-8];
    v_25113 = ncons(v_25113);
    env = stack[-8];
    goto v_25017;
v_25018:
    goto v_25014;
v_25015:
    goto v_25016;
v_25017:
    v_25113 = Lrplacd(nil, stack[0], v_25113);
    env = stack[-8];
    v_25113 = stack[-2];
    v_25113 = qcdr(v_25113);
    stack[-2] = v_25113;
    goto v_24984;
v_24983:
    goto v_24956;
v_24958:
    v_25113 = stack[-1];
    fn = elt(env, 4); // noncomperm
    v_25113 = (*qfn1(fn))(fn, v_25113);
    env = stack[-8];
    stack[-7] = v_25113;
v_25041:
    v_25113 = stack[-7];
    if (v_25113 == nil) goto v_25047;
    else goto v_25048;
v_25047:
    v_25113 = nil;
    goto v_25040;
v_25048:
    v_25113 = stack[-7];
    v_25113 = qcar(v_25113);
    goto v_25063;
v_25055:
    stack[-1] = v_25113;
    goto v_25056;
v_25057:
    stack[0] = stack[-6];
    goto v_25058;
v_25059:
    v_25113 = nil;
    v_25114 = ncons(v_25113);
    env = stack[-8];
    goto v_25060;
v_25061:
    v_25113 = stack[-5];
    goto v_25062;
v_25063:
    goto v_25055;
v_25056:
    goto v_25057;
v_25058:
    goto v_25059;
v_25060:
    goto v_25061;
v_25062:
    fn = elt(env, 6); // mcharg2
    v_25113 = (*qfnn(fn))(fn, 4, stack[-1], stack[0], v_25114, v_25113);
    env = stack[-8];
    stack[-4] = v_25113;
    v_25113 = stack[-4];
    fn = elt(env, 7); // lastpair
    v_25113 = (*qfn1(fn))(fn, v_25113);
    env = stack[-8];
    stack[-3] = v_25113;
    v_25113 = stack[-7];
    v_25113 = qcdr(v_25113);
    stack[-7] = v_25113;
    v_25113 = stack[-3];
    if (!consp(v_25113)) goto v_25075;
    else goto v_25076;
v_25075:
    goto v_25041;
v_25076:
v_25042:
    v_25113 = stack[-7];
    if (v_25113 == nil) goto v_25080;
    else goto v_25081;
v_25080:
    v_25113 = stack[-4];
    goto v_25040;
v_25081:
    goto v_25089;
v_25085:
    stack[-2] = stack[-3];
    goto v_25086;
v_25087:
    v_25113 = stack[-7];
    v_25113 = qcar(v_25113);
    goto v_25103;
v_25095:
    stack[-1] = v_25113;
    goto v_25096;
v_25097:
    stack[0] = stack[-6];
    goto v_25098;
v_25099:
    v_25113 = nil;
    v_25114 = ncons(v_25113);
    env = stack[-8];
    goto v_25100;
v_25101:
    v_25113 = stack[-5];
    goto v_25102;
v_25103:
    goto v_25095;
v_25096:
    goto v_25097;
v_25098:
    goto v_25099;
v_25100:
    goto v_25101;
v_25102:
    fn = elt(env, 6); // mcharg2
    v_25113 = (*qfnn(fn))(fn, 4, stack[-1], stack[0], v_25114, v_25113);
    env = stack[-8];
    goto v_25088;
v_25089:
    goto v_25085;
v_25086:
    goto v_25087;
v_25088:
    v_25113 = Lrplacd(nil, stack[-2], v_25113);
    env = stack[-8];
    v_25113 = stack[-3];
    fn = elt(env, 7); // lastpair
    v_25113 = (*qfn1(fn))(fn, v_25113);
    env = stack[-8];
    stack[-3] = v_25113;
    v_25113 = stack[-7];
    v_25113 = qcdr(v_25113);
    stack[-7] = v_25113;
    goto v_25042;
v_25040:
    goto v_24956;
    v_25113 = nil;
v_24956:
    {
        fn = elt(env, 8); // reversip!*
        return (*qfn1(fn))(fn, v_25113);
    }
}



// Code for gcdlist

static LispObject CC_gcdlist(LispObject env,
                         LispObject v_24950)
{
    env = qenv(env);
    LispObject v_25597, v_25598, v_25599;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_24950);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_24950);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(15);
// copy arguments values to proper place
    stack[0] = v_24950;
// end of prologue
    v_25597 = stack[0];
    if (v_25597 == nil) goto v_24954;
    else goto v_24955;
v_24954:
    v_25597 = nil;
    goto v_24953;
v_24955:
    v_25597 = stack[0];
    v_25597 = qcdr(v_25597);
    if (v_25597 == nil) goto v_24958;
    else goto v_24959;
v_24958:
    v_25597 = stack[0];
    v_25597 = qcar(v_25597);
    {
        fn = elt(env, 2); // poly!-abs
        return (*qfn1(fn))(fn, v_25597);
    }
v_24959:
    v_25597 = stack[0];
    v_25597 = qcar(v_25597);
    if (!consp(v_25597)) goto v_24969;
    else goto v_24970;
v_24969:
    v_25597 = lisp_true;
    goto v_24968;
v_24970:
    v_25597 = stack[0];
    v_25597 = qcar(v_25597);
    v_25597 = qcar(v_25597);
    v_25597 = (consp(v_25597) ? nil : lisp_true);
    goto v_24968;
    v_25597 = nil;
v_24968:
    if (v_25597 == nil) goto v_24966;
    goto v_24985;
v_24981:
    v_25597 = stack[0];
    v_25598 = qcdr(v_25597);
    goto v_24982;
v_24983:
    v_25597 = stack[0];
    v_25597 = qcar(v_25597);
    goto v_24984;
v_24985:
    goto v_24981;
v_24982:
    goto v_24983;
v_24984:
    {
        fn = elt(env, 3); // gcdld
        return (*qfn2(fn))(fn, v_25598, v_25597);
    }
v_24966:
    stack[-1] = nil;
v_24999:
    v_25597 = stack[0];
    if (v_25597 == nil) goto v_25002;
    else goto v_25003;
v_25002:
    goto v_24998;
v_25003:
    v_25597 = stack[0];
    v_25597 = qcar(v_25597);
    if (v_25597 == nil) goto v_25008;
    else goto v_25009;
v_25008:
    v_25597 = stack[0];
    v_25597 = qcdr(v_25597);
    stack[0] = v_25597;
    goto v_25007;
v_25009:
    v_25597 = stack[0];
    v_25597 = qcar(v_25597);
    if (!consp(v_25597)) goto v_25018;
    else goto v_25019;
v_25018:
    v_25597 = lisp_true;
    goto v_25017;
v_25019:
    v_25597 = stack[0];
    v_25597 = qcar(v_25597);
    v_25597 = qcar(v_25597);
    v_25597 = (consp(v_25597) ? nil : lisp_true);
    goto v_25017;
    v_25597 = nil;
v_25017:
    if (v_25597 == nil) goto v_25015;
    goto v_25036;
v_25032:
    v_25597 = stack[0];
    stack[-2] = qcdr(v_25597);
    goto v_25033;
v_25034:
    goto v_25044;
v_25040:
    v_25597 = stack[-1];
    fn = elt(env, 4); // mapcarcar
    v_25598 = (*qfn1(fn))(fn, v_25597);
    env = stack[-14];
    goto v_25041;
v_25042:
    v_25597 = stack[0];
    v_25597 = qcar(v_25597);
    goto v_25043;
v_25044:
    goto v_25040;
v_25041:
    goto v_25042;
v_25043:
    fn = elt(env, 3); // gcdld
    v_25597 = (*qfn2(fn))(fn, v_25598, v_25597);
    env = stack[-14];
    goto v_25035;
v_25036:
    goto v_25032;
v_25033:
    goto v_25034;
v_25035:
    fn = elt(env, 3); // gcdld
    v_25597 = (*qfn2(fn))(fn, stack[-2], v_25597);
    env = stack[-14];
    v_25597 = ncons(v_25597);
    env = stack[-14];
    v_25597 = ncons(v_25597);
    env = stack[-14];
    stack[-1] = v_25597;
    v_25597 = nil;
    stack[0] = v_25597;
    goto v_25007;
v_25015:
    goto v_25059;
v_25053:
    v_25597 = stack[0];
    stack[-2] = qcar(v_25597);
    goto v_25054;
v_25055:
    v_25597 = stack[0];
    v_25597 = qcar(v_25597);
    fn = elt(env, 5); // powers1
    v_25598 = (*qfn1(fn))(fn, v_25597);
    env = stack[-14];
    goto v_25056;
v_25057:
    v_25597 = stack[-1];
    goto v_25058;
v_25059:
    goto v_25053;
v_25054:
    goto v_25055;
v_25056:
    goto v_25057;
v_25058:
    v_25597 = acons(stack[-2], v_25598, v_25597);
    env = stack[-14];
    stack[-1] = v_25597;
    v_25597 = stack[0];
    v_25597 = qcdr(v_25597);
    stack[0] = v_25597;
    goto v_25007;
v_25007:
    goto v_24999;
v_24998:
    v_25597 = stack[-1];
    if (v_25597 == nil) goto v_25070;
    else goto v_25071;
v_25070:
    v_25597 = nil;
    goto v_24996;
v_25071:
    v_25597 = stack[-1];
    v_25597 = qcdr(v_25597);
    if (v_25597 == nil) goto v_25074;
    else goto v_25075;
v_25074:
    v_25597 = stack[-1];
    v_25597 = qcar(v_25597);
    v_25597 = qcar(v_25597);
    {
        fn = elt(env, 2); // poly!-abs
        return (*qfn1(fn))(fn, v_25597);
    }
v_25075:
    v_25597 = nil;
    stack[-13] = v_25597;
    v_25597 = nil;
    stack[-12] = v_25597;
    v_25597 = stack[-1];
    stack[-11] = v_25597;
    v_25597 = stack[-11];
    if (v_25597 == nil) goto v_25093;
    else goto v_25094;
v_25093:
    v_25597 = nil;
    goto v_25088;
v_25094:
    v_25597 = stack[-11];
    v_25597 = qcar(v_25597);
    stack[-7] = v_25597;
    stack[-6] = nil;
    v_25597 = stack[-7];
    v_25597 = qcdr(v_25597);
    stack[-5] = v_25597;
    v_25597 = stack[-5];
    if (v_25597 == nil) goto v_25116;
    else goto v_25117;
v_25116:
    v_25597 = nil;
    goto v_25110;
v_25117:
    v_25597 = stack[-5];
    v_25597 = qcar(v_25597);
    stack[-1] = v_25597;
    goto v_25131;
v_25125:
    v_25597 = stack[-1];
    v_25599 = qcar(v_25597);
    goto v_25126;
v_25127:
    v_25597 = stack[-1];
    v_25597 = qcdr(v_25597);
    v_25598 = qcdr(v_25597);
    goto v_25128;
v_25129:
    v_25597 = stack[-6];
    goto v_25130;
v_25131:
    goto v_25125;
v_25126:
    goto v_25127;
v_25128:
    goto v_25129;
v_25130:
    v_25597 = acons(v_25599, v_25598, v_25597);
    env = stack[-14];
    stack[-6] = v_25597;
    goto v_25143;
v_25139:
    v_25597 = stack[-1];
    stack[0] = qcar(v_25597);
    goto v_25140;
v_25141:
    goto v_25151;
v_25147:
    v_25597 = stack[-1];
    v_25597 = qcdr(v_25597);
    v_25598 = qcar(v_25597);
    goto v_25148;
v_25149:
    v_25597 = stack[-1];
    v_25597 = qcdr(v_25597);
    v_25597 = qcdr(v_25597);
    goto v_25150;
v_25151:
    goto v_25147;
v_25148:
    goto v_25149;
v_25150:
    v_25597 = difference2(v_25598, v_25597);
    env = stack[-14];
    goto v_25142;
v_25143:
    goto v_25139;
v_25140:
    goto v_25141;
v_25142:
    v_25597 = cons(stack[0], v_25597);
    env = stack[-14];
    v_25597 = ncons(v_25597);
    env = stack[-14];
    stack[-3] = v_25597;
    stack[-4] = v_25597;
v_25111:
    v_25597 = stack[-5];
    v_25597 = qcdr(v_25597);
    stack[-5] = v_25597;
    v_25597 = stack[-5];
    if (v_25597 == nil) goto v_25162;
    else goto v_25163;
v_25162:
    v_25597 = stack[-4];
    goto v_25110;
v_25163:
    goto v_25171;
v_25167:
    stack[-2] = stack[-3];
    goto v_25168;
v_25169:
    v_25597 = stack[-5];
    v_25597 = qcar(v_25597);
    stack[-1] = v_25597;
    goto v_25184;
v_25178:
    v_25597 = stack[-1];
    v_25599 = qcar(v_25597);
    goto v_25179;
v_25180:
    v_25597 = stack[-1];
    v_25597 = qcdr(v_25597);
    v_25598 = qcdr(v_25597);
    goto v_25181;
v_25182:
    v_25597 = stack[-6];
    goto v_25183;
v_25184:
    goto v_25178;
v_25179:
    goto v_25180;
v_25181:
    goto v_25182;
v_25183:
    v_25597 = acons(v_25599, v_25598, v_25597);
    env = stack[-14];
    stack[-6] = v_25597;
    goto v_25196;
v_25192:
    v_25597 = stack[-1];
    stack[0] = qcar(v_25597);
    goto v_25193;
v_25194:
    goto v_25204;
v_25200:
    v_25597 = stack[-1];
    v_25597 = qcdr(v_25597);
    v_25598 = qcar(v_25597);
    goto v_25201;
v_25202:
    v_25597 = stack[-1];
    v_25597 = qcdr(v_25597);
    v_25597 = qcdr(v_25597);
    goto v_25203;
v_25204:
    goto v_25200;
v_25201:
    goto v_25202;
v_25203:
    v_25597 = difference2(v_25598, v_25597);
    env = stack[-14];
    goto v_25195;
v_25196:
    goto v_25192;
v_25193:
    goto v_25194;
v_25195:
    v_25597 = cons(stack[0], v_25597);
    env = stack[-14];
    v_25597 = ncons(v_25597);
    env = stack[-14];
    goto v_25170;
v_25171:
    goto v_25167;
v_25168:
    goto v_25169;
v_25170:
    v_25597 = Lrplacd(nil, stack[-2], v_25597);
    env = stack[-14];
    v_25597 = stack[-3];
    v_25597 = qcdr(v_25597);
    stack[-3] = v_25597;
    goto v_25111;
v_25110:
    stack[0] = v_25597;
    v_25597 = stack[-7];
    v_25597 = qcar(v_25597);
    fn = elt(env, 6); // numeric!-content
    v_25597 = (*qfn1(fn))(fn, v_25597);
    env = stack[-14];
    stack[-1] = v_25597;
    v_25597 = stack[-12];
    if (v_25597 == nil) goto v_25218;
    else goto v_25219;
v_25218:
    v_25597 = stack[-6];
    stack[-13] = v_25597;
    v_25597 = stack[-1];
    stack[-12] = v_25597;
    goto v_25217;
v_25219:
    goto v_25230;
v_25226:
    v_25598 = stack[-13];
    goto v_25227;
v_25228:
    v_25597 = stack[-6];
    goto v_25229;
v_25230:
    goto v_25226;
v_25227:
    goto v_25228;
v_25229:
    fn = elt(env, 7); // vintersection
    v_25597 = (*qfn2(fn))(fn, v_25598, v_25597);
    env = stack[-14];
    stack[-13] = v_25597;
    goto v_25238;
v_25234:
    v_25598 = stack[-12];
    goto v_25235;
v_25236:
    v_25597 = stack[-1];
    goto v_25237;
v_25238:
    goto v_25234;
v_25235:
    goto v_25236;
v_25237:
    fn = elt(env, 8); // gcddd
    v_25597 = (*qfn2(fn))(fn, v_25598, v_25597);
    env = stack[-14];
    stack[-12] = v_25597;
    goto v_25217;
v_25217:
    v_25597 = stack[-6];
    stack[-2] = v_25597;
v_25244:
    v_25597 = stack[-2];
    if (v_25597 == nil) goto v_25248;
    else goto v_25249;
v_25248:
    goto v_25243;
v_25249:
    v_25597 = stack[-2];
    v_25597 = qcar(v_25597);
    v_25599 = v_25597;
    goto v_25263;
v_25259:
    v_25597 = v_25599;
    v_25598 = qcdr(v_25597);
    goto v_25260;
v_25261:
    v_25597 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25262;
v_25263:
    goto v_25259;
v_25260:
    goto v_25261;
v_25262:
    if (v_25598 == v_25597) goto v_25258;
    goto v_25272;
v_25268:
    goto v_25269;
v_25270:
    goto v_25280;
v_25276:
    goto v_25286;
v_25282:
    v_25597 = v_25599;
    v_25597 = qcar(v_25597);
    goto v_25283;
v_25284:
    v_25598 = v_25599;
    v_25598 = qcdr(v_25598);
    goto v_25285;
v_25286:
    goto v_25282;
v_25283:
    goto v_25284;
v_25285:
    fn = elt(env, 9); // mksp
    v_25598 = (*qfn2(fn))(fn, v_25597, v_25598);
    env = stack[-14];
    goto v_25277;
v_25278:
    v_25597 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25279;
v_25280:
    goto v_25276;
v_25277:
    goto v_25278;
v_25279:
    v_25597 = cons(v_25598, v_25597);
    env = stack[-14];
    v_25597 = ncons(v_25597);
    env = stack[-14];
    goto v_25271;
v_25272:
    goto v_25268;
v_25269:
    goto v_25270;
v_25271:
    fn = elt(env, 10); // multf
    v_25597 = (*qfn2(fn))(fn, stack[-1], v_25597);
    env = stack[-14];
    stack[-1] = v_25597;
    goto v_25256;
v_25258:
v_25256:
    v_25597 = stack[-2];
    v_25597 = qcdr(v_25597);
    stack[-2] = v_25597;
    goto v_25244;
v_25243:
    goto v_25299;
v_25295:
    goto v_25307;
v_25301:
    v_25597 = stack[-7];
    v_25599 = qcar(v_25597);
    goto v_25302;
v_25303:
    v_25598 = stack[-1];
    goto v_25304;
v_25305:
    v_25597 = elt(env, 1); // "Term content division failed"
    goto v_25306;
v_25307:
    goto v_25301;
v_25302:
    goto v_25303;
v_25304:
    goto v_25305;
v_25306:
    fn = elt(env, 11); // quotfail1
    v_25598 = (*qfnn(fn))(fn, 3, v_25599, v_25598, v_25597);
    env = stack[-14];
    goto v_25296;
v_25297:
    v_25597 = stack[0];
    goto v_25298;
v_25299:
    goto v_25295;
v_25296:
    goto v_25297;
v_25298:
    v_25597 = cons(v_25598, v_25597);
    env = stack[-14];
    v_25597 = ncons(v_25597);
    env = stack[-14];
    stack[-9] = v_25597;
    stack[-10] = v_25597;
v_25089:
    v_25597 = stack[-11];
    v_25597 = qcdr(v_25597);
    stack[-11] = v_25597;
    v_25597 = stack[-11];
    if (v_25597 == nil) goto v_25317;
    else goto v_25318;
v_25317:
    v_25597 = stack[-10];
    goto v_25088;
v_25318:
    goto v_25326;
v_25322:
    stack[-8] = stack[-9];
    goto v_25323;
v_25324:
    v_25597 = stack[-11];
    v_25597 = qcar(v_25597);
    stack[-7] = v_25597;
    stack[-6] = nil;
    v_25597 = stack[-7];
    v_25597 = qcdr(v_25597);
    stack[-5] = v_25597;
    v_25597 = stack[-5];
    if (v_25597 == nil) goto v_25347;
    else goto v_25348;
v_25347:
    v_25597 = nil;
    goto v_25341;
v_25348:
    v_25597 = stack[-5];
    v_25597 = qcar(v_25597);
    stack[-1] = v_25597;
    goto v_25362;
v_25356:
    v_25597 = stack[-1];
    v_25599 = qcar(v_25597);
    goto v_25357;
v_25358:
    v_25597 = stack[-1];
    v_25597 = qcdr(v_25597);
    v_25598 = qcdr(v_25597);
    goto v_25359;
v_25360:
    v_25597 = stack[-6];
    goto v_25361;
v_25362:
    goto v_25356;
v_25357:
    goto v_25358;
v_25359:
    goto v_25360;
v_25361:
    v_25597 = acons(v_25599, v_25598, v_25597);
    env = stack[-14];
    stack[-6] = v_25597;
    goto v_25374;
v_25370:
    v_25597 = stack[-1];
    stack[0] = qcar(v_25597);
    goto v_25371;
v_25372:
    goto v_25382;
v_25378:
    v_25597 = stack[-1];
    v_25597 = qcdr(v_25597);
    v_25598 = qcar(v_25597);
    goto v_25379;
v_25380:
    v_25597 = stack[-1];
    v_25597 = qcdr(v_25597);
    v_25597 = qcdr(v_25597);
    goto v_25381;
v_25382:
    goto v_25378;
v_25379:
    goto v_25380;
v_25381:
    v_25597 = difference2(v_25598, v_25597);
    env = stack[-14];
    goto v_25373;
v_25374:
    goto v_25370;
v_25371:
    goto v_25372;
v_25373:
    v_25597 = cons(stack[0], v_25597);
    env = stack[-14];
    v_25597 = ncons(v_25597);
    env = stack[-14];
    stack[-3] = v_25597;
    stack[-4] = v_25597;
v_25342:
    v_25597 = stack[-5];
    v_25597 = qcdr(v_25597);
    stack[-5] = v_25597;
    v_25597 = stack[-5];
    if (v_25597 == nil) goto v_25393;
    else goto v_25394;
v_25393:
    v_25597 = stack[-4];
    goto v_25341;
v_25394:
    goto v_25402;
v_25398:
    stack[-2] = stack[-3];
    goto v_25399;
v_25400:
    v_25597 = stack[-5];
    v_25597 = qcar(v_25597);
    stack[-1] = v_25597;
    goto v_25415;
v_25409:
    v_25597 = stack[-1];
    v_25599 = qcar(v_25597);
    goto v_25410;
v_25411:
    v_25597 = stack[-1];
    v_25597 = qcdr(v_25597);
    v_25598 = qcdr(v_25597);
    goto v_25412;
v_25413:
    v_25597 = stack[-6];
    goto v_25414;
v_25415:
    goto v_25409;
v_25410:
    goto v_25411;
v_25412:
    goto v_25413;
v_25414:
    v_25597 = acons(v_25599, v_25598, v_25597);
    env = stack[-14];
    stack[-6] = v_25597;
    goto v_25427;
v_25423:
    v_25597 = stack[-1];
    stack[0] = qcar(v_25597);
    goto v_25424;
v_25425:
    goto v_25435;
v_25431:
    v_25597 = stack[-1];
    v_25597 = qcdr(v_25597);
    v_25598 = qcar(v_25597);
    goto v_25432;
v_25433:
    v_25597 = stack[-1];
    v_25597 = qcdr(v_25597);
    v_25597 = qcdr(v_25597);
    goto v_25434;
v_25435:
    goto v_25431;
v_25432:
    goto v_25433;
v_25434:
    v_25597 = difference2(v_25598, v_25597);
    env = stack[-14];
    goto v_25426;
v_25427:
    goto v_25423;
v_25424:
    goto v_25425;
v_25426:
    v_25597 = cons(stack[0], v_25597);
    env = stack[-14];
    v_25597 = ncons(v_25597);
    env = stack[-14];
    goto v_25401;
v_25402:
    goto v_25398;
v_25399:
    goto v_25400;
v_25401:
    v_25597 = Lrplacd(nil, stack[-2], v_25597);
    env = stack[-14];
    v_25597 = stack[-3];
    v_25597 = qcdr(v_25597);
    stack[-3] = v_25597;
    goto v_25342;
v_25341:
    stack[0] = v_25597;
    v_25597 = stack[-7];
    v_25597 = qcar(v_25597);
    fn = elt(env, 6); // numeric!-content
    v_25597 = (*qfn1(fn))(fn, v_25597);
    env = stack[-14];
    stack[-1] = v_25597;
    v_25597 = stack[-12];
    if (v_25597 == nil) goto v_25449;
    else goto v_25450;
v_25449:
    v_25597 = stack[-6];
    stack[-13] = v_25597;
    v_25597 = stack[-1];
    stack[-12] = v_25597;
    goto v_25448;
v_25450:
    goto v_25461;
v_25457:
    v_25598 = stack[-13];
    goto v_25458;
v_25459:
    v_25597 = stack[-6];
    goto v_25460;
v_25461:
    goto v_25457;
v_25458:
    goto v_25459;
v_25460:
    fn = elt(env, 7); // vintersection
    v_25597 = (*qfn2(fn))(fn, v_25598, v_25597);
    env = stack[-14];
    stack[-13] = v_25597;
    goto v_25469;
v_25465:
    v_25598 = stack[-12];
    goto v_25466;
v_25467:
    v_25597 = stack[-1];
    goto v_25468;
v_25469:
    goto v_25465;
v_25466:
    goto v_25467;
v_25468:
    fn = elt(env, 8); // gcddd
    v_25597 = (*qfn2(fn))(fn, v_25598, v_25597);
    env = stack[-14];
    stack[-12] = v_25597;
    goto v_25448;
v_25448:
    v_25597 = stack[-6];
    stack[-2] = v_25597;
v_25475:
    v_25597 = stack[-2];
    if (v_25597 == nil) goto v_25479;
    else goto v_25480;
v_25479:
    goto v_25474;
v_25480:
    v_25597 = stack[-2];
    v_25597 = qcar(v_25597);
    v_25599 = v_25597;
    goto v_25494;
v_25490:
    v_25597 = v_25599;
    v_25598 = qcdr(v_25597);
    goto v_25491;
v_25492:
    v_25597 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25493;
v_25494:
    goto v_25490;
v_25491:
    goto v_25492;
v_25493:
    if (v_25598 == v_25597) goto v_25489;
    goto v_25503;
v_25499:
    goto v_25500;
v_25501:
    goto v_25511;
v_25507:
    goto v_25517;
v_25513:
    v_25597 = v_25599;
    v_25597 = qcar(v_25597);
    goto v_25514;
v_25515:
    v_25598 = v_25599;
    v_25598 = qcdr(v_25598);
    goto v_25516;
v_25517:
    goto v_25513;
v_25514:
    goto v_25515;
v_25516:
    fn = elt(env, 9); // mksp
    v_25598 = (*qfn2(fn))(fn, v_25597, v_25598);
    env = stack[-14];
    goto v_25508;
v_25509:
    v_25597 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25510;
v_25511:
    goto v_25507;
v_25508:
    goto v_25509;
v_25510:
    v_25597 = cons(v_25598, v_25597);
    env = stack[-14];
    v_25597 = ncons(v_25597);
    env = stack[-14];
    goto v_25502;
v_25503:
    goto v_25499;
v_25500:
    goto v_25501;
v_25502:
    fn = elt(env, 10); // multf
    v_25597 = (*qfn2(fn))(fn, stack[-1], v_25597);
    env = stack[-14];
    stack[-1] = v_25597;
    goto v_25487;
v_25489:
v_25487:
    v_25597 = stack[-2];
    v_25597 = qcdr(v_25597);
    stack[-2] = v_25597;
    goto v_25475;
v_25474:
    goto v_25530;
v_25526:
    goto v_25538;
v_25532:
    v_25597 = stack[-7];
    v_25599 = qcar(v_25597);
    goto v_25533;
v_25534:
    v_25598 = stack[-1];
    goto v_25535;
v_25536:
    v_25597 = elt(env, 1); // "Term content division failed"
    goto v_25537;
v_25538:
    goto v_25532;
v_25533:
    goto v_25534;
v_25535:
    goto v_25536;
v_25537:
    fn = elt(env, 11); // quotfail1
    v_25598 = (*qfnn(fn))(fn, 3, v_25599, v_25598, v_25597);
    env = stack[-14];
    goto v_25527;
v_25528:
    v_25597 = stack[0];
    goto v_25529;
v_25530:
    goto v_25526;
v_25527:
    goto v_25528;
v_25529:
    v_25597 = cons(v_25598, v_25597);
    env = stack[-14];
    v_25597 = ncons(v_25597);
    env = stack[-14];
    goto v_25325;
v_25326:
    goto v_25322;
v_25323:
    goto v_25324;
v_25325:
    v_25597 = Lrplacd(nil, stack[-8], v_25597);
    env = stack[-14];
    v_25597 = stack[-9];
    v_25597 = qcdr(v_25597);
    stack[-9] = v_25597;
    goto v_25089;
v_25088:
    stack[0] = v_25597;
    v_25597 = stack[-13];
    stack[-1] = v_25597;
v_25549:
    v_25597 = stack[-1];
    if (v_25597 == nil) goto v_25553;
    else goto v_25554;
v_25553:
    goto v_25548;
v_25554:
    v_25597 = stack[-1];
    v_25597 = qcar(v_25597);
    goto v_25565;
v_25561:
    stack[-2] = stack[-12];
    goto v_25562;
v_25563:
    goto v_25573;
v_25569:
    goto v_25579;
v_25575:
    v_25598 = v_25597;
    v_25598 = qcar(v_25598);
    goto v_25576;
v_25577:
    v_25597 = qcdr(v_25597);
    goto v_25578;
v_25579:
    goto v_25575;
v_25576:
    goto v_25577;
v_25578:
    fn = elt(env, 9); // mksp
    v_25598 = (*qfn2(fn))(fn, v_25598, v_25597);
    env = stack[-14];
    goto v_25570;
v_25571:
    v_25597 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25572;
v_25573:
    goto v_25569;
v_25570:
    goto v_25571;
v_25572:
    v_25597 = cons(v_25598, v_25597);
    env = stack[-14];
    v_25597 = ncons(v_25597);
    env = stack[-14];
    goto v_25564;
v_25565:
    goto v_25561;
v_25562:
    goto v_25563;
v_25564:
    fn = elt(env, 10); // multf
    v_25597 = (*qfn2(fn))(fn, stack[-2], v_25597);
    env = stack[-14];
    stack[-12] = v_25597;
    v_25597 = stack[-1];
    v_25597 = qcdr(v_25597);
    stack[-1] = v_25597;
    goto v_25549;
v_25548:
    goto v_25593;
v_25589:
    stack[-1] = stack[-12];
    goto v_25590;
v_25591:
    v_25597 = stack[0];
    fn = elt(env, 12); // gcdlist1
    v_25597 = (*qfn1(fn))(fn, v_25597);
    env = stack[-14];
    goto v_25592;
v_25593:
    goto v_25589;
v_25590:
    goto v_25591;
v_25592:
    fn = elt(env, 10); // multf
    v_25597 = (*qfn2(fn))(fn, stack[-1], v_25597);
    env = stack[-14];
    {
        fn = elt(env, 2); // poly!-abs
        return (*qfn1(fn))(fn, v_25597);
    }
v_24996:
    goto v_24953;
    v_25597 = nil;
v_24953:
    return onevalue(v_25597);
}



setup_type const u44_setup[] =
{
    {"lieninstruc",             CC_lieninstruc, TOO_MANY_1,    WRONG_NO_1},
    {"appr",                    TOO_FEW_2,      CC_appr,       WRONG_NO_2},
    {"fctargs",                 CC_fctargs,     TOO_MANY_1,    WRONG_NO_1},
    {"cgp_greenp",              CC_cgp_greenp,  TOO_MANY_1,    WRONG_NO_1},
    {"integralir",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_integralir},
    {"simpu",                   CC_simpu,       TOO_MANY_1,    WRONG_NO_1},
    {"dip2a",                   CC_dip2a,       TOO_MANY_1,    WRONG_NO_1},
    {"mkexdf",                  CC_mkexdf,      TOO_MANY_1,    WRONG_NO_1},
    {"markedvarp",              CC_markedvarp,  TOO_MANY_1,    WRONG_NO_1},
    {"ev-edgeloop",             TOO_FEW_2,      CC_evKedgeloop,WRONG_NO_2},
    {"prepsq*0",                TOO_FEW_2,      CC_prepsqH0,   WRONG_NO_2},
    {"super_vectorfield",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_super_vectorfield},
    {"co_hfn",                  CC_co_hfn,      TOO_MANY_1,    WRONG_NO_1},
    {"rtypepart",               CC_rtypepart,   TOO_MANY_1,    WRONG_NO_1},
    {"expf",                    TOO_FEW_2,      CC_expf,       WRONG_NO_2},
    {"change+int+to+sq",        CC_changeLintLtoLsq,TOO_MANY_1,WRONG_NO_1},
    {"freeof-dfl",              TOO_FEW_2,      CC_freeofKdfl, WRONG_NO_2},
    {"pasf_premf",              TOO_FEW_2,      CC_pasf_premf, WRONG_NO_2},
    {"pasf_coeflst",            TOO_FEW_2,      CC_pasf_coeflst,WRONG_NO_2},
    {"conditionml",             CC_conditionml, TOO_MANY_1,    WRONG_NO_1},
    {"mkexpt",                  TOO_FEW_2,      CC_mkexpt,     WRONG_NO_2},
    {"rnfix*",                  CC_rnfixH,      TOO_MANY_1,    WRONG_NO_1},
    {"evalmember",              TOO_FEW_2,      CC_evalmember, WRONG_NO_2},
    {"gpargp",                  CC_gpargp,      TOO_MANY_1,    WRONG_NO_1},
    {"indexvp",                 CC_indexvp,     TOO_MANY_1,    WRONG_NO_1},
    {"extract_vars",            CC_extract_vars,TOO_MANY_1,    WRONG_NO_1},
    {"cl_gand-col",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_gandKcol},
    {"numir",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_numir},
    {"ps:arg-values",           CC_psTargKvalues,TOO_MANY_1,   WRONG_NO_1},
    {"remdiff",                 CC_remdiff,     TOO_MANY_1,    WRONG_NO_1},
    {"e*",                      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_eH},
    {"nspaces",                 CC_nspaces,     TOO_MANY_1,    WRONG_NO_1},
    {"mk_simpl_map_",           CC_mk_simpl_map_,TOO_MANY_1,   WRONG_NO_1},
    {"mk_dummy_ids",            CC_mk_dummy_ids,TOO_MANY_1,    WRONG_NO_1},
    {"aex_unbind",              TOO_FEW_2,      CC_aex_unbind, WRONG_NO_2},
    {"createtriple",            CC_createtriple,TOO_MANY_1,    WRONG_NO_1},
    {"totalcompareconstants",   TOO_FEW_2,      CC_totalcompareconstants,WRONG_NO_2},
    {"mk+resimp+mat",           CC_mkLresimpLmat,TOO_MANY_1,   WRONG_NO_1},
    {"talp_invtscsimpl",        CC_talp_invtscsimpl,TOO_MANY_1,WRONG_NO_1},
    {"matrixml",                CC_matrixml,    TOO_MANY_1,    WRONG_NO_1},
    {"ieval",                   CC_ieval,       TOO_MANY_1,    WRONG_NO_1},
    {"diford",                  CC_diford,      TOO_MANY_1,    WRONG_NO_1},
    {"specrd:times",            TOO_FEW_2,      CC_specrdTtimes,WRONG_NO_2},
    {"letmtr",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_letmtr},
    {"remove_least_item",       CC_remove_least_item,TOO_MANY_1,WRONG_NO_1},
    {"r2oaddspecies",           TOO_FEW_2,      CC_r2oaddspecies,WRONG_NO_2},
    {"ev-poles",                TOO_FEW_2,      CC_evKpoles,   WRONG_NO_2},
    {"mv-compact2",             TOO_FEW_2,      CC_mvKcompact2,WRONG_NO_2},
    {"prepcadr",                CC_prepcadr,    TOO_MANY_1,    WRONG_NO_1},
    {"listminimize",            TOO_FEW_2,      CC_listminimize,WRONG_NO_2},
    {"general-multiply-by-constant-mod-p",TOO_FEW_2,CC_generalKmultiplyKbyKconstantKmodKp,WRONG_NO_2},
    {"mchsarg",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mchsarg},
    {"gcdlist",                 CC_gcdlist,     TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u44", (two_args *)"10709 6331635 6942801", 0}
};

// end of generated code
