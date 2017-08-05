
// $destdir/u13.c        Machine generated C code

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



// Code for gcdf2

static LispObject CC_gcdf2(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7408, v_7409, v_7410;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_7089;
    stack[-5] = v_7088;
// end of prologue
// Binding asymplis!*
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
    qvalue(elt(env, 1)) = nil; // asymplis!*
    v_7408 = qvalue(elt(env, 2)); // !*anygcd
    if (v_7408 == nil) goto v_7102;
    else goto v_7103;
v_7102:
    v_7408 = lisp_true;
    goto v_7101;
v_7103:
    v_7408 = stack[-5];
    fn = elt(env, 4); // num!-exponents
    v_7408 = (*qfn1(fn))(fn, v_7408);
    env = stack[-7];
    if (v_7408 == nil) goto v_7110;
    else goto v_7111;
v_7110:
    v_7408 = lisp_true;
    goto v_7109;
v_7111:
    v_7408 = stack[-4];
    fn = elt(env, 4); // num!-exponents
    v_7408 = (*qfn1(fn))(fn, v_7408);
    env = stack[-7];
    v_7408 = (v_7408 == nil ? lisp_true : nil);
    goto v_7109;
    v_7408 = nil;
v_7109:
    goto v_7101;
    v_7408 = nil;
v_7101:
    if (v_7408 == nil) goto v_7099;
    v_7408 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7095;
v_7099:
    v_7408 = qvalue(elt(env, 3)); // !*gcd
    if (v_7408 == nil) goto v_7124;
    goto v_7133;
v_7129:
    goto v_7140;
v_7136:
    v_7409 = stack[-5];
    goto v_7137;
v_7138:
    v_7408 = stack[-4];
    goto v_7139;
v_7140:
    goto v_7136;
v_7137:
    goto v_7138;
v_7139:
    fn = elt(env, 5); // kernord
    v_7408 = (*qfn2(fn))(fn, v_7409, v_7408);
    env = stack[-7];
    stack[-3] = v_7408;
    v_7409 = Llength(nil, v_7408);
    env = stack[-7];
    goto v_7130;
v_7131:
    v_7408 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7132;
v_7133:
    goto v_7129;
v_7130:
    goto v_7131;
v_7132:
    v_7408 = (LispObject)greaterp2(v_7409, v_7408);
    v_7408 = v_7408 ? lisp_true : nil;
    env = stack[-7];
    if (v_7408 == nil) goto v_7124;
    v_7408 = stack[-3];
    fn = elt(env, 6); // setkorder
    v_7408 = (*qfn1(fn))(fn, v_7408);
    env = stack[-7];
    v_7408 = ncons(v_7408);
    env = stack[-7];
    stack[-3] = v_7408;
    v_7408 = stack[-5];
    fn = elt(env, 7); // reorder
    v_7408 = (*qfn1(fn))(fn, v_7408);
    env = stack[-7];
    stack[-5] = v_7408;
    v_7408 = stack[-4];
    fn = elt(env, 7); // reorder
    v_7408 = (*qfn1(fn))(fn, v_7408);
    env = stack[-7];
    stack[-4] = v_7408;
    goto v_7122;
v_7124:
    v_7408 = nil;
    stack[-3] = v_7408;
    goto v_7122;
v_7122:
    goto v_7162;
v_7158:
    v_7408 = stack[-5];
    v_7408 = qcar(v_7408);
    v_7408 = qcar(v_7408);
    v_7409 = qcar(v_7408);
    goto v_7159;
v_7160:
    v_7408 = stack[-4];
    v_7408 = qcar(v_7408);
    v_7408 = qcar(v_7408);
    v_7408 = qcar(v_7408);
    goto v_7161;
v_7162:
    goto v_7158;
v_7159:
    goto v_7160;
v_7161:
    if (v_7409 == v_7408) goto v_7156;
    else goto v_7157;
v_7156:
    v_7408 = stack[-5];
    fn = elt(env, 8); // comfac
    v_7408 = (*qfn1(fn))(fn, v_7408);
    env = stack[-7];
    stack[-1] = v_7408;
    v_7408 = stack[-4];
    fn = elt(env, 8); // comfac
    v_7408 = (*qfn1(fn))(fn, v_7408);
    env = stack[-7];
    stack[0] = v_7408;
    goto v_7184;
v_7180:
    v_7408 = stack[-1];
    v_7409 = qcdr(v_7408);
    goto v_7181;
v_7182:
    v_7408 = stack[0];
    v_7408 = qcdr(v_7408);
    goto v_7183;
v_7184:
    goto v_7180;
v_7181:
    goto v_7182;
v_7183:
    fn = elt(env, 9); // gcdf1
    v_7408 = (*qfn2(fn))(fn, v_7409, v_7408);
    env = stack[-7];
    stack[-2] = v_7408;
    goto v_7194;
v_7190:
    goto v_7191;
v_7192:
    v_7408 = stack[-1];
    fn = elt(env, 10); // comfac!-to!-poly
    v_7408 = (*qfn1(fn))(fn, v_7408);
    env = stack[-7];
    goto v_7193;
v_7194:
    goto v_7190;
v_7191:
    goto v_7192;
v_7193:
    fn = elt(env, 11); // quotf1
    v_7408 = (*qfn2(fn))(fn, stack[-5], v_7408);
    env = stack[-7];
    stack[-5] = v_7408;
    goto v_7203;
v_7199:
    goto v_7200;
v_7201:
    v_7408 = stack[0];
    fn = elt(env, 10); // comfac!-to!-poly
    v_7408 = (*qfn1(fn))(fn, v_7408);
    env = stack[-7];
    goto v_7202;
v_7203:
    goto v_7199;
v_7200:
    goto v_7201;
v_7202:
    fn = elt(env, 11); // quotf1
    v_7408 = (*qfn2(fn))(fn, stack[-4], v_7408);
    env = stack[-7];
    stack[-4] = v_7408;
    v_7408 = qvalue(elt(env, 3)); // !*gcd
    if (v_7408 == nil) goto v_7210;
    goto v_7217;
v_7213:
    goto v_7223;
v_7219:
    v_7409 = stack[-5];
    goto v_7220;
v_7221:
    v_7408 = stack[-4];
    goto v_7222;
v_7223:
    goto v_7219;
v_7220:
    goto v_7221;
v_7222:
    fn = elt(env, 12); // gcdk
    v_7409 = (*qfn2(fn))(fn, v_7409, v_7408);
    env = stack[-7];
    goto v_7214;
v_7215:
    v_7408 = stack[-2];
    goto v_7216;
v_7217:
    goto v_7213;
v_7214:
    goto v_7215;
v_7216:
    fn = elt(env, 13); // multf
    v_7408 = (*qfn2(fn))(fn, v_7409, v_7408);
    env = stack[-7];
    stack[-2] = v_7408;
    goto v_7208;
v_7210:
    v_7408 = stack[-4];
    if (v_7408 == nil) goto v_7228;
    goto v_7237;
v_7233:
    v_7409 = stack[-5];
    goto v_7234;
v_7235:
    v_7408 = stack[-4];
    goto v_7236;
v_7237:
    goto v_7233;
v_7234:
    goto v_7235;
v_7236:
    fn = elt(env, 11); // quotf1
    v_7408 = (*qfn2(fn))(fn, v_7409, v_7408);
    env = stack[-7];
    if (v_7408 == nil) goto v_7228;
    goto v_7245;
v_7241:
    v_7409 = stack[-4];
    goto v_7242;
v_7243:
    v_7408 = stack[-2];
    goto v_7244;
v_7245:
    goto v_7241;
v_7242:
    goto v_7243;
v_7244:
    fn = elt(env, 13); // multf
    v_7408 = (*qfn2(fn))(fn, v_7409, v_7408);
    env = stack[-7];
    stack[-2] = v_7408;
    goto v_7208;
v_7228:
    v_7408 = stack[-5];
    if (v_7408 == nil) goto v_7249;
    goto v_7258;
v_7254:
    v_7409 = stack[-4];
    goto v_7255;
v_7256:
    v_7408 = stack[-5];
    goto v_7257;
v_7258:
    goto v_7254;
v_7255:
    goto v_7256;
v_7257:
    fn = elt(env, 11); // quotf1
    v_7408 = (*qfn2(fn))(fn, v_7409, v_7408);
    env = stack[-7];
    if (v_7408 == nil) goto v_7249;
    goto v_7266;
v_7262:
    v_7409 = stack[-5];
    goto v_7263;
v_7264:
    v_7408 = stack[-2];
    goto v_7265;
v_7266:
    goto v_7262;
v_7263:
    goto v_7264;
v_7265:
    fn = elt(env, 13); // multf
    v_7408 = (*qfn2(fn))(fn, v_7409, v_7408);
    env = stack[-7];
    stack[-2] = v_7408;
    goto v_7208;
v_7249:
v_7208:
    v_7408 = stack[-1];
    v_7408 = qcar(v_7408);
    if (v_7408 == nil) goto v_7272;
    v_7408 = stack[0];
    v_7408 = qcar(v_7408);
    if (v_7408 == nil) goto v_7272;
    goto v_7288;
v_7284:
    v_7408 = stack[-1];
    v_7408 = qcar(v_7408);
    v_7409 = qcdr(v_7408);
    goto v_7285;
v_7286:
    v_7408 = stack[0];
    v_7408 = qcar(v_7408);
    v_7408 = qcdr(v_7408);
    goto v_7287;
v_7288:
    goto v_7284;
v_7285:
    goto v_7286;
v_7287:
    v_7408 = (LispObject)greaterp2(v_7409, v_7408);
    v_7408 = v_7408 ? lisp_true : nil;
    env = stack[-7];
    if (v_7408 == nil) goto v_7282;
    goto v_7300;
v_7296:
    goto v_7307;
v_7303:
    v_7408 = stack[0];
    v_7409 = qcar(v_7408);
    goto v_7304;
v_7305:
    v_7408 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7306;
v_7307:
    goto v_7303;
v_7304:
    goto v_7305;
v_7306:
    v_7408 = cons(v_7409, v_7408);
    env = stack[-7];
    v_7409 = ncons(v_7408);
    env = stack[-7];
    goto v_7297;
v_7298:
    v_7408 = stack[-2];
    goto v_7299;
v_7300:
    goto v_7296;
v_7297:
    goto v_7298;
v_7299:
    fn = elt(env, 13); // multf
    v_7408 = (*qfn2(fn))(fn, v_7409, v_7408);
    env = stack[-7];
    stack[-2] = v_7408;
    goto v_7280;
v_7282:
    goto v_7319;
v_7315:
    goto v_7326;
v_7322:
    v_7408 = stack[-1];
    v_7409 = qcar(v_7408);
    goto v_7323;
v_7324:
    v_7408 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7325;
v_7326:
    goto v_7322;
v_7323:
    goto v_7324;
v_7325:
    v_7408 = cons(v_7409, v_7408);
    env = stack[-7];
    v_7409 = ncons(v_7408);
    env = stack[-7];
    goto v_7316;
v_7317:
    v_7408 = stack[-2];
    goto v_7318;
v_7319:
    goto v_7315;
v_7316:
    goto v_7317;
v_7318:
    fn = elt(env, 13); // multf
    v_7408 = (*qfn2(fn))(fn, v_7409, v_7408);
    env = stack[-7];
    stack[-2] = v_7408;
    goto v_7280;
v_7280:
    goto v_7270;
v_7272:
v_7270:
    goto v_7155;
v_7157:
    v_7408 = stack[-5];
    v_7408 = qcar(v_7408);
    v_7408 = qcar(v_7408);
    v_7408 = qcar(v_7408);
    fn = elt(env, 14); // noncomp
    v_7408 = (*qfn1(fn))(fn, v_7408);
    env = stack[-7];
    if (v_7408 == nil) goto v_7332;
    v_7408 = stack[-4];
    v_7408 = qcar(v_7408);
    v_7408 = qcar(v_7408);
    v_7408 = qcar(v_7408);
    fn = elt(env, 14); // noncomp
    v_7408 = (*qfn1(fn))(fn, v_7408);
    env = stack[-7];
    if (v_7408 == nil) goto v_7332;
    goto v_7352;
v_7346:
    v_7410 = stack[-5];
    goto v_7347;
v_7348:
    v_7409 = stack[-4];
    goto v_7349;
v_7350:
    v_7408 = stack[-4];
    v_7408 = qcar(v_7408);
    v_7408 = qcar(v_7408);
    v_7408 = qcar(v_7408);
    goto v_7351;
v_7352:
    goto v_7346;
v_7347:
    goto v_7348;
v_7349:
    goto v_7350;
v_7351:
    fn = elt(env, 15); // gcdfnc
    v_7408 = (*qfnn(fn))(fn, 3, v_7410, v_7409, v_7408);
    env = stack[-7];
    stack[-2] = v_7408;
    goto v_7155;
v_7332:
    goto v_7366;
v_7362:
    v_7408 = stack[-5];
    v_7408 = qcar(v_7408);
    v_7408 = qcar(v_7408);
    v_7409 = qcar(v_7408);
    goto v_7363;
v_7364:
    v_7408 = stack[-4];
    v_7408 = qcar(v_7408);
    v_7408 = qcar(v_7408);
    v_7408 = qcar(v_7408);
    goto v_7365;
v_7366:
    goto v_7362;
v_7363:
    goto v_7364;
v_7365:
    fn = elt(env, 16); // ordop
    v_7408 = (*qfn2(fn))(fn, v_7409, v_7408);
    env = stack[-7];
    if (v_7408 == nil) goto v_7360;
    goto v_7380;
v_7376:
    v_7408 = stack[-5];
    fn = elt(env, 8); // comfac
    v_7408 = (*qfn1(fn))(fn, v_7408);
    env = stack[-7];
    v_7409 = qcdr(v_7408);
    goto v_7377;
v_7378:
    v_7408 = stack[-4];
    goto v_7379;
v_7380:
    goto v_7376;
v_7377:
    goto v_7378;
v_7379:
    fn = elt(env, 9); // gcdf1
    v_7408 = (*qfn2(fn))(fn, v_7409, v_7408);
    env = stack[-7];
    stack[-2] = v_7408;
    goto v_7155;
v_7360:
    goto v_7392;
v_7388:
    v_7408 = stack[-4];
    fn = elt(env, 8); // comfac
    v_7408 = (*qfn1(fn))(fn, v_7408);
    env = stack[-7];
    v_7409 = qcdr(v_7408);
    goto v_7389;
v_7390:
    v_7408 = stack[-5];
    goto v_7391;
v_7392:
    goto v_7388;
v_7389:
    goto v_7390;
v_7391:
    fn = elt(env, 9); // gcdf1
    v_7408 = (*qfn2(fn))(fn, v_7409, v_7408);
    env = stack[-7];
    stack[-2] = v_7408;
    goto v_7155;
v_7155:
    v_7408 = stack[-3];
    if (v_7408 == nil) goto v_7400;
    v_7408 = stack[-3];
    v_7408 = qcar(v_7408);
    fn = elt(env, 6); // setkorder
    v_7408 = (*qfn1(fn))(fn, v_7408);
    env = stack[-7];
    v_7408 = stack[-2];
    fn = elt(env, 7); // reorder
    v_7408 = (*qfn1(fn))(fn, v_7408);
    stack[-2] = v_7408;
    goto v_7398;
v_7400:
v_7398:
    v_7408 = stack[-2];
v_7095:
    ;}  // end of a binding scope
    return onevalue(v_7408);
}



// Code for subs3f1

static LispObject CC_subs3f1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7270, v_7271, v_7272;
    LispObject fn;
    LispObject v_7090, v_7089, v_7088;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "subs3f1");
    va_start(aa, nargs);
    v_7088 = va_arg(aa, LispObject);
    v_7089 = va_arg(aa, LispObject);
    v_7090 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7090,v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7088,v_7089,v_7090);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_7090;
    stack[-1] = v_7089;
    stack[-2] = v_7088;
// end of prologue
    goto v_7104;
v_7100:
    v_7271 = nil;
    goto v_7101;
v_7102:
    v_7270 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7103;
v_7104:
    goto v_7100;
v_7101:
    goto v_7102;
v_7103:
    v_7270 = cons(v_7271, v_7270);
    env = stack[-4];
    stack[-3] = v_7270;
v_7096:
    v_7270 = stack[-2];
    if (v_7270 == nil) goto v_7109;
    else goto v_7110;
v_7109:
    v_7270 = stack[-3];
    goto v_7095;
v_7110:
    v_7270 = stack[-2];
    if (!consp(v_7270)) goto v_7117;
    else goto v_7118;
v_7117:
    v_7270 = lisp_true;
    goto v_7116;
v_7118:
    v_7270 = stack[-2];
    v_7270 = qcar(v_7270);
    v_7270 = (consp(v_7270) ? nil : lisp_true);
    goto v_7116;
    v_7270 = nil;
v_7116:
    if (v_7270 == nil) goto v_7114;
    goto v_7131;
v_7127:
    stack[0] = stack[-3];
    goto v_7128;
v_7129:
    goto v_7138;
v_7134:
    v_7271 = stack[-2];
    goto v_7135;
v_7136:
    v_7270 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7137;
v_7138:
    goto v_7134;
v_7135:
    goto v_7136;
v_7137:
    v_7270 = cons(v_7271, v_7270);
    env = stack[-4];
    goto v_7130;
v_7131:
    goto v_7127;
v_7128:
    goto v_7129;
v_7130:
    {
        LispObject v_7277 = stack[0];
        fn = elt(env, 6); // addsq
        return (*qfn2(fn))(fn, v_7277, v_7270);
    }
v_7114:
    v_7270 = stack[0];
    if (v_7270 == nil) goto v_7142;
    v_7270 = stack[-2];
    v_7270 = qcar(v_7270);
    v_7270 = qcdr(v_7270);
    if (!consp(v_7270)) goto v_7148;
    else goto v_7149;
v_7148:
    v_7270 = lisp_true;
    goto v_7147;
v_7149:
    v_7270 = stack[-2];
    v_7270 = qcar(v_7270);
    v_7270 = qcdr(v_7270);
    v_7270 = qcar(v_7270);
    v_7270 = (consp(v_7270) ? nil : lisp_true);
    goto v_7147;
    v_7270 = nil;
v_7147:
    if (v_7270 == nil) goto v_7142;
    goto v_7098;
v_7142:
    v_7270 = qvalue(elt(env, 1)); // !*mymatch
    if (v_7270 == nil) goto v_7164;
    goto v_7171;
v_7167:
    v_7270 = stack[-2];
    v_7271 = qcar(v_7270);
    goto v_7168;
v_7169:
    v_7270 = stack[-1];
    goto v_7170;
v_7171:
    goto v_7167;
v_7168:
    goto v_7169;
v_7170:
    fn = elt(env, 7); // !*subs3tnc
    v_7270 = (*qfn2(fn))(fn, v_7271, v_7270);
    env = stack[-4];
    goto v_7162;
v_7164:
    goto v_7182;
v_7178:
    v_7270 = stack[-2];
    v_7271 = qcar(v_7270);
    goto v_7179;
v_7180:
    v_7270 = stack[-1];
    goto v_7181;
v_7182:
    goto v_7178;
v_7179:
    goto v_7180;
v_7181:
    fn = elt(env, 8); // subs3t
    v_7270 = (*qfn2(fn))(fn, v_7271, v_7270);
    env = stack[-4];
    goto v_7162;
    v_7270 = nil;
v_7162:
    v_7272 = v_7270;
    v_7270 = stack[0];
    if (v_7270 == nil) goto v_7192;
    else goto v_7193;
v_7192:
    v_7270 = lisp_true;
    goto v_7191;
v_7193:
    v_7270 = qvalue(elt(env, 2)); // mchfg!*
    v_7270 = (v_7270 == nil ? lisp_true : nil);
    goto v_7191;
    v_7270 = nil;
v_7191:
    if (v_7270 == nil) goto v_7189;
    goto v_7097;
v_7189:
    v_7270 = nil;
    qvalue(elt(env, 2)) = v_7270; // mchfg!*
    goto v_7213;
v_7209:
    v_7270 = v_7272;
    v_7271 = qcar(v_7270);
    goto v_7210;
v_7211:
    v_7270 = stack[-2];
    goto v_7212;
v_7213:
    goto v_7209;
v_7210:
    goto v_7211;
v_7212:
    if (equal(v_7271, v_7270)) goto v_7207;
    else goto v_7208;
v_7207:
    goto v_7221;
v_7217:
    v_7270 = v_7272;
    v_7271 = qcdr(v_7270);
    goto v_7218;
v_7219:
    v_7270 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7220;
v_7221:
    goto v_7217;
v_7218:
    goto v_7219;
v_7220:
    v_7270 = (v_7271 == v_7270 ? lisp_true : nil);
    goto v_7206;
v_7208:
    v_7270 = nil;
    goto v_7206;
    v_7270 = nil;
v_7206:
    if (v_7270 == nil) goto v_7204;
    goto v_7234;
v_7230:
    v_7271 = stack[-2];
    goto v_7231;
v_7232:
    v_7270 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7233;
v_7234:
    goto v_7230;
v_7231:
    goto v_7232;
v_7233:
    v_7270 = cons(v_7271, v_7270);
    env = stack[-4];
    v_7272 = v_7270;
    goto v_7097;
v_7204:
    v_7270 = qvalue(elt(env, 3)); // !*resubs
    if (v_7270 == nil) goto v_7237;
    else goto v_7238;
v_7237:
    goto v_7097;
v_7238:
    v_7270 = qvalue(elt(env, 4)); // !*sub2
    if (v_7270 == nil) goto v_7242;
    else goto v_7240;
v_7242:
    v_7270 = qvalue(elt(env, 5)); // powlis1!*
    if (v_7270 == nil) goto v_7244;
    else goto v_7240;
v_7244:
    goto v_7241;
v_7240:
    v_7270 = v_7272;
    fn = elt(env, 9); // subs2q
    v_7270 = (*qfn1(fn))(fn, v_7270);
    env = stack[-4];
    v_7272 = v_7270;
    goto v_7202;
v_7241:
v_7202:
    v_7270 = v_7272;
    fn = elt(env, 10); // subs3q
    v_7270 = (*qfn1(fn))(fn, v_7270);
    env = stack[-4];
    v_7272 = v_7270;
v_7097:
    goto v_7255;
v_7251:
    v_7270 = stack[-3];
    goto v_7252;
v_7253:
    v_7271 = v_7272;
    goto v_7254;
v_7255:
    goto v_7251;
v_7252:
    goto v_7253;
v_7254:
    fn = elt(env, 6); // addsq
    v_7270 = (*qfn2(fn))(fn, v_7270, v_7271);
    env = stack[-4];
    stack[-3] = v_7270;
    v_7270 = stack[-2];
    v_7270 = qcdr(v_7270);
    stack[-2] = v_7270;
    goto v_7096;
