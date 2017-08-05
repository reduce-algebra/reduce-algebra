
// $destdir/u20.c        Machine generated C code

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



// Code for subf1

static LispObject CC_subf1(LispObject env,
                         LispObject v_11168, LispObject v_11169)
{
    env = qenv(env);
    LispObject v_11916, v_11917, v_11918;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11168,v_11169);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(15);
// copy arguments values to proper place
    stack[-11] = v_11169;
    stack[-12] = v_11168;
// end of prologue
    v_11916 = stack[-12];
    if (v_11916 == nil) goto v_11173;
    else goto v_11174;
v_11173:
    goto v_11181;
v_11177:
    v_11917 = nil;
    goto v_11178;
v_11179:
    v_11916 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11180;
v_11181:
    goto v_11177;
v_11178:
    goto v_11179;
v_11180:
    return cons(v_11917, v_11916);
v_11174:
    v_11916 = stack[-12];
    if (!consp(v_11916)) goto v_11188;
    else goto v_11189;
v_11188:
    v_11916 = lisp_true;
    goto v_11187;
v_11189:
    v_11916 = stack[-12];
    v_11916 = qcar(v_11916);
    v_11916 = (consp(v_11916) ? nil : lisp_true);
    goto v_11187;
    v_11916 = nil;
v_11187:
    if (v_11916 == nil) goto v_11185;
    v_11916 = stack[-12];
    if (!consp(v_11916)) goto v_11199;
    else goto v_11200;
v_11199:
    v_11916 = qvalue(elt(env, 1)); // dmode!*
    if (v_11916 == nil) goto v_11204;
    else goto v_11205;
v_11204:
    goto v_11212;
v_11208:
    v_11917 = stack[-12];
    goto v_11209;
v_11210:
    v_11916 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11211;
v_11212:
    goto v_11208;
v_11209:
    goto v_11210;
v_11211:
    return cons(v_11917, v_11916);
v_11205:
    v_11916 = stack[-12];
    {
        fn = elt(env, 11); // simpatom
        return (*qfn1(fn))(fn, v_11916);
    }
    v_11916 = nil;
    goto v_11198;
v_11200:
    goto v_11229;
v_11225:
    v_11917 = qvalue(elt(env, 1)); // dmode!*
    goto v_11226;
v_11227:
    v_11916 = stack[-12];
    v_11916 = qcar(v_11916);
    goto v_11228;
v_11229:
    goto v_11225;
v_11226:
    goto v_11227;
v_11228:
    if (v_11917 == v_11916) goto v_11223;
    else goto v_11224;
v_11223:
    goto v_11238;
v_11234:
    v_11917 = qvalue(elt(env, 1)); // dmode!*
    goto v_11235;
v_11236:
    v_11916 = elt(env, 2); // resimplify
    goto v_11237;
v_11238:
    goto v_11234;
v_11235:
    goto v_11236;
v_11237:
    v_11916 = Lflagp(nil, v_11917, v_11916);
    env = stack[-14];
    v_11916 = (v_11916 == nil ? lisp_true : nil);
    goto v_11222;
v_11224:
    v_11916 = nil;
    goto v_11222;
    v_11916 = nil;
v_11222:
    if (v_11916 == nil) goto v_11220;
    v_11916 = stack[-12];
    {
        fn = elt(env, 12); // !*d2q
        return (*qfn1(fn))(fn, v_11916);
    }
v_11220:
    v_11916 = stack[-12];
    fn = elt(env, 13); // prepf
    v_11916 = (*qfn1(fn))(fn, v_11916);
    env = stack[-14];
    {
        fn = elt(env, 14); // simp
        return (*qfn1(fn))(fn, v_11916);
    }
    v_11916 = nil;
v_11198:
    goto v_11172;
v_11185:
// Binding varstack!*
// FLUIDBIND: reloadenv=14 litvec-offset=3 saveloc=9
{   bind_fluid_stack bind_fluid_var(-14, 3, -9);
    qvalue(elt(env, 3)) = nil; // varstack!*
    stack[-5] = nil;
    stack[-4] = nil;
    v_11916 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-13] = v_11916;
    goto v_11284;
v_11280:
    v_11917 = nil;
    goto v_11281;
v_11282:
    v_11916 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11283;
v_11284:
    goto v_11280;
v_11281:
    goto v_11282;
v_11283:
    v_11916 = cons(v_11917, v_11916);
    env = stack[-14];
    stack[-3] = v_11916;
v_11269:
    v_11916 = stack[-12];
    v_11916 = qcar(v_11916);
    v_11916 = qcar(v_11916);
    v_11916 = qcar(v_11916);
    stack[-2] = v_11916;
    v_11916 = nil;
    stack[0] = v_11916;
    goto v_11301;
v_11297:
    v_11917 = stack[-2];
    goto v_11298;
v_11299:
    v_11916 = stack[-11];
    goto v_11300;
v_11301:
    goto v_11297;
v_11298:
    goto v_11299;
v_11300:
    v_11916 = Lassoc(nil, v_11917, v_11916);
    if (v_11916 == nil) goto v_11295;
    goto v_11310;
v_11306:
    v_11917 = stack[-2];
    goto v_11307;
v_11308:
    v_11916 = qvalue(elt(env, 4)); // wtl!*
    goto v_11309;
v_11310:
    goto v_11306;
v_11307:
    goto v_11308;
v_11309:
    v_11916 = Lassoc(nil, v_11917, v_11916);
    stack[0] = v_11916;
    if (v_11916 == nil) goto v_11295;
    v_11916 = stack[0];
    v_11916 = qcdr(v_11916);
    stack[0] = v_11916;
    goto v_11293;
v_11295:
v_11293:
    goto v_11324;
v_11320:
    v_11917 = stack[-2];
    goto v_11321;
v_11322:
    v_11916 = qvalue(elt(env, 5)); // asymplis!*
    goto v_11323;
v_11324:
    goto v_11320;
v_11321:
    goto v_11322;
v_11323:
    v_11916 = Lassoc(nil, v_11917, v_11916);
    stack[-10] = v_11916;
    if (v_11916 == nil) goto v_11319;
    v_11916 = stack[-10];
    v_11916 = qcdr(v_11916);
    stack[-10] = v_11916;
    goto v_11317;
v_11319:
v_11317:
v_11270:
    v_11916 = stack[-12];
    if (v_11916 == nil) goto v_11336;
    else goto v_11337;
v_11336:
    v_11916 = lisp_true;
    goto v_11335;
v_11337:
    goto v_11346;
v_11342:
    goto v_11352;
v_11348:
    v_11917 = stack[-12];
    goto v_11349;
v_11350:
    v_11916 = stack[-2];
    goto v_11351;
v_11352:
    goto v_11348;
v_11349:
    goto v_11350;
v_11351:
    fn = elt(env, 15); // degr
    v_11917 = (*qfn2(fn))(fn, v_11917, v_11916);
    env = stack[-14];
    stack[-13] = v_11917;
    goto v_11343;
v_11344:
    v_11916 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11345;
v_11346:
    goto v_11342;
v_11343:
    goto v_11344;
v_11345:
    v_11916 = (v_11917 == v_11916 ? lisp_true : nil);
    goto v_11335;
    v_11916 = nil;
v_11335:
    if (v_11916 == nil) goto v_11333;
    goto v_11271;
v_11333:
    v_11916 = stack[-10];
    if (v_11916 == nil) goto v_11361;
    else goto v_11362;
v_11361:
    v_11916 = lisp_true;
    goto v_11360;
v_11362:
    goto v_11372;
v_11368:
    v_11917 = stack[-13];
    goto v_11369;
v_11370:
    v_11916 = stack[-10];
    goto v_11371;
v_11372:
    goto v_11368;
v_11369:
    goto v_11370;
v_11371:
    v_11916 = (LispObject)lessp2(v_11917, v_11916);
    v_11916 = v_11916 ? lisp_true : nil;
    env = stack[-14];
    goto v_11360;
    v_11916 = nil;
v_11360:
    if (v_11916 == nil) goto v_11358;
    goto v_11380;
v_11376:
    goto v_11386;
v_11382:
    v_11916 = stack[-12];
    v_11917 = qcar(v_11916);
    goto v_11383;
v_11384:
    v_11916 = stack[0];
    goto v_11385;
v_11386:
    goto v_11382;
v_11383:
    goto v_11384;
v_11385:
    fn = elt(env, 16); // wtchk
    v_11917 = (*qfn2(fn))(fn, v_11917, v_11916);
    env = stack[-14];
    goto v_11377;
v_11378:
    v_11916 = stack[-5];
    goto v_11379;
v_11380:
    goto v_11376;
v_11377:
    goto v_11378;
v_11379:
    v_11916 = cons(v_11917, v_11916);
    env = stack[-14];
    stack[-5] = v_11916;
    goto v_11331;
v_11358:
v_11331:
    v_11916 = stack[-12];
    v_11916 = qcdr(v_11916);
    stack[-12] = v_11916;
    goto v_11270;
v_11271:
    v_11916 = nil;
    v_11918 = v_11916;
v_11396:
    v_11916 = stack[-11];
    if (v_11916 == nil) goto v_11399;
    else goto v_11400;
v_11399:
    goto v_11395;
v_11400:
    goto v_11411;
v_11407:
    v_11916 = stack[-11];
    v_11916 = qcar(v_11916);
    v_11917 = qcar(v_11916);
    goto v_11408;
v_11409:
    v_11916 = stack[-11];
    v_11916 = qcar(v_11916);
    v_11916 = qcdr(v_11916);
    goto v_11410;
v_11411:
    goto v_11407;
v_11408:
    goto v_11409;
v_11410:
    if (equal(v_11917, v_11916)) goto v_11406;
    goto v_11423;
v_11419:
    v_11916 = stack[-11];
    v_11916 = qcar(v_11916);
    goto v_11420;
v_11421:
    v_11917 = v_11918;
    goto v_11422;
v_11423:
    goto v_11419;
v_11420:
    goto v_11421;
v_11422:
    v_11916 = cons(v_11916, v_11917);
    env = stack[-14];
    v_11918 = v_11916;
    goto v_11404;
v_11406:
v_11404:
    v_11916 = stack[-11];
    v_11916 = qcdr(v_11916);
    stack[-11] = v_11916;
    goto v_11396;
v_11395:
    v_11916 = v_11918;
    v_11916 = Lnreverse(nil, v_11916);
    env = stack[-14];
    stack[-11] = v_11916;
    v_11916 = stack[-2];
    if (!consp(v_11916)) goto v_11438;
    v_11916 = stack[-2];
    v_11916 = qcar(v_11916);
    v_11916 = (consp(v_11916) ? nil : lisp_true);
    v_11916 = (v_11916 == nil ? lisp_true : nil);
    goto v_11436;
v_11438:
    v_11916 = nil;
    goto v_11436;
    v_11916 = nil;
v_11436:
    if (v_11916 == nil) goto v_11434;
    v_11916 = stack[-2];
    fn = elt(env, 13); // prepf
    v_11916 = (*qfn1(fn))(fn, v_11916);
    env = stack[-14];
    stack[-2] = v_11916;
    goto v_11432;
v_11434:
v_11432:
    v_11916 = stack[-11];
    if (v_11916 == nil) goto v_11451;
    else goto v_11452;
v_11451:
    goto v_11462;
v_11458:
    v_11917 = stack[-2];
    goto v_11459;
v_11460:
    v_11916 = elt(env, 6); // k!*
    goto v_11461;
v_11462:
    goto v_11458;
v_11459:
    goto v_11460;
v_11461:
    if (v_11917 == v_11916) goto v_11456;
    else goto v_11457;
v_11456:
    v_11916 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11455;
v_11457:
    v_11916 = stack[-2];
    goto v_11455;
    v_11916 = nil;
v_11455:
    stack[-1] = v_11916;
    goto v_11450;
v_11452:
    goto v_11479;
v_11475:
    goto v_11485;
v_11481:
    v_11917 = stack[-11];
    goto v_11482;
v_11483:
    v_11916 = stack[-2];
    goto v_11484;
v_11485:
    goto v_11481;
v_11482:
    goto v_11483;
v_11484:
    fn = elt(env, 17); // subsublis
    v_11917 = (*qfn2(fn))(fn, v_11917, v_11916);
    env = stack[-14];
    stack[-1] = v_11917;
    goto v_11476;
v_11477:
    v_11916 = stack[-2];
    goto v_11478;
v_11479:
    goto v_11475;
v_11476:
    goto v_11477;
v_11478:
    if (equal(v_11917, v_11916)) goto v_11473;
    else goto v_11474;
v_11473:
    goto v_11493;
v_11489:
    v_11917 = stack[-2];
    goto v_11490;
v_11491:
    v_11916 = qvalue(elt(env, 5)); // asymplis!*
    goto v_11492;
v_11493:
    goto v_11489;
v_11490:
    goto v_11491;
v_11492:
    v_11916 = Lassoc(nil, v_11917, v_11916);
    v_11916 = (v_11916 == nil ? lisp_true : nil);
    goto v_11472;
v_11474:
    v_11916 = nil;
    goto v_11472;
    v_11916 = nil;
v_11472:
    if (v_11916 == nil) goto v_11470;
    goto v_11274;
v_11470:
v_11450:
v_11272:
    goto v_11506;
v_11502:
    v_11917 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11503;
v_11504:
    v_11916 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11505;
v_11506:
    goto v_11502;
v_11503:
    goto v_11504;
v_11505:
    v_11916 = cons(v_11917, v_11916);
    env = stack[-14];
    stack[-8] = v_11916;
    v_11916 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-13] = v_11916;
    v_11916 = stack[-5];
    if (v_11916 == nil) goto v_11513;
    v_11916 = stack[-5];
    v_11916 = qcar(v_11916);
    v_11916 = qcar(v_11916);
    v_11916 = qcdr(v_11916);
    v_11916 = Lminusp(nil, v_11916);
    env = stack[-14];
    if (v_11916 == nil) goto v_11513;
    goto v_11275;
v_11513:
    goto v_11530;
v_11526:
    v_11916 = stack[-1];
    fn = elt(env, 18); // getrtype
    v_11917 = (*qfn1(fn))(fn, v_11916);
    env = stack[-14];
    stack[-7] = v_11917;
    goto v_11527;
v_11528:
    v_11916 = elt(env, 7); // yetunknowntype
    goto v_11529;
v_11530:
    goto v_11526;
v_11527:
    goto v_11528;
v_11529:
    if (v_11917 == v_11916) goto v_11524;
    else goto v_11525;
v_11524:
    goto v_11540;
v_11536:
    v_11917 = stack[-1];
    goto v_11537;
v_11538:
    v_11916 = nil;
    goto v_11539;
v_11540:
    goto v_11536;
v_11537:
    goto v_11538;
v_11539:
    fn = elt(env, 19); // eval!-yetunknowntypeexpr
    v_11916 = (*qfn2(fn))(fn, v_11917, v_11916);
    env = stack[-14];
    stack[-1] = v_11916;
    fn = elt(env, 18); // getrtype
    v_11916 = (*qfn1(fn))(fn, v_11916);
    env = stack[-14];
    stack[-7] = v_11916;
    goto v_11523;
v_11525:
v_11523:
    v_11916 = stack[-7];
    if (v_11916 == nil) goto v_11546;
    goto v_11554;
v_11550:
    v_11917 = stack[-7];
    goto v_11551;
v_11552:
    v_11916 = elt(env, 8); // list
    goto v_11553;
v_11554:
    goto v_11550;
v_11551:
    goto v_11552;
v_11553:
    if (v_11917 == v_11916) goto v_11546;
    goto v_11562;
v_11558:
    goto v_11568;
v_11564:
    v_11917 = stack[-7];
    goto v_11565;
v_11566:
    v_11916 = stack[-1];
    goto v_11567;
v_11568:
    goto v_11564;
v_11565:
    goto v_11566;
v_11567:
    v_11917 = list2(v_11917, v_11916);
    env = stack[-14];
    goto v_11559;
v_11560:
    v_11916 = elt(env, 9); // "substituted expression"
    goto v_11561;
v_11562:
    goto v_11558;
v_11559:
    goto v_11560;
v_11561:
    fn = elt(env, 20); // typerr
    v_11916 = (*qfn2(fn))(fn, v_11917, v_11916);
    env = stack[-14];
    goto v_11544;
v_11546:
v_11544:
    v_11916 = nil;
    fn = elt(env, 21); // setkorder
    v_11916 = (*qfn1(fn))(fn, v_11916);
    env = stack[-14];
    stack[0] = v_11916;
    v_11916 = stack[-1];
    fn = elt(env, 14); // simp
    v_11916 = (*qfn1(fn))(fn, v_11916);
    env = stack[-14];
    stack[-7] = v_11916;
    v_11916 = stack[0];
    fn = elt(env, 21); // setkorder
    v_11916 = (*qfn1(fn))(fn, v_11916);
    env = stack[-14];
    v_11916 = stack[-7];
    fn = elt(env, 22); // reordsq
    v_11916 = (*qfn1(fn))(fn, v_11916);
    env = stack[-14];
    stack[-7] = v_11916;
    v_11916 = stack[-11];
    if (v_11916 == nil) goto v_11586;
    else goto v_11587;
v_11586:
    v_11916 = stack[-7];
    fn = elt(env, 23); // kernp
    v_11916 = (*qfn1(fn))(fn, v_11916);
    env = stack[-14];
    if (v_11916 == nil) goto v_11591;
    else goto v_11592;
v_11591:
    v_11916 = nil;
    goto v_11590;
v_11592:
    goto v_11602;
v_11598:
    v_11916 = stack[-7];
    v_11916 = qcar(v_11916);
    v_11916 = qcar(v_11916);
    v_11916 = qcar(v_11916);
    v_11917 = qcar(v_11916);
    goto v_11599;
v_11600:
    v_11916 = stack[-2];
    goto v_11601;
v_11602:
    goto v_11598;
v_11599:
    goto v_11600;
v_11601:
    v_11916 = (v_11917 == v_11916 ? lisp_true : nil);
    goto v_11590;
    v_11916 = nil;
v_11590:
    goto v_11585;
v_11587:
    v_11916 = nil;
    goto v_11585;
    v_11916 = nil;
v_11585:
    if (v_11916 == nil) goto v_11583;
    goto v_11274;
v_11583:
    v_11916 = stack[-7];
    v_11916 = qcar(v_11916);
    if (v_11916 == nil) goto v_11613;
    else goto v_11614;
v_11613:
    goto v_11273;
v_11614:
    v_11916 = stack[-7];
    stack[-6] = v_11916;
    v_11916 = stack[-5];
    stack[-2] = v_11916;
v_11621:
    v_11916 = stack[-2];
    if (v_11916 == nil) goto v_11625;
    else goto v_11626;
v_11625:
    goto v_11620;
v_11626:
    v_11916 = stack[-2];
    v_11916 = qcar(v_11916);
    stack[-1] = v_11916;
    v_11916 = stack[-1];
    v_11916 = qcar(v_11916);
    v_11916 = qcdr(v_11916);
    stack[-10] = v_11916;
    goto v_11643;
v_11639:
    v_11917 = stack[-10];
    goto v_11640;
v_11641:
    v_11916 = qvalue(elt(env, 10)); // frlis!*
    goto v_11642;
v_11643:
    goto v_11639;
v_11640:
    goto v_11641;
v_11642:
    v_11916 = Lmemq(nil, v_11917, v_11916);
    if (v_11916 == nil) goto v_11638;
    goto v_11653;
v_11649:
    v_11916 = stack[-6];
    fn = elt(env, 24); // prepsq
    v_11917 = (*qfn1(fn))(fn, v_11916);
    env = stack[-14];
    goto v_11650;
v_11651:
    v_11916 = stack[-10];
    goto v_11652;
v_11653:
    goto v_11649;
v_11650:
    goto v_11651;
v_11652:
    v_11916 = list2(v_11917, v_11916);
    env = stack[-14];
    fn = elt(env, 25); // simpexpt
    v_11916 = (*qfn1(fn))(fn, v_11916);
    env = stack[-14];
    stack[-7] = v_11916;
    v_11916 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-10] = v_11916;
    goto v_11636;
v_11638:
v_11636:
    goto v_11663;
v_11659:
    goto v_11670;
v_11666:
    stack[0] = stack[-7];
    goto v_11667;
v_11668:
    goto v_11677;
v_11673:
    v_11917 = stack[-10];
    goto v_11674;
v_11675:
    v_11916 = stack[-13];
    goto v_11676;
v_11677:
    goto v_11673;
v_11674:
    goto v_11675;
v_11676:
    v_11916 = difference2(v_11917, v_11916);
    env = stack[-14];
    goto v_11669;
v_11670:
    goto v_11666;
v_11667:
    goto v_11668;
v_11669:
    fn = elt(env, 26); // exptsq
    v_11916 = (*qfn2(fn))(fn, stack[0], v_11916);
    env = stack[-14];
    fn = elt(env, 27); // subs2
    v_11917 = (*qfn1(fn))(fn, v_11916);
    env = stack[-14];
    goto v_11660;
v_11661:
    v_11916 = stack[-8];
    goto v_11662;
v_11663:
    goto v_11659;
v_11660:
    goto v_11661;
v_11662:
    fn = elt(env, 28); // multsq
    v_11916 = (*qfn2(fn))(fn, v_11917, v_11916);
    env = stack[-14];
    stack[-8] = v_11916;
    v_11916 = stack[-10];
    stack[-13] = v_11916;
    goto v_11687;
v_11683:
    goto v_11693;
v_11689:
    stack[0] = stack[-8];
    goto v_11690;
v_11691:
    goto v_11700;
v_11696:
    v_11916 = stack[-1];
    v_11917 = qcdr(v_11916);
    goto v_11697;
v_11698:
    v_11916 = stack[-11];
    goto v_11699;
v_11700:
    goto v_11696;
v_11697:
    goto v_11698;
v_11699:
    v_11916 = CC_subf1(elt(env, 0), v_11917, v_11916);
    env = stack[-14];
    goto v_11692;
v_11693:
    goto v_11689;
v_11690:
    goto v_11691;
v_11692:
    fn = elt(env, 28); // multsq
    v_11917 = (*qfn2(fn))(fn, stack[0], v_11916);
    env = stack[-14];
    goto v_11684;
v_11685:
    v_11916 = stack[-3];
    goto v_11686;
v_11687:
    goto v_11683;
v_11684:
    goto v_11685;
