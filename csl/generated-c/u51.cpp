
// $destdir/u51.c        Machine generated C code

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



// Code for constructinvolutivebasis

static LispObject CC_constructinvolutivebasis(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_31046, v_31047, v_31048;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_30755;
    stack[0] = v_30754;
// end of prologue
    goto v_30770;
v_30766:
    v_31047 = stack[0];
    goto v_30767;
v_30768:
    v_31046 = lisp_true;
    goto v_30769;
v_30770:
    goto v_30766;
v_30767:
    goto v_30768;
v_30769:
    fn = elt(env, 4); // polynomlistautoreduce
    v_31046 = (*qfn2(fn))(fn, v_31047, v_31046);
    env = stack[-7];
    stack[0] = v_31046;
v_30775:
    v_31046 = stack[0];
    v_31046 = qcar(v_31046);
    if (v_31046 == nil) goto v_30778;
    else goto v_30779;
v_30778:
    goto v_30774;
v_30779:
    goto v_30788;
v_30784:
    stack[-1] = qvalue(elt(env, 1)); // fluidbibasissetq
    goto v_30785;
v_30786:
    v_31046 = stack[0];
    v_31046 = qcar(v_31046);
    fn = elt(env, 5); // createtriple
    v_31046 = (*qfn1(fn))(fn, v_31046);
    env = stack[-7];
    goto v_30787;
v_30788:
    goto v_30784;
v_30785:
    goto v_30786;
v_30787:
    fn = elt(env, 6); // sortedtriplelistinsert
    v_31046 = (*qfn2(fn))(fn, stack[-1], v_31046);
    env = stack[-7];
    v_31046 = stack[0];
    v_31046 = qcdr(v_31046);
    stack[0] = v_31046;
    goto v_30775;
v_30774:
v_30798:
    v_31046 = qvalue(elt(env, 1)); // fluidbibasissetq
    v_31046 = qcar(v_31046);
    if (v_31046 == nil) goto v_30801;
    else goto v_30802;
v_30801:
    goto v_30797;
v_30802:
    fn = elt(env, 7); // setqget
    v_31046 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    stack[-6] = v_31046;
    goto v_30811;
v_30807:
    v_31047 = stack[-6];
    goto v_30808;
v_30809:
    v_31046 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30810;
v_30811:
    goto v_30807;
v_30808:
    goto v_30809;
v_30810:
    v_31046 = *(LispObject *)((char *)v_31047 + (CELL-TAG_VECTOR) + (((intptr_t)v_31046-TAG_FIXNUM)/(16/CELL)));
    v_31046 = qcar(v_31046);
    stack[-4] = v_31046;
    goto v_30821;
v_30817:
    v_31047 = stack[-6];
    goto v_30818;
v_30819:
    v_31046 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30820;
v_30821:
    goto v_30817;
v_30818:
    goto v_30819;
v_30820:
    v_31046 = *(LispObject *)((char *)v_31047 + (CELL-TAG_VECTOR) + (((intptr_t)v_31046-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 8); // normalform
    v_31046 = (*qfn1(fn))(fn, v_31046);
    env = stack[-7];
    stack[-3] = v_31046;
    v_31046 = stack[-3];
    v_31046 = qcar(v_31046);
    stack[-2] = v_31046;
    v_31046 = stack[-2];
    if (v_31046 == nil) goto v_30830;
    v_31046 = qvalue(elt(env, 2)); // fluidbibasisnonzeronormalforms
    v_31046 = (LispObject)((intptr_t)(v_31046) + 0x10);
    qvalue(elt(env, 2)) = v_31046; // fluidbibasisnonzeronormalforms
    v_31046 = nil;
    v_31046 = ncons(v_31046);
    env = stack[-7];
    stack[0] = v_31046;
    v_31046 = qvalue(elt(env, 3)); // fluidbibasissett
    stack[-1] = v_31046;
v_30839:
    v_31046 = stack[-1];
    v_31046 = qcar(v_31046);
    if (v_31046 == nil) goto v_30842;
    else goto v_30843;
v_30842:
    goto v_30838;
v_30843:
    goto v_30856;
v_30852:
    goto v_30861;
v_30857:
    v_31046 = stack[-1];
    v_31047 = qcar(v_31046);
    goto v_30858;
v_30859:
    v_31046 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30860;
v_30861:
    goto v_30857;
v_30858:
    goto v_30859;
v_30860:
    v_31046 = *(LispObject *)((char *)v_31047 + (CELL-TAG_VECTOR) + (((intptr_t)v_31046-TAG_FIXNUM)/(16/CELL)));
    v_31047 = qcar(v_31046);
    goto v_30853;
v_30854:
    v_31046 = stack[-2];
    goto v_30855;
v_30856:
    goto v_30852;
v_30853:
    goto v_30854;
v_30855:
    fn = elt(env, 9); // monomisdivisibleby
    v_31046 = (*qfn2(fn))(fn, v_31047, v_31046);
    env = stack[-7];
    if (v_31046 == nil) goto v_30850;
    goto v_30873;
v_30869:
    v_31046 = stack[-1];
    v_31047 = qcar(v_31046);
    goto v_30870;
v_30871:
    v_31046 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30872;
v_30873:
    goto v_30869;
v_30870:
    goto v_30871;
v_30872:
    v_31046 = *(LispObject *)((char *)v_31047 + (CELL-TAG_VECTOR) + (((intptr_t)v_31046-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 10); // setqdeletedescendants
    v_31046 = (*qfn1(fn))(fn, v_31046);
    env = stack[-7];
    goto v_30883;
v_30879:
    v_31047 = stack[0];
    goto v_30880;
v_30881:
    v_31046 = stack[-1];
    v_31046 = qcar(v_31046);
    goto v_30882;
v_30883:
    goto v_30879;
v_30880:
    goto v_30881;
v_30882:
    fn = elt(env, 6); // sortedtriplelistinsert
    v_31046 = (*qfn2(fn))(fn, v_31047, v_31046);
    env = stack[-7];
    goto v_30892;
v_30888:
    v_31046 = stack[-1];
    v_31047 = qcar(v_31046);
    goto v_30889;
v_30890:
    v_31046 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30891;
v_30892:
    goto v_30888;
v_30889:
    goto v_30890;
v_30891:
    v_31046 = *(LispObject *)((char *)v_31047 + (CELL-TAG_VECTOR) + (((intptr_t)v_31046-TAG_FIXNUM)/(16/CELL)));
    v_31046 = qcar(v_31046);
    fn = elt(env, 11); // janettreedelete
    v_31046 = (*qfn1(fn))(fn, v_31046);
    env = stack[-7];
    goto v_30903;
v_30899:
    goto v_30909;
v_30905:
    v_31047 = stack[-1];
    goto v_30906;
v_30907:
    v_31046 = stack[-1];
    v_31046 = qcdr(v_31046);
    v_31046 = qcar(v_31046);
    goto v_30908;
v_30909:
    goto v_30905;
v_30906:
    goto v_30907;
v_30908:
    v_31047 = Lrplaca(nil, v_31047, v_31046);
    env = stack[-7];
    goto v_30900;
v_30901:
    v_31046 = stack[-1];
    v_31046 = qcdr(v_31046);
    v_31046 = qcdr(v_31046);
    goto v_30902;
v_30903:
    goto v_30899;
v_30900:
    goto v_30901;
v_30902:
    v_31046 = Lrplacd(nil, v_31047, v_31046);
    env = stack[-7];
    goto v_30848;
v_30850:
    v_31046 = stack[-1];
    v_31046 = qcdr(v_31046);
    stack[-1] = v_31046;
    goto v_30848;
v_30848:
    goto v_30839;
v_30838:
    goto v_30932;
v_30928:
    v_31047 = stack[-4];
    goto v_30929;
v_30930:
    v_31046 = stack[-2];
    goto v_30931;
v_30932:
    goto v_30928;
v_30929:
    goto v_30930;
v_30931:
    if (v_31047 == v_31046) goto v_30926;
    else goto v_30927;
v_30926:
    goto v_30941;
v_30937:
    v_31048 = stack[-3];
    goto v_30938;
v_30939:
    goto v_30947;
v_30943:
    v_31047 = stack[-6];
    goto v_30944;
v_30945:
    v_31046 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_30946;
v_30947:
    goto v_30943;
v_30944:
    goto v_30945;
v_30946:
    v_31046 = *(LispObject *)((char *)v_31047 + (CELL-TAG_VECTOR) + (((intptr_t)v_31046-TAG_FIXNUM)/(16/CELL)));
    goto v_30940;
v_30941:
    goto v_30937;
v_30938:
    goto v_30939;
v_30940:
    fn = elt(env, 12); // createtriplewithancestor
    v_31046 = (*qfn2(fn))(fn, v_31048, v_31046);
    env = stack[-7];
    fn = elt(env, 13); // settinsert
    v_31046 = (*qfn1(fn))(fn, v_31046);
    env = stack[-7];
    goto v_30956;
v_30952:
    v_31046 = qvalue(elt(env, 3)); // fluidbibasissett
    v_31048 = qcar(v_31046);
    goto v_30953;
v_30954:
    goto v_30963;
v_30959:
    v_31047 = stack[-6];
    goto v_30960;
v_30961:
    v_31046 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_30962;
v_30963:
    goto v_30959;
v_30960:
    goto v_30961;
v_30962:
    v_31046 = *(LispObject *)((char *)v_31047 + (CELL-TAG_VECTOR) + (((intptr_t)v_31046-TAG_FIXNUM)/(16/CELL)));
    goto v_30955;
v_30956:
    goto v_30952;
v_30953:
    goto v_30954;
v_30955:
    fn = elt(env, 14); // triplesetprolongset
    v_31046 = (*qfn2(fn))(fn, v_31048, v_31046);
    env = stack[-7];
    goto v_30925;
v_30927:
    v_31046 = stack[-3];
    fn = elt(env, 5); // createtriple
    v_31046 = (*qfn1(fn))(fn, v_31046);
    env = stack[-7];
    fn = elt(env, 13); // settinsert
    v_31046 = (*qfn1(fn))(fn, v_31046);
    env = stack[-7];
    goto v_30925;
v_30925:
    v_31046 = stack[0];
    fn = elt(env, 15); // settcollectnonmultiprolongations
    v_31046 = (*qfn1(fn))(fn, v_31046);
    env = stack[-7];
    goto v_30985;
v_30981:
    goto v_30990;
v_30986:
    v_31047 = stack[-2];
    goto v_30987;
v_30988:
    v_31046 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30989;
v_30990:
    goto v_30986;
v_30987:
    goto v_30988;
v_30989:
    v_31047 = *(LispObject *)((char *)v_31047 + (CELL-TAG_VECTOR) + (((intptr_t)v_31046-TAG_FIXNUM)/(16/CELL)));
    goto v_30982;
v_30983:
    v_31046 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30984;
v_30985:
    goto v_30981;
v_30982:
    goto v_30983;
v_30984:
    v_31046 = Leqn(nil, v_31047, v_31046);
    env = stack[-7];
    if (v_31046 == nil) goto v_30979;
    v_31046 = nil;
    v_31046 = ncons(v_31046);
    env = stack[-7];
    qvalue(elt(env, 1)) = v_31046; // fluidbibasissetq
    goto v_30977;
v_30979:
    v_31046 = stack[0];
    fn = elt(env, 16); // setqinsertlist
    v_31046 = (*qfn1(fn))(fn, v_31046);
    env = stack[-7];
    goto v_30977;
v_30977:
    goto v_30828;
v_30830:
v_30828:
    goto v_30798;
v_30797:
    v_31046 = nil;
    v_31046 = ncons(v_31046);
    env = stack[-7];
    stack[0] = v_31046;
    v_31046 = qvalue(elt(env, 3)); // fluidbibasissett
    stack[-1] = v_31046;
v_31010:
    v_31046 = stack[-1];
    v_31046 = qcar(v_31046);
    if (v_31046 == nil) goto v_31013;
    else goto v_31014;
v_31013:
    goto v_31009;
v_31014:
    goto v_31023;
v_31019:
    v_31048 = stack[0];
    goto v_31020;
v_31021:
    goto v_31029;
v_31025:
    v_31046 = stack[-1];
    v_31047 = qcar(v_31046);
    goto v_31026;
v_31027:
    v_31046 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_31028;
v_31029:
    goto v_31025;
v_31026:
    goto v_31027;
v_31028:
    v_31046 = *(LispObject *)((char *)v_31047 + (CELL-TAG_VECTOR) + (((intptr_t)v_31046-TAG_FIXNUM)/(16/CELL)));
    goto v_31022;
v_31023:
    goto v_31019;
v_31020:
    goto v_31021;
v_31022:
    fn = elt(env, 17); // sortedpolynomlistinsert
    v_31046 = (*qfn2(fn))(fn, v_31048, v_31046);
    env = stack[-7];
    v_31046 = stack[-1];
    v_31046 = qcdr(v_31046);
    stack[-1] = v_31046;
    goto v_31010;
v_31009:
    goto v_31042;
v_31038:
    v_31047 = stack[0];
    goto v_31039;
v_31040:
    v_31046 = stack[-5];
    goto v_31041;
v_31042:
    goto v_31038;
v_31039:
    goto v_31040;
v_31041:
    {
        fn = elt(env, 4); // polynomlistautoreduce
        return (*qfn2(fn))(fn, v_31047, v_31046);
    }
    return onevalue(v_31046);
}



// Code for ofsf_sminsert1

static LispObject CC_ofsf_sminsert1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30943, v_30944, v_30945;
    LispObject fn;
    LispObject v_30758, v_30757, v_30756, v_30755, v_30754;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "ofsf_sminsert1");
    va_start(aa, nargs);
    v_30754 = va_arg(aa, LispObject);
    v_30755 = va_arg(aa, LispObject);
    v_30756 = va_arg(aa, LispObject);
    v_30757 = va_arg(aa, LispObject);
    v_30758 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_30758,v_30757,v_30756,v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_30754,v_30755,v_30756,v_30757,v_30758);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[0] = v_30758;
    stack[-1] = v_30757;
    stack[-2] = v_30756;
    stack[-3] = v_30755;
    stack[-4] = v_30754;
// end of prologue
    goto v_30769;
v_30765:
    stack[-5] = stack[-3];
    goto v_30766;
v_30767:
    v_30943 = stack[-1];
    fn = elt(env, 3); // negsq
    v_30943 = (*qfn1(fn))(fn, v_30943);
    env = stack[-6];
    goto v_30768;
v_30769:
    goto v_30765;
v_30766:
    goto v_30767;
v_30768:
    fn = elt(env, 4); // addsq
    v_30943 = (*qfn2(fn))(fn, stack[-5], v_30943);
    env = stack[-6];
    v_30943 = qcar(v_30943);
    v_30944 = v_30943;
    v_30943 = v_30944;
    if (v_30943 == nil) goto v_30776;
    else goto v_30777;
v_30776:
    goto v_30784;
v_30780:
    v_30944 = stack[-4];
    goto v_30781;
v_30782:
    v_30943 = stack[-2];
    goto v_30783;
v_30784:
    goto v_30780;
v_30781:
    goto v_30782;
v_30783:
    fn = elt(env, 5); // ofsf_smeqtable
    v_30943 = (*qfn2(fn))(fn, v_30944, v_30943);
    env = stack[-6];
    v_30945 = v_30943;
    goto v_30795;
v_30791:
    v_30944 = v_30945;
    goto v_30792;
v_30793:
    v_30943 = elt(env, 1); // false
    goto v_30794;
v_30795:
    goto v_30791;
v_30792:
    goto v_30793;
v_30794:
    if (v_30944 == v_30943) goto v_30789;
    else goto v_30790;
v_30789:
    v_30943 = elt(env, 1); // false
    goto v_30763;
v_30790:
    goto v_30807;
v_30803:
    v_30944 = stack[-4];
    goto v_30804;
v_30805:
    v_30943 = v_30945;
    goto v_30806;
v_30807:
    goto v_30803;
v_30804:
    goto v_30805;
v_30806:
    if (v_30944 == v_30943) goto v_30801;
    else goto v_30802;
v_30801:
    v_30943 = elt(env, 2); // true
    goto v_30763;
v_30802:
    goto v_30818;
v_30812:
    v_30944 = stack[0];
    goto v_30813;
v_30814:
    goto v_30815;
v_30816:
    v_30943 = stack[-3];
    goto v_30817;
v_30818:
    goto v_30812;
v_30813:
    goto v_30814;
v_30815:
    goto v_30816;
v_30817:
    return list2star(v_30944, v_30945, v_30943);
v_30777:
    v_30943 = v_30944;
    fn = elt(env, 6); // minusf
    v_30943 = (*qfn1(fn))(fn, v_30943);
    env = stack[-6];
    if (v_30943 == nil) goto v_30825;
    goto v_30833;
v_30829:
    v_30944 = stack[-4];
    goto v_30830;
v_30831:
    v_30943 = stack[-2];
    goto v_30832;
v_30833:
    goto v_30829;
v_30830:
    goto v_30831;
v_30832:
    fn = elt(env, 7); // ofsf_smordtable
    v_30943 = (*qfn2(fn))(fn, v_30944, v_30943);
    env = stack[-6];
    v_30945 = v_30943;
    v_30943 = v_30945;
    if (!consp(v_30943)) goto v_30838;
    else goto v_30839;
v_30838:
    v_30943 = v_30945;
    goto v_30763;
v_30839:
    goto v_30855;
v_30851:
    v_30944 = v_30945;
    goto v_30852;
v_30853:
    v_30943 = stack[-4];
    goto v_30854;
v_30855:
    goto v_30851;
v_30852:
    goto v_30853;
v_30854:
    if (!consp(v_30944)) goto v_30849;
    v_30944 = qcar(v_30944);
    if (v_30944 == v_30943) goto v_30848;
    else goto v_30849;
v_30848:
    v_30943 = v_30945;
    v_30943 = qcdr(v_30943);
    goto v_30847;
v_30849:
    v_30943 = nil;
    goto v_30847;
    v_30943 = nil;
v_30847:
    if (v_30943 == nil) goto v_30845;
    v_30943 = elt(env, 2); // true
    goto v_30763;
v_30845:
    goto v_30871;
v_30865:
    v_30944 = stack[0];
    goto v_30866;
v_30867:
    v_30943 = v_30945;
    v_30943 = qcar(v_30943);
    goto v_30868;
v_30869:
    v_30945 = qcdr(v_30945);
    if (v_30945 == nil) goto v_30878;
    v_30945 = stack[-3];
    goto v_30876;
v_30878:
    v_30945 = stack[-1];
    goto v_30876;
    v_30945 = nil;
v_30876:
    goto v_30870;
v_30871:
    goto v_30865;
v_30866:
    goto v_30867;
v_30868:
    goto v_30869;
v_30870:
    return list2star(v_30944, v_30943, v_30945);
v_30825:
    goto v_30890;
v_30886:
    v_30944 = stack[-2];
    goto v_30887;
v_30888:
    v_30943 = stack[-4];
    goto v_30889;
v_30890:
    goto v_30886;
v_30887:
    goto v_30888;
v_30889:
    fn = elt(env, 7); // ofsf_smordtable
    v_30943 = (*qfn2(fn))(fn, v_30944, v_30943);
    env = stack[-6];
    v_30945 = v_30943;
    v_30943 = v_30945;
    if (!consp(v_30943)) goto v_30895;
    else goto v_30896;
v_30895:
    v_30943 = v_30945;
    goto v_30763;
v_30896:
    goto v_30912;
v_30908:
    v_30944 = v_30945;
    goto v_30909;
v_30910:
    v_30943 = stack[-4];
    goto v_30911;
v_30912:
    goto v_30908;
v_30909:
    goto v_30910;
v_30911:
    if (!consp(v_30944)) goto v_30906;
    v_30944 = qcar(v_30944);
    if (v_30944 == v_30943) goto v_30905;
    else goto v_30906;
v_30905:
    v_30943 = v_30945;
    v_30943 = qcdr(v_30943);
    v_30943 = (v_30943 == nil ? lisp_true : nil);
    goto v_30904;
v_30906:
    v_30943 = nil;
    goto v_30904;
    v_30943 = nil;
v_30904:
    if (v_30943 == nil) goto v_30902;
    v_30943 = elt(env, 2); // true
    goto v_30763;
v_30902:
    goto v_30929;
v_30923:
    v_30944 = stack[0];
    goto v_30924;
v_30925:
    v_30943 = v_30945;
    v_30943 = qcar(v_30943);
    goto v_30926;
v_30927:
    v_30945 = qcdr(v_30945);
    if (v_30945 == nil) goto v_30936;
    v_30945 = stack[-1];
    goto v_30934;
v_30936:
    v_30945 = stack[-3];
    goto v_30934;
    v_30945 = nil;
v_30934:
    goto v_30928;
v_30929:
    goto v_30923;
v_30924:
    goto v_30925;
v_30926:
    goto v_30927;
v_30928:
    return list2star(v_30944, v_30943, v_30945);
v_30763:
    return onevalue(v_30943);
}



// Code for talp_cocc

static LispObject CC_talp_cocc(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30831, v_30832, v_30833;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_30755;
    v_30831 = v_30754;
// end of prologue
    v_30832 = (LispObject)0+TAG_FIXNUM; // 0
    v_30833 = v_30832;
    v_30832 = v_30831;
    v_30832 = Lconsp(nil, v_30832);
    env = stack[-3];
    if (v_30832 == nil) goto v_30765;
    stack[-2] = v_30831;
v_30771:
    v_30831 = stack[-2];
    if (v_30831 == nil) goto v_30775;
    else goto v_30776;
v_30775:
    goto v_30770;
v_30776:
    v_30831 = stack[-2];
    v_30831 = qcar(v_30831);
    v_30832 = v_30831;
    v_30831 = v_30832;
    v_30831 = Lconsp(nil, v_30831);
    env = stack[-3];
    if (v_30831 == nil) goto v_30785;
    goto v_30793;
v_30789:
    stack[0] = v_30833;
    goto v_30790;
v_30791:
    goto v_30800;
v_30796:
    goto v_30797;
v_30798:
    v_30831 = stack[-1];
    goto v_30799;
v_30800:
    goto v_30796;
v_30797:
    goto v_30798;
v_30799:
    v_30831 = CC_talp_cocc(elt(env, 0), v_30832, v_30831);
    env = stack[-3];
    goto v_30792;
v_30793:
    goto v_30789;
v_30790:
    goto v_30791;
v_30792:
    v_30831 = plus2(stack[0], v_30831);
    env = stack[-3];
    v_30833 = v_30831;
    goto v_30783;
v_30785:
    goto v_30813;
v_30809:
    goto v_30810;
v_30811:
    v_30831 = stack[-1];
    goto v_30812;
v_30813:
    goto v_30809;
v_30810:
    goto v_30811;
v_30812:
    if (v_30832 == v_30831) goto v_30807;
    else goto v_30808;
v_30807:
    v_30831 = v_30833;
    v_30831 = add1(v_30831);
    env = stack[-3];
    v_30833 = v_30831;
    goto v_30806;
v_30808:
v_30806:
    goto v_30783;
v_30783:
    v_30831 = stack[-2];
    v_30831 = qcdr(v_30831);
    stack[-2] = v_30831;
    goto v_30771;
v_30770:
    goto v_30763;
v_30765:
    goto v_30826;
v_30822:
    v_30832 = stack[-1];
    goto v_30823;
v_30824:
    goto v_30825;
v_30826:
    goto v_30822;
v_30823:
    goto v_30824;
v_30825:
    if (v_30832 == v_30831) goto v_30820;
    else goto v_30821;
v_30820:
    v_30831 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30759;
v_30821:
v_30763:
    v_30831 = v_30833;
v_30759:
    return onevalue(v_30831);
}



// Code for qqe_length!-graph!-neighbors

static LispObject CC_qqe_lengthKgraphKneighbors(LispObject env,
                         LispObject v_30754)
{
    env = qenv(env);
    LispObject v_30764, v_30765;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30764 = v_30754;
// end of prologue
    goto v_30761;
v_30757:
    goto v_30758;
v_30759:
    v_30765 = elt(env, 1); // neighbors
    goto v_30760;
v_30761:
    goto v_30757;
v_30758:
    goto v_30759;
v_30760:
    return get(v_30764, v_30765);
}



// Code for pasf_smordtable2

static LispObject CC_pasf_smordtable2(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30777, v_30778, v_30779;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30777 = v_30755;
    v_30778 = v_30754;
// end of prologue
    v_30779 = elt(env, 1); // ((lessp (lessp 2) (leq 2) (equal 2) (neq nil) (geq nil) (greaterp nil) (cong nil) (ncong nil)) (leq (lessp 2) (leq 2) (equal
// 2) (neq nil) (geq nil) (greaterp nil) (cong nil) (ncong nil)) (equal (lessp false) (leq false) (equal false) (neq 1) (geq
// 1) (greaterp 1) (cong nil) (ncong nil)) (neq (lessp 2) (leq 2) (equal 2) (neq nil) (geq nil) (greaterp nil) (cong nil) (ncong
// nil)) (geq (lessp false) (leq false) (equal false) (neq 1) (geq 1) (greaterp 1) (cong nil) (ncong nil)) (greaterp (lessp
// false) (leq false) (equal false) (neq 1) (geq 1) (greaterp 1) (cong nil) (ncong nil)))
    goto v_30765;
v_30761:
    goto v_30762;
v_30763:
    goto v_30771;
v_30767:
    goto v_30768;
v_30769:
    goto v_30770;
v_30771:
    goto v_30767;
v_30768:
    goto v_30769;
v_30770:
    v_30778 = Latsoc(nil, v_30778, v_30779);
    goto v_30764;
v_30765:
    goto v_30761;
v_30762:
    goto v_30763;
v_30764:
    v_30777 = Latsoc(nil, v_30777, v_30778);
    v_30777 = qcdr(v_30777);
    return onevalue(v_30777);
}



// Code for ldf!-sep!-var

static LispObject CC_ldfKsepKvar(LispObject env,
                         LispObject v_30754)
{
    env = qenv(env);
    LispObject v_30774;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30754);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30754;
// end of prologue
    goto v_30761;
v_30757:
    goto v_30767;
v_30763:
    v_30774 = stack[0];
    fn = elt(env, 1); // ldf!-pow!-var
    stack[-1] = (*qfn1(fn))(fn, v_30774);
    env = stack[-2];
    goto v_30764;
v_30765:
    v_30774 = stack[0];
    fn = elt(env, 2); // ldf!-dep!-var
    v_30774 = (*qfn1(fn))(fn, v_30774);
    env = stack[-2];
    goto v_30766;
v_30767:
    goto v_30763;
v_30764:
    goto v_30765;
v_30766:
    fn = elt(env, 3); // compl
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_30774);
    env = stack[-2];
    goto v_30758;
