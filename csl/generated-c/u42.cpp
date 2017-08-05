
// $destdir/u42.c        Machine generated C code

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



// Code for mk_binding

static LispObject CC_mk_binding(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23827, v_23828;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23799,v_23800);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_23800;
    stack[-1] = v_23799;
// end of prologue
    goto v_23811;
v_23807:
    v_23827 = stack[-1];
    v_23828 = qcar(v_23827);
    goto v_23808;
v_23809:
    v_23827 = stack[0];
    goto v_23810;
v_23811:
    goto v_23807;
v_23808:
    goto v_23809;
v_23810:
    fn = elt(env, 1); // can_be_proved
    v_23827 = (*qfn2(fn))(fn, v_23828, v_23827);
    env = stack[-2];
    if (v_23827 == nil) goto v_23804;
    else goto v_23805;
v_23804:
    v_23827 = nil;
    goto v_23803;
v_23805:
    goto v_23823;
v_23819:
    v_23827 = stack[-1];
    v_23828 = qcdr(v_23827);
    goto v_23820;
v_23821:
    v_23827 = stack[0];
    goto v_23822;
v_23823:
    goto v_23819;
v_23820:
    goto v_23821;
v_23822:
    {
        fn = elt(env, 2); // edge_bind
        return (*qfn2(fn))(fn, v_23828, v_23827);
    }
    v_23827 = nil;
v_23803:
    return onevalue(v_23827);
}



// Code for ratnump

static LispObject CC_ratnump(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_23831, v_23832, v_23833;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23799);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_23831 = v_23799;
// end of prologue
    fn = elt(env, 2); // simp!*
    v_23832 = (*qfn1(fn))(fn, v_23831);
    env = stack[0];
    v_23831 = v_23832;
    v_23832 = qcar(v_23832);
    if (!consp(v_23832)) goto v_23807;
    else goto v_23808;
v_23807:
    v_23832 = lisp_true;
    goto v_23806;
v_23808:
    goto v_23819;
v_23815:
    v_23832 = v_23831;
    v_23832 = qcar(v_23832);
    v_23832 = qcar(v_23832);
    goto v_23816;
v_23817:
    v_23833 = elt(env, 1); // !:rn!:
    goto v_23818;
v_23819:
    goto v_23815;
v_23816:
    goto v_23817;
v_23818:
    v_23832 = (v_23832 == v_23833 ? lisp_true : nil);
    goto v_23806;
    v_23832 = nil;
v_23806:
    if (v_23832 == nil) goto v_23804;
    v_23831 = qcdr(v_23831);
    v_23831 = (consp(v_23831) ? nil : lisp_true);
    goto v_23802;
v_23804:
    v_23831 = nil;
    goto v_23802;
    v_23831 = nil;
v_23802:
    return onevalue(v_23831);
}



// Code for miller!-rabin

static LispObject CC_millerKrabin(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23981, v_23982;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23799,v_23800);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_23800;
    stack[0] = v_23799;
// end of prologue
    goto v_23816;
v_23812:
    v_23982 = stack[-2];
    goto v_23813;
v_23814:
    v_23981 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23815;
v_23816:
    goto v_23812;
v_23813:
    goto v_23814;
v_23815:
    if (v_23982 == v_23981) goto v_23810;
    else goto v_23811;
v_23810:
    v_23981 = nil;
    goto v_23806;
v_23811:
    goto v_23826;
v_23822:
    goto v_23832;
v_23828:
    v_23982 = stack[-2];
    goto v_23829;
v_23830:
    v_23981 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_23831;
v_23832:
    goto v_23828;
v_23829:
    goto v_23830;
v_23831:
    v_23982 = Cremainder(v_23982, v_23981);
    env = stack[-4];
    goto v_23823;
v_23824:
    v_23981 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23825;
v_23826:
    goto v_23822;
v_23823:
    goto v_23824;
v_23825:
    if (v_23982 == v_23981) goto v_23820;
    else goto v_23821;
v_23820:
    goto v_23840;
v_23836:
    v_23982 = stack[-2];
    goto v_23837;
v_23838:
    v_23981 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_23839;
v_23840:
    goto v_23836;
v_23837:
    goto v_23838;
v_23839:
    v_23981 = (v_23982 == v_23981 ? lisp_true : nil);
    goto v_23806;
v_23821:
    goto v_23851;
v_23847:
    v_23982 = stack[-2];
    goto v_23848;
v_23849:
    v_23981 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_23850;
v_23851:
    goto v_23847;
v_23848:
    goto v_23849;
v_23850:
    v_23981 = (LispObject)lesseq2(v_23982, v_23981);
    v_23981 = v_23981 ? lisp_true : nil;
    env = stack[-4];
    if (v_23981 == nil) goto v_23845;
    v_23981 = lisp_true;
    goto v_23806;
v_23845:
    v_23981 = stack[-2];
    v_23981 = sub1(v_23981);
    env = stack[-4];
    stack[-1] = v_23981;
    v_23981 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_23981;
v_23860:
    goto v_23869;
v_23865:
    goto v_23875;
v_23871:
    v_23982 = stack[-1];
    goto v_23872;
v_23873:
    v_23981 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_23874;
v_23875:
    goto v_23871;
v_23872:
    goto v_23873;
v_23874:
    v_23982 = Cremainder(v_23982, v_23981);
    env = stack[-4];
    goto v_23866;
v_23867:
    v_23981 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23868;
v_23869:
    goto v_23865;
v_23866:
    goto v_23867;
v_23868:
    if (v_23982 == v_23981) goto v_23864;
    goto v_23859;
v_23864:
    goto v_23885;
v_23881:
    v_23982 = stack[-1];
    goto v_23882;
v_23883:
    v_23981 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_23884;
v_23885:
    goto v_23881;
v_23882:
    goto v_23883;
v_23884:
    v_23981 = quot2(v_23982, v_23981);
    env = stack[-4];
    stack[-1] = v_23981;
    v_23981 = stack[-3];
    v_23981 = add1(v_23981);
    env = stack[-4];
    stack[-3] = v_23981;
    goto v_23860;
v_23859:
    v_23981 = stack[-2];
    fn = elt(env, 1); // set!-modulus
    v_23981 = (*qfn1(fn))(fn, v_23981);
    env = stack[-4];
    goto v_23897;
v_23893:
    v_23982 = stack[0];
    goto v_23894;
v_23895:
    v_23981 = stack[-2];
    goto v_23896;
v_23897:
    goto v_23893;
v_23894:
    goto v_23895;
v_23896:
    v_23981 = Cremainder(v_23982, v_23981);
    env = stack[-4];
    stack[0] = v_23981;
    goto v_23905;
v_23901:
    v_23982 = stack[0];
    goto v_23902;
v_23903:
    v_23981 = stack[-1];
    goto v_23904;
v_23905:
    goto v_23901;
v_23902:
    goto v_23903;
v_23904:
    v_23981 = Lmodular_expt(nil, v_23982, v_23981);
    env = stack[-4];
    stack[-1] = v_23981;
    goto v_23920;
v_23916:
    v_23982 = stack[-1];
    goto v_23917;
v_23918:
    v_23981 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23919;
v_23920:
    goto v_23916;
v_23917:
    goto v_23918;
v_23919:
    if (v_23982 == v_23981) goto v_23914;
    else goto v_23915;
v_23914:
    v_23981 = lisp_true;
    goto v_23913;
v_23915:
    goto v_23930;
v_23926:
    stack[0] = stack[-1];
    goto v_23927;
v_23928:
    v_23981 = stack[-2];
    v_23981 = sub1(v_23981);
    env = stack[-4];
    goto v_23929;
v_23930:
    goto v_23926;
v_23927:
    goto v_23928;
v_23929:
    v_23981 = (equal(stack[0], v_23981) ? lisp_true : nil);
    goto v_23913;
    v_23981 = nil;
v_23913:
    if (v_23981 == nil) goto v_23911;
    v_23981 = lisp_true;
    goto v_23806;
v_23911:
v_23807:
    goto v_23944;
v_23940:
    v_23982 = stack[-3];
    goto v_23941;
v_23942:
    v_23981 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23943;
v_23944:
    goto v_23940;
v_23941:
    goto v_23942;
v_23943:
    if (v_23982 == v_23981) goto v_23938;
    else goto v_23939;
v_23938:
    v_23981 = nil;
    goto v_23806;
v_23939:
    goto v_23953;
v_23949:
    v_23982 = stack[-1];
    goto v_23950;
v_23951:
    v_23981 = stack[-1];
    goto v_23952;
v_23953:
    goto v_23949;
v_23950:
    goto v_23951;
v_23952:
    v_23981 = Lmodular_times(nil, v_23982, v_23981);
    env = stack[-4];
    stack[-1] = v_23981;
    goto v_23964;
v_23960:
    v_23982 = stack[-1];
    goto v_23961;
v_23962:
    v_23981 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23963;
v_23964:
    goto v_23960;
v_23961:
    goto v_23962;
v_23963:
    if (v_23982 == v_23981) goto v_23958;
    else goto v_23959;
v_23958:
    v_23981 = nil;
    goto v_23806;
v_23959:
    goto v_23974;
v_23970:
    stack[0] = stack[-1];
    goto v_23971;
v_23972:
    v_23981 = stack[-2];
    v_23981 = sub1(v_23981);
    env = stack[-4];
    goto v_23973;
v_23974:
    goto v_23970;
v_23971:
    goto v_23972;
v_23973:
    if (equal(stack[0], v_23981)) goto v_23968;
    else goto v_23969;
v_23968:
    v_23981 = lisp_true;
    goto v_23806;
v_23969:
    v_23981 = stack[-3];
    v_23981 = sub1(v_23981);
    env = stack[-4];
    stack[-3] = v_23981;
    goto v_23807;
v_23806:
    return onevalue(v_23981);
}



// Code for equiv!-coeffs

static LispObject CC_equivKcoeffs(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23881, v_23882;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23799,v_23800);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_23800;
    stack[-1] = v_23799;
// end of prologue
    stack[-2] = nil;
v_23805:
    v_23881 = stack[-1];
    if (v_23881 == nil) goto v_23808;
    else goto v_23809;
v_23808:
    goto v_23816;
v_23812:
    stack[-1] = stack[-2];
    goto v_23813;
v_23814:
    v_23881 = stack[0];
    v_23881 = Llength(nil, v_23881);
    env = stack[-3];
    fn = elt(env, 1); // nzeros
    v_23881 = (*qfn1(fn))(fn, v_23881);
    env = stack[-3];
    goto v_23815;
v_23816:
    goto v_23812;
v_23813:
    goto v_23814;
v_23815:
    {
        LispObject v_23886 = stack[-1];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_23886, v_23881);
    }
v_23809:
    v_23881 = stack[0];
    if (v_23881 == nil) goto v_23821;
    else goto v_23822;
v_23821:
    v_23881 = stack[-2];
    {
        fn = elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_23881);
    }
v_23822:
    goto v_23832;
v_23828:
    v_23881 = stack[-1];
    v_23881 = qcar(v_23881);
    v_23882 = qcar(v_23881);
    goto v_23829;
v_23830:
    v_23881 = stack[0];
    v_23881 = qcar(v_23881);
    v_23881 = qcar(v_23881);
    goto v_23831;
v_23832:
    goto v_23828;
v_23829:
    goto v_23830;
v_23831:
    if (equal(v_23882, v_23881)) goto v_23826;
    else goto v_23827;
v_23826:
    goto v_23844;
v_23840:
    v_23881 = stack[-1];
    v_23881 = qcar(v_23881);
    v_23882 = qcdr(v_23881);
    goto v_23841;
v_23842:
    v_23881 = stack[-2];
    goto v_23843;
v_23844:
    goto v_23840;
v_23841:
    goto v_23842;
v_23843:
    v_23881 = cons(v_23882, v_23881);
    env = stack[-3];
    stack[-2] = v_23881;
    v_23881 = stack[-1];
    v_23881 = qcdr(v_23881);
    stack[-1] = v_23881;
    v_23881 = stack[0];
    v_23881 = qcdr(v_23881);
    stack[0] = v_23881;
    goto v_23805;
v_23827:
    goto v_23860;
v_23856:
    v_23881 = stack[-1];
    v_23881 = qcar(v_23881);
    v_23882 = qcar(v_23881);
    goto v_23857;
v_23858:
    v_23881 = stack[0];
    v_23881 = qcar(v_23881);
    v_23881 = qcar(v_23881);
    goto v_23859;
v_23860:
    goto v_23856;
v_23857:
    goto v_23858;
v_23859:
    fn = elt(env, 3); // mv!-pow!-!>
    v_23881 = (*qfn2(fn))(fn, v_23882, v_23881);
    env = stack[-3];
    if (v_23881 == nil) goto v_23854;
    v_23881 = stack[-1];
    v_23881 = qcdr(v_23881);
    stack[-1] = v_23881;
    goto v_23805;
v_23854:
    goto v_23876;
v_23872:
    v_23882 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23873;
v_23874:
    v_23881 = stack[-2];
    goto v_23875;
v_23876:
    goto v_23872;
v_23873:
    goto v_23874;
v_23875:
    v_23881 = cons(v_23882, v_23881);
    env = stack[-3];
    stack[-2] = v_23881;
    v_23881 = stack[0];
    v_23881 = qcdr(v_23881);
    stack[0] = v_23881;
    goto v_23805;
    v_23881 = nil;
    return onevalue(v_23881);
}



// Code for !*g2lex

static LispObject CC_Hg2lex(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_23840, v_23841;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23799);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_23840 = v_23799;
// end of prologue
    v_23841 = nil;
    stack[-1] = v_23840;
v_23807:
    v_23840 = stack[-1];
    if (v_23840 == nil) goto v_23811;
    else goto v_23812;
v_23811:
    goto v_23806;
v_23812:
    v_23840 = stack[-1];
    v_23840 = qcar(v_23840);
    goto v_23823;
v_23819:
    stack[0] = v_23841;
    goto v_23820;
v_23821:
    goto v_23831;
v_23827:
    v_23841 = v_23840;
    v_23841 = qcar(v_23841);
    v_23841 = qcdr(v_23841);
    goto v_23828;
v_23829:
    v_23840 = qcdr(v_23840);
    goto v_23830;
v_23831:
    goto v_23827;
v_23828:
    goto v_23829;
v_23830:
    v_23840 = cons(v_23841, v_23840);
    env = stack[-2];
    v_23840 = ncons(v_23840);
    env = stack[-2];
    goto v_23822;
v_23823:
    goto v_23819;
v_23820:
    goto v_23821;
v_23822:
    fn = elt(env, 1); // psum
    v_23840 = (*qfn2(fn))(fn, stack[0], v_23840);
    env = stack[-2];
    v_23841 = v_23840;
    v_23840 = stack[-1];
    v_23840 = qcdr(v_23840);
    stack[-1] = v_23840;
    goto v_23807;
v_23806:
    v_23840 = v_23841;
    return onevalue(v_23840);
}



// Code for isimp1

static LispObject CC_isimp1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23975, v_23976, v_23977, v_23978, v_23979;
    LispObject fn;
    LispObject v_23803, v_23802, v_23801, v_23800, v_23799;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "isimp1");
    va_start(aa, nargs);
    v_23799 = va_arg(aa, LispObject);
    v_23800 = va_arg(aa, LispObject);
    v_23801 = va_arg(aa, LispObject);
    v_23802 = va_arg(aa, LispObject);
    v_23803 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_23803,v_23802,v_23801,v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_23799,v_23800,v_23801,v_23802,v_23803);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[0] = v_23803;
    stack[-1] = v_23802;
    stack[-2] = v_23801;
    stack[-3] = v_23800;
    stack[-4] = v_23799;
// end of prologue
    v_23975 = stack[-4];
    if (v_23975 == nil) goto v_23807;
    else goto v_23808;
v_23807:
    v_23975 = nil;
    goto v_23806;
v_23808:
    v_23975 = stack[-4];
    if (!consp(v_23975)) goto v_23815;
    else goto v_23816;
v_23815:
    v_23975 = lisp_true;
    goto v_23814;
v_23816:
    v_23975 = stack[-4];
    v_23975 = qcar(v_23975);
    v_23975 = (consp(v_23975) ? nil : lisp_true);
    goto v_23814;
    v_23975 = nil;
v_23814:
    if (v_23975 == nil) goto v_23812;
    v_23975 = stack[0];
    if (v_23975 == nil) goto v_23827;
    goto v_23834;
v_23830:
    goto v_23831;
v_23832:
    v_23975 = qvalue(elt(env, 1)); // !*cvit
    if (v_23975 == nil) goto v_23839;
    goto v_23850;
v_23842:
    v_23978 = stack[-3];
    goto v_23843;
v_23844:
    v_23977 = stack[-2];
    goto v_23845;
v_23846:
    v_23976 = stack[-1];
    goto v_23847;
v_23848:
    v_23975 = stack[0];
    goto v_23849;
v_23850:
    goto v_23842;
v_23843:
    goto v_23844;
v_23845:
    goto v_23846;
v_23847:
    goto v_23848;
v_23849:
    fn = elt(env, 2); // calc_spurx
    v_23975 = (*qfnn(fn))(fn, 4, v_23978, v_23977, v_23976, v_23975);
    env = stack[-6];
    goto v_23837;
v_23839:
    goto v_23868;
v_23858:
    v_23975 = stack[0];
    v_23979 = qcar(v_23975);
    goto v_23859;
v_23860:
    v_23978 = stack[-3];
    goto v_23861;
v_23862:
    v_23977 = stack[-2];
    goto v_23863;
v_23864:
    v_23976 = stack[-1];
    goto v_23865;
v_23866:
    v_23975 = stack[0];
    v_23975 = qcdr(v_23975);
    goto v_23867;
v_23868:
    goto v_23858;
v_23859:
    goto v_23860;
v_23861:
    goto v_23862;
v_23863:
    goto v_23864;
v_23865:
    goto v_23866;
v_23867:
    fn = elt(env, 3); // spur0
    v_23975 = (*qfnn(fn))(fn, 5, v_23979, v_23978, v_23977, v_23976, v_23975);
    env = stack[-6];
    goto v_23837;
    v_23975 = nil;
v_23837:
    goto v_23833;
v_23834:
    goto v_23830;
v_23831:
    goto v_23832;
v_23833:
    {
        LispObject v_23986 = stack[-4];
        fn = elt(env, 4); // multd
        return (*qfn2(fn))(fn, v_23986, v_23975);
    }
v_23827:
    v_23975 = stack[-2];
    if (v_23975 == nil) goto v_23877;
    goto v_23884;
v_23880:
    stack[0] = stack[-4];
    goto v_23881;
v_23882:
    goto v_23895;
v_23887:
    v_23978 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23888;
v_23889:
    v_23977 = stack[-3];
    goto v_23890;
v_23891:
    v_23976 = stack[-2];
    goto v_23892;
v_23893:
    v_23975 = stack[-1];
    goto v_23894;
v_23895:
    goto v_23887;
v_23888:
    goto v_23889;
v_23890:
    goto v_23891;
v_23892:
    goto v_23893;
v_23894:
    fn = elt(env, 5); // index_simp
    v_23975 = (*qfnn(fn))(fn, 4, v_23978, v_23977, v_23976, v_23975);
    env = stack[-6];
    goto v_23883;
v_23884:
    goto v_23880;
v_23881:
    goto v_23882;
v_23883:
    {
        LispObject v_23987 = stack[0];
        fn = elt(env, 4); // multd
        return (*qfn2(fn))(fn, v_23987, v_23975);
    }
v_23877:
    v_23975 = stack[-1];
    if (v_23975 == nil) goto v_23901;
    goto v_23908;
v_23904:
    v_23975 = stack[-1];
    fn = elt(env, 6); // emult
    stack[0] = (*qfn1(fn))(fn, v_23975);
    env = stack[-6];
    goto v_23905;
v_23906:
    goto v_23922;
v_23912:
    v_23979 = stack[-4];
    goto v_23913;
v_23914:
    v_23978 = stack[-3];
    goto v_23915;
v_23916:
    v_23977 = stack[-2];
    goto v_23917;
v_23918:
    v_23976 = nil;
    goto v_23919;
v_23920:
    v_23975 = nil;
    goto v_23921;
v_23922:
    goto v_23912;
v_23913:
    goto v_23914;
v_23915:
    goto v_23916;
v_23917:
    goto v_23918;
v_23919:
    goto v_23920;
v_23921:
    v_23975 = CC_isimp1(elt(env, 0), 5, v_23979, v_23978, v_23977, v_23976, v_23975);
    env = stack[-6];
    goto v_23907;
v_23908:
    goto v_23904;
v_23905:
    goto v_23906;
v_23907:
    {
        LispObject v_23988 = stack[0];
        fn = elt(env, 7); // multf
        return (*qfn2(fn))(fn, v_23988, v_23975);
    }
v_23901:
    v_23975 = stack[-4];
    goto v_23825;
    v_23975 = nil;
v_23825:
    goto v_23806;
v_23812:
    goto v_23938;
v_23934:
    goto v_23950;
v_23940:
    v_23975 = stack[-4];
    v_23979 = qcar(v_23975);
    goto v_23941;
v_23942:
    v_23978 = stack[-3];
    goto v_23943;
v_23944:
    v_23977 = stack[-2];
    goto v_23945;
v_23946:
    v_23976 = stack[-1];
    goto v_23947;
v_23948:
    v_23975 = stack[0];
    goto v_23949;
v_23950:
    goto v_23940;
v_23941:
    goto v_23942;
v_23943:
    goto v_23944;
v_23945:
    goto v_23946;
v_23947:
    goto v_23948;
v_23949:
    fn = elt(env, 8); // isimp2
    stack[-5] = (*qfnn(fn))(fn, 5, v_23979, v_23978, v_23977, v_23976, v_23975);
    env = stack[-6];
    goto v_23935;
v_23936:
    goto v_23968;
v_23958:
    v_23975 = stack[-4];
    v_23979 = qcdr(v_23975);
    goto v_23959;
v_23960:
    v_23978 = stack[-3];
    goto v_23961;
v_23962:
    v_23977 = stack[-2];
    goto v_23963;
v_23964:
    v_23976 = stack[-1];
    goto v_23965;
v_23966:
    v_23975 = stack[0];
    goto v_23967;
v_23968:
    goto v_23958;
v_23959:
    goto v_23960;
v_23961:
    goto v_23962;
