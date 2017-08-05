
// $destdir/u12.c        Machine generated C code

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



// Code for totalcompare

static LispObject CC_totalcompare(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6431, v_6432, v_6433;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_6344;
    stack[-1] = v_6343;
// end of prologue
v_6342:
    goto v_6354;
v_6350:
    v_6432 = stack[-1];
    goto v_6351;
v_6352:
    v_6431 = stack[0];
    goto v_6353;
v_6354:
    goto v_6350;
v_6351:
    goto v_6352;
v_6353:
    if (equal(v_6432, v_6431)) goto v_6348;
    else goto v_6349;
v_6348:
    v_6431 = elt(env, 1); // equal
    goto v_6347;
v_6349:
    goto v_6365;
v_6361:
    v_6432 = stack[-1];
    goto v_6362;
v_6363:
    v_6431 = stack[0];
    goto v_6364;
v_6365:
    goto v_6361;
v_6362:
    goto v_6363;
v_6364:
    fn = elt(env, 4); // wulessp
    v_6431 = (*qfn2(fn))(fn, v_6432, v_6431);
    env = stack[-2];
    if (v_6431 == nil) goto v_6359;
    v_6431 = elt(env, 2); // less
    goto v_6347;
v_6359:
    goto v_6376;
v_6372:
    v_6432 = stack[0];
    goto v_6373;
v_6374:
    v_6431 = stack[-1];
    goto v_6375;
v_6376:
    goto v_6372;
v_6373:
    goto v_6374;
v_6375:
    fn = elt(env, 4); // wulessp
    v_6431 = (*qfn2(fn))(fn, v_6432, v_6431);
    env = stack[-2];
    if (v_6431 == nil) goto v_6370;
    v_6431 = elt(env, 3); // greater
    goto v_6347;
v_6370:
    v_6431 = stack[-1];
    fn = elt(env, 5); // wuconstantp
    v_6431 = (*qfn1(fn))(fn, v_6431);
    env = stack[-2];
    if (v_6431 == nil) goto v_6381;
    goto v_6389;
v_6385:
    v_6432 = stack[-1];
    goto v_6386;
v_6387:
    v_6431 = stack[0];
    goto v_6388;
v_6389:
    goto v_6385;
v_6386:
    goto v_6387;
v_6388:
    {
        fn = elt(env, 6); // totalcompareconstants
        return (*qfn2(fn))(fn, v_6432, v_6431);
    }
v_6381:
    goto v_6402;
v_6398:
    v_6431 = stack[-1];
    v_6431 = qcar(v_6431);
    v_6432 = qcdr(v_6431);
    goto v_6399;
v_6400:
    v_6431 = stack[0];
    v_6431 = qcar(v_6431);
    v_6431 = qcdr(v_6431);
    goto v_6401;
v_6402:
    goto v_6398;
v_6399:
    goto v_6400;
v_6401:
    v_6431 = CC_totalcompare(elt(env, 0), v_6432, v_6431);
    env = stack[-2];
    v_6433 = v_6431;
    goto v_6417;
v_6413:
    v_6432 = v_6433;
    goto v_6414;
v_6415:
    v_6431 = elt(env, 1); // equal
    goto v_6416;
v_6417:
    goto v_6413;
v_6414:
    goto v_6415;
v_6416:
    if (v_6432 == v_6431) goto v_6412;
    v_6431 = v_6433;
    goto v_6396;
v_6412:
    goto v_6426;
v_6422:
    v_6431 = stack[-1];
    v_6432 = qcdr(v_6431);
    goto v_6423;
v_6424:
    v_6431 = stack[0];
    v_6431 = qcdr(v_6431);
    goto v_6425;
v_6426:
    goto v_6422;
v_6423:
    goto v_6424;
v_6425:
    stack[-1] = v_6432;
    stack[0] = v_6431;
    goto v_6342;
v_6396:
    goto v_6347;
    v_6431 = nil;
v_6347:
    return onevalue(v_6431);
}



// Code for rl_smrmknowl

static LispObject CC_rl_smrmknowl(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6361, v_6362;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_6361 = v_6344;
    v_6362 = v_6343;
// end of prologue
    goto v_6351;
v_6347:
    stack[0] = qvalue(elt(env, 1)); // rl_smrmknowl!*
    goto v_6348;
v_6349:
    goto v_6358;
v_6354:
    goto v_6355;
v_6356:
    goto v_6357;
v_6358:
    goto v_6354;
v_6355:
    goto v_6356;
v_6357:
    v_6361 = list2(v_6362, v_6361);
    env = stack[-1];
    goto v_6350;
v_6351:
    goto v_6347;
v_6348:
    goto v_6349;
v_6350:
    {
        LispObject v_6364 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_6364, v_6361);
    }
}



// Code for ibalp_getvar!-zmom

static LispObject CC_ibalp_getvarKzmom(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6467, v_6468;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_6467 = v_6344;
    stack[0] = v_6343;
// end of prologue
    stack[-4] = nil;
    stack[-2] = nil;
    fn = elt(env, 1); // ibalp_minclnr
    v_6467 = (*qfn1(fn))(fn, v_6467);
    env = stack[-6];
    stack[-5] = v_6467;
    v_6467 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[-3] = v_6467;
    v_6467 = stack[0];
    stack[-1] = v_6467;
v_6359:
    v_6467 = stack[-1];
    if (v_6467 == nil) goto v_6363;
    else goto v_6364;
v_6363:
    goto v_6358;
v_6364:
    v_6467 = stack[-1];
    v_6467 = qcar(v_6467);
    stack[0] = v_6467;
    v_6467 = stack[0];
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcar(v_6467);
    if (v_6467 == nil) goto v_6376;
    else goto v_6377;
v_6376:
    goto v_6387;
v_6383:
    v_6467 = stack[0];
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6468 = qcar(v_6467);
    stack[-2] = v_6468;
    goto v_6384;
v_6385:
    v_6467 = stack[-3];
    goto v_6386;
v_6387:
    goto v_6383;
v_6384:
    goto v_6385;
v_6386:
    v_6467 = (LispObject)greaterp2(v_6468, v_6467);
    v_6467 = v_6467 ? lisp_true : nil;
    env = stack[-6];
    goto v_6375;
v_6377:
    v_6467 = nil;
    goto v_6375;
    v_6467 = nil;
v_6375:
    if (v_6467 == nil) goto v_6373;
    goto v_6415;
v_6411:
    v_6467 = stack[0];
    v_6468 = qcdr(v_6467);
    goto v_6412;
v_6413:
    v_6467 = stack[-5];
    goto v_6414;
v_6415:
    goto v_6411;
v_6412:
    goto v_6413;
v_6414:
    fn = elt(env, 2); // ibalp_isinminclause
    v_6467 = (*qfn2(fn))(fn, v_6468, v_6467);
    env = stack[-6];
    if (v_6467 == nil) goto v_6409;
    v_6467 = stack[0];
    v_6467 = qcdr(v_6467);
    stack[-4] = v_6467;
    v_6467 = stack[-2];
    stack[-3] = v_6467;
    goto v_6407;
v_6409:
v_6407:
    goto v_6371;
v_6373:
v_6371:
    v_6467 = stack[-1];
    v_6467 = qcdr(v_6467);
    stack[-1] = v_6467;
    goto v_6359;
v_6358:
    goto v_6433;
v_6429:
    v_6467 = stack[-4];
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6468 = qcar(v_6467);
    goto v_6430;
v_6431:
    v_6467 = stack[-4];
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcdr(v_6467);
    v_6467 = qcar(v_6467);
    goto v_6432;
v_6433:
    goto v_6429;
v_6430:
    goto v_6431;
v_6432:
    v_6467 = (LispObject)greaterp2(v_6468, v_6467);
    v_6467 = v_6467 ? lisp_true : nil;
    if (v_6467 == nil) goto v_6427;
    v_6467 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6425;
v_6427:
    v_6467 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6425;
    v_6467 = nil;
v_6425:
    goto v_6464;
v_6460:
    v_6468 = stack[-4];
    goto v_6461;
v_6462:
    goto v_6463;
v_6464:
    goto v_6460;
v_6461:
    goto v_6462;
v_6463:
    return cons(v_6468, v_6467);
    return onevalue(v_6467);
}



// Code for integerom

static LispObject CC_integerom(LispObject env,
                         LispObject v_6343)
{
    env = qenv(env);
    LispObject v_6353;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6343);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_6343;
// end of prologue
    v_6353 = elt(env, 1); // "<OMI> "
    fn = elt(env, 3); // printout
    v_6353 = (*qfn1(fn))(fn, v_6353);
    env = stack[-1];
    v_6353 = stack[0];
    v_6353 = Lprinc(nil, v_6353);
    env = stack[-1];
    v_6353 = elt(env, 2); // " </OMI>"
    v_6353 = Lprinc(nil, v_6353);
    v_6353 = nil;
    return onevalue(v_6353);
}



// Code for writepri

static LispObject CC_writepri(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6358, v_6359, v_6360;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_6344;
    v_6358 = v_6343;
// end of prologue
    goto v_6353;
v_6347:
    fn = elt(env, 1); // eval
    v_6360 = (*qfn1(fn))(fn, v_6358);
    env = stack[-1];
    goto v_6348;
v_6349:
    v_6359 = nil;
    goto v_6350;
v_6351:
    v_6358 = stack[0];
    goto v_6352;
v_6353:
    goto v_6347;
v_6348:
    goto v_6349;
v_6350:
    goto v_6351;
v_6352:
    {
        fn = elt(env, 2); // assgnpri
        return (*qfnn(fn))(fn, 3, v_6360, v_6359, v_6358);
    }
}



// Code for cut!:ep

static LispObject CC_cutTep(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6436, v_6437;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_6344;
    stack[-2] = v_6343;
// end of prologue
    goto v_6363;
v_6359:
    v_6437 = stack[-2];
    goto v_6360;
v_6361:
    v_6436 = elt(env, 1); // !:rd!:
    goto v_6362;
v_6363:
    goto v_6359;
v_6360:
    goto v_6361;
v_6362:
    if (!consp(v_6437)) goto v_6357;
    v_6437 = qcar(v_6437);
    if (v_6437 == v_6436) goto v_6356;
    else goto v_6357;
v_6356:
    v_6436 = stack[-2];
    v_6436 = qcdr(v_6436);
    v_6436 = (consp(v_6436) ? nil : lisp_true);
    v_6436 = (v_6436 == nil ? lisp_true : nil);
    goto v_6355;
v_6357:
    v_6436 = nil;
    goto v_6355;
    v_6436 = nil;
v_6355:
    if (v_6436 == nil) goto v_6353;
    v_6436 = stack[-1];
    v_6436 = integerp(v_6436);
    goto v_6351;
v_6353:
    v_6436 = nil;
    goto v_6351;
    v_6436 = nil;
v_6351:
    if (v_6436 == nil) goto v_6349;
    goto v_6387;
v_6383:
    goto v_6393;
v_6389:
    v_6437 = stack[-1];
    goto v_6390;
v_6391:
    v_6436 = stack[-2];
    v_6436 = qcdr(v_6436);
    v_6436 = qcdr(v_6436);
    goto v_6392;
v_6393:
    goto v_6389;
v_6390:
    goto v_6391;
v_6392:
    v_6437 = difference2(v_6437, v_6436);
    env = stack[-4];
    stack[-1] = v_6437;
    goto v_6384;
v_6385:
    v_6436 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6386;
v_6387:
    goto v_6383;
v_6384:
    goto v_6385;
v_6386:
    v_6436 = (LispObject)lesseq2(v_6437, v_6436);
    v_6436 = v_6436 ? lisp_true : nil;
    env = stack[-4];
    if (v_6436 == nil) goto v_6381;
    v_6436 = stack[-2];
    goto v_6379;
v_6381:
    goto v_6409;
v_6403:
    stack[-3] = elt(env, 1); // !:rd!:
    goto v_6404;
v_6405:
    goto v_6416;
v_6412:
    v_6436 = stack[-2];
    v_6436 = qcdr(v_6436);
    stack[0] = qcar(v_6436);
    goto v_6413;
v_6414:
    v_6436 = stack[-1];
    v_6436 = negate(v_6436);
    env = stack[-4];
    goto v_6415;
v_6416:
    goto v_6412;
v_6413:
    goto v_6414;
v_6415:
    fn = elt(env, 2); // ashift
    stack[0] = (*qfn2(fn))(fn, stack[0], v_6436);
    env = stack[-4];
    goto v_6406;
v_6407:
    goto v_6427;
v_6423:
    v_6436 = stack[-2];
    v_6436 = qcdr(v_6436);
    v_6437 = qcdr(v_6436);
    goto v_6424;
v_6425:
    v_6436 = stack[-1];
    goto v_6426;
v_6427:
    goto v_6423;
v_6424:
    goto v_6425;
v_6426:
    v_6436 = plus2(v_6437, v_6436);
    goto v_6408;
v_6409:
    goto v_6403;
v_6404:
    goto v_6405;
v_6406:
    goto v_6407;
v_6408:
    {
        LispObject v_6442 = stack[-3];
        LispObject v_6443 = stack[0];
        return list2star(v_6442, v_6443, v_6436);
    }
    v_6436 = nil;
v_6379:
    goto v_6347;
v_6349:
    v_6436 = elt(env, 0); // cut!:ep
    {
        fn = elt(env, 3); // bflerrmsg
        return (*qfn1(fn))(fn, v_6436);
    }
    v_6436 = nil;
v_6347:
    return onevalue(v_6436);
}



// Code for getphystypesf

static LispObject CC_getphystypesf(LispObject env,
                         LispObject v_6343)
{
    env = qenv(env);
    LispObject v_6374;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6343);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_6343;
// end of prologue
v_6342:
    v_6374 = stack[0];
    if (v_6374 == nil) goto v_6351;
    else goto v_6352;
v_6351:
    v_6374 = lisp_true;
    goto v_6350;
v_6352:
    v_6374 = stack[0];
    fn = elt(env, 1); // domain!*p
    v_6374 = (*qfn1(fn))(fn, v_6374);
    env = stack[-1];
    goto v_6350;
    v_6374 = nil;
v_6350:
    if (v_6374 == nil) goto v_6348;
    v_6374 = nil;
    goto v_6346;
v_6348:
    v_6374 = stack[0];
    v_6374 = qcar(v_6374);
    v_6374 = qcar(v_6374);
    v_6374 = qcar(v_6374);
    fn = elt(env, 2); // getphystype
    v_6374 = (*qfn1(fn))(fn, v_6374);
    env = stack[-1];
    if (v_6374 == nil) goto v_6364;
    else goto v_6363;
v_6364:
    v_6374 = stack[0];
    v_6374 = qcar(v_6374);
    v_6374 = qcdr(v_6374);
    stack[0] = v_6374;
    goto v_6342;
v_6363:
    goto v_6346;
    v_6374 = nil;
v_6346:
    return onevalue(v_6374);
}



// Code for split!-road

static LispObject CC_splitKroad(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6387, v_6388, v_6389;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_6344;
    stack[-2] = v_6343;
// end of prologue
    goto v_6353;
v_6347:
    v_6387 = stack[-1];
    stack[-3] = qcar(v_6387);
    goto v_6348;
v_6349:
    goto v_6363;
v_6357:
    v_6387 = stack[-2];
    v_6389 = qcar(v_6387);
    goto v_6358;
v_6359:
    v_6387 = stack[-2];
    v_6388 = qcdr(v_6387);
    goto v_6360;
v_6361:
    v_6387 = stack[-1];
    v_6387 = qcdr(v_6387);
    v_6387 = qcar(v_6387);
    goto v_6362;
v_6363:
    goto v_6357;
v_6358:
    goto v_6359;
v_6360:
    goto v_6361;
v_6362:
    fn = elt(env, 1); // sroad
    stack[0] = (*qfnn(fn))(fn, 3, v_6389, v_6388, v_6387);
    env = stack[-4];
    goto v_6350;
v_6351:
    goto v_6378;
v_6372:
    v_6387 = stack[-2];
    v_6389 = qcar(v_6387);
    goto v_6373;
v_6374:
    v_6387 = stack[-2];
    v_6388 = qcdr(v_6387);
    goto v_6375;
v_6376:
    v_6387 = stack[-1];
    v_6387 = qcdr(v_6387);
    v_6387 = qcdr(v_6387);
    v_6387 = qcar(v_6387);
    goto v_6377;
v_6378:
    goto v_6372;
v_6373:
    goto v_6374;
v_6375:
    goto v_6376;
v_6377:
    fn = elt(env, 1); // sroad
    v_6387 = (*qfnn(fn))(fn, 3, v_6389, v_6388, v_6387);
    goto v_6352;
v_6353:
    goto v_6347;
v_6348:
    goto v_6349;
v_6350:
    goto v_6351;
v_6352:
    {
        LispObject v_6394 = stack[-3];
        LispObject v_6395 = stack[0];
        return list3(v_6394, v_6395, v_6387);
    }
}



// Code for simp

static LispObject CC_simp(LispObject env,
                         LispObject v_6343)
{
    env = qenv(env);
    LispObject v_7077, v_7078, v_7079;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6343);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_6343;
// end of prologue
    v_7077 = qvalue(elt(env, 1)); // varstack!*
// Binding varstack!*
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
    qvalue(elt(env, 1)) = v_7077; // varstack!*
    stack[-1] = nil;
    v_7077 = stack[-5];
    v_7077 = integerp(v_7077);
    if (v_7077 == nil) goto v_6354;
    goto v_6365;
v_6361:
    v_7078 = stack[-5];
    goto v_6362;
v_6363:
    v_7077 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6364;
v_6365:
    goto v_6361;
v_6362:
    goto v_6363;
v_6364:
    if (v_7078 == v_7077) goto v_6359;
    else goto v_6360;
v_6359:
    goto v_6373;
v_6369:
    v_7078 = nil;
    goto v_6370;
v_6371:
    v_7077 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6372;
v_6373:
    goto v_6369;
v_6370:
    goto v_6371;
v_6372:
    v_7077 = cons(v_7078, v_7077);
    goto v_6350;
v_6360:
    v_7077 = qvalue(elt(env, 2)); // dmode!*
    if (v_7077 == nil) goto v_6376;
    else goto v_6377;
v_6376:
    goto v_6384;
v_6380:
    v_7078 = stack[-5];
    goto v_6381;
v_6382:
    v_7077 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6383;
v_6384:
    goto v_6380;
v_6381:
    goto v_6382;
v_6383:
    v_7077 = cons(v_7078, v_7077);
    goto v_6350;
v_6377:
    goto v_6358;
v_6358:
    goto v_6352;
v_6354:
    goto v_6396;
v_6392:
    v_7078 = stack[-5];
    goto v_6393;
v_6394:
    v_7077 = qvalue(elt(env, 1)); // varstack!*
    goto v_6395;
v_6396:
    goto v_6392;
v_6393:
    goto v_6394;
v_6395:
    v_7077 = Lmember(nil, v_7078, v_7077);
    if (v_7077 == nil) goto v_6391;
    v_7077 = stack[-5];
    fn = elt(env, 22); // recursiveerror
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    goto v_6352;
v_6391:
v_6352:
    goto v_6407;
v_6403:
    v_7078 = stack[-5];
    goto v_6404;
v_6405:
    v_7077 = qvalue(elt(env, 1)); // varstack!*
    goto v_6406;
v_6407:
    goto v_6403;
v_6404:
    goto v_6405;
v_6406:
    v_7077 = cons(v_7078, v_7077);
    env = stack[-7];
    qvalue(elt(env, 1)) = v_7077; // varstack!*
    goto v_6419;
v_6415:
    v_7078 = qvalue(elt(env, 3)); // simpcount!*
    goto v_6416;
v_6417:
    v_7077 = qvalue(elt(env, 4)); // simplimit!*
    goto v_6418;
v_6419:
    goto v_6415;
v_6416:
    goto v_6417;
v_6418:
    v_7077 = (LispObject)greaterp2(v_7078, v_7077);
    v_7077 = v_7077 ? lisp_true : nil;
    env = stack[-7];
    if (v_7077 == nil) goto v_6413;
    v_7077 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 3)) = v_7077; // simpcount!*
    goto v_6430;
v_6424:
    v_7079 = elt(env, 5); // alg
    goto v_6425;
v_6426:
    v_7078 = (LispObject)192+TAG_FIXNUM; // 12
    goto v_6427;
v_6428:
    v_7077 = elt(env, 6); // "Simplification recursion too deep"
    goto v_6429;
v_6430:
    goto v_6424;
v_6425:
    goto v_6426;
v_6427:
    goto v_6428;
v_6429:
    fn = elt(env, 23); // rerror
    v_7077 = (*qfnn(fn))(fn, 3, v_7079, v_7078, v_7077);
    env = stack[-7];
    goto v_6411;
v_6413:
    goto v_6445;
v_6441:
    v_7078 = stack[-5];
    goto v_6442;
v_6443:
    v_7077 = elt(env, 7); // !*sq
    goto v_6444;
v_6445:
    goto v_6441;
v_6442:
    goto v_6443;
v_6444:
    if (!consp(v_7078)) goto v_6439;
    v_7078 = qcar(v_7078);
    if (v_7078 == v_7077) goto v_6438;
    else goto v_6439;
v_6438:
    v_7077 = stack[-5];
    v_7077 = qcdr(v_7077);
    v_7077 = qcdr(v_7077);
    v_7077 = qcar(v_7077);
    if (v_7077 == nil) goto v_6450;
    else goto v_6451;
v_6450:
    v_7077 = nil;
    goto v_6449;
v_6451:
    v_7077 = qvalue(elt(env, 8)); // !*resimp
    v_7077 = (v_7077 == nil ? lisp_true : nil);
    goto v_6449;
    v_7077 = nil;
v_6449:
    goto v_6437;
v_6439:
    v_7077 = nil;
    goto v_6437;
    v_7077 = nil;
v_6437:
    if (v_7077 == nil) goto v_6435;
    v_7077 = stack[-5];
    v_7077 = qcdr(v_7077);
    v_7077 = qcar(v_7077);
    goto v_6350;
v_6435:
    v_7077 = qvalue(elt(env, 9)); // !*uncached
    if (v_7077 == nil) goto v_6471;
    else goto v_6472;
v_6471:
    v_7077 = qvalue(elt(env, 10)); // alglist!*
    v_7077 = qcar(v_7077);
    v_7078 = v_7077;
    if (v_7078 == nil) goto v_6479;
    else goto v_6480;
v_6479:
    v_7077 = nil;
    goto v_6478;
v_6480:
    goto v_6490;
v_6486:
    v_7078 = stack[-5];
    goto v_6487;
v_6488:
    goto v_6489;
v_6490:
    goto v_6486;
v_6487:
    goto v_6488;
v_6489:
    fn = elt(env, 24); // gethash
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    env = stack[-7];
    goto v_6478;
    v_7077 = nil;
v_6478:
    stack[-1] = v_7077;
    goto v_6470;
v_6472:
    v_7077 = nil;
    goto v_6470;
    v_7077 = nil;
v_6470:
    if (v_7077 == nil) goto v_6468;
    v_7077 = stack[-1];
    v_7077 = qcar(v_7077);
    if (v_7077 == nil) goto v_6499;
    v_7077 = lisp_true;
    qvalue(elt(env, 11)) = v_7077; // !*sub2
    goto v_6497;
v_6499:
v_6497:
    v_7077 = stack[-1];
    v_7077 = qcdr(v_7077);
    goto v_6350;
v_6468:
v_6411:
    v_7077 = qvalue(elt(env, 3)); // simpcount!*
    v_7077 = add1(v_7077);
    env = stack[-7];
    qvalue(elt(env, 3)) = v_7077; // simpcount!*
    v_7077 = stack[-5];
    if (!consp(v_7077)) goto v_6509;
    else goto v_6510;
v_6509:
    goto v_6517;
v_6513:
    v_7077 = stack[-5];
    fn = elt(env, 25); // simpatom
    v_7078 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    goto v_6514;
