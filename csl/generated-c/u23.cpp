
// $destdir/u23.c        Machine generated C code

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



// Code for evdif

static LispObject CC_evdif(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13155, v_13156, v_13157;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13104,v_13105);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13105;
    stack[-1] = v_13104;
// end of prologue
    v_13157 = nil;
v_13112:
    v_13155 = stack[0];
    if (v_13155 == nil) goto v_13115;
    else goto v_13116;
v_13115:
    goto v_13111;
v_13116:
    v_13155 = stack[-1];
    if (v_13155 == nil) goto v_13121;
    else goto v_13122;
v_13121:
    v_13155 = elt(env, 1); // (0)
    stack[-1] = v_13155;
    goto v_13120;
v_13122:
v_13120:
    goto v_13130;
v_13126:
    goto v_13135;
v_13131:
    v_13155 = stack[-1];
    v_13156 = qcar(v_13155);
    goto v_13132;
v_13133:
    v_13155 = stack[0];
    v_13155 = qcar(v_13155);
    goto v_13134;
v_13135:
    goto v_13131;
v_13132:
    goto v_13133;
v_13134:
    v_13155 = (LispObject)(intptr_t)((intptr_t)v_13156 - (intptr_t)v_13155 + TAG_FIXNUM);
    goto v_13127;
v_13128:
    v_13156 = v_13157;
    goto v_13129;
v_13130:
    goto v_13126;
v_13127:
    goto v_13128;
v_13129:
    v_13155 = cons(v_13155, v_13156);
    env = stack[-2];
    v_13157 = v_13155;
    v_13155 = stack[-1];
    v_13155 = qcdr(v_13155);
    stack[-1] = v_13155;
    v_13155 = stack[0];
    v_13155 = qcdr(v_13155);
    stack[0] = v_13155;
    goto v_13112;
v_13111:
    goto v_13151;
v_13147:
    v_13155 = v_13157;
    v_13156 = Lnreverse(nil, v_13155);
    goto v_13148;
v_13149:
    v_13155 = stack[-1];
    goto v_13150;
v_13151:
    goto v_13147;
v_13148:
    goto v_13149;
v_13150:
        return Lnconc(nil, v_13156, v_13155);
    return onevalue(v_13155);
}



// Code for evgradlexcomp

static LispObject CC_evgradlexcomp(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13186, v_13187;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13104,v_13105);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_13105;
    stack[-2] = v_13104;
// end of prologue
v_13109:
    v_13186 = stack[-2];
    if (v_13186 == nil) goto v_13112;
    else goto v_13113;
v_13112:
    v_13186 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13108;
v_13113:
    v_13186 = stack[-1];
    if (v_13186 == nil) goto v_13116;
    else goto v_13117;
v_13116:
    v_13186 = elt(env, 1); // (0)
    stack[-1] = v_13186;
    goto v_13109;
v_13117:
    goto v_13127;
v_13123:
    v_13186 = stack[-2];
    v_13187 = qcar(v_13186);
    goto v_13124;
v_13125:
    v_13186 = stack[-1];
    v_13186 = qcar(v_13186);
    goto v_13126;
v_13127:
    goto v_13123;
v_13124:
    goto v_13125;
v_13126:
    fn = elt(env, 2); // iequal
    v_13186 = (*qfn2(fn))(fn, v_13187, v_13186);
    env = stack[-4];
    if (v_13186 == nil) goto v_13121;
    v_13186 = stack[-2];
    v_13186 = qcdr(v_13186);
    stack[-2] = v_13186;
    v_13186 = stack[-1];
    v_13186 = qcdr(v_13186);
    stack[-1] = v_13186;
    goto v_13109;
v_13121:
    v_13186 = stack[-2];
    fn = elt(env, 3); // evtdeg
    stack[0] = (*qfn1(fn))(fn, v_13186);
    env = stack[-4];
    v_13186 = stack[-1];
    fn = elt(env, 3); // evtdeg
    v_13186 = (*qfn1(fn))(fn, v_13186);
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v_13186;
    goto v_13153;
v_13149:
    v_13187 = stack[-3];
    goto v_13150;
v_13151:
    v_13186 = stack[0];
    goto v_13152;
v_13153:
    goto v_13149;
v_13150:
    goto v_13151;
v_13152:
    fn = elt(env, 2); // iequal
    v_13186 = (*qfn2(fn))(fn, v_13187, v_13186);
    if (v_13186 == nil) goto v_13147;
    goto v_13164;
v_13160:
    v_13186 = stack[-2];
    v_13187 = qcar(v_13186);
    goto v_13161;
v_13162:
    v_13186 = stack[-1];
    v_13186 = qcar(v_13186);
    goto v_13163;
v_13164:
    goto v_13160;
v_13161:
    goto v_13162;
v_13163:
    if (((intptr_t)(v_13187)) > ((intptr_t)(v_13186))) goto v_13158;
    else goto v_13159;
v_13158:
    v_13186 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13157;
v_13159:
    v_13186 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_13157;
    v_13186 = nil;
v_13157:
    goto v_13145;
v_13147:
    goto v_13179;
v_13175:
    v_13187 = stack[-3];
    goto v_13176;
v_13177:
    v_13186 = stack[0];
    goto v_13178;
v_13179:
    goto v_13175;
v_13176:
    goto v_13177;
v_13178:
    if (((intptr_t)(v_13187)) > ((intptr_t)(v_13186))) goto v_13173;
    else goto v_13174;
v_13173:
    v_13186 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13145;
v_13174:
    v_13186 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_13145;
    v_13186 = nil;
v_13145:
    goto v_13108;
    v_13186 = nil;
v_13108:
    return onevalue(v_13186);
}



// Code for wedgek2

static LispObject CC_wedgek2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13335, v_13336, v_13337;
    LispObject fn;
    LispObject v_13106, v_13105, v_13104;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "wedgek2");
    va_start(aa, nargs);
    v_13104 = va_arg(aa, LispObject);
    v_13105 = va_arg(aa, LispObject);
    v_13106 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13106,v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13104,v_13105,v_13106);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-2] = v_13106;
    stack[-3] = v_13105;
    stack[-4] = v_13104;
// end of prologue
v_13110:
    goto v_13123;
v_13119:
    v_13336 = stack[-4];
    goto v_13120;
v_13121:
    v_13335 = stack[-3];
    v_13335 = qcar(v_13335);
    goto v_13122;
v_13123:
    goto v_13119;
v_13120:
    goto v_13121;
v_13122:
    if (v_13336 == v_13335) goto v_13117;
    else goto v_13118;
v_13117:
    goto v_13132;
v_13128:
    v_13336 = stack[-4];
    goto v_13129;
v_13130:
    v_13335 = elt(env, 1); // wedge
    goto v_13131;
v_13132:
    goto v_13128;
v_13129:
    goto v_13130;
v_13131:
    v_13335 = Leqcar(nil, v_13336, v_13335);
    env = stack[-6];
    v_13335 = (v_13335 == nil ? lisp_true : nil);
    goto v_13116;
v_13118:
    v_13335 = nil;
    goto v_13116;
    v_13335 = nil;
v_13116:
    if (v_13335 == nil) goto v_13114;
    v_13335 = stack[-4];
    fn = elt(env, 2); // deg!*form
    v_13335 = (*qfn1(fn))(fn, v_13335);
    env = stack[-6];
    v_13336 = v_13335;
    v_13335 = v_13336;
    v_13335 = integerp(v_13335);
    if (v_13335 == nil) goto v_13148;
    else goto v_13149;
v_13148:
    v_13335 = nil;
    goto v_13147;
v_13149:
    v_13335 = v_13336;
    v_13335 = Loddp(nil, v_13335);
    env = stack[-6];
    goto v_13147;
    v_13335 = nil;
v_13147:
    if (v_13335 == nil) goto v_13142;
    v_13335 = nil;
    goto v_13109;
v_13142:
    goto v_13165;
v_13161:
    goto v_13172;
v_13168:
    v_13336 = stack[-4];
    goto v_13169;
v_13170:
    v_13335 = stack[-3];
    goto v_13171;
v_13172:
    goto v_13168;
v_13169:
    goto v_13170;
v_13171:
    v_13335 = cons(v_13336, v_13335);
    env = stack[-6];
    fn = elt(env, 3); // wedgef
    stack[0] = (*qfn1(fn))(fn, v_13335);
    env = stack[-6];
    goto v_13162;
v_13163:
    v_13335 = stack[-2];
    fn = elt(env, 4); // mksgnsq
    v_13335 = (*qfn1(fn))(fn, v_13335);
    env = stack[-6];
    goto v_13164;
v_13165:
    goto v_13161;
v_13162:
    goto v_13163;
v_13164:
    {
        LispObject v_13344 = stack[0];
        fn = elt(env, 5); // multpfsq
        return (*qfn2(fn))(fn, v_13344, v_13335);
    }
    goto v_13112;
v_13114:
    goto v_13184;
v_13180:
    v_13335 = stack[-3];
    v_13336 = qcar(v_13335);
    goto v_13181;
v_13182:
    v_13335 = elt(env, 1); // wedge
    goto v_13183;
v_13184:
    goto v_13180;
v_13181:
    goto v_13182;
v_13183:
    if (!consp(v_13336)) goto v_13178;
    v_13336 = qcar(v_13336);
    if (v_13336 == v_13335) goto v_13177;
    else goto v_13178;
v_13177:
    v_13335 = stack[-3];
    v_13335 = qcar(v_13335);
    v_13335 = qcdr(v_13335);
    stack[-3] = v_13335;
    goto v_13110;
v_13178:
    goto v_13198;
v_13194:
    v_13336 = stack[-4];
    goto v_13195;
v_13196:
    v_13335 = elt(env, 1); // wedge
    goto v_13197;
v_13198:
    goto v_13194;
v_13195:
    goto v_13196;
v_13197:
    if (!consp(v_13336)) goto v_13192;
    v_13336 = qcar(v_13336);
    if (v_13336 == v_13335) goto v_13191;
    else goto v_13192;
v_13191:
    goto v_13206;
v_13202:
    goto v_13212;
v_13208:
    v_13335 = stack[-4];
    v_13336 = qcdr(v_13335);
    goto v_13209;
v_13210:
    v_13335 = stack[-3];
    goto v_13211;
v_13212:
    goto v_13208;
v_13209:
    goto v_13210;
v_13211:
    fn = elt(env, 6); // wedgewedge
    stack[0] = (*qfn2(fn))(fn, v_13336, v_13335);
    env = stack[-6];
    goto v_13203;
v_13204:
    v_13335 = stack[-2];
    fn = elt(env, 4); // mksgnsq
    v_13335 = (*qfn1(fn))(fn, v_13335);
    env = stack[-6];
    goto v_13205;
v_13206:
    goto v_13202;
v_13203:
    goto v_13204;
v_13205:
    {
        LispObject v_13345 = stack[0];
        fn = elt(env, 5); // multpfsq
        return (*qfn2(fn))(fn, v_13345, v_13335);
    }
v_13192:
    goto v_13225;
v_13221:
    v_13336 = stack[-4];
    goto v_13222;
v_13223:
    v_13335 = stack[-3];
    v_13335 = qcar(v_13335);
    goto v_13224;
v_13225:
    goto v_13221;
v_13222:
    goto v_13223;
v_13224:
    fn = elt(env, 7); // worderp
    v_13335 = (*qfn2(fn))(fn, v_13336, v_13335);
    env = stack[-6];
    if (v_13335 == nil) goto v_13219;
    goto v_13234;
v_13230:
    goto v_13241;
v_13237:
    v_13336 = stack[-4];
    goto v_13238;
v_13239:
    v_13335 = stack[-3];
    goto v_13240;
v_13241:
    goto v_13237;
v_13238:
    goto v_13239;
v_13240:
    v_13335 = cons(v_13336, v_13335);
    env = stack[-6];
    fn = elt(env, 3); // wedgef
    stack[0] = (*qfn1(fn))(fn, v_13335);
    env = stack[-6];
    goto v_13231;
v_13232:
    v_13335 = stack[-2];
    fn = elt(env, 4); // mksgnsq
    v_13335 = (*qfn1(fn))(fn, v_13335);
    env = stack[-6];
    goto v_13233;
v_13234:
    goto v_13230;
v_13231:
    goto v_13232;
v_13233:
    {
        LispObject v_13346 = stack[0];
        fn = elt(env, 5); // multpfsq
        return (*qfn2(fn))(fn, v_13346, v_13335);
    }
v_13219:
    v_13335 = stack[-3];
    v_13335 = qcdr(v_13335);
    if (v_13335 == nil) goto v_13247;
    goto v_13255;
v_13251:
    goto v_13264;
v_13258:
    v_13335 = stack[-3];
    v_13337 = qcar(v_13335);
    goto v_13259;
v_13260:
    v_13336 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13261;
v_13262:
    v_13335 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13263;
v_13264:
    goto v_13258;
v_13259:
    goto v_13260;
v_13261:
    goto v_13262;
v_13263:
    v_13335 = list2star(v_13337, v_13336, v_13335);
    env = stack[-6];
    stack[-5] = ncons(v_13335);
    env = stack[-6];
    goto v_13252;
v_13253:
    goto v_13276;
v_13270:
    stack[-1] = stack[-4];
    goto v_13271;
v_13272:
    v_13335 = stack[-3];
    stack[0] = qcdr(v_13335);
    goto v_13273;
v_13274:
    goto v_13285;
v_13281:
    goto v_13282;
v_13283:
    goto v_13292;
v_13288:
    v_13335 = stack[-4];
    fn = elt(env, 2); // deg!*form
    stack[-4] = (*qfn1(fn))(fn, v_13335);
    env = stack[-6];
    goto v_13289;
v_13290:
    v_13335 = stack[-3];
    v_13335 = qcar(v_13335);
    fn = elt(env, 2); // deg!*form
    v_13335 = (*qfn1(fn))(fn, v_13335);
    env = stack[-6];
    goto v_13291;
v_13292:
    goto v_13288;
v_13289:
    goto v_13290;
v_13291:
    fn = elt(env, 8); // multf
    v_13335 = (*qfn2(fn))(fn, stack[-4], v_13335);
    env = stack[-6];
    goto v_13284;
v_13285:
    goto v_13281;
v_13282:
    goto v_13283;
v_13284:
    fn = elt(env, 9); // addf
    v_13335 = (*qfn2(fn))(fn, stack[-2], v_13335);
    env = stack[-6];
    goto v_13275;
v_13276:
    goto v_13270;
v_13271:
    goto v_13272;
v_13273:
    goto v_13274;
v_13275:
    v_13335 = CC_wedgek2(elt(env, 0), 3, stack[-1], stack[0], v_13335);
    env = stack[-6];
    goto v_13254;
v_13255:
    goto v_13251;
v_13252:
    goto v_13253;
v_13254:
    {
        LispObject v_13347 = stack[-5];
        fn = elt(env, 10); // wedgepf2
        return (*qfn2(fn))(fn, v_13347, v_13335);
    }
v_13247:
    goto v_13305;
v_13301:
    goto v_13312;
v_13308:
    v_13335 = stack[-3];
    v_13336 = qcar(v_13335);
    goto v_13309;
v_13310:
    v_13335 = stack[-4];
    goto v_13311;
v_13312:
    goto v_13308;
v_13309:
    goto v_13310;
v_13311:
    v_13335 = list2(v_13336, v_13335);
    env = stack[-6];
    fn = elt(env, 3); // wedgef
    stack[0] = (*qfn1(fn))(fn, v_13335);
    env = stack[-6];
    goto v_13302;
v_13303:
    goto v_13322;
v_13318:
    stack[-1] = stack[-2];
    goto v_13319;
v_13320:
    goto v_13329;
v_13325:
    v_13335 = stack[-4];
    fn = elt(env, 2); // deg!*form
    stack[-2] = (*qfn1(fn))(fn, v_13335);
    env = stack[-6];
    goto v_13326;
v_13327:
    v_13335 = stack[-3];
    v_13335 = qcar(v_13335);
    fn = elt(env, 2); // deg!*form
    v_13335 = (*qfn1(fn))(fn, v_13335);
    env = stack[-6];
    goto v_13328;
v_13329:
    goto v_13325;
v_13326:
    goto v_13327;
v_13328:
    fn = elt(env, 8); // multf
    v_13335 = (*qfn2(fn))(fn, stack[-2], v_13335);
    env = stack[-6];
    goto v_13321;
v_13322:
    goto v_13318;
v_13319:
    goto v_13320;
v_13321:
    fn = elt(env, 9); // addf
    v_13335 = (*qfn2(fn))(fn, stack[-1], v_13335);
    env = stack[-6];
    fn = elt(env, 4); // mksgnsq
    v_13335 = (*qfn1(fn))(fn, v_13335);
    env = stack[-6];
    goto v_13304;
v_13305:
    goto v_13301;
v_13302:
    goto v_13303;
v_13304:
    {
        LispObject v_13348 = stack[0];
        fn = elt(env, 5); // multpfsq
        return (*qfn2(fn))(fn, v_13348, v_13335);
    }
v_13112:
    v_13335 = nil;
v_13109:
    return onevalue(v_13335);
}



// Code for physop2sq

static LispObject CC_physop2sq(LispObject env,
                         LispObject v_13104)
{
    env = qenv(env);
    LispObject v_13267, v_13268;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13104);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13104;
// end of prologue
v_13103:
    v_13267 = stack[0];
    fn = elt(env, 3); // physopp
    v_13267 = (*qfn1(fn))(fn, v_13267);
    env = stack[-2];
    if (v_13267 == nil) goto v_13112;
    v_13267 = stack[0];
    if (!symbolp(v_13267)) v_13267 = nil;
    else { v_13267 = qfastgets(v_13267);
           if (v_13267 != nil) { v_13267 = elt(v_13267, 46); // rvalue
#ifdef RECORD_GET
             if (v_13267 != SPID_NOPROP)
                record_get(elt(fastget_names, 46), 1);
             else record_get(elt(fastget_names, 46), 0),
                v_13267 = nil; }
           else record_get(elt(fastget_names, 46), 0); }
#else
             if (v_13267 == SPID_NOPROP) v_13267 = nil; }}
#endif
    stack[-1] = v_13267;
    if (v_13267 == nil) goto v_13118;
    v_13267 = stack[-1];
    stack[0] = v_13267;
    goto v_13103;
v_13118:
    v_13267 = stack[0];
    if (symbolp(v_13267)) goto v_13123;
    else goto v_13124;
v_13123:
    goto v_13131;
v_13127:
    goto v_13138;
v_13134:
    goto v_13144;
v_13140:
    v_13268 = stack[0];
    goto v_13141;
v_13142:
    v_13267 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13143;
v_13144:
    goto v_13140;
v_13141:
    goto v_13142;
v_13143:
    fn = elt(env, 4); // to
    v_13268 = (*qfn2(fn))(fn, v_13268, v_13267);
    env = stack[-2];
    goto v_13135;
v_13136:
    v_13267 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13137;
v_13138:
    goto v_13134;
v_13135:
    goto v_13136;
v_13137:
    v_13267 = cons(v_13268, v_13267);
    env = stack[-2];
    v_13268 = ncons(v_13267);
    goto v_13128;
v_13129:
    v_13267 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13130;
v_13131:
    goto v_13127;
v_13128:
    goto v_13129;
v_13130:
    return cons(v_13268, v_13267);
v_13124:
    goto v_13156;
v_13152:
    v_13267 = stack[0];
    v_13268 = qcar(v_13267);
    goto v_13153;
v_13154:
    v_13267 = elt(env, 1); // psimpfn
    goto v_13155;
v_13156:
    goto v_13152;
v_13153:
    goto v_13154;
v_13155:
    v_13267 = get(v_13268, v_13267);
    env = stack[-2];
    stack[-1] = v_13267;
    if (v_13267 == nil) goto v_13150;
    goto v_13170;
v_13166:
    v_13268 = stack[-1];
    goto v_13167;
v_13168:
    v_13267 = stack[0];
    goto v_13169;
v_13170:
    goto v_13166;
v_13167:
    goto v_13168;
v_13169:
    v_13267 = Lapply1(nil, v_13268, v_13267);
    env = stack[-2];
    stack[-1] = v_13267;
    fn = elt(env, 3); // physopp
    v_13267 = (*qfn1(fn))(fn, v_13267);
    env = stack[-2];
    if (v_13267 == nil) goto v_13163;
    goto v_13178;
v_13174:
    goto v_13185;
v_13181:
    goto v_13191;
v_13187:
    v_13268 = stack[-1];
    goto v_13188;
v_13189:
    v_13267 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13190;
v_13191:
    goto v_13187;
v_13188:
    goto v_13189;
v_13190:
    fn = elt(env, 4); // to
    v_13268 = (*qfn2(fn))(fn, v_13268, v_13267);
    env = stack[-2];
    goto v_13182;
v_13183:
    v_13267 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13184;
v_13185:
    goto v_13181;
v_13182:
    goto v_13183;
v_13184:
    v_13267 = cons(v_13268, v_13267);
    env = stack[-2];
    v_13268 = ncons(v_13267);
    goto v_13175;
v_13176:
    v_13267 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13177;
v_13178:
    goto v_13174;
v_13175:
    goto v_13176;
v_13177:
    return cons(v_13268, v_13267);
v_13163:
    v_13267 = stack[-1];
    fn = elt(env, 5); // physopsm!*
    v_13267 = (*qfn1(fn))(fn, v_13267);
    v_13267 = qcdr(v_13267);
    v_13267 = qcar(v_13267);
    goto v_13161;
    v_13267 = nil;
v_13161:
    goto v_13116;
v_13150:
    v_13267 = stack[0];
    v_13267 = qcar(v_13267);
    if (!symbolp(v_13267)) v_13267 = nil;
    else { v_13267 = qfastgets(v_13267);
           if (v_13267 != nil) { v_13267 = elt(v_13267, 9); // opmtch
#ifdef RECORD_GET
             if (v_13267 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_13267 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_13267 == SPID_NOPROP) v_13267 = nil; }}
#endif
    if (v_13267 == nil) goto v_13203;
    v_13267 = stack[0];
    fn = elt(env, 6); // opmtch!*
    v_13267 = (*qfn1(fn))(fn, v_13267);
    env = stack[-2];
    stack[-1] = v_13267;
    if (v_13267 == nil) goto v_13203;
    v_13267 = stack[-1];
    stack[0] = v_13267;
    goto v_13103;
v_13203:
    goto v_13220;
v_13216:
    goto v_13227;
v_13223:
    goto v_13233;
v_13229:
    v_13268 = stack[0];
    goto v_13230;
v_13231:
    v_13267 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13232;
v_13233:
    goto v_13229;
v_13230:
    goto v_13231;
v_13232:
    fn = elt(env, 4); // to
    v_13268 = (*qfn2(fn))(fn, v_13268, v_13267);
    env = stack[-2];
    goto v_13224;
v_13225:
    v_13267 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13226;
v_13227:
    goto v_13223;
v_13224:
    goto v_13225;
v_13226:
    v_13267 = cons(v_13268, v_13267);
    env = stack[-2];
    v_13268 = ncons(v_13267);
    goto v_13217;
v_13218:
    v_13267 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13219;
v_13220:
    goto v_13216;
v_13217:
    goto v_13218;
v_13219:
    return cons(v_13268, v_13267);
    v_13267 = nil;
v_13116:
    goto v_13110;
v_13112:
    v_13267 = stack[0];
    if (!consp(v_13267)) goto v_13238;
    else goto v_13239;
v_13238:
    v_13267 = stack[0];
    {
        fn = elt(env, 7); // simp
        return (*qfn1(fn))(fn, v_13267);
    }
v_13239:
    goto v_13249;
v_13245:
    v_13267 = stack[0];
    v_13268 = qcar(v_13267);
    goto v_13246;
v_13247:
    v_13267 = elt(env, 2); // !*sq
    goto v_13248;
v_13249:
    goto v_13245;
v_13246:
    goto v_13247;
v_13248:
    if (v_13268 == v_13267) goto v_13243;
    else goto v_13244;
v_13243:
    v_13267 = stack[0];
    v_13267 = qcdr(v_13267);
    v_13267 = qcar(v_13267);
    goto v_13110;
