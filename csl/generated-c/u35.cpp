
// $destdir/u35.c        Machine generated C code

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



// Code for matsm1

static LispObject CC_matsm1(LispObject env,
                         LispObject v_19548)
{
    env = qenv(env);
    LispObject v_20405, v_20406, v_20407;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19548);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-8] = v_19548;
// end of prologue
    stack[-9] = nil;
v_19557:
    v_20405 = stack[-8];
    if (v_20405 == nil) goto v_19568;
    else goto v_19569;
v_19568:
    v_20405 = stack[-9];
    goto v_19556;
v_19569:
    goto v_19579;
v_19575:
    v_20405 = stack[-8];
    v_20406 = qcar(v_20405);
    goto v_19576;
v_19577:
    v_20405 = elt(env, 1); // !*div
    goto v_19578;
v_19579:
    goto v_19575;
v_19576:
    goto v_19577;
v_19578:
    if (!consp(v_20406)) goto v_19573;
    v_20406 = qcar(v_20406);
    if (v_20406 == v_20405) goto v_19572;
    else goto v_19573;
v_19572:
    goto v_19591;
v_19587:
    v_20405 = stack[-8];
    v_20406 = Llength(nil, v_20405);
    env = stack[-10];
    goto v_19588;
v_19589:
    v_20405 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19590;
v_19591:
    goto v_19587;
v_19588:
    goto v_19589;
v_19590:
    if (v_20406 == v_20405) goto v_19585;
    else goto v_19586;
v_19585:
    goto v_19561;
v_19586:
    goto v_19605;
v_19601:
    v_20405 = stack[-8];
    v_20406 = Llength(nil, v_20405);
    env = stack[-10];
    goto v_19602;
v_19603:
    v_20405 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_19604;
v_19605:
    goto v_19601;
v_19602:
    goto v_19603;
v_19604:
    if (v_20406 == v_20405) goto v_19599;
    else goto v_19600;
v_19599:
    goto v_19613;
v_19609:
    v_20405 = stack[-8];
    v_20405 = qcdr(v_20405);
    v_20405 = qcar(v_20405);
    v_20406 = qcar(v_20405);
    goto v_19610;
v_19611:
    v_20405 = elt(env, 2); // sparsemat
    goto v_19612;
v_19613:
    goto v_19609;
v_19610:
    goto v_19611;
v_19612:
    v_20405 = (v_20406 == v_20405 ? lisp_true : nil);
    goto v_19598;
v_19600:
    v_20405 = nil;
    goto v_19598;
    v_20405 = nil;
v_19598:
    if (v_20405 == nil) goto v_19596;
    v_20405 = stack[-8];
    v_20405 = qcdr(v_20405);
    stack[-9] = v_20405;
    goto v_19561;
v_19596:
    goto v_19561;
    goto v_19567;
v_19573:
    v_20405 = stack[-8];
    v_20405 = qcar(v_20405);
    if (!consp(v_20405)) goto v_19628;
    else goto v_19629;
v_19628:
    goto v_19564;
v_19629:
    goto v_19638;
v_19634:
    v_20405 = stack[-8];
    v_20405 = qcar(v_20405);
    v_20406 = qcar(v_20405);
    goto v_19635;
v_19636:
    v_20405 = elt(env, 3); // mat
    goto v_19637;
v_19638:
    goto v_19634;
v_19635:
    goto v_19636;
v_19637:
    if (v_20406 == v_20405) goto v_19632;
    else goto v_19633;
v_19632:
    goto v_19560;
v_19633:
    goto v_19653;
v_19649:
    v_20405 = stack[-8];
    v_20405 = qcar(v_20405);
    v_20406 = qcar(v_20405);
    goto v_19650;
v_19651:
    v_20405 = elt(env, 2); // sparsemat
    goto v_19652;
v_19653:
    goto v_19649;
v_19650:
    goto v_19651;
v_19652:
    if (v_20406 == v_20405) goto v_19647;
    else goto v_19648;
v_19647:
    goto v_19662;
v_19658:
    v_20405 = stack[-8];
    v_20406 = Llength(nil, v_20405);
    env = stack[-10];
    goto v_19659;
v_19660:
    v_20405 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19661;
v_19662:
    goto v_19658;
v_19659:
    goto v_19660;
v_19661:
    v_20405 = (v_20406 == v_20405 ? lisp_true : nil);
    goto v_19646;
v_19648:
    v_20405 = nil;
    goto v_19646;
    v_20405 = nil;
v_19646:
    if (v_20405 == nil) goto v_19644;
    v_20405 = stack[-8];
    stack[-9] = v_20405;
    goto v_19559;
v_19644:
    goto v_19681;
v_19677:
    v_20405 = stack[-8];
    v_20405 = qcar(v_20405);
    v_20406 = qcar(v_20405);
    goto v_19678;
v_19679:
    v_20405 = elt(env, 2); // sparsemat
    goto v_19680;
v_19681:
    goto v_19677;
v_19678:
    goto v_19679;
v_19680:
    if (v_20406 == v_20405) goto v_19675;
    else goto v_19676;
v_19675:
    goto v_19690;
v_19686:
    v_20405 = stack[-8];
    v_20406 = Llength(nil, v_20405);
    env = stack[-10];
    goto v_19687;
v_19688:
    v_20405 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_19689;
v_19690:
    goto v_19686;
v_19687:
    goto v_19688;
v_19689:
    v_20405 = (v_20406 == v_20405 ? lisp_true : nil);
    goto v_19674;
v_19676:
    v_20405 = nil;
    goto v_19674;
    v_20405 = nil;
v_19674:
    if (v_20405 == nil) goto v_19672;
    goto v_19707;
v_19703:
    v_20405 = stack[-8];
    v_20405 = Lreverse(nil, v_20405);
    env = stack[-10];
    v_20406 = qcar(v_20405);
    goto v_19704;
v_19705:
    v_20405 = elt(env, 1); // !*div
    goto v_19706;
v_19707:
    goto v_19703;
v_19704:
    goto v_19705;
v_19706:
    if (!consp(v_20406)) goto v_19701;
    v_20406 = qcar(v_20406);
    if (v_20406 == v_20405) goto v_19700;
    else goto v_19701;
v_19700:
    v_20405 = stack[-8];
    v_20405 = Lreverse(nil, v_20405);
    env = stack[-10];
    stack[-8] = v_20405;
    v_20405 = stack[-8];
    v_20405 = qcdr(v_20405);
    stack[-9] = v_20405;
    goto v_19561;
v_19701:
    goto v_19723;
v_19719:
    v_20405 = stack[-8];
    v_20406 = qcar(v_20405);
    goto v_19720;
v_19721:
    v_20405 = stack[-8];
    v_20405 = qcdr(v_20405);
    goto v_19722;
v_19723:
    goto v_19719;
v_19720:
    goto v_19721;
v_19722:
    fn = elt(env, 15); // spmultm
    v_20405 = (*qfn2(fn))(fn, v_20406, v_20405);
    env = stack[-10];
    stack[-9] = v_20405;
    v_20405 = stack[-8];
    v_20405 = qcdr(v_20405);
    stack[-8] = v_20405;
    goto v_19559;
    goto v_19567;
v_19672:
    goto v_19737;
v_19733:
    v_20405 = stack[-8];
    v_20405 = qcar(v_20405);
    v_20406 = qcar(v_20405);
    goto v_19734;
v_19735:
    v_20405 = elt(env, 2); // sparsemat
    goto v_19736;
v_19737:
    goto v_19733;
v_19734:
    goto v_19735;
v_19736:
    if (v_20406 == v_20405) goto v_19731;
    else goto v_19732;
v_19731:
    goto v_19747;
v_19743:
    v_20405 = stack[-8];
    v_20406 = qcar(v_20405);
    goto v_19744;
v_19745:
    v_20405 = stack[-8];
    v_20405 = qcdr(v_20405);
    goto v_19746;
v_19747:
    goto v_19743;
v_19744:
    goto v_19745;
v_19746:
    fn = elt(env, 15); // spmultm
    v_20405 = (*qfn2(fn))(fn, v_20406, v_20405);
    env = stack[-10];
    stack[-9] = v_20405;
    v_20405 = nil;
    v_20405 = ncons(v_20405);
    env = stack[-10];
    stack[-8] = v_20405;
    goto v_19559;
v_19732:
    goto v_19761;
v_19757:
    v_20405 = stack[-8];
    v_20405 = qcar(v_20405);
    v_20406 = qcar(v_20405);
    goto v_19758;
v_19759:
    v_20405 = stack[-8];
    v_20405 = qcar(v_20405);
    v_20405 = qcdr(v_20405);
    goto v_19760;
v_19761:
    goto v_19757;
v_19758:
    goto v_19759;
v_19760:
    fn = elt(env, 16); // lispapply
    v_20405 = (*qfn2(fn))(fn, v_20406, v_20405);
    env = stack[-10];
    stack[0] = v_20405;
    goto v_19567;
v_19567:
v_19558:
    v_20405 = stack[-9];
    if (v_20405 == nil) goto v_19770;
    else goto v_19771;
v_19770:
    v_20405 = stack[0];
    goto v_19769;
v_19771:
    v_20405 = stack[-9];
    v_20405 = qcdr(v_20405);
    if (v_20405 == nil) goto v_19778;
    else goto v_19779;
v_19778:
    v_20405 = stack[-9];
    v_20405 = qcar(v_20405);
    v_20405 = qcdr(v_20405);
    v_20405 = (v_20405 == nil ? lisp_true : nil);
    goto v_19777;
v_19779:
    v_20405 = nil;
    goto v_19777;
    v_20405 = nil;
v_19777:
    if (v_20405 == nil) goto v_19775;
    goto v_19794;
v_19790:
    v_20405 = stack[-9];
    v_20405 = qcar(v_20405);
    v_20406 = qcar(v_20405);
    goto v_19791;
v_19792:
    v_20405 = stack[0];
    goto v_19793;
v_19794:
    goto v_19790;
v_19791:
    goto v_19792;
v_19793:
    fn = elt(env, 17); // multsm
    v_20405 = (*qfn2(fn))(fn, v_20406, v_20405);
    env = stack[-10];
    goto v_19769;
v_19775:
    goto v_19806;
v_19802:
    v_20406 = stack[0];
    goto v_19803;
v_19804:
    v_20405 = stack[-9];
    goto v_19805;
v_19806:
    goto v_19802;
v_19803:
    goto v_19804;
v_19805:
    fn = elt(env, 18); // multm
    v_20405 = (*qfn2(fn))(fn, v_20406, v_20405);
    env = stack[-10];
    goto v_19769;
    v_20405 = nil;
v_19769:
    stack[-9] = v_20405;
v_19559:
    v_20405 = stack[-8];
    v_20405 = qcdr(v_20405);
    stack[-8] = v_20405;
    goto v_19557;
v_19560:
    v_20405 = stack[-8];
    v_20405 = qcar(v_20405);
    v_20405 = qcdr(v_20405);
    fn = elt(env, 19); // lchk
    v_20405 = (*qfn1(fn))(fn, v_20405);
    env = stack[-10];
    if (v_20405 == nil) goto v_19813;
    else goto v_19814;
v_19813:
    goto v_19826;
v_19820:
    v_20407 = elt(env, 4); // matrix
    goto v_19821;
v_19822:
    v_20406 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_19823;
v_19824:
    v_20405 = elt(env, 5); // "Matrix mismatch"
    goto v_19825;
v_19826:
    goto v_19820;
v_19821:
    goto v_19822;
v_19823:
    goto v_19824;
v_19825:
    fn = elt(env, 20); // rerror
    v_20405 = (*qfnn(fn))(fn, 3, v_20407, v_20406, v_20405);
    env = stack[-10];
    goto v_19812;
v_19814:
v_19812:
    v_20405 = stack[-8];
    v_20405 = qcar(v_20405);
    v_20405 = qcdr(v_20405);
    stack[-7] = v_20405;
    v_20405 = stack[-7];
    if (v_20405 == nil) goto v_19841;
    else goto v_19842;
v_19841:
    v_20405 = nil;
    goto v_19834;
v_19842:
    v_20405 = stack[-7];
    v_20405 = qcar(v_20405);
    stack[-3] = v_20405;
    v_20405 = stack[-3];
    if (v_20405 == nil) goto v_19858;
    else goto v_19859;
v_19858:
    v_20405 = nil;
    goto v_19853;
v_19859:
    v_20405 = stack[-3];
    v_20405 = qcar(v_20405);
    fn = elt(env, 21); // xsimp
    v_20405 = (*qfn1(fn))(fn, v_20405);
    env = stack[-10];
    v_20405 = ncons(v_20405);
    env = stack[-10];
    stack[-1] = v_20405;
    stack[-2] = v_20405;
v_19854:
    v_20405 = stack[-3];
    v_20405 = qcdr(v_20405);
    stack[-3] = v_20405;
    v_20405 = stack[-3];
    if (v_20405 == nil) goto v_19872;
    else goto v_19873;
v_19872:
    v_20405 = stack[-2];
    goto v_19853;
v_19873:
    goto v_19881;
v_19877:
    stack[0] = stack[-1];
    goto v_19878;
v_19879:
    v_20405 = stack[-3];
    v_20405 = qcar(v_20405);
    fn = elt(env, 21); // xsimp
    v_20405 = (*qfn1(fn))(fn, v_20405);
    env = stack[-10];
    v_20405 = ncons(v_20405);
    env = stack[-10];
    goto v_19880;
v_19881:
    goto v_19877;
v_19878:
    goto v_19879;
v_19880:
    v_20405 = Lrplacd(nil, stack[0], v_20405);
    env = stack[-10];
    v_20405 = stack[-1];
    v_20405 = qcdr(v_20405);
    stack[-1] = v_20405;
    goto v_19854;
v_19853:
    v_20405 = ncons(v_20405);
    env = stack[-10];
    stack[-5] = v_20405;
    stack[-6] = v_20405;
v_19835:
    v_20405 = stack[-7];
    v_20405 = qcdr(v_20405);
    stack[-7] = v_20405;
    v_20405 = stack[-7];
    if (v_20405 == nil) goto v_19895;
    else goto v_19896;
v_19895:
    v_20405 = stack[-6];
    goto v_19834;
v_19896:
    goto v_19904;
v_19900:
    stack[-4] = stack[-5];
    goto v_19901;
v_19902:
    v_20405 = stack[-7];
    v_20405 = qcar(v_20405);
    stack[-3] = v_20405;
    v_20405 = stack[-3];
    if (v_20405 == nil) goto v_19919;
    else goto v_19920;
v_19919:
    v_20405 = nil;
    goto v_19914;
v_19920:
    v_20405 = stack[-3];
    v_20405 = qcar(v_20405);
    fn = elt(env, 21); // xsimp
    v_20405 = (*qfn1(fn))(fn, v_20405);
    env = stack[-10];
    v_20405 = ncons(v_20405);
    env = stack[-10];
    stack[-1] = v_20405;
    stack[-2] = v_20405;
v_19915:
    v_20405 = stack[-3];
    v_20405 = qcdr(v_20405);
    stack[-3] = v_20405;
    v_20405 = stack[-3];
    if (v_20405 == nil) goto v_19933;
    else goto v_19934;
v_19933:
    v_20405 = stack[-2];
    goto v_19914;
v_19934:
    goto v_19942;
v_19938:
    stack[0] = stack[-1];
    goto v_19939;
v_19940:
    v_20405 = stack[-3];
    v_20405 = qcar(v_20405);
    fn = elt(env, 21); // xsimp
    v_20405 = (*qfn1(fn))(fn, v_20405);
    env = stack[-10];
    v_20405 = ncons(v_20405);
    env = stack[-10];
    goto v_19941;
v_19942:
    goto v_19938;
v_19939:
    goto v_19940;
v_19941:
    v_20405 = Lrplacd(nil, stack[0], v_20405);
    env = stack[-10];
    v_20405 = stack[-1];
    v_20405 = qcdr(v_20405);
    stack[-1] = v_20405;
    goto v_19915;
v_19914:
    v_20405 = ncons(v_20405);
    env = stack[-10];
    goto v_19903;
v_19904:
    goto v_19900;
v_19901:
    goto v_19902;
v_19903:
    v_20405 = Lrplacd(nil, stack[-4], v_20405);
    env = stack[-10];
    v_20405 = stack[-5];
    v_20405 = qcdr(v_20405);
    stack[-5] = v_20405;
    goto v_19835;
v_19834:
    stack[0] = v_20405;
    goto v_19558;
v_19561:
    goto v_19962;
v_19958:
    v_20405 = stack[-8];
    v_20405 = qcar(v_20405);
    v_20405 = qcdr(v_20405);
    v_20405 = qcar(v_20405);
    fn = elt(env, 22); // checksp
    v_20406 = (*qfn1(fn))(fn, v_20405);
    env = stack[-10];
    goto v_19959;
v_19960:
    v_20405 = elt(env, 6); // sparse
    goto v_19961;
v_19962:
    goto v_19958;
v_19959:
    goto v_19960;
v_19961:
    if (v_20406 == v_20405) goto v_19956;
    else goto v_19957;
v_19956:
    v_20405 = stack[-8];
    v_20405 = qcar(v_20405);
    v_20405 = qcdr(v_20405);
    v_20405 = qcar(v_20405);
    fn = elt(env, 23); // spmatsm
    v_20405 = (*qfn1(fn))(fn, v_20405);
    env = stack[-10];
    stack[-2] = v_20405;
    v_20405 = stack[-2];
    v_20405 = Lreverse(nil, v_20405);
    env = stack[-10];
    v_20405 = qcar(v_20405);
    v_20405 = qcdr(v_20405);
    goto v_19986;
v_19982:
    v_20406 = v_20405;
    v_20406 = qcar(v_20406);
    goto v_19983;
v_19984:
    v_20405 = qcdr(v_20405);
    v_20405 = qcar(v_20405);
    goto v_19985;
v_19986:
    goto v_19982;
v_19983:
    goto v_19984;
v_19985:
    if (equal(v_20406, v_20405)) goto v_19981;
    goto v_19999;
v_19993:
    v_20407 = elt(env, 4); // matrix
    goto v_19994;
v_19995:
    v_20406 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_19996;
v_19997:
    v_20405 = elt(env, 7); // "Non square matrix"
    goto v_19998;
v_19999:
    goto v_19993;
v_19994:
    goto v_19995;
v_19996:
    goto v_19997;
v_19998:
    fn = elt(env, 20); // rerror
    v_20405 = (*qfnn(fn))(fn, 3, v_20407, v_20406, v_20405);
    env = stack[-10];
    goto v_19979;
v_19981:
v_19979:
    goto v_19955;
v_19957:
    v_20405 = stack[-8];
    v_20405 = qcar(v_20405);
    v_20405 = qcdr(v_20405);
    v_20405 = qcar(v_20405);
    fn = elt(env, 24); // matsm
    v_20405 = (*qfn1(fn))(fn, v_20405);
    env = stack[-10];
    stack[-2] = v_20405;
    goto v_20018;
v_20014:
    v_20405 = stack[-2];
    v_20405 = qcar(v_20405);
    stack[0] = Llength(nil, v_20405);
    env = stack[-10];
    stack[-1] = stack[0];
    goto v_20015;
v_20016:
    v_20405 = stack[-2];
    v_20405 = Llength(nil, v_20405);
    env = stack[-10];
    goto v_20017;
v_20018:
    goto v_20014;
v_20015:
    goto v_20016;
v_20017:
    if (equal(stack[0], v_20405)) goto v_20013;
    goto v_20031;
v_20025:
    v_20407 = elt(env, 4); // matrix
    goto v_20026;
v_20027:
    v_20406 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_20028;
v_20029:
    v_20405 = elt(env, 7); // "Non square matrix"
    goto v_20030;
v_20031:
    goto v_20025;
v_20026:
    goto v_20027;
v_20028:
    goto v_20029;
v_20030:
    fn = elt(env, 20); // rerror
    v_20405 = (*qfnn(fn))(fn, 3, v_20407, v_20406, v_20405);
    env = stack[-10];
    goto v_20011;
v_20013:
    v_20405 = stack[-9];
    if (v_20405 == nil) goto v_20036;
    goto v_20044;
v_20040:
    stack[0] = stack[-1];
    goto v_20041;
v_20042:
    v_20405 = stack[-9];
    v_20405 = Llength(nil, v_20405);
    env = stack[-10];
    goto v_20043;
v_20044:
    goto v_20040;
v_20041:
    goto v_20042;
v_20043:
    if (equal(stack[0], v_20405)) goto v_20036;
    goto v_20055;
v_20049:
    v_20407 = elt(env, 4); // matrix
    goto v_20050;
v_20051:
    v_20406 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_20052;
v_20053:
    v_20405 = elt(env, 5); // "Matrix mismatch"
    goto v_20054;
v_20055:
    goto v_20049;
v_20050:
    goto v_20051;
v_20052:
    goto v_20053;
v_20054:
    fn = elt(env, 20); // rerror
    v_20405 = (*qfnn(fn))(fn, 3, v_20407, v_20406, v_20405);
    env = stack[-10];
    goto v_20011;
v_20036:
    v_20405 = stack[-8];
    v_20405 = qcar(v_20405);
    v_20405 = qcdr(v_20405);
    v_20405 = qcdr(v_20405);
    if (v_20405 == nil) goto v_20060;
    goto v_19563;
v_20060:
    v_20405 = stack[-2];
    v_20405 = qcdr(v_20405);
    if (v_20405 == nil) goto v_20069;
    else goto v_20070;
