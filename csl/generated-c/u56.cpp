
// $destdir/u56.c        Machine generated C code

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



// Code for partitindexvar

static LispObject CC_partitindexvar(LispObject env,
                         LispObject v_33433)
{
    env = qenv(env);
    LispObject v_34388, v_34389, v_34390;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33433);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_33433;
// end of prologue
    stack[-8] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    v_34388 = stack[-7];
    v_34388 = qcdr(v_34388);
    stack[-4] = v_34388;
    v_34388 = stack[-4];
    if (v_34388 == nil) goto v_33455;
    else goto v_33456;
v_33455:
    v_34388 = nil;
    goto v_33449;
v_33456:
    v_34388 = stack[-4];
    v_34388 = qcar(v_34388);
    fn = elt(env, 5); // revalind
    v_34388 = (*qfn1(fn))(fn, v_34388);
    env = stack[-9];
    v_34389 = v_34388;
    v_34388 = v_34389;
    if (!consp(v_34388)) goto v_33468;
    else goto v_33469;
v_33468:
    v_34388 = v_34389;
    if (is_number(v_34388)) goto v_33473;
    else goto v_33474;
v_33473:
    v_34388 = v_34389;
    v_34388 = Lminusp(nil, v_34388);
    env = stack[-9];
    if (v_34388 == nil) goto v_33479;
    goto v_33487;
v_33483:
    stack[0] = elt(env, 1); // minus
    goto v_33484;
v_33485:
    v_34388 = v_34389;
    v_34388 = Labsval(nil, v_34388);
    env = stack[-9];
    fn = elt(env, 6); // !*num2id
    v_34388 = (*qfn1(fn))(fn, v_34388);
    env = stack[-9];
    goto v_33486;
v_33487:
    goto v_33483;
v_33484:
    goto v_33485;
v_33486:
    v_34388 = list2(stack[0], v_34388);
    env = stack[-9];
    goto v_33477;
v_33479:
    v_34388 = v_34389;
    fn = elt(env, 6); // !*num2id
    v_34388 = (*qfn1(fn))(fn, v_34388);
    env = stack[-9];
    goto v_33477;
    v_34388 = nil;
v_33477:
    goto v_33472;
v_33474:
    v_34388 = v_34389;
    goto v_33472;
    v_34388 = nil;
v_33472:
    goto v_33467;
v_33469:
    v_34388 = v_34389;
    v_34388 = qcdr(v_34388);
    v_34388 = qcar(v_34388);
    if (is_number(v_34388)) goto v_33499;
    else goto v_33500;
v_33499:
    goto v_33509;
v_33505:
    stack[0] = elt(env, 1); // minus
    goto v_33506;
v_33507:
    v_34388 = v_34389;
    v_34388 = qcdr(v_34388);
    v_34388 = qcar(v_34388);
    fn = elt(env, 6); // !*num2id
    v_34388 = (*qfn1(fn))(fn, v_34388);
    env = stack[-9];
    goto v_33508;
v_33509:
    goto v_33505;
v_33506:
    goto v_33507;
v_33508:
    v_34388 = list2(stack[0], v_34388);
    env = stack[-9];
    goto v_33467;
v_33500:
    v_34388 = v_34389;
    goto v_33467;
    v_34388 = nil;
v_33467:
    v_34388 = ncons(v_34388);
    env = stack[-9];
    stack[-2] = v_34388;
    stack[-3] = v_34388;
v_33450:
    v_34388 = stack[-4];
    v_34388 = qcdr(v_34388);
    stack[-4] = v_34388;
    v_34388 = stack[-4];
    if (v_34388 == nil) goto v_33522;
    else goto v_33523;
v_33522:
    v_34388 = stack[-3];
    goto v_33449;
v_33523:
    goto v_33531;
v_33527:
    stack[-1] = stack[-2];
    goto v_33528;
v_33529:
    v_34388 = stack[-4];
    v_34388 = qcar(v_34388);
    fn = elt(env, 5); // revalind
    v_34388 = (*qfn1(fn))(fn, v_34388);
    env = stack[-9];
    v_34389 = v_34388;
    v_34388 = v_34389;
    if (!consp(v_34388)) goto v_33542;
    else goto v_33543;
v_33542:
    v_34388 = v_34389;
    if (is_number(v_34388)) goto v_33547;
    else goto v_33548;
v_33547:
    v_34388 = v_34389;
    v_34388 = Lminusp(nil, v_34388);
    env = stack[-9];
    if (v_34388 == nil) goto v_33553;
    goto v_33561;
v_33557:
    stack[0] = elt(env, 1); // minus
    goto v_33558;
v_33559:
    v_34388 = v_34389;
    v_34388 = Labsval(nil, v_34388);
    env = stack[-9];
    fn = elt(env, 6); // !*num2id
    v_34388 = (*qfn1(fn))(fn, v_34388);
    env = stack[-9];
    goto v_33560;
v_33561:
    goto v_33557;
v_33558:
    goto v_33559;
v_33560:
    v_34388 = list2(stack[0], v_34388);
    env = stack[-9];
    goto v_33551;
v_33553:
    v_34388 = v_34389;
    fn = elt(env, 6); // !*num2id
    v_34388 = (*qfn1(fn))(fn, v_34388);
    env = stack[-9];
    goto v_33551;
    v_34388 = nil;
v_33551:
    goto v_33546;
v_33548:
    v_34388 = v_34389;
    goto v_33546;
    v_34388 = nil;
v_33546:
    goto v_33541;
v_33543:
    v_34388 = v_34389;
    v_34388 = qcdr(v_34388);
    v_34388 = qcar(v_34388);
    if (is_number(v_34388)) goto v_33573;
    else goto v_33574;
v_33573:
    goto v_33583;
v_33579:
    stack[0] = elt(env, 1); // minus
    goto v_33580;
v_33581:
    v_34388 = v_34389;
    v_34388 = qcdr(v_34388);
    v_34388 = qcar(v_34388);
    fn = elt(env, 6); // !*num2id
    v_34388 = (*qfn1(fn))(fn, v_34388);
    env = stack[-9];
    goto v_33582;
v_33583:
    goto v_33579;
v_33580:
    goto v_33581;
v_33582:
    v_34388 = list2(stack[0], v_34388);
    env = stack[-9];
    goto v_33541;
v_33574:
    v_34388 = v_34389;
    goto v_33541;
    v_34388 = nil;
v_33541:
    v_34388 = ncons(v_34388);
    env = stack[-9];
    goto v_33530;
v_33531:
    goto v_33527;
v_33528:
    goto v_33529;
v_33530:
    v_34388 = Lrplacd(nil, stack[-1], v_34388);
    env = stack[-9];
    v_34388 = stack[-2];
    v_34388 = qcdr(v_34388);
    stack[-2] = v_34388;
    goto v_33450;
v_33449:
    stack[0] = v_34388;
    v_34388 = stack[-7];
    fn = elt(env, 7); // deg!*form
    v_34388 = (*qfn1(fn))(fn, v_34388);
    env = stack[-9];
    stack[-3] = v_34388;
    v_34388 = qvalue(elt(env, 2)); // metricu!*
    if (v_34388 == nil) goto v_33598;
    else goto v_33599;
v_33598:
    goto v_33444;
v_33599:
    v_34388 = stack[0];
    stack[-2] = v_34388;
    goto v_33611;
v_33607:
    v_34388 = stack[-7];
    v_34389 = qcar(v_34388);
    goto v_33608;
v_33609:
    v_34388 = elt(env, 3); // covariant
    goto v_33610;
v_33611:
    goto v_33607;
v_33608:
    goto v_33609;
v_33610:
    v_34388 = Lflagp(nil, v_34389, v_34388);
    env = stack[-9];
    if (v_34388 == nil) goto v_33604;
    else goto v_33605;
v_33604:
v_33617:
    v_34388 = stack[-2];
    if (v_34388 == nil) goto v_33620;
    v_34388 = stack[-2];
    v_34388 = qcar(v_34388);
    if (!consp(v_34388)) goto v_33627;
    else goto v_33628;
v_33627:
    v_34388 = lisp_true;
    goto v_33626;
v_33628:
    goto v_33638;
v_33634:
    v_34388 = stack[-2];
    v_34388 = qcar(v_34388);
    v_34388 = qcdr(v_34388);
    v_34389 = qcar(v_34388);
    goto v_33635;
v_33636:
    v_34388 = qvalue(elt(env, 2)); // metricu!*
    goto v_33637;
v_33638:
    goto v_33634;
v_33635:
    goto v_33636;
v_33637:
    v_34388 = Latsoc(nil, v_34389, v_34388);
    v_34388 = (v_34388 == nil ? lisp_true : nil);
    goto v_33626;
    v_34388 = nil;
v_33626:
    if (v_34388 == nil) goto v_33620;
    goto v_33621;
v_33620:
    goto v_33616;
v_33621:
    goto v_33652;
v_33648:
    v_34388 = stack[-2];
    v_34389 = qcar(v_34388);
    goto v_33649;
v_33650:
    v_34388 = stack[-6];
    goto v_33651;
v_33652:
    goto v_33648;
v_33649:
    goto v_33650;
v_33651:
    v_34388 = cons(v_34389, v_34388);
    env = stack[-9];
    stack[-6] = v_34388;
    v_34388 = stack[-2];
    v_34388 = qcar(v_34388);
    if (!consp(v_34388)) goto v_33659;
    goto v_33667;
v_33663:
    v_34388 = stack[-2];
    v_34388 = qcar(v_34388);
    v_34388 = qcdr(v_34388);
    v_34389 = qcar(v_34388);
    goto v_33664;
v_33665:
    v_34388 = stack[-8];
    goto v_33666;
v_33667:
    goto v_33663;
v_33664:
    goto v_33665;
v_33666:
    v_34388 = cons(v_34389, v_34388);
    env = stack[-9];
    stack[-8] = v_34388;
    goto v_33657;
v_33659:
v_33657:
    v_34388 = stack[-2];
    v_34388 = qcdr(v_34388);
    stack[-2] = v_34388;
    goto v_33617;
v_33616:
    v_34388 = stack[-2];
    if (v_34388 == nil) goto v_33678;
    v_34388 = nil;
    stack[-5] = v_34388;
    v_34388 = stack[-6];
    v_34388 = Lreverse(nil, v_34388);
    env = stack[-9];
    stack[-6] = v_34388;
    v_34388 = stack[-2];
    v_34388 = qcar(v_34388);
    v_34388 = qcdr(v_34388);
    v_34388 = qcar(v_34388);
    fn = elt(env, 8); // getlower
    v_34388 = (*qfn1(fn))(fn, v_34388);
    env = stack[-9];
    stack[-4] = v_34388;
v_33686:
    v_34388 = stack[-4];
    if (v_34388 == nil) goto v_33694;
    else goto v_33695;
v_33694:
    goto v_33685;
v_33695:
    v_34388 = stack[-4];
    v_34388 = qcar(v_34388);
    stack[-3] = v_34388;
    goto v_33706;
v_33702:
    goto v_33712;
v_33708:
    goto v_33719;
v_33715:
    v_34388 = stack[-7];
    stack[-1] = qcar(v_34388);
    goto v_33716;
v_33717:
    goto v_33727;
v_33723:
    stack[0] = stack[-6];
    goto v_33724;
v_33725:
    goto v_33734;
v_33730:
    v_34388 = stack[-3];
    v_34389 = qcar(v_34388);
    goto v_33731;
v_33732:
    v_34388 = stack[-2];
    v_34388 = qcdr(v_34388);
    goto v_33733;
v_33734:
    goto v_33730;
v_33731:
    goto v_33732;
v_33733:
    v_34388 = cons(v_34389, v_34388);
    env = stack[-9];
    goto v_33726;
v_33727:
    goto v_33723;
v_33724:
    goto v_33725;
v_33726:
    v_34388 = Lappend(nil, stack[0], v_34388);
    env = stack[-9];
    goto v_33718;
v_33719:
    goto v_33715;
v_33716:
    goto v_33717;
v_33718:
    v_34388 = cons(stack[-1], v_34388);
    env = stack[-9];
    stack[0] = CC_partitindexvar(elt(env, 0), v_34388);
    env = stack[-9];
    goto v_33709;
v_33710:
    v_34388 = stack[-3];
    v_34388 = qcdr(v_34388);
    fn = elt(env, 9); // simp
    v_34388 = (*qfn1(fn))(fn, v_34388);
    env = stack[-9];
    goto v_33711;
v_33712:
    goto v_33708;
v_33709:
    goto v_33710;
v_33711:
    fn = elt(env, 10); // multpfsq
    v_34389 = (*qfn2(fn))(fn, stack[0], v_34388);
    env = stack[-9];
    goto v_33703;
v_33704:
    v_34388 = stack[-5];
    goto v_33705;
v_33706:
    goto v_33702;
v_33703:
    goto v_33704;
v_33705:
    fn = elt(env, 11); // addpf
    v_34388 = (*qfn2(fn))(fn, v_34389, v_34388);
    env = stack[-9];
    stack[-5] = v_34388;
    v_34388 = stack[-4];
    v_34388 = qcdr(v_34388);
    stack[-4] = v_34388;
    goto v_33686;
v_33685:
    v_34388 = stack[-5];
    goto v_33443;
v_33678:
    goto v_33603;
v_33605:
v_33750:
    v_34388 = stack[-2];
    if (v_34388 == nil) goto v_33753;
    v_34388 = stack[-2];
    v_34388 = qcar(v_34388);
    if (!consp(v_34388)) goto v_33761;
    v_34388 = lisp_true;
    goto v_33759;
v_33761:
    goto v_33771;
v_33767:
    v_34388 = stack[-2];
    v_34389 = qcar(v_34388);
    goto v_33768;
v_33769:
    v_34388 = qvalue(elt(env, 2)); // metricu!*
    goto v_33770;
v_33771:
    goto v_33767;
v_33768:
    goto v_33769;
v_33770:
    v_34388 = Latsoc(nil, v_34389, v_34388);
    v_34388 = (v_34388 == nil ? lisp_true : nil);
    goto v_33759;
    v_34388 = nil;
v_33759:
    if (v_34388 == nil) goto v_33753;
    goto v_33754;
v_33753:
    goto v_33749;
v_33754:
    goto v_33783;
v_33779:
    v_34388 = stack[-2];
    v_34389 = qcar(v_34388);
    goto v_33780;
v_33781:
    v_34388 = stack[-6];
    goto v_33782;
v_33783:
    goto v_33779;
v_33780:
    goto v_33781;
v_33782:
    v_34388 = cons(v_34389, v_34388);
    env = stack[-9];
    stack[-6] = v_34388;
    v_34388 = stack[-2];
    v_34388 = qcar(v_34388);
    if (!consp(v_34388)) goto v_33789;
    else goto v_33790;
v_33789:
    goto v_33798;
v_33794:
    v_34388 = stack[-2];
    v_34389 = qcar(v_34388);
    goto v_33795;
v_33796:
    v_34388 = stack[-8];
    goto v_33797;
v_33798:
    goto v_33794;
v_33795:
    goto v_33796;
v_33797:
    v_34388 = cons(v_34389, v_34388);
    env = stack[-9];
    stack[-8] = v_34388;
    goto v_33788;
v_33790:
v_33788:
    v_34388 = stack[-2];
    v_34388 = qcdr(v_34388);
    stack[-2] = v_34388;
    goto v_33750;
v_33749:
    v_34388 = stack[-2];
    if (v_34388 == nil) goto v_33807;
    v_34388 = nil;
    stack[-5] = v_34388;
    v_34388 = stack[-6];
    v_34388 = Lreverse(nil, v_34388);
    env = stack[-9];
    stack[-6] = v_34388;
    v_34388 = stack[-2];
    v_34388 = qcar(v_34388);
    fn = elt(env, 12); // getupper
    v_34388 = (*qfn1(fn))(fn, v_34388);
    env = stack[-9];
    stack[-4] = v_34388;
v_33815:
    v_34388 = stack[-4];
    if (v_34388 == nil) goto v_33821;
    else goto v_33822;
v_33821:
    goto v_33814;
v_33822:
    v_34388 = stack[-4];
    v_34388 = qcar(v_34388);
    stack[-3] = v_34388;
    goto v_33833;
v_33829:
    goto v_33839;
v_33835:
    goto v_33846;
v_33842:
    v_34388 = stack[-7];
    stack[-1] = qcar(v_34388);
    goto v_33843;
v_33844:
    goto v_33854;
v_33850:
    stack[0] = stack[-6];
    goto v_33851;
v_33852:
    goto v_33861;
v_33857:
    goto v_33867;
v_33863:
    v_34389 = elt(env, 1); // minus
    goto v_33864;
v_33865:
    v_34388 = stack[-3];
    v_34388 = qcar(v_34388);
    goto v_33866;
v_33867:
    goto v_33863;
v_33864:
    goto v_33865;
v_33866:
    v_34389 = list2(v_34389, v_34388);
    env = stack[-9];
    goto v_33858;
v_33859:
    v_34388 = stack[-2];
    v_34388 = qcdr(v_34388);
    goto v_33860;
v_33861:
    goto v_33857;
v_33858:
    goto v_33859;
v_33860:
    v_34388 = cons(v_34389, v_34388);
    env = stack[-9];
    goto v_33853;
v_33854:
    goto v_33850;
v_33851:
    goto v_33852;
v_33853:
    v_34388 = Lappend(nil, stack[0], v_34388);
    env = stack[-9];
    goto v_33845;
v_33846:
    goto v_33842;
v_33843:
    goto v_33844;
v_33845:
    v_34388 = cons(stack[-1], v_34388);
    env = stack[-9];
    stack[0] = CC_partitindexvar(elt(env, 0), v_34388);
    env = stack[-9];
    goto v_33836;
v_33837:
    v_34388 = stack[-3];
    v_34388 = qcdr(v_34388);
    fn = elt(env, 9); // simp
    v_34388 = (*qfn1(fn))(fn, v_34388);
    env = stack[-9];
    goto v_33838;
v_33839:
    goto v_33835;
v_33836:
    goto v_33837;
v_33838:
    fn = elt(env, 10); // multpfsq
    v_34389 = (*qfn2(fn))(fn, stack[0], v_34388);
    env = stack[-9];
    goto v_33830;
v_33831:
    v_34388 = stack[-5];
    goto v_33832;
v_33833:
    goto v_33829;
v_33830:
    goto v_33831;
v_33832:
    fn = elt(env, 11); // addpf
    v_34388 = (*qfn2(fn))(fn, v_34389, v_34388);
    env = stack[-9];
    stack[-5] = v_34388;
    v_34388 = stack[-4];
    v_34388 = qcdr(v_34388);
    stack[-4] = v_34388;
    goto v_33815;
v_33814:
    v_34388 = stack[-5];
    goto v_33443;
v_33807:
    goto v_33603;
v_33603:
v_33444:
    v_34388 = stack[0];
    fn = elt(env, 13); // coposp
    v_34388 = (*qfn1(fn))(fn, v_34388);
    env = stack[-9];
    if (v_34388 == nil) goto v_33886;
    else goto v_33887;
v_33886:
    v_34388 = lisp_true;
    goto v_33885;
v_33887:
    goto v_33898;
v_33894:
    v_34388 = stack[-7];
    v_34389 = qcar(v_34388);
    goto v_33895;
v_33896:
    v_34388 = elt(env, 4); // indxsymmetries
    goto v_33897;
v_33898:
    goto v_33894;
v_33895:
    goto v_33896;
v_33897:
    v_34388 = get(v_34389, v_34388);
    env = stack[-9];
    v_34388 = (v_34388 == nil ? lisp_true : nil);
    goto v_33885;
    v_34388 = nil;
v_33885:
    if (v_34388 == nil) goto v_33883;
    v_34388 = stack[-3];
    if (v_34388 == nil) goto v_33906;
    goto v_33914;
v_33910:
    v_34388 = stack[-7];
    v_34389 = qcar(v_34388);
    goto v_33911;
