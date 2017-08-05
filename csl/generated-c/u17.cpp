
// $destdir/u17.c        Machine generated C code

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



// Code for lex_restore_context

static LispObject CC_lex_restore_context(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_9022, v_9023, v_9024;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8923);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_8923;
// end of prologue
    fn = elt(env, 7); // lex_cleanup
    v_9022 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    v_9022 = stack[0];
    stack[0] = v_9022;
v_8934:
    v_9022 = stack[0];
    if (v_9022 == nil) goto v_8938;
    else goto v_8939;
v_8938:
    goto v_8933;
v_8939:
    v_9022 = stack[0];
    v_9022 = qcar(v_9022);
    v_9023 = v_9022;
    v_9022 = v_9023;
    v_9022 = qcar(v_9022);
    stack[-2] = v_9022;
    v_9022 = v_9023;
    v_9022 = qcdr(v_9022);
    v_9022 = qcar(v_9022);
    stack[-1] = v_9022;
    v_9022 = v_9023;
    v_9022 = qcdr(v_9022);
    v_9022 = qcdr(v_9022);
    v_9022 = Lintern(nil, v_9022);
    env = stack[-4];
    stack[-3] = v_9022;
    goto v_8963;
v_8959:
    v_9023 = stack[-3];
    goto v_8960;
v_8961:
    v_9022 = elt(env, 1); // lex_fixed_code
    goto v_8962;
v_8963:
    goto v_8959;
v_8960:
    goto v_8961;
v_8962:
    v_9022 = get(v_9023, v_9022);
    env = stack[-4];
    if (v_9022 == nil) goto v_8956;
    else goto v_8957;
v_8956:
    goto v_8975;
v_8971:
    v_9023 = stack[-1];
    goto v_8972;
v_8973:
    v_9022 = qvalue(elt(env, 2)); // lex_next_code
    goto v_8974;
v_8975:
    goto v_8971;
v_8972:
    goto v_8973;
v_8974:
    v_9022 = (LispObject)greaterp2(v_9023, v_9022);
    v_9022 = v_9022 ? lisp_true : nil;
    env = stack[-4];
    if (v_9022 == nil) goto v_8969;
    v_9022 = stack[-1];
    qvalue(elt(env, 2)) = v_9022; // lex_next_code
    goto v_8967;
v_8969:
v_8967:
    goto v_8986;
v_8980:
    v_9024 = stack[-3];
    goto v_8981;
v_8982:
    v_9023 = elt(env, 3); // lex_dipthong
    goto v_8983;
v_8984:
    v_9022 = stack[-2];
    goto v_8985;
v_8986:
    goto v_8980;
v_8981:
    goto v_8982;
v_8983:
    goto v_8984;
v_8985:
    v_9022 = Lputprop(nil, 3, v_9024, v_9023, v_9022);
    env = stack[-4];
    goto v_8997;
v_8991:
    v_9024 = stack[-3];
    goto v_8992;
v_8993:
    v_9023 = elt(env, 4); // lex_code
    goto v_8994;
v_8995:
    v_9022 = stack[-1];
    goto v_8996;
v_8997:
    goto v_8991;
v_8992:
    goto v_8993;
v_8994:
    goto v_8995;
v_8996:
    v_9022 = Lputprop(nil, 3, v_9024, v_9023, v_9022);
    env = stack[-4];
    goto v_9008;
v_9002:
    v_9024 = stack[-1];
    goto v_9003;
v_9004:
    v_9023 = stack[-3];
    goto v_9005;
v_9006:
    v_9022 = qvalue(elt(env, 5)); // lex_codename
    goto v_9007;
v_9008:
    goto v_9002;
v_9003:
    goto v_9004;
v_9005:
    goto v_9006;
v_9007:
    v_9022 = acons(v_9024, v_9023, v_9022);
    env = stack[-4];
    qvalue(elt(env, 5)) = v_9022; // lex_codename
    goto v_9017;
v_9013:
    v_9023 = stack[-3];
    goto v_9014;
v_9015:
    v_9022 = qvalue(elt(env, 6)); // lex_keyword_names
    goto v_9016;
v_9017:
    goto v_9013;
v_9014:
    goto v_9015;
v_9016:
    v_9022 = cons(v_9023, v_9022);
    env = stack[-4];
    qvalue(elt(env, 6)) = v_9022; // lex_keyword_names
    goto v_8955;
v_8957:
v_8955:
    v_9022 = stack[0];
    v_9022 = qcdr(v_9022);
    stack[0] = v_9022;
    goto v_8934;
v_8933:
    v_9022 = nil;
    return onevalue(v_9022);
}



// Code for collect_cars

static LispObject CC_collect_cars(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_8950, v_8951;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8923);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_8923;
// end of prologue
    v_8951 = nil;
v_8928:
    v_8950 = stack[0];
    if (v_8950 == nil) goto v_8931;
    else goto v_8932;
v_8931:
    v_8950 = v_8951;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_8950);
    }
v_8932:
    goto v_8943;
v_8939:
    v_8950 = stack[0];
    v_8950 = qcar(v_8950);
    v_8950 = qcar(v_8950);
    goto v_8940;
v_8941:
    goto v_8942;
v_8943:
    goto v_8939;
v_8940:
    goto v_8941;
v_8942:
    v_8950 = cons(v_8950, v_8951);
    env = stack[-1];
    v_8951 = v_8950;
    v_8950 = stack[0];
    v_8950 = qcdr(v_8950);
    stack[0] = v_8950;
    goto v_8928;
    v_8950 = nil;
    return onevalue(v_8950);
}



// Code for processpartitie1

static LispObject CC_processpartitie1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_9054, v_9055, v_9056, v_9057, v_9058;
    LispObject fn;
    LispObject v_8927, v_8926, v_8925, v_8924, v_8923;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "processpartitie1");
    va_start(aa, nargs);
    v_8923 = va_arg(aa, LispObject);
    v_8924 = va_arg(aa, LispObject);
    v_8925 = va_arg(aa, LispObject);
    v_8926 = va_arg(aa, LispObject);
    v_8927 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_8927,v_8926,v_8925,v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_8923,v_8924,v_8925,v_8926,v_8927);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_8927;
    stack[-1] = v_8926;
    v_9056 = v_8925;
    v_9057 = v_8924;
    stack[-2] = v_8923;
// end of prologue
v_8931:
    v_9054 = stack[-2];
    if (v_9054 == nil) goto v_8934;
    else goto v_8935;
v_8934:
    v_9054 = stack[-1];
    v_9054 = qcar(v_9054);
    if (v_9054 == nil) goto v_8939;
    else goto v_8940;
v_8939:
    goto v_8950;
v_8944:
    v_9056 = elt(env, 1); // times
    goto v_8945;
v_8946:
    v_9054 = stack[-1];
    v_9055 = qcdr(v_9054);
    goto v_8947;
v_8948:
    v_9054 = stack[0];
    goto v_8949;
v_8950:
    goto v_8944;
v_8945:
    goto v_8946;
v_8947:
    goto v_8948;
v_8949:
    return acons(v_9056, v_9055, v_9054);
v_8940:
    goto v_8964;
v_8958:
    stack[-3] = elt(env, 1); // times
    goto v_8959;
v_8960:
    goto v_8973;
v_8967:
    stack[-2] = elt(env, 2); // ext
    goto v_8968;
v_8969:
    v_9054 = stack[-1];
    v_9054 = qcar(v_9054);
    fn = elt(env, 4); // ordn
    v_9054 = (*qfn1(fn))(fn, v_9054);
    env = stack[-4];
    v_9055 = Lreverse(nil, v_9054);
    env = stack[-4];
    goto v_8970;
v_8971:
    v_9054 = stack[-1];
    v_9054 = qcdr(v_9054);
    goto v_8972;
v_8973:
    goto v_8967;
v_8968:
    goto v_8969;
v_8970:
    goto v_8971;
v_8972:
    v_9055 = acons(stack[-2], v_9055, v_9054);
    goto v_8961;
v_8962:
    v_9054 = stack[0];
    goto v_8963;
v_8964:
    goto v_8958;
v_8959:
    goto v_8960;
v_8961:
    goto v_8962;
v_8963:
    {
        LispObject v_9063 = stack[-3];
        return acons(v_9063, v_9055, v_9054);
    }
    goto v_8933;
v_8935:
    goto v_8988;
v_8984:
    v_9054 = stack[-2];
    v_9055 = qcar(v_9054);
    goto v_8985;
v_8986:
    v_9054 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8987;
v_8988:
    goto v_8984;
v_8985:
    goto v_8986;
v_8987:
    if (v_9055 == v_9054) goto v_8982;
    else goto v_8983;
v_8982:
    v_9054 = stack[-2];
    v_9054 = qcdr(v_9054);
    stack[-2] = v_9054;
    goto v_8931;
v_8983:
    goto v_9000;
v_8996:
    v_9054 = stack[-2];
    v_9055 = qcar(v_9054);
    goto v_8997;
v_8998:
    v_9054 = v_9057;
    goto v_8999;
v_9000:
    goto v_8996;
v_8997:
    goto v_8998;
v_8999:
    if (equal(v_9055, v_9054)) goto v_8994;
    else goto v_8995;
v_8994:
    goto v_9015;
v_9005:
    v_9058 = v_9057;
    goto v_9006;
v_9007:
    v_9057 = v_9056;
    goto v_9008;
v_9009:
    v_9054 = stack[-2];
    v_9056 = qcdr(v_9054);
    goto v_9010;
v_9011:
    v_9055 = stack[-1];
    goto v_9012;
v_9013:
    v_9054 = stack[0];
    goto v_9014;
v_9015:
    goto v_9005;
v_9006:
    goto v_9007;
v_9008:
    goto v_9009;
v_9010:
    goto v_9011;
v_9012:
    goto v_9013;
v_9014:
    {
        fn = elt(env, 5); // processcarpartitie1
        return (*qfnn(fn))(fn, 5, v_9058, v_9057, v_9056, v_9055, v_9054);
    }
v_8995:
    goto v_9035;
v_9025:
    v_9054 = stack[-2];
    stack[-3] = qcar(v_9054);
    goto v_9026;
v_9027:
    goto v_9043;
v_9039:
    v_9054 = qvalue(elt(env, 3)); // all_graded_der
    fn = elt(env, 6); // aeval
    v_9054 = (*qfn1(fn))(fn, v_9054);
    env = stack[-4];
    v_9055 = qcdr(v_9054);
    goto v_9040;
v_9041:
    v_9054 = stack[-2];
    v_9054 = qcar(v_9054);
    goto v_9042;
v_9043:
    goto v_9039;
v_9040:
    goto v_9041;
v_9042:
    fn = elt(env, 7); // nth
    v_9054 = (*qfn2(fn))(fn, v_9055, v_9054);
    env = stack[-4];
    v_9057 = qcdr(v_9054);
    goto v_9028;
v_9029:
    v_9054 = stack[-2];
    v_9056 = qcdr(v_9054);
    goto v_9030;
v_9031:
    v_9055 = stack[-1];
    goto v_9032;
v_9033:
    v_9054 = stack[0];
    goto v_9034;
v_9035:
    goto v_9025;
v_9026:
    goto v_9027;
v_9028:
    goto v_9029;
v_9030:
    goto v_9031;
v_9032:
    goto v_9033;
v_9034:
    {
        LispObject v_9064 = stack[-3];
        fn = elt(env, 5); // processcarpartitie1
        return (*qfnn(fn))(fn, 5, v_9064, v_9057, v_9056, v_9055, v_9054);
    }
v_8933:
    v_9054 = nil;
    return onevalue(v_9054);
}



// Code for talp_smwrmknowl

static LispObject CC_talp_smwrmknowl(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_8949, v_8950, v_8951;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8950 = v_8924;
    v_8951 = v_8923;
// end of prologue
    v_8949 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_8949 == nil) goto v_8929;
    goto v_8936;
v_8932:
    v_8949 = v_8951;
    goto v_8933;
v_8934:
    goto v_8935;
v_8936:
    goto v_8932;
v_8933:
    goto v_8934;
v_8935:
    {
        fn = elt(env, 2); // cl_susirmknowl
        return (*qfn2(fn))(fn, v_8949, v_8950);
    }
v_8929:
    goto v_8946;
v_8942:
    v_8949 = v_8951;
    goto v_8943;
v_8944:
    goto v_8945;
v_8946:
    goto v_8942;
v_8943:
    goto v_8944;
v_8945:
    {
        fn = elt(env, 3); // cl_smrmknowl
        return (*qfn2(fn))(fn, v_8949, v_8950);
    }
    v_8949 = nil;
    return onevalue(v_8949);
}



// Code for sq2sspl

static LispObject CC_sq2sspl(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_8984, v_8985;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_8924;
    stack[-1] = v_8923;
// end of prologue
    stack[-2] = nil;
v_8930:
    v_8984 = stack[-1];
    if (!consp(v_8984)) goto v_8939;
    else goto v_8940;
v_8939:
    v_8984 = lisp_true;
    goto v_8938;
v_8940:
    v_8984 = stack[-1];
    v_8984 = qcar(v_8984);
    v_8984 = (consp(v_8984) ? nil : lisp_true);
    goto v_8938;
    v_8984 = nil;
v_8938:
    if (v_8984 == nil) goto v_8936;
    goto v_8931;
v_8936:
    goto v_8953;
v_8949:
    goto v_8959;
v_8955:
    v_8984 = stack[-1];
    v_8985 = qcar(v_8984);
    goto v_8956;
v_8957:
    v_8984 = stack[0];
    goto v_8958;
v_8959:
    goto v_8955;
v_8956:
    goto v_8957;
v_8958:
    fn = elt(env, 1); // sq2sstm
    v_8985 = (*qfn2(fn))(fn, v_8985, v_8984);
    env = stack[-3];
    goto v_8950;
v_8951:
    v_8984 = stack[-2];
    goto v_8952;
v_8953:
    goto v_8949;
v_8950:
    goto v_8951;
v_8952:
    v_8984 = cons(v_8985, v_8984);
    env = stack[-3];
    stack[-2] = v_8984;
    v_8984 = stack[-1];
    v_8984 = qcdr(v_8984);
    stack[-1] = v_8984;
    goto v_8930;
v_8931:
    v_8984 = stack[-1];
    v_8985 = v_8984;
v_8932:
    v_8984 = stack[-2];
    if (v_8984 == nil) goto v_8969;
    else goto v_8970;
v_8969:
    v_8984 = v_8985;
    goto v_8929;
v_8970:
    goto v_8978;
v_8974:
    v_8984 = stack[-2];
    v_8984 = qcar(v_8984);
    goto v_8975;
v_8976:
    goto v_8977;
v_8978:
    goto v_8974;
v_8975:
    goto v_8976;
v_8977:
    v_8984 = Lappend(nil, v_8984, v_8985);
    env = stack[-3];
    v_8985 = v_8984;
    v_8984 = stack[-2];
    v_8984 = qcdr(v_8984);
    stack[-2] = v_8984;
    goto v_8932;
v_8929:
    return onevalue(v_8984);
}



// Code for ibalp_lenisone

static LispObject CC_ibalp_lenisone(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_8936, v_8937;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8936 = v_8923;
// end of prologue
    v_8937 = v_8936;
    if (v_8937 == nil) goto v_8927;
    else goto v_8928;
v_8927:
    v_8936 = nil;
    goto v_8926;
v_8928:
    v_8936 = qcdr(v_8936);
    v_8936 = (v_8936 == nil ? lisp_true : nil);
    goto v_8926;
    v_8936 = nil;
v_8926:
    return onevalue(v_8936);
}



// Code for attributesml

static LispObject CC_attributesml(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_9003, v_9004;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_8924;
    stack[-1] = v_8923;
// end of prologue
    v_9003 = stack[-1];
    if (v_9003 == nil) goto v_8930;
    else goto v_8931;
v_8930:
    v_9003 = stack[0];
    v_9003 = Lprinc(nil, v_9003);
    env = stack[-2];
    v_9003 = elt(env, 1); // ">"
    v_9003 = Lprinc(nil, v_9003);
    goto v_8929;
v_8931:
    v_9003 = elt(env, 2); // " "
    v_9003 = Lprinc(nil, v_9003);
    env = stack[-2];
    v_9003 = stack[-1];
    v_9003 = qcar(v_9003);
    v_9003 = qcar(v_9003);
    v_9003 = Lprinc(nil, v_9003);
    env = stack[-2];
    v_9003 = elt(env, 3); // "="""
    v_9003 = Lprinc(nil, v_9003);
    env = stack[-2];
    goto v_8955;
v_8951:
    v_9003 = stack[-1];
    v_9003 = qcar(v_9003);
    v_9004 = qcar(v_9003);
    goto v_8952;
v_8953:
    v_9003 = elt(env, 4); // definitionurl
    goto v_8954;
v_8955:
    goto v_8951;
v_8952:
    goto v_8953;
v_8954:
    if (v_9004 == v_9003) goto v_8950;
    goto v_8968;
v_8964:
    v_9003 = stack[-1];
    v_9003 = qcar(v_9003);
    v_9003 = qcdr(v_9003);
    v_9004 = qcar(v_9003);
    goto v_8965;
v_8966:
    v_9003 = elt(env, 5); // vectorml
    goto v_8967;
v_8968:
    goto v_8964;
v_8965:
    goto v_8966;
v_8967:
    if (v_9004 == v_9003) goto v_8962;
    else goto v_8963;
v_8962:
    v_9003 = elt(env, 6); // "vector"
    v_9003 = Lprinc(nil, v_9003);
    env = stack[-2];
    goto v_8961;
v_8963:
    v_9003 = stack[-1];
    v_9003 = qcar(v_9003);
    v_9003 = qcdr(v_9003);
    v_9003 = qcar(v_9003);
    v_9003 = Lprinc(nil, v_9003);
    env = stack[-2];
    goto v_8961;
v_8961:
    goto v_8948;
v_8950:
    v_9003 = stack[-1];
    v_9003 = qcar(v_9003);
    v_9003 = qcdr(v_9003);
    v_9003 = qcar(v_9003);
    fn = elt(env, 8); // mathml_list2string
    v_9003 = (*qfn1(fn))(fn, v_9003);
    env = stack[-2];
    goto v_8948;
v_8948:
    v_9003 = elt(env, 7); // """"
    v_9003 = Lprinc(nil, v_9003);
    env = stack[-2];
    goto v_8998;
v_8994:
    v_9003 = stack[-1];
    v_9004 = qcdr(v_9003);
    goto v_8995;
v_8996:
    v_9003 = stack[0];
    goto v_8997;
v_8998:
    goto v_8994;
v_8995:
    goto v_8996;
v_8997:
    v_9003 = CC_attributesml(elt(env, 0), v_9004, v_9003);
    goto v_8929;
v_8929:
    v_9003 = nil;
    return onevalue(v_9003);
}



// Code for maprin

static LispObject CC_maprin(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_8952, v_8953, v_8954;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8953 = v_8923;
// end of prologue
    v_8952 = qvalue(elt(env, 1)); // outputhandler!*
    if (v_8952 == nil) goto v_8928;
    goto v_8937;
v_8931:
    v_8952 = qvalue(elt(env, 1)); // outputhandler!*
    goto v_8932;
v_8933:
    v_8954 = elt(env, 0); // maprin
    goto v_8934;
v_8935:
    goto v_8936;
v_8937:
    goto v_8931;
v_8932:
    goto v_8933;
v_8934:
    goto v_8935;
v_8936:
        return Lapply2(nil, 3, v_8952, v_8954, v_8953);
v_8928:
    v_8952 = qvalue(elt(env, 2)); // overflowed!*
    if (v_8952 == nil) goto v_8941;
    else goto v_8942;
v_8941:
    goto v_8949;
v_8945:
    goto v_8946;
v_8947:
    v_8952 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8948;
v_8949:
    goto v_8945;
v_8946:
    goto v_8947;
v_8948:
    {
        fn = elt(env, 3); // maprint
        return (*qfn2(fn))(fn, v_8953, v_8952);
    }
v_8942:
    v_8952 = nil;
    return onevalue(v_8952);
}



// Code for dm!-eq

static LispObject CC_dmKeq(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_8935, v_8936;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_8935 = v_8924;
    v_8936 = v_8923;
// end of prologue
    goto v_8932;
v_8928:
    goto v_8929;
v_8930:
    goto v_8931;
v_8932:
    goto v_8928;
v_8929:
    goto v_8930;
v_8931:
    fn = elt(env, 1); // dm!-difference
    v_8935 = (*qfn2(fn))(fn, v_8936, v_8935);
    env = stack[0];
    {
        fn = elt(env, 2); // !:zerop
        return (*qfn1(fn))(fn, v_8935);
    }
}



// Code for modminusp!:

static LispObject CC_modminuspT(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_8949, v_8950;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8923);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_8949 = v_8923;
// end of prologue
    v_8950 = qvalue(elt(env, 1)); // !*balanced_mod
    if (v_8950 == nil) goto v_8928;
    goto v_8935;
v_8931:
    goto v_8941;
v_8937:
    v_8950 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_8938;
v_8939:
    v_8949 = qcdr(v_8949);
    goto v_8940;
v_8941:
    goto v_8937;
v_8938:
    goto v_8939;
v_8940:
    v_8949 = times2(v_8950, v_8949);
    env = stack[0];
    goto v_8932;
v_8933:
    v_8950 = qvalue(elt(env, 2)); // current!-modulus
    goto v_8934;
v_8935:
    goto v_8931;
v_8932:
    goto v_8933;
v_8934:
        return Lgreaterp(nil, v_8949, v_8950);
v_8928:
    v_8949 = nil;
    goto v_8926;
    v_8949 = nil;
v_8926:
    return onevalue(v_8949);
}



// Code for xread1

static LispObject CC_xread1(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_10298, v_10299, v_10300;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8923);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_8923;
// end of prologue
    stack[-8] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v_10298 = qvalue(elt(env, 1)); // commentlist!*
    if (v_10298 == nil) goto v_8960;
    v_10298 = qvalue(elt(env, 1)); // commentlist!*
    stack[-1] = v_10298;
    v_10298 = nil;
    qvalue(elt(env, 1)) = v_10298; // commentlist!*
    goto v_8958;
v_8960:
v_8958:
v_8935:
    v_10298 = qvalue(elt(env, 2)); // cursym!*
    stack[-3] = v_10298;
v_8936:
    v_10298 = stack[-3];
    if (symbolp(v_10298)) goto v_8968;
    goto v_8966;
v_8968:
    goto v_8977;
v_8973:
    v_10299 = stack[-3];
    goto v_8974;
v_8975:
    v_10298 = elt(env, 3); // !*lpar!*
    goto v_8976;
v_8977:
    goto v_8973;
v_8974:
    goto v_8975;
v_8976:
    if (v_10299 == v_10298) goto v_8971;
    else goto v_8972;
v_8971:
    goto v_8940;
v_8972:
    goto v_8986;
v_8982:
    v_10299 = stack[-3];
    goto v_8983;
v_8984:
    v_10298 = elt(env, 4); // !*rpar!*
    goto v_8985;
v_8986:
    goto v_8982;
v_8983:
    goto v_8984;
v_8985:
    if (v_10299 == v_10298) goto v_8980;
    else goto v_8981;
v_8980:
    goto v_8942;
v_8981:
    v_10298 = stack[-3];
    if (!symbolp(v_10298)) v_10298 = nil;
    else { v_10298 = qfastgets(v_10298);
           if (v_10298 != nil) { v_10298 = elt(v_10298, 23); // infix
#ifdef RECORD_GET
             if (v_10298 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_10298 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_10298 == SPID_NOPROP) v_10298 = nil; }}
#endif
    stack[-4] = v_10298;
    if (v_10298 == nil) goto v_8990;
    goto v_8943;
v_8990:
    v_10298 = stack[-3];
    if (!symbolp(v_10298)) v_10298 = nil;
    else { v_10298 = qfastgets(v_10298);
           if (v_10298 != nil) { v_10298 = elt(v_10298, 55); // delim
#ifdef RECORD_GET
             if (v_10298 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v_10298 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v_10298 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v_10298 == SPID_NOPROP) v_10298 = nil; else v_10298 = lisp_true; }}
#endif
    if (v_10298 == nil) goto v_8994;
    goto v_8954;
v_8994:
    v_10298 = stack[-3];
    if (!symbolp(v_10298)) v_10298 = nil;
    else { v_10298 = qfastgets(v_10298);
           if (v_10298 != nil) { v_10298 = elt(v_10298, 36); // stat
#ifdef RECORD_GET
             if (v_10298 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v_10298 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v_10298 == SPID_NOPROP) v_10298 = nil; }}
#endif
    stack[-4] = v_10298;
    if (v_10298 == nil) goto v_8998;
    goto v_8953;
v_8998:
    v_10298 = qvalue(elt(env, 5)); // !*reduce4
    if (v_10298 == nil) goto v_9005;
    else goto v_9006;
v_9005:
    goto v_9013;
v_9009:
    v_10299 = stack[-3];
    goto v_9010;
v_9011:
    v_10298 = elt(env, 6); // type
    goto v_9012;
v_9013:
    goto v_9009;
v_9010:
    goto v_9011;
v_9012:
    v_10298 = Lflagp(nil, v_10299, v_10298);
    env = stack[-9];
    goto v_9004;
v_9006:
    v_10298 = nil;
    goto v_9004;
    v_10298 = nil;
v_9004:
    if (v_10298 == nil) goto v_9002;
    goto v_9024;
v_9020:
    goto v_9030;
v_9026:
    v_10299 = elt(env, 7); // decstat
    goto v_9027;
v_9028:
    v_10298 = nil;
    goto v_9029;