v_13244:
    v_13267 = stack[0];
    fn = elt(env, 8); // getphystype
    v_13267 = (*qfn1(fn))(fn, v_13267);
    env = stack[-2];
    if (v_13267 == nil) goto v_13256;
    else goto v_13257;
v_13256:
    v_13267 = stack[0];
    {
        fn = elt(env, 7); // simp
        return (*qfn1(fn))(fn, v_13267);
    }
v_13257:
    v_13267 = stack[0];
    fn = elt(env, 5); // physopsm!*
    v_13267 = (*qfn1(fn))(fn, v_13267);
    env = stack[-2];
    stack[0] = v_13267;
    goto v_13103;
    v_13267 = nil;
v_13110:
    return onevalue(v_13267);
}



// Code for def_edge

static LispObject CC_def_edge(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13136, v_13137, v_13138, v_13139;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13138 = v_13105;
    v_13136 = v_13104;
// end of prologue
    v_13136 = qcdr(v_13136);
    v_13136 = qcar(v_13136);
    v_13139 = v_13136;
    goto v_13119;
v_13115:
    v_13136 = v_13139;
    v_13137 = qcar(v_13136);
    goto v_13116;
v_13117:
    v_13136 = v_13138;
    goto v_13118;
v_13119:
    goto v_13115;
v_13116:
    goto v_13117;
v_13118:
    v_13136 = Lassoc(nil, v_13137, v_13136);
    if (v_13136 == nil) goto v_13113;
    else goto v_13114;
v_13113:
    v_13136 = nil;
    goto v_13112;
v_13114:
    goto v_13131;
v_13127:
    v_13136 = v_13139;
    v_13136 = qcdr(v_13136);
    goto v_13128;
v_13129:
    v_13137 = v_13138;
    goto v_13130;
v_13131:
    goto v_13127;
v_13128:
    goto v_13129;
v_13130:
    v_13136 = Lassoc(nil, v_13136, v_13137);
    goto v_13112;
    v_13136 = nil;
v_13112:
    return onevalue(v_13136);
}



// Code for pairxvars

static LispObject CC_pairxvars(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13250, v_13251, v_13252;
    LispObject fn;
    LispObject v_13107, v_13106, v_13105, v_13104;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "pairxvars");
    va_start(aa, nargs);
    v_13104 = va_arg(aa, LispObject);
    v_13105 = va_arg(aa, LispObject);
    v_13106 = va_arg(aa, LispObject);
    v_13107 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_13107,v_13106,v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_13104,v_13105,v_13106,v_13107);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_13107;
    stack[-2] = v_13106;
    stack[-3] = v_13105;
    stack[-4] = v_13104;
// end of prologue
    stack[-5] = nil;
v_13115:
    v_13250 = stack[-4];
    if (v_13250 == nil) goto v_13118;
    else goto v_13119;
v_13118:
    goto v_13114;
v_13119:
    goto v_13130;
v_13126:
    v_13250 = stack[-4];
    v_13251 = qcar(v_13250);
    goto v_13127;
v_13128:
    v_13250 = stack[-3];
    goto v_13129;
v_13130:
    goto v_13126;
v_13127:
    goto v_13128;
v_13129:
    v_13250 = Latsoc(nil, v_13251, v_13250);
    stack[0] = v_13250;
    if (v_13250 == nil) goto v_13125;
    goto v_13140;
v_13136:
    v_13251 = stack[0];
    goto v_13137;
v_13138:
    v_13250 = stack[-3];
    goto v_13139;
v_13140:
    goto v_13136;
v_13137:
    goto v_13138;
v_13139:
    v_13250 = Ldelete(nil, v_13251, v_13250);
    env = stack[-6];
    stack[-3] = v_13250;
    goto v_13151;
v_13147:
    v_13250 = stack[0];
    v_13251 = qcdr(v_13250);
    goto v_13148;
v_13149:
    v_13250 = elt(env, 1); // scalar
    goto v_13150;
v_13151:
    goto v_13147;
v_13148:
    goto v_13149;
v_13150:
    if (v_13251 == v_13250) goto v_13146;
    goto v_13162;
v_13156:
    v_13250 = stack[-4];
    v_13252 = qcar(v_13250);
    goto v_13157;
v_13158:
    v_13250 = stack[0];
    v_13251 = qcdr(v_13250);
    goto v_13159;
v_13160:
    v_13250 = stack[-5];
    goto v_13161;
v_13162:
    goto v_13156;
v_13157:
    goto v_13158;
v_13159:
    goto v_13160;
v_13161:
    v_13250 = acons(v_13252, v_13251, v_13250);
    env = stack[-6];
    stack[-5] = v_13250;
    goto v_13144;
v_13146:
    goto v_13177;
v_13171:
    v_13250 = stack[-4];
    v_13252 = qcar(v_13250);
    goto v_13172;
v_13173:
    v_13251 = stack[-1];
    goto v_13174;
v_13175:
    v_13250 = stack[-5];
    goto v_13176;
v_13177:
    goto v_13171;
v_13172:
    goto v_13173;
v_13174:
    goto v_13175;
v_13176:
    v_13250 = acons(v_13252, v_13251, v_13250);
    env = stack[-6];
    stack[-5] = v_13250;
    goto v_13144;
v_13144:
    goto v_13123;
v_13125:
    v_13250 = stack[-4];
    v_13250 = qcar(v_13250);
    if (symbolp(v_13250)) goto v_13187;
    v_13250 = lisp_true;
    goto v_13185;
v_13187:
    v_13250 = stack[-4];
    v_13250 = qcar(v_13250);
    if (!symbolp(v_13250)) v_13250 = nil;
    else { v_13250 = qfastgets(v_13250);
           if (v_13250 != nil) { v_13250 = elt(v_13250, 23); // infix
#ifdef RECORD_GET
             if (v_13250 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_13250 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_13250 == SPID_NOPROP) v_13250 = nil; }}
#endif
    if (v_13250 == nil) goto v_13195;
    else goto v_13194;
v_13195:
    v_13250 = stack[-4];
    v_13250 = qcar(v_13250);
    if (!symbolp(v_13250)) v_13250 = nil;
    else { v_13250 = qfastgets(v_13250);
           if (v_13250 != nil) { v_13250 = elt(v_13250, 36); // stat
#ifdef RECORD_GET
             if (v_13250 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v_13250 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v_13250 == SPID_NOPROP) v_13250 = nil; }}
#endif
v_13194:
    goto v_13185;
    v_13250 = nil;
v_13185:
    if (v_13250 == nil) goto v_13183;
    goto v_13207;
v_13203:
    goto v_13213;
v_13209:
    v_13251 = elt(env, 2); // "Invalid parameter:"
    goto v_13210;
v_13211:
    v_13250 = stack[-4];
    v_13250 = qcar(v_13250);
    goto v_13212;
v_13213:
    goto v_13209;
v_13210:
    goto v_13211;
v_13212:
    v_13251 = list2(v_13251, v_13250);
    env = stack[-6];
    goto v_13204;
v_13205:
    v_13250 = nil;
    goto v_13206;
v_13207:
    goto v_13203;
v_13204:
    goto v_13205;
v_13206:
    fn = elt(env, 3); // symerr
    v_13250 = (*qfn2(fn))(fn, v_13251, v_13250);
    env = stack[-6];
    goto v_13123;
v_13183:
    goto v_13227;
v_13221:
    v_13250 = stack[-4];
    v_13252 = qcar(v_13250);
    goto v_13222;
v_13223:
    v_13251 = stack[-1];
    goto v_13224;
v_13225:
    v_13250 = stack[-5];
    goto v_13226;
v_13227:
    goto v_13221;
v_13222:
    goto v_13223;
v_13224:
    goto v_13225;
v_13226:
    v_13250 = acons(v_13252, v_13251, v_13250);
    env = stack[-6];
    stack[-5] = v_13250;
    goto v_13123;
v_13123:
    v_13250 = stack[-4];
    v_13250 = qcdr(v_13250);
    stack[-4] = v_13250;
    goto v_13115;
v_13114:
    goto v_13239;
v_13235:
    goto v_13245;
v_13241:
    v_13250 = stack[-5];
    fn = elt(env, 4); // reversip!*
    v_13251 = (*qfn1(fn))(fn, v_13250);
    env = stack[-6];
    goto v_13242;
v_13243:
    v_13250 = stack[-2];
    goto v_13244;
v_13245:
    goto v_13241;
v_13242:
    goto v_13243;
v_13244:
    v_13251 = Lappend(nil, v_13251, v_13250);
    goto v_13236;
v_13237:
    v_13250 = stack[-3];
    goto v_13238;
v_13239:
    goto v_13235;
v_13236:
    goto v_13237;
v_13238:
    return cons(v_13251, v_13250);
    return onevalue(v_13250);
}



// Code for setel1

static LispObject CC_setel1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13192, v_13193, v_13194;
    LispObject fn;
    LispObject v_13107, v_13106, v_13105, v_13104;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "setel1");
    va_start(aa, nargs);
    v_13104 = va_arg(aa, LispObject);
    v_13105 = va_arg(aa, LispObject);
    v_13106 = va_arg(aa, LispObject);
    v_13107 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_13107,v_13106,v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_13104,v_13105,v_13106,v_13107);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_13107;
    stack[-1] = v_13106;
    stack[-2] = v_13105;
    stack[-3] = v_13104;
// end of prologue
v_13111:
    v_13192 = stack[-2];
    v_13192 = qcar(v_13192);
    v_13192 = integerp(v_13192);
    if (v_13192 == nil) goto v_13114;
    else goto v_13115;
v_13114:
    goto v_13124;
v_13120:
    v_13192 = stack[-2];
    v_13193 = qcar(v_13192);
    goto v_13121;
v_13122:
    v_13192 = elt(env, 1); // "array index"
    goto v_13123;
v_13124:
    goto v_13120;
v_13121:
    goto v_13122;
v_13123:
    {
        fn = elt(env, 4); // typerr
        return (*qfn2(fn))(fn, v_13193, v_13192);
    }
v_13115:
    goto v_13136;
v_13132:
    v_13192 = stack[-2];
    v_13193 = qcar(v_13192);
    goto v_13133;
v_13134:
    v_13192 = stack[0];
    v_13192 = qcar(v_13192);
    goto v_13135;
v_13136:
    goto v_13132;
v_13133:
    goto v_13134;
v_13135:
    v_13192 = (LispObject)geq2(v_13193, v_13192);
    v_13192 = v_13192 ? lisp_true : nil;
    env = stack[-4];
    if (v_13192 == nil) goto v_13130;
    else goto v_13128;
v_13130:
    goto v_13147;
v_13143:
    v_13192 = stack[-2];
    v_13193 = qcar(v_13192);
    goto v_13144;
v_13145:
    v_13192 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13146;
v_13147:
    goto v_13143;
v_13144:
    goto v_13145;
v_13146:
    v_13192 = (LispObject)lessp2(v_13193, v_13192);
    v_13192 = v_13192 ? lisp_true : nil;
    env = stack[-4];
    if (v_13192 == nil) goto v_13141;
    else goto v_13128;
v_13141:
    goto v_13129;
v_13128:
    goto v_13158;
v_13152:
    v_13194 = elt(env, 2); // rlisp
    goto v_13153;
v_13154:
    v_13193 = (LispObject)368+TAG_FIXNUM; // 23
    goto v_13155;
v_13156:
    v_13192 = elt(env, 3); // "Array out of bounds"
    goto v_13157;
v_13158:
    goto v_13152;
v_13153:
    goto v_13154;
v_13155:
    goto v_13156;
v_13157:
    {
        fn = elt(env, 5); // rerror
        return (*qfnn(fn))(fn, 3, v_13194, v_13193, v_13192);
    }
v_13129:
    v_13192 = stack[-2];
    v_13192 = qcdr(v_13192);
    if (v_13192 == nil) goto v_13162;
    else goto v_13163;
v_13162:
    goto v_13172;
v_13166:
    v_13194 = stack[-3];
    goto v_13167;
v_13168:
    v_13192 = stack[-2];
    v_13193 = qcar(v_13192);
    goto v_13169;
v_13170:
    v_13192 = stack[-1];
    goto v_13171;
v_13172:
    goto v_13166;
v_13167:
    goto v_13168;
v_13169:
    goto v_13170;
v_13171:
    *(LispObject *)((char *)v_13194 + (CELL-TAG_VECTOR) + (((intptr_t)v_13193-TAG_FIXNUM)/(16/CELL))) = v_13192;
    goto v_13110;
v_13163:
    goto v_13183;
v_13179:
    v_13193 = stack[-3];
    goto v_13180;
v_13181:
    v_13192 = stack[-2];
    v_13192 = qcar(v_13192);
    goto v_13182;
v_13183:
    goto v_13179;
v_13180:
    goto v_13181;
v_13182:
    v_13192 = *(LispObject *)((char *)v_13193 + (CELL-TAG_VECTOR) + (((intptr_t)v_13192-TAG_FIXNUM)/(16/CELL)));
    stack[-3] = v_13192;
    v_13192 = stack[-2];
    v_13192 = qcdr(v_13192);
    stack[-2] = v_13192;
    v_13192 = stack[0];
    v_13192 = qcdr(v_13192);
    stack[0] = v_13192;
    goto v_13111;
    v_13192 = nil;
v_13110:
    return onevalue(v_13192);
}



// Code for simp!-prop!-order

static LispObject CC_simpKpropKorder(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13148, v_13149, v_13150, v_13151;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13149 = v_13105;
    v_13150 = v_13104;
// end of prologue
v_13109:
    v_13148 = v_13150;
    if (v_13148 == nil) goto v_13112;
    else goto v_13113;
v_13112:
    v_13148 = nil;
    goto v_13108;
v_13113:
    goto v_13122;
v_13118:
    v_13148 = v_13150;
    v_13148 = qcar(v_13148);
    v_13151 = qcar(v_13148);
    goto v_13119;
v_13120:
    v_13148 = v_13149;
    v_13148 = qcar(v_13148);
    v_13148 = qcar(v_13148);
    goto v_13121;
v_13122:
    goto v_13118;
v_13119:
    goto v_13120;
v_13121:
    if (equal(v_13151, v_13148)) goto v_13116;
    else goto v_13117;
v_13116:
    v_13148 = v_13150;
    v_13148 = qcdr(v_13148);
    v_13150 = v_13148;
    v_13148 = v_13149;
    v_13148 = qcdr(v_13148);
    v_13149 = v_13148;
    goto v_13109;
v_13117:
    goto v_13139;
v_13135:
    v_13148 = v_13150;
    v_13148 = qcar(v_13148);
    v_13148 = qcar(v_13148);
    goto v_13136;
v_13137:
    v_13149 = elt(env, 1); // prop!*
    goto v_13138;
v_13139:
    goto v_13135;
v_13136:
    goto v_13137;
v_13138:
    if (v_13148 == v_13149) goto v_13133;
    else goto v_13134;
v_13133:
    v_13148 = lisp_true;
    goto v_13108;
v_13134:
    v_13148 = nil;
    goto v_13108;
    v_13148 = nil;
v_13108:
    return onevalue(v_13148);
}



// Code for readprogn

static LispObject CC_readprogn(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13144, v_13145;
    LispObject fn;
    argcheck(nargs, 0, "readprogn");
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
    v_13144 = elt(env, 1); // group
    fn = elt(env, 5); // xread
    v_13144 = (*qfn1(fn))(fn, v_13144);
    env = stack[-1];
    v_13144 = ncons(v_13144);
    env = stack[-1];
    stack[0] = v_13144;
v_13113:
    goto v_13122;
v_13118:
    v_13145 = qvalue(elt(env, 2)); // cursym!*
    goto v_13119;
v_13120:
    v_13144 = elt(env, 3); // !*rsqbkt!*
    goto v_13121;
v_13122:
    goto v_13118;
v_13119:
    goto v_13120;
v_13121:
    if (v_13145 == v_13144) goto v_13116;
    else goto v_13117;
v_13116:
    goto v_13112;
v_13117:
    goto v_13131;
v_13127:
    goto v_13128;
v_13129:
    v_13144 = elt(env, 1); // group
    fn = elt(env, 5); // xread
    v_13144 = (*qfn1(fn))(fn, v_13144);
    env = stack[-1];
    goto v_13130;
v_13131:
    goto v_13127;
v_13128:
    goto v_13129;
v_13130:
    fn = elt(env, 6); // aconc!*
    v_13144 = (*qfn2(fn))(fn, stack[0], v_13144);
    env = stack[-1];
    stack[0] = v_13144;
    goto v_13113;
v_13112:
    fn = elt(env, 7); // scan
    v_13144 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    goto v_13141;
v_13137:
    v_13145 = elt(env, 4); // progn
    goto v_13138;
v_13139:
    v_13144 = stack[0];
    goto v_13140;
v_13141:
    goto v_13137;
v_13138:
    goto v_13139;
v_13140:
    return cons(v_13145, v_13144);
    return onevalue(v_13144);
}



// Code for rl_atnum

static LispObject CC_rl_atnum(LispObject env,
                         LispObject v_13104)
{
    env = qenv(env);
    LispObject v_13115;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13104);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_13115 = v_13104;
// end of prologue
    goto v_13111;
v_13107:
    stack[0] = qvalue(elt(env, 1)); // rl_atnum!*
    goto v_13108;
v_13109:
    v_13115 = ncons(v_13115);
    env = stack[-1];
    goto v_13110;
v_13111:
    goto v_13107;
v_13108:
    goto v_13109;
v_13110:
    {
        LispObject v_13117 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_13117, v_13115);
    }
}



// Code for ofsf_subf

static LispObject CC_ofsf_subf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13234, v_13235, v_13236;
    LispObject fn;
    LispObject v_13106, v_13105, v_13104;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_subf");
    va_start(aa, nargs);
    v_13104 = va_arg(aa, LispObject);
    v_13105 = va_arg(aa, LispObject);
    v_13106 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13106,v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13104,v_13105,v_13106);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_13106;
    stack[-1] = v_13105;
    stack[-2] = v_13104;
// end of prologue
    v_13234 = stack[-2];
    if (!consp(v_13234)) goto v_13117;
    else goto v_13118;
v_13117:
    v_13234 = lisp_true;
    goto v_13116;
v_13118:
    v_13234 = stack[-2];
    v_13234 = qcar(v_13234);
    v_13234 = (consp(v_13234) ? nil : lisp_true);
    goto v_13116;
    v_13234 = nil;
v_13116:
    if (v_13234 == nil) goto v_13114;
    goto v_13131;
v_13127:
    v_13235 = stack[-2];
    goto v_13128;
v_13129:
    v_13234 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13130;
v_13131:
    goto v_13127;
v_13128:
    goto v_13129;
v_13130:
    return cons(v_13235, v_13234);
v_13114:
    goto v_13141;
v_13135:
    v_13234 = stack[-2];
    v_13236 = qcdr(v_13234);
    goto v_13136;
v_13137:
    v_13235 = stack[-1];
    goto v_13138;
v_13139:
    v_13234 = stack[0];
    goto v_13140;
v_13141:
    goto v_13135;
v_13136:
    goto v_13137;
v_13138:
    goto v_13139;
v_13140:
    v_13234 = CC_ofsf_subf(elt(env, 0), 3, v_13236, v_13235, v_13234);
    env = stack[-4];
    stack[-3] = v_13234;
    goto v_13154;
v_13150:
    v_13234 = stack[-2];
    v_13234 = qcar(v_13234);
    v_13234 = qcar(v_13234);
    v_13235 = qcar(v_13234);
    goto v_13151;
v_13152:
    v_13234 = stack[-1];
    goto v_13153;
v_13154:
    goto v_13150;
v_13151:
    goto v_13152;
v_13153:
    if (v_13235 == v_13234) goto v_13148;
    else goto v_13149;
v_13148:
    goto v_13165;
v_13161:
    goto v_13171;
v_13167:
    goto v_13177;
v_13173:
    v_13234 = stack[-2];
    v_13234 = qcar(v_13234);
    v_13235 = qcdr(v_13234);
    goto v_13174;
v_13175:
    v_13234 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13176;
v_13177:
    goto v_13173;
v_13174:
    goto v_13175;
v_13176:
    stack[-1] = cons(v_13235, v_13234);
    env = stack[-4];
    goto v_13168;
v_13169:
    goto v_13187;
v_13183:
    v_13235 = stack[0];
    goto v_13184;
v_13185:
    v_13234 = stack[-2];
    v_13234 = qcar(v_13234);
    v_13234 = qcar(v_13234);
    v_13234 = qcdr(v_13234);
    goto v_13186;
v_13187:
    goto v_13183;
v_13184:
    goto v_13185;
v_13186:
    fn = elt(env, 1); // exptsq
    v_13234 = (*qfn2(fn))(fn, v_13235, v_13234);
    env = stack[-4];
    goto v_13170;
v_13171:
    goto v_13167;
v_13168:
    goto v_13169;
v_13170:
    fn = elt(env, 2); // multsq
    v_13235 = (*qfn2(fn))(fn, stack[-1], v_13234);
    env = stack[-4];
    goto v_13162;
v_13163:
    v_13234 = stack[-3];
    goto v_13164;
v_13165:
    goto v_13161;
v_13162:
    goto v_13163;
v_13164:
    {
        fn = elt(env, 3); // addsq
        return (*qfn2(fn))(fn, v_13235, v_13234);
    }
v_13149:
    goto v_13199;
v_13195:
    goto v_13205;
v_13201:
    goto v_13213;
v_13207:
    v_13234 = stack[-2];
    v_13234 = qcar(v_13234);
    v_13236 = qcdr(v_13234);
    goto v_13208;
v_13209:
    v_13235 = stack[-1];
    goto v_13210;
v_13211:
    v_13234 = stack[0];
    goto v_13212;
v_13213:
    goto v_13207;
v_13208:
    goto v_13209;
v_13210:
    goto v_13211;
v_13212:
    stack[0] = CC_ofsf_subf(elt(env, 0), 3, v_13236, v_13235, v_13234);
    env = stack[-4];
    goto v_13202;
v_13203:
    goto v_13224;
v_13220:
    v_13234 = stack[-2];
    v_13234 = qcar(v_13234);
    v_13234 = qcar(v_13234);
    v_13235 = qcar(v_13234);
    goto v_13221;
v_13222:
    v_13234 = stack[-2];
    v_13234 = qcar(v_13234);
    v_13234 = qcar(v_13234);
    v_13234 = qcdr(v_13234);
    goto v_13223;
v_13224:
    goto v_13220;
v_13221:
    goto v_13222;
v_13223:
    fn = elt(env, 4); // ofsf_pow2q
    v_13234 = (*qfn2(fn))(fn, v_13235, v_13234);
    env = stack[-4];
    goto v_13204;
v_13205:
    goto v_13201;
v_13202:
    goto v_13203;
v_13204:
    fn = elt(env, 2); // multsq
    v_13235 = (*qfn2(fn))(fn, stack[0], v_13234);
    env = stack[-4];
    goto v_13196;
v_13197:
    v_13234 = stack[-3];
    goto v_13198;
v_13199:
    goto v_13195;
v_13196:
    goto v_13197;
v_13198:
    {
        fn = elt(env, 3); // addsq
        return (*qfn2(fn))(fn, v_13235, v_13234);
    }
    return onevalue(v_13234);
}



// Code for squared!+matrix!+p

static LispObject CC_squaredLmatrixLp(LispObject env,
                         LispObject v_13104)
{
    env = qenv(env);
    LispObject v_13126;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13104);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13104;
// end of prologue
    v_13126 = stack[0];
    fn = elt(env, 1); // matrix!+p
    v_13126 = (*qfn1(fn))(fn, v_13126);
    env = stack[-2];
    if (v_13126 == nil) goto v_13111;
    goto v_13120;
v_13116:
    v_13126 = stack[0];
    fn = elt(env, 2); // get!+row!+nr
    stack[-1] = (*qfn1(fn))(fn, v_13126);
    env = stack[-2];
    goto v_13117;
v_13118:
    v_13126 = stack[0];
    fn = elt(env, 3); // get!+col!+nr
    v_13126 = (*qfn1(fn))(fn, v_13126);
    goto v_13119;
