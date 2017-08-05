
// $destdir/u60.c        Machine generated C code

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



// Code for com43

static LispObject CC_com43(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_38077, v_38078, v_38079, v_38080;
    LispObject fn;
    LispObject v_36176, v_36175, v_36174, v_36173, v_36172, v_36171;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "com43");
    va_start(aa, nargs);
    v_36171 = va_arg(aa, LispObject);
    v_36172 = va_arg(aa, LispObject);
    v_36173 = va_arg(aa, LispObject);
    v_36174 = va_arg(aa, LispObject);
    v_36175 = va_arg(aa, LispObject);
    v_36176 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_36176,v_36175,v_36174,v_36173,v_36172,v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_36171,v_36172,v_36173,v_36174,v_36175,v_36176);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(17);
// copy arguments values to proper place
    stack[-4] = v_36176;
    stack[-5] = v_36175;
    stack[-6] = v_36174;
    stack[-7] = v_36173;
    stack[-8] = v_36172;
    stack[-9] = v_36171;
// end of prologue
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-15] = v_38077;
    goto v_36191;
v_36185:
    goto v_36199;
v_36193:
    v_38079 = elt(env, 1); // liemat
    goto v_36194;
v_36195:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36196;
v_36197:
    v_38077 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36198;
v_36199:
    goto v_36193;
v_36194:
    goto v_36195;
v_36196:
    goto v_36197;
v_36198:
    stack[-1] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36186;
v_36187:
    goto v_36210;
v_36204:
    v_38079 = elt(env, 2); // bb
    goto v_36205;
v_36206:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36207;
v_36208:
    v_38077 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36209;
v_36210:
    goto v_36204;
v_36205:
    goto v_36206;
v_36207:
    goto v_36208;
v_36209:
    stack[0] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36188;
v_36189:
    goto v_36221;
v_36215:
    v_38079 = elt(env, 3); // ff
    goto v_36216;
v_36217:
    v_38078 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_36218;
v_36219:
    v_38077 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_36220;
v_36221:
    goto v_36215;
v_36216:
    goto v_36217;
v_36218:
    goto v_36219;
v_36220:
    v_38077 = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36190;
v_36191:
    goto v_36185;
v_36186:
    goto v_36187;
v_36188:
    goto v_36189;
v_36190:
    v_38077 = list3(stack[-1], stack[0], v_38077);
    env = stack[-16];
    fn = elt(env, 15); // matrix
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    fn = elt(env, 16); // aeval
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_36230;
v_36226:
    stack[0] = elt(env, 4); // algebraic
    goto v_36227;
v_36228:
    goto v_36242;
v_36234:
    v_38080 = elt(env, 5); // l_z
    goto v_36235;
v_36236:
    v_38079 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36237;
v_36238:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36239;
v_36240:
    v_38077 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_36241;
v_36242:
    goto v_36234;
v_36235:
    goto v_36236;
v_36237:
    goto v_36238;
v_36239:
    goto v_36240;
v_36241:
    v_38077 = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    v_38077 = ncons(v_38077);
    env = stack[-16];
    goto v_36229;
v_36230:
    goto v_36226;
v_36227:
    goto v_36228;
v_36229:
    fn = elt(env, 17); // arrayfn
    v_38077 = (*qfn2(fn))(fn, stack[0], v_38077);
    env = stack[-16];
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-10] = v_38077;
v_36250:
    goto v_36262;
v_36258:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36259;
v_36260:
    v_38077 = stack[-10];
    goto v_36261;
v_36262:
    goto v_36258;
v_36259:
    goto v_36260;
v_36261:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_36255;
    goto v_36249;
v_36255:
    goto v_36271;
v_36267:
    goto v_36281;
v_36273:
    v_38080 = elt(env, 6); // cc
    goto v_36274;
v_36275:
    v_38079 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_36276;
v_36277:
    v_38078 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36278;
v_36279:
    v_38077 = stack[-10];
    goto v_36280;
v_36281:
    goto v_36273;
v_36274:
    goto v_36275;
v_36276:
    goto v_36277;
v_36278:
    goto v_36279;
v_36280:
    stack[-1] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36268;
v_36269:
    goto v_36292;
v_36288:
    stack[0] = elt(env, 7); // minus
    goto v_36289;
v_36290:
    goto v_36303;
v_36295:
    v_38080 = elt(env, 6); // cc
    goto v_36296;
v_36297:
    v_38079 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36298;
v_36299:
    v_38078 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_36300;
v_36301:
    v_38077 = stack[-10];
    goto v_36302;
v_36303:
    goto v_36295;
v_36296:
    goto v_36297;
v_36298:
    goto v_36299;
v_36300:
    goto v_36301;
v_36302:
    v_38077 = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36291;
v_36292:
    goto v_36288;
v_36289:
    goto v_36290;
v_36291:
    v_38077 = list2(stack[0], v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_36270;
v_36271:
    goto v_36267;
v_36268:
    goto v_36269;
v_36270:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[-1], v_38077);
    env = stack[-16];
    goto v_36313;
v_36309:
    goto v_36323;
v_36315:
    v_38080 = elt(env, 6); // cc
    goto v_36316;
v_36317:
    v_38079 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_36318;
v_36319:
    v_38078 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36320;
v_36321:
    v_38077 = stack[-10];
    goto v_36322;
v_36323:
    goto v_36315;
v_36316:
    goto v_36317;
v_36318:
    goto v_36319;
v_36320:
    goto v_36321;
v_36322:
    stack[-1] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36310;
v_36311:
    goto v_36334;
v_36330:
    stack[0] = elt(env, 7); // minus
    goto v_36331;
v_36332:
    goto v_36345;
v_36337:
    v_38080 = elt(env, 6); // cc
    goto v_36338;
v_36339:
    v_38079 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36340;
v_36341:
    v_38078 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_36342;
v_36343:
    v_38077 = stack[-10];
    goto v_36344;
v_36345:
    goto v_36337;
v_36338:
    goto v_36339;
v_36340:
    goto v_36341;
v_36342:
    goto v_36343;
v_36344:
    v_38077 = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36333;
v_36334:
    goto v_36330;
v_36331:
    goto v_36332;
v_36333:
    v_38077 = list2(stack[0], v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_36312;
v_36313:
    goto v_36309;
v_36310:
    goto v_36311;
v_36312:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[-1], v_38077);
    env = stack[-16];
    goto v_36355;
v_36351:
    goto v_36365;
v_36357:
    v_38080 = elt(env, 6); // cc
    goto v_36358;
v_36359:
    v_38079 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_36360;
v_36361:
    v_38078 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_36362;
v_36363:
    v_38077 = stack[-10];
    goto v_36364;
v_36365:
    goto v_36357;
v_36358:
    goto v_36359;
v_36360:
    goto v_36361;
v_36362:
    goto v_36363;
v_36364:
    stack[-1] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36352;
v_36353:
    goto v_36376;
v_36372:
    stack[0] = elt(env, 7); // minus
    goto v_36373;
v_36374:
    goto v_36387;
v_36379:
    v_38080 = elt(env, 6); // cc
    goto v_36380;
v_36381:
    v_38079 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_36382;
v_36383:
    v_38078 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_36384;
v_36385:
    v_38077 = stack[-10];
    goto v_36386;
v_36387:
    goto v_36379;
v_36380:
    goto v_36381;
v_36382:
    goto v_36383;
v_36384:
    goto v_36385;
v_36386:
    v_38077 = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36375;
v_36376:
    goto v_36372;
v_36373:
    goto v_36374;
v_36375:
    v_38077 = list2(stack[0], v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_36354;
v_36355:
    goto v_36351;
v_36352:
    goto v_36353;
v_36354:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[-1], v_38077);
    env = stack[-16];
    goto v_36397;
v_36393:
    goto v_36407;
v_36399:
    v_38080 = elt(env, 6); // cc
    goto v_36400;
v_36401:
    v_38079 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36402;
v_36403:
    v_38078 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36404;
v_36405:
    v_38077 = stack[-10];
    goto v_36406;
v_36407:
    goto v_36399;
v_36400:
    goto v_36401;
v_36402:
    goto v_36403;
v_36404:
    goto v_36405;
v_36406:
    stack[-1] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36394;
v_36395:
    goto v_36418;
v_36414:
    stack[0] = elt(env, 7); // minus
    goto v_36415;
v_36416:
    goto v_36429;
v_36421:
    v_38080 = elt(env, 6); // cc
    goto v_36422;
v_36423:
    v_38079 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36424;
v_36425:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36426;
v_36427:
    v_38077 = stack[-10];
    goto v_36428;
v_36429:
    goto v_36421;
v_36422:
    goto v_36423;
v_36424:
    goto v_36425;
v_36426:
    goto v_36427;
v_36428:
    v_38077 = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36417;
v_36418:
    goto v_36414;
v_36415:
    goto v_36416;
v_36417:
    v_38077 = list2(stack[0], v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_36396;
v_36397:
    goto v_36393;
v_36394:
    goto v_36395;
v_36396:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[-1], v_38077);
    env = stack[-16];
    goto v_36439;
v_36435:
    goto v_36449;
v_36441:
    v_38080 = elt(env, 6); // cc
    goto v_36442;
v_36443:
    v_38079 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36444;
v_36445:
    v_38078 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_36446;
v_36447:
    v_38077 = stack[-10];
    goto v_36448;
v_36449:
    goto v_36441;
v_36442:
    goto v_36443;
v_36444:
    goto v_36445;
v_36446:
    goto v_36447;
v_36448:
    stack[-1] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36436;
v_36437:
    goto v_36460;
v_36456:
    stack[0] = elt(env, 7); // minus
    goto v_36457;
v_36458:
    goto v_36471;
v_36463:
    v_38080 = elt(env, 6); // cc
    goto v_36464;
v_36465:
    v_38079 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_36466;
v_36467:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36468;
v_36469:
    v_38077 = stack[-10];
    goto v_36470;
v_36471:
    goto v_36463;
v_36464:
    goto v_36465;
v_36466:
    goto v_36467;
v_36468:
    goto v_36469;
v_36470:
    v_38077 = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36459;
v_36460:
    goto v_36456;
v_36457:
    goto v_36458;
v_36459:
    v_38077 = list2(stack[0], v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_36438;
v_36439:
    goto v_36435;
v_36436:
    goto v_36437;
v_36438:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[-1], v_38077);
    env = stack[-16];
    goto v_36481;
v_36477:
    goto v_36491;
v_36483:
    v_38080 = elt(env, 6); // cc
    goto v_36484;
v_36485:
    v_38079 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36486;
v_36487:
    v_38078 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_36488;
v_36489:
    v_38077 = stack[-10];
    goto v_36490;
v_36491:
    goto v_36483;
v_36484:
    goto v_36485;
v_36486:
    goto v_36487;
v_36488:
    goto v_36489;
v_36490:
    stack[-1] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36478;
v_36479:
    goto v_36502;
v_36498:
    stack[0] = elt(env, 7); // minus
    goto v_36499;
v_36500:
    goto v_36513;
v_36505:
    v_38080 = elt(env, 6); // cc
    goto v_36506;
v_36507:
    v_38079 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_36508;
v_36509:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36510;
v_36511:
    v_38077 = stack[-10];
    goto v_36512;
v_36513:
    goto v_36505;
v_36506:
    goto v_36507;
v_36508:
    goto v_36509;
v_36510:
    goto v_36511;
v_36512:
    v_38077 = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36501;
v_36502:
    goto v_36498;
v_36499:
    goto v_36500;
v_36501:
    v_38077 = list2(stack[0], v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_36480;
v_36481:
    goto v_36477;
v_36478:
    goto v_36479;
v_36480:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[-1], v_38077);
    env = stack[-16];
    goto v_36523;
v_36519:
    goto v_36533;
v_36525:
    v_38080 = elt(env, 6); // cc
    goto v_36526;
v_36527:
    v_38079 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36528;
v_36529:
    v_38078 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36530;
v_36531:
    v_38077 = stack[-10];
    goto v_36532;
v_36533:
    goto v_36525;
v_36526:
    goto v_36527;
v_36528:
    goto v_36529;
v_36530:
    goto v_36531;
v_36532:
    stack[-3] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36520;
v_36521:
    goto v_36543;
v_36539:
    goto v_36553;
v_36545:
    v_38080 = elt(env, 6); // cc
    goto v_36546;
v_36547:
    v_38079 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_36548;
v_36549:
    v_38078 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_36550;
v_36551:
    v_38077 = stack[-10];
    goto v_36552;
v_36553:
    goto v_36545;
v_36546:
    goto v_36547;
v_36548:
    goto v_36549;
v_36550:
    goto v_36551;
v_36552:
    stack[-2] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36540;
v_36541:
    goto v_36563;
v_36559:
    goto v_36573;
v_36565:
    v_38080 = elt(env, 6); // cc
    goto v_36566;
v_36567:
    v_38079 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_36568;
v_36569:
    v_38078 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_36570;
v_36571:
    v_38077 = stack[-10];
    goto v_36572;
v_36573:
    goto v_36565;
v_36566:
    goto v_36567;
v_36568:
    goto v_36569;
v_36570:
    goto v_36571;
v_36572:
    stack[-1] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36560;
v_36561:
    goto v_36583;
v_36579:
    goto v_36593;
v_36585:
    v_38080 = elt(env, 6); // cc
    goto v_36586;
v_36587:
    v_38079 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36588;
v_36589:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36590;
v_36591:
    v_38077 = stack[-10];
    goto v_36592;
v_36593:
    goto v_36585;
v_36586:
    goto v_36587;
v_36588:
    goto v_36589;
v_36590:
    goto v_36591;
v_36592:
    stack[0] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36580;
v_36581:
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_36582;
v_36583:
    goto v_36579;
v_36580:
    goto v_36581;
v_36582:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[0], v_38077);
    env = stack[-16];
    goto v_36562;
v_36563:
    goto v_36559;
v_36560:
    goto v_36561;
v_36562:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[-1], v_38077);
    env = stack[-16];
    goto v_36542;
v_36543:
    goto v_36539;
v_36540:
    goto v_36541;
v_36542:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[-2], v_38077);
    env = stack[-16];
    goto v_36522;
v_36523:
    goto v_36519;
v_36520:
    goto v_36521;
v_36522:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[-3], v_38077);
    env = stack[-16];
    goto v_36605;
v_36601:
    goto v_36613;
v_36607:
    v_38079 = elt(env, 1); // liemat
    goto v_36608;
v_36609:
    v_38078 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36610;
v_36611:
    v_38077 = stack[-10];
    goto v_36612;
v_36613:
    goto v_36607;
v_36608:
    goto v_36609;
v_36610:
    goto v_36611;
v_36612:
    stack[0] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36602;
v_36603:
    goto v_36627;
v_36619:
    v_38080 = elt(env, 6); // cc
    goto v_36620;
v_36621:
    v_38079 = stack[-9];
    goto v_36622;
v_36623:
    v_38078 = stack[-8];
    goto v_36624;
v_36625:
    v_38077 = stack[-10];
    goto v_36626;
v_36627:
    goto v_36619;
v_36620:
    goto v_36621;
v_36622:
    goto v_36623;
v_36624:
    goto v_36625;
v_36626:
    v_38077 = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_36604;
v_36605:
    goto v_36601;
v_36602:
    goto v_36603;
v_36604:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[0], v_38077);
    env = stack[-16];
    goto v_36637;
v_36633:
    goto v_36645;
v_36639:
    v_38079 = elt(env, 1); // liemat
    goto v_36640;
v_36641:
    v_38078 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_36642;
v_36643:
    v_38077 = stack[-10];
    goto v_36644;
v_36645:
    goto v_36639;
v_36640:
    goto v_36641;
v_36642:
    goto v_36643;
v_36644:
    stack[0] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36634;
v_36635:
    goto v_36659;
v_36651:
    v_38080 = elt(env, 6); // cc
    goto v_36652;
v_36653:
    v_38079 = stack[-7];
    goto v_36654;
v_36655:
    v_38078 = stack[-6];
    goto v_36656;
v_36657:
    v_38077 = stack[-10];
    goto v_36658;
v_36659:
    goto v_36651;
v_36652:
    goto v_36653;
v_36654:
    goto v_36655;
v_36656:
    goto v_36657;
v_36658:
    v_38077 = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_36636;
v_36637:
    goto v_36633;
v_36634:
    goto v_36635;
v_36636:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[0], v_38077);
    env = stack[-16];
    goto v_36669;
v_36665:
    goto v_36677;
v_36671:
    v_38079 = elt(env, 1); // liemat
    goto v_36672;
v_36673:
    v_38078 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_36674;
v_36675:
    v_38077 = stack[-10];
    goto v_36676;
v_36677:
    goto v_36671;
v_36672:
    goto v_36673;
v_36674:
    goto v_36675;
v_36676:
    stack[0] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36666;
v_36667:
    goto v_36691;
v_36683:
    v_38080 = elt(env, 6); // cc
    goto v_36684;
v_36685:
    v_38079 = stack[-5];
    goto v_36686;
v_36687:
    v_38078 = stack[-4];
    goto v_36688;
v_36689:
    v_38077 = stack[-10];
    goto v_36690;
v_36691:
    goto v_36683;
v_36684:
    goto v_36685;
v_36686:
    goto v_36687;
v_36688:
    goto v_36689;
v_36690:
    v_38077 = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_36668;
v_36669:
    goto v_36665;
v_36666:
    goto v_36667;
v_36668:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[0], v_38077);
    env = stack[-16];
    v_38077 = stack[-10];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-10] = v_38077;
    goto v_36250;
v_36249:
    goto v_36703;
v_36699:
    goto v_36711;
v_36705:
    v_38079 = elt(env, 1); // liemat
    goto v_36706;
v_36707:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36708;
v_36709:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36710;
v_36711:
    goto v_36705;
v_36706:
    goto v_36707;
v_36708:
    goto v_36709;
v_36710:
    stack[0] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36700;
v_36701:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 16); // aeval
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_36702;
v_36703:
    goto v_36699;
v_36700:
    goto v_36701;
v_36702:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[0], v_38077);
    env = stack[-16];
    goto v_36726;
v_36722:
    goto v_36733;
v_36729:
    v_38078 = elt(env, 8); // det
    goto v_36730;
v_36731:
    v_38077 = elt(env, 1); // liemat
    goto v_36732;
v_36733:
    goto v_36729;
v_36730:
    goto v_36731;
v_36732:
    v_38077 = list2(v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 16); // aeval
    v_38078 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_36723;
v_36724:
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_36725;
v_36726:
    goto v_36722;
v_36723:
    goto v_36724;
v_36725:
    fn = elt(env, 20); // evalneq
    v_38077 = (*qfn2(fn))(fn, v_38078, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_36720;
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 16); // aeval
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-15] = v_38077;
    goto v_36718;
v_36720:
    v_38077 = (LispObject)32+TAG_FIXNUM; // 2
    stack[-2] = v_38077;
v_36744:
    goto v_36756;
v_36752:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36753;
v_36754:
    v_38077 = stack[-2];
    goto v_36755;
v_36756:
    goto v_36752;
v_36753:
    goto v_36754;
v_36755:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_36749;
    goto v_36743;
v_36749:
    goto v_36765;
v_36761:
    goto v_36773;
v_36767:
    stack[-1] = elt(env, 1); // liemat
    goto v_36768;
v_36769:
    stack[0] = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36770;
v_36771:
    v_38077 = stack[-2];
    v_38077 = sub1(v_38077);
    env = stack[-16];
    goto v_36772;
v_36773:
    goto v_36767;
v_36768:
    goto v_36769;
v_36770:
    goto v_36771;
v_36772:
    stack[0] = list3(stack[-1], stack[0], v_38077);
    env = stack[-16];
    goto v_36762;
v_36763:
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_36764;
v_36765:
    goto v_36761;
v_36762:
    goto v_36763;
v_36764:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[0], v_38077);
    env = stack[-16];
    goto v_36785;
v_36781:
    goto v_36793;
v_36787:
    v_38079 = elt(env, 1); // liemat
    goto v_36788;
v_36789:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36790;
v_36791:
    v_38077 = stack[-2];
    goto v_36792;
v_36793:
    goto v_36787;
v_36788:
    goto v_36789;
v_36790:
    goto v_36791;
v_36792:
    stack[0] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36782;
v_36783:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_36784;
v_36785:
    goto v_36781;
v_36782:
    goto v_36783;