v_30759:
    v_30774 = stack[0];
    fn = elt(env, 4); // ldf!-spf!-var
    v_30774 = (*qfn1(fn))(fn, v_30774);
    env = stack[-2];
    goto v_30760;
v_30761:
    goto v_30757;
v_30758:
    goto v_30759;
v_30760:
    {
        LispObject v_30777 = stack[-1];
        fn = elt(env, 3); // compl
        return (*qfn2(fn))(fn, v_30777, v_30774);
    }
}



// Code for dipreplus

static LispObject CC_dipreplus(LispObject env,
                         LispObject v_30754)
{
    env = qenv(env);
    LispObject v_30778, v_30779;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30779 = v_30754;
// end of prologue
    v_30778 = v_30779;
    if (!consp(v_30778)) goto v_30758;
    else goto v_30759;
v_30758:
    v_30778 = v_30779;
    goto v_30757;
v_30759:
    v_30778 = v_30779;
    v_30778 = qcdr(v_30778);
    if (v_30778 == nil) goto v_30762;
    else goto v_30763;
v_30762:
    v_30778 = v_30779;
    v_30778 = qcar(v_30778);
    goto v_30757;
v_30763:
    goto v_30775;
v_30771:
    v_30778 = elt(env, 1); // plus
    goto v_30772;
v_30773:
    goto v_30774;
v_30775:
    goto v_30771;
v_30772:
    goto v_30773;
v_30774:
    return cons(v_30778, v_30779);
    v_30778 = nil;
v_30757:
    return onevalue(v_30778);
}



// Code for make_wedge_pair

static LispObject CC_make_wedge_pair(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30846, v_30847, v_30848;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_30755;
    stack[-2] = v_30754;
// end of prologue
    goto v_30762;
v_30758:
    goto v_30768;
v_30764:
    v_30847 = stack[-2];
    goto v_30765;
v_30766:
    v_30846 = stack[-2];
    goto v_30767;
v_30768:
    goto v_30764;
v_30765:
    goto v_30766;
v_30767:
    stack[0] = list2(v_30847, v_30846);
    env = stack[-4];
    goto v_30759;
v_30760:
    v_30846 = stack[-1];
    fn = elt(env, 4); // xval
    v_30846 = (*qfn1(fn))(fn, v_30846);
    env = stack[-4];
    goto v_30761;
v_30762:
    goto v_30758;
v_30759:
    goto v_30760;
v_30761:
    fn = elt(env, 5); // xlcm
    v_30846 = (*qfn2(fn))(fn, stack[0], v_30846);
    env = stack[-4];
    stack[-3] = v_30846;
    v_30846 = qvalue(elt(env, 1)); // !*twosided
    if (v_30846 == nil) goto v_30778;
    v_30846 = qvalue(elt(env, 2)); // xtruncate!*
    if (v_30846 == nil) goto v_30781;
    else goto v_30778;
v_30781:
    goto v_30777;
v_30778:
    goto v_30788;
v_30784:
    stack[0] = stack[-2];
    goto v_30785;
v_30786:
    v_30846 = stack[-1];
    fn = elt(env, 4); // xval
    v_30846 = (*qfn1(fn))(fn, v_30846);
    env = stack[-4];
    goto v_30787;
v_30788:
    goto v_30784;
v_30785:
    goto v_30786;
v_30787:
    v_30846 = Lmemq(nil, stack[0], v_30846);
    if (v_30846 == nil) goto v_30783;
    else goto v_30777;
v_30783:
    v_30846 = nil;
    goto v_30775;
v_30777:
    goto v_30805;
v_30801:
    v_30847 = stack[-2];
    goto v_30802;
v_30803:
    v_30846 = stack[-1];
    goto v_30804;
v_30805:
    goto v_30801;
v_30802:
    goto v_30803;
v_30804:
    fn = elt(env, 6); // overall_factor
    v_30846 = (*qfn2(fn))(fn, v_30847, v_30846);
    env = stack[-4];
    if (v_30846 == nil) goto v_30798;
    else goto v_30799;
v_30798:
    v_30846 = stack[-3];
    fn = elt(env, 7); // mknwedge
    v_30846 = (*qfn1(fn))(fn, v_30846);
    env = stack[-4];
    fn = elt(env, 8); // xdegreecheck
    v_30846 = (*qfn1(fn))(fn, v_30846);
    env = stack[-4];
    if (v_30846 == nil) goto v_30810;
    else goto v_30811;
v_30810:
    goto v_30824;
v_30816:
    goto v_30817;
v_30818:
    stack[0] = elt(env, 3); // wedge_pair
    goto v_30819;
v_30820:
    goto v_30835;
v_30829:
    v_30848 = stack[-2];
    goto v_30830;
v_30831:
    v_30847 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30832;
v_30833:
    v_30846 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30834;
v_30835:
    goto v_30829;
v_30830:
    goto v_30831;
v_30832:
    goto v_30833;
v_30834:
    v_30846 = list2star(v_30848, v_30847, v_30846);
    env = stack[-4];
    v_30847 = ncons(v_30846);
    goto v_30821;
v_30822:
    v_30846 = stack[-1];
    goto v_30823;
v_30824:
    goto v_30816;
v_30817:
    goto v_30818;
v_30819:
    goto v_30820;
v_30821:
    goto v_30822;
v_30823:
    {
        LispObject v_30853 = stack[-3];
        LispObject v_30854 = stack[0];
        return list4(v_30853, v_30854, v_30847, v_30846);
    }
v_30811:
    v_30846 = nil;
    goto v_30809;
    v_30846 = nil;
v_30809:
    goto v_30797;
v_30799:
    v_30846 = nil;
    goto v_30797;
    v_30846 = nil;
v_30797:
    goto v_30775;
    v_30846 = nil;
v_30775:
    return onevalue(v_30846);
}



// Code for gpexpp

static LispObject CC_gpexpp(LispObject env,
                         LispObject v_30754)
{
    env = qenv(env);
    LispObject v_30991, v_30992;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30754);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_30754;
// end of prologue
v_30759:
    v_30991 = stack[0];
    if (!consp(v_30991)) goto v_30762;
    else goto v_30763;
v_30762:
    v_30991 = stack[0];
    v_30991 = Lsymbolp(nil, v_30991);
    v_30992 = v_30991;
    if (v_30991 == nil) goto v_30768;
    v_30991 = v_30992;
    goto v_30758;
v_30768:
    v_30991 = stack[0];
    v_30991 = (is_number(v_30991) ? lisp_true : nil);
    v_30992 = v_30991;
    if (v_30991 == nil) goto v_30773;
    v_30991 = v_30992;
    goto v_30758;
v_30773:
    v_30991 = nil;
    goto v_30758;
    goto v_30761;
v_30763:
    goto v_30786;
v_30782:
    v_30991 = stack[0];
    v_30992 = qcar(v_30991);
    goto v_30783;
v_30784:
    v_30991 = elt(env, 1); // (!:rd!: !:cr!: !:crn!: !:gi!:)
    goto v_30785;
v_30786:
    goto v_30782;
v_30783:
    goto v_30784;
v_30785:
    v_30991 = Lmemq(nil, v_30992, v_30991);
    if (v_30991 == nil) goto v_30781;
    v_30991 = lisp_true;
    goto v_30758;
v_30781:
    goto v_30798;
v_30794:
    v_30991 = stack[0];
    v_30992 = qcar(v_30991);
    goto v_30795;
v_30796:
    v_30991 = elt(env, 2); // plus
    goto v_30797;
v_30798:
    goto v_30794;
v_30795:
    goto v_30796;
v_30797:
    if (v_30992 == v_30991) goto v_30792;
    else goto v_30793;
v_30792:
    goto v_30811;
v_30807:
    v_30991 = stack[0];
    v_30992 = Llength(nil, v_30991);
    env = stack[-1];
    goto v_30808;
v_30809:
    v_30991 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_30810;
v_30811:
    goto v_30807;
v_30808:
    goto v_30809;
v_30810:
    v_30991 = (LispObject)geq2(v_30992, v_30991);
    v_30991 = v_30991 ? lisp_true : nil;
    env = stack[-1];
    if (v_30991 == nil) goto v_30805;
    v_30991 = stack[0];
    v_30991 = qcdr(v_30991);
    v_30991 = qcar(v_30991);
    v_30991 = CC_gpexpp(elt(env, 0), v_30991);
    env = stack[-1];
    if (v_30991 == nil) goto v_30818;
    v_30991 = stack[0];
    v_30991 = qcdr(v_30991);
    v_30991 = qcdr(v_30991);
    {
        fn = elt(env, 8); // gpexp1p
        return (*qfn1(fn))(fn, v_30991);
    }
v_30818:
    v_30991 = nil;
    goto v_30758;
    goto v_30803;
v_30805:
    v_30991 = nil;
    goto v_30758;
v_30803:
    goto v_30761;
v_30793:
    goto v_30839;
v_30835:
    v_30991 = stack[0];
    v_30992 = qcar(v_30991);
    goto v_30836;
v_30837:
    v_30991 = elt(env, 3); // (minus recip)
    goto v_30838;
v_30839:
    goto v_30835;
v_30836:
    goto v_30837;
v_30838:
    v_30991 = Lmemq(nil, v_30992, v_30991);
    if (v_30991 == nil) goto v_30834;
    goto v_30852;
v_30848:
    v_30991 = stack[0];
    v_30992 = Llength(nil, v_30991);
    env = stack[-1];
    goto v_30849;
v_30850:
    v_30991 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_30851;
v_30852:
    goto v_30848;
v_30849:
    goto v_30850;
v_30851:
    if (v_30992 == v_30991) goto v_30846;
    else goto v_30847;
v_30846:
    v_30991 = stack[0];
    v_30991 = qcdr(v_30991);
    v_30991 = qcar(v_30991);
    stack[0] = v_30991;
    goto v_30759;
v_30847:
    v_30991 = nil;
    goto v_30758;
    goto v_30761;
v_30834:
    goto v_30868;
v_30864:
    v_30991 = stack[0];
    v_30992 = qcar(v_30991);
    goto v_30865;
v_30866:
    v_30991 = elt(env, 4); // (difference quotient expt)
    goto v_30867;
v_30868:
    goto v_30864;
v_30865:
    goto v_30866;
v_30867:
    v_30991 = Lmemq(nil, v_30992, v_30991);
    if (v_30991 == nil) goto v_30863;
    goto v_30881;
v_30877:
    v_30991 = stack[0];
    v_30992 = Llength(nil, v_30991);
    env = stack[-1];
    goto v_30878;
v_30879:
    v_30991 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_30880;
v_30881:
    goto v_30877;
v_30878:
    goto v_30879;
v_30880:
    if (v_30992 == v_30991) goto v_30875;
    else goto v_30876;
v_30875:
    v_30991 = stack[0];
    v_30991 = qcdr(v_30991);
    v_30991 = qcar(v_30991);
    v_30991 = CC_gpexpp(elt(env, 0), v_30991);
    env = stack[-1];
    if (v_30991 == nil) goto v_30888;
    v_30991 = stack[0];
    v_30991 = qcdr(v_30991);
    v_30991 = qcdr(v_30991);
    v_30991 = qcar(v_30991);
    stack[0] = v_30991;
    goto v_30759;
v_30888:
    v_30991 = nil;
    goto v_30758;
    goto v_30874;
v_30876:
    v_30991 = nil;
    goto v_30758;
v_30874:
    goto v_30761;
v_30863:
    goto v_30909;
v_30905:
    v_30991 = stack[0];
    v_30992 = qcar(v_30991);
    goto v_30906;
v_30907:
    v_30991 = elt(env, 5); // times
    goto v_30908;
v_30909:
    goto v_30905;
v_30906:
    goto v_30907;
v_30908:
    if (v_30992 == v_30991) goto v_30903;
    else goto v_30904;
v_30903:
    goto v_30922;
v_30918:
    v_30991 = stack[0];
    v_30992 = Llength(nil, v_30991);
    env = stack[-1];
    goto v_30919;
v_30920:
    v_30991 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_30921;
v_30922:
    goto v_30918;
v_30919:
    goto v_30920;
v_30921:
    v_30991 = (LispObject)geq2(v_30992, v_30991);
    v_30991 = v_30991 ? lisp_true : nil;
    env = stack[-1];
    if (v_30991 == nil) goto v_30916;
    v_30991 = stack[0];
    v_30991 = qcdr(v_30991);
    v_30991 = qcar(v_30991);
    v_30991 = CC_gpexpp(elt(env, 0), v_30991);
    env = stack[-1];
    if (v_30991 == nil) goto v_30929;
    v_30991 = stack[0];
    v_30991 = qcdr(v_30991);
    v_30991 = qcdr(v_30991);
    v_30991 = qcar(v_30991);
    v_30991 = CC_gpexpp(elt(env, 0), v_30991);
    env = stack[-1];
    if (v_30991 == nil) goto v_30937;
    v_30991 = stack[0];
    v_30991 = qcdr(v_30991);
    v_30991 = qcdr(v_30991);
    v_30991 = qcdr(v_30991);
    {
        fn = elt(env, 8); // gpexp1p
        return (*qfn1(fn))(fn, v_30991);
    }
v_30937:
    v_30991 = nil;
    goto v_30758;
    goto v_30927;
v_30929:
    v_30991 = nil;
    goto v_30758;
v_30927:
    goto v_30914;
v_30916:
    v_30991 = nil;
    goto v_30758;
v_30914:
    goto v_30761;
v_30904:
    goto v_30963;
v_30959:
    v_30991 = stack[0];
    v_30992 = qcar(v_30991);
    goto v_30960;
v_30961:
    v_30991 = elt(env, 6); // !:rd!:
    goto v_30962;
v_30963:
    goto v_30959;
v_30960:
    goto v_30961;
v_30962:
    if (v_30992 == v_30991) goto v_30957;
    else goto v_30958;
v_30957:
    v_30991 = lisp_true;
    goto v_30758;
v_30958:
    goto v_30974;
v_30970:
    v_30991 = stack[0];
    v_30992 = qcar(v_30991);
    goto v_30971;
v_30972:
    v_30991 = elt(env, 7); // (!:cr!: !:crn!: !:gi!:)
    goto v_30973;
v_30974:
    goto v_30970;
v_30971:
    goto v_30972;
v_30973:
    v_30991 = Lmemq(nil, v_30992, v_30991);
    if (v_30991 == nil) goto v_30969;
    v_30991 = lisp_true;
    goto v_30758;
v_30969:
    v_30991 = stack[0];
    v_30991 = qcar(v_30991);
    fn = elt(env, 9); // unresidp
    v_30991 = (*qfn1(fn))(fn, v_30991);
    env = stack[-1];
    if (v_30991 == nil) goto v_30981;
    v_30991 = stack[0];
    v_30991 = qcdr(v_30991);
    {
        fn = elt(env, 10); // gparg1p
        return (*qfn1(fn))(fn, v_30991);
    }
v_30981:
    v_30991 = nil;
    goto v_30758;
v_30761:
    v_30991 = nil;
v_30758:
    return onevalue(v_30991);
}



// Code for rule!-list