v_9030:
    goto v_9026;
v_9027:
    goto v_9028;
v_9029:
    fn = elt(env, 48); // lispapply
    v_10299 = (*qfn2(fn))(fn, v_10299, v_10298);
    env = stack[-9];
    goto v_9021;
v_9022:
    v_10298 = stack[-6];
    goto v_9023;
v_9024:
    goto v_9020;
v_9021:
    goto v_9022;
v_9023:
    v_10298 = cons(v_10299, v_10298);
    env = stack[-9];
    stack[-6] = v_10298;
    goto v_8935;
v_9002:
v_8966:
v_8937:
    v_10298 = nil;
    stack[-4] = v_10298;
v_8938:
    goto v_9040;
v_9036:
    v_10299 = stack[-3];
    goto v_9037;
v_9038:
    v_10298 = stack[-6];
    goto v_9039;
v_9040:
    goto v_9036;
v_9037:
    goto v_9038;
v_9039:
    v_10298 = cons(v_10299, v_10298);
    env = stack[-9];
    stack[-6] = v_10298;
    v_10298 = stack[-3];
    fn = elt(env, 49); // toknump
    v_10298 = (*qfn1(fn))(fn, v_10298);
    env = stack[-9];
    if (v_10298 == nil) goto v_9046;
    goto v_9059;
v_9055:
    v_10299 = stack[-2];
    goto v_9056;
v_9057:
    v_10298 = qvalue(elt(env, 8)); // !$eol!$
    goto v_9058;
v_9059:
    goto v_9055;
v_9056:
    goto v_9057;
v_9058:
    if (v_10299 == v_10298) goto v_9054;
    v_10298 = qvalue(elt(env, 9)); // nxtsym!*
    fn = elt(env, 50); // chknewnam
    v_10298 = (*qfn1(fn))(fn, v_10298);
    env = stack[-9];
    stack[-2] = v_10298;
    if (symbolp(v_10298)) goto v_9065;
    v_10298 = nil;
    goto v_9063;
v_9065:
    v_10298 = stack[-2];
    if (!symbolp(v_10298)) v_10298 = nil;
    else { v_10298 = qfastgets(v_10298);
           if (v_10298 != nil) { v_10298 = elt(v_10298, 55); // delim
#ifdef RECORD_GET
             if (v_10298 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v_10298 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v_10298 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v_10298 == SPID_NOPROP) v_10298 = nil; else v_10298 = lisp_true; }}
#endif
    if (v_10298 == nil) goto v_9073;
    else goto v_9074;
v_9073:
    v_10298 = stack[-2];
    if (!symbolp(v_10298)) v_10298 = nil;
    else { v_10298 = qfastgets(v_10298);
           if (v_10298 != nil) { v_10298 = elt(v_10298, 11); // switch!*
#ifdef RECORD_GET
             if (v_10298 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v_10298 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v_10298 == SPID_NOPROP) v_10298 = nil; }}
#endif
    if (v_10298 == nil) goto v_9079;
    goto v_9089;
v_9085:
    v_10299 = stack[-2];
    goto v_9086;
v_9087:
    v_10298 = elt(env, 10); // !(
    goto v_9088;
v_9089:
    goto v_9085;
v_9086:
    goto v_9087;
v_9088:
    if (v_10299 == v_10298) goto v_9079;
    goto v_9080;
v_9079:
    v_10298 = stack[-2];
    if (!symbolp(v_10298)) v_10298 = nil;
    else { v_10298 = qfastgets(v_10298);
           if (v_10298 != nil) { v_10298 = elt(v_10298, 23); // infix
#ifdef RECORD_GET
             if (v_10298 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_10298 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_10298 == SPID_NOPROP) v_10298 = nil; }}
#endif
    if (v_10298 == nil) goto v_9094;
    else goto v_9095;
v_9094:
    v_10298 = qvalue(elt(env, 11)); // !*eoldelimp
    if (v_10298 == nil) goto v_9100;
    else goto v_9101;
v_9100:
    v_10298 = nil;
    goto v_9099;
v_9101:
    goto v_9110;
v_9106:
    v_10299 = stack[-2];
    goto v_9107;
v_9108:
    v_10298 = qvalue(elt(env, 8)); // !$eol!$
    goto v_9109;
v_9110:
    goto v_9106;
v_9107:
    goto v_9108;
v_9109:
    v_10298 = (v_10299 == v_10298 ? lisp_true : nil);
    goto v_9099;
    v_10298 = nil;
v_9099:
    v_10298 = (v_10298 == nil ? lisp_true : nil);
    goto v_9093;
v_9095:
    v_10298 = nil;
    goto v_9093;
    v_10298 = nil;
v_9093:
    goto v_9078;
v_9080:
    v_10298 = nil;
    goto v_9078;
    v_10298 = nil;
v_9078:
    goto v_9072;
v_9074:
    v_10298 = nil;
    goto v_9072;
    v_10298 = nil;
v_9072:
    goto v_9063;
    v_10298 = nil;
v_9063:
    goto v_9052;
v_9054:
    v_10298 = nil;
    goto v_9052;
    v_10298 = nil;
v_9052:
    if (v_10298 == nil) goto v_9046;
    v_10298 = elt(env, 12); // times
    qvalue(elt(env, 2)) = v_10298; // cursym!*
    v_10298 = nil;
    qvalue(elt(env, 13)) = v_10298; // curescaped!*
    goto v_8935;
v_9046:
    goto v_9139;
v_9135:
    v_10299 = stack[-7];
    goto v_9136;
v_9137:
    v_10298 = elt(env, 14); // proc
    goto v_9138;
v_9139:
    goto v_9135;
v_9136:
    goto v_9137;
v_9138:
    if (v_10299 == v_10298) goto v_9133;
    else goto v_9134;
v_9133:
    goto v_9147;
v_9143:
    v_10298 = stack[-6];
    v_10299 = Llength(nil, v_10298);
    env = stack[-9];
    goto v_9144;
v_9145:
    v_10298 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_9146;
v_9147:
    goto v_9143;
v_9144:
    goto v_9145;
v_9146:
    v_10298 = (LispObject)greaterp2(v_10299, v_10298);
    v_10298 = v_10298 ? lisp_true : nil;
    env = stack[-9];
    goto v_9132;
v_9134:
    v_10298 = nil;
    goto v_9132;
    v_10298 = nil;
v_9132:
    if (v_10298 == nil) goto v_9130;
    goto v_9159;
v_9155:
    v_10299 = elt(env, 15); // "Syntax error in procedure header"
    goto v_9156;
v_9157:
    v_10298 = nil;
    goto v_9158;
v_9159:
    goto v_9155;
v_9156:
    goto v_9157;
v_9158:
    fn = elt(env, 51); // symerr
    v_10298 = (*qfn2(fn))(fn, v_10299, v_10298);
    env = stack[-9];
    goto v_9044;
v_9130:
v_9044:
v_8939:
    fn = elt(env, 52); // scan
    v_10298 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    stack[-3] = v_10298;
    goto v_8936;
v_8940:
    fn = elt(env, 53); // eolcheck
    v_10298 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    v_10298 = nil;
    stack[-4] = v_10298;
    goto v_9173;
v_9169:
    fn = elt(env, 52); // scan
    v_10299 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    goto v_9170;
v_9171:
    v_10298 = elt(env, 4); // !*rpar!*
    goto v_9172;
v_9173:
    goto v_9169;
v_9170:
    goto v_9171;
v_9172:
    if (v_10299 == v_10298) goto v_9167;
    else goto v_9168;
v_9167:
    goto v_8941;
v_9168:
    goto v_9183;
v_9179:
    v_10299 = stack[-6];
    goto v_9180;
v_9181:
    v_10298 = elt(env, 16); // struct
    goto v_9182;
v_9183:
    goto v_9179;
v_9180:
    goto v_9181;
v_9182:
    v_10298 = Lflagpcar(nil, v_10299, v_10298);
    env = stack[-9];
    if (v_10298 == nil) goto v_9177;
    v_10298 = stack[-6];
    v_10298 = qcar(v_10298);
    v_10298 = CC_xread1(elt(env, 0), v_10298);
    env = stack[-9];
    stack[-3] = v_10298;
    goto v_9166;
v_9177:
    v_10298 = elt(env, 17); // paren
    v_10298 = CC_xread1(elt(env, 0), v_10298);
    env = stack[-9];
    stack[-3] = v_10298;
    goto v_9166;
v_9166:
    goto v_9202;
v_9198:
    v_10299 = stack[-7];
    goto v_9199;
v_9200:
    v_10298 = elt(env, 16); // struct
    goto v_9201;
v_9202:
    goto v_9198;
v_9199:
    goto v_9200;
v_9201:
    v_10298 = Lflagp(nil, v_10299, v_10298);
    env = stack[-9];
    if (v_10298 == nil) goto v_9196;
    v_10298 = stack[-3];
    fn = elt(env, 54); // remcomma
    v_10298 = (*qfn1(fn))(fn, v_10298);
    env = stack[-9];
    stack[-3] = v_10298;
    goto v_8938;
v_9196:
    goto v_9214;
v_9210:
    v_10299 = stack[-3];
    goto v_9211;
v_9212:
    v_10298 = elt(env, 18); // !*comma!*
    goto v_9213;
v_9214:
    goto v_9210;
v_9211:
    goto v_9212;
v_9213:
    if (!consp(v_10299)) goto v_9207;
    v_10299 = qcar(v_10299);
    if (v_10299 == v_10298) goto v_9208;
v_9207:
    goto v_8938;
v_9208:
    v_10298 = stack[-6];
    if (v_10298 == nil) goto v_9217;
    else goto v_9218;
v_9217:
    goto v_9228;
v_9224:
    v_10299 = stack[-7];
    goto v_9225;
v_9226:
    v_10298 = elt(env, 19); // lambda
    goto v_9227;
v_9228:
    goto v_9224;
v_9225:
    goto v_9226;
v_9227:
    if (v_10299 == v_10298) goto v_9222;
    else goto v_9223;
v_9222:
    goto v_8938;
v_9223:
    goto v_9238;
v_9234:
    v_10299 = elt(env, 20); // "Improper delimiter"
    goto v_9235;
v_9236:
    v_10298 = nil;
    goto v_9237;
v_9238:
    goto v_9234;
v_9235:
    goto v_9236;
v_9237:
    fn = elt(env, 51); // symerr
    v_10298 = (*qfn2(fn))(fn, v_10299, v_10298);
    env = stack[-9];
    goto v_9221;
v_9221:
    goto v_9194;
v_9218:
    goto v_9250;
v_9244:
    v_10298 = stack[-6];
    v_10300 = qcar(v_10298);
    goto v_9245;
v_9246:
    v_10298 = stack[-3];
    v_10299 = qcdr(v_10298);
    goto v_9247;
v_9248:
    v_10298 = stack[-6];
    v_10298 = qcdr(v_10298);
    goto v_9249;
v_9250:
    goto v_9244;
v_9245:
    goto v_9246;
v_9247:
    goto v_9248;
v_9249:
    v_10298 = acons(v_10300, v_10299, v_10298);
    env = stack[-9];
    stack[-6] = v_10298;
    goto v_9194;
v_9194:
    goto v_8939;
v_8941:
    v_10298 = stack[-6];
    if (v_10298 == nil) goto v_9260;
    goto v_9267;
v_9263:
    v_10298 = stack[-6];
    v_10298 = qcar(v_10298);
    v_10299 = ncons(v_10298);
    env = stack[-9];
    goto v_9264;
v_9265:
    v_10298 = stack[-6];
    v_10298 = qcdr(v_10298);
    goto v_9266;
v_9267:
    goto v_9263;
v_9264:
    goto v_9265;
v_9266:
    v_10298 = cons(v_10299, v_10298);
    env = stack[-9];
    stack[-6] = v_10298;
    goto v_9258;
v_9260:
v_9258:
    goto v_8939;
v_8942:
    v_10298 = stack[-7];
    if (v_10298 == nil) goto v_9279;
    else goto v_9280;
v_9279:
    v_10298 = lisp_true;
    goto v_9278;
v_9280:
    goto v_9293;
v_9289:
    v_10299 = stack[-7];
    goto v_9290;
v_9291:
    v_10298 = elt(env, 21); // group
    goto v_9292;
v_9293:
    goto v_9289;
v_9290:
    goto v_9291;
v_9292:
    if (v_10299 == v_10298) goto v_9287;
    else goto v_9288;
v_9287:
    v_10298 = lisp_true;
    goto v_9286;
v_9288:
    goto v_9303;
v_9299:
    v_10299 = stack[-7];
    goto v_9300;
v_9301:
    v_10298 = elt(env, 14); // proc
    goto v_9302;
v_9303:
    goto v_9299;
v_9300:
    goto v_9301;
v_9302:
    v_10298 = (v_10299 == v_10298 ? lisp_true : nil);
    goto v_9286;
    v_10298 = nil;
v_9286:
    goto v_9278;
    v_10298 = nil;
v_9278:
    if (v_10298 == nil) goto v_9276;
    goto v_9312;
v_9308:
    v_10299 = elt(env, 22); // "Too many right parentheses"
    goto v_9309;
v_9310:
    v_10298 = nil;
    goto v_9311;
v_9312:
    goto v_9308;
v_9309:
    goto v_9310;
v_9311:
    fn = elt(env, 51); // symerr
    v_10298 = (*qfn2(fn))(fn, v_10299, v_10298);
    env = stack[-9];
    goto v_9274;
v_9276:
    goto v_8955;
v_9274:
v_8943:
    fn = elt(env, 53); // eolcheck
    v_10298 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    goto v_9330;
v_9326:
    v_10299 = stack[-3];
    goto v_9327;
v_9328:
    v_10298 = elt(env, 18); // !*comma!*
    goto v_9329;
v_9330:
    goto v_9326;
v_9327:
    goto v_9328;
v_9329:
    if (v_10299 == v_10298) goto v_9324;
    else goto v_9325;
v_9324:
    v_10298 = lisp_true;
    goto v_9323;
v_9325:
    fn = elt(env, 52); // scan
    v_10298 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    stack[-2] = v_10298;
    if (!consp(v_10298)) goto v_9339;
    v_10298 = lisp_true;
    goto v_9337;
v_9339:
    v_10298 = stack[-2];
    fn = elt(env, 49); // toknump
    v_10298 = (*qfn1(fn))(fn, v_10298);
    env = stack[-9];
    goto v_9337;
    v_10298 = nil;
v_9337:
    goto v_9323;
    v_10298 = nil;
v_9323:
    if (v_10298 == nil) goto v_9321;
    goto v_8944;
v_9321:
    goto v_9356;
v_9352:
    v_10299 = stack[-2];
    goto v_9353;
v_9354:
    v_10298 = elt(env, 4); // !*rpar!*
    goto v_9355;
v_9356:
    goto v_9352;
v_9353:
    goto v_9354;
v_9355:
    if (v_10299 == v_10298) goto v_9350;
    else goto v_9351;
v_9350:
    v_10298 = lisp_true;
    goto v_9349;
v_9351:
    goto v_9370;
v_9366:
    v_10299 = stack[-2];
    goto v_9367;
v_9368:
    v_10298 = elt(env, 18); // !*comma!*
    goto v_9369;
v_9370:
    goto v_9366;
v_9367:
    goto v_9368;
v_9369:
    if (v_10299 == v_10298) goto v_9364;
    else goto v_9365;
v_9364:
    v_10298 = lisp_true;
    goto v_9363;
v_9365:
    v_10298 = stack[-2];
    if (!symbolp(v_10298)) v_10298 = nil;
    else { v_10298 = qfastgets(v_10298);
           if (v_10298 != nil) { v_10298 = elt(v_10298, 55); // delim
#ifdef RECORD_GET
             if (v_10298 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v_10298 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v_10298 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v_10298 == SPID_NOPROP) v_10298 = nil; else v_10298 = lisp_true; }}
#endif
    goto v_9363;
    v_10298 = nil;
v_9363:
    goto v_9349;
    v_10298 = nil;
v_9349:
    if (v_10298 == nil) goto v_9347;
    goto v_8945;
v_9347:
    goto v_9388;
v_9384:
    v_10299 = stack[-2];
    goto v_9385;
v_9386:
    v_10298 = elt(env, 3); // !*lpar!*
    goto v_9387;
v_9388:
    goto v_9384;
v_9385:
    goto v_9386;
v_9387:
    if (v_10299 == v_10298) goto v_9382;
    else goto v_9383;
v_9382:
    fn = elt(env, 53); // eolcheck
    v_10298 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    if (v_10298 == nil) goto v_9393;
    else goto v_9394;
v_9393:
    v_10298 = elt(env, 17); // paren
    fn = elt(env, 55); // xread
    v_10298 = (*qfn1(fn))(fn, v_10298);
    env = stack[-9];
    stack[-2] = v_10298;
    if (!consp(v_10298)) goto v_9399;
    goto v_9410;
v_9406:
    v_10298 = stack[-2];
    v_10299 = qcar(v_10298);
    goto v_9407;
v_9408:
    v_10298 = elt(env, 18); // !*comma!*
    goto v_9409;
v_9410:
    goto v_9406;
v_9407:
    goto v_9408;
v_9409:
    if (v_10299 == v_10298) goto v_9404;
    else goto v_9405;
v_9404:
    goto v_9419;
v_9415:
    v_10299 = stack[-3];
    goto v_9416;
v_9417:
    v_10298 = stack[-2];
    v_10298 = qcdr(v_10298);
    goto v_9418;
v_9419:
    goto v_9415;
v_9416:
    goto v_9417;
v_9418:
    v_10298 = cons(v_10299, v_10298);
    env = stack[-9];
    stack[-3] = v_10298;
    goto v_9403;
v_9405:
    v_10298 = nil;
    goto v_9403;
    v_10298 = nil;
v_9403:
    goto v_9397;
v_9399:
    v_10298 = nil;
    goto v_9397;
    v_10298 = nil;
v_9397:
    goto v_9392;
v_9394:
    v_10298 = nil;
    goto v_9392;
    v_10298 = nil;
v_9392:
    goto v_9381;
v_9383:
    v_10298 = nil;
    goto v_9381;
    v_10298 = nil;
v_9381:
    if (v_10298 == nil) goto v_9379;
    goto v_8936;
v_9379:
v_8944:
    v_10298 = stack[-6];
    if (v_10298 == nil) goto v_9438;
    goto v_8947;
v_9438:
    goto v_9447;
v_9443:
    v_10299 = stack[-3];
    goto v_9444;
v_9445:
    v_10298 = elt(env, 23); // unary
    goto v_9446;
v_9447:
    goto v_9443;
v_9444:
    goto v_9445;
v_9446:
    v_10298 = get(v_10299, v_10298);
    env = stack[-9];
    stack[-3] = v_10298;
    if (v_10298 == nil) goto v_9440;
    else goto v_9441;
v_9440:
    goto v_9455;
v_9451:
    v_10299 = elt(env, 24); // "Redundant operator"
    goto v_9452;
v_9453:
    v_10298 = nil;
    goto v_9454;
v_9455:
    goto v_9451;
v_9452:
    goto v_9453;
v_9454:
    fn = elt(env, 51); // symerr
    v_10298 = (*qfn2(fn))(fn, v_10299, v_10298);
    env = stack[-9];
    goto v_9436;
v_9441:
v_9436:
    goto v_9463;
v_9459:
    v_10299 = elt(env, 25); // !*!*un!*!*
    goto v_9460;
v_9461:
    v_10298 = stack[-8];
    goto v_9462;
v_9463:
    goto v_9459;
v_9460:
    goto v_9461;
v_9462:
    v_10298 = cons(v_10299, v_10298);
    env = stack[-9];
    stack[-8] = v_10298;
    goto v_8951;
v_8945:
    v_10298 = stack[-4];
    if (v_10298 == nil) goto v_9469;
    v_10298 = nil;
    stack[-4] = v_10298;
    goto v_9467;
v_9469:
v_9467:
    goto v_9477;
v_9473:
    v_10299 = stack[-3];
    goto v_9474;
v_9475:
    v_10298 = stack[-6];
    goto v_9476;
v_9477:
    goto v_9473;
v_9474:
    goto v_9475;
v_9476:
    v_10298 = cons(v_10299, v_10298);
    env = stack[-9];
    stack[-6] = v_10298;
v_8946:
    v_10298 = stack[-2];
    stack[-3] = v_10298;
    goto v_8936;
v_8947:
    v_10298 = stack[-6];
    if (v_10298 == nil) goto v_9483;
    else goto v_9484;
v_9483:
    goto v_9491;
v_9487:
    v_10299 = elt(env, 20); // "Improper delimiter"
    goto v_9488;
v_9489:
    v_10298 = nil;
    goto v_9490;
v_9491:
    goto v_9487;
v_9488:
    goto v_9489;
v_9490:
    fn = elt(env, 51); // symerr
    v_10298 = (*qfn2(fn))(fn, v_10299, v_10298);
    env = stack[-9];
    goto v_9482;
v_9484:
v_9482:
    goto v_9499;
v_9495:
    v_10298 = stack[-6];
    v_10299 = qcar(v_10298);
    goto v_9496;
v_9497:
    v_10298 = stack[-3];
    goto v_9498;
v_9499:
    goto v_9495;
v_9496:
    goto v_9497;
v_9498:
    fn = elt(env, 56); // mkvar
    v_10298 = (*qfn2(fn))(fn, v_10299, v_10298);
    env = stack[-9];
    stack[0] = v_10298;
v_8948:
    v_10298 = stack[-6];
    v_10298 = qcdr(v_10298);
    stack[-6] = v_10298;
    v_10298 = stack[-6];
    if (v_10298 == nil) goto v_9507;
    else goto v_9508;
v_9507:
    goto v_8949;
v_9508:
    v_10298 = stack[-6];
    v_10298 = qcar(v_10298);
    if (!consp(v_10298)) goto v_9514;
    else goto v_9515;
v_9514:
    v_10298 = stack[-6];
    v_10298 = qcar(v_10298);
    v_10298 = Lsymbolp(nil, v_10298);
    env = stack[-9];
    v_10298 = (v_10298 == nil ? lisp_true : nil);
    goto v_9513;
v_9515:
    v_10298 = nil;
    goto v_9513;
    v_10298 = nil;
v_9513:
    if (v_10298 == nil) goto v_9511;
    goto v_9530;
v_9526:
    v_10299 = elt(env, 26); // "Missing operator"
    goto v_9527;
v_9528:
    v_10298 = nil;
    goto v_9529;
v_9530:
    goto v_9526;
v_9527:
    goto v_9528;
v_9529:
    fn = elt(env, 51); // symerr
    v_10298 = (*qfn2(fn))(fn, v_10299, v_10298);
    env = stack[-9];
    goto v_9506;
v_9511:
v_9506:
    goto v_9538;
v_9534:
    v_10298 = stack[-6];
    v_10299 = qcar(v_10298);
    goto v_9535;
v_9536:
    v_10298 = stack[0];
    goto v_9537;
v_9538:
    goto v_9534;
v_9535:
    goto v_9536;
v_9537:
    v_10298 = list2(v_10299, v_10298);
    env = stack[-9];
    stack[0] = v_10298;
    goto v_8948;
v_8949:
    goto v_9547;
v_9543:
    v_10299 = stack[0];
    goto v_9544;
v_9545:
    v_10298 = stack[-8];
    goto v_9546;
v_9547:
    goto v_9543;
v_9544:
    goto v_9545;
v_9546:
    v_10298 = cons(v_10299, v_10298);
    env = stack[-9];
    stack[-8] = v_10298;
v_8950:
    v_10298 = stack[-5];
    if (v_10298 == nil) goto v_9552;
    else goto v_9553;
v_9552:
    goto v_9563;
v_9559:
    v_10299 = stack[-4];
    goto v_9560;
v_9561:
    v_10298 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9562;
v_9563:
    goto v_9559;
v_9560:
    goto v_9561;
v_9562:
    if (v_10299 == v_10298) goto v_9557;
    else goto v_9558;
v_9557:
    goto v_8956;
v_9558:
    goto v_9556;
v_9556:
    goto v_9551;
v_9553:
    v_10298 = stack[-8];
    if (v_10298 == nil) goto v_9570;
    goto v_9583;
v_9579:
    v_10298 = stack[-8];
    v_10299 = qcdr(v_10298);
    goto v_9580;
v_9581:
    v_10298 = elt(env, 25); // !*!*un!*!*
    goto v_9582;
v_9583:
    goto v_9579;
v_9580:
    goto v_9581;
v_9582:
    if (!consp(v_10299)) goto v_9577;
    v_10299 = qcar(v_10299);
    if (v_10299 == v_10298) goto v_9576;
    else goto v_9577;
v_9576:
    v_10298 = stack[-5];
    v_10298 = qcdr(v_10298);
    if (v_10298 == nil) goto v_9589;
    else goto v_9590;
v_9589:
    v_10298 = nil;
    goto v_9588;
v_9590:
    goto v_9605;
v_9601:
    v_10299 = stack[-4];
    goto v_9602;
v_9603:
    v_10298 = stack[-5];
    v_10298 = qcar(v_10298);
    v_10298 = qcar(v_10298);
    goto v_9604;
v_9605:
    goto v_9601;
v_9602:
    goto v_9603;
v_9604:
    v_10298 = (LispObject)geq2(v_10299, v_10298);
    v_10298 = v_10298 ? lisp_true : nil;
    env = stack[-9];
    if (v_10298 == nil) goto v_9598;
    else goto v_9599;
v_9598:
    v_10298 = nil;
    goto v_9597;
v_9599:
    goto v_9618;
v_9614:
    v_10299 = stack[-4];
    goto v_9615;
