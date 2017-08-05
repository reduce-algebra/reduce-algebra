
// $destdir/u33.c        Machine generated C code

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



// Code for max!-degree

static LispObject CC_maxKdegree(LispObject env,
                         LispObject v_18204, LispObject v_18205)
{
    env = qenv(env);
    LispObject v_18270, v_18271, v_18272, v_18273;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18204,v_18205);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_18271 = v_18205;
    v_18272 = v_18204;
// end of prologue
v_18210:
    v_18270 = v_18272;
    if (!consp(v_18270)) goto v_18217;
    else goto v_18218;
v_18217:
    v_18270 = lisp_true;
    goto v_18216;
v_18218:
    v_18270 = v_18272;
    v_18270 = qcar(v_18270);
    v_18270 = (consp(v_18270) ? nil : lisp_true);
    goto v_18216;
    v_18270 = nil;
v_18216:
    if (v_18270 == nil) goto v_18214;
    v_18270 = v_18271;
    goto v_18209;
v_18214:
    goto v_18233;
v_18229:
    v_18273 = v_18271;
    goto v_18230;
v_18231:
    v_18270 = v_18272;
    v_18270 = qcar(v_18270);
    v_18270 = qcar(v_18270);
    v_18270 = qcdr(v_18270);
    goto v_18232;
v_18233:
    goto v_18229;
v_18230:
    goto v_18231;
v_18232:
    if (((intptr_t)(v_18273)) > ((intptr_t)(v_18270))) goto v_18227;
    else goto v_18228;
v_18227:
    v_18270 = v_18272;
    v_18270 = qcdr(v_18270);
    stack[0] = v_18270;
    goto v_18246;
v_18242:
    v_18270 = v_18272;
    v_18270 = qcar(v_18270);
    v_18270 = qcdr(v_18270);
    goto v_18243;
v_18244:
    goto v_18245;
v_18246:
    goto v_18242;
v_18243:
    goto v_18244;
v_18245:
    v_18270 = CC_maxKdegree(elt(env, 0), v_18270, v_18271);
    env = stack[-1];
    v_18271 = v_18270;
    v_18270 = stack[0];
    v_18272 = v_18270;
    goto v_18210;
v_18228:
    v_18270 = v_18272;
    v_18270 = qcdr(v_18270);
    stack[0] = v_18270;
    goto v_18261;
v_18257:
    v_18270 = v_18272;
    v_18270 = qcar(v_18270);
    v_18270 = qcdr(v_18270);
    goto v_18258;
v_18259:
    v_18271 = v_18272;
    v_18271 = qcar(v_18271);
    v_18271 = qcar(v_18271);
    v_18271 = qcdr(v_18271);
    goto v_18260;
v_18261:
    goto v_18257;
v_18258:
    goto v_18259;
v_18260:
    v_18270 = CC_maxKdegree(elt(env, 0), v_18270, v_18271);
    env = stack[-1];
    v_18271 = v_18270;
    v_18270 = stack[0];
    v_18272 = v_18270;
    goto v_18210;
    v_18270 = nil;
v_18209:
    return onevalue(v_18270);
}



// Code for chkrn!*

static LispObject CC_chkrnH(LispObject env,
                         LispObject v_18204)
{
    env = qenv(env);
    LispObject v_18216, v_18217;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18217 = v_18204;
// end of prologue
    v_18216 = qvalue(elt(env, 1)); // !*!*roundbf
    if (v_18216 == nil) goto v_18209;
    v_18216 = v_18217;
    goto v_18207;
v_18209:
    v_18216 = v_18217;
    {
        fn = elt(env, 2); // bf2flck
        return (*qfn1(fn))(fn, v_18216);
    }
    v_18216 = nil;
v_18207:
    return onevalue(v_18216);
}



// Code for length_multiindex

static LispObject CC_length_multiindex(LispObject env,
                         LispObject v_18204)
{
    env = qenv(env);
    LispObject v_18232, v_18233;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18204);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_18232 = v_18204;
// end of prologue
    stack[0] = v_18232;
    v_18232 = (LispObject)0+TAG_FIXNUM; // 0
    v_18233 = v_18232;
v_18210:
    v_18232 = stack[0];
    if (v_18232 == nil) goto v_18215;
    else goto v_18216;
v_18215:
    v_18232 = v_18233;
    goto v_18209;
v_18216:
    goto v_18224;
v_18220:
    v_18232 = stack[0];
    v_18232 = qcar(v_18232);
    goto v_18221;
v_18222:
    goto v_18223;
v_18224:
    goto v_18220;
v_18221:
    goto v_18222;
v_18223:
    v_18232 = plus2(v_18232, v_18233);
    env = stack[-1];
    v_18233 = v_18232;
    v_18232 = stack[0];
    v_18232 = qcdr(v_18232);
    stack[0] = v_18232;
    goto v_18210;
v_18209:
    return onevalue(v_18232);
}



// Code for aex_stchsgnch1

static LispObject CC_aex_stchsgnch1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18271, v_18272, v_18273;
    LispObject fn;
    LispObject v_18206, v_18205, v_18204;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "aex_stchsgnch1");
    va_start(aa, nargs);
    v_18204 = va_arg(aa, LispObject);
    v_18205 = va_arg(aa, LispObject);
    v_18206 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18206,v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18204,v_18205,v_18206);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_18206;
    stack[-4] = v_18205;
    v_18271 = v_18204;
// end of prologue
    stack[-5] = v_18271;
    v_18271 = stack[-5];
    if (v_18271 == nil) goto v_18218;
    else goto v_18219;
v_18218:
    v_18271 = nil;
    goto v_18213;
v_18219:
    v_18271 = stack[-5];
    v_18271 = qcar(v_18271);
    goto v_18234;
v_18228:
    v_18273 = v_18271;
    goto v_18229;
v_18230:
    v_18272 = stack[-4];
    goto v_18231;
v_18232:
    v_18271 = stack[-3];
    goto v_18233;
v_18234:
    goto v_18228;
v_18229:
    goto v_18230;
v_18231:
    goto v_18232;
v_18233:
    fn = elt(env, 1); // aex_subrat1
    v_18271 = (*qfnn(fn))(fn, 3, v_18273, v_18272, v_18271);
    env = stack[-6];
    fn = elt(env, 2); // aex_sgn
    v_18271 = (*qfn1(fn))(fn, v_18271);
    env = stack[-6];
    v_18271 = ncons(v_18271);
    env = stack[-6];
    stack[-1] = v_18271;
    stack[-2] = v_18271;
v_18214:
    v_18271 = stack[-5];
    v_18271 = qcdr(v_18271);
    stack[-5] = v_18271;
    v_18271 = stack[-5];
    if (v_18271 == nil) goto v_18242;
    else goto v_18243;
v_18242:
    v_18271 = stack[-2];
    goto v_18213;
v_18243:
    goto v_18251;
v_18247:
    stack[0] = stack[-1];
    goto v_18248;
v_18249:
    v_18271 = stack[-5];
    v_18271 = qcar(v_18271);
    goto v_18265;
v_18259:
    v_18273 = v_18271;
    goto v_18260;
v_18261:
    v_18272 = stack[-4];
    goto v_18262;
v_18263:
    v_18271 = stack[-3];
    goto v_18264;
v_18265:
    goto v_18259;
v_18260:
    goto v_18261;
v_18262:
    goto v_18263;
v_18264:
    fn = elt(env, 1); // aex_subrat1
    v_18271 = (*qfnn(fn))(fn, 3, v_18273, v_18272, v_18271);
    env = stack[-6];
    fn = elt(env, 2); // aex_sgn
    v_18271 = (*qfn1(fn))(fn, v_18271);
    env = stack[-6];
    v_18271 = ncons(v_18271);
    env = stack[-6];
    goto v_18250;
v_18251:
    goto v_18247;
v_18248:
    goto v_18249;
v_18250:
    v_18271 = Lrplacd(nil, stack[0], v_18271);
    env = stack[-6];
    v_18271 = stack[-1];
    v_18271 = qcdr(v_18271);
    stack[-1] = v_18271;
    goto v_18214;
v_18213:
    {
        fn = elt(env, 3); // lto_sgnchg
        return (*qfn1(fn))(fn, v_18271);
    }
}



// Code for in_list1a

static LispObject CC_in_list1a(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18501, v_18502, v_18503;
    LispObject fn;
    LispObject v_18206, v_18205, v_18204;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "in_list1a");
    va_start(aa, nargs);
    v_18204 = va_arg(aa, LispObject);
    v_18205 = va_arg(aa, LispObject);
    v_18206 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18206,v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18204,v_18205,v_18206);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_18206;
    stack[-3] = v_18205;
    stack[-4] = v_18204;
// end of prologue
    stack[0] = nil;
    v_18501 = qvalue(elt(env, 1)); // !*echo
    stack[-5] = v_18501;
    v_18501 = qvalue(elt(env, 2)); // !*reduce4
    if (v_18501 == nil) goto v_18220;
    goto v_18230;
v_18226:
    v_18501 = stack[-4];
    fn = elt(env, 17); // type
    v_18502 = (*qfn1(fn))(fn, v_18501);
    env = stack[-6];
    goto v_18227;
v_18228:
    v_18501 = elt(env, 3); // string
    goto v_18229;
v_18230:
    goto v_18226;
v_18227:
    goto v_18228;
v_18229:
    if (v_18502 == v_18501) goto v_18225;
    goto v_18239;
v_18235:
    v_18502 = stack[-4];
    goto v_18236;
v_18237:
    v_18501 = elt(env, 3); // string
    goto v_18238;
v_18239:
    goto v_18235;
v_18236:
    goto v_18237;
v_18238:
    fn = elt(env, 18); // typerr
    v_18501 = (*qfn2(fn))(fn, v_18502, v_18501);
    env = stack[-6];
    goto v_18223;
v_18225:
    v_18501 = stack[-4];
    fn = elt(env, 19); // value
    v_18501 = (*qfn1(fn))(fn, v_18501);
    env = stack[-6];
    stack[-4] = v_18501;
    goto v_18223;
v_18223:
    goto v_18218;
v_18220:
v_18218:
    v_18501 = stack[-4];
    fn = elt(env, 20); // mkfil!*
    v_18501 = (*qfn1(fn))(fn, v_18501);
    env = stack[-6];
    stack[-4] = v_18501;
    v_18501 = stack[-4];
    v_18501 = Lexplodec(nil, v_18501);
    env = stack[-6];
    stack[-1] = v_18501;
    goto v_18259;
v_18255:
    v_18502 = stack[-1];
    goto v_18256;
v_18257:
    v_18501 = elt(env, 4); // !|
    goto v_18258;
v_18259:
    goto v_18255;
v_18256:
    goto v_18257;
v_18258:
    if (!consp(v_18502)) goto v_18253;
    v_18502 = qcar(v_18502);
    if (v_18502 == v_18501) goto v_18252;
    else goto v_18253;
v_18252:
    v_18501 = lisp_true;
    stack[0] = v_18501;
    v_18501 = stack[-1];
    v_18501 = qcdr(v_18501);
    fn = elt(env, 21); // list2string
    v_18501 = (*qfn1(fn))(fn, v_18501);
    env = stack[-6];
    stack[-4] = v_18501;
    goto v_18251;
v_18253:
    goto v_18277;
v_18273:
    v_18502 = stack[-1];
    goto v_18274;
v_18275:
    v_18501 = elt(env, 5); // !$
    goto v_18276;
v_18277:
    goto v_18273;
v_18274:
    goto v_18275;
v_18276:
    if (!consp(v_18502)) goto v_18271;
    v_18502 = qcar(v_18502);
    if (v_18502 == v_18501) goto v_18270;
    else goto v_18271;
v_18270:
    goto v_18289;
v_18285:
    v_18501 = stack[-1];
    v_18502 = qcdr(v_18501);
    goto v_18286;
v_18287:
    v_18501 = elt(env, 6); // !/
    goto v_18288;
v_18289:
    goto v_18285;
v_18286:
    goto v_18287;
v_18288:
    if (!consp(v_18502)) goto v_18283;
    v_18502 = qcar(v_18502);
    if (v_18502 == v_18501) goto v_18282;
    else goto v_18283;
v_18282:
    v_18501 = lisp_true;
    goto v_18281;
v_18283:
    goto v_18301;
v_18297:
    v_18501 = stack[-1];
    v_18502 = qcdr(v_18501);
    goto v_18298;
v_18299:
    v_18501 = elt(env, 7); // !\ (backslash)
    goto v_18300;
v_18301:
    goto v_18297;
v_18298:
    goto v_18299;
v_18300:
    v_18501 = Leqcar(nil, v_18502, v_18501);
    env = stack[-6];
    goto v_18281;
    v_18501 = nil;
v_18281:
    goto v_18269;
v_18271:
    v_18501 = nil;
    goto v_18269;
    v_18501 = nil;
v_18269:
    if (v_18501 == nil) goto v_18267;
    v_18501 = qvalue(elt(env, 8)); // ifl!*
    if (v_18501 == nil) goto v_18310;
    else goto v_18311;
v_18310:
    goto v_18319;
v_18315:
    v_18502 = elt(env, 9); // !.
    goto v_18316;
v_18317:
    v_18501 = stack[-1];
    v_18501 = qcdr(v_18501);
    goto v_18318;
v_18319:
    goto v_18315;
v_18316:
    goto v_18317;
v_18318:
    v_18501 = cons(v_18502, v_18501);
    env = stack[-6];
    fn = elt(env, 21); // list2string
    v_18501 = (*qfn1(fn))(fn, v_18501);
    env = stack[-6];
    stack[-4] = v_18501;
    goto v_18309;
v_18311:
    v_18501 = qvalue(elt(env, 8)); // ifl!*
    v_18501 = qcar(v_18501);
    v_18501 = Lexplodec(nil, v_18501);
    env = stack[-6];
    v_18501 = Lreverse(nil, v_18501);
    env = stack[-6];
    v_18503 = v_18501;
v_18331:
    v_18501 = v_18503;
    if (v_18501 == nil) goto v_18334;
    goto v_18348;
v_18344:
    v_18502 = v_18503;
    goto v_18345;
v_18346:
    v_18501 = elt(env, 6); // !/
    goto v_18347;
v_18348:
    goto v_18344;
v_18345:
    goto v_18346;
v_18347:
    if (!consp(v_18502)) goto v_18342;
    v_18502 = qcar(v_18502);
    if (v_18502 == v_18501) goto v_18341;
    else goto v_18342;
v_18341:
    v_18501 = lisp_true;
    goto v_18340;
v_18342:
    goto v_18359;
v_18355:
    v_18502 = v_18503;
    goto v_18356;
v_18357:
    v_18501 = elt(env, 7); // !\ (backslash)
    goto v_18358;
v_18359:
    goto v_18355;
v_18356:
    goto v_18357;
v_18358:
    v_18501 = Leqcar(nil, v_18502, v_18501);
    env = stack[-6];
    goto v_18340;
    v_18501 = nil;
v_18340:
    if (v_18501 == nil) goto v_18338;
    else goto v_18334;
v_18338:
    goto v_18335;
v_18334:
    goto v_18330;
v_18335:
    v_18501 = v_18503;
    v_18501 = qcdr(v_18501);
    v_18503 = v_18501;
    goto v_18331;
v_18330:
    v_18501 = v_18503;
    if (v_18501 == nil) goto v_18367;
    else goto v_18368;
v_18367:
    v_18501 = elt(env, 10); // (!/ !.)
    v_18503 = v_18501;
    goto v_18366;
v_18368:
v_18366:
    goto v_18376;
v_18372:
    v_18501 = v_18503;
    v_18502 = Lreverse(nil, v_18501);
    env = stack[-6];
    goto v_18373;
v_18374:
    v_18501 = stack[-1];
    v_18501 = qcdr(v_18501);
    v_18501 = qcdr(v_18501);
    goto v_18375;
v_18376:
    goto v_18372;
v_18373:
    goto v_18374;
v_18375:
    v_18501 = Lappend(nil, v_18502, v_18501);
    env = stack[-6];
    stack[-1] = v_18501;
    v_18501 = stack[-1];
    fn = elt(env, 21); // list2string
    v_18501 = (*qfn1(fn))(fn, v_18501);
    env = stack[-6];
    stack[-4] = v_18501;
    goto v_18309;
v_18309:
    goto v_18251;
v_18267:
v_18251:
    v_18501 = stack[0];
    if (v_18501 == nil) goto v_18387;
    goto v_18394;
v_18390:
    v_18502 = stack[-4];
    goto v_18391;
v_18392:
    v_18501 = elt(env, 11); // input
    goto v_18393;
v_18394:
    goto v_18390;
v_18391:
    goto v_18392;
v_18393:
    fn = elt(env, 22); // pipe!-open
    v_18501 = (*qfn2(fn))(fn, v_18502, v_18501);
    env = stack[-6];
    goto v_18385;
v_18387:
    goto v_18404;
v_18400:
    v_18502 = stack[-4];
    goto v_18401;
v_18402:
    v_18501 = elt(env, 11); // input
    goto v_18403;
v_18404:
    goto v_18400;
v_18401:
    goto v_18402;
v_18403:
    fn = elt(env, 23); // open
    v_18501 = (*qfn2(fn))(fn, v_18502, v_18501);
    env = stack[-6];
    goto v_18385;
    v_18501 = nil;
v_18385:
    stack[-1] = v_18501;
    v_18501 = stack[-1];
    v_18501 = Lrds(nil, v_18501);
    env = stack[-6];
    stack[0] = v_18501;
    goto v_18417;
v_18413:
    v_18502 = stack[-4];
    goto v_18414;
v_18415:
    v_18501 = qvalue(elt(env, 12)); // linelist!*
    goto v_18416;
v_18417:
    goto v_18413;
v_18414:
    goto v_18415;
v_18416:
    v_18501 = Lassoc(nil, v_18502, v_18501);
    if (v_18501 == nil) goto v_18412;
    goto v_18410;
v_18412:
v_18410:
    v_18501 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 13)) = v_18501; // curline!*
    goto v_18430;
v_18424:
    v_18503 = stack[-4];
    goto v_18425;
v_18426:
    v_18502 = stack[-1];
    goto v_18427;
v_18428:
    v_18501 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18429;
v_18430:
    goto v_18424;
v_18425:
    goto v_18426;
v_18427:
    goto v_18428;
v_18429:
    v_18501 = list3(v_18503, v_18502, v_18501);
    env = stack[-6];
    qvalue(elt(env, 8)) = v_18501; // ifl!*
    goto v_18439;
v_18435:
    v_18502 = qvalue(elt(env, 8)); // ifl!*
    goto v_18436;
v_18437:
    v_18501 = qvalue(elt(env, 14)); // ipl!*
    goto v_18438;
v_18439:
    goto v_18435;
v_18436:
    goto v_18437;
v_18438:
    v_18501 = cons(v_18502, v_18501);
    env = stack[-6];
    qvalue(elt(env, 14)) = v_18501; // ipl!*
    v_18501 = stack[-3];
    qvalue(elt(env, 1)) = v_18501; // !*echo
    v_18501 = stack[-2];
    fn = elt(env, 24); // begin1a
    v_18501 = (*qfn1(fn))(fn, v_18501);
    env = stack[-6];
    v_18501 = stack[0];
    v_18501 = Lrds(nil, v_18501);
    env = stack[-6];
    v_18501 = stack[-1];
    v_18501 = Lclose(nil, v_18501);
    env = stack[-6];
    v_18501 = stack[-5];
    qvalue(elt(env, 1)) = v_18501; // !*echo
    v_18501 = qvalue(elt(env, 14)); // ipl!*
    if (v_18501 == nil) goto v_18456;
    else goto v_18457;
v_18456:
    v_18501 = qvalue(elt(env, 15)); // contl!*
    goto v_18455;
v_18457:
    v_18501 = nil;
    goto v_18455;
    v_18501 = nil;
v_18455:
    if (v_18501 == nil) goto v_18453;
    v_18501 = nil;
    goto v_18215;
v_18453:
    v_18501 = qvalue(elt(env, 14)); // ipl!*
    if (v_18501 == nil) goto v_18468;
    else goto v_18469;
v_18468:
    v_18501 = lisp_true;
    goto v_18467;
v_18469:
    goto v_18478;
v_18474:
    v_18502 = stack[-4];
    goto v_18475;
v_18476:
    v_18501 = qvalue(elt(env, 14)); // ipl!*
    v_18501 = qcar(v_18501);
    v_18501 = qcar(v_18501);
    goto v_18477;
v_18478:
    goto v_18474;
v_18475:
    goto v_18476;
v_18477:
    v_18501 = (v_18502 == v_18501 ? lisp_true : nil);
    v_18501 = (v_18501 == nil ? lisp_true : nil);
    goto v_18467;
    v_18501 = nil;
v_18467:
    if (v_18501 == nil) goto v_18465;
    goto v_18493;
v_18487:
    v_18503 = elt(env, 16); // "FILE STACK CONFUSION"
    goto v_18488;
v_18489:
    v_18502 = stack[-4];
    goto v_18490;
v_18491:
    v_18501 = qvalue(elt(env, 14)); // ipl!*
    goto v_18492;
v_18493:
    goto v_18487;
v_18488:
    goto v_18489;
v_18490:
    goto v_18491;
v_18492:
    v_18501 = list3(v_18503, v_18502, v_18501);
    env = stack[-6];
    fn = elt(env, 25); // rederr
    v_18501 = (*qfn1(fn))(fn, v_18501);
    goto v_18451;
v_18465:
    v_18501 = qvalue(elt(env, 14)); // ipl!*
    v_18501 = qcdr(v_18501);
    qvalue(elt(env, 14)) = v_18501; // ipl!*
    goto v_18451;
v_18451:
    v_18501 = nil;
v_18215:
    return onevalue(v_18501);
}



// Code for ofsf_siatsubf

static LispObject CC_ofsf_siatsubf(LispObject env,
                         LispObject v_18204, LispObject v_18205)
{
    env = qenv(env);
    LispObject v_18323, v_18324, v_18325;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18204,v_18205);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_18205;
    stack[-1] = v_18204;
// end of prologue
    v_18323 = stack[-1];
    if (!consp(v_18323)) goto v_18218;
    else goto v_18219;
v_18218:
    v_18323 = lisp_true;
    goto v_18217;
v_18219:
    v_18323 = stack[-1];
    v_18323 = qcar(v_18323);
    v_18323 = (consp(v_18323) ? nil : lisp_true);
    goto v_18217;
    v_18323 = nil;
v_18217:
    if (v_18323 == nil) goto v_18215;
    goto v_18232;
v_18228:
    v_18324 = stack[-1];
    goto v_18229;
v_18230:
    v_18323 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18231;
v_18232:
    goto v_18228;
v_18229:
    goto v_18230;
v_18231:
    return cons(v_18324, v_18323);
v_18215:
    goto v_18240;
v_18236:
    v_18323 = stack[-1];
    v_18324 = qcdr(v_18323);
    goto v_18237;
v_18238:
    v_18323 = stack[0];
    goto v_18239;
v_18240:
    goto v_18236;
v_18237:
    goto v_18238;
v_18239:
    v_18323 = CC_ofsf_siatsubf(elt(env, 0), v_18324, v_18323);
    env = stack[-3];
    stack[-2] = v_18323;
    goto v_18249;
v_18245:
    v_18323 = stack[-1];
    v_18323 = qcar(v_18323);
    v_18324 = qcdr(v_18323);
    goto v_18246;
v_18247:
    v_18323 = stack[0];
    goto v_18248;
v_18249:
    goto v_18245;
v_18246:
    goto v_18247;
v_18248:
    v_18323 = CC_ofsf_siatsubf(elt(env, 0), v_18324, v_18323);
    env = stack[-3];
    v_18324 = v_18323;
    goto v_18262;
v_18258:
    v_18323 = stack[-1];
    v_18323 = qcar(v_18323);
    v_18323 = qcar(v_18323);
    v_18325 = qcar(v_18323);
    goto v_18259;
v_18260:
    v_18323 = stack[0];
    goto v_18261;
v_18262:
    goto v_18258;
v_18259:
    goto v_18260;