v_13120:
    goto v_13116;
v_13117:
    goto v_13118;
v_13119:
    if (equal(stack[-1], v_13126)) goto v_13115;
    else goto v_13111;
v_13115:
    v_13126 = lisp_true;
    goto v_13107;
v_13111:
    v_13126 = nil;
v_13107:
    return onevalue(v_13126);
}



// Code for rl_pnf

static LispObject CC_rl_pnf(LispObject env,
                         LispObject v_13104)
{
    env = qenv(env);
    LispObject v_13115;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13104);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_13115 = v_13104;
// end of prologue
    goto v_13111;
v_13107:
    stack[0] = qvalue(elt(env, 1)); // rl_pnf!*
    goto v_13108;
v_13109:
    v_13115 = ncons(v_13115);
    env = stack[-1];
    goto v_13110;
v_13111:
    goto v_13107;
v_13108:
    goto v_13109;
v_13110:
    {
        LispObject v_13117 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_13117, v_13115);
    }
}



// Code for ev_lexcomp

static LispObject CC_ev_lexcomp(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13147, v_13148;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13104,v_13105);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13105;
    stack[-1] = v_13104;
// end of prologue
v_13109:
    v_13147 = stack[-1];
    if (v_13147 == nil) goto v_13112;
    else goto v_13113;
v_13112:
    v_13147 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13108;
v_13113:
    goto v_13123;
v_13119:
    v_13147 = stack[-1];
    v_13148 = qcar(v_13147);
    goto v_13120;
v_13121:
    v_13147 = stack[0];
    v_13147 = qcar(v_13147);
    goto v_13122;
v_13123:
    goto v_13119;
v_13120:
    goto v_13121;
v_13122:
    fn = elt(env, 1); // iequal
    v_13147 = (*qfn2(fn))(fn, v_13148, v_13147);
    env = stack[-2];
    if (v_13147 == nil) goto v_13117;
    v_13147 = stack[-1];
    v_13147 = qcdr(v_13147);
    stack[-1] = v_13147;
    v_13147 = stack[0];
    v_13147 = qcdr(v_13147);
    stack[0] = v_13147;
    goto v_13109;
v_13117:
    goto v_13138;
v_13134:
    v_13147 = stack[-1];
    v_13148 = qcar(v_13147);
    goto v_13135;
v_13136:
    v_13147 = stack[0];
    v_13147 = qcar(v_13147);
    goto v_13137;
v_13138:
    goto v_13134;
v_13135:
    goto v_13136;
v_13137:
    if (((intptr_t)(v_13148)) > ((intptr_t)(v_13147))) goto v_13132;
    else goto v_13133;
v_13132:
    v_13147 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13108;
v_13133:
    v_13147 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_13108;
    v_13147 = nil;
v_13108:
    return onevalue(v_13147);
}



// Code for makeset

static LispObject CC_makeset(LispObject env,
                         LispObject v_13104)
{
    env = qenv(env);
    LispObject v_13144, v_13145, v_13146;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13104);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_13104;
// end of prologue
    v_13146 = nil;
v_13109:
    v_13144 = stack[0];
    if (v_13144 == nil) goto v_13112;
    else goto v_13113;
v_13112:
    v_13144 = v_13146;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_13144);
    }
v_13113:
    goto v_13123;
v_13119:
    v_13144 = stack[0];
    v_13145 = qcar(v_13144);
    goto v_13120;
v_13121:
    v_13144 = stack[0];
    v_13144 = qcdr(v_13144);
    goto v_13122;
v_13123:
    goto v_13119;
v_13120:
    goto v_13121;
v_13122:
    v_13144 = Lmember(nil, v_13145, v_13144);
    if (v_13144 == nil) goto v_13118;
    v_13144 = stack[0];
    v_13144 = qcdr(v_13144);
    stack[0] = v_13144;
    goto v_13109;
v_13118:
    goto v_13138;
v_13134:
    v_13144 = stack[0];
    v_13144 = qcar(v_13144);
    goto v_13135;
v_13136:
    v_13145 = v_13146;
    goto v_13137;
v_13138:
    goto v_13134;
v_13135:
    goto v_13136;
v_13137:
    v_13144 = cons(v_13144, v_13145);
    env = stack[-1];
    v_13146 = v_13144;
    v_13144 = stack[0];
    v_13144 = qcdr(v_13144);
    stack[0] = v_13144;
    goto v_13109;
    v_13144 = nil;
    return onevalue(v_13144);
}



// Code for xlcm

static LispObject CC_xlcm(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13227, v_13228;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13104,v_13105);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13105;
    stack[-1] = v_13104;
// end of prologue
    stack[-2] = nil;
v_13110:
    v_13227 = stack[-1];
    if (v_13227 == nil) goto v_13117;
    else goto v_13118;
v_13117:
    v_13227 = lisp_true;
    goto v_13116;
v_13118:
    goto v_13127;
v_13123:
    v_13227 = stack[-1];
    v_13228 = qcar(v_13227);
    goto v_13124;
v_13125:
    v_13227 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13126;
v_13127:
    goto v_13123;
v_13124:
    goto v_13125;
v_13126:
    v_13227 = (v_13228 == v_13227 ? lisp_true : nil);
    goto v_13116;
    v_13227 = nil;
v_13116:
    if (v_13227 == nil) goto v_13114;
    goto v_13137;
v_13133:
    v_13228 = stack[-2];
    goto v_13134;
v_13135:
    v_13227 = stack[0];
    goto v_13136;
v_13137:
    goto v_13133;
v_13134:
    goto v_13135;
v_13136:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_13228, v_13227);
    }
v_13114:
    v_13227 = stack[0];
    if (v_13227 == nil) goto v_13144;
    else goto v_13145;
v_13144:
    v_13227 = lisp_true;
    goto v_13143;
v_13145:
    goto v_13154;
v_13150:
    v_13227 = stack[0];
    v_13228 = qcar(v_13227);
    goto v_13151;
v_13152:
    v_13227 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13153;
v_13154:
    goto v_13150;
v_13151:
    goto v_13152;
v_13153:
    v_13227 = (v_13228 == v_13227 ? lisp_true : nil);
    goto v_13143;
    v_13227 = nil;
v_13143:
    if (v_13227 == nil) goto v_13141;
    goto v_13164;
v_13160:
    v_13228 = stack[-2];
    goto v_13161;
v_13162:
    v_13227 = stack[-1];
    goto v_13163;
v_13164:
    goto v_13160;
v_13161:
    goto v_13162;
v_13163:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_13228, v_13227);
    }
v_13141:
    goto v_13173;
v_13169:
    v_13227 = stack[-1];
    v_13228 = qcar(v_13227);
    goto v_13170;
v_13171:
    v_13227 = stack[0];
    v_13227 = qcar(v_13227);
    goto v_13172;
v_13173:
    goto v_13169;
v_13170:
    goto v_13171;
v_13172:
    if (v_13228 == v_13227) goto v_13167;
    else goto v_13168;
v_13167:
    goto v_13183;
v_13179:
    v_13227 = stack[-1];
    v_13228 = qcar(v_13227);
    goto v_13180;
v_13181:
    v_13227 = stack[-2];
    goto v_13182;
v_13183:
    goto v_13179;
v_13180:
    goto v_13181;
v_13182:
    v_13227 = cons(v_13228, v_13227);
    env = stack[-3];
    stack[-2] = v_13227;
    v_13227 = stack[-1];
    v_13227 = qcdr(v_13227);
    stack[-1] = v_13227;
    v_13227 = stack[0];
    v_13227 = qcdr(v_13227);
    stack[0] = v_13227;
    goto v_13110;
v_13168:
    goto v_13198;
v_13194:
    v_13227 = stack[-1];
    v_13228 = qcar(v_13227);
    goto v_13195;
v_13196:
    v_13227 = stack[0];
    v_13227 = qcar(v_13227);
    goto v_13197;
v_13198:
    goto v_13194;
v_13195:
    goto v_13196;
v_13197:
    fn = elt(env, 2); // factorordp
    v_13227 = (*qfn2(fn))(fn, v_13228, v_13227);
    env = stack[-3];
    if (v_13227 == nil) goto v_13192;
    goto v_13208;
v_13204:
    v_13227 = stack[-1];
    v_13228 = qcar(v_13227);
    goto v_13205;
v_13206:
    v_13227 = stack[-2];
    goto v_13207;
v_13208:
    goto v_13204;
v_13205:
    goto v_13206;
v_13207:
    v_13227 = cons(v_13228, v_13227);
    env = stack[-3];
    stack[-2] = v_13227;
    v_13227 = stack[-1];
    v_13227 = qcdr(v_13227);
    stack[-1] = v_13227;
    goto v_13110;
v_13192:
    goto v_13221;
v_13217:
    v_13227 = stack[0];
    v_13228 = qcar(v_13227);
    goto v_13218;
v_13219:
    v_13227 = stack[-2];
    goto v_13220;
v_13221:
    goto v_13217;
v_13218:
    goto v_13219;
v_13220:
    v_13227 = cons(v_13228, v_13227);
    env = stack[-3];
    stack[-2] = v_13227;
    v_13227 = stack[0];
    v_13227 = qcdr(v_13227);
    stack[0] = v_13227;
    goto v_13110;
    v_13227 = nil;
    return onevalue(v_13227);
}



// Code for set!-global!-mode

static LispObject CC_setKglobalKmode(LispObject env,
                         LispObject v_13104)
{
    env = qenv(env);
    LispObject v_13130;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13104);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_13104;
// end of prologue
    v_13130 = nil;
    v_13130 = ncons(v_13130);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_13130; // alglist!*
    v_13130 = stack[-2];
    qvalue(elt(env, 2)) = v_13130; // !*mode
    goto v_13116;
v_13112:
    stack[-3] = elt(env, 3); // null
    goto v_13113;
v_13114:
    goto v_13125;
v_13119:
    stack[-1] = elt(env, 4); // setq
    goto v_13120;
v_13121:
    stack[0] = elt(env, 2); // !*mode
    goto v_13122;
v_13123:
    v_13130 = stack[-2];
    v_13130 = Lmkquote(nil, v_13130);
    env = stack[-4];
    goto v_13124;
v_13125:
    goto v_13119;
v_13120:
    goto v_13121;
v_13122:
    goto v_13123;
v_13124:
    v_13130 = list3(stack[-1], stack[0], v_13130);
    goto v_13115;
v_13116:
    goto v_13112;
v_13113:
    goto v_13114;
v_13115:
    {
        LispObject v_13135 = stack[-3];
        return list2(v_13135, v_13130);
    }
    return onevalue(v_13130);
}



// Code for scalprod

static LispObject CC_scalprod(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13180, v_13181, v_13182;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13104,v_13105);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13105;
    stack[-1] = v_13104;
// end of prologue
    v_13180 = stack[-1];
    if (v_13180 == nil) goto v_13113;
    else goto v_13114;
v_13113:
    v_13180 = stack[0];
    v_13180 = (v_13180 == nil ? lisp_true : nil);
    goto v_13112;
v_13114:
    v_13180 = nil;
    goto v_13112;
    v_13180 = nil;
v_13112:
    if (v_13180 == nil) goto v_13110;
    goto v_13126;
v_13122:
    v_13181 = nil;
    goto v_13123;
v_13124:
    v_13180 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13125;
v_13126:
    goto v_13122;
v_13123:
    goto v_13124;
v_13125:
    return cons(v_13181, v_13180);
v_13110:
    v_13180 = stack[-1];
    if (v_13180 == nil) goto v_13133;
    else goto v_13134;
v_13133:
    v_13180 = lisp_true;
    goto v_13132;
v_13134:
    v_13180 = stack[0];
    v_13180 = (v_13180 == nil ? lisp_true : nil);
    goto v_13132;
    v_13180 = nil;
v_13132:
    if (v_13180 == nil) goto v_13130;
    goto v_13148;
v_13142:
    v_13182 = elt(env, 1); // matrix
    goto v_13143;
v_13144:
    v_13181 = (LispObject)144+TAG_FIXNUM; // 9
    goto v_13145;
v_13146:
    v_13180 = elt(env, 2); // "Matrix mismatch"
    goto v_13147;
v_13148:
    goto v_13142;
v_13143:
    goto v_13144;
v_13145:
    goto v_13146;
v_13147:
    {
        fn = elt(env, 3); // rerror
        return (*qfnn(fn))(fn, 3, v_13182, v_13181, v_13180);
    }
v_13130:
    goto v_13159;
v_13155:
    goto v_13165;
v_13161:
    v_13180 = stack[-1];
    v_13181 = qcar(v_13180);
    goto v_13162;
v_13163:
    v_13180 = stack[0];
    v_13180 = qcar(v_13180);
    goto v_13164;
v_13165:
    goto v_13161;
v_13162:
    goto v_13163;
v_13164:
    fn = elt(env, 4); // multsq
    stack[-2] = (*qfn2(fn))(fn, v_13181, v_13180);
    env = stack[-3];
    goto v_13156;
v_13157:
    goto v_13175;
v_13171:
    v_13180 = stack[-1];
    v_13181 = qcdr(v_13180);
    goto v_13172;
v_13173:
    v_13180 = stack[0];
    v_13180 = qcdr(v_13180);
    goto v_13174;
v_13175:
    goto v_13171;
v_13172:
    goto v_13173;
v_13174:
    v_13180 = CC_scalprod(elt(env, 0), v_13181, v_13180);
    env = stack[-3];
    goto v_13158;
v_13159:
    goto v_13155;
v_13156:
    goto v_13157;
v_13158:
    {
        LispObject v_13186 = stack[-2];
        fn = elt(env, 5); // addsq
        return (*qfn2(fn))(fn, v_13186, v_13180);
    }
    v_13180 = nil;
    return onevalue(v_13180);
}



// Code for fs!:null!-angle

static LispObject CC_fsTnullKangle(LispObject env,
                         LispObject v_13104)
{
    env = qenv(env);
    LispObject v_13156, v_13157;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13104);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_13156 = v_13104;
// end of prologue
    goto v_13116;
v_13112:
    v_13157 = v_13156;
    goto v_13113;
v_13114:
    v_13156 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13115;
v_13116:
    goto v_13112;
v_13113:
    goto v_13114;
v_13115:
    v_13156 = *(LispObject *)((char *)v_13157 + (CELL-TAG_VECTOR) + (((intptr_t)v_13156-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_13156;
    v_13156 = lisp_true;
    stack[-2] = v_13156;
    v_13156 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_13156;
v_13111:
    goto v_13130;
v_13126:
    goto v_13135;
v_13131:
    v_13157 = stack[0];
    goto v_13132;
v_13133:
    v_13156 = stack[-1];
    goto v_13134;
v_13135:
    goto v_13131;
v_13132:
    goto v_13133;
v_13134:
    v_13157 = *(LispObject *)((char *)v_13157 + (CELL-TAG_VECTOR) + (((intptr_t)v_13156-TAG_FIXNUM)/(16/CELL)));
    goto v_13127;
v_13128:
    v_13156 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13129;
v_13130:
    goto v_13126;
v_13127:
    goto v_13128;
v_13129:
    if (v_13157 == v_13156) goto v_13125;
    v_13156 = nil;
    goto v_13110;
v_13125:
    v_13156 = stack[-1];
    v_13156 = add1(v_13156);
    env = stack[-3];
    stack[-1] = v_13156;
    goto v_13152;
v_13148:
    v_13157 = stack[-1];
    goto v_13149;
v_13150:
    v_13156 = (LispObject)128+TAG_FIXNUM; // 8
    goto v_13151;
v_13152:
    goto v_13148;
v_13149:
    goto v_13150;
v_13151:
    v_13156 = (LispObject)lessp2(v_13157, v_13156);
    v_13156 = v_13156 ? lisp_true : nil;
    env = stack[-3];
    if (v_13156 == nil) goto v_13146;
    goto v_13111;
v_13146:
    v_13156 = stack[-2];
v_13110:
    return onevalue(v_13156);
}



// Code for mo_equal!?

static LispObject CC_mo_equalW(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13119;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13104,v_13105);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13105;
    v_13119 = v_13104;
// end of prologue
    goto v_13111;
v_13107:
    v_13119 = qcar(v_13119);
    fn = elt(env, 1); // mo!=shorten
    stack[-1] = (*qfn1(fn))(fn, v_13119);
    env = stack[-2];
    goto v_13108;
v_13109:
    v_13119 = stack[0];
    v_13119 = qcar(v_13119);
    fn = elt(env, 1); // mo!=shorten
    v_13119 = (*qfn1(fn))(fn, v_13119);
    goto v_13110;
v_13111:
    goto v_13107;
v_13108:
    goto v_13109;
v_13110:
    v_13119 = (equal(stack[-1], v_13119) ? lisp_true : nil);
    return onevalue(v_13119);
}



// Code for ordered!-gcd!-mod!-p

static LispObject CC_orderedKgcdKmodKp(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13184, v_13185;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13104,v_13105);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13105;
    stack[-1] = v_13104;
// end of prologue
    v_13184 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_13184;
v_13110:
    goto v_13117;
v_13113:
    v_13185 = stack[-1];
    goto v_13114;
v_13115:
    v_13184 = stack[0];
    goto v_13116;
v_13117:
    goto v_13113;
v_13114:
    goto v_13115;
v_13116:
    fn = elt(env, 2); // reduce!-degree!-mod!-p
    v_13184 = (*qfn2(fn))(fn, v_13185, v_13184);
    env = stack[-3];
    stack[-1] = v_13184;
    v_13184 = stack[-1];
    if (v_13184 == nil) goto v_13122;
    else goto v_13123;
v_13122:
    v_13184 = stack[0];
    {
        fn = elt(env, 3); // monic!-mod!-p
        return (*qfn1(fn))(fn, v_13184);
    }
v_13123:
    v_13184 = stack[-2];
    v_13184 = add1(v_13184);
    env = stack[-3];
    stack[-2] = v_13184;
    v_13184 = stack[-1];
    if (!consp(v_13184)) goto v_13135;
    else goto v_13136;
v_13135:
    v_13184 = lisp_true;
    goto v_13134;
v_13136:
    v_13184 = stack[-1];
    v_13184 = qcar(v_13184);
    v_13184 = (consp(v_13184) ? nil : lisp_true);
    goto v_13134;
    v_13184 = nil;
v_13134:
    if (v_13184 == nil) goto v_13132;
    goto v_13149;
v_13145:
    v_13185 = qvalue(elt(env, 1)); // reduction!-count
    goto v_13146;
v_13147:
    v_13184 = stack[-2];
    goto v_13148;
v_13149:
    goto v_13145;
v_13146:
    goto v_13147;
v_13148:
    v_13184 = plus2(v_13185, v_13184);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_13184; // reduction!-count
    v_13184 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13109;
v_13132:
    goto v_13160;
v_13156:
    v_13184 = stack[-1];
    v_13184 = qcar(v_13184);
    v_13184 = qcar(v_13184);
    v_13185 = qcdr(v_13184);
    goto v_13157;
v_13158:
    v_13184 = stack[0];
    v_13184 = qcar(v_13184);
    v_13184 = qcar(v_13184);
    v_13184 = qcdr(v_13184);
    goto v_13159;
v_13160:
    goto v_13156;
v_13157:
    goto v_13158;
v_13159:
    v_13184 = (LispObject)lessp2(v_13185, v_13184);
    v_13184 = v_13184 ? lisp_true : nil;
    env = stack[-3];
    if (v_13184 == nil) goto v_13154;
    goto v_13177;
v_13173:
    v_13185 = qvalue(elt(env, 1)); // reduction!-count
    goto v_13174;
v_13175:
    v_13184 = stack[-2];
    goto v_13176;
v_13177:
    goto v_13173;
v_13174:
    goto v_13175;
v_13176:
    v_13184 = plus2(v_13185, v_13184);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_13184; // reduction!-count
    v_13184 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_13184;
    v_13184 = stack[-1];
    v_13185 = v_13184;
    v_13184 = stack[0];
    stack[-1] = v_13184;
    v_13184 = v_13185;
    stack[0] = v_13184;
    goto v_13130;
v_13154:
v_13130:
    goto v_13110;
v_13109:
    return onevalue(v_13184);
}



// Code for p_prinl2

static LispObject CC_p_prinl2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13595, v_13596, v_13597, v_13598;
    LispObject fn;
    LispObject v_13107, v_13106, v_13105, v_13104;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "p_prinl2");
    va_start(aa, nargs);
    v_13104 = va_arg(aa, LispObject);
    v_13105 = va_arg(aa, LispObject);
    v_13106 = va_arg(aa, LispObject);
    v_13107 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_13107,v_13106,v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_13104,v_13105,v_13106,v_13107);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-2] = v_13107;
    stack[-4] = v_13106;
    stack[-5] = v_13105;
    stack[-6] = v_13104;
// end of prologue
    v_13595 = qvalue(elt(env, 1)); // !*print!-level!*
    v_13595 = integerp(v_13595);
    if (v_13595 == nil) goto v_13112;
    goto v_13122;
v_13118:
    v_13596 = stack[-5];
    goto v_13119;
v_13120:
    v_13595 = qvalue(elt(env, 1)); // !*print!-level!*
    goto v_13121;
v_13122:
    goto v_13118;
v_13119:
    goto v_13120;
v_13121:
    v_13595 = (LispObject)greaterp2(v_13596, v_13595);
    v_13595 = v_13595 ? lisp_true : nil;
    env = stack[-8];
    if (v_13595 == nil) goto v_13112;
    goto v_13130;
v_13126:
    v_13596 = elt(env, 2); // "#"
    goto v_13127;
v_13128:
    v_13595 = stack[-2];
    goto v_13129;
v_13130:
    goto v_13126;
v_13127:
    goto v_13128;
v_13129:
    {
        fn = elt(env, 12); // p_princ
        return (*qfn2(fn))(fn, v_13596, v_13595);
    }
v_13112:
    v_13595 = stack[-6];
    if (!consp(v_13595)) goto v_13137;
    else goto v_13138;
v_13137:
    v_13595 = stack[-6];
    v_13595 = Lsimple_vectorp(nil, v_13595);
    env = stack[-8];
    if (v_13595 == nil) goto v_13142;
    else goto v_13143;
v_13142:
    v_13595 = stack[-6];
    fn = elt(env, 13); // gensymp
    v_13595 = (*qfn1(fn))(fn, v_13595);
    env = stack[-8];
    v_13595 = (v_13595 == nil ? lisp_true : nil);
    goto v_13141;
v_13143:
    v_13595 = nil;
    goto v_13141;
    v_13595 = nil;
v_13141:
    goto v_13136;
v_13138:
    v_13595 = nil;
    goto v_13136;
    v_13595 = nil;
v_13136:
    if (v_13595 == nil) goto v_13134;
    v_13595 = stack[-4];
    if (v_13595 == nil) goto v_13158;
    goto v_13165;
v_13161:
    v_13596 = stack[-6];
    goto v_13162;
v_13163:
    v_13595 = stack[-2];
    goto v_13164;
v_13165:
    goto v_13161;
v_13162:
    goto v_13163;
v_13164:
    {
        fn = elt(env, 14); // p_prin
        return (*qfn2(fn))(fn, v_13596, v_13595);
    }
v_13158:
    goto v_13175;
v_13171:
    v_13596 = stack[-6];
    goto v_13172;
v_13173:
    v_13595 = stack[-2];
    goto v_13174;
v_13175:
    goto v_13171;
v_13172:
    goto v_13173;
v_13174:
    {
        fn = elt(env, 12); // p_princ
        return (*qfn2(fn))(fn, v_13596, v_13595);
    }
    v_13595 = nil;
    goto v_13110;
v_13134:
    goto v_13190;
v_13186:
    v_13596 = stack[-6];
    goto v_13187;
v_13188:
    v_13595 = qvalue(elt(env, 3)); // !*prinl_visited_nodes!*
    goto v_13189;
v_13190:
    goto v_13186;
v_13187:
    goto v_13188;