static LispObject CC_ruleKlist(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30954, v_30955, v_30956, v_30957, v_30958;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_30755;
    stack[-2] = v_30754;
// end of prologue
v_30763:
    v_30954 = nil;
    qvalue(elt(env, 1)) = v_30954; // frasc!*
    v_30954 = stack[-2];
    if (v_30954 == nil) goto v_30771;
    else goto v_30772;
v_30771:
    v_30954 = lisp_true;
    goto v_30770;
v_30772:
    goto v_30781;
v_30777:
    stack[0] = stack[-2];
    goto v_30778;
v_30779:
    v_30954 = nil;
    v_30954 = ncons(v_30954);
    env = stack[-4];
    goto v_30780;
v_30781:
    goto v_30777;
v_30778:
    goto v_30779;
v_30780:
    v_30954 = (equal(stack[0], v_30954) ? lisp_true : nil);
    goto v_30770;
    v_30954 = nil;
v_30770:
    if (v_30954 == nil) goto v_30768;
    v_30954 = nil;
    qvalue(elt(env, 2)) = v_30954; // mcond!*
    goto v_30762;
v_30768:
    v_30954 = lisp_true;
    qvalue(elt(env, 2)) = v_30954; // mcond!*
    v_30954 = stack[-2];
    v_30954 = qcar(v_30954);
    stack[-3] = v_30954;
    v_30954 = stack[-3];
    if (symbolp(v_30954)) goto v_30792;
    else goto v_30793;
v_30792:
    v_30954 = stack[-3];
    if (!symbolp(v_30954)) v_30954 = nil;
    else { v_30954 = qfastgets(v_30954);
           if (v_30954 != nil) { v_30954 = elt(v_30954, 4); // avalue
#ifdef RECORD_GET
             if (v_30954 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_30954 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_30954 == SPID_NOPROP) v_30954 = nil; }}
#endif
    v_30956 = v_30954;
    if (v_30954 == nil) goto v_30798;
    goto v_30807;
v_30803:
    v_30954 = v_30956;
    v_30955 = qcar(v_30954);
    goto v_30804;
v_30805:
    v_30954 = elt(env, 3); // list
    goto v_30806;
v_30807:
    goto v_30803;
v_30804:
    goto v_30805;
v_30806:
    if (v_30955 == v_30954) goto v_30802;
    else goto v_30798;
v_30802:
    goto v_30816;
v_30812:
    v_30954 = v_30956;
    v_30954 = qcdr(v_30954);
    v_30954 = qcar(v_30954);
    v_30954 = qcdr(v_30954);
    v_30955 = Lreverse(nil, v_30954);
    env = stack[-4];
    goto v_30813;
v_30814:
    v_30954 = stack[-2];
    v_30954 = qcdr(v_30954);
    goto v_30815;
v_30816:
    goto v_30812;
v_30813:
    goto v_30814;
v_30815:
    v_30954 = Lappend(nil, v_30955, v_30954);
    env = stack[-4];
    stack[-2] = v_30954;
    goto v_30763;
v_30798:
    goto v_30831;
v_30827:
    v_30955 = stack[-3];
    goto v_30828;
v_30829:
    v_30954 = elt(env, 4); // "rule list"
    goto v_30830;
v_30831:
    goto v_30827;
v_30828:
    goto v_30829;
v_30830:
    fn = elt(env, 11); // typerr
    v_30954 = (*qfn2(fn))(fn, v_30955, v_30954);
    env = stack[-4];
    goto v_30796;
v_30796:
    goto v_30791;
v_30793:
    goto v_30840;
v_30836:
    v_30954 = stack[-3];
    v_30955 = qcar(v_30954);
    goto v_30837;
v_30838:
    v_30954 = elt(env, 3); // list
    goto v_30839;
v_30840:
    goto v_30836;
v_30837:
    goto v_30838;
v_30839:
    if (v_30955 == v_30954) goto v_30834;
    else goto v_30835;
v_30834:
    goto v_30849;
v_30845:
    v_30954 = stack[-3];
    v_30955 = qcdr(v_30954);
    goto v_30846;
v_30847:
    v_30954 = stack[-2];
    v_30954 = qcdr(v_30954);
    goto v_30848;
v_30849:
    goto v_30845;
v_30846:
    goto v_30847;
v_30848:
    v_30954 = Lappend(nil, v_30955, v_30954);
    env = stack[-4];
    stack[-2] = v_30954;
    goto v_30763;
v_30835:
    goto v_30860;
v_30856:
    v_30954 = stack[-3];
    v_30955 = qcar(v_30954);
    goto v_30857;
v_30858:
    v_30954 = elt(env, 5); // equal
    goto v_30859;
v_30860:
    goto v_30856;
v_30857:
    goto v_30858;
v_30859:
    if (v_30955 == v_30954) goto v_30854;
    else goto v_30855;
v_30854:
    v_30954 = elt(env, 6); // "Please use => instead of = in rules"
    fn = elt(env, 12); // lprim
    v_30954 = (*qfn1(fn))(fn, v_30954);
    env = stack[-4];
    goto v_30791;
v_30855:
    goto v_30872;
v_30868:
    v_30954 = stack[-3];
    v_30955 = qcar(v_30954);
    goto v_30869;
v_30870:
    v_30954 = elt(env, 7); // replaceby
    goto v_30871;
v_30872:
    goto v_30868;
v_30869:
    goto v_30870;
v_30871:
    if (v_30955 == v_30954) goto v_30867;
    goto v_30881;
v_30877:
    v_30955 = stack[-3];
    goto v_30878;
v_30879:
    v_30954 = elt(env, 8); // "rule"
    goto v_30880;
v_30881:
    goto v_30877;
v_30878:
    goto v_30879;
v_30880:
    fn = elt(env, 11); // typerr
    v_30954 = (*qfn2(fn))(fn, v_30955, v_30954);
    env = stack[-4];
    goto v_30791;
v_30867:
v_30791:
    v_30954 = stack[-3];
    v_30954 = qcdr(v_30954);
    v_30954 = qcar(v_30954);
    fn = elt(env, 13); // remove!-free!-vars
    v_30954 = (*qfn1(fn))(fn, v_30954);
    env = stack[-4];
    stack[0] = v_30954;
    goto v_30897;
v_30893:
    v_30954 = stack[-3];
    v_30954 = qcdr(v_30954);
    v_30954 = qcdr(v_30954);
    v_30955 = qcar(v_30954);
    goto v_30894;
v_30895:
    v_30954 = elt(env, 9); // when
    goto v_30896;
v_30897:
    goto v_30893;
v_30894:
    goto v_30895;
v_30896:
    if (!consp(v_30955)) goto v_30891;
    v_30955 = qcar(v_30955);
    if (v_30955 == v_30954) goto v_30890;
    else goto v_30891;
v_30890:
    goto v_30910;
v_30904:
    v_30954 = stack[-3];
    v_30954 = qcdr(v_30954);
    v_30954 = qcdr(v_30954);
    v_30954 = qcar(v_30954);
    v_30954 = qcdr(v_30954);
    v_30954 = qcdr(v_30954);
    v_30954 = qcar(v_30954);
    fn = elt(env, 14); // remove!-free!-vars!*
    v_30956 = (*qfn1(fn))(fn, v_30954);
    env = stack[-4];
    goto v_30905;
v_30906:
    v_30955 = nil;
    goto v_30907;
v_30908:
    v_30954 = elt(env, 10); // algebraic
    goto v_30909;
v_30910:
    goto v_30904;
v_30905:
    goto v_30906;
v_30907:
    goto v_30908;
v_30909:
    fn = elt(env, 15); // formbool
    v_30954 = (*qfnn(fn))(fn, 3, v_30956, v_30955, v_30954);
    env = stack[-4];
    qvalue(elt(env, 2)) = v_30954; // mcond!*
    v_30954 = stack[-3];
    v_30954 = qcdr(v_30954);
    v_30954 = qcdr(v_30954);
    v_30954 = qcar(v_30954);
    v_30954 = qcdr(v_30954);
    v_30954 = qcar(v_30954);
    fn = elt(env, 14); // remove!-free!-vars!*
    v_30954 = (*qfn1(fn))(fn, v_30954);
    env = stack[-4];
    goto v_30889;
v_30891:
    v_30954 = stack[-3];
    v_30954 = qcdr(v_30954);
    v_30954 = qcdr(v_30954);
    v_30954 = qcar(v_30954);
    fn = elt(env, 14); // remove!-free!-vars!*
    v_30954 = (*qfn1(fn))(fn, v_30954);
    env = stack[-4];
    goto v_30889;
v_30889:
    goto v_30946;
v_30936:
    v_30958 = stack[0];
    goto v_30937;
v_30938:
    v_30957 = v_30954;
    goto v_30939;
v_30940:
    v_30956 = qvalue(elt(env, 1)); // frasc!*
    goto v_30941;
v_30942:
    v_30955 = qvalue(elt(env, 2)); // mcond!*
    goto v_30943;
v_30944:
    v_30954 = stack[-1];
    goto v_30945;
v_30946:
    goto v_30936;
v_30937:
    goto v_30938;
v_30939:
    goto v_30940;
v_30941:
    goto v_30942;
v_30943:
    goto v_30944;
v_30945:
    fn = elt(env, 16); // rule!*
    v_30954 = (*qfnn(fn))(fn, 5, v_30958, v_30957, v_30956, v_30955, v_30954);
    env = stack[-4];
    v_30954 = stack[-2];
    v_30954 = qcdr(v_30954);
    stack[-2] = v_30954;
    goto v_30763;
v_30762:
    return onevalue(v_30954);
}



// Code for even_action_pow

static LispObject CC_even_action_pow(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30919, v_30920, v_30921, v_30922;
    LispObject fn;
    LispObject v_30757, v_30756, v_30755, v_30754;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "even_action_pow");
    va_start(aa, nargs);
    v_30754 = va_arg(aa, LispObject);
    v_30755 = va_arg(aa, LispObject);
    v_30756 = va_arg(aa, LispObject);
    v_30757 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_30757,v_30756,v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_30754,v_30755,v_30756,v_30757);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_30757;
    stack[-3] = v_30756;
    stack[-4] = v_30755;
    v_30922 = v_30754;
// end of prologue
    v_30919 = stack[-4];
    v_30919 = qcar(v_30919);
    v_30921 = v_30919;
    v_30919 = stack[-4];
    v_30919 = qcdr(v_30919);
    stack[-1] = v_30919;
    goto v_30779;
v_30775:
    v_30920 = v_30921;
    goto v_30776;
v_30777:
    v_30919 = v_30922;
    goto v_30778;
v_30779:
    goto v_30775;
v_30776:
    goto v_30777;
v_30778:
    v_30919 = Lassoc(nil, v_30920, v_30919);
    stack[0] = v_30919;
    if (v_30919 == nil) goto v_30774;
    goto v_30791;
v_30787:
    v_30920 = stack[-1];
    goto v_30788;
v_30789:
    v_30919 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30790;
v_30791:
    goto v_30787;
v_30788:
    goto v_30789;
v_30790:
    if (v_30920 == v_30919) goto v_30785;
    else goto v_30786;
v_30785:
    goto v_30799;
v_30795:
    v_30920 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30796;
v_30797:
    v_30919 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30798;
v_30799:
    goto v_30795;
v_30796:
    goto v_30797;
v_30798:
    v_30919 = cons(v_30920, v_30919);
    env = stack[-6];
    goto v_30784;
v_30786:
    goto v_30811;
v_30805:
    goto v_30817;
v_30813:
    goto v_30823;
v_30819:
    stack[-4] = v_30921;
    goto v_30820;
v_30821:
    v_30919 = stack[-1];
    v_30919 = sub1(v_30919);
    env = stack[-6];
    goto v_30822;
v_30823:
    goto v_30819;
v_30820:
    goto v_30821;
v_30822:
    fn = elt(env, 1); // to
    v_30920 = (*qfn2(fn))(fn, stack[-4], v_30919);
    env = stack[-6];
    goto v_30814;
v_30815:
    v_30919 = stack[-1];
    goto v_30816;
v_30817:
    goto v_30813;
v_30814:
    goto v_30815;
v_30816:
    v_30921 = cons(v_30920, v_30919);
    env = stack[-6];
    goto v_30806;
v_30807:
    v_30920 = nil;
    goto v_30808;
v_30809:
    v_30919 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30810;
v_30811:
    goto v_30805;
v_30806:
    goto v_30807;
v_30808:
    goto v_30809;
v_30810:
    v_30919 = acons(v_30921, v_30920, v_30919);
    env = stack[-6];
    goto v_30784;
    v_30919 = nil;
v_30784:
    goto v_30837;
v_30831:
    v_30921 = stack[0];
    goto v_30832;
v_30833:
    v_30920 = stack[-3];
    goto v_30834;
v_30835:
    goto v_30836;
v_30837:
    goto v_30831;
v_30832:
    goto v_30833;
v_30834:
    goto v_30835;
v_30836:
    fn = elt(env, 2); // component_action
    v_30919 = (*qfnn(fn))(fn, 3, v_30921, v_30920, v_30919);
    env = stack[-6];
    stack[0] = v_30919;
    goto v_30846;
v_30842:
    v_30920 = stack[0];
    goto v_30843;
v_30844:
    v_30919 = stack[-2];
    goto v_30845;
v_30846:
    goto v_30842;
v_30843:
    goto v_30844;
v_30845:
    {
        fn = elt(env, 3); // multsq
        return (*qfn2(fn))(fn, v_30920, v_30919);
    }
v_30774:
    goto v_30856;
v_30850:
    v_30920 = v_30921;
    goto v_30851;
v_30852:
    v_30921 = v_30922;
    goto v_30853;
v_30854:
    v_30919 = nil;
    goto v_30855;
v_30856:
    goto v_30850;
v_30851:
    goto v_30852;
v_30853:
    goto v_30854;
v_30855:
    fn = elt(env, 4); // find_active_components
    v_30919 = (*qfnn(fn))(fn, 3, v_30920, v_30921, v_30919);
    env = stack[-6];
    stack[-1] = v_30919;
    goto v_30865;
v_30861:
    v_30920 = nil;
    goto v_30862;
v_30863:
    v_30919 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30864;
v_30865:
    goto v_30861;
v_30862:
    goto v_30863;
v_30864:
    v_30919 = cons(v_30920, v_30919);
    env = stack[-6];
    stack[0] = v_30919;
    v_30919 = stack[-1];
    stack[-5] = v_30919;
v_30871:
    v_30919 = stack[-5];
    if (v_30919 == nil) goto v_30875;
    else goto v_30876;
v_30875:
    goto v_30870;
v_30876:
    v_30919 = stack[-5];
    v_30919 = qcar(v_30919);
    stack[-1] = v_30919;
    goto v_30887;
v_30883:
    v_30920 = stack[-4];
    goto v_30884;
v_30885:
    v_30919 = stack[-1];
    v_30919 = qcar(v_30919);
    goto v_30886;
v_30887:
    goto v_30883;
v_30884:
    goto v_30885;
v_30886:
    fn = elt(env, 5); // diffp
    v_30919 = (*qfn2(fn))(fn, v_30920, v_30919);
    env = stack[-6];
    goto v_30896;
v_30892:
    goto v_30893;
v_30894:
    goto v_30905;
v_30899:
    v_30921 = stack[-1];
    goto v_30900;
v_30901:
    v_30920 = stack[-3];
    goto v_30902;
v_30903:
    goto v_30904;
v_30905:
    goto v_30899;
v_30900:
    goto v_30901;
v_30902:
    goto v_30903;
v_30904:
    fn = elt(env, 2); // component_action
    v_30919 = (*qfnn(fn))(fn, 3, v_30921, v_30920, v_30919);
    env = stack[-6];
    goto v_30895;
v_30896:
    goto v_30892;
v_30893:
    goto v_30894;
v_30895:
    fn = elt(env, 6); // addsq
    v_30919 = (*qfn2(fn))(fn, stack[0], v_30919);
    env = stack[-6];
    stack[0] = v_30919;
    v_30919 = stack[-5];
    v_30919 = qcdr(v_30919);
    stack[-5] = v_30919;
    goto v_30871;
v_30870:
    goto v_30916;
v_30912:
    v_30920 = stack[0];
    goto v_30913;
v_30914:
    v_30919 = stack[-2];
    goto v_30915;
v_30916:
    goto v_30912;
v_30913:
    goto v_30914;
v_30915:
    {
        fn = elt(env, 3); // multsq
        return (*qfn2(fn))(fn, v_30920, v_30919);
    }
    return onevalue(v_30919);
}



// Code for ofsf_canegrel

static LispObject CC_ofsf_canegrel(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30767, v_30768;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30767 = v_30755;
    v_30768 = v_30754;
// end of prologue
    if (v_30767 == nil) goto v_30760;
    v_30767 = v_30768;
    goto v_30758;
v_30760:
    v_30767 = v_30768;
    {
        fn = elt(env, 1); // ofsf_anegrel
        return (*qfn1(fn))(fn, v_30767);
    }
    v_30767 = nil;
v_30758:
    return onevalue(v_30767);
}



// Code for !*multsq

static LispObject CC_Hmultsq(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30960, v_30961;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_30755;
    stack[-3] = v_30754;
// end of prologue
    v_30960 = stack[-3];
    v_30960 = qcar(v_30960);
    if (v_30960 == nil) goto v_30763;
    else goto v_30764;
v_30763:
    v_30960 = lisp_true;
    goto v_30762;
v_30764:
    v_30960 = stack[-2];
    v_30960 = qcar(v_30960);
    v_30960 = (v_30960 == nil ? lisp_true : nil);
    goto v_30762;
    v_30960 = nil;
v_30762:
    if (v_30960 == nil) goto v_30760;
    goto v_30778;
v_30774:
    v_30961 = nil;
    goto v_30775;
v_30776:
    v_30960 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30777;
v_30778:
    goto v_30774;
v_30775:
    goto v_30776;
v_30777:
    return cons(v_30961, v_30960);
v_30760:
    goto v_30791;
v_30787:
    v_30960 = stack[-3];
    v_30961 = qcdr(v_30960);
    goto v_30788;
v_30789:
    v_30960 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30790;
v_30791:
    goto v_30787;
v_30788:
    goto v_30789;
v_30790:
    if (v_30961 == v_30960) goto v_30785;
    else goto v_30786;
v_30785:
    goto v_30799;
v_30795:
    v_30960 = stack[-2];
    v_30961 = qcdr(v_30960);
    goto v_30796;
v_30797:
    v_30960 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30798;
v_30799:
    goto v_30795;
v_30796:
    goto v_30797;
v_30798:
    v_30960 = (v_30961 == v_30960 ? lisp_true : nil);
    goto v_30784;
v_30786:
    v_30960 = nil;
    goto v_30784;
    v_30960 = nil;
v_30784:
    if (v_30960 == nil) goto v_30782;
    goto v_30812;
v_30808:
    goto v_30818;
v_30814:
    v_30960 = stack[-3];
    v_30961 = qcar(v_30960);
    goto v_30815;
v_30816:
    v_30960 = stack[-2];
    v_30960 = qcar(v_30960);
    goto v_30817;
v_30818:
    goto v_30814;
v_30815:
    goto v_30816;
v_30817:
    fn = elt(env, 1); // !*multf
    v_30961 = (*qfn2(fn))(fn, v_30961, v_30960);
    goto v_30809;
v_30810:
    v_30960 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30811;
v_30812:
    goto v_30808;
v_30809:
    goto v_30810;
v_30811:
    return cons(v_30961, v_30960);
v_30782:
    goto v_30836;
v_30832:
    v_30960 = stack[-3];
    v_30961 = qcar(v_30960);
    goto v_30833;
v_30834:
    v_30960 = stack[-2];
    v_30960 = qcdr(v_30960);
    goto v_30835;
v_30836:
    goto v_30832;
v_30833:
    goto v_30834;
v_30835:
    fn = elt(env, 2); // gcdf
    v_30960 = (*qfn2(fn))(fn, v_30961, v_30960);
    env = stack[-5];
    stack[-4] = v_30960;
    goto v_30846;
v_30842:
    v_30960 = stack[-2];
    v_30961 = qcar(v_30960);
    goto v_30843;
v_30844:
    v_30960 = stack[-3];
    v_30960 = qcdr(v_30960);
    goto v_30845;
v_30846:
    goto v_30842;
v_30843:
    goto v_30844;
v_30845:
    fn = elt(env, 2); // gcdf
    v_30960 = (*qfn2(fn))(fn, v_30961, v_30960);
    env = stack[-5];
    stack[-1] = v_30960;
    goto v_30856;
v_30852:
    goto v_30862;
v_30858:
    v_30960 = stack[-3];
    v_30961 = qcar(v_30960);
    goto v_30859;
v_30860:
    v_30960 = stack[-4];
    goto v_30861;
v_30862:
    goto v_30858;
v_30859:
    goto v_30860;
v_30861:
    fn = elt(env, 3); // quotf!-fail
    stack[0] = (*qfn2(fn))(fn, v_30961, v_30960);
    env = stack[-5];
    goto v_30853;
v_30854:
    goto v_30871;
v_30867:
    v_30960 = stack[-2];
    v_30961 = qcar(v_30960);
    goto v_30868;
v_30869:
    v_30960 = stack[-1];
    goto v_30870;
v_30871:
    goto v_30867;
v_30868:
    goto v_30869;
v_30870:
    fn = elt(env, 3); // quotf!-fail
    v_30960 = (*qfn2(fn))(fn, v_30961, v_30960);
    env = stack[-5];
    goto v_30855;
v_30856:
    goto v_30852;
v_30853:
    goto v_30854;
v_30855:
    fn = elt(env, 1); // !*multf
    v_30960 = (*qfn2(fn))(fn, stack[0], v_30960);
    env = stack[-5];
    stack[0] = v_30960;
    goto v_30880;
v_30876:
    goto v_30886;
v_30882:
    v_30960 = stack[-3];
    v_30961 = qcdr(v_30960);
    goto v_30883;
v_30884:
    v_30960 = stack[-1];
    goto v_30885;
v_30886:
    goto v_30882;
v_30883:
    goto v_30884;
v_30885:
    fn = elt(env, 3); // quotf!-fail
    stack[-1] = (*qfn2(fn))(fn, v_30961, v_30960);
    env = stack[-5];
    goto v_30877;
v_30878:
    goto v_30895;
v_30891:
    v_30960 = stack[-2];
    v_30961 = qcdr(v_30960);
    goto v_30892;
v_30893:
    v_30960 = stack[-4];
    goto v_30894;
v_30895:
    goto v_30891;
v_30892:
    goto v_30893;
v_30894:
    fn = elt(env, 3); // quotf!-fail
    v_30960 = (*qfn2(fn))(fn, v_30961, v_30960);
    env = stack[-5];
    goto v_30879;
v_30880:
    goto v_30876;
v_30877:
    goto v_30878;
v_30879:
    fn = elt(env, 1); // !*multf
    v_30960 = (*qfn2(fn))(fn, stack[-1], v_30960);
    env = stack[-5];
    stack[-4] = v_30960;
    v_30960 = stack[-4];
    fn = elt(env, 4); // minusf
    v_30960 = (*qfn1(fn))(fn, v_30960);
    env = stack[-5];
    if (v_30960 == nil) goto v_30902;
    v_30960 = stack[0];
    fn = elt(env, 5); // negf
    v_30960 = (*qfn1(fn))(fn, v_30960);
    env = stack[-5];
    stack[0] = v_30960;
    v_30960 = stack[-4];
    fn = elt(env, 5); // negf
    v_30960 = (*qfn1(fn))(fn, v_30960);
    env = stack[-5];
    stack[-4] = v_30960;
    goto v_30900;
v_30902:
v_30900:
    goto v_30914;
v_30910:
    v_30961 = stack[0];
    goto v_30911;
v_30912:
    v_30960 = stack[-4];
    goto v_30913;
v_30914:
    goto v_30910;
v_30911:
    goto v_30912;
v_30913:
    fn = elt(env, 2); // gcdf
    v_30960 = (*qfn2(fn))(fn, v_30961, v_30960);
    env = stack[-5];
    stack[-1] = v_30960;
    goto v_30925;
v_30921:
    v_30961 = stack[-1];
    goto v_30922;
v_30923:
    v_30960 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30924;
v_30925:
    goto v_30921;
v_30922:
    goto v_30923;
v_30924:
    if (v_30961 == v_30960) goto v_30919;
    else goto v_30920;
v_30919:
    goto v_30933;
v_30929:
    v_30961 = stack[0];
    goto v_30930;
v_30931:
    v_30960 = stack[-4];
    goto v_30932;
v_30933:
    goto v_30929;
v_30930:
    goto v_30931;
v_30932:
    return cons(v_30961, v_30960);
v_30920:
    goto v_30943;
v_30939:
    goto v_30949;
v_30945:
    v_30961 = stack[0];
    goto v_30946;
v_30947:
    v_30960 = stack[-1];
    goto v_30948;
v_30949:
    goto v_30945;
v_30946:
    goto v_30947;
v_30948:
    fn = elt(env, 3); // quotf!-fail
    stack[0] = (*qfn2(fn))(fn, v_30961, v_30960);
    env = stack[-5];
    goto v_30940;
v_30941:
    goto v_30957;
v_30953:
    v_30961 = stack[-4];
    goto v_30954;
v_30955:
    v_30960 = stack[-1];
    goto v_30956;
v_30957:
    goto v_30953;
v_30954:
    goto v_30955;
v_30956:
    fn = elt(env, 3); // quotf!-fail
    v_30960 = (*qfn2(fn))(fn, v_30961, v_30960);
    goto v_30942;
v_30943:
    goto v_30939;
v_30940:
    goto v_30941;
v_30942:
    {
        LispObject v_30967 = stack[0];
        return cons(v_30967, v_30960);
    }
    v_30960 = nil;
    goto v_30758;
    v_30960 = nil;
v_30758:
    return onevalue(v_30960);
}