v_11686:
    fn = elt(env, 29); // addsq
    v_11916 = (*qfn2(fn))(fn, v_11917, v_11916);
    env = stack[-14];
    stack[-3] = v_11916;
    v_11916 = stack[-2];
    v_11916 = qcdr(v_11916);
    stack[-2] = v_11916;
    goto v_11621;
v_11620:
v_11273:
v_11709:
    v_11916 = stack[-5];
    if (v_11916 == nil) goto v_11712;
    else goto v_11713;
v_11712:
    goto v_11708;
v_11713:
    goto v_11721;
v_11717:
    v_11916 = stack[-5];
    v_11916 = qcar(v_11916);
    v_11917 = qcdr(v_11916);
    goto v_11718;
v_11719:
    v_11916 = stack[-11];
    goto v_11720;
v_11721:
    goto v_11717;
v_11718:
    goto v_11719;
v_11720:
    v_11916 = CC_subf1(elt(env, 0), v_11917, v_11916);
    env = stack[-14];
    v_11916 = stack[-5];
    v_11916 = qcdr(v_11916);
    stack[-5] = v_11916;
    goto v_11709;
v_11708:
    v_11916 = stack[-12];
    if (v_11916 == nil) goto v_11730;
    else goto v_11731;
v_11730:
    v_11916 = stack[-3];
    goto v_11268;
v_11731:
    v_11916 = stack[-12];
    if (!consp(v_11916)) goto v_11738;
    else goto v_11739;
v_11738:
    v_11916 = lisp_true;
    goto v_11737;
v_11739:
    v_11916 = stack[-12];
    v_11916 = qcar(v_11916);
    v_11916 = (consp(v_11916) ? nil : lisp_true);
    goto v_11737;
    v_11916 = nil;
v_11737:
    if (v_11916 == nil) goto v_11735;
    goto v_11752;
v_11748:
    goto v_11758;
v_11754:
    v_11917 = stack[-12];
    goto v_11755;
v_11756:
    v_11916 = stack[-11];
    goto v_11757;
v_11758:
    goto v_11754;
v_11755:
    goto v_11756;
v_11757:
    v_11917 = CC_subf1(elt(env, 0), v_11917, v_11916);
    env = stack[-14];
    goto v_11749;
v_11750:
    v_11916 = stack[-3];
    goto v_11751;
v_11752:
    goto v_11748;
v_11749:
    goto v_11750;
v_11751:
    fn = elt(env, 29); // addsq
    v_11916 = (*qfn2(fn))(fn, v_11917, v_11916);
    goto v_11268;
v_11735:
    goto v_11269;
v_11274:
    v_11916 = stack[-2];
    fn = elt(env, 30); // sub2chk
    v_11916 = (*qfn1(fn))(fn, v_11916);
    env = stack[-14];
    v_11916 = stack[-5];
    stack[-2] = v_11916;
v_11767:
    v_11916 = stack[-2];
    if (v_11916 == nil) goto v_11771;
    else goto v_11772;
v_11771:
    goto v_11766;
v_11772:
    v_11916 = stack[-2];
    v_11916 = qcar(v_11916);
    stack[-1] = v_11916;
    goto v_11783;
v_11779:
    goto v_11789;
v_11785:
    goto v_11795;
v_11791:
    goto v_11802;
v_11798:
    v_11916 = stack[-1];
    v_11917 = qcar(v_11916);
    goto v_11799;
v_11800:
    v_11916 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11801;
v_11802:
    goto v_11798;
v_11799:
    goto v_11800;
v_11801:
    v_11916 = cons(v_11917, v_11916);
    env = stack[-14];
    v_11917 = ncons(v_11916);
    env = stack[-14];
    goto v_11792;
v_11793:
    v_11916 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11794;
v_11795:
    goto v_11791;
v_11792:
    goto v_11793;
v_11794:
    stack[0] = cons(v_11917, v_11916);
    env = stack[-14];
    goto v_11786;
v_11787:
    goto v_11812;
v_11808:
    v_11916 = stack[-1];
    v_11917 = qcdr(v_11916);
    goto v_11809;
v_11810:
    v_11916 = stack[-11];
    goto v_11811;
v_11812:
    goto v_11808;
v_11809:
    goto v_11810;
v_11811:
    v_11916 = CC_subf1(elt(env, 0), v_11917, v_11916);
    env = stack[-14];
    goto v_11788;
v_11789:
    goto v_11785;
v_11786:
    goto v_11787;
v_11788:
    fn = elt(env, 28); // multsq
    v_11917 = (*qfn2(fn))(fn, stack[0], v_11916);
    env = stack[-14];
    goto v_11780;
v_11781:
    v_11916 = stack[-3];
    goto v_11782;
v_11783:
    goto v_11779;
v_11780:
    goto v_11781;
v_11782:
    fn = elt(env, 29); // addsq
    v_11916 = (*qfn2(fn))(fn, v_11917, v_11916);
    env = stack[-14];
    stack[-3] = v_11916;
    v_11916 = stack[-2];
    v_11916 = qcdr(v_11916);
    stack[-2] = v_11916;
    goto v_11767;
v_11766:
    goto v_11273;
v_11275:
    v_11916 = stack[-1];
    v_11916 = ncons(v_11916);
    env = stack[-14];
    fn = elt(env, 31); // simprecip
    v_11916 = (*qfn1(fn))(fn, v_11916);
    env = stack[-14];
    stack[-7] = v_11916;
v_11276:
    goto v_11827;
v_11823:
    v_11916 = stack[-5];
    v_11917 = qcar(v_11916);
    goto v_11824;
v_11825:
    v_11916 = stack[-4];
    goto v_11826;
v_11827:
    goto v_11823;
v_11824:
    goto v_11825;
v_11826:
    v_11916 = cons(v_11917, v_11916);
    env = stack[-14];
    stack[-4] = v_11916;
    v_11916 = stack[-5];
    v_11916 = qcdr(v_11916);
    stack[-5] = v_11916;
    v_11916 = stack[-5];
    if (v_11916 == nil) goto v_11836;
    goto v_11845;
v_11841:
    v_11916 = stack[-5];
    v_11916 = qcar(v_11916);
    v_11916 = qcar(v_11916);
    v_11917 = qcdr(v_11916);
    goto v_11842;
v_11843:
    v_11916 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11844;
v_11845:
    goto v_11841;
v_11842:
    goto v_11843;
v_11844:
    v_11916 = (LispObject)lessp2(v_11917, v_11916);
    v_11916 = v_11916 ? lisp_true : nil;
    env = stack[-14];
    if (v_11916 == nil) goto v_11836;
    goto v_11276;
v_11836:
v_11277:
    v_11916 = stack[-4];
    v_11916 = qcar(v_11916);
    v_11916 = qcar(v_11916);
    v_11916 = qcdr(v_11916);
    v_11916 = negate(v_11916);
    env = stack[-14];
    stack[-10] = v_11916;
    goto v_11861;
v_11857:
    goto v_11868;
v_11864:
    stack[0] = stack[-7];
    goto v_11865;
v_11866:
    goto v_11875;
v_11871:
    v_11917 = stack[-10];
    goto v_11872;
v_11873:
    v_11916 = stack[-13];
    goto v_11874;
v_11875:
    goto v_11871;
v_11872:
    goto v_11873;
v_11874:
    v_11916 = difference2(v_11917, v_11916);
    env = stack[-14];
    goto v_11867;
v_11868:
    goto v_11864;
v_11865:
    goto v_11866;
v_11867:
    fn = elt(env, 26); // exptsq
    v_11916 = (*qfn2(fn))(fn, stack[0], v_11916);
    env = stack[-14];
    fn = elt(env, 27); // subs2
    v_11917 = (*qfn1(fn))(fn, v_11916);
    env = stack[-14];
    goto v_11858;
v_11859:
    v_11916 = stack[-8];
    goto v_11860;
v_11861:
    goto v_11857;
v_11858:
    goto v_11859;
v_11860:
    fn = elt(env, 28); // multsq
    v_11916 = (*qfn2(fn))(fn, v_11917, v_11916);
    env = stack[-14];
    stack[-8] = v_11916;
    v_11916 = stack[-10];
    stack[-13] = v_11916;
    goto v_11885;
v_11881:
    goto v_11891;
v_11887:
    stack[0] = stack[-8];
    goto v_11888;
v_11889:
    goto v_11898;
v_11894:
    v_11916 = stack[-4];
    v_11916 = qcar(v_11916);
    v_11917 = qcdr(v_11916);
    goto v_11895;
v_11896:
    v_11916 = stack[-11];
    goto v_11897;
v_11898:
    goto v_11894;
v_11895:
    goto v_11896;
v_11897:
    v_11916 = CC_subf1(elt(env, 0), v_11917, v_11916);
    env = stack[-14];
    goto v_11890;
v_11891:
    goto v_11887;
v_11888:
    goto v_11889;
v_11890:
    fn = elt(env, 28); // multsq
    v_11917 = (*qfn2(fn))(fn, stack[0], v_11916);
    env = stack[-14];
    goto v_11882;
v_11883:
    v_11916 = stack[-3];
    goto v_11884;
v_11885:
    goto v_11881;
v_11882:
    goto v_11883;
v_11884:
    fn = elt(env, 29); // addsq
    v_11916 = (*qfn2(fn))(fn, v_11917, v_11916);
    env = stack[-14];
    stack[-3] = v_11916;
    v_11916 = stack[-4];
    v_11916 = qcdr(v_11916);
    stack[-4] = v_11916;
    v_11916 = stack[-4];
    if (v_11916 == nil) goto v_11909;
    goto v_11277;
v_11909:
    v_11916 = stack[-5];
    if (v_11916 == nil) goto v_11912;
    goto v_11272;
v_11912:
    goto v_11273;
    v_11916 = nil;
v_11268:
    ;}  // end of a binding scope
    goto v_11172;
    v_11916 = nil;
v_11172:
    return onevalue(v_11916);
}



// Code for aex_fvarl

static LispObject CC_aex_fvarl(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11181;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11168);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11168;
// end of prologue
    goto v_11175;
v_11171:
    v_11181 = stack[0];
    fn = elt(env, 1); // aex_varl
    stack[-1] = (*qfn1(fn))(fn, v_11181);
    env = stack[-2];
    goto v_11172;
v_11173:
    v_11181 = stack[0];
    fn = elt(env, 2); // aex_ctx
    v_11181 = (*qfn1(fn))(fn, v_11181);
    env = stack[-2];
    fn = elt(env, 3); // ctx_idl
    v_11181 = (*qfn1(fn))(fn, v_11181);
    env = stack[-2];
    goto v_11174;
v_11175:
    goto v_11171;
v_11172:
    goto v_11173;
v_11174:
    {
        LispObject v_11184 = stack[-1];
        fn = elt(env, 4); // lto_setminus
        return (*qfn2(fn))(fn, v_11184, v_11181);
    }
}



// Code for triplesetprolongset

static LispObject CC_triplesetprolongset(LispObject env,
                         LispObject v_11168, LispObject v_11169)
{
    env = qenv(env);
    LispObject v_11206, v_11207;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11168,v_11169);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11169;
    stack[-1] = v_11168;
// end of prologue
    v_11207 = nil;
v_11176:
    v_11206 = stack[0];
    if (v_11206 == nil) goto v_11179;
    else goto v_11180;
v_11179:
    goto v_11175;
v_11180:
    goto v_11188;
v_11184:
    v_11206 = stack[0];
    v_11206 = qcar(v_11206);
    goto v_11185;
v_11186:
    goto v_11187;
v_11188:
    goto v_11184;
v_11185:
    goto v_11186;
v_11187:
    v_11206 = cons(v_11206, v_11207);
    env = stack[-2];
    v_11207 = v_11206;
    v_11206 = stack[0];
    v_11206 = qcdr(v_11206);
    stack[0] = v_11206;
    goto v_11176;
v_11175:
    goto v_11201;
v_11195:
    goto v_11196;
v_11197:
    stack[0] = (LispObject)48+TAG_FIXNUM; // 3
    goto v_11198;
v_11199:
    v_11206 = v_11207;
    v_11206 = Lreverse(nil, v_11206);
    goto v_11200;
v_11201:
    goto v_11195;
v_11196:
    goto v_11197;
v_11198:
    goto v_11199;
v_11200:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_11206;
    v_11206 = nil;
    return onevalue(v_11206);
}



// Code for simp!*sq

static LispObject CC_simpHsq(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11187, v_11188;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11188 = v_11168;
// end of prologue
    v_11187 = v_11188;
    v_11187 = qcdr(v_11187);
    v_11187 = qcar(v_11187);
    if (v_11187 == nil) goto v_11173;
    v_11187 = qvalue(elt(env, 1)); // !*resimp
    if (v_11187 == nil) goto v_11178;
    else goto v_11173;
v_11178:
    v_11187 = v_11188;
    v_11187 = qcar(v_11187);
    goto v_11171;
v_11173:
    v_11187 = v_11188;
    v_11187 = qcar(v_11187);
    {
        fn = elt(env, 2); // resimp1
        return (*qfn1(fn))(fn, v_11187);
    }
    v_11187 = nil;
v_11171:
    return onevalue(v_11187);
}



// Code for sfto_ucontentf1

static LispObject CC_sfto_ucontentf1(LispObject env,
                         LispObject v_11168, LispObject v_11169)
{
    env = qenv(env);
    LispObject v_11241, v_11242;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11168,v_11169);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11169;
    stack[-1] = v_11168;
// end of prologue
    stack[-2] = nil;
v_11175:
    v_11241 = stack[-1];
    if (!consp(v_11241)) goto v_11188;
    else goto v_11189;
v_11188:
    v_11241 = lisp_true;
    goto v_11187;
v_11189:
    v_11241 = stack[-1];
    v_11241 = qcar(v_11241);
    v_11241 = (consp(v_11241) ? nil : lisp_true);
    goto v_11187;
    v_11241 = nil;
v_11187:
    if (v_11241 == nil) goto v_11185;
    v_11241 = lisp_true;
    goto v_11183;
v_11185:
    goto v_11205;
v_11201:
    v_11241 = stack[-1];
    v_11241 = qcar(v_11241);
    v_11241 = qcar(v_11241);
    v_11242 = qcar(v_11241);
    goto v_11202;
v_11203:
    v_11241 = stack[0];
    goto v_11204;
v_11205:
    goto v_11201;
v_11202:
    goto v_11203;
v_11204:
    v_11241 = Lneq(nil, v_11242, v_11241);
    env = stack[-3];
    goto v_11183;
    v_11241 = nil;
v_11183:
    if (v_11241 == nil) goto v_11181;
    goto v_11176;
v_11181:
    goto v_11216;
v_11212:
    v_11241 = stack[-1];
    v_11241 = qcar(v_11241);
    v_11242 = qcdr(v_11241);
    goto v_11213;
v_11214:
    v_11241 = stack[-2];
    goto v_11215;
v_11216:
    goto v_11212;
v_11213:
    goto v_11214;
v_11215:
    v_11241 = cons(v_11242, v_11241);
    env = stack[-3];
    stack[-2] = v_11241;
    v_11241 = stack[-1];
    v_11241 = qcdr(v_11241);
    stack[-1] = v_11241;
    goto v_11175;
v_11176:
    v_11241 = stack[-1];
    v_11242 = v_11241;
v_11177:
    v_11241 = stack[-2];
    if (v_11241 == nil) goto v_11226;
    else goto v_11227;
v_11226:
    v_11241 = v_11242;
    goto v_11174;
v_11227:
    goto v_11235;
v_11231:
    v_11241 = stack[-2];
    v_11241 = qcar(v_11241);
    goto v_11232;
v_11233:
    goto v_11234;
v_11235:
    goto v_11231;
v_11232:
    goto v_11233;
v_11234:
    fn = elt(env, 1); // sfto_gcdf!*
    v_11241 = (*qfn2(fn))(fn, v_11241, v_11242);
    env = stack[-3];
    v_11242 = v_11241;
    v_11241 = stack[-2];
    v_11241 = qcdr(v_11241);
    stack[-2] = v_11241;
    goto v_11177;
v_11174:
    return onevalue(v_11241);
}



// Code for talp_invn

static LispObject CC_talp_invn(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11181;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11168);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_11181 = v_11168;
// end of prologue
    fn = elt(env, 1); // talp_op
    v_11181 = (*qfn1(fn))(fn, v_11181);
    env = stack[0];
    v_11181 = Lexplodec(nil, v_11181);
    env = stack[0];
    v_11181 = qcdr(v_11181);
    v_11181 = qcdr(v_11181);
    v_11181 = qcdr(v_11181);
    v_11181 = qcdr(v_11181);
    v_11181 = qcdr(v_11181);
    v_11181 = qcar(v_11181);
    v_11181 = ncons(v_11181);
        return Lcompress(nil, v_11181);
}



// Code for lx2xx

static LispObject CC_lx2xx(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11245, v_11246;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11168);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_11168;
// end of prologue
    v_11245 = stack[-2];
    if (!consp(v_11245)) goto v_11184;
    else goto v_11185;
v_11184:
    v_11245 = lisp_true;
    goto v_11183;
v_11185:
    v_11245 = stack[-2];
    v_11245 = qcar(v_11245);
    v_11245 = (consp(v_11245) ? nil : lisp_true);
    goto v_11183;
    v_11245 = nil;
v_11183:
    if (v_11245 == nil) goto v_11181;
    v_11245 = lisp_true;
    goto v_11179;
v_11181:
    v_11245 = stack[-2];
    v_11245 = qcar(v_11245);
    if (!consp(v_11245)) goto v_11198;
    else goto v_11199;
v_11198:
    v_11245 = lisp_true;
    goto v_11197;
v_11199:
    v_11245 = stack[-2];
    v_11245 = qcar(v_11245);
    v_11245 = qcar(v_11245);
    v_11245 = (consp(v_11245) ? nil : lisp_true);
    goto v_11197;
    v_11245 = nil;
v_11197:
    goto v_11179;
    v_11245 = nil;
v_11179:
    if (v_11245 == nil) goto v_11177;
    v_11245 = stack[-2];
    goto v_11173;
v_11177:
    v_11245 = stack[-2];
    v_11245 = qcdr(v_11245);
    v_11245 = qcar(v_11245);
    stack[-3] = v_11245;
    v_11245 = stack[-3];
    fn = elt(env, 1); // lastnondomain
    v_11245 = (*qfn1(fn))(fn, v_11245);
    env = stack[-4];
    v_11245 = qcdr(v_11245);
    stack[-1] = v_11245;
    goto v_11223;
v_11217:
    v_11245 = stack[-2];
    stack[0] = qcar(v_11245);
    goto v_11218;
v_11219:
    goto v_11231;
v_11227:
    goto v_11238;
v_11234:
    v_11246 = stack[-1];
    goto v_11235;
v_11236:
    v_11245 = stack[-3];
    goto v_11237;
v_11238:
    goto v_11234;
v_11235:
    goto v_11236;
v_11237:
    fn = elt(env, 2); // delet
    v_11245 = (*qfn2(fn))(fn, v_11246, v_11245);
    env = stack[-4];
    fn = elt(env, 3); // xxsort
    v_11246 = (*qfn1(fn))(fn, v_11245);
    env = stack[-4];
    goto v_11228;
v_11229:
    v_11245 = stack[-1];
    goto v_11230;
v_11231:
    goto v_11227;
v_11228:
    goto v_11229;
v_11230:
    v_11246 = Lappend(nil, v_11246, v_11245);
    goto v_11220;
v_11221:
    v_11245 = stack[-2];
    v_11245 = qcdr(v_11245);
    v_11245 = qcdr(v_11245);
    goto v_11222;
v_11223:
    goto v_11217;
v_11218:
    goto v_11219;
v_11220:
    goto v_11221;
v_11222:
    {
        LispObject v_11251 = stack[0];
        return list2star(v_11251, v_11246, v_11245);
    }
v_11173:
    return onevalue(v_11245);
}



// Code for ibalp_renewwl

static LispObject CC_ibalp_renewwl(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11492, v_11493;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11168);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_11492 = v_11168;
// end of prologue
    stack[-2] = v_11492;
v_11176:
    v_11492 = stack[-2];
    if (v_11492 == nil) goto v_11180;
    else goto v_11181;
v_11180:
    goto v_11175;
v_11181:
    v_11492 = stack[-2];
    v_11492 = qcar(v_11492);
    stack[-1] = v_11492;
    v_11492 = stack[-1];
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcar(v_11492);
    if (v_11492 == nil) goto v_11189;
    else goto v_11190;
v_11189:
    goto v_11207;
v_11203:
    v_11492 = stack[-1];
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcar(v_11492);
    v_11493 = Llength(nil, v_11492);
    env = stack[-4];
    goto v_11204;
v_11205:
    v_11492 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11206;
v_11207:
    goto v_11203;
v_11204:
    goto v_11205;
v_11206:
    v_11492 = Leqn(nil, v_11493, v_11492);
    env = stack[-4];
    if (v_11492 == nil) goto v_11200;
    goto v_11224;
v_11220:
    goto v_11230;
v_11226:
    v_11492 = stack[-1];
    v_11492 = qcar(v_11492);
    stack[0] = Llength(nil, v_11492);
    env = stack[-4];
    goto v_11227;
v_11228:
    v_11492 = stack[-1];
    v_11492 = qcdr(v_11492);
    v_11492 = qcar(v_11492);
    v_11492 = Llength(nil, v_11492);
    env = stack[-4];
    goto v_11229;
v_11230:
    goto v_11226;
v_11227:
    goto v_11228;
v_11229:
    v_11493 = plus2(stack[0], v_11492);
    env = stack[-4];
    goto v_11221;
v_11222:
    v_11492 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11223;
v_11224:
    goto v_11220;
v_11221:
    goto v_11222;
v_11223:
    v_11492 = (LispObject)greaterp2(v_11493, v_11492);
    v_11492 = v_11492 ? lisp_true : nil;
    env = stack[-4];
    if (v_11492 == nil) goto v_11200;
    v_11492 = stack[-1];
    fn = elt(env, 1); // ibalp_getnewwl
    v_11492 = (*qfn1(fn))(fn, v_11492);
    env = stack[-4];
    stack[-3] = v_11492;
    v_11492 = stack[-3];
    if (v_11492 == nil) goto v_11244;
    goto v_11251;
v_11247:
    v_11492 = stack[-1];
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    stack[0] = qcdr(v_11492);
    goto v_11248;
v_11249:
    goto v_11264;
v_11260:
    v_11493 = stack[-3];
    goto v_11261;