v_7098:
    goto v_7265;
v_7261:
    v_7270 = stack[-2];
    v_7270 = qcar(v_7270);
    v_7271 = ncons(v_7270);
    env = stack[-4];
    goto v_7262;
v_7263:
    v_7270 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7264;
v_7265:
    goto v_7261;
v_7262:
    goto v_7263;
v_7264:
    v_7270 = cons(v_7271, v_7270);
    env = stack[-4];
    v_7272 = v_7270;
    goto v_7097;
v_7095:
    return onevalue(v_7270);
}



// Code for get_group_in

static LispObject CC_get_group_in(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7094;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7094 = v_7088;
// end of prologue
    v_7094 = qcar(v_7094);
    return onevalue(v_7094);
}



// Code for mkzl

static LispObject CC_mkzl(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7119, v_7120;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7088);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7088;
// end of prologue
    stack[-1] = nil;
v_7093:
    goto v_7102;
v_7098:
    v_7120 = stack[0];
    goto v_7099;
v_7100:
    v_7119 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7101;
v_7102:
    goto v_7098;
v_7099:
    goto v_7100;
v_7101:
    if (v_7120 == v_7119) goto v_7096;
    else goto v_7097;
v_7096:
    v_7119 = stack[-1];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_7119);
    }
v_7097:
    goto v_7114;
v_7110:
    v_7120 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7111;
v_7112:
    v_7119 = stack[-1];
    goto v_7113;
v_7114:
    goto v_7110;
v_7111:
    goto v_7112;
v_7113:
    v_7119 = cons(v_7120, v_7119);
    env = stack[-2];
    stack[-1] = v_7119;
    v_7119 = stack[0];
    v_7119 = sub1(v_7119);
    env = stack[-2];
    stack[0] = v_7119;
    goto v_7093;
    v_7119 = nil;
    return onevalue(v_7119);
}



// Code for naryrd

static LispObject CC_naryrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7109, v_7110;
    LispObject fn;
    argcheck(nargs, 0, "naryrd");
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
    fn = elt(env, 1); // mathml
    v_7109 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_7110 = v_7109;
    v_7109 = v_7110;
    if (v_7109 == nil) goto v_7095;
    else goto v_7096;
v_7095:
    v_7109 = nil;
    goto v_7094;
v_7096:
    goto v_7106;
v_7102:
    stack[0] = v_7110;
    goto v_7103;
v_7104:
    v_7109 = CC_naryrd(elt(env, 0), 0);
    goto v_7105;
v_7106:
    goto v_7102;
v_7103:
    goto v_7104;
v_7105:
    {
        LispObject v_7112 = stack[0];
        return cons(v_7112, v_7109);
    }
    v_7109 = nil;
v_7094:
    return onevalue(v_7109);
}



// Code for spquotematrix

static LispObject CC_spquotematrix(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7091;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7091 = v_7088;
// end of prologue
    v_7091 = elt(env, 1); // sparse
    return onevalue(v_7091);
}



// Code for fortranop

static LispObject CC_fortranop(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7102, v_7103, v_7104;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7088);
    }
// copy arguments values to proper place
    v_7104 = v_7088;
// end of prologue
    goto v_7098;
v_7094:
    v_7103 = v_7104;
    goto v_7095;
v_7096:
    v_7102 = elt(env, 1); // !*fortranop!*
    goto v_7097;
v_7098:
    goto v_7094;
v_7095:
    goto v_7096;
v_7097:
    v_7102 = get(v_7103, v_7102);
    if (v_7102 == nil) goto v_7092;
    else goto v_7091;
v_7092:
    v_7102 = v_7104;
v_7091:
    return onevalue(v_7102);
}



// Code for tokquote

static LispObject CC_tokquote(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7097;
    LispObject fn;
    argcheck(nargs, 0, "tokquote");
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
    fn = elt(env, 5); // readch1
    v_7097 = (*qfnn(fn))(fn, 0);
    env = stack[0];
    qvalue(elt(env, 1)) = v_7097; // crchar!*
    fn = elt(env, 6); // rread
    v_7097 = (*qfnn(fn))(fn, 0);
    env = stack[0];
    v_7097 = Lmkquote(nil, v_7097);
    env = stack[0];
    qvalue(elt(env, 2)) = v_7097; // nxtsym!*
    v_7097 = nil;
    qvalue(elt(env, 3)) = v_7097; // curescaped!*
    v_7097 = (LispObject)64+TAG_FIXNUM; // 4
    qvalue(elt(env, 4)) = v_7097; // ttype!*
    v_7097 = qvalue(elt(env, 2)); // nxtsym!*
    return onevalue(v_7097);
}



// Code for red!-ratios1

static LispObject CC_redKratios1(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7130, v_7131, v_7132, v_7133;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7089;
    stack[-1] = v_7088;
// end of prologue
v_7087:
    v_7130 = stack[-1];
    if (v_7130 == nil) goto v_7093;
    else goto v_7094;
v_7093:
    v_7130 = nil;
    goto v_7092;
v_7094:
    goto v_7111;
v_7103:
    v_7130 = stack[-1];
    v_7133 = qcdr(v_7130);
    goto v_7104;
v_7105:
    v_7130 = stack[0];
    v_7132 = qcdr(v_7130);
    goto v_7106;
v_7107:
    v_7130 = stack[-1];
    v_7131 = qcar(v_7130);
    goto v_7108;
v_7109:
    v_7130 = stack[0];
    v_7130 = qcar(v_7130);
    goto v_7110;
v_7111:
    goto v_7103;
v_7104:
    goto v_7105;
v_7106:
    goto v_7107;
v_7108:
    goto v_7109;
v_7110:
    fn = elt(env, 1); // red!-ratios2
    v_7130 = (*qfnn(fn))(fn, 4, v_7133, v_7132, v_7131, v_7130);
    env = stack[-2];
    if (v_7130 == nil) goto v_7101;
    else goto v_7100;
v_7101:
    goto v_7125;
v_7121:
    v_7130 = stack[-1];
    v_7131 = qcdr(v_7130);
    goto v_7122;
v_7123:
    v_7130 = stack[0];
    v_7130 = qcdr(v_7130);
    goto v_7124;
v_7125:
    goto v_7121;
v_7122:
    goto v_7123;
v_7124:
    stack[-1] = v_7131;
    stack[0] = v_7130;
    goto v_7087;
v_7100:
    goto v_7092;
    v_7130 = nil;
v_7092:
    return onevalue(v_7130);
}



// Code for multop

static LispObject CC_multop(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7133, v_7134, v_7135;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_7089;
    v_7135 = v_7088;
// end of prologue
    v_7133 = qvalue(elt(env, 1)); // kord!*
    if (v_7133 == nil) goto v_7093;
    else goto v_7094;
v_7093:
    goto v_7101;
v_7097:
    goto v_7108;
v_7104:
    v_7134 = v_7135;
    goto v_7105;
v_7106:
    v_7133 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7107;
v_7108:
    goto v_7104;
v_7105:
    goto v_7106;
v_7107:
    v_7133 = cons(v_7134, v_7133);
    env = stack[-1];
    v_7134 = ncons(v_7133);
    env = stack[-1];
    goto v_7098;
v_7099:
    v_7133 = stack[0];
    goto v_7100;
v_7101:
    goto v_7097;
v_7098:
    goto v_7099;
v_7100:
    {
        fn = elt(env, 3); // multf
        return (*qfn2(fn))(fn, v_7134, v_7133);
    }
v_7094:
    goto v_7118;
v_7114:
    v_7133 = v_7135;
    v_7134 = qcar(v_7133);
    goto v_7115;
v_7116:
    v_7133 = elt(env, 2); // k!*
    goto v_7117;
v_7118:
    goto v_7114;
v_7115:
    goto v_7116;
v_7117:
    if (v_7134 == v_7133) goto v_7112;
    else goto v_7113;
v_7112:
    v_7133 = stack[0];
    goto v_7092;
v_7113:
    goto v_7130;
v_7126:
    v_7134 = v_7135;
    goto v_7127;
v_7128:
    v_7133 = stack[0];
    goto v_7129;
v_7130:
    goto v_7126;
v_7127:
    goto v_7128;
v_7129:
    {
        fn = elt(env, 4); // rmultpf
        return (*qfn2(fn))(fn, v_7134, v_7133);
    }
    v_7133 = nil;
v_7092:
    return onevalue(v_7133);
}



// Code for dividef

static LispObject CC_dividef(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7140, v_7141, v_7142, v_7143;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
// copy arguments values to proper place
    v_7140 = v_7089;
    v_7141 = v_7088;
// end of prologue
    goto v_7096;
v_7092:
    goto v_7093;
v_7094:
    goto v_7095;
v_7096:
    goto v_7092;
v_7093:
    goto v_7094;
v_7095:
    v_7140 = Ldivide(nil, v_7141, v_7140);
    v_7143 = v_7140;
    goto v_7105;
v_7101:
    goto v_7114;
v_7110:
    v_7140 = v_7143;
    v_7141 = qcar(v_7140);
    goto v_7111;
v_7112:
    v_7140 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7113;
v_7114:
    goto v_7110;
v_7111:
    goto v_7112;
v_7113:
    if (v_7141 == v_7140) goto v_7108;
    else goto v_7109;
v_7108:
    v_7140 = nil;
    v_7142 = v_7140;
    goto v_7107;
v_7109:
    v_7140 = v_7143;
    v_7140 = qcar(v_7140);
    v_7142 = v_7140;
    goto v_7107;
    v_7142 = nil;
v_7107:
    goto v_7102;
v_7103:
    goto v_7131;
v_7127:
    v_7140 = v_7143;
    v_7141 = qcdr(v_7140);
    goto v_7128;
v_7129:
    v_7140 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7130;
v_7131:
    goto v_7127;
v_7128:
    goto v_7129;
v_7130:
    if (v_7141 == v_7140) goto v_7125;
    else goto v_7126;
v_7125:
    v_7140 = nil;
    goto v_7124;
v_7126:
    v_7140 = v_7143;
    v_7140 = qcdr(v_7140);
    goto v_7124;
    v_7140 = nil;
v_7124:
    goto v_7104;
v_7105:
    goto v_7101;
v_7102:
    goto v_7103;
v_7104:
    return cons(v_7142, v_7140);
}



// Code for dl_get

static LispObject CC_dl_get(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7098, v_7099;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7098 = v_7088;
// end of prologue
    goto v_7095;
v_7091:
    v_7099 = v_7098;
    goto v_7092;
v_7093:
    v_7098 = nil;
    goto v_7094;
v_7095:
    goto v_7091;
v_7092:
    goto v_7093;
v_7094:
    {
        fn = elt(env, 1); // dl_get2
        return (*qfn2(fn))(fn, v_7099, v_7098);
    }
}



// Code for crprcd

static LispObject CC_crprcd(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7108, v_7109;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7088);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7088;
// end of prologue
    v_7108 = stack[0];
    v_7108 = qcdr(v_7108);
    v_7108 = qcar(v_7108);
    fn = elt(env, 1); // convprec!*
    stack[-1] = (*qfn1(fn))(fn, v_7108);
    env = stack[-2];
    v_7108 = stack[0];
    v_7108 = qcdr(v_7108);
    v_7108 = qcdr(v_7108);
    fn = elt(env, 1); // convprec!*
    v_7108 = (*qfn1(fn))(fn, v_7108);
    v_7109 = stack[-1];
    goto v_7105;
v_7101:
    goto v_7102;
v_7103:
    goto v_7104;
v_7105:
    goto v_7101;
v_7102:
    goto v_7103;
v_7104:
    return cons(v_7109, v_7108);
}



// Code for !*q2f

static LispObject CC_Hq2f(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7115, v_7116, v_7117;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7088);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7117 = v_7088;
// end of prologue
    goto v_7098;
v_7094:
    v_7115 = v_7117;
    v_7116 = qcdr(v_7115);
    goto v_7095;
v_7096:
    v_7115 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7097;
v_7098:
    goto v_7094;
v_7095:
    goto v_7096;
v_7097:
    if (v_7116 == v_7115) goto v_7092;
    else goto v_7093;
v_7092:
    v_7115 = v_7117;
    v_7115 = qcar(v_7115);
    goto v_7091;
v_7093:
    goto v_7111;
v_7107:
    v_7115 = v_7117;
    fn = elt(env, 2); // prepsq
    v_7116 = (*qfn1(fn))(fn, v_7115);
    env = stack[0];
    goto v_7108;
v_7109:
    v_7115 = elt(env, 1); // polynomial
    goto v_7110;
v_7111:
    goto v_7107;
v_7108:
    goto v_7109;
v_7110:
    {
        fn = elt(env, 3); // typerr
        return (*qfn2(fn))(fn, v_7116, v_7115);
    }
    v_7115 = nil;
v_7091:
    return onevalue(v_7115);
}



// Code for qqe_ofsf_varlterm

static LispObject CC_qqe_ofsf_varlterm(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7159, v_7160, v_7161, v_7162;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7161 = v_7089;
    v_7162 = v_7088;
// end of prologue
    v_7159 = v_7162;
    if (!consp(v_7159)) goto v_7099;
    else goto v_7100;
v_7099:
    v_7159 = v_7162;
    if (symbolp(v_7159)) goto v_7105;
    v_7159 = nil;
    goto v_7103;
v_7105:
    goto v_7114;
v_7110:
    v_7160 = v_7162;
    goto v_7111;
v_7112:
    v_7159 = elt(env, 1); // qepsilon
    goto v_7113;
v_7114:
    goto v_7110;
v_7111:
    goto v_7112;
v_7113:
    v_7159 = (v_7160 == v_7159 ? lisp_true : nil);
    v_7159 = (v_7159 == nil ? lisp_true : nil);
    goto v_7103;
    v_7159 = nil;
v_7103:
    goto v_7098;
v_7100:
    v_7159 = nil;
    goto v_7098;
    v_7159 = nil;
v_7098:
    if (v_7159 == nil) goto v_7096;
    goto v_7127;
v_7123:
    v_7159 = v_7162;
    goto v_7124;
v_7125:
    v_7160 = v_7161;
    goto v_7126;
v_7127:
    goto v_7123;
v_7124:
    goto v_7125;
v_7126:
    fn = elt(env, 2); // lto_insertq
    v_7159 = (*qfn2(fn))(fn, v_7159, v_7160);
    v_7161 = v_7159;
    goto v_7094;
v_7096:
    v_7159 = v_7162;
    if (!consp(v_7159)) goto v_7131;
    v_7159 = v_7162;
    v_7159 = qcdr(v_7159);
    stack[0] = v_7159;
v_7136:
    v_7159 = stack[0];
    if (v_7159 == nil) goto v_7141;
    else goto v_7142;
v_7141:
    goto v_7135;
v_7142:
    v_7159 = stack[0];
    v_7159 = qcar(v_7159);
    goto v_7153;
v_7149:
    goto v_7150;
v_7151:
    v_7160 = v_7161;
    goto v_7152;
v_7153:
    goto v_7149;
v_7150:
    goto v_7151;
v_7152:
    v_7159 = CC_qqe_ofsf_varlterm(elt(env, 0), v_7159, v_7160);
    env = stack[-1];
    v_7161 = v_7159;
    v_7159 = stack[0];
    v_7159 = qcdr(v_7159);
    stack[0] = v_7159;
    goto v_7136;
v_7135:
    goto v_7094;
v_7131:
v_7094:
    v_7159 = v_7161;
    return onevalue(v_7159);
}



// Code for intexprnp

static LispObject CC_intexprnp(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7165, v_7166, v_7167, v_7168;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7166 = v_7089;
    v_7167 = v_7088;
// end of prologue
    v_7165 = qvalue(elt(env, 1)); // !*revalp
    if (v_7165 == nil) goto v_7093;
    else goto v_7094;
v_7093:
    v_7165 = nil;
    goto v_7092;
v_7094:
    v_7165 = v_7167;
    if (!consp(v_7165)) goto v_7097;
    else goto v_7098;
v_7097:
    v_7165 = v_7167;
    if (is_number(v_7165)) goto v_7102;
    else goto v_7103;
v_7102:
    v_7165 = v_7167;
    v_7165 = integerp(v_7165);
    goto v_7101;
v_7103:
    goto v_7113;
v_7109:
    v_7165 = v_7167;
    goto v_7110;
v_7111:
    goto v_7112;
v_7113:
    goto v_7109;
v_7110:
    goto v_7111;
v_7112:
    v_7165 = Latsoc(nil, v_7165, v_7166);
    v_7167 = v_7165;
    if (v_7165 == nil) goto v_7108;
    goto v_7121;
v_7117:
    v_7165 = v_7167;
    v_7165 = qcdr(v_7165);
    goto v_7118;
v_7119:
    v_7166 = elt(env, 2); // integer
    goto v_7120;
v_7121:
    goto v_7117;
v_7118:
    goto v_7119;
v_7120:
    v_7165 = (v_7165 == v_7166 ? lisp_true : nil);
    goto v_7101;
v_7108:
    v_7165 = nil;
    goto v_7101;
    v_7165 = nil;
v_7101:
    goto v_7092;
v_7098:
    v_7165 = v_7167;
    v_7165 = qcar(v_7165);
    if (symbolp(v_7165)) goto v_7134;
    v_7165 = nil;
    goto v_7132;
v_7134:
    goto v_7149;
v_7145:
    v_7165 = v_7167;
    v_7168 = qcar(v_7165);
    goto v_7146;
v_7147:
    v_7165 = elt(env, 3); // intfn
    goto v_7148;
v_7149:
    goto v_7145;
v_7146:
    goto v_7147;
v_7148:
    v_7165 = Lflagp(nil, v_7168, v_7165);
    env = stack[0];
    if (v_7165 == nil) goto v_7143;
    goto v_7158;
v_7154:
    v_7165 = v_7167;
    v_7165 = qcdr(v_7165);
    goto v_7155;
v_7156:
    goto v_7157;
v_7158:
    goto v_7154;
v_7155:
    goto v_7156;
v_7157:
    {
        fn = elt(env, 4); // intexprlisp
        return (*qfn2(fn))(fn, v_7165, v_7166);
    }
v_7143:
    v_7165 = nil;
    goto v_7141;
    v_7165 = nil;
v_7141:
    goto v_7132;
    v_7165 = nil;
v_7132:
    goto v_7092;
    v_7165 = nil;
v_7092:
    return onevalue(v_7165);
}



// Code for lesspcdr

static LispObject CC_lesspcdr(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7101, v_7102;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7101 = v_7089;
    v_7102 = v_7088;
// end of prologue
    goto v_7096;
v_7092:
    v_7102 = qcdr(v_7102);
    goto v_7093;
v_7094:
    v_7101 = qcdr(v_7101);
    goto v_7095;
v_7096:
    goto v_7092;
v_7093:
    goto v_7094;
v_7095:
        return Llessp(nil, v_7102, v_7101);
}



// Code for cgb_buch!-ev_divides!?

static LispObject CC_cgb_buchKev_dividesW(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7099, v_7100;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7100 = v_7089;
    v_7099 = v_7088;
// end of prologue
    goto v_7096;
v_7092:
    goto v_7093;
v_7094:
    goto v_7095;
v_7096:
    goto v_7092;
v_7093:
    goto v_7094;
v_7095:
    {
        fn = elt(env, 1); // ev_mtest!?
        return (*qfn2(fn))(fn, v_7100, v_7099);
    }
}



// Code for sub_math

static LispObject CC_sub_math(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7233, v_7234;
    LispObject fn;
    argcheck(nargs, 0, "sub_math");
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
    goto v_7102;
v_7098:
    v_7234 = qvalue(elt(env, 1)); // char
    goto v_7099;
v_7100:
    v_7233 = elt(env, 2); // (i d e n t !/)
    goto v_7101;
v_7102:
    goto v_7098;
v_7099:
    goto v_7100;
v_7101:
    if (equal(v_7234, v_7233)) goto v_7096;
    else goto v_7097;
v_7096:
    v_7233 = elt(env, 3); // ident
    return ncons(v_7233);
v_7097:
    goto v_7115;
v_7111:
    v_7234 = qvalue(elt(env, 1)); // char
    goto v_7112;
v_7113:
    v_7233 = elt(env, 4); // (v e c t o r)
    goto v_7114;
v_7115:
    goto v_7111;
v_7112:
    goto v_7113;
v_7114:
    if (equal(v_7234, v_7233)) goto v_7109;
    else goto v_7110;
v_7109:
    fn = elt(env, 10); // vectorrd
    v_7233 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_7233;
    goto v_7127;
v_7123:
    v_7234 = qvalue(elt(env, 1)); // char
    goto v_7124;
v_7125:
    v_7233 = elt(env, 5); // (!/ v e c t o r)
    goto v_7126;
v_7127:
    goto v_7123;
v_7124:
    goto v_7125;
v_7126:
    if (equal(v_7234, v_7233)) goto v_7122;
    goto v_7135;
v_7131:
    v_7234 = elt(env, 6); // "</vector>"
    goto v_7132;
v_7133:
    v_7233 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_7134;
v_7135:
    goto v_7131;
v_7132:
    goto v_7133;
v_7134:
    fn = elt(env, 11); // errorml
    v_7233 = (*qfn2(fn))(fn, v_7234, v_7233);
    goto v_7120;
v_7122:
v_7120:
    v_7233 = stack[-1];
    goto v_7092;
v_7110:
    goto v_7147;
v_7143:
    v_7233 = qvalue(elt(env, 1)); // char
    fn = elt(env, 12); // compress!*
    v_7234 = (*qfn1(fn))(fn, v_7233);
    env = stack[-2];
    goto v_7144;
v_7145:
    v_7233 = qvalue(elt(env, 7)); // constructors!*
    goto v_7146;
v_7147:
    goto v_7143;
v_7144:
    goto v_7145;
v_7146:
    v_7233 = Lassoc(nil, v_7234, v_7233);
    stack[0] = v_7233;
    if (v_7233 == nil) goto v_7142;
    goto v_7157;
v_7153:
    v_7233 = stack[0];
    v_7233 = qcdr(v_7233);
    v_7234 = qcar(v_7233);
    goto v_7154;
v_7155:
    v_7233 = nil;
    goto v_7156;
v_7157:
    goto v_7153;
v_7154:
    goto v_7155;
v_7156:
    fn = elt(env, 13); // apply
    v_7233 = (*qfn2(fn))(fn, v_7234, v_7233);
    env = stack[-2];
    stack[-1] = v_7233;
    v_7233 = stack[-1];
    v_7233 = Lconsp(nil, v_7233);
    env = stack[-2];
    if (v_7233 == nil) goto v_7165;
    goto v_7176;
v_7172:
    v_7233 = stack[-1];
    v_7234 = qcar(v_7233);
    goto v_7173;
v_7174:
    v_7233 = elt(env, 8); // csymbol
    goto v_7175;
v_7176:
    goto v_7172;
v_7173:
    goto v_7174;
v_7175:
    if (v_7234 == v_7233) goto v_7170;
    else goto v_7171;
v_7170:
    v_7233 = stack[-1];
    v_7233 = qcdr(v_7233);
    v_7233 = qcdr(v_7233);
    stack[-1] = v_7233;
    goto v_7169;
v_7171:
v_7169:
    goto v_7163;
v_7165:
v_7163:
    v_7233 = stack[-1];
    v_7233 = Lconsp(nil, v_7233);
    env = stack[-2];
    if (v_7233 == nil) goto v_7186;
    goto v_7197;
v_7193:
    v_7233 = stack[-1];
    v_7234 = qcar(v_7233);
    goto v_7194;
v_7195:
    v_7233 = elt(env, 9); // fn
    goto v_7196;
v_7197:
    goto v_7193;
v_7194:
    goto v_7195;
v_7196:
    if (v_7234 == v_7233) goto v_7191;
    else goto v_7192;
v_7191:
    v_7233 = stack[-1];
    v_7233 = qcdr(v_7233);
    v_7233 = qcdr(v_7233);
    stack[-1] = v_7233;
    goto v_7190;
v_7192:
v_7190:
    goto v_7184;
v_7186:
v_7184:
    goto v_7212;
v_7208:
    v_7233 = qvalue(elt(env, 1)); // char
    fn = elt(env, 12); // compress!*
    v_7234 = (*qfn1(fn))(fn, v_7233);
    env = stack[-2];
    goto v_7209;
v_7210:
    v_7233 = stack[0];
    v_7233 = qcdr(v_7233);
    v_7233 = qcdr(v_7233);
    v_7233 = qcar(v_7233);
    goto v_7211;
v_7212:
    goto v_7208;
v_7209:
    goto v_7210;
v_7211:
    if (equal(v_7234, v_7233)) goto v_7207;
    goto v_7224;
v_7220:
    v_7233 = stack[0];
    v_7233 = qcdr(v_7233);
    v_7233 = qcdr(v_7233);
    v_7233 = qcdr(v_7233);
    v_7234 = qcar(v_7233);
    goto v_7221;
v_7222:
    v_7233 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_7223;
v_7224:
    goto v_7220;
v_7221:
    goto v_7222;
v_7223:
    fn = elt(env, 11); // errorml
    v_7233 = (*qfn2(fn))(fn, v_7234, v_7233);
    goto v_7205;
v_7207:
v_7205:
    v_7233 = stack[-1];
    goto v_7092;
v_7142:
    v_7233 = nil;
v_7092:
    return onevalue(v_7233);
}