v_18261:
    v_18323 = Latsoc(nil, v_18325, v_18323);
    v_18325 = v_18323;
    if (v_18323 == nil) goto v_18257;
    goto v_18274;
v_18270:
    goto v_18280;
v_18276:
    stack[0] = v_18324;
    goto v_18277;
v_18278:
    goto v_18287;
v_18283:
    v_18323 = v_18325;
    v_18324 = qcdr(v_18323);
    goto v_18284;
v_18285:
    v_18323 = stack[-1];
    v_18323 = qcar(v_18323);
    v_18323 = qcar(v_18323);
    v_18323 = qcdr(v_18323);
    goto v_18286;
v_18287:
    goto v_18283;
v_18284:
    goto v_18285;
v_18286:
    fn = elt(env, 1); // exptsq
    v_18323 = (*qfn2(fn))(fn, v_18324, v_18323);
    env = stack[-3];
    goto v_18279;
v_18280:
    goto v_18276;
v_18277:
    goto v_18278;
v_18279:
    fn = elt(env, 2); // multsq
    v_18324 = (*qfn2(fn))(fn, stack[0], v_18323);
    env = stack[-3];
    goto v_18271;
v_18272:
    v_18323 = stack[-2];
    goto v_18273;
v_18274:
    goto v_18270;
v_18271:
    goto v_18272;
v_18273:
    {
        fn = elt(env, 3); // addsq
        return (*qfn2(fn))(fn, v_18324, v_18323);
    }
v_18257:
    goto v_18300;
v_18296:
    goto v_18306;
v_18302:
    stack[0] = v_18324;
    goto v_18303;
v_18304:
    goto v_18313;
v_18309:
    v_18323 = stack[-1];
    v_18323 = qcar(v_18323);
    v_18323 = qcar(v_18323);
    v_18324 = qcar(v_18323);
    goto v_18310;
v_18311:
    v_18323 = stack[-1];
    v_18323 = qcar(v_18323);
    v_18323 = qcar(v_18323);
    v_18323 = qcdr(v_18323);
    goto v_18312;
v_18313:
    goto v_18309;
v_18310:
    goto v_18311;
v_18312:
    fn = elt(env, 4); // ofsf_pow2q
    v_18323 = (*qfn2(fn))(fn, v_18324, v_18323);
    env = stack[-3];
    goto v_18305;
v_18306:
    goto v_18302;
v_18303:
    goto v_18304;
v_18305:
    fn = elt(env, 2); // multsq
    v_18324 = (*qfn2(fn))(fn, stack[0], v_18323);
    env = stack[-3];
    goto v_18297;
v_18298:
    v_18323 = stack[-2];
    goto v_18299;
v_18300:
    goto v_18296;
v_18297:
    goto v_18298;
v_18299:
    {
        fn = elt(env, 3); // addsq
        return (*qfn2(fn))(fn, v_18324, v_18323);
    }
    return onevalue(v_18323);
}



// Code for ofsf_simplat1

static LispObject CC_ofsf_simplat1(LispObject env,
                         LispObject v_18204, LispObject v_18205)
{
    env = qenv(env);
    LispObject v_18409, v_18410, v_18411;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18204,v_18205);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_18205;
    v_18411 = v_18204;
// end of prologue
    v_18409 = v_18411;
    v_18409 = qcar(v_18409);
    stack[-3] = v_18409;
    goto v_18221;
v_18217:
    v_18410 = stack[-3];
    goto v_18218;
v_18219:
    v_18409 = elt(env, 1); // (equal neq leq geq lessp greaterp)
    goto v_18220;
v_18221:
    goto v_18217;
v_18218:
    goto v_18219;
v_18220:
    v_18409 = Lmemq(nil, v_18410, v_18409);
    if (v_18409 == nil) goto v_18215;
    else goto v_18216;
v_18215:
    v_18409 = nil;
    goto v_18210;
v_18216:
    v_18409 = v_18411;
    v_18409 = qcdr(v_18409);
    v_18409 = qcar(v_18409);
    stack[-1] = v_18409;
    v_18409 = stack[-1];
    if (!consp(v_18409)) goto v_18235;
    else goto v_18236;
v_18235:
    v_18409 = lisp_true;
    goto v_18234;
v_18236:
    v_18409 = stack[-1];
    v_18409 = qcar(v_18409);
    v_18409 = (consp(v_18409) ? nil : lisp_true);
    goto v_18234;
    v_18409 = nil;
v_18234:
    if (v_18409 == nil) goto v_18232;
    goto v_18253;
v_18249:
    v_18410 = stack[-3];
    goto v_18250;
v_18251:
    v_18409 = stack[-1];
    goto v_18252;
v_18253:
    goto v_18249;
v_18250:
    goto v_18251;
v_18252:
    fn = elt(env, 11); // ofsf_evalatp
    v_18409 = (*qfn2(fn))(fn, v_18410, v_18409);
    env = stack[-4];
    if (v_18409 == nil) goto v_18247;
    v_18409 = elt(env, 2); // true
    goto v_18245;
v_18247:
    v_18409 = elt(env, 3); // false
    goto v_18245;
    v_18409 = nil;
v_18245:
    goto v_18210;
v_18232:
    goto v_18265;
v_18261:
    stack[0] = stack[-1];
    goto v_18262;
v_18263:
    v_18409 = stack[-1];
    fn = elt(env, 12); // sfto_dcontentf
    v_18409 = (*qfn1(fn))(fn, v_18409);
    env = stack[-4];
    goto v_18264;
v_18265:
    goto v_18261;
v_18262:
    goto v_18263;
v_18264:
    fn = elt(env, 13); // quotf
    v_18409 = (*qfn2(fn))(fn, stack[0], v_18409);
    env = stack[-4];
    stack[-1] = v_18409;
    v_18409 = stack[-1];
    fn = elt(env, 14); // minusf
    v_18409 = (*qfn1(fn))(fn, v_18409);
    env = stack[-4];
    if (v_18409 == nil) goto v_18272;
    v_18409 = stack[-1];
    fn = elt(env, 15); // negf
    v_18409 = (*qfn1(fn))(fn, v_18409);
    env = stack[-4];
    stack[-1] = v_18409;
    v_18409 = stack[-3];
    fn = elt(env, 16); // ofsf_anegrel
    v_18409 = (*qfn1(fn))(fn, v_18409);
    env = stack[-4];
    stack[-3] = v_18409;
    goto v_18270;
v_18272:
v_18270:
    v_18409 = qvalue(elt(env, 4)); // !*rlsiatadv
    if (v_18409 == nil) goto v_18281;
    else goto v_18282;
v_18281:
    goto v_18291;
v_18285:
    v_18411 = stack[-3];
    goto v_18286;
v_18287:
    v_18410 = stack[-1];
    goto v_18288;
v_18289:
    v_18409 = nil;
    goto v_18290;
v_18291:
    goto v_18285;
v_18286:
    goto v_18287;
v_18288:
    goto v_18289;
v_18290:
    return list3(v_18411, v_18410, v_18409);
v_18282:
    goto v_18303;
v_18299:
    v_18410 = stack[-3];
    goto v_18300;
v_18301:
    v_18409 = elt(env, 5); // equal
    goto v_18302;
v_18303:
    goto v_18299;
v_18300:
    goto v_18301;
v_18302:
    if (v_18410 == v_18409) goto v_18297;
    else goto v_18298;
v_18297:
    goto v_18311;
v_18307:
    v_18410 = stack[-1];
    goto v_18308;
v_18309:
    v_18409 = stack[-2];
    goto v_18310;
v_18311:
    goto v_18307;
v_18308:
    goto v_18309;
v_18310:
    {
        fn = elt(env, 17); // ofsf_simplequal
        return (*qfn2(fn))(fn, v_18410, v_18409);
    }
v_18298:
    goto v_18322;
v_18318:
    v_18410 = stack[-3];
    goto v_18319;
v_18320:
    v_18409 = elt(env, 6); // neq
    goto v_18321;
v_18322:
    goto v_18318;
v_18319:
    goto v_18320;
v_18321:
    if (v_18410 == v_18409) goto v_18316;
    else goto v_18317;
v_18316:
    goto v_18330;
v_18326:
    v_18410 = stack[-1];
    goto v_18327;
v_18328:
    v_18409 = stack[-2];
    goto v_18329;
v_18330:
    goto v_18326;
v_18327:
    goto v_18328;
v_18329:
    {
        fn = elt(env, 18); // ofsf_simplneq
        return (*qfn2(fn))(fn, v_18410, v_18409);
    }
v_18317:
    goto v_18341;
v_18337:
    v_18410 = stack[-3];
    goto v_18338;
v_18339:
    v_18409 = elt(env, 7); // leq
    goto v_18340;
v_18341:
    goto v_18337;
v_18338:
    goto v_18339;
v_18340:
    if (v_18410 == v_18409) goto v_18335;
    else goto v_18336;
v_18335:
    goto v_18349;
v_18345:
    v_18410 = stack[-1];
    goto v_18346;
v_18347:
    v_18409 = stack[-2];
    goto v_18348;
v_18349:
    goto v_18345;
v_18346:
    goto v_18347;
v_18348:
    {
        fn = elt(env, 19); // ofsf_simplleq
        return (*qfn2(fn))(fn, v_18410, v_18409);
    }
v_18336:
    goto v_18360;
v_18356:
    v_18410 = stack[-3];
    goto v_18357;
v_18358:
    v_18409 = elt(env, 8); // geq
    goto v_18359;
v_18360:
    goto v_18356;
v_18357:
    goto v_18358;
v_18359:
    if (v_18410 == v_18409) goto v_18354;
    else goto v_18355;
v_18354:
    goto v_18368;
v_18364:
    v_18410 = stack[-1];
    goto v_18365;
v_18366:
    v_18409 = stack[-2];
    goto v_18367;
v_18368:
    goto v_18364;
v_18365:
    goto v_18366;
v_18367:
    {
        fn = elt(env, 20); // ofsf_simplgeq
        return (*qfn2(fn))(fn, v_18410, v_18409);
    }
v_18355:
    goto v_18379;
v_18375:
    v_18410 = stack[-3];
    goto v_18376;
v_18377:
    v_18409 = elt(env, 9); // lessp
    goto v_18378;
v_18379:
    goto v_18375;
v_18376:
    goto v_18377;
v_18378:
    if (v_18410 == v_18409) goto v_18373;
    else goto v_18374;
v_18373:
    goto v_18387;
v_18383:
    v_18410 = stack[-1];
    goto v_18384;
v_18385:
    v_18409 = stack[-2];
    goto v_18386;
v_18387:
    goto v_18383;
v_18384:
    goto v_18385;
v_18386:
    {
        fn = elt(env, 21); // ofsf_simpllessp
        return (*qfn2(fn))(fn, v_18410, v_18409);
    }
v_18374:
    goto v_18398;
v_18394:
    v_18410 = stack[-3];
    goto v_18395;
v_18396:
    v_18409 = elt(env, 10); // greaterp
    goto v_18397;
v_18398:
    goto v_18394;
v_18395:
    goto v_18396;
v_18397:
    if (v_18410 == v_18409) goto v_18392;
    else goto v_18393;
v_18392:
    goto v_18406;
v_18402:
    v_18410 = stack[-1];
    goto v_18403;
v_18404:
    v_18409 = stack[-2];
    goto v_18405;
v_18406:
    goto v_18402;
v_18403:
    goto v_18404;
v_18405:
    {
        fn = elt(env, 22); // ofsf_simplgreaterp
        return (*qfn2(fn))(fn, v_18410, v_18409);
    }
v_18393:
    v_18409 = nil;
v_18210:
    return onevalue(v_18409);
}



// Code for talp_atnum

static LispObject CC_talp_atnum(LispObject env,
                         LispObject v_18204)
{
    env = qenv(env);
    LispObject v_18390, v_18391, v_18392, v_18393;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18204);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_18392 = v_18204;
// end of prologue
v_18203:
    v_18390 = v_18392;
    if (!consp(v_18390)) goto v_18211;
    else goto v_18212;
v_18211:
    v_18390 = v_18392;
    goto v_18210;
v_18212:
    v_18390 = v_18392;
    v_18390 = qcar(v_18390);
    goto v_18210;
    v_18390 = nil;
v_18210:
    v_18393 = v_18390;
    goto v_18239;
v_18235:
    v_18391 = v_18393;
    goto v_18236;
v_18237:
    v_18390 = elt(env, 1); // or
    goto v_18238;
v_18239:
    goto v_18235;
v_18236:
    goto v_18237;
v_18238:
    if (v_18391 == v_18390) goto v_18233;
    else goto v_18234;
v_18233:
    v_18390 = lisp_true;
    goto v_18232;
v_18234:
    goto v_18249;
v_18245:
    v_18391 = v_18393;
    goto v_18246;
v_18247:
    v_18390 = elt(env, 2); // and
    goto v_18248;
v_18249:
    goto v_18245;
v_18246:
    goto v_18247;
v_18248:
    v_18390 = (v_18391 == v_18390 ? lisp_true : nil);
    goto v_18232;
    v_18390 = nil;
v_18232:
    if (v_18390 == nil) goto v_18230;
    v_18390 = lisp_true;
    goto v_18228;
v_18230:
    goto v_18260;
v_18256:
    v_18391 = v_18393;
    goto v_18257;
v_18258:
    v_18390 = elt(env, 3); // not
    goto v_18259;
v_18260:
    goto v_18256;
v_18257:
    goto v_18258;
v_18259:
    v_18390 = (v_18391 == v_18390 ? lisp_true : nil);
    goto v_18228;
    v_18390 = nil;
v_18228:
    if (v_18390 == nil) goto v_18226;
    v_18390 = lisp_true;
    goto v_18224;
v_18226:
    goto v_18275;
v_18271:
    v_18391 = v_18393;
    goto v_18272;
v_18273:
    v_18390 = elt(env, 4); // impl
    goto v_18274;
v_18275:
    goto v_18271;
v_18272:
    goto v_18273;
v_18274:
    if (v_18391 == v_18390) goto v_18269;
    else goto v_18270;
v_18269:
    v_18390 = lisp_true;
    goto v_18268;
v_18270:
    goto v_18289;
v_18285:
    v_18391 = v_18393;
    goto v_18286;
v_18287:
    v_18390 = elt(env, 5); // repl
    goto v_18288;
v_18289:
    goto v_18285;
v_18286:
    goto v_18287;
v_18288:
    if (v_18391 == v_18390) goto v_18283;
    else goto v_18284;
v_18283:
    v_18390 = lisp_true;
    goto v_18282;
v_18284:
    goto v_18299;
v_18295:
    v_18391 = v_18393;
    goto v_18296;
v_18297:
    v_18390 = elt(env, 6); // equiv
    goto v_18298;
v_18299:
    goto v_18295;
v_18296:
    goto v_18297;
v_18298:
    v_18390 = (v_18391 == v_18390 ? lisp_true : nil);
    goto v_18282;
    v_18390 = nil;
v_18282:
    goto v_18268;
    v_18390 = nil;
v_18268:
    goto v_18224;
    v_18390 = nil;
v_18224:
    if (v_18390 == nil) goto v_18222;
    v_18390 = v_18392;
    v_18390 = qcdr(v_18390);
    stack[-1] = v_18390;
    v_18390 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_18390;
v_18307:
    v_18390 = stack[-1];
    if (v_18390 == nil) goto v_18313;
    else goto v_18314;
v_18313:
    v_18390 = stack[0];
    goto v_18306;
v_18314:
    goto v_18322;
v_18318:
    v_18390 = stack[-1];
    v_18390 = qcar(v_18390);
    v_18391 = CC_talp_atnum(elt(env, 0), v_18390);
    env = stack[-2];
    goto v_18319;
v_18320:
    v_18390 = stack[0];
    goto v_18321;
v_18322:
    goto v_18318;
v_18319:
    goto v_18320;
v_18321:
    v_18390 = plus2(v_18391, v_18390);
    env = stack[-2];
    stack[0] = v_18390;
    v_18390 = stack[-1];
    v_18390 = qcdr(v_18390);
    stack[-1] = v_18390;
    goto v_18307;
v_18306:
    goto v_18208;
v_18222:
    goto v_18343;
v_18339:
    v_18391 = v_18393;
    goto v_18340;
v_18341:
    v_18390 = elt(env, 7); // ex
    goto v_18342;
v_18343:
    goto v_18339;
v_18340:
    goto v_18341;
v_18342:
    if (v_18391 == v_18390) goto v_18337;
    else goto v_18338;
v_18337:
    v_18390 = lisp_true;
    goto v_18336;
v_18338:
    goto v_18353;
v_18349:
    v_18391 = v_18393;
    goto v_18350;
v_18351:
    v_18390 = elt(env, 8); // all
    goto v_18352;
v_18353:
    goto v_18349;
v_18350:
    goto v_18351;
v_18352:
    v_18390 = (v_18391 == v_18390 ? lisp_true : nil);
    goto v_18336;
    v_18390 = nil;
v_18336:
    if (v_18390 == nil) goto v_18334;
    v_18390 = v_18392;
    v_18390 = qcdr(v_18390);
    v_18390 = qcdr(v_18390);
    v_18390 = qcar(v_18390);
    v_18392 = v_18390;
    goto v_18203;
v_18334:
    goto v_18374;
v_18370:
    v_18391 = v_18393;
    goto v_18371;
v_18372:
    v_18390 = elt(env, 9); // true
    goto v_18373;
v_18374:
    goto v_18370;
v_18371:
    goto v_18372;
v_18373:
    if (v_18391 == v_18390) goto v_18368;
    else goto v_18369;
v_18368:
    v_18390 = lisp_true;
    goto v_18367;
v_18369:
    goto v_18384;
v_18380:
    v_18390 = v_18393;
    goto v_18381;
v_18382:
    v_18391 = elt(env, 10); // false
    goto v_18383;
v_18384:
    goto v_18380;
v_18381:
    goto v_18382;
v_18383:
    v_18390 = (v_18390 == v_18391 ? lisp_true : nil);
    goto v_18367;
    v_18390 = nil;
v_18367:
    if (v_18390 == nil) goto v_18365;
    v_18390 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18208;
v_18365:
    v_18390 = (LispObject)16+TAG_FIXNUM; // 1
v_18208:
    return onevalue(v_18390);
}



// Code for pasf_susibinad

static LispObject CC_pasf_susibinad(LispObject env,
                         LispObject v_18204, LispObject v_18205)
{
    env = qenv(env);
    LispObject v_18486, v_18487, v_18488, v_18489, v_18490, v_18491, v_18492;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18204,v_18205);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_18205;
    stack[-4] = v_18204;
// end of prologue
    goto v_18220;
v_18216:
    v_18486 = stack[-4];
    v_18487 = qcdr(v_18486);
    goto v_18217;
v_18218:
    v_18486 = stack[-3];
    v_18486 = qcdr(v_18486);
    goto v_18219;
v_18220:
    goto v_18216;
v_18217:
    goto v_18218;
v_18219:
    fn = elt(env, 5); // cl_susiminlevel
    v_18486 = (*qfn2(fn))(fn, v_18487, v_18486);
    env = stack[-6];
    stack[-1] = v_18486;
    v_18486 = stack[-4];
    v_18486 = qcar(v_18486);
    stack[-4] = v_18486;
    v_18486 = stack[-3];
    v_18486 = qcar(v_18486);
    stack[-3] = v_18486;
    goto v_18239;
v_18235:
    v_18487 = stack[-3];
    goto v_18236;
v_18237:
    v_18486 = elt(env, 1); // false
    goto v_18238;
v_18239:
    goto v_18235;
v_18236:
    goto v_18237;
v_18238:
    if (v_18487 == v_18486) goto v_18233;
    else goto v_18234;
v_18233:
    v_18486 = elt(env, 1); // false
    goto v_18214;
v_18234:
    goto v_18251;
v_18247:
    v_18487 = stack[-3];
    goto v_18248;
v_18249:
    v_18486 = elt(env, 2); // true
    goto v_18250;
v_18251:
    goto v_18247;
v_18248:
    goto v_18249;
v_18250:
    if (v_18487 == v_18486) goto v_18245;
    else goto v_18246;
v_18245:
    v_18486 = elt(env, 3); // (delete . t)
    return ncons(v_18486);
v_18246:
    goto v_18264;
v_18260:
    v_18486 = stack[-4];
    v_18486 = qcdr(v_18486);
    v_18487 = qcar(v_18486);
    goto v_18261;
v_18262:
    v_18486 = stack[-3];
    v_18486 = qcdr(v_18486);
    v_18486 = qcar(v_18486);
    goto v_18263;
v_18264:
    goto v_18260;
v_18261:
    goto v_18262;
v_18263:
    if (equal(v_18487, v_18486)) goto v_18258;
    else goto v_18259;
v_18258:
    goto v_18280;
v_18272:
    v_18486 = stack[-4];
    v_18486 = qcdr(v_18486);
    v_18489 = qcar(v_18486);
    goto v_18273;
v_18274:
    v_18486 = stack[-4];
    v_18488 = qcar(v_18486);
    goto v_18275;
v_18276:
    v_18486 = stack[-3];
    v_18487 = qcar(v_18486);
    goto v_18277;
v_18278:
    v_18486 = stack[-1];
    goto v_18279;
v_18280:
    goto v_18272;
v_18273:
    goto v_18274;
v_18275:
    goto v_18276;
v_18277:
    goto v_18278;
v_18279:
    {
        fn = elt(env, 6); // pasf_susibineq
        return (*qfnn(fn))(fn, 4, v_18489, v_18488, v_18487, v_18486);
    }
v_18259:
    v_18486 = stack[-4];
    v_18486 = qcdr(v_18486);
    v_18486 = qcar(v_18486);
    fn = elt(env, 7); // pasf_dec
    v_18486 = (*qfn1(fn))(fn, v_18486);
    env = stack[-6];
    stack[-5] = v_18486;
    v_18486 = stack[-3];
    v_18486 = qcdr(v_18486);
    v_18486 = qcar(v_18486);
    fn = elt(env, 7); // pasf_dec
    v_18486 = (*qfn1(fn))(fn, v_18486);
    env = stack[-6];
    stack[-2] = v_18486;
    goto v_18305;
v_18301:
    v_18486 = stack[-5];
    v_18487 = qcar(v_18486);
    goto v_18302;
v_18303:
    v_18486 = stack[-2];
    v_18486 = qcar(v_18486);
    goto v_18304;
v_18305:
    goto v_18301;
v_18302:
    goto v_18303;
v_18304:
    if (equal(v_18487, v_18486)) goto v_18299;
    else goto v_18300;
v_18299:
    goto v_18325;
v_18311:
    v_18486 = stack[-4];
    v_18492 = qcar(v_18486);
    goto v_18312;
v_18313:
    v_18486 = stack[-5];
    v_18491 = qcar(v_18486);
    goto v_18314;
v_18315:
    v_18486 = stack[-5];
    v_18486 = qcdr(v_18486);
    if (v_18486 == nil) goto v_18333;
    v_18486 = stack[-5];
    v_18486 = qcdr(v_18486);
    v_18490 = v_18486;
    goto v_18331;
v_18333:
    v_18486 = (LispObject)0+TAG_FIXNUM; // 0
    v_18490 = v_18486;
    goto v_18331;
    v_18490 = nil;
v_18331:
    goto v_18316;
v_18317:
    v_18486 = stack[-3];
    v_18489 = qcar(v_18486);
    goto v_18318;
v_18319:
    v_18486 = stack[-2];
    v_18488 = qcar(v_18486);
    goto v_18320;
v_18321:
    v_18486 = stack[-2];
    v_18486 = qcdr(v_18486);
    if (v_18486 == nil) goto v_18348;
    v_18486 = stack[-2];
    v_18486 = qcdr(v_18486);
    v_18487 = v_18486;
    goto v_18346;
v_18348:
    v_18486 = (LispObject)0+TAG_FIXNUM; // 0
    v_18487 = v_18486;
    goto v_18346;
    v_18487 = nil;
v_18346:
    goto v_18322;
v_18323:
    v_18486 = stack[-1];
    goto v_18324;
v_18325:
    goto v_18311;
v_18312:
    goto v_18313;