v_9616:
    v_10298 = stack[-5];
    v_10298 = qcdr(v_10298);
    v_10298 = qcar(v_10298);
    v_10298 = qcar(v_10298);
    goto v_9617;
v_9618:
    goto v_9614;
v_9615:
    goto v_9616;
v_9617:
    v_10298 = (LispObject)lesseq2(v_10299, v_10298);
    v_10298 = v_10298 ? lisp_true : nil;
    env = stack[-9];
    goto v_9597;
    v_10298 = nil;
v_9597:
    goto v_9588;
    v_10298 = nil;
v_9588:
    goto v_9575;
v_9577:
    v_10298 = nil;
    goto v_9575;
    v_10298 = nil;
v_9575:
    if (v_10298 == nil) goto v_9570;
    goto v_9632;
v_9628:
    v_10299 = elt(env, 27); // "Please use parentheses around use of the unary operator"
    goto v_9629;
v_9630:
    v_10298 = nil;
    goto v_9631;
v_9632:
    goto v_9628;
v_9629:
    goto v_9630;
v_9631:
    fn = elt(env, 51); // symerr
    v_10298 = (*qfn2(fn))(fn, v_10299, v_10298);
    env = stack[-9];
    goto v_9551;
v_9570:
    goto v_9643;
v_9639:
    v_10299 = stack[-4];
    goto v_9640;
v_9641:
    v_10298 = stack[-5];
    v_10298 = qcar(v_10298);
    v_10298 = qcar(v_10298);
    goto v_9642;
v_9643:
    goto v_9639;
v_9640:
    goto v_9641;
v_9642:
    v_10298 = (LispObject)lessp2(v_10299, v_10298);
    v_10298 = v_10298 ? lisp_true : nil;
    env = stack[-9];
    if (v_10298 == nil) goto v_9637;
    else goto v_9635;
v_9637:
    goto v_9657;
v_9653:
    v_10299 = stack[-4];
    goto v_9654;
v_9655:
    v_10298 = stack[-5];
    v_10298 = qcar(v_10298);
    v_10298 = qcar(v_10298);
    goto v_9656;
v_9657:
    goto v_9653;
v_9654:
    goto v_9655;
v_9656:
    if (equal(v_10299, v_10298)) goto v_9651;
    else goto v_9652;
v_9651:
    goto v_9674;
v_9670:
    v_10299 = stack[-3];
    goto v_9671;
v_9672:
    v_10298 = stack[-5];
    v_10298 = qcar(v_10298);
    v_10298 = qcdr(v_10298);
    goto v_9673;
v_9674:
    goto v_9670;
v_9671:
    goto v_9672;
v_9673:
    if (v_10299 == v_10298) goto v_9668;
    else goto v_9669;
v_9668:
    v_10298 = stack[-3];
    if (!symbolp(v_10298)) v_10298 = nil;
    else { v_10298 = qfastgets(v_10298);
           if (v_10298 != nil) { v_10298 = elt(v_10298, 35); // nary
#ifdef RECORD_GET
             if (v_10298 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v_10298 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v_10298 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v_10298 == SPID_NOPROP) v_10298 = nil; else v_10298 = lisp_true; }}
#endif
    if (v_10298 == nil) goto v_9681;
    else goto v_9682;
v_9681:
    goto v_9690;
v_9686:
    v_10299 = stack[-3];
    goto v_9687;
v_9688:
    v_10298 = elt(env, 28); // right
    goto v_9689;
v_9690:
    goto v_9686;
v_9687:
    goto v_9688;
v_9689:
    v_10298 = Lflagp(nil, v_10299, v_10298);
    env = stack[-9];
    v_10298 = (v_10298 == nil ? lisp_true : nil);
    goto v_9680;
v_9682:
    v_10298 = nil;
    goto v_9680;
    v_10298 = nil;
v_9680:
    goto v_9667;
v_9669:
    v_10298 = nil;
    goto v_9667;
    v_10298 = nil;
v_9667:
    if (v_10298 == nil) goto v_9665;
    v_10298 = lisp_true;
    goto v_9663;
v_9665:
    v_10298 = stack[-5];
    v_10298 = qcar(v_10298);
    v_10298 = qcdr(v_10298);
    if (!symbolp(v_10298)) v_10298 = nil;
    else { v_10298 = qfastgets(v_10298);
           if (v_10298 != nil) { v_10298 = elt(v_10298, 49); // alt
#ifdef RECORD_GET
             if (v_10298 != SPID_NOPROP)
                record_get(elt(fastget_names, 49), 1);
             else record_get(elt(fastget_names, 49), 0),
                v_10298 = nil; }
           else record_get(elt(fastget_names, 49), 0); }
#else
             if (v_10298 == SPID_NOPROP) v_10298 = nil; }}
#endif
    goto v_9663;
    v_10298 = nil;
v_9663:
    goto v_9650;
v_9652:
    v_10298 = nil;
    goto v_9650;
    v_10298 = nil;
v_9650:
    if (v_10298 == nil) goto v_9648;
    else goto v_9635;
v_9648:
    goto v_9636;
v_9635:
    goto v_8952;
v_9636:
v_9551:
v_8951:
    goto v_9717;
v_9711:
    v_10300 = stack[-4];
    goto v_9712;
v_9713:
    v_10299 = stack[-3];
    goto v_9714;
v_9715:
    v_10298 = stack[-5];
    goto v_9716;
v_9717:
    goto v_9711;
v_9712:
    goto v_9713;
v_9714:
    goto v_9715;
v_9716:
    v_10298 = acons(v_10300, v_10299, v_10298);
    env = stack[-9];
    stack[-5] = v_10298;
    goto v_9729;
v_9725:
    v_10299 = stack[-3];
    goto v_9726;
v_9727:
    v_10298 = elt(env, 18); // !*comma!*
    goto v_9728;
v_9729:
    goto v_9725;
v_9726:
    goto v_9727;
v_9728:
    if (v_10299 == v_10298) goto v_9724;
    goto v_8946;
v_9724:
    v_10298 = stack[-5];
    v_10298 = qcdr(v_10298);
    if (v_10298 == nil) goto v_9734;
    else goto v_9732;
v_9734:
    v_10298 = stack[-7];
    if (v_10298 == nil) goto v_9740;
    else goto v_9741;
v_9740:
    v_10298 = lisp_true;
    goto v_9739;
v_9741:
    goto v_9753;
v_9749:
    v_10299 = stack[-7];
    goto v_9750;
v_9751:
    v_10298 = elt(env, 29); // (lambda paren)
    goto v_9752;
v_9753:
    goto v_9749;
v_9750:
    goto v_9751;
v_9752:
    v_10298 = Lmemq(nil, v_10299, v_10298);
    if (v_10298 == nil) goto v_9748;
    else goto v_9747;
v_9748:
    goto v_9762;
v_9758:
    v_10299 = stack[-7];
    goto v_9759;
v_9760:
    v_10298 = elt(env, 16); // struct
    goto v_9761;
v_9762:
    goto v_9758;
v_9759:
    goto v_9760;
v_9761:
    v_10298 = Lflagp(nil, v_10299, v_10298);
    env = stack[-9];
v_9747:
    goto v_9739;
    v_10298 = nil;
v_9739:
    if (v_10298 == nil) goto v_9737;
    else goto v_9732;
v_9737:
    goto v_9733;
v_9732:
    goto v_8939;
v_9733:
    goto v_8956;
v_8952:
    goto v_9780;
v_9776:
    v_10298 = stack[-8];
    v_10298 = qcdr(v_10298);
    v_10299 = qcar(v_10298);
    goto v_9777;
v_9778:
    v_10298 = elt(env, 30); // not
    goto v_9779;
v_9780:
    goto v_9776;
v_9777:
    goto v_9778;
v_9779:
    if (!consp(v_10299)) goto v_9774;
    v_10299 = qcar(v_10299);
    if (v_10299 == v_10298) goto v_9773;
    else goto v_9774;
v_9773:
    goto v_9790;
v_9786:
    v_10298 = stack[-5];
    v_10298 = qcar(v_10298);
    v_10299 = qcar(v_10298);
    goto v_9787;
v_9788:
    v_10298 = elt(env, 31); // member
    if (!symbolp(v_10298)) v_10298 = nil;
    else { v_10298 = qfastgets(v_10298);
           if (v_10298 != nil) { v_10298 = elt(v_10298, 23); // infix
#ifdef RECORD_GET
             if (v_10298 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_10298 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_10298 == SPID_NOPROP) v_10298 = nil; }}
#endif
    goto v_9789;
v_9790:
    goto v_9786;
v_9787:
    goto v_9788;
v_9789:
    v_10298 = (LispObject)geq2(v_10299, v_10298);
    v_10298 = v_10298 ? lisp_true : nil;
    env = stack[-9];
    goto v_9772;
v_9774:
    v_10298 = nil;
    goto v_9772;
    v_10298 = nil;
v_9772:
    if (v_10298 == nil) goto v_9770;
    goto v_9804;
v_9800:
    v_10299 = elt(env, 32); // "NOT"
    goto v_9801;
v_9802:
    v_10298 = elt(env, 33); // "infix operator"
    goto v_9803;
v_9804:
    goto v_9800;
v_9801:
    goto v_9802;
v_9803:
    fn = elt(env, 57); // typerr
    v_10298 = (*qfn2(fn))(fn, v_10299, v_10298);
    env = stack[-9];
    goto v_9768;
v_9770:
v_9768:
    goto v_9815;
v_9811:
    v_10298 = stack[-8];
    v_10298 = qcdr(v_10298);
    v_10299 = qcar(v_10298);
    goto v_9812;
v_9813:
    v_10298 = elt(env, 25); // !*!*un!*!*
    goto v_9814;
v_9815:
    goto v_9811;
v_9812:
    goto v_9813;
v_9814:
    if (v_10299 == v_10298) goto v_9809;
    else goto v_9810;
v_9809:
    goto v_9828;
v_9824:
    v_10298 = stack[-8];
    v_10299 = qcar(v_10298);
    goto v_9825;
v_9826:
    v_10298 = elt(env, 25); // !*!*un!*!*
    goto v_9827;
v_9828:
    goto v_9824;
v_9825:
    goto v_9826;
v_9827:
    if (v_10299 == v_10298) goto v_9822;
    else goto v_9823;
v_9822:
    goto v_8951;
v_9823:
    goto v_9839;
v_9835:
    v_10298 = stack[-5];
    v_10298 = qcar(v_10298);
    v_10299 = qcdr(v_10298);
    goto v_9836;
v_9837:
    v_10298 = stack[-8];
    v_10298 = qcar(v_10298);
    goto v_9838;
v_9839:
    goto v_9835;
v_9836:
    goto v_9837;
v_9838:
    v_10298 = list2(v_10299, v_10298);
    env = stack[-9];
    stack[0] = v_10298;
    goto v_9821;
v_9821:
    goto v_9808;
v_9810:
    goto v_9852;
v_9848:
    v_10298 = stack[-5];
    v_10298 = qcar(v_10298);
    stack[0] = qcdr(v_10298);
    goto v_9849;
v_9850:
    goto v_9869;
v_9865:
    v_10298 = stack[-8];
    v_10299 = qcar(v_10298);
    goto v_9866;
v_9867:
    v_10298 = stack[-5];
    v_10298 = qcar(v_10298);
    v_10298 = qcdr(v_10298);
    goto v_9868;
v_9869:
    goto v_9865;
v_9866:
    goto v_9867;
v_9868:
    if (!consp(v_10299)) goto v_9863;
    v_10299 = qcar(v_10299);
    if (v_10299 == v_10298) goto v_9862;
    else goto v_9863;
v_9862:
    v_10298 = stack[-5];
    v_10298 = qcar(v_10298);
    v_10298 = qcdr(v_10298);
    if (!symbolp(v_10298)) v_10298 = nil;
    else { v_10298 = qfastgets(v_10298);
           if (v_10298 != nil) { v_10298 = elt(v_10298, 35); // nary
#ifdef RECORD_GET
             if (v_10298 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v_10298 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v_10298 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v_10298 == SPID_NOPROP) v_10298 = nil; else v_10298 = lisp_true; }}
#endif
    goto v_9861;
v_9863:
    v_10298 = nil;
    goto v_9861;
    v_10298 = nil;
v_9861:
    if (v_10298 == nil) goto v_9859;
    goto v_9887;
v_9883:
    v_10298 = stack[-8];
    v_10298 = qcdr(v_10298);
    v_10299 = qcar(v_10298);
    goto v_9884;
v_9885:
    v_10298 = stack[-8];
    v_10298 = qcar(v_10298);
    v_10298 = qcdr(v_10298);
    goto v_9886;
v_9887:
    goto v_9883;
v_9884:
    goto v_9885;
v_9886:
    v_10298 = cons(v_10299, v_10298);
    env = stack[-9];
    goto v_9857;
v_9859:
    goto v_9901;
v_9897:
    v_10298 = stack[-8];
    v_10298 = qcdr(v_10298);
    v_10299 = qcar(v_10298);
    goto v_9898;
v_9899:
    v_10298 = stack[-8];
    v_10298 = qcar(v_10298);
    goto v_9900;
v_9901:
    goto v_9897;
v_9898:
    goto v_9899;
v_9900:
    v_10298 = list2(v_10299, v_10298);
    env = stack[-9];
    goto v_9857;
    v_10298 = nil;
v_9857:
    goto v_9851;
v_9852:
    goto v_9848;
v_9849:
    goto v_9850;
v_9851:
    v_10298 = cons(stack[0], v_10298);
    env = stack[-9];
    stack[0] = v_10298;
    goto v_9808;
v_9808:
    v_10298 = stack[-5];
    v_10298 = qcdr(v_10298);
    stack[-5] = v_10298;
    goto v_9914;
v_9910:
    v_10299 = stack[0];
    goto v_9911;
v_9912:
    v_10298 = stack[-8];
    v_10298 = qcdr(v_10298);
    v_10298 = qcdr(v_10298);
    goto v_9913;
v_9914:
    goto v_9910;
v_9911:
    goto v_9912;
v_9913:
    v_10298 = cons(v_10299, v_10298);
    env = stack[-9];
    stack[-8] = v_10298;
    goto v_8950;
v_8953:
    goto v_9927;
v_9923:
    v_10299 = stack[-4];
    goto v_9924;
v_9925:
    v_10298 = elt(env, 34); // endstat
    goto v_9926;
v_9927:
    goto v_9923;
v_9924:
    goto v_9925;
v_9926:
    if (v_10299 == v_10298) goto v_9922;
    fn = elt(env, 53); // eolcheck
    v_10298 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    goto v_9920;
v_9922:
v_9920:
    goto v_9944;
v_9940:
    v_10299 = stack[-3];
    goto v_9941;
v_9942:
    v_10298 = elt(env, 35); // go
    goto v_9943;
v_9944:
    goto v_9940;
v_9941:
    goto v_9942;
v_9943:
    v_10298 = Lflagp(nil, v_10299, v_10298);
    env = stack[-9];
    if (v_10298 == nil) goto v_9938;
    v_10298 = lisp_true;
    goto v_9936;
v_9938:
    goto v_9958;
v_9954:
    v_10299 = stack[-7];
    goto v_9955;
v_9956:
    v_10298 = elt(env, 14); // proc
    goto v_9957;
v_9958:
    goto v_9954;
v_9955:
    goto v_9956;
v_9957:
    if (v_10299 == v_10298) goto v_9953;
    goto v_9970;
v_9966:
    v_10299 = stack[-4];
    goto v_9967;
v_9968:
    v_10298 = elt(env, 36); // endstatfn
    goto v_9969;
v_9970:
    goto v_9966;
v_9967:
    goto v_9968;
v_9969:
    v_10298 = Lflagp(nil, v_10299, v_10298);
    env = stack[-9];
    if (v_10298 == nil) goto v_9964;
    v_10298 = lisp_true;
    goto v_9962;
v_9964:
    v_10298 = qvalue(elt(env, 9)); // nxtsym!*
    fn = elt(env, 58); // delcp
    v_10298 = (*qfn1(fn))(fn, v_10298);
    env = stack[-9];
    if (v_10298 == nil) goto v_9978;
    else goto v_9979;
v_9978:
    goto v_9986;
v_9982:
    v_10299 = qvalue(elt(env, 9)); // nxtsym!*
    goto v_9983;
v_9984:
    v_10298 = elt(env, 37); // !,
    goto v_9985;
v_9986:
    goto v_9982;
v_9983:
    goto v_9984;
v_9985:
    v_10298 = (v_10299 == v_10298 ? lisp_true : nil);
    v_10298 = (v_10298 == nil ? lisp_true : nil);
    goto v_9977;
v_9979:
    v_10298 = nil;
    goto v_9977;
    v_10298 = nil;
v_9977:
    goto v_9962;
    v_10298 = nil;
v_9962:
    goto v_9951;
v_9953:
    v_10298 = nil;
    goto v_9951;
    v_10298 = nil;
v_9951:
    goto v_9936;
    v_10298 = nil;
v_9936:
    if (v_10298 == nil) goto v_9933;
    else goto v_9934;
v_9933:
    goto v_8937;
v_9934:
    goto v_10009;
v_10005:
    v_10299 = stack[-3];
    goto v_10006;
v_10007:
    v_10298 = elt(env, 38); // procedure
    goto v_10008;
v_10009:
    goto v_10005;
v_10006:
    goto v_10007;
v_10008:
    if (v_10299 == v_10298) goto v_10003;
    else goto v_10004;
v_10003:
    v_10298 = qvalue(elt(env, 5)); // !*reduce4
    goto v_10002;
v_10004:
    v_10298 = nil;
    goto v_10002;
    v_10298 = nil;
v_10002:
    if (v_10298 == nil) goto v_10000;
    v_10298 = stack[-6];
    if (v_10298 == nil) goto v_10019;
    v_10298 = stack[-6];
    v_10298 = qcdr(v_10298);
    if (v_10298 == nil) goto v_10025;
    else goto v_10023;
v_10025:
    v_10298 = qvalue(elt(env, 5)); // !*reduce4
    if (v_10298 == nil) goto v_10028;
    else goto v_10023;
v_10028:
    goto v_10024;
v_10023:
    goto v_10035;
v_10031:
    v_10299 = elt(env, 39); // "proc form"
    goto v_10032;
v_10033:
    v_10298 = nil;
    goto v_10034;
v_10035:
    goto v_10031;
v_10032:
    goto v_10033;
v_10034:
    fn = elt(env, 51); // symerr
    v_10298 = (*qfn2(fn))(fn, v_10299, v_10298);
    env = stack[-9];
    goto v_10022;
v_10024:
    v_10298 = stack[-6];
    v_10298 = qcar(v_10298);
    fn = elt(env, 59); // procstat1
    v_10298 = (*qfn1(fn))(fn, v_10298);
    env = stack[-9];
    v_10298 = ncons(v_10298);
    env = stack[-9];
    stack[-6] = v_10298;
    goto v_10022;
v_10022:
    goto v_10017;
v_10019:
    v_10298 = nil;
    fn = elt(env, 59); // procstat1
    v_10298 = (*qfn1(fn))(fn, v_10298);
    env = stack[-9];
    v_10298 = ncons(v_10298);
    env = stack[-9];
    stack[-6] = v_10298;
    goto v_10017;
v_10017:
    goto v_9998;
v_10000:
    goto v_10056;
v_10052:
    goto v_10062;
v_10058:
    v_10299 = stack[-4];
    goto v_10059;
v_10060:
    v_10298 = nil;
    goto v_10061;
v_10062:
    goto v_10058;
v_10059:
    goto v_10060;
v_10061:
    fn = elt(env, 48); // lispapply
    v_10299 = (*qfn2(fn))(fn, v_10299, v_10298);
    env = stack[-9];
    goto v_10053;
v_10054:
    v_10298 = stack[-6];
    goto v_10055;
v_10056:
    goto v_10052;
v_10053:
    goto v_10054;
v_10055:
    v_10298 = cons(v_10299, v_10298);
    env = stack[-9];
    stack[-6] = v_10298;
    goto v_9998;
v_9998:
    v_10298 = nil;
    stack[-4] = v_10298;
    goto v_8935;
v_8954:
    goto v_10075;
v_10071:
    v_10299 = qvalue(elt(env, 2)); // cursym!*
    goto v_10072;
v_10073:
    v_10298 = elt(env, 40); // !*semicol!*
    goto v_10074;
v_10075:
    goto v_10071;
v_10072:
    goto v_10073;
v_10074:
    if (v_10299 == v_10298) goto v_10070;
    fn = elt(env, 53); // eolcheck
    v_10298 = (*qfnn(fn))(fn, 0);
    env = stack[-9];
    goto v_10068;
v_10070:
v_10068:
    goto v_10092;
v_10088:
    v_10299 = stack[-3];
    goto v_10089;
v_10090:
    v_10298 = elt(env, 41); // !*colon!*
    goto v_10091;
v_10092:
    goto v_10088;
v_10089:
    goto v_10090;
v_10091:
    if (v_10299 == v_10298) goto v_10086;
    else goto v_10087;
v_10086:
    goto v_10103;
v_10099:
    v_10299 = stack[-7];
    goto v_10100;
v_10101:
    v_10298 = elt(env, 42); // for
    goto v_10102;
v_10103:
    goto v_10099;
v_10100:
    goto v_10101;
v_10102:
    if (v_10299 == v_10298) goto v_10098;
    v_10298 = qvalue(elt(env, 43)); // !*blockp
    if (v_10298 == nil) goto v_10108;
    else goto v_10109;
v_10108:
    v_10298 = lisp_true;
    goto v_10107;
v_10109:
    v_10298 = stack[-6];
    if (v_10298 == nil) goto v_10116;
    else goto v_10117;
v_10116:
    v_10298 = lisp_true;
    goto v_10115;
v_10117:
    v_10298 = stack[-6];
    v_10298 = qcar(v_10298);
    if (!consp(v_10298)) goto v_10125;
    v_10298 = lisp_true;
    goto v_10123;
v_10125:
    v_10298 = stack[-6];
    v_10298 = qcdr(v_10298);
    goto v_10123;
    v_10298 = nil;
v_10123:
    goto v_10115;
    v_10298 = nil;
v_10115:
    goto v_10107;
    v_10298 = nil;
v_10107:
    goto v_10096;
v_10098:
    v_10298 = nil;
    goto v_10096;
    v_10298 = nil;
v_10096:
    goto v_10085;
v_10087:
    v_10298 = nil;
    goto v_10085;
    v_10298 = nil;
v_10085:
    if (v_10298 == nil) goto v_10083;
    else goto v_10081;
v_10083:
    goto v_10149;
v_10145:
    v_10299 = stack[-3];
    goto v_10146;
v_10147:
    v_10298 = elt(env, 44); // nodel
    goto v_10148;
v_10149:
    goto v_10145;
v_10146:
    goto v_10147;
v_10148:
    v_10298 = Lflagp(nil, v_10299, v_10298);
    env = stack[-9];
    if (v_10298 == nil) goto v_10143;
    v_10298 = stack[-7];
    if (v_10298 == nil) goto v_10154;
    else goto v_10155;
v_10154:
    v_10298 = lisp_true;
    goto v_10153;
v_10155:
    goto v_10168;
v_10164:
    v_10299 = stack[-7];
    goto v_10165;
v_10166:
    v_10298 = elt(env, 21); // group
    goto v_10167;
v_10168:
    goto v_10164;
v_10165:
    goto v_10166;
v_10167:
    if (v_10299 == v_10298) goto v_10162;
    else goto v_10163;
v_10162:
    goto v_10175;
v_10171:
    v_10299 = stack[-3];
    goto v_10172;
v_10173:
    v_10298 = elt(env, 45); // (!*rsqbkt!* !*rcbkt!* !*rsqb!*)
    goto v_10174;
v_10175:
    goto v_10171;
v_10172:
    goto v_10173;
v_10174:
    v_10298 = Lmemq(nil, v_10299, v_10298);
    v_10298 = (v_10298 == nil ? lisp_true : nil);
    goto v_10161;
v_10163:
    v_10298 = nil;
    goto v_10161;
    v_10298 = nil;
v_10161:
    goto v_10153;
    v_10298 = nil;
v_10153:
    goto v_10141;
v_10143:
    v_10298 = nil;
    goto v_10141;
    v_10298 = nil;
v_10141:
    if (v_10298 == nil) goto v_10139;
    else goto v_10081;
v_10139:
    goto v_10082;
v_10081:
    goto v_10191;
v_10187:
    v_10299 = elt(env, 20); // "Improper delimiter"
    goto v_10188;
v_10189:
    v_10298 = nil;
    goto v_10190;
v_10191:
    goto v_10187;
v_10188:
    goto v_10189;
v_10190:
    fn = elt(env, 51); // symerr
    v_10298 = (*qfn2(fn))(fn, v_10299, v_10298);
    env = stack[-9];
    goto v_10080;
v_10082:
    v_10298 = stack[-7];
    if (symbolp(v_10298)) goto v_10196;
    else goto v_10195;
v_10196:
    goto v_10207;
v_10203:
    v_10299 = stack[-7];
    goto v_10204;
v_10205:
    v_10298 = elt(env, 17); // paren
    goto v_10206;
v_10207:
    goto v_10203;
v_10204:
    goto v_10205;
v_10206:
    if (v_10299 == v_10298) goto v_10201;
    else goto v_10202;
v_10201:
    v_10298 = lisp_true;
    goto v_10200;
v_10202:
    goto v_10218;
v_10214:
    v_10299 = stack[-7];
    goto v_10215;
v_10216:
    v_10298 = elt(env, 16); // struct
    goto v_10217;
v_10218:
    goto v_10214;