v_6515:
    v_7077 = stack[-5];
    goto v_6516;
v_6517:
    goto v_6513;
v_6514:
    goto v_6515;
v_6516:
    fn = elt(env, 26); // !*ssave
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    goto v_6350;
v_6510:
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    if (symbolp(v_7077)) goto v_6526;
    v_7077 = lisp_true;
    goto v_6524;
v_6526:
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    v_7077 = (v_7077 == nil ? lisp_true : nil);
    goto v_6524;
    v_7077 = nil;
v_6524:
    if (v_7077 == nil) goto v_6522;
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    if (!consp(v_7077)) goto v_6537;
    else goto v_6538;
v_6537:
    goto v_6546;
v_6542:
    v_7077 = stack[-5];
    v_7078 = qcar(v_7077);
    goto v_6543;
v_6544:
    v_7077 = elt(env, 12); // "operator"
    goto v_6545;
v_6546:
    goto v_6542;
v_6543:
    goto v_6544;
v_6545:
    fn = elt(env, 27); // typerr
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    goto v_6536;
v_6538:
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    v_7077 = qcar(v_7077);
    if (symbolp(v_7077)) goto v_6552;
    else goto v_6551;
v_6552:
    goto v_6562;
v_6558:
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    v_7078 = qcar(v_7077);
    goto v_6559;
v_6560:
    v_7077 = elt(env, 13); // name
    goto v_6561;
v_6562:
    goto v_6558;
v_6559:
    goto v_6560;
v_6561:
    v_7077 = get(v_7078, v_7077);
    env = stack[-7];
    stack[-1] = v_7077;
    if (v_7077 == nil) goto v_6551;
    goto v_6572;
v_6568:
    v_7078 = stack[-5];
    goto v_6569;
v_6570:
    v_7077 = stack[-5];
    goto v_6571;
v_6572:
    goto v_6568;
v_6569:
    goto v_6570;
v_6571:
    fn = elt(env, 26); // !*ssave
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    goto v_6350;
v_6551:
    goto v_6586;
v_6582:
    v_7077 = stack[-5];
    v_7078 = qcar(v_7077);
    goto v_6583;
v_6584:
    v_7077 = elt(env, 14); // mat
    goto v_6585;
v_6586:
    goto v_6582;
v_6583:
    goto v_6584;
v_6585:
    if (!consp(v_7078)) goto v_6580;
    v_7078 = qcar(v_7078);
    if (v_7078 == v_7077) goto v_6579;
    else goto v_6580;
v_6579:
    v_7077 = stack[-5];
    v_7077 = qcdr(v_7077);
    fn = elt(env, 28); // revlis
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    stack[-1] = v_7077;
    fn = elt(env, 29); // numlis
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    if (v_7077 == nil) goto v_6592;
    else goto v_6593;
v_6592:
    v_7077 = nil;
    goto v_6591;
v_6593:
    goto v_6605;
v_6601:
    v_7077 = stack[-1];
    v_7078 = Llength(nil, v_7077);
    env = stack[-7];
    goto v_6602;
v_6603:
    v_7077 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_6604;
v_6605:
    goto v_6601;
v_6602:
    goto v_6603;
v_6604:
    v_7077 = (v_7078 == v_7077 ? lisp_true : nil);
    goto v_6591;
    v_7077 = nil;
v_6591:
    goto v_6578;
v_6580:
    v_7077 = nil;
    goto v_6578;
    v_7077 = nil;
v_6578:
    if (v_7077 == nil) goto v_6576;
    goto v_6618;
v_6614:
    goto v_6625;
v_6621:
    goto v_6631;
v_6627:
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    v_7078 = qcdr(v_7077);
    goto v_6628;
v_6629:
    v_7077 = stack[-1];
    v_7077 = qcar(v_7077);
    goto v_6630;
v_6631:
    goto v_6627;
v_6628:
    goto v_6629;
v_6630:
    fn = elt(env, 30); // nth
    v_7078 = (*qfn2(fn))(fn, v_7078, v_7077);
    env = stack[-7];
    goto v_6622;
v_6623:
    v_7077 = stack[-1];
    v_7077 = qcdr(v_7077);
    v_7077 = qcar(v_7077);
    goto v_6624;
v_6625:
    goto v_6621;
v_6622:
    goto v_6623;
v_6624:
    fn = elt(env, 30); // nth
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    env = stack[-7];
    v_7078 = CC_simp(elt(env, 0), v_7077);
    env = stack[-7];
    goto v_6615;
v_6616:
    v_7077 = stack[-5];
    goto v_6617;
v_6618:
    goto v_6614;
v_6615:
    goto v_6616;
v_6617:
    fn = elt(env, 26); // !*ssave
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    goto v_6350;
v_6576:
    goto v_6648;
v_6644:
    v_7078 = stack[-5];
    goto v_6645;
v_6646:
    v_7077 = lisp_true;
    goto v_6647;
v_6648:
    goto v_6644;
v_6645:
    goto v_6646;
v_6647:
    fn = elt(env, 31); // errpri2
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    goto v_6536;
v_6536:
    goto v_6508;
v_6522:
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    if (!symbolp(v_7077)) v_7077 = nil;
    else { v_7077 = qfastgets(v_7077);
           if (v_7077 != nil) { v_7077 = elt(v_7077, 59); // opfn
#ifdef RECORD_GET
             if (v_7077 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v_7077 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v_7077 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v_7077 == SPID_NOPROP) v_7077 = nil; else v_7077 = lisp_true; }}
#endif
    if (v_7077 == nil) goto v_6652;
    v_7077 = stack[-5];
    fn = elt(env, 32); // opfneval
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    stack[-1] = v_7077;
    fn = elt(env, 33); // getrtype
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    v_7078 = v_7077;
    if (v_7077 == nil) goto v_6658;
    else goto v_6659;
v_6658:
    goto v_6668;
v_6664:
    v_7077 = stack[-1];
    fn = elt(env, 34); // simp_without_resimp
    v_7078 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    goto v_6665;
v_6666:
    v_7077 = stack[-5];
    goto v_6667;
v_6668:
    goto v_6664;
v_6665:
    goto v_6666;
v_6667:
    fn = elt(env, 26); // !*ssave
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    goto v_6350;
v_6659:
    goto v_6682;
v_6678:
    goto v_6679;
v_6680:
    v_7077 = elt(env, 15); // yetunknowntype
    goto v_6681;
v_6682:
    goto v_6678;
v_6679:
    goto v_6680;
v_6681:
    if (v_7078 == v_7077) goto v_6676;
    else goto v_6677;
v_6676:
    v_7077 = stack[-1];
    fn = elt(env, 35); // reval
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    stack[-1] = v_7077;
    fn = elt(env, 33); // getrtype
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    v_7077 = (v_7077 == nil ? lisp_true : nil);
    goto v_6675;
v_6677:
    v_7077 = nil;
    goto v_6675;
    v_7077 = nil;
v_6675:
    if (v_7077 == nil) goto v_6673;
    v_7077 = stack[-1];
    v_7077 = CC_simp(elt(env, 0), v_7077);
    goto v_6350;
v_6673:
    goto v_6701;
v_6697:
    v_7078 = stack[-5];
    goto v_6698;
v_6699:
    v_7077 = elt(env, 16); // "scalar"
    goto v_6700;
v_6701:
    goto v_6697;
v_6698:
    goto v_6699;
v_6700:
    fn = elt(env, 27); // typerr
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    goto v_6657;
v_6657:
    goto v_6508;
v_6652:
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    if (!symbolp(v_7077)) v_7077 = nil;
    else { v_7077 = qfastgets(v_7077);
           if (v_7077 != nil) { v_7077 = elt(v_7077, 45); // psopfn
#ifdef RECORD_GET
             if (v_7077 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v_7077 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v_7077 == SPID_NOPROP) v_7077 = nil; }}
#endif
    stack[-1] = v_7077;
    if (v_7077 == nil) goto v_6705;
    goto v_6719;
v_6715:
    stack[0] = stack[-1];
    goto v_6716;
v_6717:
    v_7077 = stack[-5];
    fn = elt(env, 36); // argnochk
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    v_7077 = qcdr(v_7077);
    goto v_6718;
v_6719:
    goto v_6715;
v_6716:
    goto v_6717;
v_6718:
    v_7077 = Lapply1(nil, stack[0], v_7077);
    env = stack[-7];
    stack[-1] = v_7077;
    fn = elt(env, 33); // getrtype
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    if (v_7077 == nil) goto v_6712;
    goto v_6729;
v_6725:
    v_7078 = stack[-5];
    goto v_6726;
v_6727:
    v_7077 = elt(env, 16); // "scalar"
    goto v_6728;
v_6729:
    goto v_6725;
v_6726:
    goto v_6727;
v_6728:
    fn = elt(env, 27); // typerr
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    goto v_6710;
v_6712:
    goto v_6738;
v_6734:
    v_7078 = stack[-1];
    goto v_6735;
v_6736:
    v_7077 = stack[-5];
    goto v_6737;
v_6738:
    goto v_6734;
v_6735:
    goto v_6736;
v_6737:
    if (equal(v_7078, v_7077)) goto v_6732;
    else goto v_6733;
v_6732:
    goto v_6746;
v_6742:
    goto v_6752;
v_6748:
    goto v_6759;
v_6755:
    goto v_6765;
v_6761:
    v_7078 = stack[-1];
    goto v_6762;
v_6763:
    v_7077 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6764;
v_6765:
    goto v_6761;
v_6762:
    goto v_6763;
v_6764:
    fn = elt(env, 37); // to
    v_7078 = (*qfn2(fn))(fn, v_7078, v_7077);
    env = stack[-7];
    goto v_6756;
v_6757:
    v_7077 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6758;
v_6759:
    goto v_6755;
v_6756:
    goto v_6757;
v_6758:
    v_7077 = cons(v_7078, v_7077);
    env = stack[-7];
    v_7078 = ncons(v_7077);
    env = stack[-7];
    goto v_6749;
v_6750:
    v_7077 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6751;
v_6752:
    goto v_6748;
v_6749:
    goto v_6750;
v_6751:
    v_7078 = cons(v_7078, v_7077);
    env = stack[-7];
    goto v_6743;
v_6744:
    v_7077 = stack[-5];
    goto v_6745;
v_6746:
    goto v_6742;
v_6743:
    goto v_6744;
v_6745:
    fn = elt(env, 26); // !*ssave
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    goto v_6350;
v_6733:
    goto v_6778;
v_6774:
    v_7077 = stack[-1];
    fn = elt(env, 34); // simp_without_resimp
    v_7078 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    goto v_6775;
v_6776:
    v_7077 = stack[-5];
    goto v_6777;
v_6778:
    goto v_6774;
v_6775:
    goto v_6776;
v_6777:
    fn = elt(env, 26); // !*ssave
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    goto v_6350;
v_6710:
    goto v_6508;
v_6705:
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    if (!symbolp(v_7077)) v_7077 = nil;
    else { v_7077 = qfastgets(v_7077);
           if (v_7077 != nil) { v_7077 = elt(v_7077, 41); // polyfn
#ifdef RECORD_GET
             if (v_7077 != SPID_NOPROP)
                record_get(elt(fastget_names, 41), 1);
             else record_get(elt(fastget_names, 41), 0),
                v_7077 = nil; }
           else record_get(elt(fastget_names, 41), 0); }
#else
             if (v_7077 == SPID_NOPROP) v_7077 = nil; }}
#endif
    stack[-1] = v_7077;
    if (v_7077 == nil) goto v_6783;
    v_7077 = stack[-5];
    fn = elt(env, 36); // argnochk
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    goto v_6794;
v_6790:
    goto v_6800;
v_6796:
    goto v_6806;
v_6802:
    stack[-4] = stack[-1];
    goto v_6803;
v_6804:
    v_7077 = stack[-5];
    v_7077 = qcdr(v_7077);
    stack[-3] = v_7077;
    v_7077 = stack[-3];
    if (v_7077 == nil) goto v_6818;
    else goto v_6819;
v_6818:
    v_7077 = nil;
    goto v_6812;
v_6819:
    v_7077 = stack[-3];
    v_7077 = qcar(v_7077);
    fn = elt(env, 38); // simp!*
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    fn = elt(env, 39); // !*q2f
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    v_7077 = ncons(v_7077);
    env = stack[-7];
    stack[-1] = v_7077;
    stack[-2] = v_7077;
v_6813:
    v_7077 = stack[-3];
    v_7077 = qcdr(v_7077);
    stack[-3] = v_7077;
    v_7077 = stack[-3];
    if (v_7077 == nil) goto v_6833;
    else goto v_6834;
v_6833:
    v_7077 = stack[-2];
    goto v_6812;
v_6834:
    goto v_6842;
v_6838:
    stack[0] = stack[-1];
    goto v_6839;
v_6840:
    v_7077 = stack[-3];
    v_7077 = qcar(v_7077);
    fn = elt(env, 38); // simp!*
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    fn = elt(env, 39); // !*q2f
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    v_7077 = ncons(v_7077);
    env = stack[-7];
    goto v_6841;
v_6842:
    goto v_6838;
v_6839:
    goto v_6840;
v_6841:
    v_7077 = Lrplacd(nil, stack[0], v_7077);
    env = stack[-7];
    v_7077 = stack[-1];
    v_7077 = qcdr(v_7077);
    stack[-1] = v_7077;
    goto v_6813;
v_6812:
    goto v_6805;
v_6806:
    goto v_6802;
v_6803:
    goto v_6804;
v_6805:
    fn = elt(env, 40); // lispapply
    v_7078 = (*qfn2(fn))(fn, stack[-4], v_7077);
    env = stack[-7];
    goto v_6797;
v_6798:
    v_7077 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6799;
v_6800:
    goto v_6796;
v_6797:
    goto v_6798;
v_6799:
    v_7078 = cons(v_7078, v_7077);
    env = stack[-7];
    goto v_6791;
v_6792:
    v_7077 = stack[-5];
    goto v_6793;
v_6794:
    goto v_6790;
v_6791:
    goto v_6792;
v_6793:
    fn = elt(env, 26); // !*ssave
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    goto v_6350;
v_6783:
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    if (!symbolp(v_7077)) v_7077 = nil;
    else { v_7077 = qfastgets(v_7077);
           if (v_7077 != nil) { v_7077 = elt(v_7077, 9); // opmtch
#ifdef RECORD_GET
             if (v_7077 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_7077 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_7077 == SPID_NOPROP) v_7077 = nil; }}
#endif
    if (v_7077 == nil) goto v_6856;
    goto v_6870;
v_6866:
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    if (!symbolp(v_7077)) v_7078 = nil;
    else { v_7078 = qfastgets(v_7077);
           if (v_7078 != nil) { v_7078 = elt(v_7078, 22); // simpfn
#ifdef RECORD_GET
             if (v_7078 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v_7078 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v_7078 == SPID_NOPROP) v_7078 = nil; }}
#endif
    goto v_6867;
v_6868:
    v_7077 = elt(env, 17); // simpiden
    goto v_6869;
v_6870:
    goto v_6866;
v_6867:
    goto v_6868;
v_6869:
    if (v_7078 == v_7077) goto v_6865;
    v_7077 = stack[-5];
    fn = elt(env, 41); // opmtchrevop
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    stack[-1] = v_7077;
    goto v_6863;
v_6865:
    v_7077 = nil;
    goto v_6863;
    v_7077 = nil;
v_6863:
    if (v_7077 == nil) goto v_6856;
    goto v_6885;
v_6881:
    v_7077 = stack[-1];
    v_7078 = CC_simp(elt(env, 0), v_7077);
    env = stack[-7];
    goto v_6882;
v_6883:
    v_7077 = stack[-5];
    goto v_6884;
v_6885:
    goto v_6881;
v_6882:
    goto v_6883;
v_6884:
    fn = elt(env, 26); // !*ssave
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    goto v_6350;
v_6856:
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    if (!symbolp(v_7077)) v_7077 = nil;
    else { v_7077 = qfastgets(v_7077);
           if (v_7077 != nil) { v_7077 = elt(v_7077, 22); // simpfn
#ifdef RECORD_GET
             if (v_7077 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v_7077 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v_7077 == SPID_NOPROP) v_7077 = nil; }}
#endif
    stack[-1] = v_7077;
    if (v_7077 == nil) goto v_6890;
    goto v_6899;
v_6895:
    goto v_6905;
v_6901:
    stack[0] = stack[-1];
    goto v_6902;
v_6903:
    goto v_6919;
v_6915:
    v_7078 = stack[-1];
    goto v_6916;
v_6917:
    v_7077 = elt(env, 17); // simpiden
    goto v_6918;
v_6919:
    goto v_6915;
v_6916:
    goto v_6917;
v_6918:
    if (v_7078 == v_7077) goto v_6913;
    else goto v_6914;
v_6913:
    v_7077 = lisp_true;
    goto v_6912;
v_6914:
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    if (!symbolp(v_7077)) v_7077 = nil;
    else { v_7077 = qfastgets(v_7077);
           if (v_7077 != nil) { v_7077 = elt(v_7077, 62); // full
#ifdef RECORD_GET
             if (v_7077 == SPID_NOPROP)
                record_get(elt(fastget_names, 62), 0),
                v_7077 = nil;
             else record_get(elt(fastget_names, 62), 1),
                v_7077 = lisp_true; }
           else record_get(elt(fastget_names, 62), 0); }
#else
             if (v_7077 == SPID_NOPROP) v_7077 = nil; else v_7077 = lisp_true; }}
#endif
    goto v_6912;
    v_7077 = nil;
v_6912:
    if (v_7077 == nil) goto v_6910;
    v_7077 = stack[-5];
    fn = elt(env, 36); // argnochk
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    goto v_6908;
v_6910:
    v_7077 = stack[-5];
    fn = elt(env, 36); // argnochk
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    v_7077 = qcdr(v_7077);
    goto v_6908;
    v_7077 = nil;
v_6908:
    goto v_6904;
v_6905:
    goto v_6901;
v_6902:
    goto v_6903;
v_6904:
    v_7078 = Lapply1(nil, stack[0], v_7077);
    env = stack[-7];
    goto v_6896;
v_6897:
    v_7077 = stack[-5];
    goto v_6898;
v_6899:
    goto v_6895;
v_6896:
    goto v_6897;
v_6898:
    fn = elt(env, 26); // !*ssave
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    goto v_6350;
v_6890:
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    if (!symbolp(v_7077)) v_7077 = nil;
    else { v_7077 = qfastgets(v_7077);
           if (v_7077 != nil) { v_7077 = elt(v_7077, 2); // rtype
#ifdef RECORD_GET
             if (v_7077 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_7077 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_7077 == SPID_NOPROP) v_7077 = nil; }}
#endif
    stack[-1] = v_7077;
    if (v_7077 == nil) goto v_6937;
    goto v_6948;
v_6944:
    v_7078 = stack[-1];
    goto v_6945;
v_6946:
    v_7077 = elt(env, 18); // getelemfn
    goto v_6947;
v_6948:
    goto v_6944;
v_6945:
    goto v_6946;
v_6947:
    v_7077 = get(v_7078, v_7077);
    env = stack[-7];
    stack[-1] = v_7077;
    if (v_7077 == nil) goto v_6937;
    goto v_6956;
v_6952:
    goto v_6963;
v_6959:
    v_7078 = stack[-1];
    goto v_6960;
v_6961:
    v_7077 = stack[-5];
    goto v_6962;
v_6963:
    goto v_6959;
v_6960:
    goto v_6961;
v_6962:
    v_7077 = Lapply1(nil, v_7078, v_7077);
    env = stack[-7];
    v_7078 = CC_simp(elt(env, 0), v_7077);
    env = stack[-7];
    goto v_6953;
v_6954:
    v_7077 = stack[-5];
    goto v_6955;
v_6956:
    goto v_6952;
v_6953:
    goto v_6954;
v_6955:
    fn = elt(env, 26); // !*ssave
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    goto v_6350;
v_6937:
    goto v_6978;
v_6974:
    v_7077 = stack[-5];
    v_7078 = qcar(v_7077);
    goto v_6975;
v_6976:
    v_7077 = elt(env, 19); // boolean
    goto v_6977;
v_6978:
    goto v_6974;
v_6975:
    goto v_6976;
v_6977:
    v_7077 = Lflagp(nil, v_7078, v_7077);
    env = stack[-7];
    if (v_7077 == nil) goto v_6972;
    v_7077 = lisp_true;
    goto v_6970;
v_6972:
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    if (!symbolp(v_7077)) v_7077 = nil;
    else { v_7077 = qfastgets(v_7077);
           if (v_7077 != nil) { v_7077 = elt(v_7077, 23); // infix
#ifdef RECORD_GET
             if (v_7077 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_7077 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_7077 == SPID_NOPROP) v_7077 = nil; }}
#endif
    goto v_6970;
    v_7077 = nil;
v_6970:
    if (v_7077 == nil) goto v_6968;
    goto v_6993;
v_6989:
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    if (!symbolp(v_7077)) v_7077 = nil;
    else { v_7077 = qfastgets(v_7077);
           if (v_7077 != nil) { v_7077 = elt(v_7077, 37); // prtch
#ifdef RECORD_GET
             if (v_7077 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v_7077 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v_7077 == SPID_NOPROP) v_7077 = nil; }}
#endif
    stack[-1] = v_7077;
    if (v_7077 == nil) goto v_6997;
    v_7077 = stack[-1];
    v_7078 = v_7077;
    goto v_6995;
v_6997:
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    v_7078 = v_7077;
    goto v_6995;
    v_7078 = nil;
v_6995:
    goto v_6990;
v_6991:
    v_7077 = elt(env, 20); // "algebraic operator"
    goto v_6992;
v_6993:
    goto v_6989;
v_6990:
    goto v_6991;
v_6992:
    fn = elt(env, 27); // typerr
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    goto v_6508;
v_6968:
    goto v_7014;
v_7010:
    v_7077 = stack[-5];
    v_7078 = qcar(v_7077);
    goto v_7011;
v_7012:
    v_7077 = elt(env, 21); // nochange
    goto v_7013;
v_7014:
    goto v_7010;
v_7011:
    goto v_7012;
v_7013:
    v_7077 = Lflagp(nil, v_7078, v_7077);
    env = stack[-7];
    if (v_7077 == nil) goto v_7008;
    goto v_7023;
v_7019:
    v_7077 = stack[-5];
    fn = elt(env, 42); // lispeval
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    v_7078 = CC_simp(elt(env, 0), v_7077);
    env = stack[-7];
    goto v_7020;
v_7021:
    v_7077 = stack[-5];
    goto v_7022;
v_7023:
    goto v_7019;
v_7020:
    goto v_7021;
v_7022:
    fn = elt(env, 26); // !*ssave
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    goto v_6350;
v_7008:
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    if (!symbolp(v_7077)) v_7077 = nil;
    else { v_7077 = qfastgets(v_7077);
           if (v_7077 != nil) { v_7077 = elt(v_7077, 45); // psopfn
#ifdef RECORD_GET
             if (v_7077 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v_7077 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v_7077 == SPID_NOPROP) v_7077 = nil; }}
#endif
    if (v_7077 == nil) goto v_7030;
    else goto v_7028;
v_7030:
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    if (!symbolp(v_7077)) v_7077 = nil;
    else { v_7077 = qfastgets(v_7077);
           if (v_7077 != nil) { v_7077 = elt(v_7077, 19); // rtypefn
#ifdef RECORD_GET
             if (v_7077 != SPID_NOPROP)
                record_get(elt(fastget_names, 19), 1);
             else record_get(elt(fastget_names, 19), 0),
                v_7077 = nil; }
           else record_get(elt(fastget_names, 19), 0); }
#else
             if (v_7077 == SPID_NOPROP) v_7077 = nil; }}
#endif
    if (v_7077 == nil) goto v_7034;
    else goto v_7028;
v_7034:
    goto v_7029;