v_20069:
    v_20405 = stack[-2];
    v_20405 = qcar(v_20405);
    v_20405 = qcdr(v_20405);
    v_20405 = (v_20405 == nil ? lisp_true : nil);
    goto v_20068;
v_20070:
    v_20405 = nil;
    goto v_20068;
    v_20405 = nil;
v_20068:
    if (v_20405 == nil) goto v_20066;
    goto v_19562;
v_20066:
v_20011:
    goto v_19955;
v_19955:
    v_20405 = qvalue(elt(env, 8)); // subfg!*
    stack[0] = v_20405;
    v_20405 = nil;
    qvalue(elt(env, 8)) = v_20405; // subfg!*
    v_20405 = stack[-9];
    if (v_20405 == nil) goto v_20084;
    else goto v_20085;
v_20084:
    goto v_20092;
v_20088:
    goto v_20098;
v_20094:
    v_20406 = elt(env, 3); // mat
    goto v_20095;
v_20096:
    v_20405 = elt(env, 9); // inversefn
    goto v_20097;
v_20098:
    goto v_20094;
v_20095:
    goto v_20096;
v_20097:
    v_20406 = get(v_20406, v_20405);
    env = stack[-10];
    goto v_20089;
v_20090:
    v_20405 = stack[-2];
    goto v_20091;
v_20092:
    goto v_20088;
v_20089:
    goto v_20090;
v_20091:
    v_20405 = Lapply1(nil, v_20406, v_20405);
    env = stack[-10];
    stack[-9] = v_20405;
    goto v_20083;
v_20085:
    goto v_20108;
v_20104:
    v_20405 = stack[-9];
    v_20405 = qcar(v_20405);
    v_20406 = qcar(v_20405);
    goto v_20105;
v_20106:
    v_20405 = elt(env, 2); // sparsemat
    goto v_20107;
v_20108:
    goto v_20104;
v_20105:
    goto v_20106;
v_20107:
    if (v_20406 == v_20405) goto v_20102;
    else goto v_20103;
v_20102:
    goto v_20119;
v_20115:
    goto v_20125;
v_20121:
    goto v_20131;
v_20127:
    v_20406 = elt(env, 3); // mat
    goto v_20128;
v_20129:
    v_20405 = elt(env, 9); // inversefn
    goto v_20130;
v_20131:
    goto v_20127;
v_20128:
    goto v_20129;
v_20130:
    v_20406 = get(v_20406, v_20405);
    env = stack[-10];
    goto v_20122;
v_20123:
    v_20405 = stack[-2];
    goto v_20124;
v_20125:
    goto v_20121;
v_20122:
    goto v_20123;
v_20124:
    v_20405 = Lapply1(nil, v_20406, v_20405);
    env = stack[-10];
    v_20406 = qcar(v_20405);
    goto v_20116;
v_20117:
    v_20405 = stack[-9];
    goto v_20118;
v_20119:
    goto v_20115;
v_20116:
    goto v_20117;
v_20118:
    fn = elt(env, 15); // spmultm
    v_20405 = (*qfn2(fn))(fn, v_20406, v_20405);
    env = stack[-10];
    v_20405 = ncons(v_20405);
    env = stack[-10];
    stack[-9] = v_20405;
    v_20405 = stack[-8];
    v_20405 = qcdr(v_20405);
    stack[-8] = v_20405;
    goto v_20083;
v_20103:
    goto v_20147;
v_20143:
    v_20406 = elt(env, 3); // mat
    goto v_20144;
v_20145:
    v_20405 = elt(env, 10); // lnrsolvefn
    goto v_20146;
v_20147:
    goto v_20143;
v_20144:
    goto v_20145;
v_20146:
    v_20405 = get(v_20406, v_20405);
    env = stack[-10];
    stack[0] = v_20405;
    if (v_20405 == nil) goto v_20140;
    else goto v_20141;
v_20140:
    goto v_20155;
v_20151:
    goto v_20161;
v_20157:
    goto v_20167;
v_20163:
    v_20406 = elt(env, 3); // mat
    goto v_20164;
v_20165:
    v_20405 = elt(env, 9); // inversefn
    goto v_20166;
v_20167:
    goto v_20163;
v_20164:
    goto v_20165;
v_20166:
    v_20406 = get(v_20406, v_20405);
    env = stack[-10];
    goto v_20158;
v_20159:
    v_20405 = stack[-2];
    goto v_20160;
v_20161:
    goto v_20157;
v_20158:
    goto v_20159;
v_20160:
    v_20406 = Lapply1(nil, v_20406, v_20405);
    env = stack[-10];
    goto v_20152;
v_20153:
    v_20405 = stack[-9];
    goto v_20154;
v_20155:
    goto v_20151;
v_20152:
    goto v_20153;
v_20154:
    fn = elt(env, 18); // multm
    v_20405 = (*qfn2(fn))(fn, v_20406, v_20405);
    env = stack[-10];
    stack[-9] = v_20405;
    goto v_20083;
v_20141:
    goto v_20181;
v_20175:
    goto v_20187;
v_20183:
    v_20406 = elt(env, 3); // mat
    goto v_20184;
v_20185:
    v_20405 = elt(env, 10); // lnrsolvefn
    goto v_20186;
v_20187:
    goto v_20183;
v_20184:
    goto v_20185;
v_20186:
    v_20407 = get(v_20406, v_20405);
    env = stack[-10];
    goto v_20176;
v_20177:
    v_20406 = stack[-2];
    goto v_20178;
v_20179:
    v_20405 = stack[-9];
    goto v_20180;
v_20181:
    goto v_20175;
v_20176:
    goto v_20177;
v_20178:
    goto v_20179;
v_20180:
    v_20405 = Lapply2(nil, 3, v_20407, v_20406, v_20405);
    env = stack[-10];
    stack[-9] = v_20405;
    goto v_20083;
v_20083:
    v_20405 = stack[0];
    qvalue(elt(env, 8)) = v_20405; // subfg!*
    goto v_20201;
v_20197:
    v_20405 = stack[-9];
    v_20405 = qcar(v_20405);
    v_20406 = qcar(v_20405);
    goto v_20198;
v_20199:
    v_20405 = elt(env, 2); // sparsemat
    goto v_20200;
v_20201:
    goto v_20197;
v_20198:
    goto v_20199;
v_20200:
    if (v_20406 == v_20405) goto v_20195;
    else goto v_20196;
v_20195:
    v_20405 = stack[-9];
    stack[-9] = v_20405;
    goto v_20194;
v_20196:
    v_20405 = stack[-9];
    stack[-7] = v_20405;
    v_20405 = stack[-7];
    if (v_20405 == nil) goto v_20218;
    else goto v_20219;
v_20218:
    v_20405 = nil;
    goto v_20213;
v_20219:
    v_20405 = stack[-7];
    v_20405 = qcar(v_20405);
    stack[-3] = v_20405;
    v_20405 = stack[-3];
    if (v_20405 == nil) goto v_20235;
    else goto v_20236;
v_20235:
    v_20405 = nil;
    goto v_20230;
v_20236:
    v_20405 = stack[-3];
    v_20405 = qcar(v_20405);
    v_20406 = v_20405;
    v_20405 = lisp_true;
    qvalue(elt(env, 11)) = v_20405; // !*sub2
    v_20405 = v_20406;
    fn = elt(env, 25); // subs2
    v_20405 = (*qfn1(fn))(fn, v_20405);
    env = stack[-10];
    v_20405 = ncons(v_20405);
    env = stack[-10];
    stack[-1] = v_20405;
    stack[-2] = v_20405;
v_20231:
    v_20405 = stack[-3];
    v_20405 = qcdr(v_20405);
    stack[-3] = v_20405;
    v_20405 = stack[-3];
    if (v_20405 == nil) goto v_20250;
    else goto v_20251;
v_20250:
    v_20405 = stack[-2];
    goto v_20230;
v_20251:
    goto v_20259;
v_20255:
    stack[0] = stack[-1];
    goto v_20256;
v_20257:
    v_20405 = stack[-3];
    v_20405 = qcar(v_20405);
    v_20406 = v_20405;
    v_20405 = lisp_true;
    qvalue(elt(env, 11)) = v_20405; // !*sub2
    v_20405 = v_20406;
    fn = elt(env, 25); // subs2
    v_20405 = (*qfn1(fn))(fn, v_20405);
    env = stack[-10];
    v_20405 = ncons(v_20405);
    env = stack[-10];
    goto v_20258;
v_20259:
    goto v_20255;
v_20256:
    goto v_20257;
v_20258:
    v_20405 = Lrplacd(nil, stack[0], v_20405);
    env = stack[-10];
    v_20405 = stack[-1];
    v_20405 = qcdr(v_20405);
    stack[-1] = v_20405;
    goto v_20231;
v_20230:
    v_20405 = ncons(v_20405);
    env = stack[-10];
    stack[-5] = v_20405;
    stack[-6] = v_20405;
v_20214:
    v_20405 = stack[-7];
    v_20405 = qcdr(v_20405);
    stack[-7] = v_20405;
    v_20405 = stack[-7];
    if (v_20405 == nil) goto v_20274;
    else goto v_20275;
v_20274:
    v_20405 = stack[-6];
    goto v_20213;
v_20275:
    goto v_20283;
v_20279:
    stack[-4] = stack[-5];
    goto v_20280;
v_20281:
    v_20405 = stack[-7];
    v_20405 = qcar(v_20405);
    stack[-3] = v_20405;
    v_20405 = stack[-3];
    if (v_20405 == nil) goto v_20298;
    else goto v_20299;
v_20298:
    v_20405 = nil;
    goto v_20293;
v_20299:
    v_20405 = stack[-3];
    v_20405 = qcar(v_20405);
    v_20406 = v_20405;
    v_20405 = lisp_true;
    qvalue(elt(env, 11)) = v_20405; // !*sub2
    v_20405 = v_20406;
    fn = elt(env, 25); // subs2
    v_20405 = (*qfn1(fn))(fn, v_20405);
    env = stack[-10];
    v_20405 = ncons(v_20405);
    env = stack[-10];
    stack[-1] = v_20405;
    stack[-2] = v_20405;
v_20294:
    v_20405 = stack[-3];
    v_20405 = qcdr(v_20405);
    stack[-3] = v_20405;
    v_20405 = stack[-3];
    if (v_20405 == nil) goto v_20313;
    else goto v_20314;
v_20313:
    v_20405 = stack[-2];
    goto v_20293;
v_20314:
    goto v_20322;
v_20318:
    stack[0] = stack[-1];
    goto v_20319;
v_20320:
    v_20405 = stack[-3];
    v_20405 = qcar(v_20405);
    v_20406 = v_20405;
    v_20405 = lisp_true;
    qvalue(elt(env, 11)) = v_20405; // !*sub2
    v_20405 = v_20406;
    fn = elt(env, 25); // subs2
    v_20405 = (*qfn1(fn))(fn, v_20405);
    env = stack[-10];
    v_20405 = ncons(v_20405);
    env = stack[-10];
    goto v_20321;
v_20322:
    goto v_20318;
v_20319:
    goto v_20320;
v_20321:
    v_20405 = Lrplacd(nil, stack[0], v_20405);
    env = stack[-10];
    v_20405 = stack[-1];
    v_20405 = qcdr(v_20405);
    stack[-1] = v_20405;
    goto v_20294;
v_20293:
    v_20405 = ncons(v_20405);
    env = stack[-10];
    goto v_20282;
v_20283:
    goto v_20279;
v_20280:
    goto v_20281;
v_20282:
    v_20405 = Lrplacd(nil, stack[-4], v_20405);
    env = stack[-10];
    v_20405 = stack[-5];
    v_20405 = qcdr(v_20405);
    stack[-5] = v_20405;
    goto v_20214;
v_20213:
    stack[-9] = v_20405;
    goto v_20194;
v_20194:
    goto v_19559;
v_19562:
    v_20405 = stack[-2];
    v_20405 = qcar(v_20405);
    v_20405 = qcar(v_20405);
    v_20405 = qcar(v_20405);
    if (v_20405 == nil) goto v_20337;
    else goto v_20338;
v_20337:
    goto v_20350;
v_20344:
    v_20407 = elt(env, 4); // matrix
    goto v_20345;
v_20346:
    v_20406 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_20347;
v_20348:
    v_20405 = elt(env, 12); // "Zero divisor"
    goto v_20349;
v_20350:
    goto v_20344;
v_20345:
    goto v_20346;
v_20347:
    goto v_20348;
v_20349:
    fn = elt(env, 20); // rerror
    v_20405 = (*qfnn(fn))(fn, 3, v_20407, v_20406, v_20405);
    env = stack[-10];
    goto v_20336;
v_20338:
v_20336:
    v_20405 = stack[-2];
    v_20405 = qcar(v_20405);
    v_20405 = qcar(v_20405);
    fn = elt(env, 26); // revpr
    v_20405 = (*qfn1(fn))(fn, v_20405);
    env = stack[-10];
    stack[-2] = v_20405;
    v_20405 = stack[-9];
    if (v_20405 == nil) goto v_20360;
    else goto v_20361;
v_20360:
    v_20405 = stack[-2];
    v_20405 = ncons(v_20405);
    env = stack[-10];
    v_20405 = ncons(v_20405);
    env = stack[-10];
    goto v_20359;
v_20361:
    goto v_20373;
v_20369:
    v_20406 = stack[-2];
    goto v_20370;
v_20371:
    v_20405 = stack[-9];
    goto v_20372;
v_20373:
    goto v_20369;
v_20370:
    goto v_20371;
v_20372:
    fn = elt(env, 17); // multsm
    v_20405 = (*qfn2(fn))(fn, v_20406, v_20405);
    env = stack[-10];
    goto v_20359;
    v_20405 = nil;
v_20359:
    stack[-9] = v_20405;
    goto v_19559;
v_19563:
    v_20405 = stack[-9];
    if (v_20405 == nil) goto v_20378;
    else goto v_20379;
v_20378:
    v_20405 = stack[-1];
    fn = elt(env, 27); // generateident
    v_20405 = (*qfn1(fn))(fn, v_20405);
    env = stack[-10];
    stack[-9] = v_20405;
    goto v_20377;
v_20379:
v_20377:
    goto v_19559;
v_19564:
    goto v_20390;
v_20384:
    stack[-1] = elt(env, 4); // matrix
    goto v_20385;
v_20386:
    stack[0] = (LispObject)112+TAG_FIXNUM; // 7
    goto v_20387;
v_20388:
    goto v_20400;
v_20394:
    v_20407 = elt(env, 13); // "Matrix"
    goto v_20395;
v_20396:
    v_20405 = stack[-8];
    v_20406 = qcar(v_20405);
    goto v_20397;
v_20398:
    v_20405 = elt(env, 14); // "not set"
    goto v_20399;
v_20400:
    goto v_20394;
v_20395:
    goto v_20396;
v_20397:
    goto v_20398;
v_20399:
    v_20405 = list3(v_20407, v_20406, v_20405);
    env = stack[-10];
    goto v_20389;
v_20390:
    goto v_20384;
v_20385:
    goto v_20386;
v_20387:
    goto v_20388;
v_20389:
    fn = elt(env, 20); // rerror
    v_20405 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_20405);
    v_20405 = nil;
v_19556:
    return onevalue(v_20405);
}



// Code for recaliasbacksubst

static LispObject CC_recaliasbacksubst(LispObject env,
                         LispObject v_19548, LispObject v_19549)
{
    env = qenv(env);
    LispObject v_19645, v_19646;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19549,v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19548,v_19549);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_19549;
    stack[0] = v_19548;
// end of prologue
    v_19645 = stack[0];
    if (!consp(v_19645)) goto v_19557;
    else goto v_19558;
v_19557:
    v_19645 = lisp_true;
    goto v_19556;
v_19558:
    v_19645 = stack[0];
    fn = elt(env, 1); // constp
    v_19645 = (*qfn1(fn))(fn, v_19645);
    env = stack[-5];
    goto v_19556;
    v_19645 = nil;
v_19556:
    if (v_19645 == nil) goto v_19554;
    goto v_19573;
v_19569:
    v_19646 = stack[0];
    goto v_19570;
v_19571:
    v_19645 = stack[-3];
    goto v_19572;
v_19573:
    goto v_19569;
v_19570:
    goto v_19571;
v_19572:
    v_19645 = Lassoc(nil, v_19646, v_19645);
    if (v_19645 == nil) goto v_19568;
    goto v_19581;
v_19577:
    v_19646 = stack[0];
    goto v_19578;
v_19579:
    v_19645 = stack[-3];
    goto v_19580;
v_19581:
    goto v_19577;
v_19578:
    goto v_19579;
v_19580:
    v_19645 = Lassoc(nil, v_19646, v_19645);
    v_19645 = qcdr(v_19645);
    goto v_19566;
v_19568:
    v_19645 = stack[0];
    goto v_19566;
    v_19645 = nil;
v_19566:
    goto v_19552;
v_19554:
    v_19645 = stack[0];
    stack[-4] = v_19645;
    v_19645 = stack[-4];
    if (v_19645 == nil) goto v_19600;
    else goto v_19601;
v_19600:
    v_19645 = nil;
    goto v_19595;
v_19601:
    v_19645 = stack[-4];
    v_19645 = qcar(v_19645);
    goto v_19613;
v_19609:
    v_19646 = v_19645;
    goto v_19610;
v_19611:
    v_19645 = stack[-3];
    goto v_19612;
v_19613:
    goto v_19609;
v_19610:
    goto v_19611;
v_19612:
    v_19645 = CC_recaliasbacksubst(elt(env, 0), v_19646, v_19645);
    env = stack[-5];
    v_19645 = ncons(v_19645);
    env = stack[-5];
    stack[-1] = v_19645;
    stack[-2] = v_19645;
v_19596:
    v_19645 = stack[-4];
    v_19645 = qcdr(v_19645);
    stack[-4] = v_19645;
    v_19645 = stack[-4];
    if (v_19645 == nil) goto v_19620;
    else goto v_19621;
v_19620:
    v_19645 = stack[-2];
    goto v_19595;
v_19621:
    goto v_19629;
v_19625:
    stack[0] = stack[-1];
    goto v_19626;
v_19627:
    v_19645 = stack[-4];
    v_19645 = qcar(v_19645);
    goto v_19640;
v_19636:
    v_19646 = v_19645;
    goto v_19637;
v_19638:
    v_19645 = stack[-3];
    goto v_19639;
v_19640:
    goto v_19636;
v_19637:
    goto v_19638;
v_19639:
    v_19645 = CC_recaliasbacksubst(elt(env, 0), v_19646, v_19645);
    env = stack[-5];
    v_19645 = ncons(v_19645);
    env = stack[-5];
    goto v_19628;
v_19629:
    goto v_19625;
v_19626:
    goto v_19627;
v_19628:
    v_19645 = Lrplacd(nil, stack[0], v_19645);
    env = stack[-5];
    v_19645 = stack[-1];
    v_19645 = qcdr(v_19645);
    stack[-1] = v_19645;
    goto v_19596;
v_19595:
    goto v_19552;
    v_19645 = nil;
v_19552:
    return onevalue(v_19645);
}



// Code for amatch

static LispObject CC_amatch(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_19681, v_19682, v_19683, v_19684;
    LispObject fn;
    LispObject v_19553, v_19552, v_19551, v_19550;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "amatch");
    va_start(aa, nargs);
    v_19550 = va_arg(aa, LispObject);
    v_19551 = va_arg(aa, LispObject);
    v_19552 = va_arg(aa, LispObject);
    v_19553 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_19553,v_19552,v_19551,v_19550);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_19550,v_19551,v_19552,v_19553);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_19553;
    stack[-4] = v_19552;
    v_19682 = v_19551;
    v_19681 = v_19550;
