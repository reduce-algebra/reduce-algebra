
// $destdir/u18.c        Machine generated C code

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



// Code for ibalp_initwl

static LispObject CC_ibalp_initwl(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10551, v_10552;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10311);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_10551 = v_10311;
// end of prologue
    stack[-4] = nil;
    stack[-2] = v_10551;
v_10321:
    v_10551 = stack[-2];
    if (v_10551 == nil) goto v_10325;
    else goto v_10326;
v_10325:
    goto v_10320;
v_10326:
    v_10551 = stack[-2];
    v_10551 = qcar(v_10551);
    stack[-1] = v_10551;
    v_10551 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_10551;
    v_10551 = stack[-1];
    v_10551 = qcar(v_10551);
    stack[-3] = v_10551;
v_10337:
    goto v_10351;
v_10347:
    v_10552 = stack[-5];
    goto v_10348;
v_10349:
    v_10551 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10350;
v_10351:
    goto v_10347;
v_10348:
    goto v_10349;
v_10350:
    v_10551 = Leqn(nil, v_10552, v_10551);
    env = stack[-6];
    if (v_10551 == nil) goto v_10344;
    else goto v_10345;
v_10344:
    v_10551 = stack[-3];
    goto v_10343;
v_10345:
    v_10551 = nil;
    goto v_10343;
    v_10551 = nil;
v_10343:
    if (v_10551 == nil) goto v_10340;
    else goto v_10341;
v_10340:
    goto v_10336;
v_10341:
    goto v_10364;
v_10360:
    v_10551 = stack[-1];
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    stack[0] = qcdr(v_10551);
    goto v_10361;
v_10362:
    goto v_10377;
v_10373:
    v_10551 = stack[-3];
    v_10552 = qcar(v_10551);
    goto v_10374;
v_10375:
    v_10551 = stack[-1];
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcar(v_10551);
    goto v_10376;
v_10377:
    goto v_10373;
v_10374:
    goto v_10375;
v_10376:
    v_10551 = cons(v_10552, v_10551);
    env = stack[-6];
    goto v_10363;
v_10364:
    goto v_10360;
v_10361:
    goto v_10362;
v_10363:
    fn = elt(env, 1); // setcar
    v_10551 = (*qfn2(fn))(fn, stack[0], v_10551);
    env = stack[-6];
    goto v_10393;
v_10389:
    v_10551 = stack[-3];
    v_10551 = qcar(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    stack[0] = qcdr(v_10551);
    goto v_10390;
v_10391:
    goto v_10411;
v_10407:
    v_10552 = stack[-1];
    goto v_10408;
v_10409:
    v_10551 = stack[-3];
    v_10551 = qcar(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcar(v_10551);
    goto v_10410;
v_10411:
    goto v_10407;
v_10408:
    goto v_10409;
v_10410:
    v_10551 = cons(v_10552, v_10551);
    env = stack[-6];
    goto v_10392;
v_10393:
    goto v_10389;
v_10390:
    goto v_10391;
v_10392:
    fn = elt(env, 1); // setcar
    v_10551 = (*qfn2(fn))(fn, stack[0], v_10551);
    env = stack[-6];
    v_10551 = stack[-5];
    v_10551 = add1(v_10551);
    env = stack[-6];
    stack[-5] = v_10551;
    v_10551 = stack[-3];
    v_10551 = qcdr(v_10551);
    stack[-3] = v_10551;
    goto v_10337;
v_10336:
    v_10551 = stack[-1];
    v_10551 = qcdr(v_10551);
    v_10551 = qcar(v_10551);
    stack[-3] = v_10551;
v_10435:
    goto v_10449;
v_10445:
    v_10552 = stack[-5];
    goto v_10446;
v_10447:
    v_10551 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10448;
v_10449:
    goto v_10445;
v_10446:
    goto v_10447;
v_10448:
    v_10551 = Leqn(nil, v_10552, v_10551);
    env = stack[-6];
    if (v_10551 == nil) goto v_10442;
    else goto v_10443;
v_10442:
    v_10551 = stack[-3];
    goto v_10441;
v_10443:
    v_10551 = nil;
    goto v_10441;
    v_10551 = nil;
v_10441:
    if (v_10551 == nil) goto v_10438;
    else goto v_10439;
v_10438:
    goto v_10434;
v_10439:
    goto v_10462;
v_10458:
    v_10551 = stack[-1];
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    stack[0] = qcdr(v_10551);
    goto v_10459;
v_10460:
    goto v_10475;
v_10471:
    v_10551 = stack[-3];
    v_10552 = qcar(v_10551);
    goto v_10472;
v_10473:
    v_10551 = stack[-1];
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcar(v_10551);
    goto v_10474;
v_10475:
    goto v_10471;
v_10472:
    goto v_10473;
v_10474:
    v_10551 = cons(v_10552, v_10551);
    env = stack[-6];
    goto v_10461;
v_10462:
    goto v_10458;
v_10459:
    goto v_10460;
v_10461:
    fn = elt(env, 1); // setcar
    v_10551 = (*qfn2(fn))(fn, stack[0], v_10551);
    env = stack[-6];
    goto v_10491;
v_10487:
    v_10551 = stack[-3];
    v_10551 = qcar(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    stack[0] = qcdr(v_10551);
    goto v_10488;
v_10489:
    goto v_10509;
v_10505:
    v_10552 = stack[-1];
    goto v_10506;
v_10507:
    v_10551 = stack[-3];
    v_10551 = qcar(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcdr(v_10551);
    v_10551 = qcar(v_10551);
    goto v_10508;
v_10509:
    goto v_10505;
v_10506:
    goto v_10507;
v_10508:
    v_10551 = cons(v_10552, v_10551);
    env = stack[-6];
    goto v_10490;
v_10491:
    goto v_10487;
v_10488:
    goto v_10489;
v_10490:
    fn = elt(env, 1); // setcar
    v_10551 = (*qfn2(fn))(fn, stack[0], v_10551);
    env = stack[-6];
    v_10551 = stack[-5];
    v_10551 = add1(v_10551);
    env = stack[-6];
    stack[-5] = v_10551;
    v_10551 = stack[-3];
    v_10551 = qcdr(v_10551);
    stack[-3] = v_10551;
    goto v_10435;
v_10434:
    goto v_10537;
v_10533:
    v_10552 = stack[-5];
    goto v_10534;
v_10535:
    v_10551 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10536;
v_10537:
    goto v_10533;
v_10534:
    goto v_10535;
v_10536:
    v_10551 = (LispObject)lessp2(v_10552, v_10551);
    v_10551 = v_10551 ? lisp_true : nil;
    env = stack[-6];
    if (v_10551 == nil) goto v_10531;
    goto v_10545;
v_10541:
    v_10552 = stack[-1];
    goto v_10542;
v_10543:
    v_10551 = stack[-4];
    goto v_10544;
v_10545:
    goto v_10541;
v_10542:
    goto v_10543;
v_10544:
    v_10551 = cons(v_10552, v_10551);
    env = stack[-6];
    stack[-4] = v_10551;
    goto v_10529;
v_10531:
v_10529:
    v_10551 = stack[-2];
    v_10551 = qcdr(v_10551);
    stack[-2] = v_10551;
    goto v_10321;
v_10320:
    v_10551 = stack[-4];
    return onevalue(v_10551);
}



// Code for variableom

static LispObject CC_variableom(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10366, v_10367;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10311);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10311;
// end of prologue
    goto v_10320;
v_10316:
    v_10366 = stack[0];
    v_10367 = Lintern(nil, v_10366);
    env = stack[-2];
    goto v_10317;
v_10318:
    v_10366 = qvalue(elt(env, 1)); // constantsom!*
    goto v_10319;
v_10320:
    goto v_10316;
v_10317:
    goto v_10318;
v_10319:
    v_10366 = Lassoc(nil, v_10367, v_10366);
    stack[-1] = v_10366;
    v_10366 = stack[-1];
    if (v_10366 == nil) goto v_10328;
    v_10366 = elt(env, 2); // "<OMS "
    fn = elt(env, 8); // printout
    v_10366 = (*qfn1(fn))(fn, v_10366);
    env = stack[-2];
    v_10366 = elt(env, 3); // "cd="""
    v_10366 = Lprinc(nil, v_10366);
    env = stack[-2];
    v_10366 = stack[-1];
    v_10366 = qcdr(v_10366);
    v_10366 = qcar(v_10366);
    v_10366 = Lprinc(nil, v_10366);
    env = stack[-2];
    v_10366 = elt(env, 4); // """ "
    v_10366 = Lprinc(nil, v_10366);
    env = stack[-2];
    v_10366 = elt(env, 5); // "name="""
    v_10366 = Lprinc(nil, v_10366);
    env = stack[-2];
    v_10366 = stack[-1];
    v_10366 = qcdr(v_10366);
    v_10366 = qcdr(v_10366);
    v_10366 = qcar(v_10366);
    v_10366 = Lprinc(nil, v_10366);
    env = stack[-2];
    v_10366 = elt(env, 6); // """/>"
    v_10366 = Lprinc(nil, v_10366);
    goto v_10326;
v_10328:
    v_10366 = stack[0];
    if (v_10366 == nil) goto v_10355;
    v_10366 = elt(env, 7); // "<OMV "
    fn = elt(env, 8); // printout
    v_10366 = (*qfn1(fn))(fn, v_10366);
    env = stack[-2];
    v_10366 = elt(env, 5); // "name="""
    v_10366 = Lprinc(nil, v_10366);
    env = stack[-2];
    v_10366 = stack[0];
    v_10366 = Lprinc(nil, v_10366);
    env = stack[-2];
    v_10366 = elt(env, 6); // """/>"
    v_10366 = Lprinc(nil, v_10366);
    goto v_10353;
v_10355:
v_10353:
    goto v_10326;
v_10326:
    v_10366 = nil;
    return onevalue(v_10366);
}



// Code for onoff

static LispObject CC_onoff(LispObject env,
                         LispObject v_10311, LispObject v_10312)
{
    env = qenv(env);
    LispObject v_10438, v_10439, v_10440;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10311,v_10312);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_10312;
    stack[0] = v_10311;
// end of prologue
    v_10438 = stack[0];
    if (symbolp(v_10438)) goto v_10321;
    goto v_10328;
v_10324:
    v_10439 = stack[0];
    goto v_10325;
v_10326:
    v_10438 = elt(env, 1); // "switch"
    goto v_10327;
v_10328:
    goto v_10324;
v_10325:
    goto v_10326;
v_10327:
    fn = elt(env, 9); // typerr
    v_10438 = (*qfn2(fn))(fn, v_10439, v_10438);
    env = stack[-4];
    goto v_10319;
v_10321:
    v_10438 = stack[0];
    if (!symbolp(v_10438)) v_10438 = nil;
    else { v_10438 = qfastgets(v_10438);
           if (v_10438 != nil) { v_10438 = elt(v_10438, 51); // switch
#ifdef RECORD_GET
             if (v_10438 == SPID_NOPROP)
                record_get(elt(fastget_names, 51), 0),
                v_10438 = nil;
             else record_get(elt(fastget_names, 51), 1),
                v_10438 = lisp_true; }
           else record_get(elt(fastget_names, 51), 0); }
#else
             if (v_10438 == SPID_NOPROP) v_10438 = nil; else v_10438 = lisp_true; }}
#endif
    if (v_10438 == nil) goto v_10331;
    else goto v_10332;
v_10331:
    goto v_10342;
v_10336:
    stack[-3] = elt(env, 2); // rlisp
    goto v_10337;
v_10338:
    stack[-1] = (LispObject)400+TAG_FIXNUM; // 25
    goto v_10339;
v_10340:
    goto v_10350;
v_10346:
    v_10439 = stack[0];
    goto v_10347;
v_10348:
    v_10438 = elt(env, 3); // "not defined as switch"
    goto v_10349;
v_10350:
    goto v_10346;
v_10347:
    goto v_10348;
v_10349:
    v_10438 = list2(v_10439, v_10438);
    env = stack[-4];
    goto v_10341;
v_10342:
    goto v_10336;
v_10337:
    goto v_10338;
v_10339:
    goto v_10340;
v_10341:
    fn = elt(env, 10); // rerror
    v_10438 = (*qfnn(fn))(fn, 3, stack[-3], stack[-1], v_10438);
    env = stack[-4];
    goto v_10319;
v_10332:
v_10319:
    goto v_10360;
v_10356:
    stack[-1] = elt(env, 4); // !*
    goto v_10357;
v_10358:
    v_10438 = stack[0];
    v_10438 = Lexplodec(nil, v_10438);
    env = stack[-4];
    goto v_10359;
v_10360:
    goto v_10356;
v_10357:
    goto v_10358;
v_10359:
    v_10438 = cons(stack[-1], v_10438);
    env = stack[-4];
    fn = elt(env, 11); // list2string
    v_10438 = (*qfn1(fn))(fn, v_10438);
    env = stack[-4];
    v_10438 = Lintern(nil, v_10438);
    env = stack[-4];
    stack[-3] = v_10438;
    v_10438 = qvalue(elt(env, 5)); // !*switchcheck
    if (v_10438 == nil) goto v_10367;
    goto v_10375;
v_10371:
    v_10438 = stack[-3];
    fn = elt(env, 12); // lispeval
    v_10439 = (*qfn1(fn))(fn, v_10438);
    env = stack[-4];
    goto v_10372;
v_10373:
    v_10438 = stack[-2];
    goto v_10374;
v_10375:
    goto v_10371;
v_10372:
    goto v_10373;
v_10374:
    if (v_10439 == v_10438) goto v_10370;
    else goto v_10367;
v_10370:
    v_10438 = nil;
    goto v_10317;
v_10367:
    goto v_10386;
v_10382:
    v_10440 = stack[-2];
    goto v_10383;
v_10384:
    goto v_10393;
v_10389:
    v_10439 = stack[0];
    goto v_10390;
v_10391:
    v_10438 = elt(env, 6); // simpfg
    goto v_10392;
v_10393:
    goto v_10389;
v_10390:
    goto v_10391;
v_10392:
    v_10438 = get(v_10439, v_10438);
    env = stack[-4];
    goto v_10385;
v_10386:
    goto v_10382;
v_10383:
    goto v_10384;
v_10385:
    v_10438 = Latsoc(nil, v_10440, v_10438);
    v_10439 = v_10438;
    if (v_10438 == nil) goto v_10381;
    goto v_10403;
v_10399:
    stack[-1] = elt(env, 7); // progn
    goto v_10400;
v_10401:
    goto v_10410;
v_10406:
    v_10438 = v_10439;
    stack[0] = qcdr(v_10438);
    goto v_10407;
v_10408:
    v_10438 = nil;
    v_10438 = ncons(v_10438);
    env = stack[-4];
    goto v_10409;
v_10410:
    goto v_10406;
v_10407:
    goto v_10408;
v_10409:
    v_10438 = Lappend(nil, stack[0], v_10438);
    env = stack[-4];
    goto v_10402;
v_10403:
    goto v_10399;
v_10400:
    goto v_10401;
v_10402:
    v_10438 = cons(stack[-1], v_10438);
    env = stack[-4];
    fn = elt(env, 12); // lispeval
    v_10438 = (*qfn1(fn))(fn, v_10438);
    env = stack[-4];
    goto v_10365;
v_10381:
v_10365:
    v_10438 = stack[-2];
    if (v_10438 == nil) goto v_10418;
    goto v_10426;
v_10422:
    v_10439 = stack[-3];
    goto v_10423;
v_10424:
    v_10438 = elt(env, 8); // !*raise
    goto v_10425;
v_10426:
    goto v_10422;
v_10423:
    goto v_10424;
v_10425:
    if (v_10439 == v_10438) goto v_10421;
    else goto v_10418;
v_10421:
    v_10438 = elt(env, 8); // !*raise
    stack[-3] = v_10438;
    goto v_10416;
v_10418:
v_10416:
    goto v_10435;
v_10431:
    v_10439 = stack[-3];
    goto v_10432;
v_10433:
    v_10438 = stack[-2];
    goto v_10434;
v_10435:
    goto v_10431;
v_10432:
    goto v_10433;
v_10434:
    v_10438 = Lset(nil, v_10439, v_10438);
    v_10438 = nil;
v_10317:
    return onevalue(v_10438);
}



// Code for unchecked_getmatelem

static LispObject CC_unchecked_getmatelem(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10374, v_10375, v_10376;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10311);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_10311;
// end of prologue
    goto v_10325;
v_10321:
    v_10374 = stack[-1];
    v_10375 = qcar(v_10374);
    v_10376 = v_10375;
    goto v_10322;
v_10323:
    v_10374 = elt(env, 1); // mat
    goto v_10324;
v_10325:
    goto v_10321;
v_10322:
    goto v_10323;
v_10324:
    if (!consp(v_10375)) goto v_10318;
    v_10375 = qcar(v_10375);
    if (v_10375 == v_10374) goto v_10319;
v_10318:
    goto v_10336;
v_10330:
    stack[-2] = elt(env, 2); // matrix
    goto v_10331;
v_10332:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10333;
v_10334:
    goto v_10346;
v_10340:
    v_10376 = elt(env, 3); // "Matrix"
    goto v_10341;
v_10342:
    v_10374 = stack[-1];
    v_10375 = qcar(v_10374);
    goto v_10343;
v_10344:
    v_10374 = elt(env, 4); // "not set"
    goto v_10345;
v_10346:
    goto v_10340;
v_10341:
    goto v_10342;
v_10343:
    goto v_10344;
v_10345:
    v_10374 = list3(v_10376, v_10375, v_10374);
    env = stack[-3];
    goto v_10335;
v_10336:
    goto v_10330;
v_10331:
    goto v_10332;
v_10333:
    goto v_10334;
v_10335:
    fn = elt(env, 5); // rerror
    v_10374 = (*qfnn(fn))(fn, 3, stack[-2], stack[0], v_10374);
    goto v_10317;
v_10319:
    goto v_10358;
v_10354:
    goto v_10364;
v_10360:
    v_10374 = v_10376;
    v_10375 = qcdr(v_10374);
    goto v_10361;
v_10362:
    v_10374 = stack[-1];
    v_10374 = qcdr(v_10374);
    v_10374 = qcar(v_10374);
    goto v_10363;
v_10364:
    goto v_10360;
v_10361:
    goto v_10362;
v_10363:
    fn = elt(env, 6); // nth
    v_10375 = (*qfn2(fn))(fn, v_10375, v_10374);
    env = stack[-3];
    goto v_10355;
v_10356:
    v_10374 = stack[-1];
    v_10374 = qcdr(v_10374);
    v_10374 = qcdr(v_10374);
    v_10374 = qcar(v_10374);
    goto v_10357;
v_10358:
    goto v_10354;
v_10355:
    goto v_10356;
v_10357:
    {
        fn = elt(env, 6); // nth
        return (*qfn2(fn))(fn, v_10375, v_10374);
    }
v_10317:
    v_10374 = nil;
    return onevalue(v_10374);
}



// Code for guesspftype

static LispObject CC_guesspftype(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10355, v_10356;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10311);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10311;
// end of prologue
    v_10355 = stack[0];
    if (!consp(v_10355)) goto v_10315;
    else goto v_10316;
v_10315:
    v_10355 = stack[0];
    goto v_10314;
v_10316:
    goto v_10325;
v_10321:
    v_10355 = stack[0];
    v_10356 = qcar(v_10355);
    goto v_10322;
v_10323:
    v_10355 = elt(env, 1); // (wedge d partdf hodge innerprod liedf)
    goto v_10324;
v_10325:
    goto v_10321;
v_10322:
    goto v_10323;
v_10324:
    v_10355 = Lmemq(nil, v_10356, v_10355);
    if (v_10355 == nil) goto v_10320;
    v_10355 = stack[0];
    goto v_10314;
v_10320:
    goto v_10338;
v_10334:
    v_10355 = stack[0];
    v_10355 = qcdr(v_10355);
    v_10356 = Llength(nil, v_10355);
    env = stack[-1];
    goto v_10335;
v_10336:
    v_10355 = stack[0];
    v_10355 = qcar(v_10355);
    if (!symbolp(v_10355)) v_10355 = nil;
    else { v_10355 = qfastgets(v_10355);
           if (v_10355 != nil) { v_10355 = elt(v_10355, 25); // ifdegree
#ifdef RECORD_GET
             if (v_10355 != SPID_NOPROP)
                record_get(elt(fastget_names, 25), 1);
             else record_get(elt(fastget_names, 25), 0),
                v_10355 = nil; }
           else record_get(elt(fastget_names, 25), 0); }
#else
             if (v_10355 == SPID_NOPROP) v_10355 = nil; }}
#endif
    goto v_10337;
v_10338:
    goto v_10334;
v_10335:
    goto v_10336;
v_10337:
    v_10355 = Lassoc(nil, v_10356, v_10355);
    if (v_10355 == nil) goto v_10332;
    v_10355 = stack[0];
    v_10355 = qcdr(v_10355);
    fn = elt(env, 2); // xvarlistp
    v_10355 = (*qfn1(fn))(fn, v_10355);
    env = stack[-1];
    if (v_10355 == nil) goto v_10346;
    else goto v_10332;
v_10346:
    v_10355 = stack[0];
    goto v_10314;
v_10332:
    v_10355 = stack[0];
    {
        fn = elt(env, 3); // mknwedge
        return (*qfn1(fn))(fn, v_10355);
    }
    v_10355 = nil;
v_10314:
    return onevalue(v_10355);
}



// Code for deleteall

static LispObject CC_deleteall(LispObject env,
                         LispObject v_10311, LispObject v_10312)
{
    env = qenv(env);
    LispObject v_10349, v_10350, v_10351, v_10352;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10311,v_10312);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10312;
    stack[-1] = v_10311;
// end of prologue
    v_10351 = nil;
v_10318:
    v_10349 = stack[0];
    if (v_10349 == nil) goto v_10321;
    else goto v_10322;
v_10321:
    v_10349 = v_10351;
    goto v_10317;
v_10322:
    v_10349 = stack[0];
    v_10349 = qcar(v_10349);
    v_10352 = v_10349;
    v_10349 = stack[0];
    v_10349 = qcdr(v_10349);
    stack[0] = v_10349;
    goto v_10337;
v_10333:
    v_10350 = v_10352;
    goto v_10334;
v_10335:
    v_10349 = stack[-1];
    goto v_10336;
v_10337:
    goto v_10333;
v_10334:
    goto v_10335;
v_10336:
    if (equal(v_10350, v_10349)) goto v_10332;
    goto v_10345;
v_10341:
    stack[-2] = v_10351;
    goto v_10342;
v_10343:
    v_10349 = v_10352;
    v_10349 = ncons(v_10349);
    env = stack[-3];
    goto v_10344;
v_10345:
    goto v_10341;
v_10342:
    goto v_10343;
v_10344:
    v_10349 = Lnconc(nil, stack[-2], v_10349);
    env = stack[-3];
    v_10351 = v_10349;
    goto v_10330;
v_10332:
v_10330:
    goto v_10318;
v_10317:
    return onevalue(v_10349);
}



// Code for cstimes

static LispObject CC_cstimes(LispObject env,
                         LispObject v_10311, LispObject v_10312)
{
    env = qenv(env);
    LispObject v_10371, v_10372, v_10373, v_10374;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10311,v_10312);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10372 = v_10312;
    v_10373 = v_10311;
// end of prologue
v_10317:
    v_10371 = v_10373;
    if (v_10371 == nil) goto v_10320;
    else goto v_10321;
v_10320:
    v_10371 = v_10372;
    if (v_10371 == nil) goto v_10325;
    else goto v_10326;
