
// $destdir/u45.c        Machine generated C code

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



// Code for gigcdsq

static LispObject CC_gigcdsq(LispObject env,
                         LispObject v_25615, LispObject v_25616)
{
    env = qenv(env);
    LispObject v_25689, v_25690;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25616,v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25615,v_25616);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_25616;
    stack[-1] = v_25615;
// end of prologue
    v_25689 = stack[-1];
    if (v_25689 == nil) goto v_25621;
    goto v_25628;
v_25624:
    v_25690 = stack[0];
    goto v_25625;
v_25626:
    v_25689 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25627;
v_25628:
    goto v_25624;
v_25625:
    goto v_25626;
v_25627:
    fn = elt(env, 1); // giintgcd
    v_25689 = (*qfn2(fn))(fn, v_25690, v_25689);
    env = stack[-3];
    stack[-2] = v_25689;
    goto v_25644;
v_25640:
    v_25690 = stack[-2];
    goto v_25641;
v_25642:
    v_25689 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25643;
v_25644:
    goto v_25640;
v_25641:
    goto v_25642;
v_25643:
    if (v_25690 == v_25689) goto v_25639;
    goto v_25652;
v_25648:
    goto v_25658;
v_25654:
    v_25690 = stack[-1];
    goto v_25655;
v_25656:
    v_25689 = stack[-2];
    goto v_25657;
v_25658:
    goto v_25654;
v_25655:
    goto v_25656;
v_25657:
    fn = elt(env, 1); // giintgcd
    v_25690 = (*qfn2(fn))(fn, v_25690, v_25689);
    env = stack[-3];
    stack[-2] = v_25690;
    goto v_25649;
v_25650:
    v_25689 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25651;
v_25652:
    goto v_25648;
v_25649:
    goto v_25650;
v_25651:
    v_25689 = Lneq(nil, v_25690, v_25689);
    env = stack[-3];
    goto v_25637;
v_25639:
    v_25689 = nil;
    goto v_25637;
    v_25689 = nil;
v_25637:
    if (v_25689 == nil) goto v_25635;
    goto v_25670;
v_25666:
    v_25690 = stack[-1];
    goto v_25667;
v_25668:
    v_25689 = stack[-2];
    goto v_25669;
v_25670:
    goto v_25666;
v_25667:
    goto v_25668;
v_25669:
    fn = elt(env, 2); // quotf
    v_25689 = (*qfn2(fn))(fn, v_25690, v_25689);
    env = stack[-3];
    stack[-1] = v_25689;
    goto v_25678;
v_25674:
    v_25690 = stack[0];
    goto v_25675;
v_25676:
    v_25689 = stack[-2];
    goto v_25677;
v_25678:
    goto v_25674;
v_25675:
    goto v_25676;
v_25677:
    fn = elt(env, 2); // quotf
    v_25689 = (*qfn2(fn))(fn, v_25690, v_25689);
    stack[0] = v_25689;
    goto v_25633;
v_25635:
v_25633:
    goto v_25619;
v_25621:
v_25619:
    goto v_25686;
v_25682:
    v_25690 = stack[-1];
    goto v_25683;
v_25684:
    v_25689 = stack[0];
    goto v_25685;
v_25686:
    goto v_25682;
v_25683:
    goto v_25684;
v_25685:
    return cons(v_25690, v_25689);
}



// Code for simpexpt2

static LispObject CC_simpexpt2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_26259, v_26260, v_26261;
    LispObject fn;
    LispObject v_25617, v_25616, v_25615;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "simpexpt2");
    va_start(aa, nargs);
    v_25615 = va_arg(aa, LispObject);
    v_25616 = va_arg(aa, LispObject);
    v_25617 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_25617,v_25616,v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_25615,v_25616,v_25617);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_25617;
    stack[-2] = v_25616;
    stack[-3] = v_25615;
// end of prologue
v_25614:
    stack[0] = nil;
    goto v_25632;
v_25628:
    v_26260 = stack[-3];
    goto v_25629;
v_25630:
    v_26259 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25631;
v_25632:
    goto v_25628;
v_25629:
    goto v_25630;
v_25631:
    if (v_26260 == v_26259) goto v_25626;
    else goto v_25627;
v_25626:
    goto v_25640;
v_25636:
    v_26260 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25637;
v_25638:
    v_26259 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25639;
v_25640:
    goto v_25636;
v_25637:
    goto v_25638;
v_25639:
    return cons(v_26260, v_26259);
v_25627:
    v_26259 = stack[-2];
    v_26259 = qcar(v_26259);
    stack[-4] = v_26259;
    v_26259 = stack[-3];
    v_26259 = Lconsp(nil, v_26259);
    env = stack[-5];
    if (v_26259 == nil) goto v_25648;
    goto v_25663;
v_25659:
    v_26259 = stack[-3];
    v_26260 = qcar(v_26259);
    goto v_25660;
v_25661:
    v_26259 = elt(env, 1); // expt
    goto v_25662;
v_25663:
    goto v_25659;
v_25660:
    goto v_25661;
v_25662:
    if (v_26260 == v_26259) goto v_25657;
    else goto v_25658;
v_25657:
    v_26259 = qvalue(elt(env, 2)); // !*precise_complex
    v_26259 = (v_26259 == nil ? lisp_true : nil);
    goto v_25656;
v_25658:
    v_26259 = nil;
    goto v_25656;
    v_26259 = nil;
v_25656:
    if (v_26259 == nil) goto v_25654;
    goto v_25677;
v_25673:
    v_26259 = stack[-3];
    v_26259 = qcdr(v_26259);
    v_26259 = qcdr(v_26259);
    v_26259 = qcar(v_26259);
    fn = elt(env, 14); // simp
    v_26260 = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    stack[-4] = v_26260;
    goto v_25674;
v_25675:
    v_26259 = stack[-2];
    goto v_25676;
v_25677:
    goto v_25673;
v_25674:
    goto v_25675;
v_25676:
    fn = elt(env, 15); // multsq
    v_26259 = (*qfn2(fn))(fn, v_26260, v_26259);
    env = stack[-5];
    stack[-2] = v_26259;
    v_26259 = qvalue(elt(env, 3)); // !*precise
    if (v_26259 == nil) goto v_25687;
    v_26259 = stack[-4];
    v_26259 = qcar(v_26259);
    if (is_number(v_26259)) goto v_25691;
    else goto v_25687;
v_25691:
    v_26259 = stack[-4];
    v_26259 = qcar(v_26259);
    v_26259 = Levenp(nil, v_26259);
    env = stack[-5];
    if (v_26259 == nil) goto v_25687;
    goto v_25703;
v_25699:
    v_26260 = elt(env, 4); // abs
    goto v_25700;
v_25701:
    v_26259 = stack[-3];
    v_26259 = qcdr(v_26259);
    v_26259 = qcar(v_26259);
    goto v_25702;
v_25703:
    goto v_25699;
v_25700:
    goto v_25701;
v_25702:
    v_26259 = list2(v_26260, v_26259);
    env = stack[-5];
    stack[-3] = v_26259;
    goto v_25685;
v_25687:
    v_26259 = stack[-3];
    v_26259 = qcdr(v_26259);
    v_26259 = qcar(v_26259);
    stack[-3] = v_26259;
    goto v_25685;
v_25685:
    goto v_25720;
v_25714:
    v_26261 = stack[-3];
    goto v_25715;
v_25716:
    v_26260 = stack[-2];
    goto v_25717;
v_25718:
    v_26259 = stack[-1];
    goto v_25719;
v_25720:
    goto v_25714;
v_25715:
    goto v_25716;
v_25717:
    goto v_25718;
v_25719:
    {
        fn = elt(env, 16); // simpexpt1
        return (*qfnn(fn))(fn, 3, v_26261, v_26260, v_26259);
    }
v_25654:
    goto v_25734;
v_25730:
    v_26259 = stack[-3];
    v_26260 = qcar(v_26259);
    goto v_25731;
v_25732:
    v_26259 = elt(env, 5); // sqrt
    goto v_25733;
v_25734:
    goto v_25730;
v_25731:
    goto v_25732;
v_25733:
    if (v_26260 == v_26259) goto v_25728;
    else goto v_25729;
v_25728:
    v_26259 = qvalue(elt(env, 6)); // !*keepsqrts
    v_26259 = (v_26259 == nil ? lisp_true : nil);
    goto v_25727;
v_25729:
    v_26259 = nil;
    goto v_25727;
    v_26259 = nil;
v_25727:
    if (v_26259 == nil) goto v_25725;
    goto v_25750;
v_25744:
    v_26259 = stack[-3];
    v_26259 = qcdr(v_26259);
    stack[0] = qcar(v_26259);
    goto v_25745;
v_25746:
    goto v_25759;
v_25755:
    goto v_25765;
v_25761:
    v_26260 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25762;
v_25763:
    v_26259 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_25764;
v_25765:
    goto v_25761;
v_25762:
    goto v_25763;
v_25764:
    v_26260 = cons(v_26260, v_26259);
    env = stack[-5];
    goto v_25756;
v_25757:
    v_26259 = stack[-2];
    goto v_25758;
v_25759:
    goto v_25755;
v_25756:
    goto v_25757;
v_25758:
    fn = elt(env, 15); // multsq
    v_26260 = (*qfn2(fn))(fn, v_26260, v_26259);
    env = stack[-5];
    goto v_25747;
v_25748:
    v_26259 = stack[-1];
    goto v_25749;
v_25750:
    goto v_25744;
v_25745:
    goto v_25746;
v_25747:
    goto v_25748;
v_25749:
    stack[-3] = stack[0];
    stack[-2] = v_26260;
    stack[-1] = v_26259;
    goto v_25614;
v_25725:
    goto v_25780;
v_25776:
    v_26259 = stack[-3];
    v_26260 = qcar(v_26259);
    goto v_25777;
v_25778:
    v_26259 = elt(env, 7); // times
    goto v_25779;
v_25780:
    goto v_25776;
v_25777:
    goto v_25778;
v_25779:
    if (v_26260 == v_26259) goto v_25774;
    else goto v_25775;
v_25774:
    v_26259 = qvalue(elt(env, 3)); // !*precise
    if (v_26259 == nil) goto v_25786;
    else goto v_25787;
v_25786:
    v_26259 = qvalue(elt(env, 8)); // !*modular
    v_26259 = (v_26259 == nil ? lisp_true : nil);
    goto v_25785;
v_25787:
    v_26259 = nil;
    goto v_25785;
    v_26259 = nil;
v_25785:
    goto v_25773;
v_25775:
    v_26259 = nil;
    goto v_25773;
    v_26259 = nil;
v_25773:
    if (v_26259 == nil) goto v_25771;
    goto v_25802;
v_25798:
    v_26260 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25799;
v_25800:
    v_26259 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25801;
v_25802:
    goto v_25798;
v_25799:
    goto v_25800;
v_25801:
    v_26259 = cons(v_26260, v_26259);
    env = stack[-5];
    stack[-4] = v_26259;
    v_26259 = stack[-3];
    v_26259 = qcdr(v_26259);
    stack[0] = v_26259;
v_25808:
    v_26259 = stack[0];
    if (v_26259 == nil) goto v_25813;
    else goto v_25814;
v_25813:
    goto v_25807;
v_25814:
    v_26259 = stack[0];
    v_26259 = qcar(v_26259);
    goto v_25825;
v_25821:
    goto v_25833;
v_25827:
    v_26261 = v_26259;
    goto v_25828;
v_25829:
    v_26260 = stack[-2];
    goto v_25830;
v_25831:
    v_26259 = stack[-1];
    goto v_25832;
v_25833:
    goto v_25827;
v_25828:
    goto v_25829;
v_25830:
    goto v_25831;
v_25832:
    fn = elt(env, 16); // simpexpt1
    v_26260 = (*qfnn(fn))(fn, 3, v_26261, v_26260, v_26259);
    env = stack[-5];
    goto v_25822;
v_25823:
    v_26259 = stack[-4];
    goto v_25824;
v_25825:
    goto v_25821;
v_25822:
    goto v_25823;
v_25824:
    fn = elt(env, 15); // multsq
    v_26259 = (*qfn2(fn))(fn, v_26260, v_26259);
    env = stack[-5];
    stack[-4] = v_26259;
    v_26259 = stack[0];
    v_26259 = qcdr(v_26259);
    stack[0] = v_26259;
    goto v_25808;
v_25807:
    v_26259 = stack[-4];
    goto v_25623;
v_25771:
    goto v_25851;
v_25847:
    v_26259 = stack[-3];
    v_26260 = qcar(v_26259);
    goto v_25848;
v_25849:
    v_26259 = elt(env, 7); // times
    goto v_25850;
v_25851:
    goto v_25847;
v_25848:
    goto v_25849;
v_25850:
    if (v_26260 == v_26259) goto v_25845;
    else goto v_25846;
v_25845:
    v_26259 = stack[-3];
    v_26259 = qcdr(v_26259);
    fn = elt(env, 17); // split!-sign
    v_26259 = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    stack[0] = v_26259;
    if (v_26259 == nil) goto v_25857;
    else goto v_25858;
v_25857:
    v_26259 = nil;
    goto v_25856;
v_25858:
    v_26259 = stack[0];
    v_26259 = qcar(v_26259);
    goto v_25856;
    v_26259 = nil;
v_25856:
    goto v_25844;
v_25846:
    v_26259 = nil;
    goto v_25844;
    v_26259 = nil;
v_25844:
    if (v_26259 == nil) goto v_25842;
    goto v_25877;
v_25871:
    goto v_25884;
v_25880:
    v_26259 = stack[0];
    v_26259 = qcdr(v_26259);
    v_26260 = qcar(v_26259);
    goto v_25881;
v_25882:
    v_26259 = stack[0];
    v_26259 = qcdr(v_26259);
    v_26259 = qcdr(v_26259);
    goto v_25883;
v_25884:
    goto v_25880;
v_25881:
    goto v_25882;
v_25883:
    v_26259 = Lappend(nil, v_26260, v_26259);
    env = stack[-5];
    fn = elt(env, 18); // retimes
    v_26261 = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    goto v_25872;
v_25873:
    v_26260 = stack[-2];
    goto v_25874;
v_25875:
    v_26259 = stack[-1];
    goto v_25876;
v_25877:
    goto v_25871;
v_25872:
    goto v_25873;
v_25874:
    goto v_25875;
v_25876:
    fn = elt(env, 16); // simpexpt1
    v_26259 = (*qfnn(fn))(fn, 3, v_26261, v_26260, v_26259);
    env = stack[-5];
    stack[-4] = v_26259;
    v_26259 = stack[0];
    v_26259 = qcar(v_26259);
    stack[0] = v_26259;
v_25896:
    v_26259 = stack[0];
    if (v_26259 == nil) goto v_25901;
    else goto v_25902;
v_25901:
    goto v_25895;
v_25902:
    v_26259 = stack[0];
    v_26259 = qcar(v_26259);
    goto v_25913;
v_25909:
    goto v_25921;
v_25915:
    v_26261 = v_26259;
    goto v_25916;
v_25917:
    v_26260 = stack[-2];
    goto v_25918;
v_25919:
    v_26259 = stack[-1];
    goto v_25920;
v_25921:
    goto v_25915;
v_25916:
    goto v_25917;
v_25918:
    goto v_25919;
v_25920:
    fn = elt(env, 16); // simpexpt1
    v_26260 = (*qfnn(fn))(fn, 3, v_26261, v_26260, v_26259);
    env = stack[-5];
    goto v_25910;
v_25911:
    v_26259 = stack[-4];
    goto v_25912;
v_25913:
    goto v_25909;
v_25910:
    goto v_25911;
v_25912:
    fn = elt(env, 15); // multsq
    v_26259 = (*qfn2(fn))(fn, v_26260, v_26259);
    env = stack[-5];
    stack[-4] = v_26259;
    v_26259 = stack[0];
    v_26259 = qcdr(v_26259);
    stack[0] = v_26259;
    goto v_25896;
v_25895:
    v_26259 = stack[-4];
    goto v_25623;
v_25842:
    goto v_25939;
v_25935:
    v_26259 = stack[-3];
    v_26260 = qcar(v_26259);
    goto v_25936;
v_25937:
    v_26259 = elt(env, 9); // quotient
    goto v_25938;
v_25939:
    goto v_25935;
v_25936:
    goto v_25937;
v_25938:
    if (v_26260 == v_26259) goto v_25933;
    else goto v_25934;
v_25933:
    v_26259 = qvalue(elt(env, 3)); // !*precise
    if (v_26259 == nil) goto v_25945;
    else goto v_25946;
v_25945:
    v_26259 = lisp_true;
    goto v_25944;
v_25946:
    v_26259 = stack[-3];
    v_26259 = qcdr(v_26259);
    v_26259 = qcdr(v_26259);
    v_26259 = qcar(v_26259);
    fn = elt(env, 19); // posnump
    v_26259 = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    if (v_26259 == nil) goto v_25953;
    else goto v_25954;
v_25953:
    v_26259 = nil;
    goto v_25952;
v_25954:
    v_26259 = stack[-2];
    fn = elt(env, 20); // prepsq
    v_26259 = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    fn = elt(env, 19); // posnump
    v_26259 = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    goto v_25952;
    v_26259 = nil;
v_25952:
    goto v_25944;
    v_26259 = nil;
v_25944:
    goto v_25932;
v_25934:
    v_26259 = nil;
    goto v_25932;
    v_26259 = nil;
v_25932:
    if (v_26259 == nil) goto v_25930;
    v_26259 = stack[-1];
    if (v_26259 == nil) goto v_25975;
    else goto v_25976;
v_25975:
    v_26259 = qvalue(elt(env, 10)); // !*mcd
    goto v_25974;
v_25976:
    v_26259 = nil;
    goto v_25974;
    v_26259 = nil;
v_25974:
    if (v_26259 == nil) goto v_25972;
    goto v_25989;
v_25983:
    v_26259 = stack[-3];
    fn = elt(env, 21); // simp!*
    v_26259 = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    fn = elt(env, 20); // prepsq
    v_26261 = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    goto v_25984;
v_25985:
    v_26260 = stack[-2];
    goto v_25986;
v_25987:
    v_26259 = lisp_true;
    goto v_25988;
v_25989:
    goto v_25983;
v_25984:
    goto v_25985;
v_25986:
    goto v_25987;
v_25988:
    {
        fn = elt(env, 16); // simpexpt1
        return (*qfnn(fn))(fn, 3, v_26261, v_26260, v_26259);
    }
v_25972:
    v_26259 = stack[-2];
    fn = elt(env, 20); // prepsq
    v_26259 = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    stack[-2] = v_26259;
    goto v_26002;
v_25998:
    goto v_26009;
v_26005:
    v_26259 = stack[-3];
    v_26259 = qcdr(v_26259);
    v_26260 = qcar(v_26259);
    goto v_26006;
v_26007:
    v_26259 = stack[-2];
    goto v_26008;
v_26009:
    goto v_26005;
v_26006:
    goto v_26007;
v_26008:
    v_26259 = list2(v_26260, v_26259);
    env = stack[-5];
    fn = elt(env, 22); // simpexpt
    stack[0] = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    goto v_25999;
v_26000:
    goto v_26020;
v_26016:
    v_26259 = stack[-3];
    v_26259 = qcdr(v_26259);
    v_26259 = qcdr(v_26259);
    v_26260 = qcar(v_26259);
    goto v_26017;
v_26018:
    v_26259 = stack[-2];
    goto v_26019;
v_26020:
    goto v_26016;
v_26017:
    goto v_26018;
v_26019:
    v_26259 = list2(v_26260, v_26259);
    env = stack[-5];
    fn = elt(env, 22); // simpexpt
    v_26259 = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    goto v_26001;
v_26002:
    goto v_25998;
v_25999:
    goto v_26000;
v_26001:
    {
        LispObject v_26267 = stack[0];
        fn = elt(env, 23); // quotsq
        return (*qfn2(fn))(fn, v_26267, v_26259);
    }
v_25930:
    goto v_26036;
v_26032:
    v_26259 = stack[-3];
    v_26260 = qcar(v_26259);
    goto v_26033;
v_26034:
    v_26259 = elt(env, 11); // minus
    goto v_26035;
v_26036:
    goto v_26032;
v_26033:
    goto v_26034;
v_26035:
    if (v_26260 == v_26259) goto v_26030;
    else goto v_26031;
v_26030:
    v_26259 = qvalue(elt(env, 3)); // !*precise
    if (v_26259 == nil) goto v_26042;
    else goto v_26043;
v_26042:
    goto v_26049;
v_26045:
    v_26259 = stack[-3];
    v_26259 = qcdr(v_26259);
    v_26260 = qcar(v_26259);
    goto v_26046;
v_26047:
    v_26259 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26048;
v_26049:
    goto v_26045;
v_26046:
    goto v_26047;
v_26048:
    v_26259 = (v_26260 == v_26259 ? lisp_true : nil);
    v_26259 = (v_26259 == nil ? lisp_true : nil);
    goto v_26041;
v_26043:
    v_26259 = nil;
    goto v_26041;
    v_26259 = nil;
v_26041:
    goto v_26029;
v_26031:
    v_26259 = nil;
    goto v_26029;
    v_26259 = nil;
v_26029:
    if (v_26259 == nil) goto v_26027;
    v_26259 = stack[-2];
    fn = elt(env, 20); // prepsq
    v_26259 = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    stack[-1] = v_26259;
    goto v_26070;
v_26066:
    goto v_26077;
v_26073:
    v_26260 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_26074;
v_26075:
    v_26259 = stack[-1];
    goto v_26076;
v_26077:
    goto v_26073;
v_26074:
    goto v_26075;
v_26076:
    v_26259 = list2(v_26260, v_26259);
    env = stack[-5];
    fn = elt(env, 22); // simpexpt
    stack[0] = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    goto v_26067;
v_26068:
    goto v_26086;
v_26082:
    v_26259 = stack[-3];
    v_26259 = qcdr(v_26259);
    v_26260 = qcar(v_26259);
    goto v_26083;
v_26084:
    v_26259 = stack[-1];
    goto v_26085;
v_26086:
    goto v_26082;
v_26083:
    goto v_26084;
v_26085:
    v_26259 = list2(v_26260, v_26259);
    env = stack[-5];
    fn = elt(env, 22); // simpexpt
    v_26259 = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    goto v_26069;
v_26070:
    goto v_26066;
v_26067:
    goto v_26068;
v_26069:
    {
        LispObject v_26268 = stack[0];
        fn = elt(env, 15); // multsq
        return (*qfn2(fn))(fn, v_26268, v_26259);
    }
v_26027:
    goto v_25646;