v_7028:
    goto v_7043;
v_7039:
    v_7078 = stack[-5];
    goto v_7040;
v_7041:
    v_7077 = elt(env, 16); // "scalar"
    goto v_7042;
v_7043:
    goto v_7039;
v_7040:
    goto v_7041;
v_7042:
    fn = elt(env, 27); // typerr
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    goto v_6508;
v_7029:
    goto v_7053;
v_7049:
    v_7077 = stack[-5];
    v_7078 = qcar(v_7077);
    goto v_7050;
v_7051:
    v_7077 = elt(env, 12); // "operator"
    goto v_7052;
v_7053:
    goto v_7049;
v_7050:
    goto v_7051;
v_7052:
    fn = elt(env, 43); // redmsg
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    env = stack[-7];
    v_7077 = stack[-5];
    v_7077 = qcar(v_7077);
    fn = elt(env, 44); // mkop
    v_7077 = (*qfn1(fn))(fn, v_7077);
    env = stack[-7];
    goto v_7065;
v_7061:
    v_7078 = stack[-5];
    goto v_7062;
v_7063:
    v_7077 = qvalue(elt(env, 1)); // varstack!*
    goto v_7064;
v_7065:
    goto v_7061;
v_7062:
    goto v_7063;
v_7064:
    v_7077 = Ldelete(nil, v_7078, v_7077);
    env = stack[-7];
    qvalue(elt(env, 1)) = v_7077; // varstack!*
    goto v_7073;
v_7069:
    v_7077 = stack[-5];
    v_7078 = CC_simp(elt(env, 0), v_7077);
    env = stack[-7];
    goto v_7070;
v_7071:
    v_7077 = stack[-5];
    goto v_7072;
v_7073:
    goto v_7069;
v_7070:
    goto v_7071;
v_7072:
    fn = elt(env, 26); // !*ssave
    v_7077 = (*qfn2(fn))(fn, v_7078, v_7077);
    goto v_6350;
v_6508:
    v_7077 = nil;
v_6350:
    ;}  // end of a binding scope
    return onevalue(v_7077);
}



// Code for compactfmatch2

static LispObject CC_compactfmatch2(LispObject env,
                         LispObject v_6343)
{
    env = qenv(env);
    LispObject v_6377, v_6378;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6343);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_6343;
// end of prologue
    v_6377 = stack[0];
    if (!consp(v_6377)) goto v_6347;
    else goto v_6348;
v_6347:
    v_6377 = nil;
    goto v_6346;
v_6348:
    goto v_6357;
v_6353:
    v_6377 = stack[0];
    v_6378 = qcar(v_6377);
    goto v_6354;
v_6355:
    v_6377 = elt(env, 1); // !~
    goto v_6356;
v_6357:
    goto v_6353;
v_6354:
    goto v_6355;
v_6356:
    if (v_6378 == v_6377) goto v_6351;
    else goto v_6352;
v_6351:
    v_6377 = stack[0];
    return ncons(v_6377);
v_6352:
    goto v_6370;
v_6366:
    v_6377 = stack[0];
    v_6377 = qcar(v_6377);
    stack[-1] = CC_compactfmatch2(elt(env, 0), v_6377);
    env = stack[-2];
    goto v_6367;
v_6368:
    v_6377 = stack[0];
    v_6377 = qcdr(v_6377);
    v_6377 = CC_compactfmatch2(elt(env, 0), v_6377);
    goto v_6369;
v_6370:
    goto v_6366;
v_6367:
    goto v_6368;
v_6369:
    {
        LispObject v_6381 = stack[-1];
        return Lappend(nil, v_6381, v_6377);
    }
    v_6377 = nil;
v_6346:
    return onevalue(v_6377);
}



// Code for dp!=mocompare

static LispObject CC_dpMmocompare(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6363, v_6364;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
// copy arguments values to proper place
    v_6363 = v_6344;
    v_6364 = v_6343;
// end of prologue
    goto v_6351;
v_6347:
    goto v_6357;
v_6353:
    v_6364 = qcar(v_6364);
    goto v_6354;
v_6355:
    v_6363 = qcar(v_6363);
    goto v_6356;
v_6357:
    goto v_6353;
v_6354:
    goto v_6355;
v_6356:
    fn = elt(env, 1); // mo_compare
    v_6364 = (*qfn2(fn))(fn, v_6364, v_6363);
    goto v_6348;
v_6349:
    v_6363 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6350;
v_6351:
    goto v_6347;
v_6348:
    goto v_6349;
v_6350:
        return Leqn(nil, v_6364, v_6363);
}



// Code for raiseind!:

static LispObject CC_raiseindT(LispObject env,
                         LispObject v_6343)
{
    env = qenv(env);
    LispObject v_6356, v_6357;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_6356 = v_6343;
// end of prologue
    v_6357 = v_6356;
    if (!consp(v_6357)) goto v_6347;
    else goto v_6348;
v_6347:
    goto v_6346;
v_6348:
    v_6356 = qcdr(v_6356);
    v_6356 = qcar(v_6356);
    goto v_6346;
    v_6356 = nil;
v_6346:
    return onevalue(v_6356);
}



// Code for ra_budan!-transform

static LispObject CC_ra_budanKtransform(LispObject env,
                         LispObject v_6343)
{
    env = qenv(env);
    LispObject v_6451, v_6452;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6343);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_6343;
// end of prologue
    goto v_6355;
v_6351:
    goto v_6362;
v_6358:
    goto v_6368;
v_6364:
    v_6452 = elt(env, 1); // x
    goto v_6365;
v_6366:
    v_6451 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6367;
v_6368:
    goto v_6364;
v_6365:
    goto v_6366;
v_6367:
    fn = elt(env, 2); // to
    v_6452 = (*qfn2(fn))(fn, v_6452, v_6451);
    env = stack[-4];
    goto v_6359;
v_6360:
    v_6451 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6361;
v_6362:
    goto v_6358;
v_6359:
    goto v_6360;
v_6361:
    v_6451 = cons(v_6452, v_6451);
    env = stack[-4];
    v_6452 = ncons(v_6451);
    env = stack[-4];
    goto v_6352;
v_6353:
    v_6451 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6354;
v_6355:
    goto v_6351;
v_6352:
    goto v_6353;
v_6354:
    fn = elt(env, 3); // addf
    v_6451 = (*qfn2(fn))(fn, v_6452, v_6451);
    env = stack[-4];
    stack[0] = v_6451;
    v_6451 = stack[-2];
    if (!consp(v_6451)) goto v_6379;
    else goto v_6380;
v_6379:
    v_6451 = lisp_true;
    goto v_6378;
v_6380:
    v_6451 = stack[-2];
    v_6451 = qcar(v_6451);
    v_6451 = (consp(v_6451) ? nil : lisp_true);
    goto v_6378;
    v_6451 = nil;
v_6378:
    if (v_6451 == nil) goto v_6376;
    v_6451 = stack[-2];
    goto v_6349;
v_6376:
    v_6451 = stack[-2];
    v_6451 = qcdr(v_6451);
    v_6451 = CC_ra_budanKtransform(elt(env, 0), v_6451);
    env = stack[-4];
    stack[-3] = v_6451;
    v_6451 = stack[-2];
    v_6451 = qcdr(v_6451);
    if (!consp(v_6451)) goto v_6398;
    else goto v_6399;
v_6398:
    v_6451 = lisp_true;
    goto v_6397;
v_6399:
    v_6451 = stack[-2];
    v_6451 = qcdr(v_6451);
    v_6451 = qcar(v_6451);
    v_6451 = (consp(v_6451) ? nil : lisp_true);
    goto v_6397;
    v_6451 = nil;
v_6397:
    if (v_6451 == nil) goto v_6395;
    v_6451 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6393;
v_6395:
    v_6451 = stack[-2];
    v_6451 = qcdr(v_6451);
    v_6451 = qcar(v_6451);
    v_6451 = qcar(v_6451);
    v_6451 = qcdr(v_6451);
    goto v_6393;
    v_6451 = nil;
v_6393:
    goto v_6422;
v_6418:
    v_6452 = stack[-2];
    v_6452 = qcar(v_6452);
    stack[-1] = qcdr(v_6452);
    goto v_6419;
v_6420:
    goto v_6431;
v_6427:
    goto v_6437;
v_6433:
    goto v_6434;
v_6435:
    goto v_6444;
v_6440:
    v_6452 = stack[-2];
    v_6452 = qcar(v_6452);
    v_6452 = qcar(v_6452);
    v_6452 = qcdr(v_6452);
    goto v_6441;
v_6442:
    goto v_6443;
v_6444:
    goto v_6440;
v_6441:
    goto v_6442;
v_6443:
    v_6451 = difference2(v_6452, v_6451);
    env = stack[-4];
    goto v_6436;
v_6437:
    goto v_6433;
v_6434:
    goto v_6435;
v_6436:
    fn = elt(env, 4); // exptf
    v_6452 = (*qfn2(fn))(fn, stack[0], v_6451);
    env = stack[-4];
    goto v_6428;
v_6429:
    v_6451 = stack[-3];
    goto v_6430;
v_6431:
    goto v_6427;
v_6428:
    goto v_6429;
v_6430:
    fn = elt(env, 5); // multf
    v_6451 = (*qfn2(fn))(fn, v_6452, v_6451);
    env = stack[-4];
    goto v_6421;
v_6422:
    goto v_6418;
v_6419:
    goto v_6420;
v_6421:
    {
        LispObject v_6457 = stack[-1];
        fn = elt(env, 3); // addf
        return (*qfn2(fn))(fn, v_6457, v_6451);
    }
v_6349:
    return onevalue(v_6451);
}



// Code for formprogn

static LispObject CC_formprogn(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6366, v_6367, v_6368;
    LispObject fn;
    LispObject v_6345, v_6344, v_6343;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formprogn");
    va_start(aa, nargs);
    v_6343 = va_arg(aa, LispObject);
    v_6344 = va_arg(aa, LispObject);
    v_6345 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_6345,v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_6343,v_6344,v_6345);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_6366 = v_6345;
    v_6367 = v_6344;
    v_6368 = v_6343;
// end of prologue
    goto v_6352;
v_6348:
    stack[0] = elt(env, 1); // progn
    goto v_6349;
v_6350:
    goto v_6361;
v_6355:
    v_6368 = qcdr(v_6368);
    goto v_6356;
v_6357:
    goto v_6358;
v_6359:
    goto v_6360;
v_6361:
    goto v_6355;
v_6356:
    goto v_6357;
v_6358:
    goto v_6359;
v_6360:
    fn = elt(env, 2); // formclis
    v_6366 = (*qfnn(fn))(fn, 3, v_6368, v_6367, v_6366);
    goto v_6351;
v_6352:
    goto v_6348;
v_6349:
    goto v_6350;
v_6351:
    {
        LispObject v_6370 = stack[0];
        return cons(v_6370, v_6366);
    }
}



// Code for color1

static LispObject CC_color1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6678, v_6679, v_6680, v_6681;
    LispObject fn;
    LispObject v_6345, v_6344, v_6343;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "color1");
    va_start(aa, nargs);
    v_6343 = va_arg(aa, LispObject);
    v_6344 = va_arg(aa, LispObject);
    v_6345 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_6345,v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_6343,v_6344,v_6345);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_6345;
    stack[-1] = v_6344;
    v_6680 = v_6343;
// end of prologue
v_6342:
v_6350:
    v_6678 = v_6680;
    v_6678 = qcar(v_6678);
    v_6678 = qcar(v_6678);
    if (v_6678 == nil) goto v_6357;
    else goto v_6358;
v_6357:
    v_6678 = lisp_true;
    goto v_6356;
v_6358:
    v_6678 = v_6680;
    v_6678 = qcdr(v_6678);
    v_6678 = (v_6678 == nil ? lisp_true : nil);
    goto v_6356;
    v_6678 = nil;
v_6356:
    if (v_6678 == nil) goto v_6354;
    v_6678 = stack[-1];
    if (v_6678 == nil) goto v_6370;
    else goto v_6371;
v_6370:
    goto v_6378;
v_6374:
    v_6678 = v_6680;
    v_6679 = qcar(v_6678);
    goto v_6375;
v_6376:
    v_6678 = stack[0];
    goto v_6377;
v_6378:
    goto v_6374;
v_6375:
    goto v_6376;
v_6377:
    {
        fn = elt(env, 5); // addsq
        return (*qfn2(fn))(fn, v_6679, v_6678);
    }
v_6371:
    v_6678 = stack[-1];
    v_6678 = qcar(v_6678);
    stack[-2] = v_6678;
    v_6678 = stack[-1];
    v_6678 = qcdr(v_6678);
    stack[-1] = v_6678;
    goto v_6393;
v_6389:
    v_6678 = v_6680;
    v_6679 = qcar(v_6678);
    goto v_6390;
v_6391:
    v_6678 = stack[0];
    goto v_6392;
v_6393:
    goto v_6389;
v_6390:
    goto v_6391;
v_6392:
    fn = elt(env, 5); // addsq
    v_6678 = (*qfn2(fn))(fn, v_6679, v_6678);
    env = stack[-3];
    stack[0] = v_6678;
    v_6678 = stack[-2];
    v_6680 = v_6678;
    goto v_6350;
    goto v_6352;
v_6354:
    goto v_6411;
v_6407:
    v_6679 = elt(env, 1); // qg
    goto v_6408;
v_6409:
    v_6678 = v_6680;
    v_6678 = qcdr(v_6678);
    goto v_6410;
v_6411:
    goto v_6407;
v_6408:
    goto v_6409;
v_6410:
    v_6678 = Lassoc(nil, v_6679, v_6678);
    v_6681 = v_6678;
    if (v_6678 == nil) goto v_6406;
    goto v_6428;
v_6424:
    v_6678 = v_6681;
    v_6678 = qcdr(v_6678);
    v_6679 = qcar(v_6678);
    goto v_6425;
v_6426:
    v_6678 = v_6681;
    v_6678 = qcdr(v_6678);
    v_6678 = qcdr(v_6678);
    v_6678 = qcar(v_6678);
    goto v_6427;
v_6428:
    goto v_6424;
v_6425:
    goto v_6426;
v_6427:
    if (v_6679 == v_6678) goto v_6422;
    else goto v_6423;
v_6422:
    v_6678 = lisp_true;
    goto v_6421;
v_6423:
    goto v_6447;
v_6443:
    v_6678 = v_6681;
    v_6678 = qcdr(v_6678);
    v_6679 = qcar(v_6678);
    goto v_6444;
v_6445:
    v_6678 = v_6681;
    v_6678 = qcdr(v_6678);
    v_6678 = qcdr(v_6678);
    v_6678 = qcdr(v_6678);
    v_6678 = qcar(v_6678);
    goto v_6446;
v_6447:
    goto v_6443;
v_6444:
    goto v_6445;
v_6446:
    if (v_6679 == v_6678) goto v_6441;
    else goto v_6442;
v_6441:
    v_6678 = lisp_true;
    goto v_6440;
v_6442:
    goto v_6463;
v_6459:
    v_6678 = v_6681;
    v_6678 = qcdr(v_6678);
    v_6678 = qcdr(v_6678);
    v_6679 = qcar(v_6678);
    goto v_6460;
v_6461:
    v_6678 = v_6681;
    v_6678 = qcdr(v_6678);
    v_6678 = qcdr(v_6678);
    v_6678 = qcdr(v_6678);
    v_6678 = qcar(v_6678);
    goto v_6462;
v_6463:
    goto v_6459;
v_6460:
    goto v_6461;
v_6462:
    v_6678 = (v_6679 == v_6678 ? lisp_true : nil);
    goto v_6440;
    v_6678 = nil;
v_6440:
    goto v_6421;
    v_6678 = nil;
v_6421:
    if (v_6678 == nil) goto v_6419;
    goto v_6481;
v_6475:
    goto v_6488;
v_6484:
    v_6679 = nil;
    goto v_6485;
v_6486:
    v_6678 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6487;
v_6488:
    goto v_6484;
v_6485:
    goto v_6486;
v_6487:
    v_6678 = cons(v_6679, v_6678);
    env = stack[-3];
    v_6680 = ncons(v_6678);
    env = stack[-3];
    goto v_6476;
v_6477:
    v_6679 = stack[-1];
    goto v_6478;
v_6479:
    v_6678 = stack[0];
    goto v_6480;
v_6481:
    goto v_6475;
v_6476:
    goto v_6477;
v_6478:
    goto v_6479;
v_6480:
    stack[-1] = v_6679;
    stack[0] = v_6678;
    goto v_6342;
v_6419:
    goto v_6498;
v_6494:
    v_6678 = v_6680;
    goto v_6495;
v_6496:
    v_6679 = v_6681;
    goto v_6497;
v_6498:
    goto v_6494;
v_6495:
    goto v_6496;
v_6497:
    fn = elt(env, 6); // removeg
    v_6678 = (*qfn2(fn))(fn, v_6678, v_6679);
    env = stack[-3];
    v_6680 = v_6678;
    goto v_6508;
v_6502:
    v_6678 = v_6680;
    stack[-2] = qcar(v_6678);
    goto v_6503;
v_6504:
    v_6678 = v_6680;
    v_6678 = qcdr(v_6678);
    if (v_6678 == nil) goto v_6514;
    goto v_6522;
v_6518:
    v_6678 = v_6680;
    v_6679 = qcdr(v_6678);
    goto v_6519;
v_6520:
    v_6678 = stack[-1];
    goto v_6521;
v_6522:
    goto v_6518;
v_6519:
    goto v_6520;
v_6521:
    v_6678 = cons(v_6679, v_6678);
    env = stack[-3];
    v_6679 = v_6678;
    goto v_6512;
v_6514:
    v_6678 = stack[-1];
    v_6679 = v_6678;
    goto v_6512;
    v_6679 = nil;
v_6512:
    goto v_6505;
v_6506:
    v_6678 = stack[0];
    goto v_6507;
v_6508:
    goto v_6502;
v_6503:
    goto v_6504;
v_6505:
    goto v_6506;
v_6507:
    v_6680 = stack[-2];
    stack[-1] = v_6679;
    stack[0] = v_6678;
    goto v_6342;
v_6406:
    goto v_6536;
v_6532:
    v_6679 = elt(env, 2); // g3
    goto v_6533;
v_6534:
    v_6678 = v_6680;
    v_6678 = qcdr(v_6678);
    goto v_6535;
v_6536:
    goto v_6532;
v_6533:
    goto v_6534;
v_6535:
    v_6678 = Lassoc(nil, v_6679, v_6678);
    v_6681 = v_6678;
    if (v_6678 == nil) goto v_6531;
    goto v_6553;
v_6549:
    v_6678 = v_6681;
    v_6678 = qcdr(v_6678);
    v_6679 = qcar(v_6678);
    goto v_6550;
v_6551:
    v_6678 = v_6681;
    v_6678 = qcdr(v_6678);
    v_6678 = qcdr(v_6678);
    v_6678 = qcar(v_6678);
    goto v_6552;
v_6553:
    goto v_6549;
v_6550:
    goto v_6551;
v_6552:
    if (v_6679 == v_6678) goto v_6547;
    else goto v_6548;
v_6547:
    v_6678 = lisp_true;
    goto v_6546;
v_6548:
    goto v_6572;
v_6568:
    v_6678 = v_6681;
    v_6678 = qcdr(v_6678);
    v_6679 = qcar(v_6678);
    goto v_6569;
v_6570:
    v_6678 = v_6681;
    v_6678 = qcdr(v_6678);
    v_6678 = qcdr(v_6678);
    v_6678 = qcdr(v_6678);
    v_6678 = qcar(v_6678);
    goto v_6571;
v_6572:
    goto v_6568;
v_6569:
    goto v_6570;
v_6571:
    if (v_6679 == v_6678) goto v_6566;
    else goto v_6567;
v_6566:
    v_6678 = lisp_true;
    goto v_6565;
v_6567:
    goto v_6588;
v_6584:
    v_6678 = v_6681;
    v_6678 = qcdr(v_6678);
    v_6678 = qcdr(v_6678);
    v_6679 = qcar(v_6678);
    goto v_6585;
v_6586:
    v_6678 = v_6681;
    v_6678 = qcdr(v_6678);
    v_6678 = qcdr(v_6678);
    v_6678 = qcdr(v_6678);
    v_6678 = qcar(v_6678);
    goto v_6587;
v_6588:
    goto v_6584;
v_6585:
    goto v_6586;
v_6587:
    v_6678 = (v_6679 == v_6678 ? lisp_true : nil);
    goto v_6565;
    v_6678 = nil;
v_6565:
    goto v_6546;
    v_6678 = nil;
v_6546:
    if (v_6678 == nil) goto v_6544;
    goto v_6606;
v_6600:
    goto v_6613;
v_6609:
    v_6679 = nil;
    goto v_6610;
v_6611:
    v_6678 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6612;
v_6613:
    goto v_6609;
v_6610:
    goto v_6611;
v_6612:
    v_6678 = cons(v_6679, v_6678);
    env = stack[-3];
    v_6680 = ncons(v_6678);
    env = stack[-3];
    goto v_6601;
v_6602:
    v_6679 = stack[-1];
    goto v_6603;
v_6604:
    v_6678 = stack[0];
    goto v_6605;
v_6606:
    goto v_6600;
v_6601:
    goto v_6602;
v_6603:
    goto v_6604;
v_6605:
    stack[-1] = v_6679;
    stack[0] = v_6678;
    goto v_6342;
v_6544:
    goto v_6623;
v_6619:
    v_6678 = v_6680;
    goto v_6620;
v_6621:
    v_6679 = v_6681;
    goto v_6622;
v_6623:
    goto v_6619;
v_6620:
    goto v_6621;
v_6622:
    fn = elt(env, 7); // split3gv
    v_6678 = (*qfn2(fn))(fn, v_6678, v_6679);
    env = stack[-3];
    v_6680 = v_6678;
    goto v_6633;
v_6627:
    v_6678 = v_6680;
    stack[-2] = qcar(v_6678);
    goto v_6628;
v_6629:
    goto v_6641;
v_6637:
    v_6678 = v_6680;
    v_6679 = qcdr(v_6678);
    goto v_6638;
v_6639:
    v_6678 = stack[-1];
    goto v_6640;
v_6641:
    goto v_6637;
v_6638:
    goto v_6639;
v_6640:
    v_6679 = cons(v_6679, v_6678);
    env = stack[-3];
    goto v_6630;
v_6631:
    v_6678 = stack[0];
    goto v_6632;
v_6633:
    goto v_6627;
v_6628:
    goto v_6629;
v_6630:
    goto v_6631;
v_6632:
    v_6680 = stack[-2];
    stack[-1] = v_6679;
    stack[0] = v_6678;
    goto v_6342;
v_6531:
    goto v_6654;
v_6650:
    stack[0] = elt(env, 3); // "Invalid structure of c0-graph."
    goto v_6651;
v_6652:
    v_6678 = v_6680;
    if (v_6678 == nil) goto v_6658;
    else goto v_6659;
v_6658:
    v_6678 = nil;
    goto v_6657;
v_6659:
    v_6678 = v_6680;
    v_6678 = qcdr(v_6678);
    if (v_6678 == nil) goto v_6662;
    else goto v_6663;
v_6662:
    v_6678 = v_6680;
    v_6678 = qcar(v_6678);
    goto v_6657;
v_6663:
    goto v_6675;
v_6671:
    v_6678 = elt(env, 4); // times
    goto v_6672;
v_6673:
    v_6679 = v_6680;
    goto v_6674;
v_6675:
    goto v_6671;
v_6672:
    goto v_6673;
v_6674:
    v_6678 = cons(v_6678, v_6679);
    env = stack[-3];
    goto v_6657;
    v_6678 = nil;
v_6657:
    goto v_6653;
v_6654:
    goto v_6650;
v_6651:
    goto v_6652;
v_6653:
    v_6678 = list2(stack[0], v_6678);
    env = stack[-3];
    fn = elt(env, 8); // cerror
    v_6678 = (*qfn1(fn))(fn, v_6678);
    goto v_6404;