v_10325:
    v_10371 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10316;
v_10326:
    v_10371 = v_10372;
    v_10371 = qcdr(v_10371);
    if (v_10371 == nil) goto v_10329;
    else goto v_10330;
v_10329:
    v_10371 = v_10372;
    v_10371 = qcar(v_10371);
    goto v_10316;
v_10330:
    goto v_10342;
v_10338:
    v_10371 = elt(env, 1); // times
    goto v_10339;
v_10340:
    goto v_10341;
v_10342:
    goto v_10338;
v_10339:
    goto v_10340;
v_10341:
    return cons(v_10371, v_10372);
    goto v_10319;
v_10321:
    goto v_10351;
v_10347:
    v_10371 = v_10373;
    v_10374 = qcar(v_10371);
    goto v_10348;
v_10349:
    v_10371 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10350;
v_10351:
    goto v_10347;
v_10348:
    goto v_10349;
v_10350:
    if (v_10374 == v_10371) goto v_10345;
    else goto v_10346;
v_10345:
    v_10371 = v_10373;
    v_10371 = qcdr(v_10371);
    v_10373 = v_10371;
    goto v_10317;
v_10346:
    v_10371 = v_10373;
    v_10371 = qcdr(v_10371);
    stack[0] = v_10371;
    goto v_10366;
v_10362:
    v_10371 = v_10373;
    v_10371 = qcar(v_10371);
    goto v_10363;
v_10364:
    goto v_10365;
v_10366:
    goto v_10362;
v_10363:
    goto v_10364;
v_10365:
    v_10371 = cons(v_10371, v_10372);
    env = stack[-1];
    v_10372 = v_10371;
    v_10371 = stack[0];
    v_10373 = v_10371;
    goto v_10317;
v_10319:
    v_10371 = nil;
v_10316:
    return onevalue(v_10371);
}



// Code for command

static LispObject CC_command(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10627, v_10628, v_10629, v_10630;
    LispObject fn;
    argcheck(nargs, 0, "command");
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
// Binding errmsg!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = nil; // errmsg!*
// Binding loopdelimslist!*
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-3, 2, -1);
    qvalue(elt(env, 2)) = nil; // loopdelimslist!*
    v_10627 = qvalue(elt(env, 3)); // !*demo
    if (v_10627 == nil) goto v_10325;
    v_10627 = qvalue(elt(env, 4)); // ifl!*
    if (v_10627 == nil) goto v_10325;
    fn = elt(env, 27); // commdemo
    v_10627 = (*qfnn(fn))(fn, 0);
    goto v_10318;
v_10325:
    v_10627 = qvalue(elt(env, 5)); // !*slin
    if (v_10627 == nil) goto v_10335;
    else goto v_10336;
v_10335:
    v_10627 = lisp_true;
    goto v_10334;
v_10336:
    v_10627 = qvalue(elt(env, 6)); // !*reduce4
    goto v_10334;
    v_10627 = nil;
v_10334:
    if (v_10627 == nil) goto v_10332;
    goto v_10319;
v_10332:
    fn = elt(env, 28); // setcloc!*
    v_10627 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    v_10627 = qvalue(elt(env, 7)); // lreadfn!*
    if (v_10627 == nil) goto v_10346;
    goto v_10353;
v_10349:
    v_10628 = qvalue(elt(env, 7)); // lreadfn!*
    goto v_10350;
v_10351:
    v_10627 = nil;
    goto v_10352;
v_10353:
    goto v_10349;
v_10350:
    goto v_10351;
v_10352:
    fn = elt(env, 29); // lispapply
    v_10627 = (*qfn2(fn))(fn, v_10628, v_10627);
    env = stack[-3];
    goto v_10344;
v_10346:
    v_10627 = Lread(nil, 0);
    env = stack[-3];
    goto v_10344;
    v_10627 = nil;
v_10344:
    stack[0] = v_10627;
    goto v_10320;
v_10319:
    fn = elt(env, 30); // readch1
    v_10627 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    qvalue(elt(env, 8)) = v_10627; // crchar!*
    goto v_10368;
v_10364:
    v_10628 = qvalue(elt(env, 8)); // crchar!*
    goto v_10365;
v_10366:
    v_10627 = qvalue(elt(env, 9)); // !$eol!$
    goto v_10367;
v_10368:
    goto v_10364;
v_10365:
    goto v_10366;
v_10367:
    if (equal(v_10628, v_10627)) goto v_10362;
    else goto v_10363;
v_10362:
    goto v_10319;
v_10363:
    fn = elt(env, 31); // command1
    v_10627 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    stack[0] = v_10627;
v_10320:
    v_10627 = qvalue(elt(env, 6)); // !*reduce4
    if (v_10627 == nil) goto v_10375;
    goto v_10321;
v_10375:
    v_10627 = qvalue(elt(env, 10)); // !*struct
    if (v_10627 == nil) goto v_10378;
    v_10627 = stack[0];
    fn = elt(env, 32); // structchk
    v_10627 = (*qfn1(fn))(fn, v_10627);
    env = stack[-3];
    stack[0] = v_10627;
    goto v_10373;
v_10378:
v_10373:
    v_10627 = qvalue(elt(env, 11)); // !*pret
    if (v_10627 == nil) goto v_10385;
    v_10627 = stack[0];
    if (!consp(v_10627)) goto v_10391;
    else goto v_10392;
v_10391:
    v_10627 = lisp_true;
    goto v_10390;
v_10392:
    goto v_10401;
v_10397:
    v_10627 = stack[0];
    v_10628 = qcar(v_10627);
    goto v_10398;
v_10399:
    v_10627 = elt(env, 12); // (in out shut)
    goto v_10400;
v_10401:
    goto v_10397;
v_10398:
    goto v_10399;
v_10400:
    v_10627 = Lmemq(nil, v_10628, v_10627);
    v_10627 = (v_10627 == nil ? lisp_true : nil);
    goto v_10390;
    v_10627 = nil;
v_10390:
    if (v_10627 == nil) goto v_10385;
    v_10627 = stack[0];
    if (v_10627 == nil) goto v_10413;
    else goto v_10414;
v_10413:
    goto v_10420;
v_10416:
    v_10628 = qvalue(elt(env, 13)); // cursym!*
    goto v_10417;
v_10418:
    v_10627 = elt(env, 14); // end
    goto v_10419;
v_10420:
    goto v_10416;
v_10417:
    goto v_10418;
v_10419:
    v_10627 = (v_10628 == v_10627 ? lisp_true : nil);
    goto v_10412;
v_10414:
    v_10627 = nil;
    goto v_10412;
    v_10627 = nil;
v_10412:
    if (v_10627 == nil) goto v_10410;
    v_10627 = elt(env, 14); // end
    fn = elt(env, 33); // rprint
    v_10627 = (*qfn1(fn))(fn, v_10627);
    env = stack[-3];
    goto v_10408;
v_10410:
    v_10627 = stack[0];
    fn = elt(env, 33); // rprint
    v_10627 = (*qfn1(fn))(fn, v_10627);
    env = stack[-3];
    v_10627 = Lterpri(nil, 0);
    env = stack[-3];
    goto v_10408;
v_10408:
    goto v_10383;
v_10385:
v_10383:
    v_10627 = qvalue(elt(env, 5)); // !*slin
    if (v_10627 == nil) goto v_10437;
    goto v_10444;
v_10440:
    v_10628 = elt(env, 15); // symbolic
    goto v_10441;
v_10442:
    v_10627 = stack[0];
    goto v_10443;
v_10444:
    goto v_10440;
v_10441:
    goto v_10442;
v_10443:
    v_10627 = list2(v_10628, v_10627);
    goto v_10318;
v_10437:
    v_10627 = stack[0];
    fn = elt(env, 34); // form
    v_10627 = (*qfn1(fn))(fn, v_10627);
    env = stack[-3];
    v_10628 = v_10627;
    v_10627 = qvalue(elt(env, 16)); // key!*
    if (!symbolp(v_10627)) v_10627 = nil;
    else { v_10627 = qfastgets(v_10627);
           if (v_10627 != nil) { v_10627 = elt(v_10627, 48); // modefn
#ifdef RECORD_GET
             if (v_10627 == SPID_NOPROP)
                record_get(elt(fastget_names, 48), 0),
                v_10627 = nil;
             else record_get(elt(fastget_names, 48), 1),
                v_10627 = lisp_true; }
           else record_get(elt(fastget_names, 48), 0); }
#else
             if (v_10627 == SPID_NOPROP) v_10627 = nil; else v_10627 = lisp_true; }}
#endif
    if (v_10627 == nil) goto v_10452;
    v_10627 = qvalue(elt(env, 16)); // key!*
    goto v_10450;
v_10452:
    v_10627 = v_10628;
    if (!consp(v_10627)) goto v_10461;
    goto v_10471;
v_10467:
    v_10627 = v_10628;
    v_10629 = qcar(v_10627);
    goto v_10468;
v_10469:
    v_10627 = elt(env, 17); // quote
    goto v_10470;
v_10471:
    goto v_10467;
v_10468:
    goto v_10469;
v_10470:
    if (v_10629 == v_10627) goto v_10466;
    v_10627 = v_10628;
    v_10627 = qcar(v_10627);
    if (symbolp(v_10627)) goto v_10479;
    else goto v_10477;
v_10479:
    goto v_10492;
v_10488:
    v_10627 = v_10628;
    v_10629 = qcar(v_10627);
    goto v_10489;
v_10490:
    v_10627 = elt(env, 18); // nochange
    goto v_10491;
v_10492:
    goto v_10488;
v_10489:
    goto v_10490;
v_10491:
    v_10627 = Lflagp(nil, v_10629, v_10627);
    env = stack[-3];
    if (v_10627 == nil) goto v_10486;
    v_10627 = lisp_true;
    goto v_10484;
v_10486:
    goto v_10508;
v_10504:
    v_10627 = v_10628;
    v_10629 = qcar(v_10627);
    goto v_10505;
v_10506:
    v_10627 = elt(env, 19); // intfn
    goto v_10507;
v_10508:
    goto v_10504;
v_10505:
    goto v_10506;
v_10507:
    v_10627 = Lflagp(nil, v_10629, v_10627);
    env = stack[-3];
    if (v_10627 == nil) goto v_10502;
    v_10627 = lisp_true;
    goto v_10500;
v_10502:
    goto v_10519;
v_10515:
    v_10627 = v_10628;
    v_10629 = qcar(v_10627);
    goto v_10516;
v_10517:
    v_10627 = elt(env, 20); // list
    goto v_10518;
v_10519:
    goto v_10515;
v_10516:
    goto v_10517;
v_10518:
    v_10627 = (v_10629 == v_10627 ? lisp_true : nil);
    goto v_10500;
    v_10627 = nil;
v_10500:
    goto v_10484;
    v_10627 = nil;
v_10484:
    if (v_10627 == nil) goto v_10477;
    goto v_10478;
v_10477:
    v_10627 = lisp_true;
    goto v_10476;
v_10478:
    goto v_10535;
v_10531:
    v_10627 = v_10628;
    v_10629 = qcar(v_10627);
    goto v_10532;
v_10533:
    v_10627 = elt(env, 21); // (setq setel setf)
    goto v_10534;
v_10535:
    goto v_10531;
v_10532:
    goto v_10533;
v_10534:
    v_10627 = Lmemq(nil, v_10629, v_10627);
    if (v_10627 == nil) goto v_10529;
    else goto v_10530;
v_10529:
    v_10627 = nil;
    goto v_10528;
v_10530:
    goto v_10548;
v_10544:
    v_10627 = v_10628;
    v_10627 = qcdr(v_10627);
    v_10627 = qcdr(v_10627);
    v_10629 = qcar(v_10627);
    goto v_10545;
v_10546:
    v_10627 = elt(env, 17); // quote
    goto v_10547;
v_10548:
    goto v_10544;
v_10545:
    goto v_10546;
v_10547:
    v_10627 = Leqcar(nil, v_10629, v_10627);
    env = stack[-3];
    goto v_10528;
    v_10627 = nil;
v_10528:
    goto v_10476;
    v_10627 = nil;
v_10476:
    goto v_10464;
v_10466:
    v_10627 = nil;
    goto v_10464;
    v_10627 = nil;
v_10464:
    goto v_10459;
v_10461:
    v_10627 = nil;
    goto v_10459;
    v_10627 = nil;
v_10459:
    if (v_10627 == nil) goto v_10457;
    v_10627 = elt(env, 15); // symbolic
    goto v_10450;
v_10457:
    v_10627 = qvalue(elt(env, 22)); // !*mode
    goto v_10450;
v_10450:
    goto v_10569;
v_10565:
    stack[0] = v_10627;
    goto v_10566;
v_10567:
    goto v_10580;
v_10572:
    v_10630 = v_10628;
    goto v_10573;
v_10574:
    v_10629 = nil;
    goto v_10575;
v_10576:
    v_10628 = elt(env, 15); // symbolic
    goto v_10577;
v_10578:
    goto v_10579;
v_10580:
    goto v_10572;
v_10573:
    goto v_10574;
v_10575:
    goto v_10576;
v_10577:
    goto v_10578;
v_10579:
    fn = elt(env, 35); // convertmode1
    v_10627 = (*qfnn(fn))(fn, 4, v_10630, v_10629, v_10628, v_10627);
    env = stack[-3];
    goto v_10568;
v_10569:
    goto v_10565;
v_10566:
    goto v_10567;
v_10568:
    v_10627 = list2(stack[0], v_10627);
    goto v_10318;
v_10321:
    v_10627 = qvalue(elt(env, 23)); // !*debug
    if (v_10627 == nil) goto v_10588;
    v_10627 = elt(env, 24); // "Parse: "
    v_10627 = Lprinc(nil, v_10627);
    env = stack[-3];
    v_10627 = stack[0];
    fn = elt(env, 36); // prettyprint
    v_10627 = (*qfn1(fn))(fn, v_10627);
    env = stack[-3];
    goto v_10586;
v_10588:
v_10586:
    goto v_10602;
v_10598:
    v_10628 = qvalue(elt(env, 16)); // key!*
    goto v_10599;
v_10600:
    v_10627 = elt(env, 25); // !*semicol!*
    goto v_10601;
v_10602:
    goto v_10598;
v_10599:
    goto v_10600;
v_10601:
    if (v_10628 == v_10627) goto v_10596;
    else goto v_10597;
v_10596:
    goto v_10319;
v_10597:
    v_10627 = qvalue(elt(env, 6)); // !*reduce4
    if (v_10627 == nil) goto v_10607;
    else goto v_10608;
v_10607:
    v_10627 = stack[0];
    fn = elt(env, 34); // form
    v_10627 = (*qfn1(fn))(fn, v_10627);
    env = stack[-3];
    stack[0] = v_10627;
    goto v_10606;
v_10608:
    v_10627 = stack[0];
    fn = elt(env, 37); // n_form
    v_10627 = (*qfn1(fn))(fn, v_10627);
    env = stack[-3];
    stack[0] = v_10627;
    goto v_10606;
v_10606:
    v_10627 = qvalue(elt(env, 23)); // !*debug
    if (v_10627 == nil) goto v_10619;
    v_10627 = Lterpri(nil, 0);
    env = stack[-3];
    v_10627 = elt(env, 26); // "Form: "
    v_10627 = Lprinc(nil, v_10627);
    env = stack[-3];
    v_10627 = stack[0];
    fn = elt(env, 36); // prettyprint
    v_10627 = (*qfn1(fn))(fn, v_10627);
    goto v_10617;
v_10619:
v_10617:
    v_10627 = stack[0];
v_10318:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_10627);
}



// Code for sf_member

static LispObject CC_sf_member(LispObject env,
                         LispObject v_10311, LispObject v_10312)
{
    env = qenv(env);
    LispObject v_10368, v_10369;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10311,v_10312);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10312;
    stack[-1] = v_10311;
// end of prologue
v_10310:
    v_10368 = stack[0];
    if (!consp(v_10368)) goto v_10320;
    else goto v_10321;
v_10320:
    v_10368 = lisp_true;
    goto v_10319;
v_10321:
    v_10368 = stack[0];
    v_10368 = qcar(v_10368);
    v_10368 = (consp(v_10368) ? nil : lisp_true);
    goto v_10319;
    v_10368 = nil;
v_10319:
    if (v_10368 == nil) goto v_10316;
    else goto v_10317;
v_10316:
    goto v_10337;
v_10333:
    v_10369 = stack[-1];
    goto v_10334;
v_10335:
    v_10368 = stack[0];
    v_10368 = qcar(v_10368);
    v_10368 = qcar(v_10368);
    v_10368 = qcar(v_10368);
    goto v_10336;
v_10337:
    goto v_10333;
v_10334:
    goto v_10335;
v_10336:
    fn = elt(env, 1); // mvar_member
    v_10368 = (*qfn2(fn))(fn, v_10369, v_10368);
    env = stack[-2];
    if (v_10368 == nil) goto v_10331;
    else goto v_10330;
v_10331:
    goto v_10351;
v_10347:
    v_10369 = stack[-1];
    goto v_10348;
v_10349:
    v_10368 = stack[0];
    v_10368 = qcar(v_10368);
    v_10368 = qcdr(v_10368);
    goto v_10350;
v_10351:
    goto v_10347;
v_10348:
    goto v_10349;
v_10350:
    v_10368 = CC_sf_member(elt(env, 0), v_10369, v_10368);
    env = stack[-2];
    if (v_10368 == nil) goto v_10345;
    else goto v_10344;
v_10345:
    goto v_10361;
v_10357:
    v_10369 = stack[-1];
    goto v_10358;
v_10359:
    v_10368 = stack[0];
    v_10368 = qcdr(v_10368);
    goto v_10360;
v_10361:
    goto v_10357;
v_10358:
    goto v_10359;
v_10360:
    stack[-1] = v_10369;
    stack[0] = v_10368;
    goto v_10310;
v_10344:
v_10330:
    goto v_10315;
v_10317:
    v_10368 = nil;
    goto v_10315;
    v_10368 = nil;
v_10315:
    return onevalue(v_10368);
}



// Code for b!:extadd

static LispObject CC_bTextadd(LispObject env,
                         LispObject v_10311, LispObject v_10312)
{
    env = qenv(env);
    LispObject v_10438, v_10439, v_10440;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10311,v_10312);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10312;
    stack[-1] = v_10311;
// end of prologue
    stack[-2] = nil;
v_10319:
    v_10438 = stack[-1];
    if (v_10438 == nil) goto v_10323;
    else goto v_10324;
v_10323:
    v_10438 = stack[0];
    v_10439 = v_10438;
    goto v_10320;
v_10324:
    v_10438 = stack[0];
    if (v_10438 == nil) goto v_10327;
    else goto v_10328;
v_10327:
    v_10438 = stack[-1];
    v_10439 = v_10438;
    goto v_10320;
v_10328:
    goto v_10337;
v_10333:
    v_10438 = stack[-1];
    v_10438 = qcar(v_10438);
    v_10439 = qcar(v_10438);
    goto v_10334;
v_10335:
    v_10438 = stack[0];
    v_10438 = qcar(v_10438);
    v_10438 = qcar(v_10438);
    goto v_10336;
v_10337:
    goto v_10333;
v_10334:
    goto v_10335;
v_10336:
    if (equal(v_10439, v_10438)) goto v_10331;
    else goto v_10332;
v_10331:
    goto v_10349;
v_10345:
    v_10438 = stack[-1];
    v_10438 = qcar(v_10438);
    v_10439 = qcdr(v_10438);
    goto v_10346;
v_10347:
    v_10438 = stack[0];
    v_10438 = qcar(v_10438);
    v_10438 = qcdr(v_10438);
    goto v_10348;
v_10349:
    goto v_10345;
v_10346:
    goto v_10347;
v_10348:
    fn = elt(env, 1); // addf
    v_10438 = (*qfn2(fn))(fn, v_10439, v_10438);
    env = stack[-3];
    v_10439 = v_10438;
    if (v_10439 == nil) goto v_10359;
    goto v_10368;
v_10362:
    v_10439 = stack[-1];
    v_10439 = qcar(v_10439);
    v_10440 = qcar(v_10439);
    goto v_10363;
v_10364:
    v_10439 = v_10438;
    goto v_10365;
v_10366:
    v_10438 = stack[-2];
    goto v_10367;
v_10368:
    goto v_10362;
v_10363:
    goto v_10364;
v_10365:
    goto v_10366;
v_10367:
    v_10438 = acons(v_10440, v_10439, v_10438);
    env = stack[-3];
    stack[-2] = v_10438;
    goto v_10357;
v_10359:
v_10357:
    v_10438 = stack[-1];
    v_10438 = qcdr(v_10438);
    stack[-1] = v_10438;
    v_10438 = stack[0];
    v_10438 = qcdr(v_10438);
    stack[0] = v_10438;
    goto v_10319;
v_10332:
    goto v_10385;
v_10381:
    v_10438 = stack[-1];
    v_10438 = qcar(v_10438);
    v_10439 = qcar(v_10438);
    goto v_10382;
v_10383:
    v_10438 = stack[0];
    v_10438 = qcar(v_10438);
    v_10438 = qcar(v_10438);
    goto v_10384;
v_10385:
    goto v_10381;
v_10382:
    goto v_10383;
v_10384:
    fn = elt(env, 2); // b!:ordexp
    v_10438 = (*qfn2(fn))(fn, v_10439, v_10438);
    env = stack[-3];
    if (v_10438 == nil) goto v_10379;
    goto v_10397;
v_10393:
    v_10438 = stack[-1];
    v_10439 = qcar(v_10438);
    goto v_10394;
v_10395:
    v_10438 = stack[-2];
    goto v_10396;
v_10397:
    goto v_10393;
v_10394:
    goto v_10395;
v_10396:
    v_10438 = cons(v_10439, v_10438);
    env = stack[-3];
    stack[-2] = v_10438;
    v_10438 = stack[-1];
    v_10438 = qcdr(v_10438);
    stack[-1] = v_10438;
    goto v_10319;
v_10379:
    goto v_10410;
v_10406:
    v_10438 = stack[0];
    v_10439 = qcar(v_10438);
    goto v_10407;
v_10408:
    v_10438 = stack[-2];
    goto v_10409;
v_10410:
    goto v_10406;
v_10407:
    goto v_10408;
v_10409:
    v_10438 = cons(v_10439, v_10438);
    env = stack[-3];
    stack[-2] = v_10438;
    v_10438 = stack[0];
    v_10438 = qcdr(v_10438);
    stack[0] = v_10438;
    goto v_10319;
v_10320:
v_10418:
    v_10438 = stack[-2];
    if (v_10438 == nil) goto v_10421;
    else goto v_10422;
v_10421:
    goto v_10417;
v_10422:
    v_10438 = stack[-2];
    v_10438 = qcdr(v_10438);
    stack[-1] = v_10438;
    goto v_10432;
v_10428:
    v_10438 = stack[-2];
    goto v_10429;
v_10430:
    goto v_10431;
v_10432:
    goto v_10428;
v_10429:
    goto v_10430;
v_10431:
    v_10438 = Lrplacd(nil, v_10438, v_10439);
    env = stack[-3];
    v_10438 = stack[-2];
    v_10439 = v_10438;
    v_10438 = stack[-1];
    stack[-2] = v_10438;
    goto v_10418;
v_10417:
    v_10438 = v_10439;
    return onevalue(v_10438);
}



// Code for ra_refine1