v_36784:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[0], v_38077);
    env = stack[-16];
    goto v_36808;
v_36804:
    goto v_36815;
v_36811:
    v_38078 = elt(env, 8); // det
    goto v_36812;
v_36813:
    v_38077 = elt(env, 1); // liemat
    goto v_36814;
v_36815:
    goto v_36811;
v_36812:
    goto v_36813;
v_36814:
    v_38077 = list2(v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38078 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_36805;
v_36806:
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_36807;
v_36808:
    goto v_36804;
v_36805:
    goto v_36806;
v_36807:
    fn = elt(env, 20); // evalneq
    v_38077 = (*qfn2(fn))(fn, v_38078, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_36802;
    v_38077 = stack[-2];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-15] = v_38077;
    v_38077 = (LispObject)64+TAG_FIXNUM; // 4
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-2] = v_38077;
    goto v_36800;
v_36802:
v_36800:
    v_38077 = stack[-2];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-2] = v_38077;
    goto v_36744;
v_36743:
    goto v_36718;
v_36718:
    goto v_36830;
v_36826:
    stack[0] = elt(env, 2); // bb
    goto v_36827;
v_36828:
    goto v_36840;
v_36834:
    v_38079 = elt(env, 9); // quotient
    goto v_36835;
v_36836:
    v_38078 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36837;
v_36838:
    v_38077 = elt(env, 1); // liemat
    goto v_36839;
v_36840:
    goto v_36834;
v_36835:
    goto v_36836;
v_36837:
    goto v_36838;
v_36839:
    v_38077 = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 16); // aeval
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_36829;
v_36830:
    goto v_36826;
v_36827:
    goto v_36828;
v_36829:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[0], v_38077);
    env = stack[-16];
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-14] = v_38077;
v_36847:
    goto v_36859;
v_36855:
    v_38078 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_36856;
v_36857:
    v_38077 = stack[-14];
    goto v_36858;
v_36859:
    goto v_36855;
v_36856:
    goto v_36857;
v_36858:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_36852;
    goto v_36846;
v_36852:
    goto v_36868;
v_36864:
    goto v_36878;
v_36870:
    v_38080 = elt(env, 5); // l_z
    goto v_36871;
v_36872:
    v_38079 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36873;
v_36874:
    v_38078 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_36875;
v_36876:
    v_38077 = stack[-14];
    goto v_36877;
v_36878:
    goto v_36870;
v_36871:
    goto v_36872;
v_36873:
    goto v_36874;
v_36875:
    goto v_36876;
v_36877:
    stack[-13] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36865;
v_36866:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-12] = v_38077;
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-11] = v_38077;
v_36887:
    goto v_36900;
v_36896:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36897;
v_36898:
    v_38077 = stack[-12];
    goto v_36899;
v_36900:
    goto v_36896;
v_36897:
    goto v_36898;
v_36899:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_36893;
    v_38077 = stack[-11];
    goto v_36886;
v_36893:
    goto v_36912;
v_36906:
    stack[-10] = elt(env, 10); // plus
    goto v_36907;
v_36908:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-9] = v_38077;
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-8] = v_38077;
v_36918:
    goto v_36931;
v_36927:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36928;
v_36929:
    v_38077 = stack[-9];
    goto v_36930;
v_36931:
    goto v_36927;
v_36928:
    goto v_36929;
v_36930:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_36924;
    v_38077 = stack[-8];
    v_38078 = v_38077;
    goto v_36917;
v_36924:
    goto v_36943;
v_36937:
    stack[-7] = elt(env, 10); // plus
    goto v_36938;
v_36939:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_38077;
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_38077;
v_36949:
    goto v_36962;
v_36958:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_36959;
v_36960:
    v_38077 = stack[-6];
    goto v_36961;
v_36962:
    goto v_36958;
v_36959:
    goto v_36960;
v_36961:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_36955;
    v_38077 = stack[-5];
    v_38078 = v_38077;
    goto v_36948;
v_36955:
    goto v_36974;
v_36968:
    stack[-4] = elt(env, 10); // plus
    goto v_36969;
v_36970:
    goto v_36986;
v_36978:
    stack[-3] = elt(env, 11); // times
    goto v_36979;
v_36980:
    goto v_36995;
v_36989:
    v_38079 = elt(env, 1); // liemat
    goto v_36990;
v_36991:
    v_38078 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36992;
v_36993:
    v_38077 = stack[-12];
    goto v_36994;
v_36995:
    goto v_36989;
v_36990:
    goto v_36991;
v_36992:
    goto v_36993;
v_36994:
    stack[-2] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36981;
v_36982:
    goto v_37006;
v_37000:
    v_38079 = elt(env, 1); // liemat
    goto v_37001;
v_37002:
    v_38078 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_37003;
v_37004:
    v_38077 = stack[-9];
    goto v_37005;
v_37006:
    goto v_37000;
v_37001:
    goto v_37002;
v_37003:
    goto v_37004;
v_37005:
    stack[-1] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_36983;
v_36984:
    goto v_37015;
v_37011:
    goto v_37025;
v_37017:
    v_38080 = elt(env, 6); // cc
    goto v_37018;
v_37019:
    v_38079 = stack[-12];
    goto v_37020;
v_37021:
    v_38078 = stack[-9];
    goto v_37022;
v_37023:
    v_38077 = stack[-6];
    goto v_37024;
v_37025:
    goto v_37017;
v_37018:
    goto v_37019;
v_37020:
    goto v_37021;
v_37022:
    goto v_37023;
v_37024:
    stack[0] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37012;
v_37013:
    goto v_37037;
v_37031:
    v_38079 = elt(env, 2); // bb
    goto v_37032;
v_37033:
    v_38078 = stack[-6];
    goto v_37034;
v_37035:
    v_38077 = stack[-14];
    goto v_37036;
v_37037:
    goto v_37031;
v_37032:
    goto v_37033;
v_37034:
    goto v_37035;
v_37036:
    v_38077 = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37014;
v_37015:
    goto v_37011;
v_37012:
    goto v_37013;
v_37014:
    v_38077 = list2(stack[0], v_38077);
    env = stack[-16];
    goto v_36985;
v_36986:
    goto v_36978;
v_36979:
    goto v_36980;
v_36981:
    goto v_36982;
v_36983:
    goto v_36984;
v_36985:
    v_38077 = list3star(stack[-3], stack[-2], stack[-1], v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38078 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_36971;
v_36972:
    v_38077 = stack[-5];
    goto v_36973;
v_36974:
    goto v_36968;
v_36969:
    goto v_36970;
v_36971:
    goto v_36972;
v_36973:
    v_38077 = list3(stack[-4], v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-5] = v_38077;
    v_38077 = stack[-6];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-6] = v_38077;
    goto v_36949;
v_36948:
    goto v_36940;
v_36941:
    v_38077 = stack[-8];
    goto v_36942;
v_36943:
    goto v_36937;
v_36938:
    goto v_36939;
v_36940:
    goto v_36941;
v_36942:
    v_38077 = list3(stack[-7], v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-8] = v_38077;
    v_38077 = stack[-9];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-9] = v_38077;
    goto v_36918;
v_36917:
    goto v_36909;
v_36910:
    v_38077 = stack[-11];
    goto v_36911;
v_36912:
    goto v_36906;
v_36907:
    goto v_36908;
v_36909:
    goto v_36910;
v_36911:
    v_38077 = list3(stack[-10], v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-11] = v_38077;
    v_38077 = stack[-12];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-12] = v_38077;
    goto v_36887;
v_36886:
    goto v_36867;
v_36868:
    goto v_36864;
v_36865:
    goto v_36866;
v_36867:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[-13], v_38077);
    env = stack[-16];
    goto v_37055;
v_37051:
    goto v_37065;
v_37057:
    v_38080 = elt(env, 5); // l_z
    goto v_37058;
v_37059:
    v_38079 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_37060;
v_37061:
    v_38078 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_37062;
v_37063:
    v_38077 = stack[-14];
    goto v_37064;
v_37065:
    goto v_37057;
v_37058:
    goto v_37059;
v_37060:
    goto v_37061;
v_37062:
    goto v_37063;
v_37064:
    stack[-13] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37052;
v_37053:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-12] = v_38077;
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-11] = v_38077;
v_37074:
    goto v_37087;
v_37083:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_37084;
v_37085:
    v_38077 = stack[-12];
    goto v_37086;
v_37087:
    goto v_37083;
v_37084:
    goto v_37085;
v_37086:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_37080;
    v_38077 = stack[-11];
    goto v_37073;
v_37080:
    goto v_37099;
v_37093:
    stack[-10] = elt(env, 10); // plus
    goto v_37094;
v_37095:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-9] = v_38077;
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-8] = v_38077;
v_37105:
    goto v_37118;
v_37114:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_37115;
v_37116:
    v_38077 = stack[-9];
    goto v_37117;
v_37118:
    goto v_37114;
v_37115:
    goto v_37116;
v_37117:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_37111;
    v_38077 = stack[-8];
    v_38078 = v_38077;
    goto v_37104;
v_37111:
    goto v_37130;
v_37124:
    stack[-7] = elt(env, 10); // plus
    goto v_37125;
v_37126:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_38077;
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_38077;
v_37136:
    goto v_37149;
v_37145:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_37146;
v_37147:
    v_38077 = stack[-6];
    goto v_37148;
v_37149:
    goto v_37145;
v_37146:
    goto v_37147;
v_37148:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_37142;
    v_38077 = stack[-5];
    v_38078 = v_38077;
    goto v_37135;
v_37142:
    goto v_37161;
v_37155:
    stack[-4] = elt(env, 10); // plus
    goto v_37156;
v_37157:
    goto v_37173;
v_37165:
    stack[-3] = elt(env, 11); // times
    goto v_37166;
v_37167:
    goto v_37182;
v_37176:
    v_38079 = elt(env, 1); // liemat
    goto v_37177;
v_37178:
    v_38078 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_37179;
v_37180:
    v_38077 = stack[-12];
    goto v_37181;
v_37182:
    goto v_37176;
v_37177:
    goto v_37178;
v_37179:
    goto v_37180;
v_37181:
    stack[-2] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37168;
v_37169:
    goto v_37193;
v_37187:
    v_38079 = elt(env, 1); // liemat
    goto v_37188;
v_37189:
    v_38078 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_37190;
v_37191:
    v_38077 = stack[-9];
    goto v_37192;
v_37193:
    goto v_37187;
v_37188:
    goto v_37189;
v_37190:
    goto v_37191;
v_37192:
    stack[-1] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37170;
v_37171:
    goto v_37202;
v_37198:
    goto v_37212;
v_37204:
    v_38080 = elt(env, 6); // cc
    goto v_37205;
v_37206:
    v_38079 = stack[-12];
    goto v_37207;
v_37208:
    v_38078 = stack[-9];
    goto v_37209;
v_37210:
    v_38077 = stack[-6];
    goto v_37211;
v_37212:
    goto v_37204;
v_37205:
    goto v_37206;
v_37207:
    goto v_37208;
v_37209:
    goto v_37210;
v_37211:
    stack[0] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37199;
v_37200:
    goto v_37224;
v_37218:
    v_38079 = elt(env, 2); // bb
    goto v_37219;
v_37220:
    v_38078 = stack[-6];
    goto v_37221;
v_37222:
    v_38077 = stack[-14];
    goto v_37223;
v_37224:
    goto v_37218;
v_37219:
    goto v_37220;
v_37221:
    goto v_37222;
v_37223:
    v_38077 = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37201;
v_37202:
    goto v_37198;
v_37199:
    goto v_37200;
v_37201:
    v_38077 = list2(stack[0], v_38077);
    env = stack[-16];
    goto v_37172;
v_37173:
    goto v_37165;
v_37166:
    goto v_37167;
v_37168:
    goto v_37169;
v_37170:
    goto v_37171;
v_37172:
    v_38077 = list3star(stack[-3], stack[-2], stack[-1], v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38078 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_37158;
v_37159:
    v_38077 = stack[-5];
    goto v_37160;
v_37161:
    goto v_37155;
v_37156:
    goto v_37157;
v_37158:
    goto v_37159;
v_37160:
    v_38077 = list3(stack[-4], v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-5] = v_38077;
    v_38077 = stack[-6];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-6] = v_38077;
    goto v_37136;
v_37135:
    goto v_37127;
v_37128:
    v_38077 = stack[-8];
    goto v_37129;
v_37130:
    goto v_37124;
v_37125:
    goto v_37126;
v_37127:
    goto v_37128;
v_37129:
    v_38077 = list3(stack[-7], v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-8] = v_38077;
    v_38077 = stack[-9];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-9] = v_38077;
    goto v_37105;
v_37104:
    goto v_37096;
v_37097:
    v_38077 = stack[-11];
    goto v_37098;
v_37099:
    goto v_37093;
v_37094:
    goto v_37095;
v_37096:
    goto v_37097;
v_37098:
    v_38077 = list3(stack[-10], v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-11] = v_38077;
    v_38077 = stack[-12];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-12] = v_38077;
    goto v_37074;
v_37073:
    goto v_37054;
v_37055:
    goto v_37051;
v_37052:
    goto v_37053;
v_37054:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[-13], v_38077);
    env = stack[-16];
    goto v_37242;
v_37238:
    goto v_37252;
v_37244:
    v_38080 = elt(env, 5); // l_z
    goto v_37245;
v_37246:
    v_38079 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_37247;
v_37248:
    v_38078 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_37249;
v_37250:
    v_38077 = stack[-14];
    goto v_37251;
v_37252:
    goto v_37244;
v_37245:
    goto v_37246;
v_37247:
    goto v_37248;
v_37249:
    goto v_37250;
v_37251:
    stack[-13] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37239;
v_37240:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-12] = v_38077;
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-11] = v_38077;
v_37261:
    goto v_37274;
v_37270:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_37271;
v_37272:
    v_38077 = stack[-12];
    goto v_37273;
v_37274:
    goto v_37270;
v_37271:
    goto v_37272;
v_37273:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_37267;
    v_38077 = stack[-11];
    goto v_37260;
v_37267:
    goto v_37286;
v_37280:
    stack[-10] = elt(env, 10); // plus
    goto v_37281;
v_37282:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-9] = v_38077;
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-8] = v_38077;
v_37292:
    goto v_37305;
v_37301:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_37302;
v_37303:
    v_38077 = stack[-9];
    goto v_37304;
v_37305:
    goto v_37301;
v_37302:
    goto v_37303;
v_37304:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_37298;
    v_38077 = stack[-8];
    v_38078 = v_38077;
    goto v_37291;
v_37298:
    goto v_37317;
v_37311:
    stack[-7] = elt(env, 10); // plus
    goto v_37312;
v_37313:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-6] = v_38077;
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_38077;
v_37323:
    goto v_37336;
v_37332:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_37333;
v_37334:
    v_38077 = stack[-6];
    goto v_37335;
v_37336:
    goto v_37332;
v_37333:
    goto v_37334;
v_37335:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_37329;
    v_38077 = stack[-5];
    v_38078 = v_38077;
    goto v_37322;
v_37329:
    goto v_37348;
v_37342:
    stack[-4] = elt(env, 10); // plus
    goto v_37343;
v_37344:
    goto v_37360;
v_37352:
    stack[-3] = elt(env, 11); // times
    goto v_37353;
v_37354:
    goto v_37369;
v_37363:
    v_38079 = elt(env, 1); // liemat
    goto v_37364;
v_37365:
    v_38078 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_37366;
v_37367:
    v_38077 = stack[-12];
    goto v_37368;
v_37369:
    goto v_37363;
v_37364:
    goto v_37365;
v_37366:
    goto v_37367;
v_37368:
    stack[-2] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37355;
v_37356:
    goto v_37380;
v_37374:
    v_38079 = elt(env, 1); // liemat
    goto v_37375;
v_37376:
    v_38078 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_37377;
v_37378:
    v_38077 = stack[-9];
    goto v_37379;
v_37380:
    goto v_37374;
v_37375:
    goto v_37376;
v_37377:
    goto v_37378;
v_37379:
    stack[-1] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37357;
v_37358:
    goto v_37389;
v_37385:
    goto v_37399;
v_37391:
    v_38080 = elt(env, 6); // cc
    goto v_37392;
v_37393:
    v_38079 = stack[-12];
    goto v_37394;
v_37395:
    v_38078 = stack[-9];
    goto v_37396;
v_37397:
    v_38077 = stack[-6];
    goto v_37398;
v_37399:
    goto v_37391;
v_37392:
    goto v_37393;
v_37394:
    goto v_37395;
v_37396:
    goto v_37397;
v_37398:
    stack[0] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37386;
v_37387:
    goto v_37411;
v_37405:
    v_38079 = elt(env, 2); // bb
    goto v_37406;
v_37407:
    v_38078 = stack[-6];
    goto v_37408;
v_37409:
    v_38077 = stack[-14];
    goto v_37410;
v_37411:
    goto v_37405;
v_37406:
    goto v_37407;
v_37408:
    goto v_37409;
v_37410:
    v_38077 = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37388;
v_37389:
    goto v_37385;
v_37386:
    goto v_37387;
v_37388:
    v_38077 = list2(stack[0], v_38077);
    env = stack[-16];
    goto v_37359;
v_37360:
    goto v_37352;
v_37353:
    goto v_37354;
v_37355:
    goto v_37356;
v_37357:
    goto v_37358;
v_37359:
    v_38077 = list3star(stack[-3], stack[-2], stack[-1], v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38078 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_37345;
v_37346:
    v_38077 = stack[-5];
    goto v_37347;
v_37348:
    goto v_37342;
v_37343:
    goto v_37344;
v_37345:
    goto v_37346;
v_37347:
    v_38077 = list3(stack[-4], v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-5] = v_38077;
    v_38077 = stack[-6];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-6] = v_38077;
    goto v_37323;
v_37322:
    goto v_37314;
v_37315:
    v_38077 = stack[-8];
    goto v_37316;
v_37317:
    goto v_37311;
v_37312:
    goto v_37313;
v_37314:
    goto v_37315;
v_37316:
    v_38077 = list3(stack[-7], v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-8] = v_38077;
    v_38077 = stack[-9];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-9] = v_38077;
    goto v_37292;
v_37291:
    goto v_37283;
v_37284:
    v_38077 = stack[-11];
    goto v_37285;
v_37286:
    goto v_37280;
v_37281:
    goto v_37282;
v_37283:
    goto v_37284;
v_37285:
    v_38077 = list3(stack[-10], v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-11] = v_38077;
    v_38077 = stack[-12];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-12] = v_38077;
    goto v_37261;
v_37260:
    goto v_37241;
v_37242:
    goto v_37238;
v_37239:
    goto v_37240;
v_37241:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[-13], v_38077);
    env = stack[-16];
    goto v_37429;
v_37425:
    goto v_37439;
v_37431:
    v_38080 = elt(env, 5); // l_z
    goto v_37432;
v_37433:
    v_38079 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_37434;
v_37435:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_37436;
v_37437:
    v_38077 = stack[-14];
    goto v_37438;
v_37439:
    goto v_37431;
v_37432:
    goto v_37433;
v_37434:
    goto v_37435;
v_37436:
    goto v_37437;
v_37438:
    stack[-9] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37426;
v_37427:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_38077;
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_38077;
v_37448:
    goto v_37461;
v_37457:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_37458;
v_37459:
    v_38077 = stack[-8];
    goto v_37460;
v_37461:
    goto v_37457;
v_37458:
    goto v_37459;
v_37460:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_37454;
    v_38077 = stack[-7];
    goto v_37447;
v_37454:
    goto v_37473;
v_37467:
    stack[-6] = elt(env, 10); // plus
    goto v_37468;
v_37469:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_38077;
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_38077;
v_37479:
    goto v_37492;
v_37488:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_37489;
v_37490:
    v_38077 = stack[-5];
    goto v_37491;
v_37492:
    goto v_37488;
v_37489:
    goto v_37490;
v_37491:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_37485;
    v_38077 = stack[-4];
    v_38078 = v_38077;
    goto v_37478;
v_37485:
    goto v_37504;
v_37498:
    stack[-3] = elt(env, 10); // plus
    goto v_37499;
v_37500:
    goto v_37516;
v_37508:
    stack[-2] = elt(env, 11); // times
    goto v_37509;
v_37510:
    goto v_37525;
v_37519:
    v_38079 = elt(env, 1); // liemat
    goto v_37520;