v_6404:
    v_6678 = nil;
    goto v_6349;
v_6352:
    v_6678 = nil;
v_6349:
    return onevalue(v_6678);
}



// Code for msappend

static LispObject CC_msappend(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6414, v_6415;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_6344;
    v_6414 = v_6343;
// end of prologue
    stack[-5] = v_6414;
    v_6414 = stack[-5];
    if (v_6414 == nil) goto v_6355;
    else goto v_6356;
v_6355:
    v_6414 = nil;
    goto v_6350;
v_6356:
    v_6414 = stack[-5];
    v_6414 = qcar(v_6414);
    goto v_6368;
v_6364:
    stack[0] = stack[-4];
    goto v_6365;
v_6366:
    goto v_6375;
v_6371:
    v_6415 = stack[-4];
    goto v_6372;
v_6373:
    goto v_6374;
v_6375:
    goto v_6371;
v_6372:
    goto v_6373;
v_6374:
    v_6414 = Lsublis(nil, v_6415, v_6414);
    env = stack[-6];
    goto v_6367;
v_6368:
    goto v_6364;
v_6365:
    goto v_6366;
v_6367:
    v_6414 = Lappend(nil, stack[0], v_6414);
    env = stack[-6];
    v_6414 = ncons(v_6414);
    env = stack[-6];
    stack[-2] = v_6414;
    stack[-3] = v_6414;
v_6351:
    v_6414 = stack[-5];
    v_6414 = qcdr(v_6414);
    stack[-5] = v_6414;
    v_6414 = stack[-5];
    if (v_6414 == nil) goto v_6382;
    else goto v_6383;
v_6382:
    v_6414 = stack[-3];
    goto v_6350;
v_6383:
    goto v_6391;
v_6387:
    stack[-1] = stack[-2];
    goto v_6388;
v_6389:
    v_6414 = stack[-5];
    v_6414 = qcar(v_6414);
    goto v_6402;
v_6398:
    stack[0] = stack[-4];
    goto v_6399;
v_6400:
    goto v_6409;
v_6405:
    v_6415 = stack[-4];
    goto v_6406;
v_6407:
    goto v_6408;
v_6409:
    goto v_6405;
v_6406:
    goto v_6407;
v_6408:
    v_6414 = Lsublis(nil, v_6415, v_6414);
    env = stack[-6];
    goto v_6401;
v_6402:
    goto v_6398;
v_6399:
    goto v_6400;
v_6401:
    v_6414 = Lappend(nil, stack[0], v_6414);
    env = stack[-6];
    v_6414 = ncons(v_6414);
    env = stack[-6];
    goto v_6390;
v_6391:
    goto v_6387;
v_6388:
    goto v_6389;
v_6390:
    v_6414 = Lrplacd(nil, stack[-1], v_6414);
    env = stack[-6];
    v_6414 = stack[-2];
    v_6414 = qcdr(v_6414);
    stack[-2] = v_6414;
    goto v_6351;
v_6350:
    return onevalue(v_6414);
}



// Code for cl_simpl

static LispObject CC_cl_simpl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6425, v_6426, v_6427, v_6428;
    LispObject fn;
    LispObject v_6345, v_6344, v_6343;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cl_simpl");
    va_start(aa, nargs);
    v_6343 = va_arg(aa, LispObject);
    v_6344 = va_arg(aa, LispObject);
    v_6345 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_6345,v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_6343,v_6344,v_6345);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_6345;
    v_6426 = v_6344;
    stack[-3] = v_6343;
// end of prologue
    v_6425 = qvalue(elt(env, 1)); // !*rlsism
    if (v_6425 == nil) goto v_6352;
    else goto v_6353;
v_6352:
    goto v_6364;
v_6356:
    v_6428 = stack[-3];
    goto v_6357;
v_6358:
    v_6427 = nil;
    goto v_6359;
v_6360:
    v_6426 = stack[-2];
    goto v_6361;
v_6362:
    v_6425 = nil;
    goto v_6363;
v_6364:
    goto v_6356;
v_6357:
    goto v_6358;
v_6359:
    goto v_6360;
v_6361:
    goto v_6362;
v_6363:
    {
        fn = elt(env, 5); // cl_simpl1
        return (*qfnn(fn))(fn, 4, v_6428, v_6427, v_6426, v_6425);
    }
v_6353:
    v_6425 = v_6426;
    fn = elt(env, 6); // cl_sitheo
    v_6425 = (*qfn1(fn))(fn, v_6425);
    env = stack[-5];
    v_6426 = v_6425;
    goto v_6379;
v_6375:
    v_6427 = v_6426;
    goto v_6376;
v_6377:
    v_6425 = elt(env, 2); // inctheo
    goto v_6378;
v_6379:
    goto v_6375;
v_6376:
    goto v_6377;
v_6378:
    if (v_6427 == v_6425) goto v_6373;
    else goto v_6374;
v_6373:
    v_6425 = elt(env, 2); // inctheo
    {
        fn = elt(env, 7); // rl_exc
        return (*qfn1(fn))(fn, v_6425);
    }
v_6374:
    goto v_6393;
v_6385:
    stack[-4] = elt(env, 3); // and
    goto v_6386;
v_6387:
    stack[-1] = v_6426;
    goto v_6388;
v_6389:
    stack[0] = nil;
    goto v_6390;
v_6391:
    v_6425 = stack[-2];
    v_6425 = add1(v_6425);
    env = stack[-5];
    goto v_6392;
v_6393:
    goto v_6385;
v_6386:
    goto v_6387;
v_6388:
    goto v_6389;
v_6390:
    goto v_6391;
v_6392:
    fn = elt(env, 8); // rl_smupdknowl
    v_6425 = (*qfnn(fn))(fn, 4, stack[-4], stack[-1], stack[0], v_6425);
    env = stack[-5];
    v_6426 = v_6425;
    goto v_6407;
v_6403:
    v_6427 = v_6426;
    goto v_6404;
v_6405:
    v_6425 = elt(env, 4); // false
    goto v_6406;
v_6407:
    goto v_6403;
v_6404:
    goto v_6405;
v_6406:
    if (v_6427 == v_6425) goto v_6401;
    else goto v_6402;
v_6401:
    v_6425 = elt(env, 2); // inctheo
    goto v_6349;
v_6402:
    goto v_6420;
v_6412:
    v_6428 = stack[-3];
    goto v_6413;
v_6414:
    v_6427 = v_6426;
    goto v_6415;
v_6416:
    v_6426 = stack[-2];
    goto v_6417;
v_6418:
    v_6425 = nil;
    goto v_6419;
v_6420:
    goto v_6412;
v_6413:
    goto v_6414;
v_6415:
    goto v_6416;
v_6417:
    goto v_6418;
v_6419:
    {
        fn = elt(env, 5); // cl_simpl1
        return (*qfnn(fn))(fn, 4, v_6428, v_6427, v_6426, v_6425);
    }
v_6349:
    return onevalue(v_6425);
}



// Code for qsort

static LispObject CC_qsort(LispObject env,
                         LispObject v_6343)
{
    env = qenv(env);
    LispObject v_6420, v_6421;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6343);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_6421 = v_6343;
// end of prologue
    stack[-2] = nil;
    stack[-1] = nil;
    v_6420 = v_6421;
    if (v_6420 == nil) goto v_6355;
    else goto v_6356;
v_6355:
    v_6420 = nil;
    goto v_6350;
v_6356:
    v_6420 = v_6421;
    v_6420 = qcar(v_6420);
    stack[-3] = v_6420;
    v_6420 = v_6421;
    v_6420 = qcdr(v_6420);
    stack[0] = v_6420;
v_6351:
    v_6420 = stack[0];
    if (v_6420 == nil) goto v_6365;
    else goto v_6366;
v_6365:
    goto v_6352;
v_6366:
    goto v_6377;
v_6373:
    v_6421 = stack[-3];
    goto v_6374;
v_6375:
    v_6420 = stack[0];
    v_6420 = qcar(v_6420);
    goto v_6376;
v_6377:
    goto v_6373;
v_6374:
    goto v_6375;
v_6376:
    fn = elt(env, 1); // ordop
    v_6420 = (*qfn2(fn))(fn, v_6421, v_6420);
    env = stack[-4];
    if (v_6420 == nil) goto v_6371;
    goto v_6386;
v_6382:
    v_6420 = stack[0];
    v_6421 = qcar(v_6420);
    goto v_6383;
v_6384:
    v_6420 = stack[-1];
    goto v_6385;
v_6386:
    goto v_6382;
v_6383:
    goto v_6384;
v_6385:
    v_6420 = cons(v_6421, v_6420);
    env = stack[-4];
    stack[-1] = v_6420;
    goto v_6369;
v_6371:
    goto v_6397;
v_6393:
    v_6420 = stack[0];
    v_6421 = qcar(v_6420);
    goto v_6394;
v_6395:
    v_6420 = stack[-2];
    goto v_6396;
v_6397:
    goto v_6393;
v_6394:
    goto v_6395;
v_6396:
    v_6420 = cons(v_6421, v_6420);
    env = stack[-4];
    stack[-2] = v_6420;
    goto v_6369;
v_6369:
    v_6420 = stack[0];
    v_6420 = qcdr(v_6420);
    stack[0] = v_6420;
    goto v_6351;
v_6352:
    goto v_6408;
v_6404:
    v_6420 = stack[-2];
    stack[0] = CC_qsort(elt(env, 0), v_6420);
    env = stack[-4];
    goto v_6405;
v_6406:
    goto v_6416;
v_6412:
    stack[-2] = stack[-3];
    goto v_6413;
v_6414:
    v_6420 = stack[-1];
    v_6420 = CC_qsort(elt(env, 0), v_6420);
    env = stack[-4];
    goto v_6415;
v_6416:
    goto v_6412;
v_6413:
    goto v_6414;
v_6415:
    v_6420 = cons(stack[-2], v_6420);
    goto v_6407;
v_6408:
    goto v_6404;
v_6405:
    goto v_6406;
v_6407:
    {
        LispObject v_6426 = stack[0];
        return Lappend(nil, v_6426, v_6420);
    }
v_6350:
    return onevalue(v_6420);
}



// Code for ibalp_getnewwl

static LispObject CC_ibalp_getnewwl(LispObject env,
                         LispObject v_6343)
{
    env = qenv(env);
    LispObject v_6451, v_6452, v_6453, v_6454, v_6455;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_6454 = v_6343;
// end of prologue
    v_6453 = nil;
    v_6451 = v_6454;
    v_6451 = qcar(v_6451);
    v_6455 = v_6451;
v_6353:
    v_6451 = v_6455;
    if (v_6451 == nil) goto v_6356;
    v_6451 = v_6453;
    if (v_6451 == nil) goto v_6360;
    else goto v_6356;
v_6360:
    goto v_6357;
v_6356:
    goto v_6352;
v_6357:
    v_6451 = v_6455;
    v_6451 = qcar(v_6451);
    v_6451 = qcdr(v_6451);
    v_6451 = qcar(v_6451);
    if (v_6451 == nil) goto v_6369;
    else goto v_6370;
v_6369:
    goto v_6379;
v_6375:
    v_6451 = v_6455;
    v_6452 = qcar(v_6451);
    goto v_6376;
v_6377:
    v_6451 = v_6454;
    v_6451 = qcdr(v_6451);
    v_6451 = qcdr(v_6451);
    v_6451 = qcdr(v_6451);
    v_6451 = qcdr(v_6451);
    v_6451 = qcdr(v_6451);
    v_6451 = qcdr(v_6451);
    v_6451 = qcar(v_6451);
    goto v_6378;
v_6379:
    goto v_6375;
v_6376:
    goto v_6377;
v_6378:
    v_6451 = Lmemq(nil, v_6452, v_6451);
    v_6451 = (v_6451 == nil ? lisp_true : nil);
    goto v_6368;
v_6370:
    v_6451 = nil;
    goto v_6368;
    v_6451 = nil;
v_6368:
    if (v_6451 == nil) goto v_6366;
    v_6451 = v_6455;
    v_6451 = qcar(v_6451);
    v_6453 = v_6451;
    goto v_6364;
v_6366:
v_6364:
    v_6451 = v_6455;
    v_6451 = qcdr(v_6451);
    v_6455 = v_6451;
    goto v_6353;
v_6352:
    v_6451 = v_6454;
    v_6451 = qcdr(v_6451);
    v_6451 = qcar(v_6451);
    v_6455 = v_6451;
v_6404:
    v_6451 = v_6455;
    if (v_6451 == nil) goto v_6407;
    v_6451 = v_6453;
    if (v_6451 == nil) goto v_6411;
    else goto v_6407;
v_6411:
    goto v_6408;
v_6407:
    goto v_6403;
v_6408:
    v_6451 = v_6455;
    v_6451 = qcar(v_6451);
    v_6451 = qcdr(v_6451);
    v_6451 = qcar(v_6451);
    if (v_6451 == nil) goto v_6420;
    else goto v_6421;
v_6420:
    goto v_6430;
v_6426:
    v_6451 = v_6455;
    v_6452 = qcar(v_6451);
    goto v_6427;
v_6428:
    v_6451 = v_6454;
    v_6451 = qcdr(v_6451);
    v_6451 = qcdr(v_6451);
    v_6451 = qcdr(v_6451);
    v_6451 = qcdr(v_6451);
    v_6451 = qcdr(v_6451);
    v_6451 = qcdr(v_6451);
    v_6451 = qcar(v_6451);
    goto v_6429;
v_6430:
    goto v_6426;
v_6427:
    goto v_6428;
v_6429:
    v_6451 = Lmemq(nil, v_6452, v_6451);
    v_6451 = (v_6451 == nil ? lisp_true : nil);
    goto v_6419;
v_6421:
    v_6451 = nil;
    goto v_6419;
    v_6451 = nil;
v_6419:
    if (v_6451 == nil) goto v_6417;
    v_6451 = v_6455;
    v_6451 = qcar(v_6451);
    v_6453 = v_6451;
    goto v_6415;
v_6417:
v_6415:
    v_6451 = v_6455;
    v_6451 = qcdr(v_6451);
    v_6455 = v_6451;
    goto v_6404;
v_6403:
    v_6451 = v_6453;
    return onevalue(v_6451);
}



// Code for omiir

static LispObject CC_omiir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6352;
    LispObject fn;
    argcheck(nargs, 0, "omiir");
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
    fn = elt(env, 2); // lex
    v_6352 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_6352 = qvalue(elt(env, 1)); // char
    v_6352 = Lcompress(nil, v_6352);
    env = stack[-1];
    stack[0] = v_6352;
    fn = elt(env, 2); // lex
    v_6352 = (*qfnn(fn))(fn, 0);
    v_6352 = stack[0];
    return onevalue(v_6352);
}



// Code for c!:extadd

static LispObject CC_cTextadd(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6475, v_6476, v_6477;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_6344;
    stack[-1] = v_6343;
// end of prologue
    stack[-2] = nil;
v_6351:
    v_6475 = stack[-1];
    if (v_6475 == nil) goto v_6355;
    else goto v_6356;
v_6355:
    v_6475 = stack[0];
    v_6476 = v_6475;
    goto v_6352;
v_6356:
    v_6475 = stack[0];
    if (v_6475 == nil) goto v_6359;
    else goto v_6360;
v_6359:
    v_6475 = stack[-1];
    v_6476 = v_6475;
    goto v_6352;
v_6360:
    goto v_6369;
v_6365:
    v_6475 = stack[-1];
    v_6475 = qcar(v_6475);
    v_6476 = qcar(v_6475);
    goto v_6366;
v_6367:
    v_6475 = stack[0];
    v_6475 = qcar(v_6475);
    v_6475 = qcar(v_6475);
    goto v_6368;
v_6369:
    goto v_6365;
v_6366:
    goto v_6367;
v_6368:
    if (equal(v_6476, v_6475)) goto v_6363;
    else goto v_6364;
v_6363:
    goto v_6381;
v_6377:
    v_6475 = stack[-1];
    v_6475 = qcar(v_6475);
    v_6476 = qcdr(v_6475);
    goto v_6378;
v_6379:
    v_6475 = stack[0];
    v_6475 = qcar(v_6475);
    v_6475 = qcdr(v_6475);
    goto v_6380;
v_6381:
    goto v_6377;
v_6378:
    goto v_6379;
v_6380:
    fn = elt(env, 1); // addf
    v_6475 = (*qfn2(fn))(fn, v_6476, v_6475);
    env = stack[-3];
    v_6476 = v_6475;
    if (v_6476 == nil) goto v_6390;
    else goto v_6391;
v_6390:
    v_6475 = stack[-1];
    v_6475 = qcdr(v_6475);
    stack[-1] = v_6475;
    v_6475 = stack[0];
    v_6475 = qcdr(v_6475);
    stack[0] = v_6475;
    goto v_6351;
v_6391:
    goto v_6406;
v_6400:
    v_6476 = stack[-1];
    v_6476 = qcar(v_6476);
    v_6477 = qcar(v_6476);
    goto v_6401;
v_6402:
    v_6476 = v_6475;
    goto v_6403;
v_6404:
    v_6475 = stack[-2];
    goto v_6405;
v_6406:
    goto v_6400;
v_6401:
    goto v_6402;
v_6403:
    goto v_6404;
v_6405:
    v_6475 = acons(v_6477, v_6476, v_6475);
    env = stack[-3];
    stack[-2] = v_6475;
    v_6475 = stack[-1];
    v_6475 = qcdr(v_6475);
    stack[-1] = v_6475;
    v_6475 = stack[0];
    v_6475 = qcdr(v_6475);
    stack[0] = v_6475;
    goto v_6351;
    goto v_6354;
v_6364:
    goto v_6423;
v_6419:
    v_6475 = stack[-1];
    v_6475 = qcar(v_6475);
    v_6476 = qcar(v_6475);
    goto v_6420;
v_6421:
    v_6475 = stack[0];
    v_6475 = qcar(v_6475);
    v_6475 = qcar(v_6475);
    goto v_6422;
v_6423:
    goto v_6419;
v_6420:
    goto v_6421;
v_6422:
    fn = elt(env, 2); // c!:ordexp
    v_6475 = (*qfn2(fn))(fn, v_6476, v_6475);
    env = stack[-3];
    if (v_6475 == nil) goto v_6417;
    goto v_6435;
v_6431:
    v_6475 = stack[-1];
    v_6476 = qcar(v_6475);
    goto v_6432;
v_6433:
    v_6475 = stack[-2];
    goto v_6434;
v_6435:
    goto v_6431;
v_6432:
    goto v_6433;
v_6434:
    v_6475 = cons(v_6476, v_6475);
    env = stack[-3];
    stack[-2] = v_6475;
    v_6475 = stack[-1];
    v_6475 = qcdr(v_6475);
    stack[-1] = v_6475;
    goto v_6351;
v_6417:
    goto v_6448;
v_6444:
    v_6475 = stack[0];
    v_6476 = qcar(v_6475);
    goto v_6445;
v_6446:
    v_6475 = stack[-2];
    goto v_6447;
v_6448:
    goto v_6444;
v_6445:
    goto v_6446;
v_6447:
    v_6475 = cons(v_6476, v_6475);
    env = stack[-3];
    stack[-2] = v_6475;
    v_6475 = stack[0];
    v_6475 = qcdr(v_6475);
    stack[0] = v_6475;
    goto v_6351;
v_6354:
v_6352:
v_6456:
    v_6475 = stack[-2];
    if (v_6475 == nil) goto v_6459;
    else goto v_6460;
v_6459:
    goto v_6455;
v_6460:
    goto v_6468;
v_6464:
    v_6475 = stack[-2];
    v_6475 = qcar(v_6475);
    goto v_6465;
v_6466:
    goto v_6467;
v_6468:
    goto v_6464;
v_6465:
    goto v_6466;
v_6467:
    v_6475 = cons(v_6475, v_6476);
    env = stack[-3];
    v_6476 = v_6475;
    v_6475 = stack[-2];
    v_6475 = qcdr(v_6475);
    stack[-2] = v_6475;
    goto v_6456;
v_6455:
    v_6475 = v_6476;
    return onevalue(v_6475);
}



// Code for comm_kernels1

static LispObject CC_comm_kernels1(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6414, v_6415;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_6344;
    v_6414 = v_6343;
// end of prologue
v_6342:
    v_6415 = v_6414;
    if (!consp(v_6415)) goto v_6352;
    else goto v_6353;
v_6352:
    v_6415 = lisp_true;
    goto v_6351;
v_6353:
    v_6415 = v_6414;
    v_6415 = qcar(v_6415);
    v_6415 = (consp(v_6415) ? nil : lisp_true);
    goto v_6351;
    v_6415 = nil;
v_6351:
    if (v_6415 == nil) goto v_6349;
    v_6414 = stack[-2];
    goto v_6347;
v_6349:
    v_6415 = v_6414;
    v_6415 = qcar(v_6415);
    v_6415 = qcar(v_6415);
    v_6415 = qcar(v_6415);
    stack[-3] = v_6415;
    goto v_6374;
v_6370:
    v_6415 = v_6414;
    v_6415 = qcar(v_6415);
    stack[-1] = qcdr(v_6415);
    goto v_6371;
v_6372:
    goto v_6383;
v_6379:
    stack[0] = qcdr(v_6414);
    goto v_6380;
v_6381:
    goto v_6395;
v_6391:
    v_6415 = stack[-3];
    goto v_6392;
v_6393:
    v_6414 = stack[-2];
    goto v_6394;
v_6395:
    goto v_6391;
v_6392:
    goto v_6393;
v_6394:
    v_6414 = Lmemq(nil, v_6415, v_6414);
    if (v_6414 == nil) goto v_6390;
    else goto v_6388;
v_6390:
    v_6414 = stack[-3];
    fn = elt(env, 1); // noncomp
    v_6414 = (*qfn1(fn))(fn, v_6414);
    env = stack[-4];
    if (v_6414 == nil) goto v_6399;
    else goto v_6388;
v_6399:
    goto v_6389;
v_6388:
    v_6414 = stack[-2];
    goto v_6387;
v_6389:
    goto v_6410;
v_6406:
    goto v_6407;
v_6408:
    v_6414 = stack[-3];
    v_6414 = ncons(v_6414);
    env = stack[-4];
    goto v_6409;
v_6410:
    goto v_6406;
v_6407:
    goto v_6408;
v_6409:
    v_6414 = Lappend(nil, stack[-2], v_6414);
    env = stack[-4];
    goto v_6387;
    v_6414 = nil;
v_6387:
    goto v_6382;
v_6383:
    goto v_6379;
v_6380:
    goto v_6381;
v_6382:
    v_6415 = CC_comm_kernels1(elt(env, 0), stack[0], v_6414);
    env = stack[-4];
    goto v_6373;
v_6374:
    goto v_6370;
v_6371:
    goto v_6372;
v_6373:
    v_6414 = stack[-1];
    stack[-2] = v_6415;
    goto v_6342;
    v_6414 = nil;
v_6347:
    return onevalue(v_6414);
}



// Code for addpf

static LispObject CC_addpf(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6530, v_6531, v_6532;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_6344;
    stack[-2] = v_6343;
// end of prologue
    stack[0] = nil;
v_6349:
    v_6530 = stack[-2];
    if (v_6530 == nil) goto v_6352;
    else goto v_6353;
v_6352:
    goto v_6360;
v_6356:
    v_6531 = stack[0];
    goto v_6357;
v_6358:
    v_6530 = stack[-1];
    goto v_6359;
v_6360:
    goto v_6356;
v_6357:
    goto v_6358;
v_6359:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_6531, v_6530);
    }
v_6353:
    v_6530 = stack[-1];
    if (v_6530 == nil) goto v_6363;
    else goto v_6364;
v_6363:
    goto v_6371;
v_6367:
    v_6531 = stack[0];
    goto v_6368;