v_11262:
    v_11492 = stack[-1];
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcar(v_11492);
    goto v_11263;
v_11264:
    goto v_11260;
v_11261:
    goto v_11262;
v_11263:
    v_11492 = cons(v_11493, v_11492);
    env = stack[-4];
    goto v_11250;
v_11251:
    goto v_11247;
v_11248:
    goto v_11249;
v_11250:
    fn = elt(env, 2); // setcar
    v_11492 = (*qfn2(fn))(fn, stack[0], v_11492);
    env = stack[-4];
    goto v_11279;
v_11275:
    v_11492 = stack[-3];
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    stack[0] = qcdr(v_11492);
    goto v_11276;
v_11277:
    goto v_11296;
v_11292:
    v_11493 = stack[-1];
    goto v_11293;
v_11294:
    v_11492 = stack[-3];
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcar(v_11492);
    goto v_11295;
v_11296:
    goto v_11292;
v_11293:
    goto v_11294;
v_11295:
    v_11492 = cons(v_11493, v_11492);
    env = stack[-4];
    goto v_11278;
v_11279:
    goto v_11275;
v_11276:
    goto v_11277;
v_11278:
    fn = elt(env, 2); // setcar
    v_11492 = (*qfn2(fn))(fn, stack[0], v_11492);
    env = stack[-4];
    goto v_11242;
v_11244:
v_11242:
    goto v_11198;
v_11200:
    v_11492 = stack[-1];
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcar(v_11492);
    if (v_11492 == nil) goto v_11315;
    else goto v_11316;
v_11315:
    goto v_11330;
v_11326:
    goto v_11336;
v_11332:
    v_11492 = stack[-1];
    v_11492 = qcar(v_11492);
    stack[0] = Llength(nil, v_11492);
    env = stack[-4];
    goto v_11333;
v_11334:
    v_11492 = stack[-1];
    v_11492 = qcdr(v_11492);
    v_11492 = qcar(v_11492);
    v_11492 = Llength(nil, v_11492);
    env = stack[-4];
    goto v_11335;
v_11336:
    goto v_11332;
v_11333:
    goto v_11334;
v_11335:
    v_11493 = plus2(stack[0], v_11492);
    env = stack[-4];
    goto v_11327;
v_11328:
    v_11492 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11329;
v_11330:
    goto v_11326;
v_11327:
    goto v_11328;
v_11329:
    v_11492 = (LispObject)greaterp2(v_11493, v_11492);
    v_11492 = v_11492 ? lisp_true : nil;
    env = stack[-4];
    goto v_11314;
v_11316:
    v_11492 = nil;
    goto v_11314;
    v_11492 = nil;
v_11314:
    if (v_11492 == nil) goto v_11312;
    v_11492 = stack[-1];
    fn = elt(env, 1); // ibalp_getnewwl
    v_11492 = (*qfn1(fn))(fn, v_11492);
    env = stack[-4];
    stack[-3] = v_11492;
    v_11492 = stack[-3];
    if (v_11492 == nil) goto v_11353;
    goto v_11360;
v_11356:
    v_11492 = stack[-1];
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    stack[0] = qcdr(v_11492);
    goto v_11357;
v_11358:
    goto v_11373;
v_11369:
    v_11493 = stack[-3];
    goto v_11370;
v_11371:
    v_11492 = stack[-1];
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcar(v_11492);
    goto v_11372;
v_11373:
    goto v_11369;
v_11370:
    goto v_11371;
v_11372:
    v_11492 = cons(v_11493, v_11492);
    env = stack[-4];
    goto v_11359;
v_11360:
    goto v_11356;
v_11357:
    goto v_11358;
v_11359:
    fn = elt(env, 2); // setcar
    v_11492 = (*qfn2(fn))(fn, stack[0], v_11492);
    env = stack[-4];
    goto v_11388;
v_11384:
    v_11492 = stack[-3];
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    stack[0] = qcdr(v_11492);
    goto v_11385;
v_11386:
    goto v_11405;
v_11401:
    v_11493 = stack[-1];
    goto v_11402;
v_11403:
    v_11492 = stack[-3];
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcar(v_11492);
    goto v_11404;
v_11405:
    goto v_11401;
v_11402:
    goto v_11403;
v_11404:
    v_11492 = cons(v_11493, v_11492);
    env = stack[-4];
    goto v_11387;
v_11388:
    goto v_11384;
v_11385:
    goto v_11386;
v_11387:
    fn = elt(env, 2); // setcar
    v_11492 = (*qfn2(fn))(fn, stack[0], v_11492);
    env = stack[-4];
    goto v_11351;
v_11353:
v_11351:
    v_11492 = stack[-1];
    fn = elt(env, 1); // ibalp_getnewwl
    v_11492 = (*qfn1(fn))(fn, v_11492);
    env = stack[-4];
    stack[-3] = v_11492;
    v_11492 = stack[-3];
    if (v_11492 == nil) goto v_11424;
    goto v_11431;
v_11427:
    v_11492 = stack[-1];
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    stack[0] = qcdr(v_11492);
    goto v_11428;
v_11429:
    goto v_11444;
v_11440:
    v_11493 = stack[-3];
    goto v_11441;
v_11442:
    v_11492 = stack[-1];
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcar(v_11492);
    goto v_11443;
v_11444:
    goto v_11440;
v_11441:
    goto v_11442;
v_11443:
    v_11492 = cons(v_11493, v_11492);
    env = stack[-4];
    goto v_11430;
v_11431:
    goto v_11427;
v_11428:
    goto v_11429;
v_11430:
    fn = elt(env, 2); // setcar
    v_11492 = (*qfn2(fn))(fn, stack[0], v_11492);
    env = stack[-4];
    goto v_11459;
v_11455:
    v_11492 = stack[-3];
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    stack[0] = qcdr(v_11492);
    goto v_11456;
v_11457:
    goto v_11476;
v_11472:
    v_11493 = stack[-1];
    goto v_11473;
v_11474:
    v_11492 = stack[-3];
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcdr(v_11492);
    v_11492 = qcar(v_11492);
    goto v_11475;
v_11476:
    goto v_11472;
v_11473:
    goto v_11474;
v_11475:
    v_11492 = cons(v_11493, v_11492);
    env = stack[-4];
    goto v_11458;
v_11459:
    goto v_11455;
v_11456:
    goto v_11457;
v_11458:
    fn = elt(env, 2); // setcar
    v_11492 = (*qfn2(fn))(fn, stack[0], v_11492);
    env = stack[-4];
    goto v_11422;
v_11424:
v_11422:
    goto v_11198;
v_11312:
v_11198:
    goto v_11188;
v_11190:
v_11188:
    v_11492 = stack[-2];
    v_11492 = qcdr(v_11492);
    stack[-2] = v_11492;
    goto v_11176;
v_11175:
    v_11492 = nil;
    return onevalue(v_11492);
}



// Code for stats_getargs

static LispObject CC_stats_getargs(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11187, v_11188;
    LispObject fn;
    argcheck(nargs, 0, "stats_getargs");
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
    v_11187 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_11188 = v_11187;
    v_11187 = v_11188;
    if (v_11187 == nil) goto v_11177;
    goto v_11184;
v_11180:
    stack[0] = v_11188;
    goto v_11181;
v_11182:
    v_11187 = CC_stats_getargs(elt(env, 0), 0);
    goto v_11183;
v_11184:
    goto v_11180;
v_11181:
    goto v_11182;
v_11183:
    {
        LispObject v_11190 = stack[0];
        return cons(v_11190, v_11187);
    }
v_11177:
    v_11187 = nil;
    return onevalue(v_11187);
}



// Code for list!-mgen

static LispObject CC_listKmgen(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11207, v_11208;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11168);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_11208 = v_11168;
// end of prologue
// Binding i
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 1, -1);
    qvalue(elt(env, 1)) = nil; // i
    v_11207 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 1)) = v_11207; // i
    v_11207 = v_11208;
    stack[0] = v_11207;
v_11177:
    v_11207 = stack[0];
    if (v_11207 == nil) goto v_11181;
    else goto v_11182;
v_11181:
    goto v_11176;
v_11182:
    v_11207 = stack[0];
    v_11207 = qcar(v_11207);
    v_11208 = v_11207;
    v_11207 = v_11208;
    if (!consp(v_11207)) goto v_11194;
    else goto v_11195;
v_11194:
    v_11207 = v_11208;
    fn = elt(env, 2); // mgenp
    v_11207 = (*qfn1(fn))(fn, v_11207);
    env = stack[-2];
    goto v_11193;
v_11195:
    v_11207 = nil;
    goto v_11193;
    v_11207 = nil;
v_11193:
    if (v_11207 == nil) goto v_11191;
    v_11207 = qvalue(elt(env, 1)); // i
    v_11207 = add1(v_11207);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_11207; // i
    goto v_11189;
v_11191:
v_11189:
    v_11207 = stack[0];
    v_11207 = qcdr(v_11207);
    stack[0] = v_11207;
    goto v_11177;
v_11176:
    v_11207 = qvalue(elt(env, 1)); // i
    ;}  // end of a binding scope
    return onevalue(v_11207);
}



// Code for prinfit

static LispObject CC_prinfit(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11236, v_11237, v_11238;
    LispObject fn;
    LispObject v_11170, v_11169, v_11168;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "prinfit");
    va_start(aa, nargs);
    v_11168 = va_arg(aa, LispObject);
    v_11169 = va_arg(aa, LispObject);
    v_11170 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_11170,v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_11168,v_11169,v_11170);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11170;
    stack[-1] = v_11169;
    stack[-2] = v_11168;
// end of prologue
    v_11236 = qvalue(elt(env, 1)); // !*nat
    if (v_11236 == nil) goto v_11181;
    else goto v_11182;
v_11181:
    v_11236 = lisp_true;
    goto v_11180;
v_11182:
    v_11236 = qvalue(elt(env, 2)); // testing!-width!*
    goto v_11180;
    v_11236 = nil;
v_11180:
    if (v_11236 == nil) goto v_11178;
    v_11236 = stack[0];
    if (v_11236 == nil) goto v_11191;
    v_11236 = stack[0];
    fn = elt(env, 3); // oprin
    v_11236 = (*qfn1(fn))(fn, v_11236);
    env = stack[-3];
    goto v_11189;
v_11191:
v_11189:
    goto v_11200;
v_11196:
    v_11237 = stack[-2];
    goto v_11197;
v_11198:
    v_11236 = stack[-1];
    goto v_11199;
v_11200:
    goto v_11196;
v_11197:
    goto v_11198;
v_11199:
    {
        fn = elt(env, 4); // maprint
        return (*qfn2(fn))(fn, v_11237, v_11236);
    }
v_11178:
    goto v_11210;
v_11204:
    v_11238 = stack[-2];
    goto v_11205;
v_11206:
    v_11237 = stack[-1];
    goto v_11207;
v_11208:
    v_11236 = stack[0];
    goto v_11209;
v_11210:
    goto v_11204;
v_11205:
    goto v_11206;
v_11207:
    goto v_11208;
v_11209:
    fn = elt(env, 5); // layout!-formula
    v_11236 = (*qfnn(fn))(fn, 3, v_11238, v_11237, v_11236);
    env = stack[-3];
    v_11237 = v_11236;
    v_11236 = v_11237;
    if (v_11236 == nil) goto v_11216;
    else goto v_11217;
v_11216:
    v_11236 = stack[0];
    if (v_11236 == nil) goto v_11222;
    v_11236 = stack[0];
    fn = elt(env, 3); // oprin
    v_11236 = (*qfn1(fn))(fn, v_11236);
    env = stack[-3];
    goto v_11220;
v_11222:
v_11220:
    goto v_11231;
v_11227:
    v_11237 = stack[-2];
    goto v_11228;
v_11229:
    v_11236 = stack[-1];
    goto v_11230;
v_11231:
    goto v_11227;
v_11228:
    goto v_11229;
v_11230:
    {
        fn = elt(env, 4); // maprint
        return (*qfn2(fn))(fn, v_11237, v_11236);
    }
v_11217:
    v_11236 = v_11237;
    fn = elt(env, 6); // putpline
    v_11236 = (*qfn1(fn))(fn, v_11236);
    v_11236 = nil;
    return onevalue(v_11236);
}



// Code for evalequal

static LispObject CC_evalequal(LispObject env,
                         LispObject v_11168, LispObject v_11169)
{
    env = qenv(env);
    LispObject v_11222, v_11223, v_11224;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11168,v_11169);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11169;
    stack[-2] = v_11168;
// end of prologue
    goto v_11182;
v_11178:
    v_11222 = stack[-2];
    fn = elt(env, 2); // getrtype
    stack[0] = (*qfn1(fn))(fn, v_11222);
    env = stack[-4];
    stack[-3] = stack[0];
    goto v_11179;
v_11180:
    v_11222 = stack[-1];
    fn = elt(env, 2); // getrtype
    v_11222 = (*qfn1(fn))(fn, v_11222);
    env = stack[-4];
    goto v_11181;
v_11182:
    goto v_11178;
v_11179:
    goto v_11180;
v_11181:
    if (equal(stack[0], v_11222)) goto v_11177;
    v_11222 = nil;
    goto v_11175;
v_11177:
    v_11222 = stack[-3];
    if (v_11222 == nil) goto v_11188;
    else goto v_11189;
v_11188:
    goto v_11203;
v_11197:
    v_11224 = elt(env, 1); // difference
    goto v_11198;
v_11199:
    v_11223 = stack[-2];
    goto v_11200;
v_11201:
    v_11222 = stack[-1];
    goto v_11202;
v_11203:
    goto v_11197;
v_11198:
    goto v_11199;
v_11200:
    goto v_11201;
v_11202:
    v_11222 = list3(v_11224, v_11223, v_11222);
    env = stack[-4];
    fn = elt(env, 3); // reval
    v_11222 = (*qfn1(fn))(fn, v_11222);
    stack[-3] = v_11222;
    if (is_number(v_11222)) goto v_11194;
    v_11222 = nil;
    goto v_11192;
v_11194:
    v_11222 = stack[-3];
        return Lzerop(nil, v_11222);
    v_11222 = nil;
v_11192:
    goto v_11175;
v_11189:
    goto v_11218;
v_11214:
    v_11223 = stack[-2];
    goto v_11215;
v_11216:
    v_11222 = stack[-1];
    goto v_11217;
v_11218:
    goto v_11214;
v_11215:
    goto v_11216;
v_11217:
    v_11222 = (equal(v_11223, v_11222) ? lisp_true : nil);
    goto v_11175;
    v_11222 = nil;
v_11175:
    return onevalue(v_11222);
}



// Code for mv2sf1

static LispObject CC_mv2sf1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11227, v_11228, v_11229;
    LispObject fn;
    LispObject v_11170, v_11169, v_11168;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mv2sf1");
    va_start(aa, nargs);
    v_11168 = va_arg(aa, LispObject);
    v_11169 = va_arg(aa, LispObject);
    v_11170 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_11170,v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_11168,v_11169,v_11170);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_11170;
    stack[-1] = v_11169;
    stack[-2] = v_11168;
// end of prologue
v_11174:
    v_11227 = stack[-2];
    if (v_11227 == nil) goto v_11177;
    else goto v_11178;
v_11177:
    v_11227 = stack[-1];
    goto v_11173;
v_11178:
    goto v_11187;
v_11183:
    v_11227 = stack[-2];
    v_11228 = qcar(v_11227);
    goto v_11184;
v_11185:
    v_11227 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11186;
v_11187:
    goto v_11183;
v_11184:
    goto v_11185;
v_11186:
    if (v_11228 == v_11227) goto v_11181;
    else goto v_11182;
v_11181:
    v_11227 = stack[-2];
    v_11227 = qcdr(v_11227);
    stack[-2] = v_11227;
    v_11227 = stack[0];
    v_11227 = qcdr(v_11227);
    stack[0] = v_11227;
    goto v_11174;
v_11182:
    goto v_11203;
v_11199:
    goto v_11209;
v_11205:
    v_11227 = stack[0];
    v_11228 = qcar(v_11227);
    goto v_11206;
v_11207:
    v_11227 = stack[-2];
    v_11227 = qcar(v_11227);
    goto v_11208;
v_11209:
    goto v_11205;
v_11206:
    goto v_11207;
v_11208:
    fn = elt(env, 1); // to
    stack[-3] = (*qfn2(fn))(fn, v_11228, v_11227);
    env = stack[-4];
    goto v_11200;
v_11201:
    goto v_11221;
v_11215:
    v_11227 = stack[-2];
    v_11229 = qcdr(v_11227);
    goto v_11216;
v_11217:
    v_11228 = stack[-1];
    goto v_11218;
v_11219:
    v_11227 = stack[0];
    v_11227 = qcdr(v_11227);
    goto v_11220;
v_11221:
    goto v_11215;
v_11216:
    goto v_11217;
v_11218:
    goto v_11219;
v_11220:
    v_11227 = CC_mv2sf1(elt(env, 0), 3, v_11229, v_11228, v_11227);
    env = stack[-4];
    goto v_11202;
v_11203:
    goto v_11199;
v_11200:
    goto v_11201;
v_11202:
    v_11227 = cons(stack[-3], v_11227);
    return ncons(v_11227);
    v_11227 = nil;
v_11173:
    return onevalue(v_11227);
}



// Code for decprec2internal

static LispObject CC_decprec2internal(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11186, v_11187;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11168);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_11186 = v_11168;
// end of prologue
    goto v_11175;
v_11171:
    goto v_11182;
v_11178:
    v_11187 = v_11186;
    goto v_11179;
v_11180:
    v_11186 = qvalue(elt(env, 1)); // !!log2of10
    goto v_11181;
v_11182:
    goto v_11178;
v_11179:
    goto v_11180;
v_11181:
    v_11186 = times2(v_11187, v_11186);
    env = stack[0];
    fn = elt(env, 2); // ceiling
    v_11187 = (*qfn1(fn))(fn, v_11186);
    goto v_11172;
v_11173:
    v_11186 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_11174;
v_11175:
    goto v_11171;
v_11172:
    goto v_11173;
v_11174:
    return plus2(v_11187, v_11186);
}



// Code for setk0

static LispObject CC_setk0(LispObject env,
                         LispObject v_11168, LispObject v_11169)
{
    env = qenv(env);
    LispObject v_11333, v_11334, v_11335, v_11336;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11168,v_11169);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11169;
    stack[-2] = v_11168;
// end of prologue
// Binding frasc!*
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 1, 0);
    qvalue(elt(env, 1)) = nil; // frasc!*
    v_11333 = stack[-1];
    fn = elt(env, 6); // getrtype
    v_11333 = (*qfn1(fn))(fn, v_11333);
    env = stack[-4];
    stack[-3] = v_11333;
    if (v_11333 == nil) goto v_11178;
    goto v_11188;
v_11184:
    v_11334 = stack[-3];
    goto v_11185;
v_11186:
    v_11333 = elt(env, 2); // setelemfn
    goto v_11187;
v_11188:
    goto v_11184;
v_11185:
    goto v_11186;
v_11187:
    v_11333 = get(v_11334, v_11333);
    env = stack[-4];
    if (v_11333 == nil) goto v_11178;
    v_11333 = nil;
    v_11333 = ncons(v_11333);
    env = stack[-4];
    qvalue(elt(env, 3)) = v_11333; // alglist!*
    goto v_11202;
v_11194:
    v_11336 = stack[-2];
    goto v_11195;
v_11196:
    v_11335 = stack[-1];
    goto v_11197;
v_11198:
    v_11334 = nil;
    goto v_11199;
v_11200:
    v_11333 = lisp_true;
    goto v_11201;
v_11202:
    goto v_11194;
v_11195:
    goto v_11196;
v_11197:
    goto v_11198;
v_11199:
    goto v_11200;
v_11201:
    fn = elt(env, 7); // let2
    v_11333 = (*qfnn(fn))(fn, 4, v_11336, v_11335, v_11334, v_11333);
    goto v_11176;
v_11178:
    v_11333 = stack[-2];
    if (!consp(v_11333)) goto v_11212;
    v_11333 = stack[-2];
    v_11333 = qcar(v_11333);
    if (symbolp(v_11333)) goto v_11217;
    v_11333 = nil;
    goto v_11215;
v_11217:
    v_11333 = stack[-2];
    fn = elt(env, 6); // getrtype
    v_11333 = (*qfn1(fn))(fn, v_11333);
    env = stack[-4];
    if (v_11333 == nil) goto v_11232;
    else goto v_11231;
v_11232:
    v_11333 = stack[-2];
    v_11333 = qcar(v_11333);
    if (!symbolp(v_11333)) v_11333 = nil;
    else { v_11333 = qfastgets(v_11333);
           if (v_11333 != nil) { v_11333 = elt(v_11333, 2); // rtype
#ifdef RECORD_GET
             if (v_11333 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_11333 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_11333 == SPID_NOPROP) v_11333 = nil; }}
#endif
v_11231:
    stack[-3] = v_11333;
    if (v_11333 == nil) goto v_11228;
    else goto v_11229;
v_11228:
    v_11333 = nil;
    goto v_11227;
v_11229:
    goto v_11246;
v_11242:
    v_11334 = stack[-3];
    goto v_11243;
v_11244:
    v_11333 = elt(env, 2); // setelemfn
    goto v_11245;
v_11246:
    goto v_11242;
v_11243:
    goto v_11244;
v_11245:
    v_11333 = get(v_11334, v_11333);
    env = stack[-4];
    stack[-3] = v_11333;
    goto v_11227;
    v_11333 = nil;
v_11227:
    if (v_11333 == nil) goto v_11225;
    else goto v_11224;
v_11225:
    goto v_11254;
v_11250:
    v_11333 = stack[-2];
    v_11334 = qcar(v_11333);
    goto v_11251;
v_11252:
    v_11333 = elt(env, 4); // setkfn
    goto v_11253;
v_11254:
    goto v_11250;
v_11251:
    goto v_11252;
v_11253:
    v_11333 = get(v_11334, v_11333);
    env = stack[-4];
    stack[-3] = v_11333;
v_11224:
    goto v_11215;
    v_11333 = nil;
v_11215:
    goto v_11210;
v_11212:
    v_11333 = nil;
    goto v_11210;
    v_11333 = nil;
v_11210:
    if (v_11333 == nil) goto v_11208;
    v_11333 = nil;
    v_11333 = ncons(v_11333);
    env = stack[-4];
    qvalue(elt(env, 3)) = v_11333; // alglist!*
    goto v_11270;