// Code for zeropp

static LispObject CC_zeropp(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7112, v_7113, v_7114;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7114 = v_7088;
// end of prologue
    v_7112 = v_7114;
    if (!consp(v_7112)) goto v_7092;
    else goto v_7093;
v_7092:
    v_7112 = v_7114;
        return Lzerop(nil, v_7112);
v_7093:
    goto v_7103;
v_7099:
    v_7112 = v_7114;
    v_7113 = qcar(v_7112);
    goto v_7100;
v_7101:
    v_7112 = elt(env, 1); // !:rd!:
    goto v_7102;
v_7103:
    goto v_7099;
v_7100:
    goto v_7101;
v_7102:
    if (v_7113 == v_7112) goto v_7097;
    else goto v_7098;
v_7097:
    v_7112 = v_7114;
    {
        fn = elt(env, 2); // rd!:zerop
        return (*qfn1(fn))(fn, v_7112);
    }
v_7098:
    v_7112 = nil;
    goto v_7091;
    v_7112 = nil;
v_7091:
    return onevalue(v_7112);
}



// Code for unbind

static LispObject CC_unbind(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7103, v_7104, v_7105;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7104 = v_7088;
// end of prologue
    goto v_7097;
v_7091:
    v_7103 = v_7104;
    goto v_7092;
v_7093:
    v_7105 = elt(env, 1); // binding
    goto v_7094;
v_7095:
    if (!symbolp(v_7104)) v_7104 = nil;
    else { v_7104 = qfastgets(v_7104);
           if (v_7104 != nil) { v_7104 = elt(v_7104, 13); // binding
#ifdef RECORD_GET
             if (v_7104 != SPID_NOPROP)
                record_get(elt(fastget_names, 13), 1);
             else record_get(elt(fastget_names, 13), 0),
                v_7104 = nil; }
           else record_get(elt(fastget_names, 13), 0); }
#else
             if (v_7104 == SPID_NOPROP) v_7104 = nil; }}
#endif
    v_7104 = qcdr(v_7104);
    goto v_7096;
v_7097:
    goto v_7091;
v_7092:
    goto v_7093;
v_7094:
    goto v_7095;
v_7096:
        return Lputprop(nil, 3, v_7103, v_7105, v_7104);
}



// Code for sc_null

static LispObject CC_sc_null(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7093;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7093 = v_7088;
// end of prologue
    v_7093 = qcar(v_7093);
    v_7093 = (v_7093 == nil ? lisp_true : nil);
    return onevalue(v_7093);
}



// Code for assert_dyntypep

static LispObject CC_assert_dyntypep(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7106, v_7107;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7107 = v_7088;
// end of prologue
    v_7106 = v_7107;
    if (symbolp(v_7106)) goto v_7093;
    v_7106 = nil;
    goto v_7091;
v_7093:
    goto v_7103;
v_7099:
    v_7106 = v_7107;
    goto v_7100;
v_7101:
    v_7107 = elt(env, 1); // assert_dyntype
    goto v_7102;
v_7103:
    goto v_7099;
v_7100:
    goto v_7101;
v_7102:
        return Lflagp(nil, v_7106, v_7107);
    v_7106 = nil;
v_7091:
    return onevalue(v_7106);
}



// Code for simptimes

static LispObject CC_simptimes(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7205, v_7206;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7088);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_7088;
// end of prologue
    stack[-2] = nil;
    v_7205 = stack[-1];
    if (v_7205 == nil) goto v_7100;
    else goto v_7101;
v_7100:
    goto v_7108;
v_7104:
    v_7206 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7105;
v_7106:
    v_7205 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7107;
v_7108:
    goto v_7104;
v_7105:
    goto v_7106;
v_7107:
    return cons(v_7206, v_7205);
v_7101:
    goto v_7123;
v_7119:
    v_7206 = qvalue(elt(env, 1)); // tstack!*
    goto v_7120;
v_7121:
    v_7205 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7122;
v_7123:
    goto v_7119;
v_7120:
    goto v_7121;
v_7122:
    if (v_7206 == v_7205) goto v_7118;
    v_7205 = lisp_true;
    goto v_7116;
v_7118:
    v_7205 = qvalue(elt(env, 2)); // mul!*
    v_7205 = (v_7205 == nil ? lisp_true : nil);
    goto v_7116;
    v_7205 = nil;
v_7116:
    if (v_7205 == nil) goto v_7114;
    goto v_7094;
v_7114:
    v_7205 = qvalue(elt(env, 2)); // mul!*
    stack[-2] = v_7205;
    v_7205 = nil;
    qvalue(elt(env, 2)) = v_7205; // mul!*
v_7094:
    v_7205 = qvalue(elt(env, 1)); // tstack!*
    v_7205 = add1(v_7205);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_7205; // tstack!*
    v_7205 = stack[-1];
    fn = elt(env, 4); // simpcar
    v_7205 = (*qfn1(fn))(fn, v_7205);
    env = stack[-3];
    stack[0] = v_7205;
v_7095:
    v_7205 = stack[-1];
    v_7205 = qcdr(v_7205);
    stack[-1] = v_7205;
    v_7205 = stack[0];
    v_7205 = qcar(v_7205);
    if (v_7205 == nil) goto v_7141;
    else goto v_7142;
v_7141:
    goto v_7097;
v_7142:
    v_7205 = stack[-1];
    if (v_7205 == nil) goto v_7145;
    else goto v_7146;
v_7145:
    goto v_7096;
v_7146:
    goto v_7153;
v_7149:
    goto v_7150;
v_7151:
    v_7205 = stack[-1];
    fn = elt(env, 4); // simpcar
    v_7205 = (*qfn1(fn))(fn, v_7205);
    env = stack[-3];
    goto v_7152;
v_7153:
    goto v_7149;
v_7150:
    goto v_7151;
v_7152:
    fn = elt(env, 5); // multsq
    v_7205 = (*qfn2(fn))(fn, stack[0], v_7205);
    env = stack[-3];
    stack[0] = v_7205;
    goto v_7095;
v_7096:
    v_7205 = qvalue(elt(env, 2)); // mul!*
    if (v_7205 == nil) goto v_7163;
    else goto v_7164;
v_7163:
    v_7205 = lisp_true;
    goto v_7162;
v_7164:
    goto v_7174;
v_7170:
    v_7206 = qvalue(elt(env, 1)); // tstack!*
    goto v_7171;
v_7172:
    v_7205 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7173;
v_7174:
    goto v_7170;
v_7171:
    goto v_7172;
v_7173:
    v_7205 = (LispObject)greaterp2(v_7206, v_7205);
    v_7205 = v_7205 ? lisp_true : nil;
    env = stack[-3];
    goto v_7162;
    v_7205 = nil;
v_7162:
    if (v_7205 == nil) goto v_7160;
    goto v_7097;
v_7160:
    goto v_7182;
v_7178:
    v_7205 = qvalue(elt(env, 2)); // mul!*
    v_7206 = qcar(v_7205);
    goto v_7179;
v_7180:
    v_7205 = stack[0];
    goto v_7181;
v_7182:
    goto v_7178;
v_7179:
    goto v_7180;
v_7181:
    v_7205 = Lapply1(nil, v_7206, v_7205);
    env = stack[-3];
    stack[0] = v_7205;
    v_7205 = nil;
    v_7205 = ncons(v_7205);
    env = stack[-3];
    qvalue(elt(env, 3)) = v_7205; // alglist!*
    v_7205 = qvalue(elt(env, 2)); // mul!*
    v_7205 = qcdr(v_7205);
    qvalue(elt(env, 2)) = v_7205; // mul!*
    goto v_7096;
v_7097:
    v_7205 = qvalue(elt(env, 1)); // tstack!*
    v_7205 = sub1(v_7205);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_7205; // tstack!*
    goto v_7200;
v_7196:
    v_7206 = qvalue(elt(env, 1)); // tstack!*
    goto v_7197;
v_7198:
    v_7205 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7199;
v_7200:
    goto v_7196;
v_7197:
    goto v_7198;
v_7199:
    if (v_7206 == v_7205) goto v_7194;
    else goto v_7195;
v_7194:
    v_7205 = stack[-2];
    qvalue(elt(env, 2)) = v_7205; // mul!*
    goto v_7193;
v_7195:
v_7193:
    v_7205 = stack[0];
    return onevalue(v_7205);
}



// Code for pdif

static LispObject CC_pdif(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7100, v_7101;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7100 = v_7089;
    v_7101 = v_7088;
// end of prologue
    goto v_7096;
v_7092:
    stack[0] = v_7101;
    goto v_7093;
v_7094:
    fn = elt(env, 1); // pneg
    v_7100 = (*qfn1(fn))(fn, v_7100);
    env = stack[-1];
    goto v_7095;
v_7096:
    goto v_7092;
v_7093:
    goto v_7094;
v_7095:
    {
        LispObject v_7103 = stack[0];
        fn = elt(env, 2); // psum
        return (*qfn2(fn))(fn, v_7103, v_7100);
    }
}



// Code for lalr_most_common_reduction

static LispObject CC_lalr_most_common_reduction(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7225, v_7226, v_7227;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7088);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_7225 = v_7088;
// end of prologue
    stack[-3] = nil;
    stack[-1] = v_7225;
v_7098:
    v_7225 = stack[-1];
    if (v_7225 == nil) goto v_7102;
    else goto v_7103;
v_7102:
    goto v_7097;
v_7103:
    v_7225 = stack[-1];
    v_7225 = qcar(v_7225);
    v_7226 = v_7225;
    goto v_7121;
v_7117:
    v_7225 = v_7226;
    v_7225 = qcdr(v_7225);
    v_7225 = qcar(v_7225);
    v_7227 = qcar(v_7225);
    goto v_7118;
v_7119:
    v_7225 = elt(env, 1); // reduce
    goto v_7120;
v_7121:
    goto v_7117;
v_7118:
    goto v_7119;
v_7120:
    if (v_7227 == v_7225) goto v_7115;
    else goto v_7116;
v_7115:
    v_7225 = lisp_true;
    goto v_7114;
v_7116:
    goto v_7134;
v_7130:
    v_7225 = v_7226;
    v_7225 = qcdr(v_7225);
    v_7225 = qcar(v_7225);
    v_7227 = qcar(v_7225);
    goto v_7131;
v_7132:
    v_7225 = elt(env, 2); // accept
    goto v_7133;
v_7134:
    goto v_7130;
v_7131:
    goto v_7132;
v_7133:
    v_7225 = (v_7227 == v_7225 ? lisp_true : nil);
    goto v_7114;
    v_7225 = nil;
v_7114:
    if (v_7225 == nil) goto v_7112;
    v_7225 = v_7226;
    v_7225 = qcdr(v_7225);
    v_7225 = qcar(v_7225);
    v_7227 = v_7225;
    goto v_7152;
v_7148:
    goto v_7149;
v_7150:
    v_7225 = v_7227;
    goto v_7151;
v_7152:
    goto v_7148;
v_7149:
    goto v_7150;
v_7151:
    v_7225 = Lassoc(nil, v_7226, v_7225);
    stack[-2] = v_7225;
    if (v_7225 == nil) goto v_7147;
    goto v_7161;
v_7157:
    stack[0] = stack[-2];
    goto v_7158;
v_7159:
    v_7225 = stack[-2];
    v_7225 = qcdr(v_7225);
    v_7225 = add1(v_7225);
    env = stack[-4];
    goto v_7160;
v_7161:
    goto v_7157;
v_7158:
    goto v_7159;
v_7160:
    v_7225 = Lrplacd(nil, stack[0], v_7225);
    env = stack[-4];
    goto v_7145;
v_7147:
    goto v_7175;
v_7169:
    goto v_7170;
v_7171:
    v_7226 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7172;
v_7173:
    v_7225 = stack[-3];
    goto v_7174;
v_7175:
    goto v_7169;
v_7170:
    goto v_7171;
v_7172:
    goto v_7173;
v_7174:
    v_7225 = acons(v_7227, v_7226, v_7225);
    env = stack[-4];
    stack[-3] = v_7225;
    goto v_7145;
v_7145:
    goto v_7110;
v_7112:
v_7110:
    v_7225 = stack[-1];
    v_7225 = qcdr(v_7225);
    stack[-1] = v_7225;
    goto v_7098;
v_7097:
    v_7225 = stack[-3];
    if (v_7225 == nil) goto v_7184;
    v_7225 = stack[-3];
    v_7225 = qcar(v_7225);
    stack[-2] = v_7225;
    v_7225 = stack[-3];
    v_7225 = qcdr(v_7225);
    stack[-1] = v_7225;
v_7191:
    v_7225 = stack[-1];
    if (v_7225 == nil) goto v_7196;
    else goto v_7197;
v_7196:
    goto v_7190;
v_7197:
    v_7225 = stack[-1];
    v_7225 = qcar(v_7225);
    stack[0] = v_7225;
    goto v_7212;
v_7208:
    v_7225 = stack[0];
    v_7226 = qcdr(v_7225);
    goto v_7209;
v_7210:
    v_7225 = stack[-2];
    v_7225 = qcdr(v_7225);
    goto v_7211;
v_7212:
    goto v_7208;
v_7209:
    goto v_7210;
v_7211:
    v_7225 = (LispObject)greaterp2(v_7226, v_7225);
    v_7225 = v_7225 ? lisp_true : nil;
    env = stack[-4];
    if (v_7225 == nil) goto v_7206;
    v_7225 = stack[0];
    stack[-2] = v_7225;
    goto v_7204;
v_7206:
v_7204:
    v_7225 = stack[-1];
    v_7225 = qcdr(v_7225);
    stack[-1] = v_7225;
    goto v_7191;
v_7190:
    v_7225 = stack[-2];
    v_7225 = qcar(v_7225);
    goto v_7094;
v_7184:
    v_7225 = nil;
    goto v_7094;
    v_7225 = nil;
v_7094:
    return onevalue(v_7225);
}



// Code for quotfdx

static LispObject CC_quotfdx(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7146, v_7147, v_7148, v_7149;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7148 = v_7089;
    v_7149 = v_7088;
// end of prologue
    goto v_7099;
v_7095:
    v_7147 = v_7149;
    goto v_7096;
v_7097:
    v_7146 = v_7148;
    goto v_7098;
v_7099:
    goto v_7095;
v_7096:
    goto v_7097;
v_7098:
    if (equal(v_7147, v_7146)) goto v_7093;
    else goto v_7094;
v_7093:
    v_7146 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7092;
v_7094:
    v_7146 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_7146)) v_7146 = nil;
    else { v_7146 = qfastgets(v_7146);
           if (v_7146 != nil) { v_7146 = elt(v_7146, 3); // field
#ifdef RECORD_GET
             if (v_7146 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_7146 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_7146 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_7146 == SPID_NOPROP) v_7146 = nil; else v_7146 = lisp_true; }}
#endif
    if (v_7146 == nil) goto v_7104;
    goto v_7112;
v_7108:
    v_7146 = v_7149;
    goto v_7109;
v_7110:
    v_7147 = v_7148;
    goto v_7111;
v_7112:
    goto v_7108;
v_7109:
    goto v_7110;
v_7111:
    {
        fn = elt(env, 2); // divd
        return (*qfn2(fn))(fn, v_7146, v_7147);
    }
v_7104:
    v_7146 = v_7149;
    if (!consp(v_7146)) goto v_7119;
    else goto v_7120;
v_7119:
    v_7146 = lisp_true;
    goto v_7118;
v_7120:
    v_7146 = v_7149;
    v_7146 = qcar(v_7146);
    v_7146 = (consp(v_7146) ? nil : lisp_true);
    goto v_7118;
    v_7146 = nil;
v_7118:
    if (v_7146 == nil) goto v_7116;
    goto v_7133;
v_7129:
    v_7146 = v_7149;
    goto v_7130;
v_7131:
    v_7147 = v_7148;
    goto v_7132;
v_7133:
    goto v_7129;
v_7130:
    goto v_7131;
v_7132:
    {
        fn = elt(env, 3); // quotdd
        return (*qfn2(fn))(fn, v_7146, v_7147);
    }
v_7116:
    goto v_7143;
v_7139:
    v_7146 = v_7149;
    goto v_7140;
v_7141:
    v_7147 = v_7148;
    goto v_7142;
v_7143:
    goto v_7139;
v_7140:
    goto v_7141;
v_7142:
    {
        fn = elt(env, 4); // quotkx
        return (*qfn2(fn))(fn, v_7146, v_7147);
    }
    v_7146 = nil;
v_7092:
    return onevalue(v_7146);
}



// Code for undefdchk

static LispObject CC_undefdchk(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7110, v_7111, v_7112;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7088);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7111 = v_7088;
// end of prologue
    goto v_7099;
v_7095:
    v_7112 = v_7111;
    goto v_7096;
v_7097:
    v_7110 = elt(env, 1); // defd
    goto v_7098;
v_7099:
    goto v_7095;
v_7096:
    goto v_7097;
v_7098:
    v_7110 = Lflagp(nil, v_7112, v_7110);
    env = stack[0];
    if (v_7110 == nil) goto v_7092;
    else goto v_7093;
v_7092:
    goto v_7107;
v_7103:
    goto v_7104;
v_7105:
    v_7110 = qvalue(elt(env, 2)); // undefns!*
    goto v_7106;
v_7107:
    goto v_7103;
v_7104:
    goto v_7105;
v_7106:
    v_7110 = cons(v_7111, v_7110);
    env = stack[0];
    qvalue(elt(env, 2)) = v_7110; // undefns!*
    goto v_7091;
v_7093:
    v_7110 = nil;
v_7091:
    return onevalue(v_7110);
}



// Code for rl_simp

static LispObject CC_rl_simp(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7093;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7088);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7093 = v_7088;
// end of prologue
    fn = elt(env, 1); // rl_simp1
    v_7093 = (*qfn1(fn))(fn, v_7093);
    env = stack[0];
    {
        fn = elt(env, 2); // rl_csimpl
        return (*qfn1(fn))(fn, v_7093);
    }
}



// Code for mk!+mat!+mult!+mat

static LispObject CC_mkLmatLmultLmat(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7558, v_7559, v_7560;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(17);
// copy arguments values to proper place
    stack[-13] = v_7089;
    stack[-14] = v_7088;
// end of prologue
    v_7558 = stack[-14];
    fn = elt(env, 4); // matrix!+p
    v_7558 = (*qfn1(fn))(fn, v_7558);
    env = stack[-16];
    if (v_7558 == nil) goto v_7103;
    else goto v_7104;
v_7103:
    v_7558 = elt(env, 1); // "no matrix in mult"
    fn = elt(env, 5); // rederr
    v_7558 = (*qfn1(fn))(fn, v_7558);
    env = stack[-16];
    goto v_7102;
v_7104:
v_7102:
    v_7558 = stack[-13];
    fn = elt(env, 4); // matrix!+p
    v_7558 = (*qfn1(fn))(fn, v_7558);
    env = stack[-16];
    if (v_7558 == nil) goto v_7111;
    else goto v_7112;
v_7111:
    v_7558 = elt(env, 1); // "no matrix in mult"
    fn = elt(env, 5); // rederr
    v_7558 = (*qfn1(fn))(fn, v_7558);
    env = stack[-16];
    goto v_7110;
v_7112:
v_7110:
    v_7558 = stack[-14];
    fn = elt(env, 6); // get!+col!+nr
    v_7558 = (*qfn1(fn))(fn, v_7558);
    env = stack[-16];
    stack[-15] = v_7558;
    v_7558 = stack[-14];
    fn = elt(env, 7); // get!+row!+nr
    v_7558 = (*qfn1(fn))(fn, v_7558);
    env = stack[-16];
    stack[-12] = v_7558;
    v_7558 = stack[-13];
    fn = elt(env, 6); // get!+col!+nr
    v_7558 = (*qfn1(fn))(fn, v_7558);
    env = stack[-16];
    stack[-11] = v_7558;
    goto v_7131;
v_7127:
    stack[0] = stack[-15];
    goto v_7128;
v_7129:
    v_7558 = stack[-13];
    fn = elt(env, 7); // get!+row!+nr
    v_7558 = (*qfn1(fn))(fn, v_7558);
    env = stack[-16];
    goto v_7130;
v_7131:
    goto v_7127;
v_7128:
    goto v_7129;
v_7130:
    if (equal(stack[0], v_7558)) goto v_7126;
    v_7558 = elt(env, 2); // "matrices can not be multiplied"
    fn = elt(env, 5); // rederr
    v_7558 = (*qfn1(fn))(fn, v_7558);
    env = stack[-16];
    goto v_7124;
v_7126:
v_7124:
    v_7558 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-10] = v_7558;
    goto v_7154;