v_6369:
    v_6530 = stack[-2];
    goto v_6370;
v_6371:
    goto v_6367;
v_6368:
    goto v_6369;
v_6370:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_6531, v_6530);
    }
v_6364:
    goto v_6380;
v_6376:
    v_6530 = stack[-2];
    v_6530 = qcar(v_6530);
    v_6531 = qcar(v_6530);
    goto v_6377;
v_6378:
    v_6530 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6379;
v_6380:
    goto v_6376;
v_6377:
    goto v_6378;
v_6379:
    if (v_6531 == v_6530) goto v_6374;
    else goto v_6375;
v_6374:
    goto v_6390;
v_6386:
    goto v_6387;
v_6388:
    goto v_6397;
v_6393:
    v_6531 = stack[-2];
    goto v_6394;
v_6395:
    v_6530 = stack[-1];
    goto v_6396;
v_6397:
    goto v_6393;
v_6394:
    goto v_6395;
v_6396:
    fn = elt(env, 2); // addmpf
    v_6530 = (*qfn2(fn))(fn, v_6531, v_6530);
    env = stack[-4];
    goto v_6389;
v_6390:
    goto v_6386;
v_6387:
    goto v_6388;
v_6389:
    {
        LispObject v_6537 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_6537, v_6530);
    }
v_6375:
    goto v_6406;
v_6402:
    v_6530 = stack[-1];
    v_6530 = qcar(v_6530);
    v_6531 = qcar(v_6530);
    goto v_6403;
v_6404:
    v_6530 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6405;
v_6406:
    goto v_6402;
v_6403:
    goto v_6404;
v_6405:
    if (v_6531 == v_6530) goto v_6400;
    else goto v_6401;
v_6400:
    goto v_6416;
v_6412:
    goto v_6413;
v_6414:
    goto v_6423;
v_6419:
    v_6531 = stack[-1];
    goto v_6420;
v_6421:
    v_6530 = stack[-2];
    goto v_6422;
v_6423:
    goto v_6419;
v_6420:
    goto v_6421;
v_6422:
    fn = elt(env, 2); // addmpf
    v_6530 = (*qfn2(fn))(fn, v_6531, v_6530);
    env = stack[-4];
    goto v_6415;
v_6416:
    goto v_6412;
v_6413:
    goto v_6414;
v_6415:
    {
        LispObject v_6538 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_6538, v_6530);
    }
v_6401:
    goto v_6432;
v_6428:
    v_6530 = stack[-2];
    v_6530 = qcar(v_6530);
    v_6531 = qcar(v_6530);
    goto v_6429;
v_6430:
    v_6530 = stack[-1];
    v_6530 = qcar(v_6530);
    v_6530 = qcar(v_6530);
    goto v_6431;
v_6432:
    goto v_6428;
v_6429:
    goto v_6430;
v_6431:
    if (equal(v_6531, v_6530)) goto v_6426;
    else goto v_6427;
v_6426:
    goto v_6444;
v_6440:
    stack[-3] = stack[0];
    goto v_6441;
v_6442:
    goto v_6451;
v_6447:
    v_6530 = stack[-2];
    v_6530 = qcar(v_6530);
    v_6531 = qcdr(v_6530);
    goto v_6448;
v_6449:
    v_6530 = stack[-1];
    v_6530 = qcar(v_6530);
    v_6530 = qcdr(v_6530);
    goto v_6450;
v_6451:
    goto v_6447;
v_6448:
    goto v_6449;
v_6450:
    fn = elt(env, 3); // addsq
    stack[0] = (*qfn2(fn))(fn, v_6531, v_6530);
    env = stack[-4];
    goto v_6463;
v_6459:
    v_6530 = stack[-2];
    v_6531 = qcdr(v_6530);
    goto v_6460;
v_6461:
    v_6530 = stack[-1];
    v_6530 = qcdr(v_6530);
    goto v_6462;
v_6463:
    goto v_6459;
v_6460:
    goto v_6461;
v_6462:
    v_6530 = CC_addpf(elt(env, 0), v_6531, v_6530);
    env = stack[-4];
    v_6531 = stack[0];
    v_6532 = v_6531;
    v_6532 = qcar(v_6532);
    if (v_6532 == nil) goto v_6472;
    else goto v_6473;
v_6472:
    goto v_6471;
v_6473:
    goto v_6486;
v_6480:
    v_6532 = stack[-2];
    v_6532 = qcar(v_6532);
    v_6532 = qcar(v_6532);
    goto v_6481;
v_6482:
    goto v_6483;
v_6484:
    goto v_6485;
v_6486:
    goto v_6480;
v_6481:
    goto v_6482;
v_6483:
    goto v_6484;
v_6485:
    v_6530 = acons(v_6532, v_6531, v_6530);
    env = stack[-4];
    goto v_6471;
    v_6530 = nil;
v_6471:
    goto v_6443;
v_6444:
    goto v_6440;
v_6441:
    goto v_6442;
v_6443:
    {
        LispObject v_6539 = stack[-3];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_6539, v_6530);
    }
v_6427:
    goto v_6499;
v_6495:
    v_6530 = stack[-2];
    v_6530 = qcar(v_6530);
    v_6531 = qcar(v_6530);
    goto v_6496;
v_6497:
    v_6530 = stack[-1];
    v_6530 = qcar(v_6530);
    v_6530 = qcar(v_6530);
    goto v_6498;
v_6499:
    goto v_6495;
v_6496:
    goto v_6497;
v_6498:
    fn = elt(env, 4); // termordp!!
    v_6530 = (*qfn2(fn))(fn, v_6531, v_6530);
    env = stack[-4];
    if (v_6530 == nil) goto v_6493;
    goto v_6511;
v_6507:
    v_6530 = stack[-2];
    v_6531 = qcar(v_6530);
    goto v_6508;
v_6509:
    v_6530 = stack[0];
    goto v_6510;
v_6511:
    goto v_6507;
v_6508:
    goto v_6509;
v_6510:
    v_6530 = cons(v_6531, v_6530);
    env = stack[-4];
    stack[0] = v_6530;
    v_6530 = stack[-2];
    v_6530 = qcdr(v_6530);
    stack[-2] = v_6530;
    goto v_6349;
v_6493:
    goto v_6524;
v_6520:
    v_6530 = stack[-1];
    v_6531 = qcar(v_6530);
    goto v_6521;
v_6522:
    v_6530 = stack[0];
    goto v_6523;
v_6524:
    goto v_6520;
v_6521:
    goto v_6522;
v_6523:
    v_6530 = cons(v_6531, v_6530);
    env = stack[-4];
    stack[0] = v_6530;
    v_6530 = stack[-1];
    v_6530 = qcdr(v_6530);
    stack[-1] = v_6530;
    goto v_6349;
    v_6530 = nil;
    return onevalue(v_6530);
}



// Code for gfrsq

static LispObject CC_gfrsq(LispObject env,
                         LispObject v_6343)
{
    env = qenv(env);
    LispObject v_6353, v_6354;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_6353 = v_6343;
// end of prologue
    goto v_6350;
v_6346:
    v_6354 = v_6353;
    goto v_6347;
v_6348:
    goto v_6349;
v_6350:
    goto v_6346;
v_6347:
    goto v_6348;
v_6349:
    {
        fn = elt(env, 1); // gfdot
        return (*qfn2(fn))(fn, v_6354, v_6353);
    }
}



// Code for safe!-fp!-times

static LispObject CC_safeKfpKtimes(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6437, v_6438;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_6344;
    stack[-1] = v_6343;
// end of prologue
    goto v_6354;
v_6350:
    v_6438 = stack[-1];
    goto v_6351;
v_6352:
    v_6437 = stack[0];
    goto v_6353;
v_6354:
    goto v_6350;
v_6351:
    goto v_6352;
v_6353:
    v_6437 = times2(v_6438, v_6437);
    env = stack[-3];
    stack[-2] = v_6437;
    goto v_6367;
v_6363:
    v_6438 = stack[-2];
    goto v_6364;
v_6365:
    v_6437 = qvalue(elt(env, 1)); // !!minnorm
    goto v_6366;
v_6367:
    goto v_6363;
v_6364:
    goto v_6365;
v_6366:
    v_6437 = (LispObject)lessp2(v_6438, v_6437);
    v_6437 = v_6437 ? lisp_true : nil;
    env = stack[-3];
    if (v_6437 == nil) goto v_6360;
    goto v_6377;
v_6373:
    v_6438 = stack[-2];
    goto v_6374;
v_6375:
    v_6437 = qvalue(elt(env, 2)); // !!minnegnorm
    goto v_6376;
v_6377:
    goto v_6373;
v_6374:
    goto v_6375;
v_6376:
    v_6437 = (LispObject)greaterp2(v_6438, v_6437);
    v_6437 = v_6437 ? lisp_true : nil;
    env = stack[-3];
    if (v_6437 == nil) goto v_6360;
    goto v_6389;
v_6385:
    v_6438 = stack[-1];
    goto v_6386;
v_6387:
    v_6437 = elt(env, 3); // 0.0
    goto v_6388;
v_6389:
    goto v_6385;
v_6386:
    goto v_6387;
v_6388:
    if (equal(v_6438, v_6437)) goto v_6384;
    goto v_6397;
v_6393:
    v_6438 = stack[0];
    goto v_6394;
v_6395:
    v_6437 = elt(env, 3); // 0.0
    goto v_6396;
v_6397:
    goto v_6393;
v_6394:
    goto v_6395;
v_6396:
    v_6437 = Lneq(nil, v_6438, v_6437);
    env = stack[-3];
    goto v_6382;
v_6384:
    v_6437 = nil;
    goto v_6382;
    v_6437 = nil;
v_6382:
    if (v_6437 == nil) goto v_6360;
    v_6437 = nil;
    goto v_6348;
v_6360:
    v_6437 = qvalue(elt(env, 4)); // !*nonegzerotimes
    if (v_6437 == nil) goto v_6405;
    goto v_6413;
v_6409:
    v_6438 = stack[-2];
    goto v_6410;
v_6411:
    v_6437 = elt(env, 3); // 0.0
    goto v_6412;
v_6413:
    goto v_6409;
v_6410:
    goto v_6411;
v_6412:
    if (equal(v_6438, v_6437)) goto v_6408;
    else goto v_6405;
v_6408:
    v_6437 = elt(env, 3); // 0.0
    goto v_6348;
v_6405:
    goto v_6423;
v_6419:
    goto v_6429;
v_6425:
    v_6438 = stack[-2];
    goto v_6426;
v_6427:
    v_6437 = stack[-2];
    goto v_6428;
v_6429:
    goto v_6425;
v_6426:
    goto v_6427;
v_6428:
    v_6437 = difference2(v_6438, v_6437);
    env = stack[-3];
    goto v_6420;
v_6421:
    v_6438 = elt(env, 3); // 0.0
    goto v_6422;
v_6423:
    goto v_6419;
v_6420:
    goto v_6421;
v_6422:
    if (equal(v_6437, v_6438)) goto v_6417;
    else goto v_6418;
v_6417:
    v_6437 = stack[-2];
    goto v_6348;
v_6418:
    v_6437 = nil;
    goto v_6348;
    v_6437 = nil;
v_6348:
    return onevalue(v_6437);
}



// Code for condterpri

static LispObject CC_condterpri(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6401;
    argcheck(nargs, 0, "condterpri");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_6401 = qvalue(elt(env, 1)); // !*output
    if (v_6401 == nil) goto v_6346;
    else goto v_6347;
v_6346:
    v_6401 = nil;
    goto v_6345;
v_6347:
    v_6401 = qvalue(elt(env, 2)); // !*echo
    if (v_6401 == nil) goto v_6354;
    else goto v_6355;
v_6354:
    v_6401 = nil;
    goto v_6353;
v_6355:
    v_6401 = qvalue(elt(env, 3)); // !*extraecho
    if (v_6401 == nil) goto v_6362;
    else goto v_6363;
v_6362:
    v_6401 = nil;
    goto v_6361;
v_6363:
    v_6401 = qvalue(elt(env, 4)); // !*int
    if (v_6401 == nil) goto v_6374;
    else goto v_6375;
v_6374:
    v_6401 = lisp_true;
    goto v_6373;
v_6375:
    v_6401 = qvalue(elt(env, 5)); // ifl!*
    goto v_6373;
    v_6401 = nil;
v_6373:
    if (v_6401 == nil) goto v_6370;
    else goto v_6371;
v_6370:
    v_6401 = nil;
    goto v_6369;
v_6371:
    v_6401 = qvalue(elt(env, 6)); // !*defn
    if (v_6401 == nil) goto v_6386;
    else goto v_6387;
v_6386:
    v_6401 = qvalue(elt(env, 7)); // !*demo
    if (v_6401 == nil) goto v_6391;
    else goto v_6392;
v_6391:
        return Lterpri(nil, 0);
v_6392:
    v_6401 = nil;
    goto v_6390;
    v_6401 = nil;
v_6390:
    goto v_6385;
v_6387:
    v_6401 = nil;
    goto v_6385;
    v_6401 = nil;
v_6385:
    goto v_6369;
    v_6401 = nil;
v_6369:
    goto v_6361;
    v_6401 = nil;
v_6361:
    goto v_6353;
    v_6401 = nil;
v_6353:
    goto v_6345;
    v_6401 = nil;
v_6345:
    return onevalue(v_6401);
}



// Code for argnochk

static LispObject CC_argnochk(LispObject env,
                         LispObject v_6343)
{
    env = qenv(env);
    LispObject v_6514, v_6515, v_6516;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6343);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_6343;
// end of prologue
    v_6514 = qvalue(elt(env, 1)); // !*argnochk
    if (v_6514 == nil) goto v_6350;
    else goto v_6351;
v_6350:
    v_6514 = stack[-5];
    goto v_6347;
v_6351:
    v_6514 = stack[-5];
    v_6514 = qcar(v_6514);
    fn = elt(env, 11); // argsofopr
    v_6514 = (*qfn1(fn))(fn, v_6514);
    env = stack[-7];
    stack[-6] = v_6514;
    if (v_6514 == nil) goto v_6355;
    goto v_6371;
v_6367:
    stack[0] = stack[-6];
    goto v_6368;
v_6369:
    v_6514 = stack[-5];
    v_6514 = qcdr(v_6514);
    v_6514 = Llength(nil, v_6514);
    env = stack[-7];
    goto v_6370;
v_6371:
    goto v_6367;
v_6368:
    goto v_6369;
v_6370:
    if (equal(stack[0], v_6514)) goto v_6366;
    v_6514 = stack[-5];
    v_6514 = qcar(v_6514);
    if (!symbolp(v_6514)) v_6514 = nil;
    else { v_6514 = qfastgets(v_6514);
           if (v_6514 != nil) { v_6514 = elt(v_6514, 22); // simpfn
#ifdef RECORD_GET
             if (v_6514 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v_6514 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v_6514 == SPID_NOPROP) v_6514 = nil; }}
#endif
    if (v_6514 == nil) goto v_6378;
    else goto v_6377;
v_6378:
    v_6514 = stack[-5];
    v_6514 = qcar(v_6514);
    if (!symbolp(v_6514)) v_6514 = nil;
    else { v_6514 = qfastgets(v_6514);
           if (v_6514 != nil) { v_6514 = elt(v_6514, 45); // psopfn
#ifdef RECORD_GET
             if (v_6514 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v_6514 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v_6514 == SPID_NOPROP) v_6514 = nil; }}
#endif
    if (v_6514 == nil) goto v_6384;
    else goto v_6383;
v_6384:
    goto v_6393;
v_6389:
    v_6514 = stack[-5];
    v_6515 = qcar(v_6514);
    goto v_6390;
v_6391:
    v_6514 = elt(env, 2); // variadic
    goto v_6392;
v_6393:
    goto v_6389;
v_6390:
    goto v_6391;
v_6392:
    v_6514 = Lflagp(nil, v_6515, v_6514);
    env = stack[-7];
v_6383:
v_6377:
    v_6514 = (v_6514 == nil ? lisp_true : nil);
    goto v_6364;
v_6366:
    v_6514 = nil;
    goto v_6364;
    v_6514 = nil;
v_6364:
    if (v_6514 == nil) goto v_6362;
    v_6514 = qvalue(elt(env, 3)); // !*strict_argcount
    if (v_6514 == nil) goto v_6404;
    v_6514 = elt(env, 4); // "+++++ "
    v_6514 = Lprinc(nil, v_6514);
    env = stack[-7];
    v_6514 = stack[-5];
    v_6514 = Lprint(nil, v_6514);
    env = stack[-7];
    goto v_6417;
v_6411:
    stack[-4] = elt(env, 5); // rlisp
    goto v_6412;
v_6413:
    stack[-3] = (LispObject)176+TAG_FIXNUM; // 11
    goto v_6414;
v_6415:
    goto v_6429;
v_6421:
    v_6514 = stack[-5];
    stack[-2] = qcar(v_6514);
    goto v_6422;
v_6423:
    stack[-1] = elt(env, 6); // "called with"
    goto v_6424;
v_6425:
    v_6514 = stack[-5];
    v_6514 = qcdr(v_6514);
    stack[0] = Llength(nil, v_6514);
    env = stack[-7];
    goto v_6426;
v_6427:
    goto v_6443;
v_6437:
    goto v_6452;
v_6448:
    v_6514 = stack[-5];
    v_6514 = qcdr(v_6514);
    v_6515 = Llength(nil, v_6514);
    env = stack[-7];
    goto v_6449;
v_6450:
    v_6514 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6451;
v_6452:
    goto v_6448;
v_6449:
    goto v_6450;
v_6451:
    if (v_6515 == v_6514) goto v_6446;
    else goto v_6447;
v_6446:
    v_6514 = elt(env, 7); // "argument"
    v_6516 = v_6514;
    goto v_6445;
v_6447:
    v_6514 = elt(env, 8); // "arguments"
    v_6516 = v_6514;
    goto v_6445;
    v_6516 = nil;
v_6445:
    goto v_6438;
v_6439:
    v_6515 = elt(env, 9); // "instead of"
    goto v_6440;
v_6441:
    v_6514 = stack[-6];
    goto v_6442;
v_6443:
    goto v_6437;
v_6438:
    goto v_6439;
v_6440:
    goto v_6441;
v_6442:
    v_6514 = list3(v_6516, v_6515, v_6514);
    env = stack[-7];
    goto v_6428;
v_6429:
    goto v_6421;
v_6422:
    goto v_6423;
v_6424:
    goto v_6425;
v_6426:
    goto v_6427;
v_6428:
    v_6514 = list3star(stack[-2], stack[-1], stack[0], v_6514);
    env = stack[-7];
    goto v_6416;
v_6417:
    goto v_6411;
v_6412:
    goto v_6413;
v_6414:
    goto v_6415;
v_6416:
    fn = elt(env, 12); // rerror
    v_6514 = (*qfnn(fn))(fn, 3, stack[-4], stack[-3], v_6514);
    goto v_6402;
v_6404:
    goto v_6475;
v_6467:
    v_6514 = stack[-5];
    stack[-2] = qcar(v_6514);
    goto v_6468;
v_6469:
    stack[-1] = elt(env, 6); // "called with"
    goto v_6470;
v_6471:
    v_6514 = stack[-5];
    v_6514 = qcdr(v_6514);
    stack[0] = Llength(nil, v_6514);
    env = stack[-7];
    goto v_6472;
v_6473:
    goto v_6489;
v_6483:
    v_6516 = elt(env, 9); // "instead of"
    goto v_6484;
v_6485:
    v_6515 = stack[-6];
    goto v_6486;
v_6487:
    v_6514 = elt(env, 8); // "arguments"
    goto v_6488;
v_6489:
    goto v_6483;
v_6484:
    goto v_6485;
v_6486:
    goto v_6487;
v_6488:
    v_6514 = list3(v_6516, v_6515, v_6514);
    env = stack[-7];
    goto v_6474;
v_6475:
    goto v_6467;
v_6468:
    goto v_6469;
v_6470:
    goto v_6471;
v_6472:
    goto v_6473;
v_6474:
    v_6514 = list3star(stack[-2], stack[-1], stack[0], v_6514);
    env = stack[-7];
    fn = elt(env, 13); // lprim
    v_6514 = (*qfn1(fn))(fn, v_6514);
    v_6514 = stack[-5];
    goto v_6347;
v_6402:
    goto v_6360;
v_6362:
    v_6514 = stack[-5];
    goto v_6347;
v_6360:
    goto v_6349;
v_6355:
    goto v_6506;
v_6500:
    v_6514 = stack[-5];
    stack[-1] = qcar(v_6514);
    goto v_6501;
v_6502:
    stack[0] = elt(env, 10); // number!-of!-args
    goto v_6503;
v_6504:
    v_6514 = stack[-5];
    v_6514 = qcdr(v_6514);
    v_6514 = Llength(nil, v_6514);
    env = stack[-7];
    goto v_6505;
v_6506:
    goto v_6500;
v_6501:
    goto v_6502;
v_6503:
    goto v_6504;
v_6505:
    v_6514 = Lputprop(nil, 3, stack[-1], stack[0], v_6514);
    v_6514 = stack[-5];
    goto v_6347;
v_6349:
    v_6514 = nil;
v_6347:
    return onevalue(v_6514);
}



// Code for make!-term

static LispObject CC_makeKterm(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6559, v_6560, v_6561;
    LispObject fn;
    LispObject v_6345, v_6344, v_6343;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "make-term");
    va_start(aa, nargs);
    v_6343 = va_arg(aa, LispObject);
    v_6344 = va_arg(aa, LispObject);
    v_6345 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_6345,v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_6343,v_6344,v_6345);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_6345;
    stack[-4] = v_6344;
    stack[-5] = v_6343;
// end of prologue
    v_6559 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_6559;
    v_6559 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_6559;
v_6352:
    goto v_6364;
v_6360:
    goto v_6369;
v_6365:
    v_6560 = stack[-4];
    goto v_6366;
v_6367:
    v_6559 = stack[0];
    goto v_6368;
v_6369:
    goto v_6365;
v_6366:
    goto v_6367;
v_6368:
    v_6560 = *(LispObject *)((char *)v_6560 + (CELL-TAG_VECTOR) + (((intptr_t)v_6559-TAG_FIXNUM)/(16/CELL)));
    goto v_6361;
v_6362:
    v_6559 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6363;
v_6364:
    goto v_6360;
v_6361:
    goto v_6362;
v_6363:
    v_6559 = (LispObject)lessp2(v_6560, v_6559);
    v_6559 = v_6559 ? lisp_true : nil;
    env = stack[-7];
    if (v_6559 == nil) goto v_6358;
    v_6559 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[-2] = v_6559;
    goto v_6356;
v_6358:
    goto v_6382;
v_6378:
    goto v_6387;
v_6383:
    v_6560 = stack[-4];
    goto v_6384;
v_6385:
    v_6559 = stack[0];
    goto v_6386;
v_6387:
    goto v_6383;
v_6384:
    goto v_6385;
v_6386:
    v_6560 = *(LispObject *)((char *)v_6560 + (CELL-TAG_VECTOR) + (((intptr_t)v_6559-TAG_FIXNUM)/(16/CELL)));
    goto v_6379;
v_6380:
    v_6559 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6381;
v_6382:
    goto v_6378;
v_6379:
    goto v_6380;
v_6381:
    v_6559 = (LispObject)greaterp2(v_6560, v_6559);
    v_6559 = v_6559 ? lisp_true : nil;
    env = stack[-7];
    if (v_6559 == nil) goto v_6376;
    v_6559 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_6559;
    goto v_6356;
v_6376:
    goto v_6399;
v_6395:
    v_6560 = stack[0];
    goto v_6396;
v_6397:
    v_6559 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_6398;
v_6399:
    goto v_6395;
v_6396:
    goto v_6397;
v_6398:
    if (v_6560 == v_6559) goto v_6393;
    else goto v_6394;
v_6393:
    goto v_6410;