v_11264:
    v_11335 = stack[-3];
    goto v_11265;
v_11266:
    v_11334 = stack[-2];
    goto v_11267;
v_11268:
    v_11333 = stack[-1];
    goto v_11269;
v_11270:
    goto v_11264;
v_11265:
    goto v_11266;
v_11267:
    goto v_11268;
v_11269:
    v_11333 = Lapply2(nil, 3, v_11335, v_11334, v_11333);
    goto v_11176;
v_11208:
    v_11333 = stack[-2];
    if (!consp(v_11333)) goto v_11279;
    v_11333 = stack[-2];
    v_11333 = qcar(v_11333);
    if (!consp(v_11333)) goto v_11284;
    goto v_11292;
v_11288:
    v_11333 = stack[-2];
    v_11333 = qcar(v_11333);
    v_11334 = qcar(v_11333);
    goto v_11289;
v_11290:
    v_11333 = elt(env, 5); // setstructfn
    goto v_11291;
v_11292:
    goto v_11288;
v_11289:
    goto v_11290;
v_11291:
    v_11333 = get(v_11334, v_11333);
    env = stack[-4];
    stack[-3] = v_11333;
    goto v_11282;
v_11284:
    v_11333 = nil;
    goto v_11282;
    v_11333 = nil;
v_11282:
    goto v_11277;
v_11279:
    v_11333 = nil;
    goto v_11277;
    v_11333 = nil;
v_11277:
    if (v_11333 == nil) goto v_11275;
    v_11333 = nil;
    v_11333 = ncons(v_11333);
    env = stack[-4];
    qvalue(elt(env, 3)) = v_11333; // alglist!*
    goto v_11312;
v_11306:
    v_11335 = stack[-3];
    goto v_11307;
v_11308:
    v_11334 = stack[-2];
    goto v_11309;
v_11310:
    v_11333 = stack[-1];
    goto v_11311;
v_11312:
    goto v_11306;
v_11307:
    goto v_11308;
v_11309:
    goto v_11310;
v_11311:
    v_11333 = Lapply2(nil, 3, v_11335, v_11334, v_11333);
    goto v_11176;
v_11275:
    goto v_11327;
v_11319:
    v_11336 = stack[-2];
    goto v_11320;
v_11321:
    v_11335 = stack[-1];
    goto v_11322;
v_11323:
    v_11334 = nil;
    goto v_11324;
v_11325:
    v_11333 = lisp_true;
    goto v_11326;
v_11327:
    goto v_11319;
v_11320:
    goto v_11321;
v_11322:
    goto v_11323;
v_11324:
    goto v_11325;
v_11326:
    fn = elt(env, 7); // let2
    v_11333 = (*qfnn(fn))(fn, 4, v_11336, v_11335, v_11334, v_11333);
    goto v_11176;
v_11176:
    v_11333 = stack[-1];
    ;}  // end of a binding scope
    return onevalue(v_11333);
}



// Code for print_with_margin_sub

static LispObject CC_print_with_margin_sub(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11536, v_11537, v_11538, v_11539;
    LispObject fn;
    LispObject v_11171, v_11170, v_11169, v_11168;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "print_with_margin_sub");
    va_start(aa, nargs);
    v_11168 = va_arg(aa, LispObject);
    v_11169 = va_arg(aa, LispObject);
    v_11170 = va_arg(aa, LispObject);
    v_11171 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_11171,v_11170,v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_11168,v_11169,v_11170,v_11171);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_11171;
    stack[-2] = v_11170;
    stack[-3] = v_11169;
    stack[-4] = v_11168;
// end of prologue
    goto v_11186;
v_11182:
    v_11537 = stack[-2];
    goto v_11183;
v_11184:
    v_11536 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_11185;
v_11186:
    goto v_11182;
v_11183:
    goto v_11184;
v_11185:
    v_11536 = (LispObject)lessp2(v_11537, v_11536);
    v_11536 = v_11536 ? lisp_true : nil;
    env = stack[-6];
    if (v_11536 == nil) goto v_11180;
    v_11536 = (LispObject)160+TAG_FIXNUM; // 10
    stack[-2] = v_11536;
    goto v_11178;
v_11180:
v_11178:
    goto v_11199;
v_11195:
    stack[0] = stack[-3];
    goto v_11196;
v_11197:
    goto v_11206;
v_11202:
    v_11537 = stack[-2];
    goto v_11203;
v_11204:
    v_11536 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_11205;
v_11206:
    goto v_11202;
v_11203:
    goto v_11204;
v_11205:
    v_11536 = difference2(v_11537, v_11536);
    env = stack[-6];
    goto v_11198;
v_11199:
    goto v_11195;
v_11196:
    goto v_11197;
v_11198:
    v_11536 = (LispObject)greaterp2(stack[0], v_11536);
    v_11536 = v_11536 ? lisp_true : nil;
    env = stack[-6];
    if (v_11536 == nil) goto v_11193;
    goto v_11214;
v_11210:
    v_11537 = stack[-2];
    goto v_11211;
v_11212:
    v_11536 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_11213;
v_11214:
    goto v_11210;
v_11211:
    goto v_11212;
v_11213:
    v_11536 = difference2(v_11537, v_11536);
    env = stack[-6];
    stack[-3] = v_11536;
    goto v_11191;
v_11193:
v_11191:
    v_11536 = stack[-4];
    stack[-5] = v_11536;
    v_11536 = stack[-5];
    if (!consp(v_11536)) goto v_11221;
    goto v_11232;
v_11228:
    v_11537 = Lposn(nil, 0);
    env = stack[-6];
    goto v_11229;
v_11230:
    v_11536 = stack[-2];
    goto v_11231;
v_11232:
    goto v_11228;
v_11229:
    goto v_11230;
v_11231:
    v_11536 = (LispObject)geq2(v_11537, v_11536);
    v_11536 = v_11536 ? lisp_true : nil;
    env = stack[-6];
    if (v_11536 == nil) goto v_11226;
    v_11536 = Lterpri(nil, 0);
    env = stack[-6];
    v_11536 = stack[-3];
    v_11536 = Lttab(nil, v_11536);
    env = stack[-6];
    goto v_11224;
v_11226:
v_11224:
    v_11536 = elt(env, 1); // "("
    v_11536 = Lprinc(nil, v_11536);
    env = stack[-6];
    goto v_11249;
v_11241:
    v_11536 = stack[-5];
    v_11539 = qcar(v_11536);
    goto v_11242;
v_11243:
    v_11538 = stack[-3];
    goto v_11244;
v_11245:
    v_11537 = stack[-2];
    goto v_11246;
v_11247:
    v_11536 = stack[-1];
    goto v_11248;
v_11249:
    goto v_11241;
v_11242:
    goto v_11243;
v_11244:
    goto v_11245;
v_11246:
    goto v_11247;
v_11248:
    v_11536 = CC_print_with_margin_sub(elt(env, 0), 4, v_11539, v_11538, v_11537, v_11536);
    env = stack[-6];
v_11257:
    v_11536 = stack[-5];
    v_11536 = qcdr(v_11536);
    stack[-5] = v_11536;
    if (!consp(v_11536)) goto v_11260;
    else goto v_11261;
v_11260:
    goto v_11256;
v_11261:
    goto v_11274;
v_11270:
    v_11537 = Lposn(nil, 0);
    env = stack[-6];
    goto v_11271;
v_11272:
    v_11536 = stack[-2];
    goto v_11273;
v_11274:
    goto v_11270;
v_11271:
    goto v_11272;
v_11273:
    v_11536 = (LispObject)geq2(v_11537, v_11536);
    v_11536 = v_11536 ? lisp_true : nil;
    env = stack[-6];
    if (v_11536 == nil) goto v_11268;
    v_11536 = Lterpri(nil, 0);
    env = stack[-6];
    v_11536 = stack[-3];
    v_11536 = Lttab(nil, v_11536);
    env = stack[-6];
    goto v_11266;
v_11268:
    v_11536 = elt(env, 2); // " "
    v_11536 = Lprinc(nil, v_11536);
    env = stack[-6];
    goto v_11266;
v_11266:
    goto v_11293;
v_11285:
    v_11536 = stack[-5];
    v_11539 = qcar(v_11536);
    goto v_11286;
v_11287:
    v_11538 = stack[-3];
    goto v_11288;
v_11289:
    v_11537 = stack[-2];
    goto v_11290;
v_11291:
    v_11536 = stack[-1];
    goto v_11292;
v_11293:
    goto v_11285;
v_11286:
    goto v_11287;
v_11288:
    goto v_11289;
v_11290:
    goto v_11291;
v_11292:
    v_11536 = CC_print_with_margin_sub(elt(env, 0), 4, v_11539, v_11538, v_11537, v_11536);
    env = stack[-6];
    goto v_11257;
v_11256:
    v_11536 = stack[-5];
    if (v_11536 == nil) goto v_11302;
    goto v_11313;
v_11309:
    stack[0] = Lposn(nil, 0);
    env = stack[-6];
    goto v_11310;
v_11311:
    v_11536 = stack[-2];
    v_11536 = sub1(v_11536);
    env = stack[-6];
    goto v_11312;
v_11313:
    goto v_11309;
v_11310:
    goto v_11311;
v_11312:
    v_11536 = (LispObject)geq2(stack[0], v_11536);
    v_11536 = v_11536 ? lisp_true : nil;
    env = stack[-6];
    if (v_11536 == nil) goto v_11307;
    v_11536 = Lterpri(nil, 0);
    env = stack[-6];
    v_11536 = stack[-3];
    v_11536 = Lttab(nil, v_11536);
    env = stack[-6];
    v_11536 = elt(env, 3); // ". "
    v_11536 = Lprinc(nil, v_11536);
    env = stack[-6];
    goto v_11305;
v_11307:
    v_11536 = elt(env, 4); // " ."
    v_11536 = Lprinc(nil, v_11536);
    env = stack[-6];
    goto v_11305;
v_11305:
    goto v_11335;
v_11327:
    v_11539 = stack[-5];
    goto v_11328;
v_11329:
    v_11538 = stack[-3];
    goto v_11330;
v_11331:
    v_11537 = stack[-2];
    goto v_11332;
v_11333:
    v_11536 = stack[-1];
    goto v_11334;
v_11335:
    goto v_11327;
v_11328:
    goto v_11329;
v_11330:
    goto v_11331;
v_11332:
    goto v_11333;
v_11334:
    v_11536 = CC_print_with_margin_sub(elt(env, 0), 4, v_11539, v_11538, v_11537, v_11536);
    env = stack[-6];
    goto v_11300;
v_11302:
v_11300:
    goto v_11349;
v_11345:
    v_11537 = Lposn(nil, 0);
    env = stack[-6];
    goto v_11346;
v_11347:
    v_11536 = stack[-2];
    goto v_11348;
v_11349:
    goto v_11345;
v_11346:
    goto v_11347;
v_11348:
    v_11536 = (LispObject)geq2(v_11537, v_11536);
    v_11536 = v_11536 ? lisp_true : nil;
    env = stack[-6];
    if (v_11536 == nil) goto v_11343;
    v_11536 = Lterpri(nil, 0);
    env = stack[-6];
    v_11536 = stack[-3];
    v_11536 = Lttab(nil, v_11536);
    env = stack[-6];
    goto v_11341;
v_11343:
v_11341:
    v_11536 = elt(env, 5); // ")"
    v_11536 = Lprinc(nil, v_11536);
    v_11536 = stack[-4];
    goto v_11175;
v_11221:
    goto v_11363;
v_11359:
    stack[0] = stack[-1];
    goto v_11360;
v_11361:
    v_11536 = stack[-4];
    v_11536 = ncons(v_11536);
    env = stack[-6];
    goto v_11362;
v_11363:
    goto v_11359;
v_11360:
    goto v_11361;
v_11362:
    fn = elt(env, 7); // apply
    v_11536 = (*qfn2(fn))(fn, stack[0], v_11536);
    env = stack[-6];
    stack[-5] = v_11536;
v_11176:
    goto v_11376;
v_11372:
    goto v_11382;
v_11378:
    stack[0] = Lposn(nil, 0);
    env = stack[-6];
    goto v_11379;
v_11380:
    v_11536 = stack[-5];
    v_11536 = Llength(nil, v_11536);
    env = stack[-6];
    goto v_11381;
v_11382:
    goto v_11378;
v_11379:
    goto v_11380;
v_11381:
    v_11537 = plus2(stack[0], v_11536);
    env = stack[-6];
    goto v_11373;
v_11374:
    v_11536 = stack[-2];
    goto v_11375;
v_11376:
    goto v_11372;
v_11373:
    goto v_11374;
v_11375:
    v_11536 = (LispObject)lessp2(v_11537, v_11536);
    v_11536 = v_11536 ? lisp_true : nil;
    env = stack[-6];
    if (v_11536 == nil) goto v_11370;
    v_11536 = stack[-5];
    stack[0] = v_11536;
v_11390:
    v_11536 = stack[0];
    if (v_11536 == nil) goto v_11394;
    else goto v_11395;
v_11394:
    goto v_11389;
v_11395:
    v_11536 = stack[0];
    v_11536 = qcar(v_11536);
    v_11536 = Lprinc(nil, v_11536);
    env = stack[-6];
    v_11536 = stack[0];
    v_11536 = qcdr(v_11536);
    stack[0] = v_11536;
    goto v_11390;
v_11389:
    v_11536 = stack[-4];
    goto v_11175;
v_11370:
    goto v_11413;
v_11409:
    v_11536 = stack[-5];
    stack[0] = Llength(nil, v_11536);
    env = stack[-6];
    goto v_11410;
v_11411:
    goto v_11421;
v_11417:
    v_11537 = stack[-2];
    goto v_11418;
v_11419:
    v_11536 = stack[-3];
    goto v_11420;
v_11421:
    goto v_11417;
v_11418:
    goto v_11419;
v_11420:
    v_11536 = difference2(v_11537, v_11536);
    env = stack[-6];
    goto v_11412;
v_11413:
    goto v_11409;
v_11410:
    goto v_11411;
v_11412:
    v_11536 = (LispObject)lesseq2(stack[0], v_11536);
    v_11536 = v_11536 ? lisp_true : nil;
    env = stack[-6];
    if (v_11536 == nil) goto v_11407;
    v_11536 = Lterpri(nil, 0);
    env = stack[-6];
    v_11536 = stack[-3];
    v_11536 = Lttab(nil, v_11536);
    env = stack[-6];
    v_11536 = stack[-5];
    stack[0] = v_11536;
v_11430:
    v_11536 = stack[0];
    if (v_11536 == nil) goto v_11434;
    else goto v_11435;
v_11434:
    goto v_11429;
v_11435:
    v_11536 = stack[0];
    v_11536 = qcar(v_11536);
    v_11536 = Lprinc(nil, v_11536);
    env = stack[-6];
    v_11536 = stack[0];
    v_11536 = qcdr(v_11536);
    stack[0] = v_11536;
    goto v_11430;
v_11429:
    v_11536 = stack[-4];
    goto v_11175;
v_11407:
    goto v_11453;
v_11449:
    v_11536 = stack[-5];
    v_11537 = Llength(nil, v_11536);
    env = stack[-6];
    goto v_11450;
v_11451:
    v_11536 = stack[-2];
    goto v_11452;
v_11453:
    goto v_11449;
v_11450:
    goto v_11451;
v_11452:
    v_11536 = (LispObject)lessp2(v_11537, v_11536);
    v_11536 = v_11536 ? lisp_true : nil;
    env = stack[-6];
    if (v_11536 == nil) goto v_11447;
    v_11536 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_11464;
v_11460:
    stack[0] = stack[-2];
    goto v_11461;
v_11462:
    v_11536 = stack[-5];
    v_11536 = Llength(nil, v_11536);
    env = stack[-6];
    goto v_11463;
v_11464:
    goto v_11460;
v_11461:
    goto v_11462;
v_11463:
    v_11536 = difference2(stack[0], v_11536);
    env = stack[-6];
    v_11536 = Lttab(nil, v_11536);
    env = stack[-6];
    v_11536 = stack[-5];
    stack[0] = v_11536;
v_11471:
    v_11536 = stack[0];
    if (v_11536 == nil) goto v_11475;
    else goto v_11476;
v_11475:
    goto v_11470;
v_11476:
    v_11536 = stack[0];
    v_11536 = qcar(v_11536);
    v_11536 = Lprinc(nil, v_11536);
    env = stack[-6];
    v_11536 = stack[0];
    v_11536 = qcdr(v_11536);
    stack[0] = v_11536;
    goto v_11471;
v_11470:
    v_11536 = stack[-4];
    goto v_11175;
v_11447:
    goto v_11498;
v_11494:
    stack[0] = Lposn(nil, 0);
    env = stack[-6];
    goto v_11495;
v_11496:
    goto v_11505;
v_11501:
    v_11537 = stack[-2];
    goto v_11502;
v_11503:
    v_11536 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_11504;
v_11505:
    goto v_11501;
v_11502:
    goto v_11503;
v_11504:
    v_11536 = difference2(v_11537, v_11536);
    env = stack[-6];
    goto v_11497;
v_11498:
    goto v_11494;
v_11495:
    goto v_11496;
v_11497:
    v_11536 = (LispObject)geq2(stack[0], v_11536);
    v_11536 = v_11536 ? lisp_true : nil;
    env = stack[-6];
    if (v_11536 == nil) goto v_11492;
    v_11536 = Lterpri(nil, 0);
    env = stack[-6];
    v_11536 = stack[-3];
    v_11536 = Lttab(nil, v_11536);
    env = stack[-6];
    goto v_11490;
v_11492:
v_11490:
v_11513:
    goto v_11523;
v_11519:
    stack[0] = Lposn(nil, 0);
    env = stack[-6];
    goto v_11520;
v_11521:
    v_11536 = stack[-2];
    v_11536 = sub1(v_11536);
    env = stack[-6];
    goto v_11522;
v_11523:
    goto v_11519;
v_11520:
    goto v_11521;
v_11522:
    v_11536 = (LispObject)lessp2(stack[0], v_11536);
    v_11536 = v_11536 ? lisp_true : nil;
    env = stack[-6];
    if (v_11536 == nil) goto v_11516;
    else goto v_11517;
v_11516:
    goto v_11512;
v_11517:
    v_11536 = stack[-5];
    v_11536 = qcar(v_11536);
    v_11536 = Lprinc(nil, v_11536);
    env = stack[-6];
    v_11536 = stack[-5];
    v_11536 = qcdr(v_11536);
    stack[-5] = v_11536;
    goto v_11513;
v_11512:
    v_11536 = elt(env, 6); // "\"
    v_11536 = Lprinc(nil, v_11536);
    env = stack[-6];
    v_11536 = Lterpri(nil, 0);
    env = stack[-6];
    goto v_11176;
    v_11536 = nil;
v_11175:
    return onevalue(v_11536);
}



// Code for make_tuple_type

static LispObject CC_make_tuple_type(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11194, v_11195;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11168);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_11195 = v_11168;
// end of prologue
    v_11194 = v_11195;
    if (v_11194 == nil) goto v_11172;
    else goto v_11173;
v_11172:
    v_11194 = elt(env, 1); // unit
    goto v_11171;
v_11173:
    v_11194 = v_11195;
    v_11194 = qcdr(v_11194);
    if (v_11194 == nil) goto v_11176;
    else goto v_11177;
v_11176:
    v_11194 = v_11195;
    v_11194 = qcar(v_11194);
    v_11194 = qcdr(v_11194);
    goto v_11171;
v_11177:
    goto v_11190;
v_11186:
    stack[0] = elt(env, 2); // times
    goto v_11187;
v_11188:
    v_11194 = v_11195;
    fn = elt(env, 3); // collect_cdrs
    v_11194 = (*qfn1(fn))(fn, v_11194);
    goto v_11189;
v_11190:
    goto v_11186;
v_11187:
    goto v_11188;
v_11189:
    {
        LispObject v_11197 = stack[0];
        return cons(v_11197, v_11194);
    }
    v_11194 = nil;
v_11171:
    return onevalue(v_11194);
}



// Code for subsublis

static LispObject CC_subsublis(LispObject env,
                         LispObject v_11168, LispObject v_11169)
{
    env = qenv(env);
    LispObject v_11395, v_11396, v_11397;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11168,v_11169);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_11169;
    stack[-3] = v_11168;
// end of prologue
v_11167:
    goto v_11182;
v_11178:
    v_11396 = stack[0];
    goto v_11179;
v_11180:
    v_11395 = stack[-3];
    goto v_11181;
v_11182:
    goto v_11178;
v_11179:
    goto v_11180;
v_11181:
    v_11395 = Lassoc(nil, v_11396, v_11395);
    v_11397 = v_11395;
    if (v_11395 == nil) goto v_11177;
    v_11395 = v_11397;
    v_11395 = qcdr(v_11395);
    goto v_11175;
v_11177:
    goto v_11199;
v_11195:
    v_11396 = stack[0];
    goto v_11196;
v_11197:
    v_11395 = elt(env, 1); // sqrt
    goto v_11198;
v_11199:
    goto v_11195;
v_11196:
    goto v_11197;
v_11198:
    if (!consp(v_11396)) goto v_11193;
    v_11396 = qcar(v_11396);
    if (v_11396 == v_11395) goto v_11192;
    else goto v_11193;
v_11192:
    goto v_11206;
v_11202:
    goto v_11214;
v_11208:
    v_11397 = elt(env, 2); // expt
    goto v_11209;
v_11210:
    v_11395 = stack[0];
    v_11395 = qcdr(v_11395);
    v_11396 = qcar(v_11395);
    goto v_11211;
v_11212:
    v_11395 = elt(env, 3); // (quotient 1 2)
    goto v_11213;
v_11214:
    goto v_11208;
v_11209:
    goto v_11210;
v_11211:
    goto v_11212;
v_11213:
    v_11396 = list3(v_11397, v_11396, v_11395);
    env = stack[-5];
    goto v_11203;
v_11204:
    v_11395 = stack[-3];
    goto v_11205;
v_11206:
    goto v_11202;
v_11203:
    goto v_11204;
v_11205:
    v_11395 = Lassoc(nil, v_11396, v_11395);
    v_11397 = v_11395;
    goto v_11191;
v_11193:
    v_11395 = nil;
    goto v_11191;
    v_11395 = nil;
v_11191:
    if (v_11395 == nil) goto v_11189;
    v_11395 = v_11397;
    v_11395 = qcdr(v_11395);
    goto v_11175;