v_33912:
    v_34388 = stack[0];
    goto v_33913;
v_33914:
    goto v_33910;
v_33911:
    goto v_33912;
v_33913:
    v_34388 = cons(v_34389, v_34388);
    env = stack[-9];
    {
        fn = elt(env, 14); // mkupf
        return (*qfn1(fn))(fn, v_34388);
    }
v_33906:
    goto v_33926;
v_33922:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33923;
v_33924:
    goto v_33933;
v_33929:
    goto v_33939;
v_33935:
    v_34388 = stack[-7];
    v_34389 = qcar(v_34388);
    goto v_33936;
v_33937:
    v_34388 = stack[0];
    goto v_33938;
v_33939:
    goto v_33935;
v_33936:
    goto v_33937;
v_33938:
    v_34389 = cons(v_34389, v_34388);
    env = stack[-9];
    goto v_33930;
v_33931:
    v_34388 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33932;
v_33933:
    goto v_33929;
v_33930:
    goto v_33931;
v_33932:
    fn = elt(env, 15); // mksq
    v_34388 = (*qfn2(fn))(fn, v_34389, v_34388);
    env = stack[-9];
    goto v_33925;
v_33926:
    goto v_33922;
v_33923:
    goto v_33924;
v_33925:
    v_34388 = cons(stack[-1], v_34388);
    return ncons(v_34388);
    v_34388 = nil;
    goto v_33443;
v_33883:
    v_34388 = stack[0];
    stack[-4] = v_34388;
    v_34388 = stack[-4];
    if (v_34388 == nil) goto v_33953;
    else goto v_33954;
v_33953:
    v_34388 = nil;
    goto v_33948;
v_33954:
    v_34388 = stack[-4];
    v_34388 = qcar(v_34388);
    v_34389 = v_34388;
    v_34388 = v_34389;
    if (!consp(v_34388)) goto v_33963;
    else goto v_33964;
v_33963:
    v_34388 = v_34389;
    goto v_33962;
v_33964:
    v_34388 = v_34389;
    v_34388 = qcdr(v_34388);
    v_34388 = qcar(v_34388);
    goto v_33962;
    v_34388 = nil;
v_33962:
    v_34388 = ncons(v_34388);
    env = stack[-9];
    stack[-1] = v_34388;
    stack[-2] = v_34388;
v_33949:
    v_34388 = stack[-4];
    v_34388 = qcdr(v_34388);
    stack[-4] = v_34388;
    v_34388 = stack[-4];
    if (v_34388 == nil) goto v_33976;
    else goto v_33977;
v_33976:
    v_34388 = stack[-2];
    goto v_33948;
v_33977:
    goto v_33985;
v_33981:
    stack[0] = stack[-1];
    goto v_33982;
v_33983:
    v_34388 = stack[-4];
    v_34388 = qcar(v_34388);
    v_34389 = v_34388;
    v_34388 = v_34389;
    if (!consp(v_34388)) goto v_33993;
    else goto v_33994;
v_33993:
    v_34388 = v_34389;
    goto v_33992;
v_33994:
    v_34388 = v_34389;
    v_34388 = qcdr(v_34388);
    v_34388 = qcar(v_34388);
    goto v_33992;
    v_34388 = nil;
v_33992:
    v_34388 = ncons(v_34388);
    env = stack[-9];
    goto v_33984;
v_33985:
    goto v_33981;
v_33982:
    goto v_33983;
v_33984:
    v_34388 = Lrplacd(nil, stack[0], v_34388);
    env = stack[-9];
    v_34388 = stack[-1];
    v_34388 = qcdr(v_34388);
    stack[-1] = v_34388;
    goto v_33949;
v_33948:
    stack[0] = v_34388;
    goto v_34010;
v_34006:
    v_34388 = stack[-7];
    v_34389 = qcar(v_34388);
    goto v_34007;
v_34008:
    v_34388 = stack[0];
    goto v_34009;
v_34010:
    goto v_34006;
v_34007:
    goto v_34008;
v_34009:
    v_34388 = cons(v_34389, v_34388);
    env = stack[-9];
    fn = elt(env, 16); // indexsymmetrize
    v_34388 = (*qfn1(fn))(fn, v_34388);
    env = stack[-9];
    stack[0] = v_34388;
    v_34388 = stack[0];
    if (v_34388 == nil) goto v_34016;
    else goto v_34017;
v_34016:
    v_34388 = nil;
    goto v_33443;
v_34017:
    goto v_34028;
v_34024:
    v_34388 = stack[0];
    v_34389 = qcar(v_34388);
    goto v_34025;
v_34026:
    v_34388 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_34027;
v_34028:
    goto v_34024;
v_34025:
    goto v_34026;
v_34027:
    if (v_34389 == v_34388) goto v_34022;
    else goto v_34023;
v_34022:
    v_34388 = lisp_true;
    stack[-5] = v_34388;
    goto v_34021;
v_34023:
v_34021:
    v_34388 = stack[0];
    v_34388 = qcdr(v_34388);
    v_34388 = qcdr(v_34388);
    stack[0] = v_34388;
    goto v_34045;
v_34041:
    v_34388 = stack[-7];
    v_34389 = qcar(v_34388);
    goto v_34042;
v_34043:
    v_34388 = elt(env, 3); // covariant
    goto v_34044;
v_34045:
    goto v_34041;
v_34042:
    goto v_34043;
v_34044:
    v_34388 = Lflagp(nil, v_34389, v_34388);
    env = stack[-9];
    if (v_34388 == nil) goto v_34039;
    v_34388 = stack[0];
    stack[-4] = v_34388;
    v_34388 = stack[-4];
    if (v_34388 == nil) goto v_34058;
    else goto v_34059;
v_34058:
    v_34388 = nil;
    goto v_34053;
v_34059:
    v_34388 = stack[-4];
    v_34388 = qcar(v_34388);
    v_34390 = v_34388;
    goto v_34074;
v_34070:
    v_34389 = v_34390;
    goto v_34071;
v_34072:
    v_34388 = stack[-8];
    goto v_34073;
v_34074:
    goto v_34070;
v_34071:
    goto v_34072;
v_34073:
    v_34388 = Lmemq(nil, v_34389, v_34388);
    if (v_34388 == nil) goto v_34069;
    v_34388 = v_34390;
    goto v_34067;
v_34069:
    goto v_34086;
v_34082:
    v_34388 = elt(env, 1); // minus
    goto v_34083;
v_34084:
    v_34389 = v_34390;
    goto v_34085;
v_34086:
    goto v_34082;
v_34083:
    goto v_34084;
v_34085:
    v_34388 = list2(v_34388, v_34389);
    env = stack[-9];
    goto v_34067;
    v_34388 = nil;
v_34067:
    v_34388 = ncons(v_34388);
    env = stack[-9];
    stack[-1] = v_34388;
    stack[-2] = v_34388;
v_34054:
    v_34388 = stack[-4];
    v_34388 = qcdr(v_34388);
    stack[-4] = v_34388;
    v_34388 = stack[-4];
    if (v_34388 == nil) goto v_34093;
    else goto v_34094;
v_34093:
    v_34388 = stack[-2];
    goto v_34053;
v_34094:
    goto v_34102;
v_34098:
    stack[0] = stack[-1];
    goto v_34099;
v_34100:
    v_34388 = stack[-4];
    v_34388 = qcar(v_34388);
    v_34390 = v_34388;
    goto v_34116;
v_34112:
    v_34389 = v_34390;
    goto v_34113;
v_34114:
    v_34388 = stack[-8];
    goto v_34115;
v_34116:
    goto v_34112;
v_34113:
    goto v_34114;
v_34115:
    v_34388 = Lmemq(nil, v_34389, v_34388);
    if (v_34388 == nil) goto v_34111;
    v_34388 = v_34390;
    goto v_34109;
v_34111:
    goto v_34128;
v_34124:
    v_34388 = elt(env, 1); // minus
    goto v_34125;
v_34126:
    v_34389 = v_34390;
    goto v_34127;
v_34128:
    goto v_34124;
v_34125:
    goto v_34126;
v_34127:
    v_34388 = list2(v_34388, v_34389);
    env = stack[-9];
    goto v_34109;
    v_34388 = nil;
v_34109:
    v_34388 = ncons(v_34388);
    env = stack[-9];
    goto v_34101;
v_34102:
    goto v_34098;
v_34099:
    goto v_34100;
v_34101:
    v_34388 = Lrplacd(nil, stack[0], v_34388);
    env = stack[-9];
    v_34388 = stack[-1];
    v_34388 = qcdr(v_34388);
    stack[-1] = v_34388;
    goto v_34054;
v_34053:
    stack[0] = v_34388;
    goto v_34037;
v_34039:
    v_34388 = qvalue(elt(env, 2)); // metricu!*
    if (v_34388 == nil) goto v_34137;
    else goto v_34138;
v_34137:
    v_34388 = stack[-7];
    v_34388 = qcdr(v_34388);
    v_34388 = qcar(v_34388);
    v_34388 = (consp(v_34388) ? nil : lisp_true);
    v_34388 = (v_34388 == nil ? lisp_true : nil);
    goto v_34136;
v_34138:
    v_34388 = nil;
    goto v_34136;
    v_34388 = nil;
v_34136:
    if (v_34388 == nil) goto v_34134;
    v_34388 = stack[0];
    stack[-4] = v_34388;
    v_34388 = stack[-4];
    if (v_34388 == nil) goto v_34157;
    else goto v_34158;
v_34157:
    v_34388 = nil;
    goto v_34152;
v_34158:
    v_34388 = stack[-4];
    v_34388 = qcar(v_34388);
    goto v_34170;
v_34166:
    v_34389 = elt(env, 1); // minus
    goto v_34167;
v_34168:
    goto v_34169;
v_34170:
    goto v_34166;
v_34167:
    goto v_34168;
v_34169:
    v_34388 = list2(v_34389, v_34388);
    env = stack[-9];
    v_34388 = ncons(v_34388);
    env = stack[-9];
    stack[-1] = v_34388;
    stack[-2] = v_34388;
v_34153:
    v_34388 = stack[-4];
    v_34388 = qcdr(v_34388);
    stack[-4] = v_34388;
    v_34388 = stack[-4];
    if (v_34388 == nil) goto v_34177;
    else goto v_34178;
v_34177:
    v_34388 = stack[-2];
    goto v_34152;
v_34178:
    goto v_34186;
v_34182:
    stack[0] = stack[-1];
    goto v_34183;
v_34184:
    v_34388 = stack[-4];
    v_34388 = qcar(v_34388);
    goto v_34197;
v_34193:
    v_34389 = elt(env, 1); // minus
    goto v_34194;
v_34195:
    goto v_34196;
v_34197:
    goto v_34193;
v_34194:
    goto v_34195;
v_34196:
    v_34388 = list2(v_34389, v_34388);
    env = stack[-9];
    v_34388 = ncons(v_34388);
    env = stack[-9];
    goto v_34185;
v_34186:
    goto v_34182;
v_34183:
    goto v_34184;
v_34185:
    v_34388 = Lrplacd(nil, stack[0], v_34388);
    env = stack[-9];
    v_34388 = stack[-1];
    v_34388 = qcdr(v_34388);
    stack[-1] = v_34388;
    goto v_34153;
v_34152:
    stack[0] = v_34388;
    goto v_34037;
v_34134:
    v_34388 = stack[0];
    stack[-4] = v_34388;
    v_34388 = stack[-4];
    if (v_34388 == nil) goto v_34213;
    else goto v_34214;
v_34213:
    v_34388 = nil;
    goto v_34208;
v_34214:
    v_34388 = stack[-4];
    v_34388 = qcar(v_34388);
    v_34390 = v_34388;
    goto v_34229;
v_34225:
    v_34389 = v_34390;
    goto v_34226;
v_34227:
    v_34388 = stack[-8];
    goto v_34228;
v_34229:
    goto v_34225;
v_34226:
    goto v_34227;
v_34228:
    v_34388 = Lmemq(nil, v_34389, v_34388);
    if (v_34388 == nil) goto v_34224;
    goto v_34238;
v_34234:
    v_34388 = elt(env, 1); // minus
    goto v_34235;
v_34236:
    v_34389 = v_34390;
    goto v_34237;
v_34238:
    goto v_34234;
v_34235:
    goto v_34236;
v_34237:
    v_34388 = list2(v_34388, v_34389);
    env = stack[-9];
    goto v_34222;
v_34224:
    v_34388 = v_34390;
    goto v_34222;
    v_34388 = nil;
v_34222:
    v_34388 = ncons(v_34388);
    env = stack[-9];
    stack[-1] = v_34388;
    stack[-2] = v_34388;
v_34209:
    v_34388 = stack[-4];
    v_34388 = qcdr(v_34388);
    stack[-4] = v_34388;
    v_34388 = stack[-4];
    if (v_34388 == nil) goto v_34248;
    else goto v_34249;
v_34248:
    v_34388 = stack[-2];
    goto v_34208;
v_34249:
    goto v_34257;
v_34253:
    stack[0] = stack[-1];
    goto v_34254;
v_34255:
    v_34388 = stack[-4];
    v_34388 = qcar(v_34388);
    v_34390 = v_34388;
    goto v_34271;
v_34267:
    v_34389 = v_34390;
    goto v_34268;
v_34269:
    v_34388 = stack[-8];
    goto v_34270;
v_34271:
    goto v_34267;
v_34268:
    goto v_34269;
v_34270:
    v_34388 = Lmemq(nil, v_34389, v_34388);
    if (v_34388 == nil) goto v_34266;
    goto v_34280;
v_34276:
    v_34388 = elt(env, 1); // minus
    goto v_34277;
v_34278:
    v_34389 = v_34390;
    goto v_34279;
v_34280:
    goto v_34276;
v_34277:
    goto v_34278;
v_34279:
    v_34388 = list2(v_34388, v_34389);
    env = stack[-9];
    goto v_34264;
v_34266:
    v_34388 = v_34390;
    goto v_34264;
    v_34388 = nil;
v_34264:
    v_34388 = ncons(v_34388);
    env = stack[-9];
    goto v_34256;
v_34257:
    goto v_34253;
v_34254:
    goto v_34255;
v_34256:
    v_34388 = Lrplacd(nil, stack[0], v_34388);
    env = stack[-9];
    v_34388 = stack[-1];
    v_34388 = qcdr(v_34388);
    stack[-1] = v_34388;
    goto v_34209;
v_34208:
    stack[0] = v_34388;
    goto v_34037;
v_34037:
    v_34388 = stack[-3];
    if (v_34388 == nil) goto v_34291;
    v_34388 = stack[-5];
    if (v_34388 == nil) goto v_34296;
    goto v_34303;
v_34299:
    goto v_34310;
v_34306:
    v_34388 = stack[-7];
    v_34389 = qcar(v_34388);
    goto v_34307;
v_34308:
    v_34388 = stack[0];
    goto v_34309;
v_34310:
    goto v_34306;
v_34307:
    goto v_34308;
v_34309:
    v_34388 = cons(v_34389, v_34388);
    env = stack[-9];
    fn = elt(env, 14); // mkupf
    stack[0] = (*qfn1(fn))(fn, v_34388);
    env = stack[-9];
    goto v_34300;
v_34301:
    goto v_34319;
v_34315:
    v_34389 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_34316;
v_34317:
    v_34388 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34318;
v_34319:
    goto v_34315;
v_34316:
    goto v_34317;
v_34318:
    v_34388 = cons(v_34389, v_34388);
    env = stack[-9];
    goto v_34302;
v_34303:
    goto v_34299;
v_34300:
    goto v_34301;
v_34302:
    {
        LispObject v_34400 = stack[0];
        fn = elt(env, 10); // multpfsq
        return (*qfn2(fn))(fn, v_34400, v_34388);
    }
v_34296:
    goto v_34330;
v_34326:
    v_34388 = stack[-7];
    v_34389 = qcar(v_34388);
    goto v_34327;
v_34328:
    v_34388 = stack[0];
    goto v_34329;
v_34330:
    goto v_34326;
v_34327:
    goto v_34328;
v_34329:
    v_34388 = cons(v_34389, v_34388);
    env = stack[-9];
    {
        fn = elt(env, 14); // mkupf
        return (*qfn1(fn))(fn, v_34388);
    }
    v_34388 = nil;
    goto v_34289;
v_34291:
    v_34388 = stack[-5];
    if (v_34388 == nil) goto v_34335;
    goto v_34343;
v_34339:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34340;
v_34341:
    goto v_34351;
v_34347:
    goto v_34357;
v_34353:
    v_34388 = stack[-7];
    v_34389 = qcar(v_34388);
    goto v_34354;
v_34355:
    v_34388 = stack[0];
    goto v_34356;
v_34357:
    goto v_34353;
v_34354:
    goto v_34355;
v_34356:
    v_34389 = cons(v_34389, v_34388);
    env = stack[-9];
    goto v_34348;
v_34349:
    v_34388 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34350;
v_34351:
    goto v_34347;
v_34348:
    goto v_34349;
v_34350:
    fn = elt(env, 15); // mksq
    v_34388 = (*qfn2(fn))(fn, v_34389, v_34388);
    env = stack[-9];
    fn = elt(env, 17); // negsq
    v_34388 = (*qfn1(fn))(fn, v_34388);
    env = stack[-9];
    goto v_34342;
v_34343:
    goto v_34339;
v_34340:
    goto v_34341;
v_34342:
    v_34388 = cons(stack[-1], v_34388);
    return ncons(v_34388);
v_34335:
    goto v_34370;
v_34366:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34367;
v_34368:
    goto v_34377;
v_34373:
    goto v_34383;
v_34379:
    v_34388 = stack[-7];
    v_34389 = qcar(v_34388);
    goto v_34380;
v_34381:
    v_34388 = stack[0];
    goto v_34382;
v_34383:
    goto v_34379;
v_34380:
    goto v_34381;
v_34382:
    v_34389 = cons(v_34389, v_34388);
    env = stack[-9];
    goto v_34374;
v_34375:
    v_34388 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_34376;
v_34377:
    goto v_34373;
v_34374:
    goto v_34375;
v_34376:
    fn = elt(env, 15); // mksq
    v_34388 = (*qfn2(fn))(fn, v_34389, v_34388);
    env = stack[-9];
    goto v_34369;
v_34370:
    goto v_34366;
v_34367:
    goto v_34368;
v_34369:
    v_34388 = cons(stack[-1], v_34388);
    return ncons(v_34388);
    v_34388 = nil;
v_34289:
v_33443:
    return onevalue(v_34388);
}



// Code for physop!*sq

static LispObject CC_physopHsq(LispObject env,
                         LispObject v_33433)
{
    env = qenv(env);
    LispObject v_33451;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33433);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33451 = v_33433;
// end of prologue
    v_33451 = qcar(v_33451);
    fn = elt(env, 2); // !*q2a
    v_33451 = (*qfn1(fn))(fn, v_33451);
    env = stack[0];
    fn = elt(env, 3); // !*collectphysops
    v_33451 = (*qfn1(fn))(fn, v_33451);
    env = stack[0];
    if (v_33451 == nil) goto v_33444;
    else goto v_33445;
v_33444:
    v_33451 = nil;
    goto v_33443;
v_33445:
    v_33451 = elt(env, 1); // physop
    goto v_33443;
    v_33451 = nil;
v_33443:
    return onevalue(v_33451);
}



// Code for mk!-strand!-vertex

static LispObject CC_mkKstrandKvertex(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33498, v_33499, v_33500;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33433,v_33434);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_33498 = v_33434;
    stack[-2] = v_33433;
// end of prologue
    goto v_33448;
v_33442:
    v_33500 = stack[-2];
    goto v_33443;
v_33444:
    v_33499 = v_33498;
    goto v_33445;
v_33446:
    v_33498 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33447;
v_33448:
    goto v_33442;
v_33443:
    goto v_33444;
v_33445:
    goto v_33446;