// end of prologue
// Binding r
// FLUIDBIND: reloadenv=6 litvec-offset=1 saveloc=5
{   bind_fluid_stack bind_fluid_var(-6, 1, -5);
// Binding p
// FLUIDBIND: reloadenv=6 litvec-offset=2 saveloc=2
{   bind_fluid_stack bind_fluid_var(-6, 2, -2);
    qvalue(elt(env, 1)) = v_19681; // r
    v_19681 = v_19682;
    qvalue(elt(env, 2)) = v_19681; // p
v_19564:
    v_19681 = qvalue(elt(env, 1)); // r
    if (!consp(v_19681)) goto v_19567;
    else goto v_19568;
v_19567:
    goto v_19581;
v_19571:
    stack[-1] = nil;
    goto v_19572;
v_19573:
    v_19681 = qvalue(elt(env, 1)); // r
    v_19681 = ncons(v_19681);
    env = stack[-6];
    fn = elt(env, 5); // mval
    stack[0] = (*qfn1(fn))(fn, v_19681);
    env = stack[-6];
    goto v_19574;
v_19575:
    v_19681 = qvalue(elt(env, 2)); // p
    v_19683 = ncons(v_19681);
    env = stack[-6];
    goto v_19576;
v_19577:
    v_19682 = stack[-4];
    goto v_19578;
v_19579:
    v_19681 = stack[-3];
    goto v_19580;
v_19581:
    goto v_19571;
v_19572:
    goto v_19573;
v_19574:
    goto v_19575;
v_19576:
    goto v_19577;
v_19578:
    goto v_19579;
v_19580:
    fn = elt(env, 6); // unify
    v_19681 = (*qfnn(fn))(fn, 5, stack[-1], stack[0], v_19683, v_19682, v_19681);
    goto v_19563;
v_19568:
    v_19681 = qvalue(elt(env, 2)); // p
    if (!consp(v_19681)) goto v_19594;
    else goto v_19595;
v_19594:
    v_19681 = lisp_true;
    goto v_19593;
v_19595:
    goto v_19605;
v_19601:
    v_19681 = qvalue(elt(env, 1)); // r
    v_19682 = qcar(v_19681);
    goto v_19602;
v_19603:
    v_19681 = qvalue(elt(env, 2)); // p
    v_19681 = qcar(v_19681);
    goto v_19604;
v_19605:
    goto v_19601;
v_19602:
    goto v_19603;
v_19604:
    v_19681 = Lneq(nil, v_19682, v_19681);
    env = stack[-6];
    goto v_19593;
    v_19681 = nil;
v_19593:
    if (v_19681 == nil) goto v_19590;
    else goto v_19591;
v_19590:
    goto v_19621;
v_19611:
    v_19681 = qvalue(elt(env, 1)); // r
    stack[0] = qcar(v_19681);
    goto v_19612;
v_19613:
    v_19681 = qvalue(elt(env, 1)); // r
    v_19681 = qcdr(v_19681);
    fn = elt(env, 5); // mval
    v_19684 = (*qfn1(fn))(fn, v_19681);
    env = stack[-6];
    goto v_19614;
v_19615:
    v_19681 = qvalue(elt(env, 2)); // p
    v_19683 = qcdr(v_19681);
    goto v_19616;
v_19617:
    v_19682 = stack[-4];
    goto v_19618;
v_19619:
    v_19681 = stack[-3];
    goto v_19620;
v_19621:
    goto v_19611;
v_19612:
    goto v_19613;
v_19614:
    goto v_19615;
v_19616:
    goto v_19617;
v_19618:
    goto v_19619;
v_19620:
    fn = elt(env, 6); // unify
    v_19681 = (*qfnn(fn))(fn, 5, stack[0], v_19684, v_19683, v_19682, v_19681);
    goto v_19563;
v_19591:
    v_19681 = qvalue(elt(env, 1)); // r
    fn = elt(env, 7); // suchp
    v_19681 = (*qfn1(fn))(fn, v_19681);
    env = stack[-6];
    if (v_19681 == nil) goto v_19632;
    v_19681 = qvalue(elt(env, 1)); // r
    v_19681 = qcdr(v_19681);
    v_19681 = qcar(v_19681);
    stack[0] = v_19681;
    goto v_19643;
v_19639:
    v_19681 = qvalue(elt(env, 1)); // r
    v_19681 = qcdr(v_19681);
    v_19681 = qcdr(v_19681);
    v_19682 = qcar(v_19681);
    goto v_19640;
v_19641:
    v_19681 = stack[-4];
    goto v_19642;
v_19643:
    goto v_19639;
v_19640:
    goto v_19641;
v_19642:
    v_19681 = cons(v_19682, v_19681);
    env = stack[-6];
    stack[-4] = v_19681;
    v_19681 = stack[0];
    qvalue(elt(env, 1)) = v_19681; // r
    goto v_19564;
v_19632:
    v_19681 = qvalue(elt(env, 3)); // !*semantic
    if (v_19681 == nil) goto v_19651;
    goto v_19658;
v_19654:
    goto v_19664;
v_19660:
    goto v_19672;
v_19666:
    v_19683 = elt(env, 4); // equal
    goto v_19667;
v_19668:
    v_19682 = qvalue(elt(env, 1)); // r
    goto v_19669;
v_19670:
    v_19681 = qvalue(elt(env, 2)); // p
    goto v_19671;
v_19672:
    goto v_19666;
v_19667:
    goto v_19668;
v_19669:
    goto v_19670;
v_19671:
    v_19682 = list3(v_19683, v_19682, v_19681);
    env = stack[-6];
    goto v_19661;
v_19662:
    v_19681 = stack[-4];
    goto v_19663;
v_19664:
    goto v_19660;
v_19661:
    goto v_19662;
v_19663:
    v_19682 = cons(v_19682, v_19681);
    env = stack[-6];
    goto v_19655;
v_19656:
    v_19681 = stack[-3];
    goto v_19657;
v_19658:
    goto v_19654;
v_19655:
    goto v_19656;
v_19657:
    fn = elt(env, 8); // resume
    v_19681 = (*qfn2(fn))(fn, v_19682, v_19681);
    goto v_19563;
v_19651:
    v_19681 = nil;
    goto v_19563;
    v_19681 = nil;
v_19563:
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_19681);
}



// Code for fieldp

static LispObject CC_fieldp(LispObject env,
                         LispObject v_19548)
{
    env = qenv(env);
    LispObject v_19561, v_19562;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_19561 = v_19548;
// end of prologue
    v_19562 = v_19561;
    if (!consp(v_19562)) goto v_19553;
    v_19561 = qcar(v_19561);
    if (!symbolp(v_19561)) v_19561 = nil;
    else { v_19561 = qfastgets(v_19561);
           if (v_19561 != nil) { v_19561 = elt(v_19561, 3); // field
#ifdef RECORD_GET
             if (v_19561 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_19561 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_19561 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_19561 == SPID_NOPROP) v_19561 = nil; else v_19561 = lisp_true; }}
#endif
    goto v_19551;
v_19553:
    v_19561 = nil;
    goto v_19551;
    v_19561 = nil;
v_19551:
    return onevalue(v_19561);
}



// Code for po!:statep

static LispObject CC_poTstatep(LispObject env,
                         LispObject v_19548)
{
    env = qenv(env);
    LispObject v_19597, v_19598, v_19599;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_19599 = v_19548;
// end of prologue
    v_19597 = v_19599;
    if (symbolp(v_19597)) goto v_19556;
    v_19597 = nil;
    goto v_19554;
v_19556:
    goto v_19565;
v_19561:
    v_19597 = v_19599;
    if (!symbolp(v_19597)) v_19598 = nil;
    else { v_19598 = qfastgets(v_19597);
           if (v_19598 != nil) { v_19598 = elt(v_19598, 18); // phystype
#ifdef RECORD_GET
             if (v_19598 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v_19598 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v_19598 == SPID_NOPROP) v_19598 = nil; }}
#endif
    goto v_19562;
v_19563:
    v_19597 = elt(env, 1); // state
    goto v_19564;
v_19565:
    goto v_19561;
v_19562:
    goto v_19563;
v_19564:
    v_19597 = (v_19598 == v_19597 ? lisp_true : nil);
    goto v_19554;
    v_19597 = nil;
v_19554:
    if (v_19597 == nil) goto v_19552;
    else goto v_19551;
v_19552:
    v_19597 = v_19599;
    if (!consp(v_19597)) goto v_19573;
    v_19597 = v_19599;
    v_19597 = qcar(v_19597);
    if (symbolp(v_19597)) goto v_19578;
    v_19597 = nil;
    goto v_19576;
v_19578:
    goto v_19588;
v_19584:
    v_19597 = v_19599;
    v_19597 = qcar(v_19597);
    if (!symbolp(v_19597)) v_19597 = nil;
    else { v_19597 = qfastgets(v_19597);
           if (v_19597 != nil) { v_19597 = elt(v_19597, 18); // phystype
#ifdef RECORD_GET
             if (v_19597 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v_19597 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v_19597 == SPID_NOPROP) v_19597 = nil; }}
#endif
    goto v_19585;
v_19586:
    v_19598 = elt(env, 1); // state
    goto v_19587;
v_19588:
    goto v_19584;
v_19585:
    goto v_19586;
v_19587:
    v_19597 = (v_19597 == v_19598 ? lisp_true : nil);
    goto v_19576;
    v_19597 = nil;
v_19576:
    goto v_19571;
v_19573:
    v_19597 = nil;
    goto v_19571;
    v_19597 = nil;
v_19571:
v_19551:
    return onevalue(v_19597);
}



// Code for color!-roads

static LispObject CC_colorKroads(LispObject env,
                         LispObject v_19548, LispObject v_19549)
{
    env = qenv(env);
    LispObject v_19677, v_19678, v_19679;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19549,v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19548,v_19549);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_19549;
    v_19679 = v_19548;
// end of prologue
    goto v_19561;
v_19557:
    v_19677 = stack[-4];
    v_19677 = qcar(v_19677);
    v_19678 = qcar(v_19677);
    goto v_19558;
v_19559:
    v_19677 = v_19679;
    goto v_19560;
v_19561:
    goto v_19557;
v_19558:
    goto v_19559;
v_19560:
    v_19677 = Lassoc(nil, v_19678, v_19677);
    v_19677 = qcdr(v_19677);
    stack[-1] = v_19677;
    goto v_19572;
v_19568:
    v_19677 = stack[-4];
    v_19677 = qcdr(v_19677);
    v_19677 = qcar(v_19677);
    v_19678 = qcar(v_19677);
    goto v_19569;
v_19570:
    v_19677 = v_19679;
    goto v_19571;
v_19572:
    goto v_19568;
v_19569:
    goto v_19570;
v_19571:
    v_19677 = Lassoc(nil, v_19678, v_19677);
    v_19677 = qcdr(v_19677);
    stack[0] = v_19677;
    goto v_19584;
v_19580:
    v_19677 = stack[-4];
    v_19677 = qcdr(v_19677);
    v_19677 = qcdr(v_19677);
    v_19677 = qcar(v_19677);
    v_19677 = qcar(v_19677);
    goto v_19581;
v_19582:
    v_19678 = v_19679;
    goto v_19583;
v_19584:
    goto v_19580;
v_19581:
    goto v_19582;
v_19583:
    v_19677 = Lassoc(nil, v_19677, v_19678);
    v_19677 = qcdr(v_19677);
    stack[-5] = v_19677;
    goto v_19598;
v_19594:
    goto v_19604;
v_19600:
    stack[-2] = stack[-1];
    goto v_19601;
v_19602:
    goto v_19611;
v_19607:
    v_19678 = stack[0];
    goto v_19608;
v_19609:
    v_19677 = stack[-5];
    goto v_19610;
v_19611:
    goto v_19607;
v_19608:
    goto v_19609;
v_19610:
    v_19677 = plus2(v_19678, v_19677);
    env = stack[-6];
    goto v_19603;
v_19604:
    goto v_19600;
v_19601:
    goto v_19602;
v_19603:
    v_19678 = plus2(stack[-2], v_19677);
    env = stack[-6];
    goto v_19595;
v_19596:
    v_19677 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_19597;
v_19598:
    goto v_19594;
v_19595:
    goto v_19596;
v_19597:
    v_19677 = quot2(v_19678, v_19677);
    env = stack[-6];
    stack[-2] = v_19677;
    goto v_19620;
v_19616:
    v_19678 = stack[-2];
    goto v_19617;
v_19618:
    v_19677 = stack[-1];
    goto v_19619;
v_19620:
    goto v_19616;
v_19617:
    goto v_19618;
v_19619:
    v_19677 = difference2(v_19678, v_19677);
    env = stack[-6];
    stack[-1] = v_19677;
    goto v_19628;
v_19624:
    v_19678 = stack[-2];
    goto v_19625;
v_19626:
    v_19677 = stack[0];
    goto v_19627;
v_19628:
    goto v_19624;
v_19625:
    goto v_19626;
v_19627:
    v_19677 = difference2(v_19678, v_19677);
    env = stack[-6];
    stack[0] = v_19677;
    goto v_19636;
v_19632:
    v_19678 = stack[-2];
    goto v_19633;
v_19634:
    v_19677 = stack[-5];
    goto v_19635;
v_19636:
    goto v_19632;
v_19633:
    goto v_19634;
v_19635:
    v_19677 = difference2(v_19678, v_19677);
    env = stack[-6];
    stack[-5] = v_19677;
    goto v_19646;
v_19640:
    v_19677 = stack[-4];
    v_19677 = qcar(v_19677);
    stack[-3] = qcar(v_19677);
    goto v_19641;
v_19642:
    stack[-2] = stack[-1];
    goto v_19643;
v_19644:
    goto v_19658;
v_19652:
    v_19677 = stack[-4];
    v_19677 = qcdr(v_19677);
    v_19677 = qcar(v_19677);
    stack[-1] = qcar(v_19677);
    goto v_19653;
v_19654:
    goto v_19655;
v_19656:
    goto v_19670;
v_19666:
    v_19677 = stack[-4];
    v_19677 = qcdr(v_19677);
    v_19677 = qcdr(v_19677);
    v_19677 = qcar(v_19677);
    v_19678 = qcar(v_19677);
    goto v_19667;
v_19668:
    v_19677 = stack[-5];
    goto v_19669;
v_19670:
    goto v_19666;
v_19667:
    goto v_19668;
v_19669:
    v_19677 = cons(v_19678, v_19677);
    env = stack[-6];
    v_19677 = ncons(v_19677);
    env = stack[-6];
    goto v_19657;
v_19658:
    goto v_19652;
v_19653:
    goto v_19654;
v_19655:
    goto v_19656;
v_19657:
    v_19677 = acons(stack[-1], stack[0], v_19677);
    goto v_19645;
v_19646:
    goto v_19640;
v_19641:
    goto v_19642;
v_19643:
    goto v_19644;
v_19645:
    {
        LispObject v_19686 = stack[-3];
        LispObject v_19687 = stack[-2];
        return acons(v_19686, v_19687, v_19677);
    }
    return onevalue(v_19677);
}



// Code for realvaluedp

static LispObject CC_realvaluedp(LispObject env,
                         LispObject v_19548)
{
    env = qenv(env);
    LispObject v_19618, v_19619, v_19620;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19548);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_19619 = v_19548;
// end of prologue
    v_19618 = v_19619;
    if (!consp(v_19618)) goto v_19552;
    else goto v_19553;
v_19552:
    v_19618 = v_19619;
    v_19618 = (is_number(v_19618) ? lisp_true : nil);
    if (v_19618 == nil) goto v_19557;
    else goto v_19556;
v_19557:
    goto v_19565;
v_19561:
    v_19618 = v_19619;
    goto v_19562;
v_19563:
    v_19619 = elt(env, 1); // realvalued
    goto v_19564;
v_19565:
    goto v_19561;
v_19562:
    goto v_19563;
v_19564:
        return Lflagp(nil, v_19618, v_19619);
v_19556:
    goto v_19551;
v_19553:
    goto v_19582;
v_19578:
    v_19618 = v_19619;
    v_19620 = qcar(v_19618);
    stack[0] = v_19620;
    goto v_19579;
v_19580:
    v_19618 = elt(env, 2); // alwaysrealvalued
    goto v_19581;
v_19582:
    goto v_19578;
v_19579:
    goto v_19580;
v_19581:
    v_19618 = Lflagp(nil, v_19620, v_19618);
    env = stack[-1];
    if (v_19618 == nil) goto v_19576;
    v_19618 = lisp_true;
    goto v_19574;
v_19576:
    goto v_19601;
v_19597:
    v_19620 = stack[0];
    goto v_19598;
v_19599:
    v_19618 = elt(env, 1); // realvalued
    goto v_19600;
v_19601:
    goto v_19597;
v_19598:
    goto v_19599;
v_19600:
    v_19618 = Lflagp(nil, v_19620, v_19618);
    env = stack[-1];
    if (v_19618 == nil) goto v_19595;
    v_19618 = v_19619;
    v_19618 = qcdr(v_19618);
    fn = elt(env, 4); // realvaluedlist
    v_19618 = (*qfn1(fn))(fn, v_19618);
    env = stack[-1];
    goto v_19593;
v_19595:
    v_19618 = nil;
    goto v_19593;
    v_19618 = nil;
v_19593:
    if (v_19618 == nil) goto v_19591;
    else goto v_19590;
v_19591:
    goto v_19614;
v_19610:
    v_19618 = stack[0];
    goto v_19611;
v_19612:
    v_19619 = elt(env, 3); // !:rd!:
    goto v_19613;
v_19614:
    goto v_19610;
v_19611:
    goto v_19612;
v_19613:
    v_19618 = (v_19618 == v_19619 ? lisp_true : nil);
v_19590:
    goto v_19574;
    v_19618 = nil;
v_19574:
    goto v_19551;
    v_19618 = nil;
v_19551:
    return onevalue(v_19618);
}



// Code for greaterpcdr

static LispObject CC_greaterpcdr(LispObject env,
                         LispObject v_19548, LispObject v_19549)
{
    env = qenv(env);
    LispObject v_19561, v_19562;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_19561 = v_19549;
    v_19562 = v_19548;
// end of prologue
    goto v_19556;
v_19552:
    v_19562 = qcdr(v_19562);
    goto v_19553;
v_19554:
    v_19561 = qcdr(v_19561);
    goto v_19555;
v_19556:
    goto v_19552;
v_19553:
    goto v_19554;
v_19555:
        return Lgreaterp(nil, v_19562, v_19561);
}



// Code for subs2chk

static LispObject CC_subs2chk(LispObject env,
                         LispObject v_19548)
{
    env = qenv(env);
    LispObject v_19572, v_19573, v_19574;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19548);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_19548;
// end of prologue
    v_19572 = qvalue(elt(env, 1)); // subfg!*
    if (v_19572 == nil) goto v_19556;
    goto v_19564;
v_19560:
    v_19572 = stack[0];
    fn = elt(env, 2); // subs2f
    v_19572 = (*qfn1(fn))(fn, v_19572);
    v_19574 = v_19572;
    v_19573 = qcdr(v_19572);
    goto v_19561;
v_19562:
    v_19572 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19563;
v_19564:
    goto v_19560;
v_19561:
    goto v_19562;
v_19563:
    if (v_19573 == v_19572) goto v_19559;
    else goto v_19556;
v_19559:
    v_19572 = v_19574;
    v_19572 = qcar(v_19572);
    stack[0] = v_19572;
    goto v_19554;
v_19556:
v_19554:
    v_19572 = stack[0];
    return onevalue(v_19572);
}



// Code for fs!:prin

static LispObject CC_fsTprin(LispObject env,
                         LispObject v_19548)
{
    env = qenv(env);
    LispObject v_19585, v_19586;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19548);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_19548;
// end of prologue
    v_19585 = stack[0];
    if (v_19585 == nil) goto v_19552;
    else goto v_19553;
v_19552:
    v_19585 = elt(env, 1); // " 0 "
    {
        fn = elt(env, 3); // prin2!*
        return (*qfn1(fn))(fn, v_19585);
    }
v_19553:
v_19561:
    v_19585 = stack[0];
    if (v_19585 == nil) goto v_19564;
    else goto v_19565;
v_19564:
    v_19585 = nil;
    goto v_19560;
v_19565:
    v_19585 = stack[0];
    fn = elt(env, 4); // fs!:prin1
    v_19585 = (*qfn1(fn))(fn, v_19585);
    env = stack[-1];
    goto v_19574;
v_19570:
    v_19586 = stack[0];
    goto v_19571;
v_19572:
    v_19585 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_19573;
v_19574:
    goto v_19570;
v_19571:
    goto v_19572;
v_19573:
    v_19585 = *(LispObject *)((char *)v_19586 + (CELL-TAG_VECTOR) + (((intptr_t)v_19585-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_19585;
    v_19585 = stack[0];
    if (v_19585 == nil) goto v_19581;
    v_19585 = elt(env, 2); // " + "
    fn = elt(env, 3); // prin2!*
    v_19585 = (*qfn1(fn))(fn, v_19585);
    env = stack[-1];
    goto v_19579;
v_19581:
v_19579:
    goto v_19561;
v_19560:
    goto v_19551;
    v_19585 = nil;
v_19551:
    return onevalue(v_19585);
}



// Code for mo_zero!?

static LispObject CC_mo_zeroW(LispObject env,
                         LispObject v_19548)
{
    env = qenv(env);
    LispObject v_19553;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_19553 = v_19548;
// end of prologue
    v_19553 = qcar(v_19553);
    {
        fn = elt(env, 1); // mo!=zero
        return (*qfn1(fn))(fn, v_19553);
    }
}



// Code for dv_ind2var

static LispObject CC_dv_ind2var(LispObject env,
                         LispObject v_19548)
{
    env = qenv(env);
    LispObject v_19582, v_19583;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19548);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_19548;
// end of prologue
    goto v_19559;
v_19555:
    stack[-1] = stack[0];
    goto v_19556;
v_19557:
    v_19582 = qvalue(elt(env, 1)); // g_dvnames
    fn = elt(env, 3); // upbve
    v_19582 = (*qfn1(fn))(fn, v_19582);
    env = stack[-2];
    goto v_19558;
v_19559:
    goto v_19555;
v_19556:
    goto v_19557;
v_19558:
    v_19582 = (LispObject)lesseq2(stack[-1], v_19582);
    v_19582 = v_19582 ? lisp_true : nil;
    env = stack[-2];
    if (v_19582 == nil) goto v_19553;
    goto v_19567;
v_19563:
    stack[-1] = qvalue(elt(env, 1)); // g_dvnames
    goto v_19564;
v_19565:
    v_19582 = stack[0];
    v_19582 = sub1(v_19582);
    goto v_19566;
v_19567:
    goto v_19563;
v_19564:
    goto v_19565;
v_19566:
    v_19582 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)v_19582-TAG_FIXNUM)/(16/CELL)));
    goto v_19551;
v_19553:
    goto v_19579;
v_19575:
    v_19583 = qvalue(elt(env, 2)); // g_dvbase
    goto v_19576;
v_19577:
    v_19582 = stack[0];
    goto v_19578;
v_19579:
    goto v_19575;
v_19576:
    goto v_19577;
v_19578:
    {
        fn = elt(env, 4); // mkid
        return (*qfn2(fn))(fn, v_19583, v_19582);
    }
    v_19582 = nil;
v_19551:
    return onevalue(v_19582);
}



// Code for outer!-simpsqrt