v_25648:
v_25646:
    v_26259 = stack[-1];
    if (v_26259 == nil) goto v_26093;
    else goto v_26094;
v_26093:
    v_26259 = qvalue(elt(env, 12)); // dmode!*
    if (v_26259 == nil) goto v_26098;
    v_26259 = stack[-3];
    if (symbolp(v_26259)) goto v_26103;
    else goto v_26098;
v_26103:
    goto v_26111;
v_26107:
    v_26260 = stack[-3];
    goto v_26108;
v_26109:
    v_26259 = qvalue(elt(env, 12)); // dmode!*
    goto v_26110;
v_26111:
    goto v_26107;
v_26108:
    goto v_26109;
v_26110:
    v_26259 = get(v_26260, v_26259);
    env = stack[-5];
    if (v_26259 == nil) goto v_26098;
    goto v_26099;
v_26098:
    v_26259 = stack[-3];
    fn = elt(env, 21); // simp!*
    v_26259 = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    fn = elt(env, 20); // prepsq
    v_26259 = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    stack[-3] = v_26259;
    goto v_26097;
v_26099:
v_26097:
    goto v_26124;
v_26118:
    v_26261 = stack[-3];
    goto v_26119;
v_26120:
    v_26260 = stack[-2];
    goto v_26121;
v_26122:
    v_26259 = lisp_true;
    goto v_26123;
v_26124:
    goto v_26118;
v_26119:
    goto v_26120;
v_26121:
    goto v_26122;
v_26123:
    {
        fn = elt(env, 16); // simpexpt1
        return (*qfnn(fn))(fn, 3, v_26261, v_26260, v_26259);
    }
v_26094:
    v_26259 = stack[-3];
    if (is_number(v_26259)) goto v_26130;
    else goto v_26129;
v_26130:
    v_26259 = stack[-3];
    v_26259 = (LispObject)zerop(v_26259);
    v_26259 = v_26259 ? lisp_true : nil;
    env = stack[-5];
    if (v_26259 == nil) goto v_26129;
    goto v_26140;
v_26136:
    v_26260 = nil;
    goto v_26137;
v_26138:
    v_26259 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26139;
v_26140:
    goto v_26136;
v_26137:
    goto v_26138;
v_26139:
    return cons(v_26260, v_26259);
v_26129:
    v_26259 = stack[-4];
    if (is_number(v_26259)) goto v_26144;
    v_26259 = stack[-4];
    fn = elt(env, 24); // prepf
    v_26259 = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    stack[-4] = v_26259;
    goto v_26092;
v_26144:
v_26092:
    v_26259 = stack[-2];
    v_26259 = qcdr(v_26259);
    fn = elt(env, 24); // prepf
    v_26259 = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    stack[-2] = v_26259;
    goto v_26160;
v_26156:
    v_26260 = stack[-4];
    goto v_26157;
v_26158:
    v_26259 = qvalue(elt(env, 13)); // frlis!*
    goto v_26159;
v_26160:
    goto v_26156;
v_26157:
    goto v_26158;
v_26159:
    v_26259 = Lmemq(nil, v_26260, v_26259);
    if (v_26259 == nil) goto v_26154;
    goto v_26169;
v_26165:
    v_26260 = stack[-2];
    goto v_26166;
v_26167:
    v_26259 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26168;
v_26169:
    goto v_26165;
v_26166:
    goto v_26167;
v_26168:
    if (v_26260 == v_26259) goto v_26164;
    else goto v_26154;
v_26164:
    goto v_26177;
v_26173:
    goto v_26186;
v_26180:
    v_26261 = stack[-3];
    goto v_26181;
v_26182:
    v_26260 = stack[-4];
    goto v_26183;
v_26184:
    v_26259 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26185;
v_26186:
    goto v_26180;
v_26181:
    goto v_26182;
v_26183:
    goto v_26184;
v_26185:
    v_26259 = acons(v_26261, v_26260, v_26259);
    env = stack[-5];
    v_26260 = ncons(v_26259);
    goto v_26174;
v_26175:
    v_26259 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26176;
v_26177:
    goto v_26173;
v_26174:
    goto v_26175;
v_26176:
    return cons(v_26260, v_26259);
v_26154:
    v_26259 = qvalue(elt(env, 10)); // !*mcd
    if (v_26259 == nil) goto v_26195;
    else goto v_26193;
v_26195:
    v_26259 = stack[-4];
    if (is_number(v_26259)) goto v_26201;
    v_26259 = lisp_true;
    goto v_26199;
v_26201:
    goto v_26214;
v_26210:
    v_26260 = stack[-2];
    goto v_26211;
v_26212:
    v_26259 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26213;
v_26214:
    goto v_26210;
v_26211:
    goto v_26212;
v_26213:
    if (v_26260 == v_26259) goto v_26209;
    v_26259 = lisp_true;
    goto v_26207;
v_26209:
    v_26259 = stack[-3];
    if (!consp(v_26259)) goto v_26222;
    else goto v_26223;
v_26222:
    v_26259 = lisp_true;
    goto v_26221;
v_26223:
    goto v_26233;
v_26229:
    v_26259 = stack[-3];
    fn = elt(env, 21); // simp!*
    v_26259 = (*qfn1(fn))(fn, v_26259);
    env = stack[-5];
    v_26260 = qcdr(v_26259);
    goto v_26230;
v_26231:
    v_26259 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26232;
v_26233:
    goto v_26229;
v_26230:
    goto v_26231;
v_26232:
    v_26259 = Lneq(nil, v_26260, v_26259);
    env = stack[-5];
    goto v_26221;
    v_26259 = nil;
v_26221:
    goto v_26207;
    v_26259 = nil;
v_26207:
    goto v_26199;
    v_26259 = nil;
v_26199:
    if (v_26259 == nil) goto v_26197;
    else goto v_26193;
v_26197:
    goto v_26194;
v_26193:
    goto v_26245;
v_26239:
    v_26261 = stack[-3];
    goto v_26240;
v_26241:
    v_26260 = stack[-4];
    goto v_26242;
v_26243:
    v_26259 = stack[-2];
    goto v_26244;
v_26245:
    goto v_26239;
v_26240:
    goto v_26241;
v_26242:
    goto v_26243;
v_26244:
    {
        fn = elt(env, 25); // simpx1
        return (*qfnn(fn))(fn, 3, v_26261, v_26260, v_26259);
    }
v_26194:
    goto v_26256;
v_26252:
    v_26260 = stack[-3];
    goto v_26253;
v_26254:
    v_26259 = stack[-4];
    goto v_26255;
v_26256:
    goto v_26252;
v_26253:
    goto v_26254;
v_26255:
    {
        fn = elt(env, 26); // mksq
        return (*qfn2(fn))(fn, v_26260, v_26259);
    }
    v_26259 = nil;
v_25623:
    return onevalue(v_26259);
}



// Code for enter!-sorted

static LispObject CC_enterKsorted(LispObject env,
                         LispObject v_25615, LispObject v_25616)
{
    env = qenv(env);
    LispObject v_25677, v_25678;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25616,v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25615,v_25616);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_25616;
    stack[-1] = v_25615;
// end of prologue
    stack[-2] = nil;
v_25621:
    v_25677 = stack[0];
    if (v_25677 == nil) goto v_25624;
    else goto v_25625;
v_25624:
    goto v_25632;
v_25628:
    stack[0] = stack[-2];
    goto v_25629;
v_25630:
    v_25677 = stack[-1];
    v_25677 = ncons(v_25677);
    env = stack[-3];
    goto v_25631;
v_25632:
    goto v_25628;
v_25629:
    goto v_25630;
v_25631:
    {
        LispObject v_25682 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_25682, v_25677);
    }
v_25625:
    goto v_25643;
v_25639:
    v_25677 = stack[-1];
    v_25678 = qcar(v_25677);
    goto v_25640;
v_25641:
    v_25677 = stack[0];
    v_25677 = qcar(v_25677);
    v_25677 = qcar(v_25677);
    goto v_25642;
v_25643:
    goto v_25639;
v_25640:
    goto v_25641;
v_25642:
    fn = elt(env, 2); // taydegree!<
    v_25677 = (*qfn2(fn))(fn, v_25678, v_25677);
    env = stack[-3];
    if (v_25677 == nil) goto v_25637;
    goto v_25654;
v_25650:
    goto v_25651;
v_25652:
    goto v_25661;
v_25657:
    v_25678 = stack[-1];
    goto v_25658;
v_25659:
    v_25677 = stack[0];
    goto v_25660;
v_25661:
    goto v_25657;
v_25658:
    goto v_25659;
v_25660:
    v_25677 = cons(v_25678, v_25677);
    env = stack[-3];
    goto v_25653;
v_25654:
    goto v_25650;
v_25651:
    goto v_25652;
v_25653:
    {
        LispObject v_25683 = stack[-2];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_25683, v_25677);
    }
v_25637:
    goto v_25671;
v_25667:
    v_25677 = stack[0];
    v_25678 = qcar(v_25677);
    goto v_25668;
v_25669:
    v_25677 = stack[-2];
    goto v_25670;
v_25671:
    goto v_25667;
v_25668:
    goto v_25669;
v_25670:
    v_25677 = cons(v_25678, v_25677);
    env = stack[-3];
    stack[-2] = v_25677;
    v_25677 = stack[0];
    v_25677 = qcdr(v_25677);
    stack[0] = v_25677;
    goto v_25621;
    v_25677 = nil;
    return onevalue(v_25677);
}



// Code for iv_cutn

static LispObject CC_iv_cutn(LispObject env,
                         LispObject v_25615)
{
    env = qenv(env);
    LispObject v_25638, v_25639;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25615);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_25639 = v_25615;
// end of prologue
    v_25638 = v_25639;
    v_25638 = qcdr(v_25638);
    if (v_25638 == nil) goto v_25620;
    goto v_25628;
v_25624:
    v_25638 = v_25639;
    stack[0] = qcar(v_25638);
    goto v_25625;
v_25626:
    v_25638 = v_25639;
    v_25638 = qcdr(v_25638);
    v_25638 = CC_iv_cutn(elt(env, 0), v_25638);
    env = stack[-1];
    goto v_25627;
v_25628:
    goto v_25624;
v_25625:
    goto v_25626;
v_25627:
    {
        LispObject v_25641 = stack[0];
        fn = elt(env, 1); // iv_cut
        return (*qfn2(fn))(fn, v_25641, v_25638);
    }
v_25620:
    v_25638 = v_25639;
    v_25638 = qcar(v_25638);
    goto v_25618;
    v_25638 = nil;
v_25618:
    return onevalue(v_25638);
}



// Code for conditionrd

static LispObject CC_conditionrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25651, v_25652, v_25653;
    LispObject fn;
    argcheck(nargs, 0, "conditionrd");
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
    fn = elt(env, 5); // mathml
    v_25651 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_25651;
    fn = elt(env, 6); // lex
    v_25651 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_25629;
v_25625:
    v_25652 = qvalue(elt(env, 1)); // char
    goto v_25626;
v_25627:
    v_25651 = elt(env, 2); // (!/ c o n d i t i o n)
    goto v_25628;
v_25629:
    goto v_25625;
v_25626:
    goto v_25627;
v_25628:
    if (equal(v_25652, v_25651)) goto v_25624;
    goto v_25637;
v_25633:
    v_25652 = elt(env, 3); // "</condition>"
    goto v_25634;
v_25635:
    v_25651 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_25636;
v_25637:
    goto v_25633;
v_25634:
    goto v_25635;
v_25636:
    fn = elt(env, 7); // errorml
    v_25651 = (*qfn2(fn))(fn, v_25652, v_25651);
    env = stack[-1];
    goto v_25622;
v_25624:
v_25622:
    goto v_25647;
v_25641:
    v_25653 = elt(env, 4); // condition
    goto v_25642;
v_25643:
    v_25652 = stack[0];
    goto v_25644;
v_25645:
    v_25651 = nil;
    goto v_25646;
v_25647:
    goto v_25641;
v_25642:
    goto v_25643;
v_25644:
    goto v_25645;
v_25646:
    return list2star(v_25653, v_25652, v_25651);
    return onevalue(v_25651);
}



// Code for znumrnil

static LispObject CC_znumrnil(LispObject env,
                         LispObject v_25615)
{
    env = qenv(env);
    LispObject v_25634, v_25635;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25615);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_25615;
// end of prologue
    v_25634 = stack[0];
    fn = elt(env, 1); // znumr
    v_25634 = (*qfn1(fn))(fn, v_25634);
    if (v_25634 == nil) goto v_25620;
    goto v_25628;
v_25624:
    v_25635 = nil;
    goto v_25625;
v_25626:
    v_25634 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25627;
v_25628:
    goto v_25624;
v_25625:
    goto v_25626;
v_25627:
    return cons(v_25635, v_25634);
v_25620:
    v_25634 = stack[0];
    goto v_25618;
    v_25634 = nil;
v_25618:
    return onevalue(v_25634);
}



// Code for diffp

static LispObject CC_diffp(LispObject env,
                         LispObject v_25615, LispObject v_25616)
{
    env = qenv(env);
    LispObject v_27173, v_27174, v_27175, v_27176, v_27177;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25616,v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25615,v_25616);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-7] = v_25616;
    stack[-8] = v_25615;
// end of prologue
    stack[0] = nil;
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    stack[-9] = v_27173;
    v_27173 = stack[-8];
    v_27173 = qcar(v_27173);
    stack[-8] = v_27173;
    goto v_25647;
v_25643:
    v_27174 = stack[-9];
    goto v_25644;
v_25645:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25646;
v_25647:
    goto v_25643;
v_25644:
    goto v_25645;
v_25646:
    v_27173 = (LispObject)greaterp2(v_27174, v_27173);
    v_27173 = v_27173 ? lisp_true : nil;
    env = stack[-10];
    if (v_27173 == nil) goto v_25640;
    v_27173 = stack[-8];
    fn = elt(env, 22); // noncomp
    v_27173 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    if (v_27173 == nil) goto v_25640;
    goto v_25658;
v_25654:
    goto v_25664;
v_25660:
    goto v_25671;
v_25667:
    v_27174 = stack[-8];
    goto v_25668;
v_25669:
    v_27173 = stack[-7];
    goto v_25670;
v_25671:
    goto v_25667;
v_25668:
    goto v_25669;
v_25670:
    v_27173 = list2(v_27174, v_27173);
    env = stack[-10];
    fn = elt(env, 23); // simpdf
    stack[-1] = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    goto v_25661;
v_25662:
    goto v_25680;
v_25676:
    stack[0] = stack[-8];
    goto v_25677;
v_25678:
    v_27173 = stack[-9];
    v_27173 = sub1(v_27173);
    env = stack[-10];
    goto v_25679;
v_25680:
    goto v_25676;
v_25677:
    goto v_25678;
v_25679:
    v_27173 = list2(stack[0], v_27173);
    env = stack[-10];
    fn = elt(env, 24); // simpexpt
    v_27173 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    goto v_25663;
v_25664:
    goto v_25660;
v_25661:
    goto v_25662;
v_25663:
    fn = elt(env, 25); // multsq
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_27173);
    env = stack[-10];
    goto v_25655;
v_25656:
    goto v_25689;
v_25685:
    goto v_25695;
v_25691:
    goto v_25702;
v_25698:
    goto v_25708;
v_25704:
    v_27174 = stack[-8];
    goto v_25705;
v_25706:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25707;
v_25708:
    goto v_25704;
v_25705:
    goto v_25706;
v_25707:
    fn = elt(env, 26); // to
    v_27174 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    goto v_25699;
v_25700:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25701;
v_25702:
    goto v_25698;
v_25699:
    goto v_25700;
v_25701:
    v_27173 = cons(v_27174, v_27173);
    env = stack[-10];
    v_27174 = ncons(v_27173);
    env = stack[-10];
    goto v_25692;
v_25693:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25694;
v_25695:
    goto v_25691;
v_25692:
    goto v_25693;
v_25694:
    stack[0] = cons(v_27174, v_27173);
    env = stack[-10];
    goto v_25686;
v_25687:
    goto v_25718;
v_25714:
    goto v_25724;
v_25720:
    stack[-2] = stack[-8];
    goto v_25721;
v_25722:
    v_27173 = stack[-9];
    v_27173 = sub1(v_27173);
    env = stack[-10];
    goto v_25723;
v_25724:
    goto v_25720;
v_25721:
    goto v_25722;
v_25723:
    v_27174 = cons(stack[-2], v_27173);
    env = stack[-10];
    goto v_25715;
v_25716:
    v_27173 = stack[-7];
    goto v_25717;
v_25718:
    goto v_25714;
v_25715:
    goto v_25716;
v_25717:
    v_27173 = CC_diffp(elt(env, 0), v_27174, v_27173);
    env = stack[-10];
    goto v_25688;
v_25689:
    goto v_25685;
v_25686:
    goto v_25687;
v_25688:
    fn = elt(env, 25); // multsq
    v_27173 = (*qfn2(fn))(fn, stack[0], v_27173);
    env = stack[-10];
    goto v_25657;
v_25658:
    goto v_25654;
v_25655:
    goto v_25656;
v_25657:
    {
        LispObject v_27188 = stack[-1];
        fn = elt(env, 27); // addsq
        return (*qfn2(fn))(fn, v_27188, v_27173);
    }
v_25640:
    goto v_25739;
v_25735:
    v_27174 = stack[-8];
    goto v_25736;
v_25737:
    v_27173 = stack[-7];
    goto v_25738;
v_25739:
    goto v_25735;
v_25736:
    goto v_25737;
v_25738:
    if (v_27174 == v_27173) goto v_25733;
    else goto v_25734;
v_25733:
    goto v_25747;
v_25743:
    v_27174 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25744;
v_25745:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25746;
v_25747:
    goto v_25743;
v_25744:
    goto v_25745;