v_6406:
    v_6560 = stack[-5];
    goto v_6407;
v_6408:
    v_6559 = elt(env, 1); // sin
    goto v_6409;
v_6410:
    goto v_6406;
v_6407:
    goto v_6408;
v_6409:
    if (v_6560 == v_6559) goto v_6404;
    else goto v_6405;
v_6404:
    v_6559 = nil;
    goto v_6351;
v_6405:
    goto v_6356;
v_6394:
    v_6559 = stack[0];
    v_6559 = (LispObject)((intptr_t)(v_6559) + 0x10);
    stack[0] = v_6559;
    goto v_6352;
v_6356:
    v_6559 = (LispObject)48+TAG_FIXNUM; // 3
    v_6559 = Lmkvect(nil, v_6559);
    env = stack[-7];
    stack[-6] = v_6559;
    goto v_6432;
v_6428:
    v_6560 = stack[-2];
    goto v_6429;
v_6430:
    v_6559 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6431;
v_6432:
    goto v_6428;
v_6429:
    goto v_6430;
v_6431:
    if (v_6560 == v_6559) goto v_6426;
    else goto v_6427;
v_6426:
    v_6559 = lisp_true;
    goto v_6425;
v_6427:
    goto v_6442;
v_6438:
    v_6560 = stack[-5];
    goto v_6439;
v_6440:
    v_6559 = elt(env, 2); // cos
    goto v_6441;
v_6442:
    goto v_6438;
v_6439:
    goto v_6440;
v_6441:
    v_6559 = (v_6560 == v_6559 ? lisp_true : nil);
    goto v_6425;
    v_6559 = nil;
v_6425:
    if (v_6559 == nil) goto v_6423;
    goto v_6452;
v_6446:
    v_6561 = stack[-6];
    goto v_6447;
v_6448:
    v_6560 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6449;
v_6450:
    v_6559 = stack[-3];
    goto v_6451;
v_6452:
    goto v_6446;
v_6447:
    goto v_6448;
v_6449:
    goto v_6450;
v_6451:
    *(LispObject *)((char *)v_6561 + (CELL-TAG_VECTOR) + (((intptr_t)v_6560-TAG_FIXNUM)/(16/CELL))) = v_6559;
    goto v_6421;
v_6423:
    goto v_6464;
v_6458:
    stack[-1] = stack[-6];
    goto v_6459;
v_6460:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6461;
v_6462:
    goto v_6472;
v_6468:
    v_6560 = elt(env, 3); // (-1 . 1)
    goto v_6469;
v_6470:
    v_6559 = stack[-3];
    goto v_6471;
v_6472:
    goto v_6468;
v_6469:
    goto v_6470;
v_6471:
    fn = elt(env, 4); // multsq
    v_6559 = (*qfn2(fn))(fn, v_6560, v_6559);
    env = stack[-7];
    goto v_6463;
v_6464:
    goto v_6458;
v_6459:
    goto v_6460;
v_6461:
    goto v_6462;
v_6463:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_6559;
    goto v_6421;
v_6421:
    goto v_6481;
v_6475:
    v_6561 = stack[-6];
    goto v_6476;
v_6477:
    v_6560 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6478;
v_6479:
    v_6559 = stack[-5];
    goto v_6480;
v_6481:
    goto v_6475;
v_6476:
    goto v_6477;
v_6478:
    goto v_6479;
v_6480:
    *(LispObject *)((char *)v_6561 + (CELL-TAG_VECTOR) + (((intptr_t)v_6560-TAG_FIXNUM)/(16/CELL))) = v_6559;
    goto v_6493;
v_6489:
    v_6560 = stack[-2];
    goto v_6490;
v_6491:
    v_6559 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_6492;
v_6493:
    goto v_6489;
v_6490:
    goto v_6491;
v_6492:
    if (v_6560 == v_6559) goto v_6487;
    else goto v_6488;
v_6487:
    v_6559 = (LispObject)112+TAG_FIXNUM; // 7
    v_6559 = Lmkvect(nil, v_6559);
    env = stack[-7];
    stack[-2] = v_6559;
    v_6559 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_6559;
v_6501:
    goto v_6513;
v_6509:
    v_6560 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_6510;
v_6511:
    v_6559 = stack[-3];
    goto v_6512;
v_6513:
    goto v_6509;
v_6510:
    goto v_6511;
v_6512:
    v_6559 = difference2(v_6560, v_6559);
    env = stack[-7];
    v_6559 = Lminusp(nil, v_6559);
    env = stack[-7];
    if (v_6559 == nil) goto v_6506;
    goto v_6500;
v_6506:
    goto v_6523;
v_6517:
    stack[-1] = stack[-2];
    goto v_6518;
v_6519:
    stack[0] = stack[-3];
    goto v_6520;
v_6521:
    goto v_6531;
v_6527:
    v_6560 = stack[-4];
    goto v_6528;
v_6529:
    v_6559 = stack[-3];
    goto v_6530;
v_6531:
    goto v_6527;
v_6528:
    goto v_6529;
v_6530:
    v_6559 = *(LispObject *)((char *)v_6560 + (CELL-TAG_VECTOR) + (((intptr_t)v_6559-TAG_FIXNUM)/(16/CELL)));
    v_6559 = negate(v_6559);
    env = stack[-7];
    goto v_6522;
v_6523:
    goto v_6517;
v_6518:
    goto v_6519;
v_6520:
    goto v_6521;
v_6522:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_6559;
    v_6559 = stack[-3];
    v_6559 = add1(v_6559);
    env = stack[-7];
    stack[-3] = v_6559;
    goto v_6501;
v_6500:
    v_6559 = stack[-2];
    stack[-4] = v_6559;
    goto v_6486;
v_6488:
v_6486:
    goto v_6544;
v_6538:
    v_6561 = stack[-6];
    goto v_6539;
v_6540:
    v_6560 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_6541;
v_6542:
    v_6559 = stack[-4];
    goto v_6543;
v_6544:
    goto v_6538;
v_6539:
    goto v_6540;
v_6541:
    goto v_6542;
v_6543:
    *(LispObject *)((char *)v_6561 + (CELL-TAG_VECTOR) + (((intptr_t)v_6560-TAG_FIXNUM)/(16/CELL))) = v_6559;
    goto v_6554;
v_6548:
    v_6561 = stack[-6];
    goto v_6549;
v_6550:
    v_6560 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_6551;
v_6552:
    v_6559 = nil;
    goto v_6553;
v_6554:
    goto v_6548;
v_6549:
    goto v_6550;
v_6551:
    goto v_6552;
v_6553:
    *(LispObject *)((char *)v_6561 + (CELL-TAG_VECTOR) + (((intptr_t)v_6560-TAG_FIXNUM)/(16/CELL))) = v_6559;
    v_6559 = stack[-6];
v_6351:
    return onevalue(v_6559);
}



// Code for red_divtest

static LispObject CC_red_divtest(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6374, v_6375;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_6344;
    stack[-1] = v_6343;
// end of prologue
v_6348:
    v_6374 = stack[-1];
    if (v_6374 == nil) goto v_6351;
    else goto v_6352;
v_6351:
    v_6374 = nil;
    goto v_6347;
v_6352:
    goto v_6362;
v_6358:
    v_6374 = stack[-1];
    v_6374 = qcar(v_6374);
    fn = elt(env, 1); // bas_dpoly
    v_6374 = (*qfn1(fn))(fn, v_6374);
    env = stack[-2];
    fn = elt(env, 2); // dp_lmon
    v_6375 = (*qfn1(fn))(fn, v_6374);
    env = stack[-2];
    goto v_6359;
v_6360:
    v_6374 = stack[0];
    goto v_6361;
v_6362:
    goto v_6358;
v_6359:
    goto v_6360;
v_6361:
    fn = elt(env, 3); // mo_vdivides!?
    v_6374 = (*qfn2(fn))(fn, v_6375, v_6374);
    env = stack[-2];
    if (v_6374 == nil) goto v_6356;
    v_6374 = stack[-1];
    v_6374 = qcar(v_6374);
    goto v_6347;
v_6356:
    v_6374 = stack[-1];
    v_6374 = qcdr(v_6374);
    stack[-1] = v_6374;
    goto v_6348;
    v_6374 = nil;
v_6347:
    return onevalue(v_6374);
}



// Code for ordn

static LispObject CC_ordn(LispObject env,
                         LispObject v_6343)
{
    env = qenv(env);
    LispObject v_6385, v_6386;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6343);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_6386 = v_6343;
// end of prologue
    v_6385 = v_6386;
    if (v_6385 == nil) goto v_6347;
    else goto v_6348;
v_6347:
    v_6385 = nil;
    goto v_6346;
v_6348:
    v_6385 = v_6386;
    v_6385 = qcdr(v_6385);
    if (v_6385 == nil) goto v_6351;
    else goto v_6352;
v_6351:
    v_6385 = v_6386;
    goto v_6346;
v_6352:
    v_6385 = v_6386;
    v_6385 = qcdr(v_6385);
    v_6385 = qcdr(v_6385);
    if (v_6385 == nil) goto v_6356;
    else goto v_6357;
v_6356:
    goto v_6366;
v_6362:
    v_6385 = v_6386;
    v_6385 = qcar(v_6385);
    goto v_6363;
v_6364:
    v_6386 = qcdr(v_6386);
    v_6386 = qcar(v_6386);
    goto v_6365;
v_6366:
    goto v_6362;
v_6363:
    goto v_6364;
v_6365:
    {
        fn = elt(env, 1); // ord2
        return (*qfn2(fn))(fn, v_6385, v_6386);
    }
v_6357:
    goto v_6379;
v_6375:
    v_6385 = v_6386;
    stack[0] = qcar(v_6385);
    goto v_6376;
v_6377:
    v_6385 = v_6386;
    v_6385 = qcdr(v_6385);
    v_6385 = CC_ordn(elt(env, 0), v_6385);
    env = stack[-1];
    goto v_6378;
v_6379:
    goto v_6375;
v_6376:
    goto v_6377;
v_6378:
    {
        LispObject v_6388 = stack[0];
        fn = elt(env, 2); // ordad
        return (*qfn2(fn))(fn, v_6388, v_6385);
    }
    v_6385 = nil;
v_6346:
    return onevalue(v_6385);
}



// Code for rnminus!:

static LispObject CC_rnminusT(LispObject env,
                         LispObject v_6343)
{
    env = qenv(env);
    LispObject v_6362, v_6363;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6343);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_6343;
// end of prologue
    goto v_6352;
v_6346:
    v_6362 = stack[0];
    stack[-1] = qcar(v_6362);
    goto v_6347;
v_6348:
    v_6362 = stack[0];
    v_6362 = qcdr(v_6362);
    v_6362 = qcar(v_6362);
    fn = elt(env, 1); // !:minus
    v_6363 = (*qfn1(fn))(fn, v_6362);
    goto v_6349;
v_6350:
    v_6362 = stack[0];
    v_6362 = qcdr(v_6362);
    v_6362 = qcdr(v_6362);
    goto v_6351;
v_6352:
    goto v_6346;
v_6347:
    goto v_6348;
v_6349:
    goto v_6350;
v_6351:
    {
        LispObject v_6366 = stack[-1];
        return list2star(v_6366, v_6363, v_6362);
    }
}



// Code for horner!-rule

static LispObject CC_hornerKrule(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6550, v_6551, v_6552, v_6553;
    LispObject fn;
    LispObject v_6346, v_6345, v_6344, v_6343;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "horner-rule");
    va_start(aa, nargs);
    v_6343 = va_arg(aa, LispObject);
    v_6344 = va_arg(aa, LispObject);
    v_6345 = va_arg(aa, LispObject);
    v_6346 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_6346,v_6345,v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_6343,v_6344,v_6345,v_6346);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_6346;
    stack[-2] = v_6345;
    stack[-3] = v_6344;
    stack[-4] = v_6343;
// end of prologue
v_6342:
    v_6550 = stack[-2];
    if (!consp(v_6550)) goto v_6354;
    else goto v_6355;
v_6354:
    v_6550 = lisp_true;
    goto v_6353;
v_6355:
    v_6550 = stack[-2];
    v_6550 = qcar(v_6550);
    v_6550 = (consp(v_6550) ? nil : lisp_true);
    goto v_6353;
    v_6550 = nil;
v_6353:
    if (v_6550 == nil) goto v_6351;
    v_6550 = stack[-1];
    v_6550 = qcar(v_6550);
    v_6550 = qcdr(v_6550);
    v_6550 = (LispObject)zerop(v_6550);
    v_6550 = v_6550 ? lisp_true : nil;
    env = stack[-6];
    if (v_6550 == nil) goto v_6366;
    v_6550 = stack[-2];
    {
        fn = elt(env, 1); // !*d2n
        return (*qfn1(fn))(fn, v_6550);
    }
v_6366:
    goto v_6380;
v_6376:
    v_6550 = stack[-2];
    fn = elt(env, 1); // !*d2n
    stack[0] = (*qfn1(fn))(fn, v_6550);
    env = stack[-6];
    goto v_6377;
v_6378:
    goto v_6388;
v_6384:
    stack[-2] = stack[-4];
    goto v_6385;
v_6386:
    goto v_6395;
v_6391:
    v_6550 = stack[-1];
    v_6550 = qcar(v_6550);
    v_6551 = qcdr(v_6550);
    goto v_6392;
v_6393:
    v_6550 = stack[-3];
    goto v_6394;
v_6395:
    goto v_6391;
v_6392:
    goto v_6393;
v_6394:
    v_6550 = Lexpt(nil, v_6551, v_6550);
    env = stack[-6];
    goto v_6387;
v_6388:
    goto v_6384;
v_6385:
    goto v_6386;
v_6387:
    v_6550 = times2(stack[-2], v_6550);
    goto v_6379;
v_6380:
    goto v_6376;
v_6377:
    goto v_6378;
v_6379:
    {
        LispObject v_6560 = stack[0];
        return plus2(v_6560, v_6550);
    }
    v_6550 = nil;
    goto v_6349;
v_6351:
    goto v_6406;
v_6402:
    v_6550 = stack[-2];
    v_6550 = qcar(v_6550);
    v_6550 = qcar(v_6550);
    v_6551 = qcar(v_6550);
    goto v_6403;
v_6404:
    v_6550 = stack[-1];
    v_6550 = qcar(v_6550);
    v_6550 = qcar(v_6550);
    goto v_6405;
v_6406:
    goto v_6402;
v_6403:
    goto v_6404;
v_6405:
    if (equal(v_6551, v_6550)) goto v_6401;
    v_6550 = stack[-1];
    v_6550 = qcar(v_6550);
    v_6550 = qcdr(v_6550);
    v_6550 = (LispObject)zerop(v_6550);
    v_6550 = v_6550 ? lisp_true : nil;
    env = stack[-6];
    if (v_6550 == nil) goto v_6417;
    goto v_6427;
v_6423:
    v_6551 = stack[-2];
    goto v_6424;
v_6425:
    v_6550 = stack[-1];
    v_6550 = qcdr(v_6550);
    goto v_6426;
v_6427:
    goto v_6423;
v_6424:
    goto v_6425;
v_6426:
    {
        fn = elt(env, 2); // evaluate!-in!-order
        return (*qfn2(fn))(fn, v_6551, v_6550);
    }
v_6417:
    goto v_6438;
v_6434:
    goto v_6444;
v_6440:
    v_6551 = stack[-2];
    goto v_6441;
v_6442:
    v_6550 = stack[-1];
    v_6550 = qcdr(v_6550);
    goto v_6443;
v_6444:
    goto v_6440;
v_6441:
    goto v_6442;
v_6443:
    fn = elt(env, 2); // evaluate!-in!-order
    stack[0] = (*qfn2(fn))(fn, v_6551, v_6550);
    env = stack[-6];
    goto v_6435;
v_6436:
    goto v_6453;
v_6449:
    stack[-2] = stack[-4];
    goto v_6450;
v_6451:
    goto v_6460;
v_6456:
    v_6550 = stack[-1];
    v_6550 = qcar(v_6550);
    v_6551 = qcdr(v_6550);
    goto v_6457;
v_6458:
    v_6550 = stack[-3];
    goto v_6459;
v_6460:
    goto v_6456;
v_6457:
    goto v_6458;
v_6459:
    v_6550 = Lexpt(nil, v_6551, v_6550);
    env = stack[-6];
    goto v_6452;
v_6453:
    goto v_6449;
v_6450:
    goto v_6451;
v_6452:
    v_6550 = times2(stack[-2], v_6550);
    goto v_6437;
v_6438:
    goto v_6434;
v_6435:
    goto v_6436;
v_6437:
    {
        LispObject v_6561 = stack[0];
        return plus2(v_6561, v_6550);
    }
    v_6550 = nil;
    goto v_6349;
v_6401:
    v_6550 = stack[-2];
    v_6550 = qcar(v_6550);
    v_6550 = qcar(v_6550);
    v_6550 = qcdr(v_6550);
    stack[-5] = v_6550;
    goto v_6483;
v_6475:
    v_6550 = stack[-1];
    v_6550 = qcar(v_6550);
    v_6550 = qcdr(v_6550);
    v_6550 = (LispObject)zerop(v_6550);
    v_6550 = v_6550 ? lisp_true : nil;
    env = stack[-6];
    if (v_6550 == nil) goto v_6487;
    goto v_6497;
v_6493:
    v_6550 = stack[-2];
    v_6550 = qcar(v_6550);
    v_6551 = qcdr(v_6550);
    goto v_6494;
v_6495:
    v_6550 = stack[-1];
    v_6550 = qcdr(v_6550);
    goto v_6496;
v_6497:
    goto v_6493;
v_6494:
    goto v_6495;
v_6496:
    fn = elt(env, 2); // evaluate!-in!-order
    v_6550 = (*qfn2(fn))(fn, v_6551, v_6550);
    env = stack[-6];
    v_6553 = v_6550;
    goto v_6485;
v_6487:
    goto v_6510;
v_6506:
    goto v_6516;
v_6512:
    v_6550 = stack[-2];
    v_6550 = qcar(v_6550);
    v_6551 = qcdr(v_6550);
    goto v_6513;
v_6514:
    v_6550 = stack[-1];
    v_6550 = qcdr(v_6550);
    goto v_6515;
v_6516:
    goto v_6512;
v_6513:
    goto v_6514;
v_6515:
    fn = elt(env, 2); // evaluate!-in!-order
    stack[0] = (*qfn2(fn))(fn, v_6551, v_6550);
    env = stack[-6];
    goto v_6507;
v_6508:
    goto v_6527;
v_6523:
    goto v_6524;
v_6525:
    goto v_6534;
v_6530:
    v_6550 = stack[-1];
    v_6550 = qcar(v_6550);
    v_6552 = qcdr(v_6550);
    goto v_6531;
v_6532:
    goto v_6542;
v_6538:
    v_6551 = stack[-3];
    goto v_6539;
v_6540:
    v_6550 = stack[-5];
    goto v_6541;
v_6542:
    goto v_6538;
v_6539:
    goto v_6540;
v_6541:
    v_6550 = (LispObject)(intptr_t)((intptr_t)v_6551 - (intptr_t)v_6550 + TAG_FIXNUM);
    goto v_6533;
v_6534:
    goto v_6530;
v_6531:
    goto v_6532;
v_6533:
    v_6550 = Lexpt(nil, v_6552, v_6550);
    env = stack[-6];
    goto v_6526;
v_6527:
    goto v_6523;
v_6524:
    goto v_6525;
v_6526:
    v_6550 = times2(stack[-4], v_6550);
    env = stack[-6];
    goto v_6509;
v_6510:
    goto v_6506;
v_6507:
    goto v_6508;
v_6509:
    v_6550 = plus2(stack[0], v_6550);
    env = stack[-6];
    v_6553 = v_6550;
    goto v_6485;
    v_6553 = nil;
v_6485:
    goto v_6476;
v_6477:
    v_6552 = stack[-5];
    goto v_6478;
v_6479:
    v_6550 = stack[-2];
    v_6551 = qcdr(v_6550);
    goto v_6480;
v_6481:
    v_6550 = stack[-1];
    goto v_6482;
v_6483:
    goto v_6475;
v_6476:
    goto v_6477;
v_6478:
    goto v_6479;
v_6480:
    goto v_6481;
v_6482:
    stack[-4] = v_6553;
    stack[-3] = v_6552;
    stack[-2] = v_6551;
    stack[-1] = v_6550;
    goto v_6342;
    goto v_6349;
    v_6550 = nil;
v_6349:
    return onevalue(v_6550);
}



// Code for freeofl

static LispObject CC_freeofl(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6379, v_6380;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_6344;
    stack[-1] = v_6343;
// end of prologue
v_6342:
    v_6379 = stack[0];
    if (v_6379 == nil) goto v_6348;
    else goto v_6349;
v_6348:
    v_6379 = lisp_true;
    goto v_6347;
v_6349:
    goto v_6363;
v_6359:
    v_6380 = stack[-1];
    goto v_6360;
v_6361:
    v_6379 = stack[0];
    v_6379 = qcar(v_6379);
    goto v_6362;
v_6363:
    goto v_6359;
v_6360:
    goto v_6361;
v_6362:
    fn = elt(env, 1); // freeof
    v_6379 = (*qfn2(fn))(fn, v_6380, v_6379);
    env = stack[-2];
    if (v_6379 == nil) goto v_6356;
    else goto v_6357;
v_6356:
    v_6379 = nil;
    goto v_6355;
v_6357:
    goto v_6375;
v_6371:
    v_6380 = stack[-1];
    goto v_6372;
v_6373:
    v_6379 = stack[0];
    v_6379 = qcdr(v_6379);
    goto v_6374;
v_6375:
    goto v_6371;
v_6372:
    goto v_6373;
v_6374:
    stack[-1] = v_6380;
    stack[0] = v_6379;
    goto v_6342;
    v_6379 = nil;
v_6355:
    goto v_6347;
    v_6379 = nil;
v_6347:
    return onevalue(v_6379);
}



// Code for split_f

static LispObject CC_split_f(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6541, v_6542, v_6543, v_6544;
    LispObject fn;
    LispObject v_6346, v_6345, v_6344, v_6343;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "split_f");
    va_start(aa, nargs);
    v_6343 = va_arg(aa, LispObject);
    v_6344 = va_arg(aa, LispObject);
    v_6345 = va_arg(aa, LispObject);
    v_6346 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_6346,v_6345,v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_6343,v_6344,v_6345,v_6346);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-3] = v_6346;
    stack[-4] = v_6345;
    stack[-5] = v_6344;
    stack[-6] = v_6343;
// end of prologue
v_6351:
    v_6541 = stack[-6];
    if (v_6541 == nil) goto v_6354;
    else goto v_6355;
v_6354:
    v_6541 = stack[-3];
    goto v_6350;
v_6355:
    v_6541 = stack[-6];
    if (!consp(v_6541)) goto v_6362;
    else goto v_6363;
v_6362:
    v_6541 = lisp_true;
    goto v_6361;
v_6363:
    v_6541 = stack[-6];
    v_6541 = qcar(v_6541);
    v_6541 = (consp(v_6541) ? nil : lisp_true);
    goto v_6361;
    v_6541 = nil;
v_6361:
    if (v_6541 == nil) goto v_6359;
    goto v_6376;
v_6372:
    goto v_6382;
v_6378:
    goto v_6388;
v_6384:
    v_6542 = stack[-4];
    goto v_6385;
v_6386:
    v_6541 = stack[-6];
    goto v_6387;
v_6388:
    goto v_6384;
v_6385:
    goto v_6386;
v_6387:
    fn = elt(env, 3); // multf
    v_6542 = (*qfn2(fn))(fn, v_6542, v_6541);
    env = stack[-8];
    goto v_6379;
v_6380:
    v_6541 = stack[-3];
    v_6541 = qcar(v_6541);
    goto v_6381;
v_6382:
    goto v_6378;
v_6379:
    goto v_6380;