v_13189:
    fn = elt(env, 15); // gethash
    v_13595 = (*qfn2(fn))(fn, v_13596, v_13595);
    env = stack[-8];
    stack[-1] = v_13595;
    v_13595 = stack[-1];
    if (v_13595 == nil) goto v_13196;
    v_13595 = stack[-1];
    v_13595 = (LispObject)zerop(v_13595);
    v_13595 = v_13595 ? lisp_true : nil;
    env = stack[-8];
    if (v_13595 == nil) goto v_13199;
    else goto v_13196;
v_13199:
    goto v_13211;
v_13207:
    v_13596 = stack[-1];
    goto v_13208;
v_13209:
    v_13595 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13210;
v_13211:
    goto v_13207;
v_13208:
    goto v_13209;
v_13210:
    v_13595 = (LispObject)lessp2(v_13596, v_13595);
    v_13595 = v_13595 ? lisp_true : nil;
    env = stack[-8];
    if (v_13595 == nil) goto v_13205;
    goto v_13221;
v_13215:
    v_13595 = stack[-1];
    v_13597 = negate(v_13595);
    env = stack[-8];
    goto v_13216;
v_13217:
    v_13596 = stack[-2];
    goto v_13218;
v_13219:
    v_13595 = elt(env, 2); // "#"
    goto v_13220;
v_13221:
    goto v_13215;
v_13216:
    goto v_13217;
v_13218:
    goto v_13219;
v_13220:
    fn = elt(env, 16); // p_printref
    v_13595 = (*qfnn(fn))(fn, 3, v_13597, v_13596, v_13595);
    v_13595 = nil;
    goto v_13183;
v_13205:
    goto v_13236;
v_13230:
    stack[-3] = stack[-6];
    goto v_13231;
v_13232:
    stack[0] = qvalue(elt(env, 3)); // !*prinl_visited_nodes!*
    goto v_13233;
v_13234:
    v_13595 = stack[-1];
    v_13595 = negate(v_13595);
    env = stack[-8];
    goto v_13235;
v_13236:
    goto v_13230;
v_13231:
    goto v_13232;
v_13233:
    goto v_13234;
v_13235:
    fn = elt(env, 17); // puthash
    v_13595 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_13595);
    env = stack[-8];
    goto v_13248;
v_13242:
    v_13597 = stack[-1];
    goto v_13243;
v_13244:
    v_13596 = stack[-2];
    goto v_13245;
v_13246:
    v_13595 = elt(env, 4); // "="
    goto v_13247;
v_13248:
    goto v_13242;
v_13243:
    goto v_13244;
v_13245:
    goto v_13246;
v_13247:
    fn = elt(env, 16); // p_printref
    v_13595 = (*qfnn(fn))(fn, 3, v_13597, v_13596, v_13595);
    env = stack[-8];
    v_13595 = nil;
    stack[-2] = v_13595;
    goto v_13203;
v_13203:
    goto v_13194;
v_13196:
v_13194:
    v_13595 = stack[-6];
    v_13595 = Lsimple_vectorp(nil, v_13595);
    env = stack[-8];
    if (v_13595 == nil) goto v_13256;
    goto v_13264;
v_13260:
    v_13596 = elt(env, 5); // "%("
    goto v_13261;
v_13262:
    v_13595 = stack[-2];
    goto v_13263;
v_13264:
    goto v_13260;
v_13261:
    goto v_13262;
v_13263:
    fn = elt(env, 12); // p_princ
    v_13595 = (*qfn2(fn))(fn, v_13596, v_13595);
    env = stack[-8];
    v_13595 = qvalue(elt(env, 6)); // !*print!-array!*
    if (v_13595 == nil) goto v_13270;
    v_13595 = stack[-6];
    v_13595 = Lupbv(nil, v_13595);
    env = stack[-8];
    stack[-7] = v_13595;
    v_13595 = qvalue(elt(env, 7)); // !*print!-length!*
    v_13595 = integerp(v_13595);
    if (v_13595 == nil) goto v_13277;
    goto v_13287;
v_13283:
    v_13596 = qvalue(elt(env, 7)); // !*print!-length!*
    goto v_13284;
v_13285:
    v_13595 = stack[-7];
    goto v_13286;
v_13287:
    goto v_13283;
v_13284:
    goto v_13285;
v_13286:
    v_13595 = (LispObject)lessp2(v_13596, v_13595);
    v_13595 = v_13595 ? lisp_true : nil;
    env = stack[-8];
    if (v_13595 == nil) goto v_13277;
    v_13595 = qvalue(elt(env, 7)); // !*print!-length!*
    stack[-7] = v_13595;
    goto v_13275;
v_13277:
v_13275:
    v_13595 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_13595;
v_13294:
    goto v_13306;
v_13302:
    v_13596 = stack[-7];
    goto v_13303;
v_13304:
    v_13595 = stack[-3];
    goto v_13305;
v_13306:
    goto v_13302;
v_13303:
    goto v_13304;
v_13305:
    v_13595 = difference2(v_13596, v_13595);
    env = stack[-8];
    v_13595 = Lminusp(nil, v_13595);
    env = stack[-8];
    if (v_13595 == nil) goto v_13299;
    goto v_13293;
v_13299:
    goto v_13319;
v_13311:
    goto v_13324;
v_13320:
    v_13596 = stack[-6];
    goto v_13321;
v_13322:
    v_13595 = stack[-3];
    goto v_13323;
v_13324:
    goto v_13320;
v_13321:
    goto v_13322;
v_13323:
    stack[-2] = *(LispObject *)((char *)v_13596 + (CELL-TAG_VECTOR) + (((intptr_t)v_13595-TAG_FIXNUM)/(16/CELL)));
    goto v_13312;
v_13313:
    v_13595 = stack[-5];
    stack[-1] = add1(v_13595);
    env = stack[-8];
    goto v_13314;
v_13315:
    stack[0] = stack[-4];
    goto v_13316;
v_13317:
    goto v_13336;
v_13332:
    v_13596 = stack[-3];
    goto v_13333;
v_13334:
    v_13595 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13335;
v_13336:
    goto v_13332;
v_13333:
    goto v_13334;
v_13335:
    v_13595 = Lneq(nil, v_13596, v_13595);
    env = stack[-8];
    goto v_13318;
v_13319:
    goto v_13311;
v_13312:
    goto v_13313;
v_13314:
    goto v_13315;
v_13316:
    goto v_13317;
v_13318:
    v_13595 = CC_p_prinl2(elt(env, 0), 4, stack[-2], stack[-1], stack[0], v_13595);
    env = stack[-8];
    v_13595 = stack[-3];
    v_13595 = add1(v_13595);
    env = stack[-8];
    stack[-3] = v_13595;
    goto v_13294;
v_13293:
    goto v_13268;
v_13270:
    goto v_13348;
v_13344:
    v_13596 = elt(env, 8); // "..."
    goto v_13345;
v_13346:
    v_13595 = nil;
    goto v_13347;
v_13348:
    goto v_13344;
v_13345:
    goto v_13346;
v_13347:
    fn = elt(env, 12); // p_princ
    v_13595 = (*qfn2(fn))(fn, v_13596, v_13595);
    env = stack[-8];
    goto v_13268;
v_13268:
    goto v_13356;
v_13352:
    v_13596 = elt(env, 9); // ")"
    goto v_13353;
v_13354:
    v_13595 = nil;
    goto v_13355;
v_13356:
    goto v_13352;
v_13353:
    goto v_13354;
v_13355:
    fn = elt(env, 12); // p_princ
    v_13595 = (*qfn2(fn))(fn, v_13596, v_13595);
    v_13595 = nil;
    goto v_13183;
v_13256:
    v_13595 = stack[-6];
    if (!consp(v_13595)) goto v_13360;
    else goto v_13361;
v_13360:
    v_13595 = stack[-4];
    if (v_13595 == nil) goto v_13366;
    goto v_13373;
v_13369:
    v_13596 = stack[-6];
    goto v_13370;
v_13371:
    v_13595 = stack[-2];
    goto v_13372;
v_13373:
    goto v_13369;
v_13370:
    goto v_13371;
v_13372:
    fn = elt(env, 14); // p_prin
    v_13595 = (*qfn2(fn))(fn, v_13596, v_13595);
    goto v_13364;
v_13366:
    goto v_13383;
v_13379:
    v_13596 = stack[-6];
    goto v_13380;
v_13381:
    v_13595 = stack[-2];
    goto v_13382;
v_13383:
    goto v_13379;
v_13380:
    goto v_13381;
v_13382:
    fn = elt(env, 12); // p_princ
    v_13595 = (*qfn2(fn))(fn, v_13596, v_13595);
    goto v_13364;
v_13364:
    v_13595 = nil;
    goto v_13183;
v_13361:
    goto v_13392;
v_13388:
    v_13596 = elt(env, 10); // "("
    goto v_13389;
v_13390:
    v_13595 = stack[-2];
    goto v_13391;
v_13392:
    goto v_13388;
v_13389:
    goto v_13390;
v_13391:
    fn = elt(env, 12); // p_princ
    v_13595 = (*qfn2(fn))(fn, v_13596, v_13595);
    env = stack[-8];
    goto v_13404;
v_13396:
    v_13595 = stack[-6];
    stack[0] = qcar(v_13595);
    goto v_13397;
v_13398:
    v_13595 = stack[-5];
    v_13597 = add1(v_13595);
    env = stack[-8];
    goto v_13399;
v_13400:
    v_13596 = stack[-4];
    goto v_13401;
v_13402:
    v_13595 = nil;
    goto v_13403;
v_13404:
    goto v_13396;
v_13397:
    goto v_13398;
v_13399:
    goto v_13400;
v_13401:
    goto v_13402;
v_13403:
    v_13595 = CC_p_prinl2(elt(env, 0), 4, stack[0], v_13597, v_13596, v_13595);
    env = stack[-8];
    v_13595 = stack[-6];
    v_13595 = qcdr(v_13595);
    stack[-6] = v_13595;
    v_13595 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_13595;
v_13184:
    v_13595 = stack[-6];
    if (!consp(v_13595)) goto v_13416;
    else goto v_13417;
v_13416:
    v_13595 = stack[-6];
    if (v_13595 == nil) goto v_13422;
    goto v_13429;
v_13425:
    v_13596 = elt(env, 11); // "."
    goto v_13426;
v_13427:
    v_13595 = lisp_true;
    goto v_13428;
v_13429:
    goto v_13425;
v_13426:
    goto v_13427;
v_13428:
    fn = elt(env, 12); // p_princ
    v_13595 = (*qfn2(fn))(fn, v_13596, v_13595);
    env = stack[-8];
    goto v_13441;
v_13433:
    v_13598 = stack[-6];
    goto v_13434;
v_13435:
    v_13597 = stack[-5];
    goto v_13436;
v_13437:
    v_13596 = stack[-4];
    goto v_13438;
v_13439:
    v_13595 = lisp_true;
    goto v_13440;
v_13441:
    goto v_13433;
v_13434:
    goto v_13435;
v_13436:
    goto v_13437;
v_13438:
    goto v_13439;
v_13440:
    v_13595 = CC_p_prinl2(elt(env, 0), 4, v_13598, v_13597, v_13596, v_13595);
    env = stack[-8];
    goto v_13420;
v_13422:
v_13420:
    goto v_13451;
v_13447:
    v_13596 = elt(env, 9); // ")"
    goto v_13448;
v_13449:
    v_13595 = nil;
    goto v_13450;
v_13451:
    goto v_13447;
v_13448:
    goto v_13449;
v_13450:
    {
        fn = elt(env, 12); // p_princ
        return (*qfn2(fn))(fn, v_13596, v_13595);
    }
v_13417:
    v_13595 = qvalue(elt(env, 7)); // !*print!-length!*
    v_13595 = integerp(v_13595);
    if (v_13595 == nil) goto v_13457;
    goto v_13467;
v_13463:
    v_13595 = stack[-7];
    v_13596 = add1(v_13595);
    env = stack[-8];
    stack[-7] = v_13596;
    goto v_13464;
v_13465:
    v_13595 = qvalue(elt(env, 7)); // !*print!-length!*
    goto v_13466;
v_13467:
    goto v_13463;
v_13464:
    goto v_13465;
v_13466:
    v_13595 = (LispObject)greaterp2(v_13596, v_13595);
    v_13595 = v_13595 ? lisp_true : nil;
    env = stack[-8];
    if (v_13595 == nil) goto v_13457;
    goto v_13476;
v_13472:
    v_13596 = elt(env, 8); // "..."
    goto v_13473;
v_13474:
    v_13595 = lisp_true;
    goto v_13475;
v_13476:
    goto v_13472;
v_13473:
    goto v_13474;
v_13475:
    fn = elt(env, 12); // p_princ
    v_13595 = (*qfn2(fn))(fn, v_13596, v_13595);
    env = stack[-8];
    goto v_13484;
v_13480:
    v_13596 = elt(env, 9); // ")"
    goto v_13481;
v_13482:
    v_13595 = nil;
    goto v_13483;
v_13484:
    goto v_13480;
v_13481:
    goto v_13482;
v_13483:
    {
        fn = elt(env, 12); // p_princ
        return (*qfn2(fn))(fn, v_13596, v_13595);
    }
v_13457:
    goto v_13492;
v_13488:
    v_13596 = stack[-6];
    goto v_13489;
v_13490:
    v_13595 = qvalue(elt(env, 3)); // !*prinl_visited_nodes!*
    goto v_13491;
v_13492:
    goto v_13488;
v_13489:
    goto v_13490;
v_13491:
    fn = elt(env, 15); // gethash
    v_13595 = (*qfn2(fn))(fn, v_13596, v_13595);
    env = stack[-8];
    stack[-1] = v_13595;
    v_13595 = stack[-1];
    if (v_13595 == nil) goto v_13498;
    v_13595 = stack[-1];
    v_13595 = (LispObject)zerop(v_13595);
    v_13595 = v_13595 ? lisp_true : nil;
    env = stack[-8];
    if (v_13595 == nil) goto v_13501;
    else goto v_13498;
v_13501:
    goto v_13513;
v_13509:
    v_13596 = stack[-1];
    goto v_13510;
v_13511:
    v_13595 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13512;
v_13513:
    goto v_13509;
v_13510:
    goto v_13511;
v_13512:
    v_13595 = (LispObject)lessp2(v_13596, v_13595);
    v_13595 = v_13595 ? lisp_true : nil;
    env = stack[-8];
    if (v_13595 == nil) goto v_13507;
    goto v_13521;
v_13517:
    v_13596 = elt(env, 11); // "."
    goto v_13518;
v_13519:
    v_13595 = lisp_true;
    goto v_13520;
v_13521:
    goto v_13517;
v_13518:
    goto v_13519;
v_13520:
    fn = elt(env, 12); // p_princ
    v_13595 = (*qfn2(fn))(fn, v_13596, v_13595);
    env = stack[-8];
    goto v_13531;
v_13525:
    v_13595 = stack[-1];
    v_13597 = negate(v_13595);
    env = stack[-8];
    goto v_13526;
v_13527:
    v_13596 = lisp_true;
    goto v_13528;
v_13529:
    v_13595 = elt(env, 2); // "#"
    goto v_13530;
v_13531:
    goto v_13525;
v_13526:
    goto v_13527;
v_13528:
    goto v_13529;
v_13530:
    fn = elt(env, 16); // p_printref
    v_13595 = (*qfnn(fn))(fn, 3, v_13597, v_13596, v_13595);
    env = stack[-8];
    goto v_13541;
v_13537:
    v_13596 = elt(env, 9); // ")"
    goto v_13538;
v_13539:
    v_13595 = nil;
    goto v_13540;
v_13541:
    goto v_13537;
v_13538:
    goto v_13539;
v_13540:
    {
        fn = elt(env, 12); // p_princ
        return (*qfn2(fn))(fn, v_13596, v_13595);
    }
v_13507:
    goto v_13551;
v_13547:
    v_13596 = elt(env, 11); // "."
    goto v_13548;
v_13549:
    v_13595 = lisp_true;
    goto v_13550;
v_13551:
    goto v_13547;
v_13548:
    goto v_13549;
v_13550:
    fn = elt(env, 12); // p_princ
    v_13595 = (*qfn2(fn))(fn, v_13596, v_13595);
    env = stack[-8];
    goto v_13563;
v_13555:
    stack[0] = stack[-6];
    goto v_13556;
v_13557:
    v_13595 = stack[-5];
    v_13597 = add1(v_13595);
    env = stack[-8];
    goto v_13558;
v_13559:
    v_13596 = stack[-4];
    goto v_13560;
v_13561:
    v_13595 = lisp_true;
    goto v_13562;
v_13563:
    goto v_13555;
v_13556:
    goto v_13557;
v_13558:
    goto v_13559;
v_13560:
    goto v_13561;
v_13562:
    v_13595 = CC_p_prinl2(elt(env, 0), 4, stack[0], v_13597, v_13596, v_13595);
    env = stack[-8];
    goto v_13574;
v_13570:
    v_13596 = elt(env, 9); // ")"
    goto v_13571;
v_13572:
    v_13595 = nil;
    goto v_13573;
v_13574:
    goto v_13570;
v_13571:
    goto v_13572;
v_13573:
    {
        fn = elt(env, 12); // p_princ
        return (*qfn2(fn))(fn, v_13596, v_13595);
    }
    goto v_13496;
v_13498:
v_13496:
    goto v_13586;
v_13578:
    v_13595 = stack[-6];
    stack[0] = qcar(v_13595);
    goto v_13579;
v_13580:
    v_13595 = stack[-5];
    v_13597 = add1(v_13595);
    env = stack[-8];
    goto v_13581;
v_13582:
    v_13596 = stack[-4];
    goto v_13583;
v_13584:
    v_13595 = lisp_true;
    goto v_13585;
v_13586:
    goto v_13578;
v_13579:
    goto v_13580;
v_13581:
    goto v_13582;
v_13583:
    goto v_13584;
v_13585:
    v_13595 = CC_p_prinl2(elt(env, 0), 4, stack[0], v_13597, v_13596, v_13595);
    env = stack[-8];
    v_13595 = stack[-6];
    v_13595 = qcdr(v_13595);
    stack[-6] = v_13595;
    goto v_13184;
v_13183:
    goto v_13110;
    v_13595 = nil;
v_13110:
    return onevalue(v_13595);
}



// Code for defineargs

static LispObject CC_defineargs(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13172, v_13173, v_13174, v_13175;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13104,v_13105);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13105;
    stack[-1] = v_13104;
// end of prologue
    v_13172 = stack[-1];
    if (!symbolp(v_13172)) v_13172 = nil;
    else { v_13172 = qfastgets(v_13172);
           if (v_13172 != nil) { v_13172 = elt(v_13172, 42); // number!-of!-args
#ifdef RECORD_GET
             if (v_13172 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v_13172 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v_13172 == SPID_NOPROP) v_13172 = nil; }}
#endif
    v_13173 = v_13172;
    v_13172 = v_13173;
    if (v_13172 == nil) goto v_13115;
    else goto v_13116;
v_13115:
    goto v_13123;
v_13119:
    v_13173 = stack[-1];
    goto v_13120;
v_13121:
    v_13172 = stack[0];
    goto v_13122;
v_13123:
    goto v_13119;
v_13120:
    goto v_13121;
v_13122:
    {
        fn = elt(env, 2); // hasarg
        return (*qfn2(fn))(fn, v_13173, v_13172);
    }
v_13116:
    goto v_13134;
v_13130:
    v_13174 = stack[0];
    goto v_13131;
v_13132:
    v_13172 = v_13173;
    goto v_13133;
v_13134:
    goto v_13130;
v_13131:
    goto v_13132;
v_13133:
    if (equal(v_13174, v_13172)) goto v_13128;
    else goto v_13129;
v_13128:
    v_13172 = nil;
    goto v_13110;
v_13129:
    goto v_13147;
v_13143:
    v_13174 = stack[-1];
    goto v_13144;
v_13145:
    v_13172 = elt(env, 1); // calledby
    goto v_13146;
v_13147:
    goto v_13143;
v_13144:
    goto v_13145;
v_13146:
    v_13174 = get(v_13174, v_13172);
    env = stack[-2];
    v_13172 = v_13174;
    if (v_13174 == nil) goto v_13141;
    goto v_13159;
v_13151:
    v_13175 = stack[-1];
    goto v_13152;
v_13153:
    v_13174 = stack[0];
    goto v_13154;
v_13155:
    goto v_13156;
v_13157:
    goto v_13158;
v_13159:
    goto v_13151;
v_13152:
    goto v_13153;
v_13154:
    goto v_13155;
v_13156:
    goto v_13157;
v_13158:
    fn = elt(env, 3); // instdof
    v_13172 = (*qfnn(fn))(fn, 4, v_13175, v_13174, v_13173, v_13172);
    env = stack[-2];
    goto v_13139;
v_13141:
v_13139:
    goto v_13169;
v_13165:
    v_13173 = stack[-1];
    goto v_13166;
v_13167:
    v_13172 = stack[0];
    goto v_13168;
v_13169:
    goto v_13165;
v_13166:
    goto v_13167;
v_13168:
    fn = elt(env, 2); // hasarg
    v_13172 = (*qfn2(fn))(fn, v_13173, v_13172);
    v_13172 = nil;
v_13110:
    return onevalue(v_13172);
}



// Code for tayexp!-times2

static LispObject CC_tayexpKtimes2(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13187, v_13188, v_13189;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13104,v_13105);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13105;
    v_13188 = v_13104;
// end of prologue
    v_13187 = v_13188;
    if (!consp(v_13187)) goto v_13113;
    else goto v_13114;
v_13113:
    v_13187 = stack[0];
    v_13187 = (consp(v_13187) ? nil : lisp_true);
    goto v_13112;
v_13114:
    v_13187 = nil;
    goto v_13112;
    v_13187 = nil;
v_13112:
    if (v_13187 == nil) goto v_13110;
    goto v_13126;
v_13122:
    goto v_13123;
v_13124:
    v_13187 = stack[0];
    goto v_13125;
v_13126:
    goto v_13122;
v_13123:
    goto v_13124;
v_13125:
    return times2(v_13188, v_13187);
v_13110:
    v_13187 = v_13188;
    if (!consp(v_13187)) goto v_13133;
    else goto v_13134;
v_13133:
    goto v_13141;
v_13137:
    v_13187 = v_13188;
    fn = elt(env, 1); // !*i2rn
    v_13188 = (*qfn1(fn))(fn, v_13187);
    env = stack[-2];
    goto v_13138;
v_13139:
    v_13187 = stack[0];
    goto v_13140;
v_13141:
    goto v_13137;
v_13138:
    goto v_13139;
v_13140:
    fn = elt(env, 2); // rntimes!:
    v_13187 = (*qfn2(fn))(fn, v_13188, v_13187);
    goto v_13132;
v_13134:
    v_13187 = stack[0];
    if (!consp(v_13187)) goto v_13145;
    else goto v_13146;
v_13145:
    goto v_13153;
v_13149:
    stack[-1] = v_13188;
    goto v_13150;
v_13151:
    v_13187 = stack[0];
    fn = elt(env, 1); // !*i2rn
    v_13187 = (*qfn1(fn))(fn, v_13187);
    env = stack[-2];
    goto v_13152;
v_13153:
    goto v_13149;
v_13150:
    goto v_13151;
v_13152:
    fn = elt(env, 2); // rntimes!:
    v_13187 = (*qfn2(fn))(fn, stack[-1], v_13187);
    goto v_13132;
v_13146:
    goto v_13164;
v_13160:
    goto v_13161;
v_13162:
    v_13187 = stack[0];
    goto v_13163;
v_13164:
    goto v_13160;
v_13161:
    goto v_13162;
v_13163:
    fn = elt(env, 2); // rntimes!:
    v_13187 = (*qfn2(fn))(fn, v_13188, v_13187);
    goto v_13132;
    v_13187 = nil;
v_13132:
    v_13189 = v_13187;
    goto v_13176;
v_13172:
    v_13187 = v_13189;
    v_13187 = qcdr(v_13187);
    v_13188 = qcdr(v_13187);
    goto v_13173;
v_13174:
    v_13187 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13175;
v_13176:
    goto v_13172;
v_13173:
    goto v_13174;
v_13175:
    if (v_13188 == v_13187) goto v_13170;
    else goto v_13171;