v_10215:
    goto v_10216;
v_10217:
    v_10298 = Lflagp(nil, v_10299, v_10298);
    env = stack[-9];
    goto v_10200;
    v_10298 = nil;
v_10200:
    if (v_10298 == nil) goto v_10195;
    goto v_10226;
v_10222:
    v_10299 = elt(env, 46); // "Too few right parentheses"
    goto v_10223;
v_10224:
    v_10298 = nil;
    goto v_10225;
v_10226:
    goto v_10222;
v_10223:
    goto v_10224;
v_10225:
    fn = elt(env, 51); // symerr
    v_10298 = (*qfn2(fn))(fn, v_10299, v_10298);
    env = stack[-9];
    goto v_10080;
v_10195:
v_10080:
v_8955:
    v_10298 = stack[-4];
    if (v_10298 == nil) goto v_10232;
    goto v_10239;
v_10235:
    v_10299 = elt(env, 20); // "Improper delimiter"
    goto v_10236;
v_10237:
    v_10298 = nil;
    goto v_10238;
v_10239:
    goto v_10235;
v_10236:
    goto v_10237;
v_10238:
    fn = elt(env, 51); // symerr
    v_10298 = (*qfn2(fn))(fn, v_10299, v_10298);
    env = stack[-9];
    goto v_10230;
v_10232:
    v_10298 = stack[-8];
    if (v_10298 == nil) goto v_10246;
    else goto v_10247;
v_10246:
    v_10298 = stack[-6];
    if (v_10298 == nil) goto v_10251;
    else goto v_10252;
v_10251:
    v_10298 = stack[-5];
    v_10298 = (v_10298 == nil ? lisp_true : nil);
    goto v_10250;
v_10252:
    v_10298 = nil;
    goto v_10250;
    v_10298 = nil;
v_10250:
    goto v_10245;
v_10247:
    v_10298 = nil;
    goto v_10245;
    v_10298 = nil;
v_10245:
    if (v_10298 == nil) goto v_10243;
    goto v_10267;
v_10263:
    v_10299 = nil;
    goto v_10264;
v_10265:
    v_10298 = stack[-1];
    goto v_10266;
v_10267:
    goto v_10263;
v_10264:
    goto v_10265;
v_10266:
    {
        fn = elt(env, 60); // xcomment
        return (*qfn2(fn))(fn, v_10299, v_10298);
    }
v_10243:
v_10230:
    v_10298 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_10298;
    goto v_8947;
v_8956:
    v_10298 = stack[-8];
    v_10298 = qcdr(v_10298);
    if (v_10298 == nil) goto v_10273;
    else goto v_10274;
v_10273:
    goto v_10282;
v_10278:
    v_10298 = stack[-8];
    v_10299 = qcar(v_10298);
    goto v_10279;
v_10280:
    v_10298 = stack[-1];
    goto v_10281;
v_10282:
    goto v_10278;
v_10279:
    goto v_10280;
v_10281:
    {
        fn = elt(env, 60); // xcomment
        return (*qfn2(fn))(fn, v_10299, v_10298);
    }
v_10274:
    v_10298 = elt(env, 47); // "Please send hearn@rand.org your program!!"
    v_10298 = Lprint(nil, v_10298);
    env = stack[-9];
    goto v_10272;
v_10272:
    goto v_10295;
v_10291:
    v_10299 = elt(env, 20); // "Improper delimiter"
    goto v_10292;
v_10293:
    v_10298 = nil;
    goto v_10294;
v_10295:
    goto v_10291;
v_10292:
    goto v_10293;
v_10294:
    fn = elt(env, 51); // symerr
    v_10298 = (*qfn2(fn))(fn, v_10299, v_10298);
    v_10298 = nil;
    return onevalue(v_10298);
}



// Code for dpmat_coldegs

static LispObject CC_dpmat_coldegs(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_8933, v_8934;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8933 = v_8923;
// end of prologue
    goto v_8930;
v_8926:
    v_8934 = v_8933;
    goto v_8927;
v_8928:
    v_8933 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_8929;
v_8930:
    goto v_8926;
v_8927:
    goto v_8928;
v_8929:
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(fn, v_8934, v_8933);
    }
}



// Code for pv_times1

static LispObject CC_pv_times1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8954, v_8955, v_8956;
    LispObject fn;
    LispObject v_8925, v_8924, v_8923;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pv_times1");
    va_start(aa, nargs);
    v_8923 = va_arg(aa, LispObject);
    v_8924 = va_arg(aa, LispObject);
    v_8925 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_8925,v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_8923,v_8924,v_8925);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_8955 = v_8925;
    stack[0] = v_8924;
    v_8954 = v_8923;
// end of prologue
v_8930:
    v_8956 = v_8954;
    if (v_8956 == nil) goto v_8933;
    else goto v_8934;
v_8933:
    v_8954 = v_8955;
    goto v_8929;
v_8934:
    v_8956 = v_8954;
    v_8956 = qcdr(v_8956);
    stack[-1] = v_8956;
    goto v_8948;
v_8942:
    v_8956 = qcar(v_8954);
    goto v_8943;
v_8944:
    v_8954 = stack[0];
    goto v_8945;
v_8946:
    goto v_8947;
v_8948:
    goto v_8942;
v_8943:
    goto v_8944;
v_8945:
    goto v_8946;
v_8947:
    fn = elt(env, 1); // pv_times2
    v_8954 = (*qfnn(fn))(fn, 3, v_8956, v_8954, v_8955);
    env = stack[-2];
    v_8955 = v_8954;
    v_8954 = stack[-1];
    goto v_8930;
    v_8954 = nil;
v_8929:
    return onevalue(v_8954);
}



// Code for b!:ordexp

static LispObject CC_bTordexp(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_8973, v_8974;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_8924;
    stack[-1] = v_8923;
// end of prologue
v_8922:
    v_8973 = stack[-1];
    if (v_8973 == nil) goto v_8928;
    else goto v_8929;
v_8928:
    v_8973 = lisp_true;
    goto v_8927;
v_8929:
    goto v_8942;
v_8938:
    v_8973 = stack[-1];
    v_8974 = qcar(v_8973);
    goto v_8939;
v_8940:
    v_8973 = stack[0];
    v_8973 = qcar(v_8973);
    goto v_8941;
v_8942:
    goto v_8938;
v_8939:
    goto v_8940;
v_8941:
    v_8973 = (LispObject)greaterp2(v_8974, v_8973);
    v_8973 = v_8973 ? lisp_true : nil;
    env = stack[-2];
    if (v_8973 == nil) goto v_8936;
    else goto v_8935;
v_8936:
    goto v_8955;
v_8951:
    v_8973 = stack[-1];
    v_8974 = qcar(v_8973);
    goto v_8952;
v_8953:
    v_8973 = stack[0];
    v_8973 = qcar(v_8973);
    goto v_8954;
v_8955:
    goto v_8951;
v_8952:
    goto v_8953;
v_8954:
    if (equal(v_8974, v_8973)) goto v_8949;
    else goto v_8950;
v_8949:
    goto v_8965;
v_8961:
    v_8973 = stack[-1];
    v_8974 = qcdr(v_8973);
    goto v_8962;
v_8963:
    v_8973 = stack[0];
    v_8973 = qcdr(v_8973);
    goto v_8964;
v_8965:
    goto v_8961;
v_8962:
    goto v_8963;
v_8964:
    stack[-1] = v_8974;
    stack[0] = v_8973;
    goto v_8922;
v_8950:
    v_8973 = nil;
    goto v_8948;
    v_8973 = nil;
v_8948:
v_8935:
    goto v_8927;
    v_8973 = nil;
v_8927:
    return onevalue(v_8973);
}



// Code for simpatom

static LispObject CC_simpatom(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_9214, v_9215, v_9216;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8923);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_8923;
// end of prologue
    v_9214 = stack[-1];
    if (v_9214 == nil) goto v_8927;
    else goto v_8928;
v_8927:
    goto v_8935;
v_8931:
    v_9215 = nil;
    goto v_8932;
v_8933:
    v_9214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8934;
v_8935:
    goto v_8931;
v_8932:
    goto v_8933;
v_8934:
    return cons(v_9215, v_9214);
v_8928:
    v_9214 = stack[-1];
    if (is_number(v_9214)) goto v_8938;
    else goto v_8939;
v_8938:
    goto v_8949;
v_8945:
    v_9215 = stack[-1];
    goto v_8946;
v_8947:
    v_9214 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8948;
v_8949:
    goto v_8945;
v_8946:
    goto v_8947;
v_8948:
    if (v_9215 == v_9214) goto v_8943;
    else goto v_8944;
v_8943:
    goto v_8957;
v_8953:
    v_9215 = nil;
    goto v_8954;
v_8955:
    v_9214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8956;
v_8957:
    goto v_8953;
v_8954:
    goto v_8955;
v_8956:
    return cons(v_9215, v_9214);
v_8944:
    v_9214 = stack[-1];
    v_9214 = integerp(v_9214);
    if (v_9214 == nil) goto v_8960;
    else goto v_8961;
v_8960:
    v_9214 = stack[-1];
    {
        fn = elt(env, 11); // rd!:simp
        return (*qfn1(fn))(fn, v_9214);
    }
v_8961:
    goto v_8976;
v_8972:
    v_9215 = qvalue(elt(env, 1)); // dmode!*
    goto v_8973;
v_8974:
    v_9214 = elt(env, 2); // !:mod!:
    goto v_8975;
v_8976:
    goto v_8972;
v_8973:
    goto v_8974;
v_8975:
    if (v_9215 == v_9214) goto v_8970;
    else goto v_8971;
v_8970:
    goto v_8983;
v_8979:
    v_9215 = qvalue(elt(env, 3)); // current!-modulus
    goto v_8980;
v_8981:
    v_9214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8982;
v_8983:
    goto v_8979;
v_8980:
    goto v_8981;
v_8982:
    v_9214 = (v_9215 == v_9214 ? lisp_true : nil);
    goto v_8969;
v_8971:
    v_9214 = nil;
    goto v_8969;
    v_9214 = nil;
v_8969:
    if (v_9214 == nil) goto v_8967;
    goto v_8995;
v_8991:
    v_9215 = nil;
    goto v_8992;
v_8993:
    v_9214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8994;
v_8995:
    goto v_8991;
v_8992:
    goto v_8993;
v_8994:
    return cons(v_9215, v_9214);
v_8967:
    v_9214 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_9214)) v_9214 = nil;
    else { v_9214 = qfastgets(v_9214);
           if (v_9214 != nil) { v_9214 = elt(v_9214, 5); // convert
#ifdef RECORD_GET
             if (v_9214 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v_9214 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v_9214 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v_9214 == SPID_NOPROP) v_9214 = nil; else v_9214 = lisp_true; }}
#endif
    if (v_9214 == nil) goto v_9003;
    goto v_9011;
v_9007:
    v_9215 = stack[-1];
    goto v_9008;
v_9009:
    v_9214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9010;
v_9011:
    goto v_9007;
v_9008:
    goto v_9009;
v_9010:
    v_9214 = Lneq(nil, v_9215, v_9214);
    env = stack[-3];
    goto v_9001;
v_9003:
    v_9214 = nil;
    goto v_9001;
    v_9214 = nil;
v_9001:
    if (v_9214 == nil) goto v_8999;
    goto v_9023;
v_9019:
    v_9214 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_9214)) v_9215 = nil;
    else { v_9215 = qfastgets(v_9214);
           if (v_9215 != nil) { v_9215 = elt(v_9215, 34); // i2d
#ifdef RECORD_GET
             if (v_9215 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_9215 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_9215 == SPID_NOPROP) v_9215 = nil; }}
#endif
    goto v_9020;
v_9021:
    v_9214 = stack[-1];
    goto v_9022;
v_9023:
    goto v_9019;
v_9020:
    goto v_9021;
v_9022:
    v_9214 = Lapply1(nil, v_9215, v_9214);
    env = stack[-3];
    {
        fn = elt(env, 12); // !*d2q
        return (*qfn1(fn))(fn, v_9214);
    }
v_8999:
    goto v_9034;
v_9030:
    v_9215 = stack[-1];
    goto v_9031;
v_9032:
    v_9214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9033;
v_9034:
    goto v_9030;
v_9031:
    goto v_9032;
v_9033:
    return cons(v_9215, v_9214);
    v_9214 = nil;
    goto v_8926;
v_8939:
    v_9214 = stack[-1];
    v_9214 = Lstringp(nil, v_9214);
    env = stack[-3];
    if (v_9214 == nil) goto v_9038;
    goto v_9046;
v_9042:
    goto v_9052;
v_9048:
    v_9215 = elt(env, 4); // "String"
    goto v_9049;
v_9050:
    v_9214 = stack[-1];
    goto v_9051;
v_9052:
    goto v_9048;
v_9049:
    goto v_9050;
v_9051:
    v_9215 = list2(v_9215, v_9214);
    env = stack[-3];
    goto v_9043;
v_9044:
    v_9214 = elt(env, 5); // "identifier"
    goto v_9045;
v_9046:
    goto v_9042;
v_9043:
    goto v_9044;
v_9045:
    {
        fn = elt(env, 13); // typerr
        return (*qfn2(fn))(fn, v_9215, v_9214);
    }
v_9038:
    v_9214 = stack[-1];
    if (!symbolp(v_9214)) v_9214 = nil;
    else { v_9214 = qfastgets(v_9214);
           if (v_9214 != nil) { v_9214 = elt(v_9214, 17); // share
#ifdef RECORD_GET
             if (v_9214 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v_9214 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v_9214 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v_9214 == SPID_NOPROP) v_9214 = nil; else v_9214 = lisp_true; }}
#endif
    if (v_9214 == nil) goto v_9057;
    v_9214 = stack[-1];
    fn = elt(env, 14); // lispeval
    v_9214 = (*qfn1(fn))(fn, v_9214);
    env = stack[-3];
    v_9216 = v_9214;
    goto v_9071;
v_9067:
    v_9215 = v_9216;
    goto v_9068;
v_9069:
    v_9214 = stack[-1];
    goto v_9070;
v_9071:
    goto v_9067;
v_9068:
    goto v_9069;
v_9070:
    if (v_9215 == v_9214) goto v_9065;
    else goto v_9066;
v_9065:
    goto v_9079;
v_9075:
    v_9215 = stack[-1];
    goto v_9076;
v_9077:
    v_9214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9078;
v_9079:
    goto v_9075;
v_9076:
    goto v_9077;
v_9078:
    {
        fn = elt(env, 15); // mksq
        return (*qfn2(fn))(fn, v_9215, v_9214);
    }
v_9066:
    v_9214 = v_9216;
    {
        fn = elt(env, 16); // simp
        return (*qfn1(fn))(fn, v_9214);
    }
    v_9214 = nil;
    goto v_8926;
v_9057:
    v_9214 = stack[-1];
    if (!symbolp(v_9214)) v_9214 = nil;
    else { v_9214 = qfastgets(v_9214);
           if (v_9214 != nil) { v_9214 = elt(v_9214, 56); // idvalfn
#ifdef RECORD_GET
             if (v_9214 != SPID_NOPROP)
                record_get(elt(fastget_names, 56), 1);
             else record_get(elt(fastget_names, 56), 0),
                v_9214 = nil; }
           else record_get(elt(fastget_names, 56), 0); }
#else
             if (v_9214 == SPID_NOPROP) v_9214 = nil; }}
#endif
    stack[-2] = v_9214;
    if (v_9214 == nil) goto v_9094;
    goto v_9102;
v_9098:
    v_9215 = stack[-2];
    goto v_9099;
v_9100:
    v_9214 = stack[-1];
    goto v_9101;
v_9102:
    goto v_9098;
v_9099:
    goto v_9100;
v_9101:
        return Lapply1(nil, v_9215, v_9214);
v_9094:
    v_9214 = qvalue(elt(env, 6)); // !*numval
    if (v_9214 == nil) goto v_9106;
    v_9214 = qvalue(elt(env, 1)); // dmode!*
    if (v_9214 == nil) goto v_9106;
    goto v_9122;
v_9118:
    v_9215 = stack[-1];
    goto v_9119;
v_9120:
    v_9214 = elt(env, 7); // constant
    goto v_9121;
v_9122:
    goto v_9118;
v_9119:
    goto v_9120;
v_9121:
    v_9214 = Lflagp(nil, v_9215, v_9214);
    env = stack[-3];
    if (v_9214 == nil) goto v_9116;
    goto v_9134;
v_9130:
    v_9215 = stack[-1];
    goto v_9131;
v_9132:
    v_9214 = qvalue(elt(env, 1)); // dmode!*
    goto v_9133;
v_9134:
    goto v_9130;
v_9131:
    goto v_9132;
v_9133:
    v_9214 = get(v_9215, v_9214);
    env = stack[-3];
    stack[-2] = v_9214;
    if (v_9214 == nil) goto v_9127;
    else goto v_9128;
v_9127:
    v_9214 = nil;
    goto v_9126;
v_9128:
    goto v_9150;
v_9146:
    goto v_9158;
v_9152:
    stack[0] = elt(env, 8); // lispapply
    goto v_9153;
v_9154:
    v_9214 = stack[-2];
    v_9215 = Lmkquote(nil, v_9214);
    env = stack[-3];
    goto v_9155;
v_9156:
    v_9214 = nil;
    goto v_9157;
v_9158:
    goto v_9152;
v_9153:
    goto v_9154;
v_9155:
    goto v_9156;
v_9157:
    v_9215 = list3(stack[0], v_9215, v_9214);
    env = stack[-3];
    goto v_9147;
v_9148:
    v_9214 = nil;
    goto v_9149;
v_9150:
    goto v_9146;
v_9147:
    goto v_9148;
v_9149:
    fn = elt(env, 17); // errorset!*
    v_9214 = (*qfn2(fn))(fn, v_9215, v_9214);
    env = stack[-3];
    stack[-2] = v_9214;
    fn = elt(env, 18); // errorp
    v_9214 = (*qfn1(fn))(fn, v_9214);
    env = stack[-3];
    if (v_9214 == nil) goto v_9142;
    else goto v_9143;
v_9142:
    goto v_9173;
v_9169:
    v_9214 = stack[-2];
    v_9215 = qcar(v_9214);
    stack[-2] = v_9215;
    goto v_9170;
v_9171:
    v_9214 = elt(env, 9); // !:rd!:
    goto v_9172;
v_9173:
    goto v_9169;
v_9170:
    goto v_9171;
v_9172:
    if (!consp(v_9215)) goto v_9166;
    v_9215 = qcar(v_9215);
    if (v_9215 == v_9214) goto v_9167;
v_9166:
    v_9214 = lisp_true;
    goto v_9165;
v_9167:
    v_9214 = stack[-2];
    v_9214 = qcdr(v_9214);
    fn = elt(env, 19); // complexp
    v_9214 = (*qfn1(fn))(fn, v_9214);
    env = stack[-3];
    v_9214 = (v_9214 == nil ? lisp_true : nil);
    goto v_9165;
    v_9214 = nil;
v_9165:
    goto v_9141;
v_9143:
    v_9214 = nil;
    goto v_9141;
    v_9214 = nil;
v_9141:
    goto v_9126;
    v_9214 = nil;
v_9126:
    goto v_9114;
v_9116:
    v_9214 = nil;
    goto v_9114;
    v_9214 = nil;
v_9114:
    if (v_9214 == nil) goto v_9106;
    v_9214 = stack[-2];
    {
        fn = elt(env, 12); // !*d2q
        return (*qfn1(fn))(fn, v_9214);
    }
v_9106:
    v_9214 = stack[-1];
    fn = elt(env, 20); // getrtype
    v_9214 = (*qfn1(fn))(fn, v_9214);
    env = stack[-3];
    if (v_9214 == nil) goto v_9193;
    goto v_9201;
v_9197:
    v_9215 = stack[-1];
    goto v_9198;
v_9199:
    v_9214 = elt(env, 10); // scalar
    goto v_9200;
v_9201:
    goto v_9197;
v_9198:
    goto v_9199;
v_9200:
    fn = elt(env, 13); // typerr
    v_9214 = (*qfn2(fn))(fn, v_9215, v_9214);
    goto v_9092;
v_9193:
    goto v_9211;
v_9207:
    v_9215 = stack[-1];
    goto v_9208;
v_9209:
    v_9214 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9210;
v_9211:
    goto v_9207;
v_9208:
    goto v_9209;
v_9210:
    {
        fn = elt(env, 15); // mksq
        return (*qfn2(fn))(fn, v_9215, v_9214);
    }
v_9092:
    v_9214 = nil;
    goto v_8926;
    v_9214 = nil;
v_8926:
    return onevalue(v_9214);
}



// Code for xremainder!-mod!-p

static LispObject CC_xremainderKmodKp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_9089, v_9090, v_9091;
    LispObject fn;
    LispObject v_8925, v_8924, v_8923;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "xremainder-mod-p");
    va_start(aa, nargs);
    v_8923 = va_arg(aa, LispObject);
    v_8924 = va_arg(aa, LispObject);
    v_8925 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_8925,v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_8923,v_8924,v_8925);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_8925;
    stack[-1] = v_8924;
    stack[-2] = v_8923;
// end of prologue
v_8922:
    v_9089 = stack[-2];
    if (!consp(v_9089)) goto v_8937;
    else goto v_8938;
v_8937:
    v_9089 = lisp_true;
    goto v_8936;
v_8938:
    v_9089 = stack[-2];
    v_9089 = qcar(v_9089);
    v_9089 = (consp(v_9089) ? nil : lisp_true);
    goto v_8936;
    v_9089 = nil;
v_8936:
    if (v_9089 == nil) goto v_8934;
    v_9089 = lisp_true;
    goto v_8932;
v_8934:
    goto v_8957;
v_8953:
    v_9089 = stack[-2];
    v_9089 = qcar(v_9089);
    v_9089 = qcar(v_9089);
    v_9090 = qcar(v_9089);
    goto v_8954;
v_8955:
    v_9089 = stack[0];
    goto v_8956;
v_8957:
    goto v_8953;
v_8954:
    goto v_8955;
v_8956:
    if (equal(v_9090, v_9089)) goto v_8952;
    v_9089 = lisp_true;
    goto v_8950;
v_8952:
    goto v_8970;
v_8966:
    v_9089 = stack[-2];
    v_9089 = qcar(v_9089);
    v_9089 = qcar(v_9089);
    v_9090 = qcdr(v_9089);
    goto v_8967;
v_8968:
    v_9089 = stack[-1];
    v_9089 = qcar(v_9089);
    v_9089 = qcar(v_9089);
    v_9089 = qcdr(v_9089);
    goto v_8969;
v_8970:
    goto v_8966;
v_8967:
    goto v_8968;
v_8969:
    v_9089 = ((intptr_t)v_9090 < (intptr_t)v_9089) ? lisp_true : nil;
    goto v_8950;
    v_9089 = nil;
v_8950:
    goto v_8932;
    v_9089 = nil;
v_8932:
    if (v_9089 == nil) goto v_8930;
    v_9089 = stack[-2];
    goto v_8928;
v_8930:
    goto v_8992;
v_8988:
    v_9089 = stack[-2];
    v_9089 = qcar(v_9089);
    v_9089 = qcdr(v_9089);
    fn = elt(env, 1); // minus!-mod!-p
    v_9090 = (*qfn1(fn))(fn, v_9089);
    env = stack[-4];
    goto v_8989;
v_8990:
    v_9089 = stack[-1];
    v_9089 = qcar(v_9089);
    v_9089 = qcdr(v_9089);
    goto v_8991;
v_8992:
    goto v_8988;
v_8989:
    goto v_8990;
v_8991:
    fn = elt(env, 2); // quotient!-mod!-p
    v_9089 = (*qfn2(fn))(fn, v_9090, v_9089);
    env = stack[-4];
    stack[-3] = v_9089;
    goto v_9004;
v_9000:
    v_9089 = stack[-2];
    v_9089 = qcar(v_9089);
    v_9089 = qcar(v_9089);
    v_9090 = qcdr(v_9089);
    goto v_9001;
v_9002:
    v_9089 = stack[-1];
    v_9089 = qcar(v_9089);
    v_9089 = qcar(v_9089);
    v_9089 = qcdr(v_9089);
    goto v_9003;
v_9004:
    goto v_9000;
v_9001:
    goto v_9002;
v_9003:
    v_9089 = (LispObject)(intptr_t)((intptr_t)v_9090 - (intptr_t)v_9089 + TAG_FIXNUM);
    v_9091 = v_9089;
    goto v_9022;
v_9018:
    v_9090 = v_9091;
    goto v_9019;
v_9020:
    v_9089 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9021;
v_9022:
    goto v_9018;
v_9019:
    goto v_9020;
v_9021:
    if (v_9090 == v_9089) goto v_9016;
    else goto v_9017;
v_9016:
    goto v_9030;
v_9026:
    v_9089 = stack[-2];
    stack[-2] = qcdr(v_9089);
    goto v_9027;
v_9028:
    goto v_9038;
v_9034:
    v_9089 = stack[-1];
    v_9090 = qcdr(v_9089);
    goto v_9035;
v_9036:
    v_9089 = stack[-3];
    goto v_9037;
v_9038:
    goto v_9034;
v_9035:
    goto v_9036;
v_9037:
    fn = elt(env, 3); // multiply!-by!-constant!-mod!-p
    v_9089 = (*qfn2(fn))(fn, v_9090, v_9089);
    env = stack[-4];
    goto v_9029;
v_9030:
    goto v_9026;
v_9027:
    goto v_9028;
v_9029:
    fn = elt(env, 4); // plus!-mod!-p
    v_9089 = (*qfn2(fn))(fn, stack[-2], v_9089);
    env = stack[-4];
    stack[-2] = v_9089;
    goto v_9015;