static LispObject CC_ra_refine1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10414, v_10415, v_10416;
    LispObject fn;
    LispObject v_10314, v_10313, v_10312, v_10311;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ra_refine1");
    va_start(aa, nargs);
    v_10311 = va_arg(aa, LispObject);
    v_10312 = va_arg(aa, LispObject);
    v_10313 = va_arg(aa, LispObject);
    v_10314 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_10314,v_10313,v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_10311,v_10312,v_10313,v_10314);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-2] = v_10314;
    stack[-3] = v_10313;
    stack[-4] = v_10312;
    stack[-5] = v_10311;
// end of prologue
    v_10414 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_10414;
v_10322:
    goto v_10334;
v_10330:
    v_10415 = stack[-2];
    goto v_10331;
v_10332:
    v_10414 = stack[-1];
    goto v_10333;
v_10334:
    goto v_10330;
v_10331:
    goto v_10332;
v_10333:
    v_10414 = difference2(v_10415, v_10414);
    env = stack[-7];
    v_10414 = Lminusp(nil, v_10414);
    env = stack[-7];
    if (v_10414 == nil) goto v_10327;
    goto v_10321;
v_10327:
    goto v_10343;
v_10339:
    v_10415 = stack[-4];
    goto v_10340;
v_10341:
    v_10414 = stack[-3];
    goto v_10342;
v_10343:
    goto v_10339;
v_10340:
    goto v_10341;
v_10342:
    fn = elt(env, 2); // sfto_avgq
    v_10414 = (*qfn2(fn))(fn, v_10415, v_10414);
    env = stack[-7];
    stack[-6] = v_10414;
    goto v_10355;
v_10351:
    stack[0] = stack[-5];
    goto v_10352;
v_10353:
    goto v_10363;
v_10359:
    v_10415 = elt(env, 1); // x
    goto v_10360;
v_10361:
    v_10414 = stack[-6];
    goto v_10362;
v_10363:
    goto v_10359;
v_10360:
    goto v_10361;
v_10362:
    v_10414 = cons(v_10415, v_10414);
    env = stack[-7];
    v_10414 = ncons(v_10414);
    env = stack[-7];
    goto v_10354;
v_10355:
    goto v_10351;
v_10352:
    goto v_10353;
v_10354:
    fn = elt(env, 3); // sfto_qsub1
    v_10414 = (*qfn2(fn))(fn, stack[0], v_10414);
    env = stack[-7];
    v_10414 = qcar(v_10414);
    if (v_10414 == nil) goto v_10348;
    else goto v_10349;
v_10348:
    goto v_10372;
v_10368:
    v_10415 = stack[-4];
    goto v_10369;
v_10370:
    v_10414 = stack[-6];
    goto v_10371;
v_10372:
    goto v_10368;
v_10369:
    goto v_10370;
v_10371:
    fn = elt(env, 2); // sfto_avgq
    v_10414 = (*qfn2(fn))(fn, v_10415, v_10414);
    env = stack[-7];
    stack[-4] = v_10414;
    goto v_10347;
v_10349:
    goto v_10382;
v_10378:
    goto v_10390;
v_10384:
    v_10416 = stack[-5];
    goto v_10385;
v_10386:
    v_10415 = stack[-4];
    goto v_10387;
v_10388:
    v_10414 = stack[-6];
    goto v_10389;
v_10390:
    goto v_10384;
v_10385:
    goto v_10386;
v_10387:
    goto v_10388;
v_10389:
    fn = elt(env, 4); // ra_budancount
    v_10415 = (*qfnn(fn))(fn, 3, v_10416, v_10415, v_10414);
    env = stack[-7];
    goto v_10379;
v_10380:
    v_10414 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10381;
v_10382:
    goto v_10378;
v_10379:
    goto v_10380;
v_10381:
    v_10414 = Leqn(nil, v_10415, v_10414);
    env = stack[-7];
    if (v_10414 == nil) goto v_10376;
    v_10414 = stack[-6];
    stack[-3] = v_10414;
    goto v_10347;
v_10376:
    goto v_10401;
    goto v_10399;
v_10401:
v_10399:
    v_10414 = stack[-6];
    stack[-4] = v_10414;
    goto v_10347;
v_10347:
    v_10414 = stack[-1];
    v_10414 = add1(v_10414);
    env = stack[-7];
    stack[-1] = v_10414;
    goto v_10322;
v_10321:
    goto v_10411;
v_10407:
    v_10415 = stack[-4];
    goto v_10408;
v_10409:
    v_10414 = stack[-3];
    goto v_10410;
v_10411:
    goto v_10407;
v_10408:
    goto v_10409;
v_10410:
    return cons(v_10415, v_10414);
    return onevalue(v_10414);
}



// Code for lexer_word_starter

static LispObject CC_lexer_word_starter(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10404, v_10405;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10311);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10311;
// end of prologue
    v_10404 = stack[0];
    v_10404 = Lalpha_char_p(nil, v_10404);
    env = stack[-1];
    if (v_10404 == nil) goto v_10315;
    else goto v_10314;
v_10315:
    goto v_10330;
v_10326:
    v_10405 = stack[0];
    goto v_10327;
v_10328:
    v_10404 = elt(env, 1); // !_
    goto v_10329;
v_10330:
    goto v_10326;
v_10327:
    goto v_10328;
v_10329:
    if (v_10405 == v_10404) goto v_10324;
    else goto v_10325;
v_10324:
    goto v_10339;
v_10335:
    v_10405 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_10336;
v_10337:
    v_10404 = (LispObject)32768+TAG_FIXNUM; // 2048
    goto v_10338;
v_10339:
    goto v_10335;
v_10336:
    goto v_10337;
v_10338:
    fn = elt(env, 5); // land
    v_10404 = (*qfn2(fn))(fn, v_10405, v_10404);
    env = stack[-1];
    v_10404 = (LispObject)zerop(v_10404);
    v_10404 = v_10404 ? lisp_true : nil;
    env = stack[-1];
    v_10404 = (v_10404 == nil ? lisp_true : nil);
    goto v_10323;
v_10325:
    v_10404 = nil;
    goto v_10323;
    v_10404 = nil;
v_10323:
    if (v_10404 == nil) goto v_10321;
    v_10404 = lisp_true;
    goto v_10319;
v_10321:
    goto v_10361;
v_10357:
    v_10405 = stack[0];
    goto v_10358;
v_10359:
    v_10404 = elt(env, 3); // !'
    goto v_10360;
v_10361:
    goto v_10357;
v_10358:
    goto v_10359;
v_10360:
    if (v_10405 == v_10404) goto v_10355;
    else goto v_10356;
v_10355:
    goto v_10370;
v_10366:
    v_10405 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_10367;
v_10368:
    v_10404 = (LispObject)131072+TAG_FIXNUM; // 8192
    goto v_10369;
v_10370:
    goto v_10366;
v_10367:
    goto v_10368;
v_10369:
    fn = elt(env, 5); // land
    v_10404 = (*qfn2(fn))(fn, v_10405, v_10404);
    env = stack[-1];
    v_10404 = (LispObject)zerop(v_10404);
    v_10404 = v_10404 ? lisp_true : nil;
    env = stack[-1];
    v_10404 = (v_10404 == nil ? lisp_true : nil);
    goto v_10354;
v_10356:
    v_10404 = nil;
    goto v_10354;
    v_10404 = nil;
v_10354:
    if (v_10404 == nil) goto v_10352;
    v_10404 = lisp_true;
    goto v_10350;
v_10352:
    goto v_10388;
v_10384:
    v_10405 = stack[0];
    goto v_10385;
v_10386:
    v_10404 = elt(env, 4); // !\ (backslash)
    goto v_10387;
v_10388:
    goto v_10384;
v_10385:
    goto v_10386;
v_10387:
    if (v_10405 == v_10404) goto v_10382;
    else goto v_10383;
v_10382:
    goto v_10397;
v_10393:
    v_10405 = qvalue(elt(env, 2)); // lexer_style!*
    goto v_10394;
v_10395:
    v_10404 = (LispObject)65536+TAG_FIXNUM; // 4096
    goto v_10396;
v_10397:
    goto v_10393;
v_10394:
    goto v_10395;
v_10396:
    fn = elt(env, 5); // land
    v_10404 = (*qfn2(fn))(fn, v_10405, v_10404);
    env = stack[-1];
    v_10404 = (LispObject)zerop(v_10404);
    v_10404 = v_10404 ? lisp_true : nil;
    v_10404 = (v_10404 == nil ? lisp_true : nil);
    goto v_10381;
v_10383:
    v_10404 = nil;
    goto v_10381;
    v_10404 = nil;
v_10381:
    goto v_10350;
    v_10404 = nil;
v_10350:
    goto v_10319;
    v_10404 = nil;
v_10319:
v_10314:
    return onevalue(v_10404);
}



// Code for sfto_kexp

static LispObject CC_sfto_kexp(LispObject env,
                         LispObject v_10311, LispObject v_10312)
{
    env = qenv(env);
    LispObject v_10350, v_10351;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10311,v_10312);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10312;
    stack[-1] = v_10311;
// end of prologue
    goto v_10317;
    goto v_10315;
v_10317:
v_10315:
    goto v_10328;
v_10324:
    v_10351 = stack[0];
    goto v_10325;
v_10326:
    v_10350 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10327;
v_10328:
    goto v_10324;
v_10325:
    goto v_10326;
v_10327:
    v_10350 = Leqn(nil, v_10351, v_10350);
    env = stack[-2];
    if (v_10350 == nil) goto v_10322;
    v_10350 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10320;
v_10322:
    goto v_10340;
v_10336:
    goto v_10346;
v_10342:
    v_10351 = stack[-1];
    goto v_10343;
v_10344:
    v_10350 = stack[0];
    goto v_10345;
v_10346:
    goto v_10342;
v_10343:
    goto v_10344;
v_10345:
    fn = elt(env, 1); // to
    v_10351 = (*qfn2(fn))(fn, v_10351, v_10350);
    env = stack[-2];
    goto v_10337;
v_10338:
    v_10350 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10339;
v_10340:
    goto v_10336;
v_10337:
    goto v_10338;
v_10339:
    v_10350 = cons(v_10351, v_10350);
    return ncons(v_10350);
    v_10350 = nil;
v_10320:
    return onevalue(v_10350);
}



// Code for gcref_mkedges!-tgf

static LispObject CC_gcref_mkedgesKtgf(LispObject env,
                         LispObject v_10311, LispObject v_10312)
{
    env = qenv(env);
    LispObject v_10336;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10311,v_10312);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_10336 = v_10312;
    stack[-1] = v_10311;
// end of prologue
    stack[-2] = v_10336;
v_10317:
    v_10336 = stack[-2];
    if (v_10336 == nil) goto v_10321;
    else goto v_10322;
v_10321:
    v_10336 = nil;
    goto v_10316;
v_10322:
    v_10336 = stack[-2];
    v_10336 = qcar(v_10336);
    stack[0] = v_10336;
    v_10336 = stack[-1];
    v_10336 = Lprinc(nil, v_10336);
    env = stack[-3];
    v_10336 = elt(env, 1); // " "
    v_10336 = Lprinc(nil, v_10336);
    env = stack[-3];
    v_10336 = stack[0];
    fn = elt(env, 2); // prin2t
    v_10336 = (*qfn1(fn))(fn, v_10336);
    env = stack[-3];
    v_10336 = stack[-2];
    v_10336 = qcdr(v_10336);
    stack[-2] = v_10336;
    goto v_10317;
v_10316:
    return onevalue(v_10336);
}



// Code for polynomheadreduceby

static LispObject CC_polynomheadreduceby(LispObject env,
                         LispObject v_10311, LispObject v_10312)
{
    env = qenv(env);
    LispObject v_10378, v_10379;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10311,v_10312);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_10312;
    stack[-2] = v_10311;
// end of prologue
    stack[-3] = nil;
v_10320:
    v_10378 = stack[-2];
    v_10378 = qcar(v_10378);
    if (v_10378 == nil) goto v_10323;
    v_10378 = stack[-3];
    if (v_10378 == nil) goto v_10328;
    else goto v_10323;
v_10328:
    goto v_10324;
v_10323:
    goto v_10319;
v_10324:
    goto v_10340;
v_10336:
    v_10378 = stack[-2];
    v_10379 = qcar(v_10378);
    goto v_10337;
v_10338:
    v_10378 = stack[-1];
    v_10378 = qcar(v_10378);
    goto v_10339;
v_10340:
    goto v_10336;
v_10337:
    goto v_10338;
v_10339:
    fn = elt(env, 2); // monomisdivisibleby
    v_10378 = (*qfn2(fn))(fn, v_10379, v_10378);
    env = stack[-4];
    if (v_10378 == nil) goto v_10334;
    goto v_10350;
v_10346:
    v_10378 = stack[-2];
    v_10379 = qcar(v_10378);
    goto v_10347;
v_10348:
    v_10378 = stack[-1];
    v_10378 = qcar(v_10378);
    goto v_10349;
v_10350:
    goto v_10346;
v_10347:
    goto v_10348;
v_10349:
    fn = elt(env, 3); // monomdivide
    v_10378 = (*qfn2(fn))(fn, v_10379, v_10378);
    env = stack[-4];
    goto v_10360;
v_10356:
    stack[0] = stack[-2];
    goto v_10357;
v_10358:
    goto v_10367;
v_10363:
    v_10379 = stack[-1];
    goto v_10364;
v_10365:
    goto v_10366;
v_10367:
    goto v_10363;
v_10364:
    goto v_10365;
v_10366:
    fn = elt(env, 4); // polynommultiplybymonom
    v_10378 = (*qfn2(fn))(fn, v_10379, v_10378);
    env = stack[-4];
    goto v_10359;
v_10360:
    goto v_10356;
v_10357:
    goto v_10358;
v_10359:
    fn = elt(env, 5); // polynomadd
    v_10378 = (*qfn2(fn))(fn, stack[0], v_10378);
    env = stack[-4];
    goto v_10332;
v_10334:
    v_10378 = lisp_true;
    stack[-3] = v_10378;
    goto v_10332;
v_10332:
    goto v_10320;
v_10319:
    v_10378 = qvalue(elt(env, 1)); // fluidbibasisreductionsmade
    v_10378 = (LispObject)((intptr_t)(v_10378) + 0x10);
    qvalue(elt(env, 1)) = v_10378; // fluidbibasisreductionsmade
    v_10378 = nil;
    return onevalue(v_10378);
}



// Code for wusort

static LispObject CC_wusort(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10321, v_10322;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10321 = v_10311;
// end of prologue
    goto v_10318;
v_10314:
    v_10322 = v_10321;
    goto v_10315;
v_10316:
    v_10321 = elt(env, 1); // wulessp!*
    goto v_10317;
v_10318:
    goto v_10314;
v_10315:
    goto v_10316;
v_10317:
    {
        fn = elt(env, 2); // sort
        return (*qfn2(fn))(fn, v_10322, v_10321);
    }
}



// Code for expnd1

static LispObject CC_expnd1(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10437, v_10438;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10311);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_10311;
// end of prologue
    stack[-2] = nil;
v_10317:
    v_10437 = stack[-1];
    if (!consp(v_10437)) goto v_10326;
    else goto v_10327;
v_10326:
    v_10437 = lisp_true;
    goto v_10325;
v_10327:
    v_10437 = stack[-1];
    v_10437 = qcar(v_10437);
    v_10437 = (consp(v_10437) ? nil : lisp_true);
    goto v_10325;
    v_10437 = nil;
v_10325:
    if (v_10437 == nil) goto v_10323;
    goto v_10318;
v_10323:
    goto v_10340;
v_10336:
    v_10437 = stack[-1];
    v_10437 = qcar(v_10437);
    v_10437 = qcar(v_10437);
    v_10437 = qcar(v_10437);
    fn = elt(env, 1); // sfp
    v_10437 = (*qfn1(fn))(fn, v_10437);
    env = stack[-3];
    if (v_10437 == nil) goto v_10347;
    else goto v_10348;
v_10347:
    v_10437 = lisp_true;
    goto v_10346;
v_10348:
    goto v_10362;
v_10358:
    v_10437 = stack[-1];
    v_10437 = qcar(v_10437);
    v_10437 = qcar(v_10437);
    v_10438 = qcdr(v_10437);
    goto v_10359;
v_10360:
    v_10437 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10361;
v_10362:
    goto v_10358;
v_10359:
    goto v_10360;
v_10361:
    v_10437 = (LispObject)lessp2(v_10438, v_10437);
    v_10437 = v_10437 ? lisp_true : nil;
    env = stack[-3];
    goto v_10346;
    v_10437 = nil;
v_10346:
    if (v_10437 == nil) goto v_10344;
    goto v_10373;
v_10369:
    goto v_10380;
v_10376:
    v_10437 = stack[-1];
    v_10437 = qcar(v_10437);
    v_10438 = qcar(v_10437);
    goto v_10377;
v_10378:
    v_10437 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10379;
v_10380:
    goto v_10376;
v_10377:
    goto v_10378;
v_10379:
    v_10437 = cons(v_10438, v_10437);
    env = stack[-3];
    stack[0] = ncons(v_10437);
    env = stack[-3];
    goto v_10370;
v_10371:
    v_10437 = stack[-1];
    v_10437 = qcar(v_10437);
    v_10437 = qcdr(v_10437);
    v_10437 = CC_expnd1(elt(env, 0), v_10437);
    env = stack[-3];
    goto v_10372;
v_10373:
    goto v_10369;
v_10370:
    goto v_10371;
v_10372:
    fn = elt(env, 2); // multf
    v_10437 = (*qfn2(fn))(fn, stack[0], v_10437);
    env = stack[-3];
    v_10438 = v_10437;
    goto v_10342;
v_10344:
    goto v_10396;
v_10392:
    goto v_10402;
v_10398:
    v_10437 = stack[-1];
    v_10437 = qcar(v_10437);
    v_10437 = qcar(v_10437);
    v_10437 = qcar(v_10437);
    v_10438 = CC_expnd1(elt(env, 0), v_10437);
    env = stack[-3];
    goto v_10399;
v_10400:
    v_10437 = stack[-1];
    v_10437 = qcar(v_10437);
    v_10437 = qcar(v_10437);
    v_10437 = qcdr(v_10437);
    goto v_10401;
v_10402:
    goto v_10398;
v_10399:
    goto v_10400;
v_10401:
    fn = elt(env, 3); // exptf
    stack[0] = (*qfn2(fn))(fn, v_10438, v_10437);
    env = stack[-3];
    goto v_10393;
v_10394:
    v_10437 = stack[-1];
    v_10437 = qcar(v_10437);
    v_10437 = qcdr(v_10437);
    v_10437 = CC_expnd1(elt(env, 0), v_10437);
    env = stack[-3];
    goto v_10395;
v_10396:
    goto v_10392;
v_10393:
    goto v_10394;
v_10395:
    fn = elt(env, 2); // multf
    v_10437 = (*qfn2(fn))(fn, stack[0], v_10437);
    env = stack[-3];
    v_10438 = v_10437;
    goto v_10342;
    v_10438 = nil;
v_10342:
    goto v_10337;
v_10338:
    v_10437 = stack[-2];
    goto v_10339;
v_10340:
    goto v_10336;
v_10337:
    goto v_10338;
v_10339:
    v_10437 = cons(v_10438, v_10437);
    env = stack[-3];
    stack[-2] = v_10437;
    v_10437 = stack[-1];
    v_10437 = qcdr(v_10437);
    stack[-1] = v_10437;
    goto v_10317;
v_10318:
    v_10437 = stack[-1];
    v_10438 = v_10437;
v_10319:
    v_10437 = stack[-2];
    if (v_10437 == nil) goto v_10422;
    else goto v_10423;
v_10422:
    v_10437 = v_10438;
    goto v_10316;
v_10423:
    goto v_10431;
v_10427:
    v_10437 = stack[-2];
    v_10437 = qcar(v_10437);
    goto v_10428;
v_10429:
    goto v_10430;
v_10431:
    goto v_10427;
v_10428:
    goto v_10429;
v_10430:
    fn = elt(env, 4); // addf
    v_10437 = (*qfn2(fn))(fn, v_10437, v_10438);
    env = stack[-3];
    v_10438 = v_10437;
    v_10437 = stack[-2];
    v_10437 = qcdr(v_10437);
    stack[-2] = v_10437;
    goto v_10319;
v_10316:
    return onevalue(v_10437);
}



// Code for talp_simplatat

static LispObject CC_talp_simplatat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10438, v_10439, v_10440;
    LispObject fn;
    LispObject v_10313, v_10312, v_10311;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "talp_simplatat");
    va_start(aa, nargs);
    v_10311 = va_arg(aa, LispObject);
    v_10312 = va_arg(aa, LispObject);
    v_10313 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_10313,v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_10311,v_10312,v_10313);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_10313;
    stack[-1] = v_10312;
    stack[-2] = v_10311;
// end of prologue
    goto v_10323;
v_10319:
    v_10439 = stack[-1];
    goto v_10320;
v_10321:
    v_10438 = stack[0];
    goto v_10322;
v_10323:
    goto v_10319;
v_10320:
    goto v_10321;
v_10322:
    if (v_10439 == v_10438) goto v_10317;
    else goto v_10318;
v_10317:
    goto v_10330;
v_10326:
    v_10438 = stack[-2];
    goto v_10327;
v_10328:
    v_10439 = elt(env, 1); // equal
    goto v_10329;
v_10330:
    goto v_10326;
v_10327:
    goto v_10328;
v_10329:
    v_10438 = (v_10438 == v_10439 ? lisp_true : nil);
    goto v_10316;
v_10318:
    goto v_10340;
v_10336:
    stack[-3] = stack[-1];
    goto v_10337;
v_10338:
    fn = elt(env, 2); // talp_getl
    v_10438 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_10339;
v_10340:
    goto v_10336;
v_10337:
    goto v_10338;
v_10339:
    v_10438 = Latsoc(nil, stack[-3], v_10438);
    if (v_10438 == nil) goto v_10334;
    else goto v_10335;
v_10334:
    v_10438 = stack[0];
    if (!consp(v_10438)) goto v_10346;
    else goto v_10347;
v_10346:
    goto v_10356;
v_10350:
    v_10440 = stack[-2];
    goto v_10351;
v_10352:
    v_10439 = stack[-1];
    goto v_10353;
v_10354:
    v_10438 = stack[0];
    goto v_10355;
v_10356:
    goto v_10350;
v_10351:
    goto v_10352;
v_10353:
    goto v_10354;
v_10355:
    {
        fn = elt(env, 3); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_10440, v_10439, v_10438);
    }
v_10347:
    goto v_10367;
v_10363:
    v_10439 = stack[-1];
    goto v_10364;
v_10365:
    v_10438 = stack[0];
    goto v_10366;
v_10367:
    goto v_10363;
v_10364:
    goto v_10365;
v_10366:
    fn = elt(env, 4); // talp_telp
    v_10438 = (*qfn2(fn))(fn, v_10439, v_10438);
    env = stack[-4];
    if (v_10438 == nil) goto v_10361;
    goto v_10375;
v_10371:
    v_10438 = stack[-2];
    goto v_10372;
v_10373:
    v_10439 = elt(env, 1); // equal
    goto v_10374;
v_10375:
    goto v_10371;
v_10372:
    goto v_10373;
v_10374:
        return Lneq(nil, v_10438, v_10439);
v_10361:
    goto v_10387;
v_10381:
    v_10440 = stack[-2];
    goto v_10382;
v_10383:
    v_10439 = stack[-1];
    goto v_10384;
v_10385:
    v_10438 = stack[0];
    goto v_10386;
v_10387:
    goto v_10381;