v_23963:
    goto v_23964;
v_23965:
    goto v_23966;
v_23967:
    v_23975 = CC_isimp1(elt(env, 0), 5, v_23979, v_23978, v_23977, v_23976, v_23975);
    env = stack[-6];
    goto v_23937;
v_23938:
    goto v_23934;
v_23935:
    goto v_23936;
v_23937:
    {
        LispObject v_23989 = stack[-5];
        fn = elt(env, 9); // addf
        return (*qfn2(fn))(fn, v_23989, v_23975);
    }
    v_23975 = nil;
v_23806:
    return onevalue(v_23975);
}



// Code for drop_dec_with

static LispObject CC_drop_dec_with(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23906, v_23907, v_23908;
    LispObject v_23801, v_23800, v_23799;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "drop_dec_with");
    va_start(aa, nargs);
    v_23799 = va_arg(aa, LispObject);
    v_23800 = va_arg(aa, LispObject);
    v_23801 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_23801,v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_23799,v_23800,v_23801);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_23801;
    stack[-3] = v_23800;
    stack[-4] = v_23799;
// end of prologue
    stack[-5] = nil;
    v_23906 = stack[-2];
    if (v_23906 == nil) goto v_23811;
    goto v_23818;
v_23814:
    v_23907 = stack[-3];
    goto v_23815;
v_23816:
    v_23906 = elt(env, 1); // dec_with_rl
    goto v_23817;
v_23818:
    goto v_23814;
v_23815:
    goto v_23816;
v_23817:
    v_23906 = get(v_23907, v_23906);
    env = stack[-6];
    goto v_23809;
v_23811:
    goto v_23828;
v_23824:
    v_23907 = stack[-3];
    goto v_23825;
v_23826:
    v_23906 = elt(env, 2); // dec_with
    goto v_23827;
v_23828:
    goto v_23824;
v_23825:
    goto v_23826;
v_23827:
    v_23906 = get(v_23907, v_23906);
    env = stack[-6];
    goto v_23809;
    v_23906 = nil;
v_23809:
    stack[-1] = v_23906;
v_23834:
    v_23906 = stack[-1];
    if (v_23906 == nil) goto v_23838;
    else goto v_23839;
v_23838:
    goto v_23833;
v_23839:
    v_23906 = stack[-1];
    v_23906 = qcar(v_23906);
    stack[0] = v_23906;
    goto v_23850;
v_23846:
    v_23907 = stack[-4];
    goto v_23847;
v_23848:
    v_23906 = stack[0];
    goto v_23849;
v_23850:
    goto v_23846;
v_23847:
    goto v_23848;
v_23849:
    v_23906 = Ldelete(nil, v_23907, v_23906);
    env = stack[-6];
    stack[0] = v_23906;
    goto v_23862;
v_23858:
    v_23906 = stack[0];
    v_23907 = Llength(nil, v_23906);
    env = stack[-6];
    goto v_23859;
v_23860:
    v_23906 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23861;
v_23862:
    goto v_23858;
v_23859:
    goto v_23860;
v_23861:
    v_23906 = (LispObject)greaterp2(v_23907, v_23906);
    v_23906 = v_23906 ? lisp_true : nil;
    env = stack[-6];
    if (v_23906 == nil) goto v_23856;
    goto v_23871;
v_23867:
    v_23907 = stack[0];
    goto v_23868;
v_23869:
    v_23906 = stack[-5];
    goto v_23870;
v_23871:
    goto v_23867;
v_23868:
    goto v_23869;
v_23870:
    v_23906 = cons(v_23907, v_23906);
    env = stack[-6];
    stack[-5] = v_23906;
    goto v_23854;
v_23856:
v_23854:
    v_23906 = stack[-1];
    v_23906 = qcdr(v_23906);
    stack[-1] = v_23906;
    goto v_23834;
v_23833:
    v_23906 = stack[-2];
    if (v_23906 == nil) goto v_23880;
    goto v_23889;
v_23883:
    v_23908 = stack[-3];
    goto v_23884;
v_23885:
    v_23907 = elt(env, 1); // dec_with_rl
    goto v_23886;
v_23887:
    v_23906 = stack[-5];
    goto v_23888;
v_23889:
    goto v_23883;
v_23884:
    goto v_23885;
v_23886:
    goto v_23887;
v_23888:
    v_23906 = Lputprop(nil, 3, v_23908, v_23907, v_23906);
    goto v_23878;
v_23880:
    goto v_23902;
v_23896:
    v_23908 = stack[-3];
    goto v_23897;
v_23898:
    v_23907 = elt(env, 2); // dec_with
    goto v_23899;
v_23900:
    v_23906 = stack[-5];
    goto v_23901;
v_23902:
    goto v_23896;
v_23897:
    goto v_23898;
v_23899:
    goto v_23900;
v_23901:
    v_23906 = Lputprop(nil, 3, v_23908, v_23907, v_23906);
    goto v_23878;
v_23878:
    v_23906 = nil;
    return onevalue(v_23906);
}



// Code for cl_nnf1

static LispObject CC_cl_nnf1(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_24308, v_24309, v_24310;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23799,v_23800);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_23800;
    stack[-2] = v_23799;
// end of prologue
v_23798:
    v_24308 = stack[-2];
    if (!consp(v_24308)) goto v_23807;
    else goto v_23808;
v_23807:
    v_24308 = stack[-2];
    goto v_23806;
v_23808:
    v_24308 = stack[-2];
    v_24308 = qcar(v_24308);
    goto v_23806;
    v_24308 = nil;
v_23806:
    v_24310 = v_24308;
    goto v_23823;
v_23819:
    v_24309 = v_24310;
    goto v_23820;
v_23821:
    v_24308 = elt(env, 1); // not
    goto v_23822;
v_23823:
    goto v_23819;
v_23820:
    goto v_23821;
v_23822:
    if (v_24309 == v_24308) goto v_23817;
    else goto v_23818;
v_23817:
    goto v_23831;
v_23827:
    v_24308 = stack[-2];
    v_24308 = qcdr(v_24308);
    v_24309 = qcar(v_24308);
    goto v_23828;
v_23829:
    v_24308 = stack[-4];
    v_24308 = (v_24308 == nil ? lisp_true : nil);
    goto v_23830;
v_23831:
    goto v_23827;
v_23828:
    goto v_23829;
v_23830:
    stack[-2] = v_24309;
    stack[-4] = v_24308;
    goto v_23798;
v_23818:
    goto v_23845;
v_23841:
    v_24309 = v_24310;
    goto v_23842;
v_23843:
    v_24308 = elt(env, 2); // impl
    goto v_23844;
v_23845:
    goto v_23841;
v_23842:
    goto v_23843;
v_23844:
    if (v_24309 == v_24308) goto v_23839;
    else goto v_23840;
v_23839:
    goto v_23855;
v_23849:
    goto v_23861;
v_23857:
    v_24309 = elt(env, 3); // or
    goto v_23858;
v_23859:
    v_24308 = stack[-4];
    goto v_23860;
v_23861:
    goto v_23857;
v_23858:
    goto v_23859;
v_23860:
    fn = elt(env, 13); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_24309, v_24308);
    env = stack[-6];
    goto v_23850;
v_23851:
    goto v_23869;
v_23865:
    v_24308 = stack[-2];
    v_24308 = qcdr(v_24308);
    v_24309 = qcar(v_24308);
    goto v_23866;
v_23867:
    v_24308 = stack[-4];
    v_24308 = (v_24308 == nil ? lisp_true : nil);
    goto v_23868;
v_23869:
    goto v_23865;
v_23866:
    goto v_23867;
v_23868:
    stack[0] = CC_cl_nnf1(elt(env, 0), v_24309, v_24308);
    env = stack[-6];
    goto v_23852;
v_23853:
    goto v_23881;
v_23877:
    v_24308 = stack[-2];
    v_24308 = qcdr(v_24308);
    v_24308 = qcdr(v_24308);
    v_24309 = qcar(v_24308);
    goto v_23878;
v_23879:
    v_24308 = stack[-4];
    goto v_23880;
v_23881:
    goto v_23877;
v_23878:
    goto v_23879;
v_23880:
    v_24308 = CC_cl_nnf1(elt(env, 0), v_24309, v_24308);
    env = stack[-6];
    v_24308 = ncons(v_24308);
    goto v_23854;
v_23855:
    goto v_23849;
v_23850:
    goto v_23851;
v_23852:
    goto v_23853;
v_23854:
    {
        LispObject v_24317 = stack[-1];
        LispObject v_24318 = stack[0];
        return list2star(v_24317, v_24318, v_24308);
    }
v_23840:
    goto v_23895;
v_23891:
    v_24309 = v_24310;
    goto v_23892;
v_23893:
    v_24308 = elt(env, 4); // repl
    goto v_23894;
v_23895:
    goto v_23891;
v_23892:
    goto v_23893;
v_23894:
    if (v_24309 == v_24308) goto v_23889;
    else goto v_23890;
v_23889:
    goto v_23905;
v_23899:
    goto v_23911;
v_23907:
    v_24309 = elt(env, 3); // or
    goto v_23908;
v_23909:
    v_24308 = stack[-4];
    goto v_23910;
v_23911:
    goto v_23907;
v_23908:
    goto v_23909;
v_23910:
    fn = elt(env, 13); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_24309, v_24308);
    env = stack[-6];
    goto v_23900;
v_23901:
    goto v_23919;
v_23915:
    v_24308 = stack[-2];
    v_24308 = qcdr(v_24308);
    v_24309 = qcar(v_24308);
    goto v_23916;
v_23917:
    v_24308 = stack[-4];
    goto v_23918;
v_23919:
    goto v_23915;
v_23916:
    goto v_23917;
v_23918:
    stack[0] = CC_cl_nnf1(elt(env, 0), v_24309, v_24308);
    env = stack[-6];
    goto v_23902;
v_23903:
    goto v_23930;
v_23926:
    v_24308 = stack[-2];
    v_24308 = qcdr(v_24308);
    v_24308 = qcdr(v_24308);
    v_24309 = qcar(v_24308);
    goto v_23927;
v_23928:
    v_24308 = stack[-4];
    v_24308 = (v_24308 == nil ? lisp_true : nil);
    goto v_23929;
v_23930:
    goto v_23926;
v_23927:
    goto v_23928;
v_23929:
    v_24308 = CC_cl_nnf1(elt(env, 0), v_24309, v_24308);
    env = stack[-6];
    v_24308 = ncons(v_24308);
    goto v_23904;
v_23905:
    goto v_23899;
v_23900:
    goto v_23901;
v_23902:
    goto v_23903;
v_23904:
    {
        LispObject v_24319 = stack[-1];
        LispObject v_24320 = stack[0];
        return list2star(v_24319, v_24320, v_24308);
    }
v_23890:
    goto v_23945;
v_23941:
    v_24309 = v_24310;
    goto v_23942;
v_23943:
    v_24308 = elt(env, 5); // equiv
    goto v_23944;
v_23945:
    goto v_23941;
v_23942:
    goto v_23943;
v_23944:
    if (v_24309 == v_24308) goto v_23939;
    else goto v_23940;
v_23939:
    goto v_23955;
v_23949:
    goto v_23961;
v_23957:
    v_24309 = elt(env, 3); // or
    goto v_23958;
v_23959:
    v_24308 = stack[-4];
    goto v_23960;
v_23961:
    goto v_23957;
v_23958:
    goto v_23959;
v_23960:
    fn = elt(env, 13); // cl_cflip
    stack[-5] = (*qfn2(fn))(fn, v_24309, v_24308);
    env = stack[-6];
    goto v_23950;
v_23951:
    goto v_23971;
v_23965:
    goto v_23977;
v_23973:
    v_24309 = elt(env, 6); // and
    goto v_23974;
v_23975:
    v_24308 = stack[-4];
    goto v_23976;
v_23977:
    goto v_23973;
v_23974:
    goto v_23975;
v_23976:
    fn = elt(env, 13); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_24309, v_24308);
    env = stack[-6];
    goto v_23966;
v_23967:
    goto v_23985;
v_23981:
    v_24308 = stack[-2];
    v_24308 = qcdr(v_24308);
    v_24309 = qcar(v_24308);
    goto v_23982;
v_23983:
    v_24308 = stack[-4];
    goto v_23984;
v_23985:
    goto v_23981;
v_23982:
    goto v_23983;
v_23984:
    stack[0] = CC_cl_nnf1(elt(env, 0), v_24309, v_24308);
    env = stack[-6];
    goto v_23968;
v_23969:
    goto v_23996;
v_23992:
    v_24308 = stack[-2];
    v_24308 = qcdr(v_24308);
    v_24308 = qcdr(v_24308);
    v_24309 = qcar(v_24308);
    goto v_23993;
v_23994:
    v_24308 = stack[-4];
    goto v_23995;
v_23996:
    goto v_23992;
v_23993:
    goto v_23994;
v_23995:
    v_24308 = CC_cl_nnf1(elt(env, 0), v_24309, v_24308);
    env = stack[-6];
    v_24308 = ncons(v_24308);
    env = stack[-6];
    goto v_23970;
v_23971:
    goto v_23965;
v_23966:
    goto v_23967;
v_23968:
    goto v_23969;
v_23970:
    stack[-3] = list2star(stack[-1], stack[0], v_24308);
    env = stack[-6];
    goto v_23952;
v_23953:
    goto v_24010;
v_24004:
    goto v_24016;
v_24012:
    v_24309 = elt(env, 6); // and
    goto v_24013;
v_24014:
    v_24308 = stack[-4];
    goto v_24015;
v_24016:
    goto v_24012;
v_24013:
    goto v_24014;
v_24015:
    fn = elt(env, 13); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_24309, v_24308);
    env = stack[-6];
    goto v_24005;
v_24006:
    goto v_24024;
v_24020:
    v_24308 = stack[-2];
    v_24308 = qcdr(v_24308);
    v_24309 = qcar(v_24308);
    goto v_24021;
v_24022:
    v_24308 = stack[-4];
    v_24308 = (v_24308 == nil ? lisp_true : nil);
    goto v_24023;
v_24024:
    goto v_24020;
v_24021:
    goto v_24022;
v_24023:
    stack[0] = CC_cl_nnf1(elt(env, 0), v_24309, v_24308);
    env = stack[-6];
    goto v_24007;
v_24008:
    goto v_24036;
v_24032:
    v_24308 = stack[-2];
    v_24308 = qcdr(v_24308);
    v_24308 = qcdr(v_24308);
    v_24309 = qcar(v_24308);
    goto v_24033;
v_24034:
    v_24308 = stack[-4];
    v_24308 = (v_24308 == nil ? lisp_true : nil);
    goto v_24035;
v_24036:
    goto v_24032;
v_24033:
    goto v_24034;
v_24035:
    v_24308 = CC_cl_nnf1(elt(env, 0), v_24309, v_24308);
    env = stack[-6];
    v_24308 = ncons(v_24308);
    env = stack[-6];
    goto v_24009;
v_24010:
    goto v_24004;
v_24005:
    goto v_24006;
v_24007:
    goto v_24008;
v_24009:
    v_24308 = list2star(stack[-1], stack[0], v_24308);
    env = stack[-6];
    v_24308 = ncons(v_24308);
    goto v_23954;
v_23955:
    goto v_23949;
v_23950:
    goto v_23951;
v_23952:
    goto v_23953;
v_23954:
    {
        LispObject v_24321 = stack[-5];
        LispObject v_24322 = stack[-3];
        return list2star(v_24321, v_24322, v_24308);
    }
v_23940:
    goto v_24055;
v_24051:
    v_24309 = v_24310;
    goto v_24052;
v_24053:
    v_24308 = elt(env, 7); // true
    goto v_24054;
v_24055:
    goto v_24051;
v_24052:
    goto v_24053;
v_24054:
    if (v_24309 == v_24308) goto v_24049;
    else goto v_24050;
v_24049:
    v_24308 = lisp_true;
    goto v_24048;
v_24050:
    goto v_24065;
v_24061:
    v_24309 = v_24310;
    goto v_24062;
v_24063:
    v_24308 = elt(env, 8); // false
    goto v_24064;
v_24065:
    goto v_24061;
v_24062:
    goto v_24063;
v_24064:
    v_24308 = (v_24309 == v_24308 ? lisp_true : nil);
    goto v_24048;
    v_24308 = nil;
v_24048:
    if (v_24308 == nil) goto v_24046;
    goto v_24074;
v_24070:
    v_24309 = stack[-2];
    goto v_24071;
v_24072:
    v_24308 = stack[-4];
    goto v_24073;
v_24074:
    goto v_24070;
v_24071:
    goto v_24072;
v_24073:
    {
        fn = elt(env, 13); // cl_cflip
        return (*qfn2(fn))(fn, v_24309, v_24308);
    }
v_24046:
    goto v_24089;
v_24085:
    v_24309 = v_24310;
    goto v_24086;
v_24087:
    v_24308 = elt(env, 9); // ex
    goto v_24088;
v_24089:
    goto v_24085;
v_24086:
    goto v_24087;
v_24088:
    if (v_24309 == v_24308) goto v_24083;
    else goto v_24084;
v_24083:
    v_24308 = lisp_true;
    goto v_24082;
v_24084:
    goto v_24099;
v_24095:
    v_24309 = v_24310;
    goto v_24096;
v_24097:
    v_24308 = elt(env, 10); // all
    goto v_24098;
v_24099:
    goto v_24095;
v_24096:
    goto v_24097;
v_24098:
    v_24308 = (v_24309 == v_24308 ? lisp_true : nil);
    goto v_24082;
    v_24308 = nil;
v_24082:
    if (v_24308 == nil) goto v_24080;
    goto v_24110;
v_24104:
    goto v_24116;
v_24112:
    v_24309 = v_24310;
    goto v_24113;
v_24114:
    v_24308 = stack[-4];
    goto v_24115;
v_24116:
    goto v_24112;
v_24113:
    goto v_24114;
v_24115:
    fn = elt(env, 13); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_24309, v_24308);
    env = stack[-6];
    goto v_24105;
v_24106:
    v_24308 = stack[-2];
    v_24308 = qcdr(v_24308);
    stack[0] = qcar(v_24308);
    goto v_24107;
v_24108:
    goto v_24127;
v_24123:
    v_24308 = stack[-2];
    v_24308 = qcdr(v_24308);
    v_24308 = qcdr(v_24308);
    v_24309 = qcar(v_24308);
    goto v_24124;
v_24125:
    v_24308 = stack[-4];
    goto v_24126;
v_24127:
    goto v_24123;
v_24124:
    goto v_24125;
v_24126:
    v_24308 = CC_cl_nnf1(elt(env, 0), v_24309, v_24308);
    goto v_24109;
v_24110:
    goto v_24104;
v_24105:
    goto v_24106;
v_24107:
    goto v_24108;
v_24109:
    {
        LispObject v_24323 = stack[-1];
        LispObject v_24324 = stack[0];
        return list3(v_24323, v_24324, v_24308);
    }
v_24080:
    goto v_24145;
v_24141:
    v_24309 = v_24310;
    goto v_24142;
v_24143:
    v_24308 = elt(env, 11); // bex
    goto v_24144;
v_24145:
    goto v_24141;
v_24142:
    goto v_24143;
v_24144:
    if (v_24309 == v_24308) goto v_24139;
    else goto v_24140;
v_24139:
    v_24308 = lisp_true;
    goto v_24138;
v_24140:
    goto v_24155;
v_24151:
    v_24309 = v_24310;
    goto v_24152;
v_24153:
    v_24308 = elt(env, 12); // ball
    goto v_24154;
v_24155:
    goto v_24151;
v_24152:
    goto v_24153;
v_24154:
    v_24308 = (v_24309 == v_24308 ? lisp_true : nil);
    goto v_24138;
    v_24308 = nil;
v_24138:
    if (v_24308 == nil) goto v_24136;
    goto v_24168;
v_24160:
    goto v_24174;
v_24170:
    v_24309 = v_24310;
    goto v_24171;
v_24172:
    v_24308 = stack[-4];
    goto v_24173;
v_24174:
    goto v_24170;
v_24171:
    goto v_24172;
v_24173:
    fn = elt(env, 13); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_24309, v_24308);
    env = stack[-6];
    goto v_24161;
v_24162:
    v_24308 = stack[-2];
    v_24308 = qcdr(v_24308);
    stack[0] = qcar(v_24308);
    goto v_24163;
v_24164:
    goto v_24185;
v_24181:
    v_24308 = stack[-2];
    v_24308 = qcdr(v_24308);
    v_24308 = qcdr(v_24308);
    v_24309 = qcar(v_24308);
    goto v_24182;
v_24183:
    v_24308 = stack[-4];
    goto v_24184;
v_24185:
    goto v_24181;
v_24182:
    goto v_24183;
v_24184:
    stack[-3] = CC_cl_nnf1(elt(env, 0), v_24309, v_24308);
    env = stack[-6];
    goto v_24165;
v_24166:
    goto v_24196;
v_24192:
    v_24308 = stack[-2];
    v_24308 = qcdr(v_24308);
    v_24308 = qcdr(v_24308);
    v_24308 = qcdr(v_24308);
    v_24309 = qcar(v_24308);
    goto v_24193;
v_24194:
    v_24308 = lisp_true;
    goto v_24195;
v_24196:
    goto v_24192;
v_24193:
    goto v_24194;
v_24195:
    v_24308 = CC_cl_nnf1(elt(env, 0), v_24309, v_24308);
    goto v_24167;
v_24168:
    goto v_24160;
v_24161:
    goto v_24162;
v_24163:
    goto v_24164;
v_24165:
    goto v_24166;
v_24167:
    {
        LispObject v_24325 = stack[-1];
        LispObject v_24326 = stack[0];
        LispObject v_24327 = stack[-3];
        return list4(v_24325, v_24326, v_24327, v_24308);
    }
v_24136:
    goto v_24215;
v_24211:
    v_24309 = v_24310;
    goto v_24212;
v_24213:
    v_24308 = elt(env, 3); // or
    goto v_24214;
v_24215:
    goto v_24211;
v_24212:
    goto v_24213;
v_24214:
    if (v_24309 == v_24308) goto v_24209;
    else goto v_24210;
v_24209:
    v_24308 = lisp_true;
    goto v_24208;
v_24210:
    goto v_24225;
v_24221:
    v_24309 = v_24310;
    goto v_24222;
v_24223:
    v_24308 = elt(env, 6); // and
    goto v_24224;