v_7150:
    v_7559 = stack[-12];
    goto v_7151;
v_7152:
    v_7558 = stack[-10];
    goto v_7153;
v_7154:
    goto v_7150;
v_7151:
    goto v_7152;
v_7153:
    v_7558 = difference2(v_7559, v_7558);
    env = stack[-16];
    v_7558 = Lminusp(nil, v_7558);
    env = stack[-16];
    if (v_7558 == nil) goto v_7147;
    v_7558 = nil;
    goto v_7141;
v_7147:
    v_7558 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_7558;
    goto v_7176;
v_7172:
    v_7559 = stack[-11];
    goto v_7173;
v_7174:
    v_7558 = stack[-5];
    goto v_7175;
v_7176:
    goto v_7172;
v_7173:
    goto v_7174;
v_7175:
    v_7558 = difference2(v_7559, v_7558);
    env = stack[-16];
    v_7558 = Lminusp(nil, v_7558);
    env = stack[-16];
    if (v_7558 == nil) goto v_7169;
    v_7558 = nil;
    goto v_7163;
v_7169:
    goto v_7186;
v_7182:
    v_7559 = nil;
    goto v_7183;
v_7184:
    v_7558 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7185;
v_7186:
    goto v_7182;
v_7183:
    goto v_7184;
v_7185:
    v_7558 = cons(v_7559, v_7558);
    env = stack[-16];
    stack[0] = v_7558;
    v_7558 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_7558;
v_7192:
    goto v_7204;
v_7200:
    v_7559 = stack[-15];
    goto v_7201;
v_7202:
    v_7558 = stack[-1];
    goto v_7203;
v_7204:
    goto v_7200;
v_7201:
    goto v_7202;
v_7203:
    v_7558 = difference2(v_7559, v_7558);
    env = stack[-16];
    v_7558 = Lminusp(nil, v_7558);
    env = stack[-16];
    if (v_7558 == nil) goto v_7197;
    goto v_7191;
v_7197:
    goto v_7213;
v_7209:
    stack[-2] = stack[0];
    goto v_7210;
v_7211:
    goto v_7220;
v_7216:
    goto v_7228;
v_7222:
    v_7560 = stack[-14];
    goto v_7223;
v_7224:
    v_7559 = stack[-10];
    goto v_7225;
v_7226:
    v_7558 = stack[-1];
    goto v_7227;
v_7228:
    goto v_7222;
v_7223:
    goto v_7224;
v_7225:
    goto v_7226;
v_7227:
    fn = elt(env, 8); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(fn, 3, v_7560, v_7559, v_7558);
    env = stack[-16];
    goto v_7217;
v_7218:
    goto v_7239;
v_7233:
    v_7560 = stack[-13];
    goto v_7234;
v_7235:
    v_7559 = stack[-1];
    goto v_7236;
v_7237:
    v_7558 = stack[-5];
    goto v_7238;
v_7239:
    goto v_7233;
v_7234:
    goto v_7235;
v_7236:
    goto v_7237;
v_7238:
    fn = elt(env, 8); // get!+mat!+entry
    v_7558 = (*qfnn(fn))(fn, 3, v_7560, v_7559, v_7558);
    env = stack[-16];
    goto v_7219;
v_7220:
    goto v_7216;
v_7217:
    goto v_7218;
v_7219:
    fn = elt(env, 9); // multsq
    v_7558 = (*qfn2(fn))(fn, stack[0], v_7558);
    env = stack[-16];
    goto v_7212;
v_7213:
    goto v_7209;
v_7210:
    goto v_7211;
v_7212:
    fn = elt(env, 10); // addsq
    v_7558 = (*qfn2(fn))(fn, stack[-2], v_7558);
    env = stack[-16];
    stack[0] = v_7558;
    v_7558 = stack[-1];
    v_7558 = add1(v_7558);
    env = stack[-16];
    stack[-1] = v_7558;
    goto v_7192;
v_7191:
    v_7558 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=16 litvec-offset=3 saveloc=1
{   bind_fluid_stack bind_fluid_var(-16, 3, -1);
    qvalue(elt(env, 3)) = v_7558; // !*sub2
    v_7558 = stack[0];
    fn = elt(env, 11); // subs2
    v_7558 = (*qfn1(fn))(fn, v_7558);
    env = stack[-16];
    stack[0] = v_7558;
    ;}  // end of a binding scope
    v_7558 = stack[0];
    v_7558 = ncons(v_7558);
    env = stack[-16];
    stack[-3] = v_7558;
    stack[-4] = v_7558;
v_7164:
    v_7558 = stack[-5];
    v_7558 = add1(v_7558);
    env = stack[-16];
    stack[-5] = v_7558;
    goto v_7262;
v_7258:
    v_7559 = stack[-11];
    goto v_7259;
v_7260:
    v_7558 = stack[-5];
    goto v_7261;
v_7262:
    goto v_7258;
v_7259:
    goto v_7260;
v_7261:
    v_7558 = difference2(v_7559, v_7558);
    env = stack[-16];
    v_7558 = Lminusp(nil, v_7558);
    env = stack[-16];
    if (v_7558 == nil) goto v_7255;
    v_7558 = stack[-4];
    goto v_7163;
v_7255:
    goto v_7271;
v_7267:
    stack[-2] = stack[-3];
    goto v_7268;
v_7269:
    goto v_7279;
v_7275:
    v_7559 = nil;
    goto v_7276;
v_7277:
    v_7558 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7278;
v_7279:
    goto v_7275;
v_7276:
    goto v_7277;
v_7278:
    v_7558 = cons(v_7559, v_7558);
    env = stack[-16];
    stack[0] = v_7558;
    v_7558 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_7558;
v_7285:
    goto v_7297;
v_7293:
    v_7559 = stack[-15];
    goto v_7294;
v_7295:
    v_7558 = stack[-1];
    goto v_7296;
v_7297:
    goto v_7293;
v_7294:
    goto v_7295;
v_7296:
    v_7558 = difference2(v_7559, v_7558);
    env = stack[-16];
    v_7558 = Lminusp(nil, v_7558);
    env = stack[-16];
    if (v_7558 == nil) goto v_7290;
    goto v_7284;
v_7290:
    goto v_7306;
v_7302:
    stack[-6] = stack[0];
    goto v_7303;
v_7304:
    goto v_7313;
v_7309:
    goto v_7321;
v_7315:
    v_7560 = stack[-14];
    goto v_7316;
v_7317:
    v_7559 = stack[-10];
    goto v_7318;
v_7319:
    v_7558 = stack[-1];
    goto v_7320;
v_7321:
    goto v_7315;
v_7316:
    goto v_7317;
v_7318:
    goto v_7319;
v_7320:
    fn = elt(env, 8); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(fn, 3, v_7560, v_7559, v_7558);
    env = stack[-16];
    goto v_7310;
v_7311:
    goto v_7332;
v_7326:
    v_7560 = stack[-13];
    goto v_7327;
v_7328:
    v_7559 = stack[-1];
    goto v_7329;
v_7330:
    v_7558 = stack[-5];
    goto v_7331;
v_7332:
    goto v_7326;
v_7327:
    goto v_7328;
v_7329:
    goto v_7330;
v_7331:
    fn = elt(env, 8); // get!+mat!+entry
    v_7558 = (*qfnn(fn))(fn, 3, v_7560, v_7559, v_7558);
    env = stack[-16];
    goto v_7312;
v_7313:
    goto v_7309;
v_7310:
    goto v_7311;
v_7312:
    fn = elt(env, 9); // multsq
    v_7558 = (*qfn2(fn))(fn, stack[0], v_7558);
    env = stack[-16];
    goto v_7305;
v_7306:
    goto v_7302;
v_7303:
    goto v_7304;
v_7305:
    fn = elt(env, 10); // addsq
    v_7558 = (*qfn2(fn))(fn, stack[-6], v_7558);
    env = stack[-16];
    stack[0] = v_7558;
    v_7558 = stack[-1];
    v_7558 = add1(v_7558);
    env = stack[-16];
    stack[-1] = v_7558;
    goto v_7285;
v_7284:
    v_7558 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=16 litvec-offset=3 saveloc=1
{   bind_fluid_stack bind_fluid_var(-16, 3, -1);
    qvalue(elt(env, 3)) = v_7558; // !*sub2
    v_7558 = stack[0];
    fn = elt(env, 11); // subs2
    v_7558 = (*qfn1(fn))(fn, v_7558);
    env = stack[-16];
    stack[0] = v_7558;
    ;}  // end of a binding scope
    v_7558 = stack[0];
    v_7558 = ncons(v_7558);
    env = stack[-16];
    goto v_7270;
v_7271:
    goto v_7267;
v_7268:
    goto v_7269;
v_7270:
    v_7558 = Lrplacd(nil, stack[-2], v_7558);
    env = stack[-16];
    v_7558 = stack[-3];
    v_7558 = qcdr(v_7558);
    stack[-3] = v_7558;
    goto v_7164;
v_7163:
    v_7558 = ncons(v_7558);
    env = stack[-16];
    stack[-8] = v_7558;
    stack[-9] = v_7558;
v_7142:
    v_7558 = stack[-10];
    v_7558 = add1(v_7558);
    env = stack[-16];
    stack[-10] = v_7558;
    goto v_7357;
v_7353:
    v_7559 = stack[-12];
    goto v_7354;
v_7355:
    v_7558 = stack[-10];
    goto v_7356;
v_7357:
    goto v_7353;
v_7354:
    goto v_7355;
v_7356:
    v_7558 = difference2(v_7559, v_7558);
    env = stack[-16];
    v_7558 = Lminusp(nil, v_7558);
    env = stack[-16];
    if (v_7558 == nil) goto v_7350;
    v_7558 = stack[-9];
    goto v_7141;
v_7350:
    goto v_7366;
v_7362:
    stack[-7] = stack[-8];
    goto v_7363;
v_7364:
    v_7558 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_7558;
    goto v_7386;
v_7382:
    v_7559 = stack[-11];
    goto v_7383;
v_7384:
    v_7558 = stack[-6];
    goto v_7385;
v_7386:
    goto v_7382;
v_7383:
    goto v_7384;
v_7385:
    v_7558 = difference2(v_7559, v_7558);
    env = stack[-16];
    v_7558 = Lminusp(nil, v_7558);
    env = stack[-16];
    if (v_7558 == nil) goto v_7379;
    v_7558 = nil;
    goto v_7373;
v_7379:
    goto v_7396;
v_7392:
    v_7559 = nil;
    goto v_7393;
v_7394:
    v_7558 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7395;
v_7396:
    goto v_7392;
v_7393:
    goto v_7394;
v_7395:
    v_7558 = cons(v_7559, v_7558);
    env = stack[-16];
    stack[0] = v_7558;
    v_7558 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_7558;
v_7402:
    goto v_7414;
v_7410:
    v_7559 = stack[-15];
    goto v_7411;
v_7412:
    v_7558 = stack[-1];
    goto v_7413;
v_7414:
    goto v_7410;
v_7411:
    goto v_7412;
v_7413:
    v_7558 = difference2(v_7559, v_7558);
    env = stack[-16];
    v_7558 = Lminusp(nil, v_7558);
    env = stack[-16];
    if (v_7558 == nil) goto v_7407;
    goto v_7401;
v_7407:
    goto v_7423;
v_7419:
    stack[-2] = stack[0];
    goto v_7420;
v_7421:
    goto v_7430;
v_7426:
    goto v_7438;
v_7432:
    v_7560 = stack[-14];
    goto v_7433;
v_7434:
    v_7559 = stack[-10];
    goto v_7435;
v_7436:
    v_7558 = stack[-1];
    goto v_7437;
v_7438:
    goto v_7432;
v_7433:
    goto v_7434;
v_7435:
    goto v_7436;
v_7437:
    fn = elt(env, 8); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(fn, 3, v_7560, v_7559, v_7558);
    env = stack[-16];
    goto v_7427;
v_7428:
    goto v_7449;
v_7443:
    v_7560 = stack[-13];
    goto v_7444;
v_7445:
    v_7559 = stack[-1];
    goto v_7446;
v_7447:
    v_7558 = stack[-6];
    goto v_7448;
v_7449:
    goto v_7443;
v_7444:
    goto v_7445;
v_7446:
    goto v_7447;
v_7448:
    fn = elt(env, 8); // get!+mat!+entry
    v_7558 = (*qfnn(fn))(fn, 3, v_7560, v_7559, v_7558);
    env = stack[-16];
    goto v_7429;
v_7430:
    goto v_7426;
v_7427:
    goto v_7428;
v_7429:
    fn = elt(env, 9); // multsq
    v_7558 = (*qfn2(fn))(fn, stack[0], v_7558);
    env = stack[-16];
    goto v_7422;
v_7423:
    goto v_7419;
v_7420:
    goto v_7421;
v_7422:
    fn = elt(env, 10); // addsq
    v_7558 = (*qfn2(fn))(fn, stack[-2], v_7558);
    env = stack[-16];
    stack[0] = v_7558;
    v_7558 = stack[-1];
    v_7558 = add1(v_7558);
    env = stack[-16];
    stack[-1] = v_7558;
    goto v_7402;
v_7401:
    v_7558 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=16 litvec-offset=3 saveloc=1
{   bind_fluid_stack bind_fluid_var(-16, 3, -1);
    qvalue(elt(env, 3)) = v_7558; // !*sub2
    v_7558 = stack[0];
    fn = elt(env, 11); // subs2
    v_7558 = (*qfn1(fn))(fn, v_7558);
    env = stack[-16];
    stack[0] = v_7558;
    ;}  // end of a binding scope
    v_7558 = stack[0];
    v_7558 = ncons(v_7558);
    env = stack[-16];
    stack[-4] = v_7558;
    stack[-5] = v_7558;
v_7374:
    v_7558 = stack[-6];
    v_7558 = add1(v_7558);
    env = stack[-16];
    stack[-6] = v_7558;
    goto v_7472;
v_7468:
    v_7559 = stack[-11];
    goto v_7469;
v_7470:
    v_7558 = stack[-6];
    goto v_7471;
v_7472:
    goto v_7468;
v_7469:
    goto v_7470;
v_7471:
    v_7558 = difference2(v_7559, v_7558);
    env = stack[-16];
    v_7558 = Lminusp(nil, v_7558);
    env = stack[-16];
    if (v_7558 == nil) goto v_7465;
    v_7558 = stack[-5];
    goto v_7373;
v_7465:
    goto v_7481;
v_7477:
    stack[-3] = stack[-4];
    goto v_7478;
v_7479:
    goto v_7489;
v_7485:
    v_7559 = nil;
    goto v_7486;
v_7487:
    v_7558 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7488;
v_7489:
    goto v_7485;
v_7486:
    goto v_7487;
v_7488:
    v_7558 = cons(v_7559, v_7558);
    env = stack[-16];
    stack[0] = v_7558;
    v_7558 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_7558;
v_7495:
    goto v_7507;
v_7503:
    v_7559 = stack[-15];
    goto v_7504;
v_7505:
    v_7558 = stack[-2];
    goto v_7506;
v_7507:
    goto v_7503;
v_7504:
    goto v_7505;
v_7506:
    v_7558 = difference2(v_7559, v_7558);
    env = stack[-16];
    v_7558 = Lminusp(nil, v_7558);
    env = stack[-16];
    if (v_7558 == nil) goto v_7500;
    goto v_7494;
v_7500:
    goto v_7516;
v_7512:
    stack[-1] = stack[0];
    goto v_7513;
v_7514:
    goto v_7523;
v_7519:
    goto v_7531;
v_7525:
    v_7560 = stack[-14];
    goto v_7526;
v_7527:
    v_7559 = stack[-10];
    goto v_7528;
v_7529:
    v_7558 = stack[-2];
    goto v_7530;
v_7531:
    goto v_7525;
v_7526:
    goto v_7527;
v_7528:
    goto v_7529;
v_7530:
    fn = elt(env, 8); // get!+mat!+entry
    stack[0] = (*qfnn(fn))(fn, 3, v_7560, v_7559, v_7558);
    env = stack[-16];
    goto v_7520;
v_7521:
    goto v_7542;
v_7536:
    v_7560 = stack[-13];
    goto v_7537;
v_7538:
    v_7559 = stack[-2];
    goto v_7539;
v_7540:
    v_7558 = stack[-6];
    goto v_7541;
v_7542:
    goto v_7536;
v_7537:
    goto v_7538;
v_7539:
    goto v_7540;
v_7541:
    fn = elt(env, 8); // get!+mat!+entry
    v_7558 = (*qfnn(fn))(fn, 3, v_7560, v_7559, v_7558);
    env = stack[-16];
    goto v_7522;
v_7523:
    goto v_7519;
v_7520:
    goto v_7521;
v_7522:
    fn = elt(env, 9); // multsq
    v_7558 = (*qfn2(fn))(fn, stack[0], v_7558);
    env = stack[-16];
    goto v_7515;
v_7516:
    goto v_7512;
v_7513:
    goto v_7514;
v_7515:
    fn = elt(env, 10); // addsq
    v_7558 = (*qfn2(fn))(fn, stack[-1], v_7558);
    env = stack[-16];
    stack[0] = v_7558;
    v_7558 = stack[-2];
    v_7558 = add1(v_7558);
    env = stack[-16];
    stack[-2] = v_7558;
    goto v_7495;
v_7494:
    v_7558 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=16 litvec-offset=3 saveloc=1
{   bind_fluid_stack bind_fluid_var(-16, 3, -1);
    qvalue(elt(env, 3)) = v_7558; // !*sub2
    v_7558 = stack[0];
    fn = elt(env, 11); // subs2
    v_7558 = (*qfn1(fn))(fn, v_7558);
    env = stack[-16];
    stack[0] = v_7558;
    ;}  // end of a binding scope
    v_7558 = stack[0];
    v_7558 = ncons(v_7558);
    env = stack[-16];
    goto v_7480;
v_7481:
    goto v_7477;
v_7478:
    goto v_7479;
v_7480:
    v_7558 = Lrplacd(nil, stack[-3], v_7558);
    env = stack[-16];
    v_7558 = stack[-4];
    v_7558 = qcdr(v_7558);
    stack[-4] = v_7558;
    goto v_7374;
v_7373:
    v_7558 = ncons(v_7558);
    env = stack[-16];
    goto v_7365;
v_7366:
    goto v_7362;
v_7363:
    goto v_7364;
v_7365:
    v_7558 = Lrplacd(nil, stack[-7], v_7558);
    env = stack[-16];
    v_7558 = stack[-8];
    v_7558 = qcdr(v_7558);
    stack[-8] = v_7558;
    goto v_7142;
v_7141:
    return onevalue(v_7558);
}



// Code for talp_chkknowl

static LispObject CC_talp_chkknowl(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7230, v_7231;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-1] = v_7089;
    stack[-2] = v_7088;
// end of prologue
    stack[-4] = nil;
    stack[0] = nil;
    v_7230 = stack[-2];
    fn = elt(env, 3); // talp_candp
    v_7230 = (*qfn1(fn))(fn, v_7230);
    env = stack[-8];
    if (v_7230 == nil) goto v_7104;
    v_7230 = stack[-2];
    fn = elt(env, 4); // talp_arg2l
    v_7230 = (*qfn1(fn))(fn, v_7230);
    env = stack[-8];
    if (!consp(v_7230)) goto v_7109;
    else goto v_7110;
v_7109:
    v_7230 = stack[-2];
    fn = elt(env, 4); // talp_arg2l
    v_7230 = (*qfn1(fn))(fn, v_7230);
    env = stack[-8];
    stack[-5] = v_7230;
    v_7230 = stack[-2];
    fn = elt(env, 5); // talp_arg2r
    v_7230 = (*qfn1(fn))(fn, v_7230);
    env = stack[-8];
    goto v_7108;
v_7110:
    v_7230 = stack[-2];
    fn = elt(env, 5); // talp_arg2r
    v_7230 = (*qfn1(fn))(fn, v_7230);
    env = stack[-8];
    stack[-5] = v_7230;
    v_7230 = stack[-2];
    fn = elt(env, 4); // talp_arg2l
    v_7230 = (*qfn1(fn))(fn, v_7230);
    env = stack[-8];
    goto v_7108;
    v_7230 = nil;
v_7108:
    stack[-7] = v_7230;
    v_7230 = stack[-7];
    fn = elt(env, 6); // talp_invf
    v_7230 = (*qfn1(fn))(fn, v_7230);
    env = stack[-8];
    stack[-6] = v_7230;
    v_7230 = stack[-2];
    fn = elt(env, 7); // talp_op
    v_7230 = (*qfn1(fn))(fn, v_7230);
    env = stack[-8];
    stack[-2] = v_7230;
    v_7230 = stack[-1];
    stack[-1] = v_7230;
v_7130:
    v_7230 = stack[-1];
    if (v_7230 == nil) goto v_7133;
    v_7230 = stack[-4];
    if (v_7230 == nil) goto v_7137;
    else goto v_7133;
v_7137:
    goto v_7134;
v_7133:
    goto v_7129;
v_7134:
    v_7230 = stack[-1];
    v_7230 = qcar(v_7230);
    v_7230 = qcar(v_7230);
    stack[-3] = v_7230;
    v_7230 = stack[-3];
    fn = elt(env, 3); // talp_candp
    v_7230 = (*qfn1(fn))(fn, v_7230);
    env = stack[-8];
    if (v_7230 == nil) goto v_7146;
    v_7230 = stack[-3];
    fn = elt(env, 4); // talp_arg2l
    v_7230 = (*qfn1(fn))(fn, v_7230);
    env = stack[-8];
    fn = elt(env, 8); // talp_invp
    v_7230 = (*qfn1(fn))(fn, v_7230);
    env = stack[-8];
    if (v_7230 == nil) goto v_7152;
    v_7230 = stack[-3];
    fn = elt(env, 4); // talp_arg2l
    v_7230 = (*qfn1(fn))(fn, v_7230);
    env = stack[-8];
    goto v_7150;
v_7152:
    v_7230 = stack[-3];
    fn = elt(env, 5); // talp_arg2r
    v_7230 = (*qfn1(fn))(fn, v_7230);
    env = stack[-8];
    goto v_7150;
    v_7230 = nil;
v_7150:
    stack[-7] = v_7230;
    goto v_7170;
v_7166:
    v_7230 = stack[-7];
    fn = elt(env, 9); // talp_invarg
    v_7231 = (*qfn1(fn))(fn, v_7230);
    env = stack[-8];
    goto v_7167;
v_7168:
    v_7230 = stack[-5];
    goto v_7169;
v_7170:
    goto v_7166;