v_11189:
    v_11395 = stack[0];
    if (!consp(v_11395)) goto v_11227;
    else goto v_11228;
v_11227:
    v_11395 = stack[0];
    goto v_11175;
v_11228:
    v_11395 = stack[0];
    v_11395 = qcar(v_11395);
    if (symbolp(v_11395)) goto v_11232;
    v_11395 = stack[0];
    stack[-4] = v_11395;
    v_11395 = stack[-4];
    if (v_11395 == nil) goto v_11244;
    else goto v_11245;
v_11244:
    v_11395 = nil;
    goto v_11239;
v_11245:
    v_11395 = stack[-4];
    v_11395 = qcar(v_11395);
    goto v_11257;
v_11253:
    v_11396 = stack[-3];
    goto v_11254;
v_11255:
    goto v_11256;
v_11257:
    goto v_11253;
v_11254:
    goto v_11255;
v_11256:
    v_11395 = CC_subsublis(elt(env, 0), v_11396, v_11395);
    env = stack[-5];
    v_11395 = ncons(v_11395);
    env = stack[-5];
    stack[-1] = v_11395;
    stack[-2] = v_11395;
v_11240:
    v_11395 = stack[-4];
    v_11395 = qcdr(v_11395);
    stack[-4] = v_11395;
    v_11395 = stack[-4];
    if (v_11395 == nil) goto v_11264;
    else goto v_11265;
v_11264:
    v_11395 = stack[-2];
    goto v_11239;
v_11265:
    goto v_11273;
v_11269:
    stack[0] = stack[-1];
    goto v_11270;
v_11271:
    v_11395 = stack[-4];
    v_11395 = qcar(v_11395);
    goto v_11284;
v_11280:
    v_11396 = stack[-3];
    goto v_11281;
v_11282:
    goto v_11283;
v_11284:
    goto v_11280;
v_11281:
    goto v_11282;
v_11283:
    v_11395 = CC_subsublis(elt(env, 0), v_11396, v_11395);
    env = stack[-5];
    v_11395 = ncons(v_11395);
    env = stack[-5];
    goto v_11272;
v_11273:
    goto v_11269;
v_11270:
    goto v_11271;
v_11272:
    v_11395 = Lrplacd(nil, stack[0], v_11395);
    env = stack[-5];
    v_11395 = stack[-1];
    v_11395 = qcdr(v_11395);
    stack[-1] = v_11395;
    goto v_11240;
v_11239:
    goto v_11175;
v_11232:
    goto v_11296;
v_11292:
    v_11395 = stack[0];
    v_11396 = qcar(v_11395);
    goto v_11293;
v_11294:
    v_11395 = elt(env, 4); // subfunc
    goto v_11295;
v_11296:
    goto v_11292;
v_11293:
    goto v_11294;
v_11295:
    v_11395 = get(v_11396, v_11395);
    env = stack[-5];
    v_11397 = v_11395;
    if (v_11395 == nil) goto v_11290;
    goto v_11307;
v_11301:
    goto v_11302;
v_11303:
    v_11396 = stack[-3];
    goto v_11304;
v_11305:
    v_11395 = stack[0];
    goto v_11306;
v_11307:
    goto v_11301;
v_11302:
    goto v_11303;
v_11304:
    goto v_11305;
v_11306:
        return Lapply2(nil, 3, v_11397, v_11396, v_11395);
v_11290:
    v_11395 = stack[0];
    v_11395 = qcar(v_11395);
    if (!symbolp(v_11395)) v_11395 = nil;
    else { v_11395 = qfastgets(v_11395);
           if (v_11395 != nil) { v_11395 = elt(v_11395, 8); // dname
#ifdef RECORD_GET
             if (v_11395 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_11395 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_11395 == SPID_NOPROP) v_11395 = nil; }}
#endif
    if (v_11395 == nil) goto v_11312;
    v_11395 = stack[0];
    goto v_11175;
v_11312:
    goto v_11323;
v_11319:
    v_11395 = stack[0];
    v_11396 = qcar(v_11395);
    goto v_11320;
v_11321:
    v_11395 = elt(env, 5); // !*sq
    goto v_11322;
v_11323:
    goto v_11319;
v_11320:
    goto v_11321;
v_11322:
    if (v_11396 == v_11395) goto v_11317;
    else goto v_11318;
v_11317:
    goto v_11332;
v_11328:
    stack[-1] = stack[-3];
    goto v_11329;
v_11330:
    v_11395 = stack[0];
    v_11395 = qcdr(v_11395);
    v_11395 = qcar(v_11395);
    fn = elt(env, 6); // prepsq
    v_11395 = (*qfn1(fn))(fn, v_11395);
    env = stack[-5];
    goto v_11331;
v_11332:
    goto v_11328;
v_11329:
    goto v_11330;
v_11331:
    stack[-3] = stack[-1];
    stack[0] = v_11395;
    goto v_11167;
v_11318:
    v_11395 = stack[0];
    stack[-4] = v_11395;
    v_11395 = stack[-4];
    if (v_11395 == nil) goto v_11349;
    else goto v_11350;
v_11349:
    v_11395 = nil;
    goto v_11344;
v_11350:
    v_11395 = stack[-4];
    v_11395 = qcar(v_11395);
    goto v_11362;
v_11358:
    v_11396 = stack[-3];
    goto v_11359;
v_11360:
    goto v_11361;
v_11362:
    goto v_11358;
v_11359:
    goto v_11360;
v_11361:
    v_11395 = CC_subsublis(elt(env, 0), v_11396, v_11395);
    env = stack[-5];
    v_11395 = ncons(v_11395);
    env = stack[-5];
    stack[-1] = v_11395;
    stack[-2] = v_11395;
v_11345:
    v_11395 = stack[-4];
    v_11395 = qcdr(v_11395);
    stack[-4] = v_11395;
    v_11395 = stack[-4];
    if (v_11395 == nil) goto v_11369;
    else goto v_11370;
v_11369:
    v_11395 = stack[-2];
    goto v_11344;
v_11370:
    goto v_11378;
v_11374:
    stack[0] = stack[-1];
    goto v_11375;
v_11376:
    v_11395 = stack[-4];
    v_11395 = qcar(v_11395);
    goto v_11389;
v_11385:
    v_11396 = stack[-3];
    goto v_11386;
v_11387:
    goto v_11388;
v_11389:
    goto v_11385;
v_11386:
    goto v_11387;
v_11388:
    v_11395 = CC_subsublis(elt(env, 0), v_11396, v_11395);
    env = stack[-5];
    v_11395 = ncons(v_11395);
    env = stack[-5];
    goto v_11377;
v_11378:
    goto v_11374;
v_11375:
    goto v_11376;
v_11377:
    v_11395 = Lrplacd(nil, stack[0], v_11395);
    env = stack[-5];
    v_11395 = stack[-1];
    v_11395 = qcdr(v_11395);
    stack[-1] = v_11395;
    goto v_11345;
v_11344:
    goto v_11175;
    v_11395 = nil;
v_11175:
    v_11397 = v_11395;
    v_11395 = v_11397;
    return onevalue(v_11395);
}



// Code for ibalp_var!-unsatlist

static LispObject CC_ibalp_varKunsatlist(LispObject env,
                         LispObject v_11168, LispObject v_11169)
{
    env = qenv(env);
    LispObject v_11231, v_11232;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11168,v_11169);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_11169;
    v_11231 = v_11168;
// end of prologue
    stack[-3] = v_11231;
v_11174:
    v_11231 = stack[-3];
    if (v_11231 == nil) goto v_11178;
    else goto v_11179;
v_11178:
    v_11231 = nil;
    goto v_11173;
v_11179:
    v_11231 = stack[-3];
    v_11231 = qcar(v_11231);
    stack[-1] = v_11231;
    goto v_11194;
v_11190:
    v_11232 = stack[-2];
    goto v_11191;
v_11192:
    v_11231 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11193;
v_11194:
    goto v_11190;
v_11191:
    goto v_11192;
v_11193:
    v_11231 = Leqn(nil, v_11232, v_11231);
    env = stack[-4];
    if (v_11231 == nil) goto v_11188;
    goto v_11202;
v_11198:
    v_11231 = stack[-1];
    v_11231 = qcdr(v_11231);
    v_11231 = qcdr(v_11231);
    stack[0] = qcdr(v_11231);
    goto v_11199;
v_11200:
    v_11231 = stack[-1];
    v_11231 = qcdr(v_11231);
    v_11231 = qcdr(v_11231);
    v_11231 = qcdr(v_11231);
    v_11231 = qcar(v_11231);
    v_11231 = sub1(v_11231);
    env = stack[-4];
    goto v_11201;
v_11202:
    goto v_11198;
v_11199:
    goto v_11200;
v_11201:
    fn = elt(env, 1); // setcar
    v_11231 = (*qfn2(fn))(fn, stack[0], v_11231);
    env = stack[-4];
    goto v_11186;
v_11188:
    goto v_11220;
v_11216:
    v_11231 = stack[-1];
    v_11231 = qcdr(v_11231);
    stack[0] = qcdr(v_11231);
    goto v_11217;
v_11218:
    v_11231 = stack[-1];
    v_11231 = qcdr(v_11231);
    v_11231 = qcdr(v_11231);
    v_11231 = qcar(v_11231);
    v_11231 = sub1(v_11231);
    env = stack[-4];
    goto v_11219;
v_11220:
    goto v_11216;
v_11217:
    goto v_11218;
v_11219:
    fn = elt(env, 1); // setcar
    v_11231 = (*qfn2(fn))(fn, stack[0], v_11231);
    env = stack[-4];
    goto v_11186;
v_11186:
    v_11231 = stack[-3];
    v_11231 = qcdr(v_11231);
    stack[-3] = v_11231;
    goto v_11174;
v_11173:
    return onevalue(v_11231);
}



// Code for dvfsf_susitf

static LispObject CC_dvfsf_susitf(LispObject env,
                         LispObject v_11168, LispObject v_11169)
{
    env = qenv(env);
    LispObject v_11172, v_11173;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11172 = v_11169;
    v_11173 = v_11168;
// end of prologue
    v_11172 = v_11173;
    return onevalue(v_11172);
}



// Code for applyrd

static LispObject CC_applyrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11235, v_11236;
    LispObject fn;
    argcheck(nargs, 0, "applyrd");
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
    fn = elt(env, 6); // lex
    v_11235 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_11179;
v_11175:
    v_11236 = qvalue(elt(env, 1)); // atts
    goto v_11176;
v_11177:
    v_11235 = elt(env, 2); // (type definitionurl encoding)
    goto v_11178;
v_11179:
    goto v_11175;
v_11176:
    goto v_11177;
v_11178:
    fn = elt(env, 7); // retattributes
    v_11235 = (*qfn2(fn))(fn, v_11236, v_11235);
    env = stack[-1];
    qvalue(elt(env, 3)) = v_11235; // mmlatts
    goto v_11190;
v_11186:
    v_11235 = qvalue(elt(env, 4)); // char
    fn = elt(env, 8); // compress!*
    v_11236 = (*qfn1(fn))(fn, v_11235);
    env = stack[-1];
    goto v_11187;
v_11188:
    v_11235 = qvalue(elt(env, 5)); // functions!*
    goto v_11189;
v_11190:
    goto v_11186;
v_11187:
    goto v_11188;
v_11189:
    v_11235 = Lassoc(nil, v_11236, v_11235);
    stack[0] = v_11235;
    if (v_11235 == nil) goto v_11185;
    goto v_11200;
v_11196:
    v_11235 = stack[0];
    v_11235 = qcdr(v_11235);
    v_11236 = qcar(v_11235);
    goto v_11197;
v_11198:
    v_11235 = nil;
    goto v_11199;
v_11200:
    goto v_11196;
v_11197:
    goto v_11198;
v_11199:
    fn = elt(env, 9); // apply
    v_11235 = (*qfn2(fn))(fn, v_11236, v_11235);
    env = stack[-1];
    v_11236 = v_11235;
    goto v_11210;
v_11206:
    v_11235 = qvalue(elt(env, 3)); // mmlatts
    goto v_11207;
v_11208:
    goto v_11209;
v_11210:
    goto v_11206;
v_11207:
    goto v_11208;
v_11209:
    v_11235 = cons(v_11235, v_11236);
    env = stack[-1];
    v_11236 = v_11235;
    v_11235 = nil;
    qvalue(elt(env, 3)) = v_11235; // mmlatts
    goto v_11219;
v_11215:
    v_11235 = stack[0];
    v_11235 = qcdr(v_11235);
    v_11235 = qcdr(v_11235);
    v_11235 = qcar(v_11235);
    goto v_11216;
v_11217:
    goto v_11218;
v_11219:
    goto v_11215;
v_11216:
    goto v_11217;
v_11218:
    return cons(v_11235, v_11236);
v_11185:
    goto v_11231;
v_11227:
    v_11235 = qvalue(elt(env, 4)); // char
    v_11236 = Lcompress(nil, v_11235);
    env = stack[-1];
    goto v_11228;
v_11229:
    v_11235 = (LispObject)272+TAG_FIXNUM; // 17
    goto v_11230;
v_11231:
    goto v_11227;
v_11228:
    goto v_11229;
v_11230:
    fn = elt(env, 10); // errorml
    v_11235 = (*qfn2(fn))(fn, v_11236, v_11235);
    v_11235 = nil;
    return onevalue(v_11235);
}



// Code for ps!:minusp!:

static LispObject CC_psTminuspT(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11171;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11171 = v_11168;
// end of prologue
    v_11171 = nil;
    return onevalue(v_11171);
}



// Code for arg2of2

static LispObject CC_arg2of2(LispObject env,
                         LispObject v_11168, LispObject v_11169)
{
    env = qenv(env);
    LispObject v_11172, v_11173;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11172 = v_11169;
    v_11173 = v_11168;
// end of prologue
    return onevalue(v_11172);
}



// Code for cut!:mt

static LispObject CC_cutTmt(LispObject env,
                         LispObject v_11168, LispObject v_11169)
{
    env = qenv(env);
    LispObject v_11278, v_11279;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11168,v_11169);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11169;
    stack[-2] = v_11168;
// end of prologue
    goto v_11188;
v_11184:
    v_11279 = stack[-2];
    goto v_11185;
v_11186:
    v_11278 = elt(env, 1); // !:rd!:
    goto v_11187;
v_11188:
    goto v_11184;
v_11185:
    goto v_11186;
v_11187:
    if (!consp(v_11279)) goto v_11182;
    v_11279 = qcar(v_11279);
    if (v_11279 == v_11278) goto v_11181;
    else goto v_11182;
v_11181:
    v_11278 = stack[-2];
    v_11278 = qcdr(v_11278);
    v_11278 = (consp(v_11278) ? nil : lisp_true);
    v_11278 = (v_11278 == nil ? lisp_true : nil);
    goto v_11180;
v_11182:
    v_11278 = nil;
    goto v_11180;
    v_11278 = nil;
v_11180:
    if (v_11278 == nil) goto v_11178;
    v_11278 = stack[-1];
    v_11278 = integerp(v_11278);
    if (v_11278 == nil) goto v_11200;
    else goto v_11201;
v_11200:
    v_11278 = nil;
    goto v_11199;
v_11201:
    goto v_11212;
v_11208:
    v_11279 = stack[-1];
    goto v_11209;
v_11210:
    v_11278 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11211;
v_11212:
    goto v_11208;
v_11209:
    goto v_11210;
v_11211:
    v_11278 = (LispObject)greaterp2(v_11279, v_11278);
    v_11278 = v_11278 ? lisp_true : nil;
    env = stack[-4];
    goto v_11199;
    v_11278 = nil;
v_11199:
    goto v_11176;
v_11178:
    v_11278 = nil;
    goto v_11176;
    v_11278 = nil;
v_11176:
    if (v_11278 == nil) goto v_11174;
    goto v_11227;
v_11223:
    goto v_11233;
v_11229:
    v_11278 = stack[-2];
    v_11278 = qcdr(v_11278);
    v_11278 = qcar(v_11278);
    v_11278 = Labsval(nil, v_11278);
    env = stack[-4];
    fn = elt(env, 2); // msd
    v_11279 = (*qfn1(fn))(fn, v_11278);
    env = stack[-4];
    goto v_11230;
v_11231:
    v_11278 = stack[-1];
    goto v_11232;
v_11233:
    goto v_11229;
v_11230:
    goto v_11231;
v_11232:
    v_11279 = difference2(v_11279, v_11278);
    env = stack[-4];
    stack[-1] = v_11279;
    goto v_11224;
v_11225:
    v_11278 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11226;
v_11227:
    goto v_11223;
v_11224:
    goto v_11225;
v_11226:
    v_11278 = (LispObject)lesseq2(v_11279, v_11278);
    v_11278 = v_11278 ? lisp_true : nil;
    env = stack[-4];
    if (v_11278 == nil) goto v_11221;
    v_11278 = stack[-2];
    goto v_11219;
v_11221:
    goto v_11251;
v_11245:
    stack[-3] = elt(env, 1); // !:rd!:
    goto v_11246;
v_11247:
    goto v_11258;
v_11254:
    v_11278 = stack[-2];
    v_11278 = qcdr(v_11278);
    stack[0] = qcar(v_11278);
    goto v_11255;
v_11256:
    v_11278 = stack[-1];
    v_11278 = negate(v_11278);
    env = stack[-4];
    goto v_11257;
v_11258:
    goto v_11254;
v_11255:
    goto v_11256;
v_11257:
    fn = elt(env, 3); // ashift
    stack[0] = (*qfn2(fn))(fn, stack[0], v_11278);
    env = stack[-4];
    goto v_11248;
v_11249:
    goto v_11269;
v_11265:
    v_11278 = stack[-2];
    v_11278 = qcdr(v_11278);
    v_11279 = qcdr(v_11278);
    goto v_11266;
v_11267:
    v_11278 = stack[-1];
    goto v_11268;
v_11269:
    goto v_11265;
v_11266:
    goto v_11267;
v_11268:
    v_11278 = plus2(v_11279, v_11278);
    goto v_11250;
v_11251:
    goto v_11245;
v_11246:
    goto v_11247;
v_11248:
    goto v_11249;
v_11250:
    {
        LispObject v_11284 = stack[-3];
        LispObject v_11285 = stack[0];
        return list2star(v_11284, v_11285, v_11278);
    }
    v_11278 = nil;
v_11219:
    goto v_11172;
v_11174:
    v_11278 = elt(env, 0); // cut!:mt
    {
        fn = elt(env, 4); // bflerrmsg
        return (*qfn1(fn))(fn, v_11278);
    }
    v_11278 = nil;
v_11172:
    return onevalue(v_11278);
}



// Code for lispassignp

static LispObject CC_lispassignp(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11178, v_11179;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11178 = v_11168;
// end of prologue
    goto v_11175;
v_11171:
    goto v_11172;
v_11173:
    v_11179 = elt(env, 1); // setq
    goto v_11174;
v_11175:
    goto v_11171;
v_11172:
    goto v_11173;
v_11174:
        return Leqcar(nil, v_11178, v_11179);
}



// Code for contr2!-strand

static LispObject CC_contr2Kstrand(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11285, v_11286, v_11287, v_11288;
    LispObject fn;
    LispObject v_11171, v_11170, v_11169, v_11168;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "contr2-strand");
    va_start(aa, nargs);
    v_11168 = va_arg(aa, LispObject);
    v_11169 = va_arg(aa, LispObject);
    v_11170 = va_arg(aa, LispObject);
    v_11171 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_11171,v_11170,v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_11168,v_11169,v_11170,v_11171);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_11171;
    stack[-1] = v_11170;
    stack[-2] = v_11169;
    stack[-3] = v_11168;
// end of prologue
v_11167:
    v_11285 = stack[-3];
    if (v_11285 == nil) goto v_11175;
    else goto v_11176;
v_11175:
    v_11285 = stack[-1];
    goto v_11174;
v_11176:
    goto v_11186;
v_11182:
    v_11285 = stack[-3];
    v_11286 = qcar(v_11285);
    goto v_11183;
v_11184:
    v_11285 = stack[-2];
    goto v_11185;
v_11186:
    goto v_11182;
v_11183:
    goto v_11184;
v_11185:
    fn = elt(env, 1); // contrsp
    v_11285 = (*qfn2(fn))(fn, v_11286, v_11285);
    env = stack[-4];
    v_11287 = v_11285;
    v_11285 = v_11287;
    if (v_11285 == nil) goto v_11194;
    goto v_11204;
v_11200:
    v_11285 = v_11287;
    v_11286 = qcar(v_11285);
    goto v_11201;
v_11202:
    v_11285 = v_11287;
    v_11285 = qcdr(v_11285);
    goto v_11203;
v_11204:
    goto v_11200;
v_11201:
    goto v_11202;
v_11203:
    v_11285 = Lmember(nil, v_11286, v_11285);
    if (v_11285 == nil) goto v_11199;
    goto v_11215;
v_11211:
    v_11286 = stack[-3];
    goto v_11212;
v_11213:
    v_11285 = stack[-1];
    goto v_11214;
v_11215:
    goto v_11211;
v_11212:
    goto v_11213;
v_11214:
        return Lappend(nil, v_11286, v_11285);
v_11199:
    v_11285 = stack[0];
    if (v_11285 == nil) goto v_11218;
    else goto v_11219;
v_11218:
    goto v_11230;
v_11222:
    goto v_11238;
v_11232:
    goto v_11233;
v_11234:
    v_11285 = stack[-3];
    v_11286 = qcdr(v_11285);
    goto v_11235;
v_11236:
    v_11285 = stack[-1];
    goto v_11237;
v_11238:
    goto v_11232;
v_11233:
    goto v_11234;
v_11235:
    goto v_11236;
v_11237:
    fn = elt(env, 2); // contr2
    v_11288 = (*qfnn(fn))(fn, 3, v_11287, v_11286, v_11285);
    env = stack[-4];
    goto v_11223;
v_11224:
    v_11287 = stack[-2];
    goto v_11225;
v_11226:
    v_11286 = nil;
    goto v_11227;
v_11228:
    v_11285 = lisp_true;
    goto v_11229;
v_11230:
    goto v_11222;
v_11223:
    goto v_11224;
v_11225:
    goto v_11226;
v_11227:
    goto v_11228;
v_11229:
    stack[-3] = v_11288;
    stack[-2] = v_11287;
    stack[-1] = v_11286;
    stack[0] = v_11285;
    goto v_11167;
v_11219:
    goto v_11255;
v_11249:
    goto v_11250;