v_9017:
    goto v_9049;
v_9045:
    v_9089 = stack[-2];
    stack[-2] = qcdr(v_9089);
    goto v_9046;
v_9047:
    goto v_9057;
v_9053:
    goto v_9063;
v_9059:
    goto v_9069;
v_9065:
    v_9089 = stack[-1];
    v_9089 = qcar(v_9089);
    v_9089 = qcar(v_9089);
    v_9089 = qcar(v_9089);
    goto v_9066;
v_9067:
    v_9090 = v_9091;
    goto v_9068;
v_9069:
    goto v_9065;
v_9066:
    goto v_9067;
v_9068:
    fn = elt(env, 5); // mksp
    v_9090 = (*qfn2(fn))(fn, v_9089, v_9090);
    env = stack[-4];
    goto v_9060;
v_9061:
    v_9089 = stack[-3];
    goto v_9062;
v_9063:
    goto v_9059;
v_9060:
    goto v_9061;
v_9062:
    v_9090 = cons(v_9090, v_9089);
    env = stack[-4];
    goto v_9054;
v_9055:
    v_9089 = stack[-1];
    v_9089 = qcdr(v_9089);
    goto v_9056;
v_9057:
    goto v_9053;
v_9054:
    goto v_9055;
v_9056:
    fn = elt(env, 6); // times!-term!-mod!-p
    v_9089 = (*qfn2(fn))(fn, v_9090, v_9089);
    env = stack[-4];
    goto v_9048;
v_9049:
    goto v_9045;
v_9046:
    goto v_9047;
v_9048:
    fn = elt(env, 4); // plus!-mod!-p
    v_9089 = (*qfn2(fn))(fn, stack[-2], v_9089);
    env = stack[-4];
    stack[-2] = v_9089;
    goto v_9015;
v_9015:
    goto v_9085;
v_9079:
    v_9091 = stack[-2];
    goto v_9080;
v_9081:
    v_9090 = stack[-1];
    goto v_9082;
v_9083:
    v_9089 = stack[0];
    goto v_9084;
v_9085:
    goto v_9079;
v_9080:
    goto v_9081;
v_9082:
    goto v_9083;
v_9084:
    stack[-2] = v_9091;
    stack[-1] = v_9090;
    stack[0] = v_9089;
    goto v_8922;
    goto v_8928;
    v_9089 = nil;
v_8928:
    return onevalue(v_9089);
}



// Code for update_kc_list

static LispObject CC_update_kc_list(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8991, v_8992;
    LispObject fn;
    LispObject v_8925, v_8924, v_8923;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "update_kc_list");
    va_start(aa, nargs);
    v_8923 = va_arg(aa, LispObject);
    v_8924 = va_arg(aa, LispObject);
    v_8925 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_8925,v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_8923,v_8924,v_8925);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_8925;
    stack[-1] = v_8924;
    stack[-2] = v_8923;
// end of prologue
    goto v_8932;
v_8928:
    v_8992 = stack[-1];
    goto v_8929;
v_8930:
    v_8991 = stack[-2];
    v_8991 = qcdr(v_8991);
    goto v_8931;
v_8932:
    goto v_8928;
v_8929:
    goto v_8930;
v_8931:
    fn = elt(env, 1); // list_assoc
    v_8991 = (*qfn2(fn))(fn, v_8992, v_8991);
    env = stack[-4];
    v_8992 = v_8991;
    v_8991 = v_8992;
    if (v_8991 == nil) goto v_8940;
    goto v_8947;
v_8943:
    stack[-3] = v_8992;
    goto v_8944;
v_8945:
    goto v_8954;
v_8950:
    v_8991 = v_8992;
    v_8991 = qcar(v_8991);
    stack[-1] = qcar(v_8991);
    goto v_8951;
v_8952:
    goto v_8963;
v_8959:
    v_8991 = v_8992;
    v_8991 = qcar(v_8991);
    v_8992 = qcdr(v_8991);
    goto v_8960;
v_8961:
    v_8991 = stack[0];
    goto v_8962;
v_8963:
    goto v_8959;
v_8960:
    goto v_8961;
v_8962:
    fn = elt(env, 2); // addf
    v_8991 = (*qfn2(fn))(fn, v_8992, v_8991);
    env = stack[-4];
    goto v_8953;
v_8954:
    goto v_8950;
v_8951:
    goto v_8952;
v_8953:
    v_8991 = cons(stack[-1], v_8991);
    env = stack[-4];
    goto v_8946;
v_8947:
    goto v_8943;
v_8944:
    goto v_8945;
v_8946:
    v_8991 = Lrplaca(nil, stack[-3], v_8991);
    v_8991 = stack[-2];
    goto v_8938;
v_8940:
    goto v_8978;
v_8972:
    v_8991 = stack[-2];
    stack[-3] = qcar(v_8991);
    goto v_8973;
v_8974:
    goto v_8986;
v_8982:
    v_8992 = stack[-1];
    goto v_8983;
v_8984:
    v_8991 = stack[0];
    goto v_8985;
v_8986:
    goto v_8982;
v_8983:
    goto v_8984;
v_8985:
    v_8992 = cons(v_8992, v_8991);
    goto v_8975;
v_8976:
    v_8991 = stack[-2];
    v_8991 = qcdr(v_8991);
    goto v_8977;
v_8978:
    goto v_8972;
v_8973:
    goto v_8974;
v_8975:
    goto v_8976;
v_8977:
    {
        LispObject v_8997 = stack[-3];
        return list2star(v_8997, v_8992, v_8991);
    }
    v_8991 = nil;
v_8938:
    return onevalue(v_8991);
}



// Code for get_action

static LispObject CC_get_action(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_8974, v_8975, v_8976, v_8977, v_8978;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8977 = v_8924;
    v_8974 = v_8923;
// end of prologue
    goto v_8935;
v_8931:
    v_8975 = qvalue(elt(env, 1)); // parser_action_table
    goto v_8932;
v_8933:
    goto v_8934;
v_8935:
    goto v_8931;
v_8932:
    goto v_8933;
v_8934:
    v_8974 = *(LispObject *)((char *)v_8975 + (CELL-TAG_VECTOR) + (((intptr_t)v_8974-TAG_FIXNUM)/(16/CELL)));
    v_8975 = v_8974;
    v_8975 = qcar(v_8975);
    v_8978 = v_8975;
    v_8974 = qcdr(v_8974);
    v_8976 = v_8974;
v_8945:
    v_8974 = v_8978;
    if (v_8974 == nil) goto v_8948;
    else goto v_8949;
v_8948:
    goto v_8944;
v_8949:
    goto v_8960;
v_8956:
    v_8974 = v_8978;
    v_8974 = qcar(v_8974);
    v_8975 = qcar(v_8974);
    goto v_8957;
v_8958:
    v_8974 = v_8977;
    goto v_8959;
v_8960:
    goto v_8956;
v_8957:
    goto v_8958;
v_8959:
    if (equal(v_8975, v_8974)) goto v_8954;
    else goto v_8955;
v_8954:
    v_8974 = v_8978;
    v_8974 = qcar(v_8974);
    v_8974 = qcdr(v_8974);
    v_8976 = v_8974;
    v_8974 = nil;
    v_8978 = v_8974;
    goto v_8953;
v_8955:
    v_8974 = v_8978;
    v_8974 = qcdr(v_8974);
    v_8978 = v_8974;
    goto v_8953;
v_8953:
    goto v_8945;
v_8944:
    v_8974 = v_8976;
    return onevalue(v_8974);
}



// Code for wureducedpolysp

static LispObject CC_wureducedpolysp(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_8959, v_8960;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_8924;
    stack[-1] = v_8923;
// end of prologue
v_8922:
    v_8959 = stack[0];
    if (v_8959 == nil) goto v_8928;
    else goto v_8929;
v_8928:
    v_8959 = lisp_true;
    goto v_8927;
v_8929:
    goto v_8943;
v_8939:
    v_8960 = stack[-1];
    goto v_8940;
v_8941:
    v_8959 = stack[0];
    v_8959 = qcar(v_8959);
    goto v_8942;
v_8943:
    goto v_8939;
v_8940:
    goto v_8941;
v_8942:
    fn = elt(env, 1); // wureducedp
    v_8959 = (*qfn2(fn))(fn, v_8960, v_8959);
    env = stack[-2];
    if (v_8959 == nil) goto v_8936;
    else goto v_8937;
v_8936:
    v_8959 = nil;
    goto v_8935;
v_8937:
    goto v_8955;
v_8951:
    v_8960 = stack[-1];
    goto v_8952;
v_8953:
    v_8959 = stack[0];
    v_8959 = qcdr(v_8959);
    goto v_8954;
v_8955:
    goto v_8951;
v_8952:
    goto v_8953;
v_8954:
    stack[-1] = v_8960;
    stack[0] = v_8959;
    goto v_8922;
    v_8959 = nil;
v_8935:
    goto v_8927;
    v_8959 = nil;
v_8927:
    return onevalue(v_8959);
}



// Code for constsml

static LispObject CC_constsml(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_9007, v_9008;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8923);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_8923;
// end of prologue
    v_9007 = stack[0];
    if (is_number(v_9007)) goto v_8929;
    else goto v_8930;
v_8929:
    v_9007 = elt(env, 1); // "<cn"
    fn = elt(env, 12); // printout
    v_9007 = (*qfn1(fn))(fn, v_9007);
    env = stack[-1];
    v_9007 = stack[0];
    v_9007 = Lfloatp(nil, v_9007);
    env = stack[-1];
    if (v_9007 == nil) goto v_8937;
    v_9007 = elt(env, 2); // " type=""real""> "
    v_9007 = Lprinc(nil, v_9007);
    env = stack[-1];
    goto v_8935;
v_8937:
    v_9007 = stack[0];
    v_9007 = integerp(v_9007);
    if (v_9007 == nil) goto v_8943;
    v_9007 = elt(env, 3); // " type=""integer""> "
    v_9007 = Lprinc(nil, v_9007);
    env = stack[-1];
    goto v_8935;
v_8943:
    v_9007 = elt(env, 4); // "> "
    v_9007 = Lprinc(nil, v_9007);
    env = stack[-1];
    goto v_8935;
v_8935:
    v_9007 = stack[0];
    v_9007 = Lprinc(nil, v_9007);
    env = stack[-1];
    v_9007 = elt(env, 5); // " </cn>"
    v_9007 = Lprinc(nil, v_9007);
    env = stack[-1];
    goto v_8928;
v_8930:
v_8928:
    v_9007 = stack[0];
    if (symbolp(v_9007)) goto v_8958;
    else goto v_8959;
v_8958:
    goto v_8969;
v_8965:
    v_9007 = stack[0];
    v_9008 = Lintern(nil, v_9007);
    env = stack[-1];
    goto v_8966;
v_8967:
    v_9007 = qvalue(elt(env, 6)); // constants!*
    goto v_8968;
v_8969:
    goto v_8965;
v_8966:
    goto v_8967;
v_8968:
    v_9007 = Lmember(nil, v_9008, v_9007);
    if (v_9007 == nil) goto v_8964;
    v_9007 = elt(env, 7); // "<cn type=""constant""> "
    fn = elt(env, 12); // printout
    v_9007 = (*qfn1(fn))(fn, v_9007);
    env = stack[-1];
    v_9007 = stack[0];
    v_9007 = Lprinc(nil, v_9007);
    env = stack[-1];
    v_9007 = elt(env, 5); // " </cn>"
    v_9007 = Lprinc(nil, v_9007);
    goto v_8962;
v_8964:
    v_9007 = elt(env, 8); // "<ci"
    fn = elt(env, 12); // printout
    v_9007 = (*qfn1(fn))(fn, v_9007);
    env = stack[-1];
    v_9007 = stack[0];
    fn = elt(env, 13); // listp
    v_9007 = (*qfn1(fn))(fn, v_9007);
    env = stack[-1];
    if (v_9007 == nil) goto v_8987;
    v_9007 = elt(env, 9); // " type=""list""> "
    v_9007 = Lprinc(nil, v_9007);
    env = stack[-1];
    goto v_8985;
v_8987:
    v_9007 = stack[0];
    v_9007 = Lsimple_vectorp(nil, v_9007);
    env = stack[-1];
    if (v_9007 == nil) goto v_8993;
    v_9007 = elt(env, 10); // " type=""vector""> "
    v_9007 = Lprinc(nil, v_9007);
    env = stack[-1];
    goto v_8985;
v_8993:
    v_9007 = elt(env, 4); // "> "
    v_9007 = Lprinc(nil, v_9007);
    env = stack[-1];
    goto v_8985;
v_8985:
    v_9007 = stack[0];
    v_9007 = Lprinc(nil, v_9007);
    env = stack[-1];
    v_9007 = elt(env, 11); // " </ci>"
    v_9007 = Lprinc(nil, v_9007);
    goto v_8962;
v_8962:
    goto v_8957;
v_8959:
v_8957:
    v_9007 = nil;
    return onevalue(v_9007);
}



// Code for sacar

static LispObject CC_sacar(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_8979, v_8980;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_8924;
    stack[-1] = v_8923;
// end of prologue
    v_8979 = stack[0];
    if (!consp(v_8979)) goto v_8928;
    else goto v_8929;
v_8928:
    v_8979 = nil;
    goto v_8927;
v_8929:
    goto v_8942;
v_8938:
    v_8980 = stack[-1];
    goto v_8939;
v_8940:
    v_8979 = stack[0];
    v_8979 = qcar(v_8979);
    goto v_8941;
v_8942:
    goto v_8938;
v_8939:
    goto v_8940;
v_8941:
    if (v_8980 == v_8979) goto v_8936;
    else goto v_8937;
v_8936:
    v_8979 = stack[0];
    v_8979 = qcdr(v_8979);
    goto v_8935;
v_8937:
    v_8979 = nil;
    goto v_8935;
    v_8979 = nil;
v_8935:
    if (v_8979 == nil) goto v_8933;
    v_8979 = stack[0];
    return ncons(v_8979);
v_8933:
    goto v_8960;
v_8956:
    goto v_8966;
v_8962:
    v_8980 = stack[-1];
    goto v_8963;
v_8964:
    v_8979 = stack[0];
    v_8979 = qcar(v_8979);
    goto v_8965;
v_8966:
    goto v_8962;
v_8963:
    goto v_8964;
v_8965:
    stack[-2] = CC_sacar(elt(env, 0), v_8980, v_8979);
    env = stack[-3];
    goto v_8957;
v_8958:
    goto v_8975;
v_8971:
    v_8980 = stack[-1];
    goto v_8972;
v_8973:
    v_8979 = stack[0];
    v_8979 = qcdr(v_8979);
    goto v_8974;
v_8975:
    goto v_8971;
v_8972:
    goto v_8973;
v_8974:
    v_8979 = CC_sacar(elt(env, 0), v_8980, v_8979);
    goto v_8959;
v_8960:
    goto v_8956;
v_8957:
    goto v_8958;
v_8959:
    {
        LispObject v_8984 = stack[-2];
        return Lappend(nil, v_8984, v_8979);
    }
    v_8979 = nil;
v_8927:
    return onevalue(v_8979);
}



// Code for findnewvars

static LispObject CC_findnewvars(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_8993;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8923);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_8923;
// end of prologue
    v_8993 = stack[0];
    if (!consp(v_8993)) goto v_8927;
    else goto v_8928;
v_8927:
    v_8993 = stack[0];
    fn = elt(env, 1); // genp
    v_8993 = (*qfn1(fn))(fn, v_8993);
    if (v_8993 == nil) goto v_8933;
    v_8993 = stack[0];
    return ncons(v_8993);
v_8933:
    v_8993 = nil;
    goto v_8931;
    v_8993 = nil;
v_8931:
    goto v_8926;
v_8928:
    v_8993 = stack[0];
    stack[-3] = v_8993;
v_8948:
    v_8993 = stack[-3];
    if (v_8993 == nil) goto v_8953;
    else goto v_8954;
v_8953:
    v_8993 = nil;
    goto v_8947;
v_8954:
    v_8993 = stack[-3];
    v_8993 = qcar(v_8993);
    v_8993 = CC_findnewvars(elt(env, 0), v_8993);
    env = stack[-4];
    stack[-2] = v_8993;
    v_8993 = stack[-2];
    fn = elt(env, 2); // lastpair
    v_8993 = (*qfn1(fn))(fn, v_8993);
    env = stack[-4];
    stack[-1] = v_8993;
    v_8993 = stack[-3];
    v_8993 = qcdr(v_8993);
    stack[-3] = v_8993;
    v_8993 = stack[-1];
    if (!consp(v_8993)) goto v_8968;
    else goto v_8969;
v_8968:
    goto v_8948;
v_8969:
v_8949:
    v_8993 = stack[-3];
    if (v_8993 == nil) goto v_8973;
    else goto v_8974;
v_8973:
    v_8993 = stack[-2];
    goto v_8947;
v_8974:
    goto v_8982;
v_8978:
    stack[0] = stack[-1];
    goto v_8979;
v_8980:
    v_8993 = stack[-3];
    v_8993 = qcar(v_8993);
    v_8993 = CC_findnewvars(elt(env, 0), v_8993);
    env = stack[-4];
    goto v_8981;
v_8982:
    goto v_8978;
v_8979:
    goto v_8980;
v_8981:
    v_8993 = Lrplacd(nil, stack[0], v_8993);
    env = stack[-4];
    v_8993 = stack[-1];
    fn = elt(env, 2); // lastpair
    v_8993 = (*qfn1(fn))(fn, v_8993);
    env = stack[-4];
    stack[-1] = v_8993;
    v_8993 = stack[-3];
    v_8993 = qcdr(v_8993);
    stack[-3] = v_8993;
    goto v_8949;
v_8947:
    goto v_8926;
    v_8993 = nil;
v_8926:
    return onevalue(v_8993);
}



// Code for vbcgcd

static LispObject CC_vbcgcd(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_9045, v_9046;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_8924;
    stack[-1] = v_8923;
// end of prologue
    goto v_8942;
v_8938:
    v_9046 = stack[-1];
    goto v_8939;
v_8940:
    v_9045 = (LispObject)-1600+TAG_FIXNUM; // -100
    goto v_8941;
v_8942:
    goto v_8938;
v_8939:
    goto v_8940;
v_8941:
    fn = elt(env, 2); // vbcsize
    v_9045 = (*qfn2(fn))(fn, v_9046, v_9045);
    env = stack[-2];
    if (v_9045 == nil) goto v_8935;
    else goto v_8936;
v_8935:
    v_9045 = lisp_true;
    goto v_8934;
v_8936:
    goto v_8953;
v_8949:
    v_9046 = stack[0];
    goto v_8950;
v_8951:
    v_9045 = (LispObject)-1600+TAG_FIXNUM; // -100
    goto v_8952;
v_8953:
    goto v_8949;
v_8950:
    goto v_8951;
v_8952:
    fn = elt(env, 2); // vbcsize
    v_9045 = (*qfn2(fn))(fn, v_9046, v_9045);
    env = stack[-2];
    v_9045 = (v_9045 == nil ? lisp_true : nil);
    goto v_8934;
    v_9045 = nil;
v_8934:
    if (v_9045 == nil) goto v_8932;
    v_9045 = elt(env, 1); // (1 . 1)
    goto v_8928;
v_8932:
    goto v_8970;
v_8966:
    v_9045 = stack[-1];
    v_9046 = qcdr(v_9045);
    goto v_8967;
v_8968:
    v_9045 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8969;
v_8970:
    goto v_8966;
v_8967:
    goto v_8968;
v_8969:
    if (v_9046 == v_9045) goto v_8964;
    else goto v_8965;
v_8964:
    goto v_8978;
v_8974:
    v_9045 = stack[0];
    v_9046 = qcdr(v_9045);
    goto v_8975;
v_8976:
    v_9045 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8977;
v_8978:
    goto v_8974;
v_8975:
    goto v_8976;
v_8977:
    v_9045 = (v_9046 == v_9045 ? lisp_true : nil);
    goto v_8963;
v_8965:
    v_9045 = nil;
    goto v_8963;
    v_9045 = nil;
v_8963:
    if (v_9045 == nil) goto v_8961;
    v_9045 = stack[-1];
    v_9045 = qcar(v_9045);
    v_9045 = integerp(v_9045);
    if (v_9045 == nil) goto v_8989;
    v_9045 = stack[0];
    v_9045 = qcar(v_9045);
    v_9045 = integerp(v_9045);
    if (v_9045 == nil) goto v_8989;
    goto v_9003;
v_8999:
    goto v_9009;
v_9005:
    v_9045 = stack[-1];
    v_9046 = qcar(v_9045);
    goto v_9006;
v_9007:
    v_9045 = stack[0];
    v_9045 = qcar(v_9045);
    goto v_9008;
v_9009:
    goto v_9005;
v_9006:
    goto v_9007;
v_9008:
    v_9046 = Lgcd(nil, v_9046, v_9045);
    goto v_9000;
v_9001:
    v_9045 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9002;
v_9003:
    goto v_8999;
v_9000:
    goto v_9001;
v_9002:
    return cons(v_9046, v_9045);
v_8989:
    goto v_9022;
v_9018:
    goto v_9028;
v_9024:
    v_9045 = stack[-1];
    v_9046 = qcar(v_9045);
    goto v_9025;
v_9026:
    v_9045 = stack[0];
    v_9045 = qcar(v_9045);
    goto v_9027;
v_9028:
    goto v_9024;
v_9025:
    goto v_9026;
v_9027:
    fn = elt(env, 3); // gcdf!*
    v_9046 = (*qfn2(fn))(fn, v_9046, v_9045);
    goto v_9019;
v_9020:
    v_9045 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9021;
v_9022:
    goto v_9018;
v_9019:
    goto v_9020;
v_9021:
    return cons(v_9046, v_9045);
    v_9045 = nil;
    goto v_8959;
v_8961:
    goto v_9041;
v_9037:
    v_9046 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9038;
v_9039:
    v_9045 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_9040;
v_9041:
    goto v_9037;
v_9038:
    goto v_9039;
v_9040:
    return cons(v_9046, v_9045);
    v_9045 = nil;
v_8959:
v_8928:
    return onevalue(v_9045);
}



// Code for vdpred

static LispObject CC_vdpred(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_9011, v_9012;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8923);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_8923;
// end of prologue
    v_9011 = stack[-3];
    v_9011 = qcdr(v_9011);
    v_9011 = qcdr(v_9011);
    v_9011 = qcdr(v_9011);
    v_9011 = qcar(v_9011);
    v_9011 = qcdr(v_9011);
    v_9011 = qcdr(v_9011);
    stack[-4] = v_9011;
    v_9011 = stack[-4];
    if (v_9011 == nil) goto v_8938;
    else goto v_8939;
v_8938:
    goto v_8950;
v_8942:
    stack[-2] = elt(env, 1); // vdp
    goto v_8943;
v_8944:
    stack[-1] = nil;
    goto v_8945;
v_8946:
    v_9011 = nil;
    stack[0] = ncons(v_9011);
    env = stack[-5];
    goto v_8947;
v_8948:
    goto v_8960;
v_8956:
    v_9012 = nil;
    goto v_8957;
v_8958:
    v_9011 = nil;
    goto v_8959;
v_8960:
    goto v_8956;
v_8957:
    goto v_8958;
v_8959:
    v_9011 = list2(v_9012, v_9011);
    goto v_8949;
v_8950:
    goto v_8942;
v_8943:
    goto v_8944;
v_8945:
    goto v_8946;
v_8947:
    goto v_8948;
v_8949:
    {
        LispObject v_9018 = stack[-2];
        LispObject v_9019 = stack[-1];
        LispObject v_9020 = stack[0];
        return list3star(v_9018, v_9019, v_9020, v_9011);
    }
v_8939:
    goto v_8972;
v_8964:
    stack[-2] = elt(env, 1); // vdp
    goto v_8965;
v_8966:
    v_9011 = stack[-4];
    stack[-1] = qcar(v_9011);
    goto v_8967;
v_8968:
    v_9011 = stack[-4];
    v_9011 = qcdr(v_9011);
    stack[0] = qcar(v_9011);
    goto v_8969;
v_8970:
    goto v_8984;
v_8980:
    v_9012 = stack[-4];
    goto v_8981;
v_8982:
    v_9011 = nil;
    goto v_8983;
v_8984:
    goto v_8980;
v_8981:
    goto v_8982;
v_8983:
    v_9011 = list2(v_9012, v_9011);
    env = stack[-5];
    goto v_8971;
v_8972:
    goto v_8964;
v_8965:
    goto v_8966;
v_8967:
    goto v_8968;
v_8969:
    goto v_8970;
v_8971:
    v_9011 = list3star(stack[-2], stack[-1], stack[0], v_9011);
    env = stack[-5];
    stack[-4] = v_9011;
    v_9011 = qvalue(elt(env, 2)); // !*gsugar
    if (v_9011 == nil) goto v_8990;
    goto v_8999;
v_8995:
    v_9012 = stack[-3];
    goto v_8996;
v_8997:
    v_9011 = elt(env, 3); // sugar
    goto v_8998;
v_8999:
    goto v_8995;
v_8996:
    goto v_8997;
v_8998:
    fn = elt(env, 4); // vdpgetprop
    v_9012 = (*qfn2(fn))(fn, v_9012, v_9011);
    env = stack[-5];
    v_9011 = v_9012;
    if (v_9012 == nil) goto v_8990;
    goto v_9007;
v_9003:
    v_9012 = stack[-4];
    goto v_9004;
v_9005:
    goto v_9006;
v_9007:
    goto v_9003;