v_7167:
    goto v_7168;
v_7169:
    if (v_7231 == v_7230) goto v_7164;
    else goto v_7165;
v_7164:
    goto v_7186;
v_7182:
    v_7230 = stack[-3];
    if (!consp(v_7230)) goto v_7189;
    else goto v_7190;
v_7189:
    v_7230 = stack[-3];
    v_7231 = v_7230;
    goto v_7188;
v_7190:
    v_7230 = stack[-3];
    v_7230 = qcar(v_7230);
    v_7231 = v_7230;
    goto v_7188;
    v_7231 = nil;
v_7188:
    goto v_7183;
v_7184:
    v_7230 = stack[-2];
    goto v_7185;
v_7186:
    goto v_7182;
v_7183:
    goto v_7184;
v_7185:
    if (v_7231 == v_7230) goto v_7180;
    else goto v_7181;
v_7180:
    goto v_7202;
v_7198:
    v_7231 = stack[-2];
    goto v_7199;
v_7200:
    v_7230 = elt(env, 1); // neq
    goto v_7201;
v_7202:
    goto v_7198;
v_7199:
    goto v_7200;
v_7201:
    v_7230 = (v_7231 == v_7230 ? lisp_true : nil);
    goto v_7179;
v_7181:
    v_7230 = nil;
    goto v_7179;
    v_7230 = nil;
v_7179:
    if (v_7230 == nil) goto v_7177;
    goto v_7217;
v_7213:
    v_7230 = stack[-7];
    fn = elt(env, 6); // talp_invf
    v_7231 = (*qfn1(fn))(fn, v_7230);
    env = stack[-8];
    goto v_7214;
v_7215:
    v_7230 = stack[-6];
    goto v_7216;
v_7217:
    goto v_7213;
v_7214:
    goto v_7215;
v_7216:
    if (equal(v_7231, v_7230)) goto v_7212;
    v_7230 = elt(env, 2); // true
    stack[0] = v_7230;
    v_7230 = lisp_true;
    stack[-4] = v_7230;
    goto v_7210;
v_7212:
v_7210:
    goto v_7175;
v_7177:
v_7175:
    goto v_7163;
v_7165:
v_7163:
    goto v_7144;
v_7146:
v_7144:
    v_7230 = stack[-1];
    v_7230 = qcdr(v_7230);
    stack[-1] = v_7230;
    goto v_7130;
v_7129:
    goto v_7102;
v_7104:
    v_7230 = nil;
    goto v_7100;
v_7102:
    v_7230 = stack[0];
v_7100:
    return onevalue(v_7230);
}



// Code for qqe_ofsf_prepat

static LispObject CC_qqe_ofsf_prepat(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7103;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7088);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_7088;
// end of prologue
    v_7103 = stack[0];
    fn = elt(env, 1); // qqe_op
    v_7103 = (*qfn1(fn))(fn, v_7103);
    env = stack[-1];
    fn = elt(env, 2); // qqe_rqopp
    v_7103 = (*qfn1(fn))(fn, v_7103);
    env = stack[-1];
    if (v_7103 == nil) goto v_7093;
    v_7103 = stack[0];
    {
        fn = elt(env, 3); // qqe_prepat
        return (*qfn1(fn))(fn, v_7103);
    }
v_7093:
    v_7103 = stack[0];
    {
        fn = elt(env, 4); // ofsf_prepat
        return (*qfn1(fn))(fn, v_7103);
    }
    v_7103 = nil;
    return onevalue(v_7103);
}



// Code for rl_susitf

static LispObject CC_rl_susitf(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7106, v_7107;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7106 = v_7089;
    v_7107 = v_7088;
// end of prologue
    goto v_7096;
v_7092:
    stack[0] = qvalue(elt(env, 1)); // rl_susitf!*
    goto v_7093;
v_7094:
    goto v_7103;
v_7099:
    goto v_7100;
v_7101:
    goto v_7102;
v_7103:
    goto v_7099;
v_7100:
    goto v_7101;
v_7102:
    v_7106 = list2(v_7107, v_7106);
    env = stack[-1];
    goto v_7095;
v_7096:
    goto v_7092;
v_7093:
    goto v_7094;
v_7095:
    {
        LispObject v_7109 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_7109, v_7106);
    }
}



// Code for ibalp_hassimple

static LispObject CC_ibalp_hassimple(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7129, v_7130;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7088);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_7129 = v_7088;
// end of prologue
    stack[-1] = nil;
    stack[0] = v_7129;
v_7097:
    v_7129 = stack[0];
    if (v_7129 == nil) goto v_7100;
    v_7129 = stack[-1];
    if (v_7129 == nil) goto v_7104;
    else goto v_7100;
v_7104:
    goto v_7101;
v_7100:
    goto v_7096;
v_7101:
    goto v_7116;
v_7112:
    v_7129 = stack[0];
    v_7129 = qcar(v_7129);
    v_7130 = qcar(v_7129);
    goto v_7113;
v_7114:
    v_7129 = stack[0];
    v_7129 = qcar(v_7129);
    v_7129 = qcdr(v_7129);
    v_7129 = qcar(v_7129);
    goto v_7115;
v_7116:
    goto v_7112;
v_7113:
    goto v_7114;
v_7115:
    fn = elt(env, 1); // ibalp_commonlenisone
    v_7129 = (*qfn2(fn))(fn, v_7130, v_7129);
    env = stack[-2];
    if (v_7129 == nil) goto v_7110;
    v_7129 = stack[0];
    v_7129 = qcar(v_7129);
    stack[-1] = v_7129;
    goto v_7108;
v_7110:
v_7108:
    v_7129 = stack[0];
    v_7129 = qcdr(v_7129);
    stack[0] = v_7129;
    goto v_7097;
v_7096:
    v_7129 = stack[-1];
    return onevalue(v_7129);
}



// Code for vevlcm

static LispObject CC_vevlcm(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7163, v_7164, v_7165;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7089;
    stack[-1] = v_7088;
// end of prologue
    v_7165 = nil;
v_7096:
    v_7163 = stack[-1];
    if (v_7163 == nil) goto v_7099;
    v_7163 = stack[0];
    if (v_7163 == nil) goto v_7099;
    goto v_7100;
v_7099:
    goto v_7095;
v_7100:
    goto v_7111;
v_7107:
    goto v_7120;
v_7116:
    v_7163 = stack[-1];
    v_7164 = qcar(v_7163);
    goto v_7117;
v_7118:
    v_7163 = stack[0];
    v_7163 = qcar(v_7163);
    goto v_7119;
v_7120:
    goto v_7116;
v_7117:
    goto v_7118;
v_7119:
    if (((intptr_t)(v_7164)) > ((intptr_t)(v_7163))) goto v_7114;
    else goto v_7115;
v_7114:
    v_7163 = stack[-1];
    v_7163 = qcar(v_7163);
    goto v_7113;
v_7115:
    v_7163 = stack[0];
    v_7163 = qcar(v_7163);
    goto v_7113;
    v_7163 = nil;
v_7113:
    goto v_7108;
v_7109:
    v_7164 = v_7165;
    goto v_7110;
v_7111:
    goto v_7107;
v_7108:
    goto v_7109;
v_7110:
    v_7163 = cons(v_7163, v_7164);
    env = stack[-2];
    v_7165 = v_7163;
    v_7163 = stack[-1];
    v_7163 = qcdr(v_7163);
    stack[-1] = v_7163;
    v_7163 = stack[0];
    v_7163 = qcdr(v_7163);
    stack[0] = v_7163;
    goto v_7096;
v_7095:
    v_7163 = v_7165;
    v_7163 = Lnreverse(nil, v_7163);
    env = stack[-2];
    v_7165 = v_7163;
    v_7163 = stack[-1];
    if (v_7163 == nil) goto v_7141;
    goto v_7148;
v_7144:
    v_7164 = v_7165;
    goto v_7145;
v_7146:
    v_7163 = stack[-1];
    goto v_7147;
v_7148:
    goto v_7144;
v_7145:
    goto v_7146;
v_7147:
    v_7163 = Lnconc(nil, v_7164, v_7163);
    v_7165 = v_7163;
    goto v_7139;
v_7141:
    v_7163 = stack[0];
    if (v_7163 == nil) goto v_7152;
    goto v_7159;
v_7155:
    v_7164 = v_7165;
    goto v_7156;
v_7157:
    v_7163 = stack[0];
    goto v_7158;
v_7159:
    goto v_7155;
v_7156:
    goto v_7157;
v_7158:
    v_7163 = Lnconc(nil, v_7164, v_7163);
    v_7165 = v_7163;
    goto v_7139;
v_7152:
v_7139:
    v_7163 = v_7165;
    return onevalue(v_7163);
}



// Code for listdiff

static LispObject CC_listdiff(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7117, v_7118;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_7089;
    v_7117 = v_7088;
// end of prologue
v_7093:
    v_7118 = stack[0];
    if (v_7118 == nil) goto v_7096;
    else goto v_7097;
v_7096:
    goto v_7092;
v_7097:
    v_7118 = v_7117;
    if (v_7118 == nil) goto v_7100;
    else goto v_7101;
v_7100:
    v_7117 = nil;
    goto v_7092;
v_7101:
    goto v_7111;
v_7107:
    v_7118 = stack[0];
    v_7118 = qcar(v_7118);
    goto v_7108;
v_7109:
    goto v_7110;
v_7111:
    goto v_7107;
v_7108:
    goto v_7109;
v_7110:
    v_7117 = Ldelete(nil, v_7118, v_7117);
    env = stack[-1];
    v_7118 = stack[0];
    v_7118 = qcdr(v_7118);
    stack[0] = v_7118;
    goto v_7093;
    v_7117 = nil;
v_7092:
    return onevalue(v_7117);
}



// Code for deletemult!*

static LispObject CC_deletemultH(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7142, v_7143, v_7144;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7088);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7088;
// end of prologue
    v_7142 = stack[0];
    if (v_7142 == nil) goto v_7095;
    else goto v_7096;
v_7095:
    v_7142 = stack[0];
    goto v_7092;
v_7096:
    v_7142 = stack[0];
    v_7142 = qcar(v_7142);
    v_7142 = ncons(v_7142);
    env = stack[-3];
    stack[-2] = v_7142;
    v_7142 = stack[0];
    v_7142 = qcdr(v_7142);
    stack[0] = v_7142;
    v_7142 = stack[0];
    stack[-1] = v_7142;
v_7107:
    v_7142 = stack[-1];
    if (v_7142 == nil) goto v_7111;
    else goto v_7112;
v_7111:
    goto v_7106;
v_7112:
    v_7142 = stack[-1];
    v_7142 = qcar(v_7142);
    v_7144 = v_7142;
    goto v_7126;
v_7122:
    v_7143 = v_7144;
    goto v_7123;
v_7124:
    v_7142 = stack[-2];
    goto v_7125;
v_7126:
    goto v_7122;
v_7123:
    goto v_7124;
v_7125:
    v_7142 = Lmember(nil, v_7143, v_7142);
    if (v_7142 == nil) goto v_7120;
    else goto v_7121;
v_7120:
    goto v_7135;
v_7131:
    stack[0] = stack[-2];
    goto v_7132;
v_7133:
    v_7142 = v_7144;
    v_7142 = ncons(v_7142);
    env = stack[-3];
    goto v_7134;
v_7135:
    goto v_7131;
v_7132:
    goto v_7133;
v_7134:
    v_7142 = Lnconc(nil, stack[0], v_7142);
    env = stack[-3];
    goto v_7119;
v_7121:
v_7119:
    v_7142 = stack[-1];
    v_7142 = qcdr(v_7142);
    stack[-1] = v_7142;
    goto v_7107;
v_7106:
    v_7142 = stack[-2];
v_7092:
    return onevalue(v_7142);
}



// Code for aminusp!:

static LispObject CC_aminuspT(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7148, v_7149;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7088);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_7088;
// end of prologue
    stack[-2] = nil;
    v_7148 = qvalue(elt(env, 1)); // !*modular
    if (v_7148 == nil) goto v_7097;
    goto v_7104;
v_7100:
    v_7149 = elt(env, 2); // modular
    goto v_7101;
v_7102:
    v_7148 = nil;
    goto v_7103;
v_7104:
    goto v_7100;
v_7101:
    goto v_7102;
v_7103:
    fn = elt(env, 5); // setdmode
    v_7148 = (*qfn2(fn))(fn, v_7149, v_7148);
    env = stack[-3];
    stack[-2] = v_7148;
    goto v_7095;
v_7097:
v_7095:
    goto v_7113;
v_7109:
    stack[0] = elt(env, 3); // aminusp!:1
    goto v_7110;
v_7111:
    v_7148 = stack[-1];
    v_7148 = Lmkquote(nil, v_7148);
    env = stack[-3];
    goto v_7112;
v_7113:
    goto v_7109;
v_7110:
    goto v_7111;
v_7112:
    v_7148 = list2(stack[0], v_7148);
    env = stack[-3];
    fn = elt(env, 6); // errorset2
    v_7148 = (*qfn1(fn))(fn, v_7148);
    env = stack[-3];
    stack[0] = v_7148;
    v_7148 = stack[-2];
    if (v_7148 == nil) goto v_7120;
    goto v_7127;
v_7123:
    v_7149 = elt(env, 2); // modular
    goto v_7124;
v_7125:
    v_7148 = lisp_true;
    goto v_7126;
v_7127:
    goto v_7123;
v_7124:
    goto v_7125;
v_7126:
    fn = elt(env, 5); // setdmode
    v_7148 = (*qfn2(fn))(fn, v_7149, v_7148);
    env = stack[-3];
    goto v_7118;
v_7120:
v_7118:
    v_7148 = stack[0];
    fn = elt(env, 7); // errorp
    v_7148 = (*qfn1(fn))(fn, v_7148);
    env = stack[-3];
    if (v_7148 == nil) goto v_7133;
    goto v_7141;
v_7137:
    v_7149 = stack[-1];
    goto v_7138;
v_7139:
    v_7148 = elt(env, 4); // "arithmetic expression"
    goto v_7140;
v_7141:
    goto v_7137;
v_7138:
    goto v_7139;
v_7140:
    fn = elt(env, 8); // typerr
    v_7148 = (*qfn2(fn))(fn, v_7149, v_7148);
    goto v_7131;
v_7133:
    v_7148 = stack[0];
    v_7148 = qcar(v_7148);
    goto v_7093;
v_7131:
    v_7148 = nil;
v_7093:
    return onevalue(v_7148);
}



// Code for pv_times3

static LispObject CC_pv_times3(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7117, v_7118;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7089;
    stack[-1] = v_7088;
// end of prologue
    goto v_7096;
v_7092:
    goto v_7102;
v_7098:
    v_7117 = stack[-1];
    v_7118 = qcar(v_7117);
    goto v_7099;
v_7100:
    v_7117 = stack[0];
    v_7117 = qcar(v_7117);
    goto v_7101;
v_7102:
    goto v_7098;
v_7099:
    goto v_7100;
v_7101:
    stack[-2] = times2(v_7118, v_7117);
    env = stack[-3];
    goto v_7093;
v_7094:
    goto v_7112;
v_7108:
    v_7117 = stack[-1];
    v_7118 = qcdr(v_7117);
    goto v_7109;
v_7110:
    v_7117 = stack[0];
    v_7117 = qcdr(v_7117);
    goto v_7111;
v_7112:
    goto v_7108;
v_7109:
    goto v_7110;
v_7111:
    fn = elt(env, 1); // pappend
    v_7117 = (*qfn2(fn))(fn, v_7118, v_7117);
    goto v_7095;
v_7096:
    goto v_7092;
v_7093:
    goto v_7094;
v_7095:
    {
        LispObject v_7122 = stack[-2];
        return cons(v_7122, v_7117);
    }
}



// Code for b!:ordexn

static LispObject CC_bTordexn(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7186, v_7187;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_7089;
    stack[-2] = v_7088;
// end of prologue
    stack[0] = nil;
    stack[-3] = nil;
v_7097:
    v_7186 = stack[-1];
    if (v_7186 == nil) goto v_7100;
    goto v_7110;
v_7106:
    v_7187 = stack[-2];
    goto v_7107;
v_7108:
    v_7186 = stack[-1];
    v_7186 = qcar(v_7186);
    goto v_7109;
v_7110:
    goto v_7106;
v_7107:
    goto v_7108;
v_7109:
    v_7186 = (LispObject)lessp2(v_7187, v_7186);
    v_7186 = v_7186 ? lisp_true : nil;
    env = stack[-4];
    if (v_7186 == nil) goto v_7100;
    goto v_7101;
v_7100:
    goto v_7096;
v_7101:
    goto v_7120;
v_7116:
    v_7186 = stack[-1];
    v_7187 = qcar(v_7186);
    goto v_7117;
v_7118:
    v_7186 = stack[-3];
    goto v_7119;
v_7120:
    goto v_7116;
v_7117:
    goto v_7118;
v_7119:
    v_7186 = cons(v_7187, v_7186);
    env = stack[-4];
    stack[-3] = v_7186;
    v_7186 = stack[-1];
    v_7186 = qcdr(v_7186);
    stack[-1] = v_7186;
    v_7186 = stack[0];
    v_7186 = (v_7186 == nil ? lisp_true : nil);
    stack[0] = v_7186;
    goto v_7097;
v_7096:
    v_7186 = stack[-1];
    if (v_7186 == nil) goto v_7130;
    else goto v_7131;
v_7130:
    goto v_7138;
v_7134:
    goto v_7135;
v_7136:
    goto v_7146;
v_7142:
    v_7187 = stack[-2];
    goto v_7143;
v_7144:
    v_7186 = stack[-3];
    goto v_7145;
v_7146:
    goto v_7142;
v_7143:
    goto v_7144;
v_7145:
    v_7186 = cons(v_7187, v_7186);
    env = stack[-4];
    v_7186 = Lnreverse(nil, v_7186);
    goto v_7137;
v_7138:
    goto v_7134;
v_7135:
    goto v_7136;
v_7137:
    {
        LispObject v_7192 = stack[0];
        return cons(v_7192, v_7186);
    }
v_7131:
    goto v_7158;
v_7154:
    v_7187 = stack[-2];
    goto v_7155;
v_7156:
    v_7186 = stack[-1];
    v_7186 = qcar(v_7186);
    goto v_7157;
v_7158:
    goto v_7154;
v_7155:
    goto v_7156;
v_7157:
    v_7186 = Leqn(nil, v_7187, v_7186);
    env = stack[-4];
    if (v_7186 == nil) goto v_7152;
    v_7186 = nil;
    goto v_7094;
v_7152:
    goto v_7168;
v_7164:
    goto v_7165;
v_7166:
    goto v_7175;
v_7171:
    goto v_7182;
v_7178:
    v_7187 = stack[-2];
    goto v_7179;
v_7180:
    v_7186 = stack[-3];
    goto v_7181;
v_7182:
    goto v_7178;
v_7179:
    goto v_7180;
v_7181:
    v_7186 = cons(v_7187, v_7186);
    env = stack[-4];
    v_7187 = Lnreverse(nil, v_7186);
    env = stack[-4];
    goto v_7172;
v_7173:
    v_7186 = stack[-1];
    goto v_7174;
v_7175:
    goto v_7171;
v_7172:
    goto v_7173;
v_7174:
    v_7186 = Lnconc(nil, v_7187, v_7186);
    goto v_7167;
v_7168:
    goto v_7164;
v_7165:
    goto v_7166;
v_7167:
    {
        LispObject v_7193 = stack[0];
        return cons(v_7193, v_7186);
    }
v_7094:
    return onevalue(v_7186);
}



// Code for cde_lassoc2

static LispObject CC_cde_lassoc2(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7123, v_7124, v_7125, v_7126;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7125 = v_7089;
    v_7126 = v_7088;
// end of prologue
v_7093:
    v_7123 = v_7125;
    if (v_7123 == nil) goto v_7096;
    else goto v_7097;
v_7096:
    v_7123 = nil;
    goto v_7092;
v_7097:
    v_7123 = v_7125;
    v_7123 = qcar(v_7123);
    if (!consp(v_7123)) goto v_7100;
    else goto v_7101;
v_7100:
    v_7123 = elt(env, 1); // "Error: bad alist"
    {
        fn = elt(env, 2); // rederr
        return (*qfn1(fn))(fn, v_7123);
    }
v_7101:
    goto v_7112;
v_7108:
    v_7124 = v_7126;
    goto v_7109;
v_7110:
    v_7123 = v_7125;
    v_7123 = qcar(v_7123);
    v_7123 = qcdr(v_7123);
    goto v_7111;
v_7112:
    goto v_7108;
v_7109:
    goto v_7110;
v_7111:
    if (equal(v_7124, v_7123)) goto v_7106;
    else goto v_7107;
v_7106:
    v_7123 = v_7125;
    v_7123 = qcar(v_7123);
    goto v_7092;
v_7107:
    v_7123 = v_7125;
    v_7123 = qcdr(v_7123);
    v_7125 = v_7123;
    goto v_7093;
    v_7123 = nil;
v_7092:
    return onevalue(v_7123);
}



// Code for p_princ