// Code for taymindegreel

static LispObject CC_taymindegreel(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30816, v_30817;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_30755;
    stack[-2] = v_30754;
// end of prologue
    stack[-3] = nil;
v_30760:
    v_30816 = stack[-2];
    if (v_30816 == nil) goto v_30763;
    else goto v_30764;
v_30763:
    v_30816 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_30816);
    }
v_30764:
    goto v_30775;
v_30771:
    goto v_30781;
v_30777:
    v_30816 = stack[-2];
    v_30816 = qcar(v_30816);
    stack[0] = v_30816;
    v_30816 = (LispObject)0+TAG_FIXNUM; // 0
    v_30817 = v_30816;
v_30786:
    v_30816 = stack[0];
    if (v_30816 == nil) goto v_30792;
    else goto v_30793;
v_30792:
    v_30816 = v_30817;
    v_30817 = v_30816;
    goto v_30785;
v_30793:
    goto v_30801;
v_30797:
    v_30816 = stack[0];
    v_30816 = qcar(v_30816);
    goto v_30798;
v_30799:
    goto v_30800;
v_30801:
    goto v_30797;
v_30798:
    goto v_30799;
v_30800:
    fn = elt(env, 2); // tayexp!-plus2
    v_30816 = (*qfn2(fn))(fn, v_30816, v_30817);
    env = stack[-4];
    v_30817 = v_30816;
    v_30816 = stack[0];
    v_30816 = qcdr(v_30816);
    stack[0] = v_30816;
    goto v_30786;
v_30785:
    goto v_30778;
v_30779:
    v_30816 = stack[-1];
    v_30816 = qcar(v_30816);
    goto v_30780;
v_30781:
    goto v_30777;
v_30778:
    goto v_30779;
v_30780:
    fn = elt(env, 3); // tayexp!-min2
    v_30817 = (*qfn2(fn))(fn, v_30817, v_30816);
    env = stack[-4];
    goto v_30772;
v_30773:
    v_30816 = stack[-3];
    goto v_30774;
v_30775:
    goto v_30771;
v_30772:
    goto v_30773;
v_30774:
    v_30816 = cons(v_30817, v_30816);
    env = stack[-4];
    stack[-3] = v_30816;
    v_30816 = stack[-2];
    v_30816 = qcdr(v_30816);
    stack[-2] = v_30816;
    v_30816 = stack[-1];
    v_30816 = qcdr(v_30816);
    stack[-1] = v_30816;
    goto v_30760;
    v_30816 = nil;
    return onevalue(v_30816);
}



// Code for qqe_length!-graph!-marked

static LispObject CC_qqe_lengthKgraphKmarked(LispObject env,
                         LispObject v_30754)
{
    env = qenv(env);
    LispObject v_30764, v_30765;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30764 = v_30754;
// end of prologue
    goto v_30761;
v_30757:
    goto v_30758;
v_30759:
    v_30765 = elt(env, 1); // blockmark
    goto v_30760;
v_30761:
    goto v_30757;
v_30758:
    goto v_30759;
v_30760:
    return get(v_30764, v_30765);
}



// Code for cl_susimkatl

static LispObject CC_cl_susimkatl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_31028, v_31029, v_31030;
    LispObject fn;
    LispObject v_30757, v_30756, v_30755, v_30754;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_susimkatl");
    va_start(aa, nargs);
    v_30754 = va_arg(aa, LispObject);
    v_30755 = va_arg(aa, LispObject);
    v_30756 = va_arg(aa, LispObject);
    v_30757 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_30757,v_30756,v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_30754,v_30755,v_30756,v_30757);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_30757;
    v_31028 = v_30756;
    stack[-4] = v_30755;
    stack[-5] = v_30754;
// end of prologue
    stack[-6] = v_31028;
v_30767:
    v_31028 = stack[-6];
    if (v_31028 == nil) goto v_30772;
    else goto v_30773;
v_30772:
    v_31028 = nil;
    goto v_30766;
v_30773:
    v_31028 = stack[-6];
    v_31028 = qcar(v_31028);
    v_31030 = v_31028;
    goto v_30787;
v_30783:
    v_31028 = v_31030;
    v_31029 = qcdr(v_31028);
    goto v_30784;
v_30785:
    v_31028 = stack[-3];
    goto v_30786;
v_30787:
    goto v_30783;
v_30784:
    goto v_30785;
v_30786:
    if (equal(v_31029, v_31028)) goto v_30781;
    else goto v_30782;
v_30781:
    v_31028 = v_31030;
    v_31028 = qcar(v_31028);
    v_31028 = ncons(v_31028);
    env = stack[-7];
    goto v_30780;
v_30782:
    v_31028 = nil;
v_30780:
    stack[-2] = v_31028;
    v_31028 = stack[-2];
    fn = elt(env, 6); // lastpair
    v_31028 = (*qfn1(fn))(fn, v_31028);
    env = stack[-7];
    stack[-1] = v_31028;
    v_31028 = stack[-6];
    v_31028 = qcdr(v_31028);
    stack[-6] = v_31028;
    v_31028 = stack[-1];
    if (!consp(v_31028)) goto v_30800;
    else goto v_30801;
v_30800:
    goto v_30767;
v_30801:
v_30768:
    v_31028 = stack[-6];
    if (v_31028 == nil) goto v_30805;
    else goto v_30806;
v_30805:
    v_31028 = stack[-2];
    goto v_30766;
v_30806:
    goto v_30814;
v_30810:
    stack[0] = stack[-1];
    goto v_30811;
v_30812:
    v_31028 = stack[-6];
    v_31028 = qcar(v_31028);
    v_31030 = v_31028;
    goto v_30827;
v_30823:
    v_31028 = v_31030;
    v_31029 = qcdr(v_31028);
    goto v_30824;
v_30825:
    v_31028 = stack[-3];
    goto v_30826;
v_30827:
    goto v_30823;
v_30824:
    goto v_30825;
v_30826:
    if (equal(v_31029, v_31028)) goto v_30821;
    else goto v_30822;
v_30821:
    v_31028 = v_31030;
    v_31028 = qcar(v_31028);
    v_31028 = ncons(v_31028);
    env = stack[-7];
    goto v_30820;
v_30822:
    v_31028 = nil;
v_30820:
    goto v_30813;
v_30814:
    goto v_30810;
v_30811:
    goto v_30812;
v_30813:
    v_31028 = Lrplacd(nil, stack[0], v_31028);
    env = stack[-7];
    v_31028 = stack[-1];
    fn = elt(env, 6); // lastpair
    v_31028 = (*qfn1(fn))(fn, v_31028);
    env = stack[-7];
    stack[-1] = v_31028;
    v_31028 = stack[-6];
    v_31028 = qcdr(v_31028);
    stack[-6] = v_31028;
    goto v_30768;
v_30766:
    v_31030 = v_31028;
    v_31028 = v_31030;
    if (v_31028 == nil) goto v_30840;
    else goto v_30841;
v_30840:
    v_31028 = nil;
    goto v_30761;
v_30841:
    goto v_30849;
v_30845:
    v_31029 = v_31030;
    goto v_30846;
v_30847:
    v_31028 = stack[-4];
    goto v_30848;
v_30849:
    goto v_30845;
v_30846:
    goto v_30847;
v_30848:
    fn = elt(env, 7); // rl_susipost
    v_31028 = (*qfn2(fn))(fn, v_31029, v_31028);
    env = stack[-7];
    v_31030 = v_31028;
    goto v_30864;
v_30860:
    v_31029 = v_31030;
    goto v_30861;
v_30862:
    v_31028 = elt(env, 1); // true
    goto v_30863;
v_30864:
    goto v_30860;
v_30861:
    goto v_30862;
v_30863:
    if (v_31029 == v_31028) goto v_30858;
    else goto v_30859;
v_30858:
    v_31028 = lisp_true;
    goto v_30857;
v_30859:
    goto v_30874;
v_30870:
    v_31029 = v_31030;
    goto v_30871;
v_30872:
    v_31028 = elt(env, 2); // false
    goto v_30873;
v_30874:
    goto v_30870;
v_30871:
    goto v_30872;
v_30873:
    v_31028 = (v_31029 == v_31028 ? lisp_true : nil);
    goto v_30857;
    v_31028 = nil;
v_30857:
    if (v_31028 == nil) goto v_30855;
    goto v_30884;
v_30880:
    goto v_30881;
v_30882:
    goto v_30890;
v_30886:
    v_31029 = stack[-5];
    goto v_30887;
v_30888:
    v_31028 = elt(env, 3); // and
    goto v_30889;
v_30890:
    goto v_30886;
v_30887:
    goto v_30888;
v_30889:
    v_31028 = (v_31029 == v_31028 ? lisp_true : nil);
    goto v_30883;
v_30884:
    goto v_30880;
v_30881:
    goto v_30882;
v_30883:
    fn = elt(env, 8); // cl_cflip
    v_31028 = (*qfn2(fn))(fn, v_31030, v_31028);
    return ncons(v_31028);
v_30855:
    goto v_30902;
v_30898:
    v_31029 = v_31030;
    goto v_30899;
v_30900:
    v_31028 = elt(env, 4); // inctheo
    goto v_30901;
v_30902:
    goto v_30898;
v_30899:
    goto v_30900;
v_30901:
    if (v_31029 == v_31028) goto v_30896;
    else goto v_30897;
v_30896:
    goto v_30910;
v_30906:
    v_31030 = elt(env, 2); // false
    goto v_30907;
v_30908:
    goto v_30916;
v_30912:
    v_31029 = stack[-5];
    goto v_30913;
v_30914:
    v_31028 = elt(env, 3); // and
    goto v_30915;
v_30916:
    goto v_30912;
v_30913:
    goto v_30914;
v_30915:
    v_31028 = (v_31029 == v_31028 ? lisp_true : nil);
    goto v_30909;
v_30910:
    goto v_30906;
v_30907:
    goto v_30908;
v_30909:
    {
        fn = elt(env, 8); // cl_cflip
        return (*qfn2(fn))(fn, v_31030, v_31028);
    }
v_30897:
    goto v_30928;
v_30924:
    v_31029 = stack[-5];
    goto v_30925;
v_30926:
    v_31028 = elt(env, 5); // or
    goto v_30927;
v_30928:
    goto v_30924;
v_30925:
    goto v_30926;
v_30927:
    if (v_31029 == v_31028) goto v_30922;
    else goto v_30923;
v_30922:
    v_31028 = v_31030;
    stack[-3] = v_31028;
    v_31028 = stack[-3];
    if (v_31028 == nil) goto v_30940;
    else goto v_30941;
v_30940:
    v_31028 = nil;
    goto v_30935;
v_30941:
    v_31028 = stack[-3];
    v_31028 = qcar(v_31028);
    fn = elt(env, 9); // rl_negateat
    v_31028 = (*qfn1(fn))(fn, v_31028);
    env = stack[-7];
    v_31028 = ncons(v_31028);
    env = stack[-7];
    stack[-1] = v_31028;
    stack[-2] = v_31028;
v_30936:
    v_31028 = stack[-3];
    v_31028 = qcdr(v_31028);
    stack[-3] = v_31028;
    v_31028 = stack[-3];
    if (v_31028 == nil) goto v_30954;
    else goto v_30955;
v_30954:
    v_31028 = stack[-2];
    goto v_30935;
v_30955:
    goto v_30963;
v_30959:
    stack[0] = stack[-1];
    goto v_30960;
v_30961:
    v_31028 = stack[-3];
    v_31028 = qcar(v_31028);
    fn = elt(env, 9); // rl_negateat
    v_31028 = (*qfn1(fn))(fn, v_31028);
    env = stack[-7];
    v_31028 = ncons(v_31028);
    env = stack[-7];
    goto v_30962;
v_30963:
    goto v_30959;
v_30960:
    goto v_30961;
v_30962:
    v_31028 = Lrplacd(nil, stack[0], v_31028);
    env = stack[-7];
    v_31028 = stack[-1];
    v_31028 = qcdr(v_31028);
    stack[-1] = v_31028;
    goto v_30936;
v_30935:
    v_31030 = v_31028;
    goto v_30921;
v_30923:
v_30921:
    v_31028 = v_31030;
    stack[-3] = v_31028;
    v_31028 = stack[-3];
    if (v_31028 == nil) goto v_30982;
    else goto v_30983;
v_30982:
    v_31028 = nil;
    goto v_30977;
v_30983:
    v_31028 = stack[-3];
    v_31028 = qcar(v_31028);
    goto v_30995;
v_30991:
    v_31029 = v_31028;
    goto v_30992;
v_30993:
    v_31028 = stack[-4];
    goto v_30994;
v_30995:
    goto v_30991;
v_30992:
    goto v_30993;
v_30994:
    fn = elt(env, 10); // rl_susitf
    v_31028 = (*qfn2(fn))(fn, v_31029, v_31028);
    env = stack[-7];
    v_31028 = ncons(v_31028);
    env = stack[-7];
    stack[-1] = v_31028;
    stack[-2] = v_31028;
v_30978:
    v_31028 = stack[-3];
    v_31028 = qcdr(v_31028);
    stack[-3] = v_31028;
    v_31028 = stack[-3];
    if (v_31028 == nil) goto v_31002;
    else goto v_31003;
v_31002:
    v_31028 = stack[-2];
    goto v_30977;
v_31003:
    goto v_31011;
v_31007:
    stack[0] = stack[-1];
    goto v_31008;
v_31009:
    v_31028 = stack[-3];
    v_31028 = qcar(v_31028);
    goto v_31022;
v_31018:
    v_31029 = v_31028;
    goto v_31019;
v_31020:
    v_31028 = stack[-4];
    goto v_31021;
v_31022:
    goto v_31018;
v_31019:
    goto v_31020;
v_31021:
    fn = elt(env, 10); // rl_susitf
    v_31028 = (*qfn2(fn))(fn, v_31029, v_31028);
    env = stack[-7];
    v_31028 = ncons(v_31028);
    env = stack[-7];
    goto v_31010;
v_31011:
    goto v_31007;
v_31008:
    goto v_31009;
v_31010:
    v_31028 = Lrplacd(nil, stack[0], v_31028);
    env = stack[-7];
    v_31028 = stack[-1];
    v_31028 = qcdr(v_31028);
    stack[-1] = v_31028;
    goto v_30978;
v_30977:
    v_31030 = v_31028;
    v_31028 = v_31030;
v_30761:
    return onevalue(v_31028);
}



// Code for ofsf_boundchk

static LispObject CC_ofsf_boundchk(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30919, v_30920, v_30921;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_30755;
    stack[-2] = v_30754;
// end of prologue
    v_30919 = stack[-1];
    v_30919 = ncons(v_30919);
    env = stack[-4];
    fn = elt(env, 7); // setkorder
    v_30919 = (*qfn1(fn))(fn, v_30919);
    env = stack[-4];
    stack[0] = v_30919;
    v_30919 = stack[-2];
    v_30919 = qcdr(v_30919);
    v_30919 = qcar(v_30919);
    fn = elt(env, 8); // reorder
    v_30919 = (*qfn1(fn))(fn, v_30919);
    env = stack[-4];
    stack[-3] = v_30919;
    v_30919 = stack[0];
    fn = elt(env, 7); // setkorder
    v_30919 = (*qfn1(fn))(fn, v_30919);
    env = stack[-4];
    v_30919 = stack[-3];
    if (!consp(v_30919)) goto v_30782;
    else goto v_30783;
v_30782:
    v_30919 = lisp_true;
    goto v_30781;
v_30783:
    v_30919 = stack[-3];
    v_30919 = qcar(v_30919);
    v_30919 = (consp(v_30919) ? nil : lisp_true);
    goto v_30781;
    v_30919 = nil;
v_30781:
    if (v_30919 == nil) goto v_30779;
    v_30919 = lisp_true;
    goto v_30777;
v_30779:
    goto v_30799;
v_30795:
    v_30919 = stack[-3];
    v_30919 = qcar(v_30919);
    v_30919 = qcar(v_30919);
    v_30920 = qcar(v_30919);
    goto v_30796;
v_30797:
    v_30919 = stack[-1];
    goto v_30798;
v_30799:
    goto v_30795;
v_30796:
    goto v_30797;
v_30798:
    v_30919 = Lneq(nil, v_30920, v_30919);
    env = stack[-4];
    goto v_30777;
    v_30919 = nil;
v_30777:
    if (v_30919 == nil) goto v_30775;
    v_30919 = nil;
    goto v_30762;
v_30775:
    goto v_30814;
v_30810:
    v_30919 = stack[-3];
    v_30919 = qcar(v_30919);
    v_30919 = qcar(v_30919);
    v_30920 = qcdr(v_30919);
    goto v_30811;
v_30812:
    v_30919 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30813;
v_30814:
    goto v_30810;
v_30811:
    goto v_30812;
v_30813:
    if (v_30920 == v_30919) goto v_30809;
    goto v_30828;
v_30822:
    v_30921 = elt(env, 1); // "ofsf_boundchk:"
    goto v_30823;
v_30824:
    v_30920 = stack[-1];
    goto v_30825;
v_30826:
    v_30919 = elt(env, 2); // "not linear"
    goto v_30827;
v_30828:
    goto v_30822;
v_30823:
    goto v_30824;
v_30825:
    goto v_30826;
v_30827:
    v_30919 = list3(v_30921, v_30920, v_30919);
    env = stack[-4];
    fn = elt(env, 9); // rederr
    v_30919 = (*qfn1(fn))(fn, v_30919);
    env = stack[-4];
    goto v_30807;
v_30809:
v_30807:
    goto v_30837;
v_30833:
    goto v_30843;
v_30839:
    v_30919 = stack[-3];
    v_30919 = qcdr(v_30919);
    fn = elt(env, 8); // reorder
    v_30919 = (*qfn1(fn))(fn, v_30919);
    env = stack[-4];
    fn = elt(env, 10); // negf
    v_30920 = (*qfn1(fn))(fn, v_30919);
    env = stack[-4];
    goto v_30840;
v_30841:
    v_30919 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30842;
v_30843:
    goto v_30839;
v_30840:
    goto v_30841;
v_30842:
    stack[0] = cons(v_30920, v_30919);
    env = stack[-4];
    goto v_30834;
v_30835:
    goto v_30854;
v_30850:
    v_30919 = stack[-3];
    v_30919 = qcar(v_30919);
    v_30919 = qcdr(v_30919);
    fn = elt(env, 8); // reorder
    v_30920 = (*qfn1(fn))(fn, v_30919);
    env = stack[-4];
    goto v_30851;
v_30852:
    v_30919 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30853;
v_30854:
    goto v_30850;
v_30851:
    goto v_30852;
v_30853:
    v_30919 = cons(v_30920, v_30919);
    env = stack[-4];
    goto v_30836;
v_30837:
    goto v_30833;
v_30834:
    goto v_30835;
v_30836:
    fn = elt(env, 11); // quotsq
    v_30919 = (*qfn2(fn))(fn, stack[0], v_30919);
    env = stack[-4];
    stack[0] = v_30919;
    v_30919 = stack[-2];
    v_30919 = qcar(v_30919);
    v_30921 = v_30919;
    goto v_30870;
v_30866:
    v_30920 = v_30921;
    goto v_30867;
v_30868:
    v_30919 = elt(env, 3); // equal
    goto v_30869;
v_30870:
    goto v_30866;
v_30867:
    goto v_30868;
v_30869:
    if (v_30920 == v_30919) goto v_30864;
    else goto v_30865;
v_30864:
    goto v_30878;
v_30874:
    v_30920 = elt(env, 3); // equal
    goto v_30875;
v_30876:
    v_30919 = stack[0];
    goto v_30877;
v_30878:
    goto v_30874;
v_30875:
    goto v_30876;
v_30877:
    return cons(v_30920, v_30919);
v_30865:
    goto v_30890;
v_30886:
    goto v_30895;
v_30891:
    v_30920 = v_30921;
    goto v_30892;
v_30893:
    v_30919 = elt(env, 4); // geq
    goto v_30894;
v_30895:
    goto v_30891;
v_30892:
    goto v_30893;
v_30894:
    stack[-1] = (v_30920 == v_30919 ? lisp_true : nil);
    goto v_30887;
v_30888:
    v_30919 = stack[-3];
    v_30919 = qcar(v_30919);
    v_30919 = qcdr(v_30919);
    fn = elt(env, 12); // minusf
    v_30919 = (*qfn1(fn))(fn, v_30919);
    env = stack[-4];
    goto v_30889;
v_30890:
    goto v_30886;
v_30887:
    goto v_30888;
v_30889:
    fn = elt(env, 13); // ofsf_xor
    v_30919 = (*qfn2(fn))(fn, stack[-1], v_30919);
    env = stack[-4];
    if (v_30919 == nil) goto v_30884;
    goto v_30908;
v_30904:
    v_30920 = elt(env, 5); // lb
    goto v_30905;
v_30906:
    v_30919 = stack[0];
    goto v_30907;
v_30908:
    goto v_30904;
v_30905:
    goto v_30906;
v_30907:
    return cons(v_30920, v_30919);
v_30884:
    goto v_30916;
v_30912:
    v_30920 = elt(env, 6); // ub
    goto v_30913;
v_30914:
    v_30919 = stack[0];
    goto v_30915;
v_30916:
    goto v_30912;
v_30913:
    goto v_30914;
v_30915:
    return cons(v_30920, v_30919);
v_30762:
    return onevalue(v_30919);
}



