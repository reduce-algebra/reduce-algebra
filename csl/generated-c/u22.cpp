
// $destdir/u22.c        Machine generated C code

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



// Code for lienjactest

static LispObject CC_lienjactest(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_13086, v_13087, v_13088, v_13089;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(14);
// copy arguments values to proper place
    stack[-11] = v_12672;
// end of prologue
    goto v_12681;
v_12677:
    stack[0] = elt(env, 1); // lie_jtest
    goto v_12678;
v_12679:
    v_13086 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 6); // aeval
    v_13086 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    goto v_12680;
v_12681:
    goto v_12677;
v_12678:
    goto v_12679;
v_12680:
    fn = elt(env, 7); // setk
    v_13086 = (*qfn2(fn))(fn, stack[0], v_13086);
    env = stack[-13];
    v_13086 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-12] = v_13086;
v_12688:
    goto v_12702;
v_12696:
    stack[0] = elt(env, 2); // difference
    goto v_12697;
v_12698:
    goto v_12712;
v_12706:
    v_13088 = elt(env, 2); // difference
    goto v_12707;
v_12708:
    v_13087 = stack[-11];
    goto v_12709;
v_12710:
    v_13086 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_12711;
v_12712:
    goto v_12706;
v_12707:
    goto v_12708;
v_12709:
    goto v_12710;
v_12711:
    v_13086 = list3(v_13088, v_13087, v_13086);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13087 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    goto v_12699;
v_12700:
    v_13086 = stack[-12];
    goto v_12701;
v_12702:
    goto v_12696;
v_12697:
    goto v_12698;
v_12699:
    goto v_12700;
v_12701:
    v_13086 = list3(stack[0], v_13087, v_13086);
    env = stack[-13];
    fn = elt(env, 9); // aminusp!:
    v_13086 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    if (v_13086 == nil) goto v_12693;
    goto v_12687;
v_12693:
    v_13086 = stack[-12];
    v_13086 = add1(v_13086);
    env = stack[-13];
    stack[-10] = v_13086;
v_12721:
    goto v_12736;
v_12730:
    stack[0] = elt(env, 2); // difference
    goto v_12731;
v_12732:
    goto v_12746;
v_12740:
    v_13088 = elt(env, 2); // difference
    goto v_12741;
v_12742:
    v_13087 = stack[-11];
    goto v_12743;
v_12744:
    v_13086 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12745;
v_12746:
    goto v_12740;
v_12741:
    goto v_12742;
v_12743:
    goto v_12744;
v_12745:
    v_13086 = list3(v_13088, v_13087, v_13086);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13087 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    goto v_12733;
v_12734:
    v_13086 = stack[-10];
    goto v_12735;
v_12736:
    goto v_12730;
v_12731:
    goto v_12732;
v_12733:
    goto v_12734;
v_12735:
    v_13086 = list3(stack[0], v_13087, v_13086);
    env = stack[-13];
    fn = elt(env, 9); // aminusp!:
    v_13086 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    if (v_13086 == nil) goto v_12727;
    goto v_12720;
v_12727:
    v_13086 = stack[-10];
    v_13086 = add1(v_13086);
    env = stack[-13];
    stack[-9] = v_13086;
v_12755:
    goto v_12770;
v_12764:
    stack[0] = elt(env, 2); // difference
    goto v_12765;
v_12766:
    v_13086 = stack[-11];
    fn = elt(env, 8); // aeval!*
    v_13087 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    goto v_12767;
v_12768:
    v_13086 = stack[-9];
    goto v_12769;
v_12770:
    goto v_12764;
v_12765:
    goto v_12766;
v_12767:
    goto v_12768;
v_12769:
    v_13086 = list3(stack[0], v_13087, v_13086);
    env = stack[-13];
    fn = elt(env, 9); // aminusp!:
    v_13086 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    if (v_13086 == nil) goto v_12761;
    goto v_12754;
v_12761:
    v_13086 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_13086;
v_12779:
    goto v_12793;
v_12787:
    stack[0] = elt(env, 2); // difference
    goto v_12788;
v_12789:
    v_13086 = stack[-11];
    fn = elt(env, 8); // aeval!*
    v_13087 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    goto v_12790;
v_12791:
    v_13086 = stack[-8];
    goto v_12792;
v_12793:
    goto v_12787;
v_12788:
    goto v_12789;
v_12790:
    goto v_12791;
v_12792:
    v_13086 = list3(stack[0], v_13087, v_13086);
    env = stack[-13];
    fn = elt(env, 9); // aminusp!:
    v_13086 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    if (v_13086 == nil) goto v_12784;
    goto v_12778;
v_12784:
    goto v_12808;
v_12804:
    v_13086 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-7] = v_13086;
    v_13086 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_13086;
v_12813:
    goto v_12828;
v_12822:
    stack[0] = elt(env, 2); // difference
    goto v_12823;
v_12824:
    v_13086 = stack[-11];
    fn = elt(env, 8); // aeval!*
    v_13087 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    goto v_12825;
v_12826:
    v_13086 = stack[-7];
    goto v_12827;
v_12828:
    goto v_12822;
v_12823:
    goto v_12824;
v_12825:
    goto v_12826;
v_12827:
    v_13086 = list3(stack[0], v_13087, v_13086);
    env = stack[-13];
    fn = elt(env, 9); // aminusp!:
    v_13086 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    if (v_13086 == nil) goto v_12819;
    v_13086 = stack[-6];
    v_13087 = v_13086;
    goto v_12812;
v_12819:
    goto v_12842;
v_12836:
    stack[-5] = elt(env, 3); // plus
    goto v_12837;
v_12838:
    goto v_12854;
v_12846:
    stack[-4] = elt(env, 3); // plus
    goto v_12847;
v_12848:
    goto v_12863;
v_12857:
    stack[-1] = elt(env, 4); // times
    goto v_12858;
v_12859:
    goto v_12874;
v_12866:
    v_13089 = elt(env, 5); // lie_cc
    goto v_12867;
v_12868:
    v_13088 = stack[-10];
    goto v_12869;
v_12870:
    v_13087 = stack[-9];
    goto v_12871;
v_12872:
    v_13086 = stack[-7];
    goto v_12873;
v_12874:
    goto v_12866;
v_12867:
    goto v_12868;
v_12869:
    goto v_12870;
v_12871:
    goto v_12872;
v_12873:
    stack[0] = list4(v_13089, v_13088, v_13087, v_13086);
    env = stack[-13];
    goto v_12860;
v_12861:
    goto v_12888;
v_12880:
    v_13089 = elt(env, 5); // lie_cc
    goto v_12881;
v_12882:
    v_13088 = stack[-12];
    goto v_12883;
v_12884:
    v_13087 = stack[-7];
    goto v_12885;
v_12886:
    v_13086 = stack[-8];
    goto v_12887;
v_12888:
    goto v_12880;
v_12881:
    goto v_12882;
v_12883:
    goto v_12884;
v_12885:
    goto v_12886;
v_12887:
    v_13086 = list4(v_13089, v_13088, v_13087, v_13086);
    env = stack[-13];
    goto v_12862;
v_12863:
    goto v_12857;
v_12858:
    goto v_12859;
v_12860:
    goto v_12861;
v_12862:
    stack[-3] = list3(stack[-1], stack[0], v_13086);
    env = stack[-13];
    goto v_12849;
v_12850:
    goto v_12900;
v_12894:
    stack[-1] = elt(env, 4); // times
    goto v_12895;
v_12896:
    goto v_12911;
v_12903:
    v_13089 = elt(env, 5); // lie_cc
    goto v_12904;
v_12905:
    v_13088 = stack[-12];
    goto v_12906;
v_12907:
    v_13087 = stack[-10];
    goto v_12908;
v_12909:
    v_13086 = stack[-7];
    goto v_12910;
v_12911:
    goto v_12903;
v_12904:
    goto v_12905;
v_12906:
    goto v_12907;
v_12908:
    goto v_12909;
v_12910:
    stack[0] = list4(v_13089, v_13088, v_13087, v_13086);
    env = stack[-13];
    goto v_12897;
v_12898:
    goto v_12925;
v_12917:
    v_13089 = elt(env, 5); // lie_cc
    goto v_12918;
v_12919:
    v_13088 = stack[-9];
    goto v_12920;
v_12921:
    v_13087 = stack[-7];
    goto v_12922;
v_12923:
    v_13086 = stack[-8];
    goto v_12924;
v_12925:
    goto v_12917;
v_12918:
    goto v_12919;
v_12920:
    goto v_12921;
v_12922:
    goto v_12923;
v_12924:
    v_13086 = list4(v_13089, v_13088, v_13087, v_13086);
    env = stack[-13];
    goto v_12899;
v_12900:
    goto v_12894;
v_12895:
    goto v_12896;
v_12897:
    goto v_12898;
v_12899:
    stack[-2] = list3(stack[-1], stack[0], v_13086);
    env = stack[-13];
    goto v_12851;
v_12852:
    goto v_12937;
v_12931:
    stack[-1] = elt(env, 4); // times
    goto v_12932;
v_12933:
    goto v_12948;
v_12940:
    v_13089 = elt(env, 5); // lie_cc
    goto v_12941;
v_12942:
    v_13088 = stack[-9];
    goto v_12943;
v_12944:
    v_13087 = stack[-12];
    goto v_12945;
v_12946:
    v_13086 = stack[-7];
    goto v_12947;
v_12948:
    goto v_12940;
v_12941:
    goto v_12942;
v_12943:
    goto v_12944;
v_12945:
    goto v_12946;
v_12947:
    stack[0] = list4(v_13089, v_13088, v_13087, v_13086);
    env = stack[-13];
    goto v_12934;
v_12935:
    goto v_12962;
v_12954:
    v_13089 = elt(env, 5); // lie_cc
    goto v_12955;
v_12956:
    v_13088 = stack[-10];
    goto v_12957;
v_12958:
    v_13087 = stack[-7];
    goto v_12959;
v_12960:
    v_13086 = stack[-8];
    goto v_12961;
v_12962:
    goto v_12954;
v_12955:
    goto v_12956;
v_12957:
    goto v_12958;
v_12959:
    goto v_12960;
v_12961:
    v_13086 = list4(v_13089, v_13088, v_13087, v_13086);
    env = stack[-13];
    goto v_12936;
v_12937:
    goto v_12931;
v_12932:
    goto v_12933;
v_12934:
    goto v_12935;
v_12936:
    v_13086 = list3(stack[-1], stack[0], v_13086);
    env = stack[-13];
    goto v_12853;
v_12854:
    goto v_12846;
v_12847:
    goto v_12848;
v_12849:
    goto v_12850;
v_12851:
    goto v_12852;
v_12853:
    v_13086 = list4(stack[-4], stack[-3], stack[-2], v_13086);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13087 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    goto v_12839;
v_12840:
    v_13086 = stack[-6];
    goto v_12841;
v_12842:
    goto v_12836;
v_12837:
    goto v_12838;
v_12839:
    goto v_12840;
v_12841:
    v_13086 = list3(stack[-5], v_13087, v_13086);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13086 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    stack[-6] = v_13086;
    v_13086 = stack[-7];
    goto v_12978;
v_12972:
    v_13088 = elt(env, 3); // plus
    goto v_12973;
v_12974:
    v_13087 = v_13086;
    goto v_12975;
v_12976:
    v_13086 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12977;
v_12978:
    goto v_12972;
v_12973:
    goto v_12974;
v_12975:
    goto v_12976;
v_12977:
    v_13086 = list3(v_13088, v_13087, v_13086);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13086 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    stack[-7] = v_13086;
    goto v_12813;
v_12812:
    goto v_12805;
v_12806:
    v_13086 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12807;
v_12808:
    goto v_12804;
v_12805:
    goto v_12806;
v_12807:
    fn = elt(env, 10); // evalneq
    v_13086 = (*qfn2(fn))(fn, v_13087, v_13086);
    env = stack[-13];
    if (v_13086 == nil) goto v_12802;
    goto v_12988;
v_12984:
    stack[0] = elt(env, 1); // lie_jtest
    goto v_12985;
v_12986:
    v_13086 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 8); // aeval!*
    v_13086 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    goto v_12987;
v_12988:
    goto v_12984;
v_12985:
    goto v_12986;
v_12987:
    fn = elt(env, 7); // setk
    v_13086 = (*qfn2(fn))(fn, stack[0], v_13086);
    env = stack[-13];
    goto v_13000;
v_12994:
    v_13088 = elt(env, 2); // difference
    goto v_12995;
v_12996:
    v_13087 = stack[-11];
    goto v_12997;
v_12998:
    v_13086 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12999;
v_13000:
    goto v_12994;
v_12995:
    goto v_12996;
v_12997:
    goto v_12998;
v_12999:
    v_13086 = list3(v_13088, v_13087, v_13086);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13086 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    stack[-12] = v_13086;
    v_13086 = stack[-11];
    fn = elt(env, 8); // aeval!*
    v_13086 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    stack[-10] = v_13086;
    goto v_13014;
v_13008:
    v_13088 = elt(env, 3); // plus
    goto v_13009;
v_13010:
    v_13087 = stack[-11];
    goto v_13011;
v_13012:
    v_13086 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13013;
v_13014:
    goto v_13008;
v_13009:
    goto v_13010;
v_13011:
    goto v_13012;
v_13013:
    v_13086 = list3(v_13088, v_13087, v_13086);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13086 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    stack[-9] = v_13086;
    goto v_13026;
v_13020:
    v_13088 = elt(env, 3); // plus
    goto v_13021;
v_13022:
    v_13087 = stack[-11];
    goto v_13023;
v_13024:
    v_13086 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13025;
v_13026:
    goto v_13020;
v_13021:
    goto v_13022;
v_13023:
    goto v_13024;
v_13025:
    v_13086 = list3(v_13088, v_13087, v_13086);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13086 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    stack[-8] = v_13086;
    goto v_12800;
v_12802:
v_12800:
    v_13086 = stack[-8];
    goto v_13040;
v_13034:
    v_13088 = elt(env, 3); // plus
    goto v_13035;
v_13036:
    v_13087 = v_13086;
    goto v_13037;
v_13038:
    v_13086 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13039;
v_13040:
    goto v_13034;
v_13035:
    goto v_13036;
v_13037:
    goto v_13038;
v_13039:
    v_13086 = list3(v_13088, v_13087, v_13086);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13086 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    stack[-8] = v_13086;
    goto v_12779;
v_12778:
    v_13086 = stack[-9];
    goto v_13054;
v_13048:
    v_13088 = elt(env, 3); // plus
    goto v_13049;
v_13050:
    v_13087 = v_13086;
    goto v_13051;
v_13052:
    v_13086 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13053;
v_13054:
    goto v_13048;
v_13049:
    goto v_13050;
v_13051:
    goto v_13052;
v_13053:
    v_13086 = list3(v_13088, v_13087, v_13086);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13086 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    stack[-9] = v_13086;
    goto v_12755;
v_12754:
    v_13086 = stack[-10];
    goto v_13068;
v_13062:
    v_13088 = elt(env, 3); // plus
    goto v_13063;
v_13064:
    v_13087 = v_13086;
    goto v_13065;
v_13066:
    v_13086 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13067;
v_13068:
    goto v_13062;
v_13063:
    goto v_13064;
v_13065:
    goto v_13066;
v_13067:
    v_13086 = list3(v_13088, v_13087, v_13086);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13086 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    stack[-10] = v_13086;
    goto v_12721;
v_12720:
    v_13086 = stack[-12];
    goto v_13082;
v_13076:
    v_13088 = elt(env, 3); // plus
    goto v_13077;
v_13078:
    v_13087 = v_13086;
    goto v_13079;
v_13080:
    v_13086 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13081;
v_13082:
    goto v_13076;
v_13077:
    goto v_13078;
v_13079:
    goto v_13080;
v_13081:
    v_13086 = list3(v_13088, v_13087, v_13086);
    env = stack[-13];
    fn = elt(env, 8); // aeval!*
    v_13086 = (*qfn1(fn))(fn, v_13086);
    env = stack[-13];
    stack[-12] = v_13086;
    goto v_12688;
v_12687:
    v_13086 = nil;
    return onevalue(v_13086);
}



// Code for mv!-pow!-mv!-!+

static LispObject CC_mvKpowKmvKL(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12706, v_12707;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12673;
    stack[-1] = v_12672;
// end of prologue
    stack[-2] = nil;
v_12678:
    v_12706 = stack[0];
    if (v_12706 == nil) goto v_12681;
    else goto v_12682;
v_12681:
    v_12706 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12706);
    }
v_12682:
    goto v_12693;
v_12689:
    goto v_12699;
v_12695:
    v_12707 = stack[-1];
    goto v_12696;
v_12697:
    v_12706 = stack[0];
    v_12706 = qcar(v_12706);
    goto v_12698;
v_12699:
    goto v_12695;
v_12696:
    goto v_12697;
v_12698:
    fn = elt(env, 2); // mv!-pow!-mv!-term!-!+
    v_12707 = (*qfn2(fn))(fn, v_12707, v_12706);
    env = stack[-3];
    goto v_12690;
v_12691:
    v_12706 = stack[-2];
    goto v_12692;
v_12693:
    goto v_12689;
v_12690:
    goto v_12691;
v_12692:
    v_12706 = cons(v_12707, v_12706);
    env = stack[-3];
    stack[-2] = v_12706;
    v_12706 = stack[0];
    v_12706 = qcdr(v_12706);
    stack[0] = v_12706;
    goto v_12678;
    v_12706 = nil;
    return onevalue(v_12706);
}



// Code for ilcm

static LispObject CC_ilcm(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12746, v_12747, v_12748, v_12749;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_12748 = v_12673;
    v_12749 = v_12672;
// end of prologue
    goto v_12687;
v_12683:
    v_12747 = v_12749;
    goto v_12684;
v_12685:
    v_12746 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12686;
v_12687:
    goto v_12683;
v_12684:
    goto v_12685;
v_12686:
    if (v_12747 == v_12746) goto v_12681;
    else goto v_12682;
v_12681:
    v_12746 = lisp_true;
    goto v_12680;
v_12682:
    goto v_12697;
v_12693:
    v_12747 = v_12748;
    goto v_12694;
v_12695:
    v_12746 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12696;
v_12697:
    goto v_12693;
v_12694:
    goto v_12695;
v_12696:
    v_12746 = (v_12747 == v_12746 ? lisp_true : nil);
    goto v_12680;
    v_12746 = nil;
v_12680:
    if (v_12746 == nil) goto v_12678;
    v_12746 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12676;
v_12678:
    goto v_12708;
v_12704:
    v_12747 = v_12749;
    goto v_12705;
v_12706:
    v_12746 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12707;
v_12708:
    goto v_12704;
v_12705:
    goto v_12706;
v_12707:
    if (v_12747 == v_12746) goto v_12702;
    else goto v_12703;
v_12702:
    v_12746 = v_12748;
    goto v_12676;
v_12703:
    goto v_12718;
v_12714:
    v_12747 = v_12748;
    goto v_12715;
v_12716:
    v_12746 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12717;
v_12718:
    goto v_12714;
v_12715:
    goto v_12716;
v_12717:
    if (v_12747 == v_12746) goto v_12712;
    else goto v_12713;
v_12712:
    v_12746 = v_12749;
    goto v_12676;
v_12713:
    goto v_12729;
v_12725:
    stack[-1] = v_12749;
    goto v_12726;
v_12727:
    goto v_12736;
v_12732:
    stack[0] = v_12748;
    goto v_12733;
v_12734:
    goto v_12743;
v_12739:
    v_12746 = v_12749;
    goto v_12740;
v_12741:
    v_12747 = v_12748;
    goto v_12742;
v_12743:
    goto v_12739;
v_12740:
    goto v_12741;
v_12742:
    v_12746 = Lgcd(nil, v_12746, v_12747);
    env = stack[-2];
    goto v_12735;
v_12736:
    goto v_12732;
v_12733:
    goto v_12734;
v_12735:
    v_12746 = quot2(stack[0], v_12746);
    goto v_12728;
v_12729:
    goto v_12725;
v_12726:
    goto v_12727;
v_12728:
    {
        LispObject v_12752 = stack[-1];
        return times2(v_12752, v_12746);
    }
    v_12746 = nil;
v_12676:
    return onevalue(v_12746);
}



// Code for quotfail!-in!-vector

static LispObject CC_quotfailKinKvector(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12949, v_12950, v_12951, v_12952, v_12953, v_12954, v_12955, v_12956;
    LispObject fn;
    LispObject v_12675, v_12674, v_12673, v_12672;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "quotfail-in-vector");
    va_start(aa, nargs);
    v_12672 = va_arg(aa, LispObject);
    v_12673 = va_arg(aa, LispObject);
    v_12674 = va_arg(aa, LispObject);
    v_12675 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_12675,v_12674,v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_12672,v_12673,v_12674,v_12675);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_12675;
    stack[-2] = v_12674;
    v_12951 = v_12673;
    stack[-3] = v_12672;
// end of prologue
    goto v_12685;
v_12681:
    v_12950 = v_12951;
    goto v_12682;
v_12683:
    v_12949 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12684;
v_12685:
    goto v_12681;
v_12682:
    goto v_12683;
v_12684:
    if (((intptr_t)(v_12950)) < ((intptr_t)(v_12949))) goto v_12679;
    else goto v_12680;
v_12679:
    v_12949 = v_12951;
    goto v_12678;
v_12680:
    goto v_12695;
v_12691:
    v_12950 = stack[-1];
    goto v_12692;
v_12693:
    v_12949 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12694;
v_12695:
    goto v_12691;
v_12692:
    goto v_12693;
v_12694:
    if (((intptr_t)(v_12950)) < ((intptr_t)(v_12949))) goto v_12689;
    else goto v_12690;
v_12689:
    v_12949 = elt(env, 1); // "Attempt to divide by zero"
    {
        fn = elt(env, 4); // errorf
        return (*qfn1(fn))(fn, v_12949);
    }
v_12690:
    goto v_12706;
v_12702:
    v_12950 = v_12951;
    goto v_12703;
v_12704:
    v_12949 = stack[-1];
    goto v_12705;
v_12706:
    goto v_12702;
v_12703:
    goto v_12704;
v_12705:
    if (((intptr_t)(v_12950)) < ((intptr_t)(v_12949))) goto v_12700;
    else goto v_12701;
v_12700:
    v_12949 = elt(env, 2); // "Bad degrees in quotfail-in-vector"
    {
        fn = elt(env, 4); // errorf
        return (*qfn1(fn))(fn, v_12949);
    }
v_12701:
    goto v_12720;
v_12716:
    v_12950 = v_12951;
    goto v_12717;
v_12718:
    v_12949 = stack[-1];
    goto v_12719;
v_12720:
    goto v_12716;
v_12717:
    goto v_12718;
v_12719:
    v_12949 = (LispObject)(intptr_t)((intptr_t)v_12950 - (intptr_t)v_12949 + TAG_FIXNUM);
    stack[-4] = v_12949;
    v_12949 = stack[-4];
    stack[0] = v_12949;
v_12727:
    v_12949 = stack[0];
    v_12949 = ((intptr_t)(v_12949) < 0 ? lisp_true : nil);
    if (v_12949 == nil) goto v_12732;
    goto v_12726;
v_12732:
    goto v_12744;
v_12740:
    goto v_12749;
v_12745:
    v_12951 = stack[-3];
    goto v_12746;
v_12747:
    goto v_12755;
v_12751:
    v_12950 = stack[-1];
    goto v_12752;
v_12753:
    v_12949 = stack[0];
    goto v_12754;
v_12755:
    goto v_12751;
v_12752:
    goto v_12753;
v_12754:
    v_12949 = (LispObject)(intptr_t)((intptr_t)v_12950 + (intptr_t)v_12949 - TAG_FIXNUM);
    goto v_12748;
v_12749:
    goto v_12745;
v_12746:
    goto v_12747;
v_12748:
    v_12951 = *(LispObject *)((char *)v_12951 + (CELL-TAG_VECTOR) + (((intptr_t)v_12949-TAG_FIXNUM)/(16/CELL)));
    goto v_12741;