v_25746:
    v_27173 = cons(v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_25732;
v_25734:
    v_27173 = nil;
    goto v_25732;
    v_27173 = nil;
v_25732:
    if (v_27173 == nil) goto v_25730;
    goto v_25628;
v_25730:
    v_27173 = stack[-8];
    if (!consp(v_27173)) goto v_25753;
    else goto v_25754;
v_25753:
    goto v_25629;
v_25754:
    v_27173 = stack[-8];
    v_27173 = qcar(v_27173);
    if (!consp(v_27173)) goto v_25762;
    goto v_25770;
v_25766:
    v_27174 = stack[-8];
    goto v_25767;
v_25768:
    v_27173 = stack[-7];
    goto v_25769;
v_25770:
    goto v_25766;
v_25767:
    goto v_25768;
v_25769:
    fn = elt(env, 28); // difff
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_25760;
v_25762:
    v_27173 = nil;
    goto v_25760;
    v_27173 = nil;
v_25760:
    if (v_27173 == nil) goto v_25758;
    else goto v_25756;
v_25758:
    goto v_25785;
v_25781:
    v_27173 = stack[-8];
    v_27174 = qcar(v_27173);
    goto v_25782;
v_25783:
    v_27173 = elt(env, 1); // !*sq
    goto v_25784;
v_25785:
    goto v_25781;
v_25782:
    goto v_25783;
v_25784:
    if (v_27174 == v_27173) goto v_25779;
    else goto v_25780;
v_25779:
    goto v_25794;
v_25790:
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    v_27174 = qcar(v_27173);
    goto v_25791;
v_25792:
    v_27173 = stack[-7];
    goto v_25793;
v_25794:
    goto v_25790;
v_25791:
    goto v_25792;
v_25793:
    fn = elt(env, 29); // diffsq
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_25778;
v_25780:
    v_27173 = nil;
    goto v_25778;
    v_27173 = nil;
v_25778:
    if (v_27173 == nil) goto v_25776;
    else goto v_25756;
v_25776:
    goto v_25757;
v_25756:
    goto v_25627;
v_25757:
    goto v_25809;
v_25805:
    v_27173 = stack[-8];
    v_27174 = qcar(v_27173);
    goto v_25806;
v_25807:
    v_27173 = elt(env, 2); // dfform
    goto v_25808;
v_25809:
    goto v_25805;
v_25806:
    goto v_25807;
v_25808:
    v_27173 = get(v_27174, v_27173);
    env = stack[-10];
    stack[-6] = v_27173;
    if (v_27173 == nil) goto v_25803;
    goto v_25822;
v_25814:
    v_27176 = stack[-6];
    goto v_25815;
v_25816:
    v_27175 = stack[-8];
    goto v_25817;
v_25818:
    v_27174 = stack[-7];
    goto v_25819;
v_25820:
    v_27173 = stack[-9];
    goto v_25821;
v_25822:
    goto v_25814;
v_25815:
    goto v_25816;
v_25817:
    goto v_25818;
v_25819:
    goto v_25820;
v_25821:
        return Lapply3(nil, 4, v_27176, v_27175, v_27174, v_27173);
v_25803:
    goto v_25834;
v_25830:
    v_27173 = stack[-8];
    stack[-1] = qcar(v_27173);
    goto v_25831;
v_25832:
    v_27173 = stack[-8];
    fn = elt(env, 30); // dfn_prop
    v_27173 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    goto v_25833;
v_25834:
    goto v_25830;
v_25831:
    goto v_25832;
v_25833:
    v_27173 = get(stack[-1], v_27173);
    env = stack[-10];
    stack[-6] = v_27173;
    if (v_27173 == nil) goto v_25828;
    goto v_25638;
v_25828:
    goto v_25850;
v_25846:
    v_27173 = stack[-8];
    v_27174 = qcar(v_27173);
    goto v_25847;
v_25848:
    v_27173 = elt(env, 3); // plus
    goto v_25849;
v_25850:
    goto v_25846;
v_25847:
    goto v_25848;
v_25849:
    if (v_27174 == v_27173) goto v_25844;
    else goto v_25845;
v_25844:
    goto v_25859;
v_25855:
    v_27173 = stack[-8];
    fn = elt(env, 31); // simp
    v_27174 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    goto v_25856;
v_25857:
    v_27173 = stack[-7];
    goto v_25858;
v_25859:
    goto v_25855;
v_25856:
    goto v_25857;
v_25858:
    fn = elt(env, 29); // diffsq
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_25843;
v_25845:
    v_27173 = nil;
    goto v_25843;
    v_27173 = nil;
v_25843:
    if (v_27173 == nil) goto v_25841;
    goto v_25627;
v_25841:
    goto v_25630;
v_25638:
    v_27173 = stack[-6];
    stack[-5] = v_27173;
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    stack[-4] = v_27173;
v_25626:
    goto v_25876;
v_25872:
    goto v_25882;
v_25878:
    v_27173 = stack[-4];
    v_27173 = qcar(v_27173);
    fn = elt(env, 31); // simp
    v_27174 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    goto v_25879;
v_25880:
    v_27173 = stack[-7];
    goto v_25881;
v_25882:
    goto v_25878;
v_25879:
    goto v_25880;
v_25881:
    fn = elt(env, 29); // diffsq
    v_27174 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    goto v_25873;
v_25874:
    v_27173 = stack[0];
    goto v_25875;
v_25876:
    goto v_25872;
v_25873:
    goto v_25874;
v_25875:
    v_27173 = cons(v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    v_27173 = stack[0];
    v_27173 = qcar(v_27173);
    v_27173 = qcar(v_27173);
    if (v_27173 == nil) goto v_25891;
    v_27173 = stack[-5];
    v_27173 = qcar(v_27173);
    if (v_27173 == nil) goto v_25896;
    else goto v_25891;
v_25896:
    goto v_25630;
v_25891:
    v_27173 = stack[-5];
    v_27173 = qcdr(v_27173);
    stack[-5] = v_27173;
    v_27173 = stack[-4];
    v_27173 = qcdr(v_27173);
    stack[-4] = v_27173;
    v_27173 = stack[-4];
    if (v_27173 == nil) goto v_25906;
    v_27173 = stack[-5];
    if (v_27173 == nil) goto v_25906;
    goto v_25626;
v_25906:
    v_27173 = stack[-4];
    if (v_27173 == nil) goto v_25913;
    else goto v_25911;
v_25913:
    v_27173 = stack[-5];
    if (v_27173 == nil) goto v_25915;
    else goto v_25911;
v_25915:
    goto v_25912;
v_25911:
    goto v_25630;
v_25912:
    v_27173 = stack[0];
    v_27173 = Lreverse(nil, v_27173);
    env = stack[-10];
    stack[-5] = v_27173;
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    stack[-4] = v_27173;
    goto v_25926;
v_25922:
    v_27174 = nil;
    goto v_25923;
v_25924:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25925;
v_25926:
    goto v_25922;
v_25923:
    goto v_25924;
v_25925:
    v_27173 = cons(v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
v_25931:
    v_27173 = stack[-5];
    v_27173 = qcar(v_27173);
    v_27173 = qcar(v_27173);
    if (v_27173 == nil) goto v_25935;
    goto v_25944;
v_25940:
    goto v_25950;
v_25946:
    v_27173 = stack[-5];
    stack[-1] = qcar(v_27173);
    goto v_25947;
v_25948:
    goto v_25959;
v_25955:
    goto v_25965;
v_25961:
    v_27173 = stack[-6];
    v_27173 = qcar(v_27173);
    v_27174 = qcar(v_27173);
    goto v_25962;
v_25963:
    v_27173 = stack[-4];
    goto v_25964;
v_25965:
    goto v_25961;
v_25962:
    goto v_25963;
v_25964:
    fn = elt(env, 32); // pair
    v_27174 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    goto v_25956;
v_25957:
    v_27173 = stack[-6];
    v_27173 = qcar(v_27173);
    v_27173 = qcdr(v_27173);
    goto v_25958;
v_25959:
    goto v_25955;
v_25956:
    goto v_25957;
v_25958:
    v_27173 = Lsubla(nil, v_27174, v_27173);
    env = stack[-10];
    fn = elt(env, 31); // simp
    v_27173 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    goto v_25949;
v_25950:
    goto v_25946;
v_25947:
    goto v_25948;
v_25949:
    fn = elt(env, 25); // multsq
    v_27174 = (*qfn2(fn))(fn, stack[-1], v_27173);
    env = stack[-10];
    goto v_25941;
v_25942:
    v_27173 = stack[0];
    goto v_25943;
v_25944:
    goto v_25940;
v_25941:
    goto v_25942;
v_25943:
    fn = elt(env, 27); // addsq
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_25933;
v_25935:
v_25933:
    v_27173 = stack[-6];
    v_27173 = qcdr(v_27173);
    stack[-6] = v_27173;
    v_27173 = stack[-5];
    v_27173 = qcdr(v_27173);
    stack[-5] = v_27173;
    v_27173 = stack[-5];
    if (v_27173 == nil) goto v_25981;
    goto v_25931;
v_25981:
v_25627:
v_25628:
    goto v_25991;
v_25987:
    v_27174 = stack[-8];
    goto v_25988;
v_25989:
    v_27173 = qvalue(elt(env, 4)); // wtl!*
    goto v_25990;
v_25991:
    goto v_25987;
v_25988:
    goto v_25989;
v_25990:
    v_27173 = Latsoc(nil, v_27174, v_27173);
    stack[-6] = v_27173;
    if (v_27173 == nil) goto v_25986;
    goto v_26000;
v_25996:
    goto v_26006;
v_26002:
    goto v_26013;
v_26009:
    goto v_26019;
v_26015:
    stack[-1] = elt(env, 5); // k!*
    goto v_26016;
v_26017:
    v_27173 = stack[-6];
    v_27173 = qcdr(v_27173);
    v_27173 = negate(v_27173);
    env = stack[-10];
    goto v_26018;
v_26019:
    goto v_26015;
v_26016:
    goto v_26017;
v_26018:
    fn = elt(env, 26); // to
    v_27174 = (*qfn2(fn))(fn, stack[-1], v_27173);
    env = stack[-10];
    goto v_26010;
v_26011:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26012;
v_26013:
    goto v_26009;
v_26010:
    goto v_26011;
v_26012:
    v_27173 = cons(v_27174, v_27173);
    env = stack[-10];
    v_27174 = ncons(v_27173);
    env = stack[-10];
    goto v_26003;
v_26004:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26005;
v_26006:
    goto v_26002;
v_26003:
    goto v_26004;
v_26005:
    v_27174 = cons(v_27174, v_27173);
    env = stack[-10];
    goto v_25997;
v_25998:
    v_27173 = stack[0];
    goto v_25999;
v_26000:
    goto v_25996;
v_25997:
    goto v_25998;
v_25999:
    fn = elt(env, 25); // multsq
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_25984;
v_25986:
v_25984:
    v_27173 = stack[-9];
    v_27173 = sub1(v_27173);
    env = stack[-10];
    stack[-3] = v_27173;
    goto v_26038;
v_26034:
    v_27174 = stack[-9];
    goto v_26035;
v_26036:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26037;
v_26038:
    goto v_26034;
v_26035:
    goto v_26036;
v_26037:
    if (v_27174 == v_27173) goto v_26032;
    else goto v_26033;
v_26032:
    v_27173 = stack[0];
    goto v_26031;
v_26033:
    v_27173 = qvalue(elt(env, 6)); // dmode!*
    if (!symbolp(v_27173)) v_27173 = nil;
    else { v_27173 = qfastgets(v_27173);
           if (v_27173 != nil) { v_27173 = elt(v_27173, 5); // convert
#ifdef RECORD_GET
             if (v_27173 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v_27173 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v_27173 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v_27173 == SPID_NOPROP) v_27173 = nil; else v_27173 = lisp_true; }}
#endif
    if (v_27173 == nil) goto v_26047;
    goto v_26056;
v_26052:
    v_27173 = qvalue(elt(env, 6)); // dmode!*
    if (!symbolp(v_27173)) v_27174 = nil;
    else { v_27174 = qfastgets(v_27173);
           if (v_27174 != nil) { v_27174 = elt(v_27174, 34); // i2d
#ifdef RECORD_GET
             if (v_27174 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_27174 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_27174 == SPID_NOPROP) v_27174 = nil; }}
#endif
    goto v_26053;
v_26054:
    v_27173 = stack[-9];
    goto v_26055;
v_26056:
    goto v_26052;
v_26053:
    goto v_26054;
v_26055:
    v_27173 = Lapply1(nil, v_27174, v_27173);
    env = stack[-10];
    fn = elt(env, 33); // int!-equiv!-chk
    v_27173 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    stack[-9] = v_27173;
    v_27173 = (v_27173 == nil ? lisp_true : nil);
    goto v_26045;
v_26047:
    v_27173 = nil;
    goto v_26045;
    v_27173 = nil;
v_26045:
    if (v_27173 == nil) goto v_26043;
    goto v_26069;
v_26065:
    v_27174 = nil;
    goto v_26066;
v_26067:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26068;
v_26069:
    goto v_26065;
v_26066:
    goto v_26067;
v_26068:
    v_27173 = cons(v_27174, v_27173);
    env = stack[-10];
    goto v_26031;
v_26043:
    goto v_26079;
v_26075:
    goto v_26085;
v_26081:
    goto v_26092;
v_26088:
    goto v_26098;
v_26094:
    v_27174 = stack[-8];
    goto v_26095;
v_26096:
    v_27173 = stack[-3];
    goto v_26097;
v_26098:
    goto v_26094;
v_26095:
    goto v_26096;
v_26097:
    fn = elt(env, 26); // to
    v_27174 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    goto v_26089;
v_26090:
    v_27173 = stack[-9];
    goto v_26091;
v_26092:
    goto v_26088;
v_26089:
    goto v_26090;
v_26091:
    v_27173 = cons(v_27174, v_27173);
    env = stack[-10];
    v_27174 = ncons(v_27173);
    env = stack[-10];
    goto v_26082;
v_26083:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26084;
v_26085:
    goto v_26081;
v_26082:
    goto v_26083;
v_26084:
    v_27174 = cons(v_27174, v_27173);
    env = stack[-10];
    goto v_26076;
v_26077:
    v_27173 = stack[0];
    goto v_26078;
v_26079:
    goto v_26075;
v_26076:
    goto v_26077;
v_26078:
    fn = elt(env, 25); // multsq
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    goto v_26031;
    v_27173 = nil;
v_26031:
    {
        fn = elt(env, 34); // rationalizesq
        return (*qfn1(fn))(fn, v_27173);
    }
v_25629:
    goto v_26117;
v_26113:
    v_27174 = stack[-8];
    goto v_26114;
v_26115:
    v_27173 = stack[-7];
    goto v_26116;
v_26117:
    goto v_26113;
v_26114:
    goto v_26115;
v_26116:
    fn = elt(env, 35); // depends
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    if (v_27173 == nil) goto v_26110;
    else goto v_26111;
v_26110:
    goto v_26132;
v_26128:
    v_27174 = stack[-8];
    goto v_26129;
v_26130:
    v_27173 = qvalue(elt(env, 7)); // powlis!*
    goto v_26131;
v_26132:
    goto v_26128;
v_26129:
    goto v_26130;
v_26131:
    v_27173 = Latsoc(nil, v_27174, v_27173);
    stack[-6] = v_27173;
    if (v_27173 == nil) goto v_26126;
    else goto v_26127;
v_26126:
    v_27173 = lisp_true;
    goto v_26125;
v_26127:
    goto v_26144;
v_26140:
    v_27173 = stack[-6];
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    v_27174 = qcar(v_27173);
    goto v_26141;
v_26142:
    v_27173 = stack[-7];
    goto v_26143;
v_26144:
    goto v_26140;
v_26141:
    goto v_26142;
v_26143:
    fn = elt(env, 35); // depends
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    v_27173 = (v_27173 == nil ? lisp_true : nil);
    goto v_26125;
    v_27173 = nil;
v_26125:
    if (v_27173 == nil) goto v_26123;
    v_27173 = qvalue(elt(env, 8)); // !*depend
    v_27173 = (v_27173 == nil ? lisp_true : nil);
    goto v_26121;
v_26123:
    v_27173 = nil;
    goto v_26121;
    v_27173 = nil;
v_26121:
    goto v_26109;
v_26111:
    v_27173 = nil;
    goto v_26109;
    v_27173 = nil;
v_26109:
    if (v_27173 == nil) goto v_26107;
    goto v_26165;
v_26161:
    v_27174 = nil;
    goto v_26162;
v_26163:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26164;
v_26165:
    goto v_26161;
v_26162:
    goto v_26163;
v_26164:
    return cons(v_27174, v_27173);
v_26107:
    v_27173 = qvalue(elt(env, 9)); // !*expanddf
    if (v_27173 == nil) goto v_26171;
    goto v_26187;
v_26183:
    v_27174 = stack[-8];
    goto v_26184;
v_26185:
    v_27173 = qvalue(elt(env, 7)); // powlis!*
    goto v_26186;
v_26187:
    goto v_26183;
v_26184:
    goto v_26185;
v_26186:
    v_27173 = Latsoc(nil, v_27174, v_27173);
    stack[-6] = v_27173;
    if (v_27173 == nil) goto v_26181;
    else goto v_26182;
v_26181:
    v_27173 = lisp_true;
    goto v_26180;
v_26182:
    goto v_26199;
v_26195:
    v_27173 = stack[-6];
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    v_27174 = qcar(v_27173);
    goto v_26196;
v_26197:
    v_27173 = stack[-7];
    goto v_26198;
v_26199:
    goto v_26195;
v_26196:
    goto v_26197;
v_26198:
    fn = elt(env, 35); // depends
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    v_27173 = (v_27173 == nil ? lisp_true : nil);
    goto v_26180;
    v_27173 = nil;
v_26180:
    if (v_27173 == nil) goto v_26178;
    goto v_26215;
v_26211:
    v_27174 = stack[-8];
    goto v_26212;
v_26213:
    v_27173 = qvalue(elt(env, 10)); // depl!*
    goto v_26214;
v_26215:
    goto v_26211;
v_26212:
    goto v_26213;
v_26214:
    v_27173 = Latsoc(nil, v_27174, v_27173);
    stack[-6] = v_27173;
    if (v_27173 == nil) goto v_26209;
    else goto v_26210;
v_26209:
    v_27173 = nil;
    goto v_26208;
v_26210:
    goto v_26226;
v_26222:
    v_27174 = stack[-7];
    goto v_26223;
v_26224:
    v_27173 = stack[-6];
    v_27173 = qcdr(v_27173);
    stack[-6] = v_27173;
    goto v_26225;
v_26226:
    goto v_26222;
v_26223:
    goto v_26224;
v_26225:
    v_27173 = Lmemq(nil, v_27174, v_27173);
    v_27173 = (v_27173 == nil ? lisp_true : nil);
    goto v_26208;
    v_27173 = nil;
v_26208:
    goto v_26176;
v_26178:
    v_27173 = nil;
    goto v_26176;
    v_27173 = nil;
v_26176:
    if (v_27173 == nil) goto v_26171;
    goto v_26242;
v_26236:
    v_27175 = stack[-8];
    goto v_26237;
v_26238:
    v_27174 = stack[-7];
    goto v_26239;
v_26240:
    v_27173 = stack[-6];
    goto v_26241;
v_26242:
    goto v_26236;
v_26237:
    goto v_26238;
v_26239:
    goto v_26240;
v_26241:
    fn = elt(env, 36); // df!-chain!-rule
    v_27173 = (*qfnn(fn))(fn, 3, v_27175, v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_25628;
v_26171:
    goto v_26253;
v_26247:
    v_27175 = elt(env, 11); // df
    goto v_26248;
v_26249:
    v_27174 = stack[-8];
    goto v_26250;
v_26251:
    v_27173 = stack[-7];
    goto v_26252;
v_26253:
    goto v_26247;
v_26248:
    goto v_26249;
v_26250:
    goto v_26251;
v_26252:
    v_27173 = list3(v_27175, v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    v_27173 = stack[0];
    fn = elt(env, 37); // opmtch
    v_27173 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    stack[-6] = v_27173;
    if (v_27173 == nil) goto v_26260;
    v_27173 = stack[-6];
    fn = elt(env, 31); // simp
    v_27173 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    goto v_26258;
v_26260:
    goto v_26272;
v_26268:
    v_27174 = stack[0];
    goto v_26269;
v_26270:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26271;
v_26272:
    goto v_26268;
v_26269:
    goto v_26270;
v_26271:
    fn = elt(env, 38); // mksq
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    goto v_26258;
    v_27173 = nil;
v_26258:
    stack[0] = v_27173;
    goto v_25628;
v_25630:
    goto v_26283;
v_26279:
    v_27173 = stack[-8];
    v_27174 = qcar(v_27173);
    goto v_26280;
v_26281:
    v_27173 = elt(env, 11); // df
    goto v_26282;
v_26283:
    goto v_26279;
v_26280:
    goto v_26281;
v_26282:
    if (v_27174 == v_27173) goto v_26277;
    else goto v_26278;
v_26277:
    goto v_26295;
v_26291:
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    v_27174 = qcar(v_27173);
    goto v_26292;
v_26293:
    v_27173 = stack[-7];
    goto v_26294;
v_26295:
    goto v_26291;
v_26292:
    goto v_26293;
v_26294:
    if (v_27174 == v_27173) goto v_26289;
    else goto v_26290;
v_26289:
    v_27173 = qvalue(elt(env, 12)); // !*commutedf
    if (v_27173 == nil) goto v_26303;
    v_27173 = qvalue(elt(env, 8)); // !*depend
    if (v_27173 == nil) goto v_26306;
    else goto v_26303;
v_26306:
    goto v_26313;
v_26309:
    v_27174 = nil;
    goto v_26310;
v_26311:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26312;
v_26313:
    goto v_26309;
v_26310:
    goto v_26311;
v_26312:
    return cons(v_27174, v_27173);
v_26303:
    v_27173 = qvalue(elt(env, 13)); // !*simpnoncomdf
    if (v_27173 == nil) goto v_26317;
    goto v_26326;
v_26322:
    v_27174 = stack[-7];
    goto v_26323;
v_26324:
    v_27173 = qvalue(elt(env, 10)); // depl!*
    goto v_26325;
v_26326:
    goto v_26322;
v_26323:
    goto v_26324;
v_26325:
    v_27173 = Latsoc(nil, v_27174, v_27173);
    stack[0] = v_27173;
    if (v_27173 == nil) goto v_26317;
    v_27173 = stack[0];
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    if (v_27173 == nil) goto v_26330;
    else goto v_26317;
v_26330:
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    v_27173 = qcar(v_27173);
    stack[-6] = v_27173;
    goto v_26343;
v_26339:
    goto v_26352;
v_26346:
    v_27175 = elt(env, 11); // df
    goto v_26347;
v_26348:
    v_27174 = stack[-8];
    goto v_26349;
v_26350:
    v_27173 = stack[-6];
    goto v_26351;
v_26352:
    goto v_26346;
v_26347:
    goto v_26348;
v_26349:
    goto v_26350;
v_26351:
    v_27173 = list3(v_27175, v_27174, v_27173);
    env = stack[-10];
    fn = elt(env, 31); // simp
    stack[0] = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    goto v_26340;
v_26341:
    goto v_26364;
v_26358:
    v_27175 = elt(env, 11); // df
    goto v_26359;
v_26360:
    v_27174 = stack[-7];
    goto v_26361;
v_26362:
    v_27173 = stack[-6];
    goto v_26363;
v_26364:
    goto v_26358;
v_26359:
    goto v_26360;
v_26361:
    goto v_26362;
v_26363:
    v_27173 = list3(v_27175, v_27174, v_27173);
    env = stack[-10];
    fn = elt(env, 31); // simp
    v_27173 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    goto v_26342;
v_26343:
    goto v_26339;
v_26340:
    goto v_26341;
v_26342:
    fn = elt(env, 39); // quotsq
    v_27173 = (*qfn2(fn))(fn, stack[0], v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_25628;
v_26317:
    goto v_26288;
v_26290:
    goto v_26375;
v_26371:
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    v_27174 = qcar(v_27173);
    goto v_26372;
v_26373:
    v_27173 = elt(env, 14); // int
    goto v_26374;
v_26375:
    goto v_26371;
v_26372:
    goto v_26373;
v_26374:
    if (!consp(v_27174)) goto v_26369;
    v_27174 = qcar(v_27174);
    if (v_27174 == v_27173) goto v_26368;
    else goto v_26369;
v_26368:
    goto v_26388;
v_26384:
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    v_27173 = qcar(v_27173);
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    v_27174 = qcar(v_27173);
    goto v_26385;
v_26386:
    v_27173 = stack[-7];
    goto v_26387;
v_26388:
    goto v_26384;
v_26385:
    goto v_26386;
v_26387:
    if (v_27174 == v_27173) goto v_26382;
    else goto v_26383;
v_26382:
    goto v_26403;
v_26397:
    v_27175 = elt(env, 11); // df
    goto v_26398;
v_26399:
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    v_27173 = qcar(v_27173);
    v_27173 = qcdr(v_27173);
    v_27174 = qcar(v_27173);
    goto v_26400;
v_26401:
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    goto v_26402;
v_26403:
    goto v_26397;
v_26398:
    goto v_26399;
v_26400:
    goto v_26401;
v_26402:
    v_27173 = list2star(v_27175, v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_25631;
v_26383:
    v_27173 = qvalue(elt(env, 15)); // !*allowdfint
    if (v_27173 == nil) goto v_26414;
    goto v_26424;
v_26420:
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    v_27173 = qcar(v_27173);
    v_27173 = qcdr(v_27173);
    v_27173 = qcar(v_27173);
    fn = elt(env, 40); // simp!*
    v_27174 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    goto v_26421;
v_26422:
    v_27173 = stack[-7];
    goto v_26423;
v_26424:
    goto v_26420;
v_26421:
    goto v_26422;
v_26423:
    fn = elt(env, 29); // diffsq
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    fn = elt(env, 41); // not_df_p
    v_27173 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    if (v_27173 == nil) goto v_26414;
    goto v_26439;
v_26433:
    stack[-2] = elt(env, 11); // df
    goto v_26434;
v_26435:
    goto v_26449;
v_26443:
    stack[-1] = elt(env, 14); // int
    goto v_26444;
v_26445:
    v_27173 = stack[0];
    fn = elt(env, 42); // mk!*sq
    v_27174 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    goto v_26446;
v_26447:
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    v_27173 = qcar(v_27173);
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    v_27173 = qcar(v_27173);
    goto v_26448;
v_26449:
    goto v_26443;
v_26444:
    goto v_26445;
v_26446:
    goto v_26447;
v_26448:
    v_27173 = list3(stack[-1], v_27174, v_27173);
    env = stack[-10];
    fn = elt(env, 43); // reval
    v_27174 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    goto v_26436;
v_26437:
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    goto v_26438;
v_26439:
    goto v_26433;
v_26434:
    goto v_26435;
v_26436:
    goto v_26437;
v_26438:
    v_27173 = list2star(stack[-2], v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_25631;
v_26414:
    goto v_26288;
v_26369:
v_26288:
    v_27173 = qvalue(elt(env, 9)); // !*expanddf
    if (v_27173 == nil) goto v_26465;
    goto v_26475;
v_26471:
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    v_27174 = qcar(v_27173);
    goto v_26472;
v_26473:
    v_27173 = stack[-7];
    goto v_26474;
v_26475:
    goto v_26471;
v_26472:
    goto v_26473;
v_26474:
    fn = elt(env, 35); // depends
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    if (v_27173 == nil) goto v_26465;
    goto v_26489;
v_26485:
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    v_27174 = qcar(v_27173);
    goto v_26486;
v_26487:
    v_27173 = qvalue(elt(env, 7)); // powlis!*
    goto v_26488;
v_26489:
    goto v_26485;
v_26486:
    goto v_26487;
v_26488:
    v_27173 = Latsoc(nil, v_27174, v_27173);
    stack[-6] = v_27173;
    if (v_27173 == nil) goto v_26483;
    else goto v_26484;
v_26483:
    v_27173 = lisp_true;
    goto v_26482;
v_26484:
    goto v_26503;
v_26499:
    v_27173 = stack[-6];
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    v_27174 = qcar(v_27173);
    goto v_26500;
v_26501:
    v_27173 = stack[-7];
    goto v_26502;
v_26503:
    goto v_26499;
v_26500:
    goto v_26501;
v_26502:
    fn = elt(env, 35); // depends
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    v_27173 = (v_27173 == nil ? lisp_true : nil);
    goto v_26482;
    v_27173 = nil;
v_26482:
    if (v_27173 == nil) goto v_26465;
    goto v_26520;
v_26516:
    v_27174 = stack[-7];
    goto v_26517;
v_26518:
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    v_27173 = qcar(v_27173);
    goto v_26519;
v_26520:
    goto v_26516;
v_26517:
    goto v_26518;
v_26519:
    fn = elt(env, 44); // smember
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    if (v_27173 == nil) goto v_26513;
    else goto v_26514;
v_26513:
    goto v_26529;
v_26525:
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    v_27174 = qcar(v_27173);
    goto v_26526;
v_26527:
    v_27173 = qvalue(elt(env, 10)); // depl!*
    goto v_26528;
v_26529:
    goto v_26525;
v_26526:
    goto v_26527;
v_26528:
    v_27173 = Lassoc(nil, v_27174, v_27173);
    stack[-6] = v_27173;
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    v_27173 = qcar(v_27173);
    if (!consp(v_27173)) goto v_26538;
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    v_27173 = qcar(v_27173);
    v_27173 = qcdr(v_27173);
    if (v_27173 == nil) goto v_26544;
    else goto v_26545;
v_26544:
    v_27173 = nil;
    goto v_26543;
v_26545:
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    v_27173 = qcar(v_27173);
    v_27173 = qcdr(v_27173);
    fn = elt(env, 45); // get!-all!-kernels
    v_27173 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    goto v_26543;
    v_27173 = nil;
v_26543:
    goto v_26536;
v_26538:
    v_27173 = nil;
    goto v_26536;
    v_27173 = nil;
v_26536:
    stack[-5] = v_27173;
    v_27173 = stack[-6];
    if (v_27173 == nil) goto v_26564;
    v_27173 = stack[-5];
    if (v_27173 == nil) goto v_26564;
    goto v_26576;
v_26572:
    goto v_26582;
v_26578:
    v_27174 = stack[-7];
    goto v_26579;
v_26580:
    v_27173 = stack[-5];
    goto v_26581;
v_26582:
    goto v_26578;
v_26579:
    goto v_26580;
v_26581:
    v_27174 = Ldelete(nil, v_27174, v_27173);
    env = stack[-10];
    goto v_26573;
v_26574:
    v_27173 = stack[-7];
    goto v_26575;
v_26576:
    goto v_26572;
v_26573:
    goto v_26574;
v_26575:
    fn = elt(env, 46); // ldepends
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    if (v_27173 == nil) goto v_26564;
    goto v_26562;
v_26564:
    v_27173 = stack[-6];
    if (v_27173 == nil) goto v_26588;
    goto v_26596;
v_26592:
    v_27174 = stack[-7];
    goto v_26593;
v_26594:
    v_27173 = stack[-6];
    v_27173 = qcdr(v_27173);
    stack[-6] = v_27173;
    goto v_26595;
v_26596:
    goto v_26592;
v_26593:
    goto v_26594;
v_26595:
    v_27173 = Lmemq(nil, v_27174, v_27173);
    if (v_27173 == nil) goto v_26591;
    else goto v_26588;
v_26591:
    goto v_26608;
v_26602:
    v_27175 = stack[-8];
    goto v_26603;
v_26604:
    v_27174 = stack[-7];
    goto v_26605;
v_26606:
    v_27173 = stack[-6];
    goto v_26607;
v_26608:
    goto v_26602;
v_26603:
    goto v_26604;
v_26605:
    goto v_26606;
v_26607:
    fn = elt(env, 36); // df!-chain!-rule
    v_27173 = (*qfnn(fn))(fn, 3, v_27175, v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_25628;
v_26588:
    v_27173 = stack[-5];
    if (v_27173 == nil) goto v_26613;
    goto v_26622;
v_26618:
    v_27174 = stack[-7];
    goto v_26619;
v_26620:
    v_27173 = stack[-5];
    goto v_26621;
v_26622:
    goto v_26618;
v_26619:
    goto v_26620;
v_26621:
    fn = elt(env, 44); // smember
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    if (v_27173 == nil) goto v_26616;
    else goto v_26613;
v_26616:
    goto v_26632;
v_26626:
    v_27175 = stack[-8];
    goto v_26627;
v_26628:
    v_27174 = stack[-7];
    goto v_26629;
v_26630:
    v_27173 = stack[-5];
    goto v_26631;
v_26632:
    goto v_26626;
v_26627:
    goto v_26628;
v_26629:
    goto v_26630;
v_26631:
    fn = elt(env, 36); // df!-chain!-rule
    v_27173 = (*qfnn(fn))(fn, 3, v_27175, v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_25628;
v_26613:
v_26562:
    goto v_26512;
v_26514:
v_26512:
    goto v_26463;
v_26465:
v_26463:
    goto v_26645;
v_26641:
    goto v_26651;
v_26647:
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    stack[0] = qcar(v_27173);
    goto v_26648;
v_26649:
    goto v_26660;
v_26656:
    v_27174 = stack[-8];
    goto v_26657;
v_26658:
    v_27173 = stack[-7];
    goto v_26659;
v_26660:
    goto v_26656;
v_26657:
    goto v_26658;
v_26659:
    fn = elt(env, 47); // merge!-ind!-vars
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    goto v_26650;
v_26651:
    goto v_26647;
v_26648:
    goto v_26649;
v_26650:
    v_27174 = cons(stack[0], v_27173);
    env = stack[-10];
    stack[0] = v_27174;
    goto v_26642;
v_26643:
    v_27173 = elt(env, 11); // df
    if (!symbolp(v_27173)) v_27173 = nil;
    else { v_27173 = qfastgets(v_27173);
           if (v_27173 != nil) { v_27173 = elt(v_27173, 50); // kvalue
#ifdef RECORD_GET
             if (v_27173 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v_27173 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v_27173 == SPID_NOPROP) v_27173 = nil; }}
#endif
    goto v_26644;
v_26645:
    goto v_26641;
v_26642:
    goto v_26643;
v_26644:
    fn = elt(env, 48); // find_sub_df
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    stack[-6] = v_27173;
    if (v_27173 == nil) goto v_26639;
    v_27173 = stack[-6];
    v_27173 = qcar(v_27173);
    fn = elt(env, 31); // simp
    v_27173 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    v_27173 = stack[-6];
    v_27173 = qcdr(v_27173);
    stack[-3] = v_27173;
v_26671:
    v_27173 = stack[-3];
    if (v_27173 == nil) goto v_26676;
    else goto v_26677;
v_26676:
    goto v_26670;
v_26677:
    v_27173 = stack[-3];
    v_27173 = qcar(v_27173);
    stack[-2] = v_27173;
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_27173;
v_26686:
    goto v_26698;
v_26694:
    v_27173 = stack[-2];
    v_27174 = qcdr(v_27173);
    goto v_26695;
v_26696:
    v_27173 = stack[-1];
    goto v_26697;
v_26698:
    goto v_26694;
v_26695:
    goto v_26696;
v_26697:
    v_27173 = difference2(v_27174, v_27173);
    env = stack[-10];
    v_27173 = Lminusp(nil, v_27173);
    env = stack[-10];
    if (v_27173 == nil) goto v_26691;
    goto v_26685;
v_26691:
    goto v_26708;
v_26704:
    v_27174 = stack[0];
    goto v_26705;
v_26706:
    v_27173 = stack[-2];
    v_27173 = qcar(v_27173);
    goto v_26707;
v_26708:
    goto v_26704;
v_26705:
    goto v_26706;
v_26707:
    fn = elt(env, 29); // diffsq
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    v_27173 = stack[-1];
    v_27173 = add1(v_27173);
    env = stack[-10];
    stack[-1] = v_27173;
    goto v_26686;
v_26685:
    v_27173 = stack[-3];
    v_27173 = qcdr(v_27173);
    stack[-3] = v_27173;
    goto v_26671;
v_26670:
    goto v_25628;
v_26639:
    goto v_26723;
v_26719:
    v_27174 = elt(env, 11); // df
    goto v_26720;
v_26721:
    v_27173 = stack[0];
    goto v_26722;
v_26723:
    goto v_26719;
v_26720:
    goto v_26721;
v_26722:
    v_27173 = cons(v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_26637;
v_26637:
    goto v_26276;
v_26278:
    v_27173 = qvalue(elt(env, 16)); // !*df_partial
    if (v_27173 == nil) goto v_26727;
    v_27173 = qvalue(elt(env, 9)); // !*expanddf
    if (v_27173 == nil) goto v_26727;
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    v_27173 = qcar(v_27173);
    if (!consp(v_27173)) goto v_26727;
    goto v_26744;
v_26740:
    v_27173 = stack[-8];
    v_27173 = qcar(v_27173);
    v_27174 = Lexplode(nil, v_27173);
    env = stack[-10];
    goto v_26741;
v_26742:
    v_27173 = elt(env, 17); // (!! !! !_)
    goto v_26743;
v_26744:
    goto v_26740;
v_26741:
    goto v_26742;
v_26743:
    v_27173 = Lnconc(nil, v_27174, v_27173);
    env = stack[-10];
    v_27173 = Lcompress(nil, v_27173);
    env = stack[-10];
    v_27173 = Lintern(nil, v_27173);
    env = stack[-10];
    stack[-6] = v_27173;
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    stack[-5] = v_27173;
    goto v_26756;
v_26752:
    v_27174 = nil;
    goto v_26753;
v_26754:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26755;
v_26756:
    goto v_26752;
v_26753:
    goto v_26754;
v_26755:
    v_27173 = cons(v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    v_27173 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_27173;
    v_27173 = stack[-5];
    stack[-2] = v_27173;
v_26763:
    v_27173 = stack[-2];
    if (v_27173 == nil) goto v_26767;
    else goto v_26768;
v_26767:
    goto v_26762;
v_26768:
    v_27173 = stack[-2];
    v_27173 = qcar(v_27173);
    stack[-1] = v_27173;
    v_27173 = stack[-3];
    v_27173 = add1(v_27173);
    env = stack[-10];
    stack[-3] = v_27173;
    goto v_26791;
v_26785:
    v_27175 = elt(env, 11); // df
    goto v_26786;
v_26787:
    v_27174 = stack[-1];
    goto v_26788;
v_26789:
    v_27173 = stack[-7];
    goto v_26790;
v_26791:
    goto v_26785;
v_26786:
    goto v_26787;
v_26788:
    goto v_26789;
v_26790:
    v_27173 = list3(v_27175, v_27174, v_27173);
    env = stack[-10];
    fn = elt(env, 31); // simp
    v_27173 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    stack[-1] = v_27173;
    v_27173 = qcar(v_27173);
    if (v_27173 == nil) goto v_26782;
    goto v_26801;
v_26797:
    v_27174 = stack[-6];
    goto v_26798;
v_26799:
    v_27173 = stack[-3];
    goto v_26800;
v_26801:
    goto v_26797;
v_26798:
    goto v_26799;
v_26800:
    fn = elt(env, 49); // mkid
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    stack[-4] = v_27173;
    goto v_26811;
v_26805:
    v_27175 = stack[-4];
    goto v_26806;
v_26807:
    v_27174 = elt(env, 18); // simpfn
    goto v_26808;
v_26809:
    v_27173 = elt(env, 19); // simpiden
    goto v_26810;
v_26811:
    goto v_26805;
v_26806:
    goto v_26807;
v_26808:
    goto v_26809;
v_26810:
    v_27173 = Lputprop(nil, 3, v_27175, v_27174, v_27173);
    env = stack[-10];
    goto v_26820;
v_26816:
    goto v_26817;
v_26818:
    goto v_26827;
v_26823:
    goto v_26834;
v_26830:
    v_27174 = stack[-4];
    goto v_26831;
v_26832:
    v_27173 = stack[-5];
    goto v_26833;
v_26834:
    goto v_26830;
v_26831:
    goto v_26832;
v_26833:
    v_27173 = cons(v_27174, v_27173);
    env = stack[-10];
    fn = elt(env, 31); // simp
    v_27174 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    goto v_26824;
v_26825:
    v_27173 = stack[-1];
    goto v_26826;
v_26827:
    goto v_26823;
v_26824:
    goto v_26825;
v_26826:
    fn = elt(env, 25); // multsq
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    goto v_26819;
v_26820:
    goto v_26816;
v_26817:
    goto v_26818;
v_26819:
    fn = elt(env, 27); // addsq
    v_27173 = (*qfn2(fn))(fn, stack[0], v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_26780;
v_26782:
v_26780:
    v_27173 = stack[-2];
    v_27173 = qcdr(v_27173);
    stack[-2] = v_27173;
    goto v_26763;
v_26762:
    goto v_25628;
v_26727:
    goto v_26849;
v_26843:
    v_27175 = elt(env, 11); // df
    goto v_26844;
v_26845:
    v_27174 = stack[-8];
    goto v_26846;
v_26847:
    v_27173 = stack[-7];
    goto v_26848;
v_26849:
    goto v_26843;
v_26844:
    goto v_26845;
v_26846:
    goto v_26847;
v_26848:
    v_27173 = list3(v_27175, v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_26276;
v_26276:
v_25631:
    v_27173 = stack[0];
    fn = elt(env, 37); // opmtch
    v_27173 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    stack[-6] = v_27173;
    if (v_27173 == nil) goto v_26856;
    v_27173 = stack[-6];
    fn = elt(env, 31); // simp
    v_27173 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_26854;
v_26856:
    goto v_26872;
v_26868:
    v_27174 = stack[-8];
    goto v_26869;
v_26870:
    v_27173 = stack[-7];
    goto v_26871;
v_26872:
    goto v_26868;
v_26869:
    goto v_26870;
v_26871:
    fn = elt(env, 35); // depends
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    if (v_27173 == nil) goto v_26865;
    else goto v_26866;
v_26865:
    goto v_26887;
v_26883:
    v_27173 = stack[0];
    v_27173 = qcdr(v_27173);
    v_27174 = qcar(v_27173);
    stack[-8] = v_27174;
    goto v_26884;
v_26885:
    v_27173 = qvalue(elt(env, 7)); // powlis!*
    goto v_26886;
v_26887:
    goto v_26883;
v_26884:
    goto v_26885;
v_26886:
    v_27173 = Latsoc(nil, v_27174, v_27173);
    stack[-6] = v_27173;
    if (v_27173 == nil) goto v_26881;
    else goto v_26882;
v_26881:
    v_27173 = lisp_true;
    goto v_26880;
v_26882:
    goto v_26901;
v_26897:
    v_27173 = stack[-6];
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    v_27174 = qcar(v_27173);
    goto v_26898;
v_26899:
    v_27173 = stack[0];
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    goto v_26900;
v_26901:
    goto v_26897;
v_26898:
    goto v_26899;
v_26900:
    fn = elt(env, 50); // dependsl
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    v_27173 = (v_27173 == nil ? lisp_true : nil);
    goto v_26880;
    v_27173 = nil;
v_26880:
    if (v_27173 == nil) goto v_26878;
    v_27173 = qvalue(elt(env, 8)); // !*depend
    v_27173 = (v_27173 == nil ? lisp_true : nil);
    goto v_26876;
v_26878:
    v_27173 = nil;
    goto v_26876;
    v_27173 = nil;
v_26876:
    goto v_26864;
v_26866:
    v_27173 = nil;
    goto v_26864;
    v_27173 = nil;
v_26864:
    if (v_27173 == nil) goto v_26862;
    goto v_26924;
v_26920:
    v_27174 = nil;
    goto v_26921;
v_26922:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_26923;
v_26924:
    goto v_26920;
v_26921:
    goto v_26922;
v_26923:
    return cons(v_27174, v_27173);
v_26862:
    v_27173 = qvalue(elt(env, 9)); // !*expanddf
    if (v_27173 == nil) goto v_26928;
    v_27173 = stack[-8];
    if (!consp(v_27173)) goto v_26935;
    v_27173 = stack[0];
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    if (v_27173 == nil) goto v_26939;
    else goto v_26940;
v_26939:
    goto v_26953;
v_26949:
    v_27173 = stack[-8];
    v_27174 = qcar(v_27173);
    goto v_26950;
v_26951:
    v_27173 = elt(env, 20); // (df int)
    goto v_26952;
v_26953:
    goto v_26949;
v_26950:
    goto v_26951;
v_26952:
    v_27173 = Lmemq(nil, v_27174, v_27173);
    if (v_27173 == nil) goto v_26947;
    else goto v_26948;
v_26947:
    goto v_26967;
v_26963:
    v_27174 = stack[-7];
    goto v_26964;
v_26965:
    v_27173 = stack[-8];
    goto v_26966;
v_26967:
    goto v_26963;
v_26964:
    goto v_26965;
v_26966:
    fn = elt(env, 44); // smember
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    if (v_27173 == nil) goto v_26960;
    else goto v_26961;
v_26960:
    goto v_26978;
v_26974:
    v_27174 = stack[-8];
    goto v_26975;
v_26976:
    v_27173 = qvalue(elt(env, 7)); // powlis!*
    goto v_26977;
v_26978:
    goto v_26974;
v_26975:
    goto v_26976;
v_26977:
    v_27173 = Latsoc(nil, v_27174, v_27173);
    stack[-6] = v_27173;
    if (v_27173 == nil) goto v_26972;
    else goto v_26973;
v_26972:
    v_27173 = lisp_true;
    goto v_26971;
v_26973:
    goto v_26990;
v_26986:
    v_27173 = stack[-6];
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    v_27173 = qcdr(v_27173);
    v_27174 = qcar(v_27173);
    goto v_26987;
v_26988:
    v_27173 = stack[-7];
    goto v_26989;
v_26990:
    goto v_26986;
v_26987:
    goto v_26988;
v_26989:
    fn = elt(env, 35); // depends
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    v_27173 = (v_27173 == nil ? lisp_true : nil);
    goto v_26971;
    v_27173 = nil;
v_26971:
    goto v_26959;
v_26961:
    v_27173 = nil;
    goto v_26959;
    v_27173 = nil;
v_26959:
    goto v_26946;
v_26948:
    v_27173 = nil;
    goto v_26946;
    v_27173 = nil;
v_26946:
    goto v_26938;
v_26940:
    v_27173 = nil;
    goto v_26938;
    v_27173 = nil;
v_26938:
    goto v_26933;
v_26935:
    v_27173 = nil;
    goto v_26933;
    v_27173 = nil;
v_26933:
    if (v_27173 == nil) goto v_26928;
    goto v_27014;
v_27010:
    v_27174 = stack[-8];
    goto v_27011;
v_27012:
    v_27173 = qvalue(elt(env, 10)); // depl!*
    goto v_27013;
v_27014:
    goto v_27010;
v_27011:
    goto v_27012;
v_27013:
    v_27173 = Lassoc(nil, v_27174, v_27173);
    stack[-6] = v_27173;
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    if (v_27173 == nil) goto v_27020;
    else goto v_27021;
v_27020:
    v_27173 = nil;
    goto v_27019;
v_27021:
    v_27173 = stack[-8];
    v_27173 = qcdr(v_27173);
    fn = elt(env, 45); // get!-all!-kernels
    v_27173 = (*qfn1(fn))(fn, v_27173);
    env = stack[-10];
    goto v_27019;
    v_27173 = nil;
v_27019:
    stack[-5] = v_27173;
    v_27173 = stack[-6];
    if (v_27173 == nil) goto v_27033;
    v_27173 = stack[-5];
    if (v_27173 == nil) goto v_27033;
    goto v_27045;
v_27041:
    goto v_27051;
v_27047:
    v_27174 = stack[-7];
    goto v_27048;
v_27049:
    v_27173 = stack[-5];
    goto v_27050;
v_27051:
    goto v_27047;
v_27048:
    goto v_27049;
v_27050:
    v_27174 = Ldelete(nil, v_27174, v_27173);
    env = stack[-10];
    goto v_27042;
v_27043:
    v_27173 = stack[-7];
    goto v_27044;
v_27045:
    goto v_27041;
v_27042:
    goto v_27043;
v_27044:
    fn = elt(env, 46); // ldepends
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    if (v_27173 == nil) goto v_27033;
    goto v_27066;
v_27056:
    v_27177 = elt(env, 21); // "Possible inconsistent dependencies in"
    goto v_27057;
v_27058:
    v_27176 = stack[-8];
    goto v_27059;
v_27060:
    v_27175 = nil;
    goto v_27061;
v_27062:
    v_27174 = nil;
    goto v_27063;
v_27064:
    v_27173 = nil;
    goto v_27065;
v_27066:
    goto v_27056;
v_27057:
    goto v_27058;
v_27059:
    goto v_27060;
v_27061:
    goto v_27062;
v_27063:
    goto v_27064;
v_27065:
    fn = elt(env, 51); // msgpri
    v_27173 = (*qfnn(fn))(fn, 5, v_27177, v_27176, v_27175, v_27174, v_27173);
    env = stack[-10];
    goto v_27077;
v_27073:
    v_27174 = stack[0];
    goto v_27074;
v_27075:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27076;
v_27077:
    goto v_27073;
v_27074:
    goto v_27075;
v_27076:
    fn = elt(env, 38); // mksq
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_27031;
v_27033:
    v_27173 = stack[-6];
    if (v_27173 == nil) goto v_27081;
    goto v_27091;
v_27087:
    v_27174 = stack[-7];
    goto v_27088;
v_27089:
    v_27173 = stack[-6];
    v_27173 = qcdr(v_27173);
    stack[-6] = v_27173;
    goto v_27090;
v_27091:
    goto v_27087;
v_27088:
    goto v_27089;
v_27090:
    v_27173 = Lmemq(nil, v_27174, v_27173);
    if (v_27173 == nil) goto v_27086;
    goto v_27101;
v_27097:
    v_27174 = stack[0];
    goto v_27098;
v_27099:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27100;
v_27101:
    goto v_27097;
v_27098:
    goto v_27099;
v_27100:
    fn = elt(env, 38); // mksq
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_27084;
v_27086:
    goto v_27113;
v_27107:
    v_27175 = stack[-8];
    goto v_27108;
v_27109:
    v_27174 = stack[-7];
    goto v_27110;
v_27111:
    v_27173 = stack[-6];
    goto v_27112;
v_27113:
    goto v_27107;
v_27108:
    goto v_27109;
v_27110:
    goto v_27111;
v_27112:
    fn = elt(env, 36); // df!-chain!-rule
    v_27173 = (*qfnn(fn))(fn, 3, v_27175, v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_27084;
v_27084:
    goto v_27031;
v_27081:
    v_27173 = stack[-5];
    if (v_27173 == nil) goto v_27118;
    goto v_27129;
v_27125:
    v_27174 = stack[-7];
    goto v_27126;
v_27127:
    v_27173 = stack[-5];
    goto v_27128;
v_27129:
    goto v_27125;
v_27126:
    goto v_27127;
v_27128:
    fn = elt(env, 44); // smember
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    if (v_27173 == nil) goto v_27123;
    goto v_27137;
v_27133:
    v_27174 = stack[0];
    goto v_27134;
v_27135:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27136;
v_27137:
    goto v_27133;
v_27134:
    goto v_27135;
v_27136:
    fn = elt(env, 38); // mksq
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    goto v_27121;
v_27123:
    goto v_27149;
v_27143:
    v_27175 = stack[-8];
    goto v_27144;
v_27145:
    v_27174 = stack[-7];
    goto v_27146;
v_27147:
    v_27173 = stack[-5];
    goto v_27148;
v_27149:
    goto v_27143;
v_27144:
    goto v_27145;
v_27146:
    goto v_27147;
v_27148:
    fn = elt(env, 36); // df!-chain!-rule
    v_27173 = (*qfnn(fn))(fn, 3, v_27175, v_27174, v_27173);
    env = stack[-10];
    goto v_27121;
    v_27173 = nil;
v_27121:
    stack[0] = v_27173;
    goto v_27031;
v_27118:
    goto v_27160;
v_27156:
    v_27174 = stack[0];
    goto v_27157;
v_27158:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27159;
v_27160:
    goto v_27156;
v_27157:
    goto v_27158;
v_27159:
    fn = elt(env, 38); // mksq
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_27031;
v_27031:
    goto v_26854;
v_26928:
    goto v_27170;
v_27166:
    v_27174 = stack[0];
    goto v_27167;
v_27168:
    v_27173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_27169;
v_27170:
    goto v_27166;
v_27167:
    goto v_27168;
v_27169:
    fn = elt(env, 38); // mksq
    v_27173 = (*qfn2(fn))(fn, v_27174, v_27173);
    env = stack[-10];
    stack[0] = v_27173;
    goto v_26854;
v_26854:
    goto v_25628;
    return onevalue(v_27173);
}



// Code for ndepends

static LispObject CC_ndepends(LispObject env,
                         LispObject v_25615, LispObject v_25616)
{
    env = qenv(env);
    LispObject v_25797, v_25798, v_25799;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25616,v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25615,v_25616);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_25616;
    stack[-1] = v_25615;
// end of prologue
    v_25797 = stack[-1];
    if (v_25797 == nil) goto v_25624;
    else goto v_25625;
v_25624:
    v_25797 = lisp_true;
    goto v_25623;
v_25625:
    v_25797 = stack[-1];
    v_25797 = (is_number(v_25797) ? lisp_true : nil);
    if (v_25797 == nil) goto v_25632;
    else goto v_25631;
v_25632:
    v_25797 = stack[0];
    v_25797 = (is_number(v_25797) ? lisp_true : nil);
v_25631:
    goto v_25623;
    v_25797 = nil;
v_25623:
    if (v_25797 == nil) goto v_25621;
    v_25797 = nil;
    goto v_25619;
v_25621:
    goto v_25644;
v_25640:
    v_25798 = stack[-1];
    goto v_25641;
v_25642:
    v_25797 = stack[0];
    goto v_25643;
v_25644:
    goto v_25640;
v_25641:
    goto v_25642;
v_25643:
    if (equal(v_25798, v_25797)) goto v_25638;
    else goto v_25639;
v_25638:
    v_25797 = stack[-1];
    goto v_25619;
v_25639:
    v_25797 = stack[-1];
    if (!consp(v_25797)) goto v_25652;
    else goto v_25653;
v_25652:
    goto v_25659;
v_25655:
    v_25798 = stack[-1];
    goto v_25656;
v_25657:
    v_25797 = qvalue(elt(env, 1)); // frlis!*
    goto v_25658;
v_25659:
    goto v_25655;
v_25656:
    goto v_25657;
v_25658:
    v_25797 = Lmemq(nil, v_25798, v_25797);
    goto v_25651;
v_25653:
    v_25797 = nil;
    goto v_25651;
    v_25797 = nil;
v_25651:
    if (v_25797 == nil) goto v_25649;
    v_25797 = lisp_true;
    goto v_25619;
v_25649:
    goto v_25673;
v_25669:
    v_25798 = stack[-1];
    goto v_25670;
v_25671:
    v_25797 = qvalue(elt(env, 2)); // depl!*
    goto v_25672;
v_25673:
    goto v_25669;
v_25670:
    goto v_25671;
v_25672:
    v_25797 = Lassoc(nil, v_25798, v_25797);
    v_25798 = v_25797;
    v_25797 = v_25798;
    if (v_25797 == nil) goto v_25680;
    else goto v_25681;
v_25680:
    v_25797 = nil;
    goto v_25679;
v_25681:
    goto v_25691;
v_25687:
    v_25797 = v_25798;
    v_25798 = qcdr(v_25797);
    goto v_25688;
v_25689:
    v_25797 = stack[0];
    goto v_25690;
v_25691:
    goto v_25687;
v_25688:
    goto v_25689;
v_25690:
    fn = elt(env, 4); // lndepends
    v_25797 = (*qfn2(fn))(fn, v_25798, v_25797);
    env = stack[-2];
    goto v_25679;
    v_25797 = nil;
v_25679:
    if (v_25797 == nil) goto v_25668;
    v_25797 = lisp_true;
    goto v_25619;
v_25668:
    v_25797 = stack[-1];
    if (!consp(v_25797)) goto v_25701;
    v_25797 = stack[-1];
    v_25797 = qcar(v_25797);
    if (symbolp(v_25797)) goto v_25706;
    v_25797 = nil;
    goto v_25704;
v_25706:
    v_25797 = stack[-1];
    v_25797 = qcar(v_25797);
    if (!symbolp(v_25797)) v_25797 = nil;
    else { v_25797 = qfastgets(v_25797);
           if (v_25797 != nil) { v_25797 = elt(v_25797, 8); // dname
#ifdef RECORD_GET
             if (v_25797 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_25797 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_25797 == SPID_NOPROP) v_25797 = nil; }}
#endif
    goto v_25704;
    v_25797 = nil;
v_25704:
    goto v_25699;
v_25701:
    v_25797 = nil;
    goto v_25699;
    v_25797 = nil;
v_25699:
    if (v_25797 == nil) goto v_25697;
    goto v_25723;
v_25719:
    v_25797 = stack[-1];
    v_25798 = qcar(v_25797);
    goto v_25720;
v_25721:
    v_25797 = elt(env, 3); // domain!-depends!-fn
    goto v_25722;
v_25723:
    goto v_25719;
v_25720:
    goto v_25721;
v_25722:
    v_25797 = get(v_25798, v_25797);
    v_25798 = v_25797;
    v_25797 = v_25798;
    if (v_25797 == nil) goto v_25731;
    goto v_25740;
v_25734:
    v_25799 = v_25798;
    goto v_25735;
v_25736:
    v_25798 = stack[-1];
    goto v_25737;
v_25738:
    v_25797 = stack[0];
    goto v_25739;
v_25740:
    goto v_25734;
v_25735:
    goto v_25736;
v_25737:
    goto v_25738;
v_25739:
        return Lapply2(nil, 3, v_25799, v_25798, v_25797);
v_25731:
    v_25797 = nil;
    goto v_25729;
    v_25797 = nil;
v_25729:
    goto v_25619;
v_25697:
    v_25797 = stack[-1];
    fn = elt(env, 5); // atomf
    v_25797 = (*qfn1(fn))(fn, v_25797);
    env = stack[-2];
    if (v_25797 == nil) goto v_25751;
    else goto v_25752;
v_25751:
    goto v_25763;
v_25759:
    v_25797 = stack[-1];
    v_25798 = qcdr(v_25797);
    goto v_25760;
v_25761:
    v_25797 = stack[0];
    goto v_25762;
v_25763:
    goto v_25759;
v_25760:
    goto v_25761;
v_25762:
    fn = elt(env, 4); // lndepends
    v_25797 = (*qfn2(fn))(fn, v_25798, v_25797);
    env = stack[-2];
    if (v_25797 == nil) goto v_25757;
    else goto v_25756;
v_25757:
    goto v_25772;
v_25768:
    v_25797 = stack[-1];
    v_25798 = qcar(v_25797);
    goto v_25769;
v_25770:
    v_25797 = stack[0];
    goto v_25771;
v_25772:
    goto v_25768;
v_25769:
    goto v_25770;
v_25771:
    v_25797 = CC_ndepends(elt(env, 0), v_25798, v_25797);
    env = stack[-2];
v_25756:
    goto v_25750;
v_25752:
    v_25797 = nil;
    goto v_25750;
    v_25797 = nil;
v_25750:
    if (v_25797 == nil) goto v_25748;
    v_25797 = lisp_true;
    goto v_25619;
v_25748:
    v_25797 = stack[0];
    fn = elt(env, 5); // atomf
    v_25797 = (*qfn1(fn))(fn, v_25797);
    if (v_25797 == nil) goto v_25782;
    else goto v_25780;
v_25782:
    v_25797 = stack[0];
    v_25797 = qcar(v_25797);
    if (symbolp(v_25797)) goto v_25786;
    else goto v_25785;
v_25786:
    v_25797 = stack[0];
    v_25797 = qcar(v_25797);
    if (!symbolp(v_25797)) v_25797 = nil;
    else { v_25797 = qfastgets(v_25797);
           if (v_25797 != nil) { v_25797 = elt(v_25797, 8); // dname
#ifdef RECORD_GET
             if (v_25797 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_25797 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_25797 == SPID_NOPROP) v_25797 = nil; }}
#endif
    if (v_25797 == nil) goto v_25785;
    goto v_25780;
v_25785:
    goto v_25781;
v_25780:
    v_25797 = nil;
    goto v_25619;
v_25781:
    v_25797 = nil;
    goto v_25619;
    v_25797 = nil;
v_25619:
    return onevalue(v_25797);
}



// Code for xpartitop

static LispObject CC_xpartitop(LispObject env,
                         LispObject v_25615)
{
    env = qenv(env);
    LispObject v_25620;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25615);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_25620 = v_25615;
// end of prologue
    fn = elt(env, 1); // simp!*
    v_25620 = (*qfn1(fn))(fn, v_25620);
    env = stack[0];
    {
        fn = elt(env, 2); // xpartitsq
        return (*qfn1(fn))(fn, v_25620);
    }
}



// Code for all_defined_map_

static LispObject CC_all_defined_map_(LispObject env,
                         LispObject v_25615, LispObject v_25616)
{
    env = qenv(env);
    LispObject v_25629, v_25630, v_25631;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_25629 = v_25616;
    v_25630 = v_25615;
// end of prologue
    goto v_25625;
v_25619:
    v_25631 = v_25630;
    goto v_25620;
v_25621:
    v_25630 = nil;
    goto v_25622;
v_25623:
    goto v_25624;
v_25625:
    goto v_25619;
v_25620:
    goto v_25621;
v_25622:
    goto v_25623;
v_25624:
    {
        fn = elt(env, 1); // al1_defined_map_
        return (*qfnn(fn))(fn, 3, v_25631, v_25630, v_25629);
    }
}



// Code for mkcrn

static LispObject CC_mkcrn(LispObject env,
                         LispObject v_25615, LispObject v_25616)
{
    env = qenv(env);
    LispObject v_25629, v_25630, v_25631;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_25629 = v_25616;
    v_25630 = v_25615;
// end of prologue
    goto v_25625;
v_25619:
    v_25631 = elt(env, 1); // !:crn!:
    goto v_25620;
v_25621:
    goto v_25622;
v_25623:
    goto v_25624;
v_25625:
    goto v_25619;
v_25620:
    goto v_25621;
v_25622:
    goto v_25623;
v_25624:
    return list2star(v_25631, v_25630, v_25629);
}



// Code for nlist

static LispObject CC_nlist(LispObject env,
                         LispObject v_25615, LispObject v_25616)
{
    env = qenv(env);
    LispObject v_25647, v_25648;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25616,v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25615,v_25616);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_25616;
    stack[-1] = v_25615;
// end of prologue
    stack[-2] = nil;
v_25621:
    goto v_25630;
v_25626:
    v_25648 = stack[0];
    goto v_25627;
v_25628:
    v_25647 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25629;
v_25630:
    goto v_25626;
v_25627:
    goto v_25628;
v_25629:
    if (v_25648 == v_25647) goto v_25624;
    else goto v_25625;
v_25624:
    v_25647 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_25647);
    }
v_25625:
    goto v_25642;
v_25638:
    v_25648 = stack[-1];
    goto v_25639;
v_25640:
    v_25647 = stack[-2];
    goto v_25641;
v_25642:
    goto v_25638;
v_25639:
    goto v_25640;
v_25641:
    v_25647 = cons(v_25648, v_25647);
    env = stack[-3];
    stack[-2] = v_25647;
    v_25647 = stack[0];
    v_25647 = sub1(v_25647);
    env = stack[-3];
    stack[0] = v_25647;
    goto v_25621;
    v_25647 = nil;
    return onevalue(v_25647);
}



// Code for makecoeffpairshom

static LispObject CC_makecoeffpairshom(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25965, v_25966, v_25967, v_25968;
    LispObject fn;
    LispObject v_25618, v_25617, v_25616, v_25615;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "makecoeffpairshom");
    va_start(aa, nargs);
    v_25615 = va_arg(aa, LispObject);
    v_25616 = va_arg(aa, LispObject);
    v_25617 = va_arg(aa, LispObject);
    v_25618 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_25618,v_25617,v_25616,v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_25615,v_25616,v_25617,v_25618);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(17);
// copy arguments values to proper place
    stack[-11] = v_25618;
    stack[-12] = v_25617;
    stack[-13] = v_25616;
    stack[-14] = v_25615;
// end of prologue
    v_25965 = stack[-12];
    if (v_25965 == nil) goto v_25622;
    else goto v_25623;
v_25622:
    v_25965 = elt(env, 1); // ((nil))
    goto v_25621;
v_25623:
    v_25965 = stack[-13];
    v_25965 = qcar(v_25965);
    stack[-15] = v_25965;
v_25633:
    goto v_25647;
v_25643:
    stack[0] = stack[-11];
    goto v_25644;
v_25645:
    goto v_25654;
v_25650:
    v_25965 = stack[-14];
    v_25966 = qcar(v_25965);
    goto v_25651;
v_25652:
    v_25965 = stack[-15];
    goto v_25653;
v_25654:
    goto v_25650;
v_25651:
    goto v_25652;
v_25653:
    fn = elt(env, 2); // tayexp!-difference
    v_25965 = (*qfn2(fn))(fn, v_25966, v_25965);
    env = stack[-16];
    goto v_25646;
v_25647:
    goto v_25643;
v_25644:
    goto v_25645;
v_25646:
    fn = elt(env, 3); // tayexp!-times2
    v_25965 = (*qfn2(fn))(fn, stack[0], v_25965);
    env = stack[-16];
    fn = elt(env, 4); // tayexp!-minusp
    v_25965 = (*qfn1(fn))(fn, v_25965);
    env = stack[-16];
    if (v_25965 == nil) goto v_25640;
    v_25965 = nil;
    goto v_25632;
v_25640:
    goto v_25674;
v_25666:
    v_25965 = stack[-14];
    v_25968 = qcdr(v_25965);
    goto v_25667;
v_25668:
    v_25965 = stack[-13];
    v_25967 = qcdr(v_25965);
    goto v_25669;
v_25670:
    v_25965 = stack[-12];
    v_25966 = qcdr(v_25965);
    goto v_25671;
v_25672:
    v_25965 = stack[-11];
    goto v_25673;
v_25674:
    goto v_25666;
v_25667:
    goto v_25668;
v_25669:
    goto v_25670;
v_25671:
    goto v_25672;
v_25673:
    v_25965 = CC_makecoeffpairshom(elt(env, 0), 4, v_25968, v_25967, v_25966, v_25965);
    env = stack[-16];
    stack[-7] = v_25965;
    v_25965 = stack[-7];
    if (v_25965 == nil) goto v_25684;
    else goto v_25685;
v_25684:
    v_25965 = nil;
    goto v_25663;
v_25685:
    v_25965 = stack[-7];
    v_25965 = qcar(v_25965);
    stack[-3] = v_25965;
    goto v_25699;
v_25693:
    stack[-2] = stack[-15];
    goto v_25694;
v_25695:
    v_25965 = stack[-3];
    stack[-1] = qcar(v_25965);
    goto v_25696;
v_25697:
    goto v_25708;
v_25704:
    goto v_25714;
v_25710:
    v_25965 = stack[-13];
    stack[0] = qcar(v_25965);
    goto v_25711;
v_25712:
    goto v_25722;
v_25718:
    v_25965 = stack[-12];
    v_25966 = qcar(v_25965);
    goto v_25719;
v_25720:
    v_25965 = stack[-15];
    goto v_25721;
v_25722:
    goto v_25718;
v_25719:
    goto v_25720;
v_25721:
    fn = elt(env, 2); // tayexp!-difference
    v_25965 = (*qfn2(fn))(fn, v_25966, v_25965);
    env = stack[-16];
    goto v_25713;
v_25714:
    goto v_25710;
v_25711:
    goto v_25712;
v_25713:
    fn = elt(env, 5); // tayexp!-plus2
    v_25966 = (*qfn2(fn))(fn, stack[0], v_25965);
    env = stack[-16];
    goto v_25705;
v_25706:
    v_25965 = stack[-3];
    v_25965 = qcdr(v_25965);
    goto v_25707;
v_25708:
    goto v_25704;
v_25705:
    goto v_25706;
v_25707:
    v_25965 = cons(v_25966, v_25965);
    env = stack[-16];
    goto v_25698;
v_25699:
    goto v_25693;
v_25694:
    goto v_25695;
v_25696:
    goto v_25697;
v_25698:
    v_25965 = acons(stack[-2], stack[-1], v_25965);
    env = stack[-16];
    v_25965 = ncons(v_25965);
    env = stack[-16];
    stack[-5] = v_25965;
    stack[-6] = v_25965;
v_25664:
    v_25965 = stack[-7];
    v_25965 = qcdr(v_25965);
    stack[-7] = v_25965;
    v_25965 = stack[-7];
    if (v_25965 == nil) goto v_25732;
    else goto v_25733;
v_25732:
    v_25965 = stack[-6];
    goto v_25663;
v_25733:
    goto v_25741;
v_25737:
    stack[-4] = stack[-5];
    goto v_25738;
v_25739:
    v_25965 = stack[-7];
    v_25965 = qcar(v_25965);
    stack[-3] = v_25965;
    goto v_25754;
v_25748:
    stack[-2] = stack[-15];
    goto v_25749;
v_25750:
    v_25965 = stack[-3];
    stack[-1] = qcar(v_25965);
    goto v_25751;
v_25752:
    goto v_25763;
v_25759:
    goto v_25769;
v_25765:
    v_25965 = stack[-13];
    stack[0] = qcar(v_25965);
    goto v_25766;
v_25767:
    goto v_25777;
v_25773:
    v_25965 = stack[-12];
    v_25966 = qcar(v_25965);
    goto v_25774;
v_25775:
    v_25965 = stack[-15];
    goto v_25776;
v_25777:
    goto v_25773;
v_25774:
    goto v_25775;
v_25776:
    fn = elt(env, 2); // tayexp!-difference
    v_25965 = (*qfn2(fn))(fn, v_25966, v_25965);
    env = stack[-16];
    goto v_25768;
v_25769:
    goto v_25765;
v_25766:
    goto v_25767;
v_25768:
    fn = elt(env, 5); // tayexp!-plus2
    v_25966 = (*qfn2(fn))(fn, stack[0], v_25965);
    env = stack[-16];
    goto v_25760;
v_25761:
    v_25965 = stack[-3];
    v_25965 = qcdr(v_25965);
    goto v_25762;
v_25763:
    goto v_25759;
v_25760:
    goto v_25761;
v_25762:
    v_25965 = cons(v_25966, v_25965);
    env = stack[-16];
    goto v_25753;
v_25754:
    goto v_25748;
v_25749:
    goto v_25750;
v_25751:
    goto v_25752;
v_25753:
    v_25965 = acons(stack[-2], stack[-1], v_25965);
    env = stack[-16];
    v_25965 = ncons(v_25965);
    env = stack[-16];
    goto v_25740;
v_25741:
    goto v_25737;
v_25738:
    goto v_25739;
v_25740:
    v_25965 = Lrplacd(nil, stack[-4], v_25965);
    env = stack[-16];
    v_25965 = stack[-5];
    v_25965 = qcdr(v_25965);
    stack[-5] = v_25965;
    goto v_25664;
v_25663:
    stack[-10] = v_25965;
    v_25965 = stack[-10];
    fn = elt(env, 6); // lastpair
    v_25965 = (*qfn1(fn))(fn, v_25965);
    env = stack[-16];
    stack[-9] = v_25965;
    goto v_25792;
v_25788:
    v_25966 = stack[-15];
    goto v_25789;
v_25790:
    v_25965 = stack[-11];
    goto v_25791;
v_25792:
    goto v_25788;
v_25789:
    goto v_25790;
v_25791:
    fn = elt(env, 5); // tayexp!-plus2
    v_25965 = (*qfn2(fn))(fn, v_25966, v_25965);
    env = stack[-16];
    stack[-15] = v_25965;
    v_25965 = stack[-9];
    if (!consp(v_25965)) goto v_25797;
    else goto v_25798;
v_25797:
    goto v_25633;
v_25798:
v_25634:
    goto v_25810;
v_25806:
    stack[0] = stack[-11];
    goto v_25807;
v_25808:
    goto v_25817;
v_25813:
    v_25965 = stack[-14];
    v_25966 = qcar(v_25965);
    goto v_25814;
v_25815:
    v_25965 = stack[-15];
    goto v_25816;
v_25817:
    goto v_25813;
v_25814:
    goto v_25815;
v_25816:
    fn = elt(env, 2); // tayexp!-difference
    v_25965 = (*qfn2(fn))(fn, v_25966, v_25965);
    env = stack[-16];
    goto v_25809;
v_25810:
    goto v_25806;
v_25807:
    goto v_25808;
v_25809:
    fn = elt(env, 3); // tayexp!-times2
    v_25965 = (*qfn2(fn))(fn, stack[0], v_25965);
    env = stack[-16];
    fn = elt(env, 4); // tayexp!-minusp
    v_25965 = (*qfn1(fn))(fn, v_25965);
    env = stack[-16];
    if (v_25965 == nil) goto v_25803;
    v_25965 = stack[-10];
    goto v_25632;
v_25803:
    goto v_25827;
v_25823:
    stack[-8] = stack[-9];
    goto v_25824;
v_25825:
    goto v_25844;
v_25836:
    v_25965 = stack[-14];
    v_25968 = qcdr(v_25965);
    goto v_25837;
v_25838:
    v_25965 = stack[-13];
    v_25967 = qcdr(v_25965);
    goto v_25839;
v_25840:
    v_25965 = stack[-12];
    v_25966 = qcdr(v_25965);
    goto v_25841;
v_25842:
    v_25965 = stack[-11];
    goto v_25843;
v_25844:
    goto v_25836;
v_25837:
    goto v_25838;
v_25839:
    goto v_25840;
v_25841:
    goto v_25842;
v_25843:
    v_25965 = CC_makecoeffpairshom(elt(env, 0), 4, v_25968, v_25967, v_25966, v_25965);
    env = stack[-16];
    stack[-7] = v_25965;
    v_25965 = stack[-7];
    if (v_25965 == nil) goto v_25854;
    else goto v_25855;
v_25854:
    v_25965 = nil;
    goto v_25833;
v_25855:
    v_25965 = stack[-7];
    v_25965 = qcar(v_25965);
    stack[-3] = v_25965;
    goto v_25869;
v_25863:
    stack[-2] = stack[-15];
    goto v_25864;
v_25865:
    v_25965 = stack[-3];
    stack[-1] = qcar(v_25965);
    goto v_25866;
v_25867:
    goto v_25878;
v_25874:
    goto v_25884;
v_25880:
    v_25965 = stack[-13];
    stack[0] = qcar(v_25965);
    goto v_25881;
v_25882:
    goto v_25892;
v_25888:
    v_25965 = stack[-12];
    v_25966 = qcar(v_25965);
    goto v_25889;
v_25890:
    v_25965 = stack[-15];
    goto v_25891;
v_25892:
    goto v_25888;
v_25889:
    goto v_25890;
v_25891:
    fn = elt(env, 2); // tayexp!-difference
    v_25965 = (*qfn2(fn))(fn, v_25966, v_25965);
    env = stack[-16];
    goto v_25883;
v_25884:
    goto v_25880;
v_25881:
    goto v_25882;
v_25883:
    fn = elt(env, 5); // tayexp!-plus2
    v_25966 = (*qfn2(fn))(fn, stack[0], v_25965);
    env = stack[-16];
    goto v_25875;
v_25876:
    v_25965 = stack[-3];
    v_25965 = qcdr(v_25965);
    goto v_25877;
v_25878:
    goto v_25874;
v_25875:
    goto v_25876;
v_25877:
    v_25965 = cons(v_25966, v_25965);
    env = stack[-16];
    goto v_25868;
v_25869:
    goto v_25863;
v_25864:
    goto v_25865;
v_25866:
    goto v_25867;
v_25868:
    v_25965 = acons(stack[-2], stack[-1], v_25965);
    env = stack[-16];
    v_25965 = ncons(v_25965);
    env = stack[-16];
    stack[-5] = v_25965;
    stack[-6] = v_25965;
v_25834:
    v_25965 = stack[-7];
    v_25965 = qcdr(v_25965);
    stack[-7] = v_25965;
    v_25965 = stack[-7];
    if (v_25965 == nil) goto v_25902;
    else goto v_25903;
v_25902:
    v_25965 = stack[-6];
    goto v_25833;
v_25903:
    goto v_25911;
v_25907:
    stack[-4] = stack[-5];
    goto v_25908;
v_25909:
    v_25965 = stack[-7];
    v_25965 = qcar(v_25965);
    stack[-3] = v_25965;
    goto v_25924;
v_25918:
    stack[-2] = stack[-15];
    goto v_25919;
v_25920:
    v_25965 = stack[-3];
    stack[-1] = qcar(v_25965);
    goto v_25921;
v_25922:
    goto v_25933;
v_25929:
    goto v_25939;
v_25935:
    v_25965 = stack[-13];
    stack[0] = qcar(v_25965);
    goto v_25936;
v_25937:
    goto v_25947;
v_25943:
    v_25965 = stack[-12];
    v_25966 = qcar(v_25965);
    goto v_25944;
v_25945:
    v_25965 = stack[-15];
    goto v_25946;
v_25947:
    goto v_25943;
v_25944:
    goto v_25945;
v_25946:
    fn = elt(env, 2); // tayexp!-difference
    v_25965 = (*qfn2(fn))(fn, v_25966, v_25965);
    env = stack[-16];
    goto v_25938;
v_25939:
    goto v_25935;
v_25936:
    goto v_25937;
v_25938:
    fn = elt(env, 5); // tayexp!-plus2
    v_25966 = (*qfn2(fn))(fn, stack[0], v_25965);
    env = stack[-16];
    goto v_25930;
v_25931:
    v_25965 = stack[-3];
    v_25965 = qcdr(v_25965);
    goto v_25932;
v_25933:
    goto v_25929;
v_25930:
    goto v_25931;
v_25932:
    v_25965 = cons(v_25966, v_25965);
    env = stack[-16];
    goto v_25923;
v_25924:
    goto v_25918;
v_25919:
    goto v_25920;
v_25921:
    goto v_25922;
v_25923:
    v_25965 = acons(stack[-2], stack[-1], v_25965);
    env = stack[-16];
    v_25965 = ncons(v_25965);
    env = stack[-16];
    goto v_25910;
v_25911:
    goto v_25907;
v_25908:
    goto v_25909;
v_25910:
    v_25965 = Lrplacd(nil, stack[-4], v_25965);
    env = stack[-16];
    v_25965 = stack[-5];
    v_25965 = qcdr(v_25965);
    stack[-5] = v_25965;
    goto v_25834;
v_25833:
    goto v_25826;
v_25827:
    goto v_25823;
v_25824:
    goto v_25825;
v_25826:
    v_25965 = Lrplacd(nil, stack[-8], v_25965);
    env = stack[-16];
    v_25965 = stack[-9];
    fn = elt(env, 6); // lastpair
    v_25965 = (*qfn1(fn))(fn, v_25965);
    env = stack[-16];
    stack[-9] = v_25965;
    goto v_25962;
v_25958:
    v_25966 = stack[-15];
    goto v_25959;
v_25960:
    v_25965 = stack[-11];
    goto v_25961;
v_25962:
    goto v_25958;
v_25959:
    goto v_25960;
v_25961:
    fn = elt(env, 5); // tayexp!-plus2
    v_25965 = (*qfn2(fn))(fn, v_25966, v_25965);
    env = stack[-16];
    stack[-15] = v_25965;
    goto v_25634;
v_25632:
    goto v_25621;
    v_25965 = nil;
v_25621:
    return onevalue(v_25965);
}



// Code for cols2rows2

static LispObject CC_cols2rows2(LispObject env,
                         LispObject v_25615, LispObject v_25616)
{
    env = qenv(env);
    LispObject v_25654, v_25655;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25616,v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25615,v_25616);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_25616;
    stack[-1] = v_25615;
// end of prologue
    goto v_25628;
v_25624:
    v_25655 = stack[0];
    goto v_25625;
v_25626:
    v_25654 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25627;
v_25628:
    goto v_25624;
v_25625:
    goto v_25626;
v_25627:
    if (v_25655 == v_25654) goto v_25623;
    goto v_25636;
v_25632:
    goto v_25642;
v_25638:
    v_25655 = stack[-1];
    goto v_25639;
v_25640:
    v_25654 = stack[0];
    goto v_25641;
v_25642:
    goto v_25638;
v_25639:
    goto v_25640;
v_25641:
    fn = elt(env, 1); // ithlistelem
    stack[-2] = (*qfn2(fn))(fn, v_25655, v_25654);
    env = stack[-3];
    goto v_25633;
v_25634:
    goto v_25650;
v_25646:
    goto v_25647;
v_25648:
    v_25654 = stack[0];
    v_25654 = sub1(v_25654);
    env = stack[-3];
    goto v_25649;
v_25650:
    goto v_25646;
v_25647:
    goto v_25648;
v_25649:
    v_25654 = CC_cols2rows2(elt(env, 0), stack[-1], v_25654);
    goto v_25635;
v_25636:
    goto v_25632;
v_25633:
    goto v_25634;
v_25635:
    {
        LispObject v_25659 = stack[-2];
        return cons(v_25659, v_25654);
    }
v_25623:
    v_25654 = nil;
    return onevalue(v_25654);
}



// Code for ldf!-dep!-var

static LispObject CC_ldfKdepKvar(LispObject env,
                         LispObject v_25615)
{
    env = qenv(env);
    LispObject v_25668, v_25669;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25615);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_25668 = v_25615;
// end of prologue
    stack[-2] = nil;
    stack[-1] = v_25668;
v_25623:
    v_25668 = stack[-1];
    if (v_25668 == nil) goto v_25627;
    else goto v_25628;
v_25627:
    goto v_25622;
v_25628:
    v_25668 = stack[-1];
    v_25668 = qcar(v_25668);
    stack[0] = v_25668;
    goto v_25642;
v_25638:
    v_25668 = stack[0];
    fn = elt(env, 2); // ldt!-tvar
    v_25669 = (*qfn1(fn))(fn, v_25668);
    env = stack[-3];
    goto v_25639;
v_25640:
    v_25668 = qvalue(elt(env, 1)); // depl!*
    goto v_25641;
v_25642:
    goto v_25638;
v_25639:
    goto v_25640;
v_25641:
    v_25668 = Lassoc(nil, v_25669, v_25668);
    if (v_25668 == nil) goto v_25637;
    goto v_25652;
v_25648:
    goto v_25657;
v_25653:
    v_25668 = stack[0];
    fn = elt(env, 2); // ldt!-tvar
    v_25669 = (*qfn1(fn))(fn, v_25668);
    env = stack[-3];
    goto v_25654;
v_25655:
    v_25668 = qvalue(elt(env, 1)); // depl!*
    goto v_25656;
v_25657:
    goto v_25653;
v_25654:
    goto v_25655;
v_25656:
    v_25668 = Lassoc(nil, v_25669, v_25668);
    v_25669 = qcdr(v_25668);
    goto v_25649;
v_25650:
    v_25668 = stack[-2];
    goto v_25651;
v_25652:
    goto v_25648;
v_25649:
    goto v_25650;
v_25651:
    v_25668 = Lappend(nil, v_25669, v_25668);
    env = stack[-3];
    stack[-2] = v_25668;
    goto v_25635;
v_25637:
v_25635:
    v_25668 = stack[-1];
    v_25668 = qcdr(v_25668);
    stack[-1] = v_25668;
    goto v_25623;
v_25622:
    v_25668 = stack[-2];
    {
        fn = elt(env, 3); // makeset
        return (*qfn1(fn))(fn, v_25668);
    }
    return onevalue(v_25668);
}



// Code for findhr

static LispObject CC_findhr(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25688, v_25689, v_25690;
    argcheck(nargs, 0, "findhr");
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
v_25621:
    goto v_25632;
v_25628:
    v_25689 = qvalue(elt(env, 1)); // headhisto
    goto v_25629;
v_25630:
    v_25688 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25631;
v_25632:
    goto v_25628;
v_25629:
    goto v_25630;
v_25631:
    v_25688 = (LispObject)greaterp2(v_25689, v_25688);
    v_25688 = v_25688 ? lisp_true : nil;
    env = stack[-2];
    if (v_25688 == nil) goto v_25624;
    goto v_25640;
v_25636:
    v_25689 = qvalue(elt(env, 2)); // codhisto
    goto v_25637;
v_25638:
    v_25688 = qvalue(elt(env, 1)); // headhisto
    goto v_25639;
v_25640:
    goto v_25636;
v_25637:
    goto v_25638;
v_25639:
    v_25688 = *(LispObject *)((char *)v_25689 + (CELL-TAG_VECTOR) + (((intptr_t)v_25688-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_25688;
    if (v_25688 == nil) goto v_25635;
    else goto v_25624;
v_25635:
    goto v_25625;
v_25624:
    goto v_25620;
v_25625:
    v_25688 = qvalue(elt(env, 1)); // headhisto
    v_25688 = sub1(v_25688);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_25688; // headhisto
    goto v_25621;
v_25620:
    v_25688 = stack[-1];
    if (v_25688 == nil) goto v_25650;
    v_25688 = stack[-1];
    v_25688 = ncons(v_25688);
    env = stack[-2];
    qvalue(elt(env, 3)) = v_25688; // psi
    v_25688 = (LispObject)16+TAG_FIXNUM; // 1
    qvalue(elt(env, 4)) = v_25688; // npsi
    goto v_25661;
v_25655:
    goto v_25666;
v_25662:
    stack[0] = qvalue(elt(env, 5)); // codmat
    goto v_25663;
v_25664:
    goto v_25673;
v_25669:
    v_25689 = qvalue(elt(env, 6)); // maxvar
    goto v_25670;
v_25671:
    v_25688 = stack[-1];
    goto v_25672;
v_25673:
    goto v_25669;
v_25670:
    goto v_25671;
v_25672:
    v_25688 = plus2(v_25689, v_25688);
    env = stack[-2];
    goto v_25665;
v_25666:
    goto v_25662;
v_25663:
    goto v_25664;
v_25665:
    v_25690 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_25688-TAG_FIXNUM)/(16/CELL)));
    goto v_25656;
v_25657:
    v_25689 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25658;
v_25659:
    v_25688 = nil;
    goto v_25660;
v_25661:
    goto v_25655;
v_25656:
    goto v_25657;
v_25658:
    goto v_25659;
v_25660:
    *(LispObject *)((char *)v_25690 + (CELL-TAG_VECTOR) + (((intptr_t)v_25689-TAG_FIXNUM)/(16/CELL))) = v_25688;
    goto v_25684;
v_25680:
    v_25689 = stack[-1];
    goto v_25681;
v_25682:
    v_25688 = qvalue(elt(env, 7)); // rcoccup
    goto v_25683;
v_25684:
    goto v_25680;
v_25681:
    goto v_25682;
v_25683:
    v_25688 = cons(v_25689, v_25688);
    env = stack[-2];
    qvalue(elt(env, 7)) = v_25688; // rcoccup
    goto v_25648;
v_25650:
v_25648:
    v_25688 = stack[-1];
    return onevalue(v_25688);
}



// Code for make_spoly_pair

static LispObject CC_make_spoly_pair(LispObject env,
                         LispObject v_25615, LispObject v_25616)
{
    env = qenv(env);
    LispObject v_25714, v_25715, v_25716, v_25717;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25616,v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25615,v_25616);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_25616;
    stack[-3] = v_25615;
// end of prologue
v_25621:
    goto v_25631;
v_25627:
    v_25715 = stack[-2];
    goto v_25628;
v_25629:
    v_25714 = stack[-3];
    goto v_25630;
v_25631:
    goto v_25627;
v_25628:
    goto v_25629;
v_25630:
    fn = elt(env, 2); // pfordp
    v_25714 = (*qfn2(fn))(fn, v_25715, v_25714);
    env = stack[-5];
    if (v_25714 == nil) goto v_25625;
    v_25714 = stack[-2];
    v_25715 = v_25714;
    v_25714 = stack[-3];
    stack[-2] = v_25714;
    v_25714 = v_25715;
    stack[-3] = v_25714;
    goto v_25621;
v_25625:
    goto v_25644;
v_25640:
    v_25714 = stack[-3];
    fn = elt(env, 3); // xval
    stack[0] = (*qfn1(fn))(fn, v_25714);
    env = stack[-5];
    goto v_25641;
v_25642:
    v_25714 = stack[-2];
    fn = elt(env, 3); // xval
    v_25714 = (*qfn1(fn))(fn, v_25714);
    env = stack[-5];
    goto v_25643;
v_25644:
    goto v_25640;
v_25641:
    goto v_25642;
v_25643:
    fn = elt(env, 4); // xlcm
    v_25714 = (*qfn2(fn))(fn, stack[0], v_25714);
    env = stack[-5];
    stack[-4] = v_25714;
    v_25714 = stack[-3];
    v_25714 = qcdr(v_25714);
    if (v_25714 == nil) goto v_25658;
    else goto v_25657;
v_25658:
    v_25714 = stack[-2];
    v_25714 = qcdr(v_25714);
    if (v_25714 == nil) goto v_25661;
    else goto v_25657;
v_25661:
    v_25714 = nil;
    goto v_25655;
v_25657:
    goto v_25678;
v_25672:
    stack[-1] = stack[-4];
    goto v_25673;
v_25674:
    v_25714 = stack[-3];
    fn = elt(env, 3); // xval
    stack[0] = (*qfn1(fn))(fn, v_25714);
    env = stack[-5];
    goto v_25675;
v_25676:
    v_25714 = stack[-2];
    fn = elt(env, 3); // xval
    v_25714 = (*qfn1(fn))(fn, v_25714);
    env = stack[-5];
    goto v_25677;
v_25678:
    goto v_25672;
v_25673:
    goto v_25674;
v_25675:
    goto v_25676;
v_25677:
    fn = elt(env, 5); // triviallcm
    v_25714 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_25714);
    env = stack[-5];
    if (v_25714 == nil) goto v_25669;
    else goto v_25670;
v_25669:
    v_25714 = stack[-4];
    fn = elt(env, 6); // mknwedge
    v_25714 = (*qfn1(fn))(fn, v_25714);
    env = stack[-5];
    fn = elt(env, 7); // xdegreecheck
    v_25714 = (*qfn1(fn))(fn, v_25714);
    env = stack[-5];
    if (v_25714 == nil) goto v_25686;
    else goto v_25687;
v_25686:
    goto v_25700;
v_25692:
    v_25716 = stack[-4];
    goto v_25693;
v_25694:
    v_25717 = elt(env, 1); // spoly_pair
    goto v_25695;
v_25696:
    v_25715 = stack[-3];
    goto v_25697;
v_25698:
    v_25714 = stack[-2];
    goto v_25699;
v_25700:
    goto v_25692;
v_25693:
    goto v_25694;
v_25695:
    goto v_25696;
v_25697:
    goto v_25698;
v_25699:
    return list4(v_25716, v_25717, v_25715, v_25714);
v_25687:
    v_25714 = nil;
    goto v_25685;
    v_25714 = nil;
v_25685:
    goto v_25668;
v_25670:
    v_25714 = nil;
    goto v_25668;
    v_25714 = nil;
v_25668:
    goto v_25655;
    v_25714 = nil;
v_25655:
    goto v_25651;
    v_25714 = nil;
    goto v_25651;
    v_25714 = nil;
v_25651:
    goto v_25620;
    v_25714 = nil;
v_25620:
    return onevalue(v_25714);
}



// Code for simpsetdiff

static LispObject CC_simpsetdiff(LispObject env,
                         LispObject v_25615)
{
    env = qenv(env);
    LispObject v_25715, v_25716, v_25717;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25615);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_25715 = v_25615;
// end of prologue
    goto v_25622;
v_25618:
    v_25716 = elt(env, 1); // setdiff
    goto v_25619;
v_25620:
    goto v_25621;
v_25622:
    goto v_25618;
v_25619:
    goto v_25620;
v_25621:
    fn = elt(env, 3); // applysetop
    v_25715 = (*qfn2(fn))(fn, v_25716, v_25715);
    env = stack[0];
    v_25717 = v_25715;
    goto v_25631;
v_25627:
    goto v_25638;
v_25634:
    goto v_25644;
v_25640:
    goto v_25653;
v_25649:
    v_25715 = v_25717;
    v_25716 = qcar(v_25715);
    goto v_25650;
v_25651:
    v_25715 = elt(env, 1); // setdiff
    goto v_25652;
v_25653:
    goto v_25649;
v_25650:
    goto v_25651;
v_25652:
    if (v_25716 == v_25715) goto v_25647;
    else goto v_25648;
v_25647:
    goto v_25669;
v_25665:
    v_25715 = v_25717;
    v_25715 = qcdr(v_25715);
    v_25716 = qcar(v_25715);
    goto v_25666;
v_25667:
    v_25715 = v_25717;
    v_25715 = qcdr(v_25715);
    v_25715 = qcdr(v_25715);
    v_25715 = qcar(v_25715);
    goto v_25668;
v_25669:
    goto v_25665;
v_25666:
    goto v_25667;
v_25668:
    if (equal(v_25716, v_25715)) goto v_25663;
    else goto v_25664;
v_25663:
    v_25715 = lisp_true;
    goto v_25662;
v_25664:
    goto v_25684;
v_25680:
    v_25715 = v_25717;
    v_25715 = qcdr(v_25715);
    v_25716 = qcar(v_25715);
    goto v_25681;
v_25682:
    v_25715 = qvalue(elt(env, 2)); // empty_set
    goto v_25683;
v_25684:
    goto v_25680;
v_25681:
    goto v_25682;
v_25683:
    v_25715 = (equal(v_25716, v_25715) ? lisp_true : nil);
    goto v_25662;
    v_25715 = nil;
v_25662:
    if (v_25715 == nil) goto v_25660;
    v_25715 = qvalue(elt(env, 2)); // empty_set
    goto v_25658;
v_25660:
    goto v_25697;
v_25693:
    v_25715 = v_25717;
    v_25715 = qcdr(v_25715);
    v_25715 = qcdr(v_25715);
    v_25716 = qcar(v_25715);
    goto v_25694;
v_25695:
    v_25715 = qvalue(elt(env, 2)); // empty_set
    goto v_25696;
v_25697:
    goto v_25693;
v_25694:
    goto v_25695;
v_25696:
    if (equal(v_25716, v_25715)) goto v_25691;
    else goto v_25692;
v_25691:
    v_25715 = v_25717;
    v_25715 = qcdr(v_25715);
    v_25715 = qcar(v_25715);
    goto v_25658;
v_25692:
    v_25715 = v_25717;
    goto v_25658;
    v_25715 = nil;
v_25658:
    v_25716 = v_25715;
    goto v_25646;
v_25648:
    v_25715 = v_25717;
    v_25716 = v_25715;
    goto v_25646;
    v_25716 = nil;
v_25646:
    goto v_25641;
v_25642:
    v_25715 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25643;
v_25644:
    goto v_25640;
v_25641:
    goto v_25642;
v_25643:
    fn = elt(env, 4); // mksp
    v_25716 = (*qfn2(fn))(fn, v_25716, v_25715);
    env = stack[0];
    goto v_25635;
v_25636:
    v_25715 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25637;
v_25638:
    goto v_25634;
v_25635:
    goto v_25636;
v_25637:
    v_25715 = cons(v_25716, v_25715);
    env = stack[0];
    v_25716 = ncons(v_25715);
    goto v_25628;
v_25629:
    v_25715 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25630;
v_25631:
    goto v_25627;
v_25628:
    goto v_25629;
v_25630:
    return cons(v_25716, v_25715);
}



// Code for rat_leq

static LispObject CC_rat_leq(LispObject env,
                         LispObject v_25615, LispObject v_25616)
{
    env = qenv(env);
    LispObject v_25635, v_25636;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25616,v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25615,v_25616);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_25635 = v_25616;
    v_25636 = v_25615;
// end of prologue
    goto v_25623;
v_25619:
    goto v_25630;
v_25626:
    stack[0] = v_25636;
    goto v_25627;
v_25628:
    fn = elt(env, 1); // negsq
    v_25635 = (*qfn1(fn))(fn, v_25635);
    env = stack[-1];
    goto v_25629;
v_25630:
    goto v_25626;
v_25627:
    goto v_25628;
v_25629:
    fn = elt(env, 2); // addsq
    v_25635 = (*qfn2(fn))(fn, stack[0], v_25635);
    env = stack[-1];
    fn = elt(env, 3); // rat_sgn
    v_25636 = (*qfn1(fn))(fn, v_25635);
    goto v_25620;
v_25621:
    v_25635 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25622;
v_25623:
    goto v_25619;
v_25620:
    goto v_25621;
v_25622:
        return Llessp(nil, v_25636, v_25635);
}



// Code for rl_nnfnot

static LispObject CC_rl_nnfnot(LispObject env,
                         LispObject v_25615)
{
    env = qenv(env);
    LispObject v_25626;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25615);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_25626 = v_25615;
// end of prologue
    goto v_25622;
v_25618:
    stack[0] = qvalue(elt(env, 1)); // rl_nnfnot!*
    goto v_25619;
v_25620:
    v_25626 = ncons(v_25626);
    env = stack[-1];
    goto v_25621;
v_25622:
    goto v_25618;
v_25619:
    goto v_25620;
v_25621:
    {
        LispObject v_25628 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_25628, v_25626);
    }
}