// Code for latexprint

static LispObject CC_latexprint(LispObject env,
                         LispObject v_30754)
{
    env = qenv(env);
    LispObject v_30760;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30754);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_30754;
// end of prologue
    fn = elt(env, 1); // prinlabegin
    v_30760 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_30760 = stack[0];
    fn = elt(env, 2); // latexprin
    v_30760 = (*qfn1(fn))(fn, v_30760);
    env = stack[-1];
    {
        fn = elt(env, 3); // prinlaend
        return (*qfnn(fn))(fn, 0);
    }
}



// Code for gbftimes

static LispObject CC_gbftimes(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30821, v_30822, v_30823;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_30822 = v_30755;
    v_30823 = v_30754;
// end of prologue
    v_30821 = v_30823;
    v_30821 = qcar(v_30821);
    stack[-4] = v_30821;
    v_30821 = v_30823;
    v_30821 = qcdr(v_30821);
    stack[-3] = v_30821;
    v_30821 = v_30822;
    v_30821 = qcar(v_30821);
    stack[-2] = v_30821;
    v_30821 = v_30822;
    v_30821 = qcdr(v_30821);
    stack[-1] = v_30821;
    goto v_30776;
v_30772:
    goto v_30782;
v_30778:
    goto v_30788;
v_30784:
    v_30822 = stack[-4];
    goto v_30785;
v_30786:
    v_30821 = stack[-2];
    goto v_30787;
v_30788:
    goto v_30784;
v_30785:
    goto v_30786;
v_30787:
    fn = elt(env, 1); // csl_timbf
    stack[0] = (*qfn2(fn))(fn, v_30822, v_30821);
    env = stack[-5];
    goto v_30779;
v_30780:
    goto v_30796;
v_30792:
    v_30822 = stack[-3];
    goto v_30793;
v_30794:
    v_30821 = stack[-1];
    goto v_30795;
v_30796:
    goto v_30792;
v_30793:
    goto v_30794;
v_30795:
    fn = elt(env, 1); // csl_timbf
    v_30821 = (*qfn2(fn))(fn, v_30822, v_30821);
    env = stack[-5];
    goto v_30781;
v_30782:
    goto v_30778;
v_30779:
    goto v_30780;
v_30781:
    fn = elt(env, 2); // difbf
    stack[0] = (*qfn2(fn))(fn, stack[0], v_30821);
    env = stack[-5];
    goto v_30773;
v_30774:
    goto v_30804;
v_30800:
    goto v_30810;
v_30806:
    v_30822 = stack[-4];
    goto v_30807;
v_30808:
    v_30821 = stack[-1];
    goto v_30809;
v_30810:
    goto v_30806;
v_30807:
    goto v_30808;
v_30809:
    fn = elt(env, 1); // csl_timbf
    stack[-1] = (*qfn2(fn))(fn, v_30822, v_30821);
    env = stack[-5];
    goto v_30801;
v_30802:
    goto v_30818;
v_30814:
    v_30822 = stack[-3];
    goto v_30815;
v_30816:
    v_30821 = stack[-2];
    goto v_30817;
v_30818:
    goto v_30814;
v_30815:
    goto v_30816;
v_30817:
    fn = elt(env, 1); // csl_timbf
    v_30821 = (*qfn2(fn))(fn, v_30822, v_30821);
    env = stack[-5];
    goto v_30803;
v_30804:
    goto v_30800;
v_30801:
    goto v_30802;
v_30803:
    fn = elt(env, 3); // plubf
    v_30821 = (*qfn2(fn))(fn, stack[-1], v_30821);
    goto v_30775;
v_30776:
    goto v_30772;
v_30773:
    goto v_30774;
v_30775:
    {
        LispObject v_30829 = stack[0];
        return cons(v_30829, v_30821);
    }
    return onevalue(v_30821);
}



// Code for is_buble

static LispObject CC_is_buble(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30801, v_30802;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30755;
    stack[-1] = v_30754;
// end of prologue
    goto v_30763;
v_30759:
    v_30802 = stack[-1];
    goto v_30760;
v_30761:
    v_30801 = stack[0];
    goto v_30762;
v_30763:
    goto v_30759;
v_30760:
    goto v_30761;
v_30762:
    fn = elt(env, 1); // diff_vertex
    v_30801 = (*qfn2(fn))(fn, v_30802, v_30801);
    env = stack[-3];
    v_30801 = Llength(nil, v_30801);
    env = stack[-3];
    stack[-2] = v_30801;
    goto v_30776;
v_30772:
    v_30802 = stack[-2];
    goto v_30773;
v_30774:
    v_30801 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_30775;
v_30776:
    goto v_30772;
v_30773:
    goto v_30774;
v_30775:
    v_30801 = (LispObject)geq2(v_30802, v_30801);
    v_30801 = v_30801 ? lisp_true : nil;
    env = stack[-3];
    if (v_30801 == nil) goto v_30770;
    v_30801 = nil;
    goto v_30768;
v_30770:
    goto v_30789;
v_30783:
    goto v_30795;
v_30791:
    v_30802 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_30792;
v_30793:
    v_30801 = stack[-2];
    goto v_30794;
v_30795:
    goto v_30791;
v_30792:
    goto v_30793;
v_30794:
    stack[-2] = times2(v_30802, v_30801);
    env = stack[-3];
    goto v_30784;
v_30785:
    goto v_30786;
v_30787:
    v_30801 = stack[0];
    v_30801 = ncons(v_30801);
    goto v_30788;
v_30789:
    goto v_30783;
v_30784:
    goto v_30785;
v_30786:
    goto v_30787;
v_30788:
    {
        LispObject v_30806 = stack[-2];
        LispObject v_30807 = stack[-1];
        return list2star(v_30806, v_30807, v_30801);
    }
    v_30801 = nil;
v_30768:
    return onevalue(v_30801);
}



// Code for tidysqrtf

static LispObject CC_tidysqrtf(LispObject env,
                         LispObject v_30754)
{
    env = qenv(env);
    LispObject v_30946, v_30947, v_30948;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30754);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_30754;
// end of prologue
    v_30946 = stack[-1];
    if (!consp(v_30946)) goto v_30762;
    else goto v_30763;
v_30762:
    v_30946 = lisp_true;
    goto v_30761;
v_30763:
    v_30946 = stack[-1];
    v_30946 = qcar(v_30946);
    v_30946 = (consp(v_30946) ? nil : lisp_true);
    goto v_30761;
    v_30946 = nil;
v_30761:
    if (v_30946 == nil) goto v_30759;
    goto v_30776;
v_30772:
    v_30947 = stack[-1];
    goto v_30773;
v_30774:
    v_30946 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30775;
v_30776:
    goto v_30772;
v_30773:
    goto v_30774;
v_30775:
    return cons(v_30947, v_30946);
v_30759:
    v_30946 = stack[-1];
    v_30946 = qcar(v_30946);
    v_30946 = qcar(v_30946);
    stack[-2] = v_30946;
    goto v_30796;
v_30792:
    v_30946 = stack[-2];
    v_30947 = qcar(v_30946);
    goto v_30793;
v_30794:
    v_30946 = elt(env, 1); // i
    goto v_30795;
v_30796:
    goto v_30792;
v_30793:
    goto v_30794;
v_30795:
    if (v_30947 == v_30946) goto v_30790;
    else goto v_30791;
v_30790:
    goto v_30805;
v_30801:
    v_30947 = elt(env, 2); // (sqrt -1)
    goto v_30802;
v_30803:
    v_30946 = stack[-2];
    v_30946 = qcdr(v_30946);
    goto v_30804;
v_30805:
    goto v_30801;
v_30802:
    goto v_30803;
v_30804:
    fn = elt(env, 4); // mksp
    v_30946 = (*qfn2(fn))(fn, v_30947, v_30946);
    env = stack[-3];
    stack[-2] = v_30946;
    goto v_30789;
v_30791:
v_30789:
    goto v_30822;
v_30818:
    v_30946 = stack[-2];
    v_30947 = qcar(v_30946);
    goto v_30819;
v_30820:
    v_30946 = elt(env, 3); // sqrt
    goto v_30821;
v_30822:
    goto v_30818;
v_30819:
    goto v_30820;
v_30821:
    if (!consp(v_30947)) goto v_30816;
    v_30947 = qcar(v_30947);
    if (v_30947 == v_30946) goto v_30815;
    else goto v_30816;
v_30815:
    v_30946 = stack[-2];
    v_30946 = qcdr(v_30946);
    v_30946 = Lonep(nil, v_30946);
    env = stack[-3];
    v_30946 = (v_30946 == nil ? lisp_true : nil);
    goto v_30814;
v_30816:
    v_30946 = nil;
    goto v_30814;
    v_30946 = nil;
v_30814:
    if (v_30946 == nil) goto v_30812;
    goto v_30841;
v_30837:
    v_30946 = stack[-2];
    v_30947 = qcdr(v_30946);
    goto v_30838;
v_30839:
    v_30946 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_30840;
v_30841:
    goto v_30837;
v_30838:
    goto v_30839;
v_30840:
    v_30946 = Ldivide(nil, v_30947, v_30946);
    env = stack[-3];
    stack[0] = v_30946;
    goto v_30850;
v_30846:
    v_30946 = stack[-2];
    v_30946 = qcar(v_30946);
    v_30946 = qcdr(v_30946);
    v_30946 = qcar(v_30946);
    fn = elt(env, 5); // simp
    v_30947 = (*qfn1(fn))(fn, v_30946);
    env = stack[-3];
    goto v_30847;
v_30848:
    v_30946 = stack[0];
    v_30946 = qcar(v_30946);
    goto v_30849;
v_30850:
    goto v_30846;
v_30847:
    goto v_30848;
v_30849:
    fn = elt(env, 6); // exptsq
    v_30946 = (*qfn2(fn))(fn, v_30947, v_30946);
    env = stack[-3];
    v_30948 = v_30946;
    goto v_30866;
v_30862:
    v_30946 = stack[0];
    v_30947 = qcdr(v_30946);
    goto v_30863;
v_30864:
    v_30946 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30865;
v_30866:
    goto v_30862;
v_30863:
    goto v_30864;
v_30865:
    if (v_30947 == v_30946) goto v_30861;
    goto v_30875;
v_30871:
    stack[0] = v_30948;
    goto v_30872;
v_30873:
    goto v_30884;
v_30878:
    goto v_30890;
v_30886:
    goto v_30896;
v_30892:
    v_30946 = stack[-2];
    v_30947 = qcar(v_30946);
    goto v_30893;
v_30894:
    v_30946 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30895;
v_30896:
    goto v_30892;
v_30893:
    goto v_30894;
v_30895:
    fn = elt(env, 4); // mksp
    v_30947 = (*qfn2(fn))(fn, v_30947, v_30946);
    env = stack[-3];
    goto v_30887;
v_30888:
    v_30946 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30889;
v_30890:
    goto v_30886;
v_30887:
    goto v_30888;
v_30889:
    v_30948 = cons(v_30947, v_30946);
    env = stack[-3];
    goto v_30879;
v_30880:
    v_30947 = nil;
    goto v_30881;
v_30882:
    v_30946 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30883;
v_30884:
    goto v_30878;
v_30879:
    goto v_30880;
v_30881:
    goto v_30882;
v_30883:
    v_30946 = acons(v_30948, v_30947, v_30946);
    env = stack[-3];
    goto v_30874;
v_30875:
    goto v_30871;
v_30872:
    goto v_30873;
v_30874:
    fn = elt(env, 7); // multsq
    v_30946 = (*qfn2(fn))(fn, stack[0], v_30946);
    env = stack[-3];
    v_30948 = v_30946;
    goto v_30859;
v_30861:
v_30859:
    v_30946 = v_30948;
    fn = elt(env, 8); // tidysqrt
    v_30946 = (*qfn1(fn))(fn, v_30946);
    env = stack[-3];
    v_30948 = v_30946;
    goto v_30810;
v_30812:
    goto v_30914;
v_30908:
    goto v_30920;
v_30916:
    v_30947 = stack[-2];
    goto v_30917;
v_30918:
    v_30946 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30919;
v_30920:
    goto v_30916;
v_30917:
    goto v_30918;
v_30919:
    v_30948 = cons(v_30947, v_30946);
    env = stack[-3];
    goto v_30909;
v_30910:
    v_30947 = nil;
    goto v_30911;
v_30912:
    v_30946 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30913;
v_30914:
    goto v_30908;
v_30909:
    goto v_30910;
v_30911:
    goto v_30912;
v_30913:
    v_30946 = acons(v_30948, v_30947, v_30946);
    env = stack[-3];
    v_30948 = v_30946;
    goto v_30810;
v_30810:
    goto v_30930;
v_30926:
    stack[0] = v_30948;
    goto v_30927;
v_30928:
    v_30946 = stack[-1];
    v_30946 = qcar(v_30946);
    v_30946 = qcdr(v_30946);
    v_30946 = CC_tidysqrtf(elt(env, 0), v_30946);
    env = stack[-3];
    goto v_30929;
v_30930:
    goto v_30926;
v_30927:
    goto v_30928;
v_30929:
    fn = elt(env, 7); // multsq
    v_30946 = (*qfn2(fn))(fn, stack[0], v_30946);
    env = stack[-3];
    stack[-2] = v_30946;
    goto v_30941;
v_30937:
    stack[0] = stack[-2];
    goto v_30938;
v_30939:
    v_30946 = stack[-1];
    v_30946 = qcdr(v_30946);
    v_30946 = CC_tidysqrtf(elt(env, 0), v_30946);
    env = stack[-3];
    goto v_30940;
v_30941:
    goto v_30937;
v_30938:
    goto v_30939;
v_30940:
    {
        LispObject v_30952 = stack[0];
        fn = elt(env, 9); // addsq
        return (*qfn2(fn))(fn, v_30952, v_30946);
    }
    goto v_30757;
    v_30946 = nil;
v_30757:
    return onevalue(v_30946);
}



// Code for smt_prin2x

static LispObject CC_smt_prin2x(LispObject env,
                         LispObject v_30754)
{
    env = qenv(env);
    LispObject v_30764, v_30765;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30754);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30764 = v_30754;
// end of prologue
    goto v_30761;
v_30757:
    v_30765 = v_30764;
    goto v_30758;
v_30759:
    v_30764 = qvalue(elt(env, 1)); // outl!*
    goto v_30760;
v_30761:
    goto v_30757;
v_30758:
    goto v_30759;
v_30760:
    v_30764 = cons(v_30765, v_30764);
    env = stack[0];
    qvalue(elt(env, 1)) = v_30764; // outl!*
    return onevalue(v_30764);
}



// Code for xadd!*

static LispObject CC_xaddH(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30990, v_30991, v_30992;
    LispObject fn;
    LispObject v_30756, v_30755, v_30754;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xadd*");
    va_start(aa, nargs);
    v_30754 = va_arg(aa, LispObject);
    v_30755 = va_arg(aa, LispObject);
    v_30756 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30756,v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30754,v_30755,v_30756);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(14);
// copy arguments values to proper place
    stack[-9] = v_30756;
    stack[-10] = v_30755;
    stack[-11] = v_30754;
// end of prologue
    v_30990 = stack[-10];
    stack[-12] = v_30990;
v_30765:
    v_30990 = stack[-12];
    if (v_30990 == nil) goto v_30768;
    goto v_30781;
v_30777:
    v_30990 = stack[-11];
    v_30991 = qcar(v_30990);
    goto v_30778;
v_30779:
    v_30990 = stack[-12];
    v_30990 = qcar(v_30990);
    v_30990 = qcar(v_30990);
    goto v_30780;
v_30781:
    goto v_30777;
v_30778:
    goto v_30779;
v_30780:
    if (equal(v_30991, v_30990)) goto v_30775;
    else goto v_30776;
v_30775:
    goto v_30791;
v_30787:
    v_30990 = stack[-11];
    v_30990 = qcdr(v_30990);
    v_30991 = qcar(v_30990);
    goto v_30788;
v_30789:
    v_30990 = stack[-12];
    v_30990 = qcar(v_30990);
    v_30990 = qcdr(v_30990);
    v_30990 = qcar(v_30990);
    goto v_30790;
v_30791:
    goto v_30787;
v_30788:
    goto v_30789;
v_30790:
    v_30990 = (equal(v_30991, v_30990) ? lisp_true : nil);
    goto v_30774;
v_30776:
    v_30990 = nil;
    goto v_30774;
    v_30990 = nil;
v_30774:
    if (v_30990 == nil) goto v_30772;
    else goto v_30768;
v_30772:
    goto v_30769;
v_30768:
    goto v_30764;
v_30769:
    v_30990 = stack[-12];
    v_30990 = qcdr(v_30990);
    stack[-12] = v_30990;
    goto v_30765;
v_30764:
    v_30990 = stack[-12];
    if (v_30990 == nil) goto v_30809;
    goto v_30816;
v_30812:
    v_30990 = stack[-12];
    v_30991 = qcar(v_30990);
    goto v_30813;
v_30814:
    v_30990 = stack[-10];
    goto v_30815;
v_30816:
    goto v_30812;
v_30813:
    goto v_30814;
v_30815:
    v_30990 = Ldelete(nil, v_30991, v_30990);
    env = stack[-13];
    stack[-10] = v_30990;
    v_30990 = stack[-12];
    v_30990 = qcar(v_30990);
    stack[-12] = v_30990;
    v_30990 = stack[-9];
    if (v_30990 == nil) goto v_30825;
    v_30990 = qvalue(elt(env, 1)); // newrule!*
    if (v_30990 == nil) goto v_30825;
    goto v_30842;
v_30838:
    v_30990 = stack[-12];
    v_30991 = qcar(v_30990);
    goto v_30839;
v_30840:
    v_30990 = qvalue(elt(env, 1)); // newrule!*
    v_30990 = qcar(v_30990);
    stack[0] = v_30990;
    goto v_30841;
v_30842:
    goto v_30838;
v_30839:
    goto v_30840;
v_30841:
    if (equal(v_30991, v_30990)) goto v_30837;
    v_30990 = stack[-12];
    v_30990 = qcar(v_30990);
    fn = elt(env, 6); // powlisp
    v_30990 = (*qfn1(fn))(fn, v_30990);
    env = stack[-13];
    goto v_30835;
v_30837:
    v_30990 = nil;
    goto v_30835;
    v_30990 = nil;
v_30835:
    if (v_30990 == nil) goto v_30833;
    goto v_30858;
v_30854:
    goto v_30868;
v_30862:
    stack[-8] = elt(env, 2); // plus
    goto v_30863;
v_30864:
    stack[-7] = stack[0];
    goto v_30865;
v_30866:
    goto v_30878;
v_30872:
    stack[-6] = elt(env, 3); // difference
    goto v_30873;
v_30874:
    v_30990 = stack[-12];
    v_30990 = qcdr(v_30990);
    v_30990 = qcdr(v_30990);
    stack[-5] = qcar(v_30990);
    goto v_30875;
v_30876:
    goto v_30889;
v_30885:
    stack[-4] = elt(env, 4); // times
    goto v_30886;
v_30887:
    v_30990 = stack[-12];
    v_30990 = qcar(v_30990);
    stack[-3] = v_30990;
    v_30990 = stack[-3];
    if (v_30990 == nil) goto v_30901;
    else goto v_30902;
v_30901:
    v_30990 = nil;
    goto v_30895;
v_30902:
    v_30990 = stack[-3];
    v_30990 = qcar(v_30990);
    goto v_30916;
v_30910:
    v_30992 = elt(env, 5); // expt
    goto v_30911;
v_30912:
    v_30991 = v_30990;
    v_30991 = qcar(v_30991);
    goto v_30913;
v_30914:
    v_30990 = qcdr(v_30990);
    goto v_30915;
v_30916:
    goto v_30910;
v_30911:
    goto v_30912;
v_30913:
    goto v_30914;
v_30915:
    v_30990 = list3(v_30992, v_30991, v_30990);
    env = stack[-13];
    v_30990 = ncons(v_30990);
    env = stack[-13];
    stack[-1] = v_30990;
    stack[-2] = v_30990;
v_30896:
    v_30990 = stack[-3];
    v_30990 = qcdr(v_30990);
    stack[-3] = v_30990;
    v_30990 = stack[-3];
    if (v_30990 == nil) goto v_30926;
    else goto v_30927;
v_30926:
    v_30990 = stack[-2];
    goto v_30895;
v_30927:
    goto v_30935;
v_30931:
    stack[0] = stack[-1];
    goto v_30932;
v_30933:
    v_30990 = stack[-3];
    v_30990 = qcar(v_30990);
    goto v_30948;
v_30942:
    v_30992 = elt(env, 5); // expt
    goto v_30943;
v_30944:
    v_30991 = v_30990;
    v_30991 = qcar(v_30991);
    goto v_30945;
v_30946:
    v_30990 = qcdr(v_30990);
    goto v_30947;
v_30948:
    goto v_30942;
v_30943:
    goto v_30944;
v_30945:
    goto v_30946;
v_30947:
    v_30990 = list3(v_30992, v_30991, v_30990);
    env = stack[-13];
    v_30990 = ncons(v_30990);
    env = stack[-13];
    goto v_30934;
v_30935:
    goto v_30931;
v_30932:
    goto v_30933;
v_30934:
    v_30990 = Lrplacd(nil, stack[0], v_30990);
    env = stack[-13];
    v_30990 = stack[-1];
    v_30990 = qcdr(v_30990);
    stack[-1] = v_30990;
    goto v_30896;
v_30895:
    goto v_30888;
v_30889:
    goto v_30885;
v_30886:
    goto v_30887;
v_30888:
    v_30990 = cons(stack[-4], v_30990);
    env = stack[-13];
    goto v_30877;
v_30878:
    goto v_30872;
v_30873:
    goto v_30874;
v_30875:
    goto v_30876;
v_30877:
    v_30990 = list3(stack[-6], stack[-5], v_30990);
    env = stack[-13];
    goto v_30867;
v_30868:
    goto v_30862;
v_30863:
    goto v_30864;