v_12742:
    goto v_12764;
v_12760:
    v_12950 = stack[-2];
    goto v_12761;
v_12762:
    v_12949 = stack[-1];
    goto v_12763;
v_12764:
    goto v_12760;
v_12761:
    goto v_12762;
v_12763:
    v_12949 = *(LispObject *)((char *)v_12950 + (CELL-TAG_VECTOR) + (((intptr_t)v_12949-TAG_FIXNUM)/(16/CELL)));
    goto v_12743;
v_12744:
    goto v_12740;
v_12741:
    goto v_12742;
v_12743:
    v_12949 = Lmodular_quotient(nil, v_12951, v_12949);
    env = stack[-5];
    v_12956 = v_12949;
    v_12949 = (LispObject)0+TAG_FIXNUM; // 0
    v_12955 = v_12949;
v_12771:
    goto v_12781;
v_12777:
    v_12949 = stack[-1];
    v_12950 = (LispObject)((intptr_t)(v_12949) - 0x10);
    goto v_12778;
v_12779:
    v_12949 = v_12955;
    goto v_12780;
v_12781:
    goto v_12777;
v_12778:
    goto v_12779;
v_12780:
    v_12949 = (LispObject)(intptr_t)((intptr_t)v_12950 - (intptr_t)v_12949 + TAG_FIXNUM);
    v_12949 = ((intptr_t)(v_12949) < 0 ? lisp_true : nil);
    if (v_12949 == nil) goto v_12776;
    goto v_12770;
v_12776:
    goto v_12794;
v_12788:
    v_12954 = stack[-3];
    goto v_12789;
v_12790:
    goto v_12800;
v_12796:
    v_12950 = stack[0];
    goto v_12797;
v_12798:
    v_12949 = v_12955;
    goto v_12799;
v_12800:
    goto v_12796;
v_12797:
    goto v_12798;
v_12799:
    v_12953 = (LispObject)(intptr_t)((intptr_t)v_12950 + (intptr_t)v_12949 - TAG_FIXNUM);
    goto v_12791;
v_12792:
    goto v_12808;
v_12804:
    goto v_12813;
v_12809:
    v_12951 = stack[-3];
    goto v_12810;
v_12811:
    goto v_12819;
v_12815:
    v_12950 = stack[0];
    goto v_12816;
v_12817:
    v_12949 = v_12955;
    goto v_12818;
v_12819:
    goto v_12815;
v_12816:
    goto v_12817;
v_12818:
    v_12949 = (LispObject)(intptr_t)((intptr_t)v_12950 + (intptr_t)v_12949 - TAG_FIXNUM);
    goto v_12812;
v_12813:
    goto v_12809;
v_12810:
    goto v_12811;
v_12812:
    v_12952 = *(LispObject *)((char *)v_12951 + (CELL-TAG_VECTOR) + (((intptr_t)v_12949-TAG_FIXNUM)/(16/CELL)));
    goto v_12805;
v_12806:
    goto v_12829;
v_12825:
    v_12951 = v_12956;
    goto v_12826;
v_12827:
    goto v_12835;
v_12831:
    v_12950 = stack[-2];
    goto v_12832;
v_12833:
    v_12949 = v_12955;
    goto v_12834;
v_12835:
    goto v_12831;
v_12832:
    goto v_12833;
v_12834:
    v_12949 = *(LispObject *)((char *)v_12950 + (CELL-TAG_VECTOR) + (((intptr_t)v_12949-TAG_FIXNUM)/(16/CELL)));
    goto v_12828;
v_12829:
    goto v_12825;
v_12826:
    goto v_12827;
v_12828:
    v_12949 = Lmodular_times(nil, v_12951, v_12949);
    env = stack[-5];
    goto v_12807;
v_12808:
    goto v_12804;
v_12805:
    goto v_12806;
v_12807:
    {   intptr_t w = int_of_fixnum(v_12952) - int_of_fixnum(v_12949);
        if (w < 0) w += current_modulus;
        v_12949 = fixnum_of_int(w);
    }
    goto v_12793;
v_12794:
    goto v_12788;
v_12789:
    goto v_12790;
v_12791:
    goto v_12792;
v_12793:
    *(LispObject *)((char *)v_12954 + (CELL-TAG_VECTOR) + (((intptr_t)v_12953-TAG_FIXNUM)/(16/CELL))) = v_12949;
    v_12949 = v_12955;
    v_12949 = (LispObject)((intptr_t)(v_12949) + 0x10);
    v_12955 = v_12949;
    goto v_12771;
v_12770:
    goto v_12848;
v_12842:
    v_12951 = stack[-3];
    goto v_12843;
v_12844:
    goto v_12854;
v_12850:
    v_12950 = stack[-1];
    goto v_12851;
v_12852:
    v_12949 = stack[0];
    goto v_12853;
v_12854:
    goto v_12850;
v_12851:
    goto v_12852;
v_12853:
    v_12949 = (LispObject)(intptr_t)((intptr_t)v_12950 + (intptr_t)v_12949 - TAG_FIXNUM);
    goto v_12845;
v_12846:
    v_12950 = v_12956;
    goto v_12847;
v_12848:
    goto v_12842;
v_12843:
    goto v_12844;
v_12845:
    goto v_12846;
v_12847:
    *(LispObject *)((char *)v_12951 + (CELL-TAG_VECTOR) + (((intptr_t)v_12949-TAG_FIXNUM)/(16/CELL))) = v_12950;
    v_12949 = stack[0];
    v_12949 = (LispObject)((intptr_t)(v_12949) - 0x10);
    stack[0] = v_12949;
    goto v_12727;
v_12726:
    v_12949 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_12949;
v_12864:
    goto v_12874;
v_12870:
    v_12949 = stack[-1];
    v_12950 = (LispObject)((intptr_t)(v_12949) - 0x10);
    goto v_12871;
v_12872:
    v_12949 = stack[0];
    goto v_12873;
v_12874:
    goto v_12870;
v_12871:
    goto v_12872;
v_12873:
    v_12949 = (LispObject)(intptr_t)((intptr_t)v_12950 - (intptr_t)v_12949 + TAG_FIXNUM);
    v_12949 = ((intptr_t)(v_12949) < 0 ? lisp_true : nil);
    if (v_12949 == nil) goto v_12869;
    goto v_12863;
v_12869:
    goto v_12889;
v_12885:
    goto v_12894;
v_12890:
    v_12950 = stack[-3];
    goto v_12891;
v_12892:
    v_12949 = stack[0];
    goto v_12893;
v_12894:
    goto v_12890;
v_12891:
    goto v_12892;
v_12893:
    v_12950 = *(LispObject *)((char *)v_12950 + (CELL-TAG_VECTOR) + (((intptr_t)v_12949-TAG_FIXNUM)/(16/CELL)));
    goto v_12886;
v_12887:
    v_12949 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12888;
v_12889:
    goto v_12885;
v_12886:
    goto v_12887;
v_12888:
    if (v_12950 == v_12949) goto v_12884;
    v_12949 = elt(env, 3); // "Quotient not exact in quotfail!-in!-vector"
    fn = elt(env, 4); // errorf
    v_12949 = (*qfn1(fn))(fn, v_12949);
    env = stack[-5];
    goto v_12882;
v_12884:
v_12882:
    v_12949 = stack[0];
    v_12949 = (LispObject)((intptr_t)(v_12949) + 0x10);
    stack[0] = v_12949;
    goto v_12864;
v_12863:
    v_12949 = (LispObject)0+TAG_FIXNUM; // 0
    v_12954 = v_12949;
v_12906:
    goto v_12916;
v_12912:
    v_12950 = stack[-4];
    goto v_12913;
v_12914:
    v_12949 = v_12954;
    goto v_12915;
v_12916:
    goto v_12912;
v_12913:
    goto v_12914;
v_12915:
    v_12949 = (LispObject)(intptr_t)((intptr_t)v_12950 - (intptr_t)v_12949 + TAG_FIXNUM);
    v_12949 = ((intptr_t)(v_12949) < 0 ? lisp_true : nil);
    if (v_12949 == nil) goto v_12911;
    goto v_12905;
v_12911:
    goto v_12928;
v_12922:
    v_12953 = stack[-3];
    goto v_12923;
v_12924:
    v_12952 = v_12954;
    goto v_12925;
v_12926:
    goto v_12935;
v_12931:
    v_12951 = stack[-3];
    goto v_12932;
v_12933:
    goto v_12941;
v_12937:
    v_12950 = stack[-1];
    goto v_12938;
v_12939:
    v_12949 = v_12954;
    goto v_12940;
v_12941:
    goto v_12937;
v_12938:
    goto v_12939;
v_12940:
    v_12949 = (LispObject)(intptr_t)((intptr_t)v_12950 + (intptr_t)v_12949 - TAG_FIXNUM);
    goto v_12934;
v_12935:
    goto v_12931;
v_12932:
    goto v_12933;
v_12934:
    v_12949 = *(LispObject *)((char *)v_12951 + (CELL-TAG_VECTOR) + (((intptr_t)v_12949-TAG_FIXNUM)/(16/CELL)));
    goto v_12927;
v_12928:
    goto v_12922;
v_12923:
    goto v_12924;
v_12925:
    goto v_12926;
v_12927:
    *(LispObject *)((char *)v_12953 + (CELL-TAG_VECTOR) + (((intptr_t)v_12952-TAG_FIXNUM)/(16/CELL))) = v_12949;
    v_12949 = v_12954;
    v_12949 = (LispObject)((intptr_t)(v_12949) + 0x10);
    v_12954 = v_12949;
    goto v_12906;
v_12905:
    v_12949 = stack[-4];
    goto v_12678;
    v_12949 = nil;
v_12678:
    return onevalue(v_12949);
}



// Code for gcref_mkgraph

static LispObject CC_gcref_mkgraph(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12685, v_12686;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12686 = v_12672;
// end of prologue
    v_12685 = qvalue(elt(env, 1)); // !*gcrefudg
    if (v_12685 == nil) goto v_12677;
    v_12685 = v_12686;
    {
        fn = elt(env, 2); // gcref_mkgraph!-udg
        return (*qfn1(fn))(fn, v_12685);
    }
v_12677:
    v_12685 = v_12686;
    {
        fn = elt(env, 3); // gcref_mkgraph!-tgf
        return (*qfn1(fn))(fn, v_12685);
    }
    v_12685 = nil;
    return onevalue(v_12685);
}



// Code for ofsf_smwmkatl

static LispObject CC_ofsf_smwmkatl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12712, v_12713, v_12714, v_12715, v_12716;
    LispObject fn;
    LispObject v_12675, v_12674, v_12673, v_12672;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ofsf_smwmkatl");
    va_start(aa, nargs);
    v_12672 = va_arg(aa, LispObject);
    v_12673 = va_arg(aa, LispObject);
    v_12674 = va_arg(aa, LispObject);
    v_12675 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12713 = v_12675;
    v_12714 = v_12674;
    v_12715 = v_12673;
    v_12716 = v_12672;
// end of prologue
    v_12712 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_12712 == nil) goto v_12680;
    goto v_12691;
v_12683:
    v_12712 = v_12716;
    goto v_12684;
v_12685:
    goto v_12686;
v_12687:
    goto v_12688;
v_12689:
    goto v_12690;
v_12691:
    goto v_12683;
v_12684:
    goto v_12685;
v_12686:
    goto v_12687;
v_12688:
    goto v_12689;
v_12690:
    {
        fn = elt(env, 2); // cl_susimkatl
        return (*qfnn(fn))(fn, 4, v_12712, v_12715, v_12714, v_12713);
    }
v_12680:
    goto v_12707;
v_12699:
    v_12712 = v_12716;
    goto v_12700;
v_12701:
    goto v_12702;
v_12703:
    goto v_12704;
v_12705:
    goto v_12706;
v_12707:
    goto v_12699;
v_12700:
    goto v_12701;
v_12702:
    goto v_12703;
v_12704:
    goto v_12705;
v_12706:
    {
        fn = elt(env, 3); // ofsf_smmkatl
        return (*qfnn(fn))(fn, 4, v_12712, v_12715, v_12714, v_12713);
    }
    v_12712 = nil;
    return onevalue(v_12712);
}



// Code for ezgcdf1

static LispObject CC_ezgcdf1(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12687, v_12688, v_12689;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_12688 = v_12673;
    v_12689 = v_12672;
// end of prologue
    v_12687 = (LispObject)0+TAG_FIXNUM; // 0
// Binding factor!-level
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_12687; // factor!-level
    goto v_12684;
v_12680:
    v_12687 = v_12689;
    goto v_12681;
v_12682:
    goto v_12683;
v_12684:
    goto v_12680;
v_12681:
    goto v_12682;
v_12683:
    v_12687 = list2(v_12687, v_12688);
    env = stack[-1];
    fn = elt(env, 2); // gcdlist
    v_12687 = (*qfn1(fn))(fn, v_12687);
    env = stack[-1];
    fn = elt(env, 3); // poly!-abs
    v_12687 = (*qfn1(fn))(fn, v_12687);
    ;}  // end of a binding scope
    return onevalue(v_12687);
}



// Code for talp_eqnrhskernels

static LispObject CC_talp_eqnrhskernels(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12677;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12677 = v_12672;
// end of prologue
    v_12677 = qcdr(v_12677);
    {
        fn = elt(env, 1); // talp_varlt
        return (*qfn1(fn))(fn, v_12677);
    }
}



// Code for delet

static LispObject CC_delet(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12744, v_12745, v_12746;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12673;
    stack[-1] = v_12672;
// end of prologue
    v_12746 = nil;
v_12678:
    v_12744 = stack[-1];
    if (v_12744 == nil) goto v_12681;
    else goto v_12682;
v_12681:
    goto v_12689;
v_12685:
    v_12745 = v_12746;
    goto v_12686;
v_12687:
    v_12744 = stack[0];
    goto v_12688;
v_12689:
    goto v_12685;
v_12686:
    goto v_12687;
v_12688:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_12745, v_12744);
    }
v_12682:
    v_12744 = stack[0];
    if (v_12744 == nil) goto v_12696;
    else goto v_12697;
v_12696:
    v_12744 = lisp_true;
    goto v_12695;
v_12697:
    goto v_12706;
v_12702:
    v_12745 = stack[-1];
    goto v_12703;
v_12704:
    v_12744 = stack[0];
    goto v_12705;
v_12706:
    goto v_12702;
v_12703:
    goto v_12704;
v_12705:
    v_12744 = (equal(v_12745, v_12744) ? lisp_true : nil);
    goto v_12695;
    v_12744 = nil;
v_12695:
    if (v_12744 == nil) goto v_12693;
    v_12744 = v_12746;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12744);
    }
v_12693:
    goto v_12718;
v_12714:
    v_12745 = stack[-1];
    goto v_12715;
v_12716:
    v_12744 = stack[0];
    v_12744 = qcar(v_12744);
    goto v_12717;
v_12718:
    goto v_12714;
v_12715:
    goto v_12716;
v_12717:
    if (equal(v_12745, v_12744)) goto v_12712;
    else goto v_12713;
v_12712:
    goto v_12727;
v_12723:
    v_12745 = v_12746;
    goto v_12724;
v_12725:
    v_12744 = stack[0];
    v_12744 = qcdr(v_12744);
    goto v_12726;
v_12727:
    goto v_12723;
v_12724:
    goto v_12725;
v_12726:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_12745, v_12744);
    }
v_12713:
    goto v_12738;
v_12734:
    v_12744 = stack[0];
    v_12744 = qcar(v_12744);
    goto v_12735;
v_12736:
    v_12745 = v_12746;
    goto v_12737;
v_12738:
    goto v_12734;
v_12735:
    goto v_12736;
v_12737:
    v_12744 = cons(v_12744, v_12745);
    env = stack[-2];
    v_12746 = v_12744;
    v_12744 = stack[0];
    v_12744 = qcdr(v_12744);
    stack[0] = v_12744;
    goto v_12678;
    v_12744 = nil;
    return onevalue(v_12744);
}



// Code for horner!-rule!-mod!-p

static LispObject CC_hornerKruleKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12828, v_12829, v_12830, v_12831, v_12832;
    LispObject fn;
    LispObject v_12676, v_12675, v_12674, v_12673, v_12672;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "horner-rule-mod-p");
    va_start(aa, nargs);
    v_12672 = va_arg(aa, LispObject);
    v_12673 = va_arg(aa, LispObject);
    v_12674 = va_arg(aa, LispObject);
    v_12675 = va_arg(aa, LispObject);
    v_12676 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_12676,v_12675,v_12674,v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_12672,v_12673,v_12674,v_12675,v_12676);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_12676;
    stack[-3] = v_12675;
    stack[-4] = v_12674;
    v_12830 = v_12673;
    v_12831 = v_12672;
// end of prologue
v_12671:
    v_12828 = stack[-4];
    if (!consp(v_12828)) goto v_12688;
    else goto v_12689;
v_12688:
    v_12828 = lisp_true;
    goto v_12687;
v_12689:
    v_12828 = stack[-4];
    v_12828 = qcar(v_12828);
    v_12828 = (consp(v_12828) ? nil : lisp_true);
    goto v_12687;
    v_12828 = nil;
v_12687:
    if (v_12828 == nil) goto v_12685;
    v_12828 = lisp_true;
    goto v_12683;
v_12685:
    goto v_12704;
v_12700:
    v_12828 = stack[-4];
    v_12828 = qcar(v_12828);
    v_12828 = qcar(v_12828);
    v_12829 = qcar(v_12828);
    goto v_12701;
v_12702:
    v_12828 = stack[-2];
    goto v_12703;
v_12704:
    goto v_12700;
v_12701:
    goto v_12702;
v_12703:
    v_12828 = (equal(v_12829, v_12828) ? lisp_true : nil);
    v_12828 = (v_12828 == nil ? lisp_true : nil);
    goto v_12683;
    v_12828 = nil;
v_12683:
    if (v_12828 == nil) goto v_12681;
    v_12828 = stack[-3];
    if (v_12828 == nil) goto v_12718;
    else goto v_12719;
v_12718:
    v_12828 = lisp_true;
    goto v_12717;
v_12719:
    v_12828 = stack[-3];
    v_12828 = (LispObject)zerop(v_12828);
    v_12828 = v_12828 ? lisp_true : nil;
    env = stack[-6];
    goto v_12717;
    v_12828 = nil;
v_12717:
    if (v_12828 == nil) goto v_12715;
    v_12828 = stack[-4];
    goto v_12713;
v_12715:
    goto v_12734;
v_12730:
    stack[0] = v_12831;
    goto v_12731;
v_12732:
    goto v_12741;
v_12737:
    v_12828 = stack[-3];
    goto v_12738;
v_12739:
    v_12829 = v_12830;
    goto v_12740;
v_12741:
    goto v_12737;
v_12738:
    goto v_12739;
v_12740:
    fn = elt(env, 1); // expt!-mod!-p
    v_12828 = (*qfn2(fn))(fn, v_12828, v_12829);
    env = stack[-6];
    goto v_12733;
v_12734:
    goto v_12730;
v_12731:
    goto v_12732;
v_12733:
    fn = elt(env, 2); // times!-mod!-p
    v_12828 = (*qfn2(fn))(fn, stack[0], v_12828);
    env = stack[-6];
    v_12831 = v_12828;
    goto v_12749;
v_12745:
    v_12828 = stack[-4];
    goto v_12746;
v_12747:
    v_12829 = v_12831;
    goto v_12748;
v_12749:
    goto v_12745;
v_12746:
    goto v_12747;
v_12748:
    {
        fn = elt(env, 3); // plus!-mod!-p
        return (*qfn2(fn))(fn, v_12828, v_12829);
    }
    v_12828 = nil;
v_12713:
    goto v_12679;
v_12681:
    v_12828 = stack[-4];
    v_12828 = qcar(v_12828);
    v_12828 = qcar(v_12828);
    v_12828 = qcdr(v_12828);
    stack[-5] = v_12828;
    goto v_12772;
v_12762:
    v_12828 = stack[-3];
    if (v_12828 == nil) goto v_12779;
    else goto v_12780;
v_12779:
    v_12828 = lisp_true;
    goto v_12778;
v_12780:
    v_12828 = stack[-3];
    v_12828 = (LispObject)zerop(v_12828);
    v_12828 = v_12828 ? lisp_true : nil;
    env = stack[-6];
    goto v_12778;
    v_12828 = nil;
v_12778:
    if (v_12828 == nil) goto v_12776;
    v_12828 = stack[-4];
    v_12828 = qcar(v_12828);
    v_12828 = qcdr(v_12828);
    v_12831 = v_12828;
    goto v_12774;
v_12776:
    goto v_12797;
v_12793:
    v_12828 = stack[-4];
    v_12828 = qcar(v_12828);
    stack[-1] = qcdr(v_12828);
    goto v_12794;
v_12795:
    goto v_12806;
v_12802:
    stack[0] = v_12831;
    goto v_12803;
v_12804:
    goto v_12813;
v_12809:
    v_12829 = stack[-3];
    goto v_12810;
v_12811:
    goto v_12819;
v_12815:
    goto v_12816;
v_12817:
    v_12828 = stack[-5];
    goto v_12818;
v_12819:
    goto v_12815;
v_12816:
    goto v_12817;
v_12818:
    v_12828 = (LispObject)(intptr_t)((intptr_t)v_12830 - (intptr_t)v_12828 + TAG_FIXNUM);
    goto v_12812;
v_12813:
    goto v_12809;
v_12810:
    goto v_12811;
v_12812:
    fn = elt(env, 1); // expt!-mod!-p
    v_12828 = (*qfn2(fn))(fn, v_12829, v_12828);
    env = stack[-6];
    goto v_12805;
v_12806:
    goto v_12802;
v_12803:
    goto v_12804;
v_12805:
    fn = elt(env, 2); // times!-mod!-p
    v_12828 = (*qfn2(fn))(fn, stack[0], v_12828);
    env = stack[-6];
    goto v_12796;
v_12797:
    goto v_12793;
v_12794:
    goto v_12795;
v_12796:
    fn = elt(env, 3); // plus!-mod!-p
    v_12828 = (*qfn2(fn))(fn, stack[-1], v_12828);
    env = stack[-6];
    v_12831 = v_12828;
    goto v_12774;
    v_12831 = nil;
v_12774:
    goto v_12763;
v_12764:
    v_12830 = stack[-5];
    goto v_12765;
v_12766:
    v_12828 = stack[-4];
    v_12832 = qcdr(v_12828);
    goto v_12767;
v_12768:
    v_12829 = stack[-3];
    goto v_12769;
v_12770:
    v_12828 = stack[-2];
    goto v_12771;
v_12772:
    goto v_12762;
v_12763:
    goto v_12764;
v_12765:
    goto v_12766;
v_12767:
    goto v_12768;
v_12769:
    goto v_12770;
v_12771:
    stack[-4] = v_12832;
    stack[-3] = v_12829;
    stack[-2] = v_12828;
    goto v_12671;
    goto v_12679;
    v_12828 = nil;
v_12679:
    return onevalue(v_12828);
}



// Code for getsetvars