v_10382:
    goto v_10383;
v_10384:
    goto v_10385;
v_10386:
    {
        fn = elt(env, 3); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_10440, v_10439, v_10438);
    }
    v_10438 = nil;
    goto v_10316;
v_10335:
    v_10438 = stack[0];
    if (!consp(v_10438)) goto v_10391;
    else goto v_10392;
v_10391:
    goto v_10402;
v_10398:
    stack[-3] = stack[0];
    goto v_10399;
v_10400:
    fn = elt(env, 2); // talp_getl
    v_10438 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    goto v_10401;
v_10402:
    goto v_10398;
v_10399:
    goto v_10400;
v_10401:
    v_10438 = Latsoc(nil, stack[-3], v_10438);
    if (v_10438 == nil) goto v_10396;
    else goto v_10397;
v_10396:
    goto v_10413;
v_10407:
    goto v_10408;
v_10409:
    goto v_10410;
v_10411:
    v_10438 = stack[0];
    fn = elt(env, 5); // talp_simplt
    v_10438 = (*qfn1(fn))(fn, v_10438);
    env = stack[-4];
    goto v_10412;
v_10413:
    goto v_10407;
v_10408:
    goto v_10409;
v_10410:
    goto v_10411;
v_10412:
    {
        LispObject v_10445 = stack[-2];
        LispObject v_10446 = stack[-1];
        fn = elt(env, 3); // talp_mk2
        return (*qfnn(fn))(fn, 3, v_10445, v_10446, v_10438);
    }
v_10397:
    goto v_10425;
v_10421:
    v_10438 = stack[-2];
    goto v_10422;
v_10423:
    v_10439 = elt(env, 1); // equal
    goto v_10424;
v_10425:
    goto v_10421;
v_10422:
    goto v_10423;
v_10424:
        return Lneq(nil, v_10438, v_10439);
    v_10438 = nil;
    goto v_10316;
v_10392:
    goto v_10435;
v_10431:
    v_10438 = stack[-2];
    goto v_10432;
v_10433:
    v_10439 = elt(env, 1); // equal
    goto v_10434;
v_10435:
    goto v_10431;
v_10432:
    goto v_10433;
v_10434:
        return Lneq(nil, v_10438, v_10439);
    v_10438 = nil;
v_10316:
    return onevalue(v_10438);
}



// Code for qqe_number!-of!-adds!-in!-qterm

static LispObject CC_qqe_numberKofKaddsKinKqterm(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10341, v_10342;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10311);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10311;
// end of prologue
v_10315:
    v_10341 = stack[0];
    if (!consp(v_10341)) goto v_10318;
    else goto v_10319;
v_10318:
    v_10341 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10314;
v_10319:
    goto v_10328;
v_10324:
    v_10341 = stack[0];
    fn = elt(env, 2); // qqe_op
    v_10342 = (*qfn1(fn))(fn, v_10341);
    env = stack[-1];
    goto v_10325;
v_10326:
    v_10341 = elt(env, 1); // (ladd radd)
    goto v_10327;
v_10328:
    goto v_10324;
v_10325:
    goto v_10326;
v_10327:
    v_10341 = Lmemq(nil, v_10342, v_10341);
    if (v_10341 == nil) goto v_10323;
    v_10341 = stack[0];
    fn = elt(env, 3); // qqe_arg2r
    v_10341 = (*qfn1(fn))(fn, v_10341);
    env = stack[-1];
    v_10341 = CC_qqe_numberKofKaddsKinKqterm(elt(env, 0), v_10341);
    return add1(v_10341);
v_10323:
    v_10341 = stack[0];
    fn = elt(env, 4); // qqe_arg2l
    v_10341 = (*qfn1(fn))(fn, v_10341);
    env = stack[-1];
    stack[0] = v_10341;
    goto v_10315;
    v_10341 = nil;
v_10314:
    return onevalue(v_10341);
}



// Code for mml2om

static LispObject CC_mml2om(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10326;
    LispObject fn;
    argcheck(nargs, 0, "mml2om");
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
    fn = elt(env, 2); // mml2ir
    v_10326 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_10326;
    v_10326 = lisp_true;
    fn = elt(env, 3); // terpri!*
    v_10326 = (*qfn1(fn))(fn, v_10326);
    env = stack[-1];
    v_10326 = elt(env, 1); // "Intermediate representation: "
    v_10326 = Lprinc(nil, v_10326);
    env = stack[-1];
    v_10326 = lisp_true;
    fn = elt(env, 3); // terpri!*
    v_10326 = (*qfn1(fn))(fn, v_10326);
    env = stack[-1];
    v_10326 = stack[0];
    v_10326 = Lprint(nil, v_10326);
    env = stack[-1];
    v_10326 = stack[0];
    fn = elt(env, 4); // ir2om
    v_10326 = (*qfn1(fn))(fn, v_10326);
    v_10326 = nil;
    return onevalue(v_10326);
}



// Code for add2resultbuf

static LispObject CC_add2resultbuf(LispObject env,
                         LispObject v_10311, LispObject v_10312)
{
    env = qenv(env);
    LispObject v_10452, v_10453, v_10454;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10311,v_10312);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10312;
    stack[-1] = v_10311;
// end of prologue
    v_10452 = qvalue(elt(env, 1)); // !*libreduce_active
    if (v_10452 == nil) goto v_10319;
    fn = elt(env, 13); // lr_result
    v_10452 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_10330;
v_10326:
    v_10453 = qvalue(elt(env, 2)); // semic!*
    goto v_10327;
v_10328:
    v_10452 = elt(env, 3); // !$
    goto v_10329;
v_10330:
    goto v_10326;
v_10327:
    goto v_10328;
v_10329:
    if (v_10453 == v_10452) goto v_10325;
    goto v_10338;
v_10334:
    v_10453 = stack[-1];
    goto v_10335;
v_10336:
    v_10452 = stack[0];
    goto v_10337;
v_10338:
    goto v_10334;
v_10335:
    goto v_10336;
v_10337:
    fn = elt(env, 14); // lr_printer
    v_10452 = (*qfn2(fn))(fn, v_10453, v_10452);
    env = stack[-2];
    goto v_10323;
v_10325:
v_10323:
    fn = elt(env, 15); // lr_statcounter
    v_10452 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_10452 = qvalue(elt(env, 4)); // statcounter
    v_10452 = Lprinc(nil, v_10452);
    env = stack[-2];
    fn = elt(env, 16); // lr_mode
    v_10452 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_10354;
v_10350:
    v_10453 = qvalue(elt(env, 5)); // !*mode
    goto v_10351;
v_10352:
    v_10452 = elt(env, 6); // symbolic
    goto v_10353;
v_10354:
    goto v_10350;
v_10351:
    goto v_10352;
v_10353:
    if (v_10453 == v_10452) goto v_10348;
    else goto v_10349;
v_10348:
    v_10452 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10347;
v_10349:
    v_10452 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10347;
    v_10452 = nil;
v_10347:
    v_10452 = Lprinc(nil, v_10452);
    env = stack[-2];
    fn = elt(env, 17); // lr_posttext
    v_10452 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_10452 = Lterpri(nil, 0);
    env = stack[-2];
    goto v_10317;
v_10319:
v_10317:
    goto v_10375;
v_10371:
    v_10453 = stack[0];
    goto v_10372;
v_10373:
    v_10452 = elt(env, 6); // symbolic
    goto v_10374;
v_10375:
    goto v_10371;
v_10372:
    goto v_10373;
v_10374:
    if (v_10453 == v_10452) goto v_10369;
    else goto v_10370;
v_10369:
    v_10452 = lisp_true;
    goto v_10368;
v_10370:
    v_10452 = stack[-1];
    if (v_10452 == nil) goto v_10387;
    else goto v_10388;
v_10387:
    v_10452 = qvalue(elt(env, 7)); // !*reduce4
    if (v_10452 == nil) goto v_10392;
    else goto v_10393;
v_10392:
    v_10452 = lisp_true;
    goto v_10391;
v_10393:
    goto v_10402;
v_10398:
    v_10453 = stack[0];
    goto v_10399;
v_10400:
    v_10452 = elt(env, 8); // empty_list
    goto v_10401;
v_10402:
    goto v_10398;
v_10399:
    goto v_10400;
v_10401:
    v_10452 = (v_10453 == v_10452 ? lisp_true : nil);
    v_10452 = (v_10452 == nil ? lisp_true : nil);
    goto v_10391;
    v_10452 = nil;
v_10391:
    goto v_10386;
v_10388:
    v_10452 = nil;
    goto v_10386;
    v_10452 = nil;
v_10386:
    if (v_10452 == nil) goto v_10384;
    v_10452 = lisp_true;
    goto v_10382;
v_10384:
    v_10452 = qvalue(elt(env, 9)); // !*nosave!*
    goto v_10382;
    v_10452 = nil;
v_10382:
    goto v_10368;
    v_10452 = nil;
v_10368:
    if (v_10452 == nil) goto v_10366;
    v_10452 = nil;
    goto v_10315;
v_10366:
    v_10452 = qvalue(elt(env, 7)); // !*reduce4
    if (v_10452 == nil) goto v_10418;
    goto v_10427;
v_10421:
    v_10454 = elt(env, 10); // ws
    goto v_10422;
v_10423:
    v_10453 = stack[-1];
    goto v_10424;
v_10425:
    v_10452 = stack[0];
    goto v_10426;
v_10427:
    goto v_10421;
v_10422:
    goto v_10423;
v_10424:
    goto v_10425;
v_10426:
    fn = elt(env, 18); // putobject
    v_10452 = (*qfnn(fn))(fn, 3, v_10454, v_10453, v_10452);
    env = stack[-2];
    goto v_10416;
v_10418:
    v_10452 = nil;
    v_10452 = ncons(v_10452);
    env = stack[-2];
    qvalue(elt(env, 11)) = v_10452; // alglist!*
    v_10452 = stack[-1];
    qvalue(elt(env, 10)) = v_10452; // ws
    goto v_10416;
v_10416:
    fn = elt(env, 19); // terminalp
    v_10452 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    if (v_10452 == nil) goto v_10439;
    goto v_10448;
v_10442:
    v_10454 = qvalue(elt(env, 4)); // statcounter
    goto v_10443;
v_10444:
    v_10453 = stack[-1];
    goto v_10445;
v_10446:
    v_10452 = qvalue(elt(env, 12)); // resultbuflis!*
    goto v_10447;
v_10448:
    goto v_10442;
v_10443:
    goto v_10444;
v_10445:
    goto v_10446;
v_10447:
    v_10452 = acons(v_10454, v_10453, v_10452);
    env = stack[-2];
    qvalue(elt(env, 12)) = v_10452; // resultbuflis!*
    goto v_10437;
v_10439:
v_10437:
    v_10452 = nil;
v_10315:
    return onevalue(v_10452);
}



// Code for general!-reduce!-degree!-mod!-p

static LispObject CC_generalKreduceKdegreeKmodKp(LispObject env,
                         LispObject v_10311, LispObject v_10312)
{
    env = qenv(env);
    LispObject v_10409, v_10410, v_10411;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10311,v_10312);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_10312;
    stack[-1] = v_10311;
// end of prologue
    goto v_10323;
v_10319:
    v_10409 = stack[-1];
    v_10409 = qcar(v_10409);
    v_10409 = qcdr(v_10409);
    fn = elt(env, 1); // general!-modular!-minus
    v_10410 = (*qfn1(fn))(fn, v_10409);
    env = stack[-3];
    goto v_10320;
v_10321:
    v_10409 = stack[0];
    v_10409 = qcar(v_10409);
    v_10409 = qcdr(v_10409);
    goto v_10322;
v_10323:
    goto v_10319;
v_10320:
    goto v_10321;
v_10322:
    fn = elt(env, 2); // general!-modular!-quotient
    v_10409 = (*qfn2(fn))(fn, v_10410, v_10409);
    env = stack[-3];
    stack[-2] = v_10409;
    goto v_10335;
v_10331:
    v_10409 = stack[-1];
    v_10409 = qcar(v_10409);
    v_10409 = qcar(v_10409);
    v_10410 = qcdr(v_10409);
    goto v_10332;
v_10333:
    v_10409 = stack[0];
    v_10409 = qcar(v_10409);
    v_10409 = qcar(v_10409);
    v_10409 = qcdr(v_10409);
    goto v_10334;
v_10335:
    goto v_10331;
v_10332:
    goto v_10333;
v_10334:
    v_10409 = (LispObject)(intptr_t)((intptr_t)v_10410 - (intptr_t)v_10409 + TAG_FIXNUM);
    v_10411 = v_10409;
    goto v_10353;
v_10349:
    v_10410 = v_10411;
    goto v_10350;
v_10351:
    v_10409 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10352;
v_10353:
    goto v_10349;
v_10350:
    goto v_10351;
v_10352:
    if (v_10410 == v_10409) goto v_10347;
    else goto v_10348;
v_10347:
    goto v_10361;
v_10357:
    v_10409 = stack[-1];
    stack[-1] = qcdr(v_10409);
    goto v_10358;
v_10359:
    goto v_10369;
v_10365:
    v_10409 = stack[0];
    v_10410 = qcdr(v_10409);
    goto v_10366;
v_10367:
    v_10409 = stack[-2];
    goto v_10368;
v_10369:
    goto v_10365;
v_10366:
    goto v_10367;
v_10368:
    fn = elt(env, 3); // general!-multiply!-by!-constant!-mod!-p
    v_10409 = (*qfn2(fn))(fn, v_10410, v_10409);
    env = stack[-3];
    goto v_10360;
v_10361:
    goto v_10357;
v_10358:
    goto v_10359;
v_10360:
    {
        LispObject v_10415 = stack[-1];
        fn = elt(env, 4); // general!-plus!-mod!-p
        return (*qfn2(fn))(fn, v_10415, v_10409);
    }
v_10348:
    goto v_10380;
v_10376:
    v_10409 = stack[-1];
    stack[-1] = qcdr(v_10409);
    goto v_10377;
v_10378:
    goto v_10388;
v_10384:
    goto v_10394;
v_10390:
    goto v_10400;
v_10396:
    v_10409 = stack[0];
    v_10409 = qcar(v_10409);
    v_10409 = qcar(v_10409);
    v_10409 = qcar(v_10409);
    goto v_10397;
v_10398:
    v_10410 = v_10411;
    goto v_10399;
v_10400:
    goto v_10396;
v_10397:
    goto v_10398;
v_10399:
    fn = elt(env, 5); // mksp
    v_10410 = (*qfn2(fn))(fn, v_10409, v_10410);
    env = stack[-3];
    goto v_10391;
v_10392:
    v_10409 = stack[-2];
    goto v_10393;
v_10394:
    goto v_10390;
v_10391:
    goto v_10392;
v_10393:
    v_10410 = cons(v_10410, v_10409);
    env = stack[-3];
    goto v_10385;
v_10386:
    v_10409 = stack[0];
    v_10409 = qcdr(v_10409);
    goto v_10387;
v_10388:
    goto v_10384;
v_10385:
    goto v_10386;
v_10387:
    fn = elt(env, 6); // general!-times!-term!-mod!-p
    v_10409 = (*qfn2(fn))(fn, v_10410, v_10409);
    env = stack[-3];
    goto v_10379;
v_10380:
    goto v_10376;
v_10377:
    goto v_10378;
v_10379:
    {
        LispObject v_10416 = stack[-1];
        fn = elt(env, 4); // general!-plus!-mod!-p
        return (*qfn2(fn))(fn, v_10416, v_10409);
    }
    v_10409 = nil;
    return onevalue(v_10409);
}



// Code for simpiden

static LispObject CC_simpiden(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10818, v_10819, v_10820;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10311);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[0] = v_10311;
// end of prologue
    stack[-5] = nil;
    stack[-4] = nil;
    v_10818 = stack[0];
    v_10818 = qcar(v_10818);
    stack[-7] = v_10818;
    v_10818 = stack[0];
    v_10818 = qcdr(v_10818);
    stack[0] = v_10818;
    goto v_10335;
v_10331:
    v_10819 = stack[-7];
    goto v_10332;
v_10333:
    v_10818 = stack[0];
    goto v_10334;
v_10335:
    goto v_10331;
v_10332:
    goto v_10333;
v_10334:
    fn = elt(env, 12); // valuechk
    v_10818 = (*qfn2(fn))(fn, v_10819, v_10818);
    env = stack[-8];
    stack[-6] = v_10818;
    if (v_10818 == nil) goto v_10329;
    v_10818 = stack[-6];
    goto v_10320;
v_10329:
    v_10818 = stack[0];
    if (v_10818 == nil) goto v_10346;
    goto v_10353;
v_10349:
    v_10818 = stack[0];
    v_10819 = qcar(v_10818);
    goto v_10350;
v_10351:
    v_10818 = elt(env, 1); // list
    goto v_10352;
v_10353:
    goto v_10349;
v_10350:
    goto v_10351;
v_10352:
    v_10818 = Leqcar(nil, v_10819, v_10818);
    env = stack[-8];
    goto v_10344;
v_10346:
    v_10818 = nil;
    goto v_10344;
    v_10818 = nil;
v_10344:
    if (v_10818 == nil) goto v_10342;
    goto v_10365;
v_10361:
    goto v_10371;
v_10367:
    stack[-1] = stack[-7];
    goto v_10368;
v_10369:
    v_10818 = stack[0];
    v_10818 = qcar(v_10818);
    fn = elt(env, 13); // aeval
    v_10818 = (*qfn1(fn))(fn, v_10818);
    env = stack[-8];
    goto v_10370;
v_10371:
    goto v_10367;
v_10368:
    goto v_10369;
v_10370:
    v_10819 = list2(stack[-1], v_10818);
    env = stack[-8];
    goto v_10362;
v_10363:
    v_10818 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10364;
v_10365:
    goto v_10361;
v_10362:
    goto v_10363;
v_10364:
    {
        fn = elt(env, 14); // mksq
        return (*qfn2(fn))(fn, v_10819, v_10818);
    }
v_10342:
    goto v_10384;
v_10378:
    v_10819 = stack[0];
    goto v_10379;
v_10380:
    goto v_10391;
v_10387:
    v_10820 = stack[-7];
    goto v_10388;
v_10389:
    v_10818 = elt(env, 2); // nosimp
    goto v_10390;
v_10391:
    goto v_10387;
v_10388:
    goto v_10389;
v_10390:
    v_10820 = get(v_10820, v_10818);
    env = stack[-8];
    goto v_10381;
v_10382:
    v_10818 = nil;
    goto v_10383;
v_10384:
    goto v_10378;
v_10379:
    goto v_10380;
v_10381:
    goto v_10382;
v_10383:
    fn = elt(env, 15); // fnreval
    v_10818 = (*qfnn(fn))(fn, 3, v_10819, v_10820, v_10818);
    env = stack[-8];
    stack[-6] = v_10818;
    v_10818 = stack[-6];
    stack[-3] = v_10818;
    v_10818 = stack[-3];
    if (v_10818 == nil) goto v_10404;
    else goto v_10405;
v_10404:
    v_10818 = nil;
    goto v_10399;
v_10405:
    v_10818 = stack[-3];
    v_10818 = qcar(v_10818);
    v_10820 = v_10818;
    goto v_10421;
v_10417:
    v_10819 = v_10820;
    goto v_10418;
v_10419:
    v_10818 = elt(env, 3); // !*sq
    goto v_10420;
v_10421:
    goto v_10417;
v_10418:
    goto v_10419;
v_10420:
    if (!consp(v_10819)) goto v_10415;
    v_10819 = qcar(v_10819);
    if (v_10819 == v_10818) goto v_10414;
    else goto v_10415;
v_10414:
    v_10818 = v_10820;
    v_10818 = qcdr(v_10818);
    v_10818 = qcar(v_10818);
    fn = elt(env, 16); // prepsqxx
    v_10818 = (*qfn1(fn))(fn, v_10818);
    env = stack[-8];
    goto v_10413;
v_10415:
    v_10818 = v_10820;
    if (is_number(v_10818)) goto v_10428;
    else goto v_10429;
v_10428:
    v_10818 = v_10820;
    goto v_10413;
v_10429:
    v_10818 = v_10820;
    goto v_10413;
    v_10818 = nil;
v_10413:
    v_10818 = ncons(v_10818);
    env = stack[-8];
    stack[-1] = v_10818;
    stack[-2] = v_10818;
v_10400:
    v_10818 = stack[-3];
    v_10818 = qcdr(v_10818);
    stack[-3] = v_10818;
    v_10818 = stack[-3];
    if (v_10818 == nil) goto v_10440;
    else goto v_10441;
v_10440:
    v_10818 = stack[-2];
    goto v_10399;
v_10441:
    goto v_10449;
v_10445:
    stack[0] = stack[-1];
    goto v_10446;
v_10447:
    v_10818 = stack[-3];
    v_10818 = qcar(v_10818);
    v_10820 = v_10818;
    goto v_10464;
v_10460:
    v_10819 = v_10820;
    goto v_10461;
v_10462:
    v_10818 = elt(env, 3); // !*sq
    goto v_10463;
v_10464:
    goto v_10460;
v_10461:
    goto v_10462;
v_10463:
    if (!consp(v_10819)) goto v_10458;
    v_10819 = qcar(v_10819);
    if (v_10819 == v_10818) goto v_10457;
    else goto v_10458;
v_10457:
    v_10818 = v_10820;
    v_10818 = qcdr(v_10818);
    v_10818 = qcar(v_10818);
    fn = elt(env, 16); // prepsqxx
    v_10818 = (*qfn1(fn))(fn, v_10818);
    env = stack[-8];
    goto v_10456;
v_10458:
    v_10818 = v_10820;
    if (is_number(v_10818)) goto v_10471;
    else goto v_10472;
v_10471:
    v_10818 = v_10820;
    goto v_10456;
v_10472:
    v_10818 = v_10820;
    goto v_10456;
    v_10818 = nil;
v_10456:
    v_10818 = ncons(v_10818);
    env = stack[-8];
    goto v_10448;
v_10449:
    goto v_10445;
v_10446:
    goto v_10447;
v_10448:
    v_10818 = Lrplacd(nil, stack[0], v_10818);
    env = stack[-8];
    v_10818 = stack[-1];
    v_10818 = qcdr(v_10818);
    stack[-1] = v_10818;
    goto v_10400;
v_10399:
    stack[0] = v_10818;
    v_10818 = stack[0];
    if (v_10818 == nil) goto v_10484;
    goto v_10496;
v_10492:
    v_10818 = stack[0];
    v_10819 = qcar(v_10818);
    goto v_10493;
v_10494:
    v_10818 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10495;
v_10496:
    goto v_10492;
v_10493:
    goto v_10494;
v_10495:
    if (v_10819 == v_10818) goto v_10490;
    else goto v_10491;
v_10490:
    goto v_10509;
v_10505:
    v_10819 = stack[-7];
    goto v_10506;
v_10507:
    v_10818 = elt(env, 4); // odd
    goto v_10508;
v_10509:
    goto v_10505;
v_10506:
    goto v_10507;
v_10508:
    v_10818 = Lflagp(nil, v_10819, v_10818);
    env = stack[-8];
    if (v_10818 == nil) goto v_10503;
    goto v_10517;
v_10513:
    v_10819 = stack[-7];
    goto v_10514;
v_10515:
    v_10818 = elt(env, 5); // nonzero
    goto v_10516;
v_10517:
    goto v_10513;
v_10514:
    goto v_10515;
v_10516:
    v_10818 = Lflagp(nil, v_10819, v_10818);
    env = stack[-8];
    v_10818 = (v_10818 == nil ? lisp_true : nil);
    goto v_10501;