v_33447:
    fn = elt(env, 1); // incident
    v_33498 = (*qfnn(fn))(fn, 3, v_33500, v_33499, v_33498);
    env = stack[-4];
    v_33499 = v_33498;
    v_33498 = v_33499;
    v_33498 = qcar(v_33498);
    stack[-3] = v_33498;
    goto v_33461;
v_33455:
    stack[-1] = stack[-2];
    goto v_33456;
v_33457:
    v_33498 = v_33499;
    stack[0] = qcdr(v_33498);
    goto v_33458;
v_33459:
    v_33498 = stack[-3];
    v_33498 = qcar(v_33498);
    v_33498 = qcdr(v_33498);
    v_33498 = add1(v_33498);
    env = stack[-4];
    goto v_33460;
v_33461:
    goto v_33455;
v_33456:
    goto v_33457;
v_33458:
    goto v_33459;
v_33460:
    fn = elt(env, 1); // incident
    v_33498 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_33498);
    env = stack[-4];
    v_33499 = v_33498;
    v_33498 = v_33499;
    if (v_33498 == nil) goto v_33471;
    else goto v_33472;
v_33471:
    goto v_33480;
v_33476:
    v_33499 = stack[-2];
    goto v_33477;
v_33478:
    v_33498 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33479;
v_33480:
    goto v_33476;
v_33477:
    goto v_33478;
v_33479:
    v_33498 = cons(v_33499, v_33498);
    env = stack[-4];
    v_33498 = ncons(v_33498);
    env = stack[-4];
    goto v_33470;
v_33472:
    v_33498 = v_33499;
    v_33498 = qcar(v_33498);
    goto v_33470;
    v_33498 = nil;
v_33470:
    goto v_33494;
v_33488:
    v_33500 = stack[-2];
    goto v_33489;
v_33490:
    v_33499 = stack[-3];
    goto v_33491;
v_33492:
    goto v_33493;
v_33494:
    goto v_33488;
v_33489:
    goto v_33490;
v_33491:
    goto v_33492;
v_33493:
    {
        fn = elt(env, 2); // mk!-strand!-vertex2
        return (*qfnn(fn))(fn, 3, v_33500, v_33499, v_33498);
    }
    return onevalue(v_33498);
}



// Code for prepsqyy

static LispObject CC_prepsqyy(LispObject env,
                         LispObject v_33433)
{
    env = qenv(env);
    LispObject v_33454, v_33455, v_33456;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33456 = v_33433;
// end of prologue
    goto v_33444;
v_33440:
    v_33455 = v_33456;
    goto v_33441;
v_33442:
    v_33454 = elt(env, 1); // !*sq
    goto v_33443;
v_33444:
    goto v_33440;
v_33441:
    goto v_33442;
v_33443:
    if (!consp(v_33455)) goto v_33438;
    v_33455 = qcar(v_33455);
    if (v_33455 == v_33454) goto v_33437;
    else goto v_33438;
v_33437:
    v_33454 = v_33456;
    v_33454 = qcdr(v_33454);
    v_33454 = qcar(v_33454);
    {
        fn = elt(env, 2); // prepsqxx
        return (*qfn1(fn))(fn, v_33454);
    }
v_33438:
    v_33454 = v_33456;
    goto v_33436;
    v_33454 = nil;
v_33436:
    return onevalue(v_33454);
}



// Code for general!-minus!-mod!-p

static LispObject CC_generalKminusKmodKp(LispObject env,
                         LispObject v_33433)
{
    env = qenv(env);
    LispObject v_33488, v_33489;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33433);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_33433;
// end of prologue
    stack[-2] = nil;
v_33438:
    v_33488 = stack[-1];
    if (v_33488 == nil) goto v_33441;
    else goto v_33442;
v_33441:
    v_33488 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_33488);
    }
v_33442:
    v_33488 = stack[-1];
    if (!consp(v_33488)) goto v_33450;
    else goto v_33451;
v_33450:
    v_33488 = lisp_true;
    goto v_33449;
v_33451:
    v_33488 = stack[-1];
    v_33488 = qcar(v_33488);
    v_33488 = (consp(v_33488) ? nil : lisp_true);
    goto v_33449;
    v_33488 = nil;
v_33449:
    if (v_33488 == nil) goto v_33447;
    goto v_33464;
v_33460:
    stack[0] = stack[-2];
    goto v_33461;
v_33462:
    v_33488 = stack[-1];
    fn = elt(env, 2); // general!-modular!-minus
    v_33488 = (*qfn1(fn))(fn, v_33488);
    env = stack[-3];
    goto v_33463;
v_33464:
    goto v_33460;
v_33461:
    goto v_33462;
v_33463:
    {
        LispObject v_33493 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_33493, v_33488);
    }
v_33447:
    goto v_33477;
v_33471:
    v_33488 = stack[-1];
    v_33488 = qcar(v_33488);
    stack[0] = qcar(v_33488);
    goto v_33472;
v_33473:
    v_33488 = stack[-1];
    v_33488 = qcar(v_33488);
    v_33488 = qcdr(v_33488);
    v_33489 = CC_generalKminusKmodKp(elt(env, 0), v_33488);
    env = stack[-3];
    goto v_33474;
v_33475:
    v_33488 = stack[-2];
    goto v_33476;
v_33477:
    goto v_33471;
v_33472:
    goto v_33473;
v_33474:
    goto v_33475;
v_33476:
    v_33488 = acons(stack[0], v_33489, v_33488);
    env = stack[-3];
    stack[-2] = v_33488;
    v_33488 = stack[-1];
    v_33488 = qcdr(v_33488);
    stack[-1] = v_33488;
    goto v_33438;
    v_33488 = nil;
    return onevalue(v_33488);
}



// Code for rtrnda

static LispObject CC_rtrnda(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33489, v_33490, v_33491;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33433,v_33434);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_33490 = v_33434;
    stack[0] = v_33433;
// end of prologue
    v_33489 = stack[0];
    if (!consp(v_33489)) goto v_33442;
    else goto v_33443;
v_33442:
    v_33489 = stack[0];
    v_33489 = (LispObject)zerop(v_33489);
    v_33489 = v_33489 ? lisp_true : nil;
    env = stack[-1];
    goto v_33441;
v_33443:
    goto v_33453;
v_33449:
    v_33489 = stack[0];
    v_33489 = qcdr(v_33489);
    v_33491 = qcar(v_33489);
    goto v_33450;
v_33451:
    v_33489 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33452;
v_33453:
    goto v_33449;
v_33450:
    goto v_33451;
v_33452:
    v_33489 = (v_33491 == v_33489 ? lisp_true : nil);
    goto v_33441;
    v_33489 = nil;
v_33441:
    if (v_33489 == nil) goto v_33439;
    goto v_33464;
v_33460:
    v_33490 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33461;
v_33462:
    v_33489 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33463;
v_33464:
    goto v_33460;
v_33461:
    goto v_33462;
v_33463:
    v_33489 = cons(v_33490, v_33489);
    env = stack[-1];
    qvalue(elt(env, 1)) = v_33489; // rlval!#
    v_33489 = stack[0];
    goto v_33437;
v_33439:
    goto v_33475;
v_33471:
    v_33489 = stack[0];
    goto v_33472;
v_33473:
    goto v_33474;
v_33475:
    goto v_33471;
v_33472:
    goto v_33473;
v_33474:
    fn = elt(env, 2); // round!:dec1
    v_33489 = (*qfn2(fn))(fn, v_33489, v_33490);
    env = stack[-1];
    goto v_33484;
v_33480:
    v_33490 = v_33489;
    qvalue(elt(env, 1)) = v_33490; // rlval!#
    v_33490 = qcar(v_33490);
    goto v_33481;
v_33482:
    v_33489 = qcdr(v_33489);
    goto v_33483;
v_33484:
    goto v_33480;
v_33481:
    goto v_33482;
v_33483:
    {
        fn = elt(env, 3); // decimal2internal
        return (*qfn2(fn))(fn, v_33490, v_33489);
    }
    v_33489 = nil;
v_33437:
    return onevalue(v_33489);
}



// Code for gd_newtype

static LispObject CC_gd_newtype(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33495, v_33496, v_33497, v_33498;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33497 = v_33434;
    v_33498 = v_33433;
// end of prologue
    goto v_33444;
v_33440:
    v_33496 = v_33498;
    goto v_33441;
v_33442:
    v_33495 = v_33497;
    goto v_33443;
v_33444:
    goto v_33440;
v_33441:
    goto v_33442;
v_33443:
    if (v_33496 == v_33495) goto v_33438;
    else goto v_33439;
v_33438:
    v_33495 = v_33498;
    goto v_33437;
v_33439:
    goto v_33454;
v_33450:
    v_33496 = v_33498;
    goto v_33451;
v_33452:
    v_33495 = elt(env, 1); // gec
    goto v_33453;
v_33454:
    goto v_33450;
v_33451:
    goto v_33452;
v_33453:
    if (v_33496 == v_33495) goto v_33448;
    else goto v_33449;
v_33448:
    goto v_33465;
v_33461:
    v_33496 = v_33497;
    goto v_33462;
v_33463:
    v_33495 = elt(env, 2); // geg
    goto v_33464;
v_33465:
    goto v_33461;
v_33462:
    goto v_33463;
v_33464:
    if (v_33496 == v_33495) goto v_33459;
    else goto v_33460;
v_33459:
    v_33495 = elt(env, 1); // gec
    goto v_33458;
v_33460:
    v_33495 = nil;
    goto v_33458;
    v_33495 = nil;
v_33458:
    goto v_33437;
v_33449:
    goto v_33478;
v_33474:
    v_33496 = v_33498;
    goto v_33475;
v_33476:
    v_33495 = elt(env, 2); // geg
    goto v_33477;
v_33478:
    goto v_33474;
v_33475:
    goto v_33476;
v_33477:
    if (v_33496 == v_33495) goto v_33472;
    else goto v_33473;
v_33472:
    v_33495 = v_33497;
    goto v_33437;
v_33473:
    goto v_33488;
v_33484:
    v_33496 = v_33497;
    goto v_33485;
v_33486:
    v_33495 = elt(env, 1); // gec
    goto v_33487;
v_33488:
    goto v_33484;
v_33485:
    goto v_33486;
v_33487:
    if (v_33496 == v_33495) goto v_33482;
    else goto v_33483;
v_33482:
    v_33495 = nil;
    goto v_33437;
v_33483:
    v_33495 = elt(env, 3); // ger
    goto v_33437;
    v_33495 = nil;
v_33437:
    return onevalue(v_33495);
}



// Code for chrstrem

static LispObject CC_chrstrem(LispObject env,
                         LispObject v_33433)
{
    env = qenv(env);
    LispObject v_33774, v_33775;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33433);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_33433;
// end of prologue
    v_33774 = qvalue(elt(env, 1)); // !*trwu
    if (v_33774 == nil) goto v_33445;
    else goto v_33443;
v_33445:
    v_33774 = qvalue(elt(env, 2)); // !*trchrstrem
    if (v_33774 == nil) goto v_33447;
    else goto v_33443;
v_33447:
    goto v_33444;
v_33443:
    v_33774 = lisp_true;
    fn = elt(env, 13); // terpri!*
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    v_33774 = elt(env, 3); // "--------------------------------------------------------"
    fn = elt(env, 14); // prin2t!*
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    goto v_33442;
v_33444:
v_33442:
v_33456:
    v_33774 = stack[-3];
    fn = elt(env, 15); // wusort
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    stack[-3] = v_33774;
    v_33774 = qvalue(elt(env, 1)); // !*trwu
    if (v_33774 == nil) goto v_33463;
    else goto v_33461;
v_33463:
    v_33774 = qvalue(elt(env, 2)); // !*trchrstrem
    if (v_33774 == nil) goto v_33465;
    else goto v_33461;
v_33465:
    goto v_33462;
v_33461:
    v_33774 = elt(env, 4); // "The new pol-set in ascending order is"
    fn = elt(env, 14); // prin2t!*
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    v_33774 = stack[-3];
    stack[0] = v_33774;
v_33472:
    v_33774 = stack[0];
    if (v_33774 == nil) goto v_33476;
    else goto v_33477;
v_33476:
    goto v_33471;
v_33477:
    v_33774 = stack[0];
    v_33774 = qcar(v_33774);
    fn = elt(env, 16); // printsf
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    v_33774 = stack[0];
    v_33774 = qcdr(v_33774);
    stack[0] = v_33774;
    goto v_33472;
v_33471:
    v_33774 = lisp_true;
    fn = elt(env, 13); // terpri!*
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    goto v_33460;
v_33462:
v_33460:
    v_33774 = stack[-3];
    v_33774 = qcar(v_33774);
    fn = elt(env, 17); // wuconstantp
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    if (v_33774 == nil) goto v_33493;
    v_33774 = qvalue(elt(env, 1)); // !*trwu
    if (v_33774 == nil) goto v_33500;
    v_33774 = elt(env, 5); // "which is trivially trivial"
    fn = elt(env, 14); // prin2t!*
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    goto v_33498;
v_33500:
v_33498:
    v_33774 = elt(env, 6); // inconsistent
    stack[-2] = v_33774;
    v_33774 = (LispObject)16+TAG_FIXNUM; // 1
    v_33774 = ncons(v_33774);
    env = stack[-5];
    stack[-4] = v_33774;
    goto v_33491;
v_33493:
    v_33774 = nil;
    stack[-2] = v_33774;
    v_33774 = stack[-3];
    fn = elt(env, 18); // pickbasicset
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    v_33774 = Lnreverse(nil, v_33774);
    env = stack[-5];
    stack[-4] = v_33774;
    goto v_33491;
v_33491:
    v_33774 = qvalue(elt(env, 1)); // !*trwu
    if (v_33774 == nil) goto v_33518;
    v_33774 = stack[-2];
    if (v_33774 == nil) goto v_33521;
    else goto v_33518;
v_33521:
    v_33774 = elt(env, 7); // "A basic set is"
    fn = elt(env, 14); // prin2t!*
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    v_33774 = stack[-4];
    v_33774 = Lreverse(nil, v_33774);
    env = stack[-5];
    stack[0] = v_33774;
v_33528:
    v_33774 = stack[0];
    if (v_33774 == nil) goto v_33533;
    else goto v_33534;
v_33533:
    goto v_33527;
v_33534:
    v_33774 = stack[0];
    v_33774 = qcar(v_33774);
    fn = elt(env, 16); // printsf
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    v_33774 = stack[0];
    v_33774 = qcdr(v_33774);
    stack[0] = v_33774;
    goto v_33528;
v_33527:
    v_33774 = lisp_true;
    fn = elt(env, 13); // terpri!*
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    goto v_33516;
v_33518:
v_33516:
    goto v_33552;
v_33548:
    v_33775 = stack[-3];
    goto v_33549;
v_33550:
    v_33774 = stack[-4];
    goto v_33551;
v_33552:
    goto v_33548;
v_33549:
    goto v_33550;
v_33551:
    fn = elt(env, 19); // setdiff
    v_33774 = (*qfn2(fn))(fn, v_33775, v_33774);
    env = stack[-5];
    stack[-1] = v_33774;
v_33558:
    v_33774 = stack[-1];
    if (v_33774 == nil) goto v_33562;
    else goto v_33563;
v_33562:
    goto v_33557;
v_33563:
    v_33774 = stack[-1];
    v_33774 = qcar(v_33774);
    stack[0] = v_33774;
    goto v_33577;
v_33573:
    v_33775 = stack[-2];
    goto v_33574;
v_33575:
    v_33774 = elt(env, 6); // inconsistent
    goto v_33576;
v_33577:
    goto v_33573;
v_33574:
    goto v_33575;
v_33576:
    if (v_33775 == v_33774) goto v_33572;
    v_33774 = qvalue(elt(env, 1)); // !*trwu
    if (v_33774 == nil) goto v_33583;
    v_33774 = elt(env, 8); // "The remainder of "
    fn = elt(env, 20); // prin2!*
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    v_33774 = stack[0];
    fn = elt(env, 16); // printsf
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    v_33774 = elt(env, 9); // "wrt the basic set is "
    fn = elt(env, 20); // prin2!*
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    goto v_33581;
v_33583:
v_33581:
    goto v_33596;
v_33592:
    v_33775 = stack[0];
    goto v_33593;
v_33594:
    v_33774 = stack[-4];
    goto v_33595;
v_33596:
    goto v_33592;
v_33593:
    goto v_33594;
v_33595:
    fn = elt(env, 21); // findremainder
    v_33774 = (*qfn2(fn))(fn, v_33775, v_33774);
    env = stack[-5];
    stack[0] = v_33774;
    v_33774 = qvalue(elt(env, 1)); // !*trwu
    if (v_33774 == nil) goto v_33602;
    v_33774 = stack[0];
    fn = elt(env, 16); // printsf
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    goto v_33600;
v_33602:
v_33600:
    v_33774 = stack[0];
    if (v_33774 == nil) goto v_33610;
    v_33774 = stack[0];
    fn = elt(env, 17); // wuconstantp
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    if (v_33774 == nil) goto v_33615;
    v_33774 = elt(env, 6); // inconsistent
    stack[-2] = v_33774;
    v_33774 = qvalue(elt(env, 1)); // !*trwu
    if (v_33774 == nil) goto v_33622;
    v_33774 = elt(env, 10); // "which is a non-zero constant, and so"
    fn = elt(env, 22); // prin2t
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    v_33774 = elt(env, 11); // "the equations are inconsistent."
    fn = elt(env, 22); // prin2t
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    goto v_33620;
v_33622:
v_33620:
    goto v_33613;
v_33615:
    goto v_33635;
v_33631:
    v_33774 = stack[0];
    fn = elt(env, 23); // absf
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    v_33775 = ncons(v_33774);
    env = stack[-5];
    goto v_33632;
v_33633:
    v_33774 = stack[-2];
    goto v_33634;
v_33635:
    goto v_33631;
v_33632:
    goto v_33633;
v_33634:
    fn = elt(env, 24); // union
    v_33774 = (*qfn2(fn))(fn, v_33775, v_33774);
    env = stack[-5];
    stack[-2] = v_33774;
    goto v_33613;
v_33613:
    goto v_33608;
v_33610:
v_33608:
    goto v_33570;
v_33572:
v_33570:
    v_33774 = stack[-1];
    v_33774 = qcdr(v_33774);
    stack[-1] = v_33774;
    goto v_33558;
v_33557:
    v_33774 = stack[-2];
    if (v_33774 == nil) goto v_33646;
    goto v_33654;
v_33650:
    v_33775 = stack[-2];
    goto v_33651;
v_33652:
    v_33774 = elt(env, 6); // inconsistent
    goto v_33653;
v_33654:
    goto v_33650;
v_33651:
    goto v_33652;
v_33653:
    if (v_33775 == v_33774) goto v_33646;
    goto v_33662;
v_33658:
    v_33775 = stack[-3];
    goto v_33659;
v_33660:
    v_33774 = stack[-2];
    goto v_33661;
v_33662:
    goto v_33658;
v_33659:
    goto v_33660;
v_33661:
    v_33774 = Lappend(nil, v_33775, v_33774);
    env = stack[-5];
    stack[-3] = v_33774;
    goto v_33644;
v_33646:
v_33644:
    v_33774 = stack[-2];
    if (v_33774 == nil) goto v_33671;
    else goto v_33672;
v_33671:
    v_33774 = lisp_true;
    goto v_33670;
v_33672:
    goto v_33681;
v_33677:
    v_33775 = stack[-2];
    goto v_33678;
v_33679:
    v_33774 = elt(env, 6); // inconsistent
    goto v_33680;
v_33681:
    goto v_33677;
v_33678:
    goto v_33679;
v_33680:
    v_33774 = (v_33775 == v_33774 ? lisp_true : nil);
    goto v_33670;
    v_33774 = nil;
v_33670:
    if (v_33774 == nil) goto v_33667;
    else goto v_33668;
v_33667:
    goto v_33456;
v_33668:
    goto v_33693;