v_37521:
    v_38078 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_37522;
v_37523:
    v_38077 = stack[-8];
    goto v_37524;
v_37525:
    goto v_37519;
v_37520:
    goto v_37521;
v_37522:
    goto v_37523;
v_37524:
    stack[-1] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37511;
v_37512:
    goto v_37538;
v_37530:
    v_38080 = elt(env, 6); // cc
    goto v_37531;
v_37532:
    v_38079 = stack[-8];
    goto v_37533;
v_37534:
    v_38078 = stack[-15];
    goto v_37535;
v_37536:
    v_38077 = stack[-5];
    goto v_37537;
v_37538:
    goto v_37530;
v_37531:
    goto v_37532;
v_37533:
    goto v_37534;
v_37535:
    goto v_37536;
v_37537:
    stack[0] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37513;
v_37514:
    goto v_37550;
v_37544:
    v_38079 = elt(env, 2); // bb
    goto v_37545;
v_37546:
    v_38078 = stack[-5];
    goto v_37547;
v_37548:
    v_38077 = stack[-14];
    goto v_37549;
v_37550:
    goto v_37544;
v_37545:
    goto v_37546;
v_37547:
    goto v_37548;
v_37549:
    v_38077 = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37515;
v_37516:
    goto v_37508;
v_37509:
    goto v_37510;
v_37511:
    goto v_37512;
v_37513:
    goto v_37514;
v_37515:
    v_38077 = list4(stack[-2], stack[-1], stack[0], v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38078 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_37501;
v_37502:
    v_38077 = stack[-4];
    goto v_37503;
v_37504:
    goto v_37498;
v_37499:
    goto v_37500;
v_37501:
    goto v_37502;
v_37503:
    v_38077 = list3(stack[-3], v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-4] = v_38077;
    v_38077 = stack[-5];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-5] = v_38077;
    goto v_37479;
v_37478:
    goto v_37470;
v_37471:
    v_38077 = stack[-7];
    goto v_37472;
v_37473:
    goto v_37467;
v_37468:
    goto v_37469;
v_37470:
    goto v_37471;
v_37472:
    v_38077 = list3(stack[-6], v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-7] = v_38077;
    v_38077 = stack[-8];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-8] = v_38077;
    goto v_37448;
v_37447:
    goto v_37428;
v_37429:
    goto v_37425;
v_37426:
    goto v_37427;
v_37428:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[-9], v_38077);
    env = stack[-16];
    goto v_37565;
v_37561:
    goto v_37575;
v_37567:
    v_38080 = elt(env, 5); // l_z
    goto v_37568;
v_37569:
    v_38079 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_37570;
v_37571:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_37572;
v_37573:
    v_38077 = stack[-14];
    goto v_37574;
v_37575:
    goto v_37567;
v_37568:
    goto v_37569;
v_37570:
    goto v_37571;
v_37572:
    goto v_37573;
v_37574:
    stack[-9] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37562;
v_37563:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_38077;
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_38077;
v_37584:
    goto v_37597;
v_37593:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_37594;
v_37595:
    v_38077 = stack[-8];
    goto v_37596;
v_37597:
    goto v_37593;
v_37594:
    goto v_37595;
v_37596:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_37590;
    v_38077 = stack[-7];
    goto v_37583;
v_37590:
    goto v_37609;
v_37603:
    stack[-6] = elt(env, 10); // plus
    goto v_37604;
v_37605:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_38077;
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_38077;
v_37615:
    goto v_37628;
v_37624:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_37625;
v_37626:
    v_38077 = stack[-5];
    goto v_37627;
v_37628:
    goto v_37624;
v_37625:
    goto v_37626;
v_37627:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_37621;
    v_38077 = stack[-4];
    v_38078 = v_38077;
    goto v_37614;
v_37621:
    goto v_37640;
v_37634:
    stack[-3] = elt(env, 10); // plus
    goto v_37635;
v_37636:
    goto v_37652;
v_37644:
    stack[-2] = elt(env, 11); // times
    goto v_37645;
v_37646:
    goto v_37661;
v_37655:
    v_38079 = elt(env, 1); // liemat
    goto v_37656;
v_37657:
    v_38078 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_37658;
v_37659:
    v_38077 = stack[-8];
    goto v_37660;
v_37661:
    goto v_37655;
v_37656:
    goto v_37657;
v_37658:
    goto v_37659;
v_37660:
    stack[-1] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37647;
v_37648:
    goto v_37674;
v_37666:
    v_38080 = elt(env, 6); // cc
    goto v_37667;
v_37668:
    v_38079 = stack[-8];
    goto v_37669;
v_37670:
    v_38078 = stack[-15];
    goto v_37671;
v_37672:
    v_38077 = stack[-5];
    goto v_37673;
v_37674:
    goto v_37666;
v_37667:
    goto v_37668;
v_37669:
    goto v_37670;
v_37671:
    goto v_37672;
v_37673:
    stack[0] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37649;
v_37650:
    goto v_37686;
v_37680:
    v_38079 = elt(env, 2); // bb
    goto v_37681;
v_37682:
    v_38078 = stack[-5];
    goto v_37683;
v_37684:
    v_38077 = stack[-14];
    goto v_37685;
v_37686:
    goto v_37680;
v_37681:
    goto v_37682;
v_37683:
    goto v_37684;
v_37685:
    v_38077 = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37651;
v_37652:
    goto v_37644;
v_37645:
    goto v_37646;
v_37647:
    goto v_37648;
v_37649:
    goto v_37650;
v_37651:
    v_38077 = list4(stack[-2], stack[-1], stack[0], v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38078 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_37637;
v_37638:
    v_38077 = stack[-4];
    goto v_37639;
v_37640:
    goto v_37634;
v_37635:
    goto v_37636;
v_37637:
    goto v_37638;
v_37639:
    v_38077 = list3(stack[-3], v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-4] = v_38077;
    v_38077 = stack[-5];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-5] = v_38077;
    goto v_37615;
v_37614:
    goto v_37606;
v_37607:
    v_38077 = stack[-7];
    goto v_37608;
v_37609:
    goto v_37603;
v_37604:
    goto v_37605;
v_37606:
    goto v_37607;
v_37608:
    v_38077 = list3(stack[-6], v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-7] = v_38077;
    v_38077 = stack[-8];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-8] = v_38077;
    goto v_37584;
v_37583:
    goto v_37564;
v_37565:
    goto v_37561;
v_37562:
    goto v_37563;
v_37564:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[-9], v_38077);
    env = stack[-16];
    goto v_37701;
v_37697:
    goto v_37711;
v_37703:
    v_38080 = elt(env, 5); // l_z
    goto v_37704;
v_37705:
    v_38079 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_37706;
v_37707:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_37708;
v_37709:
    v_38077 = stack[-14];
    goto v_37710;
v_37711:
    goto v_37703;
v_37704:
    goto v_37705;
v_37706:
    goto v_37707;
v_37708:
    goto v_37709;
v_37710:
    stack[-9] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37698;
v_37699:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_38077;
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_38077;
v_37720:
    goto v_37733;
v_37729:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_37730;
v_37731:
    v_38077 = stack[-8];
    goto v_37732;
v_37733:
    goto v_37729;
v_37730:
    goto v_37731;
v_37732:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_37726;
    v_38077 = stack[-7];
    goto v_37719;
v_37726:
    goto v_37745;
v_37739:
    stack[-6] = elt(env, 10); // plus
    goto v_37740;
v_37741:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-5] = v_38077;
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_38077;
v_37751:
    goto v_37764;
v_37760:
    v_38078 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_37761;
v_37762:
    v_38077 = stack[-5];
    goto v_37763;
v_37764:
    goto v_37760;
v_37761:
    goto v_37762;
v_37763:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_37757;
    v_38077 = stack[-4];
    v_38078 = v_38077;
    goto v_37750;
v_37757:
    goto v_37776;
v_37770:
    stack[-3] = elt(env, 10); // plus
    goto v_37771;
v_37772:
    goto v_37788;
v_37780:
    stack[-2] = elt(env, 11); // times
    goto v_37781;
v_37782:
    goto v_37797;
v_37791:
    v_38079 = elt(env, 1); // liemat
    goto v_37792;
v_37793:
    v_38078 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_37794;
v_37795:
    v_38077 = stack[-8];
    goto v_37796;
v_37797:
    goto v_37791;
v_37792:
    goto v_37793;
v_37794:
    goto v_37795;
v_37796:
    stack[-1] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37783;
v_37784:
    goto v_37810;
v_37802:
    v_38080 = elt(env, 6); // cc
    goto v_37803;
v_37804:
    v_38079 = stack[-8];
    goto v_37805;
v_37806:
    v_38078 = stack[-15];
    goto v_37807;
v_37808:
    v_38077 = stack[-5];
    goto v_37809;
v_37810:
    goto v_37802;
v_37803:
    goto v_37804;
v_37805:
    goto v_37806;
v_37807:
    goto v_37808;
v_37809:
    stack[0] = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37785;
v_37786:
    goto v_37822;
v_37816:
    v_38079 = elt(env, 2); // bb
    goto v_37817;
v_37818:
    v_38078 = stack[-5];
    goto v_37819;
v_37820:
    v_38077 = stack[-14];
    goto v_37821;
v_37822:
    goto v_37816;
v_37817:
    goto v_37818;
v_37819:
    goto v_37820;
v_37821:
    v_38077 = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37787;
v_37788:
    goto v_37780;
v_37781:
    goto v_37782;
v_37783:
    goto v_37784;
v_37785:
    goto v_37786;
v_37787:
    v_38077 = list4(stack[-2], stack[-1], stack[0], v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38078 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_37773;
v_37774:
    v_38077 = stack[-4];
    goto v_37775;
v_37776:
    goto v_37770;
v_37771:
    goto v_37772;
v_37773:
    goto v_37774;
v_37775:
    v_38077 = list3(stack[-3], v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-4] = v_38077;
    v_38077 = stack[-5];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-5] = v_38077;
    goto v_37751;
v_37750:
    goto v_37742;
v_37743:
    v_38077 = stack[-7];
    goto v_37744;
v_37745:
    goto v_37739;
v_37740:
    goto v_37741;
v_37742:
    goto v_37743;
v_37744:
    v_38077 = list3(stack[-6], v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-7] = v_38077;
    v_38077 = stack[-8];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-8] = v_38077;
    goto v_37720;
v_37719:
    goto v_37700;
v_37701:
    goto v_37697;
v_37698:
    goto v_37699;
v_37700:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[-9], v_38077);
    env = stack[-16];
    v_38077 = stack[-14];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-14] = v_38077;
    goto v_36847;
v_36846:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_38077;
v_37837:
    goto v_37849;
v_37845:
    v_38078 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_37846;
v_37847:
    v_38077 = stack[-1];
    goto v_37848;
v_37849:
    goto v_37845;
v_37846:
    goto v_37847;
v_37848:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_37842;
    goto v_37836;
v_37842:
    goto v_37858;
v_37854:
    goto v_37866;
v_37860:
    v_38079 = elt(env, 3); // ff
    goto v_37861;
v_37862:
    v_38078 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_37863;
v_37864:
    v_38077 = stack[-1];
    goto v_37865;
v_37866:
    goto v_37860;
v_37861:
    goto v_37862;
v_37863:
    goto v_37864;
v_37865:
    stack[0] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37855;
v_37856:
    goto v_37880;
v_37872:
    v_38080 = elt(env, 5); // l_z
    goto v_37873;
v_37874:
    v_38079 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_37875;
v_37876:
    v_38078 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_37877;
v_37878:
    v_38077 = stack[-1];
    goto v_37879;
v_37880:
    goto v_37872;
v_37873:
    goto v_37874;
v_37875:
    goto v_37876;
v_37877:
    goto v_37878;
v_37879:
    v_38077 = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_37857;
v_37858:
    goto v_37854;
v_37855:
    goto v_37856;
v_37857:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[0], v_38077);
    env = stack[-16];
    goto v_37890;
v_37886:
    goto v_37898;
v_37892:
    v_38079 = elt(env, 3); // ff
    goto v_37893;
v_37894:
    v_38078 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_37895;
v_37896:
    v_38077 = stack[-1];
    goto v_37897;
v_37898:
    goto v_37892;
v_37893:
    goto v_37894;
v_37895:
    goto v_37896;
v_37897:
    stack[0] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37887;
v_37888:
    goto v_37912;
v_37904:
    v_38080 = elt(env, 5); // l_z
    goto v_37905;
v_37906:
    v_38079 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_37907;
v_37908:
    v_38078 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_37909;
v_37910:
    v_38077 = stack[-1];
    goto v_37911;
v_37912:
    goto v_37904;
v_37905:
    goto v_37906;
v_37907:
    goto v_37908;
v_37909:
    goto v_37910;
v_37911:
    v_38077 = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_37889;
v_37890:
    goto v_37886;
v_37887:
    goto v_37888;
v_37889:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[0], v_38077);
    env = stack[-16];
    goto v_37922;
v_37918:
    goto v_37930;
v_37924:
    v_38079 = elt(env, 3); // ff
    goto v_37925;
v_37926:
    v_38078 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_37927;
v_37928:
    v_38077 = stack[-1];
    goto v_37929;
v_37930:
    goto v_37924;
v_37925:
    goto v_37926;
v_37927:
    goto v_37928;
v_37929:
    stack[0] = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    goto v_37919;
v_37920:
    goto v_37944;
v_37936:
    v_38080 = elt(env, 5); // l_z
    goto v_37937;
v_37938:
    v_38079 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_37939;
v_37940:
    v_38078 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_37941;
v_37942:
    v_38077 = stack[-1];
    goto v_37943;
v_37944:
    goto v_37936;
v_37937:
    goto v_37938;
v_37939:
    goto v_37940;
v_37941:
    goto v_37942;
v_37943:
    v_38077 = list4(v_38080, v_38079, v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_37921;
v_37922:
    goto v_37918;
v_37919:
    goto v_37920;
v_37921:
    fn = elt(env, 19); // setk
    v_38077 = (*qfn2(fn))(fn, stack[0], v_38077);
    env = stack[-16];
    v_38077 = stack[-1];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-1] = v_38077;
    goto v_37837;
v_37836:
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    fn = elt(env, 16); // aeval
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-15] = v_38077;
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_38077;
v_37956:
    goto v_37968;
v_37964:
    v_38078 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_37965;
v_37966:
    v_38077 = stack[-1];
    goto v_37967;
v_37968:
    goto v_37964;
v_37965:
    goto v_37966;
v_37967:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_37961;
    goto v_37955;
v_37961:
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_38077;
v_37975:
    goto v_37987;
v_37983:
    v_38078 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_37984;
v_37985:
    v_38077 = stack[0];
    goto v_37986;
v_37987:
    goto v_37983;
v_37984:
    goto v_37985;
v_37986:
    v_38077 = difference2(v_38078, v_38077);
    env = stack[-16];
    v_38077 = Lminusp(nil, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_37980;
    goto v_37974;
v_37980:
    goto v_38000;
v_37996:
    goto v_38009;
v_38003:
    v_38079 = elt(env, 3); // ff
    goto v_38004;
v_38005:
    v_38078 = stack[-1];
    goto v_38006;
v_38007:
    v_38077 = stack[0];
    goto v_38008;
v_38009:
    goto v_38003;
v_38004:
    goto v_38005;
v_38006:
    goto v_38007;
v_38008:
    v_38077 = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 18); // aeval!*
    v_38078 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_37997;
v_37998:
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_37999;
v_38000:
    goto v_37996;
v_37997:
    goto v_37998;
v_37999:
    fn = elt(env, 20); // evalneq
    v_38077 = (*qfn2(fn))(fn, v_38078, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_37994;
    v_38077 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-15] = v_38077;
    v_38077 = (LispObject)48+TAG_FIXNUM; // 3
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[-1] = v_38077;
    v_38077 = (LispObject)48+TAG_FIXNUM; // 3
    fn = elt(env, 18); // aeval!*
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    stack[0] = v_38077;
    goto v_37992;
v_37994:
v_37992:
    v_38077 = stack[0];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[0] = v_38077;
    goto v_37975;
v_37974:
    v_38077 = stack[-1];
    v_38077 = add1(v_38077);
    env = stack[-16];
    stack[-1] = v_38077;
    goto v_37956;
v_37955:
    goto v_38032;
v_38028:
    v_38078 = stack[-15];
    goto v_38029;
v_38030:
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_38031;
v_38032:
    goto v_38028;
v_38029:
    goto v_38030;
v_38031:
    if (v_38078 == v_38077) goto v_38026;
    else goto v_38027;
v_38026:
    v_38077 = elt(env, 12); // comcom0
    v_38077 = ncons(v_38077);
    env = stack[-16];
    fn = elt(env, 16); // aeval
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_38025;
v_38027:
    goto v_38045;
v_38041:
    goto v_38052;
v_38048:
    v_38078 = elt(env, 8); // det
    goto v_38049;
v_38050:
    v_38077 = elt(env, 3); // ff
    goto v_38051;
v_38052:
    goto v_38048;
v_38049:
    goto v_38050;
v_38051:
    v_38077 = list2(v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 16); // aeval
    v_38078 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_38042;
v_38043:
    v_38077 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_38044;
v_38045:
    goto v_38041;
v_38042:
    goto v_38043;
v_38044:
    fn = elt(env, 21); // evalequal
    v_38077 = (*qfn2(fn))(fn, v_38078, v_38077);
    env = stack[-16];
    if (v_38077 == nil) goto v_38039;
    v_38077 = elt(env, 13); // comcom1
    v_38077 = ncons(v_38077);
    env = stack[-16];
    fn = elt(env, 16); // aeval
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_38025;
v_38039:
    v_38077 = elt(env, 14); // comcom3
    v_38077 = ncons(v_38077);
    env = stack[-16];
    fn = elt(env, 16); // aeval
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    goto v_38025;
v_38025:
    goto v_38073;
v_38067:
    v_38079 = elt(env, 2); // bb
    goto v_38068;
v_38069:
    v_38078 = elt(env, 3); // ff
    goto v_38070;
v_38071:
    v_38077 = elt(env, 5); // l_z
    goto v_38072;
v_38073:
    goto v_38067;
v_38068:
    goto v_38069;
v_38070:
    goto v_38071;
v_38072:
    v_38077 = list3(v_38079, v_38078, v_38077);
    env = stack[-16];
    fn = elt(env, 22); // clear
    v_38077 = (*qfn1(fn))(fn, v_38077);
    env = stack[-16];
    fn = elt(env, 16); // aeval
    v_38077 = (*qfn1(fn))(fn, v_38077);
    v_38077 = nil;
    return onevalue(v_38077);
}



// Code for partsym_zerop

static LispObject CC_partsym_zerop(LispObject env,
                         LispObject v_36171, LispObject v_36172)
{
    env = qenv(env);
    LispObject v_36219, v_36220, v_36221;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_36172,v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_36171,v_36172);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_36172;
    stack[-1] = v_36171;
// end of prologue
v_36170:
    v_36219 = stack[-1];
    if (v_36219 == nil) goto v_36176;
    else goto v_36177;
v_36176:
    v_36219 = nil;
    goto v_36175;
v_36177:
    v_36219 = stack[-1];
    v_36219 = qcar(v_36219);
    fn = elt(env, 2); // repeats
    v_36219 = (*qfn1(fn))(fn, v_36219);
    env = stack[-2];
    v_36221 = v_36219;
    goto v_36198;
v_36194:
    v_36219 = stack[0];
    v_36220 = qcar(v_36219);
    goto v_36195;
v_36196:
    v_36219 = elt(env, 1); // !-
    goto v_36197;
v_36198:
    goto v_36194;
v_36195:
    goto v_36196;
v_36197:
    if (v_36220 == v_36219) goto v_36192;
    else goto v_36193;
v_36192:
    v_36219 = v_36221;
    goto v_36191;
v_36193:
    v_36219 = nil;
    goto v_36191;
    v_36219 = nil;
v_36191:
    if (v_36219 == nil) goto v_36189;
    v_36219 = v_36221;
    goto v_36187;
v_36189:
    goto v_36214;
v_36210:
    v_36219 = stack[-1];
    v_36220 = qcdr(v_36219);
    goto v_36211;
v_36212:
    v_36219 = stack[0];
    v_36219 = qcdr(v_36219);
    goto v_36213;
v_36214:
    goto v_36210;
v_36211:
    goto v_36212;