v_24225:
    goto v_24221;
v_24222:
    goto v_24223;
v_24224:
    v_24308 = (v_24309 == v_24308 ? lisp_true : nil);
    goto v_24208;
    v_24308 = nil;
v_24208:
    if (v_24308 == nil) goto v_24206;
    goto v_24234;
v_24230:
    goto v_24240;
v_24236:
    v_24309 = v_24310;
    goto v_24237;
v_24238:
    v_24308 = stack[-4];
    goto v_24239;
v_24240:
    goto v_24236;
v_24237:
    goto v_24238;
v_24239:
    fn = elt(env, 13); // cl_cflip
    stack[-5] = (*qfn2(fn))(fn, v_24309, v_24308);
    env = stack[-6];
    goto v_24231;
v_24232:
    v_24308 = stack[-2];
    v_24308 = qcdr(v_24308);
    stack[-3] = v_24308;
    v_24308 = stack[-3];
    if (v_24308 == nil) goto v_24253;
    else goto v_24254;
v_24253:
    v_24308 = nil;
    goto v_24247;
v_24254:
    v_24308 = stack[-3];
    v_24308 = qcar(v_24308);
    goto v_24266;
v_24262:
    v_24309 = v_24308;
    goto v_24263;
v_24264:
    v_24308 = stack[-4];
    goto v_24265;
v_24266:
    goto v_24262;
v_24263:
    goto v_24264;
v_24265:
    v_24308 = CC_cl_nnf1(elt(env, 0), v_24309, v_24308);
    env = stack[-6];
    v_24308 = ncons(v_24308);
    env = stack[-6];
    stack[-1] = v_24308;
    stack[-2] = v_24308;
v_24248:
    v_24308 = stack[-3];
    v_24308 = qcdr(v_24308);
    stack[-3] = v_24308;
    v_24308 = stack[-3];
    if (v_24308 == nil) goto v_24273;
    else goto v_24274;
v_24273:
    v_24308 = stack[-2];
    goto v_24247;
v_24274:
    goto v_24282;
v_24278:
    stack[0] = stack[-1];
    goto v_24279;
v_24280:
    v_24308 = stack[-3];
    v_24308 = qcar(v_24308);
    goto v_24293;
v_24289:
    v_24309 = v_24308;
    goto v_24290;
v_24291:
    v_24308 = stack[-4];
    goto v_24292;
v_24293:
    goto v_24289;
v_24290:
    goto v_24291;
v_24292:
    v_24308 = CC_cl_nnf1(elt(env, 0), v_24309, v_24308);
    env = stack[-6];
    v_24308 = ncons(v_24308);
    env = stack[-6];
    goto v_24281;
v_24282:
    goto v_24278;
v_24279:
    goto v_24280;
v_24281:
    v_24308 = Lrplacd(nil, stack[0], v_24308);
    env = stack[-6];
    v_24308 = stack[-1];
    v_24308 = qcdr(v_24308);
    stack[-1] = v_24308;
    goto v_24248;
v_24247:
    goto v_24233;
v_24234:
    goto v_24230;
v_24231:
    goto v_24232;
v_24233:
    {
        LispObject v_24328 = stack[-5];
        return cons(v_24328, v_24308);
    }
v_24206:
    v_24308 = stack[-4];
    if (v_24308 == nil) goto v_24301;
    v_24308 = stack[-2];
    goto v_24299;
v_24301:
    v_24308 = stack[-2];
    {
        fn = elt(env, 14); // rl_negateat
        return (*qfn1(fn))(fn, v_24308);
    }
    v_24308 = nil;
v_24299:
    return onevalue(v_24308);
}



// Code for repr_ldeg

static LispObject CC_repr_ldeg(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_23807;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23807 = v_23799;
// end of prologue
    v_23807 = qcdr(v_23807);
    v_23807 = qcdr(v_23807);
    v_23807 = qcdr(v_23807);
    v_23807 = qcdr(v_23807);
    v_23807 = qcar(v_23807);
    return onevalue(v_23807);
}



// Code for symbolsrd

static LispObject CC_symbolsrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23973, v_23974, v_23975;
    LispObject fn;
    argcheck(nargs, 0, "symbolsrd");
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
    stack[-4] = nil;
    fn = elt(env, 8); // lex
    v_23973 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_23824;
v_23820:
    v_23974 = qvalue(elt(env, 1)); // char
    goto v_23821;
v_23822:
    v_23973 = elt(env, 2); // (b v a r)
    goto v_23823;
v_23824:
    goto v_23820;
v_23821:
    goto v_23822;
v_23823:
    if (equal(v_23974, v_23973)) goto v_23818;
    else goto v_23819;
v_23818:
    fn = elt(env, 9); // bvarrd
    v_23973 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[-4] = v_23973;
    goto v_23836;
v_23832:
    v_23973 = stack[-4];
    v_23973 = qcdr(v_23973);
    v_23973 = qcdr(v_23973);
    v_23974 = qcar(v_23973);
    goto v_23833;
v_23834:
    v_23973 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23835;
v_23836:
    goto v_23832;
v_23833:
    goto v_23834;
v_23835:
    if (v_23974 == v_23973) goto v_23830;
    else goto v_23831;
v_23830:
    v_23973 = stack[-4];
    stack[-4] = v_23973;
    goto v_23829;
v_23831:
    goto v_23850;
v_23846:
    v_23974 = elt(env, 3); // ""
    goto v_23847;
v_23848:
    v_23973 = (LispObject)208+TAG_FIXNUM; // 13
    goto v_23849;
v_23850:
    goto v_23846;
v_23847:
    goto v_23848;
v_23849:
    fn = elt(env, 10); // errorml
    v_23973 = (*qfn2(fn))(fn, v_23974, v_23973);
    env = stack[-5];
    goto v_23829;
v_23829:
    fn = elt(env, 8); // lex
    v_23973 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_23817;
v_23819:
    goto v_23861;
v_23857:
    v_23974 = elt(env, 4); // "<bvar>"
    goto v_23858;
v_23859:
    v_23973 = (LispObject)224+TAG_FIXNUM; // 14
    goto v_23860;
v_23861:
    goto v_23857;
v_23858:
    goto v_23859;
v_23860:
    fn = elt(env, 10); // errorml
    v_23973 = (*qfn2(fn))(fn, v_23974, v_23973);
    env = stack[-5];
    goto v_23817;
v_23817:
    goto v_23872;
v_23868:
    v_23974 = qvalue(elt(env, 1)); // char
    goto v_23869;
v_23870:
    v_23973 = elt(env, 5); // (l o w l i m i t)
    goto v_23871;
v_23872:
    goto v_23868;
v_23869:
    goto v_23870;
v_23871:
    if (equal(v_23974, v_23973)) goto v_23866;
    else goto v_23867;
v_23866:
    fn = elt(env, 11); // lowupperlimitrd
    v_23973 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[-3] = v_23973;
    fn = elt(env, 8); // lex
    v_23973 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_23865;
v_23867:
    v_23973 = nil;
    stack[-3] = v_23973;
    goto v_23865;
v_23865:
    goto v_23888;
v_23884:
    v_23974 = qvalue(elt(env, 1)); // char
    goto v_23885;
v_23886:
    v_23973 = elt(env, 6); // (i n t e r v a l)
    goto v_23887;
v_23888:
    goto v_23884;
v_23885:
    goto v_23886;
v_23887:
    if (equal(v_23974, v_23973)) goto v_23882;
    else goto v_23883;
v_23882:
    fn = elt(env, 12); // intervalrd
    v_23973 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[-2] = v_23973;
    fn = elt(env, 8); // lex
    v_23973 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_23881;
v_23883:
    v_23973 = nil;
    stack[-2] = v_23973;
    goto v_23881;
v_23881:
    goto v_23904;
v_23900:
    v_23974 = qvalue(elt(env, 1)); // char
    goto v_23901;
v_23902:
    v_23973 = elt(env, 7); // (c o n d i t i o n)
    goto v_23903;
v_23904:
    goto v_23900;
v_23901:
    goto v_23902;
v_23903:
    if (equal(v_23974, v_23973)) goto v_23898;
    else goto v_23899;
v_23898:
    fn = elt(env, 13); // conditionrd
    v_23973 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[0] = v_23973;
    fn = elt(env, 8); // lex
    v_23973 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    goto v_23897;
v_23899:
    v_23973 = nil;
    stack[0] = v_23973;
    goto v_23897;
v_23897:
    fn = elt(env, 14); // mathml2
    v_23973 = (*qfnn(fn))(fn, 0);
    env = stack[-5];
    stack[-1] = v_23973;
    fn = elt(env, 8); // lex
    v_23973 = (*qfnn(fn))(fn, 0);
    v_23973 = stack[-3];
    if (v_23973 == nil) goto v_23917;
    goto v_23926;
v_23920:
    v_23975 = stack[-4];
    goto v_23921;
v_23922:
    v_23974 = stack[-3];
    goto v_23923;
v_23924:
    v_23973 = stack[-1];
    goto v_23925;
v_23926:
    goto v_23920;
v_23921:
    goto v_23922;
v_23923:
    goto v_23924;
v_23925:
    return list3(v_23975, v_23974, v_23973);
v_23917:
    v_23973 = stack[-2];
    if (v_23973 == nil) goto v_23933;
    goto v_23942;
v_23936:
    v_23975 = stack[-4];
    goto v_23937;
v_23938:
    v_23974 = stack[-2];
    goto v_23939;
v_23940:
    v_23973 = stack[-1];
    goto v_23941;
v_23942:
    goto v_23936;
v_23937:
    goto v_23938;
v_23939:
    goto v_23940;
v_23941:
    return list3(v_23975, v_23974, v_23973);
v_23933:
    v_23973 = stack[0];
    if (v_23973 == nil) goto v_23949;
    goto v_23958;
v_23952:
    v_23975 = stack[-4];
    goto v_23953;
v_23954:
    v_23974 = stack[0];
    goto v_23955;
v_23956:
    v_23973 = stack[-1];
    goto v_23957;
v_23958:
    goto v_23952;
v_23953:
    goto v_23954;
v_23955:
    goto v_23956;
v_23957:
    return list3(v_23975, v_23974, v_23973);
v_23949:
    goto v_23969;
v_23963:
    v_23975 = stack[-4];
    goto v_23964;
v_23965:
    v_23974 = nil;
    goto v_23966;
v_23967:
    v_23973 = stack[-1];
    goto v_23968;
v_23969:
    goto v_23963;
v_23964:
    goto v_23965;
v_23966:
    goto v_23967;
v_23968:
    return list3(v_23975, v_23974, v_23973);
    return onevalue(v_23973);
}



// Code for spcol_dim

static LispObject CC_spcol_dim(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_23827;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23799);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_23799;
// end of prologue
    v_23827 = qvalue(elt(env, 1)); // !*fast_la
    if (v_23827 == nil) goto v_23810;
    else goto v_23811;
v_23810:
    v_23827 = stack[0];
    fn = elt(env, 3); // matrixp
    v_23827 = (*qfn1(fn))(fn, v_23827);
    env = stack[-1];
    v_23827 = (v_23827 == nil ? lisp_true : nil);
    goto v_23809;
v_23811:
    v_23827 = nil;
    goto v_23809;
    v_23827 = nil;
v_23809:
    if (v_23827 == nil) goto v_23807;
    v_23827 = elt(env, 2); // "Error in spcol_dim: input should be a matrix."
    fn = elt(env, 4); // rederr
    v_23827 = (*qfn1(fn))(fn, v_23827);
    env = stack[-1];
    goto v_23805;
v_23807:
v_23805:
    v_23827 = stack[0];
    fn = elt(env, 5); // spmatlength
    v_23827 = (*qfn1(fn))(fn, v_23827);
    v_23827 = qcdr(v_23827);
    v_23827 = qcdr(v_23827);
    v_23827 = qcar(v_23827);
    return onevalue(v_23827);
}



// Code for on!-double1

static LispObject CC_onKdouble1(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_23828;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23799);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_23799;
// end of prologue
v_23803:
    v_23828 = stack[0];
    v_23828 = Lconsp(nil, v_23828);
    env = stack[-1];
    if (v_23828 == nil) goto v_23807;
    v_23828 = stack[0];
    v_23828 = qcar(v_23828);
    fn = elt(env, 2); // doublep
    v_23828 = (*qfn1(fn))(fn, v_23828);
    env = stack[-1];
    if (v_23828 == nil) goto v_23813;
    v_23828 = lisp_true;
    qvalue(elt(env, 1)) = v_23828; // !*double
    goto v_23802;
v_23813:
    v_23828 = stack[0];
    v_23828 = qcar(v_23828);
    v_23828 = CC_onKdouble1(elt(env, 0), v_23828);
    env = stack[-1];
    v_23828 = stack[0];
    v_23828 = qcdr(v_23828);
    stack[0] = v_23828;
    goto v_23803;
    goto v_23805;
v_23807:
    v_23828 = nil;
    goto v_23802;
v_23805:
    v_23828 = nil;
v_23802:
    return onevalue(v_23828);
}



// Code for gbfdiff

static LispObject CC_gbfdiff(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23828, v_23829;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23799,v_23800);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_23800;
    stack[-1] = v_23799;
// end of prologue
    goto v_23807;
v_23803:
    goto v_23813;
v_23809:
    v_23828 = stack[-1];
    v_23829 = qcar(v_23828);
    goto v_23810;
v_23811:
    v_23828 = stack[0];
    v_23828 = qcar(v_23828);
    goto v_23812;
v_23813:
    goto v_23809;
v_23810:
    goto v_23811;
v_23812:
    fn = elt(env, 1); // difbf
    stack[-2] = (*qfn2(fn))(fn, v_23829, v_23828);
    env = stack[-3];
    goto v_23804;
v_23805:
    goto v_23823;
v_23819:
    v_23828 = stack[-1];
    v_23829 = qcdr(v_23828);
    goto v_23820;
v_23821:
    v_23828 = stack[0];
    v_23828 = qcdr(v_23828);
    goto v_23822;
v_23823:
    goto v_23819;
v_23820:
    goto v_23821;
v_23822:
    fn = elt(env, 1); // difbf
    v_23828 = (*qfn2(fn))(fn, v_23829, v_23828);
    goto v_23806;
v_23807:
    goto v_23803;
v_23804:
    goto v_23805;
v_23806:
    {
        LispObject v_23833 = stack[-2];
        return cons(v_23833, v_23828);
    }
}



// Code for r2speclist1

static LispObject CC_r2speclist1(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_23842, v_23843, v_23844;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23842 = v_23799;
// end of prologue
    goto v_23810;
v_23806:
    v_23844 = v_23842;
    goto v_23807;
v_23808:
    v_23843 = elt(env, 1); // times
    goto v_23809;
v_23810:
    goto v_23806;
v_23807:
    goto v_23808;
v_23809:
    if (!consp(v_23844)) goto v_23804;
    v_23844 = qcar(v_23844);
    if (v_23844 == v_23843) goto v_23803;
    else goto v_23804;
v_23803:
    goto v_23820;
v_23814:
    v_23843 = v_23842;
    v_23843 = qcdr(v_23843);
    v_23844 = qcar(v_23843);
    goto v_23815;
v_23816:
    v_23843 = v_23842;
    v_23843 = qcdr(v_23843);
    v_23843 = qcdr(v_23843);
    v_23843 = qcar(v_23843);
    goto v_23817;
v_23818:
    v_23842 = qcdr(v_23842);
    v_23842 = qcdr(v_23842);
    v_23842 = qcdr(v_23842);
    goto v_23819;
v_23820:
    goto v_23814;
v_23815:
    goto v_23816;
v_23817:
    goto v_23818;
v_23819:
    {
        fn = elt(env, 2); // r2speclist2
        return (*qfnn(fn))(fn, 3, v_23844, v_23843, v_23842);
    }
v_23804:
    goto v_23839;
v_23835:
    v_23843 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23836;
v_23837:
    goto v_23838;
v_23839:
    goto v_23835;
v_23836:
    goto v_23837;
v_23838:
    return cons(v_23843, v_23842);
    v_23842 = nil;
    return onevalue(v_23842);
}



// Code for list!-evaluate

static LispObject CC_listKevaluate(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23863, v_23864, v_23865;
    LispObject fn;
    LispObject v_23801, v_23800, v_23799;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "list-evaluate");
    va_start(aa, nargs);
    v_23799 = va_arg(aa, LispObject);
    v_23800 = va_arg(aa, LispObject);
    v_23801 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_23801,v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_23799,v_23800,v_23801);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_23801;
    stack[-4] = v_23800;
    v_23863 = v_23799;
// end of prologue
    stack[-5] = v_23863;
    v_23863 = stack[-5];
    if (v_23863 == nil) goto v_23812;
    else goto v_23813;
v_23812:
    v_23863 = nil;
    goto v_23807;
v_23813:
    v_23863 = stack[-5];
    v_23863 = qcar(v_23863);
    goto v_23827;
v_23821:
    v_23865 = v_23863;
    goto v_23822;
v_23823:
    v_23864 = stack[-4];
    goto v_23824;
v_23825:
    v_23863 = stack[-3];
    goto v_23826;
v_23827:
    goto v_23821;
v_23822:
    goto v_23823;
v_23824:
    goto v_23825;
v_23826:
    fn = elt(env, 1); // evaluate
    v_23863 = (*qfnn(fn))(fn, 3, v_23865, v_23864, v_23863);
    env = stack[-6];
    v_23863 = ncons(v_23863);
    env = stack[-6];
    stack[-1] = v_23863;
    stack[-2] = v_23863;
v_23808:
    v_23863 = stack[-5];
    v_23863 = qcdr(v_23863);
    stack[-5] = v_23863;
    v_23863 = stack[-5];
    if (v_23863 == nil) goto v_23835;
    else goto v_23836;
v_23835:
    v_23863 = stack[-2];
    goto v_23807;
v_23836:
    goto v_23844;
v_23840:
    stack[0] = stack[-1];
    goto v_23841;
v_23842:
    v_23863 = stack[-5];
    v_23863 = qcar(v_23863);
    goto v_23857;
v_23851:
    v_23865 = v_23863;
    goto v_23852;
v_23853:
    v_23864 = stack[-4];
    goto v_23854;
v_23855:
    v_23863 = stack[-3];
    goto v_23856;
v_23857:
    goto v_23851;
v_23852:
    goto v_23853;
v_23854:
    goto v_23855;
v_23856:
    fn = elt(env, 1); // evaluate
    v_23863 = (*qfnn(fn))(fn, 3, v_23865, v_23864, v_23863);
    env = stack[-6];
    v_23863 = ncons(v_23863);
    env = stack[-6];
    goto v_23843;
v_23844:
    goto v_23840;
v_23841:
    goto v_23842;
v_23843:
    v_23863 = Lrplacd(nil, stack[0], v_23863);
    env = stack[-6];
    v_23863 = stack[-1];
    v_23863 = qcdr(v_23863);
    stack[-1] = v_23863;
    goto v_23808;
v_23807:
    return onevalue(v_23863);
}



// Code for mkassign

static LispObject CC_mkassign(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23813, v_23814, v_23815;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23813 = v_23800;
    v_23814 = v_23799;
// end of prologue
    goto v_23809;
v_23803:
    v_23815 = elt(env, 1); // setq
    goto v_23804;
v_23805:
    goto v_23806;
v_23807:
    goto v_23808;
v_23809:
    goto v_23803;
v_23804:
    goto v_23805;
v_23806:
    goto v_23807;
v_23808:
    return list3(v_23815, v_23814, v_23813);
}



// Code for set!-weights

static LispObject CC_setKweights(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_23854;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23799);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_23854 = v_23799;
// end of prologue
    goto v_23811;
v_23807:
    stack[-4] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23808;
v_23809:
    v_23854 = qcdr(v_23854);
    stack[-3] = v_23854;
    v_23854 = stack[-3];
    if (v_23854 == nil) goto v_23823;
    else goto v_23824;
v_23823:
    v_23854 = nil;
    goto v_23817;
v_23824:
    v_23854 = (LispObject)16+TAG_FIXNUM; // 1
    v_23854 = ncons(v_23854);
    env = stack[-5];
    stack[-1] = v_23854;
    stack[-2] = v_23854;
v_23818:
    v_23854 = stack[-3];
    v_23854 = qcdr(v_23854);
    stack[-3] = v_23854;
    v_23854 = stack[-3];
    if (v_23854 == nil) goto v_23836;
    else goto v_23837;
v_23836:
    v_23854 = stack[-2];
    goto v_23817;
v_23837:
    goto v_23845;
v_23841:
    stack[0] = stack[-1];
    goto v_23842;
v_23843:
    v_23854 = (LispObject)16+TAG_FIXNUM; // 1
    v_23854 = ncons(v_23854);
    env = stack[-5];
    goto v_23844;
v_23845:
    goto v_23841;
v_23842:
    goto v_23843;
v_23844:
    v_23854 = Lrplacd(nil, stack[0], v_23854);
    env = stack[-5];
    v_23854 = stack[-1];
    v_23854 = qcdr(v_23854);
    stack[-1] = v_23854;
    goto v_23818;
v_23817:
    goto v_23810;
v_23811:
    goto v_23807;
v_23808:
    goto v_23809;
v_23810:
    v_23854 = cons(stack[-4], v_23854);
        return Lnreverse(nil, v_23854);
    return onevalue(v_23854);
}



// Code for simp!-prop!-dist

static LispObject CC_simpKpropKdist(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_23933, v_23934, v_23935;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23799);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_23934 = v_23799;
// end of prologue
    goto v_23810;
v_23806:
    v_23935 = v_23934;
    goto v_23807;
v_23808:
    v_23933 = elt(env, 1); // plus
    goto v_23809;
v_23810:
    goto v_23806;
v_23807:
    goto v_23808;
v_23809:
    if (!consp(v_23935)) goto v_23804;
    v_23935 = qcar(v_23935);
    if (v_23935 == v_23933) goto v_23803;
    else goto v_23804;
v_23803:
    v_23933 = v_23934;
    v_23933 = qcdr(v_23933);
    v_23934 = v_23933;
    goto v_23802;
v_23804:
    v_23933 = v_23934;
    v_23933 = ncons(v_23933);
    env = stack[-4];
    v_23934 = v_23933;
    goto v_23802;
v_23802:
    v_23933 = v_23934;
    stack[-3] = v_23933;
    v_23933 = stack[-3];
    if (v_23933 == nil) goto v_23828;
    else goto v_23829;