v_33689:
    v_33775 = stack[-2];
    goto v_33690;
v_33691:
    v_33774 = elt(env, 6); // inconsistent
    goto v_33692;
v_33693:
    goto v_33689;
v_33690:
    goto v_33691;
v_33692:
    if (v_33775 == v_33774) goto v_33687;
    else goto v_33688;
v_33687:
    v_33774 = (LispObject)16+TAG_FIXNUM; // 1
    v_33774 = ncons(v_33774);
    env = stack[-5];
    stack[-4] = v_33774;
    goto v_33686;
v_33688:
v_33686:
    v_33774 = qvalue(elt(env, 1)); // !*trwu
    if (v_33774 == nil) goto v_33702;
    else goto v_33700;
v_33702:
    v_33774 = qvalue(elt(env, 2)); // !*trchrstrem
    if (v_33774 == nil) goto v_33704;
    else goto v_33700;
v_33704:
    goto v_33701;
v_33700:
    v_33774 = lisp_true;
    fn = elt(env, 13); // terpri!*
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    v_33774 = lisp_true;
    fn = elt(env, 13); // terpri!*
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    v_33774 = elt(env, 12); // "The final characteristic set is:"
    fn = elt(env, 14); // prin2t!*
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    v_33774 = stack[-4];
    v_33774 = Lreverse(nil, v_33774);
    env = stack[-5];
    stack[0] = v_33774;
v_33715:
    v_33774 = stack[0];
    if (v_33774 == nil) goto v_33720;
    else goto v_33721;
v_33720:
    goto v_33714;
v_33721:
    v_33774 = stack[0];
    v_33774 = qcar(v_33774);
    fn = elt(env, 16); // printsf
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    v_33774 = stack[0];
    v_33774 = qcdr(v_33774);
    stack[0] = v_33774;
    goto v_33715;
v_33714:
    goto v_33699;
v_33701:
v_33699:
    v_33774 = stack[-4];
    stack[-3] = v_33774;
    v_33774 = stack[-3];
    if (v_33774 == nil) goto v_33741;
    else goto v_33742;
v_33741:
    v_33774 = nil;
    goto v_33736;
v_33742:
    v_33774 = stack[-3];
    v_33774 = qcar(v_33774);
    fn = elt(env, 23); // absf
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    v_33774 = ncons(v_33774);
    env = stack[-5];
    stack[-1] = v_33774;
    stack[-2] = v_33774;
v_33737:
    v_33774 = stack[-3];
    v_33774 = qcdr(v_33774);
    stack[-3] = v_33774;
    v_33774 = stack[-3];
    if (v_33774 == nil) goto v_33755;
    else goto v_33756;
v_33755:
    v_33774 = stack[-2];
    goto v_33736;
v_33756:
    goto v_33764;
v_33760:
    stack[0] = stack[-1];
    goto v_33761;
v_33762:
    v_33774 = stack[-3];
    v_33774 = qcar(v_33774);
    fn = elt(env, 23); // absf
    v_33774 = (*qfn1(fn))(fn, v_33774);
    env = stack[-5];
    v_33774 = ncons(v_33774);
    env = stack[-5];
    goto v_33763;
v_33764:
    goto v_33760;
v_33761:
    goto v_33762;
v_33763:
    v_33774 = Lrplacd(nil, stack[0], v_33774);
    env = stack[-5];
    v_33774 = stack[-1];
    v_33774 = qcdr(v_33774);
    stack[-1] = v_33774;
    goto v_33737;
v_33736:
        return Lnreverse(nil, v_33774);
    return onevalue(v_33774);
}



// Code for qqe_qadd!-inside

static LispObject CC_qqe_qaddKinside(LispObject env,
                         LispObject v_33433)
{
    env = qenv(env);
    LispObject v_33555, v_33556;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33433);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_33433;
// end of prologue
    v_33555 = stack[0];
    if (v_33555 == nil) goto v_33448;
    else goto v_33449;
v_33448:
    v_33555 = lisp_true;
    goto v_33447;
v_33449:
    v_33555 = stack[0];
    v_33555 = (consp(v_33555) ? nil : lisp_true);
    goto v_33447;
    v_33555 = nil;
v_33447:
    if (v_33555 == nil) goto v_33445;
    v_33555 = nil;
    goto v_33441;
v_33445:
    v_33555 = stack[0];
    fn = elt(env, 4); // qqe_op
    v_33555 = (*qfn1(fn))(fn, v_33555);
    env = stack[-3];
    stack[-1] = v_33555;
    goto v_33464;
v_33460:
    v_33556 = elt(env, 1); // a
    goto v_33461;
v_33462:
    v_33555 = qvalue(elt(env, 2)); // qqe_qadd!-location!*
    goto v_33463;
v_33464:
    goto v_33460;
v_33461:
    goto v_33462;
v_33463:
    v_33555 = cons(v_33556, v_33555);
    env = stack[-3];
    qvalue(elt(env, 2)) = v_33555; // qqe_qadd!-location!*
    v_33555 = stack[0];
    v_33555 = Lconsp(nil, v_33555);
    env = stack[-3];
    if (v_33555 == nil) goto v_33470;
    v_33555 = stack[-1];
    fn = elt(env, 5); // qqe_qopaddp
    v_33555 = (*qfn1(fn))(fn, v_33555);
    env = stack[-3];
    if (v_33555 == nil) goto v_33474;
    else goto v_33470;
v_33474:
    v_33555 = lisp_true;
    stack[-2] = v_33555;
    v_33555 = stack[-1];
    v_33556 = v_33555;
    v_33555 = stack[0];
    v_33555 = qcdr(v_33555);
    stack[-1] = v_33555;
    v_33555 = qvalue(elt(env, 2)); // qqe_qadd!-location!*
    stack[0] = v_33555;
v_33484:
    v_33555 = stack[-1];
    if (v_33555 == nil) goto v_33487;
    v_33555 = stack[-2];
    if (v_33555 == nil) goto v_33487;
    goto v_33488;
v_33487:
    goto v_33483;
v_33488:
    goto v_33499;
v_33495:
    v_33556 = elt(env, 3); // d
    goto v_33496;
v_33497:
    v_33555 = stack[0];
    goto v_33498;
v_33499:
    goto v_33495;
v_33496:
    goto v_33497;
v_33498:
    v_33555 = cons(v_33556, v_33555);
    env = stack[-3];
    qvalue(elt(env, 2)) = v_33555; // qqe_qadd!-location!*
    v_33555 = qvalue(elt(env, 2)); // qqe_qadd!-location!*
    stack[0] = v_33555;
    v_33555 = stack[-1];
    if (!consp(v_33555)) goto v_33510;
    v_33555 = stack[-1];
    v_33555 = qcar(v_33555);
    v_33555 = Lconsp(nil, v_33555);
    env = stack[-3];
    if (v_33555 == nil) goto v_33514;
    else goto v_33515;
v_33514:
    v_33555 = nil;
    goto v_33513;
v_33515:
    v_33555 = stack[-1];
    v_33555 = qcar(v_33555);
    v_33555 = CC_qqe_qaddKinside(elt(env, 0), v_33555);
    env = stack[-3];
    goto v_33513;
    v_33555 = nil;
v_33513:
    goto v_33508;
v_33510:
    v_33555 = nil;
    goto v_33508;
    v_33555 = nil;
v_33508:
    if (v_33555 == nil) goto v_33506;
    v_33555 = nil;
    stack[-2] = v_33555;
    goto v_33504;
v_33506:
v_33504:
    v_33555 = stack[-1];
    v_33556 = v_33555;
    v_33555 = stack[-1];
    v_33555 = qcdr(v_33555);
    stack[-1] = v_33555;
    goto v_33484;
v_33483:
    v_33555 = stack[-2];
    if (v_33555 == nil) goto v_33535;
    else goto v_33536;
v_33535:
    v_33555 = v_33556;
    goto v_33441;
v_33536:
    v_33555 = nil;
    goto v_33441;
    goto v_33468;
v_33470:
    v_33555 = stack[0];
    v_33555 = Lconsp(nil, v_33555);
    env = stack[-3];
    if (v_33555 == nil) goto v_33544;
    v_33555 = stack[-1];
    fn = elt(env, 5); // qqe_qopaddp
    v_33555 = (*qfn1(fn))(fn, v_33555);
    if (v_33555 == nil) goto v_33544;
    v_33555 = lisp_true;
    goto v_33441;
v_33544:
    v_33555 = nil;
    goto v_33441;
v_33468:
    v_33555 = nil;
v_33441:
    return onevalue(v_33555);
}



// Code for dip_reduceconti

static LispObject CC_dip_reduceconti(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33469, v_33470;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33433,v_33434);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_33434;
    stack[-2] = v_33433;
// end of prologue
    v_33469 = stack[-2];
    if (v_33469 == nil) goto v_33439;
    goto v_33448;
v_33442:
    goto v_33454;
v_33450:
    v_33469 = stack[-2];
    fn = elt(env, 1); // dip_lbc
    v_33470 = (*qfn1(fn))(fn, v_33469);
    env = stack[-4];
    goto v_33451;
v_33452:
    v_33469 = stack[-1];
    goto v_33453;
v_33454:
    goto v_33450;
v_33451:
    goto v_33452;
v_33453:
    fn = elt(env, 2); // bc_quot
    stack[-3] = (*qfn2(fn))(fn, v_33470, v_33469);
    env = stack[-4];
    goto v_33443;
v_33444:
    v_33469 = stack[-2];
    fn = elt(env, 3); // dip_evlmon
    stack[0] = (*qfn1(fn))(fn, v_33469);
    env = stack[-4];
    goto v_33445;
v_33446:
    goto v_33465;
v_33461:
    v_33469 = stack[-2];
    fn = elt(env, 4); // dip_mred
    v_33470 = (*qfn1(fn))(fn, v_33469);
    env = stack[-4];
    goto v_33462;
v_33463:
    v_33469 = stack[-1];
    goto v_33464;
v_33465:
    goto v_33461;
v_33462:
    goto v_33463;
v_33464:
    v_33469 = CC_dip_reduceconti(elt(env, 0), v_33470, v_33469);
    env = stack[-4];
    goto v_33447;
v_33448:
    goto v_33442;
v_33443:
    goto v_33444;
v_33445:
    goto v_33446;
v_33447:
    {
        LispObject v_33475 = stack[-3];
        LispObject v_33476 = stack[0];
        fn = elt(env, 5); // dip_moncomp
        return (*qfnn(fn))(fn, 3, v_33475, v_33476, v_33469);
    }
v_33439:
    v_33469 = nil;
    return onevalue(v_33469);
}



// Code for search_att

static LispObject CC_search_att(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33666, v_33667;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33433,v_33434);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_33434;
    stack[-2] = v_33433;
// end of prologue
    v_33666 = nil;
    stack[0] = v_33666;
    v_33666 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_33666;
    goto v_33449;
v_33445:
    v_33667 = stack[-2];
    goto v_33446;
v_33447:
    v_33666 = stack[-1];
    goto v_33448;
v_33449:
    goto v_33445;
v_33446:
    goto v_33447;
v_33448:
    fn = elt(env, 6); // find2
    v_33666 = (*qfn2(fn))(fn, v_33667, v_33666);
    env = stack[-4];
    stack[-2] = v_33666;
    goto v_33460;
v_33456:
    v_33667 = stack[-2];
    goto v_33457;
v_33458:
    v_33666 = elt(env, 1); // (stop)
    goto v_33459;
v_33460:
    goto v_33456;
v_33457:
    goto v_33458;
v_33459:
    if (equal(v_33667, v_33666)) goto v_33455;
v_33465:
    goto v_33474;
v_33470:
    v_33666 = stack[-2];
    v_33667 = qcar(v_33666);
    goto v_33471;
v_33472:
    v_33666 = elt(env, 2); // ! 
    goto v_33473;
v_33474:
    goto v_33470;
v_33471:
    goto v_33472;
v_33473:
    if (v_33667 == v_33666) goto v_33469;
    goto v_33464;
v_33469:
    v_33666 = stack[-2];
    v_33666 = qcdr(v_33666);
    stack[-2] = v_33666;
    goto v_33465;
v_33464:
    goto v_33489;
v_33485:
    v_33666 = stack[-2];
    v_33667 = qcar(v_33666);
    goto v_33486;
v_33487:
    v_33666 = elt(env, 3); // !=
    goto v_33488;
v_33489:
    goto v_33485;
v_33486:
    goto v_33487;
v_33488:
    if (v_33667 == v_33666) goto v_33483;
    else goto v_33484;
v_33483:
    v_33666 = stack[-2];
    v_33666 = qcdr(v_33666);
    stack[-2] = v_33666;
v_33497:
    goto v_33506;
v_33502:
    v_33666 = stack[-2];
    v_33667 = qcar(v_33666);
    goto v_33503;
v_33504:
    v_33666 = elt(env, 2); // ! 
    goto v_33505;
v_33506:
    goto v_33502;
v_33503:
    goto v_33504;
v_33505:
    if (v_33667 == v_33666) goto v_33501;
    goto v_33496;
v_33501:
    v_33666 = stack[-2];
    v_33666 = qcdr(v_33666);
    stack[-2] = v_33666;
    goto v_33497;
v_33496:
    goto v_33521;
v_33517:
    v_33666 = stack[-2];
    v_33667 = qcar(v_33666);
    goto v_33518;
v_33519:
    v_33666 = elt(env, 4); // !"
    goto v_33520;
v_33521:
    goto v_33517;
v_33518:
    goto v_33519;
v_33520:
    if (v_33667 == v_33666) goto v_33515;
    else goto v_33516;
v_33515:
    v_33666 = stack[-2];
    v_33666 = qcdr(v_33666);
    stack[-2] = v_33666;
v_33529:
    goto v_33538;
v_33534:
    v_33667 = stack[-3];
    goto v_33535;
v_33536:
    v_33666 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33537;
v_33538:
    goto v_33534;
v_33535:
    goto v_33536;
v_33537:
    if (v_33667 == v_33666) goto v_33533;
    goto v_33528;
v_33533:
    goto v_33547;
v_33543:
    v_33666 = stack[-2];
    v_33667 = qcar(v_33666);
    goto v_33544;
v_33545:
    v_33666 = stack[0];
    goto v_33546;
v_33547:
    goto v_33543;
v_33544:
    goto v_33545;
v_33546:
    v_33666 = cons(v_33667, v_33666);
    env = stack[-4];
    stack[0] = v_33666;
    v_33666 = stack[-2];
    v_33666 = qcdr(v_33666);
    stack[-2] = v_33666;
    goto v_33565;
v_33561:
    v_33666 = stack[-2];
    v_33667 = qcar(v_33666);
    goto v_33562;
v_33563:
    v_33666 = elt(env, 2); // ! 
    goto v_33564;
v_33565:
    goto v_33561;
v_33562:
    goto v_33563;
v_33564:
    if (v_33667 == v_33666) goto v_33559;
    else goto v_33560;
v_33559:
    v_33666 = lisp_true;
    goto v_33558;
v_33560:
    goto v_33576;
v_33572:
    v_33666 = stack[-2];
    v_33667 = qcar(v_33666);
    goto v_33573;
v_33574:
    v_33666 = elt(env, 5); // !$
    goto v_33575;
v_33576:
    goto v_33572;
v_33573:
    goto v_33574;
v_33575:
    v_33666 = (v_33667 == v_33666 ? lisp_true : nil);
    goto v_33558;
    v_33666 = nil;
v_33558:
    if (v_33666 == nil) goto v_33556;
    v_33666 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_33666;
    goto v_33554;
v_33556:
v_33554:
    goto v_33529;
v_33528:
    goto v_33514;
v_33516:
v_33586:
    goto v_33595;
v_33591:
    v_33667 = stack[-3];
    goto v_33592;
v_33593:
    v_33666 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33594;
v_33595:
    goto v_33591;
v_33592:
    goto v_33593;
v_33594:
    if (v_33667 == v_33666) goto v_33590;
    goto v_33585;
v_33590:
    goto v_33604;
v_33600:
    v_33666 = stack[-2];
    v_33667 = qcar(v_33666);
    goto v_33601;
v_33602:
    v_33666 = stack[0];
    goto v_33603;
v_33604:
    goto v_33600;
v_33601:
    goto v_33602;
v_33603:
    v_33666 = cons(v_33667, v_33666);
    env = stack[-4];
    stack[0] = v_33666;
    v_33666 = stack[-2];
    v_33666 = qcdr(v_33666);
    stack[-2] = v_33666;
    goto v_33622;
v_33618:
    v_33666 = stack[-2];
    v_33667 = qcar(v_33666);
    goto v_33619;
v_33620:
    v_33666 = elt(env, 2); // ! 
    goto v_33621;
v_33622:
    goto v_33618;
v_33619:
    goto v_33620;
v_33621:
    if (v_33667 == v_33666) goto v_33616;
    else goto v_33617;
v_33616:
    v_33666 = lisp_true;
    goto v_33615;
v_33617:
    goto v_33633;
v_33629:
    v_33666 = stack[-2];
    v_33667 = qcar(v_33666);
    goto v_33630;
v_33631:
    v_33666 = elt(env, 5); // !$
    goto v_33632;
v_33633:
    goto v_33629;
v_33630:
    goto v_33631;
v_33632:
    v_33666 = (v_33667 == v_33666 ? lisp_true : nil);
    goto v_33615;
    v_33666 = nil;
v_33615:
    if (v_33666 == nil) goto v_33613;
    v_33666 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_33666;
    goto v_33611;
v_33613:
v_33611:
    goto v_33586;
v_33585:
    goto v_33514;
v_33514:
    goto v_33482;
v_33484:
    goto v_33646;
v_33642:
    v_33666 = stack[-1];
    v_33667 = Lcompress(nil, v_33666);
    env = stack[-4];
    goto v_33643;
v_33644:
    v_33666 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33645;
v_33646:
    goto v_33642;
v_33643:
    goto v_33644;
v_33645:
    fn = elt(env, 7); // errorml
    v_33666 = (*qfn2(fn))(fn, v_33667, v_33666);
    env = stack[-4];
    goto v_33482;
v_33482:
    goto v_33658;
v_33654:
    v_33666 = stack[0];
    v_33666 = qcar(v_33666);
    goto v_33655;
v_33656:
    v_33667 = elt(env, 4); // !"
    goto v_33657;
v_33658:
    goto v_33654;
v_33655:
    goto v_33656;
v_33657:
    if (v_33666 == v_33667) goto v_33652;
    else goto v_33653;
v_33652:
    v_33666 = stack[0];
    v_33666 = qcdr(v_33666);
    stack[0] = v_33666;
    goto v_33651;
v_33653:
v_33651:
    v_33666 = stack[0];
        return Lreverse(nil, v_33666);
v_33455:
    v_33666 = nil;
    return onevalue(v_33666);
}



// Code for setprev

static LispObject CC_setprev(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33541, v_33542;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33433,v_33434);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_33434;
    stack[-3] = v_33433;
// end of prologue
v_33438:
    goto v_33447;
v_33443:
    goto v_33452;
v_33448:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_33449;
v_33450:
    goto v_33459;
v_33455:
    v_33542 = qvalue(elt(env, 2)); // maxvar
    goto v_33456;
v_33457:
    v_33541 = stack[-3];
    goto v_33458;
v_33459:
    goto v_33455;
v_33456:
    goto v_33457;
v_33458:
    v_33541 = plus2(v_33542, v_33541);
    env = stack[-5];
    goto v_33451;
v_33452:
    goto v_33448;
v_33449:
    goto v_33450;
v_33451:
    v_33542 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_33541-TAG_FIXNUM)/(16/CELL)));
    goto v_33444;
v_33445:
    v_33541 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_33446;
v_33447:
    goto v_33443;
v_33444:
    goto v_33445;
v_33446:
    v_33541 = *(LispObject *)((char *)v_33542 + (CELL-TAG_VECTOR) + (((intptr_t)v_33541-TAG_FIXNUM)/(16/CELL)));
    if (is_number(v_33541)) goto v_33441;
    else goto v_33442;