v_6381:
    fn = elt(env, 4); // addf
    v_6542 = (*qfn2(fn))(fn, v_6542, v_6541);
    goto v_6373;
v_6374:
    v_6541 = stack[-3];
    v_6541 = qcdr(v_6541);
    goto v_6375;
v_6376:
    goto v_6372;
v_6373:
    goto v_6374;
v_6375:
    return cons(v_6542, v_6541);
v_6359:
    v_6541 = stack[-6];
    v_6541 = qcar(v_6541);
    v_6541 = qcar(v_6541);
    v_6541 = qcar(v_6541);
    if (!consp(v_6541)) goto v_6400;
    goto v_6409;
v_6405:
    v_6541 = stack[-6];
    v_6541 = qcar(v_6541);
    v_6541 = qcar(v_6541);
    v_6541 = qcar(v_6541);
    v_6542 = qcar(v_6541);
    goto v_6406;
v_6407:
    v_6541 = stack[-5];
    goto v_6408;
v_6409:
    goto v_6405;
v_6406:
    goto v_6407;
v_6408:
    v_6541 = Lmember(nil, v_6542, v_6541);
    goto v_6398;
v_6400:
    v_6541 = nil;
    goto v_6398;
    v_6541 = nil;
v_6398:
    if (v_6541 == nil) goto v_6396;
    goto v_6432;
v_6428:
    v_6541 = stack[-6];
    v_6541 = qcar(v_6541);
    v_6541 = qcar(v_6541);
    v_6542 = qcdr(v_6541);
    goto v_6429;
v_6430:
    v_6541 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6431;
v_6432:
    goto v_6428;
v_6429:
    goto v_6430;
v_6431:
    if (v_6542 == v_6541) goto v_6427;
    v_6541 = lisp_true;
    goto v_6425;
v_6427:
    goto v_6446;
v_6442:
    v_6541 = stack[-6];
    v_6541 = qcar(v_6541);
    v_6542 = qcdr(v_6541);
    goto v_6443;
v_6444:
    v_6541 = stack[-5];
    goto v_6445;
v_6446:
    goto v_6442;
v_6443:
    goto v_6444;
v_6445:
    fn = elt(env, 5); // get_first_kernel
    v_6541 = (*qfn2(fn))(fn, v_6542, v_6541);
    env = stack[-8];
    goto v_6425;
    v_6541 = nil;
v_6425:
    if (v_6541 == nil) goto v_6423;
    goto v_6462;
v_6452:
    stack[0] = elt(env, 1); // "SPLIT_F: expression not linear w.r.t."
    goto v_6453;
v_6454:
    goto v_6469;
v_6465:
    v_6542 = elt(env, 2); // list
    goto v_6466;
v_6467:
    v_6541 = stack[-5];
    goto v_6468;
v_6469:
    goto v_6465;
v_6466:
    goto v_6467;
v_6468:
    v_6544 = cons(v_6542, v_6541);
    env = stack[-8];
    goto v_6455;
v_6456:
    v_6543 = nil;
    goto v_6457;
v_6458:
    v_6542 = nil;
    goto v_6459;
v_6460:
    v_6541 = lisp_true;
    goto v_6461;
v_6462:
    goto v_6452;
v_6453:
    goto v_6454;
v_6455:
    goto v_6456;
v_6457:
    goto v_6458;
v_6459:
    goto v_6460;
v_6461:
    {
        LispObject v_6553 = stack[0];
        fn = elt(env, 6); // msgpri
        return (*qfnn(fn))(fn, 5, v_6553, v_6544, v_6543, v_6542, v_6541);
    }
v_6423:
    v_6541 = stack[-6];
    v_6541 = qcdr(v_6541);
    stack[-7] = v_6541;
    goto v_6486;
v_6480:
    stack[-1] = stack[-3];
    goto v_6481;
v_6482:
    v_6541 = stack[-6];
    v_6541 = qcar(v_6541);
    v_6541 = qcar(v_6541);
    stack[0] = qcar(v_6541);
    goto v_6483;
v_6484:
    goto v_6497;
v_6493:
    v_6542 = stack[-4];
    goto v_6494;
v_6495:
    v_6541 = stack[-6];
    v_6541 = qcar(v_6541);
    v_6541 = qcdr(v_6541);
    goto v_6496;
v_6497:
    goto v_6493;
v_6494:
    goto v_6495;
v_6496:
    fn = elt(env, 3); // multf
    v_6541 = (*qfn2(fn))(fn, v_6542, v_6541);
    env = stack[-8];
    goto v_6485;
v_6486:
    goto v_6480;
v_6481:
    goto v_6482;
v_6483:
    goto v_6484;
v_6485:
    fn = elt(env, 7); // update_kc_list
    v_6541 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_6541);
    env = stack[-8];
    stack[-3] = v_6541;
    v_6541 = stack[-7];
    stack[-6] = v_6541;
    goto v_6351;
    goto v_6353;
v_6396:
    v_6541 = stack[-6];
    v_6541 = qcdr(v_6541);
    stack[-7] = v_6541;
    goto v_6516;
v_6508:
    v_6541 = stack[-6];
    v_6541 = qcar(v_6541);
    stack[-2] = qcdr(v_6541);
    goto v_6509;
v_6510:
    stack[-1] = stack[-5];
    goto v_6511;
v_6512:
    goto v_6526;
v_6522:
    stack[0] = stack[-4];
    goto v_6523;
v_6524:
    goto v_6534;
v_6530:
    v_6541 = stack[-6];
    v_6541 = qcar(v_6541);
    v_6542 = qcar(v_6541);
    goto v_6531;
v_6532:
    v_6541 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6533;
v_6534:
    goto v_6530;
v_6531:
    goto v_6532;
v_6533:
    v_6541 = cons(v_6542, v_6541);
    env = stack[-8];
    v_6541 = ncons(v_6541);
    env = stack[-8];
    goto v_6525;
v_6526:
    goto v_6522;
v_6523:
    goto v_6524;
v_6525:
    fn = elt(env, 3); // multf
    v_6542 = (*qfn2(fn))(fn, stack[0], v_6541);
    env = stack[-8];
    goto v_6513;
v_6514:
    v_6541 = stack[-3];
    goto v_6515;
v_6516:
    goto v_6508;
v_6509:
    goto v_6510;
v_6511:
    goto v_6512;
v_6513:
    goto v_6514;
v_6515:
    v_6541 = CC_split_f(elt(env, 0), 4, stack[-2], stack[-1], v_6542, v_6541);
    env = stack[-8];
    stack[-3] = v_6541;
    v_6541 = stack[-7];
    stack[-6] = v_6541;
    goto v_6351;
v_6353:
    v_6541 = nil;
v_6350:
    return onevalue(v_6541);
}



// Code for ofsf_smwcpknowl

static LispObject CC_ofsf_smwcpknowl(LispObject env,
                         LispObject v_6343)
{
    env = qenv(env);
    LispObject v_6356, v_6357;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_6357 = v_6343;
// end of prologue
    v_6356 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_6356 == nil) goto v_6348;
    v_6356 = v_6357;
    {
        fn = elt(env, 2); // cl_susicpknowl
        return (*qfn1(fn))(fn, v_6356);
    }
v_6348:
    v_6356 = v_6357;
    {
        fn = elt(env, 3); // ofsf_smcpknowl
        return (*qfn1(fn))(fn, v_6356);
    }
    v_6356 = nil;
    return onevalue(v_6356);
}



// Code for get_rep_matrix_in

static LispObject CC_get_rep_matrix_in(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6411, v_6412;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_6412 = v_6344;
    stack[-2] = v_6343;
// end of prologue
    stack[-1] = nil;
    v_6411 = nil;
    stack[-3] = v_6411;
    v_6411 = v_6412;
    v_6411 = qcdr(v_6411);
    stack[0] = v_6411;
v_6356:
    v_6411 = stack[-3];
    if (v_6411 == nil) goto v_6363;
    else goto v_6364;
v_6363:
    goto v_6371;
v_6367:
    v_6411 = stack[0];
    v_6412 = Llength(nil, v_6411);
    env = stack[-4];
    goto v_6368;
v_6369:
    v_6411 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6370;
v_6371:
    goto v_6367;
v_6368:
    goto v_6369;
v_6370:
    v_6411 = (LispObject)greaterp2(v_6412, v_6411);
    v_6411 = v_6411 ? lisp_true : nil;
    env = stack[-4];
    goto v_6362;
v_6364:
    v_6411 = nil;
    goto v_6362;
    v_6411 = nil;
v_6362:
    if (v_6411 == nil) goto v_6359;
    else goto v_6360;
v_6359:
    goto v_6355;
v_6360:
    goto v_6387;
v_6383:
    v_6411 = stack[0];
    v_6411 = qcar(v_6411);
    v_6412 = qcar(v_6411);
    goto v_6384;
v_6385:
    v_6411 = stack[-2];
    goto v_6386;
v_6387:
    goto v_6383;
v_6384:
    goto v_6385;
v_6386:
    if (equal(v_6412, v_6411)) goto v_6381;
    else goto v_6382;
v_6381:
    v_6411 = stack[0];
    v_6411 = qcar(v_6411);
    v_6411 = qcdr(v_6411);
    v_6411 = qcar(v_6411);
    stack[-1] = v_6411;
    v_6411 = lisp_true;
    stack[-3] = v_6411;
    goto v_6380;
v_6382:
v_6380:
    v_6411 = stack[0];
    v_6411 = qcdr(v_6411);
    stack[0] = v_6411;
    goto v_6356;
v_6355:
    v_6411 = stack[-3];
    if (v_6411 == nil) goto v_6404;
    v_6411 = stack[-1];
    goto v_6350;
v_6404:
    v_6411 = elt(env, 1); // "error in get representation matrix"
    fn = elt(env, 2); // rederr
    v_6411 = (*qfn1(fn))(fn, v_6411);
    goto v_6402;
v_6402:
    v_6411 = nil;
v_6350:
    return onevalue(v_6411);
}



// Code for cl_fvarl

static LispObject CC_cl_fvarl(LispObject env,
                         LispObject v_6343)
{
    env = qenv(env);
    LispObject v_6354, v_6355;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6343);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_6354 = v_6343;
// end of prologue
    goto v_6350;
v_6346:
    fn = elt(env, 2); // cl_fvarl1
    v_6355 = (*qfn1(fn))(fn, v_6354);
    env = stack[0];
    goto v_6347;
v_6348:
    v_6354 = elt(env, 1); // ordp
    goto v_6349;
v_6350:
    goto v_6346;
v_6347:
    goto v_6348;
v_6349:
    {
        fn = elt(env, 3); // sort
        return (*qfn2(fn))(fn, v_6355, v_6354);
    }
}



// Code for cl_varl2

static LispObject CC_cl_varl2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6721, v_6722, v_6723, v_6724;
    LispObject fn;
    LispObject v_6346, v_6345, v_6344, v_6343;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_varl2");
    va_start(aa, nargs);
    v_6343 = va_arg(aa, LispObject);
    v_6344 = va_arg(aa, LispObject);
    v_6345 = va_arg(aa, LispObject);
    v_6346 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_6346,v_6345,v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_6343,v_6344,v_6345,v_6346);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_6346;
    stack[-1] = v_6345;
    stack[-2] = v_6344;
    stack[-3] = v_6343;
// end of prologue
v_6342:
    v_6721 = stack[-3];
    if (!consp(v_6721)) goto v_6353;
    else goto v_6354;
v_6353:
    v_6721 = stack[-3];
    goto v_6352;
v_6354:
    v_6721 = stack[-3];
    v_6721 = qcar(v_6721);
    goto v_6352;
    v_6721 = nil;
v_6352:
    v_6723 = v_6721;
    goto v_6373;
v_6369:
    v_6722 = v_6723;
    goto v_6370;
v_6371:
    v_6721 = elt(env, 1); // true
    goto v_6372;
v_6373:
    goto v_6369;
v_6370:
    goto v_6371;
v_6372:
    if (v_6722 == v_6721) goto v_6367;
    else goto v_6368;
v_6367:
    v_6721 = lisp_true;
    goto v_6366;
v_6368:
    goto v_6383;
v_6379:
    v_6722 = v_6723;
    goto v_6380;
v_6381:
    v_6721 = elt(env, 2); // false
    goto v_6382;
v_6383:
    goto v_6379;
v_6380:
    goto v_6381;
v_6382:
    v_6721 = (v_6722 == v_6721 ? lisp_true : nil);
    goto v_6366;
    v_6721 = nil;
v_6366:
    if (v_6721 == nil) goto v_6364;
    goto v_6392;
v_6388:
    v_6722 = stack[-2];
    goto v_6389;
v_6390:
    v_6721 = stack[0];
    goto v_6391;
v_6392:
    goto v_6388;
v_6389:
    goto v_6390;
v_6391:
    return cons(v_6722, v_6721);
v_6364:
    goto v_6415;
v_6411:
    v_6722 = v_6723;
    goto v_6412;
v_6413:
    v_6721 = elt(env, 3); // or
    goto v_6414;
v_6415:
    goto v_6411;
v_6412:
    goto v_6413;
v_6414:
    if (v_6722 == v_6721) goto v_6409;
    else goto v_6410;
v_6409:
    v_6721 = lisp_true;
    goto v_6408;
v_6410:
    goto v_6425;
v_6421:
    v_6722 = v_6723;
    goto v_6422;
v_6423:
    v_6721 = elt(env, 4); // and
    goto v_6424;
v_6425:
    goto v_6421;
v_6422:
    goto v_6423;
v_6424:
    v_6721 = (v_6722 == v_6721 ? lisp_true : nil);
    goto v_6408;
    v_6721 = nil;
v_6408:
    if (v_6721 == nil) goto v_6406;
    v_6721 = lisp_true;
    goto v_6404;
v_6406:
    goto v_6436;
v_6432:
    v_6722 = v_6723;
    goto v_6433;
v_6434:
    v_6721 = elt(env, 5); // not
    goto v_6435;
v_6436:
    goto v_6432;
v_6433:
    goto v_6434;
v_6435:
    v_6721 = (v_6722 == v_6721 ? lisp_true : nil);
    goto v_6404;
    v_6721 = nil;
v_6404:
    if (v_6721 == nil) goto v_6402;
    v_6721 = lisp_true;
    goto v_6400;
v_6402:
    goto v_6451;
v_6447:
    v_6722 = v_6723;
    goto v_6448;
v_6449:
    v_6721 = elt(env, 6); // impl
    goto v_6450;
v_6451:
    goto v_6447;
v_6448:
    goto v_6449;
v_6450:
    if (v_6722 == v_6721) goto v_6445;
    else goto v_6446;
v_6445:
    v_6721 = lisp_true;
    goto v_6444;
v_6446:
    goto v_6465;
v_6461:
    v_6722 = v_6723;
    goto v_6462;
v_6463:
    v_6721 = elt(env, 7); // repl
    goto v_6464;
v_6465:
    goto v_6461;
v_6462:
    goto v_6463;
v_6464:
    if (v_6722 == v_6721) goto v_6459;
    else goto v_6460;
v_6459:
    v_6721 = lisp_true;
    goto v_6458;
v_6460:
    goto v_6475;
v_6471:
    v_6722 = v_6723;
    goto v_6472;
v_6473:
    v_6721 = elt(env, 8); // equiv
    goto v_6474;
v_6475:
    goto v_6471;
v_6472:
    goto v_6473;
v_6474:
    v_6721 = (v_6722 == v_6721 ? lisp_true : nil);
    goto v_6458;
    v_6721 = nil;
v_6458:
    goto v_6444;
    v_6721 = nil;
v_6444:
    goto v_6400;
    v_6721 = nil;
v_6400:
    if (v_6721 == nil) goto v_6398;
    v_6721 = stack[-3];
    v_6721 = qcdr(v_6721);
    stack[-3] = v_6721;
v_6482:
    v_6721 = stack[-3];
    if (v_6721 == nil) goto v_6487;
    else goto v_6488;
v_6487:
    goto v_6481;
v_6488:
    v_6721 = stack[-3];
    v_6721 = qcar(v_6721);
    goto v_6506;
v_6498:
    v_6724 = v_6721;
    goto v_6499;
v_6500:
    v_6723 = stack[-2];
    goto v_6501;
v_6502:
    v_6722 = stack[-1];
    goto v_6503;
v_6504:
    v_6721 = stack[0];
    goto v_6505;
v_6506:
    goto v_6498;
v_6499:
    goto v_6500;
v_6501:
    goto v_6502;
v_6503:
    goto v_6504;
v_6505:
    v_6721 = CC_cl_varl2(elt(env, 0), 4, v_6724, v_6723, v_6722, v_6721);
    env = stack[-5];
    v_6722 = v_6721;
    v_6721 = v_6722;
    v_6721 = qcar(v_6721);
    stack[-2] = v_6721;
    v_6721 = v_6722;
    v_6721 = qcdr(v_6721);
    stack[0] = v_6721;
    v_6721 = stack[-3];
    v_6721 = qcdr(v_6721);
    stack[-3] = v_6721;
    goto v_6482;
v_6481:
    goto v_6523;
v_6519:
    v_6722 = stack[-2];
    goto v_6520;
v_6521:
    v_6721 = stack[0];
    goto v_6522;
v_6523:
    goto v_6519;
v_6520:
    goto v_6521;
v_6522:
    return cons(v_6722, v_6721);
v_6398:
    goto v_6538;
v_6534:
    v_6722 = v_6723;
    goto v_6535;
v_6536:
    v_6721 = elt(env, 9); // ex
    goto v_6537;
v_6538:
    goto v_6534;
v_6535:
    goto v_6536;
v_6537:
    if (v_6722 == v_6721) goto v_6532;
    else goto v_6533;
v_6532:
    v_6721 = lisp_true;
    goto v_6531;
v_6533:
    goto v_6548;
v_6544:
    v_6722 = v_6723;
    goto v_6545;
v_6546:
    v_6721 = elt(env, 10); // all
    goto v_6547;
v_6548:
    goto v_6544;
v_6545:
    goto v_6546;
v_6547:
    v_6721 = (v_6722 == v_6721 ? lisp_true : nil);
    goto v_6531;
    v_6721 = nil;
v_6531:
    if (v_6721 == nil) goto v_6529;
    goto v_6561;
v_6553:
    v_6721 = stack[-3];
    v_6721 = qcdr(v_6721);
    v_6721 = qcdr(v_6721);
    stack[-4] = qcar(v_6721);
    goto v_6554;
v_6555:
    goto v_6556;
v_6557:
    goto v_6572;
v_6568:
    v_6721 = stack[-3];
    v_6721 = qcdr(v_6721);
    v_6722 = qcar(v_6721);
    goto v_6569;
v_6570:
    v_6721 = stack[-1];
    goto v_6571;
v_6572:
    goto v_6568;
v_6569:
    goto v_6570;
v_6571:
    fn = elt(env, 13); // lto_insertq
    v_6722 = (*qfn2(fn))(fn, v_6722, v_6721);
    env = stack[-5];
    goto v_6558;
v_6559:
    v_6721 = stack[0];
    goto v_6560;
v_6561:
    goto v_6553;
v_6554:
    goto v_6555;
v_6556:
    goto v_6557;
v_6558:
    goto v_6559;
v_6560:
    stack[-3] = stack[-4];
    stack[-1] = v_6722;
    stack[0] = v_6721;
    goto v_6342;
v_6529:
    goto v_6590;
v_6586:
    v_6722 = v_6723;
    goto v_6587;
v_6588:
    v_6721 = elt(env, 11); // bex
    goto v_6589;
v_6590:
    goto v_6586;
v_6587:
    goto v_6588;
v_6589:
    if (v_6722 == v_6721) goto v_6584;
    else goto v_6585;
v_6584:
    v_6721 = lisp_true;
    goto v_6583;
v_6585:
    goto v_6600;
v_6596:
    v_6722 = v_6723;
    goto v_6597;
v_6598:
    v_6721 = elt(env, 12); // ball
    goto v_6599;
v_6600:
    goto v_6596;
v_6597:
    goto v_6598;
v_6599:
    v_6721 = (v_6722 == v_6721 ? lisp_true : nil);
    goto v_6583;
    v_6721 = nil;
v_6583:
    if (v_6721 == nil) goto v_6581;
    goto v_6609;
v_6605:
    v_6721 = stack[-3];
    v_6721 = qcdr(v_6721);
    v_6722 = qcar(v_6721);
    goto v_6606;
v_6607:
    v_6721 = stack[-1];
    goto v_6608;
v_6609:
    goto v_6605;
v_6606:
    goto v_6607;
v_6608:
    fn = elt(env, 13); // lto_insertq
    v_6721 = (*qfn2(fn))(fn, v_6722, v_6721);
    env = stack[-5];
    stack[-1] = v_6721;
    goto v_6626;
v_6618:
    v_6721 = stack[-3];
    v_6721 = qcdr(v_6721);
    v_6721 = qcdr(v_6721);
    v_6721 = qcdr(v_6721);
    v_6724 = qcar(v_6721);
    goto v_6619;
v_6620:
    v_6723 = stack[-2];
    goto v_6621;
v_6622:
    v_6722 = stack[-1];
    goto v_6623;
v_6624:
    v_6721 = stack[0];
    goto v_6625;
v_6626:
    goto v_6618;
v_6619:
    goto v_6620;
v_6621:
    goto v_6622;
v_6623:
    goto v_6624;
v_6625:
    v_6721 = CC_cl_varl2(elt(env, 0), 4, v_6724, v_6723, v_6722, v_6721);
    env = stack[-5];
    v_6722 = v_6721;
    v_6721 = v_6722;
    v_6721 = qcar(v_6721);
    stack[-2] = v_6721;
    v_6721 = v_6722;
    v_6721 = qcdr(v_6721);
    stack[0] = v_6721;
    goto v_6649;
v_6641:
    v_6721 = stack[-3];
    v_6721 = qcdr(v_6721);
    v_6721 = qcdr(v_6721);
    stack[-4] = qcar(v_6721);
    goto v_6642;
v_6643:
    goto v_6644;
v_6645:
    goto v_6660;
v_6656:
    v_6721 = stack[-3];
    v_6721 = qcdr(v_6721);
    v_6722 = qcar(v_6721);
    goto v_6657;
v_6658:
    v_6721 = stack[-1];
    goto v_6659;
v_6660:
    goto v_6656;
v_6657:
    goto v_6658;
v_6659:
    fn = elt(env, 13); // lto_insertq
    v_6722 = (*qfn2(fn))(fn, v_6722, v_6721);
    env = stack[-5];
    goto v_6646;
v_6647:
    v_6721 = stack[0];
    goto v_6648;
v_6649:
    goto v_6641;
v_6642:
    goto v_6643;
v_6644:
    goto v_6645;
v_6646:
    goto v_6647;
v_6648:
    stack[-3] = stack[-4];
    stack[-1] = v_6722;
    stack[0] = v_6721;
    goto v_6342;
v_6581:
    v_6721 = stack[-3];
    fn = elt(env, 14); // rl_varlat
    v_6721 = (*qfn1(fn))(fn, v_6721);
    env = stack[-5];
    stack[-3] = v_6721;
v_6669:
    v_6721 = stack[-3];
    if (v_6721 == nil) goto v_6674;
    else goto v_6675;
v_6674:
    goto v_6668;
v_6675:
    v_6721 = stack[-3];
    v_6721 = qcar(v_6721);
    v_6723 = v_6721;
    goto v_6689;
v_6685:
    v_6722 = v_6723;
    goto v_6686;
v_6687:
    v_6721 = stack[-1];
    goto v_6688;
v_6689:
    goto v_6685;
v_6686:
    goto v_6687;
v_6688:
    v_6721 = Lmemq(nil, v_6722, v_6721);
    if (v_6721 == nil) goto v_6684;
    goto v_6698;
v_6694:
    v_6722 = v_6723;
    goto v_6695;
v_6696:
    v_6721 = stack[0];
    goto v_6697;
v_6698:
    goto v_6694;