// Code for ofsf_simplequal

static LispObject CC_ofsf_simplequal(LispObject env,
                         LispObject v_25615, LispObject v_25616)
{
    env = qenv(env);
    LispObject v_25707, v_25708, v_25709;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25616,v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25615,v_25616);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_25616;
    stack[-2] = v_25615;
// end of prologue
    v_25707 = stack[-2];
    fn = elt(env, 8); // ofsf_posdefp
    v_25707 = (*qfn1(fn))(fn, v_25707);
    env = stack[-4];
    stack[-3] = v_25707;
    goto v_25633;
v_25629:
    v_25708 = stack[-3];
    goto v_25630;
v_25631:
    v_25707 = elt(env, 1); // stsq
    goto v_25632;
v_25633:
    goto v_25629;
v_25630:
    goto v_25631;
v_25632:
    if (v_25708 == v_25707) goto v_25627;
    else goto v_25628;
v_25627:
    v_25707 = elt(env, 2); // false
    goto v_25622;
v_25628:
    v_25707 = stack[-2];
    fn = elt(env, 9); // sfto_sqfpartf
    v_25707 = (*qfn1(fn))(fn, v_25707);
    env = stack[-4];
    stack[0] = v_25707;
    v_25707 = stack[0];
    fn = elt(env, 8); // ofsf_posdefp
    v_25707 = (*qfn1(fn))(fn, v_25707);
    env = stack[-4];
    v_25709 = v_25707;
    goto v_25649;