v_33441:
    goto v_33469;
v_33465:
    goto v_33474;
v_33470:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_33471;
v_33472:
    goto v_33481;
v_33477:
    v_33542 = qvalue(elt(env, 2)); // maxvar
    goto v_33478;
v_33479:
    v_33541 = stack[-3];
    goto v_33480;
v_33481:
    goto v_33477;
v_33478:
    goto v_33479;
v_33480:
    v_33541 = plus2(v_33542, v_33541);
    env = stack[-5];
    goto v_33473;
v_33474:
    goto v_33470;
v_33471:
    goto v_33472;
v_33473:
    v_33542 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_33541-TAG_FIXNUM)/(16/CELL)));
    goto v_33466;
v_33467:
    v_33541 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_33468;
v_33469:
    goto v_33465;
v_33466:
    goto v_33467;
v_33468:
    v_33541 = *(LispObject *)((char *)v_33542 + (CELL-TAG_VECTOR) + (((intptr_t)v_33541-TAG_FIXNUM)/(16/CELL)));
    stack[-3] = v_33541;
    goto v_33438;
v_33442:
    goto v_33495;
v_33489:
    goto v_33500;
v_33496:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_33497;
v_33498:
    goto v_33507;
v_33503:
    v_33542 = qvalue(elt(env, 2)); // maxvar
    goto v_33504;
v_33505:
    v_33541 = stack[-3];
    goto v_33506;
v_33507:
    goto v_33503;
v_33504:
    goto v_33505;
v_33506:
    v_33541 = plus2(v_33542, v_33541);
    env = stack[-5];
    goto v_33499;
v_33500:
    goto v_33496;
v_33497:
    goto v_33498;
v_33499:
    stack[-4] = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_33541-TAG_FIXNUM)/(16/CELL)));
    goto v_33490;
v_33491:
    stack[-2] = (LispObject)128+TAG_FIXNUM; // 8
    goto v_33492;
v_33493:
    goto v_33517;
v_33513:
    stack[-1] = stack[0];
    goto v_33514;
v_33515:
    goto v_33523;
v_33519:
    goto v_33528;
v_33524:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_33525;
v_33526:
    goto v_33535;
v_33531:
    v_33542 = qvalue(elt(env, 2)); // maxvar
    goto v_33532;
v_33533:
    v_33541 = stack[-3];
    goto v_33534;
v_33535:
    goto v_33531;
v_33532:
    goto v_33533;
v_33534:
    v_33541 = plus2(v_33542, v_33541);
    env = stack[-5];
    goto v_33527;
v_33528:
    goto v_33524;
v_33525:
    goto v_33526;
v_33527:
    v_33542 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_33541-TAG_FIXNUM)/(16/CELL)));
    goto v_33520;
v_33521:
    v_33541 = (LispObject)128+TAG_FIXNUM; // 8
    goto v_33522;
v_33523:
    goto v_33519;
v_33520:
    goto v_33521;
v_33522:
    v_33541 = *(LispObject *)((char *)v_33542 + (CELL-TAG_VECTOR) + (((intptr_t)v_33541-TAG_FIXNUM)/(16/CELL)));
    goto v_33516;
v_33517:
    goto v_33513;
v_33514:
    goto v_33515;
v_33516:
    v_33541 = cons(stack[-1], v_33541);
    goto v_33494;
v_33495:
    goto v_33489;
v_33490:
    goto v_33491;
v_33492:
    goto v_33493;
v_33494:
    *(LispObject *)((char *)stack[-4] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-2]-TAG_FIXNUM)/(16/CELL))) = v_33541;
    goto v_33437;
    v_33541 = nil;
v_33437:
    return onevalue(v_33541);
}



// Code for poly!-remainder

static LispObject CC_polyKremainder(LispObject env,
                         LispObject v_33433)
{
    env = qenv(env);
    LispObject v_33446, v_33447, v_33448;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33446 = v_33433;
// end of prologue
    goto v_33442;
v_33436:
    v_33448 = v_33446;
    goto v_33437;
v_33438:
    v_33447 = elt(env, 1); // remainder
    goto v_33439;
v_33440:
    v_33446 = nil;
    goto v_33441;
v_33442:
    goto v_33436;
v_33437:
    goto v_33438;
v_33439:
    goto v_33440;
v_33441:
    {
        fn = elt(env, 2); // poly!-divide!*
        return (*qfnn(fn))(fn, 3, v_33448, v_33447, v_33446);
    }
}



// Code for mkuniquewedge

static LispObject CC_mkuniquewedge(LispObject env,
                         LispObject v_33433)
{
    env = qenv(env);
    LispObject v_33487, v_33488;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33433);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33433;
// end of prologue
    stack[-1] = nil;
v_33439:
    v_33487 = stack[0];
    if (v_33487 == nil) goto v_33444;
    else goto v_33445;
v_33444:
    goto v_33440;
v_33445:
    goto v_33452;
v_33448:
    goto v_33458;
v_33454:
    v_33487 = stack[0];
    v_33487 = qcar(v_33487);
    v_33487 = qcar(v_33487);
    fn = elt(env, 1); // mkuniquewedge1
    v_33488 = (*qfn1(fn))(fn, v_33487);
    env = stack[-2];
    goto v_33455;
v_33456:
    v_33487 = stack[0];
    v_33487 = qcar(v_33487);
    v_33487 = qcdr(v_33487);
    goto v_33457;
v_33458:
    goto v_33454;
v_33455:
    goto v_33456;
v_33457:
    fn = elt(env, 2); // multpfsq
    v_33488 = (*qfn2(fn))(fn, v_33488, v_33487);
    env = stack[-2];
    goto v_33449;
v_33450:
    v_33487 = stack[-1];
    goto v_33451;
v_33452:
    goto v_33448;
v_33449:
    goto v_33450;
v_33451:
    v_33487 = cons(v_33488, v_33487);
    env = stack[-2];
    stack[-1] = v_33487;
    v_33487 = stack[0];
    v_33487 = qcdr(v_33487);
    stack[0] = v_33487;
    goto v_33439;
v_33440:
    v_33487 = nil;
    v_33488 = v_33487;
v_33441:
    v_33487 = stack[-1];
    if (v_33487 == nil) goto v_33472;
    else goto v_33473;
v_33472:
    v_33487 = v_33488;
    goto v_33438;
v_33473:
    goto v_33481;
v_33477:
    v_33487 = stack[-1];
    v_33487 = qcar(v_33487);
    goto v_33478;
v_33479:
    goto v_33480;
v_33481:
    goto v_33477;
v_33478:
    goto v_33479;
v_33480:
    fn = elt(env, 3); // addpf
    v_33487 = (*qfn2(fn))(fn, v_33487, v_33488);
    env = stack[-2];
    v_33488 = v_33487;
    v_33487 = stack[-1];
    v_33487 = qcdr(v_33487);
    stack[-1] = v_33487;
    goto v_33441;
v_33438:
    return onevalue(v_33487);
}



// Code for rand!-comb

static LispObject CC_randKcomb(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33637, v_33638, v_33639;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33433,v_33434);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_33434;
    stack[-1] = v_33433;
// end of prologue
    goto v_33444;
v_33440:
    v_33638 = stack[-3];
    goto v_33441;
v_33442:
    v_33637 = stack[-1];
    goto v_33443;
v_33444:
    goto v_33440;
v_33441:
    goto v_33442;
v_33443:
    if (equal(v_33638, v_33637)) goto v_33438;
    else goto v_33439;
v_33438:
    v_33637 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_33637;
    goto v_33464;
v_33460:
    v_33637 = stack[-3];
    v_33638 = sub1(v_33637);
    env = stack[-5];
    goto v_33461;
v_33462:
    v_33637 = stack[-4];
    goto v_33463;
v_33464:
    goto v_33460;
v_33461:
    goto v_33462;
v_33463:
    v_33637 = difference2(v_33638, v_33637);
    env = stack[-5];
    v_33637 = Lminusp(nil, v_33637);
    env = stack[-5];
    if (v_33637 == nil) goto v_33457;
    v_33637 = nil;
    goto v_33451;
v_33457:
    v_33637 = stack[-4];
    v_33637 = ncons(v_33637);
    env = stack[-5];
    stack[-1] = v_33637;
    stack[-2] = v_33637;
v_33452:
    v_33637 = stack[-4];
    v_33637 = add1(v_33637);
    env = stack[-5];
    stack[-4] = v_33637;
    goto v_33483;
v_33479:
    v_33637 = stack[-3];
    v_33638 = sub1(v_33637);
    env = stack[-5];
    goto v_33480;
v_33481:
    v_33637 = stack[-4];
    goto v_33482;
v_33483:
    goto v_33479;
v_33480:
    goto v_33481;
v_33482:
    v_33637 = difference2(v_33638, v_33637);
    env = stack[-5];
    v_33637 = Lminusp(nil, v_33637);
    env = stack[-5];
    if (v_33637 == nil) goto v_33476;
    v_33637 = stack[-2];
    goto v_33451;
v_33476:
    goto v_33493;
v_33489:
    stack[0] = stack[-1];
    goto v_33490;
v_33491:
    v_33637 = stack[-4];
    v_33637 = ncons(v_33637);
    env = stack[-5];
    goto v_33492;
v_33493:
    goto v_33489;
v_33490:
    goto v_33491;
v_33492:
    v_33637 = Lrplacd(nil, stack[0], v_33637);
    env = stack[-5];
    v_33637 = stack[-1];
    v_33637 = qcdr(v_33637);
    stack[-1] = v_33637;
    goto v_33452;
v_33451:
    goto v_33437;
v_33439:
    stack[-2] = nil;
    goto v_33513;
v_33509:
    goto v_33519;
v_33515:
    v_33638 = stack[-1];
    goto v_33516;
v_33517:
    v_33637 = stack[-3];
    goto v_33518;
v_33519:
    goto v_33515;
v_33516:
    goto v_33517;
v_33518:
    v_33638 = difference2(v_33638, v_33637);
    env = stack[-5];
    goto v_33510;
v_33511:
    v_33637 = stack[-3];
    goto v_33512;
v_33513:
    goto v_33509;
v_33510:
    goto v_33511;
v_33512:
    v_33637 = (LispObject)lessp2(v_33638, v_33637);
    v_33637 = v_33637 ? lisp_true : nil;
    env = stack[-5];
    if (v_33637 == nil) goto v_33507;
    goto v_33531;
v_33527:
    stack[0] = stack[-1];
    goto v_33528;
v_33529:
    goto v_33538;
v_33534:
    v_33638 = stack[-1];
    goto v_33535;
v_33536:
    v_33637 = stack[-3];
    goto v_33537;
v_33538:
    goto v_33534;
v_33535:
    goto v_33536;
v_33537:
    v_33637 = difference2(v_33638, v_33637);
    env = stack[-5];
    goto v_33530;
v_33531:
    goto v_33527;
v_33528:
    goto v_33529;
v_33530:
    v_33637 = CC_randKcomb(elt(env, 0), stack[0], v_33637);
    env = stack[-5];
    stack[-3] = v_33637;
    v_33637 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_33637;
v_33544:
    goto v_33556;
v_33552:
    v_33637 = stack[-1];
    v_33638 = sub1(v_33637);
    env = stack[-5];
    goto v_33553;
v_33554:
    v_33637 = stack[0];
    goto v_33555;
v_33556:
    goto v_33552;
v_33553:
    goto v_33554;
v_33555:
    v_33637 = difference2(v_33638, v_33637);
    env = stack[-5];
    v_33637 = Lminusp(nil, v_33637);
    env = stack[-5];
    if (v_33637 == nil) goto v_33549;
    goto v_33543;
v_33549:
    goto v_33569;
v_33565:
    v_33638 = stack[0];
    goto v_33566;
v_33567:
    v_33637 = stack[-3];
    goto v_33568;
v_33569:
    goto v_33565;
v_33566:
    goto v_33567;
v_33568:
    v_33637 = Lmember(nil, v_33638, v_33637);
    if (v_33637 == nil) goto v_33563;
    else goto v_33564;
v_33563:
    goto v_33578;
v_33574:
    v_33638 = stack[0];
    goto v_33575;
v_33576:
    v_33637 = stack[-2];
    goto v_33577;
v_33578:
    goto v_33574;
v_33575:
    goto v_33576;
v_33577:
    v_33637 = cons(v_33638, v_33637);
    env = stack[-5];
    stack[-2] = v_33637;
    goto v_33562;
v_33564:
v_33562:
    v_33637 = stack[0];
    v_33637 = add1(v_33637);
    env = stack[-5];
    stack[0] = v_33637;
    goto v_33544;
v_33543:
    goto v_33505;
v_33507:
    v_33637 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_33637;
v_33588:
    goto v_33600;
v_33596:
    v_33637 = stack[-3];
    v_33638 = sub1(v_33637);
    env = stack[-5];
    goto v_33597;
v_33598:
    v_33637 = stack[0];
    goto v_33599;
v_33600:
    goto v_33596;
v_33597:
    goto v_33598;
v_33599:
    v_33637 = difference2(v_33638, v_33637);
    env = stack[-5];
    v_33637 = Lminusp(nil, v_33637);
    env = stack[-5];
    if (v_33637 == nil) goto v_33593;
    goto v_33587;
v_33593:
v_33610:
    goto v_33620;
v_33616:
    v_33637 = stack[-1];
    fn = elt(env, 1); // random
    v_33638 = (*qfn1(fn))(fn, v_33637);
    env = stack[-5];
    v_33639 = v_33638;
    goto v_33617;
v_33618:
    v_33637 = stack[-2];
    goto v_33619;
v_33620:
    goto v_33616;
v_33617:
    goto v_33618;
v_33619:
    v_33637 = Lmember(nil, v_33638, v_33637);
    if (v_33637 == nil) goto v_33614;
    else goto v_33615;
v_33614:
    goto v_33609;
v_33615:
    goto v_33610;
v_33609:
    goto v_33631;
v_33627:
    v_33638 = v_33639;
    goto v_33628;
v_33629:
    v_33637 = stack[-2];
    goto v_33630;
v_33631:
    goto v_33627;
v_33628:
    goto v_33629;
v_33630:
    v_33637 = cons(v_33638, v_33637);
    env = stack[-5];
    stack[-2] = v_33637;
    v_33637 = stack[0];
    v_33637 = add1(v_33637);
    env = stack[-5];
    stack[0] = v_33637;
    goto v_33588;
v_33587:
    goto v_33505;
v_33505:
    v_33637 = stack[-2];
    goto v_33437;
    v_33637 = nil;
v_33437:
    return onevalue(v_33637);
}



// Code for new_provev

static LispObject CC_new_provev(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33479, v_33480, v_33481, v_33482;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33480 = v_33434;
    v_33481 = v_33433;
// end of prologue
    goto v_33444;
v_33440:
    v_33482 = v_33481;
    goto v_33441;
v_33442:
    v_33479 = v_33480;
    goto v_33443;
v_33444:
    goto v_33440;
v_33441:
    goto v_33442;
v_33443:
    v_33479 = Lmember(nil, v_33482, v_33479);
    if (v_33479 == nil) goto v_33438;
    else goto v_33439;
v_33438:
    v_33479 = nil;
    goto v_33437;
v_33439:
    goto v_33456;
v_33452:
    v_33479 = v_33481;
    v_33479 = qcdr(v_33479);
    v_33479 = qcar(v_33479);
    v_33482 = qcar(v_33479);
    goto v_33453;
v_33454:
    v_33479 = v_33480;
    goto v_33455;
v_33456:
    goto v_33452;
v_33453:
    goto v_33454;
v_33455:
    v_33479 = Lassoc(nil, v_33482, v_33479);
    if (v_33479 == nil) goto v_33450;
    goto v_33468;
v_33464:
    v_33479 = v_33481;
    v_33479 = qcdr(v_33479);
    v_33479 = qcar(v_33479);
    v_33481 = qcdr(v_33479);
    goto v_33465;
v_33466:
    v_33479 = v_33480;
    goto v_33467;
v_33468:
    goto v_33464;
v_33465:
    goto v_33466;
v_33467:
    v_33479 = Lassoc(nil, v_33481, v_33479);
    if (v_33479 == nil) goto v_33450;
    v_33479 = nil;
    goto v_33437;
v_33450:
    v_33479 = v_33480;
    goto v_33437;
    v_33479 = nil;
v_33437:
    return onevalue(v_33479);
}



// Code for allbkern

static LispObject CC_allbkern(LispObject env,
                         LispObject v_33433)
{
    env = qenv(env);
    LispObject v_33479, v_33480;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33433);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33433;
// end of prologue
    stack[-1] = nil;
v_33439:
    v_33479 = stack[0];
    if (v_33479 == nil) goto v_33444;
    else goto v_33445;
v_33444:
    goto v_33440;
v_33445:
    goto v_33452;
v_33448:
    v_33479 = stack[0];
    v_33479 = qcar(v_33479);
    v_33479 = qcar(v_33479);
    fn = elt(env, 1); // kernels
    v_33479 = (*qfn1(fn))(fn, v_33479);
    env = stack[-2];
    fn = elt(env, 2); // basic!-kern
    v_33480 = (*qfn1(fn))(fn, v_33479);
    env = stack[-2];
    goto v_33449;
v_33450:
    v_33479 = stack[-1];
    goto v_33451;
v_33452:
    goto v_33448;
v_33449:
    goto v_33450;
v_33451:
    v_33479 = cons(v_33480, v_33479);
    env = stack[-2];
    stack[-1] = v_33479;
    v_33479 = stack[0];
    v_33479 = qcdr(v_33479);
    stack[0] = v_33479;
    goto v_33439;
v_33440:
    v_33479 = nil;
    v_33480 = v_33479;
v_33441:
    v_33479 = stack[-1];
    if (v_33479 == nil) goto v_33464;
    else goto v_33465;
v_33464:
    v_33479 = v_33480;
    goto v_33438;
v_33465:
    goto v_33473;
v_33469:
    v_33479 = stack[-1];
    v_33479 = qcar(v_33479);
    goto v_33470;
v_33471:
    goto v_33472;
v_33473:
    goto v_33469;
v_33470:
    goto v_33471;
v_33472:
    fn = elt(env, 3); // union
    v_33479 = (*qfn2(fn))(fn, v_33479, v_33480);
    env = stack[-2];
    v_33480 = v_33479;
    v_33479 = stack[-1];
    v_33479 = qcdr(v_33479);
    stack[-1] = v_33479;
    goto v_33441;
v_33438:
    return onevalue(v_33479);
}



// Code for coeffs!-to!-form

static LispObject CC_coeffsKtoKform(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33457, v_33458, v_33459;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33433,v_33434);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_33458 = v_33434;
    v_33459 = v_33433;
// end of prologue
    v_33457 = v_33459;
    if (v_33457 == nil) goto v_33438;
    else goto v_33439;
v_33438:
    v_33457 = nil;
    goto v_33437;
v_33439:
    goto v_33451;
v_33445:
    stack[-1] = v_33459;
    goto v_33446;
v_33447:
    stack[0] = v_33458;
    goto v_33448;
v_33449:
    v_33457 = v_33459;
    v_33457 = Llength(nil, v_33457);
    env = stack[-2];
    v_33457 = sub1(v_33457);
    env = stack[-2];
    goto v_33450;
v_33451:
    goto v_33445;
v_33446:
    goto v_33447;
v_33448:
    goto v_33449;
v_33450:
    {
        LispObject v_33462 = stack[-1];
        LispObject v_33463 = stack[0];
        fn = elt(env, 1); // coeffs!-to!-form1
        return (*qfnn(fn))(fn, 3, v_33462, v_33463, v_33457);
    }
    v_33457 = nil;
v_33437:
    return onevalue(v_33457);
}



// Code for no_of_tm_sf

static LispObject CC_no_of_tm_sf(LispObject env,
                         LispObject v_33433)
{
    env = qenv(env);
    LispObject v_33472;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33433);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33433;