static LispObject CC_outerKsimpsqrt(LispObject env,
                         LispObject v_19548)
{
    env = qenv(env);
    LispObject v_19561, v_19562;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_19562 = v_19548;
// end of prologue
    v_19561 = qvalue(elt(env, 1)); // !*inside!-int!*
    if (v_19561 == nil) goto v_19553;
    v_19561 = v_19562;
    {
        fn = elt(env, 2); // proper!-simpsqrt
        return (*qfn1(fn))(fn, v_19561);
    }
v_19553:
    v_19561 = v_19562;
    {
        fn = elt(env, 3); // simpsqrt
        return (*qfn1(fn))(fn, v_19561);
    }
    v_19561 = nil;
    return onevalue(v_19561);
}



// Code for msolve!-polyn

static LispObject CC_msolveKpolyn(LispObject env,
                         LispObject v_19548, LispObject v_19549)
{
    env = qenv(env);
    LispObject v_19797, v_19798, v_19799;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19549,v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19548,v_19549);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-8] = v_19549;
    stack[-9] = v_19548;
// end of prologue
    v_19797 = stack[-8];
    v_19797 = qcar(v_19797);
    stack[-10] = v_19797;
    v_19797 = stack[-8];
    v_19797 = qcdr(v_19797);
    if (v_19797 == nil) goto v_19556;
    else goto v_19557;
v_19556:
    goto v_19565;
v_19561:
    v_19798 = stack[-9];
    goto v_19562;
v_19563:
    v_19797 = stack[-8];
    v_19797 = qcar(v_19797);
    goto v_19564;
v_19565:
    goto v_19561;
v_19562:
    goto v_19563;
v_19564:
    {
        fn = elt(env, 2); // msolve!-poly1
        return (*qfn2(fn))(fn, v_19798, v_19797);
    }
v_19557:
    v_19797 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_19797;
v_19576:
    goto v_19589;
v_19585:
    v_19797 = qvalue(elt(env, 1)); // current!-modulus
    v_19798 = sub1(v_19797);
    env = stack[-11];
    goto v_19586;
v_19587:
    v_19797 = stack[-7];
    goto v_19588;
v_19589:
    goto v_19585;
v_19586:
    goto v_19587;
v_19588:
    v_19797 = difference2(v_19798, v_19797);
    env = stack[-11];
    v_19797 = Lminusp(nil, v_19797);
    env = stack[-11];
    if (v_19797 == nil) goto v_19582;
    v_19797 = nil;
    goto v_19575;
v_19582:
    goto v_19605;
v_19601:
    goto v_19611;
v_19607:
    stack[0] = stack[-9];
    goto v_19608;
v_19609:
    goto v_19619;
v_19615:
    v_19798 = stack[-10];
    goto v_19616;
v_19617:
    v_19797 = stack[-7];
    goto v_19618;
v_19619:
    goto v_19615;
v_19616:
    goto v_19617;
v_19618:
    v_19797 = cons(v_19798, v_19797);
    env = stack[-11];
    v_19797 = ncons(v_19797);
    env = stack[-11];
    goto v_19610;
v_19611:
    goto v_19607;
v_19608:
    goto v_19609;
v_19610:
    fn = elt(env, 3); // subf
    v_19797 = (*qfn2(fn))(fn, stack[0], v_19797);
    env = stack[-11];
    v_19798 = qcar(v_19797);
    goto v_19602;
v_19603:
    v_19797 = stack[-8];
    v_19797 = qcdr(v_19797);
    goto v_19604;
v_19605:
    goto v_19601;
v_19602:
    goto v_19603;
v_19604:
    v_19797 = CC_msolveKpolyn(elt(env, 0), v_19798, v_19797);
    env = stack[-11];
    stack[-3] = v_19797;
    v_19797 = stack[-3];
    if (v_19797 == nil) goto v_19627;
    else goto v_19628;
v_19627:
    v_19797 = nil;
    goto v_19598;
v_19628:
    v_19797 = stack[-3];
    v_19797 = qcar(v_19797);
    goto v_19642;
v_19636:
    v_19799 = stack[-10];
    goto v_19637;
v_19638:
    v_19798 = stack[-7];
    goto v_19639;
v_19640:
    goto v_19641;
v_19642:
    goto v_19636;
v_19637:
    goto v_19638;
v_19639:
    goto v_19640;
v_19641:
    v_19797 = acons(v_19799, v_19798, v_19797);
    env = stack[-11];
    v_19797 = ncons(v_19797);
    env = stack[-11];
    stack[-1] = v_19797;
    stack[-2] = v_19797;
v_19599:
    v_19797 = stack[-3];
    v_19797 = qcdr(v_19797);
    stack[-3] = v_19797;
    v_19797 = stack[-3];
    if (v_19797 == nil) goto v_19650;
    else goto v_19651;
v_19650:
    v_19797 = stack[-2];
    goto v_19598;
v_19651:
    goto v_19659;
v_19655:
    stack[0] = stack[-1];
    goto v_19656;
v_19657:
    v_19797 = stack[-3];
    v_19797 = qcar(v_19797);
    goto v_19672;
v_19666:
    v_19799 = stack[-10];
    goto v_19667;
v_19668:
    v_19798 = stack[-7];
    goto v_19669;
v_19670:
    goto v_19671;
v_19672:
    goto v_19666;
v_19667:
    goto v_19668;
v_19669:
    goto v_19670;
v_19671:
    v_19797 = acons(v_19799, v_19798, v_19797);
    env = stack[-11];
    v_19797 = ncons(v_19797);
    env = stack[-11];
    goto v_19658;
v_19659:
    goto v_19655;
v_19656:
    goto v_19657;
v_19658:
    v_19797 = Lrplacd(nil, stack[0], v_19797);
    env = stack[-11];
    v_19797 = stack[-1];
    v_19797 = qcdr(v_19797);
    stack[-1] = v_19797;
    goto v_19599;
v_19598:
    stack[-6] = v_19797;
    v_19797 = stack[-6];
    fn = elt(env, 4); // lastpair
    v_19797 = (*qfn1(fn))(fn, v_19797);
    env = stack[-11];
    stack[-5] = v_19797;
    v_19797 = stack[-7];
    v_19797 = add1(v_19797);
    env = stack[-11];
    stack[-7] = v_19797;
    v_19797 = stack[-5];
    if (!consp(v_19797)) goto v_19684;
    else goto v_19685;
v_19684:
    goto v_19576;
v_19685:
v_19577:
    goto v_19697;
v_19693:
    v_19797 = qvalue(elt(env, 1)); // current!-modulus
    v_19798 = sub1(v_19797);
    env = stack[-11];
    goto v_19694;
v_19695:
    v_19797 = stack[-7];
    goto v_19696;
v_19697:
    goto v_19693;
v_19694:
    goto v_19695;
v_19696:
    v_19797 = difference2(v_19798, v_19797);
    env = stack[-11];
    v_19797 = Lminusp(nil, v_19797);
    env = stack[-11];
    if (v_19797 == nil) goto v_19690;
    v_19797 = stack[-6];
    goto v_19575;
v_19690:
    goto v_19707;
v_19703:
    stack[-4] = stack[-5];
    goto v_19704;
v_19705:
    goto v_19720;
v_19716:
    goto v_19726;
v_19722:
    stack[0] = stack[-9];
    goto v_19723;
v_19724:
    goto v_19734;
v_19730:
    v_19798 = stack[-10];
    goto v_19731;
v_19732:
    v_19797 = stack[-7];
    goto v_19733;
v_19734:
    goto v_19730;
v_19731:
    goto v_19732;
v_19733:
    v_19797 = cons(v_19798, v_19797);
    env = stack[-11];
    v_19797 = ncons(v_19797);
    env = stack[-11];
    goto v_19725;
v_19726:
    goto v_19722;
v_19723:
    goto v_19724;
v_19725:
    fn = elt(env, 3); // subf
    v_19797 = (*qfn2(fn))(fn, stack[0], v_19797);
    env = stack[-11];
    v_19798 = qcar(v_19797);
    goto v_19717;
v_19718:
    v_19797 = stack[-8];
    v_19797 = qcdr(v_19797);
    goto v_19719;
v_19720:
    goto v_19716;
v_19717:
    goto v_19718;
v_19719:
    v_19797 = CC_msolveKpolyn(elt(env, 0), v_19798, v_19797);
    env = stack[-11];
    stack[-3] = v_19797;
    v_19797 = stack[-3];
    if (v_19797 == nil) goto v_19742;
    else goto v_19743;
v_19742:
    v_19797 = nil;
    goto v_19713;
v_19743:
    v_19797 = stack[-3];
    v_19797 = qcar(v_19797);
    goto v_19757;
v_19751:
    v_19799 = stack[-10];
    goto v_19752;
v_19753:
    v_19798 = stack[-7];
    goto v_19754;
v_19755:
    goto v_19756;
v_19757:
    goto v_19751;
v_19752:
    goto v_19753;
v_19754:
    goto v_19755;
v_19756:
    v_19797 = acons(v_19799, v_19798, v_19797);
    env = stack[-11];
    v_19797 = ncons(v_19797);
    env = stack[-11];
    stack[-1] = v_19797;
    stack[-2] = v_19797;
v_19714:
    v_19797 = stack[-3];
    v_19797 = qcdr(v_19797);
    stack[-3] = v_19797;
    v_19797 = stack[-3];
    if (v_19797 == nil) goto v_19765;
    else goto v_19766;
v_19765:
    v_19797 = stack[-2];
    goto v_19713;
v_19766:
    goto v_19774;
v_19770:
    stack[0] = stack[-1];
    goto v_19771;
v_19772:
    v_19797 = stack[-3];
    v_19797 = qcar(v_19797);
    goto v_19787;
v_19781:
    v_19799 = stack[-10];
    goto v_19782;
v_19783:
    v_19798 = stack[-7];
    goto v_19784;
v_19785:
    goto v_19786;
v_19787:
    goto v_19781;
v_19782:
    goto v_19783;
v_19784:
    goto v_19785;
v_19786:
    v_19797 = acons(v_19799, v_19798, v_19797);
    env = stack[-11];
    v_19797 = ncons(v_19797);
    env = stack[-11];
    goto v_19773;
v_19774:
    goto v_19770;
v_19771:
    goto v_19772;
v_19773:
    v_19797 = Lrplacd(nil, stack[0], v_19797);
    env = stack[-11];
    v_19797 = stack[-1];
    v_19797 = qcdr(v_19797);
    stack[-1] = v_19797;
    goto v_19714;
v_19713:
    goto v_19706;
v_19707:
    goto v_19703;
v_19704:
    goto v_19705;
v_19706:
    v_19797 = Lrplacd(nil, stack[-4], v_19797);
    env = stack[-11];
    v_19797 = stack[-5];
    fn = elt(env, 4); // lastpair
    v_19797 = (*qfn1(fn))(fn, v_19797);
    env = stack[-11];
    stack[-5] = v_19797;
    v_19797 = stack[-7];
    v_19797 = add1(v_19797);
    env = stack[-11];
    stack[-7] = v_19797;
    goto v_19577;
v_19575:
    goto v_19555;
    v_19797 = nil;
v_19555:
    return onevalue(v_19797);
}



// Code for find!-null!-space

static LispObject CC_findKnullKspace(LispObject env,
                         LispObject v_19548, LispObject v_19549)
{
    env = qenv(env);
    LispObject v_19600, v_19601, v_19602, v_19603;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19549,v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19548,v_19549);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_19549;
    stack[-2] = v_19548;
// end of prologue
// Binding null!-space!-basis
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 1, -3);
    qvalue(elt(env, 1)) = nil; // null!-space!-basis
    v_19600 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_19600;
v_19557:
    goto v_19567;
v_19563:
    v_19601 = stack[-1];
    goto v_19564;
v_19565:
    v_19600 = stack[0];
    goto v_19566;
v_19567:
    goto v_19563;
v_19564:
    goto v_19565;
v_19566:
    v_19600 = (LispObject)(intptr_t)((intptr_t)v_19601 - (intptr_t)v_19600 + TAG_FIXNUM);
    v_19600 = ((intptr_t)(v_19600) < 0 ? lisp_true : nil);
    if (v_19600 == nil) goto v_19562;
    goto v_19556;
v_19562:
    goto v_19582;
v_19574:
    v_19603 = stack[0];
    goto v_19575;
v_19576:
    v_19602 = qvalue(elt(env, 1)); // null!-space!-basis
    goto v_19577;
v_19578:
    v_19601 = stack[-2];
    goto v_19579;
v_19580:
    v_19600 = stack[-1];
    goto v_19581;
v_19582:
    goto v_19574;
v_19575:
    goto v_19576;
v_19577:
    goto v_19578;
v_19579:
    goto v_19580;
v_19581:
    fn = elt(env, 2); // clear!-column
    v_19600 = (*qfnn(fn))(fn, 4, v_19603, v_19602, v_19601, v_19600);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_19600; // null!-space!-basis
    v_19600 = stack[0];
    v_19600 = (LispObject)((intptr_t)(v_19600) + 0x10);
    stack[0] = v_19600;
    goto v_19557;
v_19556:
    goto v_19596;
v_19590:
    v_19602 = qvalue(elt(env, 1)); // null!-space!-basis
    goto v_19591;
v_19592:
    v_19601 = stack[-2];
    goto v_19593;
v_19594:
    v_19600 = stack[-1];
    goto v_19595;
v_19596:
    goto v_19590;
v_19591:
    goto v_19592;
v_19593:
    goto v_19594;
v_19595:
    fn = elt(env, 3); // tidy!-up!-null!-vectors
    v_19600 = (*qfnn(fn))(fn, 3, v_19602, v_19601, v_19600);
    ;}  // end of a binding scope
    return onevalue(v_19600);
}



// Code for ofsf_ir2atl

static LispObject CC_ofsf_ir2atl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_19659, v_19660, v_19661;
    LispObject fn;
    LispObject v_19550, v_19549, v_19548;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_ir2atl");
    va_start(aa, nargs);
    v_19548 = va_arg(aa, LispObject);
    v_19549 = va_arg(aa, LispObject);
    v_19550 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_19550,v_19549,v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_19548,v_19549,v_19550);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_19550;
    stack[0] = v_19549;
    stack[-5] = v_19548;
// end of prologue
    goto v_19557;
v_19553:
    v_19659 = stack[0];
    v_19660 = qcar(v_19659);
    goto v_19554;
v_19555:
    v_19659 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19556;
v_19557:
    goto v_19553;
v_19554:
    goto v_19555;
v_19556:
    v_19659 = cons(v_19660, v_19659);
    env = stack[-7];
    stack[-6] = v_19659;
    v_19659 = stack[0];
    v_19659 = qcdr(v_19659);
    stack[-3] = v_19659;
v_19567:
    v_19659 = stack[-3];
    if (v_19659 == nil) goto v_19573;
    else goto v_19574;
v_19573:
    v_19659 = nil;
    goto v_19566;
v_19574:
    v_19659 = stack[-3];
    v_19659 = qcar(v_19659);
    v_19660 = v_19659;
    goto v_19588;
v_19584:
    v_19659 = v_19660;
    v_19661 = qcar(v_19659);
    goto v_19585;
v_19586:
    v_19659 = stack[-4];
    goto v_19587;
v_19588:
    goto v_19584;
v_19585:
    goto v_19586;
v_19587:
    if (equal(v_19661, v_19659)) goto v_19582;
    else goto v_19583;
v_19582:
    goto v_19600;
v_19594:
    v_19661 = stack[-5];
    goto v_19595;
v_19596:
    v_19659 = v_19660;
    v_19660 = qcdr(v_19659);
    goto v_19597;
v_19598:
    v_19659 = stack[-6];
    goto v_19599;
v_19600:
    goto v_19594;
v_19595:
    goto v_19596;
v_19597:
    goto v_19598;
v_19599:
    fn = elt(env, 1); // ofsf_entry2at
    v_19659 = (*qfnn(fn))(fn, 3, v_19661, v_19660, v_19659);
    env = stack[-7];
    v_19659 = ncons(v_19659);
    env = stack[-7];
    goto v_19581;
v_19583:
    v_19659 = nil;
v_19581:
    stack[-2] = v_19659;
    v_19659 = stack[-2];
    fn = elt(env, 2); // lastpair
    v_19659 = (*qfn1(fn))(fn, v_19659);
    env = stack[-7];
    stack[-1] = v_19659;
    v_19659 = stack[-3];
    v_19659 = qcdr(v_19659);
    stack[-3] = v_19659;
    v_19659 = stack[-1];
    if (!consp(v_19659)) goto v_19611;
    else goto v_19612;
v_19611:
    goto v_19567;
v_19612:
v_19568:
    v_19659 = stack[-3];
    if (v_19659 == nil) goto v_19616;
    else goto v_19617;
v_19616:
    v_19659 = stack[-2];
    goto v_19566;
v_19617:
    goto v_19625;
v_19621:
    stack[0] = stack[-1];
    goto v_19622;
v_19623:
    v_19659 = stack[-3];
    v_19659 = qcar(v_19659);
    v_19660 = v_19659;
    goto v_19638;
v_19634:
    v_19659 = v_19660;
    v_19661 = qcar(v_19659);
    goto v_19635;
v_19636:
    v_19659 = stack[-4];
    goto v_19637;
v_19638:
    goto v_19634;
v_19635:
    goto v_19636;
v_19637:
    if (equal(v_19661, v_19659)) goto v_19632;
    else goto v_19633;
v_19632:
    goto v_19650;
v_19644:
    v_19661 = stack[-5];
    goto v_19645;
v_19646:
    v_19659 = v_19660;
    v_19660 = qcdr(v_19659);
    goto v_19647;
v_19648:
    v_19659 = stack[-6];
    goto v_19649;
v_19650:
    goto v_19644;
v_19645:
    goto v_19646;
v_19647:
    goto v_19648;
v_19649:
    fn = elt(env, 1); // ofsf_entry2at
    v_19659 = (*qfnn(fn))(fn, 3, v_19661, v_19660, v_19659);
    env = stack[-7];
    v_19659 = ncons(v_19659);
    env = stack[-7];
    goto v_19631;
v_19633:
    v_19659 = nil;
v_19631:
    goto v_19624;
v_19625:
    goto v_19621;
v_19622:
    goto v_19623;
v_19624:
    v_19659 = Lrplacd(nil, stack[0], v_19659);
    env = stack[-7];
    v_19659 = stack[-1];
    fn = elt(env, 2); // lastpair
    v_19659 = (*qfn1(fn))(fn, v_19659);
    env = stack[-7];
    stack[-1] = v_19659;
    v_19659 = stack[-3];
    v_19659 = qcdr(v_19659);
    stack[-3] = v_19659;
    goto v_19568;
v_19566:
    return onevalue(v_19659);
}



// Code for plusdf

static LispObject CC_plusdf(LispObject env,
                         LispObject v_19548, LispObject v_19549)
{
    env = qenv(env);
    LispObject v_19683, v_19684, v_19685;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19549,v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19548,v_19549);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_19549;
    stack[-2] = v_19548;
// end of prologue
    stack[0] = nil;
v_19554:
    v_19683 = stack[-2];
    if (v_19683 == nil) goto v_19557;
    else goto v_19558;
v_19557:
    goto v_19565;
v_19561:
    v_19684 = stack[0];
    goto v_19562;
v_19563:
    v_19683 = stack[-1];
    goto v_19564;
v_19565:
    goto v_19561;
v_19562:
    goto v_19563;
v_19564:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_19684, v_19683);
    }
v_19558:
    v_19683 = stack[-1];
    if (v_19683 == nil) goto v_19568;
    else goto v_19569;
v_19568:
    goto v_19576;
v_19572:
    v_19684 = stack[0];
    goto v_19573;
v_19574:
    v_19683 = stack[-2];
    goto v_19575;
v_19576:
    goto v_19572;
v_19573:
    goto v_19574;
v_19575:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_19684, v_19683);
    }
v_19569:
    goto v_19585;
v_19581:
    v_19683 = stack[-2];
    v_19683 = qcar(v_19683);
    v_19684 = qcar(v_19683);
    goto v_19582;
v_19583:
    v_19683 = stack[-1];
    v_19683 = qcar(v_19683);
    v_19683 = qcar(v_19683);
    goto v_19584;
v_19585:
    goto v_19581;
v_19582:
    goto v_19583;
v_19584:
    if (equal(v_19684, v_19683)) goto v_19579;
    else goto v_19580;
v_19579:
    goto v_19597;
v_19593:
    stack[-3] = stack[0];
    goto v_19594;
v_19595:
    goto v_19604;
v_19600:
    v_19683 = stack[-2];
    v_19683 = qcar(v_19683);
    v_19684 = qcdr(v_19683);
    goto v_19601;
v_19602:
    v_19683 = stack[-1];
    v_19683 = qcar(v_19683);
    v_19683 = qcdr(v_19683);
    goto v_19603;
v_19604:
    goto v_19600;
v_19601:
    goto v_19602;
v_19603:
    fn = elt(env, 2); // !*addsq
    stack[0] = (*qfn2(fn))(fn, v_19684, v_19683);
    env = stack[-4];
    goto v_19616;
v_19612:
    v_19683 = stack[-2];
    v_19684 = qcdr(v_19683);
    goto v_19613;
v_19614:
    v_19683 = stack[-1];
    v_19683 = qcdr(v_19683);
    goto v_19615;
v_19616:
    goto v_19612;
v_19613:
    goto v_19614;
v_19615:
    v_19683 = CC_plusdf(elt(env, 0), v_19684, v_19683);
    env = stack[-4];
    v_19684 = stack[0];
    v_19685 = v_19684;
    v_19685 = qcar(v_19685);
    if (v_19685 == nil) goto v_19625;
    else goto v_19626;