v_25645:
    v_25708 = v_25709;
    goto v_25646;
v_25647:
    v_25707 = elt(env, 1); // stsq
    goto v_25648;
v_25649:
    goto v_25645;
v_25646:
    goto v_25647;
v_25648:
    if (v_25708 == v_25707) goto v_25643;
    else goto v_25644;
v_25643:
    v_25707 = elt(env, 2); // false
    goto v_25622;
v_25644:
    v_25707 = qvalue(elt(env, 3)); // !*rlsitsqspl
    if (v_25707 == nil) goto v_25656;
    v_25707 = qvalue(elt(env, 4)); // !*rlsiexpla
    if (v_25707 == nil) goto v_25660;
    else goto v_25659;
v_25660:
    v_25707 = qvalue(elt(env, 5)); // !*rlsiexpl
    if (v_25707 == nil) goto v_25662;
    goto v_25670;
v_25666:
    v_25708 = stack[-1];
    goto v_25667;
v_25668:
    v_25707 = elt(env, 6); // and
    goto v_25669;
v_25670:
    goto v_25666;
v_25667:
    goto v_25668;
v_25669:
    if (v_25708 == v_25707) goto v_25665;
    else goto v_25662;
v_25665:
    goto v_25659;
v_25662:
    goto v_25656;