v_18314:
    goto v_18315;
v_18316:
    goto v_18317;
v_18318:
    goto v_18319;
v_18320:
    goto v_18321;
v_18322:
    goto v_18323;
v_18324:
    {
        fn = elt(env, 8); // pasf_susibinord
        return (*qfnn(fn))(fn, 7, v_18492, v_18491, v_18490, v_18489, v_18488, v_18487, v_18486);
    }
v_18300:
    v_18486 = stack[-5];
    v_18486 = qcar(v_18486);
    fn = elt(env, 9); // kernels
    v_18486 = (*qfn1(fn))(fn, v_18486);
    env = stack[-6];
    stack[0] = v_18486;
    v_18486 = stack[-2];
    v_18486 = qcar(v_18486);
    fn = elt(env, 9); // kernels
    v_18486 = (*qfn1(fn))(fn, v_18486);
    env = stack[-6];
    v_18488 = v_18486;
    goto v_18375;
v_18371:
    v_18486 = stack[-4];
    v_18487 = qcar(v_18486);
    goto v_18372;
v_18373:
    v_18486 = elt(env, 4); // equal
    goto v_18374;
v_18375:
    goto v_18371;
v_18372:
    goto v_18373;
v_18374:
    if (v_18487 == v_18486) goto v_18369;
    else goto v_18370;
v_18369:
    v_18486 = stack[0];
    v_18486 = qcdr(v_18486);
    if (v_18486 == nil) goto v_18381;
    else goto v_18382;
v_18381:
    goto v_18389;
v_18385:
    v_18486 = stack[0];
    v_18487 = qcar(v_18486);
    goto v_18386;
v_18387:
    v_18486 = v_18488;
    goto v_18388;
v_18389:
    goto v_18385;
v_18386:
    goto v_18387;
v_18388:
    v_18486 = Lmemq(nil, v_18487, v_18486);
    goto v_18380;
v_18382:
    v_18486 = nil;
    goto v_18380;
    v_18486 = nil;
v_18380:
    goto v_18368;
v_18370:
    v_18486 = nil;
    goto v_18368;
    v_18486 = nil;
v_18368:
    if (v_18486 == nil) goto v_18366;
    goto v_18407;
v_18401:
    goto v_18415;
v_18409:
    stack[-2] = stack[-3];
    goto v_18410;
v_18411:
    v_18486 = stack[0];
    stack[0] = qcar(v_18486);
    goto v_18412;
v_18413:
    v_18486 = stack[-5];
    v_18486 = qcdr(v_18486);
    fn = elt(env, 10); // negf
    v_18486 = (*qfn1(fn))(fn, v_18486);
    env = stack[-6];
    goto v_18414;
v_18415:
    goto v_18409;
v_18410:
    goto v_18411;
v_18412:
    goto v_18413;
v_18414:
    fn = elt(env, 11); // pasf_subfof1
    v_18488 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_18486);
    env = stack[-6];
    goto v_18402;
v_18403:
    v_18487 = stack[-1];
    goto v_18404;
v_18405:
    v_18486 = lisp_true;
    goto v_18406;
v_18407:
    goto v_18401;
v_18402:
    goto v_18403;
v_18404:
    goto v_18405;
v_18406:
    {
        fn = elt(env, 12); // pasf_susibinad1
        return (*qfnn(fn))(fn, 3, v_18488, v_18487, v_18486);
    }
v_18366:
    goto v_18436;
v_18432:
    v_18486 = stack[-3];
    v_18487 = qcar(v_18486);
    goto v_18433;
v_18434:
    v_18486 = elt(env, 4); // equal
    goto v_18435;
v_18436:
    goto v_18432;
v_18433:
    goto v_18434;
v_18435:
    if (v_18487 == v_18486) goto v_18430;
    else goto v_18431;
v_18430:
    v_18486 = v_18488;
    v_18486 = qcdr(v_18486);
    if (v_18486 == nil) goto v_18442;
    else goto v_18443;
v_18442:
    goto v_18450;
v_18446:
    v_18486 = v_18488;
    v_18487 = qcar(v_18486);
    goto v_18447;
v_18448:
    v_18486 = stack[0];
    goto v_18449;
v_18450:
    goto v_18446;
v_18447:
    goto v_18448;
v_18449:
    v_18486 = Lmemq(nil, v_18487, v_18486);
    goto v_18441;
v_18443:
    v_18486 = nil;
    goto v_18441;
    v_18486 = nil;
v_18441:
    goto v_18429;
v_18431:
    v_18486 = nil;
    goto v_18429;
    v_18486 = nil;
v_18429:
    if (v_18486 == nil) goto v_18427;
    goto v_18468;
v_18462:
    goto v_18476;
v_18470:
    stack[-3] = stack[-4];
    goto v_18471;
v_18472:
    v_18486 = v_18488;
    stack[0] = qcar(v_18486);
    goto v_18473;
v_18474:
    v_18486 = stack[-2];
    v_18486 = qcdr(v_18486);
    fn = elt(env, 10); // negf
    v_18486 = (*qfn1(fn))(fn, v_18486);
    env = stack[-6];
    goto v_18475;
v_18476:
    goto v_18470;
v_18471:
    goto v_18472;
v_18473:
    goto v_18474;
v_18475:
    fn = elt(env, 11); // pasf_subfof1
    v_18488 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_18486);
    env = stack[-6];
    goto v_18463;
v_18464:
    v_18487 = stack[-1];
    goto v_18465;
v_18466:
    v_18486 = nil;
    goto v_18467;
v_18468:
    goto v_18462;
v_18463:
    goto v_18464;
v_18465:
    goto v_18466;
v_18467:
    {
        fn = elt(env, 12); // pasf_susibinad1
        return (*qfnn(fn))(fn, 3, v_18488, v_18487, v_18486);
    }
v_18427:
    v_18486 = nil;
v_18214:
    return onevalue(v_18486);
}



// Code for ev_max!#

static LispObject CC_ev_maxC(LispObject env,
                         LispObject v_18204, LispObject v_18205)
{
    env = qenv(env);
    LispObject v_18222, v_18223, v_18224, v_18225;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18223 = v_18205;
    v_18224 = v_18204;
// end of prologue
    goto v_18215;
v_18211:
    v_18225 = v_18224;
    goto v_18212;
v_18213:
    v_18222 = v_18223;
    goto v_18214;
v_18215:
    goto v_18211;
v_18212:
    goto v_18213;
v_18214:
    if (((intptr_t)(v_18225)) > ((intptr_t)(v_18222))) goto v_18209;
    else goto v_18210;
v_18209:
    v_18222 = v_18224;
    goto v_18208;
v_18210:
    v_18222 = v_18223;
    goto v_18208;
    v_18222 = nil;
v_18208:
    return onevalue(v_18222);
}



// Code for minusml

static LispObject CC_minusml(LispObject env,
                         LispObject v_18204)
{
    env = qenv(env);
    LispObject v_18219;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18204);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18204;
// end of prologue
    v_18219 = elt(env, 1); // "<apply><minus/>"
    fn = elt(env, 3); // printout
    v_18219 = (*qfn1(fn))(fn, v_18219);
    env = stack[-1];
    v_18219 = lisp_true;
    fn = elt(env, 4); // indent!*
    v_18219 = (*qfn1(fn))(fn, v_18219);
    env = stack[-1];
    v_18219 = stack[0];
    v_18219 = qcdr(v_18219);
    fn = elt(env, 5); // multiminus
    v_18219 = (*qfn1(fn))(fn, v_18219);
    env = stack[-1];
    v_18219 = nil;
    fn = elt(env, 4); // indent!*
    v_18219 = (*qfn1(fn))(fn, v_18219);
    env = stack[-1];
    v_18219 = elt(env, 2); // "</apply>"
    fn = elt(env, 3); // printout
    v_18219 = (*qfn1(fn))(fn, v_18219);
    v_18219 = nil;
    return onevalue(v_18219);
}



// Code for dm!-min

static LispObject CC_dmKmin(LispObject env,
                         LispObject v_18204, LispObject v_18205)
{
    env = qenv(env);
    LispObject v_18223, v_18224;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18204,v_18205);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18205;
    stack[-1] = v_18204;
// end of prologue
    goto v_18216;
v_18212:
    v_18224 = stack[-1];
    goto v_18213;
v_18214:
    v_18223 = stack[0];
    goto v_18215;
v_18216:
    goto v_18212;
v_18213:
    goto v_18214;
v_18215:
    fn = elt(env, 1); // dm!-gt
    v_18223 = (*qfn2(fn))(fn, v_18224, v_18223);
    if (v_18223 == nil) goto v_18210;
    v_18223 = stack[0];
    goto v_18208;
v_18210:
    v_18223 = stack[-1];
    goto v_18208;
    v_18223 = nil;
v_18208:
    return onevalue(v_18223);
}



// Code for !:dmtimeslst

static LispObject CC_Tdmtimeslst(LispObject env,
                         LispObject v_18204)
{
    env = qenv(env);
    LispObject v_18231, v_18232;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18204);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_18232 = v_18204;
// end of prologue
    v_18231 = v_18232;
    if (v_18231 == nil) goto v_18208;
    else goto v_18209;
v_18208:
    v_18231 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18207;
v_18209:
    v_18231 = v_18232;
    v_18231 = qcdr(v_18231);
    if (v_18231 == nil) goto v_18212;
    else goto v_18213;
v_18212:
    v_18231 = v_18232;
    v_18231 = qcar(v_18231);
    goto v_18207;
v_18213:
    goto v_18225;
v_18221:
    v_18231 = v_18232;
    stack[0] = qcar(v_18231);
    goto v_18222;
v_18223:
    v_18231 = v_18232;
    v_18231 = qcdr(v_18231);
    v_18231 = CC_Tdmtimeslst(elt(env, 0), v_18231);
    env = stack[-1];
    goto v_18224;
v_18225:
    goto v_18221;
v_18222:
    goto v_18223;
v_18224:
    {
        LispObject v_18234 = stack[0];
        fn = elt(env, 1); // !:times
        return (*qfn2(fn))(fn, v_18234, v_18231);
    }
    v_18231 = nil;
v_18207:
    return onevalue(v_18231);
}



// Code for !*di2q

static LispObject CC_Hdi2q(LispObject env,
                         LispObject v_18205, LispObject v_18206)
{
    env = qenv(env);
    LispObject v_18283, v_18284, v_18285;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18206,v_18205);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18205,v_18206);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_18283 = v_18206;
    v_18284 = v_18205;
// end of prologue
// Binding varlist!*
// FLUIDBIND: reloadenv=5 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-5, 1, -4);
    qvalue(elt(env, 1)) = v_18283; // varlist!*
    goto v_18217;
v_18213:
    v_18283 = v_18284;
    stack[-3] = v_18283;
    v_18283 = stack[-3];
    if (v_18283 == nil) goto v_18227;
    else goto v_18228;
v_18227:
    v_18283 = nil;
    v_18284 = v_18283;
    goto v_18222;
v_18228:
    v_18283 = stack[-3];
    v_18283 = qcar(v_18283);
    goto v_18242;
v_18236:
    v_18284 = v_18283;
    v_18285 = qcar(v_18284);
    goto v_18237;
v_18238:
    v_18284 = qcdr(v_18283);
    goto v_18239;
v_18240:
    v_18283 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18241;
v_18242:
    goto v_18236;
v_18237:
    goto v_18238;
v_18239:
    goto v_18240;
v_18241:
    v_18283 = list2star(v_18285, v_18284, v_18283);
    env = stack[-5];
    v_18283 = ncons(v_18283);
    env = stack[-5];
    stack[-1] = v_18283;
    stack[-2] = v_18283;
v_18223:
    v_18283 = stack[-3];
    v_18283 = qcdr(v_18283);
    stack[-3] = v_18283;
    v_18283 = stack[-3];
    if (v_18283 == nil) goto v_18252;
    else goto v_18253;
v_18252:
    v_18283 = stack[-2];
    v_18284 = v_18283;
    goto v_18222;
v_18253:
    goto v_18261;
v_18257:
    stack[0] = stack[-1];
    goto v_18258;
v_18259:
    v_18283 = stack[-3];
    v_18283 = qcar(v_18283);
    goto v_18274;
v_18268:
    v_18284 = v_18283;
    v_18285 = qcar(v_18284);
    goto v_18269;
v_18270:
    v_18284 = qcdr(v_18283);
    goto v_18271;
v_18272:
    v_18283 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18273;
v_18274:
    goto v_18268;
v_18269:
    goto v_18270;
v_18271:
    goto v_18272;
v_18273:
    v_18283 = list2star(v_18285, v_18284, v_18283);
    env = stack[-5];
    v_18283 = ncons(v_18283);
    env = stack[-5];
    goto v_18260;
v_18261:
    goto v_18257;
v_18258:
    goto v_18259;
v_18260:
    v_18283 = Lrplacd(nil, stack[0], v_18283);
    env = stack[-5];
    v_18283 = stack[-1];
    v_18283 = qcdr(v_18283);
    stack[-1] = v_18283;
    goto v_18223;
v_18222:
    goto v_18214;
v_18215:
    v_18283 = qvalue(elt(env, 1)); // varlist!*
    goto v_18216;
v_18217:
    goto v_18213;
v_18214:
    goto v_18215;
v_18216:
    fn = elt(env, 2); // !*di2q0
    v_18283 = (*qfn2(fn))(fn, v_18284, v_18283);
    ;}  // end of a binding scope
    return onevalue(v_18283);
}



// Code for expand_rule

static LispObject CC_expand_rule(LispObject env,
                         LispObject v_18204)
{
    env = qenv(env);
    LispObject v_18355, v_18356;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18204);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    v_18356 = v_18204;
// end of prologue
    goto v_18211;
v_18207:
    v_18355 = v_18356;
    stack[-9] = qcar(v_18355);
    goto v_18208;
v_18209:
    v_18355 = v_18356;
    v_18355 = qcdr(v_18355);
    stack[-8] = v_18355;
    v_18355 = stack[-8];
    if (v_18355 == nil) goto v_18224;
    else goto v_18225;
v_18224:
    v_18355 = nil;
    goto v_18218;
v_18225:
    v_18355 = stack[-8];
    v_18355 = qcar(v_18355);
    stack[-4] = v_18355;
    goto v_18237;
v_18233:
    v_18355 = stack[-4];
    v_18355 = qcar(v_18355);
    stack[-3] = v_18355;
    v_18355 = stack[-3];
    if (v_18355 == nil) goto v_18248;
    else goto v_18249;
v_18248:
    v_18355 = nil;
    v_18356 = v_18355;
    goto v_18242;
v_18249:
    v_18355 = stack[-3];
    v_18355 = qcar(v_18355);
    fn = elt(env, 1); // expand_terminal
    v_18355 = (*qfn1(fn))(fn, v_18355);
    env = stack[-10];
    v_18355 = ncons(v_18355);
    env = stack[-10];
    stack[-1] = v_18355;
    stack[-2] = v_18355;
v_18243:
    v_18355 = stack[-3];
    v_18355 = qcdr(v_18355);
    stack[-3] = v_18355;
    v_18355 = stack[-3];
    if (v_18355 == nil) goto v_18262;
    else goto v_18263;
v_18262:
    v_18355 = stack[-2];
    v_18356 = v_18355;
    goto v_18242;
v_18263:
    goto v_18271;
v_18267:
    stack[0] = stack[-1];
    goto v_18268;
v_18269:
    v_18355 = stack[-3];
    v_18355 = qcar(v_18355);
    fn = elt(env, 1); // expand_terminal
    v_18355 = (*qfn1(fn))(fn, v_18355);
    env = stack[-10];
    v_18355 = ncons(v_18355);
    env = stack[-10];
    goto v_18270;
v_18271:
    goto v_18267;
v_18268:
    goto v_18269;
v_18270:
    v_18355 = Lrplacd(nil, stack[0], v_18355);
    env = stack[-10];
    v_18355 = stack[-1];
    v_18355 = qcdr(v_18355);
    stack[-1] = v_18355;
    goto v_18243;
v_18242:
    goto v_18234;
v_18235:
    v_18355 = stack[-4];
    v_18355 = qcdr(v_18355);
    goto v_18236;
v_18237:
    goto v_18233;
v_18234:
    goto v_18235;
v_18236:
    v_18355 = cons(v_18356, v_18355);
    env = stack[-10];
    v_18355 = ncons(v_18355);
    env = stack[-10];
    stack[-6] = v_18355;
    stack[-7] = v_18355;
v_18219:
    v_18355 = stack[-8];
    v_18355 = qcdr(v_18355);
    stack[-8] = v_18355;
    v_18355 = stack[-8];
    if (v_18355 == nil) goto v_18287;
    else goto v_18288;
v_18287:
    v_18355 = stack[-7];
    goto v_18218;
v_18288:
    goto v_18296;
v_18292:
    stack[-5] = stack[-6];
    goto v_18293;
v_18294:
    v_18355 = stack[-8];
    v_18355 = qcar(v_18355);
    stack[-4] = v_18355;
    goto v_18307;
v_18303:
    v_18355 = stack[-4];
    v_18355 = qcar(v_18355);
    stack[-3] = v_18355;
    v_18355 = stack[-3];
    if (v_18355 == nil) goto v_18318;
    else goto v_18319;
v_18318:
    v_18355 = nil;
    v_18356 = v_18355;
    goto v_18312;
v_18319:
    v_18355 = stack[-3];
    v_18355 = qcar(v_18355);
    fn = elt(env, 1); // expand_terminal
    v_18355 = (*qfn1(fn))(fn, v_18355);
    env = stack[-10];
    v_18355 = ncons(v_18355);
    env = stack[-10];
    stack[-1] = v_18355;
    stack[-2] = v_18355;
v_18313:
    v_18355 = stack[-3];
    v_18355 = qcdr(v_18355);
    stack[-3] = v_18355;
    v_18355 = stack[-3];
    if (v_18355 == nil) goto v_18332;
    else goto v_18333;
v_18332:
    v_18355 = stack[-2];
    v_18356 = v_18355;
    goto v_18312;
v_18333:
    goto v_18341;
v_18337:
    stack[0] = stack[-1];
    goto v_18338;
v_18339:
    v_18355 = stack[-3];
    v_18355 = qcar(v_18355);
    fn = elt(env, 1); // expand_terminal
    v_18355 = (*qfn1(fn))(fn, v_18355);
    env = stack[-10];
    v_18355 = ncons(v_18355);
    env = stack[-10];
    goto v_18340;
v_18341:
    goto v_18337;
v_18338:
    goto v_18339;
v_18340:
    v_18355 = Lrplacd(nil, stack[0], v_18355);
    env = stack[-10];
    v_18355 = stack[-1];
    v_18355 = qcdr(v_18355);
    stack[-1] = v_18355;
    goto v_18313;
v_18312:
    goto v_18304;
v_18305:
    v_18355 = stack[-4];
    v_18355 = qcdr(v_18355);
    goto v_18306;
v_18307:
    goto v_18303;
v_18304:
    goto v_18305;
v_18306:
    v_18355 = cons(v_18356, v_18355);
    env = stack[-10];
    v_18355 = ncons(v_18355);
    env = stack[-10];
    goto v_18295;
v_18296:
    goto v_18292;
v_18293:
    goto v_18294;
v_18295:
    v_18355 = Lrplacd(nil, stack[-5], v_18355);
    env = stack[-10];
    v_18355 = stack[-6];
    v_18355 = qcdr(v_18355);
    stack[-6] = v_18355;
    goto v_18219;
v_18218:
    goto v_18210;
v_18211:
    goto v_18207;
v_18208:
    goto v_18209;
v_18210:
    {
        LispObject v_18367 = stack[-9];
        return cons(v_18367, v_18355);
    }
}



// Code for pasf_sisub

static LispObject CC_pasf_sisub(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18655, v_18656, v_18657, v_18658, v_18659, v_18660;
    LispObject fn;
    LispObject v_18206, v_18205, v_18204;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pasf_sisub");
    va_start(aa, nargs);
    v_18204 = va_arg(aa, LispObject);
    v_18205 = va_arg(aa, LispObject);
    v_18206 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18206,v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18204,v_18205,v_18206);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_18206;
    stack[-5] = v_18205;
    stack[-1] = v_18204;
// end of prologue
    v_18655 = stack[-1];
    if (!consp(v_18655)) goto v_18213;
    else goto v_18214;
v_18213:
    v_18655 = stack[-1];
    goto v_18212;
v_18214:
    v_18655 = stack[-1];
    v_18655 = qcar(v_18655);
    goto v_18212;
    v_18655 = nil;
v_18212:
    stack[-6] = v_18655;
    goto v_18233;
v_18229:
    v_18656 = stack[-6];
    goto v_18230;
v_18231:
    v_18655 = elt(env, 1); // ex
    goto v_18232;
v_18233:
    goto v_18229;
v_18230:
    goto v_18231;
v_18232:
    if (v_18656 == v_18655) goto v_18227;
    else goto v_18228;
v_18227:
    v_18655 = lisp_true;
    goto v_18226;
v_18228:
    goto v_18243;
v_18239:
    v_18656 = stack[-6];
    goto v_18240;
v_18241:
    v_18655 = elt(env, 2); // all
    goto v_18242;
v_18243:
    goto v_18239;
v_18240:
    goto v_18241;
v_18242:
    v_18655 = (v_18656 == v_18655 ? lisp_true : nil);
    goto v_18226;
    v_18655 = nil;
v_18226:
    if (v_18655 == nil) goto v_18224;
    goto v_18254;
v_18248:
    stack[-2] = stack[-6];
    goto v_18249;
v_18250:
    v_18655 = stack[-1];
    v_18655 = qcdr(v_18655);
    stack[0] = qcar(v_18655);
    goto v_18251;
v_18252:
    goto v_18266;
v_18260:
    v_18655 = stack[-1];
    v_18655 = qcdr(v_18655);
    v_18655 = qcdr(v_18655);
    v_18657 = qcar(v_18655);
    goto v_18261;
v_18262:
    v_18656 = stack[-5];
    goto v_18263;
v_18264:
    v_18655 = stack[-4];
    goto v_18265;
v_18266:
    goto v_18260;
v_18261:
    goto v_18262;
v_18263:
    goto v_18264;
v_18265:
    v_18655 = CC_pasf_sisub(elt(env, 0), 3, v_18657, v_18656, v_18655);
    goto v_18253;
v_18254:
    goto v_18248;
v_18249:
    goto v_18250;
v_18251:
    goto v_18252;
v_18253:
    {
        LispObject v_18668 = stack[-2];
        LispObject v_18669 = stack[0];
        return list3(v_18668, v_18669, v_18655);
    }
v_18224:
    goto v_18285;
v_18281:
    v_18656 = stack[-6];
    goto v_18282;
v_18283:
    v_18655 = elt(env, 3); // bex
    goto v_18284;
v_18285:
    goto v_18281;
v_18282:
    goto v_18283;
v_18284:
    if (v_18656 == v_18655) goto v_18279;
    else goto v_18280;
v_18279:
    v_18655 = lisp_true;
    goto v_18278;
v_18280:
    goto v_18295;
v_18291:
    v_18656 = stack[-6];
    goto v_18292;
v_18293:
    v_18655 = elt(env, 4); // ball
    goto v_18294;
v_18295:
    goto v_18291;
v_18292:
    goto v_18293;
v_18294:
    v_18655 = (v_18656 == v_18655 ? lisp_true : nil);
    goto v_18278;
    v_18655 = nil;
v_18278:
    if (v_18655 == nil) goto v_18276;
    goto v_18308;
v_18300:
    stack[-3] = stack[-6];
    goto v_18301;
v_18302:
    v_18655 = stack[-1];
    v_18655 = qcdr(v_18655);
    stack[-2] = qcar(v_18655);
    goto v_18303;
v_18304:
    goto v_18320;
v_18314:
    v_18655 = stack[-1];
    v_18655 = qcdr(v_18655);
    v_18655 = qcdr(v_18655);
    v_18657 = qcar(v_18655);
    goto v_18315;
v_18316:
    v_18656 = stack[-5];
    goto v_18317;
v_18318:
    v_18655 = stack[-4];
    goto v_18319;