v_19625:
    goto v_19624;
v_19626:
    goto v_19639;
v_19633:
    v_19685 = stack[-2];
    v_19685 = qcar(v_19685);
    v_19685 = qcar(v_19685);
    goto v_19634;
v_19635:
    goto v_19636;
v_19637:
    goto v_19638;
v_19639:
    goto v_19633;
v_19634:
    goto v_19635;
v_19636:
    goto v_19637;
v_19638:
    v_19683 = acons(v_19685, v_19684, v_19683);
    env = stack[-4];
    goto v_19624;
    v_19683 = nil;
v_19624:
    goto v_19596;
v_19597:
    goto v_19593;
v_19594:
    goto v_19595;
v_19596:
    {
        LispObject v_19690 = stack[-3];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_19690, v_19683);
    }
v_19580:
    goto v_19652;
v_19648:
    v_19683 = stack[-2];
    v_19683 = qcar(v_19683);
    v_19684 = qcar(v_19683);
    goto v_19649;
v_19650:
    v_19683 = stack[-1];
    v_19683 = qcar(v_19683);
    v_19683 = qcar(v_19683);
    goto v_19651;
v_19652:
    goto v_19648;
v_19649:
    goto v_19650;
v_19651:
    fn = elt(env, 3); // orddf
    v_19683 = (*qfn2(fn))(fn, v_19684, v_19683);
    env = stack[-4];
    if (v_19683 == nil) goto v_19646;
    goto v_19664;
v_19660:
    v_19683 = stack[-2];
    v_19684 = qcar(v_19683);
    goto v_19661;
v_19662:
    v_19683 = stack[0];
    goto v_19663;
v_19664:
    goto v_19660;
v_19661:
    goto v_19662;
v_19663:
    v_19683 = cons(v_19684, v_19683);
    env = stack[-4];
    stack[0] = v_19683;
    v_19683 = stack[-2];
    v_19683 = qcdr(v_19683);
    stack[-2] = v_19683;
    goto v_19554;
v_19646:
    goto v_19677;
v_19673:
    v_19683 = stack[-1];
    v_19684 = qcar(v_19683);
    goto v_19674;
v_19675:
    v_19683 = stack[0];
    goto v_19676;
v_19677:
    goto v_19673;
v_19674:
    goto v_19675;
v_19676:
    v_19683 = cons(v_19684, v_19683);
    env = stack[-4];
    stack[0] = v_19683;
    v_19683 = stack[-1];
    v_19683 = qcdr(v_19683);
    stack[-1] = v_19683;
    goto v_19554;
    v_19683 = nil;
    return onevalue(v_19683);
}



// Code for gen!+can!+bas

static LispObject CC_genLcanLbas(LispObject env,
                         LispObject v_19548)
{
    env = qenv(env);
    LispObject v_19778, v_19779;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19548);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_19548;
// end of prologue
    goto v_19562;
v_19558:
    v_19779 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19559;
v_19560:
    v_19778 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19561;
v_19562:
    goto v_19558;
v_19559:
    goto v_19560;
v_19561:
    v_19778 = cons(v_19779, v_19778);
    env = stack[-11];
    stack[-10] = v_19778;
    goto v_19570;
v_19566:
    v_19779 = nil;
    goto v_19567;
v_19568:
    v_19778 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19569;
v_19570:
    goto v_19566;
v_19567:
    goto v_19568;
v_19569:
    v_19778 = cons(v_19779, v_19778);
    env = stack[-11];
    stack[-8] = v_19778;
    v_19778 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-7] = v_19778;
    goto v_19590;
v_19586:
    v_19779 = stack[-9];
    goto v_19587;
v_19588:
    v_19778 = stack[-7];
    goto v_19589;
v_19590:
    goto v_19586;
v_19587:
    goto v_19588;
v_19589:
    v_19778 = difference2(v_19779, v_19778);
    env = stack[-11];
    v_19778 = Lminusp(nil, v_19778);
    env = stack[-11];
    if (v_19778 == nil) goto v_19583;
    v_19778 = nil;
    goto v_19577;
v_19583:
    v_19778 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_19778;
    goto v_19612;
v_19608:
    v_19779 = stack[-9];
    goto v_19609;
v_19610:
    v_19778 = stack[-3];
    goto v_19611;
v_19612:
    goto v_19608;
v_19609:
    goto v_19610;
v_19611:
    v_19778 = difference2(v_19779, v_19778);
    env = stack[-11];
    v_19778 = Lminusp(nil, v_19778);
    env = stack[-11];
    if (v_19778 == nil) goto v_19605;
    v_19778 = nil;
    goto v_19599;
v_19605:
    goto v_19625;
v_19621:
    v_19779 = stack[-7];
    goto v_19622;
v_19623:
    v_19778 = stack[-3];
    goto v_19624;
v_19625:
    goto v_19621;
v_19622:
    goto v_19623;
v_19624:
    if (equal(v_19779, v_19778)) goto v_19619;
    else goto v_19620;
v_19619:
    v_19778 = stack[-10];
    goto v_19618;
v_19620:
    v_19778 = stack[-8];
    goto v_19618;
    v_19778 = nil;
v_19618:
    v_19778 = ncons(v_19778);
    env = stack[-11];
    stack[-1] = v_19778;
    stack[-2] = v_19778;
v_19600:
    v_19778 = stack[-3];
    v_19778 = add1(v_19778);
    env = stack[-11];
    stack[-3] = v_19778;
    goto v_19644;
v_19640:
    v_19779 = stack[-9];
    goto v_19641;
v_19642:
    v_19778 = stack[-3];
    goto v_19643;
v_19644:
    goto v_19640;
v_19641:
    goto v_19642;
v_19643:
    v_19778 = difference2(v_19779, v_19778);
    env = stack[-11];
    v_19778 = Lminusp(nil, v_19778);
    env = stack[-11];
    if (v_19778 == nil) goto v_19637;
    v_19778 = stack[-2];
    goto v_19599;
v_19637:
    goto v_19653;
v_19649:
    stack[0] = stack[-1];
    goto v_19650;
v_19651:
    goto v_19664;
v_19660:
    v_19779 = stack[-7];
    goto v_19661;
v_19662:
    v_19778 = stack[-3];
    goto v_19663;
v_19664:
    goto v_19660;
v_19661:
    goto v_19662;
v_19663:
    if (equal(v_19779, v_19778)) goto v_19658;
    else goto v_19659;
v_19658:
    v_19778 = stack[-10];
    goto v_19657;
v_19659:
    v_19778 = stack[-8];
    goto v_19657;
    v_19778 = nil;
v_19657:
    v_19778 = ncons(v_19778);
    env = stack[-11];
    goto v_19652;
v_19653:
    goto v_19649;
v_19650:
    goto v_19651;
v_19652:
    v_19778 = Lrplacd(nil, stack[0], v_19778);
    env = stack[-11];
    v_19778 = stack[-1];
    v_19778 = qcdr(v_19778);
    stack[-1] = v_19778;
    goto v_19600;
v_19599:
    v_19778 = ncons(v_19778);
    env = stack[-11];
    stack[-5] = v_19778;
    stack[-6] = v_19778;
v_19578:
    v_19778 = stack[-7];
    v_19778 = add1(v_19778);
    env = stack[-11];
    stack[-7] = v_19778;
    goto v_19685;
v_19681:
    v_19779 = stack[-9];
    goto v_19682;
v_19683:
    v_19778 = stack[-7];
    goto v_19684;
v_19685:
    goto v_19681;
v_19682:
    goto v_19683;
v_19684:
    v_19778 = difference2(v_19779, v_19778);
    env = stack[-11];
    v_19778 = Lminusp(nil, v_19778);
    env = stack[-11];
    if (v_19778 == nil) goto v_19678;
    v_19778 = stack[-6];
    goto v_19577;
v_19678:
    goto v_19694;
v_19690:
    stack[-4] = stack[-5];
    goto v_19691;
v_19692:
    v_19778 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_19778;
    goto v_19714;
v_19710:
    v_19779 = stack[-9];
    goto v_19711;
v_19712:
    v_19778 = stack[-3];
    goto v_19713;
v_19714:
    goto v_19710;
v_19711:
    goto v_19712;
v_19713:
    v_19778 = difference2(v_19779, v_19778);
    env = stack[-11];
    v_19778 = Lminusp(nil, v_19778);
    env = stack[-11];
    if (v_19778 == nil) goto v_19707;
    v_19778 = nil;
    goto v_19701;
v_19707:
    goto v_19727;
v_19723:
    v_19779 = stack[-7];
    goto v_19724;
v_19725:
    v_19778 = stack[-3];
    goto v_19726;
v_19727:
    goto v_19723;
v_19724:
    goto v_19725;
v_19726:
    if (equal(v_19779, v_19778)) goto v_19721;
    else goto v_19722;
v_19721:
    v_19778 = stack[-10];
    goto v_19720;
v_19722:
    v_19778 = stack[-8];
    goto v_19720;
    v_19778 = nil;
v_19720:
    v_19778 = ncons(v_19778);
    env = stack[-11];
    stack[-1] = v_19778;
    stack[-2] = v_19778;
v_19702:
    v_19778 = stack[-3];
    v_19778 = add1(v_19778);
    env = stack[-11];
    stack[-3] = v_19778;
    goto v_19746;
v_19742:
    v_19779 = stack[-9];
    goto v_19743;
v_19744:
    v_19778 = stack[-3];
    goto v_19745;
v_19746:
    goto v_19742;
v_19743:
    goto v_19744;
v_19745:
    v_19778 = difference2(v_19779, v_19778);
    env = stack[-11];
    v_19778 = Lminusp(nil, v_19778);
    env = stack[-11];
    if (v_19778 == nil) goto v_19739;
    v_19778 = stack[-2];
    goto v_19701;
v_19739:
    goto v_19755;
v_19751:
    stack[0] = stack[-1];
    goto v_19752;
v_19753:
    goto v_19766;
v_19762:
    v_19779 = stack[-7];
    goto v_19763;
v_19764:
    v_19778 = stack[-3];
    goto v_19765;
v_19766:
    goto v_19762;
v_19763:
    goto v_19764;
v_19765:
    if (equal(v_19779, v_19778)) goto v_19760;
    else goto v_19761;
v_19760:
    v_19778 = stack[-10];
    goto v_19759;
v_19761:
    v_19778 = stack[-8];
    goto v_19759;
    v_19778 = nil;
v_19759:
    v_19778 = ncons(v_19778);
    env = stack[-11];
    goto v_19754;
v_19755:
    goto v_19751;
v_19752:
    goto v_19753;
v_19754:
    v_19778 = Lrplacd(nil, stack[0], v_19778);
    env = stack[-11];
    v_19778 = stack[-1];
    v_19778 = qcdr(v_19778);
    stack[-1] = v_19778;
    goto v_19702;
v_19701:
    v_19778 = ncons(v_19778);
    env = stack[-11];
    goto v_19693;
v_19694:
    goto v_19690;
v_19691:
    goto v_19692;
v_19693:
    v_19778 = Lrplacd(nil, stack[-4], v_19778);
    env = stack[-11];
    v_19778 = stack[-5];
    v_19778 = qcdr(v_19778);
    stack[-5] = v_19778;
    goto v_19578;
v_19577:
    return onevalue(v_19778);
}



// Code for cl_susicpknowl

static LispObject CC_cl_susicpknowl(LispObject env,
                         LispObject v_19548)
{
    env = qenv(env);
    LispObject v_19608, v_19609;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19548);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_19608 = v_19548;
// end of prologue
    stack[-3] = v_19608;
    v_19608 = stack[-3];
    if (v_19608 == nil) goto v_19559;
    else goto v_19560;
v_19559:
    v_19608 = nil;
    goto v_19554;
v_19560:
    v_19608 = stack[-3];
    v_19608 = qcar(v_19608);
    goto v_19572;
v_19568:
    v_19609 = v_19608;
    v_19609 = qcar(v_19609);
    goto v_19569;
v_19570:
    v_19608 = qcdr(v_19608);
    goto v_19571;
v_19572:
    goto v_19568;
v_19569:
    goto v_19570;
v_19571:
    v_19608 = cons(v_19609, v_19608);
    env = stack[-4];
    v_19608 = ncons(v_19608);
    env = stack[-4];
    stack[-1] = v_19608;
    stack[-2] = v_19608;
v_19555:
    v_19608 = stack[-3];
    v_19608 = qcdr(v_19608);
    stack[-3] = v_19608;
    v_19608 = stack[-3];
    if (v_19608 == nil) goto v_19581;
    else goto v_19582;
v_19581:
    v_19608 = stack[-2];
    goto v_19554;
v_19582:
    goto v_19590;
v_19586:
    stack[0] = stack[-1];
    goto v_19587;
v_19588:
    v_19608 = stack[-3];
    v_19608 = qcar(v_19608);
    goto v_19601;
v_19597:
    v_19609 = v_19608;
    v_19609 = qcar(v_19609);
    goto v_19598;
v_19599:
    v_19608 = qcdr(v_19608);
    goto v_19600;
v_19601:
    goto v_19597;
v_19598:
    goto v_19599;
v_19600:
    v_19608 = cons(v_19609, v_19608);
    env = stack[-4];
    v_19608 = ncons(v_19608);
    env = stack[-4];
    goto v_19589;
v_19590:
    goto v_19586;
v_19587:
    goto v_19588;
v_19589:
    v_19608 = Lrplacd(nil, stack[0], v_19608);
    env = stack[-4];
    v_19608 = stack[-1];
    v_19608 = qcdr(v_19608);
    stack[-1] = v_19608;
    goto v_19555;
v_19554:
    return onevalue(v_19608);
}



// Code for vectorml

static LispObject CC_vectorml(LispObject env,
                         LispObject v_19548)
{
    env = qenv(env);
    LispObject v_19572, v_19573;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19548);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_19548;
// end of prologue
    v_19572 = elt(env, 1); // "<vector"
    fn = elt(env, 4); // printout
    v_19572 = (*qfn1(fn))(fn, v_19572);
    env = stack[-1];
    goto v_19559;
v_19555:
    v_19572 = stack[0];
    v_19573 = qcar(v_19572);
    goto v_19556;
v_19557:
    v_19572 = elt(env, 2); // ""
    goto v_19558;
v_19559:
    goto v_19555;
v_19556:
    goto v_19557;
v_19558:
    fn = elt(env, 5); // attributesml
    v_19572 = (*qfn2(fn))(fn, v_19573, v_19572);
    env = stack[-1];
    v_19572 = lisp_true;
    fn = elt(env, 6); // indent!*
    v_19572 = (*qfn1(fn))(fn, v_19572);
    env = stack[-1];
    v_19572 = stack[0];
    v_19572 = qcdr(v_19572);
    fn = elt(env, 7); // multi_elem
    v_19572 = (*qfn1(fn))(fn, v_19572);
    env = stack[-1];
    v_19572 = nil;
    fn = elt(env, 6); // indent!*
    v_19572 = (*qfn1(fn))(fn, v_19572);
    env = stack[-1];
    v_19572 = elt(env, 3); // "</vector>"
    fn = elt(env, 4); // printout
    v_19572 = (*qfn1(fn))(fn, v_19572);
    v_19572 = nil;
    return onevalue(v_19572);
}



// Code for delyzz

static LispObject CC_delyzz(LispObject env,
                         LispObject v_19548, LispObject v_19549)
{
    env = qenv(env);
    LispObject v_19590, v_19591, v_19592;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19549,v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19548,v_19549);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_19549;
    stack[-1] = v_19548;
// end of prologue
    v_19592 = nil;
v_19554:
    goto v_19563;
v_19559:
    v_19591 = stack[-1];
    goto v_19560;
v_19561:
    v_19590 = stack[0];
    v_19590 = qcar(v_19590);
    v_19590 = qcar(v_19590);
    goto v_19562;
v_19563:
    goto v_19559;
v_19560:
    goto v_19561;
v_19562:
    if (equal(v_19591, v_19590)) goto v_19557;
    else goto v_19558;
v_19557:
    goto v_19573;
v_19569:
    v_19591 = v_19592;
    goto v_19570;
v_19571:
    v_19590 = stack[0];
    v_19590 = qcdr(v_19590);
    goto v_19572;
v_19573:
    goto v_19569;
v_19570:
    goto v_19571;
v_19572:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_19591, v_19590);
    }
v_19558:
    goto v_19584;
v_19580:
    v_19590 = stack[0];
    v_19590 = qcar(v_19590);
    goto v_19581;
v_19582:
    v_19591 = v_19592;
    goto v_19583;
v_19584:
    goto v_19580;
v_19581:
    goto v_19582;
v_19583:
    v_19590 = cons(v_19590, v_19591);
    env = stack[-2];
    v_19592 = v_19590;
    v_19590 = stack[0];
    v_19590 = qcdr(v_19590);
    stack[0] = v_19590;
    goto v_19554;
    v_19590 = nil;
    return onevalue(v_19590);
}



// Code for dipsimpcont

static LispObject CC_dipsimpcont(LispObject env,
                         LispObject v_19548)
{
    env = qenv(env);
    LispObject v_19564, v_19565;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_19565 = v_19548;
// end of prologue
    v_19564 = qvalue(elt(env, 1)); // !*vdpinteger
    if (v_19564 == nil) goto v_19554;
    else goto v_19552;
v_19554:
    v_19564 = qvalue(elt(env, 2)); // !*groebdivide
    if (v_19564 == nil) goto v_19552;
    goto v_19553;
v_19552:
    v_19564 = v_19565;
    {
        fn = elt(env, 3); // dipsimpconti
        return (*qfn1(fn))(fn, v_19564);
    }
v_19553:
    v_19564 = v_19565;
    {
        fn = elt(env, 4); // dipsimpcontr
        return (*qfn1(fn))(fn, v_19564);
    }
    v_19564 = nil;
    return onevalue(v_19564);
}



// Code for dipprodin

static LispObject CC_dipprodin(LispObject env,
                         LispObject v_19548, LispObject v_19549)
{
    env = qenv(env);
    LispObject v_19614, v_19615, v_19616;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19549,v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19548,v_19549);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_19549;
    stack[-1] = v_19548;
// end of prologue
    stack[-2] = nil;
v_19555:
    v_19614 = stack[-1];
    if (v_19614 == nil) goto v_19564;
    else goto v_19565;
v_19564:
    v_19614 = lisp_true;
    goto v_19563;
v_19565:
    v_19614 = stack[0];
    v_19614 = (v_19614 == nil ? lisp_true : nil);
    goto v_19563;
    v_19614 = nil;
v_19563:
    if (v_19614 == nil) goto v_19561;
    goto v_19556;
v_19561:
    goto v_19577;
v_19573:
    goto v_19585;
v_19579:
    v_19614 = stack[-1];
    v_19614 = qcdr(v_19614);
    v_19616 = qcar(v_19614);
    goto v_19580;
v_19581:
    v_19614 = stack[-1];
    v_19615 = qcar(v_19614);
    goto v_19582;
v_19583:
    v_19614 = stack[0];
    goto v_19584;
v_19585:
    goto v_19579;
v_19580:
    goto v_19581;
v_19582:
    goto v_19583;
v_19584:
    fn = elt(env, 2); // dipprodin1
    v_19615 = (*qfnn(fn))(fn, 3, v_19616, v_19615, v_19614);
    env = stack[-3];
    goto v_19574;
v_19575:
    v_19614 = stack[-2];
    goto v_19576;
v_19577:
    goto v_19573;
v_19574:
    goto v_19575;
v_19576:
    v_19614 = cons(v_19615, v_19614);
    env = stack[-3];
    stack[-2] = v_19614;
    v_19614 = stack[-1];
    v_19614 = qcdr(v_19614);
    v_19614 = qcdr(v_19614);
    stack[-1] = v_19614;
    goto v_19555;
v_19556:
    v_19614 = qvalue(elt(env, 1)); // dipzero
    v_19615 = v_19614;
v_19557:
    v_19614 = stack[-2];
    if (v_19614 == nil) goto v_19599;
    else goto v_19600;
v_19599:
    v_19614 = v_19615;
    goto v_19554;
v_19600:
    goto v_19608;
v_19604:
    v_19614 = stack[-2];
    v_19614 = qcar(v_19614);
    goto v_19605;
v_19606:
    goto v_19607;
v_19608:
    goto v_19604;
v_19605:
    goto v_19606;
v_19607:
    fn = elt(env, 3); // dipsum
    v_19614 = (*qfn2(fn))(fn, v_19614, v_19615);
    env = stack[-3];
    v_19615 = v_19614;
    v_19614 = stack[-2];
    v_19614 = qcdr(v_19614);
    stack[-2] = v_19614;
    goto v_19557;
v_19554:
    return onevalue(v_19614);
}



// Code for unplus

static LispObject CC_unplus(LispObject env,
                         LispObject v_19548)
{
    env = qenv(env);
    LispObject v_19632, v_19633, v_19634;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19548);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_19548;
// end of prologue
    v_19634 = nil;
v_19553:
    v_19632 = stack[-1];
    if (!consp(v_19632)) goto v_19556;
    else goto v_19557;
v_19556:
    goto v_19564;
v_19560:
    v_19633 = v_19634;
    goto v_19561;
v_19562:
    v_19632 = stack[-1];
    goto v_19563;
v_19564:
    goto v_19560;
v_19561:
    goto v_19562;
v_19563:
    {
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_19633, v_19632);
    }
v_19557:
    goto v_19573;
v_19569:
    v_19632 = stack[-1];
    v_19633 = qcar(v_19632);
    goto v_19570;
v_19571:
    v_19632 = elt(env, 1); // plus
    goto v_19572;