v_36213:
    stack[-1] = v_36220;
    stack[0] = v_36219;
    goto v_36170;
    v_36219 = nil;
v_36187:
    goto v_36175;
    v_36219 = nil;
v_36175:
    return onevalue(v_36219);
}



// Code for sc_repkern

static LispObject CC_sc_repkern(LispObject env,
                         LispObject v_36171, LispObject v_36172)
{
    env = qenv(env);
    LispObject v_36474, v_36475, v_36476;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_36172,v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_36171,v_36172);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_36172;
    v_36475 = v_36171;
// end of prologue
    goto v_36182;
v_36178:
    v_36474 = v_36475;
    v_36476 = qcar(v_36474);
    goto v_36179;
v_36180:
    v_36474 = elt(env, 1); // !*
    goto v_36181;
v_36182:
    goto v_36178;
v_36179:
    goto v_36180;
v_36181:
    if (v_36476 == v_36474) goto v_36176;
    else goto v_36177;
v_36176:
    stack[-6] = nil;
    v_36474 = v_36475;
    v_36474 = qcdr(v_36474);
    stack[0] = v_36474;
    v_36474 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_36474;
v_36200:
    v_36474 = stack[0];
    if (v_36474 == nil) goto v_36203;
    else goto v_36204;
v_36203:
    goto v_36199;
v_36204:
    v_36474 = stack[0];
    v_36474 = qcar(v_36474);
    stack[-3] = v_36474;
    goto v_36214;
v_36210:
    v_36474 = stack[-3];
    v_36475 = ncons(v_36474);
    env = stack[-7];
    goto v_36211;
v_36212:
    v_36474 = stack[-6];
    goto v_36213;
v_36214:
    goto v_36210;
v_36211:
    goto v_36212;
v_36213:
    v_36474 = cons(v_36475, v_36474);
    env = stack[-7];
    stack[-6] = v_36474;
    v_36474 = stack[0];
    v_36474 = qcdr(v_36474);
    stack[0] = v_36474;
    v_36474 = nil;
    stack[-4] = v_36474;
    goto v_36227;
v_36223:
    v_36475 = stack[-2];
    goto v_36224;
v_36225:
    v_36474 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_36226;
v_36227:
    goto v_36223;
v_36224:
    goto v_36225;
v_36226:
    v_36474 = times2(v_36475, v_36474);
    env = stack[-7];
    v_36474 = add1(v_36474);
    env = stack[-7];
    stack[-2] = v_36474;
    v_36474 = stack[0];
    stack[-1] = v_36474;
v_36233:
    v_36474 = stack[-1];
    if (v_36474 == nil) goto v_36237;
    else goto v_36238;
v_36237:
    goto v_36232;
v_36238:
    v_36474 = stack[-1];
    v_36474 = qcar(v_36474);
    stack[0] = v_36474;
    goto v_36252;
v_36248:
    v_36475 = stack[0];
    goto v_36249;
v_36250:
    v_36474 = stack[-3];
    goto v_36251;
v_36252:
    goto v_36248;
v_36249:
    goto v_36250;
v_36251:
    if (v_36475 == v_36474) goto v_36246;
    else goto v_36247;
v_36246:
    goto v_36261;
v_36257:
    v_36475 = stack[-2];
    goto v_36258;
v_36259:
    v_36474 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_36260;
v_36261:
    goto v_36257;
v_36258:
    goto v_36259;
v_36260:
    v_36474 = times2(v_36475, v_36474);
    env = stack[-7];
    v_36474 = add1(v_36474);
    env = stack[-7];
    stack[-2] = v_36474;
    goto v_36245;
v_36247:
    goto v_36271;
v_36267:
    v_36475 = stack[-2];
    goto v_36268;
v_36269:
    v_36474 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_36270;
v_36271:
    goto v_36267;
v_36268:
    goto v_36269;
v_36270:
    v_36474 = times2(v_36475, v_36474);
    env = stack[-7];
    stack[-2] = v_36474;
    goto v_36279;
v_36275:
    v_36475 = stack[0];
    goto v_36276;
v_36277:
    v_36474 = stack[-4];
    goto v_36278;
v_36279:
    goto v_36275;
v_36276:
    goto v_36277;
v_36278:
    v_36474 = cons(v_36475, v_36474);
    env = stack[-7];
    stack[-4] = v_36474;
    goto v_36245;
v_36245:
    v_36474 = stack[-1];
    v_36474 = qcdr(v_36474);
    stack[-1] = v_36474;
    goto v_36233;
v_36232:
    v_36474 = stack[-4];
    v_36474 = Lreverse(nil, v_36474);
    env = stack[-7];
    stack[0] = v_36474;
    goto v_36200;
v_36199:
    goto v_36292;
v_36288:
    stack[0] = stack[-2];
    goto v_36289;
v_36290:
    goto v_36299;
v_36295:
    v_36474 = stack[-6];
    v_36475 = Lreverse(nil, v_36474);
    env = stack[-7];
    goto v_36296;
v_36297:
    v_36474 = stack[-5];
    goto v_36298;
v_36299:
    goto v_36295;
v_36296:
    goto v_36297;
v_36298:
    fn = elt(env, 3); // pa_list2vect
    v_36474 = (*qfn2(fn))(fn, v_36475, v_36474);
    goto v_36291;
v_36292:
    goto v_36288;
v_36289:
    goto v_36290;
v_36291:
    {
        LispObject v_36484 = stack[0];
        return list2(v_36484, v_36474);
    }
    goto v_36175;
v_36177:
    stack[-1] = nil;
    stack[-6] = nil;
    stack[-4] = nil;
    v_36474 = v_36475;
    v_36474 = qcdr(v_36474);
    v_36475 = v_36474;
    v_36474 = v_36475;
    stack[-2] = v_36474;
v_36318:
    v_36474 = stack[-2];
    if (v_36474 == nil) goto v_36322;
    else goto v_36323;
v_36322:
    goto v_36317;
v_36323:
    v_36474 = stack[-2];
    v_36474 = qcar(v_36474);
    v_36475 = v_36474;
    goto v_36337;
v_36333:
    v_36476 = v_36475;
    goto v_36334;
v_36335:
    v_36474 = stack[-1];
    goto v_36336;
v_36337:
    goto v_36333;
v_36334:
    goto v_36335;
v_36336:
    v_36474 = Lassoc(nil, v_36476, v_36474);
    v_36476 = v_36474;
    if (v_36474 == nil) goto v_36332;
    goto v_36346;
v_36342:
    stack[0] = v_36476;
    goto v_36343;
v_36344:
    v_36474 = v_36476;
    v_36474 = qcdr(v_36474);
    v_36474 = add1(v_36474);
    env = stack[-7];
    goto v_36345;
v_36346:
    goto v_36342;
v_36343:
    goto v_36344;
v_36345:
    v_36474 = Lrplacd(nil, stack[0], v_36474);
    env = stack[-7];
    goto v_36330;
v_36332:
    goto v_36360;
v_36354:
    v_36476 = v_36475;
    goto v_36355;
v_36356:
    v_36475 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36357;
v_36358:
    v_36474 = stack[-1];
    goto v_36359;
v_36360:
    goto v_36354;
v_36355:
    goto v_36356;
v_36357:
    goto v_36358;
v_36359:
    v_36474 = acons(v_36476, v_36475, v_36474);
    env = stack[-7];
    stack[-1] = v_36474;
    goto v_36330;
v_36330:
    v_36474 = stack[-2];
    v_36474 = qcdr(v_36474);
    stack[-2] = v_36474;
    goto v_36318;
v_36317:
    goto v_36371;
v_36367:
    v_36475 = stack[-1];
    goto v_36368;
v_36369:
    v_36474 = elt(env, 2); // lambda_1x539vlzlwg93
    goto v_36370;
v_36371:
    goto v_36367;
v_36368:
    goto v_36369;
v_36370:
    fn = elt(env, 4); // sort
    v_36474 = (*qfn2(fn))(fn, v_36475, v_36474);
    env = stack[-7];
    stack[-1] = v_36474;
    v_36474 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_36474;
    v_36474 = stack[-1];
    stack[-2] = v_36474;
v_36378:
    v_36474 = stack[-2];
    if (v_36474 == nil) goto v_36382;
    else goto v_36383;
v_36382:
    goto v_36377;
v_36383:
    v_36474 = stack[-2];
    v_36474 = qcar(v_36474);
    stack[-1] = v_36474;
    goto v_36397;
v_36393:
    v_36474 = stack[-1];
    v_36475 = qcdr(v_36474);
    goto v_36394;
v_36395:
    v_36474 = stack[-3];
    goto v_36396;
v_36397:
    goto v_36393;
v_36394:
    goto v_36395;
v_36396:
    if (equal(v_36475, v_36474)) goto v_36392;
    goto v_36408;
v_36402:
    v_36474 = stack[-1];
    v_36476 = qcdr(v_36474);
    goto v_36403;
v_36404:
    v_36475 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36405;
v_36406:
    v_36474 = stack[-6];
    goto v_36407;
v_36408:
    goto v_36402;
v_36403:
    goto v_36404;
v_36405:
    goto v_36406;
v_36407:
    v_36474 = acons(v_36476, v_36475, v_36474);
    env = stack[-7];
    stack[-6] = v_36474;
    goto v_36418;
v_36414:
    v_36474 = stack[-1];
    v_36474 = qcar(v_36474);
    v_36475 = ncons(v_36474);
    env = stack[-7];
    goto v_36415;
v_36416:
    v_36474 = stack[-4];
    goto v_36417;
v_36418:
    goto v_36414;
v_36415:
    goto v_36416;
v_36417:
    v_36474 = cons(v_36475, v_36474);
    env = stack[-7];
    stack[-4] = v_36474;
    v_36474 = stack[-1];
    v_36474 = qcdr(v_36474);
    stack[-3] = v_36474;
    goto v_36390;
v_36392:
    goto v_36433;
v_36429:
    v_36474 = stack[-6];
    stack[0] = qcar(v_36474);
    goto v_36430;
v_36431:
    v_36474 = stack[-6];
    v_36474 = qcar(v_36474);
    v_36474 = qcdr(v_36474);
    v_36474 = add1(v_36474);
    env = stack[-7];
    goto v_36432;
v_36433:
    goto v_36429;
v_36430:
    goto v_36431;
v_36432:
    v_36474 = Lrplacd(nil, stack[0], v_36474);
    env = stack[-7];
    goto v_36445;
v_36441:
    stack[0] = stack[-4];
    goto v_36442;
v_36443:
    goto v_36452;
v_36448:
    v_36474 = stack[-1];
    v_36475 = qcar(v_36474);
    goto v_36449;
v_36450:
    v_36474 = stack[-4];
    v_36474 = qcar(v_36474);
    goto v_36451;
v_36452:
    goto v_36448;
v_36449:
    goto v_36450;
v_36451:
    v_36474 = cons(v_36475, v_36474);
    env = stack[-7];
    goto v_36444;
v_36445:
    goto v_36441;
v_36442:
    goto v_36443;
v_36444:
    v_36474 = Lrplaca(nil, stack[0], v_36474);
    env = stack[-7];
    goto v_36390;
v_36390:
    v_36474 = stack[-2];
    v_36474 = qcdr(v_36474);
    stack[-2] = v_36474;
    goto v_36378;
v_36377:
    goto v_36464;
v_36460:
    stack[0] = stack[-6];
    goto v_36461;
v_36462:
    goto v_36471;
v_36467:
    v_36475 = stack[-4];
    goto v_36468;
v_36469:
    v_36474 = stack[-5];
    goto v_36470;
v_36471:
    goto v_36467;
v_36468:
    goto v_36469;
v_36470:
    fn = elt(env, 3); // pa_list2vect
    v_36474 = (*qfn2(fn))(fn, v_36475, v_36474);
    goto v_36463;
v_36464:
    goto v_36460;
v_36461:
    goto v_36462;
v_36463:
    {
        LispObject v_36485 = stack[0];
        return list2(v_36485, v_36474);
    }
    goto v_36175;
    v_36474 = nil;
v_36175:
    return onevalue(v_36474);
}



// Code for lambda_1x539vlzlwg93

static LispObject CC_lambda_1x539vlzlwg93(LispObject env,
                         LispObject v_36171, LispObject v_36172)
{
    env = qenv(env);
    LispObject v_36184, v_36185;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_36184 = v_36172;
    v_36185 = v_36171;
// end of prologue
    goto v_36179;
v_36175:
    v_36185 = qcdr(v_36185);
    goto v_36176;
v_36177:
    v_36184 = qcdr(v_36184);
    goto v_36178;
v_36179:
    goto v_36175;
v_36176:
    goto v_36177;
v_36178:
        return Lleq(nil, v_36185, v_36184);
}



// Code for super_product_sq

static LispObject CC_super_product_sq(LispObject env,
                         LispObject v_36171, LispObject v_36172)
{
    env = qenv(env);
    LispObject v_36269, v_36270;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_36172,v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_36171,v_36172);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-1] = v_36172;
    v_36269 = v_36171;
// end of prologue
    goto v_36184;
v_36180:
    v_36270 = v_36269;
    goto v_36181;
v_36182:
    v_36269 = elt(env, 1); // (ext)
    goto v_36183;
v_36184:
    goto v_36180;
v_36181:
    goto v_36182;
v_36183:
    fn = elt(env, 2); // split_ext
    v_36269 = (*qfn2(fn))(fn, v_36270, v_36269);
    env = stack[-7];
    stack[0] = v_36269;
    goto v_36192;
v_36188:
    v_36270 = stack[-1];
    goto v_36189;
v_36190:
    v_36269 = elt(env, 1); // (ext)
    goto v_36191;
v_36192:
    goto v_36188;
v_36189:
    goto v_36190;
v_36191:
    fn = elt(env, 2); // split_ext
    v_36269 = (*qfn2(fn))(fn, v_36270, v_36269);
    env = stack[-7];
    stack[-6] = v_36269;
    goto v_36200;
v_36196:
    v_36270 = nil;
    goto v_36197;
v_36198:
    v_36269 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36199;
v_36200:
    goto v_36196;
v_36197:
    goto v_36198;
v_36199:
    v_36269 = cons(v_36270, v_36269);
    env = stack[-7];
    v_36270 = v_36269;
    v_36269 = stack[0];
    stack[-5] = v_36269;
v_36206:
    v_36269 = stack[-5];
    if (v_36269 == nil) goto v_36210;
    else goto v_36211;
v_36210:
    goto v_36205;
v_36211:
    v_36269 = stack[-5];
    v_36269 = qcar(v_36269);
    stack[-4] = v_36269;
    v_36269 = stack[-6];
    stack[-3] = v_36269;
v_36220:
    v_36269 = stack[-3];
    if (v_36269 == nil) goto v_36224;
    else goto v_36225;
v_36224:
    goto v_36219;
v_36225:
    v_36269 = stack[-3];
    v_36269 = qcar(v_36269);
    stack[-2] = v_36269;
    goto v_36236;
v_36232:
    stack[-1] = v_36270;
    goto v_36233;
v_36234:
    goto v_36243;
v_36239:
    goto v_36249;
v_36245:
    v_36269 = stack[-4];
    v_36270 = qcdr(v_36269);
    goto v_36246;
v_36247:
    v_36269 = stack[-2];
    v_36269 = qcdr(v_36269);
    goto v_36248;
v_36249:
    goto v_36245;
v_36246:
    goto v_36247;
v_36248:
    fn = elt(env, 3); // multsq
    stack[0] = (*qfn2(fn))(fn, v_36270, v_36269);
    env = stack[-7];
    goto v_36240;
v_36241:
    goto v_36259;
v_36255:
    v_36269 = stack[-4];
    v_36270 = qcar(v_36269);
    goto v_36256;
v_36257:
    v_36269 = stack[-2];
    v_36269 = qcar(v_36269);
    goto v_36258;
v_36259:
    goto v_36255;
v_36256:
    goto v_36257;
v_36258:
    fn = elt(env, 4); // ext_mult
    v_36269 = (*qfn2(fn))(fn, v_36270, v_36269);
    env = stack[-7];
    goto v_36242;
v_36243:
    goto v_36239;
v_36240:
    goto v_36241;
v_36242:
    fn = elt(env, 3); // multsq
    v_36269 = (*qfn2(fn))(fn, stack[0], v_36269);
    env = stack[-7];
    goto v_36235;
v_36236:
    goto v_36232;
v_36233:
    goto v_36234;
v_36235:
    fn = elt(env, 5); // addsq
    v_36269 = (*qfn2(fn))(fn, stack[-1], v_36269);
    env = stack[-7];
    v_36270 = v_36269;
    v_36269 = stack[-3];
    v_36269 = qcdr(v_36269);
    stack[-3] = v_36269;
    goto v_36220;
v_36219:
    v_36269 = stack[-5];
    v_36269 = qcdr(v_36269);
    stack[-5] = v_36269;
    goto v_36206;
v_36205:
    v_36269 = v_36270;
    return onevalue(v_36269);
}



// Code for sfto_mindeg1

static LispObject CC_sfto_mindeg1(LispObject env,
                         LispObject v_36171, LispObject v_36172)
{
    env = qenv(env);
    LispObject v_36223, v_36224;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_36172,v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_36171,v_36172);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_36172;
    stack[-1] = v_36171;
// end of prologue
v_36176:
    v_36223 = stack[-1];
    if (!consp(v_36223)) goto v_36187;
    else goto v_36188;
v_36187:
    v_36223 = lisp_true;
    goto v_36186;
v_36188:
    v_36223 = stack[-1];
    v_36223 = qcar(v_36223);
    v_36223 = (consp(v_36223) ? nil : lisp_true);
    goto v_36186;
    v_36223 = nil;
v_36186:
    if (v_36223 == nil) goto v_36184;
    v_36223 = lisp_true;
    goto v_36182;
v_36184:
    goto v_36204;
v_36200:
    v_36223 = stack[-1];
    v_36223 = qcar(v_36223);
    v_36223 = qcar(v_36223);
    v_36224 = qcar(v_36223);
    goto v_36201;
v_36202:
    v_36223 = stack[0];
    goto v_36203;
v_36204:
    goto v_36200;
v_36201:
    goto v_36202;
v_36203:
    v_36223 = Lneq(nil, v_36224, v_36223);
    env = stack[-2];
    goto v_36182;
    v_36223 = nil;
v_36182:
    if (v_36223 == nil) goto v_36180;
    v_36223 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_36175;
v_36180:
    v_36223 = stack[-1];
    v_36223 = qcdr(v_36223);
    if (v_36223 == nil) goto v_36212;
    v_36223 = stack[-1];
    v_36223 = qcdr(v_36223);
    stack[-1] = v_36223;
    goto v_36176;
v_36212:
    v_36223 = stack[-1];
    v_36223 = qcar(v_36223);
    v_36223 = qcar(v_36223);
    v_36223 = qcdr(v_36223);
    goto v_36175;
    v_36223 = nil;
v_36175:
    return onevalue(v_36223);
}



// Code for rat_min

static LispObject CC_rat_min(LispObject env,
                         LispObject v_36171, LispObject v_36172)
{
    env = qenv(env);
    LispObject v_36190, v_36191;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_36172,v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_36171,v_36172);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_36172;
    stack[-1] = v_36171;
// end of prologue
    goto v_36183;
v_36179:
    v_36191 = stack[-1];
    goto v_36180;
v_36181:
    v_36190 = stack[0];
    goto v_36182;
v_36183:
    goto v_36179;
v_36180:
    goto v_36181;
v_36182:
    fn = elt(env, 1); // rat_leq
    v_36190 = (*qfn2(fn))(fn, v_36191, v_36190);
    if (v_36190 == nil) goto v_36177;
    v_36190 = stack[-1];
    goto v_36175;
v_36177:
    v_36190 = stack[0];
    goto v_36175;
    v_36190 = nil;
v_36175:
    return onevalue(v_36190);
}



// Code for setqdeletedescendants

static LispObject CC_setqdeletedescendants(LispObject env,
                         LispObject v_36171)
{
    env = qenv(env);
    LispObject v_36232, v_36233;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_36171);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_36171;
// end of prologue
    v_36232 = qvalue(elt(env, 1)); // fluidbibasissetq
    stack[-1] = v_36232;
v_36179:
    v_36232 = stack[-1];
    v_36232 = qcar(v_36232);
    if (v_36232 == nil) goto v_36182;
    else goto v_36183;