v_18320:
    goto v_18314;
v_18315:
    goto v_18316;
v_18317:
    goto v_18318;
v_18319:
    stack[0] = CC_pasf_sisub(elt(env, 0), 3, v_18657, v_18656, v_18655);
    env = stack[-7];
    goto v_18305;
v_18306:
    goto v_18334;
v_18328:
    v_18655 = stack[-1];
    v_18655 = qcdr(v_18655);
    v_18655 = qcdr(v_18655);
    v_18655 = qcdr(v_18655);
    v_18657 = qcar(v_18655);
    goto v_18329;
v_18330:
    v_18656 = stack[-5];
    goto v_18331;
v_18332:
    v_18655 = stack[-4];
    goto v_18333;
v_18334:
    goto v_18328;
v_18329:
    goto v_18330;
v_18331:
    goto v_18332;
v_18333:
    v_18655 = CC_pasf_sisub(elt(env, 0), 3, v_18657, v_18656, v_18655);
    goto v_18307;
v_18308:
    goto v_18300;
v_18301:
    goto v_18302;
v_18303:
    goto v_18304;
v_18305:
    goto v_18306;
v_18307:
    {
        LispObject v_18670 = stack[-3];
        LispObject v_18671 = stack[-2];
        LispObject v_18672 = stack[0];
        return list4(v_18670, v_18671, v_18672, v_18655);
    }
v_18276:
    goto v_18350;
v_18346:
    v_18656 = stack[-6];
    goto v_18347;
v_18348:
    v_18655 = elt(env, 5); // and
    goto v_18349;
v_18350:
    goto v_18346;
v_18347:
    goto v_18348;
v_18349:
    if (v_18656 == v_18655) goto v_18344;
    else goto v_18345;
v_18344:
    goto v_18366;
v_18354:
    v_18660 = elt(env, 5); // and
    goto v_18355;
v_18356:
    v_18655 = stack[-1];
    v_18659 = qcdr(v_18655);
    goto v_18357;
v_18358:
    v_18658 = stack[-5];
    goto v_18359;
v_18360:
    v_18657 = stack[-4];
    goto v_18361;
v_18362:
    v_18656 = elt(env, 6); // true
    goto v_18363;
v_18364:
    v_18655 = elt(env, 7); // false
    goto v_18365;
v_18366:
    goto v_18354;
v_18355:
    goto v_18356;
v_18357:
    goto v_18358;
v_18359:
    goto v_18360;
v_18361:
    goto v_18362;
v_18363:
    goto v_18364;
v_18365:
    {
        fn = elt(env, 13); // pasf_sisub!-gand
        return (*qfnn(fn))(fn, 6, v_18660, v_18659, v_18658, v_18657, v_18656, v_18655);
    }
v_18345:
    goto v_18382;
v_18378:
    v_18656 = stack[-6];
    goto v_18379;
v_18380:
    v_18655 = elt(env, 8); // or
    goto v_18381;
v_18382:
    goto v_18378;
v_18379:
    goto v_18380;
v_18381:
    if (v_18656 == v_18655) goto v_18376;
    else goto v_18377;
v_18376:
    goto v_18398;
v_18386:
    v_18660 = elt(env, 8); // or
    goto v_18387;
v_18388:
    v_18655 = stack[-1];
    v_18659 = qcdr(v_18655);
    goto v_18389;
v_18390:
    v_18658 = stack[-5];
    goto v_18391;
v_18392:
    v_18657 = stack[-4];
    goto v_18393;
v_18394:
    v_18656 = elt(env, 7); // false
    goto v_18395;
v_18396:
    v_18655 = elt(env, 6); // true
    goto v_18397;
v_18398:
    goto v_18386;
v_18387:
    goto v_18388;
v_18389:
    goto v_18390;
v_18391:
    goto v_18392;
v_18393:
    goto v_18394;
v_18395:
    goto v_18396;
v_18397:
    {
        fn = elt(env, 13); // pasf_sisub!-gand
        return (*qfnn(fn))(fn, 6, v_18660, v_18659, v_18658, v_18657, v_18656, v_18655);
    }
v_18377:
    goto v_18426;
v_18422:
    v_18656 = stack[-6];
    goto v_18423;
v_18424:
    v_18655 = elt(env, 8); // or
    goto v_18425;
v_18426:
    goto v_18422;
v_18423:
    goto v_18424;
v_18425:
    if (v_18656 == v_18655) goto v_18420;
    else goto v_18421;
v_18420:
    v_18655 = lisp_true;
    goto v_18419;
v_18421:
    goto v_18436;
v_18432:
    v_18656 = stack[-6];
    goto v_18433;
v_18434:
    v_18655 = elt(env, 5); // and
    goto v_18435;
v_18436:
    goto v_18432;
v_18433:
    goto v_18434;
v_18435:
    v_18655 = (v_18656 == v_18655 ? lisp_true : nil);
    goto v_18419;
    v_18655 = nil;
v_18419:
    if (v_18655 == nil) goto v_18417;
    v_18655 = lisp_true;
    goto v_18415;
v_18417:
    goto v_18447;
v_18443:
    v_18656 = stack[-6];
    goto v_18444;
v_18445:
    v_18655 = elt(env, 9); // not
    goto v_18446;
v_18447:
    goto v_18443;
v_18444:
    goto v_18445;
v_18446:
    v_18655 = (v_18656 == v_18655 ? lisp_true : nil);
    goto v_18415;
    v_18655 = nil;
v_18415:
    if (v_18655 == nil) goto v_18413;
    v_18655 = lisp_true;
    goto v_18411;
v_18413:
    goto v_18462;
v_18458:
    v_18656 = stack[-6];
    goto v_18459;
v_18460:
    v_18655 = elt(env, 10); // impl
    goto v_18461;
v_18462:
    goto v_18458;
v_18459:
    goto v_18460;
v_18461:
    if (v_18656 == v_18655) goto v_18456;
    else goto v_18457;
v_18456:
    v_18655 = lisp_true;
    goto v_18455;
v_18457:
    goto v_18476;
v_18472:
    v_18656 = stack[-6];
    goto v_18473;
v_18474:
    v_18655 = elt(env, 11); // repl
    goto v_18475;
v_18476:
    goto v_18472;
v_18473:
    goto v_18474;
v_18475:
    if (v_18656 == v_18655) goto v_18470;
    else goto v_18471;
v_18470:
    v_18655 = lisp_true;
    goto v_18469;
v_18471:
    goto v_18486;
v_18482:
    v_18656 = stack[-6];
    goto v_18483;
v_18484:
    v_18655 = elt(env, 12); // equiv
    goto v_18485;
v_18486:
    goto v_18482;
v_18483:
    goto v_18484;
v_18485:
    v_18655 = (v_18656 == v_18655 ? lisp_true : nil);
    goto v_18469;
    v_18655 = nil;
v_18469:
    goto v_18455;
    v_18655 = nil;
v_18455:
    goto v_18411;
    v_18655 = nil;
v_18411:
    if (v_18655 == nil) goto v_18409;
    v_18655 = stack[-1];
    v_18655 = qcdr(v_18655);
    stack[-3] = v_18655;
    v_18655 = stack[-3];
    if (v_18655 == nil) goto v_18500;
    else goto v_18501;
v_18500:
    v_18655 = nil;
    goto v_18494;
v_18501:
    v_18655 = stack[-3];
    v_18655 = qcar(v_18655);
    goto v_18515;
v_18509:
    v_18657 = v_18655;
    goto v_18510;
v_18511:
    v_18656 = stack[-5];
    goto v_18512;
v_18513:
    v_18655 = stack[-4];
    goto v_18514;
v_18515:
    goto v_18509;
v_18510:
    goto v_18511;
v_18512:
    goto v_18513;
v_18514:
    v_18655 = CC_pasf_sisub(elt(env, 0), 3, v_18657, v_18656, v_18655);
    env = stack[-7];
    v_18655 = ncons(v_18655);
    env = stack[-7];
    stack[-1] = v_18655;
    stack[-2] = v_18655;
v_18495:
    v_18655 = stack[-3];
    v_18655 = qcdr(v_18655);
    stack[-3] = v_18655;
    v_18655 = stack[-3];
    if (v_18655 == nil) goto v_18523;
    else goto v_18524;
v_18523:
    v_18655 = stack[-2];
    goto v_18494;
v_18524:
    goto v_18532;
v_18528:
    stack[0] = stack[-1];
    goto v_18529;
v_18530:
    v_18655 = stack[-3];
    v_18655 = qcar(v_18655);
    goto v_18545;
v_18539:
    v_18657 = v_18655;
    goto v_18540;
v_18541:
    v_18656 = stack[-5];
    goto v_18542;
v_18543:
    v_18655 = stack[-4];
    goto v_18544;
v_18545:
    goto v_18539;
v_18540:
    goto v_18541;
v_18542:
    goto v_18543;
v_18544:
    v_18655 = CC_pasf_sisub(elt(env, 0), 3, v_18657, v_18656, v_18655);
    env = stack[-7];
    v_18655 = ncons(v_18655);
    env = stack[-7];
    goto v_18531;
v_18532:
    goto v_18528;
v_18529:
    goto v_18530;
v_18531:
    v_18655 = Lrplacd(nil, stack[0], v_18655);
    env = stack[-7];
    v_18655 = stack[-1];
    v_18655 = qcdr(v_18655);
    stack[-1] = v_18655;
    goto v_18495;
v_18494:
    v_18656 = v_18655;
    v_18655 = v_18656;
    if (v_18655 == nil) goto v_18555;
    v_18655 = v_18656;
    v_18655 = qcdr(v_18655);
    if (v_18655 == nil) goto v_18555;
    goto v_18566;
v_18562:
    v_18655 = stack[-6];
    goto v_18563;
v_18564:
    goto v_18565;
v_18566:
    goto v_18562;
v_18563:
    goto v_18564;
v_18565:
    return cons(v_18655, v_18656);
v_18555:
    v_18655 = v_18656;
    if (v_18655 == nil) goto v_18569;
    else goto v_18570;
v_18569:
    goto v_18580;
v_18576:
    v_18656 = stack[-6];
    goto v_18577;
v_18578:
    v_18655 = elt(env, 5); // and
    goto v_18579;
v_18580:
    goto v_18576;
v_18577:
    goto v_18578;
v_18579:
    if (v_18656 == v_18655) goto v_18574;
    else goto v_18575;
v_18574:
    v_18655 = elt(env, 6); // true
    goto v_18573;
v_18575:
    v_18655 = elt(env, 7); // false
    goto v_18573;
    v_18655 = nil;
v_18573:
    goto v_18553;
v_18570:
    v_18655 = v_18656;
    v_18655 = qcar(v_18655);
    goto v_18553;
    v_18655 = nil;
v_18553:
    goto v_18210;
v_18409:
    goto v_18603;
v_18599:
    v_18656 = stack[-6];
    goto v_18600;
v_18601:
    v_18655 = elt(env, 6); // true
    goto v_18602;
v_18603:
    goto v_18599;
v_18600:
    goto v_18601;
v_18602:
    if (v_18656 == v_18655) goto v_18597;
    else goto v_18598;
v_18597:
    v_18655 = lisp_true;
    goto v_18596;
v_18598:
    goto v_18613;
v_18609:
    v_18656 = stack[-6];
    goto v_18610;
v_18611:
    v_18655 = elt(env, 7); // false
    goto v_18612;
v_18613:
    goto v_18609;
v_18610:
    goto v_18611;
v_18612:
    v_18655 = (v_18656 == v_18655 ? lisp_true : nil);
    goto v_18596;
    v_18655 = nil;
v_18596:
    if (v_18655 == nil) goto v_18594;
    v_18655 = stack[-1];
    goto v_18210;
v_18594:
    goto v_18623;
v_18619:
    goto v_18631;
v_18625:
    v_18655 = stack[-1];
    stack[0] = qcar(v_18655);
    goto v_18626;
v_18627:
    goto v_18639;
v_18635:
    v_18655 = stack[-1];
    v_18655 = qcdr(v_18655);
    stack[-1] = qcar(v_18655);
    goto v_18636;
v_18637:
    goto v_18649;
v_18645:
    v_18656 = stack[-5];
    goto v_18646;
v_18647:
    v_18655 = stack[-4];
    goto v_18648;
v_18649:
    goto v_18645;
v_18646:
    goto v_18647;
v_18648:
    v_18655 = cons(v_18656, v_18655);
    env = stack[-7];
    v_18655 = ncons(v_18655);
    env = stack[-7];
    goto v_18638;
v_18639:
    goto v_18635;
v_18636:
    goto v_18637;
v_18638:
    fn = elt(env, 14); // subf
    v_18655 = (*qfn2(fn))(fn, stack[-1], v_18655);
    env = stack[-7];
    v_18656 = qcar(v_18655);
    goto v_18628;
v_18629:
    v_18655 = nil;
    goto v_18630;
v_18631:
    goto v_18625;
v_18626:
    goto v_18627;
v_18628:
    goto v_18629;
v_18630:
    v_18656 = list3(stack[0], v_18656, v_18655);
    env = stack[-7];
    goto v_18620;
v_18621:
    v_18655 = stack[-6];
    goto v_18622;
v_18623:
    goto v_18619;
v_18620:
    goto v_18621;
v_18622:
    {
        fn = elt(env, 15); // pasf_simplat1
        return (*qfn2(fn))(fn, v_18656, v_18655);
    }
v_18210:
    return onevalue(v_18655);
}



// Code for dip_ilcomb2r

static LispObject CC_dip_ilcomb2r(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18474, v_18475, v_18476;
    LispObject fn;
    LispObject v_18210, v_18209, v_18208, v_18207, v_18206, v_18205, v_18204;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 7, "dip_ilcomb2r");
    va_start(aa, nargs);
    v_18204 = va_arg(aa, LispObject);
    v_18205 = va_arg(aa, LispObject);
    v_18206 = va_arg(aa, LispObject);
    v_18207 = va_arg(aa, LispObject);
    v_18208 = va_arg(aa, LispObject);
    v_18209 = va_arg(aa, LispObject);
    v_18210 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_18210,v_18209,v_18208,v_18207,v_18206,v_18205);
        push(v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_18204,v_18205,v_18206,v_18207,v_18208,v_18209);
        pop(v_18210);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[0] = v_18210;
    stack[-1] = v_18209;
    stack[-2] = v_18208;
    stack[-3] = v_18207;
    stack[-4] = v_18206;
    stack[-5] = v_18205;
    stack[-6] = v_18204;
// end of prologue
    stack[-7] = nil;
v_18218:
    v_18474 = stack[-1];
    if (v_18474 == nil) goto v_18221;
    goto v_18231;
v_18227:
    goto v_18237;
v_18233:
    v_18475 = stack[-4];
    goto v_18234;
v_18235:
    v_18474 = stack[-2];
    goto v_18236;
v_18237:
    goto v_18233;
v_18234:
    goto v_18235;
v_18236:
    fn = elt(env, 1); // ev_comp
    v_18475 = (*qfn2(fn))(fn, v_18475, v_18474);
    env = stack[-8];
    stack[-7] = v_18475;
    goto v_18228;
v_18229:
    v_18474 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_18230;
v_18231:
    goto v_18227;
v_18228:
    goto v_18229;
v_18230:
    fn = elt(env, 2); // iequal
    v_18474 = (*qfn2(fn))(fn, v_18475, v_18474);
    env = stack[-8];
    if (v_18474 == nil) goto v_18221;
    goto v_18222;
v_18221:
    goto v_18217;
v_18222:
    goto v_18249;
v_18243:
    v_18476 = stack[-3];
    goto v_18244;
v_18245:
    v_18475 = stack[-2];
    goto v_18246;
v_18247:
    v_18474 = stack[-6];
    goto v_18248;
v_18249:
    goto v_18243;
v_18244:
    goto v_18245;
v_18246:
    goto v_18247;
v_18248:
    v_18474 = list2star(v_18476, v_18475, v_18474);
    env = stack[-8];
    stack[-6] = v_18474;
    v_18474 = stack[-1];
    v_18474 = qcar(v_18474);
    stack[-2] = v_18474;
    v_18474 = stack[-1];
    v_18474 = qcdr(v_18474);
    stack[-1] = v_18474;
    goto v_18262;
v_18258:
    v_18474 = stack[-1];
    v_18475 = qcar(v_18474);
    goto v_18259;
v_18260:
    v_18474 = stack[0];
    goto v_18261;
v_18262:
    goto v_18258;
v_18259:
    goto v_18260;
v_18261:
    fn = elt(env, 3); // bc_prod
    v_18474 = (*qfn2(fn))(fn, v_18475, v_18474);
    env = stack[-8];
    stack[-3] = v_18474;
    v_18474 = stack[-1];
    v_18474 = qcdr(v_18474);
    stack[-1] = v_18474;
    goto v_18218;
v_18217:
    v_18474 = stack[-1];
    if (v_18474 == nil) goto v_18271;
    goto v_18282;
v_18278:
    v_18475 = stack[-7];
    goto v_18279;
v_18280:
    v_18474 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18281;
v_18282:
    goto v_18278;
v_18279:
    goto v_18280;
v_18281:
    fn = elt(env, 2); // iequal
    v_18474 = (*qfn2(fn))(fn, v_18475, v_18474);
    env = stack[-8];
    if (v_18474 == nil) goto v_18276;
    goto v_18292;
v_18286:
    goto v_18287;
v_18288:
    goto v_18289;
v_18290:
    goto v_18302;
v_18296:
    v_18476 = stack[-5];
    goto v_18297;
v_18298:
    v_18475 = stack[-4];
    goto v_18299;
v_18300:
    v_18474 = stack[-6];
    goto v_18301;
v_18302:
    goto v_18296;
v_18297:
    goto v_18298;
v_18299:
    goto v_18300;
v_18301:
    v_18474 = list2star(v_18476, v_18475, v_18474);
    env = stack[-8];
    goto v_18291;
v_18292:
    goto v_18286;
v_18287:
    goto v_18288;
v_18289:
    goto v_18290;
v_18291:
    v_18474 = list2star(stack[-3], stack[-2], v_18474);
    env = stack[-8];
    stack[-6] = v_18474;
    goto v_18274;
v_18276:
    goto v_18313;
v_18309:
    v_18475 = stack[-5];
    goto v_18310;
v_18311:
    v_18474 = stack[-3];
    goto v_18312;
v_18313:
    goto v_18309;
v_18310:
    goto v_18311;
v_18312:
    fn = elt(env, 4); // bc_sum
    v_18474 = (*qfn2(fn))(fn, v_18475, v_18474);
    env = stack[-8];
    stack[-2] = v_18474;
    v_18474 = stack[-2];
    fn = elt(env, 5); // bc_zero!?
    v_18474 = (*qfn1(fn))(fn, v_18474);
    env = stack[-8];
    if (v_18474 == nil) goto v_18318;
    else goto v_18319;
v_18318:
    goto v_18329;
v_18323:
    v_18476 = stack[-2];
    goto v_18324;
v_18325:
    v_18475 = stack[-4];
    goto v_18326;
v_18327:
    v_18474 = stack[-6];
    goto v_18328;
v_18329:
    goto v_18323;
v_18324:
    goto v_18325;
v_18326:
    goto v_18327;
v_18328:
    v_18474 = list2star(v_18476, v_18475, v_18474);
    env = stack[-8];
    stack[-6] = v_18474;
    goto v_18317;
v_18319:
v_18317:
    goto v_18274;
v_18274:
v_18335:
    v_18474 = stack[-1];
    if (v_18474 == nil) goto v_18338;
    else goto v_18339;
v_18338:
    goto v_18334;
v_18339:
    goto v_18347;
v_18343:
    v_18474 = stack[-1];
    v_18475 = qcar(v_18474);
    goto v_18344;
v_18345:
    v_18474 = stack[-6];
    goto v_18346;
v_18347:
    goto v_18343;
v_18344:
    goto v_18345;
v_18346:
    v_18474 = cons(v_18475, v_18474);
    env = stack[-8];
    stack[-6] = v_18474;
    v_18474 = stack[-1];
    v_18474 = qcdr(v_18474);
    stack[-1] = v_18474;
    goto v_18358;
v_18354:
    goto v_18364;
v_18360:
    v_18474 = stack[-1];
    v_18475 = qcar(v_18474);
    goto v_18361;
v_18362:
    v_18474 = stack[0];
    goto v_18363;
v_18364:
    goto v_18360;
v_18361:
    goto v_18362;
v_18363:
    fn = elt(env, 3); // bc_prod
    v_18475 = (*qfn2(fn))(fn, v_18475, v_18474);
    env = stack[-8];
    goto v_18355;
v_18356:
    v_18474 = stack[-6];
    goto v_18357;
v_18358:
    goto v_18354;
v_18355:
    goto v_18356;
v_18357:
    v_18474 = cons(v_18475, v_18474);
    env = stack[-8];
    stack[-6] = v_18474;
    v_18474 = stack[-1];
    v_18474 = qcdr(v_18474);
    stack[-1] = v_18474;
    goto v_18335;
v_18334:
    v_18474 = stack[-6];
        return Lnreverse(nil, v_18474);
v_18271:
    goto v_18378;
v_18374:
    v_18475 = stack[-4];
    goto v_18375;
v_18376:
    v_18474 = stack[-2];
    goto v_18377;
v_18378:
    goto v_18374;
v_18375:
    goto v_18376;
v_18377:
    fn = elt(env, 1); // ev_comp
    v_18474 = (*qfn2(fn))(fn, v_18475, v_18474);
    env = stack[-8];
    stack[-7] = v_18474;
    goto v_18390;
v_18386:
    v_18475 = stack[-7];
    goto v_18387;
v_18388:
    v_18474 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_18389;
v_18390:
    goto v_18386;
v_18387:
    goto v_18388;
v_18389:
    fn = elt(env, 2); // iequal
    v_18474 = (*qfn2(fn))(fn, v_18475, v_18474);
    env = stack[-8];
    if (v_18474 == nil) goto v_18384;
    goto v_18400;
v_18394:
    stack[0] = stack[-5];
    goto v_18395;
v_18396:
    stack[-1] = stack[-4];
    goto v_18397;
v_18398:
    goto v_18410;
v_18404:
    v_18476 = stack[-3];
    goto v_18405;
v_18406:
    v_18475 = stack[-2];
    goto v_18407;
v_18408:
    v_18474 = stack[-6];
    goto v_18409;
v_18410:
    goto v_18404;
v_18405:
    goto v_18406;
v_18407:
    goto v_18408;
v_18409:
    v_18474 = list2star(v_18476, v_18475, v_18474);
    env = stack[-8];
    goto v_18399;
v_18400:
    goto v_18394;
v_18395:
    goto v_18396;
v_18397:
    goto v_18398;
v_18399:
    v_18474 = list2star(stack[0], stack[-1], v_18474);
    stack[-6] = v_18474;
    goto v_18382;
v_18384:
    goto v_18421;
v_18417:
    v_18475 = stack[-7];
    goto v_18418;
v_18419:
    v_18474 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18420;
v_18421:
    goto v_18417;
v_18418:
    goto v_18419;
v_18420:
    fn = elt(env, 2); // iequal
    v_18474 = (*qfn2(fn))(fn, v_18475, v_18474);
    env = stack[-8];
    if (v_18474 == nil) goto v_18415;
    goto v_18431;
v_18425:
    stack[0] = stack[-3];
    goto v_18426;
v_18427:
    stack[-1] = stack[-2];
    goto v_18428;
v_18429:
    goto v_18441;
v_18435:
    v_18476 = stack[-5];
    goto v_18436;
v_18437:
    v_18475 = stack[-4];
    goto v_18438;
v_18439:
    v_18474 = stack[-6];
    goto v_18440;
v_18441:
    goto v_18435;
v_18436:
    goto v_18437;
v_18438:
    goto v_18439;
v_18440:
    v_18474 = list2star(v_18476, v_18475, v_18474);
    env = stack[-8];
    goto v_18430;
v_18431:
    goto v_18425;
v_18426:
    goto v_18427;
v_18428:
    goto v_18429;
v_18430:
    v_18474 = list2star(stack[0], stack[-1], v_18474);
    stack[-6] = v_18474;
    goto v_18382;