static LispObject CC_getsetvars(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12740, v_12741;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12672;
// end of prologue
    stack[-1] = nil;
v_12677:
    v_12740 = stack[0];
    if (!consp(v_12740)) goto v_12680;
    else goto v_12681;
v_12680:
    v_12740 = stack[-1];
    {
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(fn, v_12740);
    }
v_12681:
    goto v_12691;
v_12687:
    v_12740 = stack[0];
    v_12741 = qcar(v_12740);
    goto v_12688;
v_12689:
    v_12740 = elt(env, 1); // (setel setk)
    goto v_12690;
v_12691:
    goto v_12687;
v_12688:
    goto v_12689;
v_12690:
    v_12740 = Lmemq(nil, v_12741, v_12740);
    if (v_12740 == nil) goto v_12686;
    goto v_12701;
v_12697:
    v_12740 = stack[0];
    v_12740 = qcdr(v_12740);
    v_12740 = qcar(v_12740);
    fn = elt(env, 4); // getsetvarlis
    v_12741 = (*qfn1(fn))(fn, v_12740);
    env = stack[-2];
    goto v_12698;
v_12699:
    v_12740 = stack[-1];
    goto v_12700;
v_12701:
    goto v_12697;
v_12698:
    goto v_12699;
v_12700:
    v_12740 = cons(v_12741, v_12740);
    env = stack[-2];
    stack[-1] = v_12740;
    v_12740 = stack[0];
    v_12740 = qcdr(v_12740);
    v_12740 = qcdr(v_12740);
    v_12740 = qcar(v_12740);
    stack[0] = v_12740;
    goto v_12677;
v_12686:
    goto v_12717;
v_12713:
    v_12740 = stack[0];
    v_12741 = qcar(v_12740);
    goto v_12714;
v_12715:
    v_12740 = elt(env, 2); // setq
    goto v_12716;
v_12717:
    goto v_12713;
v_12714:
    goto v_12715;
v_12716:
    if (v_12741 == v_12740) goto v_12711;
    else goto v_12712;
v_12711:
    goto v_12726;
v_12722:
    v_12740 = stack[0];
    v_12740 = qcdr(v_12740);
    v_12740 = qcar(v_12740);
    v_12741 = Lmkquote(nil, v_12740);
    env = stack[-2];
    goto v_12723;
v_12724:
    v_12740 = stack[-1];
    goto v_12725;
v_12726:
    goto v_12722;
v_12723:
    goto v_12724;
v_12725:
    v_12740 = cons(v_12741, v_12740);
    env = stack[-2];
    stack[-1] = v_12740;
    v_12740 = stack[0];
    v_12740 = qcdr(v_12740);
    v_12740 = qcdr(v_12740);
    v_12740 = qcar(v_12740);
    stack[0] = v_12740;
    goto v_12677;
v_12712:
    v_12740 = stack[-1];
    {
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(fn, v_12740);
    }
    v_12740 = nil;
    return onevalue(v_12740);
}



// Code for mchkopt1

static LispObject CC_mchkopt1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12859, v_12860, v_12861;
    LispObject fn;
    LispObject v_12674, v_12673, v_12672;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mchkopt1");
    va_start(aa, nargs);
    v_12672 = va_arg(aa, LispObject);
    v_12673 = va_arg(aa, LispObject);
    v_12674 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12674,v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12672,v_12673,v_12674);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_12674;
    v_12859 = v_12673;
    v_12861 = v_12672;
// end of prologue
    v_12859 = qcdr(v_12859);
    v_12860 = v_12859;
    if (v_12859 == nil) goto v_12683;
    else goto v_12684;
v_12683:
    v_12859 = nil;
    goto v_12680;
v_12684:
    v_12859 = v_12860;
    v_12859 = qcar(v_12859);
    stack[-3] = v_12859;
    v_12859 = v_12860;
    v_12859 = qcdr(v_12859);
    v_12860 = v_12859;
    if (v_12859 == nil) goto v_12692;
    else goto v_12693;
v_12692:
    v_12859 = nil;
    goto v_12680;
v_12693:
    v_12859 = v_12860;
    v_12859 = qcar(v_12859);
    stack[-5] = v_12859;
    v_12859 = v_12860;
    v_12859 = qcdr(v_12859);
    if (v_12859 == nil) goto v_12702;
    v_12859 = nil;
    goto v_12680;
v_12702:
    v_12859 = stack[-3];
    if (!symbolp(v_12859)) v_12859 = nil;
    else { v_12859 = qfastgets(v_12859);
           if (v_12859 != nil) { v_12859 = elt(v_12859, 6); // optional
#ifdef RECORD_GET
             if (v_12859 == SPID_NOPROP)
                record_get(elt(fastget_names, 6), 0),
                v_12859 = nil;
             else record_get(elt(fastget_names, 6), 1),
                v_12859 = lisp_true; }
           else record_get(elt(fastget_names, 6), 0); }
#else
             if (v_12859 == SPID_NOPROP) v_12859 = nil; else v_12859 = lisp_true; }}
#endif
    if (v_12859 == nil) goto v_12709;
    goto v_12723;
v_12719:
    v_12860 = v_12861;
    goto v_12720;
v_12721:
    v_12859 = stack[-5];
    goto v_12722;
v_12723:
    goto v_12719;
v_12720:
    goto v_12721;
v_12722:
    fn = elt(env, 1); // mchk
    v_12859 = (*qfn2(fn))(fn, v_12860, v_12859);
    env = stack[-6];
    stack[-5] = v_12859;
    v_12859 = stack[-5];
    if (v_12859 == nil) goto v_12728;
    else goto v_12729;
v_12728:
    v_12859 = nil;
    goto v_12716;
v_12729:
    v_12859 = stack[-5];
    v_12859 = qcar(v_12859);
    goto v_12743;
v_12737:
    v_12861 = stack[-3];
    goto v_12738;
v_12739:
    v_12860 = stack[-4];
    v_12860 = qcar(v_12860);
    goto v_12740;
v_12741:
    goto v_12742;
v_12743:
    goto v_12737;
v_12738:
    goto v_12739;
v_12740:
    goto v_12741;
v_12742:
    v_12859 = acons(v_12861, v_12860, v_12859);
    env = stack[-6];
    v_12859 = ncons(v_12859);
    env = stack[-6];
    stack[-1] = v_12859;
    stack[-2] = v_12859;
v_12717:
    v_12859 = stack[-5];
    v_12859 = qcdr(v_12859);
    stack[-5] = v_12859;
    v_12859 = stack[-5];
    if (v_12859 == nil) goto v_12752;
    else goto v_12753;
v_12752:
    v_12859 = stack[-2];
    goto v_12716;
v_12753:
    goto v_12761;
v_12757:
    stack[0] = stack[-1];
    goto v_12758;
v_12759:
    v_12859 = stack[-5];
    v_12859 = qcar(v_12859);
    goto v_12774;
v_12768:
    v_12861 = stack[-3];
    goto v_12769;
v_12770:
    v_12860 = stack[-4];
    v_12860 = qcar(v_12860);
    goto v_12771;
v_12772:
    goto v_12773;
v_12774:
    goto v_12768;
v_12769:
    goto v_12770;
v_12771:
    goto v_12772;
v_12773:
    v_12859 = acons(v_12861, v_12860, v_12859);
    env = stack[-6];
    v_12859 = ncons(v_12859);
    env = stack[-6];
    goto v_12760;
v_12761:
    goto v_12757;
v_12758:
    goto v_12759;
v_12760:
    v_12859 = Lrplacd(nil, stack[0], v_12859);
    env = stack[-6];
    v_12859 = stack[-1];
    v_12859 = qcdr(v_12859);
    stack[-1] = v_12859;
    goto v_12717;
v_12716:
    goto v_12707;
v_12709:
    v_12859 = stack[-5];
    if (!symbolp(v_12859)) v_12859 = nil;
    else { v_12859 = qfastgets(v_12859);
           if (v_12859 != nil) { v_12859 = elt(v_12859, 6); // optional
#ifdef RECORD_GET
             if (v_12859 == SPID_NOPROP)
                record_get(elt(fastget_names, 6), 0),
                v_12859 = nil;
             else record_get(elt(fastget_names, 6), 1),
                v_12859 = lisp_true; }
           else record_get(elt(fastget_names, 6), 0); }
#else
             if (v_12859 == SPID_NOPROP) v_12859 = nil; else v_12859 = lisp_true; }}
#endif
    if (v_12859 == nil) goto v_12782;
    goto v_12796;
v_12792:
    v_12860 = v_12861;
    goto v_12793;
v_12794:
    v_12859 = stack[-3];
    goto v_12795;
v_12796:
    goto v_12792;
v_12793:
    goto v_12794;
v_12795:
    fn = elt(env, 1); // mchk
    v_12859 = (*qfn2(fn))(fn, v_12860, v_12859);
    env = stack[-6];
    stack[-3] = v_12859;
    v_12859 = stack[-3];
    if (v_12859 == nil) goto v_12801;
    else goto v_12802;
v_12801:
    v_12859 = nil;
    goto v_12789;
v_12802:
    v_12859 = stack[-3];
    v_12859 = qcar(v_12859);
    goto v_12816;
v_12810:
    v_12861 = stack[-5];
    goto v_12811;
v_12812:
    v_12860 = stack[-4];
    v_12860 = qcdr(v_12860);
    v_12860 = qcar(v_12860);
    goto v_12813;
v_12814:
    goto v_12815;
v_12816:
    goto v_12810;
v_12811:
    goto v_12812;
v_12813:
    goto v_12814;
v_12815:
    v_12859 = acons(v_12861, v_12860, v_12859);
    env = stack[-6];
    v_12859 = ncons(v_12859);
    env = stack[-6];
    stack[-1] = v_12859;
    stack[-2] = v_12859;
v_12790:
    v_12859 = stack[-3];
    v_12859 = qcdr(v_12859);
    stack[-3] = v_12859;
    v_12859 = stack[-3];
    if (v_12859 == nil) goto v_12826;
    else goto v_12827;
v_12826:
    v_12859 = stack[-2];
    goto v_12789;
v_12827:
    goto v_12835;
v_12831:
    stack[0] = stack[-1];
    goto v_12832;
v_12833:
    v_12859 = stack[-3];
    v_12859 = qcar(v_12859);
    goto v_12848;
v_12842:
    v_12861 = stack[-5];
    goto v_12843;
v_12844:
    v_12860 = stack[-4];
    v_12860 = qcdr(v_12860);
    v_12860 = qcar(v_12860);
    goto v_12845;
v_12846:
    goto v_12847;
v_12848:
    goto v_12842;
v_12843:
    goto v_12844;
v_12845:
    goto v_12846;
v_12847:
    v_12859 = acons(v_12861, v_12860, v_12859);
    env = stack[-6];
    v_12859 = ncons(v_12859);
    env = stack[-6];
    goto v_12834;
v_12835:
    goto v_12831;
v_12832:
    goto v_12833;
v_12834:
    v_12859 = Lrplacd(nil, stack[0], v_12859);
    env = stack[-6];
    v_12859 = stack[-1];
    v_12859 = qcdr(v_12859);
    stack[-1] = v_12859;
    goto v_12790;
v_12789:
    goto v_12707;
v_12782:
    v_12859 = nil;
    goto v_12707;
    v_12859 = nil;
v_12707:
v_12680:
    return onevalue(v_12859);
}



// Code for ps!:evaluate

static LispObject CC_psTevaluate(LispObject env,
                         LispObject v_12673, LispObject v_12674)
{
    env = qenv(env);
    LispObject v_12729, v_12730;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12674,v_12673);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12673,v_12674);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_12674;
    v_12729 = v_12673;
// end of prologue
// Binding ps
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = v_12729; // ps
    goto v_12688;
v_12684:
    v_12730 = qvalue(elt(env, 1)); // ps
    goto v_12685;
v_12686:
    v_12729 = stack[-2];
    goto v_12687;
v_12688:
    goto v_12684;
v_12685:
    goto v_12686;
v_12687:
    fn = elt(env, 2); // ps!:get!-term
    v_12729 = (*qfn2(fn))(fn, v_12730, v_12729);
    env = stack[-4];
    stack[-1] = v_12729;
    v_12729 = stack[-1];
    if (v_12729 == nil) goto v_12694;
    v_12729 = stack[-1];
    goto v_12682;
v_12694:
    v_12729 = qvalue(elt(env, 1)); // ps
    fn = elt(env, 3); // ps!:last!-term
    v_12729 = (*qfn1(fn))(fn, v_12729);
    env = stack[-4];
    v_12729 = add1(v_12729);
    env = stack[-4];
    stack[0] = v_12729;
v_12700:
    goto v_12714;
v_12710:
    v_12730 = stack[-2];
    goto v_12711;
v_12712:
    v_12729 = stack[0];
    goto v_12713;
v_12714:
    goto v_12710;
v_12711:
    goto v_12712;
v_12713:
    v_12729 = difference2(v_12730, v_12729);
    env = stack[-4];
    v_12729 = Lminusp(nil, v_12729);
    env = stack[-4];
    if (v_12729 == nil) goto v_12707;
    goto v_12699;
v_12707:
    goto v_12723;
v_12719:
    v_12730 = qvalue(elt(env, 1)); // ps
    goto v_12720;
v_12721:
    v_12729 = stack[0];
    goto v_12722;
v_12723:
    goto v_12719;
v_12720:
    goto v_12721;
v_12722:
    fn = elt(env, 4); // ps!:evaluate!-next
    v_12729 = (*qfn2(fn))(fn, v_12730, v_12729);
    env = stack[-4];
    stack[-1] = v_12729;
    v_12729 = stack[0];
    v_12729 = add1(v_12729);
    env = stack[-4];
    stack[0] = v_12729;
    goto v_12700;
v_12699:
    v_12729 = stack[-1];
v_12682:
    ;}  // end of a binding scope
    return onevalue(v_12729);
}



// Code for reform!-minus

static LispObject CC_reformKminus(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12784, v_12785, v_12786;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12673;
    stack[-1] = v_12672;
// end of prologue
    v_12784 = stack[0];
    if (v_12784 == nil) goto v_12681;
    else goto v_12682;
v_12681:
    v_12784 = lisp_true;
    goto v_12680;
v_12682:
    v_12784 = stack[-1];
    v_12784 = (v_12784 == nil ? lisp_true : nil);
    goto v_12680;
    v_12784 = nil;
v_12680:
    if (v_12784 == nil) goto v_12678;
    v_12784 = stack[-1];
    goto v_12676;
v_12678:
    v_12784 = stack[-1];
    v_12784 = qcar(v_12784);
    goto v_12700;
v_12696:
    goto v_12714;
v_12710:
    v_12785 = stack[0];
    v_12786 = qcar(v_12785);
    goto v_12711;
v_12712:
    v_12785 = elt(env, 1); // minus
    goto v_12713;
v_12714:
    goto v_12710;
v_12711:
    goto v_12712;
v_12713:
    if (!consp(v_12786)) goto v_12708;
    v_12786 = qcar(v_12786);
    if (v_12786 == v_12785) goto v_12707;
    else goto v_12708;
v_12707:
    goto v_12727;
v_12723:
    v_12786 = v_12784;
    goto v_12724;
v_12725:
    v_12785 = elt(env, 2); // quotient
    goto v_12726;
v_12727:
    goto v_12723;
v_12724:
    goto v_12725;
v_12726:
    if (!consp(v_12786)) goto v_12721;
    v_12786 = qcar(v_12786);
    if (v_12786 == v_12785) goto v_12720;
    else goto v_12721;
v_12720:
    goto v_12735;
v_12731:
    v_12785 = v_12784;
    v_12785 = qcdr(v_12785);
    v_12786 = qcar(v_12785);
    goto v_12732;
v_12733:
    v_12785 = elt(env, 1); // minus
    goto v_12734;
v_12735:
    goto v_12731;
v_12732:
    goto v_12733;
v_12734:
    v_12785 = Leqcar(nil, v_12786, v_12785);
    env = stack[-3];
    goto v_12719;
v_12721:
    v_12785 = nil;
    goto v_12719;
    v_12785 = nil;
v_12719:
    goto v_12706;
v_12708:
    v_12785 = nil;
    goto v_12706;
    v_12785 = nil;
v_12706:
    if (v_12785 == nil) goto v_12704;
    goto v_12751;
v_12747:
    stack[-2] = elt(env, 1); // minus
    goto v_12748;
v_12749:
    goto v_12760;
v_12754:
    v_12786 = elt(env, 2); // quotient
    goto v_12755;
v_12756:
    v_12785 = v_12784;
    v_12785 = qcdr(v_12785);
    v_12785 = qcar(v_12785);
    v_12785 = qcdr(v_12785);
    v_12785 = qcar(v_12785);
    goto v_12757;
v_12758:
    v_12784 = qcdr(v_12784);
    v_12784 = qcdr(v_12784);
    v_12784 = qcar(v_12784);
    goto v_12759;
v_12760:
    goto v_12754;
v_12755:
    goto v_12756;
v_12757:
    goto v_12758;
v_12759:
    v_12784 = list3(v_12786, v_12785, v_12784);
    env = stack[-3];
    goto v_12750;
v_12751:
    goto v_12747;
v_12748:
    goto v_12749;
v_12750:
    v_12784 = list2(stack[-2], v_12784);
    env = stack[-3];
    stack[-2] = v_12784;
    goto v_12702;
v_12704:
    stack[-2] = v_12784;
    goto v_12702;
    stack[-2] = nil;
v_12702:
    goto v_12697;
v_12698:
    goto v_12779;
v_12775:
    v_12784 = stack[-1];
    v_12785 = qcdr(v_12784);
    goto v_12776;
v_12777:
    v_12784 = stack[0];
    v_12784 = qcdr(v_12784);
    goto v_12778;
v_12779:
    goto v_12775;
v_12776:
    goto v_12777;
v_12778:
    v_12784 = CC_reformKminus(elt(env, 0), v_12785, v_12784);
    goto v_12699;
v_12700:
    goto v_12696;
v_12697:
    goto v_12698;
v_12699:
    {
        LispObject v_12790 = stack[-2];
        return cons(v_12790, v_12784);
    }
    v_12784 = nil;
v_12676:
    return onevalue(v_12784);
}



// Code for setmat

static LispObject CC_setmat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12731, v_12732, v_12733;
    LispObject fn;
    LispObject v_12675, v_12674, v_12673, v_12672;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "setmat");
    va_start(aa, nargs);
    v_12672 = va_arg(aa, LispObject);
    v_12673 = va_arg(aa, LispObject);
    v_12674 = va_arg(aa, LispObject);
    v_12675 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_12675,v_12674,v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_12672,v_12673,v_12674,v_12675);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_12675;
    stack[-1] = v_12674;
    stack[-2] = v_12673;
    stack[-3] = v_12672;
// end of prologue
    v_12731 = qvalue(elt(env, 1)); // !*modular
    if (v_12731 == nil) goto v_12680;
    v_12731 = elt(env, 2); // modular
    v_12731 = ncons(v_12731);
    env = stack[-4];
    fn = elt(env, 5); // off
    v_12731 = (*qfn1(fn))(fn, v_12731);
    env = stack[-4];
    v_12731 = elt(env, 3); // mod_was_on
    v_12731 = ncons(v_12731);
    env = stack[-4];
    fn = elt(env, 6); // on
    v_12731 = (*qfn1(fn))(fn, v_12731);
    env = stack[-4];
    goto v_12678;
v_12680:
v_12678:
    v_12731 = stack[-2];
    fn = elt(env, 7); // reval
    v_12731 = (*qfn1(fn))(fn, v_12731);
    env = stack[-4];
    stack[-2] = v_12731;
    v_12731 = stack[-1];
    fn = elt(env, 7); // reval
    v_12731 = (*qfn1(fn))(fn, v_12731);
    env = stack[-4];
    stack[-1] = v_12731;
    v_12731 = stack[0];
    fn = elt(env, 7); // reval
    v_12731 = (*qfn1(fn))(fn, v_12731);
    env = stack[-4];
    fn = elt(env, 8); // simp
    v_12731 = (*qfn1(fn))(fn, v_12731);
    env = stack[-4];
    fn = elt(env, 9); // mk!*sq
    v_12731 = (*qfn1(fn))(fn, v_12731);
    env = stack[-4];
    stack[0] = v_12731;
    goto v_12704;
v_12698:
    goto v_12712;
v_12706:
    v_12733 = stack[-3];
    goto v_12707;
v_12708:
    v_12732 = stack[-2];
    goto v_12709;
v_12710:
    v_12731 = stack[-1];
    goto v_12711;
v_12712:
    goto v_12706;
v_12707:
    goto v_12708;
v_12709:
    goto v_12710;
v_12711:
    v_12733 = list3(v_12733, v_12732, v_12731);
    env = stack[-4];
    goto v_12699;
v_12700:
    v_12732 = stack[0];
    goto v_12701;
v_12702:
    v_12731 = stack[-3];
    goto v_12703;
v_12704:
    goto v_12698;
v_12699:
    goto v_12700;
v_12701:
    goto v_12702;
v_12703:
    fn = elt(env, 10); // letmtr
    v_12731 = (*qfnn(fn))(fn, 3, v_12733, v_12732, v_12731);
    env = stack[-4];
    v_12731 = qvalue(elt(env, 4)); // !*mod_was_on
    if (v_12731 == nil) goto v_12721;
    v_12731 = elt(env, 2); // modular
    v_12731 = ncons(v_12731);
    env = stack[-4];
    fn = elt(env, 6); // on
    v_12731 = (*qfn1(fn))(fn, v_12731);
    env = stack[-4];
    v_12731 = elt(env, 3); // mod_was_on
    v_12731 = ncons(v_12731);
    env = stack[-4];
    fn = elt(env, 5); // off
    v_12731 = (*qfn1(fn))(fn, v_12731);
    goto v_12719;
v_12721:
v_12719:
    v_12731 = stack[-3];
    return onevalue(v_12731);
}



// Code for freeoffl

static LispObject CC_freeoffl(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12708, v_12709;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12673;
    stack[-1] = v_12672;
// end of prologue
v_12671:
    v_12708 = stack[0];
    if (v_12708 == nil) goto v_12677;
    else goto v_12678;
v_12677:
    v_12708 = lisp_true;
    goto v_12676;
v_12678:
    goto v_12692;
v_12688:
    v_12709 = stack[-1];
    goto v_12689;
v_12690:
    v_12708 = stack[0];
    v_12708 = qcar(v_12708);
    goto v_12691;
v_12692:
    goto v_12688;
v_12689:
    goto v_12690;
v_12691:
    fn = elt(env, 1); // freeoff
    v_12708 = (*qfn2(fn))(fn, v_12709, v_12708);
    env = stack[-2];
    if (v_12708 == nil) goto v_12685;
    else goto v_12686;
v_12685:
    v_12708 = nil;
    goto v_12684;
v_12686:
    goto v_12704;
v_12700:
    v_12709 = stack[-1];
    goto v_12701;
v_12702:
    v_12708 = stack[0];
    v_12708 = qcdr(v_12708);
    goto v_12703;
v_12704:
    goto v_12700;
v_12701:
    goto v_12702;
v_12703:
    stack[-1] = v_12709;
    stack[0] = v_12708;
    goto v_12671;
    v_12708 = nil;
v_12684:
    goto v_12676;
    v_12708 = nil;
v_12676:
    return onevalue(v_12708);
}



// Code for indordp

static LispObject CC_indordp(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12732, v_12733, v_12734, v_12735, v_12736;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12734 = v_12673;
    v_12735 = v_12672;
// end of prologue
    v_12732 = qvalue(elt(env, 1)); // indxl!*
    v_12736 = v_12732;
    goto v_12688;
v_12684:
    v_12733 = v_12735;
    goto v_12685;
v_12686:
    v_12732 = v_12736;
    goto v_12687;
v_12688:
    goto v_12684;
v_12685:
    goto v_12686;
v_12687:
    v_12732 = Lmemq(nil, v_12733, v_12732);
    if (v_12732 == nil) goto v_12682;
    else goto v_12683;
v_12682:
    v_12732 = lisp_true;
    goto v_12677;
v_12683:
v_12678:
    v_12732 = v_12736;
    if (v_12732 == nil) goto v_12695;
    else goto v_12696;
v_12695:
    goto v_12703;
v_12699:
    v_12732 = v_12735;
    goto v_12700;
v_12701:
    v_12733 = v_12734;
    goto v_12702;
v_12703:
    goto v_12699;
v_12700:
    goto v_12701;
v_12702:
        return Lorderp(nil, v_12732, v_12733);
v_12696:
    goto v_12714;
v_12710:
    v_12733 = v_12735;
    goto v_12711;
v_12712:
    v_12732 = v_12736;
    v_12732 = qcar(v_12732);
    goto v_12713;
v_12714:
    goto v_12710;
v_12711:
    goto v_12712;
v_12713:
    if (v_12733 == v_12732) goto v_12708;
    else goto v_12709;
v_12708:
    v_12732 = lisp_true;
    goto v_12677;
v_12709:
    goto v_12725;
v_12721:
    v_12733 = v_12734;
    goto v_12722;
v_12723:
    v_12732 = v_12736;
    v_12732 = qcar(v_12732);
    goto v_12724;
v_12725:
    goto v_12721;
v_12722:
    goto v_12723;
v_12724:
    if (v_12733 == v_12732) goto v_12719;
    else goto v_12720;
v_12719:
    v_12732 = nil;
    goto v_12677;
v_12720:
    v_12732 = v_12736;
    v_12732 = qcdr(v_12732);
    v_12736 = v_12732;
    goto v_12678;
v_12677:
    return onevalue(v_12732);
}