v_36182:
    goto v_36178;
v_36183:
    goto v_36195;
v_36191:
    goto v_36200;
v_36196:
    v_36232 = stack[-1];
    v_36233 = qcar(v_36232);
    goto v_36197;
v_36198:
    v_36232 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_36199;
v_36200:
    goto v_36196;
v_36197:
    goto v_36198;
v_36199:
    v_36233 = *(LispObject *)((char *)v_36233 + (CELL-TAG_VECTOR) + (((intptr_t)v_36232-TAG_FIXNUM)/(16/CELL)));
    goto v_36192;
v_36193:
    v_36232 = stack[0];
    goto v_36194;
v_36195:
    goto v_36191;
v_36192:
    goto v_36193;
v_36194:
    if (equal(v_36233, v_36232)) goto v_36189;
    else goto v_36190;
v_36189:
    goto v_36211;
v_36207:
    goto v_36217;
v_36213:
    v_36233 = stack[-1];
    goto v_36214;
v_36215:
    v_36232 = stack[-1];
    v_36232 = qcdr(v_36232);
    v_36232 = qcar(v_36232);
    goto v_36216;
v_36217:
    goto v_36213;
v_36214:
    goto v_36215;
v_36216:
    v_36233 = Lrplaca(nil, v_36233, v_36232);
    env = stack[-2];
    goto v_36208;
v_36209:
    v_36232 = stack[-1];
    v_36232 = qcdr(v_36232);
    v_36232 = qcdr(v_36232);
    goto v_36210;
v_36211:
    goto v_36207;
v_36208:
    goto v_36209;
v_36210:
    v_36232 = Lrplacd(nil, v_36233, v_36232);
    env = stack[-2];
    goto v_36188;
v_36190:
    v_36232 = stack[-1];
    v_36232 = qcdr(v_36232);
    stack[-1] = v_36232;
    goto v_36188;
v_36188:
    goto v_36179;
v_36178:
    v_36232 = nil;
    return onevalue(v_36232);
}



// Code for interglue

static LispObject CC_interglue(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_36539, v_36540;
    LispObject v_36174, v_36173, v_36172, v_36171;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "interglue");
    va_start(aa, nargs);
    v_36171 = va_arg(aa, LispObject);
    v_36172 = va_arg(aa, LispObject);
    v_36173 = va_arg(aa, LispObject);
    v_36174 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_36174,v_36173,v_36172,v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_36171,v_36172,v_36173,v_36174);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_36174;
    stack[-2] = v_36173;
    stack[-3] = v_36172;
    stack[-4] = v_36171;
// end of prologue
    v_36539 = stack[-4];
    if (v_36539 == nil) goto v_36182;
    else goto v_36183;
v_36182:
    v_36539 = lisp_true;
    goto v_36181;
v_36183:
    v_36539 = stack[-3];
    if (v_36539 == nil) goto v_36190;
    else goto v_36191;
v_36190:
    v_36539 = lisp_true;
    goto v_36189;
v_36191:
    v_36539 = stack[-4];
    if (!consp(v_36539)) goto v_36199;
    v_36539 = lisp_true;
    goto v_36197;
v_36199:
    v_36539 = stack[-3];
    v_36539 = (consp(v_36539) ? nil : lisp_true);
    v_36539 = (v_36539 == nil ? lisp_true : nil);
    goto v_36197;
    v_36539 = nil;
v_36197:
    goto v_36189;
    v_36539 = nil;
v_36189:
    goto v_36181;
    v_36539 = nil;
v_36181:
    if (v_36539 == nil) goto v_36179;
    v_36539 = nil;
    goto v_36177;
v_36179:
    v_36539 = stack[-4];
    if (!symbolp(v_36539)) v_36539 = nil;
    else { v_36539 = qfastgets(v_36539);
           if (v_36539 != nil) { v_36539 = elt(v_36539, 7); // class
#ifdef RECORD_GET
             if (v_36539 != SPID_NOPROP)
                record_get(elt(fastget_names, 7), 1);
             else record_get(elt(fastget_names, 7), 0),
                v_36539 = nil; }
           else record_get(elt(fastget_names, 7), 0); }
#else
             if (v_36539 == SPID_NOPROP) v_36539 = nil; }}
#endif
    stack[0] = v_36539;
    v_36539 = stack[-3];
    if (!symbolp(v_36539)) v_36539 = nil;
    else { v_36539 = qfastgets(v_36539);
           if (v_36539 != nil) { v_36539 = elt(v_36539, 7); // class
#ifdef RECORD_GET
             if (v_36539 != SPID_NOPROP)
                record_get(elt(fastget_names, 7), 1);
             else record_get(elt(fastget_names, 7), 0),
                v_36539 = nil; }
           else record_get(elt(fastget_names, 7), 0); }
#else
             if (v_36539 == SPID_NOPROP) v_36539 = nil; }}
#endif
    goto v_36224;
v_36220:
    v_36540 = stack[0];
    goto v_36221;
v_36222:
    goto v_36223;
v_36224:
    goto v_36220;
v_36221:
    goto v_36222;
v_36223:
    v_36539 = get(v_36540, v_36539);
    env = stack[-6];
    stack[-5] = v_36539;
    v_36539 = stack[-5];
    if (v_36539 == nil) goto v_36229;
    else goto v_36230;
v_36229:
    v_36539 = nil;
    goto v_36214;
v_36230:
    goto v_36241;
v_36237:
    v_36540 = stack[-4];
    goto v_36238;
v_36239:
    v_36539 = elt(env, 1); // !\co! 
    goto v_36240;
v_36241:
    goto v_36237;
v_36238:
    goto v_36239;
v_36240:
    if (v_36540 == v_36539) goto v_36235;
    else goto v_36236;
v_36235:
    goto v_36249;
v_36245:
    v_36540 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_36246;
v_36247:
    v_36539 = (LispObject)-160000+TAG_FIXNUM; // -10000
    goto v_36248;
v_36249:
    goto v_36245;
v_36246:
    goto v_36247;
v_36248:
    return list2(v_36540, v_36539);
v_36236:
    goto v_36261;
v_36257:
    v_36540 = stack[-5];
    goto v_36258;
v_36259:
    v_36539 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_36260;
v_36261:
    goto v_36257;
v_36258:
    goto v_36259;
v_36260:
    v_36539 = (LispObject)lessp2(v_36540, v_36539);
    v_36539 = v_36539 ? lisp_true : nil;
    env = stack[-6];
    if (v_36539 == nil) goto v_36255;
    goto v_36273;
v_36269:
    v_36540 = stack[-2];
    goto v_36270;
v_36271:
    v_36539 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_36272;
v_36273:
    goto v_36269;
v_36270:
    goto v_36271;
v_36272:
    v_36539 = (LispObject)greaterp2(v_36540, v_36539);
    v_36539 = v_36539 ? lisp_true : nil;
    env = stack[-6];
    if (v_36539 == nil) goto v_36267;
    v_36539 = nil;
    goto v_36214;
v_36267:
    v_36539 = stack[-5];
    v_36539 = negate(v_36539);
    env = stack[-6];
    stack[-5] = v_36539;
    goto v_36265;
v_36265:
    goto v_36253;
v_36255:
v_36253:
    goto v_36289;
v_36285:
    v_36540 = stack[-5];
    goto v_36286;
v_36287:
    v_36539 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36288;
v_36289:
    goto v_36285;
v_36286:
    goto v_36287;
v_36288:
    if (v_36540 == v_36539) goto v_36283;
    else goto v_36284;
v_36283:
    goto v_36297;
v_36293:
    stack[0] = (LispObject)1295360+TAG_FIXNUM; // 80960
    goto v_36294;
v_36295:
    goto v_36304;
v_36300:
    goto v_36310;
v_36306:
    v_36540 = stack[-1];
    goto v_36307;
v_36308:
    v_36539 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_36309;
v_36310:
    goto v_36306;
v_36307:
    goto v_36308;
v_36309:
    v_36540 = times2(v_36540, v_36539);
    env = stack[-6];
    goto v_36301;
v_36302:
    v_36539 = (LispObject)320+TAG_FIXNUM; // 20
    goto v_36303;
v_36304:
    goto v_36300;
v_36301:
    goto v_36302;
v_36303:
    v_36539 = plus2(v_36540, v_36539);
    goto v_36296;
v_36297:
    goto v_36293;
v_36294:
    goto v_36295;
v_36296:
    {
        LispObject v_36547 = stack[0];
        return list2(v_36547, v_36539);
    }
v_36284:
    goto v_36320;
v_36316:
    v_36540 = stack[-5];
    goto v_36317;
v_36318:
    v_36539 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_36319;
v_36320:
    goto v_36316;
v_36317:
    goto v_36318;
v_36319:
    if (v_36540 == v_36539) goto v_36314;
    else goto v_36315;
v_36314:
    goto v_36335;
v_36331:
    v_36540 = stack[-4];
    goto v_36332;
v_36333:
    v_36539 = elt(env, 2); // !+
    goto v_36334;
v_36335:
    goto v_36331;
v_36332:
    goto v_36333;
v_36334:
    if (v_36540 == v_36539) goto v_36329;
    else goto v_36330;
v_36329:
    v_36539 = lisp_true;
    goto v_36328;
v_36330:
    goto v_36345;
v_36341:
    v_36540 = stack[-4];
    goto v_36342;
v_36343:
    v_36539 = elt(env, 3); // !-
    goto v_36344;
v_36345:
    goto v_36341;
v_36342:
    goto v_36343;
v_36344:
    v_36539 = (v_36540 == v_36539 ? lisp_true : nil);
    goto v_36328;
    v_36539 = nil;
v_36328:
    if (v_36539 == nil) goto v_36326;
    v_36539 = nil;
    goto v_36214;
v_36326:
    goto v_36358;
v_36354:
    v_36540 = stack[-3];
    goto v_36355;
v_36356:
    v_36539 = elt(env, 2); // !+
    goto v_36357;
v_36358:
    goto v_36354;
v_36355:
    goto v_36356;
v_36357:
    if (v_36540 == v_36539) goto v_36352;
    else goto v_36353;
v_36352:
    goto v_36366;
v_36362:
    stack[0] = (LispObject)2621440+TAG_FIXNUM; // 163840
    goto v_36363;
v_36364:
    goto v_36373;
v_36369:
    goto v_36379;
v_36375:
    v_36540 = stack[-1];
    goto v_36376;
v_36377:
    v_36539 = (LispObject)480+TAG_FIXNUM; // 30
    goto v_36378;
v_36379:
    goto v_36375;
v_36376:
    goto v_36377;
v_36378:
    v_36540 = times2(v_36540, v_36539);
    env = stack[-6];
    goto v_36370;
v_36371:
    v_36539 = (LispObject)6240+TAG_FIXNUM; // 390
    goto v_36372;
v_36373:
    goto v_36369;
v_36370:
    goto v_36371;
v_36372:
    v_36539 = difference2(v_36540, v_36539);
    goto v_36365;
v_36366:
    goto v_36362;
v_36363:
    goto v_36364;
v_36365:
    {
        LispObject v_36548 = stack[0];
        return list2(v_36548, v_36539);
    }
v_36353:
    goto v_36395;
v_36391:
    v_36540 = stack[-3];
    goto v_36392;
v_36393:
    v_36539 = elt(env, 3); // !-
    goto v_36394;
v_36395:
    goto v_36391;
v_36392:
    goto v_36393;
v_36394:
    if (v_36540 == v_36539) goto v_36389;
    else goto v_36390;
v_36389:
    goto v_36406;
v_36402:
    v_36540 = stack[0];
    goto v_36403;
v_36404:
    v_36539 = elt(env, 4); // ord
    goto v_36405;
v_36406:
    goto v_36402;
v_36403:
    goto v_36404;
v_36405:
    if (v_36540 == v_36539) goto v_36400;
    else goto v_36401;
v_36400:
    v_36539 = lisp_true;
    goto v_36399;
v_36401:
    goto v_36416;
v_36412:
    v_36540 = stack[0];
    goto v_36413;
v_36414:
    v_36539 = elt(env, 5); // clo
    goto v_36415;
v_36416:
    goto v_36412;
v_36413:
    goto v_36414;
v_36415:
    v_36539 = (v_36540 == v_36539 ? lisp_true : nil);
    goto v_36399;
    v_36539 = nil;
v_36399:
    goto v_36388;
v_36390:
    v_36539 = nil;
    goto v_36388;
    v_36539 = nil;
v_36388:
    if (v_36539 == nil) goto v_36386;
    goto v_36428;
v_36424:
    stack[0] = (LispObject)2621440+TAG_FIXNUM; // 163840
    goto v_36425;
v_36426:
    goto v_36435;
v_36431:
    goto v_36441;
v_36437:
    v_36540 = stack[-1];
    goto v_36438;
v_36439:
    v_36539 = (LispObject)480+TAG_FIXNUM; // 30
    goto v_36440;
v_36441:
    goto v_36437;
v_36438:
    goto v_36439;
v_36440:
    v_36540 = times2(v_36540, v_36539);
    env = stack[-6];
    goto v_36432;
v_36433:
    v_36539 = (LispObject)3360+TAG_FIXNUM; // 210
    goto v_36434;
v_36435:
    goto v_36431;
v_36432:
    goto v_36433;
v_36434:
    v_36539 = difference2(v_36540, v_36539);
    goto v_36427;
v_36428:
    goto v_36424;
v_36425:
    goto v_36426;
v_36427:
    {
        LispObject v_36549 = stack[0];
        return list2(v_36549, v_36539);
    }
v_36386:
    goto v_36453;
v_36449:
    v_36540 = stack[-4];
    goto v_36450;
v_36451:
    v_36539 = elt(env, 6); // !\cdot! 
    goto v_36452;
v_36453:
    goto v_36449;
v_36450:
    goto v_36451;
v_36452:
    if (v_36540 == v_36539) goto v_36447;
    else goto v_36448;
v_36447:
    goto v_36461;
v_36457:
    stack[0] = (LispObject)2621440+TAG_FIXNUM; // 163840
    goto v_36458;
v_36459:
    goto v_36468;
v_36464:
    goto v_36474;
v_36470:
    v_36540 = stack[-1];
    goto v_36471;
v_36472:
    v_36539 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_36473;
v_36474:
    goto v_36470;
v_36471:
    goto v_36472;
v_36473:
    v_36540 = times2(v_36540, v_36539);
    env = stack[-6];
    goto v_36465;
v_36466:
    v_36539 = (LispObject)800+TAG_FIXNUM; // 50
    goto v_36467;
v_36468:
    goto v_36464;
v_36465:
    goto v_36466;
v_36467:
    v_36539 = plus2(v_36540, v_36539);
    goto v_36460;
v_36461:
    goto v_36457;
v_36458:
    goto v_36459;
v_36460:
    {
        LispObject v_36550 = stack[0];
        return list2(v_36550, v_36539);
    }
v_36448:
    goto v_36486;
v_36482:
    v_36540 = stack[-3];
    goto v_36483;
v_36484:
    v_36539 = elt(env, 6); // !\cdot! 
    goto v_36485;
v_36486:
    goto v_36482;
v_36483:
    goto v_36484;
v_36485:
    if (v_36540 == v_36539) goto v_36480;
    else goto v_36481;
v_36480:
    v_36539 = nil;
    goto v_36214;
v_36481:
    goto v_36495;
v_36491:
    stack[0] = (LispObject)2621440+TAG_FIXNUM; // 163840
    goto v_36492;
v_36493:
    goto v_36502;
v_36498:
    v_36540 = stack[-1];
    goto v_36499;
v_36500:
    v_36539 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_36501;
v_36502:
    goto v_36498;
v_36499:
    goto v_36500;
v_36501:
    v_36539 = times2(v_36540, v_36539);
    goto v_36494;
v_36495:
    goto v_36491;
v_36492:
    goto v_36493;
v_36494:
    {
        LispObject v_36551 = stack[0];
        return list2(v_36551, v_36539);
    }
v_36315:
    goto v_36511;
v_36507:
    v_36540 = stack[-5];
    goto v_36508;
v_36509:
    v_36539 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_36510;
v_36511:
    goto v_36507;
v_36508:
    goto v_36509;
v_36510:
    if (v_36540 == v_36539) goto v_36505;
    else goto v_36506;
v_36505:
    goto v_36519;
v_36515:
    stack[0] = (LispObject)10485760+TAG_FIXNUM; // 655360
    goto v_36516;
v_36517:
    goto v_36526;
v_36522:
    goto v_36532;
v_36528:
    v_36540 = stack[-1];
    goto v_36529;
v_36530:
    v_36539 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_36531;
v_36532:
    goto v_36528;
v_36529:
    goto v_36530;
v_36531:
    v_36540 = times2(v_36540, v_36539);
    env = stack[-6];
    goto v_36523;
v_36524:
    v_36539 = (LispObject)800+TAG_FIXNUM; // 50
    goto v_36525;
v_36526:
    goto v_36522;
v_36523:
    goto v_36524;
v_36525:
    v_36539 = difference2(v_36540, v_36539);
    goto v_36518;
v_36519:
    goto v_36515;
v_36516:
    goto v_36517;
v_36518:
    {
        LispObject v_36552 = stack[0];
        return list2(v_36552, v_36539);
    }
v_36506:
    v_36539 = nil;
    goto v_36214;
    v_36539 = nil;
v_36214:
    goto v_36177;
    v_36539 = nil;
v_36177:
    return onevalue(v_36539);
}



// Code for !*s2arg

static LispObject CC_Hs2arg(LispObject env,
                         LispObject v_36171, LispObject v_36172)
{
    env = qenv(env);
    LispObject v_36281, v_36282, v_36283;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_36172,v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_36171,v_36172);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_36172;
    v_36282 = v_36171;
// end of prologue
    v_36281 = v_36282;
    if (!consp(v_36281)) goto v_36180;
    else goto v_36181;
v_36180:
    v_36281 = lisp_true;
    goto v_36179;
v_36181:
    goto v_36190;
v_36186:
    v_36281 = v_36282;
    v_36283 = qcar(v_36281);
    goto v_36187;
v_36188:
    v_36281 = elt(env, 1); // quote
    goto v_36189;
v_36190:
    goto v_36186;
v_36187:
    goto v_36188;
v_36189:
    v_36281 = (v_36283 == v_36281 ? lisp_true : nil);
    goto v_36179;
    v_36281 = nil;
v_36179:
    if (v_36281 == nil) goto v_36177;
    v_36281 = v_36282;
    goto v_36175;
v_36177:
    v_36281 = v_36282;
    v_36281 = qcar(v_36281);
    if (symbolp(v_36281)) goto v_36201;
    v_36281 = lisp_true;
    goto v_36199;
v_36201:
    goto v_36212;
v_36208:
    v_36281 = v_36282;
    v_36283 = qcar(v_36281);
    goto v_36209;
v_36210:
    v_36281 = elt(env, 2); // nochange
    goto v_36211;
v_36212:
    goto v_36208;
v_36209:
    goto v_36210;
v_36211:
    v_36281 = Lflagp(nil, v_36283, v_36281);
    env = stack[-5];
    v_36281 = (v_36281 == nil ? lisp_true : nil);
    goto v_36199;
    v_36281 = nil;
v_36199:
    if (v_36281 == nil) goto v_36197;
    v_36281 = v_36282;
    stack[-4] = v_36281;
    v_36281 = stack[-4];
    if (v_36281 == nil) goto v_36226;
    else goto v_36227;
v_36226:
    v_36281 = nil;
    goto v_36221;
v_36227:
    v_36281 = stack[-4];
    v_36281 = qcar(v_36281);
    goto v_36239;
v_36235:
    v_36282 = v_36281;
    goto v_36236;
v_36237:
    v_36281 = stack[-3];
    goto v_36238;
v_36239:
    goto v_36235;
v_36236:
    goto v_36237;
v_36238:
    v_36281 = CC_Hs2arg(elt(env, 0), v_36282, v_36281);
    env = stack[-5];
    v_36281 = ncons(v_36281);
    env = stack[-5];
    stack[-1] = v_36281;
    stack[-2] = v_36281;
v_36222:
    v_36281 = stack[-4];
    v_36281 = qcdr(v_36281);
    stack[-4] = v_36281;
    v_36281 = stack[-4];
    if (v_36281 == nil) goto v_36246;
    else goto v_36247;
v_36246:
    v_36281 = stack[-2];
    goto v_36221;