v_19573:
    goto v_19569;
v_19570:
    goto v_19571;
v_19572:
    if (v_19633 == v_19632) goto v_19567;
    else goto v_19568;
v_19567:
    v_19632 = stack[-1];
    v_19632 = qcdr(v_19632);
    stack[-1] = v_19632;
    goto v_19553;
v_19568:
    v_19632 = stack[-1];
    v_19632 = qcar(v_19632);
    if (!consp(v_19632)) goto v_19583;
    else goto v_19584;
v_19583:
    v_19632 = lisp_true;
    goto v_19582;
v_19584:
    goto v_19595;
v_19591:
    v_19632 = stack[-1];
    v_19633 = qcar(v_19632);
    goto v_19592;
v_19593:
    v_19632 = elt(env, 1); // plus
    goto v_19594;
v_19595:
    goto v_19591;
v_19592:
    goto v_19593;
v_19594:
    v_19632 = Leqcar(nil, v_19633, v_19632);
    env = stack[-3];
    v_19632 = (v_19632 == nil ? lisp_true : nil);
    goto v_19582;
    v_19632 = nil;
v_19582:
    if (v_19632 == nil) goto v_19580;
    goto v_19605;
v_19601:
    v_19632 = stack[-1];
    v_19632 = qcar(v_19632);
    goto v_19602;
v_19603:
    v_19633 = v_19634;
    goto v_19604;
v_19605:
    goto v_19601;
v_19602:
    goto v_19603;
v_19604:
    v_19632 = cons(v_19632, v_19633);
    env = stack[-3];
    v_19634 = v_19632;
    v_19632 = stack[-1];
    v_19632 = qcdr(v_19632);
    stack[-1] = v_19632;
    goto v_19553;
v_19580:
    goto v_19618;
v_19614:
    stack[-2] = v_19634;
    goto v_19615;
v_19616:
    goto v_19625;
v_19621:
    v_19632 = stack[-1];
    v_19632 = qcar(v_19632);
    stack[0] = qcdr(v_19632);
    goto v_19622;
v_19623:
    v_19632 = stack[-1];
    v_19632 = qcdr(v_19632);
    v_19632 = CC_unplus(elt(env, 0), v_19632);
    env = stack[-3];
    goto v_19624;
v_19625:
    goto v_19621;
v_19622:
    goto v_19623;
v_19624:
    v_19632 = Lappend(nil, stack[0], v_19632);
    env = stack[-3];
    goto v_19617;
v_19618:
    goto v_19614;
v_19615:
    goto v_19616;
v_19617:
    {
        LispObject v_19638 = stack[-2];
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_19638, v_19632);
    }
    v_19632 = nil;
    return onevalue(v_19632);
}



// Code for convprc2

static LispObject CC_convprc2(LispObject env,
                         LispObject v_19548, LispObject v_19549)
{
    env = qenv(env);
    LispObject v_19637, v_19638, v_19639;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19549,v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19548,v_19549);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_19549;
    stack[-1] = v_19548;
// end of prologue
    v_19637 = stack[-1];
    fn = elt(env, 4); // convprec
    v_19637 = (*qfn1(fn))(fn, v_19637);
    env = stack[-2];
    stack[-1] = v_19637;
    v_19637 = stack[0];
    fn = elt(env, 4); // convprec
    v_19637 = (*qfn1(fn))(fn, v_19637);
    env = stack[-2];
    qvalue(elt(env, 1)) = v_19637; // yy!!
    v_19637 = qvalue(elt(env, 2)); // !*roundbf
    if (v_19637 == nil) goto v_19558;
    v_19637 = qvalue(elt(env, 1)); // yy!!
    v_19638 = v_19637;
    v_19638 = Lfloatp(nil, v_19638);
    env = stack[-2];
    if (v_19638 == nil) goto v_19565;
    fn = elt(env, 5); // fl2bf
    v_19637 = (*qfn1(fn))(fn, v_19637);
    env = stack[-2];
    goto v_19563;
v_19565:
    v_19638 = v_19637;
    if (!consp(v_19638)) goto v_19576;
    goto v_19574;
v_19576:
    v_19638 = v_19637;
    v_19638 = integerp(v_19638);
    if (v_19638 == nil) goto v_19580;
    goto v_19590;
v_19584:
    v_19639 = elt(env, 3); // !:rd!:
    goto v_19585;
v_19586:
    v_19638 = v_19637;
    goto v_19587;
v_19588:
    v_19637 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19589;
v_19590:
    goto v_19584;
v_19585:
    goto v_19586;
v_19587:
    goto v_19588;
v_19589:
    v_19637 = list2star(v_19639, v_19638, v_19637);
    env = stack[-2];
    goto v_19574;
v_19580:
    fn = elt(env, 6); // read!:num
    v_19637 = (*qfn1(fn))(fn, v_19637);
    env = stack[-2];
    goto v_19574;
    v_19637 = nil;
v_19574:
    fn = elt(env, 7); // normbf
    v_19637 = (*qfn1(fn))(fn, v_19637);
    env = stack[-2];
    goto v_19563;
    v_19637 = nil;
v_19563:
    qvalue(elt(env, 1)) = v_19637; // yy!!
    v_19637 = stack[-1];
    v_19637 = Lfloatp(nil, v_19637);
    env = stack[-2];
    if (v_19637 == nil) goto v_19601;
    v_19637 = stack[-1];
    {
        fn = elt(env, 5); // fl2bf
        return (*qfn1(fn))(fn, v_19637);
    }
v_19601:
    v_19637 = stack[-1];
    if (!consp(v_19637)) goto v_19612;
    v_19637 = stack[-1];
    goto v_19610;
v_19612:
    v_19637 = stack[-1];
    v_19637 = integerp(v_19637);
    if (v_19637 == nil) goto v_19616;
    goto v_19626;
v_19620:
    v_19639 = elt(env, 3); // !:rd!:
    goto v_19621;
v_19622:
    v_19638 = stack[-1];
    goto v_19623;
v_19624:
    v_19637 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19625;
v_19626:
    goto v_19620;
v_19621:
    goto v_19622;
v_19623:
    goto v_19624;
v_19625:
    v_19637 = list2star(v_19639, v_19638, v_19637);
    env = stack[-2];
    goto v_19610;
v_19616:
    v_19637 = stack[-1];
    fn = elt(env, 6); // read!:num
    v_19637 = (*qfn1(fn))(fn, v_19637);
    env = stack[-2];
    goto v_19610;
    v_19637 = nil;
v_19610:
    {
        fn = elt(env, 7); // normbf
        return (*qfn1(fn))(fn, v_19637);
    }
    v_19637 = nil;
    goto v_19556;
v_19558:
    v_19637 = stack[-1];
    goto v_19556;
    v_19637 = nil;
v_19556:
    return onevalue(v_19637);
}



// Code for color!-strand

static LispObject CC_colorKstrand(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_19588, v_19589, v_19590;
    LispObject fn;
    LispObject v_19550, v_19549, v_19548;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "color-strand");
    va_start(aa, nargs);
    v_19548 = va_arg(aa, LispObject);
    v_19549 = va_arg(aa, LispObject);
    v_19550 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_19550,v_19549,v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_19548,v_19549,v_19550);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_19550;
    stack[-1] = v_19549;
    stack[-2] = v_19548;
// end of prologue
    stack[-3] = nil;
v_19555:
    v_19588 = stack[-1];
    if (v_19588 == nil) goto v_19558;
    else goto v_19559;
v_19558:
    v_19588 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_19588);
    }
v_19559:
    goto v_19572;
v_19566:
    goto v_19578;
v_19574:
    v_19589 = stack[-2];
    goto v_19575;
v_19576:
    v_19588 = stack[-1];
    v_19588 = qcar(v_19588);
    goto v_19577;
v_19578:
    goto v_19574;
v_19575:
    goto v_19576;
v_19577:
    fn = elt(env, 2); // color!-roads
    v_19590 = (*qfn2(fn))(fn, v_19589, v_19588);
    env = stack[-4];
    goto v_19567;
v_19568:
    v_19589 = stack[0];
    goto v_19569;
v_19570:
    v_19588 = stack[-3];
    goto v_19571;
v_19572:
    goto v_19566;
v_19567:
    goto v_19568;
v_19569:
    goto v_19570;
v_19571:
    v_19588 = acons(v_19590, v_19589, v_19588);
    env = stack[-4];
    stack[-3] = v_19588;
    v_19588 = stack[-1];
    v_19588 = qcdr(v_19588);
    stack[-1] = v_19588;
    v_19588 = stack[0];
    v_19588 = add1(v_19588);
    env = stack[-4];
    stack[0] = v_19588;
    goto v_19555;
    v_19588 = nil;
    return onevalue(v_19588);
}



// Code for ratfunpri1

static LispObject CC_ratfunpri1(LispObject env,
                         LispObject v_19548)
{
    env = qenv(env);
    LispObject v_19965, v_19966, v_19967;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19548);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[0] = v_19548;
// end of prologue
    goto v_19574;
v_19570:
    v_19966 = qvalue(elt(env, 1)); // spare!*
    goto v_19571;
v_19572:
    v_19965 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_19573;
v_19574:
    goto v_19570;
v_19571:
    goto v_19572;
v_19573:
    v_19965 = plus2(v_19966, v_19965);
    env = stack[-8];
    qvalue(elt(env, 1)) = v_19965; // spare!*
    goto v_19589;
v_19583:
    v_19965 = stack[0];
    v_19965 = qcdr(v_19965);
    v_19967 = qcar(v_19965);
    goto v_19584;
v_19585:
    v_19966 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19586;
v_19587:
    v_19965 = nil;
    goto v_19588;
v_19589:
    goto v_19583;
v_19584:
    goto v_19585;
v_19586:
    goto v_19587;
v_19588:
    fn = elt(env, 13); // layout!-formula
    v_19965 = (*qfnn(fn))(fn, 3, v_19967, v_19966, v_19965);
    env = stack[-8];
    stack[-7] = v_19965;
    if (v_19965 == nil) goto v_19580;
    goto v_19603;
v_19597:
    v_19965 = stack[0];
    v_19965 = qcdr(v_19965);
    v_19965 = qcdr(v_19965);
    v_19967 = qcar(v_19965);
    goto v_19598;
v_19599:
    v_19966 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19600;
v_19601:
    v_19965 = nil;
    goto v_19602;
v_19603:
    goto v_19597;
v_19598:
    goto v_19599;
v_19600:
    goto v_19601;
v_19602:
    fn = elt(env, 13); // layout!-formula
    v_19965 = (*qfnn(fn))(fn, 3, v_19967, v_19966, v_19965);
    env = stack[-8];
    stack[-6] = v_19965;
    if (v_19965 == nil) goto v_19580;
    goto v_19615;
v_19611:
    v_19966 = qvalue(elt(env, 1)); // spare!*
    goto v_19612;
v_19613:
    v_19965 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_19614;
v_19615:
    goto v_19611;
v_19612:
    goto v_19613;
v_19614:
    v_19965 = difference2(v_19966, v_19965);
    env = stack[-8];
    qvalue(elt(env, 1)) = v_19965; // spare!*
    goto v_19623;
v_19619:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_19620;
v_19621:
    goto v_19630;
v_19626:
    v_19965 = stack[-7];
    v_19965 = qcar(v_19965);
    v_19966 = qcdr(v_19965);
    goto v_19627;
v_19628:
    v_19965 = stack[-6];
    v_19965 = qcar(v_19965);
    v_19965 = qcdr(v_19965);
    goto v_19629;
v_19630:
    goto v_19626;
v_19627:
    goto v_19628;
v_19629:
    fn = elt(env, 14); // max
    v_19965 = (*qfn2(fn))(fn, v_19966, v_19965);
    env = stack[-8];
    goto v_19622;
v_19623:
    goto v_19619;
v_19620:
    goto v_19621;
v_19622:
    v_19965 = plus2(stack[0], v_19965);
    env = stack[-8];
    stack[-2] = v_19965;
    goto v_19646;
v_19642:
    stack[0] = stack[-2];
    goto v_19643;
v_19644:
    goto v_19653;
v_19649:
    goto v_19659;
v_19655:
    v_19965 = nil;
    v_19966 = Llinelength(nil, v_19965);
    env = stack[-8];
    goto v_19656;
v_19657:
    v_19965 = qvalue(elt(env, 1)); // spare!*
    goto v_19658;
v_19659:
    goto v_19655;
v_19656:
    goto v_19657;
v_19658:
    v_19966 = difference2(v_19966, v_19965);
    env = stack[-8];
    goto v_19650;
v_19651:
    v_19965 = qvalue(elt(env, 2)); // posn!*
    goto v_19652;
v_19653:
    goto v_19649;
v_19650:
    goto v_19651;
v_19652:
    v_19965 = difference2(v_19966, v_19965);
    env = stack[-8];
    goto v_19645;
v_19646:
    goto v_19642;
v_19643:
    goto v_19644;
v_19645:
    v_19965 = (LispObject)greaterp2(stack[0], v_19965);
    v_19965 = v_19965 ? lisp_true : nil;
    env = stack[-8];
    if (v_19965 == nil) goto v_19640;
    v_19965 = lisp_true;
    fn = elt(env, 15); // terpri!*
    v_19965 = (*qfn1(fn))(fn, v_19965);
    env = stack[-8];
    goto v_19638;
v_19640:
v_19638:
    goto v_19671;
v_19667:
    v_19965 = stack[-7];
    v_19965 = qcar(v_19965);
    v_19966 = qcdr(v_19965);
    goto v_19668;
v_19669:
    v_19965 = stack[-6];
    v_19965 = qcar(v_19965);
    v_19965 = qcdr(v_19965);
    goto v_19670;
v_19671:
    goto v_19667;
v_19668:
    goto v_19669;
v_19670:
    v_19965 = difference2(v_19966, v_19965);
    env = stack[-8];
    stack[-1] = v_19965;
    goto v_19687;
v_19683:
    v_19966 = stack[-1];
    goto v_19684;
v_19685:
    v_19965 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19686;
v_19687:
    goto v_19683;
v_19684:
    goto v_19685;
v_19686:
    v_19965 = (LispObject)greaterp2(v_19966, v_19965);
    v_19965 = v_19965 ? lisp_true : nil;
    env = stack[-8];
    if (v_19965 == nil) goto v_19681;
    v_19965 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_19965;
    goto v_19696;
v_19692:
    v_19966 = stack[-1];
    goto v_19693;
v_19694:
    v_19965 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_19695;
v_19696:
    goto v_19692;
v_19693:
    goto v_19694;
v_19695:
    v_19965 = quot2(v_19966, v_19965);
    env = stack[-8];
    stack[-3] = v_19965;
    goto v_19679;
v_19681:
    goto v_19706;
v_19702:
    v_19965 = stack[-1];
    v_19966 = negate(v_19965);
    env = stack[-8];
    goto v_19703;
v_19704:
    v_19965 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_19705;
v_19706:
    goto v_19702;
v_19703:
    goto v_19704;
v_19705:
    v_19965 = quot2(v_19966, v_19965);
    env = stack[-8];
    stack[0] = v_19965;
    v_19965 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_19965;
    goto v_19679;
v_19679:
    goto v_19717;
v_19713:
    v_19965 = stack[-7];
    v_19965 = qcdr(v_19965);
    v_19966 = qcdr(v_19965);
    goto v_19714;
v_19715:
    v_19965 = stack[-7];
    v_19965 = qcdr(v_19965);
    v_19965 = qcar(v_19965);
    goto v_19716;
v_19717:
    goto v_19713;
v_19714:
    goto v_19715;
v_19716:
    v_19965 = difference2(v_19966, v_19965);
    env = stack[-8];
    v_19965 = add1(v_19965);
    env = stack[-8];
    stack[-5] = v_19965;
    goto v_19730;
v_19726:
    v_19965 = stack[-6];
    v_19965 = qcdr(v_19965);
    v_19966 = qcdr(v_19965);
    goto v_19727;
v_19728:
    v_19965 = stack[-6];
    v_19965 = qcdr(v_19965);
    v_19965 = qcar(v_19965);
    goto v_19729;
v_19730:
    goto v_19726;
v_19727:
    goto v_19728;
v_19729:
    v_19965 = difference2(v_19966, v_19965);
    env = stack[-8];
    v_19965 = add1(v_19965);
    env = stack[-8];
    stack[-4] = v_19965;
    goto v_19742;
v_19738:
    goto v_19750;
v_19744:
    goto v_19756;
v_19752:
    stack[-1] = stack[0];
    goto v_19753;
v_19754:
    goto v_19763;
v_19759:
    stack[0] = qvalue(elt(env, 2)); // posn!*
    goto v_19760;
v_19761:
    goto v_19770;
v_19766:
    v_19966 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19767;
v_19768:
    v_19965 = qvalue(elt(env, 3)); // orig!*
    goto v_19769;
v_19770:
    goto v_19766;
v_19767:
    goto v_19768;
v_19769:
    v_19965 = difference2(v_19966, v_19965);
    env = stack[-8];
    goto v_19762;
v_19763:
    goto v_19759;
v_19760:
    goto v_19761;
v_19762:
    v_19965 = plus2(stack[0], v_19965);
    env = stack[-8];
    goto v_19755;
v_19756:
    goto v_19752;
v_19753:
    goto v_19754;
v_19755:
    stack[0] = plus2(stack[-1], v_19965);
    env = stack[-8];
    goto v_19745;
v_19746:
    goto v_19778;
v_19774:
    goto v_19784;
v_19780:
    v_19966 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19781;
v_19782:
    v_19965 = stack[-7];
    v_19965 = qcdr(v_19965);
    v_19965 = qcar(v_19965);
    goto v_19783;
v_19784:
    goto v_19780;
v_19781:
    goto v_19782;
v_19783:
    v_19966 = difference2(v_19966, v_19965);
    env = stack[-8];
    goto v_19775;
v_19776:
    v_19965 = qvalue(elt(env, 4)); // ycoord!*
    goto v_19777;
v_19778:
    goto v_19774;
v_19775:
    goto v_19776;
v_19777:
    v_19966 = plus2(v_19966, v_19965);
    env = stack[-8];
    goto v_19747;
v_19748:
    v_19965 = stack[-7];
    v_19965 = qcar(v_19965);
    v_19965 = qcar(v_19965);
    goto v_19749;
v_19750:
    goto v_19744;
v_19745:
    goto v_19746;
v_19747:
    goto v_19748;
v_19749:
    fn = elt(env, 16); // update!-pline
    stack[-1] = (*qfnn(fn))(fn, 3, stack[0], v_19966, v_19965);
    env = stack[-8];
    goto v_19739;
v_19740:
    goto v_19798;
v_19794:
    goto v_19806;
v_19800:
    goto v_19812;
v_19808:
    goto v_19809;
v_19810:
    goto v_19819;
v_19815:
    stack[0] = qvalue(elt(env, 2)); // posn!*
    goto v_19816;
v_19817:
    goto v_19826;
v_19822:
    v_19966 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19823;
v_19824:
    v_19965 = qvalue(elt(env, 3)); // orig!*
    goto v_19825;
v_19826:
    goto v_19822;
v_19823:
    goto v_19824;
v_19825:
    v_19965 = difference2(v_19966, v_19965);
    env = stack[-8];
    goto v_19818;
v_19819:
    goto v_19815;
v_19816:
    goto v_19817;
v_19818:
    v_19965 = plus2(stack[0], v_19965);
    env = stack[-8];
    goto v_19811;
v_19812:
    goto v_19808;
v_19809:
    goto v_19810;
v_19811:
    stack[0] = plus2(stack[-3], v_19965);
    env = stack[-8];
    goto v_19801;
v_19802:
    goto v_19835;
v_19831:
    v_19966 = qvalue(elt(env, 4)); // ycoord!*
    goto v_19832;
v_19833:
    v_19965 = stack[-6];
    v_19965 = qcdr(v_19965);
    v_19965 = qcdr(v_19965);
    goto v_19834;
v_19835:
    goto v_19831;
v_19832:
    goto v_19833;
v_19834:
    v_19965 = difference2(v_19966, v_19965);
    env = stack[-8];
    v_19966 = sub1(v_19965);
    env = stack[-8];
    goto v_19803;
v_19804:
    v_19965 = stack[-6];
    v_19965 = qcar(v_19965);
    v_19965 = qcar(v_19965);
    goto v_19805;
v_19806:
    goto v_19800;
v_19801:
    goto v_19802;
v_19803:
    goto v_19804;
v_19805:
    fn = elt(env, 16); // update!-pline
    v_19966 = (*qfnn(fn))(fn, 3, stack[0], v_19966, v_19965);
    env = stack[-8];
    goto v_19795;
v_19796:
    v_19965 = qvalue(elt(env, 5)); // pline!*
    goto v_19797;
v_19798:
    goto v_19794;
v_19795:
    goto v_19796;
v_19797:
    v_19965 = Lappend(nil, v_19966, v_19965);
    env = stack[-8];
    goto v_19741;
v_19742:
    goto v_19738;
v_19739:
    goto v_19740;
v_19741:
    v_19965 = Lappend(nil, stack[-1], v_19965);
    env = stack[-8];
    qvalue(elt(env, 5)) = v_19965; // pline!*
    goto v_19849;
v_19845:
    stack[0] = qvalue(elt(env, 6)); // ymin!*
    goto v_19846;
v_19847:
    goto v_19856;
v_19852:
    v_19966 = qvalue(elt(env, 4)); // ycoord!*
    goto v_19853;
v_19854:
    v_19965 = stack[-4];
    goto v_19855;
v_19856:
    goto v_19852;