v_13170:
    v_13187 = v_13189;
    v_13187 = qcdr(v_13187);
    v_13187 = qcar(v_13187);
    goto v_13169;
v_13171:
    v_13187 = v_13189;
    goto v_13169;
    v_13187 = nil;
v_13169:
    goto v_13108;
    v_13187 = nil;
v_13108:
    return onevalue(v_13187);
}



// Code for talp_contains

static LispObject CC_talp_contains(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13174, v_13175, v_13176;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13104,v_13105);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13105;
    v_13174 = v_13104;
// end of prologue
    v_13176 = nil;
    v_13175 = v_13174;
    v_13175 = Lconsp(nil, v_13175);
    env = stack[-2];
    if (v_13175 == nil) goto v_13113;
    stack[-1] = v_13174;
v_13119:
    v_13174 = stack[-1];
    if (v_13174 == nil) goto v_13123;
    else goto v_13124;
v_13123:
    goto v_13118;
v_13124:
    v_13174 = stack[-1];
    v_13174 = qcar(v_13174);
    v_13175 = v_13174;
    v_13174 = v_13175;
    v_13174 = Lconsp(nil, v_13174);
    env = stack[-2];
    if (v_13174 == nil) goto v_13133;
    v_13174 = v_13176;
    if (v_13174 == nil) goto v_13137;
    else goto v_13133;
v_13137:
    goto v_13144;
v_13140:
    goto v_13141;
v_13142:
    v_13174 = stack[0];
    goto v_13143;
v_13144:
    goto v_13140;
v_13141:
    goto v_13142;
v_13143:
    v_13174 = CC_talp_contains(elt(env, 0), v_13175, v_13174);
    env = stack[-2];
    v_13176 = v_13174;
    goto v_13131;
v_13133:
    goto v_13157;
v_13153:
    goto v_13154;
v_13155:
    v_13174 = stack[0];
    goto v_13156;
v_13157:
    goto v_13153;
v_13154:
    goto v_13155;
v_13156:
    if (v_13175 == v_13174) goto v_13151;
    else goto v_13152;
v_13151:
    v_13174 = lisp_true;
    v_13176 = v_13174;
    goto v_13150;
v_13152:
v_13150:
    goto v_13131;
v_13131:
    v_13174 = stack[-1];
    v_13174 = qcdr(v_13174);
    stack[-1] = v_13174;
    goto v_13119;
v_13118:
    goto v_13111;
v_13113:
    goto v_13169;
v_13165:
    v_13175 = stack[0];
    goto v_13166;
v_13167:
    goto v_13168;
v_13169:
    goto v_13165;
v_13166:
    goto v_13167;
v_13168:
    if (v_13175 == v_13174) goto v_13163;
    else goto v_13164;
v_13163:
    v_13174 = lisp_true;
    goto v_13109;
v_13164:
v_13111:
    v_13174 = v_13176;
v_13109:
    return onevalue(v_13174);
}



// Code for mri_pasf2mri

static LispObject CC_mri_pasf2mri(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13119, v_13120;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13104,v_13105);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_13119 = v_13105;
    v_13120 = v_13104;
// end of prologue
    goto v_13114;
v_13108:
    stack[-1] = v_13120;
    goto v_13109;
v_13110:
    stack[0] = elt(env, 1); // mri_pasf2mriat
    goto v_13111;
v_13112:
    v_13119 = ncons(v_13119);
    env = stack[-2];
    goto v_13113;
v_13114:
    goto v_13108;
v_13109:
    goto v_13110;
v_13111:
    goto v_13112;
v_13113:
    {
        LispObject v_13123 = stack[-1];
        LispObject v_13124 = stack[0];
        fn = elt(env, 2); // cl_apply2ats1
        return (*qfnn(fn))(fn, 3, v_13123, v_13124, v_13119);
    }
}



// Code for vsl_boundtype

static LispObject CC_vsl_boundtype(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13117, v_13118;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13117 = v_13105;
    v_13118 = v_13104;
// end of prologue
    goto v_13112;
v_13108:
    v_13118 = qcdr(v_13118);
    v_13118 = qcar(v_13118);
    goto v_13109;
v_13110:
    goto v_13111;
v_13112:
    goto v_13108;
v_13109:
    goto v_13110;
v_13111:
    {
        fn = elt(env, 1); // vsl_boundtype1
        return (*qfn2(fn))(fn, v_13118, v_13117);
    }
}



// Code for subs4q

static LispObject CC_subs4q(LispObject env,
                         LispObject v_13104)
{
    env = qenv(env);
    LispObject v_13250, v_13251, v_13252;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13104);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_13104;
// end of prologue
    stack[-3] = nil;
    stack[-2] = nil;
    v_13250 = elt(env, 1); // slash
    if (!symbolp(v_13250)) v_13250 = nil;
    else { v_13250 = qfastgets(v_13250);
           if (v_13250 != nil) { v_13250 = elt(v_13250, 9); // opmtch
#ifdef RECORD_GET
             if (v_13250 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_13250 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_13250 == SPID_NOPROP) v_13250 = nil; }}
#endif
    stack[-6] = v_13250;
    if (v_13250 == nil) goto v_13114;
    else goto v_13115;
v_13114:
    v_13250 = stack[-5];
    goto v_13111;
v_13115:
    v_13250 = stack[-5];
    fn = elt(env, 6); // prepsq
    v_13250 = (*qfn1(fn))(fn, v_13250);
    env = stack[-7];
    stack[-4] = v_13250;
    goto v_13126;
v_13122:
    v_13251 = elt(env, 1); // slash
    goto v_13123;
v_13124:
    v_13250 = elt(env, 2); // opmtch
    goto v_13125;
v_13126:
    goto v_13122;
v_13123:
    goto v_13124;
v_13125:
    v_13250 = Lremprop(nil, v_13251, v_13250);
    env = stack[-7];
    goto v_13136;
v_13130:
    v_13252 = elt(env, 3); // slash!*
    goto v_13131;
v_13132:
    v_13251 = elt(env, 2); // opmtch
    goto v_13133;
v_13134:
    v_13250 = stack[-6];
    goto v_13135;
v_13136:
    goto v_13130;
v_13131:
    goto v_13132;
v_13133:
    goto v_13134;
v_13135:
    v_13250 = Lputprop(nil, 3, v_13252, v_13251, v_13250);
    env = stack[-7];
v_13142:
    v_13250 = stack[-4];
    if (v_13250 == nil) goto v_13145;
    goto v_13155;
v_13151:
    v_13251 = stack[-4];
    stack[-3] = v_13251;
    goto v_13152;
v_13153:
    v_13250 = elt(env, 4); // quotient
    goto v_13154;
v_13155:
    goto v_13151;
v_13152:
    goto v_13153;
v_13154:
    if (!consp(v_13251)) goto v_13145;
    v_13251 = qcar(v_13251);
    if (v_13251 == v_13250) goto v_13149;
    else goto v_13145;
v_13149:
    goto v_13146;
v_13145:
    goto v_13141;
v_13146:
    goto v_13168;
v_13164:
    v_13251 = elt(env, 3); // slash!*
    goto v_13165;
v_13166:
    v_13250 = stack[-4];
    v_13250 = qcdr(v_13250);
    goto v_13167;
v_13168:
    goto v_13164;
v_13165:
    goto v_13166;
v_13167:
    v_13250 = cons(v_13251, v_13250);
    env = stack[-7];
    fn = elt(env, 2); // opmtch
    v_13250 = (*qfn1(fn))(fn, v_13250);
    env = stack[-7];
    if (v_13250 == nil) goto v_13161;
    else goto v_13160;
v_13161:
    goto v_13181;
v_13177:
    v_13251 = elt(env, 5); // minus
    goto v_13178;
v_13179:
    v_13250 = stack[-4];
    v_13250 = qcdr(v_13250);
    v_13250 = qcdr(v_13250);
    v_13250 = qcar(v_13250);
    goto v_13180;
v_13181:
    goto v_13177;
v_13178:
    goto v_13179;
v_13180:
    v_13250 = Lsmemq(nil, v_13251, v_13250);
    env = stack[-7];
    if (v_13250 == nil) goto v_13174;
    else goto v_13175;
v_13174:
    v_13250 = nil;
    goto v_13173;
v_13175:
    goto v_13198;
v_13192:
    stack[-1] = elt(env, 3); // slash!*
    goto v_13193;
v_13194:
    goto v_13206;
v_13202:
    v_13251 = elt(env, 5); // minus
    goto v_13203;
v_13204:
    v_13250 = stack[-4];
    v_13250 = qcdr(v_13250);
    v_13250 = qcar(v_13250);
    goto v_13205;
v_13206:
    goto v_13202;
v_13203:
    goto v_13204;
v_13205:
    v_13250 = list2(v_13251, v_13250);
    env = stack[-7];
    fn = elt(env, 7); // reval
    stack[0] = (*qfn1(fn))(fn, v_13250);
    env = stack[-7];
    goto v_13195;
v_13196:
    goto v_13217;
v_13213:
    v_13251 = elt(env, 5); // minus
    goto v_13214;
v_13215:
    v_13250 = stack[-4];
    v_13250 = qcdr(v_13250);
    v_13250 = qcdr(v_13250);
    v_13250 = qcar(v_13250);
    goto v_13216;
v_13217:
    goto v_13213;
v_13214:
    goto v_13215;
v_13216:
    v_13250 = list2(v_13251, v_13250);
    env = stack[-7];
    fn = elt(env, 7); // reval
    v_13250 = (*qfn1(fn))(fn, v_13250);
    env = stack[-7];
    goto v_13197;
v_13198:
    goto v_13192;
v_13193:
    goto v_13194;
v_13195:
    goto v_13196;
v_13197:
    v_13250 = list3(stack[-1], stack[0], v_13250);
    env = stack[-7];
    fn = elt(env, 2); // opmtch
    v_13250 = (*qfn1(fn))(fn, v_13250);
    env = stack[-7];
    goto v_13173;
    v_13250 = nil;
v_13173:
v_13160:
    stack[-4] = v_13250;
    v_13250 = stack[-2];
    if (v_13250 == nil) goto v_13225;
    else goto v_13224;
v_13225:
    v_13250 = stack[-4];
v_13224:
    stack[-2] = v_13250;
    goto v_13142;
v_13141:
    v_13250 = stack[-2];
    if (v_13250 == nil) goto v_13231;
    v_13250 = stack[-3];
    fn = elt(env, 8); // simp!*
    v_13250 = (*qfn1(fn))(fn, v_13250);
    env = stack[-7];
    goto v_13229;
v_13231:
    v_13250 = stack[-5];
    goto v_13229;
    v_13250 = nil;
v_13229:
    stack[-5] = v_13250;
    goto v_13245;
v_13239:
    v_13252 = elt(env, 1); // slash
    goto v_13240;
v_13241:
    v_13251 = elt(env, 2); // opmtch
    goto v_13242;
v_13243:
    v_13250 = stack[-6];
    goto v_13244;
v_13245:
    goto v_13239;
v_13240:
    goto v_13241;
v_13242:
    goto v_13243;
v_13244:
    v_13250 = Lputprop(nil, 3, v_13252, v_13251, v_13250);
    v_13250 = stack[-5];
v_13111:
    return onevalue(v_13250);
}



// Code for xregister_wedge_pair

static LispObject CC_xregister_wedge_pair(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13106;
    argcheck(nargs, 0, "xregister_wedge_pair");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_13106 = nil;
    return onevalue(v_13106);
}



// Code for total!-degree!-in!-powers

static LispObject CC_totalKdegreeKinKpowers(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13218, v_13219, v_13220;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13104,v_13105);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13105;
    stack[-1] = v_13104;
// end of prologue
v_13103:
    v_13218 = stack[-1];
    if (v_13218 == nil) goto v_13113;
    else goto v_13114;
v_13113:
    v_13218 = lisp_true;
    goto v_13112;
v_13114:
    v_13218 = stack[-1];
    if (!consp(v_13218)) goto v_13121;
    else goto v_13122;
v_13121:
    v_13218 = lisp_true;
    goto v_13120;
v_13122:
    v_13218 = stack[-1];
    v_13218 = qcar(v_13218);
    v_13218 = (consp(v_13218) ? nil : lisp_true);
    goto v_13120;
    v_13218 = nil;
v_13120:
    goto v_13112;
    v_13218 = nil;
v_13112:
    if (v_13218 == nil) goto v_13110;
    v_13218 = stack[0];
    goto v_13108;
v_13110:
    goto v_13144;
v_13140:
    v_13218 = stack[-1];
    v_13218 = qcar(v_13218);
    v_13218 = qcar(v_13218);
    v_13219 = qcar(v_13218);
    goto v_13141;
v_13142:
    v_13218 = stack[0];
    goto v_13143;
v_13144:
    goto v_13140;
v_13141:
    goto v_13142;
v_13143:
    v_13218 = Latsoc(nil, v_13219, v_13218);
    stack[-2] = v_13218;
    if (v_13218 == nil) goto v_13139;
    goto v_13160;
v_13156:
    v_13218 = stack[-1];
    v_13218 = qcar(v_13218);
    v_13218 = qcar(v_13218);
    v_13219 = qcdr(v_13218);
    goto v_13157;
v_13158:
    v_13218 = stack[-2];
    v_13218 = qcdr(v_13218);
    goto v_13159;
v_13160:
    goto v_13156;
v_13157:
    goto v_13158;
v_13159:
    v_13218 = (LispObject)greaterp2(v_13219, v_13218);
    v_13218 = v_13218 ? lisp_true : nil;
    env = stack[-3];
    if (v_13218 == nil) goto v_13153;
    else goto v_13154;
v_13153:
    goto v_13152;
v_13154:
    goto v_13175;
v_13171:
    v_13219 = stack[-2];
    goto v_13172;
v_13173:
    v_13218 = stack[-1];
    v_13218 = qcar(v_13218);
    v_13218 = qcar(v_13218);
    v_13218 = qcdr(v_13218);
    goto v_13174;
v_13175:
    goto v_13171;
v_13172:
    goto v_13173;
v_13174:
    v_13218 = Lrplacd(nil, v_13219, v_13218);
    env = stack[-3];
    goto v_13152;
v_13152:
    goto v_13137;
v_13139:
    goto v_13190;
v_13184:
    v_13218 = stack[-1];
    v_13218 = qcar(v_13218);
    v_13218 = qcar(v_13218);
    v_13220 = qcar(v_13218);
    goto v_13185;
v_13186:
    v_13218 = stack[-1];
    v_13218 = qcar(v_13218);
    v_13218 = qcar(v_13218);
    v_13219 = qcdr(v_13218);
    goto v_13187;
v_13188:
    v_13218 = stack[0];
    goto v_13189;
v_13190:
    goto v_13184;
v_13185:
    goto v_13186;
v_13187:
    goto v_13188;
v_13189:
    v_13218 = acons(v_13220, v_13219, v_13218);
    env = stack[-3];
    stack[0] = v_13218;
    goto v_13137;
v_13137:
    goto v_13205;
v_13201:
    v_13218 = stack[-1];
    stack[-2] = qcdr(v_13218);
    goto v_13202;
v_13203:
    goto v_13213;
v_13209:
    v_13218 = stack[-1];
    v_13218 = qcar(v_13218);
    v_13219 = qcdr(v_13218);
    goto v_13210;
v_13211:
    v_13218 = stack[0];
    goto v_13212;
v_13213:
    goto v_13209;
v_13210:
    goto v_13211;
v_13212:
    v_13218 = CC_totalKdegreeKinKpowers(elt(env, 0), v_13219, v_13218);
    env = stack[-3];
    goto v_13204;
v_13205:
    goto v_13201;
v_13202:
    goto v_13203;
v_13204:
    stack[-1] = stack[-2];
    stack[0] = v_13218;
    goto v_13103;
    goto v_13108;
    v_13218 = nil;
v_13108:
    return onevalue(v_13218);
}



// Code for putd

static LispObject CC_putd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13283, v_13284, v_13285;
    LispObject fn;
    LispObject v_13106, v_13105, v_13104;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "putd");
    va_start(aa, nargs);
    v_13104 = va_arg(aa, LispObject);
    v_13105 = va_arg(aa, LispObject);
    v_13106 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13106,v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13104,v_13105,v_13106);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13106;
    stack[-1] = v_13105;
    stack[-2] = v_13104;
// end of prologue
    goto v_13117;
v_13113:
    v_13284 = stack[0];
    goto v_13114;
v_13115:
    v_13283 = elt(env, 1); // funarg
    goto v_13116;
v_13117:
    goto v_13113;
v_13114:
    goto v_13115;
v_13116:
    if (!consp(v_13284)) goto v_13111;
    v_13284 = qcar(v_13284);
    if (v_13284 == v_13283) goto v_13110;
    else goto v_13111;
v_13110:
    goto v_13125;
v_13121:
    v_13284 = elt(env, 2); // lambda
    goto v_13122;
v_13123:
    v_13283 = stack[0];
    v_13283 = qcdr(v_13283);
    v_13283 = qcdr(v_13283);
    goto v_13124;
v_13125:
    goto v_13121;
v_13122:
    goto v_13123;
v_13124:
    v_13283 = cons(v_13284, v_13283);
    env = stack[-3];
    stack[0] = v_13283;
    goto v_13109;
v_13111:
v_13109:
    v_13283 = stack[-2];
    if (!symbolp(v_13283)) v_13283 = nil;
    else { v_13283 = qfastgets(v_13283);
           if (v_13283 != nil) { v_13283 = elt(v_13283, 1); // lose
#ifdef RECORD_GET
             if (v_13283 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v_13283 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v_13283 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v_13283 == SPID_NOPROP) v_13283 = nil; else v_13283 = lisp_true; }}
#endif
    if (v_13283 == nil) goto v_13133;
    v_13283 = Lterpri(nil, 0);
    env = stack[-3];
    v_13283 = elt(env, 3); // "+++ "
    v_13283 = Lprinc(nil, v_13283);
    env = stack[-3];
    v_13283 = stack[-2];
    v_13283 = Lprin(nil, v_13283);
    env = stack[-3];
    v_13283 = elt(env, 4); // " not defined (LOSE flag)"
    v_13283 = Lprintc(nil, v_13283);
    v_13283 = nil;
    goto v_13131;
v_13133:
    v_13283 = qvalue(elt(env, 5)); // !*redefmsg
    if (v_13283 == nil) goto v_13149;
    v_13283 = stack[-2];
    fn = elt(env, 14); // getd
    v_13283 = (*qfn1(fn))(fn, v_13283);
    env = stack[-3];
    if (v_13283 == nil) goto v_13149;
    v_13283 = Lterpri(nil, 0);
    env = stack[-3];
    v_13283 = elt(env, 3); // "+++ "
    v_13283 = Lprinc(nil, v_13283);
    env = stack[-3];
    v_13283 = stack[-2];
    v_13283 = Lprin(nil, v_13283);
    env = stack[-3];
    v_13283 = elt(env, 6); // " redefined"
    v_13283 = Lprintc(nil, v_13283);
    env = stack[-3];
    goto v_13147;
v_13149:
v_13147:
    goto v_13170;
v_13166:
    v_13284 = stack[-1];
    goto v_13167;
v_13168:
    v_13283 = elt(env, 7); // expr
    goto v_13169;
v_13170:
    goto v_13166;
v_13167:
    goto v_13168;
v_13169:
    if (v_13284 == v_13283) goto v_13164;
    else goto v_13165;
v_13164:
    goto v_13178;
v_13174:
    v_13284 = stack[-2];
    goto v_13175;
v_13176:
    v_13283 = stack[0];
    goto v_13177;
v_13178:
    goto v_13174;
v_13175:
    goto v_13176;
v_13177:
    v_13283 = Lsymbol_set_definition(nil, v_13284, v_13283);
    goto v_13163;
v_13165:
    goto v_13187;
v_13183:
    v_13284 = stack[-1];
    goto v_13184;
v_13185:
    v_13283 = elt(env, 8); // subr
    goto v_13186;
v_13187:
    goto v_13183;
v_13184:
    goto v_13185;
v_13186:
    if (v_13284 == v_13283) goto v_13181;
    else goto v_13182;
v_13181:
    goto v_13195;
v_13191:
    v_13284 = stack[-2];
    goto v_13192;
v_13193:
    v_13283 = stack[0];
    goto v_13194;
v_13195:
    goto v_13191;
v_13192:
    goto v_13193;
v_13194:
    v_13283 = Lsymbol_set_definition(nil, v_13284, v_13283);
    goto v_13163;
v_13182:
    goto v_13208;
v_13204:
    v_13284 = stack[-1];
    goto v_13205;
v_13206:
    v_13283 = elt(env, 9); // macro
    goto v_13207;
v_13208:
    goto v_13204;
v_13205:
    goto v_13206;
v_13207:
    if (v_13284 == v_13283) goto v_13202;
    else goto v_13203;
v_13202:
    goto v_13216;
v_13212:
    v_13284 = stack[0];
    goto v_13213;
v_13214:
    v_13283 = elt(env, 2); // lambda
    goto v_13215;
v_13216:
    goto v_13212;
v_13213:
    goto v_13214;
v_13215:
    v_13283 = Leqcar(nil, v_13284, v_13283);
    env = stack[-3];
    goto v_13201;
v_13203:
    v_13283 = nil;
    goto v_13201;
    v_13283 = nil;
v_13201:
    if (v_13283 == nil) goto v_13199;
    goto v_13230;
v_13224:
    v_13285 = elt(env, 10); // dm
    goto v_13225;
v_13226:
    v_13284 = stack[-2];
    goto v_13227;
v_13228:
    v_13283 = stack[0];
    v_13283 = qcdr(v_13283);
    goto v_13229;
v_13230:
    goto v_13224;
v_13225:
    goto v_13226;
v_13227:
    goto v_13228;
v_13229:
    v_13283 = list2star(v_13285, v_13284, v_13283);
    env = stack[-3];
    fn = elt(env, 15); // eval
    v_13283 = (*qfn1(fn))(fn, v_13283);
    goto v_13163;
v_13199:
    goto v_13245;
v_13241:
    v_13284 = stack[-1];
    goto v_13242;
v_13243:
    v_13283 = elt(env, 11); // fexpr
    goto v_13244;
v_13245:
    goto v_13241;
v_13242:
    goto v_13243;
v_13244:
    if (v_13284 == v_13283) goto v_13239;
    else goto v_13240;
v_13239:
    goto v_13253;
v_13249:
    v_13284 = stack[0];
    goto v_13250;
v_13251:
    v_13283 = elt(env, 2); // lambda
    goto v_13252;
v_13253:
    goto v_13249;
v_13250:
    goto v_13251;
v_13252:
    v_13283 = Leqcar(nil, v_13284, v_13283);
    env = stack[-3];
    goto v_13238;
v_13240:
    v_13283 = nil;
    goto v_13238;
    v_13283 = nil;
v_13238:
    if (v_13283 == nil) goto v_13236;
    goto v_13267;
v_13261:
    v_13285 = elt(env, 12); // df
    goto v_13262;
v_13263:
    v_13284 = stack[-2];
    goto v_13264;
v_13265:
    v_13283 = stack[0];
    v_13283 = qcdr(v_13283);
    goto v_13266;
v_13267:
    goto v_13261;
v_13262:
    goto v_13263;
v_13264:
    goto v_13265;
v_13266:
    v_13283 = list2star(v_13285, v_13284, v_13283);
    env = stack[-3];
    fn = elt(env, 15); // eval
    v_13283 = (*qfn1(fn))(fn, v_13283);
    goto v_13163;
v_13236:
    goto v_13279;
v_13275:
    v_13284 = elt(env, 13); // "Bad type ~S in putd"
    goto v_13276;
v_13277:
    v_13283 = stack[-1];
    goto v_13278;
v_13279:
    goto v_13275;
v_13276:
    goto v_13277;
v_13278:
    fn = elt(env, 16); // error
    v_13283 = (*qfn2(fn))(fn, v_13284, v_13283);
    goto v_13163;
v_13163:
    v_13283 = stack[-2];
    goto v_13131;
    v_13283 = nil;
v_13131:
    return onevalue(v_13283);
}



// Code for setel