v_9004:
    goto v_9005;
v_9006:
    fn = elt(env, 5); // gsetsugar
    v_9011 = (*qfn2(fn))(fn, v_9012, v_9011);
    goto v_8988;
v_8990:
v_8988:
    v_9011 = stack[-4];
    return onevalue(v_9011);
}



// Code for xord_gradlex

static LispObject CC_xord_gradlex(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_8981, v_8982;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_8924;
    stack[-1] = v_8923;
// end of prologue
    goto v_8934;
v_8930:
    v_8981 = stack[-1];
    v_8982 = qcar(v_8981);
    goto v_8931;
v_8932:
    v_8981 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8933;
v_8934:
    goto v_8930;
v_8931:
    goto v_8932;
v_8933:
    if (v_8982 == v_8981) goto v_8928;
    else goto v_8929;
v_8928:
    v_8981 = nil;
    goto v_8927;
v_8929:
    goto v_8945;
v_8941:
    v_8981 = stack[0];
    v_8982 = qcar(v_8981);
    goto v_8942;
v_8943:
    v_8981 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8944;
v_8945:
    goto v_8941;
v_8942:
    goto v_8943;
v_8944:
    if (v_8982 == v_8981) goto v_8939;
    else goto v_8940;
v_8939:
    v_8981 = lisp_true;
    goto v_8927;
v_8940:
    goto v_8956;
v_8952:
    v_8981 = stack[-1];
    stack[-2] = Llength(nil, v_8981);
    env = stack[-3];
    goto v_8953;
v_8954:
    v_8981 = stack[0];
    v_8981 = Llength(nil, v_8981);
    env = stack[-3];
    goto v_8955;
v_8956:
    goto v_8952;
v_8953:
    goto v_8954;
v_8955:
    if (equal(stack[-2], v_8981)) goto v_8950;
    else goto v_8951;
v_8950:
    goto v_8966;
v_8962:
    v_8982 = stack[-1];
    goto v_8963;
v_8964:
    v_8981 = stack[0];
    goto v_8965;
v_8966:
    goto v_8962;
v_8963:
    goto v_8964;
v_8965:
    {
        fn = elt(env, 1); // xord_lex
        return (*qfn2(fn))(fn, v_8982, v_8981);
    }
v_8951:
    goto v_8976;
v_8972:
    v_8981 = stack[-1];
    stack[-1] = Llength(nil, v_8981);
    env = stack[-3];
    goto v_8973;
v_8974:
    v_8981 = stack[0];
    v_8981 = Llength(nil, v_8981);
    goto v_8975;
v_8976:
    goto v_8972;
v_8973:
    goto v_8974;
v_8975:
    {
        LispObject v_8986 = stack[-1];
        return Lgreaterp(nil, v_8986, v_8981);
    }
    v_8981 = nil;
v_8927:
    return onevalue(v_8981);
}



// Code for removeindices

static LispObject CC_removeindices(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_9066, v_9067;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_8924;
    stack[-3] = v_8923;
// end of prologue
    v_9066 = elt(env, 0); // removeindices
    if (!symbolp(v_9066)) v_9066 = nil;
    else { v_9066 = qfastgets(v_9066);
           if (v_9066 != nil) { v_9066 = elt(v_9066, 53); // tracing
#ifdef RECORD_GET
             if (v_9066 == SPID_NOPROP)
                record_get(elt(fastget_names, 53), 0),
                v_9066 = nil;
             else record_get(elt(fastget_names, 53), 1),
                v_9066 = lisp_true; }
           else record_get(elt(fastget_names, 53), 0); }
#else
             if (v_9066 == SPID_NOPROP) v_9066 = nil; else v_9066 = lisp_true; }}
#endif
    if (v_9066 == nil) goto v_8932;
    goto v_8945;
v_8937:
    stack[-4] = elt(env, 0); // removeindices
    goto v_8938;
v_8939:
    stack[-1] = elt(env, 1); // "u= "
    goto v_8940;
v_8941:
    stack[0] = stack[-3];
    goto v_8942;
v_8943:
    goto v_8954;
v_8950:
    v_9067 = elt(env, 2); // " x= "
    goto v_8951;
v_8952:
    v_9066 = stack[-2];
    goto v_8953;
v_8954:
    goto v_8950;
v_8951:
    goto v_8952;
v_8953:
    v_9066 = list2(v_9067, v_9066);
    env = stack[-5];
    goto v_8944;
v_8945:
    goto v_8937;
v_8938:
    goto v_8939;
v_8940:
    goto v_8941;
v_8942:
    goto v_8943;
v_8944:
    v_9066 = list3star(stack[-4], stack[-1], stack[0], v_9066);
    env = stack[-5];
    fn = elt(env, 4); // trwrite
    v_9066 = (*qfn1(fn))(fn, v_9066);
    env = stack[-5];
    goto v_8930;
v_8932:
v_8930:
    v_9066 = stack[-2];
    if (v_9066 == nil) goto v_8963;
    else goto v_8964;
v_8963:
    v_9066 = lisp_true;
    goto v_8962;
v_8964:
    v_9066 = stack[-3];
    v_9066 = Lsymbolp(nil, v_9066);
    env = stack[-5];
    if (v_9066 == nil) goto v_8971;
    else goto v_8970;
v_8971:
    v_9066 = stack[-3];
    fn = elt(env, 5); // !*physopp
    v_9066 = (*qfn1(fn))(fn, v_9066);
    env = stack[-5];
    v_9066 = (v_9066 == nil ? lisp_true : nil);
v_8970:
    goto v_8962;
    v_9066 = nil;
v_8962:
    if (v_9066 == nil) goto v_8960;
    v_9066 = stack[-3];
    goto v_8928;
v_8960:
    v_9066 = stack[-2];
    if (symbolp(v_9066)) goto v_8983;
    else goto v_8982;
v_8983:
    v_9066 = stack[-2];
    fn = elt(env, 6); // isanindex
    v_9066 = (*qfn1(fn))(fn, v_9066);
    env = stack[-5];
    if (v_9066 == nil) goto v_8985;
    else goto v_8982;
v_8985:
    goto v_8980;
v_8982:
    v_9066 = stack[-2];
    fn = elt(env, 7); // idlistp
    v_9066 = (*qfn1(fn))(fn, v_9066);
    env = stack[-5];
    if (v_9066 == nil) goto v_8988;
    v_9066 = stack[-2];
    fn = elt(env, 8); // areallindices
    v_9066 = (*qfn1(fn))(fn, v_9066);
    env = stack[-5];
    if (v_9066 == nil) goto v_8992;
    else goto v_8988;
v_8992:
    goto v_8980;
v_8988:
    goto v_8981;
v_8980:
    goto v_9000;
v_8996:
    v_9067 = elt(env, 0); // removeindices
    goto v_8997;
v_8998:
    v_9066 = elt(env, 3); // "invalid arguments to removeindices"
    goto v_8999;
v_9000:
    goto v_8996;
v_8997:
    goto v_8998;
v_8999:
    fn = elt(env, 9); // rederr2
    v_9066 = (*qfn2(fn))(fn, v_9067, v_9066);
    env = stack[-5];
    goto v_8979;
v_8981:
v_8979:
    v_9066 = stack[-3];
    v_9066 = qcar(v_9066);
    stack[0] = v_9066;
    v_9066 = stack[-3];
    v_9066 = qcdr(v_9066);
    stack[-3] = v_9066;
    v_9066 = stack[-3];
    if (v_9066 == nil) goto v_9009;
    else goto v_9010;
v_9009:
    v_9066 = stack[0];
    goto v_8928;
v_9010:
    v_9066 = stack[-2];
    if (symbolp(v_9066)) goto v_9013;
    else goto v_9014;
v_9013:
    goto v_9021;
v_9017:
    v_9067 = stack[-2];
    goto v_9018;
v_9019:
    v_9066 = stack[-3];
    goto v_9020;
v_9021:
    goto v_9017;
v_9018:
    goto v_9019;
v_9020:
    v_9066 = Ldelete(nil, v_9067, v_9066);
    stack[-3] = v_9066;
    goto v_9008;
v_9014:
    v_9066 = stack[-2];
    stack[-1] = v_9066;
v_9029:
    v_9066 = stack[-1];
    if (v_9066 == nil) goto v_9033;
    else goto v_9034;
v_9033:
    goto v_9028;
v_9034:
    v_9066 = stack[-1];
    v_9066 = qcar(v_9066);
    goto v_9045;
v_9041:
    v_9067 = v_9066;
    goto v_9042;
v_9043:
    v_9066 = stack[-3];
    goto v_9044;
v_9045:
    goto v_9041;
v_9042:
    goto v_9043;
v_9044:
    v_9066 = Ldelete(nil, v_9067, v_9066);
    env = stack[-5];
    stack[-3] = v_9066;
    v_9066 = stack[-1];
    v_9066 = qcdr(v_9066);
    stack[-1] = v_9066;
    goto v_9029;
v_9028:
    goto v_9008;
v_9008:
    v_9066 = stack[-3];
    if (v_9066 == nil) goto v_9052;
    else goto v_9053;
v_9052:
    v_9066 = stack[0];
    goto v_9051;
v_9053:
    goto v_9063;
v_9059:
    v_9067 = stack[0];
    goto v_9060;
v_9061:
    v_9066 = stack[-3];
    goto v_9062;
v_9063:
    goto v_9059;
v_9060:
    goto v_9061;
v_9062:
    return cons(v_9067, v_9066);
    v_9066 = nil;
v_9051:
v_8928:
    return onevalue(v_9066);
}



// Code for simp!-sign

static LispObject CC_simpKsign(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_8929;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8923);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_8929 = v_8923;
// end of prologue
    v_8929 = qcar(v_8929);
    fn = elt(env, 1); // reval
    v_8929 = (*qfn1(fn))(fn, v_8929);
    env = stack[0];
    {
        fn = elt(env, 2); // simp!-sign1
        return (*qfn1(fn))(fn, v_8929);
    }
}



// Code for sqp

static LispObject CC_sqp(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_8947;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8923);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_8923;
// end of prologue
    v_8947 = stack[0];
    v_8947 = Lconsp(nil, v_8947);
    env = stack[-1];
    if (v_8947 == nil) goto v_8927;
    else goto v_8928;
v_8927:
    v_8947 = nil;
    goto v_8926;
v_8928:
    v_8947 = stack[0];
    v_8947 = qcar(v_8947);
    fn = elt(env, 1); // sfpx
    v_8947 = (*qfn1(fn))(fn, v_8947);
    env = stack[-1];
    if (v_8947 == nil) goto v_8936;
    else goto v_8937;
v_8936:
    v_8947 = nil;
    goto v_8935;
v_8937:
    v_8947 = stack[0];
    v_8947 = qcdr(v_8947);
    {
        fn = elt(env, 1); // sfpx
        return (*qfn1(fn))(fn, v_8947);
    }
    v_8947 = nil;
v_8935:
    goto v_8926;
    v_8947 = nil;
v_8926:
    return onevalue(v_8947);
}



// Code for invbf

static LispObject CC_invbf(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_8937, v_8938, v_8939;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8923);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_8937 = v_8923;
// end of prologue
    goto v_8933;
v_8927:
    v_8939 = qvalue(elt(env, 1)); // bfone!*
    goto v_8928;
v_8929:
    v_8938 = v_8937;
    goto v_8930;
v_8931:
    v_8937 = qvalue(elt(env, 2)); // !:bprec!:
    goto v_8932;
v_8933:
    goto v_8927;
v_8928:
    goto v_8929;
v_8930:
    goto v_8931;
v_8932:
    fn = elt(env, 3); // divide!:
    v_8937 = (*qfnn(fn))(fn, 3, v_8939, v_8938, v_8937);
    env = stack[0];
    {
        fn = elt(env, 4); // normbf
        return (*qfn1(fn))(fn, v_8937);
    }
}



// Code for in_list1

static LispObject CC_in_list1(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_8937, v_8938, v_8939;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8937 = v_8924;
    v_8938 = v_8923;
// end of prologue
    goto v_8933;
v_8927:
    v_8939 = v_8938;
    goto v_8928;
v_8929:
    v_8938 = v_8937;
    goto v_8930;
v_8931:
    v_8937 = nil;
    goto v_8932;
v_8933:
    goto v_8927;
v_8928:
    goto v_8929;
v_8930:
    goto v_8931;
v_8932:
    {
        fn = elt(env, 1); // in_list1a
        return (*qfnn(fn))(fn, 3, v_8939, v_8938, v_8937);
    }
}



// Code for mkkl

static LispObject CC_mkkl(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_8951, v_8952, v_8953;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_8951 = v_8924;
    v_8952 = v_8923;
// end of prologue
v_8929:
    v_8953 = v_8952;
    if (v_8953 == nil) goto v_8932;
    else goto v_8933;
v_8932:
    goto v_8928;
v_8933:
    v_8953 = v_8952;
    v_8953 = qcdr(v_8953);
    stack[0] = v_8953;
    goto v_8946;
v_8942:
    v_8952 = qcar(v_8952);
    goto v_8943;
v_8944:
    goto v_8945;
v_8946:
    goto v_8942;
v_8943:
    goto v_8944;
v_8945:
    v_8951 = cons(v_8952, v_8951);
    env = stack[-1];
    v_8951 = ncons(v_8951);
    env = stack[-1];
    v_8952 = stack[0];
    goto v_8929;
    v_8951 = nil;
v_8928:
    return onevalue(v_8951);
}



// Code for findremainder

static LispObject CC_findremainder(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_8958, v_8959, v_8960;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_8958 = v_8924;
    v_8959 = v_8923;
// end of prologue
    stack[0] = v_8958;
v_8929:
    v_8958 = stack[0];
    if (v_8958 == nil) goto v_8933;
    else goto v_8934;
v_8933:
    goto v_8928;
v_8934:
    v_8958 = stack[0];
    v_8958 = qcar(v_8958);
    goto v_8947;
v_8941:
    v_8960 = v_8959;
    goto v_8942;
v_8943:
    v_8959 = v_8958;
    goto v_8944;
v_8945:
    v_8958 = qcar(v_8958);
    v_8958 = qcar(v_8958);
    v_8958 = qcar(v_8958);
    goto v_8946;
v_8947:
    goto v_8941;
v_8942:
    goto v_8943;
v_8944:
    goto v_8945;
v_8946:
    fn = elt(env, 1); // wupseudodivide
    v_8958 = (*qfnn(fn))(fn, 3, v_8960, v_8959, v_8958);
    env = stack[-1];
    v_8958 = qcdr(v_8958);
    v_8959 = v_8958;
    v_8958 = stack[0];
    v_8958 = qcdr(v_8958);
    stack[0] = v_8958;
    goto v_8929;
v_8928:
    v_8958 = v_8959;
    return onevalue(v_8958);
}



// Code for talp_eqtp

static LispObject CC_talp_eqtp(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_9015, v_9016;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_8924;
    stack[-1] = v_8923;
// end of prologue
v_8928:
    v_9015 = stack[-1];
    if (!consp(v_9015)) goto v_8935;
    else goto v_8936;
v_8935:
    v_9015 = lisp_true;
    goto v_8934;
v_8936:
    v_9015 = stack[0];
    v_9015 = (consp(v_9015) ? nil : lisp_true);
    goto v_8934;
    v_9015 = nil;
v_8934:
    if (v_9015 == nil) goto v_8932;
    goto v_8951;
v_8947:
    v_9016 = stack[-1];
    goto v_8948;
v_8949:
    v_9015 = stack[0];
    goto v_8950;
v_8951:
    goto v_8947;
v_8948:
    goto v_8949;
v_8950:
    if (v_9016 == v_9015) goto v_8945;
    else goto v_8946;
v_8945:
    v_9015 = lisp_true;
    goto v_8927;
v_8946:
    v_9015 = nil;
    goto v_8927;
    goto v_8930;
v_8932:
    v_9015 = stack[-1];
    v_9015 = qcar(v_9015);
    if (!consp(v_9015)) goto v_8962;
    else goto v_8963;
v_8962:
    v_9015 = stack[0];
    v_9015 = qcar(v_9015);
    v_9015 = (consp(v_9015) ? nil : lisp_true);
    goto v_8961;
v_8963:
    v_9015 = nil;
    goto v_8961;
    v_9015 = nil;
v_8961:
    if (v_9015 == nil) goto v_8959;
    goto v_8980;
v_8976:
    v_9015 = stack[-1];
    v_9016 = qcar(v_9015);
    goto v_8977;
v_8978:
    v_9015 = stack[0];
    v_9015 = qcar(v_9015);
    goto v_8979;
v_8980:
    goto v_8976;
v_8977:
    goto v_8978;
v_8979:
    if (v_9016 == v_9015) goto v_8974;
    else goto v_8975;
v_8974:
    v_9015 = stack[-1];
    v_9015 = qcdr(v_9015);
    stack[-1] = v_9015;
    v_9015 = stack[0];
    v_9015 = qcdr(v_9015);
    stack[0] = v_9015;
    goto v_8928;
v_8975:
    v_9015 = nil;
    goto v_8927;
    goto v_8930;
v_8959:
    goto v_9003;
v_8999:
    v_9015 = stack[-1];
    v_9016 = qcar(v_9015);
    goto v_9000;
v_9001:
    v_9015 = stack[0];
    v_9015 = qcar(v_9015);
    goto v_9002;
v_9003:
    goto v_8999;
v_9000:
    goto v_9001;
v_9002:
    v_9015 = CC_talp_eqtp(elt(env, 0), v_9016, v_9015);
    env = stack[-2];
    if (v_9015 == nil) goto v_8997;
    v_9015 = stack[-1];
    v_9015 = qcdr(v_9015);
    stack[-1] = v_9015;
    v_9015 = stack[0];
    v_9015 = qcdr(v_9015);
    stack[0] = v_9015;
    goto v_8928;
v_8997:
    v_9015 = nil;
    goto v_8927;
    goto v_8930;
v_8930:
    v_9015 = nil;
v_8927:
    return onevalue(v_9015);
}



// Code for qqe_simplat1

static LispObject CC_qqe_simplat1(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_8976, v_8977, v_8978;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_8924;
    stack[-1] = v_8923;
// end of prologue
    v_8976 = stack[-1];
    fn = elt(env, 3); // qqe_op
    v_8976 = (*qfn1(fn))(fn, v_8976);
    env = stack[-2];
    v_8978 = v_8976;
    goto v_8937;
v_8933:
    v_8977 = v_8978;
    goto v_8934;
v_8935:
    v_8976 = elt(env, 1); // (qequal qneq)
    goto v_8936;
v_8937:
    goto v_8933;
v_8934:
    goto v_8935;
v_8936:
    v_8976 = Lmemq(nil, v_8977, v_8976);
    if (v_8976 == nil) goto v_8931;
    else goto v_8932;
v_8931:
    goto v_8946;
v_8942:
    v_8977 = stack[-1];
    goto v_8943;
v_8944:
    v_8976 = stack[0];
    goto v_8945;
v_8946:
    goto v_8942;
v_8943:
    goto v_8944;
v_8945:
    {
        fn = elt(env, 4); // qqe_simplbtat
        return (*qfn2(fn))(fn, v_8977, v_8976);
    }
v_8932:
    goto v_8955;
v_8951:
    v_8977 = v_8978;
    goto v_8952;
v_8953:
    v_8976 = elt(env, 2); // qequal
    goto v_8954;
v_8955:
    goto v_8951;
v_8952:
    goto v_8953;
v_8954:
    if (v_8977 == v_8976) goto v_8949;
    else goto v_8950;
v_8949:
    goto v_8963;
v_8959:
    v_8977 = stack[-1];
    goto v_8960;
v_8961:
    v_8976 = stack[0];
    goto v_8962;
v_8963:
    goto v_8959;
v_8960:
    goto v_8961;
v_8962:
    {
        fn = elt(env, 5); // qqe_simplqequal
        return (*qfn2(fn))(fn, v_8977, v_8976);
    }
v_8950:
    goto v_8973;
v_8969:
    v_8977 = stack[-1];
    goto v_8970;
v_8971:
    v_8976 = stack[0];
    goto v_8972;
v_8973:
    goto v_8969;
v_8970:
    goto v_8971;
v_8972:
    {
        fn = elt(env, 6); // qqe_simplqneq
        return (*qfn2(fn))(fn, v_8977, v_8976);
    }
    v_8976 = nil;
    return onevalue(v_8976);
}



// Code for cgp_number

static LispObject CC_cgp_number(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_8933, v_8934;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8933 = v_8923;
// end of prologue
    goto v_8930;
v_8926:
    v_8934 = v_8933;
    goto v_8927;
v_8928:
    v_8933 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_8929;
v_8930:
    goto v_8926;
v_8927:
    goto v_8928;
v_8929:
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(fn, v_8934, v_8933);
    }
}



// Code for nary

static LispObject CC_nary(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_8990, v_8991;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_8924;
    stack[-1] = v_8923;
// end of prologue
    goto v_8940;
v_8936:
    v_8990 = stack[-1];
    v_8991 = qcar(v_8990);
    goto v_8937;
v_8938:
    v_8990 = elt(env, 1); // e
    goto v_8939;
v_8940:
    goto v_8936;
v_8937:
    goto v_8938;
v_8939:
    if (v_8991 == v_8990) goto v_8934;
    else goto v_8935;
v_8934:
    goto v_8948;
v_8944:
    v_8991 = stack[0];
    goto v_8945;
v_8946:
    v_8990 = elt(env, 2); // power
    goto v_8947;
v_8948:
    goto v_8944;
v_8945:
    goto v_8946;
v_8947:
    v_8990 = (v_8991 == v_8990 ? lisp_true : nil);
    goto v_8933;
v_8935:
    v_8990 = nil;
    goto v_8933;
    v_8990 = nil;
v_8933:
    if (v_8990 == nil) goto v_8931;
    goto v_8960;
v_8956:
    v_8990 = stack[-1];
    v_8991 = qcdr(v_8990);
    goto v_8957;
v_8958:
    v_8990 = elt(env, 3); // exp
    goto v_8959;
v_8960:
    goto v_8956;
v_8957:
    goto v_8958;
v_8959:
    fn = elt(env, 8); // unary
    v_8990 = (*qfn2(fn))(fn, v_8991, v_8990);
    goto v_8929;
v_8931:
    v_8990 = elt(env, 4); // "<apply>"
    fn = elt(env, 9); // printout
    v_8990 = (*qfn1(fn))(fn, v_8990);
    env = stack[-2];
    v_8990 = elt(env, 5); // "<"
    v_8990 = Lprinc(nil, v_8990);
    env = stack[-2];
    v_8990 = stack[0];
    v_8990 = Lprinc(nil, v_8990);
    env = stack[-2];
    goto v_8977;
v_8973:
    v_8990 = stack[-1];
    v_8991 = qcar(v_8990);
    goto v_8974;
v_8975:
    v_8990 = elt(env, 6); // "/"
    goto v_8976;
v_8977:
    goto v_8973;
v_8974:
    goto v_8975;
v_8976:
    fn = elt(env, 10); // attributesml
    v_8990 = (*qfn2(fn))(fn, v_8991, v_8990);
    env = stack[-2];
    v_8990 = lisp_true;
    fn = elt(env, 11); // indent!*
    v_8990 = (*qfn1(fn))(fn, v_8990);
    env = stack[-2];
    v_8990 = stack[-1];
    v_8990 = qcdr(v_8990);
    fn = elt(env, 12); // multi_elem
    v_8990 = (*qfn1(fn))(fn, v_8990);
    env = stack[-2];
    v_8990 = nil;
    fn = elt(env, 11); // indent!*
    v_8990 = (*qfn1(fn))(fn, v_8990);
    env = stack[-2];
    v_8990 = elt(env, 7); // "</apply>"
    fn = elt(env, 9); // printout
    v_8990 = (*qfn1(fn))(fn, v_8990);
    goto v_8929;
v_8929:
    v_8990 = nil;
    return onevalue(v_8990);
}



// Code for spband_matrix

static LispObject CC_spband_matrix(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_9201, v_9202, v_9203;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-7] = v_8924;
    stack[-8] = v_8923;
// end of prologue
    goto v_8944;
v_8940:
    stack[0] = stack[-7];
    goto v_8941;
v_8942:
    goto v_8953;
v_8947:
    v_9203 = elt(env, 1); // spm
    goto v_8948;
v_8949:
    v_9202 = stack[-7];
    goto v_8950;
v_8951:
    v_9201 = stack[-7];
    goto v_8952;
v_8953:
    goto v_8947;
v_8948:
    goto v_8949;
v_8950:
    goto v_8951;
v_8952:
    v_9201 = list3(v_9203, v_9202, v_9201);
    env = stack[-10];
    goto v_8943;
v_8944:
    goto v_8940;
v_8941:
    goto v_8942;
v_8943:
    fn = elt(env, 8); // mkempspmat
    v_9201 = (*qfn2(fn))(fn, stack[0], v_9201);
    env = stack[-10];
    stack[-9] = v_9201;
    v_9201 = stack[-7];
    v_9201 = integerp(v_9201);
    if (v_9201 == nil) goto v_8959;
    else goto v_8960;
v_8959:
    v_9201 = elt(env, 2); // "Error in spband_matrix(second argument): should be an integer."
    fn = elt(env, 9); // rederr
    v_9201 = (*qfn1(fn))(fn, v_9201);
    env = stack[-10];
    goto v_8958;
v_8960:
v_8958:
    v_9201 = stack[-8];
    if (!consp(v_9201)) goto v_8967;
    else goto v_8968;
v_8967:
    v_9201 = stack[-8];
    v_9201 = ncons(v_9201);
    env = stack[-10];
    stack[-8] = v_9201;
    goto v_8966;