// end of prologue
    v_33472 = stack[0];
    if (v_33472 == nil) goto v_33437;
    else goto v_33438;
v_33437:
    v_33472 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33436;
v_33438:
    v_33472 = stack[0];
    v_33472 = Lconsp(nil, v_33472);
    env = stack[-2];
    if (v_33472 == nil) goto v_33445;
    else goto v_33446;
v_33445:
    v_33472 = lisp_true;
    goto v_33444;
v_33446:
    v_33472 = stack[0];
    v_33472 = qcar(v_33472);
    v_33472 = Lconsp(nil, v_33472);
    env = stack[-2];
    v_33472 = (v_33472 == nil ? lisp_true : nil);
    goto v_33444;
    v_33472 = nil;
v_33444:
    if (v_33472 == nil) goto v_33442;
    v_33472 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33436;
v_33442:
    goto v_33464;
v_33460:
    v_33472 = stack[0];
    v_33472 = qcar(v_33472);
    v_33472 = qcdr(v_33472);
    stack[-1] = CC_no_of_tm_sf(elt(env, 0), v_33472);
    env = stack[-2];
    goto v_33461;
v_33462:
    v_33472 = stack[0];
    v_33472 = qcdr(v_33472);
    v_33472 = CC_no_of_tm_sf(elt(env, 0), v_33472);
    goto v_33463;
v_33464:
    goto v_33460;
v_33461:
    goto v_33462;
v_33463:
    {
        LispObject v_33475 = stack[-1];
        return plus2(v_33475, v_33472);
    }
    v_33472 = nil;
v_33436:
    return onevalue(v_33472);
}



// Code for cde_mkset

static LispObject CC_cde_mkset(LispObject env,
                         LispObject v_33433)
{
    env = qenv(env);
    LispObject v_33477, v_33478, v_33479;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33433);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_33433;
// end of prologue
    v_33479 = nil;
v_33438:
    v_33477 = stack[0];
    if (v_33477 == nil) goto v_33442;
    goto v_33452;
v_33448:
    v_33477 = stack[0];
    v_33478 = qcar(v_33477);
    goto v_33449;
v_33450:
    v_33477 = stack[0];
    v_33477 = qcdr(v_33477);
    goto v_33451;
v_33452:
    goto v_33448;
v_33449:
    goto v_33450;
v_33451:
    v_33477 = Lmember(nil, v_33478, v_33477);
    if (v_33477 == nil) goto v_33447;
    v_33477 = stack[0];
    v_33477 = qcdr(v_33477);
    stack[0] = v_33477;
    goto v_33438;
v_33447:
    goto v_33467;
v_33463:
    v_33477 = stack[0];
    v_33477 = qcar(v_33477);
    goto v_33464;
v_33465:
    v_33478 = v_33479;
    goto v_33466;
v_33467:
    goto v_33463;
v_33464:
    goto v_33465;
v_33466:
    v_33477 = cons(v_33477, v_33478);
    env = stack[-1];
    v_33479 = v_33477;
    v_33477 = stack[0];
    v_33477 = qcdr(v_33477);
    stack[0] = v_33477;
    goto v_33438;
    goto v_33440;
v_33442:
    v_33477 = v_33479;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_33477);
    }
v_33440:
    v_33477 = nil;
    return onevalue(v_33477);
}



// Code for cl_ex

static LispObject CC_cl_ex(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33447, v_33448, v_33449;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33447 = v_33434;
    v_33448 = v_33433;
// end of prologue
    goto v_33443;
v_33437:
    v_33449 = elt(env, 1); // ex
    goto v_33438;
v_33439:
    goto v_33440;
v_33441:
    goto v_33442;
v_33443:
    goto v_33437;
v_33438:
    goto v_33439;
v_33440:
    goto v_33441;
v_33442:
    {
        fn = elt(env, 2); // cl_closure
        return (*qfnn(fn))(fn, 3, v_33449, v_33448, v_33447);
    }
}



// Code for dfmax

static LispObject CC_dfmax(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33456, v_33457, v_33458;
    LispObject fn;
    LispObject v_33435, v_33434, v_33433;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dfmax");
    va_start(aa, nargs);
    v_33433 = va_arg(aa, LispObject);
    v_33434 = va_arg(aa, LispObject);
    v_33435 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_33435,v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_33433,v_33434,v_33435);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_33456 = v_33435;
    stack[0] = v_33434;
    stack[-1] = v_33433;
// end of prologue
    goto v_33448;
v_33442:
    v_33458 = stack[-1];
    goto v_33443;
v_33444:
    v_33457 = stack[0];
    goto v_33445;
v_33446:
    goto v_33447;
v_33448:
    goto v_33442;
v_33443:
    goto v_33444;
v_33445:
    goto v_33446;
v_33447:
    fn = elt(env, 1); // dfrel
    v_33456 = (*qfnn(fn))(fn, 3, v_33458, v_33457, v_33456);
    if (v_33456 == nil) goto v_33440;
    v_33456 = stack[0];
    goto v_33438;
v_33440:
    v_33456 = stack[-1];
    goto v_33438;
    v_33456 = nil;
v_33438:
    return onevalue(v_33456);
}



// Code for rl_!*qe

static LispObject CC_rl_Hqe(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33451, v_33452;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33433,v_33434);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_33451 = v_33434;
    v_33452 = v_33433;
// end of prologue
    goto v_33441;
v_33437:
    stack[0] = elt(env, 1); // rl_qe
    goto v_33438;
v_33439:
    goto v_33448;
v_33444:
    goto v_33445;
v_33446:
    goto v_33447;
v_33448:
    goto v_33444;
v_33445:
    goto v_33446;
v_33447:
    v_33451 = list2(v_33452, v_33451);
    env = stack[-1];
    goto v_33440;
v_33441:
    goto v_33437;
v_33438:
    goto v_33439;
v_33440:
    {
        LispObject v_33454 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_33454, v_33451);
    }
}



// Code for search4facf

static LispObject CC_search4facf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33493, v_33494;
    LispObject fn;
    LispObject v_33435, v_33434, v_33433;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "search4facf");
    va_start(aa, nargs);
    v_33433 = va_arg(aa, LispObject);
    v_33434 = va_arg(aa, LispObject);
    v_33435 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_33435,v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_33433,v_33434,v_33435);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_33435;
    stack[-3] = v_33434;
    stack[-4] = v_33433;
// end of prologue
    v_33493 = stack[-3];
    if (v_33493 == nil) goto v_33439;
    else goto v_33440;
v_33439:
    goto v_33447;
v_33443:
    v_33494 = stack[-4];
    goto v_33444;
v_33445:
    v_33493 = stack[-2];
    goto v_33446;
v_33447:
    goto v_33443;
v_33444:
    goto v_33445;
v_33446:
    {
        fn = elt(env, 1); // tryfactorf
        return (*qfn2(fn))(fn, v_33494, v_33493);
    }
v_33440:
    v_33493 = stack[-3];
    v_33493 = qcar(v_33493);
    stack[-5] = v_33493;
v_33456:
    v_33493 = stack[-5];
    if (v_33493 == nil) goto v_33461;
    else goto v_33462;
v_33461:
    v_33493 = nil;
    goto v_33455;
v_33462:
    goto v_33472;
v_33466:
    stack[-1] = stack[-4];
    goto v_33467;
v_33468:
    v_33493 = stack[-3];
    stack[0] = qcdr(v_33493);
    goto v_33469;
v_33470:
    goto v_33481;
v_33477:
    v_33493 = stack[-5];
    v_33494 = qcar(v_33493);
    goto v_33478;
v_33479:
    v_33493 = stack[-2];
    goto v_33480;
v_33481:
    goto v_33477;
v_33478:
    goto v_33479;
v_33480:
    v_33493 = cons(v_33494, v_33493);
    env = stack[-6];
    goto v_33471;
v_33472:
    goto v_33466;
v_33467:
    goto v_33468;
v_33469:
    goto v_33470;
v_33471:
    v_33493 = CC_search4facf(elt(env, 0), 3, stack[-1], stack[0], v_33493);
    env = stack[-6];
    v_33494 = v_33493;
    v_33493 = v_33494;
    if (v_33493 == nil) goto v_33487;
    else goto v_33488;
v_33487:
    v_33493 = stack[-5];
    v_33493 = qcdr(v_33493);
    stack[-5] = v_33493;
    goto v_33456;
v_33488:
    v_33493 = v_33494;
v_33455:
    goto v_33438;
    v_33493 = nil;
v_33438:
    return onevalue(v_33493);
}



// Code for rewrite2

static LispObject CC_rewrite2(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33489, v_33490;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33433,v_33434);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_33434;
    v_33489 = v_33433;
// end of prologue
    stack[-1] = nil;
    stack[0] = v_33489;
v_33445:
    v_33489 = stack[0];
    if (v_33489 == nil) goto v_33449;
    else goto v_33450;
v_33449:
    goto v_33444;
v_33450:
    v_33489 = stack[0];
    v_33489 = qcar(v_33489);
    v_33490 = v_33489;
    v_33489 = v_33490;
    v_33489 = qcdr(v_33489);
    stack[-3] = v_33489;
    v_33489 = v_33490;
    v_33489 = qcar(v_33489);
    goto v_33465;
v_33461:
    v_33490 = v_33489;
    goto v_33462;
v_33463:
    v_33489 = stack[-2];
    goto v_33464;
v_33465:
    goto v_33461;
v_33462:
    goto v_33463;
v_33464:
    v_33489 = plus2(v_33490, v_33489);
    env = stack[-4];
    goto v_33473;
v_33469:
    v_33490 = v_33489;
    goto v_33470;
v_33471:
    v_33489 = stack[-3];
    goto v_33472;
v_33473:
    goto v_33469;
v_33470:
    goto v_33471;
v_33472:
    v_33489 = cons(v_33490, v_33489);
    env = stack[-4];
    goto v_33481;
v_33477:
    v_33490 = v_33489;
    goto v_33478;
v_33479:
    v_33489 = stack[-1];
    goto v_33480;
v_33481:
    goto v_33477;
v_33478:
    goto v_33479;
v_33480:
    v_33489 = cons(v_33490, v_33489);
    env = stack[-4];
    stack[-1] = v_33489;
    v_33489 = stack[0];
    v_33489 = qcdr(v_33489);
    stack[0] = v_33489;
    goto v_33445;
v_33444:
    v_33489 = stack[-1];
        return Lreverse(nil, v_33489);
    return onevalue(v_33489);
}



// Code for column_dim

static LispObject CC_column_dim(LispObject env,
                         LispObject v_33433)
{
    env = qenv(env);
    LispObject v_33458;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33433);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_33433;
// end of prologue
    v_33458 = qvalue(elt(env, 1)); // !*fast_la
    if (v_33458 == nil) goto v_33443;
    else goto v_33444;
v_33443:
    v_33458 = stack[0];
    fn = elt(env, 3); // matrixp
    v_33458 = (*qfn1(fn))(fn, v_33458);
    env = stack[-1];
    v_33458 = (v_33458 == nil ? lisp_true : nil);
    goto v_33442;
v_33444:
    v_33458 = nil;
    goto v_33442;
    v_33458 = nil;
v_33442:
    if (v_33458 == nil) goto v_33440;
    v_33458 = elt(env, 2); // "Error in column_dim: input should be a matrix."
    fn = elt(env, 4); // rederr
    v_33458 = (*qfn1(fn))(fn, v_33458);
    env = stack[-1];
    goto v_33438;
v_33440:
v_33438:
    v_33458 = stack[0];
    fn = elt(env, 5); // size_of_matrix
    v_33458 = (*qfn1(fn))(fn, v_33458);
    v_33458 = qcdr(v_33458);
    v_33458 = qcar(v_33458);
    return onevalue(v_33458);
}



// Code for gvarlis

static LispObject CC_gvarlis(LispObject env,
                         LispObject v_33433)
{
    env = qenv(env);
    LispObject v_33450, v_33451;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33433);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_33450 = v_33433;
// end of prologue
    goto v_33440;
v_33436:
    goto v_33446;
v_33442:
    v_33451 = v_33450;
    goto v_33443;
v_33444:
    v_33450 = nil;
    goto v_33445;
v_33446:
    goto v_33442;
v_33443:
    goto v_33444;
v_33445:
    fn = elt(env, 2); // gvarlis1
    v_33451 = (*qfn2(fn))(fn, v_33451, v_33450);
    env = stack[0];
    goto v_33437;
v_33438:
    v_33450 = elt(env, 1); // ordop
    goto v_33439;
v_33440:
    goto v_33436;
v_33437:
    goto v_33438;
v_33439:
    {
        fn = elt(env, 3); // sort
        return (*qfn2(fn))(fn, v_33451, v_33450);
    }
}



// Code for weak_xreduce

static LispObject CC_weak_xreduce(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33500, v_33501, v_33502;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33433,v_33434);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_33434;
    stack[-1] = v_33433;
// end of prologue
    v_33500 = nil;
    v_33500 = ncons(v_33500);
    env = stack[-3];
    stack[-2] = v_33500;
    v_33500 = qvalue(elt(env, 1)); // !*trxmod
    if (v_33500 == nil) goto v_33445;
    goto v_33452;
v_33448:
    v_33500 = stack[-1];
    fn = elt(env, 6); // preppf
    v_33500 = (*qfn1(fn))(fn, v_33500);
    env = stack[-3];
    v_33501 = Lmkquote(nil, v_33500);
    env = stack[-3];
    goto v_33449;
v_33450:
    v_33500 = nil;
    goto v_33451;
v_33452:
    goto v_33448;
v_33449:
    goto v_33450;
v_33451:
    fn = elt(env, 7); // writepri
    v_33500 = (*qfn2(fn))(fn, v_33501, v_33500);
    env = stack[-3];
    goto v_33462;
v_33458:
    v_33501 = elt(env, 2); // " ="
    goto v_33459;
v_33460:
    v_33500 = elt(env, 3); // last
    goto v_33461;
v_33462:
    goto v_33458;
v_33459:
    goto v_33460;
v_33461:
    fn = elt(env, 7); // writepri
    v_33500 = (*qfn2(fn))(fn, v_33501, v_33500);
    env = stack[-3];
    goto v_33443;
v_33445:
v_33443:
    goto v_33472;
v_33466:
    v_33502 = stack[-1];
    goto v_33467;
v_33468:
    v_33501 = stack[0];
    goto v_33469;
v_33470:
    v_33500 = stack[-2];
    goto v_33471;
v_33472:
    goto v_33466;
v_33467:
    goto v_33468;
v_33469:
    goto v_33470;
v_33471:
    fn = elt(env, 8); // weak_xreduce1
    v_33500 = (*qfnn(fn))(fn, 3, v_33502, v_33501, v_33500);
    env = stack[-3];
    stack[0] = v_33500;
    v_33500 = qvalue(elt(env, 1)); // !*trxmod
    if (v_33500 == nil) goto v_33479;
    goto v_33486;
v_33482:
    v_33501 = elt(env, 4); // "   "
    goto v_33483;
v_33484:
    v_33500 = elt(env, 5); // first
    goto v_33485;
v_33486:
    goto v_33482;
v_33483:
    goto v_33484;
v_33485:
    fn = elt(env, 7); // writepri
    v_33500 = (*qfn2(fn))(fn, v_33501, v_33500);
    env = stack[-3];
    goto v_33494;
v_33490:
    v_33500 = stack[0];
    fn = elt(env, 6); // preppf
    v_33500 = (*qfn1(fn))(fn, v_33500);
    env = stack[-3];
    v_33501 = Lmkquote(nil, v_33500);
    env = stack[-3];
    goto v_33491;
v_33492:
    v_33500 = elt(env, 3); // last
    goto v_33493;
v_33494:
    goto v_33490;
v_33491:
    goto v_33492;
v_33493:
    fn = elt(env, 7); // writepri
    v_33500 = (*qfn2(fn))(fn, v_33501, v_33500);
    goto v_33477;
v_33479:
v_33477:
    v_33500 = stack[0];
    return onevalue(v_33500);
}



// Code for tvectorp

static LispObject CC_tvectorp(LispObject env,
                         LispObject v_33433)
{
    env = qenv(env);
    LispObject v_33456, v_33457;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33433);
    }
// copy arguments values to proper place
    v_33456 = v_33433;
// end of prologue
    v_33456 = qcar(v_33456);
    v_33456 = qcar(v_33456);
    fn = elt(env, 1); // deg!*form
    v_33456 = (*qfn1(fn))(fn, v_33456);
    v_33457 = v_33456;
    v_33456 = v_33457;
    if (is_number(v_33456)) goto v_33443;
    v_33456 = nil;
    goto v_33441;
v_33443:
    goto v_33453;
v_33449:
    goto v_33450;
v_33451:
    v_33456 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33452;
v_33453:
    goto v_33449;
v_33450:
    goto v_33451;
v_33452:
        return Llessp(nil, v_33457, v_33456);
    v_33456 = nil;
v_33441:
    return onevalue(v_33456);
}



// Code for ev!-tades

static LispObject CC_evKtades(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33482, v_33483, v_33484;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33433,v_33434);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_33434;
    stack[-1] = v_33433;
// end of prologue
    stack[-2] = nil;
v_33439:
    v_33482 = stack[-1];
    if (v_33482 == nil) goto v_33442;
    else goto v_33443;
v_33442:
    goto v_33450;
v_33446:
    stack[0] = stack[-2];
    goto v_33447;
v_33448:
    v_33482 = (LispObject)16+TAG_FIXNUM; // 1
    v_33482 = ncons(v_33482);
    env = stack[-3];
    goto v_33449;
v_33450:
    goto v_33446;
v_33447:
    goto v_33448;
v_33449:
    {
        LispObject v_33488 = stack[0];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_33488, v_33482);
    }
v_33443:
    goto v_33461;
v_33457:
    goto v_33467;
v_33463:
    v_33484 = qvalue(elt(env, 1)); // ndim!*
    goto v_33464;
v_33465:
    goto v_33473;
v_33469:
    v_33482 = stack[-1];
    v_33483 = qcar(v_33482);
    goto v_33470;
v_33471:
    v_33482 = stack[0];
    goto v_33472;
v_33473:
    goto v_33469;
v_33470:
    goto v_33471;
v_33472:
    v_33482 = Lassoc(nil, v_33483, v_33482);
    v_33482 = qcdr(v_33482);
    goto v_33466;
v_33467:
    goto v_33463;
v_33464:
    goto v_33465;
v_33466:
    fn = elt(env, 3); // binc
    v_33483 = (*qfn2(fn))(fn, v_33484, v_33482);
    env = stack[-3];
    goto v_33458;
v_33459:
    v_33482 = stack[-2];
    goto v_33460;
v_33461:
    goto v_33457;
v_33458:
    goto v_33459;
v_33460:
    v_33482 = cons(v_33483, v_33482);
    env = stack[-3];
    stack[-2] = v_33482;
    v_33482 = stack[-1];
    v_33482 = qcdr(v_33482);
    stack[-1] = v_33482;
    goto v_33439;
    v_33482 = nil;
    return onevalue(v_33482);
}



// Code for restore_props