v_10503:
    v_10818 = nil;
    goto v_10501;
    v_10818 = nil;
v_10501:
    goto v_10489;
v_10491:
    v_10818 = nil;
    goto v_10489;
    v_10818 = nil;
v_10489:
    if (v_10818 == nil) goto v_10484;
    goto v_10532;
v_10528:
    v_10819 = nil;
    goto v_10529;
v_10530:
    v_10818 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10531;
v_10532:
    goto v_10528;
v_10529:
    goto v_10530;
v_10531:
    return cons(v_10819, v_10818);
v_10484:
    goto v_10540;
v_10536:
    v_10819 = stack[-7];
    goto v_10537;
v_10538:
    v_10818 = stack[0];
    goto v_10539;
v_10540:
    goto v_10536;
v_10537:
    goto v_10538;
v_10539:
    v_10818 = cons(v_10819, v_10818);
    env = stack[-8];
    stack[0] = v_10818;
    v_10818 = stack[-7];
    if (!symbolp(v_10818)) v_10818 = nil;
    else { v_10818 = qfastgets(v_10818);
           if (v_10818 != nil) { v_10818 = elt(v_10818, 0); // noncom
#ifdef RECORD_GET
             if (v_10818 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_10818 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_10818 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_10818 == SPID_NOPROP) v_10818 = nil; else v_10818 = lisp_true; }}
#endif
    if (v_10818 == nil) goto v_10546;
    v_10818 = lisp_true;
    qvalue(elt(env, 6)) = v_10818; // ncmp!*
    goto v_10544;
v_10546:
v_10544:
    v_10818 = qvalue(elt(env, 7)); // subfg!*
    if (v_10818 == nil) goto v_10552;
    else goto v_10553;
v_10552:
    goto v_10321;
v_10553:
    goto v_10566;
v_10562:
    v_10819 = stack[-7];
    goto v_10563;
v_10564:
    v_10818 = elt(env, 8); // linear
    goto v_10565;
v_10566:
    goto v_10562;
v_10563:
    goto v_10564;
v_10565:
    v_10818 = Lflagp(nil, v_10819, v_10818);
    env = stack[-8];
    if (v_10818 == nil) goto v_10560;
    goto v_10574;
v_10570:
    v_10818 = stack[0];
    fn = elt(env, 17); // formlnr
    v_10819 = (*qfn1(fn))(fn, v_10818);
    env = stack[-8];
    stack[-4] = v_10819;
    goto v_10571;
v_10572:
    v_10818 = stack[0];
    goto v_10573;
v_10574:
    goto v_10570;
v_10571:
    goto v_10572;
v_10573:
    v_10818 = Lneq(nil, v_10819, v_10818);
    env = stack[-8];
    goto v_10558;
v_10560:
    v_10818 = nil;
    goto v_10558;
    v_10818 = nil;
v_10558:
    if (v_10818 == nil) goto v_10556;
    v_10818 = stack[-4];
    {
        fn = elt(env, 18); // simp
        return (*qfn1(fn))(fn, v_10818);
    }
v_10556:
    v_10818 = stack[0];
    fn = elt(env, 19); // opmtch
    v_10818 = (*qfn1(fn))(fn, v_10818);
    env = stack[-8];
    stack[-4] = v_10818;
    if (v_10818 == nil) goto v_10584;
    v_10818 = stack[-4];
    {
        fn = elt(env, 18); // simp
        return (*qfn1(fn))(fn, v_10818);
    }
v_10584:
    goto v_10596;
v_10592:
    v_10818 = stack[0];
    v_10819 = qcar(v_10818);
    goto v_10593;
v_10594:
    v_10818 = elt(env, 9); // opvalfn
    goto v_10595;
v_10596:
    goto v_10592;
v_10593:
    goto v_10594;
v_10595:
    v_10818 = get(v_10819, v_10818);
    env = stack[-8];
    stack[-4] = v_10818;
    if (v_10818 == nil) goto v_10590;
    goto v_10605;
v_10601:
    v_10819 = stack[-4];
    goto v_10602;
v_10603:
    v_10818 = stack[0];
    goto v_10604;
v_10605:
    goto v_10601;
v_10602:
    goto v_10603;
v_10604:
        return Lapply1(nil, v_10819, v_10818);
v_10590:
v_10321:
    v_10818 = stack[-7];
    if (!symbolp(v_10818)) v_10818 = nil;
    else { v_10818 = qfastgets(v_10818);
           if (v_10818 != nil) { v_10818 = elt(v_10818, 43); // symmetric
#ifdef RECORD_GET
             if (v_10818 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v_10818 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v_10818 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v_10818 == SPID_NOPROP) v_10818 = nil; else v_10818 = lisp_true; }}
#endif
    if (v_10818 == nil) goto v_10611;
    goto v_10619;
v_10615:
    stack[-1] = stack[-7];
    goto v_10616;
v_10617:
    v_10818 = stack[0];
    v_10818 = qcdr(v_10818);
    fn = elt(env, 20); // ordn
    v_10818 = (*qfn1(fn))(fn, v_10818);
    env = stack[-8];
    goto v_10618;
v_10619:
    goto v_10615;
v_10616:
    goto v_10617;
v_10618:
    v_10818 = cons(stack[-1], v_10818);
    env = stack[-8];
    stack[0] = v_10818;
    goto v_10609;
v_10611:
    goto v_10631;
v_10627:
    v_10819 = stack[-7];
    goto v_10628;
v_10629:
    v_10818 = elt(env, 10); // antisymmetric
    goto v_10630;
v_10631:
    goto v_10627;
v_10628:
    goto v_10629;
v_10630:
    v_10818 = Lflagp(nil, v_10819, v_10818);
    env = stack[-8];
    if (v_10818 == nil) goto v_10625;
    v_10818 = stack[0];
    v_10818 = qcdr(v_10818);
    fn = elt(env, 21); // repeats
    v_10818 = (*qfn1(fn))(fn, v_10818);
    env = stack[-8];
    if (v_10818 == nil) goto v_10637;
    goto v_10646;
v_10642:
    v_10819 = nil;
    goto v_10643;
v_10644:
    v_10818 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10645;
v_10646:
    goto v_10642;
v_10643:
    goto v_10644;
v_10645:
    return cons(v_10819, v_10818);
v_10637:
    goto v_10656;
v_10652:
    v_10818 = stack[0];
    v_10818 = qcdr(v_10818);
    fn = elt(env, 20); // ordn
    v_10819 = (*qfn1(fn))(fn, v_10818);
    env = stack[-8];
    stack[-4] = v_10819;
    goto v_10653;
v_10654:
    v_10818 = stack[0];
    v_10818 = qcdr(v_10818);
    goto v_10655;
v_10656:
    goto v_10652;
v_10653:
    goto v_10654;
v_10655:
    fn = elt(env, 22); // permp
    v_10818 = (*qfn2(fn))(fn, v_10819, v_10818);
    env = stack[-8];
    if (v_10818 == nil) goto v_10649;
    else goto v_10650;
v_10649:
    v_10818 = lisp_true;
    stack[-5] = v_10818;
    goto v_10635;
v_10650:
v_10635:
    goto v_10668;
v_10664:
    v_10818 = stack[0];
    v_10819 = qcar(v_10818);
    goto v_10665;
v_10666:
    v_10818 = stack[-4];
    goto v_10667;
v_10668:
    goto v_10664;
v_10665:
    goto v_10666;
v_10667:
    v_10818 = cons(v_10819, v_10818);
    env = stack[-8];
    stack[-7] = v_10818;
    goto v_10684;
v_10680:
    v_10819 = stack[-4];
    goto v_10681;
v_10682:
    v_10818 = stack[0];
    v_10818 = qcdr(v_10818);
    goto v_10683;
v_10684:
    goto v_10680;
v_10681:
    goto v_10682;
v_10683:
    if (equal(v_10819, v_10818)) goto v_10679;
    v_10818 = stack[-7];
    fn = elt(env, 19); // opmtch
    v_10818 = (*qfn1(fn))(fn, v_10818);
    env = stack[-8];
    stack[-4] = v_10818;
    goto v_10677;
v_10679:
    v_10818 = nil;
    goto v_10677;
    v_10818 = nil;
v_10677:
    if (v_10818 == nil) goto v_10675;
    v_10818 = stack[-5];
    if (v_10818 == nil) goto v_10696;
    v_10818 = stack[-4];
    fn = elt(env, 18); // simp
    v_10818 = (*qfn1(fn))(fn, v_10818);
    env = stack[-8];
    {
        fn = elt(env, 23); // negsq
        return (*qfn1(fn))(fn, v_10818);
    }
v_10696:
    v_10818 = stack[-4];
    {
        fn = elt(env, 18); // simp
        return (*qfn1(fn))(fn, v_10818);
    }
    v_10818 = nil;
    goto v_10320;
v_10675:
    v_10818 = stack[-7];
    stack[0] = v_10818;
    goto v_10609;
v_10625:
v_10609:
    goto v_10723;
v_10719:
    v_10819 = stack[-7];
    goto v_10720;
v_10721:
    v_10818 = elt(env, 11); // even
    goto v_10722;
v_10723:
    goto v_10719;
v_10720:
    goto v_10721;
v_10722:
    v_10818 = Lflagp(nil, v_10819, v_10818);
    env = stack[-8];
    if (v_10818 == nil) goto v_10717;
    v_10818 = lisp_true;
    goto v_10715;
v_10717:
    goto v_10734;
v_10730:
    v_10819 = stack[-7];
    goto v_10731;
v_10732:
    v_10818 = elt(env, 4); // odd
    goto v_10733;
v_10734:
    goto v_10730;
v_10731:
    goto v_10732;
v_10733:
    v_10818 = Lflagp(nil, v_10819, v_10818);
    env = stack[-8];
    goto v_10715;
    v_10818 = nil;
v_10715:
    if (v_10818 == nil) goto v_10713;
    v_10818 = stack[-6];
    if (v_10818 == nil) goto v_10739;
    else goto v_10740;
v_10739:
    v_10818 = nil;
    goto v_10738;
v_10740:
    v_10818 = stack[-6];
    v_10818 = qcar(v_10818);
    fn = elt(env, 18); // simp
    v_10818 = (*qfn1(fn))(fn, v_10818);
    env = stack[-8];
    stack[-6] = v_10818;
    v_10818 = qcar(v_10818);
    fn = elt(env, 24); // minusf
    v_10818 = (*qfn1(fn))(fn, v_10818);
    env = stack[-8];
    goto v_10738;
    v_10818 = nil;
v_10738:
    goto v_10711;
v_10713:
    v_10818 = nil;
    goto v_10711;
    v_10818 = nil;
v_10711:
    if (v_10818 == nil) goto v_10709;
    goto v_10762;
v_10758:
    v_10819 = stack[-7];
    goto v_10759;
v_10760:
    v_10818 = elt(env, 4); // odd
    goto v_10761;
v_10762:
    goto v_10758;
v_10759:
    goto v_10760;
v_10761:
    v_10818 = Lflagp(nil, v_10819, v_10818);
    env = stack[-8];
    if (v_10818 == nil) goto v_10756;
    v_10818 = stack[-5];
    v_10818 = (v_10818 == nil ? lisp_true : nil);
    stack[-5] = v_10818;
    goto v_10754;
v_10756:
v_10754:
    goto v_10774;
v_10768:
    stack[-1] = stack[-7];
    goto v_10769;
v_10770:
    v_10818 = stack[-6];
    fn = elt(env, 23); // negsq
    v_10818 = (*qfn1(fn))(fn, v_10818);
    env = stack[-8];
    fn = elt(env, 16); // prepsqxx
    v_10819 = (*qfn1(fn))(fn, v_10818);
    env = stack[-8];
    goto v_10771;
v_10772:
    v_10818 = stack[0];
    v_10818 = qcdr(v_10818);
    v_10818 = qcdr(v_10818);
    goto v_10773;
v_10774:
    goto v_10768;
v_10769:
    goto v_10770;
v_10771:
    goto v_10772;
v_10773:
    v_10818 = list2star(stack[-1], v_10819, v_10818);
    env = stack[-8];
    stack[0] = v_10818;
    v_10818 = stack[0];
    fn = elt(env, 19); // opmtch
    v_10818 = (*qfn1(fn))(fn, v_10818);
    env = stack[-8];
    stack[-4] = v_10818;
    if (v_10818 == nil) goto v_10785;
    v_10818 = stack[-5];
    if (v_10818 == nil) goto v_10791;
    v_10818 = stack[-4];
    fn = elt(env, 18); // simp
    v_10818 = (*qfn1(fn))(fn, v_10818);
    env = stack[-8];
    {
        fn = elt(env, 23); // negsq
        return (*qfn1(fn))(fn, v_10818);
    }
v_10791:
    v_10818 = stack[-4];
    {
        fn = elt(env, 18); // simp
        return (*qfn1(fn))(fn, v_10818);
    }
    v_10818 = nil;
    goto v_10320;
v_10785:
    goto v_10707;
v_10709:
v_10707:
    goto v_10805;
v_10801:
    v_10819 = stack[0];
    goto v_10802;
v_10803:
    v_10818 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10804;
v_10805:
    goto v_10801;
v_10802:
    goto v_10803;
v_10804:
    fn = elt(env, 14); // mksq
    v_10818 = (*qfn2(fn))(fn, v_10819, v_10818);
    env = stack[-8];
    stack[0] = v_10818;
    v_10818 = stack[-5];
    if (v_10818 == nil) goto v_10811;
    v_10818 = stack[0];
    {
        fn = elt(env, 23); // negsq
        return (*qfn1(fn))(fn, v_10818);
    }
v_10811:
    v_10818 = stack[0];
    goto v_10809;
    v_10818 = nil;
v_10809:
v_10320:
    return onevalue(v_10818);
}



// Code for ctx_filter

static LispObject CC_ctx_filter(LispObject env,
                         LispObject v_10311, LispObject v_10312)
{
    env = qenv(env);
    LispObject v_10398, v_10399, v_10400;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10311,v_10312);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_10398 = v_10312;
    stack[-4] = v_10311;
// end of prologue
    goto v_10319;
v_10315:
    stack[-5] = elt(env, 1); // ctx
    goto v_10316;
v_10317:
    fn = elt(env, 2); // ctx_ial
    v_10398 = (*qfn1(fn))(fn, v_10398);
    env = stack[-6];
    stack[-3] = v_10398;
v_10326:
    v_10398 = stack[-3];
    if (v_10398 == nil) goto v_10332;
    else goto v_10333;
v_10332:
    v_10398 = nil;
    goto v_10325;
v_10333:
    v_10398 = stack[-3];
    v_10398 = qcar(v_10398);
    v_10400 = v_10398;
    goto v_10347;
v_10343:
    v_10398 = v_10400;
    v_10399 = qcar(v_10398);
    goto v_10344;
v_10345:
    v_10398 = stack[-4];
    goto v_10346;
v_10347:
    goto v_10343;
v_10344:
    goto v_10345;
v_10346:
    v_10398 = Lmemq(nil, v_10399, v_10398);
    if (v_10398 == nil) goto v_10342;
    v_10398 = v_10400;
    v_10398 = ncons(v_10398);
    env = stack[-6];
    goto v_10340;
v_10342:
    v_10398 = nil;
v_10340:
    stack[-2] = v_10398;
    v_10398 = stack[-2];
    fn = elt(env, 3); // lastpair
    v_10398 = (*qfn1(fn))(fn, v_10398);
    env = stack[-6];
    stack[-1] = v_10398;
    v_10398 = stack[-3];
    v_10398 = qcdr(v_10398);
    stack[-3] = v_10398;
    v_10398 = stack[-1];
    if (!consp(v_10398)) goto v_10360;
    else goto v_10361;
v_10360:
    goto v_10326;
v_10361:
v_10327:
    v_10398 = stack[-3];
    if (v_10398 == nil) goto v_10365;
    else goto v_10366;
v_10365:
    v_10398 = stack[-2];
    goto v_10325;
v_10366:
    goto v_10374;
v_10370:
    stack[0] = stack[-1];
    goto v_10371;
v_10372:
    v_10398 = stack[-3];
    v_10398 = qcar(v_10398);
    v_10400 = v_10398;
    goto v_10387;
v_10383:
    v_10398 = v_10400;
    v_10399 = qcar(v_10398);
    goto v_10384;
v_10385:
    v_10398 = stack[-4];
    goto v_10386;
v_10387:
    goto v_10383;
v_10384:
    goto v_10385;
v_10386:
    v_10398 = Lmemq(nil, v_10399, v_10398);
    if (v_10398 == nil) goto v_10382;
    v_10398 = v_10400;
    v_10398 = ncons(v_10398);
    env = stack[-6];
    goto v_10380;
v_10382:
    v_10398 = nil;
v_10380:
    goto v_10373;
v_10374:
    goto v_10370;
v_10371:
    goto v_10372;
v_10373:
    v_10398 = Lrplacd(nil, stack[0], v_10398);
    env = stack[-6];
    v_10398 = stack[-1];
    fn = elt(env, 3); // lastpair
    v_10398 = (*qfn1(fn))(fn, v_10398);
    env = stack[-6];
    stack[-1] = v_10398;
    v_10398 = stack[-3];
    v_10398 = qcdr(v_10398);
    stack[-3] = v_10398;
    goto v_10327;
v_10325:
    goto v_10318;
v_10319:
    goto v_10315;
v_10316:
    goto v_10317;
v_10318:
    {
        LispObject v_10407 = stack[-5];
        return list2(v_10407, v_10398);
    }
}



// Code for read_typed_name

static LispObject CC_read_typed_name(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10345, v_10346;
    LispObject fn;
    argcheck(nargs, 0, "read_typed_name");
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
    v_10345 = qvalue(elt(env, 1)); // cursym!*
    stack[0] = v_10345;
    fn = elt(env, 4); // scan
    v_10345 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_10325;
v_10321:
    v_10346 = qvalue(elt(env, 1)); // cursym!*
    goto v_10322;
v_10323:
    v_10345 = elt(env, 2); // !*colon!*
    goto v_10324;
v_10325:
    goto v_10321;
v_10322:
    goto v_10323;
v_10324:
    if (v_10346 == v_10345) goto v_10320;
    goto v_10333;
v_10329:
    v_10345 = stack[0];
    goto v_10330;
v_10331:
    v_10346 = elt(env, 3); // general
    goto v_10332;
v_10333:
    goto v_10329;
v_10330:
    goto v_10331;
v_10332:
    return cons(v_10345, v_10346);
v_10320:
    fn = elt(env, 4); // scan
    v_10345 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_10342;
v_10338:
    goto v_10339;
v_10340:
    fn = elt(env, 5); // read_type
    v_10345 = (*qfnn(fn))(fn, 0);
    goto v_10341;
v_10342:
    goto v_10338;
v_10339:
    goto v_10340;
v_10341:
    {
        LispObject v_10348 = stack[0];
        return cons(v_10348, v_10345);
    }
    return onevalue(v_10345);
}



// Code for rl_bestgaussp

static LispObject CC_rl_bestgaussp(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10322;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10311);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10322 = v_10311;
// end of prologue
    goto v_10318;
v_10314:
    stack[0] = qvalue(elt(env, 1)); // rl_bestgaussp!*
    goto v_10315;
v_10316:
    v_10322 = ncons(v_10322);
    env = stack[-1];
    goto v_10317;
v_10318:
    goto v_10314;
v_10315:
    goto v_10316;
v_10317:
    {
        LispObject v_10324 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_10324, v_10322);
    }
}



// Code for replus

static LispObject CC_replus(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10340, v_10341;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10311);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_10341 = v_10311;
// end of prologue
    v_10340 = v_10341;
    if (v_10340 == nil) goto v_10315;
    else goto v_10316;
v_10315:
    v_10340 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10314;
v_10316:
    v_10340 = v_10341;
    if (!consp(v_10340)) goto v_10319;
    else goto v_10320;
v_10319:
    v_10340 = v_10341;
    goto v_10314;
v_10320:
    v_10340 = v_10341;
    v_10340 = qcdr(v_10340);
    if (v_10340 == nil) goto v_10323;
    else goto v_10324;
v_10323:
    v_10340 = v_10341;
    v_10340 = qcar(v_10340);
    goto v_10314;
v_10324:
    goto v_10336;
v_10332:
    stack[0] = elt(env, 1); // plus
    goto v_10333;
v_10334:
    v_10340 = v_10341;
    fn = elt(env, 2); // unplus
    v_10340 = (*qfn1(fn))(fn, v_10340);
    goto v_10335;
v_10336:
    goto v_10332;
v_10333:
    goto v_10334;
v_10335:
    {
        LispObject v_10343 = stack[0];
        return cons(v_10343, v_10340);
    }
    v_10340 = nil;
v_10314:
    return onevalue(v_10340);
}



// Code for rl_subat

static LispObject CC_rl_subat(LispObject env,
                         LispObject v_10311, LispObject v_10312)
{
    env = qenv(env);
    LispObject v_10329, v_10330;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10311,v_10312);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10329 = v_10312;
    v_10330 = v_10311;
// end of prologue
    goto v_10319;
v_10315:
    stack[0] = qvalue(elt(env, 1)); // rl_subat!*
    goto v_10316;
v_10317:
    goto v_10326;
v_10322:
    goto v_10323;
v_10324:
    goto v_10325;
v_10326:
    goto v_10322;
v_10323:
    goto v_10324;
v_10325:
    v_10329 = list2(v_10330, v_10329);
    env = stack[-1];
    goto v_10318;
v_10319:
    goto v_10315;
v_10316:
    goto v_10317;
v_10318:
    {
        LispObject v_10332 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_10332, v_10329);
    }
}



// Code for sf2ss

static LispObject CC_sf2ss(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10364, v_10365;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10311);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_10311;
// end of prologue
    v_10364 = stack[-1];
    if (!consp(v_10364)) goto v_10323;
    else goto v_10324;
v_10323:
    v_10364 = lisp_true;
    goto v_10322;
v_10324:
    v_10364 = stack[-1];
    v_10364 = qcar(v_10364);
    v_10364 = (consp(v_10364) ? nil : lisp_true);
    goto v_10322;
    v_10364 = nil;
v_10322:
    if (v_10364 == nil) goto v_10320;
    v_10364 = stack[-1];
    goto v_10316;
v_10320:
    v_10364 = stack[-1];
    fn = elt(env, 1); // searchpl
    v_10364 = (*qfn1(fn))(fn, v_10364);
    env = stack[-3];
    stack[-2] = v_10364;
    goto v_10340;
v_10336:
    v_10364 = stack[-2];
    fn = elt(env, 2); // qsort
    stack[0] = (*qfn1(fn))(fn, v_10364);
    env = stack[-3];
    goto v_10337;
v_10338:
    v_10364 = stack[-2];
    v_10364 = Llength(nil, v_10364);
    env = stack[-3];
    goto v_10339;
v_10340:
    goto v_10336;
v_10337:
    goto v_10338;
v_10339:
    v_10364 = cons(stack[0], v_10364);
    env = stack[-3];
    goto v_10353;
v_10347:
    stack[0] = v_10364;
    goto v_10348;
v_10349:
    goto v_10360;
v_10356:
    v_10365 = stack[-1];
    goto v_10357;
v_10358:
    goto v_10359;
v_10360:
    goto v_10356;
v_10357:
    goto v_10358;
v_10359:
    fn = elt(env, 3); // sq2sspl
    v_10365 = (*qfn2(fn))(fn, v_10365, v_10364);
    env = stack[-3];
    goto v_10350;