v_11251:
    v_11285 = stack[-3];
    v_11286 = qcdr(v_11285);
    goto v_11252;
v_11253:
    v_11285 = stack[-1];
    goto v_11254;
v_11255:
    goto v_11249;
v_11250:
    goto v_11251;
v_11252:
    goto v_11253;
v_11254:
    {
        fn = elt(env, 2); // contr2
        return (*qfnn(fn))(fn, 3, v_11287, v_11286, v_11285);
    }
    v_11285 = nil;
    goto v_11192;
v_11194:
    goto v_11271;
v_11263:
    v_11285 = stack[-3];
    stack[0] = qcdr(v_11285);
    goto v_11264;
v_11265:
    goto v_11266;
v_11267:
    goto v_11280;
v_11276:
    v_11285 = stack[-3];
    v_11286 = qcar(v_11285);
    goto v_11277;
v_11278:
    v_11285 = stack[-1];
    goto v_11279;
v_11280:
    goto v_11276;
v_11277:
    goto v_11278;
v_11279:
    v_11286 = cons(v_11286, v_11285);
    env = stack[-4];
    goto v_11268;
v_11269:
    v_11285 = nil;
    goto v_11270;
v_11271:
    goto v_11263;
v_11264:
    goto v_11265;
v_11266:
    goto v_11267;
v_11268:
    goto v_11269;
v_11270:
    stack[-3] = stack[0];
    stack[-1] = v_11286;
    stack[0] = v_11285;
    goto v_11167;
    v_11285 = nil;
v_11192:
    goto v_11174;
    v_11285 = nil;
v_11174:
    return onevalue(v_11285);
}



// Code for lpriw

static LispObject CC_lpriw(LispObject env,
                         LispObject v_11168, LispObject v_11169)
{
    env = qenv(env);
    LispObject v_11232, v_11233;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11168,v_11169);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_11233 = v_11169;
    stack[0] = v_11168;
// end of prologue
    goto v_11178;
v_11174:
    goto v_11175;
v_11176:
    v_11232 = v_11233;
    if (v_11232 == nil) goto v_11183;
    v_11232 = v_11233;
    if (!consp(v_11232)) goto v_11186;
    else goto v_11183;
v_11186:
    v_11232 = v_11233;
    v_11232 = ncons(v_11232);
    env = stack[-1];
    goto v_11181;
v_11183:
    v_11232 = v_11233;
    goto v_11181;
    v_11232 = nil;
v_11181:
    goto v_11177;
v_11178:
    goto v_11174;
v_11175:
    goto v_11176;
v_11177:
    v_11232 = cons(stack[0], v_11232);
    env = stack[-1];
    stack[0] = v_11232;
    v_11232 = qvalue(elt(env, 1)); // ofl!*
    if (v_11232 == nil) goto v_11195;
    else goto v_11196;
v_11195:
    v_11232 = Lterpri(nil, 0);
    env = stack[-1];
    v_11232 = stack[0];
    fn = elt(env, 5); // lpri
    v_11232 = (*qfn1(fn))(fn, v_11232);
    env = stack[-1];
    v_11232 = Lterpri(nil, 0);
    goto v_11194;
v_11196:
    v_11232 = qvalue(elt(env, 2)); // !*fort
    if (v_11232 == nil) goto v_11208;
    else goto v_11207;
v_11208:
    v_11232 = qvalue(elt(env, 3)); // !*nat
    if (v_11232 == nil) goto v_11213;
    else goto v_11214;
v_11213:
    v_11232 = lisp_true;
    goto v_11212;
v_11214:
    v_11232 = qvalue(elt(env, 4)); // !*defn
    goto v_11212;
    v_11232 = nil;
v_11212:
    if (v_11232 == nil) goto v_11210;
    else goto v_11207;
v_11210:
    v_11232 = Lterpri(nil, 0);
    env = stack[-1];
    v_11232 = stack[0];
    fn = elt(env, 5); // lpri
    v_11232 = (*qfn1(fn))(fn, v_11232);
    env = stack[-1];
    v_11232 = Lterpri(nil, 0);
    env = stack[-1];
    goto v_11205;
v_11207:
v_11205:
    v_11232 = nil;
    v_11232 = Lwrs(nil, v_11232);
    env = stack[-1];
    v_11232 = stack[0];
    fn = elt(env, 5); // lpri
    v_11232 = (*qfn1(fn))(fn, v_11232);
    env = stack[-1];
    v_11232 = Lterpri(nil, 0);
    env = stack[-1];
    v_11232 = qvalue(elt(env, 1)); // ofl!*
    v_11232 = qcdr(v_11232);
    v_11232 = Lwrs(nil, v_11232);
    goto v_11194;
v_11194:
    v_11232 = nil;
    return onevalue(v_11232);
}



// Code for rnminusp!:

static LispObject CC_rnminuspT(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11197, v_11198;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11197 = v_11168;
// end of prologue
    v_11197 = qcdr(v_11197);
    v_11198 = qcar(v_11197);
    v_11197 = v_11198;
    if (!consp(v_11198)) goto v_11172;
    else goto v_11173;
v_11172:
    goto v_11182;
v_11178:
    v_11198 = v_11197;
    goto v_11179;
v_11180:
    v_11197 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11181;
v_11182:
    goto v_11178;
v_11179:
    goto v_11180;
v_11181:
        return Llessp(nil, v_11198, v_11197);
v_11173:
    goto v_11192;
v_11188:
    v_11198 = v_11197;
    v_11198 = qcar(v_11198);
    if (!symbolp(v_11198)) v_11198 = nil;
    else { v_11198 = qfastgets(v_11198);
           if (v_11198 != nil) { v_11198 = elt(v_11198, 30); // minusp
#ifdef RECORD_GET
             if (v_11198 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v_11198 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v_11198 == SPID_NOPROP) v_11198 = nil; }}
#endif
    goto v_11189;
v_11190:
    goto v_11191;
v_11192:
    goto v_11188;
v_11189:
    goto v_11190;
v_11191:
        return Lapply1(nil, v_11198, v_11197);
    v_11197 = nil;
    return onevalue(v_11197);
}



// Code for qremd

static LispObject CC_qremd(LispObject env,
                         LispObject v_11168, LispObject v_11169)
{
    env = qenv(env);
    LispObject v_11304, v_11305;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11168,v_11169);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_11169;
    stack[-2] = v_11168;
// end of prologue
    v_11304 = stack[-2];
    if (v_11304 == nil) goto v_11173;
    else goto v_11174;
v_11173:
    goto v_11181;
v_11177:
    v_11305 = stack[-2];
    goto v_11178;
v_11179:
    v_11304 = stack[-2];
    goto v_11180;
v_11181:
    goto v_11177;
v_11178:
    goto v_11179;
v_11180:
    return cons(v_11305, v_11304);
v_11174:
    goto v_11190;
v_11186:
    v_11305 = stack[-1];
    goto v_11187;
v_11188:
    v_11304 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11189;
v_11190:
    goto v_11186;
v_11187:
    goto v_11188;
v_11189:
    if (v_11305 == v_11304) goto v_11184;
    else goto v_11185;
v_11184:
    v_11304 = stack[-2];
    return ncons(v_11304);
v_11185:
    v_11304 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_11304)) v_11304 = nil;
    else { v_11304 = qfastgets(v_11304);
           if (v_11304 != nil) { v_11304 = elt(v_11304, 3); // field
#ifdef RECORD_GET
             if (v_11304 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_11304 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_11304 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_11304 == SPID_NOPROP) v_11304 = nil; else v_11304 = lisp_true; }}
#endif
    if (v_11304 == nil) goto v_11196;
    goto v_11205;
v_11201:
    v_11304 = stack[-1];
    fn = elt(env, 2); // !:recip
    v_11305 = (*qfn1(fn))(fn, v_11304);
    env = stack[-4];
    goto v_11202;
v_11203:
    v_11304 = stack[-2];
    goto v_11204;
v_11205:
    goto v_11201;
v_11202:
    goto v_11203;
v_11204:
    fn = elt(env, 3); // multd
    v_11304 = (*qfn2(fn))(fn, v_11305, v_11304);
    return ncons(v_11304);
v_11196:
    v_11304 = stack[-2];
    if (!consp(v_11304)) goto v_11213;
    else goto v_11214;
v_11213:
    v_11304 = lisp_true;
    goto v_11212;
v_11214:
    v_11304 = stack[-2];
    v_11304 = qcar(v_11304);
    v_11304 = (consp(v_11304) ? nil : lisp_true);
    goto v_11212;
    v_11304 = nil;
v_11212:
    if (v_11304 == nil) goto v_11210;
    goto v_11227;
v_11223:
    v_11305 = stack[-2];
    goto v_11224;
v_11225:
    v_11304 = stack[-1];
    goto v_11226;
v_11227:
    goto v_11223;
v_11224:
    goto v_11225;
v_11226:
    {
        fn = elt(env, 4); // !:divide
        return (*qfn2(fn))(fn, v_11305, v_11304);
    }
v_11210:
    goto v_11240;
v_11236:
    v_11304 = stack[-2];
    v_11304 = qcar(v_11304);
    v_11305 = qcdr(v_11304);
    goto v_11237;
v_11238:
    v_11304 = stack[-1];
    goto v_11239;
v_11240:
    goto v_11236;
v_11237:
    goto v_11238;
v_11239:
    fn = elt(env, 5); // qremf
    v_11304 = (*qfn2(fn))(fn, v_11305, v_11304);
    env = stack[-4];
    stack[-3] = v_11304;
    goto v_11250;
v_11246:
    goto v_11256;
v_11252:
    goto v_11262;
v_11258:
    goto v_11269;
v_11265:
    v_11304 = stack[-2];
    v_11304 = qcar(v_11304);
    v_11305 = qcar(v_11304);
    goto v_11266;
v_11267:
    v_11304 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11268;
v_11269:
    goto v_11265;
v_11266:
    goto v_11267;
v_11268:
    v_11304 = cons(v_11305, v_11304);
    env = stack[-4];
    v_11305 = ncons(v_11304);
    env = stack[-4];
    goto v_11259;
v_11260:
    v_11304 = stack[-3];
    v_11304 = qcar(v_11304);
    goto v_11261;
v_11262:
    goto v_11258;
v_11259:
    goto v_11260;
v_11261:
    fn = elt(env, 6); // multf
    stack[0] = (*qfn2(fn))(fn, v_11305, v_11304);
    env = stack[-4];
    goto v_11253;
v_11254:
    goto v_11281;
v_11277:
    goto v_11288;
v_11284:
    v_11304 = stack[-2];
    v_11304 = qcar(v_11304);
    v_11305 = qcar(v_11304);
    goto v_11285;
v_11286:
    v_11304 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11287;
v_11288:
    goto v_11284;
v_11285:
    goto v_11286;
v_11287:
    v_11304 = cons(v_11305, v_11304);
    env = stack[-4];
    v_11305 = ncons(v_11304);
    env = stack[-4];
    goto v_11278;
v_11279:
    v_11304 = stack[-3];
    v_11304 = qcdr(v_11304);
    goto v_11280;
v_11281:
    goto v_11277;
v_11278:
    goto v_11279;
v_11280:
    fn = elt(env, 6); // multf
    v_11304 = (*qfn2(fn))(fn, v_11305, v_11304);
    env = stack[-4];
    goto v_11255;
v_11256:
    goto v_11252;
v_11253:
    goto v_11254;
v_11255:
    stack[0] = cons(stack[0], v_11304);
    env = stack[-4];
    goto v_11247;
v_11248:
    goto v_11300;
v_11296:
    v_11304 = stack[-2];
    v_11305 = qcdr(v_11304);
    goto v_11297;
v_11298:
    v_11304 = stack[-1];
    goto v_11299;
v_11300:
    goto v_11296;
v_11297:
    goto v_11298;
v_11299:
    v_11304 = CC_qremd(elt(env, 0), v_11305, v_11304);
    env = stack[-4];
    goto v_11249;
v_11250:
    goto v_11246;
v_11247:
    goto v_11248;
v_11249:
    {
        LispObject v_11310 = stack[0];
        fn = elt(env, 7); // praddf
        return (*qfn2(fn))(fn, v_11310, v_11304);
    }
    goto v_11172;
    v_11304 = nil;
v_11172:
    return onevalue(v_11304);
}



// Code for reverse!-num

static LispObject CC_reverseKnum(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11217, v_11218;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11168);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11168;
// end of prologue
    goto v_11178;
v_11174:
    v_11218 = stack[0];
    goto v_11175;
v_11176:
    v_11217 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11177;
v_11178:
    goto v_11174;
v_11175:
    goto v_11176;
v_11177:
    if (v_11218 == v_11217) goto v_11172;
    else goto v_11173;
v_11172:
    v_11217 = stack[0];
    goto v_11171;
v_11173:
    goto v_11189;
v_11185:
    v_11218 = stack[0];
    goto v_11186;
v_11187:
    v_11217 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11188;
v_11189:
    goto v_11185;
v_11186:
    goto v_11187;
v_11188:
    v_11217 = (LispObject)lessp2(v_11218, v_11217);
    v_11217 = v_11217 ? lisp_true : nil;
    env = stack[-2];
    if (v_11217 == nil) goto v_11183;
    goto v_11198;
v_11194:
    v_11217 = stack[0];
    stack[-1] = negate(v_11217);
    env = stack[-2];
    goto v_11195;
v_11196:
    v_11217 = stack[0];
    v_11217 = negate(v_11217);
    env = stack[-2];
    fn = elt(env, 1); // ilog2
    v_11217 = (*qfn1(fn))(fn, v_11217);
    env = stack[-2];
    v_11217 = add1(v_11217);
    env = stack[-2];
    goto v_11197;
v_11198:
    goto v_11194;
v_11195:
    goto v_11196;
v_11197:
    fn = elt(env, 2); // reverse!-num1
    v_11217 = (*qfn2(fn))(fn, stack[-1], v_11217);
    return negate(v_11217);
v_11183:
    goto v_11212;
v_11208:
    stack[-1] = stack[0];
    goto v_11209;
v_11210:
    v_11217 = stack[0];
    fn = elt(env, 1); // ilog2
    v_11217 = (*qfn1(fn))(fn, v_11217);
    env = stack[-2];
    v_11217 = add1(v_11217);
    env = stack[-2];
    goto v_11211;
v_11212:
    goto v_11208;
v_11209:
    goto v_11210;
v_11211:
    {
        LispObject v_11221 = stack[-1];
        fn = elt(env, 2); // reverse!-num1
        return (*qfn2(fn))(fn, v_11221, v_11217);
    }
    v_11217 = nil;
v_11171:
    return onevalue(v_11217);
}



// Code for quotient!-mod!-p

static LispObject CC_quotientKmodKp(LispObject env,
                         LispObject v_11168, LispObject v_11169)
{
    env = qenv(env);
    LispObject v_11320, v_11321, v_11322;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11168,v_11169);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11169;
    stack[-1] = v_11168;
// end of prologue
    v_11320 = stack[0];
    if (v_11320 == nil) goto v_11173;
    else goto v_11174;
v_11173:
    v_11320 = elt(env, 1); // "b=0 in quotient-mod-p"
    {
        fn = elt(env, 3); // errorf
        return (*qfn1(fn))(fn, v_11320);
    }
v_11174:
    v_11320 = stack[0];
    if (!consp(v_11320)) goto v_11182;
    else goto v_11183;
v_11182:
    v_11320 = lisp_true;
    goto v_11181;
v_11183:
    v_11320 = stack[0];
    v_11320 = qcar(v_11320);
    v_11320 = (consp(v_11320) ? nil : lisp_true);
    goto v_11181;
    v_11320 = nil;
v_11181:
    if (v_11320 == nil) goto v_11179;
    v_11320 = stack[0];
    fn = elt(env, 4); // safe!-modular!-reciprocal
    v_11320 = (*qfn1(fn))(fn, v_11320);
    env = stack[-3];
    v_11321 = v_11320;
    if (v_11321 == nil) goto v_11198;
    else goto v_11199;
v_11198:
    v_11320 = nil;
    qvalue(elt(env, 2)) = v_11320; // exact!-quotient!-flag
    goto v_11193;
v_11199:
    goto v_11209;
v_11205:
    v_11321 = stack[-1];
    goto v_11206;
v_11207:
    goto v_11208;
v_11209:
    goto v_11205;
v_11206:
    goto v_11207;
v_11208:
    {
        fn = elt(env, 5); // multiply!-by!-constant!-mod!-p
        return (*qfn2(fn))(fn, v_11321, v_11320);
    }
    v_11320 = nil;
v_11193:
    goto v_11172;
v_11179:
    v_11320 = stack[-1];
    if (v_11320 == nil) goto v_11212;
    else goto v_11213;
v_11212:
    v_11320 = nil;
    goto v_11172;
v_11213:
    v_11320 = stack[-1];
    if (!consp(v_11320)) goto v_11220;
    else goto v_11221;
v_11220:
    v_11320 = lisp_true;
    goto v_11219;
v_11221:
    v_11320 = stack[-1];
    v_11320 = qcar(v_11320);
    v_11320 = (consp(v_11320) ? nil : lisp_true);
    goto v_11219;
    v_11320 = nil;
v_11219:
    if (v_11320 == nil) goto v_11217;
    v_11320 = nil;
    qvalue(elt(env, 2)) = v_11320; // exact!-quotient!-flag
    goto v_11172;
v_11217:
    goto v_11236;
v_11232:
    v_11320 = stack[-1];
    v_11320 = qcar(v_11320);
    v_11320 = qcar(v_11320);
    v_11321 = qcar(v_11320);
    goto v_11233;
v_11234:
    v_11320 = stack[0];
    v_11320 = qcar(v_11320);
    v_11320 = qcar(v_11320);
    v_11320 = qcar(v_11320);
    goto v_11235;
v_11236:
    goto v_11232;
v_11233:
    goto v_11234;
v_11235:
    if (equal(v_11321, v_11320)) goto v_11230;
    else goto v_11231;
v_11230:
    goto v_11252;
v_11246:
    v_11322 = stack[-1];
    goto v_11247;
v_11248:
    v_11321 = stack[0];
    goto v_11249;
v_11250:
    v_11320 = stack[0];
    v_11320 = qcar(v_11320);
    v_11320 = qcar(v_11320);
    v_11320 = qcar(v_11320);
    goto v_11251;
v_11252:
    goto v_11246;
v_11247:
    goto v_11248;
v_11249:
    goto v_11250;
v_11251:
    {
        fn = elt(env, 6); // xquotient!-mod!-p
        return (*qfnn(fn))(fn, 3, v_11322, v_11321, v_11320);
    }
v_11231:
    goto v_11266;
v_11262:
    v_11320 = stack[-1];
    v_11320 = qcar(v_11320);
    v_11320 = qcar(v_11320);
    v_11321 = qcar(v_11320);
    goto v_11263;
v_11264:
    v_11320 = stack[0];
    v_11320 = qcar(v_11320);
    v_11320 = qcar(v_11320);
    v_11320 = qcar(v_11320);
    goto v_11265;
v_11266:
    goto v_11262;
v_11263:
    goto v_11264;
v_11265:
    fn = elt(env, 7); // ordop
    v_11320 = (*qfn2(fn))(fn, v_11321, v_11320);
    env = stack[-3];
    if (v_11320 == nil) goto v_11260;
    goto v_11280;
v_11276:
    v_11320 = stack[-1];
    v_11320 = qcar(v_11320);
    v_11321 = qcdr(v_11320);
    goto v_11277;
v_11278:
    v_11320 = stack[0];
    goto v_11279;
v_11280:
    goto v_11276;
v_11277:
    goto v_11278;
v_11279:
    stack[-2] = CC_quotientKmodKp(elt(env, 0), v_11321, v_11320);
    env = stack[-3];
    goto v_11290;
v_11286:
    v_11320 = stack[-1];
    v_11321 = qcdr(v_11320);
    goto v_11287;
v_11288:
    v_11320 = stack[0];
    goto v_11289;
v_11290:
    goto v_11286;
v_11287:
    goto v_11288;
v_11289:
    v_11320 = CC_quotientKmodKp(elt(env, 0), v_11321, v_11320);
    v_11321 = stack[-2];
    v_11322 = v_11321;
    if (v_11322 == nil) goto v_11298;
    else goto v_11299;
v_11298:
    goto v_11297;
v_11299:
    goto v_11311;
v_11305:
    v_11322 = stack[-1];
    v_11322 = qcar(v_11322);
    v_11322 = qcar(v_11322);
    goto v_11306;
v_11307:
    goto v_11308;
v_11309:
    goto v_11310;
v_11311:
    goto v_11305;
v_11306:
    goto v_11307;
v_11308:
    goto v_11309;
v_11310:
    return acons(v_11322, v_11321, v_11320);
    v_11320 = nil;
v_11297:
    goto v_11172;
v_11260:
    v_11320 = nil;
    qvalue(elt(env, 2)) = v_11320; // exact!-quotient!-flag
    goto v_11172;
    v_11320 = nil;
v_11172:
    return onevalue(v_11320);
}



// Code for traput

static LispObject CC_traput(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_11232, v_11233, v_11234, v_11235, v_11236;
    LispObject v_11170, v_11169, v_11168;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "traput");
    va_start(aa, nargs);
    v_11168 = va_arg(aa, LispObject);
    v_11169 = va_arg(aa, LispObject);
    v_11170 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_11170,v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_11168,v_11169,v_11170);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_11233 = v_11170;
    v_11234 = v_11169;
    v_11235 = v_11168;
// end of prologue
    goto v_11184;
v_11180:
    v_11236 = v_11235;
    goto v_11181;
v_11182:
    v_11232 = v_11234;
    goto v_11183;
v_11184:
    goto v_11180;
v_11181:
    goto v_11182;
v_11183:
    v_11232 = get(v_11236, v_11232);
    env = stack[-2];
    v_11236 = v_11232;
    if (v_11232 == nil) goto v_11178;
    v_11232 = qvalue(elt(env, 1)); // toplv!*
    if (v_11232 == nil) goto v_11191;
    else goto v_11190;
v_11191:
    goto v_11198;
v_11194:
    v_11234 = v_11233;
    goto v_11195;
v_11196:
    v_11232 = v_11236;
    goto v_11197;
v_11198:
    goto v_11194;
v_11195:
    goto v_11196;
v_11197:
    v_11232 = Lmemq(nil, v_11234, v_11232);
    if (v_11232 == nil) goto v_11193;
    else goto v_11190;