v_6695:
    goto v_6696;
v_6697:
    fn = elt(env, 13); // lto_insertq
    v_6721 = (*qfn2(fn))(fn, v_6722, v_6721);
    env = stack[-5];
    stack[0] = v_6721;
    goto v_6682;
v_6684:
    goto v_6708;
v_6704:
    v_6722 = v_6723;
    goto v_6705;
v_6706:
    v_6721 = stack[-2];
    goto v_6707;
v_6708:
    goto v_6704;
v_6705:
    goto v_6706;
v_6707:
    fn = elt(env, 13); // lto_insertq
    v_6721 = (*qfn2(fn))(fn, v_6722, v_6721);
    env = stack[-5];
    stack[-2] = v_6721;
    goto v_6682;
v_6682:
    v_6721 = stack[-3];
    v_6721 = qcdr(v_6721);
    stack[-3] = v_6721;
    goto v_6669;
v_6668:
    goto v_6718;
v_6714:
    v_6722 = stack[-2];
    goto v_6715;
v_6716:
    v_6721 = stack[0];
    goto v_6717;
v_6718:
    goto v_6714;
v_6715:
    goto v_6716;
v_6717:
    return cons(v_6722, v_6721);
    return onevalue(v_6721);
}



// Code for omvir

static LispObject CC_omvir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6396, v_6397;
    LispObject fn;
    argcheck(nargs, 0, "omvir");
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
    goto v_6352;
v_6348:
    v_6397 = qvalue(elt(env, 1)); // atts
    goto v_6349;
v_6350:
    v_6396 = elt(env, 2); // name
    goto v_6351;
v_6352:
    goto v_6348;
v_6349:
    goto v_6350;
v_6351:
    fn = elt(env, 6); // find
    v_6396 = (*qfn2(fn))(fn, v_6397, v_6396);
    env = stack[-1];
    stack[0] = v_6396;
    goto v_6364;
v_6360:
    v_6397 = qvalue(elt(env, 1)); // atts
    goto v_6361;
v_6362:
    v_6396 = elt(env, 3); // hex
    goto v_6363;
v_6364:
    goto v_6360;
v_6361:
    goto v_6362;
v_6363:
    fn = elt(env, 6); // find
    v_6396 = (*qfn2(fn))(fn, v_6397, v_6396);
    env = stack[-1];
    if (v_6396 == nil) goto v_6358;
    goto v_6372;
v_6368:
    v_6397 = elt(env, 4); // "wrong att"
    goto v_6369;
v_6370:
    v_6396 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_6371;
v_6372:
    goto v_6368;
v_6369:
    goto v_6370;
v_6371:
    fn = elt(env, 7); // errorml
    v_6396 = (*qfn2(fn))(fn, v_6397, v_6396);
    env = stack[-1];
    goto v_6356;
v_6358:
v_6356:
    goto v_6384;
v_6380:
    v_6397 = qvalue(elt(env, 1)); // atts
    goto v_6381;
v_6382:
    v_6396 = elt(env, 5); // dec
    goto v_6383;
v_6384:
    goto v_6380;
v_6381:
    goto v_6382;
v_6383:
    fn = elt(env, 6); // find
    v_6396 = (*qfn2(fn))(fn, v_6397, v_6396);
    env = stack[-1];
    if (v_6396 == nil) goto v_6378;
    goto v_6392;
v_6388:
    v_6397 = elt(env, 4); // "wrong att"
    goto v_6389;
v_6390:
    v_6396 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_6391;
v_6392:
    goto v_6388;
v_6389:
    goto v_6390;
v_6391:
    fn = elt(env, 7); // errorml
    v_6396 = (*qfn2(fn))(fn, v_6397, v_6396);
    goto v_6376;
v_6378:
v_6376:
    v_6396 = stack[0];
    return onevalue(v_6396);
}



// Code for simpexpon1

static LispObject CC_simpexpon1(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6399, v_6400;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_6344;
    stack[-2] = v_6343;
// end of prologue
    v_6399 = qvalue(elt(env, 1)); // !*numval
    if (v_6399 == nil) goto v_6349;
    goto v_6361;
v_6357:
    v_6400 = qvalue(elt(env, 2)); // dmode!*
    goto v_6358;
v_6359:
    v_6399 = elt(env, 3); // !:rd!:
    goto v_6360;
v_6361:
    goto v_6357;
v_6358:
    goto v_6359;
v_6360:
    if (v_6400 == v_6399) goto v_6355;
    else goto v_6356;
v_6355:
    v_6399 = lisp_true;
    goto v_6354;
v_6356:
    goto v_6371;
v_6367:
    v_6400 = qvalue(elt(env, 2)); // dmode!*
    goto v_6368;
v_6369:
    v_6399 = elt(env, 4); // !:cr!:
    goto v_6370;
v_6371:
    goto v_6367;
v_6368:
    goto v_6369;
v_6370:
    v_6399 = (v_6400 == v_6399 ? lisp_true : nil);
    goto v_6354;
    v_6399 = nil;
v_6354:
    if (v_6399 == nil) goto v_6349;
    goto v_6380;
v_6376:
    v_6400 = stack[-1];
    goto v_6377;
v_6378:
    v_6399 = stack[-2];
    goto v_6379;
v_6380:
    goto v_6376;
v_6377:
    goto v_6378;
v_6379:
        return Lapply1(nil, v_6400, v_6399);
v_6349:
// Binding dmode!*
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 2, -3);
    qvalue(elt(env, 2)) = nil; // dmode!*
// Binding alglist!*
// FLUIDBIND: reloadenv=4 litvec-offset=5 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 5, 0);
    qvalue(elt(env, 5)) = nil; // alglist!*
    v_6399 = nil;
    v_6399 = ncons(v_6399);
    env = stack[-4];
    qvalue(elt(env, 5)) = v_6399; // alglist!*
    goto v_6396;
v_6392:
    v_6400 = stack[-1];
    goto v_6393;
v_6394:
    v_6399 = stack[-2];
    goto v_6395;
v_6396:
    goto v_6392;
v_6393:
    goto v_6394;
v_6395:
    v_6399 = Lapply1(nil, v_6400, v_6399);
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_6347;
    v_6399 = nil;
v_6347:
    return onevalue(v_6399);
}



// Code for sc_setmat

static LispObject CC_sc_setmat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6367, v_6368;
    LispObject v_6346, v_6345, v_6344, v_6343;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "sc_setmat");
    va_start(aa, nargs);
    v_6343 = va_arg(aa, LispObject);
    v_6344 = va_arg(aa, LispObject);
    v_6345 = va_arg(aa, LispObject);
    v_6346 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_6346,v_6345,v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_6343,v_6344,v_6345,v_6346);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_6346;
    stack[-1] = v_6345;
    v_6367 = v_6344;
    v_6368 = v_6343;
// end of prologue
    goto v_6354;
v_6348:
    goto v_6359;
v_6355:
    stack[-2] = v_6368;
    goto v_6356;
v_6357:
    v_6367 = sub1(v_6367);
    env = stack[-3];
    goto v_6358;
v_6359:
    goto v_6355;
v_6356:
    goto v_6357;
v_6358:
    stack[-2] = *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + (((intptr_t)v_6367-TAG_FIXNUM)/(16/CELL)));
    goto v_6349;
v_6350:
    v_6367 = stack[-1];
    v_6368 = sub1(v_6367);
    goto v_6351;
v_6352:
    v_6367 = stack[0];
    goto v_6353;
v_6354:
    goto v_6348;
v_6349:
    goto v_6350;
v_6351:
    goto v_6352;
v_6353:
    *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + (((intptr_t)v_6368-TAG_FIXNUM)/(16/CELL))) = v_6367;
    return onevalue(v_6367);
}



// Code for vdpzero

static LispObject CC_vdpzero(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6346;
    LispObject fn;
    argcheck(nargs, 0, "vdpzero");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_6346 = (LispObject)0+TAG_FIXNUM; // 0
    {
        fn = elt(env, 1); // a2vdp
        return (*qfn1(fn))(fn, v_6346);
    }
}



// Code for revalind

static LispObject CC_revalind(LispObject env,
                         LispObject v_6343)
{
    env = qenv(env);
    LispObject v_6371, v_6372, v_6373;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6343);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_6343;
// end of prologue
// Binding alglist!*
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 1, -1);
    qvalue(elt(env, 1)) = nil; // alglist!*
// Binding dmode!*
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 2, 0);
    qvalue(elt(env, 2)) = nil; // dmode!*
    v_6371 = nil;
    v_6371 = ncons(v_6371);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_6371; // alglist!*
    v_6371 = qvalue(elt(env, 3)); // subfg!*
    stack[-3] = v_6371;
    v_6371 = nil;
    qvalue(elt(env, 3)) = v_6371; // subfg!*
    goto v_6362;
v_6356:
    v_6373 = elt(env, 4); // !0
    goto v_6357;
v_6358:
    v_6372 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6359;
v_6360:
    v_6371 = stack[-2];
    goto v_6361;
v_6362:
    goto v_6356;
v_6357:
    goto v_6358;
v_6359:
    goto v_6360;
v_6361:
    v_6371 = Lsubst(nil, 3, v_6373, v_6372, v_6371);
    env = stack[-4];
    stack[-2] = v_6371;
    v_6371 = stack[-2];
    fn = elt(env, 5); // simp
    v_6371 = (*qfn1(fn))(fn, v_6371);
    env = stack[-4];
    fn = elt(env, 6); // prepsq
    v_6371 = (*qfn1(fn))(fn, v_6371);
    env = stack[-4];
    v_6372 = v_6371;
    v_6371 = stack[-3];
    qvalue(elt(env, 3)) = v_6371; // subfg!*
    v_6371 = v_6372;
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_6371);
}



// Code for flatindxl

static LispObject CC_flatindxl(LispObject env,
                         LispObject v_6343)
{
    env = qenv(env);
    LispObject v_6405, v_6406;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6343);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_6405 = v_6343;
// end of prologue
    stack[-3] = v_6405;
    v_6405 = stack[-3];
    if (v_6405 == nil) goto v_6354;
    else goto v_6355;
v_6354:
    v_6405 = nil;
    goto v_6349;
v_6355:
    v_6405 = stack[-3];
    v_6405 = qcar(v_6405);
    v_6406 = v_6405;
    v_6405 = v_6406;
    if (!consp(v_6405)) goto v_6364;
    else goto v_6365;
v_6364:
    v_6405 = v_6406;
    goto v_6363;
v_6365:
    v_6405 = v_6406;
    v_6405 = qcdr(v_6405);
    v_6405 = qcar(v_6405);
    goto v_6363;
    v_6405 = nil;
v_6363:
    v_6405 = ncons(v_6405);
    env = stack[-4];
    stack[-1] = v_6405;
    stack[-2] = v_6405;
v_6350:
    v_6405 = stack[-3];
    v_6405 = qcdr(v_6405);
    stack[-3] = v_6405;
    v_6405 = stack[-3];
    if (v_6405 == nil) goto v_6377;
    else goto v_6378;
v_6377:
    v_6405 = stack[-2];
    goto v_6349;
v_6378:
    goto v_6386;
v_6382:
    stack[0] = stack[-1];
    goto v_6383;
v_6384:
    v_6405 = stack[-3];
    v_6405 = qcar(v_6405);
    v_6406 = v_6405;
    v_6405 = v_6406;
    if (!consp(v_6405)) goto v_6394;
    else goto v_6395;
v_6394:
    v_6405 = v_6406;
    goto v_6393;
v_6395:
    v_6405 = v_6406;
    v_6405 = qcdr(v_6405);
    v_6405 = qcar(v_6405);
    goto v_6393;
    v_6405 = nil;
v_6393:
    v_6405 = ncons(v_6405);
    env = stack[-4];
    goto v_6385;
v_6386:
    goto v_6382;
v_6383:
    goto v_6384;
v_6385:
    v_6405 = Lrplacd(nil, stack[0], v_6405);
    env = stack[-4];
    v_6405 = stack[-1];
    v_6405 = qcdr(v_6405);
    stack[-1] = v_6405;
    goto v_6350;
v_6349:
    return onevalue(v_6405);
}



// Code for convchk

static LispObject CC_convchk(LispObject env,
                         LispObject v_6343)
{
    env = qenv(env);
    LispObject v_6402, v_6403, v_6404;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6343);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_6402 = v_6343;
// end of prologue
    v_6403 = qvalue(elt(env, 1)); // !*!*roundbf
    if (v_6403 == nil) goto v_6348;
    v_6403 = v_6402;
    if (!consp(v_6403)) goto v_6352;
    else goto v_6353;
v_6352:
    v_6403 = v_6402;
    v_6403 = Lfloatp(nil, v_6403);
    env = stack[0];
    if (v_6403 == nil) goto v_6358;
    {
        fn = elt(env, 3); // fl2bf
        return (*qfn1(fn))(fn, v_6402);
    }
v_6358:
    v_6403 = v_6402;
    if (!consp(v_6403)) goto v_6369;
    goto v_6367;
v_6369:
    v_6403 = v_6402;
    v_6403 = integerp(v_6403);
    if (v_6403 == nil) goto v_6373;
    goto v_6383;
v_6377:
    v_6404 = elt(env, 2); // !:rd!:
    goto v_6378;
v_6379:
    v_6403 = v_6402;
    goto v_6380;
v_6381:
    v_6402 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6382;
v_6383:
    goto v_6377;
v_6378:
    goto v_6379;
v_6380:
    goto v_6381;
v_6382:
    v_6402 = list2star(v_6404, v_6403, v_6402);
    env = stack[0];
    goto v_6367;
v_6373:
    fn = elt(env, 4); // read!:num
    v_6402 = (*qfn1(fn))(fn, v_6402);
    env = stack[0];
    goto v_6367;
    v_6402 = nil;
v_6367:
    {
        fn = elt(env, 5); // normbf
        return (*qfn1(fn))(fn, v_6402);
    }
    v_6402 = nil;
    goto v_6351;
v_6353:
    goto v_6351;
    v_6402 = nil;
v_6351:
    goto v_6346;
v_6348:
    v_6403 = v_6402;
    if (!consp(v_6403)) goto v_6394;
    else goto v_6395;
v_6394:
    goto v_6346;
v_6395:
    {
        fn = elt(env, 6); // bf2flck
        return (*qfn1(fn))(fn, v_6402);
    }
    v_6402 = nil;
v_6346:
    return onevalue(v_6402);
}



// Code for ncmpchk

static LispObject CC_ncmpchk(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6369, v_6370;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_6344;
    stack[-1] = v_6343;
// end of prologue
    goto v_6355;
v_6351:
    v_6370 = stack[-1];
    goto v_6352;
v_6353:
    v_6369 = stack[0];
    goto v_6354;
v_6355:
    goto v_6351;
v_6352:
    goto v_6353;
v_6354:
    fn = elt(env, 1); // noncommuting
    v_6369 = (*qfn2(fn))(fn, v_6370, v_6369);
    env = stack[-2];
    if (v_6369 == nil) goto v_6348;
    else goto v_6349;
v_6348:
    v_6369 = lisp_true;
    goto v_6347;
v_6349:
    goto v_6366;
v_6362:
    v_6370 = stack[-1];
    goto v_6363;
v_6364:
    v_6369 = stack[0];
    goto v_6365;
v_6366:
    goto v_6362;
v_6363:
    goto v_6364;
v_6365:
    {
        fn = elt(env, 2); // physop!-ordop
        return (*qfn2(fn))(fn, v_6370, v_6369);
    }
    v_6369 = nil;
v_6347:
    return onevalue(v_6369);
}



// Code for mv!-pow!-!-

static LispObject CC_mvKpowKK(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6380, v_6381;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_6344;
    stack[-1] = v_6343;
// end of prologue
    stack[-2] = nil;
v_6349:
    v_6380 = stack[-1];
    if (v_6380 == nil) goto v_6352;
    else goto v_6353;
v_6352:
    v_6380 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_6380);
    }
v_6353:
    goto v_6364;
v_6360:
    goto v_6370;
v_6366:
    v_6380 = stack[-1];
    v_6381 = qcar(v_6380);
    goto v_6367;
v_6368:
    v_6380 = stack[0];
    v_6380 = qcar(v_6380);
    goto v_6369;
v_6370:
    goto v_6366;
v_6367:
    goto v_6368;
v_6369:
    v_6381 = difference2(v_6381, v_6380);
    env = stack[-3];
    goto v_6361;
v_6362:
    v_6380 = stack[-2];
    goto v_6363;
v_6364:
    goto v_6360;
v_6361:
    goto v_6362;
v_6363:
    v_6380 = cons(v_6381, v_6380);
    env = stack[-3];
    stack[-2] = v_6380;
    v_6380 = stack[-1];
    v_6380 = qcdr(v_6380);
    stack[-1] = v_6380;
    v_6380 = stack[0];
    v_6380 = qcdr(v_6380);
    stack[0] = v_6380;
    goto v_6349;
    v_6380 = nil;
    return onevalue(v_6380);
}



// Code for artimes!:

static LispObject CC_artimesT(LispObject env,
                         LispObject v_6343, LispObject v_6344)
{
    env = qenv(env);
    LispObject v_6369, v_6370, v_6371;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6344,v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6343,v_6344);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_6370 = v_6344;
    v_6371 = v_6343;
// end of prologue
// Binding dmode!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = nil; // dmode!*
// Binding !*exp
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-3, 2, -1);
    qvalue(elt(env, 2)) = nil; // !*exp
    v_6369 = lisp_true;
    qvalue(elt(env, 2)) = v_6369; // !*exp
    goto v_6356;
v_6352:
    stack[0] = elt(env, 3); // !:ar!:
    goto v_6353;
v_6354:
    goto v_6364;
v_6360:
    v_6369 = v_6371;
    v_6369 = qcdr(v_6369);
    goto v_6361;
v_6362:
    v_6370 = qcdr(v_6370);
    goto v_6363;
v_6364:
    goto v_6360;
v_6361:
    goto v_6362;
v_6363:
    fn = elt(env, 4); // multf
    v_6369 = (*qfn2(fn))(fn, v_6369, v_6370);
    env = stack[-3];
    fn = elt(env, 5); // reducepowers
    v_6369 = (*qfn1(fn))(fn, v_6369);
    env = stack[-3];
    goto v_6355;
v_6356:
    goto v_6352;
v_6353:
    goto v_6354;
v_6355:
    v_6369 = cons(stack[0], v_6369);
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_6369);
}



// Code for lalr_make_compressed_action_row

static LispObject CC_lalr_make_compressed_action_row(LispObject env,
                         LispObject v_6343)
{
    env = qenv(env);
    LispObject v_6361, v_6362;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6343);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6343);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_6343;
// end of prologue
    v_6361 = stack[0];
    fn = elt(env, 1); // lalr_list_of_actions
    v_6361 = (*qfn1(fn))(fn, v_6361);
    env = stack[-1];
    goto v_6355;
v_6351:
    v_6362 = v_6361;
    goto v_6352;
v_6353:
    v_6361 = stack[0];
    v_6361 = qcdr(v_6361);
    goto v_6354;
v_6355:
    goto v_6351;
v_6352:
    goto v_6353;
v_6354:
    fn = elt(env, 2); // lalr_resolve_conflicts
    v_6361 = (*qfn2(fn))(fn, v_6362, v_6361);
    env = stack[-1];
    {
        fn = elt(env, 3); // lalr_make_compressed_action_row1
        return (*qfn1(fn))(fn, v_6361);
    }
    return onevalue(v_6361);
}



setup_type const u12_setup[] =
{
    {"totalcompare",            TOO_FEW_2,      CC_totalcompare,WRONG_NO_2},
    {"rl_smrmknowl",            TOO_FEW_2,      CC_rl_smrmknowl,WRONG_NO_2},
    {"ibalp_getvar-zmom",       TOO_FEW_2,      CC_ibalp_getvarKzmom,WRONG_NO_2},
    {"integerom",               CC_integerom,   TOO_MANY_1,    WRONG_NO_1},
    {"writepri",                TOO_FEW_2,      CC_writepri,   WRONG_NO_2},
    {"cut:ep",                  TOO_FEW_2,      CC_cutTep,     WRONG_NO_2},
    {"getphystypesf",           CC_getphystypesf,TOO_MANY_1,   WRONG_NO_1},
    {"split-road",              TOO_FEW_2,      CC_splitKroad, WRONG_NO_2},
    {"simp",                    CC_simp,        TOO_MANY_1,    WRONG_NO_1},
    {"compactfmatch2",          CC_compactfmatch2,TOO_MANY_1,  WRONG_NO_1},
    {"dp=mocompare",            TOO_FEW_2,      CC_dpMmocompare,WRONG_NO_2},
    {"raiseind:",               CC_raiseindT,   TOO_MANY_1,    WRONG_NO_1},
    {"ra_budan-transform",      CC_ra_budanKtransform,TOO_MANY_1,WRONG_NO_1},
    {"formprogn",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formprogn},
    {"color1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_color1},
    {"msappend",                TOO_FEW_2,      CC_msappend,   WRONG_NO_2},
    {"cl_simpl",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_simpl},
    {"qsort",                   CC_qsort,       TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_getnewwl",          CC_ibalp_getnewwl,TOO_MANY_1,  WRONG_NO_1},
    {"omiir",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_omiir},
    {"c:extadd",                TOO_FEW_2,      CC_cTextadd,   WRONG_NO_2},
    {"comm_kernels1",           TOO_FEW_2,      CC_comm_kernels1,WRONG_NO_2},
    {"addpf",                   TOO_FEW_2,      CC_addpf,      WRONG_NO_2},
    {"gfrsq",                   CC_gfrsq,       TOO_MANY_1,    WRONG_NO_1},
    {"safe-fp-times",           TOO_FEW_2,      CC_safeKfpKtimes,WRONG_NO_2},
    {"condterpri",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_condterpri},
    {"argnochk",                CC_argnochk,    TOO_MANY_1,    WRONG_NO_1},
    {"make-term",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_makeKterm},
    {"red_divtest",             TOO_FEW_2,      CC_red_divtest,WRONG_NO_2},
    {"ordn",                    CC_ordn,        TOO_MANY_1,    WRONG_NO_1},
    {"rnminus:",                CC_rnminusT,    TOO_MANY_1,    WRONG_NO_1},
    {"horner-rule",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_hornerKrule},
    {"freeofl",                 TOO_FEW_2,      CC_freeofl,    WRONG_NO_2},
    {"split_f",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_split_f},
    {"ofsf_smwcpknowl",         CC_ofsf_smwcpknowl,TOO_MANY_1, WRONG_NO_1},
    {"get_rep_matrix_in",       TOO_FEW_2,      CC_get_rep_matrix_in,WRONG_NO_2},
    {"cl_fvarl",                CC_cl_fvarl,    TOO_MANY_1,    WRONG_NO_1},
    {"cl_varl2",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_varl2},
    {"omvir",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_omvir},
    {"simpexpon1",              TOO_FEW_2,      CC_simpexpon1, WRONG_NO_2},
    {"sc_setmat",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_sc_setmat},
    {"vdpzero",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vdpzero},
    {"revalind",                CC_revalind,    TOO_MANY_1,    WRONG_NO_1},
    {"flatindxl",               CC_flatindxl,   TOO_MANY_1,    WRONG_NO_1},
    {"convchk",                 CC_convchk,     TOO_MANY_1,    WRONG_NO_1},
    {"ncmpchk",                 TOO_FEW_2,      CC_ncmpchk,    WRONG_NO_2},
    {"mv-pow--",                TOO_FEW_2,      CC_mvKpowKK,   WRONG_NO_2},
    {"artimes:",                TOO_FEW_2,      CC_artimesT,   WRONG_NO_2},
    {"lalr_make_compressed_action_row",CC_lalr_make_compressed_action_row,TOO_MANY_1,WRONG_NO_1},
    {NULL, (one_args *)"u12", (two_args *)"75728 6031767 338853", 0}
};

// end of generated code