static LispObject CC_p_princ(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7190, v_7191;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7089;
    stack[-1] = v_7088;
// end of prologue
    v_7190 = stack[-1];
    v_7190 = Lexplodec(nil, v_7190);
    env = stack[-3];
    stack[-2] = v_7190;
    v_7190 = qvalue(elt(env, 1)); // bldmsg_chars!*
    if (v_7190 == nil) goto v_7099;
    v_7190 = stack[0];
    if (v_7190 == nil) goto v_7104;
    goto v_7111;
v_7107:
    v_7191 = elt(env, 2); // ! 
    goto v_7108;
v_7109:
    v_7190 = qvalue(elt(env, 1)); // bldmsg_chars!*
    goto v_7110;
v_7111:
    goto v_7107;
v_7108:
    goto v_7109;
v_7110:
    v_7190 = cons(v_7191, v_7190);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_7190; // bldmsg_chars!*
    goto v_7102;
v_7104:
v_7102:
    v_7190 = stack[-2];
    stack[0] = v_7190;
v_7117:
    v_7190 = stack[0];
    if (v_7190 == nil) goto v_7121;
    else goto v_7122;
v_7121:
    goto v_7116;
v_7122:
    v_7190 = stack[0];
    v_7190 = qcar(v_7190);
    goto v_7133;
v_7129:
    v_7191 = v_7190;
    goto v_7130;
v_7131:
    v_7190 = qvalue(elt(env, 1)); // bldmsg_chars!*
    goto v_7132;
v_7133:
    goto v_7129;
v_7130:
    goto v_7131;
v_7132:
    v_7190 = cons(v_7191, v_7190);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_7190; // bldmsg_chars!*
    v_7190 = stack[0];
    v_7190 = qcdr(v_7190);
    stack[0] = v_7190;
    goto v_7117;
v_7116:
    goto v_7097;
v_7099:
    v_7190 = stack[0];
    if (v_7190 == nil) goto v_7143;
    goto v_7154;
v_7150:
    goto v_7160;
v_7156:
    stack[0] = Lposn(nil, 0);
    env = stack[-3];
    goto v_7157;
v_7158:
    v_7190 = stack[-2];
    v_7190 = Llength(nil, v_7190);
    env = stack[-3];
    v_7190 = add1(v_7190);
    env = stack[-3];
    goto v_7159;
v_7160:
    goto v_7156;
v_7157:
    goto v_7158;
v_7159:
    v_7191 = plus2(stack[0], v_7190);
    env = stack[-3];
    goto v_7151;
v_7152:
    v_7190 = qvalue(elt(env, 3)); // !*ll!*
    goto v_7153;
v_7154:
    goto v_7150;
v_7151:
    goto v_7152;
v_7153:
    v_7190 = (LispObject)greaterp2(v_7191, v_7190);
    v_7190 = v_7190 ? lisp_true : nil;
    env = stack[-3];
    if (v_7190 == nil) goto v_7148;
    v_7190 = Lterpri(nil, 0);
    env = stack[-3];
    goto v_7146;
v_7148:
v_7146:
    v_7190 = elt(env, 4); // " "
    v_7190 = Lprinc(nil, v_7190);
    env = stack[-3];
    goto v_7141;
v_7143:
    goto v_7176;
v_7172:
    goto v_7182;
v_7178:
    stack[0] = Lposn(nil, 0);
    env = stack[-3];
    goto v_7179;
v_7180:
    v_7190 = stack[-2];
    v_7190 = Llength(nil, v_7190);
    env = stack[-3];
    goto v_7181;
v_7182:
    goto v_7178;
v_7179:
    goto v_7180;
v_7181:
    v_7191 = plus2(stack[0], v_7190);
    env = stack[-3];
    goto v_7173;
v_7174:
    v_7190 = qvalue(elt(env, 3)); // !*ll!*
    goto v_7175;
v_7176:
    goto v_7172;
v_7173:
    goto v_7174;
v_7175:
    v_7190 = (LispObject)greaterp2(v_7191, v_7190);
    v_7190 = v_7190 ? lisp_true : nil;
    env = stack[-3];
    if (v_7190 == nil) goto v_7170;
    v_7190 = Lterpri(nil, 0);
    env = stack[-3];
    goto v_7141;
v_7170:
v_7141:
    v_7190 = stack[-1];
    v_7190 = Lprinc(nil, v_7190);
    goto v_7097;
v_7097:
    v_7190 = nil;
    return onevalue(v_7190);
}



// Code for removeg1

static LispObject CC_removeg1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7506, v_7507, v_7508, v_7509;
    LispObject fn;
    LispObject v_7090, v_7089, v_7088;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "removeg1");
    va_start(aa, nargs);
    v_7088 = va_arg(aa, LispObject);
    v_7089 = va_arg(aa, LispObject);
    v_7090 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7090,v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7088,v_7089,v_7090);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_7090;
    stack[-4] = v_7089;
    stack[-5] = v_7088;
// end of prologue
    goto v_7103;
v_7099:
    v_7507 = stack[-5];
    goto v_7100;
v_7101:
    v_7506 = stack[-4];
    goto v_7102;
v_7103:
    goto v_7099;
v_7100:
    goto v_7101;
v_7102:
    fn = elt(env, 7); // removev
    v_7506 = (*qfn2(fn))(fn, v_7507, v_7506);
    env = stack[-7];
    goto v_7111;
v_7107:
    v_7507 = stack[-5];
    goto v_7108;
v_7109:
    v_7506 = stack[-3];
    goto v_7110;
v_7111:
    goto v_7107;
v_7108:
    goto v_7109;
v_7110:
    fn = elt(env, 7); // removev
    v_7506 = (*qfn2(fn))(fn, v_7507, v_7506);
    env = stack[-7];
    goto v_7126;
v_7122:
    v_7506 = stack[-4];
    v_7506 = qcdr(v_7506);
    v_7507 = qcar(v_7506);
    goto v_7123;
v_7124:
    v_7506 = stack[-3];
    v_7506 = qcdr(v_7506);
    v_7506 = qcdr(v_7506);
    v_7506 = qcar(v_7506);
    goto v_7125;
v_7126:
    goto v_7122;
v_7123:
    goto v_7124;
v_7125:
    if (v_7507 == v_7506) goto v_7120;
    else goto v_7121;
v_7120:
    goto v_7138;
v_7134:
    v_7506 = stack[-4];
    v_7506 = qcdr(v_7506);
    v_7506 = qcdr(v_7506);
    v_7507 = qcar(v_7506);
    goto v_7135;
v_7136:
    v_7506 = stack[-3];
    v_7506 = qcdr(v_7506);
    v_7506 = qcar(v_7506);
    goto v_7137;
v_7138:
    goto v_7134;
v_7135:
    goto v_7136;
v_7137:
    v_7506 = (v_7507 == v_7506 ? lisp_true : nil);
    goto v_7119;
v_7121:
    v_7506 = nil;
    goto v_7119;
    v_7506 = nil;
v_7119:
    if (v_7506 == nil) goto v_7117;
    goto v_7156;
v_7152:
    goto v_7162;
v_7158:
    v_7507 = qvalue(elt(env, 1)); // n!*!*2!-1
    goto v_7159;
v_7160:
    v_7506 = stack[-5];
    v_7506 = qcar(v_7506);
    goto v_7161;
v_7162:
    goto v_7158;
v_7159:
    goto v_7160;
v_7161:
    fn = elt(env, 8); // multsq
    v_7507 = (*qfn2(fn))(fn, v_7507, v_7506);
    env = stack[-7];
    goto v_7153;
v_7154:
    v_7506 = stack[-5];
    v_7506 = qcdr(v_7506);
    goto v_7155;
v_7156:
    goto v_7152;
v_7153:
    goto v_7154;
v_7155:
    v_7506 = cons(v_7507, v_7506);
    return ncons(v_7506);
v_7117:
    goto v_7173;
v_7169:
    v_7506 = stack[-5];
    v_7507 = qcdr(v_7506);
    goto v_7170;
v_7171:
    v_7506 = stack[-4];
    v_7506 = qcdr(v_7506);
    v_7506 = qcdr(v_7506);
    v_7506 = qcar(v_7506);
    goto v_7172;
v_7173:
    goto v_7169;
v_7170:
    goto v_7171;
v_7172:
    fn = elt(env, 9); // finde
    v_7506 = (*qfn2(fn))(fn, v_7507, v_7506);
    env = stack[-7];
    stack[-6] = v_7506;
    goto v_7188;
v_7184:
    v_7506 = stack[-4];
    v_7506 = qcdr(v_7506);
    v_7507 = qcar(v_7506);
    goto v_7185;
v_7186:
    v_7506 = stack[-3];
    v_7506 = qcdr(v_7506);
    v_7506 = qcdr(v_7506);
    v_7506 = qcar(v_7506);
    goto v_7187;
v_7188:
    goto v_7184;
v_7185:
    goto v_7186;
v_7187:
    if (v_7507 == v_7506) goto v_7182;
    else goto v_7183;
v_7182:
    v_7506 = stack[-6];
    if (v_7506 == nil) goto v_7199;
    goto v_7206;
v_7202:
    v_7506 = stack[-6];
    v_7506 = qcar(v_7506);
    v_7507 = qcdr(v_7506);
    goto v_7203;
v_7204:
    v_7506 = stack[-3];
    v_7506 = qcdr(v_7506);
    v_7506 = qcar(v_7506);
    goto v_7205;
v_7206:
    goto v_7202;
v_7203:
    goto v_7204;
v_7205:
    v_7506 = Lrplaca(nil, v_7507, v_7506);
    env = stack[-7];
    goto v_7197;
v_7199:
    goto v_7225;
v_7217:
    v_7509 = elt(env, 2); // "Free edge"
    goto v_7218;
v_7219:
    v_7506 = stack[-4];
    v_7506 = qcdr(v_7506);
    v_7506 = qcdr(v_7506);
    v_7508 = qcar(v_7506);
    goto v_7220;
v_7221:
    v_7507 = elt(env, 3); // "in vertex"
    goto v_7222;
v_7223:
    v_7506 = stack[-4];
    goto v_7224;
v_7225:
    goto v_7217;
v_7218:
    goto v_7219;
v_7220:
    goto v_7221;
v_7222:
    goto v_7223;
v_7224:
    v_7506 = list4(v_7509, v_7508, v_7507, v_7506);
    env = stack[-7];
    fn = elt(env, 10); // cerror
    v_7506 = (*qfn1(fn))(fn, v_7506);
    env = stack[-7];
    goto v_7197;
v_7197:
    goto v_7239;
v_7235:
    goto v_7245;
v_7241:
    goto v_7251;
v_7247:
    v_7507 = qvalue(elt(env, 1)); // n!*!*2!-1
    goto v_7248;
v_7249:
    v_7506 = qvalue(elt(env, 4)); // su_order
    goto v_7250;
v_7251:
    goto v_7247;
v_7248:
    goto v_7249;
v_7250:
    fn = elt(env, 11); // quotsq
    v_7507 = (*qfn2(fn))(fn, v_7507, v_7506);
    env = stack[-7];
    goto v_7242;
v_7243:
    v_7506 = stack[-5];
    v_7506 = qcar(v_7506);
    goto v_7244;
v_7245:
    goto v_7241;
v_7242:
    goto v_7243;
v_7244:
    fn = elt(env, 8); // multsq
    v_7507 = (*qfn2(fn))(fn, v_7507, v_7506);
    env = stack[-7];
    goto v_7236;
v_7237:
    v_7506 = stack[-5];
    v_7506 = qcdr(v_7506);
    goto v_7238;
v_7239:
    goto v_7235;
v_7236:
    goto v_7237;
v_7238:
    v_7506 = cons(v_7507, v_7506);
    return ncons(v_7506);
v_7183:
    goto v_7264;
v_7260:
    v_7506 = stack[-5];
    v_7507 = qcdr(v_7506);
    goto v_7261;
v_7262:
    v_7506 = stack[-3];
    v_7506 = qcdr(v_7506);
    v_7506 = qcdr(v_7506);
    v_7506 = qcar(v_7506);
    goto v_7263;
v_7264:
    goto v_7260;
v_7261:
    goto v_7262;
v_7263:
    fn = elt(env, 9); // finde
    v_7506 = (*qfn2(fn))(fn, v_7507, v_7506);
    env = stack[-7];
    stack[-2] = v_7506;
    goto v_7279;
v_7275:
    v_7506 = stack[-4];
    v_7506 = qcdr(v_7506);
    v_7506 = qcdr(v_7506);
    v_7507 = qcar(v_7506);
    goto v_7276;
v_7277:
    v_7506 = stack[-3];
    v_7506 = qcdr(v_7506);
    v_7506 = qcar(v_7506);
    goto v_7278;
v_7279:
    goto v_7275;
v_7276:
    goto v_7277;
v_7278:
    if (v_7507 == v_7506) goto v_7273;
    else goto v_7274;
v_7273:
    v_7506 = stack[-2];
    if (v_7506 == nil) goto v_7290;
    goto v_7297;
v_7293:
    v_7506 = stack[-2];
    v_7506 = qcar(v_7506);
    v_7507 = qcdr(v_7506);
    goto v_7294;
v_7295:
    v_7506 = stack[-4];
    v_7506 = qcdr(v_7506);
    v_7506 = qcar(v_7506);
    goto v_7296;
v_7297:
    goto v_7293;
v_7294:
    goto v_7295;
v_7296:
    v_7506 = Lrplaca(nil, v_7507, v_7506);
    env = stack[-7];
    goto v_7288;
v_7290:
    goto v_7316;
v_7308:
    v_7509 = elt(env, 2); // "Free edge"
    goto v_7309;
v_7310:
    v_7506 = stack[-3];
    v_7506 = qcdr(v_7506);
    v_7506 = qcdr(v_7506);
    v_7508 = qcar(v_7506);
    goto v_7311;
v_7312:
    v_7507 = elt(env, 3); // "in vertex"
    goto v_7313;
v_7314:
    v_7506 = stack[-3];
    goto v_7315;
v_7316:
    goto v_7308;
v_7309:
    goto v_7310;
v_7311:
    goto v_7312;
v_7313:
    goto v_7314;
v_7315:
    v_7506 = list4(v_7509, v_7508, v_7507, v_7506);
    env = stack[-7];
    fn = elt(env, 10); // cerror
    v_7506 = (*qfn1(fn))(fn, v_7506);
    env = stack[-7];
    goto v_7288;
v_7288:
    goto v_7330;
v_7326:
    goto v_7336;
v_7332:
    goto v_7342;
v_7338:
    v_7507 = qvalue(elt(env, 1)); // n!*!*2!-1
    goto v_7339;
v_7340:
    v_7506 = qvalue(elt(env, 4)); // su_order
    goto v_7341;
v_7342:
    goto v_7338;
v_7339:
    goto v_7340;
v_7341:
    fn = elt(env, 11); // quotsq
    v_7507 = (*qfn2(fn))(fn, v_7507, v_7506);
    env = stack[-7];
    goto v_7333;
v_7334:
    v_7506 = stack[-5];
    v_7506 = qcar(v_7506);
    goto v_7335;
v_7336:
    goto v_7332;
v_7333:
    goto v_7334;
v_7335:
    fn = elt(env, 8); // multsq
    v_7507 = (*qfn2(fn))(fn, v_7507, v_7506);
    env = stack[-7];
    goto v_7327;
v_7328:
    v_7506 = stack[-5];
    v_7506 = qcdr(v_7506);
    goto v_7329;
v_7330:
    goto v_7326;
v_7327:
    goto v_7328;
v_7329:
    v_7506 = cons(v_7507, v_7506);
    return ncons(v_7506);
v_7274:
    v_7506 = stack[-6];
    if (v_7506 == nil) goto v_7356;
    else goto v_7357;
v_7356:
    v_7506 = lisp_true;
    goto v_7355;
v_7357:
    v_7506 = stack[-2];
    v_7506 = (v_7506 == nil ? lisp_true : nil);
    goto v_7355;
    v_7506 = nil;
v_7355:
    if (v_7506 == nil) goto v_7353;
    goto v_7370;
v_7366:
    stack[0] = elt(env, 5); // "Invalid structure of c-graph"
    goto v_7367;
v_7368:
    v_7506 = stack[-5];
    if (v_7506 == nil) goto v_7374;
    else goto v_7375;
v_7374:
    v_7506 = nil;
    goto v_7373;
v_7375:
    v_7506 = stack[-5];
    v_7506 = qcdr(v_7506);
    if (v_7506 == nil) goto v_7378;
    else goto v_7379;
v_7378:
    v_7506 = stack[-5];
    v_7506 = qcar(v_7506);
    goto v_7373;
v_7379:
    goto v_7391;
v_7387:
    v_7507 = elt(env, 6); // times
    goto v_7388;
v_7389:
    v_7506 = stack[-5];
    goto v_7390;
v_7391:
    goto v_7387;
v_7388:
    goto v_7389;
v_7390:
    v_7506 = cons(v_7507, v_7506);
    env = stack[-7];
    goto v_7373;
    v_7506 = nil;
v_7373:
    goto v_7369;
v_7370:
    goto v_7366;
v_7367:
    goto v_7368;
v_7369:
    v_7506 = list2(stack[0], v_7506);
    env = stack[-7];
    fn = elt(env, 10); // cerror
    v_7506 = (*qfn1(fn))(fn, v_7506);
    env = stack[-7];
    goto v_7351;
v_7353:
v_7351:
    v_7506 = stack[-6];
    v_7506 = qcar(v_7506);
    stack[-6] = v_7506;
    v_7506 = stack[-2];
    v_7506 = qcar(v_7506);
    stack[-2] = v_7506;
    goto v_7403;
v_7399:
    v_7506 = stack[-6];
    v_7507 = qcdr(v_7506);
    goto v_7400;
v_7401:
    v_7506 = stack[-3];
    v_7506 = qcdr(v_7506);
    v_7506 = qcar(v_7506);
    goto v_7402;
v_7403:
    goto v_7399;
v_7400:
    goto v_7401;
v_7402:
    v_7506 = Lrplaca(nil, v_7507, v_7506);
    env = stack[-7];
    goto v_7414;
v_7410:
    v_7506 = stack[-2];
    v_7507 = qcdr(v_7506);
    goto v_7411;
v_7412:
    v_7506 = stack[-4];
    v_7506 = qcdr(v_7506);
    v_7506 = qcar(v_7506);
    goto v_7413;
v_7414:
    goto v_7410;
v_7411:
    goto v_7412;
v_7413:
    v_7506 = Lrplaca(nil, v_7507, v_7506);
    env = stack[-7];
    goto v_7425;
v_7421:
    v_7506 = stack[-5];
    stack[0] = qcar(v_7506);
    goto v_7422;
v_7423:
    v_7506 = stack[-5];
    v_7506 = qcdr(v_7506);
    fn = elt(env, 12); // mkcopy
    v_7506 = (*qfn1(fn))(fn, v_7506);
    env = stack[-7];
    goto v_7424;
v_7425:
    goto v_7421;
v_7422:
    goto v_7423;
v_7424:
    v_7506 = cons(stack[0], v_7506);
    env = stack[-7];
    stack[-1] = v_7506;
    v_7506 = stack[-1];
    v_7506 = qcdr(v_7506);
    stack[0] = v_7506;
    goto v_7437;
v_7433:
    v_7507 = stack[-6];
    goto v_7434;
v_7435:
    v_7506 = stack[0];
    goto v_7436;
v_7437:
    goto v_7433;
v_7434:
    goto v_7435;
v_7436:
    v_7506 = Lmember(nil, v_7507, v_7506);
    v_7506 = qcar(v_7506);
    stack[-6] = v_7506;
    goto v_7446;
v_7442:
    v_7507 = stack[-2];
    goto v_7443;
v_7444:
    v_7506 = stack[0];
    goto v_7445;
v_7446:
    goto v_7442;
v_7443:
    goto v_7444;
v_7445:
    v_7506 = Lmember(nil, v_7507, v_7506);
    v_7506 = qcar(v_7506);
    stack[-2] = v_7506;
    goto v_7456;
v_7452:
    v_7506 = stack[-6];
    v_7507 = qcdr(v_7506);
    goto v_7453;
v_7454:
    v_7506 = stack[-4];
    v_7506 = qcdr(v_7506);
    v_7506 = qcar(v_7506);
    goto v_7455;
v_7456:
    goto v_7452;
v_7453:
    goto v_7454;
v_7455:
    v_7506 = Lrplaca(nil, v_7507, v_7506);
    env = stack[-7];
    goto v_7467;
v_7463:
    v_7506 = stack[-2];
    v_7507 = qcdr(v_7506);
    goto v_7464;
v_7465:
    v_7506 = stack[-3];
    v_7506 = qcdr(v_7506);
    v_7506 = qcar(v_7506);
    goto v_7466;
v_7467:
    goto v_7463;
v_7464:
    goto v_7465;
v_7466:
    v_7506 = Lrplaca(nil, v_7507, v_7506);
    env = stack[-7];
    goto v_7480;
v_7474:
    stack[-2] = stack[-5];
    goto v_7475;
v_7476:
    goto v_7487;
v_7483:
    goto v_7493;
v_7489:
    goto v_7499;
v_7495:
    v_7507 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_7496;
v_7497:
    v_7506 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7498;
v_7499:
    goto v_7495;
v_7496:
    goto v_7497;
v_7498:
    v_7507 = cons(v_7507, v_7506);
    env = stack[-7];
    goto v_7490;
v_7491:
    v_7506 = qvalue(elt(env, 4)); // su_order
    goto v_7492;
v_7493:
    goto v_7489;
v_7490:
    goto v_7491;
v_7492:
    fn = elt(env, 11); // quotsq
    v_7507 = (*qfn2(fn))(fn, v_7507, v_7506);
    env = stack[-7];
    goto v_7484;
v_7485:
    v_7506 = stack[-1];
    v_7506 = qcar(v_7506);
    goto v_7486;
v_7487:
    goto v_7483;
v_7484:
    goto v_7485;
v_7486:
    fn = elt(env, 8); // multsq
    v_7507 = (*qfn2(fn))(fn, v_7507, v_7506);
    goto v_7477;
v_7478:
    v_7506 = stack[0];
    goto v_7479;
v_7480:
    goto v_7474;
v_7475:
    goto v_7476;
v_7477:
    goto v_7478;
v_7479:
    {
        LispObject v_7517 = stack[-2];
        return list2star(v_7517, v_7507, v_7506);
    }
    return onevalue(v_7506);
}



// Code for talp_simplatrinv

static LispObject CC_talp_simplatrinv(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7194, v_7195, v_7196;
    LispObject fn;
    LispObject v_7090, v_7089, v_7088;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_simplatrinv");
    va_start(aa, nargs);
    v_7088 = va_arg(aa, LispObject);
    v_7089 = va_arg(aa, LispObject);
    v_7090 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7090,v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7088,v_7089,v_7090);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7090;
    stack[-1] = v_7089;
    stack[-2] = v_7088;
// end of prologue
    v_7194 = stack[0];
    fn = elt(env, 2); // talp_simplt
    v_7194 = (*qfn1(fn))(fn, v_7194);
    env = stack[-3];
    stack[0] = v_7194;
    v_7194 = stack[0];
    fn = elt(env, 3); // talp_invp
    v_7194 = (*qfn1(fn))(fn, v_7194);
    env = stack[-3];
    if (v_7194 == nil) goto v_7097;
    v_7194 = stack[-1];
    fn = elt(env, 3); // talp_invp
    v_7194 = (*qfn1(fn))(fn, v_7194);
    env = stack[-3];
    if (v_7194 == nil) goto v_7103;
    v_7194 = stack[-1];
    fn = elt(env, 2); // talp_simplt
    v_7194 = (*qfn1(fn))(fn, v_7194);
    env = stack[-3];
    stack[-1] = v_7194;
    v_7194 = stack[-1];
    fn = elt(env, 3); // talp_invp
    v_7194 = (*qfn1(fn))(fn, v_7194);
    env = stack[-3];
    if (v_7194 == nil) goto v_7111;
    goto v_7123;
v_7119:
    v_7195 = stack[-1];
    goto v_7120;
v_7121:
    v_7194 = stack[0];
    goto v_7122;
v_7123:
    goto v_7119;
v_7120:
    goto v_7121;
v_7122:
    fn = elt(env, 4); // talp_eqtp
    v_7194 = (*qfn2(fn))(fn, v_7195, v_7194);
    env = stack[-3];
    if (v_7194 == nil) goto v_7117;
    goto v_7134;
v_7130:
    v_7194 = stack[-2];
    goto v_7131;