v_19853:
    goto v_19854;
v_19855:
    v_19965 = difference2(v_19966, v_19965);
    env = stack[-8];
    goto v_19848;
v_19849:
    goto v_19845;
v_19846:
    goto v_19847;
v_19848:
    fn = elt(env, 17); // min
    v_19965 = (*qfn2(fn))(fn, stack[0], v_19965);
    env = stack[-8];
    qvalue(elt(env, 6)) = v_19965; // ymin!*
    goto v_19864;
v_19860:
    stack[0] = qvalue(elt(env, 7)); // ymax!*
    goto v_19861;
v_19862:
    goto v_19871;
v_19867:
    v_19966 = qvalue(elt(env, 4)); // ycoord!*
    goto v_19868;
v_19869:
    v_19965 = stack[-5];
    goto v_19870;
v_19871:
    goto v_19867;
v_19868:
    goto v_19869;
v_19870:
    v_19965 = plus2(v_19966, v_19965);
    env = stack[-8];
    goto v_19863;
v_19864:
    goto v_19860;
v_19861:
    goto v_19862;
v_19863:
    fn = elt(env, 14); // max
    v_19965 = (*qfn2(fn))(fn, stack[0], v_19965);
    env = stack[-8];
    qvalue(elt(env, 7)) = v_19965; // ymax!*
    v_19965 = elt(env, 8); // bar
    fn = elt(env, 18); // symbol
    v_19965 = (*qfn1(fn))(fn, v_19965);
    env = stack[-8];
    stack[-1] = v_19965;
    v_19965 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_19965;
v_19879:
    goto v_19891;
v_19887:
    v_19966 = stack[-2];
    goto v_19888;
v_19889:
    v_19965 = stack[0];
    goto v_19890;
v_19891:
    goto v_19887;
v_19888:
    goto v_19889;
v_19890:
    v_19965 = difference2(v_19966, v_19965);
    env = stack[-8];
    v_19965 = Lminusp(nil, v_19965);
    env = stack[-8];
    if (v_19965 == nil) goto v_19884;
    goto v_19878;
v_19884:
    v_19965 = stack[-1];
    fn = elt(env, 19); // prin2!*
    v_19965 = (*qfn1(fn))(fn, v_19965);
    env = stack[-8];
    v_19965 = stack[0];
    v_19965 = add1(v_19965);
    env = stack[-8];
    stack[0] = v_19965;
    goto v_19879;
v_19878:
    goto v_19578;
v_19580:
    goto v_19906;
v_19902:
    v_19966 = qvalue(elt(env, 1)); // spare!*
    goto v_19903;
v_19904:
    v_19965 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_19905;
v_19906:
    goto v_19902;
v_19903:
    goto v_19904;
v_19905:
    v_19965 = difference2(v_19966, v_19965);
    env = stack[-8];
    qvalue(elt(env, 1)) = v_19965; // spare!*
    v_19965 = stack[0];
    v_19965 = qcdr(v_19965);
    stack[0] = v_19965;
    v_19965 = elt(env, 9); // quotient
    if (!symbolp(v_19965)) v_19965 = nil;
    else { v_19965 = qfastgets(v_19965);
           if (v_19965 != nil) { v_19965 = elt(v_19965, 23); // infix
#ifdef RECORD_GET
             if (v_19965 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_19965 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_19965 == SPID_NOPROP) v_19965 = nil; }}
#endif
    stack[-2] = v_19965;
    v_19965 = qvalue(elt(env, 10)); // p!*!*
    if (v_19965 == nil) goto v_19916;
    goto v_19923;
v_19919:
    v_19966 = qvalue(elt(env, 10)); // p!*!*
    goto v_19920;
v_19921:
    v_19965 = stack[-2];
    goto v_19922;
v_19923:
    goto v_19919;
v_19920:
    goto v_19921;
v_19922:
    v_19965 = (LispObject)greaterp2(v_19966, v_19965);
    v_19965 = v_19965 ? lisp_true : nil;
    env = stack[-8];
    stack[-1] = v_19965;
    goto v_19914;
v_19916:
    v_19965 = nil;
    stack[-1] = v_19965;
    goto v_19914;
v_19914:
    v_19965 = stack[-1];
    if (v_19965 == nil) goto v_19932;
    v_19965 = elt(env, 11); // "("
    fn = elt(env, 19); // prin2!*
    v_19965 = (*qfn1(fn))(fn, v_19965);
    env = stack[-8];
    goto v_19930;
v_19932:
v_19930:
    goto v_19941;
v_19937:
    v_19965 = stack[0];
    v_19966 = qcar(v_19965);
    goto v_19938;
v_19939:
    v_19965 = stack[-2];
    goto v_19940;
v_19941:
    goto v_19937;
v_19938:
    goto v_19939;
v_19940:
    fn = elt(env, 20); // maprint
    v_19965 = (*qfn2(fn))(fn, v_19966, v_19965);
    env = stack[-8];
    v_19965 = elt(env, 9); // quotient
    fn = elt(env, 21); // oprin
    v_19965 = (*qfn1(fn))(fn, v_19965);
    env = stack[-8];
    goto v_19952;
v_19948:
    v_19965 = stack[0];
    v_19965 = qcdr(v_19965);
    v_19965 = qcar(v_19965);
    fn = elt(env, 22); // negnumberchk
    v_19966 = (*qfn1(fn))(fn, v_19965);
    env = stack[-8];
    goto v_19949;
v_19950:
    v_19965 = stack[-2];
    goto v_19951;
v_19952:
    goto v_19948;
v_19949:
    goto v_19950;
v_19951:
    fn = elt(env, 20); // maprint
    v_19965 = (*qfn2(fn))(fn, v_19966, v_19965);
    env = stack[-8];
    v_19965 = stack[-1];
    if (v_19965 == nil) goto v_19961;
    v_19965 = elt(env, 12); // ")"
    fn = elt(env, 19); // prin2!*
    v_19965 = (*qfn1(fn))(fn, v_19965);
    goto v_19959;
v_19961:
v_19959:
    goto v_19578;
v_19578:
    v_19965 = nil;
    return onevalue(v_19965);
}



// Code for !*f2di

static LispObject CC_Hf2di(LispObject env,
                         LispObject v_19549, LispObject v_19550)
{
    env = qenv(env);
    LispObject v_19782, v_19783;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19550,v_19549);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19549,v_19550);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    v_19782 = v_19550;
    stack[-5] = v_19549;
// end of prologue
// Binding varlist!*
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
    qvalue(elt(env, 1)) = v_19782; // varlist!*
    v_19782 = stack[-5];
    if (v_19782 == nil) goto v_19558;
    else goto v_19559;
v_19558:
    v_19782 = nil;
    goto v_19557;
v_19559:
    v_19782 = stack[-5];
    if (!consp(v_19782)) goto v_19566;
    else goto v_19567;
v_19566:
    v_19782 = lisp_true;
    goto v_19565;
v_19567:
    v_19782 = stack[-5];
    v_19782 = qcar(v_19782);
    v_19782 = (consp(v_19782) ? nil : lisp_true);
    goto v_19565;
    v_19782 = nil;
v_19565:
    if (v_19782 == nil) goto v_19563;
    goto v_19581;
v_19577:
    v_19782 = qvalue(elt(env, 1)); // varlist!*
    stack[-3] = v_19782;
    v_19782 = stack[-3];
    if (v_19782 == nil) goto v_19592;
    else goto v_19593;
v_19592:
    v_19782 = nil;
    goto v_19587;
v_19593:
    v_19782 = (LispObject)0+TAG_FIXNUM; // 0
    v_19782 = ncons(v_19782);
    env = stack[-7];
    stack[-1] = v_19782;
    stack[-2] = v_19782;
v_19588:
    v_19782 = stack[-3];
    v_19782 = qcdr(v_19782);
    stack[-3] = v_19782;
    v_19782 = stack[-3];
    if (v_19782 == nil) goto v_19605;
    else goto v_19606;
v_19605:
    v_19782 = stack[-2];
    goto v_19587;
v_19606:
    goto v_19614;
v_19610:
    stack[0] = stack[-1];
    goto v_19611;
v_19612:
    v_19782 = (LispObject)0+TAG_FIXNUM; // 0
    v_19782 = ncons(v_19782);
    env = stack[-7];
    goto v_19613;
v_19614:
    goto v_19610;
v_19611:
    goto v_19612;
v_19613:
    v_19782 = Lrplacd(nil, stack[0], v_19782);
    env = stack[-7];
    v_19782 = stack[-1];
    v_19782 = qcdr(v_19782);
    stack[-1] = v_19782;
    goto v_19588;
v_19587:
    fn = elt(env, 2); // addgt
    v_19783 = (*qfn1(fn))(fn, v_19782);
    env = stack[-7];
    goto v_19578;
v_19579:
    v_19782 = stack[-5];
    goto v_19580;
v_19581:
    goto v_19577;
v_19578:
    goto v_19579;
v_19580:
    v_19782 = cons(v_19783, v_19782);
    env = stack[-7];
    v_19782 = ncons(v_19782);
    goto v_19557;
v_19563:
    goto v_19631;
v_19627:
    goto v_19640;
v_19636:
    v_19782 = stack[-5];
    v_19782 = qcar(v_19782);
    v_19782 = qcar(v_19782);
    v_19783 = qcar(v_19782);
    goto v_19637;
v_19638:
    v_19782 = qvalue(elt(env, 1)); // varlist!*
    goto v_19639;
v_19640:
    goto v_19636;
v_19637:
    goto v_19638;
v_19639:
    v_19782 = Lmember(nil, v_19783, v_19782);
    if (v_19782 == nil) goto v_19635;
    goto v_19652;
v_19648:
    goto v_19658;
v_19654:
    v_19782 = stack[-5];
    v_19782 = qcar(v_19782);
    v_19783 = qcdr(v_19782);
    goto v_19655;
v_19656:
    v_19782 = qvalue(elt(env, 1)); // varlist!*
    goto v_19657;
v_19658:
    goto v_19654;
v_19655:
    goto v_19656;
v_19657:
    stack[-4] = CC_Hf2di(elt(env, 0), v_19783, v_19782);
    env = stack[-7];
    goto v_19649;
v_19650:
    v_19782 = qvalue(elt(env, 1)); // varlist!*
    stack[-3] = v_19782;
    v_19782 = stack[-3];
    if (v_19782 == nil) goto v_19673;
    else goto v_19674;
v_19673:
    v_19782 = nil;
    goto v_19668;
v_19674:
    v_19782 = stack[-3];
    v_19782 = qcar(v_19782);
    goto v_19689;
v_19685:
    v_19783 = v_19782;
    goto v_19686;
v_19687:
    v_19782 = stack[-5];
    v_19782 = qcar(v_19782);
    v_19782 = qcar(v_19782);
    v_19782 = qcar(v_19782);
    goto v_19688;
v_19689:
    goto v_19685;
v_19686:
    goto v_19687;
v_19688:
    if (equal(v_19783, v_19782)) goto v_19683;
    else goto v_19684;
v_19683:
    v_19782 = stack[-5];
    v_19782 = qcar(v_19782);
    v_19782 = qcar(v_19782);
    v_19782 = qcdr(v_19782);
    goto v_19682;
v_19684:
    v_19782 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19682;
    v_19782 = nil;
v_19682:
    v_19782 = ncons(v_19782);
    env = stack[-7];
    stack[-1] = v_19782;
    stack[-2] = v_19782;
v_19669:
    v_19782 = stack[-3];
    v_19782 = qcdr(v_19782);
    stack[-3] = v_19782;
    v_19782 = stack[-3];
    if (v_19782 == nil) goto v_19706;
    else goto v_19707;
v_19706:
    v_19782 = stack[-2];
    goto v_19668;
v_19707:
    goto v_19715;
v_19711:
    stack[0] = stack[-1];
    goto v_19712;
v_19713:
    v_19782 = stack[-3];
    v_19782 = qcar(v_19782);
    goto v_19729;
v_19725:
    v_19783 = v_19782;
    goto v_19726;
v_19727:
    v_19782 = stack[-5];
    v_19782 = qcar(v_19782);
    v_19782 = qcar(v_19782);
    v_19782 = qcar(v_19782);
    goto v_19728;
v_19729:
    goto v_19725;
v_19726:
    goto v_19727;
v_19728:
    if (equal(v_19783, v_19782)) goto v_19723;
    else goto v_19724;
v_19723:
    v_19782 = stack[-5];
    v_19782 = qcar(v_19782);
    v_19782 = qcar(v_19782);
    v_19782 = qcdr(v_19782);
    goto v_19722;
v_19724:
    v_19782 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19722;
    v_19782 = nil;
v_19722:
    v_19782 = ncons(v_19782);
    env = stack[-7];
    goto v_19714;
v_19715:
    goto v_19711;
v_19712:
    goto v_19713;
v_19714:
    v_19782 = Lrplacd(nil, stack[0], v_19782);
    env = stack[-7];
    v_19782 = stack[-1];
    v_19782 = qcdr(v_19782);
    stack[-1] = v_19782;
    goto v_19669;
v_19668:
    fn = elt(env, 2); // addgt
    v_19782 = (*qfn1(fn))(fn, v_19782);
    env = stack[-7];
    goto v_19651;
v_19652:
    goto v_19648;
v_19649:
    goto v_19650;
v_19651:
    fn = elt(env, 3); // pdmult
    v_19782 = (*qfn2(fn))(fn, stack[-4], v_19782);
    env = stack[-7];
    stack[0] = v_19782;
    goto v_19633;
v_19635:
    goto v_19751;
v_19747:
    goto v_19757;
v_19753:
    v_19782 = stack[-5];
    v_19782 = qcar(v_19782);
    v_19783 = qcdr(v_19782);
    goto v_19754;
v_19755:
    v_19782 = qvalue(elt(env, 1)); // varlist!*
    goto v_19756;
v_19757:
    goto v_19753;
v_19754:
    goto v_19755;
v_19756:
    stack[0] = CC_Hf2di(elt(env, 0), v_19783, v_19782);
    env = stack[-7];
    goto v_19748;
v_19749:
    goto v_19768;
v_19764:
    v_19782 = stack[-5];
    v_19782 = qcar(v_19782);
    v_19783 = qcar(v_19782);
    goto v_19765;
v_19766:
    v_19782 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19767;
v_19768:
    goto v_19764;
v_19765:
    goto v_19766;
v_19767:
    v_19782 = cons(v_19783, v_19782);
    env = stack[-7];
    v_19782 = ncons(v_19782);
    env = stack[-7];
    goto v_19750;
v_19751:
    goto v_19747;
v_19748:
    goto v_19749;
v_19750:
    fn = elt(env, 4); // pcmult
    v_19782 = (*qfn2(fn))(fn, stack[0], v_19782);
    env = stack[-7];
    stack[0] = v_19782;
    goto v_19633;
    stack[0] = nil;
v_19633:
    goto v_19628;
v_19629:
    goto v_19778;
v_19774:
    v_19782 = stack[-5];
    v_19783 = qcdr(v_19782);
    goto v_19775;
v_19776:
    v_19782 = qvalue(elt(env, 1)); // varlist!*
    goto v_19777;
v_19778:
    goto v_19774;
v_19775:
    goto v_19776;
v_19777:
    v_19782 = CC_Hf2di(elt(env, 0), v_19783, v_19782);
    env = stack[-7];
    goto v_19630;
v_19631:
    goto v_19627;
v_19628:
    goto v_19629;
v_19630:
    fn = elt(env, 5); // psum
    v_19782 = (*qfn2(fn))(fn, stack[0], v_19782);
    goto v_19557;
    v_19782 = nil;
v_19557:
    ;}  // end of a binding scope
    return onevalue(v_19782);
}



// Code for list_is_all_free

static LispObject CC_list_is_all_free(LispObject env,
                         LispObject v_19548)
{
    env = qenv(env);
    LispObject v_19569;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19548);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_19548;
// end of prologue
v_19552:
    v_19569 = stack[0];
    if (v_19569 == nil) goto v_19555;
    else goto v_19556;
v_19555:
    v_19569 = lisp_true;
    goto v_19551;
v_19556:
    v_19569 = stack[0];
    v_19569 = qcar(v_19569);
    fn = elt(env, 1); // nodum_varp
    v_19569 = (*qfn1(fn))(fn, v_19569);
    env = stack[-1];
    if (v_19569 == nil) goto v_19560;
    v_19569 = stack[0];
    v_19569 = qcdr(v_19569);
    stack[0] = v_19569;
    goto v_19552;
v_19560:
    v_19569 = nil;
    goto v_19551;
    v_19569 = nil;
v_19551:
    return onevalue(v_19569);
}



// Code for msolve!-poly1

static LispObject CC_msolveKpoly1(LispObject env,
                         LispObject v_19548, LispObject v_19549)
{
    env = qenv(env);
    LispObject v_19852, v_19853, v_19854;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19549,v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19548,v_19549);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_19549;
    stack[-5] = v_19548;
// end of prologue
    v_19852 = stack[-5];
    if (!consp(v_19852)) goto v_19563;
    else goto v_19564;
v_19563:
    v_19852 = lisp_true;
    goto v_19562;
v_19564:
    v_19852 = stack[-5];
    v_19852 = qcar(v_19852);
    v_19852 = (consp(v_19852) ? nil : lisp_true);
    goto v_19562;
    v_19852 = nil;
v_19562:
    if (v_19852 == nil) goto v_19560;
    goto v_19558;
v_19560:
    goto v_19579;
v_19575:
    v_19852 = stack[-5];
    v_19852 = qcar(v_19852);
    v_19852 = qcar(v_19852);
    v_19853 = qcdr(v_19852);
    goto v_19576;
v_19577:
    v_19852 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_19578;
v_19579:
    goto v_19575;
v_19576:
    goto v_19577;
v_19578:
    if (v_19853 == v_19852) goto v_19573;
    else goto v_19574;
v_19573:
    v_19852 = stack[-5];
    v_19852 = qcar(v_19852);
    v_19852 = qcdr(v_19852);
    fn = elt(env, 4); // safe!-modrecip
    v_19852 = (*qfn1(fn))(fn, v_19852);
    env = stack[-7];
    stack[0] = v_19852;
    v_19852 = nil;
    qvalue(elt(env, 1)) = v_19852; // erfg!*
    v_19852 = stack[0];
    if (v_19852 == nil) goto v_19592;
    else goto v_19593;
v_19592:
    goto v_19555;
v_19593:
    goto v_19601;
v_19597:
    goto v_19598;
v_19599:
    v_19852 = stack[-5];
    v_19852 = qcdr(v_19852);
    fn = elt(env, 5); // negf
    v_19852 = (*qfn1(fn))(fn, v_19852);
    env = stack[-7];
    goto v_19600;
v_19601:
    goto v_19597;
v_19598:
    goto v_19599;
v_19600:
    fn = elt(env, 6); // multf
    v_19852 = (*qfn2(fn))(fn, stack[0], v_19852);
    env = stack[-7];
    fn = elt(env, 7); // moduntag
    v_19852 = (*qfn1(fn))(fn, v_19852);
    env = stack[-7];
    stack[0] = v_19852;
    v_19852 = stack[0];
    if (v_19852 == nil) goto v_19609;
    goto v_19619;
v_19615:
    v_19853 = stack[0];
    goto v_19616;
v_19617:
    v_19852 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19618;
v_19619:
    goto v_19615;
v_19616:
    goto v_19617;
v_19618:
    v_19852 = (LispObject)lessp2(v_19853, v_19852);
    v_19852 = v_19852 ? lisp_true : nil;
    env = stack[-7];
    if (v_19852 == nil) goto v_19613;
    else goto v_19612;
v_19613:
    goto v_19628;
v_19624:
    v_19853 = stack[0];
    goto v_19625;
v_19626:
    v_19852 = qvalue(elt(env, 2)); // current!-modulus
    goto v_19627;
v_19628:
    goto v_19624;
v_19625:
    goto v_19626;
v_19627:
    v_19852 = (LispObject)greaterp2(v_19853, v_19852);
    v_19852 = v_19852 ? lisp_true : nil;
    env = stack[-7];
    if (v_19852 == nil) goto v_19622;
    else goto v_19612;
v_19622:
    goto v_19609;
v_19612:
    v_19852 = stack[0];
    fn = elt(env, 8); // general!-modular!-number
    v_19852 = (*qfn1(fn))(fn, v_19852);
    env = stack[-7];
    stack[0] = v_19852;
    goto v_19607;
v_19609:
v_19607:
    v_19852 = stack[0];
    v_19852 = ncons(v_19852);
    env = stack[-7];
    stack[0] = v_19852;
    goto v_19556;
v_19574:
v_19558:
v_19555:
    goto v_19642;
v_19636:
    v_19854 = stack[-5];
    goto v_19637;
v_19638:
    v_19853 = stack[-4];
    goto v_19639;
v_19640:
    v_19852 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19641;
v_19642:
    goto v_19636;
v_19637:
    goto v_19638;
v_19639:
    goto v_19640;
v_19641:
    fn = elt(env, 9); // lowestdeg
    v_19852 = (*qfnn(fn))(fn, 3, v_19854, v_19853, v_19852);
    env = stack[-7];
    stack[-6] = v_19852;
    goto v_19655;
v_19651:
    v_19853 = stack[-6];
    goto v_19652;
v_19653:
    v_19852 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19654;
v_19655:
    goto v_19651;
v_19652:
    goto v_19653;
v_19654:
    v_19852 = (LispObject)greaterp2(v_19853, v_19852);
    v_19852 = v_19852 ? lisp_true : nil;
    env = stack[-7];
    if (v_19852 == nil) goto v_19649;
    goto v_19663;