static LispObject CC_restore_props(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_33486, v_33487, v_33488;
    argcheck(nargs, 0, "restore_props");
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
    v_33486 = qvalue(elt(env, 1)); // props!*
    stack[-1] = v_33486;
v_33437:
    v_33486 = stack[-1];
    if (v_33486 == nil) goto v_33441;
    else goto v_33442;
v_33441:
    v_33486 = nil;
    goto v_33436;
v_33442:
    v_33486 = stack[-1];
    v_33486 = qcar(v_33486);
    stack[0] = v_33486;
    v_33486 = stack[0];
    v_33486 = qcdr(v_33486);
    v_33486 = Lconsp(nil, v_33486);
    env = stack[-2];
    if (v_33486 == nil) goto v_33451;
    goto v_33462;
v_33456:
    v_33486 = stack[0];
    v_33488 = qcar(v_33486);
    goto v_33457;
v_33458:
    v_33486 = stack[0];
    v_33486 = qcdr(v_33486);
    v_33487 = qcar(v_33486);
    goto v_33459;
v_33460:
    v_33486 = stack[0];
    v_33486 = qcdr(v_33486);
    v_33486 = qcdr(v_33486);
    goto v_33461;
v_33462:
    goto v_33456;
v_33457:
    goto v_33458;
v_33459:
    goto v_33460;
v_33461:
    v_33486 = Lputprop(nil, 3, v_33488, v_33487, v_33486);
    env = stack[-2];
    goto v_33449;
v_33451:
    goto v_33478;
v_33474:
    v_33486 = stack[0];
    v_33486 = qcar(v_33486);
    v_33487 = ncons(v_33486);
    env = stack[-2];
    goto v_33475;
v_33476:
    v_33486 = stack[0];
    v_33486 = qcdr(v_33486);
    goto v_33477;
v_33478:
    goto v_33474;
v_33475:
    goto v_33476;
v_33477:
    v_33486 = Lflag(nil, v_33487, v_33486);
    env = stack[-2];
    goto v_33449;
v_33449:
    v_33486 = stack[-1];
    v_33486 = qcdr(v_33486);
    stack[-1] = v_33486;
    goto v_33437;
v_33436:
    return onevalue(v_33486);
}



// Code for reprod

static LispObject CC_reprod(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33465, v_33466;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33433,v_33434);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33434;
    stack[-1] = v_33433;
// end of prologue
v_33438:
    v_33465 = stack[-1];
    if (v_33465 == nil) goto v_33441;
    else goto v_33442;
v_33441:
    goto v_33437;
v_33442:
    goto v_33450;
v_33446:
    goto v_33457;
v_33453:
    v_33465 = stack[-1];
    v_33466 = qcar(v_33465);
    goto v_33454;
v_33455:
    v_33465 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33456;
v_33457:
    goto v_33453;
v_33454:
    goto v_33455;
v_33456:
    v_33465 = cons(v_33466, v_33465);
    env = stack[-2];
    v_33466 = ncons(v_33465);
    env = stack[-2];
    goto v_33447;
v_33448:
    v_33465 = stack[0];
    goto v_33449;
v_33450:
    goto v_33446;
v_33447:
    goto v_33448;
v_33449:
    fn = elt(env, 1); // multf
    v_33465 = (*qfn2(fn))(fn, v_33466, v_33465);
    env = stack[-2];
    stack[0] = v_33465;
    v_33465 = stack[-1];
    v_33465 = qcdr(v_33465);
    stack[-1] = v_33465;
    goto v_33438;
v_33437:
    v_33465 = stack[0];
    return onevalue(v_33465);
}



// Code for mo_from_ei

static LispObject CC_mo_from_ei(LispObject env,
                         LispObject v_33433)
{
    env = qenv(env);
    LispObject v_33461, v_33462, v_33463;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33433);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_33463 = v_33433;
// end of prologue
    goto v_33443;
v_33439:
    v_33462 = v_33463;
    goto v_33440;
v_33441:
    v_33461 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33442;
v_33443:
    goto v_33439;
v_33440:
    goto v_33441;
v_33442:
    if (v_33462 == v_33461) goto v_33437;
    else goto v_33438;
v_33437:
    {
        fn = elt(env, 1); // mo_zero
        return (*qfnn(fn))(fn, 0);
    }
v_33438:
    v_33461 = v_33463;
    v_33461 = ncons(v_33461);
    env = stack[-1];
    goto v_33457;
v_33453:
    stack[0] = v_33461;
    goto v_33454;
v_33455:
    fn = elt(env, 2); // mo!=deglist
    v_33461 = (*qfn1(fn))(fn, v_33461);
    goto v_33456;
v_33457:
    goto v_33453;
v_33454:
    goto v_33455;
v_33456:
    {
        LispObject v_33465 = stack[0];
        return cons(v_33465, v_33461);
    }
    v_33461 = nil;
    return onevalue(v_33461);
}



// Code for pa_vect2list

static LispObject CC_pa_vect2list(LispObject env,
                         LispObject v_33433)
{
    env = qenv(env);
    LispObject v_33566, v_33567;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33433);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_33433;
// end of prologue
    v_33566 = stack[-6];
    v_33566 = qcdr(v_33566);
    fn = elt(env, 1); // upbve
    v_33566 = (*qfn1(fn))(fn, v_33566);
    env = stack[-8];
    v_33566 = sub1(v_33566);
    env = stack[-8];
    v_33566 = Lmkvect(nil, v_33566);
    env = stack[-8];
    stack[-7] = v_33566;
    v_33566 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_33566;
v_33450:
    goto v_33462;
v_33458:
    v_33566 = stack[-6];
    v_33566 = qcdr(v_33566);
    fn = elt(env, 1); // upbve
    v_33567 = (*qfn1(fn))(fn, v_33566);
    env = stack[-8];
    goto v_33459;
v_33460:
    v_33566 = stack[-4];
    goto v_33461;
v_33462:
    goto v_33458;
v_33459:
    goto v_33460;
v_33461:
    v_33566 = difference2(v_33567, v_33566);
    env = stack[-8];
    v_33566 = Lminusp(nil, v_33566);
    env = stack[-8];
    if (v_33566 == nil) goto v_33455;
    goto v_33449;
v_33455:
    goto v_33472;
v_33468:
    v_33566 = stack[-6];
    stack[0] = qcdr(v_33566);
    goto v_33469;
v_33470:
    v_33566 = stack[-4];
    v_33566 = sub1(v_33566);
    env = stack[-8];
    goto v_33471;
v_33472:
    goto v_33468;
v_33469:
    goto v_33470;
v_33471:
    v_33566 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_33566-TAG_FIXNUM)/(16/CELL)));
    stack[-5] = v_33566;
    goto v_33484;
v_33478:
    stack[-3] = stack[-7];
    goto v_33479;
v_33480:
    v_33566 = stack[-5];
    stack[-2] = sub1(v_33566);
    env = stack[-8];
    goto v_33481;
v_33482:
    goto v_33493;
v_33489:
    stack[-1] = stack[-4];
    goto v_33490;
v_33491:
    goto v_33499;
v_33495:
    stack[0] = stack[-7];
    goto v_33496;
v_33497:
    v_33566 = stack[-5];
    v_33566 = sub1(v_33566);
    env = stack[-8];
    goto v_33498;
v_33499:
    goto v_33495;
v_33496:
    goto v_33497;
v_33498:
    v_33566 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_33566-TAG_FIXNUM)/(16/CELL)));
    goto v_33492;
v_33493:
    goto v_33489;
v_33490:
    goto v_33491;
v_33492:
    v_33566 = cons(stack[-1], v_33566);
    env = stack[-8];
    goto v_33483;
v_33484:
    goto v_33478;
v_33479:
    goto v_33480;
v_33481:
    goto v_33482;
v_33483:
    *(LispObject *)((char *)stack[-3] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-2]-TAG_FIXNUM)/(16/CELL))) = v_33566;
    v_33566 = stack[-4];
    v_33566 = add1(v_33566);
    env = stack[-8];
    stack[-4] = v_33566;
    goto v_33450;
v_33449:
    v_33566 = stack[-6];
    v_33566 = qcar(v_33566);
    stack[-4] = v_33566;
    v_33566 = stack[-4];
    if (v_33566 == nil) goto v_33517;
    else goto v_33518;
v_33517:
    v_33566 = nil;
    goto v_33511;
v_33518:
    v_33566 = stack[-4];
    v_33566 = qcar(v_33566);
    goto v_33530;
v_33526:
    stack[0] = stack[-7];
    goto v_33527;
v_33528:
    v_33566 = sub1(v_33566);
    env = stack[-8];
    goto v_33529;
v_33530:
    goto v_33526;
v_33527:
    goto v_33528;
v_33529:
    v_33566 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_33566-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 2); // ordn
    v_33566 = (*qfn1(fn))(fn, v_33566);
    env = stack[-8];
    v_33566 = ncons(v_33566);
    env = stack[-8];
    stack[-2] = v_33566;
    stack[-3] = v_33566;
v_33512:
    v_33566 = stack[-4];
    v_33566 = qcdr(v_33566);
    stack[-4] = v_33566;
    v_33566 = stack[-4];
    if (v_33566 == nil) goto v_33539;
    else goto v_33540;
v_33539:
    v_33566 = stack[-3];
    goto v_33511;
v_33540:
    goto v_33548;
v_33544:
    stack[-1] = stack[-2];
    goto v_33545;
v_33546:
    v_33566 = stack[-4];
    v_33566 = qcar(v_33566);
    goto v_33559;
v_33555:
    stack[0] = stack[-7];
    goto v_33556;
v_33557:
    v_33566 = sub1(v_33566);
    env = stack[-8];
    goto v_33558;
v_33559:
    goto v_33555;
v_33556:
    goto v_33557;
v_33558:
    v_33566 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_33566-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 2); // ordn
    v_33566 = (*qfn1(fn))(fn, v_33566);
    env = stack[-8];
    v_33566 = ncons(v_33566);
    env = stack[-8];
    goto v_33547;
v_33548:
    goto v_33544;
v_33545:
    goto v_33546;
v_33547:
    v_33566 = Lrplacd(nil, stack[-1], v_33566);
    env = stack[-8];
    v_33566 = stack[-2];
    v_33566 = qcdr(v_33566);
    stack[-2] = v_33566;
    goto v_33512;
v_33511:
    return onevalue(v_33566);
}



// Code for remk

static LispObject CC_remk(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33550, v_33551;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33433,v_33434);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_33434;
    stack[-5] = v_33433;
// end of prologue
    v_33550 = stack[-4];
    v_33550 = qcar(v_33550);
    v_33550 = qcdr(v_33550);
    stack[-6] = v_33550;
    v_33550 = stack[-4];
    v_33550 = qcar(v_33550);
    v_33550 = qcar(v_33550);
    v_33550 = qcar(v_33550);
    stack[-3] = v_33550;
    v_33550 = stack[-4];
    v_33550 = qcar(v_33550);
    v_33550 = qcar(v_33550);
    v_33550 = qcdr(v_33550);
    stack[0] = v_33550;
v_33458:
    goto v_33468;
v_33464:
    goto v_33474;
v_33470:
    goto v_33480;
v_33476:
    v_33551 = stack[-5];
    goto v_33477;
v_33478:
    v_33550 = stack[-3];
    goto v_33479;
v_33480:
    goto v_33476;
v_33477:
    goto v_33478;
v_33479:
    fn = elt(env, 1); // degr
    v_33551 = (*qfn2(fn))(fn, v_33551, v_33550);
    env = stack[-7];
    goto v_33471;
v_33472:
    v_33550 = stack[0];
    goto v_33473;
v_33474:
    goto v_33470;
v_33471:
    goto v_33472;
v_33473:
    v_33551 = difference2(v_33551, v_33550);
    env = stack[-7];
    stack[-1] = v_33551;
    goto v_33465;
v_33466:
    v_33550 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33467;
v_33468:
    goto v_33464;
v_33465:
    goto v_33466;
v_33467:
    v_33550 = (LispObject)geq2(v_33551, v_33550);
    v_33550 = v_33550 ? lisp_true : nil;
    env = stack[-7];
    if (v_33550 == nil) goto v_33461;
    else goto v_33462;
v_33461:
    goto v_33457;
v_33462:
    goto v_33492;
v_33488:
    v_33550 = stack[-5];
    v_33550 = qcar(v_33550);
    v_33551 = qcdr(v_33550);
    goto v_33489;
v_33490:
    v_33550 = stack[-4];
    v_33550 = qcdr(v_33550);
    goto v_33491;
v_33492:
    goto v_33488;
v_33489:
    goto v_33490;
v_33491:
    fn = elt(env, 2); // multf
    v_33550 = (*qfn2(fn))(fn, v_33551, v_33550);
    env = stack[-7];
    fn = elt(env, 3); // negf
    v_33550 = (*qfn1(fn))(fn, v_33550);
    env = stack[-7];
    stack[-2] = v_33550;
    goto v_33507;
v_33503:
    v_33551 = stack[-1];
    goto v_33504;
v_33505:
    v_33550 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_33506;
v_33507:
    goto v_33503;
v_33504:
    goto v_33505;
v_33506:
    v_33550 = (LispObject)greaterp2(v_33551, v_33550);
    v_33550 = v_33550 ? lisp_true : nil;
    env = stack[-7];
    if (v_33550 == nil) goto v_33501;
    goto v_33515;
v_33511:
    goto v_33522;
v_33518:
    goto v_33528;
v_33524:
    v_33551 = stack[-3];
    goto v_33525;
v_33526:
    v_33550 = stack[-1];
    goto v_33527;
v_33528:
    goto v_33524;
v_33525:
    goto v_33526;
v_33527:
    fn = elt(env, 4); // to
    v_33551 = (*qfn2(fn))(fn, v_33551, v_33550);
    env = stack[-7];
    goto v_33519;
v_33520:
    v_33550 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33521;
v_33522:
    goto v_33518;
v_33519:
    goto v_33520;
v_33521:
    v_33550 = cons(v_33551, v_33550);
    env = stack[-7];
    v_33551 = ncons(v_33550);
    env = stack[-7];
    goto v_33512;
v_33513:
    v_33550 = stack[-2];
    goto v_33514;
v_33515:
    goto v_33511;
v_33512:
    goto v_33513;
v_33514:
    fn = elt(env, 2); // multf
    v_33550 = (*qfn2(fn))(fn, v_33551, v_33550);
    env = stack[-7];
    stack[-2] = v_33550;
    goto v_33499;
v_33501:
v_33499:
    goto v_33538;
v_33534:
    goto v_33544;
v_33540:
    v_33551 = stack[-6];
    goto v_33541;
v_33542:
    v_33550 = stack[-5];
    v_33550 = qcdr(v_33550);
    goto v_33543;
v_33544:
    goto v_33540;
v_33541:
    goto v_33542;
v_33543:
    fn = elt(env, 2); // multf
    v_33551 = (*qfn2(fn))(fn, v_33551, v_33550);
    env = stack[-7];
    goto v_33535;
v_33536:
    v_33550 = stack[-2];
    goto v_33537;
v_33538:
    goto v_33534;
v_33535:
    goto v_33536;
v_33537:
    fn = elt(env, 5); // addf
    v_33550 = (*qfn2(fn))(fn, v_33551, v_33550);
    env = stack[-7];
    stack[-5] = v_33550;
    goto v_33458;
v_33457:
    v_33550 = stack[-5];
    return onevalue(v_33550);
}



// Code for modroots1

static LispObject CC_modroots1(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33686, v_33687, v_33688;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33433,v_33434);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(13);
// copy arguments values to proper place
    stack[-1] = v_33434;
    stack[-10] = v_33433;
// end of prologue
    v_33686 = stack[-1];
    v_33686 = qcdr(v_33686);
    if (v_33686 == nil) goto v_33438;
    else goto v_33439;
v_33438:
    goto v_33449;
v_33443:
    v_33688 = stack[-10];
    goto v_33444;
v_33445:
    v_33686 = stack[-1];
    v_33687 = qcar(v_33686);
    goto v_33446;
v_33447:
    v_33686 = nil;
    goto v_33448;
v_33449:
    goto v_33443;
v_33444:
    goto v_33445;
v_33446:
    goto v_33447;
v_33448:
    {
        fn = elt(env, 4); // modroots2
        return (*qfnn(fn))(fn, 3, v_33688, v_33687, v_33686);
    }
v_33439:
    stack[-7] = nil;
    v_33686 = stack[-1];
    v_33686 = qcar(v_33686);
    stack[-11] = v_33686;
    v_33686 = stack[-1];
    v_33686 = qcdr(v_33686);
    stack[-1] = v_33686;
    goto v_33475;
v_33471:
    v_33687 = stack[-10];
    goto v_33472;
v_33473:
    v_33686 = stack[-1];
    goto v_33474;
v_33475:
    goto v_33471;
v_33472:
    goto v_33473;
v_33474:
    v_33686 = CC_modroots1(elt(env, 0), v_33687, v_33686);
    env = stack[-12];
    stack[0] = v_33686;
    v_33686 = stack[0];
    if (v_33686 == nil) goto v_33480;
    else goto v_33481;
v_33480:
    v_33686 = nil;
    goto v_33465;
v_33481:
    v_33686 = stack[-10];
    v_33686 = qcar(v_33686);
    v_33686 = qcar(v_33686);
    v_33686 = qcar(v_33686);
    stack[-6] = v_33686;
    v_33686 = elt(env, 1); // g
    v_33686 = Lgensym1(nil, v_33686);
    env = stack[-12];
    stack[-5] = v_33686;
    v_33686 = stack[-1];
    stack[-1] = v_33686;
    v_33686 = (LispObject)16+TAG_FIXNUM; // 1
    v_33687 = v_33686;
v_33494:
    v_33686 = stack[-1];
    if (v_33686 == nil) goto v_33499;
    else goto v_33500;
v_33499:
    v_33686 = v_33687;
    goto v_33493;
v_33500:
    goto v_33508;
v_33504:
    v_33686 = stack[-1];
    v_33686 = qcar(v_33686);
    goto v_33505;
v_33506:
    goto v_33507;
v_33508:
    goto v_33504;
v_33505:
    goto v_33506;
v_33507:
    v_33686 = times2(v_33686, v_33687);
    env = stack[-12];
    v_33687 = v_33686;
    v_33686 = stack[-1];
    v_33686 = qcdr(v_33686);
    stack[-1] = v_33686;
    goto v_33494;
v_33493:
    stack[-9] = v_33686;
    goto v_33521;
v_33517:
    v_33687 = stack[-11];
    goto v_33518;
v_33519:
    v_33686 = stack[-9];
    goto v_33520;
v_33521:
    goto v_33517;
v_33518:
    goto v_33519;
v_33520:
    v_33686 = times2(v_33687, v_33686);
    env = stack[-12];
    stack[-8] = v_33686;
    v_33686 = stack[0];
    stack[-4] = v_33686;
v_33527:
    v_33686 = stack[-4];
    if (v_33686 == nil) goto v_33531;
    else goto v_33532;
v_33531:
    goto v_33526;
v_33532:
    v_33686 = stack[-4];
    v_33686 = qcar(v_33686);
    stack[-3] = v_33686;
    goto v_33543;
v_33539:
    stack[-2] = stack[-10];
    goto v_33540;
v_33541:
    goto v_33553;
v_33547:
    stack[-1] = stack[-6];
    goto v_33548;
v_33549:
    stack[0] = elt(env, 2); // plus
    goto v_33550;
v_33551:
    goto v_33561;
v_33557:
    goto v_33569;
v_33563:
    v_33688 = elt(env, 3); // times
    goto v_33564;
v_33565:
    v_33687 = stack[-5];
    goto v_33566;
v_33567:
    v_33686 = stack[-9];
    goto v_33568;
v_33569:
    goto v_33563;
v_33564:
    goto v_33565;
v_33566:
    goto v_33567;
v_33568:
    v_33687 = list3(v_33688, v_33687, v_33686);
    env = stack[-12];
    goto v_33558;
v_33559:
    v_33686 = stack[-3];
    goto v_33560;
v_33561:
    goto v_33557;
v_33558:
    goto v_33559;
v_33560:
    v_33686 = list2(v_33687, v_33686);
    env = stack[-12];
    goto v_33552;
v_33553:
    goto v_33547;
v_33548:
    goto v_33549;
v_33550:
    goto v_33551;
v_33552:
    v_33686 = list2star(stack[-1], stack[0], v_33686);
    env = stack[-12];
    v_33686 = ncons(v_33686);
    env = stack[-12];
    goto v_33542;
v_33543:
    goto v_33539;
v_33540:
    goto v_33541;