v_30865:
    goto v_30866;
v_30867:
    v_30990 = list3(stack[-8], stack[-7], v_30990);
    env = stack[-13];
    fn = elt(env, 7); // simp
    v_30990 = (*qfn1(fn))(fn, v_30990);
    env = stack[-13];
    fn = elt(env, 8); // prepsq
    v_30991 = (*qfn1(fn))(fn, v_30990);
    env = stack[-13];
    goto v_30855;
v_30856:
    v_30990 = stack[-12];
    v_30990 = qcdr(v_30990);
    v_30990 = qcar(v_30990);
    v_30990 = qcdr(v_30990);
    goto v_30857;
v_30858:
    goto v_30854;
v_30855:
    goto v_30856;
v_30857:
    fn = elt(env, 9); // updoldrules
    v_30990 = (*qfn2(fn))(fn, v_30991, v_30990);
    env = stack[-13];
    goto v_30831;
v_30833:
    goto v_30967;
v_30963:
    v_30990 = stack[-12];
    v_30990 = qcdr(v_30990);
    v_30990 = qcdr(v_30990);
    v_30991 = qcar(v_30990);
    goto v_30964;
v_30965:
    v_30990 = stack[-12];
    v_30990 = qcdr(v_30990);
    v_30990 = qcar(v_30990);
    v_30990 = qcdr(v_30990);
    goto v_30966;
v_30967:
    goto v_30963;
v_30964:
    goto v_30965;
v_30966:
    fn = elt(env, 9); // updoldrules
    v_30990 = (*qfn2(fn))(fn, v_30991, v_30990);
    env = stack[-13];
    goto v_30831;
v_30831:
    goto v_30823;
v_30825:
v_30823:
    goto v_30807;
v_30809:
v_30807:
    v_30990 = stack[-9];
    if (v_30990 == nil) goto v_30979;
    goto v_30986;
v_30982:
    v_30991 = stack[-11];
    goto v_30983;
v_30984:
    v_30990 = stack[-10];
    goto v_30985;
v_30986:
    goto v_30982;
v_30983:
    goto v_30984;
v_30985:
    v_30990 = cons(v_30991, v_30990);
    stack[-10] = v_30990;
    goto v_30977;
v_30979:
v_30977:
    v_30990 = stack[-10];
    return onevalue(v_30990);
}



// Code for vdpfmon

static LispObject CC_vdpfmon(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30801;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_30755;
    v_30801 = v_30754;
// end of prologue
    goto v_30769;
v_30761:
    stack[-5] = elt(env, 1); // vdp
    goto v_30762;
v_30763:
    stack[-3] = stack[-4];
    goto v_30764;
v_30765:
    stack[-2] = v_30801;
    goto v_30766;
v_30767:
    goto v_30780;
v_30774:
    stack[-1] = stack[-4];
    goto v_30775;
v_30776:
    stack[0] = ncons(v_30801);
    env = stack[-6];
    goto v_30777;
v_30778:
    v_30801 = nil;
    v_30801 = ncons(v_30801);
    env = stack[-6];
    goto v_30779;
v_30780:
    goto v_30774;
v_30775:
    goto v_30776;
v_30777:
    goto v_30778;
v_30779:
    v_30801 = acons(stack[-1], stack[0], v_30801);
    env = stack[-6];
    goto v_30768;
v_30769:
    goto v_30761;
v_30762:
    goto v_30763;
v_30764:
    goto v_30765;
v_30766:
    goto v_30767;
v_30768:
    v_30801 = list3star(stack[-5], stack[-3], stack[-2], v_30801);
    env = stack[-6];
    stack[-1] = v_30801;
    v_30801 = qvalue(elt(env, 2)); // !*gsugar
    if (v_30801 == nil) goto v_30789;
    goto v_30796;
v_30792:
    stack[0] = stack[-1];
    goto v_30793;
v_30794:
    v_30801 = stack[-4];
    fn = elt(env, 3); // vevtdeg
    v_30801 = (*qfn1(fn))(fn, v_30801);
    env = stack[-6];
    goto v_30795;
v_30796:
    goto v_30792;
v_30793:
    goto v_30794;
v_30795:
    fn = elt(env, 4); // gsetsugar
    v_30801 = (*qfn2(fn))(fn, stack[0], v_30801);
    goto v_30787;
v_30789:
v_30787:
    v_30801 = stack[-1];
    return onevalue(v_30801);
}



// Code for xexptpf

static LispObject CC_xexptpf(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30803, v_30804;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30755;
    stack[-1] = v_30754;
// end of prologue
    stack[-2] = nil;
v_30761:
    goto v_30772;
v_30768:
    v_30804 = stack[0];
    goto v_30769;
v_30770:
    v_30803 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30771;
v_30772:
    goto v_30768;
v_30769:
    goto v_30770;
v_30771:
    if (v_30804 == v_30803) goto v_30766;
    else goto v_30767;
v_30766:
    goto v_30762;
v_30767:
    goto v_30780;
v_30776:
    v_30804 = stack[-1];
    goto v_30777;
v_30778:
    v_30803 = stack[-2];
    goto v_30779;
v_30780:
    goto v_30776;
v_30777:
    goto v_30778;
v_30779:
    v_30803 = cons(v_30804, v_30803);
    env = stack[-3];
    stack[-2] = v_30803;
    v_30803 = stack[0];
    v_30803 = sub1(v_30803);
    env = stack[-3];
    stack[0] = v_30803;
    goto v_30761;
v_30762:
    v_30803 = stack[-1];
    v_30804 = v_30803;
v_30763:
    v_30803 = stack[-2];
    if (v_30803 == nil) goto v_30788;
    else goto v_30789;
v_30788:
    v_30803 = v_30804;
    goto v_30760;
v_30789:
    goto v_30797;
v_30793:
    v_30803 = stack[-2];
    v_30803 = qcar(v_30803);
    goto v_30794;
v_30795:
    goto v_30796;
v_30797:
    goto v_30793;
v_30794:
    goto v_30795;
v_30796:
    fn = elt(env, 1); // wedgepf
    v_30803 = (*qfn2(fn))(fn, v_30803, v_30804);
    env = stack[-3];
    v_30804 = v_30803;
    v_30803 = stack[-2];
    v_30803 = qcdr(v_30803);
    stack[-2] = v_30803;
    goto v_30763;
v_30760:
    return onevalue(v_30803);
}



// Code for decimal2internal

static LispObject CC_decimal2internal(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30815, v_30816, v_30817;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30755;
    stack[-1] = v_30754;
// end of prologue
    goto v_30766;
v_30762:
    v_30816 = stack[0];
    goto v_30763;
v_30764:
    v_30815 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30765;
v_30766:
    goto v_30762;
v_30763:
    goto v_30764;
v_30765:
    v_30815 = (LispObject)geq2(v_30816, v_30815);
    v_30815 = v_30815 ? lisp_true : nil;
    env = stack[-3];
    if (v_30815 == nil) goto v_30760;
    goto v_30776;
v_30770:
    stack[-2] = elt(env, 1); // !:rd!:
    goto v_30771;
v_30772:
    goto v_30783;
v_30779:
    goto v_30780;
v_30781:
    goto v_30790;
v_30786:
    v_30816 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_30787;
v_30788:
    v_30815 = stack[0];
    goto v_30789;
v_30790:
    goto v_30786;
v_30787:
    goto v_30788;
v_30789:
    v_30815 = Lexpt(nil, v_30816, v_30815);
    env = stack[-3];
    goto v_30782;
v_30783:
    goto v_30779;
v_30780:
    goto v_30781;
v_30782:
    v_30816 = times2(stack[-1], v_30815);
    goto v_30773;
v_30774:
    v_30815 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30775;
v_30776:
    goto v_30770;
v_30771:
    goto v_30772;
v_30773:
    goto v_30774;
v_30775:
    {
        LispObject v_30821 = stack[-2];
        return list2star(v_30821, v_30816, v_30815);
    }
v_30760:
    goto v_30801;
v_30797:
    goto v_30809;
v_30803:
    v_30817 = elt(env, 1); // !:rd!:
    goto v_30804;
v_30805:
    v_30816 = stack[-1];
    goto v_30806;
v_30807:
    v_30815 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30808;
v_30809:
    goto v_30803;
v_30804:
    goto v_30805;
v_30806:
    goto v_30807;
v_30808:
    stack[-1] = list2star(v_30817, v_30816, v_30815);
    env = stack[-3];
    goto v_30798;
v_30799:
    v_30815 = stack[0];
    v_30815 = negate(v_30815);
    env = stack[-3];
    goto v_30800;
v_30801:
    goto v_30797;
v_30798:
    goto v_30799;
v_30800:
    {
        LispObject v_30822 = stack[-1];
        fn = elt(env, 2); // divide!-by!-power!-of!-ten
        return (*qfn2(fn))(fn, v_30822, v_30815);
    }
    v_30815 = nil;
    return onevalue(v_30815);
}



// Code for mk!-contract!-coeff

static LispObject CC_mkKcontractKcoeff(LispObject env,
                         LispObject v_30754)
{
    env = qenv(env);
    LispObject v_30815, v_30816;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30754);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_30754;
// end of prologue
    goto v_30764;
v_30760:
    v_30815 = stack[0];
    v_30815 = qcar(v_30815);
    v_30816 = qcar(v_30815);
    goto v_30761;
v_30762:
    v_30815 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30763;
v_30764:
    goto v_30760;
v_30761:
    goto v_30762;
v_30763:
    if (v_30816 == v_30815) goto v_30758;
    else goto v_30759;
v_30758:
    v_30815 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30757;
v_30759:
    v_30815 = stack[0];
    v_30815 = qcar(v_30815);
    v_30815 = qcar(v_30815);
    stack[-3] = v_30815;
    v_30815 = stack[0];
    v_30815 = qcdr(v_30815);
    v_30815 = qcar(v_30815);
    v_30815 = Llength(nil, v_30815);
    env = stack[-4];
    v_30816 = v_30815;
    goto v_30791;
v_30787:
    v_30815 = stack[0];
    v_30815 = qcar(v_30815);
    v_30815 = qcdr(v_30815);
    stack[-2] = qcar(v_30815);
    goto v_30788;
v_30789:
    goto v_30803;
v_30797:
    stack[-1] = qvalue(elt(env, 1)); // ndim!*
    goto v_30798;
v_30799:
    stack[0] = v_30816;
    goto v_30800;
v_30801:
    goto v_30811;
v_30807:
    goto v_30808;
v_30809:
    v_30815 = stack[-3];
    goto v_30810;
v_30811:
    goto v_30807;
v_30808:
    goto v_30809;
v_30810:
    v_30815 = plus2(v_30816, v_30815);
    env = stack[-4];
    goto v_30802;
v_30803:
    goto v_30797;
v_30798:
    goto v_30799;
v_30800:
    goto v_30801;
v_30802:
    fn = elt(env, 2); // mk!-numr
    v_30815 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_30815);
    env = stack[-4];
    goto v_30790;
v_30791:
    goto v_30787;
v_30788:
    goto v_30789;
v_30790:
    v_30815 = cons(stack[-2], v_30815);
    env = stack[-4];
    {
        fn = elt(env, 3); // constimes
        return (*qfn1(fn))(fn, v_30815);
    }
    goto v_30757;
    v_30815 = nil;
v_30757:
    return onevalue(v_30815);
}



// Code for hdiff

static LispObject CC_hdiff(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30794, v_30795;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30755;
    stack[-1] = v_30754;
// end of prologue
    v_30794 = stack[-1];
    if (v_30794 == nil) goto v_30759;
    else goto v_30760;
v_30759:
    v_30794 = nil;
    goto v_30758;
v_30760:
    goto v_30770;
v_30766:
    goto v_30776;
v_30772:
    goto v_30781;
v_30777:
    v_30795 = stack[-1];
    goto v_30778;
v_30779:
    v_30794 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_30780;
v_30781:
    goto v_30777;
v_30778:
    goto v_30779;
v_30780:
    v_30795 = *(LispObject *)((char *)v_30795 + (CELL-TAG_VECTOR) + (((intptr_t)v_30794-TAG_FIXNUM)/(16/CELL)));
    goto v_30773;
v_30774:
    v_30794 = stack[0];
    goto v_30775;
v_30776:
    goto v_30772;
v_30773:
    goto v_30774;
v_30775:
    stack[-2] = CC_hdiff(elt(env, 0), v_30795, v_30794);
    env = stack[-3];
    goto v_30767;
v_30768:
    goto v_30791;
v_30787:
    v_30795 = stack[-1];
    goto v_30788;
v_30789:
    v_30794 = stack[0];
    goto v_30790;
v_30791:
    goto v_30787;
v_30788:
    goto v_30789;
v_30790:
    fn = elt(env, 1); // hdiffterm
    v_30794 = (*qfn2(fn))(fn, v_30795, v_30794);
    env = stack[-3];
    goto v_30769;
v_30770:
    goto v_30766;
v_30767:
    goto v_30768;
v_30769:
    {
        LispObject v_30799 = stack[-2];
        fn = elt(env, 2); // fs!:plus
        return (*qfn2(fn))(fn, v_30799, v_30794);
    }
    v_30794 = nil;
v_30758:
    return onevalue(v_30794);
}



// Code for test!-bool

static LispObject CC_testKbool(LispObject env,
                         LispObject v_30754)
{
    env = qenv(env);
    LispObject v_30762;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30754);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30762 = v_30754;
// end of prologue
    v_30762 = qcar(v_30762);
    fn = elt(env, 1); // boolean!-eval1
    v_30762 = (*qfn1(fn))(fn, v_30762);
    env = stack[0];
    v_30762 = ncons(v_30762);
    env = stack[0];
    fn = elt(env, 2); // simp!-prop
    v_30762 = (*qfn1(fn))(fn, v_30762);
    env = stack[0];
    {
        fn = elt(env, 3); // mk!*sq
        return (*qfn1(fn))(fn, v_30762);
    }
}



// Code for combin

static LispObject CC_combin(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30853, v_30854;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_30755;
    stack[-3] = v_30754;
// end of prologue
    goto v_30766;
v_30762:
    v_30854 = stack[-3];
    goto v_30763;
v_30764:
    v_30853 = stack[-2];
    goto v_30765;
v_30766:
    goto v_30762;
v_30763:
    goto v_30764;
v_30765:
    v_30853 = (LispObject)greaterp2(v_30854, v_30853);
    v_30853 = v_30853 ? lisp_true : nil;
    env = stack[-5];
    if (v_30853 == nil) goto v_30760;
    v_30853 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30758;
v_30760:
    v_30853 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_30853;
    stack[-4] = v_30853;
    goto v_30789;
v_30785:
    v_30854 = stack[-2];
    goto v_30786;
v_30787:
    v_30853 = stack[-3];
    goto v_30788;
v_30789:
    goto v_30785;
v_30786:
    goto v_30787;
v_30788:
    v_30853 = difference2(v_30854, v_30853);
    env = stack[-5];
    v_30853 = add1(v_30853);
    env = stack[-5];
    stack[0] = v_30853;
v_30782:
    goto v_30802;
v_30798:
    v_30854 = stack[-2];
    goto v_30799;
v_30800:
    v_30853 = stack[0];
    goto v_30801;
v_30802:
    goto v_30798;
v_30799:
    goto v_30800;
v_30801:
    v_30853 = difference2(v_30854, v_30853);
    env = stack[-5];
    v_30853 = Lminusp(nil, v_30853);
    env = stack[-5];
    if (v_30853 == nil) goto v_30795;
    goto v_30781;
v_30795:
    goto v_30811;
v_30807:
    v_30854 = stack[-4];
    goto v_30808;
v_30809:
    v_30853 = stack[0];
    goto v_30810;
v_30811:
    goto v_30807;
v_30808:
    goto v_30809;
v_30810:
    v_30853 = times2(v_30854, v_30853);
    env = stack[-5];
    stack[-4] = v_30853;
    v_30853 = stack[0];
    v_30853 = add1(v_30853);
    env = stack[-5];
    stack[0] = v_30853;
    goto v_30782;
v_30781:
    v_30853 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_30853;
v_30819:
    goto v_30831;
v_30827:
    v_30854 = stack[-3];
    goto v_30828;
v_30829:
    v_30853 = stack[0];
    goto v_30830;
v_30831:
    goto v_30827;
v_30828:
    goto v_30829;
v_30830:
    v_30853 = difference2(v_30854, v_30853);
    env = stack[-5];
    v_30853 = Lminusp(nil, v_30853);
    env = stack[-5];
    if (v_30853 == nil) goto v_30824;
    goto v_30818;
v_30824:
    goto v_30840;
v_30836:
    v_30854 = stack[-1];
    goto v_30837;
v_30838:
    v_30853 = stack[0];
    goto v_30839;
v_30840:
    goto v_30836;
v_30837:
    goto v_30838;
v_30839:
    v_30853 = times2(v_30854, v_30853);
    env = stack[-5];
    stack[-1] = v_30853;
    v_30853 = stack[0];
    v_30853 = add1(v_30853);
    env = stack[-5];
    stack[0] = v_30853;
    goto v_30819;
v_30818:
    goto v_30850;
v_30846:
    v_30854 = stack[-4];
    goto v_30847;
v_30848:
    v_30853 = stack[-1];
    goto v_30849;
v_30850:
    goto v_30846;
v_30847:
    goto v_30848;
v_30849:
    return quot2(v_30854, v_30853);
    goto v_30758;
    v_30853 = nil;
v_30758:
    return onevalue(v_30853);
}



// Code for coeffs!-to!-form1

static LispObject CC_coeffsKtoKform1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30816, v_30817, v_30818;
    LispObject fn;
    LispObject v_30756, v_30755, v_30754;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "coeffs-to-form1");
    va_start(aa, nargs);
    v_30754 = va_arg(aa, LispObject);
    v_30755 = va_arg(aa, LispObject);
    v_30756 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_30756,v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_30754,v_30755,v_30756);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_30756;
    stack[-2] = v_30755;
    stack[-3] = v_30754;
// end of prologue
    goto v_30767;
v_30763:
    v_30817 = stack[-1];
    goto v_30764;
v_30765:
    v_30816 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30766;
v_30767:
    goto v_30763;
v_30764:
    goto v_30765;
v_30766:
    v_30816 = (LispObject)greaterp2(v_30817, v_30816);
    v_30816 = v_30816 ? lisp_true : nil;
    env = stack[-5];
    if (v_30816 == nil) goto v_30761;
    goto v_30777;
v_30771:
    v_30816 = stack[-3];
    stack[-4] = qcdr(v_30816);
    goto v_30772;
v_30773:
    stack[0] = stack[-2];
    goto v_30774;
v_30775:
    v_30816 = stack[-1];
    v_30816 = sub1(v_30816);
    env = stack[-5];
    goto v_30776;
v_30777:
    goto v_30771;
v_30772:
    goto v_30773;
v_30774:
    goto v_30775;
v_30776:
    v_30816 = CC_coeffsKtoKform1(elt(env, 0), 3, stack[-4], stack[0], v_30816);
    env = stack[-5];
    stack[0] = v_30816;
    v_30816 = stack[-3];
    v_30816 = qcar(v_30816);
    if (v_30816 == nil) goto v_30787;
    goto v_30797;
v_30791:
    goto v_30803;
v_30799:
    v_30817 = stack[-2];
    goto v_30800;
v_30801:
    v_30816 = stack[-1];
    goto v_30802;
v_30803:
    goto v_30799;
v_30800:
    goto v_30801;
v_30802:
    fn = elt(env, 1); // to
    v_30818 = (*qfn2(fn))(fn, v_30817, v_30816);
    goto v_30792;
v_30793:
    v_30816 = stack[-3];
    v_30817 = qcar(v_30816);
    goto v_30794;
v_30795:
    v_30816 = stack[0];
    goto v_30796;
v_30797:
    goto v_30791;
v_30792:
    goto v_30793;
v_30794:
    goto v_30795;
v_30796:
    return acons(v_30818, v_30817, v_30816);
v_30787:
    v_30816 = stack[0];
    goto v_30785;
    v_30816 = nil;
v_30785:
    goto v_30759;
v_30761:
    v_30816 = stack[-3];
    v_30816 = qcar(v_30816);
    goto v_30759;
    v_30816 = nil;
v_30759:
    return onevalue(v_30816);
}



// Code for qroundup

static LispObject CC_qroundup(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30797, v_30798;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30755;
    stack[-1] = v_30754;
// end of prologue
    goto v_30766;
v_30762:
    v_30798 = stack[-1];
    goto v_30763;
v_30764:
    v_30797 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_30765;
v_30766:
    goto v_30762;
v_30763:
    goto v_30764;
v_30765:
    v_30797 = (LispObject)lessp2(v_30798, v_30797);
    v_30797 = v_30797 ? lisp_true : nil;
    env = stack[-2];
    if (v_30797 == nil) goto v_30760;
    goto v_30775;
v_30771:
    v_30797 = stack[-1];
    v_30798 = negate(v_30797);
    env = stack[-2];
    goto v_30772;
v_30773:
    v_30797 = stack[0];
    goto v_30774;
v_30775:
    goto v_30771;
v_30772:
    goto v_30773;
v_30774:
    v_30797 = quot2(v_30798, v_30797);
    return negate(v_30797);
v_30760:
    goto v_30786;
v_30782:
    goto v_30792;
v_30788:
    goto v_30789;
v_30790:
    v_30797 = stack[0];
    v_30797 = sub1(v_30797);
    env = stack[-2];
    goto v_30791;
v_30792:
    goto v_30788;
v_30789:
    goto v_30790;
v_30791:
    v_30798 = plus2(stack[-1], v_30797);
    goto v_30783;
v_30784:
    v_30797 = stack[0];
    goto v_30785;
v_30786:
    goto v_30782;
v_30783:
    goto v_30784;
v_30785:
    return quot2(v_30798, v_30797);
    v_30797 = nil;
    return onevalue(v_30797);
}



// Code for ofsf_smwrmknowl

static LispObject CC_ofsf_smwrmknowl(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30780, v_30781, v_30782;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30781 = v_30755;
    v_30782 = v_30754;
// end of prologue
    v_30780 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_30780 == nil) goto v_30760;
    goto v_30767;
v_30763:
    v_30780 = v_30782;
    goto v_30764;