v_25659:
    goto v_25681;
v_25677:
    v_25708 = v_25709;
    goto v_25678;
v_25679:
    v_25707 = elt(env, 7); // tsq
    goto v_25680;
v_25681:
    goto v_25677;
v_25678:
    goto v_25679;
v_25680:
    if (v_25708 == v_25707) goto v_25675;
    else goto v_25676;
v_25675:
    v_25707 = stack[0];
    {
        fn = elt(env, 10); // ofsf_tsqsplequal
        return (*qfn1(fn))(fn, v_25707);
    }
v_25676:
    goto v_25694;
v_25690:
    v_25708 = stack[-3];
    goto v_25691;
v_25692:
    v_25707 = elt(env, 7); // tsq
    goto v_25693;
v_25694:
    goto v_25690;
v_25691:
    goto v_25692;
v_25693:
    if (v_25708 == v_25707) goto v_25688;
    else goto v_25689;
v_25688:
    v_25707 = stack[-2];
    {
        fn = elt(env, 10); // ofsf_tsqsplequal
        return (*qfn1(fn))(fn, v_25707);
    }
v_25689:
    goto v_25654;
v_25656:
v_25654:
    goto v_25704;
v_25700:
    v_25708 = stack[0];
    goto v_25701;
v_25702:
    v_25707 = stack[-1];
    goto v_25703;