v_23828:
    v_23933 = nil;
    goto v_23823;
v_23829:
    v_23933 = stack[-3];
    v_23933 = qcar(v_23933);
    v_23935 = v_23933;
    goto v_23845;
v_23841:
    v_23934 = v_23935;
    goto v_23842;
v_23843:
    v_23933 = elt(env, 2); // times
    goto v_23844;
v_23845:
    goto v_23841;
v_23842:
    goto v_23843;
v_23844:
    if (!consp(v_23934)) goto v_23839;
    v_23934 = qcar(v_23934);
    if (v_23934 == v_23933) goto v_23838;
    else goto v_23839;
v_23838:
    v_23933 = v_23935;
    v_23933 = qcdr(v_23933);
    goto v_23837;
v_23839:
    v_23933 = v_23935;
    v_23933 = ncons(v_23933);
    env = stack[-4];
    goto v_23837;
    v_23933 = nil;
v_23837:
    v_23935 = v_23933;
    v_23933 = v_23935;
    v_23933 = qcar(v_23933);
    if (is_number(v_23933)) goto v_23856;
    else goto v_23857;
v_23856:
    v_23933 = v_23935;
    v_23933 = qcdr(v_23933);
    v_23935 = v_23933;
    goto v_23855;
v_23857:
v_23855:
    goto v_23867;
v_23863:
    v_23934 = v_23935;
    goto v_23864;
v_23865:
    v_23933 = elt(env, 3); // lambda_iff2c8okfzyq1
    goto v_23866;
v_23867:
    goto v_23863;
v_23864:
    goto v_23865;
v_23866:
    fn = elt(env, 5); // sort
    v_23933 = (*qfn2(fn))(fn, v_23934, v_23933);
    env = stack[-4];
    v_23933 = ncons(v_23933);
    env = stack[-4];
    stack[-1] = v_23933;
    stack[-2] = v_23933;
v_23824:
    v_23933 = stack[-3];
    v_23933 = qcdr(v_23933);
    stack[-3] = v_23933;
    v_23933 = stack[-3];
    if (v_23933 == nil) goto v_23874;
    else goto v_23875;
v_23874:
    v_23933 = stack[-2];
    goto v_23823;
v_23875:
    goto v_23883;
v_23879:
    stack[0] = stack[-1];
    goto v_23880;
v_23881:
    v_23933 = stack[-3];
    v_23933 = qcar(v_23933);
    v_23935 = v_23933;
    goto v_23898;
v_23894:
    v_23934 = v_23935;
    goto v_23895;
v_23896:
    v_23933 = elt(env, 2); // times
    goto v_23897;
v_23898:
    goto v_23894;
v_23895:
    goto v_23896;
v_23897:
    if (!consp(v_23934)) goto v_23892;
    v_23934 = qcar(v_23934);
    if (v_23934 == v_23933) goto v_23891;
    else goto v_23892;
v_23891:
    v_23933 = v_23935;
    v_23933 = qcdr(v_23933);
    goto v_23890;
v_23892:
    v_23933 = v_23935;
    v_23933 = ncons(v_23933);
    env = stack[-4];
    goto v_23890;
    v_23933 = nil;
v_23890:
    v_23935 = v_23933;
    v_23933 = v_23935;
    v_23933 = qcar(v_23933);
    if (is_number(v_23933)) goto v_23909;
    else goto v_23910;
v_23909:
    v_23933 = v_23935;
    v_23933 = qcdr(v_23933);
    v_23935 = v_23933;
    goto v_23908;
v_23910:
v_23908:
    goto v_23920;
v_23916:
    v_23934 = v_23935;
    goto v_23917;
v_23918:
    v_23933 = elt(env, 3); // lambda_iff2c8okfzyq1
    goto v_23919;
v_23920:
    goto v_23916;
v_23917:
    goto v_23918;
v_23919:
    fn = elt(env, 5); // sort
    v_23933 = (*qfn2(fn))(fn, v_23934, v_23933);
    env = stack[-4];
    v_23933 = ncons(v_23933);
    env = stack[-4];
    goto v_23882;
v_23883:
    goto v_23879;
v_23880:
    goto v_23881;
v_23882:
    v_23933 = Lrplacd(nil, stack[0], v_23933);
    env = stack[-4];
    v_23933 = stack[-1];
    v_23933 = qcdr(v_23933);
    stack[-1] = v_23933;
    goto v_23824;
v_23823:
    v_23934 = v_23933;
    goto v_23930;
v_23926:
    goto v_23927;
v_23928:
    v_23933 = elt(env, 4); // simp!-prop!-order
    goto v_23929;
v_23930:
    goto v_23926;
v_23927:
    goto v_23928;
v_23929:
    {
        fn = elt(env, 5); // sort
        return (*qfn2(fn))(fn, v_23934, v_23933);
    }
}



// Code for lambda_iff2c8okfzyq1

static LispObject CC_lambda_iff2c8okfzyq1(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23814, v_23815;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23814 = v_23800;
    v_23815 = v_23799;
// end of prologue
    goto v_23807;
v_23803:
    v_23815 = qcdr(v_23815);
    v_23815 = qcar(v_23815);
    goto v_23804;
v_23805:
    v_23814 = qcdr(v_23814);
    v_23814 = qcar(v_23814);
    goto v_23806;
v_23807:
    goto v_23803;
v_23804:
    goto v_23805;
v_23806:
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_23815, v_23814);
    }
}



// Code for lambda_iff2c8okfzyq1

static LispObject CC1_lambda_iff2c8okfzyq1(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23814, v_23815;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23814 = v_23800;
    v_23815 = v_23799;
// end of prologue
    goto v_23807;
v_23803:
    v_23815 = qcdr(v_23815);
    v_23815 = qcar(v_23815);
    goto v_23804;
v_23805:
    v_23814 = qcdr(v_23814);
    v_23814 = qcar(v_23814);
    goto v_23806;
v_23807:
    goto v_23803;
v_23804:
    goto v_23805;
v_23806:
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_23815, v_23814);
    }
}



// Code for lesspcar

static LispObject CC_lesspcar(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23812, v_23813;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23812 = v_23800;
    v_23813 = v_23799;
// end of prologue
    goto v_23807;
v_23803:
    v_23813 = qcar(v_23813);
    goto v_23804;
v_23805:
    v_23812 = qcar(v_23812);
    goto v_23806;
v_23807:
    goto v_23803;
v_23804:
    goto v_23805;
v_23806:
        return Llessp(nil, v_23813, v_23812);
}



// Code for simpquot

static LispObject CC_simpquot(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_23989, v_23990, v_23991;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23799);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_23799;
// end of prologue
    v_23989 = stack[-1];
    fn = elt(env, 7); // simpcar
    stack[0] = (*qfn1(fn))(fn, v_23989);
    env = stack[-3];
    v_23989 = stack[-1];
    v_23989 = qcdr(v_23989);
    v_23989 = qcar(v_23989);
    fn = elt(env, 8); // simp
    v_23989 = (*qfn1(fn))(fn, v_23989);
    env = stack[-3];
    stack[-2] = stack[0];
    stack[0] = v_23989;
    v_23989 = stack[0];
    v_23989 = qcar(v_23989);
    if (v_23989 == nil) goto v_23811;
    else goto v_23812;
v_23811:
    v_23989 = stack[-2];
    v_23989 = qcar(v_23989);
    if (v_23989 == nil) goto v_23817;
    else goto v_23818;
v_23817:
    goto v_23828;
v_23822:
    v_23991 = elt(env, 1); // alg
    goto v_23823;
v_23824:
    v_23990 = (LispObject)304+TAG_FIXNUM; // 19
    goto v_23825;
v_23826:
    v_23989 = elt(env, 2); // "0/0 formed"
    goto v_23827;
v_23828:
    goto v_23822;
v_23823:
    goto v_23824;
v_23825:
    goto v_23826;
v_23827:
    {
        fn = elt(env, 9); // rerror
        return (*qfnn(fn))(fn, 3, v_23991, v_23990, v_23989);
    }
v_23818:
    goto v_23841;
v_23835:
    v_23991 = elt(env, 1); // alg
    goto v_23836;
v_23837:
    v_23990 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_23838;
v_23839:
    v_23989 = elt(env, 3); // "Zero divisor"
    goto v_23840;
v_23841:
    goto v_23835;
v_23836:
    goto v_23837;
v_23838:
    goto v_23839;
v_23840:
    {
        fn = elt(env, 9); // rerror
        return (*qfnn(fn))(fn, 3, v_23991, v_23990, v_23989);
    }
    v_23989 = nil;
    goto v_23810;
v_23812:
    goto v_23852;
v_23848:
    v_23990 = qvalue(elt(env, 4)); // dmode!*
    goto v_23849;
v_23850:
    v_23989 = elt(env, 5); // (!:rd!: !:cr!:)
    goto v_23851;
v_23852:
    goto v_23848;
v_23849:
    goto v_23850;
v_23851:
    v_23989 = Lmemq(nil, v_23990, v_23989);
    if (v_23989 == nil) goto v_23846;
    v_23989 = stack[0];
    v_23989 = qcar(v_23989);
    if (!consp(v_23989)) goto v_23863;
    else goto v_23864;
v_23863:
    v_23989 = lisp_true;
    goto v_23862;
v_23864:
    v_23989 = stack[0];
    v_23989 = qcar(v_23989);
    v_23989 = qcar(v_23989);
    v_23989 = (consp(v_23989) ? nil : lisp_true);
    goto v_23862;
    v_23989 = nil;
v_23862:
    if (v_23989 == nil) goto v_23860;
    v_23989 = stack[0];
    v_23989 = qcdr(v_23989);
    if (!consp(v_23989)) goto v_23880;
    else goto v_23881;
v_23880:
    v_23989 = lisp_true;
    goto v_23879;
v_23881:
    v_23989 = stack[0];
    v_23989 = qcdr(v_23989);
    v_23989 = qcar(v_23989);
    v_23989 = (consp(v_23989) ? nil : lisp_true);
    goto v_23879;
    v_23989 = nil;
v_23879:
    if (v_23989 == nil) goto v_23877;
    v_23989 = stack[-2];
    v_23989 = qcdr(v_23989);
    if (!consp(v_23989)) goto v_23897;
    else goto v_23898;
v_23897:
    v_23989 = lisp_true;
    goto v_23896;
v_23898:
    v_23989 = stack[-2];
    v_23989 = qcdr(v_23989);
    v_23989 = qcar(v_23989);
    v_23989 = (consp(v_23989) ? nil : lisp_true);
    goto v_23896;
    v_23989 = nil;
v_23896:
    if (v_23989 == nil) goto v_23894;
    v_23989 = stack[0];
    v_23989 = qcdr(v_23989);
    fn = elt(env, 10); // !:onep
    v_23989 = (*qfn1(fn))(fn, v_23989);
    env = stack[-3];
    if (v_23989 == nil) goto v_23910;
    else goto v_23911;
v_23910:
    v_23989 = nil;
    goto v_23909;
v_23911:
    v_23989 = stack[-2];
    v_23989 = qcdr(v_23989);
    fn = elt(env, 10); // !:onep
    v_23989 = (*qfn1(fn))(fn, v_23989);
    env = stack[-3];
    goto v_23909;
    v_23989 = nil;
v_23909:
    goto v_23892;
v_23894:
    v_23989 = nil;
    goto v_23892;
    v_23989 = nil;
v_23892:
    goto v_23875;
v_23877:
    v_23989 = nil;
    goto v_23875;
    v_23989 = nil;
v_23875:
    goto v_23858;
v_23860:
    v_23989 = nil;
    goto v_23858;
    v_23989 = nil;
v_23858:
    if (v_23989 == nil) goto v_23846;
    goto v_23935;
v_23931:
    v_23989 = stack[-2];
    v_23989 = qcar(v_23989);
    if (v_23989 == nil) goto v_23938;
    else goto v_23939;
v_23938:
    v_23989 = nil;
    v_23990 = v_23989;
    goto v_23937;
v_23939:
    goto v_23950;
v_23946:
    v_23989 = stack[-2];
    v_23990 = qcar(v_23989);
    goto v_23947;
v_23948:
    v_23989 = stack[0];
    v_23989 = qcar(v_23989);
    goto v_23949;
v_23950:
    goto v_23946;
v_23947:
    goto v_23948;
v_23949:
    fn = elt(env, 11); // divd
    v_23989 = (*qfn2(fn))(fn, v_23990, v_23989);
    v_23990 = v_23989;
    goto v_23937;
    v_23990 = nil;
v_23937:
    goto v_23932;
v_23933:
    v_23989 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23934;
v_23935:
    goto v_23931;
v_23932:
    goto v_23933;
v_23934:
    return cons(v_23990, v_23989);
v_23846:
    goto v_23963;
v_23959:
    stack[0] = stack[-2];
    goto v_23960;
v_23961:
    v_23989 = stack[-1];
    v_23989 = qcdr(v_23989);
    fn = elt(env, 12); // simprecip
    v_23989 = (*qfn1(fn))(fn, v_23989);
    env = stack[-3];
    goto v_23962;
v_23963:
    goto v_23959;
v_23960:
    goto v_23961;
v_23962:
    fn = elt(env, 13); // multsq
    v_23989 = (*qfn2(fn))(fn, stack[0], v_23989);
    env = stack[-3];
    stack[-1] = v_23989;
    v_23989 = qvalue(elt(env, 6)); // !*modular
    if (v_23989 == nil) goto v_23971;
    v_23989 = stack[-1];
    v_23989 = qcdr(v_23989);
    if (v_23989 == nil) goto v_23974;
    else goto v_23971;
v_23974:
    goto v_23984;
v_23978:
    v_23991 = elt(env, 1); // alg
    goto v_23979;
v_23980:
    v_23990 = (LispObject)3216+TAG_FIXNUM; // 201
    goto v_23981;
v_23982:
    v_23989 = elt(env, 3); // "Zero divisor"
    goto v_23983;
v_23984:
    goto v_23978;
v_23979:
    goto v_23980;
v_23981:
    goto v_23982;
v_23983:
    fn = elt(env, 9); // rerror
    v_23989 = (*qfnn(fn))(fn, 3, v_23991, v_23990, v_23989);
    goto v_23969;
v_23971:
v_23969:
    v_23989 = stack[-1];
    goto v_23810;
    v_23989 = nil;
v_23810:
    return onevalue(v_23989);
}



// Code for rl_qe

static LispObject CC_rl_qe(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23817, v_23818;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23799,v_23800);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_23817 = v_23800;
    v_23818 = v_23799;
// end of prologue
    goto v_23807;
v_23803:
    stack[0] = qvalue(elt(env, 1)); // rl_qe!*
    goto v_23804;
v_23805:
    goto v_23814;
v_23810:
    goto v_23811;
v_23812:
    goto v_23813;
v_23814:
    goto v_23810;
v_23811:
    goto v_23812;
v_23813:
    v_23817 = list2(v_23818, v_23817);
    env = stack[-1];
    goto v_23806;
v_23807:
    goto v_23803;
v_23804:
    goto v_23805;
v_23806:
    {
        LispObject v_23820 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_23820, v_23817);
    }
}



// Code for ofsf_evalatp

static LispObject CC_ofsf_evalatp(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23894, v_23895, v_23896;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23799,v_23800);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_23800;
    v_23896 = v_23799;
// end of prologue
    goto v_23810;
v_23806:
    v_23895 = v_23896;
    goto v_23807;
v_23808:
    v_23894 = elt(env, 1); // equal
    goto v_23809;
v_23810:
    goto v_23806;
v_23807:
    goto v_23808;
v_23809:
    if (v_23895 == v_23894) goto v_23804;
    else goto v_23805;
v_23804:
    v_23894 = stack[0];
    v_23894 = (v_23894 == nil ? lisp_true : nil);
    goto v_23803;
v_23805:
    goto v_23821;
v_23817:
    v_23895 = v_23896;
    goto v_23818;
v_23819:
    v_23894 = elt(env, 2); // neq
    goto v_23820;
v_23821:
    goto v_23817;
v_23818:
    goto v_23819;
v_23820:
    if (v_23895 == v_23894) goto v_23815;
    else goto v_23816;
v_23815:
    v_23894 = stack[0];
    v_23894 = (v_23894 == nil ? lisp_true : nil);
    v_23894 = (v_23894 == nil ? lisp_true : nil);
    goto v_23803;
v_23816:
    goto v_23833;
v_23829:
    v_23895 = v_23896;
    goto v_23830;
v_23831:
    v_23894 = elt(env, 3); // leq
    goto v_23832;
v_23833:
    goto v_23829;
v_23830:
    goto v_23831;
v_23832:
    if (v_23895 == v_23894) goto v_23827;
    else goto v_23828;
v_23827:
    v_23894 = stack[0];
    fn = elt(env, 8); // minusf
    v_23894 = (*qfn1(fn))(fn, v_23894);
    if (v_23894 == nil) goto v_23838;
    else goto v_23837;
v_23838:
    v_23894 = stack[0];
    v_23894 = (v_23894 == nil ? lisp_true : nil);
v_23837:
    goto v_23803;
v_23828:
    goto v_23849;
v_23845:
    v_23895 = v_23896;
    goto v_23846;
v_23847:
    v_23894 = elt(env, 4); // geq
    goto v_23848;
v_23849:
    goto v_23845;
v_23846:
    goto v_23847;
v_23848:
    if (v_23895 == v_23894) goto v_23843;
    else goto v_23844;
v_23843:
    v_23894 = stack[0];
    fn = elt(env, 8); // minusf
    v_23894 = (*qfn1(fn))(fn, v_23894);
    v_23894 = (v_23894 == nil ? lisp_true : nil);
    goto v_23803;
v_23844:
    goto v_23861;
v_23857:
    v_23895 = v_23896;
    goto v_23858;
v_23859:
    v_23894 = elt(env, 5); // lessp
    goto v_23860;
v_23861:
    goto v_23857;
v_23858:
    goto v_23859;
v_23860:
    if (v_23895 == v_23894) goto v_23855;
    else goto v_23856;
v_23855:
    v_23894 = stack[0];
    {
        fn = elt(env, 8); // minusf
        return (*qfn1(fn))(fn, v_23894);
    }
v_23856:
    goto v_23872;
v_23868:
    v_23895 = v_23896;
    goto v_23869;
v_23870:
    v_23894 = elt(env, 6); // greaterp
    goto v_23871;
v_23872:
    goto v_23868;
v_23869:
    goto v_23870;
v_23871:
    if (v_23895 == v_23894) goto v_23866;
    else goto v_23867;
v_23866:
    v_23894 = stack[0];
    fn = elt(env, 8); // minusf
    v_23894 = (*qfn1(fn))(fn, v_23894);
    if (v_23894 == nil) goto v_23877;
    else goto v_23876;
v_23877:
    v_23894 = stack[0];
    v_23894 = (v_23894 == nil ? lisp_true : nil);
v_23876:
    v_23894 = (v_23894 == nil ? lisp_true : nil);
    goto v_23803;
v_23867:
    goto v_23891;
v_23887:
    v_23894 = elt(env, 7); // "ofsf_evalatp: unknown operator "
    goto v_23888;
v_23889:
    v_23895 = v_23896;
    goto v_23890;
v_23891:
    goto v_23887;
v_23888:
    goto v_23889;
v_23890:
    v_23894 = list2(v_23894, v_23895);
    env = stack[-1];
    {
        fn = elt(env, 9); // rederr
        return (*qfn1(fn))(fn, v_23894);
    }
    v_23894 = nil;
v_23803:
    return onevalue(v_23894);
}



// Code for talp_trygaussvar

static LispObject CC_talp_trygaussvar(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23880, v_23881, v_23882;
    LispObject fn;
    LispObject v_23801, v_23800, v_23799;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_trygaussvar");
    va_start(aa, nargs);
    v_23799 = va_arg(aa, LispObject);
    v_23800 = va_arg(aa, LispObject);
    v_23801 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_23801,v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_23799,v_23800,v_23801);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_23801;
    stack[-1] = v_23800;
    stack[-2] = v_23799;
// end of prologue
    v_23880 = stack[-1];
    fn = elt(env, 4); // talp_atfp
    v_23880 = (*qfn1(fn))(fn, v_23880);
    env = stack[-3];
    if (v_23880 == nil) goto v_23806;
    goto v_23814;
v_23810:
    v_23881 = stack[-2];
    goto v_23811;
v_23812:
    v_23880 = stack[-1];
    goto v_23813;
v_23814:
    goto v_23810;
v_23811:
    goto v_23812;
v_23813:
    {
        fn = elt(env, 5); // talp_qesolset
        return (*qfn2(fn))(fn, v_23881, v_23880);
    }
v_23806:
    goto v_23823;
v_23819:
    v_23880 = stack[-1];
    if (!consp(v_23880)) goto v_23826;
    else goto v_23827;
v_23826:
    v_23880 = stack[-1];
    v_23881 = v_23880;
    goto v_23825;
v_23827:
    v_23880 = stack[-1];
    v_23880 = qcar(v_23880);
    v_23881 = v_23880;
    goto v_23825;
    v_23881 = nil;
v_23825:
    goto v_23820;
v_23821:
    v_23880 = elt(env, 1); // and
    goto v_23822;
v_23823:
    goto v_23819;
v_23820:
    goto v_23821;
v_23822:
    if (v_23881 == v_23880) goto v_23817;
    else goto v_23818;
v_23817:
    goto v_23842;
v_23836:
    v_23882 = stack[-2];
    goto v_23837;
v_23838:
    v_23880 = stack[-1];
    v_23881 = qcdr(v_23880);
    goto v_23839;
v_23840:
    v_23880 = stack[0];
    goto v_23841;
v_23842:
    goto v_23836;
v_23837:
    goto v_23838;
v_23839:
    goto v_23840;
v_23841:
    {
        fn = elt(env, 6); // talp_gaussand
        return (*qfnn(fn))(fn, 3, v_23882, v_23881, v_23880);
    }
v_23818:
    goto v_23853;
v_23849:
    v_23880 = stack[-1];
    if (!consp(v_23880)) goto v_23856;
    else goto v_23857;
v_23856:
    v_23880 = stack[-1];
    v_23881 = v_23880;
    goto v_23855;
v_23857:
    v_23880 = stack[-1];
    v_23880 = qcar(v_23880);
    v_23881 = v_23880;
    goto v_23855;
    v_23881 = nil;