// Code for symbvarlst

static LispObject CC_symbvarlst(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12779, v_12780, v_12781;
    LispObject fn;
    LispObject v_12674, v_12673, v_12672;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "symbvarlst");
    va_start(aa, nargs);
    v_12672 = va_arg(aa, LispObject);
    v_12673 = va_arg(aa, LispObject);
    v_12674 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12674,v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12672,v_12673,v_12674);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_12779 = v_12674;
    stack[-3] = v_12673;
    v_12781 = v_12672;
// end of prologue
    goto v_12688;
v_12684:
    v_12780 = v_12779;
    goto v_12685;
v_12686:
    v_12779 = elt(env, 1); // symbolic
    goto v_12687;
v_12688:
    goto v_12684;
v_12685:
    goto v_12686;
v_12687:
    if (v_12780 == v_12779) goto v_12683;
    v_12779 = nil;
    goto v_12679;
v_12683:
    v_12779 = v_12781;
    stack[-4] = v_12779;
v_12695:
    v_12779 = stack[-4];
    if (v_12779 == nil) goto v_12698;
    else goto v_12699;
v_12698:
    goto v_12694;
v_12699:
    v_12779 = stack[-4];
    v_12779 = qcar(v_12779);
    v_12779 = Lconsp(nil, v_12779);
    env = stack[-5];
    if (v_12779 == nil) goto v_12705;
    v_12779 = stack[-4];
    v_12779 = qcar(v_12779);
    v_12779 = qcar(v_12779);
    goto v_12703;
v_12705:
    v_12779 = stack[-4];
    v_12779 = qcar(v_12779);
    goto v_12703;
    v_12779 = nil;
v_12703:
    stack[0] = v_12779;
    v_12779 = stack[0];
    v_12779 = Lsymbol_specialp(nil, v_12779);
    env = stack[-5];
    if (v_12779 == nil) goto v_12722;
    else goto v_12723;
v_12722:
    v_12779 = stack[0];
    v_12779 = Lsymbol_globalp(nil, v_12779);
    env = stack[-5];
    if (v_12779 == nil) goto v_12728;
    else goto v_12729;
v_12728:
    goto v_12741;
v_12737:
    v_12780 = stack[0];
    goto v_12738;
v_12739:
    v_12779 = stack[-3];
    goto v_12740;
v_12741:
    goto v_12737;
v_12738:
    goto v_12739;
v_12740:
    v_12779 = Lsmemq(nil, v_12780, v_12779);
    env = stack[-5];
    if (v_12779 == nil) goto v_12734;
    else goto v_12735;
v_12734:
    v_12779 = qvalue(elt(env, 2)); // !*novarmsg
    v_12779 = (v_12779 == nil ? lisp_true : nil);
    goto v_12733;
v_12735:
    v_12779 = nil;
    goto v_12733;
    v_12779 = nil;
v_12733:
    goto v_12727;
v_12729:
    v_12779 = nil;
    goto v_12727;
    v_12779 = nil;
v_12727:
    goto v_12721;
v_12723:
    v_12779 = nil;
    goto v_12721;
    v_12779 = nil;
v_12721:
    if (v_12779 == nil) goto v_12719;
    goto v_12765;
v_12757:
    stack[-2] = elt(env, 3); // "local variable"
    goto v_12758;
v_12759:
    stack[-1] = stack[0];
    goto v_12760;
v_12761:
    stack[0] = elt(env, 4); // "in procedure"
    goto v_12762;
v_12763:
    goto v_12774;
v_12770:
    v_12780 = qvalue(elt(env, 5)); // fname!*
    goto v_12771;
v_12772:
    v_12779 = elt(env, 6); // "not used"
    goto v_12773;
v_12774:
    goto v_12770;
v_12771:
    goto v_12772;
v_12773:
    v_12779 = list2(v_12780, v_12779);
    env = stack[-5];
    goto v_12764;
v_12765:
    goto v_12757;
v_12758:
    goto v_12759;
v_12760:
    goto v_12761;
v_12762:
    goto v_12763;
v_12764:
    v_12779 = list3star(stack[-2], stack[-1], stack[0], v_12779);
    env = stack[-5];
    fn = elt(env, 7); // lprim
    v_12779 = (*qfn1(fn))(fn, v_12779);
    env = stack[-5];
    goto v_12717;
v_12719:
v_12717:
    v_12779 = stack[-4];
    v_12779 = qcdr(v_12779);
    stack[-4] = v_12779;
    goto v_12695;
v_12694:
    v_12779 = nil;
v_12679:
    return onevalue(v_12779);
}



// Code for mv!-domainlist!-!+

static LispObject CC_mvKdomainlistKL(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12709, v_12710;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12673;
    stack[-1] = v_12672;
// end of prologue
    stack[-2] = nil;
v_12678:
    v_12709 = stack[-1];
    if (v_12709 == nil) goto v_12681;
    else goto v_12682;
v_12681:
    v_12709 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12709);
    }
v_12682:
    goto v_12693;
v_12689:
    goto v_12699;
v_12695:
    v_12709 = stack[-1];
    v_12710 = qcar(v_12709);
    goto v_12696;
v_12697:
    v_12709 = stack[0];
    v_12709 = qcar(v_12709);
    goto v_12698;
v_12699:
    goto v_12695;
v_12696:
    goto v_12697;
v_12698:
    v_12710 = plus2(v_12710, v_12709);
    env = stack[-3];
    goto v_12690;
v_12691:
    v_12709 = stack[-2];
    goto v_12692;
v_12693:
    goto v_12689;
v_12690:
    goto v_12691;
v_12692:
    v_12709 = cons(v_12710, v_12709);
    env = stack[-3];
    stack[-2] = v_12709;
    v_12709 = stack[-1];
    v_12709 = qcdr(v_12709);
    stack[-1] = v_12709;
    v_12709 = stack[0];
    v_12709 = qcdr(v_12709);
    stack[0] = v_12709;
    goto v_12678;
    v_12709 = nil;
    return onevalue(v_12709);
}



// Code for mo_lcm

static LispObject CC_mo_lcm(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12753, v_12754;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_12754 = v_12673;
    v_12753 = v_12672;
// end of prologue
    stack[-2] = nil;
    v_12753 = qcar(v_12753);
    stack[-1] = v_12753;
    v_12753 = v_12754;
    v_12753 = qcar(v_12753);
    stack[0] = v_12753;
v_12686:
    v_12753 = stack[-1];
    if (v_12753 == nil) goto v_12689;
    v_12753 = stack[0];
    if (v_12753 == nil) goto v_12689;
    goto v_12690;
v_12689:
    goto v_12685;
v_12690:
    goto v_12701;
v_12697:
    goto v_12710;
v_12706:
    v_12753 = stack[-1];
    v_12754 = qcar(v_12753);
    goto v_12707;
v_12708:
    v_12753 = stack[0];
    v_12753 = qcar(v_12753);
    goto v_12709;
v_12710:
    goto v_12706;
v_12707:
    goto v_12708;
v_12709:
    if (((intptr_t)(v_12754)) > ((intptr_t)(v_12753))) goto v_12704;
    else goto v_12705;
v_12704:
    v_12753 = stack[-1];
    v_12753 = qcar(v_12753);
    v_12754 = v_12753;
    goto v_12703;
v_12705:
    v_12753 = stack[0];
    v_12753 = qcar(v_12753);
    v_12754 = v_12753;
    goto v_12703;
    v_12754 = nil;
v_12703:
    goto v_12698;
v_12699:
    v_12753 = stack[-2];
    goto v_12700;
v_12701:
    goto v_12697;
v_12698:
    goto v_12699;
v_12700:
    v_12753 = cons(v_12754, v_12753);
    env = stack[-3];
    stack[-2] = v_12753;
    v_12753 = stack[-1];
    v_12753 = qcdr(v_12753);
    stack[-1] = v_12753;
    v_12753 = stack[0];
    v_12753 = qcdr(v_12753);
    stack[0] = v_12753;
    goto v_12686;
v_12685:
    goto v_12731;
v_12727:
    v_12753 = stack[-2];
    v_12754 = Lnreverse(nil, v_12753);
    env = stack[-3];
    goto v_12728;
v_12729:
    v_12753 = stack[-1];
    if (v_12753 == nil) goto v_12737;
    v_12753 = stack[-1];
    goto v_12735;
v_12737:
    v_12753 = stack[0];
    goto v_12735;
    v_12753 = nil;
v_12735:
    goto v_12730;
v_12731:
    goto v_12727;
v_12728:
    goto v_12729;
v_12730:
    v_12753 = Lappend(nil, v_12754, v_12753);
    env = stack[-3];
    stack[-2] = v_12753;
    goto v_12748;
v_12744:
    v_12753 = stack[-2];
    fn = elt(env, 1); // mo!=shorten
    stack[0] = (*qfn1(fn))(fn, v_12753);
    env = stack[-3];
    goto v_12745;
v_12746:
    v_12753 = stack[-2];
    fn = elt(env, 2); // mo!=deglist
    v_12753 = (*qfn1(fn))(fn, v_12753);
    goto v_12747;
v_12748:
    goto v_12744;
v_12745:
    goto v_12746;
v_12747:
    {
        LispObject v_12758 = stack[0];
        return cons(v_12758, v_12753);
    }
    return onevalue(v_12753);
}



// Code for arglist_member

static LispObject CC_arglist_member(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12704, v_12705;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12673;
    stack[-1] = v_12672;
// end of prologue
v_12671:
    v_12704 = stack[0];
    if (!consp(v_12704)) goto v_12678;
    goto v_12688;
v_12684:
    v_12705 = stack[-1];
    goto v_12685;
v_12686:
    v_12704 = stack[0];
    v_12704 = qcar(v_12704);
    goto v_12687;
v_12688:
    goto v_12684;
v_12685:
    goto v_12686;
v_12687:
    fn = elt(env, 1); // mvar_member
    v_12704 = (*qfn2(fn))(fn, v_12705, v_12704);
    env = stack[-2];
    if (v_12704 == nil) goto v_12682;
    else goto v_12681;
v_12682:
    goto v_12697;
v_12693:
    v_12705 = stack[-1];
    goto v_12694;
v_12695:
    v_12704 = stack[0];
    v_12704 = qcdr(v_12704);
    goto v_12696;
v_12697:
    goto v_12693;
v_12694:
    goto v_12695;
v_12696:
    stack[-1] = v_12705;
    stack[0] = v_12704;
    goto v_12671;
v_12681:
    goto v_12676;
v_12678:
    v_12704 = nil;
    goto v_12676;
    v_12704 = nil;
v_12676:
    return onevalue(v_12704);
}



// Code for drop_rl_with

static LispObject CC_drop_rl_with(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12700, v_12701, v_12702;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_12700 = v_12673;
    v_12701 = v_12672;
// end of prologue
    goto v_12682;
v_12676:
    stack[-1] = v_12700;
    goto v_12677;
v_12678:
    stack[0] = elt(env, 1); // rl_with
    goto v_12679;
v_12680:
    goto v_12690;
v_12686:
    v_12702 = v_12701;
    goto v_12687;
v_12688:
    goto v_12697;
v_12693:
    v_12701 = v_12700;
    goto v_12694;
v_12695:
    v_12700 = elt(env, 1); // rl_with
    goto v_12696;
v_12697:
    goto v_12693;
v_12694:
    goto v_12695;
v_12696:
    v_12700 = get(v_12701, v_12700);
    env = stack[-2];
    goto v_12689;
v_12690:
    goto v_12686;
v_12687:
    goto v_12688;
v_12689:
    v_12700 = Ldelete(nil, v_12702, v_12700);
    goto v_12681;
v_12682:
    goto v_12676;
v_12677:
    goto v_12678;
v_12679:
    goto v_12680;
v_12681:
    {
        LispObject v_12705 = stack[-1];
        LispObject v_12706 = stack[0];
        return Lputprop(nil, 3, v_12705, v_12706, v_12700);
    }
}



// Code for yypeek

static LispObject CC_yypeek(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12683;
    LispObject fn;
    argcheck(nargs, 0, "yypeek");
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
// Binding lex_char
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = nil; // lex_char
    v_12683 = qvalue(elt(env, 2)); // lex_peek_char
    if (v_12683 == nil) goto v_12678;
    else goto v_12679;
v_12678:
    fn = elt(env, 3); // yyreadch
    v_12683 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_12683; // lex_peek_char
    goto v_12677;
v_12679:
v_12677:
    v_12683 = qvalue(elt(env, 2)); // lex_peek_char
    ;}  // end of a binding scope
    return onevalue(v_12683);
}



// Code for collect_cdrs

static LispObject CC_collect_cdrs(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12699, v_12700;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_12672;
// end of prologue
    v_12700 = nil;
v_12677:
    v_12699 = stack[0];
    if (v_12699 == nil) goto v_12680;
    else goto v_12681;
v_12680:
    v_12699 = v_12700;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12699);
    }
v_12681:
    goto v_12692;
v_12688:
    v_12699 = stack[0];
    v_12699 = qcar(v_12699);
    v_12699 = qcdr(v_12699);
    goto v_12689;
v_12690:
    goto v_12691;
v_12692:
    goto v_12688;
v_12689:
    goto v_12690;
v_12691:
    v_12699 = cons(v_12699, v_12700);
    env = stack[-1];
    v_12700 = v_12699;
    v_12699 = stack[0];
    v_12699 = qcdr(v_12699);
    stack[0] = v_12699;
    goto v_12677;
    v_12699 = nil;
    return onevalue(v_12699);
}



// Code for setqget

static LispObject CC_setqget(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12700, v_12701;
    argcheck(nargs, 0, "setqget");
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
    v_12700 = qvalue(elt(env, 1)); // fluidbibasissetq
    v_12700 = qcar(v_12700);
    stack[-1] = v_12700;
    v_12700 = qvalue(elt(env, 1)); // fluidbibasissetq
    stack[0] = v_12700;
    goto v_12685;
v_12681:
    goto v_12691;
v_12687:
    v_12701 = stack[0];
    goto v_12688;
v_12689:
    v_12700 = stack[0];
    v_12700 = qcdr(v_12700);
    v_12700 = qcar(v_12700);
    goto v_12690;
v_12691:
    goto v_12687;
v_12688:
    goto v_12689;
v_12690:
    v_12701 = Lrplaca(nil, v_12701, v_12700);
    env = stack[-2];
    goto v_12682;
v_12683:
    v_12700 = stack[0];
    v_12700 = qcdr(v_12700);
    v_12700 = qcdr(v_12700);
    goto v_12684;
v_12685:
    goto v_12681;
v_12682:
    goto v_12683;
v_12684:
    v_12700 = Lrplacd(nil, v_12701, v_12700);
    v_12700 = stack[-1];
    return onevalue(v_12700);
}



// Code for reln

static LispObject CC_reln(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12701, v_12702;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12673;
    stack[-1] = v_12672;
// end of prologue
    v_12701 = elt(env, 1); // "<apply>"
    fn = elt(env, 5); // printout
    v_12701 = (*qfn1(fn))(fn, v_12701);
    env = stack[-2];
    v_12701 = elt(env, 2); // "<"
    v_12701 = Lprinc(nil, v_12701);
    env = stack[-2];
    v_12701 = stack[0];
    v_12701 = Lprinc(nil, v_12701);
    env = stack[-2];
    goto v_12688;
v_12684:
    v_12701 = stack[-1];
    v_12702 = qcar(v_12701);
    goto v_12685;
v_12686:
    v_12701 = elt(env, 3); // "/"
    goto v_12687;
v_12688:
    goto v_12684;
v_12685:
    goto v_12686;
v_12687:
    fn = elt(env, 6); // attributesml
    v_12701 = (*qfn2(fn))(fn, v_12702, v_12701);
    env = stack[-2];
    v_12701 = lisp_true;
    fn = elt(env, 7); // indent!*
    v_12701 = (*qfn1(fn))(fn, v_12701);
    env = stack[-2];
    v_12701 = stack[-1];
    v_12701 = qcdr(v_12701);
    fn = elt(env, 8); // multi_elem
    v_12701 = (*qfn1(fn))(fn, v_12701);
    env = stack[-2];
    v_12701 = nil;
    fn = elt(env, 7); // indent!*
    v_12701 = (*qfn1(fn))(fn, v_12701);
    env = stack[-2];
    v_12701 = elt(env, 4); // "</apply>"
    fn = elt(env, 5); // printout
    v_12701 = (*qfn1(fn))(fn, v_12701);
    v_12701 = nil;
    return onevalue(v_12701);
}



// Code for ps!:prepfn!:

static LispObject CC_psTprepfnT(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12675;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12675 = v_12672;
// end of prologue
    return onevalue(v_12675);
}



// Code for diffsq

static LispObject CC_diffsq(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12722, v_12723;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_12673;
    stack[-2] = v_12672;
// end of prologue
    goto v_12680;
v_12676:
    goto v_12686;
v_12682:
    goto v_12692;
v_12688:
    v_12722 = stack[-2];
    v_12723 = qcar(v_12722);
    goto v_12689;
v_12690:
    v_12722 = stack[-1];
    goto v_12691;
v_12692:
    goto v_12688;
v_12689:
    goto v_12690;
v_12691:
    fn = elt(env, 1); // difff
    stack[-3] = (*qfn2(fn))(fn, v_12723, v_12722);
    env = stack[-4];
    goto v_12683;
v_12684:
    goto v_12702;
v_12698:
    stack[0] = stack[-2];
    goto v_12699;
v_12700:
    goto v_12709;
v_12705:
    v_12722 = stack[-2];
    v_12723 = qcdr(v_12722);
    goto v_12706;
v_12707:
    v_12722 = stack[-1];
    goto v_12708;
v_12709:
    goto v_12705;
v_12706:
    goto v_12707;
v_12708:
    fn = elt(env, 1); // difff
    v_12722 = (*qfn2(fn))(fn, v_12723, v_12722);
    env = stack[-4];
    goto v_12701;
v_12702:
    goto v_12698;
v_12699:
    goto v_12700;
v_12701:
    fn = elt(env, 2); // multsq
    v_12722 = (*qfn2(fn))(fn, stack[0], v_12722);
    env = stack[-4];
    fn = elt(env, 3); // negsq
    v_12722 = (*qfn1(fn))(fn, v_12722);
    env = stack[-4];
    goto v_12685;
v_12686:
    goto v_12682;
v_12683:
    goto v_12684;
v_12685:
    fn = elt(env, 4); // addsq
    stack[0] = (*qfn2(fn))(fn, stack[-3], v_12722);
    env = stack[-4];
    goto v_12677;
v_12678:
    goto v_12718;
v_12714:
    v_12723 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12715;
v_12716:
    v_12722 = stack[-2];
    v_12722 = qcdr(v_12722);
    goto v_12717;
v_12718:
    goto v_12714;
v_12715:
    goto v_12716;
v_12717:
    v_12722 = cons(v_12723, v_12722);
    env = stack[-4];
    goto v_12679;
v_12680:
    goto v_12676;
v_12677:
    goto v_12678;
v_12679:
    {
        LispObject v_12728 = stack[0];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_12728, v_12722);
    }
}



// Code for xdegreecheck

static LispObject CC_xdegreecheck(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12691, v_12692;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12692 = v_12672;
// end of prologue
    v_12691 = qvalue(elt(env, 1)); // xtruncate!*
    if (v_12691 == nil) goto v_12676;
    else goto v_12677;
v_12676:
    v_12691 = nil;
    goto v_12675;
v_12677:
    goto v_12687;
v_12683:
    v_12691 = v_12692;
    fn = elt(env, 2); // xdegree
    v_12691 = (*qfn1(fn))(fn, v_12691);
    env = stack[0];
    goto v_12684;
v_12685:
    v_12692 = qvalue(elt(env, 1)); // xtruncate!*
    goto v_12686;
v_12687:
    goto v_12683;
v_12684:
    goto v_12685;
v_12686:
        return Lgreaterp(nil, v_12691, v_12692);
    v_12691 = nil;
v_12675:
    return onevalue(v_12691);
}



// Code for fortexp

static LispObject CC_fortexp(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12682, v_12683;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12682 = v_12672;
// end of prologue
    goto v_12679;
v_12675:
    v_12683 = v_12682;
    goto v_12676;
v_12677:
    v_12682 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12678;
v_12679:
    goto v_12675;
v_12676:
    goto v_12677;
v_12678:
    {
        fn = elt(env, 1); // fortexp1
        return (*qfn2(fn))(fn, v_12683, v_12682);
    }
}



// Code for physopsm!*

static LispObject CC_physopsmH(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12939, v_12940, v_12941, v_12942;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_12672;
// end of prologue
    stack[0] = nil;
    v_12939 = stack[-3];
    if (v_12939 == nil) goto v_12687;
    else goto v_12688;
v_12687:
    v_12939 = lisp_true;
    goto v_12686;
v_12688:
    v_12939 = stack[-3];
    v_12939 = (is_number(v_12939) ? lisp_true : nil);
    goto v_12686;
    v_12939 = nil;
v_12686:
    if (v_12939 == nil) goto v_12684;
    v_12939 = stack[-3];
    stack[0] = v_12939;
    goto v_12682;
v_12684:
    v_12939 = stack[-3];
    fn = elt(env, 11); // physopp
    v_12939 = (*qfn1(fn))(fn, v_12939);
    env = stack[-5];
    if (v_12939 == nil) goto v_12697;
    v_12939 = stack[-3];
    if (!symbolp(v_12939)) v_12939 = nil;
    else { v_12939 = qfastgets(v_12939);
           if (v_12939 != nil) { v_12939 = elt(v_12939, 46); // rvalue
#ifdef RECORD_GET
             if (v_12939 != SPID_NOPROP)
                record_get(elt(fastget_names, 46), 1);
             else record_get(elt(fastget_names, 46), 0),
                v_12939 = nil; }
           else record_get(elt(fastget_names, 46), 0); }
#else
             if (v_12939 == SPID_NOPROP) v_12939 = nil; }}
#endif
    stack[-1] = v_12939;
    if (v_12939 == nil) goto v_12703;
    v_12939 = stack[-1];
    fn = elt(env, 12); // physopaeval
    v_12939 = (*qfn1(fn))(fn, v_12939);
    goto v_12701;
v_12703:
    v_12939 = stack[-3];
    if (symbolp(v_12939)) goto v_12708;
    else goto v_12709;
v_12708:
    v_12939 = stack[-3];
    goto v_12701;
v_12709:
    goto v_12719;
v_12715:
    v_12939 = stack[-3];
    v_12940 = qcar(v_12939);
    goto v_12716;
v_12717:
    v_12939 = elt(env, 1); // psimpfn
    goto v_12718;
v_12719:
    goto v_12715;
v_12716:
    goto v_12717;
v_12718:
    v_12939 = get(v_12940, v_12939);
    env = stack[-5];
    stack[-1] = v_12939;
    if (v_12939 == nil) goto v_12713;
    goto v_12728;
v_12724:
    v_12940 = stack[-1];
    goto v_12725;
v_12726:
    v_12939 = stack[-3];
    goto v_12727;
v_12728:
    goto v_12724;
v_12725:
    goto v_12726;
v_12727:
    v_12939 = Lapply1(nil, v_12940, v_12939);
    goto v_12701;