static LispObject CC_setel(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13163, v_13164, v_13165, v_13166;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13104,v_13105);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_13105;
    stack[-2] = v_13104;
// end of prologue
    goto v_13112;
v_13108:
    v_13163 = stack[-2];
    v_13164 = qcar(v_13163);
    goto v_13109;
v_13110:
    v_13163 = elt(env, 1); // dimension
    goto v_13111;
v_13112:
    goto v_13108;
v_13109:
    goto v_13110;
v_13111:
    v_13163 = get(v_13164, v_13163);
    env = stack[-4];
    stack[-3] = v_13163;
    goto v_13125;
v_13121:
    v_13163 = stack[-3];
    stack[0] = Llength(nil, v_13163);
    env = stack[-4];
    goto v_13122;
v_13123:
    v_13163 = stack[-2];
    v_13163 = qcdr(v_13163);
    v_13163 = Llength(nil, v_13163);
    env = stack[-4];
    goto v_13124;
v_13125:
    goto v_13121;
v_13122:
    goto v_13123;
v_13124:
    if (equal(stack[0], v_13163)) goto v_13120;
    goto v_13138;
v_13132:
    v_13165 = elt(env, 2); // rlisp
    goto v_13133;
v_13134:
    v_13164 = (LispObject)352+TAG_FIXNUM; // 22
    goto v_13135;
v_13136:
    v_13163 = elt(env, 3); // "Incorrect array reference"
    goto v_13137;
v_13138:
    goto v_13132;
v_13133:
    goto v_13134;
v_13135:
    goto v_13136;
v_13137:
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_13165, v_13164, v_13163);
    }
v_13120:
    goto v_13153;
v_13145:
    v_13163 = stack[-2];
    v_13163 = qcar(v_13163);
    if (!symbolp(v_13163)) v_13163 = nil;
    else { v_13163 = qfastgets(v_13163);
           if (v_13163 != nil) { v_13163 = elt(v_13163, 4); // avalue
#ifdef RECORD_GET
             if (v_13163 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_13163 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_13163 == SPID_NOPROP) v_13163 = nil; }}
#endif
    v_13163 = qcdr(v_13163);
    v_13166 = qcar(v_13163);
    goto v_13146;
v_13147:
    v_13163 = stack[-2];
    v_13165 = qcdr(v_13163);
    goto v_13148;
v_13149:
    v_13164 = stack[-1];
    goto v_13150;
v_13151:
    v_13163 = stack[-3];
    goto v_13152;
v_13153:
    goto v_13145;
v_13146:
    goto v_13147;
v_13148:
    goto v_13149;
v_13150:
    goto v_13151;
v_13152:
    {
        fn = elt(env, 5); // setel1
        return (*qfnn(fn))(fn, 4, v_13166, v_13165, v_13164, v_13163);
    }
    v_13163 = nil;
    return onevalue(v_13163);
}



// Code for fs!:prin1

static LispObject CC_fsTprin1(LispObject env,
                         LispObject v_13104)
{
    env = qenv(env);
    LispObject v_13274, v_13275;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13104);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_13104;
// end of prologue
    v_13274 = lisp_true;
    stack[-3] = v_13274;
    goto v_13120;
v_13116:
    goto v_13125;
v_13121:
    v_13275 = stack[0];
    goto v_13122;
v_13123:
    v_13274 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13124;
v_13125:
    goto v_13121;
v_13122:
    goto v_13123;
v_13124:
    v_13275 = *(LispObject *)((char *)v_13275 + (CELL-TAG_VECTOR) + (((intptr_t)v_13274-TAG_FIXNUM)/(16/CELL)));
    goto v_13117;
v_13118:
    v_13274 = elt(env, 1); // (1 . 1)
    goto v_13119;
v_13120:
    goto v_13116;
v_13117:
    goto v_13118;
v_13119:
    if (equal(v_13275, v_13274)) goto v_13115;
    v_13274 = elt(env, 2); // "("
    fn = elt(env, 10); // prin2!*
    v_13274 = (*qfn1(fn))(fn, v_13274);
    env = stack[-4];
    goto v_13137;
v_13133:
    v_13275 = stack[0];
    goto v_13134;
v_13135:
    v_13274 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13136;
v_13137:
    goto v_13133;
v_13134:
    goto v_13135;
v_13136:
    v_13274 = *(LispObject *)((char *)v_13275 + (CELL-TAG_VECTOR) + (((intptr_t)v_13274-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 11); // sqprint
    v_13274 = (*qfn1(fn))(fn, v_13274);
    env = stack[-4];
    v_13274 = elt(env, 3); // ")"
    fn = elt(env, 10); // prin2!*
    v_13274 = (*qfn1(fn))(fn, v_13274);
    env = stack[-4];
    goto v_13113;
v_13115:
v_13113:
    v_13274 = stack[0];
    fn = elt(env, 12); // fs!:null!-angle
    v_13274 = (*qfn1(fn))(fn, v_13274);
    env = stack[-4];
    if (v_13274 == nil) goto v_13145;
    else goto v_13146;
v_13145:
    goto v_13154;
v_13150:
    v_13275 = stack[0];
    goto v_13151;
v_13152:
    v_13274 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13153;
v_13154:
    goto v_13150;
v_13151:
    goto v_13152;
v_13153:
    v_13274 = *(LispObject *)((char *)v_13275 + (CELL-TAG_VECTOR) + (((intptr_t)v_13274-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 10); // prin2!*
    v_13274 = (*qfn1(fn))(fn, v_13274);
    env = stack[-4];
    v_13274 = elt(env, 4); // "["
    fn = elt(env, 10); // prin2!*
    v_13274 = (*qfn1(fn))(fn, v_13274);
    env = stack[-4];
    goto v_13164;
v_13160:
    v_13275 = stack[0];
    goto v_13161;
v_13162:
    v_13274 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13163;
v_13164:
    goto v_13160;
v_13161:
    goto v_13162;
v_13163:
    v_13274 = *(LispObject *)((char *)v_13275 + (CELL-TAG_VECTOR) + (((intptr_t)v_13274-TAG_FIXNUM)/(16/CELL)));
    stack[-2] = v_13274;
    v_13274 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_13274;
v_13171:
    goto v_13183;
v_13179:
    v_13275 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_13180;
v_13181:
    v_13274 = stack[0];
    goto v_13182;
v_13183:
    goto v_13179;
v_13180:
    goto v_13181;
v_13182:
    v_13274 = difference2(v_13275, v_13274);
    env = stack[-4];
    v_13274 = Lminusp(nil, v_13274);
    env = stack[-4];
    if (v_13274 == nil) goto v_13176;
    goto v_13170;
v_13176:
    goto v_13195;
v_13191:
    goto v_13200;
v_13196:
    v_13275 = stack[-2];
    goto v_13197;
v_13198:
    v_13274 = stack[0];
    goto v_13199;
v_13200:
    goto v_13196;
v_13197:
    goto v_13198;
v_13199:
    v_13275 = *(LispObject *)((char *)v_13275 + (CELL-TAG_VECTOR) + (((intptr_t)v_13274-TAG_FIXNUM)/(16/CELL)));
    stack[-1] = v_13275;
    goto v_13192;
v_13193:
    v_13274 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13194;
v_13195:
    goto v_13191;
v_13192:
    goto v_13193;
v_13194:
    if (v_13275 == v_13274) goto v_13190;
    goto v_13214;
v_13210:
    v_13275 = stack[-1];
    goto v_13211;
v_13212:
    v_13274 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13213;
v_13214:
    goto v_13210;
v_13211:
    goto v_13212;
v_13213:
    v_13274 = (LispObject)lessp2(v_13275, v_13274);
    v_13274 = v_13274 ? lisp_true : nil;
    env = stack[-4];
    if (v_13274 == nil) goto v_13208;
    v_13274 = lisp_true;
    stack[-3] = v_13274;
    v_13274 = elt(env, 5); // "-"
    fn = elt(env, 10); // prin2!*
    v_13274 = (*qfn1(fn))(fn, v_13274);
    env = stack[-4];
    v_13274 = stack[-1];
    v_13274 = negate(v_13274);
    env = stack[-4];
    stack[-1] = v_13274;
    goto v_13206;
v_13208:
v_13206:
    v_13274 = stack[-3];
    if (v_13274 == nil) goto v_13224;
    else goto v_13225;
v_13224:
    v_13274 = elt(env, 6); // "+"
    fn = elt(env, 10); // prin2!*
    v_13274 = (*qfn1(fn))(fn, v_13274);
    env = stack[-4];
    goto v_13223;
v_13225:
v_13223:
    goto v_13237;
v_13233:
    v_13275 = stack[-1];
    goto v_13234;
v_13235:
    v_13274 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13236;
v_13237:
    goto v_13233;
v_13234:
    goto v_13235;
v_13236:
    if (v_13275 == v_13274) goto v_13232;
    v_13274 = stack[-1];
    fn = elt(env, 10); // prin2!*
    v_13274 = (*qfn1(fn))(fn, v_13274);
    env = stack[-4];
    goto v_13230;
v_13232:
v_13230:
    v_13274 = nil;
    stack[-3] = v_13274;
    goto v_13248;
v_13244:
    v_13275 = qvalue(elt(env, 7)); // fourier!-name!*
    goto v_13245;
v_13246:
    v_13274 = stack[0];
    goto v_13247;
v_13248:
    goto v_13244;
v_13245:
    goto v_13246;
v_13247:
    v_13274 = *(LispObject *)((char *)v_13275 + (CELL-TAG_VECTOR) + (((intptr_t)v_13274-TAG_FIXNUM)/(16/CELL)));
    fn = elt(env, 10); // prin2!*
    v_13274 = (*qfn1(fn))(fn, v_13274);
    env = stack[-4];
    goto v_13188;
v_13190:
v_13188:
    v_13274 = stack[0];
    v_13274 = add1(v_13274);
    env = stack[-4];
    stack[0] = v_13274;
    goto v_13171;
v_13170:
    v_13274 = elt(env, 8); // "]"
    fn = elt(env, 10); // prin2!*
    v_13274 = (*qfn1(fn))(fn, v_13274);
    goto v_13144;
v_13146:
    goto v_13262;
v_13258:
    goto v_13267;
v_13263:
    v_13275 = stack[0];
    goto v_13264;
v_13265:
    v_13274 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13266;
v_13267:
    goto v_13263;
v_13264:
    goto v_13265;
v_13266:
    v_13275 = *(LispObject *)((char *)v_13275 + (CELL-TAG_VECTOR) + (((intptr_t)v_13274-TAG_FIXNUM)/(16/CELL)));
    goto v_13259;
v_13260:
    v_13274 = elt(env, 1); // (1 . 1)
    goto v_13261;
v_13262:
    goto v_13258;
v_13259:
    goto v_13260;
v_13261:
    if (equal(v_13275, v_13274)) goto v_13256;
    else goto v_13257;
v_13256:
    v_13274 = elt(env, 9); // "1"
    fn = elt(env, 10); // prin2!*
    v_13274 = (*qfn1(fn))(fn, v_13274);
    goto v_13144;
v_13257:
v_13144:
    v_13274 = nil;
    return onevalue(v_13274);
}



// Code for st_sorttree

static LispObject CC_st_sorttree(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13120, v_13121, v_13122;
    LispObject fn;
    LispObject v_13106, v_13105, v_13104;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "st_sorttree");
    va_start(aa, nargs);
    v_13104 = va_arg(aa, LispObject);
    v_13105 = va_arg(aa, LispObject);
    v_13106 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13106,v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13104,v_13105,v_13106);
    }
// copy arguments values to proper place
    v_13120 = v_13106;
    v_13121 = v_13105;
    v_13122 = v_13104;
// end of prologue
    goto v_13115;
v_13109:
    goto v_13110;
v_13111:
    goto v_13112;
v_13113:
    goto v_13114;
v_13115:
    goto v_13109;
v_13110:
    goto v_13111;
v_13112:
    goto v_13113;
v_13114:
    fn = elt(env, 1); // st_sorttree1
    v_13120 = (*qfnn(fn))(fn, 3, v_13122, v_13121, v_13120);
    v_13120 = qcdr(v_13120);
    return onevalue(v_13120);
}



// Code for general!-modular!-expt

static LispObject CC_generalKmodularKexpt(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13272, v_13273, v_13274;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13104,v_13105);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13105;
    stack[-1] = v_13104;
// end of prologue
v_13109:
    goto v_13118;
v_13114:
    v_13273 = stack[-1];
    goto v_13115;
v_13116:
    v_13272 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13117;
v_13118:
    goto v_13114;
v_13115:
    goto v_13116;
v_13117:
    if (v_13273 == v_13272) goto v_13112;
    else goto v_13113;
v_13112:
    goto v_13129;
v_13125:
    v_13273 = stack[0];
    goto v_13126;
v_13127:
    v_13272 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13128;
v_13129:
    goto v_13125;
v_13126:
    goto v_13127;
v_13128:
    if (v_13273 == v_13272) goto v_13123;
    else goto v_13124;
v_13123:
    goto v_13139;
v_13133:
    v_13274 = elt(env, 1); // alg
    goto v_13134;
v_13135:
    v_13273 = (LispObject)1616+TAG_FIXNUM; // 101
    goto v_13136;
v_13137:
    v_13272 = elt(env, 2); // "0^0 formed"
    goto v_13138;
v_13139:
    goto v_13133;
v_13134:
    goto v_13135;
v_13136:
    goto v_13137;
v_13138:
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_13274, v_13273, v_13272);
    }
v_13124:
    v_13272 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13108;
    goto v_13111;
v_13113:
    goto v_13152;
v_13148:
    v_13273 = stack[0];
    goto v_13149;
v_13150:
    v_13272 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13151;
v_13152:
    goto v_13148;
v_13149:
    goto v_13150;
v_13151:
    if (v_13273 == v_13272) goto v_13146;
    else goto v_13147;
v_13146:
    v_13272 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13108;
v_13147:
    goto v_13162;
v_13158:
    v_13273 = stack[0];
    goto v_13159;
v_13160:
    v_13272 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13161;
v_13162:
    goto v_13158;
v_13159:
    goto v_13160;
v_13161:
    if (v_13273 == v_13272) goto v_13156;
    else goto v_13157;
v_13156:
    v_13272 = stack[-1];
    goto v_13108;
v_13157:
    goto v_13174;
v_13170:
    stack[-2] = stack[0];
    goto v_13171;
v_13172:
    v_13272 = qvalue(elt(env, 3)); // current!-modulus
    v_13272 = sub1(v_13272);
    env = stack[-3];
    goto v_13173;
v_13174:
    goto v_13170;
v_13171:
    goto v_13172;
v_13173:
    v_13272 = (LispObject)geq2(stack[-2], v_13272);
    v_13272 = v_13272 ? lisp_true : nil;
    env = stack[-3];
    if (v_13272 == nil) goto v_13167;
    v_13272 = qvalue(elt(env, 3)); // current!-modulus
    fn = elt(env, 5); // primep
    v_13272 = (*qfn1(fn))(fn, v_13272);
    env = stack[-3];
    if (v_13272 == nil) goto v_13167;
    goto v_13186;
v_13182:
    goto v_13183;
v_13184:
    v_13272 = qvalue(elt(env, 3)); // current!-modulus
    v_13272 = sub1(v_13272);
    env = stack[-3];
    goto v_13185;
v_13186:
    goto v_13182;
v_13183:
    goto v_13184;
v_13185:
    v_13272 = Cremainder(stack[0], v_13272);
    env = stack[-3];
    stack[0] = v_13272;
    goto v_13109;
v_13167:
v_13198:
    v_13272 = stack[0];
    v_13272 = Levenp(nil, v_13272);
    env = stack[-3];
    if (v_13272 == nil) goto v_13201;
    else goto v_13202;
v_13201:
    goto v_13197;
v_13202:
    goto v_13211;
v_13207:
    v_13273 = stack[0];
    goto v_13208;
v_13209:
    v_13272 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13210;
v_13211:
    goto v_13207;
v_13208:
    goto v_13209;
v_13210:
    v_13272 = quot2(v_13273, v_13272);
    env = stack[-3];
    stack[0] = v_13272;
    goto v_13219;
v_13215:
    v_13273 = stack[-1];
    goto v_13216;
v_13217:
    v_13272 = stack[-1];
    goto v_13218;
v_13219:
    goto v_13215;
v_13216:
    goto v_13217;
v_13218:
    fn = elt(env, 6); // general!-modular!-times
    v_13272 = (*qfn2(fn))(fn, v_13273, v_13272);
    env = stack[-3];
    stack[-1] = v_13272;
    goto v_13198;
v_13197:
    v_13272 = stack[0];
    fn = elt(env, 7); // reverse!-num
    v_13272 = (*qfn1(fn))(fn, v_13272);
    env = stack[-3];
    stack[0] = v_13272;
    v_13272 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_13272;
v_13227:
    goto v_13237;
v_13233:
    v_13273 = stack[0];
    goto v_13234;
v_13235:
    v_13272 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13236;
v_13237:
    goto v_13233;
v_13234:
    goto v_13235;
v_13236:
    v_13272 = (LispObject)greaterp2(v_13273, v_13272);
    v_13272 = v_13272 ? lisp_true : nil;
    env = stack[-3];
    if (v_13272 == nil) goto v_13230;
    else goto v_13231;
v_13230:
    goto v_13226;
v_13231:
    goto v_13246;
v_13242:
    v_13273 = stack[-2];
    goto v_13243;
v_13244:
    v_13272 = stack[-2];
    goto v_13245;
v_13246:
    goto v_13242;
v_13243:
    goto v_13244;
v_13245:
    fn = elt(env, 6); // general!-modular!-times
    v_13272 = (*qfn2(fn))(fn, v_13273, v_13272);
    env = stack[-3];
    stack[-2] = v_13272;
    v_13272 = stack[0];
    v_13272 = Levenp(nil, v_13272);
    env = stack[-3];
    if (v_13272 == nil) goto v_13251;
    else goto v_13252;
v_13251:
    goto v_13260;
v_13256:
    v_13273 = stack[-2];
    goto v_13257;
v_13258:
    v_13272 = stack[-1];
    goto v_13259;
v_13260:
    goto v_13256;
v_13257:
    goto v_13258;
v_13259:
    fn = elt(env, 6); // general!-modular!-times
    v_13272 = (*qfn2(fn))(fn, v_13273, v_13272);
    env = stack[-3];
    stack[-2] = v_13272;
    goto v_13250;
v_13252:
v_13250:
    goto v_13268;
v_13264:
    v_13273 = stack[0];
    goto v_13265;
v_13266:
    v_13272 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_13267;
v_13268:
    goto v_13264;
v_13265:
    goto v_13266;
v_13267:
    v_13272 = quot2(v_13273, v_13272);
    env = stack[-3];
    stack[0] = v_13272;
    goto v_13227;
v_13226:
    v_13272 = stack[-2];
    goto v_13108;
v_13111:
    v_13272 = nil;
v_13108:
    return onevalue(v_13272);
}



// Code for ctx_idl

static LispObject CC_ctx_idl(LispObject env,
                         LispObject v_13104)
{
    env = qenv(env);
    LispObject v_13149;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13104);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_13149 = v_13104;
// end of prologue
    fn = elt(env, 1); // ctx_ial
    v_13149 = (*qfn1(fn))(fn, v_13149);
    env = stack[-4];
    stack[-3] = v_13149;
    v_13149 = stack[-3];
    if (v_13149 == nil) goto v_13116;
    else goto v_13117;
v_13116:
    v_13149 = nil;
    goto v_13110;
v_13117:
    v_13149 = stack[-3];
    v_13149 = qcar(v_13149);
    v_13149 = qcar(v_13149);
    v_13149 = ncons(v_13149);
    env = stack[-4];
    stack[-1] = v_13149;
    stack[-2] = v_13149;
v_13111:
    v_13149 = stack[-3];
    v_13149 = qcdr(v_13149);
    stack[-3] = v_13149;
    v_13149 = stack[-3];
    if (v_13149 == nil) goto v_13130;
    else goto v_13131;
v_13130:
    v_13149 = stack[-2];
    goto v_13110;
v_13131:
    goto v_13139;
v_13135:
    stack[0] = stack[-1];
    goto v_13136;
v_13137:
    v_13149 = stack[-3];
    v_13149 = qcar(v_13149);
    v_13149 = qcar(v_13149);
    v_13149 = ncons(v_13149);
    env = stack[-4];
    goto v_13138;
v_13139:
    goto v_13135;
v_13136:
    goto v_13137;
v_13138:
    v_13149 = Lrplacd(nil, stack[0], v_13149);
    env = stack[-4];
    v_13149 = stack[-1];
    v_13149 = qcdr(v_13149);
    stack[-1] = v_13149;
    goto v_13111;
v_13110:
    return onevalue(v_13149);
}



// Code for polynomlistreduce

static LispObject CC_polynomlistreduce(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13219, v_13220, v_13221;
    LispObject fn;
    LispObject v_13106, v_13105, v_13104;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "polynomlistreduce");
    va_start(aa, nargs);
    v_13104 = va_arg(aa, LispObject);
    v_13105 = va_arg(aa, LispObject);
    v_13106 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13106,v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13104,v_13105,v_13106);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_13106;
    stack[-2] = v_13105;
    stack[-3] = v_13104;
// end of prologue
    v_13219 = nil;
    v_13219 = ncons(v_13219);
    env = stack[-5];
    stack[-4] = v_13219;
    v_13219 = stack[-2];
    v_13219 = qcar(v_13219);
    if (v_13219 == nil) goto v_13116;
    else goto v_13117;
v_13116:
    v_13219 = stack[-4];
    goto v_13111;
v_13117:
v_13124:
    v_13219 = stack[-2];
    v_13219 = qcar(v_13219);
    if (v_13219 == nil) goto v_13127;
    else goto v_13128;
v_13127:
    goto v_13123;
v_13128:
    goto v_13139;
v_13133:
    v_13221 = stack[-3];
    goto v_13134;
v_13135:
    v_13220 = stack[-2];
    goto v_13136;
v_13137:
    v_13219 = stack[-1];
    goto v_13138;
v_13139:
    goto v_13133;
v_13134:
    goto v_13135;
v_13136:
    goto v_13137;
v_13138:
    fn = elt(env, 1); // polynomlistfinddivisor
    v_13219 = (*qfnn(fn))(fn, 3, v_13221, v_13220, v_13219);
    env = stack[-5];
v_13145:
    v_13220 = v_13219;
    if (v_13220 == nil) goto v_13148;
    else goto v_13149;
v_13148:
    goto v_13144;
v_13149:
    goto v_13157;
v_13153:
    v_13220 = stack[-2];
    goto v_13154;
v_13155:
    goto v_13156;
v_13157:
    goto v_13153;
v_13154:
    goto v_13155;
v_13156:
    fn = elt(env, 2); // polynomreduceby
    v_13219 = (*qfn2(fn))(fn, v_13220, v_13219);
    env = stack[-5];
    goto v_13167;
v_13161:
    v_13221 = stack[-3];
    goto v_13162;
v_13163:
    v_13220 = stack[-2];
    goto v_13164;
v_13165:
    v_13219 = stack[-1];
    goto v_13166;
v_13167:
    goto v_13161;
v_13162:
    goto v_13163;
v_13164:
    goto v_13165;
v_13166:
    fn = elt(env, 1); // polynomlistfinddivisor
    v_13219 = (*qfnn(fn))(fn, 3, v_13221, v_13220, v_13219);
    env = stack[-5];
    goto v_13145;
v_13144:
    v_13219 = stack[-2];
    v_13219 = qcar(v_13219);
    if (v_13219 == nil) goto v_13175;
    goto v_13183;
v_13179:
    stack[0] = stack[-4];
    goto v_13180;
v_13181:
    goto v_13192;
v_13186:
    v_13219 = stack[-2];
    v_13221 = qcar(v_13219);
    goto v_13187;
v_13188:
    v_13220 = nil;
    goto v_13189;
v_13190:
    v_13219 = nil;
    goto v_13191;
v_13192:
    goto v_13186;
v_13187:
    goto v_13188;
v_13189:
    goto v_13190;