v_36247:
    goto v_36255;
v_36251:
    stack[0] = stack[-1];
    goto v_36252;
v_36253:
    v_36281 = stack[-4];
    v_36281 = qcar(v_36281);
    goto v_36266;
v_36262:
    v_36282 = v_36281;
    goto v_36263;
v_36264:
    v_36281 = stack[-3];
    goto v_36265;
v_36266:
    goto v_36262;
v_36263:
    goto v_36264;
v_36265:
    v_36281 = CC_Hs2arg(elt(env, 0), v_36282, v_36281);
    env = stack[-5];
    v_36281 = ncons(v_36281);
    env = stack[-5];
    goto v_36254;
v_36255:
    goto v_36251;
v_36252:
    goto v_36253;
v_36254:
    v_36281 = Lrplacd(nil, stack[0], v_36281);
    env = stack[-5];
    v_36281 = stack[-1];
    v_36281 = qcdr(v_36281);
    stack[-1] = v_36281;
    goto v_36222;
v_36221:
    goto v_36175;
v_36197:
    goto v_36278;
v_36274:
    goto v_36275;
v_36276:
    v_36281 = stack[-3];
    goto v_36277;
v_36278:
    goto v_36274;
v_36275:
    goto v_36276;
v_36277:
    {
        fn = elt(env, 3); // mkarg
        return (*qfn2(fn))(fn, v_36282, v_36281);
    }
    v_36281 = nil;
v_36175:
    return onevalue(v_36281);
}



// Code for actual_world

static LispObject CC_actual_world(LispObject env,
                         LispObject v_36171, LispObject v_36172)
{
    env = qenv(env);
    LispObject v_36191, v_36192, v_36193;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_36172,v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_36171,v_36172);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_36192 = v_36172;
    v_36193 = v_36171;
// end of prologue
    goto v_36179;
v_36175:
    v_36191 = v_36193;
    stack[0] = qcar(v_36191);
    goto v_36176;
v_36177:
    goto v_36187;
v_36183:
    v_36191 = v_36192;
    goto v_36184;
v_36185:
    v_36192 = v_36193;
    v_36192 = qcdr(v_36192);
    goto v_36186;
v_36187:
    goto v_36183;
v_36184:
    goto v_36185;
v_36186:
    fn = elt(env, 1); // exclude_edges
    v_36191 = (*qfn2(fn))(fn, v_36191, v_36192);
    env = stack[-1];
    goto v_36178;
v_36179:
    goto v_36175;
v_36176:
    goto v_36177;
v_36178:
    {
        LispObject v_36195 = stack[0];
        fn = elt(env, 2); // union_edges
        return (*qfn2(fn))(fn, v_36195, v_36191);
    }
}



// Code for mo_dlexcomp

static LispObject CC_mo_dlexcomp(LispObject env,
                         LispObject v_36171, LispObject v_36172)
{
    env = qenv(env);
    LispObject v_36191, v_36192;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_36172,v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_36171,v_36172);
    }
// copy arguments values to proper place
    v_36191 = v_36172;
    v_36192 = v_36171;
// end of prologue
    goto v_36178;
v_36174:
    goto v_36184;
v_36180:
    v_36192 = qcar(v_36192);
    goto v_36181;
v_36182:
    v_36191 = qcar(v_36191);
    goto v_36183;
v_36184:
    goto v_36180;
v_36181:
    goto v_36182;
v_36183:
    fn = elt(env, 1); // mo!=lexcomp
    v_36192 = (*qfn2(fn))(fn, v_36192, v_36191);
    goto v_36175;
v_36176:
    v_36191 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36177;
v_36178:
    goto v_36174;
v_36175:
    goto v_36176;
v_36177:
    v_36191 = (v_36192 == v_36191 ? lisp_true : nil);
    return onevalue(v_36191);
}



// Code for affinep

static LispObject CC_affinep(LispObject env,
                         LispObject v_36171)
{
    env = qenv(env);
    LispObject v_36191, v_36192;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_36171);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_36191 = v_36171;
// end of prologue
    goto v_36178;
v_36174:
    v_36192 = qcar(v_36191);
    goto v_36175;
v_36176:
    v_36191 = elt(env, 1); // belong_to_space
    goto v_36177;
v_36178:
    goto v_36174;
v_36175:
    goto v_36176;
v_36177:
    v_36191 = get(v_36192, v_36191);
    env = stack[0];
    v_36192 = v_36191;
    v_36191 = v_36192;
    if (v_36191 == nil) goto v_36186;
    v_36191 = v_36192;
    fn = elt(env, 2); // get_sign_space
    v_36191 = (*qfn1(fn))(fn, v_36191);
    v_36191 = (v_36191 == nil ? lisp_true : nil);
    goto v_36184;
v_36186:
    v_36191 = nil;
v_36184:
    return onevalue(v_36191);
}



// Code for r2flbf

static LispObject CC_r2flbf(LispObject env,
                         LispObject v_36171)
{
    env = qenv(env);
    LispObject v_36184, v_36185;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_36185 = v_36171;
// end of prologue
    v_36184 = qvalue(elt(env, 1)); // !*bftag
    if (v_36184 == nil) goto v_36176;
    v_36184 = v_36185;
    {
        fn = elt(env, 2); // r2bf
        return (*qfn1(fn))(fn, v_36184);
    }
v_36176:
    v_36184 = v_36185;
    {
        fn = elt(env, 3); // r2fl
        return (*qfn1(fn))(fn, v_36184);
    }
    v_36184 = nil;
    return onevalue(v_36184);
}



// Code for redmsg

static LispObject CC_redmsg(LispObject env,
                         LispObject v_36171, LispObject v_36172)
{
    env = qenv(env);
    LispObject v_36242, v_36243, v_36244;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_36172,v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_36171,v_36172);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_36172;
    stack[-1] = v_36171;
// end of prologue
    v_36242 = qvalue(elt(env, 1)); // !*wsm
    if (v_36242 == nil) goto v_36180;
    else goto v_36181;
v_36180:
    v_36242 = qvalue(elt(env, 2)); // !*msg
    if (v_36242 == nil) goto v_36185;
    else goto v_36186;
v_36185:
    v_36242 = nil;
    goto v_36184;
v_36186:
    goto v_36195;
v_36191:
    v_36243 = stack[0];
    goto v_36192;
v_36193:
    v_36242 = elt(env, 3); // ("operator" "predicate")
    goto v_36194;
v_36195:
    goto v_36191;
v_36192:
    goto v_36193;
v_36194:
    v_36242 = Lmember(nil, v_36243, v_36242);
    goto v_36184;
    v_36242 = nil;
v_36184:
    goto v_36179;
v_36181:
    v_36242 = nil;
    goto v_36179;
    v_36242 = nil;
v_36179:
    if (v_36242 == nil) goto v_36177;
    fn = elt(env, 7); // terminalp
    v_36242 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    if (v_36242 == nil) goto v_36205;
    goto v_36220;
v_36212:
    stack[-2] = elt(env, 4); // "Declare"
    goto v_36213;
v_36214:
    v_36242 = stack[-1];
    fn = elt(env, 8); // get!-print!-name
    v_36244 = (*qfn1(fn))(fn, v_36242);
    env = stack[-3];
    goto v_36215;
v_36216:
    v_36243 = stack[0];
    goto v_36217;
v_36218:
    v_36242 = elt(env, 5); // "?"
    goto v_36219;
v_36220:
    goto v_36212;
v_36213:
    goto v_36214;
v_36215:
    goto v_36216;
v_36217:
    goto v_36218;
v_36219:
    v_36242 = list4(stack[-2], v_36244, v_36243, v_36242);
    env = stack[-3];
    fn = elt(env, 9); // yesp
    v_36242 = (*qfn1(fn))(fn, v_36242);
    if (v_36242 == nil) goto v_36209;
    else goto v_36208;
v_36209:
        Lerror0(nil, 0);
v_36208:
    goto v_36203;
v_36205:
    goto v_36237;
v_36231:
    v_36242 = stack[-1];
    fn = elt(env, 8); // get!-print!-name
    v_36244 = (*qfn1(fn))(fn, v_36242);
    env = stack[-3];
    goto v_36232;
v_36233:
    v_36243 = elt(env, 6); // "declared"
    goto v_36234;
v_36235:
    v_36242 = stack[0];
    goto v_36236;
v_36237:
    goto v_36231;
v_36232:
    goto v_36233;
v_36234:
    goto v_36235;
v_36236:
    v_36242 = list3(v_36244, v_36243, v_36242);
    env = stack[-3];
    {
        fn = elt(env, 10); // lprim
        return (*qfn1(fn))(fn, v_36242);
    }
    v_36242 = nil;
v_36203:
    goto v_36175;
v_36177:
    v_36242 = nil;
v_36175:
    return onevalue(v_36242);
}



// Code for ofsf_ordrelp

static LispObject CC_ofsf_ordrelp(LispObject env,
                         LispObject v_36171, LispObject v_36172)
{
    env = qenv(env);
    LispObject v_36190, v_36191, v_36192;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_36191 = v_36172;
    v_36190 = v_36171;
// end of prologue
    goto v_36178;
v_36174:
    goto v_36175;
v_36176:
    goto v_36184;
v_36180:
    goto v_36181;
v_36182:
    v_36192 = elt(env, 1); // (equal neq leq lessp geq greaterp)
    goto v_36183;
v_36184:
    goto v_36180;
v_36181:
    goto v_36182;
v_36183:
    v_36190 = Lmemq(nil, v_36190, v_36192);
    v_36190 = qcdr(v_36190);
    goto v_36177;
v_36178:
    goto v_36174;
v_36175:
    goto v_36176;
v_36177:
    v_36190 = Lmemq(nil, v_36191, v_36190);
    return onevalue(v_36190);
}



// Code for gcdk

static LispObject CC_gcdk(LispObject env,
                         LispObject v_36171, LispObject v_36172)
{
    env = qenv(env);
    LispObject v_36545, v_36546, v_36547;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_36172,v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_36171,v_36172);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_36172;
    stack[0] = v_36171;
// end of prologue
    stack[-10] = nil;
    stack[-8] = nil;
    goto v_36189;
v_36185:
    v_36546 = stack[0];
    goto v_36186;
v_36187:
    v_36545 = stack[-9];
    goto v_36188;
v_36189:
    goto v_36185;
v_36186:
    goto v_36187;
v_36188:
    if (equal(v_36546, v_36545)) goto v_36183;
    else goto v_36184;
v_36183:
    v_36545 = stack[0];
    goto v_36179;
v_36184:
    v_36545 = stack[0];
    if (!consp(v_36545)) goto v_36201;
    else goto v_36202;
v_36201:
    v_36545 = lisp_true;
    goto v_36200;
v_36202:
    v_36545 = stack[0];
    v_36545 = qcar(v_36545);
    v_36545 = (consp(v_36545) ? nil : lisp_true);
    goto v_36200;
    v_36545 = nil;
v_36200:
    if (v_36545 == nil) goto v_36198;
    v_36545 = lisp_true;
    goto v_36196;
v_36198:
    goto v_36217;
v_36213:
    goto v_36223;
v_36219:
    v_36546 = stack[-9];
    goto v_36220;
v_36221:
    v_36545 = stack[0];
    v_36545 = qcar(v_36545);
    v_36545 = qcar(v_36545);
    v_36545 = qcar(v_36545);
    stack[-8] = v_36545;
    goto v_36222;
v_36223:
    goto v_36219;
v_36220:
    goto v_36221;
v_36222:
    fn = elt(env, 5); // degr
    v_36546 = (*qfn2(fn))(fn, v_36546, v_36545);
    env = stack[-11];
    goto v_36214;
v_36215:
    v_36545 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_36216;
v_36217:
    goto v_36213;
v_36214:
    goto v_36215;
v_36216:
    v_36545 = (v_36546 == v_36545 ? lisp_true : nil);
    goto v_36196;
    v_36545 = nil;
v_36196:
    if (v_36545 == nil) goto v_36194;
    v_36545 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36179;
v_36194:
    goto v_36239;
v_36235:
    v_36545 = stack[0];
    v_36545 = qcar(v_36545);
    v_36545 = qcar(v_36545);
    v_36546 = qcdr(v_36545);
    goto v_36236;
v_36237:
    v_36545 = stack[-9];
    v_36545 = qcar(v_36545);
    v_36545 = qcar(v_36545);
    v_36545 = qcdr(v_36545);
    goto v_36238;
v_36239:
    goto v_36235;
v_36236:
    goto v_36237;
v_36238:
    v_36545 = (LispObject)lessp2(v_36546, v_36545);
    v_36545 = v_36545 ? lisp_true : nil;
    env = stack[-11];
    if (v_36545 == nil) goto v_36233;
    v_36545 = stack[0];
    stack[-7] = v_36545;
    v_36545 = stack[-9];
    stack[0] = v_36545;
    v_36545 = stack[-7];
    stack[-9] = v_36545;
    goto v_36182;
v_36233:
v_36182:
    goto v_36260;
v_36256:
    v_36546 = stack[0];
    goto v_36257;
v_36258:
    v_36545 = stack[-9];
    goto v_36259;
v_36260:
    goto v_36256;
v_36257:
    goto v_36258;
v_36259:
    fn = elt(env, 6); // quotf1
    v_36545 = (*qfn2(fn))(fn, v_36546, v_36545);
    env = stack[-11];
    if (v_36545 == nil) goto v_36254;
    v_36545 = stack[-9];
    goto v_36179;
v_36254:
    v_36545 = qvalue(elt(env, 1)); // !*heugcd
    if (v_36545 == nil) goto v_36265;
    goto v_36274;
v_36270:
    v_36546 = stack[0];
    goto v_36271;
v_36272:
    v_36545 = stack[-9];
    goto v_36273;
v_36274:
    goto v_36270;
v_36271:
    goto v_36272;
v_36273:
    fn = elt(env, 7); // heu!-gcd
    v_36545 = (*qfn2(fn))(fn, v_36546, v_36545);
    env = stack[-11];
    v_36546 = v_36545;
    if (v_36545 == nil) goto v_36265;
    v_36545 = v_36546;
    goto v_36179;
v_36265:
    goto v_36288;
v_36284:
    v_36545 = stack[-9];
    v_36545 = qcar(v_36545);
    v_36545 = qcar(v_36545);
    v_36546 = qcdr(v_36545);
    goto v_36285;
v_36286:
    v_36545 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36287;
v_36288:
    goto v_36284;
v_36285:
    goto v_36286;
v_36287:
    if (v_36546 == v_36545) goto v_36282;
    else goto v_36283;
v_36282:
    v_36545 = lisp_true;
    goto v_36281;
v_36283:
    v_36545 = elt(env, 2); // modular!-multicheck
    fn = elt(env, 8); // getd
    v_36545 = (*qfn1(fn))(fn, v_36545);
    env = stack[-11];
    if (v_36545 == nil) goto v_36302;
    else goto v_36303;
v_36302:
    v_36545 = nil;
    goto v_36301;
v_36303:
    goto v_36316;
v_36310:
    v_36547 = stack[0];
    goto v_36311;
v_36312:
    v_36546 = stack[-9];
    goto v_36313;
v_36314:
    v_36545 = stack[-8];
    goto v_36315;
v_36316:
    goto v_36310;
v_36311:
    goto v_36312;
v_36313:
    goto v_36314;
v_36315:
    fn = elt(env, 2); // modular!-multicheck
    v_36545 = (*qfnn(fn))(fn, 3, v_36547, v_36546, v_36545);
    env = stack[-11];
    goto v_36301;
    v_36545 = nil;
v_36301:
    if (v_36545 == nil) goto v_36299;
    else goto v_36298;
v_36299:
    v_36545 = qvalue(elt(env, 3)); // !*mcd
    v_36545 = (v_36545 == nil ? lisp_true : nil);
v_36298:
    goto v_36281;
    v_36545 = nil;
v_36281:
    if (v_36545 == nil) goto v_36279;
    v_36545 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36179;
v_36279:
v_36180:
    goto v_36328;
v_36324:
    v_36546 = stack[0];
    goto v_36325;
v_36326:
    v_36545 = stack[-9];
    goto v_36327;
v_36328:
    goto v_36324;
v_36325:
    goto v_36326;
v_36327:
    fn = elt(env, 9); // remk
    v_36545 = (*qfn2(fn))(fn, v_36546, v_36545);
    env = stack[-11];
    stack[-7] = v_36545;
    v_36545 = stack[-7];
    if (v_36545 == nil) goto v_36333;
    else goto v_36334;
v_36333:
    v_36545 = stack[-9];
    goto v_36179;
v_36334:
    goto v_36343;
v_36339:
    goto v_36349;
v_36345:
    v_36546 = stack[-7];
    goto v_36346;
v_36347:
    v_36545 = stack[-8];
    goto v_36348;
v_36349:
    goto v_36345;
v_36346:
    goto v_36347;
v_36348:
    fn = elt(env, 5); // degr
    v_36546 = (*qfn2(fn))(fn, v_36546, v_36545);
    env = stack[-11];
    goto v_36340;
v_36341:
    v_36545 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_36342;
v_36343:
    goto v_36339;
v_36340:
    goto v_36341;
v_36342:
    if (v_36546 == v_36545) goto v_36337;
    else goto v_36338;
v_36337:
    v_36545 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36179;
v_36338:
    goto v_36359;
v_36355:
    v_36546 = stack[-9];
    goto v_36356;
v_36357:
    v_36545 = stack[-10];
    goto v_36358;
v_36359:
    goto v_36355;
v_36356:
    goto v_36357;
v_36358:
    fn = elt(env, 10); // addlc
    v_36545 = (*qfn2(fn))(fn, v_36546, v_36545);
    env = stack[-11];
    stack[-10] = v_36545;
    goto v_36371;
v_36367:
    v_36546 = stack[-7];
    goto v_36368;
v_36369:
    v_36545 = stack[-7];
    v_36545 = qcar(v_36545);
    v_36545 = qcdr(v_36545);
    goto v_36370;
v_36371:
    goto v_36367;
v_36368:
    goto v_36369;
v_36370:
    fn = elt(env, 6); // quotf1
    v_36545 = (*qfn2(fn))(fn, v_36546, v_36545);
    env = stack[-11];
    v_36546 = v_36545;
    if (v_36545 == nil) goto v_36365;
    v_36545 = v_36546;
    stack[-7] = v_36545;
    goto v_36363;
v_36365:
    v_36545 = stack[-10];
    stack[-6] = v_36545;
v_36382:
    v_36545 = stack[-6];
    if (v_36545 == nil) goto v_36386;
    else goto v_36387;
v_36386:
    goto v_36381;
v_36387:
    v_36545 = stack[-6];
    v_36545 = qcar(v_36545);
    stack[-5] = v_36545;
    v_36545 = stack[-5];
    if (!consp(v_36545)) goto v_36403;
    else goto v_36404;
v_36403:
    v_36545 = qvalue(elt(env, 4)); // dmode!*
    if (!symbolp(v_36545)) v_36545 = nil;
    else { v_36545 = qfastgets(v_36545);
           if (v_36545 != nil) { v_36545 = elt(v_36545, 3); // field
#ifdef RECORD_GET
             if (v_36545 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_36545 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_36545 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_36545 == SPID_NOPROP) v_36545 = nil; else v_36545 = lisp_true; }}
#endif
    v_36545 = (v_36545 == nil ? lisp_true : nil);
    goto v_36402;
v_36404:
    v_36545 = nil;
    goto v_36402;
    v_36545 = nil;
v_36402:
    if (v_36545 == nil) goto v_36400;
    v_36545 = lisp_true;
    goto v_36398;
v_36400:
    v_36545 = stack[-5];
    if (!consp(v_36545)) goto v_36421;
    else goto v_36422;
v_36421:
    v_36545 = lisp_true;
    goto v_36420;
v_36422:
    v_36545 = stack[-5];
    v_36545 = qcar(v_36545);
    v_36545 = (consp(v_36545) ? nil : lisp_true);
    goto v_36420;
    v_36545 = nil;
v_36420:
    if (v_36545 == nil) goto v_36418;
    v_36545 = qvalue(elt(env, 4)); // dmode!*
    if (!symbolp(v_36545)) v_36545 = nil;
    else { v_36545 = qfastgets(v_36545);
           if (v_36545 != nil) { v_36545 = elt(v_36545, 3); // field
#ifdef RECORD_GET
             if (v_36545 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_36545 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_36545 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_36545 == SPID_NOPROP) v_36545 = nil; else v_36545 = lisp_true; }}