v_33542:
    fn = elt(env, 5); // subf
    v_33686 = (*qfn2(fn))(fn, stack[-2], v_33686);
    env = stack[-12];
    v_33686 = qcar(v_33686);
    goto v_33586;
v_33580:
    goto v_33592;
v_33588:
    v_33687 = v_33686;
    goto v_33589;
v_33590:
    v_33686 = stack[-11];
    goto v_33591;
v_33592:
    goto v_33588;
v_33589:
    goto v_33590;
v_33591:
    fn = elt(env, 6); // reduce!-mod!-p!*
    v_33688 = (*qfn2(fn))(fn, v_33687, v_33686);
    env = stack[-12];
    goto v_33581;
v_33582:
    v_33687 = stack[-11];
    goto v_33583;
v_33584:
    v_33686 = lisp_true;
    goto v_33585;
v_33586:
    goto v_33580;
v_33581:
    goto v_33582;
v_33583:
    goto v_33584;
v_33585:
    fn = elt(env, 4); // modroots2
    v_33686 = (*qfnn(fn))(fn, 3, v_33688, v_33687, v_33686);
    env = stack[-12];
    stack[-2] = v_33686;
v_33578:
    v_33686 = stack[-2];
    if (v_33686 == nil) goto v_33599;
    else goto v_33600;
v_33599:
    goto v_33577;
v_33600:
    v_33686 = stack[-2];
    v_33686 = qcar(v_33686);
    stack[-1] = v_33686;
    goto v_33611;
v_33607:
    goto v_33617;
v_33613:
    goto v_33623;
v_33619:
    v_33687 = stack[-1];
    goto v_33620;
v_33621:
    v_33686 = stack[-9];
    goto v_33622;
v_33623:
    goto v_33619;
v_33620:
    goto v_33621;
v_33622:
    v_33687 = times2(v_33687, v_33686);
    env = stack[-12];
    goto v_33614;
v_33615:
    v_33686 = stack[-3];
    goto v_33616;
v_33617:
    goto v_33613;
v_33614:
    goto v_33615;
v_33616:
    v_33687 = plus2(v_33687, v_33686);
    env = stack[-12];
    goto v_33608;
v_33609:
    v_33686 = stack[-8];
    goto v_33610;
v_33611:
    goto v_33607;
v_33608:
    goto v_33609;
v_33610:
    fn = elt(env, 7); // modp
    v_33686 = (*qfn2(fn))(fn, v_33687, v_33686);
    env = stack[-12];
    stack[-1] = v_33686;
    goto v_33641;
v_33637:
    goto v_33647;
v_33643:
    stack[0] = stack[-10];
    goto v_33644;
v_33645:
    goto v_33655;
v_33651:
    v_33687 = stack[-6];
    goto v_33652;
v_33653:
    v_33686 = stack[-1];
    goto v_33654;
v_33655:
    goto v_33651;
v_33652:
    goto v_33653;
v_33654:
    v_33686 = cons(v_33687, v_33686);
    env = stack[-12];
    v_33686 = ncons(v_33686);
    env = stack[-12];
    goto v_33646;
v_33647:
    goto v_33643;
v_33644:
    goto v_33645;
v_33646:
    fn = elt(env, 5); // subf
    v_33686 = (*qfn2(fn))(fn, stack[0], v_33686);
    env = stack[-12];
    v_33687 = qcar(v_33686);
    goto v_33638;
v_33639:
    v_33686 = stack[-8];
    goto v_33640;
v_33641:
    goto v_33637;
v_33638:
    goto v_33639;
v_33640:
    fn = elt(env, 6); // reduce!-mod!-p!*
    v_33686 = (*qfn2(fn))(fn, v_33687, v_33686);
    env = stack[-12];
    if (v_33686 == nil) goto v_33634;
    else goto v_33635;
v_33634:
    goto v_33664;
v_33660:
    v_33687 = stack[-1];
    goto v_33661;
v_33662:
    v_33686 = stack[-7];
    goto v_33663;
v_33664:
    goto v_33660;
v_33661:
    goto v_33662;
v_33663:
    v_33686 = Lmember(nil, v_33687, v_33686);
    v_33686 = (v_33686 == nil ? lisp_true : nil);
    goto v_33633;
v_33635:
    v_33686 = nil;
    goto v_33633;
    v_33686 = nil;
v_33633:
    if (v_33686 == nil) goto v_33631;
    goto v_33677;
v_33673:
    v_33687 = stack[-1];
    goto v_33674;
v_33675:
    v_33686 = stack[-7];
    goto v_33676;
v_33677:
    goto v_33673;
v_33674:
    goto v_33675;
v_33676:
    v_33686 = cons(v_33687, v_33686);
    env = stack[-12];
    stack[-7] = v_33686;
    goto v_33629;
v_33631:
v_33629:
    v_33686 = stack[-2];
    v_33686 = qcdr(v_33686);
    stack[-2] = v_33686;
    goto v_33578;
v_33577:
    v_33686 = stack[-4];
    v_33686 = qcdr(v_33686);
    stack[-4] = v_33686;
    goto v_33527;
v_33526:
    v_33686 = stack[-7];
v_33465:
    goto v_33437;
    v_33686 = nil;
v_33437:
    return onevalue(v_33686);
}



// Code for anu_mk

static LispObject CC_anu_mk(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33447, v_33448, v_33449;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33447 = v_33434;
    v_33448 = v_33433;
// end of prologue
    goto v_33443;
v_33437:
    v_33449 = elt(env, 1); // anu
    goto v_33438;
v_33439:
    goto v_33440;
v_33441:
    goto v_33442;
v_33443:
    goto v_33437;
v_33438:
    goto v_33439;
v_33440:
    goto v_33441;
v_33442:
    return list3(v_33449, v_33448, v_33447);
}



// Code for quotfexf!*1

static LispObject CC_quotfexfH1(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33513, v_33514, v_33515;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33433,v_33434);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_33434;
    stack[-1] = v_33433;
// end of prologue
    v_33513 = stack[-1];
    if (v_33513 == nil) goto v_33438;
    else goto v_33439;
v_33438:
    v_33513 = nil;
    goto v_33437;
v_33439:
    goto v_33449;
v_33445:
    v_33514 = stack[-1];
    goto v_33446;
v_33447:
    v_33513 = stack[0];
    goto v_33448;
v_33449:
    goto v_33445;
v_33446:
    goto v_33447;
v_33448:
    fn = elt(env, 4); // quotf
    v_33513 = (*qfn2(fn))(fn, v_33514, v_33513);
    env = stack[-2];
    v_33514 = v_33513;
    v_33513 = v_33514;
    if (v_33513 == nil) goto v_33456;
    v_33513 = v_33514;
    goto v_33454;
v_33456:
    goto v_33467;
v_33463:
    v_33514 = stack[-1];
    goto v_33464;
v_33465:
    v_33513 = stack[0];
    goto v_33466;
v_33467:
    goto v_33463;
v_33464:
    goto v_33465;
v_33466:
    v_33513 = cons(v_33514, v_33513);
    env = stack[-2];
    fn = elt(env, 5); // rationalizesq
    v_33513 = (*qfn1(fn))(fn, v_33513);
    env = stack[-2];
    v_33515 = v_33513;
    goto v_33479;
v_33475:
    v_33513 = v_33515;
    v_33514 = qcdr(v_33513);
    goto v_33476;
v_33477:
    v_33513 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33478;
v_33479:
    goto v_33475;
v_33476:
    goto v_33477;
v_33478:
    if (v_33514 == v_33513) goto v_33473;
    else goto v_33474;
v_33473:
    v_33513 = v_33515;
    v_33513 = qcar(v_33513);
    goto v_33472;
v_33474:
    goto v_33491;
v_33487:
    v_33513 = lisp_true;
// Binding !*rationalize
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-2, 1, 0);
    qvalue(elt(env, 1)) = v_33513; // !*rationalize
    v_33513 = v_33515;
    fn = elt(env, 5); // rationalizesq
    v_33513 = (*qfn1(fn))(fn, v_33513);
    env = stack[-2];
    ;}  // end of a binding scope
    v_33515 = v_33513;
    v_33514 = qcdr(v_33513);
    goto v_33488;
v_33489:
    v_33513 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_33490;
v_33491:
    goto v_33487;
v_33488:
    goto v_33489;
v_33490:
    if (v_33514 == v_33513) goto v_33485;
    else goto v_33486;
v_33485:
    v_33513 = v_33515;
    v_33513 = qcar(v_33513);
    goto v_33472;
v_33486:
    goto v_33509;
v_33503:
    v_33515 = elt(env, 2); // matrix
    goto v_33504;
v_33505:
    v_33514 = (LispObject)176+TAG_FIXNUM; // 11
    goto v_33506;
v_33507:
    v_33513 = elt(env, 3); // "Catastrophic division failure"
    goto v_33508;
v_33509:
    goto v_33503;
v_33504:
    goto v_33505;
v_33506:
    goto v_33507;
v_33508:
    {
        fn = elt(env, 6); // rerror
        return (*qfnn(fn))(fn, 3, v_33515, v_33514, v_33513);
    }
    v_33513 = nil;
v_33472:
    goto v_33454;
    v_33513 = nil;
v_33454:
    goto v_33437;
    v_33513 = nil;
v_33437:
    return onevalue(v_33513);
}



// Code for ps!:constmult!-erule

static LispObject CC_psTconstmultKerule(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33456, v_33457, v_33458;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33433,v_33434);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_33457 = v_33434;
    v_33458 = v_33433;
// end of prologue
    goto v_33441;
v_33437:
    v_33456 = v_33458;
    v_33456 = qcdr(v_33456);
    stack[0] = qcar(v_33456);
    goto v_33438;
v_33439:
    goto v_33450;
v_33446:
    v_33456 = v_33458;
    v_33456 = qcdr(v_33456);
    v_33456 = qcdr(v_33456);
    v_33456 = qcar(v_33456);
    goto v_33447;
v_33448:
    goto v_33449;
v_33450:
    goto v_33446;
v_33447:
    goto v_33448;
v_33449:
    fn = elt(env, 1); // ps!:evaluate
    v_33456 = (*qfn2(fn))(fn, v_33456, v_33457);
    env = stack[-1];
    goto v_33440;
v_33441:
    goto v_33437;
v_33438:
    goto v_33439;
v_33440:
    {
        LispObject v_33460 = stack[0];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_33460, v_33456);
    }
}



// Code for redpar

static LispObject CC_redpar(LispObject env,
                         LispObject v_33433, LispObject v_33434)
{
    env = qenv(env);
    LispObject v_33492, v_33493;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_33434,v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_33433,v_33434);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_33434;
    stack[-1] = v_33433;
// end of prologue
    stack[-2] = nil;
v_33441:
    v_33492 = stack[0];
    if (v_33492 == nil) goto v_33444;
    else goto v_33445;
v_33444:
    goto v_33440;
v_33445:
    goto v_33456;
v_33452:
    v_33492 = stack[0];
    v_33493 = qcar(v_33492);
    goto v_33453;
v_33454:
    v_33492 = stack[-1];
    goto v_33455;
v_33456:
    goto v_33452;
v_33453:
    goto v_33454;
v_33455:
    v_33492 = Lmember(nil, v_33493, v_33492);
    if (v_33492 == nil) goto v_33451;
    goto v_33466;
v_33462:
    v_33492 = stack[0];
    v_33493 = qcar(v_33492);
    goto v_33463;
v_33464:
    v_33492 = stack[-1];
    goto v_33465;
v_33466:
    goto v_33462;
v_33463:
    goto v_33464;
v_33465:
    v_33492 = Ldelete(nil, v_33493, v_33492);
    env = stack[-3];
    stack[-1] = v_33492;
    goto v_33449;
v_33451:
    goto v_33477;
v_33473:
    v_33492 = stack[0];
    v_33493 = qcar(v_33492);
    goto v_33474;
v_33475:
    v_33492 = stack[-2];
    goto v_33476;
v_33477:
    goto v_33473;
v_33474:
    goto v_33475;
v_33476:
    v_33492 = cons(v_33493, v_33492);
    env = stack[-3];
    stack[-2] = v_33492;
    goto v_33449;
v_33449:
    v_33492 = stack[0];
    v_33492 = qcdr(v_33492);
    stack[0] = v_33492;
    goto v_33441;
v_33440:
    goto v_33488;
v_33484:
    stack[0] = stack[-1];
    goto v_33485;
v_33486:
    v_33492 = stack[-2];
    v_33492 = Lreverse(nil, v_33492);
    goto v_33487;
v_33488:
    goto v_33484;
v_33485:
    goto v_33486;
v_33487:
    {
        LispObject v_33497 = stack[0];
        return list2(v_33497, v_33492);
    }
    return onevalue(v_33492);
}



// Code for remove_root_item

static LispObject CC_remove_root_item(LispObject env,
                         LispObject v_33433)
{
    env = qenv(env);
    LispObject v_33504, v_33505;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_33433);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_33433);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_33433;
// end of prologue
    v_33504 = stack[-1];
    v_33504 = qcdr(v_33504);
    v_33504 = qcar(v_33504);
    stack[-2] = v_33504;
    v_33504 = stack[-1];
    v_33504 = qcar(v_33504);
    stack[0] = v_33504;
    goto v_33449;
v_33445:
    v_33505 = stack[-1];
    goto v_33446;
v_33447:
    v_33504 = stack[-1];
    v_33504 = qcdr(v_33504);
    v_33504 = qcdr(v_33504);
    v_33504 = qcar(v_33504);
    goto v_33448;
v_33449:
    goto v_33445;
v_33446:
    goto v_33447;
v_33448:
    fn = elt(env, 1); // setcar
    v_33504 = (*qfn2(fn))(fn, v_33505, v_33504);
    env = stack[-3];
    goto v_33460;
v_33456:
    v_33505 = stack[-1];
    goto v_33457;
v_33458:
    v_33504 = stack[-1];
    v_33504 = qcdr(v_33504);
    v_33504 = qcdr(v_33504);
    v_33504 = qcdr(v_33504);
    goto v_33459;
v_33460:
    goto v_33456;
v_33457:
    goto v_33458;
v_33459:
    fn = elt(env, 2); // setcdr
    v_33504 = (*qfn2(fn))(fn, v_33505, v_33504);
    env = stack[-3];
    v_33504 = stack[-2];
    v_33504 = qcdr(v_33504);
    if (v_33504 == nil) goto v_33469;
v_33474:
    v_33504 = stack[-1];
    v_33504 = qcdr(v_33504);
    if (v_33504 == nil) goto v_33477;
    else goto v_33478;
v_33477:
    goto v_33473;
v_33478:
    v_33504 = stack[-1];
    v_33504 = qcdr(v_33504);
    v_33504 = qcar(v_33504);
    stack[-1] = v_33504;
    goto v_33474;
v_33473:
    goto v_33490;
v_33486:
    v_33505 = stack[-1];
    goto v_33487;
v_33488:
    v_33504 = stack[-2];
    v_33504 = qcar(v_33504);
    goto v_33489;
v_33490:
    goto v_33486;
v_33487:
    goto v_33488;
v_33489:
    fn = elt(env, 1); // setcar
    v_33504 = (*qfn2(fn))(fn, v_33505, v_33504);
    env = stack[-3];
    goto v_33499;
v_33495:
    v_33505 = stack[-1];
    goto v_33496;
v_33497:
    v_33504 = stack[-2];
    v_33504 = qcdr(v_33504);
    goto v_33498;
v_33499:
    goto v_33495;
v_33496:
    goto v_33497;
v_33498:
    fn = elt(env, 2); // setcdr
    v_33504 = (*qfn2(fn))(fn, v_33505, v_33504);
    goto v_33467;
v_33469:
v_33467:
    v_33504 = stack[0];
    return onevalue(v_33504);
}



setup_type const u56_setup[] =
{
    {"partitindexvar",          CC_partitindexvar,TOO_MANY_1,  WRONG_NO_1},
    {"physop*sq",               CC_physopHsq,   TOO_MANY_1,    WRONG_NO_1},
    {"mk-strand-vertex",        TOO_FEW_2,      CC_mkKstrandKvertex,WRONG_NO_2},
    {"prepsqyy",                CC_prepsqyy,    TOO_MANY_1,    WRONG_NO_1},
    {"general-minus-mod-p",     CC_generalKminusKmodKp,TOO_MANY_1,WRONG_NO_1},
    {"rtrnda",                  TOO_FEW_2,      CC_rtrnda,     WRONG_NO_2},
    {"gd_newtype",              TOO_FEW_2,      CC_gd_newtype, WRONG_NO_2},
    {"chrstrem",                CC_chrstrem,    TOO_MANY_1,    WRONG_NO_1},
    {"qqe_qadd-inside",         CC_qqe_qaddKinside,TOO_MANY_1, WRONG_NO_1},
    {"dip_reduceconti",         TOO_FEW_2,      CC_dip_reduceconti,WRONG_NO_2},
    {"search_att",              TOO_FEW_2,      CC_search_att, WRONG_NO_2},
    {"setprev",                 TOO_FEW_2,      CC_setprev,    WRONG_NO_2},
    {"poly-remainder",          CC_polyKremainder,TOO_MANY_1,  WRONG_NO_1},
    {"mkuniquewedge",           CC_mkuniquewedge,TOO_MANY_1,   WRONG_NO_1},
    {"rand-comb",               TOO_FEW_2,      CC_randKcomb,  WRONG_NO_2},
    {"new_provev",              TOO_FEW_2,      CC_new_provev, WRONG_NO_2},
    {"allbkern",                CC_allbkern,    TOO_MANY_1,    WRONG_NO_1},
    {"coeffs-to-form",          TOO_FEW_2,      CC_coeffsKtoKform,WRONG_NO_2},
    {"no_of_tm_sf",             CC_no_of_tm_sf, TOO_MANY_1,    WRONG_NO_1},
    {"cde_mkset",               CC_cde_mkset,   TOO_MANY_1,    WRONG_NO_1},
    {"cl_ex",                   TOO_FEW_2,      CC_cl_ex,      WRONG_NO_2},
    {"dfmax",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dfmax},
    {"rl_*qe",                  TOO_FEW_2,      CC_rl_Hqe,     WRONG_NO_2},
    {"search4facf",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_search4facf},
    {"rewrite2",                TOO_FEW_2,      CC_rewrite2,   WRONG_NO_2},
    {"column_dim",              CC_column_dim,  TOO_MANY_1,    WRONG_NO_1},
    {"gvarlis",                 CC_gvarlis,     TOO_MANY_1,    WRONG_NO_1},
    {"weak_xreduce",            TOO_FEW_2,      CC_weak_xreduce,WRONG_NO_2},
    {"tvectorp",                CC_tvectorp,    TOO_MANY_1,    WRONG_NO_1},
    {"ev-tades",                TOO_FEW_2,      CC_evKtades,   WRONG_NO_2},
    {"restore_props",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_restore_props},
    {"reprod",                  TOO_FEW_2,      CC_reprod,     WRONG_NO_2},
    {"mo_from_ei",              CC_mo_from_ei,  TOO_MANY_1,    WRONG_NO_1},
    {"pa_vect2list",            CC_pa_vect2list,TOO_MANY_1,    WRONG_NO_1},
    {"remk",                    TOO_FEW_2,      CC_remk,       WRONG_NO_2},
    {"modroots1",               TOO_FEW_2,      CC_modroots1,  WRONG_NO_2},
    {"anu_mk",                  TOO_FEW_2,      CC_anu_mk,     WRONG_NO_2},
    {"quotfexf*1",              TOO_FEW_2,      CC_quotfexfH1, WRONG_NO_2},
    {"ps:constmult-erule",      TOO_FEW_2,      CC_psTconstmultKerule,WRONG_NO_2},
    {"redpar",                  TOO_FEW_2,      CC_redpar,     WRONG_NO_2},
    {"remove_root_item",        CC_remove_root_item,TOO_MANY_1,WRONG_NO_1},
    {NULL, (one_args *)"u56", (two_args *)"152281 6579054 6063550", 0}
};

// end of generated code