v_23855:
    goto v_23850;
v_23851:
    v_23880 = elt(env, 2); // or
    goto v_23852;
v_23853:
    goto v_23849;
v_23850:
    goto v_23851;
v_23852:
    if (v_23881 == v_23880) goto v_23847;
    else goto v_23848;
v_23847:
    goto v_23872;
v_23866:
    v_23882 = stack[-2];
    goto v_23867;
v_23868:
    v_23880 = stack[-1];
    v_23881 = qcdr(v_23880);
    goto v_23869;
v_23870:
    v_23880 = stack[0];
    goto v_23871;
v_23872:
    goto v_23866;
v_23867:
    goto v_23868;
v_23869:
    goto v_23870;
v_23871:
    {
        fn = elt(env, 7); // talp_gaussor
        return (*qfnn(fn))(fn, 3, v_23882, v_23881, v_23880);
    }
v_23848:
    v_23880 = elt(env, 3); // failed
    goto v_23804;
    v_23880 = nil;
v_23804:
    return onevalue(v_23880);
}



// Code for fctrf

static LispObject CC_fctrf(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_24023, v_24024, v_24025;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23799);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_23799;
// end of prologue
    v_24024 = qvalue(elt(env, 1)); // !*exp
    v_24023 = qvalue(elt(env, 2)); // ncmp!*
// Binding !*exp
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
    qvalue(elt(env, 1)) = v_24024; // !*exp
// Binding ncmp!*
// FLUIDBIND: reloadenv=7 litvec-offset=2 saveloc=4
{   bind_fluid_stack bind_fluid_var(-7, 2, -4);
    qvalue(elt(env, 2)) = v_24023; // ncmp!*
// Binding !*ezgcd
// FLUIDBIND: reloadenv=7 litvec-offset=3 saveloc=3
{   bind_fluid_stack bind_fluid_var(-7, 3, -3);
    qvalue(elt(env, 3)) = nil; // !*ezgcd
// Binding !*gcd
// FLUIDBIND: reloadenv=7 litvec-offset=4 saveloc=2
{   bind_fluid_stack bind_fluid_var(-7, 4, -2);
    qvalue(elt(env, 4)) = nil; // !*gcd
    stack[-1] = nil;
    v_24023 = stack[-5];
    if (!consp(v_24023)) goto v_23818;
    else goto v_23819;
v_23818:
    v_24023 = lisp_true;
    goto v_23817;
v_23819:
    v_24023 = stack[-5];
    v_24023 = qcar(v_24023);
    v_24023 = (consp(v_24023) ? nil : lisp_true);
    goto v_23817;
    v_24023 = nil;
v_23817:
    if (v_24023 == nil) goto v_23815;
    v_24023 = stack[-5];
    v_24023 = ncons(v_24023);
    goto v_23811;
v_23815:
    v_24023 = qvalue(elt(env, 2)); // ncmp!*
    if (v_24023 == nil) goto v_23830;
    v_24023 = stack[-5];
    fn = elt(env, 14); // noncomfp
    v_24023 = (*qfn1(fn))(fn, v_24023);
    env = stack[-7];
    if (v_24023 == nil) goto v_23833;
    else goto v_23830;
v_23833:
    v_24023 = nil;
    qvalue(elt(env, 2)) = v_24023; // ncmp!*
    goto v_23813;
v_23830:
v_23813:
    v_24023 = lisp_true;
    qvalue(elt(env, 4)) = v_24023; // !*gcd
    v_24023 = qvalue(elt(env, 5)); // !*limitedfactors
    if (v_24023 == nil) goto v_23844;
    else goto v_23845;
v_23844:
    v_24023 = qvalue(elt(env, 6)); // dmode!*
    v_24023 = (v_24023 == nil ? lisp_true : nil);
    goto v_23843;
v_23845:
    v_24023 = nil;
    goto v_23843;
    v_24023 = nil;
v_23843:
    if (v_24023 == nil) goto v_23841;
    v_24023 = lisp_true;
    qvalue(elt(env, 3)) = v_24023; // !*ezgcd
    goto v_23839;
v_23841:
v_23839:
    v_24023 = qvalue(elt(env, 7)); // !*mcd
    if (v_24023 == nil) goto v_23855;
    else goto v_23856;
v_23855:
    goto v_23865;
v_23859:
    v_24025 = elt(env, 8); // poly
    goto v_23860;
v_23861:
    v_24024 = (LispObject)240+TAG_FIXNUM; // 15
    goto v_23862;
v_23863:
    v_24023 = elt(env, 9); // "Factorization invalid with MCD off"
    goto v_23864;
v_23865:
    goto v_23859;
v_23860:
    goto v_23861;
v_23862:
    goto v_23863;
v_23864:
    fn = elt(env, 15); // rerror
    v_24023 = (*qfnn(fn))(fn, 3, v_24025, v_24024, v_24023);
    env = stack[-7];
    goto v_23854;
v_23856:
    v_24023 = qvalue(elt(env, 1)); // !*exp
    if (v_24023 == nil) goto v_23869;
    else goto v_23870;
v_23869:
    v_24023 = lisp_true;
    qvalue(elt(env, 1)) = v_24023; // !*exp
    goto v_23880;
v_23876:
    v_24024 = stack[-5];
    goto v_23877;
v_23878:
    v_24023 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23879;
v_23880:
    goto v_23876;
v_23877:
    goto v_23878;
v_23879:
    v_24023 = cons(v_24024, v_24023);
    env = stack[-7];
    fn = elt(env, 16); // resimp
    v_24023 = (*qfn1(fn))(fn, v_24023);
    env = stack[-7];
    fn = elt(env, 17); // !*q2f
    v_24023 = (*qfn1(fn))(fn, v_24023);
    env = stack[-7];
    stack[-5] = v_24023;
    goto v_23854;
v_23870:
v_23854:
    goto v_23891;
v_23887:
    v_24024 = qvalue(elt(env, 6)); // dmode!*
    goto v_23888;
v_23889:
    v_24023 = elt(env, 10); // !:rn!:
    goto v_23890;
v_23891:
    goto v_23887;
v_23888:
    goto v_23889;
v_23890:
    if (v_24024 == v_24023) goto v_23885;
    else goto v_23886;
v_23885:
    v_24023 = nil;
    qvalue(elt(env, 6)) = v_24023; // dmode!*
    v_24023 = nil;
    v_24023 = ncons(v_24023);
    env = stack[-7];
    qvalue(elt(env, 11)) = v_24023; // alglist!*
    v_24023 = stack[-5];
    fn = elt(env, 18); // prepf
    v_24023 = (*qfn1(fn))(fn, v_24023);
    env = stack[-7];
    fn = elt(env, 19); // simp
    v_24023 = (*qfn1(fn))(fn, v_24023);
    env = stack[-7];
    stack[0] = v_24023;
    v_24023 = stack[0];
    v_24023 = qcdr(v_24023);
    if (!consp(v_24023)) goto v_23902;
    else goto v_23903;
v_23902:
    v_24023 = stack[0];
    v_24023 = qcdr(v_24023);
    stack[-1] = v_24023;
    v_24023 = stack[0];
    v_24023 = qcar(v_24023);
    stack[-5] = v_24023;
    goto v_23901;
v_23903:
    v_24023 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_24023;
    goto v_23901;
v_23901:
    goto v_23884;
v_23886:
v_23884:
    v_24023 = qvalue(elt(env, 2)); // ncmp!*
    if (v_24023 == nil) goto v_23915;
    else goto v_23916;
v_23915:
    v_24023 = stack[-5];
    fn = elt(env, 20); // sf2ss
    v_24023 = (*qfn1(fn))(fn, v_24023);
    env = stack[-7];
    stack[0] = v_24023;
    v_24023 = stack[0];
    fn = elt(env, 21); // homogp
    v_24023 = (*qfn1(fn))(fn, v_24023);
    env = stack[-7];
    if (v_24023 == nil) goto v_23923;
    v_24023 = qvalue(elt(env, 12)); // !*trfac
    if (v_24023 == nil) goto v_23929;
    v_24023 = elt(env, 13); // "This polynomial is homogeneous - variables scaled"
    fn = elt(env, 22); // prin2t
    v_24023 = (*qfn1(fn))(fn, v_24023);
    env = stack[-7];
    goto v_23927;
v_23929:
v_23927:
    goto v_23938;
v_23934:
    v_24023 = stack[0];
    v_24023 = qcar(v_24023);
    v_24023 = qcar(v_24023);
    stack[-1] = qcar(v_24023);
    goto v_23935;
v_23936:
    v_24023 = stack[0];
    v_24023 = qcdr(v_24023);
    v_24023 = qcar(v_24023);
    v_24023 = qcar(v_24023);
    v_24023 = qcar(v_24023);
    fn = elt(env, 23); // listsum
    v_24023 = (*qfn1(fn))(fn, v_24023);
    env = stack[-7];
    goto v_23937;
v_23938:
    goto v_23934;
v_23935:
    goto v_23936;
v_23937:
    v_24023 = cons(stack[-1], v_24023);
    env = stack[-7];
    stack[-5] = v_24023;
    goto v_23958;
v_23952:
    v_24023 = stack[0];
    stack[-1] = qcar(v_24023);
    goto v_23953;
v_23954:
    v_24023 = stack[0];
    v_24023 = qcdr(v_24023);
    v_24023 = qcar(v_24023);
    fn = elt(env, 24); // subs0
    v_24023 = (*qfn1(fn))(fn, v_24023);
    env = stack[-7];
    v_24024 = Lreverse(nil, v_24023);
    env = stack[-7];
    goto v_23955;
v_23956:
    v_24023 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23957;
v_23958:
    goto v_23952;
v_23953:
    goto v_23954;
v_23955:
    goto v_23956;
v_23957:
    v_24023 = list2star(stack[-1], v_24024, v_24023);
    env = stack[-7];
    fn = elt(env, 25); // ss2sf
    v_24023 = (*qfn1(fn))(fn, v_24023);
    env = stack[-7];
    fn = elt(env, 26); // fctrf1
    v_24023 = (*qfn1(fn))(fn, v_24023);
    env = stack[-7];
    stack[0] = v_24023;
    goto v_23972;
v_23968:
    v_24024 = stack[-5];
    goto v_23969;
v_23970:
    v_24023 = stack[0];
    goto v_23971;
v_23972:
    goto v_23968;
v_23969:
    goto v_23970;
v_23971:
    fn = elt(env, 27); // rconst
    v_24023 = (*qfn2(fn))(fn, v_24024, v_24023);
    env = stack[-7];
    stack[0] = v_24023;
    goto v_23980;
v_23976:
    v_24023 = stack[0];
    stack[-1] = qcar(v_24023);
    goto v_23977;
v_23978:
    v_24023 = stack[0];
    v_24023 = qcdr(v_24023);
    fn = elt(env, 28); // sort!-factors
    v_24023 = (*qfn1(fn))(fn, v_24023);
    env = stack[-7];
    goto v_23979;
v_23980:
    goto v_23976;
v_23977:
    goto v_23978;
v_23979:
    v_24023 = cons(stack[-1], v_24023);
    goto v_23811;
v_23923:
    goto v_23914;
v_23916:
v_23914:
    v_24023 = stack[-5];
    fn = elt(env, 26); // fctrf1
    v_24023 = (*qfn1(fn))(fn, v_24023);
    env = stack[-7];
    stack[-5] = v_24023;
    v_24023 = stack[-1];
    if (v_24023 == nil) goto v_23991;
    v_24023 = nil;
    v_24023 = ncons(v_24023);
    env = stack[-7];
    qvalue(elt(env, 11)) = v_24023; // alglist!*
    v_24023 = elt(env, 10); // !:rn!:
    qvalue(elt(env, 6)) = v_24023; // dmode!*
    goto v_24001;
v_23997:
    stack[0] = stack[-5];
    goto v_23998;
v_23999:
    goto v_24008;
v_24004:
    v_24023 = stack[-5];
    v_24024 = qcar(v_24023);
    goto v_24005;
v_24006:
    v_24023 = stack[-1];
    goto v_24007;
v_24008:
    goto v_24004;
v_24005:
    goto v_24006;
v_24007:
    fn = elt(env, 29); // quotf!*
    v_24023 = (*qfn2(fn))(fn, v_24024, v_24023);
    env = stack[-7];
    goto v_24000;
v_24001:
    goto v_23997;
v_23998:
    goto v_23999;
v_24000:
    fn = elt(env, 30); // setcar
    v_24023 = (*qfn2(fn))(fn, stack[0], v_24023);
    env = stack[-7];
    goto v_23989;
v_23991:
v_23989:
    goto v_24017;
v_24013:
    v_24023 = stack[-5];
    stack[0] = qcar(v_24023);
    goto v_24014;
v_24015:
    v_24023 = stack[-5];
    v_24023 = qcdr(v_24023);
    fn = elt(env, 28); // sort!-factors
    v_24023 = (*qfn1(fn))(fn, v_24023);
    env = stack[-7];
    goto v_24016;
v_24017:
    goto v_24013;
v_24014:
    goto v_24015;
v_24016:
    v_24023 = cons(stack[0], v_24023);
v_23811:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_24023);
}



// Code for transposerd

static LispObject CC_transposerd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23807;
    LispObject fn;
    argcheck(nargs, 0, "transposerd");
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
    v_23807 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_23807;
    fn = elt(env, 2); // lex
    v_23807 = (*qfnn(fn))(fn, 0);
    v_23807 = stack[0];
    return ncons(v_23807);
    return onevalue(v_23807);
}



// Code for findelem2

static LispObject CC_findelem2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23858, v_23859, v_23860, v_23861, v_23862;
    LispObject v_23801, v_23800, v_23799;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "findelem2");
    va_start(aa, nargs);
    v_23799 = va_arg(aa, LispObject);
    v_23800 = va_arg(aa, LispObject);
    v_23801 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_23801,v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_23799,v_23800,v_23801);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_23858 = v_23801;
    v_23859 = v_23800;
    v_23860 = v_23799;
// end of prologue
    v_23861 = v_23860;
    v_23861 = Lconsp(nil, v_23861);
    env = stack[0];
    if (v_23861 == nil) goto v_23812;
    goto v_23821;
v_23817:
    v_23861 = v_23860;
    v_23861 = qcar(v_23861);
    goto v_23818;
v_23819:
    v_23862 = elt(env, 1); // sparsemat
    goto v_23820;
v_23821:
    goto v_23817;
v_23818:
    goto v_23819;
v_23820:
    if (v_23861 == v_23862) goto v_23816;
    else goto v_23812;
v_23816:
    v_23860 = qcdr(v_23860);
    v_23860 = qcar(v_23860);
    goto v_23810;
v_23812:
    goto v_23810;
v_23810:
    goto v_23835;
v_23831:
    goto v_23832;
v_23833:
    goto v_23834;
v_23835:
    goto v_23831;
v_23832:
    goto v_23833;
v_23834:
    v_23859 = *(LispObject *)((char *)v_23860 + (CELL-TAG_VECTOR) + (((intptr_t)v_23859-TAG_FIXNUM)/(16/CELL)));
    goto v_23843;
v_23839:
    goto v_23840;
v_23841:
    goto v_23842;
v_23843:
    goto v_23839;
v_23840:
    goto v_23841;
v_23842:
    v_23858 = Latsoc(nil, v_23858, v_23859);
    v_23859 = v_23858;
    v_23858 = v_23859;
    if (v_23858 == nil) goto v_23849;
    else goto v_23850;
v_23849:
    v_23858 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23848;
v_23850:
    v_23858 = v_23859;
    v_23858 = qcdr(v_23858);
    goto v_23848;
v_23848:
    return onevalue(v_23858);
}



// Code for inszzz

static LispObject CC_inszzz(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23919, v_23920;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23799,v_23800);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_23800;
    stack[-2] = v_23799;
// end of prologue
    stack[-3] = nil;
v_23805:
    v_23919 = stack[-1];
    if (v_23919 == nil) goto v_23812;
    else goto v_23813;
v_23812:
    v_23919 = lisp_true;
    goto v_23811;
v_23813:
    goto v_23823;
v_23819:
    v_23919 = stack[-1];
    v_23919 = qcar(v_23919);
    v_23920 = qcar(v_23919);
    goto v_23820;
v_23821:
    v_23919 = stack[-2];
    v_23919 = qcar(v_23919);
    goto v_23822;
v_23823:
    goto v_23819;
v_23820:
    goto v_23821;
v_23822:
    v_23919 = (LispObject)lessp2(v_23920, v_23919);
    v_23919 = v_23919 ? lisp_true : nil;
    env = stack[-4];
    goto v_23811;
    v_23919 = nil;
v_23811:
    if (v_23919 == nil) goto v_23809;
    goto v_23834;
v_23830:
    stack[0] = stack[-3];
    goto v_23831;
v_23832:
    goto v_23841;
v_23837:
    v_23920 = stack[-2];
    goto v_23838;
v_23839:
    v_23919 = stack[-1];
    goto v_23840;
v_23841:
    goto v_23837;
v_23838:
    goto v_23839;
v_23840:
    v_23919 = cons(v_23920, v_23919);
    env = stack[-4];
    goto v_23833;
v_23834:
    goto v_23830;
v_23831:
    goto v_23832;
v_23833:
    {
        LispObject v_23925 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_23925, v_23919);
    }
v_23809:
    goto v_23850;
v_23846:
    v_23919 = stack[-1];
    v_23919 = qcar(v_23919);
    v_23920 = qcar(v_23919);
    goto v_23847;
v_23848:
    v_23919 = stack[-2];
    v_23919 = qcar(v_23919);
    goto v_23849;
v_23850:
    goto v_23846;
v_23847:
    goto v_23848;
v_23849:
    if (equal(v_23920, v_23919)) goto v_23844;
    else goto v_23845;
v_23844:
    goto v_23861;
v_23857:
    v_23919 = stack[-1];
    v_23919 = qcar(v_23919);
    stack[0] = qcdr(v_23919);
    goto v_23858;
v_23859:
    goto v_23870;
v_23866:
    v_23919 = stack[-1];
    v_23919 = qcar(v_23919);
    v_23919 = qcdr(v_23919);
    v_23920 = qcar(v_23919);
    goto v_23867;
v_23868:
    v_23919 = stack[-2];
    v_23919 = qcdr(v_23919);
    v_23919 = qcar(v_23919);
    goto v_23869;
v_23870:
    goto v_23866;
v_23867:
    goto v_23868;
v_23869:
    fn = elt(env, 2); // dm!-plus
    v_23919 = (*qfn2(fn))(fn, v_23920, v_23919);
    env = stack[-4];
    goto v_23860;
v_23861:
    goto v_23857;
v_23858:
    goto v_23859;
v_23860:
    v_23919 = Lrplaca(nil, stack[0], v_23919);
    env = stack[-4];
    v_23919 = stack[-1];
    v_23919 = qcar(v_23919);
    v_23919 = qcdr(v_23919);
    v_23919 = qcar(v_23919);
    fn = elt(env, 3); // zeropp
    v_23919 = (*qfn1(fn))(fn, v_23919);
    env = stack[-4];
    if (v_23919 == nil) goto v_23881;
    goto v_23892;
v_23888:
    v_23920 = stack[-3];
    goto v_23889;
v_23890:
    v_23919 = stack[-1];
    v_23919 = qcdr(v_23919);
    goto v_23891;
v_23892:
    goto v_23888;
v_23889:
    goto v_23890;
v_23891:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_23920, v_23919);
    }
v_23881:
    goto v_23903;
v_23899:
    v_23920 = stack[-3];
    goto v_23900;
v_23901:
    v_23919 = stack[-1];
    goto v_23902;
v_23903:
    goto v_23899;
v_23900:
    goto v_23901;
v_23902:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_23920, v_23919);
    }
    goto v_23807;
v_23845:
    goto v_23913;
v_23909:
    v_23919 = stack[-1];
    v_23920 = qcar(v_23919);
    goto v_23910;
v_23911:
    v_23919 = stack[-3];
    goto v_23912;
v_23913:
    goto v_23909;
v_23910:
    goto v_23911;
v_23912:
    v_23919 = cons(v_23920, v_23919);
    env = stack[-4];
    stack[-3] = v_23919;
    v_23919 = stack[-1];
    v_23919 = qcdr(v_23919);
    stack[-1] = v_23919;
    goto v_23805;
v_23807:
    v_23919 = nil;
    return onevalue(v_23919);
}



// Code for get!:const

static LispObject CC_getTconst(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23891, v_23892;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23799,v_23800);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_23800;
    stack[-1] = v_23799;
// end of prologue
    v_23891 = stack[-1];
    if (!consp(v_23891)) goto v_23808;
    else goto v_23809;
v_23808:
    v_23891 = stack[0];
    v_23891 = integerp(v_23891);
    if (v_23891 == nil) goto v_23813;
    else goto v_23814;
v_23813:
    v_23891 = nil;
    goto v_23812;
v_23814:
    goto v_23825;
v_23821:
    v_23892 = stack[0];
    goto v_23822;
v_23823:
    v_23891 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23824;
v_23825:
    goto v_23821;
v_23822:
    goto v_23823;
v_23824:
    v_23891 = (LispObject)greaterp2(v_23892, v_23891);
    v_23891 = v_23891 ? lisp_true : nil;
    env = stack[-2];
    goto v_23812;
    v_23891 = nil;
v_23812:
    goto v_23807;
v_23809:
    v_23891 = nil;
    goto v_23807;
    v_23891 = nil;
v_23807:
    if (v_23891 == nil) goto v_23805;
    goto v_23839;
v_23835:
    v_23892 = stack[-1];
    goto v_23836;
v_23837:
    v_23891 = elt(env, 1); // save!:c
    goto v_23838;
v_23839:
    goto v_23835;
v_23836:
    goto v_23837;
v_23838:
    v_23891 = get(v_23892, v_23891);
    env = stack[-2];
    stack[-1] = v_23891;
    v_23891 = stack[-1];
    if (v_23891 == nil) goto v_23848;
    else goto v_23849;
v_23848:
    v_23891 = lisp_true;
    goto v_23847;
v_23849:
    goto v_23859;
v_23855:
    v_23891 = stack[-1];
    v_23892 = qcar(v_23891);
    goto v_23856;
v_23857:
    v_23891 = stack[0];
    goto v_23858;
v_23859:
    goto v_23855;
v_23856:
    goto v_23857;