v_25704:
    goto v_25700;
v_25701:
    goto v_25702;
v_25703:
    {
        fn = elt(env, 11); // ofsf_facequal!*
        return (*qfn2(fn))(fn, v_25708, v_25707);
    }
v_25622:
    return onevalue(v_25707);
}



// Code for rule

static LispObject CC_rule(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_25836, v_25837, v_25838, v_25839, v_25840;
    LispObject fn;
    LispObject v_25618, v_25617, v_25616, v_25615;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "rule");
    va_start(aa, nargs);
    v_25615 = va_arg(aa, LispObject);
    v_25616 = va_arg(aa, LispObject);
    v_25617 = va_arg(aa, LispObject);
    v_25618 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_25618,v_25617,v_25616,v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_25615,v_25616,v_25617,v_25618);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_25618;
    stack[0] = v_25617;
    stack[-5] = v_25616;
    stack[-6] = v_25615;
// end of prologue
    stack[-7] = nil;
    goto v_25632;
v_25628:
    v_25837 = stack[0];
    goto v_25629;
v_25630:
    v_25836 = stack[-6];
    goto v_25631;
v_25632:
    goto v_25628;
v_25629:
    goto v_25630;
v_25631:
    v_25836 = Lsubla(nil, v_25837, v_25836);
    env = stack[-8];
    stack[-2] = v_25836;
    goto v_25643;
v_25639:
    v_25837 = stack[-2];
    goto v_25640;
v_25641:
    v_25836 = stack[-6];
    goto v_25642;
v_25643:
    goto v_25639;
v_25640:
    goto v_25641;
v_25642:
    if (equal(v_25837, v_25836)) goto v_25638;
    v_25836 = stack[-2];
    if (!consp(v_25836)) goto v_25648;
    else goto v_25649;
v_25648:
    v_25836 = stack[-6];
    {
        fn = elt(env, 7); // errpri1
        return (*qfn1(fn))(fn, v_25836);
    }
v_25649:
    v_25836 = lisp_true;
    stack[-7] = v_25836;
    v_25836 = stack[-2];
    stack[-6] = v_25836;
    goto v_25647;
v_25647:
    goto v_25636;
v_25638:
v_25636:
    goto v_25662;
v_25658:
    v_25837 = stack[0];
    goto v_25659;
v_25660:
    v_25836 = stack[-5];
    goto v_25661;
v_25662:
    goto v_25658;
v_25659:
    goto v_25660;
v_25661:
    v_25836 = Lsubla(nil, v_25837, v_25836);
    env = stack[-8];
    stack[-2] = v_25836;
    goto v_25673;
v_25669:
    v_25837 = stack[-2];
    goto v_25670;
v_25671:
    v_25836 = stack[-5];
    goto v_25672;
v_25673:
    goto v_25669;
v_25670:
    goto v_25671;
v_25672:
    if (equal(v_25837, v_25836)) goto v_25668;
    v_25836 = stack[-2];
    stack[-5] = v_25836;
    goto v_25686;
v_25682:
    v_25837 = stack[-5];
    goto v_25683;
v_25684:
    v_25836 = elt(env, 1); // !*sq!*
    goto v_25685;
v_25686:
    goto v_25682;
v_25683:
    goto v_25684;
v_25685:
    if (!consp(v_25837)) goto v_25680;
    v_25837 = qcar(v_25837);
    if (v_25837 == v_25836) goto v_25679;
    else goto v_25680;
v_25679:
    v_25836 = stack[-5];
    v_25836 = qcdr(v_25836);
    v_25836 = qcar(v_25836);
    fn = elt(env, 8); // prepsq!*
    v_25836 = (*qfn1(fn))(fn, v_25836);
    env = stack[-8];
    stack[-5] = v_25836;
    goto v_25678;
v_25680:
v_25678:
    goto v_25666;
v_25668:
v_25666:
    v_25836 = stack[0];
    stack[-3] = v_25836;
    v_25836 = stack[-3];
    if (v_25836 == nil) goto v_25702;
    else goto v_25703;
v_25702:
    v_25836 = nil;
    goto v_25697;
v_25703:
    v_25836 = stack[-3];
    v_25836 = qcar(v_25836);
    v_25836 = qcdr(v_25836);
    v_25836 = ncons(v_25836);
    env = stack[-8];
    stack[-1] = v_25836;
    stack[-2] = v_25836;
v_25698:
    v_25836 = stack[-3];
    v_25836 = qcdr(v_25836);
    stack[-3] = v_25836;
    v_25836 = stack[-3];
    if (v_25836 == nil) goto v_25716;
    else goto v_25717;
v_25716:
    v_25836 = stack[-2];
    goto v_25697;
v_25717:
    goto v_25725;
v_25721:
    stack[0] = stack[-1];
    goto v_25722;
v_25723:
    v_25836 = stack[-3];
    v_25836 = qcar(v_25836);
    v_25836 = qcdr(v_25836);
    v_25836 = ncons(v_25836);
    env = stack[-8];
    goto v_25724;
v_25725:
    goto v_25721;
v_25722:
    goto v_25723;
v_25724:
    v_25836 = Lrplacd(nil, stack[0], v_25836);
    env = stack[-8];
    v_25836 = stack[-1];
    v_25836 = qcdr(v_25836);
    stack[-1] = v_25836;
    goto v_25698;
v_25697:
    stack[0] = v_25836;
    goto v_25740;
v_25736:
    v_25837 = stack[0];
    goto v_25737;
v_25738:
    v_25836 = qvalue(elt(env, 2)); // mcond!*
    goto v_25739;
v_25740:
    goto v_25736;
v_25737:
    goto v_25738;
v_25739:
    fn = elt(env, 9); // smemql
    v_25836 = (*qfn2(fn))(fn, v_25837, v_25836);
    env = stack[-8];
    stack[-2] = v_25836;
    goto v_25748;
v_25744:
    v_25837 = stack[0];
    goto v_25745;
v_25746:
    v_25836 = stack[-6];
    goto v_25747;
v_25748:
    goto v_25744;
v_25745:
    goto v_25746;
v_25747:
    fn = elt(env, 9); // smemql
    v_25836 = (*qfn2(fn))(fn, v_25837, v_25836);
    env = stack[-8];
    stack[-1] = v_25836;
    goto v_25761;
v_25757:
    v_25837 = stack[-2];
    goto v_25758;
v_25759:
    v_25836 = stack[-1];
    goto v_25760;
v_25761:
    goto v_25757;
v_25758:
    goto v_25759;
v_25760:
    fn = elt(env, 10); // setdiff
    v_25837 = (*qfn2(fn))(fn, v_25837, v_25836);
    env = stack[-8];
    v_25836 = v_25837;
    if (v_25837 == nil) goto v_25755;
    else goto v_25753;
v_25755:
    goto v_25770;
v_25766:
    goto v_25776;
v_25772:
    goto v_25782;
v_25778:
    v_25837 = stack[0];
    goto v_25779;
v_25780:
    v_25836 = stack[-5];
    goto v_25781;
v_25782:
    goto v_25778;
v_25779:
    goto v_25780;
v_25781:
    fn = elt(env, 9); // smemql
    v_25837 = (*qfn2(fn))(fn, v_25837, v_25836);
    env = stack[-8];
    goto v_25773;
v_25774:
    v_25836 = stack[-2];
    goto v_25775;
v_25776:
    goto v_25772;
v_25773:
    goto v_25774;
v_25775:
    fn = elt(env, 10); // setdiff
    stack[0] = (*qfn2(fn))(fn, v_25837, v_25836);
    env = stack[-8];
    goto v_25767;
v_25768:
    goto v_25791;
v_25787:
    v_25837 = stack[-1];
    goto v_25788;
v_25789:
    v_25836 = stack[-2];
    goto v_25790;
v_25791:
    goto v_25787;
v_25788:
    goto v_25789;
v_25790:
    fn = elt(env, 10); // setdiff
    v_25836 = (*qfn2(fn))(fn, v_25837, v_25836);
    env = stack[-8];
    goto v_25769;
v_25770:
    goto v_25766;
v_25767:
    goto v_25768;
v_25769:
    fn = elt(env, 10); // setdiff
    v_25837 = (*qfn2(fn))(fn, stack[0], v_25836);
    env = stack[-8];
    v_25836 = v_25837;
    if (v_25837 == nil) goto v_25764;
    else goto v_25753;
v_25764:
    goto v_25754;
v_25753:
    goto v_25800;
v_25796:
    v_25837 = elt(env, 3); // "Unmatched free variable(s)"
    goto v_25797;
v_25798:
    goto v_25799;
v_25800:
    goto v_25796;
v_25797:
    goto v_25798;
v_25799:
    v_25836 = cons(v_25837, v_25836);
    env = stack[-8];
    fn = elt(env, 11); // lprie
    v_25836 = (*qfn1(fn))(fn, v_25836);
    env = stack[-8];
    v_25836 = elt(env, 4); // hold
    qvalue(elt(env, 5)) = v_25836; // erfg!*
    v_25836 = nil;
    goto v_25626;
v_25754:
    goto v_25812;
v_25808:
    v_25837 = stack[-6];
    goto v_25809;
v_25810:
    v_25836 = elt(env, 6); // getel
    goto v_25811;
v_25812:
    goto v_25808;
v_25809:
    goto v_25810;
v_25811:
    if (!consp(v_25837)) goto v_25806;
    v_25837 = qcar(v_25837);
    if (v_25837 == v_25836) goto v_25805;
    else goto v_25806;
v_25805:
    v_25836 = stack[-6];
    v_25836 = qcdr(v_25836);
    v_25836 = qcar(v_25836);
    fn = elt(env, 12); // lispeval
    v_25836 = (*qfn1(fn))(fn, v_25836);
    env = stack[-8];
    stack[-6] = v_25836;
    goto v_25752;
v_25806:
v_25752:
    goto v_25830;
v_25820:
    v_25840 = stack[-6];
    goto v_25821;
v_25822:
    v_25839 = stack[-5];
    goto v_25823;
v_25824:
    v_25838 = nil;
    goto v_25825;
v_25826:
    v_25837 = stack[-4];
    goto v_25827;
v_25828:
    v_25836 = stack[-7];
    goto v_25829;
v_25830:
    goto v_25820;
v_25821:
    goto v_25822;
v_25823:
    goto v_25824;
v_25825:
    goto v_25826;
v_25827:
    goto v_25828;
v_25829:
    {
        fn = elt(env, 13); // let3
        return (*qfnn(fn))(fn, 5, v_25840, v_25839, v_25838, v_25837, v_25836);
    }
v_25626:
    return onevalue(v_25836);
}



// Code for pasf_ceil

static LispObject CC_pasf_ceil(LispObject env,
                         LispObject v_25615, LispObject v_25616)
{
    env = qenv(env);
    LispObject v_25737, v_25738, v_25739;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25616,v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25615,v_25616);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_25616;
    stack[-1] = v_25615;
// end of prologue
    v_25737 = stack[-1];
    if (!consp(v_25737)) goto v_25628;
    else goto v_25629;
v_25628:
    v_25737 = lisp_true;
    goto v_25627;
v_25629:
    v_25737 = stack[-1];
    v_25737 = qcar(v_25737);
    v_25737 = (consp(v_25737) ? nil : lisp_true);
    goto v_25627;
    v_25737 = nil;
v_25627:
    if (v_25737 == nil) goto v_25625;
    v_25737 = stack[0];
    if (!consp(v_25737)) goto v_25639;
    else goto v_25640;
v_25639:
    v_25737 = lisp_true;
    goto v_25638;
v_25640:
    v_25737 = stack[0];
    v_25737 = qcar(v_25737);
    v_25737 = (consp(v_25737) ? nil : lisp_true);
    goto v_25638;
    v_25737 = nil;
v_25638:
    goto v_25623;
v_25625:
    v_25737 = nil;
    goto v_25623;
    v_25737 = nil;
v_25623:
    if (v_25737 == nil) goto v_25621;
    v_25737 = stack[-1];
    if (v_25737 == nil) goto v_25653;
    else goto v_25654;
v_25653:
    v_25737 = nil;
    goto v_25652;
v_25654:
    goto v_25668;
v_25664:
    goto v_25674;
v_25670:
    v_25738 = stack[-1];
    goto v_25671;
v_25672:
    v_25737 = stack[0];
    goto v_25673;
v_25674:
    goto v_25670;
v_25671:
    goto v_25672;
v_25673:
    v_25738 = Cremainder(v_25738, v_25737);
    env = stack[-2];
    goto v_25665;
v_25666:
    v_25737 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25667;
v_25668:
    goto v_25664;
v_25665:
    goto v_25666;
v_25667:
    if (v_25738 == v_25737) goto v_25662;
    else goto v_25663;
v_25662:
    goto v_25683;
v_25679:
    v_25738 = stack[-1];
    goto v_25680;
v_25681:
    v_25737 = stack[0];
    goto v_25682;
v_25683:
    goto v_25679;
v_25680:
    goto v_25681;
v_25682:
    v_25737 = quot2(v_25738, v_25737);
    env = stack[-2];
    goto v_25661;
v_25663:
    goto v_25693;
v_25689:
    goto v_25699;
v_25695:
    v_25738 = stack[-1];
    goto v_25696;
v_25697:
    v_25737 = stack[0];
    goto v_25698;
v_25699:
    goto v_25695;
v_25696:
    goto v_25697;
v_25698:
    v_25738 = times2(v_25738, v_25737);
    env = stack[-2];
    goto v_25690;
v_25691:
    v_25737 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25692;
v_25693:
    goto v_25689;
v_25690:
    goto v_25691;
v_25692:
    v_25737 = (LispObject)greaterp2(v_25738, v_25737);
    v_25737 = v_25737 ? lisp_true : nil;
    env = stack[-2];
    if (v_25737 == nil) goto v_25687;
    goto v_25709;
v_25705:
    v_25738 = stack[-1];
    goto v_25706;
v_25707:
    v_25737 = stack[0];
    goto v_25708;
v_25709:
    goto v_25705;
v_25706:
    goto v_25707;
v_25708:
    v_25737 = quot2(v_25738, v_25737);
    env = stack[-2];
    v_25737 = add1(v_25737);
    env = stack[-2];
    goto v_25661;
v_25687:
    goto v_25719;
v_25715:
    v_25738 = stack[-1];
    goto v_25716;
v_25717:
    v_25737 = stack[0];
    goto v_25718;
v_25719:
    goto v_25715;
v_25716:
    goto v_25717;
v_25718:
    v_25737 = quot2(v_25738, v_25737);
    env = stack[-2];
    goto v_25661;
    v_25737 = nil;
v_25661:
    fn = elt(env, 2); // simp
    v_25737 = (*qfn1(fn))(fn, v_25737);
    v_25737 = qcar(v_25737);
    goto v_25652;
    v_25737 = nil;
v_25652:
    goto v_25619;
v_25621:
    goto v_25733;
v_25727:
    v_25739 = elt(env, 1); // "pasf_ceil: not a domain valued sf in input"
    goto v_25728;
v_25729:
    v_25738 = stack[-1];
    goto v_25730;
v_25731:
    v_25737 = stack[0];
    goto v_25732;
v_25733:
    goto v_25727;
v_25728:
    goto v_25729;
v_25730:
    goto v_25731;
v_25732:
    v_25737 = list3(v_25739, v_25738, v_25737);
    env = stack[-2];
    {
        fn = elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_25737);
    }
    v_25737 = nil;
v_25619:
    return onevalue(v_25737);
}



// Code for vdp_mred

static LispObject CC_vdp_mred(LispObject env,
                         LispObject v_25615)
{
    env = qenv(env);
    LispObject v_25652, v_25653;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25615);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_25615;