v_12713:
    v_12939 = stack[-3];
    v_12939 = qcar(v_12939);
    if (!symbolp(v_12939)) v_12939 = nil;
    else { v_12939 = qfastgets(v_12939);
           if (v_12939 != nil) { v_12939 = elt(v_12939, 9); // opmtch
#ifdef RECORD_GET
             if (v_12939 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_12939 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_12939 == SPID_NOPROP) v_12939 = nil; }}
#endif
    if (v_12939 == nil) goto v_12732;
    v_12939 = stack[-3];
    fn = elt(env, 13); // opmtch!*
    v_12939 = (*qfn1(fn))(fn, v_12939);
    stack[-1] = v_12939;
    if (v_12939 == nil) goto v_12732;
    v_12939 = stack[-1];
    goto v_12701;
v_12732:
    v_12939 = stack[-3];
    goto v_12701;
    v_12939 = nil;
v_12701:
    stack[0] = v_12939;
    goto v_12682;
v_12697:
    v_12939 = stack[-3];
    if (!consp(v_12939)) goto v_12744;
    else goto v_12745;
v_12744:
    v_12939 = stack[-3];
    fn = elt(env, 14); // aeval
    v_12939 = (*qfn1(fn))(fn, v_12939);
    stack[0] = v_12939;
    goto v_12682;
v_12745:
    v_12939 = stack[-3];
    v_12939 = qcar(v_12939);
    stack[-4] = v_12939;
    v_12939 = stack[-3];
    v_12939 = qcdr(v_12939);
    stack[-2] = v_12939;
    goto v_12764;
v_12760:
    v_12940 = stack[-4];
    goto v_12761;
v_12762:
    v_12939 = elt(env, 2); // physopfunction
    goto v_12763;
v_12764:
    goto v_12760;
v_12761:
    goto v_12762;
v_12763:
    v_12939 = get(v_12940, v_12939);
    env = stack[-5];
    stack[-1] = v_12939;
    if (v_12939 == nil) goto v_12758;
    goto v_12776;
v_12772:
    v_12940 = stack[-4];
    goto v_12773;
v_12774:
    v_12939 = elt(env, 3); // physoparith
    goto v_12775;
v_12776:
    goto v_12772;
v_12773:
    goto v_12774;
v_12775:
    v_12939 = Lflagp(nil, v_12940, v_12939);
    env = stack[-5];
    if (v_12939 == nil) goto v_12770;
    v_12939 = stack[-2];
    fn = elt(env, 15); // hasonephysop
    v_12939 = (*qfn1(fn))(fn, v_12939);
    env = stack[-5];
    if (v_12939 == nil) goto v_12782;
    goto v_12790;
v_12786:
    stack[0] = stack[-1];
    goto v_12787;
v_12788:
    v_12939 = stack[-2];
    v_12939 = ncons(v_12939);
    env = stack[-5];
    goto v_12789;
v_12790:
    goto v_12786;
v_12787:
    goto v_12788;
v_12789:
    fn = elt(env, 16); // apply
    v_12939 = (*qfn2(fn))(fn, stack[0], v_12939);
    stack[0] = v_12939;
    goto v_12780;
v_12782:
    goto v_12802;
v_12798:
    v_12940 = stack[-4];
    goto v_12799;
v_12800:
    v_12939 = stack[-2];
    goto v_12801;
v_12802:
    goto v_12798;
v_12799:
    goto v_12800;
v_12801:
    v_12939 = cons(v_12940, v_12939);
    env = stack[-5];
    fn = elt(env, 17); // reval3
    v_12939 = (*qfn1(fn))(fn, v_12939);
    stack[0] = v_12939;
    goto v_12780;
v_12780:
    goto v_12768;
v_12770:
    goto v_12812;
v_12808:
    v_12940 = stack[-4];
    goto v_12809;
v_12810:
    v_12939 = elt(env, 4); // physopfn
    goto v_12811;
v_12812:
    goto v_12808;
v_12809:
    goto v_12810;
v_12811:
    v_12939 = Lflagp(nil, v_12940, v_12939);
    env = stack[-5];
    if (v_12939 == nil) goto v_12806;
    v_12939 = stack[-2];
    fn = elt(env, 18); // areallphysops
    v_12939 = (*qfn1(fn))(fn, v_12939);
    env = stack[-5];
    if (v_12939 == nil) goto v_12818;
    goto v_12826;
v_12822:
    stack[0] = stack[-1];
    goto v_12823;
v_12824:
    v_12939 = stack[-2];
    v_12939 = ncons(v_12939);
    env = stack[-5];
    goto v_12825;
v_12826:
    goto v_12822;
v_12823:
    goto v_12824;
v_12825:
    fn = elt(env, 16); // apply
    v_12939 = (*qfn2(fn))(fn, stack[0], v_12939);
    stack[0] = v_12939;
    goto v_12816;
v_12818:
    goto v_12837;
v_12833:
    stack[-1] = elt(env, 0); // physopsm!*
    goto v_12834;
v_12835:
    goto v_12848;
v_12840:
    v_12942 = elt(env, 5); // "invalid call of "
    goto v_12841;
v_12842:
    v_12941 = stack[-4];
    goto v_12843;
v_12844:
    v_12940 = elt(env, 6); // " with args: "
    goto v_12845;
v_12846:
    v_12939 = stack[-2];
    goto v_12847;
v_12848:
    goto v_12840;
v_12841:
    goto v_12842;
v_12843:
    goto v_12844;
v_12845:
    goto v_12846;
v_12847:
    v_12939 = list4(v_12942, v_12941, v_12940, v_12939);
    env = stack[-5];
    goto v_12836;
v_12837:
    goto v_12833;
v_12834:
    goto v_12835;
v_12836:
    fn = elt(env, 19); // rederr2
    v_12939 = (*qfn2(fn))(fn, stack[-1], v_12939);
    goto v_12816;
v_12816:
    goto v_12768;
v_12806:
    goto v_12860;
v_12856:
    stack[-1] = elt(env, 0); // physopsm!*
    goto v_12857;
v_12858:
    goto v_12869;
v_12863:
    v_12941 = stack[-4];
    goto v_12864;
v_12865:
    v_12940 = elt(env, 7); // " has been flagged Physopfunction"
    goto v_12866;
v_12867:
    v_12939 = elt(env, 8); // " but is not defined"
    goto v_12868;
v_12869:
    goto v_12863;
v_12864:
    goto v_12865;
v_12866:
    goto v_12867;
v_12868:
    v_12939 = list3(v_12941, v_12940, v_12939);
    env = stack[-5];
    goto v_12859;
v_12860:
    goto v_12856;
v_12857:
    goto v_12858;
v_12859:
    fn = elt(env, 19); // rederr2
    v_12939 = (*qfn2(fn))(fn, stack[-1], v_12939);
    goto v_12768;
v_12768:
    goto v_12756;
v_12758:
    goto v_12884;
v_12880:
    v_12940 = stack[-4];
    goto v_12881;
v_12882:
    v_12939 = elt(env, 9); // physopmapping
    goto v_12883;
v_12884:
    goto v_12880;
v_12881:
    goto v_12882;
v_12883:
    v_12939 = Lflagp(nil, v_12940, v_12939);
    env = stack[-5];
    if (v_12939 == nil) goto v_12878;
    v_12939 = stack[-2];
    fn = elt(env, 20); // !*physopp!*
    v_12939 = (*qfn1(fn))(fn, v_12939);
    env = stack[-5];
    goto v_12876;
v_12878:
    v_12939 = nil;
    goto v_12876;
    v_12939 = nil;
v_12876:
    if (v_12939 == nil) goto v_12874;
    goto v_12898;
v_12894:
    goto v_12905;
v_12901:
    goto v_12911;
v_12907:
    goto v_12917;
v_12913:
    v_12940 = stack[-4];
    goto v_12914;
v_12915:
    v_12939 = stack[-2];
    goto v_12916;
v_12917:
    goto v_12913;
v_12914:
    goto v_12915;
v_12916:
    v_12940 = cons(v_12940, v_12939);
    env = stack[-5];
    goto v_12908;
v_12909:
    v_12939 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12910;
v_12911:
    goto v_12907;
v_12908:
    goto v_12909;
v_12910:
    fn = elt(env, 21); // to
    v_12940 = (*qfn2(fn))(fn, v_12940, v_12939);
    env = stack[-5];
    goto v_12902;
v_12903:
    v_12939 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12904;
v_12905:
    goto v_12901;
v_12902:
    goto v_12903;
v_12904:
    v_12939 = cons(v_12940, v_12939);
    env = stack[-5];
    v_12940 = ncons(v_12939);
    env = stack[-5];
    goto v_12895;
v_12896:
    v_12939 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12897;
v_12898:
    goto v_12894;
v_12895:
    goto v_12896;
v_12897:
    v_12939 = cons(v_12940, v_12939);
    env = stack[-5];
    fn = elt(env, 22); // mk!*sq
    v_12939 = (*qfn1(fn))(fn, v_12939);
    stack[0] = v_12939;
    goto v_12756;
v_12874:
    goto v_12929;
v_12925:
    v_12940 = stack[-4];
    goto v_12926;
v_12927:
    v_12939 = elt(env, 10); // prog
    goto v_12928;
v_12929:
    goto v_12925;
v_12926:
    goto v_12927;
v_12928:
    if (v_12940 == v_12939) goto v_12923;
    else goto v_12924;
v_12923:
    v_12939 = stack[-2];
    fn = elt(env, 23); // physopprog
    v_12939 = (*qfn1(fn))(fn, v_12939);
    stack[0] = v_12939;
    goto v_12756;
v_12924:
    v_12939 = stack[-3];
    fn = elt(env, 14); // aeval
    v_12939 = (*qfn1(fn))(fn, v_12939);
    stack[0] = v_12939;
    goto v_12756;
v_12756:
    goto v_12682;
v_12682:
    v_12939 = stack[0];
    return onevalue(v_12939);
}



// Code for assert_uninstall1

static LispObject CC_assert_uninstall1(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12723, v_12724, v_12725;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_12672;
// end of prologue
    goto v_12683;
v_12679:
    v_12724 = stack[0];
    goto v_12680;
v_12681:
    v_12723 = elt(env, 1); // assert_installed
    goto v_12682;
v_12683:
    goto v_12679;
v_12680:
    goto v_12681;
v_12682:
    v_12723 = get(v_12724, v_12723);
    env = stack[-1];
    if (v_12723 == nil) goto v_12676;
    else goto v_12677;
v_12676:
    goto v_12692;
v_12688:
    v_12724 = elt(env, 2); // "assert not installed for"
    goto v_12689;
v_12690:
    v_12723 = stack[0];
    goto v_12691;
v_12692:
    goto v_12688;
v_12689:
    goto v_12690;
v_12691:
    v_12723 = list2(v_12724, v_12723);
    env = stack[-1];
    {
        fn = elt(env, 4); // lprim
        return (*qfn1(fn))(fn, v_12723);
    }
v_12677:
    goto v_12702;
v_12698:
    v_12725 = stack[0];
    goto v_12699;
v_12700:
    goto v_12709;
v_12705:
    v_12724 = stack[0];
    goto v_12706;
v_12707:
    v_12723 = elt(env, 3); // assert_noassertfn
    goto v_12708;
v_12709:
    goto v_12705;
v_12706:
    goto v_12707;
v_12708:
    v_12723 = get(v_12724, v_12723);
    env = stack[-1];
    goto v_12701;
v_12702:
    goto v_12698;
v_12699:
    goto v_12700;
v_12701:
    fn = elt(env, 5); // copyd
    v_12723 = (*qfn2(fn))(fn, v_12725, v_12723);
    env = stack[-1];
    goto v_12719;
v_12713:
    v_12724 = stack[0];
    goto v_12714;
v_12715:
    v_12725 = elt(env, 1); // assert_installed
    goto v_12716;
v_12717:
    v_12723 = nil;
    goto v_12718;
v_12719:
    goto v_12713;
v_12714:
    goto v_12715;
v_12716:
    goto v_12717;
v_12718:
        return Lputprop(nil, 3, v_12724, v_12725, v_12723);
    v_12723 = nil;
    return onevalue(v_12723);
}



// Code for prepd1

static LispObject CC_prepd1(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12698, v_12699, v_12700;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
// copy arguments values to proper place
    v_12700 = v_12672;
// end of prologue
    v_12698 = v_12700;
    if (!consp(v_12698)) goto v_12676;
    else goto v_12677;
v_12676:
    v_12698 = v_12700;
    goto v_12675;
v_12677:
    goto v_12687;
v_12683:
    goto v_12693;
v_12689:
    v_12698 = v_12700;
    v_12699 = qcar(v_12698);
    goto v_12690;
v_12691:
    v_12698 = elt(env, 1); // prepfn
    goto v_12692;
v_12693:
    goto v_12689;
v_12690:
    goto v_12691;
v_12692:
    v_12698 = get(v_12699, v_12698);
    goto v_12684;
v_12685:
    v_12699 = v_12700;
    goto v_12686;
v_12687:
    goto v_12683;
v_12684:
    goto v_12685;
v_12686:
        return Lapply1(nil, v_12698, v_12699);
    v_12698 = nil;
v_12675:
    return onevalue(v_12698);
}



// Code for ad_numsort

static LispObject CC_ad_numsort(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12682, v_12683;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12682 = v_12672;
// end of prologue
    goto v_12679;
v_12675:
    v_12683 = v_12682;
    goto v_12676;
v_12677:
    v_12682 = elt(env, 1); // lambda_ygm6np4pcqv31
    goto v_12678;
v_12679:
    goto v_12675;
v_12676:
    goto v_12677;
v_12678:
    {
        fn = elt(env, 2); // sort
        return (*qfn2(fn))(fn, v_12683, v_12682);
    }
}



// Code for lambda_ygm6np4pcqv31

static LispObject CC_lambda_ygm6np4pcqv31(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12683, v_12684;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12683 = v_12673;
    v_12684 = v_12672;
// end of prologue
    goto v_12680;
v_12676:
    goto v_12677;
v_12678:
    goto v_12679;
v_12680:
    goto v_12676;
v_12677:
    goto v_12678;
v_12679:
        return Lleq(nil, v_12684, v_12683);
}



// Code for resimpf

static LispObject CC_resimpf(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12685, v_12686;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_12686 = v_12672;
// end of prologue
    v_12685 = nil;
// Binding varstack!*
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_12685; // varstack!*
    goto v_12681;
v_12677:
    goto v_12678;
v_12679:
    v_12685 = nil;
    goto v_12680;
v_12681:
    goto v_12677;
v_12678:
    goto v_12679;
v_12680:
    fn = elt(env, 2); // subf1
    v_12685 = (*qfn2(fn))(fn, v_12686, v_12685);
    v_12685 = qcar(v_12685);
    ;}  // end of a binding scope
    return onevalue(v_12685);
}



// Code for quotkx

static LispObject CC_quotkx(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12744, v_12745, v_12746;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12673;
    stack[-1] = v_12672;
// end of prologue
    goto v_12680;
v_12676:
    v_12744 = stack[-1];
    v_12744 = qcar(v_12744);
    v_12745 = qcdr(v_12744);
    goto v_12677;
v_12678:
    v_12744 = stack[0];
    goto v_12679;
v_12680:
    goto v_12676;
v_12677:
    goto v_12678;
v_12679:
    fn = elt(env, 1); // quotfx1
    v_12744 = (*qfn2(fn))(fn, v_12745, v_12744);
    env = stack[-3];
    stack[-2] = v_12744;
    v_12744 = stack[-2];
    if (v_12744 == nil) goto v_12689;
    v_12744 = stack[-1];
    v_12744 = qcdr(v_12744);
    if (v_12744 == nil) goto v_12693;
    else goto v_12694;
v_12693:
    goto v_12703;
v_12699:
    v_12744 = stack[-1];
    v_12744 = qcar(v_12744);
    v_12745 = qcar(v_12744);
    goto v_12700;
v_12701:
    v_12744 = stack[-2];
    goto v_12702;
v_12703:
    goto v_12699;
v_12700:
    goto v_12701;
v_12702:
    v_12744 = cons(v_12745, v_12744);
    return ncons(v_12744);
v_12694:
    goto v_12715;
v_12711:
    v_12744 = stack[-1];
    v_12745 = qcdr(v_12744);
    goto v_12712;
v_12713:
    v_12744 = stack[0];
    goto v_12714;
v_12715:
    goto v_12711;
v_12712:
    goto v_12713;
v_12714:
    fn = elt(env, 1); // quotfx1
    v_12744 = (*qfn2(fn))(fn, v_12745, v_12744);
    v_12745 = v_12744;
    if (v_12745 == nil) goto v_12723;
    goto v_12732;
v_12726:
    v_12745 = stack[-1];
    v_12745 = qcar(v_12745);
    v_12746 = qcar(v_12745);
    goto v_12727;
v_12728:
    v_12745 = stack[-2];
    goto v_12729;
v_12730:
    goto v_12731;
v_12732:
    goto v_12726;
v_12727:
    goto v_12728;
v_12729:
    goto v_12730;
v_12731:
    return acons(v_12746, v_12745, v_12744);
v_12723:
    v_12744 = nil;
    goto v_12721;
    v_12744 = nil;
v_12721:
    goto v_12692;
    v_12744 = nil;
v_12692:
    goto v_12687;
v_12689:
    v_12744 = nil;
    goto v_12687;
    v_12744 = nil;
v_12687:
    return onevalue(v_12744);
}



// Code for qqe_arg!-check

static LispObject CC_qqe_argKcheck(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12760, v_12761;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12672;
// end of prologue
    v_12760 = stack[0];
    v_12760 = qcar(v_12760);
    stack[-1] = v_12760;
    v_12760 = stack[-1];
    fn = elt(env, 3); // qqe_rqopp
    v_12760 = (*qfn1(fn))(fn, v_12760);
    env = stack[-2];
    if (v_12760 == nil) goto v_12680;
    v_12760 = stack[0];
    fn = elt(env, 4); // qqe_arg!-check!-lq!-rq
    v_12760 = (*qfn1(fn))(fn, v_12760);
    goto v_12678;
v_12680:
    v_12760 = stack[-1];
    fn = elt(env, 5); // qqe_rbopp
    v_12760 = (*qfn1(fn))(fn, v_12760);
    env = stack[-2];
    if (v_12760 == nil) goto v_12686;
    v_12760 = stack[0];
    fn = elt(env, 6); // qqe_arg!-check!-lb!-rb
    v_12760 = (*qfn1(fn))(fn, v_12760);
    goto v_12678;
v_12686:
    v_12760 = stack[-1];
    fn = elt(env, 7); // qqe_qopheadp
    v_12760 = (*qfn1(fn))(fn, v_12760);
    env = stack[-2];
    if (v_12760 == nil) goto v_12693;
    else goto v_12691;
v_12693:
    v_12760 = stack[-1];
    fn = elt(env, 8); // qqe_qoptailp
    v_12760 = (*qfn1(fn))(fn, v_12760);
    env = stack[-2];
    if (v_12760 == nil) goto v_12696;
    else goto v_12691;
v_12696:
    goto v_12692;
v_12691:
    v_12760 = stack[0];
    v_12760 = qcdr(v_12760);
    v_12760 = qcar(v_12760);
    fn = elt(env, 9); // qqe_arg!-check!-q
    v_12760 = (*qfn1(fn))(fn, v_12760);
    env = stack[-2];
    if (v_12760 == nil) goto v_12701;
    else goto v_12702;
v_12701:
    fn = elt(env, 10); // qqe_arg!-check!-marked!-ids!-rollback
    v_12760 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_12713;
v_12709:
    v_12761 = stack[0];
    goto v_12710;
v_12711:
    v_12760 = elt(env, 1); // "some arguments are not of queue type"
    goto v_12712;
v_12713:
    goto v_12709;
v_12710:
    goto v_12711;
v_12712:
    fn = elt(env, 11); // typerr
    v_12760 = (*qfn2(fn))(fn, v_12761, v_12760);
    goto v_12700;
v_12702:
v_12700:
    goto v_12678;
v_12692:
    v_12760 = stack[-1];
    fn = elt(env, 12); // qqe_qopaddp
    v_12760 = (*qfn1(fn))(fn, v_12760);
    env = stack[-2];
    if (v_12760 == nil) goto v_12719;
    v_12760 = stack[0];
    fn = elt(env, 13); // qqe_arg!-check!-lb!-rq
    v_12760 = (*qfn1(fn))(fn, v_12760);
    goto v_12678;
v_12719:
    v_12760 = stack[0];
    v_12760 = qcdr(v_12760);
    stack[-1] = v_12760;
v_12729:
    v_12760 = stack[-1];
    if (v_12760 == nil) goto v_12734;
    else goto v_12735;
v_12734:
    goto v_12728;
v_12735:
    v_12760 = stack[-1];
    v_12760 = qcar(v_12760);
    fn = elt(env, 14); // qqe_arg!-check!-b
    v_12760 = (*qfn1(fn))(fn, v_12760);
    env = stack[-2];
    if (v_12760 == nil) goto v_12743;
    else goto v_12744;
v_12743:
    fn = elt(env, 10); // qqe_arg!-check!-marked!-ids!-rollback
    v_12760 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_12753;
v_12749:
    v_12761 = stack[0];
    goto v_12750;
v_12751:
    v_12760 = elt(env, 2); // "some arguments are not of basic type"
    goto v_12752;
v_12753:
    goto v_12749;
v_12750:
    goto v_12751;
v_12752:
    fn = elt(env, 11); // typerr
    v_12760 = (*qfn2(fn))(fn, v_12761, v_12760);
    env = stack[-2];
    goto v_12742;
v_12744:
v_12742:
    v_12760 = stack[-1];
    v_12760 = qcdr(v_12760);
    stack[-1] = v_12760;
    goto v_12729;
v_12728:
    goto v_12678;
v_12678:
    v_12760 = nil;
    return onevalue(v_12760);
}



// Code for !*!*a2s

static LispObject CC_HHa2s(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12758, v_12759;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_12758 = v_12673;
    stack[-3] = v_12672;
// end of prologue
    v_12758 = stack[-3];
    if (v_12758 == nil) goto v_12677;
    else goto v_12678;
v_12677:
    v_12758 = elt(env, 1); // "tell Hearn!!"
    {
        fn = elt(env, 10); // rederr
        return (*qfn1(fn))(fn, v_12758);
    }
v_12678:
    goto v_12690;
v_12686:
    v_12759 = stack[-3];
    goto v_12687;
v_12688:
    v_12758 = elt(env, 2); // nochange
    goto v_12689;
v_12690:
    goto v_12686;
v_12687:
    goto v_12688;
v_12689:
    v_12758 = Lflagpcar(nil, v_12759, v_12758);
    env = stack[-5];
    if (v_12758 == nil) goto v_12683;
    goto v_12698;
v_12694:
    v_12758 = stack[-3];
    v_12759 = qcar(v_12758);
    goto v_12695;
v_12696:
    v_12758 = elt(env, 3); // getel
    goto v_12697;
v_12698:
    goto v_12694;
v_12695:
    goto v_12696;
v_12697:
    if (v_12759 == v_12758) goto v_12683;
    v_12758 = stack[-3];
    goto v_12676;
v_12683:
    goto v_12710;
v_12706:
    v_12759 = elt(env, 4); // random
    goto v_12707;
v_12708:
    v_12758 = stack[-3];
    goto v_12709;
v_12710:
    goto v_12706;
v_12707:
    goto v_12708;
v_12709:
    fn = elt(env, 11); // smember
    v_12758 = (*qfn2(fn))(fn, v_12759, v_12758);
    env = stack[-5];
    if (v_12758 == nil) goto v_12704;
    goto v_12718;
v_12714:
    goto v_12726;
v_12720:
    stack[-4] = elt(env, 5); // lambda
    goto v_12721;
v_12722:
    stack[-2] = elt(env, 6); // (!*uncached)
    goto v_12723;
v_12724:
    goto v_12736;
v_12730:
    stack[-1] = elt(env, 7); // progn
    goto v_12731;
v_12732:
    stack[0] = elt(env, 8); // (declare (special !*uncached))
    goto v_12733;
v_12734:
    goto v_12744;
v_12740:
    v_12759 = qvalue(elt(env, 9)); // !*!*a2sfn
    goto v_12741;
v_12742:
    v_12758 = stack[-3];
    goto v_12743;
v_12744:
    goto v_12740;
v_12741:
    goto v_12742;
v_12743:
    v_12758 = list2(v_12759, v_12758);
    env = stack[-5];
    goto v_12735;
v_12736:
    goto v_12730;
v_12731:
    goto v_12732;
v_12733:
    goto v_12734;
v_12735:
    v_12758 = list3(stack[-1], stack[0], v_12758);
    env = stack[-5];
    goto v_12725;
v_12726:
    goto v_12720;
v_12721:
    goto v_12722;
v_12723:
    goto v_12724;
v_12725:
    v_12759 = list3(stack[-4], stack[-2], v_12758);
    goto v_12715;
v_12716:
    v_12758 = lisp_true;
    goto v_12717;
v_12718:
    goto v_12714;
v_12715:
    goto v_12716;
v_12717:
    return list2(v_12759, v_12758);
v_12704:
    goto v_12755;
v_12751:
    v_12759 = qvalue(elt(env, 9)); // !*!*a2sfn
    goto v_12752;
v_12753:
    v_12758 = stack[-3];
    goto v_12754;
v_12755:
    goto v_12751;
v_12752:
    goto v_12753;
v_12754:
    return list2(v_12759, v_12758);
    v_12758 = nil;
v_12676:
    return onevalue(v_12758);
}