#endif
    if (v_36545 == nil) goto v_36433;
    v_36545 = lisp_true;
    goto v_36431;
v_36433:
    v_36545 = stack[-5];
    v_36545 = qcar(v_36545);
    if (!symbolp(v_36545)) v_36545 = nil;
    else { v_36545 = qfastgets(v_36545);
           if (v_36545 != nil) { v_36545 = elt(v_36545, 27); // units
#ifdef RECORD_GET
             if (v_36545 != SPID_NOPROP)
                record_get(elt(fastget_names, 27), 1);
             else record_get(elt(fastget_names, 27), 0),
                v_36545 = nil; }
           else record_get(elt(fastget_names, 27), 0); }
#else
             if (v_36545 == SPID_NOPROP) v_36545 = nil; }}
#endif
    v_36546 = v_36545;
    if (v_36545 == nil) goto v_36441;
    else goto v_36442;
v_36441:
    v_36545 = nil;
    goto v_36440;
v_36442:
    goto v_36453;
v_36449:
    stack[-4] = stack[-5];
    goto v_36450;
v_36451:
    v_36545 = v_36546;
    stack[-3] = v_36545;
    v_36545 = stack[-3];
    if (v_36545 == nil) goto v_36464;
    else goto v_36465;
v_36464:
    v_36545 = nil;
    goto v_36459;
v_36465:
    v_36545 = stack[-3];
    v_36545 = qcar(v_36545);
    v_36545 = qcar(v_36545);
    v_36545 = ncons(v_36545);
    env = stack[-11];
    stack[-1] = v_36545;
    stack[-2] = v_36545;
v_36460:
    v_36545 = stack[-3];
    v_36545 = qcdr(v_36545);
    stack[-3] = v_36545;
    v_36545 = stack[-3];
    if (v_36545 == nil) goto v_36478;
    else goto v_36479;
v_36478:
    v_36545 = stack[-2];
    goto v_36459;
v_36479:
    goto v_36487;
v_36483:
    stack[0] = stack[-1];
    goto v_36484;
v_36485:
    v_36545 = stack[-3];
    v_36545 = qcar(v_36545);
    v_36545 = qcar(v_36545);
    v_36545 = ncons(v_36545);
    env = stack[-11];
    goto v_36486;
v_36487:
    goto v_36483;
v_36484:
    goto v_36485;
v_36486:
    v_36545 = Lrplacd(nil, stack[0], v_36545);
    env = stack[-11];
    v_36545 = stack[-1];
    v_36545 = qcdr(v_36545);
    stack[-1] = v_36545;
    goto v_36460;
v_36459:
    goto v_36452;
v_36453:
    goto v_36449;
v_36450:
    goto v_36451;
v_36452:
    v_36545 = Lmember(nil, stack[-4], v_36545);
    goto v_36440;
    v_36545 = nil;
v_36440:
    goto v_36431;
    v_36545 = nil;
v_36431:
    goto v_36416;
v_36418:
    v_36545 = nil;
    goto v_36416;
    v_36545 = nil;
v_36416:
    v_36545 = (v_36545 == nil ? lisp_true : nil);
    goto v_36398;
    v_36545 = nil;
v_36398:
    if (v_36545 == nil) goto v_36396;
v_36504:
    goto v_36514;
v_36510:
    v_36546 = stack[-7];
    goto v_36511;
v_36512:
    v_36545 = stack[-5];
    goto v_36513;
v_36514:
    goto v_36510;
v_36511:
    goto v_36512;
v_36513:
    fn = elt(env, 6); // quotf1
    v_36545 = (*qfn2(fn))(fn, v_36546, v_36545);
    env = stack[-11];
    v_36546 = v_36545;
    if (v_36545 == nil) goto v_36507;
    else goto v_36508;
v_36507:
    goto v_36503;
v_36508:
    v_36545 = v_36546;
    stack[-7] = v_36545;
    goto v_36504;
v_36503:
    goto v_36394;
v_36396:
v_36394:
    v_36545 = stack[-6];
    v_36545 = qcdr(v_36545);
    stack[-6] = v_36545;
    goto v_36382;
v_36381:
    goto v_36363;
v_36363:
    v_36545 = stack[-9];
    stack[0] = v_36545;
    v_36545 = stack[-7];
    fn = elt(env, 11); // prim!-part
    v_36545 = (*qfn1(fn))(fn, v_36545);
    env = stack[-11];
    stack[-9] = v_36545;
    goto v_36532;
v_36528:
    goto v_36538;
v_36534:
    v_36546 = stack[-9];
    goto v_36535;
v_36536:
    v_36545 = stack[-8];
    goto v_36537;
v_36538:
    goto v_36534;
v_36535:
    goto v_36536;
v_36537:
    fn = elt(env, 5); // degr
    v_36546 = (*qfn2(fn))(fn, v_36546, v_36545);
    env = stack[-11];
    goto v_36529;
v_36530:
    v_36545 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_36531;
v_36532:
    goto v_36528;
v_36529:
    goto v_36530;
v_36531:
    if (v_36546 == v_36545) goto v_36526;
    else goto v_36527;
v_36526:
    v_36545 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36179;
v_36527:
    goto v_36180;
    v_36545 = nil;
v_36179:
    return onevalue(v_36545);
}



// Code for mk_character

static LispObject CC_mk_character(LispObject env,
                         LispObject v_36171)
{
    env = qenv(env);
    LispObject v_36261, v_36262;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_36171);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_36171;
// end of prologue
    v_36261 = stack[-5];
    fn = elt(env, 1); // get_group_in
    v_36261 = (*qfn1(fn))(fn, v_36261);
    env = stack[-7];
    stack[-6] = v_36261;
    v_36261 = stack[-6];
    fn = elt(env, 2); // get!*elements
    v_36261 = (*qfn1(fn))(fn, v_36261);
    env = stack[-7];
    stack[-4] = v_36261;
    v_36261 = stack[-4];
    if (v_36261 == nil) goto v_36190;
    else goto v_36191;
v_36190:
    v_36261 = nil;
    goto v_36184;
v_36191:
    v_36261 = stack[-4];
    v_36261 = qcar(v_36261);
    goto v_36203;
v_36199:
    stack[0] = v_36261;
    goto v_36200;
v_36201:
    goto v_36211;
v_36207:
    v_36262 = v_36261;
    goto v_36208;
v_36209:
    v_36261 = stack[-5];
    goto v_36210;
v_36211:
    goto v_36207;
v_36208:
    goto v_36209;
v_36210:
    fn = elt(env, 3); // get_rep_matrix_in
    v_36261 = (*qfn2(fn))(fn, v_36262, v_36261);
    env = stack[-7];
    fn = elt(env, 4); // mk!+trace
    v_36261 = (*qfn1(fn))(fn, v_36261);
    env = stack[-7];
    goto v_36202;
v_36203:
    goto v_36199;
v_36200:
    goto v_36201;
v_36202:
    v_36261 = list2(stack[0], v_36261);
    env = stack[-7];
    v_36261 = ncons(v_36261);
    env = stack[-7];
    stack[-2] = v_36261;
    stack[-3] = v_36261;
v_36185:
    v_36261 = stack[-4];
    v_36261 = qcdr(v_36261);
    stack[-4] = v_36261;
    v_36261 = stack[-4];
    if (v_36261 == nil) goto v_36218;
    else goto v_36219;
v_36218:
    v_36261 = stack[-3];
    goto v_36184;
v_36219:
    goto v_36227;
v_36223:
    stack[-1] = stack[-2];
    goto v_36224;
v_36225:
    v_36261 = stack[-4];
    v_36261 = qcar(v_36261);
    goto v_36238;
v_36234:
    stack[0] = v_36261;
    goto v_36235;
v_36236:
    goto v_36246;
v_36242:
    v_36262 = v_36261;
    goto v_36243;
v_36244:
    v_36261 = stack[-5];
    goto v_36245;
v_36246:
    goto v_36242;
v_36243:
    goto v_36244;
v_36245:
    fn = elt(env, 3); // get_rep_matrix_in
    v_36261 = (*qfn2(fn))(fn, v_36262, v_36261);
    env = stack[-7];
    fn = elt(env, 4); // mk!+trace
    v_36261 = (*qfn1(fn))(fn, v_36261);
    env = stack[-7];
    goto v_36237;
v_36238:
    goto v_36234;
v_36235:
    goto v_36236;
v_36237:
    v_36261 = list2(stack[0], v_36261);
    env = stack[-7];
    v_36261 = ncons(v_36261);
    env = stack[-7];
    goto v_36226;
v_36227:
    goto v_36223;
v_36224:
    goto v_36225;
v_36226:
    v_36261 = Lrplacd(nil, stack[-1], v_36261);
    env = stack[-7];
    v_36261 = stack[-2];
    v_36261 = qcdr(v_36261);
    stack[-2] = v_36261;
    goto v_36185;
v_36184:
    stack[0] = v_36261;
    goto v_36256;
v_36252:
    v_36261 = stack[-6];
    v_36262 = ncons(v_36261);
    goto v_36253;
v_36254:
    v_36261 = stack[0];
    goto v_36255;
v_36256:
    goto v_36252;
v_36253:
    goto v_36254;
v_36255:
        return Lappend(nil, v_36262, v_36261);
    return onevalue(v_36261);
}



// Code for qqe_length!-graph!-remove!-mark

static LispObject CC_qqe_lengthKgraphKremoveKmark(LispObject env,
                         LispObject v_36171, LispObject v_36172)
{
    env = qenv(env);
    LispObject v_36199, v_36200, v_36201, v_36202;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_36172,v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_36171,v_36172);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_36201 = v_36172;
    v_36199 = v_36171;
// end of prologue
    v_36202 = v_36199;
v_36177:
    v_36199 = v_36202;
    if (v_36199 == nil) goto v_36181;
    else goto v_36182;
v_36181:
    v_36199 = nil;
    goto v_36176;
v_36182:
    v_36199 = v_36202;
    v_36199 = qcar(v_36199);
    goto v_36193;
v_36189:
    v_36200 = v_36199;
    goto v_36190;
v_36191:
    v_36199 = v_36201;
    goto v_36192;
v_36193:
    goto v_36189;
v_36190:
    goto v_36191;
v_36192:
    v_36199 = Lremprop(nil, v_36200, v_36199);
    env = stack[0];
    v_36199 = v_36202;
    v_36199 = qcdr(v_36199);
    v_36202 = v_36199;
    goto v_36177;
v_36176:
    return onevalue(v_36199);
}



// Code for groebfactorize3

static LispObject CC_groebfactorize3(LispObject env,
                         LispObject v_36171)
{
    env = qenv(env);
    LispObject v_36175;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_36175 = v_36171;
// end of prologue
    v_36175 = nil;
    return onevalue(v_36175);
}



// Code for xvarp

static LispObject CC_xvarp(LispObject env,
                         LispObject v_36171)
{
    env = qenv(env);
    LispObject v_36240, v_36241;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_36171);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_36171;
// end of prologue
    goto v_36181;
v_36177:
    v_36241 = qvalue(elt(env, 1)); // xvars!*
    goto v_36178;
v_36179:
    v_36240 = lisp_true;
    goto v_36180;
v_36181:
    goto v_36177;
v_36178:
    goto v_36179;
v_36180:
    if (equal(v_36241, v_36240)) goto v_36176;
    goto v_36192;
v_36188:
    v_36240 = stack[0];
    fn = elt(env, 3); // xdegree
    v_36241 = (*qfn1(fn))(fn, v_36240);
    env = stack[-1];
    goto v_36189;
v_36190:
    v_36240 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_36191;
v_36192:
    goto v_36188;
v_36189:
    goto v_36190;
v_36191:
    if (v_36241 == v_36240) goto v_36187;
    v_36240 = lisp_true;
    goto v_36185;
v_36187:
    goto v_36203;
v_36199:
    v_36240 = stack[0];
    goto v_36200;
v_36201:
    v_36241 = qvalue(elt(env, 1)); // xvars!*
    goto v_36202;
v_36203:
    goto v_36199;
v_36200:
    goto v_36201;
v_36202:
    v_36240 = Lmemq(nil, v_36240, v_36241);
    goto v_36185;
    v_36240 = nil;
v_36185:
    goto v_36174;
v_36176:
    v_36240 = stack[0];
    if (!consp(v_36240)) goto v_36207;
    else goto v_36208;
v_36207:
    v_36240 = stack[0];
    if (!symbolp(v_36240)) v_36240 = nil;
    else { v_36240 = qfastgets(v_36240);
           if (v_36240 != nil) { v_36240 = elt(v_36240, 29); // fdegree
#ifdef RECORD_GET
             if (v_36240 != SPID_NOPROP)
                record_get(elt(fastget_names, 29), 1);
             else record_get(elt(fastget_names, 29), 0),
                v_36240 = nil; }
           else record_get(elt(fastget_names, 29), 0); }
#else
             if (v_36240 == SPID_NOPROP) v_36240 = nil; }}
#endif
    goto v_36174;
v_36208:
    v_36240 = stack[0];
    v_36240 = qcar(v_36240);
    if (!symbolp(v_36240)) v_36240 = nil;
    else { v_36240 = qfastgets(v_36240);
           if (v_36240 != nil) { v_36240 = elt(v_36240, 16); // indexvar
#ifdef RECORD_GET
             if (v_36240 == SPID_NOPROP)
                record_get(elt(fastget_names, 16), 0),
                v_36240 = nil;
             else record_get(elt(fastget_names, 16), 1),
                v_36240 = lisp_true; }
           else record_get(elt(fastget_names, 16), 0); }
#else
             if (v_36240 == SPID_NOPROP) v_36240 = nil; else v_36240 = lisp_true; }}
#endif
    if (v_36240 == nil) goto v_36213;
    goto v_36221;
v_36217:
    v_36240 = stack[0];
    v_36240 = qcdr(v_36240);
    v_36241 = Llength(nil, v_36240);
    goto v_36218;
v_36219:
    v_36240 = stack[0];
    v_36240 = qcar(v_36240);
    if (!symbolp(v_36240)) v_36240 = nil;
    else { v_36240 = qfastgets(v_36240);
           if (v_36240 != nil) { v_36240 = elt(v_36240, 25); // ifdegree
#ifdef RECORD_GET
             if (v_36240 != SPID_NOPROP)
                record_get(elt(fastget_names, 25), 1);
             else record_get(elt(fastget_names, 25), 0),
                v_36240 = nil; }
           else record_get(elt(fastget_names, 25), 0); }
#else
             if (v_36240 == SPID_NOPROP) v_36240 = nil; }}
#endif
    goto v_36220;
v_36221:
    goto v_36217;
v_36218:
    goto v_36219;
v_36220:
    v_36240 = Lassoc(nil, v_36241, v_36240);
    goto v_36174;
v_36213:
    goto v_36235;
v_36231:
    v_36240 = stack[0];
    v_36240 = qcar(v_36240);
    goto v_36232;
v_36233:
    v_36241 = elt(env, 2); // (wedge d partdf hodge innerprod liedf)
    goto v_36234;
v_36235:
    goto v_36231;
v_36232:
    goto v_36233;
v_36234:
    v_36240 = Lmemq(nil, v_36240, v_36241);
    goto v_36174;
    v_36240 = nil;
v_36174:
    return onevalue(v_36240);
}



// Code for exp!:

static LispObject CC_expT(LispObject env,
                         LispObject v_36171, LispObject v_36172)
{
    env = qenv(env);
    LispObject v_36478, v_36479, v_36480;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_36172,v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_36171,v_36172);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(14);
// copy arguments values to proper place
    stack[-10] = v_36172;
    stack[-11] = v_36171;
// end of prologue
    v_36478 = stack[-10];
    v_36478 = integerp(v_36478);
    if (v_36478 == nil) goto v_36180;
    else goto v_36181;
v_36180:
    v_36478 = lisp_true;
    goto v_36179;
v_36181:
    goto v_36192;
v_36188:
    v_36479 = stack[-10];
    goto v_36189;
v_36190:
    v_36478 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_36191;
v_36192:
    goto v_36188;
v_36189:
    goto v_36190;
v_36191:
    v_36478 = (LispObject)lesseq2(v_36479, v_36478);
    v_36478 = v_36478 ? lisp_true : nil;
    env = stack[-13];
    goto v_36179;
    v_36478 = nil;
v_36179:
    if (v_36478 == nil) goto v_36177;
    v_36478 = elt(env, 0); // exp!:
    {
        fn = elt(env, 4); // bflerrmsg
        return (*qfn1(fn))(fn, v_36478);
    }
v_36177:
    v_36478 = stack[-11];
    fn = elt(env, 5); // bfzerop!:
    v_36478 = (*qfn1(fn))(fn, v_36478);
    env = stack[-13];
    if (v_36478 == nil) goto v_36198;
    v_36478 = qvalue(elt(env, 1)); // bfone!*
    goto v_36175;
v_36198:
    goto v_36222;
v_36216:
    stack[0] = elt(env, 2); // !:rd!:
    goto v_36217;
v_36218:
    v_36478 = stack[-11];
    fn = elt(env, 6); // abs!:
    v_36478 = (*qfn1(fn))(fn, v_36478);
    env = stack[-13];
    stack[-1] = v_36478;
    fn = elt(env, 7); // conv!:bf2i
    v_36479 = (*qfn1(fn))(fn, v_36478);
    env = stack[-13];
    stack[-9] = v_36479;
    goto v_36219;
v_36220:
    v_36478 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_36221;
v_36222:
    goto v_36216;
v_36217:
    goto v_36218;
v_36219:
    goto v_36220;
v_36221:
    v_36478 = list2star(stack[0], v_36479, v_36478);
    env = stack[-13];
    stack[0] = v_36478;
    goto v_36233;
v_36229:
    v_36479 = stack[-1];
    goto v_36230;
v_36231:
    v_36478 = stack[0];
    goto v_36232;
v_36233:
    goto v_36229;
v_36230:
    goto v_36231;
v_36232:
    fn = elt(env, 8); // difference!:
    v_36478 = (*qfn2(fn))(fn, v_36479, v_36478);
    env = stack[-13];
    goto v_36241;
v_36237:
    stack[-2] = stack[-10];
    goto v_36238;
v_36239:
    goto v_36248;
v_36244:
    v_36478 = stack[-9];
    fn = elt(env, 9); // msd
    v_36479 = (*qfn1(fn))(fn, v_36478);
    env = stack[-13];
    goto v_36245;
v_36246:
    v_36478 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_36247;
v_36248:
    goto v_36244;
v_36245:
    goto v_36246;
v_36247:
    v_36478 = plus2(v_36479, v_36478);
    env = stack[-13];
    goto v_36240;
v_36241:
    goto v_36237;
v_36238:
    goto v_36239;
v_36240:
    v_36478 = plus2(stack[-2], v_36478);
    env = stack[-13];
    stack[-12] = v_36478;
    goto v_36257;
v_36253:
    v_36479 = stack[-1];
    goto v_36254;
v_36255:
    v_36478 = stack[0];
    goto v_36256;
v_36257:
    goto v_36253;
v_36254:
    goto v_36255;
v_36256:
    fn = elt(env, 8); // difference!:
    v_36478 = (*qfn2(fn))(fn, v_36479, v_36478);
    env = stack[-13];
    stack[-8] = v_36478;
    v_36478 = stack[0];
    fn = elt(env, 5); // bfzerop!:
    v_36478 = (*qfn1(fn))(fn, v_36478);
    env = stack[-13];
    if (v_36478 == nil) goto v_36263;
    v_36478 = qvalue(elt(env, 1)); // bfone!*
    stack[-7] = v_36478;
    goto v_36261;
v_36263:
    v_36478 = stack[-12];
// Binding !:bprec!:
// FLUIDBIND: reloadenv=13 litvec-offset=3 saveloc=0
{   bind_fluid_stack bind_fluid_var(-13, 3, 0);
    qvalue(elt(env, 3)) = v_36478; // !:bprec!:
    goto v_36276;
v_36272:
    v_36478 = stack[-12];
    fn = elt(env, 10); // !:e
    v_36479 = (*qfn1(fn))(fn, v_36478);
    env = stack[-13];
    goto v_36273;
v_36274:
    v_36478 = stack[-9];
    goto v_36275;
v_36276:
    goto v_36272;
v_36273:
    goto v_36274;
v_36275:
    fn = elt(env, 11); // texpt!:
    v_36478 = (*qfn2(fn))(fn, v_36479, v_36478);
    env = stack[-13];
    stack[-7] = v_36478;
    ;}  // end of a binding scope
    goto v_36261;