v_13191:
    v_13219 = list2star(v_13221, v_13220, v_13219);
    env = stack[-5];
    goto v_13182;
v_13183:
    goto v_13179;
v_13180:
    goto v_13181;
v_13182:
    fn = elt(env, 3); // polynomadd
    v_13219 = (*qfn2(fn))(fn, stack[0], v_13219);
    env = stack[-5];
    goto v_13202;
v_13198:
    goto v_13208;
v_13204:
    v_13220 = stack[-2];
    goto v_13205;
v_13206:
    v_13219 = stack[-2];
    v_13219 = qcdr(v_13219);
    v_13219 = qcar(v_13219);
    goto v_13207;
v_13208:
    goto v_13204;
v_13205:
    goto v_13206;
v_13207:
    v_13220 = Lrplaca(nil, v_13220, v_13219);
    env = stack[-5];
    goto v_13199;
v_13200:
    v_13219 = stack[-2];
    v_13219 = qcdr(v_13219);
    v_13219 = qcdr(v_13219);
    goto v_13201;
v_13202:
    goto v_13198;
v_13199:
    goto v_13200;
v_13201:
    v_13219 = Lrplacd(nil, v_13220, v_13219);
    env = stack[-5];
    goto v_13173;
v_13175:
v_13173:
    goto v_13124;
v_13123:
    v_13219 = stack[-4];
v_13111:
    return onevalue(v_13219);
}



// Code for qqe_eta!-in!-term

static LispObject CC_qqe_etaKinKterm(LispObject env,
                         LispObject v_13104)
{
    env = qenv(env);
    LispObject v_13180, v_13181;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13104);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13104;
// end of prologue
    v_13180 = nil;
    stack[-1] = v_13180;
    v_13180 = stack[0];
    if (!consp(v_13180)) goto v_13113;
    else goto v_13114;
v_13113:
    v_13180 = nil;
    goto v_13109;
v_13114:
    goto v_13123;
v_13119:
    v_13180 = stack[0];
    fn = elt(env, 2); // qqe_op
    v_13181 = (*qfn1(fn))(fn, v_13180);
    env = stack[-2];
    goto v_13120;
v_13121:
    v_13180 = elt(env, 1); // (lhead rhead)
    goto v_13122;
v_13123:
    goto v_13119;
v_13120:
    goto v_13121;
v_13122:
    v_13180 = Lmemq(nil, v_13181, v_13180);
    if (v_13180 == nil) goto v_13118;
    v_13180 = stack[0];
    {
        fn = elt(env, 3); // qqe_eta!-in!-term1
        return (*qfn1(fn))(fn, v_13180);
    }
v_13118:
    v_13180 = stack[0];
    v_13180 = qcdr(v_13180);
    stack[0] = v_13180;
v_13136:
    v_13180 = stack[0];
    if (v_13180 == nil) goto v_13139;
    v_13180 = stack[-1];
    if (v_13180 == nil) goto v_13143;
    else goto v_13139;
v_13143:
    goto v_13140;
v_13139:
    goto v_13135;
v_13140:
    v_13180 = stack[0];
    v_13180 = qcar(v_13180);
    if (!consp(v_13180)) goto v_13149;
    goto v_13160;
v_13156:
    v_13180 = stack[0];
    v_13180 = qcar(v_13180);
    fn = elt(env, 2); // qqe_op
    v_13181 = (*qfn1(fn))(fn, v_13180);
    env = stack[-2];
    goto v_13157;
v_13158:
    v_13180 = elt(env, 1); // (lhead rhead)
    goto v_13159;
v_13160:
    goto v_13156;
v_13157:
    goto v_13158;
v_13159:
    v_13180 = Lmemq(nil, v_13181, v_13180);
    if (v_13180 == nil) goto v_13155;
    v_13180 = stack[0];
    v_13180 = qcar(v_13180);
    fn = elt(env, 3); // qqe_eta!-in!-term1
    v_13180 = (*qfn1(fn))(fn, v_13180);
    env = stack[-2];
    stack[-1] = v_13180;
    goto v_13153;
v_13155:
    v_13180 = stack[0];
    v_13180 = qcar(v_13180);
    v_13180 = CC_qqe_etaKinKterm(elt(env, 0), v_13180);
    env = stack[-2];
    stack[-1] = v_13180;
    goto v_13153;
v_13153:
    goto v_13147;
v_13149:
v_13147:
    v_13180 = stack[0];
    v_13180 = qcdr(v_13180);
    stack[0] = v_13180;
    goto v_13136;
v_13135:
    v_13180 = stack[-1];
    goto v_13109;
    v_13180 = nil;
v_13109:
    return onevalue(v_13180);
}



// Code for pasf_sacat

static LispObject CC_pasf_sacat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13109, v_13110, v_13111;
    LispObject v_13106, v_13105, v_13104;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pasf_sacat");
    va_start(aa, nargs);
    v_13104 = va_arg(aa, LispObject);
    v_13105 = va_arg(aa, LispObject);
    v_13106 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13109 = v_13106;
    v_13110 = v_13105;
    v_13111 = v_13104;
// end of prologue
    v_13109 = nil;
    return onevalue(v_13109);
}



// Code for unaryrd

static LispObject CC_unaryrd(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13112;
    LispObject fn;
    argcheck(nargs, 0, "unaryrd");
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
    v_13112 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    stack[0] = v_13112;
    fn = elt(env, 2); // lex
    v_13112 = (*qfnn(fn))(fn, 0);
    v_13112 = stack[0];
    return ncons(v_13112);
    return onevalue(v_13112);
}



// Code for groedeletip

static LispObject CC_groedeletip(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13176, v_13177;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13104,v_13105);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13105;
    stack[-1] = v_13104;
// end of prologue
v_13112:
    v_13176 = stack[0];
    if (v_13176 == nil) goto v_13115;
    goto v_13124;
v_13120:
    v_13177 = stack[-1];
    goto v_13121;
v_13122:
    v_13176 = stack[0];
    v_13176 = qcar(v_13176);
    goto v_13123;
v_13124:
    goto v_13120;
v_13121:
    goto v_13122;
v_13123:
    if (equal(v_13177, v_13176)) goto v_13119;
    else goto v_13115;
v_13119:
    goto v_13116;
v_13115:
    goto v_13111;
v_13116:
    v_13176 = stack[0];
    v_13176 = qcdr(v_13176);
    stack[0] = v_13176;
    goto v_13112;
v_13111:
    v_13176 = stack[0];
    if (v_13176 == nil) goto v_13133;
    else goto v_13134;
v_13133:
    v_13176 = nil;
    goto v_13109;
v_13134:
    v_13176 = stack[0];
    stack[-2] = v_13176;
v_13140:
    v_13176 = stack[0];
    v_13176 = qcdr(v_13176);
    if (v_13176 == nil) goto v_13143;
    else goto v_13144;
v_13143:
    goto v_13139;
v_13144:
    goto v_13156;
v_13152:
    v_13177 = stack[-1];
    goto v_13153;
v_13154:
    v_13176 = stack[0];
    v_13176 = qcdr(v_13176);
    v_13176 = qcar(v_13176);
    goto v_13155;
v_13156:
    goto v_13152;
v_13153:
    goto v_13154;
v_13155:
    if (equal(v_13177, v_13176)) goto v_13150;
    else goto v_13151;
v_13150:
    goto v_13166;
v_13162:
    v_13177 = stack[0];
    goto v_13163;
v_13164:
    v_13176 = stack[0];
    v_13176 = qcdr(v_13176);
    v_13176 = qcdr(v_13176);
    goto v_13165;
v_13166:
    goto v_13162;
v_13163:
    goto v_13164;
v_13165:
    fn = elt(env, 1); // setcdr
    v_13176 = (*qfn2(fn))(fn, v_13177, v_13176);
    env = stack[-3];
    goto v_13149;
v_13151:
    v_13176 = stack[0];
    v_13176 = qcdr(v_13176);
    stack[0] = v_13176;
    goto v_13149;
v_13149:
    goto v_13140;
v_13139:
    v_13176 = stack[-2];
v_13109:
    return onevalue(v_13176);
}



// Code for mktails

static LispObject CC_mktails(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_13171, v_13172, v_13173;
    LispObject fn;
    LispObject v_13106, v_13105, v_13104;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "mktails");
    va_start(aa, nargs);
    v_13104 = va_arg(aa, LispObject);
    v_13105 = va_arg(aa, LispObject);
    v_13106 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_13106,v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_13104,v_13105,v_13106);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_13172 = v_13106;
    stack[-2] = v_13105;
    v_13173 = v_13104;
// end of prologue
    stack[0] = nil;
    v_13171 = v_13173;
    if (v_13171 == nil) goto v_13116;
    else goto v_13117;
v_13116:
    goto v_13124;
v_13120:
    v_13171 = nil;
    goto v_13121;
v_13122:
    goto v_13123;
v_13124:
    goto v_13120;
v_13121:
    goto v_13122;
v_13123:
    return cons(v_13171, v_13172);
v_13117:
    v_13171 = v_13173;
    stack[-3] = v_13171;
    v_13171 = v_13172;
    stack[-1] = v_13171;
v_13131:
    v_13171 = stack[-3];
    if (v_13171 == nil) goto v_13134;
    else goto v_13135;
v_13134:
    goto v_13130;
v_13135:
    goto v_13145;
v_13139:
    v_13171 = stack[-3];
    v_13173 = qcar(v_13171);
    goto v_13140;
v_13141:
    v_13172 = stack[-2];
    goto v_13142;
v_13143:
    v_13171 = stack[-1];
    goto v_13144;
v_13145:
    goto v_13139;
v_13140:
    goto v_13141;
v_13142:
    goto v_13143;
v_13144:
    fn = elt(env, 1); // mktails1
    v_13171 = (*qfnn(fn))(fn, 3, v_13173, v_13172, v_13171);
    env = stack[-4];
    v_13172 = v_13171;
    v_13171 = v_13172;
    v_13171 = qcdr(v_13171);
    stack[-1] = v_13171;
    goto v_13157;
v_13153:
    v_13171 = v_13172;
    v_13172 = qcar(v_13171);
    goto v_13154;
v_13155:
    v_13171 = stack[0];
    goto v_13156;
v_13157:
    goto v_13153;
v_13154:
    goto v_13155;
v_13156:
    v_13171 = Lappend(nil, v_13172, v_13171);
    env = stack[-4];
    stack[0] = v_13171;
    v_13171 = stack[-3];
    v_13171 = qcdr(v_13171);
    stack[-3] = v_13171;
    goto v_13131;
v_13130:
    goto v_13168;
v_13164:
    v_13172 = stack[0];
    goto v_13165;
v_13166:
    v_13171 = stack[-1];
    goto v_13167;
v_13168:
    goto v_13164;
v_13165:
    goto v_13166;
v_13167:
    return cons(v_13172, v_13171);
    return onevalue(v_13171);
}



// Code for numlist_ordp

static LispObject CC_numlist_ordp(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13118, v_13119, v_13120;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13118 = v_13105;
    v_13119 = v_13104;
// end of prologue
    goto v_13114;
v_13108:
    v_13120 = v_13119;
    goto v_13109;
v_13110:
    v_13119 = v_13118;
    goto v_13111;
v_13112:
    v_13118 = elt(env, 1); // lambda_ygm6np4pcqv31
    goto v_13113;
v_13114:
    goto v_13108;
v_13109:
    goto v_13110;
v_13111:
    goto v_13112;
v_13113:
    {
        fn = elt(env, 2); // cons_ordp
        return (*qfnn(fn))(fn, 3, v_13120, v_13119, v_13118);
    }
}



// Code for lambda_ygm6np4pcqv31

static LispObject CC_lambda_ygm6np4pcqv31(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13115, v_13116;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_13115 = v_13105;
    v_13116 = v_13104;
// end of prologue
    goto v_13112;
v_13108:
    goto v_13109;
v_13110:
    goto v_13111;
v_13112:
    goto v_13108;
v_13109:
    goto v_13110;
v_13111:
        return Lleq(nil, v_13116, v_13115);
}



// Code for subf

static LispObject CC_subf(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13301, v_13302;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13104,v_13105);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-6] = v_13105;
    stack[-7] = v_13104;
// end of prologue
// Binding alglist!*
// FLUIDBIND: reloadenv=9 litvec-offset=1 saveloc=8
{   bind_fluid_stack bind_fluid_var(-9, 1, -8);
    qvalue(elt(env, 1)) = nil; // alglist!*
    stack[-5] = nil;
    stack[-4] = nil;
    v_13301 = nil;
    v_13301 = ncons(v_13301);
    env = stack[-9];
    qvalue(elt(env, 1)) = v_13301; // alglist!*
    v_13301 = stack[-7];
    if (!consp(v_13301)) goto v_13121;
    else goto v_13122;
v_13121:
    v_13301 = lisp_true;
    goto v_13120;
v_13122:
    v_13301 = stack[-7];
    v_13301 = qcar(v_13301);
    v_13301 = (consp(v_13301) ? nil : lisp_true);
    goto v_13120;
    v_13301 = nil;
v_13120:
    if (v_13301 == nil) goto v_13118;
    v_13301 = stack[-7];
    fn = elt(env, 5); // !*d2q
    v_13301 = (*qfn1(fn))(fn, v_13301);
    goto v_13112;
v_13118:
    v_13301 = qvalue(elt(env, 2)); // ncmp!*
    if (v_13301 == nil) goto v_13133;
    v_13301 = stack[-7];
    fn = elt(env, 6); // noncomexpf
    v_13301 = (*qfn1(fn))(fn, v_13301);
    env = stack[-9];
    if (v_13301 == nil) goto v_13133;
    goto v_13144;
v_13140:
    v_13302 = stack[-7];
    goto v_13141;
v_13142:
    v_13301 = stack[-6];
    goto v_13143;
v_13144:
    goto v_13140;
v_13141:
    goto v_13142;
v_13143:
    fn = elt(env, 7); // subf1
    v_13301 = (*qfn2(fn))(fn, v_13302, v_13301);
    goto v_13112;
v_13133:
    goto v_13153;
v_13149:
    v_13301 = stack[-6];
    stack[-3] = v_13301;
    v_13301 = stack[-3];
    if (v_13301 == nil) goto v_13163;
    else goto v_13164;
v_13163:
    v_13301 = nil;
    stack[0] = v_13301;
    goto v_13158;
v_13164:
    v_13301 = stack[-3];
    v_13301 = qcar(v_13301);
    v_13301 = qcar(v_13301);
    v_13301 = ncons(v_13301);
    env = stack[-9];
    stack[-1] = v_13301;
    stack[-2] = v_13301;
v_13159:
    v_13301 = stack[-3];
    v_13301 = qcdr(v_13301);
    stack[-3] = v_13301;
    v_13301 = stack[-3];
    if (v_13301 == nil) goto v_13177;
    else goto v_13178;
v_13177:
    v_13301 = stack[-2];
    stack[0] = v_13301;
    goto v_13158;
v_13178:
    goto v_13186;
v_13182:
    stack[0] = stack[-1];
    goto v_13183;
v_13184:
    v_13301 = stack[-3];
    v_13301 = qcar(v_13301);
    v_13301 = qcar(v_13301);
    v_13301 = ncons(v_13301);
    env = stack[-9];
    goto v_13185;
v_13186:
    goto v_13182;
v_13183:
    goto v_13184;
v_13185:
    v_13301 = Lrplacd(nil, stack[0], v_13301);
    env = stack[-9];
    v_13301 = stack[-1];
    v_13301 = qcdr(v_13301);
    stack[-1] = v_13301;
    goto v_13159;
v_13158:
    goto v_13150;
v_13151:
    goto v_13201;
v_13197:
    v_13302 = stack[-7];
    goto v_13198;
v_13199:
    v_13301 = nil;
    goto v_13200;
v_13201:
    goto v_13197;
v_13198:
    goto v_13199;
v_13200:
    fn = elt(env, 8); // kernord
    v_13301 = (*qfn2(fn))(fn, v_13302, v_13301);
    env = stack[-9];
    goto v_13152;
v_13153:
    goto v_13149;
v_13150:
    goto v_13151;
v_13152:
    fn = elt(env, 9); // intersection
    v_13301 = (*qfn2(fn))(fn, stack[0], v_13301);
    env = stack[-9];
    v_13301 = Lreverse(nil, v_13301);
    env = stack[-9];
    stack[0] = v_13301;
    v_13301 = stack[0];
    fn = elt(env, 10); // setkorder
    v_13301 = (*qfn1(fn))(fn, v_13301);
    env = stack[-9];
    stack[0] = v_13301;
    goto v_13211;
v_13207:
    v_13301 = stack[-7];
    fn = elt(env, 11); // reorder
    v_13302 = (*qfn1(fn))(fn, v_13301);
    env = stack[-9];
    goto v_13208;
v_13209:
    v_13301 = stack[-6];
    goto v_13210;
v_13211:
    goto v_13207;
v_13208:
    goto v_13209;
v_13210:
    fn = elt(env, 7); // subf1
    v_13301 = (*qfn2(fn))(fn, v_13302, v_13301);
    env = stack[-9];
    stack[-7] = v_13301;
v_13217:
    goto v_13230;
v_13226:
    v_13302 = stack[-7];
    goto v_13227;
v_13228:
    v_13301 = stack[-4];
    goto v_13229;
v_13230:
    goto v_13226;
v_13227:
    goto v_13228;
v_13229:
    v_13301 = Lmember(nil, v_13302, v_13301);
    if (v_13301 == nil) goto v_13224;
    else goto v_13225;
v_13224:
    goto v_13243;
v_13239:
    stack[-1] = elt(env, 3); // expt
    goto v_13240;
v_13241:
    v_13301 = stack[-7];
    v_13301 = qcar(v_13301);
    fn = elt(env, 12); // kernels
    v_13301 = (*qfn1(fn))(fn, v_13301);
    env = stack[-9];
    goto v_13242;
v_13243:
    goto v_13239;
v_13240:
    goto v_13241;
v_13242:
    v_13301 = Latsoc(nil, stack[-1], v_13301);
    if (v_13301 == nil) goto v_13238;
    else goto v_13237;
v_13238:
    goto v_13254;
v_13250:
    stack[-1] = elt(env, 3); // expt
    goto v_13251;
v_13252:
    v_13301 = stack[-7];
    v_13301 = qcdr(v_13301);
    fn = elt(env, 12); // kernels
    v_13301 = (*qfn1(fn))(fn, v_13301);
    env = stack[-9];
    goto v_13253;
v_13254:
    goto v_13250;
v_13251:
    goto v_13252;
v_13253:
    v_13301 = Latsoc(nil, stack[-1], v_13301);
    if (v_13301 == nil) goto v_13249;
    else goto v_13237;
v_13249:
    v_13301 = nil;
    goto v_13235;
v_13237:
    goto v_13267;
v_13263:
    v_13301 = stack[-7];
    fn = elt(env, 13); // prepsq
    v_13302 = (*qfn1(fn))(fn, v_13301);
    env = stack[-9];
    stack[-5] = v_13302;
    goto v_13264;
v_13265:
    v_13301 = qvalue(elt(env, 4)); // varstack!*
    goto v_13266;
v_13267:
    goto v_13263;
v_13264:
    goto v_13265;
v_13266:
    v_13301 = Lmember(nil, v_13302, v_13301);
    v_13301 = (v_13301 == nil ? lisp_true : nil);
    goto v_13235;
    v_13301 = nil;
v_13235:
    goto v_13223;
v_13225:
    v_13301 = nil;
    goto v_13223;
    v_13301 = nil;
v_13223:
    if (v_13301 == nil) goto v_13220;
    else goto v_13221;
v_13220:
    goto v_13216;
v_13221:
    goto v_13282;
v_13278:
    v_13302 = stack[-7];
    goto v_13279;
v_13280:
    v_13301 = stack[-4];
    goto v_13281;
v_13282:
    goto v_13278;
v_13279:
    goto v_13280;
v_13281:
    v_13301 = cons(v_13302, v_13301);
    env = stack[-9];
    stack[-4] = v_13301;
    v_13301 = stack[-5];
    fn = elt(env, 14); // simp
    v_13301 = (*qfn1(fn))(fn, v_13301);
    env = stack[-9];
    stack[-7] = v_13301;
    goto v_13217;
v_13216:
    v_13301 = stack[0];
    fn = elt(env, 10); // setkorder
    v_13301 = (*qfn1(fn))(fn, v_13301);
    env = stack[-9];
    goto v_13294;
v_13290:
    v_13301 = stack[-7];
    v_13301 = qcar(v_13301);
    fn = elt(env, 11); // reorder
    stack[0] = (*qfn1(fn))(fn, v_13301);
    env = stack[-9];
    goto v_13291;
v_13292:
    v_13301 = stack[-7];
    v_13301 = qcdr(v_13301);
    fn = elt(env, 11); // reorder
    v_13301 = (*qfn1(fn))(fn, v_13301);
    env = stack[-9];
    goto v_13293;
v_13294:
    goto v_13290;
v_13291:
    goto v_13292;
v_13293:
    v_13301 = cons(stack[0], v_13301);
v_13112:
    ;}  // end of a binding scope
    return onevalue(v_13301);
}



// Code for random!-teeny!-prime

static LispObject CC_randomKteenyKprime(LispObject env,
                         LispObject v_13104)
{
    env = qenv(env);
    LispObject v_13170, v_13171, v_13172;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13104);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13104;
// end of prologue
    goto v_13118;
v_13114:
    v_13171 = stack[0];
    goto v_13115;
v_13116:
    v_13170 = elt(env, 1); // all
    goto v_13117;
v_13118:
    goto v_13114;
v_13115:
    goto v_13116;
v_13117:
    if (v_13171 == v_13170) goto v_13112;
    else goto v_13113;
v_13112:
    v_13170 = lisp_true;
    goto v_13111;
v_13113:
    goto v_13128;
v_13124:
    v_13170 = stack[0];
    v_13171 = Llength(nil, v_13170);
    env = stack[-2];
    goto v_13125;
v_13126:
    v_13170 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_13127;
v_13128:
    goto v_13124;
v_13125:
    goto v_13126;
v_13127:
    v_13170 = (v_13171 == v_13170 ? lisp_true : nil);
    goto v_13111;
    v_13170 = nil;
v_13111:
    if (v_13170 == nil) goto v_13109;
    v_13170 = nil;
    goto v_13107;
v_13109:
v_13141:
    goto v_13146;
v_13142:
    stack[-1] = qvalue(elt(env, 2)); // teeny!-primes
    goto v_13143;
v_13144:
    goto v_13153;
v_13149:
    fn = elt(env, 3); // next!-random!-number
    v_13171 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_13150;
v_13151:
    v_13170 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_13152;
v_13153:
    goto v_13149;
v_13150:
    goto v_13151;
v_13152:
    v_13170 = Cremainder(v_13171, v_13170);
    env = stack[-2];
    goto v_13145;
v_13146:
    goto v_13142;
v_13143:
    goto v_13144;
v_13145:
    v_13170 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_13170-TAG_FIXNUM)/(16/CELL)));
    v_13172 = v_13170;
    goto v_13165;
v_13161:
    v_13171 = v_13172;
    goto v_13162;
v_13163:
    v_13170 = stack[0];
    goto v_13164;
v_13165:
    goto v_13161;
v_13162:
    goto v_13163;
v_13164:
    v_13170 = Lmember(nil, v_13171, v_13170);
    if (v_13170 == nil) goto v_13160;
    goto v_13141;
v_13160:
    v_13170 = v_13172;
    goto v_13107;
    v_13170 = nil;
v_13107:
    return onevalue(v_13170);
}



// Code for lto_sgnchg1

static LispObject CC_lto_sgnchg1(LispObject env,
                         LispObject v_13104)
{
    env = qenv(env);
    LispObject v_13147;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13104);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_13104;
// end of prologue
v_13108:
    v_13147 = stack[0];
    if (v_13147 == nil) goto v_13115;
    else goto v_13116;
v_13115:
    v_13147 = lisp_true;
    goto v_13114;
v_13116:
    v_13147 = stack[0];
    v_13147 = qcdr(v_13147);
    v_13147 = (v_13147 == nil ? lisp_true : nil);
    goto v_13114;
    v_13147 = nil;