v_18415:
    goto v_18452;
v_18448:
    v_18475 = stack[-5];
    goto v_18449;
v_18450:
    v_18474 = stack[-3];
    goto v_18451;
v_18452:
    goto v_18448;
v_18449:
    goto v_18450;
v_18451:
    fn = elt(env, 4); // bc_sum
    v_18474 = (*qfn2(fn))(fn, v_18475, v_18474);
    env = stack[-8];
    stack[-2] = v_18474;
    v_18474 = stack[-2];
    fn = elt(env, 5); // bc_zero!?
    v_18474 = (*qfn1(fn))(fn, v_18474);
    env = stack[-8];
    if (v_18474 == nil) goto v_18457;
    else goto v_18458;
v_18457:
    goto v_18468;
v_18462:
    v_18476 = stack[-2];
    goto v_18463;
v_18464:
    v_18475 = stack[-4];
    goto v_18465;
v_18466:
    v_18474 = stack[-6];
    goto v_18467;
v_18468:
    goto v_18462;
v_18463:
    goto v_18464;
v_18465:
    goto v_18466;
v_18467:
    v_18474 = list2star(v_18476, v_18475, v_18474);
    stack[-6] = v_18474;
    goto v_18456;
v_18458:
v_18456:
    goto v_18382;
v_18382:
    v_18474 = stack[-6];
        return Lnreverse(nil, v_18474);
    return onevalue(v_18474);
}



// Code for multiminus

static LispObject CC_multiminus(LispObject env,
                         LispObject v_18204)
{
    env = qenv(env);
    LispObject v_18227, v_18228;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18204);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18204;
// end of prologue
    v_18227 = stack[0];
    v_18227 = qcar(v_18227);
    fn = elt(env, 1); // expression
    v_18227 = (*qfn1(fn))(fn, v_18227);
    env = stack[-1];
    goto v_18219;
v_18215:
    v_18227 = stack[0];
    v_18228 = Llength(nil, v_18227);
    env = stack[-1];
    goto v_18216;
v_18217:
    v_18227 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_18218;
v_18219:
    goto v_18215;
v_18216:
    goto v_18217;
v_18218:
    if (v_18228 == v_18227) goto v_18213;
    else goto v_18214;
v_18213:
    v_18227 = stack[0];
    v_18227 = qcdr(v_18227);
    v_18227 = qcar(v_18227);
    fn = elt(env, 1); // expression
    v_18227 = (*qfn1(fn))(fn, v_18227);
    goto v_18212;
v_18214:
v_18212:
    v_18227 = nil;
    return onevalue(v_18227);
}



// Code for mkempspmat

static LispObject CC_mkempspmat(LispObject env,
                         LispObject v_18204, LispObject v_18205)
{
    env = qenv(env);
    LispObject v_18223, v_18224;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18204,v_18205);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18205;
    v_18223 = v_18204;
// end of prologue
    goto v_18217;
v_18211:
    stack[-1] = elt(env, 1); // sparsemat
    goto v_18212;
v_18213:
    v_18224 = Lmkvect(nil, v_18223);
    goto v_18214;
v_18215:
    v_18223 = stack[0];
    goto v_18216;
v_18217:
    goto v_18211;
v_18212:
    goto v_18213;
v_18214:
    goto v_18215;
v_18216:
    {
        LispObject v_18227 = stack[-1];
        return list3(v_18227, v_18224, v_18223);
    }
    return onevalue(v_18223);
}



// Code for suchp

static LispObject CC_suchp(LispObject env,
                         LispObject v_18204)
{
    env = qenv(env);
    LispObject v_18223, v_18224;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18224 = v_18204;
// end of prologue
    v_18223 = v_18224;
    if (!consp(v_18223)) goto v_18209;
    goto v_18215;
v_18211:
    v_18223 = v_18224;
    v_18223 = qcar(v_18223);
    goto v_18212;
v_18213:
    v_18224 = elt(env, 1); // such!-that
    goto v_18214;
v_18215:
    goto v_18211;
v_18212:
    goto v_18213;
v_18214:
    v_18223 = (v_18223 == v_18224 ? lisp_true : nil);
    goto v_18207;
v_18209:
    v_18223 = nil;
    goto v_18207;
    v_18223 = nil;
v_18207:
    return onevalue(v_18223);
}



// Code for dipequal

static LispObject CC_dipequal(LispObject env,
                         LispObject v_18204, LispObject v_18205)
{
    env = qenv(env);
    LispObject v_18264, v_18265;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18204,v_18205);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18205;
    stack[-1] = v_18204;
// end of prologue
v_18209:
    v_18264 = stack[-1];
    if (v_18264 == nil) goto v_18212;
    else goto v_18213;
v_18212:
    v_18264 = stack[0];
    v_18264 = (v_18264 == nil ? lisp_true : nil);
    goto v_18208;
v_18213:
    v_18264 = stack[0];
    if (v_18264 == nil) goto v_18217;
    else goto v_18218;
v_18217:
    v_18264 = nil;
    goto v_18208;
v_18218:
    goto v_18231;
v_18227:
    v_18264 = stack[-1];
    v_18264 = qcdr(v_18264);
    v_18265 = qcar(v_18264);
    goto v_18228;
v_18229:
    v_18264 = stack[0];
    v_18264 = qcdr(v_18264);
    v_18264 = qcar(v_18264);
    goto v_18230;
v_18231:
    goto v_18227;
v_18228:
    goto v_18229;
v_18230:
    if (equal(v_18265, v_18264)) goto v_18225;
    else goto v_18226;
v_18225:
    goto v_18247;
v_18243:
    v_18264 = stack[-1];
    v_18265 = qcar(v_18264);
    goto v_18244;
v_18245:
    v_18264 = stack[0];
    v_18264 = qcar(v_18264);
    goto v_18246;
v_18247:
    goto v_18243;
v_18244:
    goto v_18245;
v_18246:
    fn = elt(env, 1); // evequal
    v_18264 = (*qfn2(fn))(fn, v_18265, v_18264);
    env = stack[-2];
    if (v_18264 == nil) goto v_18241;
    v_18264 = stack[-1];
    v_18264 = qcdr(v_18264);
    v_18264 = qcdr(v_18264);
    stack[-1] = v_18264;
    v_18264 = stack[0];
    v_18264 = qcdr(v_18264);
    v_18264 = qcdr(v_18264);
    stack[0] = v_18264;
    goto v_18209;
v_18241:
    v_18264 = nil;
    goto v_18208;
    goto v_18224;
v_18226:
    v_18264 = nil;
    goto v_18208;
v_18224:
    goto v_18211;
v_18211:
    v_18264 = nil;
v_18208:
    return onevalue(v_18264);
}



// Code for f2dip11

static LispObject CC_f2dip11(LispObject env,
                         LispObject v_18204)
{
    env = qenv(env);
    LispObject v_18257, v_18258;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18204);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_18204;
// end of prologue
v_18203:
    v_18257 = qvalue(elt(env, 1)); // !*notestparameters
    if (v_18257 == nil) goto v_18208;
    else goto v_18207;
v_18208:
    goto v_18218;
v_18214:
    v_18258 = stack[0];
    goto v_18215;
v_18216:
    v_18257 = qvalue(elt(env, 2)); // vdpvars!*
    goto v_18217;
v_18218:
    goto v_18214;
v_18215:
    goto v_18216;
v_18217:
    v_18257 = Lmember(nil, v_18258, v_18257);
    if (v_18257 == nil) goto v_18213;
    goto v_18228;
v_18224:
    v_18258 = stack[0];
    goto v_18225;
v_18226:
    v_18257 = elt(env, 3); // "occurs in a parameter and is member of the groebner variables."
    goto v_18227;
v_18228:
    goto v_18224;
v_18225:
    goto v_18226;
v_18227:
    v_18257 = list2(v_18258, v_18257);
    env = stack[-1];
    fn = elt(env, 6); // rederr
    v_18257 = (*qfn1(fn))(fn, v_18257);
    env = stack[-1];
    goto v_18211;
v_18213:
v_18211:
    v_18257 = stack[0];
    if (!consp(v_18257)) goto v_18233;
    else goto v_18234;
v_18233:
    goto v_18244;
v_18240:
    v_18258 = stack[0];
    goto v_18241;
v_18242:
    v_18257 = elt(env, 4); // list
    goto v_18243;
v_18244:
    goto v_18240;
v_18241:
    goto v_18242;
v_18243:
    if (v_18258 == v_18257) goto v_18238;
    else goto v_18239;
v_18238:
    v_18257 = elt(env, 5); // "groebner: LIST not allowed."
    {
        fn = elt(env, 6); // rederr
        return (*qfn1(fn))(fn, v_18257);
    }
v_18239:
    v_18257 = nil;
    goto v_18232;
v_18234:
    v_18257 = stack[0];
    v_18257 = qcar(v_18257);
    v_18257 = CC_f2dip11(elt(env, 0), v_18257);
    env = stack[-1];
    v_18257 = stack[0];
    v_18257 = qcdr(v_18257);
    stack[0] = v_18257;
    goto v_18203;
    v_18257 = nil;
v_18232:
v_18207:
    return onevalue(v_18257);
}



// Code for !*xadd

static LispObject CC_Hxadd(LispObject env,
                         LispObject v_18204, LispObject v_18205)
{
    env = qenv(env);
    LispObject v_18257, v_18258, v_18259, v_18260;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18204,v_18205);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18260 = v_18205;
    stack[0] = v_18204;
// end of prologue
    v_18257 = v_18260;
    v_18259 = v_18257;
v_18213:
    v_18257 = v_18259;
    if (v_18257 == nil) goto v_18216;
    goto v_18225;
v_18221:
    v_18257 = stack[0];
    v_18258 = qcar(v_18257);
    goto v_18222;
v_18223:
    v_18257 = v_18259;
    v_18257 = qcar(v_18257);
    v_18257 = qcar(v_18257);
    goto v_18224;
v_18225:
    goto v_18221;
v_18222:
    goto v_18223;
v_18224:
    if (equal(v_18258, v_18257)) goto v_18216;
    goto v_18217;
v_18216:
    goto v_18212;
v_18217:
    v_18257 = v_18259;
    v_18257 = qcdr(v_18257);
    v_18259 = v_18257;
    goto v_18213;
v_18212:
    v_18257 = v_18259;
    if (v_18257 == nil) goto v_18237;
    goto v_18244;
v_18240:
    v_18257 = v_18259;
    v_18257 = qcar(v_18257);
    goto v_18241;
v_18242:
    v_18258 = v_18260;
    goto v_18243;
v_18244:
    goto v_18240;
v_18241:
    goto v_18242;
v_18243:
    v_18257 = Ldelete(nil, v_18257, v_18258);
    v_18260 = v_18257;
    goto v_18235;
v_18237:
v_18235:
    goto v_18253;
v_18249:
    v_18257 = stack[0];
    goto v_18250;
v_18251:
    v_18258 = v_18260;
    goto v_18252;
v_18253:
    goto v_18249;
v_18250:
    goto v_18251;
v_18252:
    return cons(v_18257, v_18258);
    return onevalue(v_18257);
}



// Code for simp!-prop1

static LispObject CC_simpKprop1(LispObject env,
                         LispObject v_18204, LispObject v_18205)
{
    env = qenv(env);
    LispObject v_18702, v_18703, v_18704;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18204,v_18205);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_18205;
    stack[-4] = v_18204;
// end of prologue
v_18203:
    v_18702 = stack[-4];
    if (!consp(v_18702)) goto v_18214;
    else goto v_18215;
v_18214:
    goto v_18210;
v_18215:
    goto v_18230;
v_18226:
    v_18702 = stack[-4];
    v_18703 = qcar(v_18702);
    goto v_18227;
v_18228:
    v_18702 = qvalue(elt(env, 1)); // !'and
    goto v_18229;
v_18230:
    goto v_18226;
v_18227:
    goto v_18228;
v_18229:
    if (equal(v_18703, v_18702)) goto v_18224;
    else goto v_18225;
v_18224:
    v_18702 = stack[-3];
    goto v_18223;
v_18225:
    v_18702 = nil;
    goto v_18223;
    v_18702 = nil;
v_18223:
    if (v_18702 == nil) goto v_18221;
    else goto v_18219;
v_18221:
    goto v_18247;
v_18243:
    v_18702 = stack[-4];
    v_18703 = qcar(v_18702);
    goto v_18244;
v_18245:
    v_18702 = qvalue(elt(env, 2)); // !'or
    goto v_18246;
v_18247:
    goto v_18243;
v_18244:
    goto v_18245;
v_18246:
    if (equal(v_18703, v_18702)) goto v_18241;
    else goto v_18242;
v_18241:
    v_18702 = stack[-3];
    v_18702 = (v_18702 == nil ? lisp_true : nil);
    goto v_18240;
v_18242:
    v_18702 = nil;
    goto v_18240;
    v_18702 = nil;
v_18240:
    if (v_18702 == nil) goto v_18238;
    else goto v_18219;
v_18238:
    goto v_18220;
v_18219:
    v_18702 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_18702;
    v_18702 = stack[-4];
    v_18702 = qcdr(v_18702);
    stack[-1] = v_18702;
v_18260:
    v_18702 = stack[-1];
    if (v_18702 == nil) goto v_18265;
    else goto v_18266;
v_18265:
    goto v_18259;
v_18266:
    v_18702 = stack[-1];
    v_18702 = qcar(v_18702);
    goto v_18277;
v_18273:
    goto v_18274;
v_18275:
    goto v_18284;
v_18280:
    v_18703 = v_18702;
    goto v_18281;
v_18282:
    v_18702 = stack[-3];
    goto v_18283;
v_18284:
    goto v_18280;
v_18281:
    goto v_18282;
v_18283:
    v_18702 = CC_simpKprop1(elt(env, 0), v_18703, v_18702);
    env = stack[-6];
    goto v_18276;
v_18277:
    goto v_18273;
v_18274:
    goto v_18275;
v_18276:
    fn = elt(env, 16); // multf
    v_18702 = (*qfn2(fn))(fn, stack[0], v_18702);
    env = stack[-6];
    stack[0] = v_18702;
    v_18702 = stack[-1];
    v_18702 = qcdr(v_18702);
    stack[-1] = v_18702;
    goto v_18260;
v_18259:
    goto v_18218;
v_18220:
    goto v_18300;
v_18296:
    v_18702 = stack[-4];
    v_18703 = qcar(v_18702);
    goto v_18297;
v_18298:
    v_18702 = qvalue(elt(env, 2)); // !'or
    goto v_18299;
v_18300:
    goto v_18296;
v_18297:
    goto v_18298;
v_18299:
    if (equal(v_18703, v_18702)) goto v_18294;
    else goto v_18295;
v_18294:
    v_18702 = stack[-3];
    goto v_18293;
v_18295:
    v_18702 = nil;
    goto v_18293;
    v_18702 = nil;
v_18293:
    if (v_18702 == nil) goto v_18291;
    else goto v_18289;
v_18291:
    goto v_18317;
v_18313:
    v_18702 = stack[-4];
    v_18703 = qcar(v_18702);
    goto v_18314;
v_18315:
    v_18702 = qvalue(elt(env, 1)); // !'and
    goto v_18316;
v_18317:
    goto v_18313;
v_18314:
    goto v_18315;
v_18316:
    if (equal(v_18703, v_18702)) goto v_18311;
    else goto v_18312;
v_18311:
    v_18702 = stack[-3];
    v_18702 = (v_18702 == nil ? lisp_true : nil);
    goto v_18310;
v_18312:
    v_18702 = nil;
    goto v_18310;
    v_18702 = nil;
v_18310:
    if (v_18702 == nil) goto v_18308;
    else goto v_18289;
v_18308:
    goto v_18290;
v_18289:
    v_18702 = nil;
    stack[0] = v_18702;
    v_18702 = stack[-4];
    v_18702 = qcdr(v_18702);
    stack[-1] = v_18702;
v_18330:
    v_18702 = stack[-1];
    if (v_18702 == nil) goto v_18335;
    else goto v_18336;
v_18335:
    goto v_18329;
v_18336:
    v_18702 = stack[-1];
    v_18702 = qcar(v_18702);
    goto v_18347;
v_18343:
    goto v_18344;
v_18345:
    goto v_18354;
v_18350:
    v_18703 = v_18702;
    goto v_18351;
v_18352:
    v_18702 = stack[-3];
    goto v_18353;
v_18354:
    goto v_18350;
v_18351:
    goto v_18352;
v_18353:
    v_18702 = CC_simpKprop1(elt(env, 0), v_18703, v_18702);
    env = stack[-6];
    goto v_18346;
v_18347:
    goto v_18343;
v_18344:
    goto v_18345;
v_18346:
    fn = elt(env, 17); // addf
    v_18702 = (*qfn2(fn))(fn, stack[0], v_18702);
    env = stack[-6];
    stack[0] = v_18702;
    v_18702 = stack[-1];
    v_18702 = qcdr(v_18702);
    stack[-1] = v_18702;
    goto v_18330;
v_18329:
    goto v_18218;
v_18290:
    goto v_18365;
v_18361:
    v_18702 = stack[-4];
    v_18703 = qcar(v_18702);
    goto v_18362;
v_18363:
    v_18702 = elt(env, 3); // not
    goto v_18364;
v_18365:
    goto v_18361;
v_18362:
    goto v_18363;
v_18364:
    if (v_18703 == v_18702) goto v_18359;
    else goto v_18360;
v_18359:
    goto v_18374;
v_18370:
    v_18702 = stack[-4];
    v_18702 = qcdr(v_18702);
    v_18703 = qcar(v_18702);
    goto v_18371;
v_18372:
    v_18702 = stack[-3];
    v_18702 = (v_18702 == nil ? lisp_true : nil);
    goto v_18373;
v_18374:
    goto v_18370;
v_18371:
    goto v_18372;
v_18373:
    v_18702 = CC_simpKprop1(elt(env, 0), v_18703, v_18702);
    stack[0] = v_18702;
    goto v_18218;
v_18360:
    goto v_18386;
v_18382:
    v_18702 = stack[-4];
    v_18703 = qcar(v_18702);
    goto v_18383;
v_18384:
    v_18702 = elt(env, 4); // implies
    goto v_18385;
v_18386:
    goto v_18382;
v_18383:
    goto v_18384;
v_18385:
    if (v_18703 == v_18702) goto v_18380;
    else goto v_18381;
v_18380:
    v_18702 = stack[-3];
    if (v_18702 == nil) goto v_18393;
    goto v_18400;
v_18396:
    goto v_18408;
v_18402:
    stack[0] = elt(env, 5); // or
    goto v_18403;
v_18404:
    goto v_18415;
v_18411:
    v_18703 = elt(env, 3); // not
    goto v_18412;
v_18413:
    v_18702 = stack[-4];
    v_18702 = qcdr(v_18702);
    v_18702 = qcar(v_18702);
    goto v_18414;
v_18415:
    goto v_18411;
v_18412:
    goto v_18413;
v_18414:
    v_18703 = list2(v_18703, v_18702);
    env = stack[-6];
    goto v_18405;
v_18406:
    v_18702 = stack[-4];
    v_18702 = qcdr(v_18702);
    v_18702 = qcdr(v_18702);
    v_18702 = qcar(v_18702);
    goto v_18407;
v_18408:
    goto v_18402;
v_18403:
    goto v_18404;
v_18405:
    goto v_18406;
v_18407:
    v_18703 = list3(stack[0], v_18703, v_18702);
    env = stack[-6];
    goto v_18397;
v_18398:
    v_18702 = lisp_true;
    goto v_18399;
v_18400:
    goto v_18396;
v_18397:
    goto v_18398;
v_18399:
    v_18702 = CC_simpKprop1(elt(env, 0), v_18703, v_18702);
    stack[0] = v_18702;
    goto v_18391;
v_18393:
    goto v_18432;
v_18428:
    goto v_18440;
v_18434:
    stack[0] = elt(env, 5); // or
    goto v_18435;
v_18436:
    goto v_18447;
v_18443:
    v_18703 = elt(env, 3); // not
    goto v_18444;
v_18445:
    v_18702 = stack[-4];
    v_18702 = qcdr(v_18702);
    v_18702 = qcdr(v_18702);
    v_18702 = qcar(v_18702);
    goto v_18446;
v_18447:
    goto v_18443;
v_18444:
    goto v_18445;
v_18446:
    v_18703 = list2(v_18703, v_18702);
    env = stack[-6];
    goto v_18437;
v_18438:
    v_18702 = stack[-4];
    v_18702 = qcdr(v_18702);
    v_18702 = qcar(v_18702);
    goto v_18439;
v_18440:
    goto v_18434;
v_18435:
    goto v_18436;
v_18437:
    goto v_18438;
v_18439:
    v_18703 = list3(stack[0], v_18703, v_18702);
    env = stack[-6];
    goto v_18429;
v_18430:
    v_18702 = lisp_true;
    goto v_18431;
v_18432:
    goto v_18428;
v_18429:
    goto v_18430;
v_18431:
    v_18702 = CC_simpKprop1(elt(env, 0), v_18703, v_18702);
    stack[0] = v_18702;
    goto v_18391;
v_18391:
    goto v_18218;
v_18381:
    goto v_18463;
v_18459:
    v_18702 = stack[-4];
    v_18703 = qcar(v_18702);
    goto v_18460;
v_18461:
    v_18702 = elt(env, 6); // equiv
    goto v_18462;
v_18463:
    goto v_18459;
v_18460:
    goto v_18461;
v_18462:
    if (v_18703 == v_18702) goto v_18457;
    else goto v_18458;
v_18457:
    goto v_18472;
v_18468:
    goto v_18480;
v_18474:
    stack[-5] = elt(env, 5); // or
    goto v_18475;
v_18476:
    goto v_18489;
v_18483:
    v_18704 = elt(env, 7); // and
    goto v_18484;
v_18485:
    v_18702 = stack[-4];
    v_18702 = qcdr(v_18702);
    v_18703 = qcar(v_18702);
    goto v_18486;
v_18487:
    v_18702 = stack[-4];
    v_18702 = qcdr(v_18702);
    v_18702 = qcdr(v_18702);
    v_18702 = qcar(v_18702);
    goto v_18488;
v_18489:
    goto v_18483;
v_18484:
    goto v_18485;
v_18486:
    goto v_18487;
v_18488:
    stack[-2] = list3(v_18704, v_18703, v_18702);
    env = stack[-6];
    goto v_18477;
v_18478:
    goto v_18505;
v_18499:
    stack[-1] = elt(env, 7); // and
    goto v_18500;
v_18501:
    goto v_18512;
v_18508:
    v_18703 = elt(env, 3); // not
    goto v_18509;
v_18510:
    v_18702 = stack[-4];
    v_18702 = qcdr(v_18702);
    v_18702 = qcar(v_18702);
    goto v_18511;
v_18512:
    goto v_18508;
v_18509:
    goto v_18510;
v_18511:
    stack[0] = list2(v_18703, v_18702);
    env = stack[-6];
    goto v_18502;
v_18503:
    goto v_18522;
v_18518:
    v_18703 = elt(env, 3); // not
    goto v_18519;
v_18520:
    v_18702 = stack[-4];
    v_18702 = qcdr(v_18702);
    v_18702 = qcdr(v_18702);
    v_18702 = qcar(v_18702);
    goto v_18521;
v_18522:
    goto v_18518;
v_18519:
    goto v_18520;
v_18521:
    v_18702 = list2(v_18703, v_18702);
    env = stack[-6];
    goto v_18504;
v_18505:
    goto v_18499;
v_18500:
    goto v_18501;
v_18502:
    goto v_18503;
v_18504:
    v_18702 = list3(stack[-1], stack[0], v_18702);
    env = stack[-6];
    goto v_18479;
v_18480:
    goto v_18474;
v_18475:
    goto v_18476;
v_18477:
    goto v_18478;
v_18479:
    v_18703 = list3(stack[-5], stack[-2], v_18702);
    env = stack[-6];
    goto v_18469;
v_18470:
    v_18702 = stack[-3];
    goto v_18471;
v_18472:
    goto v_18468;