v_23858:
    v_23891 = (LispObject)lessp2(v_23892, v_23891);
    v_23891 = v_23891 ? lisp_true : nil;
    env = stack[-2];
    goto v_23847;
    v_23891 = nil;
v_23847:
    if (v_23891 == nil) goto v_23845;
    v_23891 = elt(env, 2); // not_found
    goto v_23833;
v_23845:
    goto v_23870;
v_23866:
    v_23891 = stack[-1];
    v_23892 = qcar(v_23891);
    goto v_23867;
v_23868:
    v_23891 = stack[0];
    goto v_23869;
v_23870:
    goto v_23866;
v_23867:
    goto v_23868;
v_23869:
    if (equal(v_23892, v_23891)) goto v_23864;
    else goto v_23865;
v_23864:
    v_23891 = stack[-1];
    v_23891 = qcdr(v_23891);
    goto v_23833;
v_23865:
    goto v_23883;
v_23879:
    v_23891 = stack[-1];
    v_23892 = qcdr(v_23891);
    goto v_23880;
v_23881:
    v_23891 = stack[0];
    goto v_23882;
v_23883:
    goto v_23879;
v_23880:
    goto v_23881;
v_23882:
    {
        fn = elt(env, 3); // round!:mt
        return (*qfn2(fn))(fn, v_23892, v_23891);
    }
    v_23891 = nil;
v_23833:
    goto v_23803;
v_23805:
    v_23891 = elt(env, 0); // get!:const
    {
        fn = elt(env, 4); // bflerrmsg
        return (*qfn1(fn))(fn, v_23891);
    }
    v_23891 = nil;
v_23803:
    return onevalue(v_23891);
}



// Code for consrecip

static LispObject CC_consrecip(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_23841, v_23842, v_23843;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23843 = v_23799;
// end of prologue
    goto v_23813;
v_23809:
    v_23841 = v_23843;
    v_23842 = qcar(v_23841);
    goto v_23810;
v_23811:
    v_23841 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23812;
v_23813:
    goto v_23809;
v_23810:
    goto v_23811;
v_23812:
    if (v_23842 == v_23841) goto v_23807;
    else goto v_23808;
v_23807:
    v_23841 = lisp_true;
    goto v_23806;
v_23808:
    goto v_23824;
v_23820:
    v_23841 = v_23843;
    v_23842 = qcar(v_23841);
    goto v_23821;
v_23822:
    v_23841 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_23823;
v_23824:
    goto v_23820;
v_23821:
    goto v_23822;
v_23823:
    v_23841 = (v_23842 == v_23841 ? lisp_true : nil);
    goto v_23806;
    v_23841 = nil;
v_23806:
    if (v_23841 == nil) goto v_23804;
    v_23841 = v_23843;
    v_23841 = qcar(v_23841);
    goto v_23802;
v_23804:
    goto v_23838;
v_23834:
    v_23841 = elt(env, 1); // recip
    goto v_23835;
v_23836:
    v_23842 = v_23843;
    goto v_23837;
v_23838:
    goto v_23834;
v_23835:
    goto v_23836;
v_23837:
    return cons(v_23841, v_23842);
    v_23841 = nil;
v_23802:
    return onevalue(v_23841);
}



// Code for splitup

static LispObject CC_splitup(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23874, v_23875, v_23876;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23799,v_23800);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_23876 = v_23800;
    stack[0] = v_23799;
// end of prologue
    v_23874 = stack[0];
    if (v_23874 == nil) goto v_23804;
    else goto v_23805;
v_23804:
    goto v_23812;
v_23808:
    v_23875 = nil;
    goto v_23809;
v_23810:
    v_23874 = nil;
    goto v_23811;
v_23812:
    goto v_23808;
v_23809:
    goto v_23810;
v_23811:
    return list2(v_23875, v_23874);
v_23805:
    v_23874 = stack[0];
    v_23874 = qcar(v_23874);
    v_23874 = qcar(v_23874);
    v_23874 = qcar(v_23874);
    v_23875 = v_23874;
    v_23874 = v_23875;
    if (v_23874 == nil) goto v_23824;
    else goto v_23825;
v_23824:
    v_23874 = lisp_true;
    goto v_23823;
v_23825:
    goto v_23834;
v_23830:
    goto v_23831;
v_23832:
    v_23874 = v_23876;
    goto v_23833;
v_23834:
    goto v_23830;
v_23831:
    goto v_23832;
v_23833:
    v_23874 = Lmemq(nil, v_23875, v_23874);
    goto v_23823;
    v_23874 = nil;
v_23823:
    if (v_23874 == nil) goto v_23816;
    goto v_23843;
v_23839:
    v_23875 = nil;
    goto v_23840;
v_23841:
    v_23874 = stack[0];
    goto v_23842;
v_23843:
    goto v_23839;
v_23840:
    goto v_23841;
v_23842:
    return list2(v_23875, v_23874);
v_23816:
    goto v_23853;
v_23849:
    v_23874 = stack[0];
    v_23874 = qcdr(v_23874);
    goto v_23850;
v_23851:
    v_23875 = v_23876;
    goto v_23852;
v_23853:
    goto v_23849;
v_23850:
    goto v_23851;
v_23852:
    v_23874 = CC_splitup(elt(env, 0), v_23874, v_23875);
    env = stack[-2];
    v_23875 = v_23874;
    goto v_23865;
v_23859:
    v_23874 = stack[0];
    stack[-1] = qcar(v_23874);
    goto v_23860;
v_23861:
    v_23874 = v_23875;
    stack[0] = qcar(v_23874);
    goto v_23862;
v_23863:
    v_23874 = v_23875;
    v_23874 = qcdr(v_23874);
    v_23874 = qcar(v_23874);
    v_23874 = ncons(v_23874);
    goto v_23864;
v_23865:
    goto v_23859;
v_23860:
    goto v_23861;
v_23862:
    goto v_23863;
v_23864:
    {
        LispObject v_23879 = stack[-1];
        LispObject v_23880 = stack[0];
        return acons(v_23879, v_23880, v_23874);
    }
    v_23874 = nil;
    return onevalue(v_23874);
}



// Code for groeb!=testc1

static LispObject CC_groebMtestc1(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_23841, v_23842;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23799);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_23799;
// end of prologue
    goto v_23806;
v_23802:
    goto v_23812;
v_23808:
    goto v_23820;
v_23816:
    v_23842 = stack[0];
    goto v_23817;
v_23818:
    v_23841 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_23819;
v_23820:
    goto v_23816;
v_23817:
    goto v_23818;
v_23819:
    fn = elt(env, 1); // nth
    v_23841 = (*qfn2(fn))(fn, v_23842, v_23841);
    env = stack[-2];
    fn = elt(env, 2); // bas_dpoly
    v_23841 = (*qfn1(fn))(fn, v_23841);
    env = stack[-2];
    fn = elt(env, 3); // dp_lmon
    stack[-1] = (*qfn1(fn))(fn, v_23841);
    env = stack[-2];
    goto v_23809;
v_23810:
    goto v_23830;
v_23826:
    v_23842 = stack[0];
    goto v_23827;
v_23828:
    v_23841 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_23829;
v_23830:
    goto v_23826;
v_23827:
    goto v_23828;
v_23829:
    fn = elt(env, 1); // nth
    v_23841 = (*qfn2(fn))(fn, v_23842, v_23841);
    env = stack[-2];
    fn = elt(env, 2); // bas_dpoly
    v_23841 = (*qfn1(fn))(fn, v_23841);
    env = stack[-2];
    fn = elt(env, 3); // dp_lmon
    v_23841 = (*qfn1(fn))(fn, v_23841);
    env = stack[-2];
    goto v_23811;
v_23812:
    goto v_23808;
v_23809:
    goto v_23810;
v_23811:
    fn = elt(env, 4); // mo_sum
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_23841);
    env = stack[-2];
    goto v_23803;
v_23804:
    goto v_23838;
v_23834:
    v_23842 = stack[0];
    goto v_23835;
v_23836:
    v_23841 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_23837;
v_23838:
    goto v_23834;
v_23835:
    goto v_23836;
v_23837:
    fn = elt(env, 1); // nth
    v_23841 = (*qfn2(fn))(fn, v_23842, v_23841);
    env = stack[-2];
    goto v_23805;
v_23806:
    goto v_23802;
v_23803:
    goto v_23804;
v_23805:
    {
        LispObject v_23845 = stack[-1];
        fn = elt(env, 5); // mo_equal!?
        return (*qfn2(fn))(fn, v_23845, v_23841);
    }
}



// Code for list2vect!*

static LispObject CC_list2vectH(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23873, v_23874;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23799,v_23800);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_23800;
    stack[-4] = v_23799;
// end of prologue
    v_23873 = stack[-4];
    v_23873 = Llength(nil, v_23873);
    env = stack[-6];
    v_23873 = sub1(v_23873);
    env = stack[-6];
    v_23873 = Lmkvect(nil, v_23873);
    env = stack[-6];
    stack[-5] = v_23873;
    v_23873 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_23873;
v_23812:
    goto v_23824;
v_23820:
    v_23873 = stack[-5];
    v_23873 = Lupbv(nil, v_23873);
    env = stack[-6];
    v_23874 = add1(v_23873);
    env = stack[-6];
    goto v_23821;
v_23822:
    v_23873 = stack[-2];
    goto v_23823;
v_23824:
    goto v_23820;
v_23821:
    goto v_23822;
v_23823:
    v_23873 = difference2(v_23874, v_23873);
    env = stack[-6];
    v_23873 = Lminusp(nil, v_23873);
    env = stack[-6];
    if (v_23873 == nil) goto v_23817;
    goto v_23811;
v_23817:
    goto v_23836;
v_23830:
    stack[-1] = stack[-5];
    goto v_23831;
v_23832:
    v_23873 = stack[-2];
    stack[0] = sub1(v_23873);
    env = stack[-6];
    goto v_23833;
v_23834:
    goto v_23848;
v_23844:
    v_23874 = stack[-3];
    goto v_23845;
v_23846:
    v_23873 = elt(env, 1); // algebraic
    goto v_23847;
v_23848:
    goto v_23844;
v_23845:
    goto v_23846;
v_23847:
    if (v_23874 == v_23873) goto v_23842;
    else goto v_23843;
v_23842:
    goto v_23857;
v_23853:
    v_23874 = stack[-4];
    goto v_23854;
v_23855:
    v_23873 = stack[-2];
    goto v_23856;
v_23857:
    goto v_23853;
v_23854:
    goto v_23855;
v_23856:
    fn = elt(env, 2); // nth
    v_23873 = (*qfn2(fn))(fn, v_23874, v_23873);
    env = stack[-6];
    fn = elt(env, 3); // symb_to_alg
    v_23873 = (*qfn1(fn))(fn, v_23873);
    env = stack[-6];
    goto v_23841;
v_23843:
    goto v_23867;
v_23863:
    v_23874 = stack[-4];
    goto v_23864;
v_23865:
    v_23873 = stack[-2];
    goto v_23866;
v_23867:
    goto v_23863;
v_23864:
    goto v_23865;
v_23866:
    fn = elt(env, 2); // nth
    v_23873 = (*qfn2(fn))(fn, v_23874, v_23873);
    env = stack[-6];
    goto v_23841;
    v_23873 = nil;
v_23841:
    goto v_23835;
v_23836:
    goto v_23830;
v_23831:
    goto v_23832;
v_23833:
    goto v_23834;
v_23835:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_23873;
    v_23873 = stack[-2];
    v_23873 = add1(v_23873);
    env = stack[-6];
    stack[-2] = v_23873;
    goto v_23812;
v_23811:
    v_23873 = stack[-5];
    return onevalue(v_23873);
}



// Code for basic!-kern

static LispObject CC_basicKkern(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_23829, v_23830;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23799);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_23830 = v_23799;
// end of prologue
    v_23829 = nil;
    stack[-1] = v_23829;
    v_23829 = v_23830;
    stack[0] = v_23829;
v_23806:
    v_23829 = stack[0];
    if (v_23829 == nil) goto v_23810;
    else goto v_23811;
v_23810:
    goto v_23805;
v_23811:
    v_23829 = stack[0];
    v_23829 = qcar(v_23829);
    goto v_23822;
v_23818:
    fn = elt(env, 1); // basic!-kern1
    v_23830 = (*qfn1(fn))(fn, v_23829);
    env = stack[-2];
    goto v_23819;
v_23820:
    v_23829 = stack[-1];
    goto v_23821;
v_23822:
    goto v_23818;
v_23819:
    goto v_23820;
v_23821:
    fn = elt(env, 2); // union
    v_23829 = (*qfn2(fn))(fn, v_23830, v_23829);
    env = stack[-2];
    stack[-1] = v_23829;
    v_23829 = stack[0];
    v_23829 = qcdr(v_23829);
    stack[0] = v_23829;
    goto v_23806;
v_23805:
    v_23829 = stack[-1];
    return onevalue(v_23829);
}



// Code for xquotient!-mod!-p

static LispObject CC_xquotientKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_24003, v_24004, v_24005;
    LispObject fn;
    LispObject v_23801, v_23800, v_23799;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xquotient-mod-p");
    va_start(aa, nargs);
    v_23799 = va_arg(aa, LispObject);
    v_23800 = va_arg(aa, LispObject);
    v_23801 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_23801,v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_23799,v_23800,v_23801);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_23801;
    stack[-1] = v_23800;
    stack[-2] = v_23799;
// end of prologue
    v_24003 = stack[-2];
    if (v_24003 == nil) goto v_23805;
    else goto v_23806;
v_23805:
    v_24003 = nil;
    goto v_23804;
v_23806:
    v_24003 = stack[-2];
    if (!consp(v_24003)) goto v_23817;
    else goto v_23818;
v_23817:
    v_24003 = lisp_true;
    goto v_23816;
v_23818:
    v_24003 = stack[-2];
    v_24003 = qcar(v_24003);
    v_24003 = (consp(v_24003) ? nil : lisp_true);
    goto v_23816;
    v_24003 = nil;
v_23816:
    if (v_24003 == nil) goto v_23814;
    v_24003 = lisp_true;
    goto v_23812;
v_23814:
    goto v_23837;
v_23833:
    v_24003 = stack[-2];
    v_24003 = qcar(v_24003);
    v_24003 = qcar(v_24003);
    v_24004 = qcar(v_24003);
    goto v_23834;
v_23835:
    v_24003 = stack[0];
    goto v_23836;
v_23837:
    goto v_23833;
v_23834:
    goto v_23835;
v_23836:
    if (equal(v_24004, v_24003)) goto v_23832;
    v_24003 = lisp_true;
    goto v_23830;
v_23832:
    goto v_23850;
v_23846:
    v_24003 = stack[-2];
    v_24003 = qcar(v_24003);
    v_24003 = qcar(v_24003);
    v_24004 = qcdr(v_24003);
    goto v_23847;
v_23848:
    v_24003 = stack[-1];
    v_24003 = qcar(v_24003);
    v_24003 = qcar(v_24003);
    v_24003 = qcdr(v_24003);
    goto v_23849;
v_23850:
    goto v_23846;
v_23847:
    goto v_23848;
v_23849:
    v_24003 = ((intptr_t)v_24004 < (intptr_t)v_24003) ? lisp_true : nil;
    goto v_23830;
    v_24003 = nil;
v_23830:
    goto v_23812;
    v_24003 = nil;
v_23812:
    if (v_24003 == nil) goto v_23810;
    v_24003 = nil;
    qvalue(elt(env, 1)) = v_24003; // exact!-quotient!-flag
    goto v_23804;
v_23810:
    goto v_23867;
v_23863:
    v_24003 = stack[-2];
    v_24003 = qcar(v_24003);
    v_24003 = qcar(v_24003);
    v_24004 = qcdr(v_24003);
    goto v_23864;
v_23865:
    v_24003 = stack[-1];
    v_24003 = qcar(v_24003);
    v_24003 = qcar(v_24003);
    v_24003 = qcdr(v_24003);
    goto v_23866;
v_23867:
    goto v_23863;
v_23864:
    goto v_23865;
v_23866:
    if (equal(v_24004, v_24003)) goto v_23861;
    else goto v_23862;
v_23861:
    goto v_23884;
v_23880:
    v_24003 = stack[-2];
    v_24003 = qcar(v_24003);
    v_24004 = qcdr(v_24003);
    goto v_23881;
v_23882:
    v_24003 = stack[-1];
    v_24003 = qcar(v_24003);
    v_24003 = qcdr(v_24003);
    goto v_23883;
v_23884:
    goto v_23880;
v_23881:
    goto v_23882;
v_23883:
    fn = elt(env, 2); // quotient!-mod!-p
    v_24003 = (*qfn2(fn))(fn, v_24004, v_24003);
    env = stack[-4];
    stack[0] = v_24003;
    v_24003 = stack[0];
    if (v_24003 == nil) goto v_23897;
    else goto v_23898;
v_23897:
    v_24003 = lisp_true;
    goto v_23896;
v_23898:
    goto v_23908;
v_23904:
    goto v_23905;
v_23906:
    goto v_23915;
v_23911:
    v_24004 = stack[0];
    goto v_23912;
v_23913:
    v_24003 = stack[-1];
    goto v_23914;
v_23915:
    goto v_23911;
v_23912:
    goto v_23913;
v_23914:
    fn = elt(env, 3); // times!-mod!-p
    v_24003 = (*qfn2(fn))(fn, v_24004, v_24003);
    env = stack[-4];
    goto v_23907;
v_23908:
    goto v_23904;
v_23905:
    goto v_23906;
v_23907:
    fn = elt(env, 4); // difference!-mod!-p
    v_24003 = (*qfn2(fn))(fn, stack[-2], v_24003);
    env = stack[-4];
    goto v_23896;
    v_24003 = nil;
v_23896:
    if (v_24003 == nil) goto v_23894;
    v_24003 = nil;
    qvalue(elt(env, 1)) = v_24003; // exact!-quotient!-flag
    goto v_23892;
v_23894:
v_23892:
    v_24003 = stack[0];
    goto v_23804;
v_23862:
    goto v_23930;
v_23926:
    goto v_23936;
v_23932:
    v_24003 = stack[-2];
    v_24003 = qcar(v_24003);
    v_24003 = qcar(v_24003);
    v_24005 = qcar(v_24003);
    goto v_23933;
v_23934:
    goto v_23945;
v_23941:
    v_24003 = stack[-2];
    v_24003 = qcar(v_24003);
    v_24003 = qcar(v_24003);
    v_24004 = qcdr(v_24003);
    goto v_23942;
v_23943:
    v_24003 = stack[-1];
    v_24003 = qcar(v_24003);
    v_24003 = qcar(v_24003);
    v_24003 = qcdr(v_24003);
    goto v_23944;
v_23945:
    goto v_23941;
v_23942:
    goto v_23943;
v_23944:
    v_24003 = (LispObject)(intptr_t)((intptr_t)v_24004 - (intptr_t)v_24003 + TAG_FIXNUM);
    goto v_23935;
v_23936:
    goto v_23932;
v_23933:
    goto v_23934;
v_23935:
    fn = elt(env, 5); // mksp
    stack[-3] = (*qfn2(fn))(fn, v_24005, v_24003);
    env = stack[-4];
    goto v_23927;
v_23928:
    goto v_23960;
v_23956:
    v_24003 = stack[-2];
    v_24003 = qcar(v_24003);
    v_24004 = qcdr(v_24003);
    goto v_23957;
v_23958:
    v_24003 = stack[-1];
    v_24003 = qcar(v_24003);
    v_24003 = qcdr(v_24003);
    goto v_23959;
v_23960:
    goto v_23956;
v_23957:
    goto v_23958;
v_23959:
    fn = elt(env, 2); // quotient!-mod!-p
    v_24003 = (*qfn2(fn))(fn, v_24004, v_24003);
    env = stack[-4];
    goto v_23929;
v_23930:
    goto v_23926;
v_23927:
    goto v_23928;
v_23929:
    v_24003 = cons(stack[-3], v_24003);
    env = stack[-4];
    stack[-3] = v_24003;
    goto v_23972;
v_23968:
    v_24003 = stack[-2];
    stack[-2] = qcdr(v_24003);
    goto v_23969;
v_23970:
    goto v_23980;
v_23976:
    v_24003 = stack[-3];
    fn = elt(env, 6); // negate!-term
    v_24004 = (*qfn1(fn))(fn, v_24003);
    env = stack[-4];
    goto v_23977;
v_23978:
    v_24003 = stack[-1];
    v_24003 = qcdr(v_24003);
    goto v_23979;
v_23980:
    goto v_23976;
v_23977:
    goto v_23978;
v_23979:
    fn = elt(env, 7); // times!-term!-mod!-p
    v_24003 = (*qfn2(fn))(fn, v_24004, v_24003);
    env = stack[-4];
    goto v_23971;
v_23972:
    goto v_23968;
v_23969:
    goto v_23970;
v_23971:
    fn = elt(env, 8); // plus!-mod!-p
    v_24003 = (*qfn2(fn))(fn, stack[-2], v_24003);
    env = stack[-4];
    stack[-2] = v_24003;
    goto v_23990;
v_23986:
    goto v_23987;
v_23988:
    goto v_23999;
v_23993:
    v_24005 = stack[-2];
    goto v_23994;
v_23995:
    v_24004 = stack[-1];
    goto v_23996;
v_23997:
    v_24003 = stack[0];
    goto v_23998;
v_23999:
    goto v_23993;
v_23994:
    goto v_23995;
v_23996:
    goto v_23997;
v_23998:
    v_24003 = CC_xquotientKmodKp(elt(env, 0), 3, v_24005, v_24004, v_24003);
    goto v_23989;
v_23990:
    goto v_23986;
v_23987:
    goto v_23988;
v_23989:
    {
        LispObject v_24010 = stack[-3];
        return cons(v_24010, v_24003);
    }
    goto v_23804;
    v_24003 = nil;
v_23804:
    return onevalue(v_24003);
}



// Code for algmodep

static LispObject CC_algmodep(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_23818, v_23819;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23819 = v_23799;
// end of prologue
    v_23818 = v_23819;
    if (!consp(v_23818)) goto v_23804;
    goto v_23810;
v_23806:
    v_23818 = v_23819;
    v_23818 = qcar(v_23818);
    goto v_23807;
v_23808:
    v_23819 = elt(env, 1); // (aeval aeval!*)
    goto v_23809;
v_23810:
    goto v_23806;
v_23807:
    goto v_23808;
v_23809:
    v_23818 = Lmemq(nil, v_23818, v_23819);
    goto v_23802;
v_23804:
    v_23818 = nil;
    goto v_23802;
    v_23818 = nil;
v_23802:
    return onevalue(v_23818);
}