v_7132:
    v_7195 = elt(env, 1); // equal
    goto v_7133;
v_7134:
    goto v_7130;
v_7131:
    goto v_7132;
v_7133:
    if (v_7194 == v_7195) goto v_7128;
    else goto v_7129;
v_7128:
    v_7194 = lisp_true;
    goto v_7127;
v_7129:
    v_7194 = nil;
    goto v_7127;
    v_7194 = nil;
v_7127:
    goto v_7115;
v_7117:
    goto v_7150;
v_7144:
    v_7196 = stack[-2];
    goto v_7145;
v_7146:
    v_7195 = stack[-1];
    goto v_7147;
v_7148:
    v_7194 = stack[0];
    goto v_7149;
v_7150:
    goto v_7144;
v_7145:
    goto v_7146;
v_7147:
    goto v_7148;
v_7149:
    {
        fn = elt(env, 5); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_7196, v_7195, v_7194);
    }
    v_7194 = nil;
v_7115:
    goto v_7109;
v_7111:
    goto v_7163;
v_7157:
    v_7196 = stack[-2];
    goto v_7158;
v_7159:
    v_7195 = stack[-1];
    goto v_7160;
v_7161:
    v_7194 = stack[0];
    goto v_7162;
v_7163:
    goto v_7157;
v_7158:
    goto v_7159;
v_7160:
    goto v_7161;
v_7162:
    {
        fn = elt(env, 6); // talp_simplat2
        return (*qfnn(fn))(fn, 3, v_7196, v_7195, v_7194);
    }
    v_7194 = nil;
v_7109:
    goto v_7101;
v_7103:
    goto v_7176;
v_7170:
    goto v_7171;
v_7172:
    v_7194 = stack[-1];
    fn = elt(env, 2); // talp_simplt
    v_7195 = (*qfn1(fn))(fn, v_7194);
    env = stack[-3];
    goto v_7173;
v_7174:
    v_7194 = stack[0];
    goto v_7175;
v_7176:
    goto v_7170;
v_7171:
    goto v_7172;
v_7173:
    goto v_7174;
v_7175:
    {
        LispObject v_7200 = stack[-2];
        fn = elt(env, 5); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_7200, v_7195, v_7194);
    }
    v_7194 = nil;
v_7101:
    goto v_7095;
v_7097:
    goto v_7190;
v_7184:
    v_7196 = stack[-2];
    goto v_7185;
v_7186:
    v_7195 = stack[-1];
    goto v_7187;
v_7188:
    v_7194 = stack[0];
    goto v_7189;
v_7190:
    goto v_7184;
v_7185:
    goto v_7186;
v_7187:
    goto v_7188;
v_7189:
    {
        fn = elt(env, 6); // talp_simplat2
        return (*qfnn(fn))(fn, 3, v_7196, v_7195, v_7194);
    }
    v_7194 = nil;
v_7095:
    return onevalue(v_7194);
}



// Code for qqe_qprefix!-var

static LispObject CC_qqe_qprefixKvar(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7125, v_7126;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7088);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_7088;
// end of prologue
v_7094:
    v_7125 = stack[0];
    if (v_7125 == nil) goto v_7097;
    v_7125 = stack[0];
    if (!consp(v_7125)) goto v_7097;
    goto v_7098;
v_7097:
    goto v_7093;
v_7098:
    goto v_7112;
v_7108:
    v_7125 = stack[0];
    fn = elt(env, 2); // qqe_op
    v_7126 = (*qfn1(fn))(fn, v_7125);
    env = stack[-1];
    goto v_7109;
v_7110:
    v_7125 = elt(env, 1); // (ltail rtail lhead rhead)
    goto v_7111;
v_7112:
    goto v_7108;
v_7109:
    goto v_7110;
v_7111:
    v_7125 = Lmemq(nil, v_7126, v_7125);
    if (v_7125 == nil) goto v_7107;
    v_7125 = stack[0];
    fn = elt(env, 3); // qqe_arg2l
    v_7125 = (*qfn1(fn))(fn, v_7125);
    env = stack[-1];
    stack[0] = v_7125;
    goto v_7105;
v_7107:
    v_7125 = stack[0];
    fn = elt(env, 4); // qqe_arg2r
    v_7125 = (*qfn1(fn))(fn, v_7125);
    env = stack[-1];
    stack[0] = v_7125;
    goto v_7105;
v_7105:
    goto v_7094;
v_7093:
    v_7125 = stack[0];
    return onevalue(v_7125);
}



// Code for terpri!*

static LispObject CC_terpriH(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7166, v_7167, v_7168;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7088);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7088;
// end of prologue
    v_7166 = qvalue(elt(env, 1)); // outputhandler!*
    if (v_7166 == nil) goto v_7097;
    goto v_7106;
v_7100:
    v_7167 = qvalue(elt(env, 1)); // outputhandler!*
    goto v_7101;
v_7102:
    v_7168 = elt(env, 2); // terpri
    goto v_7103;
v_7104:
    v_7166 = stack[0];
    goto v_7105;
v_7106:
    goto v_7100;
v_7101:
    goto v_7102;
v_7103:
    goto v_7104;
v_7105:
        return Lapply2(nil, 3, v_7167, v_7168, v_7166);
v_7097:
    v_7166 = qvalue(elt(env, 3)); // testing!-width!*
    if (v_7166 == nil) goto v_7111;
    v_7166 = lisp_true;
    qvalue(elt(env, 4)) = v_7166; // overflowed!*
    goto v_7092;
v_7111:
    v_7166 = qvalue(elt(env, 5)); // !*fort
    if (v_7166 == nil) goto v_7115;
    v_7166 = stack[0];
    {
        fn = elt(env, 13); // fterpri
        return (*qfn1(fn))(fn, v_7166);
    }
v_7115:
    v_7166 = qvalue(elt(env, 6)); // !*nat
    if (v_7166 == nil) goto v_7120;
    v_7166 = qvalue(elt(env, 7)); // pline!*
    if (v_7166 == nil) goto v_7120;
    v_7166 = qvalue(elt(env, 7)); // pline!*
    v_7166 = Lreverse(nil, v_7166);
    env = stack[-2];
    qvalue(elt(env, 7)) = v_7166; // pline!*
    v_7166 = qvalue(elt(env, 8)); // ymax!*
    stack[-1] = v_7166;
v_7130:
    goto v_7142;
v_7138:
    v_7167 = stack[-1];
    goto v_7139;
v_7140:
    v_7166 = qvalue(elt(env, 9)); // ymin!*
    goto v_7141;
v_7142:
    goto v_7138;
v_7139:
    goto v_7140;
v_7141:
    v_7166 = difference2(v_7167, v_7166);
    env = stack[-2];
    v_7166 = Lminusp(nil, v_7166);
    env = stack[-2];
    if (v_7166 == nil) goto v_7135;
    goto v_7129;
v_7135:
    goto v_7151;
v_7147:
    v_7167 = qvalue(elt(env, 7)); // pline!*
    goto v_7148;
v_7149:
    v_7166 = stack[-1];
    goto v_7150;
v_7151:
    goto v_7147;
v_7148:
    goto v_7149;
v_7150:
    fn = elt(env, 14); // scprint
    v_7166 = (*qfn2(fn))(fn, v_7167, v_7166);
    env = stack[-2];
    v_7166 = Lterpri(nil, 0);
    env = stack[-2];
    v_7166 = stack[-1];
    v_7166 = sub1(v_7166);
    env = stack[-2];
    stack[-1] = v_7166;
    goto v_7130;
v_7129:
    v_7166 = nil;
    qvalue(elt(env, 7)) = v_7166; // pline!*
    goto v_7095;
v_7120:
v_7095:
    v_7166 = stack[0];
    if (v_7166 == nil) goto v_7161;
    v_7166 = Lterpri(nil, 0);
    env = stack[-2];
    goto v_7159;
v_7161:
v_7159:
    v_7166 = qvalue(elt(env, 10)); // orig!*
    qvalue(elt(env, 11)) = v_7166; // posn!*
    v_7166 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 9)) = v_7166; // ymin!*
    qvalue(elt(env, 8)) = v_7166; // ymax!*
    qvalue(elt(env, 12)) = v_7166; // ycoord!*
    v_7166 = nil;
v_7092:
    return onevalue(v_7166);
}



// Code for rd!:minus

static LispObject CC_rdTminus(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7110, v_7111;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7088);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7111 = v_7088;
// end of prologue
    v_7110 = v_7111;
    v_7110 = qcdr(v_7110);
    if (!consp(v_7110)) goto v_7092;
    else goto v_7093;
v_7092:
    goto v_7101;
v_7097:
    stack[0] = elt(env, 1); // !:rd!:
    goto v_7098;
v_7099:
    v_7110 = v_7111;
    v_7110 = qcdr(v_7110);
    fn = elt(env, 2); // safe!-fp!-minus
    v_7110 = (*qfn1(fn))(fn, v_7110);
    goto v_7100;
v_7101:
    goto v_7097;
v_7098:
    goto v_7099;
v_7100:
    {
        LispObject v_7113 = stack[0];
        return cons(v_7113, v_7110);
    }
v_7093:
    v_7110 = v_7111;
    {
        fn = elt(env, 3); // minus!:
        return (*qfn1(fn))(fn, v_7110);
    }
    v_7110 = nil;
    return onevalue(v_7110);
}



// Code for groebcpcompless!?

static LispObject CC_groebcpcomplessW(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7202, v_7203, v_7204, v_7205;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7089;
    stack[-1] = v_7088;
// end of prologue
    v_7202 = qvalue(elt(env, 1)); // !*gsugar
    if (v_7202 == nil) goto v_7094;
    goto v_7101;
v_7097:
    v_7202 = stack[-1];
    v_7202 = qcdr(v_7202);
    v_7202 = qcdr(v_7202);
    v_7202 = qcdr(v_7202);
    v_7203 = qcar(v_7202);
    goto v_7098;
v_7099:
    v_7202 = stack[0];
    v_7202 = qcdr(v_7202);
    v_7202 = qcdr(v_7202);
    v_7202 = qcdr(v_7202);
    v_7202 = qcar(v_7202);
    goto v_7100;
v_7101:
    goto v_7097;
v_7098:
    goto v_7099;
v_7100:
    stack[-2] = difference2(v_7203, v_7202);
    env = stack[-3];
    goto v_7117;
v_7113:
    v_7202 = stack[-1];
    v_7203 = qcar(v_7202);
    goto v_7114;
v_7115:
    v_7202 = stack[0];
    v_7202 = qcar(v_7202);
    goto v_7116;
v_7117:
    goto v_7113;
v_7114:
    goto v_7115;
v_7116:
    fn = elt(env, 3); // vevcomp
    v_7202 = (*qfn2(fn))(fn, v_7203, v_7202);
    env = stack[-3];
    v_7205 = stack[-2];
    v_7204 = v_7202;
    goto v_7132;
v_7128:
    v_7203 = v_7205;
    goto v_7129;
v_7130:
    v_7202 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7131;
v_7132:
    goto v_7128;
v_7129:
    goto v_7130;
v_7131:
    if (v_7203 == v_7202) goto v_7127;
    goto v_7140;
v_7136:
    v_7203 = v_7205;
    goto v_7137;
v_7138:
    v_7202 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7139;
v_7140:
    goto v_7136;
v_7137:
    goto v_7138;
v_7139:
        return Llessp(nil, v_7203, v_7202);
v_7127:
    goto v_7149;
v_7145:
    v_7203 = v_7204;
    goto v_7146;
v_7147:
    v_7202 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7148;
v_7149:
    goto v_7145;
v_7146:
    goto v_7147;
v_7148:
    if (v_7203 == v_7202) goto v_7144;
    goto v_7157;
v_7153:
    v_7203 = v_7204;
    goto v_7154;
v_7155:
    v_7202 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7156;
v_7157:
    goto v_7153;
v_7154:
    goto v_7155;
v_7156:
        return Llessp(nil, v_7203, v_7202);
v_7144:
    goto v_7167;
v_7163:
    goto v_7173;
v_7169:
    v_7202 = stack[-1];
    v_7202 = qcdr(v_7202);
    v_7202 = qcdr(v_7202);
    v_7203 = qcar(v_7202);
    goto v_7170;
v_7171:
    v_7202 = elt(env, 2); // number
    goto v_7172;
v_7173:
    goto v_7169;
v_7170:
    goto v_7171;
v_7172:
    fn = elt(env, 4); // vdpgetprop
    stack[-1] = (*qfn2(fn))(fn, v_7203, v_7202);
    env = stack[-3];
    goto v_7164;
v_7165:
    goto v_7184;
v_7180:
    v_7202 = stack[0];
    v_7202 = qcdr(v_7202);
    v_7202 = qcdr(v_7202);
    v_7203 = qcar(v_7202);
    goto v_7181;
v_7182:
    v_7202 = elt(env, 2); // number
    goto v_7183;
v_7184:
    goto v_7180;
v_7181:
    goto v_7182;
v_7183:
    fn = elt(env, 4); // vdpgetprop
    v_7202 = (*qfn2(fn))(fn, v_7203, v_7202);
    goto v_7166;
v_7167:
    goto v_7163;
v_7164:
    goto v_7165;
v_7166:
    {
        LispObject v_7209 = stack[-1];
        return Llessp(nil, v_7209, v_7202);
    }
    v_7202 = nil;
    goto v_7092;
v_7094:
    goto v_7197;
v_7193:
    v_7202 = stack[-1];
    v_7203 = qcar(v_7202);
    goto v_7194;
v_7195:
    v_7202 = stack[0];
    v_7202 = qcar(v_7202);
    goto v_7196;
v_7197:
    goto v_7193;
v_7194:
    goto v_7195;
v_7196:
    {
        fn = elt(env, 5); // vevcompless!?
        return (*qfn2(fn))(fn, v_7203, v_7202);
    }
    v_7202 = nil;
v_7092:
    return onevalue(v_7202);
}



// Code for wedget2

static LispObject CC_wedget2(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7184, v_7185, v_7186;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7089;
    stack[-1] = v_7088;
// end of prologue
    goto v_7099;
v_7095:
    v_7184 = stack[-1];
    v_7185 = qcar(v_7184);
    goto v_7096;
v_7097:
    v_7184 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7098;
v_7099:
    goto v_7095;
v_7096:
    goto v_7097;
v_7098:
    if (v_7185 == v_7184) goto v_7093;
    else goto v_7094;
v_7093:
    goto v_7109;
v_7105:
    v_7184 = stack[0];
    stack[-2] = qcar(v_7184);
    goto v_7106;
v_7107:
    goto v_7117;
v_7113:
    v_7184 = stack[-1];
    v_7185 = qcdr(v_7184);
    goto v_7114;
v_7115:
    v_7184 = stack[0];
    v_7184 = qcdr(v_7184);
    goto v_7116;
v_7117:
    goto v_7113;
v_7114:
    goto v_7115;
v_7116:
    fn = elt(env, 1); // multsq
    v_7184 = (*qfn2(fn))(fn, v_7185, v_7184);
    env = stack[-3];
    goto v_7108;
v_7109:
    goto v_7105;
v_7106:
    goto v_7107;
v_7108:
    v_7184 = cons(stack[-2], v_7184);
    return ncons(v_7184);
v_7094:
    goto v_7128;
v_7124:
    v_7184 = stack[0];
    v_7184 = qcar(v_7184);
    v_7185 = qcar(v_7184);
    goto v_7125;
v_7126:
    v_7184 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7127;
v_7128:
    goto v_7124;
v_7125:
    goto v_7126;
v_7127:
    if (v_7185 == v_7184) goto v_7122;
    else goto v_7123;
v_7122:
    goto v_7139;
v_7135:
    v_7184 = stack[-1];
    v_7184 = qcar(v_7184);
    stack[-2] = ncons(v_7184);
    env = stack[-3];
    goto v_7136;
v_7137:
    goto v_7148;
v_7144:
    v_7184 = stack[-1];
    v_7185 = qcdr(v_7184);
    goto v_7145;
v_7146:
    v_7184 = stack[0];
    v_7184 = qcdr(v_7184);
    goto v_7147;
v_7148:
    goto v_7144;
v_7145:
    goto v_7146;
v_7147:
    fn = elt(env, 1); // multsq
    v_7184 = (*qfn2(fn))(fn, v_7185, v_7184);
    env = stack[-3];
    goto v_7138;
v_7139:
    goto v_7135;
v_7136:
    goto v_7137;
v_7138:
    v_7184 = cons(stack[-2], v_7184);
    return ncons(v_7184);
v_7123:
    goto v_7160;
v_7156:
    goto v_7168;
v_7162:
    v_7184 = stack[-1];
    v_7186 = qcar(v_7184);
    goto v_7163;
v_7164:
    v_7184 = stack[0];
    v_7185 = qcar(v_7184);
    goto v_7165;
v_7166:
    v_7184 = nil;
    goto v_7167;
v_7168:
    goto v_7162;
v_7163:
    goto v_7164;
v_7165:
    goto v_7166;
v_7167:
    fn = elt(env, 2); // wedgek2
    stack[-2] = (*qfnn(fn))(fn, 3, v_7186, v_7185, v_7184);
    env = stack[-3];
    goto v_7157;
v_7158:
    goto v_7179;
v_7175:
    v_7184 = stack[-1];
    v_7185 = qcdr(v_7184);
    goto v_7176;
v_7177:
    v_7184 = stack[0];
    v_7184 = qcdr(v_7184);
    goto v_7178;
v_7179:
    goto v_7175;
v_7176:
    goto v_7177;
v_7178:
    fn = elt(env, 1); // multsq
    v_7184 = (*qfn2(fn))(fn, v_7185, v_7184);
    env = stack[-3];
    goto v_7159;
v_7160:
    goto v_7156;
v_7157:
    goto v_7158;
v_7159:
    {
        LispObject v_7190 = stack[-2];
        fn = elt(env, 3); // multpfsq
        return (*qfn2(fn))(fn, v_7190, v_7184);
    }
    v_7184 = nil;
    return onevalue(v_7184);
}



// Code for wtchk

static LispObject CC_wtchk(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7154, v_7155, v_7156;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_7089;
    stack[-2] = v_7088;
// end of prologue
    v_7154 = stack[-1];
    if (v_7154 == nil) goto v_7093;
    else goto v_7094;
v_7093:
    v_7154 = stack[-2];
    goto v_7092;
v_7094:
    goto v_7104;
v_7100:
    v_7154 = stack[-2];
    stack[-3] = ncons(v_7154);
    env = stack[-4];
    goto v_7101;
v_7102:
    goto v_7113;
v_7109:
    goto v_7119;
v_7115:
    stack[0] = elt(env, 1); // k!*
    goto v_7116;
v_7117:
    goto v_7126;
v_7122:
    v_7155 = stack[-1];
    goto v_7123;
v_7124:
    v_7154 = stack[-2];
    v_7154 = qcar(v_7154);
    v_7154 = qcdr(v_7154);
    goto v_7125;
v_7126:
    goto v_7122;
v_7123:
    goto v_7124;
v_7125:
    v_7154 = times2(v_7155, v_7154);
    env = stack[-4];
    goto v_7118;
v_7119:
    goto v_7115;
v_7116:
    goto v_7117;
v_7118:
    fn = elt(env, 3); // to
    v_7155 = (*qfn2(fn))(fn, stack[0], v_7154);
    env = stack[-4];
    goto v_7110;
v_7111:
    v_7154 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7112;
v_7113:
    goto v_7109;
v_7110:
    goto v_7111;
v_7112:
    v_7154 = cons(v_7155, v_7154);
    env = stack[-4];
    v_7154 = ncons(v_7154);
    env = stack[-4];
    goto v_7103;
v_7104:
    goto v_7100;
v_7101:
    goto v_7102;
v_7103:
    fn = elt(env, 4); // quotf
    v_7154 = (*qfn2(fn))(fn, stack[-3], v_7154);
    env = stack[-4];
    v_7155 = v_7154;
    v_7154 = v_7155;
    if (v_7154 == nil) goto v_7135;
    else goto v_7136;
v_7135:
    goto v_7146;
v_7140:
    v_7156 = elt(env, 2); // "weight confusion"
    goto v_7141;
v_7142:
    v_7155 = stack[-2];
    goto v_7143;
v_7144:
    v_7154 = stack[-1];
    goto v_7145;
v_7146:
    goto v_7140;
v_7141:
    goto v_7142;
v_7143:
    goto v_7144;
v_7145:
    v_7154 = list3(v_7156, v_7155, v_7154);
    env = stack[-4];
    {
        fn = elt(env, 5); // errach
        return (*qfn1(fn))(fn, v_7154);
    }
v_7136:
    v_7154 = v_7155;
    v_7154 = qcar(v_7154);
    goto v_7134;
    v_7154 = nil;
v_7134:
    goto v_7092;
    v_7154 = nil;
v_7092:
    return onevalue(v_7154);
}



// Code for mo!=revlexcomp

static LispObject CC_moMrevlexcomp(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7130;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7089;
    stack[-1] = v_7088;
// end of prologue
    goto v_7099;
v_7095:
    v_7130 = stack[-1];
    stack[-2] = Llength(nil, v_7130);
    env = stack[-3];
    goto v_7096;
v_7097:
    v_7130 = stack[0];
    v_7130 = Llength(nil, v_7130);
    env = stack[-3];
    goto v_7098;
v_7099:
    goto v_7095;
v_7096:
    goto v_7097;
v_7098:
    if (((intptr_t)(stack[-2])) > ((intptr_t)(v_7130))) goto v_7093;
    else goto v_7094;
v_7093:
    v_7130 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_7092;
v_7094:
    goto v_7111;
v_7107:
    v_7130 = stack[0];
    stack[-2] = Llength(nil, v_7130);
    env = stack[-3];
    goto v_7108;
v_7109:
    v_7130 = stack[-1];
    v_7130 = Llength(nil, v_7130);
    env = stack[-3];
    goto v_7110;
v_7111:
    goto v_7107;
v_7108:
    goto v_7109;
v_7110:
    if (((intptr_t)(stack[-2])) > ((intptr_t)(v_7130))) goto v_7105;
    else goto v_7106;
v_7105:
    v_7130 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7092;
v_7106:
    goto v_7125;
v_7121:
    v_7130 = stack[-1];
    stack[-1] = Lreverse(nil, v_7130);
    env = stack[-3];
    goto v_7122;
v_7123:
    v_7130 = stack[0];
    v_7130 = Lreverse(nil, v_7130);
    env = stack[-3];
    goto v_7124;
v_7125:
    goto v_7121;
v_7122:
    goto v_7123;
v_7124:
    fn = elt(env, 1); // mo!=degcomp
    v_7130 = (*qfn2(fn))(fn, stack[-1], v_7130);
    return negate(v_7130);
    v_7130 = nil;
v_7092:
    return onevalue(v_7130);
}



// Code for dd