v_10351:
    v_10364 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10352;
v_10353:
    goto v_10347;
v_10348:
    goto v_10349;
v_10350:
    goto v_10351;
v_10352:
    v_10364 = list2star(stack[0], v_10365, v_10364);
    env = stack[-3];
    {
        fn = elt(env, 4); // lx2xx
        return (*qfn1(fn))(fn, v_10364);
    }
v_10316:
    return onevalue(v_10364);
}



// Code for ibalp_unvar!-unsatlist

static LispObject CC_ibalp_unvarKunsatlist(LispObject env,
                         LispObject v_10311, LispObject v_10312)
{
    env = qenv(env);
    LispObject v_10690, v_10691;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10311,v_10312);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_10312;
    v_10690 = v_10311;
// end of prologue
    stack[-5] = v_10690;
v_10320:
    v_10690 = stack[-5];
    if (v_10690 == nil) goto v_10324;
    else goto v_10325;
v_10324:
    goto v_10319;
v_10325:
    v_10690 = stack[-5];
    v_10690 = qcar(v_10690);
    stack[-3] = v_10690;
    goto v_10336;
v_10332:
    v_10690 = stack[-3];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    stack[0] = qcdr(v_10690);
    goto v_10333;
v_10334:
    goto v_10347;
v_10343:
    v_10691 = stack[-4];
    goto v_10344;
v_10345:
    v_10690 = stack[-3];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcar(v_10690);
    goto v_10346;
v_10347:
    goto v_10343;
v_10344:
    goto v_10345;
v_10346:
    fn = elt(env, 1); // lto_delq
    v_10690 = (*qfn2(fn))(fn, v_10691, v_10690);
    env = stack[-6];
    goto v_10335;
v_10336:
    goto v_10332;
v_10333:
    goto v_10334;
v_10335:
    fn = elt(env, 2); // setcar
    v_10690 = (*qfn2(fn))(fn, stack[0], v_10690);
    env = stack[-6];
    v_10690 = stack[-3];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcar(v_10690);
    if (v_10690 == nil) goto v_10357;
    else goto v_10358;
v_10357:
    v_10690 = stack[-3];
    v_10690 = qcar(v_10690);
    stack[-2] = v_10690;
v_10368:
    v_10690 = stack[-2];
    if (v_10690 == nil) goto v_10373;
    else goto v_10374;
v_10373:
    goto v_10367;
v_10374:
    v_10690 = stack[-2];
    v_10690 = qcar(v_10690);
    stack[-1] = v_10690;
    goto v_10385;
v_10381:
    v_10690 = stack[-1];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    stack[0] = qcdr(v_10690);
    goto v_10382;
v_10383:
    v_10690 = stack[-1];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcar(v_10690);
    v_10690 = add1(v_10690);
    env = stack[-6];
    goto v_10384;
v_10385:
    goto v_10381;
v_10382:
    goto v_10383;
v_10384:
    fn = elt(env, 2); // setcar
    v_10690 = (*qfn2(fn))(fn, stack[0], v_10690);
    env = stack[-6];
    goto v_10403;
v_10399:
    v_10690 = stack[-1];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    stack[0] = qcdr(v_10690);
    goto v_10400;
v_10401:
    v_10690 = stack[-1];
    fn = elt(env, 3); // ibalp_calcmom
    v_10690 = (*qfn1(fn))(fn, v_10690);
    env = stack[-6];
    goto v_10402;
v_10403:
    goto v_10399;
v_10400:
    goto v_10401;
v_10402:
    fn = elt(env, 2); // setcar
    v_10690 = (*qfn2(fn))(fn, stack[0], v_10690);
    env = stack[-6];
    v_10690 = stack[-2];
    v_10690 = qcdr(v_10690);
    stack[-2] = v_10690;
    goto v_10368;
v_10367:
    v_10690 = stack[-3];
    v_10690 = qcdr(v_10690);
    v_10690 = qcar(v_10690);
    stack[-2] = v_10690;
v_10423:
    v_10690 = stack[-2];
    if (v_10690 == nil) goto v_10429;
    else goto v_10430;
v_10429:
    goto v_10422;
v_10430:
    v_10690 = stack[-2];
    v_10690 = qcar(v_10690);
    stack[-1] = v_10690;
    goto v_10441;
v_10437:
    v_10690 = stack[-1];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    stack[0] = qcdr(v_10690);
    goto v_10438;
v_10439:
    v_10690 = stack[-1];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcar(v_10690);
    v_10690 = add1(v_10690);
    env = stack[-6];
    goto v_10440;
v_10441:
    goto v_10437;
v_10438:
    goto v_10439;
v_10440:
    fn = elt(env, 2); // setcar
    v_10690 = (*qfn2(fn))(fn, stack[0], v_10690);
    env = stack[-6];
    goto v_10461;
v_10457:
    v_10690 = stack[-1];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    stack[0] = qcdr(v_10690);
    goto v_10458;
v_10459:
    v_10690 = stack[-1];
    fn = elt(env, 3); // ibalp_calcmom
    v_10690 = (*qfn1(fn))(fn, v_10690);
    env = stack[-6];
    goto v_10460;
v_10461:
    goto v_10457;
v_10458:
    goto v_10459;
v_10460:
    fn = elt(env, 2); // setcar
    v_10690 = (*qfn2(fn))(fn, stack[0], v_10690);
    env = stack[-6];
    v_10690 = stack[-2];
    v_10690 = qcdr(v_10690);
    stack[-2] = v_10690;
    goto v_10423;
v_10422:
    v_10690 = stack[-3];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcar(v_10690);
    stack[-1] = v_10690;
v_10481:
    v_10690 = stack[-1];
    if (v_10690 == nil) goto v_10492;
    else goto v_10493;
v_10492:
    goto v_10480;
v_10493:
    v_10690 = stack[-1];
    v_10690 = qcar(v_10690);
    goto v_10504;
v_10500:
    v_10691 = v_10690;
    v_10691 = qcdr(v_10691);
    v_10691 = qcdr(v_10691);
    v_10691 = qcdr(v_10691);
    v_10691 = qcdr(v_10691);
    v_10691 = qcdr(v_10691);
    v_10691 = qcdr(v_10691);
    v_10691 = qcdr(v_10691);
    v_10691 = qcdr(v_10691);
    v_10691 = qcdr(v_10691);
    stack[0] = qcdr(v_10691);
    goto v_10501;
v_10502:
    goto v_10521;
v_10517:
    v_10691 = stack[-3];
    goto v_10518;
v_10519:
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcar(v_10690);
    goto v_10520;
v_10521:
    goto v_10517;
v_10518:
    goto v_10519;
v_10520:
    fn = elt(env, 1); // lto_delq
    v_10690 = (*qfn2(fn))(fn, v_10691, v_10690);
    env = stack[-6];
    goto v_10503;
v_10504:
    goto v_10500;
v_10501:
    goto v_10502;
v_10503:
    fn = elt(env, 2); // setcar
    v_10690 = (*qfn2(fn))(fn, stack[0], v_10690);
    env = stack[-6];
    v_10690 = stack[-1];
    v_10690 = qcdr(v_10690);
    stack[-1] = v_10690;
    goto v_10481;
v_10480:
    goto v_10542;
v_10538:
    v_10690 = stack[-3];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10691 = qcdr(v_10690);
    goto v_10539;
v_10540:
    v_10690 = nil;
    goto v_10541;
v_10542:
    goto v_10538;
v_10539:
    goto v_10540;
v_10541:
    fn = elt(env, 2); // setcar
    v_10690 = (*qfn2(fn))(fn, v_10691, v_10690);
    env = stack[-6];
    v_10690 = stack[-3];
    fn = elt(env, 4); // ibalp_getnewwl
    v_10690 = (*qfn1(fn))(fn, v_10690);
    env = stack[-6];
    stack[-1] = v_10690;
    goto v_10558;
v_10554:
    v_10690 = stack[-3];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    stack[0] = qcdr(v_10690);
    goto v_10555;
v_10556:
    goto v_10571;
v_10567:
    v_10691 = stack[-1];
    goto v_10568;
v_10569:
    v_10690 = stack[-3];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcar(v_10690);
    goto v_10570;
v_10571:
    goto v_10567;
v_10568:
    goto v_10569;
v_10570:
    v_10690 = cons(v_10691, v_10690);
    env = stack[-6];
    goto v_10557;
v_10558:
    goto v_10554;
v_10555:
    goto v_10556;
v_10557:
    fn = elt(env, 2); // setcar
    v_10690 = (*qfn2(fn))(fn, stack[0], v_10690);
    env = stack[-6];
    goto v_10586;
v_10582:
    v_10690 = stack[-1];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    stack[0] = qcdr(v_10690);
    goto v_10583;
v_10584:
    goto v_10603;
v_10599:
    v_10691 = stack[-3];
    goto v_10600;
v_10601:
    v_10690 = stack[-1];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcar(v_10690);
    goto v_10602;
v_10603:
    goto v_10599;
v_10600:
    goto v_10601;
v_10602:
    v_10690 = cons(v_10691, v_10690);
    env = stack[-6];
    goto v_10585;
v_10586:
    goto v_10582;
v_10583:
    goto v_10584;
v_10585:
    fn = elt(env, 2); // setcar
    v_10690 = (*qfn2(fn))(fn, stack[0], v_10690);
    env = stack[-6];
    v_10690 = stack[-3];
    fn = elt(env, 4); // ibalp_getnewwl
    v_10690 = (*qfn1(fn))(fn, v_10690);
    env = stack[-6];
    stack[-1] = v_10690;
    v_10690 = stack[-1];
    if (v_10690 == nil) goto v_10622;
    goto v_10629;
v_10625:
    v_10690 = stack[-3];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    stack[0] = qcdr(v_10690);
    goto v_10626;
v_10627:
    goto v_10642;
v_10638:
    v_10691 = stack[-1];
    goto v_10639;
v_10640:
    v_10690 = stack[-3];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcar(v_10690);
    goto v_10641;
v_10642:
    goto v_10638;
v_10639:
    goto v_10640;
v_10641:
    v_10690 = cons(v_10691, v_10690);
    env = stack[-6];
    goto v_10628;
v_10629:
    goto v_10625;
v_10626:
    goto v_10627;
v_10628:
    fn = elt(env, 2); // setcar
    v_10690 = (*qfn2(fn))(fn, stack[0], v_10690);
    env = stack[-6];
    goto v_10657;
v_10653:
    v_10690 = stack[-1];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    stack[0] = qcdr(v_10690);
    goto v_10654;
v_10655:
    goto v_10674;
v_10670:
    v_10691 = stack[-3];
    goto v_10671;
v_10672:
    v_10690 = stack[-1];
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcdr(v_10690);
    v_10690 = qcar(v_10690);
    goto v_10673;
v_10674:
    goto v_10670;
v_10671:
    goto v_10672;
v_10673:
    v_10690 = cons(v_10691, v_10690);
    env = stack[-6];
    goto v_10656;
v_10657:
    goto v_10653;
v_10654:
    goto v_10655;
v_10656:
    fn = elt(env, 2); // setcar
    v_10690 = (*qfn2(fn))(fn, stack[0], v_10690);
    env = stack[-6];
    goto v_10620;
v_10622:
v_10620:
    goto v_10356;
v_10358:
v_10356:
    v_10690 = stack[-5];
    v_10690 = qcdr(v_10690);
    stack[-5] = v_10690;
    goto v_10320;
v_10319:
    v_10690 = nil;
    return onevalue(v_10690);
}



// Code for vdpputprop

static LispObject CC_vdpputprop(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10434, v_10435, v_10436, v_10437;
    LispObject fn;
    LispObject v_10313, v_10312, v_10311;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "vdpputprop");
    va_start(aa, nargs);
    v_10311 = va_arg(aa, LispObject);
    v_10312 = va_arg(aa, LispObject);
    v_10313 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_10313,v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_10311,v_10312,v_10313);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_10313;
    stack[-3] = v_10312;
    stack[-4] = v_10311;
// end of prologue
    stack[-5] = nil;
    v_10434 = stack[-4];
    v_10434 = Lconsp(nil, v_10434);
    env = stack[-6];
    if (v_10434 == nil) goto v_10325;
    else goto v_10326;
v_10325:
    v_10434 = lisp_true;
    goto v_10324;
v_10326:
    v_10434 = stack[-4];
    v_10434 = qcdr(v_10434);
    stack[-5] = v_10434;
    v_10434 = Lconsp(nil, v_10434);
    env = stack[-6];
    if (v_10434 == nil) goto v_10334;
    else goto v_10335;
v_10334:
    v_10434 = lisp_true;
    goto v_10333;
v_10335:
    v_10434 = stack[-5];
    v_10434 = qcdr(v_10434);
    stack[-5] = v_10434;
    v_10434 = Lconsp(nil, v_10434);
    env = stack[-6];
    if (v_10434 == nil) goto v_10344;
    else goto v_10345;
v_10344:
    v_10434 = lisp_true;
    goto v_10343;
v_10345:
    v_10434 = stack[-5];
    v_10434 = qcdr(v_10434);
    stack[-5] = v_10434;
    v_10434 = Lconsp(nil, v_10434);
    env = stack[-6];
    if (v_10434 == nil) goto v_10354;
    else goto v_10355;
v_10354:
    v_10434 = lisp_true;
    goto v_10353;
v_10355:
    v_10434 = stack[-5];
    v_10434 = qcdr(v_10434);
    stack[-5] = v_10434;
    v_10434 = Lconsp(nil, v_10434);
    env = stack[-6];
    v_10434 = (v_10434 == nil ? lisp_true : nil);
    goto v_10353;
    v_10434 = nil;
v_10353:
    goto v_10343;
    v_10434 = nil;
v_10343:
    goto v_10333;
    v_10434 = nil;
v_10333:
    goto v_10324;
    v_10434 = nil;
v_10324:
    if (v_10434 == nil) goto v_10322;
    goto v_10373;
v_10367:
    stack[-1] = elt(env, 1); // dipoly
    goto v_10368;
v_10369:
    stack[0] = (LispObject)96+TAG_FIXNUM; // 6
    goto v_10370;
v_10371:
    goto v_10385;
v_10377:
    v_10437 = elt(env, 2); // "vdpputprop given a non-vdp as 1st parameter"
    goto v_10378;
v_10379:
    v_10436 = stack[-4];
    goto v_10380;
v_10381:
    v_10435 = stack[-3];
    goto v_10382;
v_10383:
    v_10434 = stack[-2];
    goto v_10384;
v_10385:
    goto v_10377;
v_10378:
    goto v_10379;
v_10380:
    goto v_10381;
v_10382:
    goto v_10383;
v_10384:
    v_10434 = list4(v_10437, v_10436, v_10435, v_10434);
    env = stack[-6];
    goto v_10372;
v_10373:
    goto v_10367;
v_10368:
    goto v_10369;
v_10370:
    goto v_10371;
v_10372:
    fn = elt(env, 3); // rerror
    v_10434 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_10434);
    env = stack[-6];
    goto v_10320;
v_10322:
v_10320:
    goto v_10394;
v_10390:
    v_10435 = stack[-3];
    goto v_10391;
v_10392:
    v_10434 = stack[-5];
    v_10434 = qcar(v_10434);
    goto v_10393;
v_10394:
    goto v_10390;
v_10391:
    goto v_10392;
v_10393:
    v_10434 = Lassoc(nil, v_10435, v_10434);
    v_10435 = v_10434;
    v_10434 = v_10435;
    if (v_10434 == nil) goto v_10402;
    goto v_10409;
v_10405:
    goto v_10406;
v_10407:
    v_10434 = stack[-2];
    goto v_10408;
v_10409:
    goto v_10405;
v_10406:
    goto v_10407;
v_10408:
    v_10434 = Lrplacd(nil, v_10435, v_10434);
    goto v_10400;
v_10402:
    goto v_10419;
v_10415:
    stack[0] = stack[-5];
    goto v_10416;
v_10417:
    goto v_10428;
v_10422:
    v_10436 = stack[-3];
    goto v_10423;
v_10424:
    v_10435 = stack[-2];
    goto v_10425;
v_10426:
    v_10434 = stack[-5];
    v_10434 = qcar(v_10434);
    goto v_10427;
v_10428:
    goto v_10422;
v_10423:
    goto v_10424;
v_10425:
    goto v_10426;
v_10427:
    v_10434 = acons(v_10436, v_10435, v_10434);
    env = stack[-6];
    goto v_10418;
v_10419:
    goto v_10415;
v_10416:
    goto v_10417;
v_10418:
    v_10434 = Lrplaca(nil, stack[0], v_10434);
    goto v_10400;
v_10400:
    v_10434 = stack[-4];
    return onevalue(v_10434);
}



// Code for equalreplaceby

static LispObject CC_equalreplaceby(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10321, v_10322;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10321 = v_10311;
// end of prologue
    goto v_10318;
v_10314:
    v_10322 = elt(env, 1); // replaceby
    goto v_10315;
v_10316:
    goto v_10317;
v_10318:
    goto v_10314;
v_10315:
    goto v_10316;
v_10317:
    return cons(v_10322, v_10321);
}



// Code for class

static LispObject CC_class(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10347, v_10348;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10311);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10311;
// end of prologue
    goto v_10321;
v_10317:
    v_10347 = stack[0];
    fn = elt(env, 3); // ord
    v_10348 = (*qfn1(fn))(fn, v_10347);
    env = stack[-1];
    goto v_10318;
v_10319:
    v_10347 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10320;
v_10321:
    goto v_10317;
v_10318:
    goto v_10319;
v_10320:
    if (v_10348 == v_10347) goto v_10315;
    else goto v_10316;
v_10315:
    v_10347 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10314;
v_10316:
    goto v_10338;
v_10334:
    v_10348 = qvalue(elt(env, 1)); // ordering
    goto v_10335;
v_10336:
    v_10347 = elt(env, 2); // lex
    goto v_10337;
v_10338:
    goto v_10334;
v_10335:
    goto v_10336;
v_10337:
    if (v_10348 == v_10347) goto v_10332;
    else goto v_10333;
v_10332:
    v_10347 = stack[0];
    goto v_10331;
v_10333:
    v_10347 = stack[0];
    v_10347 = qcdr(v_10347);
    goto v_10331;
    v_10347 = nil;
v_10331:
    v_10347 = Lreverse(nil, v_10347);
    env = stack[-1];
    fn = elt(env, 4); // leftzeros
    v_10347 = (*qfn1(fn))(fn, v_10347);
    v_10347 = (LispObject)((intptr_t)(v_10347) + 0x10);
    goto v_10314;
    v_10347 = nil;
v_10314:
    return onevalue(v_10347);
}



// Code for ord2

static LispObject CC_ord2(LispObject env,
                         LispObject v_10311, LispObject v_10312)
{
    env = qenv(env);
    LispObject v_10344, v_10345;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10311,v_10312);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10312;
    stack[-1] = v_10311;
// end of prologue
    goto v_10323;
v_10319:
    v_10345 = stack[-1];
    goto v_10320;
v_10321:
    v_10344 = stack[0];
    goto v_10322;
v_10323:
    goto v_10319;
v_10320:
    goto v_10321;
v_10322:
    fn = elt(env, 1); // ordp
    v_10344 = (*qfn2(fn))(fn, v_10345, v_10344);
    if (v_10344 == nil) goto v_10317;
    goto v_10331;
v_10327:
    v_10345 = stack[-1];
    goto v_10328;
v_10329:
    v_10344 = stack[0];
    goto v_10330;
v_10331:
    goto v_10327;
v_10328:
    goto v_10329;
v_10330:
    return list2(v_10345, v_10344);
v_10317:
    goto v_10341;
v_10337:
    v_10345 = stack[0];
    goto v_10338;
v_10339:
    v_10344 = stack[-1];
    goto v_10340;
v_10341:
    goto v_10337;
v_10338:
    goto v_10339;
v_10340:
    return list2(v_10345, v_10344);
    v_10344 = nil;
    return onevalue(v_10344);
}



// Code for moduntag

static LispObject CC_moduntag(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10363, v_10364;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10311);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10311;
// end of prologue
    stack[-1] = nil;
v_10316:
    goto v_10326;
v_10322:
    v_10364 = stack[0];
    goto v_10323;
v_10324:
    v_10363 = elt(env, 1); // !:mod!:
    goto v_10325;
v_10326:
    goto v_10322;
v_10323:
    goto v_10324;
v_10325:
    if (!consp(v_10364)) goto v_10320;
    v_10364 = qcar(v_10364);
    if (v_10364 == v_10363) goto v_10319;
    else goto v_10320;
v_10319:
    goto v_10334;
v_10330:
    v_10364 = stack[-1];
    goto v_10331;
v_10332:
    v_10363 = stack[0];
    v_10363 = qcdr(v_10363);
    goto v_10333;
v_10334:
    goto v_10330;
v_10331:
    goto v_10332;
v_10333:
    {
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_10364, v_10363);
    }
v_10320:
    v_10363 = stack[0];
    if (!consp(v_10363)) goto v_10338;
    else goto v_10339;
v_10338:
    goto v_10346;
v_10342:
    v_10364 = stack[-1];
    goto v_10343;
v_10344:
    v_10363 = stack[0];
    goto v_10345;
v_10346:
    goto v_10342;
v_10343:
    goto v_10344;
v_10345:
    {
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_10364, v_10363);
    }
v_10339:
    goto v_10356;
v_10352:
    v_10363 = stack[0];
    v_10363 = qcar(v_10363);
    v_10364 = CC_moduntag(elt(env, 0), v_10363);
    env = stack[-2];
    goto v_10353;
v_10354:
    v_10363 = stack[-1];
    goto v_10355;
v_10356:
    goto v_10352;
v_10353:
    goto v_10354;
v_10355:
    v_10363 = cons(v_10364, v_10363);
    env = stack[-2];
    stack[-1] = v_10363;
    v_10363 = stack[0];
    v_10363 = qcdr(v_10363);
    stack[0] = v_10363;
    goto v_10316;
    v_10363 = nil;
    return onevalue(v_10363);
}



// Code for rrdls