v_19659:
    stack[0] = stack[-5];
    goto v_19660;
v_19661:
    goto v_19673;
v_19667:
    v_19854 = elt(env, 3); // expt
    goto v_19668;
v_19669:
    v_19853 = stack[-4];
    goto v_19670;
v_19671:
    v_19852 = stack[-6];
    goto v_19672;
v_19673:
    goto v_19667;
v_19668:
    goto v_19669;
v_19670:
    goto v_19671;
v_19672:
    v_19852 = list3(v_19854, v_19853, v_19852);
    env = stack[-7];
    fn = elt(env, 10); // simp
    v_19852 = (*qfn1(fn))(fn, v_19852);
    env = stack[-7];
    v_19852 = qcar(v_19852);
    goto v_19662;
v_19663:
    goto v_19659;
v_19660:
    goto v_19661;
v_19662:
    fn = elt(env, 11); // quotf
    v_19852 = (*qfn2(fn))(fn, stack[0], v_19852);
    env = stack[-7];
    stack[-5] = v_19852;
    goto v_19647;
v_19649:
v_19647:
    v_19852 = stack[-5];
    fn = elt(env, 7); // moduntag
    v_19852 = (*qfn1(fn))(fn, v_19852);
    env = stack[-7];
    fn = elt(env, 12); // general!-reduce!-mod!-p
    v_19852 = (*qfn1(fn))(fn, v_19852);
    env = stack[-7];
    stack[-5] = v_19852;
    v_19852 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_19852;
v_19686:
    goto v_19699;
v_19695:
    v_19852 = qvalue(elt(env, 2)); // current!-modulus
    v_19853 = sub1(v_19852);
    env = stack[-7];
    goto v_19696;
v_19697:
    v_19852 = stack[-3];
    goto v_19698;
v_19699:
    goto v_19695;
v_19696:
    goto v_19697;
v_19698:
    v_19852 = difference2(v_19853, v_19852);
    env = stack[-7];
    v_19852 = Lminusp(nil, v_19852);
    env = stack[-7];
    if (v_19852 == nil) goto v_19692;
    v_19852 = nil;
    goto v_19685;
v_19692:
    goto v_19715;
v_19709:
    v_19854 = stack[-5];
    goto v_19710;
v_19711:
    v_19853 = stack[-4];
    goto v_19712;
v_19713:
    v_19852 = stack[-3];
    goto v_19714;
v_19715:
    goto v_19709;
v_19710:
    goto v_19711;
v_19712:
    goto v_19713;
v_19714:
    fn = elt(env, 13); // general!-evaluate!-mod!-p
    v_19852 = (*qfnn(fn))(fn, 3, v_19854, v_19853, v_19852);
    env = stack[-7];
    if (v_19852 == nil) goto v_19706;
    else goto v_19707;
v_19706:
    v_19852 = stack[-3];
    v_19852 = ncons(v_19852);
    env = stack[-7];
    goto v_19705;
v_19707:
    v_19852 = nil;
v_19705:
    stack[-2] = v_19852;
    v_19852 = stack[-2];
    fn = elt(env, 14); // lastpair
    v_19852 = (*qfn1(fn))(fn, v_19852);
    env = stack[-7];
    stack[-1] = v_19852;
    v_19852 = stack[-3];
    v_19852 = add1(v_19852);
    env = stack[-7];
    stack[-3] = v_19852;
    v_19852 = stack[-1];
    if (!consp(v_19852)) goto v_19727;
    else goto v_19728;
v_19727:
    goto v_19686;
v_19728:
v_19687:
    goto v_19740;
v_19736:
    v_19852 = qvalue(elt(env, 2)); // current!-modulus
    v_19853 = sub1(v_19852);
    env = stack[-7];
    goto v_19737;
v_19738:
    v_19852 = stack[-3];
    goto v_19739;
v_19740:
    goto v_19736;
v_19737:
    goto v_19738;
v_19739:
    v_19852 = difference2(v_19853, v_19852);
    env = stack[-7];
    v_19852 = Lminusp(nil, v_19852);
    env = stack[-7];
    if (v_19852 == nil) goto v_19733;
    v_19852 = stack[-2];
    goto v_19685;
v_19733:
    goto v_19750;
v_19746:
    stack[0] = stack[-1];
    goto v_19747;
v_19748:
    goto v_19763;
v_19757:
    v_19854 = stack[-5];
    goto v_19758;
v_19759:
    v_19853 = stack[-4];
    goto v_19760;
v_19761:
    v_19852 = stack[-3];
    goto v_19762;
v_19763:
    goto v_19757;
v_19758:
    goto v_19759;
v_19760:
    goto v_19761;
v_19762:
    fn = elt(env, 13); // general!-evaluate!-mod!-p
    v_19852 = (*qfnn(fn))(fn, 3, v_19854, v_19853, v_19852);
    env = stack[-7];
    if (v_19852 == nil) goto v_19754;
    else goto v_19755;
v_19754:
    v_19852 = stack[-3];
    v_19852 = ncons(v_19852);
    env = stack[-7];
    goto v_19753;
v_19755:
    v_19852 = nil;
v_19753:
    goto v_19749;
v_19750:
    goto v_19746;
v_19747:
    goto v_19748;
v_19749:
    v_19852 = Lrplacd(nil, stack[0], v_19852);
    env = stack[-7];
    v_19852 = stack[-1];
    fn = elt(env, 14); // lastpair
    v_19852 = (*qfn1(fn))(fn, v_19852);
    env = stack[-7];
    stack[-1] = v_19852;
    v_19852 = stack[-3];
    v_19852 = add1(v_19852);
    env = stack[-7];
    stack[-3] = v_19852;
    goto v_19687;
v_19685:
    stack[0] = v_19852;
    goto v_19782;
v_19778:
    v_19853 = stack[-6];
    goto v_19779;
v_19780:
    v_19852 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_19781;
v_19782:
    goto v_19778;
v_19779:
    goto v_19780;
v_19781:
    v_19852 = (LispObject)greaterp2(v_19853, v_19852);
    v_19852 = v_19852 ? lisp_true : nil;
    env = stack[-7];
    if (v_19852 == nil) goto v_19776;
    goto v_19790;
v_19786:
    goto v_19787;
v_19788:
    v_19852 = nil;
    v_19852 = ncons(v_19852);
    env = stack[-7];
    goto v_19789;
v_19790:
    goto v_19786;
v_19787:
    goto v_19788;
v_19789:
    v_19852 = Lappend(nil, stack[0], v_19852);
    env = stack[-7];
    stack[0] = v_19852;
    goto v_19774;
v_19776:
v_19774:
v_19556:
    v_19852 = stack[0];
    stack[-5] = v_19852;
    v_19852 = stack[-5];
    if (v_19852 == nil) goto v_19803;
    else goto v_19804;
v_19803:
    v_19852 = nil;
    goto v_19798;
v_19804:
    v_19852 = stack[-5];
    v_19852 = qcar(v_19852);
    goto v_19817;
v_19813:
    stack[0] = stack[-4];
    goto v_19814;
v_19815:
    fn = elt(env, 15); // prepf
    v_19852 = (*qfn1(fn))(fn, v_19852);
    env = stack[-7];
    goto v_19816;
v_19817:
    goto v_19813;
v_19814:
    goto v_19815;
v_19816:
    v_19852 = cons(stack[0], v_19852);
    env = stack[-7];
    v_19852 = ncons(v_19852);
    env = stack[-7];
    v_19852 = ncons(v_19852);
    env = stack[-7];
    stack[-2] = v_19852;
    stack[-3] = v_19852;
v_19799:
    v_19852 = stack[-5];
    v_19852 = qcdr(v_19852);
    stack[-5] = v_19852;
    v_19852 = stack[-5];
    if (v_19852 == nil) goto v_19825;
    else goto v_19826;
v_19825:
    v_19852 = stack[-3];
    goto v_19798;
v_19826:
    goto v_19834;
v_19830:
    stack[-1] = stack[-2];
    goto v_19831;
v_19832:
    v_19852 = stack[-5];
    v_19852 = qcar(v_19852);
    goto v_19846;
v_19842:
    stack[0] = stack[-4];
    goto v_19843;
v_19844:
    fn = elt(env, 15); // prepf
    v_19852 = (*qfn1(fn))(fn, v_19852);
    env = stack[-7];
    goto v_19845;
v_19846:
    goto v_19842;
v_19843:
    goto v_19844;
v_19845:
    v_19852 = cons(stack[0], v_19852);
    env = stack[-7];
    v_19852 = ncons(v_19852);
    env = stack[-7];
    v_19852 = ncons(v_19852);
    env = stack[-7];
    goto v_19833;
v_19834:
    goto v_19830;
v_19831:
    goto v_19832;
v_19833:
    v_19852 = Lrplacd(nil, stack[-1], v_19852);
    env = stack[-7];
    v_19852 = stack[-2];
    v_19852 = qcdr(v_19852);
    stack[-2] = v_19852;
    goto v_19799;
v_19798:
    return onevalue(v_19852);
}



// Code for reduce!-mod!-eigf

static LispObject CC_reduceKmodKeigf(LispObject env,
                         LispObject v_19548, LispObject v_19549)
{
    env = qenv(env);
    LispObject v_19583, v_19584;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_19549,v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_19548,v_19549);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_19549;
    v_19583 = v_19548;
// end of prologue
    v_19584 = qvalue(elt(env, 1)); // !*sub2
// Binding !*sub2
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = v_19584; // !*sub2
    goto v_19559;
v_19555:
    goto v_19565;
v_19561:
    v_19584 = v_19583;
    v_19584 = qcar(v_19584);
    stack[0] = qcar(v_19584);
    goto v_19562;
v_19563:
    goto v_19576;
v_19572:
    v_19584 = v_19583;
    v_19584 = qcdr(v_19584);
    goto v_19573;
v_19574:
    v_19583 = qcar(v_19583);
    v_19583 = qcdr(v_19583);
    goto v_19575;
v_19576:
    goto v_19572;
v_19573:
    goto v_19574;
v_19575:
    v_19583 = cons(v_19584, v_19583);
    env = stack[-3];
    fn = elt(env, 2); // cancel
    v_19583 = (*qfn1(fn))(fn, v_19583);
    env = stack[-3];
    fn = elt(env, 3); // negsq
    v_19583 = (*qfn1(fn))(fn, v_19583);
    env = stack[-3];
    goto v_19564;
v_19565:
    goto v_19561;
v_19562:
    goto v_19563;
v_19564:
    v_19584 = cons(stack[0], v_19583);
    env = stack[-3];
    goto v_19556;
v_19557:
    v_19583 = stack[-1];
    goto v_19558;
v_19559:
    goto v_19555;
v_19556:
    goto v_19557;
v_19558:
    fn = elt(env, 4); // reduce!-eival!-powers
    v_19583 = (*qfn2(fn))(fn, v_19584, v_19583);
    env = stack[-3];
    fn = elt(env, 5); // subs2
    v_19583 = (*qfn1(fn))(fn, v_19583);
    ;}  // end of a binding scope
    return onevalue(v_19583);
}



// Code for !*a2k

static LispObject CC_Ha2k(LispObject env,
                         LispObject v_19548)
{
    env = qenv(env);
    LispObject v_19583, v_19584;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_19548);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_19548;
// end of prologue
    v_19583 = stack[0];
    fn = elt(env, 2); // simp!*
    v_19583 = (*qfn1(fn))(fn, v_19583);
    env = stack[-2];
    stack[-1] = v_19583;
    fn = elt(env, 3); // kernp
    v_19583 = (*qfn1(fn))(fn, v_19583);
    env = stack[-2];
    if (v_19583 == nil) goto v_19556;
    v_19583 = stack[-1];
    v_19583 = qcar(v_19583);
    v_19583 = qcar(v_19583);
    v_19583 = qcar(v_19583);
    v_19583 = qcar(v_19583);
    goto v_19552;
v_19556:
    goto v_19572;
v_19568:
    v_19583 = stack[0];
    if (v_19583 == nil) goto v_19575;
    else goto v_19576;
v_19575:
    v_19583 = (LispObject)0+TAG_FIXNUM; // 0
    v_19584 = v_19583;
    goto v_19574;
v_19576:
    v_19583 = stack[0];
    v_19584 = v_19583;
    goto v_19574;
    v_19584 = nil;
v_19574:
    goto v_19569;
v_19570:
    v_19583 = elt(env, 1); // kernel
    goto v_19571;
v_19572:
    goto v_19568;
v_19569:
    goto v_19570;
v_19571:
    fn = elt(env, 4); // typerr
    v_19583 = (*qfn2(fn))(fn, v_19584, v_19583);
    goto v_19554;
v_19554:
    v_19583 = nil;
v_19552:
    return onevalue(v_19583);
}



// Code for lalr_warn_shift_reduce_conflict

static LispObject CC_lalr_warn_shift_reduce_conflict(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_19590;
    LispObject fn;
    LispObject v_19550, v_19549, v_19548;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "lalr_warn_shift_reduce_conflict");
    va_start(aa, nargs);
    v_19548 = va_arg(aa, LispObject);
    v_19549 = va_arg(aa, LispObject);
    v_19550 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_19550,v_19549,v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_19548,v_19549,v_19550);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_19550;
    stack[-1] = v_19549;
    stack[-2] = v_19548;
// end of prologue
    v_19590 = Lposn(nil, 0);
    env = stack[-3];
    v_19590 = (LispObject)zerop(v_19590);
    v_19590 = v_19590 ? lisp_true : nil;
    env = stack[-3];
    if (v_19590 == nil) goto v_19554;
    else goto v_19555;
v_19554:
    v_19590 = Lterpri(nil, 0);
    env = stack[-3];
    goto v_19553;
v_19555:
v_19553:
    v_19590 = elt(env, 1); // "+++ Shift/reduce conflict in itemset #"
    v_19590 = Lprinc(nil, v_19590);
    env = stack[-3];
    v_19590 = stack[0];
    v_19590 = Lprin(nil, v_19590);
    env = stack[-3];
    v_19590 = elt(env, 2); // " on lookahead "
    v_19590 = Lprinc(nil, v_19590);
    env = stack[-3];
    v_19590 = stack[-2];
    v_19590 = qcar(v_19590);
    fn = elt(env, 6); // lalr_prin_symbol
    v_19590 = (*qfn1(fn))(fn, v_19590);
    env = stack[-3];
    v_19590 = Lterpri(nil, 0);
    env = stack[-3];
    v_19590 = elt(env, 3); // "Reduce: "
    v_19590 = Lprinc(nil, v_19590);
    env = stack[-3];
    v_19590 = stack[-1];
    v_19590 = qcdr(v_19590);
    v_19590 = qcar(v_19590);
    v_19590 = qcdr(v_19590);
    v_19590 = qcar(v_19590);
    fn = elt(env, 7); // lalr_prin_production
    v_19590 = (*qfn1(fn))(fn, v_19590);
    env = stack[-3];
    v_19590 = Lterpri(nil, 0);
    env = stack[-3];
    v_19590 = elt(env, 4); // "Shift: to state #"
    v_19590 = Lprinc(nil, v_19590);
    env = stack[-3];
    v_19590 = stack[-2];
    v_19590 = qcdr(v_19590);
    v_19590 = qcar(v_19590);
    v_19590 = qcdr(v_19590);
    v_19590 = qcar(v_19590);
    v_19590 = Lprin(nil, v_19590);
    env = stack[-3];
    v_19590 = Lterpri(nil, 0);
    env = stack[-3];
    v_19590 = elt(env, 5); // "Resolved in favour of the shift operation"
    v_19590 = Lprintc(nil, v_19590);
        return Lterpri(nil, 0);
}



// Code for rl_transform

static LispObject CC_rl_transform(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_19590, v_19591, v_19592, v_19593, v_19594, v_19595, v_19596;
    LispObject fn;
    LispObject v_19554, v_19553, v_19552, v_19551, v_19550, v_19549, v_19548;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 7, "rl_transform");
    va_start(aa, nargs);
    v_19548 = va_arg(aa, LispObject);
    v_19549 = va_arg(aa, LispObject);
    v_19550 = va_arg(aa, LispObject);
    v_19551 = va_arg(aa, LispObject);
    v_19552 = va_arg(aa, LispObject);
    v_19553 = va_arg(aa, LispObject);
    v_19554 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_19554,v_19553,v_19552,v_19551,v_19550,v_19549);
        push(v_19548);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_19548,v_19549,v_19550,v_19551,v_19552,v_19553);
        pop(v_19554);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_19590 = v_19554;
    v_19591 = v_19553;
    v_19592 = v_19552;
    v_19593 = v_19551;
    v_19594 = v_19550;
    v_19595 = v_19549;
    v_19596 = v_19548;
// end of prologue
    goto v_19561;
v_19557:
    stack[-3] = qvalue(elt(env, 1)); // rl_transform!*
    goto v_19558;
v_19559:
    goto v_19572;
v_19564:
    stack[-2] = v_19596;
    goto v_19565;
v_19566:
    stack[-1] = v_19595;
    goto v_19567;
v_19568:
    stack[0] = v_19594;
    goto v_19569;
v_19570:
    goto v_19585;
v_19577:
    goto v_19578;
v_19579:
    goto v_19580;
v_19581:
    goto v_19582;
v_19583:
    goto v_19584;
v_19585:
    goto v_19577;
v_19578:
    goto v_19579;
v_19580:
    goto v_19581;
v_19582:
    goto v_19583;
v_19584:
    v_19590 = list4(v_19593, v_19592, v_19591, v_19590);
    env = stack[-4];
    goto v_19571;
v_19572:
    goto v_19564;
v_19565:
    goto v_19566;
v_19567:
    goto v_19568;
v_19569:
    goto v_19570;
v_19571:
    v_19590 = list3star(stack[-2], stack[-1], stack[0], v_19590);
    env = stack[-4];
    goto v_19560;
v_19561:
    goto v_19557;
v_19558:
    goto v_19559;
v_19560:
    {
        LispObject v_19601 = stack[-3];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_19601, v_19590);
    }
}



setup_type const u35_setup[] =
{
    {"matsm1",                  CC_matsm1,      TOO_MANY_1,    WRONG_NO_1},
    {"recaliasbacksubst",       TOO_FEW_2,      CC_recaliasbacksubst,WRONG_NO_2},
    {"amatch",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_amatch},
    {"fieldp",                  CC_fieldp,      TOO_MANY_1,    WRONG_NO_1},
    {"po:statep",               CC_poTstatep,   TOO_MANY_1,    WRONG_NO_1},
    {"color-roads",             TOO_FEW_2,      CC_colorKroads,WRONG_NO_2},
    {"realvaluedp",             CC_realvaluedp, TOO_MANY_1,    WRONG_NO_1},
    {"greaterpcdr",             TOO_FEW_2,      CC_greaterpcdr,WRONG_NO_2},
    {"subs2chk",                CC_subs2chk,    TOO_MANY_1,    WRONG_NO_1},
    {"fs:prin",                 CC_fsTprin,     TOO_MANY_1,    WRONG_NO_1},
    {"mo_zero?",                CC_mo_zeroW,    TOO_MANY_1,    WRONG_NO_1},
    {"dv_ind2var",              CC_dv_ind2var,  TOO_MANY_1,    WRONG_NO_1},
    {"outer-simpsqrt",          CC_outerKsimpsqrt,TOO_MANY_1,  WRONG_NO_1},
    {"msolve-polyn",            TOO_FEW_2,      CC_msolveKpolyn,WRONG_NO_2},
    {"find-null-space",         TOO_FEW_2,      CC_findKnullKspace,WRONG_NO_2},
    {"ofsf_ir2atl",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_ir2atl},
    {"plusdf",                  TOO_FEW_2,      CC_plusdf,     WRONG_NO_2},
    {"gen+can+bas",             CC_genLcanLbas, TOO_MANY_1,    WRONG_NO_1},
    {"cl_susicpknowl",          CC_cl_susicpknowl,TOO_MANY_1,  WRONG_NO_1},
    {"vectorml",                CC_vectorml,    TOO_MANY_1,    WRONG_NO_1},
    {"delyzz",                  TOO_FEW_2,      CC_delyzz,     WRONG_NO_2},
    {"dipsimpcont",             CC_dipsimpcont, TOO_MANY_1,    WRONG_NO_1},
    {"dipprodin",               TOO_FEW_2,      CC_dipprodin,  WRONG_NO_2},
    {"unplus",                  CC_unplus,      TOO_MANY_1,    WRONG_NO_1},
    {"convprc2",                TOO_FEW_2,      CC_convprc2,   WRONG_NO_2},
    {"color-strand",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_colorKstrand},
    {"ratfunpri1",              CC_ratfunpri1,  TOO_MANY_1,    WRONG_NO_1},
    {"*f2di",                   TOO_FEW_2,      CC_Hf2di,      WRONG_NO_2},
    {"list_is_all_free",        CC_list_is_all_free,TOO_MANY_1,WRONG_NO_1},
    {"msolve-poly1",            TOO_FEW_2,      CC_msolveKpoly1,WRONG_NO_2},
    {"reduce-mod-eigf",         TOO_FEW_2,      CC_reduceKmodKeigf,WRONG_NO_2},
    {"*a2k",                    CC_Ha2k,        TOO_MANY_1,    WRONG_NO_1},
    {"lalr_warn_shift_reduce_conflict",WRONG_NO_NA,WRONG_NO_NB,(n_args *)CC_lalr_warn_shift_reduce_conflict},
    {"rl_transform",            WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rl_transform},
    {NULL, (one_args *)"u35", (two_args *)"146037 1035370 2203483", 0}
};

// end of generated code