v_8968:
    goto v_8978;
v_8974:
    v_9201 = stack[-8];
    v_9202 = qcar(v_9201);
    goto v_8975;
v_8976:
    v_9201 = elt(env, 3); // list
    goto v_8977;
v_8978:
    goto v_8974;
v_8975:
    goto v_8976;
v_8977:
    if (v_9202 == v_9201) goto v_8972;
    else goto v_8973;
v_8972:
    v_9201 = stack[-8];
    v_9201 = qcdr(v_9201);
    stack[-8] = v_9201;
    goto v_8966;
v_8973:
    v_9201 = elt(env, 4); // "Error in spband_matrix(first argument): should be single value or list."
    fn = elt(env, 9); // rederr
    v_9201 = (*qfn1(fn))(fn, v_9201);
    env = stack[-10];
    goto v_8966;
v_8966:
    v_9201 = stack[-8];
    v_9201 = Llength(nil, v_9201);
    env = stack[-10];
    stack[-4] = v_9201;
    v_9201 = stack[-4];
    v_9201 = Levenp(nil, v_9201);
    env = stack[-10];
    if (v_9201 == nil) goto v_8993;
    v_9201 = elt(env, 5); // "Error in spband matrix(first argument): number of elements must be odd."
    fn = elt(env, 9); // rederr
    v_9201 = (*qfn1(fn))(fn, v_9201);
    env = stack[-10];
    goto v_8991;
v_8993:
v_8991:
    goto v_9006;
v_9000:
    stack[0] = elt(env, 6); // quotient
    goto v_9001;
v_9002:
    v_9201 = stack[-4];
    v_9202 = add1(v_9201);
    env = stack[-10];
    goto v_9003;
v_9004:
    v_9201 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_9005;
v_9006:
    goto v_9000;
v_9001:
    goto v_9002;
v_9003:
    goto v_9004;
v_9005:
    v_9201 = list3(stack[0], v_9202, v_9201);
    env = stack[-10];
    fn = elt(env, 10); // reval
    v_9201 = (*qfn1(fn))(fn, v_9201);
    env = stack[-10];
    stack[-3] = v_9201;
    goto v_9020;
v_9016:
    v_9201 = stack[-3];
    v_9201 = integerp(v_9201);
    if (v_9201 == nil) goto v_9024;
    v_9201 = stack[-3];
    v_9202 = v_9201;
    goto v_9022;
v_9024:
    v_9201 = stack[-3];
    fn = elt(env, 10); // reval
    v_9201 = (*qfn1(fn))(fn, v_9201);
    env = stack[-10];
    v_9202 = v_9201;
    goto v_9022;
    v_9202 = nil;
v_9022:
    goto v_9017;
v_9018:
    v_9201 = stack[-7];
    goto v_9019;
v_9020:
    goto v_9016;
v_9017:
    goto v_9018;
v_9019:
    v_9201 = (LispObject)greaterp2(v_9202, v_9201);
    v_9201 = v_9201 ? lisp_true : nil;
    env = stack[-10];
    if (v_9201 == nil) goto v_9014;
    v_9201 = elt(env, 7); // "Error in spband_matrix: too many elements. Band matrix is overflowing."
    fn = elt(env, 9); // rederr
    v_9201 = (*qfn1(fn))(fn, v_9201);
    env = stack[-10];
    goto v_9012;
v_9014:
v_9012:
    v_9201 = (LispObject)32+TAG_FIXNUM; // 2
    stack[-5] = v_9201;
    v_9201 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_9201;
v_9039:
    goto v_9051;
v_9047:
    v_9202 = stack[-7];
    goto v_9048;
v_9049:
    v_9201 = stack[-2];
    goto v_9050;
v_9051:
    goto v_9047;
v_9048:
    goto v_9049;
v_9050:
    v_9201 = difference2(v_9202, v_9201);
    env = stack[-10];
    v_9201 = Lminusp(nil, v_9201);
    env = stack[-10];
    if (v_9201 == nil) goto v_9044;
    goto v_9038;
v_9044:
    goto v_9064;
v_9060:
    v_9202 = stack[-2];
    goto v_9061;
v_9062:
    v_9201 = stack[-3];
    goto v_9063;
v_9064:
    goto v_9060;
v_9061:
    goto v_9062;
v_9063:
    v_9201 = (LispObject)lesseq2(v_9202, v_9201);
    v_9201 = v_9201 ? lisp_true : nil;
    env = stack[-10];
    if (v_9201 == nil) goto v_9058;
    v_9201 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_9201;
    goto v_9056;
v_9058:
    v_9201 = stack[-5];
    stack[-6] = v_9201;
    goto v_9056;
v_9056:
v_9073:
    goto v_9084;
v_9080:
    goto v_9090;
v_9086:
    goto v_9096;
v_9092:
    v_9202 = stack[-3];
    goto v_9093;
v_9094:
    v_9201 = stack[-2];
    goto v_9095;
v_9096:
    goto v_9092;
v_9093:
    goto v_9094;
v_9095:
    v_9202 = difference2(v_9202, v_9201);
    env = stack[-10];
    goto v_9087;
v_9088:
    v_9201 = stack[-6];
    goto v_9089;
v_9090:
    goto v_9086;
v_9087:
    goto v_9088;
v_9089:
    v_9202 = plus2(v_9202, v_9201);
    env = stack[-10];
    goto v_9081;
v_9082:
    v_9201 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_9083;
v_9084:
    goto v_9080;
v_9081:
    goto v_9082;
v_9083:
    v_9201 = (LispObject)greaterp2(v_9202, v_9201);
    v_9201 = v_9201 ? lisp_true : nil;
    env = stack[-10];
    if (v_9201 == nil) goto v_9076;
    goto v_9108;
v_9104:
    v_9202 = stack[-6];
    goto v_9105;
v_9106:
    v_9201 = stack[-7];
    goto v_9107;
v_9108:
    goto v_9104;
v_9105:
    goto v_9106;
v_9107:
    v_9201 = (LispObject)lesseq2(v_9202, v_9201);
    v_9201 = v_9201 ? lisp_true : nil;
    env = stack[-10];
    if (v_9201 == nil) goto v_9076;
    goto v_9117;
v_9113:
    goto v_9123;
v_9119:
    goto v_9129;
v_9125:
    v_9202 = stack[-3];
    goto v_9126;
v_9127:
    v_9201 = stack[-2];
    goto v_9128;
v_9129:
    goto v_9125;
v_9126:
    goto v_9127;
v_9128:
    v_9202 = difference2(v_9202, v_9201);
    env = stack[-10];
    goto v_9120;
v_9121:
    v_9201 = stack[-6];
    goto v_9122;
v_9123:
    goto v_9119;
v_9120:
    goto v_9121;
v_9122:
    v_9202 = plus2(v_9202, v_9201);
    env = stack[-10];
    goto v_9114;
v_9115:
    v_9201 = stack[-4];
    goto v_9116;
v_9117:
    goto v_9113;
v_9114:
    goto v_9115;
v_9116:
    v_9201 = (LispObject)lesseq2(v_9202, v_9201);
    v_9201 = v_9201 ? lisp_true : nil;
    env = stack[-10];
    if (v_9201 == nil) goto v_9076;
    goto v_9077;
v_9076:
    goto v_9072;
v_9077:
    goto v_9144;
v_9136:
    goto v_9152;
v_9146:
    v_9203 = stack[-9];
    goto v_9147;
v_9148:
    v_9202 = stack[-2];
    goto v_9149;
v_9150:
    v_9201 = stack[-6];
    goto v_9151;
v_9152:
    goto v_9146;
v_9147:
    goto v_9148;
v_9149:
    goto v_9150;
v_9151:
    stack[-1] = list3(v_9203, v_9202, v_9201);
    env = stack[-10];
    goto v_9137;
v_9138:
    goto v_9161;
v_9157:
    stack[0] = stack[-8];
    goto v_9158;
v_9159:
    goto v_9168;
v_9164:
    goto v_9174;
v_9170:
    v_9202 = stack[-3];
    goto v_9171;
v_9172:
    v_9201 = stack[-2];
    goto v_9173;
v_9174:
    goto v_9170;
v_9171:
    goto v_9172;
v_9173:
    v_9202 = difference2(v_9202, v_9201);
    env = stack[-10];
    goto v_9165;
v_9166:
    v_9201 = stack[-6];
    goto v_9167;
v_9168:
    goto v_9164;
v_9165:
    goto v_9166;
v_9167:
    v_9201 = plus2(v_9202, v_9201);
    env = stack[-10];
    goto v_9160;
v_9161:
    goto v_9157;
v_9158:
    goto v_9159;
v_9160:
    fn = elt(env, 11); // nth
    v_9203 = (*qfn2(fn))(fn, stack[0], v_9201);
    env = stack[-10];
    goto v_9139;
v_9140:
    v_9202 = stack[-9];
    goto v_9141;
v_9142:
    v_9201 = nil;
    goto v_9143;
v_9144:
    goto v_9136;
v_9137:
    goto v_9138;
v_9139:
    goto v_9140;
v_9141:
    goto v_9142;
v_9143:
    fn = elt(env, 12); // letmtr3
    v_9201 = (*qfnn(fn))(fn, 4, stack[-1], v_9203, v_9202, v_9201);
    env = stack[-10];
    v_9201 = stack[-6];
    v_9201 = add1(v_9201);
    env = stack[-10];
    stack[-6] = v_9201;
    goto v_9073;
v_9072:
    goto v_9192;
v_9188:
    v_9202 = stack[-2];
    goto v_9189;
v_9190:
    v_9201 = stack[-3];
    goto v_9191;
v_9192:
    goto v_9188;
v_9189:
    goto v_9190;
v_9191:
    v_9201 = (LispObject)greaterp2(v_9202, v_9201);
    v_9201 = v_9201 ? lisp_true : nil;
    env = stack[-10];
    if (v_9201 == nil) goto v_9186;
    v_9201 = stack[-5];
    v_9201 = add1(v_9201);
    env = stack[-10];
    stack[-5] = v_9201;
    goto v_9184;
v_9186:
v_9184:
    v_9201 = stack[-2];
    v_9201 = add1(v_9201);
    env = stack[-10];
    stack[-2] = v_9201;
    goto v_9039;
v_9038:
    v_9201 = stack[-9];
    return onevalue(v_9201);
}



// Code for inshisto

static LispObject CC_inshisto(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_9087, v_9088, v_9089;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8923);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_8923;
// end of prologue
    goto v_8934;
v_8930:
    goto v_8939;
v_8935:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_8936;
v_8937:
    goto v_8946;
v_8942:
    v_9088 = qvalue(elt(env, 2)); // maxvar
    goto v_8943;
v_8944:
    v_9087 = stack[-3];
    goto v_8945;
v_8946:
    goto v_8942;
v_8943:
    goto v_8944;
v_8945:
    v_9087 = plus2(v_9088, v_9087);
    env = stack[-5];
    goto v_8938;
v_8939:
    goto v_8935;
v_8936:
    goto v_8937;
v_8938:
    v_9088 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_9087-TAG_FIXNUM)/(16/CELL)));
    goto v_8931;
v_8932:
    v_9087 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8933;
v_8934:
    goto v_8930;
v_8931:
    goto v_8932;
v_8933:
    v_9087 = *(LispObject *)((char *)v_9088 + (CELL-TAG_VECTOR) + (((intptr_t)v_9087-TAG_FIXNUM)/(16/CELL)));
    if (v_9087 == nil) goto v_8928;
    goto v_8958;
v_8954:
    v_9088 = stack[-3];
    goto v_8955;
v_8956:
    v_9087 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8957;
v_8958:
    goto v_8954;
v_8955:
    goto v_8956;
v_8957:
    v_9087 = (LispObject)geq2(v_9088, v_9087);
    v_9087 = v_9087 ? lisp_true : nil;
    env = stack[-5];
    if (v_9087 == nil) goto v_8928;
    goto v_8973;
v_8969:
    stack[0] = qvalue(elt(env, 3)); // codhisto
    goto v_8970;
v_8971:
    goto v_8980;
v_8976:
    goto v_8985;
v_8981:
    goto v_8990;
v_8986:
    stack[-1] = qvalue(elt(env, 1)); // codmat
    goto v_8987;
v_8988:
    goto v_8997;
v_8993:
    v_9088 = qvalue(elt(env, 2)); // maxvar
    goto v_8994;
v_8995:
    v_9087 = stack[-3];
    goto v_8996;
v_8997:
    goto v_8993;
v_8994:
    goto v_8995;
v_8996:
    v_9087 = plus2(v_9088, v_9087);
    env = stack[-5];
    goto v_8989;
v_8990:
    goto v_8986;
v_8987:
    goto v_8988;
v_8989:
    v_9088 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_9087-TAG_FIXNUM)/(16/CELL)));
    goto v_8982;
v_8983:
    v_9087 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8984;
v_8985:
    goto v_8981;
v_8982:
    goto v_8983;
v_8984:
    v_9087 = *(LispObject *)((char *)v_9088 + (CELL-TAG_VECTOR) + (((intptr_t)v_9087-TAG_FIXNUM)/(16/CELL)));
    v_9088 = qcdr(v_9087);
    goto v_8977;
v_8978:
    v_9087 = (LispObject)3200+TAG_FIXNUM; // 200
    goto v_8979;
v_8980:
    goto v_8976;
v_8977:
    goto v_8978;
v_8979:
    fn = elt(env, 5); // min
    v_9087 = (*qfn2(fn))(fn, v_9088, v_9087);
    env = stack[-5];
    stack[-2] = v_9087;
    goto v_8972;
v_8973:
    goto v_8969;
v_8970:
    goto v_8971;
v_8972:
    v_9087 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_9087-TAG_FIXNUM)/(16/CELL)));
    stack[-4] = v_9087;
    if (v_9087 == nil) goto v_8968;
    goto v_9011;
v_9007:
    goto v_9016;
v_9012:
    goto v_9021;
v_9017:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_9018;
v_9019:
    goto v_9028;
v_9024:
    v_9088 = qvalue(elt(env, 2)); // maxvar
    goto v_9025;
v_9026:
    v_9087 = stack[-4];
    goto v_9027;
v_9028:
    goto v_9024;
v_9025:
    goto v_9026;
v_9027:
    v_9087 = plus2(v_9088, v_9087);
    env = stack[-5];
    goto v_9020;
v_9021:
    goto v_9017;
v_9018:
    goto v_9019;
v_9020:
    v_9088 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_9087-TAG_FIXNUM)/(16/CELL)));
    goto v_9013;
v_9014:
    v_9087 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_9015;
v_9016:
    goto v_9012;
v_9013:
    goto v_9014;
v_9015:
    v_9088 = *(LispObject *)((char *)v_9088 + (CELL-TAG_VECTOR) + (((intptr_t)v_9087-TAG_FIXNUM)/(16/CELL)));
    goto v_9008;
v_9009:
    v_9087 = stack[-3];
    goto v_9010;
v_9011:
    goto v_9007;
v_9008:
    goto v_9009;
v_9010:
    v_9087 = Lrplaca(nil, v_9088, v_9087);
    env = stack[-5];
    goto v_8966;
v_8968:
    goto v_9042;
v_9038:
    v_9088 = stack[-2];
    goto v_9039;
v_9040:
    v_9087 = qvalue(elt(env, 4)); // headhisto
    goto v_9041;
v_9042:
    goto v_9038;
v_9039:
    goto v_9040;
v_9041:
    v_9087 = (LispObject)greaterp2(v_9088, v_9087);
    v_9087 = v_9087 ? lisp_true : nil;
    env = stack[-5];
    if (v_9087 == nil) goto v_9036;
    v_9087 = stack[-2];
    qvalue(elt(env, 4)) = v_9087; // headhisto
    goto v_8966;
v_9036:
v_8966:
    goto v_9052;
v_9046:
    goto v_9057;
v_9053:
    stack[0] = qvalue(elt(env, 1)); // codmat
    goto v_9054;
v_9055:
    goto v_9064;
v_9060:
    v_9088 = qvalue(elt(env, 2)); // maxvar
    goto v_9061;
v_9062:
    v_9087 = stack[-3];
    goto v_9063;
v_9064:
    goto v_9060;
v_9061:
    goto v_9062;
v_9063:
    v_9087 = plus2(v_9088, v_9087);
    env = stack[-5];
    goto v_9056;
v_9057:
    goto v_9053;
v_9054:
    goto v_9055;
v_9056:
    stack[-1] = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_9087-TAG_FIXNUM)/(16/CELL)));
    goto v_9047;
v_9048:
    stack[0] = (LispObject)112+TAG_FIXNUM; // 7
    goto v_9049;
v_9050:
    goto v_9074;
v_9070:
    v_9088 = nil;
    goto v_9071;
v_9072:
    v_9087 = stack[-4];
    goto v_9073;
v_9074:
    goto v_9070;
v_9071:
    goto v_9072;
v_9073:
    v_9087 = cons(v_9088, v_9087);
    env = stack[-5];
    goto v_9051;
v_9052:
    goto v_9046;
v_9047:
    goto v_9048;
v_9049:
    goto v_9050;
v_9051:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_9087;
    goto v_9083;
v_9077:
    v_9089 = qvalue(elt(env, 3)); // codhisto
    goto v_9078;
v_9079:
    v_9088 = stack[-2];
    goto v_9080;
v_9081:
    v_9087 = stack[-3];
    goto v_9082;
v_9083:
    goto v_9077;
v_9078:
    goto v_9079;
v_9080:
    goto v_9081;
v_9082:
    *(LispObject *)((char *)v_9089 + (CELL-TAG_VECTOR) + (((intptr_t)v_9088-TAG_FIXNUM)/(16/CELL))) = v_9087;
    v_9087 = nil;
    goto v_8926;
v_8928:
    v_9087 = nil;
v_8926:
    return onevalue(v_9087);
}



// Code for bcquot

static LispObject CC_bcquot(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_8985, v_8986, v_8987;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_8924;
    stack[-1] = v_8923;
// end of prologue
    v_8985 = qvalue(elt(env, 1)); // !*grmod!*
    if (v_8985 == nil) goto v_8929;
    goto v_8937;
v_8933:
    goto v_8934;
v_8935:
    v_8985 = stack[0];
    v_8985 = Lmodular_reciprocal(nil, v_8985);
    env = stack[-2];
    goto v_8936;
v_8937:
    goto v_8933;
v_8934:
    goto v_8935;
v_8936:
    v_8985 = times2(stack[-1], v_8985);
    env = stack[-2];
    {
        fn = elt(env, 4); // bcfi
        return (*qfn1(fn))(fn, v_8985);
    }
v_8929:
    v_8985 = qvalue(elt(env, 2)); // !*vdpinteger
    if (v_8985 == nil) goto v_8942;
    goto v_8954;
v_8948:
    v_8987 = stack[-1];
    goto v_8949;
v_8950:
    v_8986 = stack[0];
    goto v_8951;
v_8952:
    v_8985 = elt(env, 3); // quotientx
    goto v_8953;
v_8954:
    goto v_8948;
v_8949:
    goto v_8950;
v_8951:
    goto v_8952;
v_8953:
    fn = elt(env, 5); // bcint2op
    v_8985 = (*qfnn(fn))(fn, 3, v_8987, v_8986, v_8985);
    env = stack[-2];
    if (v_8985 == nil) goto v_8946;
    else goto v_8945;
v_8946:
    goto v_8963;
v_8959:
    goto v_8969;
v_8965:
    v_8985 = stack[-1];
    v_8986 = qcar(v_8985);
    goto v_8966;
v_8967:
    v_8985 = stack[0];
    v_8985 = qcar(v_8985);
    goto v_8968;
v_8969:
    goto v_8965;
v_8966:
    goto v_8967;
v_8968:
    fn = elt(env, 6); // quotfx
    v_8986 = (*qfn2(fn))(fn, v_8986, v_8985);
    goto v_8960;
v_8961:
    v_8985 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8962;
v_8963:
    goto v_8959;
v_8960:
    goto v_8961;
v_8962:
    return cons(v_8986, v_8985);
v_8945:
    goto v_8927;
v_8942:
    goto v_8982;
v_8978:
    v_8986 = stack[-1];
    goto v_8979;
v_8980:
    v_8985 = stack[0];
    goto v_8981;
v_8982:
    goto v_8978;
v_8979:
    goto v_8980;
v_8981:
    {
        fn = elt(env, 7); // quotsq
        return (*qfn2(fn))(fn, v_8986, v_8985);
    }
    v_8985 = nil;
v_8927:
    return onevalue(v_8985);
}



// Code for bcplus!?

static LispObject CC_bcplusW(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_8944, v_8945;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8944 = v_8923;
// end of prologue
    v_8944 = qcar(v_8944);
    v_8945 = v_8944;
    v_8944 = v_8945;
    if (is_number(v_8944)) goto v_8931;
    v_8944 = nil;
    goto v_8929;
v_8931:
    goto v_8941;
v_8937:
    goto v_8938;
v_8939:
    v_8944 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8940;
v_8941:
    goto v_8937;
v_8938:
    goto v_8939;
v_8940:
        return Lgreaterp(nil, v_8945, v_8944);
    v_8944 = nil;
v_8929:
    return onevalue(v_8944);
}



// Code for groebbuchcrit4t

static LispObject CC_groebbuchcrit4t(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_8977, v_8978;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_8924;
    stack[-1] = v_8923;
// end of prologue
v_8928:
    v_8977 = stack[-1];
    if (v_8977 == nil) goto v_8935;
    else goto v_8936;
v_8935:
    v_8977 = lisp_true;
    goto v_8934;
v_8936:
    v_8977 = stack[0];
    v_8977 = (v_8977 == nil ? lisp_true : nil);
    goto v_8934;
    v_8977 = nil;
v_8934:
    if (v_8977 == nil) goto v_8932;
    v_8977 = nil;
    goto v_8927;
v_8932:
    goto v_8954;
v_8950:
    v_8977 = stack[-1];
    v_8978 = qcar(v_8977);
    goto v_8951;
v_8952:
    v_8977 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8953;
v_8954:
    goto v_8950;
v_8951:
    goto v_8952;
v_8953:
    if (v_8978 == v_8977) goto v_8949;
    goto v_8963;
v_8959:
    v_8977 = stack[0];
    v_8978 = qcar(v_8977);
    goto v_8960;
v_8961:
    v_8977 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8962;
v_8963:
    goto v_8959;
v_8960:
    goto v_8961;
v_8962:
    v_8977 = Lneq(nil, v_8978, v_8977);
    env = stack[-2];
    goto v_8947;
v_8949:
    v_8977 = nil;
    goto v_8947;
    v_8977 = nil;
v_8947:
    if (v_8977 == nil) goto v_8945;
    v_8977 = lisp_true;
    goto v_8927;
v_8945:
    v_8977 = stack[-1];
    v_8977 = qcdr(v_8977);
    stack[-1] = v_8977;
    v_8977 = stack[0];
    v_8977 = qcdr(v_8977);
    stack[0] = v_8977;
    goto v_8928;
    v_8977 = nil;
v_8927:
    return onevalue(v_8977);
}



// Code for !*pf2wedgepf

static LispObject CC_Hpf2wedgepf(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_8956, v_8957, v_8958;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8923);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_8923;
// end of prologue
    stack[-1] = nil;
v_8928:
    v_8956 = stack[0];
    if (v_8956 == nil) goto v_8931;
    else goto v_8932;
v_8931:
    v_8956 = stack[-1];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_8956);
    }
v_8932:
    goto v_8945;
v_8939:
    v_8956 = stack[0];
    v_8956 = qcar(v_8956);
    v_8956 = qcar(v_8956);
    fn = elt(env, 2); // wedgefax
    v_8958 = (*qfn1(fn))(fn, v_8956);
    env = stack[-2];
    goto v_8940;
v_8941:
    v_8956 = stack[0];
    v_8956 = qcar(v_8956);
    v_8957 = qcdr(v_8956);
    goto v_8942;
v_8943:
    v_8956 = stack[-1];
    goto v_8944;
v_8945:
    goto v_8939;
v_8940:
    goto v_8941;
v_8942:
    goto v_8943;
v_8944:
    v_8956 = acons(v_8958, v_8957, v_8956);
    env = stack[-2];
    stack[-1] = v_8956;
    v_8956 = stack[0];
    v_8956 = qcdr(v_8956);
    stack[0] = v_8956;
    goto v_8928;
    v_8956 = nil;
    return onevalue(v_8956);
}



// Code for list!+list

static LispObject CC_listLlist(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_8960, v_8961;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_8924;
    stack[-1] = v_8923;
// end of prologue
    stack[-2] = nil;
v_8929:
    v_8960 = stack[-1];
    if (v_8960 == nil) goto v_8932;
    else goto v_8933;
v_8932:
    v_8960 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_8960);
    }
v_8933:
    goto v_8944;
v_8940:
    goto v_8950;
v_8946:
    v_8960 = stack[-1];
    v_8961 = qcar(v_8960);
    goto v_8947;
v_8948:
    v_8960 = stack[0];
    v_8960 = qcar(v_8960);
    goto v_8949;
v_8950:
    goto v_8946;
v_8947:
    goto v_8948;
v_8949:
    fn = elt(env, 2); // !:plus
    v_8961 = (*qfn2(fn))(fn, v_8961, v_8960);
    env = stack[-3];
    goto v_8941;
v_8942:
    v_8960 = stack[-2];
    goto v_8943;
v_8944:
    goto v_8940;
v_8941:
    goto v_8942;