v_11193:
    goto v_11207;
v_11203:
    stack[0] = v_11236;
    goto v_11204;
v_11205:
    goto v_11214;
v_11210:
    v_11232 = v_11233;
    goto v_11211;
v_11212:
    v_11233 = v_11236;
    v_11233 = qcdr(v_11233);
    goto v_11213;
v_11214:
    goto v_11210;
v_11211:
    goto v_11212;
v_11213:
    v_11232 = cons(v_11232, v_11233);
    env = stack[-2];
    goto v_11206;
v_11207:
    goto v_11203;
v_11204:
    goto v_11205;
v_11206:
    v_11232 = Lrplacd(nil, stack[0], v_11232);
    goto v_11188;
v_11190:
v_11188:
    goto v_11176;
v_11178:
    goto v_11227;
v_11221:
    stack[-1] = v_11235;
    goto v_11222;
v_11223:
    stack[0] = v_11234;
    goto v_11224;
v_11225:
    v_11232 = v_11233;
    v_11232 = ncons(v_11232);
    env = stack[-2];
    goto v_11226;
v_11227:
    goto v_11221;
v_11222:
    goto v_11223;
v_11224:
    goto v_11225;
v_11226:
    v_11232 = Lputprop(nil, 3, stack[-1], stack[0], v_11232);
    goto v_11176;
v_11176:
    v_11232 = nil;
    return onevalue(v_11232);
}



// Code for rl_csimpl

static LispObject CC_rl_csimpl(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11193, v_11194, v_11195;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11168);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_11168;
// end of prologue
    v_11193 = qvalue(elt(env, 1)); // !*rlsimpl
    if (v_11193 == nil) goto v_11173;
    v_11193 = elt(env, 2); // rl_simpl
    fn = elt(env, 3); // getd
    v_11193 = (*qfn1(fn))(fn, v_11193);
    env = stack[-1];
    if (v_11193 == nil) goto v_11173;
    goto v_11186;
v_11180:
    v_11195 = stack[0];
    goto v_11181;
v_11182:
    v_11194 = nil;
    goto v_11183;
v_11184:
    v_11193 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_11185;
v_11186:
    goto v_11180;
v_11181:
    goto v_11182;
v_11183:
    goto v_11184;
v_11185:
    {
        fn = elt(env, 2); // rl_simpl
        return (*qfnn(fn))(fn, 3, v_11195, v_11194, v_11193);
    }
v_11173:
    v_11193 = stack[0];
    goto v_11171;
    v_11193 = nil;
v_11171:
    return onevalue(v_11193);
}



// Code for lto_max1

static LispObject CC_lto_max1(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11213, v_11214;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11168);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11168;
// end of prologue
    stack[-1] = nil;
v_11174:
    v_11213 = stack[0];
    v_11213 = qcdr(v_11213);
    if (v_11213 == nil) goto v_11179;
    else goto v_11180;
v_11179:
    goto v_11175;
v_11180:
    goto v_11188;
v_11184:
    v_11213 = stack[0];
    v_11214 = qcar(v_11213);
    goto v_11185;
v_11186:
    v_11213 = stack[-1];
    goto v_11187;
v_11188:
    goto v_11184;
v_11185:
    goto v_11186;
v_11187:
    v_11213 = cons(v_11214, v_11213);
    env = stack[-2];
    stack[-1] = v_11213;
    v_11213 = stack[0];
    v_11213 = qcdr(v_11213);
    stack[0] = v_11213;
    goto v_11174;
v_11175:
    v_11213 = stack[0];
    v_11213 = qcar(v_11213);
    v_11214 = v_11213;
v_11176:
    v_11213 = stack[-1];
    if (v_11213 == nil) goto v_11198;
    else goto v_11199;
v_11198:
    v_11213 = v_11214;
    goto v_11173;
v_11199:
    goto v_11207;
v_11203:
    v_11213 = stack[-1];
    v_11213 = qcar(v_11213);
    goto v_11204;
v_11205:
    goto v_11206;
v_11207:
    goto v_11203;
v_11204:
    goto v_11205;
v_11206:
    fn = elt(env, 1); // max
    v_11213 = (*qfn2(fn))(fn, v_11213, v_11214);
    env = stack[-2];
    v_11214 = v_11213;
    v_11213 = stack[-1];
    v_11213 = qcdr(v_11213);
    stack[-1] = v_11213;
    goto v_11176;
v_11173:
    return onevalue(v_11213);
}



// Code for dip_fmon

static LispObject CC_dip_fmon(LispObject env,
                         LispObject v_11168, LispObject v_11169)
{
    env = qenv(env);
    LispObject v_11182, v_11183, v_11184;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11183 = v_11169;
    v_11182 = v_11168;
// end of prologue
    goto v_11178;
v_11172:
    v_11184 = v_11183;
    goto v_11173;
v_11174:
    v_11183 = v_11182;
    goto v_11175;
v_11176:
    v_11182 = nil;
    goto v_11177;
v_11178:
    goto v_11172;
v_11173:
    goto v_11174;
v_11175:
    goto v_11176;
v_11177:
    return list2star(v_11184, v_11183, v_11182);
}



// Code for merge!-ind!-vars

static LispObject CC_mergeKindKvars(LispObject env,
                         LispObject v_11168, LispObject v_11169)
{
    env = qenv(env);
    LispObject v_11227, v_11228;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11168,v_11169);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11169;
    stack[-1] = v_11168;
// end of prologue
    v_11227 = qvalue(elt(env, 1)); // !*nocommutedf
    if (v_11227 == nil) goto v_11175;
    else goto v_11173;
v_11175:
    v_11227 = qvalue(elt(env, 2)); // !*commutedf
    if (v_11227 == nil) goto v_11180;
    else goto v_11181;
v_11180:
    goto v_11187;
v_11183:
    v_11227 = stack[-1];
    v_11227 = qcdr(v_11227);
    stack[-2] = qcar(v_11227);
    goto v_11184;
v_11185:
    goto v_11196;
v_11192:
    v_11228 = stack[0];
    goto v_11193;
v_11194:
    v_11227 = stack[-1];
    v_11227 = qcdr(v_11227);
    v_11227 = qcdr(v_11227);
    goto v_11195;
v_11196:
    goto v_11192;
v_11193:
    goto v_11194;
v_11195:
    v_11227 = cons(v_11228, v_11227);
    env = stack[-3];
    goto v_11186;
v_11187:
    goto v_11183;
v_11184:
    goto v_11185;
v_11186:
    v_11227 = Lmemq(nil, stack[-2], v_11227);
    goto v_11179;
v_11181:
    v_11227 = nil;
    goto v_11179;
    v_11227 = nil;
v_11179:
    if (v_11227 == nil) goto v_11177;
    else goto v_11173;
v_11177:
    goto v_11174;
v_11173:
    goto v_11210;
v_11206:
    v_11228 = stack[0];
    goto v_11207;
v_11208:
    v_11227 = stack[-1];
    v_11227 = qcdr(v_11227);
    v_11227 = qcdr(v_11227);
    goto v_11209;
v_11210:
    goto v_11206;
v_11207:
    goto v_11208;
v_11209:
    {
        fn = elt(env, 3); // derad!*
        return (*qfn2(fn))(fn, v_11228, v_11227);
    }
v_11174:
    goto v_11222;
v_11218:
    v_11228 = stack[0];
    goto v_11219;
v_11220:
    v_11227 = stack[-1];
    v_11227 = qcdr(v_11227);
    v_11227 = qcdr(v_11227);
    goto v_11221;
v_11222:
    goto v_11218;
v_11219:
    goto v_11220;
v_11221:
    {
        fn = elt(env, 4); // derad
        return (*qfn2(fn))(fn, v_11228, v_11227);
    }
    v_11227 = nil;
    return onevalue(v_11227);
}



// Code for testredzz

static LispObject CC_testredzz(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11210, v_11211;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11168);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_11210 = v_11168;
// end of prologue
    goto v_11178;
v_11174:
    goto v_11183;
v_11179:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_11180;
v_11181:
    goto v_11190;
v_11186:
    v_11211 = qvalue(elt(env, 2)); // maxvar
    goto v_11187;
v_11188:
    goto v_11189;
v_11190:
    goto v_11186;
v_11187:
    goto v_11188;
v_11189:
    v_11210 = plus2(v_11211, v_11210);
    env = stack[-1];
    goto v_11182;
v_11183:
    goto v_11179;
v_11180:
    goto v_11181;
v_11182:
    v_11211 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_11210-TAG_FIXNUM)/(16/CELL)));
    goto v_11175;
v_11176:
    v_11210 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_11177;
v_11178:
    goto v_11174;
v_11175:
    goto v_11176;
v_11177:
    v_11210 = *(LispObject *)((char *)v_11211 + (CELL-TAG_VECTOR) + (((intptr_t)v_11210-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_11210;
v_11173:
    v_11210 = stack[0];
    if (v_11210 == nil) goto v_11198;
    else goto v_11199;
v_11198:
    v_11210 = nil;
    goto v_11172;
v_11199:
    v_11210 = stack[0];
    v_11210 = qcar(v_11210);
    v_11210 = qcar(v_11210);
    fn = elt(env, 3); // testredh
    v_11210 = (*qfn1(fn))(fn, v_11210);
    env = stack[-1];
    v_11210 = stack[0];
    v_11210 = qcdr(v_11210);
    stack[0] = v_11210;
    goto v_11173;
v_11172:
    return onevalue(v_11210);
}



// Code for indexvarordp

static LispObject CC_indexvarordp(LispObject env,
                         LispObject v_11168, LispObject v_11169)
{
    env = qenv(env);
    LispObject v_11286, v_11287;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11168,v_11169);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_11169;
    stack[-1] = v_11168;
// end of prologue
    goto v_11183;
v_11179:
    v_11286 = stack[-1];
    v_11287 = qcar(v_11286);
    goto v_11180;
v_11181:
    v_11286 = stack[0];
    v_11286 = qcar(v_11286);
    goto v_11182;
v_11183:
    goto v_11179;
v_11180:
    goto v_11181;
v_11182:
    if (v_11287 == v_11286) goto v_11178;
    v_11286 = lisp_true;
    goto v_11176;
v_11178:
    goto v_11198;
v_11194:
    v_11287 = stack[-1];
    goto v_11195;
v_11196:
    v_11286 = qvalue(elt(env, 1)); // kord!*
    goto v_11197;
v_11198:
    goto v_11194;
v_11195:
    goto v_11196;
v_11197:
    v_11286 = Lmemq(nil, v_11287, v_11286);
    if (v_11286 == nil) goto v_11193;
    else goto v_11192;
v_11193:
    goto v_11206;
v_11202:
    v_11287 = stack[0];
    goto v_11203;
v_11204:
    v_11286 = qvalue(elt(env, 1)); // kord!*
    goto v_11205;
v_11206:
    goto v_11202;
v_11203:
    goto v_11204;
v_11205:
    v_11286 = Lmemq(nil, v_11287, v_11286);
v_11192:
    goto v_11176;
    v_11286 = nil;
v_11176:
    if (v_11286 == nil) goto v_11174;
    goto v_11215;
v_11211:
    v_11287 = stack[-1];
    goto v_11212;
v_11213:
    v_11286 = stack[0];
    goto v_11214;
v_11215:
    goto v_11211;
v_11212:
    goto v_11213;
v_11214:
    {
        fn = elt(env, 3); // ordop
        return (*qfn2(fn))(fn, v_11287, v_11286);
    }
v_11174:
    v_11286 = stack[-1];
    v_11286 = qcdr(v_11286);
    fn = elt(env, 4); // flatindxl
    stack[-2] = (*qfn1(fn))(fn, v_11286);
    env = stack[-3];
    v_11286 = stack[0];
    v_11286 = qcdr(v_11286);
    fn = elt(env, 4); // flatindxl
    v_11287 = (*qfn1(fn))(fn, v_11286);
    env = stack[-3];
    v_11286 = stack[-2];
    stack[-2] = v_11287;
    goto v_11237;
v_11233:
    v_11287 = v_11286;
    goto v_11234;
v_11235:
    v_11286 = qvalue(elt(env, 2)); // indxl!*
    goto v_11236;
v_11237:
    goto v_11233;
v_11234:
    goto v_11235;
v_11236:
    fn = elt(env, 5); // boundindp
    v_11286 = (*qfn2(fn))(fn, v_11287, v_11286);
    env = stack[-3];
    if (v_11286 == nil) goto v_11231;
    goto v_11249;
v_11245:
    v_11287 = stack[-2];
    goto v_11246;
v_11247:
    v_11286 = qvalue(elt(env, 2)); // indxl!*
    goto v_11248;
v_11249:
    goto v_11245;
v_11246:
    goto v_11247;
v_11248:
    fn = elt(env, 5); // boundindp
    v_11286 = (*qfn2(fn))(fn, v_11287, v_11286);
    env = stack[-3];
    if (v_11286 == nil) goto v_11243;
    goto v_11257;
v_11253:
    v_11286 = stack[-1];
    v_11287 = qcdr(v_11286);
    goto v_11254;
v_11255:
    v_11286 = stack[0];
    v_11286 = qcdr(v_11286);
    goto v_11256;
v_11257:
    goto v_11253;
v_11254:
    goto v_11255;
v_11256:
    {
        fn = elt(env, 6); // indordlp
        return (*qfn2(fn))(fn, v_11287, v_11286);
    }
v_11243:
    v_11286 = lisp_true;
    goto v_11241;
    v_11286 = nil;
v_11241:
    goto v_11229;
v_11231:
    goto v_11272;
v_11268:
    v_11287 = stack[-2];
    goto v_11269;
v_11270:
    v_11286 = qvalue(elt(env, 2)); // indxl!*
    goto v_11271;
v_11272:
    goto v_11268;
v_11269:
    goto v_11270;
v_11271:
    fn = elt(env, 5); // boundindp
    v_11286 = (*qfn2(fn))(fn, v_11287, v_11286);
    env = stack[-3];
    if (v_11286 == nil) goto v_11266;
    v_11286 = nil;
    goto v_11229;
v_11266:
    goto v_11283;
v_11279:
    v_11287 = stack[-1];
    goto v_11280;
v_11281:
    v_11286 = stack[0];
    goto v_11282;
v_11283:
    goto v_11279;
v_11280:
    goto v_11281;
v_11282:
    {
        fn = elt(env, 3); // ordop
        return (*qfn2(fn))(fn, v_11287, v_11286);
    }
    v_11286 = nil;
v_11229:
    goto v_11172;
    v_11286 = nil;
v_11172:
    return onevalue(v_11286);
}



// Code for inttovec!-solve

static LispObject CC_inttovecKsolve(LispObject env,
                         LispObject v_11168, LispObject v_11169)
{
    env = qenv(env);
    LispObject v_11270, v_11271;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_11169,v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_11168,v_11169);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_11169;
    stack[-3] = v_11168;
// end of prologue
    goto v_11183;
v_11179:
    v_11271 = stack[-2];
    goto v_11180;
v_11181:
    v_11270 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11182;
v_11183:
    goto v_11179;
v_11180:
    goto v_11181;
v_11182:
    if (v_11271 == v_11270) goto v_11177;
    else goto v_11178;
v_11177:
    v_11270 = lisp_true;
    goto v_11176;
v_11178:
    goto v_11193;
v_11189:
    v_11271 = stack[-3];
    goto v_11190;
v_11191:
    v_11270 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11192;
v_11193:
    goto v_11189;
v_11190:
    goto v_11191;
v_11192:
    v_11270 = (v_11271 == v_11270 ? lisp_true : nil);
    goto v_11176;
    v_11270 = nil;
v_11176:
    if (v_11270 == nil) goto v_11174;
    goto v_11202;
v_11198:
    v_11271 = stack[-2];
    goto v_11199;
v_11200:
    v_11270 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11201;
v_11202:
    goto v_11198;
v_11199:
    goto v_11200;
v_11201:
    return cons(v_11271, v_11270);
v_11174:
    v_11270 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_11270;
    v_11270 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_11270;
v_11216:
    v_11270 = stack[0];
    stack[-1] = v_11270;
    v_11270 = stack[-4];
    v_11270 = add1(v_11270);
    env = stack[-5];
    stack[-4] = v_11270;
    goto v_11225;
v_11221:
    goto v_11231;
v_11227:
    goto v_11237;
v_11233:
    v_11271 = stack[-3];
    goto v_11234;
v_11235:
    v_11270 = stack[-4];
    goto v_11236;
v_11237:
    goto v_11233;
v_11234:
    goto v_11235;
v_11236:
    v_11271 = plus2(v_11271, v_11270);
    env = stack[-5];
    goto v_11228;
v_11229:
    v_11270 = stack[-1];
    goto v_11230;
v_11231:
    goto v_11227;
v_11228:
    goto v_11229;
v_11230:
    v_11271 = times2(v_11271, v_11270);
    env = stack[-5];
    goto v_11222;
v_11223:
    v_11270 = stack[-4];
    goto v_11224;
v_11225:
    goto v_11221;
v_11222:
    goto v_11223;
v_11224:
    v_11270 = quot2(v_11271, v_11270);
    env = stack[-5];
    stack[0] = v_11270;
    goto v_11252;
v_11248:
    v_11271 = stack[0];
    goto v_11249;
v_11250:
    v_11270 = stack[-2];
    goto v_11251;
v_11252:
    goto v_11248;
v_11249:
    goto v_11250;
v_11251:
    v_11270 = (LispObject)greaterp2(v_11271, v_11270);
    v_11270 = v_11270 ? lisp_true : nil;
    env = stack[-5];
    if (v_11270 == nil) goto v_11245;
    else goto v_11246;
v_11245:
    goto v_11216;
v_11246:
    goto v_11260;
v_11256:
    stack[0] = stack[-4];
    goto v_11257;
v_11258:
    goto v_11267;
v_11263:
    v_11271 = stack[-2];
    goto v_11264;
v_11265:
    v_11270 = stack[-1];
    goto v_11266;
v_11267:
    goto v_11263;
v_11264:
    goto v_11265;
v_11266:
    v_11270 = difference2(v_11271, v_11270);
    goto v_11259;
v_11260:
    goto v_11256;
v_11257:
    goto v_11258;
v_11259:
    {
        LispObject v_11277 = stack[0];
        return cons(v_11277, v_11270);
    }
    goto v_11172;
    v_11270 = nil;
v_11172:
    return onevalue(v_11270);
}



// Code for expand!-imrepart

static LispObject CC_expandKimrepart(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11240, v_11241;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11168);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_11168;
// end of prologue
    stack[-2] = nil;
v_11174:
    v_11240 = stack[-1];
    if (!consp(v_11240)) goto v_11183;
    else goto v_11184;
v_11183:
    v_11240 = lisp_true;
    goto v_11182;
v_11184:
    v_11240 = stack[-1];
    v_11240 = qcar(v_11240);
    v_11240 = (consp(v_11240) ? nil : lisp_true);
    goto v_11182;
    v_11240 = nil;
v_11182:
    if (v_11240 == nil) goto v_11180;
    goto v_11175;
v_11180:
    goto v_11197;
v_11193:
    goto v_11203;
v_11199:
    v_11240 = stack[-1];
    v_11240 = qcar(v_11240);
    v_11240 = qcar(v_11240);
    fn = elt(env, 1); // expand!-imrepartpow
    stack[0] = (*qfn1(fn))(fn, v_11240);
    env = stack[-3];
    goto v_11200;
v_11201:
    v_11240 = stack[-1];
    v_11240 = qcar(v_11240);
    v_11240 = qcdr(v_11240);
    v_11240 = CC_expandKimrepart(elt(env, 0), v_11240);
    env = stack[-3];
    goto v_11202;
v_11203:
    goto v_11199;
v_11200:
    goto v_11201;
v_11202:
    fn = elt(env, 2); // multsq
    v_11241 = (*qfn2(fn))(fn, stack[0], v_11240);
    env = stack[-3];
    goto v_11194;
v_11195:
    v_11240 = stack[-2];
    goto v_11196;
v_11197:
    goto v_11193;
v_11194:
    goto v_11195;
v_11196:
    v_11240 = cons(v_11241, v_11240);
    env = stack[-3];
    stack[-2] = v_11240;
    v_11240 = stack[-1];
    v_11240 = qcdr(v_11240);
    stack[-1] = v_11240;
    goto v_11174;
v_11175:
    goto v_11220;
v_11216:
    v_11241 = stack[-1];
    goto v_11217;
v_11218:
    v_11240 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_11219;
v_11220:
    goto v_11216;
v_11217:
    goto v_11218;
v_11219:
    v_11240 = cons(v_11241, v_11240);
    env = stack[-3];
    v_11241 = v_11240;
v_11176:
    v_11240 = stack[-2];
    if (v_11240 == nil) goto v_11225;
    else goto v_11226;
v_11225:
    v_11240 = v_11241;
    goto v_11173;
v_11226:
    goto v_11234;
v_11230:
    v_11240 = stack[-2];
    v_11240 = qcar(v_11240);
    goto v_11231;
v_11232:
    goto v_11233;
v_11234:
    goto v_11230;
v_11231:
    goto v_11232;
v_11233:
    fn = elt(env, 3); // addsq
    v_11240 = (*qfn2(fn))(fn, v_11240, v_11241);
    env = stack[-3];
    v_11241 = v_11240;
    v_11240 = stack[-2];
    v_11240 = qcdr(v_11240);
    stack[-2] = v_11240;
    goto v_11176;
v_11173:
    return onevalue(v_11240);
}



// Code for begin1a

static LispObject CC_begin1a(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11531, v_11532, v_11533;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_11168);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_11168);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_11168;
// end of prologue
    v_11531 = Ltime(nil, 0);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_11531; // otime!*
    v_11531 = elt(env, 2); // gctime
    fn = elt(env, 53); // getd
    v_11531 = (*qfn1(fn))(fn, v_11531);
    env = stack[-2];
    if (v_11531 == nil) goto v_11185;
    v_11531 = Lgctime(nil, 0);
    env = stack[-2];
    qvalue(elt(env, 3)) = v_11531; // ogctime!*
    goto v_11183;
v_11185:
    v_11531 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 3)) = v_11531; // ogctime!*
    goto v_11183;