static LispObject CC_dd(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7194, v_7195, v_7196;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_7089;
    stack[-2] = v_7088;
// end of prologue
    goto v_7100;
v_7096:
    v_7195 = stack[0];
    goto v_7097;
v_7098:
    v_7194 = stack[-2];
    goto v_7099;
v_7100:
    goto v_7096;
v_7097:
    goto v_7098;
v_7099:
    fn = elt(env, 5); // dquot
    v_7194 = (*qfn2(fn))(fn, v_7195, v_7194);
    env = stack[-4];
    v_7196 = v_7194;
    v_7194 = v_7196;
    if (v_7194 == nil) goto v_7105;
    else goto v_7106;
v_7105:
    goto v_7117;
v_7113:
    v_7195 = stack[-2];
    goto v_7114;
v_7115:
    v_7194 = stack[0];
    goto v_7116;
v_7117:
    goto v_7113;
v_7114:
    goto v_7115;
v_7116:
    fn = elt(env, 6); // dless
    v_7194 = (*qfn2(fn))(fn, v_7195, v_7194);
    if (v_7194 == nil) goto v_7111;
    v_7194 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7109;
v_7111:
    v_7194 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7109;
    v_7194 = nil;
v_7109:
    goto v_7094;
v_7106:
    goto v_7132;
v_7128:
    v_7195 = qvalue(elt(env, 1)); // ordering
    goto v_7129;
v_7130:
    v_7194 = elt(env, 2); // lex
    goto v_7131;
v_7132:
    goto v_7128;
v_7129:
    goto v_7130;
v_7131:
    if (v_7195 == v_7194) goto v_7127;
    v_7194 = v_7196;
    v_7194 = qcdr(v_7194);
    v_7196 = v_7194;
    goto v_7125;
v_7127:
v_7125:
    v_7194 = v_7196;
    fn = elt(env, 7); // leftzeros
    v_7194 = (*qfn1(fn))(fn, v_7194);
    env = stack[-4];
    stack[-3] = v_7194;
    v_7194 = qvalue(elt(env, 3)); // nc!*
    if (v_7194 == nil) goto v_7145;
    else goto v_7146;
v_7145:
    goto v_7152;
v_7148:
    stack[-1] = stack[-3];
    goto v_7149;
v_7150:
    goto v_7158;
v_7154:
    v_7194 = qvalue(elt(env, 4)); // varlist!*
    stack[0] = Llength(nil, v_7194);
    env = stack[-4];
    goto v_7155;
v_7156:
    v_7194 = stack[-2];
    fn = elt(env, 8); // class
    v_7194 = (*qfn1(fn))(fn, v_7194);
    env = stack[-4];
    goto v_7157;
v_7158:
    goto v_7154;
v_7155:
    goto v_7156;
v_7157:
    v_7194 = (LispObject)(intptr_t)((intptr_t)stack[0] - (intptr_t)v_7194 + TAG_FIXNUM);
    goto v_7151;
v_7152:
    goto v_7148;
v_7149:
    goto v_7150;
v_7151:
    v_7194 = ((intptr_t)stack[-1] < (intptr_t)v_7194) ? lisp_true : nil;
    v_7194 = (v_7194 == nil ? lisp_true : nil);
    goto v_7144;
v_7146:
    v_7194 = nil;
    goto v_7144;
    v_7194 = nil;
v_7144:
    if (v_7194 == nil) goto v_7142;
    v_7194 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_7140;
v_7142:
    v_7194 = qvalue(elt(env, 3)); // nc!*
    if (v_7194 == nil) goto v_7171;
    goto v_7179;
v_7175:
    stack[0] = stack[-3];
    goto v_7176;
v_7177:
    goto v_7185;
v_7181:
    v_7194 = qvalue(elt(env, 4)); // varlist!*
    v_7194 = Llength(nil, v_7194);
    env = stack[-4];
    goto v_7182;
v_7183:
    v_7195 = qvalue(elt(env, 3)); // nc!*
    goto v_7184;
v_7185:
    goto v_7181;
v_7182:
    goto v_7183;
v_7184:
    v_7194 = (LispObject)(intptr_t)((intptr_t)v_7194 - (intptr_t)v_7195 + TAG_FIXNUM);
    goto v_7178;
v_7179:
    goto v_7175;
v_7176:
    goto v_7177;
v_7178:
    if (((intptr_t)(stack[0])) < ((intptr_t)(v_7194))) goto v_7171;
    v_7194 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_7140;
v_7171:
    v_7194 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_7140;
    v_7194 = nil;
v_7140:
v_7094:
    return onevalue(v_7194);
}



// Code for noncomperm

static LispObject CC_noncomperm(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7209, v_7210, v_7211;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7088);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_7088;
// end of prologue
    v_7209 = stack[-4];
    if (v_7209 == nil) goto v_7092;
    else goto v_7093;
v_7092:
    v_7209 = stack[-4];
    return ncons(v_7209);
v_7093:
    v_7209 = stack[-4];
    stack[-5] = v_7209;
v_7104:
    v_7209 = stack[-5];
    if (v_7209 == nil) goto v_7109;
    else goto v_7110;
v_7109:
    v_7209 = nil;
    goto v_7103;
v_7110:
    v_7209 = stack[-5];
    v_7209 = qcar(v_7209);
    stack[0] = v_7209;
    goto v_7121;
v_7117:
    v_7210 = stack[0];
    goto v_7118;
v_7119:
    v_7209 = stack[-4];
    goto v_7120;
v_7121:
    goto v_7117;
v_7118:
    goto v_7119;
v_7120:
    fn = elt(env, 2); // noncomdel
    v_7209 = (*qfn2(fn))(fn, v_7210, v_7209);
    env = stack[-6];
    v_7211 = v_7209;
    goto v_7133;
v_7129:
    v_7210 = v_7211;
    goto v_7130;
v_7131:
    v_7209 = elt(env, 1); // failed
    goto v_7132;
v_7133:
    goto v_7129;
v_7130:
    goto v_7131;
v_7132:
    if (v_7210 == v_7209) goto v_7127;
    else goto v_7128;
v_7127:
    v_7209 = nil;
    goto v_7126;
v_7128:
    goto v_7144;
v_7140:
    v_7209 = v_7211;
    v_7210 = CC_noncomperm(elt(env, 0), v_7209);
    env = stack[-6];
    goto v_7141;
v_7142:
    v_7209 = stack[0];
    goto v_7143;
v_7144:
    goto v_7140;
v_7141:
    goto v_7142;
v_7143:
    fn = elt(env, 3); // mapcons
    v_7209 = (*qfn2(fn))(fn, v_7210, v_7209);
    env = stack[-6];
    goto v_7126;
    v_7209 = nil;
v_7126:
    stack[-3] = v_7209;
    v_7209 = stack[-3];
    fn = elt(env, 4); // lastpair
    v_7209 = (*qfn1(fn))(fn, v_7209);
    env = stack[-6];
    stack[-2] = v_7209;
    v_7209 = stack[-5];
    v_7209 = qcdr(v_7209);
    stack[-5] = v_7209;
    v_7209 = stack[-2];
    if (!consp(v_7209)) goto v_7154;
    else goto v_7155;
v_7154:
    goto v_7104;
v_7155:
v_7105:
    v_7209 = stack[-5];
    if (v_7209 == nil) goto v_7159;
    else goto v_7160;
v_7159:
    v_7209 = stack[-3];
    goto v_7103;
v_7160:
    goto v_7168;
v_7164:
    stack[-1] = stack[-2];
    goto v_7165;
v_7166:
    v_7209 = stack[-5];
    v_7209 = qcar(v_7209);
    stack[0] = v_7209;
    goto v_7178;
v_7174:
    v_7210 = stack[0];
    goto v_7175;
v_7176:
    v_7209 = stack[-4];
    goto v_7177;
v_7178:
    goto v_7174;
v_7175:
    goto v_7176;
v_7177:
    fn = elt(env, 2); // noncomdel
    v_7209 = (*qfn2(fn))(fn, v_7210, v_7209);
    env = stack[-6];
    v_7211 = v_7209;
    goto v_7190;
v_7186:
    v_7210 = v_7211;
    goto v_7187;
v_7188:
    v_7209 = elt(env, 1); // failed
    goto v_7189;
v_7190:
    goto v_7186;
v_7187:
    goto v_7188;
v_7189:
    if (v_7210 == v_7209) goto v_7184;
    else goto v_7185;
v_7184:
    v_7209 = nil;
    goto v_7183;
v_7185:
    goto v_7201;
v_7197:
    v_7209 = v_7211;
    v_7210 = CC_noncomperm(elt(env, 0), v_7209);
    env = stack[-6];
    goto v_7198;
v_7199:
    v_7209 = stack[0];
    goto v_7200;
v_7201:
    goto v_7197;
v_7198:
    goto v_7199;
v_7200:
    fn = elt(env, 3); // mapcons
    v_7209 = (*qfn2(fn))(fn, v_7210, v_7209);
    env = stack[-6];
    goto v_7183;
    v_7209 = nil;
v_7183:
    goto v_7167;
v_7168:
    goto v_7164;
v_7165:
    goto v_7166;
v_7167:
    v_7209 = Lrplacd(nil, stack[-1], v_7209);
    env = stack[-6];
    v_7209 = stack[-2];
    fn = elt(env, 4); // lastpair
    v_7209 = (*qfn1(fn))(fn, v_7209);
    env = stack[-6];
    stack[-2] = v_7209;
    v_7209 = stack[-5];
    v_7209 = qcdr(v_7209);
    stack[-5] = v_7209;
    goto v_7105;
v_7103:
    goto v_7091;
    v_7209 = nil;
v_7091:
    return onevalue(v_7209);
}



// Code for put!-kvalue

static LispObject CC_putKkvalue(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7158, v_7159;
    LispObject fn;
    LispObject v_7091, v_7090, v_7089, v_7088;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "put-kvalue");
    va_start(aa, nargs);
    v_7088 = va_arg(aa, LispObject);
    v_7089 = va_arg(aa, LispObject);
    v_7090 = va_arg(aa, LispObject);
    v_7091 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_7091,v_7090,v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_7088,v_7089,v_7090,v_7091);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_7091;
    stack[-2] = v_7090;
    stack[-3] = v_7089;
    stack[0] = v_7088;
// end of prologue
    goto v_7106;
v_7102:
    v_7159 = stack[-1];
    goto v_7103;
v_7104:
    v_7158 = elt(env, 1); // !*sq
    goto v_7105;
v_7106:
    goto v_7102;
v_7103:
    goto v_7104;
v_7105:
    if (!consp(v_7159)) goto v_7100;
    v_7159 = qcar(v_7159);
    if (v_7159 == v_7158) goto v_7099;
    else goto v_7100;
v_7099:
    goto v_7114;
v_7110:
    v_7159 = stack[-2];
    goto v_7111;
v_7112:
    v_7158 = stack[-1];
    v_7158 = qcdr(v_7158);
    v_7158 = qcar(v_7158);
    goto v_7113;
v_7114:
    goto v_7110;
v_7111:
    goto v_7112;
v_7113:
    fn = elt(env, 3); // sq_member
    v_7158 = (*qfn2(fn))(fn, v_7159, v_7158);
    env = stack[-5];
    goto v_7098;
v_7100:
    goto v_7126;
v_7122:
    v_7159 = stack[-2];
    goto v_7123;
v_7124:
    v_7158 = stack[-1];
    goto v_7125;
v_7126:
    goto v_7122;
v_7123:
    goto v_7124;
v_7125:
    fn = elt(env, 4); // smember
    v_7158 = (*qfn2(fn))(fn, v_7159, v_7158);
    env = stack[-5];
    goto v_7098;
    v_7158 = nil;
v_7098:
    if (v_7158 == nil) goto v_7096;
    v_7158 = stack[-2];
    {
        fn = elt(env, 5); // recursiveerror
        return (*qfn1(fn))(fn, v_7158);
    }
v_7096:
    goto v_7140;
v_7134:
    stack[-4] = stack[0];
    goto v_7135;
v_7136:
    stack[0] = elt(env, 2); // kvalue
    goto v_7137;
v_7138:
    goto v_7148;
v_7144:
    goto v_7145;
v_7146:
    goto v_7155;
v_7151:
    v_7159 = stack[-2];
    goto v_7152;
v_7153:
    v_7158 = stack[-1];
    goto v_7154;
v_7155:
    goto v_7151;
v_7152:
    goto v_7153;
v_7154:
    v_7158 = list2(v_7159, v_7158);
    env = stack[-5];
    goto v_7147;
v_7148:
    goto v_7144;
v_7145:
    goto v_7146;
v_7147:
    fn = elt(env, 6); // aconc
    v_7158 = (*qfn2(fn))(fn, stack[-3], v_7158);
    goto v_7139;
v_7140:
    goto v_7134;
v_7135:
    goto v_7136;
v_7137:
    goto v_7138;
v_7139:
    {
        LispObject v_7165 = stack[-4];
        LispObject v_7166 = stack[0];
        return Lputprop(nil, 3, v_7165, v_7166, v_7158);
    }
    v_7158 = nil;
    return onevalue(v_7158);
}



// Code for gcref_mknode!-tgf

static LispObject CC_gcref_mknodeKtgf(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7097;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7088);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_7088;
// end of prologue
    v_7097 = stack[0];
    v_7097 = Lprinc(nil, v_7097);
    env = stack[-1];
    v_7097 = elt(env, 1); // " "
    v_7097 = Lprinc(nil, v_7097);
    env = stack[-1];
    v_7097 = stack[0];
    fn = elt(env, 2); // prin2t
    v_7097 = (*qfn1(fn))(fn, v_7097);
    v_7097 = nil;
    return onevalue(v_7097);
}



// Code for exceeds!-order

static LispObject CC_exceedsKorder(LispObject env,
                         LispObject v_7088, LispObject v_7089)
{
    env = qenv(env);
    LispObject v_7151, v_7152;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7089,v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7088,v_7089);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7089;
    stack[-1] = v_7088;
// end of prologue
v_7087:
    v_7151 = stack[-1];
    if (v_7151 == nil) goto v_7093;
    else goto v_7094;
v_7093:
    v_7151 = nil;
    goto v_7092;
v_7094:
    goto v_7108;
v_7104:
    v_7151 = stack[0];
    v_7151 = qcar(v_7151);
    stack[-2] = v_7151;
    v_7151 = (LispObject)0+TAG_FIXNUM; // 0
    v_7152 = v_7151;
v_7113:
    v_7151 = stack[-2];
    if (v_7151 == nil) goto v_7119;
    else goto v_7120;
v_7119:
    v_7151 = v_7152;
    v_7152 = v_7151;
    goto v_7112;
v_7120:
    goto v_7128;
v_7124:
    v_7151 = stack[-2];
    v_7151 = qcar(v_7151);
    goto v_7125;
v_7126:
    goto v_7127;
v_7128:
    goto v_7124;
v_7125:
    goto v_7126;
v_7127:
    fn = elt(env, 1); // tayexp!-plus2
    v_7151 = (*qfn2(fn))(fn, v_7151, v_7152);
    env = stack[-3];
    v_7152 = v_7151;
    v_7151 = stack[-2];
    v_7151 = qcdr(v_7151);
    stack[-2] = v_7151;
    goto v_7113;
v_7112:
    goto v_7105;
v_7106:
    v_7151 = stack[-1];
    v_7151 = qcar(v_7151);
    goto v_7107;
v_7108:
    goto v_7104;
v_7105:
    goto v_7106;
v_7107:
    fn = elt(env, 2); // tayexp!-lessp
    v_7151 = (*qfn2(fn))(fn, v_7152, v_7151);
    env = stack[-3];
    if (v_7151 == nil) goto v_7101;
    else goto v_7102;
v_7101:
    v_7151 = lisp_true;
    goto v_7100;
v_7102:
    goto v_7146;
v_7142:
    v_7151 = stack[-1];
    v_7152 = qcdr(v_7151);
    goto v_7143;
v_7144:
    v_7151 = stack[0];
    v_7151 = qcdr(v_7151);
    goto v_7145;
v_7146:
    goto v_7142;
v_7143:
    goto v_7144;
v_7145:
    stack[-1] = v_7152;
    stack[0] = v_7151;
    goto v_7087;
    v_7151 = nil;
v_7100:
    goto v_7092;
    v_7151 = nil;
v_7092:
    return onevalue(v_7151);
}



// Code for talp_rnf

static LispObject CC_talp_rnf(LispObject env,
                         LispObject v_7088)
{
    env = qenv(env);
    LispObject v_7102, v_7103, v_7104;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7088);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7088);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7102 = v_7088;
// end of prologue
    goto v_7098;
v_7092:
    v_7104 = v_7102;
    goto v_7093;
v_7094:
    v_7103 = nil;
    goto v_7095;
v_7096:
    v_7102 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_7097;
v_7098:
    goto v_7092;
v_7093:
    goto v_7094;
v_7095:
    goto v_7096;
v_7097:
    fn = elt(env, 1); // cl_simpl
    v_7102 = (*qfnn(fn))(fn, 3, v_7104, v_7103, v_7102);
    env = stack[0];
    {
        fn = elt(env, 2); // talp_rnf1
        return (*qfn1(fn))(fn, v_7102);
    }
}



setup_type const u13_setup[] =
{
    {"gcdf2",                   TOO_FEW_2,      CC_gcdf2,      WRONG_NO_2},
    {"subs3f1",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_subs3f1},
    {"get_group_in",            CC_get_group_in,TOO_MANY_1,    WRONG_NO_1},
    {"mkzl",                    CC_mkzl,        TOO_MANY_1,    WRONG_NO_1},
    {"naryrd",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_naryrd},
    {"spquotematrix",           CC_spquotematrix,TOO_MANY_1,   WRONG_NO_1},
    {"fortranop",               CC_fortranop,   TOO_MANY_1,    WRONG_NO_1},
    {"tokquote",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_tokquote},
    {"red-ratios1",             TOO_FEW_2,      CC_redKratios1,WRONG_NO_2},
    {"multop",                  TOO_FEW_2,      CC_multop,     WRONG_NO_2},
    {"dividef",                 TOO_FEW_2,      CC_dividef,    WRONG_NO_2},
    {"dl_get",                  CC_dl_get,      TOO_MANY_1,    WRONG_NO_1},
    {"crprcd",                  CC_crprcd,      TOO_MANY_1,    WRONG_NO_1},
    {"*q2f",                    CC_Hq2f,        TOO_MANY_1,    WRONG_NO_1},
    {"qqe_ofsf_varlterm",       TOO_FEW_2,      CC_qqe_ofsf_varlterm,WRONG_NO_2},
    {"intexprnp",               TOO_FEW_2,      CC_intexprnp,  WRONG_NO_2},
    {"lesspcdr",                TOO_FEW_2,      CC_lesspcdr,   WRONG_NO_2},
    {"cgb_buch-ev_divides?",    TOO_FEW_2,      CC_cgb_buchKev_dividesW,WRONG_NO_2},
    {"sub_math",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_sub_math},
    {"zeropp",                  CC_zeropp,      TOO_MANY_1,    WRONG_NO_1},
    {"unbind",                  CC_unbind,      TOO_MANY_1,    WRONG_NO_1},
    {"sc_null",                 CC_sc_null,     TOO_MANY_1,    WRONG_NO_1},
    {"assert_dyntypep",         CC_assert_dyntypep,TOO_MANY_1, WRONG_NO_1},
    {"simptimes",               CC_simptimes,   TOO_MANY_1,    WRONG_NO_1},
    {"pdif",                    TOO_FEW_2,      CC_pdif,       WRONG_NO_2},
    {"lalr_most_common_reduction",CC_lalr_most_common_reduction,TOO_MANY_1,WRONG_NO_1},
    {"quotfdx",                 TOO_FEW_2,      CC_quotfdx,    WRONG_NO_2},
    {"undefdchk",               CC_undefdchk,   TOO_MANY_1,    WRONG_NO_1},
    {"rl_simp",                 CC_rl_simp,     TOO_MANY_1,    WRONG_NO_1},
    {"mk+mat+mult+mat",         TOO_FEW_2,      CC_mkLmatLmultLmat,WRONG_NO_2},
    {"talp_chkknowl",           TOO_FEW_2,      CC_talp_chkknowl,WRONG_NO_2},
    {"qqe_ofsf_prepat",         CC_qqe_ofsf_prepat,TOO_MANY_1, WRONG_NO_1},
    {"rl_susitf",               TOO_FEW_2,      CC_rl_susitf,  WRONG_NO_2},
    {"ibalp_hassimple",         CC_ibalp_hassimple,TOO_MANY_1, WRONG_NO_1},
    {"vevlcm",                  TOO_FEW_2,      CC_vevlcm,     WRONG_NO_2},
    {"listdiff",                TOO_FEW_2,      CC_listdiff,   WRONG_NO_2},
    {"deletemult*",             CC_deletemultH, TOO_MANY_1,    WRONG_NO_1},
    {"aminusp:",                CC_aminuspT,    TOO_MANY_1,    WRONG_NO_1},
    {"pv_times3",               TOO_FEW_2,      CC_pv_times3,  WRONG_NO_2},
    {"b:ordexn",                TOO_FEW_2,      CC_bTordexn,   WRONG_NO_2},
    {"cde_lassoc2",             TOO_FEW_2,      CC_cde_lassoc2,WRONG_NO_2},
    {"p_princ",                 TOO_FEW_2,      CC_p_princ,    WRONG_NO_2},
    {"removeg1",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_removeg1},
    {"talp_simplatrinv",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_simplatrinv},
    {"qqe_qprefix-var",         CC_qqe_qprefixKvar,TOO_MANY_1, WRONG_NO_1},
    {"terpri*",                 CC_terpriH,     TOO_MANY_1,    WRONG_NO_1},
    {"rd:minus",                CC_rdTminus,    TOO_MANY_1,    WRONG_NO_1},
    {"groebcpcompless?",        TOO_FEW_2,      CC_groebcpcomplessW,WRONG_NO_2},
    {"wedget2",                 TOO_FEW_2,      CC_wedget2,    WRONG_NO_2},
    {"wtchk",                   TOO_FEW_2,      CC_wtchk,      WRONG_NO_2},
    {"mo=revlexcomp",           TOO_FEW_2,      CC_moMrevlexcomp,WRONG_NO_2},
    {"dd",                      TOO_FEW_2,      CC_dd,         WRONG_NO_2},
    {"noncomperm",              CC_noncomperm,  TOO_MANY_1,    WRONG_NO_1},
    {"put-kvalue",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_putKkvalue},
    {"gcref_mknode-tgf",        CC_gcref_mknodeKtgf,TOO_MANY_1,WRONG_NO_1},
    {"exceeds-order",           TOO_FEW_2,      CC_exceedsKorder,WRONG_NO_2},
    {"talp_rnf",                CC_talp_rnf,    TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u13", (two_args *)"165568 8125554 7912416", 0}
};

// end of generated code