static LispObject CC_rrdls(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_10407, v_10408, v_10409;
    LispObject fn;
    argcheck(nargs, 0, "rrdls");
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
    stack[0] = nil;
v_10317:
    fn = elt(env, 7); // rread1
    v_10407 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_10407;
    goto v_10328;
v_10324:
    v_10408 = qvalue(elt(env, 1)); // ttype!*
    goto v_10325;
v_10326:
    v_10407 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_10327;
v_10328:
    goto v_10324;
v_10325:
    goto v_10326;
v_10327:
    if (v_10408 == v_10407) goto v_10323;
    goto v_10318;
v_10323:
    goto v_10337;
v_10333:
    v_10408 = stack[-1];
    goto v_10334;
v_10335:
    v_10407 = elt(env, 2); // !)
    goto v_10336;
v_10337:
    goto v_10333;
v_10334:
    goto v_10335;
v_10336:
    if (v_10408 == v_10407) goto v_10331;
    else goto v_10332;
v_10331:
    v_10407 = stack[0];
    goto v_10316;
v_10332:
    goto v_10347;
v_10343:
    v_10408 = stack[-1];
    goto v_10344;
v_10345:
    v_10407 = elt(env, 3); // !.
    goto v_10346;
v_10347:
    goto v_10343;
v_10344:
    goto v_10345;
v_10346:
    if (v_10408 == v_10407) goto v_10342;
    goto v_10318;
v_10342:
    fn = elt(env, 7); // rread1
    v_10407 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_10407;
    fn = elt(env, 8); // ptoken
    v_10407 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_10409 = v_10407;
    goto v_10364;
v_10360:
    v_10408 = qvalue(elt(env, 1)); // ttype!*
    goto v_10361;
v_10362:
    v_10407 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_10363;
v_10364:
    goto v_10360;
v_10361:
    goto v_10362;
v_10363:
    if (v_10408 == v_10407) goto v_10359;
    v_10407 = lisp_true;
    goto v_10357;
v_10359:
    goto v_10374;
v_10370:
    v_10408 = v_10409;
    goto v_10371;
v_10372:
    v_10407 = elt(env, 2); // !)
    goto v_10373;
v_10374:
    goto v_10370;
v_10371:
    goto v_10372;
v_10373:
    v_10407 = (v_10408 == v_10407 ? lisp_true : nil);
    v_10407 = (v_10407 == nil ? lisp_true : nil);
    goto v_10357;
    v_10407 = nil;
v_10357:
    if (v_10407 == nil) goto v_10355;
    v_10407 = elt(env, 4); // " "
    qvalue(elt(env, 5)) = v_10407; // nxtsym!*
    goto v_10385;
v_10381:
    v_10408 = elt(env, 6); // "Invalid S-expression"
    goto v_10382;
v_10383:
    v_10407 = nil;
    goto v_10384;
v_10385:
    goto v_10381;
v_10382:
    goto v_10383;
v_10384:
    fn = elt(env, 9); // symerr
    v_10407 = (*qfn2(fn))(fn, v_10408, v_10407);
    env = stack[-2];
    goto v_10353;
v_10355:
    goto v_10395;
v_10391:
    v_10408 = stack[0];
    goto v_10392;
v_10393:
    v_10407 = stack[-1];
    goto v_10394;
v_10395:
    goto v_10391;
v_10392:
    goto v_10393;
v_10394:
        return Lnconc(nil, v_10408, v_10407);
v_10353:
v_10318:
    goto v_10403;
v_10399:
    goto v_10400;
v_10401:
    v_10407 = stack[-1];
    v_10407 = ncons(v_10407);
    env = stack[-2];
    goto v_10402;
v_10403:
    goto v_10399;
v_10400:
    goto v_10401;
v_10402:
    v_10407 = Lnconc(nil, stack[0], v_10407);
    env = stack[-2];
    stack[0] = v_10407;
    goto v_10317;
v_10316:
    return onevalue(v_10407);
}



// Code for rl_susipost

static LispObject CC_rl_susipost(LispObject env,
                         LispObject v_10311, LispObject v_10312)
{
    env = qenv(env);
    LispObject v_10329, v_10330;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10311,v_10312);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10329 = v_10312;
    v_10330 = v_10311;
// end of prologue
    goto v_10319;
v_10315:
    stack[0] = qvalue(elt(env, 1)); // rl_susipost!*
    goto v_10316;
v_10317:
    goto v_10326;
v_10322:
    goto v_10323;
v_10324:
    goto v_10325;
v_10326:
    goto v_10322;
v_10323:
    goto v_10324;
v_10325:
    v_10329 = list2(v_10330, v_10329);
    env = stack[-1];
    goto v_10318;
v_10319:
    goto v_10315;
v_10316:
    goto v_10317;
v_10318:
    {
        LispObject v_10332 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_10332, v_10329);
    }
}



// Code for rl_simp1

static LispObject CC_rl_simp1(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10593, v_10594, v_10595, v_10596;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10311);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_10311;
// end of prologue
v_10310:
    v_10593 = qvalue(elt(env, 1)); // rl_cid!*
    if (v_10593 == nil) goto v_10319;
    else goto v_10320;
v_10319:
    v_10593 = elt(env, 2); // "select a context"
    v_10593 = ncons(v_10593);
    env = stack[-5];
    fn = elt(env, 10); // rederr
    v_10593 = (*qfn1(fn))(fn, v_10593);
    env = stack[-5];
    goto v_10318;
v_10320:
v_10318:
    v_10593 = stack[0];
    if (!consp(v_10593)) goto v_10327;
    else goto v_10328;
v_10327:
    v_10593 = stack[0];
    {
        fn = elt(env, 11); // rl_simpatom
        return (*qfn1(fn))(fn, v_10593);
    }
v_10328:
    v_10593 = lisp_true;
// Binding !*strict_argcount
// FLUIDBIND: reloadenv=5 litvec-offset=3 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 3, -1);
    qvalue(elt(env, 3)) = v_10593; // !*strict_argcount
    v_10593 = stack[0];
    fn = elt(env, 12); // argnochk
    v_10593 = (*qfn1(fn))(fn, v_10593);
    env = stack[-5];
    ;}  // end of a binding scope
    goto v_10345;
v_10341:
    v_10593 = stack[0];
    v_10594 = qcar(v_10593);
    goto v_10342;
v_10343:
    v_10593 = elt(env, 4); // rl_simpfn
    goto v_10344;
v_10345:
    goto v_10341;
v_10342:
    goto v_10343;
v_10344:
    v_10593 = get(v_10594, v_10593);
    env = stack[-5];
    v_10594 = v_10593;
    if (v_10593 == nil) goto v_10339;
    v_10593 = v_10594;
    if (!symbolp(v_10593)) v_10593 = nil;
    else { v_10593 = qfastgets(v_10593);
           if (v_10593 != nil) { v_10593 = elt(v_10593, 62); // full
#ifdef RECORD_GET
             if (v_10593 == SPID_NOPROP)
                record_get(elt(fastget_names, 62), 0),
                v_10593 = nil;
             else record_get(elt(fastget_names, 62), 1),
                v_10593 = lisp_true; }
           else record_get(elt(fastget_names, 62), 0); }
#else
             if (v_10593 == SPID_NOPROP) v_10593 = nil; else v_10593 = lisp_true; }}
#endif
    if (v_10593 == nil) goto v_10352;
    goto v_10360;
v_10356:
    stack[-1] = v_10594;
    goto v_10357;
v_10358:
    v_10593 = stack[0];
    v_10593 = ncons(v_10593);
    env = stack[-5];
    goto v_10359;
v_10360:
    goto v_10356;
v_10357:
    goto v_10358;
v_10359:
    {
        LispObject v_10602 = stack[-1];
        fn = elt(env, 13); // apply
        return (*qfn2(fn))(fn, v_10602, v_10593);
    }
v_10352:
    goto v_10371;
v_10367:
    stack[-1] = v_10594;
    goto v_10368;
v_10369:
    v_10593 = stack[0];
    v_10593 = qcdr(v_10593);
    v_10593 = ncons(v_10593);
    env = stack[-5];
    goto v_10370;
v_10371:
    goto v_10367;
v_10368:
    goto v_10369;
v_10370:
    {
        LispObject v_10603 = stack[-1];
        fn = elt(env, 13); // apply
        return (*qfn2(fn))(fn, v_10603, v_10593);
    }
    v_10593 = nil;
    goto v_10316;
v_10339:
    goto v_10385;
v_10381:
    v_10593 = stack[0];
    v_10595 = qcar(v_10593);
    goto v_10382;
v_10383:
    goto v_10393;
v_10389:
    v_10593 = qvalue(elt(env, 1)); // rl_cid!*
    v_10594 = qcar(v_10593);
    goto v_10390;
v_10391:
    v_10593 = elt(env, 5); // simpfnname
    goto v_10392;
v_10393:
    goto v_10389;
v_10390:
    goto v_10391;
v_10392:
    v_10593 = get(v_10594, v_10593);
    env = stack[-5];
    goto v_10384;
v_10385:
    goto v_10381;
v_10382:
    goto v_10383;
v_10384:
    v_10593 = get(v_10595, v_10593);
    env = stack[-5];
    v_10594 = v_10593;
    if (v_10593 == nil) goto v_10379;
    v_10593 = v_10594;
    if (!symbolp(v_10593)) v_10593 = nil;
    else { v_10593 = qfastgets(v_10593);
           if (v_10593 != nil) { v_10593 = elt(v_10593, 62); // full
#ifdef RECORD_GET
             if (v_10593 == SPID_NOPROP)
                record_get(elt(fastget_names, 62), 0),
                v_10593 = nil;
             else record_get(elt(fastget_names, 62), 1),
                v_10593 = lisp_true; }
           else record_get(elt(fastget_names, 62), 0); }
#else
             if (v_10593 == SPID_NOPROP) v_10593 = nil; else v_10593 = lisp_true; }}
#endif
    if (v_10593 == nil) goto v_10400;
    goto v_10408;
v_10404:
    stack[-1] = v_10594;
    goto v_10405;
v_10406:
    v_10593 = stack[0];
    v_10593 = ncons(v_10593);
    env = stack[-5];
    goto v_10407;
v_10408:
    goto v_10404;
v_10405:
    goto v_10406;
v_10407:
    {
        LispObject v_10604 = stack[-1];
        fn = elt(env, 13); // apply
        return (*qfn2(fn))(fn, v_10604, v_10593);
    }
v_10400:
    goto v_10419;
v_10415:
    stack[-1] = v_10594;
    goto v_10416;
v_10417:
    v_10593 = stack[0];
    v_10593 = qcdr(v_10593);
    v_10593 = ncons(v_10593);
    env = stack[-5];
    goto v_10418;
v_10419:
    goto v_10415;
v_10416:
    goto v_10417;
v_10418:
    {
        LispObject v_10605 = stack[-1];
        fn = elt(env, 13); // apply
        return (*qfn2(fn))(fn, v_10605, v_10593);
    }
    v_10593 = nil;
    goto v_10316;
v_10379:
    v_10593 = stack[0];
    v_10593 = qcar(v_10593);
    if (!symbolp(v_10593)) v_10593 = nil;
    else { v_10593 = qfastgets(v_10593);
           if (v_10593 != nil) { v_10593 = elt(v_10593, 45); // psopfn
#ifdef RECORD_GET
             if (v_10593 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v_10593 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v_10593 == SPID_NOPROP) v_10593 = nil; }}
#endif
    v_10594 = v_10593;
    if (v_10593 == nil) goto v_10427;
    goto v_10436;
v_10432:
    goto v_10433;
v_10434:
    v_10593 = stack[0];
    v_10593 = qcdr(v_10593);
    goto v_10435;
v_10436:
    goto v_10432;
v_10433:
    goto v_10434;
v_10435:
    v_10593 = Lapply1(nil, v_10594, v_10593);
    env = stack[-5];
    stack[-1] = v_10593;
    goto v_10448;
v_10444:
    v_10594 = stack[-1];
    goto v_10445;
v_10446:
    v_10593 = stack[0];
    goto v_10447;
v_10448:
    goto v_10444;
v_10445:
    goto v_10446;
v_10447:
    if (equal(v_10594, v_10593)) goto v_10443;
    v_10593 = stack[-1];
    stack[0] = v_10593;
    goto v_10310;
v_10443:
    goto v_10425;
v_10427:
v_10425:
    v_10593 = stack[0];
    v_10593 = qcar(v_10593);
    if (!symbolp(v_10593)) v_10593 = nil;
    else { v_10593 = qfastgets(v_10593);
           if (v_10593 != nil) { v_10593 = elt(v_10593, 59); // opfn
#ifdef RECORD_GET
             if (v_10593 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v_10593 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v_10593 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v_10593 == SPID_NOPROP) v_10593 = nil; else v_10593 = lisp_true; }}
#endif
    if (v_10593 == nil) goto v_10456;
    goto v_10466;
v_10462:
    v_10593 = stack[0];
    stack[-4] = qcar(v_10593);
    goto v_10463;
v_10464:
    v_10593 = stack[0];
    v_10593 = qcdr(v_10593);
    stack[-3] = v_10593;
    v_10593 = stack[-3];
    if (v_10593 == nil) goto v_10479;
    else goto v_10480;
v_10479:
    v_10593 = nil;
    goto v_10473;
v_10480:
    v_10593 = stack[-3];
    v_10593 = qcar(v_10593);
    fn = elt(env, 14); // reval
    v_10593 = (*qfn1(fn))(fn, v_10593);
    env = stack[-5];
    v_10593 = ncons(v_10593);
    env = stack[-5];
    stack[-1] = v_10593;
    stack[-2] = v_10593;
v_10474:
    v_10593 = stack[-3];
    v_10593 = qcdr(v_10593);
    stack[-3] = v_10593;
    v_10593 = stack[-3];
    if (v_10593 == nil) goto v_10493;
    else goto v_10494;
v_10493:
    v_10593 = stack[-2];
    goto v_10473;
v_10494:
    goto v_10502;
v_10498:
    stack[0] = stack[-1];
    goto v_10499;
v_10500:
    v_10593 = stack[-3];
    v_10593 = qcar(v_10593);
    fn = elt(env, 14); // reval
    v_10593 = (*qfn1(fn))(fn, v_10593);
    env = stack[-5];
    v_10593 = ncons(v_10593);
    env = stack[-5];
    goto v_10501;
v_10502:
    goto v_10498;
v_10499:
    goto v_10500;
v_10501:
    v_10593 = Lrplacd(nil, stack[0], v_10593);
    env = stack[-5];
    v_10593 = stack[-1];
    v_10593 = qcdr(v_10593);
    stack[-1] = v_10593;
    goto v_10474;
v_10473:
    goto v_10465;
v_10466:
    goto v_10462;
v_10463:
    goto v_10464;
v_10465:
    fn = elt(env, 13); // apply
    v_10593 = (*qfn2(fn))(fn, stack[-4], v_10593);
    env = stack[-5];
    stack[0] = v_10593;
    goto v_10310;
v_10456:
    v_10593 = stack[0];
    v_10593 = qcar(v_10593);
    if (!symbolp(v_10593)) v_10593 = nil;
    else { v_10593 = qfastgets(v_10593);
           if (v_10593 != nil) { v_10593 = elt(v_10593, 44); // prepfn2
#ifdef RECORD_GET
             if (v_10593 != SPID_NOPROP)
                record_get(elt(fastget_names, 44), 1);
             else record_get(elt(fastget_names, 44), 0),
                v_10593 = nil; }
           else record_get(elt(fastget_names, 44), 0); }
#else
             if (v_10593 == SPID_NOPROP) v_10593 = nil; }}
#endif
    v_10594 = v_10593;
    if (v_10593 == nil) goto v_10515;
    goto v_10525;
v_10521:
    stack[-1] = v_10594;
    goto v_10522;
v_10523:
    v_10593 = stack[0];
    v_10593 = ncons(v_10593);
    env = stack[-5];
    goto v_10524;
v_10525:
    goto v_10521;
v_10522:
    goto v_10523;
v_10524:
    fn = elt(env, 13); // apply
    v_10593 = (*qfn2(fn))(fn, stack[-1], v_10593);
    env = stack[-5];
    stack[0] = v_10593;
    goto v_10310;
v_10515:
    v_10593 = stack[0];
    v_10593 = qcar(v_10593);
    fn = elt(env, 15); // ioto_form2str
    v_10593 = (*qfn1(fn))(fn, v_10593);
    env = stack[-5];
    stack[-1] = v_10593;
    v_10593 = stack[0];
    v_10593 = qcar(v_10593);
    if (!symbolp(v_10593)) v_10593 = nil;
    else { v_10593 = qfastgets(v_10593);
           if (v_10593 != nil) { v_10593 = elt(v_10593, 37); // prtch
#ifdef RECORD_GET
             if (v_10593 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v_10593 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v_10593 == SPID_NOPROP) v_10593 = nil; }}
#endif
    v_10594 = v_10593;
    if (v_10593 == nil) goto v_10535;
    goto v_10549;
v_10541:
    v_10593 = v_10594;
    fn = elt(env, 15); // ioto_form2str
    v_10596 = (*qfn1(fn))(fn, v_10593);
    env = stack[-5];
    goto v_10542;
v_10543:
    v_10595 = elt(env, 6); // " ("
    goto v_10544;
v_10545:
    v_10594 = stack[-1];
    goto v_10546;
v_10547:
    v_10593 = elt(env, 7); // ")"
    goto v_10548;
v_10549:
    goto v_10541;
v_10542:
    goto v_10543;
v_10544:
    goto v_10545;
v_10546:
    goto v_10547;
v_10548:
    v_10593 = list4(v_10596, v_10595, v_10594, v_10593);
    env = stack[-5];
    fn = elt(env, 16); // lto_sconcat
    v_10593 = (*qfn1(fn))(fn, v_10593);
    env = stack[-5];
    stack[-1] = v_10593;
    goto v_10533;
v_10535:
v_10533:
    goto v_10560;
v_10556:
    v_10594 = stack[-1];
    goto v_10557;
v_10558:
    v_10593 = elt(env, 8); // "predicate"
    goto v_10559;
v_10560:
    goto v_10556;
v_10557:
    goto v_10558;
v_10559:
    fn = elt(env, 17); // redmsg
    v_10593 = (*qfn2(fn))(fn, v_10594, v_10593);
    env = stack[-5];
    goto v_10570;
v_10564:
    v_10593 = stack[0];
    v_10596 = qcar(v_10593);
    goto v_10565;
v_10566:
    goto v_10578;
v_10574:
    v_10593 = qvalue(elt(env, 1)); // rl_cid!*
    v_10594 = qcar(v_10593);
    goto v_10575;
v_10576:
    v_10593 = elt(env, 5); // simpfnname
    goto v_10577;
v_10578:
    goto v_10574;
v_10575:
    goto v_10576;
v_10577:
    v_10595 = get(v_10594, v_10593);
    env = stack[-5];
    goto v_10567;
v_10568:
    goto v_10587;
v_10583:
    v_10593 = qvalue(elt(env, 1)); // rl_cid!*
    v_10594 = qcar(v_10593);
    goto v_10584;
v_10585:
    v_10593 = elt(env, 9); // simpdefault
    goto v_10586;
v_10587:
    goto v_10583;
v_10584:
    goto v_10585;
v_10586:
    v_10593 = get(v_10594, v_10593);
    env = stack[-5];
    goto v_10569;
v_10570:
    goto v_10564;
v_10565:
    goto v_10566;
v_10567:
    goto v_10568;
v_10569:
    v_10593 = Lputprop(nil, 3, v_10596, v_10595, v_10593);
    env = stack[-5];
    v_10593 = stack[0];
    stack[0] = v_10593;
    goto v_10310;
v_10316:
    return onevalue(v_10593);
}



// Code for ev_sum

static LispObject CC_ev_sum(LispObject env,
                         LispObject v_10311, LispObject v_10312)
{
    env = qenv(env);
    LispObject v_10349, v_10350, v_10351;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10311,v_10312);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_10312;
    stack[-1] = v_10311;
// end of prologue
    v_10351 = nil;
v_10319:
    v_10349 = stack[-1];
    if (v_10349 == nil) goto v_10322;
    else goto v_10323;
v_10322:
    goto v_10318;
v_10323:
    goto v_10331;
v_10327:
    goto v_10336;
v_10332:
    v_10349 = stack[-1];
    v_10350 = qcar(v_10349);
    goto v_10333;
v_10334:
    v_10349 = stack[0];
    v_10349 = qcar(v_10349);
    goto v_10335;
v_10336:
    goto v_10332;
v_10333:
    goto v_10334;
v_10335:
    v_10349 = (LispObject)(intptr_t)((intptr_t)v_10350 + (intptr_t)v_10349 - TAG_FIXNUM);
    goto v_10328;
v_10329:
    v_10350 = v_10351;
    goto v_10330;
v_10331:
    goto v_10327;
v_10328:
    goto v_10329;
v_10330:
    v_10349 = cons(v_10349, v_10350);
    env = stack[-2];
    v_10351 = v_10349;
    v_10349 = stack[-1];
    v_10349 = qcdr(v_10349);
    stack[-1] = v_10349;
    v_10349 = stack[0];
    v_10349 = qcdr(v_10349);
    stack[0] = v_10349;
    goto v_10319;
v_10318:
    v_10349 = v_10351;
        return Lnreverse(nil, v_10349);
    return onevalue(v_10349);
}



// Code for exptpri

static LispObject CC_exptpri(LispObject env,
                         LispObject v_10311, LispObject v_10312)
{
    env = qenv(env);
    LispObject v_10727, v_10728, v_10729;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10311,v_10312);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    v_10727 = v_10312;
    stack[-5] = v_10311;
// end of prologue
    v_10728 = qvalue(elt(env, 1)); // !*utf8
    if (v_10728 == nil) goto v_10317;
    goto v_10324;
v_10320:
    v_10728 = stack[-5];
    goto v_10321;
v_10322:
    goto v_10323;
v_10324:
    goto v_10320;
v_10321:
    goto v_10322;
v_10323:
    {
        fn = elt(env, 18); // utf8_exptpri
        return (*qfn2(fn))(fn, v_10728, v_10727);
    }
v_10317:
// Binding !*list
// FLUIDBIND: reloadenv=7 litvec-offset=2 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 2, -6);
    qvalue(elt(env, 2)) = nil; // !*list
    stack[0] = nil;
    v_10728 = qvalue(elt(env, 3)); // !*nat
    if (v_10728 == nil) goto v_10343;
    else goto v_10344;
v_10343:
    v_10728 = lisp_true;
    goto v_10342;
v_10344:
    v_10728 = qvalue(elt(env, 4)); // !*fort
    goto v_10342;
    v_10728 = nil;
v_10342:
    if (v_10728 == nil) goto v_10340;
    v_10727 = elt(env, 5); // failed
    goto v_10336;
v_10340:
    goto v_10356;
v_10352:
    v_10728 = elt(env, 6); // expt
    if (!symbolp(v_10728)) v_10728 = nil;
    else { v_10728 = qfastgets(v_10728);
           if (v_10728 != nil) { v_10728 = elt(v_10728, 23); // infix
#ifdef RECORD_GET
             if (v_10728 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_10728 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_10728 == SPID_NOPROP) v_10728 = nil; }}
#endif
    stack[-2] = v_10728;
    goto v_10353;
v_10354:
    goto v_10355;
v_10356:
    goto v_10352;
v_10353:
    goto v_10354;
v_10355:
    v_10727 = (LispObject)greaterp2(v_10728, v_10727);
    v_10727 = v_10727 ? lisp_true : nil;
    env = stack[-7];
    v_10727 = (v_10727 == nil ? lisp_true : nil);
    stack[-4] = v_10727;
    v_10727 = stack[-5];
    v_10727 = qcdr(v_10727);
    v_10727 = qcar(v_10727);
    stack[-1] = v_10727;
    v_10727 = stack[-5];
    v_10727 = qcdr(v_10727);
    v_10727 = qcdr(v_10727);
    v_10727 = qcar(v_10727);
    stack[-3] = v_10727;
    v_10727 = qvalue(elt(env, 7)); // !*eraise
    if (v_10727 == nil) goto v_10371;
    v_10727 = stack[-1];
    if (!consp(v_10727)) goto v_10378;
    v_10727 = stack[-1];
    v_10727 = qcar(v_10727);
    if (!symbolp(v_10727)) v_10727 = nil;
    else { v_10727 = qfastgets(v_10727);
           if (v_10727 != nil) { v_10727 = elt(v_10727, 57); // prifn
#ifdef RECORD_GET
             if (v_10727 != SPID_NOPROP)
                record_get(elt(fastget_names, 57), 1);
             else record_get(elt(fastget_names, 57), 0),
                v_10727 = nil; }
           else record_get(elt(fastget_names, 57), 0); }
#else
             if (v_10727 == SPID_NOPROP) v_10727 = nil; }}
#endif
    stack[0] = v_10727;
    if (v_10727 == nil) goto v_10382;
    else goto v_10383;
v_10382:
    v_10727 = nil;
    goto v_10381;