v_8943:
    v_8960 = cons(v_8961, v_8960);
    env = stack[-3];
    stack[-2] = v_8960;
    v_8960 = stack[-1];
    v_8960 = qcdr(v_8960);
    stack[-1] = v_8960;
    v_8960 = stack[0];
    v_8960 = qcdr(v_8960);
    stack[0] = v_8960;
    goto v_8929;
    v_8960 = nil;
    return onevalue(v_8960);
}



// Code for simprepart

static LispObject CC_simprepart(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_8931, v_8932;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8923);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_8932 = v_8923;
// end of prologue
    v_8931 = nil;
// Binding !*factor
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_8931; // !*factor
    v_8931 = v_8932;
    v_8931 = qcar(v_8931);
    fn = elt(env, 2); // simp!*
    v_8931 = (*qfn1(fn))(fn, v_8931);
    env = stack[-1];
    fn = elt(env, 3); // repartsq
    v_8931 = (*qfn1(fn))(fn, v_8931);
    ;}  // end of a binding scope
    return onevalue(v_8931);
}



// Code for copyd

static LispObject CC_copyd(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_9019, v_9020, v_9021;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_8924;
    stack[-2] = v_8923;
// end of prologue
    v_9019 = stack[-1];
    fn = elt(env, 5); // getd
    v_9019 = (*qfn1(fn))(fn, v_9019);
    env = stack[-4];
    v_9020 = v_9019;
    if (v_9020 == nil) goto v_8933;
    else goto v_8934;
v_8933:
    goto v_8944;
v_8940:
    v_9020 = qvalue(elt(env, 1)); // !*savedef
    goto v_8941;
v_8942:
    v_9019 = elt(env, 1); // !*savedef
    goto v_8943;
v_8944:
    goto v_8940;
v_8941:
    goto v_8942;
v_8943:
    if (v_9020 == v_9019) goto v_8939;
    goto v_8954;
v_8948:
    stack[-3] = elt(env, 2); // rlisp
    goto v_8949;
v_8950:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8951;
v_8952:
    goto v_8962;
v_8958:
    v_9020 = stack[-1];
    goto v_8959;
v_8960:
    v_9019 = elt(env, 3); // "has no definition in copyd"
    goto v_8961;
v_8962:
    goto v_8958;
v_8959:
    goto v_8960;
v_8961:
    v_9019 = list2(v_9020, v_9019);
    env = stack[-4];
    goto v_8953;
v_8954:
    goto v_8948;
v_8949:
    goto v_8950;
v_8951:
    goto v_8952;
v_8953:
    fn = elt(env, 6); // rerror
    v_9019 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_9019);
    env = stack[-4];
    goto v_8937;
v_8939:
v_8937:
    goto v_8932;
v_8934:
    goto v_8974;
v_8968:
    v_9021 = stack[-2];
    goto v_8969;
v_8970:
    v_9020 = v_9019;
    v_9020 = qcar(v_9020);
    goto v_8971;
v_8972:
    v_9019 = qcdr(v_9019);
    goto v_8973;
v_8974:
    goto v_8968;
v_8969:
    goto v_8970;
v_8971:
    goto v_8972;
v_8973:
    fn = elt(env, 7); // putd
    v_9019 = (*qfnn(fn))(fn, 3, v_9021, v_9020, v_9019);
    env = stack[-4];
    v_9019 = stack[-1];
    if (!symbolp(v_9019)) v_9019 = nil;
    else { v_9019 = qfastgets(v_9019);
           if (v_9019 != nil) { v_9019 = elt(v_9019, 1); // lose
#ifdef RECORD_GET
             if (v_9019 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v_9019 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v_9019 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v_9019 == SPID_NOPROP) v_9019 = nil; else v_9019 = lisp_true; }}
#endif
    if (v_9019 == nil) goto v_8983;
    goto v_8991;
v_8987:
    v_9019 = stack[-2];
    v_9020 = ncons(v_9019);
    env = stack[-4];
    goto v_8988;
v_8989:
    v_9019 = elt(env, 4); // lose
    goto v_8990;
v_8991:
    goto v_8987;
v_8988:
    goto v_8989;
v_8990:
    v_9019 = Lflag(nil, v_9020, v_9019);
    env = stack[-4];
    goto v_8981;
v_8983:
v_8981:
    goto v_8932;
v_8932:
    goto v_9004;
v_9000:
    v_9020 = stack[-1];
    goto v_9001;
v_9002:
    v_9019 = elt(env, 1); // !*savedef
    goto v_9003;
v_9004:
    goto v_9000;
v_9001:
    goto v_9002;
v_9003:
    v_9020 = get(v_9020, v_9019);
    env = stack[-4];
    v_9019 = v_9020;
    if (v_9020 == nil) goto v_8998;
    goto v_9014;
v_9008:
    v_9021 = stack[-2];
    goto v_9009;
v_9010:
    v_9020 = elt(env, 1); // !*savedef
    goto v_9011;
v_9012:
    goto v_9013;
v_9014:
    goto v_9008;
v_9009:
    goto v_9010;
v_9011:
    goto v_9012;
v_9013:
    v_9019 = Lputprop(nil, 3, v_9021, v_9020, v_9019);
    goto v_8996;
v_8998:
v_8996:
    v_9019 = stack[-2];
    return onevalue(v_9019);
}



// Code for degree!-in!-variable

static LispObject CC_degreeKinKvariable(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_8998, v_8999;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_8923,v_8924);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_8924;
    stack[-1] = v_8923;
// end of prologue
    v_8998 = stack[-1];
    if (!consp(v_8998)) goto v_8932;
    else goto v_8933;
v_8932:
    v_8998 = lisp_true;
    goto v_8931;
v_8933:
    v_8998 = stack[-1];
    v_8998 = qcar(v_8998);
    v_8998 = (consp(v_8998) ? nil : lisp_true);
    goto v_8931;
    v_8998 = nil;
v_8931:
    if (v_8998 == nil) goto v_8929;
    v_8998 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8927;
v_8929:
    goto v_8948;
v_8944:
    v_8998 = stack[-1];
    v_8998 = qcar(v_8998);
    v_8999 = qcdr(v_8998);
    goto v_8945;
v_8946:
    v_8998 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8947;
v_8948:
    goto v_8944;
v_8945:
    goto v_8946;
v_8947:
    if (v_8999 == v_8998) goto v_8942;
    else goto v_8943;
v_8942:
    v_8998 = elt(env, 1); // "Polynomial with a zero coefficient found"
    {
        fn = elt(env, 2); // errorf
        return (*qfn1(fn))(fn, v_8998);
    }
v_8943:
    goto v_8961;
v_8957:
    v_8999 = stack[0];
    goto v_8958;
v_8959:
    v_8998 = stack[-1];
    v_8998 = qcar(v_8998);
    v_8998 = qcar(v_8998);
    v_8998 = qcar(v_8998);
    goto v_8960;
v_8961:
    goto v_8957;
v_8958:
    goto v_8959;
v_8960:
    if (equal(v_8999, v_8998)) goto v_8955;
    else goto v_8956;
v_8955:
    v_8998 = stack[-1];
    v_8998 = qcar(v_8998);
    v_8998 = qcar(v_8998);
    v_8998 = qcdr(v_8998);
    goto v_8927;
v_8956:
    goto v_8978;
v_8974:
    goto v_8984;
v_8980:
    v_8998 = stack[-1];
    v_8998 = qcar(v_8998);
    v_8999 = qcdr(v_8998);
    goto v_8981;
v_8982:
    v_8998 = stack[0];
    goto v_8983;
v_8984:
    goto v_8980;
v_8981:
    goto v_8982;
v_8983:
    stack[-2] = CC_degreeKinKvariable(elt(env, 0), v_8999, v_8998);
    env = stack[-3];
    goto v_8975;
v_8976:
    goto v_8994;
v_8990:
    v_8998 = stack[-1];
    v_8999 = qcdr(v_8998);
    goto v_8991;
v_8992:
    v_8998 = stack[0];
    goto v_8993;
v_8994:
    goto v_8990;
v_8991:
    goto v_8992;
v_8993:
    v_8998 = CC_degreeKinKvariable(elt(env, 0), v_8999, v_8998);
    env = stack[-3];
    goto v_8977;
v_8978:
    goto v_8974;
v_8975:
    goto v_8976;
v_8977:
    {
        LispObject v_9003 = stack[-2];
        fn = elt(env, 3); // max
        return (*qfn2(fn))(fn, v_9003, v_8998);
    }
    v_8998 = nil;
v_8927:
    return onevalue(v_8998);
}



// Code for aex_subrat1

static LispObject CC_aex_subrat1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8963, v_8964, v_8965;
    LispObject fn;
    LispObject v_8925, v_8924, v_8923;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "aex_subrat1");
    va_start(aa, nargs);
    v_8923 = va_arg(aa, LispObject);
    v_8924 = va_arg(aa, LispObject);
    v_8925 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_8925,v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_8923,v_8924,v_8925);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_8925;
    stack[-1] = v_8924;
    stack[-2] = v_8923;
// end of prologue
    v_8963 = stack[-2];
    fn = elt(env, 1); // aex_ex
    v_8963 = (*qfn1(fn))(fn, v_8963);
    env = stack[-3];
    goto v_8940;
v_8934:
    v_8965 = qcar(v_8963);
    goto v_8935;
v_8936:
    v_8964 = stack[-1];
    goto v_8937;
v_8938:
    v_8963 = stack[0];
    goto v_8939;
v_8940:
    goto v_8934;
v_8935:
    goto v_8936;
v_8937:
    goto v_8938;
v_8939:
    fn = elt(env, 2); // sfto_qsubhor1
    v_8963 = (*qfnn(fn))(fn, 3, v_8965, v_8964, v_8963);
    env = stack[-3];
    goto v_8950;
v_8946:
    stack[-1] = v_8963;
    goto v_8947;
v_8948:
    goto v_8957;
v_8953:
    v_8963 = qcar(v_8963);
    fn = elt(env, 3); // kernels
    stack[0] = (*qfn1(fn))(fn, v_8963);
    env = stack[-3];
    goto v_8954;
v_8955:
    v_8963 = stack[-2];
    fn = elt(env, 4); // aex_ctx
    v_8963 = (*qfn1(fn))(fn, v_8963);
    env = stack[-3];
    goto v_8956;
v_8957:
    goto v_8953;
v_8954:
    goto v_8955;
v_8956:
    fn = elt(env, 5); // ctx_filter
    v_8963 = (*qfn2(fn))(fn, stack[0], v_8963);
    env = stack[-3];
    goto v_8949;
v_8950:
    goto v_8946;
v_8947:
    goto v_8948;
v_8949:
    {
        LispObject v_8969 = stack[-1];
        fn = elt(env, 6); // aex_mk
        return (*qfn2(fn))(fn, v_8969, v_8963);
    }
    return onevalue(v_8963);
}



// Code for simplify!-filename

static LispObject CC_simplifyKfilename(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_8973, v_8974;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8923);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_8923;
// end of prologue
    v_8973 = stack[-1];
    v_8973 = Lexplodec(nil, v_8973);
    env = stack[-3];
    stack[-2] = v_8973;
    v_8973 = elt(env, 1); // "/packages/"
    v_8973 = Lexplodec(nil, v_8973);
    env = stack[-3];
    stack[0] = v_8973;
v_8935:
    v_8973 = stack[-2];
    if (v_8973 == nil) goto v_8938;
    goto v_8948;
v_8944:
    v_8974 = stack[-2];
    goto v_8945;
v_8946:
    v_8973 = stack[0];
    goto v_8947;
v_8948:
    goto v_8944;
v_8945:
    goto v_8946;
v_8947:
    fn = elt(env, 2); // starts!-with
    v_8973 = (*qfn2(fn))(fn, v_8974, v_8973);
    env = stack[-3];
    if (v_8973 == nil) goto v_8942;
    else goto v_8938;
v_8942:
    goto v_8939;
v_8938:
    goto v_8934;
v_8939:
    v_8973 = stack[-2];
    v_8973 = qcdr(v_8973);
    stack[-2] = v_8973;
    goto v_8935;
v_8934:
    v_8973 = stack[-2];
    if (v_8973 == nil) goto v_8956;
    else goto v_8957;
v_8956:
    v_8973 = stack[-1];
    goto v_8928;
v_8957:
    v_8973 = stack[-2];
    v_8973 = qcdr(v_8973);
    v_8973 = qcdr(v_8973);
    v_8973 = qcdr(v_8973);
    v_8973 = qcdr(v_8973);
    v_8973 = qcdr(v_8973);
    v_8973 = qcdr(v_8973);
    v_8973 = qcdr(v_8973);
    v_8973 = qcdr(v_8973);
    v_8973 = qcdr(v_8973);
    v_8973 = qcdr(v_8973);
    stack[-2] = v_8973;
    v_8973 = stack[-2];
    {
        fn = elt(env, 3); // list2string
        return (*qfn1(fn))(fn, v_8973);
    }
v_8928:
    return onevalue(v_8973);
}



// Code for prepreform

static LispObject CC_prepreform(LispObject env,
                         LispObject v_8923)
{
    env = qenv(env);
    LispObject v_8940, v_8941;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_8923);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_8940 = v_8923;
// end of prologue
    goto v_8930;
v_8926:
    stack[0] = v_8940;
    goto v_8927;
v_8928:
    goto v_8937;
v_8933:
    v_8941 = qvalue(elt(env, 1)); // ordl!*
    goto v_8934;
v_8935:
    v_8940 = qvalue(elt(env, 2)); // factors!*
    goto v_8936;
v_8937:
    goto v_8933;
v_8934:
    goto v_8935;
v_8936:
    v_8940 = Lappend(nil, v_8941, v_8940);
    env = stack[-1];
    goto v_8929;
v_8930:
    goto v_8926;
v_8927:
    goto v_8928;
v_8929:
    {
        LispObject v_8943 = stack[0];
        fn = elt(env, 3); // prepreform1
        return (*qfn2(fn))(fn, v_8943, v_8940);
    }
}



// Code for exptcompare

static LispObject CC_exptcompare(LispObject env,
                         LispObject v_8923, LispObject v_8924)
{
    env = qenv(env);
    LispObject v_8963, v_8964, v_8965;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8963 = v_8924;
    v_8964 = v_8923;
// end of prologue
    v_8965 = v_8964;
    if (!consp(v_8965)) goto v_8928;
    else goto v_8929;
v_8928:
    v_8965 = v_8963;
    if (!consp(v_8965)) goto v_8933;
    else goto v_8934;
v_8933:
    goto v_8941;
v_8937:
    goto v_8938;
v_8939:
    goto v_8940;
v_8941:
    goto v_8937;
v_8938:
    goto v_8939;
v_8940:
        return Lgreaterp(nil, v_8964, v_8963);
v_8934:
    v_8963 = nil;
    goto v_8932;
    v_8963 = nil;
v_8932:
    goto v_8927;
v_8929:
    v_8965 = v_8963;
    if (!consp(v_8965)) goto v_8947;
    else goto v_8948;
v_8947:
    v_8963 = lisp_true;
    goto v_8927;
v_8948:
    goto v_8958;
v_8954:
    v_8964 = qcar(v_8964);
    goto v_8955;
v_8956:
    v_8963 = qcar(v_8963);
    goto v_8957;
v_8958:
    goto v_8954;
v_8955:
    goto v_8956;
v_8957:
        return Lgreaterp(nil, v_8964, v_8963);
    v_8963 = nil;
v_8927:
    return onevalue(v_8963);
}



// Code for cl_smsimpl!-junct2

static LispObject CC_cl_smsimplKjunct2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_9039, v_9040, v_9041, v_9042;
    LispObject fn;
    LispObject v_8928, v_8927, v_8926, v_8925, v_8924, v_8923;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "cl_smsimpl-junct2");
    va_start(aa, nargs);
    v_8923 = va_arg(aa, LispObject);
    v_8924 = va_arg(aa, LispObject);
    v_8925 = va_arg(aa, LispObject);
    v_8926 = va_arg(aa, LispObject);
    v_8927 = va_arg(aa, LispObject);
    v_8928 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_8928,v_8927,v_8926,v_8925,v_8924,v_8923);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_8923,v_8924,v_8925,v_8926,v_8927,v_8928);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_8928;
    v_9039 = v_8927;
    v_9040 = v_8926;
    v_9041 = v_8925;
    stack[-2] = v_8924;
    v_9042 = v_8923;
// end of prologue
    goto v_8943;
v_8935:
    goto v_8936;
v_8937:
    goto v_8938;
v_8939:
    goto v_8940;
v_8941:
    goto v_8942;
v_8943:
    goto v_8935;
v_8936:
    goto v_8937;
v_8938:
    goto v_8939;
v_8940:
    goto v_8941;
v_8942:
    fn = elt(env, 6); // rl_smmkatl
    v_9039 = (*qfnn(fn))(fn, 4, v_9042, v_9041, v_9040, v_9039);
    env = stack[-4];
    stack[-3] = v_9039;
    goto v_8956;
v_8952:
    v_9040 = stack[-3];
    goto v_8953;
v_8954:
    v_9039 = stack[-1];
    goto v_8955;
v_8956:
    goto v_8952;
v_8953:
    goto v_8954;
v_8955:
    if (v_9040 == v_9039) goto v_8950;
    else goto v_8951;
v_8950:
    v_9039 = stack[-1];
    return ncons(v_9039);
v_8951:
    v_9039 = qvalue(elt(env, 1)); // !*rlsichk
    if (v_9039 == nil) goto v_8964;
    v_9039 = stack[-2];
    v_9040 = v_9039;
    v_9039 = nil;
    stack[-2] = v_9039;
    v_9039 = v_9040;
    stack[0] = v_9039;
v_8971:
    v_9039 = stack[0];
    if (v_9039 == nil) goto v_8975;
    else goto v_8976;
v_8975:
    goto v_8970;
v_8976:
    v_9039 = stack[0];
    v_9039 = qcar(v_9039);
    goto v_8987;
v_8983:
    v_9040 = v_9039;
    goto v_8984;
v_8985:
    v_9039 = stack[-2];
    goto v_8986;
v_8987:
    goto v_8983;
v_8984:
    goto v_8985;
v_8986:
    fn = elt(env, 7); // lto_insert
    v_9039 = (*qfn2(fn))(fn, v_9040, v_9039);
    env = stack[-4];
    stack[-2] = v_9039;
    v_9039 = stack[0];
    v_9039 = qcdr(v_9039);
    stack[0] = v_9039;
    goto v_8971;
v_8970:
    goto v_8962;
v_8964:
    v_9039 = stack[-2];
    v_9039 = Lnreverse(nil, v_9039);
    env = stack[-4];
    stack[-2] = v_9039;
    goto v_8962;
v_8962:
    v_9039 = qvalue(elt(env, 2)); // !*rlsiso
    if (v_9039 == nil) goto v_8999;
    goto v_9006;
v_9002:
    v_9040 = stack[-3];
    goto v_9003;
v_9004:
    v_9039 = elt(env, 3); // rl_ordatp
    goto v_9005;
v_9006:
    goto v_9002;
v_9003:
    goto v_9004;
v_9005:
    fn = elt(env, 8); // sort
    v_9039 = (*qfn2(fn))(fn, v_9040, v_9039);
    env = stack[-4];
    stack[-3] = v_9039;
    v_9039 = qvalue(elt(env, 4)); // !*rlsisocx
    if (v_9039 == nil) goto v_9012;
    goto v_9019;
v_9015:
    v_9040 = stack[-2];
    goto v_9016;
v_9017:
    v_9039 = elt(env, 5); // cl_sordp
    goto v_9018;
v_9019:
    goto v_9015;
v_9016:
    goto v_9017;
v_9018:
    fn = elt(env, 8); // sort
    v_9039 = (*qfn2(fn))(fn, v_9040, v_9039);
    env = stack[-4];
    stack[-2] = v_9039;
    goto v_9010;
v_9012:
v_9010:
    goto v_8997;
v_8999:
v_8997:
    goto v_9027;
v_9023:
    v_9040 = stack[-3];
    goto v_9024;
v_9025:
    v_9039 = stack[-2];
    goto v_9026;
v_9027:
    goto v_9023;
v_9024:
    goto v_9025;
v_9026:
    v_9039 = Lnconc(nil, v_9040, v_9039);
    env = stack[-4];
    v_9040 = v_9039;
    v_9039 = v_9040;
    if (v_9039 == nil) goto v_9033;
    v_9039 = v_9040;
    goto v_8933;
v_9033:
    v_9039 = stack[-1];
    fn = elt(env, 9); // cl_flip
    v_9039 = (*qfn1(fn))(fn, v_9039);
    return ncons(v_9039);
v_8933:
    return onevalue(v_9039);
}



setup_type const u17_setup[] =
{
    {"lex_restore_context",     CC_lex_restore_context,TOO_MANY_1,WRONG_NO_1},
    {"collect_cars",            CC_collect_cars,TOO_MANY_1,    WRONG_NO_1},
    {"processpartitie1",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_processpartitie1},
    {"talp_smwrmknowl",         TOO_FEW_2,      CC_talp_smwrmknowl,WRONG_NO_2},
    {"sq2sspl",                 TOO_FEW_2,      CC_sq2sspl,    WRONG_NO_2},
    {"ibalp_lenisone",          CC_ibalp_lenisone,TOO_MANY_1,  WRONG_NO_1},
    {"attributesml",            TOO_FEW_2,      CC_attributesml,WRONG_NO_2},
    {"maprin",                  CC_maprin,      TOO_MANY_1,    WRONG_NO_1},
    {"dm-eq",                   TOO_FEW_2,      CC_dmKeq,      WRONG_NO_2},
    {"modminusp:",              CC_modminuspT,  TOO_MANY_1,    WRONG_NO_1},
    {"xread1",                  CC_xread1,      TOO_MANY_1,    WRONG_NO_1},
    {"dpmat_coldegs",           CC_dpmat_coldegs,TOO_MANY_1,   WRONG_NO_1},
    {"pv_times1",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pv_times1},
    {"b:ordexp",                TOO_FEW_2,      CC_bTordexp,   WRONG_NO_2},
    {"simpatom",                CC_simpatom,    TOO_MANY_1,    WRONG_NO_1},
    {"xremainder-mod-p",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_xremainderKmodKp},
    {"update_kc_list",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_update_kc_list},
    {"get_action",              TOO_FEW_2,      CC_get_action, WRONG_NO_2},
    {"wureducedpolysp",         TOO_FEW_2,      CC_wureducedpolysp,WRONG_NO_2},
    {"constsml",                CC_constsml,    TOO_MANY_1,    WRONG_NO_1},
    {"sacar",                   TOO_FEW_2,      CC_sacar,      WRONG_NO_2},
    {"findnewvars",             CC_findnewvars, TOO_MANY_1,    WRONG_NO_1},
    {"vbcgcd",                  TOO_FEW_2,      CC_vbcgcd,     WRONG_NO_2},
    {"vdpred",                  CC_vdpred,      TOO_MANY_1,    WRONG_NO_1},
    {"xord_gradlex",            TOO_FEW_2,      CC_xord_gradlex,WRONG_NO_2},
    {"removeindices",           TOO_FEW_2,      CC_removeindices,WRONG_NO_2},
    {"simp-sign",               CC_simpKsign,   TOO_MANY_1,    WRONG_NO_1},
    {"sqp",                     CC_sqp,         TOO_MANY_1,    WRONG_NO_1},
    {"invbf",                   CC_invbf,       TOO_MANY_1,    WRONG_NO_1},
    {"in_list1",                TOO_FEW_2,      CC_in_list1,   WRONG_NO_2},
    {"mkkl",                    TOO_FEW_2,      CC_mkkl,       WRONG_NO_2},
    {"findremainder",           TOO_FEW_2,      CC_findremainder,WRONG_NO_2},
    {"talp_eqtp",               TOO_FEW_2,      CC_talp_eqtp,  WRONG_NO_2},
    {"qqe_simplat1",            TOO_FEW_2,      CC_qqe_simplat1,WRONG_NO_2},
    {"cgp_number",              CC_cgp_number,  TOO_MANY_1,    WRONG_NO_1},
    {"nary",                    TOO_FEW_2,      CC_nary,       WRONG_NO_2},
    {"spband_matrix",           TOO_FEW_2,      CC_spband_matrix,WRONG_NO_2},
    {"inshisto",                CC_inshisto,    TOO_MANY_1,    WRONG_NO_1},
    {"bcquot",                  TOO_FEW_2,      CC_bcquot,     WRONG_NO_2},
    {"bcplus?",                 CC_bcplusW,     TOO_MANY_1,    WRONG_NO_1},
    {"groebbuchcrit4t",         TOO_FEW_2,      CC_groebbuchcrit4t,WRONG_NO_2},
    {"*pf2wedgepf",             CC_Hpf2wedgepf, TOO_MANY_1,    WRONG_NO_1},
    {"list+list",               TOO_FEW_2,      CC_listLlist,  WRONG_NO_2},
    {"simprepart",              CC_simprepart,  TOO_MANY_1,    WRONG_NO_1},
    {"copyd",                   TOO_FEW_2,      CC_copyd,      WRONG_NO_2},
    {"degree-in-variable",      TOO_FEW_2,      CC_degreeKinKvariable,WRONG_NO_2},
    {"aex_subrat1",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_aex_subrat1},
    {"simplify-filename",       CC_simplifyKfilename,TOO_MANY_1,WRONG_NO_1},
    {"prepreform",              CC_prepreform,  TOO_MANY_1,    WRONG_NO_1},
    {"exptcompare",             TOO_FEW_2,      CC_exptcompare,WRONG_NO_2},
    {"cl_smsimpl-junct2",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_smsimplKjunct2},
    {NULL, (one_args *)"u17", (two_args *)"11976 9252619 8197870", 0}
};

// end of generated code