v_30765:
    goto v_30766;
v_30767:
    goto v_30763;
v_30764:
    goto v_30765;
v_30766:
    {
        fn = elt(env, 2); // ofsf_susirmknowl
        return (*qfn2(fn))(fn, v_30780, v_30781);
    }
v_30760:
    goto v_30777;
v_30773:
    v_30780 = v_30782;
    goto v_30774;
v_30775:
    goto v_30776;
v_30777:
    goto v_30773;
v_30774:
    goto v_30775;
v_30776:
    {
        fn = elt(env, 3); // ofsf_smrmknowl
        return (*qfn2(fn))(fn, v_30780, v_30781);
    }
    v_30780 = nil;
    return onevalue(v_30780);
}



// Code for eval!-yetunknowntypeexpr

static LispObject CC_evalKyetunknowntypeexpr(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30911, v_30912;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_30755;
    stack[0] = v_30754;
// end of prologue
v_30753:
    v_30911 = stack[0];
    if (!consp(v_30911)) goto v_30759;
    else goto v_30760;
v_30759:
    v_30911 = stack[0];
    if (!symbolp(v_30911)) v_30911 = nil;
    else { v_30911 = qfastgets(v_30911);
           if (v_30911 != nil) { v_30911 = elt(v_30911, 4); // avalue
#ifdef RECORD_GET
             if (v_30911 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_30911 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_30911 == SPID_NOPROP) v_30911 = nil; }}
#endif
    v_30912 = v_30911;
    v_30911 = v_30912;
    if (v_30911 == nil) goto v_30768;
    goto v_30775;
v_30771:
    v_30911 = v_30912;
    v_30911 = qcdr(v_30911);
    v_30912 = qcar(v_30911);
    goto v_30772;
v_30773:
    v_30911 = stack[-4];
    goto v_30774;
v_30775:
    goto v_30771;
v_30772:
    goto v_30773;
v_30774:
    stack[0] = v_30912;
    stack[-4] = v_30911;
    goto v_30753;
v_30768:
    v_30911 = stack[0];
    goto v_30766;
    v_30911 = nil;
v_30766:
    goto v_30758;
v_30760:
    goto v_30793;
v_30789:
    v_30911 = stack[0];
    v_30912 = qcar(v_30911);
    goto v_30790;
v_30791:
    v_30911 = elt(env, 1); // !*sq
    goto v_30792;
v_30793:
    goto v_30789;
v_30790:
    goto v_30791;
v_30792:
    if (v_30912 == v_30911) goto v_30787;
    else goto v_30788;
v_30787:
    v_30911 = lisp_true;
    goto v_30786;
v_30788:
    v_30911 = stack[0];
    v_30911 = qcar(v_30911);
    if (!symbolp(v_30911)) v_30911 = nil;
    else { v_30911 = qfastgets(v_30911);
           if (v_30911 != nil) { v_30911 = elt(v_30911, 8); // dname
#ifdef RECORD_GET
             if (v_30911 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_30911 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_30911 == SPID_NOPROP) v_30911 = nil; }}
#endif
    if (v_30911 == nil) goto v_30802;
    else goto v_30801;
v_30802:
    goto v_30810;
v_30806:
    v_30911 = stack[0];
    v_30912 = qcar(v_30911);
    goto v_30807;
v_30808:
    v_30911 = elt(env, 2); // !:dn!:
    goto v_30809;
v_30810:
    goto v_30806;
v_30807:
    goto v_30808;
v_30809:
    v_30911 = (v_30912 == v_30911 ? lisp_true : nil);
v_30801:
    goto v_30786;
    v_30911 = nil;
v_30786:
    if (v_30911 == nil) goto v_30784;
    v_30911 = stack[0];
    goto v_30758;
v_30784:
    v_30911 = stack[0];
    v_30911 = qcar(v_30911);
    if (!symbolp(v_30911)) v_30911 = nil;
    else { v_30911 = qfastgets(v_30911);
           if (v_30911 != nil) { v_30911 = elt(v_30911, 45); // psopfn
#ifdef RECORD_GET
             if (v_30911 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v_30911 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v_30911 == SPID_NOPROP) v_30911 = nil; }}
#endif
    stack[-1] = v_30911;
    v_30911 = stack[-1];
    if (v_30911 == nil) goto v_30825;
    goto v_30833;
v_30829:
    v_30911 = stack[0];
    fn = elt(env, 4); // getrtype
    v_30912 = (*qfn1(fn))(fn, v_30911);
    env = stack[-6];
    goto v_30830;
v_30831:
    v_30911 = elt(env, 3); // yetunknowntype
    goto v_30832;
v_30833:
    goto v_30829;
v_30830:
    goto v_30831;
v_30832:
    if (v_30912 == v_30911) goto v_30828;
    else goto v_30825;
v_30828:
    goto v_30842;
v_30838:
    v_30912 = stack[-1];
    goto v_30839;
v_30840:
    v_30911 = stack[0];
    v_30911 = qcdr(v_30911);
    goto v_30841;
v_30842:
    goto v_30838;
v_30839:
    goto v_30840;
v_30841:
        return Lapply1(nil, v_30912, v_30911);
v_30825:
    goto v_30853;
v_30849:
    v_30911 = stack[0];
    stack[-5] = qcar(v_30911);
    goto v_30850;
v_30851:
    v_30911 = stack[0];
    v_30911 = qcdr(v_30911);
    stack[-3] = v_30911;
    v_30911 = stack[-3];
    if (v_30911 == nil) goto v_30866;
    else goto v_30867;
v_30866:
    v_30911 = nil;
    goto v_30860;
v_30867:
    v_30911 = stack[-3];
    v_30911 = qcar(v_30911);
    goto v_30879;
v_30875:
    v_30912 = v_30911;
    goto v_30876;
v_30877:
    v_30911 = stack[-4];
    goto v_30878;
v_30879:
    goto v_30875;
v_30876:
    goto v_30877;
v_30878:
    v_30911 = CC_evalKyetunknowntypeexpr(elt(env, 0), v_30912, v_30911);
    env = stack[-6];
    v_30911 = ncons(v_30911);
    env = stack[-6];
    stack[-1] = v_30911;
    stack[-2] = v_30911;
v_30861:
    v_30911 = stack[-3];
    v_30911 = qcdr(v_30911);
    stack[-3] = v_30911;
    v_30911 = stack[-3];
    if (v_30911 == nil) goto v_30886;
    else goto v_30887;
v_30886:
    v_30911 = stack[-2];
    goto v_30860;
v_30887:
    goto v_30895;
v_30891:
    stack[0] = stack[-1];
    goto v_30892;
v_30893:
    v_30911 = stack[-3];
    v_30911 = qcar(v_30911);
    goto v_30906;
v_30902:
    v_30912 = v_30911;
    goto v_30903;
v_30904:
    v_30911 = stack[-4];
    goto v_30905;
v_30906:
    goto v_30902;
v_30903:
    goto v_30904;
v_30905:
    v_30911 = CC_evalKyetunknowntypeexpr(elt(env, 0), v_30912, v_30911);
    env = stack[-6];
    v_30911 = ncons(v_30911);
    env = stack[-6];
    goto v_30894;
v_30895:
    goto v_30891;
v_30892:
    goto v_30893;
v_30894:
    v_30911 = Lrplacd(nil, stack[0], v_30911);
    env = stack[-6];
    v_30911 = stack[-1];
    v_30911 = qcdr(v_30911);
    stack[-1] = v_30911;
    goto v_30861;
v_30860:
    goto v_30852;
v_30853:
    goto v_30849;
v_30850:
    goto v_30851;
v_30852:
    {
        LispObject v_30919 = stack[-5];
        return cons(v_30919, v_30911);
    }
    v_30911 = nil;
    goto v_30758;
    v_30911 = nil;
v_30758:
    return onevalue(v_30911);
}



// Code for quotf!*

static LispObject CC_quotfH(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30820, v_30821, v_30822;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_30755;
    stack[-1] = v_30754;
// end of prologue
    v_30820 = stack[-1];
    if (v_30820 == nil) goto v_30759;
    else goto v_30760;
v_30759:
    v_30820 = nil;
    goto v_30758;
v_30760:
    goto v_30770;
v_30766:
    v_30821 = stack[-1];
    goto v_30767;
v_30768:
    v_30820 = stack[0];
    goto v_30769;
v_30770:
    goto v_30766;
v_30767:
    goto v_30768;
v_30769:
    fn = elt(env, 2); // quotf
    v_30820 = (*qfn2(fn))(fn, v_30821, v_30820);
    env = stack[-2];
    v_30821 = v_30820;
    v_30820 = v_30821;
    if (v_30820 == nil) goto v_30777;
    v_30820 = v_30821;
    goto v_30775;
v_30777:
    goto v_30788;
v_30784:
    v_30821 = stack[-1];
    goto v_30785;
v_30786:
    v_30820 = stack[0];
    goto v_30787;
v_30788:
    goto v_30784;
v_30785:
    goto v_30786;
v_30787:
    v_30820 = cons(v_30821, v_30820);
    env = stack[-2];
    fn = elt(env, 3); // rationalizesq
    v_30820 = (*qfn1(fn))(fn, v_30820);
    env = stack[-2];
    v_30822 = v_30820;
    goto v_30800;
v_30796:
    v_30820 = v_30822;
    v_30821 = qcdr(v_30820);
    goto v_30797;
v_30798:
    v_30820 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30799;
v_30800:
    goto v_30796;
v_30797:
    goto v_30798;
v_30799:
    if (v_30821 == v_30820) goto v_30794;
    else goto v_30795;
v_30794:
    v_30820 = v_30822;
    v_30820 = qcar(v_30820);
    goto v_30793;
v_30795:
    goto v_30816;
v_30810:
    v_30822 = elt(env, 1); // "DIVISION FAILED"
    goto v_30811;
v_30812:
    v_30821 = stack[-1];
    goto v_30813;
v_30814:
    v_30820 = stack[0];
    goto v_30815;
v_30816:
    goto v_30810;
v_30811:
    goto v_30812;
v_30813:
    goto v_30814;
v_30815:
    v_30820 = list3(v_30822, v_30821, v_30820);
    env = stack[-2];
    {
        fn = elt(env, 4); // errach
        return (*qfn1(fn))(fn, v_30820);
    }
    v_30820 = nil;
v_30793:
    goto v_30775;
    v_30820 = nil;
v_30775:
    goto v_30758;
    v_30820 = nil;
v_30758:
    return onevalue(v_30820);
}



// Code for ldf!-spf!-var

static LispObject CC_ldfKspfKvar(LispObject env,
                         LispObject v_30754)
{
    env = qenv(env);
    LispObject v_30861, v_30862;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30754);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_30861 = v_30754;
// end of prologue
    v_30862 = nil;
    stack[-3] = nil;
    stack[-1] = v_30861;
v_30763:
    v_30861 = stack[-1];
    if (v_30861 == nil) goto v_30767;
    else goto v_30768;
v_30767:
    goto v_30762;
v_30768:
    v_30861 = stack[-1];
    v_30861 = qcar(v_30861);
    goto v_30779;
v_30775:
    stack[0] = v_30862;
    goto v_30776;
v_30777:
    v_30861 = qcdr(v_30861);
    fn = elt(env, 3); // kernels
    v_30861 = (*qfn1(fn))(fn, v_30861);
    env = stack[-4];
    goto v_30778;
v_30779:
    goto v_30775;
v_30776:
    goto v_30777;
v_30778:
    v_30861 = Lappend(nil, stack[0], v_30861);
    env = stack[-4];
    v_30862 = v_30861;
    v_30861 = stack[-1];
    v_30861 = qcdr(v_30861);
    stack[-1] = v_30861;
    goto v_30763;
v_30762:
    v_30861 = v_30862;
    fn = elt(env, 4); // makeset
    v_30861 = (*qfn1(fn))(fn, v_30861);
    env = stack[-4];
    fn = elt(env, 5); // prlist
    v_30861 = (*qfn1(fn))(fn, v_30861);
    env = stack[-4];
    stack[-2] = v_30861;
v_30789:
    v_30861 = stack[-2];
    if (v_30861 == nil) goto v_30795;
    else goto v_30796;
v_30795:
    goto v_30788;
v_30796:
    v_30861 = stack[-2];
    v_30861 = qcar(v_30861);
    stack[-1] = v_30861;
    goto v_30815;
v_30811:
    v_30862 = stack[-1];
    goto v_30812;
v_30813:
    v_30861 = elt(env, 1); // x
    goto v_30814;
v_30815:
    goto v_30811;
v_30812:
    goto v_30813;
v_30814:
    if (!consp(v_30862)) goto v_30808;
    v_30862 = qcar(v_30862);
    if (v_30862 == v_30861) goto v_30809;
v_30808:
    goto v_30823;
v_30819:
    v_30862 = stack[-1];
    goto v_30820;
v_30821:
    v_30861 = elt(env, 2); // u
    goto v_30822;
v_30823:
    goto v_30819;
v_30820:
    goto v_30821;
v_30822:
    v_30861 = Leqcar(nil, v_30862, v_30861);
    env = stack[-4];
    v_30861 = (v_30861 == nil ? lisp_true : nil);
    goto v_30807;
v_30809:
    v_30861 = nil;
    goto v_30807;
    v_30861 = nil;
v_30807:
    if (v_30861 == nil) goto v_30805;
    goto v_30837;
v_30831:
    goto v_30843;
v_30839:
    v_30862 = elt(env, 1); // x
    goto v_30840;
v_30841:
    v_30861 = stack[-1];
    v_30861 = qcdr(v_30861);
    goto v_30842;
v_30843:
    goto v_30839;
v_30840:
    goto v_30841;
v_30842:
    fn = elt(env, 6); // sacar
    stack[0] = (*qfn2(fn))(fn, v_30862, v_30861);
    env = stack[-4];
    goto v_30832;
v_30833:
    goto v_30852;
v_30848:
    v_30862 = elt(env, 2); // u
    goto v_30849;
v_30850:
    v_30861 = stack[-1];
    v_30861 = qcdr(v_30861);
    goto v_30851;
v_30852:
    goto v_30848;
v_30849:
    goto v_30850;
v_30851:
    fn = elt(env, 6); // sacar
    v_30862 = (*qfn2(fn))(fn, v_30862, v_30861);
    env = stack[-4];
    goto v_30834;
v_30835:
    v_30861 = stack[-3];
    goto v_30836;
v_30837:
    goto v_30831;
v_30832:
    goto v_30833;
v_30834:
    goto v_30835;
v_30836:
    fn = elt(env, 7); // appends
    v_30861 = (*qfnn(fn))(fn, 3, stack[0], v_30862, v_30861);
    env = stack[-4];
    stack[-3] = v_30861;
    goto v_30803;
v_30805:
v_30803:
    v_30861 = stack[-2];
    v_30861 = qcdr(v_30861);
    stack[-2] = v_30861;
    goto v_30789;
v_30788:
    v_30861 = stack[-3];
    {
        fn = elt(env, 4); // makeset
        return (*qfn1(fn))(fn, v_30861);
    }
    return onevalue(v_30861);
}



// Code for al1_defined_vertex

static LispObject CC_al1_defined_vertex(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_30838, v_30839;
    LispObject fn;
    LispObject v_30757, v_30756, v_30755, v_30754;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "al1_defined_vertex");
    va_start(aa, nargs);
    v_30754 = va_arg(aa, LispObject);
    v_30755 = va_arg(aa, LispObject);
    v_30756 = va_arg(aa, LispObject);
    v_30757 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_30757,v_30756,v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_30754,v_30755,v_30756,v_30757);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_30757;
    stack[-1] = v_30756;
    stack[-2] = v_30755;
    stack[-3] = v_30754;
// end of prologue
v_30762:
    v_30838 = stack[-3];
    if (v_30838 == nil) goto v_30765;
    else goto v_30766;
v_30765:
    v_30838 = stack[-2];
    if (v_30838 == nil) goto v_30770;
    else goto v_30771;
v_30770:
    v_30838 = lisp_true;
    goto v_30761;
v_30771:
    goto v_30781;
v_30777:
    v_30839 = stack[-2];
    goto v_30778;
v_30779:
    v_30838 = stack[-1];
    goto v_30780;
v_30781:
    goto v_30777;
v_30778:
    goto v_30779;
v_30780:
    {
        fn = elt(env, 1); // re_parents
        return (*qfn2(fn))(fn, v_30839, v_30838);
    }
    goto v_30764;
v_30766:
    goto v_30791;
v_30787:
    v_30838 = stack[-3];
    v_30839 = qcar(v_30838);
    goto v_30788;
v_30789:
    v_30838 = stack[0];
    goto v_30790;
v_30791:
    goto v_30787;
v_30788:
    goto v_30789;
v_30790:
    fn = elt(env, 2); // defined_edge
    v_30838 = (*qfn2(fn))(fn, v_30839, v_30838);
    env = stack[-5];
    if (v_30838 == nil) goto v_30785;
    goto v_30800;
v_30796:
    v_30839 = stack[-2];
    goto v_30797;
v_30798:
    v_30838 = stack[-3];
    v_30838 = qcdr(v_30838);
    goto v_30799;
v_30800:
    goto v_30796;
v_30797:
    goto v_30798;
v_30799:
    v_30838 = Lnconc(nil, v_30839, v_30838);
    env = stack[-5];
    stack[-4] = v_30838;
    v_30838 = nil;
    stack[-2] = v_30838;
    goto v_30810;
v_30806:
    v_30838 = stack[-3];
    v_30839 = qcar(v_30838);
    goto v_30807;
v_30808:
    v_30838 = stack[-1];
    goto v_30809;
v_30810:
    goto v_30806;
v_30807:
    goto v_30808;
v_30809:
    v_30838 = cons(v_30839, v_30838);
    env = stack[-5];
    stack[-1] = v_30838;
    goto v_30819;
v_30815:
    v_30838 = stack[-3];
    v_30839 = qcar(v_30838);
    goto v_30816;
v_30817:
    v_30838 = stack[0];
    goto v_30818;
v_30819:
    goto v_30815;
v_30816:
    goto v_30817;
v_30818:
    v_30838 = cons(v_30839, v_30838);
    env = stack[-5];
    stack[0] = v_30838;
    v_30838 = stack[-4];
    stack[-3] = v_30838;
    goto v_30762;
v_30785:
    v_30838 = stack[-3];
    v_30838 = qcdr(v_30838);
    stack[-4] = v_30838;
    goto v_30833;
v_30829:
    v_30838 = stack[-3];
    v_30839 = qcar(v_30838);
    goto v_30830;
v_30831:
    v_30838 = stack[-2];
    goto v_30832;
v_30833:
    goto v_30829;
v_30830:
    goto v_30831;
v_30832:
    v_30838 = cons(v_30839, v_30838);
    env = stack[-5];
    stack[-2] = v_30838;
    v_30838 = stack[-4];
    stack[-3] = v_30838;
    goto v_30762;
v_30764:
    v_30838 = nil;
v_30761:
    return onevalue(v_30838);
}



// Code for dp!=comp

static LispObject CC_dpMcomp(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30795, v_30796;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30755;
    stack[-1] = v_30754;
// end of prologue
    stack[-2] = nil;
v_30760:
    v_30795 = stack[0];
    if (v_30795 == nil) goto v_30763;
    else goto v_30764;
v_30763:
    v_30795 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_30795);
    }
v_30764:
    goto v_30775;
v_30771:
    v_30795 = stack[0];
    fn = elt(env, 2); // dp_lmon
    v_30795 = (*qfn1(fn))(fn, v_30795);
    env = stack[-3];
    fn = elt(env, 3); // mo_comp
    v_30796 = (*qfn1(fn))(fn, v_30795);
    env = stack[-3];
    goto v_30772;
v_30773:
    v_30795 = stack[-1];
    goto v_30774;
v_30775:
    goto v_30771;
v_30772:
    goto v_30773;
v_30774:
    v_30795 = Leqn(nil, v_30796, v_30795);
    env = stack[-3];
    if (v_30795 == nil) goto v_30769;
    goto v_30785;
v_30781:
    v_30795 = stack[0];
    v_30796 = qcar(v_30795);
    goto v_30782;
v_30783:
    v_30795 = stack[-2];
    goto v_30784;
v_30785:
    goto v_30781;
v_30782:
    goto v_30783;
v_30784:
    v_30795 = cons(v_30796, v_30795);
    env = stack[-3];
    stack[-2] = v_30795;
    v_30795 = stack[0];
    v_30795 = qcdr(v_30795);
    stack[0] = v_30795;
    goto v_30760;
v_30769:
    v_30795 = stack[0];
    v_30795 = qcdr(v_30795);
    stack[0] = v_30795;
    goto v_30760;
    v_30795 = nil;
    return onevalue(v_30795);
}



// Code for simp!-prop!-form

static LispObject CC_simpKpropKform(LispObject env,
                         LispObject v_30754)
{
    env = qenv(env);
    LispObject v_31046, v_31047, v_31048;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30754);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    v_31047 = v_30754;
// end of prologue
    goto v_30764;
v_30760:
    v_31048 = v_31047;
    goto v_30761;
v_30762:
    v_31046 = elt(env, 1); // (nil)
    goto v_30763;
v_30764:
    goto v_30760;
v_30761:
    goto v_30762;
v_30763:
    if (equal(v_31048, v_31046)) goto v_30758;
    else goto v_30759;
v_30758:
    v_31046 = qvalue(elt(env, 2)); // !'true
    goto v_30757;
v_30759:
    v_31046 = v_31047;
    stack[-7] = v_31046;
    v_31046 = stack[-7];
    if (v_31046 == nil) goto v_30779;
    else goto v_30780;
v_30779:
    v_31046 = nil;
    goto v_30774;
v_30780:
    v_31046 = stack[-7];
    v_31046 = qcar(v_31046);
    stack[-3] = v_31046;
    v_31046 = stack[-3];
    if (v_31046 == nil) goto v_30796;
    else goto v_30797;
v_30796:
    v_31046 = nil;
    goto v_30791;
v_30797:
    v_31046 = stack[-3];
    v_31046 = qcar(v_31046);
    v_31048 = v_31046;
    goto v_30813;
v_30809:
    v_31047 = v_31048;
    goto v_30810;
v_30811:
    v_31046 = elt(env, 3); // not_prop!*
    goto v_30812;