// Code for xnp

static LispObject CC_xnp(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23831, v_23832, v_23833, v_23834;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23832 = v_23800;
    v_23833 = v_23799;
// end of prologue
v_23798:
    v_23831 = v_23833;
    if (v_23831 == nil) goto v_23804;
    else goto v_23805;
v_23804:
    v_23831 = nil;
    goto v_23803;
v_23805:
    goto v_23817;
v_23813:
    v_23831 = v_23833;
    v_23834 = qcar(v_23831);
    goto v_23814;
v_23815:
    v_23831 = v_23832;
    goto v_23816;
v_23817:
    goto v_23813;
v_23814:
    goto v_23815;
v_23816:
    v_23831 = Lmemq(nil, v_23834, v_23831);
    if (v_23831 == nil) goto v_23812;
    else goto v_23811;
v_23812:
    goto v_23827;
v_23823:
    v_23831 = v_23833;
    v_23833 = qcdr(v_23831);
    goto v_23824;
v_23825:
    v_23831 = v_23832;
    goto v_23826;
v_23827:
    goto v_23823;
v_23824:
    goto v_23825;
v_23826:
    v_23832 = v_23831;
    goto v_23798;
v_23811:
    goto v_23803;
    v_23831 = nil;
v_23803:
    return onevalue(v_23831);
}



// Code for lalr_set_nonterminal_codes

static LispObject CC_lalr_set_nonterminal_codes(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23889, v_23890, v_23891;
    argcheck(nargs, 0, "lalr_set_nonterminal_codes");
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
    v_23889 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_23889;
    v_23889 = qvalue(elt(env, 1)); // nonterminals
    stack[-1] = v_23889;
v_23807:
    v_23889 = stack[-1];
    if (v_23889 == nil) goto v_23811;
    else goto v_23812;
v_23811:
    goto v_23806;
v_23812:
    v_23889 = stack[-1];
    v_23889 = qcar(v_23889);
    stack[0] = v_23889;
    goto v_23826;
v_23822:
    v_23890 = stack[0];
    goto v_23823;
v_23824:
    v_23889 = elt(env, 2); // !S!'
    goto v_23825;
v_23826:
    goto v_23822;
v_23823:
    goto v_23824;
v_23825:
    if (v_23890 == v_23889) goto v_23820;
    else goto v_23821;
v_23820:
    goto v_23836;
v_23830:
    v_23891 = stack[0];
    goto v_23831;
v_23832:
    v_23890 = elt(env, 3); // lalr_nonterminal_code
    goto v_23833;
v_23834:
    v_23889 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_23835;
v_23836:
    goto v_23830;
v_23831:
    goto v_23832;
v_23833:
    goto v_23834;
v_23835:
    v_23889 = Lputprop(nil, 3, v_23891, v_23890, v_23889);
    env = stack[-3];
    goto v_23819;
v_23821:
    goto v_23849;
v_23843:
    v_23891 = stack[0];
    goto v_23844;
v_23845:
    v_23890 = elt(env, 3); // lalr_nonterminal_code
    goto v_23846;
v_23847:
    v_23889 = stack[-2];
    goto v_23848;
v_23849:
    goto v_23843;
v_23844:
    goto v_23845;
v_23846:
    goto v_23847;
v_23848:
    v_23889 = Lputprop(nil, 3, v_23891, v_23890, v_23889);
    env = stack[-3];
    v_23889 = qvalue(elt(env, 4)); // !*lalr_verbose
    if (v_23889 == nil) goto v_23856;
    goto v_23865;
v_23859:
    v_23891 = stack[-2];
    goto v_23860;
v_23861:
    v_23890 = stack[0];
    goto v_23862;
v_23863:
    v_23889 = qvalue(elt(env, 5)); // nonterminal_codes
    goto v_23864;
v_23865:
    goto v_23859;
v_23860:
    goto v_23861;
v_23862:
    goto v_23863;
v_23864:
    v_23889 = acons(v_23891, v_23890, v_23889);
    env = stack[-3];
    qvalue(elt(env, 5)) = v_23889; // nonterminal_codes
    goto v_23854;
v_23856:
v_23854:
    v_23889 = stack[-2];
    v_23889 = add1(v_23889);
    env = stack[-3];
    stack[-2] = v_23889;
    goto v_23819;
v_23819:
    v_23889 = stack[-1];
    v_23889 = qcdr(v_23889);
    stack[-1] = v_23889;
    goto v_23807;
v_23806:
    v_23889 = qvalue(elt(env, 4)); // !*lalr_verbose
    if (v_23889 == nil) goto v_23876;
    goto v_23885;
v_23879:
    v_23891 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_23880;
v_23881:
    v_23890 = elt(env, 2); // !S!'
    goto v_23882;
v_23883:
    v_23889 = qvalue(elt(env, 5)); // nonterminal_codes
    goto v_23884;
v_23885:
    goto v_23879;
v_23880:
    goto v_23881;
v_23882:
    goto v_23883;
v_23884:
    v_23889 = acons(v_23891, v_23890, v_23889);
    env = stack[-3];
    qvalue(elt(env, 5)) = v_23889; // nonterminal_codes
    goto v_23874;
v_23876:
v_23874:
    v_23889 = nil;
    return onevalue(v_23889);
}



// Code for cl_subfof

static LispObject CC_cl_subfof(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23891, v_23892, v_23893, v_23894;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23799,v_23800);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_23800;
    stack[-5] = v_23799;
// end of prologue
    stack[-6] = nil;
    stack[-2] = nil;
    v_23891 = stack[-5];
    fn = elt(env, 1); // rl_subalchk
    v_23891 = (*qfn1(fn))(fn, v_23891);
    env = stack[-7];
    v_23891 = stack[-5];
    stack[-1] = v_23891;
v_23812:
    v_23891 = stack[-1];
    if (v_23891 == nil) goto v_23816;
    else goto v_23817;
v_23816:
    goto v_23811;
v_23817:
    v_23891 = stack[-1];
    v_23891 = qcar(v_23891);
    stack[0] = v_23891;
    v_23891 = stack[0];
    fn = elt(env, 2); // rl_eqnrhskernels
    v_23891 = (*qfn1(fn))(fn, v_23891);
    env = stack[-7];
    stack[-3] = v_23891;
    goto v_23831;
v_23827:
    goto v_23838;
v_23834:
    v_23891 = stack[0];
    v_23892 = qcar(v_23891);
    goto v_23835;
v_23836:
    v_23891 = stack[-3];
    goto v_23837;
v_23838:
    goto v_23834;
v_23835:
    goto v_23836;
v_23837:
    v_23891 = cons(v_23892, v_23891);
    env = stack[-7];
    v_23892 = ncons(v_23891);
    env = stack[-7];
    goto v_23828;
v_23829:
    v_23891 = stack[-6];
    goto v_23830;
v_23831:
    goto v_23827;
v_23828:
    goto v_23829;
v_23830:
    v_23891 = list2(v_23892, v_23891);
    env = stack[-7];
    fn = elt(env, 3); // lto_alunion
    v_23891 = (*qfn1(fn))(fn, v_23891);
    env = stack[-7];
    stack[-6] = v_23891;
    goto v_23848;
v_23844:
    v_23891 = stack[0];
    stack[0] = qcar(v_23891);
    goto v_23845;
v_23846:
    goto v_23856;
v_23852:
    v_23892 = stack[-3];
    goto v_23853;
v_23854:
    v_23891 = stack[-2];
    goto v_23855;
v_23856:
    goto v_23852;
v_23853:
    goto v_23854;
v_23855:
    v_23891 = Lappend(nil, v_23892, v_23891);
    env = stack[-7];
    goto v_23847;
v_23848:
    goto v_23844;
v_23845:
    goto v_23846;
v_23847:
    v_23891 = cons(stack[0], v_23891);
    env = stack[-7];
    stack[-2] = v_23891;
    v_23891 = stack[-1];
    v_23891 = qcdr(v_23891);
    stack[-1] = v_23891;
    goto v_23812;
v_23811:
    v_23891 = stack[-4];
    fn = elt(env, 4); // cl_varl1
    v_23891 = (*qfn1(fn))(fn, v_23891);
    env = stack[-7];
    stack[-3] = v_23891;
    goto v_23871;
v_23865:
    v_23893 = stack[-2];
    goto v_23866;
v_23867:
    v_23891 = stack[-3];
    v_23892 = qcar(v_23891);
    goto v_23868;
v_23869:
    v_23891 = stack[-3];
    v_23891 = qcdr(v_23891);
    goto v_23870;
v_23871:
    goto v_23865;
v_23866:
    goto v_23867;
v_23868:
    goto v_23869;
v_23870:
    v_23891 = list3(v_23893, v_23892, v_23891);
    env = stack[-7];
    fn = elt(env, 5); // lto_nconcn
    v_23891 = (*qfn1(fn))(fn, v_23891);
    env = stack[-7];
    stack[-2] = v_23891;
    goto v_23886;
v_23878:
    v_23894 = stack[-5];
    goto v_23879;
v_23880:
    v_23893 = stack[-4];
    goto v_23881;
v_23882:
    v_23892 = stack[-6];
    goto v_23883;
v_23884:
    v_23891 = stack[-2];
    goto v_23885;
v_23886:
    goto v_23878;
v_23879:
    goto v_23880;
v_23881:
    goto v_23882;
v_23883:
    goto v_23884;
v_23885:
    {
        fn = elt(env, 6); // cl_subfof1
        return (*qfnn(fn))(fn, 4, v_23894, v_23893, v_23892, v_23891);
    }
    return onevalue(v_23891);
}



// Code for cl_sacatlp

static LispObject CC_cl_sacatlp(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23803, v_23804;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23803 = v_23800;
    v_23804 = v_23799;
// end of prologue
    v_23803 = lisp_true;
    return onevalue(v_23803);
}



// Code for ofsf_anegrel

static LispObject CC_ofsf_anegrel(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_23822, v_23823, v_23824;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23799);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_23824 = v_23799;
// end of prologue
    goto v_23808;
v_23804:
    v_23823 = v_23824;
    goto v_23805;
v_23806:
    v_23822 = elt(env, 1); // ((equal . equal) (neq . neq) (leq . geq) (geq . leq) (lessp . greaterp) (greaterp . lessp))
    goto v_23807;
v_23808:
    goto v_23804;
v_23805:
    goto v_23806;
v_23807:
    v_23822 = Latsoc(nil, v_23823, v_23822);
    v_23822 = qcdr(v_23822);
    if (v_23822 == nil) goto v_23803;
    else goto v_23802;
v_23803:
    goto v_23819;
v_23815:
    v_23822 = elt(env, 2); // "ofsf_anegrel: unknown operator "
    goto v_23816;
v_23817:
    v_23823 = v_23824;
    goto v_23818;
v_23819:
    goto v_23815;
v_23816:
    goto v_23817;
v_23818:
    v_23822 = list2(v_23822, v_23823);
    env = stack[0];
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_23822);
    }
v_23802:
    return onevalue(v_23822);
}



// Code for diffrd

static LispObject CC_diffrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_23832, v_23833;
    LispObject fn;
    argcheck(nargs, 0, "diffrd");
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
    fn = elt(env, 3); // lex
    v_23832 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_23813;
v_23809:
    v_23833 = qvalue(elt(env, 1)); // char
    goto v_23810;
v_23811:
    v_23832 = elt(env, 2); // (b v a r)
    goto v_23812;
v_23813:
    goto v_23809;
v_23810:
    goto v_23811;
v_23812:
    if (equal(v_23833, v_23832)) goto v_23807;
    else goto v_23808;
v_23807:
    fn = elt(env, 4); // bvarrd
    v_23832 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_23832;
    fn = elt(env, 3); // lex
    v_23832 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_23806;
v_23808:
    v_23832 = nil;
    stack[-1] = v_23832;
    goto v_23806;
v_23806:
    fn = elt(env, 5); // mathml2
    v_23832 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[0] = v_23832;
    fn = elt(env, 3); // lex
    v_23832 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_23829;
v_23825:
    v_23833 = stack[-1];
    goto v_23826;
v_23827:
    v_23832 = stack[0];
    goto v_23828;
v_23829:
    goto v_23825;
v_23826:
    goto v_23827;
v_23828:
    v_23832 = list2(v_23833, v_23832);
    env = stack[-2];
    {
        fn = elt(env, 6); // diff2
        return (*qfn1(fn))(fn, v_23832);
    }
    return onevalue(v_23832);
}



// Code for insertocc

static LispObject CC_insertocc(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23851, v_23852, v_23853;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_23800,v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_23799,v_23800);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_23853 = v_23800;
    stack[-1] = v_23799;
// end of prologue
    goto v_23813;
v_23809:
    v_23852 = v_23853;
    goto v_23810;
v_23811:
    v_23851 = stack[-1];
    goto v_23812;
v_23813:
    goto v_23809;
v_23810:
    goto v_23811;
v_23812:
    v_23851 = Lassoc(nil, v_23852, v_23851);
    stack[-2] = v_23851;
    if (v_23851 == nil) goto v_23808;
    goto v_23824;
v_23818:
    goto v_23830;
v_23826:
    stack[0] = v_23853;
    goto v_23827;
v_23828:
    v_23851 = stack[-2];
    v_23851 = qcdr(v_23851);
    v_23851 = add1(v_23851);
    env = stack[-3];
    goto v_23829;
v_23830:
    goto v_23826;
v_23827:
    goto v_23828;
v_23829:
    v_23853 = cons(stack[0], v_23851);
    env = stack[-3];
    goto v_23819;
v_23820:
    v_23852 = stack[-2];
    goto v_23821;
v_23822:
    v_23851 = stack[-1];
    goto v_23823;
v_23824:
    goto v_23818;
v_23819:
    goto v_23820;
v_23821:
    goto v_23822;
v_23823:
    v_23851 = Lsubst(nil, 3, v_23853, v_23852, v_23851);
    stack[-1] = v_23851;
    goto v_23806;
v_23808:
    goto v_23846;
v_23840:
    goto v_23841;
v_23842:
    v_23852 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23843;
v_23844:
    v_23851 = stack[-1];
    goto v_23845;
v_23846:
    goto v_23840;
v_23841:
    goto v_23842;
v_23843:
    goto v_23844;
v_23845:
    v_23851 = acons(v_23853, v_23852, v_23851);
    stack[-1] = v_23851;
    goto v_23806;
v_23806:
    v_23851 = stack[-1];
    return onevalue(v_23851);
}



// Code for size_of_matrix

static LispObject CC_size_of_matrix(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_23830, v_23831;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23799);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_23799;
// end of prologue
    v_23830 = stack[0];
    fn = elt(env, 1); // matrix_input_test
    v_23830 = (*qfn1(fn))(fn, v_23830);
    env = stack[-2];
    goto v_23814;
v_23810:
    stack[-1] = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_23811;
v_23812:
    v_23830 = stack[0];
    v_23830 = Llength(nil, v_23830);
    env = stack[-2];
    goto v_23813;
v_23814:
    goto v_23810;
v_23811:
    goto v_23812;
v_23813:
    v_23830 = plus2(stack[-1], v_23830);
    env = stack[-2];
    stack[-1] = v_23830;
    v_23830 = stack[0];
    v_23830 = qcdr(v_23830);
    v_23830 = qcar(v_23830);
    v_23830 = Llength(nil, v_23830);
    goto v_23827;
v_23823:
    v_23831 = stack[-1];
    goto v_23824;
v_23825:
    goto v_23826;
v_23827:
    goto v_23823;
v_23824:
    goto v_23825;
v_23826:
    return list2(v_23831, v_23830);
    return onevalue(v_23830);
}



// Code for a2vdp

static LispObject CC_a2vdp(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_23878, v_23879, v_23880;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23799);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_23880 = v_23799;
// end of prologue
    goto v_23813;
v_23809:
    v_23879 = v_23880;
    goto v_23810;
v_23811:
    v_23878 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23812;
v_23813:
    goto v_23809;
v_23810:
    goto v_23811;
v_23812:
    if (v_23879 == v_23878) goto v_23807;
    else goto v_23808;
v_23807:
    v_23878 = lisp_true;
    goto v_23806;
v_23808:
    v_23878 = v_23880;
    v_23878 = (v_23878 == nil ? lisp_true : nil);
    goto v_23806;
    v_23878 = nil;
v_23806:
    if (v_23878 == nil) goto v_23804;
    goto v_23830;
v_23822:
    stack[-2] = elt(env, 1); // vdp
    goto v_23823;
v_23824:
    stack[-1] = nil;
    goto v_23825;
v_23826:
    goto v_23838;
v_23834:
    v_23879 = nil;
    goto v_23835;
v_23836:
    v_23878 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_23837;
v_23838:
    goto v_23834;
v_23835:
    goto v_23836;
v_23837:
    stack[0] = cons(v_23879, v_23878);
    env = stack[-3];
    goto v_23827;
v_23828:
    goto v_23846;
v_23842:
    v_23879 = nil;
    goto v_23843;
v_23844:
    v_23878 = nil;
    goto v_23845;
v_23846:
    goto v_23842;
v_23843:
    goto v_23844;
v_23845:
    v_23878 = list2(v_23879, v_23878);
    goto v_23829;
v_23830:
    goto v_23822;
v_23823:
    goto v_23824;
v_23825:
    goto v_23826;
v_23827:
    goto v_23828;
v_23829:
    {
        LispObject v_23884 = stack[-2];
        LispObject v_23885 = stack[-1];
        LispObject v_23886 = stack[0];
        return list3star(v_23884, v_23885, v_23886, v_23878);
    }
v_23804:
    v_23878 = v_23880;
    fn = elt(env, 2); // a2dip
    v_23878 = (*qfn1(fn))(fn, v_23878);
    env = stack[-3];
    v_23879 = v_23878;
    goto v_23863;
v_23855:
    stack[-2] = elt(env, 1); // vdp
    goto v_23856;
v_23857:
    v_23878 = v_23879;
    stack[-1] = qcar(v_23878);
    goto v_23858;
v_23859:
    v_23878 = v_23879;
    v_23878 = qcdr(v_23878);
    stack[0] = qcar(v_23878);
    goto v_23860;
v_23861:
    goto v_23875;
v_23871:
    goto v_23872;
v_23873:
    v_23878 = nil;
    goto v_23874;
v_23875:
    goto v_23871;
v_23872:
    goto v_23873;
v_23874:
    v_23878 = list2(v_23879, v_23878);
    goto v_23862;
v_23863:
    goto v_23855;
v_23856:
    goto v_23857;
v_23858:
    goto v_23859;
v_23860:
    goto v_23861;
v_23862:
    {
        LispObject v_23887 = stack[-2];
        LispObject v_23888 = stack[-1];
        LispObject v_23889 = stack[0];
        return list3star(v_23887, v_23888, v_23889, v_23878);
    }
    v_23878 = nil;
    return onevalue(v_23878);
}



// Code for listpri

static LispObject CC_listpri(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_23882, v_23883;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23799);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_23799;
// end of prologue
    v_23882 = stack[-2];
    stack[0] = v_23882;
    v_23882 = stack[-2];
    v_23882 = qcdr(v_23882);
    stack[-2] = v_23882;
    v_23882 = elt(env, 1); // !*lcbkt!*
    if (!symbolp(v_23882)) v_23882 = nil;
    else { v_23882 = qfastgets(v_23882);
           if (v_23882 != nil) { v_23882 = elt(v_23882, 37); // prtch
#ifdef RECORD_GET
             if (v_23882 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v_23882 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v_23882 == SPID_NOPROP) v_23882 = nil; }}
#endif
    fn = elt(env, 7); // prin2!*
    v_23882 = (*qfn1(fn))(fn, v_23882);
    env = stack[-4];
    v_23882 = qvalue(elt(env, 2)); // orig!*
    stack[-3] = v_23882;
    goto v_23824;
v_23820:
    v_23883 = qvalue(elt(env, 3)); // posn!*
    goto v_23821;
v_23822:
    v_23882 = (LispObject)288+TAG_FIXNUM; // 18
    goto v_23823;
v_23824:
    goto v_23820;
v_23821:
    goto v_23822;
v_23823:
    v_23882 = (LispObject)lessp2(v_23883, v_23882);
    v_23882 = v_23882 ? lisp_true : nil;
    env = stack[-4];
    if (v_23882 == nil) goto v_23818;
    v_23882 = qvalue(elt(env, 3)); // posn!*
    goto v_23816;
v_23818:
    goto v_23835;
v_23831:
    v_23883 = qvalue(elt(env, 2)); // orig!*
    goto v_23832;
v_23833:
    v_23882 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_23834;
v_23835:
    goto v_23831;
v_23832:
    goto v_23833;
v_23834:
    v_23882 = plus2(v_23883, v_23882);
    env = stack[-4];
    goto v_23816;
    v_23882 = nil;
v_23816:
    qvalue(elt(env, 2)) = v_23882; // orig!*
    v_23882 = stack[-2];
    if (v_23882 == nil) goto v_23840;
    else goto v_23841;
v_23840:
    goto v_23807;
v_23841:
    goto v_23848;
v_23844:
    v_23883 = stack[-2];
    goto v_23845;
v_23846:
    v_23882 = qvalue(elt(env, 4)); // listpri_depth!*
    goto v_23847;
v_23848:
    goto v_23844;
v_23845:
    goto v_23846;
v_23847:
    fn = elt(env, 8); // treesizep
    v_23882 = (*qfn2(fn))(fn, v_23883, v_23882);
    env = stack[-4];
    stack[-1] = v_23882;
v_23806:
    goto v_23856;
v_23852:
    v_23882 = stack[-2];
    v_23882 = qcar(v_23882);
    fn = elt(env, 9); // negnumberchk
    v_23883 = (*qfn1(fn))(fn, v_23882);
    env = stack[-4];
    goto v_23853;
v_23854:
    v_23882 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23855;
v_23856:
    goto v_23852;
v_23853:
    goto v_23854;
v_23855:
    fn = elt(env, 10); // maprint
    v_23882 = (*qfn2(fn))(fn, v_23883, v_23882);
    env = stack[-4];
    v_23882 = stack[-2];
    v_23882 = qcdr(v_23882);
    stack[-2] = v_23882;
    v_23882 = stack[-2];
    if (v_23882 == nil) goto v_23865;
    else goto v_23866;