v_36261:
    v_36478 = stack[-8];
    fn = elt(env, 5); // bfzerop!:
    v_36478 = (*qfn1(fn))(fn, v_36478);
    env = stack[-13];
    if (v_36478 == nil) goto v_36283;
    v_36478 = qvalue(elt(env, 1)); // bfone!*
    stack[-6] = v_36478;
    goto v_36281;
v_36283:
    goto v_36306;
v_36300:
    stack[-1] = elt(env, 2); // !:rd!:
    goto v_36301;
v_36302:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_36303;
v_36304:
    v_36478 = stack[-12];
    v_36478 = negate(v_36478);
    env = stack[-13];
    goto v_36305;
v_36306:
    goto v_36300;
v_36301:
    goto v_36302;
v_36303:
    goto v_36304;
v_36305:
    v_36478 = list2star(stack[-1], stack[0], v_36478);
    env = stack[-13];
    stack[-4] = v_36478;
    v_36478 = qvalue(elt(env, 1)); // bfone!*
    stack[0] = v_36478;
    stack[-2] = v_36478;
    stack[-6] = v_36478;
    v_36478 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-9] = v_36478;
    v_36478 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_36478;
v_36316:
    goto v_36326;
v_36322:
    v_36479 = stack[0];
    goto v_36323;
v_36324:
    v_36478 = stack[-4];
    goto v_36325;
v_36326:
    goto v_36322;
v_36323:
    goto v_36324;
v_36325:
    fn = elt(env, 12); // greaterp!:
    v_36478 = (*qfn2(fn))(fn, v_36479, v_36478);
    env = stack[-13];
    if (v_36478 == nil) goto v_36319;
    else goto v_36320;
v_36319:
    goto v_36315;
v_36320:
    goto v_36337;
v_36331:
    stack[0] = elt(env, 2); // !:rd!:
    goto v_36332;
v_36333:
    goto v_36344;
v_36340:
    stack[-1] = stack[-9];
    goto v_36341;
v_36342:
    v_36478 = stack[-5];
    v_36478 = add1(v_36478);
    env = stack[-13];
    stack[-5] = v_36478;
    goto v_36343;
v_36344:
    goto v_36340;
v_36341:
    goto v_36342;
v_36343:
    v_36479 = times2(stack[-1], v_36478);
    env = stack[-13];
    stack[-9] = v_36479;
    goto v_36334;
v_36335:
    v_36478 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_36336;
v_36337:
    goto v_36331;
v_36332:
    goto v_36333;
v_36334:
    goto v_36335;
v_36336:
    v_36478 = list2star(stack[0], v_36479, v_36478);
    env = stack[-13];
    stack[-3] = v_36478;
    goto v_36354;
v_36350:
    goto v_36360;
v_36356:
    v_36479 = stack[-2];
    goto v_36357;
v_36358:
    v_36478 = stack[-8];
    goto v_36359;
v_36360:
    goto v_36356;
v_36357:
    goto v_36358;
v_36359:
    fn = elt(env, 13); // times!:
    stack[0] = (*qfn2(fn))(fn, v_36479, v_36478);
    env = stack[-13];
    goto v_36351;
v_36352:
    v_36478 = stack[-12];
    v_36478 = negate(v_36478);
    env = stack[-13];
    goto v_36353;
v_36354:
    goto v_36350;
v_36351:
    goto v_36352;
v_36353:
    fn = elt(env, 14); // cut!:ep
    v_36478 = (*qfn2(fn))(fn, stack[0], v_36478);
    env = stack[-13];
    stack[-2] = v_36478;
    goto v_36370;
v_36366:
    stack[-1] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36367;
v_36368:
    goto v_36377;
v_36373:
    goto v_36383;
v_36379:
    stack[0] = stack[-12];
    goto v_36380;
v_36381:
    v_36478 = stack[-3];
    fn = elt(env, 15); // order!:
    v_36478 = (*qfn1(fn))(fn, v_36478);
    env = stack[-13];
    goto v_36382;
v_36383:
    goto v_36379;
v_36380:
    goto v_36381;
v_36382:
    stack[0] = difference2(stack[0], v_36478);
    env = stack[-13];
    goto v_36374;
v_36375:
    v_36478 = stack[-2];
    fn = elt(env, 15); // order!:
    v_36478 = (*qfn1(fn))(fn, v_36478);
    env = stack[-13];
    goto v_36376;
v_36377:
    goto v_36373;
v_36374:
    goto v_36375;
v_36376:
    v_36478 = plus2(stack[0], v_36478);
    env = stack[-13];
    goto v_36369;
v_36370:
    goto v_36366;
v_36367:
    goto v_36368;
v_36369:
    fn = elt(env, 16); // max
    v_36478 = (*qfn2(fn))(fn, stack[-1], v_36478);
    env = stack[-13];
    goto v_36396;
v_36390:
    v_36480 = stack[-2];
    goto v_36391;
v_36392:
    v_36479 = stack[-3];
    goto v_36393;
v_36394:
    goto v_36395;
v_36396:
    goto v_36390;
v_36391:
    goto v_36392;
v_36393:
    goto v_36394;
v_36395:
    fn = elt(env, 17); // divide!:
    v_36478 = (*qfnn(fn))(fn, 3, v_36480, v_36479, v_36478);
    env = stack[-13];
    stack[0] = v_36478;
    goto v_36405;
v_36401:
    v_36479 = stack[-6];
    goto v_36402;
v_36403:
    v_36478 = stack[0];
    goto v_36404;
v_36405:
    goto v_36401;
v_36402:
    goto v_36403;
v_36404:
    fn = elt(env, 18); // plus!:
    v_36478 = (*qfn2(fn))(fn, v_36479, v_36478);
    env = stack[-13];
    stack[-6] = v_36478;
    goto v_36416;
v_36412:
    goto v_36422;
v_36418:
    v_36479 = stack[-5];
    goto v_36419;
v_36420:
    v_36478 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_36421;
v_36422:
    goto v_36418;
v_36419:
    goto v_36420;
v_36421:
    v_36479 = Cremainder(v_36479, v_36478);
    env = stack[-13];
    goto v_36413;
v_36414:
    v_36478 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_36415;
v_36416:
    goto v_36412;
v_36413:
    goto v_36414;
v_36415:
    if (v_36479 == v_36478) goto v_36410;
    else goto v_36411;
v_36410:
    goto v_36431;
v_36427:
    stack[-1] = stack[-6];
    goto v_36428;
v_36429:
    v_36478 = stack[-12];
    v_36478 = negate(v_36478);
    env = stack[-13];
    goto v_36430;
v_36431:
    goto v_36427;
v_36428:
    goto v_36429;
v_36430:
    fn = elt(env, 14); // cut!:ep
    v_36478 = (*qfn2(fn))(fn, stack[-1], v_36478);
    env = stack[-13];
    stack[-6] = v_36478;
    goto v_36409;
v_36411:
v_36409:
    goto v_36316;
v_36315:
    goto v_36281;
v_36281:
    goto v_36440;
v_36436:
    goto v_36446;
v_36442:
    v_36479 = stack[-7];
    goto v_36443;
v_36444:
    v_36478 = stack[-6];
    goto v_36445;
v_36446:
    goto v_36442;
v_36443:
    goto v_36444;
v_36445:
    fn = elt(env, 13); // times!:
    stack[0] = (*qfn2(fn))(fn, v_36479, v_36478);
    env = stack[-13];
    goto v_36437;
v_36438:
    v_36478 = stack[-10];
    v_36478 = add1(v_36478);
    env = stack[-13];
    goto v_36439;
v_36440:
    goto v_36436;
v_36437:
    goto v_36438;
v_36439:
    fn = elt(env, 19); // cut!:mt
    v_36478 = (*qfn2(fn))(fn, stack[0], v_36478);
    env = stack[-13];
    stack[-1] = v_36478;
    v_36478 = stack[-11];
    fn = elt(env, 20); // minusp!:
    v_36478 = (*qfn1(fn))(fn, v_36478);
    env = stack[-13];
    if (v_36478 == nil) goto v_36454;
    goto v_36464;
v_36458:
    v_36480 = qvalue(elt(env, 1)); // bfone!*
    goto v_36459;
v_36460:
    v_36479 = stack[-1];
    goto v_36461;
v_36462:
    v_36478 = stack[-10];
    goto v_36463;
v_36464:
    goto v_36458;
v_36459:
    goto v_36460;
v_36461:
    goto v_36462;
v_36463:
    {
        fn = elt(env, 17); // divide!:
        return (*qfnn(fn))(fn, 3, v_36480, v_36479, v_36478);
    }
v_36454:
    goto v_36475;
v_36471:
    v_36479 = stack[-1];
    goto v_36472;
v_36473:
    v_36478 = stack[-10];
    goto v_36474;
v_36475:
    goto v_36471;
v_36472:
    goto v_36473;
v_36474:
    {
        fn = elt(env, 21); // round!:mt
        return (*qfn2(fn))(fn, v_36479, v_36478);
    }
    v_36478 = nil;
    goto v_36175;
    v_36478 = nil;
v_36175:
    return onevalue(v_36478);
}



// Code for kernelp

static LispObject CC_kernelp(LispObject env,
                         LispObject v_36171)
{
    env = qenv(env);
    LispObject v_36229, v_36230, v_36231;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_36230 = v_36171;
// end of prologue
    v_36229 = v_36230;
    if (!consp(v_36229)) goto v_36187;
    else goto v_36188;
v_36187:
    v_36229 = lisp_true;
    goto v_36186;
v_36188:
    v_36229 = v_36230;
    v_36229 = qcar(v_36229);
    v_36229 = (consp(v_36229) ? nil : lisp_true);
    goto v_36186;
    v_36229 = nil;
v_36186:
    if (v_36229 == nil) goto v_36183;
    else goto v_36184;
v_36183:
    v_36229 = v_36230;
    v_36229 = qcdr(v_36229);
    v_36229 = (v_36229 == nil ? lisp_true : nil);
    goto v_36182;
v_36184:
    v_36229 = nil;
    goto v_36182;
    v_36229 = nil;
v_36182:
    if (v_36229 == nil) goto v_36180;
    goto v_36206;
v_36202:
    v_36229 = v_36230;
    v_36229 = qcar(v_36229);
    v_36231 = qcdr(v_36229);
    goto v_36203;
v_36204:
    v_36229 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36205;
v_36206:
    goto v_36202;
v_36203:
    goto v_36204;
v_36205:
    v_36229 = (v_36231 == v_36229 ? lisp_true : nil);
    goto v_36178;
v_36180:
    v_36229 = nil;
    goto v_36178;
    v_36229 = nil;
v_36178:
    if (v_36229 == nil) goto v_36176;
    goto v_36219;
v_36215:
    v_36229 = v_36230;
    v_36229 = qcar(v_36229);
    v_36229 = qcar(v_36229);
    v_36230 = qcdr(v_36229);
    goto v_36216;
v_36217:
    v_36229 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_36218;
v_36219:
    goto v_36215;
v_36216:
    goto v_36217;
v_36218:
    v_36229 = (v_36230 == v_36229 ? lisp_true : nil);
    goto v_36174;
v_36176:
    v_36229 = nil;
    goto v_36174;
    v_36229 = nil;
v_36174:
    return onevalue(v_36229);
}



// Code for rep_parents

static LispObject CC_rep_parents(LispObject env,
                         LispObject v_36171, LispObject v_36172)
{
    env = qenv(env);
    LispObject v_36183, v_36184;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_36172,v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_36171,v_36172);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_36183 = v_36172;
    stack[0] = v_36171;
// end of prologue
    goto v_36179;
v_36175:
    v_36184 = stack[0];
    goto v_36176;
v_36177:
    goto v_36178;
v_36179:
    goto v_36175;
v_36176:
    goto v_36177;
v_36178:
    v_36183 = Lrplacd(nil, v_36184, v_36183);
    v_36183 = stack[0];
    return onevalue(v_36183);
}



// Code for dp_content

static LispObject CC_dp_content(LispObject env,
                         LispObject v_36171)
{
    env = qenv(env);
    LispObject v_36214;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_36171);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_36171;
// end of prologue
    v_36214 = stack[0];
    if (v_36214 == nil) goto v_36175;
    else goto v_36176;
v_36175:
    v_36214 = (LispObject)0+TAG_FIXNUM; // 0
    {
        fn = elt(env, 1); // cali_bc_fi
        return (*qfn1(fn))(fn, v_36214);
    }
v_36176:
    v_36214 = stack[0];
    fn = elt(env, 2); // dp_lc
    v_36214 = (*qfn1(fn))(fn, v_36214);
    env = stack[-2];
    stack[-1] = v_36214;
    v_36214 = stack[0];
    v_36214 = qcdr(v_36214);
    stack[0] = v_36214;
v_36191:
    v_36214 = stack[0];
    if (v_36214 == nil) goto v_36194;
    v_36214 = stack[-1];
    fn = elt(env, 3); // cali_bc_inv
    v_36214 = (*qfn1(fn))(fn, v_36214);
    env = stack[-2];
    if (v_36214 == nil) goto v_36198;
    else goto v_36194;
v_36198:
    goto v_36195;
v_36194:
    goto v_36190;
v_36195:
    goto v_36207;
v_36203:
    goto v_36204;
v_36205:
    v_36214 = stack[0];
    fn = elt(env, 2); // dp_lc
    v_36214 = (*qfn1(fn))(fn, v_36214);
    env = stack[-2];
    goto v_36206;
v_36207:
    goto v_36203;
v_36204:
    goto v_36205;
v_36206:
    fn = elt(env, 4); // cali_bc_gcd
    v_36214 = (*qfn2(fn))(fn, stack[-1], v_36214);
    env = stack[-2];
    stack[-1] = v_36214;
    v_36214 = stack[0];
    v_36214 = qcdr(v_36214);
    stack[0] = v_36214;
    goto v_36191;
v_36190:
    v_36214 = stack[-1];
    goto v_36174;
    v_36214 = nil;
v_36174:
    return onevalue(v_36214);
}



// Code for tensor_has_dummy_idx

static LispObject CC_tensor_has_dummy_idx(LispObject env,
                         LispObject v_36171, LispObject v_36172)
{
    env = qenv(env);
    LispObject v_36199, v_36200;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_36172,v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_36171,v_36172);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_36172;
    stack[-1] = v_36171;
// end of prologue
v_36176:
    v_36199 = stack[-1];
    if (v_36199 == nil) goto v_36179;
    else goto v_36180;
v_36179:
    v_36199 = nil;
    goto v_36175;
v_36180:
    goto v_36190;
v_36186:
    v_36199 = stack[-1];
    v_36200 = qcar(v_36199);
    goto v_36187;
v_36188:
    v_36199 = stack[0];
    goto v_36189;
v_36190:
    goto v_36186;
v_36187:
    goto v_36188;
v_36189:
    fn = elt(env, 1); // smember
    v_36199 = (*qfn2(fn))(fn, v_36200, v_36199);
    env = stack[-2];
    if (v_36199 == nil) goto v_36184;
    v_36199 = lisp_true;
    goto v_36175;
v_36184:
    v_36199 = stack[-1];
    v_36199 = qcdr(v_36199);
    stack[-1] = v_36199;
    goto v_36176;
    v_36199 = nil;
v_36175:
    return onevalue(v_36199);
}



// Code for algebnp

static LispObject CC_algebnp(LispObject env,
                         LispObject v_36171)
{
    env = qenv(env);
    LispObject v_36216, v_36217;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_36171);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_36171);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_36171;
// end of prologue
v_36170:
    v_36216 = stack[0];
    if (!consp(v_36216)) goto v_36175;
    else goto v_36176;
v_36175:
    v_36216 = nil;
    goto v_36174;
v_36176:
    goto v_36185;
v_36181:
    v_36216 = stack[0];
    v_36217 = qcar(v_36216);
    goto v_36182;
v_36183:
    v_36216 = elt(env, 1); // !:ar!:
    goto v_36184;
v_36185:
    goto v_36181;
v_36182:
    goto v_36183;
v_36184:
    if (v_36217 == v_36216) goto v_36179;
    else goto v_36180;
v_36179:
    v_36216 = lisp_true;
    goto v_36174;
v_36180:
    v_36216 = stack[0];
    if (!consp(v_36216)) goto v_36194;
    else goto v_36195;
v_36194:
    v_36216 = lisp_true;
    goto v_36193;
v_36195:
    v_36216 = stack[0];
    v_36216 = qcar(v_36216);
    v_36216 = (consp(v_36216) ? nil : lisp_true);
    goto v_36193;
    v_36216 = nil;
v_36193:
    if (v_36216 == nil) goto v_36191;
    v_36216 = nil;
    goto v_36174;
v_36191:
    v_36216 = stack[0];
    v_36216 = qcar(v_36216);
    v_36216 = qcdr(v_36216);
    v_36216 = CC_algebnp(elt(env, 0), v_36216);
    env = stack[-1];
    if (v_36216 == nil) goto v_36208;
    else goto v_36207;
v_36208:
    v_36216 = stack[0];
    v_36216 = qcdr(v_36216);
    stack[0] = v_36216;
    goto v_36170;
v_36207:
    goto v_36174;
    v_36216 = nil;
v_36174:
    return onevalue(v_36216);
}



setup_type const u60_setup[] =
{
    {"com43",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_com43},
    {"partsym_zerop",           TOO_FEW_2,      CC_partsym_zerop,WRONG_NO_2},
    {"sc_repkern",              TOO_FEW_2,      CC_sc_repkern, WRONG_NO_2},
    {"lambda_1x539vlzlwg93",    TOO_FEW_2,      CC_lambda_1x539vlzlwg93,WRONG_NO_2},
    {"super_product_sq",        TOO_FEW_2,      CC_super_product_sq,WRONG_NO_2},
    {"sfto_mindeg1",            TOO_FEW_2,      CC_sfto_mindeg1,WRONG_NO_2},
    {"rat_min",                 TOO_FEW_2,      CC_rat_min,    WRONG_NO_2},
    {"setqdeletedescendants",   CC_setqdeletedescendants,TOO_MANY_1,WRONG_NO_1},
    {"interglue",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_interglue},
    {"*s2arg",                  TOO_FEW_2,      CC_Hs2arg,     WRONG_NO_2},
    {"actual_world",            TOO_FEW_2,      CC_actual_world,WRONG_NO_2},
    {"mo_dlexcomp",             TOO_FEW_2,      CC_mo_dlexcomp,WRONG_NO_2},
    {"affinep",                 CC_affinep,     TOO_MANY_1,    WRONG_NO_1},
    {"r2flbf",                  CC_r2flbf,      TOO_MANY_1,    WRONG_NO_1},
    {"redmsg",                  TOO_FEW_2,      CC_redmsg,     WRONG_NO_2},
    {"ofsf_ordrelp",            TOO_FEW_2,      CC_ofsf_ordrelp,WRONG_NO_2},
    {"gcdk",                    TOO_FEW_2,      CC_gcdk,       WRONG_NO_2},
    {"mk_character",            CC_mk_character,TOO_MANY_1,    WRONG_NO_1},
    {"qqe_length-graph-remove-mark",TOO_FEW_2,  CC_qqe_lengthKgraphKremoveKmark,WRONG_NO_2},
    {"groebfactorize3",         CC_groebfactorize3,TOO_MANY_1, WRONG_NO_1},
    {"xvarp",                   CC_xvarp,       TOO_MANY_1,    WRONG_NO_1},
    {"exp:",                    TOO_FEW_2,      CC_expT,       WRONG_NO_2},
    {"kernelp",                 CC_kernelp,     TOO_MANY_1,    WRONG_NO_1},
    {"rep_parents",             TOO_FEW_2,      CC_rep_parents,WRONG_NO_2},
    {"dp_content",              CC_dp_content,  TOO_MANY_1,    WRONG_NO_1},
    {"tensor_has_dummy_idx",    TOO_FEW_2,      CC_tensor_has_dummy_idx,WRONG_NO_2},
    {"algebnp",                 CC_algebnp,     TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u60", (two_args *)"55327 4906264 6217405", 0}
};

// end of generated code