v_18469:
    goto v_18470;
v_18471:
    v_18702 = CC_simpKprop1(elt(env, 0), v_18703, v_18702);
    stack[0] = v_18702;
    goto v_18218;
v_18458:
    goto v_18211;
v_18218:
    v_18702 = stack[0];
    goto v_18209;
v_18210:
    goto v_18544;
v_18540:
    v_18703 = stack[-4];
    goto v_18541;
v_18542:
    v_18702 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18543;
v_18544:
    goto v_18540;
v_18541:
    goto v_18542;
v_18543:
    if (v_18703 == v_18702) goto v_18538;
    else goto v_18539;
v_18538:
    v_18702 = lisp_true;
    goto v_18537;
v_18539:
    goto v_18558;
v_18554:
    v_18703 = stack[-4];
    goto v_18555;
v_18556:
    v_18702 = lisp_true;
    goto v_18557;
v_18558:
    goto v_18554;
v_18555:
    goto v_18556;
v_18557:
    if (equal(v_18703, v_18702)) goto v_18552;
    else goto v_18553;
v_18552:
    v_18702 = lisp_true;
    goto v_18551;
v_18553:
    goto v_18568;
v_18564:
    v_18703 = stack[-4];
    goto v_18565;
v_18566:
    v_18702 = elt(env, 8); // true
    goto v_18567;
v_18568:
    goto v_18564;
v_18565:
    goto v_18566;
v_18567:
    v_18702 = (v_18703 == v_18702 ? lisp_true : nil);
    goto v_18551;
    v_18702 = nil;
v_18551:
    goto v_18537;
    v_18702 = nil;
v_18537:
    if (v_18702 == nil) goto v_18535;
    v_18702 = stack[-3];
    stack[-4] = v_18702;
    goto v_18533;
v_18535:
    goto v_18583;
v_18579:
    v_18703 = stack[-4];
    goto v_18580;
v_18581:
    v_18702 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18582;
v_18583:
    goto v_18579;
v_18580:
    goto v_18581;
v_18582:
    if (v_18703 == v_18702) goto v_18577;
    else goto v_18578;
v_18577:
    v_18702 = lisp_true;
    goto v_18576;
v_18578:
    v_18702 = stack[-4];
    if (v_18702 == nil) goto v_18591;
    else goto v_18592;
v_18591:
    v_18702 = lisp_true;
    goto v_18590;
v_18592:
    goto v_18601;
v_18597:
    v_18703 = stack[-4];
    goto v_18598;
v_18599:
    v_18702 = elt(env, 9); // false
    goto v_18600;
v_18601:
    goto v_18597;
v_18598:
    goto v_18599;
v_18600:
    v_18702 = (v_18703 == v_18702 ? lisp_true : nil);
    goto v_18590;
    v_18702 = nil;
v_18590:
    goto v_18576;
    v_18702 = nil;
v_18576:
    if (v_18702 == nil) goto v_18574;
    v_18702 = stack[-3];
    v_18702 = (v_18702 == nil ? lisp_true : nil);
    stack[-4] = v_18702;
    goto v_18533;
v_18574:
v_18533:
    goto v_18615;
v_18611:
    v_18703 = stack[-4];
    goto v_18612;
v_18613:
    v_18702 = lisp_true;
    goto v_18614;
v_18615:
    goto v_18611;
v_18612:
    goto v_18613;
v_18614:
    if (equal(v_18703, v_18702)) goto v_18609;
    else goto v_18610;
v_18609:
    goto v_18623;
v_18619:
    v_18703 = elt(env, 10); // (or !*true (not !*true))
    goto v_18620;
v_18621:
    v_18702 = lisp_true;
    goto v_18622;
v_18623:
    goto v_18619;
v_18620:
    goto v_18621;
v_18622:
    stack[-4] = v_18703;
    stack[-3] = v_18702;
    goto v_18203;
v_18610:
    v_18702 = stack[-4];
    if (v_18702 == nil) goto v_18628;
    else goto v_18629;
v_18628:
    goto v_18636;
v_18632:
    v_18703 = elt(env, 11); // (and !*true (not !*true))
    goto v_18633;
v_18634:
    v_18702 = lisp_true;
    goto v_18635;
v_18636:
    goto v_18632;
v_18633:
    goto v_18634;
v_18635:
    stack[-4] = v_18703;
    stack[-3] = v_18702;
    goto v_18203;
v_18629:
v_18211:
    v_18702 = stack[-4];
    fn = elt(env, 18); // reval
    v_18702 = (*qfn1(fn))(fn, v_18702);
    env = stack[-6];
    stack[-4] = v_18702;
    goto v_18650;
v_18646:
    v_18703 = stack[-4];
    goto v_18647;
v_18648:
    v_18702 = elt(env, 12); // boolean
    goto v_18649;
v_18650:
    goto v_18646;
v_18647:
    goto v_18648;
v_18649:
    if (!consp(v_18703)) goto v_18644;
    v_18703 = qcar(v_18703);
    if (v_18703 == v_18702) goto v_18643;
    else goto v_18644;
v_18643:
    goto v_18658;
v_18654:
    v_18702 = stack[-4];
    v_18702 = qcdr(v_18702);
    v_18703 = qcar(v_18702);
    goto v_18655;
v_18656:
    v_18702 = stack[-3];
    goto v_18657;
v_18658:
    goto v_18654;
v_18655:
    goto v_18656;
v_18657:
    stack[-4] = v_18703;
    stack[-3] = v_18702;
    goto v_18203;
v_18644:
    goto v_18669;
v_18665:
    v_18702 = stack[-3];
    if (v_18702 == nil) goto v_18673;
    v_18702 = elt(env, 13); // prop!*
    v_18703 = v_18702;
    goto v_18671;
v_18673:
    v_18702 = elt(env, 14); // not_prop!*
    v_18703 = v_18702;
    goto v_18671;
    v_18703 = nil;
v_18671:
    goto v_18666;
v_18667:
    v_18702 = stack[-4];
    goto v_18668;
v_18669:
    goto v_18665;
v_18666:
    goto v_18667;
v_18668:
    v_18702 = list2(v_18703, v_18702);
    env = stack[-6];
    fn = elt(env, 19); // simp
    v_18702 = (*qfn1(fn))(fn, v_18702);
    env = stack[-6];
    v_18702 = qcar(v_18702);
    stack[0] = v_18702;
    goto v_18689;
v_18685:
    v_18703 = stack[-4];
    goto v_18686;
v_18687:
    v_18702 = qvalue(elt(env, 15)); // propvars!*
    goto v_18688;
v_18689:
    goto v_18685;
v_18686:
    goto v_18687;
v_18688:
    v_18702 = Lmember(nil, v_18703, v_18702);
    if (v_18702 == nil) goto v_18683;
    else goto v_18684;
v_18683:
    goto v_18698;
v_18694:
    v_18703 = stack[-4];
    goto v_18695;
v_18696:
    v_18702 = qvalue(elt(env, 15)); // propvars!*
    goto v_18697;
v_18698:
    goto v_18694;
v_18695:
    goto v_18696;
v_18697:
    v_18702 = cons(v_18703, v_18702);
    env = stack[-6];
    qvalue(elt(env, 15)) = v_18702; // propvars!*
    goto v_18682;
v_18684:
v_18682:
    v_18702 = stack[0];
v_18209:
    return onevalue(v_18702);
}



// Code for split_cov_cont_ids

static LispObject CC_split_cov_cont_ids(LispObject env,
                         LispObject v_18204)
{
    env = qenv(env);
    LispObject v_18266, v_18267, v_18268;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18204);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_18204;
// end of prologue
    stack[-2] = nil;
    stack[0] = nil;
v_18212:
    v_18266 = stack[-1];
    if (v_18266 == nil) goto v_18215;
    else goto v_18216;
v_18215:
    goto v_18211;
v_18216:
    v_18266 = stack[-1];
    v_18266 = qcar(v_18266);
    v_18268 = v_18266;
    goto v_18231;
v_18227:
    v_18267 = v_18268;
    goto v_18228;
v_18229:
    v_18266 = elt(env, 1); // minus
    goto v_18230;
v_18231:
    goto v_18227;
v_18228:
    goto v_18229;
v_18230:
    if (!consp(v_18267)) goto v_18225;
    v_18267 = qcar(v_18267);
    if (v_18267 == v_18266) goto v_18224;
    else goto v_18225;
v_18224:
    goto v_18239;
v_18235:
    v_18266 = v_18268;
    v_18266 = qcdr(v_18266);
    v_18267 = qcar(v_18266);
    goto v_18236;
v_18237:
    v_18266 = stack[-2];
    goto v_18238;
v_18239:
    goto v_18235;
v_18236:
    goto v_18237;
v_18238:
    v_18266 = cons(v_18267, v_18266);
    env = stack[-3];
    stack[-2] = v_18266;
    goto v_18223;
v_18225:
    goto v_18251;
v_18247:
    v_18267 = v_18268;
    goto v_18248;
v_18249:
    v_18266 = stack[0];
    goto v_18250;
v_18251:
    goto v_18247;
v_18248:
    goto v_18249;
v_18250:
    v_18266 = cons(v_18267, v_18266);
    env = stack[-3];
    stack[0] = v_18266;
    goto v_18223;
v_18223:
    v_18266 = stack[-1];
    v_18266 = qcdr(v_18266);
    stack[-1] = v_18266;
    goto v_18212;
v_18211:
    goto v_18261;
v_18257:
    v_18266 = stack[-2];
    v_18267 = Lnreverse(nil, v_18266);
    env = stack[-3];
    goto v_18258;
v_18259:
    v_18266 = stack[0];
    v_18266 = Lnreverse(nil, v_18266);
    goto v_18260;
v_18261:
    goto v_18257;
v_18258:
    goto v_18259;
v_18260:
    return list2(v_18267, v_18266);
    return onevalue(v_18266);
}



// Code for st_ad_numsorttree

static LispObject CC_st_ad_numsorttree(LispObject env,
                         LispObject v_18204)
{
    env = qenv(env);
    LispObject v_18222, v_18223;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18204);
    }
// copy arguments values to proper place
    v_18222 = v_18204;
// end of prologue
    fn = elt(env, 1); // st_ad_numsorttree1
    v_18222 = (*qfn1(fn))(fn, v_18222);
    goto v_18216;
v_18212:
    v_18223 = v_18222;
    v_18223 = qcar(v_18223);
    goto v_18213;
v_18214:
    v_18222 = qcdr(v_18222);
    v_18222 = qcar(v_18222);
    goto v_18215;
v_18216:
    goto v_18212;
v_18213:
    goto v_18214;
v_18215:
    return cons(v_18223, v_18222);
    return onevalue(v_18222);
}



// Code for general!-horner!-rule!-mod!-p

static LispObject CC_generalKhornerKruleKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18360, v_18361, v_18362, v_18363, v_18364;
    LispObject fn;
    LispObject v_18208, v_18207, v_18206, v_18205, v_18204;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "general-horner-rule-mod-p");
    va_start(aa, nargs);
    v_18204 = va_arg(aa, LispObject);
    v_18205 = va_arg(aa, LispObject);
    v_18206 = va_arg(aa, LispObject);
    v_18207 = va_arg(aa, LispObject);
    v_18208 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_18208,v_18207,v_18206,v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_18204,v_18205,v_18206,v_18207,v_18208);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_18208;
    stack[-3] = v_18207;
    stack[-4] = v_18206;
    v_18362 = v_18205;
    v_18363 = v_18204;
// end of prologue
v_18203:
    v_18360 = stack[-4];
    if (!consp(v_18360)) goto v_18220;
    else goto v_18221;
v_18220:
    v_18360 = lisp_true;
    goto v_18219;
v_18221:
    v_18360 = stack[-4];
    v_18360 = qcar(v_18360);
    v_18360 = (consp(v_18360) ? nil : lisp_true);
    goto v_18219;
    v_18360 = nil;
v_18219:
    if (v_18360 == nil) goto v_18217;
    v_18360 = lisp_true;
    goto v_18215;
v_18217:
    goto v_18236;
v_18232:
    v_18360 = stack[-4];
    v_18360 = qcar(v_18360);
    v_18360 = qcar(v_18360);
    v_18361 = qcar(v_18360);
    goto v_18233;
v_18234:
    v_18360 = stack[-2];
    goto v_18235;
v_18236:
    goto v_18232;
v_18233:
    goto v_18234;
v_18235:
    v_18360 = (equal(v_18361, v_18360) ? lisp_true : nil);
    v_18360 = (v_18360 == nil ? lisp_true : nil);
    goto v_18215;
    v_18360 = nil;
v_18215:
    if (v_18360 == nil) goto v_18213;
    v_18360 = stack[-3];
    if (v_18360 == nil) goto v_18250;
    else goto v_18251;
v_18250:
    v_18360 = lisp_true;
    goto v_18249;
v_18251:
    v_18360 = stack[-3];
    v_18360 = (LispObject)zerop(v_18360);
    v_18360 = v_18360 ? lisp_true : nil;
    env = stack[-6];
    goto v_18249;
    v_18360 = nil;
v_18249:
    if (v_18360 == nil) goto v_18247;
    v_18360 = stack[-4];
    goto v_18245;
v_18247:
    goto v_18266;
v_18262:
    stack[0] = v_18363;
    goto v_18263;
v_18264:
    goto v_18273;
v_18269:
    v_18360 = stack[-3];
    goto v_18270;
v_18271:
    v_18361 = v_18362;
    goto v_18272;
v_18273:
    goto v_18269;
v_18270:
    goto v_18271;
v_18272:
    fn = elt(env, 1); // general!-expt!-mod!-p
    v_18360 = (*qfn2(fn))(fn, v_18360, v_18361);
    env = stack[-6];
    goto v_18265;
v_18266:
    goto v_18262;
v_18263:
    goto v_18264;
v_18265:
    fn = elt(env, 2); // general!-times!-mod!-p
    v_18360 = (*qfn2(fn))(fn, stack[0], v_18360);
    env = stack[-6];
    v_18363 = v_18360;
    goto v_18281;
v_18277:
    v_18360 = stack[-4];
    goto v_18278;
v_18279:
    v_18361 = v_18363;
    goto v_18280;
v_18281:
    goto v_18277;
v_18278:
    goto v_18279;
v_18280:
    {
        fn = elt(env, 3); // general!-plus!-mod!-p
        return (*qfn2(fn))(fn, v_18360, v_18361);
    }
    v_18360 = nil;
v_18245:
    goto v_18211;
v_18213:
    v_18360 = stack[-4];
    v_18360 = qcar(v_18360);
    v_18360 = qcar(v_18360);
    v_18360 = qcdr(v_18360);
    stack[-5] = v_18360;
    goto v_18304;
v_18294:
    v_18360 = stack[-3];
    if (v_18360 == nil) goto v_18311;
    else goto v_18312;
v_18311:
    v_18360 = lisp_true;
    goto v_18310;
v_18312:
    v_18360 = stack[-3];
    v_18360 = (LispObject)zerop(v_18360);
    v_18360 = v_18360 ? lisp_true : nil;
    env = stack[-6];
    goto v_18310;
    v_18360 = nil;
v_18310:
    if (v_18360 == nil) goto v_18308;
    v_18360 = stack[-4];
    v_18360 = qcar(v_18360);
    v_18360 = qcdr(v_18360);
    v_18363 = v_18360;
    goto v_18306;
v_18308:
    goto v_18329;
v_18325:
    v_18360 = stack[-4];
    v_18360 = qcar(v_18360);
    stack[-1] = qcdr(v_18360);
    goto v_18326;
v_18327:
    goto v_18338;
v_18334:
    stack[0] = v_18363;
    goto v_18335;
v_18336:
    goto v_18345;
v_18341:
    v_18361 = stack[-3];
    goto v_18342;
v_18343:
    goto v_18351;
v_18347:
    goto v_18348;
v_18349:
    v_18360 = stack[-5];
    goto v_18350;
v_18351:
    goto v_18347;
v_18348:
    goto v_18349;
v_18350:
    v_18360 = (LispObject)(intptr_t)((intptr_t)v_18362 - (intptr_t)v_18360 + TAG_FIXNUM);
    goto v_18344;
v_18345:
    goto v_18341;
v_18342:
    goto v_18343;
v_18344:
    fn = elt(env, 1); // general!-expt!-mod!-p
    v_18360 = (*qfn2(fn))(fn, v_18361, v_18360);
    env = stack[-6];
    goto v_18337;
v_18338:
    goto v_18334;
v_18335:
    goto v_18336;
v_18337:
    fn = elt(env, 2); // general!-times!-mod!-p
    v_18360 = (*qfn2(fn))(fn, stack[0], v_18360);
    env = stack[-6];
    goto v_18328;
v_18329:
    goto v_18325;
v_18326:
    goto v_18327;
v_18328:
    fn = elt(env, 3); // general!-plus!-mod!-p
    v_18360 = (*qfn2(fn))(fn, stack[-1], v_18360);
    env = stack[-6];
    v_18363 = v_18360;
    goto v_18306;
    v_18363 = nil;
v_18306:
    goto v_18295;
v_18296:
    v_18362 = stack[-5];
    goto v_18297;
v_18298:
    v_18360 = stack[-4];
    v_18364 = qcdr(v_18360);
    goto v_18299;
v_18300:
    v_18361 = stack[-3];
    goto v_18301;
v_18302:
    v_18360 = stack[-2];
    goto v_18303;
v_18304:
    goto v_18294;
v_18295:
    goto v_18296;
v_18297:
    goto v_18298;
v_18299:
    goto v_18300;
v_18301:
    goto v_18302;
v_18303:
    stack[-4] = v_18364;
    stack[-3] = v_18361;
    stack[-2] = v_18360;
    goto v_18203;
    goto v_18211;
    v_18360 = nil;
v_18211:
    return onevalue(v_18360);
}



// Code for gitimes!:

static LispObject CC_gitimesT(LispObject env,
                         LispObject v_18204, LispObject v_18205)
{
    env = qenv(env);
    LispObject v_18273, v_18274, v_18275, v_18276;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18204,v_18205);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_18273 = v_18205;
    v_18274 = v_18204;
// end of prologue
    v_18275 = v_18274;
    v_18275 = qcdr(v_18275);
    v_18276 = qcar(v_18275);
    v_18274 = qcdr(v_18274);
    v_18275 = qcdr(v_18274);
    v_18274 = v_18273;
    v_18274 = qcdr(v_18274);
    v_18274 = qcar(v_18274);
    v_18273 = qcdr(v_18273);
    v_18273 = qcdr(v_18273);
    stack[-4] = v_18276;
    stack[-3] = v_18275;
    stack[-2] = v_18274;
    stack[-1] = v_18273;
    goto v_18228;
v_18224:
    goto v_18234;
v_18230:
    goto v_18240;
v_18236:
    v_18274 = stack[-4];
    goto v_18237;
v_18238:
    v_18273 = stack[-2];
    goto v_18239;
v_18240:
    goto v_18236;
v_18237:
    goto v_18238;
v_18239:
    stack[0] = times2(v_18274, v_18273);
    env = stack[-5];
    goto v_18231;
v_18232:
    goto v_18248;
v_18244:
    v_18274 = stack[-3];
    goto v_18245;
v_18246:
    v_18273 = stack[-1];
    goto v_18247;
v_18248:
    goto v_18244;
v_18245:
    goto v_18246;
v_18247:
    v_18273 = times2(v_18274, v_18273);
    env = stack[-5];
    goto v_18233;
v_18234:
    goto v_18230;
v_18231:
    goto v_18232;
v_18233:
    stack[0] = difference2(stack[0], v_18273);
    env = stack[-5];
    goto v_18225;
v_18226:
    goto v_18256;
v_18252:
    goto v_18262;
v_18258:
    v_18274 = stack[-4];
    goto v_18259;
v_18260:
    v_18273 = stack[-1];
    goto v_18261;
v_18262:
    goto v_18258;
v_18259:
    goto v_18260;
v_18261:
    stack[-1] = times2(v_18274, v_18273);
    env = stack[-5];
    goto v_18253;
v_18254:
    goto v_18270;
v_18266:
    v_18274 = stack[-2];
    goto v_18267;
v_18268:
    v_18273 = stack[-3];
    goto v_18269;
v_18270:
    goto v_18266;
v_18267:
    goto v_18268;
v_18269:
    v_18273 = times2(v_18274, v_18273);
    env = stack[-5];
    goto v_18255;
v_18256:
    goto v_18252;
v_18253:
    goto v_18254;
v_18255:
    v_18273 = plus2(stack[-1], v_18273);
    env = stack[-5];
    goto v_18227;
v_18228:
    goto v_18224;
v_18225:
    goto v_18226;
v_18227:
    {
        LispObject v_18282 = stack[0];
        fn = elt(env, 1); // mkgi
        return (*qfn2(fn))(fn, v_18282, v_18273);
    }
}



// Code for !*a2f

static LispObject CC_Ha2f(LispObject env,
                         LispObject v_18204)
{
    env = qenv(env);
    LispObject v_18209;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_18204);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_18209 = v_18204;
// end of prologue
    fn = elt(env, 1); // simp!*
    v_18209 = (*qfn1(fn))(fn, v_18209);
    env = stack[0];
    {
        fn = elt(env, 2); // !*q2f
        return (*qfn1(fn))(fn, v_18209);
    }
}



// Code for letexprn

static LispObject CC_letexprn(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18777, v_18778, v_18779;
    LispObject fn;
    LispObject v_18209, v_18208, v_18207, v_18206, v_18205, v_18204;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "letexprn");
    va_start(aa, nargs);
    v_18204 = va_arg(aa, LispObject);
    v_18205 = va_arg(aa, LispObject);
    v_18206 = va_arg(aa, LispObject);
    v_18207 = va_arg(aa, LispObject);
    v_18208 = va_arg(aa, LispObject);
    v_18209 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_18209,v_18208,v_18207,v_18206,v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_18204,v_18205,v_18206,v_18207,v_18208,v_18209);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-1] = v_18209;
    stack[-2] = v_18208;
    stack[-3] = v_18207;
    stack[-4] = v_18206;
    stack[-5] = v_18205;
    stack[-6] = v_18204;
// end of prologue
    goto v_18223;
v_18219:
    v_18777 = stack[-3];
    v_18778 = qcdr(v_18777);
    goto v_18220;
v_18221:
    v_18777 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18222;
v_18223:
    goto v_18219;
v_18220:
    goto v_18221;
v_18222:
    if (v_18778 == v_18777) goto v_18218;
    goto v_18236;
v_18228:
    v_18777 = stack[-3];
    v_18777 = qcar(v_18777);
    fn = elt(env, 14); // let!-prepf
    stack[-1] = (*qfn1(fn))(fn, v_18777);
    env = stack[-8];
    goto v_18229;
v_18230:
    goto v_18247;
v_18241:
    stack[0] = elt(env, 1); // times
    goto v_18242;
v_18243:
    v_18777 = stack[-3];
    v_18777 = qcdr(v_18777);
    fn = elt(env, 14); // let!-prepf
    v_18778 = (*qfn1(fn))(fn, v_18777);
    env = stack[-8];
    goto v_18244;
v_18245:
    v_18777 = stack[-5];
    goto v_18246;
v_18247:
    goto v_18241;
v_18242:
    goto v_18243;
v_18244:
    goto v_18245;
v_18246:
    v_18779 = list3(stack[0], v_18778, v_18777);
    env = stack[-8];
    goto v_18231;
v_18232:
    v_18778 = stack[-4];
    goto v_18233;
v_18234:
    v_18777 = stack[-2];
    goto v_18235;
v_18236:
    goto v_18228;
v_18229:
    goto v_18230;
v_18231:
    goto v_18232;
v_18233:
    goto v_18234;
v_18235:
    {
        LispObject v_18788 = stack[-1];
        fn = elt(env, 15); // let2
        return (*qfnn(fn))(fn, 4, v_18788, v_18779, v_18778, v_18777);
    }
v_18218:
    v_18777 = stack[-3];
    v_18777 = qcar(v_18777);
    stack[-3] = v_18777;
    v_18777 = qcdr(v_18777);
    if (v_18777 == nil) goto v_18256;
    goto v_18269;