// Code for dm!-minus

static LispObject CC_dmKminus(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12686, v_12687;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
// copy arguments values to proper place
    v_12686 = v_12672;
// end of prologue
    fn = elt(env, 1); // !:minus
    v_12686 = (*qfn1(fn))(fn, v_12686);
    v_12687 = v_12686;
    v_12686 = v_12687;
    if (v_12686 == nil) goto v_12679;
    else goto v_12680;
v_12679:
    v_12686 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12678;
v_12680:
    v_12686 = v_12687;
    goto v_12678;
    v_12686 = nil;
v_12678:
    return onevalue(v_12686);
}



// Code for groebcplistsortin1

static LispObject CC_groebcplistsortin1(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12733, v_12734;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12673;
    stack[-1] = v_12672;
// end of prologue
v_12677:
    goto v_12687;
v_12683:
    v_12733 = stack[0];
    v_12734 = qcar(v_12733);
    goto v_12684;
v_12685:
    v_12733 = stack[-1];
    goto v_12686;
v_12687:
    goto v_12683;
v_12684:
    goto v_12685;
v_12686:
    fn = elt(env, 1); // groebcpcompless!?
    v_12733 = (*qfn2(fn))(fn, v_12734, v_12733);
    env = stack[-3];
    if (v_12733 == nil) goto v_12680;
    else goto v_12681;
v_12680:
    goto v_12696;
v_12692:
    stack[-2] = stack[0];
    goto v_12693;
v_12694:
    goto v_12703;
v_12699:
    v_12733 = stack[0];
    v_12734 = qcar(v_12733);
    goto v_12700;
v_12701:
    v_12733 = stack[0];
    v_12733 = qcdr(v_12733);
    goto v_12702;
v_12703:
    goto v_12699;
v_12700:
    goto v_12701;
v_12702:
    v_12733 = cons(v_12734, v_12733);
    env = stack[-3];
    goto v_12695;
v_12696:
    goto v_12692;
v_12693:
    goto v_12694;
v_12695:
    v_12733 = Lrplacd(nil, stack[-2], v_12733);
    goto v_12713;
v_12709:
    v_12734 = stack[0];
    goto v_12710;
v_12711:
    v_12733 = stack[-1];
    goto v_12712;
v_12713:
    goto v_12709;
v_12710:
    goto v_12711;
v_12712:
        return Lrplaca(nil, v_12734, v_12733);
v_12681:
    v_12733 = stack[0];
    v_12733 = qcdr(v_12733);
    if (v_12733 == nil) goto v_12716;
    else goto v_12717;
v_12716:
    goto v_12725;
v_12721:
    goto v_12722;
v_12723:
    v_12733 = stack[-1];
    v_12733 = ncons(v_12733);
    goto v_12724;
v_12725:
    goto v_12721;
v_12722:
    goto v_12723;
v_12724:
    {
        LispObject v_12738 = stack[0];
        return Lrplacd(nil, v_12738, v_12733);
    }
v_12717:
    v_12733 = stack[0];
    v_12733 = qcdr(v_12733);
    stack[0] = v_12733;
    goto v_12677;
    v_12733 = nil;
    return onevalue(v_12733);
}



// Code for bytelist2id

static LispObject CC_bytelist2id(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12677;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
// copy arguments values to proper place
    v_12677 = v_12672;
// end of prologue
    fn = elt(env, 1); // list2string
    v_12677 = (*qfn1(fn))(fn, v_12677);
        return Lintern(nil, v_12677);
}



// Code for gfdot

static LispObject CC_gfdot(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12699, v_12700, v_12701;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12700 = v_12673;
    v_12701 = v_12672;
// end of prologue
    v_12699 = v_12701;
    v_12699 = qcar(v_12699);
    if (!consp(v_12699)) goto v_12677;
    else goto v_12678;
v_12677:
    goto v_12686;
v_12682:
    v_12699 = v_12701;
    goto v_12683;
v_12684:
    goto v_12685;
v_12686:
    goto v_12682;
v_12683:
    goto v_12684;
v_12685:
    {
        fn = elt(env, 1); // gffdot
        return (*qfn2(fn))(fn, v_12699, v_12700);
    }
v_12678:
    goto v_12696;
v_12692:
    v_12699 = v_12701;
    goto v_12693;
v_12694:
    goto v_12695;
v_12696:
    goto v_12692;
v_12693:
    goto v_12694;
v_12695:
    {
        fn = elt(env, 2); // gbfdot
        return (*qfn2(fn))(fn, v_12699, v_12700);
    }
    v_12699 = nil;
    return onevalue(v_12699);
}



// Code for rdcos!*

static LispObject CC_rdcosH(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12689, v_12690;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12689 = v_12672;
// end of prologue
    fn = elt(env, 1); // convprec
    v_12689 = (*qfn1(fn))(fn, v_12689);
    env = stack[0];
    v_12690 = v_12689;
    v_12689 = v_12690;
    if (!consp(v_12689)) goto v_12680;
    else goto v_12681;
v_12680:
    v_12689 = v_12690;
    fn = elt(env, 2); // cos
    v_12689 = (*qfn1(fn))(fn, v_12689);
    env = stack[0];
    goto v_12679;
v_12681:
    v_12689 = v_12690;
    fn = elt(env, 3); // cos!*
    v_12689 = (*qfn1(fn))(fn, v_12689);
    env = stack[0];
    goto v_12679;
    v_12689 = nil;
v_12679:
    {
        fn = elt(env, 4); // mkround
        return (*qfn1(fn))(fn, v_12689);
    }
}



// Code for trwrite

static LispObject CC_trwrite(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12713;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_12672;
// end of prologue
    v_12713 = stack[0];
    v_12713 = qcar(v_12713);
    if (!symbolp(v_12713)) v_12713 = nil;
    else { v_12713 = qfastgets(v_12713);
           if (v_12713 != nil) { v_12713 = elt(v_12713, 53); // tracing
#ifdef RECORD_GET
             if (v_12713 == SPID_NOPROP)
                record_get(elt(fastget_names, 53), 0),
                v_12713 = nil;
             else record_get(elt(fastget_names, 53), 1),
                v_12713 = lisp_true; }
           else record_get(elt(fastget_names, 53), 0); }
#else
             if (v_12713 == SPID_NOPROP) v_12713 = nil; else v_12713 = lisp_true; }}
#endif
    if (v_12713 == nil) goto v_12679;
    else goto v_12680;
v_12679:
    v_12713 = nil;
    goto v_12676;
v_12680:
    v_12713 = elt(env, 1); // "**in procedure: "
    v_12713 = Lprinc(nil, v_12713);
    env = stack[-1];
    v_12713 = stack[0];
    v_12713 = qcar(v_12713);
    v_12713 = Lprinc(nil, v_12713);
    env = stack[-1];
    v_12713 = Lterpri(nil, 0);
    env = stack[-1];
    v_12713 = stack[0];
    v_12713 = qcdr(v_12713);
    stack[0] = v_12713;
v_12695:
    v_12713 = stack[0];
    if (v_12713 == nil) goto v_12700;
    else goto v_12701;
v_12700:
    goto v_12694;
v_12701:
    v_12713 = stack[0];
    v_12713 = qcar(v_12713);
    v_12713 = Lprinc(nil, v_12713);
    env = stack[-1];
    v_12713 = stack[0];
    v_12713 = qcdr(v_12713);
    stack[0] = v_12713;
    goto v_12695;
v_12694:
    v_12713 = Lterpri(nil, 0);
    v_12713 = nil;
v_12676:
    return onevalue(v_12713);
}



// Code for repartf

static LispObject CC_repartf(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12794, v_12795;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_12672;
// end of prologue
    goto v_12679;
v_12675:
    v_12795 = elt(env, 1); // i
    goto v_12676;
v_12677:
    v_12794 = qvalue(elt(env, 2)); // kord!*
    goto v_12678;
v_12679:
    goto v_12675;
v_12676:
    goto v_12677;
v_12678:
    v_12794 = cons(v_12795, v_12794);
    env = stack[-4];
// Binding kord!*
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 2, -3);
    qvalue(elt(env, 2)) = v_12794; // kord!*
    v_12794 = stack[0];
    fn = elt(env, 4); // reorder
    v_12794 = (*qfn1(fn))(fn, v_12794);
    env = stack[-4];
    stack[-2] = v_12794;
    v_12794 = stack[-2];
    if (!consp(v_12794)) goto v_12692;
    else goto v_12693;
v_12692:
    v_12794 = lisp_true;
    goto v_12691;
v_12693:
    v_12794 = stack[-2];
    v_12794 = qcar(v_12794);
    v_12794 = (consp(v_12794) ? nil : lisp_true);
    goto v_12691;
    v_12794 = nil;
v_12691:
    if (v_12794 == nil) goto v_12689;
    v_12794 = stack[-2];
    if (!consp(v_12794)) goto v_12703;
    else goto v_12704;
v_12703:
    v_12794 = stack[-2];
    goto v_12702;
v_12704:
    goto v_12714;
v_12710:
    v_12794 = stack[-2];
    v_12795 = qcar(v_12794);
    goto v_12711;
v_12712:
    v_12794 = elt(env, 3); // cmpxfn
    goto v_12713;
v_12714:
    goto v_12710;
v_12711:
    goto v_12712;
v_12713:
    v_12794 = get(v_12795, v_12794);
    env = stack[-4];
    if (v_12794 == nil) goto v_12708;
    goto v_12726;
v_12720:
    v_12794 = stack[-2];
    stack[-1] = qcar(v_12794);
    goto v_12721;
v_12722:
    v_12794 = stack[-2];
    v_12794 = qcdr(v_12794);
    stack[0] = qcar(v_12794);
    goto v_12723;
v_12724:
    goto v_12737;
v_12733:
    v_12794 = stack[-2];
    v_12794 = qcar(v_12794);
    if (!symbolp(v_12794)) v_12795 = nil;
    else { v_12795 = qfastgets(v_12794);
           if (v_12795 != nil) { v_12795 = elt(v_12795, 34); // i2d
#ifdef RECORD_GET
             if (v_12795 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_12795 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_12795 == SPID_NOPROP) v_12795 = nil; }}
#endif
    goto v_12734;
v_12735:
    v_12794 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12736;
v_12737:
    goto v_12733;
v_12734:
    goto v_12735;
v_12736:
    v_12794 = Lapply1(nil, v_12795, v_12794);
    env = stack[-4];
    v_12794 = qcdr(v_12794);
    v_12794 = qcar(v_12794);
    goto v_12725;
v_12726:
    goto v_12720;
v_12721:
    goto v_12722;
v_12723:
    goto v_12724;
v_12725:
    v_12794 = list2star(stack[-1], stack[0], v_12794);
    env = stack[-4];
    fn = elt(env, 5); // int!-equiv!-chk
    v_12794 = (*qfn1(fn))(fn, v_12794);
    goto v_12702;
v_12708:
    v_12794 = stack[-2];
    goto v_12702;
    v_12794 = nil;
v_12702:
    goto v_12687;
v_12689:
    goto v_12753;
v_12749:
    v_12794 = stack[-2];
    v_12794 = qcar(v_12794);
    v_12794 = qcar(v_12794);
    v_12795 = qcar(v_12794);
    goto v_12750;
v_12751:
    v_12794 = elt(env, 1); // i
    goto v_12752;
v_12753:
    goto v_12749;
v_12750:
    goto v_12751;
v_12752:
    if (v_12795 == v_12794) goto v_12747;
    else goto v_12748;
v_12747:
    v_12794 = stack[-2];
    v_12794 = qcdr(v_12794);
    v_12794 = CC_repartf(elt(env, 0), v_12794);
    goto v_12687;
v_12748:
    goto v_12769;
v_12765:
    goto v_12775;
v_12771:
    goto v_12782;
v_12778:
    v_12794 = stack[-2];
    v_12794 = qcar(v_12794);
    v_12795 = qcar(v_12794);
    goto v_12779;
v_12780:
    v_12794 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12781;
v_12782:
    goto v_12778;
v_12779:
    goto v_12780;
v_12781:
    v_12794 = cons(v_12795, v_12794);
    env = stack[-4];
    stack[0] = ncons(v_12794);
    env = stack[-4];
    goto v_12772;
v_12773:
    v_12794 = stack[-2];
    v_12794 = qcar(v_12794);
    v_12794 = qcdr(v_12794);
    v_12794 = CC_repartf(elt(env, 0), v_12794);
    env = stack[-4];
    goto v_12774;
v_12775:
    goto v_12771;
v_12772:
    goto v_12773;
v_12774:
    fn = elt(env, 6); // multf
    stack[0] = (*qfn2(fn))(fn, stack[0], v_12794);
    env = stack[-4];
    goto v_12766;
v_12767:
    v_12794 = stack[-2];
    v_12794 = qcdr(v_12794);
    v_12794 = CC_repartf(elt(env, 0), v_12794);
    env = stack[-4];
    goto v_12768;
v_12769:
    goto v_12765;
v_12766:
    goto v_12767;
v_12768:
    fn = elt(env, 7); // addf
    v_12794 = (*qfn2(fn))(fn, stack[0], v_12794);
    goto v_12687;
    v_12794 = nil;
v_12687:
    ;}  // end of a binding scope
    return onevalue(v_12794);
}



// Code for one!-entry!-listp

static LispObject CC_oneKentryKlistp(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12708, v_12709;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12673;
    stack[-1] = v_12672;
// end of prologue
v_12671:
    v_12708 = stack[-1];
    if (v_12708 == nil) goto v_12677;
    else goto v_12678;
v_12677:
    v_12708 = lisp_true;
    goto v_12676;
v_12678:
    goto v_12692;
v_12688:
    v_12708 = stack[-1];
    v_12709 = qcar(v_12708);
    goto v_12689;
v_12690:
    v_12708 = stack[0];
    goto v_12691;
v_12692:
    goto v_12688;
v_12689:
    goto v_12690;
v_12691:
    fn = elt(env, 1); // one!-entryp
    v_12708 = (*qfn2(fn))(fn, v_12709, v_12708);
    env = stack[-2];
    if (v_12708 == nil) goto v_12685;
    else goto v_12686;
v_12685:
    v_12708 = nil;
    goto v_12684;
v_12686:
    goto v_12704;
v_12700:
    v_12708 = stack[-1];
    v_12709 = qcdr(v_12708);
    goto v_12701;
v_12702:
    v_12708 = stack[0];
    goto v_12703;
v_12704:
    goto v_12700;
v_12701:
    goto v_12702;
v_12703:
    stack[-1] = v_12709;
    stack[0] = v_12708;
    goto v_12671;
    v_12708 = nil;
v_12684:
    goto v_12676;
    v_12708 = nil;
v_12676:
    return onevalue(v_12708);
}



// Code for fs!:times

static LispObject CC_fsTtimes(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12720, v_12721;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12673;
    stack[-1] = v_12672;
// end of prologue
    v_12720 = stack[-1];
    if (v_12720 == nil) goto v_12677;
    else goto v_12678;
v_12677:
    v_12720 = nil;
    goto v_12676;
v_12678:
    v_12720 = stack[0];
    if (v_12720 == nil) goto v_12681;
    else goto v_12682;
v_12681:
    v_12720 = nil;
    goto v_12676;
v_12682:
    goto v_12695;
v_12691:
    v_12721 = stack[-1];
    goto v_12692;
v_12693:
    v_12720 = stack[0];
    goto v_12694;
v_12695:
    goto v_12691;
v_12692:
    goto v_12693;
v_12694:
    fn = elt(env, 1); // fs!:timesterm
    v_12720 = (*qfn2(fn))(fn, v_12721, v_12720);
    env = stack[-3];
    goto v_12703;
v_12699:
    stack[-2] = v_12720;
    goto v_12700;
v_12701:
    goto v_12710;
v_12706:
    goto v_12715;
v_12711:
    v_12721 = stack[-1];
    goto v_12712;
v_12713:
    v_12720 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_12714;
v_12715:
    goto v_12711;
v_12712:
    goto v_12713;
v_12714:
    v_12721 = *(LispObject *)((char *)v_12721 + (CELL-TAG_VECTOR) + (((intptr_t)v_12720-TAG_FIXNUM)/(16/CELL)));
    goto v_12707;
v_12708:
    v_12720 = stack[0];
    goto v_12709;
v_12710:
    goto v_12706;
v_12707:
    goto v_12708;
v_12709:
    v_12720 = CC_fsTtimes(elt(env, 0), v_12721, v_12720);
    env = stack[-3];
    goto v_12702;
v_12703:
    goto v_12699;
v_12700:
    goto v_12701;
v_12702:
    {
        LispObject v_12725 = stack[-2];
        fn = elt(env, 2); // fs!:plus
        return (*qfn2(fn))(fn, v_12725, v_12720);
    }
    goto v_12676;
    v_12720 = nil;
v_12676:
    return onevalue(v_12720);
}



// Code for moid_member

static LispObject CC_moid_member(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12704, v_12705;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12673;
    stack[-1] = v_12672;
// end of prologue
v_12671:
    v_12704 = stack[0];
    if (v_12704 == nil) goto v_12677;
    else goto v_12678;
v_12677:
    v_12704 = nil;
    goto v_12676;
v_12678:
    goto v_12691;
v_12687:
    v_12704 = stack[0];
    v_12705 = qcar(v_12704);
    goto v_12688;
v_12689:
    v_12704 = stack[-1];
    goto v_12690;
v_12691:
    goto v_12687;
v_12688:
    goto v_12689;
v_12690:
    fn = elt(env, 1); // mo_vdivides!?
    v_12704 = (*qfn2(fn))(fn, v_12705, v_12704);
    env = stack[-2];
    if (v_12704 == nil) goto v_12685;
    else goto v_12684;
v_12685:
    goto v_12700;
v_12696:
    v_12705 = stack[-1];
    goto v_12697;
v_12698:
    v_12704 = stack[0];
    v_12704 = qcdr(v_12704);
    goto v_12699;
v_12700:
    goto v_12696;
v_12697:
    goto v_12698;
v_12699:
    stack[-1] = v_12705;
    stack[0] = v_12704;
    goto v_12671;
v_12684:
    goto v_12676;
    v_12704 = nil;
v_12676:
    return onevalue(v_12704);
}



// Code for splitlist!:

static LispObject CC_splitlistT(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12712, v_12713, v_12714;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12673;
    stack[-1] = v_12672;
// end of prologue
    v_12714 = nil;
v_12678:
    v_12712 = stack[-1];
    if (v_12712 == nil) goto v_12681;
    else goto v_12682;
v_12681:
    v_12712 = v_12714;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_12712);
    }
v_12682:
    goto v_12693;
v_12689:
    v_12712 = stack[-1];
    v_12713 = qcar(v_12712);
    goto v_12690;
v_12691:
    v_12712 = stack[0];
    goto v_12692;
v_12693:
    goto v_12689;
v_12690:
    goto v_12691;
v_12692:
    if (!consp(v_12713)) goto v_12687;
    v_12713 = qcar(v_12713);
    if (v_12713 == v_12712) goto v_12686;
    else goto v_12687;
v_12686:
    goto v_12702;
v_12698:
    v_12712 = stack[-1];
    v_12712 = qcar(v_12712);
    goto v_12699;
v_12700:
    v_12713 = v_12714;
    goto v_12701;
v_12702:
    goto v_12698;
v_12699:
    goto v_12700;
v_12701:
    v_12712 = cons(v_12712, v_12713);
    env = stack[-2];
    v_12714 = v_12712;
    v_12712 = stack[-1];
    v_12712 = qcdr(v_12712);
    stack[-1] = v_12712;
    goto v_12678;
v_12687:
    v_12712 = stack[-1];
    v_12712 = qcdr(v_12712);
    stack[-1] = v_12712;
    goto v_12678;
    v_12712 = nil;
    return onevalue(v_12712);
}



// Code for gfk

static LispObject CC_gfk(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12750, v_12751, v_12752, v_12753, v_12754, v_12755;
    LispObject v_12674, v_12673, v_12672;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "gfk");
    va_start(aa, nargs);
    v_12672 = va_arg(aa, LispObject);
    v_12673 = va_arg(aa, LispObject);
    v_12674 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_12674,v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_12672,v_12673,v_12674);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_12753 = v_12674;
    v_12754 = v_12673;
    v_12750 = v_12672;
// end of prologue
v_12671:
    v_12751 = v_12753;
    if (v_12751 == nil) goto v_12680;
    else goto v_12678;
v_12680:
    v_12751 = v_12750;
    if (!consp(v_12751)) goto v_12685;
    else goto v_12686;
v_12685:
    v_12751 = lisp_true;
    goto v_12684;
v_12686:
    v_12751 = v_12750;
    v_12751 = qcar(v_12751);
    v_12751 = (consp(v_12751) ? nil : lisp_true);
    goto v_12684;
    v_12751 = nil;
v_12684:
    if (v_12751 == nil) goto v_12682;
    else goto v_12678;
v_12682:
    goto v_12679;
v_12678:
    v_12750 = v_12753;
    goto v_12677;
v_12679:
    v_12751 = v_12750;
    v_12751 = qcar(v_12751);
    v_12751 = qcar(v_12751);
    v_12751 = qcar(v_12751);
    v_12755 = v_12751;
    goto v_12709;
v_12703:
    v_12751 = v_12750;
    stack[-1] = qcdr(v_12751);
    goto v_12704;
v_12705:
    stack[0] = v_12754;
    goto v_12706;
v_12707:
    goto v_12720;
v_12714:
    v_12750 = qcar(v_12750);
    v_12752 = qcdr(v_12750);
    goto v_12715;
v_12716:
    v_12751 = v_12754;
    goto v_12717;
v_12718:
    v_12750 = v_12755;
    if (!consp(v_12750)) goto v_12732;
    goto v_12738;
v_12734:
    v_12750 = v_12755;
    v_12750 = qcar(v_12750);
    goto v_12735;
v_12736:
    goto v_12737;
v_12738:
    goto v_12734;
v_12735:
    goto v_12736;
v_12737:
    v_12750 = Lmember(nil, v_12750, v_12754);
    goto v_12730;
v_12732:
    v_12750 = nil;
    goto v_12730;
    v_12750 = nil;
v_12730:
    if (v_12750 == nil) goto v_12728;
    v_12750 = v_12755;
    goto v_12726;
v_12728:
    v_12750 = v_12753;
    goto v_12726;
    v_12750 = nil;
v_12726:
    goto v_12719;
v_12720:
    goto v_12714;
v_12715:
    goto v_12716;
v_12717:
    goto v_12718;
v_12719:
    v_12751 = CC_gfk(elt(env, 0), 3, v_12752, v_12751, v_12750);
    env = stack[-2];
    goto v_12708;
v_12709:
    goto v_12703;