v_23865:
    goto v_23807;
v_23866:
    v_23882 = elt(env, 5); // !*comma!*
    fn = elt(env, 11); // oprin
    v_23882 = (*qfn1(fn))(fn, v_23882);
    env = stack[-4];
    v_23882 = stack[-1];
    if (v_23882 == nil) goto v_23873;
    v_23882 = lisp_true;
    fn = elt(env, 12); // terpri!*
    v_23882 = (*qfn1(fn))(fn, v_23882);
    env = stack[-4];
    goto v_23871;
v_23873:
v_23871:
    goto v_23806;
v_23807:
    v_23882 = elt(env, 6); // !*rcbkt!*
    if (!symbolp(v_23882)) v_23882 = nil;
    else { v_23882 = qfastgets(v_23882);
           if (v_23882 != nil) { v_23882 = elt(v_23882, 37); // prtch
#ifdef RECORD_GET
             if (v_23882 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v_23882 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v_23882 == SPID_NOPROP) v_23882 = nil; }}
#endif
    fn = elt(env, 7); // prin2!*
    v_23882 = (*qfn1(fn))(fn, v_23882);
    env = stack[-4];
    v_23882 = stack[-3];
    qvalue(elt(env, 2)) = v_23882; // orig!*
    v_23882 = stack[0];
    return onevalue(v_23882);
}



// Code for gfdiffer

static LispObject CC_gfdiffer(LispObject env,
                         LispObject v_23799, LispObject v_23800)
{
    env = qenv(env);
    LispObject v_23826, v_23827, v_23828;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23827 = v_23800;
    v_23828 = v_23799;
// end of prologue
    v_23826 = v_23828;
    v_23826 = qcar(v_23826);
    if (!consp(v_23826)) goto v_23804;
    else goto v_23805;
v_23804:
    goto v_23813;
v_23809:
    v_23826 = v_23828;
    goto v_23810;
v_23811:
    goto v_23812;
v_23813:
    goto v_23809;
v_23810:
    goto v_23811;
v_23812:
    {
        fn = elt(env, 1); // gffdiff
        return (*qfn2(fn))(fn, v_23826, v_23827);
    }
v_23805:
    goto v_23823;
v_23819:
    v_23826 = v_23828;
    goto v_23820;
v_23821:
    goto v_23822;
v_23823:
    goto v_23819;
v_23820:
    goto v_23821;
v_23822:
    {
        fn = elt(env, 2); // gbfdiff
        return (*qfn2(fn))(fn, v_23826, v_23827);
    }
    v_23826 = nil;
    return onevalue(v_23826);
}



// Code for physoppri

static LispObject CC_physoppri(LispObject env,
                         LispObject v_23799)
{
    env = qenv(env);
    LispObject v_24111, v_24112, v_24113, v_24114;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_23799);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_23799);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_23799;
// end of prologue
    stack[-6] = nil;
    v_24111 = stack[-8];
    if (symbolp(v_24111)) goto v_23810;
    else goto v_23811;
v_23810:
    v_24111 = stack[-8];
    goto v_23809;
v_23811:
    v_24111 = stack[-8];
    v_24111 = qcar(v_24111);
    goto v_23809;
    v_24111 = nil;
v_23809:
    stack[-9] = v_24111;
    v_24111 = stack[-8];
    if (symbolp(v_24111)) goto v_23820;
    else goto v_23821;
v_23820:
    v_24111 = nil;
    goto v_23819;
v_23821:
    v_24111 = stack[-8];
    v_24111 = qcdr(v_24111);
    goto v_23819;
    v_24111 = nil;
v_23819:
    stack[-7] = v_24111;
    goto v_23838;
v_23830:
    stack[-5] = elt(env, 0); // physoppri
    goto v_23831;
v_23832:
    stack[-4] = elt(env, 1); // "x= "
    goto v_23833;
v_23834:
    stack[-3] = stack[-9];
    goto v_23835;
v_23836:
    goto v_23851;
v_23843:
    stack[-2] = elt(env, 2); // " y= "
    goto v_23844;
v_23845:
    stack[-1] = stack[-7];
    goto v_23846;
v_23847:
    stack[0] = elt(env, 3); // "nat= "
    goto v_23848;
v_23849:
    goto v_23862;
v_23856:
    v_24113 = elt(env, 4); // !*nat
    goto v_23857;
v_23858:
    v_24112 = elt(env, 5); // " contract= "
    goto v_23859;
v_23860:
    v_24111 = elt(env, 6); // !*contract
    goto v_23861;
v_23862:
    goto v_23856;
v_23857:
    goto v_23858;
v_23859:
    goto v_23860;
v_23861:
    v_24111 = list3(v_24113, v_24112, v_24111);
    env = stack[-10];
    goto v_23850;
v_23851:
    goto v_23843;
v_23844:
    goto v_23845;
v_23846:
    goto v_23847;
v_23848:
    goto v_23849;
v_23850:
    v_24111 = list3star(stack[-2], stack[-1], stack[0], v_24111);
    env = stack[-10];
    goto v_23837;
v_23838:
    goto v_23830;
v_23831:
    goto v_23832;
v_23833:
    goto v_23834;
v_23835:
    goto v_23836;
v_23837:
    v_24111 = list3star(stack[-5], stack[-4], stack[-3], v_24111);
    env = stack[-10];
    fn = elt(env, 18); // trwrite
    v_24111 = (*qfn1(fn))(fn, v_24111);
    env = stack[-10];
    v_24111 = qvalue(elt(env, 4)); // !*nat
    if (v_24111 == nil) goto v_23869;
    v_24111 = qvalue(elt(env, 6)); // !*contract
    if (v_24111 == nil) goto v_23872;
    else goto v_23869;
v_23872:
    goto v_23807;
v_23869:
    goto v_23880;
v_23876:
    goto v_23886;
v_23882:
    stack[0] = elt(env, 7); // !"
    goto v_23883;
v_23884:
    v_24111 = stack[-9];
    v_24111 = Lexplode(nil, v_24111);
    env = stack[-10];
    goto v_23885;
v_23886:
    goto v_23882;
v_23883:
    goto v_23884;
v_23885:
    stack[0] = cons(stack[0], v_24111);
    env = stack[-10];
    goto v_23877;
v_23878:
    v_24111 = elt(env, 7); // !"
    v_24111 = ncons(v_24111);
    env = stack[-10];
    goto v_23879;
v_23880:
    goto v_23876;
v_23877:
    goto v_23878;
v_23879:
    v_24111 = Lappend(nil, stack[0], v_24111);
    env = stack[-10];
    v_24111 = Lcompress(nil, v_24111);
    env = stack[-10];
    stack[-9] = v_24111;
    v_24111 = stack[-9];
    fn = elt(env, 19); // prin2!*
    v_24111 = (*qfn1(fn))(fn, v_24111);
    env = stack[-10];
    v_24111 = stack[-7];
    if (v_24111 == nil) goto v_23897;
    v_24111 = elt(env, 8); // "("
    fn = elt(env, 19); // prin2!*
    v_24111 = (*qfn1(fn))(fn, v_24111);
    env = stack[-10];
    v_24111 = nil;
    qvalue(elt(env, 9)) = v_24111; // obrkp!*
    goto v_23909;
v_23903:
    v_24113 = elt(env, 10); // !*comma!*
    goto v_23904;
v_23905:
    v_24112 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_23906;
v_23907:
    v_24111 = stack[-7];
    goto v_23908;
v_23909:
    goto v_23903;
v_23904:
    goto v_23905;
v_23906:
    goto v_23907;
v_23908:
    fn = elt(env, 20); // inprint
    v_24111 = (*qfnn(fn))(fn, 3, v_24113, v_24112, v_24111);
    env = stack[-10];
    v_24111 = lisp_true;
    qvalue(elt(env, 9)) = v_24111; // obrkp!*
    v_24111 = elt(env, 11); // ")"
    fn = elt(env, 19); // prin2!*
    v_24111 = (*qfn1(fn))(fn, v_24111);
    goto v_23895;
v_23897:
v_23895:
    v_24111 = stack[-8];
    goto v_23806;
v_23807:
    v_24111 = stack[-9];
    v_24111 = Lexplode(nil, v_24111);
    env = stack[-10];
    v_24111 = Lreverse(nil, v_24111);
    env = stack[-10];
    stack[-9] = v_24111;
    goto v_23929;
v_23925:
    v_24111 = stack[-9];
    v_24112 = Llength(nil, v_24111);
    env = stack[-10];
    goto v_23926;
v_23927:
    v_24111 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_23928;
v_23929:
    goto v_23925;
v_23926:
    goto v_23927;
v_23928:
    v_24111 = (LispObject)greaterp2(v_24112, v_24111);
    v_24111 = v_24111 ? lisp_true : nil;
    env = stack[-10];
    if (v_24111 == nil) goto v_23923;
    goto v_23941;
v_23937:
    v_24111 = stack[-9];
    v_24111 = qcdr(v_24111);
    v_24112 = qcar(v_24111);
    goto v_23938;
v_23939:
    v_24111 = elt(env, 12); // !-
    goto v_23940;
v_23941:
    goto v_23937;
v_23938:
    goto v_23939;
v_23940:
    if (v_24112 == v_24111) goto v_23935;
    else goto v_23936;
v_23935:
    goto v_23952;
v_23948:
    v_24112 = elt(env, 12); // !-
    goto v_23949;
v_23950:
    v_24111 = elt(env, 13); // !1
    goto v_23951;
v_23952:
    goto v_23948;
v_23949:
    goto v_23950;
v_23951:
    v_24111 = list2(v_24112, v_24111);
    env = stack[-10];
    v_24111 = Lcompress(nil, v_24111);
    env = stack[-10];
    stack[-6] = v_24111;
    goto v_23962;
v_23958:
    v_24112 = stack[-9];
    goto v_23959;
v_23960:
    v_24111 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_23961;
v_23962:
    goto v_23958;
v_23959:
    goto v_23960;
v_23961:
    fn = elt(env, 21); // pnth
    v_24111 = (*qfn2(fn))(fn, v_24112, v_24111);
    env = stack[-10];
    v_24111 = Lreverse(nil, v_24111);
    env = stack[-10];
    v_24111 = Lcompress(nil, v_24111);
    env = stack[-10];
    stack[-9] = v_24111;
    goto v_23934;
v_23936:
    goto v_23972;
v_23968:
    v_24111 = stack[-9];
    v_24112 = qcar(v_24111);
    goto v_23969;
v_23970:
    v_24111 = elt(env, 14); // !+
    goto v_23971;
v_23972:
    goto v_23968;
v_23969:
    goto v_23970;
v_23971:
    if (v_24112 == v_24111) goto v_23966;
    else goto v_23967;
v_23966:
    v_24111 = elt(env, 14); // !+
    stack[-6] = v_24111;
    goto v_23984;
v_23980:
    v_24112 = stack[-9];
    goto v_23981;
v_23982:
    v_24111 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_23983;
v_23984:
    goto v_23980;
v_23981:
    goto v_23982;
v_23983:
    fn = elt(env, 21); // pnth
    v_24111 = (*qfn2(fn))(fn, v_24112, v_24111);
    env = stack[-10];
    v_24111 = Lreverse(nil, v_24111);
    env = stack[-10];
    v_24111 = Lcompress(nil, v_24111);
    env = stack[-10];
    stack[-9] = v_24111;
    goto v_23934;
v_23967:
    v_24111 = stack[-9];
    v_24111 = Lreverse(nil, v_24111);
    env = stack[-10];
    v_24111 = Lcompress(nil, v_24111);
    env = stack[-10];
    stack[-9] = v_24111;
    goto v_23934;
v_23934:
    goto v_23921;
v_23923:
    v_24111 = stack[-9];
    v_24111 = Lreverse(nil, v_24111);
    env = stack[-10];
    v_24111 = Lcompress(nil, v_24111);
    env = stack[-10];
    stack[-9] = v_24111;
    goto v_23921;
v_23921:
    goto v_24004;
v_24000:
    goto v_24010;
v_24006:
    stack[0] = elt(env, 7); // !"
    goto v_24007;
v_24008:
    v_24111 = stack[-9];
    v_24111 = Lexplode(nil, v_24111);
    env = stack[-10];
    goto v_24009;
v_24010:
    goto v_24006;
v_24007:
    goto v_24008;
v_24009:
    stack[0] = cons(stack[0], v_24111);
    env = stack[-10];
    goto v_24001;
v_24002:
    v_24111 = elt(env, 7); // !"
    v_24111 = ncons(v_24111);
    env = stack[-10];
    goto v_24003;
v_24004:
    goto v_24000;
v_24001:
    goto v_24002;
v_24003:
    v_24111 = Lappend(nil, stack[0], v_24111);
    env = stack[-10];
    v_24111 = Lcompress(nil, v_24111);
    env = stack[-10];
    stack[-9] = v_24111;
    v_24111 = stack[-7];
    if (v_24111 == nil) goto v_24019;
    goto v_24026;
v_24022:
    v_24112 = stack[-9];
    goto v_24023;
v_24024:
    v_24111 = stack[-7];
    goto v_24025;
v_24026:
    goto v_24022;
v_24023:
    goto v_24024;
v_24025:
    v_24111 = cons(v_24112, v_24111);
    env = stack[-10];
    goto v_24017;
v_24019:
    v_24111 = stack[-9];
    goto v_24017;
    v_24111 = nil;
v_24017:
    stack[-3] = v_24111;
    goto v_24042;
v_24034:
    stack[-2] = elt(env, 0); // physoppri
    goto v_24035;
v_24036:
    stack[-1] = elt(env, 1); // "x= "
    goto v_24037;
v_24038:
    stack[0] = stack[-9];
    goto v_24039;
v_24040:
    goto v_24055;
v_24047:
    v_24114 = elt(env, 15); // " z= "
    goto v_24048;
v_24049:
    v_24113 = stack[-6];
    goto v_24050;
v_24051:
    v_24112 = elt(env, 16); // " x1= "
    goto v_24052;
v_24053:
    v_24111 = stack[-3];
    goto v_24054;
v_24055:
    goto v_24047;
v_24048:
    goto v_24049;
v_24050:
    goto v_24051;
v_24052:
    goto v_24053;
v_24054:
    v_24111 = list4(v_24114, v_24113, v_24112, v_24111);
    env = stack[-10];
    goto v_24041;
v_24042:
    goto v_24034;
v_24035:
    goto v_24036;
v_24037:
    goto v_24038;
v_24039:
    goto v_24040;
v_24041:
    v_24111 = list3star(stack[-2], stack[-1], stack[0], v_24111);
    env = stack[-10];
    fn = elt(env, 18); // trwrite
    v_24111 = (*qfn1(fn))(fn, v_24111);
    env = stack[-10];
    v_24111 = stack[-6];
    if (v_24111 == nil) goto v_24063;
    goto v_24070;
v_24066:
    goto v_24078;
v_24072:
    v_24113 = elt(env, 17); // expt
    goto v_24073;
v_24074:
    v_24112 = stack[-3];
    goto v_24075;
v_24076:
    v_24111 = stack[-6];
    goto v_24077;
v_24078:
    goto v_24072;
v_24073:
    goto v_24074;
v_24075:
    goto v_24076;
v_24077:
    v_24112 = list3(v_24113, v_24112, v_24111);
    env = stack[-10];
    goto v_24067;
v_24068:
    v_24111 = elt(env, 17); // expt
    if (!symbolp(v_24111)) v_24111 = nil;
    else { v_24111 = qfastgets(v_24111);
           if (v_24111 != nil) { v_24111 = elt(v_24111, 23); // infix
#ifdef RECORD_GET
             if (v_24111 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_24111 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_24111 == SPID_NOPROP) v_24111 = nil; }}
#endif
    goto v_24069;
v_24070:
    goto v_24066;
v_24067:
    goto v_24068;
v_24069:
    fn = elt(env, 22); // exptpri
    v_24111 = (*qfn2(fn))(fn, v_24112, v_24111);
    goto v_24061;
v_24063:
    v_24111 = stack[-9];
    fn = elt(env, 19); // prin2!*
    v_24111 = (*qfn1(fn))(fn, v_24111);
    env = stack[-10];
    v_24111 = stack[-7];
    if (v_24111 == nil) goto v_24091;
    v_24111 = elt(env, 8); // "("
    fn = elt(env, 19); // prin2!*
    v_24111 = (*qfn1(fn))(fn, v_24111);
    env = stack[-10];
    v_24111 = nil;
    qvalue(elt(env, 9)) = v_24111; // obrkp!*
    goto v_24103;
v_24097:
    v_24113 = elt(env, 10); // !*comma!*
    goto v_24098;
v_24099:
    v_24112 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_24100;
v_24101:
    v_24111 = stack[-7];
    goto v_24102;
v_24103:
    goto v_24097;
v_24098:
    goto v_24099;
v_24100:
    goto v_24101;
v_24102:
    fn = elt(env, 20); // inprint
    v_24111 = (*qfnn(fn))(fn, 3, v_24113, v_24112, v_24111);
    env = stack[-10];
    v_24111 = lisp_true;
    qvalue(elt(env, 9)) = v_24111; // obrkp!*
    v_24111 = elt(env, 11); // ")"
    fn = elt(env, 19); // prin2!*
    v_24111 = (*qfn1(fn))(fn, v_24111);
    goto v_24089;
v_24091:
v_24089:
    goto v_24061;
v_24061:
    v_24111 = stack[-8];
v_23806:
    return onevalue(v_24111);
}



setup_type const u42_setup[] =
{
    {"mk_binding",              TOO_FEW_2,      CC_mk_binding, WRONG_NO_2},
    {"ratnump",                 CC_ratnump,     TOO_MANY_1,    WRONG_NO_1},
    {"miller-rabin",            TOO_FEW_2,      CC_millerKrabin,WRONG_NO_2},
    {"equiv-coeffs",            TOO_FEW_2,      CC_equivKcoeffs,WRONG_NO_2},
    {"*g2lex",                  CC_Hg2lex,      TOO_MANY_1,    WRONG_NO_1},
    {"isimp1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_isimp1},
    {"drop_dec_with",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_drop_dec_with},
    {"cl_nnf1",                 TOO_FEW_2,      CC_cl_nnf1,    WRONG_NO_2},
    {"repr_ldeg",               CC_repr_ldeg,   TOO_MANY_1,    WRONG_NO_1},
    {"symbolsrd",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_symbolsrd},
    {"spcol_dim",               CC_spcol_dim,   TOO_MANY_1,    WRONG_NO_1},
    {"on-double1",              CC_onKdouble1,  TOO_MANY_1,    WRONG_NO_1},
    {"gbfdiff",                 TOO_FEW_2,      CC_gbfdiff,    WRONG_NO_2},
    {"r2speclist1",             CC_r2speclist1, TOO_MANY_1,    WRONG_NO_1},
    {"list-evaluate",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_listKevaluate},
    {"mkassign",                TOO_FEW_2,      CC_mkassign,   WRONG_NO_2},
    {"set-weights",             CC_setKweights, TOO_MANY_1,    WRONG_NO_1},
    {"simp-prop-dist",          CC_simpKpropKdist,TOO_MANY_1,  WRONG_NO_1},
    {"lambda_iff2c8okfzyq1",    TOO_FEW_2,      CC_lambda_iff2c8okfzyq1,WRONG_NO_2},
    {"lambda_iff2c8okfzyq1",    TOO_FEW_2,      CC1_lambda_iff2c8okfzyq1,WRONG_NO_2},
    {"lesspcar",                TOO_FEW_2,      CC_lesspcar,   WRONG_NO_2},
    {"simpquot",                CC_simpquot,    TOO_MANY_1,    WRONG_NO_1},
    {"rl_qe",                   TOO_FEW_2,      CC_rl_qe,      WRONG_NO_2},
    {"ofsf_evalatp",            TOO_FEW_2,      CC_ofsf_evalatp,WRONG_NO_2},
    {"talp_trygaussvar",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_trygaussvar},
    {"fctrf",                   CC_fctrf,       TOO_MANY_1,    WRONG_NO_1},
    {"transposerd",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_transposerd},
    {"findelem2",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_findelem2},
    {"inszzz",                  TOO_FEW_2,      CC_inszzz,     WRONG_NO_2},
    {"get:const",               TOO_FEW_2,      CC_getTconst,  WRONG_NO_2},
    {"consrecip",               CC_consrecip,   TOO_MANY_1,    WRONG_NO_1},
    {"splitup",                 TOO_FEW_2,      CC_splitup,    WRONG_NO_2},
    {"groeb=testc1",            CC_groebMtestc1,TOO_MANY_1,    WRONG_NO_1},
    {"list2vect*",              TOO_FEW_2,      CC_list2vectH, WRONG_NO_2},
    {"basic-kern",              CC_basicKkern,  TOO_MANY_1,    WRONG_NO_1},
    {"xquotient-mod-p",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xquotientKmodKp},
    {"algmodep",                CC_algmodep,    TOO_MANY_1,    WRONG_NO_1},
    {"xnp",                     TOO_FEW_2,      CC_xnp,        WRONG_NO_2},
    {"lalr_set_nonterminal_codes",WRONG_NO_NA,  WRONG_NO_NB,   (n_args *)CC_lalr_set_nonterminal_codes},
    {"cl_subfof",               TOO_FEW_2,      CC_cl_subfof,  WRONG_NO_2},
    {"cl_sacatlp",              TOO_FEW_2,      CC_cl_sacatlp, WRONG_NO_2},
    {"ofsf_anegrel",            CC_ofsf_anegrel,TOO_MANY_1,    WRONG_NO_1},
    {"diffrd",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_diffrd},
    {"insertocc",               TOO_FEW_2,      CC_insertocc,  WRONG_NO_2},
    {"size_of_matrix",          CC_size_of_matrix,TOO_MANY_1,  WRONG_NO_1},
    {"a2vdp",                   CC_a2vdp,       TOO_MANY_1,    WRONG_NO_1},
    {"listpri",                 CC_listpri,     TOO_MANY_1,    WRONG_NO_1},
    {"gfdiffer",                TOO_FEW_2,      CC_gfdiffer,   WRONG_NO_2},
    {"physoppri",               CC_physoppri,   TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u42", (two_args *)"159355 4850469 5392592", 0}
};

// end of generated code