v_18261:
    v_18777 = stack[-3];
    v_18777 = qcar(v_18777);
    v_18777 = ncons(v_18777);
    env = stack[-8];
    fn = elt(env, 14); // let!-prepf
    stack[-1] = (*qfn1(fn))(fn, v_18777);
    env = stack[-8];
    goto v_18262;
v_18263:
    goto v_18281;
v_18275:
    stack[0] = elt(env, 2); // difference
    goto v_18276;
v_18277:
    goto v_18278;
v_18279:
    v_18777 = stack[-3];
    v_18777 = qcdr(v_18777);
    fn = elt(env, 14); // let!-prepf
    v_18777 = (*qfn1(fn))(fn, v_18777);
    env = stack[-8];
    goto v_18280;
v_18281:
    goto v_18275;
v_18276:
    goto v_18277;
v_18278:
    goto v_18279;
v_18280:
    v_18779 = list3(stack[0], stack[-5], v_18777);
    env = stack[-8];
    goto v_18264;
v_18265:
    v_18778 = stack[-4];
    goto v_18266;
v_18267:
    v_18777 = stack[-2];
    goto v_18268;
v_18269:
    goto v_18261;
v_18262:
    goto v_18263;
v_18264:
    goto v_18265;
v_18266:
    goto v_18267;
v_18268:
    {
        LispObject v_18789 = stack[-1];
        fn = elt(env, 15); // let2
        return (*qfnn(fn))(fn, 4, v_18789, v_18779, v_18778, v_18777);
    }
v_18256:
    v_18777 = stack[-3];
    fn = elt(env, 16); // kernlp
    v_18777 = (*qfn1(fn))(fn, v_18777);
    env = stack[-8];
    stack[0] = v_18777;
    if (v_18777 == nil) goto v_18289;
    else goto v_18290;
v_18289:
    v_18777 = stack[-3];
    fn = elt(env, 17); // term!-split
    v_18777 = (*qfn1(fn))(fn, v_18777);
    env = stack[-8];
    stack[0] = v_18777;
    goto v_18304;
v_18296:
    v_18777 = stack[0];
    v_18777 = qcar(v_18777);
    fn = elt(env, 14); // let!-prepf
    stack[-3] = (*qfn1(fn))(fn, v_18777);
    env = stack[-8];
    goto v_18297;
v_18298:
    goto v_18315;
v_18309:
    stack[-1] = elt(env, 2); // difference
    goto v_18310;
v_18311:
    goto v_18312;
v_18313:
    v_18777 = stack[0];
    v_18777 = qcdr(v_18777);
    fn = elt(env, 14); // let!-prepf
    v_18777 = (*qfn1(fn))(fn, v_18777);
    env = stack[-8];
    goto v_18314;
v_18315:
    goto v_18309;
v_18310:
    goto v_18311;
v_18312:
    goto v_18313;
v_18314:
    v_18779 = list3(stack[-1], stack[-5], v_18777);
    env = stack[-8];
    goto v_18299;
v_18300:
    v_18778 = stack[-4];
    goto v_18301;
v_18302:
    v_18777 = stack[-2];
    goto v_18303;
v_18304:
    goto v_18296;
v_18297:
    goto v_18298;
v_18299:
    goto v_18300;
v_18301:
    goto v_18302;
v_18303:
    {
        LispObject v_18790 = stack[-3];
        fn = elt(env, 15); // let2
        return (*qfnn(fn))(fn, 4, v_18790, v_18779, v_18778, v_18777);
    }
v_18290:
    goto v_18329;
v_18325:
    v_18778 = stack[0];
    goto v_18326;
v_18327:
    v_18777 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18328;
v_18329:
    goto v_18325;
v_18326:
    goto v_18327;
v_18328:
    if (v_18778 == v_18777) goto v_18324;
    goto v_18341;
v_18333:
    goto v_18348;
v_18344:
    v_18778 = stack[-3];
    goto v_18345;
v_18346:
    v_18777 = stack[0];
    goto v_18347;
v_18348:
    goto v_18344;
v_18345:
    goto v_18346;
v_18347:
    fn = elt(env, 18); // quotf!*
    v_18777 = (*qfn2(fn))(fn, v_18778, v_18777);
    env = stack[-8];
    fn = elt(env, 14); // let!-prepf
    stack[-3] = (*qfn1(fn))(fn, v_18777);
    env = stack[-8];
    goto v_18334;
v_18335:
    goto v_18358;
v_18352:
    stack[-1] = elt(env, 3); // quotient
    goto v_18353;
v_18354:
    goto v_18355;
v_18356:
    v_18777 = stack[0];
    fn = elt(env, 14); // let!-prepf
    v_18777 = (*qfn1(fn))(fn, v_18777);
    env = stack[-8];
    goto v_18357;
v_18358:
    goto v_18352;
v_18353:
    goto v_18354;
v_18355:
    goto v_18356;
v_18357:
    v_18779 = list3(stack[-1], stack[-5], v_18777);
    env = stack[-8];
    goto v_18336;
v_18337:
    v_18778 = stack[-4];
    goto v_18338;
v_18339:
    v_18777 = stack[-2];
    goto v_18340;
v_18341:
    goto v_18333;
v_18334:
    goto v_18335;
v_18336:
    goto v_18337;
v_18338:
    goto v_18339;
v_18340:
    {
        LispObject v_18791 = stack[-3];
        fn = elt(env, 15); // let2
        return (*qfnn(fn))(fn, 4, v_18791, v_18779, v_18778, v_18777);
    }
v_18324:
    v_18777 = stack[-3];
    fn = elt(env, 19); // klistt
    v_18777 = (*qfn1(fn))(fn, v_18777);
    env = stack[-8];
    stack[-3] = v_18777;
    goto v_18374;
v_18368:
    stack[-7] = stack[-4];
    goto v_18369;
v_18370:
    v_18777 = qvalue(elt(env, 4)); // mcond!*
    if (v_18777 == nil) goto v_18379;
    v_18777 = qvalue(elt(env, 4)); // mcond!*
    stack[0] = v_18777;
    goto v_18377;
v_18379:
    v_18777 = lisp_true;
    stack[0] = v_18777;
    goto v_18377;
    stack[0] = nil;
v_18377:
    goto v_18371;
v_18372:
    goto v_18390;
v_18386:
    v_18778 = stack[-5];
    goto v_18387;
v_18388:
    v_18777 = nil;
    goto v_18389;
v_18390:
    goto v_18386;
v_18387:
    goto v_18388;
v_18389:
    v_18777 = list2(v_18778, v_18777);
    env = stack[-8];
    goto v_18373;
v_18374:
    goto v_18368;
v_18369:
    goto v_18370;
v_18371:
    goto v_18372;
v_18373:
    v_18777 = acons(stack[-7], stack[0], v_18777);
    env = stack[-8];
    stack[0] = v_18777;
    v_18777 = stack[-3];
    v_18777 = qcdr(v_18777);
    if (v_18777 == nil) goto v_18396;
    fn = elt(env, 20); // rmsubs
    v_18777 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_18407;
v_18401:
    goto v_18413;
v_18409:
    v_18778 = stack[-3];
    goto v_18410;
v_18411:
    v_18777 = stack[0];
    goto v_18412;
v_18413:
    goto v_18409;
v_18410:
    goto v_18411;
v_18412:
    v_18779 = cons(v_18778, v_18777);
    env = stack[-8];
    goto v_18402;
v_18403:
    v_18778 = qvalue(elt(env, 5)); // !*match
    goto v_18404;
v_18405:
    v_18777 = stack[-2];
    goto v_18406;
v_18407:
    goto v_18401;
v_18402:
    goto v_18403;
v_18404:
    goto v_18405;
v_18406:
    fn = elt(env, 21); // xadd!*
    v_18777 = (*qfnn(fn))(fn, 3, v_18779, v_18778, v_18777);
    env = stack[-8];
    qvalue(elt(env, 5)) = v_18777; // !*match
    goto v_18214;
v_18396:
    v_18777 = stack[-4];
    if (v_18777 == nil) goto v_18422;
    else goto v_18423;
v_18422:
    goto v_18429;
v_18425:
    v_18777 = stack[-3];
    v_18777 = qcar(v_18777);
    v_18778 = qcdr(v_18777);
    goto v_18426;
v_18427:
    v_18777 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_18428;
v_18429:
    goto v_18425;
v_18426:
    goto v_18427;
v_18428:
    v_18777 = (v_18778 == v_18777 ? lisp_true : nil);
    goto v_18421;
v_18423:
    v_18777 = nil;
    goto v_18421;
    v_18777 = nil;
v_18421:
    if (v_18777 == nil) goto v_18419;
    v_18777 = stack[-3];
    v_18777 = qcar(v_18777);
    v_18777 = qcar(v_18777);
    stack[-3] = v_18777;
    v_18777 = stack[-1];
    if (v_18777 == nil) goto v_18447;
    else goto v_18448;
v_18447:
    v_18777 = qvalue(elt(env, 4)); // mcond!*
    if (v_18777 == nil) goto v_18452;
    else goto v_18453;
v_18452:
    v_18777 = lisp_true;
    goto v_18451;
v_18453:
    goto v_18466;
v_18462:
    v_18778 = qvalue(elt(env, 4)); // mcond!*
    goto v_18463;
v_18464:
    v_18777 = lisp_true;
    goto v_18465;
v_18466:
    goto v_18462;
v_18463:
    goto v_18464;
v_18465:
    if (v_18778 == v_18777) goto v_18460;
    else goto v_18461;
v_18460:
    v_18777 = lisp_true;
    goto v_18459;
v_18461:
    goto v_18477;
v_18473:
    v_18778 = stack[-3];
    goto v_18474;
v_18475:
    v_18777 = qvalue(elt(env, 4)); // mcond!*
    goto v_18476;
v_18477:
    goto v_18473;
v_18474:
    goto v_18475;
v_18476:
    fn = elt(env, 22); // smember
    v_18777 = (*qfn2(fn))(fn, v_18778, v_18777);
    env = stack[-8];
    v_18777 = (v_18777 == nil ? lisp_true : nil);
    goto v_18459;
    v_18777 = nil;
v_18459:
    goto v_18451;
    v_18777 = nil;
v_18451:
    goto v_18446;
v_18448:
    v_18777 = nil;
    goto v_18446;
    v_18777 = nil;
v_18446:
    if (v_18777 == nil) goto v_18444;
    v_18777 = stack[-3];
    if (!consp(v_18777)) goto v_18486;
    else goto v_18487;
v_18486:
    goto v_18498;
v_18494:
    v_18778 = stack[-3];
    goto v_18495;
v_18496:
    v_18777 = elt(env, 6); // used!*
    goto v_18497;
v_18498:
    goto v_18494;
v_18495:
    goto v_18496;
v_18497:
    v_18777 = Lflagp(nil, v_18778, v_18777);
    env = stack[-8];
    if (v_18777 == nil) goto v_18492;
    fn = elt(env, 20); // rmsubs
    v_18777 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_18490;
v_18492:
    goto v_18490;
v_18490:
    goto v_18485;
v_18487:
    goto v_18512;
v_18508:
    stack[0] = elt(env, 6); // used!*
    goto v_18509;
v_18510:
    v_18777 = stack[-3];
    fn = elt(env, 23); // fkern
    v_18777 = (*qfn1(fn))(fn, v_18777);
    env = stack[-8];
    v_18777 = qcdr(v_18777);
    v_18777 = qcdr(v_18777);
    goto v_18511;
v_18512:
    goto v_18508;
v_18509:
    goto v_18510;
v_18511:
    v_18777 = Lmemq(nil, stack[0], v_18777);
    if (v_18777 == nil) goto v_18507;
    else goto v_18505;
v_18507:
    goto v_18524;
v_18520:
    v_18777 = stack[-3];
    v_18778 = qcar(v_18777);
    goto v_18521;
v_18522:
    v_18777 = elt(env, 7); // df
    goto v_18523;
v_18524:
    goto v_18520;
v_18521:
    goto v_18522;
v_18523:
    if (v_18778 == v_18777) goto v_18505;
    goto v_18506;
v_18505:
    fn = elt(env, 20); // rmsubs
    v_18777 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_18485;
v_18506:
v_18485:
    goto v_18536;
v_18530:
    v_18779 = stack[-3];
    goto v_18531;
v_18532:
    v_18778 = stack[-5];
    goto v_18533;
v_18534:
    v_18777 = stack[-2];
    goto v_18535;
v_18536:
    goto v_18530;
v_18531:
    goto v_18532;
v_18533:
    goto v_18534;
v_18535:
    fn = elt(env, 24); // setk1
    v_18777 = (*qfnn(fn))(fn, 3, v_18779, v_18778, v_18777);
    goto v_18442;
v_18444:
    v_18777 = stack[-3];
    if (!consp(v_18777)) goto v_18540;
    else goto v_18541;
v_18540:
    v_18777 = stack[-6];
    {
        fn = elt(env, 25); // errpri1
        return (*qfn1(fn))(fn, v_18777);
    }
v_18541:
    fn = elt(env, 20); // rmsubs
    v_18777 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_18555;
v_18549:
    v_18777 = stack[-3];
    stack[-4] = qcar(v_18777);
    goto v_18550;
v_18551:
    stack[-1] = elt(env, 8); // opmtch
    goto v_18552;
v_18553:
    goto v_18566;
v_18560:
    goto v_18572;
v_18568:
    v_18777 = stack[-3];
    v_18778 = qcdr(v_18777);
    goto v_18569;
v_18570:
    v_18777 = stack[0];
    goto v_18571;
v_18572:
    goto v_18568;
v_18569:
    goto v_18570;
v_18571:
    v_18779 = cons(v_18778, v_18777);
    env = stack[-8];
    goto v_18561;
v_18562:
    v_18777 = stack[-3];
    v_18777 = qcar(v_18777);
    if (!symbolp(v_18777)) v_18778 = nil;
    else { v_18778 = qfastgets(v_18777);
           if (v_18778 != nil) { v_18778 = elt(v_18778, 9); // opmtch
#ifdef RECORD_GET
             if (v_18778 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_18778 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_18778 == SPID_NOPROP) v_18778 = nil; }}
#endif
    goto v_18563;
v_18564:
    v_18777 = stack[-2];
    goto v_18565;
v_18566:
    goto v_18560;
v_18561:
    goto v_18562;
v_18563:
    goto v_18564;
v_18565:
    fn = elt(env, 21); // xadd!*
    v_18777 = (*qfnn(fn))(fn, 3, v_18779, v_18778, v_18777);
    env = stack[-8];
    goto v_18554;
v_18555:
    goto v_18549;
v_18550:
    goto v_18551;
v_18552:
    goto v_18553;
v_18554:
    v_18777 = Lputprop(nil, 3, stack[-4], stack[-1], v_18777);
    goto v_18442;
v_18442:
    goto v_18394;
v_18419:
    fn = elt(env, 20); // rmsubs
    v_18777 = (*qfnn(fn))(fn, 0);
    env = stack[-8];
    goto v_18595;
v_18591:
    v_18778 = stack[-5];
    goto v_18592;
v_18593:
    v_18777 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18594;
v_18595:
    goto v_18591;
v_18592:
    goto v_18593;
v_18594:
    if (v_18778 == v_18777) goto v_18589;
    else goto v_18590;
v_18589:
    v_18777 = stack[-4];
    if (v_18777 == nil) goto v_18600;
    else goto v_18601;
v_18600:
    v_18777 = stack[-1];
    v_18777 = (v_18777 == nil ? lisp_true : nil);
    goto v_18599;
v_18601:
    v_18777 = nil;
    goto v_18599;
    v_18777 = nil;
v_18599:
    goto v_18588;
v_18590:
    v_18777 = nil;
    goto v_18588;
    v_18777 = nil;
v_18588:
    if (v_18777 == nil) goto v_18586;
    goto v_18618;
v_18612:
    v_18777 = stack[-3];
    v_18779 = qcar(v_18777);
    goto v_18613;
v_18614:
    v_18778 = qvalue(elt(env, 9)); // asymplis!*
    goto v_18615;
v_18616:
    v_18777 = stack[-2];
    goto v_18617;
v_18618:
    goto v_18612;
v_18613:
    goto v_18614;
v_18615:
    goto v_18616;
v_18617:
    fn = elt(env, 26); // xadd
    v_18777 = (*qfnn(fn))(fn, 3, v_18779, v_18778, v_18777);
    env = stack[-8];
    qvalue(elt(env, 9)) = v_18777; // asymplis!*
    goto v_18630;
v_18624:
    goto v_18638;
v_18632:
    v_18777 = stack[-3];
    v_18777 = qcar(v_18777);
    v_18779 = qcar(v_18777);
    goto v_18633;
v_18634:
    v_18777 = stack[-3];
    v_18777 = qcar(v_18777);
    v_18778 = qcdr(v_18777);
    goto v_18635;
v_18636:
    v_18777 = stack[0];
    goto v_18637;
v_18638:
    goto v_18632;
v_18633:
    goto v_18634;
v_18635:
    goto v_18636;
v_18637:
    v_18779 = list2star(v_18779, v_18778, v_18777);
    env = stack[-8];
    goto v_18625;
v_18626:
    v_18778 = qvalue(elt(env, 10)); // powlis!*
    goto v_18627;
v_18628:
    v_18777 = elt(env, 11); // replace
    goto v_18629;
v_18630:
    goto v_18624;
v_18625:
    goto v_18626;
v_18627:
    goto v_18628;
v_18629:
    fn = elt(env, 26); // xadd
    v_18777 = (*qfnn(fn))(fn, 3, v_18779, v_18778, v_18777);
    env = stack[-8];
    qvalue(elt(env, 10)) = v_18777; // powlis!*
    goto v_18584;
v_18586:
    v_18777 = stack[-4];
    if (v_18777 == nil) goto v_18650;
    else goto v_18648;
v_18650:
    goto v_18661;
v_18657:
    v_18777 = stack[0];
    v_18777 = qcar(v_18777);
    v_18778 = qcdr(v_18777);
    goto v_18658;
v_18659:
    v_18777 = lisp_true;
    goto v_18660;
v_18661:
    goto v_18657;
v_18658:
    goto v_18659;
v_18660:
    if (v_18778 == v_18777) goto v_18656;
    v_18777 = lisp_true;
    goto v_18654;
v_18656:
    v_18777 = qvalue(elt(env, 12)); // frasc!*
    goto v_18654;
    v_18777 = nil;
v_18654:
    if (v_18777 == nil) goto v_18652;
    else goto v_18648;
v_18652:
    goto v_18649;
v_18648:
    goto v_18677;
v_18671:
    goto v_18683;
v_18679:
    v_18777 = stack[-3];
    v_18778 = qcar(v_18777);
    goto v_18680;
v_18681:
    v_18777 = stack[0];
    goto v_18682;
v_18683:
    goto v_18679;
v_18680:
    goto v_18681;
v_18682:
    v_18779 = cons(v_18778, v_18777);
    env = stack[-8];
    goto v_18672;
v_18673:
    v_18778 = qvalue(elt(env, 13)); // powlis1!*
    goto v_18674;
v_18675:
    v_18777 = stack[-2];
    goto v_18676;
v_18677:
    goto v_18671;
v_18672:
    goto v_18673;
v_18674:
    goto v_18675;
v_18676:
    fn = elt(env, 26); // xadd
    v_18777 = (*qfnn(fn))(fn, 3, v_18779, v_18778, v_18777);
    env = stack[-8];
    qvalue(elt(env, 13)) = v_18777; // powlis1!*
    goto v_18584;
v_18649:
    v_18777 = stack[-2];
    if (v_18777 == nil) goto v_18693;
    else goto v_18694;
v_18693:
    goto v_18704;
v_18700:
    v_18777 = stack[-3];
    v_18777 = qcar(v_18777);
    v_18778 = qcar(v_18777);
    goto v_18701;
v_18702:
    v_18777 = qvalue(elt(env, 9)); // asymplis!*
    goto v_18703;
v_18704:
    goto v_18700;
v_18701:
    goto v_18702;
v_18703:
    v_18777 = Lassoc(nil, v_18778, v_18777);
    v_18778 = v_18777;
    if (v_18777 == nil) goto v_18698;
    else goto v_18699;
v_18698:
    v_18777 = nil;
    goto v_18697;
v_18699:
    goto v_18717;
v_18713:
    goto v_18714;
v_18715:
    v_18777 = stack[-3];
    v_18777 = qcar(v_18777);
    goto v_18716;
v_18717:
    goto v_18713;
v_18714:
    goto v_18715;
v_18716:
    v_18777 = (equal(v_18778, v_18777) ? lisp_true : nil);
    goto v_18697;
    v_18777 = nil;
v_18697:
    goto v_18692;
v_18694:
    v_18777 = nil;
    goto v_18692;
    v_18777 = nil;
v_18692:
    if (v_18777 == nil) goto v_18690;
    goto v_18730;
v_18726:
    v_18777 = stack[-3];
    v_18777 = qcar(v_18777);
    v_18778 = qcar(v_18777);
    goto v_18727;
v_18728:
    v_18777 = qvalue(elt(env, 9)); // asymplis!*
    goto v_18729;
v_18730:
    goto v_18726;
v_18727:
    goto v_18728;
v_18729:
    fn = elt(env, 27); // delasc
    v_18777 = (*qfn2(fn))(fn, v_18778, v_18777);
    env = stack[-8];
    qvalue(elt(env, 9)) = v_18777; // asymplis!*
    goto v_18584;
v_18690:
    goto v_18744;
v_18738:
    goto v_18752;
v_18746:
    v_18777 = stack[-3];
    v_18777 = qcar(v_18777);
    v_18779 = qcar(v_18777);
    goto v_18747;
v_18748:
    v_18777 = stack[-3];
    v_18777 = qcar(v_18777);
    v_18778 = qcdr(v_18777);
    goto v_18749;
v_18750:
    v_18777 = stack[0];
    goto v_18751;
v_18752:
    goto v_18746;
v_18747:
    goto v_18748;
v_18749:
    goto v_18750;
v_18751:
    v_18779 = list2star(v_18779, v_18778, v_18777);
    env = stack[-8];
    goto v_18739;
v_18740:
    v_18778 = qvalue(elt(env, 10)); // powlis!*
    goto v_18741;
v_18742:
    v_18777 = stack[-2];
    goto v_18743;
v_18744:
    goto v_18738;
v_18739:
    goto v_18740;
v_18741:
    goto v_18742;
v_18743:
    fn = elt(env, 26); // xadd
    v_18777 = (*qfnn(fn))(fn, 3, v_18779, v_18778, v_18777);
    env = stack[-8];
    qvalue(elt(env, 10)) = v_18777; // powlis!*
    v_18777 = stack[-2];
    if (v_18777 == nil) goto v_18765;
    goto v_18772;
v_18768:
    v_18777 = stack[-3];
    v_18777 = qcar(v_18777);
    v_18778 = qcar(v_18777);
    goto v_18769;
v_18770:
    v_18777 = qvalue(elt(env, 9)); // asymplis!*
    goto v_18771;
v_18772:
    goto v_18768;
v_18769:
    goto v_18770;
v_18771:
    fn = elt(env, 27); // delasc
    v_18777 = (*qfn2(fn))(fn, v_18778, v_18777);
    env = stack[-8];
    qvalue(elt(env, 9)) = v_18777; // asymplis!*
    goto v_18763;
v_18765:
v_18763:
    goto v_18584;
v_18584:
    goto v_18394;
v_18394:
    v_18777 = nil;
v_18214:
    return onevalue(v_18777);
}



// Code for triplesetprolongedby

static LispObject CC_triplesetprolongedby(LispObject env,
                         LispObject v_18204, LispObject v_18205)
{
    env = qenv(env);
    LispObject v_18283, v_18284;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18204,v_18205);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_18205;
    v_18283 = v_18204;
// end of prologue
    goto v_18214;
v_18210:
    v_18284 = v_18283;
    goto v_18211;
v_18212:
    v_18283 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_18213;
v_18214:
    goto v_18210;
v_18211:
    goto v_18212;