v_12704:
    goto v_12705;
v_12706:
    goto v_12707;
v_12708:
    v_12750 = stack[-1];
    v_12754 = stack[0];
    v_12753 = v_12751;
    goto v_12671;
    v_12750 = nil;
v_12677:
    return onevalue(v_12750);
}



// Code for aex_neg

static LispObject CC_aex_neg(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12685;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12672;
// end of prologue
    goto v_12679;
v_12675:
    v_12685 = stack[0];
    fn = elt(env, 1); // aex_ex
    v_12685 = (*qfn1(fn))(fn, v_12685);
    env = stack[-2];
    fn = elt(env, 2); // negsq
    stack[-1] = (*qfn1(fn))(fn, v_12685);
    env = stack[-2];
    goto v_12676;
v_12677:
    v_12685 = stack[0];
    fn = elt(env, 3); // aex_ctx
    v_12685 = (*qfn1(fn))(fn, v_12685);
    env = stack[-2];
    goto v_12678;
v_12679:
    goto v_12675;
v_12676:
    goto v_12677;
v_12678:
    {
        LispObject v_12688 = stack[-1];
        fn = elt(env, 4); // aex_mk
        return (*qfn2(fn))(fn, v_12688, v_12685);
    }
}



// Code for ofsf_surep

static LispObject CC_ofsf_surep(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12693, v_12694, v_12695;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12693 = v_12673;
    v_12694 = v_12672;
// end of prologue
    goto v_12679;
v_12675:
    goto v_12687;
v_12681:
    v_12695 = v_12694;
    goto v_12682;
v_12683:
    v_12694 = v_12693;
    goto v_12684;
v_12685:
    v_12693 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_12686;
v_12687:
    goto v_12681;
v_12682:
    goto v_12683;
v_12684:
    goto v_12685;
v_12686:
    fn = elt(env, 2); // cl_simpl
    v_12693 = (*qfnn(fn))(fn, 3, v_12695, v_12694, v_12693);
    env = stack[0];
    goto v_12676;
v_12677:
    v_12694 = elt(env, 1); // true
    goto v_12678;
v_12679:
    goto v_12675;
v_12676:
    goto v_12677;
v_12678:
    v_12693 = (v_12693 == v_12694 ? lisp_true : nil);
    return onevalue(v_12693);
}



// Code for simpexpt

static LispObject CC_simpexpt(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12709, v_12710, v_12711;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12672;
// end of prologue
    v_12709 = nil;
// Binding kord!*
// FLUIDBIND: reloadenv=2 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-2, 1, -1);
    qvalue(elt(env, 1)) = v_12709; // kord!*
    goto v_12685;
v_12681:
    v_12709 = stack[0];
    v_12710 = qcdr(v_12709);
    goto v_12682;
v_12683:
    v_12709 = elt(env, 2); // expt
    goto v_12684;
v_12685:
    goto v_12681;
v_12682:
    goto v_12683;
v_12684:
    fn = elt(env, 4); // carx
    v_12709 = (*qfn2(fn))(fn, v_12710, v_12709);
    env = stack[-2];
    fn = elt(env, 5); // simpexpon
    v_12709 = (*qfn1(fn))(fn, v_12709);
    env = stack[-2];
    ;}  // end of a binding scope
    goto v_12694;
v_12690:
    v_12710 = v_12709;
    goto v_12691;
v_12692:
    v_12709 = elt(env, 3); // resimp
    goto v_12693;
v_12694:
    goto v_12690;
v_12691:
    goto v_12692;
v_12693:
    fn = elt(env, 6); // simpexpon1
    v_12709 = (*qfn2(fn))(fn, v_12710, v_12709);
    env = stack[-2];
    goto v_12704;
v_12698:
    v_12710 = stack[0];
    v_12711 = qcar(v_12710);
    goto v_12699;
v_12700:
    v_12710 = v_12709;
    goto v_12701;
v_12702:
    v_12709 = nil;
    goto v_12703;
v_12704:
    goto v_12698;
v_12699:
    goto v_12700;
v_12701:
    goto v_12702;
v_12703:
    {
        fn = elt(env, 7); // simpexpt1
        return (*qfnn(fn))(fn, 3, v_12711, v_12710, v_12709);
    }
    return onevalue(v_12709);
}



// Code for inttovec1

static LispObject CC_inttovec1(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12727, v_12728;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12673;
    stack[-1] = v_12672;
// end of prologue
    goto v_12683;
v_12679:
    v_12728 = stack[-1];
    goto v_12680;
v_12681:
    v_12727 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12682;
v_12683:
    goto v_12679;
v_12680:
    goto v_12681;
v_12682:
    if (v_12728 == v_12727) goto v_12677;
    else goto v_12678;
v_12677:
    v_12727 = stack[0];
    v_12727 = qcar(v_12727);
    return ncons(v_12727);
v_12678:
    goto v_12696;
v_12692:
    v_12727 = stack[-1];
    v_12728 = sub1(v_12727);
    env = stack[-3];
    goto v_12693;
v_12694:
    v_12727 = stack[0];
    v_12727 = qcdr(v_12727);
    goto v_12695;
v_12696:
    goto v_12692;
v_12693:
    goto v_12694;
v_12695:
    fn = elt(env, 1); // inttovec!-solve
    v_12727 = (*qfn2(fn))(fn, v_12728, v_12727);
    env = stack[-3];
    stack[-2] = v_12727;
    goto v_12707;
v_12703:
    goto v_12713;
v_12709:
    v_12727 = stack[0];
    v_12728 = qcar(v_12727);
    goto v_12710;
v_12711:
    v_12727 = stack[-2];
    v_12727 = qcar(v_12727);
    goto v_12712;
v_12713:
    goto v_12709;
v_12710:
    goto v_12711;
v_12712:
    stack[0] = difference2(v_12728, v_12727);
    env = stack[-3];
    goto v_12704;
v_12705:
    goto v_12723;
v_12719:
    v_12727 = stack[-1];
    v_12728 = sub1(v_12727);
    env = stack[-3];
    goto v_12720;
v_12721:
    v_12727 = stack[-2];
    goto v_12722;
v_12723:
    goto v_12719;
v_12720:
    goto v_12721;
v_12722:
    v_12727 = CC_inttovec1(elt(env, 0), v_12728, v_12727);
    goto v_12706;
v_12707:
    goto v_12703;
v_12704:
    goto v_12705;
v_12706:
    {
        LispObject v_12732 = stack[0];
        return cons(v_12732, v_12727);
    }
    v_12727 = nil;
    return onevalue(v_12727);
}



// Code for mkfortterpri

static LispObject CC_mkfortterpri(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12675;
    argcheck(nargs, 0, "mkfortterpri");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_12675 = elt(env, 1); // fortterpri
    return ncons(v_12675);
}



// Code for collectphystype

static LispObject CC_collectphystype(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12732;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_12672;
// end of prologue
    v_12732 = stack[0];
    fn = elt(env, 1); // physopp
    v_12732 = (*qfn1(fn))(fn, v_12732);
    env = stack[-4];
    if (v_12732 == nil) goto v_12677;
    v_12732 = stack[0];
    fn = elt(env, 2); // getphystype
    v_12732 = (*qfn1(fn))(fn, v_12732);
    return ncons(v_12732);
v_12677:
    v_12732 = stack[0];
    if (!consp(v_12732)) goto v_12683;
    else goto v_12684;
v_12683:
    v_12732 = nil;
    goto v_12675;
v_12684:
    v_12732 = stack[0];
    stack[-3] = v_12732;
    v_12732 = stack[-3];
    if (v_12732 == nil) goto v_12699;
    else goto v_12700;
v_12699:
    v_12732 = nil;
    goto v_12694;
v_12700:
    v_12732 = stack[-3];
    v_12732 = qcar(v_12732);
    fn = elt(env, 2); // getphystype
    v_12732 = (*qfn1(fn))(fn, v_12732);
    env = stack[-4];
    v_12732 = ncons(v_12732);
    env = stack[-4];
    stack[-1] = v_12732;
    stack[-2] = v_12732;
v_12695:
    v_12732 = stack[-3];
    v_12732 = qcdr(v_12732);
    stack[-3] = v_12732;
    v_12732 = stack[-3];
    if (v_12732 == nil) goto v_12713;
    else goto v_12714;
v_12713:
    v_12732 = stack[-2];
    goto v_12694;
v_12714:
    goto v_12722;
v_12718:
    stack[0] = stack[-1];
    goto v_12719;
v_12720:
    v_12732 = stack[-3];
    v_12732 = qcar(v_12732);
    fn = elt(env, 2); // getphystype
    v_12732 = (*qfn1(fn))(fn, v_12732);
    env = stack[-4];
    v_12732 = ncons(v_12732);
    env = stack[-4];
    goto v_12721;
v_12722:
    goto v_12718;
v_12719:
    goto v_12720;
v_12721:
    v_12732 = Lrplacd(nil, stack[0], v_12732);
    env = stack[-4];
    v_12732 = stack[-1];
    v_12732 = qcdr(v_12732);
    stack[-1] = v_12732;
    goto v_12695;
v_12694:
    {
        fn = elt(env, 3); // deletemult!*
        return (*qfn1(fn))(fn, v_12732);
    }
    v_12732 = nil;
v_12675:
    return onevalue(v_12732);
}



// Code for replace1_parents

static LispObject CC_replace1_parents(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12691, v_12692, v_12693;
    LispObject fn;
    LispObject v_12674, v_12673, v_12672;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "replace1_parents");
    va_start(aa, nargs);
    v_12672 = va_arg(aa, LispObject);
    v_12673 = va_arg(aa, LispObject);
    v_12674 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12691 = v_12674;
    v_12692 = v_12673;
    v_12693 = v_12672;
// end of prologue
    goto v_12683;
v_12677:
    v_12693 = qcar(v_12693);
    goto v_12678;
v_12679:
    v_12692 = qcar(v_12692);
    goto v_12680;
v_12681:
    v_12691 = qcdr(v_12691);
    v_12691 = qcar(v_12691);
    goto v_12682;
v_12683:
    goto v_12677;
v_12678:
    goto v_12679;
v_12680:
    goto v_12681;
v_12682:
    {
        fn = elt(env, 1); // replace2_parents
        return (*qfnn(fn))(fn, 3, v_12693, v_12692, v_12691);
    }
}



// Code for setelv

static LispObject CC_setelv(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12733, v_12734;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_12673;
    v_12734 = v_12672;
// end of prologue
    goto v_12680;
v_12676:
    goto v_12686;
v_12682:
    v_12733 = v_12734;
    stack[-5] = qcar(v_12733);
    goto v_12683;
v_12684:
    v_12733 = v_12734;
    v_12733 = qcdr(v_12733);
    stack[-3] = v_12733;
    v_12733 = stack[-3];
    if (v_12733 == nil) goto v_12699;
    else goto v_12700;
v_12699:
    v_12733 = nil;
    goto v_12693;
v_12700:
    v_12733 = stack[-3];
    v_12733 = qcar(v_12733);
    fn = elt(env, 1); // reval_without_mod
    v_12733 = (*qfn1(fn))(fn, v_12733);
    env = stack[-6];
    v_12733 = ncons(v_12733);
    env = stack[-6];
    stack[-1] = v_12733;
    stack[-2] = v_12733;
v_12694:
    v_12733 = stack[-3];
    v_12733 = qcdr(v_12733);
    stack[-3] = v_12733;
    v_12733 = stack[-3];
    if (v_12733 == nil) goto v_12713;
    else goto v_12714;
v_12713:
    v_12733 = stack[-2];
    goto v_12693;
v_12714:
    goto v_12722;
v_12718:
    stack[0] = stack[-1];
    goto v_12719;
v_12720:
    v_12733 = stack[-3];
    v_12733 = qcar(v_12733);
    fn = elt(env, 1); // reval_without_mod
    v_12733 = (*qfn1(fn))(fn, v_12733);
    env = stack[-6];
    v_12733 = ncons(v_12733);
    env = stack[-6];
    goto v_12721;
v_12722:
    goto v_12718;
v_12719:
    goto v_12720;
v_12721:
    v_12733 = Lrplacd(nil, stack[0], v_12733);
    env = stack[-6];
    v_12733 = stack[-1];
    v_12733 = qcdr(v_12733);
    stack[-1] = v_12733;
    goto v_12694;
v_12693:
    goto v_12685;
v_12686:
    goto v_12682;
v_12683:
    goto v_12684;
v_12685:
    v_12734 = cons(stack[-5], v_12733);
    env = stack[-6];
    goto v_12677;
v_12678:
    v_12733 = stack[-4];
    goto v_12679;
v_12680:
    goto v_12676;
v_12677:
    goto v_12678;
v_12679:
    {
        fn = elt(env, 2); // setel
        return (*qfn2(fn))(fn, v_12734, v_12733);
    }
}



// Code for red!=cancelsimp

static LispObject CC_redMcancelsimp(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12702, v_12703;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12673;
    stack[-1] = v_12672;
// end of prologue
    goto v_12684;
v_12680:
    v_12703 = stack[-1];
    goto v_12681;
v_12682:
    v_12702 = stack[0];
    goto v_12683;
v_12684:
    goto v_12680;
v_12681:
    goto v_12682;
v_12683:
    fn = elt(env, 1); // red_better
    v_12702 = (*qfn2(fn))(fn, v_12703, v_12702);
    env = stack[-2];
    if (v_12702 == nil) goto v_12677;
    else goto v_12678;
v_12677:
    v_12702 = nil;
    goto v_12676;
v_12678:
    goto v_12695;
v_12691:
    v_12702 = stack[-1];
    fn = elt(env, 2); // bas_dpoly
    v_12702 = (*qfn1(fn))(fn, v_12702);
    env = stack[-2];
    fn = elt(env, 3); // dp_lmon
    stack[-1] = (*qfn1(fn))(fn, v_12702);
    env = stack[-2];
    goto v_12692;
v_12693:
    v_12702 = stack[0];
    fn = elt(env, 2); // bas_dpoly
    v_12702 = (*qfn1(fn))(fn, v_12702);
    env = stack[-2];
    fn = elt(env, 3); // dp_lmon
    v_12702 = (*qfn1(fn))(fn, v_12702);
    env = stack[-2];
    goto v_12694;
v_12695:
    goto v_12691;
v_12692:
    goto v_12693;
v_12694:
    {
        LispObject v_12706 = stack[-1];
        fn = elt(env, 4); // mo_vdivides!?
        return (*qfn2(fn))(fn, v_12706, v_12702);
    }
    v_12702 = nil;
v_12676:
    return onevalue(v_12702);
}



// Code for pst_termnodep

static LispObject CC_pst_termnodep(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12685, v_12686;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12685 = v_12672;
// end of prologue
    goto v_12678;
v_12674:
    v_12686 = qcdr(v_12685);
    goto v_12675;
v_12676:
    v_12685 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12677;
v_12678:
    goto v_12674;
v_12675:
    goto v_12676;
v_12677:
    v_12685 = *(LispObject *)((char *)v_12686 + (CELL-TAG_VECTOR) + (((intptr_t)v_12685-TAG_FIXNUM)/(16/CELL)));
    v_12685 = qcdr(v_12685);
    v_12685 = (v_12685 == nil ? lisp_true : nil);
    return onevalue(v_12685);
}



// Code for ratn

static LispObject CC_ratn(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12723, v_12724, v_12725;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12725 = v_12672;
// end of prologue
    v_12723 = v_12725;
    if (v_12723 == nil) goto v_12676;
    else goto v_12677;
v_12676:
    goto v_12684;
v_12680:
    v_12724 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_12681;
v_12682:
    v_12723 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12683;
v_12684:
    goto v_12680;
v_12681:
    goto v_12682;
v_12683:
    return cons(v_12724, v_12723);
v_12677:
    v_12723 = v_12725;
    if (!consp(v_12723)) goto v_12687;
    else goto v_12688;
v_12687:
    goto v_12695;
v_12691:
    v_12724 = v_12725;
    goto v_12692;
v_12693:
    v_12723 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12694;
v_12695:
    goto v_12691;
v_12692:
    goto v_12693;
v_12694:
    return cons(v_12724, v_12723);
v_12688:
    goto v_12704;
v_12700:
    v_12723 = v_12725;
    v_12724 = qcar(v_12723);
    goto v_12701;
v_12702:
    v_12723 = elt(env, 1); // !:rn!:
    goto v_12703;
v_12704:
    goto v_12700;
v_12701:
    goto v_12702;
v_12703:
    if (v_12724 == v_12723) goto v_12698;
    else goto v_12699;
v_12698:
    v_12723 = v_12725;
    v_12723 = qcdr(v_12723);
    goto v_12675;
v_12699:
    goto v_12719;
v_12713:
    v_12725 = elt(env, 2); // arnum
    goto v_12714;
v_12715:
    v_12724 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_12716;
v_12717:
    v_12723 = elt(env, 3); // "Illegal domain in :ar:"
    goto v_12718;
v_12719:
    goto v_12713;
v_12714:
    goto v_12715;
v_12716:
    goto v_12717;
v_12718:
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_12725, v_12724, v_12723);
    }
    v_12723 = nil;
v_12675:
    return onevalue(v_12723);
}



// Code for crprcd2

static LispObject CC_crprcd2(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12680;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12673;
    stack[-1] = v_12672;
// end of prologue
    v_12680 = stack[-1];
    fn = elt(env, 2); // crprcd
    v_12680 = (*qfn1(fn))(fn, v_12680);
    env = stack[-2];
    stack[-1] = v_12680;
    v_12680 = stack[0];
    fn = elt(env, 2); // crprcd
    v_12680 = (*qfn1(fn))(fn, v_12680);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_12680; // yy!!
    v_12680 = stack[-1];
    return onevalue(v_12680);
}



// Code for innprodkp

static LispObject CC_innprodkp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12727, v_12728, v_12729;
    LispObject fn;
    LispObject v_12675, v_12674, v_12673, v_12672;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "innprodkp");
    va_start(aa, nargs);
    v_12672 = va_arg(aa, LispObject);
    v_12673 = va_arg(aa, LispObject);
    v_12674 = va_arg(aa, LispObject);
    v_12675 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_12675,v_12674,v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_12672,v_12673,v_12674,v_12675);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_12675;
    stack[-1] = v_12674;
    stack[-2] = v_12673;
    v_12728 = v_12672;
// end of prologue
v_12679:
    v_12727 = stack[-1];
    if (v_12727 == nil) goto v_12682;
    else goto v_12683;
v_12682:
    v_12727 = nil;
    goto v_12678;
v_12683:
    goto v_12692;
v_12688:
    v_12729 = stack[-2];
    goto v_12689;
v_12690:
    v_12727 = stack[-1];
    v_12727 = qcar(v_12727);
    goto v_12691;
v_12692:
    goto v_12688;
v_12689:
    goto v_12690;
v_12691:
    if (equal(v_12729, v_12727)) goto v_12686;
    else goto v_12687;
v_12686:
    goto v_12701;
v_12697:
    goto v_12698;
v_12699:
    goto v_12708;
v_12704:
    goto v_12705;
v_12706:
    v_12727 = stack[-1];
    v_12727 = qcdr(v_12727);
    goto v_12707;
v_12708:
    goto v_12704;
v_12705:
    goto v_12706;
v_12707:
    fn = elt(env, 1); // reversip2
    v_12727 = (*qfn2(fn))(fn, v_12728, v_12727);
    goto v_12700;
v_12701:
    goto v_12697;
v_12698:
    goto v_12699;
v_12700:
    {
        LispObject v_12733 = stack[0];
        return cons(v_12733, v_12727);
    }
v_12687:
    goto v_12719;
v_12715:
    v_12727 = stack[-1];
    v_12727 = qcar(v_12727);
    goto v_12716;
v_12717:
    goto v_12718;
v_12719:
    goto v_12715;
v_12716:
    goto v_12717;
v_12718:
    v_12727 = cons(v_12727, v_12728);
    env = stack[-3];
    v_12728 = v_12727;
    v_12727 = stack[-1];
    v_12727 = qcdr(v_12727);
    stack[-1] = v_12727;
    v_12727 = stack[0];
    v_12727 = (v_12727 == nil ? lisp_true : nil);
    stack[0] = v_12727;
    goto v_12679;
    v_12727 = nil;
v_12678:
    return onevalue(v_12727);
}



// Code for dfprint

static LispObject CC_dfprint(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12719, v_12720;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_12672;
// end of prologue
    v_12719 = qvalue(elt(env, 1)); // dfprint!*
    if (v_12719 == nil) goto v_12677;
    goto v_12684;
v_12680:
    stack[-1] = qvalue(elt(env, 1)); // dfprint!*
    goto v_12681;
v_12682:
    v_12719 = stack[0];
    v_12719 = ncons(v_12719);
    env = stack[-2];
    goto v_12683;
v_12684:
    goto v_12680;
v_12681:
    goto v_12682;
v_12683:
    {
        LispObject v_12723 = stack[-1];
        fn = elt(env, 4); // lispapply
        return (*qfn2(fn))(fn, v_12723, v_12719);
    }
v_12677:
    v_12719 = qvalue(elt(env, 2)); // cmsg!*
    if (v_12719 == nil) goto v_12689;
    v_12719 = nil;
    goto v_12675;
v_12689:
    goto v_12699;
v_12695:
    v_12720 = stack[0];
    goto v_12696;
v_12697:
    v_12719 = elt(env, 3); // progn
    goto v_12698;
v_12699:
    goto v_12695;
v_12696:
    goto v_12697;
v_12698:
    if (!consp(v_12720)) goto v_12692;
    v_12720 = qcar(v_12720);
    if (v_12720 == v_12719) goto v_12693;
v_12692:
    v_12719 = stack[0];
    {
        fn = elt(env, 5); // prettyprint
        return (*qfn1(fn))(fn, v_12719);
    }
v_12693:
v_12708:
    v_12719 = stack[0];
    v_12719 = qcdr(v_12719);
    stack[0] = v_12719;
    if (v_12719 == nil) goto v_12711;
    else goto v_12712;
v_12711:
    v_12719 = nil;
    goto v_12707;
v_12712:
    v_12719 = stack[0];
    v_12719 = qcar(v_12719);
    v_12719 = CC_dfprint(elt(env, 0), v_12719);
    env = stack[-2];
    goto v_12708;
v_12707:
    goto v_12675;
    v_12719 = nil;
v_12675:
    return onevalue(v_12719);
}



// Code for monomwrite