v_10383:
    goto v_10394;
v_10390:
    goto v_10400;
v_10396:
    v_10728 = stack[0];
    goto v_10397;
v_10398:
    v_10727 = elt(env, 6); // expt
    goto v_10399;
v_10400:
    goto v_10396;
v_10397:
    goto v_10398;
v_10399:
    v_10728 = get(v_10728, v_10727);
    env = stack[-7];
    goto v_10391;
v_10392:
    v_10727 = elt(env, 8); // inbrackets
    goto v_10393;
v_10394:
    goto v_10390;
v_10391:
    goto v_10392;
v_10393:
    v_10727 = (v_10728 == v_10727 ? lisp_true : nil);
    goto v_10381;
    v_10727 = nil;
v_10381:
    goto v_10376;
v_10378:
    v_10727 = nil;
    goto v_10376;
    v_10727 = nil;
v_10376:
    if (v_10727 == nil) goto v_10371;
    goto v_10415;
v_10409:
    v_10729 = stack[-1];
    goto v_10410;
v_10411:
    v_10728 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10412;
v_10413:
    v_10727 = elt(env, 8); // inbrackets
    goto v_10414;
v_10415:
    goto v_10409;
v_10410:
    goto v_10411;
v_10412:
    goto v_10413;
v_10414:
    fn = elt(env, 19); // layout!-formula
    v_10727 = (*qfnn(fn))(fn, 3, v_10729, v_10728, v_10727);
    env = stack[-7];
    stack[-1] = v_10727;
    goto v_10369;
v_10371:
    goto v_10429;
v_10425:
    v_10728 = stack[0];
    goto v_10426;
v_10427:
    v_10727 = elt(env, 9); // indexprin
    goto v_10428;
v_10429:
    goto v_10425;
v_10426:
    goto v_10427;
v_10428:
    if (v_10728 == v_10727) goto v_10423;
    else goto v_10424;
v_10423:
    goto v_10436;
v_10432:
    goto v_10442;
v_10438:
    v_10728 = stack[-1];
    goto v_10439;
v_10440:
    v_10727 = stack[-3];
    goto v_10441;
v_10442:
    goto v_10438;
v_10439:
    goto v_10440;
v_10441:
    fn = elt(env, 20); // indexpower
    v_10728 = (*qfn2(fn))(fn, v_10728, v_10727);
    env = stack[-7];
    goto v_10433;
v_10434:
    v_10727 = elt(env, 5); // failed
    goto v_10435;
v_10436:
    goto v_10432;
v_10433:
    goto v_10434;
v_10435:
    v_10727 = (v_10728 == v_10727 ? lisp_true : nil);
    v_10727 = (v_10727 == nil ? lisp_true : nil);
    goto v_10422;
v_10424:
    v_10727 = nil;
    goto v_10422;
    v_10727 = nil;
v_10422:
    if (v_10727 == nil) goto v_10420;
    v_10727 = nil;
    goto v_10336;
v_10420:
    goto v_10461;
v_10455:
    v_10729 = stack[-1];
    goto v_10456;
v_10457:
    v_10728 = stack[-2];
    goto v_10458;
v_10459:
    v_10727 = nil;
    goto v_10460;
v_10461:
    goto v_10455;
v_10456:
    goto v_10457;
v_10458:
    goto v_10459;
v_10460:
    fn = elt(env, 19); // layout!-formula
    v_10727 = (*qfnn(fn))(fn, 3, v_10729, v_10728, v_10727);
    env = stack[-7];
    stack[-1] = v_10727;
    goto v_10369;
v_10369:
    v_10727 = stack[-1];
    if (v_10727 == nil) goto v_10467;
    else goto v_10468;
v_10467:
    v_10727 = elt(env, 5); // failed
    goto v_10336;
v_10468:
// Binding !*ratpri
// FLUIDBIND: reloadenv=7 litvec-offset=10 saveloc=5
{   bind_fluid_stack bind_fluid_var(-7, 10, -5);
    qvalue(elt(env, 10)) = nil; // !*ratpri
    goto v_10487;
v_10483:
    v_10728 = stack[-3];
    goto v_10484;
v_10485:
    v_10727 = elt(env, 11); // quotient
    goto v_10486;
v_10487:
    goto v_10483;
v_10484:
    goto v_10485;
v_10486:
    if (!consp(v_10728)) goto v_10481;
    v_10728 = qcar(v_10728);
    if (v_10728 == v_10727) goto v_10480;
    else goto v_10481;
v_10480:
    goto v_10495;
v_10491:
    v_10727 = stack[-3];
    v_10727 = qcdr(v_10727);
    v_10728 = qcar(v_10727);
    goto v_10492;
v_10493:
    v_10727 = elt(env, 12); // minus
    goto v_10494;
v_10495:
    goto v_10491;
v_10492:
    goto v_10493;
v_10494:
    v_10727 = Leqcar(nil, v_10728, v_10727);
    env = stack[-7];
    goto v_10479;
v_10481:
    v_10727 = nil;
    goto v_10479;
    v_10727 = nil;
v_10479:
    if (v_10727 == nil) goto v_10477;
    goto v_10508;
v_10504:
    stack[0] = elt(env, 12); // minus
    goto v_10505;
v_10506:
    goto v_10517;
v_10511:
    v_10727 = stack[-3];
    v_10729 = qcar(v_10727);
    goto v_10512;
v_10513:
    v_10727 = stack[-3];
    v_10727 = qcdr(v_10727);
    v_10727 = qcar(v_10727);
    v_10727 = qcdr(v_10727);
    v_10728 = qcar(v_10727);
    goto v_10514;
v_10515:
    v_10727 = stack[-3];
    v_10727 = qcdr(v_10727);
    v_10727 = qcdr(v_10727);
    v_10727 = qcar(v_10727);
    goto v_10516;
v_10517:
    goto v_10511;
v_10512:
    goto v_10513;
v_10514:
    goto v_10515;
v_10516:
    v_10727 = list3(v_10729, v_10728, v_10727);
    env = stack[-7];
    goto v_10507;
v_10508:
    goto v_10504;
v_10505:
    goto v_10506;
v_10507:
    v_10727 = list2(stack[0], v_10727);
    env = stack[-7];
    stack[-3] = v_10727;
    goto v_10475;
v_10477:
    v_10727 = stack[-3];
    fn = elt(env, 21); // negnumberchk
    v_10727 = (*qfn1(fn))(fn, v_10727);
    env = stack[-7];
    stack[-3] = v_10727;
    goto v_10475;
v_10475:
    goto v_10540;
v_10534:
    v_10729 = stack[-3];
    goto v_10535;
v_10536:
    v_10727 = qvalue(elt(env, 7)); // !*eraise
    if (v_10727 == nil) goto v_10545;
    v_10727 = (LispObject)0+TAG_FIXNUM; // 0
    v_10728 = v_10727;
    goto v_10543;
v_10545:
    v_10727 = stack[-2];
    v_10728 = v_10727;
    goto v_10543;
    v_10728 = nil;
v_10543:
    goto v_10537;
v_10538:
    v_10727 = nil;
    goto v_10539;
v_10540:
    goto v_10534;
v_10535:
    goto v_10536;
v_10537:
    goto v_10538;
v_10539:
    fn = elt(env, 19); // layout!-formula
    v_10727 = (*qfnn(fn))(fn, 3, v_10729, v_10728, v_10727);
    env = stack[-7];
    stack[-3] = v_10727;
    ;}  // end of a binding scope
    v_10727 = stack[-3];
    if (v_10727 == nil) goto v_10554;
    else goto v_10555;
v_10554:
    v_10727 = elt(env, 5); // failed
    goto v_10336;
v_10555:
    goto v_10563;
v_10559:
    v_10727 = stack[-1];
    v_10727 = qcar(v_10727);
    v_10728 = qcdr(v_10727);
    goto v_10560;
v_10561:
    v_10727 = stack[-3];
    v_10727 = qcar(v_10727);
    v_10727 = qcdr(v_10727);
    goto v_10562;
v_10563:
    goto v_10559;
v_10560:
    goto v_10561;
v_10562:
    v_10727 = plus2(v_10728, v_10727);
    env = stack[-7];
    stack[-5] = v_10727;
    v_10727 = stack[-4];
    if (v_10727 == nil) goto v_10573;
    goto v_10580;
v_10576:
    v_10728 = stack[-5];
    goto v_10577;
v_10578:
    v_10727 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_10579;
v_10580:
    goto v_10576;
v_10577:
    goto v_10578;
v_10579:
    v_10727 = plus2(v_10728, v_10727);
    env = stack[-7];
    stack[-5] = v_10727;
    goto v_10571;
v_10573:
v_10571:
    goto v_10592;
v_10588:
    stack[0] = stack[-5];
    goto v_10589;
v_10590:
    goto v_10599;
v_10595:
    goto v_10605;
v_10601:
    v_10727 = nil;
    v_10728 = Llinelength(nil, v_10727);
    env = stack[-7];
    goto v_10602;
v_10603:
    v_10727 = qvalue(elt(env, 13)); // spare!*
    goto v_10604;
v_10605:
    goto v_10601;
v_10602:
    goto v_10603;
v_10604:
    v_10728 = difference2(v_10728, v_10727);
    env = stack[-7];
    goto v_10596;
v_10597:
    v_10727 = qvalue(elt(env, 14)); // orig!*
    goto v_10598;
v_10599:
    goto v_10595;
v_10596:
    goto v_10597;
v_10598:
    v_10727 = difference2(v_10728, v_10727);
    env = stack[-7];
    goto v_10591;
v_10592:
    goto v_10588;
v_10589:
    goto v_10590;
v_10591:
    v_10727 = (LispObject)greaterp2(stack[0], v_10727);
    v_10727 = v_10727 ? lisp_true : nil;
    env = stack[-7];
    if (v_10727 == nil) goto v_10586;
    v_10727 = elt(env, 5); // failed
    goto v_10336;
v_10586:
    goto v_10620;
v_10616:
    stack[0] = stack[-5];
    goto v_10617;
v_10618:
    goto v_10627;
v_10623:
    goto v_10633;
v_10629:
    v_10727 = nil;
    v_10728 = Llinelength(nil, v_10727);
    env = stack[-7];
    goto v_10630;
v_10631:
    v_10727 = qvalue(elt(env, 13)); // spare!*
    goto v_10632;
v_10633:
    goto v_10629;
v_10630:
    goto v_10631;
v_10632:
    v_10728 = difference2(v_10728, v_10727);
    env = stack[-7];
    goto v_10624;
v_10625:
    v_10727 = qvalue(elt(env, 15)); // posn!*
    goto v_10626;
v_10627:
    goto v_10623;
v_10624:
    goto v_10625;
v_10626:
    v_10727 = difference2(v_10728, v_10727);
    env = stack[-7];
    goto v_10619;
v_10620:
    goto v_10616;
v_10617:
    goto v_10618;
v_10619:
    v_10727 = (LispObject)greaterp2(stack[0], v_10727);
    v_10727 = v_10727 ? lisp_true : nil;
    env = stack[-7];
    if (v_10727 == nil) goto v_10614;
    v_10727 = lisp_true;
    fn = elt(env, 22); // terpri!*
    v_10727 = (*qfn1(fn))(fn, v_10727);
    env = stack[-7];
    goto v_10612;
v_10614:
v_10612:
    v_10727 = stack[-4];
    if (v_10727 == nil) goto v_10643;
    v_10727 = elt(env, 16); // "("
    fn = elt(env, 23); // prin2!*
    v_10727 = (*qfn1(fn))(fn, v_10727);
    env = stack[-7];
    goto v_10641;
v_10643:
v_10641:
    v_10727 = stack[-1];
    fn = elt(env, 24); // putpline
    v_10727 = (*qfn1(fn))(fn, v_10727);
    env = stack[-7];
    v_10727 = qvalue(elt(env, 7)); // !*eraise
    if (v_10727 == nil) goto v_10652;
    goto v_10659;
v_10655:
    v_10728 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10656;
v_10657:
    v_10727 = stack[-3];
    v_10727 = qcdr(v_10727);
    v_10727 = qcar(v_10727);
    goto v_10658;
v_10659:
    goto v_10655;
v_10656:
    goto v_10657;
v_10658:
    v_10727 = difference2(v_10728, v_10727);
    env = stack[-7];
    stack[-5] = v_10727;
    goto v_10650;
v_10652:
    v_10727 = elt(env, 6); // expt
    fn = elt(env, 25); // oprin
    v_10727 = (*qfn1(fn))(fn, v_10727);
    env = stack[-7];
    v_10727 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_10727;
    goto v_10650;
v_10650:
    goto v_10677;
v_10671:
    goto v_10685;
v_10679:
    v_10729 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_10680;
v_10681:
    v_10728 = stack[-5];
    goto v_10682;
v_10683:
    v_10727 = stack[-3];
    v_10727 = qcar(v_10727);
    v_10727 = qcar(v_10727);
    goto v_10684;
v_10685:
    goto v_10679;
v_10680:
    goto v_10681;
v_10682:
    goto v_10683;
v_10684:
    fn = elt(env, 26); // update!-pline
    stack[-2] = (*qfnn(fn))(fn, 3, v_10729, v_10728, v_10727);
    env = stack[-7];
    goto v_10672;
v_10673:
    v_10727 = stack[-3];
    v_10727 = qcar(v_10727);
    stack[-1] = qcdr(v_10727);
    goto v_10674;
v_10675:
    goto v_10699;
v_10695:
    goto v_10705;
v_10701:
    v_10727 = stack[-3];
    v_10727 = qcdr(v_10727);
    v_10728 = qcar(v_10727);
    goto v_10702;
v_10703:
    v_10727 = stack[-5];
    goto v_10704;
v_10705:
    goto v_10701;
v_10702:
    goto v_10703;
v_10704:
    stack[0] = plus2(v_10728, v_10727);
    env = stack[-7];
    goto v_10696;
v_10697:
    goto v_10715;
v_10711:
    v_10727 = stack[-3];
    v_10727 = qcdr(v_10727);
    v_10728 = qcdr(v_10727);
    goto v_10712;
v_10713:
    v_10727 = stack[-5];
    goto v_10714;
v_10715:
    goto v_10711;
v_10712:
    goto v_10713;
v_10714:
    v_10727 = plus2(v_10728, v_10727);
    env = stack[-7];
    goto v_10698;
v_10699:
    goto v_10695;
v_10696:
    goto v_10697;
v_10698:
    v_10727 = cons(stack[0], v_10727);
    env = stack[-7];
    goto v_10676;
v_10677:
    goto v_10671;
v_10672:
    goto v_10673;
v_10674:
    goto v_10675;
v_10676:
    v_10727 = acons(stack[-2], stack[-1], v_10727);
    env = stack[-7];
    fn = elt(env, 24); // putpline
    v_10727 = (*qfn1(fn))(fn, v_10727);
    env = stack[-7];
    v_10727 = stack[-4];
    if (v_10727 == nil) goto v_10723;
    v_10727 = elt(env, 17); // ")"
    fn = elt(env, 23); // prin2!*
    v_10727 = (*qfn1(fn))(fn, v_10727);
    goto v_10721;
v_10723:
v_10721:
    v_10727 = nil;
v_10336:
    ;}  // end of a binding scope
    goto v_10315;
    v_10727 = nil;
v_10315:
    return onevalue(v_10727);
}



// Code for tobvarir

static LispObject CC_tobvarir(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10341, v_10342;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10311);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_10311;
// end of prologue
    v_10341 = stack[-1];
    if (v_10341 == nil) goto v_10318;
    goto v_10327;
v_10321:
    stack[-2] = elt(env, 1); // bvar
    goto v_10322;
v_10323:
    goto v_10334;
v_10330:
    v_10341 = stack[-1];
    v_10342 = qcar(v_10341);
    goto v_10331;
v_10332:
    v_10341 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_10333;
v_10334:
    goto v_10330;
v_10331:
    goto v_10332;
v_10333:
    stack[0] = list2(v_10342, v_10341);
    env = stack[-3];
    goto v_10324;
v_10325:
    v_10341 = stack[-1];
    v_10341 = qcdr(v_10341);
    v_10341 = CC_tobvarir(elt(env, 0), v_10341);
    goto v_10326;
v_10327:
    goto v_10321;
v_10322:
    goto v_10323;
v_10324:
    goto v_10325;
v_10326:
    {
        LispObject v_10346 = stack[-2];
        LispObject v_10347 = stack[0];
        return acons(v_10346, v_10347, v_10341);
    }
v_10318:
    v_10341 = nil;
    return onevalue(v_10341);
}



// Code for floatprop

static LispObject CC_floatprop(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10326, v_10327;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10311);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_10326 = v_10311;
// end of prologue
    v_10327 = v_10326;
    v_10327 = Lfloatp(nil, v_10327);
    env = stack[0];
    if (v_10327 == nil) goto v_10315;
    else goto v_10314;
v_10315:
    goto v_10323;
v_10319:
    goto v_10320;
v_10321:
    v_10327 = elt(env, 1); // !:rd!:
    goto v_10322;
v_10323:
    goto v_10319;
v_10320:
    goto v_10321;
v_10322:
        return Leqcar(nil, v_10326, v_10327);
v_10314:
    return onevalue(v_10327);
}



// Code for inttovec

static LispObject CC_inttovec(LispObject env,
                         LispObject v_10311, LispObject v_10312)
{
    env = qenv(env);
    LispObject v_10329, v_10330;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_10312,v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_10311,v_10312);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10330 = v_10312;
    v_10329 = v_10311;
// end of prologue
    goto v_10319;
v_10315:
    stack[0] = v_10330;
    goto v_10316;
v_10317:
    goto v_10326;
v_10322:
    goto v_10323;
v_10324:
    goto v_10325;
v_10326:
    goto v_10322;
v_10323:
    goto v_10324;
v_10325:
    fn = elt(env, 1); // inttovec!-solve
    v_10329 = (*qfn2(fn))(fn, v_10330, v_10329);
    env = stack[-1];
    goto v_10318;
v_10319:
    goto v_10315;
v_10316:
    goto v_10317;
v_10318:
    {
        LispObject v_10332 = stack[0];
        fn = elt(env, 2); // inttovec1
        return (*qfn2(fn))(fn, v_10332, v_10329);
    }
}



// Code for gpexp1p

static LispObject CC_gpexp1p(LispObject env,
                         LispObject v_10311)
{
    env = qenv(env);
    LispObject v_10334;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_10311);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_10311);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_10311;
// end of prologue
v_10310:
    v_10334 = stack[0];
    if (v_10334 == nil) goto v_10315;
    else goto v_10316;
v_10315:
    v_10334 = lisp_true;
    goto v_10314;
v_10316:
    v_10334 = stack[0];
    v_10334 = qcar(v_10334);
    fn = elt(env, 1); // gpexpp
    v_10334 = (*qfn1(fn))(fn, v_10334);
    env = stack[-1];
    if (v_10334 == nil) goto v_10323;
    else goto v_10324;
v_10323:
    v_10334 = nil;
    goto v_10322;
v_10324:
    v_10334 = stack[0];
    v_10334 = qcdr(v_10334);
    stack[0] = v_10334;
    goto v_10310;
    v_10334 = nil;
v_10322:
    goto v_10314;
    v_10334 = nil;
v_10314:
    return onevalue(v_10334);
}



setup_type const u18_setup[] =
{
    {"ibalp_initwl",            CC_ibalp_initwl,TOO_MANY_1,    WRONG_NO_1},
    {"variableom",              CC_variableom,  TOO_MANY_1,    WRONG_NO_1},
    {"onoff",                   TOO_FEW_2,      CC_onoff,      WRONG_NO_2},
    {"unchecked_getmatelem",    CC_unchecked_getmatelem,TOO_MANY_1,WRONG_NO_1},
    {"guesspftype",             CC_guesspftype, TOO_MANY_1,    WRONG_NO_1},
    {"deleteall",               TOO_FEW_2,      CC_deleteall,  WRONG_NO_2},
    {"cstimes",                 TOO_FEW_2,      CC_cstimes,    WRONG_NO_2},
    {"command",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_command},
    {"sf_member",               TOO_FEW_2,      CC_sf_member,  WRONG_NO_2},
    {"b:extadd",                TOO_FEW_2,      CC_bTextadd,   WRONG_NO_2},
    {"ra_refine1",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ra_refine1},
    {"lexer_word_starter",      CC_lexer_word_starter,TOO_MANY_1,WRONG_NO_1},
    {"sfto_kexp",               TOO_FEW_2,      CC_sfto_kexp,  WRONG_NO_2},
    {"gcref_mkedges-tgf",       TOO_FEW_2,      CC_gcref_mkedgesKtgf,WRONG_NO_2},
    {"polynomheadreduceby",     TOO_FEW_2,      CC_polynomheadreduceby,WRONG_NO_2},
    {"wusort",                  CC_wusort,      TOO_MANY_1,    WRONG_NO_1},
    {"expnd1",                  CC_expnd1,      TOO_MANY_1,    WRONG_NO_1},
    {"talp_simplatat",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_talp_simplatat},
    {"qqe_number-of-adds-in-qterm",CC_qqe_numberKofKaddsKinKqterm,TOO_MANY_1,WRONG_NO_1},
    {"mml2om",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mml2om},
    {"add2resultbuf",           TOO_FEW_2,      CC_add2resultbuf,WRONG_NO_2},
    {"general-reduce-degree-mod-p",TOO_FEW_2,   CC_generalKreduceKdegreeKmodKp,WRONG_NO_2},
    {"simpiden",                CC_simpiden,    TOO_MANY_1,    WRONG_NO_1},
    {"ctx_filter",              TOO_FEW_2,      CC_ctx_filter, WRONG_NO_2},
    {"read_typed_name",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_read_typed_name},
    {"rl_bestgaussp",           CC_rl_bestgaussp,TOO_MANY_1,   WRONG_NO_1},
    {"replus",                  CC_replus,      TOO_MANY_1,    WRONG_NO_1},
    {"rl_subat",                TOO_FEW_2,      CC_rl_subat,   WRONG_NO_2},
    {"sf2ss",                   CC_sf2ss,       TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_unvar-unsatlist",   TOO_FEW_2,      CC_ibalp_unvarKunsatlist,WRONG_NO_2},
    {"vdpputprop",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vdpputprop},
    {"equalreplaceby",          CC_equalreplaceby,TOO_MANY_1,  WRONG_NO_1},
    {"class",                   CC_class,       TOO_MANY_1,    WRONG_NO_1},
    {"ord2",                    TOO_FEW_2,      CC_ord2,       WRONG_NO_2},
    {"moduntag",                CC_moduntag,    TOO_MANY_1,    WRONG_NO_1},
    {"rrdls",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rrdls},
    {"rl_susipost",             TOO_FEW_2,      CC_rl_susipost,WRONG_NO_2},
    {"rl_simp1",                CC_rl_simp1,    TOO_MANY_1,    WRONG_NO_1},
    {"ev_sum",                  TOO_FEW_2,      CC_ev_sum,     WRONG_NO_2},
    {"exptpri",                 TOO_FEW_2,      CC_exptpri,    WRONG_NO_2},
    {"tobvarir",                CC_tobvarir,    TOO_MANY_1,    WRONG_NO_1},
    {"floatprop",               CC_floatprop,   TOO_MANY_1,    WRONG_NO_1},
    {"inttovec",                TOO_FEW_2,      CC_inttovec,   WRONG_NO_2},
    {"gpexp1p",                 CC_gpexp1p,     TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u18", (two_args *)"169316 9825449 3823509", 0}
};

// end of generated code