// end of prologue
    v_25652 = stack[-1];
    fn = elt(env, 1); // vdp_poly
    v_25652 = (*qfn1(fn))(fn, v_25652);
    env = stack[-3];
    fn = elt(env, 2); // dip_mred
    v_25652 = (*qfn1(fn))(fn, v_25652);
    env = stack[-3];
    stack[-2] = v_25652;
    v_25652 = stack[-2];
    if (v_25652 == nil) goto v_25625;
    else goto v_25626;
v_25625:
    {
        fn = elt(env, 3); // vdp_zero
        return (*qfnn(fn))(fn, 0);
    }
v_25626:
    goto v_25636;
v_25630:
    v_25652 = stack[-2];
    fn = elt(env, 4); // dip_lbc
    stack[0] = (*qfn1(fn))(fn, v_25652);
    env = stack[-3];
    goto v_25631;
v_25632:
    v_25652 = stack[-2];
    fn = elt(env, 5); // dip_evlmon
    v_25653 = (*qfn1(fn))(fn, v_25652);
    env = stack[-3];
    goto v_25633;
v_25634:
    v_25652 = stack[-2];
    goto v_25635;
v_25636:
    goto v_25630;
v_25631:
    goto v_25632;
v_25633:
    goto v_25634;
v_25635:
    fn = elt(env, 6); // vdp_make
    v_25652 = (*qfnn(fn))(fn, 3, stack[0], v_25653, v_25652);
    env = stack[-3];
    stack[-2] = v_25652;
    goto v_25647;
v_25643:
    stack[0] = stack[-2];
    goto v_25644;
v_25645:
    v_25652 = stack[-1];
    fn = elt(env, 7); // vdp_sugar
    v_25652 = (*qfn1(fn))(fn, v_25652);
    env = stack[-3];
    goto v_25646;
v_25647:
    goto v_25643;
v_25644:
    goto v_25645;
v_25646:
    fn = elt(env, 8); // vdp_setsugar
    v_25652 = (*qfn2(fn))(fn, stack[0], v_25652);
    v_25652 = stack[-2];
    return onevalue(v_25652);
}



// Code for lowupperlimitml

static LispObject CC_lowupperlimitml(LispObject env,
                         LispObject v_25615)
{
    env = qenv(env);
    LispObject v_25644;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25615);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_25615;
// end of prologue
    v_25644 = elt(env, 1); // "<lowlimit>"
    fn = elt(env, 5); // printout
    v_25644 = (*qfn1(fn))(fn, v_25644);
    env = stack[-1];
    v_25644 = lisp_true;
    fn = elt(env, 6); // indent!*
    v_25644 = (*qfn1(fn))(fn, v_25644);
    env = stack[-1];
    v_25644 = stack[0];
    v_25644 = qcdr(v_25644);
    v_25644 = qcar(v_25644);
    fn = elt(env, 7); // expression
    v_25644 = (*qfn1(fn))(fn, v_25644);
    env = stack[-1];
    v_25644 = nil;
    fn = elt(env, 6); // indent!*
    v_25644 = (*qfn1(fn))(fn, v_25644);
    env = stack[-1];
    v_25644 = elt(env, 2); // "</lowlimit>"
    fn = elt(env, 5); // printout
    v_25644 = (*qfn1(fn))(fn, v_25644);
    env = stack[-1];
    v_25644 = elt(env, 3); // "<uplimit>"
    fn = elt(env, 5); // printout
    v_25644 = (*qfn1(fn))(fn, v_25644);
    env = stack[-1];
    v_25644 = lisp_true;
    fn = elt(env, 6); // indent!*
    v_25644 = (*qfn1(fn))(fn, v_25644);
    env = stack[-1];
    v_25644 = stack[0];
    v_25644 = qcdr(v_25644);
    v_25644 = qcdr(v_25644);
    v_25644 = qcar(v_25644);
    fn = elt(env, 7); // expression
    v_25644 = (*qfn1(fn))(fn, v_25644);
    env = stack[-1];
    v_25644 = nil;
    fn = elt(env, 6); // indent!*
    v_25644 = (*qfn1(fn))(fn, v_25644);
    env = stack[-1];
    v_25644 = elt(env, 4); // "</uplimit>"
    fn = elt(env, 5); // printout
    v_25644 = (*qfn1(fn))(fn, v_25644);
    v_25644 = nil;
    return onevalue(v_25644);
}



// Code for simpdf

static LispObject CC_simpdf(LispObject env,
                         LispObject v_25615)
{
    env = qenv(env);
    LispObject v_25912, v_25913;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_25615);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_25615;
// end of prologue
    stack[-3] = nil;
    v_25912 = qvalue(elt(env, 1)); // subfg!*
    if (v_25912 == nil) goto v_25626;
    else goto v_25627;
v_25626:
    goto v_25634;
v_25630:
    goto v_25640;
v_25636:
    v_25913 = elt(env, 2); // df
    goto v_25637;
v_25638:
    v_25912 = stack[-5];
    goto v_25639;
v_25640:
    goto v_25636;
v_25637:
    goto v_25638;
v_25639:
    v_25913 = cons(v_25913, v_25912);
    env = stack[-7];
    goto v_25631;
v_25632:
    v_25912 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25633;
v_25634:
    goto v_25630;
v_25631:
    goto v_25632;
v_25633:
    {
        fn = elt(env, 8); // mksq
        return (*qfn2(fn))(fn, v_25913, v_25912);
    }
v_25627:
    v_25912 = stack[-5];
    v_25912 = qcdr(v_25912);
    stack[-6] = v_25912;
    v_25912 = stack[-5];
    v_25912 = qcar(v_25912);
    fn = elt(env, 9); // simp!*
    v_25912 = (*qfn1(fn))(fn, v_25912);
    env = stack[-7];
    stack[-5] = v_25912;
v_25623:
    v_25912 = stack[-6];
    if (v_25912 == nil) goto v_25655;
    else goto v_25656;
v_25655:
    v_25912 = lisp_true;
    goto v_25654;
v_25656:
    v_25912 = stack[-5];
    v_25912 = qcar(v_25912);
    v_25912 = (v_25912 == nil ? lisp_true : nil);
    goto v_25654;
    v_25912 = nil;
v_25654:
    if (v_25912 == nil) goto v_25652;
    v_25912 = stack[-5];
    goto v_25622;
v_25652:
    v_25912 = stack[-3];
    if (v_25912 == nil) goto v_25671;
    else goto v_25672;
v_25671:
    v_25912 = lisp_true;
    goto v_25670;
v_25672:
    goto v_25681;
v_25677:
    v_25913 = stack[-3];
    goto v_25678;
v_25679:
    v_25912 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_25680;
v_25681:
    goto v_25677;
v_25678:
    goto v_25679;
v_25680:
    v_25912 = (v_25913 == v_25912 ? lisp_true : nil);
    goto v_25670;
    v_25912 = nil;
v_25670:
    if (v_25912 == nil) goto v_25668;
    v_25912 = stack[-6];
    v_25912 = qcar(v_25912);
    fn = elt(env, 9); // simp!*
    v_25912 = (*qfn1(fn))(fn, v_25912);
    env = stack[-7];
    goto v_25666;
v_25668:
    v_25912 = stack[-3];
    goto v_25666;
    v_25912 = nil;
v_25666:
    stack[-4] = v_25912;
    goto v_25703;
v_25699:
    v_25912 = stack[-4];
    v_25913 = qcdr(v_25912);
    goto v_25700;
v_25701:
    v_25912 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25702;
v_25703:
    goto v_25699;
v_25700:
    goto v_25701;
v_25702:
    if (v_25913 == v_25912) goto v_25698;
    v_25912 = lisp_true;
    goto v_25696;
v_25698:
    v_25912 = stack[-4];
    v_25912 = qcar(v_25912);
    v_25912 = (consp(v_25912) ? nil : lisp_true);
    goto v_25696;
    v_25912 = nil;
v_25696:
    if (v_25912 == nil) goto v_25694;
    goto v_25718;
v_25714:
    v_25912 = stack[-4];
    fn = elt(env, 10); // prepsq
    v_25913 = (*qfn1(fn))(fn, v_25912);
    env = stack[-7];
    goto v_25715;
v_25716:
    v_25912 = elt(env, 3); // "kernel or integer"
    goto v_25717;
v_25718:
    goto v_25714;
v_25715:
    goto v_25716;
v_25717:
    fn = elt(env, 11); // typerr
    v_25912 = (*qfn2(fn))(fn, v_25913, v_25912);
    env = stack[-7];
    goto v_25692;
v_25694:
    v_25912 = stack[-4];
    v_25912 = qcar(v_25912);
    stack[-2] = v_25912;
    v_25912 = stack[-2];
    if (!consp(v_25912)) goto v_25733;
    else goto v_25734;
v_25733:
    v_25912 = lisp_true;
    goto v_25732;
v_25734:
    v_25912 = stack[-2];
    v_25912 = qcar(v_25912);
    v_25912 = (consp(v_25912) ? nil : lisp_true);
    goto v_25732;
    v_25912 = nil;
v_25732:
    if (v_25912 == nil) goto v_25730;
    goto v_25751;
v_25747:
    v_25912 = stack[-2];
    v_25913 = qcar(v_25912);
    goto v_25748;
v_25749:
    v_25912 = elt(env, 4); // domain!-diff!-fn
    goto v_25750;
v_25751:
    goto v_25747;
v_25748:
    goto v_25749;
v_25750:
    v_25912 = get(v_25913, v_25912);
    env = stack[-7];
    if (v_25912 == nil) goto v_25745;
// Binding dmode!*
// FLUIDBIND: reloadenv=7 litvec-offset=5 saveloc=1
{   bind_fluid_stack bind_fluid_var(-7, 5, -1);
    qvalue(elt(env, 5)) = nil; // dmode!*
// Binding alglist!*
// FLUIDBIND: reloadenv=7 litvec-offset=6 saveloc=0
{   bind_fluid_stack bind_fluid_var(-7, 6, 0);
    qvalue(elt(env, 6)) = nil; // alglist!*
    v_25912 = nil;
    v_25912 = ncons(v_25912);
    env = stack[-7];
    qvalue(elt(env, 6)) = v_25912; // alglist!*
    v_25912 = stack[-2];
    fn = elt(env, 12); // prepf
    v_25912 = (*qfn1(fn))(fn, v_25912);
    env = stack[-7];
    stack[-4] = v_25912;
    v_25912 = stack[-4];
    fn = elt(env, 13); // prekernp
    v_25912 = (*qfn1(fn))(fn, v_25912);
    env = stack[-7];
    if (v_25912 == nil) goto v_25765;
    else goto v_25766;
v_25765:
    goto v_25774;
v_25770:
    v_25913 = stack[-4];
    goto v_25771;
v_25772:
    v_25912 = elt(env, 7); // "kernel"
    goto v_25773;
v_25774:
    goto v_25770;
v_25771:
    goto v_25772;
v_25773:
    fn = elt(env, 11); // typerr
    v_25912 = (*qfn2(fn))(fn, v_25913, v_25912);
    env = stack[-7];
    goto v_25764;
v_25766:
v_25764:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_25743;
v_25745:
    goto v_25784;
v_25780:
    v_25912 = stack[-2];
    fn = elt(env, 12); // prepf
    v_25913 = (*qfn1(fn))(fn, v_25912);
    env = stack[-7];
    goto v_25781;
v_25782:
    v_25912 = elt(env, 7); // "kernel"
    goto v_25783;
v_25784:
    goto v_25780;
v_25781:
    goto v_25782;
v_25783:
    fn = elt(env, 11); // typerr
    v_25912 = (*qfn2(fn))(fn, v_25913, v_25912);
    env = stack[-7];
    goto v_25743;
v_25743:
    goto v_25728;
v_25730:
    v_25912 = stack[-2];
    v_25912 = qcdr(v_25912);
    if (v_25912 == nil) goto v_25792;
    else goto v_25793;
v_25792:
    goto v_25804;
v_25800:
    v_25912 = stack[-2];
    v_25912 = qcar(v_25912);
    v_25913 = qcdr(v_25912);
    goto v_25801;
v_25802:
    v_25912 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25803;
v_25804:
    goto v_25800;
v_25801:
    goto v_25802;
v_25803:
    if (v_25913 == v_25912) goto v_25798;
    else goto v_25799;
v_25798:
    goto v_25813;
v_25809:
    v_25912 = stack[-2];
    v_25912 = qcar(v_25912);
    v_25912 = qcar(v_25912);
    v_25913 = qcdr(v_25912);
    goto v_25810;
v_25811:
    v_25912 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_25812;
v_25813:
    goto v_25809;
v_25810:
    goto v_25811;
v_25812:
    v_25912 = (v_25913 == v_25912 ? lisp_true : nil);
    goto v_25797;
v_25799:
    v_25912 = nil;
    goto v_25797;
    v_25912 = nil;
v_25797:
    goto v_25791;
v_25793:
    v_25912 = nil;
    goto v_25791;
    v_25912 = nil;
v_25791:
    if (v_25912 == nil) goto v_25789;
    v_25912 = stack[-2];
    v_25912 = qcar(v_25912);
    v_25912 = qcar(v_25912);
    v_25912 = qcar(v_25912);
    stack[-4] = v_25912;
    goto v_25728;
v_25789:
    goto v_25837;
v_25833:
    v_25912 = stack[-2];
    fn = elt(env, 12); // prepf
    v_25913 = (*qfn1(fn))(fn, v_25912);
    env = stack[-7];
    goto v_25834;
v_25835:
    v_25912 = elt(env, 7); // "kernel"
    goto v_25836;
v_25837:
    goto v_25833;
v_25834:
    goto v_25835;
v_25836:
    fn = elt(env, 11); // typerr
    v_25912 = (*qfn2(fn))(fn, v_25913, v_25912);
    env = stack[-7];
    goto v_25728;
v_25728:
    goto v_25692;
v_25692:
    v_25912 = stack[-6];
    v_25912 = qcdr(v_25912);
    stack[-6] = v_25912;
    v_25912 = stack[-6];
    if (v_25912 == nil) goto v_25845;
    else goto v_25846;
v_25845:
    goto v_25853;
v_25849:
    v_25913 = stack[-5];
    goto v_25850;
v_25851:
    v_25912 = stack[-4];
    goto v_25852;
v_25853:
    goto v_25849;
v_25850:
    goto v_25851;
v_25852:
    fn = elt(env, 14); // diffsq
    v_25912 = (*qfn2(fn))(fn, v_25913, v_25912);
    env = stack[-7];
    stack[-5] = v_25912;
    goto v_25623;
v_25846:
    v_25912 = stack[-6];
    v_25912 = qcar(v_25912);
    fn = elt(env, 9); // simp!*
    v_25912 = (*qfn1(fn))(fn, v_25912);
    env = stack[-7];
    stack[-3] = v_25912;
    v_25912 = stack[-3];
    v_25912 = qcar(v_25912);
    if (v_25912 == nil) goto v_25861;
    else goto v_25862;
v_25861:
    v_25912 = stack[-6];
    v_25912 = qcdr(v_25912);
    stack[-6] = v_25912;
    v_25912 = nil;
    stack[-3] = v_25912;
    goto v_25623;
v_25862:
    v_25912 = stack[-3];
    fn = elt(env, 15); // d2int
    v_25912 = (*qfn1(fn))(fn, v_25912);
    env = stack[-7];
    stack[0] = v_25912;
    if (v_25912 == nil) goto v_25868;
    else goto v_25869;
v_25868:
    goto v_25877;
v_25873:
    v_25913 = stack[-5];
    goto v_25874;
v_25875:
    v_25912 = stack[-4];
    goto v_25876;
v_25877:
    goto v_25873;
v_25874:
    goto v_25875;
v_25876:
    fn = elt(env, 14); // diffsq
    v_25912 = (*qfn2(fn))(fn, v_25913, v_25912);
    env = stack[-7];
    stack[-5] = v_25912;
    goto v_25623;
v_25869:
    v_25912 = stack[-6];
    v_25912 = qcdr(v_25912);
    stack[-6] = v_25912;
    v_25912 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_25912;
v_25885:
    goto v_25897;
v_25893:
    v_25913 = stack[0];
    goto v_25894;
v_25895:
    v_25912 = stack[-1];
    goto v_25896;
v_25897:
    goto v_25893;
v_25894:
    goto v_25895;
v_25896:
    v_25912 = difference2(v_25913, v_25912);
    env = stack[-7];
    v_25912 = Lminusp(nil, v_25912);
    env = stack[-7];
    if (v_25912 == nil) goto v_25890;
    goto v_25884;
v_25890:
    goto v_25906;
v_25902:
    v_25913 = stack[-5];
    goto v_25903;
v_25904:
    v_25912 = stack[-4];
    goto v_25905;
v_25906:
    goto v_25902;
v_25903:
    goto v_25904;
v_25905:
    fn = elt(env, 14); // diffsq
    v_25912 = (*qfn2(fn))(fn, v_25913, v_25912);
    env = stack[-7];
    stack[-5] = v_25912;
    v_25912 = stack[-1];
    v_25912 = add1(v_25912);
    env = stack[-7];
    stack[-1] = v_25912;
    goto v_25885;
v_25884:
    v_25912 = nil;
    stack[-3] = v_25912;
    goto v_25623;
v_25622:
    return onevalue(v_25912);
}



// Code for gfstorval

static LispObject CC_gfstorval(LispObject env,
                         LispObject v_25615, LispObject v_25616)
{
    env = qenv(env);
    LispObject v_25629, v_25630, v_25631;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25616,v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25615,v_25616);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_25629 = v_25616;
    v_25630 = v_25615;
// end of prologue
    goto v_25625;
v_25619:
    v_25631 = v_25630;
    goto v_25620;
v_25621:
    v_25630 = v_25629;
    goto v_25622;
v_25623:
    v_25629 = qvalue(elt(env, 1)); // !*xnlist
    goto v_25624;
v_25625:
    goto v_25619;
v_25620:
    goto v_25621;
v_25622:
    goto v_25623;
v_25624:
    v_25629 = acons(v_25631, v_25630, v_25629);
    env = stack[0];
    qvalue(elt(env, 1)) = v_25629; // !*xnlist
    return onevalue(v_25629);
}



// Code for evalletsub

static LispObject CC_evalletsub(LispObject env,
                         LispObject v_25615, LispObject v_25616)
{
    env = qenv(env);
    LispObject v_25646, v_25647, v_25648;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_25616,v_25615);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_25615,v_25616);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_25646 = v_25616;
    stack[0] = v_25615;
// end of prologue
    goto v_25628;
v_25624:
    v_25647 = stack[0];
    goto v_25625;
v_25626:
    goto v_25627;
v_25628:
    goto v_25624;
v_25625:
    goto v_25626;
v_25627:
    fn = elt(env, 3); // evalletsub2
    v_25646 = (*qfn2(fn))(fn, v_25647, v_25646);
    env = stack[-1];
    stack[0] = v_25646;
    fn = elt(env, 4); // errorp
    v_25646 = (*qfn1(fn))(fn, v_25646);
    env = stack[-1];
    if (v_25646 == nil) goto v_25621;
    goto v_25638;
v_25632:
    v_25648 = elt(env, 1); // alg
    goto v_25633;
v_25634:
    v_25647 = (LispObject)384+TAG_FIXNUM; // 24
    goto v_25635;
v_25636:
    v_25646 = elt(env, 2); // "Invalid simplification"
    goto v_25637;
v_25638:
    goto v_25632;
v_25633:
    goto v_25634;
v_25635:
    goto v_25636;
v_25637:
    {
        fn = elt(env, 5); // rerror
        return (*qfnn(fn))(fn, 3, v_25648, v_25647, v_25646);
    }
v_25621:
    v_25646 = stack[0];
    v_25646 = qcar(v_25646);
    goto v_25619;
    v_25646 = nil;
v_25619:
    return onevalue(v_25646);
}



setup_type const u45_setup[] =
{
    {"gigcdsq",                 TOO_FEW_2,      CC_gigcdsq,    WRONG_NO_2},
    {"simpexpt2",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_simpexpt2},
    {"enter-sorted",            TOO_FEW_2,      CC_enterKsorted,WRONG_NO_2},
    {"iv_cutn",                 CC_iv_cutn,     TOO_MANY_1,    WRONG_NO_1},
    {"conditionrd",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_conditionrd},
    {"znumrnil",                CC_znumrnil,    TOO_MANY_1,    WRONG_NO_1},
    {"diffp",                   TOO_FEW_2,      CC_diffp,      WRONG_NO_2},
    {"ndepends",                TOO_FEW_2,      CC_ndepends,   WRONG_NO_2},
    {"xpartitop",               CC_xpartitop,   TOO_MANY_1,    WRONG_NO_1},
    {"all_defined_map_",        TOO_FEW_2,      CC_all_defined_map_,WRONG_NO_2},
    {"mkcrn",                   TOO_FEW_2,      CC_mkcrn,      WRONG_NO_2},
    {"nlist",                   TOO_FEW_2,      CC_nlist,      WRONG_NO_2},
    {"makecoeffpairshom",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_makecoeffpairshom},
    {"cols2rows2",              TOO_FEW_2,      CC_cols2rows2, WRONG_NO_2},
    {"ldf-dep-var",             CC_ldfKdepKvar, TOO_MANY_1,    WRONG_NO_1},
    {"findhr",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_findhr},
    {"make_spoly_pair",         TOO_FEW_2,      CC_make_spoly_pair,WRONG_NO_2},
    {"simpsetdiff",             CC_simpsetdiff, TOO_MANY_1,    WRONG_NO_1},
    {"rat_leq",                 TOO_FEW_2,      CC_rat_leq,    WRONG_NO_2},
    {"rl_nnfnot",               CC_rl_nnfnot,   TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_simplequal",         TOO_FEW_2,      CC_ofsf_simplequal,WRONG_NO_2},
    {"rule",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rule},
    {"pasf_ceil",               TOO_FEW_2,      CC_pasf_ceil,  WRONG_NO_2},
    {"vdp_mred",                CC_vdp_mred,    TOO_MANY_1,    WRONG_NO_1},
    {"lowupperlimitml",         CC_lowupperlimitml,TOO_MANY_1, WRONG_NO_1},
    {"simpdf",                  CC_simpdf,      TOO_MANY_1,    WRONG_NO_1},
    {"gfstorval",               TOO_FEW_2,      CC_gfstorval,  WRONG_NO_2},
    {"evalletsub",              TOO_FEW_2,      CC_evalletsub, WRONG_NO_2},
    {NULL, (one_args *)"u45", (two_args *)"88129 2371418 8843889", 0}
};

// end of generated code