v_18213:
    v_18283 = *(LispObject *)((char *)v_18284 + (CELL-TAG_VECTOR) + (((intptr_t)v_18283-TAG_FIXNUM)/(16/CELL)));
    stack[-2] = v_18283;
v_18220:
    v_18283 = stack[-2];
    v_18283 = qcar(v_18283);
    if (v_18283 == nil) goto v_18223;
    goto v_18234;
v_18230:
    v_18283 = stack[-2];
    v_18284 = qcar(v_18283);
    goto v_18231;
v_18232:
    v_18283 = stack[-1];
    goto v_18233;
v_18234:
    goto v_18230;
v_18231:
    goto v_18232;
v_18233:
    v_18283 = (LispObject)greaterp2(v_18284, v_18283);
    v_18283 = v_18283 ? lisp_true : nil;
    env = stack[-3];
    if (v_18283 == nil) goto v_18223;
    goto v_18224;
v_18223:
    goto v_18219;
v_18224:
    v_18283 = stack[-2];
    v_18283 = qcdr(v_18283);
    stack[-2] = v_18283;
    goto v_18220;
v_18219:
    v_18283 = stack[-2];
    v_18283 = qcar(v_18283);
    if (v_18283 == nil) goto v_18244;
    goto v_18254;
v_18250:
    v_18283 = stack[-2];
    v_18284 = qcar(v_18283);
    goto v_18251;
v_18252:
    v_18283 = stack[-1];
    goto v_18253;
v_18254:
    goto v_18250;
v_18251:
    goto v_18252;
v_18253:
    if (equal(v_18284, v_18283)) goto v_18249;
    else goto v_18244;
v_18249:
    goto v_18245;
v_18244:
    goto v_18263;
v_18259:
    goto v_18269;
v_18265:
    stack[0] = stack[-2];
    goto v_18266;
v_18267:
    goto v_18276;
v_18272:
    v_18283 = stack[-2];
    v_18284 = qcar(v_18283);
    goto v_18273;
v_18274:
    v_18283 = stack[-2];
    v_18283 = qcdr(v_18283);
    goto v_18275;
v_18276:
    goto v_18272;
v_18273:
    goto v_18274;
v_18275:
    v_18283 = cons(v_18284, v_18283);
    env = stack[-3];
    goto v_18268;
v_18269:
    goto v_18265;
v_18266:
    goto v_18267;
v_18268:
    v_18284 = Lrplacd(nil, stack[0], v_18283);
    env = stack[-3];
    goto v_18260;
v_18261:
    v_18283 = stack[-1];
    goto v_18262;
v_18263:
    goto v_18259;
v_18260:
    goto v_18261;
v_18262:
    v_18283 = Lrplaca(nil, v_18284, v_18283);
    goto v_18243;
v_18245:
v_18243:
    v_18283 = nil;
    return onevalue(v_18283);
}



// Code for ofsf_facequal!*

static LispObject CC_ofsf_facequalH(LispObject env,
                         LispObject v_18204, LispObject v_18205)
{
    env = qenv(env);
    LispObject v_18242, v_18243, v_18244;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18243 = v_18205;
    v_18244 = v_18204;
// end of prologue
    v_18242 = qvalue(elt(env, 1)); // !*rlsifac
    if (v_18242 == nil) goto v_18210;
    v_18242 = qvalue(elt(env, 2)); // !*rlsiexpla
    if (v_18242 == nil) goto v_18214;
    else goto v_18213;
v_18214:
    v_18242 = qvalue(elt(env, 3)); // !*rlsiexpl
    if (v_18242 == nil) goto v_18216;
    goto v_18224;
v_18220:
    goto v_18221;
v_18222:
    v_18242 = elt(env, 4); // or
    goto v_18223;
v_18224:
    goto v_18220;
v_18221:
    goto v_18222;
v_18223:
    if (v_18243 == v_18242) goto v_18219;
    else goto v_18216;
v_18219:
    goto v_18213;
v_18216:
    goto v_18210;
v_18213:
    v_18242 = v_18244;
    {
        fn = elt(env, 6); // ofsf_facequal
        return (*qfn1(fn))(fn, v_18242);
    }
v_18210:
    goto v_18238;
v_18232:
    v_18243 = elt(env, 5); // equal
    goto v_18233;
v_18234:
    goto v_18235;
v_18236:
    v_18242 = nil;
    goto v_18237;
v_18238:
    goto v_18232;
v_18233:
    goto v_18234;
v_18235:
    goto v_18236;
v_18237:
    return list3(v_18243, v_18244, v_18242);
    v_18242 = nil;
    return onevalue(v_18242);
}



// Code for talp_specsubt

static LispObject CC_talp_specsubt(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18314, v_18315, v_18316;
    LispObject fn;
    LispObject v_18206, v_18205, v_18204;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_specsubt");
    va_start(aa, nargs);
    v_18204 = va_arg(aa, LispObject);
    v_18205 = va_arg(aa, LispObject);
    v_18206 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_18206,v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_18204,v_18205,v_18206);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[0] = v_18206;
    stack[-4] = v_18205;
    stack[-5] = v_18204;
// end of prologue
    v_18314 = stack[0];
    if (!consp(v_18314)) goto v_18213;
    else goto v_18214;
v_18213:
    goto v_18224;
v_18220:
    v_18315 = stack[0];
    goto v_18221;
v_18222:
    v_18314 = stack[-5];
    goto v_18223;
v_18224:
    goto v_18220;
v_18221:
    goto v_18222;
v_18223:
    if (v_18315 == v_18314) goto v_18218;
    else goto v_18219;
v_18218:
    v_18314 = stack[-4];
    goto v_18217;
v_18219:
    v_18314 = stack[0];
    goto v_18217;
    v_18314 = nil;
v_18217:
    goto v_18210;
v_18214:
    goto v_18240;
v_18236:
    v_18315 = stack[-5];
    goto v_18237;
v_18238:
    v_18314 = stack[0];
    goto v_18239;
v_18240:
    goto v_18236;
v_18237:
    goto v_18238;
v_18239:
    fn = elt(env, 1); // talp_eqtp
    v_18314 = (*qfn2(fn))(fn, v_18315, v_18314);
    env = stack[-7];
    if (v_18314 == nil) goto v_18234;
    v_18314 = stack[-4];
    goto v_18210;
v_18234:
    goto v_18249;
v_18245:
    v_18314 = stack[0];
    stack[-6] = qcar(v_18314);
    goto v_18246;
v_18247:
    v_18314 = stack[0];
    v_18314 = qcdr(v_18314);
    stack[-3] = v_18314;
    v_18314 = stack[-3];
    if (v_18314 == nil) goto v_18262;
    else goto v_18263;
v_18262:
    v_18314 = nil;
    goto v_18256;
v_18263:
    v_18314 = stack[-3];
    v_18314 = qcar(v_18314);
    goto v_18277;
v_18271:
    v_18316 = stack[-5];
    goto v_18272;
v_18273:
    v_18315 = stack[-4];
    goto v_18274;
v_18275:
    goto v_18276;
v_18277:
    goto v_18271;
v_18272:
    goto v_18273;
v_18274:
    goto v_18275;
v_18276:
    v_18314 = CC_talp_specsubt(elt(env, 0), 3, v_18316, v_18315, v_18314);
    env = stack[-7];
    v_18314 = ncons(v_18314);
    env = stack[-7];
    stack[-1] = v_18314;
    stack[-2] = v_18314;
v_18257:
    v_18314 = stack[-3];
    v_18314 = qcdr(v_18314);
    stack[-3] = v_18314;
    v_18314 = stack[-3];
    if (v_18314 == nil) goto v_18285;
    else goto v_18286;
v_18285:
    v_18314 = stack[-2];
    goto v_18256;
v_18286:
    goto v_18294;
v_18290:
    stack[0] = stack[-1];
    goto v_18291;
v_18292:
    v_18314 = stack[-3];
    v_18314 = qcar(v_18314);
    goto v_18307;
v_18301:
    v_18316 = stack[-5];
    goto v_18302;
v_18303:
    v_18315 = stack[-4];
    goto v_18304;
v_18305:
    goto v_18306;
v_18307:
    goto v_18301;
v_18302:
    goto v_18303;
v_18304:
    goto v_18305;
v_18306:
    v_18314 = CC_talp_specsubt(elt(env, 0), 3, v_18316, v_18315, v_18314);
    env = stack[-7];
    v_18314 = ncons(v_18314);
    env = stack[-7];
    goto v_18293;
v_18294:
    goto v_18290;
v_18291:
    goto v_18292;
v_18293:
    v_18314 = Lrplacd(nil, stack[0], v_18314);
    env = stack[-7];
    v_18314 = stack[-1];
    v_18314 = qcdr(v_18314);
    stack[-1] = v_18314;
    goto v_18257;
v_18256:
    goto v_18248;
v_18249:
    goto v_18245;
v_18246:
    goto v_18247;
v_18248:
    {
        LispObject v_18324 = stack[-6];
        return cons(v_18324, v_18314);
    }
v_18210:
    return onevalue(v_18314);
}



// Code for pasf_floor

static LispObject CC_pasf_floor(LispObject env,
                         LispObject v_18204, LispObject v_18205)
{
    env = qenv(env);
    LispObject v_18326, v_18327, v_18328;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18204,v_18205);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18205;
    stack[-1] = v_18204;
// end of prologue
    v_18326 = stack[-1];
    if (!consp(v_18326)) goto v_18217;
    else goto v_18218;
v_18217:
    v_18326 = lisp_true;
    goto v_18216;
v_18218:
    v_18326 = stack[-1];
    v_18326 = qcar(v_18326);
    v_18326 = (consp(v_18326) ? nil : lisp_true);
    goto v_18216;
    v_18326 = nil;
v_18216:
    if (v_18326 == nil) goto v_18214;
    v_18326 = stack[0];
    if (!consp(v_18326)) goto v_18228;
    else goto v_18229;
v_18228:
    v_18326 = lisp_true;
    goto v_18227;
v_18229:
    v_18326 = stack[0];
    v_18326 = qcar(v_18326);
    v_18326 = (consp(v_18326) ? nil : lisp_true);
    goto v_18227;
    v_18326 = nil;
v_18227:
    goto v_18212;
v_18214:
    v_18326 = nil;
    goto v_18212;
    v_18326 = nil;
v_18212:
    if (v_18326 == nil) goto v_18210;
    v_18326 = stack[-1];
    if (v_18326 == nil) goto v_18242;
    else goto v_18243;
v_18242:
    v_18326 = nil;
    goto v_18241;
v_18243:
    goto v_18257;
v_18253:
    goto v_18263;
v_18259:
    v_18327 = stack[-1];
    goto v_18260;
v_18261:
    v_18326 = stack[0];
    goto v_18262;
v_18263:
    goto v_18259;
v_18260:
    goto v_18261;
v_18262:
    v_18327 = Cremainder(v_18327, v_18326);
    env = stack[-2];
    goto v_18254;
v_18255:
    v_18326 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18256;
v_18257:
    goto v_18253;
v_18254:
    goto v_18255;
v_18256:
    if (v_18327 == v_18326) goto v_18251;
    else goto v_18252;
v_18251:
    goto v_18272;
v_18268:
    v_18327 = stack[-1];
    goto v_18269;
v_18270:
    v_18326 = stack[0];
    goto v_18271;
v_18272:
    goto v_18268;
v_18269:
    goto v_18270;
v_18271:
    v_18326 = quot2(v_18327, v_18326);
    env = stack[-2];
    goto v_18250;
v_18252:
    goto v_18282;
v_18278:
    goto v_18288;
v_18284:
    v_18327 = stack[-1];
    goto v_18285;
v_18286:
    v_18326 = stack[0];
    goto v_18287;
v_18288:
    goto v_18284;
v_18285:
    goto v_18286;
v_18287:
    v_18327 = times2(v_18327, v_18326);
    env = stack[-2];
    goto v_18279;
v_18280:
    v_18326 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_18281;
v_18282:
    goto v_18278;
v_18279:
    goto v_18280;
v_18281:
    v_18326 = (LispObject)greaterp2(v_18327, v_18326);
    v_18326 = v_18326 ? lisp_true : nil;
    env = stack[-2];
    if (v_18326 == nil) goto v_18276;
    goto v_18297;
v_18293:
    v_18327 = stack[-1];
    goto v_18294;
v_18295:
    v_18326 = stack[0];
    goto v_18296;
v_18297:
    goto v_18293;
v_18294:
    goto v_18295;
v_18296:
    v_18326 = quot2(v_18327, v_18326);
    env = stack[-2];
    goto v_18250;
v_18276:
    goto v_18308;
v_18304:
    v_18327 = stack[-1];
    goto v_18305;
v_18306:
    v_18326 = stack[0];
    goto v_18307;
v_18308:
    goto v_18304;
v_18305:
    goto v_18306;
v_18307:
    v_18326 = quot2(v_18327, v_18326);
    env = stack[-2];
    v_18326 = sub1(v_18326);
    env = stack[-2];
    goto v_18250;
    v_18326 = nil;
v_18250:
    fn = elt(env, 2); // simp
    v_18326 = (*qfn1(fn))(fn, v_18326);
    v_18326 = qcar(v_18326);
    goto v_18241;
    v_18326 = nil;
v_18241:
    goto v_18208;
v_18210:
    goto v_18322;
v_18316:
    v_18328 = elt(env, 1); // "pasf_floor: not a domain valued sf in input"
    goto v_18317;
v_18318:
    v_18327 = stack[-1];
    goto v_18319;
v_18320:
    v_18326 = stack[0];
    goto v_18321;
v_18322:
    goto v_18316;
v_18317:
    goto v_18318;
v_18319:
    goto v_18320;
v_18321:
    v_18326 = list3(v_18328, v_18327, v_18326);
    env = stack[-2];
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_18326);
    }
    v_18326 = nil;
v_18208:
    return onevalue(v_18326);
}



// Code for ev_dif

static LispObject CC_ev_dif(LispObject env,
                         LispObject v_18204, LispObject v_18205)
{
    env = qenv(env);
    LispObject v_18242, v_18243, v_18244;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18204,v_18205);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_18205;
    stack[-1] = v_18204;
// end of prologue
    v_18244 = nil;
v_18212:
    v_18242 = stack[-1];
    if (v_18242 == nil) goto v_18215;
    else goto v_18216;
v_18215:
    goto v_18211;
v_18216:
    goto v_18224;
v_18220:
    goto v_18229;
v_18225:
    v_18242 = stack[-1];
    v_18243 = qcar(v_18242);
    goto v_18226;
v_18227:
    v_18242 = stack[0];
    v_18242 = qcar(v_18242);
    goto v_18228;
v_18229:
    goto v_18225;
v_18226:
    goto v_18227;
v_18228:
    v_18242 = (LispObject)(intptr_t)((intptr_t)v_18243 - (intptr_t)v_18242 + TAG_FIXNUM);
    goto v_18221;
v_18222:
    v_18243 = v_18244;
    goto v_18223;
v_18224:
    goto v_18220;
v_18221:
    goto v_18222;
v_18223:
    v_18242 = cons(v_18242, v_18243);
    env = stack[-2];
    v_18244 = v_18242;
    v_18242 = stack[-1];
    v_18242 = qcdr(v_18242);
    stack[-1] = v_18242;
    v_18242 = stack[0];
    v_18242 = qcdr(v_18242);
    stack[0] = v_18242;
    goto v_18212;
v_18211:
    v_18242 = v_18244;
        return Lnreverse(nil, v_18242);
    return onevalue(v_18242);
}



// Code for innprodp2

static LispObject CC_innprodp2(LispObject env,
                         LispObject v_18204, LispObject v_18205)
{
    env = qenv(env);
    LispObject v_18249, v_18250, v_18251, v_18252;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_18204,v_18205);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_18251 = v_18205;
    stack[0] = v_18204;
// end of prologue
    goto v_18214;
v_18210:
    v_18249 = nil;
    goto v_18211;
v_18212:
    v_18250 = v_18251;
    goto v_18213;
v_18214:
    goto v_18210;
v_18211:
    goto v_18212;
v_18213:
    v_18249 = cons(v_18249, v_18250);
    env = stack[-1];
    v_18251 = v_18249;
v_18219:
    v_18249 = stack[0];
    if (v_18249 == nil) goto v_18222;
    v_18249 = v_18251;
    if (v_18249 == nil) goto v_18222;
    goto v_18223;
v_18222:
    goto v_18218;
v_18223:
    goto v_18238;
v_18230:
    v_18252 = nil;
    goto v_18231;
v_18232:
    v_18249 = stack[0];
    v_18250 = qcar(v_18249);
    goto v_18233;
v_18234:
    v_18249 = v_18251;
    v_18249 = qcdr(v_18249);
    goto v_18235;
v_18236:
    v_18251 = qcar(v_18251);
    goto v_18237;
v_18238:
    goto v_18230;
v_18231:
    goto v_18232;
v_18233:
    goto v_18234;
v_18235:
    goto v_18236;
v_18237:
    fn = elt(env, 1); // innprodkp
    v_18249 = (*qfnn(fn))(fn, 4, v_18252, v_18250, v_18249, v_18251);
    env = stack[-1];
    v_18251 = v_18249;
    v_18249 = stack[0];
    v_18249 = qcdr(v_18249);
    stack[0] = v_18249;
    goto v_18219;
v_18218:
    v_18249 = v_18251;
    return onevalue(v_18249);
}



// Code for cgp_mk

static LispObject CC_cgp_mk(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18234, v_18235, v_18236, v_18237, v_18238;
    LispObject v_18208, v_18207, v_18206, v_18205, v_18204;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "cgp_mk");
    va_start(aa, nargs);
    v_18204 = va_arg(aa, LispObject);
    v_18205 = va_arg(aa, LispObject);
    v_18206 = va_arg(aa, LispObject);
    v_18207 = va_arg(aa, LispObject);
    v_18208 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_18208,v_18207,v_18206,v_18205,v_18204);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_18204,v_18205,v_18206,v_18207,v_18208);
    }
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_18234 = v_18208;
    v_18235 = v_18207;
    v_18236 = v_18206;
    v_18237 = v_18205;
    v_18238 = v_18204;
// end of prologue
    goto v_18219;
v_18211:
    stack[-2] = elt(env, 1); // cgp
    goto v_18212;
v_18213:
    stack[-1] = v_18238;
    goto v_18214;
v_18215:
    stack[0] = v_18237;
    goto v_18216;
v_18217:
    goto v_18230;
v_18224:
    goto v_18225;
v_18226:
    goto v_18227;
v_18228:
    goto v_18229;
v_18230:
    goto v_18224;
v_18225:
    goto v_18226;
v_18227:
    goto v_18228;
v_18229:
    v_18234 = list3(v_18236, v_18235, v_18234);
    goto v_18218;
v_18219:
    goto v_18211;
v_18212:
    goto v_18213;
v_18214:
    goto v_18215;
v_18216:
    goto v_18217;
v_18218:
    {
        LispObject v_18242 = stack[-2];
        LispObject v_18243 = stack[-1];
        LispObject v_18244 = stack[0];
        return list3star(v_18242, v_18243, v_18244, v_18234);
    }
}



// Code for omatpir

static LispObject CC_omatpir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_18230, v_18231, v_18232;
    LispObject fn;
    argcheck(nargs, 0, "omatpir");
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
    fn = elt(env, 2); // lex
    v_18230 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    fn = elt(env, 3); // omsir
    v_18230 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_18230 = qcar(v_18230);
    stack[-1] = v_18230;
    fn = elt(env, 2); // lex
    v_18230 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    fn = elt(env, 4); // omobj
    v_18230 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_18230 = qcar(v_18230);
    stack[0] = v_18230;
    fn = elt(env, 2); // lex
    v_18230 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_18230 = elt(env, 1); // (!/ o m a t p)
    fn = elt(env, 5); // checktag
    v_18230 = (*qfn1(fn))(fn, v_18230);
    env = stack[-2];
    goto v_18226;
v_18220:
    v_18232 = stack[-1];
    goto v_18221;
v_18222:
    v_18231 = stack[0];
    goto v_18223;
v_18224:
    v_18230 = nil;
    goto v_18225;
v_18226:
    goto v_18220;
v_18221:
    goto v_18222;
v_18223:
    goto v_18224;
v_18225:
    v_18230 = list2star(v_18232, v_18231, v_18230);
    return ncons(v_18230);
    return onevalue(v_18230);
}



setup_type const u33_setup[] =
{
    {"max-degree",              TOO_FEW_2,      CC_maxKdegree, WRONG_NO_2},
    {"chkrn*",                  CC_chkrnH,      TOO_MANY_1,    WRONG_NO_1},
    {"length_multiindex",       CC_length_multiindex,TOO_MANY_1,WRONG_NO_1},
    {"aex_stchsgnch1",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_aex_stchsgnch1},
    {"in_list1a",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_in_list1a},
    {"ofsf_siatsubf",           TOO_FEW_2,      CC_ofsf_siatsubf,WRONG_NO_2},
    {"ofsf_simplat1",           TOO_FEW_2,      CC_ofsf_simplat1,WRONG_NO_2},
    {"talp_atnum",              CC_talp_atnum,  TOO_MANY_1,    WRONG_NO_1},
    {"pasf_susibinad",          TOO_FEW_2,      CC_pasf_susibinad,WRONG_NO_2},
    {"ev_max#",                 TOO_FEW_2,      CC_ev_maxC,    WRONG_NO_2},
    {"minusml",                 CC_minusml,     TOO_MANY_1,    WRONG_NO_1},
    {"dm-min",                  TOO_FEW_2,      CC_dmKmin,     WRONG_NO_2},
    {":dmtimeslst",             CC_Tdmtimeslst, TOO_MANY_1,    WRONG_NO_1},
    {"*di2q",                   TOO_FEW_2,      CC_Hdi2q,      WRONG_NO_2},
    {"expand_rule",             CC_expand_rule, TOO_MANY_1,    WRONG_NO_1},
    {"pasf_sisub",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pasf_sisub},
    {"dip_ilcomb2r",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dip_ilcomb2r},
    {"multiminus",              CC_multiminus,  TOO_MANY_1,    WRONG_NO_1},
    {"mkempspmat",              TOO_FEW_2,      CC_mkempspmat, WRONG_NO_2},
    {"suchp",                   CC_suchp,       TOO_MANY_1,    WRONG_NO_1},
    {"dipequal",                TOO_FEW_2,      CC_dipequal,   WRONG_NO_2},
    {"f2dip11",                 CC_f2dip11,     TOO_MANY_1,    WRONG_NO_1},
    {"*xadd",                   TOO_FEW_2,      CC_Hxadd,      WRONG_NO_2},
    {"simp-prop1",              TOO_FEW_2,      CC_simpKprop1, WRONG_NO_2},
    {"split_cov_cont_ids",      CC_split_cov_cont_ids,TOO_MANY_1,WRONG_NO_1},
    {"st_ad_numsorttree",       CC_st_ad_numsorttree,TOO_MANY_1,WRONG_NO_1},
    {"general-horner-rule-mod-p",WRONG_NO_NA,   WRONG_NO_NB,   (n_args *)CC_generalKhornerKruleKmodKp},
    {"gitimes:",                TOO_FEW_2,      CC_gitimesT,   WRONG_NO_2},
    {"*a2f",                    CC_Ha2f,        TOO_MANY_1,    WRONG_NO_1},
    {"letexprn",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_letexprn},
    {"triplesetprolongedby",    TOO_FEW_2,      CC_triplesetprolongedby,WRONG_NO_2},
    {"ofsf_facequal*",          TOO_FEW_2,      CC_ofsf_facequalH,WRONG_NO_2},
    {"talp_specsubt",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_specsubt},
    {"pasf_floor",              TOO_FEW_2,      CC_pasf_floor, WRONG_NO_2},
    {"ev_dif",                  TOO_FEW_2,      CC_ev_dif,     WRONG_NO_2},
    {"innprodp2",               TOO_FEW_2,      CC_innprodp2,  WRONG_NO_2},
    {"cgp_mk",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cgp_mk},
    {"omatpir",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_omatpir},
    {NULL, (one_args *)"u33", (two_args *)"129118 491857 6942456", 0}
};

// end of generated code