v_13114:
    if (v_13147 == nil) goto v_13112;
    v_13147 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13107;
v_13112:
    goto v_13131;
v_13127:
    v_13147 = stack[0];
    v_13147 = qcar(v_13147);
    fn = elt(env, 1); // sgn
    stack[-1] = (*qfn1(fn))(fn, v_13147);
    env = stack[-2];
    goto v_13128;
v_13129:
    v_13147 = stack[0];
    v_13147 = qcdr(v_13147);
    v_13147 = qcar(v_13147);
    fn = elt(env, 1); // sgn
    v_13147 = (*qfn1(fn))(fn, v_13147);
    env = stack[-2];
    goto v_13130;
v_13131:
    goto v_13127;
v_13128:
    goto v_13129;
v_13130:
    if (stack[-1] == v_13147) goto v_13125;
    else goto v_13126;
v_13125:
    v_13147 = stack[0];
    v_13147 = qcdr(v_13147);
    stack[0] = v_13147;
    goto v_13108;
v_13126:
    v_13147 = stack[0];
    v_13147 = qcdr(v_13147);
    v_13147 = CC_lto_sgnchg1(elt(env, 0), v_13147);
    return add1(v_13147);
    v_13147 = nil;
v_13107:
    return onevalue(v_13147);
}



// Code for remlocs

static LispObject CC_remlocs(LispObject env,
                         LispObject v_13104)
{
    env = qenv(env);
    LispObject v_13202, v_13203;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13104);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_13203 = v_13104;
// end of prologue
    v_13202 = qvalue(elt(env, 1)); // !*globals
    if (v_13202 == nil) goto v_13112;
    v_13202 = v_13203;
    stack[-2] = v_13202;
v_13117:
    v_13202 = stack[-2];
    if (v_13202 == nil) goto v_13121;
    else goto v_13122;
v_13121:
    goto v_13116;
v_13122:
    v_13202 = stack[-2];
    v_13202 = qcar(v_13202);
    stack[-1] = v_13202;
    goto v_13132;
v_13128:
    v_13203 = stack[-1];
    goto v_13129;
v_13130:
    v_13202 = qvalue(elt(env, 2)); // locls!*
    goto v_13131;
v_13132:
    goto v_13128;
v_13129:
    goto v_13130;
v_13131:
    v_13202 = Lassoc(nil, v_13203, v_13202);
    stack[-3] = v_13202;
    v_13202 = stack[-3];
    if (v_13202 == nil) goto v_13138;
    else goto v_13139;
v_13138:
    v_13202 = elt(env, 3); // begin
    fn = elt(env, 5); // getd
    v_13202 = (*qfn1(fn))(fn, v_13202);
    env = stack[-4];
    if (v_13202 == nil) goto v_13144;
    goto v_13153;
v_13149:
    v_13203 = elt(env, 4); // " Lvar confused"
    goto v_13150;
v_13151:
    v_13202 = stack[-1];
    goto v_13152;
v_13153:
    goto v_13149;
v_13150:
    goto v_13151;
v_13152:
    v_13202 = list2(v_13203, v_13202);
    env = stack[-4];
    fn = elt(env, 6); // rederr
    v_13202 = (*qfn1(fn))(fn, v_13202);
    env = stack[-4];
    goto v_13142;
v_13144:
    goto v_13163;
v_13159:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_13160;
v_13161:
    goto v_13170;
v_13166:
    v_13203 = elt(env, 4); // " Lvar confused"
    goto v_13167;
v_13168:
    v_13202 = stack[-1];
    goto v_13169;
v_13170:
    goto v_13166;
v_13167:
    goto v_13168;
v_13169:
    v_13202 = list2(v_13203, v_13202);
    env = stack[-4];
    goto v_13162;
v_13163:
    goto v_13159;
v_13160:
    goto v_13161;
v_13162:
    fn = elt(env, 7); // error
    v_13202 = (*qfn2(fn))(fn, stack[0], v_13202);
    env = stack[-4];
    goto v_13142;
v_13142:
    goto v_13137;
v_13139:
v_13137:
    v_13202 = stack[-3];
    v_13202 = qcdr(v_13202);
    v_13202 = qcdr(v_13202);
    if (v_13202 == nil) goto v_13176;
    goto v_13185;
v_13181:
    v_13203 = stack[-3];
    goto v_13182;
v_13183:
    v_13202 = stack[-3];
    v_13202 = qcdr(v_13202);
    v_13202 = qcdr(v_13202);
    goto v_13184;
v_13185:
    goto v_13181;
v_13182:
    goto v_13183;
v_13184:
    v_13202 = Lrplacd(nil, v_13203, v_13202);
    env = stack[-4];
    goto v_13174;
v_13176:
    goto v_13197;
v_13193:
    v_13203 = stack[-3];
    goto v_13194;
v_13195:
    v_13202 = qvalue(elt(env, 2)); // locls!*
    goto v_13196;
v_13197:
    goto v_13193;
v_13194:
    goto v_13195;
v_13196:
    fn = elt(env, 8); // efface1
    v_13202 = (*qfn2(fn))(fn, v_13203, v_13202);
    env = stack[-4];
    qvalue(elt(env, 2)) = v_13202; // locls!*
    goto v_13174;
v_13174:
    v_13202 = stack[-2];
    v_13202 = qcdr(v_13202);
    stack[-2] = v_13202;
    goto v_13117;
v_13116:
    goto v_13110;
v_13112:
v_13110:
    v_13202 = nil;
    return onevalue(v_13202);
}



// Code for poly!-multfnc

static LispObject CC_polyKmultfnc(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13330, v_13331, v_13332;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13104,v_13105);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_13105;
    stack[-2] = v_13104;
// end of prologue
    v_13330 = qvalue(elt(env, 1)); // !*sstools!-loaded
    if (v_13330 == nil) goto v_13110;
    goto v_13117;
v_13113:
    v_13331 = stack[-2];
    goto v_13114;
v_13115:
    v_13330 = stack[-1];
    goto v_13116;
v_13117:
    goto v_13113;
v_13114:
    goto v_13115;
v_13116:
    {
        fn = elt(env, 3); // sstools!-multfnc
        return (*qfn2(fn))(fn, v_13331, v_13330);
    }
v_13110:
    goto v_13131;
v_13127:
    v_13330 = stack[-2];
    v_13330 = qcar(v_13330);
    stack[0] = qcdr(v_13330);
    goto v_13128;
v_13129:
    v_13330 = stack[-1];
    v_13330 = qcar(v_13330);
    v_13330 = ncons(v_13330);
    env = stack[-4];
    goto v_13130;
v_13131:
    goto v_13127;
v_13128:
    goto v_13129;
v_13130:
    fn = elt(env, 4); // poly!-multf
    v_13330 = (*qfn2(fn))(fn, stack[0], v_13330);
    env = stack[-4];
    stack[-3] = v_13330;
    v_13330 = stack[-3];
    if (v_13330 == nil) goto v_13140;
    else goto v_13141;
v_13140:
    goto v_13139;
v_13141:
    v_13330 = stack[-3];
    if (!consp(v_13330)) goto v_13152;
    else goto v_13153;
v_13152:
    v_13330 = lisp_true;
    goto v_13151;
v_13153:
    v_13330 = stack[-3];
    v_13330 = qcar(v_13330);
    v_13330 = (consp(v_13330) ? nil : lisp_true);
    goto v_13151;
    v_13330 = nil;
v_13151:
    if (v_13330 == nil) goto v_13148;
    else goto v_13149;
v_13148:
    goto v_13165;
v_13161:
    v_13330 = stack[-3];
    v_13330 = qcar(v_13330);
    v_13330 = qcar(v_13330);
    v_13331 = qcar(v_13330);
    goto v_13162;
v_13163:
    v_13330 = stack[-2];
    v_13330 = qcar(v_13330);
    v_13330 = qcar(v_13330);
    v_13330 = qcar(v_13330);
    goto v_13164;
v_13165:
    goto v_13161;
v_13162:
    goto v_13163;
v_13164:
    v_13330 = (v_13331 == v_13330 ? lisp_true : nil);
    goto v_13147;
v_13149:
    v_13330 = nil;
    goto v_13147;
    v_13330 = nil;
v_13147:
    if (v_13330 == nil) goto v_13145;
    goto v_13183;
v_13179:
    goto v_13193;
v_13189:
    v_13330 = stack[-2];
    v_13330 = qcar(v_13330);
    v_13330 = qcar(v_13330);
    stack[0] = qcar(v_13330);
    goto v_13190;
v_13191:
    goto v_13203;
v_13199:
    v_13330 = stack[-2];
    v_13330 = qcar(v_13330);
    v_13330 = qcar(v_13330);
    v_13331 = qcdr(v_13330);
    goto v_13200;
v_13201:
    v_13330 = stack[-3];
    v_13330 = qcar(v_13330);
    v_13330 = qcar(v_13330);
    v_13330 = qcdr(v_13330);
    goto v_13202;
v_13203:
    goto v_13199;
v_13200:
    goto v_13201;
v_13202:
    v_13330 = plus2(v_13331, v_13330);
    env = stack[-4];
    goto v_13192;
v_13193:
    goto v_13189;
v_13190:
    goto v_13191;
v_13192:
    fn = elt(env, 5); // mkspm
    v_13330 = (*qfn2(fn))(fn, stack[0], v_13330);
    env = stack[-4];
    v_13332 = v_13330;
    if (v_13330 == nil) goto v_13186;
    else goto v_13187;
v_13186:
    v_13330 = nil;
    stack[0] = v_13330;
    goto v_13185;
v_13187:
    goto v_13219;
v_13215:
    v_13331 = v_13332;
    goto v_13216;
v_13217:
    v_13330 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13218;
v_13219:
    goto v_13215;
v_13216:
    goto v_13217;
v_13218:
    if (v_13331 == v_13330) goto v_13213;
    else goto v_13214;
v_13213:
    v_13330 = stack[-3];
    v_13330 = qcar(v_13330);
    v_13330 = qcdr(v_13330);
    stack[0] = v_13330;
    goto v_13185;
v_13214:
    goto v_13233;
v_13229:
    v_13331 = v_13332;
    goto v_13230;
v_13231:
    v_13330 = stack[-3];
    v_13330 = qcar(v_13330);
    v_13330 = qcdr(v_13330);
    goto v_13232;
v_13233:
    goto v_13229;
v_13230:
    goto v_13231;
v_13232:
    v_13330 = cons(v_13331, v_13330);
    env = stack[-4];
    v_13330 = ncons(v_13330);
    env = stack[-4];
    stack[0] = v_13330;
    goto v_13185;
    stack[0] = nil;
v_13185:
    goto v_13180;
v_13181:
    goto v_13243;
v_13239:
    goto v_13250;
v_13246:
    v_13330 = stack[-2];
    v_13330 = qcar(v_13330);
    v_13331 = qcar(v_13330);
    goto v_13247;
v_13248:
    v_13330 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13249;
v_13250:
    goto v_13246;
v_13247:
    goto v_13248;
v_13249:
    v_13330 = cons(v_13331, v_13330);
    env = stack[-4];
    v_13331 = ncons(v_13330);
    env = stack[-4];
    goto v_13240;
v_13241:
    v_13330 = stack[-3];
    v_13330 = qcdr(v_13330);
    goto v_13242;
v_13243:
    goto v_13239;
v_13240:
    goto v_13241;
v_13242:
    fn = elt(env, 4); // poly!-multf
    v_13330 = (*qfn2(fn))(fn, v_13331, v_13330);
    env = stack[-4];
    goto v_13182;
v_13183:
    goto v_13179;
v_13180:
    goto v_13181;
v_13182:
    fn = elt(env, 6); // addf
    v_13330 = (*qfn2(fn))(fn, stack[0], v_13330);
    env = stack[-4];
    stack[-3] = v_13330;
    goto v_13139;
v_13145:
    v_13330 = stack[-2];
    v_13330 = qcar(v_13330);
    v_13330 = qcar(v_13330);
    v_13330 = qcar(v_13330);
    fn = elt(env, 7); // noncomp
    v_13330 = (*qfn1(fn))(fn, v_13330);
    env = stack[-4];
    if (v_13330 == nil) goto v_13258;
    goto v_13270;
v_13266:
    v_13330 = stack[-2];
    v_13330 = qcar(v_13330);
    v_13331 = qcar(v_13330);
    goto v_13267;
v_13268:
    v_13330 = stack[-3];
    goto v_13269;
v_13270:
    goto v_13266;
v_13267:
    goto v_13268;
v_13269:
    v_13330 = cons(v_13331, v_13330);
    env = stack[-4];
    v_13330 = ncons(v_13330);
    env = stack[-4];
    stack[-3] = v_13330;
    goto v_13139;
v_13258:
    v_13330 = lisp_true;
// Binding !*!*processed
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 2, 0);
    qvalue(elt(env, 2)) = v_13330; // !*!*processed
    goto v_13284;
v_13280:
    goto v_13291;
v_13287:
    v_13330 = stack[-2];
    v_13330 = qcar(v_13330);
    v_13331 = qcar(v_13330);
    goto v_13288;
v_13289:
    v_13330 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13290;
v_13291:
    goto v_13287;
v_13288:
    goto v_13289;
v_13290:
    v_13330 = cons(v_13331, v_13330);
    env = stack[-4];
    v_13331 = ncons(v_13330);
    env = stack[-4];
    goto v_13281;
v_13282:
    v_13330 = stack[-3];
    goto v_13283;
v_13284:
    goto v_13280;
v_13281:
    goto v_13282;
v_13283:
    fn = elt(env, 4); // poly!-multf
    v_13330 = (*qfn2(fn))(fn, v_13331, v_13330);
    env = stack[-4];
    stack[-3] = v_13330;
    ;}  // end of a binding scope
    goto v_13139;
v_13139:
    goto v_13302;
v_13298:
    goto v_13299;
v_13300:
    goto v_13309;
v_13305:
    goto v_13315;
v_13311:
    v_13330 = stack[-2];
    v_13331 = qcdr(v_13330);
    goto v_13312;
v_13313:
    v_13330 = stack[-1];
    goto v_13314;
v_13315:
    goto v_13311;
v_13312:
    goto v_13313;
v_13314:
    fn = elt(env, 4); // poly!-multf
    stack[0] = (*qfn2(fn))(fn, v_13331, v_13330);
    env = stack[-4];
    goto v_13306;
v_13307:
    goto v_13324;
v_13320:
    v_13330 = stack[-2];
    v_13330 = qcar(v_13330);
    v_13331 = ncons(v_13330);
    env = stack[-4];
    goto v_13321;
v_13322:
    v_13330 = stack[-1];
    v_13330 = qcdr(v_13330);
    goto v_13323;
v_13324:
    goto v_13320;
v_13321:
    goto v_13322;
v_13323:
    fn = elt(env, 4); // poly!-multf
    v_13330 = (*qfn2(fn))(fn, v_13331, v_13330);
    env = stack[-4];
    goto v_13308;
v_13309:
    goto v_13305;
v_13306:
    goto v_13307;
v_13308:
    fn = elt(env, 6); // addf
    v_13330 = (*qfn2(fn))(fn, stack[0], v_13330);
    env = stack[-4];
    goto v_13301;
v_13302:
    goto v_13298;
v_13299:
    goto v_13300;
v_13301:
    {
        LispObject v_13337 = stack[-3];
        fn = elt(env, 6); // addf
        return (*qfn2(fn))(fn, v_13337, v_13330);
    }
    goto v_13108;
    v_13330 = nil;
v_13108:
    return onevalue(v_13330);
}



// Code for rl_subalchk

static LispObject CC_rl_subalchk(LispObject env,
                         LispObject v_13104)
{
    env = qenv(env);
    LispObject v_13115;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_13104);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_13115 = v_13104;
// end of prologue
    goto v_13111;
v_13107:
    stack[0] = qvalue(elt(env, 1)); // rl_subalchk!*
    goto v_13108;
v_13109:
    v_13115 = ncons(v_13115);
    env = stack[-1];
    goto v_13110;
v_13111:
    goto v_13107;
v_13108:
    goto v_13109;
v_13110:
    {
        LispObject v_13117 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_13117, v_13115);
    }
}



// Code for termorder

static LispObject CC_termorder(LispObject env,
                         LispObject v_13104, LispObject v_13105)
{
    env = qenv(env);
    LispObject v_13173, v_13174, v_13175;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_13105,v_13104);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_13104,v_13105);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_13105;
    stack[-1] = v_13104;
// end of prologue
    v_13173 = stack[-1];
    if (v_13173 == nil) goto v_13113;
    else goto v_13114;
v_13113:
    goto v_13112;
v_13114:
    v_13173 = stack[-1];
    v_13173 = (LispObject)zerop(v_13173);
    v_13173 = v_13173 ? lisp_true : nil;
    env = stack[-3];
    if (v_13173 == nil) goto v_13118;
    v_13173 = stack[0];
    v_13173 = (LispObject)zerop(v_13173);
    v_13173 = v_13173 ? lisp_true : nil;
    env = stack[-3];
    if (v_13173 == nil) goto v_13118;
    goto v_13112;
v_13118:
    v_13173 = stack[-1];
    v_13173 = (LispObject)zerop(v_13173);
    v_13173 = v_13173 ? lisp_true : nil;
    env = stack[-3];
    if (v_13173 == nil) goto v_13127;
    goto v_13112;
v_13127:
    v_13173 = stack[0];
    v_13173 = (LispObject)zerop(v_13173);
    v_13173 = v_13173 ? lisp_true : nil;
    env = stack[-3];
    if (v_13173 == nil) goto v_13132;
    goto v_13112;
v_13132:
v_13112:
    v_13173 = stack[-1];
    fn = elt(env, 1); // listsum
    v_13173 = (*qfn1(fn))(fn, v_13173);
    env = stack[-3];
    stack[-2] = v_13173;
    v_13173 = stack[0];
    fn = elt(env, 1); // listsum
    v_13173 = (*qfn1(fn))(fn, v_13173);
    env = stack[-3];
    v_13175 = v_13173;
    goto v_13148;
v_13144:
    v_13174 = stack[-2];
    goto v_13145;
v_13146:
    v_13173 = v_13175;
    goto v_13147;
v_13148:
    goto v_13144;
v_13145:
    goto v_13146;
v_13147:
    if (equal(v_13174, v_13173)) goto v_13142;
    else goto v_13143;
v_13142:
    goto v_13156;
v_13152:
    v_13174 = stack[-1];
    goto v_13153;
v_13154:
    v_13173 = stack[0];
    goto v_13155;
v_13156:
    goto v_13152;
v_13153:
    goto v_13154;
v_13155:
    {
        fn = elt(env, 2); // termorder1
        return (*qfn2(fn))(fn, v_13174, v_13173);
    }
v_13143:
    goto v_13166;
v_13162:
    v_13173 = stack[-2];
    goto v_13163;
v_13164:
    v_13174 = v_13175;
    goto v_13165;
v_13166:
    goto v_13162;
v_13163:
    goto v_13164;
v_13165:
    v_13173 = (LispObject)lessp2(v_13173, v_13174);
    v_13173 = v_13173 ? lisp_true : nil;
    if (v_13173 == nil) goto v_13160;
    v_13173 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_13141;
v_13160:
    v_13173 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_13141;
    v_13173 = nil;
v_13141:
    return onevalue(v_13173);
}



setup_type const u23_setup[] =
{
    {"evdif",                   TOO_FEW_2,      CC_evdif,      WRONG_NO_2},
    {"evgradlexcomp",           TOO_FEW_2,      CC_evgradlexcomp,WRONG_NO_2},
    {"wedgek2",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_wedgek2},
    {"physop2sq",               CC_physop2sq,   TOO_MANY_1,    WRONG_NO_1},
    {"def_edge",                TOO_FEW_2,      CC_def_edge,   WRONG_NO_2},
    {"pairxvars",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pairxvars},
    {"setel1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_setel1},
    {"simp-prop-order",         TOO_FEW_2,      CC_simpKpropKorder,WRONG_NO_2},
    {"readprogn",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_readprogn},
    {"rl_atnum",                CC_rl_atnum,    TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_subf",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_subf},
    {"squared+matrix+p",        CC_squaredLmatrixLp,TOO_MANY_1,WRONG_NO_1},
    {"rl_pnf",                  CC_rl_pnf,      TOO_MANY_1,    WRONG_NO_1},
    {"ev_lexcomp",              TOO_FEW_2,      CC_ev_lexcomp, WRONG_NO_2},
    {"makeset",                 CC_makeset,     TOO_MANY_1,    WRONG_NO_1},
    {"xlcm",                    TOO_FEW_2,      CC_xlcm,       WRONG_NO_2},
    {"set-global-mode",         CC_setKglobalKmode,TOO_MANY_1, WRONG_NO_1},
    {"scalprod",                TOO_FEW_2,      CC_scalprod,   WRONG_NO_2},
    {"fs:null-angle",           CC_fsTnullKangle,TOO_MANY_1,   WRONG_NO_1},
    {"mo_equal?",               TOO_FEW_2,      CC_mo_equalW,  WRONG_NO_2},
    {"ordered-gcd-mod-p",       TOO_FEW_2,      CC_orderedKgcdKmodKp,WRONG_NO_2},
    {"p_prinl2",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_p_prinl2},
    {"defineargs",              TOO_FEW_2,      CC_defineargs, WRONG_NO_2},
    {"tayexp-times2",           TOO_FEW_2,      CC_tayexpKtimes2,WRONG_NO_2},
    {"talp_contains",           TOO_FEW_2,      CC_talp_contains,WRONG_NO_2},
    {"mri_pasf2mri",            TOO_FEW_2,      CC_mri_pasf2mri,WRONG_NO_2},
    {"vsl_boundtype",           TOO_FEW_2,      CC_vsl_boundtype,WRONG_NO_2},
    {"subs4q",                  CC_subs4q,      TOO_MANY_1,    WRONG_NO_1},
    {"xregister_wedge_pair",    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xregister_wedge_pair},
    {"total-degree-in-powers",  TOO_FEW_2,      CC_totalKdegreeKinKpowers,WRONG_NO_2},
    {"putd",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_putd},
    {"setel",                   TOO_FEW_2,      CC_setel,      WRONG_NO_2},
    {"fs:prin1",                CC_fsTprin1,    TOO_MANY_1,    WRONG_NO_1},
    {"st_sorttree",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_st_sorttree},
    {"general-modular-expt",    TOO_FEW_2,      CC_generalKmodularKexpt,WRONG_NO_2},
    {"ctx_idl",                 CC_ctx_idl,     TOO_MANY_1,    WRONG_NO_1},
    {"polynomlistreduce",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_polynomlistreduce},
    {"qqe_eta-in-term",         CC_qqe_etaKinKterm,TOO_MANY_1, WRONG_NO_1},
    {"pasf_sacat",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pasf_sacat},
    {"unaryrd",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_unaryrd},
    {"groedeletip",             TOO_FEW_2,      CC_groedeletip,WRONG_NO_2},
    {"mktails",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_mktails},
    {"numlist_ordp",            TOO_FEW_2,      CC_numlist_ordp,WRONG_NO_2},
    {"lambda_ygm6np4pcqv31",    TOO_FEW_2,      CC_lambda_ygm6np4pcqv31,WRONG_NO_2},
    {"subf",                    TOO_FEW_2,      CC_subf,       WRONG_NO_2},
    {"random-teeny-prime",      CC_randomKteenyKprime,TOO_MANY_1,WRONG_NO_1},
    {"lto_sgnchg1",             CC_lto_sgnchg1, TOO_MANY_1,    WRONG_NO_1},
    {"remlocs",                 CC_remlocs,     TOO_MANY_1,    WRONG_NO_1},
    {"poly-multfnc",            TOO_FEW_2,      CC_polyKmultfnc,WRONG_NO_2},
    {"rl_subalchk",             CC_rl_subalchk, TOO_MANY_1,    WRONG_NO_1},
    {"termorder",               TOO_FEW_2,      CC_termorder,  WRONG_NO_2},
    {NULL, (one_args *)"u23", (two_args *)"58900 4674716 2012588", 0}
};

// end of generated code