static LispObject CC_monomwrite(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12772, v_12773, v_12774;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_12773 = v_12672;
// end of prologue
    stack[-5] = nil;
    v_12772 = qvalue(elt(env, 1)); // fluidbibasisnumberofvariables
    stack[-2] = v_12772;
    v_12772 = qvalue(elt(env, 2)); // fluidbibasisreversedvariables
    stack[-4] = v_12772;
    goto v_12687;
v_12683:
    goto v_12684;
v_12685:
    v_12772 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12686;
v_12687:
    goto v_12683;
v_12684:
    goto v_12685;
v_12686:
    v_12772 = *(LispObject *)((char *)v_12773 + (CELL-TAG_VECTOR) + (((intptr_t)v_12772-TAG_FIXNUM)/(16/CELL)));
    stack[-3] = v_12772;
v_12693:
    v_12772 = stack[-3];
    v_12772 = qcar(v_12772);
    if (v_12772 == nil) goto v_12696;
    else goto v_12697;
v_12696:
    goto v_12692;
v_12697:
    v_12772 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_12772;
v_12704:
    goto v_12716;
v_12712:
    goto v_12722;
v_12718:
    v_12773 = stack[-2];
    goto v_12719;
v_12720:
    v_12772 = stack[-3];
    v_12772 = qcar(v_12772);
    goto v_12721;
v_12722:
    goto v_12718;
v_12719:
    goto v_12720;
v_12721:
    v_12773 = difference2(v_12773, v_12772);
    env = stack[-6];
    goto v_12713;
v_12714:
    v_12772 = stack[0];
    goto v_12715;
v_12716:
    goto v_12712;
v_12713:
    goto v_12714;
v_12715:
    v_12772 = difference2(v_12773, v_12772);
    env = stack[-6];
    v_12772 = Lminusp(nil, v_12772);
    env = stack[-6];
    if (v_12772 == nil) goto v_12709;
    goto v_12703;
v_12709:
    v_12772 = stack[-4];
    v_12772 = qcdr(v_12772);
    stack[-4] = v_12772;
    v_12772 = stack[0];
    v_12772 = add1(v_12772);
    env = stack[-6];
    stack[0] = v_12772;
    goto v_12704;
v_12703:
    v_12772 = stack[-3];
    v_12772 = qcar(v_12772);
    stack[-2] = v_12772;
    v_12772 = stack[-5];
    if (v_12772 == nil) goto v_12738;
    goto v_12747;
v_12741:
    v_12772 = stack[-4];
    stack[-1] = qcar(v_12772);
    goto v_12742;
v_12743:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12744;
v_12745:
    v_12772 = stack[-5];
    v_12772 = ncons(v_12772);
    env = stack[-6];
    goto v_12746;
v_12747:
    goto v_12741;
v_12742:
    goto v_12743;
v_12744:
    goto v_12745;
v_12746:
    v_12772 = acons(stack[-1], stack[0], v_12772);
    env = stack[-6];
    stack[-5] = v_12772;
    goto v_12736;
v_12738:
    goto v_12762;
v_12756:
    v_12772 = stack[-4];
    v_12774 = qcar(v_12772);
    goto v_12757;
v_12758:
    v_12773 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12759;
v_12760:
    v_12772 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12761;
v_12762:
    goto v_12756;
v_12757:
    goto v_12758;
v_12759:
    goto v_12760;
v_12761:
    v_12772 = acons(v_12774, v_12773, v_12772);
    env = stack[-6];
    stack[-5] = v_12772;
    goto v_12736;
v_12736:
    v_12772 = stack[-3];
    v_12772 = qcdr(v_12772);
    stack[-3] = v_12772;
    goto v_12693;
v_12692:
    v_12772 = stack[-5];
    return onevalue(v_12772);
}



// Code for mkpartitions1

static LispObject CC_mkpartitions1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_12800, v_12801, v_12802, v_12803;
    LispObject v_12677, v_12676, v_12675, v_12674, v_12673, v_12672;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "mkpartitions1");
    va_start(aa, nargs);
    v_12672 = va_arg(aa, LispObject);
    v_12673 = va_arg(aa, LispObject);
    v_12674 = va_arg(aa, LispObject);
    v_12675 = va_arg(aa, LispObject);
    v_12676 = va_arg(aa, LispObject);
    v_12677 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_12677,v_12676,v_12675,v_12674,v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_12672,v_12673,v_12674,v_12675,v_12676,v_12677);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-3] = v_12677;
    stack[-4] = v_12676;
    stack[-5] = v_12675;
    stack[-6] = v_12674;
    stack[-7] = v_12673;
    stack[-8] = v_12672;
// end of prologue
v_12685:
    goto v_12694;
v_12690:
    v_12801 = stack[-7];
    goto v_12691;
v_12692:
    v_12800 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_12693;
v_12694:
    goto v_12690;
v_12691:
    goto v_12692;
v_12693:
    if (v_12801 == v_12800) goto v_12688;
    else goto v_12689;
v_12688:
    goto v_12706;
v_12702:
    v_12801 = stack[-8];
    goto v_12703;
v_12704:
    v_12800 = stack[-6];
    goto v_12705;
v_12706:
    goto v_12702;
v_12703:
    goto v_12704;
v_12705:
    v_12800 = (LispObject)geq2(v_12801, v_12800);
    v_12800 = v_12800 ? lisp_true : nil;
    env = stack[-10];
    if (v_12800 == nil) goto v_12700;
    goto v_12714;
v_12710:
    goto v_12721;
v_12717:
    v_12801 = stack[-8];
    goto v_12718;
v_12719:
    v_12800 = stack[-4];
    goto v_12720;
v_12721:
    goto v_12717;
v_12718:
    goto v_12719;
v_12720:
    v_12800 = cons(v_12801, v_12800);
    env = stack[-10];
    v_12801 = Lreverse(nil, v_12800);
    goto v_12711;
v_12712:
    v_12800 = stack[-3];
    goto v_12713;
v_12714:
    goto v_12710;
v_12711:
    goto v_12712;
v_12713:
    return cons(v_12801, v_12800);
v_12700:
    v_12800 = stack[-3];
    goto v_12684;
    goto v_12687;
v_12689:
    goto v_12735;
v_12731:
    v_12801 = stack[-6];
    goto v_12732;
v_12733:
    v_12800 = stack[-5];
    goto v_12734;
v_12735:
    goto v_12731;
v_12732:
    goto v_12733;
v_12734:
    v_12800 = (LispObject)greaterp2(v_12801, v_12800);
    v_12800 = v_12800 ? lisp_true : nil;
    env = stack[-10];
    if (v_12800 == nil) goto v_12729;
    v_12800 = stack[-3];
    goto v_12684;
v_12729:
    goto v_12746;
v_12742:
    v_12801 = stack[-8];
    goto v_12743;
v_12744:
    v_12800 = stack[-6];
    goto v_12745;
v_12746:
    goto v_12742;
v_12743:
    goto v_12744;
v_12745:
    v_12800 = difference2(v_12801, v_12800);
    env = stack[-10];
    stack[-9] = v_12800;
    v_12800 = stack[-7];
    v_12800 = sub1(v_12800);
    env = stack[-10];
    stack[-2] = v_12800;
    goto v_12756;
v_12752:
    goto v_12762;
v_12758:
    v_12801 = stack[-8];
    goto v_12759;
v_12760:
    v_12800 = stack[-6];
    goto v_12761;
v_12762:
    goto v_12758;
v_12759:
    goto v_12760;
v_12761:
    stack[0] = difference2(v_12801, v_12800);
    env = stack[-10];
    goto v_12753;
v_12754:
    v_12800 = stack[-7];
    v_12800 = sub1(v_12800);
    env = stack[-10];
    goto v_12755;
v_12756:
    goto v_12752;
v_12753:
    goto v_12754;
v_12755:
    v_12800 = quot2(stack[0], v_12800);
    env = stack[-10];
    stack[-1] = v_12800;
    goto v_12772;
v_12768:
    v_12801 = stack[-6];
    goto v_12769;
v_12770:
    v_12800 = stack[-4];
    goto v_12771;
v_12772:
    goto v_12768;
v_12769:
    goto v_12770;
v_12771:
    v_12800 = cons(v_12801, v_12800);
    env = stack[-10];
    stack[0] = v_12800;
    goto v_12788;
v_12776:
    goto v_12777;
v_12778:
    goto v_12779;
v_12780:
    v_12800 = stack[-6];
    v_12803 = add1(v_12800);
    env = stack[-10];
    goto v_12781;
v_12782:
    v_12802 = stack[-5];
    goto v_12783;
v_12784:
    v_12801 = stack[-4];
    goto v_12785;
v_12786:
    v_12800 = stack[-3];
    goto v_12787;
v_12788:
    goto v_12776;
v_12777:
    goto v_12778;
v_12779:
    goto v_12780;
v_12781:
    goto v_12782;
v_12783:
    goto v_12784;
v_12785:
    goto v_12786;
v_12787:
    v_12800 = CC_mkpartitions1(elt(env, 0), 6, stack[-8], stack[-7], v_12803, v_12802, v_12801, v_12800);
    env = stack[-10];
    stack[-3] = v_12800;
    v_12800 = stack[0];
    stack[-4] = v_12800;
    v_12800 = stack[-1];
    stack[-5] = v_12800;
    v_12800 = stack[-2];
    stack[-7] = v_12800;
    v_12800 = stack[-9];
    stack[-8] = v_12800;
    goto v_12685;
v_12687:
    v_12800 = nil;
v_12684:
    return onevalue(v_12800);
}



// Code for revalx

static LispObject CC_revalx(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12696, v_12697;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_12697 = v_12672;
// end of prologue
    v_12696 = v_12697;
    if (!consp(v_12696)) goto v_12682;
    v_12696 = v_12697;
    v_12696 = qcar(v_12696);
    v_12696 = (consp(v_12696) ? nil : lisp_true);
    v_12696 = (v_12696 == nil ? lisp_true : nil);
    goto v_12680;
v_12682:
    v_12696 = nil;
    goto v_12680;
    v_12696 = nil;
v_12680:
    if (v_12696 == nil) goto v_12678;
    v_12696 = v_12697;
    fn = elt(env, 1); // prepf
    v_12696 = (*qfn1(fn))(fn, v_12696);
    env = stack[0];
    goto v_12676;
v_12678:
    v_12696 = v_12697;
    goto v_12676;
    v_12696 = nil;
v_12676:
    {
        fn = elt(env, 2); // reval
        return (*qfn1(fn))(fn, v_12696);
    }
}



// Code for get!*elements

static LispObject CC_getHelements(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12685, v_12686;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12685 = v_12672;
// end of prologue
    goto v_12682;
v_12678:
    goto v_12679;
v_12680:
    v_12686 = elt(env, 1); // elems
    goto v_12681;
v_12682:
    goto v_12678;
v_12679:
    goto v_12680;
v_12681:
    return get(v_12685, v_12686);
    return onevalue(v_12685);
}



// Code for talp_subt

static LispObject CC_talp_subt(LispObject env,
                         LispObject v_12672, LispObject v_12673)
{
    env = qenv(env);
    LispObject v_12764, v_12765, v_12766;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_12673,v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_12672,v_12673);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_12765 = v_12673;
    stack[-4] = v_12672;
// end of prologue
    v_12764 = v_12765;
    if (symbolp(v_12764)) goto v_12682;
    else goto v_12681;
v_12682:
    goto v_12689;
v_12685:
    v_12766 = v_12765;
    goto v_12686;
v_12687:
    v_12764 = stack[-4];
    goto v_12688;
v_12689:
    goto v_12685;
v_12686:
    goto v_12687;
v_12688:
    v_12764 = Latsoc(nil, v_12766, v_12764);
    v_12766 = v_12764;
    if (v_12764 == nil) goto v_12681;
    v_12764 = v_12766;
    v_12764 = qcdr(v_12764);
    goto v_12677;
v_12681:
    v_12764 = v_12765;
    if (!consp(v_12764)) goto v_12697;
    else goto v_12698;
v_12697:
    v_12764 = v_12765;
    goto v_12677;
v_12698:
    goto v_12706;
v_12702:
    v_12764 = v_12765;
    stack[-5] = qcar(v_12764);
    goto v_12703;
v_12704:
    v_12764 = v_12765;
    v_12764 = qcdr(v_12764);
    stack[-3] = v_12764;
    v_12764 = stack[-3];
    if (v_12764 == nil) goto v_12719;
    else goto v_12720;
v_12719:
    v_12764 = nil;
    goto v_12713;
v_12720:
    v_12764 = stack[-3];
    v_12764 = qcar(v_12764);
    goto v_12732;
v_12728:
    v_12765 = stack[-4];
    goto v_12729;
v_12730:
    goto v_12731;
v_12732:
    goto v_12728;
v_12729:
    goto v_12730;
v_12731:
    v_12764 = CC_talp_subt(elt(env, 0), v_12765, v_12764);
    env = stack[-6];
    v_12764 = ncons(v_12764);
    env = stack[-6];
    stack[-1] = v_12764;
    stack[-2] = v_12764;
v_12714:
    v_12764 = stack[-3];
    v_12764 = qcdr(v_12764);
    stack[-3] = v_12764;
    v_12764 = stack[-3];
    if (v_12764 == nil) goto v_12739;
    else goto v_12740;
v_12739:
    v_12764 = stack[-2];
    goto v_12713;
v_12740:
    goto v_12748;
v_12744:
    stack[0] = stack[-1];
    goto v_12745;
v_12746:
    v_12764 = stack[-3];
    v_12764 = qcar(v_12764);
    goto v_12759;
v_12755:
    v_12765 = stack[-4];
    goto v_12756;
v_12757:
    goto v_12758;
v_12759:
    goto v_12755;
v_12756:
    goto v_12757;
v_12758:
    v_12764 = CC_talp_subt(elt(env, 0), v_12765, v_12764);
    env = stack[-6];
    v_12764 = ncons(v_12764);
    env = stack[-6];
    goto v_12747;
v_12748:
    goto v_12744;
v_12745:
    goto v_12746;
v_12747:
    v_12764 = Lrplacd(nil, stack[0], v_12764);
    env = stack[-6];
    v_12764 = stack[-1];
    v_12764 = qcdr(v_12764);
    stack[-1] = v_12764;
    goto v_12714;
v_12713:
    goto v_12705;
v_12706:
    goto v_12702;
v_12703:
    goto v_12704;
v_12705:
    {
        LispObject v_12773 = stack[-5];
        return cons(v_12773, v_12764);
    }
v_12677:
    return onevalue(v_12764);
}



// Code for naryom

static LispObject CC_naryom(LispObject env,
                         LispObject v_12672)
{
    env = qenv(env);
    LispObject v_12766, v_12767;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_12672);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_12672);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_12672;
// end of prologue
    v_12766 = stack[-1];
    v_12766 = qcar(v_12766);
    stack[0] = v_12766;
    goto v_12688;
v_12684:
    v_12767 = stack[0];
    goto v_12685;
v_12686:
    v_12766 = elt(env, 1); // var
    goto v_12687;
v_12688:
    goto v_12684;
v_12685:
    goto v_12686;
v_12687:
    if (v_12767 == v_12766) goto v_12682;
    else goto v_12683;
v_12682:
    v_12766 = elt(env, 2); // variance
    stack[0] = v_12766;
    goto v_12681;
v_12683:
v_12681:
    goto v_12696;
v_12692:
    v_12767 = stack[0];
    goto v_12693;
v_12694:
    v_12766 = qvalue(elt(env, 3)); // valid_om!*
    goto v_12695;
v_12696:
    goto v_12692;
v_12693:
    goto v_12694;
v_12695:
    v_12766 = Lassoc(nil, v_12767, v_12766);
    stack[-2] = v_12766;
    v_12766 = stack[-2];
    if (v_12766 == nil) goto v_12703;
    v_12766 = stack[-2];
    v_12766 = qcdr(v_12766);
    v_12766 = qcar(v_12766);
    stack[-2] = v_12766;
    goto v_12701;
v_12703:
v_12701:
    v_12766 = stack[-1];
    v_12766 = qcdr(v_12766);
    v_12766 = qcar(v_12766);
    if (v_12766 == nil) goto v_12711;
    goto v_12723;
v_12719:
    v_12766 = stack[-1];
    v_12766 = qcdr(v_12766);
    v_12767 = qcar(v_12766);
    goto v_12720;
v_12721:
    v_12766 = elt(env, 4); // multiset
    goto v_12722;
v_12723:
    goto v_12719;
v_12720:
    goto v_12721;
v_12722:
    if (v_12767 == v_12766) goto v_12717;
    else goto v_12718;
v_12717:
    v_12766 = stack[-1];
    v_12766 = qcdr(v_12766);
    v_12766 = qcar(v_12766);
    stack[-2] = v_12766;
    goto v_12716;
v_12718:
v_12716:
    goto v_12709;
v_12711:
v_12709:
    v_12766 = elt(env, 5); // "<OMA>"
    fn = elt(env, 11); // printout
    v_12766 = (*qfn1(fn))(fn, v_12766);
    env = stack[-3];
    goto v_12739;
v_12735:
    v_12767 = qvalue(elt(env, 6)); // indent
    goto v_12736;
v_12737:
    v_12766 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_12738;
v_12739:
    goto v_12735;
v_12736:
    goto v_12737;
v_12738:
    v_12766 = plus2(v_12767, v_12766);
    env = stack[-3];
    qvalue(elt(env, 6)) = v_12766; // indent
    v_12766 = elt(env, 7); // "<OMS cd="""
    fn = elt(env, 11); // printout
    v_12766 = (*qfn1(fn))(fn, v_12766);
    env = stack[-3];
    v_12766 = stack[-2];
    v_12766 = Lprinc(nil, v_12766);
    env = stack[-3];
    v_12766 = elt(env, 8); // """ name="""
    v_12766 = Lprinc(nil, v_12766);
    env = stack[-3];
    v_12766 = stack[0];
    v_12766 = Lprinc(nil, v_12766);
    env = stack[-3];
    v_12766 = elt(env, 9); // """>"
    v_12766 = Lprinc(nil, v_12766);
    env = stack[-3];
    v_12766 = stack[-1];
    v_12766 = qcdr(v_12766);
    v_12766 = qcdr(v_12766);
    fn = elt(env, 12); // multiom
    v_12766 = (*qfn1(fn))(fn, v_12766);
    env = stack[-3];
    goto v_12761;
v_12757:
    v_12767 = qvalue(elt(env, 6)); // indent
    goto v_12758;
v_12759:
    v_12766 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_12760;
v_12761:
    goto v_12757;
v_12758:
    goto v_12759;
v_12760:
    v_12766 = difference2(v_12767, v_12766);
    env = stack[-3];
    qvalue(elt(env, 6)) = v_12766; // indent
    v_12766 = elt(env, 10); // "</OMA>"
    fn = elt(env, 11); // printout
    v_12766 = (*qfn1(fn))(fn, v_12766);
    v_12766 = nil;
    return onevalue(v_12766);
}



setup_type const u22_setup[] =
{
    {"lienjactest",             CC_lienjactest, TOO_MANY_1,    WRONG_NO_1},
    {"mv-pow-mv-+",             TOO_FEW_2,      CC_mvKpowKmvKL,WRONG_NO_2},
    {"ilcm",                    TOO_FEW_2,      CC_ilcm,       WRONG_NO_2},
    {"quotfail-in-vector",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_quotfailKinKvector},
    {"gcref_mkgraph",           CC_gcref_mkgraph,TOO_MANY_1,   WRONG_NO_1},
    {"ofsf_smwmkatl",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smwmkatl},
    {"ezgcdf1",                 TOO_FEW_2,      CC_ezgcdf1,    WRONG_NO_2},
    {"talp_eqnrhskernels",      CC_talp_eqnrhskernels,TOO_MANY_1,WRONG_NO_1},
    {"delet",                   TOO_FEW_2,      CC_delet,      WRONG_NO_2},
    {"horner-rule-mod-p",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_hornerKruleKmodKp},
    {"getsetvars",              CC_getsetvars,  TOO_MANY_1,    WRONG_NO_1},
    {"mchkopt1",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mchkopt1},
    {"ps:evaluate",             TOO_FEW_2,      CC_psTevaluate,WRONG_NO_2},
    {"reform-minus",            TOO_FEW_2,      CC_reformKminus,WRONG_NO_2},
    {"setmat",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setmat},
    {"freeoffl",                TOO_FEW_2,      CC_freeoffl,   WRONG_NO_2},
    {"indordp",                 TOO_FEW_2,      CC_indordp,    WRONG_NO_2},
    {"symbvarlst",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_symbvarlst},
    {"mv-domainlist-+",         TOO_FEW_2,      CC_mvKdomainlistKL,WRONG_NO_2},
    {"mo_lcm",                  TOO_FEW_2,      CC_mo_lcm,     WRONG_NO_2},
    {"arglist_member",          TOO_FEW_2,      CC_arglist_member,WRONG_NO_2},
    {"drop_rl_with",            TOO_FEW_2,      CC_drop_rl_with,WRONG_NO_2},
    {"yypeek",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_yypeek},
    {"collect_cdrs",            CC_collect_cdrs,TOO_MANY_1,    WRONG_NO_1},
    {"setqget",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setqget},
    {"reln",                    TOO_FEW_2,      CC_reln,       WRONG_NO_2},
    {"ps:prepfn:",              CC_psTprepfnT,  TOO_MANY_1,    WRONG_NO_1},
    {"diffsq",                  TOO_FEW_2,      CC_diffsq,     WRONG_NO_2},
    {"xdegreecheck",            CC_xdegreecheck,TOO_MANY_1,    WRONG_NO_1},
    {"fortexp",                 CC_fortexp,     TOO_MANY_1,    WRONG_NO_1},
    {"physopsm*",               CC_physopsmH,   TOO_MANY_1,    WRONG_NO_1},
    {"assert_uninstall1",       CC_assert_uninstall1,TOO_MANY_1,WRONG_NO_1},
    {"prepd1",                  CC_prepd1,      TOO_MANY_1,    WRONG_NO_1},
    {"ad_numsort",              CC_ad_numsort,  TOO_MANY_1,    WRONG_NO_1},
    {"lambda_ygm6np4pcqv31",    TOO_FEW_2,      CC_lambda_ygm6np4pcqv31,WRONG_NO_2},
    {"resimpf",                 CC_resimpf,     TOO_MANY_1,    WRONG_NO_1},
    {"quotkx",                  TOO_FEW_2,      CC_quotkx,     WRONG_NO_2},
    {"qqe_arg-check",           CC_qqe_argKcheck,TOO_MANY_1,   WRONG_NO_1},
    {"**a2s",                   TOO_FEW_2,      CC_HHa2s,      WRONG_NO_2},
    {"dm-minus",                CC_dmKminus,    TOO_MANY_1,    WRONG_NO_1},
    {"groebcplistsortin1",      TOO_FEW_2,      CC_groebcplistsortin1,WRONG_NO_2},
    {"bytelist2id",             CC_bytelist2id, TOO_MANY_1,    WRONG_NO_1},
    {"gfdot",                   TOO_FEW_2,      CC_gfdot,      WRONG_NO_2},
    {"rdcos*",                  CC_rdcosH,      TOO_MANY_1,    WRONG_NO_1},
    {"trwrite",                 CC_trwrite,     TOO_MANY_1,    WRONG_NO_1},
    {"repartf",                 CC_repartf,     TOO_MANY_1,    WRONG_NO_1},
    {"one-entry-listp",         TOO_FEW_2,      CC_oneKentryKlistp,WRONG_NO_2},
    {"fs:times",                TOO_FEW_2,      CC_fsTtimes,   WRONG_NO_2},
    {"moid_member",             TOO_FEW_2,      CC_moid_member,WRONG_NO_2},
    {"splitlist:",              TOO_FEW_2,      CC_splitlistT, WRONG_NO_2},
    {"gfk",                     WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_gfk},
    {"aex_neg",                 CC_aex_neg,     TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_surep",              TOO_FEW_2,      CC_ofsf_surep, WRONG_NO_2},
    {"simpexpt",                CC_simpexpt,    TOO_MANY_1,    WRONG_NO_1},
    {"inttovec1",               TOO_FEW_2,      CC_inttovec1,  WRONG_NO_2},
    {"mkfortterpri",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mkfortterpri},
    {"collectphystype",         CC_collectphystype,TOO_MANY_1, WRONG_NO_1},
    {"replace1_parents",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_replace1_parents},
    {"setelv",                  TOO_FEW_2,      CC_setelv,     WRONG_NO_2},
    {"red=cancelsimp",          TOO_FEW_2,      CC_redMcancelsimp,WRONG_NO_2},
    {"pst_termnodep",           CC_pst_termnodep,TOO_MANY_1,   WRONG_NO_1},
    {"ratn",                    CC_ratn,        TOO_MANY_1,    WRONG_NO_1},
    {"crprcd2",                 TOO_FEW_2,      CC_crprcd2,    WRONG_NO_2},
    {"innprodkp",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_innprodkp},
    {"dfprint",                 CC_dfprint,     TOO_MANY_1,    WRONG_NO_1},
    {"monomwrite",              CC_monomwrite,  TOO_MANY_1,    WRONG_NO_1},
    {"mkpartitions1",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mkpartitions1},
    {"revalx",                  CC_revalx,      TOO_MANY_1,    WRONG_NO_1},
    {"get*elements",            CC_getHelements,TOO_MANY_1,    WRONG_NO_1},
    {"talp_subt",               TOO_FEW_2,      CC_talp_subt,  WRONG_NO_2},
    {"naryom",                  CC_naryom,      TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u22", (two_args *)"34335 2034270 8437448", 0}
};

// end of generated code