v_30813:
    goto v_30809;
v_30810:
    goto v_30811;
v_30812:
    if (!consp(v_31047)) goto v_30807;
    v_31047 = qcar(v_31047);
    if (v_31047 == v_31046) goto v_30806;
    else goto v_30807;
v_30806:
    goto v_30821;
v_30817:
    v_31046 = elt(env, 4); // not
    goto v_30818;
v_30819:
    v_31047 = v_31048;
    v_31047 = qcdr(v_31047);
    v_31047 = qcar(v_31047);
    goto v_30820;
v_30821:
    goto v_30817;
v_30818:
    goto v_30819;
v_30820:
    v_31046 = list2(v_31046, v_31047);
    env = stack[-8];
    goto v_30805;
v_30807:
    v_31046 = v_31048;
    v_31046 = qcdr(v_31046);
    v_31046 = qcar(v_31046);
    goto v_30805;
    v_31046 = nil;
v_30805:
    v_31046 = ncons(v_31046);
    env = stack[-8];
    stack[-1] = v_31046;
    stack[-2] = v_31046;
v_30792:
    v_31046 = stack[-3];
    v_31046 = qcdr(v_31046);
    stack[-3] = v_31046;
    v_31046 = stack[-3];
    if (v_31046 == nil) goto v_30835;
    else goto v_30836;
v_30835:
    v_31046 = stack[-2];
    goto v_30791;
v_30836:
    goto v_30844;
v_30840:
    stack[0] = stack[-1];
    goto v_30841;
v_30842:
    v_31046 = stack[-3];
    v_31046 = qcar(v_31046);
    v_31048 = v_31046;
    goto v_30859;
v_30855:
    v_31047 = v_31048;
    goto v_30856;
v_30857:
    v_31046 = elt(env, 3); // not_prop!*
    goto v_30858;
v_30859:
    goto v_30855;
v_30856:
    goto v_30857;
v_30858:
    if (!consp(v_31047)) goto v_30853;
    v_31047 = qcar(v_31047);
    if (v_31047 == v_31046) goto v_30852;
    else goto v_30853;
v_30852:
    goto v_30867;
v_30863:
    v_31046 = elt(env, 4); // not
    goto v_30864;
v_30865:
    v_31047 = v_31048;
    v_31047 = qcdr(v_31047);
    v_31047 = qcar(v_31047);
    goto v_30866;
v_30867:
    goto v_30863;
v_30864:
    goto v_30865;
v_30866:
    v_31046 = list2(v_31046, v_31047);
    env = stack[-8];
    goto v_30851;
v_30853:
    v_31046 = v_31048;
    v_31046 = qcdr(v_31046);
    v_31046 = qcar(v_31046);
    goto v_30851;
    v_31046 = nil;
v_30851:
    v_31046 = ncons(v_31046);
    env = stack[-8];
    goto v_30843;
v_30844:
    goto v_30840;
v_30841:
    goto v_30842;
v_30843:
    v_31046 = Lrplacd(nil, stack[0], v_31046);
    env = stack[-8];
    v_31046 = stack[-1];
    v_31046 = qcdr(v_31046);
    stack[-1] = v_31046;
    goto v_30792;
v_30791:
    v_31047 = v_31046;
    v_31047 = qcdr(v_31047);
    if (v_31047 == nil) goto v_30882;
    goto v_30890;
v_30886:
    v_31047 = qvalue(elt(env, 5)); // !'and
    goto v_30887;
v_30888:
    goto v_30889;
v_30890:
    goto v_30886;
v_30887:
    goto v_30888;
v_30889:
    v_31046 = cons(v_31047, v_31046);
    env = stack[-8];
    goto v_30880;
v_30882:
    v_31046 = qcar(v_31046);
    goto v_30880;
    v_31046 = nil;
v_30880:
    v_31046 = ncons(v_31046);
    env = stack[-8];
    stack[-5] = v_31046;
    stack[-6] = v_31046;
v_30775:
    v_31046 = stack[-7];
    v_31046 = qcdr(v_31046);
    stack[-7] = v_31046;
    v_31046 = stack[-7];
    if (v_31046 == nil) goto v_30901;
    else goto v_30902;
v_30901:
    v_31046 = stack[-6];
    goto v_30774;
v_30902:
    goto v_30910;
v_30906:
    stack[-4] = stack[-5];
    goto v_30907;
v_30908:
    v_31046 = stack[-7];
    v_31046 = qcar(v_31046);
    stack[-3] = v_31046;
    v_31046 = stack[-3];
    if (v_31046 == nil) goto v_30925;
    else goto v_30926;
v_30925:
    v_31046 = nil;
    goto v_30920;
v_30926:
    v_31046 = stack[-3];
    v_31046 = qcar(v_31046);
    v_31048 = v_31046;
    goto v_30942;
v_30938:
    v_31047 = v_31048;
    goto v_30939;
v_30940:
    v_31046 = elt(env, 3); // not_prop!*
    goto v_30941;
v_30942:
    goto v_30938;
v_30939:
    goto v_30940;
v_30941:
    if (!consp(v_31047)) goto v_30936;
    v_31047 = qcar(v_31047);
    if (v_31047 == v_31046) goto v_30935;
    else goto v_30936;
v_30935:
    goto v_30950;
v_30946:
    v_31046 = elt(env, 4); // not
    goto v_30947;
v_30948:
    v_31047 = v_31048;
    v_31047 = qcdr(v_31047);
    v_31047 = qcar(v_31047);
    goto v_30949;
v_30950:
    goto v_30946;
v_30947:
    goto v_30948;
v_30949:
    v_31046 = list2(v_31046, v_31047);
    env = stack[-8];
    goto v_30934;
v_30936:
    v_31046 = v_31048;
    v_31046 = qcdr(v_31046);
    v_31046 = qcar(v_31046);
    goto v_30934;
    v_31046 = nil;
v_30934:
    v_31046 = ncons(v_31046);
    env = stack[-8];
    stack[-1] = v_31046;
    stack[-2] = v_31046;
v_30921:
    v_31046 = stack[-3];
    v_31046 = qcdr(v_31046);
    stack[-3] = v_31046;
    v_31046 = stack[-3];
    if (v_31046 == nil) goto v_30964;
    else goto v_30965;
v_30964:
    v_31046 = stack[-2];
    goto v_30920;
v_30965:
    goto v_30973;
v_30969:
    stack[0] = stack[-1];
    goto v_30970;
v_30971:
    v_31046 = stack[-3];
    v_31046 = qcar(v_31046);
    v_31048 = v_31046;
    goto v_30988;
v_30984:
    v_31047 = v_31048;
    goto v_30985;
v_30986:
    v_31046 = elt(env, 3); // not_prop!*
    goto v_30987;
v_30988:
    goto v_30984;
v_30985:
    goto v_30986;
v_30987:
    if (!consp(v_31047)) goto v_30982;
    v_31047 = qcar(v_31047);
    if (v_31047 == v_31046) goto v_30981;
    else goto v_30982;
v_30981:
    goto v_30996;
v_30992:
    v_31046 = elt(env, 4); // not
    goto v_30993;
v_30994:
    v_31047 = v_31048;
    v_31047 = qcdr(v_31047);
    v_31047 = qcar(v_31047);
    goto v_30995;
v_30996:
    goto v_30992;
v_30993:
    goto v_30994;
v_30995:
    v_31046 = list2(v_31046, v_31047);
    env = stack[-8];
    goto v_30980;
v_30982:
    v_31046 = v_31048;
    v_31046 = qcdr(v_31046);
    v_31046 = qcar(v_31046);
    goto v_30980;
    v_31046 = nil;
v_30980:
    v_31046 = ncons(v_31046);
    env = stack[-8];
    goto v_30972;
v_30973:
    goto v_30969;
v_30970:
    goto v_30971;
v_30972:
    v_31046 = Lrplacd(nil, stack[0], v_31046);
    env = stack[-8];
    v_31046 = stack[-1];
    v_31046 = qcdr(v_31046);
    stack[-1] = v_31046;
    goto v_30921;
v_30920:
    v_31047 = v_31046;
    v_31047 = qcdr(v_31047);
    if (v_31047 == nil) goto v_31011;
    goto v_31019;
v_31015:
    v_31047 = qvalue(elt(env, 5)); // !'and
    goto v_31016;
v_31017:
    goto v_31018;
v_31019:
    goto v_31015;
v_31016:
    goto v_31017;
v_31018:
    v_31046 = cons(v_31047, v_31046);
    env = stack[-8];
    goto v_31009;
v_31011:
    v_31046 = qcar(v_31046);
    goto v_31009;
    v_31046 = nil;
v_31009:
    v_31046 = ncons(v_31046);
    env = stack[-8];
    goto v_30909;
v_30910:
    goto v_30906;
v_30907:
    goto v_30908;
v_30909:
    v_31046 = Lrplacd(nil, stack[-4], v_31046);
    env = stack[-8];
    v_31046 = stack[-5];
    v_31046 = qcdr(v_31046);
    stack[-5] = v_31046;
    goto v_30775;
v_30774:
    v_31047 = v_31046;
    v_31046 = v_31047;
    v_31046 = qcdr(v_31046);
    if (v_31046 == nil) goto v_31031;
    goto v_31039;
v_31035:
    v_31046 = qvalue(elt(env, 6)); // !'or
    goto v_31036;
v_31037:
    goto v_31038;
v_31039:
    goto v_31035;
v_31036:
    goto v_31037;
v_31038:
    return cons(v_31046, v_31047);
v_31031:
    v_31046 = v_31047;
    v_31046 = qcar(v_31046);
    goto v_31029;
    v_31046 = nil;
v_31029:
    goto v_30757;
    v_31046 = nil;
v_30757:
    return onevalue(v_31046);
}



// Code for can_rep_cell

static LispObject CC_can_rep_cell(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30775, v_30776, v_30777;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30777 = v_30755;
    v_30775 = v_30754;
// end of prologue
    goto v_30761;
v_30757:
    goto v_30766;
v_30762:
    v_30775 = qcdr(v_30775);
    v_30776 = qcar(v_30775);
    goto v_30763;
v_30764:
    v_30775 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30765;
v_30766:
    goto v_30762;
v_30763:
    goto v_30764;
v_30765:
    stack[0] = *(LispObject *)((char *)v_30776 + (CELL-TAG_VECTOR) + (((intptr_t)v_30775-TAG_FIXNUM)/(16/CELL)));
    goto v_30758;
v_30759:
    v_30775 = v_30777;
    v_30775 = sub1(v_30775);
    goto v_30760;
v_30761:
    goto v_30757;
v_30758:
    goto v_30759;
v_30760:
    v_30775 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_30775-TAG_FIXNUM)/(16/CELL)));
    return onevalue(v_30775);
}



// Code for simpdot

static LispObject CC_simpdot(LispObject env,
                         LispObject v_30754)
{
    env = qenv(env);
    LispObject v_30764, v_30765;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30764 = v_30754;
// end of prologue
    goto v_30761;
v_30757:
    v_30765 = v_30764;
    goto v_30758;
v_30759:
    v_30764 = elt(env, 1); // dotord
    goto v_30760;
v_30761:
    goto v_30757;
v_30758:
    goto v_30759;
v_30760:
    {
        fn = elt(env, 2); // mkvarg
        return (*qfn2(fn))(fn, v_30765, v_30764);
    }
}



// Code for texexplode

static LispObject CC_texexplode(LispObject env,
                         LispObject v_30754)
{
    env = qenv(env);
    LispObject v_30828, v_30829, v_30830;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30754);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_30829 = v_30754;
// end of prologue
    v_30828 = v_30829;
    if (v_30828 == nil) goto v_30762;
    v_30828 = v_30829;
    if (!consp(v_30828)) goto v_30765;
    else goto v_30762;
v_30765:
    goto v_30778;
v_30774:
    v_30830 = v_30829;
    goto v_30775;
v_30776:
    v_30828 = elt(env, 1); // texname
    goto v_30777;
v_30778:
    goto v_30774;
v_30775:
    goto v_30776;
v_30777:
    v_30828 = get(v_30830, v_30828);
    env = stack[0];
    if (v_30828 == nil) goto v_30772;
    else goto v_30771;
v_30772:
    v_30828 = v_30829;
    if (!symbolp(v_30828)) v_30828 = nil;
    else { v_30828 = qfastgets(v_30828);
           if (v_30828 != nil) { v_30828 = elt(v_30828, 7); // class
#ifdef RECORD_GET
             if (v_30828 != SPID_NOPROP)
                record_get(elt(fastget_names, 7), 1);
             else record_get(elt(fastget_names, 7), 0),
                v_30828 = nil; }
           else record_get(elt(fastget_names, 7), 0); }
#else
             if (v_30828 == SPID_NOPROP) v_30828 = nil; }}
#endif
    if (v_30828 == nil) goto v_30783;
    else goto v_30784;
v_30783:
    v_30828 = nil;
    goto v_30782;
v_30784:
    v_30828 = v_30829;
    goto v_30782;
    v_30828 = nil;
v_30782:
v_30771:
    if (v_30828 == nil) goto v_30769;
    else goto v_30768;
v_30769:
    v_30828 = v_30829;
    if (is_number(v_30828)) goto v_30793;
    else goto v_30794;
v_30793:
    v_30828 = v_30829;
    v_30828 = Lexplode(nil, v_30828);
    env = stack[0];
    fn = elt(env, 3); // texcollect
    v_30828 = (*qfn1(fn))(fn, v_30828);
    env = stack[0];
    goto v_30792;
v_30794:
    v_30828 = v_30829;
    v_30828 = Lstringp(nil, v_30828);
    env = stack[0];
    if (v_30828 == nil) goto v_30800;
    v_30828 = v_30829;
    v_30828 = Lexplodec(nil, v_30828);
    env = stack[0];
    fn = elt(env, 4); // strcollect
    v_30828 = (*qfn1(fn))(fn, v_30828);
    env = stack[0];
    goto v_30792;
v_30800:
    v_30828 = v_30829;
    v_30828 = Lexplodec(nil, v_30828);
    env = stack[0];
    fn = elt(env, 3); // texcollect
    v_30828 = (*qfn1(fn))(fn, v_30828);
    env = stack[0];
    fn = elt(env, 5); // texexplist
    v_30828 = (*qfn1(fn))(fn, v_30828);
    env = stack[0];
    goto v_30792;
    v_30828 = nil;
v_30792:
v_30768:
    goto v_30760;
v_30762:
    v_30828 = nil;
v_30760:
    v_30829 = v_30828;
    v_30828 = v_30829;
    if (v_30828 == nil) goto v_30814;
    else goto v_30815;
v_30814:
    v_30828 = elt(env, 2); // ! 
    return ncons(v_30828);
v_30815:
    v_30828 = v_30829;
    if (!consp(v_30828)) goto v_30820;
    v_30828 = v_30829;
    goto v_30813;
v_30820:
    v_30828 = v_30829;
    return ncons(v_30828);
    v_30828 = nil;
v_30813:
    v_30829 = v_30828;
    v_30828 = v_30829;
    return onevalue(v_30828);
}



// Code for gigcd!:

static LispObject CC_gigcdT(LispObject env,
                         LispObject v_30754, LispObject v_30755)
{
    env = qenv(env);
    LispObject v_30781, v_30782;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_30755,v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_30754,v_30755);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_30755;
    stack[-1] = v_30754;
// end of prologue
v_30760:
    v_30781 = stack[0];
    fn = elt(env, 1); // gizerop!:
    v_30781 = (*qfn1(fn))(fn, v_30781);
    env = stack[-3];
    if (v_30781 == nil) goto v_30764;
    v_30781 = stack[-1];
    {
        fn = elt(env, 2); // fqa
        return (*qfn1(fn))(fn, v_30781);
    }
v_30764:
    v_30781 = stack[0];
    stack[-2] = v_30781;
    goto v_30777;
v_30773:
    v_30782 = stack[-1];
    goto v_30774;
v_30775:
    v_30781 = stack[0];
    goto v_30776;
v_30777:
    goto v_30773;
v_30774:
    goto v_30775;
v_30776:
    fn = elt(env, 3); // giremainder
    v_30781 = (*qfn2(fn))(fn, v_30782, v_30781);
    env = stack[-3];
    stack[0] = v_30781;
    v_30781 = stack[-2];
    stack[-1] = v_30781;
    goto v_30760;
    v_30781 = nil;
    return onevalue(v_30781);
}



// Code for simp!-sign2

static LispObject CC_simpKsign2(LispObject env,
                         LispObject v_30754)
{
    env = qenv(env);
    LispObject v_30783, v_30784;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_30754);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_30754);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_30754;
// end of prologue
    v_30783 = stack[0];
    fn = elt(env, 2); // rd!-sign
    v_30783 = (*qfn1(fn))(fn, v_30783);
    env = stack[-1];
    v_30784 = v_30783;
    v_30783 = v_30784;
    if (v_30783 == nil) goto v_30762;
    goto v_30769;
v_30765:
    goto v_30766;
v_30767:
    v_30783 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_30768;
v_30769:
    goto v_30765;
v_30766:
    goto v_30767;
v_30768:
    return cons(v_30784, v_30783);
v_30762:
    goto v_30780;
v_30776:
    v_30784 = elt(env, 1); // sign
    goto v_30777;
v_30778:
    v_30783 = stack[0];
    goto v_30779;
v_30780:
    goto v_30776;
v_30777:
    goto v_30778;
v_30779:
    v_30783 = list2(v_30784, v_30783);
    env = stack[-1];
    {
        fn = elt(env, 3); // simpiden
        return (*qfn1(fn))(fn, v_30783);
    }
    v_30783 = nil;
    return onevalue(v_30783);
}



setup_type const u51_setup[] =
{
    {"constructinvolutivebasis",TOO_FEW_2,      CC_constructinvolutivebasis,WRONG_NO_2},
    {"ofsf_sminsert1",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_sminsert1},
    {"talp_cocc",               TOO_FEW_2,      CC_talp_cocc,  WRONG_NO_2},
    {"qqe_length-graph-neighbors",CC_qqe_lengthKgraphKneighbors,TOO_MANY_1,WRONG_NO_1},
    {"pasf_smordtable2",        TOO_FEW_2,      CC_pasf_smordtable2,WRONG_NO_2},
    {"ldf-sep-var",             CC_ldfKsepKvar, TOO_MANY_1,    WRONG_NO_1},
    {"dipreplus",               CC_dipreplus,   TOO_MANY_1,    WRONG_NO_1},
    {"make_wedge_pair",         TOO_FEW_2,      CC_make_wedge_pair,WRONG_NO_2},
    {"gpexpp",                  CC_gpexpp,      TOO_MANY_1,    WRONG_NO_1},
    {"rule-list",               TOO_FEW_2,      CC_ruleKlist,  WRONG_NO_2},
    {"even_action_pow",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_even_action_pow},
    {"ofsf_canegrel",           TOO_FEW_2,      CC_ofsf_canegrel,WRONG_NO_2},
    {"*multsq",                 TOO_FEW_2,      CC_Hmultsq,    WRONG_NO_2},
    {"taymindegreel",           TOO_FEW_2,      CC_taymindegreel,WRONG_NO_2},
    {"qqe_length-graph-marked", CC_qqe_lengthKgraphKmarked,TOO_MANY_1,WRONG_NO_1},
    {"cl_susimkatl",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_susimkatl},
    {"ofsf_boundchk",           TOO_FEW_2,      CC_ofsf_boundchk,WRONG_NO_2},
    {"latexprint",              CC_latexprint,  TOO_MANY_1,    WRONG_NO_1},
    {"gbftimes",                TOO_FEW_2,      CC_gbftimes,   WRONG_NO_2},
    {"is_buble",                TOO_FEW_2,      CC_is_buble,   WRONG_NO_2},
    {"tidysqrtf",               CC_tidysqrtf,   TOO_MANY_1,    WRONG_NO_1},
    {"smt_prin2x",              CC_smt_prin2x,  TOO_MANY_1,    WRONG_NO_1},
    {"xadd*",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xaddH},
    {"vdpfmon",                 TOO_FEW_2,      CC_vdpfmon,    WRONG_NO_2},
    {"xexptpf",                 TOO_FEW_2,      CC_xexptpf,    WRONG_NO_2},
    {"decimal2internal",        TOO_FEW_2,      CC_decimal2internal,WRONG_NO_2},
    {"mk-contract-coeff",       CC_mkKcontractKcoeff,TOO_MANY_1,WRONG_NO_1},
    {"hdiff",                   TOO_FEW_2,      CC_hdiff,      WRONG_NO_2},
    {"test-bool",               CC_testKbool,   TOO_MANY_1,    WRONG_NO_1},
    {"combin",                  TOO_FEW_2,      CC_combin,     WRONG_NO_2},
    {"coeffs-to-form1",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_coeffsKtoKform1},
    {"qroundup",                TOO_FEW_2,      CC_qroundup,   WRONG_NO_2},
    {"ofsf_smwrmknowl",         TOO_FEW_2,      CC_ofsf_smwrmknowl,WRONG_NO_2},
    {"eval-yetunknowntypeexpr", TOO_FEW_2,      CC_evalKyetunknowntypeexpr,WRONG_NO_2},
    {"quotf*",                  TOO_FEW_2,      CC_quotfH,     WRONG_NO_2},
    {"ldf-spf-var",             CC_ldfKspfKvar, TOO_MANY_1,    WRONG_NO_1},
    {"al1_defined_vertex",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_al1_defined_vertex},
    {"dp=comp",                 TOO_FEW_2,      CC_dpMcomp,    WRONG_NO_2},
    {"simp-prop-form",          CC_simpKpropKform,TOO_MANY_1,  WRONG_NO_1},
    {"can_rep_cell",            TOO_FEW_2,      CC_can_rep_cell,WRONG_NO_2},
    {"simpdot",                 CC_simpdot,     TOO_MANY_1,    WRONG_NO_1},
    {"texexplode",              CC_texexplode,  TOO_MANY_1,    WRONG_NO_1},
    {"gigcd:",                  TOO_FEW_2,      CC_gigcdT,     WRONG_NO_2},
    {"simp-sign2",              CC_simpKsign2,  TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u51", (two_args *)"103174 4598682 9268978", 0}
};

// end of generated code