v_11183:
    v_11531 = qvalue(elt(env, 1)); // otime!*
    qvalue(elt(env, 4)) = v_11531; // otime3!*
    qvalue(elt(env, 5)) = v_11531; // otime2!*
    qvalue(elt(env, 6)) = v_11531; // otime1!*
    v_11531 = qvalue(elt(env, 3)); // ogctime!*
    qvalue(elt(env, 7)) = v_11531; // ogctime3!*
    qvalue(elt(env, 8)) = v_11531; // ogctime2!*
    qvalue(elt(env, 9)) = v_11531; // ogctime1!*
    v_11531 = stack[0];
    qvalue(elt(env, 10)) = v_11531; // peekchar!*
    v_11531 = elt(env, 11); // !*semicol!*
    qvalue(elt(env, 12)) = v_11531; // cursym!*
    v_11531 = nil;
    qvalue(elt(env, 13)) = v_11531; // curescaped!*
v_11175:
    fn = elt(env, 54); // terminalp
    v_11531 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_11531 == nil) goto v_11200;
    v_11531 = qvalue(elt(env, 14)); // !*nosave!*
    if (v_11531 == nil) goto v_11206;
    else goto v_11204;
v_11206:
    goto v_11213;
v_11209:
    v_11532 = qvalue(elt(env, 15)); // statcounter
    goto v_11210;
v_11211:
    v_11531 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11212;
v_11213:
    goto v_11209;
v_11210:
    goto v_11211;
v_11212:
    if (v_11532 == v_11531) goto v_11204;
    goto v_11205;
v_11204:
    goto v_11203;
v_11205:
    fn = elt(env, 55); // add2buflis
    v_11531 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_11203;
v_11203:
    fn = elt(env, 56); // update_prompt
    v_11531 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_11198;
v_11200:
v_11198:
    v_11531 = nil;
    qvalue(elt(env, 14)) = v_11531; // !*nosave!*
    v_11531 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 16)) = v_11531; // !*strind
    v_11531 = nil;
    stack[-1] = v_11531;
    v_11531 = qvalue(elt(env, 17)); // !*time
    if (v_11531 == nil) goto v_11227;
    v_11531 = elt(env, 18); // (showtime nil)
    fn = elt(env, 57); // lispeval
    v_11531 = (*qfn1(fn))(fn, v_11531);
    env = stack[-2];
    goto v_11225;
v_11227:
v_11225:
    v_11531 = qvalue(elt(env, 19)); // !*output
    if (v_11531 == nil) goto v_11234;
    v_11531 = qvalue(elt(env, 20)); // ofl!*
    if (v_11531 == nil) goto v_11240;
    else goto v_11241;
v_11240:
    fn = elt(env, 54); // terminalp
    v_11531 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_11531 == nil) goto v_11245;
    else goto v_11246;
v_11245:
    v_11531 = nil;
    goto v_11244;
v_11246:
    v_11531 = qvalue(elt(env, 21)); // !*defn
    if (v_11531 == nil) goto v_11253;
    else goto v_11254;
v_11253:
    v_11531 = qvalue(elt(env, 22)); // !*lessspace
    v_11531 = (v_11531 == nil ? lisp_true : nil);
    goto v_11252;
v_11254:
    v_11531 = nil;
    goto v_11252;
    v_11531 = nil;
v_11252:
    goto v_11244;
    v_11531 = nil;
v_11244:
    goto v_11239;
v_11241:
    v_11531 = nil;
    goto v_11239;
    v_11531 = nil;
v_11239:
    if (v_11531 == nil) goto v_11234;
    v_11531 = Lterpri(nil, 0);
    env = stack[-2];
    goto v_11232;
v_11234:
v_11232:
    v_11531 = qvalue(elt(env, 23)); // tslin!*
    if (v_11531 == nil) goto v_11268;
    v_11531 = qvalue(elt(env, 23)); // tslin!*
    v_11531 = qcar(v_11531);
    qvalue(elt(env, 24)) = v_11531; // !*slin
    v_11531 = qvalue(elt(env, 23)); // tslin!*
    v_11531 = qcdr(v_11531);
    qvalue(elt(env, 25)) = v_11531; // lreadfn!*
    v_11531 = nil;
    qvalue(elt(env, 23)) = v_11531; // tslin!*
    goto v_11266;
v_11268:
v_11266:
    v_11531 = qvalue(elt(env, 26)); // initl!*
    stack[0] = v_11531;
v_11176:
    v_11531 = stack[0];
    if (v_11531 == nil) goto v_11279;
    v_11531 = stack[0];
    v_11531 = qcar(v_11531);
    fn = elt(env, 58); // sinitl
    v_11531 = (*qfn1(fn))(fn, v_11531);
    env = stack[-2];
    v_11531 = stack[0];
    v_11531 = qcdr(v_11531);
    stack[0] = v_11531;
    goto v_11176;
v_11279:
    goto v_11291;
v_11287:
    v_11532 = qvalue(elt(env, 27)); // forkeywords!*
    goto v_11288;
v_11289:
    v_11531 = elt(env, 28); // delim
    goto v_11290;
v_11291:
    goto v_11287;
v_11288:
    goto v_11289;
v_11290:
    v_11531 = Lremflag(nil, v_11532, v_11531);
    env = stack[-2];
    goto v_11299;
v_11295:
    v_11532 = qvalue(elt(env, 29)); // repeatkeywords!*
    goto v_11296;
v_11297:
    v_11531 = elt(env, 28); // delim
    goto v_11298;
v_11299:
    goto v_11295;
v_11296:
    goto v_11297;
v_11298:
    v_11531 = Lremflag(nil, v_11532, v_11531);
    env = stack[-2];
    goto v_11307;
v_11303:
    v_11532 = qvalue(elt(env, 30)); // whilekeywords!*
    goto v_11304;
v_11305:
    v_11531 = elt(env, 28); // delim
    goto v_11306;
v_11307:
    goto v_11303;
v_11304:
    goto v_11305;
v_11306:
    v_11531 = Lremflag(nil, v_11532, v_11531);
    env = stack[-2];
    v_11531 = qvalue(elt(env, 31)); // !*int
    if (v_11531 == nil) goto v_11313;
    v_11531 = nil;
    qvalue(elt(env, 32)) = v_11531; // erfg!*
    goto v_11311;
v_11313:
v_11311:
    goto v_11324;
v_11320:
    v_11532 = qvalue(elt(env, 12)); // cursym!*
    goto v_11321;
v_11322:
    v_11531 = elt(env, 33); // end
    goto v_11323;
v_11324:
    goto v_11320;
v_11321:
    goto v_11322;
v_11323:
    if (v_11532 == v_11531) goto v_11318;
    else goto v_11319;
v_11318:
    v_11531 = elt(env, 33); // end
    fn = elt(env, 59); // comm1
    v_11531 = (*qfn1(fn))(fn, v_11531);
    v_11531 = nil;
    goto v_11174;
v_11319:
    fn = elt(env, 54); // terminalp
    v_11531 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_11531 == nil) goto v_11331;
    goto v_11339;
v_11335:
    v_11532 = qvalue(elt(env, 34)); // key!*
    goto v_11336;
v_11337:
    v_11531 = elt(env, 35); // ed
    goto v_11338;
v_11339:
    goto v_11335;
v_11336:
    goto v_11337;
v_11338:
    if (v_11532 == v_11531) goto v_11331;
    v_11531 = qvalue(elt(env, 36)); // promptexp!*
    fn = elt(env, 60); // printprompt
    v_11531 = (*qfn1(fn))(fn, v_11531);
    env = stack[-2];
    goto v_11317;
v_11331:
v_11317:
    goto v_11349;
v_11345:
    v_11532 = elt(env, 37); // (command)
    goto v_11346;
v_11347:
    v_11531 = lisp_true;
    goto v_11348;
v_11349:
    goto v_11345;
v_11346:
    goto v_11347;
v_11348:
    fn = elt(env, 61); // errorset!*
    v_11531 = (*qfn2(fn))(fn, v_11532, v_11531);
    env = stack[-2];
    stack[0] = v_11531;
    fn = elt(env, 62); // condterpri
    v_11531 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_11531 = stack[0];
    fn = elt(env, 63); // errorp
    v_11531 = (*qfn1(fn))(fn, v_11531);
    env = stack[-2];
    if (v_11531 == nil) goto v_11356;
    goto v_11178;
v_11356:
    v_11531 = stack[0];
    v_11531 = qcar(v_11531);
    stack[0] = v_11531;
    goto v_11373;
v_11369:
    v_11531 = stack[0];
    v_11532 = qcar(v_11531);
    goto v_11370;
v_11371:
    v_11531 = elt(env, 38); // symbolic
    goto v_11372;
v_11373:
    goto v_11369;
v_11370:
    goto v_11371;
v_11372:
    if (v_11532 == v_11531) goto v_11367;
    else goto v_11368;
v_11367:
    goto v_11382;
v_11378:
    v_11531 = stack[0];
    v_11531 = qcdr(v_11531);
    v_11532 = qcar(v_11531);
    goto v_11379;
v_11380:
    v_11531 = elt(env, 39); // xmodule
    goto v_11381;
v_11382:
    goto v_11378;
v_11379:
    goto v_11380;
v_11381:
    v_11531 = Leqcar(nil, v_11532, v_11531);
    env = stack[-2];
    goto v_11366;
v_11368:
    v_11531 = nil;
    goto v_11366;
    v_11531 = nil;
v_11366:
    if (v_11531 == nil) goto v_11364;
    v_11531 = stack[0];
    v_11531 = qcdr(v_11531);
    v_11531 = qcar(v_11531);
    fn = elt(env, 64); // eval
    v_11531 = (*qfn1(fn))(fn, v_11531);
    env = stack[-2];
    fn = elt(env, 65); // xmodloop
    v_11531 = (*qfn1(fn))(fn, v_11531);
    env = stack[-2];
    v_11533 = v_11531;
    goto v_11362;
v_11364:
    v_11531 = stack[0];
    fn = elt(env, 66); // begin11
    v_11531 = (*qfn1(fn))(fn, v_11531);
    env = stack[-2];
    v_11533 = v_11531;
    goto v_11362;
v_11362:
    v_11531 = v_11533;
    if (v_11531 == nil) goto v_11401;
    else goto v_11402;
v_11401:
    goto v_11175;
v_11402:
    goto v_11410;
v_11406:
    v_11532 = v_11533;
    goto v_11407;
v_11408:
    v_11531 = elt(env, 33); // end
    goto v_11409;
v_11410:
    goto v_11406;
v_11407:
    goto v_11408;
v_11409:
    if (v_11532 == v_11531) goto v_11404;
    else goto v_11405;
v_11404:
    v_11531 = nil;
    goto v_11174;
v_11405:
    goto v_11420;
v_11416:
    v_11532 = v_11533;
    goto v_11417;
v_11418:
    v_11531 = elt(env, 40); // err2
    goto v_11419;
v_11420:
    goto v_11416;
v_11417:
    goto v_11418;
v_11419:
    if (v_11532 == v_11531) goto v_11414;
    else goto v_11415;
v_11414:
    goto v_11179;
v_11415:
    goto v_11429;
v_11425:
    v_11532 = v_11533;
    goto v_11426;
v_11427:
    v_11531 = elt(env, 41); // err3
    goto v_11428;
v_11429:
    goto v_11425;
v_11426:
    goto v_11427;
v_11428:
    if (v_11532 == v_11531) goto v_11423;
    else goto v_11424;
v_11423:
    goto v_11180;
v_11424:
v_11177:
    v_11531 = qvalue(elt(env, 42)); // crbuf1!*
    if (v_11531 == nil) goto v_11435;
    v_11531 = elt(env, 43); // "Closing object improperly removed. Redo edit."
    fn = elt(env, 67); // lprim
    v_11531 = (*qfn1(fn))(fn, v_11531);
    env = stack[-2];
    v_11531 = nil;
    qvalue(elt(env, 42)) = v_11531; // crbuf1!*
    v_11531 = nil;
    goto v_11174;
v_11435:
    goto v_11448;
v_11444:
    v_11532 = qvalue(elt(env, 44)); // eof!*
    goto v_11445;
v_11446:
    v_11531 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_11447;
v_11448:
    goto v_11444;
v_11445:
    goto v_11446;
v_11447:
    v_11531 = (LispObject)greaterp2(v_11532, v_11531);
    v_11531 = v_11531 ? lisp_true : nil;
    env = stack[-2];
    if (v_11531 == nil) goto v_11442;
    v_11531 = elt(env, 45); // "End-of-file read"
    fn = elt(env, 67); // lprim
    v_11531 = (*qfn1(fn))(fn, v_11531);
    env = stack[-2];
    v_11531 = elt(env, 46); // (bye)
    {
        fn = elt(env, 57); // lispeval
        return (*qfn1(fn))(fn, v_11531);
    }
v_11442:
    fn = elt(env, 54); // terminalp
    v_11531 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_11531 == nil) goto v_11456;
    v_11531 = nil;
    qvalue(elt(env, 47)) = v_11531; // crbuf!*
    v_11531 = lisp_true;
    qvalue(elt(env, 14)) = v_11531; // !*nosave!*
    goto v_11175;
v_11456:
    v_11531 = nil;
    goto v_11174;
v_11178:
    fn = elt(env, 68); // eofcheck
    v_11531 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_11531 == nil) goto v_11467;
    else goto v_11465;
v_11467:
    goto v_11475;
v_11471:
    v_11532 = qvalue(elt(env, 44)); // eof!*
    goto v_11472;
v_11473:
    v_11531 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_11474;
v_11475:
    goto v_11471;
v_11472:
    goto v_11473;
v_11474:
    v_11531 = (LispObject)greaterp2(v_11532, v_11531);
    v_11531 = v_11531 ? lisp_true : nil;
    env = stack[-2];
    if (v_11531 == nil) goto v_11469;
    else goto v_11465;
v_11469:
    goto v_11466;
v_11465:
    goto v_11177;
v_11466:
    goto v_11484;
v_11480:
    v_11532 = stack[0];
    goto v_11481;
v_11482:
    v_11531 = elt(env, 48); // "BEGIN invalid"
    goto v_11483;
v_11484:
    goto v_11480;
v_11481:
    goto v_11482;
v_11483:
    if (equal(v_11532, v_11531)) goto v_11478;
    else goto v_11479;
v_11478:
    goto v_11175;
v_11479:
    v_11531 = lisp_true;
    stack[-1] = v_11531;
v_11179:
    fn = elt(env, 69); // resetparser
    v_11531 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
v_11180:
    v_11531 = lisp_true;
    qvalue(elt(env, 32)) = v_11531; // erfg!*
    v_11531 = qvalue(elt(env, 31)); // !*int
    if (v_11531 == nil) goto v_11496;
    else goto v_11497;
v_11496:
    v_11531 = qvalue(elt(env, 49)); // !*errcont
    v_11531 = (v_11531 == nil ? lisp_true : nil);
    goto v_11495;
v_11497:
    v_11531 = nil;
    goto v_11495;
    v_11531 = nil;
v_11495:
    if (v_11531 == nil) goto v_11493;
    v_11531 = lisp_true;
    qvalue(elt(env, 21)) = v_11531; // !*defn
    v_11531 = lisp_true;
    qvalue(elt(env, 50)) = v_11531; // !*echo
    v_11531 = qvalue(elt(env, 51)); // cmsg!*
    if (v_11531 == nil) goto v_11508;
    else goto v_11509;
v_11508:
    v_11531 = elt(env, 52); // "Continuing with parsing only ..."
    fn = elt(env, 70); // lprie
    v_11531 = (*qfn1(fn))(fn, v_11531);
    env = stack[-2];
    goto v_11507;
v_11509:
v_11507:
    v_11531 = lisp_true;
    qvalue(elt(env, 51)) = v_11531; // cmsg!*
    goto v_11491;
v_11493:
    v_11531 = qvalue(elt(env, 49)); // !*errcont
    if (v_11531 == nil) goto v_11514;
    else goto v_11515;
v_11514:
    v_11531 = stack[-1];
    fn = elt(env, 71); // pause1
    v_11531 = (*qfn1(fn))(fn, v_11531);
    env = stack[-2];
    v_11533 = v_11531;
    v_11531 = v_11533;
    if (v_11531 == nil) goto v_11522;
    v_11531 = v_11533;
    fn = elt(env, 57); // lispeval
    v_11531 = (*qfn1(fn))(fn, v_11531);
    v_11531 = (v_11531 == nil ? lisp_true : nil);
    goto v_11174;
v_11522:
    v_11531 = nil;
    qvalue(elt(env, 32)) = v_11531; // erfg!*
    goto v_11491;
v_11515:
    v_11531 = nil;
    qvalue(elt(env, 32)) = v_11531; // erfg!*
    goto v_11491;
v_11491:
    goto v_11175;
v_11174:
    return onevalue(v_11531);
}



// Code for bas_newnumber

static LispObject CC_bas_newnumber(LispObject env,
                         LispObject v_11168, LispObject v_11169)
{
    env = qenv(env);
    LispObject v_11180, v_11181;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11180 = v_11169;
    v_11181 = v_11168;
// end of prologue
    goto v_11176;
v_11172:
    goto v_11173;
v_11174:
    v_11180 = qcdr(v_11180);
    goto v_11175;
v_11176:
    goto v_11172;
v_11173:
    goto v_11174;
v_11175:
    return cons(v_11181, v_11180);
}



// Code for cl_nnf

static LispObject CC_cl_nnf(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11178, v_11179;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11178 = v_11168;
// end of prologue
    goto v_11175;
v_11171:
    v_11179 = v_11178;
    goto v_11172;
v_11173:
    v_11178 = lisp_true;
    goto v_11174;
v_11175:
    goto v_11171;
v_11172:
    goto v_11173;
v_11174:
    {
        fn = elt(env, 1); // cl_nnf1
        return (*qfn2(fn))(fn, v_11179, v_11178);
    }
}



// Code for simpqg

static LispObject CC_simpqg(LispObject env,
                         LispObject v_11168)
{
    env = qenv(env);
    LispObject v_11178, v_11179;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_11178 = v_11168;
// end of prologue
    goto v_11175;
v_11171:
    v_11179 = v_11178;
    goto v_11172;
v_11173:
    v_11178 = elt(env, 1); // qg
    goto v_11174;
v_11175:
    goto v_11171;
v_11172:
    goto v_11173;
v_11174:
    {
        fn = elt(env, 2); // simpcv
        return (*qfn2(fn))(fn, v_11179, v_11178);
    }
}



setup_type const u20_setup[] =
{
    {"subf1",                   TOO_FEW_2,      CC_subf1,      WRONG_NO_2},
    {"aex_fvarl",               CC_aex_fvarl,   TOO_MANY_1,    WRONG_NO_1},
    {"triplesetprolongset",     TOO_FEW_2,      CC_triplesetprolongset,WRONG_NO_2},
    {"simp*sq",                 CC_simpHsq,     TOO_MANY_1,    WRONG_NO_1},
    {"sfto_ucontentf1",         TOO_FEW_2,      CC_sfto_ucontentf1,WRONG_NO_2},
    {"talp_invn",               CC_talp_invn,   TOO_MANY_1,    WRONG_NO_1},
    {"lx2xx",                   CC_lx2xx,       TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_renewwl",           CC_ibalp_renewwl,TOO_MANY_1,   WRONG_NO_1},
    {"stats_getargs",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_stats_getargs},
    {"list-mgen",               CC_listKmgen,   TOO_MANY_1,    WRONG_NO_1},
    {"prinfit",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_prinfit},
    {"evalequal",               TOO_FEW_2,      CC_evalequal,  WRONG_NO_2},
    {"mv2sf1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mv2sf1},
    {"decprec2internal",        CC_decprec2internal,TOO_MANY_1,WRONG_NO_1},
    {"setk0",                   TOO_FEW_2,      CC_setk0,      WRONG_NO_2},
    {"print_with_margin_sub",   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_print_with_margin_sub},
    {"make_tuple_type",         CC_make_tuple_type,TOO_MANY_1, WRONG_NO_1},
    {"subsublis",               TOO_FEW_2,      CC_subsublis,  WRONG_NO_2},
    {"ibalp_var-unsatlist",     TOO_FEW_2,      CC_ibalp_varKunsatlist,WRONG_NO_2},
    {"dvfsf_susitf",            TOO_FEW_2,      CC_dvfsf_susitf,WRONG_NO_2},
    {"applyrd",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_applyrd},
    {"ps:minusp:",              CC_psTminuspT,  TOO_MANY_1,    WRONG_NO_1},
    {"arg2of2",                 TOO_FEW_2,      CC_arg2of2,    WRONG_NO_2},
    {"cut:mt",                  TOO_FEW_2,      CC_cutTmt,     WRONG_NO_2},
    {"lispassignp",             CC_lispassignp, TOO_MANY_1,    WRONG_NO_1},
    {"contr2-strand",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_contr2Kstrand},
    {"lpriw",                   TOO_FEW_2,      CC_lpriw,      WRONG_NO_2},
    {"rnminusp:",               CC_rnminuspT,   TOO_MANY_1,    WRONG_NO_1},
    {"qremd",                   TOO_FEW_2,      CC_qremd,      WRONG_NO_2},
    {"reverse-num",             CC_reverseKnum, TOO_MANY_1,    WRONG_NO_1},
    {"quotient-mod-p",          TOO_FEW_2,      CC_quotientKmodKp,WRONG_NO_2},
    {"traput",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_traput},
    {"rl_csimpl",               CC_rl_csimpl,   TOO_MANY_1,    WRONG_NO_1},
    {"lto_max1",                CC_lto_max1,    TOO_MANY_1,    WRONG_NO_1},
    {"dip_fmon",                TOO_FEW_2,      CC_dip_fmon,   WRONG_NO_2},
    {"merge-ind-vars",          TOO_FEW_2,      CC_mergeKindKvars,WRONG_NO_2},
    {"testredzz",               CC_testredzz,   TOO_MANY_1,    WRONG_NO_1},
    {"indexvarordp",            TOO_FEW_2,      CC_indexvarordp,WRONG_NO_2},
    {"inttovec-solve",          TOO_FEW_2,      CC_inttovecKsolve,WRONG_NO_2},
    {"expand-imrepart",         CC_expandKimrepart,TOO_MANY_1, WRONG_NO_1},
    {"begin1a",                 CC_begin1a,     TOO_MANY_1,    WRONG_NO_1},
    {"bas_newnumber",           TOO_FEW_2,      CC_bas_newnumber,WRONG_NO_2},
    {"cl_nnf",                  CC_cl_nnf,      TOO_MANY_1,    WRONG_NO_1},
    {"simpqg",                  CC_simpqg,      TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u20", (two_args *)"16573 1621790 4350908", 0}
};

// end of generated code
